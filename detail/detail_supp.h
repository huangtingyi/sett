#ifndef __DETAIL_SUPP_H__
#define __DETAIL_SUPP_H__

#include <hnixs.h>
#include <wwfile.h>
#include <list.h>
#include <trie.h>

//#include <detail_intf.h>


/*输出结构缓冲申明*/
struct AccSttTicketStructOut{

#ifndef ACC_STT_TICKET_BUFLEN_OUT
#define ACC_STT_TICKET_BUFLEN_OUT		300
#endif

	struct AccSttTicketStructOut *pNext;

	int 	iCurPos;
	int 	iRecordCnt;
	char 	sTableName[31];
	char    asUsageSeq[ACC_STT_TICKET_BUFLEN_OUT][19];
	char    asSourceID[ACC_STT_TICKET_BUFLEN_OUT][7];
	char    asHomeAreaCode[ACC_STT_TICKET_BUFLEN_OUT][7];
	char    asMsisdn[ACC_STT_TICKET_BUFLEN_OUT][31];
	char    asSettCity[ACC_STT_TICKET_BUFLEN_OUT][7];
	char    asOppAreaCode[ACC_STT_TICKET_BUFLEN_OUT][7];
	char    asOtherParty[ACC_STT_TICKET_BUFLEN_OUT][31];
	char    asCallType[ACC_STT_TICKET_BUFLEN_OUT][3];
	char    asStartTime[ACC_STT_TICKET_BUFLEN_OUT][14];
	char    asEndTime[ACC_STT_TICKET_BUFLEN_OUT][14];
	char    asDuration[ACC_STT_TICKET_BUFLEN_OUT][9];
	char    asAuditType[ACC_STT_TICKET_BUFLEN_OUT][3];
};

/*输入缓冲结构说明*/
struct AccSttTicketStructIn{

#ifndef ACC_STT_TICKET_BUFLEN_IN
#define ACC_STT_TICKET_BUFLEN_IN		300
#endif

	struct AccSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asUsageSeq[ACC_STT_TICKET_BUFLEN_IN][19];
	char    asCityID[ACC_STT_TICKET_BUFLEN_IN][7];
	char    asCdrType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asCallingCityID[ACC_STT_TICKET_BUFLEN_IN][9];
	char    asCallingException[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asCallingType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asCallingCompCode[ACC_STT_TICKET_BUFLEN_IN][3];
	char    asCallingAreaCode[ACC_STT_TICKET_BUFLEN_IN][9];
	char    asCallingNumber[ACC_STT_TICKET_BUFLEN_IN][31];
	char    asCalledCityID[ACC_STT_TICKET_BUFLEN_IN][9];
	char    asCalledException[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asCalledNumberType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asCalledCompCode[ACC_STT_TICKET_BUFLEN_IN][3];
	char    asCalledAreaCode[ACC_STT_TICKET_BUFLEN_IN][9];
	char    asCalledNumber[ACC_STT_TICKET_BUFLEN_IN][31];
	char    asStartTime[ACC_STT_TICKET_BUFLEN_IN][17];
	char    asEndTime[ACC_STT_TICKET_BUFLEN_IN][17];
	char    asDuration[ACC_STT_TICKET_BUFLEN_IN][19];
	char    asInTrunkNumber[ACC_STT_TICKET_BUFLEN_IN][12];
	char    asInCompanyCode[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asInTrunkNetType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asOutTrunkNumber[ACC_STT_TICKET_BUFLEN_IN][12];
	char    asOutCompanyCode[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asOutTrunkNetType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asIsFree[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asCallingLocation[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asSecondCallingLocation[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asOrigCallingNumber[ACC_STT_TICKET_BUFLEN_IN][37];
	char    asOrigCalledNumber[ACC_STT_TICKET_BUFLEN_IN][37];
	char    asOrigSecondCallingNumber[ACC_STT_TICKET_BUFLEN_IN][37];
	char    asExceptionType[ACC_STT_TICKET_BUFLEN_IN][11];
	char    asPreCallType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asTurnType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asProdID[ACC_STT_TICKET_BUFLEN_IN][16];
	char    asRateUnitType[ACC_STT_TICKET_BUFLEN_IN][5];
	char    asStlDuration[ACC_STT_TICKET_BUFLEN_IN][19];
	char    asRateID[ACC_STT_TICKET_BUFLEN_IN][11];
	char    asStlAmount[ACC_STT_TICKET_BUFLEN_IN][19];
	char    asGroupID[ACC_STT_TICKET_BUFLEN_IN][3];
	char    asFileName[ACC_STT_TICKET_BUFLEN_IN][65];
	char    asCallType[ACC_STT_TICKET_BUFLEN_IN][3];
};


/*单个结构申明*/
struct AccSttTicketStruct{

	struct AccSttTicketStruct *pNext;
	char    sUsageSeq[19];
	char    sCityID[7];
	char    sCdrType[5];
	char    sCallingCityID[9];
	char    sCallingException[5];
	char    sCallingType[5];
	char    sCallingCompCode[3];
	char    sCallingAreaCode[9];
	char    sCallingNumber[31];
	char    sCalledCityID[9];
	char    sCalledException[5];
	char    sCalledNumberType[5];
	char    sCalledCompCode[3];
	char    sCalledAreaCode[9];
	char    sCalledNumber[31];
	char    sStartTime[17];
	char    sEndTime[17];
	char    sDuration[19];
	char    sInTrunkNumber[12];
	char    sInCompanyCode[5];
	char    sInTrunkNetType[5];
	char    sOutTrunkNumber[12];
	char    sOutCompanyCode[5];
	char    sOutTrunkNetType[5];
	char    sIsFree[5];
	char    sCallingLocation[5];
	char    sSecondCallingLocation[5];
	char    sOrigCallingNumber[37];
	char    sOrigCalledNumber[37];
	char    sOrigSecondCallingNumber[37];
	char    sExceptionType[11];
	char    sPreCallType[5];
	char    sTurnType[5];
	char    sProdID[16];
	char    sRateUnitType[5];
	char    sStlDuration[19];
	char    sRateID[11];
	char    sStlAmount[19];
	char    sGroupID[3];
	char    sFileName[65];
	char    sCallType[3];
	struct AccSttTicketStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FAccSttTicketStruct{

	char    sUsageSeq[18];
	char    sCityID[6];
	char    sCdrType[4];
	char    sCallingCityID[8];
	char    sCallingException[4];
	char    sCallingType[4];
	char    sCallingCompCode[2];
	char    sCallingAreaCode[8];
	char    sCallingNumber[30];
	char    sCalledCityID[8];
	char    sCalledException[4];
	char    sCalledNumberType[4];
	char    sCalledCompCode[2];
	char    sCalledAreaCode[8];
	char    sCalledNumber[30];
	char    sStartTime[16];
	char    sEndTime[16];
	char    sDuration[18];
	char    sInTrunkNumber[11];
	char    sInCompanyCode[4];
	char    sInTrunkNetType[4];
	char    sOutTrunkNumber[11];
	char    sOutCompanyCode[4];
	char    sOutTrunkNetType[4];
	char    sIsFree[4];
	char    sCallingLocation[4];
	char    sSecondCallingLocation[4];
	char    sOrigCallingNumber[36];
	char    sOrigCalledNumber[36];
	char    sOrigSecondCallingNumber[36];
	char    sExceptionType[10];
	char    sPreCallType[4];
	char    sTurnType[4];
	char    sProdID[15];
	char    sRateUnitType[4];
	char    sStlDuration[18];
	char    sRateID[10];
	char    sStlAmount[18];
	char    sGroupID[2];
	char    sFileName[64];
	char    sCallType[2];
};


/*输出结构缓冲申明*/
struct AccSmsTicketStructOut{

#ifndef ACC_SMS_TICKET_BUFLEN_OUT
#define ACC_SMS_TICKET_BUFLEN_OUT		300
#endif

	struct AccSmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asProdID[ACC_SMS_TICKET_BUFLEN_OUT][31];
	char    asStartTime[ACC_SMS_TICKET_BUFLEN_OUT][19];
	char    asEndTime[ACC_SMS_TICKET_BUFLEN_OUT][19];
	char    asCallingNumber[ACC_SMS_TICKET_BUFLEN_OUT][33];
	char    asCallingCityID[ACC_SMS_TICKET_BUFLEN_OUT][7];
	char    asCallingCompanyID[ACC_SMS_TICKET_BUFLEN_OUT][3];
	char    asCallingNumberType[ACC_SMS_TICKET_BUFLEN_OUT][5];
	char    asCalledNumber[ACC_SMS_TICKET_BUFLEN_OUT][33];
	char    asCalledCityID[ACC_SMS_TICKET_BUFLEN_OUT][7];
	char    asCalledCompanyID[ACC_SMS_TICKET_BUFLEN_OUT][3];
	char    asCalledNumberType[ACC_SMS_TICKET_BUFLEN_OUT][5];
	int     aiCityID[ACC_SMS_TICKET_BUFLEN_OUT];
	char    asIsFree[ACC_SMS_TICKET_BUFLEN_OUT][5];
	int     aiBillCycleSeq[ACC_SMS_TICKET_BUFLEN_OUT];
	char    asExceptionType[ACC_SMS_TICKET_BUFLEN_OUT][9];
	char    asStlAmount[ACC_SMS_TICKET_BUFLEN_OUT][19];
	char    asCallingAreaCode[ACC_SMS_TICKET_BUFLEN_OUT][33];
	char    asCalledAreaCode[ACC_SMS_TICKET_BUFLEN_OUT][33];
	char    asStlDirection[ACC_SMS_TICKET_BUFLEN_OUT][5];
	char    asUpGw[ACC_SMS_TICKET_BUFLEN_OUT][33];
	char    asDownGw[ACC_SMS_TICKET_BUFLEN_OUT][33];
	char    asUpCompanyID[ACC_SMS_TICKET_BUFLEN_OUT][3];
	char    asDownCompanyID[ACC_SMS_TICKET_BUFLEN_OUT][3];
	char    asUsageEventID[ACC_SMS_TICKET_BUFLEN_OUT][19];
	char    asFileName[ACC_SMS_TICKET_BUFLEN_OUT][65];
	char    asGroupID[ACC_SMS_TICKET_BUFLEN_OUT][3];
	char    asCallType[ACC_SMS_TICKET_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
struct AccSmsTicketStructIn{

#ifndef ACC_SMS_TICKET_BUFLEN_IN
#define ACC_SMS_TICKET_BUFLEN_IN		300
#endif

	struct AccSmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asProdID[ACC_SMS_TICKET_BUFLEN_IN][31];
	char    asStartTime[ACC_SMS_TICKET_BUFLEN_IN][19];
	char    asEndTime[ACC_SMS_TICKET_BUFLEN_IN][19];
	char    asCallingNumber[ACC_SMS_TICKET_BUFLEN_IN][33];
	char    asCallingCityID[ACC_SMS_TICKET_BUFLEN_IN][7];
	char    asCallingCompanyID[ACC_SMS_TICKET_BUFLEN_IN][3];
	char    asCallingNumberType[ACC_SMS_TICKET_BUFLEN_IN][5];
	char    asCalledNumber[ACC_SMS_TICKET_BUFLEN_IN][33];
	char    asCalledCityID[ACC_SMS_TICKET_BUFLEN_IN][7];
	char    asCalledCompanyID[ACC_SMS_TICKET_BUFLEN_IN][3];
	char    asCalledNumberType[ACC_SMS_TICKET_BUFLEN_IN][5];
	int     aiCityID[ACC_SMS_TICKET_BUFLEN_IN];
	char    asIsFree[ACC_SMS_TICKET_BUFLEN_IN][5];
	int     aiBillCycleSeq[ACC_SMS_TICKET_BUFLEN_IN];
	char    asExceptionType[ACC_SMS_TICKET_BUFLEN_IN][9];
	char    asStlAmount[ACC_SMS_TICKET_BUFLEN_IN][19];
	char    asCallingAreaCode[ACC_SMS_TICKET_BUFLEN_IN][33];
	char    asCalledAreaCode[ACC_SMS_TICKET_BUFLEN_IN][33];
	char    asStlDirection[ACC_SMS_TICKET_BUFLEN_IN][5];
	char    asUpGw[ACC_SMS_TICKET_BUFLEN_IN][33];
	char    asDownGw[ACC_SMS_TICKET_BUFLEN_IN][33];
	char    asUpCompanyID[ACC_SMS_TICKET_BUFLEN_IN][3];
	char    asDownCompanyID[ACC_SMS_TICKET_BUFLEN_IN][3];
	char    asUsageEventID[ACC_SMS_TICKET_BUFLEN_IN][19];
	char    asFileName[ACC_SMS_TICKET_BUFLEN_IN][65];
	char    asGroupID[ACC_SMS_TICKET_BUFLEN_IN][3];
	char    asCallType[ACC_SMS_TICKET_BUFLEN_IN][3];
};


/*单个结构申明*/
struct AccSmsTicketStruct{

	struct AccSmsTicketStruct *pNext;
	char    sProdID[31];
	char    sStartTime[19];
	char    sEndTime[19];
	char    sCallingNumber[33];
	char    sCallingCityID[7];
	char    sCallingCompanyID[3];
	char    sCallingNumberType[5];
	char    sCalledNumber[33];
	char    sCalledCityID[7];
	char    sCalledCompanyID[3];
	char    sCalledNumberType[5];
	int     iCityID;
	char    sIsFree[5];
	int     iBillCycleSeq;
	char    sExceptionType[9];
	char    sStlAmount[19];
	char    sCallingAreaCode[33];
	char    sCalledAreaCode[33];
	char    sStlDirection[5];
	char    sUpGw[33];
	char    sDownGw[33];
	char    sUpCompanyID[3];
	char    sDownCompanyID[3];
	char    sUsageEventID[19];
	char    sFileName[65];
	char    sGroupID[3];
	char    sCallType[3];
	struct AccSmsTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAccSmsTicketStruct{

	char    sProdID[30];
	char    sStartTime[18];
	char    sEndTime[18];
	char    sCallingNumber[32];
	char    sCallingCityID[6];
	char    sCallingCompanyID[2];
	char    sCallingNumberType[4];
	char    sCalledNumber[32];
	char    sCalledCityID[6];
	char    sCalledCompanyID[2];
	char    sCalledNumberType[4];
	char    sCityID[8];
	char    sIsFree[4];
	char    sBillCycleSeq[6];
	char    sExceptionType[8];
	char    sStlAmount[18];
	char    sCallingAreaCode[32];
	char    sCalledAreaCode[32];
	char    sStlDirection[4];
	char    sUpGw[32];
	char    sDownGw[32];
	char    sUpCompanyID[2];
	char    sDownCompanyID[2];
	char    sUsageEventID[18];
	char    sFileName[64];
	char    sGroupID[2];
	char    sCallType[2];
};

/*输出结构缓冲申明*/
struct AccMmsTicketStructOut{

#ifndef ACC_MMS_TICKET_BUFLEN_OUT
#define ACC_MMS_TICKET_BUFLEN_OUT		300
#endif

	struct AccMmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asProdID[ACC_MMS_TICKET_BUFLEN_OUT][31];
	char    asStartTime[ACC_MMS_TICKET_BUFLEN_OUT][19];
	char    asEndTime[ACC_MMS_TICKET_BUFLEN_OUT][19];
	char    asCallingNumber[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asCalledNumber[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asOperationTypeID[ACC_MMS_TICKET_BUFLEN_OUT][9];
	int     aiCityID[ACC_MMS_TICKET_BUFLEN_OUT];
	char    asIsFree[ACC_MMS_TICKET_BUFLEN_OUT][5];
	char    asRateUnitType[ACC_MMS_TICKET_BUFLEN_OUT][5];
	char    asRateUnits[ACC_MMS_TICKET_BUFLEN_OUT][13];
	int     aiBillCycleSeq[ACC_MMS_TICKET_BUFLEN_OUT];
	char    asExceptionType[ACC_MMS_TICKET_BUFLEN_OUT][9];
	char    asProvinceID[ACC_MMS_TICKET_BUFLEN_OUT][5];
	char    asCallingGroupID[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asCalledGroupID[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asCallingCompanyID[ACC_MMS_TICKET_BUFLEN_OUT][9];
	char    asCalledCompanyID[ACC_MMS_TICKET_BUFLEN_OUT][9];
	char    asStlObject[ACC_MMS_TICKET_BUFLEN_OUT][9];
	char    asStlAmount[ACC_MMS_TICKET_BUFLEN_OUT][19];
	char    asCallingAreaCode[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asCalledAreaCode[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asStlDirection[ACC_MMS_TICKET_BUFLEN_OUT][5];
	char    asUpGw[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asDownGw[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asUpgwGroupID[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asDownGwGroupID[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asUpCompanyID[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asDownCompanyID[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asUsageSeq[ACC_MMS_TICKET_BUFLEN_OUT][19];
	char    asCallingCityCode[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asCalledCityCode[ACC_MMS_TICKET_BUFLEN_OUT][33];
	char    asFileName[ACC_MMS_TICKET_BUFLEN_OUT][65];
	char    asGroupID[ACC_MMS_TICKET_BUFLEN_OUT][3];
	char    asCallType[ACC_MMS_TICKET_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
struct AccMmsTicketStructIn{

#ifndef ACC_MMS_TICKET_BUFLEN_IN
#define ACC_MMS_TICKET_BUFLEN_IN		300
#endif

	struct AccMmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asProdID[ACC_MMS_TICKET_BUFLEN_IN][31];
	char    asStartTime[ACC_MMS_TICKET_BUFLEN_IN][19];
	char    asEndTime[ACC_MMS_TICKET_BUFLEN_IN][19];
	char    asCallingNumber[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asCalledNumber[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asOperationTypeID[ACC_MMS_TICKET_BUFLEN_IN][9];
	int     aiCityID[ACC_MMS_TICKET_BUFLEN_IN];
	char    asIsFree[ACC_MMS_TICKET_BUFLEN_IN][5];
	char    asRateUnitType[ACC_MMS_TICKET_BUFLEN_IN][5];
	char    asRateUnits[ACC_MMS_TICKET_BUFLEN_IN][13];
	int     aiBillCycleSeq[ACC_MMS_TICKET_BUFLEN_IN];
	char    asExceptionType[ACC_MMS_TICKET_BUFLEN_IN][9];
	char    asProvinceID[ACC_MMS_TICKET_BUFLEN_IN][5];
	char    asCallingGroupID[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asCalledGroupID[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asCallingCompanyID[ACC_MMS_TICKET_BUFLEN_IN][9];
	char    asCalledCompanyID[ACC_MMS_TICKET_BUFLEN_IN][9];
	char    asStlObject[ACC_MMS_TICKET_BUFLEN_IN][9];
	char    asStlAmount[ACC_MMS_TICKET_BUFLEN_IN][19];
	char    asCallingAreaCode[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asCalledAreaCode[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asStlDirection[ACC_MMS_TICKET_BUFLEN_IN][5];
	char    asUpGw[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asDownGw[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asUpgwGroupID[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asDownGwGroupID[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asUpCompanyID[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asDownCompanyID[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asUsageSeq[ACC_MMS_TICKET_BUFLEN_IN][19];
	char    asCallingCityCode[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asCalledCityCode[ACC_MMS_TICKET_BUFLEN_IN][33];
	char    asFileName[ACC_MMS_TICKET_BUFLEN_IN][65];
	char    asGroupID[ACC_MMS_TICKET_BUFLEN_IN][3];
	char    asCallType[ACC_MMS_TICKET_BUFLEN_IN][3];
};


/*单个结构申明*/
struct AccMmsTicketStruct{

	struct AccMmsTicketStruct *pNext;
	char    sProdID[31];
	char    sStartTime[19];
	char    sEndTime[19];
	char    sCallingNumber[33];
	char    sCalledNumber[33];
	char    sOperationTypeID[9];
	int     iCityID;
	char    sIsFree[5];
	char    sRateUnitType[5];
	char    sRateUnits[13];
	int     iBillCycleSeq;
	char    sExceptionType[9];
	char    sProvinceID[5];
	char    sCallingGroupID[33];
	char    sCalledGroupID[33];
	char    sCallingCompanyID[9];
	char    sCalledCompanyID[9];
	char    sStlObject[9];
	char    sStlAmount[19];
	char    sCallingAreaCode[33];
	char    sCalledAreaCode[33];
	char    sStlDirection[5];
	char    sUpGw[33];
	char    sDownGw[33];
	char    sUpgwGroupID[33];
	char    sDownGwGroupID[33];
	char    sUpCompanyID[33];
	char    sDownCompanyID[33];
	char    sUsageSeq[19];
	char    sCallingCityCode[33];
	char    sCalledCityCode[33];
	char    sFileName[65];
	char    sGroupID[3];
	char    sCallType[3];
	struct AccMmsTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAccMmsTicketStruct{

	char    sProdID[30];
	char    sStartTime[18];
	char    sEndTime[18];
	char    sCallingNumber[32];
	char    sCalledNumber[32];
	char    sOperationTypeID[8];
	char    sCityID[8];
	char    sIsFree[4];
	char    sRateUnitType[4];
	char    sRateUnits[12];
	char    sBillCycleSeq[6];
	char    sExceptionType[8];
	char    sProvinceID[4];
	char    sCallingGroupID[32];
	char    sCalledGroupID[32];
	char    sCallingCompanyID[8];
	char    sCalledCompanyID[8];
	char    sStlObject[8];
	char    sStlAmount[18];
	char    sCallingAreaCode[32];
	char    sCalledAreaCode[32];
	char    sStlDirection[4];
	char    sUpGw[32];
	char    sDownGw[32];
	char    sUpgwGroupID[32];
	char    sDownGwGroupID[32];
	char    sUpCompanyID[32];
	char    sDownCompanyID[32];
	char    sUsageSeq[18];
	char    sCallingCityCode[32];
	char    sCalledCityCode[32];
	char    sFileName[64];
	char    sGroupID[2];
	char    sCallType[2];
};

/* 输入结构缓冲申明*/
struct StPrepTicketStructIn{

#ifndef ST_PREP_TICKET_BUFLEN_IN
#define ST_PREP_TICKET_BUFLEN_IN		300
#endif

	struct StPrepTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[1024];
	char sCondition[1024];
	char    asUsageEventID[ST_PREP_TICKET_BUFLEN_IN][19];
	char    asSourceID[ST_PREP_TICKET_BUFLEN_IN][7];
	char    asHomeAreaCode[ST_PREP_TICKET_BUFLEN_IN][7];
	char    asMsisdn[ST_PREP_TICKET_BUFLEN_IN][31];
	char    asSettCity[ST_PREP_TICKET_BUFLEN_IN][7];
	char    asOppAreaCode[ST_PREP_TICKET_BUFLEN_IN][7];
	char    asOtherParty[ST_PREP_TICKET_BUFLEN_IN][31];
	char    asCallType[ST_PREP_TICKET_BUFLEN_IN][3];
	char    asStartTime[ST_PREP_TICKET_BUFLEN_IN][15];
	char    asEndTime[ST_PREP_TICKET_BUFLEN_IN][15];
	int     aiDuration[ST_PREP_TICKET_BUFLEN_IN];
	char    asAuditType[ST_PREP_TICKET_BUFLEN_IN][3];
	char    asGroupId[ST_PREP_TICKET_BUFLEN_IN][3];
	char    asThirdParty[ST_PREP_TICKET_BUFLEN_IN][31];
	char	asOppUsageEventID[ST_PREP_TICKET_BUFLEN_IN][19];
	char    asDataFileDay[ST_PREP_TICKET_BUFLEN_IN][9];
	char    asCalledAMsisdn[ST_PREP_TICKET_BUFLEN_IN][31];
	char    asFileName[ST_PREP_TICKET_BUFLEN_IN][81];
	char    asRowID[ST_PREP_TICKET_BUFLEN_IN][19];
};

/*输出结构缓冲申明*/
struct StPrepTicketStructOut{

#ifndef ST_PREP_TICKET_BUFLEN_OUT
#define ST_PREP_TICKET_BUFLEN_OUT		300
#endif

	struct StPrepTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[1024];
	char    asUsageEventID[ST_PREP_TICKET_BUFLEN_OUT][19];
	char    asSourceID[ST_PREP_TICKET_BUFLEN_OUT][7];
	char    asHomeAreaCode[ST_PREP_TICKET_BUFLEN_OUT][7];
	char    asMsisdn[ST_PREP_TICKET_BUFLEN_OUT][31];
	char    asSettCity[ST_PREP_TICKET_BUFLEN_OUT][7];
	char    asOppAreaCode[ST_PREP_TICKET_BUFLEN_OUT][7];
	char    asOtherParty[ST_PREP_TICKET_BUFLEN_OUT][31];
	char    asCallType[ST_PREP_TICKET_BUFLEN_OUT][3];
	char    asStartTime[ST_PREP_TICKET_BUFLEN_OUT][15];
	char    asEndTime[ST_PREP_TICKET_BUFLEN_OUT][15];
	int     aiDuration[ST_PREP_TICKET_BUFLEN_OUT];
	char    asAuditType[ST_PREP_TICKET_BUFLEN_OUT][3];
	char    asGroupId[ST_PREP_TICKET_BUFLEN_OUT][3];
	char    asThirdParty[ST_PREP_TICKET_BUFLEN_OUT][31];
	char    asRowID[ST_PREP_TICKET_BUFLEN_OUT][19];
	char		asOppUsageEventID[ST_PREP_TICKET_BUFLEN_OUT][19];
	char    asDataFileDay[ST_PREP_TICKET_BUFLEN_OUT][9];
	char    asCalledMsisdn[ST_PREP_TICKET_BUFLEN_OUT][31];
	char    asFileName[ST_PREP_TICKET_BUFLEN_OUT][81];
};

/*单个结构申明*/
struct StPrepTicketStruct{

	struct StPrepTicketStruct *pNext;
	char    sUsageEventID[19];
	char    sSourceID[7];
	char    sHomeAreaCode[7];
	char    sMsisdn[31];
	char    sSettCity[7];
	char    sOppAreaCode[7];
	char    sOtherParty[31];
	char    sCallType[3];
	char    sStartTime[15];
	char    sEndTime[15];
	int     iDuration;
	char    sAuditType[3];
	char		sGroupId[3];
	char    sThirdParty[31];
	char		sOppUsageEventID[19];
	char    sDataFileDay[9];
	char    sCalledMsisdn[31];
	char    sFileName[81];
	char		sRowID[19];
	
	
	char	sSplitFlag[2];
	int	iOffset;
	char	sFirstFlag;
	char	cPreFlag;
	struct StPrepTicketStruct *pLoadNext;
};
struct StPrepTicketStructUp
{
#ifndef ST_PREP_TICKET_UP
#define ST_PREP_TICKET_UP 	300
#endif
	int	iCurPos;
	char	sTableName[1024];
	
	char	asAuditType[ST_PREP_TICKET_UP][3];
	char	asOppUsageEventID[ST_PREP_TICKET_UP][19];
	char	asRowID[ST_PREP_TICKET_UP][19];
};

/*单个文件结构申明*/
struct FStPrepTicketStruct{

	char    sUsageEventID[18];
	char    sSourceID[6];
	char    sHomeAreaCode[6];
	char    sMsisdn[30];
	char    sSettCity[6];
	char    sOppAreaCode[6];
	char    sOtherParty[30];
	char    sCallType[2];
	char    sStartTime[14];
	char    sEndTime[14];
	char    sDuration[8];
	char    sAuditType[2];
	char    sThirdParty[30];
	char		sDataFileDay[8];
	char		sCalledMsisdn[30];
	char 	  sFileName[80];		
	char		sGroupId[2];/*新增字段一定要放在这个前面*/
};

/*批量数据结构缓冲写入ST_PREP_TICKET*/
int EGetStPrepTicketToStruct(struct StPrepTicketStruct *p,
	struct StPrepTicketStructIn *pSource);
/*批量数据结构缓冲写入ST_STT_PREP_TICKET*/
int EInsertStructToStPrepTicket(struct StPrepTicketStruct *p,
	int iInsertFlag,struct StPrepTicketStructOut *pTarget, char *sSourceID);
/*数据文件移动到内存部分*/
void mvitem_fmstprepticket(struct FStPrepTicketStruct *pi,
	struct StPrepTicketStruct *po);
int EUpdateStructToStPrepTicket(struct StPrepTicketStruct *p,
	int iUpdateFlag,struct StPrepTicketStructUp *pTarget);

/*输出结构缓冲申明*/
struct OdsSttTicketStructOut{

#ifndef ODS_STT_TICKET_BUFLEN_OUT
#define ODS_STT_TICKET_BUFLEN_OUT		300
#endif

	struct OdsSttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asUsageEventID[ODS_STT_TICKET_BUFLEN_OUT][19];
	char    asVisitAreaCode[ODS_STT_TICKET_BUFLEN_OUT][11];
	int     aiCallType[ODS_STT_TICKET_BUFLEN_OUT];
	char    asServiceNum1[ODS_STT_TICKET_BUFLEN_OUT][41];
	char    asServiceNumr[ODS_STT_TICKET_BUFLEN_OUT][41];
	int     aiSubscriptionID[ODS_STT_TICKET_BUFLEN_OUT];
	char    asHomeAreaCode[ODS_STT_TICKET_BUFLEN_OUT][11];
	char    asOtherParty[ODS_STT_TICKET_BUFLEN_OUT][41];
	char    asOppAreaCode[ODS_STT_TICKET_BUFLEN_OUT][11];
	int     aiOppNetType[ODS_STT_TICKET_BUFLEN_OUT];
	int     aiOppNumType[ODS_STT_TICKET_BUFLEN_OUT];
	char    asStartTime[ODS_STT_TICKET_BUFLEN_OUT][15];
	int     aiCallDuration[ODS_STT_TICKET_BUFLEN_OUT];
	char    asThirdParty[ODS_STT_TICKET_BUFLEN_OUT][41];
	char    asDataFileDay[ODS_STT_TICKET_BUFLEN_OUT][9];
	char    asTrunkGroupout[ODS_STT_TICKET_BUFLEN_OUT][25];
	char    asOriginalFile[ODS_STT_TICKET_BUFLEN_OUT][81];
};


/* 输入结构缓冲申明*/
struct OdsSttTicketStructIn{

#ifndef ODS_STT_TICKET_BUFLEN_IN
#define ODS_STT_TICKET_BUFLEN_IN		300
#endif

	struct OdsSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asUsageEventID[ODS_STT_TICKET_BUFLEN_IN][19];
	char    asVisitAreaCode[ODS_STT_TICKET_BUFLEN_IN][11];
	int     aiCallType[ODS_STT_TICKET_BUFLEN_IN];
	char    asServiceNum1[ODS_STT_TICKET_BUFLEN_IN][41];
	char    asServiceNumr[ODS_STT_TICKET_BUFLEN_IN][41];
	int     aiSubscriptionID[ODS_STT_TICKET_BUFLEN_IN];
	char    asHomeAreaCode[ODS_STT_TICKET_BUFLEN_IN][11];
	char    asOtherParty[ODS_STT_TICKET_BUFLEN_IN][41];
	char    asOppAreaCode[ODS_STT_TICKET_BUFLEN_IN][11];
	int     aiOppNetType[ODS_STT_TICKET_BUFLEN_IN];
	int     aiOppNumType[ODS_STT_TICKET_BUFLEN_IN];
	char    asStartTime[ODS_STT_TICKET_BUFLEN_IN][15];
	int     aiCallDuration[ODS_STT_TICKET_BUFLEN_IN];
	char    asThirdParty[ODS_STT_TICKET_BUFLEN_IN][41];
	char    asDataFileDay[ODS_STT_TICKET_BUFLEN_IN][9];
	char    asTrunkGroupout[ODS_STT_TICKET_BUFLEN_IN][25];
	char    asOriginalFile[ODS_STT_TICKET_BUFLEN_IN][81];
};


/*单个结构申明*/
struct OdsSttTicketStruct{

	struct OdsSttTicketStruct *pNext;
	char    sUsageEventID[19];
	char    sVisitAreaCode[11];
	int     iCallType;
	char    sServiceNum1[41];
	char    sServiceNumr[41];
	int     iSubscriptionID;
	char    sHomeAreaCode[11];
	char    sOtherParty[41];
	char    sOppAreaCode[11];
	int     iOppNetType;
	int     iOppNumType;
	char    sStartTime[15];
	int     iCallDuration;
	char    sThirdParty[41];
	char    sDataFileDay[9];
	char    sTrunkGroupout[25];
	char    sOriginalFile[81];
	struct OdsSttTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FOdsSttTicketStruct{

	char    sUsageEventID[18];
	char    sVisitAreaCode[10];
	char    sCallType[2];
	char    sServiceNum1[40];
	char    sServiceNumr[40];
	char    sSubscriptionID[9];
	char    sHomeAreaCode[10];
	char    sOtherParty[40];
	char    sOppAreaCode[10];
	char    sOppNetType[2];
	char    sOppNumType[4];
	char    sStartTime[14];
	char    sCallDuration[9];
	char    sThirdParty[40];
	char    sDataFileDay[8];
	char    sTrunkGroupout[24];
	char    sOriginalFile[80];
};

/*输出结构缓冲申明*/
struct OdsSmsTicketStructOut{

#ifndef ODS_SMS_TICKET_BUFLEN_OUT
#define ODS_SMS_TICKET_BUFLEN_OUT		300
#endif

	struct OdsSmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiServiceID[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asBillNumber[ODS_SMS_TICKET_BUFLEN_OUT][41];
	int     aiCallType[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asHomeArea[ODS_SMS_TICKET_BUFLEN_OUT][6];
	char    asStartTime[ODS_SMS_TICKET_BUFLEN_OUT][15];
	char    asOtherParty[ODS_SMS_TICKET_BUFLEN_OUT][41];
	char    asOppNumber[ODS_SMS_TICKET_BUFLEN_OUT][41];
	char    asSpCode[ODS_SMS_TICKET_BUFLEN_OUT][7];
	char    asSpSmg[ODS_SMS_TICKET_BUFLEN_OUT][7];
	char    asAccessCode[ODS_SMS_TICKET_BUFLEN_OUT][21];
	char    asServiceCode[ODS_SMS_TICKET_BUFLEN_OUT][31];
	char    asLangType[ODS_SMS_TICKET_BUFLEN_OUT][2];
	int     aiSvType[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asSvcEx[ODS_SMS_TICKET_BUFLEN_OUT][7];
	char    asSmType[ODS_SMS_TICKET_BUFLEN_OUT][16];
	int     aiMsgLength[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiEndReason[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiNice[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asSmgCode[ODS_SMS_TICKET_BUFLEN_OUT][9];
	int     aiUserType[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiCfee1[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiAfee1[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asServiceNumr[ODS_SMS_TICKET_BUFLEN_OUT][41];
	int     aiPartID[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiAccountID[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiSubscriptionID[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiSvcType[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asRegionID[ODS_SMS_TICKET_BUFLEN_OUT][2];
	int     aiUsageType[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiUsageCase[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiUsageClass[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiClassOfServiceCode[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiCfee[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiLfee[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiIfee[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiDisCfee[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiDisLfee[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiDisIfee[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiCfeeTimes[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiLfeeTimes[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiIfeeTimes[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiPackageID[ODS_SMS_TICKET_BUFLEN_OUT];
	int     aiProductClass[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asOriginalFile[ODS_SMS_TICKET_BUFLEN_OUT][81];
	int     aiLateLink[ODS_SMS_TICKET_BUFLEN_OUT];
	char    asCalTime[ODS_SMS_TICKET_BUFLEN_OUT][15];
	char    asAudiStr[ODS_SMS_TICKET_BUFLEN_OUT][2049];
	char    asVarianStr[ODS_SMS_TICKET_BUFLEN_OUT][256];
	char    asTimestamp[ODS_SMS_TICKET_BUFLEN_OUT][15];
	char    asDatafileDay[ODS_SMS_TICKET_BUFLEN_OUT][9];
	char    asInstorageDay[ODS_SMS_TICKET_BUFLEN_OUT][9];
};


/* 输入结构缓冲申明*/
struct OdsSmsTicketStructIn{

#ifndef ODS_SMS_TICKET_BUFLEN_IN
#define ODS_SMS_TICKET_BUFLEN_IN		300
#endif

	struct OdsSmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiServiceID[ODS_SMS_TICKET_BUFLEN_IN];
	char    asBillNumber[ODS_SMS_TICKET_BUFLEN_IN][41];
	int     aiCallType[ODS_SMS_TICKET_BUFLEN_IN];
	char    asHomeArea[ODS_SMS_TICKET_BUFLEN_IN][6];
	char    asStartTime[ODS_SMS_TICKET_BUFLEN_IN][15];
	char    asOtherParty[ODS_SMS_TICKET_BUFLEN_IN][41];
	char    asOppNumber[ODS_SMS_TICKET_BUFLEN_IN][41];
	char    asSpCode[ODS_SMS_TICKET_BUFLEN_IN][7];
	char    asSpSmg[ODS_SMS_TICKET_BUFLEN_IN][7];
	char    asAccessCode[ODS_SMS_TICKET_BUFLEN_IN][21];
	char    asServiceCode[ODS_SMS_TICKET_BUFLEN_IN][31];
	char    asLangType[ODS_SMS_TICKET_BUFLEN_IN][2];
	int     aiSvType[ODS_SMS_TICKET_BUFLEN_IN];
	char    asSvcEx[ODS_SMS_TICKET_BUFLEN_IN][7];
	char    asSmType[ODS_SMS_TICKET_BUFLEN_IN][16];
	int     aiMsgLength[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiEndReason[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiNice[ODS_SMS_TICKET_BUFLEN_IN];
	char    asSmgCode[ODS_SMS_TICKET_BUFLEN_IN][9];
	int     aiUserType[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiCfee1[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiAfee1[ODS_SMS_TICKET_BUFLEN_IN];
	char    asServiceNumr[ODS_SMS_TICKET_BUFLEN_IN][41];
	int     aiPartID[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiAccountID[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiSubscriptionID[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiSvcType[ODS_SMS_TICKET_BUFLEN_IN];
	char    asRegionID[ODS_SMS_TICKET_BUFLEN_IN][2];
	int     aiUsageType[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiUsageCase[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiUsageClass[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiClassOfServiceCode[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiCfee[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiLfee[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiIfee[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiDisCfee[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiDisLfee[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiDisIfee[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiCfeeTimes[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiLfeeTimes[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiIfeeTimes[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiPackageID[ODS_SMS_TICKET_BUFLEN_IN];
	int     aiProductClass[ODS_SMS_TICKET_BUFLEN_IN];
	char    asOriginalFile[ODS_SMS_TICKET_BUFLEN_IN][81];
	int     aiLateLink[ODS_SMS_TICKET_BUFLEN_IN];
	char    asCalTime[ODS_SMS_TICKET_BUFLEN_IN][15];
	char    asAudiStr[ODS_SMS_TICKET_BUFLEN_IN][2049];
	char    asVarianStr[ODS_SMS_TICKET_BUFLEN_IN][256];
	char    asTimestamp[ODS_SMS_TICKET_BUFLEN_IN][15];
	char    asDatafileDay[ODS_SMS_TICKET_BUFLEN_IN][9];
	char    asInstorageDay[ODS_SMS_TICKET_BUFLEN_IN][9];
};


/*单个结构申明*/
struct OdsSmsTicketStruct{

	struct OdsSmsTicketStruct *pNext;
	int     iServiceID;
	char    sBillNumber[41];
	int     iCallType;
	char    sHomeArea[6];
	char    sStartTime[15];
	char    sOtherParty[41];
	char    sOppNumber[41];
	char    sSpCode[7];
	char    sSpSmg[7];
	char    sAccessCode[21];
	char    sServiceCode[31];
	char    sLangType[2];
	int     iSvType;
	char    sSvcEx[7];
	char    sSmType[16];
	int     iMsgLength;
	int     iEndReason;
	int     iNice;
	char    sSmgCode[9];
	int     iUserType;
	int     iCfee1;
	int     iAfee1;
	char    sServiceNumr[41];
	int     iPartID;
	int     iAccountID;
	int     iSubscriptionID;
	int     iSvcType;
	char    sRegionID[2];
	int     iUsageType;
	int     iUsageCase;
	int     iUsageClass;
	int     iClassOfServiceCode;
	int     iCfee;
	int     iLfee;
	int     iIfee;
	int     iDisCfee;
	int     iDisLfee;
	int     iDisIfee;
	int     iCfeeTimes;
	int     iLfeeTimes;
	int     iIfeeTimes;
	int     iPackageID;
	int     iProductClass;
	char    sOriginalFile[81];
	int     iLateLink;
	char    sCalTime[15];
	char    sAudiStr[2049];
	char    sVarianStr[256];
	char    sTimestamp[15];
	char    sDatafileDay[9];
	char    sInstorageDay[9];
	struct OdsSmsTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FOdsSmsTicketStruct{

	char    sServiceID[2];
	char    sBillNumber[40];
	char    sCallType[2];
	char    sHomeArea[5];
	char    sStartTime[14];
	char    sOtherParty[40];
	char    sOppNumber[40];
	char    sSpCode[6];
	char    sSpSmg[6];
	char    sAccessCode[20];
	char    sServiceCode[30];
	char    sLangType[1];
	char    sSvType[4];
	char    sSvcEx[6];
	char    sSmType[15];
	char    sMsgLength[4];
	char    sEndReason[1];
	char    sNice[3];
	char    sSmgCode[8];
	char    sUserType[1];
	char    sCfee1[9];
	char    sAfee1[9];
	char    sServiceNumr[40];
	char    sPartID[2];
	char    sAccountID[9];
	char    sSubscriptionID[9];
	char    sSvcType[4];
	char    sRegionID[1];
	char    sUsageType[6];
	char    sUsageCase[6];
	char    sUsageClass[6];
	char    sClassOfServiceCode[6];
	char    sCfee[9];
	char    sLfee[9];
	char    sIfee[9];
	char    sDisCfee[9];
	char    sDisLfee[9];
	char    sDisIfee[9];
	char    sCfeeTimes[9];
	char    sLfeeTimes[9];
	char    sIfeeTimes[9];
	char    sPackageID[9];
	char    sProductClass[4];
	char    sOriginalFile[80];
	char    sLateLink[3];
	char    sCalTime[14];
	char    sAudiStr[2048];
	char    sVarianStr[255];
	char    sTimestamp[14];
	char    sDatafileDay[8];
	char    sInstorageDay[8];
};

/*输出结构缓冲申明*/
struct OdsMmsTicketStructOut{

#ifndef ODS_MMS_TICKET_BUFLEN_OUT
#define ODS_MMS_TICKET_BUFLEN_OUT		300
#endif

	struct OdsMmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiServiceID[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asBillNumber[ODS_MMS_TICKET_BUFLEN_OUT][41];
	int     aiCallType[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asHomeArea[ODS_MMS_TICKET_BUFLEN_OUT][6];
	char    asStartTime[ODS_MMS_TICKET_BUFLEN_OUT][15];
	char    asOtherParty[ODS_MMS_TICKET_BUFLEN_OUT][41];
	char    asOppNumber[ODS_MMS_TICKET_BUFLEN_OUT][41];
	char    asSpCode[ODS_MMS_TICKET_BUFLEN_OUT][10];
	char    asSpSmg[ODS_MMS_TICKET_BUFLEN_OUT][7];
	char    asAccessCode[ODS_MMS_TICKET_BUFLEN_OUT][11];
	char    asServiceCode[ODS_MMS_TICKET_BUFLEN_OUT][11];
	char    asLangType[ODS_MMS_TICKET_BUFLEN_OUT][2];
	int     aiSvType[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asSvcEx[ODS_MMS_TICKET_BUFLEN_OUT][4];
	char    asSmType[ODS_MMS_TICKET_BUFLEN_OUT][16];
	char    asMsgLength[ODS_MMS_TICKET_BUFLEN_OUT][17];
	int     aiEndReason[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiNice[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asSmgCode[ODS_MMS_TICKET_BUFLEN_OUT][5];
	int     aiUserType[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiCfee1[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiAfee1[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asServiceNumr[ODS_MMS_TICKET_BUFLEN_OUT][41];
	int     aiPartID[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiAccountID[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiSubscriptionID[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiSvcType[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asRegionID[ODS_MMS_TICKET_BUFLEN_OUT][2];
	int     aiUsageType[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiUsageCase[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiUsageClass[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiClassOfServiceCode[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiCfee[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiLfee[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiIfee[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiDisCfee[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiDisLfee[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiDisIfee[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiCfeeTimes[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiLfeeTimes[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiIfeeTimes[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiPackageID[ODS_MMS_TICKET_BUFLEN_OUT];
	int     aiProductClass[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asOriginalFile[ODS_MMS_TICKET_BUFLEN_OUT][81];
	int     aiLateLink[ODS_MMS_TICKET_BUFLEN_OUT];
	char    asCalTime[ODS_MMS_TICKET_BUFLEN_OUT][15];
	char    asAudiStr[ODS_MMS_TICKET_BUFLEN_OUT][2049];
	char    asVarianStr[ODS_MMS_TICKET_BUFLEN_OUT][81];
	char    asDatafileDay[ODS_MMS_TICKET_BUFLEN_OUT][9];
	char    asInstorageDay[ODS_MMS_TICKET_BUFLEN_OUT][9];
	char    asUsageSeq[ODS_MMS_TICKET_BUFLEN_OUT][19];
};


/* 输入结构缓冲申明*/
struct OdsMmsTicketStructIn{

#ifndef ODS_MMS_TICKET_BUFLEN_IN
#define ODS_MMS_TICKET_BUFLEN_IN		300
#endif

	struct OdsMmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiServiceID[ODS_MMS_TICKET_BUFLEN_IN];
	char    asBillNumber[ODS_MMS_TICKET_BUFLEN_IN][41];
	int     aiCallType[ODS_MMS_TICKET_BUFLEN_IN];
	char    asHomeArea[ODS_MMS_TICKET_BUFLEN_IN][6];
	char    asStartTime[ODS_MMS_TICKET_BUFLEN_IN][15];
	char    asOtherParty[ODS_MMS_TICKET_BUFLEN_IN][41];
	char    asOppNumber[ODS_MMS_TICKET_BUFLEN_IN][41];
	char    asSpCode[ODS_MMS_TICKET_BUFLEN_IN][10];
	char    asSpSmg[ODS_MMS_TICKET_BUFLEN_IN][7];
	char    asAccessCode[ODS_MMS_TICKET_BUFLEN_IN][11];
	char    asServiceCode[ODS_MMS_TICKET_BUFLEN_IN][11];
	char    asLangType[ODS_MMS_TICKET_BUFLEN_IN][2];
	int     aiSvType[ODS_MMS_TICKET_BUFLEN_IN];
	char    asSvcEx[ODS_MMS_TICKET_BUFLEN_IN][4];
	char    asSmType[ODS_MMS_TICKET_BUFLEN_IN][16];
	char    asMsgLength[ODS_MMS_TICKET_BUFLEN_IN][17];
	int     aiEndReason[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiNice[ODS_MMS_TICKET_BUFLEN_IN];
	char    asSmgCode[ODS_MMS_TICKET_BUFLEN_IN][5];
	int     aiUserType[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiCfee1[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiAfee1[ODS_MMS_TICKET_BUFLEN_IN];
	char    asServiceNumr[ODS_MMS_TICKET_BUFLEN_IN][41];
	int     aiPartID[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiAccountID[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiSubscriptionID[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiSvcType[ODS_MMS_TICKET_BUFLEN_IN];
	char    asRegionID[ODS_MMS_TICKET_BUFLEN_IN][2];
	int     aiUsageType[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiUsageCase[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiUsageClass[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiClassOfServiceCode[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiCfee[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiLfee[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiIfee[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiDisCfee[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiDisLfee[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiDisIfee[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiCfeeTimes[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiLfeeTimes[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiIfeeTimes[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiPackageID[ODS_MMS_TICKET_BUFLEN_IN];
	int     aiProductClass[ODS_MMS_TICKET_BUFLEN_IN];
	char    asOriginalFile[ODS_MMS_TICKET_BUFLEN_IN][81];
	int     aiLateLink[ODS_MMS_TICKET_BUFLEN_IN];
	char    asCalTime[ODS_MMS_TICKET_BUFLEN_IN][15];
	char    asAudiStr[ODS_MMS_TICKET_BUFLEN_IN][2049];
	char    asVarianStr[ODS_MMS_TICKET_BUFLEN_IN][81];
	char    asDatafileDay[ODS_MMS_TICKET_BUFLEN_IN][9];
	char    asInstorageDay[ODS_MMS_TICKET_BUFLEN_IN][9];
	char    asUsageSeq[ODS_MMS_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct OdsMmsTicketStruct{

	struct OdsMmsTicketStruct *pNext;
	int     iServiceID;
	char    sBillNumber[41];
	int     iCallType;
	char    sHomeArea[6];
	char    sStartTime[15];
	char    sOtherParty[41];
	char    sOppNumber[41];
	char    sSpCode[10];
	char    sSpSmg[7];
	char    sAccessCode[11];
	char    sServiceCode[11];
	char    sLangType[2];
	int     iSvType;
	char    sSvcEx[4];
	char    sSmType[16];
	char    sMsgLength[17];
	int     iEndReason;
	int     iNice;
	char    sSmgCode[5];
	int     iUserType;
	int     iCfee1;
	int     iAfee1;
	char    sServiceNumr[41];
	int     iPartID;
	int     iAccountID;
	int     iSubscriptionID;
	int     iSvcType;
	char    sRegionID[2];
	int     iUsageType;
	int     iUsageCase;
	int     iUsageClass;
	int     iClassOfServiceCode;
	int     iCfee;
	int     iLfee;
	int     iIfee;
	int     iDisCfee;
	int     iDisLfee;
	int     iDisIfee;
	int     iCfeeTimes;
	int     iLfeeTimes;
	int     iIfeeTimes;
	int     iPackageID;
	int     iProductClass;
	char    sOriginalFile[81];
	int     iLateLink;
	char    sCalTime[15];
	char    sAudiStr[2049];
	char    sVarianStr[81];
	char    sDatafileDay[9];
	char    sInstorageDay[9];
	char    sUsageSeq[19];
	struct OdsMmsTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FOdsMmsTicketStruct{

	char    sServiceID[2];
	char    sBillNumber[40];
	char    sCallType[2];
	char    sHomeArea[5];
	char    sStartTime[14];
	char    sOtherParty[40];
	char    sOppNumber[40];
	char    sSpCode[9];
	char    sSpSmg[6];
	char    sAccessCode[10];
	char    sServiceCode[10];
	char    sLangType[1];
	char    sSvType[4];
	char    sSvcEx[3];
	char    sSmType[15];
	char    sMsgLength[16];
	char    sEndReason[1];
	char    sNice[3];
	char    sSmgCode[4];
	char    sUserType[1];
	char    sCfee1[9];
	char    sAfee1[9];
	char    sServiceNumr[40];
	char    sPartID[2];
	char    sAccountID[9];
	char    sSubscriptionID[9];
	char    sSvcType[4];
	char    sRegionID[1];
	char    sUsageType[6];
	char    sUsageCase[6];
	char    sUsageClass[6];
	char    sClassOfServiceCode[6];
	char    sCfee[9];
	char    sLfee[9];
	char    sIfee[9];
	char    sDisCfee[9];
	char    sDisLfee[9];
	char    sDisIfee[9];
	char    sCfeeTimes[9];
	char    sLfeeTimes[9];
	char    sIfeeTimes[9];
	char    sPackageID[9];
	char    sProductClass[9];
	char    sOriginalFile[80];
	char    sLateLink[3];
	char    sCalTime[14];
	char    sAudiStr[2048];
	char    sVarianStr[80];
	char    sDatafileDay[8];
	char    sInstorageDay[8];
	char    sUsageSeq[18];
};

/*输出结构缓冲申明*/
struct LocSttTicketStructOut{

#ifndef LOC_STT_TICKET_BUFLEN_OUT
#define LOC_STT_TICKET_BUFLEN_OUT		300
#endif

	struct LocSttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiTicketTypeID[LOC_STT_TICKET_BUFLEN_OUT];
	char    asCallType[LOC_STT_TICKET_BUFLEN_OUT][3];
	char    asMsisdn[LOC_STT_TICKET_BUFLEN_OUT][16];
	char    asCalledCode[LOC_STT_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[LOC_STT_TICKET_BUFLEN_OUT][25];
	char    asVisitAreaCode[LOC_STT_TICKET_BUFLEN_OUT][6];
	int     aiRoamFee[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiTollFee[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiAddFee[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiDuration[LOC_STT_TICKET_BUFLEN_OUT];
	char    asStartTime[LOC_STT_TICKET_BUFLEN_OUT][15];
	char    asHomeAreaCode[LOC_STT_TICKET_BUFLEN_OUT][6];
	char    asRoamType[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asDistanceType[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asOppType[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asUserType[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asSplitRuleID[LOC_STT_TICKET_BUFLEN_OUT][5];
	char    asOppRoamType[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asServiceType[LOC_STT_TICKET_BUFLEN_OUT][4];
	char    asServiceCode[LOC_STT_TICKET_BUFLEN_OUT][5];
	char    asImsi[LOC_STT_TICKET_BUFLEN_OUT][16];
	char    asMsc[LOC_STT_TICKET_BUFLEN_OUT][16];
	char    asLac[LOC_STT_TICKET_BUFLEN_OUT][6];
	char    asCellID[LOC_STT_TICKET_BUFLEN_OUT][6];
	char    asOtherLac[LOC_STT_TICKET_BUFLEN_OUT][6];
	char    asOtherCellID[LOC_STT_TICKET_BUFLEN_OUT][6];
	char    asTrunkIn[LOC_STT_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[LOC_STT_TICKET_BUFLEN_OUT][8];
	char    asThirdParty[LOC_STT_TICKET_BUFLEN_OUT][16];
	char    asMsrn[LOC_STT_TICKET_BUFLEN_OUT][13];
	int     aiTrunkInTypeID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutTypeID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiTrunkInCarrierID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutCarrierID[LOC_STT_TICKET_BUFLEN_OUT];
	char    asTrunkInType[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asTrunkOutType[LOC_STT_TICKET_BUFLEN_OUT][2];
	int     aiCallingCarrierID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiCalledCarrierID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiCallingTypeID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiCalledTypeID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiCallingAreaID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiCalledAreaID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiASettAreaID[LOC_STT_TICKET_BUFLEN_OUT];
	int     aiBSettAreaID[LOC_STT_TICKET_BUFLEN_OUT];
	char    asSplitType[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asCal[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asEsn[LOC_STT_TICKET_BUFLEN_OUT][16];
	char    asScpFlag[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asReserve[LOC_STT_TICKET_BUFLEN_OUT][9];
	char    asBillMode[LOC_STT_TICKET_BUFLEN_OUT][4];
	char    asReserve1[LOC_STT_TICKET_BUFLEN_OUT][3];
	char    asRoamTariffType[LOC_STT_TICKET_BUFLEN_OUT][4];
	char    asTollTariffType[LOC_STT_TICKET_BUFLEN_OUT][4];
	char    asAddTariffType[LOC_STT_TICKET_BUFLEN_OUT][4];
	char    asErrCode[LOC_STT_TICKET_BUFLEN_OUT][5];
	char    asFileName[LOC_STT_TICKET_BUFLEN_OUT][20];
	char    asModule[LOC_STT_TICKET_BUFLEN_OUT][4];
	char    asAreaCode[LOC_STT_TICKET_BUFLEN_OUT][6];
	char    asState[LOC_STT_TICKET_BUFLEN_OUT][2];
	char    asUpdateDate[LOC_STT_TICKET_BUFLEN_OUT][15];
	char    asDealDate[LOC_STT_TICKET_BUFLEN_OUT][15];
	char    asSourceID[LOC_STT_TICKET_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct LocSttTicketStructIn{

#ifndef LOC_STT_TICKET_BUFLEN_IN
#define LOC_STT_TICKET_BUFLEN_IN		300
#endif

	struct LocSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiTicketTypeID[LOC_STT_TICKET_BUFLEN_IN];
	char    asCallType[LOC_STT_TICKET_BUFLEN_IN][3];
	char    asMsisdn[LOC_STT_TICKET_BUFLEN_IN][16];
	char    asCalledCode[LOC_STT_TICKET_BUFLEN_IN][6];
	char    asOtherParty[LOC_STT_TICKET_BUFLEN_IN][25];
	char    asVisitAreaCode[LOC_STT_TICKET_BUFLEN_IN][6];
	int     aiRoamFee[LOC_STT_TICKET_BUFLEN_IN];
	int     aiTollFee[LOC_STT_TICKET_BUFLEN_IN];
	int     aiAddFee[LOC_STT_TICKET_BUFLEN_IN];
	int     aiDuration[LOC_STT_TICKET_BUFLEN_IN];
	char    asStartTime[LOC_STT_TICKET_BUFLEN_IN][15];
	char    asHomeAreaCode[LOC_STT_TICKET_BUFLEN_IN][6];
	char    asRoamType[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asDistanceType[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asOppType[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asUserType[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asSplitRuleID[LOC_STT_TICKET_BUFLEN_IN][5];
	char    asOppRoamType[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asServiceType[LOC_STT_TICKET_BUFLEN_IN][4];
	char    asServiceCode[LOC_STT_TICKET_BUFLEN_IN][5];
	char    asImsi[LOC_STT_TICKET_BUFLEN_IN][16];
	char    asMsc[LOC_STT_TICKET_BUFLEN_IN][16];
	char    asLac[LOC_STT_TICKET_BUFLEN_IN][6];
	char    asCellID[LOC_STT_TICKET_BUFLEN_IN][6];
	char    asOtherLac[LOC_STT_TICKET_BUFLEN_IN][6];
	char    asOtherCellID[LOC_STT_TICKET_BUFLEN_IN][6];
	char    asTrunkIn[LOC_STT_TICKET_BUFLEN_IN][8];
	char    asTrunkOut[LOC_STT_TICKET_BUFLEN_IN][8];
	char    asThirdParty[LOC_STT_TICKET_BUFLEN_IN][16];
	char    asMsrn[LOC_STT_TICKET_BUFLEN_IN][13];
	int     aiTrunkInTypeID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiTrunkOutTypeID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiTrunkInCarrierID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiTrunkOutCarrierID[LOC_STT_TICKET_BUFLEN_IN];
	char    asTrunkInType[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asTrunkOutType[LOC_STT_TICKET_BUFLEN_IN][2];
	int     aiCallingCarrierID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiCalledCarrierID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiCallingTypeID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiCalledTypeID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiCallingAreaID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiCalledAreaID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiASettAreaID[LOC_STT_TICKET_BUFLEN_IN];
	int     aiBSettAreaID[LOC_STT_TICKET_BUFLEN_IN];
	char    asSplitType[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asCal[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asEsn[LOC_STT_TICKET_BUFLEN_IN][16];
	char    asScpFlag[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asReserve[LOC_STT_TICKET_BUFLEN_IN][9];
	char    asBillMode[LOC_STT_TICKET_BUFLEN_IN][4];
	char    asReserve1[LOC_STT_TICKET_BUFLEN_IN][3];
	char    asRoamTariffType[LOC_STT_TICKET_BUFLEN_IN][4];
	char    asTollTariffType[LOC_STT_TICKET_BUFLEN_IN][4];
	char    asAddTariffType[LOC_STT_TICKET_BUFLEN_IN][4];
	char    asErrCode[LOC_STT_TICKET_BUFLEN_IN][5];
	char    asFileName[LOC_STT_TICKET_BUFLEN_IN][20];
	char    asModule[LOC_STT_TICKET_BUFLEN_IN][4];
	char    asAreaCode[LOC_STT_TICKET_BUFLEN_IN][6];
	char    asState[LOC_STT_TICKET_BUFLEN_IN][2];
	char    asUpdateDate[LOC_STT_TICKET_BUFLEN_IN][15];
	char    asDealDate[LOC_STT_TICKET_BUFLEN_IN][15];
	char    asSourceID[LOC_STT_TICKET_BUFLEN_IN][41];
};


/*单个结构申明*/
struct LocSttTicketStruct{

	struct LocSttTicketStruct *pNext;
	int     iTicketTypeID;
	char    sCallType[3];
	char    sMsisdn[16];
	char    sCalledCode[6];
	char    sOtherParty[25];
	char    sVisitAreaCode[6];
	int     iRoamFee;
	int     iTollFee;
	int     iAddFee;
	int     iDuration;
	char    sStartTime[15];
	char    sHomeAreaCode[6];
	char    sRoamType[2];
	char    sDistanceType[2];
	char    sOppType[2];
	char    sUserType[2];
	char    sSplitRuleID[5];
	char    sOppRoamType[2];
	char    sServiceType[4];
	char    sServiceCode[5];
	char    sImsi[16];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sOtherLac[6];
	char    sOtherCellID[6];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sThirdParty[16];
	char    sMsrn[13];
	int     iTrunkInTypeID;
	int     iTrunkOutTypeID;
	int     iTrunkInCarrierID;
	int     iTrunkOutCarrierID;
	char    sTrunkInType[2];
	char    sTrunkOutType[2];
	int     iCallingCarrierID;
	int     iCalledCarrierID;
	int     iCallingTypeID;
	int     iCalledTypeID;
	int     iCallingAreaID;
	int     iCalledAreaID;
	int     iASettAreaID;
	int     iBSettAreaID;
	char    sSplitType[2];
	char    sCal[2];
	char    sEsn[16];
	char    sScpFlag[2];
	char    sDeformFlag[2];
	char    sReserve[9];
	char    sBillMode[4];
	char    sReserve1[3];
	char    sRoamTariffType[4];
	char    sTollTariffType[4];
	char    sAddTariffType[4];
	char    sErrCode[5];
	char    sFileName[20];
	char    sModule[4];
	char    sAreaCode[6];
	char    sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct LocSttTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FLocSttTicketStruct{

	char    sTicketTypeID[4];
	char    sCallType[2];
	char    sMsisdn[15];
	char    sCalledCode[5];
	char    sOtherParty[24];
	char    sVisitAreaCode[5];
	char    sRoamFee[5];
	char    sTollFee[7];
	char    sAddFee[5];
	char    sDuration[6];
	char    sStartTime[14];
	char    sHomeAreaCode[5];
	char    sRoamType[1];
	char    sDistanceType[1];
	char    sOppType[1];
	char    sUserType[1];
	char    sSplitRuleID[4];
	char    sOppRoamType[1];
	char    sServiceType[3];
	char    sServiceCode[4];
	char    sImsi[15];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sOtherLac[5];
	char    sOtherCellID[5];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sThirdParty[15];
	char    sMsrn[12];
	char    sTrunkInTypeID[4];
	char    sTrunkOutTypeID[4];
	char    sTrunkInCarrierID[4];
	char    sTrunkOutCarrierID[4];
	char    sTrunkInType[1];
	char    sTrunkOutType[1];
	char    sCallingCarrierID[4];
	char    sCalledCarrierID[4];
	char    sCallingTypeID[4];
	char    sCalledTypeID[4];
	char    sCallingAreaID[4];
	char    sCalledAreaID[4];
	char    sASettAreaID[4];
	char    sBSettAreaID[4];
	char    sSplitType[1];
	char    sCal[1];
	char    sEsn[15];
	char    sScpFlag[1];
	char    sDeformFlag[1];
	char    sReserve[8];
	char    sBillMode[3];
	char    sReserve1[2];
	char    sRoamTariffType[3];
	char    sTollTariffType[3];
	char    sAddTariffType[3];
	char    sErrCode[4];
	char    sFileName[19];
	char    sModule[3];
	char    sAreaCode[5];
	char    sState[1];
	char    sUpdateDate[14];
	char    sDealDate[14];
	char    sSourceID[40];
};


/*批量数据动态从T_YD_UE_CM中用结构缓冲方式取数据*/
int EGetAccSttTicketToStruct(struct AccSttTicketStruct *p,
	struct AccSttTicketStructIn *pSource);

/*批量数据动态从ST_SMS_TICKET中用结构缓冲方式取数据*/
int EGetAccSmsTicketToStruct(struct AccSmsTicketStruct *p,
	struct AccSmsTicketStructIn *pSource);

/*批量数据动态从ST_MMS_TICKET中用结构缓冲方式取数据*/
int EGetAccMmsTicketToStruct(struct AccMmsTicketStruct *p,
	struct AccMmsTicketStructIn *pSource);

/*批量数据动态从ST_ODS_DR_G中用结构缓冲方式取数据*/
int EGetOdsSttTicketToStruct(struct OdsSttTicketStruct *p,
	struct OdsSttTicketStructIn *pSource);

/*批量数据动态从ST_ODS_SM_G_201410中用结构缓冲方式取数据*/
int EGetOdsSmsTicketToStruct(struct OdsSmsTicketStruct *p,
	struct OdsSmsTicketStructIn *pSource);
	
/*批量数据动态从ODS_MMS_TICKET中用结构缓冲方式取数据*/
int EGetOdsMmsTicketToStruct(struct OdsMmsTicketStruct *p,
	struct OdsMmsTicketStructIn *pSource);

/*批量数据动态从LOC_STT_TICKET中用结构缓冲方式取数据*/
int EGetLocSttTicketToStruct(struct LocSttTicketStruct *p,
	struct LocSttTicketStructIn *pSource);
		
void CreateTable(char tablename[]);


/*输出结构缓冲申明*/
struct StAreaMscTimeOffsetStructOut{

#ifndef ST_AREA_MSC_TIME_OFFSET_BUFLEN_OUT
#define ST_AREA_MSC_TIME_OFFSET_BUFLEN_OUT		300
#endif

	struct StAreaMscTimeOffsetStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 地市 */
	char    asAreaCode[ST_AREA_MSC_TIME_OFFSET_BUFLEN_OUT][10];
		/* 交换机 */
	char    asMsc[ST_AREA_MSC_TIME_OFFSET_BUFLEN_OUT][15];
		/* 时间偏移量 */
	int     aiOffset[ST_AREA_MSC_TIME_OFFSET_BUFLEN_OUT];
	char	asHomeAreaCode[ST_AREA_MSC_TIME_OFFSET_BUFLEN_OUT][10];
};


/* 输入结构缓冲申明*/
struct StAreaMscTimeOffsetStructIn{

#ifndef ST_AREA_MSC_TIME_OFFSET_BUFLEN_IN
#define ST_AREA_MSC_TIME_OFFSET_BUFLEN_IN		300
#endif

	struct StAreaMscTimeOffsetStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 地市 */
	char    asAreaCode[ST_AREA_MSC_TIME_OFFSET_BUFLEN_IN][10];
		/* 交换机 */
	char    asMsc[ST_AREA_MSC_TIME_OFFSET_BUFLEN_IN][15];
		/* 时间偏移量 */
	int     aiOffset[ST_AREA_MSC_TIME_OFFSET_BUFLEN_IN];
	char	asHomeAreaCode[ST_AREA_MSC_TIME_OFFSET_BUFLEN_IN][10];
};


/*单个结构申明*/
struct StAreaMscTimeOffsetStruct{

	struct StAreaMscTimeOffsetStruct *pNext;
	char    sAreaCode[10];		/* 地市 */
	char    sMsc[15];		/* 交换机 */
	int     iOffset;		/* 时间偏移量 */
	char	sHomeAreaCode[10];
	struct StAreaMscTimeOffsetStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FStAreaMscTimeOffsetStruct{

	char    sAreaCode[9];		/* 地市 */
	char    sMsc[14];		/* 交换机 */
	char    sOffset[8];		/* 时间偏移量 */
	char	sHomeAreaCode[9];
};



/*批量数据动态从ST_AREA_MSC_TIME_OFFSET中用结构缓冲方式取数据*/
int EGetStAreaMscTimeOffsetToStruct(struct StAreaMscTimeOffsetStruct *p,
	struct StAreaMscTimeOffsetStructIn *pSource);
void mvitem_stareamsctimeoffset(struct StAreaMscTimeOffsetStruct *pi,struct StAreaMscTimeOffsetStruct *po);
void mvitem_fmstareamsctimeoffset(struct FStAreaMscTimeOffsetStruct *pi,struct StAreaMscTimeOffsetStruct *po);
void mvitem_mfstareamsctimeoffset(struct StAreaMscTimeOffsetStruct *pi,struct FStAreaMscTimeOffsetStruct *po);
/**对表ST_AREA_MSC_TIME_OFFSET的链表释放函数**/
void DestroyStAreaMscTimeOffset(struct StAreaMscTimeOffsetStruct *ptHead);
int InitStAreaMscTimeOffset(struct StAreaMscTimeOffsetStruct **pptHead);
/*批量数据结构缓冲写入ST_AREA_MSC_TIME_OFFSET*/
int EInsertStructToStAreaMscTimeOffset(struct StAreaMscTimeOffsetStruct *p,
	int iInsertFlag,struct StAreaMscTimeOffsetStructOut *pTarget);

#endif

