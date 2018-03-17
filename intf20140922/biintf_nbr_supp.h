#ifndef __BIINTF_NBR_SUPP_H__
#define __BIINTF_NBR_SUPP_H__


/*输出结构缓冲申明*/
struct SettNbrIntfFjbiStructOut{

#ifndef SETT_NBR_INTF_FJBI_BUFLEN_OUT
#define SETT_NBR_INTF_FJBI_BUFLEN_OUT		300
#endif

	struct SettNbrIntfFjbiStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算账期 */
	char    asBillingCycleID[SETT_NBR_INTF_FJBI_BUFLEN_OUT][7];
		/* 结算地区号 */
	char    asVisitAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* 结算号码 */
	char    asAccNbr[SETT_NBR_INTF_FJBI_BUFLEN_OUT][25];
		/* 主叫号码归属地 */
	char    asHomeAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* 被叫号码归属地 */
	char    asOppAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* 漫游通话地 */
	char    asRoamAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* 主叫号码运营商 */
	int     aiHomeCarrID[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 被叫号码运营商 */
	int     aiOppCarrID[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 呼叫方向编码 */
	int     aiCallDirection[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 结算类型 */
	int     aiTicketTypeID[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 话单数 */
	int     aiCnt[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 通话时长 */
	int     aiDuration[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 结算时长 */
	int     aiFeeDuration[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 结算收入 */
	int     aiInFee[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutFee[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceType[SETT_NBR_INTF_FJBI_BUFLEN_OUT][4];
		/* 本端用户网络类型 */
	char    asNbrType[SETT_NBR_INTF_FJBI_BUFLEN_OUT][5];
		/* 对方用户网络类型 */
	char    asOppNbrType[SETT_NBR_INTF_FJBI_BUFLEN_OUT][5];
		/* 结算收支标识 */
	int     aiSettFlag[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* 保留维度1 */
	char    asReserve1[SETT_NBR_INTF_FJBI_BUFLEN_OUT][11];
		/* 保留维度2 */
	char    asReserve2[SETT_NBR_INTF_FJBI_BUFLEN_OUT][11];
		/* 处理时间 */
	char    asDealDate[SETT_NBR_INTF_FJBI_BUFLEN_OUT][15];
};


/* 输入结构缓冲申明*/
struct SettNbrIntfFjbiStructIn{

#ifndef SETT_NBR_INTF_FJBI_BUFLEN_IN
#define SETT_NBR_INTF_FJBI_BUFLEN_IN		300
#endif

	struct SettNbrIntfFjbiStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 结算账期 */
	char    asBillingCycleID[SETT_NBR_INTF_FJBI_BUFLEN_IN][7];
		/* 结算地区号 */
	char    asVisitAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* 结算号码 */
	char    asAccNbr[SETT_NBR_INTF_FJBI_BUFLEN_IN][25];
		/* 主叫号码归属地 */
	char    asHomeAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* 被叫号码归属地 */
	char    asOppAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* 漫游通话地 */
	char    asRoamAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* 主叫号码运营商 */
	int     aiHomeCarrID[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 被叫号码运营商 */
	int     aiOppCarrID[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 呼叫方向编码 */
	int     aiCallDirection[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 结算类型 */
	int     aiTicketTypeID[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 话单数 */
	int     aiCnt[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 通话时长 */
	int     aiDuration[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 结算时长 */
	int     aiFeeDuration[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 结算收入 */
	int     aiInFee[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutFee[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceType[SETT_NBR_INTF_FJBI_BUFLEN_IN][4];
		/* 本端用户网络类型 */
	char    asNbrType[SETT_NBR_INTF_FJBI_BUFLEN_IN][5];
		/* 对方用户网络类型 */
	char    asOppNbrType[SETT_NBR_INTF_FJBI_BUFLEN_IN][5];
		/* 结算收支标识 */
	int     aiSettFlag[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* 保留维度1 */
	char    asReserve1[SETT_NBR_INTF_FJBI_BUFLEN_IN][11];
		/* 保留维度2 */
	char    asReserve2[SETT_NBR_INTF_FJBI_BUFLEN_IN][11];
		/* 处理时间 */
	char    asDealDate[SETT_NBR_INTF_FJBI_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SettNbrIntfFjbiStruct{

	struct SettNbrIntfFjbiStruct *pNext;
	char    sBillingCycleID[7];		/* 结算账期 */
	char    sVisitAreaCode[6];		/* 结算地区号 */
	char    sAccNbr[25];		/* 结算号码 */
	char    sHomeAreaCode[6];		/* 主叫号码归属地 */
	char    sOppAreaCode[6];		/* 被叫号码归属地 */
	char    sRoamAreaCode[6];		/* 漫游通话地 */
	int     iHomeCarrID;		/* 主叫号码运营商 */
	int     iOppCarrID;		/* 被叫号码运营商 */
	int     iCallDirection;		/* 呼叫方向编码 */
	int     iTicketTypeID;		/* 结算类型 */
	int     iCnt;		/* 话单数 */
	int     iDuration;		/* 通话时长 */
	int     iFeeDuration;		/* 结算时长 */
	int     iInFee;		/* 结算收入 */
	int     iOutFee;		/* 结算支出 */
	char    sServiceType[4];		/* 业务类型 */
	char    sNbrType[5];		/* 本端用户网络类型 */
	char    sOppNbrType[5];		/* 对方用户网络类型 */
	int     iSettFlag;		/* 结算收支标识 */
	char    sReserve1[11];		/* 保留维度1 */
	char    sReserve2[11];		/* 保留维度2 */
	char    sDealDate[15];		/* 处理时间 */
	struct SettNbrIntfFjbiStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettNbrIntfFjbiStruct{

	char    sBillingCycleID[6];		/* 结算账期 */
	char    sVisitAreaCode[5];		/* 结算地区号 */
	char    sAccNbr[24];		/* 结算号码 */
	char    sHomeAreaCode[5];		/* 主叫号码归属地 */
	char    sOppAreaCode[5];		/* 被叫号码归属地 */
	char    sRoamAreaCode[5];		/* 漫游通话地 */
	char    sHomeCarrID[4];		/* 主叫号码运营商 */
	char    sOppCarrID[4];		/* 被叫号码运营商 */
	char    sCallDirection[4];		/* 呼叫方向编码 */
	char    sTicketTypeID[4];		/* 结算类型 */
	char    sCnt[9];		/* 话单数 */
	char    sDuration[9];		/* 通话时长 */
	char    sFeeDuration[9];		/* 结算时长 */
	char    sInFee[9];		/* 结算收入 */
	char    sOutFee[9];		/* 结算支出 */
	char    sServiceType[3];		/* 业务类型 */
	char    sNbrType[4];		/* 本端用户网络类型 */
	char    sOppNbrType[4];		/* 对方用户网络类型 */
	char    sSettFlag[4];		/* 结算收支标识 */
	char    sReserve1[10];		/* 保留维度1 */
	char    sReserve2[10];		/* 保留维度2 */
	char    sDealDate[14];		/* 处理时间 */
};
/*批量数据动态从SETT_NBR_INTF_FJBI中用结构缓冲方式取数据*/
int EGetSettNbrIntfFjbiToStruct(struct SettNbrIntfFjbiStruct *p,
	struct SettNbrIntfFjbiStructIn *pSource);
/*批量数据结构缓冲写入SETT_NBR_INTF_FJBI*/
int EInsertStructToSettNbrIntfFjbi(struct SettNbrIntfFjbiStruct *p,
	int iInsertFlag,struct SettNbrIntfFjbiStructOut *pTarget);
void mvitem_settnbrintffjbi(struct SettNbrIntfFjbiStruct *pi,struct SettNbrIntfFjbiStruct *po);

#endif
