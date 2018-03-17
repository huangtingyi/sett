
#include "hnixs.h"
#include "wwshm.h"
#include "list.h"
#include "wwtiny.h"

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


void *CreateShm(key_t shmkey,size_t iSize,int *piErrCode)
{
	void *pShm;
	int shmid;

	if((shmid=shmget(shmkey,iSize,0640|IPC_EXCL|IPC_CREAT))==-1){
		*piErrCode=1;
		return NULL;
	}

	pShm=(void *)shmat(shmid,NULL,0);
	*piErrCode = ((void *)pShm==(void *)(-1))?1:0;

	if(*piErrCode)perror("allocshm1");

	return pShm;
}
void DestroyShm(key_t shmkey)
{
	int shmid;
	/* 取key为shmkey的share memory id */
	shmid=shmget(shmkey,0,0);
	/*若key为shmkey的share memory已存在，则删除它并释放所占资源*/
	shmctl(shmid,IPC_RMID,NULL);
}
void *AttachShm(key_t shmkey,int *piErrCode,void *p)
{
	void *pShm;
	int shmid;

	if((shmid=shmget(shmkey,0,0400))==-1){
		*piErrCode=1;
		return NULL;
	}
	pShm=(void *)shmat(shmid,p,0400);
	*piErrCode = ((void *)pShm==(void *)(-1))?1:0;

	return pShm;
}
void *CreateShmX(key_t shmkey,size_t iSize)
{
	void *p=NULL;
	int iErrCode=0;
	
	p=CreateShm(shmkey,iSize,&iErrCode);
	
	if(iErrCode!=0)	p=AttachShm(shmkey,&iErrCode,0);
	
	if(iErrCode!=0) return NULL;
	
	return p;
	
}
void DetachShm(void *pShm)
{
	shmdt(pShm);
}
void FreeShm(key_t shmkey)
{
	DestroyShm(shmkey);
}
void *GetShm(key_t shmkey,int *piErrCode,void *p)
{
	return AttachShm(shmkey,piErrCode,p);
}
void *AllocShm(key_t shmkey,size_t iSize,int *piErrCode)
{
	return CreateShm(shmkey,iSize,piErrCode);
}
int UpdateShmHead(key_t shmkey,size_t iSize)
{
	int iShmID,iErrCode=0;
	char	sUpdateTime[15];
	struct ShmHead *pShmHead;

	GetHostTime(sUpdateTime);
	/*检测共享内存是否改变*/
	iShmID=shmget(shmkey,0,0400);/*30万次/秒*/
	
	pShmHead=(struct ShmHead*)AttachShm(shmkey,&iErrCode,0);
	if(iErrCode!=0) return -1;

	pShmHead->iShmID=iShmID;
	strcpy(pShmHead->sUpdateTime,sUpdateTime);
	if(iSize>0)
		pShmHead->iTotalLen=iSize;

	DetachShm((void*)pShmHead);
	
	return 0;
}
int GetShmHead(key_t shmkey,struct ShmHead *ptCur)
{
	int iErrCode=0;
	struct ShmHead *pShmHead;
	
	pShmHead=(struct ShmHead*)AttachShm(shmkey,&iErrCode,0);
	if(iErrCode!=0) return -1;
	
	memcpy((void*)ptCur,(void*)pShmHead,sizeof(struct ShmHead));
	
	DetachShm((void*)pShmHead);
	
	return 0;
}
int ShmHeadValid(key_t shmkey,struct ShmHead *pPre,struct ShmHead *pShmHead)
{
	int iShmID;

	/*检测共享内存是否改变*/
	iShmID=shmget(shmkey,0,0400);/*30万次/秒*/
	if(iShmID!=pPre->iShmID) return false;
	
	if(pShmHead->iTotalLen!=pPre->iTotalLen) return false;

	if(strcmp(pShmHead->sUpdateTime,pPre->sUpdateTime)!=0) return false;
	
	return true;
}
void *CreateShmInitHead(key_t iShmKey,POINTER iTotalLen,int *piErrCode)
{
	void *pData;
	
	pData=CreateShm(iShmKey,iTotalLen,piErrCode);
	
	if(*piErrCode) return NULL;
	DetachShm(pData);
	
	if(UpdateShmHead(iShmKey,iTotalLen)<0){
		*piErrCode=1;
		return NULL;
	}
	
	pData=AttachShm(iShmKey,piErrCode,0);
	if(*piErrCode) return NULL;
	
	return pData;
}
void *CreateMultiShm(key_t shmkey,POINTER iTotalLen,
	POINTER iBlockLen,struct FMemStruct *pMem)
{
	void *pTmp;
	struct FShmStruct *pShm;
	int i,k,iTempLen,iErrCode=0;
	int iBlockCnt=(int)((iTotalLen+iBlockLen-1)/iBlockLen);

	if(iBlockCnt>FLISTMAX) return NULL;

	bzero((void*)pMem,sizeof(struct FMemStruct));
	
	pMem->iTotalLen=iBlockLen*iBlockCnt;
	pMem->iBlockLen=iBlockLen;
	pMem->iBlockCnt=iBlockCnt;

	for(i=0;i<iBlockCnt;i++){
		
		if(i==iBlockCnt-1)	iTempLen=iTotalLen%(iBlockLen+1);
		else			iTempLen=iBlockLen;
			
		if(i==0){
			pTmp=CreateShmInitHead(shmkey,iBlockLen,&iErrCode);
			if(iErrCode!=0) return NULL;
			pShm=(struct FShmStruct*)pTmp;
			pShm->iBlockLen=iBlockLen;
			pShm->iBlockCnt=iBlockCnt;
			pMem->apHead[i]=pTmp;
			continue;
		}
		pTmp=CreateShm(shmkey+i,iTempLen,&iErrCode);
		if(iErrCode!=0){
			for(k=0;k<i;k++) DestroyShm(shmkey+k);
			return NULL;
		}
		pMem->apHead[i]=pTmp;
	}

	return (void*)pShm;
}
void DestroyMultiShm(key_t shmkey,struct FMemStruct *pMem)
{
	int i;

	for(i=0;i<pMem->iBlockCnt;i++){
		DestroyShm(shmkey+i);
		pMem->apHead[i]=NULL;
	}
}
void *AttachMultiShm(key_t shmkey,struct FMemStruct *pMem)
{
	void *pTmp;
	int i,k,iErrCode=0;
	struct FShmStruct *pShm;

	bzero((void*)pMem,sizeof(struct FMemStruct));

	pTmp=AttachShm(shmkey,&iErrCode,NULL);
	if(iErrCode!=0){
		DetachShm(pTmp);
		return NULL;
	}
	pMem->apHead[0]=pTmp;

	pShm=(struct FShmStruct *)pTmp;	
	for(i=1;i<pShm->iBlockCnt;i++){
		pTmp=AttachShm(shmkey+i,&iErrCode,NULL);
		if(iErrCode!=0){
			for(k=0;k<i;k++)DetachShm(pMem->apHead[k]);
			return NULL;
		}
		pMem->apHead[i]=pTmp;
	}
	pMem->iTotalLen=pShm->Head.iTotalLen;
	pMem->iBlockLen=pShm->iBlockLen;
	pMem->iBlockCnt=pShm->iBlockCnt;

	return (void*)pShm;
}
void DetachMultiShm(struct FMemStruct *pMem)
{
	int i;

	for(i=0;i<pMem->iBlockCnt;i++){
		DetachShm(pMem->apHead[i]);
		pMem->apHead[i]=NULL;
	}
}
void InitEShmCtrl(int iRecLen,int iRecCnt,void *pHead,POINTER ioffHead,
	struct ShmCtrlStruct *p)
{
	int i;

	bzero((void*)p,sizeof(struct ShmCtrlStruct));
	p->iRecLen=	iRecLen;
	p->iRecCnt=	iRecCnt;
	p->ioffFree=	-1;
	
	for(i=0;i<iRecCnt;i++){
		bzero((void*)OPELIST(pHead,ioffHead),iRecLen);
		InsertEList(pHead,&(p->ioffFree),ioffHead);
		ioffHead+=iRecLen;
	}
}

POINTER MallocEItem(void *pSeg,struct ShmCtrlStruct *ptHead)
{
	POINTER ioffNew;

	ioffNew=ptHead->ioffFree;
	if(ioffNew==-1) return -1;

	ptHead->ioffFree=OOELISTNXT(pSeg,ioffNew);
	ptHead->iUsedCnt++;
	
	return ioffNew;
}
void FreeEItem(void *pSeg,struct ShmCtrlStruct *ptHead,POINTER ioffValue)
{
	InsertEList(pSeg,&(ptHead->ioffFree),ioffValue);
	ptHead->iUsedCnt--;
}

POINTER InitFShmCtrl(int iRecLen,int iRecCnt,void *pHead,POINTER ioffHead,
	struct ShmCtrlStruct *p)
{
	int i;
	void *p1,*p2;
	POINTER ioffTmp=ioffHead;

	bzero((void*)p,sizeof(struct ShmCtrlStruct));
	p->iRecLen=	iRecLen;
	p->iRecCnt=	iRecCnt;
	p->ioffFree=	-1;
	
	for(i=0;i<iRecCnt;i++){

		if(FLISTLEN(pHead)<=ioffHead)return -1;
		
		p1=(void*)OPFLIST(pHead,ioffHead);
		p2=(void*)OPFLIST(pHead,ioffHead+iRecLen);
		if(p1==NULL||p2==NULL) return -1;

	/*如果内存块跨越共享内存块，则将这个块忽略*/
		while(((char*)p2-(char*)p1)!=iRecLen){

			ioffHead+=iRecLen;
			if(FLISTLEN(pHead)<=ioffHead)return -1;
	
			p1=(void*)OPFLIST(pHead,ioffHead);
			p2=(void*)OPFLIST(pHead,ioffHead+iRecLen);
			if(p1==NULL||p2==NULL) return -1;
		}
		bzero((void*)p1,iRecLen);
		InsertFList(pHead,&(p->ioffFree),ioffHead);
		ioffHead+=iRecLen;
	}
	return ioffHead-ioffTmp;
}

POINTER MallocFItem(void *pSeg,struct ShmCtrlStruct *ptHead)
{
	POINTER ioffNew;

	ioffNew=ptHead->ioffFree;
	if(ioffNew==-1) return -1;

	ptHead->ioffFree=OOFLISTNXT(pSeg,ioffNew);
	ptHead->iUsedCnt++;
	
	return ioffNew;
}
void FreeFItem(void *pSeg,struct ShmCtrlStruct *ptHead,POINTER ioffValue)
{
	InsertFList(pSeg,&(ptHead->ioffFree),ioffValue);
	ptHead->iUsedCnt--;
}

