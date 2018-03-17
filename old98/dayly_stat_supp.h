#ifndef __DAYLY_STAT_SUPP_H__
#define __DAYLY_STAT_SUPP_H__

int CheckDaylyStatLog(char sServiceType[],char sDataDate[]);
int SetDaylyStatLog(char sServiceType[],char sDataDate[],char sState[]);


/*����ṹ��������*/
struct DaylySttHourStatStructOut{

#ifndef DAYLY_STT_HOUR_STAT_BUFLEN_OUT
#define DAYLY_STT_HOUR_STAT_BUFLEN_OUT		300
#endif

	struct DaylySttHourStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 ȥ����,02���� */
	char    asCallType[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][3];
		/* ����� */
	char    asVisitAreaCode[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* ������ */
	char    asMsc[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* ���м� */
	char    asTrunkIn[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* ���м����� */
	int     aiTrunkInTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* ���м���Ӫ�� */
	int     aiTrunkInCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asTrunkOut[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][10];
		/* ���м����� */
	int     aiTrunkOutTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* ���м���Ӫ�� */
	int     aiTrunkOutCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* ͳ��Сʱ */
	char    asStartHour[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][11];
		/* ��ʱ�� */
	int     aiTotalSec[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* �������� */
	int     aiIncome[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutcome[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* ��������� */
	int     aiTotalMin[DAYLY_STT_HOUR_STAT_BUFLEN_OUT];
		/* ͳ������ */
	char    asSettItemDate[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][15];
		/* �������� */
	char    asBillingCycleID[DAYLY_STT_HOUR_STAT_BUFLEN_OUT][7];
};



/*UP�ṹ��������*/
struct DaylySttHourStatStructUp{

#ifndef DAYLY_STT_HOUR_STAT_BUFLEN_UP
#define DAYLY_STT_HOUR_STAT_BUFLEN_UP		300
#endif

	struct DaylySttHourStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 ȥ����,02���� */
	char    asCallType[DAYLY_STT_HOUR_STAT_BUFLEN_UP][3];
		/* ����� */
	char    asVisitAreaCode[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* ������ */
	char    asMsc[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* ���м� */
	char    asTrunkIn[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* ���м����� */
	int     aiTrunkInTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* ���м���Ӫ�� */
	int     aiTrunkInCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asTrunkOut[DAYLY_STT_HOUR_STAT_BUFLEN_UP][10];
		/* ���м����� */
	int     aiTrunkOutTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* ���м���Ӫ�� */
	int     aiTrunkOutCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* ͳ��Сʱ */
	char    asStartHour[DAYLY_STT_HOUR_STAT_BUFLEN_UP][11];
		/* ��ʱ�� */
	int     aiTotalSec[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* �������� */
	int     aiIncome[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* ����֧�� */
	int     aiOutcome[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* ��������� */
	int     aiTotalMin[DAYLY_STT_HOUR_STAT_BUFLEN_UP];
		/* ͳ������ */
	char    asSettItemDate[DAYLY_STT_HOUR_STAT_BUFLEN_UP][15];
		/* �������� */
	char    asBillingCycleID[DAYLY_STT_HOUR_STAT_BUFLEN_UP][7];
	char    asRowID[DAYLY_STT_HOUR_STAT_BUFLEN_UP][19];
};

/* ����ṹ��������*/
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
		/* 01 ȥ����,02���� */
	char    asCallType[DAYLY_STT_HOUR_STAT_BUFLEN_IN][3];
		/* ����� */
	char    asVisitAreaCode[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* ������ */
	char    asMsc[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* ���м� */
	char    asTrunkIn[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* ���м����� */
	int     aiTrunkInTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* ���м���Ӫ�� */
	int     aiTrunkInCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asTrunkOut[DAYLY_STT_HOUR_STAT_BUFLEN_IN][10];
		/* ���м����� */
	int     aiTrunkOutTypeID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* ���м���Ӫ�� */
	int     aiTrunkOutCarrID[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* ͳ��Сʱ */
	char    asStartHour[DAYLY_STT_HOUR_STAT_BUFLEN_IN][11];
		/* ��ʱ�� */
	int     aiTotalSec[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* �������� */
	int     aiIncome[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutcome[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* ��������� */
	int     aiTotalMin[DAYLY_STT_HOUR_STAT_BUFLEN_IN];
		/* ͳ������ */
	char    asSettItemDate[DAYLY_STT_HOUR_STAT_BUFLEN_IN][15];
		/* �������� */
	char    asBillingCycleID[DAYLY_STT_HOUR_STAT_BUFLEN_IN][7];
	char    asRowID[DAYLY_STT_HOUR_STAT_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct DaylySttHourStatStruct{

	struct DaylySttHourStatStruct *pNext;
	char    sCallType[3];		/* 01 ȥ����,02���� */
	char    sVisitAreaCode[10];		/* ����� */
	char    sMsc[10];		/* ������ */
	char    sTrunkIn[10];		/* ���м� */
	int     iTrunkInTypeID;		/* ���м����� */
	int     iTrunkInCarrID;		/* ���м���Ӫ�� */
	char    sTrunkOut[10];		/* 1 ����,2ʡ��,3ʡ��,X���� */
	int     iTrunkOutTypeID;		/* ���м����� */
	int     iTrunkOutCarrID;		/* ���м���Ӫ�� */
	char    sStartHour[11];		/* ͳ��Сʱ */
	int     iTotalSec;		/* ��ʱ�� */
	int     iIncome;		/* �������� */
	int     iOutcome;		/* ����֧�� */
	int     iTotalMin;		/* ��������� */
	char    sSettItemDate[15];		/* ͳ������ */
	char    sBillingCycleID[7];		/* �������� */
	char    sRowID[19];             /* ��¼���� */
	struct DaylySttHourStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FDaylySttHourStatStruct{

	char    sCallType[2];		/* 01 ȥ����,02���� */
	char    sVisitAreaCode[9];		/* ����� */
	char    sMsc[9];		/* ������ */
	char    sTrunkIn[9];		/* ���м� */
	char    sTrunkInTypeID[4];		/* ���м����� */
	char    sTrunkInCarrID[4];		/* ���м���Ӫ�� */
	char    sTrunkOut[9];		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    sTrunkOutTypeID[4];		/* ���м����� */
	char    sTrunkOutCarrID[4];		/* ���м���Ӫ�� */
	char    sStartHour[10];		/* ͳ��Сʱ */
	char    sTotalSec[9];		/* ��ʱ�� */
	char    sIncome[9];		/* �������� */
	char    sOutcome[9];		/* ����֧�� */
	char    sTotalMin[9];		/* ��������� */
	char    sSettItemDate[14];		/* ͳ������ */
	char    sBillingCycleID[6];		/* �������� */
};

int data_search_bintree_stt_hour_e(void *pValue,void*pData);
void assign_insert_bintree_stt_hour_e(void **ppData,void *pData);

/*�������ݶ�̬��DAYLY_STT_HOUR_STAT���ýṹ���巽ʽȡ����*/
int EGetDaylySttHourStatToStruct(struct DaylySttHourStatStruct *p,
	struct DaylySttHourStatStructIn *pSource);
/*�������ݽṹ����д��DAYLY_STT_HOUR_STAT*/
int EInsertStructToDaylySttHourStat(struct DaylySttHourStatStruct *p,
	int iInsertFlag,struct DaylySttHourStatStructOut *pTarget);
/*�������ݽṹ�������DAYLY_STT_HOUR_STAT*/
int EUpdateStructToDaylySttHourStat(struct DaylySttHourStatStruct *p,
	int iUpdateFlag,struct DaylySttHourStatStructUp *pTarget);


/*����ṹ��������*/
struct DaylySttStatStructOut{

#ifndef DAYLY_STT_STAT_BUFLEN_OUT
#define DAYLY_STT_STAT_BUFLEN_OUT		300
#endif

	struct DaylySttStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 ȥ����,02���� */
	char    asCallType[DAYLY_STT_STAT_BUFLEN_OUT][3];
		/* ����� */
	char    asVisitAreaCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* �û����� */
	char    asHomeAreaCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* �û�ʡ������ */
	char    asHomeCapitalCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* �Զ˹��� */
	char    asCalledCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* �Զ�ʡ������ */
	char    asCalledCapitalCode[DAYLY_STT_STAT_BUFLEN_OUT][10];
		/* �������� */
	int     aiTicketTypeID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* �������� */
	char    asNetType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asMsisdnUserType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* �ҷ��������� */
	char    asMsisdnNbrType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* �ҷ��ƶ���ͷ */
	char    asMsisdnHead[DAYLY_STT_STAT_BUFLEN_OUT][8];
		/* �ҷ��������� */
	int     aiMsisdnAreaID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* �ҷ��ײ����� */
	char    asMsisdnBillingTypeID[DAYLY_STT_STAT_BUFLEN_OUT][11];
		/* �ҷ���Ӫ�� */
	int     aiMsisdnCarrierID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* �Է��û����� */
	char    asOppUserType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* �Է��������� */
	char    asOppNbrType[DAYLY_STT_STAT_BUFLEN_OUT][2];
		/* �Է��ƶ���ͷ */
	char    asOppHead[DAYLY_STT_STAT_BUFLEN_OUT][8];
		/* �Է����� */
	int     aiOppAreaID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* �Է���Ӫ�� */
	int     aiOppCarrierID[DAYLY_STT_STAT_BUFLEN_OUT];
		/* �������� */
	int     aiIncome[DAYLY_STT_STAT_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutcome[DAYLY_STT_STAT_BUFLEN_OUT];
		/* ��������� */
	int     aiTotalMin[DAYLY_STT_STAT_BUFLEN_OUT];
		/* ͳ������ */
	char    asSettItemDate[DAYLY_STT_STAT_BUFLEN_OUT][15];
		/* �������� */
	char    asBillingCycleID[DAYLY_STT_STAT_BUFLEN_OUT][7];
};


/*���½ṹ��������*/
struct DaylySttStatStructUp{

#ifndef DAYLY_STT_STAT_BUFLEN_UP
#define DAYLY_STT_STAT_BUFLEN_UP		300
#endif

	struct DaylySttStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 ȥ����,02���� */
	char    asCallType[DAYLY_STT_STAT_BUFLEN_UP][3];
		/* ����� */
	char    asVisitAreaCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* �û����� */
	char    asHomeAreaCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* �û�ʡ������ */
	char    asHomeCapitalCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* �Զ˹��� */
	char    asCalledCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* �Զ�ʡ������ */
	char    asCalledCapitalCode[DAYLY_STT_STAT_BUFLEN_UP][10];
		/* �������� */
	int     aiTicketTypeID[DAYLY_STT_STAT_BUFLEN_UP];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[DAYLY_STT_STAT_BUFLEN_UP];
		/* �������� */
	char    asNetType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asMsisdnUserType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* �ҷ��������� */
	char    asMsisdnNbrType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* �ҷ��ƶ���ͷ */
	char    asMsisdnHead[DAYLY_STT_STAT_BUFLEN_UP][8];
		/* �ҷ��������� */
	int     aiMsisdnAreaID[DAYLY_STT_STAT_BUFLEN_UP];
		/* �ҷ��ײ����� */
	char    asMsisdnBillingTypeID[DAYLY_STT_STAT_BUFLEN_UP][11];
		/* �ҷ���Ӫ�� */
	int     aiMsisdnCarrierID[DAYLY_STT_STAT_BUFLEN_UP];
		/* �Է��û����� */
	char    asOppUserType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* �Է��������� */
	char    asOppNbrType[DAYLY_STT_STAT_BUFLEN_UP][2];
		/* �Է��ƶ���ͷ */
	char    asOppHead[DAYLY_STT_STAT_BUFLEN_UP][8];
		/* �Է����� */
	int     aiOppAreaID[DAYLY_STT_STAT_BUFLEN_UP];
		/* �Է���Ӫ�� */
	int     aiOppCarrierID[DAYLY_STT_STAT_BUFLEN_UP];
		/* �������� */
	int     aiIncome[DAYLY_STT_STAT_BUFLEN_UP];
		/* ����֧�� */
	int     aiOutcome[DAYLY_STT_STAT_BUFLEN_UP];
		/* ��������� */
	int     aiTotalMin[DAYLY_STT_STAT_BUFLEN_UP];
		/* ͳ������ */
	char    asSettItemDate[DAYLY_STT_STAT_BUFLEN_UP][15];
		/* �������� */
	char    asBillingCycleID[DAYLY_STT_STAT_BUFLEN_UP][7];
	char    asRowID[DAYLY_STT_STAT_BUFLEN_UP][19];
};


/* ����ṹ��������*/
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
		/* 01 ȥ����,02���� */
	char    asCallType[DAYLY_STT_STAT_BUFLEN_IN][3];
		/* ����� */
	char    asVisitAreaCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* �û����� */
	char    asHomeAreaCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* �û�ʡ������ */
	char    asHomeCapitalCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* �Զ˹��� */
	char    asCalledCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* �Զ�ʡ������ */
	char    asCalledCapitalCode[DAYLY_STT_STAT_BUFLEN_IN][10];
		/* �������� */
	int     aiTicketTypeID[DAYLY_STT_STAT_BUFLEN_IN];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[DAYLY_STT_STAT_BUFLEN_IN];
		/* �������� */
	char    asNetType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asMsisdnUserType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* �ҷ��������� */
	char    asMsisdnNbrType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* �ҷ��ƶ���ͷ */
	char    asMsisdnHead[DAYLY_STT_STAT_BUFLEN_IN][8];
		/* �ҷ��������� */
	int     aiMsisdnAreaID[DAYLY_STT_STAT_BUFLEN_IN];
		/* �ҷ��ײ����� */
	char    asMsisdnBillingTypeID[DAYLY_STT_STAT_BUFLEN_IN][11];
		/* �ҷ���Ӫ�� */
	int     aiMsisdnCarrierID[DAYLY_STT_STAT_BUFLEN_IN];
		/* �Է��û����� */
	char    asOppUserType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* �Է��������� */
	char    asOppNbrType[DAYLY_STT_STAT_BUFLEN_IN][2];
		/* �Է��ƶ���ͷ */
	char    asOppHead[DAYLY_STT_STAT_BUFLEN_IN][8];
		/* �Է����� */
	int     aiOppAreaID[DAYLY_STT_STAT_BUFLEN_IN];
		/* �Է���Ӫ�� */
	int     aiOppCarrierID[DAYLY_STT_STAT_BUFLEN_IN];
		/* �������� */
	int     aiIncome[DAYLY_STT_STAT_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutcome[DAYLY_STT_STAT_BUFLEN_IN];
		/* ��������� */
	int     aiTotalMin[DAYLY_STT_STAT_BUFLEN_IN];
		/* ͳ������ */
	char    asSettItemDate[DAYLY_STT_STAT_BUFLEN_IN][15];
		/* �������� */
	char    asBillingCycleID[DAYLY_STT_STAT_BUFLEN_IN][7];
	char    asRowID[DAYLY_STT_STAT_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct DaylySttStatStruct{

	struct DaylySttStatStruct *pNext;
	char    sCallType[3];		/* 01 ȥ����,02���� */
	char    sVisitAreaCode[10];		/* ����� */
	char    sHomeAreaCode[10];		/* �û����� */
	char    sHomeCapitalCode[10];		/* �û�ʡ������ */
	char    sCalledCode[10];		/* �Զ˹��� */
	char    sCalledCapitalCode[10];		/* �Զ�ʡ������ */
	int     iTicketTypeID;		/* �������� */
	int     iOppCarrID;		/* �Զ���Ӫ�� */
	char    sNetType[2];		/* �������� */
	char    sMsisdnUserType[2];		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    sMsisdnNbrType[2];		/* �ҷ��������� */
	char    sMsisdnHead[8];		/* �ҷ��ƶ���ͷ */
	int     iMsisdnAreaID;		/* �ҷ��������� */
	char    sMsisdnBillingTypeID[11];		/* �ҷ��ײ����� */
	int     iMsisdnCarrierID;		/* �ҷ���Ӫ�� */
	char    sOppUserType[2];		/* �Է��û����� */
	char    sOppNbrType[2];		/* �Է��������� */
	char    sOppHead[8];		/* �Է��ƶ���ͷ */
	int     iOppAreaID;		/* �Է����� */
	int     iOppCarrierID;		/* �Է���Ӫ�� */
	int     iIncome;		/* �������� */
	int     iOutcome;		/* ����֧�� */
	int     iTotalMin;		/* ��������� */
	char    sSettItemDate[15];		/* ͳ������ */
	char    sBillingCycleID[7];		/* �������� */
	char    sRowID[19];             /* ��¼���� */
	struct DaylySttStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FDaylySttStatStruct{

	char    sCallType[2];		/* 01 ȥ����,02���� */
	char    sVisitAreaCode[9];		/* ����� */
	char    sHomeAreaCode[9];		/* �û����� */
	char    sHomeCapitalCode[9];		/* �û�ʡ������ */
	char    sCalledCode[9];		/* �Զ˹��� */
	char    sCalledCapitalCode[9];		/* �Զ�ʡ������ */
	char    sTicketTypeID[4];		/* �������� */
	char    sOppCarrID[4];		/* �Զ���Ӫ�� */
	char    sNetType[1];		/* �������� */
	char    sMsisdnUserType[1];		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    sMsisdnNbrType[1];		/* �ҷ��������� */
	char    sMsisdnHead[7];		/* �ҷ��ƶ���ͷ */
	char    sMsisdnAreaID[4];		/* �ҷ��������� */
	char    sMsisdnBillingTypeID[10];		/* �ҷ��ײ����� */
	char    sMsisdnCarrierID[4];		/* �ҷ���Ӫ�� */
	char    sOppUserType[1];		/* �Է��û����� */
	char    sOppNbrType[1];		/* �Է��������� */
	char    sOppHead[7];		/* �Է��ƶ���ͷ */
	char    sOppAreaID[4];		/* �Է����� */
	char    sOppCarrierID[4];		/* �Է���Ӫ�� */
	char    sIncome[9];		/* �������� */
	char    sOutcome[9];		/* ����֧�� */
	char    sTotalMin[9];		/* ��������� */
	char    sSettItemDate[14];		/* ͳ������ */
	char    sBillingCycleID[6];		/* �������� */
};


int data_search_bintree_dayly_stt_stat_e(void *pValue,void*pData);
void assign_insert_bintree_dayly_stt_stat_e(void **ppData,void *pData);



/*�������ݶ�̬��DAYLY_STT_STAT���ýṹ���巽ʽȡ����*/
int EGetDaylySttStatToStruct(struct DaylySttStatStruct *p,
	struct DaylySttStatStructIn *pSource);
/*�������ݽṹ����д��DAYLY_STT_STAT*/
int EInsertStructToDaylySttStat(struct DaylySttStatStruct *p,
	int iInsertFlag,struct DaylySttStatStructOut *pTarget);
/*�������ݽṹ�������DAYLY_STT_STAT*/
int EUpdateStructToDaylySttStat(struct DaylySttStatStruct *p,
	int iUpdateFlag,struct DaylySttStatStructUp *pTarget);



/*����ṹ��������*/
struct SrtStatStructOut{

#ifndef SRT_STAT_BUFLEN_OUT
#define SRT_STAT_BUFLEN_OUT		300
#endif

	struct SrtStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 ȥ����,02���� */
	char    asCallType[SRT_STAT_BUFLEN_OUT][3];
		/* ����� */
	char    asAreaCode[SRT_STAT_BUFLEN_OUT][10];
		/* �Զ˽���� */
	char    asOppAreaCode[SRT_STAT_BUFLEN_OUT][10];
		/* �Զ˽���ʡ������ */
	char    asOppCapitalCode[SRT_STAT_BUFLEN_OUT][10];
		/* �Զ˺�������� */
	char    asCalledCode[SRT_STAT_BUFLEN_OUT][10];
		/* �Զ˺������ʡ������ */
	char    asCalledCapitalCode[SRT_STAT_BUFLEN_OUT][10];
		/* �������� */
	int     aiTicketTypeID[SRT_STAT_BUFLEN_OUT];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[SRT_STAT_BUFLEN_OUT];
		/* �������� */
	char    asNetType[SRT_STAT_BUFLEN_OUT][2];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asMsisdnUserType[SRT_STAT_BUFLEN_OUT][2];
		/* �û��������� */
	char    asMsisdnNbrType[SRT_STAT_BUFLEN_OUT][2];
		/* �û��ƶ���ͷ */
	char    asMsisdnHead[SRT_STAT_BUFLEN_OUT][8];
		/* �û��������� */
	int     aiMsisdnAreaID[SRT_STAT_BUFLEN_OUT];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[SRT_STAT_BUFLEN_OUT][11];
		/* �Զ��û����� */
	char    asOppUserType[SRT_STAT_BUFLEN_OUT][2];
		/* �Զ˺������� */
	char    asOppNbrType[SRT_STAT_BUFLEN_OUT][2];
		/* �Զ˺�ͷ */
	char    asOppHead[SRT_STAT_BUFLEN_OUT][8];
		/* �Զ����� */
	int     aiOppAreaID[SRT_STAT_BUFLEN_OUT];
		/* �Զ��ײ����� */
	char    asOppBillingTypeID[SRT_STAT_BUFLEN_OUT][11];
		/* ���η� */
	int     aiRoamFee[SRT_STAT_BUFLEN_OUT];
		/* ��;�� */
	int     aiTollFee[SRT_STAT_BUFLEN_OUT];
		/* �������� */
	int     aiIncome[SRT_STAT_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutcome[SRT_STAT_BUFLEN_OUT];
		/* ��������� */
	int     aiTotalMin[SRT_STAT_BUFLEN_OUT];
		/* ͳ������ */
	char    asSettItemDate[SRT_STAT_BUFLEN_OUT][15];
		/* �������� */
	char    asBillingCycleID[SRT_STAT_BUFLEN_OUT][7];
};


/*���½ṹ��������*/
struct SrtStatStructUp{

#ifndef SRT_STAT_BUFLEN_UP
#define SRT_STAT_BUFLEN_UP		300
#endif

	struct SrtStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 01 ȥ����,02���� */
	char    asCallType[SRT_STAT_BUFLEN_UP][3];
		/* ����� */
	char    asAreaCode[SRT_STAT_BUFLEN_UP][10];
		/* �Զ˽���� */
	char    asOppAreaCode[SRT_STAT_BUFLEN_UP][10];
		/* �Զ˽���ʡ������ */
	char    asOppCapitalCode[SRT_STAT_BUFLEN_UP][10];
		/* �Զ˺�������� */
	char    asCalledCode[SRT_STAT_BUFLEN_UP][10];
		/* �Զ˺������ʡ������ */
	char    asCalledCapitalCode[SRT_STAT_BUFLEN_UP][10];
		/* �������� */
	int     aiTicketTypeID[SRT_STAT_BUFLEN_UP];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[SRT_STAT_BUFLEN_UP];
		/* �������� */
	char    asNetType[SRT_STAT_BUFLEN_UP][2];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asMsisdnUserType[SRT_STAT_BUFLEN_UP][2];
		/* �û��������� */
	char    asMsisdnNbrType[SRT_STAT_BUFLEN_UP][2];
		/* �û��ƶ���ͷ */
	char    asMsisdnHead[SRT_STAT_BUFLEN_UP][8];
		/* �û��������� */
	int     aiMsisdnAreaID[SRT_STAT_BUFLEN_UP];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[SRT_STAT_BUFLEN_UP][11];
		/* �Զ��û����� */
	char    asOppUserType[SRT_STAT_BUFLEN_UP][2];
		/* �Զ˺������� */
	char    asOppNbrType[SRT_STAT_BUFLEN_UP][2];
		/* �Զ˺�ͷ */
	char    asOppHead[SRT_STAT_BUFLEN_UP][8];
		/* �Զ����� */
	int     aiOppAreaID[SRT_STAT_BUFLEN_UP];
		/* �Զ��ײ����� */
	char    asOppBillingTypeID[SRT_STAT_BUFLEN_UP][11];
		/* ���η� */
	int     aiRoamFee[SRT_STAT_BUFLEN_UP];
		/* ��;�� */
	int     aiTollFee[SRT_STAT_BUFLEN_UP];
		/* �������� */
	int     aiIncome[SRT_STAT_BUFLEN_UP];
		/* ����֧�� */
	int     aiOutcome[SRT_STAT_BUFLEN_UP];
		/* ��������� */
	int     aiTotalMin[SRT_STAT_BUFLEN_UP];
		/* ͳ������ */
	char    asSettItemDate[SRT_STAT_BUFLEN_UP][15];
		/* �������� */
	char    asBillingCycleID[SRT_STAT_BUFLEN_UP][7];
	char    asRowID[SRT_STAT_BUFLEN_UP][19];
};

/* ����ṹ��������*/
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
		/* 01 ȥ����,02���� */
	char    asCallType[SRT_STAT_BUFLEN_IN][3];
		/* ����� */
	char    asAreaCode[SRT_STAT_BUFLEN_IN][10];
		/* �Զ˽���� */
	char    asOppAreaCode[SRT_STAT_BUFLEN_IN][10];
		/* �Զ˽���ʡ������ */
	char    asOppCapitalCode[SRT_STAT_BUFLEN_IN][10];
		/* �Զ˺�������� */
	char    asCalledCode[SRT_STAT_BUFLEN_IN][10];
		/* �Զ˺������ʡ������ */
	char    asCalledCapitalCode[SRT_STAT_BUFLEN_IN][10];
		/* �������� */
	int     aiTicketTypeID[SRT_STAT_BUFLEN_IN];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[SRT_STAT_BUFLEN_IN];
		/* �������� */
	char    asNetType[SRT_STAT_BUFLEN_IN][2];
		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    asMsisdnUserType[SRT_STAT_BUFLEN_IN][2];
		/* �û��������� */
	char    asMsisdnNbrType[SRT_STAT_BUFLEN_IN][2];
		/* �û��ƶ���ͷ */
	char    asMsisdnHead[SRT_STAT_BUFLEN_IN][8];
		/* �û��������� */
	int     aiMsisdnAreaID[SRT_STAT_BUFLEN_IN];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[SRT_STAT_BUFLEN_IN][11];
		/* �Զ��û����� */
	char    asOppUserType[SRT_STAT_BUFLEN_IN][2];
		/* �Զ˺������� */
	char    asOppNbrType[SRT_STAT_BUFLEN_IN][2];
		/* �Զ˺�ͷ */
	char    asOppHead[SRT_STAT_BUFLEN_IN][8];
		/* �Զ����� */
	int     aiOppAreaID[SRT_STAT_BUFLEN_IN];
		/* �Զ��ײ����� */
	char    asOppBillingTypeID[SRT_STAT_BUFLEN_IN][11];
		/* ���η� */
	int     aiRoamFee[SRT_STAT_BUFLEN_IN];
		/* ��;�� */
	int     aiTollFee[SRT_STAT_BUFLEN_IN];
		/* �������� */
	int     aiIncome[SRT_STAT_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutcome[SRT_STAT_BUFLEN_IN];
		/* ��������� */
	int     aiTotalMin[SRT_STAT_BUFLEN_IN];
		/* ͳ������ */
	char    asSettItemDate[SRT_STAT_BUFLEN_IN][15];
		/* �������� */
	char    asBillingCycleID[SRT_STAT_BUFLEN_IN][7];
	char    asRowID[SRT_STAT_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct SrtStatStruct{

	struct SrtStatStruct *pNext;
	char    sCallType[3];		/* 01 ȥ����,02���� */
	char    sAreaCode[10];		/* ����� */
	char    sOppAreaCode[10];		/* �Զ˽���� */
	char    sOppCapitalCode[10];		/* �Զ˽���ʡ������ */
	char    sCalledCode[10];		/* �Զ˺�������� */
	char    sCalledCapitalCode[10];		/* �Զ˺������ʡ������ */
	int     iTicketTypeID;		/* �������� */
	int     iOppCarrID;		/* �Զ���Ӫ�� */
	char    sNetType[2];		/* �������� */
	char    sMsisdnUserType[2];		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    sMsisdnNbrType[2];		/* �û��������� */
	char    sMsisdnHead[8];		/* �û��ƶ���ͷ */
	int     iMsisdnAreaID;		/* �û��������� */
	char    sMsisdnBillingTypeID[11];		/* �û��ײ����� */
	char    sOppUserType[2];		/* �Զ��û����� */
	char    sOppNbrType[2];		/* �Զ˺������� */
	char    sOppHead[8];		/* �Զ˺�ͷ */
	int     iOppAreaID;		/* �Զ����� */
	char    sOppBillingTypeID[11];		/* �Զ��ײ����� */
	int     iRoamFee;		/* ���η� */
	int     iTollFee;		/* ��;�� */
	int     iIncome;		/* �������� */
	int     iOutcome;		/* ����֧�� */
	int     iTotalMin;		/* ��������� */
	char    sSettItemDate[15];		/* ͳ������ */
	char    sBillingCycleID[7];		/* �������� */
	char    sRowID[19];             /* ��¼���� */
	struct SrtStatStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FSrtStatStruct{

	char    sCallType[2];		/* 01 ȥ����,02���� */
	char    sAreaCode[9];		/* ����� */
	char    sOppAreaCode[9];		/* �Զ˽���� */
	char    sOppCapitalCode[9];		/* �Զ˽���ʡ������ */
	char    sCalledCode[9];		/* �Զ˺�������� */
	char    sCalledCapitalCode[9];		/* �Զ˺������ʡ������ */
	char    sTicketTypeID[4];		/* �������� */
	char    sOppCarrID[4];		/* �Զ���Ӫ�� */
	char    sNetType[1];		/* �������� */
	char    sMsisdnUserType[1];		/* 1 ����,2ʡ��,3ʡ��,X���� */
	char    sMsisdnNbrType[1];		/* �û��������� */
	char    sMsisdnHead[7];		/* �û��ƶ���ͷ */
	char    sMsisdnAreaID[4];		/* �û��������� */
	char    sMsisdnBillingTypeID[10];		/* �û��ײ����� */
	char    sOppUserType[1];		/* �Զ��û����� */
	char    sOppNbrType[1];		/* �Զ˺������� */
	char    sOppHead[7];		/* �Զ˺�ͷ */
	char    sOppAreaID[4];		/* �Զ����� */
	char    sOppBillingTypeID[10];		/* �Զ��ײ����� */
	char    sRoamFee[9];		/* ���η� */
	char    sTollFee[9];		/* ��;�� */
	char    sIncome[9];		/* �������� */
	char    sOutcome[9];		/* ����֧�� */
	char    sTotalMin[9];		/* ��������� */
	char    sSettItemDate[14];		/* ͳ������ */
	char    sBillingCycleID[6];		/* �������� */
};



int data_search_bintree_srt_stat_e(void *pValue,void*pData);
void assign_insert_bintree_srt_stat_e(void **ppData,void *pData);

/*�������ݶ�̬��SRT_STAT���ýṹ���巽ʽȡ����*/
int EGetSrtStatToStruct(struct SrtStatStruct *p,
	struct SrtStatStructIn *pSource);
/*�������ݽṹ����д��SRT_STAT*/
int EInsertStructToSrtStat(struct SrtStatStruct *p,
	int iInsertFlag,struct SrtStatStructOut *pTarget);
/*�������ݽṹ�������SRT_STAT*/
int EUpdateStructToSrtStat(struct SrtStatStruct *p,
	int iUpdateFlag,struct SrtStatStructUp *pTarget);


/*����ṹ��������*/
struct SpcpStatStructOut{

#ifndef SPCP_STAT_BUFLEN_OUT
#define SPCP_STAT_BUFLEN_OUT		300
#endif

	struct SpcpStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����� */
	char    asAreaCode[SPCP_STAT_BUFLEN_OUT][10];
		/* SP���� */
	char    asSpCode[SPCP_STAT_BUFLEN_OUT][11];
		/* SPҵ����� */
	char    asSpServiceCode[SPCP_STAT_BUFLEN_OUT][11];
		/* SP���� */
	char    asSpAccNbr[SPCP_STAT_BUFLEN_OUT][13];
		/* �������� */
	int     aiTicketTypeID[SPCP_STAT_BUFLEN_OUT];
		/* �������� */
	char    asNetType[SPCP_STAT_BUFLEN_OUT][2];
		/* �û���ͷ */
	char    asMsisdnHead[SPCP_STAT_BUFLEN_OUT][8];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[SPCP_STAT_BUFLEN_OUT][11];
		/* ����� */
	int     aiRentFee[SPCP_STAT_BUFLEN_OUT];
		/* ��Ϣ�� */
	int     aiInfoFee[SPCP_STAT_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutcome[SPCP_STAT_BUFLEN_OUT];
		/* �������� */
	char    asBillingCycleID[SPCP_STAT_BUFLEN_OUT][7];
};

/*���½ṹ��������*/
struct SpcpStatStructUp{

#ifndef SPCP_STAT_BUFLEN_UP
#define SPCP_STAT_BUFLEN_UP		300
#endif

	struct SpcpStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����� */
	char    asAreaCode[SPCP_STAT_BUFLEN_UP][10];
		/* SP���� */
	char    asSpCode[SPCP_STAT_BUFLEN_UP][11];
		/* SPҵ����� */
	char    asSpServiceCode[SPCP_STAT_BUFLEN_UP][11];
		/* SP���� */
	char    asSpAccNbr[SPCP_STAT_BUFLEN_UP][13];
		/* �������� */
	int     aiTicketTypeID[SPCP_STAT_BUFLEN_UP];
		/* �������� */
	char    asNetType[SPCP_STAT_BUFLEN_UP][2];
		/* �û���ͷ */
	char    asMsisdnHead[SPCP_STAT_BUFLEN_UP][8];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[SPCP_STAT_BUFLEN_UP][11];
		/* ����� */
	int     aiRentFee[SPCP_STAT_BUFLEN_UP];
		/* ��Ϣ�� */
	int     aiInfoFee[SPCP_STAT_BUFLEN_UP];
		/* ����֧�� */
	int     aiOutcome[SPCP_STAT_BUFLEN_UP];
		/* �������� */
	char    asBillingCycleID[SPCP_STAT_BUFLEN_UP][7];
	char    asRowID[SPCP_STAT_BUFLEN_UP][19];
};


/* ����ṹ��������*/
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
		/* ����� */
	char    asAreaCode[SPCP_STAT_BUFLEN_IN][10];
		/* SP���� */
	char    asSpCode[SPCP_STAT_BUFLEN_IN][11];
		/* SPҵ����� */
	char    asSpServiceCode[SPCP_STAT_BUFLEN_IN][11];
		/* SP���� */
	char    asSpAccNbr[SPCP_STAT_BUFLEN_IN][13];
		/* �������� */
	int     aiTicketTypeID[SPCP_STAT_BUFLEN_IN];
		/* �������� */
	char    asNetType[SPCP_STAT_BUFLEN_IN][2];
		/* �û���ͷ */
	char    asMsisdnHead[SPCP_STAT_BUFLEN_IN][8];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[SPCP_STAT_BUFLEN_IN][11];
		/* ����� */
	int     aiRentFee[SPCP_STAT_BUFLEN_IN];
		/* ��Ϣ�� */
	int     aiInfoFee[SPCP_STAT_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutcome[SPCP_STAT_BUFLEN_IN];
		/* �������� */
	char    asBillingCycleID[SPCP_STAT_BUFLEN_IN][7];
	char    asRowID[SPCP_STAT_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct SpcpStatStruct{

	struct SpcpStatStruct *pNext;
	char    sAreaCode[10];		/* ����� */
	char    sSpCode[11];		/* SP���� */
	char    sSpServiceCode[11];		/* SPҵ����� */
	char    sSpAccNbr[13];		/* SP���� */
	int     iTicketTypeID;		/* �������� */
	char    sNetType[2];		/* �������� */
	char    sMsisdnHead[8];		/* �û���ͷ */
	char    sMsisdnBillingTypeID[11];		/* �û��ײ����� */
	int     iRentFee;		/* ����� */
	int     iInfoFee;		/* ��Ϣ�� */
	int     iOutcome;		/* ����֧�� */
	char    sBillingCycleID[7];		/* �������� */
	char    sRowID[19];             /* ��¼���� */
	struct SpcpStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSpcpStatStruct{

	char    sAreaCode[9];		/* ����� */
	char    sSpCode[10];		/* SP���� */
	char    sSpServiceCode[10];		/* SPҵ����� */
	char    sSpAccNbr[12];		/* SP���� */
	char    sTicketTypeID[4];		/* �������� */
	char    sNetType[1];		/* �������� */
	char    sMsisdnHead[7];		/* �û���ͷ */
	char    sMsisdnBillingTypeID[10];		/* �û��ײ����� */
	char    sRentFee[9];		/* ����� */
	char    sInfoFee[9];		/* ��Ϣ�� */
	char    sOutcome[9];		/* ����֧�� */
	char    sBillingCycleID[6];		/* �������� */
};


int data_search_bintree_spcp_stat_e(void *pValue,void*pData);
void assign_insert_bintree_spcp_stat_e(void **ppData,void *pData);

/*�������ݶ�̬��SPCP_STAT���ýṹ���巽ʽȡ����*/
int EGetSpcpStatToStruct(struct SpcpStatStruct *p,
	struct SpcpStatStructIn *pSource);
/*�������ݽṹ����д��SPCP_STAT*/
int EInsertStructToSpcpStat(struct SpcpStatStruct *p,
	int iInsertFlag,struct SpcpStatStructOut *pTarget);
/*�������ݽṹ�������SPCP_STAT*/
int EUpdateStructToSpcpStat(struct SpcpStatStruct *p,
	int iUpdateFlag,struct SpcpStatStructUp *pTarget);

/*����ṹ��������*/
struct Gprs1xStatStructOut{

#ifndef GPRS_1X_STAT_BUFLEN_OUT
#define GPRS_1X_STAT_BUFLEN_OUT		300
#endif

	struct Gprs1xStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����� */
	char    asAreaCode[GPRS_1X_STAT_BUFLEN_OUT][10];
		/* �Զ˽���� */
	char    asOppAreaCode[GPRS_1X_STAT_BUFLEN_OUT][10];
		/* �������� */
	int     aiTicketTypeID[GPRS_1X_STAT_BUFLEN_OUT];
		/* �������� */
	char    asNetType[GPRS_1X_STAT_BUFLEN_OUT][2];
		/* �û��ƶ���ͷ */
	char    asMsisdnHead[GPRS_1X_STAT_BUFLEN_OUT][8];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[GPRS_1X_STAT_BUFLEN_OUT][11];
		/* ������ */
	int     aiFlowFee[GPRS_1X_STAT_BUFLEN_OUT];
		/* �������� */
	int     aiIncome[GPRS_1X_STAT_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutcome[GPRS_1X_STAT_BUFLEN_OUT];
		/* �������� */
	LONGINT aiDataFlow[GPRS_1X_STAT_BUFLEN_OUT];
		/* ͳ������ */
	char    asSettItemDate[GPRS_1X_STAT_BUFLEN_OUT][15];
		/* �������� */
	char    asBillingCycleID[GPRS_1X_STAT_BUFLEN_OUT][7];
};


/*���½ṹ��������*/
struct Gprs1xStatStructUp{

#ifndef GPRS_1X_STAT_BUFLEN_UP
#define GPRS_1X_STAT_BUFLEN_UP		300
#endif

	struct Gprs1xStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����� */
	char    asAreaCode[GPRS_1X_STAT_BUFLEN_UP][10];
		/* �Զ˽���� */
	char    asOppAreaCode[GPRS_1X_STAT_BUFLEN_UP][10];
		/* �������� */
	int     aiTicketTypeID[GPRS_1X_STAT_BUFLEN_UP];
		/* �������� */
	char    asNetType[GPRS_1X_STAT_BUFLEN_UP][2];
		/* �û��ƶ���ͷ */
	char    asMsisdnHead[GPRS_1X_STAT_BUFLEN_UP][8];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[GPRS_1X_STAT_BUFLEN_UP][11];
		/* ������ */
	int     aiFlowFee[GPRS_1X_STAT_BUFLEN_UP];
		/* �������� */
	int     aiIncome[GPRS_1X_STAT_BUFLEN_UP];
		/* ����֧�� */
	int     aiOutcome[GPRS_1X_STAT_BUFLEN_UP];
		/* �������� */
	LONGINT aiDataFlow[GPRS_1X_STAT_BUFLEN_UP];
		/* ͳ������ */
	char    asSettItemDate[GPRS_1X_STAT_BUFLEN_UP][15];
		/* �������� */
	char    asBillingCycleID[GPRS_1X_STAT_BUFLEN_UP][7];	
	char    asRowID[GPRS_1X_STAT_BUFLEN_UP][19];
};


/* ����ṹ��������*/
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
		/* ����� */
	char    asAreaCode[GPRS_1X_STAT_BUFLEN_IN][10];
		/* �Զ˽���� */
	char    asOppAreaCode[GPRS_1X_STAT_BUFLEN_IN][10];
		/* �������� */
	int     aiTicketTypeID[GPRS_1X_STAT_BUFLEN_IN];
		/* �������� */
	char    asNetType[GPRS_1X_STAT_BUFLEN_IN][2];
		/* �û��ƶ���ͷ */
	char    asMsisdnHead[GPRS_1X_STAT_BUFLEN_IN][8];
		/* �û��ײ����� */
	char    asMsisdnBillingTypeID[GPRS_1X_STAT_BUFLEN_IN][11];
		/* ������ */
	int     aiFlowFee[GPRS_1X_STAT_BUFLEN_IN];
		/* �������� */
	int     aiIncome[GPRS_1X_STAT_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutcome[GPRS_1X_STAT_BUFLEN_IN];
		/* �������� */
	LONGINT aiDataFlow[GPRS_1X_STAT_BUFLEN_IN];
		/* ͳ������ */
	char    asSettItemDate[GPRS_1X_STAT_BUFLEN_IN][15];
		/* �������� */
	char    asBillingCycleID[GPRS_1X_STAT_BUFLEN_IN][7];
	char    asRowID[GPRS_1X_STAT_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct Gprs1xStatStruct{

	struct Gprs1xStatStruct *pNext;
	char    sAreaCode[10];		/* ����� */
	char    sOppAreaCode[10];		/* �Զ˽���� */
	int     iTicketTypeID;		/* �������� */
	char    sNetType[2];		/* �������� */
	char    sMsisdnHead[8];		/* �û��ƶ���ͷ */
	char    sMsisdnBillingTypeID[11];		/* �û��ײ����� */
	int     iFlowFee;		/* ������ */
	int     iIncome;		/* �������� */
	int     iOutcome;		/* ����֧�� */
	LONGINT iDataFlow;		/* �������� */
	char    sSettItemDate[15];		/* ͳ������ */
	char    sBillingCycleID[7];		/* �������� */
	char    sRowID[19];             /* ��¼���� */
	struct Gprs1xStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FGprs1xStatStruct{

	char    sAreaCode[9];		/* ����� */
	char    sOppAreaCode[9];		/* �Զ˽���� */
	char    sTicketTypeID[4];		/* �������� */
	char    sNetType[1];		/* �������� */
	char    sMsisdnHead[7];		/* �û��ƶ���ͷ */
	char    sMsisdnBillingTypeID[10];		/* �û��ײ����� */
	char    sFlowFee[9];		/* ������ */
	char    sIncome[9];		/* �������� */
	char    sOutcome[9];		/* ����֧�� */
	char    sDataFlow[12];		/* �������� */
	char    sSettItemDate[14];		/* ͳ������ */
	char    sBillingCycleID[6];		/* �������� */
};


int data_search_bintree_gprs1x_stat_e(void *pValue,void*pData);
void assign_insert_bintree_gprs1x_stat_e(void **ppData,void *pData);

/*�������ݶ�̬��GPRS_1X_STAT���ýṹ���巽ʽȡ����*/
int EGetGprs1xStatToStruct(struct Gprs1xStatStruct *p,
	struct Gprs1xStatStructIn *pSource);
/*�������ݽṹ����д��GPRS_1X_STAT*/
int EInsertStructToGprs1xStat(struct Gprs1xStatStruct *p,
	int iInsertFlag,struct Gprs1xStatStructOut *pTarget);
/*�������ݽṹ�������GPRS_1X_STAT*/
int EUpdateStructToGprs1xStat(struct Gprs1xStatStruct *p,
	int iUpdateFlag,struct Gprs1xStatStructUp *pTarget);

#endif
