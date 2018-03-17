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
	
	/**复位话单结构的当前输出链表{unlink pCur链表}*/
	ResetTicket();
	/**加载原始话单到指定的原始话单结构字段，设置原始话单长度*/
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
		
		/*执行公式{这里可以获得pCur链表，link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			WriteAlertPrint("执行公式错误");
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_str_value("$SUFFIXSTR",pExprBuf,sTemp);
		GetFixStrX(sTemp,0,20,SUFFIX_STR);
		
		get_str_value("$ERRINFO",pExprBuf,sTemp);
		if(iErrInfo==0) iErrInfo=atoi(sTemp);
		
		/*直接忽略掉无效话单,只输出一次错误话单*/
		if(iTicketValid<=0){
			
			char	sFileName[128];
			
			if(iTicketValid==-1) continue;
			if(*piErrCnt!=0) continue;
			
			*piErrCnt=1;

			if(iErrInfo==0){
				if((l=mvitem2commerr(sLine,strlen(sLine),
					-iTicketValid,sBaseName,sMod,
					sAreaCode,sRecord))>1024){
					WriteAlertPrint("话单记录太长，大于1024");
					return -1;
				}
			}
			else{
				if((l=mvitem2err(sLine,strlen(sLine),
					-iTicketValid,sRecord))>1024){
					WriteAlertPrint("话单记录太长，大于1024");
					return -1;
				}
			}
			if(Item2FileOut(ppAbnormal,sRecord,l,sTargetName,"a")<0){
				WriteAlertPrint("生成异常话单链表错误");
				return -1;
			}
			GetOutFileName(sTargetName,"a",sFileName);
			if(SumTinyRollLog(&pSumLog,sBaseName,sFileName,1)<0){
				WriteAlertMsg("生成日志文件列表错误");
				return -1;
			}
			if(strstr(sSplitNew,"a")==NULL) strcat(sSplitNew,"a");
			
			continue;
		}
/**如果是随便指定的TEMPLATE_RULE_ID和SPLIT_TYPE,就输出之*/
		if(pTemp->pSplitRule==NULL){
			GenStdTicket();
			pTemp->iCnt++;
			if(Item2FileSplitOut(ppNormal,TICKET.sStd,
				TICKET.iStdLen,sBaseName,sTargetName,
				pTemp->sSplitType,&pSumLog,sSplitNew,msg)<0){
				WriteAlertPrint("生成正常话单链表错误,消息:%s",msg);
				return -1;
			}
			(*piNormalCnt)++;
			continue;
		}
/*如果匹配不上，则不出这类话单*/
		if((pSplitRule=GetMultiSplitRule(pTemp))==NULL)continue;
/*在分离模版匹配不上的话单就不要了*/
		if(pSplitRule->iTicketTypeID<0) continue;
		
		GenStdTicket();
		pTemp->iCnt++;
		if(Item2FileSplitOut(ppNormal,TICKET.sStd,TICKET.iStdLen,
			sBaseName,sTargetName,pTemp->sSplitType,
			&pSumLog,sSplitNew,msg)<0){
			WriteAlertPrint("生成正常话单链表错误,消息:%s",msg);
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
			printf("系统不支持%s的类别,类别=(S,M,N,R,X,P,T,[1-4,5,6,9],t,I,Z,a).\n",sType);
			return -1;
	}
/*初始化批价参数*/
	MoveAllShmToMem();
/*建立分离列表*/
	InitFileControlList(sTemplateRule,sSplitStr,&pControlList);
	pFileControlList=pControlList;
	
	InitTollTariffList(comp_toll_tariff_ticket);
	
/*将公式读到内存*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,msg)!=0){
		WriteAlertPrint("读文件%s失败:%s",sExprName,msg);
		return -1;
	}
/*加载编译公式函数及参数*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;
	
	/*更新*/
	bzero((void*)&TempUp,sizeof(struct UCommTicketStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
	GetHostTime(sDateTime);

	/*计算文件名*/
	strcpy(TempUTicket.sModule,sModule);
	strcpy(TempUTicket.sAreaCode,sVisitAreaCode);
	strcpy(TempUTicket.sState,"1");
	strcpy(TempUTicket.sUpdateDate,sDateTime);
	GetBaseNameX(sTargetName,sBaseName);
	strncpy(TempUTicket.sFileName,sBaseName,19);
	TempUTicket.sFileName[19]=0;
	
	/*如果是通用类型则对表名和条件做变换*/
	if(sType[0]=='*'){
		i=GetXStrTableName(sTableName,sCondition,sNewName);
		if(i<0){
			WriteAlertPrint("获取表%s的拼接语句错误",
				sTableName);
			return -1;
		}
		strcpy(sCondition,"");
		/*对于*这种类型的话单不能UPDATE*/
		if(iWantUpdate==1) iWantUpdate=0;
	}
	else	strcpy(sNewName,sTableName);
		
	while(Ticket2Str(sNewName,sCondition,sBaseName,sRowID,sLine)==true){

		/*生成输出话单列表*/
		if((iRet=MyProcessTicket(pControlList,sVisitAreaCode,
			sBaseName,sModule,&pNormal,&pAbnormal,sLine,
			sTargetName,&iFlag,&iErrCnt,sSplitNew))<0){
	
			WriteAlertPrint("处理话单失败，表%s",sTableName);
			return -1;
		}
		if(iWantUpdate==1&&iErrCnt!=1&&iFlag>0){
			strcpy(TempUTicket.sRowID,sRowID);
			if(EUpdateStructToUCommTicket(&TempUTicket,false,&TempUp)<0){
				WriteAlertMsg("表%s更新数据错误.",TempUp.sTableName);
				return -1;
			}
		}		
		
		if(iErrCnt==1) 		iAbnormalCnt++;
		else if(iFlag>0)	iNormalCnt+=iFlag;
		
		if((++iCnt)%10000==0){

			WriteProcMsg("对表%s出文件,处理数%d,其中异常数%d,输出数%d",
				sTableName,iCnt,iAbnormalCnt,iNormalCnt);

			if(iWantUpdate==1){
				if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
					WriteAlertMsg("表%s更新数据错误.",TempUp.sTableName);
					return -1;
				}
			}
		}

	}
	if(iWantUpdate==1){

		if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
			WriteAlertMsg("表%s更新数据错误.",TempUp.sTableName);
			return -1;
		}
	}

	if(WriteRollLogCtl(pSumLog,sTargetName)<0){
		WriteAlertMsg("写日志控制文件失败");
		return -1;
	}

	CloseFileOut(pAbnormal);
	CloseFileOutAll(pNormal);

	WriteProcMsg("对表%s出文件完毕,处理数%d,其中正常数%d,异常数%d",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt);
	if(iNormalCnt==0)
		WriteProcMsg("正常话单数为0，可能1:没有满足条件的特定话单,",
			"2:id=%s,split=%s的分离类型没有一条话单能匹配上",
				sTemplateRule,sSplitStr);
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt,sSplitNew);
	
	CommitWork();
	DisconnectDatabase();
	
/*将pFileControlList释放*/
	DestroyFileControlList(pControlList);
/*释放批价参数*/
	DistroyAllMem();

	
	return 0;
}
