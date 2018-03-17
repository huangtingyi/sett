#ifndef __DAYLY_STAT_SUPP_H__
#define __DAYLY_STAT_SUPP_H__

int CheckDaylyStatLog(char sServiceType[],char sDataDate[]);
int SetDaylyStatLog(char sServiceType[],char sDataDate[],char sState[]);


/*输出结构缓冲申明*/
struct DaylySttHourStatStructOut{

#ifndef DAYLY_STT_HOUR_STAT_BUFLEN_OUT
#define DAYLY_STT_HOUR_STAT_BUFLEN_OUT		300
#endif

	struct DaylySttHourStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 去话单,02来话 */
	char    asCallType[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][3];
		/* 结算地 */
	char    asVisitAreaCode[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* 交换机 */
	char    asMsc[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* 入中继 */
	char    asTrunkIn[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* 入中继类型 */
	int     aiTrunkInTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 入中继运营商 */
	int     aiTrunkInCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 1 本地,2省内,3省际,X其他 */
	char    asTrunkOut[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* 出中继类型 */
	int     aiTrunkOutTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 出中继运营商 */
	int     aiTrunkOutCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 统计小时 */
	char    asStartHour[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][11];
		/* 总时长 */
	int     aiTotalSec[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 结算收入 */
	int     aiIncome[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutcome[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 结算分钟数 */
	int     aiTotalMin[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 统计日期 */
	char    asSettItemDate[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][15];
		/* 帐务周期 */
	char    asBillingCycleID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][7];
};



/*UP结构缓冲申明*/
struct DaylySttHourStatStructUp{

#ifndef DAYLY_STT_HOUR_STAT_BUFLEN_UP
#define DAYLY_STT_HOUR_STAT_BUFLEN_UP		300
#endif

	struct DaylySttHourStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 去话单,02来话 */
	char    asCallType[DAYLY_STT_HOUR_STAT_BUFLEN_UP][3];
		/* 结算地 */
	char    asVisitAreaCode[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* 交换机 */
	char    asMsc[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* 入中继 */
	char    asTrunkIn[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* 入中继类型 */
	int     aiTrunkInTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 入中继运营商 */
	int     aiTrunkInCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 1 本地,2省内,3省际,X其他 */
	char    asTrunkOut[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* 出中继类型 */
	int     aiTrunkOutTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 出中继运营商 */
	int     aiTrunkOutCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 统计小时 */
	char    asStartHour[DAYLY_STT_HOUR_STAT_BUFLEN_UP][11];
		/* 总时长 */
	int     aiTotalSec[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 结算收入 */
	int     aiIncome[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 结算支出 */
	int     aiOutcome[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 结算分钟数 */
	int     aiTotalMin[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 统计日期 */
	char    asSettItemDate[DAYLY_STT_HOUR_STAT_BUFLEN_UP][15];
		/* 帐务周期 */
	char    asBillingCycleID[DAYLY_STT_HOUR_STAT_BUFLEN_UP][7];
	char    asRowID[DAYLY_STT_HOUR_STAT_BUFLEN_UP][19];
};

/* 输入结构缓冲申明*/
struct DaylySttHourStatStructIn{

#ifndef DAYLY_STT_HOUR_STAT_BUFLEN_IN
#define DAYLY_STT_HOUR_STAT_BUFLEN_IN		300
#endif

	struct DaylySttHourStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 01 去话单,02来话 */
	char    asCallType[DAYLY_STT_HOUR_STAT_BUFLEN_IN][3];
		/* 结算地 */
	char    asVisitAreaCode[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* 交换机 */
	char    asMsc[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* 入中继 */
	char    asTrunkIn[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* 入中继类型 */
	int     aiTrunkInTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 入中继运营商 */
	int     aiTrunkInCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 1 本地,2省内,3省际,X其他 */
	char    asTrunkOut[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* 出中继类型 */
	int     aiTrunkOutTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 出中继运营商 */
	int     aiTrunkOutCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 统计小时 */
	char    asStartHour[DAYLY_STT_HOUR_STAT_BUFLEN_IN][11];
		/* 总时长 */
	int     aiTotalSec[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 结算收入 */
	int     aiIncome[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutcome[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 结算分钟数 */
	int     aiTotalMin[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 统计日期 */
	char    asSettItemDate[DAYLY_STT_HOUR_STAT_BUFLEN_IN][15];
		/* 帐务周期 */
	char    asBillingCycleID[DAYLY_STT_HOUR_STAT_BUFLEN_IN][7];
	char    asRowID[DAYLY_STT_HOUR_STAT_BUFLEN_IN][19];
};


/*单个结构申明*/
struct DaylySttHourStatStruct{

	struct DaylySttHourStatStruct *pNext;
	char    sCallType[3];		/* 01 去话单,02来话 */
	char    sVisitAreaCode[10];		/* 结算地 */
	char    sMsc[10];		/* 交换机 */
	char    sTrunkIn[10];		/* 入中继 */
	int     iTrunkInTypeID;		/* 入中继类型 */
	int     iTrunkInCarrID;		/* 入中继运营商 */
	char    sTrunkOut[10];		/* 1 本地,2省内,3省际,X其他 */
	int     iTrunkOutTypeID;		/* 出中继类型 */
	int     iTrunkOutCarrID;		/* 出中继运营商 */
	char    sStartHour[11];		/* 统计小时 */
	int     iTotalSec;		/* 总时长 */
	int     iIncome;		/* 结算收入 */
	int     iOutcome;		/* 结算支出 */
	int     iTotalMin;		/* 结算分钟数 */
	char    sSettItemDate[15];		/* 统计日期 */
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sRowID[19];             /* 记录索引 */
	struct DaylySttHourStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FDaylySttHourStatStruct{

	char    sCallType[2];		/* 01 去话单,02来话 */
	char    sVisitAreaCode[9];		/* 结算地 */
	char    sMsc[9];		/* 交换机 */
	char    sTrunkIn[9];		/* 入中继 */
	char    sTrunkInTypeID[4];		/* 入中继类型 */
	char    sTrunkInCarrID[4];		/* 入中继运营商 */
	char    sTrunkOut[9];		/* 1 本地,2省内,3省际,X其他 */
	char    sTrunkOutTypeID[4];		/* 出中继类型 */
	char    sTrunkOutCarrID[4];		/* 出中继运营商 */
	char    sStartHour[10];		/* 统计小时 */
	char    sTotalSec[9];		/* 总时长 */
	char    sIncome[9];		/* 结算收入 */
	char    sOutcome[9];		/* 结算支出 */
	char    sTotalMin[9];		/* 结算分钟数 */
	char    sSettItemDate[14];		/* 统计日期 */
	char    sBillingCycleID[6];		/* 帐务周期 */
};

int data_search_bintree_stt_hour_e(void *pValue,void*pData);
void assign_insert_bintree_stt_hour_e(void **ppData,void *pData);

/*批量数据动态从DAYLY_STT_HOUR_STAT中用结构缓冲方式取数据*/
int EGetDaylySttHourStatToStruct(struct DaylySttHourStatStruct *p,
	struct DaylySttHourStatStructIn *pSource);
/*批量数据结构缓冲写入DAYLY_STT_HOUR_STAT*/
int EInsertStructToDaylySttHourStat(struct DaylySttHourStatStruct *p,
	int iInsertFlag,struct DaylySttHourStatStructOut *pTarget);
/*批量数据结构缓冲更新DAYLY_STT_HOUR_STAT*/
int EUpdateStructToDaylySttHourStat(struct DaylySttHourStatStruct *p,
	int iUpdateFlag,struct DaylySttHourStatStructUp *pTarget);


/*输出结构缓冲申明*/
struct DaylySttStatStructOut{

#ifndef DAYLY_STT_STAT_BUFLEN_OUT
#define DAYLY_STT_STAT_BUFLEN_OUT		300
#endif

	struct DaylySttStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 去话单,02来话 */
	char    asCallType[DAYLY_STT_STAT_BUFLEN_OUT][3];
		/* 结算地 */
	char    asVisitAreaCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* 用户归属 */
	char    asHomeAreaCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* 用户省会区号 */
	char    asHomeCapitalCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* 对端归属 */
	char    asCalledCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* 对端省会区号 */
	char    asCalledCapitalCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* 结算类型 */
	int     aiTicketTypeID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 对端运营商 */
	int     aiOppCarrID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 网络类型 */
	char    asNetType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* 1 本地,2省内,3省际,X其他 */
	char    asMsisdnUserType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* 我方号码类型 */
	char    asMsisdnNbrType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* 我方移动号头 */
	char    asMsisdnHead[DAYLY_STT_STAT_BUFLEN_OUT][8];
		/* 我方归属县市 */
	int     aiMsisdnAreaID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 我方套餐类型 */
	char    asMsisdnBillingTypeID[DAYLY_STT_STAT_BUFLEN_OUT][11];
		/* 我方运营商 */
	int     aiMsisdnCarrierID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 对方用户类型 */
	char    asOppUserType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* 对方号码类型 */
	char    asOppNbrType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* 对方移动号头 */
	char    asOppHead[DAYLY_STT_STAT_BUFLEN_OUT][8];
		/* 对方县市 */
	int     aiOppAreaID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 对方运营商 */
	int     aiOppCarrierID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 结算收入 */
	int     aiIncome[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutcome[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 结算分钟数 */
	int     aiTotalMin[DAYLY_STT_STAT_BUFLEN_OUT];
		/* 统计日期 */
	char    asSettItemDate[DAYLY_STT_STAT_BUFLEN_OUT][15];
		/* 帐务周期 */
	char    asBillingCycleID[DAYLY_STT_STAT_BUFLEN_OUT][7];
};


/*更新结构缓冲申明*/
struct DaylySttStatStructUp{

#ifndef DAYLY_STT_STAT_BUFLEN_UP
#define DAYLY_STT_STAT_BUFLEN_UP		300
#endif

	struct DaylySttStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 去话单,02来话 */
	char    asCallType[DAYLY_STT_STAT_BUFLEN_UP][3];
		/* 结算地 */
	char    asVisitAreaCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* 用户归属 */
	char    asHomeAreaCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* 用户省会区号 */
	char    asHomeCapitalCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* 对端归属 */
	char    asCalledCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* 对端省会区号 */
	char    asCalledCapitalCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* 结算类型 */
	int     aiTicketTypeID[DAYLY_STT_STAT_BUFLEN_UP];
		/* 对端运营商 */
	int     aiOppCarrID[DAYLY_STT_STAT_BUFLEN_UP];
		/* 网络类型 */
	char    asNetType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* 1 本地,2省内,3省际,X其他 */
	char    asMsisdnUserType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* 我方号码类型 */
	char    asMsisdnNbrType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* 我方移动号头 */
	char    asMsisdnHead[DAYLY_STT_STAT_BUFLEN_UP][8];
		/* 我方归属县市 */
	int     aiMsisdnAreaID[DAYLY_STT_STAT_BUFLEN_UP];
		/* 我方套餐类型 */
	char    asMsisdnBillingTypeID[DAYLY_STT_STAT_BUFLEN_UP][11];
		/* 我方运营商 */
	int     aiMsisdnCarrierID[DAYLY_STT_STAT_BUFLEN_UP];
		/* 对方用户类型 */
	char    asOppUserType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* 对方号码类型 */
	char    asOppNbrType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* 对方移动号头 */
	char    asOppHead[DAYLY_STT_STAT_BUFLEN_UP][8];
		/* 对方县市 */
	int     aiOppAreaID[DAYLY_STT_STAT_BUFLEN_UP];
		/* 对方运营商 */
	int     aiOppCarrierID[DAYLY_STT_STAT_BUFLEN_UP];
		/* 结算收入 */
	int     aiIncome[DAYLY_STT_STAT_BUFLEN_UP];
		/* 结算支出 */
	int     aiOutcome[DAYLY_STT_STAT_BUFLEN_UP];
		/* 结算分钟数 */
	int     aiTotalMin[DAYLY_STT_STAT_BUFLEN_UP];
		/* 统计日期 */
	char    asSettItemDate[DAYLY_STT_STAT_BUFLEN_UP][15];
		/* 帐务周期 */
	char    asBillingCycleID[DAYLY_STT_STAT_BUFLEN_UP][7];
	char    asRowID[DAYLY_STT_STAT_BUFLEN_UP][19];
};


/* 输入结构缓冲申明*/
struct DaylySttStatStructIn{

#ifndef DAYLY_STT_STAT_BUFLEN_IN
#define DAYLY_STT_STAT_BUFLEN_IN		300
#endif

	struct DaylySttStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 01 去话单,02来话 */
	char    asCallType[DAYLY_STT_STAT_BUFLEN_IN][3];
		/* 结算地 */
	char    asVisitAreaCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* 用户归属 */
	char    asHomeAreaCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* 用户省会区号 */
	char    asHomeCapitalCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* 对端归属 */
	char    asCalledCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* 对端省会区号 */
	char    asCalledCapitalCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* 结算类型 */
	int     aiTicketTypeID[DAYLY_STT_STAT_BUFLEN_IN];
		/* 对端运营商 */
	int     aiOppCarrID[DAYLY_STT_STAT_BUFLEN_IN];
		/* 网络类型 */
	char    asNetType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* 1 本地,2省内,3省际,X其他 */
	char    asMsisdnUserType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* 我方号码类型 */
	char    asMsisdnNbrType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* 我方移动号头 */
	char    asMsisdnHead[DAYLY_STT_STAT_BUFLEN_IN][8];
		/* 我方归属县市 */
	int     aiMsisdnAreaID[DAYLY_STT_STAT_BUFLEN_IN];
		/* 我方套餐类型 */
	char    asMsisdnBillingTypeID[DAYLY_STT_STAT_BUFLEN_IN][11];
		/* 我方运营商 */
	int     aiMsisdnCarrierID[DAYLY_STT_STAT_BUFLEN_IN];
		/* 对方用户类型 */
	char    asOppUserType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* 对方号码类型 */
	char    asOppNbrType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* 对方移动号头 */
	char    asOppHead[DAYLY_STT_STAT_BUFLEN_IN][8];
		/* 对方县市 */
	int     aiOppAreaID[DAYLY_STT_STAT_BUFLEN_IN];
		/* 对方运营商 */
	int     aiOppCarrierID[DAYLY_STT_STAT_BUFLEN_IN];
		/* 结算收入 */
	int     aiIncome[DAYLY_STT_STAT_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutcome[DAYLY_STT_STAT_BUFLEN_IN];
		/* 结算分钟数 */
	int     aiTotalMin[DAYLY_STT_STAT_BUFLEN_IN];
		/* 统计日期 */
	char    asSettItemDate[DAYLY_STT_STAT_BUFLEN_IN][15];
		/* 帐务周期 */
	char    asBillingCycleID[DAYLY_STT_STAT_BUFLEN_IN][7];
	char    asRowID[DAYLY_STT_STAT_BUFLEN_IN][19];
};


/*单个结构申明*/
struct DaylySttStatStruct{

	struct DaylySttStatStruct *pNext;
	char    sCallType[3];		/* 01 去话单,02来话 */
	char    sVisitAreaCode[10];		/* 结算地 */
	char    sHomeAreaCode[10];		/* 用户归属 */
	char    sHomeCapitalCode[10];		/* 用户省会区号 */
	char    sCalledCode[10];		/* 对端归属 */
	char    sCalledCapitalCode[10];		/* 对端省会区号 */
	int     iTicketTypeID;		/* 结算类型 */
	int     iOppCarrID;		/* 对端运营商 */
	char    sNetType[2];		/* 网络类型 */
	char    sMsisdnUserType[2];		/* 1 本地,2省内,3省际,X其他 */
	char    sMsisdnNbrType[2];		/* 我方号码类型 */
	char    sMsisdnHead[8];		/* 我方移动号头 */
	int     iMsisdnAreaID;		/* 我方归属县市 */
	char    sMsisdnBillingTypeID[11];		/* 我方套餐类型 */
	int     iMsisdnCarrierID;		/* 我方运营商 */
	char    sOppUserType[2];		/* 对方用户类型 */
	char    sOppNbrType[2];		/* 对方号码类型 */
	char    sOppHead[8];		/* 对方移动号头 */
	int     iOppAreaID;		/* 对方县市 */
	int     iOppCarrierID;		/* 对方运营商 */
	int     iIncome;		/* 结算收入 */
	int     iOutcome;		/* 结算支出 */
	int     iTotalMin;		/* 结算分钟数 */
	char    sSettItemDate[15];		/* 统计日期 */
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sRowID[19];             /* 记录索引 */
	struct DaylySttStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FDaylySttStatStruct{

	char    sCallType[2];		/* 01 去话单,02来话 */
	char    sVisitAreaCode[9];		/* 结算地 */
	char    sHomeAreaCode[9];		/* 用户归属 */
	char    sHomeCapitalCode[9];		/* 用户省会区号 */
	char    sCalledCode[9];		/* 对端归属 */
	char    sCalledCapitalCode[9];		/* 对端省会区号 */
	char    sTicketTypeID[4];		/* 结算类型 */
	char    sOppCarrID[4];		/* 对端运营商 */
	char    sNetType[1];		/* 网络类型 */
	char    sMsisdnUserType[1];		/* 1 本地,2省内,3省际,X其他 */
	char    sMsisdnNbrType[1];		/* 我方号码类型 */
	char    sMsisdnHead[7];		/* 我方移动号头 */
	char    sMsisdnAreaID[4];		/* 我方归属县市 */
	char    sMsisdnBillingTypeID[10];		/* 我方套餐类型 */
	char    sMsisdnCarrierID[4];		/* 我方运营商 */
	char    sOppUserType[1];		/* 对方用户类型 */
	char    sOppNbrType[1];		/* 对方号码类型 */
	char    sOppHead[7];		/* 对方移动号头 */
	char    sOppAreaID[4];		/* 对方县市 */
	char    sOppCarrierID[4];		/* 对方运营商 */
	char    sIncome[9];		/* 结算收入 */
	char    sOutcome[9];		/* 结算支出 */
	char    sTotalMin[9];		/* 结算分钟数 */
	char    sSettItemDate[14];		/* 统计日期 */
	char    sBillingCycleID[6];		/* 帐务周期 */
};


int data_search_bintree_dayly_stt_stat_e(void *pValue,void*pData);
void assign_insert_bintree_dayly_stt_stat_e(void **ppData,void *pData);



/*批量数据动态从DAYLY_STT_STAT中用结构缓冲方式取数据*/
int EGetDaylySttStatToStruct(struct DaylySttStatStruct *p,
	struct DaylySttStatStructIn *pSource);
/*批量数据结构缓冲写入DAYLY_STT_STAT*/
int EInsertStructToDaylySttStat(struct DaylySttStatStruct *p,
	int iInsertFlag,struct DaylySttStatStructOut *pTarget);
/*批量数据结构缓冲更新DAYLY_STT_STAT*/
int EUpdateStructToDaylySttStat(struct DaylySttStatStruct *p,
	int iUpdateFlag,struct DaylySttStatStructUp *pTarget);



/*输出结构缓冲申明*/
struct SrtStatStructOut{

#ifndef SRT_STAT_BUFLEN_OUT
#define SRT_STAT_BUFLEN_OUT		300
#endif

	struct SrtStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 去话单,02来话 */
	char    asCallType[SRT_STAT_BUFLEN_OUT][3];
		/* 结算地 */
	char    asAreaCode[SRT_STAT_BUFLEN_OUT][10];
		/* 对端结算地 */
	char    asOppAreaCode[SRT_STAT_BUFLEN_OUT][10];
		/* 对端结算省会区号 */
	char    asOppCapitalCode[SRT_STAT_BUFLEN_OUT][10];
		/* 对端号码归属地 */
	char    asCalledCode[SRT_STAT_BUFLEN_OUT][10];
		/* 对端号码归属省会区号 */
	char    asCalledCapitalCode[SRT_STAT_BUFLEN_OUT][10];
		/* 结算类型 */
	int     aiTicketTypeID[SRT_STAT_BUFLEN_OUT];
		/* 对端运营商 */
	int     aiOppCarrID[SRT_STAT_BUFLEN_OUT];
		/* 网络类型 */
	char    asNetType[SRT_STAT_BUFLEN_OUT][2];
		/* 1 本地,2省内,3省际,X其他 */
	char    asMsisdnUserType[SRT_STAT_BUFLEN_OUT][2];
		/* 用户号码类型 */
	char    asMsisdnNbrType[SRT_STAT_BUFLEN_OUT][2];
		/* 用户移动号头 */
	char    asMsisdnHead[SRT_STAT_BUFLEN_OUT][8];
		/* 用户归属县市 */
	int     aiMsisdnAreaID[SRT_STAT_BUFLEN_OUT];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[SRT_STAT_BUFLEN_OUT][11];
		/* 对端用户类型 */
	char    asOppUserType[SRT_STAT_BUFLEN_OUT][2];
		/* 对端号码类型 */
	char    asOppNbrType[SRT_STAT_BUFLEN_OUT][2];
		/* 对端号头 */
	char    asOppHead[SRT_STAT_BUFLEN_OUT][8];
		/* 对端县市 */
	int     aiOppAreaID[SRT_STAT_BUFLEN_OUT];
		/* 对端套餐类型 */
	char    asOppBillingTypeID[SRT_STAT_BUFLEN_OUT][11];
		/* 漫游费 */
	int     aiRoamFee[SRT_STAT_BUFLEN_OUT];
		/* 长途费 */
	int     aiTollFee[SRT_STAT_BUFLEN_OUT];
		/* 结算收入 */
	int     aiIncome[SRT_STAT_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutcome[SRT_STAT_BUFLEN_OUT];
		/* 结算分钟数 */
	int     aiTotalMin[SRT_STAT_BUFLEN_OUT];
		/* 统计日期 */
	char    asSettItemDate[SRT_STAT_BUFLEN_OUT][15];
		/* 帐务周期 */
	char    asBillingCycleID[SRT_STAT_BUFLEN_OUT][7];
};


/*更新结构缓冲申明*/
struct SrtStatStructUp{

#ifndef SRT_STAT_BUFLEN_UP
#define SRT_STAT_BUFLEN_UP		300
#endif

	struct SrtStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 去话单,02来话 */
	char    asCallType[SRT_STAT_BUFLEN_UP][3];
		/* 结算地 */
	char    asAreaCode[SRT_STAT_BUFLEN_UP][10];
		/* 对端结算地 */
	char    asOppAreaCode[SRT_STAT_BUFLEN_UP][10];
		/* 对端结算省会区号 */
	char    asOppCapitalCode[SRT_STAT_BUFLEN_UP][10];
		/* 对端号码归属地 */
	char    asCalledCode[SRT_STAT_BUFLEN_UP][10];
		/* 对端号码归属省会区号 */
	char    asCalledCapitalCode[SRT_STAT_BUFLEN_UP][10];
		/* 结算类型 */
	int     aiTicketTypeID[SRT_STAT_BUFLEN_UP];
		/* 对端运营商 */
	int     aiOppCarrID[SRT_STAT_BUFLEN_UP];
		/* 网络类型 */
	char    asNetType[SRT_STAT_BUFLEN_UP][2];
		/* 1 本地,2省内,3省际,X其他 */
	char    asMsisdnUserType[SRT_STAT_BUFLEN_UP][2];
		/* 用户号码类型 */
	char    asMsisdnNbrType[SRT_STAT_BUFLEN_UP][2];
		/* 用户移动号头 */
	char    asMsisdnHead[SRT_STAT_BUFLEN_UP][8];
		/* 用户归属县市 */
	int     aiMsisdnAreaID[SRT_STAT_BUFLEN_UP];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[SRT_STAT_BUFLEN_UP][11];
		/* 对端用户类型 */
	char    asOppUserType[SRT_STAT_BUFLEN_UP][2];
		/* 对端号码类型 */
	char    asOppNbrType[SRT_STAT_BUFLEN_UP][2];
		/* 对端号头 */
	char    asOppHead[SRT_STAT_BUFLEN_UP][8];
		/* 对端县市 */
	int     aiOppAreaID[SRT_STAT_BUFLEN_UP];
		/* 对端套餐类型 */
	char    asOppBillingTypeID[SRT_STAT_BUFLEN_UP][11];
		/* 漫游费 */
	int     aiRoamFee[SRT_STAT_BUFLEN_UP];
		/* 长途费 */
	int     aiTollFee[SRT_STAT_BUFLEN_UP];
		/* 结算收入 */
	int     aiIncome[SRT_STAT_BUFLEN_UP];
		/* 结算支出 */
	int     aiOutcome[SRT_STAT_BUFLEN_UP];
		/* 结算分钟数 */
	int     aiTotalMin[SRT_STAT_BUFLEN_UP];
		/* 统计日期 */
	char    asSettItemDate[SRT_STAT_BUFLEN_UP][15];
		/* 帐务周期 */
	char    asBillingCycleID[SRT_STAT_BUFLEN_UP][7];
	char    asRowID[SRT_STAT_BUFLEN_UP][19];
};

/* 输入结构缓冲申明*/
struct SrtStatStructIn{

#ifndef SRT_STAT_BUFLEN_IN
#define SRT_STAT_BUFLEN_IN		300
#endif

	struct SrtStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 01 去话单,02来话 */
	char    asCallType[SRT_STAT_BUFLEN_IN][3];
		/* 结算地 */
	char    asAreaCode[SRT_STAT_BUFLEN_IN][10];
		/* 对端结算地 */
	char    asOppAreaCode[SRT_STAT_BUFLEN_IN][10];
		/* 对端结算省会区号 */
	char    asOppCapitalCode[SRT_STAT_BUFLEN_IN][10];
		/* 对端号码归属地 */
	char    asCalledCode[SRT_STAT_BUFLEN_IN][10];
		/* 对端号码归属省会区号 */
	char    asCalledCapitalCode[SRT_STAT_BUFLEN_IN][10];
		/* 结算类型 */
	int     aiTicketTypeID[SRT_STAT_BUFLEN_IN];
		/* 对端运营商 */
	int     aiOppCarrID[SRT_STAT_BUFLEN_IN];
		/* 网络类型 */
	char    asNetType[SRT_STAT_BUFLEN_IN][2];
		/* 1 本地,2省内,3省际,X其他 */
	char    asMsisdnUserType[SRT_STAT_BUFLEN_IN][2];
		/* 用户号码类型 */
	char    asMsisdnNbrType[SRT_STAT_BUFLEN_IN][2];
		/* 用户移动号头 */
	char    asMsisdnHead[SRT_STAT_BUFLEN_IN][8];
		/* 用户归属县市 */
	int     aiMsisdnAreaID[SRT_STAT_BUFLEN_IN];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[SRT_STAT_BUFLEN_IN][11];
		/* 对端用户类型 */
	char    asOppUserType[SRT_STAT_BUFLEN_IN][2];
		/* 对端号码类型 */
	char    asOppNbrType[SRT_STAT_BUFLEN_IN][2];
		/* 对端号头 */
	char    asOppHead[SRT_STAT_BUFLEN_IN][8];
		/* 对端县市 */
	int     aiOppAreaID[SRT_STAT_BUFLEN_IN];
		/* 对端套餐类型 */
	char    asOppBillingTypeID[SRT_STAT_BUFLEN_IN][11];
		/* 漫游费 */
	int     aiRoamFee[SRT_STAT_BUFLEN_IN];
		/* 长途费 */
	int     aiTollFee[SRT_STAT_BUFLEN_IN];
		/* 结算收入 */
	int     aiIncome[SRT_STAT_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutcome[SRT_STAT_BUFLEN_IN];
		/* 结算分钟数 */
	int     aiTotalMin[SRT_STAT_BUFLEN_IN];
		/* 统计日期 */
	char    asSettItemDate[SRT_STAT_BUFLEN_IN][15];
		/* 帐务周期 */
	char    asBillingCycleID[SRT_STAT_BUFLEN_IN][7];
	char    asRowID[SRT_STAT_BUFLEN_IN][19];
};


/*单个结构申明*/
struct SrtStatStruct{

	struct SrtStatStruct *pNext;
	char    sCallType[3];		/* 01 去话单,02来话 */
	char    sAreaCode[10];		/* 结算地 */
	char    sOppAreaCode[10];		/* 对端结算地 */
	char    sOppCapitalCode[10];		/* 对端结算省会区号 */
	char    sCalledCode[10];		/* 对端号码归属地 */
	char    sCalledCapitalCode[10];		/* 对端号码归属省会区号 */
	int     iTicketTypeID;		/* 结算类型 */
	int     iOppCarrID;		/* 对端运营商 */
	char    sNetType[2];		/* 网络类型 */
	char    sMsisdnUserType[2];		/* 1 本地,2省内,3省际,X其他 */
	char    sMsisdnNbrType[2];		/* 用户号码类型 */
	char    sMsisdnHead[8];		/* 用户移动号头 */
	int     iMsisdnAreaID;		/* 用户归属县市 */
	char    sMsisdnBillingTypeID[11];		/* 用户套餐类型 */
	char    sOppUserType[2];		/* 对端用户类型 */
	char    sOppNbrType[2];		/* 对端号码类型 */
	char    sOppHead[8];		/* 对端号头 */
	int     iOppAreaID;		/* 对端县市 */
	char    sOppBillingTypeID[11];		/* 对端套餐类型 */
	int     iRoamFee;		/* 漫游费 */
	int     iTollFee;		/* 长途费 */
	int     iIncome;		/* 结算收入 */
	int     iOutcome;		/* 结算支出 */
	int     iTotalMin;		/* 结算分钟数 */
	char    sSettItemDate[15];		/* 统计日期 */
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sRowID[19];             /* 记录索引 */
	struct SrtStatStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FSrtStatStruct{

	char    sCallType[2];		/* 01 去话单,02来话 */
	char    sAreaCode[9];		/* 结算地 */
	char    sOppAreaCode[9];		/* 对端结算地 */
	char    sOppCapitalCode[9];		/* 对端结算省会区号 */
	char    sCalledCode[9];		/* 对端号码归属地 */
	char    sCalledCapitalCode[9];		/* 对端号码归属省会区号 */
	char    sTicketTypeID[4];		/* 结算类型 */
	char    sOppCarrID[4];		/* 对端运营商 */
	char    sNetType[1];		/* 网络类型 */
	char    sMsisdnUserType[1];		/* 1 本地,2省内,3省际,X其他 */
	char    sMsisdnNbrType[1];		/* 用户号码类型 */
	char    sMsisdnHead[7];		/* 用户移动号头 */
	char    sMsisdnAreaID[4];		/* 用户归属县市 */
	char    sMsisdnBillingTypeID[10];		/* 用户套餐类型 */
	char    sOppUserType[1];		/* 对端用户类型 */
	char    sOppNbrType[1];		/* 对端号码类型 */
	char    sOppHead[7];		/* 对端号头 */
	char    sOppAreaID[4];		/* 对端县市 */
	char    sOppBillingTypeID[10];		/* 对端套餐类型 */
	char    sRoamFee[9];		/* 漫游费 */
	char    sTollFee[9];		/* 长途费 */
	char    sIncome[9];		/* 结算收入 */
	char    sOutcome[9];		/* 结算支出 */
	char    sTotalMin[9];		/* 结算分钟数 */
	char    sSettItemDate[14];		/* 统计日期 */
	char    sBillingCycleID[6];		/* 帐务周期 */
};



int data_search_bintree_srt_stat_e(void *pValue,void*pData);
void assign_insert_bintree_srt_stat_e(void **ppData,void *pData);

/*批量数据动态从SRT_STAT中用结构缓冲方式取数据*/
int EGetSrtStatToStruct(struct SrtStatStruct *p,
	struct SrtStatStructIn *pSource);
/*批量数据结构缓冲写入SRT_STAT*/
int EInsertStructToSrtStat(struct SrtStatStruct *p,
	int iInsertFlag,struct SrtStatStructOut *pTarget);
/*批量数据结构缓冲更新SRT_STAT*/
int EUpdateStructToSrtStat(struct SrtStatStruct *p,
	int iUpdateFlag,struct SrtStatStructUp *pTarget);


/*输出结构缓冲申明*/
struct SpcpStatStructOut{

#ifndef SPCP_STAT_BUFLEN_OUT
#define SPCP_STAT_BUFLEN_OUT		300
#endif

	struct SpcpStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算地 */
	char    asAreaCode[SPCP_STAT_BUFLEN_OUT][10];
		/* SP代码 */
	char    asSpCode[SPCP_STAT_BUFLEN_OUT][11];
		/* SP业务代码 */
	char    asSpServiceCode[SPCP_STAT_BUFLEN_OUT][11];
		/* SP号码 */
	char    asSpAccNbr[SPCP_STAT_BUFLEN_OUT][13];
		/* 结算类型 */
	int     aiTicketTypeID[SPCP_STAT_BUFLEN_OUT];
		/* 网络类型 */
	char    asNetType[SPCP_STAT_BUFLEN_OUT][2];
		/* 用户号头 */
	char    asMsisdnHead[SPCP_STAT_BUFLEN_OUT][8];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[SPCP_STAT_BUFLEN_OUT][11];
		/* 月租费 */
	int     aiRentFee[SPCP_STAT_BUFLEN_OUT];
		/* 信息费 */
	int     aiInfoFee[SPCP_STAT_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutcome[SPCP_STAT_BUFLEN_OUT];
		/* 帐务周期 */
	char    asBillingCycleID[SPCP_STAT_BUFLEN_OUT][7];
};

/*更新结构缓冲申明*/
struct SpcpStatStructUp{

#ifndef SPCP_STAT_BUFLEN_UP
#define SPCP_STAT_BUFLEN_UP		300
#endif

	struct SpcpStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算地 */
	char    asAreaCode[SPCP_STAT_BUFLEN_UP][10];
		/* SP代码 */
	char    asSpCode[SPCP_STAT_BUFLEN_UP][11];
		/* SP业务代码 */
	char    asSpServiceCode[SPCP_STAT_BUFLEN_UP][11];
		/* SP号码 */
	char    asSpAccNbr[SPCP_STAT_BUFLEN_UP][13];
		/* 结算类型 */
	int     aiTicketTypeID[SPCP_STAT_BUFLEN_UP];
		/* 网络类型 */
	char    asNetType[SPCP_STAT_BUFLEN_UP][2];
		/* 用户号头 */
	char    asMsisdnHead[SPCP_STAT_BUFLEN_UP][8];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[SPCP_STAT_BUFLEN_UP][11];
		/* 月租费 */
	int     aiRentFee[SPCP_STAT_BUFLEN_UP];
		/* 信息费 */
	int     aiInfoFee[SPCP_STAT_BUFLEN_UP];
		/* 结算支出 */
	int     aiOutcome[SPCP_STAT_BUFLEN_UP];
		/* 帐务周期 */
	char    asBillingCycleID[SPCP_STAT_BUFLEN_UP][7];
	char    asRowID[SPCP_STAT_BUFLEN_UP][19];
};


/* 输入结构缓冲申明*/
struct SpcpStatStructIn{

#ifndef SPCP_STAT_BUFLEN_IN
#define SPCP_STAT_BUFLEN_IN		300
#endif

	struct SpcpStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 结算地 */
	char    asAreaCode[SPCP_STAT_BUFLEN_IN][10];
		/* SP代码 */
	char    asSpCode[SPCP_STAT_BUFLEN_IN][11];
		/* SP业务代码 */
	char    asSpServiceCode[SPCP_STAT_BUFLEN_IN][11];
		/* SP号码 */
	char    asSpAccNbr[SPCP_STAT_BUFLEN_IN][13];
		/* 结算类型 */
	int     aiTicketTypeID[SPCP_STAT_BUFLEN_IN];
		/* 网络类型 */
	char    asNetType[SPCP_STAT_BUFLEN_IN][2];
		/* 用户号头 */
	char    asMsisdnHead[SPCP_STAT_BUFLEN_IN][8];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[SPCP_STAT_BUFLEN_IN][11];
		/* 月租费 */
	int     aiRentFee[SPCP_STAT_BUFLEN_IN];
		/* 信息费 */
	int     aiInfoFee[SPCP_STAT_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutcome[SPCP_STAT_BUFLEN_IN];
		/* 帐务周期 */
	char    asBillingCycleID[SPCP_STAT_BUFLEN_IN][7];
	char    asRowID[SPCP_STAT_BUFLEN_IN][19];
};


/*单个结构申明*/
struct SpcpStatStruct{

	struct SpcpStatStruct *pNext;
	char    sAreaCode[10];		/* 结算地 */
	char    sSpCode[11];		/* SP代码 */
	char    sSpServiceCode[11];		/* SP业务代码 */
	char    sSpAccNbr[13];		/* SP号码 */
	int     iTicketTypeID;		/* 结算类型 */
	char    sNetType[2];		/* 网络类型 */
	char    sMsisdnHead[8];		/* 用户号头 */
	char    sMsisdnBillingTypeID[11];		/* 用户套餐类型 */
	int     iRentFee;		/* 月租费 */
	int     iInfoFee;		/* 信息费 */
	int     iOutcome;		/* 结算支出 */
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sRowID[19];             /* 记录索引 */
	struct SpcpStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSpcpStatStruct{

	char    sAreaCode[9];		/* 结算地 */
	char    sSpCode[10];		/* SP代码 */
	char    sSpServiceCode[10];		/* SP业务代码 */
	char    sSpAccNbr[12];		/* SP号码 */
	char    sTicketTypeID[4];		/* 结算类型 */
	char    sNetType[1];		/* 网络类型 */
	char    sMsisdnHead[7];		/* 用户号头 */
	char    sMsisdnBillingTypeID[10];		/* 用户套餐类型 */
	char    sRentFee[9];		/* 月租费 */
	char    sInfoFee[9];		/* 信息费 */
	char    sOutcome[9];		/* 结算支出 */
	char    sBillingCycleID[6];		/* 帐务周期 */
};


int data_search_bintree_spcp_stat_e(void *pValue,void*pData);
void assign_insert_bintree_spcp_stat_e(void **ppData,void *pData);

/*批量数据动态从SPCP_STAT中用结构缓冲方式取数据*/
int EGetSpcpStatToStruct(struct SpcpStatStruct *p,
	struct SpcpStatStructIn *pSource);
/*批量数据结构缓冲写入SPCP_STAT*/
int EInsertStructToSpcpStat(struct SpcpStatStruct *p,
	int iInsertFlag,struct SpcpStatStructOut *pTarget);
/*批量数据结构缓冲更新SPCP_STAT*/
int EUpdateStructToSpcpStat(struct SpcpStatStruct *p,
	int iUpdateFlag,struct SpcpStatStructUp *pTarget);

/*输出结构缓冲申明*/
struct Gprs1xStatStructOut{

#ifndef GPRS_1X_STAT_BUFLEN_OUT
#define GPRS_1X_STAT_BUFLEN_OUT		300
#endif

	struct Gprs1xStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算地 */
	char    asAreaCode[GPRS_1X_STAT_BUFLEN_OUT][10];
		/* 对端结算地 */
	char    asOppAreaCode[GPRS_1X_STAT_BUFLEN_OUT][10];
		/* 结算类型 */
	int     aiTicketTypeID[GPRS_1X_STAT_BUFLEN_OUT];
		/* 网络类型 */
	char    asNetType[GPRS_1X_STAT_BUFLEN_OUT][2];
		/* 用户移动号头 */
	char    asMsisdnHead[GPRS_1X_STAT_BUFLEN_OUT][8];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[GPRS_1X_STAT_BUFLEN_OUT][11];
		/* 流量费 */
	int     aiFlowFee[GPRS_1X_STAT_BUFLEN_OUT];
		/* 结算收入 */
	int     aiIncome[GPRS_1X_STAT_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutcome[GPRS_1X_STAT_BUFLEN_OUT];
		/* 数据流量 */
	LONGINT aiDataFlow[GPRS_1X_STAT_BUFLEN_OUT];
		/* 统计日期 */
	char    asSettItemDate[GPRS_1X_STAT_BUFLEN_OUT][15];
		/* 帐务周期 */
	char    asBillingCycleID[GPRS_1X_STAT_BUFLEN_OUT][7];
};


/*更新结构缓冲申明*/
struct Gprs1xStatStructUp{

#ifndef GPRS_1X_STAT_BUFLEN_UP
#define GPRS_1X_STAT_BUFLEN_UP		300
#endif

	struct Gprs1xStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算地 */
	char    asAreaCode[GPRS_1X_STAT_BUFLEN_UP][10];
		/* 对端结算地 */
	char    asOppAreaCode[GPRS_1X_STAT_BUFLEN_UP][10];
		/* 结算类型 */
	int     aiTicketTypeID[GPRS_1X_STAT_BUFLEN_UP];
		/* 网络类型 */
	char    asNetType[GPRS_1X_STAT_BUFLEN_UP][2];
		/* 用户移动号头 */
	char    asMsisdnHead[GPRS_1X_STAT_BUFLEN_UP][8];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[GPRS_1X_STAT_BUFLEN_UP][11];
		/* 流量费 */
	int     aiFlowFee[GPRS_1X_STAT_BUFLEN_UP];
		/* 结算收入 */
	int     aiIncome[GPRS_1X_STAT_BUFLEN_UP];
		/* 结算支出 */
	int     aiOutcome[GPRS_1X_STAT_BUFLEN_UP];
		/* 数据流量 */
	LONGINT aiDataFlow[GPRS_1X_STAT_BUFLEN_UP];
		/* 统计日期 */
	char    asSettItemDate[GPRS_1X_STAT_BUFLEN_UP][15];
		/* 帐务周期 */
	char    asBillingCycleID[GPRS_1X_STAT_BUFLEN_UP][7];	
	char    asRowID[GPRS_1X_STAT_BUFLEN_UP][19];
};


/* 输入结构缓冲申明*/
struct Gprs1xStatStructIn{

#ifndef GPRS_1X_STAT_BUFLEN_IN
#define GPRS_1X_STAT_BUFLEN_IN		300
#endif

	struct Gprs1xStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 结算地 */
	char    asAreaCode[GPRS_1X_STAT_BUFLEN_IN][10];
		/* 对端结算地 */
	char    asOppAreaCode[GPRS_1X_STAT_BUFLEN_IN][10];
		/* 结算类型 */
	int     aiTicketTypeID[GPRS_1X_STAT_BUFLEN_IN];
		/* 网络类型 */
	char    asNetType[GPRS_1X_STAT_BUFLEN_IN][2];
		/* 用户移动号头 */
	char    asMsisdnHead[GPRS_1X_STAT_BUFLEN_IN][8];
		/* 用户套餐类型 */
	char    asMsisdnBillingTypeID[GPRS_1X_STAT_BUFLEN_IN][11];
		/* 流量费 */
	int     aiFlowFee[GPRS_1X_STAT_BUFLEN_IN];
		/* 结算收入 */
	int     aiIncome[GPRS_1X_STAT_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutcome[GPRS_1X_STAT_BUFLEN_IN];
		/* 数据流量 */
	LONGINT aiDataFlow[GPRS_1X_STAT_BUFLEN_IN];
		/* 统计日期 */
	char    asSettItemDate[GPRS_1X_STAT_BUFLEN_IN][15];
		/* 帐务周期 */
	char    asBillingCycleID[GPRS_1X_STAT_BUFLEN_IN][7];
	char    asRowID[GPRS_1X_STAT_BUFLEN_IN][19];
};


/*单个结构申明*/
struct Gprs1xStatStruct{

	struct Gprs1xStatStruct *pNext;
	char    sAreaCode[10];		/* 结算地 */
	char    sOppAreaCode[10];		/* 对端结算地 */
	int     iTicketTypeID;		/* 结算类型 */
	char    sNetType[2];		/* 网络类型 */
	char    sMsisdnHead[8];		/* 用户移动号头 */
	char    sMsisdnBillingTypeID[11];		/* 用户套餐类型 */
	int     iFlowFee;		/* 流量费 */
	int     iIncome;		/* 结算收入 */
	int     iOutcome;		/* 结算支出 */
	LONGINT iDataFlow;		/* 数据流量 */
	char    sSettItemDate[15];		/* 统计日期 */
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sRowID[19];             /* 记录索引 */
	struct Gprs1xStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FGprs1xStatStruct{

	char    sAreaCode[9];		/* 结算地 */
	char    sOppAreaCode[9];		/* 对端结算地 */
	char    sTicketTypeID[4];		/* 结算类型 */
	char    sNetType[1];		/* 网络类型 */
	char    sMsisdnHead[7];		/* 用户移动号头 */
	char    sMsisdnBillingTypeID[10];		/* 用户套餐类型 */
	char    sFlowFee[9];		/* 流量费 */
	char    sIncome[9];		/* 结算收入 */
	char    sOutcome[9];		/* 结算支出 */
	char    sDataFlow[12];		/* 数据流量 */
	char    sSettItemDate[14];		/* 统计日期 */
	char    sBillingCycleID[6];		/* 帐务周期 */
};


int data_search_bintree_gprs1x_stat_e(void *pValue,void*pData);
void assign_insert_bintree_gprs1x_stat_e(void **ppData,void *pData);

/*批量数据动态从GPRS_1X_STAT中用结构缓冲方式取数据*/
int EGetGprs1xStatToStruct(struct Gprs1xStatStruct *p,
	struct Gprs1xStatStructIn *pSource);
/*批量数据结构缓冲写入GPRS_1X_STAT*/
int EInsertStructToGprs1xStat(struct Gprs1xStatStruct *p,
	int iInsertFlag,struct Gprs1xStatStructOut *pTarget);
/*批量数据结构缓冲更新GPRS_1X_STAT*/
int EUpdateStructToGprs1xStat(struct Gprs1xStatStruct *p,
	int iUpdateFlag,struct Gprs1xStatStructUp *pTarget);

#endif
