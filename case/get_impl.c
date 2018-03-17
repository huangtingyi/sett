#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwcoding.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <ticket_field.h>
#include <param_intf.h>
#include <up_back.h>
#include <stt_ticket.h>

void mvitem_mfprepticket(struct PrepTicketStruct *pi,struct FPrepTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FPrepTicketStruct));

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sTrunkIn,pi->sTrunkIn,strlen(pi->sTrunkIn));
		strncpy(po->sTrunkOut,pi->sTrunkOut,strlen(pi->sTrunkOut));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sOtherLac,pi->sOtherLac,strlen(pi->sOtherLac));
		strncpy(po->sOtherCellID,pi->sOtherCellID,strlen(pi->sOtherCellID));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sThirdParty,pi->sThirdParty,strlen(pi->sThirdParty));
		strncpy(po->sMsrn,pi->sMsrn,strlen(pi->sMsrn));
		
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));

		strncpy(po->sEsn,pi->sEsn,strlen(pi->sEsn));
		strncpy(po->sScpFlag,pi->sScpFlag,strlen(pi->sScpFlag));
		strncpy(po->sDeformFlag,pi->sDeformFlag,strlen(pi->sDeformFlag));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}
void mvitem_mfsttticket(struct SttTicketStruct *pi,struct FSttTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSttTicketStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sCalledCode,pi->sCalledCode,strlen(pi->sCalledCode));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sVisitAreaCode,pi->sVisitAreaCode,strlen(pi->sVisitAreaCode));

		sprintf(sTemp,"%05d",pi->iRoamFee);
		strncpy(po->sRoamFee,sTemp,5);
		sprintf(sTemp,"%07d",pi->iTollFee);
		strncpy(po->sTollFee,sTemp,7);
		sprintf(sTemp,"%05d",pi->iAddFee);
		strncpy(po->sAddFee,sTemp,5);
		sprintf(sTemp,"%06d",pi->iDuration);
		strncpy(po->sDuration,sTemp,6);

		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sRoamType,pi->sRoamType,strlen(pi->sRoamType));
		strncpy(po->sDistanceType,pi->sDistanceType,strlen(pi->sDistanceType));
		strncpy(po->sOppType,pi->sOppType,strlen(pi->sOppType));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sSplitRuleID,pi->sSplitRuleID,strlen(pi->sSplitRuleID));
		strncpy(po->sOppRoamType,pi->sOppRoamType,strlen(pi->sOppRoamType));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sOtherLac,pi->sOtherLac,strlen(pi->sOtherLac));
		strncpy(po->sOtherCellID,pi->sOtherCellID,strlen(pi->sOtherCellID));
		strncpy(po->sTrunkIn,pi->sTrunkIn,strlen(pi->sTrunkIn));
		strncpy(po->sTrunkOut,pi->sTrunkOut,strlen(pi->sTrunkOut));
		strncpy(po->sThirdParty,pi->sThirdParty,strlen(pi->sThirdParty));
		strncpy(po->sMsrn,pi->sMsrn,strlen(pi->sMsrn));

		sprintf(sTemp,"%04d",pi->iTrunkInTypeID);
		strncpy(po->sTrunkInTypeID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iTrunkOutTypeID);
		strncpy(po->sTrunkOutTypeID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iTrunkInCarrierID);
		strncpy(po->sTrunkInCarrierID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iTrunkOutCarrierID);
		strncpy(po->sTrunkOutCarrierID,sTemp,4);

		strncpy(po->sTrunkInType,pi->sTrunkInType,strlen(pi->sTrunkInType));
		strncpy(po->sTrunkOutType,pi->sTrunkOutType,strlen(pi->sTrunkOutType));

		sprintf(sTemp,"%04d",pi->iCallingCarrierID);
		strncpy(po->sCallingCarrierID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iCalledCarrierID);
		strncpy(po->sCalledCarrierID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iCallingTypeID);
		strncpy(po->sCallingTypeID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iCalledTypeID);
		strncpy(po->sCalledTypeID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iCallingAreaID);
		strncpy(po->sCallingAreaID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iCalledAreaID);
		strncpy(po->sCalledAreaID,sTemp,4);

		strncpy(po->sSplitType,pi->sSplitType,strlen(pi->sSplitType));
		strncpy(po->sCal,pi->sCal,strlen(pi->sCal));
		strncpy(po->sEsn,pi->sEsn,strlen(pi->sEsn));

		strncpy(po->sScpFlag,pi->sScpFlag,strlen(pi->sScpFlag));
		strncpy(po->sDeformFlag,pi->sDeformFlag,strlen(pi->sDeformFlag));

		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));
		strncpy(po->sBillMode,pi->sBillMode,strlen(pi->sBillMode));
		
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sRoamTariffType,pi->sRoamTariffType,strlen(pi->sRoamTariffType));
		strncpy(po->sTollTariffType,pi->sTollTariffType,strlen(pi->sTollTariffType));
		strncpy(po->sAddTariffType,pi->sAddTariffType,strlen(pi->sAddTariffType));

		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}
void mvitem_mfsmscticket(struct SmscTicketStruct *pi,struct FSmscTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FSmscTicketStruct));

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sSmsp,pi->sSmsp,strlen(pi->sSmsp));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sFee,pi->sFee,strlen(pi->sFee));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));

		sprintf(po->sTicketTypeID,"%04d",pi->iTicketTypeID);

		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}

void mvitem_mfsmspticket(struct SmspTicketStruct *pi,struct FSmspTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FSmspTicketStruct));

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sSmsp,pi->sSmsp,strlen(pi->sSmsp));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sFee1,pi->sFee1,strlen(pi->sFee1));
		strncpy(po->sFee2,pi->sFee2,strlen(pi->sFee2));
		strncpy(po->sFee3,pi->sFee3,strlen(pi->sFee3));
		strncpy(po->sFee4,pi->sFee4,strlen(pi->sFee4));

		strncpy(po->sFee5,pi->sFee5,strlen(pi->sFee5));
		strncpy(po->sFee6,pi->sFee6,strlen(pi->sFee6));
		sprintf(po->sTicketTypeID,"%04d",pi->iTicketTypeID);

		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}
void mvitem_mfgprsticket(struct GprsTicketStruct *pi,struct FGprsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FGprsTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sNiPdp,pi->sNiPdp,strlen(pi->sNiPdp));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sSgsn,pi->sSgsn,strlen(pi->sSgsn));
		strncpy(po->sMsnc,pi->sMsnc,strlen(pi->sMsnc));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sRouteArea,pi->sRouteArea,strlen(pi->sRouteArea));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sChargingID,pi->sChargingID,strlen(pi->sChargingID));
		strncpy(po->sGgsn,pi->sGgsn,strlen(pi->sGgsn));
		strncpy(po->sApnNi,pi->sApnNi,strlen(pi->sApnNi));
		strncpy(po->sApnOi,pi->sApnOi,strlen(pi->sApnOi));
		strncpy(po->sPdpType,pi->sPdpType,strlen(pi->sPdpType));
		strncpy(po->sServedPdpAddress,pi->sServedPdpAddress,strlen(pi->sServedPdpAddress));
		strncpy(po->sSgsnChange,pi->sSgsnChange,strlen(pi->sSgsnChange));
		strncpy(po->sCloseCause,pi->sCloseCause,strlen(pi->sCloseCause));
		strncpy(po->sResult,pi->sResult,strlen(pi->sResult));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sVisitAreaCode,pi->sVisitAreaCode,strlen(pi->sVisitAreaCode));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sFeeType,pi->sFeeType,strlen(pi->sFeeType));
		strncpy(po->sRoamType,pi->sRoamType,strlen(pi->sRoamType));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sCallDuration,pi->sCallDuration,strlen(pi->sCallDuration));
		strncpy(po->sTariff1,pi->sTariff1,strlen(pi->sTariff1));
		strncpy(po->sDataFlowup1,pi->sDataFlowup1,strlen(pi->sDataFlowup1));
		strncpy(po->sDataFlowdn1,pi->sDataFlowdn1,strlen(pi->sDataFlowdn1));
		strncpy(po->sDuration1,pi->sDuration1,strlen(pi->sDuration1));
		strncpy(po->sTariff2,pi->sTariff2,strlen(pi->sTariff2));
		strncpy(po->sDataFlowup2,pi->sDataFlowup2,strlen(pi->sDataFlowup2));
		strncpy(po->sDataFlowdn2,pi->sDataFlowdn2,strlen(pi->sDataFlowdn2));
		strncpy(po->sDuration2,pi->sDuration2,strlen(pi->sDuration2));
		strncpy(po->sTariff3,pi->sTariff3,strlen(pi->sTariff3));
		strncpy(po->sDataFlowup3,pi->sDataFlowup3,strlen(pi->sDataFlowup3));
		strncpy(po->sDataFlowdn3,pi->sDataFlowdn3,strlen(pi->sDataFlowdn3));
		strncpy(po->sDuration3,pi->sDuration3,strlen(pi->sDuration3));
		strncpy(po->sTariff4,pi->sTariff4,strlen(pi->sTariff4));
		strncpy(po->sDataFlowup4,pi->sDataFlowup4,strlen(pi->sDataFlowup4));
		strncpy(po->sDataFlowdn4,pi->sDataFlowdn4,strlen(pi->sDataFlowdn4));
		strncpy(po->sDuration4,pi->sDuration4,strlen(pi->sDuration4));
		strncpy(po->sTariff5,pi->sTariff5,strlen(pi->sTariff5));
		strncpy(po->sDataFlowup5,pi->sDataFlowup5,strlen(pi->sDataFlowup5));
		strncpy(po->sDataFlowdn5,pi->sDataFlowdn5,strlen(pi->sDataFlowdn5));
		strncpy(po->sDuration5,pi->sDuration5,strlen(pi->sDuration5));
		strncpy(po->sTariff6,pi->sTariff6,strlen(pi->sTariff6));
		strncpy(po->sDataFlowup6,pi->sDataFlowup6,strlen(pi->sDataFlowup6));
		strncpy(po->sDataFlowdn6,pi->sDataFlowdn6,strlen(pi->sDataFlowdn6));
		strncpy(po->sDuration6,pi->sDuration6,strlen(pi->sDuration6));
		strncpy(po->sCfee,pi->sCfee,strlen(pi->sCfee));
		strncpy(po->sFee1,pi->sFee1,strlen(pi->sFee1));
		strncpy(po->sFee2,pi->sFee2,strlen(pi->sFee2));
		strncpy(po->sFee3,pi->sFee3,strlen(pi->sFee3));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));

		sprintf(po->sTicketTypeID,"%04d",pi->iTicketTypeID);

		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));

}
void mvitem_mfcdma1xticket(struct Cdma1xTicketStruct *pi,struct FCdma1xTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FCdma1xTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sSeqNumber,pi->sSeqNumber,strlen(pi->sSeqNumber));
		strncpy(po->sMdn,pi->sMdn,strlen(pi->sMdn));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sEsn,pi->sEsn,strlen(pi->sEsn));
		strncpy(po->sIp,pi->sIp,strlen(pi->sIp));
		strncpy(po->sNai,pi->sNai,strlen(pi->sNai));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sNaiAreaCode,pi->sNaiAreaCode,strlen(pi->sNaiAreaCode));
		strncpy(po->sRoamType,pi->sRoamType,strlen(pi->sRoamType));
		strncpy(po->sIpTechType,pi->sIpTechType,strlen(pi->sIpTechType));
		strncpy(po->sAccountSessionID,pi->sAccountSessionID,strlen(pi->sAccountSessionID));
		strncpy(po->sCorrelationID,pi->sCorrelationID,strlen(pi->sCorrelationID));
		strncpy(po->sHaip,pi->sHaip,strlen(pi->sHaip));
		strncpy(po->sPdsnip,pi->sPdsnip,strlen(pi->sPdsnip));
		strncpy(po->sPcfip,pi->sPcfip,strlen(pi->sPcfip));
		strncpy(po->sBsid,pi->sBsid,strlen(pi->sBsid));
		strncpy(po->sUzid,pi->sUzid,strlen(pi->sUzid));
		strncpy(po->sServiceOption,pi->sServiceOption,strlen(pi->sServiceOption));
		strncpy(po->sCompulsoryTunnel,pi->sCompulsoryTunnel,strlen(pi->sCompulsoryTunnel));
		strncpy(po->sEndRelease,pi->sEndRelease,strlen(pi->sEndRelease));
		strncpy(po->sDataCountTermination,pi->sDataCountTermination,strlen(pi->sDataCountTermination));
		strncpy(po->sDataCountOrigination,pi->sDataCountOrigination,strlen(pi->sDataCountOrigination));
		strncpy(po->sBadFrameCount,pi->sBadFrameCount,strlen(pi->sBadFrameCount));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sStopTime,pi->sStopTime,strlen(pi->sStopTime));
		strncpy(po->sActiveTime,pi->sActiveTime,strlen(pi->sActiveTime));
		strncpy(po->sActionCount,pi->sActionCount,strlen(pi->sActionCount));
		strncpy(po->sSdbCountTermination,pi->sSdbCountTermination,strlen(pi->sSdbCountTermination));
		strncpy(po->sSdbCountOrigination,pi->sSdbCountOrigination,strlen(pi->sSdbCountOrigination));
		strncpy(po->sSdbTerminationnum,pi->sSdbTerminationnum,strlen(pi->sSdbTerminationnum));
		strncpy(po->sSdbOriginationnum,pi->sSdbOriginationnum,strlen(pi->sSdbOriginationnum));
		strncpy(po->sPdsnReceiveNum,pi->sPdsnReceiveNum,strlen(pi->sPdsnReceiveNum));
		strncpy(po->sMipReceiveNum,pi->sMipReceiveNum,strlen(pi->sMipReceiveNum));
		strncpy(po->sMipSendNum,pi->sMipSendNum,strlen(pi->sMipSendNum));
		strncpy(po->sIpqos,pi->sIpqos,strlen(pi->sIpqos));
		strncpy(po->sAirlinkqos,pi->sAirlinkqos,strlen(pi->sAirlinkqos));

		sprintf(sTemp,"%08d",pi->iBaseCharge);
		strncpy(po->sBaseCharge,sTemp,8);
		sprintf(sTemp,"%08d",pi->iFluxCharge);
		strncpy(po->sFluxCharge,sTemp,8);
		sprintf(sTemp,"%08d",pi->iOtherCharge);
		strncpy(po->sOtherCharge,sTemp,8);

		strncpy(po->sHomeCountryCode,pi->sHomeCountryCode,strlen(pi->sHomeCountryCode));
		strncpy(po->sHomeOperatorCode,pi->sHomeOperatorCode,strlen(pi->sHomeOperatorCode));
		strncpy(po->sVisitCountryCode,pi->sVisitCountryCode,strlen(pi->sVisitCountryCode));
		strncpy(po->sVisitOperatoCode,pi->sVisitOperatoCode,strlen(pi->sVisitOperatoCode));
		strncpy(po->sRatingRuleID,pi->sRatingRuleID,strlen(pi->sRatingRuleID));
		strncpy(po->sNoused1,pi->sNoused1,strlen(pi->sNoused1));
		strncpy(po->sNoused2,pi->sNoused2,strlen(pi->sNoused2));
		strncpy(po->sNoused3,pi->sNoused3,strlen(pi->sNoused3));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}

void mvitem_mfinfoacct(struct InfoAcctStruct *pi,struct FInfoAcctStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FInfoAcctStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sProvinceID,pi->sProvinceID,strlen(pi->sProvinceID));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));

		sprintf(sTemp,"%09d",pi->iTotalCnt);
		strncpy(po->sTotalCnt,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalFee);
		strncpy(po->sTotalFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iValidCnt);
		strncpy(po->sValidCnt,sTemp,9);
		sprintf(sTemp,"%09d",pi->iValidFee);
		strncpy(po->sValidFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iInvalidCnt);
		strncpy(po->sInvalidCnt,sTemp,9);

		strncpy(po->sInvalidFee,pi->sInvalidFee,strlen(pi->sInvalidFee));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));

		sprintf(sTemp,"%09d",pi->iFee);
		strncpy(po->sFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iOweFee);
		strncpy(po->sOweFee,sTemp,9);

}
void mvitem_mficcticket(struct IccTicketStruct *pi,struct FIccTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FIccTicketStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sProvinceCode,pi->sProvinceCode,strlen(pi->sProvinceCode));
		strncpy(po->sCallAreaCode,pi->sCallAreaCode,strlen(pi->sCallAreaCode));
		strncpy(po->sCardID,pi->sCardID,strlen(pi->sCardID));
		strncpy(po->sCardProvinceCode,pi->sCardProvinceCode,strlen(pi->sCardProvinceCode));
		strncpy(po->sCardAreaCode,pi->sCardAreaCode,strlen(pi->sCardAreaCode));
		strncpy(po->sCardAreaID,pi->sCardAreaID,strlen(pi->sCardAreaID));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));

		sprintf(sTemp,"%09d",pi->iDuration);
		strncpy(po->sDuration,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalFee);
		strncpy(po->sTotalFee,sTemp,9);

		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sDistanceType,pi->sDistanceType,strlen(pi->sDistanceType));

}
void mvitem_mfznwticket(struct ZnwTicketStruct *pi,struct FZnwTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FZnwTicketStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
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

		sprintf(sTemp,"%09d",pi->iDuration);
		strncpy(po->sDuration,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalFee);
		strncpy(po->sTotalFee,sTemp,9);

		strncpy(po->sBearCapability,pi->sBearCapability,strlen(pi->sBearCapability));
		strncpy(po->sTariffClass,pi->sTariffClass,strlen(pi->sTariffClass));
		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sUserID,pi->sUserID,strlen(pi->sUserID));
		strncpy(po->sServiceNbr,pi->sServiceNbr,strlen(pi->sServiceNbr));

		sprintf(sTemp,"%08d",pi->iCount);
		strncpy(po->sCount,sTemp,8);
		sprintf(sTemp,"%09d",pi->iBaseFee);
		strncpy(po->sBaseFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iBountyFee);
		strncpy(po->sBountyFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iAddFee);
		strncpy(po->sAddFee,sTemp,9);

		strncpy(po->sTransParam,pi->sTransParam,strlen(pi->sTransParam));
		strncpy(po->sCallparttobecharger,pi->sCallparttobecharger,strlen(pi->sCallparttobecharger));
		strncpy(po->sScpID,pi->sScpID,strlen(pi->sScpID));
		strncpy(po->sCauseOfCallend,pi->sCauseOfCallend,strlen(pi->sCauseOfCallend));
		strncpy(po->sServiceModulator,pi->sServiceModulator,strlen(pi->sServiceModulator));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sCardID,pi->sCardID,strlen(pi->sCardID));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sCalledCode,pi->sCalledCode,strlen(pi->sCalledCode));
		strncpy(po->sBillingAreaCode,pi->sBillingAreaCode,strlen(pi->sBillingAreaCode));
		strncpy(po->sCardAreaCode,pi->sCardAreaCode,strlen(pi->sCardAreaCode));
		strncpy(po->sDistanceType,pi->sDistanceType,strlen(pi->sDistanceType));
		strncpy(po->sOriFileName,pi->sOriFileName,strlen(pi->sOriFileName));

}

void mvitem_mfsmgticket(struct SmgTicketStruct *pi,struct FSmgTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmgTicketStruct));

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

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

}
void mvitem_mfsmsupintfticket(struct SmsupIntfTicketStruct *pi,struct FSmsupIntfTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmsupIntfTicketStruct));

		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sMsgType,pi->sMsgType,strlen(pi->sMsgType));

		sprintf(sTemp,"%03d",pi->iSpProvCode);
		strncpy(po->sSpProvCode,sTemp,3);
		sprintf(sTemp,"%05d",pi->iSmg);
		strncpy(po->sSmg,sTemp,5);
		sprintf(sTemp,"%05d",pi->iSpCode);
		strncpy(po->sSpCode,sTemp,5);
		sprintf(sTemp,"%05d",pi->iFwSmg);
		strncpy(po->sFwSmg,sTemp,5);
		sprintf(sTemp,"%03d",pi->iFwSmgProv);
		strncpy(po->sFwSmgProv,sTemp,3);

		strncpy(po->sMinStartTime,pi->sMinStartTime,strlen(pi->sMinStartTime));
		strncpy(po->sMaxStartTime,pi->sMaxStartTime,strlen(pi->sMaxStartTime));

		LeftPad(pi->sMoCnt1,10,'0');
		LeftPad(pi->sMoCnt2,10,'0');
		LeftPad(pi->sMfCnt1,10,'0');
		LeftPad(pi->sMfCnt2,10,'0');
		LeftPad(pi->sFee1,12,'0');
		LeftPad(pi->sFee2,12,'0');
		strncpy(po->sMoCnt1,pi->sMoCnt1,10);
		strncpy(po->sMoCnt2,pi->sMoCnt2,10);
		strncpy(po->sMfCnt1,pi->sMfCnt1,10);
		strncpy(po->sMfCnt2,pi->sMfCnt2,10);
		strncpy(po->sFee1,pi->sFee1,12);
		strncpy(po->sFee2,pi->sFee2,12);

		sprintf(sTemp,"%03d",pi->iHomeProvCode);
		strncpy(po->sHomeProvCode,sTemp,3);

		LeftPad(pi->sRoamFee1 ,10,'0');
		LeftPad(pi->sRoamFee2 ,10,'0');
		LeftPad(pi->sInfoFee1 ,10,'0');
		LeftPad(pi->sInfoFee2 ,10,'0');

		/*负数补0处理*/
		sprintf(sTemp,"%010d",atoi(pi->sRoamNfee1));
		strcpy(pi->sRoamNfee1,sTemp);
		sprintf(sTemp,"%010d",atoi(pi->sRoamNfee2));
		strcpy(pi->sRoamNfee2,sTemp);

		strncpy(po->sRoamFee1, pi->sRoamFee1 ,10);
		strncpy(po->sRoamFee2, pi->sRoamFee2 ,10);
		strncpy(po->sInfoFee1, pi->sInfoFee1 ,10);
		strncpy(po->sInfoFee2, pi->sInfoFee2 ,10);
		strncpy(po->sRoamNfee1,pi->sRoamNfee1,10);
		strncpy(po->sRoamNfee2,pi->sRoamNfee2,10);
		strncpy(po->sReserve1, pi->sReserve1 ,strlen(pi->sReserve1));
}

void mvitem_mfsmsticket(struct SmsTicketStruct *pi,struct FSmsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmsTicketStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sCalledCode,pi->sCalledCode,strlen(pi->sCalledCode));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));

		sprintf(sTemp,"%04d",pi->iMsgLen);
		strncpy(po->sMsgLen,sTemp,4);

		strncpy(po->sMsgID,pi->sMsgID,strlen(pi->sMsgID));
		strncpy(po->sSmsc,pi->sSmsc,strlen(pi->sSmsc));
		strncpy(po->sSmg,pi->sSmg,strlen(pi->sSmg));
		strncpy(po->sTsmg,pi->sTsmg,strlen(pi->sTsmg));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sCalledType,pi->sCalledType,strlen(pi->sCalledType));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));

		sprintf(sTemp,"%08d",pi->iBaseFee);
		strncpy(po->sBaseFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iInfoFee);
		strncpy(po->sInfoFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iRentFee);
		strncpy(po->sRentFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iOtherFee);
		strncpy(po->sOtherFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iInFee);
		strncpy(po->sInFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iOutFee);
		strncpy(po->sOutFee,sTemp,8);

		strncpy(po->sOriCallType,pi->sOriCallType,strlen(pi->sOriCallType));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

		strncpy(po->sSpProvCode,pi->sSpProvCode,strlen(pi->sSpProvCode));
		strncpy(po->sHomeProvCode,pi->sHomeProvCode,strlen(pi->sHomeProvCode));
		strncpy(po->sScpFlag,pi->sScpFlag,strlen(pi->sScpFlag));
		sprintf(sTemp,"%04d",pi->iCallingTypeID);
		strncpy(po->sCallingTypeID,sTemp,4);
		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));


		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}

void mvitem_mfnsmsticket(struct NsmsTicketStruct *pi,struct FNsmsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FNsmsTicketStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sCalledCode,pi->sCalledCode,strlen(pi->sCalledCode));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));

		sprintf(sTemp,"%04d",pi->iMsgLen);
		strncpy(po->sMsgLen,sTemp,4);

		strncpy(po->sMsgID,pi->sMsgID,strlen(pi->sMsgID));
		strncpy(po->sOppMsgID,pi->sOppMsgID,strlen(pi->sOppMsgID));
		strncpy(po->sSubType,pi->sSubType,strlen(pi->sSubType));
		strncpy(po->sSmsc,pi->sSmsc,strlen(pi->sSmsc));
		strncpy(po->sSmg,pi->sSmg,strlen(pi->sSmg));
		strncpy(po->sTsmg,pi->sTsmg,strlen(pi->sTsmg));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sCalledType,pi->sCalledType,strlen(pi->sCalledType));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));

		sprintf(sTemp,"%08d",pi->iBaseFee);
		strncpy(po->sBaseFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iInfoFee);
		strncpy(po->sInfoFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iRentFee);
		strncpy(po->sRentFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iOtherFee);
		strncpy(po->sOtherFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iInFee);
		strncpy(po->sInFee,sTemp,8);
		sprintf(sTemp,"%08d",pi->iOutFee);
		strncpy(po->sOutFee,sTemp,8);

		strncpy(po->sOriCallType,pi->sOriCallType,strlen(pi->sOriCallType));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));
		strncpy(po->sSpProvCode,pi->sSpProvCode,strlen(pi->sSpProvCode));
		strncpy(po->sHomeProvCode,pi->sHomeProvCode,strlen(pi->sHomeProvCode));
		strncpy(po->sScpFlag,pi->sScpFlag,strlen(pi->sScpFlag));

		sprintf(sTemp,"%04d",pi->iCallingTypeID);
		strncpy(po->sCallingTypeID,sTemp,4);

		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));

}

void mvitem_mfsmcdmaticket(struct SmcdmaTicketStruct *pi,struct FSmcdmaTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmcdmaTicketStruct));

		strncpy(po->sRecNo,pi->sRecNo,strlen(pi->sRecNo));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sRegisterTime,pi->sRegisterTime,strlen(pi->sRegisterTime));
		strncpy(po->sSendTime,pi->sSendTime,strlen(pi->sSendTime));

		sprintf(sTemp,"%03d",pi->iMsgLen);
		strncpy(po->sMsgLen,sTemp,3);

		strncpy(po->sLastStatus,pi->sLastStatus,strlen(pi->sLastStatus));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sLandType,pi->sLandType,strlen(pi->sLandType));
		strncpy(po->sPriority,pi->sPriority,strlen(pi->sPriority));

}

void mvitem_mfsmgsmticket(struct SmgsmTicketStruct *pi,struct FSmgsmTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmgsmTicketStruct));

		strncpy(po->sReqNo,pi->sReqNo,strlen(pi->sReqNo));
		strncpy(po->sMsgID,pi->sMsgID,strlen(pi->sMsgID));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCallingTon,pi->sCallingTon,strlen(pi->sCallingTon));
		strncpy(po->sCallingNpi,pi->sCallingNpi,strlen(pi->sCallingNpi));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sCalledTon,pi->sCalledTon,strlen(pi->sCalledTon));
		strncpy(po->sCalledNpi,pi->sCalledNpi,strlen(pi->sCalledNpi));
		strncpy(po->sRegisterTime,pi->sRegisterTime,strlen(pi->sRegisterTime));
		strncpy(po->sSendTime,pi->sSendTime,strlen(pi->sSendTime));
		strncpy(po->sPriority,pi->sPriority,strlen(pi->sPriority));
		strncpy(po->sSsr,pi->sSsr,strlen(pi->sSsr));
		strncpy(po->sPid,pi->sPid,strlen(pi->sPid));
		strncpy(po->sDcs,pi->sDcs,strlen(pi->sDcs));

		sprintf(sTemp,"%03d",pi->iMsgLen);
		strncpy(po->sMsgLen,sTemp,3);

		strncpy(po->sLastStatus,pi->sLastStatus,strlen(pi->sLastStatus));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sMsgType,pi->sMsgType,strlen(pi->sMsgType));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sPpsFlag,pi->sPpsFlag,strlen(pi->sPpsFlag));
		strncpy(po->sOrgAccount,pi->sOrgAccount,strlen(pi->sOrgAccount));
		strncpy(po->sDestAccount,pi->sDestAccount,strlen(pi->sDestAccount));
		strncpy(po->sRightResult,pi->sRightResult,strlen(pi->sRightResult));
		strncpy(po->sUdhi,pi->sUdhi,strlen(pi->sUdhi));
		strncpy(po->sMr,pi->sMr,strlen(pi->sMr));
		strncpy(po->sRn,pi->sRn,strlen(pi->sRn));
		strncpy(po->sMn,pi->sMn,strlen(pi->sMn));
		strncpy(po->sSn,pi->sSn,strlen(pi->sSn));

}
void mvitem_mfsmmobticket(struct SmmobTicketStruct *pi,struct FSmmobTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmmobTicketStruct));

		strncpy(po->sRegNo,pi->sRegNo,strlen(pi->sRegNo));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sLastStatus,pi->sLastStatus,strlen(pi->sLastStatus));

		sprintf(sTemp,"%03d",pi->iMsgLen);
		strncpy(po->sMsgLen,sTemp,3);

		strncpy(po->sSmg,pi->sSmg,strlen(pi->sSmg));
		strncpy(po->sTsmg,pi->sTsmg,strlen(pi->sTsmg));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sSmsc,pi->sSmsc,strlen(pi->sSmsc));
		strncpy(po->sRegisterTime,pi->sRegisterTime,strlen(pi->sRegisterTime));
		strncpy(po->sSendTime,pi->sSendTime,strlen(pi->sSendTime));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}

void mvitem_mfsmtelticket(struct SmtelTicketStruct *pi,struct FSmtelTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmtelTicketStruct));

		strncpy(po->sRegNo,pi->sRegNo,strlen(pi->sRegNo));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sCityCode,pi->sCityCode,strlen(pi->sCityCode));
		strncpy(po->sLastStatus,pi->sLastStatus,strlen(pi->sLastStatus));

		sprintf(sTemp,"%03d",pi->iMsgLen);
		strncpy(po->sMsgLen,sTemp,3);

		strncpy(po->sSmg,pi->sSmg,strlen(pi->sSmg));
		strncpy(po->sTsmg,pi->sTsmg,strlen(pi->sTsmg));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sSmsc,pi->sSmsc,strlen(pi->sSmsc));
		strncpy(po->sRegisterTime,pi->sRegisterTime,strlen(pi->sRegisterTime));
		strncpy(po->sSendTime,pi->sSendTime,strlen(pi->sSendTime));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}
void mvitem_mfsmsp1ticket(struct Smsp1TicketStruct *pi,struct FSmsp1TicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmsp1TicketStruct));

		strncpy(po->sRegNo,pi->sRegNo,strlen(pi->sRegNo));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpHomeSmg,pi->sSpHomeSmg,strlen(pi->sSpHomeSmg));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sBillingType,pi->sBillingType,strlen(pi->sBillingType));

		sprintf(sTemp,"%06d",pi->iInfoFee);
		strncpy(po->sInfoFee,sTemp,6);
		sprintf(sTemp,"%06d",pi->iRentFee);
		strncpy(po->sRentFee,sTemp,6);
		sprintf(sTemp,"%06d",pi->iReturnFee);
		strncpy(po->sReturnFee,sTemp,6);

		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sMoFlag,pi->sMoFlag,strlen(pi->sMoFlag));
		strncpy(po->sLastStatus,pi->sLastStatus,strlen(pi->sLastStatus));
		strncpy(po->sPriority,pi->sPriority,strlen(pi->sPriority));

		sprintf(sTemp,"%02d",pi->iMsgCnt);
		strncpy(po->sMsgCnt,sTemp,2);

		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sSmg,pi->sSmg,strlen(pi->sSmg));
		strncpy(po->sTsmg,pi->sTsmg,strlen(pi->sTsmg));
		strncpy(po->sSmsc,pi->sSmsc,strlen(pi->sSmsc));
		strncpy(po->sRegisterTime,pi->sRegisterTime,strlen(pi->sRegisterTime));
		strncpy(po->sSendTime,pi->sSendTime,strlen(pi->sSendTime));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}

void mvitem_mfs1xfjticket(struct Sp1xfjTicketStruct *pi,struct FSp1xfjTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FSp1xfjTicketStruct));

		strncpy(po->sSeqNumber,pi->sSeqNumber,strlen(pi->sSeqNumber));
		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpLoginName,pi->sSpLoginName,strlen(pi->sSpLoginName));
		strncpy(po->sMsIpAddress,pi->sMsIpAddress,strlen(pi->sMsIpAddress));
		strncpy(po->sSpSrvType,pi->sSpSrvType,strlen(pi->sSpSrvType));
		strncpy(po->sSpSrvTypeName,pi->sSpSrvTypeName,strlen(pi->sSpSrvTypeName));
		strncpy(po->sSpServiceType,pi->sSpServiceType,strlen(pi->sSpServiceType));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sSpServiceName,pi->sSpServiceName,strlen(pi->sSpServiceName));
		strncpy(po->sContentCode,pi->sContentCode,strlen(pi->sContentCode));
		strncpy(po->sContentName,pi->sContentName,strlen(pi->sContentName));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sNai,pi->sNai,strlen(pi->sNai));
		strncpy(po->sNaiDomain,pi->sNaiDomain,strlen(pi->sNaiDomain));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sStopTime,pi->sStopTime,strlen(pi->sStopTime));
		strncpy(po->sActionCount,pi->sActionCount,strlen(pi->sActionCount));
		strncpy(po->sActiveTime,pi->sActiveTime,strlen(pi->sActiveTime));
		strncpy(po->sDataCountTermination,pi->sDataCountTermination,strlen(pi->sDataCountTermination));
		strncpy(po->sDataCountOrigination,pi->sDataCountOrigination,strlen(pi->sDataCountOrigination));
		strncpy(po->sDataCountTotal,pi->sDataCountTotal,strlen(pi->sDataCountTotal));
		strncpy(po->sPreDiscntFee,pi->sPreDiscntFee,strlen(pi->sPreDiscntFee));
		strncpy(po->sPostDiscntFee,pi->sPostDiscntFee,strlen(pi->sPostDiscntFee));
		strncpy(po->sDiscntFee,pi->sDiscntFee,strlen(pi->sDiscntFee));
		strncpy(po->sRateUnit,pi->sRateUnit,strlen(pi->sRateUnit));
		strncpy(po->sFeeType,pi->sFeeType,strlen(pi->sFeeType));
		strncpy(po->sFeeRateDescCode,pi->sFeeRateDescCode,strlen(pi->sFeeRateDescCode));
		strncpy(po->sDiscntDescCode,pi->sDiscntDescCode,strlen(pi->sDiscntDescCode));
		strncpy(po->sUrl,pi->sUrl,strlen(pi->sUrl));
		strncpy(po->sSysID,pi->sSysID,strlen(pi->sSysID));
		strncpy(po->sSysIntraKey,pi->sSysIntraKey,strlen(pi->sSysIntraKey));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sNoused1,pi->sNoused1,strlen(pi->sNoused1));
		strncpy(po->sNoused2,pi->sNoused2,strlen(pi->sNoused2));
		strncpy(po->sNoused3,pi->sNoused3,strlen(pi->sNoused3));
		strncpy(po->sNoused4,pi->sNoused4,strlen(pi->sNoused4));

}

void mvitem_mfsspfjticket(struct SmspfjTicketStruct *pi,struct FSmspfjTicketStruct *po)
{/*内存数据移动到文件记录到部分*/

	memset((void*)po,' ',sizeof(struct FSmspfjTicketStruct));

		strncpy(po->sBusiType,pi->sBusiType,strlen(pi->sBusiType));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		strncpy(po->sCalledNbr,pi->sCalledNbr,strlen(pi->sCalledNbr));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sFeeType,pi->sFeeType,strlen(pi->sFeeType));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sCnt,pi->sCnt,strlen(pi->sCnt));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sBaseFee,pi->sBaseFee,strlen(pi->sBaseFee));
		strncpy(po->sInfoFee,pi->sInfoFee,strlen(pi->sInfoFee));
		strncpy(po->sRentFee,pi->sRentFee,strlen(pi->sRentFee));
		strncpy(po->sInfoFeeType,pi->sInfoFeeType,strlen(pi->sInfoFeeType));
		strncpy(po->sOriFileName,pi->sOriFileName,strlen(pi->sOriFileName));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}

void mvitem_mfsmspnbrstat(struct RSmspNbrStatStruct *pi,struct FSmspNbrStatStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmspNbrStatStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));

		sprintf(sTemp,"%09d",pi->iTotalFee);
		strncpy(po->sTotalFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalInfoFee);
		strncpy(po->sTotalInfoFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalCommFee);
		strncpy(po->sTotalCommFee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalRentFee);
		strncpy(po->sTotalRentFee,sTemp,9);

		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,strlen(pi->sSpAccNbr));

		sprintf(sTemp,"%06d",pi->iMoCnt);
		strncpy(po->sMoCnt,sTemp,6);
		sprintf(sTemp,"%06d",pi->iMtCnt);
		strncpy(po->sMtCnt,sTemp,6);
		sprintf(sTemp,"%06d",pi->iTotalCnt);
		strncpy(po->sTotalCnt,sTemp,6);

		strncpy(po->sMinStartTime,pi->sMinStartTime,strlen(pi->sMinStartTime));
		strncpy(po->sMaxStartTime,pi->sMaxStartTime,strlen(pi->sMaxStartTime));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sCreatedDate,pi->sCreatedDate,strlen(pi->sCreatedDate));
		strncpy(po->sUpdatedDate,pi->sUpdatedDate,strlen(pi->sUpdatedDate));

}

/**对表SP_ACCT_ITEM的链表释放函数**/
void DestroySpAcctItem(struct SpAcctItemStruct *ptHead)
{
	struct SpAcctItemStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSpAcctItem(struct SpAcctItemStruct **pptHead,char sInputTable[])
{
	int iCnt=0;
	static struct SpAcctItemStruct *pTemp,*ptHead=NULL;
	struct SpAcctItemStruct Temp;
	struct SpAcctItemStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySpAcctItem(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SpAcctItemStructIn));
	strcpy(TempIn.sTableName,sInputTable);
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSpAcctItemToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SpAcctItemStruct*)
			malloc(sizeof(struct SpAcctItemStruct)))==NULL){

			DestroySpAcctItem(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		Fmt86A13(Temp.sMsisdn);
		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SpAcctItemStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SP_ACCT_ITEM记录数%d",iCnt);
	}

	WriteProcMsg("加载表SP_ACCT_ITEM完毕总记录数%d",iCnt);

	return iCnt;
}
void mvitem_mfspacctitem(struct SpAcctItemStruct *pi,struct FSpAcctItemStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSpAcctItemStruct));

		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sPayCycleID,pi->sPayCycleID,strlen(pi->sPayCycleID));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpServiceCode,pi->sSpServiceCode,strlen(pi->sSpServiceCode));
		strncpy(po->sCharge,pi->sCharge,strlen(pi->sCharge));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sPayTime,pi->sPayTime,strlen(pi->sPayTime));

}

int SttTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SttTicketStruct Temp;
	static struct SttTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSttTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsttticket(&Temp,(struct FSttTicketStruct*)sTemp);
	sTemp[sizeof(struct FSttTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
int SmscTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmscTicketStruct Temp;
	static struct SmscTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmscTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmscticket(&Temp,(struct FSmscTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmscTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);

	return true;
}
int SmspTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmspTicketStruct Temp;
	static struct SmspTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmspTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmspticket(&Temp,(struct FSmspTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmspTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);

	return true;
}
int GprsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct GprsTicketStruct Temp;
	static struct GprsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetGprsTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfgprsticket(&Temp,(struct FGprsTicketStruct*)sTemp);
	sTemp[sizeof(struct FGprsTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
int SmsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmsTicketStruct Temp;
	static struct SmsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmsTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmsticket(&Temp,(struct FSmsTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmsTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
int NsmsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct NsmsTicketStruct Temp;
	static struct NsmsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetNsmsTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfnsmsticket(&Temp,(struct FNsmsTicketStruct*)sTemp);
	sTemp[sizeof(struct FNsmsTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
int PrepTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct PrepTicketStruct Temp;
	static struct PrepTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetPrepTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfprepticket(&Temp,(struct FPrepTicketStruct*)sTemp);
	sTemp[sizeof(struct FPrepTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);

	return true;
}
int Cdma1xTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct Cdma1xTicketStruct Temp;
	static struct Cdma1xTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetCdma1xTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfcdma1xticket(&Temp,(struct FCdma1xTicketStruct*)sTemp);
	sTemp[sizeof(struct FCdma1xTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}

int IccTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct IccTicketStruct Temp;
	static struct IccTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetIccTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mficcticket(&Temp,(struct FIccTicketStruct*)sTemp);
	sTemp[sizeof(struct FIccTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
int ZnwTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct ZnwTicketStruct Temp;
	static struct ZnwTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetZnwTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfznwticket(&Temp,(struct FZnwTicketStruct*)sTemp);
	sTemp[sizeof(struct FZnwTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
int SmgTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmgTicketStruct Temp;
	static struct SmgTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmgTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmgticket(&Temp,(struct FSmgTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmgTicketStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
int InfoAcct2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct InfoAcctStruct Temp;
	static struct InfoAcctStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetInfoAcctToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfinfoacct(&Temp,(struct FInfoAcctStruct*)sTemp);
	sTemp[sizeof(struct FInfoAcctStruct)]=0;
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
/**短信导成字符串函数支持**/
int SmcdmaTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmcdmaTicketStruct Temp;
	static struct SmcdmaTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmcdmaTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmcdmaticket(&Temp,(struct FSmcdmaTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmcdmaTicketStruct)]=0;
	strcpy(sSourceID,"SMCDMA");
	strcpy(sRowID,	"");
	return true;
}
int SmgsmTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmgsmTicketStruct Temp;
	static struct SmgsmTicketStructIn TempIn;

	struct SmgsmTicketStruct *p;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmgsmTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
/*	mvitem_mfsmgsmticket(&Temp,(struct FSmgsmTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmgsmTicketStruct)]=0;*/

	p=(struct SmgsmTicketStruct *)&Temp;

	sprintf(sTemp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,\
%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",
		p->sReqNo,
		p->sMsgID,
		p->sCallingNbr,
		p->sCallingTon,
		p->sCallingNpi,
		p->sCalledNbr,
		p->sCalledTon,
		p->sCalledNpi,
		p->sRegisterTime,
		p->sSendTime,
		p->sPriority,
		p->sSsr,
		p->sPid,
		p->sDcs,
		p->iMsgLen,
		p->sLastStatus,
		p->sErrCode,
		p->sMsgType,
		p->sServiceType,
		p->sPpsFlag,
		p->sOrgAccount,
		p->sDestAccount,
		p->sRightResult,
		p->sUdhi,
		p->sMr,
		p->sRn,
		p->sMn,
		p->sSn);

	strcpy(sSourceID,"SMGSM");
	strcpy(sRowID,	"");
	return true;
}
int SmmobTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmmobTicketStruct Temp;
	static struct SmmobTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmmobTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmmobticket(&Temp,(struct FSmmobTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmmobTicketStruct)]=0;
	strcpy(sSourceID,"SMMOB");
	strcpy(sRowID,	"");
	return true;
}
int SmtelTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmtelTicketStruct Temp;
	static struct SmtelTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmtelTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmtelticket(&Temp,(struct FSmtelTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmtelTicketStruct)]=0;
	strcpy(sSourceID,"SMTEL");
	strcpy(sRowID,	"");
	return true;
}
int Smsp1Ticket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct Smsp1TicketStruct Temp;
	static struct Smsp1TicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmsp1TicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmsp1ticket(&Temp,(struct FSmsp1TicketStruct*)sTemp);
	sTemp[sizeof(struct FSmsp1TicketStruct)]=0;
	strcpy(sSourceID,"SMSP1");
	strcpy(sRowID,	"");
	return true;
}

int Sp1xfjTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct Sp1xfjTicketStruct Temp;
	static struct Sp1xfjTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSp1xfjTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfs1xfjticket(&Temp,(struct FSp1xfjTicketStruct*)sTemp);
	sTemp[sizeof(struct FSp1xfjTicketStruct)]=0;
	strcpy(sSourceID,"P1XFJ");
	strcpy(sRowID,	"");
	return true;
}

int SmspfjTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SmspfjTicketStruct Temp;
	static struct SmspfjTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmspfjTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsspfjticket(&Temp,(struct FSmspfjTicketStruct*)sTemp);
	sTemp[sizeof(struct FSmspfjTicketStruct)]=0;
	strcpy(sSourceID,"SMSPFJ");
	strcpy(sRowID,	"");
	return true;
}

int SmspNbrStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct RSmspNbrStatStruct Temp;
	static struct RSmspNbrStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSmspNbrStatToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfsmspnbrstat(&Temp,(struct FSmspNbrStatStruct*)sTemp);
	sTemp[sizeof(struct FSmspNbrStatStruct)]=0;
	strcpy(sSourceID,"SMSP01");
	strcpy(sRowID,	Temp.sRowID);
	return true;
}

int SpAcctItem2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct SpAcctItemStruct Temp;
	static struct SpAcctItemStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetSpAcctItemToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfspacctitem(&Temp,(struct FSpAcctItemStruct*)sTemp);
	sTemp[sizeof(struct FSpAcctItemStruct)]=0;
	strcpy(sSourceID,"ACSP01");
	/*strcpy(sRowID,	Temp.sRowID);*/
	return true;
}

void mvitem_mfservcard(struct ServCardStruct *pi,struct FServCardStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FServCardStruct));

		strncpy(po->sAccNbr,pi->sAccNbr,strlen(pi->sAccNbr));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
		strncpy(po->sAreaCodeName,pi->sAreaCodeName,strlen(pi->sAreaCodeName));
		strncpy(po->sAreaName,pi->sAreaName,strlen(pi->sAreaName));
		strncpy(po->sCustNane,pi->sCustNane,strlen(pi->sCustNane));

		sprintf(sTemp,"%04d",pi->iTypeID);
		strncpy(po->sTypeID,sTemp,4);

}

int MsisdnStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct MsisdnStatStruct Temp;
	static struct MsisdnStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetMsisdnStatToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfmsisdnstat(&Temp,(struct FMsisdnStatStruct*)sTemp);
	sTemp[sizeof(struct FMsisdnStatStruct)]=0;
	strcpy(sRowID,	Temp.sRowID);
	return true;
}
void mvitem_mfmsisdnstat(struct MsisdnStatStruct *pi,
	struct FMsisdnStatStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FMsisdnStatStruct));

		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));

		sprintf(sTemp,"%04d",pi->iAreaID);
		strncpy(po->sAreaID,sTemp,4);

		strncpy(po->sNetType,pi->sNetType,strlen(pi->sNetType));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));

		sprintf(sTemp,"%09d",pi->iTotalDuration);
		strncpy(po->sTotalDuration,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalMin);
		strncpy(po->sTotalMin,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalCnt);
		strncpy(po->sTotalCnt,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalFee1);
		strncpy(po->sTotalFee1,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalFee2);
		strncpy(po->sTotalFee2,sTemp,9);
		sprintf(sTemp,"%09d",pi->iTotalFee3);
		strncpy(po->sTotalFee3,sTemp,9);

		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));

}

void mvitem_mfsettday(struct SettDayStruct *pi,struct FSettDayStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettDayStruct));

		sprintf(sTemp,"%-8d",pi->iRecordNumber);
		strncpy(po->sRecordNumber,sTemp,8);

		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sCalledCode,pi->sCalledCode,strlen(pi->sCalledCode));
		strncpy(po->sStartDate,pi->sStartDate,strlen(pi->sStartDate));
		strncpy(po->sCallingCarrierID,pi->sCallingCarrierID,strlen(pi->sCallingCarrierID));
		strncpy(po->sCalledCarrierID,pi->sCalledCarrierID,strlen(pi->sCalledCarrierID));
		strncpy(po->sThirdCarrierID,pi->sThirdCarrierID,strlen(pi->sThirdCarrierID));
		strncpy(po->sSettCarrierID,pi->sSettCarrierID,strlen(pi->sSettCarrierID));
		strncpy(po->sSettType,pi->sSettType,strlen(pi->sSettType));
		strncpy(po->sRoamType,pi->sRoamType,strlen(pi->sRoamType));
		strncpy(po->sTariffType,pi->sTariffType,strlen(pi->sTariffType));
		strncpy(po->sCountyFlag,pi->sCountyFlag,strlen(pi->sCountyFlag));
		strncpy(po->sIpAccNbr,pi->sIpAccNbr,strlen(pi->sIpAccNbr));
		strncpy(po->sDurationCnt,pi->sDurationCnt,strlen(pi->sDurationCnt));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sSettCnt,pi->sSettCnt,strlen(pi->sSettCnt));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sCount,pi->sCount,strlen(pi->sCount));

}

void mvitem_mfcustcnt(struct CustCntStruct *pi,struct FCustCntStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FCustCntStruct));

		sprintf(sTemp,"%-8d",pi->iRecordNumber);
		strncpy(po->sRecordNumber,sTemp,8);

		strncpy(po->sStatMonth,pi->sStatMonth,strlen(pi->sStatMonth));
		strncpy(po->sOppCarrierID,pi->sOppCarrierID,strlen(pi->sOppCarrierID));

		sprintf(sTemp,"%8d",pi->iCustCnt);
		strncpy(po->sCustCnt,sTemp,8);
		sprintf(sTemp,"%8d",pi->iAddCustCnt);
		strncpy(po->sAddCustCnt,sTemp,8);

}

void mvitem_mfsettmonth(struct SettMonthStruct *pi,struct FSettMonthStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettMonthStruct));

		sprintf(sTemp,"%-8d",pi->iRecordNumber);
		strncpy(po->sRecordNumber,sTemp,8);

		strncpy(po->sVisitAreaCode,pi->sVisitAreaCode,strlen(pi->sVisitAreaCode));
		strncpy(po->sStatMonth,pi->sStatMonth,strlen(pi->sStatMonth));
		strncpy(po->sSettCarrierID,pi->sSettCarrierID,strlen(pi->sSettCarrierID));
		strncpy(po->sSettType,pi->sSettType,strlen(pi->sSettType));
		strncpy(po->sDurationCnt,pi->sDurationCnt,strlen(pi->sDurationCnt));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sSettCnt,pi->sSettCnt,strlen(pi->sSettCnt));
		strncpy(po->sTotalFee,pi->sTotalFee,strlen(pi->sTotalFee));
		strncpy(po->sCount,pi->sCount,strlen(pi->sCount));

}

void mvitem_mfsmsstatup(struct SmsStatUpStruct *pi,struct FSmsStatUpStruct *po)
{/*内存数据移动到文件记录到部分*/
	memset((void*)po,' ',sizeof(struct FSmsStatUpStruct));

		strncpy(po->sSettCapitalCode,pi->sSettCapitalCode,strlen(pi->sSettCapitalCode));
		strncpy(po->sBillType,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));
		strncpy(po->sSettAreaCode,pi->sSettAreaCode,strlen(pi->sSettAreaCode));
		strncpy(po->sCallingCarrierID,pi->sCallingCarrierID,strlen(pi->sCallingCarrierID));
		strncpy(po->sRecordType,pi->sRecordType,strlen(pi->sRecordType));
		strncpy(po->sCalledCapitalCode,pi->sCalledCapitalCode,strlen(pi->sCalledCapitalCode));
		strncpy(po->sCalledCarrierID,pi->sCalledCarrierID,strlen(pi->sCalledCarrierID));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		
		AllTrim(pi->sTotalCnt);
		sprintf(po->sTotalCnt,"%015ld",atol(pi->sTotalCnt));

		AllTrim(pi->sTotalFee);
		sprintf(po->sTotalFee,"%015ld",atol(pi->sTotalFee));

		strncpy(po->sFlag,pi->sFlag,strlen(pi->sFlag));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}

void mvitem_mfsmsstatuphead(struct SmsStatUpHeadStruct *pi,struct FSmsStatUpHeadStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSmsStatUpHeadStruct));

		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->CapitalCode,pi->CapitalCode,strlen(pi->CapitalCode));
		strncpy(po->sCreateDate,pi->sCreateDate,strlen(pi->sCreateDate));
		
		sprintf(sTemp,"%06d",pi->iFileCnt);
		strncpy(po->sFileCnt,sTemp,8);

		
		AllTrim(pi->sTotalCnt);
		sprintf(po->sTotalCnt,"%015ld",atol(pi->sTotalCnt));

		AllTrim(pi->sTotalFee);
		sprintf(po->sTotalFee,"%015ld",atol(pi->sTotalFee));

		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));

}



void mvitem_mfdownvoipstat(struct DownVoipStatStruct *pi,struct FDownVoipStatStruct *po)
{/*内存数据移动到文件记录到部分*/
/*	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FDownVoipStatStruct));

		strncpy(po->sCallingUserType,pi->sCallingUserType,strlen(pi->sCallingUserType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCout,pi->sOutCityCout,strlen(pi->sOutCityCout));
		strncpy(po->sTollFee1,pi->sTollFee1,strlen(pi->sTollFee1));
		strncpy(po->sDuration1,pi->sDuration1,strlen(pi->sDuration1));
		strncpy(po->sCnt1,pi->sCnt1,strlen(pi->sCnt1));
		strncpy(po->sTollFee2,pi->sTollFee2,strlen(pi->sTollFee2));
		strncpy(po->sDuration2,pi->sDuration2,strlen(pi->sDuration2));
		strncpy(po->sCnt2,pi->sCnt2,strlen(pi->sCnt2));
		strncpy(po->sTollFee3,pi->sTollFee3,strlen(pi->sTollFee3));
		strncpy(po->sDuration3,pi->sDuration3,strlen(pi->sDuration3));
		strncpy(po->sCnt3,pi->sCnt3,strlen(pi->sCnt3));
		strncpy(po->sTollFee4,pi->sTollFee4,strlen(pi->sTollFee4));
		strncpy(po->sDuration4,pi->sDuration4,strlen(pi->sDuration4));
		strncpy(po->sCnt4,pi->sCnt4,strlen(pi->sCnt4));
		strncpy(po->sTollFee5,pi->sTollFee5,strlen(pi->sTollFee5));
		strncpy(po->sDuration5,pi->sDuration5,strlen(pi->sDuration5));
		strncpy(po->sCnt5,pi->sCnt5,strlen(pi->sCnt5));
		strncpy(po->sTollFee6,pi->sTollFee6,strlen(pi->sTollFee6));
		strncpy(po->sDuration6,pi->sDuration6,strlen(pi->sDuration6));
		strncpy(po->sCnt6,pi->sCnt6,strlen(pi->sCnt6));
		strncpy(po->sSettMonth,pi->sSettMonth,strlen(pi->sSettMonth));

}

int DownVoipStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct DownVoipStatStruct Temp;
	static struct DownVoipStatStructIn TempIn;
	
	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetDownVoipStatToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfdownvoipstat(&Temp,(struct FDownVoipStatStruct*)sTemp);
	sTemp[sizeof(struct FDownVoipStatStruct)]=0;
	strcpy(sSourceID,"DWVO19");
	/*strcpy(sRowID,	Temp.sRowID);*/
	return true;
}

void mvitem_mfdowntollstat(struct DownTollStatStruct *pi,struct FDownTollStatStruct *po)
{/*内存数据移动到文件记录到部分*/
/*	char sTemp[128];*/

	memset((void*)po,' ',sizeof(struct FDownTollStatStruct));

		strncpy(po->sCallingUserType,pi->sCallingUserType,strlen(pi->sCallingUserType));
		strncpy(po->sInCityCode,pi->sInCityCode,strlen(pi->sInCityCode));
		strncpy(po->sOutCityCout,pi->sOutCityCout,strlen(pi->sOutCityCout));
		strncpy(po->sTollFee1,pi->sTollFee1,strlen(pi->sTollFee1));
		strncpy(po->sDuration1,pi->sDuration1,strlen(pi->sDuration1));
		strncpy(po->sCnt1,pi->sCnt1,strlen(pi->sCnt1));
		strncpy(po->sTollFee2,pi->sTollFee2,strlen(pi->sTollFee2));
		strncpy(po->sDuration2,pi->sDuration2,strlen(pi->sDuration2));
		strncpy(po->sCnt2,pi->sCnt2,strlen(pi->sCnt2));
		strncpy(po->sTollFee3,pi->sTollFee3,strlen(pi->sTollFee3));
		strncpy(po->sDuration3,pi->sDuration3,strlen(pi->sDuration3));
		strncpy(po->sCnt3,pi->sCnt3,strlen(pi->sCnt3));
		strncpy(po->sSettMonth,pi->sSettMonth,strlen(pi->sSettMonth));

}
int DownTollStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct DownTollStatStruct Temp;
	static struct DownTollStatStructIn TempIn;
	
	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetDownTollStatToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfdowntollstat(&Temp,(struct FDownTollStatStruct*)sTemp);
	sTemp[sizeof(struct FDownTollStatStruct)]=0;
	strcpy(sSourceID,"");
	/*strcpy(sRowID,	Temp.sRowID);*/
	return true;
}

int XStrTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[])
{
	static int iFirstFlag=true;
	static struct XStrTicketStruct Temp;
	static struct XStrTicketStructIn TempIn;
	
	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	if(EGetXStrTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sSourceID,"");
		strcpy(sRowID,"");
		strcpy(sTemp,"");
		return false;
	}
	strcpy(sTemp,Temp.sXStr);
	strcpy(sSourceID,Temp.sSourceID);
	strcpy(sRowID,Temp.sRowID);

	return true;
}
/**对表MY_TAB_COLUMNS的链表释放函数**/
void DestroyMyTabColumns(struct MyTabColumnsStruct *ptHead)
{
	struct MyTabColumnsStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitMyTabColumns(char sTableName[],struct MyTabColumnsStruct **pptHead)
{
	int iCnt=0;
	static struct MyTabColumnsStruct *pTemp,*ptHead=NULL;
	struct MyTabColumnsStruct Temp;
	struct MyTabColumnsStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyMyTabColumns(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct MyTabColumnsStructIn));
		
	sprintf(TempIn.sTableName,"(\n\
		SELECT \n\
			nvl(TABLE_NAME,' ')	TABLE_NAME,\n\
			nvl(DATA_TYPE,' ') 	DATA_TYPE,\n\
			nvl(COLUMN_NAME,' ')	COLUMN_NAME,\n\
			nvl(LEN,0) 		LEN,\n\
			nvl(SCALE,0) 		SCALE,\n\
			nvl(NULLABLE,' ')	NULLABLE,\n\
			nvl(COLUMN_ID,0)	COLUMN_ID\n\
		FROM MY_TAB_COLUMNS \n\
		WHERE TABLE_NAME='%s' OR TABLE_NAME IN (\n\
			SELECT TEMPLATE_NAME FROM MY_TAB_TEMPLATE \n\
			WHERE TABLE_NAME='%s'\n\
		)\n\
		ORDER BY COLUMN_ID DESC)",sTableName,sTableName);

	/*如果配置表中没有配置则取USER_TAB_COLUMNS中的记录*/
	if(SDGetTabCnt(TempIn.sTableName)<=0){
		sprintf(TempIn.sTableName,"(\n\
			SELECT \n\
				nvl(TABLE_NAME,' ')	TABLE_NAME,\n\
				nvl(DATA_TYPE,' ') 	DATA_TYPE,\n\
				nvl(COLUMN_NAME,' ')	COLUMN_NAME,\n\
				decode(DATA_TYPE,'NUMBER',\n\
decode(nvl(DATA_SCALE,0),0,nvl(DATA_PRECISION,12),DATA_PRECISION+1),\n\
				'DATE',14,DATA_LENGTH) LEN,\n\
				nvl(DATA_SCALE,0) 	SCALE,\n\
				nvl(NULLABLE,' ')	NULLABLE,\n\
				nvl(COLUMN_ID,0)	COLUMN_ID\n\
			FROM USER_TAB_COLUMNS WHERE TABLE_NAME='%s'\n\
			ORDER BY COLUMN_ID DESC)",sTableName);
	}

	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetMyTabColumnsToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct MyTabColumnsStruct*)
			malloc(sizeof(struct MyTabColumnsStruct)))==NULL){

			DestroyMyTabColumns(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct MyTabColumnsStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表MY_TAB_COLUMNS记录数%d",iCnt);
	}

	WriteProcMsg("加载表MY_TAB_COLUMNS完毕总记录数%d",iCnt);

	return iCnt;
}

void GetSeleColumnStr(struct MyTabColumnsStruct *pTemp,char sOutput[])
{
	int i=0;
	char sNvlBgn[32],sNvlEnd[128],pin[128];
	
	strcpy(sOutput,"");
	
	strcpy(sNvlBgn,"");
	strcpy(sNvlEnd,"");

	if(strcmp(pTemp->sNullable,"Y")==0){
		strcpy(sNvlBgn,"nvl(");
		if(strcmp(pTemp->sDataType,"NUMBER")==0)/*整数默认为0*/
			strcpy(sNvlEnd,",0)");
		else if(strcmp(pTemp->sDataType,"DATE")==0){/*日期默认19900101*/
			if(strcmp(pTemp->sColumnName,"EFF_DATE")==0)
				strcpy(sNvlEnd,",to_date('19900101','yyyymmdd'))");
			else if(strcmp(pTemp->sColumnName,"EXP_DATE")==0)
				strcpy(sNvlEnd,",to_date('20300101','yyyymmdd'))");
			else	strcpy(sNvlEnd,",trunc(SYSDATE))");
		}
		else					/*字符串默认为空*/
			strcpy(sNvlEnd,",' ')");
	}
	if(strcmp(pTemp->sDataType,"NUMBER")==0){
		
		for(i=0;i<pTemp->iLen;i++)
			pin[i]='9';
		pin[i]=0;

		if(pTemp->iScale!=0)
			pin[i-pTemp->iScale-1]='.';

		/*NUMBER      直接取12位用9.2表示*/
		if(pTemp->iLen==0&&pTemp->iScale==0)
			strcpy(pin,"999999999.99");

		/*左补0*/
		pin[0]='0';

		sprintf(sOutput,"ltrim(to_char(%s%s%s,'%s'))",
			sNvlBgn,pTemp->sColumnName,sNvlEnd,pin);
			
	}
	else if(strcmp(pTemp->sDataType,"DATE")==0){
		sprintf(sOutput,"to_char(%s%s%s,'yyyymmddhh24miss')",
			sNvlBgn,pTemp->sColumnName,sNvlEnd);
	}
	else if(strcmp(pTemp->sDataType,"VARCHAR2")==0||
		strcmp(pTemp->sDataType,"VARCHAR")==0||
		strcmp(pTemp->sDataType,"CHAR")==0){

		sprintf(sOutput,"rpad(%s%s%s,%d,' ')",
			sNvlBgn,pTemp->sColumnName,sNvlEnd,pTemp->iLen);
		/*对一个字符的情况的特殊处理*/
		if(pTemp->iLen==1)sprintf(sOutput,"%s%s%s",
			sNvlBgn,pTemp->sColumnName,sNvlEnd);
			
	}
}
int ExistColumn(struct MyTabColumnsStruct *ptHead,char sColumnName[])
{
	while(ptHead!=NULL){
		if(strcmp(sColumnName,ptHead->sColumnName)==0) return true;
		ptHead=ptHead->pNext;
	}
	return false;

}
void GetXStrSqlStmt(struct MyTabColumnsStruct *ptHead,char sTableName[],
	char statement[])
{
	int l=0;
	char  sTemp[128],sSourceField[128];
	struct MyTabColumnsStruct *pTemp;
	
	if(ExistColumn(ptHead,"SOURCE_ID"))
		strcpy(sSourceField,"SOURCE_ID");
	else	strcpy(sSourceField,"' ' SOURCE_ID");
	
	l+=sprintf(statement,"\nSELECT \n");
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		GetSeleColumnStr(pTemp,sTemp);
		
		if(strlen(sTemp)==0) continue;

		if(ptHead!=NULL)
			l+=sprintf(statement+l,"\t%s||\n",sTemp);
		else
			l+=sprintf(statement+l,
			"\t%s X_STR,\n\t%s,\n\trowidtochar(ROWID) ROW_ID \n",
				sTemp,sSourceField);
	}
	l+=sprintf(statement+l,"FROM %s \n",sTableName);
}
int UCommColumnExist(struct MyTabColumnsStruct *ptHead)
{
	if(!ExistColumn(ptHead,"FILE_NAME")) return false;
	if(!ExistColumn(ptHead,"MODULE")) return false;
	if(!ExistColumn(ptHead,"AREA_CODE")) return false;
	if(!ExistColumn(ptHead,"STATE")) return false;
	if(!ExistColumn(ptHead,"UPDATE_DATE")) return false;
	return true;
}
void GetXStrTableNameStmt(struct MyTabColumnsStruct *ptLkHead,
	char sTableName[],char sCondition[],char statement[])
{
	char sTemp[256];
	
	strcpy(statement,"(");
	
	GetXStrSqlStmt(ptLkHead,sTableName,statement+1);
	
	sprintf(sTemp,"%s \n)",sCondition);
	strcat(statement,sTemp);
}
int GetXStrTableName(char sTableName[],char sCondition[],char statement[])
{
	int iRet;
	struct MyTabColumnsStruct *ptLkHead=NULL;

	if(InitMyTabColumns(sTableName,&ptLkHead)<0)
		return -1;
	
	GetXStrTableNameStmt(ptLkHead,sTableName,sCondition,statement);
	
	iRet=UCommColumnExist(ptLkHead);
	
	DestroyList((LIST*)ptLkHead);
	
	return iRet;
	
}

int InitMyTabIoColumns(char sTableName[],struct MyTabColumnsStruct **pptHead)
{
	int iCnt=0;
	static struct MyTabColumnsStruct *pTemp,*ptHead=NULL;
	struct MyTabColumnsStruct Temp;
	struct MyTabColumnsStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyMyTabColumns(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct MyTabColumnsStructIn));
	
	sprintf(TempIn.sTableName,"(\n\
		SELECT \n\
			nvl(TABLE_NAME,' ')	TABLE_NAME,\n\
			nvl(DATA_TYPE,' ') 	DATA_TYPE,\n\
			nvl(COLUMN_NAME,' ')	COLUMN_NAME,\n\
			nvl(LEN,0) 		LEN,\n\
			nvl(SCALE,0) 		SCALE,\n\
			nvl(NULLABLE,' ')	NULLABLE,\n\
			nvl(COLUMN_ID,0)	COLUMN_ID\n\
		FROM MY_TAB_IO_COLUMNS \n\
		WHERE TABLE_NAME='%s' OR TABLE_NAME IN (\n\
			SELECT TEMPLATE_NAME FROM MY_TAB_TEMPLATE \n\
			WHERE TABLE_NAME='%s'\n\
		)\n\
		ORDER BY COLUMN_ID DESC)",sTableName,sTableName);
	
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetMyTabColumnsToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct MyTabColumnsStruct*)
			malloc(sizeof(struct MyTabColumnsStruct)))==NULL){

			DestroyMyTabColumns(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct MyTabColumnsStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表MY_TAB_IO_COLUMNS记录数%d",iCnt);
	}

	WriteProcMsg("加载表MY_TAB_IO_COLUMNS完毕总记录数%d",iCnt);

	return iCnt;
}
int my_tab_columns_comp_list(LIST *pValue,LIST *pHead)
{
	struct MyTabColumnsStruct *pSource=(struct MyTabColumnsStruct *)pValue;
	struct MyTabColumnsStruct *pTarget=(struct MyTabColumnsStruct *)pHead;
	
	return pSource->iColumnID-pTarget->iColumnID;
}
/*得到从小到大的按column_id排列的两个列表*/
void GetIoMyTabColumnList(struct MyTabColumnsStruct **pptHead,
	struct MyTabColumnsStruct **ppInList,
	struct MyTabColumnsStruct **ppOutList)
{
	struct MyTabColumnsStruct *ptHead=*pptHead,*pTemp;
	
	*ppInList=*ppOutList=*pptHead=NULL;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->sNullable,"N")==0)
			pptHead=ppInList;
		else	pptHead=ppOutList;

		InsertListSort((LIST**)pptHead,(LIST*)pTemp,
			my_tab_columns_comp_list);
	}
}
void SetMyTabColumnOffset(struct MyTabColumnsStruct *ptHead)
{
	int i=0,k=1;
	
	struct MyTabColumnsStruct *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		pTemp->iOffset=i;
		pTemp->iSeq=k;
		k++;
		i+=pTemp->iLen;
	}
}
int SearchMyTabColumnByName(struct MyTabColumnsStruct *ptHead,char sColumnName[],
	struct MyTabColumnsStruct **pptCur)
{
	*pptCur=NULL;

	while(ptHead!=NULL){
		if(strcmp(sColumnName,ptHead->sColumnName)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void LinkMyTabColumnHead(struct MyTabColumnsStruct *ptHead,
	struct MyTabColumnsStruct *ptLkHead)
{
	struct MyTabColumnsStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		SearchMyTabColumnByName(ptLkHead,pTemp->sColumnName,
			&(pTemp->pHead));
	}
}
void GetMyTabStr(struct MyTabColumnsStruct *ptHead,char sLine[],char sOutput[])
{
	int l=0;
	char sTemp[256];
	struct MyTabColumnsStruct *pTemp,*pHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		pHead=pTemp->pHead;
		
		strncpy(sTemp,sLine+pHead->iOffset,pHead->iLen);
		sTemp[pHead->iLen]=0;

		/*如果特定的字段较短则直接截掉*/
		if(pTemp->iLen<pHead->iLen) sTemp[pTemp->iLen]=0;

		if(pTemp->iLen>pHead->iLen){
			if(strcmp(pTemp->sDataType,"NUMBER")==0)
				LeftPad(sTemp,pTemp->iLen,'0');
			else	RightPad(sTemp,pTemp->iLen,' ');
		}

		l+=sprintf(sOutput+l,"%s",sTemp);
	}
}
static void TransC(char sColumnName[])
{
	int i;
	char sName[128];
	
	strcpy(sName,sColumnName);
	
	Lower(sName);
	
	for(i=0;i<strlen(sName);i++){
		
		if(i==0){
			if(sName[i]>='a'&&sName[i]<='z')
				sName[i]=sName[i]+'A'-'a';
		}
		if(sName[i]=='_'){
			if(sName[i+1]>='a'&&sName[i+1]<='z')
				sName[i+1]=sName[i+1]+'A'-'a';
		}
	}

	ReplaceStr(sName,"_Id_","_ID_");
	if(RLike(sName,"_Id"))
		strcpy(sName+strlen(sName)-3,"_ID");
	
	ReplaceStr(sName,"_","");
	
	strcpy(sColumnName,sName);
}
void GetUpdColumnStr(struct MyTabColumnsStruct *pTemp,char sOutput[])
{
	char sName[128],sNewName[128];

/*	这里全部用as
	if(strcmp(pTemp->sDataType,"NUMBER")==0)
		strcpy(sName,"ai");
	else	strcpy(sName,"as");
*/
	strcpy(sName,"as");

	strcpy(sNewName,pTemp->sColumnName);
	TransC(sNewName);
	
	strcat(sName,sNewName);

	strcpy(sOutput,"");
	
	if(strcmp(pTemp->sDataType,"NUMBER")==0)
		sprintf(sOutput,"to_number(:%s)",sName);
	else if(strcmp(pTemp->sDataType,"DATE")==0)
		sprintf(sOutput,"to_date(:%s,'yyyymmddhh24miss')",sName);
	else if(strcmp(pTemp->sDataType,"VARCHAR2")==0||
		strcmp(pTemp->sDataType,"VARCHAR")==0||
		strcmp(pTemp->sDataType,"CHAR")==0)
		sprintf(sOutput,":%s",sName);
	else
		sprintf(sOutput,":%s",sName);
}
void GetUpdSqlStmt(struct MyTabColumnsStruct *ptHead,char sTableName[],
	char statement[])
{
	int l=0;
	char  sTemp[128];
	struct MyTabColumnsStruct *pTemp;
	
	l+=sprintf(statement,"\nUPDATE %s \nSET \n",sTableName);
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		GetUpdColumnStr(pTemp,sTemp);

		if(ptHead!=NULL)
			l+=sprintf(statement+l,"\t%s=%s,\n",pTemp->sColumnName,sTemp);
		else
			l+=sprintf(statement+l,"\t%s=%s \n",pTemp->sColumnName,sTemp);
	}

	sprintf(statement+l,"WHERE ROWID = chartorowid(:asRowID)\n");
}

struct UStrStructUp *MallocUStrStructUp(struct MyTabColumnsStruct *ptHead)
{
	int b=-1;/*扣掉原来一个字节*/
	
	struct UStrStructUp *pTarget;
	
	while(ptHead!=NULL){
		b+=(ptHead->iLen+1)*XSTR_BUFLEN_UP;
		ptHead=ptHead->pNext;
	}
	if((pTarget=(struct UStrStructUp*)
		malloc(sizeof(struct UStrStructUp)+b))==NULL) return NULL;
		
	bzero((void*)pTarget,sizeof(struct UStrStructUp)+b);

	return pTarget;
}
