#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>

#include <ticket_field.h>
#include <tariff_disct.h>
#include <ticket.h>
#include <stt_ticket.h>

#include <fileout.h>

int (*Ticket2Str)(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
struct TinyRollLogStruct *pSumLog=NULL;

int MyProcessTicket(struct FileControlListStruct *ptHead,char sAreaCode[],
	char sBaseName[],char sMod[],struct FileControlOutStruct **ppNormal,
	struct FileControlStruct **ppAbnormal,char sLine[],char sTargetName[],
	int *piNormalCnt,int *piErrCnt,char sSplitNew[])
{
	int iRet,iTicketValid=0,l,iErrInfo=0;
	char	sHostTime[15],sRecord[4096],msg[1024],sTemp[256];
	struct SplitRuleStruct *pSplitRule=NULL;
	struct FileControlListStruct *pTemp;	
	
	/**��λ�����ṹ�ĵ�ǰ�������{unlink pCur����}*/
	ResetTicket();
	/**����ԭʼ������ָ����ԭʼ�����ṹ�ֶΣ�����ԭʼ��������*/
	l=strlen(sLine);
	
	TICKET.iOriLen=	l;TICKET.sOri[l]=0;
	memcpy((void*)(TICKET.sOri),sLine,l);

	*piErrCnt=*piNormalCnt=0;
	GetHostTime(sHostTime);	
	
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		set_str_value("$FILENAME",pExprBuf,sBaseName);
		set_str_value("$MODULE",pExprBuf,sMod);
		set_str_value("$NOW",pExprBuf,sHostTime);
		set_str_value("$SPLITTYPE",pExprBuf,pTemp->sSplitType);
		set_str_value("$AREACODE",pExprBuf,sAreaCode);
		
		/*ִ�й�ʽ{������Ի��pCur����link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			WriteAlertPrint("ִ�й�ʽ����");
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_str_value("$SUFFIXSTR",pExprBuf,sTemp);
		GetFixStrX(sTemp,0,20,SUFFIX_STR);
		
		get_str_value("$ERRINFO",pExprBuf,sTemp);
		if(iErrInfo==0) iErrInfo=atoi(sTemp);
		
		/*ֱ�Ӻ��Ե���Ч����,ֻ���һ�δ��󻰵�*/
		if(iTicketValid<=0){
			
			char	sFileName[128];
			
			if(iTicketValid==-1) continue;
			if(*piErrCnt!=0) continue;
			
			*piErrCnt=1;

			if(iErrInfo==0){
				if((l=mvitem2commerr(sLine,strlen(sLine),
					-iTicketValid,sBaseName,sMod,
					sAreaCode,sRecord))>1024){
					WriteAlertPrint("������¼̫��������1024");
					return -1;
				}
			}
			else{
				if((l=mvitem2err(sLine,strlen(sLine),
					-iTicketValid,sRecord))>1024){
					WriteAlertPrint("������¼̫��������1024");
					return -1;
				}
			}
			if(Item2FileOut(ppAbnormal,sRecord,l,sTargetName,"a")<0){
				WriteAlertPrint("�����쳣�����������");
				return -1;
			}
			GetOutFileName(sTargetName,"a",sFileName);
			if(SumTinyRollLog(&pSumLog,sBaseName,sFileName,1)<0){
				WriteAlertMsg("������־�ļ��б����");
				return -1;
			}
			if(strstr(sSplitNew,"a")==NULL) strcat(sSplitNew,"a");
			
			continue;
		}
/**��������ָ����TEMPLATE_RULE_ID��SPLIT_TYPE,�����֮*/
		if(pTemp->pSplitRule==NULL){
			GenStdTicket();
			pTemp->iCnt++;
			if(Item2FileSplitOut(ppNormal,TICKET.sStd,
				TICKET.iStdLen,sBaseName,sTargetName,
				pTemp->sSplitType,&pSumLog,sSplitNew,msg)<0){
				WriteAlertPrint("�������������������,��Ϣ:%s",msg);
				return -1;
			}
			(*piNormalCnt)++;
			continue;
		}
/*���ƥ�䲻�ϣ��򲻳����໰��*/
		if((pSplitRule=GetMultiSplitRule(pTemp))==NULL)continue;
/*�ڷ���ģ��ƥ�䲻�ϵĻ����Ͳ�Ҫ��*/
		if(pSplitRule->iTicketTypeID<0) continue;
		
		GenStdTicket();
		pTemp->iCnt++;
		if(Item2FileSplitOut(ppNormal,TICKET.sStd,TICKET.iStdLen,
			sBaseName,sTargetName,pTemp->sSplitType,
			&pSumLog,sSplitNew,msg)<0){
			WriteAlertPrint("�������������������,��Ϣ:%s",msg);
			return -1;
		}
		(*piNormalCnt)++;
	}
	return 0;
}
int main(int argc, char **argv)
{
	int i,l,iRet,iErrCnt=0,iFlag=0,iWantUpdate=false;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0;
	
	char sTableName[32],sCondition[128],sLine[4096];
	char	msg[2048],sType[5],sTargetName[256],sNewName[8192];
	char  sTemplateRule[128],sInput[EXPRLEN],sModule[4],sSplitNew[21];
	char  sBaseName[128],sRowID[19],sDateTime[15],sNormalPath[128];
	char  sExprName[128],sSplitStr[10],sVisitAreaCode[10];

	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	

	struct FileControlStruct *pAbnormal=NULL;
	struct FileControlOutStruct *pNormal=NULL;
	struct	FileControlListStruct *pControlList=NULL;

	struct UCommTicketStruct TempUTicket;
	struct UCommTicketStructUp TempUp;	

	if(argc!=11){
		printf("Usage %s tablename wherecause type exprfile \
templateid splitstr visitcode module targetname update(def=0).\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[2]);
	strncpy(sType,argv[3],4);sType[4]=0;AllTrim(sType);
	strcpy(sExprName,argv[4]);
	strcpy(sTemplateRule,argv[5]);
	strcpy(sSplitStr,argv[6]);
	strcpy(sVisitAreaCode,argv[7]);
	strncpy(sModule,argv[8],3);sModule[3]=0;
	strcpy(sTargetName,argv[9]);
	if((iWantUpdate=atoi(argv[10]))!=0) iWantUpdate=1;
	
	pSumLog=NULL;
	
	strcpy(sSplitNew,"");

	RegularDir(sNormalPath);
	Upper(sTableName);

	switch (sType[0]){
		case 'S':Ticket2Str=SttTicket2Str;break;
		case 'M':Ticket2Str=SmscTicket2Str;break;
		case 'N':Ticket2Str=SmspTicket2Str;break;
		case 'R':Ticket2Str=GprsTicket2Str;break;
		case 'X':Ticket2Str=Cdma1xTicket2Str;break;
		case 'P':Ticket2Str=PrepTicket2Str;break;
		case 'T':Ticket2Str=SmsTicket2Str;break;
		case '3':Ticket2Str=SmgsmTicket2Str;break;
		case '4':Ticket2Str=SmcdmaTicket2Str;break;
		case '1':Ticket2Str=SmtelTicket2Str;break;
		case '2':Ticket2Str=SmmobTicket2Str;break;
		case '9':Ticket2Str=Smsp1Ticket2Str;break;
		case '5':Ticket2Str=Sp1xfjTicket2Str;break;
		case '6':Ticket2Str=SmspfjTicket2Str;break;
		case 't':Ticket2Str=NsmsTicket2Str;break;
		case 'I':Ticket2Str=IccTicket2Str;break;
		case 'Z':Ticket2Str=ZnwTicket2Str;break;
		case 'a':Ticket2Str=SmgTicket2Str;break;
		case '*':Ticket2Str=XStrTicket2Str;break;
		default:
			printf("ϵͳ��֧��%s�����,���=(S,M,N,R,X,P,T,[1-4,5,6,9],t,I,Z,a).\n",sType);
			return -1;
	}
/*��ʼ�����۲���*/
	MoveAllShmToMem();
/*���������б�*/
	InitFileControlList(sTemplateRule,sSplitStr,&pControlList);
	pFileControlList=pControlList;
	
	InitTollTariffList(comp_toll_tariff_ticket);
	
/*����ʽ�����ڴ�*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,msg)!=0){
		WriteAlertPrint("���ļ�%sʧ��:%s",sExprName,msg);
		return -1;
	}
/*���ر��빫ʽ����������*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*���빫ʽ*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
/**�������ݿ�***/
	if(ConnectDataDB()<0) return -1;
	
	/*����*/
	bzero((void*)&TempUp,sizeof(struct UCommTicketStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
	GetHostTime(sDateTime);

	/*�����ļ���*/
	strcpy(TempUTicket.sModule,sModule);
	strcpy(TempUTicket.sAreaCode,sVisitAreaCode);
	strcpy(TempUTicket.sState,"1");
	strcpy(TempUTicket.sUpdateDate,sDateTime);
	GetBaseNameX(sTargetName,sBaseName);
	strncpy(TempUTicket.sFileName,sBaseName,19);
	TempUTicket.sFileName[19]=0;
	
	/*�����ͨ��������Ա������������任*/
	if(sType[0]=='*'){
		i=GetXStrTableName(sTableName,sCondition,sNewName);
		if(i<0){
			WriteAlertPrint("��ȡ��%s��ƴ��������",
				sTableName);
			return -1;
		}
		strcpy(sCondition,"");
		/*����*�������͵Ļ�������UPDATE*/
		if(iWantUpdate==1) iWantUpdate=0;
	}
	else	strcpy(sNewName,sTableName);
		
	while(Ticket2Str(sNewName,sCondition,sBaseName,sRowID,sLine)==true){

		/*������������б�*/
		if((iRet=MyProcessTicket(pControlList,sVisitAreaCode,
			sBaseName,sModule,&pNormal,&pAbnormal,sLine,
			sTargetName,&iFlag,&iErrCnt,sSplitNew))<0){
	
			WriteAlertPrint("������ʧ�ܣ���%s",sTableName);
			return -1;
		}
		if(iWantUpdate==1&&iErrCnt!=1&&iFlag>0){
			strcpy(TempUTicket.sRowID,sRowID);
			if(EUpdateStructToUCommTicket(&TempUTicket,false,&TempUp)<0){
				WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
				return -1;
			}
		}		
		
		if(iErrCnt==1) 		iAbnormalCnt++;
		else if(iFlag>0)	iNormalCnt+=iFlag;
		
		if((++iCnt)%10000==0){

			WriteProcMsg("�Ա�%s���ļ�,������%d,�����쳣��%d,�����%d",
				sTableName,iCnt,iAbnormalCnt,iNormalCnt);

			if(iWantUpdate==1){
				if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
					WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
					return -1;
				}
			}
		}

	}
	if(iWantUpdate==1){

		if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
			WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
			return -1;
		}
	}

	if(WriteRollLogCtl(pSumLog,sTargetName)<0){
		WriteAlertMsg("д��־�����ļ�ʧ��");
		return -1;
	}

	CloseFileOut(pAbnormal);
	CloseFileOutAll(pNormal);

	WriteProcMsg("�Ա�%s���ļ����,������%d,����������%d,�쳣��%d",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt);
	if(iNormalCnt==0)
		WriteProcMsg("����������Ϊ0������1:û�������������ض�����,",
			"2:id=%s,split=%s�ķ�������û��һ��������ƥ����",
				sTemplateRule,sSplitStr);
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt,sSplitNew);
	
	CommitWork();
	DisconnectDatabase();
	
/*��pFileControlList�ͷ�*/
	DestroyFileControlList(pControlList);
/*�ͷ����۲���*/
	DistroyAllMem();

	
	return 0;
}
