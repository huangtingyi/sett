/*---------头文件代码 serv_product.h----------*/
#ifndef __SERV_PRODUCT_H__
#define __SERV_PRODUCT_H__

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

/*单个结构申明*/
struct ServProductStruct{

	struct ServProductStruct *pNext;
	int     iProductID;
	char    sServID[11];
	int     iServSeqNbr;
	int     iSeqNbr;
	int     iProductTypeID;
	int     iProductQuantity;
	char    sState[4];
	char    sStateDate[15];
	char    sExpDate[15];
};

/* 输入结构缓冲申明*/
struct ServProductStructIn{

#ifndef SERV_PRODUCT_BUFLEN_IN
#define SERV_PRODUCT_BUFLEN_IN		300
#endif

	struct ServProductStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[256];
	int     aiProductID[SERV_PRODUCT_BUFLEN_IN];
	char    asServID[SERV_PRODUCT_BUFLEN_IN][11];
	int     aiServSeqNbr[SERV_PRODUCT_BUFLEN_IN];
	int     aiSeqNbr[SERV_PRODUCT_BUFLEN_IN];
	int     aiProductTypeID[SERV_PRODUCT_BUFLEN_IN];
	int     aiProductQuantity[SERV_PRODUCT_BUFLEN_IN];
	char    asAttachMsg[SERV_PRODUCT_BUFLEN_IN][17];
	char    asState[SERV_PRODUCT_BUFLEN_IN][4];
	char    asStateDate[SERV_PRODUCT_BUFLEN_IN][15];
	char    asExpDate[SERV_PRODUCT_BUFLEN_IN][15];
};
/*私有统计表*/
struct StatServProductHead{

	int iServIDNodeCnt;
	
	TRIE *pServIDTrie;
	
	char  	sUpdateTime[15];	/*上次更新时间*/
	
	int iServProductCnt;
	struct ServProductStruct *pServProductList;
};
/*对数据的取出*/
int EGetServProductToStruct(struct ServProductStruct *p,struct ServProductStructIn *pSource);

/*****给资料更新通用过程加载函数接口***/
int  CheckShmServProductEffect();
void DestroyServProductStatList();
int  MountingUpdatedServProductToMem();
int  MountingTotalServProductToMem();
int  BuildServProductTemporaryPrimaryIndex();
int  DestroyServProductTemporaryPrimaryIndex();
int  CountingServProductCurDeleteRecord();
int  CountingServProductIncrementRecord();
int  GetServProductTotalBufRecord();
int  CountingServProductIncrementNode();
int  GetServProductTotalBufNode();
int  LockServProductShm();
void UnlockServProductShm();
void TruncateServProductShmIndexAndRetriveNode();
int  RebuildServProductShmCurIndexAndRetriveExpireRecord();
int  BuildServProductMemListIndexAndMoveToShm();
int  ServProductSemWorking();
int  ClientServProductUnmountNotify();
int  ClientServProductConnectNotify();
int  CountingServProductTotalRecord();
int  StatServProductTotalNode();
int  InitServProductControlRecord();
void CopyServProductControlToShm();

#endif
