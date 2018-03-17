#ifndef _AUSETT_SUPP_H_
#define _AUSETT_SUPP_H_


/*---------基本部分代码 report_item_config.txt----------*/

/*输出结构缓冲申明*/
struct ReportItemConfigStructOut{

#ifndef REPORT_ITEM_CONFIG_BUFLEN_OUT
#define REPORT_ITEM_CONFIG_BUFLEN_OUT		300
#endif

	struct ReportItemConfigStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[64];
		/* 报表项（前6位报表ID，后两位项ID） */
	int     aiReportItemID[REPORT_ITEM_CONFIG_BUFLEN_OUT];
		/* 0是支出, 1是收入, *是无记录, 2是只统计 */
	char    asFeeType[REPORT_ITEM_CONFIG_BUFLEN_OUT][3];
		/* 话单类型 */
	char    asTicketTypeID[REPORT_ITEM_CONFIG_BUFLEN_OUT][31];
		/* 条件字段 */
	char    asColumnName[REPORT_ITEM_CONFIG_BUFLEN_OUT][31];
		/* 值 */
	char    asColumnValue[REPORT_ITEM_CONFIG_BUFLEN_OUT][61];
		/* 字段控制函数：1为in，2为 not in  ... */
	int     aiColumnCtrl[REPORT_ITEM_CONFIG_BUFLEN_OUT];
		/* 结算类型（GSM网间语音：与电信固网 10,与电信cdma 11,与移动 12,与铁通 13;固网网间语音：与电信固网 20,与电信cdma 21, 与移动 22,与铁通 23） */
	char    asSettType[REPORT_ITEM_CONFIG_BUFLEN_OUT][6];
};


/* 输入结构缓冲申明*/
struct ReportItemConfigStructIn{

#ifndef REPORT_ITEM_CONFIG_BUFLEN_IN
#define REPORT_ITEM_CONFIG_BUFLEN_IN		300
#endif

	struct ReportItemConfigStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[64];
	char sCondition[1024];
		/* 报表项（前6位报表ID，后两位项ID） */
	int     aiReportItemID[REPORT_ITEM_CONFIG_BUFLEN_IN];
		/* 0是支出, 1是收入, *是无记录, 2是只统计 */
	char    asFeeType[REPORT_ITEM_CONFIG_BUFLEN_IN][3];
		/* 话单类型 */
	char    asTicketTypeID[REPORT_ITEM_CONFIG_BUFLEN_IN][31];
		/* 条件字段 */
	char    asColumnName[REPORT_ITEM_CONFIG_BUFLEN_IN][31];
		/* 值 */
	char    asColumnValue[REPORT_ITEM_CONFIG_BUFLEN_IN][61];
		/* 字段控制函数：1为in，2为 not in  ... */
	int     aiColumnCtrl[REPORT_ITEM_CONFIG_BUFLEN_IN];
		/* 结算类型（GSM网间语音：与电信固网 10,与电信cdma 11,与移动 12,与铁通 13;固网网间语音：与电信固网 20,与电信cdma 21, 与移动 22,与铁通 23） */
	char    asSettType[REPORT_ITEM_CONFIG_BUFLEN_IN][6];
};


/*单个结构申明*/
struct ReportItemConfigStruct{

	struct ReportItemConfigStruct *pNext;
	int     iReportItemID;		/* 报表项（前6位报表ID，后两位项ID） */
	char    sFeeType[3];		/* 0是支出, 1是收入, *是无记录, 2是只统计 */
	char    sTicketTypeID[31];		/* 话单类型 */
	char    sColumnName[31];		/* 条件字段 */
	char    sColumnValue[61];		/* 值 */
	int     iColumnCtrl;		/* 字段控制函数：1为in，2为 not in  ... */
	char    sSettType[6];		/* 结算类型（GSM网间语音：与电信固网 10,与电信cdma 11,与移动 12,与铁通 13;固网网间语音：与电信固网 20,与电信cdma 21, 与移动 22,与铁通 23） */
	struct ReportItemConfigStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FReportItemConfigStruct{

	char    sReportItemID[8];		/* 报表项（前6位报表ID，后两位项ID） */
	char    sFeeType[2];		/* 0是支出, 1是收入, *是无记录, 2是只统计 */
	char    sTicketTypeID[30];		/* 话单类型 */
	char    sColumnName[30];		/* 条件字段 */
	char    sColumnValue[60];		/* 值 */
	char    sColumnCtrl[3];		/* 字段控制函数：1为in，2为 not in  ... */
	char    sSettType[5];		/* 结算类型（GSM网间语音：与电信固网 10,与电信cdma 11,与移动 12,与铁通 13;固网网间语音：与电信固网 20,与电信cdma 21, 与移动 22,与铁通 23） */
};
void mvitem_fmreportitemconfig(struct FReportItemConfigStruct *pi,struct ReportItemConfigStruct *po);
/*批量数据动态从REPORT_ITEM_CONFIG中用结构缓冲方式取数据*/
int EGetReportItemConfigToStruct(struct ReportItemConfigStruct *p,
	struct ReportItemConfigStructIn *pSource);



/*---------基本部分代码 stt_ticket.txt----------*/

/*输出结构缓冲申明*/
struct SttTicketStructOut{

#ifndef STT_TICKET_BUFLEN_OUT
#define STT_TICKET_BUFLEN_OUT		300
#endif

	struct SttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiTicketTypeID[STT_TICKET_BUFLEN_OUT];
	char    asCallType[STT_TICKET_BUFLEN_OUT][3];
	char    asMsisdn[STT_TICKET_BUFLEN_OUT][16];
	char    asCalledCode[STT_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[STT_TICKET_BUFLEN_OUT][25];
	char    asVisitAreaCode[STT_TICKET_BUFLEN_OUT][6];
	int     aiRoamFee[STT_TICKET_BUFLEN_OUT];
	int     aiTollFee[STT_TICKET_BUFLEN_OUT];
	int     aiAddFee[STT_TICKET_BUFLEN_OUT];
	int     aiDuration[STT_TICKET_BUFLEN_OUT];
	char    asStartTime[STT_TICKET_BUFLEN_OUT][15];
	char    asHomeAreaCode[STT_TICKET_BUFLEN_OUT][6];
	char    asRoamType[STT_TICKET_BUFLEN_OUT][2];
	char    asDistanceType[STT_TICKET_BUFLEN_OUT][2];
	char    asOppType[STT_TICKET_BUFLEN_OUT][2];
	char    asUserType[STT_TICKET_BUFLEN_OUT][2];
	char    asSplitRuleID[STT_TICKET_BUFLEN_OUT][5];
	char    asOppRoamType[STT_TICKET_BUFLEN_OUT][2];
	char    asServiceType[STT_TICKET_BUFLEN_OUT][4];
	char    asServiceCode[STT_TICKET_BUFLEN_OUT][5];
	char    asImsi[STT_TICKET_BUFLEN_OUT][16];
	char    asMsc[STT_TICKET_BUFLEN_OUT][16];
	char    asLac[STT_TICKET_BUFLEN_OUT][6];
	char    asCellID[STT_TICKET_BUFLEN_OUT][6];
	char    asOtherLac[STT_TICKET_BUFLEN_OUT][6];
	char    asOtherCellID[STT_TICKET_BUFLEN_OUT][6];
	char    asTrunkIn[STT_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[STT_TICKET_BUFLEN_OUT][8];
	char    asThirdParty[STT_TICKET_BUFLEN_OUT][16];
	char    asMsrn[STT_TICKET_BUFLEN_OUT][13];
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_OUT];
	char    asTrunkInType[STT_TICKET_BUFLEN_OUT][2];
	char    asTrunkOutType[STT_TICKET_BUFLEN_OUT][2];
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_OUT];
	int     aiCallingTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiCallingAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiASettAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiBSettAreaID[STT_TICKET_BUFLEN_OUT];
	char    asSplitType[STT_TICKET_BUFLEN_OUT][2];
	char    asCal[STT_TICKET_BUFLEN_OUT][2];
	char    asEsn[STT_TICKET_BUFLEN_OUT][16];
	char    asScpFlag[STT_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_OUT][2];
	char    asReserve[STT_TICKET_BUFLEN_OUT][9];
	char    asBillMode[STT_TICKET_BUFLEN_OUT][4];
	char    asReserve1[STT_TICKET_BUFLEN_OUT][3];
	char    asRoamTariffType[STT_TICKET_BUFLEN_OUT][4];
	char    asTollTariffType[STT_TICKET_BUFLEN_OUT][4];
	char    asAddTariffType[STT_TICKET_BUFLEN_OUT][4];
	char    asErrCode[STT_TICKET_BUFLEN_OUT][5];
	char    asFileName[STT_TICKET_BUFLEN_OUT][20];
	char    asModule[STT_TICKET_BUFLEN_OUT][4];
	char    asAreaCode[STT_TICKET_BUFLEN_OUT][6];
	char    asState[STT_TICKET_BUFLEN_OUT][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_OUT][15];
	char    asDealDate[STT_TICKET_BUFLEN_OUT][15];
	char    asSourceID[STT_TICKET_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct SttTicketStructIn{

#ifndef STT_TICKET_BUFLEN_IN
#define STT_TICKET_BUFLEN_IN		300
#endif

	struct SttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[128];
	char sCondition[1024];
	int     aiTicketTypeID[STT_TICKET_BUFLEN_IN];
	char    asCallType[STT_TICKET_BUFLEN_IN][3];
	char    asMsisdn[STT_TICKET_BUFLEN_IN][16];
	char    asCalledCode[STT_TICKET_BUFLEN_IN][6];
	char    asOtherParty[STT_TICKET_BUFLEN_IN][25];
	char    asVisitAreaCode[STT_TICKET_BUFLEN_IN][6];
	int     aiRoamFee[STT_TICKET_BUFLEN_IN];
	int     aiTollFee[STT_TICKET_BUFLEN_IN];
	int     aiAddFee[STT_TICKET_BUFLEN_IN];
	int     aiDuration[STT_TICKET_BUFLEN_IN];
	char    asStartTime[STT_TICKET_BUFLEN_IN][15];
	char    asHomeAreaCode[STT_TICKET_BUFLEN_IN][6];
	char    asRoamType[STT_TICKET_BUFLEN_IN][2];
	char    asDistanceType[STT_TICKET_BUFLEN_IN][2];
	char    asOppType[STT_TICKET_BUFLEN_IN][2];
	char    asUserType[STT_TICKET_BUFLEN_IN][2];
	char    asSplitRuleID[STT_TICKET_BUFLEN_IN][5];
	char    asOppRoamType[STT_TICKET_BUFLEN_IN][2];
	char    asServiceType[STT_TICKET_BUFLEN_IN][4];
	char    asServiceCode[STT_TICKET_BUFLEN_IN][5];
	char    asImsi[STT_TICKET_BUFLEN_IN][16];
	char    asMsc[STT_TICKET_BUFLEN_IN][16];
	char    asLac[STT_TICKET_BUFLEN_IN][6];
	char    asCellID[STT_TICKET_BUFLEN_IN][6];
	char    asOtherLac[STT_TICKET_BUFLEN_IN][6];
	char    asOtherCellID[STT_TICKET_BUFLEN_IN][6];
	char    asTrunkIn[STT_TICKET_BUFLEN_IN][8];
	char    asTrunkOut[STT_TICKET_BUFLEN_IN][8];
	char    asThirdParty[STT_TICKET_BUFLEN_IN][16];
	char    asMsrn[STT_TICKET_BUFLEN_IN][13];
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_IN];
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_IN];
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_IN];
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_IN];
	char    asTrunkInType[STT_TICKET_BUFLEN_IN][2];
	char    asTrunkOutType[STT_TICKET_BUFLEN_IN][2];
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_IN];
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_IN];
	int     aiCallingTypeID[STT_TICKET_BUFLEN_IN];
	int     aiCalledTypeID[STT_TICKET_BUFLEN_IN];
	int     aiCallingAreaID[STT_TICKET_BUFLEN_IN];
	int     aiCalledAreaID[STT_TICKET_BUFLEN_IN];
	int     aiASettAreaID[STT_TICKET_BUFLEN_IN];
	int     aiBSettAreaID[STT_TICKET_BUFLEN_IN];
	char    asSplitType[STT_TICKET_BUFLEN_IN][2];
	char    asCal[STT_TICKET_BUFLEN_IN][2];
	char    asEsn[STT_TICKET_BUFLEN_IN][16];
	char    asScpFlag[STT_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_IN][2];
	char    asReserve[STT_TICKET_BUFLEN_IN][9];
	char    asBillMode[STT_TICKET_BUFLEN_IN][4];
	char    asReserve1[STT_TICKET_BUFLEN_IN][3];
	char    asRoamTariffType[STT_TICKET_BUFLEN_IN][4];
	char    asTollTariffType[STT_TICKET_BUFLEN_IN][4];
	char    asAddTariffType[STT_TICKET_BUFLEN_IN][4];
	char    asErrCode[STT_TICKET_BUFLEN_IN][5];
	char    asFileName[STT_TICKET_BUFLEN_IN][20];
	char    asModule[STT_TICKET_BUFLEN_IN][4];
	char    asAreaCode[STT_TICKET_BUFLEN_IN][6];
	char    asState[STT_TICKET_BUFLEN_IN][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_IN][15];
	char    asDealDate[STT_TICKET_BUFLEN_IN][15];
	char    asSourceID[STT_TICKET_BUFLEN_IN][41];
};


/*单个结构申明*/
struct SttTicketStruct{

	struct SttTicketStruct *pNext;
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
	struct SttTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSttTicketStruct{

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
/*批量数据动态从STT_TICKET中用结构缓冲方式取数据*/
int EGetSttTicketToStruct_t(struct SttTicketStruct *p,
	struct SttTicketStructIn *pSource);
void mvitem_fmtemplatesttticket(struct FSttTicketStruct *pi,struct SttTicketStruct *po);
int InitSttTicket(struct SttTicketStruct **pptHead);


/*---------基本部分代码 au_sett_log.txt----------*/

/*输出结构缓冲申明*/
struct AuSettLogStructOut{

#ifndef AU_SETT_LOG_BUFLEN_OUT
#define AU_SETT_LOG_BUFLEN_OUT		300
#endif

	struct AuSettLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 输入表名 */
	char    asDealTable[AU_SETT_LOG_BUFLEN_OUT][41];
		/* 收入输出表 */
	char    asOutTableIn[AU_SETT_LOG_BUFLEN_OUT][41];
		/* 支出输出表 */
	char    asOutTableOut[AU_SETT_LOG_BUFLEN_OUT][41];
		/* 数据时间 */
	char    asDataDate[AU_SETT_LOG_BUFLEN_OUT][15];
		/* 处理时间 */
	char    asDealDate[AU_SETT_LOG_BUFLEN_OUT][15];
		/* P0F:处理失败  P0S:处理成功  60A:处理中 */
	char    asDealState[AU_SETT_LOG_BUFLEN_OUT][4];
};


/* 输入结构缓冲申明*/
struct AuSettLogStructIn{

#ifndef AU_SETT_LOG_BUFLEN_IN
#define AU_SETT_LOG_BUFLEN_IN		300
#endif

	struct AuSettLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 输入表名 */
	char    asDealTable[AU_SETT_LOG_BUFLEN_IN][41];
		/* 收入输出表 */
	char    asOutTableIn[AU_SETT_LOG_BUFLEN_IN][41];
		/* 支出输出表 */
	char    asOutTableOut[AU_SETT_LOG_BUFLEN_IN][41];
		/* 数据时间 */
	char    asDataDate[AU_SETT_LOG_BUFLEN_IN][15];
		/* 处理时间 */
	char    asDealDate[AU_SETT_LOG_BUFLEN_IN][15];
		/* P0F:处理失败  P0S:处理成功  60A:处理中 */
	char    asDealState[AU_SETT_LOG_BUFLEN_IN][4];
};


/*单个结构申明*/
struct AuSettLogStruct{

	struct AuSettLogStruct *pNext;
	char    sDealTable[41];		/* 输入表名 */
	char    sOutTableIn[41];		/* 收入输出表 */
	char    sOutTableOut[41];		/* 支出输出表 */
	char    sDataDate[15];		/* 数据时间 */
	char    sDealDate[15];		/* 处理时间 */
	char    sDealState[4];		/* P0F:处理失败  P0S:处理成功  60A:处理中 */
	struct AuSettLogStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAuSettLogStruct{

	char    sDealTable[40];		/* 输入表名 */
	char    sOutTableIn[40];		/* 收入输出表 */
	char    sOutTableOut[40];		/* 支出输出表 */
	char    sDataDate[14];		/* 数据时间 */
	char    sDealDate[14];		/* 处理时间 */
	char    sDealState[3];		/* P0F:处理失败  P0S:处理成功  60A:处理中 */
};





/*---------基本部分代码 收入 支出 表公用的结构体----------*/

/*输出结构缓冲申明*/
struct AuSettNbrStatStructOut{

#ifndef AU_SETT_NBR_STAT_BUFLEN_OUT
#define AU_SETT_NBR_STAT_BUFLEN_OUT		300
#endif

	struct AuSettNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asAccNbr[AU_SETT_NBR_STAT_BUFLEN_OUT][21];
	char    asHomeAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_NBR_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_NBR_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_NBR_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_NBR_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asBillingCycleID[AU_SETT_NBR_STAT_BUFLEN_OUT][7];
	int     aiCnt[AU_SETT_NBR_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_NBR_STAT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct AuSettNbrStatStructIn{

#ifndef AU_SETT_NBR_STAT_BUFLEN_IN
#define AU_SETT_NBR_STAT_BUFLEN_IN		300
#endif

	struct AuSettNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asAccNbr[AU_SETT_NBR_STAT_BUFLEN_IN][21];
	char    asHomeAreaCode[AU_SETT_NBR_STAT_BUFLEN_IN][6];
	char    asVisitAreaCode[AU_SETT_NBR_STAT_BUFLEN_IN][6];
	char    asCalledCode[AU_SETT_NBR_STAT_BUFLEN_IN][6];
	char    asNetType[AU_SETT_NBR_STAT_BUFLEN_IN][2];
	int     aiReportItemID[AU_SETT_NBR_STAT_BUFLEN_IN];
	char    asSettType[AU_SETT_NBR_STAT_BUFLEN_IN][3];
	char    asSettNbrType[AU_SETT_NBR_STAT_BUFLEN_IN][4];
	char    asSettCarrID[AU_SETT_NBR_STAT_BUFLEN_IN][2];
	char    asMsc[AU_SETT_NBR_STAT_BUFLEN_IN][16];
	char    asTrunkIn[AU_SETT_NBR_STAT_BUFLEN_IN][8];
	char    asTrunkOut[AU_SETT_NBR_STAT_BUFLEN_IN][8];
	char    asTrunkCarrierID[AU_SETT_NBR_STAT_BUFLEN_IN][2];
	char    asBillingCycleID[AU_SETT_NBR_STAT_BUFLEN_IN][7];
	int     aiCnt[AU_SETT_NBR_STAT_BUFLEN_IN];
	int     aiSettMin[AU_SETT_NBR_STAT_BUFLEN_IN];
	double    adFee[AU_SETT_NBR_STAT_BUFLEN_IN];
	double    adDuration[AU_SETT_NBR_STAT_BUFLEN_IN];
	char	asRowID[AU_SETT_NBR_STAT_BUFLEN_IN][19];

};


/*单个结构申明*/
struct AuSettNbrStatStruct{

	struct AuSettNbrStatStruct *pNext;
	char    sAccNbr[21];
	char    sHomeAreaCode[6];
	char    sVisitAreaCode[6];
	char    sCalledCode[6];
	char    sNetType[2];
	int     iReportItemID;
	char    sSettType[3];
	char    sSettNbrType[4];
	char    sSettCarrID[2];
	char    sMsc[16];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sTrunkCarrierID[2];
	char    sBillingCycleID[7];
	int     iCnt;
	int     iSettMin;
	double    dFee;
	double    dDuration;
	
	int	iInFlag;	/*收入:1  支出:0*/
	char	sRowID[19];
	struct AuSettNbrStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAuSettNbrStatStruct{

	char    sAccNbr[20];
	char    sHomeAreaCode[5];
	char    sVisitAreaCode[5];
	char    sCalledCode[5];
	char    sNetType[1];
	char    sReportItemID[4];
	char    sSettType[2];
	char    sSettNbrType[3];
	char    sSettCarrID[1];
	char    sMsc[15];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sTrunkCarrierID[1];
	char    sBillingCycleID[6];
	char    sCnt[9];
	char    sSettMin[9];
	char    sFee[12];
	char    sDuration[12];
};

/*---------基本部分代码 au_sett_stat.txt----------*/

/*输出结构缓冲申明*/
struct AuSettStatStructOut{

#ifndef AU_SETT_STAT_BUFLEN_OUT
#define AU_SETT_STAT_BUFLEN_OUT		300
#endif

	struct AuSettStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asHomeAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asSettItemDate[AU_SETT_STAT_BUFLEN_OUT][9];
	char    asBillingCycleID[AU_SETT_STAT_BUFLEN_OUT][7];
	int     aiCnt[AU_SETT_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_STAT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct AuSettStatStructIn{

#ifndef AU_SETT_STAT_BUFLEN_IN
#define AU_SETT_STAT_BUFLEN_IN		300
#endif

	struct AuSettStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asHomeAreaCode[AU_SETT_STAT_BUFLEN_IN][6];
	char    asVisitAreaCode[AU_SETT_STAT_BUFLEN_IN][6];
	char    asCalledCode[AU_SETT_STAT_BUFLEN_IN][6];
	char    asNetType[AU_SETT_STAT_BUFLEN_IN][2];
	int     aiReportItemID[AU_SETT_STAT_BUFLEN_IN];
	char    asSettType[AU_SETT_STAT_BUFLEN_IN][3];
	char    asSettNbrType[AU_SETT_STAT_BUFLEN_IN][4];
	char    asSettCarrID[AU_SETT_STAT_BUFLEN_IN][2];
	char    asMsc[AU_SETT_STAT_BUFLEN_IN][16];
	char    asTrunkIn[AU_SETT_STAT_BUFLEN_IN][8];
	char    asTrunkOut[AU_SETT_STAT_BUFLEN_IN][8];
	char    asTrunkCarrierID[AU_SETT_STAT_BUFLEN_IN][2];
	char    asSettItemDate[AU_SETT_STAT_BUFLEN_IN][9];
	char    asBillingCycleID[AU_SETT_STAT_BUFLEN_IN][7];
	int     aiCnt[AU_SETT_STAT_BUFLEN_IN];
	int     aiSettMin[AU_SETT_STAT_BUFLEN_IN];
	double    adFee[AU_SETT_STAT_BUFLEN_IN];
	double    adDuration[AU_SETT_STAT_BUFLEN_IN];
	char	asRowID[AU_SETT_STAT_BUFLEN_IN][19];
};


/*单个结构申明*/
struct AuSettStatStruct{

	struct AuSettStatStruct *pNext;
	char    sHomeAreaCode[6];
	char    sVisitAreaCode[6];
	char    sCalledCode[6];
	char    sNetType[2];
	int     iReportItemID;
	char    sSettType[3];
	char    sSettNbrType[4];
	char    sSettCarrID[2];
	char    sMsc[16];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sTrunkCarrierID[2];
	char    sSettItemDate[9];
	char    sBillingCycleID[7];
	int     iCnt;
	int     iSettMin;
	double    dFee;
	double    dDuration;
	int	iInFlag;
	char	sRowID[19];
	struct AuSettStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAuSettStatStruct{

	char    sHomeAreaCode[5];
	char    sVisitAreaCode[5];
	char    sCalledCode[5];
	char    sNetType[1];
	char    sReportItemID[4];
	char    sSettType[2];
	char    sSettNbrType[3];
	char    sSettCarrID[1];
	char    sMsc[15];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sTrunkCarrierID[1];
	char    sSettItemDate[8];
	char    sBillingCycleID[6];
	char    sCnt[9];
	char    sSettMin[9];
	char    sFee[12];
	char    sDuration[12];
};



/*----------------------更新输出结构---------------------------------------*/
/*更新结构缓冲申明*/
struct AuSettNbrStatStructUpdOut{

#ifndef AU_SETT_NBR_STAT_BUFLEN_OUT
#define AU_SETT_NBR_STAT_BUFLEN_OUT		300
#endif

	struct AuSettNbrStatStructUpOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
/*	
	char    asAccNbr[AU_SETT_NBR_STAT_BUFLEN_OUT][21];
	char    asHomeAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_NBR_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_NBR_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_NBR_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_NBR_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asBillingCycleID[AU_SETT_NBR_STAT_BUFLEN_OUT][7];
*/
	int     aiCnt[AU_SETT_NBR_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_NBR_STAT_BUFLEN_OUT];
	char	asRowID[AU_SETT_NBR_STAT_BUFLEN_OUT][19];
};

/*输出结构缓冲申明*/
struct AuSettStatStructUpdOut{

#ifndef AU_SETT_STAT_BUFLEN_OUT
#define AU_SETT_STAT_BUFLEN_OUT		300
#endif

	struct AuSettStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
/*
	char    asHomeAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asSettItemDate[AU_SETT_STAT_BUFLEN_OUT][9];
	char    asBillingCycleID[AU_SETT_STAT_BUFLEN_OUT][7];
*/
	int     aiCnt[AU_SETT_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_STAT_BUFLEN_OUT];
	char	asRowID[AU_SETT_STAT_BUFLEN_OUT][19];
};



/*批量数据动态从AU_SETT_LOG中用结构缓冲方式取数据*/
int EGetAuSettLogToStruct(struct AuSettLogStruct *p,struct AuSettLogStructIn *pSource);
void mvitem_fmausettlog(struct FAuSettLogStruct *pi,struct AuSettLogStruct *po);
/*批量数据结构缓冲写入AU_SETT_LOG*/
int EInsertStructToAuSettLog(struct AuSettLogStruct *p,int iInsertFlag,struct AuSettLogStructOut *pTarget);

/*批量数据动态从AU_SETT_NBR_IN_STAT中用结构缓冲方式取数据*/
int EGetAuSettNbrInStatToStruct(struct AuSettNbrStatStruct *p,struct AuSettNbrStatStructIn *pSource);
void mvitem_fmausettnbrstat(struct FAuSettNbrStatStruct *pi,struct AuSettNbrStatStruct *po);
/*批量数据结构缓冲写入AU_SETT_NBR_IN_STAT*/
int EInsertStructToAuSettNbrInStat(struct AuSettNbrStatStruct *p,int iInsertFlag,struct AuSettNbrStatStructOut *pTarget);

/*批量数据动态从AU_SETT_NBR_OUT_STAT中用结构缓冲方式取数据*/
int EGetAuSettNbrOutStatToStruct(struct AuSettNbrStatStruct *p,struct AuSettNbrStatStructIn *pSource);
void mvitem_fmausettnbrstat(struct FAuSettNbrStatStruct *pi,struct AuSettNbrStatStruct *po);
/*批量数据结构缓冲写入AU_SETT_NBR_OUT_STAT*/
int EInsertStructToAuSettNbrOutStat(struct AuSettNbrStatStruct *p,int iInsertFlag,struct AuSettNbrStatStructOut *pTarget);



/*批量数据动态从AU_SETT_IN_STAT中用结构缓冲方式取数据*/
int EGetAuSettInStatToStruct(struct AuSettStatStruct *p,struct AuSettStatStructIn *pSource);
void mvitem_fmausettstat(struct FAuSettStatStruct *pi,struct AuSettStatStruct *po);
/*批量数据结构缓冲写入AU_SETT_IN_STAT*/
int EInsertStructToAuSettInStat(struct AuSettStatStruct *p,int iInsertFlag,struct AuSettStatStructOut *pTarget);

/*批量数据动态从AU_SETT_OUT_STAT中用结构缓冲方式取数据*/
int EGetAuSettOutStatToStruct(struct AuSettStatStruct *p,struct AuSettStatStructIn *pSource);
/*批量数据结构缓冲写入AU_SETT_OUT_STAT*/
int EInsertStructToAuSettOutStat(struct AuSettStatStruct *p,int iInsertFlag,struct AuSettStatStructOut *pTarget);



/*批量数据结构缓冲更新AU_SETT_NBR_IN_STAT*/
int EUpDateStructToAuSettNbrInStat(struct AuSettNbrStatStruct *p,
	int iUpdateFlag,struct AuSettNbrStatStructUpdOut *pTarget);
/*批量数据结构缓冲更新AU_SETT_NBR_OUT_STAT*/
int EUpDateStructToAuSettNbrOutStat(struct AuSettNbrStatStruct *p,
	int iUpdateFlag,struct AuSettNbrStatStructUpdOut *pTarget);
/*批量数据结构缓冲更新AU_SETT_IN_STAT*/
int EUpDateStructToAuSettInStat(struct AuSettStatStruct *p,
	int iUpdateFlag,struct AuSettStatStructUpdOut *pTarget);
/*批量数据结构缓冲更新AU_SETT_OUT_STAT*/
int EUpDateStructToAuSettOutStat(struct AuSettStatStruct *p,
	int iUpdateFlag,struct AuSettStatStructUpdOut *pTarget);

#endif

