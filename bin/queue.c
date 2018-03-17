#include "hnixs.h"
#include "list.h"
#include "queue.h"

void InitQueue(QUEUE_HEAD *qh)
{
	qh->pHead=qh->pTail=NULL;
}
int QueueEmpty(QUEUE_HEAD *qh)
{
	if(qh->pHead==NULL&&qh->pTail==NULL) return true;
	return false;
}
void InsertQueueTail(QUEUE_HEAD *qh,QUEUE *p)
{
	if(QueueEmpty(qh)){
		qh->pHead=qh->pTail=p;
		p->pPre=p->pNxt=NULL;
	}
	else{
		p->pPre=qh->pTail;
		p->pNxt=NULL;


		qh->pTail->pNxt=p;
		qh->pTail=p;
	}
}
void InsertQueueHead(QUEUE_HEAD *qh,QUEUE *p)
{
	if(QueueEmpty(qh)){
		qh->pHead=qh->pTail=p;
		p->pPre=p->pNxt=NULL;
	}
	else{
		p->pNxt=qh->pHead;
		p->pPre=NULL;

		qh->pHead->pPre=p;
		qh->pHead=p;
	}
}
void InsertQueueItem(QUEUE *pPre,QUEUE *pCur,QUEUE *pTemp)
{
	pTemp->pPre=pPre;
	pTemp->pNxt=pCur;

	pPre->pNxt=pTemp;
	pCur->pPre=pTemp;
}
void InsertQueuePosNxt(QUEUE_HEAD *qh,QUEUE *q,QUEUE *p)
{
	if(q->pNxt!=NULL)
		InsertQueueItem(q,q->pNxt,p);
	else
		InsertQueueTail(qh,p);
}
void InsertQueuePosPre(QUEUE_HEAD *qh,QUEUE *q,QUEUE *p)
{
	if(q->pPre!=NULL)
		InsertQueueItem(q->pPre,q,p);
	else
		InsertQueueHead(qh,p);
}
QUEUE *GetQueueHead(QUEUE_HEAD *qh)
{
	QUEUE *p;

	if(qh->pHead==NULL) return NULL;

	p=qh->pHead;

	if(p->pNxt!=NULL){
		qh->pHead=p->pNxt;
		p->pNxt->pPre=NULL;
		p->pNxt=NULL;
	}
	else
		InitQueue(qh);

	return p;
}
QUEUE *GetQueueTail(QUEUE_HEAD *qh)
{
	QUEUE *p;

	if(QueueEmpty(qh)) return NULL;

	p=qh->pTail;

	if(p->pPre!=NULL){
		qh->pTail=p->pPre;
		p->pPre->pNxt=NULL;
		p->pPre=NULL;
	}
	else
		InitQueue(qh);

	return p;
}
QUEUE *GetQueuePos(QUEUE_HEAD *qh,QUEUE *p)
{
	QUEUE *pPre,*pCur;

	if(QueueEmpty(qh)) return NULL;

	if(p==qh->pHead) return GetQueueHead(qh);
	if(p==qh->pTail) return GetQueueTail(qh);


	pPre=p->pPre;
	pCur=p->pNxt;


	pPre->pNxt=pCur;
	pCur->pPre=pPre;

	p->pPre=p->pNxt=NULL;

	return p;
}
int QueueLength(QUEUE_HEAD *qh)
{
	int iCnt=0;

	QUEUE *p=qh->pHead;

	while(p!=NULL){iCnt++;p=p->pNxt;}

	return iCnt;
}
int TravelQueue(QUEUE_HEAD *qh,int ( *pOperation)(QUEUE *))
{
	int j=0;
	QUEUE *p=qh->pHead;

	while(p!=NULL){
		j+=(*pOperation)(p);
		p=p->pNxt;
	}
	return j;
}
void DestroyQueue(QUEUE_HEAD *qh)
{
	QUEUE *p=qh->pHead;

	while(p!=NULL){
		free(p);
		p=p->pNxt;
	}
	InitQueue(qh);
}
QUEUE *MallocQueueItem(void *pData,int iLen)
{
	QUEUE *pTemp;

	if((pTemp=malloc(sizeof(QUEUE)+iLen))==NULL) return NULL;

	pTemp->pData=(void*)(pTemp+1);

	pTemp->pNxt=pTemp->pPre=NULL;
	pTemp->iLen=iLen;
	memcpy(pTemp->pData,pData,iLen);

	return pTemp;
}
void PushQueue(QUEUE_HEAD *qh,QUEUE *p)
{
	InsertQueueHead(qh,p);
}
QUEUE *PopQueue(QUEUE_HEAD *qh)
{
	return GetQueueHead(qh);
}
/*单块共享内存的QUEUE*/

void InitEQueue(EQUEUE_HEAD *qh)
{
	qh->ioffHead=qh->ioffTail=-1;
}
int EQueueEmpty(EQUEUE_HEAD *qh)
{
	if(qh->ioffHead==-1&&qh->ioffTail==-1) return true;
	return false;
}
void InsertEQueueTail(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	EQUEUE *p,*pTmp;

	p=(EQUEUE*)OPELIST(pSeg,ioffTmp);

	if(EQueueEmpty(qh)){
		qh->ioffHead=qh->ioffTail=ioffTmp;
		p->ioffPre=p->ioffNxt=-1;
	}
	else{
		p->ioffPre=qh->ioffTail;
		p->ioffNxt=-1;
		
		pTmp=(EQUEUE*)OPELIST(pSeg,qh->ioffTail);
		pTmp->ioffNxt=ioffTmp;
		qh->ioffTail=ioffTmp;
	}
}
void InsertEQueueHead(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	EQUEUE *p,*pTmp;

	p=(EQUEUE*)OPELIST(pSeg,ioffTmp);

	if(qh->ioffHead==-1){
		qh->ioffHead=qh->ioffTail=ioffTmp;
		p->ioffPre=p->ioffNxt=-1;
	}
	else{
		p->ioffNxt=qh->ioffHead;
		p->ioffPre=-1;

		pTmp=(EQUEUE*)OPELIST(pSeg,qh->ioffHead);
		pTmp->ioffPre=ioffTmp;
		qh->ioffHead=ioffTmp;
	}
}
void InsertEQueueItem(void *pSeg,POINTER ioffPre,POINTER ioffCur,POINTER ioffTmp)
{
	EQUEUE *pPre,*pCur,*pTmp;

	pPre=(EQUEUE*)OPELIST(pSeg,ioffPre);
	pCur=(EQUEUE*)OPELIST(pSeg,ioffCur);
	pTmp=(EQUEUE*)OPELIST(pSeg,ioffTmp);

	pTmp->ioffPre=ioffPre;
	pTmp->ioffNxt=ioffCur;

	pPre->ioffNxt=ioffTmp;
	pCur->ioffPre=ioffTmp;
}
void InsertEQueuePosNxt(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp)
{
	EQUEUE *pPos,*pTmp;
	
	pPos=(EQUEUE*)OPELIST(pSeg,ioffPos);
	pTmp=(EQUEUE*)OPELIST(pSeg,ioffTmp);


	if(pPos->ioffNxt!=-1)
		InsertEQueueItem(pSeg,ioffPos,pPos->ioffNxt,ioffTmp);
	else
		InsertEQueueTail(pSeg,qh,ioffTmp);
}
void InsertEQueuePosPre(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp)
{
	EQUEUE *pPos,*pTmp;
	
	pPos=(EQUEUE*)OPELIST(pSeg,ioffPos);
	pTmp=(EQUEUE*)OPELIST(pSeg,ioffTmp);

	if(pPos->ioffPre!=-1)
		InsertEQueueItem(pSeg,pPos->ioffPre,ioffPos,ioffTmp);
	else
		InsertEQueueHead(pSeg,qh,ioffTmp);
}
POINTER GetEQueueHead(void *pSeg,EQUEUE_HEAD *qh)
{
	POINTER ioffTmp;
	EQUEUE *p,*pTmp;

	if(EQueueEmpty(qh)) return -1;

	ioffTmp=qh->ioffHead;

	p=(EQUEUE*)OPELIST(pSeg,ioffTmp);

	if(p->ioffNxt!=-1){
		qh->ioffHead=p->ioffNxt;
		/*p->ioffNxt->ioffPre=-1;*/
		pTmp=(EQUEUE*)OPELIST(pSeg,p->ioffNxt);
		pTmp->ioffPre=-1;
		p->ioffNxt=-1;
	}
	else
		InitEQueue(qh);

	return ioffTmp;
}
POINTER GetEQueueTail(void *pSeg,EQUEUE_HEAD *qh)
{
	POINTER ioffTmp;
	EQUEUE *p,*pTmp;

	if(EQueueEmpty(qh)) return -1;

	ioffTmp=qh->ioffTail;

	p=(EQUEUE*)OPELIST(pSeg,ioffTmp);

	if(p->ioffPre!=-1){
		qh->ioffTail=p->ioffPre;
		/*p->ioffPre->ioffNxt=-1;*/
		pTmp=(EQUEUE*)OPELIST(pSeg,p->ioffPre);
		pTmp->ioffNxt=-1;
		p->ioffPre=-1;
	}
	else
		InitEQueue(qh);

	return ioffTmp;
}
POINTER GetEQueuePos(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	EQUEUE *pPre,*pCur,*p;

	if(ioffTmp==-1) return -1;

	if(ioffTmp==qh->ioffHead) return GetEQueueHead(pSeg,qh);
	if(ioffTmp==qh->ioffTail) return GetEQueueTail(pSeg,qh);

	p=(EQUEUE*)OPELIST(pSeg,ioffTmp);


	pPre=(EQUEUE*)OPELIST(pSeg,p->ioffPre);
	pCur=(EQUEUE*)OPELIST(pSeg,p->ioffNxt);


	pPre->ioffNxt=p->ioffNxt;
	pCur->ioffPre=p->ioffPre;

	p->ioffPre=p->ioffNxt=-1;

	return ioffTmp;
}
int EQueueLength(void *pSeg,EQUEUE_HEAD *qh)
{
	int iCnt=0;

	POINTER ioffTmp;
	EQUEUE *p;
	
	ioffTmp=qh->ioffHead;
	
	while(ioffTmp!=-1){
		iCnt++;
		
		p=(EQUEUE*)OPELIST(pSeg,ioffTmp);
		ioffTmp=p->ioffNxt;
	}
	
	return iCnt;
}
int TravelEQueue(void *pSeg,EQUEUE_HEAD *qh,int ( *pOperation)(POINTER *))
{
	int j=0;
	POINTER ioffTmp;
	EQUEUE *p;
	
	ioffTmp=qh->ioffHead;
	
	while(ioffTmp!=-1){

		p=(EQUEUE*)OPELIST(pSeg,ioffTmp);
		j+=(*pOperation)(&(p->ioffData));
		ioffTmp=p->ioffNxt;
	}
	return j;
}

void PushEQueue(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	InsertEQueueHead(pSeg,qh,ioffTmp);
}
POINTER PopEQueue(void *pSeg,EQUEUE_HEAD *qh)
{
	return GetEQueueHead(pSeg,qh);
}

/*多块共享内存的QUEUE,以下代码和EQueue一组函数一致*/

void InitFQueue(EQUEUE_HEAD *qh)
{
	qh->ioffHead=qh->ioffTail=-1;
}
int FQueueEmpty(EQUEUE_HEAD *qh)
{
	if(qh->ioffHead==-1&&qh->ioffTail==-1) return true;
	return false;
}
void InsertFQueueTail(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	EQUEUE *p,*pTmp;

	p=(EQUEUE*)OPFLIST(pSeg,ioffTmp);

	if(FQueueEmpty(qh)){
		qh->ioffHead=qh->ioffTail=ioffTmp;
		p->ioffPre=p->ioffNxt=-1;
	}
	else{
		p->ioffPre=qh->ioffTail;
		p->ioffNxt=-1;
		
		pTmp=(EQUEUE*)OPFLIST(pSeg,qh->ioffTail);
		pTmp->ioffNxt=ioffTmp;
		qh->ioffTail=ioffTmp;
	}
}
void InsertFQueueHead(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	EQUEUE *p,*pTmp;

	p=(EQUEUE*)OPFLIST(pSeg,ioffTmp);

	if(qh->ioffHead==-1){
		qh->ioffHead=qh->ioffTail=ioffTmp;
		p->ioffPre=p->ioffNxt=-1;
	}
	else{
		p->ioffNxt=qh->ioffHead;
		p->ioffPre=-1;

		pTmp=(EQUEUE*)OPFLIST(pSeg,qh->ioffHead);
		pTmp->ioffPre=ioffTmp;
		qh->ioffHead=ioffTmp;
	}
}
void InsertFQueueItem(void *pSeg,POINTER ioffPre,POINTER ioffCur,POINTER ioffTmp)
{
	EQUEUE *pPre,*pCur,*pTmp;

	pPre=(EQUEUE*)OPFLIST(pSeg,ioffPre);
	pCur=(EQUEUE*)OPFLIST(pSeg,ioffCur);
	pTmp=(EQUEUE*)OPFLIST(pSeg,ioffTmp);

	pTmp->ioffPre=ioffPre;
	pTmp->ioffNxt=ioffCur;

	pPre->ioffNxt=ioffTmp;
	pCur->ioffPre=ioffTmp;
}
void InsertFQueuePosNxt(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp)
{
	EQUEUE *pPos,*pTmp;
	
	pPos=(EQUEUE*)OPFLIST(pSeg,ioffPos);
	pTmp=(EQUEUE*)OPFLIST(pSeg,ioffTmp);


	if(pPos->ioffNxt!=-1)
		InsertFQueueItem(pSeg,ioffPos,pPos->ioffNxt,ioffTmp);
	else
		InsertFQueueTail(pSeg,qh,ioffTmp);
}
void InsertFQueuePosPre(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffPos,POINTER ioffTmp)
{
	EQUEUE *pPos,*pTmp;
	
	pPos=(EQUEUE*)OPFLIST(pSeg,ioffPos);
	pTmp=(EQUEUE*)OPFLIST(pSeg,ioffTmp);

	if(pPos->ioffPre!=-1)
		InsertFQueueItem(pSeg,pPos->ioffPre,ioffPos,ioffTmp);
	else
		InsertFQueueHead(pSeg,qh,ioffTmp);
}
POINTER GetFQueueHead(void *pSeg,EQUEUE_HEAD *qh)
{
	POINTER ioffTmp;
	EQUEUE *p,*pTmp;

	if(FQueueEmpty(qh)) return -1;

	ioffTmp=qh->ioffHead;

	p=(EQUEUE*)OPFLIST(pSeg,ioffTmp);

	if(p->ioffNxt!=-1){
		qh->ioffHead=p->ioffNxt;
		/*p->ioffNxt->ioffPre=-1;*/
		pTmp=(EQUEUE*)OPFLIST(pSeg,p->ioffNxt);
		pTmp->ioffPre=-1;
		p->ioffNxt=-1;
	}
	else
		InitFQueue(qh);

	return ioffTmp;
}
POINTER GetFQueueTail(void *pSeg,EQUEUE_HEAD *qh)
{
	POINTER ioffTmp;
	EQUEUE *p,*pTmp;

	if(FQueueEmpty(qh)) return -1;

	ioffTmp=qh->ioffTail;

	p=(EQUEUE*)OPFLIST(pSeg,ioffTmp);

	if(p->ioffPre!=-1){
		qh->ioffTail=p->ioffPre;
		/*p->ioffPre->ioffNxt=-1;*/
		pTmp=(EQUEUE*)OPFLIST(pSeg,p->ioffPre);
		pTmp->ioffNxt=-1;
		p->ioffPre=-1;
	}
	else
		InitFQueue(qh);

	return ioffTmp;
}
POINTER GetFQueuePos(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	EQUEUE *pPre,*pCur,*p;

	if(ioffTmp==-1) return -1;

	if(ioffTmp==qh->ioffHead) return GetFQueueHead(pSeg,qh);
	if(ioffTmp==qh->ioffTail) return GetFQueueTail(pSeg,qh);

	p=(EQUEUE*)OPFLIST(pSeg,ioffTmp);


	pPre=(EQUEUE*)OPFLIST(pSeg,p->ioffPre);
	pCur=(EQUEUE*)OPFLIST(pSeg,p->ioffNxt);


	pPre->ioffNxt=p->ioffNxt;
	pCur->ioffPre=p->ioffPre;

	p->ioffPre=p->ioffNxt=-1;

	return ioffTmp;
}
int FQueueLength(void *pSeg,EQUEUE_HEAD *qh)
{
	int iCnt=0;

	POINTER ioffTmp;
	EQUEUE *p;
	
	ioffTmp=qh->ioffHead;
	
	while(ioffTmp!=-1){
		iCnt++;
		
		p=(EQUEUE*)OPFLIST(pSeg,ioffTmp);
		ioffTmp=p->ioffNxt;
	}
	
	return iCnt;
}
int TravelFQueue(void *pSeg,EQUEUE_HEAD *qh,int ( *pOperation)(POINTER *))
{
	int j=0;
	POINTER ioffTmp;
	EQUEUE *p;
	
	ioffTmp=qh->ioffHead;
	
	while(ioffTmp!=-1){

		p=(EQUEUE*)OPFLIST(pSeg,ioffTmp);
		j+=(*pOperation)(&(p->ioffData));
		ioffTmp=p->ioffNxt;
	}
	return j;
}

void PushFQueue(void *pSeg,EQUEUE_HEAD *qh,POINTER ioffTmp)
{
	InsertFQueueHead(pSeg,qh,ioffTmp);
}
POINTER PopFQueue(void *pSeg,EQUEUE_HEAD *qh)
{
	return GetFQueueHead(pSeg,qh);
}
