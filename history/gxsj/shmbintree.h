#ifndef __SHMBINTREE_H__
#define __SHMBINTREE_H__

#define MAX_BINTREE_NUM 3
#define SHM_AREA_SIZE 20480000
#define SHM_AREA_CNT 3
#define MULTI_SHM_ID 0x7000

struct ShmBinTreeHead
{
	char sName[31];
	
	int	iRecLen;
	int 	iRecCnt;
		
	struct ShmCtrlStruct Item;
	struct ShmCtrlStruct BinTree;
	
	int iOffHead;
	int iOffRoot;
};

struct FBinTreeShmStruct
{
	struct ShmHead Head;
	POINTER iBlockLen;
	int	iBlockCnt;
	
	int ioffset;
	
	struct ShmBinTreeHead BTree[MAX_BINTREE_NUM];
};

int MvList2ShmBinTree(struct ShmBinTreeHead *ptHead,LIST *ptData,int iSize,
	int4b ( *pFunction)(POINTER,POINTER));
int SearchShmBinTree(struct ShmBinTreeHead *pShm,
	void *pValue,int ( *pFunction)(void *,POINTER),void **pptCur);
void AttachBinTreeShm(struct FBinTreeShmStruct **pptHead,int iShmID);
void InitBinTreeShm(struct FBinTreeShmStruct **pptHead,int iShmID);
struct ShmBinTreeHead *AddShmBinTree(struct FBinTreeShmStruct *pShm,
	char sName[],int iRecLen,int iRecCnt); 
struct ShmBinTreeHead *GetShmBinTree(struct FBinTreeShmStruct *pShm,char sName[]);
struct ShmBinTreeHead *AttachShmBinTree(char sName[]);
#endif
