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

void assign_bin_e_list(POINTER *piOffHead,POINTER ioffValue/*����ƫ��*/)
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
			printf("������LIST�ڵ��ڴ�ʧ��!\n");
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
		
		/*ȡ�õ�ǰ�Ŀսڵ㡣*/
		pTemp=(struct CommShmStruct *)OPFLIST(&FMem,ioffCur);
		
		/*�˴�ֱ��copy�����ڵ㣬pTemp->ioffNext��memcpy���ΪLIST->pNext
		��ֵ������insertFlist�����á������ȷ��
		�˴���Ϊ�������Ҳ���Լ�POINTER��void *��ƫ��
		��������Ҫ����32λ������64λ����sizeof(ָ��)��С�Ĳ�ͬ.��
		memcpy(pTemp,pLTemp,iSize);*/
		memcpy((char *)pTemp+sizeof(POINTER),
			(char *)pLTemp+sizeof(pLTemp->pNext),
			iSize-sizeof(pLTemp->pNext));
		
		/*����ǰ�ڵ�����������.*/
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

/*ʹ����ߵ�ͷ��struct FBinTreeShmStruct,�Ա�����¼���ͼ�¼��С*/
void InitBinTreeShm(struct FBinTreeShmStruct **pptHead,int iShmID)
{
	int iTotalLen;
	struct FBinTreeShmStruct *pShm=NULL;
	
	iTotalLen=iShmAreaSize*iShmAreaCnt;
	
/*todo:���¼�����Ҫ���ڴ�Ĵ�С������
iRecLen*iRecCnt+sizeof(EBINTREE)*iRecCnt+sizeof(struct FBinTreeShmStruct)+���ࡣ
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
		
		/*�½�ʱ��ʼ��*//*ע����ʹ��FBinTreeShmStruct�ޡ�*/
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
		printf("δ�ҵ�����Ϊ%s��BINTREE.\n",sName);
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
		printf("����Ľڵ�����ҪҪ���ڴ���ڹ����ڴ�"
			"��ӵ�еĿ����ڴ棬������ʧ�ܣ�����������ڴ��С.\n");
		return NULL;
	}
	
	for( i=0;i<MAX_BINTREE_NUM;i++ ){
		if (strlen((pShm->BTree[i]).sName)==0){
			pBTree=&(pShm->BTree[i]);
			break;
		}
	}
	
	if (pBTree==NULL||i==MAX_BINTREE_NUM){
		printf("���BINTREEʧ�ܣ�����MAX_BINTREE_NUM���Ƶ����������"
			"���ڳ���ʼʱ���¶���MAX_BINTREE_NUMֵ��"
			"#define MAX_BINTREE_NUM xxx\n");
		return NULL;
	}
	
	/*���ü�¼���ݺͼ�¼��С*/
	pBTree->iRecLen = iRecLen;
	pBTree->iRecCnt = iRecCnt;
	strcpy(pBTree->sName,sName);
	
	pShm->ioffset+=InitFShmCtrl(iRecLen,iRecCnt,
		(void*)&FMem,pShm->ioffset,&(pBTree->Item));

	pShm->ioffset+=InitFShmCtrl(sizeof(EBINTREE),iRecCnt,
		(void*)&FMem,pShm->ioffset,&(pBTree->BinTree));
		
	return pBTree;
}

