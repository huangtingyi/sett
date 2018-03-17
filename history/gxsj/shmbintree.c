#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <hnixs.h>
#include <wwsem.h>
#include <wwshm.h>
#include "list.h"
#include <bintree.h>
#include <trie.h>
#include <wwlog.h>
#include <wwtiny.h>
#include "shmbintree.h"

struct FMemStruct FMem;
char asShmArea[SHM_AREA_CNT][SHM_AREA_SIZE ];
int  iShmAreaSize=SHM_AREA_SIZE;
int  iShmAreaCnt=SHM_AREA_CNT;

void assign_bin_e_list(POINTER *piOffHead,POINTER ioffValue/*数据偏移*/)
{
	*piOffHead=ioffValue;
	//InsertFList((void*)&FMem,piOffHead,ioffValue);
}

int MvShm2List(struct FMemStruct *pFMem,
	int iOffHead,int iMemberSize,LIST **pptHead)
{
	int iCnt=0;
	void *p=NULL;
	LIST *pTemp=NULL;
	
	while(iOffHead!=-1){
		p=OPFLIST(pFMem,iOffHead);
		if ((pTemp = (LIST *)malloc(iMemberSize))==NULL){
			printf("分配置LIST节点内存失败!\n");
			return -1;
		}

		memcpy((char *)pTemp+sizeof(pTemp->pNext),
			(char *)p+sizeof(POINTER),
			iMemberSize-sizeof(pTemp->pNext));		
		InsertList(pptHead,pTemp);
		iCnt++;
		
		iOffHead=OOFLISTNXT(pFMem,iOffHead);
	}	
	return iCnt;
}

int MvList2ShmBinTree(struct ShmBinTreeHead *ptHead,LIST *ptData,int iSize,
	int4b ( *pFunction)(POINTER,POINTER)){
        	
	struct CommShmStruct *pTemp=NULL; 
	POINTER iOffHead=-1,iOffRoot=-1,ioffNew,ioffCur;
	LIST *pLHead=NULL,*pLTemp=NULL;
	
	pLHead = ptData;
	ioffNew=(ptHead->Item).ioffFree;
	
	while( pLHead != NULL ){
		
		pLTemp = pLHead;
		pLHead = pLHead->pNext;
		
		if (ioffNew==-1) break;
		ioffCur=ioffNew;
		ioffNew=OOFLISTNXT(&FMem,ioffCur);
		
		/*取得当前的空节点。*/
		pTemp=(struct CommShmStruct *)OPFLIST(&FMem,ioffCur);
		
		/*此处直接copy整个节点，pTemp->ioffNext在memcpy完后为LIST->pNext
		的值，将在insertFlist处重置。结果正确，
		此处如为保险起见也可以加POINTER或void *的偏移
		来处理（需要处理32位主机及64位主机sizeof(指针)大小的不同.）
		memcpy(pTemp,pLTemp,iSize);*/
		memcpy((char *)pTemp+sizeof(POINTER),
			(char *)pLTemp+sizeof(pLTemp->pNext),
			iSize-sizeof(pLTemp->pNext));
		
		/*将当前节点插入链表和树.*/
		InsertFList((void*)&FMem,&iOffHead,ioffCur);
		InsertFBin((void*)&FMem,&iOffRoot,
			&(ptHead->BinTree),iOffHead,
			pFunction,assign_bin_e_list);		
	}
	
	ptHead->iOffRoot = iOffRoot;
	ptHead->iOffHead = iOffHead;
	
	return 0;
}

int SearchShmBinTree(struct ShmBinTreeHead *pShm,
	void *pValue,int ( *pFunction)(void *,POINTER),void **pptCur)
{
	POINTER ioffCur=-1;
	void *pTemp=NULL;	
	
	*pptCur=NULL;
	
	SearchFBin((void*)&FMem, pShm->iOffRoot,pValue,
		pFunction,&ioffCur);

	if(ioffCur!=-1){
		pTemp=(struct TestItemShmStruct*)OPFLIST(&FMem,ioffCur);
		if (pTemp==NULL) return NOTFOUND;
		*pptCur = pTemp;
		return FOUND;
	}
		
	return NOTFOUND;
}
void AttachBinTreeShm(struct FBinTreeShmStruct **pptHead,int iShmID){
	InitBinTreeShm(pptHead,iShmID);
}

/*使用这边的头部struct FBinTreeShmStruct,以保留记录数和记录大小*/
void InitBinTreeShm(struct FBinTreeShmStruct **pptHead,int iShmID)
{
	int iTotalLen;
	struct FBinTreeShmStruct *pShm=NULL;
	
	iTotalLen=iShmAreaSize*iShmAreaCnt;
	
/*todo:重新计算需要的内存的大小。。。
iRecLen*iRecCnt+sizeof(EBINTREE)*iRecCnt+sizeof(struct FBinTreeShmStruct)+冗余。
*/
	
	/*CreateMulti*/
	if((pShm=AttachMultiShm(iShmID,&FMem))==NULL){
			
		if((pShm=CreateMultiShm(iShmID,iTotalLen,iShmAreaSize,
			&FMem))==NULL){
			printf("error.\n");
			exit(1);
		}
		
		bzero(pShm,sizeof(struct FBinTreeShmStruct));
		
		GetHostTime((pShm->Head).sUpdateTime);
		(pShm->Head).iTotalLen = iTotalLen;
		(pShm->Head).iShmID = iShmID;
		pShm->iBlockLen=iShmAreaSize;
		pShm->iBlockCnt=iShmAreaCnt;
		
		/*新建时初始化*//*注意是使用FBinTreeShmStruct噢。*/
		pShm->ioffset=sizeof(struct FBinTreeShmStruct);
	}
	
	*pptHead = pShm;
}

struct ShmBinTreeHead *GetShmBinTree(struct FBinTreeShmStruct *pShm,char sName[])
{
	struct ShmBinTreeHead *pBTree=NULL;
	int i;
	
	assert(pShm!=NULL);
	assert(sName!=NULL&&strlen(sName)!=0);
	
	for( i=0;i<MAX_BINTREE_NUM;i++ ){
		if (strcmp((pShm->BTree[i]).sName,sName)==0){
			pBTree=&(pShm->BTree[i]);
			break;
		}
	}
	
	return pBTree;
	
}

struct ShmBinTreeHead *AttachShmBinTree(char sName[])
{
	static int iFirstFlag=true;
	static struct FBinTreeShmStruct *ptBin=NULL;
	struct ShmBinTreeHead *pTree=NULL;
	
	if (iFirstFlag==true){
		AttachBinTreeShm(&ptBin,MULTI_SHM_ID);
		iFirstFlag = false;
	}
	
	assert(ptBin!=NULL);
	
	pTree = GetShmBinTree(ptBin,sName);
	if (pTree == NULL){
		printf("未找到名字为%s的BINTREE.\n",sName);
		return NULL;
	}
	
	return pTree;
}

struct ShmBinTreeHead * AddShmBinTree(struct FBinTreeShmStruct *pShm,
	char sName[],int iRecLen,int iRecCnt)
{
	struct ShmBinTreeHead *pBTree=NULL;
		
	int i=0;
	
	assert(pShm!=NULL);
	assert(sName!=NULL&&strlen(sName)!=0);
	assert(iRecLen!=0);
	assert(iRecCnt!=0);
	
	if (pShm->ioffset+iRecLen*iRecCnt+
		iRecCnt*sizeof(EBINTREE) > (pShm->Head).iTotalLen ){
		printf("申请的节点数需要要的内存大于共享内存"
			"所拥有的空闲内存，增加树失败！请调整共享内存大小.\n");
		return NULL;
	}
	
	for( i=0;i<MAX_BINTREE_NUM;i++ ){
		if (strlen((pShm->BTree[i]).sName)==0){
			pBTree=&(pShm->BTree[i]);
			break;
		}
	}
	
	if (pBTree==NULL||i==MAX_BINTREE_NUM){
		printf("添加BINTREE失败，超过MAX_BINTREE_NUM限制的最大数量，"
			"可在程序开始时重新定义MAX_BINTREE_NUM值。"
			"#define MAX_BINTREE_NUM xxx\n");
		return NULL;
	}
	
	/*设置记录数据和记录大小*/
	pBTree->iRecLen = iRecLen;
	pBTree->iRecCnt = iRecCnt;
	strcpy(pBTree->sName,sName);
	
	pShm->ioffset+=InitFShmCtrl(iRecLen,iRecCnt,
		(void*)&FMem,pShm->ioffset,&(pBTree->Item));

	pShm->ioffset+=InitFShmCtrl(sizeof(EBINTREE),iRecCnt,
		(void*)&FMem,pShm->ioffset,&(pBTree->BinTree));
		
	return pBTree;
}

