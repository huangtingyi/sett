#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <detail_intf.h>

void mvitem_mfaccsttticket(struct AccSttTicketStruct *pi,struct FAccSttTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FAccSttTicketStruct));

		strncpy(po->sUsageSeq,pi->sUsageSeq,strlen(pi->sUsageSeq));
		strncpy(po->sCityID,pi->sCityID,strlen(pi->sCityID));
		strncpy(po->sCdrType,pi->sCdrType,strlen(pi->sCdrType));
		strncpy(po->sCallingCityID,pi->sCallingCityID,strlen(pi->sCallingCityID));
		strncpy(po->sCallingException,pi->sCallingException,strlen(pi->sCallingException));
		strncpy(po->sCallingType,pi->sCallingType,strlen(pi->sCallingType));
		strncpy(po->sCallingCompCode,pi->sCallingCompCode,strlen(pi->sCallingCompCode));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCalledCityID,pi->sCalledCityID,strlen(pi->sCalledCityID));
		strncpy(po->sCalledException,pi->sCalledException,strlen(pi->sCalledException));
		strncpy(po->sCalledNumberType,pi->sCalledNumberType,strlen(pi->sCalledNumberType));
		strncpy(po->sCalledCompCode,pi->sCalledCompCode,strlen(pi->sCalledCompCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sInTrunkNumber,pi->sInTrunkNumber,strlen(pi->sInTrunkNumber));
		strncpy(po->sInCompanyCode,pi->sInCompanyCode,strlen(pi->sInCompanyCode));
		strncpy(po->sInTrunkNetType,pi->sInTrunkNetType,strlen(pi->sInTrunkNetType));
		strncpy(po->sOutTrunkNumber,pi->sOutTrunkNumber,strlen(pi->sOutTrunkNumber));
		strncpy(po->sOutCompanyCode,pi->sOutCompanyCode,strlen(pi->sOutCompanyCode));
		strncpy(po->sOutTrunkNetType,pi->sOutTrunkNetType,strlen(pi->sOutTrunkNetType));
		strncpy(po->sIsFree,pi->sIsFree,strlen(pi->sIsFree));
		strncpy(po->sCallingLocation,pi->sCallingLocation,strlen(pi->sCallingLocation));
		strncpy(po->sSecondCallingLocation,pi->sSecondCallingLocation,strlen(pi->sSecondCallingLocation));
		strncpy(po->sOrigCallingNumber,pi->sOrigCallingNumber,strlen(pi->sOrigCallingNumber));
		strncpy(po->sOrigCalledNumber,pi->sOrigCalledNumber,strlen(pi->sOrigCalledNumber));
		strncpy(po->sOrigSecondCallingNumber,pi->sOrigSecondCallingNumber,strlen(pi->sOrigSecondCallingNumber));
		strncpy(po->sExceptionType,pi->sExceptionType,strlen(pi->sExceptionType));
		strncpy(po->sPreCallType,pi->sPreCallType,strlen(pi->sPreCallType));
		strncpy(po->sTurnType,pi->sTurnType,strlen(pi->sTurnType));
		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sRateUnitType,pi->sRateUnitType,strlen(pi->sRateUnitType));
		strncpy(po->sStlDuration,pi->sStlDuration,strlen(pi->sStlDuration));
		strncpy(po->sRateID,pi->sRateID,strlen(pi->sRateID));
		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));
		strncpy(po->sGroupID,pi->sGroupID,strlen(pi->sGroupID));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));

}

int AccSttTicket2Str(char sTableName[], char sTemp[], char sPrepTime[])
{
	static int iFirstFlag=true;
	static struct AccSttTicketStruct Temp;
	static struct AccSttTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName, sTableName);
		sprintf(TempIn.sCondition,"partition(PART%s)",sPrepTime);
		iFirstFlag=false;
	}
	if(EGetAccSttTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfaccsttticket(&Temp,(struct FAccSttTicketStruct*)sTemp);
	sTemp[sizeof(struct FAccSttTicketStruct)]=0;

	return true;
}

void mvitem_mfaccsmsticket(struct AccSmsTicketStruct *pi,struct FAccSmsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FAccSmsTicketStruct));

		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCallingCityID,pi->sCallingCityID,strlen(pi->sCallingCityID));
		strncpy(po->sCallingCompanyID,pi->sCallingCompanyID,strlen(pi->sCallingCompanyID));
		strncpy(po->sCallingNumberType,pi->sCallingNumberType,strlen(pi->sCallingNumberType));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sCalledCityID,pi->sCalledCityID,strlen(pi->sCalledCityID));
		strncpy(po->sCalledCompanyID,pi->sCalledCompanyID,strlen(pi->sCalledCompanyID));
		strncpy(po->sCalledNumberType,pi->sCalledNumberType,strlen(pi->sCalledNumberType));

		sprintf(sTemp,"%8d",pi->iCityID);
		strncpy(po->sCityID,sTemp,8);

		strncpy(po->sIsFree,pi->sIsFree,strlen(pi->sIsFree));

		sprintf(sTemp,"%6d",pi->iBillCycleSeq);
		strncpy(po->sBillCycleSeq,sTemp,6);

		strncpy(po->sExceptionType,pi->sExceptionType,strlen(pi->sExceptionType));
		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sStlDirection,pi->sStlDirection,strlen(pi->sStlDirection));
		strncpy(po->sUpGw,pi->sUpGw,strlen(pi->sUpGw));
		strncpy(po->sDownGw,pi->sDownGw,strlen(pi->sDownGw));
		strncpy(po->sUpCompanyID,pi->sUpCompanyID,strlen(pi->sUpCompanyID));
		strncpy(po->sDownCompanyID,pi->sDownCompanyID,strlen(pi->sDownCompanyID));
		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sGroupID,pi->sGroupID,strlen(pi->sGroupID));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));

}

int AccSmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[])
{
	static int iFirstFlag=true;
	static struct AccSmsTicketStruct Temp;
	static struct AccSmsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName, sTableName);
		sprintf(TempIn.sCondition,"partition(PART%s)",sPrepTime);
		iFirstFlag=false;
	}
	if(EGetAccSmsTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfaccsmsticket(&Temp,(struct FAccSmsTicketStruct*)sTemp);
	sTemp[sizeof(struct FAccSmsTicketStruct)]=0;
	
	return true;
}

void mvitem_mfaccmmsticket(struct AccMmsTicketStruct *pi,struct FAccMmsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FAccMmsTicketStruct));

		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sOperationTypeID,pi->sOperationTypeID,strlen(pi->sOperationTypeID));

		sprintf(sTemp,"%8d",pi->iCityID);
		strncpy(po->sCityID,sTemp,8);

		strncpy(po->sIsFree,pi->sIsFree,strlen(pi->sIsFree));
		strncpy(po->sRateUnitType,pi->sRateUnitType,strlen(pi->sRateUnitType));
		strncpy(po->sRateUnits,pi->sRateUnits,strlen(pi->sRateUnits));

		sprintf(sTemp,"%6d",pi->iBillCycleSeq);
		strncpy(po->sBillCycleSeq,sTemp,6);

		strncpy(po->sExceptionType,pi->sExceptionType,strlen(pi->sExceptionType));
		strncpy(po->sProvinceID,pi->sProvinceID,strlen(pi->sProvinceID));
		strncpy(po->sCallingGroupID,pi->sCallingGroupID,strlen(pi->sCallingGroupID));
		strncpy(po->sCalledGroupID,pi->sCalledGroupID,strlen(pi->sCalledGroupID));
		strncpy(po->sCallingCompanyID,pi->sCallingCompanyID,strlen(pi->sCallingCompanyID));
		strncpy(po->sCalledCompanyID,pi->sCalledCompanyID,strlen(pi->sCalledCompanyID));
		strncpy(po->sStlObject,pi->sStlObject,strlen(pi->sStlObject));
		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sStlDirection,pi->sStlDirection,strlen(pi->sStlDirection));
		strncpy(po->sUpGw,pi->sUpGw,strlen(pi->sUpGw));
		strncpy(po->sDownGw,pi->sDownGw,strlen(pi->sDownGw));
		strncpy(po->sUpgwGroupID,pi->sUpgwGroupID,strlen(pi->sUpgwGroupID));
		strncpy(po->sDownGwGroupID,pi->sDownGwGroupID,strlen(pi->sDownGwGroupID));
		strncpy(po->sUpCompanyID,pi->sUpCompanyID,strlen(pi->sUpCompanyID));
		strncpy(po->sDownCompanyID,pi->sDownCompanyID,strlen(pi->sDownCompanyID));
		strncpy(po->sUsageSeq,pi->sUsageSeq,strlen(pi->sUsageSeq));
		strncpy(po->sCallingCityCode,pi->sCallingCityCode,strlen(pi->sCallingCityCode));
		strncpy(po->sCalledCityCode,pi->sCalledCityCode,strlen(pi->sCalledCityCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sGroupID,pi->sGroupID,strlen(pi->sGroupID));
		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));

}

int AccMmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[])
{
	static int iFirstFlag=true;
	static struct AccMmsTicketStruct Temp;
	static struct AccMmsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName, sTableName);
		sprintf(TempIn.sCondition,"partition(PART%s)",sPrepTime);
		iFirstFlag=false;
	}
	if(EGetAccMmsTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfaccmmsticket(&Temp,(struct FAccMmsTicketStruct*)sTemp);
	sTemp[sizeof(struct FAccMmsTicketStruct)]=0;
	
	return true;
}

void mvitem_mfodssttticket(struct OdsSttTicketStruct *pi,struct FOdsSttTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FOdsSttTicketStruct));

		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));
		strncpy(po->sVisitAreaCode,pi->sVisitAreaCode,strlen(pi->sVisitAreaCode));

		sprintf(sTemp,"%2d",pi->iCallType);
		strncpy(po->sCallType,sTemp,2);

		strncpy(po->sServiceNum1,pi->sServiceNum1,strlen(pi->sServiceNum1));
		strncpy(po->sServiceNumr,pi->sServiceNumr,strlen(pi->sServiceNumr));

		sprintf(sTemp,"%9d",pi->iSubscriptionID);
		strncpy(po->sSubscriptionID,sTemp,9);

		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sOppAreaCode,pi->sOppAreaCode,strlen(pi->sOppAreaCode));

		sprintf(sTemp,"%2d",pi->iOppNetType);
		strncpy(po->sOppNetType,sTemp,2);
		sprintf(sTemp,"%4d",pi->iOppNumType);
		strncpy(po->sOppNumType,sTemp,4);

		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));

		sprintf(sTemp,"%9d",pi->iCallDuration);
		strncpy(po->sCallDuration,sTemp,9);
		strncpy(po->sThirdParty,pi->sThirdParty,strlen(pi->sThirdParty));
		strncpy(po->sDataFileDay,pi->sDataFileDay,strlen(pi->sDataFileDay));
		strncpy(po->sTrunkGroupout,pi->sTrunkGroupout,strlen(pi->sTrunkGroupout));
		strncpy(po->sOriginalFile,pi->sOriginalFile,strlen(pi->sOriginalFile));

}

int OdsSttTicket2Str(char sTableName[], char sTemp[], char sPrepTime[])
{
	static int iFirstFlag=true;
	static struct OdsSttTicketStruct Temp;
	static struct OdsSttTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName, sTableName);
		sprintf(TempIn.sCondition,"partition(PART%s)",sPrepTime);
		iFirstFlag=false;
	}
	if(EGetOdsSttTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfodssttticket(&Temp,(struct FOdsSttTicketStruct*)sTemp);
	sTemp[sizeof(struct FOdsSttTicketStruct)]=0;
	
	return true;
}

void mvitem_mfodssmsticket(struct OdsSmsTicketStruct *pi,struct FOdsSmsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FOdsSmsTicketStruct));

		sprintf(sTemp,"%02d",pi->iServiceID);
		strncpy(po->sServiceID,sTemp,2);

		strncpy(po->sBillNumber,pi->sBillNumber,strlen(pi->sBillNumber));

		sprintf(sTemp,"%02d",pi->iCallType);
		strncpy(po->sCallType,sTemp,2);

		strncpy(po->sHomeArea,pi->sHomeArea,strlen(pi->sHomeArea));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sOppNumber,pi->sOppNumber,strlen(pi->sOppNumber));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpSmg,pi->sSpSmg,strlen(pi->sSpSmg));
		strncpy(po->sAccessCode,pi->sAccessCode,strlen(pi->sAccessCode));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sLangType,pi->sLangType,strlen(pi->sLangType));

		sprintf(sTemp,"%04d",pi->iSvType);
		strncpy(po->sSvType,sTemp,4);

		strncpy(po->sSvcEx,pi->sSvcEx,strlen(pi->sSvcEx));
		strncpy(po->sSmType,pi->sSmType,strlen(pi->sSmType));

		sprintf(sTemp,"%04d",pi->iMsgLength);
		strncpy(po->sMsgLength,sTemp,4);
		sprintf(sTemp,"%01d",pi->iEndReason);
		strncpy(po->sEndReason,sTemp,1);
		sprintf(sTemp,"%03d",pi->iNice);
		strncpy(po->sNice,sTemp,3);

		strncpy(po->sSmgCode,pi->sSmgCode,strlen(pi->sSmgCode));

		sprintf(sTemp,"%01d",pi->iUserType);
		strncpy(po->sUserType,sTemp,1);
		sprintf(sTemp,"%09d",pi->iCfee1);
		strncpy(po->sCfee1,sTemp,9);
		sprintf(sTemp,"%09d",pi->iAfee1);
		strncpy(po->sAfee1,sTemp,9);

		strncpy(po->sServiceNumr,pi->sServiceNumr,strlen(pi->sServiceNumr));

		sprintf(sTemp,"%02d",pi->iPartID);
		strncpy(po->sPartID,sTemp,2);
		sprintf(sTemp,"%09d",pi->iAccountID);
		strncpy(po->sAccountID,sTemp,9);
		sprintf(sTemp,"%09d",pi->iSubscriptionID);
		strncpy(po->sSubscriptionID,sTemp,9);
		sprintf(sTemp,"%04d",pi->iSvcType);
		strncpy(po->sSvcType,sTemp,4);

		strncpy(po->sRegionID,pi->sRegionID,strlen(pi->sRegionID));

		sprintf(sTemp,"%06d",pi->iUsageType);
		strncpy(po->sUsageType,sTemp,6);
		sprintf(sTemp,"%06d",pi->iUsageCase);
		strncpy(po->sUsageCase,sTemp,6);
		sprintf(sTemp,"%06d",pi->iUsageClass);
		strncpy(po->sUsageClass,sTemp,6);
		sprintf(sTemp,"%06d",pi->iClassOfServiceCode);
		strncpy(po->sClassOfServiceCode,sTemp,6);
		sprintf(sTemp,"%09d",pi->iCfee);
		strncpy(po->sCfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iLfee);
		strncpy(po->sLfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iIfee);
		strncpy(po->sIfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDisCfee);
		strncpy(po->sDisCfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDisLfee);
		strncpy(po->sDisLfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDisIfee);
		strncpy(po->sDisIfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iCfeeTimes);
		strncpy(po->sCfeeTimes,sTemp,9);
		sprintf(sTemp,"%09d",pi->iLfeeTimes);
		strncpy(po->sLfeeTimes,sTemp,9);
		sprintf(sTemp,"%09d",pi->iIfeeTimes);
		strncpy(po->sIfeeTimes,sTemp,9);
		sprintf(sTemp,"%09d",pi->iPackageID);
		strncpy(po->sPackageID,sTemp,9);
		sprintf(sTemp,"%04d",pi->iProductClass);
		strncpy(po->sProductClass,sTemp,4);

		strncpy(po->sOriginalFile,pi->sOriginalFile,strlen(pi->sOriginalFile));

		sprintf(sTemp,"%03d",pi->iLateLink);
		strncpy(po->sLateLink,sTemp,3);

		strncpy(po->sCalTime,pi->sCalTime,strlen(pi->sCalTime));
		strncpy(po->sAudiStr,pi->sAudiStr,strlen(pi->sAudiStr));
		strncpy(po->sVarianStr,pi->sVarianStr,strlen(pi->sVarianStr));
		strncpy(po->sTimestamp,pi->sTimestamp,strlen(pi->sTimestamp));
		strncpy(po->sDatafileDay,pi->sDatafileDay,strlen(pi->sDatafileDay));
		strncpy(po->sInstorageDay,pi->sInstorageDay,strlen(pi->sInstorageDay));

}

int OdsSmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[])
{
	static int iFirstFlag=true;
	static struct OdsSmsTicketStruct Temp;
	static struct OdsSmsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName, sTableName);
		sprintf(TempIn.sCondition,"partition(PART%s)",sPrepTime);
		iFirstFlag=false;
	}
	if(EGetOdsSmsTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfodssmsticket(&Temp,(struct FOdsSmsTicketStruct*)sTemp);
	sTemp[sizeof(struct FOdsSmsTicketStruct)]=0;
	
	return true;
}

void mvitem_mfodsmmsticket(struct OdsMmsTicketStruct *pi,struct FOdsMmsTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FOdsMmsTicketStruct));

		sprintf(sTemp,"%02d",pi->iServiceID);
		strncpy(po->sServiceID,sTemp,2);

		strncpy(po->sBillNumber,pi->sBillNumber,strlen(pi->sBillNumber));

		sprintf(sTemp,"%02d",pi->iCallType);
		strncpy(po->sCallType,sTemp,2);

		strncpy(po->sHomeArea,pi->sHomeArea,strlen(pi->sHomeArea));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sOppNumber,pi->sOppNumber,strlen(pi->sOppNumber));
		strncpy(po->sSpCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sSpSmg,pi->sSpSmg,strlen(pi->sSpSmg));
		strncpy(po->sAccessCode,pi->sAccessCode,strlen(pi->sAccessCode));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sLangType,pi->sLangType,strlen(pi->sLangType));

		sprintf(sTemp,"%04d",pi->iSvType);
		strncpy(po->sSvType,sTemp,4);

		strncpy(po->sSvcEx,pi->sSvcEx,strlen(pi->sSvcEx));
		strncpy(po->sSmType,pi->sSmType,strlen(pi->sSmType));
		strncpy(po->sMsgLength,pi->sMsgLength,strlen(pi->sMsgLength));

		sprintf(sTemp,"%01d",pi->iEndReason);
		strncpy(po->sEndReason,sTemp,1);
		sprintf(sTemp,"%03d",pi->iNice);
		strncpy(po->sNice,sTemp,3);

		strncpy(po->sSmgCode,pi->sSmgCode,strlen(pi->sSmgCode));

		sprintf(sTemp,"%01d",pi->iUserType);
		strncpy(po->sUserType,sTemp,1);
		sprintf(sTemp,"%09d",pi->iCfee1);
		strncpy(po->sCfee1,sTemp,9);
		sprintf(sTemp,"%09d",pi->iAfee1);
		strncpy(po->sAfee1,sTemp,9);

		strncpy(po->sServiceNumr,pi->sServiceNumr,strlen(pi->sServiceNumr));

		sprintf(sTemp,"%02d",pi->iPartID);
		strncpy(po->sPartID,sTemp,2);
		sprintf(sTemp,"%09d",pi->iAccountID);
		strncpy(po->sAccountID,sTemp,9);
		sprintf(sTemp,"%09d",pi->iSubscriptionID);
		strncpy(po->sSubscriptionID,sTemp,9);
		sprintf(sTemp,"%04d",pi->iSvcType);
		strncpy(po->sSvcType,sTemp,4);

		strncpy(po->sRegionID,pi->sRegionID,strlen(pi->sRegionID));

		sprintf(sTemp,"%06d",pi->iUsageType);
		strncpy(po->sUsageType,sTemp,6);
		sprintf(sTemp,"%06d",pi->iUsageCase);
		strncpy(po->sUsageCase,sTemp,6);
		sprintf(sTemp,"%06d",pi->iUsageClass);
		strncpy(po->sUsageClass,sTemp,6);
		sprintf(sTemp,"%06d",pi->iClassOfServiceCode);
		strncpy(po->sClassOfServiceCode,sTemp,6);
		sprintf(sTemp,"%09d",pi->iCfee);
		strncpy(po->sCfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iLfee);
		strncpy(po->sLfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iIfee);
		strncpy(po->sIfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDisCfee);
		strncpy(po->sDisCfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDisLfee);
		strncpy(po->sDisLfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDisIfee);
		strncpy(po->sDisIfee,sTemp,9);
		sprintf(sTemp,"%09d",pi->iCfeeTimes);
		strncpy(po->sCfeeTimes,sTemp,9);
		sprintf(sTemp,"%09d",pi->iLfeeTimes);
		strncpy(po->sLfeeTimes,sTemp,9);
		sprintf(sTemp,"%09d",pi->iIfeeTimes);
		strncpy(po->sIfeeTimes,sTemp,9);
		sprintf(sTemp,"%09d",pi->iPackageID);
		strncpy(po->sPackageID,sTemp,9);
		sprintf(sTemp,"%09d",pi->iProductClass);
		strncpy(po->sProductClass,sTemp,9);

		strncpy(po->sOriginalFile,pi->sOriginalFile,strlen(pi->sOriginalFile));

		sprintf(sTemp,"%03d",pi->iLateLink);
		strncpy(po->sLateLink,sTemp,3);

		strncpy(po->sCalTime,pi->sCalTime,strlen(pi->sCalTime));
		strncpy(po->sAudiStr,pi->sAudiStr,strlen(pi->sAudiStr));
		strncpy(po->sVarianStr,pi->sVarianStr,strlen(pi->sVarianStr));
		strncpy(po->sDatafileDay,pi->sDatafileDay,strlen(pi->sDatafileDay));
		strncpy(po->sInstorageDay,pi->sInstorageDay,strlen(pi->sInstorageDay));
		strncpy(po->sUsageSeq,pi->sUsageSeq,strlen(pi->sUsageSeq));

}

int OdsMmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[])
{
	static int iFirstFlag=true;
	static struct OdsMmsTicketStruct Temp;
	static struct OdsMmsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName, sTableName);
		sprintf(TempIn.sCondition,"partition(PART%s)",sPrepTime);
		iFirstFlag=false;
	}
	if(EGetOdsMmsTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mfodsmmsticket(&Temp,(struct FOdsMmsTicketStruct*)sTemp);
	sTemp[sizeof(struct FOdsMmsTicketStruct)]=0;
	
	return true;
}

int SearchStAreaMscTimeOffsetItem(char sAreaCode[],struct StAreaMscTimeOffsetStruct **pptCur)
{
	static struct StAreaMscTimeOffsetStruct *ptHead=NULL;
	static int iFirstFlag=true;
	
	struct StAreaMscTimeOffsetStruct *pTemp,*ptLkHead;
	
	if(iFirstFlag==true){
		if(InitStAreaMscTimeOffset(&ptHead)<0) return -1;
		iFirstFlag=false;
	}
	
	ptLkHead=ptHead;
	*pptCur=NULL;
	while(ptLkHead!=NULL){
		
		pTemp=ptLkHead;
		ptLkHead=ptLkHead->pNext;
		
		if(strcmp(pTemp->sAreaCode,sAreaCode)==0){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	return NOTFOUND;
}

void mvitem_mflocsttticket(struct LocSttTicketStruct *pi,struct FLocSttTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FLocSttTicketStruct));

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
		sprintf(sTemp,"%04d",pi->iASettAreaID);
		strncpy(po->sASettAreaID,sTemp,4);
		sprintf(sTemp,"%04d",pi->iBSettAreaID);
		strncpy(po->sBSettAreaID,sTemp,4);

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
		strncpy(po->sState,pi->sState,strlen(pi->sState));
		strncpy(po->sUpdateDate,pi->sUpdateDate,strlen(pi->sUpdateDate));
		strncpy(po->sDealDate,pi->sDealDate,strlen(pi->sDealDate));
		strncpy(po->sSourceID,pi->sSourceID,strlen(pi->sSourceID));

}
int LocSttTicket2Str(char sTableName[], char sTemp[], char sPrepTime[])
{
	static int iFirstFlag=true;
	static struct LocSttTicketStruct Temp;
	static struct LocSttTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName, sTableName);
		sprintf(TempIn.sCondition,"partition(PART%s)",sPrepTime);
		iFirstFlag=false;
	}
	if(EGetLocSttTicketToStruct(&Temp,&TempIn)==false){
		strcpy(sTemp,"");
		return false;
	}
	mvitem_mflocsttticket(&Temp,(struct FLocSttTicketStruct*)sTemp);
	sTemp[sizeof(struct FLocSttTicketStruct)]=0;
	
	return true;
}
