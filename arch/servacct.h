/*---------ͷ�ļ����� serv_acct.h----------*/
#ifndef __SERV_ACCT_H__
#define __SERV_ACCT_H__

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

/*�����ṹ����*/
struct ServAcctStruct{

	struct ServAcctStruct *pNext;
	char    sAcctID[11];
	int     iAcctSeqNbr;
	int     iAcctItemTypeID;
	char    sServID[11];
	int     iServSeqNbr;
	char    sState[4];
	char    sStateDate[15];
};

/* ����ṹ��������*/
struct ServAcctStructIn{

#ifndef SERV_ACCT_BUFLEN_IN
#define SERV_ACCT_BUFLEN_IN		300
#endif

	struct ServAcctStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[256];
	char    asAcctID[SERV_ACCT_BUFLEN_IN][11];
	int     aiAcctSeqNbr[SERV_ACCT_BUFLEN_IN];
	int     aiAcctItemTypeID[SERV_ACCT_BUFLEN_IN];
	char    asServID[SERV_ACCT_BUFLEN_IN][11];
	int     aiServSeqNbr[SERV_ACCT_BUFLEN_IN];
	char    asState[SERV_ACCT_BUFLEN_IN][4] ;
	char    asStateDate[SERV_ACCT_BUFLEN_IN][15];
};


struct StatServAcctHead{

	int iServIDNodeCnt;
	TRIE *pServIDTrie;
	
	char  	sUpdateTime[15];	/*�ϴθ���ʱ��*/
	int iServAcctCnt;
	struct ServAcctStruct *pServAcctList;
};

/*�����ݵ�ȡ��*/
int EGetServAcctToStruct(struct ServAcctStruct *p,
	struct ServAcctStructIn *pSource);

/*****�����ϸ���ͨ�ù��̼��غ����ӿ�***/
int  CheckShmServAcctEffect();
void DestroyServAcctStatList();
int  MountingUpdatedServAcctToMem();
int  MountingTotalServAcctToMem();
int  BuildServAcctTemporaryPrimaryIndex();
int  DestroyServAcctTemporaryPrimaryIndex();
int  CountingServAcctCurDeleteRecord();
int  CountingServAcctIncrementRecord();
int  GetServAcctTotalBufRecord();
int  CountingServAcctIncrementNode();
int  GetServAcctTotalBufNode();
int  LockServAcctShm();
void UnlockServAcctShm();
void TruncateServAcctShmIndexAndRetriveNode();
int  RebuildServAcctShmCurIndexAndRetriveExpireRecord();
int  BuildServAcctMemListIndexAndMoveToShm();
int  ServAcctSemWorking();
int  ClientServAcctUnmountNotify();
int  ClientServAcctConnectNotify();
int  CountingServAcctTotalRecord();
int  StatServAcctTotalNode();
int  InitServAcctControlRecord();
void CopyServAcctControlToShm();


#endif
