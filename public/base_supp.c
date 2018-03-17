
#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <wwshm.h>

#include <bintree.h>
#include <trie.h>

#include "gen_supp.h"
#include "base_supp.h"
#include "param_intf.h"

char GetCommSearchType(struct CommSearchStruct *pTemp);

int SupposeIncreaseCnt(int iCnt)
{
	if(iCnt<100)	return 20;
	if(iCnt>100000) return 10000;
	if(iCnt<1000)	return 100;
	return iCnt/10;
}
int SupposeTotalCnt(int iCnt)
{
	return SupposeIncreaseCnt(iCnt)+iCnt;
}
/*计算共享内存大小*/
int CalcNeedShm(struct MemTableStruct *ptHead)
{
	int l,dCnt;

	l=ptHead->iRecCnt*ptHead->iRecLen;

	dCnt=SupposeIncreaseCnt(ptHead->iRecCnt);
	
	l+=dCnt*ptHead->iRecLen;
	
	ptHead->iTabLen=	l;
	if(l>1024*1024)	WriteProcMsg("name=%s size=%d,rec=%d.",
		ptHead->sTableName,l,ptHead->iRecLen);
	
	return l;
}
void InitCsc(void *pSeg,struct ShmCscStruct *pc)
{
	POINTER ioffset=0;
	int iRecCnt=0,iRecLen=0;
	struct ShmCtrlStruct *pShmCtl=NULL;

	pc->isCnt=SupposeTotalCnt(pc->isCnt);
	pc->imCnt=SupposeTotalCnt(pc->imCnt);
	pc->ilCnt=SupposeTotalCnt(pc->ilCnt);
	pc->ibCnt=SupposeTotalCnt(pc->ibCnt);
	pc->itCnt=SupposeTotalCnt(pc->itCnt);
	
	ioffset=sizeof(struct ShmPcbStruct)+sizeof(struct ShmCscStruct);

	iRecCnt=pc->isCnt;
	iRecLen=S_COMM_SEARCH_LEN;
	pShmCtl=&(pc->SItem);
	InitEShmCtrl(iRecLen,iRecCnt,pSeg,ioffset,pShmCtl);
	ioffset+=iRecLen*iRecCnt;

	iRecCnt=pc->imCnt;
	iRecLen=M_COMM_SEARCH_LEN;
	pShmCtl=&(pc->MItem);
	InitEShmCtrl(iRecLen,iRecCnt,pSeg,ioffset,pShmCtl);
	ioffset+=iRecLen*iRecCnt;

	iRecCnt=pc->ilCnt;
	iRecLen=S_COMM_SEARCH_LEN;
	pShmCtl=&(pc->LItem);
	InitEShmCtrl(iRecLen,iRecCnt,pSeg,ioffset,pShmCtl);
	ioffset+=iRecLen*iRecCnt;

	iRecCnt=pc->ibCnt;
	iRecLen=sizeof(EBINTREE);
	pShmCtl=&(pc->bNode);
	InitEShmCtrl(iRecLen,iRecCnt,pSeg,ioffset,pShmCtl);
	ioffset+=iRecLen*iRecCnt;

	iRecCnt=pc->itCnt;
	iRecLen=sizeof(ETRIE);
	pShmCtl=&(pc->tNode);
	InitEShmCtrl(iRecLen,iRecCnt,pSeg,ioffset,pShmCtl);
	ioffset+=iRecLen*iRecCnt;
}
POINTER MallocCSItem(void *pSeg,char cType,struct ShmCscStruct *pc)
{
	struct ShmCtrlStruct *ptHead;
	
	if(cType=='S')		ptHead=&(pc->SItem);
	else if(cType=='M')	ptHead=&(pc->MItem);
	else /*if(cType=='L')*/	ptHead=&(pc->LItem);
	
	return MallocEItem(pSeg,ptHead);
}
void FreeCSItem(void *pSeg,POINTER ioffset,struct ShmCscStruct *pc)
{
	struct ICommSearchStruct *p;
	struct ShmCtrlStruct *ptHead;
	
	p=(struct ICommSearchStruct*)OPELIST(pSeg,ioffset);
	
	if(p->cType=='S')	ptHead=&(pc->SItem);
	else if(p->cType=='M')	ptHead=&(pc->MItem);
	else /*if(cType=='L')*/	ptHead=&(pc->LItem);
	
	FreeEItem(pSeg,ptHead,ioffset);
}
void mvitem_commsearch2icommsearch(struct CommSearchStruct *pi,
	char cType,struct ICommSearchStruct *po)
{
/*
	bzero((void*)po,sizeof(struct ICommSearchStruct));
这里不能bzero,因为ICommSearch结构比较大会越界
*/

	po->ioffNext=-1;
	po->iIntKey=		pi->iIntKey;
	po->iIntVal=		pi->iIntVal;

	strcpy(po->sEffDate,	pi->sEffDate);
	strcpy(po->sExpDate,	pi->sExpDate);
	strcpy(po->sState,	pi->sState);
	strcpy(po->sStateDate,	pi->sStateDate);
	strcpy(po->sCreatedDate,pi->sCreatedDate);
	strcpy(po->sTableName,	pi->sTableName);
	po->cType=		cType;
	strcpy(po->sKey,	pi->sStrKey);
	
	if(cType=='S'){
		struct SKeyValStruct *p=(struct SKeyValStruct *)&(po->sKey);
		strcpy(p->sKey,	pi->sStrKey);
		strcpy(p->sVal,	pi->sStrVal);
	}
	else if(cType=='M'){
		struct MKeyValStruct *p=(struct MKeyValStruct *)&(po->sKey);
		strcpy(p->sKey,	pi->sStrKey);
		strcpy(p->sVal,	pi->sStrVal);
	}
	else /*if(cType=='L')*/{
		struct LKeyValStruct *p=(struct LKeyValStruct *)&(po->sKey);
		strcpy(p->sKey,	pi->sStrKey);
		strcpy(p->sVal,	pi->sStrVal);
	}
}
int data_search_bintree_comm_search_i(POINTER ioffValue,POINTER ioffData)
{
	int res;

	struct ICommSearchStruct *pSource;
	struct ICommSearchStruct *pTarget;

	pSource=(struct ICommSearchStruct *)OPELIST(PSHM,ioffValue);
	pTarget=(struct ICommSearchStruct *)OPELIST(PSHM,ioffData);

	if((res=pSource->iIntKey-pTarget->iIntKey)!=0) return res;
	if((res=strcmp(pSource->sTableName,pTarget->sTableName))!=0) return res;

	return strcmp(pSource->sKey,pTarget->sKey);
}
int comp_insert_list_comm_search_i(POINTER ioffValue,POINTER ioffHead)
{
	int res=0;
	struct ICommSearchStruct *pSource;
	struct ICommSearchStruct *pTarget;

	pSource=(struct ICommSearchStruct *)OPELIST(PSHM,ioffValue);
	pTarget=(struct ICommSearchStruct *)OPELIST(PSHM,ioffHead);
	
	
	if((res=pSource->iIntKey-pTarget->iIntKey)!=0) return res;
	if((res=strcmp(pSource->sTableName,pTarget->sTableName))!=0) return res;
	if((res=strcmp(pSource->sKey,pTarget->sKey))!=0) return res;

	if((res=strcmp(pTarget->sCreatedDate,pSource->sCreatedDate))!=0) return res;
	if((res=strcmp(pTarget->sStateDate,pSource->sStateDate))!=0) return res;

	return res;

}
void assign_insert_comm_search_i(POINTER *pioffHead,POINTER ioffValue)
{
	InsertEListSort(PSHM,pioffHead,ioffValue,
		comp_insert_list_comm_search_i);
}
/*拿到结构的类型*/
char GetCommSearchType(struct CommSearchStruct *pTemp)
{
	int lk,lv;
	
	lk=strlen(pTemp->sStrKey);
	lv=strlen(pTemp->sStrVal);

	if(lk<=MY_MAXS_LEN&&lv<=MY_MAXS_LEN) return 'S';
	
	if(lk<=MY_MAXM_LEN&&lv<=MY_MAXM_LEN) return 'M';
	
	return 'L';
}

/*统计节点数支持函数*/
static void assign_justdo_assign(void **pp,void *p)
{
	*pp=p;
}
int data_search_bintree_comm_search_e(void *pValue,void*pData)
{
	int res;
	struct CommSearchStruct *pSource=(struct CommSearchStruct *)pValue;
	struct CommSearchStruct *pTarget=(struct CommSearchStruct *)pData;

	if((res=pSource->iIntKey-pTarget->iIntKey)!=0) return res;
	if((res=strcmp(pSource->sTableName,pTarget->sTableName))!=0) return res;

	return strcmp(pSource->sStrKey,pTarget->sStrKey);
}
/*
1.计算出需要多少TRIE节点以及 smallcnt,middlecnt,largecnt;
*/
int CalcCommSearchTrie(struct MemTableStruct *pMem,int *pitNode,
	int *pisCnt,int *pimCnt,int *pilCnt)
{
	char cType;
	int j;
	TRIE *pStatRoot=NULL;
	struct CommSearchStruct *ptHead,*pTemp;
	
	ptHead=(struct CommSearchStruct *)(pMem->pHead);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		cType=GetCommSearchType(pTemp);
		
		if(cType=='S')		(*pisCnt)++;
		else if(cType=='M')	(*pimCnt)++;
		else /*if(cType=='L')*/	(*pilCnt)++;
		
		j=InsertTrie(&pStatRoot,pTemp->sStrKey,(void *)pTemp,
                	assign_justdo_assign);

                if(j<0) return -1;

                *pitNode+=j;
	}

	DestroyTrie(pStatRoot);
		
	return 0;
}
/*2.计算出需要多少BIN节点以及 smallcnt,middlecnt,largecnt;
*/
int CalcCommSearchBin(struct MemTableStruct *pMem,int *pibNode,
	int *pisCnt,int *pimCnt,int *pilCnt)
{
	char cType;
	int j;
	BINTREE *pStatRoot=NULL;
	struct CommSearchStruct *ptHead,*pTemp,Temp;
		
	ptHead=(struct CommSearchStruct *)(pMem->pHead);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		cType=GetCommSearchType(pTemp);
		
		if(cType=='S')		(*pisCnt)++;
		else if(cType=='M')	(*pimCnt)++;
		else /*if(cType=='L')*/	(*pilCnt)++;
		
		/*找到了就不需要特定节点*/
		if(SearchBin(pStatRoot,&Temp,data_search_bintree_comm_search_e,
			(void**)&pTemp)==FOUND) continue;

		/*没找到则插入，并统计节点数*/
		j=InsertBin(&pStatRoot,(void *)pTemp,
			data_search_bintree_comm_search_e,
                	assign_justdo_assign);

                if(j<0) return -1;

                (*pibNode)++;
	}

	DestroyBin(pStatRoot);
		
	return 0;
}

int MoveCommSearchToShm(void *pSeg,struct ShmCscStruct *pc,
	struct MemTableStruct *pbMem,struct MemTableStruct *ptMem)
{
	char cType;	
	POINTER ioffValue;
	struct CommSearchStruct *ptHead,*pTemp;
	struct ICommSearchStruct *po;

	WriteProcPrint("开始建立COMM_SEARCH_BIN共享内存树.");
	
/*做一个循环将数据加载到共享内存BINTREE中*/
	ptHead=(struct CommSearchStruct *)(pbMem->pHead);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		cType=GetCommSearchType(pTemp);
		
		/*分配不到内存*/
		if((ioffValue=MallocCSItem(pSeg,cType,pc))<0) return -1;
		
		po=(struct ICommSearchStruct *)OPELIST(pSeg,ioffValue);
		
		mvitem_commsearch2icommsearch(pTemp,cType,po);

		if(InsertEBin(pSeg,&(pc->ioffbRoot),&(pc->bNode),ioffValue,
			data_search_bintree_comm_search_i,
			assign_insert_comm_search_i)<0) return -1;
		
	}
	WriteProcPrint("建立COMM_SEARCH_BIN共享内存树完毕.");

/*再作一个循环将数据加载到共享内存TRIE中*/
	ptHead=(struct CommSearchStruct *)(ptMem->pHead);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		cType=GetCommSearchType(pTemp);
		
		/*分配不到内存*/
		if((ioffValue=MallocCSItem(pSeg,cType,pc))<0) return -1;
		
		po=(struct ICommSearchStruct *)OPELIST(pSeg,ioffValue);
		
		mvitem_commsearch2icommsearch(pTemp,cType,po);
        
		if(InsertETrie(pSeg,&(pc->iofftRoot),po->sKey,
			&(pc->tNode),ioffValue,
			assign_insert_comm_search_i)<0) return -1;
		
	}
	
	WriteProcPrint("建立COMM_SEARCH_TRIE共享内存树完毕,开始REHOOK.");

	/*将共享内存挂上去*/
	ReHookETrie(pSeg,pc->iofftRoot,pc->iofftRoot);

	return 0;
}
/*建立共享内存初始结构,并使PSHM指向共享内存*/
int BuildShmInit(struct MemTableStruct *ptHead,struct ShmCscStruct *pc)
{
	POINTER ioffset=sizeof(struct ShmPcbStruct);

	int iTotalLen=sizeof(struct ShmPcbStruct),iNewLen=0;
	int l,iErrCode=0,iTabCnt=0,i=0;
	struct MemTableStruct *pTemp;
	struct ShmTableStruct 	*pShmTab;
	struct ShmPcbStruct 	*pPcb;

	/*计算CSC块的大小*/
	iNewLen+=sizeof(struct ShmCscStruct);

	iNewLen+=SupposeTotalCnt(pc->isCnt)*S_COMM_SEARCH_LEN;
	
	iNewLen+=SupposeTotalCnt(pc->imCnt)*M_COMM_SEARCH_LEN;

	iNewLen+=SupposeTotalCnt(pc->ilCnt)*L_COMM_SEARCH_LEN;
	
	iNewLen+=SupposeTotalCnt(pc->ibCnt)*sizeof(EBINTREE);

	iNewLen+=SupposeTotalCnt(pc->itCnt)*sizeof(ETRIE);
	
	iTotalLen+=iNewLen;

	pTemp=ptHead;
	while(pTemp!=NULL){
		/*不计算COMM_SEARCH两张表*/
		if(LLike(pTemp->sTableName,"COMM_SEARCH")){
			pTemp=pTemp->pNext;
			continue;
		}

		l=CalcNeedShm(pTemp);
		if(l<0) return -1;
		iTotalLen+=l;
		iTabCnt++;
		pTemp=pTemp->pNext;
	}
	
	/*加入PCB块*/
	PSHM=CreateShm(SHM_PCB_KEY,iTotalLen,&iErrCode);
	if(iErrCode) return -1;
	
	pPcb=(struct ShmPcbStruct *)PSHM;
			
/*将数据加入到树中去*/
	memcpy((void*)OPELIST(PSHM,ioffset),(void*)pc,
		sizeof(struct ShmCscStruct));

/*初始化Csc结构*/
	InitCsc(PSHM,(struct ShmCscStruct*)OPELIST(PSHM,ioffset));

	pPcb->iTotalLen=iTotalLen;
	pPcb->iTabCnt=	iTabCnt;
	pPcb->iTabMax=	TABMAX;
	
	pPcb->ioffDataFree=sizeof(struct ShmPcbStruct)+iNewLen;
	
	pTemp=ptHead;
	i=0;
	while(pTemp!=NULL){
		pShmTab=&pPcb->ShmTab[i];
		
		strcpy(pShmTab->sTableName,pTemp->sTableName);
		pShmTab->iRecLen=	pTemp->iRecLen;
		pShmTab->iRecCnt=	pTemp->iRecCnt;
		pShmTab->iTabLen=	pTemp->iTabLen;
		
		pShmTab->iLock=		1;
		pShmTab->ioffset=	-1;
		i++;
		if(i>=pPcb->iTabMax){
			DetachShm(PSHM);
			return -1;
		}
		pTemp=pTemp->pNext;
	}
	
	WriteProcPrint("初始化共享内存数据结构完毕.");
	
	return 0;
}

/*参数从memtable--->shmtab,一张表*/
int MoveTableListToShm(struct MemTableStruct *ptHead)
{
	LIST *pTemp;
	POINTER ioffsetCur,ioffsetHead;
	struct ShmTableStruct 	*pShmTab;
	struct ShmPcbStruct 	*pPcb;
	int i=0,iRecCnt=0;
	
	pPcb=(struct ShmPcbStruct *)PSHM;
	
	for(i=0;i<pPcb->iTabCnt;i++){
		if(strcmp(ptHead->sTableName,pPcb->ShmTab[i].sTableName)==0)
			break;
	}
	pShmTab=&(pPcb->ShmTab[i]);
	if(i==pPcb->iTabCnt){
		if(i>=pPcb->iTabMax) return -1;

		strcpy(pShmTab->sTableName,ptHead->sTableName);
		pShmTab->iRecLen=	ptHead->iRecLen;
		pShmTab->iRecCnt=	ptHead->iRecCnt;
		pShmTab->iTabLen=	ptHead->iTabLen;
		
		pShmTab->iLock=		1;
		pShmTab->ioffset=	-1;
		pPcb->iTabCnt++;
		ioffsetHead=ioffsetCur=	pPcb->ioffDataFree;
		pPcb->ioffDataFree+=ptHead->iTabLen;

		if(pPcb->ioffDataFree>pPcb->iTotalLen) return -1;
	}
	else{
		if(pShmTab->ioffset==-1){
			ioffsetHead=ioffsetCur=	pPcb->ioffDataFree;
			pPcb->ioffDataFree+=ptHead->iTabLen;
		}
		else
			ioffsetHead=ioffsetCur=	pShmTab->ioffset;
	
		pShmTab->iRecLen=	ptHead->iRecLen;

		pShmTab->iLock=		1;
		pShmTab->ioffset=	-1;

		if((ptHead->iRecCnt*ptHead->iRecLen)>=pShmTab->iTabLen)
			return -1;
	}
/*啊，如果不存在的表，这里就建立了index结构*/
	
	pTemp=		ptHead->pHead;

	/*将链表数据移动到shm*/
	while(pTemp!=NULL){
		memcpy((void*)PPCBDATA(PSHM,ioffsetCur),
			(void*)pTemp,ptHead->iRecLen);

		pTemp=pTemp->pNext;
		ioffsetCur+=ptHead->iRecLen;
		iRecCnt++;
	}
	/*开锁*/
	pShmTab->ioffset=	ioffsetHead;
	pShmTab->iLock=		0;
	pShmTab->iRecCnt=	iRecCnt;
		
	return 0;
}

/*将表的数据加载到MemTableStruct链表中，所有表*/
int DataToMemTable(struct ShmTableRegStruct *ptHead,struct MemTableStruct **pptHead)
{
	int iTotalLen=sizeof(struct ShmPcbStruct);
	void *pTemp;
	struct MemTableStruct *pMem;

	while(ptHead!=NULL){
		if(ptHead->InitRecordList(&pTemp)<0) return -1;
		
		if((pMem=(struct MemTableStruct*)malloc(
			sizeof(struct MemTableStruct)))==NULL){
			PrintErr("malloc error datatomem.\n");
			return -1;
		}
		memset((void*)pMem,0,sizeof(struct MemTableStruct));
		pMem->iRecLen=	ptHead->iRecLen;
		strcpy(pMem->sTableName,ptHead->sTableName);
		pMem->iRecCnt=	CountList((LIST*)pTemp);
		pMem->iTabLen=	CalcNeedShm(pMem);
		pMem->pHead=pTemp;
		
		iTotalLen+=pMem->iTabLen;
	
		InsertList((LIST**)pptHead,(LIST*)pMem);
		
		ptHead=ptHead->pNext;
	}
	WriteProcMsg("total shm need=%d",iTotalLen);

	return 0;
}

int SearchMemTable(struct MemTableStruct *ptHead,char sTableName[],
	struct MemTableStruct **pptCur)
{
	*pptCur=NULL;

	while(ptHead!=NULL){
		if(strcmp(sTableName,ptHead->sTableName)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
int CscCntEnough(struct ShmCscStruct *pc,struct ShmCscStruct *shmpc)
{
	if(pc->isCnt>shmpc->isCnt||
		pc->imCnt>shmpc->imCnt||
		pc->ilCnt>shmpc->ilCnt||
		pc->ibCnt>shmpc->ibCnt||
		pc->itCnt>shmpc->itCnt) return false;
	return true;
}
int free_i_comm_search_list(POINTER *pioffHead)
{
	POINTER ioffHead,ioffTemp;
	struct ShmCscStruct *pc;
	struct ICommSearchStruct *pi;
	struct ShmCtrlStruct *pCtl;
	
	pc=(struct ShmCscStruct*)OPELIST(PSHM,sizeof(struct ShmPcbStruct));
	
	ioffHead=*pioffHead;
	
	while(ioffHead!=-1){
		ioffTemp=ioffHead;
		ioffHead=OPELIST(PSHM,ioffHead)->ioffNext;
		
		pi=(struct ICommSearchStruct *)OPELIST(PSHM,ioffTemp);

		/*考虑到ReHookTrie函数的关系，对已放到free链表
		中的记录cType设为0,对于已为0的记录则不重复free了*/		
		if(pi->cType==0) break;

		if(pi->cType=='S')	pCtl=&pc->SItem;
		else if(pi->cType=='M')	pCtl=&pc->MItem;
		else /*if(cType=='L')*/	pCtl=&pc->LItem;
		
		pi->cType=0;

		/*将内存放回到管理结构中*/
		FreeEItem(PSHM,pCtl,ioffTemp);
	}
	return 0;
}
void DestroyCscTrie()
{
	struct ShmCscStruct *pc;
	
	pc=(struct ShmCscStruct*)OPELIST(PSHM,sizeof(struct ShmPcbStruct));
	
	TravelETrie(PSHM,pc->iofftRoot,free_i_comm_search_list);
	
	DestroyETrie(PSHM,pc->iofftRoot,&pc->tNode);
	
	pc->iofftRoot=-1;
	
}
void DestroyCscBin()
{
	struct ShmCscStruct *pc;
	
	pc=(struct ShmCscStruct*)OPELIST(PSHM,sizeof(struct ShmPcbStruct));

	TravelEBin(PSHM,pc->ioffbRoot,free_i_comm_search_list);
	
	DestroyEBin(PSHM,pc->ioffbRoot,&pc->bNode);
	
	pc->ioffbRoot=-1;
}
/*将本地内存数据加载到共享内存，除了COMM_SEARCH的所有表*/
int MemTableToShm(struct MemTableStruct *ptHead,struct ShmCscStruct *pc)
{
	POINTER ioffset=sizeof(struct ShmPcbStruct);
	struct MemTableStruct *pTemp,*ptMem=NULL,*pbMem=NULL;
	struct ShmCscStruct *ps;
	struct ShmPcbStruct *pcb;

	WriteProcPrint("开始移动固定表数据到共享内存.");
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		/*如果表名是CommSearch打头的就不导入*/
		if(LLike(pTemp->sTableName,"COMM_SEARCH_BIN")){
			pbMem=pTemp;
			continue;
		}
		
		if(LLike(pTemp->sTableName,"COMM_SEARCH_TRIE")){
			ptMem=pTemp;
			continue;
		}

		if(MoveTableListToShm(pTemp)<0) return -1;

	}

	WriteProcPrint("移动固定表数据到共享内存完毕,开始free.");

	ps=(struct ShmCscStruct*)OPELIST(PSHM,ioffset);
	pcb=(struct ShmPcbStruct*)PSHM;

	/*将茶内存够不够*/
	if(CscCntEnough(pc,ps)==false) return -1;
	
	/*将CSC结构共享内存释放并加入*/
	DestroyCscTrie();
	WriteProcPrint("free,TRIE完毕.");
	DestroyCscBin();
	WriteProcPrint("free,BINTREE完毕.");

	/*内存放回管理结构中，如果还出现有使用的则出错*/
	if(ps->SItem.iUsedCnt!=0||
		ps->MItem.iUsedCnt!=0||
		ps->LItem.iUsedCnt!=0||
		ps->bNode.iUsedCnt!=0||
		ps->tNode.iUsedCnt!=0){
		printf("共享内存CSC树释放不彻底");
		return -1;
	}
	if(pbMem==NULL||ptMem==NULL){
		printf("程序逻辑错误，系统应注册COMM_SEARCH_BIN和COMM_SEARCH_TRIE表.\n");
		return -1;
	}
	if(MoveCommSearchToShm(PSHM,ps,pbMem,ptMem)<0) return -1;

	
	WriteProcPrint("数据加入共享内存成功,总空间%dM,其中pcb=%d字节,csc=%d字节,"
		"cb=%dM,ct=%dM,datablk=%dM",pcb->iTotalLen/1024/1024,
		sizeof(struct ShmPcbStruct),sizeof(struct ShmCscStruct),
		ps->bBytes/1024/1024,ps->tBytes/1024/1024,
		(pcb->iTotalLen-ps->bBytes-ps->tBytes)/1024/1024);
		
	return 0;
}

/*注册参数刷新函数*/
int RegShmTabFun(int (*InitRecordList)(void **pptHead),int iRecLen,char sTableName[],
	struct ShmTableRegStruct **pptHead)
{
	struct ShmTableRegStruct *pTemp;
	
	if((pTemp=(struct ShmTableRegStruct *)malloc(
		sizeof(struct ShmTableRegStruct)))==NULL) return -1;
	memset((void*)pTemp,0,sizeof(struct ShmTableRegStruct));
	
	pTemp->InitRecordList=	InitRecordList;
	pTemp->iRecLen=		iRecLen;
	strcpy(pTemp->sTableName,sTableName);
	
	InsertList((LIST**)pptHead,(LIST*)pTemp);
	return 0;
}


int RegTotalShmTab(struct ShmTableRegStruct **pptHead)
{
	int l;
	
	l=RegShmTabFun(IInitAcrossCellCode,
		sizeof(struct AcrossCellCodeStruct),
		"ACROSS_CELL_CODE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitAreaCodeDesc,
		sizeof(struct AreaCodeDescStruct),
		"AREA_CODE_DESC",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitT130AreaCode,
		sizeof(struct T130AreaCodeStruct),
		"T130_AREA_CODE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitTrunk,
		sizeof(struct TrunkStruct),
		"TRUNK",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitMsc,
		sizeof(struct MscStruct),
		"MSC",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitTelecomCarrier,
		sizeof(struct TelecomCarrierStruct),
		"TELECOM_CARRIER",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitTicketField,
		sizeof(struct TicketFieldStruct),
		"TICKET_FIELD",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitTicketFieldRule,
		sizeof(struct TicketFieldRuleStruct),
		"TICKET_FIELD_RULE",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitTicketFieldValue,
		sizeof(struct TicketFieldValueStruct),
		"TICKET_FIELD_VALUE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitSplitRule,
		sizeof(struct SplitRuleStruct),
		"SPLIT_RULE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitTollTariff,
		sizeof(struct TollTariffStruct),
		"TOLL_TARIFF",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitExprDef,
		sizeof(struct ExprDefStruct),
		"EXPR_DEF",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitExprDisct,
		sizeof(struct ExprDisctStruct),
		"EXPR_DISCT",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitHeadCarr,
		sizeof(struct HeadCarrStruct),
		"HEAD_CARR",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitTicketBasedDisct,
		sizeof(struct TicketBasedDisctStruct),
		"TICKET_BASED_DISCT",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitTicketType,
		sizeof(struct TicketTypeStruct),
		"TICKET_TYPE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitTicketTypeTariff,
		sizeof(struct TicketTypeTariffStruct),
		"TICKET_TYPE_TARIFF",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitTimeSpanDisct,
		sizeof(struct TimeSpanDisctStruct),
		"TIME_SPAN_DISCT",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitDisctRule,
		sizeof(struct DisctRuleStruct),
		"DISCT_RULE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitCellCode,
		sizeof(struct CellCodeStruct),
		"CELL_CODE",pptHead);
	if(l<0) return -1;
			
	l=RegShmTabFun(IInitDisctRuleMutex,
		sizeof(struct DisctRuleMutexStruct),
		"DISCT_RULE_MUTEX",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitInstParam,
		sizeof(struct InstParamStruct),
		"INST_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitPickParam,
		sizeof(struct PickParamStruct),
		"PICK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitPrepParam,
		sizeof(struct PrepParamStruct),
		"PREP_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitBillParam,
		sizeof(struct BillParamStruct),
		"BILL_PARAM",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitDispParam,
		sizeof(struct DispParamStruct),
		"DISP_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitCommSearchBin,
		sizeof(struct CommSearchStruct),
		"COMM_SEARCH_BIN",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitCommSearchTrie,
		sizeof(struct CommSearchStruct),
		"COMM_SEARCH_TRIE",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitCommRange,
		sizeof(struct CommRangeStruct),
		"COMM_RANGE",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitSwitch,
		sizeof(struct SwitchStruct),
		"SWITCH",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitCmdTemplate,
		sizeof(struct CmdTemplateStruct),
		"CMD_TEMPLATE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitNbrHead,
		sizeof(struct NbrHeadStruct),
		"NBR_HEAD",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitAcctItemType,
		sizeof(struct AcctItemTypeStruct),
		"ACCT_ITEM_TYPE",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitSettRule,
		sizeof(struct SettRuleStruct),
		"SETT_RULE",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitSettCycle,
		sizeof(struct SettCycleStruct),
		"SETT_CYCLE",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitLatn,
		sizeof(struct LatnStruct),
		"LATN",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitPutParam,
		sizeof(struct PutParamStruct),
		"PUT_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitCommParam,
		sizeof(struct CommParamStruct),
		"COMM_PARAM",pptHead);
	if(l<0) return -1;
	
	l=RegShmTabFun(IInitSettArea,
		sizeof(struct SettAreaStruct),
		"SETT_AREA",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitFlowApp,
		sizeof(struct FlowAppStruct),
		"FLOW_APP",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitFlowTask,
		sizeof(struct FlowTaskStruct),
		"FLOW_TASK",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitFlowTache,
		sizeof(struct FlowTacheStruct),
		"FLOW_TACHE",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitTaskParam,
		sizeof(struct TaskParamStruct),
		"TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitAcctTaskParam,
		sizeof(struct AcctTaskParamStruct),
		"ACCT_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitBillTaskParam,
		sizeof(struct BillTaskParamStruct),
		"BILL_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitInstTaskParam,
		sizeof(struct InstTaskParamStruct),
		"INST_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitIntfTaskParam,
		sizeof(struct IntfTaskParamStruct),
		"INTF_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitPickTaskParam,
		sizeof(struct PickTaskParamStruct),
		"PICK_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitPrepTaskParam,
		sizeof(struct PrepTaskParamStruct),
		"PREP_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitPutTaskParam,
		sizeof(struct PutTaskParamStruct),
		"PUT_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitRcylTaskParam,
		sizeof(struct RcylTaskParamStruct),
		"RCYL_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitRollTaskParam,
		sizeof(struct RollTaskParamStruct),
		"ROLL_TASK_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitAcctParam,
		sizeof(struct AcctParamStruct),
		"ACCT_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitIntfParam,
		sizeof(struct IntfParamStruct),
		"INTF_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitRcylParam,
		sizeof(struct RcylParamStruct),
		"RCYL_PARAM",pptHead);
	if(l<0) return -1;

	l=RegShmTabFun(IInitRollParam,
		sizeof(struct RollParamStruct),
		"ROLL_PARAM",pptHead);
	if(l<0) return -1;
	l=RegShmTabFun(IInitSourceDesc,
		sizeof(struct SourceDescStruct),
		"SOURCE_DESC",pptHead);
	if(l<0) return -1;

	return 0;
}

/*********加载函数封装部分*******************/
int IInitAcrossCellCode(void **pptHead)
{
	return InitAcrossCellCode( (struct AcrossCellCodeStruct **)pptHead);
}
int IInitAreaCodeDesc(void **pptHead)
{
	return InitAreaCodeDesc( (struct AreaCodeDescStruct **)pptHead);
}
int IInitT130AreaCode(void **pptHead)
{
	return InitT130AreaCode( (struct T130AreaCodeStruct **)pptHead);
}
int IInitTrunk(void **pptHead)
{
	return InitTrunk( (struct TrunkStruct **)pptHead);
}

int IInitMsc(void **pptHead)
{
	return InitMsc( (struct MscStruct **)pptHead);
}
int IInitTelecomCarrier(void **pptHead)
{
	return InitTelecomCarrier( (struct TelecomCarrierStruct **)pptHead);
}
int IInitTicketField(void **pptHead)
{
	return InitTicketField( (struct TicketFieldStruct **)pptHead);
}
int IInitTicketFieldRule(void **pptHead)
{
	return InitTicketFieldRule( (struct TicketFieldRuleStruct **)pptHead);
}
int IInitTicketFieldValue(void **pptHead)
{
	return InitTicketFieldValue( (struct TicketFieldValueStruct **)pptHead);
}
int IInitSplitRule(void **pptHead)
{
	return InitSplitRule( (struct SplitRuleStruct **)pptHead);
}
int IInitTollTariff(void **pptHead)
{
	return InitTollTariff( (struct TollTariffStruct **)pptHead);
}
int IInitExprDef(void **pptHead)
{
	return InitExprDef( (struct ExprDefStruct **)pptHead);
}
int IInitExprDisct(void **pptHead)
{
	return InitExprDisct( (struct ExprDisctStruct **)pptHead);
}
int IInitHeadCarr(void **pptHead)
{
	return InitHeadCarr( (struct HeadCarrStruct **)pptHead);
}
int IInitTicketBasedDisct(void **pptHead)
{
	return InitTicketBasedDisct( (struct TicketBasedDisctStruct **)pptHead);
}
int IInitTicketType(void **pptHead)
{
	return InitTicketType( (struct TicketTypeStruct **)pptHead);
}
int IInitTicketTypeTariff(void **pptHead)
{
	return InitTicketTypeTariff( (struct TicketTypeTariffStruct **)pptHead);
}
int IInitTimeSpanDisct(void **pptHead)
{
	return InitTimeSpanDisct( (struct TimeSpanDisctStruct **)pptHead);
}
int IInitDisctRule(void **pptHead)
{
	return InitDisctRule( (struct DisctRuleStruct **)pptHead);
}
int IInitCellCode(void **pptHead)
{
	return InitCellCode( (struct CellCodeStruct **)pptHead);
}
int IInitDisctRuleMutex(void **pptHead)
{
	return InitDisctRuleMutex((struct DisctRuleMutexStruct**)pptHead);
}
int IInitDispParam(void **pptHead)
{
	return InitDispParam((struct DispParamStruct**)pptHead);
}
int IInitInstParam(void **pptHead)
{
	return InitInstParam((struct InstParamStruct**)pptHead);
}
int IInitPickParam(void **pptHead)
{
	return InitPickParam((struct PickParamStruct**)pptHead);
}
int IInitPrepParam(void **pptHead)
{
	return InitPrepParam((struct PrepParamStruct**)pptHead);
}
int IInitBillParam(void **pptHead)
{
	return InitBillParam((struct BillParamStruct**)pptHead);
}
int IInitCommSearchBin(void **pptHead)
{
	return InitCommSearchBin((struct CommSearchStruct**)pptHead);
}
int IInitCommSearchTrie(void **pptHead)
{
	return InitCommSearchTrie((struct CommSearchStruct**)pptHead);
}
int IInitCommRange(void **pptHead)
{
	return InitCommRange((struct CommRangeStruct**)pptHead);
}
int IInitSwitch(void **pptHead)
{
	return InitSwitch((struct SwitchStruct**)pptHead);
}
int IInitCmdTemplate(void **pptHead)
{
	return InitCmdTemplate((struct CmdTemplateStruct**)pptHead);
}
int IInitNbrHead(void **pptHead)
{
	return InitNbrHead((struct NbrHeadStruct**)pptHead);
}
int IInitAcctItemType(void **pptHead)
{
	return InitAcctItemType((struct AcctItemTypeStruct**)pptHead);
}
int IInitSettRule(void **pptHead)
{
	return InitSettRule((struct SettRuleStruct**)pptHead);
}
int IInitSettCycle(void **pptHead)
{
	return InitSettCycle((struct SettCycleStruct**)pptHead);
}
int IInitLatn(void **pptHead)
{
	return InitLatn((struct LatnStruct**)pptHead);
}
int IInitPutParam(void **pptHead)
{
	return InitPutParam((struct PutParamStruct**)pptHead);
}
int IInitCommParam(void **pptHead)
{
	return InitCommParam((struct CommParamStruct**)pptHead);
}
/***2006/07/11加**/
int IInitSettArea(void **pptHead)
{
	return InitSettArea((struct SettAreaStruct**)pptHead);
}
int IInitFlowApp(void **pptHead)
{
	return InitFlowApp((struct FlowAppStruct**)pptHead);
}
int IInitFlowTask(void **pptHead)
{
	return InitFlowTask((struct FlowTaskStruct**)pptHead);
}
int IInitFlowTache(void **pptHead)
{
	return InitFlowTache((struct FlowTacheStruct**)pptHead);
}
int IInitTaskParam(void **pptHead)
{
	return InitTaskParam((struct TaskParamStruct**)pptHead);
}
int IInitAcctTaskParam(void **pptHead)
{
	return InitAcctTaskParam((struct AcctTaskParamStruct**)pptHead);
}
int IInitBillTaskParam(void **pptHead)
{
	return InitBillTaskParam((struct BillTaskParamStruct**)pptHead);
}
int IInitInstTaskParam(void **pptHead)
{
	return InitInstTaskParam((struct InstTaskParamStruct**)pptHead);
}
int IInitIntfTaskParam(void **pptHead)
{
	return InitIntfTaskParam((struct IntfTaskParamStruct**)pptHead);
}
int IInitPickTaskParam(void **pptHead)
{
	return InitPickTaskParam((struct PickTaskParamStruct**)pptHead);
}
int IInitPrepTaskParam(void **pptHead)
{
	return InitPrepTaskParam((struct PrepTaskParamStruct**)pptHead);
}
int IInitPutTaskParam(void **pptHead)
{
	return InitPutTaskParam((struct PutTaskParamStruct**)pptHead);
}
int IInitRcylTaskParam(void **pptHead)
{
	return InitRcylTaskParam((struct RcylTaskParamStruct**)pptHead);
}
int IInitRollTaskParam(void **pptHead)
{
	return InitRollTaskParam((struct RollTaskParamStruct**)pptHead);
}
int IInitAcctParam(void **pptHead)
{
	return InitAcctParam((struct AcctParamStruct**)pptHead);
}
int IInitIntfParam(void **pptHead)
{
	return InitIntfParam((struct IntfParamStruct**)pptHead);
}
int IInitRcylParam(void **pptHead)
{
	return InitRcylParam((struct RcylParamStruct**)pptHead);
}
int IInitRollParam(void **pptHead)
{
	return InitRollParam((struct RollParamStruct**)pptHead);
}
int IInitSourceDesc(void **pptHead)
{
	return InitSourceDesc((struct SourceDescStruct**)pptHead);
}
