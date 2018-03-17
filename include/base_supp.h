#ifndef __BASE_SUPP_H__
#define __BASE_SUPP_H__

#include <datatype.h>

struct ShmTableStruct
{
	char	sTableName[31];
	int	iRecLen;
	int	iRecCnt;
	int	iTabLen;
	int	iLock;		/*0无锁，1锁*/
	POINTER	ioffset;	/*由导入模块确定*/
};

#define TABMAX	100
/*共享内存参数表*/
struct ShmPcbStruct
{
	POINTER iTotalLen;
	int iTabCnt;
	int iTabMax;
	POINTER ioffDataFree;
	struct ShmTableStruct ShmTab[TABMAX];
};

/*内存中间结构链表*/
struct MemTableStruct
{
	struct  MemTableStruct *pNext;
	int	iRecLen;
	int	iRecCnt;
	int	iTabLen;
	char	sTableName[31];
	void	*pHead;		/*链表指针*/
};
/*参数刷新注册链表*/
struct	ShmTableRegStruct
{
	struct	ShmTableRegStruct *pNext;
	/*将数据库内的数据加载到内存结构中*/
	int	(*InitRecordList)(void **pptHead);
	int	iRecLen;
	char	sTableName[31];
};

/*计算共享内存大小*/
int CalcNeedShm(struct MemTableStruct *ptHead);

/*参数从memtable--->shmtab,一张表*/
int MoveTableListToShm(struct MemTableStruct *ptHead);

/*将表的数据加载到MemTableStruct链表中，所有表*/
int DataToMemTable(struct ShmTableRegStruct *ptHead,struct MemTableStruct **pptHead);

/*注册参数刷新函数*/
int RegShmTabFun(int (*InitRecordList)(void **pptHead),int iRecLen,char sTableName[],
	struct ShmTableRegStruct **pptHead);

#define PPCBDATA(x,y)	(((char*)x)+y)


int RegTotalShmTab(struct ShmTableRegStruct **pptHead);

/*******数据加载封装部分*************/
int IInitAcrossCellCode(void **pptHead);
int IInitAreaCodeDesc(void **pptHead);
int IInitT130AreaCode(void **pptHead);
int IInitTrunk(void **pptHead);
int IInitMsc(void **pptHead);
int IInitTelecomCarrier(void **pptHead);
int IInitTicketField(void **pptHead);
int IInitTicketFieldRule(void **pptHead);
int IInitTicketFieldValue(void **pptHead);
int IInitSplitRule(void **pptHead);
int IInitTollTariff(void **pptHead);
int IInitExprDef(void **pptHead);
int IInitExprDisct(void **pptHead);
int IInitHeadCarr(void **pptHead);
int IInitTariffDisct(void **pptHead);
int IInitTicketBasedDisct(void **pptHead);
int IInitTicketType(void **pptHead);
int IInitTicketTypeTariff(void **pptHead);
int IInitTimeSpanDisct(void **pptHead);
int IInitDisctRule(void **pptHead);
int IInitCellCode(void **pptHead);
int IInitDisctRuleMutex(void **pptHead);

int IInitDispParam(void **pptHead);
int IInitInstParam(void **pptHead);
int IInitPickParam(void **pptHead);
int IInitPrepParam(void **pptHead);
int IInitBillParam(void **pptHead);
int IInitCommSearchBin(void **pptHead);
int IInitCommSearchTrie(void **pptHead);
int IInitLCommSearchBin(void **pptHead);
int IInitLCommSearchTrie(void **pptHead);
int IInitCommRange(void **pptHead);
int IInitSwitch(void **pptHead);
int IInitCmdTemplate(void **pptHead);
int IInitNbrHead(void **pptHead);
int IInitAcctItemType(void **pptHead);
int IInitSettRule(void **pptHead);
int IInitSettCycle(void **pptHead);
int IInitLatn(void **pptHead);
int IInitPutParam(void **pptHead);
int IInitCommParam(void **pptHead);

int IInitSettArea(void **pptHead);
int IInitFlowApp(void **pptHead);
int IInitFlowTask(void **pptHead);
int IInitFlowTache(void **pptHead);
int IInitTaskParam(void **pptHead);
int IInitAcctTaskParam(void **pptHead);
int IInitBillTaskParam(void **pptHead);
int IInitInstTaskParam(void **pptHead);
int IInitIntfTaskParam(void **pptHead);
int IInitPickTaskParam(void **pptHead);
int IInitPrepTaskParam(void **pptHead);
int IInitPutTaskParam(void **pptHead);
int IInitRcylTaskParam(void **pptHead);
int IInitRollTaskParam(void **pptHead);
int IInitAcctParam(void **pptHead);
int IInitIntfParam(void **pptHead);
int IInitRcylParam(void **pptHead);
int IInitRollParam(void **pptHead);
int IInitSourceDesc(void **pptHead);

struct ShmCscStruct			/*共享内存CommSearchControl结构*/
{
	int	isCnt;			/*小结构记录数*/
	int	imCnt;			/*中结构记录数*/
	int	ilCnt;			/*大结构记录数*/
	int	ibCnt;			/*binNode节点数*/
	int	itCnt;			/*trieNode节点数*/
	int	bBytes;
	int	tBytes;
	struct ShmCtrlStruct SItem;	/*小结构内存控制块*/
	struct ShmCtrlStruct MItem;	/*中结构内存控制块*/
	struct ShmCtrlStruct LItem;	/*大结构内存控制块*/
	struct ShmCtrlStruct bNode;	/*binNode内存控制块*/
	struct ShmCtrlStruct tNode;	/*trieNode内存控制块*/
	POINTER ioffbRoot;		/*bin树*/
	POINTER iofftRoot;		/*trie树*/
};

/****共享内存结构如下:

修改前为:
PCB+ PCB各数据的数据块

修改后为：
PCB+ CSC + CS数据区 + CS索引区 + PCB各数据的数据块

***/
/*建立共享内存初始结构*/
int BuildShmInit(struct MemTableStruct *ptHead,struct ShmCscStruct *pc);

int MemTableToShm(struct MemTableStruct *ptHead,struct ShmCscStruct *pc);

int SearchMemTable(struct MemTableStruct *ptHead,char sTableName[],
	struct MemTableStruct **pptCur);
/*
1.计算出需要多少TRIE节点以及 smallcnt,middlecnt,largecnt;
*/
int CalcCommSearchTrie(struct MemTableStruct *pMem,int *pitNode,
	int *pisCnt,int *pimCnt,int *pilCnt);
/*2.计算出需要多少BIN节点以及 smallcnt,middlecnt,largecnt;
*/
int CalcCommSearchBin(struct MemTableStruct *pMem,int *pibNode,
	int *pisCnt,int *pimCnt,int *pilCnt);


#endif


