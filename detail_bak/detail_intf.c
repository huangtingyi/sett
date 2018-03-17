#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <detail_intf.h>

void mvitem_mfaccsttticket(struct AccSttTicketStruct *pi,struct FAccSttTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FAccSttTicketStruct));

		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));
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
		/*strcpy(TempIn.sCondition, "partition(PART");
		strcat(TempIn.sCondition, sPrepTime);
		strcat(TempIn.sCondition, ")");*/
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
		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));
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
