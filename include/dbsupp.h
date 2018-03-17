#ifndef __DBSUPP_H__
#define __DBSUPP_H__

/*单个结构申明*/
struct AcctLogStruct{

	struct AcctLogStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	char    sModule[4];		/* 模块标识 */
	char    sState[2];		/* 状态 */
	int     iByte;		/* 字节数 */
	int     iCnt;		/* 正确记录数 */
	char    sFileName[81];		/* 文件名 */
	char    sTableName[31];		/* 目标表名 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	char    sDataDate[15];		/* 数据归属日期 */
	char	sOperType[4];
	char    sFileType[6];		/* 文件类型 */
	int     iTacheID;		/* 环节标识 */
	char    sAppID[11];		/* 应用标识 */
	struct AcctLogStruct *pLoadNext;
};



/*单个结构申明*/
struct PickLogStruct{

	struct PickLogStruct *pNext;
	int     iInputID;		/* 文件标识 */
	char    sSourceID[7];		/* 来源 */
	int     iByte;		/* 字节数 */
	char    sFileName[81];		/* 文件名 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	int     iSeq;		/* 原始序号 */
	char    sState[2];		/* 状态 */
	char    sFileType[6];		/* 文件类型 */
	int     iTacheID;		/* 环节标识 */
	char    sAppID[11];		/* 应用标识 */
	struct PickLogStruct *pLoadNext;
};

/*单个结构申明*/
struct PrepLogStruct{

	struct PrepLogStruct *pNext;
	int     iInputID;		/* 文件标识 */
	char    sSourceID[7];		/* 来源 */
	char    sModule[4];		/* 模块标识 */
	char    sState[2];		/* 状态 */
	int     iCnt;		/* 正确记录数 */
	char    sFileName[41];		/* 文件名 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	char    sDataDate[15];		/* 数据归属日期 */
	int     iSeq;		/* 文件序号 */
	char    sOriFileName[81];		/* 原始文件名 */
	char    sFileType[6];		/* 文件类型 */
	char    sAppID[11];
	int     iTacheID;
	struct PrepLogStruct *pLoadNext;
};
/*单个结构申明*/
struct PrepProcLogStruct{

	struct PrepProcLogStruct *pNext;
	int     iInputID;		/* 输入流水 */
	char    sSourceID[7];		/* 文件来源 */
	char    sModule[4];		/* 处理模块 */
	int     iByte;		/* 输入文件字节数 */
	int     iCnt;		/* 输入文件记录数 */
	char    sFileName[81];		/* 处理文件名 */
	char    sDealBeginDate[15];		/* 处理起始时间 */
	char    sDealEndDate[15];		/* 处理终止时间 */
	int	iNormalCnt;
	int	iErrCnt;
	int	iDupCnt;
	int	iAbnoCnt;
	int	iNewCnt;
	char    sFileType[6];		/* 文件类型 */
	char    sAppID[11];
	int     iTacheID;
	struct PrepProcLogStruct *pLoadNext;
};

/*单个结构申明*/
struct BillingLogStruct{

	struct BillingLogStruct *pNext;
	int     iInputID;		/* 文件标识 */
	char    sSourceID[7];		/* 来源 */
	char    sModule[4];		/* 模块标识 */
	char    sState[2];		/* 状态 */
	int     iCnt;		/* 正确记录数 */
	char    sFileName[41];		/* 文件名 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	char    sDataDate[15];		/* 数据归属日期 */
	int     iSeq;		/* 文件序号 */
	char    sOriFileName[81];		/* 原始文件名 */
	char    sFileType[6];		/* 文件类型 */
	char	sAppCode[9];
	int     iTacheID;		/* 环节标识 */
	char    sAppID[11];		/* 应用标识 */
	struct BillingLogStruct *pLoadNext;
};


/* 输入结构缓冲申明*/
struct BillingLogStructIn{

#ifndef BILLING_LOG_BUFLEN_IN
#define BILLING_LOG_BUFLEN_IN		1000
#endif

	struct BillingLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 文件标识 */
	int     aiInputID[BILLING_LOG_BUFLEN_IN];
		/* 来源 */
	char    asSourceID[BILLING_LOG_BUFLEN_IN][7];
		/* 模块标识 */
	char    asModule[BILLING_LOG_BUFLEN_IN][4];
		/* 状态 */
	char    asState[BILLING_LOG_BUFLEN_IN][2];
		/* 正确记录数 */
	int     aiCnt[BILLING_LOG_BUFLEN_IN];
		/* 文件名 */
	char    asFileName[BILLING_LOG_BUFLEN_IN][41];
		/* 处理开始时间 */
	char    asDealBeginDate[BILLING_LOG_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asDealEndDate[BILLING_LOG_BUFLEN_IN][15];
		/* 数据归属日期 */
	char    asDataDate[BILLING_LOG_BUFLEN_IN][15];
		/* 文件序号 */
	int     aiSeq[BILLING_LOG_BUFLEN_IN];
		/* 原始文件名 */
	char    asOriFileName[BILLING_LOG_BUFLEN_IN][81];
		/* 文件类型 */
	char    asFileType[BILLING_LOG_BUFLEN_IN][6];
		/* 环节标识 */
	int     aiTacheID[BILLING_LOG_BUFLEN_IN];
		/* 应用标识 */
	char    asAppID[BILLING_LOG_BUFLEN_IN][11];
};

/*单个结构申明*/
struct RollProcLogStruct{

	struct RollProcLogStruct *pNext;
	int     iInputID;		/* 文件标识 */
	char    sSourceID[7];		/* 来源 */
	char    sModule[4];		/* 模块标识 */
	char    sState[2];		/* 状态 */
	int     iCnt;		/* 正确记录数 */
	char    sFileName[41];		/* 输出文件 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	char    sOriFileName[81];		/* 原始文件名 */
	char    sFileType[6];		/* 文件类型 */
	char	sAppCode[9];
	char    sAppID[11];
	int     iTacheID;
	struct RollProcLogStruct *pLoadNext;
};
/*单个结构申明*/
struct RollLogStruct{

	struct RollLogStruct *pNext;
	int     iInputID;		/* 文件标识 */
	char    sSourceID[7];		/* 来源 */
	char    sModule[4];		/* 模块标识 */
	char    sState[2];		/* 状态 */
	char    sFileName[81];		/* 文件名 */
	int     iCnt;		/* 记录数 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	char    sDataDate[15];		/* 数据归属日期 */
	int     iSeq;		/* 文件序号 */
	char    sFileType[6];		/* 文件类型 */
	char	sAppCode[9];
	char    sAppID[11];
	int     iTacheID;
	struct RollLogStruct *pLoadNext;
};

/*对数据的写入*/
int SDInsertStructToRollProcLog(struct RollProcLogStruct *p,char sTableName[]);
int SDInsertStructToRollLog(struct RollLogStruct *p,char sTableName[]);

/*批量数据动态从PROC_LOG中用结构缓冲方式取数据*/
int EGetBillingLogToStruct(struct BillingLogStruct *p,struct BillingLogStructIn *pSource);


/*批量数据动态从PROC_LOG中用结构缓冲方式取数据*/
int EGetBillingLogToStruct(struct BillingLogStruct *p,struct BillingLogStructIn *pSource);


/*对数据的取出*/
int SDGetAcctLogToStruct(struct AcctLogStruct *p,char sTableName[],char sCondition[]);
/*对数据的写入*/
int SDInsertStructToAcctLog(struct AcctLogStruct *p,char sTableName[]);
/*对数据的取出*/
int SDGetPickLogToStruct(struct PickLogStruct *p,char sTableName[],char sCondition[]);
/*对数据的写入*/
int SDInsertStructToPickLog(struct PickLogStruct *p,char sTableName[]);
/*对数据的取出*/
int SDGetPrepProcLogToStruct(struct PrepProcLogStruct *p,char sTableName[],char sCondition[]);
int SDGetPrepLogToStruct(struct PrepLogStruct *p,char sTableName[],char sCondition[]);
/*对PREP_PROC_LOG的写入*/
int SDInsertStructToPrepProcLog(struct PrepProcLogStruct *p,char sTableName[]);
/*对PREP_LOG的写入*/
int SDInsertStructToPrepLog(struct PrepLogStruct *p,char sTableName[]);
/*对数据的取出*/
int SDGetBillingLogToStruct(struct BillingLogStruct *p,char sTableName[],char sCondition[]);
/*对数据的写入*/
int SDInsertStructToBillingLog(struct BillingLogStruct *p,char sTableName[]);

/*单个结构申明*/
struct UpdataLogStruct{

	struct UpdataLogStruct *pNext;
	int     iUpdataID;		/* 文件序号 */
	char    sFileType[6];		/* 文件类型 */
	char    sFileName[81];		/* 文件名 */
	char    sBeginTime[15];		/* 首次通话时间 */
	char    sEndTime[15];		/* 末次通话时间 */
	int     iRecCnt;		/* 记录数 */
	int     iTotalCharge;		/* 总费用 */
	char    sDataDate[15];		/* 数据归属日期 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	char	sAppID[11];
	int	iTacheID;
	struct UpdataLogStruct *pLoadNext;
};
/*单个结构申明*/
struct UpdataProcLogStruct{

	struct UpdataProcLogStruct *pNext;
	char    sOriFileName[81];		/* 输入文件名 */
	char    sCurFileName[81];		/* 输出文件名 */
	int     iByte;		/* 输入文件字节数 */
	int     iRecCnt;		/* 输入文件记录数 */
	char    sFileDate[15];		/* 文件修改日期 */
	char	sAppID[11];
	int	iTacheID;
	struct UpdataProcLogStruct *pLoadNext;
};
/*单条数据从用动态SQL从UPDATA_LOG取数据*/
int SDGetUpdataLogToStruct(struct UpdataLogStruct *p,char sTableName[],char sCondition[]);
/*单条数据动态SQL向UPDATA_LOG写数据*/
int SDInsertStructToUpdataLog(struct UpdataLogStruct *p,char sTableName[]);
/*单条数据从用动态SQL从UPDATA_PROC_LOG取数据*/
int SDGetUpdataProcLogToStruct(struct UpdataProcLogStruct *p,char sTableName[],char sCondition[]);
/*单条数据动态SQL向UPDATA_PROC_LOG写数据*/
int SDInsertStructToUpdataProcLog(struct UpdataProcLogStruct *p,char sTableName[]);

int GetLastDateSeq(char sFileType[],char sDataDate[],int *piSeq);
int GetLastSeqComm(char sFileType[],int *piSeq);
int GetLastSeq(char sFileType[],char sDataDate[],int *piSeq);

/*取CDMA1X上传下一序列号*/
int GetLastDateSeq1X(char sFileType[],char sNextSeq[]);

int GetInputID();
int BillingLogCheck(char sSourceID[20],char sFileName[80],
	char sModule[10],char sTargetName[]);
int PrepLogCheck(char sSourceID[20],char sFileName[80],char sModule[10]);
int PickLogCheck(char sSourceID[20],char sFileName[80],int iChkDays);
int GetPrepNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10]);
int GetRcylNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10]);
int GetRollNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10]);
int GetBillNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10]);

/*系统监控部分*/
int GetTablespaceUsedPercent(char sTableSpaceName[31]);
void PrintErrTicket(char sTableName[],int iMaxCnt);
void PrintMissTrunk(char sTableName[],int iMaxCnt);
void PrintInsertLogCnt(char sSourceID[10],int iDay);
int PrintDataDelay(char sType[],char sTableName[31]);
void GetPickLogDelay(char sSourceID[7],char sDealEndDate[15],int *piDelay);


/* 输入结构缓冲申明*/
struct PickLogStructIn{

#ifndef PICK_LOG_BUFLEN_IN
#define PICK_LOG_BUFLEN_IN		1000
#endif

	struct PickLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 文件标识 */
	int     aiInputID[PICK_LOG_BUFLEN_IN];
		/* 来源 */
	char    asSourceID[PICK_LOG_BUFLEN_IN][7];
		/* 字节数 */
	int     aiByte[PICK_LOG_BUFLEN_IN];
		/* 文件名 */
	char    asFileName[PICK_LOG_BUFLEN_IN][81];
		/* 处理开始时间 */
	char    asDealBeginDate[PICK_LOG_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asDealEndDate[PICK_LOG_BUFLEN_IN][15];
		/* 原始序号 */
	int     aiSeq[PICK_LOG_BUFLEN_IN];
		/* 状态 */
	char    asState[PICK_LOG_BUFLEN_IN][2];
		/* 文件类型 */
	char    asFileType[PICK_LOG_BUFLEN_IN][6];
		/* 环节标识 */
	int     aiTacheID[PICK_LOG_BUFLEN_IN];
		/* 应用标识 */
	char    asAppID[PICK_LOG_BUFLEN_IN][11];
};

int EGetPickLogToStruct(struct PickLogStruct *p,
	struct PickLogStructIn *pSource);
int InitPickLog(char sSourceID[],char sTableName[],
	struct PickLogStruct **pptHead);
void DestroyPickLog(struct PickLogStruct *ptHead);


/* 输入结构缓冲申明*/
struct PrepLogStructIn{

#ifndef PREP_LOG_BUFLEN_IN
#define PREP_LOG_BUFLEN_IN		300
#endif

	struct PrepLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 文件标识 */
	int     aiInputID[PREP_LOG_BUFLEN_IN];
		/* 来源 */
	char    asSourceID[PREP_LOG_BUFLEN_IN][7];
		/* 模块标识 */
	char    asModule[PREP_LOG_BUFLEN_IN][4];
		/* 状态 */
	char    asState[PREP_LOG_BUFLEN_IN][2];
		/* 正确记录数 */
	int     aiCnt[PREP_LOG_BUFLEN_IN];
		/* 文件名 */
	char    asFileName[PREP_LOG_BUFLEN_IN][41];
		/* 处理开始时间 */
	char    asDealBeginDate[PREP_LOG_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asDealEndDate[PREP_LOG_BUFLEN_IN][15];
		/* 数据归属日期 */
	char    asDataDate[PREP_LOG_BUFLEN_IN][15];
		/* 文件序号 */
	int     aiSeq[PREP_LOG_BUFLEN_IN];
		/* 原始文件名 */
	char    asOriFileName[PREP_LOG_BUFLEN_IN][81];
		/* 文件类型 */
	char    asFileType[PREP_LOG_BUFLEN_IN][6];
	char    asAppID[PREP_LOG_BUFLEN_IN][11];
	int     aiTacheID[PREP_LOG_BUFLEN_IN];
};
/* 输入结构缓冲申明*/
struct PrepProcLogStructIn{

#ifndef PREP_PROC_LOG_BUFLEN_IN
#define PREP_PROC_LOG_BUFLEN_IN		300
#endif

	struct PrepProcLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 输入流水 */
	int     aiInputID[PREP_PROC_LOG_BUFLEN_IN];
		/* 文件来源 */
	char    asSourceID[PREP_PROC_LOG_BUFLEN_IN][7];
		/* 处理模块 */
	char    asModule[PREP_PROC_LOG_BUFLEN_IN][4];
		/* 输入文件字节数 */
	int     aiByte[PREP_PROC_LOG_BUFLEN_IN];
		/* 输入文件记录数 */
	int     aiCnt[PREP_PROC_LOG_BUFLEN_IN];
		/* 处理文件名 */
	char    asFileName[PREP_PROC_LOG_BUFLEN_IN][81];
		/* 处理起始时间 */
	char    asDealBeginDate[PREP_PROC_LOG_BUFLEN_IN][15];
		/* 处理终止时间 */
	char    asDealEndDate[PREP_PROC_LOG_BUFLEN_IN][15];
		/* 文件类型 */
	int	aiNormalCnt[PREP_PROC_LOG_BUFLEN_IN];
	int	aiErrCnt[PREP_PROC_LOG_BUFLEN_IN];
	int	aiDupCnt[PREP_PROC_LOG_BUFLEN_IN];
	int	aiAbnoCnt[PREP_PROC_LOG_BUFLEN_IN];
	int	aiNewCnt[PREP_PROC_LOG_BUFLEN_IN];
	char    asFileType[PREP_PROC_LOG_BUFLEN_IN][6];
	char    asAppID[PREP_PROC_LOG_BUFLEN_IN][11];
	int     aiTacheID[PREP_PROC_LOG_BUFLEN_IN];
};

struct DateCntStruct
{
	struct DateCntStruct *pNext;
	char sDataDate[15];
	int iCnt;
	int iDupCnt;
	char sFileName[128];
	char sDupName[128];
};
#define MAX_ITEM_CNT	100

/*单个结构申明*/
struct SettLogStruct{

	struct SettLogStruct *pNext;
	int     iInputID;		/* 来源 */
	char    sModule[4];		/* 模块标识 */
	int     iSettCarrierID;		/* 结算对象 */
	int     iLatnID;		/* 本地网标识 */
	int     iSettCycleID;		/* 结算帐期标识 */
	char    sSettItemDate[15];		/* 结算数据时间 */
	char    sDealBeginDate[15];		/* 处理开始时间 */
	char    sDealEndDate[15];		/* 处理结束时间 */
	char    sStep[2];		/* 'D' 日结 'M' 月结 */
	char    sState[2];		/* 状态 */
	char    sStateDate[15];		/* 状态时间 */
	struct SettLogStruct *pLoadNext;
};

int SDInsertStructToSettLog(struct SettLogStruct *p,char sTableName[]);
int SDGetSettLogToStruct(struct SettLogStruct *p,char sTableName[],char sCondition[]);


/*单个结构申明*/
struct ProcCtrlStruct{

	struct ProcCtrlStruct *pNext;
	int     iInputID;		/* 文件标识 */
	char    sFileName[256];		/* 文件名 */
	char	sCreatedDate[15];
	char	sDealDate[15];
	char    sState[2];		
/* '0' 文件刚生成,'1'文件处理中,'2' 文件处理完毕,'3'文件处理失败 */
	char    sCreateCmd[256];		/* 文件生成 */
	char    sProcCmd[256];		/* 文件处理 */
	struct ProcCtrlStruct *pLoadNext;
};

/*单条数据静态SQL向PROC_CTRL写数据*/
int SSInsertStructToProcCtrl(struct ProcCtrlStruct *p);
/*生成一条记录*/
int NewProcCtrl(char sFileName[],char sCreateCmd[]);
/*检查某个文件是否生成*/
int CheckProcCtrl(char sFileName[]);
/*将生成的文件锁定*/
int BeginProcCtrl(int iInputID);
/*将处理文件的状况写到文件记录*/
int EndProcCtrl(int iInputID,char sState[],char sProcCmd[]);

int InsertPickLog(char sSourceID[],int iSize,char sFileName[],
	char sDealBeginDate[], char sDealEndDate[],int iSeq,
	char sFileType[],int iTacheID,char sAppID[]);
char GetLogFileType(char cSplitType);
int WritePrepLog(struct PrepLogStruct *p,int iErrCnt,
	int iAbnoCnt,char sPrefix[],char sSplitStr[],char sPath[]);
int InsertPrepLog(char sSourceID[],char sModule[],char sOriFileName[],
	char sDataDate[],int iByte,int iNormalCnt,int iErrCnt,int iAbnoCnt,
	char sDealBeginDate[],char sDealEndDate[],char sSplitStr[],
	char sState[],char sOutName[],
	char sInFileType[],int iTacheID,char sAppID[],char sPrefix[]);
int InsertBillingLog(char sSourceID[],char sModule[],char sOriFileName[],
	int iByte,int iCnt,char sDataDate[],char sDealBeginDate[],
	char sDealEndDate[],char sState[],char sSplitStr[],char sNormalPath[],
	char sErrPath[],char sInType[],char sOutType[],
	char sAppCode[],int iTacheID,char sAppID[],char sPrefix[]);
int InsertRollLog(char sSourceID[],char sModule[],char sFileName[],
	int iSeq,char sDataDate[],char sDealBeginDate[],char sDealEndDate[],
	char sNormalPath[],char sFileType[],char sAppCode[],
	int iTacheID,char sAppID[]);
int InsertRcylLog(char sSourceID[],char sModule[],char sFileName[],
	int iSeq,char sDataDate[],char sDealBeginDate[],char sDealEndDate[],
	char sNormalPath[],char sFileType[],char sAppCode[],
	int iTacheID,char sAppID[]);

/*单个结构申明*/
struct BillingProcLogStruct{

	struct BillingProcLogStruct *pNext;
	int     iInputID;		/* 输入流水 */
	char    sSourceID[7];		/* 文件来源 */
	char    sModule[4];		/* 处理模块 */
	char    sFileName[81];		/* 处理文件名 */
	char    sSplitStr[21];		/* 输出分离串 */
	int     iByte;		/* 输入文件字节数 */
	int     iCnt;		/* 输入文件记录数 */
	char    sDealBeginDate[15];		/* 处理起始时间 */
	char    sDealEndDate[15];		/* 处理终止时间 */
	char    sCurFileName[81];
	int     iNormalCnt;
	int     iAbnoCnt;
	int     iNewCnt;
	char    sFileType[6];		/* 文件类型 */
	char	sAppCode[9];
	int     iTacheID;		/* 环节标识 */
	char    sAppID[11];		/* 应用标识 */
	struct BillingProcLogStruct *pLoadNext;
};

/*单条数据动态SQL向BILLING_PROC_LOG写数据*/
int SDInsertStructToBillingProcLog(struct BillingProcLogStruct *p,char sTableName[]);
int GetNextSeq( char sFileType[] );

/*批量数据动态从PREP_LOG中用结构缓冲方式取数据*/
int EGetPrepLogToStruct(struct PrepLogStruct *p,
	struct PrepLogStructIn *pSource);
/*批量数据动态从PREP_PROC_LOG中用结构缓冲方式取数据*/
int EGetPrepProcLogToStruct(struct PrepProcLogStruct *p,
	struct PrepProcLogStructIn *pSource);



/*输出结构缓冲申明*/
struct PickCheckLogStructOut{

#ifndef PICK_CHECK_LOG_BUFLEN_OUT
#define PICK_CHECK_LOG_BUFLEN_OUT		300
#endif

	struct PickCheckLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 来源 */
	char    asSourceID[PICK_CHECK_LOG_BUFLEN_OUT][7];
		/* 业务模块 */
	char    asModule[PICK_CHECK_LOG_BUFLEN_OUT][4];
		/* 文件名 */
	char    asFileName[PICK_CHECK_LOG_BUFLEN_OUT][81];
		/* 文件日期 */
	char    asFileDate[PICK_CHECK_LOG_BUFLEN_OUT][15];
		/* 待稽核文件名 */
	char    asChkFileName[PICK_CHECK_LOG_BUFLEN_OUT][81];
		/* 待稽核记录 */
	int     aiChkCnt[PICK_CHECK_LOG_BUFLEN_OUT];
		/* 系统处理记录 */
	int     aiPreCnt[PICK_CHECK_LOG_BUFLEN_OUT];
		/* 文件类型 */
	char    asFileType[PICK_CHECK_LOG_BUFLEN_OUT][6];
		/* 处理时间 */
	char    asDealDate[PICK_CHECK_LOG_BUFLEN_OUT][15];
};


/* 输入结构缓冲申明*/
struct PickCheckLogStructIn{

#ifndef PICK_CHECK_LOG_BUFLEN_IN
#define PICK_CHECK_LOG_BUFLEN_IN		300
#endif

	struct PickCheckLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[PICK_CHECK_LOG_BUFLEN_IN][7];
		/* 业务模块 */
	char    asModule[PICK_CHECK_LOG_BUFLEN_IN][4];
		/* 文件名 */
	char    asFileName[PICK_CHECK_LOG_BUFLEN_IN][81];
		/* 文件日期 */
	char    asFileDate[PICK_CHECK_LOG_BUFLEN_IN][15];
		/* 待稽核文件名 */
	char    asChkFileName[PICK_CHECK_LOG_BUFLEN_IN][81];
		/* 待稽核记录 */
	int     aiChkCnt[PICK_CHECK_LOG_BUFLEN_IN];
		/* 系统处理记录 */
	int     aiPreCnt[PICK_CHECK_LOG_BUFLEN_IN];
		/* 文件类型 */
	char    asFileType[PICK_CHECK_LOG_BUFLEN_IN][6];
		/* 处理时间 */
	char    asDealDate[PICK_CHECK_LOG_BUFLEN_IN][15];
};


/*单个结构申明*/
struct PickCheckLogStruct{

	struct PickCheckLogStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	char    sModule[4];		/* 业务模块 */
	char    sFileName[81];		/* 文件名 */
	char    sFileDate[15];		/* 文件日期 */
	char    sChkFileName[81];		/* 待稽核文件名 */
	int     iChkCnt;		/* 待稽核记录 */
	int     iPreCnt;		/* 系统处理记录 */
	char    sFileType[6];		/* 文件类型 */
	char    sDealDate[15];		/* 处理时间 */
	struct PickCheckLogStruct *pLoadNext;
};

/*批量数据结构缓冲写入PICK_CHECK_LOG*/
int EInsertStructToPickCheckLog(struct PickCheckLogStruct *p,
	int iInsertFlag,struct PickCheckLogStructOut *pTarget);
int SDGetPickCheckLogToStruct(struct PickCheckLogStruct *p,char sTableName[],char sCondition[]);

int PutLogCheck(char sSourceID[20],char sFileName[80],int iChkDays);
int InsertPutLog(char sSourceID[],int iSize,char sFileName[],
	char sDealBeginDate[], char sDealEndDate[],int iSeq,
	char sFileType[],int iTacheID,char sAppID[]);

int SDGetTabCnt(char sTableName[]);

#endif
