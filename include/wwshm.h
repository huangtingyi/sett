#ifndef __WWSHM_H__
#define __WWSHM_H__

#include "datatype.h"
#include "list.h"

void *CreateShm(key_t shmkey,size_t iSize,int *piErrCode);
void *CreateShmX(key_t shmkey,size_t iSize);

void DestroyShm(key_t shmkey);
void *AttachShm(key_t shmkey,int *piErrCode,void *p);
void DetachShm(void *pShm);

struct ShmCtrlStruct
{
	int	iRecLen;/*单个记录的长度*/
	int	iRecCnt;/*记录个数*/
	int	iUsedCnt;/*已用的记录个数*/
	POINTER ioffFree;/*空闲链表*/
};
void InitEShmCtrl(int iRecLen,int iRecCnt,void *pHead,POINTER ioffHead,
	struct ShmCtrlStruct *p);
POINTER MallocEItem(void *pSeg,struct ShmCtrlStruct *ptHead);
void FreeEItem(void *pSeg,struct ShmCtrlStruct *ptHead,POINTER ioffValue);

POINTER InitFShmCtrl(int iRecLen,int iRecCnt,void *pHead,POINTER ioffHead,
	struct ShmCtrlStruct *p);
POINTER MallocFItem(void *pSeg,struct ShmCtrlStruct *ptHead);
void FreeFItem(void *pSeg,struct ShmCtrlStruct *ptHead,POINTER ioffValue);

struct ShmHead
{
	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
};
struct FShmStruct
{
	struct ShmHead Head;
	POINTER iBlockLen;
	int	iBlockCnt;
};
int UpdateShmHead(key_t shmkey,size_t iSize);
int GetShmHead(key_t shmkey,struct ShmHead *ptCur);
int ShmHeadValid(key_t shmkey,struct ShmHead *pPre,struct ShmHead *pShm);
void *CreateShmInitHead(key_t iShmKey,POINTER iTotalLen,int *piErrCode);
void FreeShm(key_t shmkey);
void *GetShm(key_t shmkey,int *piErrCode,void *p);
void *AllocShm(key_t shmkey,size_t iSize,int *piErrCode);

void *CreateMultiShm(key_t shmkey,POINTER iTotalLen,
	POINTER iBlockLen,struct FMemStruct *pMem);
void DestroyMultiShm(key_t shmkey,struct FMemStruct *pMem);
void *AttachMultiShm(key_t shmkey,struct FMemStruct *pMem);
void DetachMultiShm(struct FMemStruct *pMem);

#endif
