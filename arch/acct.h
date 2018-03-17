/*---------ͷ�ļ����� acct.h----------*/
#ifndef __ACCT_H__
#define __ACCT_H__

/*�����ļ�*/
#include <stdio.h>
#include <sqlca.h>
#include <datatype.h>
#include <trie.h>
#include <list.h>
/*����һ��64λ������*/
/*typedef long LONGINT;*/
/*ORACLE���ú궨��*/
#ifndef NoDataFetched
#define NoDataFetched (sqlca.sqlcode==1403||sqlca.sqlcode==100)
#endif
#ifndef FetchColNum
#define FetchColNum   (sqlca.sqlerrd[2])
#endif


/*�����ṹ����*/
struct AcctStruct{

	struct AcctStruct *pNext;
	char    sAcctID[11];
	int     iAcctSeqNbr;
	int     iBranchID;
	char    sPaymentMethod[4];
	char    sAcctNbr[31];
	char    sBankAcct[31];
	int	    iQuota;
	int     iCreditGrade;
	int	    iBalance;
	int	    iChange;
	char    sCreatedDate[15];
	char    sState[4];
	char    sStateDate[15];
};
/* ����ṹ��������*/
struct AcctStructIn{

#ifndef ACCT_BUFLEN_IN
#define ACCT_BUFLEN_IN		300
#endif

	struct AcctStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[256];
	char    asAcctID[ACCT_BUFLEN_IN][11];
	int     aiAcctSeqNbr[ACCT_BUFLEN_IN];
	int     aiBranchID[ACCT_BUFLEN_IN];
	char    asPaymentMethod[ACCT_BUFLEN_IN][4];
	char    asAcctNbr[ACCT_BUFLEN_IN][31];
	char    asBankAcct[ACCT_BUFLEN_IN][31];
	int     aiQuota[ACCT_BUFLEN_IN];
	int     aiCreditGrade[ACCT_BUFLEN_IN];
	int     aiBalance[ACCT_BUFLEN_IN];
	int     aiChange[ACCT_BUFLEN_IN];
	char    asCreatedDate[ACCT_BUFLEN_IN][15];
	char    asState[ACCT_BUFLEN_IN][4];
	char    asStateDate[ACCT_BUFLEN_IN][15];
};
/*˽��ͳ�Ʊ�*/
struct StatAcctHead{

	int iAcctIDNodeCnt;

	TRIE *pAcctIDTrie;
	
	char sUpdateTime[15];
	
	int iAcctCnt;
	struct AcctStruct *pAcctList;
};

/*�����ݵ�ȡ��*/
int EGetAcctToStruct(struct AcctStruct *p,struct AcctStructIn *pSource);

int  CheckShmAcctEffect();
void DestroyAcctStatList();
int  MountingUpdatedAcctToMem();
int  MountingTotalAcctToMem();
int  BuildAcctTemporaryPrimaryIndex();
int  DestroyAcctTemporaryPrimaryIndex();
int  CountingAcctCurDeleteRecord();
int  CountingAcctIncrementRecord();
int  GetAcctTotalBufRecord();
int  CountingAcctIncrementNode();
int  GetAcctTotalBufNode();
int  LockAcctShm();
void UnlockAcctShm();
void TruncateAcctShmIndexAndRetriveNode();
int  RebuildAcctShmCurIndexAndRetriveExpireRecord();
int  BuildAcctMemListIndexAndMoveToShm();
int  AcctSemWorking();
int  ClientAcctUnmountNotify();
int  ClientAcctConnectNotify();
int  CountingAcctTotalRecord();
int  StatAcctTotalNode();
int  InitAcctControlRecord();
void CopyAcctControlToShm();


#endif
