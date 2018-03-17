#ifndef __BASE_SUPP_H__
#define __BASE_SUPP_H__

#include <datatype.h>

struct ShmTableStruct
{
	char	sTableName[31];
	int	iRecLen;
	int	iRecCnt;
	int	iTabLen;
	int	iLock;		/*0������1��*/
	POINTER	ioffset;	/*�ɵ���ģ��ȷ��*/
};

#define TABMAX	100
/*�����ڴ������*/
struct ShmPcbStruct
{
	POINTER iTotalLen;
	int iTabCnt;
	int iTabMax;
	POINTER ioffDataFree;
	struct ShmTableStruct ShmTab[TABMAX];
};

/*�ڴ��м�ṹ����*/
struct MemTableStruct
{
	struct  MemTableStruct *pNext;
	int	iRecLen;
	int	iRecCnt;
	int	iTabLen;
	char	sTableName[31];
	void	*pHead;		/*����ָ��*/
};
/*����ˢ��ע������*/
struct	ShmTableRegStruct
{
	struct	ShmTableRegStruct *pNext;
	/*�����ݿ��ڵ����ݼ��ص��ڴ�ṹ��*/
	int	(*InitRecordList)(void **pptHead);
	int	iRecLen;
	char	sTableName[31];
};

/*���㹲���ڴ��С*/
int CalcNeedShm(struct MemTableStruct *ptHead);

/*������memtable--->shmtab,һ�ű�*/
int MoveTableListToShm(struct MemTableStruct *ptHead);

/*��������ݼ��ص�MemTableStruct�����У����б�*/
int DataToMemTable(struct ShmTableRegStruct *ptHead,struct MemTableStruct **pptHead);

/*ע�����ˢ�º���*/
int RegShmTabFun(int (*InitRecordList)(void **pptHead),int iRecLen,char sTableName[],
	struct ShmTableRegStruct **pptHead);

#define PPCBDATA(x,y)	(((char*)x)+y)


int RegTotalShmTab(struct ShmTableRegStruct **pptHead);

/*******���ݼ��ط�װ����*************/
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

struct ShmCscStruct			/*�����ڴ�CommSearchControl�ṹ*/
{
	int	isCnt;			/*С�ṹ��¼��*/
	int	imCnt;			/*�нṹ��¼��*/
	int	ilCnt;			/*��ṹ��¼��*/
	int	ibCnt;			/*binNode�ڵ���*/
	int	itCnt;			/*trieNode�ڵ���*/
	int	bBytes;
	int	tBytes;
	struct ShmCtrlStruct SItem;	/*С�ṹ�ڴ���ƿ�*/
	struct ShmCtrlStruct MItem;	/*�нṹ�ڴ���ƿ�*/
	struct ShmCtrlStruct LItem;	/*��ṹ�ڴ���ƿ�*/
	struct ShmCtrlStruct bNode;	/*binNode�ڴ���ƿ�*/
	struct ShmCtrlStruct tNode;	/*trieNode�ڴ���ƿ�*/
	POINTER ioffbRoot;		/*bin��*/
	POINTER iofftRoot;		/*trie��*/
};

/****�����ڴ�ṹ����:

�޸�ǰΪ:
PCB+ PCB�����ݵ����ݿ�

�޸ĺ�Ϊ��
PCB+ CSC + CS������ + CS������ + PCB�����ݵ����ݿ�

***/
/*���������ڴ��ʼ�ṹ*/
int BuildShmInit(struct MemTableStruct *ptHead,struct ShmCscStruct *pc);

int MemTableToShm(struct MemTableStruct *ptHead,struct ShmCscStruct *pc);

int SearchMemTable(struct MemTableStruct *ptHead,char sTableName[],
	struct MemTableStruct **pptCur);
/*
1.�������Ҫ����TRIE�ڵ��Լ� smallcnt,middlecnt,largecnt;
*/
int CalcCommSearchTrie(struct MemTableStruct *pMem,int *pitNode,
	int *pisCnt,int *pimCnt,int *pilCnt);
/*2.�������Ҫ����BIN�ڵ��Լ� smallcnt,middlecnt,largecnt;
*/
int CalcCommSearchBin(struct MemTableStruct *pMem,int *pibNode,
	int *pisCnt,int *pimCnt,int *pilCnt);


#endif


