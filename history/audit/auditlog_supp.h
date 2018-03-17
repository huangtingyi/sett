#ifndef __AUDITLOG_SUPP_H__
#define __AUDITLOG_SUPP_H__

struct AuditParamStruct
{
	char sType[2];
	char sSerialNbr[20];
	int  iFlowID;
	int  iPreTacheID;
	int  iTacheID;
	char sSourceID[7];
	char sBeginDate[9];
	char sEndDate[9];
	int  iStaffID;
	char sPreAppLog[40];
	char sAppLog[40];
};

/* 输入结构缓冲申明*/
struct BillingProcLogStructIn{

#ifndef BILLING_PROC_LOG_BUFLEN_IN
#define BILLING_PROC_LOG_BUFLEN_IN		300
#endif

	struct BillingProcLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiInputID[BILLING_PROC_LOG_BUFLEN_IN];
	char    asSourceID[BILLING_PROC_LOG_BUFLEN_IN][7];
	char    asModule[BILLING_PROC_LOG_BUFLEN_IN][4];
	char    asFileName[BILLING_PROC_LOG_BUFLEN_IN][81];
	char    asSplitStr[BILLING_PROC_LOG_BUFLEN_IN][11];
	int     aiByte[BILLING_PROC_LOG_BUFLEN_IN];
	int     aiCnt[BILLING_PROC_LOG_BUFLEN_IN];
	char    asDealBeginDate[BILLING_PROC_LOG_BUFLEN_IN][15];
	char    asDealEndDate[BILLING_PROC_LOG_BUFLEN_IN][15];
	char    asFileType[BILLING_PROC_LOG_BUFLEN_IN][6];
	char    asAppCode[BILLING_PROC_LOG_BUFLEN_IN][9];
	char    asAppID[BILLING_PROC_LOG_BUFLEN_IN][11];
	int     aiTacheID[BILLING_PROC_LOG_BUFLEN_IN];
};

/* 输入结构缓冲申明*/
struct AcctLogStructIn{

#ifndef ACCT_LOG_BUFLEN_IN
#define ACCT_LOG_BUFLEN_IN		300
#endif

	struct AcctLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[ACCT_LOG_BUFLEN_IN][7];
	char    asModule[ACCT_LOG_BUFLEN_IN][4];
	char    asState[ACCT_LOG_BUFLEN_IN][2];
	int     aiByte[ACCT_LOG_BUFLEN_IN];
	int     aiCnt[ACCT_LOG_BUFLEN_IN];
	char    asFileName[ACCT_LOG_BUFLEN_IN][81];
	char    asTableName[ACCT_LOG_BUFLEN_IN][31];
	char    asDealBeginDate[ACCT_LOG_BUFLEN_IN][15];
	char    asDealEndDate[ACCT_LOG_BUFLEN_IN][15];
	char    asDataDate[ACCT_LOG_BUFLEN_IN][15];
	char    asOperType[ACCT_LOG_BUFLEN_IN][4];
	char    asFileType[ACCT_LOG_BUFLEN_IN][6];
	char    asAppID[ACCT_LOG_BUFLEN_IN][11];
	int     aiTacheID[ACCT_LOG_BUFLEN_IN];
};

/* 输入结构缓冲申明*/
struct UpdataProcLogStructIn{

#ifndef UPDATA_PROC_LOG_BUFLEN_IN
#define UPDATA_PROC_LOG_BUFLEN_IN		300
#endif

	struct UpdataProcLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asOriFileName[UPDATA_PROC_LOG_BUFLEN_IN][81];
	char    asCurFileName[UPDATA_PROC_LOG_BUFLEN_IN][81];
	int     aiByte[UPDATA_PROC_LOG_BUFLEN_IN];
	int     aiRecCnt[UPDATA_PROC_LOG_BUFLEN_IN];
	char    asFileDate[UPDATA_PROC_LOG_BUFLEN_IN][15];
	char    asAppID[UPDATA_PROC_LOG_BUFLEN_IN][11];
	int     aiTacheID[UPDATA_PROC_LOG_BUFLEN_IN];
};

/* 输入结构缓冲申明*/
struct UpdataLogStructIn{

#ifndef UPDATA_LOG_BUFLEN_IN
#define UPDATA_LOG_BUFLEN_IN		300
#endif

	struct UpdataLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiUpdataID[UPDATA_LOG_BUFLEN_IN];
	char    asFileType[UPDATA_LOG_BUFLEN_IN][6];
	char    asFileName[UPDATA_LOG_BUFLEN_IN][81];
	char    asBeginTime[UPDATA_LOG_BUFLEN_IN][15];
	char    asEndTime[UPDATA_LOG_BUFLEN_IN][15];
	int     aiRecCnt[UPDATA_LOG_BUFLEN_IN];
	int     aiTotalCharge[UPDATA_LOG_BUFLEN_IN];
	char    asDataDate[UPDATA_LOG_BUFLEN_IN][15];
	char    asDealBeginDate[UPDATA_LOG_BUFLEN_IN][15];
	char    asDealEndDate[UPDATA_LOG_BUFLEN_IN][15];
	char    asAppID[UPDATA_LOG_BUFLEN_IN][11];
	int     aiTacheID[UPDATA_LOG_BUFLEN_IN];
};

/*单个结构申明*/
struct LogAuditStruct{

	struct LogAuditStruct *pNext;
	int     iFlowID;
	int     iPreTacheID;
	int     iTacheID;
	char    sType[2];
	char    sSourceID[7];
	int     iCnt;
	int     iAbnoCnt;
	char    sBeginDate[15];
	char    sEndDate[15];
	char    sDataDate[15];
	int     iStaffID;
	char    sSerialNbr[21];
	struct LogAuditStruct *pLoadNext;
};

/*输出结构缓冲申明*/
struct LogAuditStructOut{

#ifndef LOG_AUDIT_BUFLEN_OUT
#define LOG_AUDIT_BUFLEN_OUT		300
#endif

	struct LogAuditStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiFlowID[LOG_AUDIT_BUFLEN_OUT];
	int     aiPreTacheID[LOG_AUDIT_BUFLEN_OUT];
	int     aiTacheID[LOG_AUDIT_BUFLEN_OUT];
	char    asType[LOG_AUDIT_BUFLEN_OUT][2];
	char    asSourceID[LOG_AUDIT_BUFLEN_OUT][7];
	int     aiCnt[LOG_AUDIT_BUFLEN_OUT];
	int     aiAbnoCnt[LOG_AUDIT_BUFLEN_OUT];
	char    asBeginDate[LOG_AUDIT_BUFLEN_OUT][15];
	char    asEndDate[LOG_AUDIT_BUFLEN_OUT][15];
	char    asDataDate[LOG_AUDIT_BUFLEN_OUT][15];
	int     aiStaffID[LOG_AUDIT_BUFLEN_OUT];
	char    asSerialNbr[LOG_AUDIT_BUFLEN_OUT][21];
};

/*单个结构申明*/
struct LogAuditDetailStruct{

	struct LogAuditDetailStruct *pNext;
	int     iFlowID;
	int     iPreTacheID;
	int     iTacheID;
	char    sSourceID[7];
	char    sFileName[81];
	int     iByte;
	int     iCnt;
	char    sType[2];
	char    sBeginDate[15];
	char    sEndDate[15];
	char    sDataDate[15];
	int     iStaffID;
	char    sSerialNbr[21];
	struct LogAuditDetailStruct *pLoadNext;
};
/*输出结构缓冲申明*/
struct LogAuditDetailStructOut{

#ifndef LOG_AUDIT_DETAIL_BUFLEN_OUT
#define LOG_AUDIT_DETAIL_BUFLEN_OUT		300
#endif

	struct LogAuditDetailStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiFlowID[LOG_AUDIT_DETAIL_BUFLEN_OUT];
	int     aiPreTacheID[LOG_AUDIT_DETAIL_BUFLEN_OUT];
	int     aiTacheID[LOG_AUDIT_DETAIL_BUFLEN_OUT];
	char    asSourceID[LOG_AUDIT_DETAIL_BUFLEN_OUT][7];
	char    asFileName[LOG_AUDIT_DETAIL_BUFLEN_OUT][81];
	int     aiByte[LOG_AUDIT_DETAIL_BUFLEN_OUT];
	int     aiCnt[LOG_AUDIT_DETAIL_BUFLEN_OUT];
	char    asType[LOG_AUDIT_DETAIL_BUFLEN_OUT][2];
	char    asBeginDate[LOG_AUDIT_DETAIL_BUFLEN_OUT][15];
	char    asEndDate[LOG_AUDIT_DETAIL_BUFLEN_OUT][15];
	char    asDataDate[LOG_AUDIT_DETAIL_BUFLEN_OUT][15];
	int     aiStaffID[LOG_AUDIT_DETAIL_BUFLEN_OUT];
	char    asSerialNbr[LOG_AUDIT_DETAIL_BUFLEN_OUT][21];
};

/*批量数据结构缓冲写入LOG_AUDIT_DETAIL*/
int EInsertStructToLogAuditDetail(struct LogAuditDetailStruct *p,
	int iInsertFlag,struct LogAuditDetailStructOut *pTarget);
/*批量数据结构缓冲写入LOG_AUDIT*/
int EInsertStructToLogAudit(struct LogAuditStruct *p,
	int iInsertFlag,struct LogAuditStructOut *pTarget);
/*加载审核日志表*/
int MountPickLog(struct PickLogStruct **pptHead,char sCondition[]);
int MountPrepLog(struct PrepLogStruct **pptHead,char sCondition[]);
int MountPrepProcLog(struct PrepProcLogStruct **pptHead,char sCondition[]);
int MountBillingLog(struct BillingLogStruct **pptHead,char sCondition[]);
int MountBillingProcLog(struct BillingProcLogStruct **pptHead,char sCondition[]);
int MountInsertLog(struct AcctLogStruct **pptHead,char sCondition[]);
int MountUpdataProcLog(struct UpdataProcLogStruct **pptHead,char sCondition[]);
int MountUpdataLog(struct UpdataLogStruct **pptHead,char sCondition[]);
int MountAcctLog(struct AcctLogStruct **pptHead,char sTableName[],char sCondition[]);

int InsertLogAuditDetail(struct LogAuditDetailStruct *ptHead);
int InsertLogAudit(struct LogAuditStruct *ptHead);

void DestroyPickLog(struct PickLogStruct *ptHead);

void AuditPickPrep(struct AuditParamStruct *pAuditParam);
void AuditPrepBilling(struct AuditParamStruct *pAuditParam);
void AuditBillingInsert(struct AuditParamStruct *pAuditParam);
void AuditPrepInsert(struct AuditParamStruct *pAuditParam);
void AuditBillingAcct(struct AuditParamStruct *pAuditParam);
void AuditBillingUpdata(struct AuditParamStruct *pAuditParam);
void AuditUpdataAcct(struct AuditParamStruct *pAuditParam);

#endif
