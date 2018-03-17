#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "datatype.h"

typedef struct	__Queue_Head__
{
	struct __Queue__ *pHead;
	struct __Queue__ *pTail;
} QUEUE_HEAD;

typedef struct	__Queue__
{
	struct __Queue__ *pNxt;
	struct __Queue__ *pPre;
	int	iLen;
	void	*pData;
} QUEUE;


typedef struct __E_Queue_Head__
{
	POINTER ioffHead;
	POINTER ioffTail;
} EQUEUE_HEAD;

typedef struct __E_Queue__
{
	POINTER ioffNext;
	POINTER ioffNxt;
	POINTER ioffPre;
	POINTER ioffData;
} EQUEUE;

/*初始化队列，将队列结构设为空*/
void InitQueue(QUEUE_HEAD *qh);
int QueueEmpty(QUEUE_HEAD *qh);

/*插入队尾，从队头获取一个节点*/
void InsertQueueTail(QUEUE_HEAD *qh,QUEUE *p);
QUEUE *GetQueueHead(QUEUE_HEAD *qh);
/*插入对头，从队尾获取一个节点*/
void InsertQueueHead(QUEUE_HEAD *qh,QUEUE *p);
QUEUE *GetQueueTail(QUEUE_HEAD *qh);

/*插入队列特定的元素前面活后面，从队列特定元素处拿出一个元素*/
void InsertQueueItem(QUEUE *pPre,QUEUE *pCur,QUEUE *pTemp);
void InsertQueuePosNxt(QUEUE_HEAD *qh,QUEUE *q,QUEUE *p);
void InsertQueuePosPre(QUEUE_HEAD *qh,QUEUE *q,QUEUE *p);
QUEUE *GetQueuePos(QUEUE_HEAD *qh,QUEUE *p);

/*判断拿到队列的长度，以及遍历队列*/
int QueueLength(QUEUE_HEAD *qh);
int TravelQueue(QUEUE_HEAD *qh,int ( *pOperation)(QUEUE *));
void DestroyQueue(QUEUE_HEAD *qh);
QUEUE *MallocQueueItem(void *pData,int iLen);

void PushQueue(QUEUE_HEAD *qh,QUEUE *p);
QUEUE *PopQueue(QUEUE_HEAD *qh);


/*单块共享内存的QUEUE*/
void InitEQueue(EQUEUE_HEAD *qh);
int EQueueEmpty(EQUEUE_HEAD *qh);
void InsertEQueueTail(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
void InsertEQueueHead(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
void InsertEQueueItem(void *pSeg,POINTER ioffPre,POINTER ioffCur,POINTER ioffTmp);
void InsertEQueuePosNxt(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp);
void InsertEQueuePosPre(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp);
POINTER GetEQueueHead(void *pSeg,EQUEUE_HEAD *qh);
POINTER GetEQueueTail(void *pSeg,EQUEUE_HEAD *qh);
POINTER GetEQueuePos(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
int EQueueLength(void *pSeg,EQUEUE_HEAD *qh);
int TravelEQueue(void *pSeg,EQUEUE_HEAD *qh,int ( *pOperation)(POINTER *));
void PushEQueue(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
POINTER PopEQueue(void *pSeg,EQUEUE_HEAD *qh);

/*多块共享内存的QUEUE,以下代码和EQueue一组函数一致*/
void InitFQueue(EQUEUE_HEAD *qh);
int FQueueEmpty(EQUEUE_HEAD *qh);
void InsertFQueueTail(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
void InsertFQueueHead(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
void InsertFQueueItem(void *pSeg,POINTER ioffPre,POINTER ioffCur,POINTER ioffTmp);
void InsertFQueuePosNxt(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp);
void InsertFQueuePosPre(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp);
POINTER GetFQueueHead(void *pSeg,EQUEUE_HEAD *qh);
POINTER GetFQueueTail(void *pSeg,EQUEUE_HEAD *qh);
POINTER GetFQueuePos(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
int FQueueLength(void *pSeg,EQUEUE_HEAD *qh);
int TravelFQueue(void *pSeg,EQUEUE_HEAD *qh,int ( *pOperation)(POINTER *));

void PushFQueue(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp);
POINTER PopFQueue(void *pSeg,EQUEUE_HEAD *qh);


#endif
