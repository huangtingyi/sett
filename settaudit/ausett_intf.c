#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdb.h>
#include <bintree.h>


#include "ausett_supp.h"
#include "ausett_intf.h"


struct ReportItemConfigExtStruct *g_ptRic=NULL;

int data_search_bintree_report_item_config(void *pValue,void *pData)
{
	int iRes;
	
	struct ReportItemConfigExtStruct *pSource=(struct ReportItemConfigExtStruct *)pValue;
	struct ReportItemConfigExtStruct *pTarget=(struct ReportItemConfigExtStruct *)pData;
	
	if((iRes=pSource->iReportItemID-pTarget->iReportItemID)!=0) return iRes;
	if((iRes=strcmp(pSource->sFeeType,pTarget->sFeeType))!=0) return iRes;
	if((iRes=strcmp(pSource->sTicketTypeID,pTarget->sTicketTypeID))!=0) return iRes;
	
		
	return 0;
}
void assign_insert_bintree_report_item_config(void **ppData,void *pData)
{
	*ppData=pData;
}
int append_bintree_report_item_config(void **ppData)
{
	struct ReportItemConfigExtStruct *pTemp=(struct ReportItemConfigExtStruct *)*ppData;
	
	pTemp->pNext=g_ptRic;
	g_ptRic=pTemp;
	
	return 0;
}
/*-----------------------------------------------------------------------------*/
int TruncateTableData(char sTableName[])
{
	char sBuff[1024];
	
	sprintf(sBuff,"TRUNCATE TABLE %s ",sTableName);
	if(ExecSql(sBuff)<0){
		RollbackWork();
		return -1;
	}
	CommitWork();
	
	return 0;
}

int DeleteTableDataByDate(char sTableName[],char sDate[])
{
	char sBuff[1024];
	
	sprintf(sBuff,"DELETE FROM %s WHERE data_date=to_date('%s','yyyymmdd') ",sTableName,sDate);
	if(ExecSql(sBuff)<0){
		RollbackWork();
		return -1;
	}
	CommitWork();
	
	return 0;
}

int OutputProcessInfo2LogTable(struct AuSettLogStruct *ptHead,char sTableOut[])
{
	int iInsertCnt=0;
	struct AuSettLogStruct *pTemp;
	
	struct AuSettLogStructOut TempOut;
	
	bzero(&TempOut,sizeof(struct AuSettLogStructOut));
	strcpy(TempOut.sTableName,sTableOut);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if((++iInsertCnt)%50000==0){
			if(EInsertStructToAuSettLog(NULL,true,&TempOut)<0){
				WriteAlertMsg("写表%s错误.",sTableOut);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
			WriteProcMsg("当前输出数据到表 %s 记录数 %d 条.",
				sTableOut,iInsertCnt);
		}

		if(EInsertStructToAuSettLog(pTemp,false,&TempOut)<0){
			WriteAlertMsg("写表%s错误.",sTableOut);
			WriteErrStackAlert();
			RollbackWorkRelease();
			
			return -1;
		}
		
		free(pTemp);
	}
	
	if(EInsertStructToAuSettLog(NULL,true,&TempOut)<0){
		WriteAlertMsg("写表%s错误.",sTableOut);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	WriteProcMsg("输出数据到表 %s 总记录数 %d 条.",
		sTableOut,iInsertCnt);
		
	return 0;
}

int WriteState2LogTable(struct StatCtrlStruct *pCtrl,char sDealState[])
{
	char sLogTable[32];
	static struct AuSettLogStruct aslTemp;
	
	aslTemp.pNext=NULL;
	aslTemp.pLoadNext=NULL;
	strcpy(aslTemp.sDealTable,pCtrl->sTableNameIn);
	strcpy(aslTemp.sOutTableIn,pCtrl->sTableNameOut1);
	strcpy(aslTemp.sOutTableOut,pCtrl->sTableNameOut0);
	strcpy(aslTemp.sDataDate,pCtrl->sBillingDate);
	GetHostTime(aslTemp.sDealDate);
	strcpy(aslTemp.sDealState,sDealState);
	
	strcpy(sLogTable,"AU_SETT_LOG");
	DeleteTableDataByDate(sLogTable,aslTemp.sDataDate);
	if(OutputProcessInfo2LogTable(&aslTemp,sLogTable)<0) return -1;
	
	return 0;
}

/*-----------------------------我方报表项相关函数---------------------------------*/
int GetSepStrBySepChar(char sOriStr[],char cSep,struct ConditionValStruct **ppHead)
{
	int iLen;
	char *pStart,*pFound;
	char sBuff[128];
	
	struct ConditionValStruct *pTemp;
	
	*ppHead=NULL;
	if(sOriStr==NULL || strlen(sOriStr)==0){
		return 0;
	}
	
	pStart=sOriStr;
	while((pFound=strchr(pStart,cSep))!=NULL){
		
		iLen=pFound-pStart;
		strncpy(sBuff,pStart,iLen);
		sBuff[iLen]=0;
		pStart=pFound+1;
		
		if((pTemp=(struct ConditionValStruct*)
			malloc(sizeof(struct ConditionValStruct)))==NULL){
                	
			DestroyList((LIST*)*ppHead);
			WriteAlertMsg("malloc ConditionValStruct failed");
			return -1;
		}
		pTemp->iValue=atoi(sBuff);
		
		InsertList((LIST**)ppHead,(LIST*)pTemp);
	}
	
	strcpy(sBuff,pStart);
	if((pTemp=(struct ConditionValStruct*)
		malloc(sizeof(struct ConditionValStruct)))==NULL){
                	
		DestroyList((LIST*)*ppHead);
		WriteAlertMsg("malloc ConditionValStruct failed");
		return -1;
	}
	pTemp->iValue=atoi(sBuff);
	InsertList((LIST**)ppHead,(LIST*)pTemp);
	
	return 0;
}
int AddConditionColumn(struct ReportItemConfigStruct *pi,
	struct ReportItemConfigExtStruct *po)
{
	struct ConditionColStruct *pTemp;
	
	if(pi->sColumnName[0]!=0){
		if((pTemp=(struct ConditionColStruct*)
			malloc(sizeof(struct ConditionColStruct)))==NULL){
                	
			DestroyList((LIST*)po->ptLkCondi);
			WriteAlertMsg("malloc ConditionColStruct failed");
			return -1;
		}
		strcpy(pTemp->sColumnName,pi->sColumnName);
		strcpy(pTemp->sColumnValue,pi->sColumnValue);
		pTemp->iColumnCtrl=pi->iColumnCtrl;
		
		InsertList((LIST**)&po->ptLkCondi,(LIST*)pTemp);
	}
	
	return 0;
}
int mvitem_reportitemconfig2ext(struct ReportItemConfigStruct *pi,
	struct ReportItemConfigExtStruct *po)
{
	strcpy(po->sTicketTypeID,pi->sTicketTypeID);
	po->iReportItemID=pi->iReportItemID;
	strcpy(po->sFeeType,pi->sFeeType);
	strcpy(po->sSettType,pi->sSettType);
	if(GetSepStrBySepChar(pi->sTicketTypeID,',',&po->ptLkTtid)<0) return -1;
	
	if(AddConditionColumn(pi,po)<0) return -1;
	
	return 0;
}

int LoadTableReportItemConfig(char sTableName[],char sCondi[],
	struct ReportItemConfigExtStruct **pptHead)
{
	int iCnt=0;
	
	BINTREE *ptRoot=NULL;
	struct ReportItemConfigExtStruct *pTemp,*ptFound,ricTemp;
	struct ReportItemConfigStruct Temp;
	struct ReportItemConfigStructIn TempIn;

	*pptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct ReportItemConfigStructIn));
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,sCondi);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetReportItemConfigToStruct(&Temp,&TempIn)){
		
		if(Temp.sFeeType[0]=='*') continue;
		
		ricTemp.iReportItemID=Temp.iReportItemID;
		strcpy(ricTemp.sFeeType,Temp.sFeeType);
		strcpy(ricTemp.sTicketTypeID,Temp.sTicketTypeID);
		if(SearchBin(ptRoot,&ricTemp,data_search_bintree_report_item_config,
			(void**)&ptFound)==FOUND){
			if(AddConditionColumn(&Temp,ptFound)<0) return -1;
		}
		else{
			if((pTemp=(struct ReportItemConfigExtStruct*)
				malloc(sizeof(struct ReportItemConfigExtStruct)))==NULL){
                		WriteAlertMsg("malloc ReportItemConfigExtStruct failed");
				DestroyBin(ptRoot);
				return -1;
			}
			pTemp->pNext=NULL;
			pTemp->ptLkTtid=NULL;
			pTemp->ptLkCondi=NULL;
			if(mvitem_reportitemconfig2ext(&Temp,pTemp)<0) return -1;
			
			if(InsertBin(&ptRoot,pTemp,data_search_bintree_report_item_config,
				assign_insert_bintree_report_item_config)<0){
				WriteAlertMsg("建树 ReportItemConfigExtStruct 失败");
				DestroyBin(ptRoot);
				return -1;
			}
		}
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表 %s 记录数%d",sTableName,iCnt);
	}
	WriteProcMsg("加载表 %s 完毕总记录数%d",sTableName,iCnt);

	g_ptRic=NULL;
	TravelBin(ptRoot,append_bintree_report_item_config);
	*pptHead=g_ptRic;
	
	return iCnt;
}

int CompareTicketTypeID(struct SttTicketStruct *pValue,struct ReportItemConfigExtStruct *pData)
{
	static struct ConditionValStruct *ptHead;
	
	ptHead=pData->ptLkTtid;
	if(ptHead == NULL) return FOUND;
		
	while(ptHead!=NULL){
		if(ptHead->iValue==pValue->iTicketTypeID)
			return FOUND;
		
		ptHead=ptHead->pNext;
	}
	
	return NOTFOUND;
}

int CompareCal(struct SttTicketStruct *pValue,struct ConditionColStruct *pData)
{
	static char *pch;
	
	pch=pData->sColumnValue;
	if(pch[0] == 0) return FOUND;
		
	if(pData->iColumnCtrl==1){/* IN */
		while(*pch != 0){
			if(*pch==',') continue;
			
			if(pValue->sCal[0]==*pch) return FOUND;
			
			++pch;
		}
		
	}
	else if(pData->iColumnCtrl==2){/* NOTIN*/
		while(*pch != 0){
			if(*pch==',') continue;
			
			if(pValue->sCal[0]==*pch) return NOTFOUND;
			
			++pch;
		}
		return FOUND;
	}
	
	return NOTFOUND;
}

int CompareState(struct SttTicketStruct *pValue,struct ConditionColStruct *pData)
{
	static char *pch;
	
	pch=pData->sColumnValue;
	if(pch[0] == 0) return FOUND;
	
	if(pData->iColumnCtrl==1){/* IN */	
		while(*pch != 0){
			if(*pch==',') continue;
		
			if(pValue->sState[0]==*pch) return FOUND;
		
			++pch;
		}
	}
	else if(pData->iColumnCtrl==2){/* NOTIN*/
		while(*pch != 0){
			if(*pch==',') continue;
			
			if(pValue->sState[0]==*pch) return NOTFOUND;
			
			++pch;
		}
		return FOUND;
	}
	
	return NOTFOUND;
}

int CompareCallingTypeID(struct SttTicketStruct *pValue,struct ConditionColStruct *pData)
{
	static int iTypeID;
	
	iTypeID=atoi(pData->sColumnValue);
	
	if(pData->iColumnCtrl==1){/* IN */
		if(pValue->iCallingTypeID==iTypeID)
			return FOUND;
		else	
			return NOTFOUND;
	}
	else if(pData->iColumnCtrl==2){/* NOTIN*/
		if(pValue->iCallingTypeID==iTypeID)
			return NOTFOUND;
		else
			return FOUND;
	}
}
int CompareCalledTypeID(struct SttTicketStruct *pValue,struct ConditionColStruct *pData)
{
	static int iTypeID;
	
	iTypeID=atoi(pData->sColumnValue);
	
	if(pData->iColumnCtrl==1){/* IN */
		if(pValue->iCalledTypeID==iTypeID)
			return FOUND;
		else	
			return NOTFOUND;
	}
	else if(pData->iColumnCtrl==2){/* NOTIN*/
		if(pValue->iCalledTypeID==iTypeID)
			return NOTFOUND;
		else
			return FOUND;
	}
}
int CompareUserType_stt(struct SttTicketStruct *pValue,struct ConditionColStruct *pData)
{
	if(pData->iColumnCtrl==1){/* IN */
		if(pValue->sUserType[0]==pData->sColumnValue[0]) return FOUND;
	}
	else if(pData->iColumnCtrl==2){/* NOTIN*/
		if(pValue->sUserType[0]==pData->sColumnValue[0])
			return NOTFOUND;
		else
			return FOUND;
	}
	
	return NOTFOUND;
}

int SearchReportItemConfig(struct ReportItemConfigExtStruct *ptHead,struct SttTicketStruct *pValue,
	struct ReportItemConfigExtStruct **pptCur)
{
	static struct ReportItemConfigExtStruct *pTemp;
	static struct ConditionColStruct *pCol,*pCur;
	
	*pptCur=NULL;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(CompareTicketTypeID(pValue,pTemp)==NOTFOUND) continue;
			
		pCol=pTemp->ptLkCondi;
		if(pCol==NULL){
			*pptCur=pTemp;
			return FOUND;
		}
		
		while(pCol!=NULL){
			pCur=pCol;
			pCol=pCol->pNext;
			
			if(strcmp(pCol->sColumnName,"CAL")==0){
				if(CompareCal(pValue,pCol)==NOTFOUND) goto cont;
			}
			else if(strcmp(pCol->sColumnName,"STATE")==0){
				if(CompareState(pValue,pCol)==NOTFOUND) goto cont;
			}
			else if(strcmp(pCol->sColumnName,"CALLING_TYPE_ID")==0){
				if(CompareCallingTypeID(pValue,pCol)==NOTFOUND) goto cont;
			}
			else if(strcmp(pCol->sColumnName,"CALLED_TYPE_ID")==0){
				if(CompareCalledTypeID(pValue,pCol)==NOTFOUND) goto cont;
			}
			else if(strcmp(pCol->sColumnName,"USER_TYPE")==0){
				if(CompareUserType_stt(pValue,pCol)==NOTFOUND) goto cont;
			}
		}
		*pptCur=pTemp;
		return FOUND;
cont:		continue;		
	}
	
	return NOTFOUND;
}

