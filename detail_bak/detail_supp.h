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
	char    asUsageEventID[ACC_STT_TICKET_BUFLEN_OUT][19];
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
	char    asUsageEventID[ACC_STT_TICKET_BUFLEN_IN][19];
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
	char    sUsageEventID[19];
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

	char    sUsageEventID[18];
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
	char    asUsageEventID[ACC_MMS_TICKET_BUFLEN_OUT][19];
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
	char    asUsageEventID[ACC_MMS_TICKET_BUFLEN_IN][19];
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
	char    sUsageEventID[19];
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
	char    sUsageEventID[18];
	char    sCallingCityCode[32];
	char    sCalledCityCode[32];
	char    sFileName[64];
	char    sGroupID[2];
	char    sCallType[2];
};




/*输出表结构*/
struct TargetTableStruct{
	char    sUsageEventID[19];
	char    sSourceID[7];
	char    sHomeAreaCode[7];
	char    sMsisdn[31];
	char    sSettCity[7];
	char    sOppAreaCode[7];
	char    sOtherParty[31];
	char    sCallType[3];
	char    sStartTime[14];
	char    sEndTime[14];
	char    sDuration[9];
	char    sAuditType[3];
};

/*输出结构缓冲申明*/
struct TargetTableStructOut{

#ifndef T_BUFLEN_OUT
#define T_BUFLEN_OUT		300
#endif

	struct TargetTableStructOut *pNext;

	int 	iCurPos;
	int 	iRecordCnt;
	char 	sTableName[31];
	
	char    asUsageEventID[T_BUFLEN_OUT][19];
	char    asSourceID[T_BUFLEN_OUT][7];
	char    asHomeAreaCode[T_BUFLEN_OUT][7];
	char    asMsisdn[T_BUFLEN_OUT][31];
	char    asSettCity[T_BUFLEN_OUT][7];
	char    asOppAreaCode[T_BUFLEN_OUT][7];
	char    asOtherParty[T_BUFLEN_OUT][31];
	char    asCallType[T_BUFLEN_OUT][3];
	char    asStartTime[T_BUFLEN_OUT][14];
	char    asEndTime[T_BUFLEN_OUT][14];
	char    asDuration[T_BUFLEN_OUT][9];
	char    asAuditType[T_BUFLEN_OUT][3];
	
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
	char	sGroupId[3];
	char    sThirdParty[31];
	char	sRowID[19];
	
	char	sSplitFlag[2];
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
	char	sGroupId[3];

};

/*批量数据结构缓冲写入ST_PREP_TICKET*/
int EGetStPrepTicketToStruct(struct StPrepTicketStruct *p,
	struct StPrepTicketStructIn *pSource);
/*批量数据结构缓冲写入ST_STT_PREP_TICKET*/
int EInsertStructToStPrepTicket(struct StPrepTicketStruct *p,
	int iInsertFlag,struct StPrepTicketStructOut *pTarget);
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


void CreateTable(char tablename[]);

#endif

