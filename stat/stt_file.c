#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <wwfile.h>
#include <expr_fun.h>
#include <datatype.h>

#include "dbsupp.h"
#include "stt_ticket.h"
#include "sett_item.h"

BINTREE *pRoot=NULL;
BINTREE *pOutRoot=NULL;

BINTREE *pSettTypeRoot=NULL;

struct SettDayStruct *ptSettDay=NULL;
struct SettMonthStruct *ptSettMonth=NULL;
struct CustCntStruct *ptCustCnt=NULL;
struct SmsStatUpStruct *ptSmsStatUp=NULL;

char sCapitalCode[4];

int AddDate(char sStatDate[],int i,char sFileType[]);

int SettTypeRelation2Bintree(BINTREE **ppRoot)
{
	static int iFirstFlag=true;
        static struct SettTypeRelationStruct Temp;
        static struct SettTypeRelationStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,"SETT_TYPE_RELATION");
        	strcpy(TempIn.sCondition,"");
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetSettTypeRelationToStruct(&Temp,&TempIn)){

                if(InsertBin(ppRoot,&Temp,
			data_search_bintree_sett_type_r_e,
			assign_insert_bintree_sett_type_r_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
        }
	return 0;
}
int data_search_bintree_sett_type_r_e(void *pValue,void*pData)
{
	struct SettTypeRelationStruct *pSource=(struct SettTypeRelationStruct *)pValue;
	struct SettTypeRelationStruct *pTarget=(struct SettTypeRelationStruct *)pData;
	int res;
	
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
	
	if((res=strcmp(pSource->sSettType,pTarget->sSettType))!=0) return res;
	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	
	

	return 0;
}

void assign_insert_bintree_sett_type_r_e(void **ppData,void *pData)
{

	struct SettTypeRelationStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SettTypeRelationStruct));
		ERROR_EXIT(pTemp==NULL,"分配SettTypeRelation结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SettTypeRelationStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
}


int rdata_search_bintree_sett_type_r_e(void *pValue,void*pData)
{
	struct SettTypeRelationStruct *pSource=(struct SettTypeRelationStruct *)pValue;
	struct SettTypeRelationStruct *pTarget=(struct SettTypeRelationStruct *)pData;
	int res;
	
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
	
	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	
	

	return 0;
}


int data_search_bintree_sett_day_e(void *pValue,void*pData)
{
	struct SettDayStruct *pSource=(struct SettDayStruct *)pValue;
	struct SettDayStruct *pTarget=(struct SettDayStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
	if((res=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return res;
	if((res=strcmp(pSource->sStartDate,pTarget->sStartDate))!=0) return res;
	if((res=strcmp(pSource->sCallingCarrierID,pTarget->sCallingCarrierID))!=0) return res;
	if((res=strcmp(pSource->sCalledCarrierID,pTarget->sCalledCarrierID))!=0) return res;
	if((res=strcmp(pSource->sThirdCarrierID,pTarget->sThirdCarrierID))!=0) return res;
	if((res=strcmp(pSource->sSettCarrierID,pTarget->sSettCarrierID))!=0) return res;
	if((res=strcmp(pSource->sSettType,pTarget->sSettType))!=0) return res;
	if((res=strcmp(pSource->sRoamType,pTarget->sRoamType))!=0) return res;
	if((res=strcmp(pSource->sTariffType,pTarget->sTariffType))!=0) return res;
	if((res=strcmp(pSource->sCountyFlag,pTarget->sCountyFlag))!=0) return res;
	if((res=strcmp(pSource->sIpAccNbr,pTarget->sIpAccNbr))!=0) return res;

	return 0;
}

void assign_insert_bintree_sett_day_e(void **ppData,void *pData)
{
	int iDurationCnt=0,iDuration=0,iSettCnt=0,iTotalFee=0,iCount=0;

	struct SettDayStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SettDayStruct));
		ERROR_EXIT(pTemp==NULL,"分配SettDayStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SettDayStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	iDurationCnt	=atoi(((struct SettDayStruct*)pData)->sDurationCnt);
	iDuration	=atoi(((struct SettDayStruct*)pData)->sDuration);
	iSettCnt	=atoi(((struct SettDayStruct*)pData)->sSettCnt);
	iTotalFee	=atoi(((struct SettDayStruct*)pData)->sTotalFee);
	iCount		=atoi(((struct SettDayStruct*)pData)->sCount);

	iDurationCnt	+=atoi(pTemp->sDurationCnt);  
	iDuration	+=atoi(pTemp->sDuration);     
	iSettCnt	+=atoi(pTemp->sSettCnt);      
	iTotalFee	+=atoi(pTemp->sTotalFee);     
	iCount		+=atoi(pTemp->sCount);        
	
	sprintf(pTemp->sDurationCnt ,	"%d",iDurationCnt);
	sprintf(pTemp->sDuration    ,	"%d",iDuration	);
	sprintf(pTemp->sSettCnt     ,	"%d",iSettCnt	);
	sprintf(pTemp->sTotalFee    ,	"%d",iTotalFee	);
	sprintf(pTemp->sCount       ,	"%d",iCount	);	
	
}

int data_search_bintree_sett_month_e(void *pValue,void*pData)
{
	struct SettMonthStruct *pSource=(struct SettMonthStruct *)pValue;
	struct SettMonthStruct *pTarget=(struct SettMonthStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return res;
	if((res=strcmp(pSource->sStatMonth,pTarget->sStatMonth))!=0) return res;
	if((res=strcmp(pSource->sSettCarrierID,pTarget->sSettCarrierID))!=0) return res;
	if((res=strcmp(pSource->sSettType,pTarget->sSettType))!=0) return res;

	return 0;
}

void assign_insert_bintree_sett_month_e(void **ppData,void *pData)
{
	double iDurationCnt,iDuration,iSettCnt,iCount,iTotalFee;

	struct SettMonthStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SettMonthStruct));
		ERROR_EXIT(pTemp==NULL,"分配SettMonthStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SettMonthStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	iDurationCnt=0.0;
	iDuration=0.0;
	iSettCnt=0.0;
	iTotalFee=0.0;
	iCount=0.0;

	iDurationCnt	=atof(((struct SettMonthStruct*)pData)->sDurationCnt); 
	iDuration	=atof(((struct SettMonthStruct*)pData)->sDuration);    
	iSettCnt	=atof(((struct SettMonthStruct*)pData)->sSettCnt);     
	iTotalFee	=atof(((struct SettMonthStruct*)pData)->sTotalFee);    
	iCount		=atof(((struct SettMonthStruct*)pData)->sCount);       

	iDurationCnt	+=atof(pTemp->sDurationCnt);  
	iDuration	+=atof(pTemp->sDuration);     
	iSettCnt	+=atof(pTemp->sSettCnt);      
	iTotalFee	+=atof(pTemp->sTotalFee);     
	iCount		+=atof(pTemp->sCount);        
	
	sprintf(pTemp->sDurationCnt ,	"%-15.0f",iDurationCnt);
	sprintf(pTemp->sDuration    ,	"%-15.0f",iDuration);
	sprintf(pTemp->sSettCnt     ,	"%-15.0f",iSettCnt);
	sprintf(pTemp->sTotalFee    ,	"%-15.0f",iTotalFee);
	sprintf(pTemp->sCount       ,	"%-15.0f",iCount);	
	
}

int data_search_bintree_cust_cnt_e(void *pValue,void*pData)
{
	struct CustCntStruct *pSource=(struct CustCntStruct *)pValue;
	struct CustCntStruct *pTarget=(struct CustCntStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sStatMonth,pTarget->sStatMonth))!=0) return res;
	if((res=strcmp(pSource->sOppCarrierID,pTarget->sOppCarrierID))!=0) return res;

	return 0;
}

void assign_insert_bintree_cust_cnt_e(void **ppData,void *pData)
{

	struct CustCntStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct CustCntStruct));
		ERROR_EXIT(pTemp==NULL,"分配CustCntStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct CustCntStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	pTemp->iCustCnt	+=((struct CustCntStruct*)pData)->iCustCnt;
	pTemp->iAddCustCnt	+=((struct CustCntStruct*)pData)->iAddCustCnt;

}


int data_search_bintree_sms_stat_up_e(void *pValue,void*pData)
{
	struct SmsStatUpStruct *pSource=(struct SmsStatUpStruct *)pValue;
	struct SmsStatUpStruct *pTarget=(struct SmsStatUpStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sSettCapitalCode,pTarget->sSettCapitalCode))!=0) return res;
	if((res=strcmp(pSource->sBillType,pTarget->sBillType))!=0) return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;
	if((res=strcmp(pSource->sSettAreaCode,pTarget->sSettAreaCode))!=0) return res;
	if((res=strcmp(pSource->sCallingCarrierID,pTarget->sCallingCarrierID))!=0) return res;
	if((res=strcmp(pSource->sRecordType,pTarget->sRecordType))!=0) return res;
	if((res=strcmp(pSource->sCalledCapitalCode,pTarget->sCalledCapitalCode))!=0) return res;
	if((res=strcmp(pSource->sCalledCarrierID,pTarget->sCalledCarrierID))!=0) return res;
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	
	if((res=strcmp(pSource->sFlag,pTarget->sFlag))!=0) return res;
	if((res=strcmp(pSource->sReserve,pTarget->sReserve))!=0) return res;

	return 0;
}

void assign_insert_bintree_sms_stat_up_e(void **ppData,void *pData)
{
	int iTotalCnt=0,iTotalFee=0;
	
	struct SmsStatUpStruct *pTemp;
	
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SmsStatUpStruct));
		ERROR_EXIT(pTemp==NULL,"分配SmsStatUpStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SmsStatUpStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}

	iTotalCnt	=atoi(((struct SmsStatUpStruct*)pData)->sTotalCnt);
	iTotalFee	=atoi(((struct SmsStatUpStruct*)pData)->sTotalFee);

	iTotalCnt	+=atoi(pTemp->sTotalCnt);  
	iTotalFee	+=atoi(pTemp->sTotalFee);     
	
	sprintf(pTemp->sTotalCnt ,	"%d",iTotalCnt);
	sprintf(pTemp->sTotalFee ,	"%d",iTotalFee);

}
int GetOppCarrierID(int iInCarrierID,char sOutCarrierID[])
{
	
	if(iInCarrierID==1)strcpy(sOutCarrierID,"20000");
	else if(iInCarrierID==2)strcpy(sOutCarrierID,"30000");
	else if(iInCarrierID==3)strcpy(sOutCarrierID,"40000");
	else if(iInCarrierID==4)strcpy(sOutCarrierID,"10000");
	else if(iInCarrierID==5)strcpy(sOutCarrierID,"50000");
	else if(iInCarrierID==6)strcpy(sOutCarrierID,"60000");
	else strcpy(sOutCarrierID,"99999");
	
	return 0;
}

int mvitem_Settitem2settmonth(struct SettItemStruct *pi,
	struct SettMonthStruct *po)
{/*数据移动部分*/

	int i=0,a=-1,b=0;
	char sSecPerCnt[6],sHostDate[15];

	struct SettTypeRelationStruct Temp,*pTemp=NULL;;

	bzero((void*)po,sizeof(struct SettMonthStruct));

	GetHostTime(sHostDate);
	po->iRecordNumber=0;

	if(strcmp(sCapitalCode,"311")==0){
		if(pi->iLatnID<=0||
			pi->iLatnID>35||
			(pi->iLatnID>=20&&pi->iLatnID<35)){
			return -1;
		}
		i=pi->iLatnID+300;
	}
	else if(strcmp(sCapitalCode,"591")==0){
		if(pi->iLatnID<11||pi->iLatnID>19){
			return -1;
		}
		i=pi->iLatnID+580;
		
	}
	else i=pi->iLatnID;
		
	sprintf(po->sVisitAreaCode,	"%05d",i);
	strncpy(po->sStatMonth,		pi->sSettItemDate,6);

	if(strlen(pi->sUserType)!=1)return -1;
	
	if(strncmp(pi->sUserType,"C",1)==0)
	        strcpy(Temp.sUserType,"C");
	else
	        strcpy(Temp.sUserType,"");
	
	if(pi->iAcctItemTypeID>800000&&pi->iAcctItemTypeID<900000)
		Temp.iTicketTypeID=(pi->iAcctItemTypeID-800000)/10;
	else	
		return -1;
	
	if((SearchBin(pSettTypeRoot,(void*)&Temp,
		rdata_search_bintree_sett_type_r_e,
		(void**)&pTemp))==NOTFOUND){/*未找到记录return*/
		return -1;
	}

	strncpy(po->sSettCarrierID,	pTemp->sCarrierID,5);
	strncpy(po->sSettType,		pTemp->sSettType,12);
	
	a=(pi->iAcctItemTypeID%10);
	
	if(a==0){
		sprintf(po->sDurationCnt,"%d",pi->iCharge);
		sprintf(po->sCount,	 "%d",pi->iCharge);
	}
	else if(a==1){
		sprintf(po->sDuration,"%d",pi->iCharge);
	}
	else if(a==2){
		GetBinStr("TICKET_TARIFF",Temp.iTicketTypeID,"",
			sHostDate,sSecPerCnt);
		i=atoi(sSecPerCnt);
		if(i<=0)i=60;
		b=(pi->iCharge)/i;
		
		sprintf(po->sSettCnt, "%d",b);
	}
	else if(a==3&&pi->iCharge!=0){
		sprintf(po->sTotalFee,"%d",pi->iCharge);
	}
	else if(a==4&&pi->iCharge!=0){
		sprintf(po->sTotalFee,"-%d",pi->iCharge);
	}

	return 0;
}
int mvitem_Settitem2custcnt(struct SettItemStruct *pi,
	struct CustCntStruct *po,char sStatDate[],char sUpStatDate[])
{/*数据移动部分*/

	int a=-1,iCarrierID=0;
	char sTemp[7];

	bzero((void*)po,sizeof(struct CustCntStruct));

		po->iRecordNumber=0;

		if(pi->iLatnID<=0||
			pi->iLatnID>35||
			(pi->iLatnID>=20&&pi->iLatnID<35)){
			return -1;
		}
		
		strncpy(sTemp,pi->sSettItemDate,6);sTemp[6]=0;
		strcpy(po->sStatMonth,sStatDate);
		
		if(pi->iAcctItemTypeID>800000&&pi->iAcctItemTypeID<900000)
			iCarrierID=(pi->iAcctItemTypeID-800000)/10000;
		else	
			return -1;

		GetOppCarrierID(iCarrierID,po->sOppCarrierID);

		a=(pi->iAcctItemTypeID%10);
		
		if(a==0){
			if(strcmp(sTemp,sStatDate)==0)
				po->iCustCnt=pi->iCharge;
			else if(strcmp(sTemp,sUpStatDate)==0)
				po->iAddCustCnt=pi->iCharge;
			else return -1;
		}


	return 0;
}

int GetSmsCarrierID(int iInCarrierID,char sOutCarrierID[])
{
	
	if(iInCarrierID==1)strcpy(sOutCarrierID,"02");
	else if(iInCarrierID==2)strcpy(sOutCarrierID,"04");
	else if(iInCarrierID==3)strcpy(sOutCarrierID,"03");
	else if(iInCarrierID==4)strcpy(sOutCarrierID,"01");
	else if(iInCarrierID==5)strcpy(sOutCarrierID,"05");
	else if(iInCarrierID==6)strcpy(sOutCarrierID,"06");
	else strcpy(sOutCarrierID,"00");
	
	return 0;
}

int mvitem_MsisdnStat2SmsStatUp(struct MsisdnStatStruct *pi,
	struct SmsStatUpStruct *po)
{/*数据移动部分*/

	int i=0;
	char sTemp[7];

	bzero((void*)po,sizeof(struct SmsStatUpStruct));

		strcpy(po->sSettCapitalCode,sCapitalCode);
		strncpy(po->sBillType,		pi->sCallType,1);
		po->sBillType[1]=0;
		
		strcpy(po->sBillingCycleID,"000000");
		
		/*结算本地网标识+","+被叫所属省公司标识*/
		GetSepStr(pi->sAreaCode,',',0,sTemp);AllTrim(sTemp);
		sprintf(po->sSettAreaCode,"%03d",atoi(sTemp));
		
		strcpy(sTemp,"");
		GetSepStr(pi->sAreaCode,',',1,sTemp);AllTrim(sTemp);
		if(atoi(sTemp)==0)
			strcpy(po->sCalledCapitalCode,"");
		else 
			sprintf(po->sCalledCapitalCode,"%03d",atoi(sTemp));
		
		strcpy(po->sRecordType,	pi->sNetType);
		
		/*主叫所属运营商标识*10+被叫所属运营商标识*/
		if(pi->iAreaID==0){
			strcpy(po->sCallingCarrierID,"00");
			strcpy(po->sCalledCarrierID,"00");
		}
		else{
			i=pi->iAreaID/10;
			GetSmsCarrierID(i,po->sCallingCarrierID);
			i=pi->iAreaID%10;
			GetSmsCarrierID(i,po->sCalledCarrierID);
		}

		strncpy(po->sSpCode,		pi->sMsisdn,10);
		po->sSpCode[10]=0;
		
		sprintf(po->sTotalCnt,"%d",pi->iTotalCnt);
		sprintf(po->sTotalFee,"%d",pi->iTotalFee1+pi->iTotalFee2);
		strcpy(po->sFlag,"0");
		strcpy(po->sReserve,"");

	return 0;
}


int NbrTrim(char sAccNbr[])
{
	int l=0;
	char sTemp[24];
	
	strcpy(sTemp,sAccNbr);
	l=strlen(sTemp)-1;
	
	if(strncmp(sTemp+l,"A",1)==0||
		strncmp(sTemp+l,"B",1)==0||
		strncmp(sTemp+l,"C",1)==0){
		sAccNbr[l]=0;
		
	}
	
	return 0;
}

int mvitem_SettSumDay2settday(struct SettSumDayStruct *pi,
	struct SettDayStruct *po)
{/*数据移动部分*/

	int i=0;
	char sTemp[10];
	struct SettTypeRelationStruct Temp,*pTemp=NULL;;

	bzero((void*)po,sizeof(struct SettDayStruct));

		po->iRecordNumber=0;
		NbrTrim(pi->sHomeAreaCode);
		NbrTrim(pi->sCalledCode);
		sprintf(po->sHomeAreaCode,	"%05d",atoi(pi->sHomeAreaCode));
		sprintf(po->sCalledCode,	"%05d",atoi(pi->sCalledCode));
		strncpy(po->sStartDate,		pi->sStartDate,8);
		
		GetOppCarrierID(pi->iThirdCarrierID,po->sThirdCarrierID);
		
		strncpy(po->sIpAccNbr,		pi->sIpAccNbr,8);
		sprintf(po->sDurationCnt,	"%d",pi->iDurationCnt);
		sprintf(po->sDuration,		"%d",pi->iDuration);
		sprintf(po->sSettCnt,		"%d",pi->iSettCnt);
		sprintf(po->sTotalFee,		"%d",pi->iTotalFee);
		sprintf(po->sCount,		"%d",pi->iCount);

	        if(strncmp(pi->sUserType,"C",1)==0)
	                strcpy(Temp.sUserType,"C");
	        else
	                strcpy(Temp.sUserType,"");

		Temp.iTicketTypeID=pi->iTicketTypeID;
		
		if((SearchBin(pSettTypeRoot,(void*)&Temp,
			rdata_search_bintree_sett_type_r_e,
			(void**)&pTemp))==NOTFOUND){/*未找到记录return*/
			return -1;
		}

		strncpy(po->sSettCarrierID,	pTemp->sCarrierID,5);
		strncpy(po->sSettType,		pTemp->sSettType,12);
		strncpy(po->sTariffType,	pTemp->sTariffType,2);
		strncpy(po->sCountyFlag,	pTemp->sCountyFlag,1);
		
		if(strcmp(sCapitalCode,"591")==0){
			strncpy(sTemp,po->sSettType,2);sTemp[2]=0;
			i=atoi(sTemp);
			if(i>=10&&i<=60)
				sprintf(po->sCallingCarrierID,"%s000",sTemp);
			else	strcpy(po->sCallingCarrierID,	"99999");

			strncpy(sTemp,po->sSettType+6,2);sTemp[2]=0;
			i=atoi(sTemp);
			if(i>=10&&i<=60)
				sprintf(po->sCalledCarrierID,"%s000",sTemp);
			else	strcpy(po->sCalledCarrierID,	"99999");
			
			strcpy(po->sThirdCarrierID,	"     ");
			sprintf(po->sHomeAreaCode,	"%05d",atoi(pi->sVisitAreaCode));
			sprintf(po->sCalledCode,	"%05d",atoi(pi->sVisitAreaCode));

			strcpy(po->sRoamType,	"1");
			
		}			
		else{
			strcpy(po->sRoamType,	" ");
			GetOppCarrierID(pi->iCallingCarrierID,po->sCallingCarrierID);
			GetOppCarrierID(pi->iCalledCarrierID,po->sCalledCarrierID);
		}	
		
		/*非转接的po->sThirdCarrierID为空*/
		
		if(strcmp(pTemp->sSettType+1,"04010100000")!=0){
			strcpy(po->sThirdCarrierID,"");
		}
		
	return 0;
}

int SettItem2SettMonth(BINTREE **ppRoot,char sTableName[],
	char sStatDate[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct SettItemStruct Temp;
        static struct SettItemStructIn TempIn;
        
        struct SettMonthStruct TempOut;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition,
			" WHERE TO_CHAR(SETT_ITEM_DATE,'YYYYMM')='%s' ",sStatDate);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetSettItemToStruct(&Temp,&TempIn)){

		if(mvitem_Settitem2settmonth(&Temp,&TempOut)!=0){
			continue;
		}
		/*插入SettMonthStruct*/
                if(InsertBin(ppRoot,&TempOut,
			data_search_bintree_sett_month_e,
			assign_insert_bintree_sett_month_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
 		if((++iCnt%10000)==0)
			WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);
        }
	WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);        
	return 0;
}

int SettSumDay2SettDay(BINTREE **ppRoot,char sTableName[],
	char sStatDate[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct SettSumDayStruct Temp;
        static struct SettSumDayStructIn TempIn;
        
        struct SettDayStruct TempOut;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition,
			" WHERE START_DATE='%s' ",sStatDate);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetSettSumDayToStruct(&Temp,&TempIn)){

		if(mvitem_SettSumDay2settday(&Temp,&TempOut)!=0){
			continue;
		}
		/*插入SettDayStruct*/
                if(InsertBin(ppRoot,&TempOut,
			data_search_bintree_sett_day_e,
			assign_insert_bintree_sett_day_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
 		if((++iCnt%10000)==0)
			WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);
        }
	WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);        
	return 0;
}
int SettItem2CustCnt(BINTREE **ppRoot,char sTableName[],
	char sStatDate[])
{
	int iCnt=0;
	char sUpStatDate[7];
	
	static int iFirstFlag=true;
        static struct SettItemStruct Temp;
        static struct SettItemStructIn TempIn;
        
        struct CustCntStruct TempOut;

	strcpy(sUpStatDate,sStatDate);
	strcat(sUpStatDate,"01");sUpStatDate[6]=0;
	AddDate(sUpStatDate,-86400,"20209");
	
	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition," \n\
		WHERE TO_CHAR(SETT_ITEM_DATE,'YYYYMM') IN ('%s','%s') AND \n\
			SUBSTR(ACCT_ITEM_TYPE_ID,2,5) IN \n\
			('19100','29100','39100','49100','59100','69100') ",sStatDate,sUpStatDate);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetSettItemToStruct(&Temp,&TempIn)){

		if(mvitem_Settitem2custcnt(&Temp,
			&TempOut,sStatDate,sUpStatDate)!=0){
			continue;
		}
		/*插入CustCntStruct*/
                if(InsertBin(ppRoot,&TempOut,
			data_search_bintree_cust_cnt_e,
			assign_insert_bintree_cust_cnt_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
 		if((++iCnt%10000)==0)
			WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);
        }
	WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);        
	return 0;
}
int MsisdnStat2SmsStatUp(BINTREE **ppRoot,char sTableName[],
	char sStatDate[])
{
	int iCnt=0;
	
	static int iFirstFlag=true;
        static struct MsisdnStatStruct Temp;
        static struct MsisdnStatStructIn TempIn;
        
        struct SmsStatUpStruct TempOut;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition," \n\
		WHERE BILLING_CYCLE_ID='%s' AND SERVICE_TYPE='SMS' ",sStatDate);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetMsisdnStatToStruct(&Temp,&TempIn)){

		if(mvitem_MsisdnStat2SmsStatUp(&Temp,&TempOut)!=0){
			continue;
		}
		/*插入SmsStatUpStruct*/
                if(InsertBin(ppRoot,&TempOut,
			data_search_bintree_sms_stat_up_e,
			assign_insert_bintree_sms_stat_up_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
 		if((++iCnt%10000)==0)
			WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);
        }
	WriteProcMsg("加载表%s当前记录数为%d",sTableName,iCnt);        
	return 0;
}
int link_sms_stat_up(void **ppData)
{
	InsertList((LIST**)&ptSmsStatUp,(LIST*)(*ppData));
	return 0;
}
int link_cust_cnt(void **ppData)
{
	InsertList((LIST**)&ptCustCnt,(LIST*)(*ppData));
	return 0;
}
int link_sett_month(void **ppData)
{
	InsertList((LIST**)&ptSettMonth,(LIST*)(*ppData));
	return 0;
}
int link_sett_day(void **ppData)
{
	InsertList((LIST**)&ptSettDay,(LIST*)(*ppData));
	return 0;
}
int GetFileName(char sFileType[],char sStatDate[],char sNormalDir[],
	char sOutFileName[],char sChkFileName[])
{
	char sHostDate[15];
	
	strcpy(sOutFileName,"");
	if(strcmp(sFileType,"SMS")==0){
		GetHostTime(sHostDate);
		sHostDate[8]=0;
		sprintf(sOutFileName,"%s%s%s%s.%s",
			sNormalDir,sFileType,sCapitalCode,sHostDate,sStatDate);
			
		strcpy(sChkFileName,"");		
	}
	else{
		sprintf(sOutFileName,"%ss_00%s_%s_%s_00_001.dat",
			sNormalDir,sCapitalCode,sStatDate,sFileType);
		sprintf(sChkFileName,"%ss_00%s_%s_%s_00.verf",
			sNormalDir,sCapitalCode,sStatDate,sFileType);
		
	}
	
	return 0;
}
int SttMonth2File(struct SettMonthStruct *pSource,
	char sTargetName[],char sChkFileName[],char sStatDate[])
{
	int iFileRecordLen,iCnt=0,iFileSize=0,l=0,y=0;
	double iToTalFee;
	char sBaseName[128],sHostDate[15],sRecord[1024];
	struct FileControlStruct *pRec=NULL;
	struct SettMonthStruct	*ptHead=NULL,*pTemp;
	struct FSettMonthStruct FTemp;
	
	FILE *fp=NULL;

	ptHead=pSource;
	
	if(ptHead==NULL)return 0;
	
	iFileRecordLen=sizeof(struct FSettMonthStruct);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		pTemp->iRecordNumber=iCnt;

		iToTalFee=0.0;
		y=atoi(pTemp->sTotalFee);
		
		iToTalFee=y/1000.0;		
		
		sprintf(pTemp->sTotalFee,"%-13.2f",iToTalFee);
		
		mvitem_mfsettmonth(pTemp,&FTemp);
		
		if(item2listtail(&pRec,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2filelrn(&pRec,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}
	
	GetBaseName(sTargetName,sBaseName);
	iFileSize=FileSize(sTargetName);
	GetHostTime(sHostDate);
	
	listfree(&pRec);
	
	if((fp=fopen(sChkFileName,"w"))==NULL) return -1;
	
	l+=sprintf(sRecord+l,"%-40s%-20d%-20d%-8s%-14s\r\n",
			sBaseName,iFileSize,iCnt,sStatDate,sHostDate);
	
	WriteFile(fp,sRecord,l);
	
	fclose(fp);
	
	return iCnt;
}
int SttDay2File(struct SettDayStruct *pSource,
	char sTargetName[],char sChkFileName[],char sStatDate[])
{
	int iFileRecordLen,iCnt=0,iFileSize=0,l=0,y=0;
	double iToTalFee;
	char sBaseName[128],sHostDate[15],sRecord[1024];
	struct FileControlStruct *pRec=NULL;
	struct SettDayStruct	*ptHead=NULL,*pTemp;
	struct FSettDayStruct 	FTemp;
	
	FILE *fp=NULL;

	ptHead=pSource;
	
	if(ptHead==NULL)return 0;
	
	iFileRecordLen=sizeof(struct FSettDayStruct);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		pTemp->iRecordNumber=iCnt;
		
		iToTalFee=0.0;
		y=atoi(pTemp->sTotalFee);

		iToTalFee=y/1000.0;

		sprintf(pTemp->sTotalFee,"%-10.2f",iToTalFee);
		
		
		mvitem_mfsettday(pTemp,&FTemp);
		
		if(item2listtail(&pRec,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2filelrn(&pRec,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}
	
	GetBaseName(sTargetName,sBaseName);
	iFileSize=FileSize(sTargetName);
	GetHostTime(sHostDate);
	
	listfree(&pRec);
	
	if((fp=fopen(sChkFileName,"w"))==NULL) return -1;
	
	l+=sprintf(sRecord+l,"%-40s%-20d%-20d%-8s%-14s\r\n",
			sBaseName,iFileSize,iCnt,sStatDate,sHostDate);
	
	WriteFile(fp,sRecord,l);
	
	fclose(fp);
	
	return iCnt;
}
int CustCnt2File(struct CustCntStruct *pSource,
	char sTargetName[],char sChkFileName[],char sStatDate[])
{
	int iFileRecordLen,iCnt=0,iFileSize=0,l=0,y=0;
	char sBaseName[128],sHostDate[15],sRecord[1024];
	struct FileControlStruct *pRec=NULL;
	struct CustCntStruct	*ptHead=NULL,*pTemp;
	struct FCustCntStruct 	FTemp;
	
	FILE *fp=NULL;

	ptHead=pSource;
	
	if(ptHead==NULL)return 0;
	
	iFileRecordLen=sizeof(struct FCustCntStruct);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		pTemp->iRecordNumber=iCnt;
		
		y=pTemp->iAddCustCnt;
		
		pTemp->iAddCustCnt=pTemp->iCustCnt-y;
		
		if(pTemp->iAddCustCnt<0)pTemp->iAddCustCnt=0;

		mvitem_mfcustcnt(pTemp,&FTemp);
		
		if(item2listtail(&pRec,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2fileln(&pRec,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}
	
	GetBaseName(sTargetName,sBaseName);
	iFileSize=FileSize(sTargetName);
	GetHostTime(sHostDate);
	
	listfree(&pRec);
	
	if((fp=fopen(sChkFileName,"w"))==NULL) return -1;
	
	l+=sprintf(sRecord+l,"%-40s%-20d%-20d%-8s%-14s\n",
			sBaseName,iFileSize,iCnt,sStatDate,sHostDate);
	
	WriteFile(fp,sRecord,l);
	
	fclose(fp);
	
	return iCnt;
}
int SmsStatUp2File(struct SmsStatUpStruct *pSource,
	char sTargetName[],char sChkFileName[],char sStatDate[])
{
	int iFileRecordLen,iCnt=0;
	char sHostDate[15];
	struct FileControlStruct *pRec=NULL;
	struct SmsStatUpStruct	*ptHead=NULL,*pTemp;
	struct FSmsStatUpStruct	FTemp;
	struct FSmsStatUpHeadStruct FFileHead;
	
	static struct SmsStatUpHeadStruct *pFileHead=NULL;
	
	int iTotalCnt=0,iTotalFee=0;

	ptHead=pSource;
	
	if(ptHead==NULL)return 0;
	
	pFileHead=(struct SmsStatUpHeadStruct *)
		malloc(sizeof(struct SmsStatUpHeadStruct));
	ERROR_EXIT(pFileHead==NULL,"分配SmsStatUpHeadStruct结构错误");
	
	iFileRecordLen=sizeof(struct FSmsStatUpStruct);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		iTotalCnt+=atoi(pTemp->sTotalCnt);
		iTotalFee+=atoi(pTemp->sTotalFee);
				
		mvitem_mfsmsstatup(pTemp,&FTemp);
		
		if(item2listtail(&pRec,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	GetHostTime(sHostDate);
	
	sprintf(pFileHead->sServiceCode,"%-s","SMS");
	strcpy(pFileHead->CapitalCode,sCapitalCode);
	strncpy(pFileHead->sCreateDate,sHostDate,8);
	pFileHead->sCreateDate[8]=0;
	pFileHead->iFileCnt=iCnt;
	
	sprintf(pFileHead->sTotalCnt,"%0d",iTotalCnt);
	sprintf(pFileHead->sTotalFee,"%0d",iTotalFee);

	strcpy(pFileHead->sReserve,"");
	
	iFileRecordLen=sizeof(struct FSmsStatUpHeadStruct);
	
	mvitem_mfsmsstatuphead(pFileHead,&FFileHead);
		
	if(item2list(&pRec,(void*)&FFileHead,
		iFileRecordLen)<0){
		WriteAlertMsg("数据插入输出链表失败");
		return -1;
	}
		
	/*输出文件*/
	if(list2fileln(&pRec,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}
	
	
	listfree(&pRec);
	
	
	return iCnt;
}
int AddDate(char sStatDate[],int i,char sFileType[])
{
	char sChkDate[15];

	if(strcmp(sFileType,"20101")==0){
		strcpy(sChkDate,sStatDate);
		strcat(sChkDate,"000000");
		if(AddTimes(sChkDate,i)<0) return -1;
		strncpy(sStatDate,sChkDate,8);
		sStatDate[8]=0;
		
	}
	else if(strcmp(sFileType,"20102")==0||
		strcmp(sFileType,"20209")==0||
		strcmp(sFileType,"SMS")==0){
		strncpy(sChkDate,sStatDate,6);
		sChkDate[6]=0;
		strcat(sChkDate,"01000000");
		if(AddTimes(sChkDate,i)<0) return -1;
		strncpy(sStatDate,sChkDate,6);
		sStatDate[6]=0;
		
	}
	else{
		printf("系统不支持%s的类别,类别=(20101,20102,20209,SMS).\n",sFileType);
		return -1;	
	
	}

	
	return 0;
		
	
}
int main(int argc, char **argv)
{
	int  iCnt=0;
	char sStatDate[9],sNormalDir[256],sTableName[31],sFileType[6];
	char sOutFileName[256],sChkFileName[256];
	
	BINTREE *pSettRoot=NULL;

	if(argc!=6){
		printf("Usage %s tablename filetype normaldir statdate[yyyymmdd] CapitalCode .\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sTableName,argv[1]);
	Upper(sTableName);
	strcpy(sFileType,argv[2]);
	sFileType[5]=0;
	strcpy(sNormalDir,argv[3]);

	strcpy(sStatDate,argv[4]);
	sStatDate[8]=0;
	
	strcpy(sCapitalCode,argv[5]);sCapitalCode[4]=0;

/*初始化批价参数*/
	MoveAllShmToMem();
	
	AddDate(sStatDate,-86400,sFileType);

	RegularDir(sNormalDir);
	
	if(GetFileName(sFileType,sStatDate,sNormalDir,
		sOutFileName,sChkFileName)!=0){
		WriteAlertMsg("生成输出文件名失败");
		return -1;
	}
	
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;
/*加载SETT_TYPE_RELATION*/
	if(SettTypeRelation2Bintree(&pSettTypeRoot)<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}
	if(strcmp(sFileType,"20101")==0){	
	/*加载网间日汇总表并得到SettDay*/
		if(SettSumDay2SettDay(&pSettRoot,sTableName,sStatDate)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
	/*挂到ptSettDay中*/
		TravelBin(pSettRoot,link_sett_day);
	
	/*输出到网间日汇总文件*/
		if((iCnt=SttDay2File(ptSettDay,
			sOutFileName,sChkFileName,sStatDate))<0){
			RollbackWorkRelease();
			return -1;
		}
	}
	else if(strcmp(sFileType,"20102")==0){
	/*加载帐单表并得到SettMonth*/
		if(SettItem2SettMonth(&pSettRoot,sTableName,sStatDate)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
	/*挂到ptSettMonth中*/
		TravelBin(pSettRoot,link_sett_month);
	
	/*输出到网间月汇总文件*/
		if((iCnt=SttMonth2File(ptSettMonth,
			sOutFileName,sChkFileName,sStatDate))<0){
			RollbackWorkRelease();
			return -1;
		}
	}
	else if(strcmp(sFileType,"20209")==0){
	/*加载帐单表并得到CustCnt*/
		if(SettItem2CustCnt(&pSettRoot,sTableName,sStatDate)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
	/*挂到ptCustCnt中*/
		TravelBin(pSettRoot,link_cust_cnt);
	
	/*输出到竞争对手客户发展情况文件*/
		if((iCnt=CustCnt2File(ptCustCnt,
			sOutFileName,sChkFileName,sStatDate))<0){
			RollbackWorkRelease();
			return -1;
		}
	}
	else if(strcmp(sFileType,"SMS")==0){
	/*加载帐单表并得到SmsStatUp*/
		if(MsisdnStat2SmsStatUp(&pSettRoot,sTableName,sStatDate)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
	/*挂到ptSmsStatUp中*/
		TravelBin(pSettRoot,link_sms_stat_up);
	
	/*输出到竞争对手客户发展情况文件*/
		if((iCnt=SmsStatUp2File(ptSmsStatUp,
			sOutFileName,sChkFileName,sStatDate))<0){
			RollbackWorkRelease();
			return -1;
		}
	}		
	
	WriteProcMsg(" %d 条记录输出到文件 %s 成功.",iCnt,sOutFileName);
/*释放批价参数*/
	DistroyAllMem();

	DestroyBin(pRoot);
	DestroyBin(pSettRoot);

	DisconnectDatabase();
	
	return 0;
}
