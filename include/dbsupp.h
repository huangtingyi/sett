#ifndef __DBSUPP_H__
#define __DBSUPP_H__

/*�����ṹ����*/
struct AcctLogStruct{

	struct AcctLogStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	char    sModule[4];		/* ģ���ʶ */
	char    sState[2];		/* ״̬ */
	int     iByte;		/* �ֽ��� */
	int     iCnt;		/* ��ȷ��¼�� */
	char    sFileName[81];		/* �ļ��� */
	char    sTableName[31];		/* Ŀ����� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	char    sDataDate[15];		/* ���ݹ������� */
	char	sOperType[4];
	char    sFileType[6];		/* �ļ����� */
	int     iTacheID;		/* ���ڱ�ʶ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	struct AcctLogStruct *pLoadNext;
};



/*�����ṹ����*/
struct PickLogStruct{

	struct PickLogStruct *pNext;
	int     iInputID;		/* �ļ���ʶ */
	char    sSourceID[7];		/* ��Դ */
	int     iByte;		/* �ֽ��� */
	char    sFileName[81];		/* �ļ��� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	int     iSeq;		/* ԭʼ��� */
	char    sState[2];		/* ״̬ */
	char    sFileType[6];		/* �ļ����� */
	int     iTacheID;		/* ���ڱ�ʶ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	struct PickLogStruct *pLoadNext;
};

/*�����ṹ����*/
struct PrepLogStruct{

	struct PrepLogStruct *pNext;
	int     iInputID;		/* �ļ���ʶ */
	char    sSourceID[7];		/* ��Դ */
	char    sModule[4];		/* ģ���ʶ */
	char    sState[2];		/* ״̬ */
	int     iCnt;		/* ��ȷ��¼�� */
	char    sFileName[41];		/* �ļ��� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	char    sDataDate[15];		/* ���ݹ������� */
	int     iSeq;		/* �ļ���� */
	char    sOriFileName[81];		/* ԭʼ�ļ��� */
	char    sFileType[6];		/* �ļ����� */
	char    sAppID[11];
	int     iTacheID;
	struct PrepLogStruct *pLoadNext;
};
/*�����ṹ����*/
struct PrepProcLogStruct{

	struct PrepProcLogStruct *pNext;
	int     iInputID;		/* ������ˮ */
	char    sSourceID[7];		/* �ļ���Դ */
	char    sModule[4];		/* ����ģ�� */
	int     iByte;		/* �����ļ��ֽ��� */
	int     iCnt;		/* �����ļ���¼�� */
	char    sFileName[81];		/* �����ļ��� */
	char    sDealBeginDate[15];		/* ������ʼʱ�� */
	char    sDealEndDate[15];		/* ������ֹʱ�� */
	int	iNormalCnt;
	int	iErrCnt;
	int	iDupCnt;
	int	iAbnoCnt;
	int	iNewCnt;
	char    sFileType[6];		/* �ļ����� */
	char    sAppID[11];
	int     iTacheID;
	struct PrepProcLogStruct *pLoadNext;
};

/*�����ṹ����*/
struct BillingLogStruct{

	struct BillingLogStruct *pNext;
	int     iInputID;		/* �ļ���ʶ */
	char    sSourceID[7];		/* ��Դ */
	char    sModule[4];		/* ģ���ʶ */
	char    sState[2];		/* ״̬ */
	int     iCnt;		/* ��ȷ��¼�� */
	char    sFileName[41];		/* �ļ��� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	char    sDataDate[15];		/* ���ݹ������� */
	int     iSeq;		/* �ļ���� */
	char    sOriFileName[81];		/* ԭʼ�ļ��� */
	char    sFileType[6];		/* �ļ����� */
	char	sAppCode[9];
	int     iTacheID;		/* ���ڱ�ʶ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	struct BillingLogStruct *pLoadNext;
};


/* ����ṹ��������*/
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
		/* �ļ���ʶ */
	int     aiInputID[BILLING_LOG_BUFLEN_IN];
		/* ��Դ */
	char    asSourceID[BILLING_LOG_BUFLEN_IN][7];
		/* ģ���ʶ */
	char    asModule[BILLING_LOG_BUFLEN_IN][4];
		/* ״̬ */
	char    asState[BILLING_LOG_BUFLEN_IN][2];
		/* ��ȷ��¼�� */
	int     aiCnt[BILLING_LOG_BUFLEN_IN];
		/* �ļ��� */
	char    asFileName[BILLING_LOG_BUFLEN_IN][41];
		/* ����ʼʱ�� */
	char    asDealBeginDate[BILLING_LOG_BUFLEN_IN][15];
		/* �������ʱ�� */
	char    asDealEndDate[BILLING_LOG_BUFLEN_IN][15];
		/* ���ݹ������� */
	char    asDataDate[BILLING_LOG_BUFLEN_IN][15];
		/* �ļ���� */
	int     aiSeq[BILLING_LOG_BUFLEN_IN];
		/* ԭʼ�ļ��� */
	char    asOriFileName[BILLING_LOG_BUFLEN_IN][81];
		/* �ļ����� */
	char    asFileType[BILLING_LOG_BUFLEN_IN][6];
		/* ���ڱ�ʶ */
	int     aiTacheID[BILLING_LOG_BUFLEN_IN];
		/* Ӧ�ñ�ʶ */
	char    asAppID[BILLING_LOG_BUFLEN_IN][11];
};

/*�����ṹ����*/
struct RollProcLogStruct{

	struct RollProcLogStruct *pNext;
	int     iInputID;		/* �ļ���ʶ */
	char    sSourceID[7];		/* ��Դ */
	char    sModule[4];		/* ģ���ʶ */
	char    sState[2];		/* ״̬ */
	int     iCnt;		/* ��ȷ��¼�� */
	char    sFileName[41];		/* ����ļ� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	char    sOriFileName[81];		/* ԭʼ�ļ��� */
	char    sFileType[6];		/* �ļ����� */
	char	sAppCode[9];
	char    sAppID[11];
	int     iTacheID;
	struct RollProcLogStruct *pLoadNext;
};
/*�����ṹ����*/
struct RollLogStruct{

	struct RollLogStruct *pNext;
	int     iInputID;		/* �ļ���ʶ */
	char    sSourceID[7];		/* ��Դ */
	char    sModule[4];		/* ģ���ʶ */
	char    sState[2];		/* ״̬ */
	char    sFileName[81];		/* �ļ��� */
	int     iCnt;		/* ��¼�� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	char    sDataDate[15];		/* ���ݹ������� */
	int     iSeq;		/* �ļ���� */
	char    sFileType[6];		/* �ļ����� */
	char	sAppCode[9];
	char    sAppID[11];
	int     iTacheID;
	struct RollLogStruct *pLoadNext;
};

/*�����ݵ�д��*/
int SDInsertStructToRollProcLog(struct RollProcLogStruct *p,char sTableName[]);
int SDInsertStructToRollLog(struct RollLogStruct *p,char sTableName[]);

/*�������ݶ�̬��PROC_LOG���ýṹ���巽ʽȡ����*/
int EGetBillingLogToStruct(struct BillingLogStruct *p,struct BillingLogStructIn *pSource);


/*�������ݶ�̬��PROC_LOG���ýṹ���巽ʽȡ����*/
int EGetBillingLogToStruct(struct BillingLogStruct *p,struct BillingLogStructIn *pSource);


/*�����ݵ�ȡ��*/
int SDGetAcctLogToStruct(struct AcctLogStruct *p,char sTableName[],char sCondition[]);
/*�����ݵ�д��*/
int SDInsertStructToAcctLog(struct AcctLogStruct *p,char sTableName[]);
/*�����ݵ�ȡ��*/
int SDGetPickLogToStruct(struct PickLogStruct *p,char sTableName[],char sCondition[]);
/*�����ݵ�д��*/
int SDInsertStructToPickLog(struct PickLogStruct *p,char sTableName[]);
/*�����ݵ�ȡ��*/
int SDGetPrepProcLogToStruct(struct PrepProcLogStruct *p,char sTableName[],char sCondition[]);
int SDGetPrepLogToStruct(struct PrepLogStruct *p,char sTableName[],char sCondition[]);
/*��PREP_PROC_LOG��д��*/
int SDInsertStructToPrepProcLog(struct PrepProcLogStruct *p,char sTableName[]);
/*��PREP_LOG��д��*/
int SDInsertStructToPrepLog(struct PrepLogStruct *p,char sTableName[]);
/*�����ݵ�ȡ��*/
int SDGetBillingLogToStruct(struct BillingLogStruct *p,char sTableName[],char sCondition[]);
/*�����ݵ�д��*/
int SDInsertStructToBillingLog(struct BillingLogStruct *p,char sTableName[]);

/*�����ṹ����*/
struct UpdataLogStruct{

	struct UpdataLogStruct *pNext;
	int     iUpdataID;		/* �ļ���� */
	char    sFileType[6];		/* �ļ����� */
	char    sFileName[81];		/* �ļ��� */
	char    sBeginTime[15];		/* �״�ͨ��ʱ�� */
	char    sEndTime[15];		/* ĩ��ͨ��ʱ�� */
	int     iRecCnt;		/* ��¼�� */
	int     iTotalCharge;		/* �ܷ��� */
	char    sDataDate[15];		/* ���ݹ������� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	char	sAppID[11];
	int	iTacheID;
	struct UpdataLogStruct *pLoadNext;
};
/*�����ṹ����*/
struct UpdataProcLogStruct{

	struct UpdataProcLogStruct *pNext;
	char    sOriFileName[81];		/* �����ļ��� */
	char    sCurFileName[81];		/* ����ļ��� */
	int     iByte;		/* �����ļ��ֽ��� */
	int     iRecCnt;		/* �����ļ���¼�� */
	char    sFileDate[15];		/* �ļ��޸����� */
	char	sAppID[11];
	int	iTacheID;
	struct UpdataProcLogStruct *pLoadNext;
};
/*�������ݴ��ö�̬SQL��UPDATA_LOGȡ����*/
int SDGetUpdataLogToStruct(struct UpdataLogStruct *p,char sTableName[],char sCondition[]);
/*�������ݶ�̬SQL��UPDATA_LOGд����*/
int SDInsertStructToUpdataLog(struct UpdataLogStruct *p,char sTableName[]);
/*�������ݴ��ö�̬SQL��UPDATA_PROC_LOGȡ����*/
int SDGetUpdataProcLogToStruct(struct UpdataProcLogStruct *p,char sTableName[],char sCondition[]);
/*�������ݶ�̬SQL��UPDATA_PROC_LOGд����*/
int SDInsertStructToUpdataProcLog(struct UpdataProcLogStruct *p,char sTableName[]);

int GetLastDateSeq(char sFileType[],char sDataDate[],int *piSeq);
int GetLastSeqComm(char sFileType[],int *piSeq);
int GetLastSeq(char sFileType[],char sDataDate[],int *piSeq);

/*ȡCDMA1X�ϴ���һ���к�*/
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

/*ϵͳ��ز���*/
int GetTablespaceUsedPercent(char sTableSpaceName[31]);
void PrintErrTicket(char sTableName[],int iMaxCnt);
void PrintMissTrunk(char sTableName[],int iMaxCnt);
void PrintInsertLogCnt(char sSourceID[10],int iDay);
int PrintDataDelay(char sType[],char sTableName[31]);
void GetPickLogDelay(char sSourceID[7],char sDealEndDate[15],int *piDelay);


/* ����ṹ��������*/
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
		/* �ļ���ʶ */
	int     aiInputID[PICK_LOG_BUFLEN_IN];
		/* ��Դ */
	char    asSourceID[PICK_LOG_BUFLEN_IN][7];
		/* �ֽ��� */
	int     aiByte[PICK_LOG_BUFLEN_IN];
		/* �ļ��� */
	char    asFileName[PICK_LOG_BUFLEN_IN][81];
		/* ����ʼʱ�� */
	char    asDealBeginDate[PICK_LOG_BUFLEN_IN][15];
		/* �������ʱ�� */
	char    asDealEndDate[PICK_LOG_BUFLEN_IN][15];
		/* ԭʼ��� */
	int     aiSeq[PICK_LOG_BUFLEN_IN];
		/* ״̬ */
	char    asState[PICK_LOG_BUFLEN_IN][2];
		/* �ļ����� */
	char    asFileType[PICK_LOG_BUFLEN_IN][6];
		/* ���ڱ�ʶ */
	int     aiTacheID[PICK_LOG_BUFLEN_IN];
		/* Ӧ�ñ�ʶ */
	char    asAppID[PICK_LOG_BUFLEN_IN][11];
};

int EGetPickLogToStruct(struct PickLogStruct *p,
	struct PickLogStructIn *pSource);
int InitPickLog(char sSourceID[],char sTableName[],
	struct PickLogStruct **pptHead);
void DestroyPickLog(struct PickLogStruct *ptHead);


/* ����ṹ��������*/
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
		/* �ļ���ʶ */
	int     aiInputID[PREP_LOG_BUFLEN_IN];
		/* ��Դ */
	char    asSourceID[PREP_LOG_BUFLEN_IN][7];
		/* ģ���ʶ */
	char    asModule[PREP_LOG_BUFLEN_IN][4];
		/* ״̬ */
	char    asState[PREP_LOG_BUFLEN_IN][2];
		/* ��ȷ��¼�� */
	int     aiCnt[PREP_LOG_BUFLEN_IN];
		/* �ļ��� */
	char    asFileName[PREP_LOG_BUFLEN_IN][41];
		/* ����ʼʱ�� */
	char    asDealBeginDate[PREP_LOG_BUFLEN_IN][15];
		/* �������ʱ�� */
	char    asDealEndDate[PREP_LOG_BUFLEN_IN][15];
		/* ���ݹ������� */
	char    asDataDate[PREP_LOG_BUFLEN_IN][15];
		/* �ļ���� */
	int     aiSeq[PREP_LOG_BUFLEN_IN];
		/* ԭʼ�ļ��� */
	char    asOriFileName[PREP_LOG_BUFLEN_IN][81];
		/* �ļ����� */
	char    asFileType[PREP_LOG_BUFLEN_IN][6];
	char    asAppID[PREP_LOG_BUFLEN_IN][11];
	int     aiTacheID[PREP_LOG_BUFLEN_IN];
};
/* ����ṹ��������*/
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
		/* ������ˮ */
	int     aiInputID[PREP_PROC_LOG_BUFLEN_IN];
		/* �ļ���Դ */
	char    asSourceID[PREP_PROC_LOG_BUFLEN_IN][7];
		/* ����ģ�� */
	char    asModule[PREP_PROC_LOG_BUFLEN_IN][4];
		/* �����ļ��ֽ��� */
	int     aiByte[PREP_PROC_LOG_BUFLEN_IN];
		/* �����ļ���¼�� */
	int     aiCnt[PREP_PROC_LOG_BUFLEN_IN];
		/* �����ļ��� */
	char    asFileName[PREP_PROC_LOG_BUFLEN_IN][81];
		/* ������ʼʱ�� */
	char    asDealBeginDate[PREP_PROC_LOG_BUFLEN_IN][15];
		/* ������ֹʱ�� */
	char    asDealEndDate[PREP_PROC_LOG_BUFLEN_IN][15];
		/* �ļ����� */
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

/*�����ṹ����*/
struct SettLogStruct{

	struct SettLogStruct *pNext;
	int     iInputID;		/* ��Դ */
	char    sModule[4];		/* ģ���ʶ */
	int     iSettCarrierID;		/* ������� */
	int     iLatnID;		/* ��������ʶ */
	int     iSettCycleID;		/* �������ڱ�ʶ */
	char    sSettItemDate[15];		/* ��������ʱ�� */
	char    sDealBeginDate[15];		/* ����ʼʱ�� */
	char    sDealEndDate[15];		/* �������ʱ�� */
	char    sStep[2];		/* 'D' �ս� 'M' �½� */
	char    sState[2];		/* ״̬ */
	char    sStateDate[15];		/* ״̬ʱ�� */
	struct SettLogStruct *pLoadNext;
};

int SDInsertStructToSettLog(struct SettLogStruct *p,char sTableName[]);
int SDGetSettLogToStruct(struct SettLogStruct *p,char sTableName[],char sCondition[]);


/*�����ṹ����*/
struct ProcCtrlStruct{

	struct ProcCtrlStruct *pNext;
	int     iInputID;		/* �ļ���ʶ */
	char    sFileName[256];		/* �ļ��� */
	char	sCreatedDate[15];
	char	sDealDate[15];
	char    sState[2];		
/* '0' �ļ�������,'1'�ļ�������,'2' �ļ��������,'3'�ļ�����ʧ�� */
	char    sCreateCmd[256];		/* �ļ����� */
	char    sProcCmd[256];		/* �ļ����� */
	struct ProcCtrlStruct *pLoadNext;
};

/*�������ݾ�̬SQL��PROC_CTRLд����*/
int SSInsertStructToProcCtrl(struct ProcCtrlStruct *p);
/*����һ����¼*/
int NewProcCtrl(char sFileName[],char sCreateCmd[]);
/*���ĳ���ļ��Ƿ�����*/
int CheckProcCtrl(char sFileName[]);
/*�����ɵ��ļ�����*/
int BeginProcCtrl(int iInputID);
/*�������ļ���״��д���ļ���¼*/
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

/*�����ṹ����*/
struct BillingProcLogStruct{

	struct BillingProcLogStruct *pNext;
	int     iInputID;		/* ������ˮ */
	char    sSourceID[7];		/* �ļ���Դ */
	char    sModule[4];		/* ����ģ�� */
	char    sFileName[81];		/* �����ļ��� */
	char    sSplitStr[21];		/* ������봮 */
	int     iByte;		/* �����ļ��ֽ��� */
	int     iCnt;		/* �����ļ���¼�� */
	char    sDealBeginDate[15];		/* ������ʼʱ�� */
	char    sDealEndDate[15];		/* ������ֹʱ�� */
	char    sCurFileName[81];
	int     iNormalCnt;
	int     iAbnoCnt;
	int     iNewCnt;
	char    sFileType[6];		/* �ļ����� */
	char	sAppCode[9];
	int     iTacheID;		/* ���ڱ�ʶ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	struct BillingProcLogStruct *pLoadNext;
};

/*�������ݶ�̬SQL��BILLING_PROC_LOGд����*/
int SDInsertStructToBillingProcLog(struct BillingProcLogStruct *p,char sTableName[]);
int GetNextSeq( char sFileType[] );

/*�������ݶ�̬��PREP_LOG���ýṹ���巽ʽȡ����*/
int EGetPrepLogToStruct(struct PrepLogStruct *p,
	struct PrepLogStructIn *pSource);
/*�������ݶ�̬��PREP_PROC_LOG���ýṹ���巽ʽȡ����*/
int EGetPrepProcLogToStruct(struct PrepProcLogStruct *p,
	struct PrepProcLogStructIn *pSource);



/*����ṹ��������*/
struct PickCheckLogStructOut{

#ifndef PICK_CHECK_LOG_BUFLEN_OUT
#define PICK_CHECK_LOG_BUFLEN_OUT		300
#endif

	struct PickCheckLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Դ */
	char    asSourceID[PICK_CHECK_LOG_BUFLEN_OUT][7];
		/* ҵ��ģ�� */
	char    asModule[PICK_CHECK_LOG_BUFLEN_OUT][4];
		/* �ļ��� */
	char    asFileName[PICK_CHECK_LOG_BUFLEN_OUT][81];
		/* �ļ����� */
	char    asFileDate[PICK_CHECK_LOG_BUFLEN_OUT][15];
		/* �������ļ��� */
	char    asChkFileName[PICK_CHECK_LOG_BUFLEN_OUT][81];
		/* �����˼�¼ */
	int     aiChkCnt[PICK_CHECK_LOG_BUFLEN_OUT];
		/* ϵͳ�����¼ */
	int     aiPreCnt[PICK_CHECK_LOG_BUFLEN_OUT];
		/* �ļ����� */
	char    asFileType[PICK_CHECK_LOG_BUFLEN_OUT][6];
		/* ����ʱ�� */
	char    asDealDate[PICK_CHECK_LOG_BUFLEN_OUT][15];
};


/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[PICK_CHECK_LOG_BUFLEN_IN][7];
		/* ҵ��ģ�� */
	char    asModule[PICK_CHECK_LOG_BUFLEN_IN][4];
		/* �ļ��� */
	char    asFileName[PICK_CHECK_LOG_BUFLEN_IN][81];
		/* �ļ����� */
	char    asFileDate[PICK_CHECK_LOG_BUFLEN_IN][15];
		/* �������ļ��� */
	char    asChkFileName[PICK_CHECK_LOG_BUFLEN_IN][81];
		/* �����˼�¼ */
	int     aiChkCnt[PICK_CHECK_LOG_BUFLEN_IN];
		/* ϵͳ�����¼ */
	int     aiPreCnt[PICK_CHECK_LOG_BUFLEN_IN];
		/* �ļ����� */
	char    asFileType[PICK_CHECK_LOG_BUFLEN_IN][6];
		/* ����ʱ�� */
	char    asDealDate[PICK_CHECK_LOG_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct PickCheckLogStruct{

	struct PickCheckLogStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	char    sModule[4];		/* ҵ��ģ�� */
	char    sFileName[81];		/* �ļ��� */
	char    sFileDate[15];		/* �ļ����� */
	char    sChkFileName[81];		/* �������ļ��� */
	int     iChkCnt;		/* �����˼�¼ */
	int     iPreCnt;		/* ϵͳ�����¼ */
	char    sFileType[6];		/* �ļ����� */
	char    sDealDate[15];		/* ����ʱ�� */
	struct PickCheckLogStruct *pLoadNext;
};

/*�������ݽṹ����д��PICK_CHECK_LOG*/
int EInsertStructToPickCheckLog(struct PickCheckLogStruct *p,
	int iInsertFlag,struct PickCheckLogStructOut *pTarget);
int SDGetPickCheckLogToStruct(struct PickCheckLogStruct *p,char sTableName[],char sCondition[]);

int PutLogCheck(char sSourceID[20],char sFileName[80],int iChkDays);
int InsertPutLog(char sSourceID[],int iSize,char sFileName[],
	char sDealBeginDate[], char sDealEndDate[],int iSeq,
	char sFileType[],int iTacheID,char sAppID[]);

int SDGetTabCnt(char sTableName[]);

#endif
