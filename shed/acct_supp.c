#include <hnixs.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <list.h>
#include <bintree.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <param_intf.h>
#include <ticket_field.h>

#include "sett_item.h"
#include "dbsupp.h"
#include "stt_ticket.h"
#include "acct_supp.h"
#include "appsupp.h"

#define MAX_PROC_CNT 500000

struct AcctCtlStruct
{
	int iNewCnt;
	int iModCnt;
	char sDealBeginDate[15];
	char sDealEndDate[15];
};

struct AcctCtlStruct ACCTCTL;
char GETTABLE[256],GETEXPR[256],GETITEM[256];
struct SettItemStruct *pNewItemList=NULL,*pModItemList=NULL;

int ProcessFile(BINTREE **ppRoot,char sFileName[],char sExprName[],
	char sFileType[],char sSourceID[],char sDateRule[],char sModule[],
	char sAreaCode[],char sOperType[],char sAppID[],int iTacheID);
void BackupFileList(struct FileControlStruct *ptHead,
	struct FileControlStruct *pEnd,char sSourcePath[],char sBackPath[]);

int SearchLatnByAreaCode(char sAreaCode[],struct LatnStruct **pptCur)
{
	struct LatnStruct *ptCur=NULL;

	if(SearchLatn(-1,&ptCur)==FOUND){
		while(ptCur!=NULL){
			if(strcmp(sAreaCode,ptCur->sAreaCode)==0){
				*pptCur=ptCur;
				return FOUND;
			}
			ptCur=ptCur->pNext;
		}
	}
	return NOTFOUND;
}
int GetLatnID(char sAreaCode[])
{
	struct LatnStruct *ptCur=NULL;

	if(SearchLatnByAreaCode(sAreaCode,&ptCur)==FOUND)
		return ptCur->iLatnID;
	return 0;

}
int GetTableName(char sModule[],char sBaseName[],char sAreaCode[],
	char sGetTable[],char sTableName[])
{
	char sCommand[256],sResult[1024];

	strcpy(sTableName,"");

	sprintf(sCommand,"%s %s %s %s",
		sGetTable,sModule,sBaseName,sAreaCode);

	if(exec2str(sCommand,sResult)!=0) return -1;

	GetSepStrX(sResult,'\t',0,30,sTableName);

	return 0;
}
int GetExprFile(char sModule[],char sFilter[],char sGetExpr[],char sExprName[])
{
	int l;
	char sCommand[256],sResult[1024],sPath[256];

	GetBillHome(sPath);

	sprintf(sCommand,"%s %s \"%s\"",sGetExpr,sModule,sFilter);

	if(exec2str(sCommand,sResult)!=0) return -1;

	strcpy(sExprName,sPath);
	strcat(sExprName,"expr/");
	l=strlen(sExprName);

	GetSepStrX(sResult,'\t',0,128,sExprName+l);

	return 0;
}
int GetItemTableName(char sFileType[],char sModule[],char sAreaCode[],
	char sGetItem[],char sItemTableName[])
{
	char sCommand[256],sResult[1024];

	sprintf(sCommand,"%s %s %s %s",sGetItem,sFileType,sModule,sAreaCode);

	if(exec2str(sCommand,sResult)!=0) return -1;

	GetSepStrX(sResult,'\t',0,128,sItemTableName);

	return 0;
}
int InitAcctCtl()
{
	char sPath[256];

	GetBillHome(sPath);

	bzero((void*)&ACCTCTL,sizeof(struct AcctCtlStruct));

	strcpy(ACCTCTL.sDealBeginDate,"21000101000000");
	strcpy(ACCTCTL.sDealEndDate,"19800101000000");

	sprintf(GETTABLE,"%sshell/gettablename.sh",sPath);
	sprintf(GETITEM,"%sshell/getitem.sh",sPath);
	sprintf(GETEXPR,"%sshell/getexprfile.sh",sPath);
	if(IsFile(GETTABLE)==FALSE){
		printALERT("文件%s无效.",GETTABLE);
		return -1;
	}
	if(IsFile(GETEXPR)==FALSE){
		printALERT("文件%s无效.",GETTABLE);
		return -1;
	}
	if(IsFile(GETITEM)==FALSE) strcpy(GETITEM,"");

	return 0;
}
int AcctLogCheck(char sFileName[],char sSourceID[],char sModule[])
{
	char	sCondition[128];
	struct AcctLogStruct Temp;

	sprintf(sCondition," WHERE SOURCE_ID='%s' AND\n\
			FILE_NAME='%s' AND \n\
			MODULE='%s'",
			sSourceID,sFileName,sModule);
	return SDGetAcctLogToStruct(&Temp,"ACCT_LOG",sCondition);
}
int CompileStatExpr(char sExprName[])
{
	int i,l=0;
	char	sInput[EXPRLEN],msg[8192];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];

	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,msg)!=0){
		printALERT("%s",msg);
		return -1;
	}

/*注册公式函数*/
	RegPrepVar();
	RegAcctItemVar();
	CheckSysVar=CheckAcctItemVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printALERT("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	return 0;
}
void LoadAcctItemAndSummary(char sDealBeginDate[],char sDealEndDate[],
	char sTableName[],BINTREE *pRoot)
{
	static int iFirstFlag=true;
        static struct SettItemStructIn TempIn;

	struct SettItemStruct Temp;
	struct SettItemStruct *pTemp=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"\n\
		WHERE SETT_ITEM_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
			SETT_ITEM_DATE<=to_date('%s','yyyymmddhh24miss')\n\
		",sDealBeginDate,sDealEndDate);

        /*取出表中记录加载二叉树*/
        while(EGetSettItemToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_acct_item_e,
			(void **)&pTemp)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
			if(pTemp->sRowID[0]!=0) continue;

			pTemp->iCharge+=	Temp.iCharge;
			strcpy(pTemp->sRowID,	Temp.sRowID);
		}
        }
}
int link_acct_item_out_up(void **ppData)
{
	struct SettItemStruct *pTemp=(struct SettItemStruct *)(*ppData);

	if(pTemp->sRowID[0]==0)
		InsertList((LIST**)&pNewItemList,(LIST*)pTemp);
	else	InsertList((LIST**)&pModItemList,(LIST*)pTemp);

	return 0;
}
int AppendNewItem2AcctItem(struct SettItemStruct *pList,char sTableName[])
{
	struct SettItemStructOut TempOut;
	struct	SettItemStruct *ptCur,*ptPre;

/**输出数据到累帐表**/
        bzero((void*)&TempOut,sizeof(struct SettItemStructOut));

        strcpy(TempOut.sTableName,sTableName);

  	ptCur=pList;
	ACCTCTL.iNewCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		ptPre->iSettItemID=	iGetAcctItemID();
		if(EInsertStructToSettItem(ptPre,false,&TempOut)<0){
			printALERT("输出帐目错误SETT_ITEM");
			return -1;
		}
		ACCTCTL.iNewCnt++;

	}
	if(EInsertStructToSettItem(NULL,true,&TempOut)<0){
		printALERT("输出帐目错误SETT_ITEM");
		return -1;
	}
	return 0;	
}
int UpdateModItem2AcctItem(struct SettItemStruct *pList,char sTableName[])
{
	struct SettItemStructUp TempUp;
	struct	SettItemStruct *ptCur,*ptPre;

/**输出数据到累帐表**/
        bzero((void*)&TempUp,sizeof(struct SettItemStructUp));

        strcpy(TempUp.sTableName,sTableName);

	ptCur=pList;
	ACCTCTL.iModCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToSettItem(ptPre,false,&TempUp)<0){
			printALERT("更新帐目错误SETT_ITEM");
			return -1;
		}
		ACCTCTL.iModCnt++;

	}
	if(EUpdateStructToSettItem(NULL,true,&TempUp)<0){
		printALERT("更新帐目错误SETT_ITEM");
		return -1;
	}
	return 0;
}
/*将账目列表汇总到数据库中*/
int AllItemList2AcctItem(struct SettItemStruct *pNewList,
	struct SettItemStruct *pModList,char sTableName[])
{
	int iRet;
	
	if((iRet=AppendNewItem2AcctItem(pNewList,sTableName))<0) return -1;
	
	return UpdateModItem2AcctItem(pModList,sTableName);
}
int data_search_bintree_acct_item_e(void *pValue,void*pData)
{
	struct SettItemStruct *pSource=(struct SettItemStruct *)pValue;
	struct SettItemStruct *pTarget=(struct SettItemStruct *)pData;
	int res;

	if((res=pSource->iLatnID-pTarget->iLatnID)!=0) return res;
	if((res=pSource->iAcctItemTypeID-pTarget->iAcctItemTypeID)!=0) return res;
	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;
	if((res=pSource->iOppCarrierID-pTarget->iOppCarrierID)!=0) return res;
	if((res=pSource->iSettCycleID-pTarget->iSettCycleID)!=0) return res;
	return 0;

}
void assign_insert_bintree_acct_item_e(void **ppData,void *pData)
{

	struct SettItemStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SettItemStruct));
		ERROR_EXIT(pTemp==NULL,"分配SettItem结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SettItemStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	pTemp->iCharge+=((struct SettItemStruct*)pData)->iCharge;
}

/*文件累帐并插入树*/
int AcctTicket(char sFileName[],char sSourceID[],char sExprName[],
	BINTREE **ppRoot)
{
	int	iAcctItemTypeID,iCharge,iCnt=0,iSplitFlag=-1;
	int	iOppCarrierID=-1,iSettCycleID=-1,iLatnID=-1;
	char	sState[2],sUserType[128],sBaseName[128];
	char	sDataDate[15],sAcctSourceID[31];

	static struct SettItemStruct	Temp;
	struct FileControlStruct *ptHead=NULL,*pTemp,*pList=NULL;

	strcpy(sDataDate,"");

/*将文件数据调用函数加载到内存*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件%s到内存失败.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}

/*作一个循环处理每条话单记录，并将公式的输出账单信息加入树中*/
	pList=ptHead;
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		TICKET.iOriLen=MY_MIN(pTemp->iLen,sizeof(TICKET.sOri)-1);
		memcpy((void*)(TICKET.sOri),pTemp->pData,TICKET.iOriLen);
		TICKET.sOri[TICKET.iOriLen]=0;

		GetBaseName(sFileName,sBaseName);

		set_str_value("$SOURCE",pExprBuf,sSourceID);
		set_str_value("$FILENAME",pExprBuf,sBaseName);
		if(ExecCode(pExprBuf)<0){
			printf("执行公式%s失败.\n",sExprName);
			return -1;
		}
		get_int_value("latn_id",pExprBuf,&iLatnID);
		get_int_value("split_flag",pExprBuf,&iSplitFlag);
		get_str_value("data_date",pExprBuf,sDataDate);
		get_str_value("user_type",pExprBuf,sUserType);
		get_int_value("opp_carrier_id",pExprBuf,&iOppCarrierID);
		get_int_value("sett_cycle_id",pExprBuf,&iSettCycleID);
		get_str_value("source_id",pExprBuf,sAcctSourceID);

		/*校准字段*/
		strcpy(sDataDate+8,"000000");
		sUserType[10]=0;
		if(strlen(sAcctSourceID)==0)strcpy(sAcctSourceID,"000000");
		sAcctSourceID[30]=0;

		while(GetAcctItemValue(&iAcctItemTypeID,&iCharge,sState)){

			if(iCharge==0) continue;

			Temp.iSettItemID=	0;
			Temp.iLatnID=		iLatnID;
			Temp.iAcctItemTypeID=	iAcctItemTypeID;
			Temp.iCharge=		iCharge;
			strcpy(Temp.sSettItemDate,sDataDate);

			GetHostTime(Temp.sCreatedDate);
			strcpy(Temp.sState,sState);
			strcpy(Temp.sUserType,sUserType);
			strcpy(Temp.sSourceID,sAcctSourceID);

			Temp.iOppCarrierID=	iOppCarrierID;
			Temp.iSettCycleID=	iSettCycleID;

			if(InsertBin(ppRoot,(void *)&Temp,
				data_search_bintree_acct_item_e,
				assign_insert_bintree_acct_item_e)<0){
				WriteAlertMsg("生成BINTREE失败SETT_ITEM_DAY");
				return -1;
			}

			/*默认为-1,这也是get_int_value的默认值*/
			if(strlen(Temp.sUserType)>1&&iSplitFlag==-1){
				Temp.sUserType[1]=0;
				if(InsertBin(ppRoot,(void *)&Temp,
					data_search_bintree_acct_item_e,
					assign_insert_bintree_acct_item_e)<0){
					WriteAlertMsg("生成BINTREE失败SETT_ITEM_DAY");
					return -1;
				}
			}
		}

		/*获取批处理的begin_date和end_date*/
		if(strcmp(sDataDate,ACCTCTL.sDealEndDate)>0)
			strcpy(ACCTCTL.sDealEndDate,sDataDate);
		if(strcmp(sDataDate,ACCTCTL.sDealBeginDate)<0)
			strcpy(ACCTCTL.sDealBeginDate,sDataDate);

		iCnt++;
	}

	if(ChkTime(ACCTCTL.sDealBeginDate)<0)return -1;
	if(ChkTime(ACCTCTL.sDealEndDate)<0)return -1;

      	listfree(&pList);

	return	iCnt;
}
void BackupFileList(struct FileControlStruct *ptHead,
	struct FileControlStruct *pEnd,char sSourcePath[],char sBackPath[])
{
	char	sCommand[256],*pc;
	char	sTemp[128],sFileName[128],sBackName[128],sBaseName[128];
	struct FileControlStruct *pTemp;

	while(ptHead!=pEnd){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sTemp,(char*)(pTemp->pData),pTemp->iLen);
		sTemp[pTemp->iLen]=0;

		/*时间不满足条件的文件不要处理*/
		if(strlen(sTemp)==0) continue;

		if((pc=strchr(sTemp,'\n'))!=NULL) *pc=0;
		GetBaseName(sTemp,sBaseName);
		sprintf(sFileName,"%s%s",sSourcePath,sBaseName);
		sprintf(sBackName,"%s%s",sBackPath,sBaseName);

		if(strlen(sBackPath)==0)
			sprintf(sCommand,"rm -f %s",sFileName);
		else
			sprintf(sCommand,"mv %s %s",sFileName,sBackName);

		if(system(sCommand)!=0){
			WriteAlertMsg("备份%s文件失败",sFileName);
			break;
		}
	}
}
int WantInst(char sOperType[])
{
	if(sOperType[0]=='3') return true;
	return false;
}
int ProcessFile(BINTREE **ppRoot,char sFileName[],char sExprName[],
	char sFileType[],char sSourceID[],char sDateRule[],char sModule[],
	char sAreaCode[],char sOperType[],char sAppID[],int iTacheID)
{
	struct AcctLogStruct Temp;
	char sBaseName[256],sTableName[31],sDataDate[15];

	GetBaseName(sFileName,sBaseName);
/*获取DATA_DATE字段*/
	FileBackupDate(sFileName,sDateRule,sDataDate);
	if(strcmp(sDataDate,"")==0){
		if(FileModifyDate(sFileName,sDataDate)!=0){
			printALERT("文件%s不可访问",sFileName);
			return -1;
		}
	}
/*获取改入库的表名*/
	if(GetTableName(sModule,sBaseName,sAreaCode,GETTABLE,sTableName)!=0){

		printALERT("模块%s,区号%s,文件%s获取表失败",
			sModule,sAreaCode,sBaseName);
		return -1;
	}

/*设置成员结构*/
	bzero((void*)&Temp,sizeof(struct AcctLogStruct));

	GetHostTime(Temp.sDealBeginDate);
	strcpy(Temp.sTableName, sTableName);
	strcpy(Temp.sFileType,  sFileType);
	strcpy(Temp.sSourceID,  sSourceID);
	strcpy(Temp.sModule,    sModule);
	strcpy(Temp.sState,     "A");
	Temp.iByte=     	FileSize(sFileName);
	strcpy(Temp.sFileName,  sBaseName);
	strcpy(Temp.sDataDate,  sDataDate);
	strcpy(Temp.sDataDate+8,"000000");
	strcpy(Temp.sOperType,  sOperType);
	strcpy(Temp.sAppID,  	sAppID);
	Temp.iTacheID=		iTacheID;

/**统计文件，将文件统计结果加入平衡二叉树中**/
	if((Temp.iCnt=AcctTicket(sFileName,sSourceID,sExprName,ppRoot))<0){
		printALERT("对文件%s累账失败",sFileName);
		return -1;
	}

	if(WantInst(sOperType)==true){
/*调用主入库函数入库*/
		if(InsertTicket(sFileName,sTableName,sFileType)<0){
			printALERT("对表%s 入库文件%s失败",sTableName,sFileName);
			return -1;
		}
	}
/*写日志*/
	GetHostTime(Temp.sDealEndDate);

	if(SDInsertStructToAcctLog(&Temp,"ACCT_LOG")<0){
		printALERT("写入日志表ACCT_LOG失败.");
		WriteErrStackAlert();
		return -1;
	}

	return Temp.iCnt;
}

int AcctDBMain(char sSourceID[],char sSourcePath[],char sFileType[],
	char sFilter[],char sBackPath[],char sModule[],char sAreaCode[],
	char sDefTableName[],char sDateRule[],char sOperType[],
	char sAppID[],int iTacheID)
{
	int iLatnID=0,iCnt=0,iTotalCnt=0;
	char sFileName[256],sTempName[256],sExprName[256],sItemTableName[32];
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;

	BINTREE *pRoot=NULL; /*文件累帐*/

	strcpy(sItemTableName,sDefTableName);

/*初始化ACCTDB应用位置和公式路径到全局变量*/
	if(InitAcctCtl()<0) return -1;

	iLatnID=GetLatnID(sAreaCode);

/*检查控制表关键字*/
	if(CheckAcctDbCtrl(iLatnID,sModule)<0){
		printALERT("%s 模块有进程锁定 %d 的数据.",sModule,iLatnID);
		return 0;
	}

	/*获取统计公式*/
	if(GetExprFile(sModule,sFilter,GETEXPR,sExprName)!=0){
		printALERT("模块%s,文件类型%s获取公式文件名失败",sModule,sFilter);
		return -1;
	}

	if(strlen(GETITEM)>0){
		/*如果必要获取累账目标表*/
		if(GetItemTableName(sFileType,sModule,sAreaCode,GETITEM,
			sItemTableName)!=0){
			printALERT("模块%s,文件类型%s,区号%s获取表失败",
				sModule,sFileType,sAreaCode);
			return -1;

		}
	}
/*处理编译公式*/
	RegRateExprFun();
	if(CompileStatExpr(sExprName)<0){
		printALERT("编译统计公式文件%s失败",sExprName);
		WriteErrStackAlert();
		return -1;
	}

/*生成一个文件列表*/
	if(dir2list(sSourcePath,sFilter,&ptHead)<0){
		printALERT("获取目录%s的%s模式的文件列表失败",
			sSourcePath,sFilter);
		return -1;
	}

/*设置控制表关键字*/
	if(SetAcctDbCtrl(iLatnID,sModule,"A0X")<0) return -1;

	CommitWork();

	ptLkHead=ptHead;

	while(ptHead!=NULL){

		pTemp = ptHead;
		ptHead = ptHead->pNext;

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);

		sprintf(sTempName,"%s%s",sSourcePath,sFileName);
		
		if(FileModifyDiff(sTempName)<1){
			/*间隔太小不备份*/
			strcpy((char*)(pTemp->pData),"");
			continue;
		}
		
		if(AcctLogCheck(sFileName,sSourceID,sModule)==true){
			printNORMAL("文件%s已汇总，该文件无法处理",sFileName);
			/*已经处理过的文件也不备份,并将文件改名避免重复加载*/
			strcpy((char*)(pTemp->pData),"");
			AddFileExtName(sTempName,"done");
			continue;
		}

	/*调用通用处理函数*/
		if((iCnt=ProcessFile(&pRoot,sTempName,sExprName,sFileType,
			sSourceID,sDateRule,sModule,sAreaCode,sOperType,
			sAppID,iTacheID))<0){

			/*避免累账程序重复加载*/
			AddFileExtName(sTempName,"err");

			RollbackWork();
			if(SetAcctDbCtrl(iLatnID,sModule,"A0A")<0) return -1;
			CommitWork();
			return -1;
		}
		
		iTotalCnt+=iCnt;
		
		/*达到处理最大数*/
		if(iTotalCnt>=MAX_PROC_CNT) break;

		printNORMAL("处理%s文件完成",sFileName);
	}

/*加载账单表,并将加载的账单累加到平衡二叉树上*/
	LoadAcctItemAndSummary(ACCTCTL.sDealBeginDate,
		ACCTCTL.sDealEndDate,sItemTableName,pRoot);

/*将有sRowID的加到UPDATE链表，将无ROWID的加到INSERT链表*/
	TravelBin(pRoot,link_acct_item_out_up);

/**输出数据到统计表**/
	if(AllItemList2AcctItem(pNewItemList,pModItemList,sItemTableName)<0){
		
		RollbackWork();
		if(SetAcctDbCtrl(iLatnID,sModule,"A0A")<0) return -1;
		CommitWork();
		printALERT("输出数据到%s统计表出错.",sItemTableName);
		return -1;
	}

	DestroyBin(pRoot);
	DestroyList((LIST*)pNewItemList);
	DestroyList((LIST*)pModItemList);
	pNewItemList=pModItemList=NULL;

/*设置控制表关键字*/
	if(SetAcctDbCtrl(iLatnID,sModule,"A0A")<0) return -1;

	CommitWork();

	/*
	备份文件，从文件列表开头开始处理，直到已经处理的最后一个文件，
	即：因为达到最大处理数据量而break或文件列表结束
	*/
	BackupFileList(ptLkHead,ptHead,sSourcePath,sBackPath);

	WriteProcPrint("处理目录%s成功，输出帐目数%d,更新帐目数%d",
		sSourcePath,ACCTCTL.iNewCnt,ACCTCTL.iModCnt);

	return 0;
}
