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

/*---------基本部分代码 t_template_yd_gw_ue.txt----------*/

/*输出结构缓冲申明*/
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


/* 输入结构缓冲申明*/
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


/*单个结构申明*/
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
/*20140117新增*/
	char	sGroupID[3];
	struct TTemplateYdGwUeStruct *pLoadNext;
};


/*单个文件结构申明*/
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

/*批量数据动态从T_TEMPLATE_YD_GW_UE中用结构缓冲方式取数据*/
int EGetTTemplateYdGwUeToStruct(struct TTemplateYdGwUeStruct *p,
	struct TTemplateYdGwUeStructIn *pSource);

void mvitem_ttemplateydgwue(struct TTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po);

void mvitem_fmttemplateydgwue(struct FTTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po);

void mvitem_mfttemplateydgwue(struct TTemplateYdGwUeStruct *pi,struct FTTemplateYdGwUeStruct *po);

/**对表T_TEMPLATE_YD_GW_UE的链表释放函数**/
void DestroyTTemplateYdGwUe(struct TTemplateYdGwUeStruct *ptHead);

int InitTTemplateYdGwUe(struct TTemplateYdGwUeStruct **pptHead);

/*批量数据结构缓冲写入T_TEMPLATE_YD_GW_UE*/
int EInsertStructToTTemplateYdGwUe(struct TTemplateYdGwUeStruct *p,
	int iInsertFlag,struct TTemplateYdGwUeStructOut *pTarget);
/********************************20140910接口改造*************************************/

/*输出结构缓冲申明*/
struct SettTicketUeStructOut{

#ifndef SETT_TICKET_UE_BUFLEN_OUT
#define SETT_TICKET_UE_BUFLEN_OUT		300
#endif

	struct SettTicketUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[128];
		/* 使用事件流水标识 */
	char    asUsageEventID[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* 城市编码 */
	char    asCityID[SETT_TICKET_UE_BUFLEN_OUT][7];
		/* 话单类型 */
	char    asCdrType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 主叫城市代码 */
	char    asCallingCityID[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* 主叫异常类型 */
	char    asCallingException[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 主叫号码类型 */
	char    asCallingType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 主叫运营商 */
	char    asCallingCompCode[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* 规整后的主叫区号 */
	char    asCallingAreaCode[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* 规整后的主叫号码 */
	char    asCallingNumber[SETT_TICKET_UE_BUFLEN_OUT][31];
		/* 被叫城市代码 */
	char    asCalledCityID[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* 被叫异常类型 */
	char    asCalledException[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 被叫号码类型 */
	char    asCalledNumberType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 被叫运营商 */
	char    asCalledCompCode[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* 规整后的被叫区号 */
	char    asCalledAreaCode[SETT_TICKET_UE_BUFLEN_OUT][9];
		/* 规整后的被叫号码 */
	char    asCalledNumber[SETT_TICKET_UE_BUFLEN_OUT][31];
		/* 开始时间 */
	char    asStartTime[SETT_TICKET_UE_BUFLEN_OUT][17];
		/* 开始时间 */
	char    asEndTime[SETT_TICKET_UE_BUFLEN_OUT][17];
		/* 时长 */
	char    asDuration[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* 入中继号码 */
	char    asInTrunkNumber[SETT_TICKET_UE_BUFLEN_OUT][12];
		/* 入中继运营商 */
	char    asInCompanyCode[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 入中继网别 */
	char    asInTrunkNetType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 出中继号码 */
	char    asOutTrunkNumber[SETT_TICKET_UE_BUFLEN_OUT][12];
		/* 出中继运营商 */
	char    asOutCompanyCode[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 出中继网别 */
	char    asOutTrunkNetType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 是否免费 */
	char    asIsFree[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 主叫地址属性 */
	char    asCallingLocation[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 第二主叫地址属性 */
	char    asSecondCallingLocation[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 原始主叫号码 */
	char    asOrigCallingNumber[SETT_TICKET_UE_BUFLEN_OUT][37];
		/* 原始被叫号码 */
	char    asOrigCalledNumber[SETT_TICKET_UE_BUFLEN_OUT][37];
		/* 原始第二主叫号码 */
	char    asOrigSecondCallingNumber[SETT_TICKET_UE_BUFLEN_OUT][37];
		/* 错误类型 */
	char    asExceptionType[SETT_TICKET_UE_BUFLEN_OUT][11];
		/* 呼叫前转类型 */
	char    asPreCallType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 转接类型 */
	char    asTurnType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 结算产品标识 */
	char    asProdID[SETT_TICKET_UE_BUFLEN_OUT][16];
		/* 计价单位类型 */
	char    asRateUnitType[SETT_TICKET_UE_BUFLEN_OUT][5];
		/* 转换后的结算时长 */
	char    asStlDuration[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* 费率标识 */
	char    asRateID[SETT_TICKET_UE_BUFLEN_OUT][11];
		/* 结算费用 */
	char    asStlAmount[SETT_TICKET_UE_BUFLEN_OUT][19];
		/* 入中继子类型   取值（0-固网 ，1-移动网） */
	char	asInTrunkSubType[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* 出中继子类型   取值（0-固网 ，1-移动网） */
	char	asOutTrunkSubType[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* 用户分组(按用户号码末两位分组，非数字的就用00代替) */
	char    asGroupID[SETT_TICKET_UE_BUFLEN_OUT][3];
		/* 当前话单所在文件名 */
	char    asFileName[SETT_TICKET_UE_BUFLEN_OUT][65];
		/*呼叫类型*/
	char	asCallType[SETT_TICKET_UE_BUFLEN_OUT][3];
	char	asUsageSeq[SETT_TICKET_UE_BUFLEN_OUT][19];
	
};


/* 输入结构缓冲申明*/
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
		/* 使用事件流水标识 */
	char    asUsageEventID[SETT_TICKET_UE_BUFLEN_IN][19];
		/* 城市编码 */
	char    asCityID[SETT_TICKET_UE_BUFLEN_IN][7];
		/* 话单类型 */
	char    asCdrType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 主叫城市代码 */
	char    asCallingCityID[SETT_TICKET_UE_BUFLEN_IN][9];
		/* 主叫异常类型 */
	char    asCallingException[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 主叫号码类型 */
	char    asCallingType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 主叫运营商 */
	char    asCallingCompCode[SETT_TICKET_UE_BUFLEN_IN][3];
		/* 规整后的主叫区号 */
	char    asCallingAreaCode[SETT_TICKET_UE_BUFLEN_IN][9];
		/* 规整后的主叫号码 */
	char    asCallingNumber[SETT_TICKET_UE_BUFLEN_IN][31];
		/* 被叫城市代码 */
	char    asCalledCityID[SETT_TICKET_UE_BUFLEN_IN][9];
		/* 被叫异常类型 */
	char    asCalledException[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 被叫号码类型 */
	char    asCalledNumberType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 被叫运营商 */
	char    asCalledCompCode[SETT_TICKET_UE_BUFLEN_IN][3];
		/* 规整后的被叫区号 */
	char    asCalledAreaCode[SETT_TICKET_UE_BUFLEN_IN][9];
		/* 规整后的被叫号码 */
	char    asCalledNumber[SETT_TICKET_UE_BUFLEN_IN][31];
		/* 开始时间 */
	char    asStartTime[SETT_TICKET_UE_BUFLEN_IN][17];
		/* 开始时间 */
	char    asEndTime[SETT_TICKET_UE_BUFLEN_IN][17];
		/* 时长 */
	char    asDuration[SETT_TICKET_UE_BUFLEN_IN][19];
		/* 入中继号码 */
	char    asInTrunkNumber[SETT_TICKET_UE_BUFLEN_IN][12];
		/* 入中继运营商 */
	char    asInCompanyCode[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 入中继网别 */
	char    asInTrunkNetType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 出中继号码 */
	char    asOutTrunkNumber[SETT_TICKET_UE_BUFLEN_IN][12];
		/* 出中继运营商 */
	char    asOutCompanyCode[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 出中继网别 */
	char    asOutTrunkNetType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 是否免费 */
	char    asIsFree[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 主叫地址属性 */
	char    asCallingLocation[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 第二主叫地址属性 */
	char    asSecondCallingLocation[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 原始主叫号码 */
	char    asOrigCallingNumber[SETT_TICKET_UE_BUFLEN_IN][37];
		/* 原始被叫号码 */
	char    asOrigCalledNumber[SETT_TICKET_UE_BUFLEN_IN][37];
		/* 原始第二主叫号码 */
	char    asOrigSecondCallingNumber[SETT_TICKET_UE_BUFLEN_IN][37];
		/* 错误类型 */
	char    asExceptionType[SETT_TICKET_UE_BUFLEN_IN][11];
		/* 呼叫前转类型 */
	char    asPreCallType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 转接类型 */
	char    asTurnType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 结算产品标识 */
	char    asProdID[SETT_TICKET_UE_BUFLEN_IN][16];
		/* 计价单位类型 */
	char    asRateUnitType[SETT_TICKET_UE_BUFLEN_IN][5];
		/* 转换后的结算时长 */
	char    asStlDuration[SETT_TICKET_UE_BUFLEN_IN][19];
		/* 费率标识 */
	char    asRateID[SETT_TICKET_UE_BUFLEN_IN][11];
		/* 结算费用 */
	char    asStlAmount[SETT_TICKET_UE_BUFLEN_IN][19];
		/* 入中继子类型   取值（0-固网 ，1-移动网） */
	char	asInTrunkSubType[SETT_TICKET_UE_BUFLEN_IN][3];
		/* 出中继子类型   取值（0-固网 ，1-移动网） */
	char	asOutTrunkSubType[SETT_TICKET_UE_BUFLEN_IN][3];
		/* 用户分组(按用户号码末两位分组，非数字的就用00代替) */
	char    asGroupID[SETT_TICKET_UE_BUFLEN_IN][3];
		/* 当前话单所在文件名 */
	char    asFileName[SETT_TICKET_UE_BUFLEN_IN][65];
		/*呼叫类型*/
	char	asCallType[SETT_TICKET_UE_BUFLEN_IN][3];
	char	asUsageSeq[SETT_TICKET_UE_BUFLEN_IN][19];
};


/*单个结构申明*/
struct SettTicketUeStruct{

	struct SettTicketUeStruct *pNext;
	char    sUsageEventID[19];		/* 使用事件流水标识 */
	char    sCityID[7];		/* 城市编码 */
	char    sCdrType[5];		/* 话单类型 */
	char    sCallingCityID[9];		/* 主叫城市代码 */
	char    sCallingException[5];		/* 主叫异常类型 */
	char    sCallingType[5];		/* 主叫号码类型 */
	char    sCallingCompCode[3];		/* 主叫运营商 */
	char    sCallingAreaCode[9];		/* 规整后的主叫区号 */
	char    sCallingNumber[31];		/* 规整后的主叫号码 */
	char    sCalledCityID[9];		/* 被叫城市代码 */
	char    sCalledException[5];		/* 被叫异常类型 */
	char    sCalledNumberType[5];		/* 被叫号码类型 */
	char    sCalledCompCode[3];		/* 被叫运营商 */
	char    sCalledAreaCode[9];		/* 规整后的被叫区号 */
	char    sCalledNumber[31];		/* 规整后的被叫号码 */
	char    sStartTime[17];		/* 开始时间 */
	char    sEndTime[17];		/* 开始时间 */
	char    sDuration[19];		/* 时长 */
	char    sInTrunkNumber[12];		/* 入中继号码 */
	char    sInCompanyCode[5];		/* 入中继运营商 */
	char    sInTrunkNetType[5];		/* 入中继网别 */
	char    sOutTrunkNumber[12];		/* 出中继号码 */
	char    sOutCompanyCode[5];		/* 出中继运营商 */
	char    sOutTrunkNetType[5];		/* 出中继网别 */
	char    sIsFree[5];		/* 是否免费 */
	char    sCallingLocation[5];		/* 主叫地址属性 */
	char    sSecondCallingLocation[5];		/* 第二主叫地址属性 */
	char    sOrigCallingNumber[37];		/* 原始主叫号码 */
	char    sOrigCalledNumber[37];		/* 原始被叫号码 */
	char    sOrigSecondCallingNumber[37];		/* 原始第二主叫号码 */
	char    sExceptionType[11];		/* 错误类型 */
	char    sPreCallType[5];		/* 呼叫前转类型 */
	char    sTurnType[5];		/* 转接类型 */
	char    sProdID[16];		/* 结算产品标识 */
	char    sRateUnitType[5];		/* 计价单位类型 */
	char    sStlDuration[19];		/* 转换后的结算时长 */
	char    sRateID[11];		/* 费率标识 */
	char    sStlAmount[19];		/* 结算费用 */
	char	sInTrunkSubType[3];	/* 入中继子类型   取值（0-固网 ，1-移动网） */
	char	sOutTrunkSubType[3];	/* 出中继子类型   取值（0-固网 ，1-移动网） */
	char    sGroupID[3];		/* 用户分组(按用户号码末两位分组，非数字的就用00代替) */
	char    sFileName[65];		/* 当前话单所在文件名 */
	char	sCallType[3];		/* 呼叫类型 */
	char	sUsageSeq[19];
	struct SettTicketUeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettTicketUeStruct{

	char    sUsageEventID[18];		/* 使用事件流水标识 */
	char    sCityID[6];		/* 城市编码 */
	char    sCdrType[4];		/* 话单类型 */
	char    sCallingCityID[8];		/* 主叫城市代码 */
	char    sCallingException[4];		/* 主叫异常类型 */
	char    sCallingType[4];		/* 主叫号码类型 */
	char    sCallingCompCode[2];		/* 主叫运营商 */
	char    sCallingAreaCode[8];		/* 规整后的主叫区号 */
	char    sCallingNumber[30];		/* 规整后的主叫号码 */
	char    sCalledCityID[8];		/* 被叫城市代码 */
	char    sCalledException[4];		/* 被叫异常类型 */
	char    sCalledNumberType[4];		/* 被叫号码类型 */
	char    sCalledCompCode[2];		/* 被叫运营商 */
	char    sCalledAreaCode[8];		/* 规整后的被叫区号 */
	char    sCalledNumber[30];		/* 规整后的被叫号码 */
	char    sStartTime[16];		/* 开始时间 */
	char    sEndTime[16];		/* 开始时间 */
	char    sDuration[18];		/* 时长 */
	char    sInTrunkNumber[11];		/* 入中继号码 */
	char    sInCompanyCode[4];		/* 入中继运营商 */
	char    sInTrunkNetType[4];		/* 入中继网别 */
	char    sOutTrunkNumber[11];		/* 出中继号码 */
	char    sOutCompanyCode[4];		/* 出中继运营商 */
	char    sOutTrunkNetType[4];		/* 出中继网别 */
	char    sIsFree[4];		/* 是 否免费 */
	char    sCallingLocation[4];		/* 主叫地址属性 */
	char    sSecondCallingLocation[4];		/* 第二主叫地址属性 */
	char    sOrigCallingNumber[36];		/* 原始主叫号码 */
	char    sOrigCalledNumber[36];		/* 原始被叫号码 */
	char    sOrigSecondCallingNumber[36];		/* 原始第二主叫号码 */
	char    sExceptionType[10];		/* 错误类型 */
	char    sPreCallType[4];		/* 呼叫前转类型 */
	char    sTurnType[4];		/* 转接类型 */
	char    sProdID[15];		/* 结算产品标识 */
	char    sRateUnitType[4];		/* 计价单位类型 */
	char    sStlDuration[18];		/* 转换后的结算时长 */
	char    sRateID[10];		/* 费率标识 */
	char    sStlAmount[18];		/* 结算费用 */
	char	sInTrunkSubType[2];	/* 入中继子类型   取值（0-固网 ，1-移动网） */
	char	sOutTrunkSubType[2];	/* 出中继子类型   取值（0-固网 ，1-移动网） */
};


/*批量数据动态从SETT_TICKET_UE中用结构缓冲方式取数据*/
int EGetSettTicketUeToStruct(struct SettTicketUeStruct *p,
	struct SettTicketUeStructIn *pSource);
void mvitem_settticketue(struct SettTicketUeStruct *pi,struct SettTicketUeStruct *po);
void mvitem_fmsettticketue(struct FSettTicketUeStruct *pi,struct SettTicketUeStruct *po);
void mvitem_mfsettticketue(struct SettTicketUeStruct *pi,struct FSettTicketUeStruct *po);
/**对表SETT_TICKET_UE的链表释放函数**/
void DestroySettTicketUe(struct SettTicketUeStruct *ptHead);
int InitSettTicketUe(struct SettTicketUeStruct **pptHead);
/*批量数据结构缓冲写入SETT_TICKET_UE*/
int EInsertStructToSettTicketUe(struct SettTicketUeStruct *p,
	int iInsertFlag,struct SettTicketUeStructOut *pTarget);


/*输出结构缓冲申明*/
struct SettTicketSmStructOut{

#ifndef SETT_TICKET_SM_BUFLEN_OUT
#define SETT_TICKET_SM_BUFLEN_OUT		300
#endif

	struct SettTicketSmStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[256];
		/* 结算产品标识 */
	char    asProdID[SETT_TICKET_SM_BUFLEN_OUT][31];
		/* 开始时间 */
	char    asStartTime[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* 结束时间 */
	char    asEndTime[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* 主叫号码 */
	char    asCallingNumber[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* 主叫城市代码 */
	char    asCallingCityID[SETT_TICKET_SM_BUFLEN_OUT][9];
		/* 主叫运营商 */
	char    asCallingCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* 主叫号码类型 */
	char    asCallingNumberType[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* 被叫号码 */
	char    asCalledNumber[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* 被叫城市代码 */
	char    asCalledCityID[SETT_TICKET_SM_BUFLEN_OUT][9];
		/* 被叫运营商 */
	char    asCalledCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* 被叫号码类型 */
	char    asCalledNumberType[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* 结算归属地市编码 */
	int     aiCityID[SETT_TICKET_SM_BUFLEN_OUT];
		/* 是否免费 */
	char    asIsFree[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* 结算账期 */
	int     aiBillCycleSeq[SETT_TICKET_SM_BUFLEN_OUT];
		/* 错误类型 */
	char    asExceptionType[SETT_TICKET_SM_BUFLEN_OUT][9];
		/* 结算金额 */
	char    asStlAmount[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* 主叫区号 */
	char    asCallingAreaCode[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* 被叫区号 */
	char    asCalledAreaCode[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* 结算方向 */
	char    asStlDirection[SETT_TICKET_SM_BUFLEN_OUT][5];
		/* 上行网元 */
	char    asUpGw[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* 下行网元 */
	char    asDownGw[SETT_TICKET_SM_BUFLEN_OUT][33];
		/* 上行网元运营商 */
	char    asUpCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* 下行网元运营商 */
	char    asDownCompanyID[SETT_TICKET_SM_BUFLEN_OUT][3];
		/* 使用事件流水标识 */
	char    asUsageEventID[SETT_TICKET_SM_BUFLEN_OUT][19];
		/* 文件名 */
	char    asFileName[SETT_TICKET_SM_BUFLEN_OUT][65];
		/* 分组编码 */
	char    asGroupID[SETT_TICKET_SM_BUFLEN_OUT][4];
		/* 呼叫类型 */
	char	asCallType[SETT_TICKET_SM_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
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
		/* 结算产品标识 */
	char    asProdID[SETT_TICKET_SM_BUFLEN_IN][31];
		/* 开始时间 */
	char    asStartTime[SETT_TICKET_SM_BUFLEN_IN][19];
		/* 结束时间 */
	char    asEndTime[SETT_TICKET_SM_BUFLEN_IN][19];
		/* 主叫号码 */
	char    asCallingNumber[SETT_TICKET_SM_BUFLEN_IN][33];
		/* 主叫城市代码 */
	char    asCallingCityID[SETT_TICKET_SM_BUFLEN_IN][9];
		/* 主叫运营商 */
	char    asCallingCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* 主叫号码类型 */
	char    asCallingNumberType[SETT_TICKET_SM_BUFLEN_IN][5];
		/* 被叫号码 */
	char    asCalledNumber[SETT_TICKET_SM_BUFLEN_IN][33];
		/* 被叫城市代码 */
	char    asCalledCityID[SETT_TICKET_SM_BUFLEN_IN][9];
		/* 被叫运营商 */
	char    asCalledCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* 被叫号码类型 */
	char    asCalledNumberType[SETT_TICKET_SM_BUFLEN_IN][5];
		/* 结算归属地市编码 */
	int     aiCityID[SETT_TICKET_SM_BUFLEN_IN];
		/* 是否免费 */
	char    asIsFree[SETT_TICKET_SM_BUFLEN_IN][5];
		/* 结算账期 */
	int     aiBillCycleSeq[SETT_TICKET_SM_BUFLEN_IN];
		/* 错误类型 */
	char    asExceptionType[SETT_TICKET_SM_BUFLEN_IN][9];
		/* 结算金额 */
	char    asStlAmount[SETT_TICKET_SM_BUFLEN_IN][19];
		/* 主叫区号 */
	char    asCallingAreaCode[SETT_TICKET_SM_BUFLEN_IN][33];
		/* 被叫区号 */
	char    asCalledAreaCode[SETT_TICKET_SM_BUFLEN_IN][33];
		/* 结算方向 */
	char    asStlDirection[SETT_TICKET_SM_BUFLEN_IN][5];
		/* 上行网元 */
	char    asUpGw[SETT_TICKET_SM_BUFLEN_IN][33];
		/* 下行网元 */
	char    asDownGw[SETT_TICKET_SM_BUFLEN_IN][33];
		/* 上行网元运营商 */
	char    asUpCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* 下行网元运营商 */
	char    asDownCompanyID[SETT_TICKET_SM_BUFLEN_IN][3];
		/* 使用事件流水标识 */
	char    asUsageEventID[SETT_TICKET_SM_BUFLEN_IN][19];
		/* 文件名 */
	char    asFileName[SETT_TICKET_SM_BUFLEN_IN][65];
		/* 分组编码 */
	char    asGroupID[SETT_TICKET_SM_BUFLEN_IN][4];
		/* 呼叫类型 */
	char	asCallType[SETT_TICKET_SM_BUFLEN_IN][3];
};


/*单个结构申明*/
struct SettTicketSmStruct{

	struct SettTicketSmStruct *pNext;
	char    sProdID[31];		/* 结算产品标识 */
	char    sStartTime[19];		/* 开始时间 */
	char    sEndTime[19];		/* 结束时间 */
	char    sCallingNumber[33];		/* 主叫号码 */
	char    sCallingCityID[9];		/* 主叫城市代码 */
	char    sCallingCompanyID[3];		/* 主叫运营商 */
	char    sCallingNumberType[5];		/* 主叫号码类型 */
	char    sCalledNumber[33];		/* 被叫号码 */
	char    sCalledCityID[9];		/* 被叫城市代码 */
	char    sCalledCompanyID[3];		/* 被叫运营商 */
	char    sCalledNumberType[5];		/* 被叫号码类型 */
	int     iCityID;		/* 结算归属地市编码 */
	char    sIsFree[5];		/* 是否免费 */
	int     iBillCycleSeq;		/* 结算账期 */
	char    sExceptionType[9];		/* 错误类型 */
	char    sStlAmount[19];		/* 结算金额 */
	char    sCallingAreaCode[33];		/* 主叫区号 */
	char    sCalledAreaCode[33];		/* 被叫区号 */
	char    sStlDirection[5];		/* 结算方向 */
	char    sUpGw[33];		/* 上行网元 */
	char    sDownGw[33];		/* 下行网元 */
	char    sUpCompanyID[3];		/* 上行网元运营商 */
	char    sDownCompanyID[3];		/* 下行网元运营商 */
	char    sUsageEventID[19];		/* 使用事件流水标识 */
	char    sFileName[65];		/* 文件名 */
	char    sGroupID[4];		/* 分组编码 */
	char	sCallType[3];		/* 呼叫类型 */
	struct SettTicketSmStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettTicketSmStruct{

	char    sProdID[30];		/* 结算产品标识 */
	char    sStartTime[18];		/* 开始时间 */
	char    sEndTime[18];		/* 结束时间 */
	char    sCallingNumber[32];		/* 主叫号码 */
	char    sCallingCityID[8];		/* 主叫城市代码 */
	char    sCallingCompanyID[2];		/* 主叫运营商 */
	char    sCallingNumberType[4];		/* 主叫号码类型 */
	char    sCalledNumber[32];		/* 被叫号码 */
	char    sCalledCityID[8];		/* 被叫城市代码 */
	char    sCalledCompanyID[2];		/* 被叫运营商 */
	char    sCalledNumberType[4];		/* 被叫号码类型 */
	char    sCityID[8];		/* 结算归属地市编码 */
	char    sIsFree[4];		/* 是否免费 */
	char    sBillCycleSeq[6];		/* 结算账期 */
	char    sExceptionType[8];		/* 错误类型 */
	char    sStlAmount[18];		/* 结算金额 */
	char    sCallingAreaCode[32];		/* 主叫区号 */
	char    sCalledAreaCode[32];		/* 被叫区号 */
	char    sStlDirection[4];		/* 结算方向 */
	char    sUpGw[32];		/* 上行网元 */
	char    sDownGw[32];		/* 下行网元 */
	char    sUpCompanyID[2];		/* 上行网元运营商 */
	char    sDownCompanyID[2];		/* 下行网元运营商 */
	char    sUsageEventID[18];		/* 使用事件流水标识 */
};


/*批量数据动态从SETT_TICKET_SM中用结构缓冲方式取数据*/
int EGetSettTicketSmToStruct(struct SettTicketSmStruct *p,
	struct SettTicketSmStructIn *pSource);
void mvitem_settticketsm(struct SettTicketSmStruct *pi,struct SettTicketSmStruct *po);
void mvitem_fmsettticketsm(struct FSettTicketSmStruct *pi,struct SettTicketSmStruct *po);
void mvitem_mfsettticketsm(struct SettTicketSmStruct *pi,struct FSettTicketSmStruct *po);
/**对表SETT_TICKET_SM的链表释放函数**/
void DestroySettTicketSm(struct SettTicketSmStruct *ptHead);
int InitSettTicketSm(struct SettTicketSmStruct **pptHead);
/*批量数据结构缓冲写入SETT_TICKET_SM*/
int EInsertStructToSettTicketSm(struct SettTicketSmStruct *p,
	int iInsertFlag,struct SettTicketSmStructOut *pTarget);



/*输出结构缓冲申明*/
struct SettTicketMmsStructOut{

#ifndef SETT_TICKET_MMS_BUFLEN_OUT
#define SETT_TICKET_MMS_BUFLEN_OUT		300
#endif

	struct SettTicketMmsStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[256];
		/* 结算产品标识 */
	char    asProdID[SETT_TICKET_MMS_BUFLEN_OUT][31];
		/* 开始时间 */
	char    asStartTime[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* 结束时间 */
	char    asEndTime[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* 主叫号码 */
	char    asCallingNumber[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 被叫号码 */
	char    asCalledNumber[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 业务类别 */
	char    asOperationTypeID[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* 结算归属地市编码 */
	int     aiCityID[SETT_TICKET_MMS_BUFLEN_OUT];
		/* 是否免费 */
	char    asIsFree[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* 计价单位类型 */
	char    asRateUnitType[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* 计价单位数 */
	char    asRateUnits[SETT_TICKET_MMS_BUFLEN_OUT][13];
		/* 结算账期 */
	int     aiBillCycleSeq[SETT_TICKET_MMS_BUFLEN_OUT];
		/* 错误类型 */
	char    asExceptionType[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* 省份编码 */
	char    asProvinceID[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* 主叫分组ID */
	char    asCallingGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 被叫分组ID */
	char    asCalledGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 主叫归属运营商 */
	char    asCallingCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* 被叫归属运营商 */
	char    asCalledCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* 结算对象 */
	char    asStlObject[SETT_TICKET_MMS_BUFLEN_OUT][9];
		/* 结算金额（单位：毫厘） */
	char    asStlAmount[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* 主叫区号 */
	char    asCallingAreaCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 被叫区号 */
	char    asCalledAreaCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 结算方向 */
	char    asStlDirection[SETT_TICKET_MMS_BUFLEN_OUT][5];
		/* 上行网元 */
	char    asUpGw[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 下行网元 */
	char    asDownGw[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 上行网元分组 */
	char    asUpgwGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 下行网元分组 */
	char    asDownGwGroupID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 上行网元运营商 */
	char    asUpCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 下行网元运营商 */
	char    asDownCompanyID[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 使用事件流水标识 */
	char    asUsageEventID[SETT_TICKET_MMS_BUFLEN_OUT][19];
		/* 主叫地市代码 */
	char    asCallingCityCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 被叫地市代码 */
	char    asCalledCityCode[SETT_TICKET_MMS_BUFLEN_OUT][33];
		/* 文件名 */
	char    asFileName[SETT_TICKET_MMS_BUFLEN_OUT][65];
		/* 分组ID */
	char    asGroupID[SETT_TICKET_MMS_BUFLEN_OUT][3];
		/* 主被叫 */
	char    asCallType[SETT_TICKET_MMS_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
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
		/* 结算产品标识 */
	char    asProdID[SETT_TICKET_MMS_BUFLEN_IN][31];
		/* 开始时间 */
	char    asStartTime[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* 结束时间 */
	char    asEndTime[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* 主叫号码 */
	char    asCallingNumber[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 被叫号码 */
	char    asCalledNumber[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 业务类别 */
	char    asOperationTypeID[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* 结算归属地市编码 */
	int     aiCityID[SETT_TICKET_MMS_BUFLEN_IN];
		/* 是否免费 */
	char    asIsFree[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* 计价单位类型 */
	char    asRateUnitType[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* 计价单位数 */
	char    asRateUnits[SETT_TICKET_MMS_BUFLEN_IN][13];
		/* 结算账期 */
	int     aiBillCycleSeq[SETT_TICKET_MMS_BUFLEN_IN];
		/* 错误类型 */
	char    asExceptionType[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* 省份编码 */
	char    asProvinceID[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* 主叫分组ID */
	char    asCallingGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 被叫分组ID */
	char    asCalledGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 主叫归属运营商 */
	char    asCallingCompanyID[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* 被叫归属运营商 */
	char    asCalledCompanyID[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* 结算对象 */
	char    asStlObject[SETT_TICKET_MMS_BUFLEN_IN][9];
		/* 结算金额（单位：毫厘） */
	char    asStlAmount[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* 主叫区号 */
	char    asCallingAreaCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 被叫区号 */
	char    asCalledAreaCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 结算方向 */
	char    asStlDirection[SETT_TICKET_MMS_BUFLEN_IN][5];
		/* 上行网元 */
	char    asUpGw[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 下行网元 */
	char    asDownGw[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 上行网元分组 */
	char    asUpgwGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 下行网元分组 */
	char    asDownGwGroupID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 上行网元运营商 */
	char    asUpCompanyID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 下行网元运营商 */
	char    asDownCompanyID[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 使用事件流水标识 */
	char    asUsageEventID[SETT_TICKET_MMS_BUFLEN_IN][19];
		/* 主叫地市代码 */
	char    asCallingCityCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 被叫地市代码 */
	char    asCalledCityCode[SETT_TICKET_MMS_BUFLEN_IN][33];
		/* 文件名 */
	char    asFileName[SETT_TICKET_MMS_BUFLEN_IN][65];
		/* 分组ID */
	char    asGroupID[SETT_TICKET_MMS_BUFLEN_IN][3];
		/* 主被叫 */
	char    asCallType[SETT_TICKET_MMS_BUFLEN_IN][3];
};


/*单个结构申明*/
struct SettTicketMmsStruct{

	struct SettTicketMmsStruct *pNext;
	char    sProdID[31];		/* 结算产品标识 */
	char    sStartTime[19];		/* 开始时间 */
	char    sEndTime[19];		/* 结束时间 */
	char    sCallingNumber[33];		/* 主叫号码 */
	char    sCalledNumber[33];		/* 被叫号码 */
	char    sOperationTypeID[9];		/* 业务类别 */
	int     iCityID;		/* 结算归属地市编码 */
	char    sIsFree[5];		/* 是否免费 */
	char    sRateUnitType[5];		/* 计价单位类型 */
	char    sRateUnits[13];		/* 计价单位数 */
	int     iBillCycleSeq;		/* 结算账期 */
	char    sExceptionType[9];		/* 错误类型 */
	char    sProvinceID[5];		/* 省份编码 */
	char    sCallingGroupID[33];		/* 主叫分组ID */
	char    sCalledGroupID[33];		/* 被叫分组ID */
	char    sCallingCompanyID[9];		/* 主叫归属运营商 */
	char    sCalledCompanyID[9];		/* 被叫归属运营商 */
	char    sStlObject[9];		/* 结算对象 */
	char    sStlAmount[19];		/* 结算金额（单位：毫厘） */
	char    sCallingAreaCode[33];		/* 主叫区号 */
	char    sCalledAreaCode[33];		/* 被叫区号 */
	char    sStlDirection[5];		/* 结算方向 */
	char    sUpGw[33];		/* 上行网元 */
	char    sDownGw[33];		/* 下行网元 */
	char    sUpgwGroupID[33];		/* 上行网元分组 */
	char    sDownGwGroupID[33];		/* 下行网元分组 */
	char    sUpCompanyID[33];		/* 上行网元运营商 */
	char    sDownCompanyID[33];		/* 下行网元运营商 */
	char    sUsageEventID[19];		/* 使用事件流水标识 */
	char    sCallingCityCode[33];		/* 主叫地市代码 */
	char    sCalledCityCode[33];		/* 被叫地市代码 */
	char    sFileName[65];		/* 文件名 */
	char    sGroupID[3];		/* 分组ID */
	char    sCallType[3];		/* 主被叫 */
	struct SettTicketMmsStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettTicketMmsStruct{

	char    sProdID[30];		/* 结算产品标识 */
	char    sStartTime[18];		/* 开始时间 */
	char    sEndTime[18];		/* 结束时间 */
	char    sCallingNumber[32];		/* 主叫号码 */
	char    sCalledNumber[32];		/* 被叫号码 */
	char    sOperationTypeID[8];		/* 业务类别 */
	char    sCityID[8];		/* 结算归属地市编码 */
	char    sIsFree[4];		/* 是否免费 */
	char    sRateUnitType[4];		/* 计价单位类型 */
	char    sRateUnits[12];		/* 计价单位数 */
	char    sBillCycleSeq[6];		/* 结算账期 */
	char    sExceptionType[8];		/* 错误类型 */
	char    sProvinceID[4];		/* 省份编码 */
	char    sCallingGroupID[32];		/* 主叫分组ID */
	char    sCalledGroupID[32];		/* 被叫分组ID */
	char    sCallingCompanyID[8];		/* 主叫归属运营商 */
	char    sCalledCompanyID[8];		/* 被叫归属运营商 */
	char    sStlObject[8];		/* 结算对象 */
	char    sStlAmount[18];		/* 结算金额（单位：毫厘） */
	char    sCallingAreaCode[32];		/* 主叫区号 */
	char    sCalledAreaCode[32];		/* 被叫区号 */
	char    sStlDirection[4];		/* 结算方向 */
	char    sUpGw[32];		/* 上行网元 */
	char    sDownGw[32];		/* 下行网元 */
	char    sUpgwGroupID[32];		/* 上行网元分组 */
	char    sDownGwGroupID[32];		/* 下行网元分组 */
	char    sUpCompanyID[32];		/* 上行网元运营商 */
	char    sDownCompanyID[32];		/* 下行网元运营商 */
	char    sUsageEventID[18];		/* 使用事件流水标识 */
	char    sCallingCityCode[32];		/* 主叫地市代码 */
	char    sCalledCityCode[32];		/* 被叫地市代码 */
};



/*批量数据动态从SETT_TICKET_MMS中用结构缓冲方式取数据*/
int EGetSettTicketMmsToStruct(struct SettTicketMmsStruct *p,
	struct SettTicketMmsStructIn *pSource);
void mvitem_settticketmms(struct SettTicketMmsStruct *pi,struct SettTicketMmsStruct *po);
void mvitem_fmsettticketmms(struct FSettTicketMmsStruct *pi,struct SettTicketMmsStruct *po);
void mvitem_mfsettticketmms(struct SettTicketMmsStruct *pi,struct FSettTicketMmsStruct *po);
/**对表SETT_TICKET_MMS的链表释放函数**/
void DestroySettTicketMms(struct SettTicketMmsStruct *ptHead);
int InitSettTicketMms(struct SettTicketMmsStruct **pptHead);
/*批量数据结构缓冲写入SETT_TICKET_MMS*/
int EInsertStructToSettTicketMms(struct SettTicketMmsStruct *p,
	int iInsertFlag,struct SettTicketMmsStructOut *pTarget);


/*********************************20140910接口改造******************************************/

struct SettleBintreeStruct{
	
	char sNetWork[4];
	char sOperators[4];
	int iCnt;
	BINTREE *ptRoot;
};

/*输出结构缓冲申明*/
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


/* 输入结构缓冲申明*/
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


/*单个结构申明*/
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


/*单个文件结构申明*/
struct FSettBillStorLogStruct{

	char    sSettBillStorSeq[9];
	char    sFileName[64];
	char    sFileDate[8];
	char    sDealTime[14];
	char    sState[1];
};
int SDInsertStructToSettBillStorLog(struct SettBillStorLogStruct *p,char sTableName[]);
int SDGetSettBillStorLogToStruct(struct SettBillStorLogStruct *p,char sTableName[],char sCondition[]);

/*输出结构缓冲申明*/
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
		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    asFlag[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* 费用类型,0是支出, 1是收入 */
	char    asFeeType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* 产品类型,1是本地结算, 0是其他 */
	char    asProdType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
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
		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    asFlag[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* 费用类型,0是支出, 1是收入 */
	char    asFeeType[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* 产品类型,1是本地结算, 0是其他 */
	char    asProdType[TICKET_TYPE_MAP_BUFLEN_IN][2];
};


/*单个结构申明*/
struct TicketTypeMapStruct{

	struct TicketTypeMapStruct *pNext;
	int     iReportItemID;
	char    sProdID[11];
	char    sInTrunkCarrID[2];
	char    sOutTrunkCarrID[2];
	char    sCallType[2];
	char    sFlag[2];		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    sFeeType[2];		/* 费用类型,0是支出, 1是收入 */
	char    sProdType[2];		/* 产品类型,1是本地结算, 0是其他 */
	struct TicketTypeMapStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTicketTypeMapStruct{

	char    sReportItemID[8];
	char    sProdID[10];
	char    sInTrunkCarrID[1];
	char    sOutTrunkCarrID[1];
	char    sCallType[1];
	char    sFlag[1];		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    sFeeType[1];		/* 费用类型,0是支出, 1是收入 */
	char    sProdType[1];		/* 产品类型,1是本地结算, 0是其他 */
};

/*批量数据动态从TICKET_TYPE_MAP中用结构缓冲方式取数据*/
int EGetTicketTypeMapToStruct(struct TicketTypeMapStruct *p,
	struct TicketTypeMapStructIn *pSource);
int InitTicketTypeMap(struct TicketTypeMapStruct **pptHead);


/**一级统计部分**/
/*输出结构缓冲申明*/
struct SettMTicketUeStructOut{

#ifndef SETT_M_TICKET_UE_BUFLEN_OUT
#define SETT_M_TICKET_UE_BUFLEN_OUT		300
#endif

	struct SettMTicketUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[128];
		/* 城市编码 */
	char    asCityID[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* 主叫城市代码 */
	char    asCallingCityID[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* 主叫号码类型 */
	char    asCallingType[SETT_M_TICKET_UE_BUFLEN_OUT][5];
		/* 主叫运营商 */
	char    asCallingCompCode[SETT_M_TICKET_UE_BUFLEN_OUT][3];
		/* 规整后的主叫区号 */
	char    asCallingAreaCode[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* 规整后的主叫号码 */
	char    asCallingNumber[SETT_M_TICKET_UE_BUFLEN_OUT][31];
		/* 被叫城市代码 */
	char    asCalledCityID[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* 被叫号码类型 */
	char    asCalledNumberType[SETT_M_TICKET_UE_BUFLEN_OUT][5];
		/* 主叫运营商 */
	char    asCalledCompCode[SETT_M_TICKET_UE_BUFLEN_OUT][3];
		/* 规整后的被叫区号 */
	char    asCalledAreaCode[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* 规整后的被叫号码 */
	char    asCalledNumber[SETT_M_TICKET_UE_BUFLEN_OUT][31];
		/* 时长 */
	char    asDuration[SETT_M_TICKET_UE_BUFLEN_OUT][19];
		/* 结算产品标识 */
	char    asProdID[SETT_M_TICKET_UE_BUFLEN_OUT][16];
		/* 转换后的结算时长 */
	char    asStlDuration[SETT_M_TICKET_UE_BUFLEN_OUT][19];
		/* 结算费用 */
	char    asStlAmount[SETT_M_TICKET_UE_BUFLEN_OUT][19];
		/* 话单数 */
	int     aiSettCnt[SETT_M_TICKET_UE_BUFLEN_OUT];
		/* 呼叫类型 */
	char    asCallType[SETT_M_TICKET_UE_BUFLEN_OUT][3];
		/* 结算时间 */
	char    asSettDate[SETT_M_TICKET_UE_BUFLEN_OUT][9];
		/* 主叫分组 */
	char    asGroupID[SETT_M_TICKET_UE_BUFLEN_OUT][4];
		/* 被叫分组 */
	char    asOtherGroupID[SETT_M_TICKET_UE_BUFLEN_OUT][4];
		/* 报表项ID */
	int     aiReportItemID[SETT_M_TICKET_UE_BUFLEN_OUT];
	
	char	asCallingNbrType[SETT_M_TICKET_UE_BUFLEN_OUT][3];	
	char	asCalledNbrType[SETT_M_TICKET_UE_BUFLEN_OUT][3];
	char	asSettDirection[SETT_M_TICKET_UE_BUFLEN_OUT][3];
	char	asSettCarrID[SETT_M_TICKET_UE_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
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
		/* 城市编码 */
	char    asCityID[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* 主叫城市代码 */
	char    asCallingCityID[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* 主叫号码类型 */
	char    asCallingType[SETT_M_TICKET_UE_BUFLEN_IN][5];
		/* 主叫运营商 */
	char    asCallingCompCode[SETT_M_TICKET_UE_BUFLEN_IN][3];
		/* 规整后的主叫区号 */
	char    asCallingAreaCode[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* 规整后的主叫号码 */
	char    asCallingNumber[SETT_M_TICKET_UE_BUFLEN_IN][31];
		/* 被叫城市代码 */
	char    asCalledCityID[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* 被叫号码类型 */
	char    asCalledNumberType[SETT_M_TICKET_UE_BUFLEN_IN][5];
		/* 主叫运营商 */
	char    asCalledCompCode[SETT_M_TICKET_UE_BUFLEN_IN][3];
		/* 规整后的被叫区号 */
	char    asCalledAreaCode[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* 规整后的被叫号码 */
	char    asCalledNumber[SETT_M_TICKET_UE_BUFLEN_IN][31];
		/* 时长 */
	char    asDuration[SETT_M_TICKET_UE_BUFLEN_IN][19];
		/* 结算产品标识 */
	char    asProdID[SETT_M_TICKET_UE_BUFLEN_IN][16];
		/* 转换后的结算时长 */
	char    asStlDuration[SETT_M_TICKET_UE_BUFLEN_IN][19];
		/* 结算费用 */
	char    asStlAmount[SETT_M_TICKET_UE_BUFLEN_IN][19];
		/* 话单数 */
	int     aiSettCnt[SETT_M_TICKET_UE_BUFLEN_IN];
		/* 呼叫类型 */
	char    asCallType[SETT_M_TICKET_UE_BUFLEN_IN][3];
		/* 结算时间 */
	char    asSettDate[SETT_M_TICKET_UE_BUFLEN_IN][9];
		/* 主叫分组 */
	char    asGroupID[SETT_M_TICKET_UE_BUFLEN_IN][4];
		/* 被叫分组 */
	char    asOtherGroupID[SETT_M_TICKET_UE_BUFLEN_IN][4];
		/* 报表项ID */
	int     aiReportItemID[SETT_M_TICKET_UE_BUFLEN_IN];
	
	char	asCallingNbrType[SETT_M_TICKET_UE_BUFLEN_IN][3];	
	char	asCalledNbrType[SETT_M_TICKET_UE_BUFLEN_IN][3];
	char	asSettDirection[SETT_M_TICKET_UE_BUFLEN_IN][3];
	char	asSettCarrID[SETT_M_TICKET_UE_BUFLEN_IN][3];
};


/*单个结构申明*/
struct SettMTicketUeStruct{

	struct SettMTicketUeStruct *pNext;
	char    sCityID[9];		/* 城市编码 */
	char    sCallingCityID[9];		/* 主叫城市代码 */
	char    sCallingType[5];		/* 主叫号码类型 */
	char    sCallingCompCode[3];		/* 主叫运营商 */
	char    sCallingAreaCode[9];		/* 规整后的主叫区号 */
	char    sCallingNumber[31];		/* 规整后的主叫号码 */
	char    sCalledCityID[9];		/* 被叫城市代码 */
	char    sCalledNumberType[5];		/* 被叫号码类型 */
	char    sCalledCompCode[3];		/* 主叫运营商 */
	char    sCalledAreaCode[9];		/* 规整后的被叫区号 */
	char    sCalledNumber[31];		/* 规整后的被叫号码 */
	char    sDuration[19];		/* 时长 */
	double	dDuration;
	char    sProdID[16];		/* 结算产品标识 */
	char    sStlDuration[19];		/* 转换后的结算时长 */
	double	dStlDuration;	
	char    sStlAmount[19];		/* 结算费用 */
	double	dStlAmount;
	int     iSettCnt;		/* 话单数 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sSettDate[9];		/* 结算时间 */
	char    sGroupID[4];		/* 主叫分组 */
	char    sOtherGroupID[4];		/* 被叫分组 */
	int     iReportItemID;		/* 报表项ID */
	
	char	sCallingNbrType[3];	
	char	sCalledNbrType[3];
	char	sSettDirection[3];
	char	sSettCarrID[3];
	
	struct SettMTicketUeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettMTicketUeStruct{

	char    sCityID[8];		/* 城市编码 */
	char    sCallingCityID[8];		/* 主叫城市代码 */
	char    sCallingType[4];		/* 主叫号码类型 */
	char    sCallingCompCode[2];		/* 主叫运营商 */
	char    sCallingAreaCode[8];		/* 规整后的主叫区号 */
	char    sCallingNumber[30];		/* 规整后的主叫号码 */
	char    sCalledCityID[8];		/* 被叫城市代码 */
	char    sCalledNumberType[4];		/* 被叫号码类型 */
	char    sCalledCompCode[2];		/* 主叫运营商 */
	char    sCalledAreaCode[8];		/* 规整后的被叫区号 */
	char    sCalledNumber[30];		/* 规整后的被叫号码 */
	char    sDuration[18];		/* 时长 */
	char    sProdID[15];		/* 结算产品标识 */
	char    sStlDuration[18];		/* 转换后的结算时长 */
	char    sStlAmount[18];		/* 结算费用 */
	char    sSettCnt[6];		/* 话单数 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sSettDate[8];		/* 结算时间 */
	char    sGroupID[3];		/* 主叫分组 */
	char    sOtherGroupID[3];		/* 被叫分组 */
	char    sReportItemID[9];		/* 报表项ID */
	
	char	sCallingNbrType[2];	
	char	sCalledNbrType[2];
	char	sSettDirection[2];
	char	sSettCarrID[2];
};

/*批量数据动态从SETT_M_TICKET_UE中用结构缓冲方式取数据*/
int EGetSettMTicketUeToStruct(struct SettMTicketUeStruct *p,
	struct SettMTicketUeStructIn *pSource);
void mvitem_settmticketue(struct SettMTicketUeStruct *pi,struct SettMTicketUeStruct *po);
void mvitem_fmsettmticketue(struct FSettMTicketUeStruct *pi,struct SettMTicketUeStruct *po);
void mvitem_mfsettmticketue(struct SettMTicketUeStruct *pi,struct FSettMTicketUeStruct *po);
/**对表SETT_M_TICKET_UE的链表释放函数**/
void DestroySettMTicketUe(struct SettMTicketUeStruct *ptHead);
int InitSettMTicketUe(struct SettMTicketUeStruct **pptHead);
/*批量数据结构缓冲写入SETT_M_TICKET_UE*/
int EInsertStructToSettMTicketUe(struct SettMTicketUeStruct *p,
	int iInsertFlag,struct SettMTicketUeStructOut *pTarget);

/**一级统计部分**/

/*二级统计部分*/

/*输出结构缓冲申明*/
struct SettNbrStatUeStructOut{

#ifndef SETT_NBR_STAT_UE_BUFLEN_OUT
#define SETT_NBR_STAT_UE_BUFLEN_OUT		300
#endif

	struct SettNbrStatUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[128];
		/* 帐期月份 */
	char    asSettDate[SETT_NBR_STAT_UE_BUFLEN_OUT][9];
		/* 结算归属地区号 */
	char    asSettCity[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* 结算号码 */
	char    asSettNumber[SETT_NBR_STAT_UE_BUFLEN_OUT][25];
		/* 本方号码归属地 */
	char    asHomeAreaCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* 对方号码归属地 */
	char    asOtherAreaCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* 漫游通话地 */
	char    asVisitAreaCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* 本方运营商编码 */
	char    asHomeCompCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* 对方运营商编码 */
	char    asOtherCompCode[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
		/* 呼叫方向编码 */
	char    asCallDirection[SETT_NBR_STAT_UE_BUFLEN_OUT][2];
		/* 结算类别编码 */
	char    asProdID[SETT_NBR_STAT_UE_BUFLEN_OUT][16];
		/* 结算收入 */
	int     aiSettIncome[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* 结算支出 */
	int     aiSettExpenses[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* 结算时长 */
	int     aiSettDuration[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* 通话时长 */
	int     aiDuration[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* 通话次数 */
	int     aiSettCnt[SETT_NBR_STAT_UE_BUFLEN_OUT];
		/* 业务类型 */
	char    asSvcType[SETT_NBR_STAT_UE_BUFLEN_OUT][4];
		/* 本端用户网络类型 */
	char    asHomeNetType[SETT_NBR_STAT_UE_BUFLEN_OUT][5];
		/* 对端用户网络类型 */
	char    asOtherNetType[SETT_NBR_STAT_UE_BUFLEN_OUT][5];
		/* 结算收支标识 */
	char    asSettFlag[SETT_NBR_STAT_UE_BUFLEN_OUT][2];
		/* 保留1 */
	char    asReserve1[SETT_NBR_STAT_UE_BUFLEN_OUT][11];
		/* 保留2 */
	char    asReserve2[SETT_NBR_STAT_UE_BUFLEN_OUT][11];
	
	char	asInComp[SETT_NBR_STAT_UE_BUFLEN_OUT][6];
};


/* 输入结构缓冲申明*/
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
		/* 帐期月份 */
	char    asSettDate[SETT_NBR_STAT_UE_BUFLEN_IN][9];
		/* 结算归属地区号 */
	char    asSettCity[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* 结算号码 */
	char    asSettNumber[SETT_NBR_STAT_UE_BUFLEN_IN][25];
		/* 本方号码归属地 */
	char    asHomeAreaCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* 对方号码归属地 */
	char    asOtherAreaCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* 漫游通话地 */
	char    asVisitAreaCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* 本方运营商编码 */
	char    asHomeCompCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* 对方运营商编码 */
	char    asOtherCompCode[SETT_NBR_STAT_UE_BUFLEN_IN][6];
		/* 呼叫方向编码 */
	char    asCallDirection[SETT_NBR_STAT_UE_BUFLEN_IN][2];
		/* 结算类别编码 */
	char    asProdID[SETT_NBR_STAT_UE_BUFLEN_IN][16];
		/* 结算收入 */
	int     aiSettIncome[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* 结算支出 */
	int     aiSettExpenses[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* 结算时长 */
	int     aiSettDuration[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* 通话时长 */
	int     aiDuration[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* 通话次数 */
	int     aiSettCnt[SETT_NBR_STAT_UE_BUFLEN_IN];
		/* 业务类型 */
	char    asSvcType[SETT_NBR_STAT_UE_BUFLEN_IN][4];
		/* 本端用户网络类型 */
	char    asHomeNetType[SETT_NBR_STAT_UE_BUFLEN_IN][5];
		/* 对端用户网络类型 */
	char    asOtherNetType[SETT_NBR_STAT_UE_BUFLEN_IN][5];
		/* 结算收支标识 */
	char    asSettFlag[SETT_NBR_STAT_UE_BUFLEN_IN][2];
		/* 保留1 */
	char    asReserve1[SETT_NBR_STAT_UE_BUFLEN_IN][11];
		/* 保留2 */
	char    asReserve2[SETT_NBR_STAT_UE_BUFLEN_IN][11];
	
	char	asInComp[SETT_NBR_STAT_UE_BUFLEN_IN][6];
};


/*单个结构申明*/
struct SettNbrStatUeStruct{

	struct SettNbrStatUeStruct *pNext;
	char    sSettDate[9];		/* 帐期月份 */
	char    sSettCity[6];		/* 结算归属地区号 */
	char    sSettNumber[25];		/* 结算号码 */
	char    sHomeAreaCode[6];		/* 本方号码归属地 */
	char    sOtherAreaCode[6];		/* 对方号码归属地 */
	char    sVisitAreaCode[6];		/* 漫游通话地 */
	char    sHomeCompCode[6];		/* 本方运营商编码 */
	char    sOtherCompCode[6];		/* 对方运营商编码 */
	char    sCallDirection[2];		/* 呼叫方向编码 */
	char    sProdID[16];		/* 结算类别编码 */
	int     iSettIncome;		/* 结算收入 */
	int     iSettExpenses;		/* 结算支出 */
	int     iSettDuration;		/* 结算时长 */
	int     iDuration;		/* 通话时长 */
	int     iSettCnt;		/* 通话次数 */
	char    sSvcType[4];		/* 业务类型 */
	char    sHomeNetType[5];		/* 本端用户网络类型 */
	char    sOtherNetType[5];		/* 对端用户网络类型 */
	char    sSettFlag[2];		/* 结算收支标识 */
	char    sReserve1[11];		/* 保留1 */
	char    sReserve2[11];		/* 保留2 */
	
	char	sInComp[6];		/* 附加信息，不做统计使用 */
	
	struct SettNbrStatUeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettNbrStatUeStruct{

	char    sSettDate[8];		/* 帐期月份 */
	char    sSettCity[5];		/* 结算归属地区号 */
	char    sSettNumber[24];		/* 结算号码 */
	char    sHomeAreaCode[5];		/* 本方号码归属地 */
	char    sOtherAreaCode[5];		/* 对方号码归属地 */
	char    sVisitAreaCode[5];		/* 漫游通话地 */
	char    sHomeCompCode[5];		/* 本方运营商编码 */
	char    sOtherCompCode[5];		/* 对方运营商编码 */
	char    sCallDirection[1];		/* 呼叫方向编码 */
	char    sProdID[15];		/* 结算类别编码 */
	char    sSettIncome[9];		/* 结算收入 */
	char    sSettExpenses[9];		/* 结算支出 */
	char    sSettDuration[9];		/* 结算时长 */
	char    sDuration[9];		/* 通话时长 */
	char    sSettCnt[9];		/* 通话次数 */
	char    sSvcType[3];		/* 业务类型 */
	char    sHomeNetType[4];		/* 本端用户网络类型 */
	char    sOtherNetType[4];		/* 对端用户网络类型 */
	char    sSettFlag[1];		/* 结算收支标识 */
	char    sReserve1[10];		/* 保留1 */
	char    sReserve2[10];		/* 保留2 */
};


/*批量数据动态从SETT_NBR_STAT_UE中用结构缓冲方式取数据*/
int EGetSettNbrStatUeToStruct(struct SettNbrStatUeStruct *p,
	struct SettNbrStatUeStructIn *pSource);
void mvitem_settnbrstatue(struct SettNbrStatUeStruct *pi,struct SettNbrStatUeStruct *po);
void mvitem_fmsettnbrstatue(struct FSettNbrStatUeStruct *pi,struct SettNbrStatUeStruct *po);
void mvitem_mfsettnbrstatue(struct SettNbrStatUeStruct *pi,struct FSettNbrStatUeStruct *po);
/**对表SETT_NBR_STAT_UE的链表释放函数**/
void DestroySettNbrStatUe(struct SettNbrStatUeStruct *ptHead);
int InitSettNbrStatUe(struct SettNbrStatUeStruct **pptHead);
/*批量数据结构缓冲写入SETT_NBR_STAT_UE*/
int EInsertStructToSettNbrStatUe(struct SettNbrStatUeStruct *p,
	int iInsertFlag,struct SettNbrStatUeStructOut *pTarget);


/*二级统计部分*/

/*输出结构缓冲申明*/
struct BiProductDescStructOut{

#ifndef BI_PRODUCT_DESC_BUFLEN_OUT
#define BI_PRODUCT_DESC_BUFLEN_OUT		300
#endif

	struct BiProductDescStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 产品编码 */
	char    asProdID[BI_PRODUCT_DESC_BUFLEN_OUT][16];
		/* 产品名称 */
	char    asProdName[BI_PRODUCT_DESC_BUFLEN_OUT][129];
		/* 结算方向（0：支出，1：收入） */
	char    asSettDirection[BI_PRODUCT_DESC_BUFLEN_OUT][5];
		/* 结算对象（T:电信，M：移动，U：联通） */
	char    asSettCompany[BI_PRODUCT_DESC_BUFLEN_OUT][5];
};


/* 输入结构缓冲申明*/
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
		/* 产品编码 */
	char    asProdID[BI_PRODUCT_DESC_BUFLEN_IN][16];
		/* 产品名称 */
	char    asProdName[BI_PRODUCT_DESC_BUFLEN_IN][129];
		/* 结算方向（0：支出，1：收入） */
	char    asSettDirection[BI_PRODUCT_DESC_BUFLEN_IN][5];
		/* 结算对象（T:电信，M：移动，U：联通） */
	char    asSettCompany[BI_PRODUCT_DESC_BUFLEN_IN][5];
};


/*单个结构申明*/
struct BiProductDescStruct{

	struct BiProductDescStruct *pNext;
	char    sProdID[16];		/* 产品编码 */
	char    sProdName[129];		/* 产品名称 */
	char    sSettDirection[5];		/* 结算方向（0：支出，1：收入） */
	char    sSettCompany[5];		/* 结算对象（T:电信，M：移动，U：联通） */
	struct BiProductDescStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FBiProductDescStruct{

	char    sProdID[15];		/* 产品编码 */
	char    sProdName[128];		/* 产品名称 */
	char    sSettDirection[4];		/* 结算方向（0：支出，1：收入） */
	char    sSettCompany[4];		/* 结算对象（T:电信，M：移动，U：联通） */
};


/*批量数据动态从BI_PRODUCT_DESC中用结构缓冲方式取数据*/
int EGetBiProductDescToStruct(struct BiProductDescStruct *p,
	struct BiProductDescStructIn *pSource);
/**对表BI_PRODUCT_DESC的链表释放函数**/
void DestroyBiProductDesc(struct BiProductDescStruct *ptHead);
int InitBiProductDesc(struct BiProductDescStruct **pptHead);

/*输出结构缓冲申明*/
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


/* 输入结构缓冲申明*/
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


/*单个结构申明*/
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


/*单个文件结构申明*/
struct FRptMidRelStruct{

	char    sRptCode[20];
	char    sIndexID[20];
	char    sIndexGroupID[8];
	char    sIndexGroupName[200];
};


/*批量数据动态从RPT_MID_REL中用结构缓冲方式取数据*/
int EGetRptMidRelToStruct(struct RptMidRelStruct *p,
	struct RptMidRelStructIn *pSource);
int InitRptMidRel(struct RptMidRelStruct **pptHead);
/**对表RPT_MID_REL的链表释放函数**/
void DestroyRptMidRel(struct RptMidRelStruct *ptHead);

/*输出结构缓冲申明*/
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


/* 输入结构缓冲申明*/
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


/*单个结构申明*/
struct SettInsertLogStruct{

	struct SettInsertLogStruct *pNext;
	char    sFileName[129];
	char    sTableName[31];
	char    sDataDate[9];
	int	iInsertCnt;
	char	sState[3];
	struct SettInsertLogStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettInsertLogStruct{

	char    sFileName[128];
	char	sTableName[30];
	char    sDataDate[8];
	char	sInsertCnt[8];
};


/*批量数据动态从SETT_INSERT_LOG中用结构缓冲方式取数据*/
int EGetSettInsertLogToStruct(struct SettInsertLogStruct *p,
	struct SettInsertLogStructIn *pSource);
/**对表SETT_INSERT_LOG的链表释放函数**/
void DestroySettInsertLog(struct SettInsertLogStruct *ptHead);
/*批量数据结构缓冲写入SETT_INSERT_LOG*/
int EInsertStructToSettInsertLog(struct SettInsertLogStruct *p,
	int iInsertFlag,struct SettInsertLogStructOut *pTarget);

/*输出结构缓冲申明*/
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


/* 输入结构缓冲申明*/
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


/*单个结构申明*/
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


/*单个文件结构申明*/
struct FSubsTrunkStruct{

	char    sTrunkNumber[12];
	char    sCityID[4];
	char    sProvinceID[4];
	char    sTrunkDesc[40];
	char    sTrunkAttribute[4];
	char    sSubType[1];
};


/*批量数据动态从SUBS_TRUNK中用结构缓冲方式取数据*/
int EGetSubsTrunkToStruct(struct SubsTrunkStruct *p,
	struct SubsTrunkStructIn *pSource);
/**对表SUBS_TRUNK的链表释放函数**/
void DestroySubsTrunk(struct SubsTrunkStruct *ptHead);
int InitSubsTrunk(struct SubsTrunkStruct **pptHead);





#endif
