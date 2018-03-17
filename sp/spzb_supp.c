#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <param_intf.h>

#include "spzb_supp.h"
#include "stt_ticket.h"

void mvitem_mfysticketup(struct OutYsTicketUpStruct *pi,struct FYsTicketUpStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FYsTicketUpStruct));

		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sSpServiceType,pi->sSpServiceType,strlen(pi->sSpServiceType));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));
		strncpy(po->sReserv2,pi->sReserv2,strlen(pi->sReserv2));
		strncpy(po->sYsHdCnt,pi->sYsHdCnt,strlen(pi->sYsHdCnt));
		strncpy(po->sYsFee,pi->sYsFee,strlen(pi->sYsFee));
		strncpy(po->sMoCnt,pi->sMoCnt,strlen(pi->sMoCnt));
		strncpy(po->sMtCnt,pi->sMtCnt,strlen(pi->sMtCnt));
		strncpy(po->sH20Cnt,pi->sH20Cnt,strlen(pi->sH20Cnt));
		strncpy(po->sH20Fee,pi->sH20Fee,strlen(pi->sH20Fee));
		strncpy(po->sReserv3,pi->sReserv3,strlen(pi->sReserv3));

}
void mvitem_mfysticketuphead(struct YsTicketUpHeadStruct *pi,struct FYsTicketUpHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FYsTicketUpHeadStruct));

		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVersion,pi->sFileVersion,strlen(pi->sFileVersion));
		strncpy(po->sFileCreatDate,pi->sFileCreatDate,strlen(pi->sFileCreatDate));
		strncpy(po->sProvCode,pi->sProvCode,strlen(pi->sProvCode));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sTotalCnt,pi->sTotalCnt,strlen(pi->sTotalCnt));
		strncpy(po->sTotalHdCnt,pi->sTotalHdCnt,strlen(pi->sTotalHdCnt));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sTotalMoCnt,pi->sTotalMoCnt,strlen(pi->sTotalMoCnt));
		strncpy(po->sTotalMtCnt,pi->sTotalMtCnt,strlen(pi->sTotalMtCnt));
		strncpy(po->sTotalH20Cnt,pi->sTotalH20Cnt,strlen(pi->sTotalH20Cnt));
		strncpy(po->sTotalH20Fee,pi->sTotalH20Fee,strlen(pi->sTotalH20Fee));
		strncpy(po->sReserv2,pi->sReserv2,strlen(pi->sReserv2));

}

int data_search_bintree_cx_down_e(void *pValue,void*pData)
{
	struct CxTicketDownStruct *pSource=(struct CxTicketDownStruct *)pValue;
	struct CxTicketDownStruct *pTarget=(struct CxTicketDownStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) return res;
	if((res=strcmp(pSource->sCityCode,pTarget->sCityCode))!=0) return res;
	if((res=strcmp(pSource->sReserv3,pTarget->sReserv3))!=0) return res;

	return 0;
}

int data_search_bintree_smsb_e(void *pValue,void*pData)
{
	struct SmsTicketBStruct *pSource=(struct SmsTicketBStruct *)pValue;
	struct SmsTicketBStruct *pTarget=(struct SmsTicketBStruct *)pData;
	int res;

	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) return res;
	if((res=strcmp(pSource->sCityCode,pTarget->sCityCode))!=0) return res;
	if((res=strcmp(pSource->sNetTpye,pTarget->sNetTpye))!=0) return res;
	if((res=strcmp(pSource->sChkDate,pTarget->sChkDate))!=0) return res;


	return 0;
}

void assign_insert_bintree_smsb_e(void **ppData,void *pData)
{
	int iYsHdCnt=0,iYsFee=0,iMoCnt=0,iMtCnt=0;

	struct SmsTicketBStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SmsTicketBStruct));
		ERROR_EXIT(pTemp==NULL,"分配SpServ结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SmsTicketBStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	
	iYsHdCnt=atoi(pTemp->sYsHdCnt)+
		atoi(((struct SmsTicketBStruct*)pData)->sYsHdCnt);
	iYsFee=atoi(pTemp->sYsFee)+
		atoi(((struct SmsTicketBStruct*)pData)->sYsFee);
	iMoCnt=atoi(pTemp->sMoCnt)+
		atoi(((struct SmsTicketBStruct*)pData)->sMoCnt);
	iMtCnt=atoi(pTemp->sMtCnt)+
		atoi(((struct SmsTicketBStruct*)pData)->sMtCnt);


	sprintf(pTemp->sYsHdCnt,		"%010d",iYsHdCnt);
	sprintf(pTemp->sYsFee,		        "%015d",iYsFee);
	sprintf(pTemp->sMoCnt,		        "%010d",iMoCnt);
	sprintf(pTemp->sMtCnt,		        "%010d",iMtCnt);

}




int data_search_bintree_ysup_e(void *pValue,void*pData)
{
	struct OutYsTicketUpStruct *pSource=(struct OutYsTicketUpStruct *)pValue;
	struct OutYsTicketUpStruct *pTarget=(struct OutYsTicketUpStruct *)pData;
	int res;

	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) return res;
	if((res=strcmp(pSource->sCityCode,pTarget->sCityCode))!=0) return res;
	if((res=strcmp(pSource->sReserv1,pTarget->sReserv1))!=0) return res;
	if((res=strcmp(pSource->sReserv2,pTarget->sReserv2))!=0) return res;
	if((res=strcmp(pSource->sReserv3,pTarget->sReserv3))!=0) return res;
	if((res=strcmp(pSource->sOutFileName,pTarget->sOutFileName))!=0) return res;

	return 0;
}

void assign_insert_bintree_ysup_e(void **ppData,void *pData)
{

	int iYsHdCnt=0,iYsFee=0,iMoCnt=0,iMtCnt=0,iH20Cnt=0,iH20Fee=0;
	struct OutYsTicketUpStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct OutYsTicketUpStruct));
		ERROR_EXIT(pTemp==NULL,"分配SpServ结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct OutYsTicketUpStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	iYsHdCnt=atoi(pTemp->sYsHdCnt)+
		atoi(((struct OutYsTicketUpStruct*)pData)->sYsHdCnt);
	iYsFee=atoi(pTemp->sYsFee)+
		atoi(((struct OutYsTicketUpStruct*)pData)->sYsFee);
	iMoCnt=atoi(pTemp->sMoCnt)+
		atoi(((struct OutYsTicketUpStruct*)pData)->sMoCnt);
	iMtCnt=atoi(pTemp->sMtCnt)+
		atoi(((struct OutYsTicketUpStruct*)pData)->sMtCnt);
	iH20Cnt=atoi(pTemp->sH20Cnt)+
		atoi(((struct OutYsTicketUpStruct*)pData)->sH20Cnt);
	iH20Fee=atoi(pTemp->sH20Fee)+
		atoi(((struct OutYsTicketUpStruct*)pData)->sH20Fee);


	sprintf(pTemp->sYsHdCnt,		"%010d",iYsHdCnt);
	sprintf(pTemp->sYsFee,		        "%015d",iYsFee);
	sprintf(pTemp->sMoCnt,		        "%010d",iMoCnt);
	sprintf(pTemp->sMtCnt,		        "%010d",iMtCnt);
	sprintf(pTemp->sH20Cnt,		        "%010d",iH20Cnt);
	sprintf(pTemp->sH20Fee,		        "%010d",iH20Fee);

}



void GetCxDown(struct SmsTicketStruct *pi,struct CxTicketDownStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct CxTicketDownStruct));

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sSpServiceType,	pi->sSpProvCode,2);

		if(GetCityCode(pi->sHomeAreaCode,po->sCityCode)==NOTFOUND){
			strcpy(po->sCityCode,"380");
		}
		if(IS_UNICOMCDMA(pi->sMsisdn))
			strcpy(po->sReserv3,"C");
		else
			strcpy(po->sReserv3,"G");
		
}
void GetMxYssjChk(struct MxTicketUpStruct *pi,struct YssjChkStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct YssjChkStruct));

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpServiceType,	pi->sSpServiceType,2);
		strcpy(po->sCityCode,	pi->sVisitCityCode);
	
}

void GetTpYssjChk(struct TpTicketUpStruct *pi,struct YssjChkStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct YssjChkStruct));

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpServiceType,	pi->sSpServiceType,2);
		strcpy(po->sCityCode,	pi->sVisitCityCode);
	
}
int ChkSpCode(char sSpCode[],char sSpAccNbr[],char sSpServiceCode[])
{
	char sTemp[64],sSpType[20],sHostTime[15];
	
	if(strncmp(sSpCode,"X",1)==0)return -1;

/*10176特殊处理,需要查找上传参数配置表*/
	if(strncmp(sSpAccNbr,"10176",5)==0){
		
		strcpy(sTemp,sSpCode);
		strcpy(sTemp+5,sSpAccNbr);
		
		GetHostTime(sHostTime);
		
		GetTrieStr("SP_10176_UP",0,sTemp,
			sHostTime,sSpType);

		if(strcmp(sSpType,"10176")!=0)return -1;
	}
	
	return 0;
}
void SetHomeAreaCode(char sHomeAreaCodeIn[],char sHomeAreaCodeOut[])
{
	strncpy(sHomeAreaCodeOut,sHomeAreaCodeIn,3);
	sHomeAreaCodeOut[3]=0;

}
void SetSpAccNbr(struct SmsTicketStruct *pi)
{
	char sSpAccNbr[13];
	
	if(strcmp(pi->sSpCode,"10008")==0&&
		strcmp(pi->sSpServiceCode,"9500")==0){
		 strcpy(sSpAccNbr,pi->sSpServiceCode);
		 strcpy(pi->sSpServiceCode,pi->sSpAccNbr);
		 strcpy(pi->sSpAccNbr,sSpAccNbr);
			
	}
}

void mvitem_mfrxticketup(struct RxTicketUpStruct *pi,struct FRxTicketUpStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FRxTicketUpStruct));

		strncpy(po->sTicketSeq,pi->sTicketSeq,strlen(pi->sTicketSeq));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sTicketType,pi->sTicketType,strlen(pi->sTicketType));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sVisitCityCode,pi->sVisitCityCode,strlen(pi->sVisitCityCode));
		strncpy(po->sInfoFee,pi->sInfoFee,strlen(pi->sInfoFee));
		strncpy(po->sRecvTime,pi->sRecvTime,strlen(pi->sRecvTime));
		strncpy(po->sDoneTime,pi->sDoneTime,strlen(pi->sDoneTime));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));
		strncpy(po->sRxReason,pi->sRxReason,strlen(pi->sRxReason));

}

void mvitem_mfrxticketuphead(struct RxTicketUpHeadStruct *pi,struct FRxTicketUpHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FRxTicketUpHeadStruct));

		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVersion,pi->sFileVersion,strlen(pi->sFileVersion));
		strncpy(po->sFileCreatDate,pi->sFileCreatDate,strlen(pi->sFileCreatDate));
		strncpy(po->sProvCode,pi->sProvCode,strlen(pi->sProvCode));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sTotalRxCnt,pi->sTotalRxCnt,strlen(pi->sTotalRxCnt));
		strncpy(po->sTotalRxFee,pi->sTotalRxFee,strlen(pi->sTotalRxFee));
		strncpy(po->sReserv,pi->sReserv,strlen(pi->sReserv));

}

int data_search_bintree_spsj_e(void *pValue,void*pData)
{
	struct SjTicketUpStruct *pSource=(struct SjTicketUpStruct *)pValue;
	struct SjTicketUpStruct *pTarget=(struct SjTicketUpStruct *)pData;
	int res;

	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) return res;
	if((res=strcmp(pSource->sCityCode,pTarget->sCityCode))!=0) return res;
/*sReserv6,用于区分G&C的统计记录*/
	if((res=strcmp(pSource->sReserv6,pTarget->sReserv6))!=0) return res;



	return 0;
}

void assign_insert_bintree_spsj_e(void **ppData,void *pData)
{
	int iSjHdCnt=0,iSjFee=0,iTpFee=0,iRenegeFee=0,iAdjustFee=0;

	struct SjTicketUpStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SjTicketUpStruct));
		ERROR_EXIT(pTemp==NULL,"分配SjTicketUpStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SjTicketUpStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	iSjHdCnt=atoi(pTemp->sSjHdCnt)+
		atoi(((struct SjTicketUpStruct*)pData)->sSjHdCnt);
	iSjFee=atoi(pTemp->sSjFee)+
		atoi(((struct SjTicketUpStruct*)pData)->sSjFee);
	iTpFee=atoi(pTemp->sTpFee)+
		atoi(((struct SjTicketUpStruct*)pData)->sTpFee);
	iRenegeFee=atoi(pTemp->sRenegeFee)+
		atoi(((struct SjTicketUpStruct*)pData)->sRenegeFee);
	iAdjustFee=atoi(pTemp->sAdjustFee)+
		atoi(((struct SjTicketUpStruct*)pData)->sAdjustFee);

	sprintf(pTemp->sSjHdCnt,		"%010d",iSjHdCnt);
	sprintf(pTemp->sSjFee,		        "%015d",iSjFee);
	sprintf(pTemp->sTpFee,		        "%010d",iTpFee);
	sprintf(pTemp->sRenegeFee,		"%010d",iRenegeFee);
	sprintf(pTemp->sAdjustFee,		"%010d",iAdjustFee);

}

void mvitem_mfsjticketup(struct SjTicketUpStruct *pi,struct FSjTicketUpStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FSjTicketUpStruct));

		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sSpServiceType,pi->sSpServiceType,strlen(pi->sSpServiceType));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));
		strncpy(po->sReserv2,pi->sReserv2,strlen(pi->sReserv2));
		strncpy(po->sSjHdCnt,pi->sSjHdCnt,strlen(pi->sSjHdCnt));
		strncpy(po->sSjFee,pi->sSjFee,strlen(pi->sSjFee));
		strncpy(po->sTpFee,pi->sTpFee,strlen(pi->sTpFee));
		strncpy(po->sRenegeFee,pi->sRenegeFee,strlen(pi->sRenegeFee));
		strncpy(po->sAdjustFee,pi->sAdjustFee,strlen(pi->sAdjustFee));
		strncpy(po->sReserv5,pi->sReserv5,strlen(pi->sReserv5));
		strncpy(po->sReserv6,pi->sReserv6,strlen(pi->sReserv6));

}

void mvitem_mfsjticketuphead(struct SjTicketUpHeadStruct *pi,struct FSjTicketUpHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSjTicketUpHeadStruct));

		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVersion,pi->sFileVersion,strlen(pi->sFileVersion));
		strncpy(po->sFileCreatDate,pi->sFileCreatDate,strlen(pi->sFileCreatDate));
		strncpy(po->sProvCode,pi->sProvCode,strlen(pi->sProvCode));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sTotalCnt,pi->sTotalCnt,strlen(pi->sTotalCnt));
		strncpy(po->sTotalHdCnt,pi->sTotalHdCnt,strlen(pi->sTotalHdCnt));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sTotalTpFee,pi->sTotalTpFee,strlen(pi->sTotalTpFee));
		strncpy(po->sTotalRenegeFee,pi->sTotalRenegeFee,strlen(pi->sTotalRenegeFee));
		strncpy(po->sTotalAdjustFee,pi->sTotalAdjustFee,strlen(pi->sTotalAdjustFee));
		strncpy(po->sReserv3,pi->sReserv3,strlen(pi->sReserv3));
		strncpy(po->sReserv4,pi->sReserv4,strlen(pi->sReserv4));

}

int data_search_bintree_yssjchk_e(void *pValue,void*pData)
{               	
	struct YssjChkStruct *pSource=(struct YssjChkStruct *)pValue;
	struct YssjChkStruct *pTarget=(struct YssjChkStruct *)pData;
	int res=0;
	
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) 
		return res;	
	if((res=strcmp(pSource->sCityCode,pTarget->sCityCode))!=0) 
		return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) 
		return res;

	return res;
}
void assign_insert_bintree_yssjchk_e(void **ppData,void *pData)
{
	int iYsFee=0,iSjFee=0,iTpFee=0,iRenegeFee=0,iAdjustFee=0;
	
	struct YssjChkStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct YssjChkStruct));
		ERROR_EXIT(pTemp==NULL,"分配YssjChkStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct YssjChkStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	
	iYsFee=atoi(pTemp->sYsFee)+
		atoi(((struct YssjChkStruct*)pData)->sYsFee);
	iSjFee=atoi(pTemp->sSjFee)+
		atoi(((struct YssjChkStruct*)pData)->sSjFee);
	iTpFee=atoi(pTemp->sTpFee)+
		atoi(((struct YssjChkStruct*)pData)->sTpFee);
	iRenegeFee=atoi(pTemp->sRenegeFee)+
		atoi(((struct YssjChkStruct*)pData)->sRenegeFee);
	iAdjustFee=atoi(pTemp->sAdjustFee)+
		atoi(((struct YssjChkStruct*)pData)->sAdjustFee);
	
	sprintf(pTemp->sYsFee,	"%d",iYsFee);
	sprintf(pTemp->sSjFee,	"%d",iSjFee);
	sprintf(pTemp->sTpFee,	"%d",iTpFee);
	sprintf(pTemp->sRenegeFee,	"%d",iRenegeFee);
	sprintf(pTemp->sAdjustFee,	"%d",iAdjustFee);

}

int data_search_bintree_yssjchk_s_e(void *pValue,void*pData)
{
	struct YssjChkStruct *pSource=(struct YssjChkStruct *)pValue;
	struct YssjChkStruct *pTarget=(struct YssjChkStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) return res;
	if((res=strcmp(pSource->sCityCode,pTarget->sCityCode))!=0) return res;

	return 0;
}

void mvitem_mfmxticketup(struct MxTicketUpStruct *pi,struct FMxTicketUpStruct *po)
{/*内存数据移动到文件记录到部分*/

	char sMxFee[7];
	memset((void*)po,' ',sizeof(struct FMxTicketUpStruct));

		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sVisitCityCode,pi->sVisitCityCode,strlen(pi->sVisitCityCode));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpServiceType,pi->sSpServiceType,strlen(pi->sSpServiceType));
		
		sprintf(sMxFee,		"%06d",atoi(pi->sMxFee));
		strncpy(po->sMxFee,sMxFee,strlen(sMxFee));
		
		strncpy(po->sMxType,pi->sMxType,strlen(pi->sMxType));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));
		strncpy(po->sReserv2,pi->sReserv2,strlen(pi->sReserv2));
		strncpy(po->sReserv3,pi->sReserv3,strlen(pi->sReserv3));
		strncpy(po->sReserv4,pi->sReserv4,strlen(pi->sReserv4));

}

void mvitem_mfmxticketuphead(struct MxTicketUpHeadStruct *pi,struct FMxTicketUpHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FMxTicketUpHeadStruct));

		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVersion,pi->sFileVersion,strlen(pi->sFileVersion));
		strncpy(po->sFileCreatDate,pi->sFileCreatDate,strlen(pi->sFileCreatDate));
		strncpy(po->sProvCode,pi->sProvCode,strlen(pi->sProvCode));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sTotalCnt,pi->sTotalCnt,strlen(pi->sTotalCnt));
		strncpy(po->sMxFee,pi->sMxFee,strlen(pi->sMxFee));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));
		strncpy(po->sReserv2,pi->sReserv2,strlen(pi->sReserv2));

}



void mvitem_mftpticketup(struct TpTicketUpStruct *pi,struct FTpTicketUpStruct *po)
{/*内存数据移动到文件记录到部分*/

	char sTpFee[7];
	memset((void*)po,' ',sizeof(struct FTpTicketUpStruct));

		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sVisitCityCode,pi->sVisitCityCode,strlen(pi->sVisitCityCode));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpServiceType,pi->sSpServiceType,strlen(pi->sSpServiceType));

		sprintf(sTpFee,		"%06d",atoi(pi->sTpFee));
		strncpy(po->sTpFee,sTpFee,strlen(sTpFee));
			
		strncpy(po->sTpReason,pi->sTpReason,strlen(pi->sTpReason));
		strncpy(po->sTpTime,pi->sTpTime,strlen(pi->sTpTime));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));
		strncpy(po->sReserv2,pi->sReserv2,strlen(pi->sReserv2));
		strncpy(po->sReserv3,pi->sReserv3,strlen(pi->sReserv3));

}

void mvitem_mftpticketuphead(struct TpTicketUpHeadStruct *pi,
	struct FTpTicketUpHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FTpTicketUpHeadStruct));

		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVersion,pi->sFileVersion,strlen(pi->sFileVersion));
		strncpy(po->sFileCreatDate,pi->sFileCreatDate,strlen(pi->sFileCreatDate));
		strncpy(po->sProvCode,pi->sProvCode,strlen(pi->sProvCode));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sTotalCnt,pi->sTotalCnt,strlen(pi->sTotalCnt));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));

}

