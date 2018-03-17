
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwcoding.h>
#include <wwdb.h>

#include <list.h>
#include <gen_supp.h>
#include <param_intf.h>
#include <appsupp.h>

void printsourceNORMAL(char sSourceID[],char *fmt,...)
{
	va_list	argptr;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	sprintf(sFileName,"%s%s.%s.log",sPath,AppRes.sAppName,sSourceID);

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	PrintLog(sFileName,"时间:%s 消息:%s\n",sHostTime,sMessage);
}

void printNORMAL(char *fmt,...)
{
	va_list	argptr;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	sprintf(sFileName,"%s%s.log",sPath,AppRes.sAppName);

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	PrintLog(sFileName,"时间:%s 消息:%s\n",sHostTime,sMessage);
	printf("时间:%s 消息:%s\n",sHostTime,sMessage);
}

void printALERT(char *fmt,...)
{
	va_list	argptr;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	sprintf(sFileName,"%ssh.alert.log",sPath);

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	PrintLog(sFileName,"应用%s,告警!时间:%s 消息:%s\n",
		AppRes.sAppName,sHostTime,sMessage);
	printf("应用%s,告警!时间:%s 消息:%s\n",
		AppRes.sAppName,sHostTime,sMessage);
}
void GetTaskPath(char sSourcePath[],char sSourceID[],char sTargetPath[])
{
	char *env;

	strcpy(sTargetPath,sSourcePath);

	ReplaceStr(sTargetPath,"$(SOURCE_ID)",sSourceID);

	if((env=getenv("TICKETROOT"))!=NULL)
		ReplaceStr(sTargetPath,"$(TICKETROOT)",env);
	RegularDir(sTargetPath);
}
int ShmIniName(char sFileName[])
{
	if(strcmp(sFileName,"shm")==0) return true;
	return false;
}
int FlowIniName(char sFileName[],int *piFlowID)
{
	*piFlowID=0;

	if(strncmp(sFileName,"flow",4)==0){
		*piFlowID=atoi(sFileName+4);
		return true;
	}
	return false;
}
int GetTacheID(int iParamID,int iFlowID)
{
	struct FlowTaskStruct *pFlowTask=NULL;
	struct FlowTacheStruct *pFlowTache=NULL;

	if(SearchFlowTask(iParamID,&pFlowTask)==NOTFOUND) return -1;

	if(SearchFlowTache(pFlowTask->iTaskID,iFlowID,&pFlowTache)
		==NOTFOUND) return -1;

	return pFlowTache->iTacheID;
}

void mvitem_str2pick(char sLine[],struct PickParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct PickParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sSourceID);
	GetTabStrX(sLine,2,80,p->sOppPath);	RegularDir(p->sOppPath);
	GetTabStrX(sLine,3,80,p->sLocalPath);	RegularDir(p->sLocalPath);
	GetTabStrX(sLine,4,80,p->sOppBkupPath);	RegularDir(p->sOppBkupPath);
	GetTabStrX(sLine,5,16,p->sIp);
	GetTabStrX(sLine,6,20,p->sUserName);
	GetTabStrX(sLine,7,20,p->sPasswd);

	/*用户无密码时转换*/
	if(strcmp(p->sPasswd,"nil")==0)
		strcpy(p->sPasswd,"");
	
	GetTabStrX(sLine,8,20,p->sFilter);
	TrimAllX(p->sFilter,'"');
	
	GetTabStrX(sLine,9,2,sTemp);
	p->iSeqOff=atoi(sTemp);

	GetTabStrX(sLine,10,2,sTemp);
	p->iSeqLen=atoi(sTemp);

	GetTabStrX(sLine,11,1,p->sDeleteType);
	
	GetTabStrX(sLine,12,5,p->sOutType);

	GetTabStrX(sLine,13,5,p->sAppID);
	GetTabStr(sLine,14,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);

	strcpy(p->sState,"A");
}
int FInitPickList(char sFileName[],int iGroupID,
	struct PickParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	PickParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;
/*备份链表*/
	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2pick(sTemp,&Temp);
/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;

		if((ptCur=(struct PickParamStruct*)malloc(
			sizeof(struct PickParamStruct)))==NULL){
			WriteAlertPrint("分配内存PickParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct PickParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}
void mvitem_task2pick(struct PickTaskParamStruct *pi,int iTacheID,
	struct SourceDescStruct *ps,struct TaskParamStruct *ptp,
	struct PickParamStruct *po)
{
	bzero((void*)po,sizeof(struct PickParamStruct));

	strcpy(po->sSourceID,pi->sSourceID);
	
	po->iGroupID=	pi->iGroupID;
	
	strcpy(po->sOppPath,	pi->sOppPath);
	strcpy(po->sOppBkupPath,pi->sOppBkupPath);
	strcpy(po->sIp,		pi->sIp);
	strcpy(po->sUserName,	pi->sUserName);
	strcpy(po->sPasswd,	pi->sPasswd);
	strcpy(po->sFilter,	pi->sFilter);

	po->iSeqOff=	pi->iSeqOff;
	po->iSeqLen=	pi->iSeqLen;
	
	strcpy(po->sDeleteType, pi->sDeleteType);

/*如果TASK_PARAM指定输出，则从TASK_PARAM，未指定则默认为SOURCE_DESC*/
	if(strlen(ptp->sOutType)!=0)
		strcpy(po->sOutType,	ptp->sOutType);
	else
		strcpy(po->sOutType,	ps->sFileType);

	GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sLocalPath);
	strcpy(po->sAppID,	ptp->sAppID);

	po->iTacheID=		iTacheID;
	strcpy(po->sState,	"A");
}
int GetFlowPickParamList(int iFlowID,int iGroupID,
	struct PickParamStruct **pptHead)
{
	int iTacheID=0;
	struct PickTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct PickParamStruct *pTemp;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;
		
		if(SearchPickTaskParam(pPreSrc->sSourceID,iGroupID,&pParam)
			==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 PICK_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		
		if((pTemp=(struct PickParamStruct*)malloc(
			sizeof(struct PickParamStruct)))==NULL){
			WriteAlertPrint("分配内存PickParamStruct失败,退出!");
			return -1;
		}

		mvitem_task2pick(pParam,iTacheID,pPreSrc,pTaskParam,pTemp);

		InsertListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetPickParamList(char sFileName[],int iGroupID,
	struct PickParamStruct **pptHead)
{
	int iFlowID=0;
	struct PickParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowPickParamList(iFlowID,iGroupID,pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitPickParam)<0,
			"获取PICK_PARAM错误");

		if (SearchPickParam(iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitPickList(sFileName,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}

void mvitem_str2prep(char sLine[],struct PrepParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct PrepParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sSourceID);
	GetTabStrX(sLine,2,15,p->sMsc);
	GetTabStrX(sLine,3,5,p->sAreaCode);
	GetTabStrX(sLine,4,80,p->sExprFile);
	GetTabStrX(sLine,5,20,p->sFilter);	TrimAllX(p->sFilter,'"');
	GetTabStrX(sLine,6,80,p->sSourcePath);	RegularDir(p->sSourcePath);
	GetTabStrX(sLine,7,80,p->sBackPath);	RegularDir(p->sBackPath);
	GetTabStrX(sLine,8,80,p->sNormalPath);	RegularDir(p->sNormalPath);
	
	strcpy(p->sErrPath,p->sNormalPath);
	GetTabStrX(sLine,9,3,p->sModule);
	
	GetTabStrX(sLine,10,10,p->sSplit);

	GetTabStr(sLine,11,sTemp);AllTrim(sTemp);
	p->iStartPos=atoi(sTemp);
	GetTabStr(sLine,12,sTemp);AllTrim(sTemp);
	p->iKeyLen=atoi(sTemp);

	GetTabStrX(sLine,13,3,p->sChkMod);
	
	GetTabStrX(sLine,14,1,p->sUserType);

	GetTabStrX(sLine,15,6,p->sInType);
	GetTabStrX(sLine,16,6,p->sOutType);
	GetTabStrX(sLine,17,5,p->sAppID);
	GetTabStr(sLine,18,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);
	
	strcpy(p->sState,"A");
}

int FInitPrepList(char sFileName[],int iGroupID,
	struct PrepParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	PrepParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2prep(sTemp,&Temp);

/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;
		
		if((ptCur=(struct PrepParamStruct*)malloc(
			sizeof(struct PrepParamStruct)))==NULL){
			WriteAlertPrint("分配内存PrepParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct PrepParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}
void mvitem_task2prep(struct PrepTaskParamStruct *pi,int iTacheID,
	struct SourceDescStruct *ps,struct TaskParamStruct *ptp,
	struct PrepParamStruct *po)
{
	bzero((void*)po,sizeof(struct PrepParamStruct));

	strcpy(po->sSourceID,pi->sSourceID);
	
	po->iGroupID=	pi->iGroupID;
	
	strcpy(po->sMsc,	pi->sMsc);
	strcpy(po->sAreaCode,	pi->sAreaCode);
	strcpy(po->sExprFile,	pi->sExprFile);

	strcpy(po->sModule,	pi->sModule);
	
	po->iStartPos=	pi->iStartPos;
	po->iKeyLen=	pi->iKeyLen;
	strcpy(po->sChkMod,	pi->sChkMod);

	if(strlen(ptp->sInFilter)!=0)
		strcpy(po->sFilter,	ptp->sInFilter);
	else	strcpy(po->sFilter,	ps->sFilter);
	
	if(strlen(ptp->sInType)!=0)
		strcpy(po->sInType,	ptp->sInType);
	else	strcpy(po->sInType,	ps->sFileType);

	strcpy(po->sOutType,	ptp->sOutType);
	
	GetTaskPath(ptp->sInPath,pi->sSourceID,po->sSourcePath);
	GetTaskPath(ptp->sBakPath,pi->sSourceID,po->sBackPath);
	GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sNormalPath);
	GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sErrPath);
	
	strcpy(po->sAppID,	ptp->sAppID);

	po->iTacheID=		iTacheID;
	strcpy(po->sState,	"A");
}
int GetFlowPrepParamList(int iFlowID,int iGroupID,
	struct PrepParamStruct **pptHead)
{
	int iTacheID=0;
	struct PrepTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct PrepParamStruct *pTemp;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;
		
		if(SearchPrepTaskParam(pPreSrc->sSourceID,iGroupID,&pParam)
			==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 PREP_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		
		if((pTemp=(struct PrepParamStruct*)malloc(
			sizeof(struct PrepParamStruct)))==NULL){
			WriteAlertPrint("分配内存PrepParamStruct失败,退出!");
			return -1;
		}

		mvitem_task2prep(pParam,iTacheID,pPreSrc,pTaskParam,pTemp);

		InsertListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetPrepParamList(char sFileName[],int iGroupID,
	struct PrepParamStruct **pptHead)
{
	int iFlowID=0;
	struct PrepParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowPrepParamList(iFlowID,iGroupID,pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitPrepParam)<0,
			"获取PREP_PARAM错误");

		if (SearchPrepParam(iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitPrepList(sFileName,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}

void mvitem_str2disp(char sLine[],struct DispParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct DispParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,80,p->sSourcePath);	RegularDir(p->sSourcePath);
	GetTabStrX(sLine,2,20,p->sFilter);	TrimAllX(p->sFilter,'"');
	GetTabStrX(sLine,3,80,p->sDestPath1);	RegularDir(p->sDestPath1);
	GetTabStrX(sLine,4,80,p->sDestPath2);	RegularDir(p->sDestPath2);
	GetTabStrX(sLine,5,80,p->sDestPath3);	RegularDir(p->sDestPath3);
	GetTabStrX(sLine,6,80,p->sDestPath4);	RegularDir(p->sDestPath4);
	
	strcpy(p->sState,"A");
}

int FInitDispList(char sFileName[],int iGroupID,
	struct DispParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	DispParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2disp(sTemp,&Temp);

/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;

		if((ptCur=(struct DispParamStruct*)malloc(
			sizeof(struct DispParamStruct)))==NULL){
			WriteAlertPrint("分配内存DispParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct DispParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}
int GetDispParamList(char sFileName[],int iGroupID,
	struct DispParamStruct **pptHead)
{
	
	struct DispParamStruct *ptLkHead=NULL;

/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitDispParam)<0,
			"获取DISP_PARAM错误");

		if (SearchDispParam(iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitDispList(sFileName,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}

void mvitem_str2bill(char sLine[],struct BillParamStruct *p)
{
	char *pc,sTemp[256];

	bzero((void*)p,sizeof(struct BillParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sSourceID);
	GetTabStrX(sLine,2,20,p->sFilter);	TrimAllX(p->sFilter,'"');
	GetTabStrX(sLine,3,80,p->sSourcePath);	RegularDir(p->sSourcePath);
	GetTabStrX(sLine,4,80,p->sBackPath);	RegularDir(p->sBackPath);
	GetTabStrX(sLine,5,80,p->sNormalPath);	RegularDir(p->sNormalPath);

	strcpy(p->sErrPath,p->sNormalPath);

	GetTabStrX(sLine,6,40,p->sUserType);
	GetTabStrX(sLine,7,80,p->sTemplateID);
	GetTabStrX(sLine,8,20,p->sSplitStr);
	GetTabStrX(sLine,9,10,sTemp);
	if((pc=strchr(sTemp,':'))==NULL)
		strncpy(p->sBelongCode,sTemp,5);
	else
		strncpy(p->sBelongCode,pc,5);
	p->sBelongCode[5]=0;

	GetTabStrX(sLine,10,3,p->sModule);

	GetTabStrX(sLine,11,10,p->sSplit);
	
	GetTabStr(sLine,12,sTemp);AllTrim(sTemp);
	p->iStartPos=atoi(sTemp);

	GetTabStr(sLine,13,sTemp);AllTrim(sTemp);
	p->iKeyLen=atoi(sTemp);

	GetTabStrX(sLine,14,1,p->sBatchFlag);

	GetTabStrX(sLine,15,5,p->sAppID);
	GetTabStr(sLine,16,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);

	strcpy(p->sState,"A");
}

int FInitBillList(char sFileName[],char sAppCode[],int iGroupID,
	struct BillParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	BillParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2bill(sTemp,&Temp);

/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;
/*加入APPCODE用于前台程序区分*/
		strcpy(Temp.sAppCode,sAppCode);

		if((ptCur=(struct BillParamStruct*)malloc(
			sizeof(struct BillParamStruct)))==NULL){
			WriteAlertPrint("分配内存BillParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct BillParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}
int mvitem_task2billlist(struct BillTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct BillParamStruct **pptHead)
{
	
	int i=0;
	char sFilter[21],sTemp[256];
	struct BillParamStruct *po=NULL;
	
	*pptHead=NULL;
	strcpy(sFilter,"");
	strcpy(sTemp,ptp->sInFilter);

	while(1){
		GetSepStrX(sTemp,';',i++,20,sFilter);
		if(strlen(sFilter)==0) break;

		if((po=(struct BillParamStruct*)malloc(
			sizeof(struct BillParamStruct)))==NULL){
			WriteAlertPrint("分配内存BillParamStruct失败,退出!");
			return -1;
		}
	
		bzero((void*)po,sizeof(struct BillParamStruct));

		strcpy(po->sSourceID,pi->sSourceID);
	
		po->iGroupID=	pi->iGroupID;
	
		strcpy(po->sUserType,	pi->sUserType);
		strcpy(po->sTemplateID,	pi->sTemplateID);
		strcpy(po->sSplitStr,	pi->sSplitStr);
		strcpy(po->sBelongCode,	pi->sBelongCode);

		strcpy(po->sModule,	pi->sModule);
		strcpy(po->sSplit,	pi->sSplit);
	

		po->iStartPos=		pi->iStartPos;
		po->iKeyLen=		pi->iKeyLen;
	
		strcpy(po->sFilter,	sFilter);
		strcpy(po->sInType,	ptp->sInType);
		strcpy(po->sOutType,	ptp->sOutType);
	
		GetTaskPath(ptp->sInPath,pi->sSourceID,po->sSourcePath);
		GetTaskPath(ptp->sBakPath,pi->sSourceID,po->sBackPath);
		GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sNormalPath);
		GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sErrPath);

		strcpy(po->sAppID,	ptp->sAppID);
		po->iTacheID=		iTacheID;

		strcpy(po->sState,	"A");

		InsertListTail((LIST**)pptHead,(LIST*)po);
	}
	return 0;
}
int GetFlowBillParamList(int iFlowID,char sAppCode[],int iGroupID,
	struct BillParamStruct **pptHead)
{
	int iTacheID=0;
	struct BillTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct BillParamStruct *pTemp;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;
		
		if(SearchBillTaskParam(pPreSrc->sSourceID,sAppCode,iGroupID,
			&pParam)==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 BILL_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}

		if(mvitem_task2billlist(pParam,iTacheID,pTaskParam,&pTemp)<0){
			WriteAlertMsg("分配内存错误");
			return -1;
		}
		if(pTemp!=NULL)
			AppendListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetBillParamList(char sFileName[],char sAppCode[],int iGroupID,
	struct BillParamStruct **pptHead)
{
	int iFlowID=0;
	struct BillParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowBillParamList(iFlowID,sAppCode,iGroupID,pptHead)<0)
			return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitBillParam)<0,
			"获取PREP_PARAM错误");

		if (SearchBillParam(sAppCode,iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitBillList(sFileName,sAppCode,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}

void mvitem_str2inst(char sLine[],struct InstParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct InstParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sSourceID);
	GetTabStrX(sLine,2,4,p->sFileType);
	GetTabStrX(sLine,3,12,p->sDateRule);	
	GetTabStrX(sLine,4,80,p->sSourcePath);	RegularDir(p->sSourcePath);
	GetTabStrX(sLine,5,80,p->sBackPath);

	if(strcmp(p->sBackPath,"/dev/null")==0) strcpy(p->sBackPath,"");
	else RegularDir(p->sBackPath);

	GetTabStrX(sLine,6,20,p->sFilter); TrimAllX(p->sFilter,'"');
/*这里的第七个参数原来是gettablename.sh脚本，现在不用了*/
	GetTabStrX(sLine,7,5,p->sBelongCode);
	GetTabStrX(sLine,8,3,p->sOperType);
	GetTabStrX(sLine,9,3,p->sModule);
	
	GetTabStrX(sLine,10,5,p->sAppID);
	GetTabStr(sLine,11,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);

	strcpy(p->sState,"A");
}

int FInitInstList(char sFileName[],int iGroupID,
	struct InstParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	InstParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2inst(sTemp,&Temp);

/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;

		if((ptCur=(struct InstParamStruct*)malloc(
			sizeof(struct InstParamStruct)))==NULL){
			WriteAlertPrint("分配内存InstParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct InstParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}
int mvitem_task2instlist(struct InstTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct InstParamStruct **pptHead)
{
	int i=0;
	char sFilter[21],sTemp[256];
	struct InstParamStruct *po=NULL;

	*pptHead=NULL;
	strcpy(sFilter,"");
	strcpy(sTemp,ptp->sInFilter);

	while(1){
		GetSepStrX(sTemp,';',i++,20,sFilter);
		if(strlen(sFilter)==0) break;

		if((po=(struct InstParamStruct*)malloc(
			sizeof(struct InstParamStruct)))==NULL){
			WriteAlertPrint("分配内存InstParamStruct失败,退出!");
			return -1;
		}

		bzero((void*)po,sizeof(struct InstParamStruct));

		strcpy(po->sSourceID,pi->sSourceID);
	
		po->iGroupID=	pi->iGroupID;
		
		strcpy(po->sOperType,	pi->sOperType);
		strcpy(po->sDateRule,	pi->sDateRule);
		strcpy(po->sBelongCode,	pi->sBelongCode);

		strcpy(po->sModule,	pi->sModule);
	
		strcpy(po->sFilter,	sFilter);
		strcpy(po->sFileType,	ptp->sInType);
	
		GetTaskPath(ptp->sInPath,pi->sSourceID,po->sSourcePath);
		GetTaskPath(ptp->sBakPath,pi->sSourceID,po->sBackPath);

		strcpy(po->sAppID,	ptp->sAppID);
		po->iTacheID=		iTacheID;

		strcpy(po->sState,	"A");
		
		InsertListTail((LIST**)pptHead,(LIST*)po);
	}
	return 0;
}
int GetFlowInstParamList(int iFlowID,int iGroupID,
	struct InstParamStruct **pptHead)
{
	int iTacheID=0;
	struct InstTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct InstParamStruct *pTemp=NULL;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;
		
		if(SearchInstTaskParam(pPreSrc->sSourceID,iGroupID,&pParam)
			==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 INST_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}

		if(mvitem_task2instlist(pParam,iTacheID,pTaskParam,&pTemp)<0){
			WriteAlertMsg("分配内存错误");
			return -1;
		}

		if(pTemp!=NULL)
			AppendListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetInstParamList(char sFileName[],int iGroupID,
	struct InstParamStruct **pptHead)
{
	int iFlowID=0;
	struct InstParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowInstParamList(iFlowID,iGroupID,pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitInstParam)<0,
			"获取PREP_PARAM错误");

		if (SearchInstParam(iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitInstList(sFileName,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}

void mvitem_str2acct(char sLine[],struct AcctParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct AcctParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sSourceID);
	GetTabStrX(sLine,2,4,p->sFileType);
	GetTabStrX(sLine,3,3,p->sOperType);
	GetTabStrX(sLine,4,12,p->sDateRule);	
	GetTabStrX(sLine,5,80,p->sSourcePath);	RegularDir(p->sSourcePath);
	GetTabStrX(sLine,6,80,p->sBackPath);

	if(strcmp(p->sBackPath,"/dev/null")==0) strcpy(p->sBackPath,"");
	else RegularDir(p->sBackPath);

	GetTabStrX(sLine,7,20,p->sFilter); TrimAllX(p->sFilter,'"');
/*这里的第七个参数原来是gettablename.sh脚本，现在不用了*/
	GetTabStrX(sLine,8,5,p->sBelongCode);
	GetTabStrX(sLine,9,3,p->sModule);
	
	GetTabStrX(sLine,10,5,p->sAppID);
	GetTabStr(sLine,11,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);

	strcpy(p->sState,"A");
}

int FInitAcctList(char sFileName[],int iGroupID,
	struct AcctParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	AcctParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2acct(sTemp,&Temp);

/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;

		if((ptCur=(struct AcctParamStruct*)malloc(
			sizeof(struct AcctParamStruct)))==NULL){
			WriteAlertPrint("分配内存AcctParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct AcctParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}
int mvitem_task2acctlist(struct AcctTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct AcctParamStruct **pptHead)
{
	int i=0;
	char sFilter[21],sTemp[256];
	struct AcctParamStruct *po=NULL;

	*pptHead=NULL;
	strcpy(sFilter,"");
	strcpy(sTemp,ptp->sInFilter);

	while(1){
		GetSepStrX(sTemp,';',i++,20,sFilter);
		if(strlen(sFilter)==0) break;

		if((po=(struct AcctParamStruct*)malloc(
			sizeof(struct AcctParamStruct)))==NULL){
			WriteAlertPrint("分配内存AcctParamStruct失败,退出!");
			return -1;
		}

		bzero((void*)po,sizeof(struct AcctParamStruct));

		strcpy(po->sSourceID,pi->sSourceID);
	
		po->iGroupID=	pi->iGroupID;
		
		strcpy(po->sOperType,	pi->sOperType);	
		strcpy(po->sDateRule,	pi->sDateRule);
		strcpy(po->sBelongCode,	pi->sBelongCode);

		strcpy(po->sModule,	pi->sModule);
	
		strcpy(po->sFilter,	sFilter);
		strcpy(po->sFileType,	ptp->sInType);
	
		GetTaskPath(ptp->sInPath,pi->sSourceID,po->sSourcePath);
		GetTaskPath(ptp->sBakPath,pi->sSourceID,po->sBackPath);

		strcpy(po->sAppID,	ptp->sAppID);
		po->iTacheID=		iTacheID;

		strcpy(po->sState,	"A");
		
		InsertListTail((LIST**)pptHead,(LIST*)po);
	}
	return 0;
}
int GetFlowAcctParamList(int iFlowID,int iGroupID,
	struct AcctParamStruct **pptHead)
{
	int iTacheID=0;
	struct AcctTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct AcctParamStruct *pTemp=NULL;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;
		
		if(SearchAcctTaskParam(pPreSrc->sSourceID,iGroupID,&pParam)
			==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 ACCT_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}

		if(mvitem_task2acctlist(pParam,iTacheID,pTaskParam,&pTemp)<0){
			WriteAlertMsg("分配内存错误");
			return -1;
		}

		if(pTemp!=NULL)
			AppendListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetAcctParamList(char sFileName[],int iGroupID,
	struct AcctParamStruct **pptHead)
{
	int iFlowID=0;
	struct AcctParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowAcctParamList(iFlowID,iGroupID,pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitAcctParam)<0,
			"获取PREP_PARAM错误");

		if (SearchAcctParam(iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitAcctList(sFileName,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}
int GetPutParamList(char sFileName[],int iGroupID,
	struct PutParamStruct **pptHead)
{
	int iFlowID=0;
	struct PutParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowPutParamList(iFlowID,iGroupID,pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitPutParam)<0,
			"获取PUT_PARAM错误");

		if (SearchPutParam(iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitPutList(sFileName,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}


int GetFlowPutParamList(int iFlowID,int iGroupID,
	struct PutParamStruct **pptHead)
{
	int iTacheID=0;
	struct PutTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct PutParamStruct *pTemp;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;
		
		if(SearchPutTaskParam(pPreSrc->sSourceID,iGroupID,&pParam)
			==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 PUT_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		
		if((pTemp=(struct PutParamStruct*)malloc(
			sizeof(struct PutParamStruct)))==NULL){
			WriteAlertPrint("分配内存PutParamStruct失败,退出!");
			return -1;
		}

		mvitem_task2put(pParam,iTacheID,pPreSrc,pTaskParam,pTemp);

		InsertListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}

int FInitPutList(char sFileName[],int iGroupID,
	struct PutParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	PutParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;
/*备份链表*/
	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2put(sTemp,&Temp);
/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;

		if((ptCur=(struct PutParamStruct*)malloc(
			sizeof(struct PutParamStruct)))==NULL){
			WriteAlertPrint("分配内存PutParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct PutParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}

void mvitem_task2put(struct PutTaskParamStruct *pi,int iTacheID,
	struct SourceDescStruct *ps,struct TaskParamStruct *ptp,
	struct PutParamStruct *po)
{
	bzero((void*)po,sizeof(struct PutParamStruct));

	strcpy(po->sSourceID,pi->sSourceID);
	
	po->iGroupID=	pi->iGroupID;
	
	strcpy(po->sOppPath,	pi->sOppPath);
	
	strcpy(po->sIp,		pi->sIp);
	strcpy(po->sUserName,	pi->sUserName);
	strcpy(po->sPasswd,	pi->sPasswd);
	strcpy(po->sFilter,	pi->sFilter);

	po->iSeqOff=	pi->iSeqOff;
	po->iSeqLen=	pi->iSeqLen;
	
	strcpy(po->sDeleteType, pi->sDeleteType);

/*如果TASK_PARAM指定输出，则从TASK_PARAM，未指定则默认为SOURCE_DESC*/
	/*if(strlen(ptp->sOutType)!=0)
		strcpy(po->sOutType,	ptp->sOutType);
	else
		strcpy(po->sOutType,	ps->sFileType);*/

	GetTaskPath(ptp->sInPath,pi->sSourceID,po->sLocalPath);
	GetTaskPath(ptp->sBakPath,pi->sSourceID,po->sLocalBkupPath);
	strcpy(po->sAppID,	ptp->sAppID);

	po->iTacheID=		iTacheID;
	strcpy(po->sState,	"A");
}

void mvitem_str2put(char sLine[],struct PutParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct PutParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sSourceID);
	GetTabStrX(sLine,2,80,p->sOppPath);	RegularDir(p->sOppPath);
	GetTabStrX(sLine,3,80,p->sLocalPath);	RegularDir(p->sLocalPath);
	GetTabStrX(sLine,4,80,p->sLocalBkupPath);	RegularDir(p->sLocalBkupPath);
	GetTabStrX(sLine,5,16,p->sIp);
	GetTabStrX(sLine,6,20,p->sUserName);
	GetTabStrX(sLine,7,20,p->sPasswd);

	/*用户无密码时转换*/
	if(strcmp(p->sPasswd,"nil")==0)
		strcpy(p->sPasswd,"");
	
	GetTabStrX(sLine,8,20,p->sFilter);
	TrimAllX(p->sFilter,'"');
	
	GetTabStrX(sLine,9,2,sTemp);
	p->iSeqOff=atoi(sTemp);

	GetTabStrX(sLine,10,2,sTemp);
	p->iSeqLen=atoi(sTemp);

	GetTabStrX(sLine,11,1,p->sDeleteType);
	
	GetTabStrX(sLine,12,5,p->sAppID);
	GetTabStr(sLine,13,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);

	strcpy(p->sState,"A");
}
void mvitem_str2Intf(char sLine[],struct IntfParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct IntfParamStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sFileType);
	GetTabStrX(sLine,2,80,p->sSourcePath);	RegularDir(p->sSourcePath);
	GetTabStrX(sLine,3,80,p->sBackPath);	
	GetTabStrX(sLine,5,80,p->sNormalPath);	RegularDir(p->sNormalPath);

	if(strcmp(p->sBackPath,"/dev/null")==0) strcpy(p->sBackPath,"");
	else RegularDir(p->sBackPath);

	GetTabStrX(sLine,6,20,p->sFilter); TrimAllX(p->sFilter,'"');
/*这里的第七个参数原来是gettablename.sh脚本，现在不用了*/
	GetTabStrX(sLine,7,5,sTemp);
	p->iDelay=atoi(sTemp);
	GetTabStrX(sLine,8,3,p->sCityCode);
	
	GetTabStrX(sLine,9,5,p->sAppID);
	GetTabStr(sLine,10,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);

	strcpy(p->sState,"A");
}

int FInitIntfList(char sFileName[],int iGroupID,
	struct IntfParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	IntfParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2Intf(sTemp,&Temp);

/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;

		if((ptCur=(struct IntfParamStruct*)malloc(
			sizeof(struct IntfParamStruct)))==NULL){
			WriteAlertPrint("分配内存IntfParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct IntfParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}

int mvitem_task2intflist(struct IntfTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct IntfParamStruct **pptHead)
{
	int i=0;
	char sFilter[21],sTemp[256];
	struct IntfParamStruct *po=NULL;

	*pptHead=NULL;
	strcpy(sFilter,"");
	strcpy(sTemp,pi->sFilter);

	while(1){
		GetSepStrX(sTemp,';',i++,20,sFilter);
		if(strlen(sFilter)==0) break;

		if((po=(struct IntfParamStruct*)malloc(
			sizeof(struct IntfParamStruct)))==NULL){
			WriteAlertPrint("分配内存IntfParamStruct失败,退出!");
			return -1;
		}

		bzero((void*)po,sizeof(struct IntfParamStruct));

		strcpy(po->sSourceID,pi->sSourceID);
	
		po->iGroupID=	pi->iGroupID;

		GetTaskPath(ptp->sInPath,pi->sSourceID,po->sSourcePath);
		GetTaskPath(ptp->sBakPath,pi->sSourceID,po->sBackPath);
		GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sNormalPath);
					
		strcpy(po->sFilter,	sFilter);
		po->iDelay=		pi->iDelay;
		strcpy(po->sCityCode,	pi->sCityCode);
		strcpy(po->sFileType,	pi->sFileType);
		
		strcpy(po->sState,	"A");

		strcpy(po->sAppID,	ptp->sAppID);
		po->iTacheID=		iTacheID;
		
		InsertListTail((LIST**)pptHead,(LIST*)po);
	}
	return 0;
}

int GetFlowIntfParamList(int iFlowID,int iGroupID,
	struct IntfParamStruct **pptHead)
{
	int iTacheID=0;
	struct IntfTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct IntfParamStruct *pTemp=NULL;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;
		
		if(SearchIntfTaskParam(pPreSrc->sSourceID,iGroupID,&pParam)
			==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 INTF_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}

		if(mvitem_task2intflist(pParam,iTacheID,pTaskParam,&pTemp)<0){
			WriteAlertMsg("分配内存错误");
			return -1;
		}

		if(pTemp!=NULL)
			AppendListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetIntfParamList(char sFileName[],int iGroupID,
	struct IntfParamStruct **pptHead)
{
	int iFlowID=0;
	struct IntfParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowIntfParamList(iFlowID,iGroupID,pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitIntfParam)<0,
			"获取PREP_PARAM错误");

		if (SearchIntfParam(iGroupID,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%d组.",iGroupID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitIntfList(sFileName,iGroupID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}

void mvitem_str2rcyl(char sLine[],struct RcylParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct RcylParamStruct));

	p->pNext=NULL;
	
	GetTabStrX(sLine,0,6,p->sSourceID);

	GetTabStr(sLine,1,sTemp);AllTrim(sTemp);
	p->iTaskSeqNbr=atoi(sTemp);

	GetTabStrX(sLine,2,30,p->sTableName);
	GetTabStrX(sLine,3,60,p->sCondition);	
	GetTabStrX(sLine,4,40,p->sExprFile);
	GetTabStrX(sLine,5,10,p->sTemplateID);
	GetTabStrX(sLine,6,80,p->sNormalPath);	RegularDir(p->sNormalPath);
	GetTabStrX(sLine,7,10,p->sSplitStr);
	GetTabStrX(sLine,8,9,p->sVisitCode);
	GetTabStrX(sLine,9,3,p->sModule);
	GetTabStrX(sLine,10,6,p->sFileType);
	
	GetTabStrX(sLine,11,10,p->sAppID);
	GetTabStr(sLine,12,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);
}

int FInitRcylList(char sFileName[],char sSourceID[],
	struct RcylParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	RcylParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2rcyl(sTemp,&Temp);

/*去掉不属于指sSourceID的记录*/
		if(strcmp(sSourceID,Temp.sSourceID)!=0) continue;

		if((ptCur=(struct RcylParamStruct*)malloc(
			sizeof(struct RcylParamStruct)))==NULL){
			WriteAlertPrint("分配内存RcylParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct RcylParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}

int mvitem_task2rcyllist(struct RcylTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct RcylParamStruct **pptHead)
{
	struct RcylParamStruct *po=NULL;

	*pptHead=NULL;

	if((po=(struct RcylParamStruct*)malloc(
		sizeof(struct RcylParamStruct)))==NULL){
		WriteAlertPrint("分配内存RcylParamStruct失败,退出!");
		return -1;
	}

	bzero((void*)po,sizeof(struct RcylParamStruct));

	strcpy(po->sSourceID,pi->sSourceID);
	
	po->iTaskSeqNbr=	pi->iTaskSeqNbr;
	
	strcpy(po->sTableName,pi->sTableName);
	strcpy(po->sCondition,pi->sCondition);
	strcpy(po->sExprFile,pi->sExprFile);
	strcpy(po->sTemplateID,pi->sTemplateID);
	
	GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sNormalPath);

	strcpy(po->sSplitStr,pi->sSplitStr);
	strcpy(po->sVisitCode,pi->sVisitCode);
	strcpy(po->sModule,pi->sModule);
	strcpy(po->sFileType,	ptp->sOutType);
	
	strcpy(po->sAppID,	ptp->sAppID);
	po->iTacheID=		iTacheID;
	
	InsertListTail((LIST**)pptHead,(LIST*)po);

	return 0;
}

int GetFlowRcylParamList(int iFlowID,char sSourceID[],int iTaskSeqNbr,
	struct RcylParamStruct **pptHead)
{
	int iTacheID=0;
	struct RcylTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct RcylParamStruct *pTemp=NULL;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;

		/*SOURCE_ID不匹配的参数不取*/
		if(strcmp(pPreSrc->sSourceID,sSourceID)!=0)continue;
		
		if(SearchRcylTaskParam(pPreSrc->sSourceID,iTaskSeqNbr,&pParam)
			==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 RECYCLE_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}

		if(mvitem_task2rcyllist(pParam,iTacheID,pTaskParam,&pTemp)<0){
			WriteAlertMsg("分配内存错误");
			return -1;
		}

		if(pTemp!=NULL)
			AppendListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetRcylParamList(char sFileName[],char sSourceID[],int iTaskSeqNbr,
	struct RcylParamStruct **pptHead)
{
	int iFlowID=0;
	struct RcylParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowRcylParamList(iFlowID,sSourceID,iTaskSeqNbr,
			pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitRcylParam)<0,
			"获取PREP_PARAM错误");

		if (SearchRcylParam(sSourceID,iTaskSeqNbr,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%s组.",sSourceID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitRcylList(sFileName,sSourceID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}

void mvitem_str2roll(char sLine[],struct RollParamStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct RollParamStruct));

	p->pNext=NULL;
		
	GetTabStrX(sLine,0,6,p->sSourceID);
	
	GetTabStr(sLine,1,sTemp);AllTrim(sTemp);
	p->iTaskSeqNbr=atoi(sTemp);

	GetTabStrX(sLine,2,30,p->sTableName);
	GetTabStrX(sLine,3,60,p->sCondition);	
	GetTabStrX(sLine,4,10,p->sTemplateID);
	
	GetTabStrX(sLine,5,40,p->sUserType);
	GetTabStrX(sLine,6,80,p->sNormalPath);	RegularDir(p->sNormalPath);
	
	GetTabStrX(sLine,7,1,p->sSplitType);
	GetTabStrX(sLine,8,9,p->sVisitCode);
	GetTabStrX(sLine,9,3,p->sModule);
	
	GetTabStrX(sLine,10,6,p->sFileType);
	
	GetTabStrX(sLine,11,10,p->sAppID);
	GetTabStr(sLine,12,sTemp);AllTrim(sTemp);
	p->iTacheID=atoi(sTemp);

}

int FInitRollList(char sFileName[],char sSourceID[],
	struct RollParamStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	RollParamStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(strchr(sTemp,'#')!=NULL) continue;
		
/*将行记录转换结构格式*/
		mvitem_str2roll(sTemp,&Temp);

/*去掉不属于指sSourceID的记录*/
		if(strcmp(sSourceID,Temp.sSourceID)!=0) continue;

		if((ptCur=(struct RollParamStruct*)malloc(
			sizeof(struct RollParamStruct)))==NULL){
			WriteAlertPrint("分配内存RollParamStruct失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct RollParamStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}

int mvitem_task2rolllist(struct RollTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct RollParamStruct **pptHead)
{
	struct RollParamStruct *po=NULL;

	*pptHead=NULL;

	if((po=(struct RollParamStruct*)malloc(
		sizeof(struct RollParamStruct)))==NULL){
		WriteAlertPrint("分配内存RollParamStruct失败,退出!");
		return -1;
	}

	strcpy(po->sSourceID,pi->sSourceID);
	
	po->iTaskSeqNbr=	pi->iTaskSeqNbr;
	
	strcpy(po->sTableName,pi->sTableName);
	strcpy(po->sCondition,pi->sCondition);
	
	strcpy(po->sUserType,pi->sUserType);
	strcpy(po->sTemplateID,pi->sTemplateID);
	
	GetTaskPath(ptp->sOutPath,pi->sSourceID,po->sNormalPath);

	strcpy(po->sSplitType,pi->sSplitType);
	strcpy(po->sVisitCode,pi->sVisitCode);
	strcpy(po->sModule,pi->sModule);
	strcpy(po->sFileType,	ptp->sOutType);
	
	strcpy(po->sAppID,	ptp->sAppID);
	po->iTacheID=		iTacheID;
	
	InsertListTail((LIST**)pptHead,(LIST*)po);

	return 0;
}

int GetFlowRollParamList(int iFlowID,char sSourceID[],int iTaskSeqNbr,
	struct RollParamStruct **pptHead)
{
	int iTacheID=0;
	struct RollTaskParamStruct *pParam=NULL;
	struct TaskParamStruct *pTaskParam=NULL;
	struct SourceDescStruct *pSourceList=NULL,*pPreSrc,*pCurSrc=NULL;
	struct RollParamStruct *pTemp=NULL;
	
	*pptHead=NULL;
	
	if(SearchSourceDesc(iFlowID,&pSourceList)==NOTFOUND) return 0;
	
	pCurSrc=pSourceList;
	
	while(pCurSrc!=NULL){
		pPreSrc=pCurSrc;
		pCurSrc=pCurSrc->pNext;

		/*SOURCE_ID不匹配的参数不取*/
		if(strcmp(pPreSrc->sSourceID,sSourceID)!=0)continue;
		
		if(SearchRollTaskParam(pPreSrc->sSourceID,iTaskSeqNbr,
			&pParam)==NOTFOUND) continue;

		if(SearchTaskParam(pParam->iParamID,&pTaskParam)==NOTFOUND){
			WriteAlertMsg(" paramid=%d, flowid=%d 在 ROLL_TASK_PARAM 但是不在 TASK_PARAM ",
				pParam->iParamID,iFlowID);
			return -1;
		}
		if((iTacheID=GetTacheID(pParam->iParamID,iFlowID))<0){
			WriteAlertMsg(" paramid=%d, flowid=%d 的FLOW_TASK,FLOW_TACHE参数异常 ",
				pParam->iParamID,iFlowID);
			return -1;
		}

		if(mvitem_task2rolllist(pParam,iTacheID,pTaskParam,&pTemp)<0){
			WriteAlertMsg("分配内存错误");
			return -1;
		}

		if(pTemp!=NULL)
			AppendListTail((LIST**)pptHead,(LIST*)pTemp);
	}
		
	return 0;
}
int GetRollParamList(char sFileName[],char sSourceID[],int iTaskSeqNbr,
	struct RollParamStruct **pptHead)
{
	int iFlowID=0;
	struct RollParamStruct *ptLkHead=NULL;

/*如果INI指定为流程参数*/
	if(FlowIniName(sFileName,&iFlowID)==true){
		if(GetFlowRollParamList(iFlowID,sSourceID,iTaskSeqNbr,
			pptHead)<0)return -1;
		return 0;
	}
/*如果INI指定为共享内存则*/
	if(ShmIniName(sFileName)==true){
		
/*获取预处理参数*/
		ERROR_EXIT(MoveShmToMem(MInitRollParam)<0,
			"获取PREP_PARAM错误");

		if (SearchRollParam(sSourceID,iTaskSeqNbr,&ptLkHead)==NOTFOUND){
			WriteAlertPrint("采集参数%s组.",sSourceID);
			return -1;
		}
		*pptHead=ptLkHead;
		return 0;
	}
/*获取文件的INI参数*/
	if(FInitRollList(sFileName,sSourceID,&ptLkHead)<0) return -1;

	*pptHead=ptLkHead;

	return 0;
}
