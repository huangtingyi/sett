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
#include <bill_supp.h>


/*upd_supp.c中申明*/

int EUpdateXStr2Tab(char sXStr[],char sRowID[],
        int iUpdateFlag,struct MyTabColumnsStruct *ptLkHead,
	struct UStrStructUp *pTarget);

struct FileControlOutStruct *pOutput=NULL;
struct TinyRollLogStruct *pSumLog=NULL;


int GenOutputList(char sSplitType[],char sSourceID[],char sOldRec[],
	char sFileName[],char sNewRec[])
{
	int i,l;
	char sRecord[1024],msg[1024],sTargetName[256],sSplitNew[21];
	
	strcpy(sSplitNew,"");
	
	if(Item2OutListX(&pOutput,sSplitType,sNewRec,strlen(sNewRec),
		sSplitNew,msg)<0){
		WriteAlertMsg("生成原话单链表错误");
		return -1;
	}
	l=sprintf(sRecord,"%s::RLL\n",sOldRec);
	
	if(Item2OutListX(&pOutput,sSplitType,sRecord,l,sSplitNew,msg)<0){
		WriteAlertMsg("生成新话单链表错误");
		return -1;
	}

	for(i=0;i<strlen(sSplitNew);i++){

		sprintf(sTargetName,"%s.%c",sFileName,sSplitNew[i]);

		if(SumTinyRollLog(&pSumLog,sSourceID,sTargetName,2)<0){
			WriteAlertMsg("生成日志文件列表错误");
			return -1;
		}
	}
	
	return 0;	
}
int WantOutput(char sFileName[])
{
	if(strcmp(sFileName,"null")==0||
		strcmp(sFileName,"NULL")==0) return false;
	return true;
}
int main(int argc, char **argv)
{
	int i,l,iRet,iWantOutput=false;
	int iMissCnt=0,iRightCnt=0,iCnt=0,iTicketValid=0;
	
	char  sTableName[31],sCondition[128],sFileName[256],sHostTime[15];
	char  msg[2048],sNewName[8192],sBaseName[128],sRowID[19],sSplitNew[30];
	char  sTemplateRule[128],sInput[EXPRLEN],sModule[4],sNormalDir[256];
	char  sExprName[128],sSplitStr[10],sSplitType[10],sVisitAreaCode[10];
	
	char sOriLine[1024]; /*原始RATE结果记录，新结果记录*/
	char sOriIn[1024],sOriRes[1024],sNewRes[1024];/*原始输入、输出及新输出*/

	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	
	struct SplitRuleStruct *pSplitRule=NULL;
	struct	FileControlListStruct *pList;
	struct MyTabColumnsStruct *ptMyTab,*ptIoTab,*ptInTab,*ptOutTab;
	
	struct UStrStructUp *pTarget=NULL;
	
	if(argc!=9){
		printf("Usage %s tablename wherecause exprfile \
templateid splittype visitcode module filename.\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[2]);
	strcpy(sExprName,argv[3]);
	strcpy(sTemplateRule,argv[4]);
	strcpy(sSplitType,argv[5]);sSplitType[1]=0;/*这里只取1位*/
	strcpy(sVisitAreaCode,argv[6]);
	strncpy(sModule,argv[7],3);sModule[3]=0;
	strcpy(sFileName,argv[8]);
	
	iWantOutput=WantOutput(sFileName);
	pSumLog=NULL;

/*初始化批价参数*/
	MoveAllShmToMem();
	
/*到共享内存去将TEMPLATE_ID对应的SPLIT_TYPE串获取到，08.06.03*/
	if(GetTemplateSplitStr(sTemplateRule,sSplitStr)<0) return -1;

/*建立分离列表*/
	InitFileControlList(sTemplateRule,sSplitStr,&pFileControlList);
	
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
		WriteAlertPrint("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;

/*获取新的SQL语句用于获取记录*/
	if(InitMyTabColumns(sTableName,&ptMyTab)<0)return -1;

	GetXStrTableNameStmt(ptMyTab,sTableName,sCondition,sNewName);
	
/*printf("newname=%s\n",sNewName);
*/

	if(InitMyTabIoColumns(sTableName,&ptIoTab)<0) return -1;
	
	SetMyTabColumnOffset(ptMyTab);

	LinkMyTabColumnHead(ptIoTab,ptMyTab);
	
	GetIoMyTabColumnList(&ptIoTab,&ptInTab,&ptOutTab);
	
	SetMyTabColumnOffset(ptInTab);
	SetMyTabColumnOffset(ptOutTab);

/*初始化EUPDATE结构*/	
	if((pTarget=MallocUStrStructUp(ptOutTab))==NULL){
		WriteAlertPrint("分配内存UStrStructUp错误");
		return -1;
	}
	strcpy(pTarget->sTableName,sTableName);
	GetUpdSqlStmt(ptOutTab,sTableName,pTarget->sStatement);

/*printf("statement=%s\n",pTarget->sStatement);
*/

	GetHostTime(sHostTime);

	while(XStrTicket2Str(sNewName,"",sBaseName,sRowID,sOriLine)==true){

		iCnt++;

		/*将原始输入和原始结果字段重组合起来*/
		GetMyTabStr(ptInTab,sOriLine,sOriIn);
		GetMyTabStr(ptOutTab,sOriLine,sOriRes);
		
		TICKET.iOriLen=strlen(sOriIn);
		strcpy(TICKET.sOri,sOriIn);

		set_str_value("$FILENAME",pExprBuf,sBaseName);
		set_str_value("$MODULE",pExprBuf,sModule);
		set_str_value("$NOW",pExprBuf,sHostTime);
		set_str_value("$SPLITTYPE",pExprBuf,sSplitType);
		set_str_value("$AREACODE",pExprBuf,sVisitAreaCode);

		/*执行公式{这里可以获得pCur链表，link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			WriteAlertPrint("执行公式错误");
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		
/*如果重RATE发现话单无效则直接忽略*/
		if(iTicketValid<=0) continue;

/*按照指定的话单分离模版分离并批价*/
		pList=GetFileControlList(pFileControlList,sSplitType);
		
		if(pList!=NULL){
			if((pSplitRule=GetMultiSplitRule(pList))==NULL)
				continue;
/*在分离模版匹配不上的话单就不要了*/
			if(pSplitRule->iTicketTypeID<0) continue;
		}

		GenStdTicket();
	/**生成新的输出串**/
		GetMyTabStr(ptOutTab,TICKET.sStd,sNewRes);
	/*如果新生成的串和原串一致的直接忽略*/
		if(strcmp(sOriRes,sNewRes)==0){
			iMissCnt++;
			continue;
		}

	/*如果要写文件就写*/
		if(iWantOutput){
			/*将sOriLine、Ticket.sStd写到新文件中*/
			if(GenOutputList(sSplitType,sBaseName,sOriLine,
				sFileName,TICKET.sStd)<0){
				WriteAlertMsg("生成输出链表失败");
				return -1;
			}
		}
	/*将差异的记录形成批量的UPDATE语句更新到原表*/
		
		if(EUpdateXStr2Tab(sNewRes,sRowID,false,ptOutTab,pTarget)<0){
			WriteAlertMsg("表%s更新数据错误.",sTableName);
			return -1;
		}
		
		if((++iRightCnt)%10000==0){
	
			if(EUpdateXStr2Tab("","",true,ptOutTab,pTarget)<0){
				WriteAlertMsg("表%s更新数据错误.",sTableName);
				return -1;
			}

			CommitWork();
			WriteProcMsg("对表%s重批话单数目%d,其中不必重批价的话单数%d,必须重批话单数%d",
				sTableName,iCnt,iMissCnt,iRightCnt);
		}

	}
	
	
	if(EUpdateXStr2Tab("","",true,ptOutTab,pTarget)<0){
		WriteAlertMsg("表%s更新数据错误.",sTableName);
		return -1;
	}

	WriteProcMsg("对表%s重批话单数目%d,其中不必重批价的话单数%d,必须重批话单数%d",
		sTableName,iCnt,iMissCnt,iRightCnt);

	CommitWork();
	DisconnectDatabase();
	
/*输出话单*/
	if(iWantOutput){
		if(WriteRollLogCtl(pSumLog,sFileName)<0){
			WriteAlertMsg("写日志控制文件失败");
			return -1;
		}

		GetPathName(sFileName,sNormalDir);
		GetBaseName(sFileName,sBaseName);

		if(OutList2File(pOutput,sNormalDir,sBaseName,sSplitNew)<0){
			WriteAlertMsg("写正常话单文件%s失败",sFileName);
			return -1;
		}
	}
	
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iMissCnt,iRightCnt,sSplitNew);

	return 0;
}
