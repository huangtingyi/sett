/*---------头文件代码 serv_acct.h----------*/
#ifndef __SERV_ACCT_H__
#define __SERV_ACCT_H__

/*包含文件*/
#include <stdio.h>
#include <sqlca.h>
#include <datatype.h>
#include <trie.h>
#include <list.h>
/*定义一个64位的类型*/
/*typedef long LONGINT;*/
/*ORACLE引用宏定义*/
#ifndef NoDataFetched
#define NoDataFetched (sqlca.sqlcode==1403||sqlca.sqlcode==100)
#endif
#ifndef FetchColNum
#define FetchColNum   (sqlca.sqlerrd[2])
#endif

/*当个结构定义*/

/*单个结构申明*/
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

/* 输入结构缓冲申明*/
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
	
	char  	sUpdateTime[15];	/*上次更新时间*/
	int iServAcctCnt;
	struct ServAcctStruct *pServAcctList;
};

/*对数据的取出*/
int EGetServAcctToStruct(struct ServAcctStruct *p,
	struct ServAcctStructIn *pSource);

/*****给资料更新通用过程加载函数接口***/
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
