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

struct TinyRollLogStruct *pSumLog=NULL;

int main(int argc, char **argv)
{
	int i,l,iRet,iErrCnt=0,iWantUpdate=false,iTicketValid=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0,iOriLen=0,iLen=0;
	
	char sTableName[32],sCondition[128];
	char	msg[2048],sType[5],sTargetName[256];
	char  sMsc[16],sInput[EXPRLEN],sModule[4],sSplitNew[21];
	char  sBaseName[128],sDateTime[15],sNormalPath[128];
	char  sExprName[128],sUserType[10],sAreaCode[10];
	char  sOri[4096],sSourceID[7],sFileType[7],sNow[15];
	char  sTemp[64],sSuffixStr[20],sFileName[256],sMsg[1024];

	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	
	struct FileControlStruct *pAbnormal=NULL;
	struct FileControlOutStruct *pNormal=NULL;

	struct UCommTicketStruct TempUTicket;
	struct UCommTicketStructUp TempUp;
	
	struct ErrTicketStructIn TempIn;
	struct ErrTicketStruct Temp;

	if(argc!=13){
		printf("Usage %s tablename wherecause type[E] exprfile \
MSC usertype visitcode module source filetype targetname update(def=0).\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[2]);
	strncpy(sType,argv[3],4);sType[4]=0;AllTrim(sType);
	strcpy(sExprName,argv[4]);
	strcpy(sMsc,argv[5]);
	strcpy(sUserType,argv[6]);
	strcpy(sAreaCode,argv[7]);
	strncpy(sModule,argv[8],3);sModule[3]=0;
	strncpy(sSourceID,argv[9],6);sSourceID[6]=0;
	strncpy(sFileType,argv[10],5);sFileType[5]=0;
	
	strcpy(sTargetName,argv[11]);

	if((iWantUpdate=atoi(argv[12]))!=0) iWantUpdate=1;
	
	strcpy(sSplitNew,"");

	RegularDir(sNormalPath);

/*��һ�����͵�У��*/
	if(strcmp(sType,"E")!=0){
		printf("ϵͳ��֧��E���͸�ʽ����.\n");
		return -1;
	}

/*��ʼ�����۲���*/
	MoveAllShmToMem();
	
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
	strcpy(TempUTicket.sAreaCode,sAreaCode);
	strcpy(TempUTicket.sState,"1");
	strcpy(TempUTicket.sUpdateDate,sDateTime);
	GetBaseNameX(sTargetName,sBaseName);
	strncpy(TempUTicket.sFileName,sBaseName,19);
	TempUTicket.sFileName[19]=0;
	
	bzero((void*)&Temp,sizeof(struct ErrTicketStruct));
	bzero((void*)&TempIn,sizeof(struct ErrTicketStructIn));
	
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,sCondition);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
		
	 while(EGetErrTicketToStruct(&Temp,&TempIn)){
		/*��ӡ���������*/
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

		if(ResetErr2Ori(Temp.sRecordType,Temp.sErrRec,sOri,&iOriLen)<0){
			WriteAlertPrint("�ָ����ļ���ԭʼ��ʽʧ�ܣ���%s",sTableName);
			return -1;
		}
				
		/**����ԭʼ������ָ����ԭʼ�����ṹ�ֶΣ�����ԭʼ��������*/
		iLen=MY_MIN(iOriLen,sizeof(TICKET.sOri)-1);
		TICKET.iOriLen=	iLen;
		TICKET.sOri[iLen]=0;
		
		memcpy((void*)(TICKET.sOri),sOri,iLen);
		
		/**��λ�����ṹ�ĵ�ǰ�������{unlink pCur����}*/
		ResetTicket();
		set_str_value("$FILENAME",pExprBuf,sSourceID);
		set_str_value("$FILEINFO",pExprBuf,sBaseName);
		GetHostTime(sNow);	
		set_str_value("$NOW",pExprBuf,sNow);
		set_str_value("$MSC",pExprBuf,sMsc);
		set_str_value("$AREACODE",pExprBuf,sAreaCode);
		set_str_value("$USERTYPE",pExprBuf,sUserType);
		set_str_value("$MODULE",pExprBuf,sModule);
		set_str_value("$FILETYPE",pExprBuf,sFileType);
		
		/*ִ�й�ʽ{������Ի��pCur����link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			printf("ִ�й�ʽ%sʧ��.\n",sExprName);
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_str_value("$SUFFIXSTR",pExprBuf,sTemp);
		GetFixStrX(sTemp,0,20,sSuffixStr);
		if(strlen(sSuffixStr)==0)strcpy(sSuffixStr,"C");
		
		/*���ɱ�׼�������*/
		GenStdTicket();

		/*ticketvalid����
			<0:��Ч����;
			0 :У�鲻ͨ���쳣����������
			>0:��������
		*/
		/*��������У�鲻ͨ���Ĵ��󻰵�����ԭʼ�������ں���*/
		if(iTicketValid<0){
			/*��Ч����������Ч�򲻻���*/
			iErrCnt++;
			continue;
		}
		
		if(iTicketValid==0){/*0��ʾ�쳣����*/
			iAbnormalCnt++;
			
			
			if(Item2FileOut(&pAbnormal,TICKET.sStd,TICKET.iStdLen,
				sTargetName,"a")<0){
				WriteAlertPrint("�����쳣�����������");
				return -1;
			}
			GetOutFileName(sTargetName,"a",sFileName);
			if(SumTinyRollLog(&pSumLog,sBaseName,sFileName,1)<0){
				WriteAlertMsg("������־�ļ��б����");
				return -1;
			}
			if(strstr(sSplitNew,"a")==NULL) strcat(sSplitNew,"a");
		}
		else{
			iNormalCnt++;
			
			if(Item2FileSplitOut(&pNormal,TICKET.sStd,
				TICKET.iStdLen,sBaseName,sTargetName,
				"C",&pSumLog,sSplitNew,sMsg)<0){
				WriteAlertPrint("�������������������,��Ϣ:%s",msg);
				return -1;
			}
		}

		if(iWantUpdate==1){
			strcpy(TempUTicket.sRowID,Temp.sRowID);
			if(EUpdateStructToUCommTicket(&TempUTicket,false,&TempUp)<0){
				WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
				return -1;
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
				sMsc,sUserType);
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt,sSplitNew);
	
	CommitWork();
	DisconnectDatabase();
	
/*�ͷŲ���*/
	DistroyAllMem();

	
	return 0;
}
