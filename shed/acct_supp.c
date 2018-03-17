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
		printALERT("�ļ�%s��Ч.",GETTABLE);
		return -1;
	}
	if(IsFile(GETEXPR)==FALSE){
		printALERT("�ļ�%s��Ч.",GETTABLE);
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

/*ע�ṫʽ����*/
	RegPrepVar();
	RegAcctItemVar();
	CheckSysVar=CheckAcctItemVar;
/*���빫ʽ*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printALERT("���빫ʽ%s����::\n%s\n",
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

        /*ȡ�����м�¼���ض�����*/
        while(EGetSettItemToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_acct_item_e,
			(void **)&pTemp)==FOUND){

			/*������������쳣���¹ؼ����ж�����¼����ֻ�ۼ�һ��*/
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

/**������ݵ����ʱ�**/
        bzero((void*)&TempOut,sizeof(struct SettItemStructOut));

        strcpy(TempOut.sTableName,sTableName);

  	ptCur=pList;
	ACCTCTL.iNewCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		ptPre->iSettItemID=	iGetAcctItemID();
		if(EInsertStructToSettItem(ptPre,false,&TempOut)<0){
			printALERT("�����Ŀ����SETT_ITEM");
			return -1;
		}
		ACCTCTL.iNewCnt++;

	}
	if(EInsertStructToSettItem(NULL,true,&TempOut)<0){
		printALERT("�����Ŀ����SETT_ITEM");
		return -1;
	}
	return 0;	
}
int UpdateModItem2AcctItem(struct SettItemStruct *pList,char sTableName[])
{
	struct SettItemStructUp TempUp;
	struct	SettItemStruct *ptCur,*ptPre;

/**������ݵ����ʱ�**/
        bzero((void*)&TempUp,sizeof(struct SettItemStructUp));

        strcpy(TempUp.sTableName,sTableName);

	ptCur=pList;
	ACCTCTL.iModCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToSettItem(ptPre,false,&TempUp)<0){
			printALERT("������Ŀ����SETT_ITEM");
			return -1;
		}
		ACCTCTL.iModCnt++;

	}
	if(EUpdateStructToSettItem(NULL,true,&TempUp)<0){
		printALERT("������Ŀ����SETT_ITEM");
		return -1;
	}
	return 0;
}
/*����Ŀ�б���ܵ����ݿ���*/
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
		ERROR_EXIT(pTemp==NULL,"����SettItem�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct SettItemStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	pTemp->iCharge+=((struct SettItemStruct*)pData)->iCharge;
}

/*�ļ����ʲ�������*/
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

/*���ļ����ݵ��ú������ص��ڴ�*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("�����ļ�%s���ڴ�ʧ��.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}

/*��һ��ѭ������ÿ��������¼��������ʽ������˵���Ϣ��������*/
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
			printf("ִ�й�ʽ%sʧ��.\n",sExprName);
			return -1;
		}
		get_int_value("latn_id",pExprBuf,&iLatnID);
		get_int_value("split_flag",pExprBuf,&iSplitFlag);
		get_str_value("data_date",pExprBuf,sDataDate);
		get_str_value("user_type",pExprBuf,sUserType);
		get_int_value("opp_carrier_id",pExprBuf,&iOppCarrierID);
		get_int_value("sett_cycle_id",pExprBuf,&iSettCycleID);
		get_str_value("source_id",pExprBuf,sAcctSourceID);

		/*У׼�ֶ�*/
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
				WriteAlertMsg("����BINTREEʧ��SETT_ITEM_DAY");
				return -1;
			}

			/*Ĭ��Ϊ-1,��Ҳ��get_int_value��Ĭ��ֵ*/
			if(strlen(Temp.sUserType)>1&&iSplitFlag==-1){
				Temp.sUserType[1]=0;
				if(InsertBin(ppRoot,(void *)&Temp,
					data_search_bintree_acct_item_e,
					assign_insert_bintree_acct_item_e)<0){
					WriteAlertMsg("����BINTREEʧ��SETT_ITEM_DAY");
					return -1;
				}
			}
		}

		/*��ȡ�������begin_date��end_date*/
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

		/*ʱ�䲻�����������ļ���Ҫ����*/
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
			WriteAlertMsg("����%s�ļ�ʧ��",sFileName);
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
/*��ȡDATA_DATE�ֶ�*/
	FileBackupDate(sFileName,sDateRule,sDataDate);
	if(strcmp(sDataDate,"")==0){
		if(FileModifyDate(sFileName,sDataDate)!=0){
			printALERT("�ļ�%s���ɷ���",sFileName);
			return -1;
		}
	}
/*��ȡ�����ı���*/
	if(GetTableName(sModule,sBaseName,sAreaCode,GETTABLE,sTableName)!=0){

		printALERT("ģ��%s,����%s,�ļ�%s��ȡ��ʧ��",
			sModule,sAreaCode,sBaseName);
		return -1;
	}

/*���ó�Ա�ṹ*/
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

/**ͳ���ļ������ļ�ͳ�ƽ������ƽ���������**/
	if((Temp.iCnt=AcctTicket(sFileName,sSourceID,sExprName,ppRoot))<0){
		printALERT("���ļ�%s����ʧ��",sFileName);
		return -1;
	}

	if(WantInst(sOperType)==true){
/*��������⺯�����*/
		if(InsertTicket(sFileName,sTableName,sFileType)<0){
			printALERT("�Ա�%s ����ļ�%sʧ��",sTableName,sFileName);
			return -1;
		}
	}
/*д��־*/
	GetHostTime(Temp.sDealEndDate);

	if(SDInsertStructToAcctLog(&Temp,"ACCT_LOG")<0){
		printALERT("д����־��ACCT_LOGʧ��.");
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

	BINTREE *pRoot=NULL; /*�ļ�����*/

	strcpy(sItemTableName,sDefTableName);

/*��ʼ��ACCTDBӦ��λ�ú͹�ʽ·����ȫ�ֱ���*/
	if(InitAcctCtl()<0) return -1;

	iLatnID=GetLatnID(sAreaCode);

/*�����Ʊ�ؼ���*/
	if(CheckAcctDbCtrl(iLatnID,sModule)<0){
		printALERT("%s ģ���н������� %d ������.",sModule,iLatnID);
		return 0;
	}

	/*��ȡͳ�ƹ�ʽ*/
	if(GetExprFile(sModule,sFilter,GETEXPR,sExprName)!=0){
		printALERT("ģ��%s,�ļ�����%s��ȡ��ʽ�ļ���ʧ��",sModule,sFilter);
		return -1;
	}

	if(strlen(GETITEM)>0){
		/*�����Ҫ��ȡ����Ŀ���*/
		if(GetItemTableName(sFileType,sModule,sAreaCode,GETITEM,
			sItemTableName)!=0){
			printALERT("ģ��%s,�ļ�����%s,����%s��ȡ��ʧ��",
				sModule,sFileType,sAreaCode);
			return -1;

		}
	}
/*������빫ʽ*/
	RegRateExprFun();
	if(CompileStatExpr(sExprName)<0){
		printALERT("����ͳ�ƹ�ʽ�ļ�%sʧ��",sExprName);
		WriteErrStackAlert();
		return -1;
	}

/*����һ���ļ��б�*/
	if(dir2list(sSourcePath,sFilter,&ptHead)<0){
		printALERT("��ȡĿ¼%s��%sģʽ���ļ��б�ʧ��",
			sSourcePath,sFilter);
		return -1;
	}

/*���ÿ��Ʊ�ؼ���*/
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
			/*���̫С������*/
			strcpy((char*)(pTemp->pData),"");
			continue;
		}
		
		if(AcctLogCheck(sFileName,sSourceID,sModule)==true){
			printNORMAL("�ļ�%s�ѻ��ܣ����ļ��޷�����",sFileName);
			/*�Ѿ���������ļ�Ҳ������,�����ļ����������ظ�����*/
			strcpy((char*)(pTemp->pData),"");
			AddFileExtName(sTempName,"done");
			continue;
		}

	/*����ͨ�ô�����*/
		if((iCnt=ProcessFile(&pRoot,sTempName,sExprName,sFileType,
			sSourceID,sDateRule,sModule,sAreaCode,sOperType,
			sAppID,iTacheID))<0){

			/*�������˳����ظ�����*/
			AddFileExtName(sTempName,"err");

			RollbackWork();
			if(SetAcctDbCtrl(iLatnID,sModule,"A0A")<0) return -1;
			CommitWork();
			return -1;
		}
		
		iTotalCnt+=iCnt;
		
		/*�ﵽ���������*/
		if(iTotalCnt>=MAX_PROC_CNT) break;

		printNORMAL("����%s�ļ����",sFileName);
	}

/*�����˵���,�������ص��˵��ۼӵ�ƽ���������*/
	LoadAcctItemAndSummary(ACCTCTL.sDealBeginDate,
		ACCTCTL.sDealEndDate,sItemTableName,pRoot);

/*����sRowID�ļӵ�UPDATE��������ROWID�ļӵ�INSERT����*/
	TravelBin(pRoot,link_acct_item_out_up);

/**������ݵ�ͳ�Ʊ�**/
	if(AllItemList2AcctItem(pNewItemList,pModItemList,sItemTableName)<0){
		
		RollbackWork();
		if(SetAcctDbCtrl(iLatnID,sModule,"A0A")<0) return -1;
		CommitWork();
		printALERT("������ݵ�%sͳ�Ʊ����.",sItemTableName);
		return -1;
	}

	DestroyBin(pRoot);
	DestroyList((LIST*)pNewItemList);
	DestroyList((LIST*)pModItemList);
	pNewItemList=pModItemList=NULL;

/*���ÿ��Ʊ�ؼ���*/
	if(SetAcctDbCtrl(iLatnID,sModule,"A0A")<0) return -1;

	CommitWork();

	/*
	�����ļ������ļ��б�ͷ��ʼ����ֱ���Ѿ���������һ���ļ���
	������Ϊ�ﵽ�������������break���ļ��б����
	*/
	BackupFileList(ptLkHead,ptHead,sSourcePath,sBackPath);

	WriteProcPrint("����Ŀ¼%s�ɹ��������Ŀ��%d,������Ŀ��%d",
		sSourcePath,ACCTCTL.iNewCnt,ACCTCTL.iModCnt);

	return 0;
}
