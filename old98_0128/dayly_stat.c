#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <stt_ticket.h>

#include "dbsupp.h"
#include "dayly_stat_supp.h"

struct DaylyStatCtlStruct
{

	int iOppCarr;
	char sServiceType[6];
	char sOutStr[256];/*格式：OUTTYPE1|OUTTYPE2|OUTTYPEn...*/

};

struct DaylyStatCtlStruct STATCTL;

BINTREE *HSTT_pRoot=NULL;
struct DaylySttHourStatStruct *pSttHourOut=NULL;
struct DaylySttHourStatStruct *pSttHourUp=NULL;

BINTREE *DSTT_pRoot=NULL;
BINTREE *ASTT_pRoot=NULL;
struct DaylySttStatStruct *pDaylySttOut=NULL;
struct DaylySttStatStruct *pDaylySttUp=NULL;


BINTREE *SRP_pRoot=NULL;
BINTREE *SRT_pRoot=NULL;
BINTREE *TLP_pRoot=NULL;
BINTREE *TLL_pRoot=NULL;
BINTREE *ASRP_pRoot=NULL;
BINTREE *ASRT_pRoot=NULL;
BINTREE *ATLP_pRoot=NULL;
BINTREE *ATLL_pRoot=NULL;

struct SrtStatStruct *pSrtStatOut=NULL;
struct SrtStatStruct *pSrtStatUp=NULL;

BINTREE *SPP_pRoot=NULL;
BINTREE *SPT_pRoot=NULL;
struct SpcpStatStruct *pSpcpStatOut=NULL;
struct SpcpStatStruct *pSpcpStatUp=NULL;

BINTREE *GXP_pRoot=NULL;
BINTREE *GXT_pRoot=NULL;
struct Gprs1xStatStruct *pGprs1xStatOut=NULL;
struct Gprs1xStatStruct *pGprs1xStatUp=NULL;



int (*Ticket2Str)(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

int XDealRecord(char sInput[],char sBillingCycleID[]);
int XDealStatData(char sBillingCycleID[]);
void DestroyBinX();

int IsHSTT(char sOutType[]);
int HSTT_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[]);
int GetDaylySttHourStat(char sInput[],struct DaylySttHourStatStruct *p);
int link_stt_hour_outup(void **ppData);
int DaylySttHourStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[]);
void sum_stt_hour_stat(struct DaylySttHourStatStruct *pHead,
	 struct DaylySttHourStatStruct *pTemp);
int SttHourList2Table(struct DaylySttHourStatStruct *ptOut,
	struct DaylySttHourStatStruct *ptUp,char sTableName[]);

/*DAYLY_STT_STAT共用*/

int DSTT_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[]);
int GetDaylySttStat(char sInput[],struct DaylySttStatStruct *p);
int link_dayly_stt_stat_outup(void **ppData);
int DaylySttStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[]);
void sum_dayly_stt_stat(struct DaylySttStatStruct *pHead,
	 struct DaylySttStatStruct *pTemp);
int DaylySttList2Table(struct DaylySttStatStruct *ptOut,
	struct DaylySttStatStruct *ptUp,char sTableName[]);
int XDealDaylySttStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[]);
void DestroyDaylySttStat(struct DaylySttStatStruct *ptHead);

int IsDSTT(char sOutType[]);
int IsASTT(char sOutType[]);
int IsDSMS(char sOutType[]);
int IsASMS(char sOutType[]);
int IsDMMS(char sOutType[]);


/*SRT_STAT共用*/
int XSRT_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[]);
int GetSrtStat(char sInput[],struct SrtStatStruct *p);
int link_srt_stat_outup(void **ppData);
int SrtStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[]);
void sum_srt_stat(struct SrtStatStruct *pHead,
	 struct SrtStatStruct *pTemp);
int SrtStatList2Table(struct SrtStatStruct *ptOut,
	struct SrtStatStruct *ptUp,char sTableName[]);
int XDealSrtStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[]);
void DestroySrtStat(struct SrtStatStruct *ptHead);

int IsSRP(char sOutType[]);
int IsSRT(char sOutType[]);
int IsTLP(char sOutType[]);
int IsTLL(char sOutType[]);
int IsASRP(char sOutType[]);
int IsASRT(char sOutType[]);
int IsATLP(char sOutType[]);
int IsATLL(char sOutType[]);


/*SPCP_STAT共用*/
int SPCP_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[]);
int GetSpcpStat(char sInput[],struct SpcpStatStruct *p);
int link_spcp_stat_outup(void **ppData);
int SpcpStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[]);
void sum_spcp_stat(struct SpcpStatStruct *pHead,
	 struct SpcpStatStruct *pTemp);
int SpcpStatList2Table(struct SpcpStatStruct *ptOut,
	struct SpcpStatStruct *ptUp,char sTableName[]);
int XDealSpcpStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[]);
void DestroySpcpStat(struct SpcpStatStruct *ptHead);

int IsSPP(char sOutType[]);
int IsSPT(char sOutType[]);



/*GPRS_1X_STAT共用*/
int GPRS1X_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[]);
int GetGprs1xStat(char sInput[],struct Gprs1xStatStruct *p);
int link_gprs_1x_stat_outup(void **ppData);
int Gprs1xStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[]);
void sum_gprs_1x_stat(struct Gprs1xStatStruct *pHead,
	 struct Gprs1xStatStruct *pTemp);
int Gprs1xStatList2Table(struct Gprs1xStatStruct *ptOut,
	struct Gprs1xStatStruct *ptUp,char sTableName[]);
int XDealGprs1xStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[]);
void DestroyGprs1xStat(struct Gprs1xStatStruct *ptHead);

int Is1XT(char sOutType[]);
int IsA1XT(char sOutType[]);


int IsHSTT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"HSTT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"HSTT"))!=NULL){

		iFirstFlag=0;
		return true;
	}

	return false;
}

int IsDSTT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"DSTT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"DSTT"))!=NULL){

		iFirstFlag=0;
		return true;
	}

	return false;
}
int IsASTT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"ASTT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"ASTT"))!=NULL){

		iFirstFlag=0;
		return true;
	}

	return false;
}

int IsDSMS(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"DSMS")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"DSMS"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}

int IsASMS(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"ASMS")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"ASMS"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}

int IsDMMS(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"DMMS")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"DMMS"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}



int IsSRP(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"SRP")==0) return true;


	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"SRP"))!=NULL){

		iFirstFlag=0;
		return true;
	}

	return false;
}

int IsSRT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"SRT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"SRT"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}


int IsTLP(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"TLP")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"TLP"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}


int IsTLL(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"TLL")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"TLL"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}

int IsASRP(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"ASRP")==0) return true;


	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"ASRP"))!=NULL){

		iFirstFlag=0;
		return true;
	}

	return false;
}

int IsASRT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"ASRT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"ASRT"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}


int IsATLP(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"ATLP")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"ATLP"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}


int IsATLL(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"ATLL")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"ATLL"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}

int IsSPP(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"SPP")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"SPP"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}


int IsSPT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"SPT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"SPT"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}

int Is1XT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"1XT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"1XT"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}


int IsA1XT(char sOutType[])
{
	char *pc;

	static int iFirstFlag=1;

	if(strcmp(sOutType,"A1XT")==0) return true;

	if(iFirstFlag==1&&
		strcmp(sOutType,"")==0&&
		(pc=strstr(STATCTL.sOutStr,"A1XT"))!=NULL){

		iFirstFlag=0;
		return true;
	}
	return false;
}


int XDealRecord(char sInput[],char sBillingCycleID[])
{
	char sHead[40],sRecord[256],*pPre,*pCur;
	char sRecordFlag[2],sOutType[10];
 /*
TYPE格式:"TYPE1|TYPE2"
    	TYPE1表示:本记录有效性, TYPE1='X'表示本记录输出无效;
    	TYPE2表示:sOutType     输出类型
*/

	pPre=sInput;
	pCur=strchr(pPre,',');

	if(pCur==NULL) return -1;

	strncpy(sHead,pPre,pCur-pPre);
	sHead[pCur-pPre]=0;

	pPre=pCur+1;
	strcpy(sRecord,pPre);

	if(sRecord[0]==0)  return -1;

	ParseArgv(sHead,'|');

	strcpy(sRecordFlag,	ParseToken[0]);
	strcpy(sOutType,	ParseToken[1]);


	if(strcmp(sRecordFlag,"X")==0)return -1;/*本记录输出无效*/

	if(IsHSTT(sOutType)){

		if(HSTT_DealRecord(sRecord,sOutType,sBillingCycleID)<0){
			WriteAlertMsg("输出记录失败");
			return -1;
		}
	}
	else if(IsDSTT(sOutType)||
		IsDSMS(sOutType)||
		IsASMS(sOutType)||
		IsDMMS(sOutType)||
		IsASTT(sOutType)){

		if(DSTT_DealRecord(sRecord,sOutType,sBillingCycleID)<0){
			WriteAlertMsg("输出记录失败");
			return -1;
		}
	}
	else if(IsSRP(sOutType)||
		IsSRT(sOutType)||
		IsTLP(sOutType)||
		IsTLL(sOutType)||
		IsASRP(sOutType)||
		IsASRT(sOutType)||
		IsATLP(sOutType)||
		IsATLL(sOutType)){

		if(XSRT_DealRecord(sRecord,sOutType,sBillingCycleID)<0){
			WriteAlertMsg("输出记录失败");
			return -1;
		}
	}
	else if(IsSPP(sOutType)||
		IsSPT(sOutType)){

		if(SPCP_DealRecord(sRecord,sOutType,sBillingCycleID)<0){
			WriteAlertMsg("输出记录失败");
			return -1;
		}
	}
	else if(Is1XT(sOutType)||
		IsA1XT(sOutType)){

		if(GPRS1X_DealRecord(sRecord,sOutType,sBillingCycleID)<0){
			WriteAlertMsg("输出记录失败");
			return -1;
		}
	}

	return 0;
}

int XDealStatData(char sBillingCycleID[])
{
	int iCnt=0;

	char sStatName[31],sMonth[3];

 	if(IsHSTT("")){
 		strcpy(sStatName,"DAYLY_STT_HOUR_STAT");

		if((iCnt=DaylySttHourStat2Bin(HSTT_pRoot,sStatName,sBillingCycleID))<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
		WriteProcMsg("加载%s表%s帐周的数据完毕,%d条",
			sStatName,sBillingCycleID,iCnt);

	/*将有sRowID的加到UPDATE链表，将无ROWID的加到INSERT链表*/
		TravelBin(HSTT_pRoot,link_stt_hour_outup);

	/**输出数据到统计表**/
		if(SttHourList2Table(pSttHourOut,pSttHourUp,sStatName)<0){
			WriteAlertMsg("输出数据到统计表出错.\n");
			return -1;
		}
 	}
	
	strncpy(sMonth,sBillingCycleID+4,2);sMonth[2]=0;
	
	
 	if(IsDSTT("")){
 		strcpy(sStatName,"DAYLY_STT_STAT_");
 		strcat(sStatName,sMonth);
 		printf("sStatName=%s.\n",sStatName);
 		 		
		if(XDealDaylySttStat(DSTT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
 	}

 	if(IsASTT("")){
 		strcpy(sStatName,"DAYLY_ALL_STT_STAT");

		if(XDealDaylySttStat(ASTT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
 	}

 	if(IsDSMS("")){
 		strcpy(sStatName,"DAYLY_SMS_STAT_");
 		strcat(sStatName,sMonth);
		STATCTL.iOppCarr=0;
		if(XDealDaylySttStat(DSTT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
 	}

 	if(IsASMS("")){
 		strcpy(sStatName,"DAYLY_ALL_SMS_STAT");
 		STATCTL.iOppCarr=0;
		if(XDealDaylySttStat(ASTT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
 	}

 	if(IsDMMS("")){
 		strcpy(sStatName,"DAYLY_MMS_STAT");
		if(XDealDaylySttStat(DSTT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
 	}

	if(IsSRP("")){
 		strcpy(sStatName,"DAYLY_SRT_PRV_STAT_");
 		strcat(sStatName,sMonth);

		if(XDealSrtStat(SRP_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsSRT("")){
 		strcpy(sStatName,"DAYLY_SRT_VIT_STAT_");
 		strcat(sStatName,sMonth);

		if(XDealSrtStat(SRT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsTLP("")){
 		strcpy(sStatName,"DAYLY_TLL_PRV_STAT_");
 		strcat(sStatName,sMonth);

		if(XDealSrtStat(TLP_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsTLL("")){
 		strcpy(sStatName,"DAYLY_TLL_VIT_STAT_");
 		strcat(sStatName,sMonth);

		if(XDealSrtStat(TLL_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsASRP("")){
 		strcpy(sStatName,"DAYLY_ALL_SRT_PRV_STAT");
		if(XDealSrtStat(ASRP_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsASRT("")){
 		strcpy(sStatName,"DAYLY_ALL_SRT_VIT_STAT");
		if(XDealSrtStat(ASRT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsATLP("")){
 		strcpy(sStatName,"DAYLY_ALL_TLL_PRV_STAT");
		if(XDealSrtStat(ATLP_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsATLL("")){
 		strcpy(sStatName,"DAYLY_ALL_TLL_VIT_STAT");
		if(XDealSrtStat(ATLL_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsSPP("")){
 		strcpy(sStatName,"SPCP_PRV_STAT");
		if(XDealSpcpStat(SPP_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsSPT("")){
 		strcpy(sStatName,"SPCP_VIT_STAT");
		if(XDealSpcpStat(SPT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(Is1XT("")){
 		strcpy(sStatName,"DAYLY_CDMA1X_STAT_");
 		strcat(sStatName,sMonth);

		if(XDealGprs1xStat(GXP_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	if(IsA1XT("")){
 		strcpy(sStatName,"DAYLY_ALL_CDMA1X_STAT");
		if(XDealGprs1xStat(GXT_pRoot,
			sStatName,sBillingCycleID)<0)return -1;
	}

	return 0;
}

void DestroyBinX()
{
	DestroyBin(HSTT_pRoot);
	DestroyBin(DSTT_pRoot);
	DestroyBin(ASTT_pRoot);
	DestroyBin(SRP_pRoot);
	DestroyBin(SRT_pRoot);
	DestroyBin(TLP_pRoot);
	DestroyBin(TLL_pRoot);
	DestroyBin(SPP_pRoot);
	DestroyBin(SPT_pRoot);
	DestroyBin(GXP_pRoot);
	DestroyBin(GXT_pRoot);
	
}


/*HSTT处理*/

int HSTT_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[])
{

	char *pc;
	struct 	DaylySttHourStatStruct	Temp;


	if((pc=strstr(STATCTL.sOutStr,sOutType))==NULL){
		strcat(STATCTL.sOutStr,sOutType);
		strcat(STATCTL.sOutStr,"|");
	}


	bzero((void*)&Temp,sizeof(struct DaylySttHourStatStruct));
	strncpy(Temp.sBillingCycleID,sBillingCycleID,6);
	Temp.sBillingCycleID[6]=0;

	if(GetDaylySttHourStat(sInput,&Temp)!=0)return -1;

	if(InsertBin(&HSTT_pRoot,(void *)&Temp,
		data_search_bintree_stt_hour_e,
		assign_insert_bintree_stt_hour_e)<0){
		WriteAlertMsg("生成BINTREE失败DaylySttHourStatStruct");
		return -1;
	}

	return 0;
}

int data_search_bintree_stt_hour_e(void *pValue,void*pData)
{
	struct DaylySttHourStatStruct *pSource=(struct DaylySttHourStatStruct *)pValue;
	struct DaylySttHourStatStruct *pTarget=(struct DaylySttHourStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
	if((res=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return res;
	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	if((res=strcmp(pSource->sTrunkIn,pTarget->sTrunkIn))!=0) return res;

	if((res=pSource->iTrunkInTypeID-pTarget->iTrunkInTypeID)!=0) return res;
	if((res=pSource->iTrunkInCarrID-pTarget->iTrunkInCarrID)!=0) return res;

	if((res=strcmp(pSource->sTrunkOut,pTarget->sTrunkOut))!=0) return res;

	if((res=pSource->iTrunkOutTypeID-pTarget->iTrunkOutTypeID)!=0) return res;
	if((res=pSource->iTrunkOutCarrID-pTarget->iTrunkOutCarrID)!=0) return res;

	if((res=strcmp(pSource->sStartHour,pTarget->sStartHour))!=0) return res;
	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}
void assign_insert_bintree_stt_hour_e(void **ppData,void *pData)
{
	struct DaylySttHourStatStruct *pHead=(struct DaylySttHourStatStruct *)(*ppData);
	struct DaylySttHourStatStruct *pValue=(struct DaylySttHourStatStruct *)pData;

	if(pHead==NULL){
		pHead=malloc(sizeof(struct DaylySttHourStatStruct));
		ERROR_EXIT(pHead==NULL,"分配DaylySttHourStat结构错误");

		memcpy((void*)pHead,pData,sizeof(struct DaylySttHourStatStruct));
		pHead->pNext=NULL;
		*ppData=(void*)pHead;
	}
	else{

		pHead->iTotalSec+=	pValue->iTotalSec;
		pHead->iIncome+=	pValue->iIncome;
		pHead->iOutcome+=	pValue->iOutcome;
		pHead->iTotalMin+=	pValue->iTotalMin;
	}
}


int GetDaylySttHourStat(char sInput[],struct DaylySttHourStatStruct *p)
{

	ParseArgv(sInput,'|');

	strcpy(p->sCallType		,ParseToken[0]);
	strcpy(p->sVisitAreaCode	,ParseToken[1]);
	strcpy(p->sMsc			,ParseToken[2]);
	strcpy(p->sTrunkIn              ,ParseToken[3]);

	p->iTrunkInTypeID	 =atoi(ParseToken[4]);
	p->iTrunkInCarrID         =atoi(ParseToken[5]);

	strcpy(p->sTrunkOut	        ,ParseToken[6]);

	p->iTrunkOutTypeID	 =atoi(ParseToken[7]);
	p->iTrunkOutCarrID       =atoi(ParseToken[8]);

	strcpy(p->sStartHour	        ,ParseToken[9]);

	p->iTotalSec		=atoi(ParseToken[10]);
	p->iIncome		=atoi(ParseToken[11]);
	p->iOutcome		=atoi(ParseToken[12]);
	p->iTotalMin	        =atoi(ParseToken[13]);

	strcpy(p->sSettItemDate	      ,ParseToken[14]);



	return 0;
}


int link_stt_hour_outup(void **ppData)
{
	struct DaylySttHourStatStruct *pTemp=(struct DaylySttHourStatStruct *)(*ppData);

	if(pTemp->sRowID[0]==0)
		InsertList((LIST**)&pSttHourOut,(LIST*)pTemp);
	else	InsertList((LIST**)&pSttHourUp,(LIST*)pTemp);

	return 0;
}
/*从数据库中取数据，并加到汇总纪录中*/
int DaylySttHourStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct DaylySttHourStatStruct Temp;
        static struct DaylySttHourStatStructIn TempIn;

        static struct DaylySttHourStatStruct *pHead=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition," WHERE BILLING_CYCLE_ID ='%s' ",sCycleID);

        /*取出表中记录加载二叉树*/
        while(EGetDaylySttHourStatToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_stt_hour_e,
			(void **)&pHead)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
			if(pHead->sRowID[0]!=0) continue;

			sum_stt_hour_stat(pHead,&Temp);
		}
		iCnt++;
        }
	return iCnt;
}
void sum_stt_hour_stat(struct DaylySttHourStatStruct *pHead,
	 struct DaylySttHourStatStruct *pTemp)
{

	pHead->iTotalSec+=	pTemp->iTotalSec;
	pHead->iIncome+=	pTemp->iIncome;
	pHead->iOutcome+=	pTemp->iOutcome;
	pHead->iTotalMin+=	pTemp->iTotalMin;

	strcpy(pHead->sRowID,	pTemp->sRowID);
}

int SttHourList2Table(struct DaylySttHourStatStruct *ptOut,
	struct DaylySttHourStatStruct *ptUp,char sTableName[])
{
	struct DaylySttHourStatStructOut TempOut;
	struct DaylySttHourStatStructUp TempUp;
	struct	DaylySttHourStatStruct *ptCur,*ptPre;
	int	iCnt=0,iUpdateCnt=0;

/**输出数据到统计表**/
        bzero((void*)&TempOut,sizeof(struct DaylySttHourStatStructOut));
        bzero((void*)&TempUp,sizeof(struct DaylySttHourStatStructUp));

        strcpy(TempOut.sTableName,sTableName);
        strcpy(TempUp.sTableName,sTableName);

  	ptCur=ptOut;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToDaylySttHourStat(ptPre,false,&TempOut)<0){
			printf("输出数据错误DAYLY_STT_HOUR_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iCnt)%10000==0)
			WriteProcMsg("对表%s输出纪录数%d条",sTableName,iCnt);

	}
	if(EInsertStructToDaylySttHourStat(NULL,true,&TempOut)<0){
		printf("输出数据错误DAYLY_STT_HOUR_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%输出完毕,共计记录数%d条",iCnt);

/**更新数据到日帐表**/
	ptCur=ptUp;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToDaylySttHourStat(ptPre,false,&TempUp)<0){
			printf("更新数据错误DAYLY_STT_HOUR_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iUpdateCnt)%10000==0)
			WriteProcMsg("对表%s更新纪录数%d条",sTableName,iUpdateCnt);
	}
	if(EUpdateStructToDaylySttHourStat(NULL,true,&TempUp)<0){
		printf("更新数据错误DAYLY_STT_HOUR_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%s更新完毕,共计记录数%d条",sTableName,iUpdateCnt);

	WriteProcPrint("汇总数据到表%s正确,输出记录数%d,更新记录数%d",
		sTableName,iCnt,iUpdateCnt);
	return 0;

}


/*DSTT处理*/
int DSTT_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[])
{

	char *pc;
	struct 	DaylySttStatStruct	Temp;


	if((pc=strstr(STATCTL.sOutStr,sOutType))==NULL){
		strcat(STATCTL.sOutStr,sOutType);
		strcat(STATCTL.sOutStr,"|");
	}


	bzero((void*)&Temp,sizeof(struct DaylySttStatStruct));
	strncpy(Temp.sBillingCycleID,sBillingCycleID,6);
	Temp.sBillingCycleID[6]=0;

	if(GetDaylySttStat(sInput,&Temp)!=0)return -1;


	if(IsDSTT(sOutType)||
		IsDSMS(sOutType)||
		IsDMMS(sOutType)){
		if(InsertBin(&DSTT_pRoot,(void *)&Temp,
			data_search_bintree_dayly_stt_stat_e,
			assign_insert_bintree_dayly_stt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败DaylySttStatStruct");
			return -1;
		}
	}
	else if(IsASTT(sOutType)||
		IsASMS(sOutType)){
		if(InsertBin(&ASTT_pRoot,(void *)&Temp,
			data_search_bintree_dayly_stt_stat_e,
			assign_insert_bintree_dayly_stt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败DaylySttStatStruct");
			return -1;
		}
	}

	return 0;
}

int data_search_bintree_dayly_stt_stat_e(void *pValue,void*pData)
{
	struct DaylySttStatStruct *pSource=(struct DaylySttStatStruct *)pValue;
	struct DaylySttStatStruct *pTarget=(struct DaylySttStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
	if((res=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return res;
	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
	if((res=strcmp(pSource->sHomeCapitalCode,pTarget->sHomeCapitalCode))!=0) return res;
	if((res=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return res;
	if((res=strcmp(pSource->sCalledCapitalCode,pTarget->sCalledCapitalCode))!=0) return res;	

	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
	if((res=pSource->iOppCarrID-pTarget->iOppCarrID)!=0) return res;

	if((res=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnUserType,pTarget->sMsisdnUserType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnNbrType,pTarget->sMsisdnNbrType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnHead,pTarget->sMsisdnHead))!=0) return res;

	if((res=pSource->iMsisdnAreaID-pTarget->iMsisdnAreaID)!=0) return res;

	if((res=strcmp(pSource->sMsisdnBillingTypeID,pTarget->sMsisdnBillingTypeID))!=0) return res;

	if((res=pSource->iMsisdnCarrierID-pTarget->iMsisdnCarrierID)!=0) return res;

	if((res=strcmp(pSource->sOppUserType,pTarget->sOppUserType))!=0) return res;
	if((res=strcmp(pSource->sOppNbrType,pTarget->sOppNbrType))!=0) return res;
	if((res=strcmp(pSource->sOppHead,pTarget->sOppHead))!=0) return res;

	if((res=pSource->iOppAreaID-pTarget->iOppAreaID)!=0) return res;
	if((res=pSource->iOppCarrierID-pTarget->iOppCarrierID)!=0) return res;

	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}
void assign_insert_bintree_dayly_stt_stat_e(void **ppData,void *pData)
{
	struct DaylySttStatStruct *pHead=(struct DaylySttStatStruct *)(*ppData);
	struct DaylySttStatStruct *pValue=(struct DaylySttStatStruct *)pData;

	if(pHead==NULL){
		pHead=malloc(sizeof(struct DaylySttStatStruct));
		ERROR_EXIT(pHead==NULL,"分配DaylySttStat结构错误");

		memcpy((void*)pHead,pData,sizeof(struct DaylySttStatStruct));
		pHead->pNext=NULL;
		*ppData=(void*)pHead;
	}
	else{
		pHead->iIncome+=	pValue->iIncome;
		pHead->iOutcome+=	pValue->iOutcome;
		pHead->iTotalMin+=	pValue->iTotalMin;
	}
}

int GetDaylySttStat(char sInput[],struct DaylySttStatStruct *p)
{

	ParseArgv(sInput,'|');

	strcpy(p->sCallType		,ParseToken[0]);
	strcpy(p->sVisitAreaCode	,ParseToken[1]);
	strcpy(p->sHomeAreaCode		,ParseToken[2]);
	strcpy(p->sHomeCapitalCode	,ParseToken[3]);	
	strcpy(p->sCalledCode           ,ParseToken[4]);
	strcpy(p->sCalledCapitalCode	,ParseToken[5]);	

	p->iTicketTypeID		=atoi(ParseToken[6]);
	p->iOppCarrID 		        =atoi(ParseToken[7]);

	strcpy(p->sNetType	        ,ParseToken[8]);
	strcpy(p->sMsisdnUserType	,ParseToken[9]);
	strcpy(p->sMsisdnNbrType	,ParseToken[10]);
	strcpy(p->sMsisdnHead	        ,ParseToken[11]);

	p->iMsisdnAreaID	 =atoi(ParseToken[12]);

	strcpy(p->sMsisdnBillingTypeID	,ParseToken[13]);

	p->iMsisdnCarrierID       =atoi(ParseToken[14]);

	strcpy(p->sOppUserType	        ,ParseToken[15]);
	strcpy(p->sOppNbrType	        ,ParseToken[16]);
	strcpy(p->sOppHead	        ,ParseToken[17]);

	p->iOppAreaID	 	=atoi(ParseToken[18]);
	p->iOppCarrierID	=atoi(ParseToken[19]);
	p->iIncome		=atoi(ParseToken[20]);
	p->iOutcome		=atoi(ParseToken[21]);
	p->iTotalMin	        =atoi(ParseToken[22]);

	strcpy(p->sSettItemDate	      ,ParseToken[23]);

	return 0;
}



int link_dayly_stt_stat_outup(void **ppData)
{
	struct DaylySttStatStruct *pTemp=(struct DaylySttStatStruct *)(*ppData);

	if(pTemp->sRowID[0]==0)
		InsertList((LIST**)&pDaylySttOut,(LIST*)pTemp);
	else	InsertList((LIST**)&pDaylySttUp,(LIST*)pTemp);

	return 0;
}
/*从数据库中取数据，并加到汇总纪录中*/
int DaylySttStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct DaylySttStatStruct Temp;
        static struct DaylySttStatStructIn TempIn;

        static struct DaylySttStatStruct *pHead=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,sTableName);
	if(STATCTL.iOppCarr==0)
		sprintf(TempIn.sCondition,
			" WHERE BILLING_CYCLE_ID ='%s' ",sCycleID);
	else
		sprintf(TempIn.sCondition,
			" WHERE BILLING_CYCLE_ID ='%s' AND OPP_CARR_ID=%d ",
				sCycleID,STATCTL.iOppCarr);
	

        /*取出表中记录加载二叉树*/
        while(EGetDaylySttStatToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_dayly_stt_stat_e,
			(void **)&pHead)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
			if(pHead->sRowID[0]!=0) continue;

			sum_dayly_stt_stat(pHead,&Temp);
		}
		iCnt++;
        }
	return iCnt;
}
void sum_dayly_stt_stat(struct DaylySttStatStruct *pHead,
	 struct DaylySttStatStruct *pTemp)
{

	pHead->iIncome+=	pTemp->iIncome;
	pHead->iOutcome+=	pTemp->iOutcome;
	pHead->iTotalMin+=	pTemp->iTotalMin;

	strcpy(pHead->sRowID,	pTemp->sRowID);
}

int DaylySttList2Table(struct DaylySttStatStruct *ptOut,
	struct DaylySttStatStruct *ptUp,char sTableName[])
{
	struct DaylySttStatStructOut TempOut;
	struct DaylySttStatStructUp TempUp;
	struct	DaylySttStatStruct *ptCur,*ptPre;
	int	iCnt=0,iUpdateCnt=0;

/**输出数据到统计表**/
        bzero((void*)&TempOut,sizeof(struct DaylySttStatStructOut));
        bzero((void*)&TempUp,sizeof(struct DaylySttStatStructUp));

        strcpy(TempOut.sTableName,sTableName);
        strcpy(TempUp.sTableName,sTableName);

  	ptCur=ptOut;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToDaylySttStat(ptPre,false,&TempOut)<0){
			printf("输出数据错误DAYLY_STT_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iCnt)%10000==0)
			WriteProcMsg("对表%s输出纪录数%d条",sTableName,iCnt);

	}
	if(EInsertStructToDaylySttStat(NULL,true,&TempOut)<0){
		printf("输出数据错误DAYLY_STT_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%输出完毕,共计记录数%d条",iCnt);

/**更新数据到日帐表**/
	ptCur=ptUp;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToDaylySttStat(ptPre,false,&TempUp)<0){
			printf("更新数据错误DAYLY_STT_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iUpdateCnt)%10000==0)
			WriteProcMsg("对表%s更新纪录数%d条",sTableName,iUpdateCnt);
	}
	if(EUpdateStructToDaylySttStat(NULL,true,&TempUp)<0){
		printf("更新数据错误DAYLY_STT_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%s更新完毕,共计记录数%d条",sTableName,iUpdateCnt);

	WriteProcPrint("汇总数据到表%s正确,输出记录数%d,更新记录数%d",
		sTableName,iCnt,iUpdateCnt);
	return 0;

}

/**对表DAYLY_STT_STAT的链表释放函数**/
void DestroyDaylySttStat(struct DaylySttStatStruct *ptHead)
{
	struct DaylySttStatStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

int XDealDaylySttStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[])
{
	int iCnt=0;

	if((iCnt=DaylySttStat2Bin(pRoot,sStatName,sBillingCycleID))<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}
	WriteProcMsg("加载%s表%s帐周的数据完毕,%d条",
		sStatName,sBillingCycleID,iCnt);

/*将有sRowID的加到UPDATE链表，将无ROWID的加到INSERT链表*/
	DestroyDaylySttStat(pDaylySttOut);
	DestroyDaylySttStat(pDaylySttUp);
	pDaylySttOut=NULL;
	pDaylySttUp=NULL;

	TravelBin(pRoot,link_dayly_stt_stat_outup);

/**输出数据到统计表**/
	
	if(DaylySttList2Table(pDaylySttOut,pDaylySttUp,sStatName)<0){
		WriteAlertMsg("输出数据到统计表出错.\n");
		return -1;
	}
	
}


/*SRT处理*/
int XSRT_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[])
{

	char *pc;
	struct 	SrtStatStruct	Temp;


	if((pc=strstr(STATCTL.sOutStr,sOutType))==NULL){
		strcat(STATCTL.sOutStr,sOutType);
		strcat(STATCTL.sOutStr,"|");
	}


	bzero((void*)&Temp,sizeof(struct SrtStatStruct));
	strncpy(Temp.sBillingCycleID,sBillingCycleID,6);
	Temp.sBillingCycleID[6]=0;

	if(GetSrtStat(sInput,&Temp)!=0)return -1;


	if(IsSRP(sOutType)){
		if(InsertBin(&SRP_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	else if(IsSRT(sOutType)){
		if(InsertBin(&SRT_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	else if(IsTLP(sOutType)){
		if(InsertBin(&TLP_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	else if(IsTLL(sOutType)){
		if(InsertBin(&TLL_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	else if(IsASRP(sOutType)){
		if(InsertBin(&ASRP_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	else if(IsASRT(sOutType)){
		if(InsertBin(&ASRT_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	else if(IsATLP(sOutType)){
		if(InsertBin(&ATLP_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	else if(IsATLL(sOutType)){
		if(InsertBin(&ATLL_pRoot,(void *)&Temp,
			data_search_bintree_srt_stat_e,
			assign_insert_bintree_srt_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SrtStatStruct");
			return -1;
		}
	}
	return 0;
}

int data_search_bintree_srt_stat_e(void *pValue,void*pData)
{
	struct SrtStatStruct *pSource=(struct SrtStatStruct *)pValue;
	struct SrtStatStruct *pTarget=(struct SrtStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	if((res=strcmp(pSource->sOppAreaCode,pTarget->sOppAreaCode))!=0) return res;
	if((res=strcmp(pSource->sOppCapitalCode,pTarget->sOppCapitalCode))!=0) return res;	
	if((res=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return res;
	if((res=strcmp(pSource->sCalledCapitalCode,pTarget->sCalledCapitalCode))!=0) return res;	

	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
	if((res=pSource->iOppCarrID-pTarget->iOppCarrID)!=0) return res;

	if((res=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnUserType,pTarget->sMsisdnUserType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnNbrType,pTarget->sMsisdnNbrType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnHead,pTarget->sMsisdnHead))!=0) return res;

	if((res=pSource->iMsisdnAreaID-pTarget->iMsisdnAreaID)!=0) return res;

	if((res=strcmp(pSource->sMsisdnBillingTypeID,pTarget->sMsisdnBillingTypeID))!=0) return res;
	if((res=strcmp(pSource->sOppUserType,pTarget->sOppUserType))!=0) return res;
	if((res=strcmp(pSource->sOppNbrType,pTarget->sOppNbrType))!=0) return res;		
	if((res=strcmp(pSource->sOppHead,pTarget->sOppHead))!=0) return res;

	if((res=pSource->iOppAreaID-pTarget->iOppAreaID)!=0) return res;

	if((res=strcmp(pSource->sOppBillingTypeID,pTarget->sOppBillingTypeID))!=0) return res;

	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}
void assign_insert_bintree_srt_stat_e(void **ppData,void *pData)
{
	struct SrtStatStruct *pHead=(struct SrtStatStruct *)(*ppData);
	struct SrtStatStruct *pValue=(struct SrtStatStruct *)pData;

	if(pHead==NULL){
		pHead=malloc(sizeof(struct SrtStatStruct));
		ERROR_EXIT(pHead==NULL,"分配SrtStatStruct结构错误");

		memcpy((void*)pHead,pData,sizeof(struct SrtStatStruct));
		pHead->pNext=NULL;
		*ppData=(void*)pHead;
	}
	else{
		pHead->iRoamFee+=	pValue->iRoamFee;
		pHead->iTollFee+=	pValue->iTollFee;
		pHead->iIncome+=	pValue->iIncome;
		pHead->iOutcome+=	pValue->iOutcome;
		pHead->iTotalMin+=	pValue->iTotalMin;
	}
}

int GetSrtStat(char sInput[],struct SrtStatStruct *p)
{

	ParseArgv(sInput,'|');

	strcpy(p->sCallType		,ParseToken[0]);
	strcpy(p->sAreaCode		,ParseToken[1]);
	strcpy(p->sOppAreaCode		,ParseToken[2]);
	strcpy(p->sOppCapitalCode	,ParseToken[3]);
	strcpy(p->sCalledCode           ,ParseToken[4]);
	strcpy(p->sCalledCapitalCode	,ParseToken[5]);

	p->iTicketTypeID		=atoi(ParseToken[6]);
	p->iOppCarrID 		        =atoi(ParseToken[7]);

	strcpy(p->sNetType	        ,ParseToken[8]);
	strcpy(p->sMsisdnUserType	,ParseToken[9]);
	strcpy(p->sMsisdnNbrType	,ParseToken[10]);
	strcpy(p->sMsisdnHead		,ParseToken[11]);
	
	p->iMsisdnAreaID	 =atoi(ParseToken[12]);
	
	strcpy(p->sMsisdnBillingTypeID	,ParseToken[13]);

	strcpy(p->sOppUserType	        ,ParseToken[14]);
	strcpy(p->sOppNbrType	        ,ParseToken[15]);
	strcpy(p->sOppHead	        ,ParseToken[16]);

	p->iOppAreaID	 	=atoi(ParseToken[17]);

	strcpy(p->sOppBillingTypeID	,ParseToken[18]);

	p->iRoamFee		=atoi(ParseToken[19]);
	p->iTollFee		=atoi(ParseToken[20]);
	p->iIncome		=atoi(ParseToken[21]);
	p->iOutcome		=atoi(ParseToken[22]);
	p->iTotalMin	        =atoi(ParseToken[23]);

	strcpy(p->sSettItemDate	      ,ParseToken[24]);

	return 0;
}



int link_srt_stat_outup(void **ppData)
{
	struct SrtStatStruct *pTemp=(struct SrtStatStruct *)(*ppData);

	if(pTemp->sRowID[0]==0)
		InsertList((LIST**)&pSrtStatOut,(LIST*)pTemp);
	else	InsertList((LIST**)&pSrtStatUp,(LIST*)pTemp);

	return 0;
}
/*从数据库中取数据，并加到汇总纪录中*/
int SrtStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct SrtStatStruct Temp;
        static struct SrtStatStructIn TempIn;

        static struct SrtStatStruct *pHead=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,
		" WHERE BILLING_CYCLE_ID ='%s' ",sCycleID);

        /*取出表中记录加载二叉树*/
        while(EGetSrtStatToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_srt_stat_e,
			(void **)&pHead)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
			if(pHead->sRowID[0]!=0) continue;

			sum_srt_stat(pHead,&Temp);
		}
		iCnt++;
        }
	return iCnt;
}
void sum_srt_stat(struct SrtStatStruct *pHead,
	 struct SrtStatStruct *pTemp)
{

	pHead->iRoamFee+=	pTemp->iRoamFee;
	pHead->iTollFee+=	pTemp->iTollFee;
	pHead->iIncome+=	pTemp->iIncome;
	pHead->iOutcome+=	pTemp->iOutcome;
	pHead->iTotalMin+=	pTemp->iTotalMin;

	strcpy(pHead->sRowID,	pTemp->sRowID);
}

int SrtStatList2Table(struct SrtStatStruct *ptOut,
	struct SrtStatStruct *ptUp,char sTableName[])
{
	struct SrtStatStructOut TempOut;
	struct SrtStatStructUp TempUp;
	struct	SrtStatStruct *ptCur,*ptPre;
	int	iCnt=0,iUpdateCnt=0;

/**输出数据到统计表**/
        bzero((void*)&TempOut,sizeof(struct SrtStatStructOut));
        bzero((void*)&TempUp,sizeof(struct SrtStatStructUp));

        strcpy(TempOut.sTableName,sTableName);
        strcpy(TempUp.sTableName,sTableName);

  	ptCur=ptOut;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToSrtStat(ptPre,false,&TempOut)<0){
			printf("输出数据错误SRT_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iCnt)%10000==0)
			WriteProcMsg("对表%s输出纪录数%d条",sTableName,iCnt);

	}
	if(EInsertStructToSrtStat(NULL,true,&TempOut)<0){
		printf("输出数据错误SRT_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%输出完毕,共计记录数%d条",iCnt);

/**更新数据到日帐表**/
	ptCur=ptUp;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToSrtStat(ptPre,false,&TempUp)<0){
			printf("更新数据错误SRT_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iUpdateCnt)%10000==0)
			WriteProcMsg("对表%s更新纪录数%d条",sTableName,iUpdateCnt);
	}
	if(EUpdateStructToSrtStat(NULL,true,&TempUp)<0){
		printf("更新数据错误SRT_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%s更新完毕,共计记录数%d条",sTableName,iUpdateCnt);

	WriteProcPrint("汇总数据到表%s正确,输出记录数%d,更新记录数%d",
		sTableName,iCnt,iUpdateCnt);
	return 0;

}


/**对表SRT_STAT的链表释放函数**/
void DestroySrtStat(struct SrtStatStruct *ptHead)
{
	struct SrtStatStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int XDealSrtStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[])
{
	int iCnt=0;

	if((iCnt=SrtStat2Bin(pRoot,sStatName,sBillingCycleID))<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}
	WriteProcMsg("加载%s表%s帐周的数据完毕,%d条",
		sStatName,sBillingCycleID,iCnt);

/*将有sRowID的加到UPDATE链表，将无ROWID的加到INSERT链表*/
	DestroySrtStat(pSrtStatOut);
	DestroySrtStat(pSrtStatUp);
	pSrtStatOut=NULL;
	pSrtStatUp=NULL;

	TravelBin(pRoot,link_srt_stat_outup);

/**输出数据到统计表**/
		
	if(SrtStatList2Table(pSrtStatOut,pSrtStatUp,sStatName)<0){
		WriteAlertMsg("输出数据到统计表出错.\n");
		return -1;
	}
}



/*SPCP处理*/
int SPCP_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[])
{
	char *pc;
	struct 	SpcpStatStruct	Temp;


	if((pc=strstr(STATCTL.sOutStr,sOutType))==NULL){
		strcat(STATCTL.sOutStr,sOutType);
		strcat(STATCTL.sOutStr,"|");
	}

	bzero((void*)&Temp,sizeof(struct SpcpStatStruct));
	strncpy(Temp.sBillingCycleID,sBillingCycleID,6);
	Temp.sBillingCycleID[6]=0;

	if(GetSpcpStat(sInput,&Temp)!=0)return -1;


	if(IsSPP(sOutType)){
		if(InsertBin(&SPP_pRoot,(void *)&Temp,
			data_search_bintree_spcp_stat_e,
			assign_insert_bintree_spcp_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SpcpStatStruct");
			return -1;
		}	
	}
	else if(IsSPT(sOutType)){
		if(InsertBin(&SPT_pRoot,(void *)&Temp,
			data_search_bintree_spcp_stat_e,
			assign_insert_bintree_spcp_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败SpcpStatStruct");
			return -1;
		}	
	}

	return 0;
}

int data_search_bintree_spcp_stat_e(void *pValue,void*pData)
{
	struct SpcpStatStruct *pSource=(struct SpcpStatStruct *)pValue;
	struct SpcpStatStruct *pTarget=(struct SpcpStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpServiceCode,pTarget->sSpServiceCode))!=0) return res;
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;	

	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;

	if((res=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnHead,pTarget->sMsisdnHead))!=0) return res;
	if((res=strcmp(pSource->sMsisdnBillingTypeID,pTarget->sMsisdnBillingTypeID))!=0) return res;

	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}
void assign_insert_bintree_spcp_stat_e(void **ppData,void *pData)
{
	struct SpcpStatStruct *pHead=(struct SpcpStatStruct *)(*ppData);
	struct SpcpStatStruct *pValue=(struct SpcpStatStruct *)pData;

	if(pHead==NULL){
		pHead=malloc(sizeof(struct SpcpStatStruct));
		ERROR_EXIT(pHead==NULL,"分配SpcpStatStruct结构错误");

		memcpy((void*)pHead,pData,sizeof(struct SpcpStatStruct));
		pHead->pNext=NULL;
		*ppData=(void*)pHead;
	}
	else{
		pHead->iRentFee+=	pValue->iRentFee;
		pHead->iInfoFee+=	pValue->iInfoFee;
		pHead->iOutcome+=	pValue->iOutcome;
	}
}

int GetSpcpStat(char sInput[],struct SpcpStatStruct *p)
{

	ParseArgv(sInput,'|');

	strcpy(p->sAreaCode		,ParseToken[0]);
	strcpy(p->sSpCode		,ParseToken[1]);
	strcpy(p->sSpServiceCode	,ParseToken[2]);
	strcpy(p->sSpAccNbr           	,ParseToken[3]);


	p->iTicketTypeID		=atoi(ParseToken[4]);

	strcpy(p->sNetType	        ,ParseToken[5]);
	strcpy(p->sMsisdnHead		,ParseToken[6]);
	strcpy(p->sMsisdnBillingTypeID	,ParseToken[7]);

	p->iRentFee		=atoi(ParseToken[8]);
	p->iInfoFee		=atoi(ParseToken[9]);
	p->iOutcome		=atoi(ParseToken[10]);

	return 0;
}



int link_spcp_stat_outup(void **ppData)
{
	struct SpcpStatStruct *pTemp=(struct SpcpStatStruct *)(*ppData);

	if(pTemp->sRowID[0]==0)
		InsertList((LIST**)&pSpcpStatOut,(LIST*)pTemp);
	else	InsertList((LIST**)&pSpcpStatUp,(LIST*)pTemp);

	return 0;
}
/*从数据库中取数据，并加到汇总纪录中*/
int SpcpStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct SpcpStatStruct Temp;
        static struct SpcpStatStructIn TempIn;

        static struct SpcpStatStruct *pHead=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,
		" WHERE BILLING_CYCLE_ID ='%s' ",sCycleID);

        /*取出表中记录加载二叉树*/
        while(EGetSpcpStatToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_spcp_stat_e,
			(void **)&pHead)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
			if(pHead->sRowID[0]!=0) continue;

			sum_spcp_stat(pHead,&Temp);
		}
		iCnt++;
        }
	return iCnt;
}
void sum_spcp_stat(struct SpcpStatStruct *pHead,
	 struct SpcpStatStruct *pTemp)
{

	pHead->iRentFee+=	pTemp->iRentFee;
	pHead->iInfoFee+=	pTemp->iInfoFee;
	pHead->iOutcome+=	pTemp->iOutcome;

	strcpy(pHead->sRowID,	pTemp->sRowID);
}

int SpcpStatList2Table(struct SpcpStatStruct *ptOut,
	struct SpcpStatStruct *ptUp,char sTableName[])
{
	struct SpcpStatStructOut TempOut;
	struct SpcpStatStructUp TempUp;
	struct	SpcpStatStruct *ptCur,*ptPre;
	int	iCnt=0,iUpdateCnt=0;

/**输出数据到统计表**/
        bzero((void*)&TempOut,sizeof(struct SpcpStatStructOut));
        bzero((void*)&TempUp,sizeof(struct SpcpStatStructUp));

        strcpy(TempOut.sTableName,sTableName);
        strcpy(TempUp.sTableName,sTableName);

  	ptCur=ptOut;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToSpcpStat(ptPre,false,&TempOut)<0){
			printf("输出数据错误SPCP_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iCnt)%10000==0)
			WriteProcMsg("对表%s输出纪录数%d条",sTableName,iCnt);

	}
	if(EInsertStructToSpcpStat(NULL,true,&TempOut)<0){
		printf("输出数据错误SPCP_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%输出完毕,共计记录数%d条",iCnt);

/**更新数据到日帐表**/
	ptCur=ptUp;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToSpcpStat(ptPre,false,&TempUp)<0){
			printf("更新数据错误SPCP_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iUpdateCnt)%10000==0)
			WriteProcMsg("对表%s更新纪录数%d条",sTableName,iUpdateCnt);
	}
	if(EUpdateStructToSpcpStat(NULL,true,&TempUp)<0){
		printf("更新数据错误SPCP_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%s更新完毕,共计记录数%d条",sTableName,iUpdateCnt);

	WriteProcPrint("汇总数据到表%s正确,输出记录数%d,更新记录数%d",
		sTableName,iCnt,iUpdateCnt);
	return 0;

}


/**对表SPCP_STAT的链表释放函数**/
void DestroySpcpStat(struct SpcpStatStruct *ptHead)
{
	struct SpcpStatStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

int XDealSpcpStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[])
{
	int iCnt=0;

	if((iCnt=SpcpStat2Bin(pRoot,sStatName,sBillingCycleID))<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}
	WriteProcMsg("加载%s表%s帐周的数据完毕,%d条",
		sStatName,sBillingCycleID,iCnt);

/*将有sRowID的加到UPDATE链表，将无ROWID的加到INSERT链表*/
	DestroySpcpStat(pSpcpStatOut);
	DestroySpcpStat(pSpcpStatOut);
	TravelBin(pRoot,link_spcp_stat_outup);

/**输出数据到统计表**/
	if(SpcpStatList2Table(pSpcpStatOut,pSpcpStatOut,sStatName)<0){
		WriteAlertMsg("输出数据到统计表出错.\n");
		return -1;
	}
}

/*GPRS1X处理*/
int GPRS1X_DealRecord(char sInput[],char sOutType[],char sBillingCycleID[])
{
	char *pc;
	struct 	Gprs1xStatStruct	Temp;


	if((pc=strstr(STATCTL.sOutStr,sOutType))==NULL){
		strcat(STATCTL.sOutStr,sOutType);
		strcat(STATCTL.sOutStr,"|");
	}


	bzero((void*)&Temp,sizeof(struct Gprs1xStatStruct));
	strncpy(Temp.sBillingCycleID,sBillingCycleID,6);
	Temp.sBillingCycleID[6]=0;

	if(GetGprs1xStat(sInput,&Temp)!=0)return -1;


	if(Is1XT(sOutType)){
		if(InsertBin(&GXP_pRoot,(void *)&Temp,
			data_search_bintree_gprs1x_stat_e,
			assign_insert_bintree_gprs1x_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败Gprs1xStatStruct");
			return -1;
		}
	}
	else if(IsA1XT(sOutType)){
		if(InsertBin(&GXT_pRoot,(void *)&Temp,
			data_search_bintree_gprs1x_stat_e,
			assign_insert_bintree_gprs1x_stat_e)<0){
			WriteAlertMsg("生成BINTREE失败Gprs1xStatStruct");
			return -1;
		}
	}

	return 0;
}

int data_search_bintree_gprs1x_stat_e(void *pValue,void*pData)
{
	struct Gprs1xStatStruct *pSource=(struct Gprs1xStatStruct *)pValue;
	struct Gprs1xStatStruct *pTarget=(struct Gprs1xStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	if((res=strcmp(pSource->sOppAreaCode,pTarget->sOppAreaCode))!=0) return res;

	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;

	if((res=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return res;
	if((res=strcmp(pSource->sMsisdnHead,pTarget->sMsisdnHead))!=0) return res;
	if((res=strcmp(pSource->sMsisdnBillingTypeID,pTarget->sMsisdnBillingTypeID))!=0) return res;

	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}
void assign_insert_bintree_gprs1x_stat_e(void **ppData,void *pData)
{
	struct Gprs1xStatStruct *pHead=(struct Gprs1xStatStruct *)(*ppData);
	struct Gprs1xStatStruct *pValue=(struct Gprs1xStatStruct *)pData;

	if(pHead==NULL){
		pHead=malloc(sizeof(struct Gprs1xStatStruct));
		ERROR_EXIT(pHead==NULL,"分配Gprs1xStatStruct结构错误");

		memcpy((void*)pHead,pData,sizeof(struct Gprs1xStatStruct));
		pHead->pNext=NULL;
		*ppData=(void*)pHead;
	}
	else{
		pHead->iFlowFee+=	pValue->iFlowFee;
		pHead->iIncome+=	pValue->iIncome;
		pHead->iOutcome+=	pValue->iOutcome;
		pHead->iDataFlow+=	pValue->iDataFlow;
	}
}

int GetGprs1xStat(char sInput[],struct Gprs1xStatStruct *p)
{

	ParseArgv(sInput,'|');

	strcpy(p->sAreaCode		,ParseToken[0]);
	strcpy(p->sOppAreaCode		,ParseToken[1]);

	p->iTicketTypeID		=atoi(ParseToken[2]);

	strcpy(p->sNetType	        ,ParseToken[3]);
	strcpy(p->sMsisdnHead		,ParseToken[4]);
	strcpy(p->sMsisdnBillingTypeID	,ParseToken[5]);

	p->iFlowFee		=atoi(ParseToken[6]);
	p->iIncome		=atoi(ParseToken[7]);
	p->iOutcome		=atoi(ParseToken[8]);
	p->iDataFlow		=(LONGINT)atoi(ParseToken[9]);

	strcpy(p->sSettItemDate		,ParseToken[10]);

	return 0;
}



int link_gprs_1x_stat_outup(void **ppData)
{
	struct Gprs1xStatStruct *pTemp=(struct Gprs1xStatStruct *)(*ppData);

	if(pTemp->sRowID[0]==0)
		InsertList((LIST**)&pGprs1xStatOut,(LIST*)pTemp);
	else	InsertList((LIST**)&pGprs1xStatUp,(LIST*)pTemp);

	return 0;
}
/*从数据库中取数据，并加到汇总纪录中*/
int Gprs1xStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct Gprs1xStatStruct Temp;
        static struct Gprs1xStatStructIn TempIn;

        static struct Gprs1xStatStruct *pHead=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,
		" WHERE BILLING_CYCLE_ID ='%s' ",sCycleID);

        /*取出表中记录加载二叉树*/
        while(EGetGprs1xStatToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_gprs1x_stat_e,
			(void **)&pHead)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
			if(pHead->sRowID[0]!=0) continue;

			sum_gprs_1x_stat(pHead,&Temp);
		}
		iCnt++;
        }
	return iCnt;
}
void sum_gprs_1x_stat(struct Gprs1xStatStruct *pHead,
	 struct Gprs1xStatStruct *pTemp)
{

	pHead->iFlowFee+=	pTemp->iFlowFee;
	pHead->iIncome+=	pTemp->iIncome;
	pHead->iOutcome+=	pTemp->iOutcome;
	pHead->iDataFlow+=	pTemp->iDataFlow;	

	strcpy(pHead->sRowID,	pTemp->sRowID);
}

int Gprs1xStatList2Table(struct Gprs1xStatStruct *ptOut,
	struct Gprs1xStatStruct *ptUp,char sTableName[])
{
	struct Gprs1xStatStructOut TempOut;
	struct Gprs1xStatStructUp TempUp;
	struct	Gprs1xStatStruct *ptCur,*ptPre;
	int	iCnt=0,iUpdateCnt=0;

/**输出数据到统计表**/
        bzero((void*)&TempOut,sizeof(struct Gprs1xStatStructOut));
        bzero((void*)&TempUp,sizeof(struct Gprs1xStatStructUp));

        strcpy(TempOut.sTableName,sTableName);
        strcpy(TempUp.sTableName,sTableName);

  	ptCur=ptOut;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToGprs1xStat(ptPre,false,&TempOut)<0){
			printf("输出数据错误GPRS_1X_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iCnt)%10000==0)
			WriteProcMsg("对表%s输出纪录数%d条",sTableName,iCnt);

	}
	if(EInsertStructToGprs1xStat(NULL,true,&TempOut)<0){
		printf("输出数据错误GPRS_1X_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%输出完毕,共计记录数%d条",iCnt);

/**更新数据到日帐表**/
	ptCur=ptUp;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToGprs1xStat(ptPre,false,&TempUp)<0){
			printf("更新数据错误GPRS_1X_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iUpdateCnt)%10000==0)
			WriteProcMsg("对表%s更新纪录数%d条",sTableName,iUpdateCnt);
	}
	if(EUpdateStructToGprs1xStat(NULL,true,&TempUp)<0){
		printf("更新数据错误GPRS_1X_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%s更新完毕,共计记录数%d条",sTableName,iUpdateCnt);

	WriteProcPrint("汇总数据到表%s正确,输出记录数%d,更新记录数%d",
		sTableName,iCnt,iUpdateCnt);
	return 0;

}



/**对表GPRS1X_STAT的链表释放函数**/
void DestroyGprs1xStat(struct Gprs1xStatStruct *ptHead)
{
	struct Gprs1xStatStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

int XDealGprs1xStat(BINTREE *pRoot,char sStatName[],char sBillingCycleID[])
{
	int iCnt=0;

	if((iCnt=Gprs1xStat2Bin(pRoot,sStatName,sBillingCycleID))<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}
	WriteProcMsg("加载%s表%s帐周的数据完毕,%d条",
		sStatName,sBillingCycleID,iCnt);

/*将有sRowID的加到UPDATE链表，将无ROWID的加到INSERT链表*/

	DestroyGprs1xStat(pGprs1xStatOut);
	DestroyGprs1xStat(pGprs1xStatUp);
	TravelBin(pRoot,link_gprs_1x_stat_outup);

/**输出数据到统计表**/
	if(Gprs1xStatList2Table(pGprs1xStatOut,pGprs1xStatUp,sStatName)<0){
		WriteAlertMsg("输出数据到统计表出错.\n");
		return -1;
	}
}

int CompileStatExpr(char sExprName[])
{
	int l,i;
	FILE *fp;
	char	sInput[EXPRLEN];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];

	if(IsFile(sExprName)==FALSE){
		printf("公式文件%s无效.\n",sExprName);
		return -1;
	}
/*将公式文件读到内存*/
	if((l=FileSize(sExprName))>=EXPRLEN){
		printf("参数文件%s大于%d,%d.\n",sExprName,EXPRLEN,l);
		return -1;
	}
	fp=fopen(sExprName,"r");
	if(fread(sInput,l,1,fp)!=1){
		printf("读文件%s失败.\n",sExprName);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);

/*注册公式函数*/
	RegPrepVar();
	RegAcctItemVar();
	CheckSysVar=CheckAcctItemVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	return 0;
}
int main(int argc, char **argv)
{
	int  iTotalCnt=0,iCnt=0,t1=0,iTicketValid=-1,iOppCarr=0;
	char sSourceID[31],sRowID[19],sType[2],sStatName[31],sLockName[256];
	char sTableName[31],sCondition[128],sExprName[128],sDateTemp[15];
	char sStatDate[15],sChkDate[15],sStrOri[4096],sTemp[104],sAppID[256];
	char sBillingCycleID[7],sExprServiceType[6],*pPre,*pCur;


	if(argc!=8){
		printf("Usage %s exprfile type(S,P,T,N,X) oppcarr tablename \
statdate servicetype [wherecause].\n",argv[0]);
		return -1;
	}
	sprintf(sAppID,"%s_%s",argv[0],argv[3]);
	InitAppRes(sAppID);
	strcpy(sExprName,argv[1]);
	strncpy(sType,argv[2],1);sType[1]=0;
	iOppCarr=	atoi(argv[3]);
	strcpy(sTableName,argv[4]);Upper(sTableName);
	strcpy(sDateTemp,argv[5]);Upper(sDateTemp);sDateTemp[8]=0;
	strcpy(STATCTL.sServiceType,argv[6]);
        strcpy(sCondition,argv[7]);Upper(sCondition);

	STATCTL.iOppCarr=iOppCarr;


        strcpy(sChkDate,sDateTemp); strcat(sChkDate,"000000");
        if((t1=tGetTime(sChkDate))<0) return -1;
/*取前一天日期        if(AddTimes(sChkDate,-86400)<0) return -1;*/
        strncpy(sStatDate,sChkDate,8);  sStatDate[8]=0;

	strcpy(sStatDate,sDateTemp);


	switch (sType[0]){
		case 'S':Ticket2Str=SttTicket2Str;break;
		case 'P':Ticket2Str=PrepTicket2Str;break;
		case 'T':Ticket2Str=SmsTicket2Str;break;
		case 'N':Ticket2Str=SmspTicket2Str;break;
		case 'X':Ticket2Str=Cdma1xTicket2Str;break;
		default:
			printf("系统不支持%s的类别,类别=(S,P,T,N,X).\n",sType);
			return -1;
	}
	RegRateExprFun();
	RegSimpleServExprFun();
/*处理编译公式*/
	if(CompileStatExpr(sExprName)<0){
		printf("处理公式文件%s失败.\n",sExprName);
		WriteErrStackAlert();
		return -1;
	}
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;

	strncpy(sBillingCycleID,sStatDate,6);sBillingCycleID[6]=0;

	if(strlen(sCondition)==0)
		sprintf(sCondition," WHERE SUBSTR(START_TIME,1,8)='%s' ",sStatDate);

/*判断DAYLY_STAT_LOG日志表*/
	if(CheckDaylyStatLog(STATCTL.sServiceType,sStatDate)<0)return -1;
	CommitWork();

	WriteProcMsg("对表%s统计日期%s的统计开始",sTableName,sStatDate);

	while(Ticket2Str(sTableName,sCondition,sSourceID,sRowID,TICKET.sOri)==true){

		++iTotalCnt;
		if(iTotalCnt==1) TICKET.iOriLen=strlen(TICKET.sOri);

		set_str_value("$FILENAME",pExprBuf,sSourceID);
		set_int_value("opp_carrier_id",pExprBuf,iOppCarr);
		set_str_value("stat_date",pExprBuf,sStatDate);

		if(ExecCode(pExprBuf)<0){
			printf("执行公式%s失败.\n",sExprName);
			if(SetDaylyStatLog(STATCTL.sServiceType,
				sStatDate,"A0A")<0)return -1;
			CommitWork();
			return -1;
		}

	/*str_ori格式："记录1;记录2;记录3;记录n....;"

	    记录1格式:"TYPE,字段"
	    	TYPE格式:"TYPE1|TYPE2"
	    		TYPE1表示:本记录有效性, TYPE1='X'表示本记录输出无效;
	    		TYPE2表示:sOutType     输出类型
	    	字段格式:"字段1|字段2|字段3|字段n...."
	*/

		get_str_value("str_ori",pExprBuf,sStrOri);
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);

		if(iTicketValid<0) continue;	/*数据源不统计*/

		get_str_value("service_type",pExprBuf,sExprServiceType);
		
		if(strcmp(STATCTL.sServiceType,sExprServiceType)!=0){
			printf("命令行ServiceType=%s和公式中\
ServiceType=%s不相符.\n",STATCTL.sServiceType,sExprServiceType);
			WriteAlertMsg("命令行ServiceType=%s和公式中\
ServiceType=%s不相符.",	STATCTL.sServiceType,sExprServiceType);				
			if(SetDaylyStatLog(STATCTL.sServiceType,
				sStatDate,"A0A")<0)return -1;
			CommitWork();
			return -1;

		}
		
		
		pPre=sStrOri;
		pCur=strchr(pPre,';');

		while(1){
			if(pCur!=NULL){
				strncpy(sTemp,pPre,pCur-pPre);
				sTemp[pCur-pPre]=0;
			}
			else	strcpy(sTemp,pPre);

			if(pCur==NULL) break;

			pPre=pCur+1;
			pCur=strchr(pPre,';');

			if(sTemp[0]==0) continue;

		/*处理统计记录*/
			if(XDealRecord(sTemp,sBillingCycleID)<0)continue;
		}

		if((++iCnt%30000)==0)
			WriteProcMsg("表%s当前话单数为%d 参与统计数为%d",
				sTableName,iTotalCnt,iCnt);
	}
	WriteProcMsg("表%s当前话单数为%d 参与统计数为%d",
		sTableName,iTotalCnt,iCnt);

	WriteProcMsg("加载%s类型%s帐期数据到内存",STATCTL.sServiceType,sBillingCycleID);

/*加载统计表,将加载的数据和平衡二叉树上的数据汇总，然后输出的统计表*/
	if(XDealStatData(sBillingCycleID)<0){
		RollbackWork();
		if(SetDaylyStatLog(STATCTL.sServiceType,
			sStatDate,"A0A")<0)return -1;
		CommitWork();
		return -1;
	}

	/*处理完，update STATE='A0H'*/
	if(SetDaylyStatLog(STATCTL.sServiceType,sStatDate,"A0H")<0)return -1;
	
	WriteProcMsg("对表%s统计日期%s的统计结束",sTableName,sStatDate);
	
	CommitWork();
	DestroyBinX();
	DisconnectDatabase();

	return 0;
}
