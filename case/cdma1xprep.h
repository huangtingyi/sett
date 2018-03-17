#ifndef __CDMA1XPREP_H__
#define __CDMA1XPREP_H__

/*单个结构申明*/
struct Cdma1xPrepStruct{

	struct Cdma1xPrepStruct *pNext;
	char    sSequencenum[11];
	char    sAccountingStatusType[5];
	char    sMsid[16];
	char    sIp[16];
	char    sNai[65];
	char    sAccountSessionID[9];
	char    sCorrelationID[9];
	char    sSessionContinue[5];
	char    sMipHomeAgent[16];
	char    sPdsn[16];
	char    sServingPcf[16];
	char    sBsid[13];
	char    sUserZone[11];
	char    sForwardTarfficType[5];
	char    sReverseMuxOption[5];
	char    sServiceOption[5];
	char    sForwardTrafficType[5];
	char    sReverseTrafficType[5];
	char    sFundamentaFrameSice[5];
	char    sForwardFundamenta[5];
	char    sReverseFundamenta[5];
	char    sIpTechnology[5];
	char    sCompulsoryTunnel[5];
	char    sReleaseIndicator[5];
	char    sDcch[5];
	char    sDataOctetCountUp[11];
	char    sDataOctetCountDown[11];
	char    sBadPpp[11];
	char    sEventTime[11];
	char    sActiveTime[11];
	char    sNumberActive[11];
	char    sSdbOctetCountDonw[11];
	char    sSdbOctetCountUp[11];
	char    sNumberSdbsDown[11];
	char    sNumberSdbsUp[11];
	char    sNumberHdlc[11];
	char    sBoundMobile[11];
	char    sOutBoundMobile[11];
	char    sIpQualityService[11];
	char    sAirlikeQuality[11];
	char    sAirlikeRecoredType[11];
	char    sRpSessionID[11];
	char    sAirlikeSequenceNumber[11];
	char    sMobileTerminated[11];
	char    sMdn[21];
	char    sUserType[11];
	char    sNaiBureald[11];
	char    sRoamingID[11];
	char    sEsn[20];
	struct Cdma1xPrepStruct *pLoadNext;
};

#endif

