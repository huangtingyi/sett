#ifndef __SETTREPORT_SUPP_H__
#define __SETTREPORT_SUPP_H__


/* 输入结构缓冲申明*/
struct ParamReportStatStructIn{

#ifndef PARAM_REPORT_STAT_BUFLEN_IN
#define PARAM_REPORT_STAT_BUFLEN_IN		300
#endif

	struct ParamReportStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiItemID[PARAM_REPORT_STAT_BUFLEN_IN];
	int     aiAcctItemTypeID[PARAM_REPORT_STAT_BUFLEN_IN];
	char    asOppCarrierID[PARAM_REPORT_STAT_BUFLEN_IN][41];
	char    asUserType[PARAM_REPORT_STAT_BUFLEN_IN][41];
	char    asRemark[PARAM_REPORT_STAT_BUFLEN_IN][201];
	char    asEffDate[PARAM_REPORT_STAT_BUFLEN_IN][15];
	char    asExpDate[PARAM_REPORT_STAT_BUFLEN_IN][15];
	char    asState[PARAM_REPORT_STAT_BUFLEN_IN][4];
	char    asStateDate[PARAM_REPORT_STAT_BUFLEN_IN][15];
	char    asCreatedDate[PARAM_REPORT_STAT_BUFLEN_IN][15];
};


/*单个结构申明*/
struct ParamReportStatStruct{

	struct ParamReportStatStruct *pNext;
	int     iItemID;
	int     iAcctItemTypeID;
	char    sOppCarrierID[41];
	char    sUserType[41];
	char    sRemark[201];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct ParamReportStatStruct *pLoadNext;
};

/*批量数据动态从PARAM_REPORT_STAT中用结构缓冲方式取数据*/
int EGetParamReportStatToStruct(struct ParamReportStatStruct *p,
	struct ParamReportStatStructIn *pSource);
int data_search_bintree_paramreportstat_e(void *pValue,void*pData);
int InitParamReportStat2Bin(BINTREE **ppRoot);


/*输出结构缓冲申明*/
struct ReportStatStructOut{

#ifndef REPORT_STAT_BUFLEN_OUT
#define REPORT_STAT_BUFLEN_OUT		300
#endif

	struct ReportStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiReportStatID[REPORT_STAT_BUFLEN_OUT];
	int     aiItemID[REPORT_STAT_BUFLEN_OUT];
	int     aiLatnID[REPORT_STAT_BUFLEN_OUT];
	char    asCharge[REPORT_STAT_BUFLEN_OUT][13];
	char    asSettItemDate[REPORT_STAT_BUFLEN_OUT][15];
	int     aiSettCycleID[REPORT_STAT_BUFLEN_OUT];
	char    asCreatedDate[REPORT_STAT_BUFLEN_OUT][15];
	char    asState[REPORT_STAT_BUFLEN_OUT][4];
	int     aiOppCarrierID[REPORT_STAT_BUFLEN_OUT];
	char    asOppArea[REPORT_STAT_BUFLEN_OUT][6];
	char    asReserve[REPORT_STAT_BUFLEN_OUT][11];
	char    asSourceID[REPORT_STAT_BUFLEN_OUT][7];
};


/* 输入结构缓冲申明*/
struct ReportStatStructIn{

#ifndef REPORT_STAT_BUFLEN_IN
#define REPORT_STAT_BUFLEN_IN		300
#endif

	struct ReportStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiReportStatID[REPORT_STAT_BUFLEN_IN];
	int     aiItemID[REPORT_STAT_BUFLEN_IN];
	int     aiLatnID[REPORT_STAT_BUFLEN_IN];
	char    asCharge[REPORT_STAT_BUFLEN_IN][13];
	char    asSettItemDate[REPORT_STAT_BUFLEN_IN][15];
	int     aiSettCycleID[REPORT_STAT_BUFLEN_IN];
	char    asCreatedDate[REPORT_STAT_BUFLEN_IN][15];
	char    asState[REPORT_STAT_BUFLEN_IN][4];
	int     aiOppCarrierID[REPORT_STAT_BUFLEN_IN];
	char    asOppArea[REPORT_STAT_BUFLEN_IN][6];
	char    asReserve[REPORT_STAT_BUFLEN_IN][11];
	char    asSourceID[REPORT_STAT_BUFLEN_IN][7];
};


/*单个结构申明*/
struct ReportStatStruct{

	struct ReportStatStruct *pNext;
	int     iReportStatID;
	int     iItemID;
	int     iLatnID;
	char    sCharge[13];
	char    sSettItemDate[15];
	int     iSettCycleID;
	char    sCreatedDate[15];
	char    sState[4];
	int     iOppCarrierID;
	char    sOppArea[6];
	char    sReserve[11];
	char    sSourceID[7];
	struct ReportStatStruct *pLoadNext;
};


/*批量数据动态从REPORT_STAT中用结构缓冲方式取数据*/
int EGetReportStatToStruct(struct ReportStatStruct *p,
	struct ReportStatStructIn *pSource);
/*批量数据结构缓冲写入REPORT_STAT*/
int EInsertStructToReportStat(struct ReportStatStruct *p,
	int iInsertFlag,struct ReportStatStructOut *pTarget);
int iReportStatID();

#endif

