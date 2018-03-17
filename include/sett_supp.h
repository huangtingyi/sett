#ifndef __SETT_SUPP_H__
#define __SETT_SUPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <bintree.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <wwfile.h>

/*---------�������ִ��� t_template_yd_gw_ue.txt----------*/

/*����ṹ��������*/
struct TTemplateYdGwUeStructOut{

#ifndef T_TEMPLATE_YD_GW_UE_BUFLEN_OUT
#define T_TEMPLATE_YD_GW_UE_BUFLEN_OUT		300
#endif

	struct TTemplateYdGwUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asProdID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asStartTime[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][15];
	char    asEndTime[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][15];
	char    asRateTime[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][15];
	char    asOperationTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][9];
	char    asCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCalledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asBilledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asThirdNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	int     aiCallingAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiCalledAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asInTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asOutTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	int     aiRawUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asRawUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiRateUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asIsFree[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	int     aiRateUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asCalledAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asCallingRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCalledRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCallingRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asCalledRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asTotalDueAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiProdInstID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiRateID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asUpFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asDuration[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asDownFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asFileName[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][61];
	char    asTotalFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asStatus[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][4];
	int     aiBillCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asCurrBalance[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiCreateCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asRateKey1[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asRateKey2[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asRateKey3[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	int     aiPureCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiFileClassID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asExceptionType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][6];
	char    asOrigUsageTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][13];
	int     aiTotalDueUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asStlAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asPostFlag[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	int     aiIsPrepay[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiParentFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asTableName[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCalledCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asSwitchCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asDurationMinnum[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asDurationSec6[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asInTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asOutTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asCallingNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCalledNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asCalledGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asStlObject[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asProdPropID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCallingSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCalledSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiStlDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asPreCallType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asTurnCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][51];
	char    asTurnCodeCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asTurnCodeProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	int     aiTurnCodeCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asTurnCodeOperationTypeGrade[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asTurnType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asTurnCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	char    asSecondCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asSecondCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asSecondCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asSecondCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asPreCallParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asPreCallSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asPreCallSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	char    asPreCallSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asPreCallUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asTurnParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asTurnSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asTurnSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	char    asTurnSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asTurnUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asInTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asOutTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asInTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asOutTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCallingNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCalledNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCallingDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCalledDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asSecondSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asSecondCallingRoamnumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asViewCall[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char	asGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][3];
};


/* ����ṹ��������*/
struct TTemplateYdGwUeStructIn{

#ifndef T_TEMPLATE_YD_GW_UE_BUFLEN_IN
#define T_TEMPLATE_YD_GW_UE_BUFLEN_IN		300
#endif

	struct TTemplateYdGwUeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asProdID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asStartTime[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][15];
	char    asEndTime[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][15];
	char    asRateTime[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][15];
	char    asOperationTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][9];
	char    asCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCalledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asBilledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asThirdNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	int     aiCallingAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiCalledAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asInTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asOutTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	int     aiRawUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asRawUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiRateUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asIsFree[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	int     aiRateUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asCalledAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asCallingRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCalledRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCallingRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asCalledRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asTotalDueAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiProdInstID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiRateID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asUpFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asDuration[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asDownFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asFileName[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][61];
	char    asTotalFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asStatus[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][4];
	int     aiBillCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asCurrBalance[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiCreateCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asRateKey1[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asRateKey2[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asRateKey3[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	int     aiPureCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiFileClassID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asExceptionType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][6];
	char    asOrigUsageTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][13];
	int     aiTotalDueUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asStlAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asPostFlag[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	int     aiIsPrepay[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiParentFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asTableName[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCalledCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asSwitchCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asDurationMinnum[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asDurationSec6[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asInTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asOutTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asCallingNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCalledNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asCalledGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asStlObject[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asProdPropID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCallingSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCalledSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiStlDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asPreCallType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asTurnCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][51];
	char    asTurnCodeCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asTurnCodeProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	int     aiTurnCodeCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asTurnCodeOperationTypeGrade[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asTurnType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asTurnCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	char    asSecondCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asSecondCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asSecondCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asSecondCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asPreCallParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asPreCallSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asPreCallSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	char    asPreCallSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asPreCallUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asTurnParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asTurnSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asTurnSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	char    asTurnSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asTurnUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asInTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asOutTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asInTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asOutTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCallingNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCalledNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCallingDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCalledDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asSecondSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asSecondCallingRoamnumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asViewCall[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char	asGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][3];
};


/*�����ṹ����*/
struct TTemplateYdGwUeStruct{

	struct TTemplateYdGwUeStruct *pNext;
	char    sUsageEventID[19];
	char    sProdID[11];
	char    sStartTime[15];
	char    sEndTime[15];
	char    sRateTime[15];
	char    sOperationTypeID[9];
	char    sCallingNumber[31];
	char    sCalledNumber[31];
	char    sBilledNumber[31];
	char    sThirdNumber[31];
	int     iCallingAreaID;
	int     iCalledAreaID;
	char    sInTrunkNumber[21];
	char    sOutTrunkNumber[21];
	int     iRawUnitType;
	char    sRawUnits[19];
	int     iRateUnitType;
	char    sIsFree[21];
	int     iRateUnits;
	char    sCallingAreaCode[11];
	char    sCalledAreaCode[11];
	char    sCallingRoamNumber[31];
	char    sCalledRoamNumber[31];
	char    sCallingRoamAreaCode[11];
	char    sCalledRoamAreaCode[11];
	char    sTotalDueAmount[19];
	int     iProdInstID;
	int     iRateID;
	char    sUpFlux[19];
	char    sDuration[19];
	int     iCityID;
	char    sDownFlux[19];
	char    sFileName[61];
	char    sTotalFlux[19];
	char    sStatus[4];
	int     iBillCycleSeq;
	char    sCurrBalance[19];
	int     iCreateCycleSeq;
	char    sRateKey1[31];
	char    sRateKey2[31];
	char    sRateKey3[31];
	int     iPureCycleSeq;
	int     iDirection;
	int     iFileClassID;
	char    sExceptionType[6];
	char    sOrigUsageTypeID[13];
	int     iTotalDueUnits;
	char    sStlAmount[19];
	char    sPostFlag[5];
	int     iIsPrepay;
	int     iFileID;
	int     iParentFileID;
	char    sTableName[31];
	char    sCallingCompanyID[19];
	char    sCalledCompanyID[19];
	char    sSwitchCompanyID[19];
	char    sProvinceID[21];
	char    sDurationMinnum[19];
	char    sDurationSec6[19];
	char    sInTrunkGroup[16];
	char    sOutTrunkGroup[16];
	char    sCallingNumberCompanyID[19];
	char    sCalledNumberCompanyID[19];
	char    sCallingGroupID[16];
	char    sCalledGroupID[16];
	char    sStlObject[19];
	char    sProdPropID[19];
	char    sCallingSubType[19];
	char    sCalledSubType[19];
	int     iStlDirection;
	char    sPreCallType[31];
	char    sTurnCode[51];
	char    sTurnCodeCompanyID[11];
	char    sTurnCodeProvinceID[21];
	int     iTurnCodeCityID;
	char    sTurnCodeOperationTypeGrade[31];
	char    sTurnType[31];
	char    sTurnCdrID[5];
	char    sSecondCallingNumber[31];
	char    sSecondCallingAreaCode[11];
	char    sSecondCallingGroupID[31];
	char    sSecondCallingCompanyID[11];
	char    sPreCallParentCdrID[21];
	char    sPreCallSubCdrID[21];
	char    sPreCallSubCdrNum[5];
	char    sPreCallSubCdrSeq[11];
	char    sPreCallUsageEventID[19];
	char    sTurnParentCdrID[21];
	char    sTurnSubCdrID[21];
	char    sTurnSubCdrNum[5];
	char    sTurnSubCdrSeq[11];
	char    sTurnUsageEventID[19];
	char    sInTrunkGenre[21];
	char    sOutTrunkGenre[21];
	char    sInTrunkNetType[21];
	char    sOutTrunkNetType[21];
	char    sCallingNumberType[21];
	char    sCalledNumberType[21];
	char    sCallingDomainID[21];
	char    sCalledDomainID[21];
	char    sSecondSubType[21];
	char    sSecondCallingRoamnumber[31];
	char    sViewCall[11];
/*20140117����*/
	char	sGroupID[3];
	struct TTemplateYdGwUeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FTTemplateYdGwUeStruct{

	char    sUsageEventID[18];
	char    sProdID[10];
	char    sStartTime[14];
	char    sEndTime[14];
	char    sRateTime[14];
	char    sOperationTypeID[8];
	char    sCallingNumber[30];
	char    sCalledNumber[30];
	char    sBilledNumber[30];
	char    sThirdNumber[30];
	char    sCallingAreaID[8];
	char    sCalledAreaID[8];
	char    sInTrunkNumber[20];
	char    sOutTrunkNumber[20];
	char    sRawUnitType[4];
	char    sRawUnits[18];
	char    sRateUnitType[4];
	char    sIsFree[20];
	char    sRateUnits[8];
	char    sCallingAreaCode[10];
	char    sCalledAreaCode[10];
	char    sCallingRoamNumber[30];
	char    sCalledRoamNumber[30];
	char    sCallingRoamAreaCode[10];
	char    sCalledRoamAreaCode[10];
	char    sTotalDueAmount[18];
	char    sProdInstID[8];
	char    sRateID[8];
	char    sUpFlux[18];
	char    sDuration[18];
	char    sCityID[8];
	char    sDownFlux[18];
	char    sFileName[60];
	char    sTotalFlux[18];
	char    sStatus[3];
	char    sBillCycleSeq[8];
	char    sCurrBalance[18];
	char    sCreateCycleSeq[8];
	char    sRateKey1[30];
	char    sRateKey2[30];
	char    sRateKey3[30];
	char    sPureCycleSeq[8];
	char    sDirection[1];
	char    sFileClassID[8];
	char    sExceptionType[5];
	char    sOrigUsageTypeID[12];
	char    sTotalDueUnits[8];
	char    sStlAmount[18];
	char    sPostFlag[4];
	char    sIsPrepay[1];
	char    sFileID[9];
	char    sParentFileID[9];
	char    sTableName[30];
	char    sCallingCompanyID[18];
	char    sCalledCompanyID[18];
	char    sSwitchCompanyID[18];
	char    sProvinceID[20];
	char    sDurationMinnum[18];
	char    sDurationSec6[18];
	char    sInTrunkGroup[15];
	char    sOutTrunkGroup[15];
	char    sCallingNumberCompanyID[18];
	char    sCalledNumberCompanyID[18];
	char    sCallingGroupID[15];
	char    sCalledGroupID[15];
	char    sStlObject[18];
	char    sProdPropID[18];
	char    sCallingSubType[18];
	char    sCalledSubType[18];
	char    sStlDirection[1];
	char    sPreCallType[30];
	char    sTurnCode[50];
	char    sTurnCodeCompanyID[10];
	char    sTurnCodeProvinceID[20];
	char    sTurnCodeCityID[8];
	char    sTurnCodeOperationTypeGrade[30];
	char    sTurnType[30];
	char    sTurnCdrID[4];
	char    sSecondCallingNumber[30];
	char    sSecondCallingAreaCode[10];
	char    sSecondCallingGroupID[30];
	char    sSecondCallingCompanyID[10];
	char    sPreCallParentCdrID[20];
	char    sPreCallSubCdrID[20];
	char    sPreCallSubCdrNum[4];
	char    sPreCallSubCdrSeq[10];
	char    sPreCallUsageEventID[18];
	char    sTurnParentCdrID[20];
	char    sTurnSubCdrID[20];
	char    sTurnSubCdrNum[4];
	char    sTurnSubCdrSeq[10];
	char    sTurnUsageEventID[18];
	char    sInTrunkGenre[20];
	char    sOutTrunkGenre[20];
	char    sInTrunkNetType[20];
	char    sOutTrunkNetType[20];
	char    sCallingNumberType[20];
	char    sCalledNumberType[20];
	char    sCallingDomainID[20];
	char    sCalledDomainID[20];
	char    sSecondSubType[20];
	char    sSecondCallingRoamnumber[30];
	char    sViewCall[10];
};

/*�������ݶ�̬��T_TEMPLATE_YD_GW_UE���ýṹ���巽ʽȡ����*/
int EGetTTemplateYdGwUeToStruct(struct TTemplateYdGwUeStruct *p,
	struct TTemplateYdGwUeStructIn *pSource);

void mvitem_ttemplateydgwue(struct TTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po);

void mvitem_fmttemplateydgwue(struct FTTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po);

void mvitem_mfttemplateydgwue(struct TTemplateYdGwUeStruct *pi,struct FTTemplateYdGwUeStruct *po);

/**�Ա�T_TEMPLATE_YD_GW_UE�������ͷź���**/
void DestroyTTemplateYdGwUe(struct TTemplateYdGwUeStruct *ptHead);

int InitTTemplateYdGwUe(struct TTemplateYdGwUeStruct **pptHead);

/*�������ݽṹ����д��T_TEMPLATE_YD_GW_UE*/
int EInsertStructToTTemplateYdGwUe(struct TTemplateYdGwUeStruct *p,
	int iInsertFlag,struct TTemplateYdGwUeStructOut *pTarget);
/********************************20140910�ӿڸ���*************************************/

/*����ṹ��������*/
struct SettTicketUeStructOut{

#ifndef SETT_TICKET_UE_BUFLEN_OUT
#define SETT_TICKET_UE_BUFLEN_OUT		300
#endif

	struct SettTicketUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[128];
		/* ʹ���¼���ˮ��ʶ */
	char    asUsageEventID[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* ���б��� */
	char    asCityID[SETT_TICKET_UE_BUFLEN_OUT][7];
		/* �������� */
	char    asCdrType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ���г��д��� */
	char    asCallingCityID[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* �����쳣���� */
	char    asCallingException[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ���к������� */
	char    asCallingType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ������Ӫ�� */
	char    asCallingCompCode[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* ��������������� */
	char    asCallingAreaCode[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* ����������к��� */
	char    asCallingNumber[SETT_TICKET_UE_BUFLEN_OUT][31];
		/* ���г��д��� */
	char    asCalledCityID[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* �����쳣���� */
	char    asCalledException[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ���к������� */
	char    asCalledNumberType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ������Ӫ�� */
	char    asCalledCompCode[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* ������ı������� */
	char    asCalledAreaCode[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* ������ı��к��� */
	char    asCalledNumber[SETT_TICKET_UE_BUFLEN_OUT][31];
		/* ��ʼʱ�� */
	char    asStartTime[SETT_TICKET_UE_BUFLEN_OUT][17];
		/* ��ʼʱ�� */
	char    asEndTime[SETT_TICKET_UE_BUFLEN_OUT][17];
		/* ʱ�� */
	char    asDuration[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* ���м̺��� */
	char    asInTrunkNumber[SETT_TICKET_UE_BUFLEN_OUT][12];
		/* ���м���Ӫ�� */
	char    asInCompanyCode[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ���м����� */
	char    asInTrunkNetType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ���м̺��� */
	char    asOutTrunkNumber[SETT_TICKET_UE_BUFLEN_OUT][12];
		/* ���м���Ӫ�� */
	char    asOutCompanyCode[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ���м����� */
	char    asOutTrunkNetType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* �Ƿ���� */
	char    asIsFree[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ���е�ַ���� */
	char    asCallingLocation[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* �ڶ����е�ַ���� */
	char    asSecondCallingLocation[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ԭʼ���к��� */
	char    asOrigCallingNumber[SETT_TICKET_UE_BUFLEN_OUT][37];
		/* ԭʼ���к��� */
	char    asOrigCalledNumber[SETT_TICKET_UE_BUFLEN_OUT][37];
		/* ԭʼ�ڶ����к��� */
	char    asOrigSecondCallingNumber[SETT_TICKET_UE_BUFLEN_OUT][37];
		/* �������� */
	char    asExceptionType[SETT_TICKET_UE_BUFLEN_OUT][11];
		/* ����ǰת���� */
	char    asPreCallType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ת������ */
	char    asTurnType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_TICKET_UE_BUFLEN_OUT][16];
		/* �Ƽ۵�λ���� */
	char    asRateUnitType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* ת����Ľ���ʱ�� */
	char    asStlDuration[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* ���ʱ�ʶ */
	char    asRateID[SETT_TICKET_UE_BUFLEN_OUT][11];
		/* ������� */
	char    asStlAmount[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
	char	asInTrunkSubType[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
	char	asOutTrunkSubType[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* �û�����(���û�����ĩ��λ���飬�����ֵľ���00����) */
	char    asGroupID[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* ��ǰ���������ļ��� */
	char    asFileName[SETT_TICKET_UE_BUFLEN_OUT][65];
		/*��������*/
	char	asCallType[SETT_TICKET_UE_BUFLEN_OUT][3];
	char	asUsageSeq[SETT_TICKET_UE_BUFLEN_OUT][19];
	
};


/* ����ṹ��������*/
struct SettTicketUeStructIn{

#ifndef SETT_TICKET_UE_BUFLEN_IN
#define SETT_TICKET_UE_BUFLEN_IN		300
#endif

	struct SettTicketUeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[128];
	char sCondition[1024];
		/* ʹ���¼���ˮ��ʶ */
	char    asUsageEventID[SETT_TICKET_UE_BUFLEN_IN][19];
		/* ���б��� */
	char    asCityID[SETT_TICKET_UE_BUFLEN_IN][7];
		/* �������� */
	char    asCdrType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ���г��д��� */
	char    asCallingCityID[SETT_TICKET_UE_BUFLEN_IN][9];
		/* �����쳣���� */
	char    asCallingException[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ���к������� */
	char    asCallingType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ������Ӫ�� */
	char    asCallingCompCode[SETT_TICKET_UE_BUFLEN_IN][3];
		/* ��������������� */
	char    asCallingAreaCode[SETT_TICKET_UE_BUFLEN_IN][9];
		/* ����������к��� */
	char    asCallingNumber[SETT_TICKET_UE_BUFLEN_IN][31];
		/* ���г��д��� */
	char    asCalledCityID[SETT_TICKET_UE_BUFLEN_IN][9];
		/* �����쳣���� */
	char    asCalledException[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ���к������� */
	char    asCalledNumberType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ������Ӫ�� */
	char    asCalledCompCode[SETT_TICKET_UE_BUFLEN_IN][3];
		/* ������ı������� */
	char    asCalledAreaCode[SETT_TICKET_UE_BUFLEN_IN][9];
		/* ������ı��к��� */
	char    asCalledNumber[SETT_TICKET_UE_BUFLEN_IN][31];
		/* ��ʼʱ�� */
	char    asStartTime[SETT_TICKET_UE_BUFLEN_IN][17];
		/* ��ʼʱ�� */
	char    asEndTime[SETT_TICKET_UE_BUFLEN_IN][17];
		/* ʱ�� */
	char    asDuration[SETT_TICKET_UE_BUFLEN_IN][19];
		/* ���м̺��� */
	char    asInTrunkNumber[SETT_TICKET_UE_BUFLEN_IN][12];
		/* ���м���Ӫ�� */
	char    asInCompanyCode[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ���м����� */
	char    asInTrunkNetType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ���м̺��� */
	char    asOutTrunkNumber[SETT_TICKET_UE_BUFLEN_IN][12];
		/* ���м���Ӫ�� */
	char    asOutCompanyCode[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ���м����� */
	char    asOutTrunkNetType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* �Ƿ���� */
	char    asIsFree[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ���е�ַ���� */
	char    asCallingLocation[SETT_TICKET_UE_BUFLEN_IN][5];
		/* �ڶ����е�ַ���� */
	char    asSecondCallingLocation[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ԭʼ���к��� */
	char    asOrigCallingNumber[SETT_TICKET_UE_BUFLEN_IN][37];
		/* ԭʼ���к��� */
	char    asOrigCalledNumber[SETT_TICKET_UE_BUFLEN_IN][37];
		/* ԭʼ�ڶ����к��� */
	char    asOrigSecondCallingNumber[SETT_TICKET_UE_BUFLEN_IN][37];
		/* �������� */
	char    asExceptionType[SETT_TICKET_UE_BUFLEN_IN][11];
		/* ����ǰת���� */
	char    asPreCallType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ת������ */
	char    asTurnType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_TICKET_UE_BUFLEN_IN][16];
		/* �Ƽ۵�λ���� */
	char    asRateUnitType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* ת����Ľ���ʱ�� */
	char    asStlDuration[SETT_TICKET_UE_BUFLEN_IN][19];
		/* ���ʱ�ʶ */
	char    asRateID[SETT_TICKET_UE_BUFLEN_IN][11];
		/* ������� */
	char    asStlAmount[SETT_TICKET_UE_BUFLEN_IN][19];
		/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
	char	asInTrunkSubType[SETT_TICKET_UE_BUFLEN_IN][3];
		/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
	char	asOutTrunkSubType[SETT_TICKET_UE_BUFLEN_IN][3];
		/* �û�����(���û�����ĩ��λ���飬�����ֵľ���00����) */
	char    asGroupID[SETT_TICKET_UE_BUFLEN_IN][3];
		/* ��ǰ���������ļ��� */
	char    asFileName[SETT_TICKET_UE_BUFLEN_IN][65];
		/*��������*/
	char	asCallType[SETT_TICKET_UE_BUFLEN_IN][3];
	char	asUsageSeq[SETT_TICKET_UE_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct SettTicketUeStruct{

	struct SettTicketUeStruct *pNext;
	char    sUsageEventID[19];		/* ʹ���¼���ˮ��ʶ */
	char    sCityID[7];		/* ���б��� */
	char    sCdrType[5];		/* �������� */
	char    sCallingCityID[9];		/* ���г��д��� */
	char    sCallingException[5];		/* �����쳣���� */
	char    sCallingType[5];		/* ���к������� */
	char    sCallingCompCode[3];		/* ������Ӫ�� */
	char    sCallingAreaCode[9];		/* ��������������� */
	char    sCallingNumber[31];		/* ����������к��� */
	char    sCalledCityID[9];		/* ���г��д��� */
	char    sCalledException[5];		/* �����쳣���� */
	char    sCalledNumberType[5];		/* ���к������� */
	char    sCalledCompCode[3];		/* ������Ӫ�� */
	char    sCalledAreaCode[9];		/* ������ı������� */
	char    sCalledNumber[31];		/* ������ı��к��� */
	char    sStartTime[17];		/* ��ʼʱ�� */
	char    sEndTime[17];		/* ��ʼʱ�� */
	char    sDuration[19];		/* ʱ�� */
	char    sInTrunkNumber[12];		/* ���м̺��� */
	char    sInCompanyCode[5];		/* ���м���Ӫ�� */
	char    sInTrunkNetType[5];		/* ���м����� */
	char    sOutTrunkNumber[12];		/* ���м̺��� */
	char    sOutCompanyCode[5];		/* ���м���Ӫ�� */
	char    sOutTrunkNetType[5];		/* ���м����� */
	char    sIsFree[5];		/* �Ƿ���� */
	char    sCallingLocation[5];		/* ���е�ַ���� */
	char    sSecondCallingLocation[5];		/* �ڶ����е�ַ���� */
	char    sOrigCallingNumber[37];		/* ԭʼ���к��� */
	char    sOrigCalledNumber[37];		/* ԭʼ���к��� */
	char    sOrigSecondCallingNumber[37];		/* ԭʼ�ڶ����к��� */
	char    sExceptionType[11];		/* �������� */
	char    sPreCallType[5];		/* ����ǰת���� */
	char    sTurnType[5];		/* ת������ */
	char    sProdID[16];		/* �����Ʒ��ʶ */
	char    sRateUnitType[5];		/* �Ƽ۵�λ���� */
	char    sStlDuration[19];		/* ת����Ľ���ʱ�� */
	char    sRateID[11];		/* ���ʱ�ʶ */
	char    sStlAmount[19];		/* ������� */
	char	sInTrunkSubType[3];	/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
	char	sOutTrunkSubType[3];	/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
	char    sGroupID[3];		/* �û�����(���û�����ĩ��λ���飬�����ֵľ���00����) */
	char    sFileName[65];		/* ��ǰ���������ļ��� */
	char	sCallType[3];		/* �������� */
	char	sUsageSeq[19];
	struct SettTicketUeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettTicketUeStruct{

	char    sUsageEventID[18];		/* ʹ���¼���ˮ��ʶ */
	char    sCityID[6];		/* ���б��� */
	char    sCdrType[4];		/* �������� */
	char    sCallingCityID[8];		/* ���г��д��� */
	char    sCallingException[4];		/* �����쳣���� */
	char    sCallingType[4];		/* ���к������� */
	char    sCallingCompCode[2];		/* ������Ӫ�� */
	char    sCallingAreaCode[8];		/* ��������������� */
	char    sCallingNumber[30];		/* ����������к��� */
	char    sCalledCityID[8];		/* ���г��д��� */
	char    sCalledException[4];		/* �����쳣���� */
	char    sCalledNumberType[4];		/* ���к������� */
	char    sCalledCompCode[2];		/* ������Ӫ�� */
	char    sCalledAreaCode[8];		/* ������ı������� */
	char    sCalledNumber[30];		/* ������ı��к��� */
	char    sStartTime[16];		/* ��ʼʱ�� */
	char    sEndTime[16];		/* ��ʼʱ�� */
	char    sDuration[18];		/* ʱ�� */
	char    sInTrunkNumber[11];		/* ���м̺��� */
	char    sInCompanyCode[4];		/* ���м���Ӫ�� */
	char    sInTrunkNetType[4];		/* ���м����� */
	char    sOutTrunkNumber[11];		/* ���м̺��� */
	char    sOutCompanyCode[4];		/* ���м���Ӫ�� */
	char    sOutTrunkNetType[4];		/* ���м����� */
	char    sIsFree[4];		/* �� ����� */
	char    sCallingLocation[4];		/* ���е�ַ���� */
	char    sSecondCallingLocation[4];		/* �ڶ����е�ַ���� */
	char    sOrigCallingNumber[36];		/* ԭʼ���к��� */
	char    sOrigCalledNumber[36];		/* ԭʼ���к��� */
	char    sOrigSecondCallingNumber[36];		/* ԭʼ�ڶ����к��� */
	char    sExceptionType[10];		/* �������� */
	char    sPreCallType[4];		/* ����ǰת���� */
	char    sTurnType[4];		/* ת������ */
	char    sProdID[15];		/* �����Ʒ��ʶ */
	char    sRateUnitType[4];		/* �Ƽ۵�λ���� */
	char    sStlDuration[18];		/* ת����Ľ���ʱ�� */
	char    sRateID[10];		/* ���ʱ�ʶ */
	char    sStlAmount[18];		/* ������� */
	char	sInTrunkSubType[2];	/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
	char	sOutTrunkSubType[2];	/* ���м�������   ȡֵ��0-���� ��1-�ƶ����� */
};


/*�������ݶ�̬��SETT_TICKET_UE���ýṹ���巽ʽȡ����*/
int EGetSettTicketUeToStruct(struct SettTicketUeStruct *p,
	struct SettTicketUeStructIn *pSource);
void mvitem_settticketue(struct SettTicketUeStruct *pi,struct SettTicketUeStruct *po);
void mvitem_fmsettticketue(struct FSettTicketUeStruct *pi,struct SettTicketUeStruct *po);
void mvitem_mfsettticketue(struct SettTicketUeStruct *pi,struct FSettTicketUeStruct *po);
/**�Ա�SETT_TICKET_UE�������ͷź���**/
void DestroySettTicketUe(struct SettTicketUeStruct *ptHead);
int InitSettTicketUe(struct SettTicketUeStruct **pptHead);
/*�������ݽṹ����д��SETT_TICKET_UE*/
int EInsertStructToSettTicketUe(struct SettTicketUeStruct *p,
	int iInsertFlag,struct SettTicketUeStructOut *pTarget);


/*����ṹ��������*/
struct SettTicketSmStructOut{

#ifndef SETT_TICKET_SM_BUFLEN_OUT
#define SETT_TICKET_SM_BUFLEN_OUT		300
#endif

	struct SettTicketSmStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[256];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_TICKET_SM_BUFLEN_OUT][31];
		/* ��ʼʱ�� */
	char    asStartTime[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* ����ʱ�� */
	char    asEndTime[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* ���к��� */
	char    asCallingNumber[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* ���г��д��� */
	char    asCallingCityID[SETT_TICKET_SM_BUFLEN_OUT][9];
		/* ������Ӫ�� */
	char    asCallingCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* ���к������� */
	char    asCallingNumberType[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* ���к��� */
	char    asCalledNumber[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* ���г��д��� */
	char    asCalledCityID[SETT_TICKET_SM_BUFLEN_OUT][9];
		/* ������Ӫ�� */
	char    asCalledCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* ���к������� */
	char    asCalledNumberType[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* ����������б��� */
	int     aiCityID[SETT_TICKET_SM_BUFLEN_OUT];
		/* �Ƿ���� */
	char    asIsFree[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* �������� */
	int     aiBillCycleSeq[SETT_TICKET_SM_BUFLEN_OUT];
		/* �������� */
	char    asExceptionType[SETT_TICKET_SM_BUFLEN_OUT][9];
		/* ������ */
	char    asStlAmount[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* �������� */
	char    asCallingAreaCode[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* �������� */
	char    asCalledAreaCode[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* ���㷽�� */
	char    asStlDirection[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* ������Ԫ */
	char    asUpGw[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* ������Ԫ */
	char    asDownGw[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* ������Ԫ��Ӫ�� */
	char    asUpCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* ������Ԫ��Ӫ�� */
	char    asDownCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* ʹ���¼���ˮ��ʶ */
	char    asUsageEventID[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* �ļ��� */
	char    asFileName[SETT_TICKET_SM_BUFLEN_OUT][65];
		/* ������� */
	char    asGroupID[SETT_TICKET_SM_BUFLEN_OUT][4];
		/* �������� */
	char	asCallType[SETT_TICKET_SM_BUFLEN_OUT][3];
};


/* ����ṹ��������*/
struct SettTicketSmStructIn{

#ifndef SETT_TICKET_SM_BUFLEN_IN
#define SETT_TICKET_SM_BUFLEN_IN		300
#endif

	struct SettTicketSmStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[256];
	char sCondition[1024];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_TICKET_SM_BUFLEN_IN][31];
		/* ��ʼʱ�� */
	char    asStartTime[SETT_TICKET_SM_BUFLEN_IN][19];
		/* ����ʱ�� */
	char    asEndTime[SETT_TICKET_SM_BUFLEN_IN][19];
		/* ���к��� */
	char    asCallingNumber[SETT_TICKET_SM_BUFLEN_IN][33];
		/* ���г��д��� */
	char    asCallingCityID[SETT_TICKET_SM_BUFLEN_IN][9];
		/* ������Ӫ�� */
	char    asCallingCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* ���к������� */
	char    asCallingNumberType[SETT_TICKET_SM_BUFLEN_IN][5];
		/* ���к��� */
	char    asCalledNumber[SETT_TICKET_SM_BUFLEN_IN][33];
		/* ���г��д��� */
	char    asCalledCityID[SETT_TICKET_SM_BUFLEN_IN][9];
		/* ������Ӫ�� */
	char    asCalledCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* ���к������� */
	char    asCalledNumberType[SETT_TICKET_SM_BUFLEN_IN][5];
		/* ����������б��� */
	int     aiCityID[SETT_TICKET_SM_BUFLEN_IN];
		/* �Ƿ���� */
	char    asIsFree[SETT_TICKET_SM_BUFLEN_IN][5];
		/* �������� */
	int     aiBillCycleSeq[SETT_TICKET_SM_BUFLEN_IN];
		/* �������� */
	char    asExceptionType[SETT_TICKET_SM_BUFLEN_IN][9];
		/* ������ */
	char    asStlAmount[SETT_TICKET_SM_BUFLEN_IN][19];
		/* �������� */
	char    asCallingAreaCode[SETT_TICKET_SM_BUFLEN_IN][33];
		/* �������� */
	char    asCalledAreaCode[SETT_TICKET_SM_BUFLEN_IN][33];
		/* ���㷽�� */
	char    asStlDirection[SETT_TICKET_SM_BUFLEN_IN][5];
		/* ������Ԫ */
	char    asUpGw[SETT_TICKET_SM_BUFLEN_IN][33];
		/* ������Ԫ */
	char    asDownGw[SETT_TICKET_SM_BUFLEN_IN][33];
		/* ������Ԫ��Ӫ�� */
	char    asUpCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* ������Ԫ��Ӫ�� */
	char    asDownCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* ʹ���¼���ˮ��ʶ */
	char    asUsageEventID[SETT_TICKET_SM_BUFLEN_IN][19];
		/* �ļ��� */
	char    asFileName[SETT_TICKET_SM_BUFLEN_IN][65];
		/* ������� */
	char    asGroupID[SETT_TICKET_SM_BUFLEN_IN][4];
		/* �������� */
	char	asCallType[SETT_TICKET_SM_BUFLEN_IN][3];
};


/*�����ṹ����*/
struct SettTicketSmStruct{

	struct SettTicketSmStruct *pNext;
	char    sProdID[31];		/* �����Ʒ��ʶ */
	char    sStartTime[19];		/* ��ʼʱ�� */
	char    sEndTime[19];		/* ����ʱ�� */
	char    sCallingNumber[33];		/* ���к��� */
	char    sCallingCityID[9];		/* ���г��д��� */
	char    sCallingCompanyID[3];		/* ������Ӫ�� */
	char    sCallingNumberType[5];		/* ���к������� */
	char    sCalledNumber[33];		/* ���к��� */
	char    sCalledCityID[9];		/* ���г��д��� */
	char    sCalledCompanyID[3];		/* ������Ӫ�� */
	char    sCalledNumberType[5];		/* ���к������� */
	int     iCityID;		/* ����������б��� */
	char    sIsFree[5];		/* �Ƿ���� */
	int     iBillCycleSeq;		/* �������� */
	char    sExceptionType[9];		/* �������� */
	char    sStlAmount[19];		/* ������ */
	char    sCallingAreaCode[33];		/* �������� */
	char    sCalledAreaCode[33];		/* �������� */
	char    sStlDirection[5];		/* ���㷽�� */
	char    sUpGw[33];		/* ������Ԫ */
	char    sDownGw[33];		/* ������Ԫ */
	char    sUpCompanyID[3];		/* ������Ԫ��Ӫ�� */
	char    sDownCompanyID[3];		/* ������Ԫ��Ӫ�� */
	char    sUsageEventID[19];		/* ʹ���¼���ˮ��ʶ */
	char    sFileName[65];		/* �ļ��� */
	char    sGroupID[4];		/* ������� */
	char	sCallType[3];		/* �������� */
	struct SettTicketSmStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettTicketSmStruct{

	char    sProdID[30];		/* �����Ʒ��ʶ */
	char    sStartTime[18];		/* ��ʼʱ�� */
	char    sEndTime[18];		/* ����ʱ�� */
	char    sCallingNumber[32];		/* ���к��� */
	char    sCallingCityID[8];		/* ���г��д��� */
	char    sCallingCompanyID[2];		/* ������Ӫ�� */
	char    sCallingNumberType[4];		/* ���к������� */
	char    sCalledNumber[32];		/* ���к��� */
	char    sCalledCityID[8];		/* ���г��д��� */
	char    sCalledCompanyID[2];		/* ������Ӫ�� */
	char    sCalledNumberType[4];		/* ���к������� */
	char    sCityID[8];		/* ����������б��� */
	char    sIsFree[4];		/* �Ƿ���� */
	char    sBillCycleSeq[6];		/* �������� */
	char    sExceptionType[8];		/* �������� */
	char    sStlAmount[18];		/* ������ */
	char    sCallingAreaCode[32];		/* �������� */
	char    sCalledAreaCode[32];		/* �������� */
	char    sStlDirection[4];		/* ���㷽�� */
	char    sUpGw[32];		/* ������Ԫ */
	char    sDownGw[32];		/* ������Ԫ */
	char    sUpCompanyID[2];		/* ������Ԫ��Ӫ�� */
	char    sDownCompanyID[2];		/* ������Ԫ��Ӫ�� */
	char    sUsageEventID[18];		/* ʹ���¼���ˮ��ʶ */
};


/*�������ݶ�̬��SETT_TICKET_SM���ýṹ���巽ʽȡ����*/
int EGetSettTicketSmToStruct(struct SettTicketSmStruct *p,
	struct SettTicketSmStructIn *pSource);
void mvitem_settticketsm(struct SettTicketSmStruct *pi,struct SettTicketSmStruct *po);
void mvitem_fmsettticketsm(struct FSettTicketSmStruct *pi,struct SettTicketSmStruct *po);
void mvitem_mfsettticketsm(struct SettTicketSmStruct *pi,struct FSettTicketSmStruct *po);
/**�Ա�SETT_TICKET_SM�������ͷź���**/
void DestroySettTicketSm(struct SettTicketSmStruct *ptHead);
int InitSettTicketSm(struct SettTicketSmStruct **pptHead);
/*�������ݽṹ����д��SETT_TICKET_SM*/
int EInsertStructToSettTicketSm(struct SettTicketSmStruct *p,
	int iInsertFlag,struct SettTicketSmStructOut *pTarget);



/*����ṹ��������*/
struct SettTicketMmsStructOut{

#ifndef SETT_TICKET_MMS_BUFLEN_OUT
#define SETT_TICKET_MMS_BUFLEN_OUT		300
#endif

	struct SettTicketMmsStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[256];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_TICKET_MMS_BUFLEN_OUT][31];
		/* ��ʼʱ�� */
	char    asStartTime[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* ����ʱ�� */
	char    asEndTime[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* ���к��� */
	char    asCallingNumber[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ���к��� */
	char    asCalledNumber[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ҵ����� */
	char    asOperationTypeID[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* ����������б��� */
	int     aiCityID[SETT_TICKET_MMS_BUFLEN_OUT];
		/* �Ƿ���� */
	char    asIsFree[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* �Ƽ۵�λ���� */
	char    asRateUnitType[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* �Ƽ۵�λ�� */
	char    asRateUnits[SETT_TICKET_MMS_BUFLEN_OUT][13];
		/* �������� */
	int     aiBillCycleSeq[SETT_TICKET_MMS_BUFLEN_OUT];
		/* �������� */
	char    asExceptionType[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* ʡ�ݱ��� */
	char    asProvinceID[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* ���з���ID */
	char    asCallingGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ���з���ID */
	char    asCalledGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ���й�����Ӫ�� */
	char    asCallingCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* ���й�����Ӫ�� */
	char    asCalledCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* ������� */
	char    asStlObject[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* �������λ�����壩 */
	char    asStlAmount[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* �������� */
	char    asCallingAreaCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* �������� */
	char    asCalledAreaCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ���㷽�� */
	char    asStlDirection[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* ������Ԫ */
	char    asUpGw[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ������Ԫ */
	char    asDownGw[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ������Ԫ���� */
	char    asUpgwGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ������Ԫ���� */
	char    asDownGwGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ������Ԫ��Ӫ�� */
	char    asUpCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ������Ԫ��Ӫ�� */
	char    asDownCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ʹ���¼���ˮ��ʶ */
	char    asUsageEventID[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* ���е��д��� */
	char    asCallingCityCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* ���е��д��� */
	char    asCalledCityCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* �ļ��� */
	char    asFileName[SETT_TICKET_MMS_BUFLEN_OUT][65];
		/* ����ID */
	char    asGroupID[SETT_TICKET_MMS_BUFLEN_OUT][3];
		/* ������ */
	char    asCallType[SETT_TICKET_MMS_BUFLEN_OUT][3];
};


/* ����ṹ��������*/
struct SettTicketMmsStructIn{

#ifndef SETT_TICKET_MMS_BUFLEN_IN
#define SETT_TICKET_MMS_BUFLEN_IN		300
#endif

	struct SettTicketMmsStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[256];
	char sCondition[1024];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_TICKET_MMS_BUFLEN_IN][31];
		/* ��ʼʱ�� */
	char    asStartTime[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* ����ʱ�� */
	char    asEndTime[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* ���к��� */
	char    asCallingNumber[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ���к��� */
	char    asCalledNumber[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ҵ����� */
	char    asOperationTypeID[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* ����������б��� */
	int     aiCityID[SETT_TICKET_MMS_BUFLEN_IN];
		/* �Ƿ���� */
	char    asIsFree[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* �Ƽ۵�λ���� */
	char    asRateUnitType[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* �Ƽ۵�λ�� */
	char    asRateUnits[SETT_TICKET_MMS_BUFLEN_IN][13];
		/* �������� */
	int     aiBillCycleSeq[SETT_TICKET_MMS_BUFLEN_IN];
		/* �������� */
	char    asExceptionType[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* ʡ�ݱ��� */
	char    asProvinceID[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* ���з���ID */
	char    asCallingGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ���з���ID */
	char    asCalledGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ���й�����Ӫ�� */
	char    asCallingCompanyID[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* ���й�����Ӫ�� */
	char    asCalledCompanyID[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* ������� */
	char    asStlObject[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* �������λ�����壩 */
	char    asStlAmount[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* �������� */
	char    asCallingAreaCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* �������� */
	char    asCalledAreaCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ���㷽�� */
	char    asStlDirection[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* ������Ԫ */
	char    asUpGw[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ������Ԫ */
	char    asDownGw[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ������Ԫ���� */
	char    asUpgwGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ������Ԫ���� */
	char    asDownGwGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ������Ԫ��Ӫ�� */
	char    asUpCompanyID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ������Ԫ��Ӫ�� */
	char    asDownCompanyID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ʹ���¼���ˮ��ʶ */
	char    asUsageEventID[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* ���е��д��� */
	char    asCallingCityCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* ���е��д��� */
	char    asCalledCityCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* �ļ��� */
	char    asFileName[SETT_TICKET_MMS_BUFLEN_IN][65];
		/* ����ID */
	char    asGroupID[SETT_TICKET_MMS_BUFLEN_IN][3];
		/* ������ */
	char    asCallType[SETT_TICKET_MMS_BUFLEN_IN][3];
};


/*�����ṹ����*/
struct SettTicketMmsStruct{

	struct SettTicketMmsStruct *pNext;
	char    sProdID[31];		/* �����Ʒ��ʶ */
	char    sStartTime[19];		/* ��ʼʱ�� */
	char    sEndTime[19];		/* ����ʱ�� */
	char    sCallingNumber[33];		/* ���к��� */
	char    sCalledNumber[33];		/* ���к��� */
	char    sOperationTypeID[9];		/* ҵ����� */
	int     iCityID;		/* ����������б��� */
	char    sIsFree[5];		/* �Ƿ���� */
	char    sRateUnitType[5];		/* �Ƽ۵�λ���� */
	char    sRateUnits[13];		/* �Ƽ۵�λ�� */
	int     iBillCycleSeq;		/* �������� */
	char    sExceptionType[9];		/* �������� */
	char    sProvinceID[5];		/* ʡ�ݱ��� */
	char    sCallingGroupID[33];		/* ���з���ID */
	char    sCalledGroupID[33];		/* ���з���ID */
	char    sCallingCompanyID[9];		/* ���й�����Ӫ�� */
	char    sCalledCompanyID[9];		/* ���й�����Ӫ�� */
	char    sStlObject[9];		/* ������� */
	char    sStlAmount[19];		/* �������λ�����壩 */
	char    sCallingAreaCode[33];		/* �������� */
	char    sCalledAreaCode[33];		/* �������� */
	char    sStlDirection[5];		/* ���㷽�� */
	char    sUpGw[33];		/* ������Ԫ */
	char    sDownGw[33];		/* ������Ԫ */
	char    sUpgwGroupID[33];		/* ������Ԫ���� */
	char    sDownGwGroupID[33];		/* ������Ԫ���� */
	char    sUpCompanyID[33];		/* ������Ԫ��Ӫ�� */
	char    sDownCompanyID[33];		/* ������Ԫ��Ӫ�� */
	char    sUsageEventID[19];		/* ʹ���¼���ˮ��ʶ */
	char    sCallingCityCode[33];		/* ���е��д��� */
	char    sCalledCityCode[33];		/* ���е��д��� */
	char    sFileName[65];		/* �ļ��� */
	char    sGroupID[3];		/* ����ID */
	char    sCallType[3];		/* ������ */
	struct SettTicketMmsStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettTicketMmsStruct{

	char    sProdID[30];		/* �����Ʒ��ʶ */
	char    sStartTime[18];		/* ��ʼʱ�� */
	char    sEndTime[18];		/* ����ʱ�� */
	char    sCallingNumber[32];		/* ���к��� */
	char    sCalledNumber[32];		/* ���к��� */
	char    sOperationTypeID[8];		/* ҵ����� */
	char    sCityID[8];		/* ����������б��� */
	char    sIsFree[4];		/* �Ƿ���� */
	char    sRateUnitType[4];		/* �Ƽ۵�λ���� */
	char    sRateUnits[12];		/* �Ƽ۵�λ�� */
	char    sBillCycleSeq[6];		/* �������� */
	char    sExceptionType[8];		/* �������� */
	char    sProvinceID[4];		/* ʡ�ݱ��� */
	char    sCallingGroupID[32];		/* ���з���ID */
	char    sCalledGroupID[32];		/* ���з���ID */
	char    sCallingCompanyID[8];		/* ���й�����Ӫ�� */
	char    sCalledCompanyID[8];		/* ���й�����Ӫ�� */
	char    sStlObject[8];		/* ������� */
	char    sStlAmount[18];		/* �������λ�����壩 */
	char    sCallingAreaCode[32];		/* �������� */
	char    sCalledAreaCode[32];		/* �������� */
	char    sStlDirection[4];		/* ���㷽�� */
	char    sUpGw[32];		/* ������Ԫ */
	char    sDownGw[32];		/* ������Ԫ */
	char    sUpgwGroupID[32];		/* ������Ԫ���� */
	char    sDownGwGroupID[32];		/* ������Ԫ���� */
	char    sUpCompanyID[32];		/* ������Ԫ��Ӫ�� */
	char    sDownCompanyID[32];		/* ������Ԫ��Ӫ�� */
	char    sUsageEventID[18];		/* ʹ���¼���ˮ��ʶ */
	char    sCallingCityCode[32];		/* ���е��д��� */
	char    sCalledCityCode[32];		/* ���е��д��� */
};



/*�������ݶ�̬��SETT_TICKET_MMS���ýṹ���巽ʽȡ����*/
int EGetSettTicketMmsToStruct(struct SettTicketMmsStruct *p,
	struct SettTicketMmsStructIn *pSource);
void mvitem_settticketmms(struct SettTicketMmsStruct *pi,struct SettTicketMmsStruct *po);
void mvitem_fmsettticketmms(struct FSettTicketMmsStruct *pi,struct SettTicketMmsStruct *po);
void mvitem_mfsettticketmms(struct SettTicketMmsStruct *pi,struct FSettTicketMmsStruct *po);
/**�Ա�SETT_TICKET_MMS�������ͷź���**/
void DestroySettTicketMms(struct SettTicketMmsStruct *ptHead);
int InitSettTicketMms(struct SettTicketMmsStruct **pptHead);
/*�������ݽṹ����д��SETT_TICKET_MMS*/
int EInsertStructToSettTicketMms(struct SettTicketMmsStruct *p,
	int iInsertFlag,struct SettTicketMmsStructOut *pTarget);


/*********************************20140910�ӿڸ���******************************************/

struct SettleBintreeStruct{
	
	char sNetWork[4];
	char sOperators[4];
	int iCnt;
	BINTREE *ptRoot;
};

/*����ṹ��������*/
struct SettBillStorLogStructOut{

#ifndef SETT_BILL_STOR_LOG_BUFLEN_OUT
#define SETT_BILL_STOR_LOG_BUFLEN_OUT		300
#endif

	struct SettBillStorLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiSettBillStorSeq[SETT_BILL_STOR_LOG_BUFLEN_OUT];
	char    asFileName[SETT_BILL_STOR_LOG_BUFLEN_OUT][65];
	char    asFileDate[SETT_BILL_STOR_LOG_BUFLEN_OUT][9];
	char    asDealTime[SETT_BILL_STOR_LOG_BUFLEN_OUT][15];
	char    asState[SETT_BILL_STOR_LOG_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
struct SettBillStorLogStructIn{

#ifndef SETT_BILL_STOR_LOG_BUFLEN_IN
#define SETT_BILL_STOR_LOG_BUFLEN_IN		300
#endif

	struct SettBillStorLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiSettBillStorSeq[SETT_BILL_STOR_LOG_BUFLEN_IN];
	char    asFileName[SETT_BILL_STOR_LOG_BUFLEN_IN][65];
	char    asFileDate[SETT_BILL_STOR_LOG_BUFLEN_IN][9];
	char    asDealTime[SETT_BILL_STOR_LOG_BUFLEN_IN][15];
	char    asState[SETT_BILL_STOR_LOG_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct SettBillStorLogStruct{

	struct SettBillStorLogStruct *pNext;
	int     iSettBillStorSeq;
	char    sFileName[65];
	char    sFileDate[9];
	char    sDealTime[15];
	char    sState[2];
	int	iFileSize;
	int	iFileLines;
	struct SettBillStorLogStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettBillStorLogStruct{

	char    sSettBillStorSeq[9];
	char    sFileName[64];
	char    sFileDate[8];
	char    sDealTime[14];
	char    sState[1];
};
int SDInsertStructToSettBillStorLog(struct SettBillStorLogStruct *p,char sTableName[]);
int SDGetSettBillStorLogToStruct(struct SettBillStorLogStruct *p,char sTableName[],char sCondition[]);

/*����ṹ��������*/
struct TicketTypeMapStructOut{

#ifndef TICKET_TYPE_MAP_BUFLEN_OUT
#define TICKET_TYPE_MAP_BUFLEN_OUT		300
#endif

	struct TicketTypeMapStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiReportItemID[TICKET_TYPE_MAP_BUFLEN_OUT];
	char    asProdID[TICKET_TYPE_MAP_BUFLEN_OUT][11];
	char    asInTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_OUT][2];
	char    asOutTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_OUT][2];
	char    asCallType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* ����ʶ:1����IP��2�������ˣ�3����ת�� */
	char    asFlag[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* ��������,0��֧��, 1������ */
	char    asFeeType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* ��Ʒ����,1�Ǳ��ؽ���, 0������ */
	char    asProdType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
struct TicketTypeMapStructIn{

#ifndef TICKET_TYPE_MAP_BUFLEN_IN
#define TICKET_TYPE_MAP_BUFLEN_IN		300
#endif

	struct TicketTypeMapStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiReportItemID[TICKET_TYPE_MAP_BUFLEN_IN];
	char    asProdID[TICKET_TYPE_MAP_BUFLEN_IN][11];
	char    asInTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_IN][2];
	char    asOutTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_IN][2];
	char    asCallType[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* ����ʶ:1����IP��2�������ˣ�3����ת�� */
	char    asFlag[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* ��������,0��֧��, 1������ */
	char    asFeeType[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* ��Ʒ����,1�Ǳ��ؽ���, 0������ */
	char    asProdType[TICKET_TYPE_MAP_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct TicketTypeMapStruct{

	struct TicketTypeMapStruct *pNext;
	int     iReportItemID;
	char    sProdID[11];
	char    sInTrunkCarrID[2];
	char    sOutTrunkCarrID[2];
	char    sCallType[2];
	char    sFlag[2];		/* ����ʶ:1����IP��2�������ˣ�3����ת�� */
	char    sFeeType[2];		/* ��������,0��֧��, 1������ */
	char    sProdType[2];		/* ��Ʒ����,1�Ǳ��ؽ���, 0������ */
	struct TicketTypeMapStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FTicketTypeMapStruct{

	char    sReportItemID[8];
	char    sProdID[10];
	char    sInTrunkCarrID[1];
	char    sOutTrunkCarrID[1];
	char    sCallType[1];
	char    sFlag[1];		/* ����ʶ:1����IP��2�������ˣ�3����ת�� */
	char    sFeeType[1];		/* ��������,0��֧��, 1������ */
	char    sProdType[1];		/* ��Ʒ����,1�Ǳ��ؽ���, 0������ */
};

/*�������ݶ�̬��TICKET_TYPE_MAP���ýṹ���巽ʽȡ����*/
int EGetTicketTypeMapToStruct(struct TicketTypeMapStruct *p,
	struct TicketTypeMapStructIn *pSource);
int InitTicketTypeMap(struct TicketTypeMapStruct **pptHead);


/**һ��ͳ�Ʋ���**/
/*����ṹ��������*/
struct SettMTicketUeStructOut{

#ifndef SETT_M_TICKET_UE_BUFLEN_OUT
#define SETT_M_TICKET_UE_BUFLEN_OUT		300
#endif

	struct SettMTicketUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[128];
		/* ���б��� */
	char    asCityID[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* ���г��д��� */
	char    asCallingCityID[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* ���к������� */
	char    asCallingType[SETT_M_TICKET_UE_BUFLEN_OUT][5];
		/* ������Ӫ�� */
	char    asCallingCompCode[SETT_M_TICKET_UE_BUFLEN_OUT][3];
		/* ��������������� */
	char    asCallingAreaCode[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* ����������к��� */
	char    asCallingNumber[SETT_M_TICKET_UE_BUFLEN_OUT][31];
		/* ���г��д��� */
	char    asCalledCityID[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* ���к������� */
	char    asCalledNumberType[SETT_M_TICKET_UE_BUFLEN_OUT][5];
		/* ������Ӫ�� */
	char    asCalledCompCode[SETT_M_TICKET_UE_BUFLEN_OUT][3];
		/* ������ı������� */
	char    asCalledAreaCode[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* ������ı��к��� */
	char    asCalledNumber[SETT_M_TICKET_UE_BUFLEN_OUT][31];
		/* ʱ�� */
	char    asDuration[SETT_M_TICKET_UE_BUFLEN_OUT][19];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_M_TICKET_UE_BUFLEN_OUT][16];
		/* ת����Ľ���ʱ�� */
	char    asStlDuration[SETT_M_TICKET_UE_BUFLEN_OUT][19];
		/* ������� */
	char    asStlAmount[SETT_M_TICKET_UE_BUFLEN_OUT][19];
		/* ������ */
	int     aiSettCnt[SETT_M_TICKET_UE_BUFLEN_OUT];
		/* �������� */
	char    asCallType[SETT_M_TICKET_UE_BUFLEN_OUT][3];
		/* ����ʱ�� */
	char    asSettDate[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* ���з��� */
	char    asGroupID[SETT_M_TICKET_UE_BUFLEN_OUT][4];
		/* ���з��� */
	char    asOtherGroupID[SETT_M_TICKET_UE_BUFLEN_OUT][4];
		/* ������ID */
	int     aiReportItemID[SETT_M_TICKET_UE_BUFLEN_OUT];
	
	char	asCallingNbrType[SETT_M_TICKET_UE_BUFLEN_OUT][3];	
	char	asCalledNbrType[SETT_M_TICKET_UE_BUFLEN_OUT][3];
	char	asSettDirection[SETT_M_TICKET_UE_BUFLEN_OUT][3];
	char	asSettCarrID[SETT_M_TICKET_UE_BUFLEN_OUT][3];
};


/* ����ṹ��������*/
struct SettMTicketUeStructIn{

#ifndef SETT_M_TICKET_UE_BUFLEN_IN
#define SETT_M_TICKET_UE_BUFLEN_IN		300
#endif

	struct SettMTicketUeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[128];
	char sCondition[1024];
		/* ���б��� */
	char    asCityID[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* ���г��д��� */
	char    asCallingCityID[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* ���к������� */
	char    asCallingType[SETT_M_TICKET_UE_BUFLEN_IN][5];
		/* ������Ӫ�� */
	char    asCallingCompCode[SETT_M_TICKET_UE_BUFLEN_IN][3];
		/* ��������������� */
	char    asCallingAreaCode[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* ����������к��� */
	char    asCallingNumber[SETT_M_TICKET_UE_BUFLEN_IN][31];
		/* ���г��д��� */
	char    asCalledCityID[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* ���к������� */
	char    asCalledNumberType[SETT_M_TICKET_UE_BUFLEN_IN][5];
		/* ������Ӫ�� */
	char    asCalledCompCode[SETT_M_TICKET_UE_BUFLEN_IN][3];
		/* ������ı������� */
	char    asCalledAreaCode[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* ������ı��к��� */
	char    asCalledNumber[SETT_M_TICKET_UE_BUFLEN_IN][31];
		/* ʱ�� */
	char    asDuration[SETT_M_TICKET_UE_BUFLEN_IN][19];
		/* �����Ʒ��ʶ */
	char    asProdID[SETT_M_TICKET_UE_BUFLEN_IN][16];
		/* ת����Ľ���ʱ�� */
	char    asStlDuration[SETT_M_TICKET_UE_BUFLEN_IN][19];
		/* ������� */
	char    asStlAmount[SETT_M_TICKET_UE_BUFLEN_IN][19];
		/* ������ */
	int     aiSettCnt[SETT_M_TICKET_UE_BUFLEN_IN];
		/* �������� */
	char    asCallType[SETT_M_TICKET_UE_BUFLEN_IN][3];
		/* ����ʱ�� */
	char    asSettDate[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* ���з��� */
	char    asGroupID[SETT_M_TICKET_UE_BUFLEN_IN][4];
		/* ���з��� */
	char    asOtherGroupID[SETT_M_TICKET_UE_BUFLEN_IN][4];
		/* ������ID */
	int     aiReportItemID[SETT_M_TICKET_UE_BUFLEN_IN];
	
	char	asCallingNbrType[SETT_M_TICKET_UE_BUFLEN_IN][3];	
	char	asCalledNbrType[SETT_M_TICKET_UE_BUFLEN_IN][3];
	char	asSettDirection[SETT_M_TICKET_UE_BUFLEN_IN][3];
	char	asSettCarrID[SETT_M_TICKET_UE_BUFLEN_IN][3];
};


/*�����ṹ����*/
struct SettMTicketUeStruct{

	struct SettMTicketUeStruct *pNext;
	char    sCityID[9];		/* ���б��� */
	char    sCallingCityID[9];		/* ���г��д��� */
	char    sCallingType[5];		/* ���к������� */
	char    sCallingCompCode[3];		/* ������Ӫ�� */
	char    sCallingAreaCode[9];		/* ��������������� */
	char    sCallingNumber[31];		/* ����������к��� */
	char    sCalledCityID[9];		/* ���г��д��� */
	char    sCalledNumberType[5];		/* ���к������� */
	char    sCalledCompCode[3];		/* ������Ӫ�� */
	char    sCalledAreaCode[9];		/* ������ı������� */
	char    sCalledNumber[31];		/* ������ı��к��� */
	char    sDuration[19];		/* ʱ�� */
	double	dDuration;
	char    sProdID[16];		/* �����Ʒ��ʶ */
	char    sStlDuration[19];		/* ת����Ľ���ʱ�� */
	double	dStlDuration;	
	char    sStlAmount[19];		/* ������� */
	double	dStlAmount;
	int     iSettCnt;		/* ������ */
	char    sCallType[3];		/* �������� */
	char    sSettDate[9];		/* ����ʱ�� */
	char    sGroupID[4];		/* ���з��� */
	char    sOtherGroupID[4];		/* ���з��� */
	int     iReportItemID;		/* ������ID */
	
	char	sCallingNbrType[3];	
	char	sCalledNbrType[3];
	char	sSettDirection[3];
	char	sSettCarrID[3];
	
	struct SettMTicketUeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettMTicketUeStruct{

	char    sCityID[8];		/* ���б��� */
	char    sCallingCityID[8];		/* ���г��д��� */
	char    sCallingType[4];		/* ���к������� */
	char    sCallingCompCode[2];		/* ������Ӫ�� */
	char    sCallingAreaCode[8];		/* ��������������� */
	char    sCallingNumber[30];		/* ����������к��� */
	char    sCalledCityID[8];		/* ���г��д��� */
	char    sCalledNumberType[4];		/* ���к������� */
	char    sCalledCompCode[2];		/* ������Ӫ�� */
	char    sCalledAreaCode[8];		/* ������ı������� */
	char    sCalledNumber[30];		/* ������ı��к��� */
	char    sDuration[18];		/* ʱ�� */
	char    sProdID[15];		/* �����Ʒ��ʶ */
	char    sStlDuration[18];		/* ת����Ľ���ʱ�� */
	char    sStlAmount[18];		/* ������� */
	char    sSettCnt[6];		/* ������ */
	char    sCallType[2];		/* �������� */
	char    sSettDate[8];		/* ����ʱ�� */
	char    sGroupID[3];		/* ���з��� */
	char    sOtherGroupID[3];		/* ���з��� */
	char    sReportItemID[9];		/* ������ID */
	
	char	sCallingNbrType[2];	
	char	sCalledNbrType[2];
	char	sSettDirection[2];
	char	sSettCarrID[2];
};

/*�������ݶ�̬��SETT_M_TICKET_UE���ýṹ���巽ʽȡ����*/
int EGetSettMTicketUeToStruct(struct SettMTicketUeStruct *p,
	struct SettMTicketUeStructIn *pSource);
void mvitem_settmticketue(struct SettMTicketUeStruct *pi,struct SettMTicketUeStruct *po);
void mvitem_fmsettmticketue(struct FSettMTicketUeStruct *pi,struct SettMTicketUeStruct *po);
void mvitem_mfsettmticketue(struct SettMTicketUeStruct *pi,struct FSettMTicketUeStruct *po);
/**�Ա�SETT_M_TICKET_UE�������ͷź���**/
void DestroySettMTicketUe(struct SettMTicketUeStruct *ptHead);
int InitSettMTicketUe(struct SettMTicketUeStruct **pptHead);
/*�������ݽṹ����д��SETT_M_TICKET_UE*/
int EInsertStructToSettMTicketUe(struct SettMTicketUeStruct *p,
	int iInsertFlag,struct SettMTicketUeStructOut *pTarget);

/**һ��ͳ�Ʋ���**/

/*����ͳ�Ʋ���*/

/*����ṹ��������*/
struct SettNbrStatUeStructOut{

#ifndef SETT_NBR_STAT_UE_BUFLEN_OUT
#define SETT_NBR_STAT_UE_BUFLEN_OUT		300
#endif

	struct SettNbrStatUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[128];
		/* �����·� */
	char    asSettDate[SETT_NBR_STAT_UE_BUFLEN_OUT][9];
		/* ������������� */
	char    asSettCity[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* ������� */
	char    asSettNumber[SETT_NBR_STAT_UE_BUFLEN_OUT][25];
		/* ������������� */
	char    asHomeAreaCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* �Է���������� */
	char    asOtherAreaCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* ����ͨ���� */
	char    asVisitAreaCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* ������Ӫ�̱��� */
	char    asHomeCompCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* �Է���Ӫ�̱��� */
	char    asOtherCompCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* ���з������ */
	char    asCallDirection[SETT_NBR_STAT_UE_BUFLEN_OUT][2];
		/* ���������� */
	char    asProdID[SETT_NBR_STAT_UE_BUFLEN_OUT][16];
		/* �������� */
	int     aiSettIncome[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* ����֧�� */
	int     aiSettExpenses[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* ����ʱ�� */
	int     aiSettDuration[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* ͨ������ */
	int     aiSettCnt[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* ҵ������ */
	char    asSvcType[SETT_NBR_STAT_UE_BUFLEN_OUT][4];
		/* �����û��������� */
	char    asHomeNetType[SETT_NBR_STAT_UE_BUFLEN_OUT][5];
		/* �Զ��û��������� */
	char    asOtherNetType[SETT_NBR_STAT_UE_BUFLEN_OUT][5];
		/* ������֧��ʶ */
	char    asSettFlag[SETT_NBR_STAT_UE_BUFLEN_OUT][2];
		/* ����1 */
	char    asReserve1[SETT_NBR_STAT_UE_BUFLEN_OUT][11];
		/* ����2 */
	char    asReserve2[SETT_NBR_STAT_UE_BUFLEN_OUT][11];
	
	char	asInComp[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
};


/* ����ṹ��������*/
struct SettNbrStatUeStructIn{

#ifndef SETT_NBR_STAT_UE_BUFLEN_IN
#define SETT_NBR_STAT_UE_BUFLEN_IN		300
#endif

	struct SettNbrStatUeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[128];
	char sCondition[1024];
		/* �����·� */
	char    asSettDate[SETT_NBR_STAT_UE_BUFLEN_IN][9];
		/* ������������� */
	char    asSettCity[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* ������� */
	char    asSettNumber[SETT_NBR_STAT_UE_BUFLEN_IN][25];
		/* ������������� */
	char    asHomeAreaCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* �Է���������� */
	char    asOtherAreaCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* ����ͨ���� */
	char    asVisitAreaCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* ������Ӫ�̱��� */
	char    asHomeCompCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* �Է���Ӫ�̱��� */
	char    asOtherCompCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* ���з������ */
	char    asCallDirection[SETT_NBR_STAT_UE_BUFLEN_IN][2];
		/* ���������� */
	char    asProdID[SETT_NBR_STAT_UE_BUFLEN_IN][16];
		/* �������� */
	int     aiSettIncome[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* ����֧�� */
	int     aiSettExpenses[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* ����ʱ�� */
	int     aiSettDuration[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* ͨ������ */
	int     aiSettCnt[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* ҵ������ */
	char    asSvcType[SETT_NBR_STAT_UE_BUFLEN_IN][4];
		/* �����û��������� */
	char    asHomeNetType[SETT_NBR_STAT_UE_BUFLEN_IN][5];
		/* �Զ��û��������� */
	char    asOtherNetType[SETT_NBR_STAT_UE_BUFLEN_IN][5];
		/* ������֧��ʶ */
	char    asSettFlag[SETT_NBR_STAT_UE_BUFLEN_IN][2];
		/* ����1 */
	char    asReserve1[SETT_NBR_STAT_UE_BUFLEN_IN][11];
		/* ����2 */
	char    asReserve2[SETT_NBR_STAT_UE_BUFLEN_IN][11];
	
	char	asInComp[SETT_NBR_STAT_UE_BUFLEN_IN][6];
};


/*�����ṹ����*/
struct SettNbrStatUeStruct{

	struct SettNbrStatUeStruct *pNext;
	char    sSettDate[9];		/* �����·� */
	char    sSettCity[6];		/* ������������� */
	char    sSettNumber[25];		/* ������� */
	char    sHomeAreaCode[6];		/* ������������� */
	char    sOtherAreaCode[6];		/* �Է���������� */
	char    sVisitAreaCode[6];		/* ����ͨ���� */
	char    sHomeCompCode[6];		/* ������Ӫ�̱��� */
	char    sOtherCompCode[6];		/* �Է���Ӫ�̱��� */
	char    sCallDirection[2];		/* ���з������ */
	char    sProdID[16];		/* ���������� */
	int     iSettIncome;		/* �������� */
	int     iSettExpenses;		/* ����֧�� */
	int     iSettDuration;		/* ����ʱ�� */
	int     iDuration;		/* ͨ��ʱ�� */
	int     iSettCnt;		/* ͨ������ */
	char    sSvcType[4];		/* ҵ������ */
	char    sHomeNetType[5];		/* �����û��������� */
	char    sOtherNetType[5];		/* �Զ��û��������� */
	char    sSettFlag[2];		/* ������֧��ʶ */
	char    sReserve1[11];		/* ����1 */
	char    sReserve2[11];		/* ����2 */
	
	char	sInComp[6];		/* ������Ϣ������ͳ��ʹ�� */
	
	struct SettNbrStatUeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettNbrStatUeStruct{

	char    sSettDate[8];		/* �����·� */
	char    sSettCity[5];		/* ������������� */
	char    sSettNumber[24];		/* ������� */
	char    sHomeAreaCode[5];		/* ������������� */
	char    sOtherAreaCode[5];		/* �Է���������� */
	char    sVisitAreaCode[5];		/* ����ͨ���� */
	char    sHomeCompCode[5];		/* ������Ӫ�̱��� */
	char    sOtherCompCode[5];		/* �Է���Ӫ�̱��� */
	char    sCallDirection[1];		/* ���з������ */
	char    sProdID[15];		/* ���������� */
	char    sSettIncome[9];		/* �������� */
	char    sSettExpenses[9];		/* ����֧�� */
	char    sSettDuration[9];		/* ����ʱ�� */
	char    sDuration[9];		/* ͨ��ʱ�� */
	char    sSettCnt[9];		/* ͨ������ */
	char    sSvcType[3];		/* ҵ������ */
	char    sHomeNetType[4];		/* �����û��������� */
	char    sOtherNetType[4];		/* �Զ��û��������� */
	char    sSettFlag[1];		/* ������֧��ʶ */
	char    sReserve1[10];		/* ����1 */
	char    sReserve2[10];		/* ����2 */
};


/*�������ݶ�̬��SETT_NBR_STAT_UE���ýṹ���巽ʽȡ����*/
int EGetSettNbrStatUeToStruct(struct SettNbrStatUeStruct *p,
	struct SettNbrStatUeStructIn *pSource);
void mvitem_settnbrstatue(struct SettNbrStatUeStruct *pi,struct SettNbrStatUeStruct *po);
void mvitem_fmsettnbrstatue(struct FSettNbrStatUeStruct *pi,struct SettNbrStatUeStruct *po);
void mvitem_mfsettnbrstatue(struct SettNbrStatUeStruct *pi,struct FSettNbrStatUeStruct *po);
/**�Ա�SETT_NBR_STAT_UE�������ͷź���**/
void DestroySettNbrStatUe(struct SettNbrStatUeStruct *ptHead);
int InitSettNbrStatUe(struct SettNbrStatUeStruct **pptHead);
/*�������ݽṹ����д��SETT_NBR_STAT_UE*/
int EInsertStructToSettNbrStatUe(struct SettNbrStatUeStruct *p,
	int iInsertFlag,struct SettNbrStatUeStructOut *pTarget);


/*����ͳ�Ʋ���*/

/*����ṹ��������*/
struct BiProductDescStructOut{

#ifndef BI_PRODUCT_DESC_BUFLEN_OUT
#define BI_PRODUCT_DESC_BUFLEN_OUT		300
#endif

	struct BiProductDescStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ʒ���� */
	char    asProdID[BI_PRODUCT_DESC_BUFLEN_OUT][16];
		/* ��Ʒ���� */
	char    asProdName[BI_PRODUCT_DESC_BUFLEN_OUT][129];
		/* ���㷽��0��֧����1�����룩 */
	char    asSettDirection[BI_PRODUCT_DESC_BUFLEN_OUT][5];
		/* �������T:���ţ�M���ƶ���U����ͨ�� */
	char    asSettCompany[BI_PRODUCT_DESC_BUFLEN_OUT][5];
};


/* ����ṹ��������*/
struct BiProductDescStructIn{

#ifndef BI_PRODUCT_DESC_BUFLEN_IN
#define BI_PRODUCT_DESC_BUFLEN_IN		300
#endif

	struct BiProductDescStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��Ʒ���� */
	char    asProdID[BI_PRODUCT_DESC_BUFLEN_IN][16];
		/* ��Ʒ���� */
	char    asProdName[BI_PRODUCT_DESC_BUFLEN_IN][129];
		/* ���㷽��0��֧����1�����룩 */
	char    asSettDirection[BI_PRODUCT_DESC_BUFLEN_IN][5];
		/* �������T:���ţ�M���ƶ���U����ͨ�� */
	char    asSettCompany[BI_PRODUCT_DESC_BUFLEN_IN][5];
};


/*�����ṹ����*/
struct BiProductDescStruct{

	struct BiProductDescStruct *pNext;
	char    sProdID[16];		/* ��Ʒ���� */
	char    sProdName[129];		/* ��Ʒ���� */
	char    sSettDirection[5];		/* ���㷽��0��֧����1�����룩 */
	char    sSettCompany[5];		/* �������T:���ţ�M���ƶ���U����ͨ�� */
	struct BiProductDescStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FBiProductDescStruct{

	char    sProdID[15];		/* ��Ʒ���� */
	char    sProdName[128];		/* ��Ʒ���� */
	char    sSettDirection[4];		/* ���㷽��0��֧����1�����룩 */
	char    sSettCompany[4];		/* �������T:���ţ�M���ƶ���U����ͨ�� */
};


/*�������ݶ�̬��BI_PRODUCT_DESC���ýṹ���巽ʽȡ����*/
int EGetBiProductDescToStruct(struct BiProductDescStruct *p,
	struct BiProductDescStructIn *pSource);
/**�Ա�BI_PRODUCT_DESC�������ͷź���**/
void DestroyBiProductDesc(struct BiProductDescStruct *ptHead);
int InitBiProductDesc(struct BiProductDescStruct **pptHead);

/*����ṹ��������*/
struct RptMidRelStructOut{

#ifndef RPT_MID_REL_BUFLEN_OUT
#define RPT_MID_REL_BUFLEN_OUT		300
#endif

	struct RptMidRelStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRptCode[RPT_MID_REL_BUFLEN_OUT][21];
	char    asIndexID[RPT_MID_REL_BUFLEN_OUT][21];
	int     aiIndexGroupID[RPT_MID_REL_BUFLEN_OUT];
	char    asIndexGroupName[RPT_MID_REL_BUFLEN_OUT][201];
};


/* ����ṹ��������*/
struct RptMidRelStructIn{

#ifndef RPT_MID_REL_BUFLEN_IN
#define RPT_MID_REL_BUFLEN_IN		300
#endif

	struct RptMidRelStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRptCode[RPT_MID_REL_BUFLEN_IN][21];
	char    asIndexID[RPT_MID_REL_BUFLEN_IN][21];
	int     aiIndexGroupID[RPT_MID_REL_BUFLEN_IN];
	char    asIndexGroupName[RPT_MID_REL_BUFLEN_IN][201];
};


/*�����ṹ����*/
struct RptMidRelStruct{

	struct RptMidRelStruct *pNext;
	char    sRptCode[21];
	char    sIndexID[21];
	int     iIndexGroupID;
	char    sIndexGroupName[201];
	
	char	sHomeCode[9];
	char	sOppCode[9];
	
	struct RptMidRelStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FRptMidRelStruct{

	char    sRptCode[20];
	char    sIndexID[20];
	char    sIndexGroupID[8];
	char    sIndexGroupName[200];
};


/*�������ݶ�̬��RPT_MID_REL���ýṹ���巽ʽȡ����*/
int EGetRptMidRelToStruct(struct RptMidRelStruct *p,
	struct RptMidRelStructIn *pSource);
int InitRptMidRel(struct RptMidRelStruct **pptHead);
/**�Ա�RPT_MID_REL�������ͷź���**/
void DestroyRptMidRel(struct RptMidRelStruct *ptHead);

/*����ṹ��������*/
struct SettInsertLogStructOut{

#ifndef SETT_INSERT_LOG_BUFLEN_OUT
#define SETT_INSERT_LOG_BUFLEN_OUT		300
#endif

	struct SettInsertLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asFileName[SETT_INSERT_LOG_BUFLEN_OUT][129];
	char    asTableName[SETT_INSERT_LOG_BUFLEN_OUT][31];
	char    asDataDate[SETT_INSERT_LOG_BUFLEN_OUT][9];
	int	aiInsertCnt[SETT_INSERT_LOG_BUFLEN_OUT];
	char    asState[SETT_INSERT_LOG_BUFLEN_OUT][3];
};


/* ����ṹ��������*/
struct SettInsertLogStructIn{

#ifndef SETT_INSERT_LOG_BUFLEN_IN
#define SETT_INSERT_LOG_BUFLEN_IN		300
#endif

	struct SettInsertLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asFileName[SETT_INSERT_LOG_BUFLEN_IN][129];
	char    asTableName[SETT_INSERT_LOG_BUFLEN_IN][31];
	char    asDataDate[SETT_INSERT_LOG_BUFLEN_IN][9];
	int	aiInsertCnt[SETT_INSERT_LOG_BUFLEN_IN];
	char    asState[SETT_INSERT_LOG_BUFLEN_IN][3];
};


/*�����ṹ����*/
struct SettInsertLogStruct{

	struct SettInsertLogStruct *pNext;
	char    sFileName[129];
	char    sTableName[31];
	char    sDataDate[9];
	int	iInsertCnt;
	char	sState[3];
	struct SettInsertLogStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettInsertLogStruct{

	char    sFileName[128];
	char	sTableName[30];
	char    sDataDate[8];
	char	sInsertCnt[8];
};


/*�������ݶ�̬��SETT_INSERT_LOG���ýṹ���巽ʽȡ����*/
int EGetSettInsertLogToStruct(struct SettInsertLogStruct *p,
	struct SettInsertLogStructIn *pSource);
/**�Ա�SETT_INSERT_LOG�������ͷź���**/
void DestroySettInsertLog(struct SettInsertLogStruct *ptHead);
/*�������ݽṹ����д��SETT_INSERT_LOG*/
int EInsertStructToSettInsertLog(struct SettInsertLogStruct *p,
	int iInsertFlag,struct SettInsertLogStructOut *pTarget);

/*����ṹ��������*/
struct SubsTrunkStructOut{

#ifndef SUBS_TRUNK_BUFLEN_OUT
#define SUBS_TRUNK_BUFLEN_OUT		300
#endif

	struct SubsTrunkStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asTrunkNumber[SUBS_TRUNK_BUFLEN_OUT][13];
	char    asCityID[SUBS_TRUNK_BUFLEN_OUT][5];
	char    asProvinceID[SUBS_TRUNK_BUFLEN_OUT][5];
	char    asTrunkDesc[SUBS_TRUNK_BUFLEN_OUT][41];
	char    asTrunkAttribute[SUBS_TRUNK_BUFLEN_OUT][5];
	char    asSubType[SUBS_TRUNK_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
struct SubsTrunkStructIn{

#ifndef SUBS_TRUNK_BUFLEN_IN
#define SUBS_TRUNK_BUFLEN_IN		300
#endif

	struct SubsTrunkStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asTrunkNumber[SUBS_TRUNK_BUFLEN_IN][13];
	char    asCityID[SUBS_TRUNK_BUFLEN_IN][5];
	char    asProvinceID[SUBS_TRUNK_BUFLEN_IN][5];
	char    asTrunkDesc[SUBS_TRUNK_BUFLEN_IN][41];
	char    asTrunkAttribute[SUBS_TRUNK_BUFLEN_IN][5];
	char    asSubType[SUBS_TRUNK_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct SubsTrunkStruct{

	struct SubsTrunkStruct *pNext;
	char    sTrunkNumber[13];
	char    sCityID[5];
	char    sProvinceID[5];
	char    sTrunkDesc[41];
	char    sTrunkAttribute[5];
	char    sSubType[2];
	struct SubsTrunkStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSubsTrunkStruct{

	char    sTrunkNumber[12];
	char    sCityID[4];
	char    sProvinceID[4];
	char    sTrunkDesc[40];
	char    sTrunkAttribute[4];
	char    sSubType[1];
};


/*�������ݶ�̬��SUBS_TRUNK���ýṹ���巽ʽȡ����*/
int EGetSubsTrunkToStruct(struct SubsTrunkStruct *p,
	struct SubsTrunkStructIn *pSource);
/**�Ա�SUBS_TRUNK�������ͷź���**/
void DestroySubsTrunk(struct SubsTrunkStruct *ptHead);
int InitSubsTrunk(struct SubsTrunkStruct **pptHead);





#endif