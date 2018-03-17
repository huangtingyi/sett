#include <hnixs.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>

#include "md5.h"
#include "updata_ticket.h"

void mvitem_fmcdmaticket(struct FCdmaTicketStruct *pi,struct CdmaTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct CdmaTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,11);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sEsn,		pi->sEsn,11);
		strncpy(po->sOtherParty,	pi->sOtherParty,21);
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sThirdParty,	pi->sThirdParty,21);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sOtherLac,		pi->sOtherLac,5);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,5);
		strncpy(po->sAppendServiceCode,	pi->sAppendServiceCode,2);
		strncpy(po->sEndReason,		pi->sEndReason,1);
		strncpy(po->sDeformityFlag,	pi->sDeformityFlag,1);
		strncpy(po->sRoamFee,		pi->sRoamFee,8);
		strncpy(po->sRoamDuration,	pi->sRoamDuration,6);
		strncpy(po->sRoamRateType,	pi->sRoamRateType,1);
		strncpy(po->sTollFee,		pi->sTollFee,8);
		strncpy(po->sTollDuration,	pi->sTollDuration,6);
		strncpy(po->sTollFeeType,	pi->sTollFeeType,1);
		strncpy(po->sInfoFee,		pi->sInfoFee,8);
		strncpy(po->sOtherFee,		pi->sOtherFee,8);
		strncpy(po->sOppCityCode,	pi->sOppCityCode,3);
		strncpy(po->sOppProvCode,	pi->sOppProvCode,3);
		strncpy(po->sOppCountryCode,	pi->sOppCountryCode,3);
		strncpy(po->sTollType,		pi->sTollType,1);
		strncpy(po->sTollNetType,	pi->sTollNetType,1);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sActCode,		pi->sActCode,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);

		AllTrim(po->sRecordType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sImsi);
		AllTrim(po->sEsn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sThirdParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sAppendServiceCode);
		AllTrim(po->sEndReason);
		AllTrim(po->sDeformityFlag);
		AllTrim(po->sRoamFee);
		AllTrim(po->sRoamDuration);
		AllTrim(po->sRoamRateType);
		AllTrim(po->sTollFee);
		AllTrim(po->sTollDuration);
		AllTrim(po->sTollFeeType);
		AllTrim(po->sInfoFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sOppCityCode);
		AllTrim(po->sOppProvCode);
		AllTrim(po->sOppCountryCode);
		AllTrim(po->sTollType);
		AllTrim(po->sTollNetType);
		AllTrim(po->sRoamType);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sUserType);
		AllTrim(po->sActCode);
		AllTrim(po->sServiceCode);
}
void mvitem_fmcdmahead(struct FCdmaheadStruct *pi,struct CdmaheadStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct CdmaheadStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sCityCode,		pi->sCityCode,3);
		strncpy(po->sFileTag,		pi->sFileTag,4);
		strncpy(po->sFileSeq,		pi->sFileSeq,4);
		strncpy(po->sFileVer,		pi->sFileVer,2);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,8);
		strncpy(po->sFirstCallDate,	pi->sFirstCallDate,8);
		strncpy(po->sFirstCallTime,	pi->sFirstCallTime,6);
		strncpy(po->sEndCallDate,	pi->sEndCallDate,8);
		strncpy(po->sEndCallTime,	pi->sEndCallTime,6);

		strncpy(sTemp,	pi->sAllRecords,6);sTemp[6]=0;
		po->iAllRecords=atoi(sTemp);

		strncpy(po->sAllDurations,	pi->sAllDurations,15);
		strncpy(po->sNoused,		pi->sNoused,105);
		strncpy(po->sBackSpace,		pi->sBackSpace,1);

		AllTrim(po->sRecordType);
		AllTrim(po->sCityCode);
		AllTrim(po->sFileTag);
		AllTrim(po->sFileSeq);
		AllTrim(po->sFileVer);
		AllTrim(po->sCreatedDate);
		AllTrim(po->sFirstCallDate);
		AllTrim(po->sFirstCallTime);
		AllTrim(po->sEndCallDate);
		AllTrim(po->sEndCallTime);
		AllTrim(po->sAllDurations);
		AllTrim(po->sNoused);
		AllTrim(po->sBackSpace);
}
void mvitem_mfcdmahead(struct CdmaheadStruct *pi,struct FCdmaheadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FCdmaheadStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sFileTag,pi->sFileTag,strlen(pi->sFileTag));
		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVer,pi->sFileVer,strlen(pi->sFileVer));
		strncpy(po->sCreatedDate,pi->sCreatedDate,strlen(pi->sCreatedDate));
		strncpy(po->sFirstCallDate,pi->sFirstCallDate,strlen(pi->sFirstCallDate));
		strncpy(po->sFirstCallTime,pi->sFirstCallTime,strlen(pi->sFirstCallTime));
		strncpy(po->sEndCallDate,pi->sEndCallDate,strlen(pi->sEndCallDate));
		strncpy(po->sEndCallTime,pi->sEndCallTime,strlen(pi->sEndCallTime));

		sprintf(sTemp,"%06d",pi->iAllRecords);
		strncpy(po->sAllRecords,sTemp,6);

		strncpy(po->sAllDurations,pi->sAllDurations,strlen(pi->sAllDurations));
		strncpy(po->sNoused,pi->sNoused,strlen(pi->sNoused));
		strncpy(po->sBackSpace,pi->sBackSpace,strlen(pi->sBackSpace));

}

/**对表CDMAHEAD的链表释放函数**/
void DestroyCdmahead(struct CdmaheadStruct *ptHead)
{
	struct CdmaheadStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}


void mvitem_fmcdma1xhead(struct FCdma1xheadStruct *pi,struct Cdma1xheadStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct Cdma1xheadStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sFileSeq,		pi->sFileSeq,4);
		strncpy(po->sFileVer,		pi->sFileVer,2);
		strncpy(po->sAaaSyscode,	pi->sAaaSyscode,3);
		strncpy(po->sCityCode,		pi->sCityCode,3);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,8);
		strncpy(po->sFirstCallDate,	pi->sFirstCallDate,8);
		strncpy(po->sFirstCallTime,	pi->sFirstCallTime,6);
		strncpy(po->sEndCallDate,	pi->sEndCallDate,8);
		strncpy(po->sEndCallTime,	pi->sEndCallTime,6);
		strncpy(po->sAllRecords,	pi->sAllRecords,10);
		strncpy(po->sAllDurations,	pi->sAllDurations,10);
		strncpy(po->sNoused,		pi->sNoused,418);
/*		strncpy(po->sSbackspace1,	pi->sSbackspace1,1);*/

		AllTrim(po->sRecordType);
		AllTrim(po->sFileSeq);
		AllTrim(po->sFileVer);
		AllTrim(po->sAaaSyscode);
		AllTrim(po->sCityCode);
		AllTrim(po->sCreatedDate);
		AllTrim(po->sFirstCallDate);
		AllTrim(po->sFirstCallTime);
		AllTrim(po->sEndCallDate);
		AllTrim(po->sEndCallTime);
		AllTrim(po->sAllRecords);
		AllTrim(po->sAllDurations);
		AllTrim(po->sNoused);
		/*AllTrim(po->sSbackspace1);*/
}
void mvitem_mfcdma1xhead(struct Cdma1xheadStruct *pi,struct FCdma1xheadStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FCdma1xheadStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVer,pi->sFileVer,strlen(pi->sFileVer));
		strncpy(po->sAaaSyscode,pi->sAaaSyscode,strlen(pi->sAaaSyscode));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sCreatedDate,pi->sCreatedDate,strlen(pi->sCreatedDate));
		strncpy(po->sFirstCallDate,pi->sFirstCallDate,strlen(pi->sFirstCallDate));
		strncpy(po->sFirstCallTime,pi->sFirstCallTime,strlen(pi->sFirstCallTime));
		strncpy(po->sEndCallDate,pi->sEndCallDate,strlen(pi->sEndCallDate));
		strncpy(po->sEndCallTime,pi->sEndCallTime,strlen(pi->sEndCallTime));
		strncpy(po->sAllRecords,pi->sAllRecords,strlen(pi->sAllRecords));
		strncpy(po->sAllDurations,pi->sAllDurations,strlen(pi->sAllDurations));
		strncpy(po->sNoused,pi->sNoused,strlen(pi->sNoused));
/*		strncpy(po->sSbackspace1,pi->sSbackspace1,strlen(pi->sSbackspace1));*/

}
/**对表CDMA1XHEAD的链表释放函数**/
void DestroyCdma1xhead(struct Cdma1xheadStruct *ptHead)
{
	struct Cdma1xheadStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

void mvitem_fmcriticket(struct FCriTicketStruct *pi,struct CriTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct CriTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sLinkRef,		pi->sLinkRef,6);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sModifyTag,		pi->sModifyTag,1);
		strncpy(po->sNbrType,		pi->sNbrType,1);
		strncpy(po->sNbrPlan,		pi->sNbrPlan,1);
		strncpy(po->sOtherParty,	pi->sOtherParty,15);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sDupServiceType,	pi->sDupServiceType,1);
		strncpy(po->sDupServiceCode,	pi->sDupServiceCode,2);
		strncpy(po->sAckChannel,	pi->sAckChannel,1);
		strncpy(po->sUseChannel,	pi->sUseChannel,1);
		strncpy(po->sTransparentFlag,	pi->sTransparentFlag,1);
		strncpy(po->sAct1,		pi->sAct1,1);
		strncpy(po->sCode1,		pi->sCode1,2);
		strncpy(po->sAct2,		pi->sAct2,1);
		strncpy(po->sCode2,		pi->sCode2,2);
		strncpy(po->sAct3,		pi->sAct3,1);
		strncpy(po->sCode3,		pi->sCode3,2);
		strncpy(po->sAct4,		pi->sAct4,1);
		strncpy(po->sCode4,		pi->sCode4,2);
		strncpy(po->sAct5,		pi->sAct5,1);
		strncpy(po->sCode5,		pi->sCode5,2);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sFlowRef,		pi->sFlowRef,6);
		strncpy(po->sTollCode,		pi->sTollCode,1);
		strncpy(po->sOtherCode,		pi->sOtherCode,2);
		strncpy(po->sRoamFee,		pi->sRoamFee,9);
		strncpy(po->sTollFee,		pi->sTollFee,6);
		strncpy(po->sOtherFee,		pi->sOtherFee,6);
		strncpy(po->sPayItem,		pi->sPayItem,1);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sModifyTag);
		AllTrim(po->sNbrType);
		AllTrim(po->sNbrPlan);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sDupServiceType);
		AllTrim(po->sDupServiceCode);
		AllTrim(po->sAckChannel);
		AllTrim(po->sUseChannel);
		AllTrim(po->sTransparentFlag);
		AllTrim(po->sAct1);
		AllTrim(po->sCode1);
		AllTrim(po->sAct2);
		AllTrim(po->sCode2);
		AllTrim(po->sAct3);
		AllTrim(po->sCode3);
		AllTrim(po->sAct4);
		AllTrim(po->sCode4);
		AllTrim(po->sAct5);
		AllTrim(po->sCode5);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sFlowRef);
		AllTrim(po->sTollCode);
		AllTrim(po->sOtherCode);
		AllTrim(po->sRoamFee);
		AllTrim(po->sTollFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sPayItem);
}
void mvitem_mfcriticket(struct CriTicketStruct *pi,struct FCriTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FCriTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCode,pi->sOutCityCode,strlen(pi->sOutCityCode));
		strncpy(po->sLinkRef,pi->sLinkRef,strlen(pi->sLinkRef));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sModifyTag,pi->sModifyTag,strlen(pi->sModifyTag));
		strncpy(po->sNbrType,pi->sNbrType,strlen(pi->sNbrType));
		strncpy(po->sNbrPlan,pi->sNbrPlan,strlen(pi->sNbrPlan));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sDupServiceType,pi->sDupServiceType,strlen(pi->sDupServiceType));
		strncpy(po->sDupServiceCode,pi->sDupServiceCode,strlen(pi->sDupServiceCode));
		strncpy(po->sAckChannel,pi->sAckChannel,strlen(pi->sAckChannel));
		strncpy(po->sUseChannel,pi->sUseChannel,strlen(pi->sUseChannel));
		strncpy(po->sTransparentFlag,pi->sTransparentFlag,strlen(pi->sTransparentFlag));
		strncpy(po->sAct1,pi->sAct1,strlen(pi->sAct1));
		strncpy(po->sCode1,pi->sCode1,strlen(pi->sCode1));
		strncpy(po->sAct2,pi->sAct2,strlen(pi->sAct2));
		strncpy(po->sCode2,pi->sCode2,strlen(pi->sCode2));
		strncpy(po->sAct3,pi->sAct3,strlen(pi->sAct3));
		strncpy(po->sCode3,pi->sCode3,strlen(pi->sCode3));
		strncpy(po->sAct4,pi->sAct4,strlen(pi->sAct4));
		strncpy(po->sCode4,pi->sCode4,strlen(pi->sCode4));
		strncpy(po->sAct5,pi->sAct5,strlen(pi->sAct5));
		strncpy(po->sCode5,pi->sCode5,strlen(pi->sCode5));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sServType,pi->sServType,strlen(pi->sServType));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sPayUnit,pi->sPayUnit,strlen(pi->sPayUnit));
		strncpy(po->sFlowRef,pi->sFlowRef,strlen(pi->sFlowRef));
		strncpy(po->sTollCode,pi->sTollCode,strlen(pi->sTollCode));
		strncpy(po->sOtherCode,pi->sOtherCode,strlen(pi->sOtherCode));
		strncpy(po->sRoamFee,pi->sRoamFee,strlen(pi->sRoamFee));
		strncpy(po->sTollFee,pi->sTollFee,strlen(pi->sTollFee));
		strncpy(po->sOtherFee,pi->sOtherFee,strlen(pi->sOtherFee));
		strncpy(po->sPayItem,pi->sPayItem,strlen(pi->sPayItem));

}
/**对表CRI_TICKET的链表释放函数**/
void DestroyCriTicket(struct CriTicketStruct *ptHead)
{
	struct CriTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

void mvitem_fmciiticket(struct FCiiTicketStruct *pi,struct CiiTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct CiiTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sLinkRef,		pi->sLinkRef,6);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sModifyTag,		pi->sModifyTag,1);
		strncpy(po->sNbrType,		pi->sNbrType,1);
		strncpy(po->sNbrPlan,		pi->sNbrPlan,1);
		strncpy(po->sOtherParty,	pi->sOtherParty,15);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sDupServiceType,	pi->sDupServiceType,1);
		strncpy(po->sDupServiceCode,	pi->sDupServiceCode,2);
		strncpy(po->sAckChannel,	pi->sAckChannel,1);
		strncpy(po->sUseChannel,	pi->sUseChannel,1);
		strncpy(po->sTransparentFlag,	pi->sTransparentFlag,1);
		strncpy(po->sAct1,		pi->sAct1,1);
		strncpy(po->sCode1,		pi->sCode1,2);
		strncpy(po->sAct2,		pi->sAct2,1);
		strncpy(po->sCode2,		pi->sCode2,2);
		strncpy(po->sAct3,		pi->sAct3,1);
		strncpy(po->sCode3,		pi->sCode3,2);
		strncpy(po->sAct4,		pi->sAct4,1);
		strncpy(po->sCode4,		pi->sCode4,2);
		strncpy(po->sAct5,		pi->sAct5,1);
		strncpy(po->sCode5,		pi->sCode5,2);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sFlowRef,		pi->sFlowRef,6);
		strncpy(po->sFee,		pi->sFee,9);
		strncpy(po->sPayItem,		pi->sPayItem,1);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sModifyTag);
		AllTrim(po->sNbrType);
		AllTrim(po->sNbrPlan);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sDupServiceType);
		AllTrim(po->sDupServiceCode);
		AllTrim(po->sAckChannel);
		AllTrim(po->sUseChannel);
		AllTrim(po->sTransparentFlag);
		AllTrim(po->sAct1);
		AllTrim(po->sCode1);
		AllTrim(po->sAct2);
		AllTrim(po->sCode2);
		AllTrim(po->sAct3);
		AllTrim(po->sCode3);
		AllTrim(po->sAct4);
		AllTrim(po->sCode4);
		AllTrim(po->sAct5);
		AllTrim(po->sCode5);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sFlowRef);
		AllTrim(po->sFee);
		AllTrim(po->sPayItem);
}
void mvitem_mfciiticket(struct CiiTicketStruct *pi,struct FCiiTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FCiiTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCode,pi->sOutCityCode,strlen(pi->sOutCityCode));
		strncpy(po->sLinkRef,pi->sLinkRef,strlen(pi->sLinkRef));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sModifyTag,pi->sModifyTag,strlen(pi->sModifyTag));
		strncpy(po->sNbrType,pi->sNbrType,strlen(pi->sNbrType));
		strncpy(po->sNbrPlan,pi->sNbrPlan,strlen(pi->sNbrPlan));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sDupServiceType,pi->sDupServiceType,strlen(pi->sDupServiceType));
		strncpy(po->sDupServiceCode,pi->sDupServiceCode,strlen(pi->sDupServiceCode));
		strncpy(po->sAckChannel,pi->sAckChannel,strlen(pi->sAckChannel));
		strncpy(po->sUseChannel,pi->sUseChannel,strlen(pi->sUseChannel));
		strncpy(po->sTransparentFlag,pi->sTransparentFlag,strlen(pi->sTransparentFlag));
		strncpy(po->sAct1,pi->sAct1,strlen(pi->sAct1));
		strncpy(po->sCode1,pi->sCode1,strlen(pi->sCode1));
		strncpy(po->sAct2,pi->sAct2,strlen(pi->sAct2));
		strncpy(po->sCode2,pi->sCode2,strlen(pi->sCode2));
		strncpy(po->sAct3,pi->sAct3,strlen(pi->sAct3));
		strncpy(po->sCode3,pi->sCode3,strlen(pi->sCode3));
		strncpy(po->sAct4,pi->sAct4,strlen(pi->sAct4));
		strncpy(po->sCode4,pi->sCode4,strlen(pi->sCode4));
		strncpy(po->sAct5,pi->sAct5,strlen(pi->sAct5));
		strncpy(po->sCode5,pi->sCode5,strlen(pi->sCode5));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sServType,pi->sServType,strlen(pi->sServType));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sPayUnit,pi->sPayUnit,strlen(pi->sPayUnit));
		strncpy(po->sFlowRef,pi->sFlowRef,strlen(pi->sFlowRef));
		strncpy(po->sFee,pi->sFee,strlen(pi->sFee));
		strncpy(po->sPayItem,pi->sPayItem,strlen(pi->sPayItem));

}
/**对表CII_TICKET的链表释放函数**/
void DestroyCiiTicket(struct CiiTicketStruct *ptHead)
{
	struct CiiTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

void mvitem_fmjriticket(struct FJriTicketStruct *pi,struct JriTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct JriTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sRetCode,		pi->sRetCode,1);
		strncpy(po->sErrCode,		pi->sErrCode,2);
		strncpy(po->sErrField,		pi->sErrField,3);
		strncpy(po->sMsidTag,		pi->sMsidTag,1);
		strncpy(po->sMsid,		pi->sMsid,15);
		strncpy(po->sMsisdnLen,		pi->sMsisdnLen,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sEsnTag,		pi->sEsnTag,1);
		strncpy(po->sEsn,		pi->sEsn,19);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
		strncpy(po->sTotalFee,		pi->sTotalFee,10);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sProvTex,		pi->sProvTex,10);
		strncpy(po->sReserve2,		pi->sReserve2,1);
		strncpy(po->sLocalTex,		pi->sLocalTex,10);
		strncpy(po->sReserve3,		pi->sReserve3,1);
		strncpy(po->sStartDate,		pi->sStartDate,6);
		strncpy(po->sDirection,		pi->sDirection,1);
		strncpy(po->sEndFlag,		pi->sEndFlag,1);
		strncpy(po->sStopFlag,		pi->sStopFlag,1);
		strncpy(po->sOtherPartyLen,	pi->sOtherPartyLen,2);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sMsrnLen,		pi->sMsrnLen,2);
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sReserve4,		pi->sReserve4,2);
		strncpy(po->sCellCode,		pi->sCellCode,11);
		strncpy(po->sMad,		pi->sMad,10);
		strncpy(po->sRoamStartTime,	pi->sRoamStartTime,6);
		strncpy(po->sRoamBillDuration,	pi->sRoamBillDuration,6);
		strncpy(po->sRoamDuration,	pi->sRoamDuration,6);
		strncpy(po->sRoamTimeSpan,	pi->sRoamTimeSpan,2);
		strncpy(po->sRoamTimeType,	pi->sRoamTimeType,1);
		strncpy(po->sRoamFee,		pi->sRoamFee,10);
		strncpy(po->sReserve5,		pi->sReserve5,1);
		strncpy(po->sOtherFeeTag,	pi->sOtherFeeTag,2);
		strncpy(po->sOtherFee,		pi->sOtherFee,10);
		strncpy(po->sReserve6,		pi->sReserve6,1);
		strncpy(po->sReserve7,		pi->sReserve7,13);
		strncpy(po->sSpecialService,	pi->sSpecialService,5);
		strncpy(po->sOppCityCode,	pi->sOppCityCode,10);
		strncpy(po->sOppProvCode,	pi->sOppProvCode,3);
		strncpy(po->sOppCountryCode,	pi->sOppCountryCode,3);
		strncpy(po->sTollStartTime,	pi->sTollStartTime,6);
		strncpy(po->sTollBillDuration,	pi->sTollBillDuration,6);
		strncpy(po->sTollDuration,	pi->sTollDuration,6);
		strncpy(po->sTollFeeDesc,	pi->sTollFeeDesc,2);
		strncpy(po->sTollTimeSpan,	pi->sTollTimeSpan,2);
		strncpy(po->sTollTimeType,	pi->sTollTimeType,1);
		strncpy(po->sTollFee,		pi->sTollFee,10);
		strncpy(po->sReserve8,		pi->sReserve8,1);
		strncpy(po->sTollProvTex,	pi->sTollProvTex,10);
		strncpy(po->sReserve9,		pi->sReserve9,1);
		strncpy(po->sTollLocalTex,	pi->sTollLocalTex,10);
		strncpy(po->sReserve10,		pi->sReserve10,1);
		strncpy(po->sTollNetOperator,	pi->sTollNetOperator,5);

		AllTrim(po->sRecordType);
		AllTrim(po->sRetCode);
		AllTrim(po->sErrCode);
		AllTrim(po->sErrField);
		AllTrim(po->sMsidTag);
		AllTrim(po->sMsid);
		AllTrim(po->sMsisdnLen);
		AllTrim(po->sMsisdn);
		AllTrim(po->sEsnTag);
		AllTrim(po->sEsn);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sTotalFee);
		AllTrim(po->sReserve1);
		AllTrim(po->sProvTex);
		AllTrim(po->sReserve2);
		AllTrim(po->sLocalTex);
		AllTrim(po->sReserve3);
		AllTrim(po->sStartDate);
		AllTrim(po->sDirection);
		AllTrim(po->sEndFlag);
		AllTrim(po->sStopFlag);
		AllTrim(po->sOtherPartyLen);
		AllTrim(po->sOtherParty);
		AllTrim(po->sMsrnLen);
		AllTrim(po->sMsrn);
		AllTrim(po->sReserve4);
		AllTrim(po->sCellCode);
		AllTrim(po->sMad);
		AllTrim(po->sRoamStartTime);
		AllTrim(po->sRoamBillDuration);
		AllTrim(po->sRoamDuration);
		AllTrim(po->sRoamTimeSpan);
		AllTrim(po->sRoamTimeType);
		AllTrim(po->sRoamFee);
		AllTrim(po->sReserve5);
		AllTrim(po->sOtherFeeTag);
		AllTrim(po->sOtherFee);
		AllTrim(po->sReserve6);
		AllTrim(po->sReserve7);
		AllTrim(po->sSpecialService);
		AllTrim(po->sOppCityCode);
		AllTrim(po->sOppProvCode);
		AllTrim(po->sOppCountryCode);
		AllTrim(po->sTollStartTime);
		AllTrim(po->sTollBillDuration);
		AllTrim(po->sTollDuration);
		AllTrim(po->sTollFeeDesc);
		AllTrim(po->sTollTimeSpan);
		AllTrim(po->sTollTimeType);
		AllTrim(po->sTollFee);
		AllTrim(po->sReserve8);
		AllTrim(po->sTollProvTex);
		AllTrim(po->sReserve9);
		AllTrim(po->sTollLocalTex);
		AllTrim(po->sReserve10);
		AllTrim(po->sTollNetOperator);
}
void mvitem_mfjriticket(struct JriTicketStruct *pi,struct FJriTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FJriTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sRetCode,pi->sRetCode,strlen(pi->sRetCode));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sErrField,pi->sErrField,strlen(pi->sErrField));
		strncpy(po->sMsidTag,pi->sMsidTag,strlen(pi->sMsidTag));
		strncpy(po->sMsid,pi->sMsid,strlen(pi->sMsid));
		strncpy(po->sMsisdnLen,pi->sMsisdnLen,strlen(pi->sMsisdnLen));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sEsnTag,pi->sEsnTag,strlen(pi->sEsnTag));
		strncpy(po->sEsn,pi->sEsn,strlen(pi->sEsn));
		strncpy(po->sVisitCityCode,pi->sVisitCityCode,strlen(pi->sVisitCityCode));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sProvTex,pi->sProvTex,strlen(pi->sProvTex));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));
		strncpy(po->sLocalTex,pi->sLocalTex,strlen(pi->sLocalTex));
		strncpy(po->sReserve3,pi->sReserve3,strlen(pi->sReserve3));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sDirection,pi->sDirection,strlen(pi->sDirection));
		strncpy(po->sEndFlag,pi->sEndFlag,strlen(pi->sEndFlag));
		strncpy(po->sStopFlag,pi->sStopFlag,strlen(pi->sStopFlag));
		strncpy(po->sOtherPartyLen,pi->sOtherPartyLen,strlen(pi->sOtherPartyLen));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sMsrnLen,pi->sMsrnLen,strlen(pi->sMsrnLen));
		strncpy(po->sMsrn,pi->sMsrn,strlen(pi->sMsrn));
		strncpy(po->sReserve4,pi->sReserve4,strlen(pi->sReserve4));
		strncpy(po->sCellCode,pi->sCellCode,strlen(pi->sCellCode));
		strncpy(po->sMad,pi->sMad,strlen(pi->sMad));
		strncpy(po->sRoamStartTime,pi->sRoamStartTime,strlen(pi->sRoamStartTime));
		strncpy(po->sRoamBillDuration,pi->sRoamBillDuration,strlen(pi->sRoamBillDuration));
		strncpy(po->sRoamDuration,pi->sRoamDuration,strlen(pi->sRoamDuration));
		strncpy(po->sRoamTimeSpan,pi->sRoamTimeSpan,strlen(pi->sRoamTimeSpan));
		strncpy(po->sRoamTimeType,pi->sRoamTimeType,strlen(pi->sRoamTimeType));
		strncpy(po->sRoamFee,pi->sRoamFee,strlen(pi->sRoamFee));
		strncpy(po->sReserve5,pi->sReserve5,strlen(pi->sReserve5));
		strncpy(po->sOtherFeeTag,pi->sOtherFeeTag,strlen(pi->sOtherFeeTag));
		strncpy(po->sOtherFee,pi->sOtherFee,strlen(pi->sOtherFee));
		strncpy(po->sReserve6,pi->sReserve6,strlen(pi->sReserve6));
		strncpy(po->sReserve7,pi->sReserve7,strlen(pi->sReserve7));
		strncpy(po->sSpecialService,pi->sSpecialService,strlen(pi->sSpecialService));
		strncpy(po->sOppCityCode,pi->sOppCityCode,strlen(pi->sOppCityCode));
		strncpy(po->sOppProvCode,pi->sOppProvCode,strlen(pi->sOppProvCode));
		strncpy(po->sOppCountryCode,pi->sOppCountryCode,strlen(pi->sOppCountryCode));
		strncpy(po->sTollStartTime,pi->sTollStartTime,strlen(pi->sTollStartTime));
		strncpy(po->sTollBillDuration,pi->sTollBillDuration,strlen(pi->sTollBillDuration));
		strncpy(po->sTollDuration,pi->sTollDuration,strlen(pi->sTollDuration));
		strncpy(po->sTollFeeDesc,pi->sTollFeeDesc,strlen(pi->sTollFeeDesc));
		strncpy(po->sTollTimeSpan,pi->sTollTimeSpan,strlen(pi->sTollTimeSpan));
		strncpy(po->sTollTimeType,pi->sTollTimeType,strlen(pi->sTollTimeType));
		strncpy(po->sTollFee,pi->sTollFee,strlen(pi->sTollFee));
		strncpy(po->sReserve8,pi->sReserve8,strlen(pi->sReserve8));
		strncpy(po->sTollProvTex,pi->sTollProvTex,strlen(pi->sTollProvTex));
		strncpy(po->sReserve9,pi->sReserve9,strlen(pi->sReserve9));
		strncpy(po->sTollLocalTex,pi->sTollLocalTex,strlen(pi->sTollLocalTex));
		strncpy(po->sReserve10,pi->sReserve10,strlen(pi->sReserve10));
		strncpy(po->sTollNetOperator,pi->sTollNetOperator,strlen(pi->sTollNetOperator));

}
/**对表JRI_TICKET的链表释放函数**/
void DestroyJriTicket(struct JriTicketStruct *ptHead)
{
	struct JriTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

void mvitem_fmjiiticket(struct FJiiTicketStruct *pi,struct JiiTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct JiiTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sRetCode,		pi->sRetCode,1);
		strncpy(po->sErrCode,		pi->sErrCode,2);
		strncpy(po->sErrField,		pi->sErrField,3);
		strncpy(po->sMsidTag,		pi->sMsidTag,1);
		strncpy(po->sMsid,		pi->sMsid,15);
		strncpy(po->sMsisdnLen,		pi->sMsisdnLen,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sEsnTag,		pi->sEsnTag,1);
		strncpy(po->sEsn,		pi->sEsn,19);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,5);
		strncpy(po->sTotalFee,		pi->sTotalFee,10);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sProvTex,		pi->sProvTex,10);
		strncpy(po->sReserve2,		pi->sReserve2,1);
		strncpy(po->sLocalTex,		pi->sLocalTex,10);
		strncpy(po->sReserve3,		pi->sReserve3,1);
		strncpy(po->sStartDate,		pi->sStartDate,6);
		strncpy(po->sDirection,		pi->sDirection,1);
		strncpy(po->sEndFlag,		pi->sEndFlag,1);
		strncpy(po->sStopFlag,		pi->sStopFlag,1);
		strncpy(po->sOtherPartyLen,	pi->sOtherPartyLen,2);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sMsrnLen,		pi->sMsrnLen,2);
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sReserve4,		pi->sReserve4,2);
		strncpy(po->sCellCode,		pi->sCellCode,11);
		strncpy(po->sTimeZone,		pi->sTimeZone,2);
		strncpy(po->sSummerTimeTag,	pi->sSummerTimeTag,1);
		strncpy(po->sMad,		pi->sMad,10);
		strncpy(po->sRoamStartTime,	pi->sRoamStartTime,6);
		strncpy(po->sRoamBillDuration,	pi->sRoamBillDuration,6);
		strncpy(po->sRoamDuration,	pi->sRoamDuration,6);
		strncpy(po->sRoamTimeSpan,	pi->sRoamTimeSpan,2);
		strncpy(po->sRoamTimeType,	pi->sRoamTimeType,1);
		strncpy(po->sRoamFee,		pi->sRoamFee,10);
		strncpy(po->sReserve5,		pi->sReserve5,1);
		strncpy(po->sOtherFeeTag,	pi->sOtherFeeTag,2);
		strncpy(po->sOtherFee,		pi->sOtherFee,10);
		strncpy(po->sReserve6,		pi->sReserve6,1);
		strncpy(po->sReserve7,		pi->sReserve7,13);
		strncpy(po->sOppDesc,		pi->sOppDesc,15);
		strncpy(po->sSpecialService,	pi->sSpecialService,5);
		strncpy(po->sOppCityCode,	pi->sOppCityCode,10);
		strncpy(po->sOppProvCode,	pi->sOppProvCode,3);
		strncpy(po->sOppCountryCode,	pi->sOppCountryCode,3);
		strncpy(po->sTollStartTime,	pi->sTollStartTime,6);
		strncpy(po->sTollBillDuration,	pi->sTollBillDuration,6);
		strncpy(po->sTollDuration,	pi->sTollDuration,6);
		strncpy(po->sTollFeeDesc,	pi->sTollFeeDesc,2);
		strncpy(po->sTollTimeSpan,	pi->sTollTimeSpan,2);
		strncpy(po->sTollTimeType,	pi->sTollTimeType,1);
		strncpy(po->sTollFee,		pi->sTollFee,10);
		strncpy(po->sReserve8,		pi->sReserve8,1);
		strncpy(po->sTollProvTex,	pi->sTollProvTex,10);
		strncpy(po->sReserve9,		pi->sReserve9,1);
		strncpy(po->sTollLocalTex,	pi->sTollLocalTex,10);

		AllTrim(po->sRecordType);
		AllTrim(po->sRetCode);
		AllTrim(po->sErrCode);
		AllTrim(po->sErrField);
		AllTrim(po->sMsidTag);
		AllTrim(po->sMsid);
		AllTrim(po->sMsisdnLen);
		AllTrim(po->sMsisdn);
		AllTrim(po->sEsnTag);
		AllTrim(po->sEsn);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sTotalFee);
		AllTrim(po->sReserve1);
		AllTrim(po->sProvTex);
		AllTrim(po->sReserve2);
		AllTrim(po->sLocalTex);
		AllTrim(po->sReserve3);
		AllTrim(po->sStartDate);
		AllTrim(po->sDirection);
		AllTrim(po->sEndFlag);
		AllTrim(po->sStopFlag);
		AllTrim(po->sOtherPartyLen);
		AllTrim(po->sOtherParty);
		AllTrim(po->sMsrnLen);
		AllTrim(po->sMsrn);
		AllTrim(po->sReserve4);
		AllTrim(po->sCellCode);
		AllTrim(po->sTimeZone);
		AllTrim(po->sSummerTimeTag);
		AllTrim(po->sMad);
		AllTrim(po->sRoamStartTime);
		AllTrim(po->sRoamBillDuration);
		AllTrim(po->sRoamDuration);
		AllTrim(po->sRoamTimeSpan);
		AllTrim(po->sRoamTimeType);
		AllTrim(po->sRoamFee);
		AllTrim(po->sReserve5);
		AllTrim(po->sOtherFeeTag);
		AllTrim(po->sOtherFee);
		AllTrim(po->sReserve6);
		AllTrim(po->sReserve7);
		AllTrim(po->sOppDesc);
		AllTrim(po->sSpecialService);
		AllTrim(po->sOppCityCode);
		AllTrim(po->sOppProvCode);
		AllTrim(po->sOppCountryCode);
		AllTrim(po->sTollStartTime);
		AllTrim(po->sTollBillDuration);
		AllTrim(po->sTollDuration);
		AllTrim(po->sTollFeeDesc);
		AllTrim(po->sTollTimeSpan);
		AllTrim(po->sTollTimeType);
		AllTrim(po->sTollFee);
		AllTrim(po->sReserve8);
		AllTrim(po->sTollProvTex);
		AllTrim(po->sReserve9);
		AllTrim(po->sTollLocalTex);
}
void mvitem_mfjiiticket(struct JiiTicketStruct *pi,struct FJiiTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FJiiTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sRetCode,pi->sRetCode,strlen(pi->sRetCode));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sErrField,pi->sErrField,strlen(pi->sErrField));
		strncpy(po->sMsidTag,pi->sMsidTag,strlen(pi->sMsidTag));
		strncpy(po->sMsid,pi->sMsid,strlen(pi->sMsid));
		strncpy(po->sMsisdnLen,pi->sMsisdnLen,strlen(pi->sMsisdnLen));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sEsnTag,pi->sEsnTag,strlen(pi->sEsnTag));
		strncpy(po->sEsn,pi->sEsn,strlen(pi->sEsn));
		strncpy(po->sVisitCityCode,pi->sVisitCityCode,strlen(pi->sVisitCityCode));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sProvTex,pi->sProvTex,strlen(pi->sProvTex));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));
		strncpy(po->sLocalTex,pi->sLocalTex,strlen(pi->sLocalTex));
		strncpy(po->sReserve3,pi->sReserve3,strlen(pi->sReserve3));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sDirection,pi->sDirection,strlen(pi->sDirection));
		strncpy(po->sEndFlag,pi->sEndFlag,strlen(pi->sEndFlag));
		strncpy(po->sStopFlag,pi->sStopFlag,strlen(pi->sStopFlag));
		strncpy(po->sOtherPartyLen,pi->sOtherPartyLen,strlen(pi->sOtherPartyLen));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sMsrnLen,pi->sMsrnLen,strlen(pi->sMsrnLen));
		strncpy(po->sMsrn,pi->sMsrn,strlen(pi->sMsrn));
		strncpy(po->sReserve4,pi->sReserve4,strlen(pi->sReserve4));
		strncpy(po->sCellCode,pi->sCellCode,strlen(pi->sCellCode));
		strncpy(po->sTimeZone,pi->sTimeZone,strlen(pi->sTimeZone));
		strncpy(po->sSummerTimeTag,pi->sSummerTimeTag,strlen(pi->sSummerTimeTag));
		strncpy(po->sMad,pi->sMad,strlen(pi->sMad));
		strncpy(po->sRoamStartTime,pi->sRoamStartTime,strlen(pi->sRoamStartTime));
		strncpy(po->sRoamBillDuration,pi->sRoamBillDuration,strlen(pi->sRoamBillDuration));
		strncpy(po->sRoamDuration,pi->sRoamDuration,strlen(pi->sRoamDuration));
		strncpy(po->sRoamTimeSpan,pi->sRoamTimeSpan,strlen(pi->sRoamTimeSpan));
		strncpy(po->sRoamTimeType,pi->sRoamTimeType,strlen(pi->sRoamTimeType));
		strncpy(po->sRoamFee,pi->sRoamFee,strlen(pi->sRoamFee));
		strncpy(po->sReserve5,pi->sReserve5,strlen(pi->sReserve5));
		strncpy(po->sOtherFeeTag,pi->sOtherFeeTag,strlen(pi->sOtherFeeTag));
		strncpy(po->sOtherFee,pi->sOtherFee,strlen(pi->sOtherFee));
		strncpy(po->sReserve6,pi->sReserve6,strlen(pi->sReserve6));
		strncpy(po->sReserve7,pi->sReserve7,strlen(pi->sReserve7));
		strncpy(po->sOppDesc,pi->sOppDesc,strlen(pi->sOppDesc));
		strncpy(po->sSpecialService,pi->sSpecialService,strlen(pi->sSpecialService));
		strncpy(po->sOppCityCode,pi->sOppCityCode,strlen(pi->sOppCityCode));
		strncpy(po->sOppProvCode,pi->sOppProvCode,strlen(pi->sOppProvCode));
		strncpy(po->sOppCountryCode,pi->sOppCountryCode,strlen(pi->sOppCountryCode));
		strncpy(po->sTollStartTime,pi->sTollStartTime,strlen(pi->sTollStartTime));
		strncpy(po->sTollBillDuration,pi->sTollBillDuration,strlen(pi->sTollBillDuration));
		strncpy(po->sTollDuration,pi->sTollDuration,strlen(pi->sTollDuration));
		strncpy(po->sTollFeeDesc,pi->sTollFeeDesc,strlen(pi->sTollFeeDesc));
		strncpy(po->sTollTimeSpan,pi->sTollTimeSpan,strlen(pi->sTollTimeSpan));
		strncpy(po->sTollTimeType,pi->sTollTimeType,strlen(pi->sTollTimeType));
		strncpy(po->sTollFee,pi->sTollFee,strlen(pi->sTollFee));
		strncpy(po->sReserve8,pi->sReserve8,strlen(pi->sReserve8));
		strncpy(po->sTollProvTex,pi->sTollProvTex,strlen(pi->sTollProvTex));
		strncpy(po->sReserve9,pi->sReserve9,strlen(pi->sReserve9));
		strncpy(po->sTollLocalTex,pi->sTollLocalTex,strlen(pi->sTollLocalTex));

}
/**对表JII_TICKET的链表释放函数**/
void DestroyJiiTicket(struct JiiTicketStruct *ptHead)
{
	struct JiiTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

void mvitem_fmtrsticket(struct FTrsTicketStruct *pi,struct TrsTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct TrsTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sLinkRef,		pi->sLinkRef,6);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,15);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sReserve2,		pi->sReserve2,9);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sReserve3,		pi->sReserve3,31);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sReserve2);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sReserve3);
}
void mvitem_mftrsticket(struct TrsTicketStruct *pi,struct FTrsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FTrsTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCode,pi->sOutCityCode,strlen(pi->sOutCityCode));
		strncpy(po->sLinkRef,pi->sLinkRef,strlen(pi->sLinkRef));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sThirdParty,pi->sThirdParty,strlen(pi->sThirdParty));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sServType,pi->sServType,strlen(pi->sServType));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sPayUnit,pi->sPayUnit,strlen(pi->sPayUnit));
		strncpy(po->sReserve3,pi->sReserve3,strlen(pi->sReserve3));

}
/**对表TRS_TICKET的链表释放函数**/
void DestroyTrsTicket(struct TrsTicketStruct *ptHead)
{
	struct TrsTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}


void mvitem_fmrhjfbody(struct FRhjfBodyStruct *pi,struct RhjfBodyStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct RhjfBodyStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,15);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,30);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sSwitchNbr,		pi->sSwitchNbr,15);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,7);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,7);
		strncpy(po->sBaseFee,		pi->sBaseFee,8);
		strncpy(po->sLongFee,		pi->sLongFee,8);
		strncpy(po->sOtherFee,		pi->sOtherFee,8);
		strncpy(po->sDistanceType,	pi->sDistanceType,1);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,5);
		strncpy(po->sBelongAreaCode,	pi->sBelongAreaCode,5);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,5);

		AllTrim(po->sCallType);
		AllTrim(po->sRecordType);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sSwitchNbr);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sBaseFee);
		AllTrim(po->sLongFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sDistanceType);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sBelongAreaCode);
		AllTrim(po->sCalledAreaCode);
}
void mvitem_mfrhjfbody(struct RhjfBodyStruct *pi,struct FRhjfBodyStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FRhjfBodyStruct));

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sSwitchNbr,pi->sSwitchNbr,strlen(pi->sSwitchNbr));
		strncpy(po->sTrunkIn,pi->sTrunkIn,strlen(pi->sTrunkIn));
		strncpy(po->sTrunkOut,pi->sTrunkOut,strlen(pi->sTrunkOut));
		strncpy(po->sBaseFee,pi->sBaseFee,strlen(pi->sBaseFee));
		strncpy(po->sLongFee,pi->sLongFee,strlen(pi->sLongFee));
		strncpy(po->sOtherFee,pi->sOtherFee,strlen(pi->sOtherFee));
		strncpy(po->sDistanceType,pi->sDistanceType,strlen(pi->sDistanceType));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sBelongAreaCode,pi->sBelongAreaCode,strlen(pi->sBelongAreaCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));

}

void mvitem_fmrhjfhead(struct FRhjfHeadStruct *pi,struct RhjfHeadStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct RhjfHeadStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sCityCode,		pi->sCityCode,5);
		strncpy(po->sFileFlag,		pi->sFileFlag,4);
		strncpy(po->sFileSeq,		pi->sFileSeq,4);
		strncpy(po->sFileVersion,	pi->sFileVersion,2);
		strncpy(po->sFileCreatDate,	pi->sFileCreatDate,8);
		strncpy(po->sFirstCallDate,	pi->sFirstCallDate,8);
		strncpy(po->sFirstCallTime,	pi->sFirstCallTime,6);
		strncpy(po->sLastCallDate,	pi->sLastCallDate,8);
		strncpy(po->sLastCallTime,	pi->sLastCallTime,6);
		strncpy(po->sCallSumNbr,	pi->sCallSumNbr,6);
		strncpy(po->sCallSumFee,	pi->sCallSumFee,15);
		strncpy(po->sNouse,		pi->sNouse,60);

		AllTrim(po->sRecordType);
		AllTrim(po->sCityCode);
		AllTrim(po->sFileFlag);
		AllTrim(po->sFileSeq);
		AllTrim(po->sFileVersion);
		AllTrim(po->sFileCreatDate);
		AllTrim(po->sFirstCallDate);
		AllTrim(po->sFirstCallTime);
		AllTrim(po->sLastCallDate);
		AllTrim(po->sLastCallTime);
		AllTrim(po->sCallSumNbr);
		AllTrim(po->sCallSumFee);
		AllTrim(po->sNouse);
}
void mvitem_mfrhjfhead(struct RhjfHeadStruct *pi,struct FRhjfHeadStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FRhjfHeadStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sFileFlag,pi->sFileFlag,strlen(pi->sFileFlag));
		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVersion,pi->sFileVersion,strlen(pi->sFileVersion));
		strncpy(po->sFileCreatDate,pi->sFileCreatDate,strlen(pi->sFileCreatDate));
		strncpy(po->sFirstCallDate,pi->sFirstCallDate,strlen(pi->sFirstCallDate));
		strncpy(po->sFirstCallTime,pi->sFirstCallTime,strlen(pi->sFirstCallTime));
		strncpy(po->sLastCallDate,pi->sLastCallDate,strlen(pi->sLastCallDate));
		strncpy(po->sLastCallTime,pi->sLastCallTime,strlen(pi->sLastCallTime));
		strncpy(po->sCallSumNbr,pi->sCallSumNbr,strlen(pi->sCallSumNbr));
		strncpy(po->sCallSumFee,pi->sCallSumFee,strlen(pi->sCallSumFee));
		strncpy(po->sNouse,pi->sNouse,strlen(pi->sNouse));

}

void mvitem_fmgsmhead(struct FGsmHeadStruct *pi,struct GsmHeadStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct GsmHeadStruct));

		strncpy(po->sRecordType,pi->sRecordType,2);
		strncpy(po->sCityCode,	pi->sCityCode,3);

		strncpy(sTemp,	pi->sFileSeq,8);sTemp[8]=0;
		po->iFileSeq=atoi(sTemp);

		strncpy(po->sFileVer,	pi->sFileVer,2);
		strncpy(po->sCreateDate,pi->sCreateDate,8);

		strncpy(sTemp,	pi->sRecordCnt,6);sTemp[6]=0;
		po->iRecordCnt=atoi(sTemp);

		AllTrim(po->sRecordType);
		AllTrim(po->sCityCode);
		AllTrim(po->sFileVer);
		AllTrim(po->sCreateDate);
}
void mvitem_mfgsmhead(struct GsmHeadStruct *pi,struct FGsmHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FGsmHeadStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));

		sprintf(sTemp,"%08d",pi->iFileSeq);
		strncpy(po->sFileSeq,sTemp,8);

		strncpy(po->sFileVer,pi->sFileVer,strlen(pi->sFileVer));
		strncpy(po->sCreateDate,pi->sCreateDate,strlen(pi->sCreateDate));

		sprintf(sTemp,"%06d",pi->iRecordCnt);
		strncpy(po->sRecordCnt,sTemp,6);

}

void mvitem_fmsmshead(struct FSmsHeadStruct *pi,struct SmsHeadStruct *po)
{/*数据文件移动到内存部分*/
	bzero((void*)po,sizeof(struct SmsHeadStruct));
		strncpy(po->sHeadTag,		pi->sHeadTag,2);
		strncpy(po->sFileSeq,		pi->sFileSeq,4);
		strncpy(po->sFileVer,		pi->sFileVer,2);
		strncpy(po->sCreateDate,	pi->sCreateDate,8);
		strncpy(po->sFirstCallDate,	pi->sFirstCallDate,14);
		strncpy(po->sLastCallDate,	pi->sLastCallDate,14);
		strncpy(po->sRecordCnt,		pi->sRecordCnt,10);
		strncpy(po->sRoamFee,		pi->sRoamFee,10);
		strncpy(po->sInfoFee,		pi->sInfoFee,10);
		strncpy(po->sReserve,		pi->sReserve,56);

		AllTrim(po->sHeadTag);
		AllTrim(po->sFileSeq);
		AllTrim(po->sFileVer);
		AllTrim(po->sCreateDate);
		AllTrim(po->sFirstCallDate);
		AllTrim(po->sLastCallDate);
		AllTrim(po->sRecordCnt);
		AllTrim(po->sRoamFee);
		AllTrim(po->sInfoFee);
		AllTrim(po->sReserve);
}
void mvitem_mfsmshead(struct SmsHeadStruct *pi,struct FSmsHeadStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FSmsHeadStruct));

		strncpy(po->sHeadTag,pi->sHeadTag,strlen(pi->sHeadTag));
		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVer,pi->sFileVer,strlen(pi->sFileVer));
		strncpy(po->sCreateDate,pi->sCreateDate,strlen(pi->sCreateDate));
		strncpy(po->sFirstCallDate,pi->sFirstCallDate,strlen(pi->sFirstCallDate));
		strncpy(po->sLastCallDate,pi->sLastCallDate,strlen(pi->sLastCallDate));
		strncpy(po->sRecordCnt,pi->sRecordCnt,strlen(pi->sRecordCnt));
		strncpy(po->sRoamFee,pi->sRoamFee,strlen(pi->sRoamFee));
		strncpy(po->sInfoFee,pi->sInfoFee,strlen(pi->sInfoFee));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}

void mvitem_mfnxrhjfhead(struct NxRhjfHeadStruct *pi,struct FNxRhjfHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FNxRhjfHeadStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sPickID,pi->sPickID,strlen(pi->sPickID));
		strncpy(po->sOriFileName,pi->sOriFileName,strlen(pi->sOriFileName));

		sprintf(sTemp,"%04d",pi->iSeqNbr);
		strncpy(po->sSeqNbr,sTemp,4);

		strncpy(po->sVersion,pi->sVersion,strlen(pi->sVersion));
		strncpy(po->sCreatedDate,pi->sCreatedDate,strlen(pi->sCreatedDate));
		strncpy(po->sBeginTime,pi->sBeginTime,strlen(pi->sBeginTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));

		sprintf(sTemp,"%08d",pi->iTotalCnt);
		strncpy(po->sTotalCnt,sTemp,8);

		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}

void mvitem_fmsmgdticket(struct FSmgDTicketStruct *pi,struct SmgDTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct SmgDTicketStruct));

		strncpy(po->sMessageID,		pi->sMessageID,21);
		strncpy(po->sSmsType,		pi->sSmsType,2);
		strncpy(po->sSubType,		pi->sSubType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,22);
		strncpy(po->sSpCode,		pi->sSpCode,11);
		strncpy(po->sOtherParty,	pi->sOtherParty,22);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,11);
		strncpy(po->sBillType,		pi->sBillType,3);
		strncpy(po->sInfoFee,		pi->sInfoFee,7);
		strncpy(po->sPriority,		pi->sPriority,2);
		strncpy(po->sMsgLen,		pi->sMsgLen,4);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sSmg,		pi->sSmg,7);
		strncpy(po->sTsmg,		pi->sTsmg,7);
		strncpy(po->sSmc,		pi->sSmc,7);
		strncpy(po->sRecvDateTime,	pi->sRecvDateTime,15);
		strncpy(po->sDoneDateTime,	pi->sDoneDateTime,15);
		strncpy(po->sMsgID,		pi->sMsgID,21);
		strncpy(po->sOppMsgID,		pi->sOppMsgID,21);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,21);

		AllTrim(po->sMessageID);
		AllTrim(po->sSmsType);
		AllTrim(po->sSubType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sSpCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sSpServiceCode);
		AllTrim(po->sBillType);
		AllTrim(po->sInfoFee);
		AllTrim(po->sPriority);
		AllTrim(po->sMsgLen);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sSmg);
		AllTrim(po->sTsmg);
		AllTrim(po->sSmc);
		AllTrim(po->sRecvDateTime);
		AllTrim(po->sDoneDateTime);
		AllTrim(po->sMsgID);
		AllTrim(po->sOppMsgID);
		AllTrim(po->sCallingNbr);
}

void mvitem_mfsmgdticket(struct SmgDTicketStruct *pi,struct FSmgDTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FSmgDTicketStruct));

		strncpy(po->sMessageID,pi->sMessageID,strlen(pi->sMessageID));
		strncpy(po->sSmsType,pi->sSmsType,strlen(pi->sSmsType));
		strncpy(po->sSubType,pi->sSubType,strlen(pi->sSubType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sInfoFee,pi->sInfoFee,strlen(pi->sInfoFee));
		strncpy(po->sPriority,pi->sPriority,strlen(pi->sPriority));
		strncpy(po->sMsgLen,pi->sMsgLen,strlen(pi->sMsgLen));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sSmg,pi->sSmg,strlen(pi->sSmg));
		strncpy(po->sTsmg,pi->sTsmg,strlen(pi->sTsmg));
		strncpy(po->sSmc,pi->sSmc,strlen(pi->sSmc));
		strncpy(po->sRecvDateTime,pi->sRecvDateTime,strlen(pi->sRecvDateTime));
		strncpy(po->sDoneDateTime,pi->sDoneDateTime,strlen(pi->sDoneDateTime));
		strncpy(po->sMsgID,pi->sMsgID,strlen(pi->sMsgID));
		strncpy(po->sOppMsgID,pi->sOppMsgID,strlen(pi->sOppMsgID));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));

}
void mvitem_mfsmgdhead(struct HbjsFileHeadStruct *pi,struct FHbjsFileHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FHbjsFileHeadStruct));

		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));

		sprintf(sTemp,"%09d",pi->iTotalCnt);
		strncpy(po->sTotalCnt,sTemp,9);

		strncpy(po->sFirstCallDate,pi->sFirstCallDate,strlen(pi->sFirstCallDate));
		strncpy(po->sFirstCallTime,pi->sFirstCallTime,strlen(pi->sFirstCallTime));
		strncpy(po->sEndCallDate,pi->sEndCallDate,strlen(pi->sEndCallDate));
		strncpy(po->sEndCallTime,pi->sEndCallTime,strlen(pi->sEndCallTime));
		strncpy(po->sCreatedDate,pi->sCreatedDate,strlen(pi->sCreatedDate));

}

void mvitem_fmznwsnintf(struct FZnwSnIntfStruct *pi,struct ZnwSnIntfStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct ZnwSnIntfStruct));

		strncpy(po->sServiceKey,	pi->sServiceKey,3);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,24);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,24);
		strncpy(po->sTranslatedNbr,	pi->sTranslatedNbr,24);
		strncpy(po->sBillingNbr,	pi->sBillingNbr,24);
		strncpy(po->sDuration,		pi->sDuration,12);

		strncpy(sTemp,		pi->sSecond,2);sTemp[2]=0;
		po->iSecond=atoi(sTemp);

		strncpy(po->sTotalFee,		pi->sTotalFee,12);

		strncpy(sTemp,		pi->sBaseFee,8);sTemp[8]=0;
		po->iBaseFee=atoi(sTemp);

		strncpy(po->sTrunkIn,		pi->sTrunkIn,4);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,4);
		strncpy(po->sMsc,		pi->sMsc,1);
		strncpy(po->sTariffClass,	pi->sTariffClass,2);
		strncpy(po->sReserve,		pi->sReserve,2);
		strncpy(po->sGroupID,		pi->sGroupID,12);
		strncpy(po->sCardID,		pi->sCardID,13);

		AllTrim(po->sServiceKey);
		AllTrim(po->sStartTime);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sTranslatedNbr);
		AllTrim(po->sBillingNbr);
		AllTrim(po->sDuration);
		AllTrim(po->sTotalFee);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sMsc);
		AllTrim(po->sTariffClass);
		AllTrim(po->sReserve);
		AllTrim(po->sGroupID);
		AllTrim(po->sCardID);
}
void mvitem_mfznwsnintf(struct ZnwSnIntfStruct *pi,struct FZnwSnIntfStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FZnwSnIntfStruct));

		strncpy(po->sServiceKey,pi->sServiceKey,strlen(pi->sServiceKey));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sTranslatedNbr,pi->sTranslatedNbr,strlen(pi->sTranslatedNbr));
		strncpy(po->sBillingNbr,pi->sBillingNbr,strlen(pi->sBillingNbr));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));

		sprintf(sTemp,"%02d",pi->iSecond);
		strncpy(po->sSecond,sTemp,2);

		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));

		sprintf(sTemp,"%08d",pi->iBaseFee);
		strncpy(po->sBaseFee,sTemp,8);

		strncpy(po->sTrunkIn,pi->sTrunkIn,strlen(pi->sTrunkIn));
		strncpy(po->sTrunkOut,pi->sTrunkOut,strlen(pi->sTrunkOut));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sTariffClass,pi->sTariffClass,strlen(pi->sTariffClass));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));
		strncpy(po->sGroupID,pi->sGroupID,strlen(pi->sGroupID));
		strncpy(po->sCardID,pi->sCardID,strlen(pi->sCardID));

}
void mvitem_fmznwgjintf(struct FZnwGjIntfStruct *pi,struct ZnwGjIntfStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct ZnwGjIntfStruct));

		strncpy(po->sStreamNumber,		pi->sStreamNumber,10);
		strncpy(po->sServiceKey,		pi->sServiceKey,10);
		strncpy(po->sBillingMode,		pi->sBillingMode,1);
		strncpy(po->sChargeRecordID,		pi->sChargeRecordID,8);
		strncpy(po->sCallingNbr,		pi->sCallingNbr,24);
		strncpy(po->sCalledNbr,			pi->sCalledNbr,24);
		strncpy(po->sTranslatedNbr,		pi->sTranslatedNbr,24);
		strncpy(po->sLocationNbr,		pi->sLocationNbr,4);
		strncpy(po->sBillingFlag,		pi->sBillingFlag,4);
		strncpy(po->sBillingNbr,		pi->sBillingNbr,24);
		strncpy(po->sStartTime,			pi->sStartTime,14);
		strncpy(po->sStopTime,			pi->sStopTime,14);
		strncpy(po->sDuration,			pi->sDuration,10);
		strncpy(po->sTotalFee,			pi->sTotalFee,10);
		strncpy(po->sBearCapability,		pi->sBearCapability,2);
		strncpy(po->sTariffClass,		pi->sTariffClass,2);
		strncpy(po->sBillType,			pi->sBillType,4);
		strncpy(po->sUserID,			pi->sUserID,10);
		strncpy(po->sServiceNbr,		pi->sServiceNbr,28);

		strncpy(sTemp,			pi->sCount,8);sTemp[8]=0;
		po->iCount=atoi(sTemp);

		strncpy(po->sBaseFee,			pi->sBaseFee,10);
		strncpy(po->sBountyFee,			pi->sBountyFee,10);
		strncpy(po->sAddFee,			pi->sAddFee,10);
		strncpy(po->sTransParam,		pi->sTransParam,30);
		strncpy(po->sCallparttobecharger,	pi->sCallparttobecharger,32);
		strncpy(po->sScpID,			pi->sScpID,10);
		strncpy(po->sCauseOfCallend,		pi->sCauseOfCallend,4);
		strncpy(po->sServiceModulator,		pi->sServiceModulator,4);
		strncpy(po->sServiceType,		pi->sServiceType,2);
		strncpy(po->sHomeAreaCode,		pi->sHomeAreaCode,10);
		strncpy(po->sCalledCode,		pi->sCalledCode,10);
		strncpy(po->sBillingAreaCode,		pi->sBillingAreaCode,10);
		strncpy(po->sOriFileName,		pi->sOriFileName,64);

		AllTrim(po->sStreamNumber);
		AllTrim(po->sServiceKey);
		AllTrim(po->sBillingMode);
		AllTrim(po->sChargeRecordID);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sTranslatedNbr);
		AllTrim(po->sLocationNbr);
		AllTrim(po->sBillingFlag);
		AllTrim(po->sBillingNbr);
		AllTrim(po->sStartTime);
		AllTrim(po->sStopTime);
		AllTrim(po->sDuration);
		AllTrim(po->sTotalFee);
		AllTrim(po->sBearCapability);
		AllTrim(po->sTariffClass);
		AllTrim(po->sBillType);
		AllTrim(po->sUserID);
		AllTrim(po->sServiceNbr);
		AllTrim(po->sBaseFee);
		AllTrim(po->sBountyFee);
		AllTrim(po->sAddFee);
		AllTrim(po->sTransParam);
		AllTrim(po->sCallparttobecharger);
		AllTrim(po->sScpID);
		AllTrim(po->sCauseOfCallend);
		AllTrim(po->sServiceModulator);
		AllTrim(po->sServiceType);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sCalledCode);
		AllTrim(po->sBillingAreaCode);
		AllTrim(po->sOriFileName);
}
void mvitem_mfznwgjintf(struct ZnwGjIntfStruct *pi,struct FZnwGjIntfStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FZnwGjIntfStruct));

		strncpy(po->sStreamNumber,pi->sStreamNumber,strlen(pi->sStreamNumber));
		strncpy(po->sServiceKey,pi->sServiceKey,strlen(pi->sServiceKey));
		strncpy(po->sBillingMode,pi->sBillingMode,strlen(pi->sBillingMode));
		strncpy(po->sChargeRecordID,pi->sChargeRecordID,strlen(pi->sChargeRecordID));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sTranslatedNbr,pi->sTranslatedNbr,strlen(pi->sTranslatedNbr));
		strncpy(po->sLocationNbr,pi->sLocationNbr,strlen(pi->sLocationNbr));
		strncpy(po->sBillingFlag,pi->sBillingFlag,strlen(pi->sBillingFlag));
		strncpy(po->sBillingNbr,pi->sBillingNbr,strlen(pi->sBillingNbr));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sStopTime,pi->sStopTime,strlen(pi->sStopTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sBearCapability,pi->sBearCapability,strlen(pi->sBearCapability));
		strncpy(po->sTariffClass,pi->sTariffClass,strlen(pi->sTariffClass));
		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sUserID,pi->sUserID,strlen(pi->sUserID));
		strncpy(po->sServiceNbr,pi->sServiceNbr,strlen(pi->sServiceNbr));

		sprintf(sTemp,"%08d",pi->iCount);
		strncpy(po->sCount,sTemp,8);

		strncpy(po->sBaseFee,pi->sBaseFee,strlen(pi->sBaseFee));
		strncpy(po->sBountyFee,pi->sBountyFee,strlen(pi->sBountyFee));
		strncpy(po->sAddFee,pi->sAddFee,strlen(pi->sAddFee));
		strncpy(po->sTransParam,pi->sTransParam,strlen(pi->sTransParam));
		strncpy(po->sCallparttobecharger,pi->sCallparttobecharger,strlen(pi->sCallparttobecharger));
		strncpy(po->sScpID,pi->sScpID,strlen(pi->sScpID));
		strncpy(po->sCauseOfCallend,pi->sCauseOfCallend,strlen(pi->sCauseOfCallend));
		strncpy(po->sServiceModulator,pi->sServiceModulator,strlen(pi->sServiceModulator));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sCalledCode,pi->sCalledCode,strlen(pi->sCalledCode));
		strncpy(po->sBillingAreaCode,pi->sBillingAreaCode,strlen(pi->sBillingAreaCode));
		strncpy(po->sOriFileName,pi->sOriFileName,strlen(pi->sOriFileName));

}
void mvitem_mfznwgjhead(struct HbZnwGjFileHeadStruct *pi,struct FHbZnwGjFileHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FHbZnwGjFileHeadStruct));

		sprintf(sTemp,"%011d",atoi(pi->sTotalCnt));
		strncpy(po->sTotalCnt,sTemp,11);
		sprintf(sTemp,"%011d",atoi(pi->sTotalDuration));
		strncpy(po->sTotalDuration,sTemp,11);
		sprintf(sTemp,"%011d",atoi(pi->sTotalFee));
		strncpy(po->sTotalFee,sTemp,11);


}

void mvitem_fmznw52intf(struct FZnw52IntfStruct *pi,struct Znw52IntfStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct Znw52IntfStruct));

		strncpy(po->sCallingNbr,	pi->sCallingNbr,24);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,24);
		strncpy(po->sTranslatedNbr,	pi->sTranslatedNbr,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sStopTime,		pi->sStopTime,14);
		strncpy(po->sDuration,		pi->sDuration,10);
		strncpy(po->sTotalFee,		pi->sTotalFee,10);

		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sTranslatedNbr);
		AllTrim(po->sStartTime);
		AllTrim(po->sStopTime);
		AllTrim(po->sDuration);
		AllTrim(po->sTotalFee);
}
void mvitem_mfznw52intf(struct Znw52IntfStruct *pi,struct FZnw52IntfStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FZnw52IntfStruct));

	strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
	strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
	strncpy(po->sTranslatedNbr,pi->sTranslatedNbr,strlen(pi->sTranslatedNbr));
	strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
	strncpy(po->sStopTime,pi->sStopTime,strlen(pi->sStopTime));
	strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
	strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
}

void mvitem_fmspcdrsnintf(struct FSpCdrSnIntfStruct *pi,struct SpCdrSnIntfStruct *po)
{/*数据文件移动到内存部分*/
/*	char sTemp[128];*/

	bzero((void*)po,sizeof(struct SpCdrSnIntfStruct));

		strncpy(po->sCallingNbr,pi->sCallingNbr,20);
		strncpy(po->sCalledNbr,	pi->sCalledNbr,10);
		strncpy(po->sServiceNbr,pi->sServiceNbr,20);
		strncpy(po->sStartTime,	pi->sStartTime,14);
		strncpy(po->sDuration,	pi->sDuration,11);
		strncpy(po->sFee,	pi->sFee,11);
		strncpy(po->sNotes,	pi->sNotes,20);
		strncpy(po->sRate,	pi->sRate,15);
		strncpy(po->sSpNbr,	pi->sSpNbr,9);

		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sServiceNbr);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sFee);
		AllTrim(po->sNotes);
		AllTrim(po->sRate);
		AllTrim(po->sSpNbr);
}
void mvitem_mfspcdrsnintf(struct SpCdrSnIntfStruct *pi,struct FSpCdrSnIntfStruct *po)
{/*内存数据移动到文件记录到部分*/
/*	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FSpCdrSnIntfStruct));

		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sServiceNbr,pi->sServiceNbr,strlen(pi->sServiceNbr));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sFee,pi->sFee,strlen(pi->sFee));
		strncpy(po->sNotes,pi->sNotes,strlen(pi->sNotes));
		strncpy(po->sRate,pi->sRate,strlen(pi->sRate));
		strncpy(po->sSpNbr,pi->sSpNbr,strlen(pi->sSpNbr));

}
void mvitem_fmspcdrzbintf(struct FSpCdrZbIntfStruct *pi,struct SpCdrZbIntfStruct *po)
{/*数据文件移动到内存部分*/
/*	char sTemp[128];*/

	bzero((void*)po,sizeof(struct SpCdrZbIntfStruct));

		strncpy(po->sCallingNbr,pi->sCallingNbr,20);
		strncpy(po->sCalledNbr,	pi->sCalledNbr,10);
		strncpy(po->sServiceNbr,pi->sServiceNbr,20);
		strncpy(po->sStartTime,	pi->sStartTime,14);
		strncpy(po->sDuration,	pi->sDuration,11);
		strncpy(po->sFee,	pi->sFee,11);

		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sServiceNbr);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sFee);
}
void mvitem_mfspcdrzbintf(struct SpCdrZbIntfStruct *pi,struct FSpCdrZbIntfStruct *po)
{/*内存数据移动到文件记录到部分*/
/*	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FSpCdrZbIntfStruct));

		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sServiceNbr,pi->sServiceNbr,strlen(pi->sServiceNbr));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sFee,pi->sFee,strlen(pi->sFee));

}
void mvitem_mfspacctsnintf(struct SpAcctSnIntfStruct *pi,struct FSpAcctSnIntfStruct *po)
{/*内存数据移动到文件记录到部分*/
/*	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FSpAcctSnIntfStruct));

		strncpy(po->sProvinceName,pi->sProvinceName,strlen(pi->sProvinceName));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
		strncpy(po->sSpNbr,pi->sSpNbr,strlen(pi->sSpNbr));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sCnt,pi->sCnt,strlen(pi->sCnt));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sFee,pi->sFee,strlen(pi->sFee));
		strncpy(po->sRate,pi->sRate,strlen(pi->sRate));
		strncpy(po->sNotes,pi->sNotes,strlen(pi->sNotes));

}
void mvitem_fmspacctsnintf(struct FSpAcctSnIntfStruct *pi,struct SpAcctSnIntfStruct *po)
{/*数据文件移动到内存部分
	char sTemp[128];*/

	bzero((void*)po,sizeof(struct SpAcctSnIntfStruct));

		strncpy(po->sProvinceName,	pi->sProvinceName,4);
		strncpy(po->sAreaCode,		pi->sAreaCode,4);
		strncpy(po->sSpNbr,		pi->sSpNbr,9);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,20);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,10);
		strncpy(po->sCnt,		pi->sCnt,11);
		strncpy(po->sDuration,		pi->sDuration,11);
		strncpy(po->sFee,		pi->sFee,11);
		strncpy(po->sRate,		pi->sRate,15);
		strncpy(po->sNotes,		pi->sNotes,20);

		AllTrim(po->sProvinceName);
		AllTrim(po->sAreaCode);
		AllTrim(po->sSpNbr);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sCnt);
		AllTrim(po->sDuration);
		AllTrim(po->sFee);
		AllTrim(po->sRate);
		AllTrim(po->sNotes);
}

void mvitem_mfznwgjacct(struct ZnwGjAcctStruct *pi,struct FZnwGjAcctStruct *po)
{/*内存数据移动到文件记录到部分
	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FZnwGjAcctStruct));

		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sServiceKey,pi->sServiceKey,strlen(pi->sServiceKey));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));

		sprintf(po->sBaseFee  ,	"%010d",atoi(pi->sBaseFee  ));
		sprintf(po->sAddFee   ,	"%010d",atoi(pi->sAddFee   ));
		sprintf(po->sLcnt     ,	"%011d",atoi(pi->sLcnt     ));
		sprintf(po->sLduration,	"%011d",atoi(pi->sLduration));
		sprintf(po->sLfee     ,	"%011d",atoi(pi->sLfee     ));
		sprintf(po->sNcnt     ,	"%011d",atoi(pi->sNcnt     ));
		sprintf(po->sNduration,	"%011d",atoi(pi->sNduration));
		sprintf(po->sNfee     ,	"%011d",atoi(pi->sNfee     ));
		sprintf(po->sScnt     ,	"%011d",atoi(pi->sScnt     ));
		sprintf(po->sSduration,	"%011d",atoi(pi->sSduration));
		sprintf(po->sSfee     ,	"%011d",atoi(pi->sSfee     ));
		sprintf(po->sGcnt     ,	"%011d",atoi(pi->sGcnt     ));
		sprintf(po->sGduration,	"%011d",atoi(pi->sGduration));
		sprintf(po->sGfee     ,	"%011d",atoi(pi->sGfee     ));
		sprintf(po->sCnt      ,	"%011d",atoi(pi->sCnt      ));
		sprintf(po->sDuration ,	"%011d",atoi(pi->sDuration ));
		sprintf(po->sFee      ,	"%011d",atoi(pi->sFee      ));		

}
void mvitem_mfspacctzbintf(struct SpAcctZbIntfStruct *pi,struct FSpAcctZbIntfStruct *po)
{/*内存数据移动到文件记录到部分
	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FSpAcctZbIntfStruct));

		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sCnt,pi->sCnt,strlen(pi->sCnt));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sFee,pi->sFee,strlen(pi->sFee));

}

void Newmvitem_fmcriticket(struct FNewCriTicketStruct *pi,struct NewCriTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct NewCriTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sLinkRef,		pi->sLinkRef,6);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,25);
		strncpy(po->sModifyTag,		pi->sModifyTag,1);
		strncpy(po->sNbrType,		pi->sNbrType,1);
		strncpy(po->sNbrPlan,		pi->sNbrPlan,1);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sDupServiceType,	pi->sDupServiceType,1);
		strncpy(po->sDupServiceCode,	pi->sDupServiceCode,2);
		strncpy(po->sAckChannel,	pi->sAckChannel,1);
		strncpy(po->sUseChannel,	pi->sUseChannel,1);
		strncpy(po->sTransparentFlag,	pi->sTransparentFlag,1);
		strncpy(po->sAct1,		pi->sAct1,1);
		strncpy(po->sCode1,		pi->sCode1,2);
		strncpy(po->sAct2,		pi->sAct2,1);
		strncpy(po->sCode2,		pi->sCode2,2);
		strncpy(po->sAct3,		pi->sAct3,1);
		strncpy(po->sCode3,		pi->sCode3,2);
		strncpy(po->sAct4,		pi->sAct4,1);
		strncpy(po->sCode4,		pi->sCode4,2);
		strncpy(po->sAct5,		pi->sAct5,1);
		strncpy(po->sCode5,		pi->sCode5,2);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sFlowRef,		pi->sFlowRef,6);
		strncpy(po->sTollCode,		pi->sTollCode,1);
		strncpy(po->sOtherCode,		pi->sOtherCode,2);
		strncpy(po->sRoamFee,		pi->sRoamFee,9);
		strncpy(po->sTollFee,		pi->sTollFee,6);
		strncpy(po->sOtherFee,		pi->sOtherFee,6);
		strncpy(po->sPayItem,		pi->sPayItem,1);
		strncpy(po->sSystemType,	pi->sSystemType,1);
		strncpy(po->sRateIndication,	pi->sRateIndication,1);
		strncpy(po->sHotBillingTag,	pi->sHotBillingTag,1);
		strncpy(po->sImei,		pi->sImei,25);
		strncpy(po->sReserve2,		pi->sReserve2,30);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sModifyTag);
		AllTrim(po->sNbrType);
		AllTrim(po->sNbrPlan);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sDupServiceType);
		AllTrim(po->sDupServiceCode);
		AllTrim(po->sAckChannel);
		AllTrim(po->sUseChannel);
		AllTrim(po->sTransparentFlag);
		AllTrim(po->sAct1);
		AllTrim(po->sCode1);
		AllTrim(po->sAct2);
		AllTrim(po->sCode2);
		AllTrim(po->sAct3);
		AllTrim(po->sCode3);
		AllTrim(po->sAct4);
		AllTrim(po->sCode4);
		AllTrim(po->sAct5);
		AllTrim(po->sCode5);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sFlowRef);
		AllTrim(po->sTollCode);
		AllTrim(po->sOtherCode);
		AllTrim(po->sRoamFee);
		AllTrim(po->sTollFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sPayItem);
		AllTrim(po->sSystemType);
		AllTrim(po->sRateIndication);
		AllTrim(po->sHotBillingTag);
		AllTrim(po->sImei);
		AllTrim(po->sReserve2);
}
void Newmvitem_mfcriticket(struct NewCriTicketStruct *pi,struct FNewCriTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FNewCriTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCode,pi->sOutCityCode,strlen(pi->sOutCityCode));
		strncpy(po->sLinkRef,pi->sLinkRef,strlen(pi->sLinkRef));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sModifyTag,pi->sModifyTag,strlen(pi->sModifyTag));
		strncpy(po->sNbrType,pi->sNbrType,strlen(pi->sNbrType));
		strncpy(po->sNbrPlan,pi->sNbrPlan,strlen(pi->sNbrPlan));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sDupServiceType,pi->sDupServiceType,strlen(pi->sDupServiceType));
		strncpy(po->sDupServiceCode,pi->sDupServiceCode,strlen(pi->sDupServiceCode));
		strncpy(po->sAckChannel,pi->sAckChannel,strlen(pi->sAckChannel));
		strncpy(po->sUseChannel,pi->sUseChannel,strlen(pi->sUseChannel));
		strncpy(po->sTransparentFlag,pi->sTransparentFlag,strlen(pi->sTransparentFlag));
		strncpy(po->sAct1,pi->sAct1,strlen(pi->sAct1));
		strncpy(po->sCode1,pi->sCode1,strlen(pi->sCode1));
		strncpy(po->sAct2,pi->sAct2,strlen(pi->sAct2));
		strncpy(po->sCode2,pi->sCode2,strlen(pi->sCode2));
		strncpy(po->sAct3,pi->sAct3,strlen(pi->sAct3));
		strncpy(po->sCode3,pi->sCode3,strlen(pi->sCode3));
		strncpy(po->sAct4,pi->sAct4,strlen(pi->sAct4));
		strncpy(po->sCode4,pi->sCode4,strlen(pi->sCode4));
		strncpy(po->sAct5,pi->sAct5,strlen(pi->sAct5));
		strncpy(po->sCode5,pi->sCode5,strlen(pi->sCode5));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sServType,pi->sServType,strlen(pi->sServType));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sPayUnit,pi->sPayUnit,strlen(pi->sPayUnit));
		strncpy(po->sFlowRef,pi->sFlowRef,strlen(pi->sFlowRef));
		strncpy(po->sTollCode,pi->sTollCode,strlen(pi->sTollCode));
		strncpy(po->sOtherCode,pi->sOtherCode,strlen(pi->sOtherCode));
		strncpy(po->sRoamFee,pi->sRoamFee,strlen(pi->sRoamFee));
		strncpy(po->sTollFee,pi->sTollFee,strlen(pi->sTollFee));
		strncpy(po->sOtherFee,pi->sOtherFee,strlen(pi->sOtherFee));
		strncpy(po->sPayItem,pi->sPayItem,strlen(pi->sPayItem));
		strncpy(po->sSystemType,pi->sSystemType,strlen(pi->sSystemType));
		strncpy(po->sRateIndication,pi->sRateIndication,strlen(pi->sRateIndication));
		strncpy(po->sHotBillingTag,pi->sHotBillingTag,strlen(pi->sHotBillingTag));
		strncpy(po->sImei,pi->sImei,strlen(pi->sImei));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));

}
/**对表CRI_TICKET的链表释放函数**/
void NewDestroyCriTicket(struct NewCriTicketStruct *ptHead)
{
	struct NewCriTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

void Newmvitem_fmciiticket(struct FNewCiiTicketStruct *pi,struct NewCiiTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct NewCiiTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sLinkRef,		pi->sLinkRef,6);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,25);
		strncpy(po->sModifyTag,		pi->sModifyTag,1);
		strncpy(po->sNbrType,		pi->sNbrType,1);
		strncpy(po->sNbrPlan,		pi->sNbrPlan,1);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sDupServiceType,	pi->sDupServiceType,1);
		strncpy(po->sDupServiceCode,	pi->sDupServiceCode,2);
		strncpy(po->sAckChannel,	pi->sAckChannel,1);
		strncpy(po->sUseChannel,	pi->sUseChannel,1);
		strncpy(po->sTransparentFlag,	pi->sTransparentFlag,1);
		strncpy(po->sAct1,		pi->sAct1,1);
		strncpy(po->sCode1,		pi->sCode1,2);
		strncpy(po->sAct2,		pi->sAct2,1);
		strncpy(po->sCode2,		pi->sCode2,2);
		strncpy(po->sAct3,		pi->sAct3,1);
		strncpy(po->sCode3,		pi->sCode3,2);
		strncpy(po->sAct4,		pi->sAct4,1);
		strncpy(po->sCode4,		pi->sCode4,2);
		strncpy(po->sAct5,		pi->sAct5,1);
		strncpy(po->sCode5,		pi->sCode5,2);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sFlowRef,		pi->sFlowRef,6);
		strncpy(po->sFee,		pi->sFee,9);
		strncpy(po->sPayItem,		pi->sPayItem,1);
		strncpy(po->sSystemType,	pi->sSystemType,1);
		strncpy(po->sRateIndication,	pi->sRateIndication,1);
		strncpy(po->sHotBillingTag,	pi->sHotBillingTag,1);
		strncpy(po->sVhe,		pi->sVhe,1);
		strncpy(po->sInterScpFlag,	pi->sInterScpFlag,10);
		strncpy(po->sReserve2,		pi->sReserve2,16);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sModifyTag);
		AllTrim(po->sNbrType);
		AllTrim(po->sNbrPlan);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sDupServiceType);
		AllTrim(po->sDupServiceCode);
		AllTrim(po->sAckChannel);
		AllTrim(po->sUseChannel);
		AllTrim(po->sTransparentFlag);
		AllTrim(po->sAct1);
		AllTrim(po->sCode1);
		AllTrim(po->sAct2);
		AllTrim(po->sCode2);
		AllTrim(po->sAct3);
		AllTrim(po->sCode3);
		AllTrim(po->sAct4);
		AllTrim(po->sCode4);
		AllTrim(po->sAct5);
		AllTrim(po->sCode5);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sFlowRef);
		AllTrim(po->sFee);
		AllTrim(po->sPayItem);
		AllTrim(po->sSystemType);
		AllTrim(po->sRateIndication);
		AllTrim(po->sHotBillingTag);
		AllTrim(po->sVhe);
		AllTrim(po->sInterScpFlag);
		AllTrim(po->sReserve2);
}
void Newmvitem_mfciiticket(struct NewCiiTicketStruct *pi,struct FNewCiiTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FNewCiiTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCode,pi->sOutCityCode,strlen(pi->sOutCityCode));
		strncpy(po->sLinkRef,pi->sLinkRef,strlen(pi->sLinkRef));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sModifyTag,pi->sModifyTag,strlen(pi->sModifyTag));
		strncpy(po->sNbrType,pi->sNbrType,strlen(pi->sNbrType));
		strncpy(po->sNbrPlan,pi->sNbrPlan,strlen(pi->sNbrPlan));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sDupServiceType,pi->sDupServiceType,strlen(pi->sDupServiceType));
		strncpy(po->sDupServiceCode,pi->sDupServiceCode,strlen(pi->sDupServiceCode));
		strncpy(po->sAckChannel,pi->sAckChannel,strlen(pi->sAckChannel));
		strncpy(po->sUseChannel,pi->sUseChannel,strlen(pi->sUseChannel));
		strncpy(po->sTransparentFlag,pi->sTransparentFlag,strlen(pi->sTransparentFlag));
		strncpy(po->sAct1,pi->sAct1,strlen(pi->sAct1));
		strncpy(po->sCode1,pi->sCode1,strlen(pi->sCode1));
		strncpy(po->sAct2,pi->sAct2,strlen(pi->sAct2));
		strncpy(po->sCode2,pi->sCode2,strlen(pi->sCode2));
		strncpy(po->sAct3,pi->sAct3,strlen(pi->sAct3));
		strncpy(po->sCode3,pi->sCode3,strlen(pi->sCode3));
		strncpy(po->sAct4,pi->sAct4,strlen(pi->sAct4));
		strncpy(po->sCode4,pi->sCode4,strlen(pi->sCode4));
		strncpy(po->sAct5,pi->sAct5,strlen(pi->sAct5));
		strncpy(po->sCode5,pi->sCode5,strlen(pi->sCode5));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sServType,pi->sServType,strlen(pi->sServType));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sPayUnit,pi->sPayUnit,strlen(pi->sPayUnit));
		strncpy(po->sFlowRef,pi->sFlowRef,strlen(pi->sFlowRef));
		strncpy(po->sFee,pi->sFee,strlen(pi->sFee));
		strncpy(po->sPayItem,pi->sPayItem,strlen(pi->sPayItem));
		strncpy(po->sSystemType,pi->sSystemType,strlen(pi->sSystemType));
		strncpy(po->sRateIndication,pi->sRateIndication,strlen(pi->sRateIndication));
		strncpy(po->sHotBillingTag,pi->sHotBillingTag,strlen(pi->sHotBillingTag));
		strncpy(po->sVhe,pi->sVhe,strlen(pi->sVhe));
		strncpy(po->sInterScpFlag,pi->sInterScpFlag,strlen(pi->sInterScpFlag));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));

}
/**对表CII_TICKET的链表释放函数**/
void NewDestroyCiiTicket(struct NewCiiTicketStruct *ptHead)
{
	struct NewCiiTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
void Newmvitem_fmtrsticket(struct FNewTrsTicketStruct *pi,struct NewTrsTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct NewTrsTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sLinkRef,		pi->sLinkRef,6);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sThirdParty,	pi->sThirdParty,25);
		strncpy(po->sMsisdn,		pi->sMsisdn,25);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sReserve2,		pi->sReserve2,9);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sSystemType,	pi->sSystemType,1);
		strncpy(po->sRateIndication,	pi->sRateIndication,1);
		strncpy(po->sHotBillingTag,	pi->sHotBillingTag,1);
		strncpy(po->sImei,		pi->sImei,25);
		strncpy(po->sReserve3,		pi->sReserve3,51);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sReserve2);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sSystemType);
		AllTrim(po->sRateIndication);
		AllTrim(po->sHotBillingTag);
		AllTrim(po->sImei);
		AllTrim(po->sReserve3);
}
void Newmvitem_mftrsticket(struct NewTrsTicketStruct *pi,struct FNewTrsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FNewTrsTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCode,pi->sOutCityCode,strlen(pi->sOutCityCode));
		strncpy(po->sLinkRef,pi->sLinkRef,strlen(pi->sLinkRef));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sThirdParty,pi->sThirdParty,strlen(pi->sThirdParty));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sServType,pi->sServType,strlen(pi->sServType));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sPayUnit,pi->sPayUnit,strlen(pi->sPayUnit));
		strncpy(po->sSystemType,pi->sSystemType,strlen(pi->sSystemType));
		strncpy(po->sRateIndication,pi->sRateIndication,strlen(pi->sRateIndication));
		strncpy(po->sHotBillingTag,pi->sHotBillingTag,strlen(pi->sHotBillingTag));
		strncpy(po->sImei,pi->sImei,strlen(pi->sImei));
		strncpy(po->sReserve3,pi->sReserve3,strlen(pi->sReserve3));

}
void mvitem_mfgprshead(struct GprsHeadStruct *pi,struct FGprsHeadStruct *po)
{/*内存数据移动到文件记录到部分
	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FGprsHeadStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sProvCode,pi->sProvCode,strlen(pi->sProvCode));
		strncpy(po->sFileFlag,pi->sFileFlag,strlen(pi->sFileFlag));
		strncpy(po->sFileSeq,pi->sFileSeq,strlen(pi->sFileSeq));
		strncpy(po->sFileVersion,pi->sFileVersion,strlen(pi->sFileVersion));
		strncpy(po->sFileCreatDate,pi->sFileCreatDate,strlen(pi->sFileCreatDate));
		strncpy(po->sFirstCallDate,pi->sFirstCallDate,strlen(pi->sFirstCallDate));
		strncpy(po->sFirstCallTime,pi->sFirstCallTime,strlen(pi->sFirstCallTime));
		strncpy(po->sLastCallDate,pi->sLastCallDate,strlen(pi->sLastCallDate));
		strncpy(po->sLastCallTime,pi->sLastCallTime,strlen(pi->sLastCallTime));
		strncpy(po->sTotalCnt,pi->sTotalCnt,strlen(pi->sTotalCnt));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sNouse,pi->sNouse,strlen(pi->sNouse));

}
void mvitem_mfgprsticketintf(struct GprsTicketIntfStruct *pi,
	struct FGprsTicketIntfStruct *po)
{/*内存数据移动到文件记录到部分
	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FGprsTicketIntfStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sRoamType,pi->sRoamType,strlen(pi->sRoamType));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sSgsn,pi->sSgsn,strlen(pi->sSgsn));
		strncpy(po->sSgsnChange,pi->sSgsnChange,strlen(pi->sSgsnChange));
		strncpy(po->sGgsn,pi->sGgsn,strlen(pi->sGgsn));
		strncpy(po->sServedPdpAddress,pi->sServedPdpAddress,strlen(pi->sServedPdpAddress));
		strncpy(po->sApnNi,pi->sApnNi,strlen(pi->sApnNi));
		strncpy(po->sApnOi,pi->sApnOi,strlen(pi->sApnOi));
		strncpy(po->sReserv1,pi->sReserv1,strlen(pi->sReserv1));
		strncpy(po->sCallDuration,pi->sCallDuration,strlen(pi->sCallDuration));
		strncpy(po->sPartialType,pi->sPartialType,strlen(pi->sPartialType));
		strncpy(po->sCloseCause,pi->sCloseCause,strlen(pi->sCloseCause));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sNiPdp,pi->sNiPdp,strlen(pi->sNiPdp));
		strncpy(po->sChargingID,pi->sChargingID,strlen(pi->sChargingID));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sVisitCityCode,pi->sVisitCityCode,strlen(pi->sVisitCityCode));
		strncpy(po->sReserv2,pi->sReserv2,strlen(pi->sReserv2));
		strncpy(po->sRoamRemark,pi->sRoamRemark,strlen(pi->sRoamRemark));
		strncpy(po->sImei,pi->sImei,strlen(pi->sImei));
		strncpy(po->sDataFlowdn,pi->sDataFlowdn,strlen(pi->sDataFlowdn));
		strncpy(po->sDataFlowup,pi->sDataFlowup,strlen(pi->sDataFlowup));
		strncpy(po->sChargeItem,pi->sChargeItem,strlen(pi->sChargeItem));
		strncpy(po->sChargeUnit,pi->sChargeUnit,strlen(pi->sChargeUnit));
		strncpy(po->sChargeOperation,pi->sChargeOperation,strlen(pi->sChargeOperation));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sReserv3,pi->sReserv3,strlen(pi->sReserv3));

}
/**对表TRS_TICKET的链表释放函数**/
void NewDestroyTrsTicket(struct NewTrsTicketStruct *ptHead)
{
	struct NewTrsTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

/*保存文件用的全局变量，使TravelBin的hook函数能保存文件*/
FILE *SaveKeyFP;

int hook_save_file(void **ppData)
{
	fwrite(*ppData,sizeof(struct KeyStruct),1,SaveKeyFP);
	return 0;
}

int SaveKeytoFile(BINTREE **pptRoot,char sFileName[])
{
	if (*pptRoot == NULL) return 0;

	SaveKeyFP = fopen(sFileName,"w");
	if (SaveKeyFP==NULL){
		perror("打开文件写失败");
		WriteAlertMsg("打开键值文件:%s写失败!",sFileName);
		return -1;
	}

	/*在hook_pdup_list中处理写文件记录操作。。。。*/
	TravelBin(*pptRoot,hook_save_file);
	DestroyBin(*pptRoot);
	*pptRoot=NULL;

	fclose(SaveKeyFP);

	return 0;
}

static int data_comp_dup_key_e(void *pValue,void *pData)
{
	struct KeyStruct *pSource=(struct KeyStruct *)pValue;
	struct KeyStruct *pTarget=(struct KeyStruct *)pData;

	return memcmp(pSource->sKey,pTarget->sKey,KEYLEN);
}

static void assign_insert_bintree_dup_key_e(void **ppHead,void *pData)
{
	*ppHead=pData;
}

int LoadKeyFromFile(BINTREE **pptRoot,const char sFileName[],
	int (*hook_load_file)(struct KeyStruct *pNode)){

	FILE *fp;
	struct KeyStruct *p;

	/*忽略打开失败，可能初次运行*/
	fp=fopen(sFileName,"rb");
	if (fp==NULL){
		perror("打开文件读失败");
		/*WriteAlertMsg("打开键值文件:%s读失败!",sFileName);*/
		return 0;
	}

	while(true){

		if((p=(struct KeyStruct*)calloc(
			sizeof(struct KeyStruct),1))==NULL){
			WriteAlertMsg("生成DUPKEY失败dup_key");
			exit(1);
		}

		if (fread(p,1,sizeof(struct KeyStruct),fp)!=
				sizeof(struct KeyStruct)){
			free(p);
			p=NULL;
			break;
		}

		/*处理节点*/
		if (hook_load_file != NULL)
			if (hook_load_file(p)<0){
				free(p);
				p=NULL;
				continue;
			}

		if(InsertBin(pptRoot,(void *)p,
			data_comp_dup_key_e,
			assign_insert_bintree_dup_key_e)<0){
			WriteAlertMsg("生成BINTREE失败dup_key");
			exit(1);
		}
	}

	fclose(fp);
	return 0;
}

int IsDupTicket(BINTREE *pRoot,struct KeyStruct *pNode)
{
	struct KeyStruct *pNoUse;

	if((SearchBin(pRoot,pNode,data_comp_dup_key_e,(void**)&pNoUse))==FOUND)
		return FOUND;

	return NOTFOUND;
}

int AddKeyToFile(struct KeyStruct *pTmpNode, BINTREE **pptRoot)
{
	struct KeyStruct *pNode=NULL;

	if((pNode=(struct KeyStruct*)calloc(
		sizeof(struct KeyStruct),1))==NULL){
		WriteAlertMsg("生成DUPKEY失败dup_key");
		exit(1);
	}

	memcpy(pNode,pTmpNode,sizeof(struct KeyStruct));

	if(InsertBin(pptRoot,(void *)pNode,
		data_comp_dup_key_e,
		assign_insert_bintree_dup_key_e)<0){
		WriteAlertMsg("生成BINTREE失败dup_key");
		exit(1);
	}

	return 0;
}
/*载入的hook为节点是处理函数，返回>=0表示加载/保存此节点,可修改参数值。*/
int delete_overtime_ticket(struct KeyStruct *pNode)
{
	time_t tnow;

	/*保存30小时内的话单*/
	if (time(&tnow)-pNode->tDateTime>=108000)
		return -1;
	return 0;
}

/*
获取数据的md5编码
输入最大长度8192字节
输出16位的md5的unsigned char编码
注意:为方便调用,使用static变量保存结果，故非线程安全.
功能与MD5基本一致为一组内存编码为md5,但为节省空间保存在unsigned char中
*/
struct KeyStruct *MakeDupKey(char sDateTime[],char *fmt,...)
{
	static struct KeyStruct DupKey;

#define MAXLEN 8192
	int iBuffLen=0;
	char sText[MAXLEN+1];
	va_list argptr;

	md5_state_t state;
	md5_byte_t digest[16];

	/*获取将编码值，空返回*/
	memset(sText,0,MAXLEN);
	va_start(argptr, fmt);
	vsprintf(sText, fmt, argptr);
	va_end(argptr);
	sText[MAXLEN] = 0;
	iBuffLen=strlen(sText);

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)sText, iBuffLen);
	md5_finish(&state, digest);

	memcpy(DupKey.sKey,digest,KEYLEN);
	DupKey.tDateTime=tGetTime(sDateTime);

	return &DupKey;
}

int MD5(char sOutput[],char *fmt,...)
{
#define MAXLEN 8192
	int iBuffLen=0;
	char sText[MAXLEN+1];
	va_list argptr;

	md5_state_t state;
	md5_byte_t digest[16];
	char hex_output[16*2 + 1];
	int di;

	/*获取将编码值，空返回*/
	memset(sText,0,MAXLEN);
	va_start(argptr, fmt);
	vsprintf(sText, fmt, argptr);
	va_end(argptr);
	sText[MAXLEN] = 0;

	iBuffLen = strlen(sText);
	if (iBuffLen==0){
		sOutput[0]='\0';
		return 0;
	}

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)sText, iBuffLen);
	md5_finish(&state, digest);
	for (di = 0; di < 16; ++di)
		sprintf(hex_output + di * 2, "%02x", digest[di]);

	strcpy(sOutput,hex_output);

	return 0;
}
