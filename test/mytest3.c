#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwsem.h>
#include <wwshm.h>
#include "list.h"
#include <bintree.h>
#include <trie.h>
#include <wwlog.h>
#include <wwtiny.h>

struct TestItemStruct
{
	POINTER ioffNxt;
	char	sValue[32];
};

struct ShmTestHead
{
	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	struct ShmCtrlStruct Item;
	struct ShmCtrlStruct BinTree;
	struct ShmCtrlStruct Trie;

	struct TestItemStruct d0[10];
	EBINTREE d1[10];
	ETRIE 	 d2[100];

	POINTER ioffHead;
	POINTER ioffTrie;
};

struct ShmTestHead TestHead;

struct FMemStruct Test;
char	asShmArea[3][2*1024];

void InitShmTest(struct ShmTestHead *p);
void InitTestHead(struct ShmTestHead *p);
void PrintTestItemList(POINTER ioffHead);


int comp_e_list_test(POINTER ioffSource,POINTER ioffTarget)
{
	struct TestItemStruct *pSource;
	struct TestItemStruct *pTarget;
	
	pSource=(struct TestItemStruct *)OPFLIST(&Test,ioffSource);
	pTarget=(struct TestItemStruct *)OPFLIST(&Test,ioffTarget);
	
	return strcmp(pSource->sValue,pTarget->sValue);
}
int comp_search_e_list(void *pValue,POINTER ioffTarget)
{
	struct TestItemStruct *pTarget;	
	char *sValue=(char*)pValue;
	
	pTarget=(struct TestItemStruct *)OPFLIST(&Test,ioffTarget);
	
	return strcmp(sValue,pTarget->sValue);
}
void assign_bin_e_list(POINTER *pioffHead,POINTER ioffValue/*Êý¾ÝÆ«ÒÆ*/)
{
	*pioffHead=ioffValue;
}
int print_item(POINTER *pioffHead)
{
	struct TestItemStruct *pTarget;
	
	if(*pioffHead==-1) return 0;
	
	pTarget=(struct TestItemStruct *)OPFLIST(&Test,*pioffHead);
	
	printf("in print item value=%s.\n",pTarget->sValue);
	return 0;
}
int main()
{
	int i=0;
	struct ShmTestHead *p;
	EBINTREE *pEBin;
	struct TestItemStruct *pTemp;
	POINTER ioffHead=-1,ioffNew,ioffCur,ioffTmp;
	POINTER ioffRoot=-1,ioffTrie=-1,*pioffTmp;
	
	p=&TestHead;
	InitShmTest(&TestHead);
	InitTestHead(&TestHead);
	
	ioffNew=TestHead.Item.ioffFree;
	
	while(ioffNew!=-1){
		ioffCur=ioffNew;
		ioffNew=OOFLISTNXT(&Test,ioffCur);
		
		pTemp=(struct TestItemStruct *)OPFLIST(&Test,ioffCur);
		strcpy(pTemp->sValue,p->d0[i%10].sValue);
		if(i<10)pTemp->sValue[0]='1';
		i++;
		InsertFList((void*)&Test,&ioffHead,ioffCur);
/*		InsertFListSort((void*)&Test,&ioffHead,ioffCur,
			comp_e_list_test);
*/
	}
	printf("=======after sort==================.\n");
	PrintTestItemList(ioffHead);

	ioffTmp=ioffHead;


/*	ETRIE²âÊÔ..*/
	ioffNew=ioffHead=ioffTmp;
	while(ioffNew!=-1){

		DeleteFList((void*)&Test,&ioffHead,ioffNew);
		pTemp=(struct TestItemStruct*)OPFLIST(&Test,ioffNew);
		
		InsertFTrie((void*)&Test,&ioffTrie,pTemp->sValue,
			&(TestHead.Trie),ioffNew,assign_bin_e_list);
		ioffNew=ioffHead;
	}

	SearchFTrie((void*)&Test,ioffTrie,(void*)"003",&ioffCur);

	if(ioffCur!=-1){
		pTemp=(struct TestItemStruct*)OPFLIST(&Test,ioffCur);
		printf("the value is %s.\n",pTemp->sValue);
	}
	else printf("the value not found.\n");
		
	pioffTmp=GetFTrieLk((void*)&Test, ioffTrie,(void*)"003");
	if(pioffTmp!=NULL){
		ioffCur=*pioffTmp;
		*pioffTmp=-1;	
		pTemp=(struct TestItemStruct*)OPFLIST(&Test,ioffCur);
		printf("the value is %s,22.\n",pTemp->sValue);
	}
	else
		 printf("the value not found,GetETrie.\n");
	
	TravelFTrieD((void*)&Test,ioffTrie,print_item);

	printf(" the Ftrie test ok.\n");

/*	Æ½ºâ¶þ²æÊ÷²âÊÔ..*/
	i=0;
	ioffNew=ioffHead=ioffTmp;
	while(ioffNew!=-1){

		DeleteFList((void*)&Test,&ioffHead,ioffNew);
	
		printf("the cur cnt=%d.\n",i);
		
		InsertFBin((void*)&Test,&ioffRoot,
			&(TestHead.BinTree),ioffNew,
			comp_e_list_test,
			assign_bin_e_list);
		printf("the cur cnt++=%d.\n",i++);
		
		ioffNew=ioffHead;
	}

	SearchFBin((void*)&Test, ioffRoot,(void*)"003",
		comp_search_e_list,&ioffCur);
	if(ioffCur!=-1){
		pTemp=(struct TestItemStruct*)OPFLIST(&Test,ioffCur);
		printf("the value is %s.\n",pTemp->sValue);
	}
	else printf("the value not found.\n");
		
	TravelFBin((void*)&Test,ioffRoot,print_item);

	ioffCur=-1;
	DeleteFBin((void*)&Test,&ioffRoot,(void*)"004",
		comp_search_e_list,&ioffCur);
	if(ioffCur!=-1){
		pEBin=(EBINTREE*)OPFLIST(&Test,ioffCur);
		ioffCur=pEBin->ioffData;
		pTemp=(struct TestItemStruct*)OPFLIST(&Test,ioffCur);
		printf("the deleted value is %s,%ld.\n",pTemp->sValue,ioffCur);
	}
	else printf("the value delete error.\n");
	
	TravelFBin((void*)&Test,ioffRoot,print_item);
	
	exit(1);
/**	
	printf("=======delete 1 ==================.\n");
	DeleteEList((void*)&TestHead,&ioffHead,((char*)(&(p->d0[3]))-(char*)p) );
	PrintTestItemList(ioffHead);
	printf("=======append 1 to tail==========================.\n");
	InsertEListTail((void*)&TestHead,&ioffHead,((char*)(&(p->d0[3]))-(char*)p) );
	PrintTestItemList(ioffHead);
	printf("=======reverse list ==========================.\n");
	ReverseEList((void*)&TestHead,&ioffHead);
	PrintTestItemList(ioffHead);
	printf("=======search e list ==========================.\n");
	ioffCur=-1;
	SearchEList((void*)&TestHead, ioffHead,(void*)"003",&ioffCur,
		comp_search_e_list);
	if(ioffCur!=-1){
		pTemp=(struct TestItemStruct*)OPELIST(&TestHead,ioffCur);
		printf("the value is %s.\n",pTemp->sValue);
	}
	else printf("the value not found.\n");
*/	
	return 0;
}
void PrintTestItemList(POINTER ioffHead)
{
	int i=0;
	struct TestItemStruct *pTemp;
	
	while(ioffHead!=-1){
		pTemp=(struct TestItemStruct*)OPFLIST(&Test,ioffHead);
		
		printf("the %d value is %s.\n",i++,pTemp->sValue);
		
		ioffHead=OOFLISTNXT(&Test,ioffHead);
	}
}
void InitTestHead(struct ShmTestHead *p)
{
	strcpy(p->d0[0].sValue,"000");
	strcpy(p->d0[3].sValue,"001");
	strcpy(p->d0[1].sValue,"002");
	strcpy(p->d0[2].sValue,"003");
	strcpy(p->d0[4].sValue,"004");
	strcpy(p->d0[5].sValue,"005");
	strcpy(p->d0[6].sValue,"006");
	strcpy(p->d0[7].sValue,"007");
	strcpy(p->d0[8].sValue,"008");
	strcpy(p->d0[9].sValue,"009");
}

void InitShmTest(struct ShmTestHead *p)
{
	POINTER ioffset=0;
	
	p->iShmID=100;
	p->iTotalLen=sizeof(asShmArea);
	GetHostTime(p->sUpdateTime);
	
	bzero((void*)&Test,sizeof(struct FMemStruct));
	Test.iTotalLen=p->iTotalLen;
	Test.iBlockLen=sizeof(asShmArea)/3;
	Test.apHead[0]=&(asShmArea[0][0]);
	Test.apHead[1]=&(asShmArea[1][0]);
	Test.apHead[2]=&(asShmArea[2][0]);
	
	/*CreateMulti*/
	if(AttachMultiShm(0x7000,&Test)==NULL){
		printf("attach error.\n");
		if(CreateMultiShm(0x7000,p->iTotalLen,sizeof(asShmArea)/3,
			&Test)==NULL){
			printf("error.\n");
			exit(1);
		}
	}
	ioffset=sizeof(struct FShmStruct);
	
	ioffset+=InitFShmCtrl(sizeof(struct TestItemStruct),20,
		(void*)&Test,ioffset,&(p->Item));

	ioffset+=InitFShmCtrl(sizeof(EBINTREE),20,
		(void*)&Test,ioffset,&(p->BinTree));

	ioffset+=InitFShmCtrl(sizeof(ETRIE),40,
		(void*)&Test,ioffset,&(p->Trie));
}


