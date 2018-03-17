/*---------ͷ�ļ����� serv.h----------*/
#ifndef __SERV_H__
#define __SERV_H__

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
struct ServStruct{

	struct ServStruct *pNext;
	char    sServID[11];
	int     iServSeqNbr;
	int     iBillingTypeID;
	int     iServTypeID;
	int     iAreaID;
	char    sAccNbrStateID[4];
	int     iStopTypeID;
	int     iCycleTypeID;
	int     iCentrexID;
	int     iInNetType;
	char    sAccNbr[21];
	char    sImsi[21];
	char    sDefaultAcctID[11];
	int     iQuota;			
	int     iSiteID;	
	char    sCompletedDate[15];	
	char    sCreatedDate[15];	
	int     iCreditGrade;		
	char    sState[4];
	char    sStateDate[15];			

	int	iVipFlag;
	
	int	NextOffset;	 /*��һ���������ݵ�ƫ��*/	
	int	iTServCatgID;
	int	iAServCatgID;
	
};

/* ����ṹ��������*/
struct ServStructIn{

#ifndef SERV_BUFLEN_IN
#define SERV_BUFLEN_IN		300
#endif

	struct ServStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];

	char    asServID[SERV_BUFLEN_IN][11];
	int     aiServSeqNbr[SERV_BUFLEN_IN];
	int     aiBillingTypeID[SERV_BUFLEN_IN];
	int     aiServTypeID[SERV_BUFLEN_IN];
	int     aiAreaID[SERV_BUFLEN_IN];
	char    asAccNbrStateID[SERV_BUFLEN_IN][4];
	int     aiStopTypeID[SERV_BUFLEN_IN];
	int     aiCycleTypeID[SERV_BUFLEN_IN];
	int     aiCentrexID[SERV_BUFLEN_IN];
	int     aiInNetType[SERV_BUFLEN_IN];
	char    asAccNbr[SERV_BUFLEN_IN][21];
	char    asImsi[SERV_BUFLEN_IN][21];
	char    asDefaultAcctID[SERV_BUFLEN_IN][11];
	int 	aiQuota[SERV_BUFLEN_IN];
	int     aiSiteID[SERV_BUFLEN_IN];
	char    asCompletedDate[SERV_BUFLEN_IN][15];
	char    asCreatedDate[SERV_BUFLEN_IN][15];
	int     aiCreditGrade[SERV_BUFLEN_IN];
	char    asState[SERV_BUFLEN_IN][4];
	char    asStateDate[SERV_BUFLEN_IN][15];
	
	int	aiVipFlag[SERV_BUFLEN_IN];
};
/*˽��ͳ�Ʊ�*/
struct StatServHead{

	int iServIDNodeCnt;
	int iImsiNodeCnt;
	int iAccNbrNodeCnt;
	int iAcctIDNodeCnt;
	
	TRIE *pServIDTrie;
	TRIE *pImsiTrie;
	TRIE *pAccNbrTrie;
	TRIE *pAcctIDTrie;
	
	char sUpdateTime[15];
	
	int iServCnt;
	struct ServStruct *pServList;
};

/*�����ݵ�ȡ��*/
int EGetServToStruct(struct ServStruct *p,struct ServStructIn *pSource);

/*****�����ϸ���ͨ�ù��̼��غ����ӿ�***/
int CheckShmServEffect();
void DestroyServStatList();
int MountingUpdatedServToMem();
int MountingTotalServToMem();
int BuildServTemporaryPrimaryIndex();
int DestroyServTemporaryPrimaryIndex();
int CountingServCurDeleteRecord();
int CountingServIncrementRecord();
int GetServTotalBufRecord();
int CountingServIncrementNode();
int GetServTotalBufNode();
int LockServShm();
void UnlockServShm();
void TruncateServShmIndexAndRetriveNode();
int RebuildServShmCurIndexAndRetriveExpireRecord();
int BuildServMemListIndexAndMoveToShm();
int ServSemWorking();
int ClientServUnmountNotify();
int ClientServConnectNotify();
int CountingServTotalRecord();
int StatServTotalNode();
int InitServControlRecord();
void CopyServControlToShm();





#endif

