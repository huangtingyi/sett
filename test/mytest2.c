#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwsem.h>
#include <wwshm.h>
#include "list.h"
#include <bintree.h>
#include <trie.h>
#include <wwtiny.h>
#include <wwlog.h>

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

void InitShmTest(struct ShmTestHead *p);
void InitTestHead(struct ShmTestHead *p);
void PrintTestItemList(POINTER ioffHead);


int comp_e_list_test(POINTER ioffSource,POINTER ioffTarget)
{
	struct TestItemStruct *pSource;
	struct TestItemStruct *pTarget;
	
	pSource=(struct TestItemStruct *)OPELIST(&TestHead,ioffSource);
	pTarget=(struct TestItemStruct *)OPELIST(&TestHead,ioffTarget);
	
	return strcmp(pSource->sValue,pTarget->sValue);
}
int comp_search_e_list(void *pValue,POINTER ioffTarget)
{
	struct TestItemStruct *pTarget;	
	char *sValue=(char*)pValue;
	
	pTarget=(struct TestItemStruct *)OPELIST(&TestHead,ioffTarget);
	
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
	
	pTarget=(struct TestItemStruct *)OPELIST(&TestHead,*pioffHead);
	
	printf("in print item value=%s.\n",pTarget->sValue);
	return 0;
}
int main()
{
	struct ShmTestHead *p;
	EBINTREE *pEBin;
	struct TestItemStruct *pTemp;
	POINTER ioffHead=-1,ioffNew,ioffCur;
	POINTER ioffRoot=-1,ioffTrie=-1,*pioffTmp;
	
	p=&TestHead;
	InitShmTest(&TestHead);
	InitTestHead(&TestHead);
	
	ioffNew=TestHead.Item.ioffFree;
	
	while(ioffNew!=-1){
		ioffCur=ioffNew;
		ioffNew=OOELISTNXT(&TestHead,ioffCur);
		
		InsertEList((void*)&TestHead,&ioffHead,ioffCur);
		/*,comp_e_list_test);*/
	}
	printf("=======after sort==================.\n");
	PrintTestItemList(ioffHead);
	
/*	ETRIE²âÊÔ..*/
	ioffNew=ioffHead;
	while(ioffNew!=-1){

		DeleteEList((void*)&TestHead,&ioffHead,ioffNew);
		pTemp=(struct TestItemStruct*)OPELIST(&TestHead,ioffNew);
		
		InsertETrie((void*)&TestHead,&ioffTrie,pTemp->sValue,
			&(TestHead.Trie),ioffNew,
			assign_bin_e_list);
		ioffNew=ioffHead;
	}

	SearchETrie((void*)&TestHead, ioffTrie,(void*)"003",&ioffCur);
	if(ioffCur!=-1){
		pTemp=(struct TestItemStruct*)OPELIST(&TestHead,ioffCur);
		printf("the value is %s.\n",pTemp->sValue);
	}
	else printf("the value not found.\n");
	
	pioffTmp=GetETrieLk((void*)&TestHead, ioffTrie,(void*)"003");
	if(pioffTmp!=NULL){
		ioffCur=*pioffTmp;
		*pioffTmp=-1;	
		pTemp=(struct TestItemStruct*)OPELIST(&TestHead,ioffCur);
		printf("the value is %s,22.\n",pTemp->sValue);
	}
	else
		 printf("the value not found,GetETrie.\n");
	
	TravelETrieD((void*)&TestHead,ioffTrie,print_item);

/*	Æ½ºâ¶þ²æÊ÷²âÊÔ..*/
	ioffNew=ioffHead;
	while(ioffNew!=-1){

		DeleteEList((void*)&TestHead,&ioffHead,ioffNew);
		
		InsertEBin((void*)&TestHead,&ioffRoot,
			&(TestHead.BinTree),ioffNew,
			comp_e_list_test,
			assign_bin_e_list);
		ioffNew=ioffHead;
	}

	SearchEBin((void*)&TestHead, ioffRoot,(void*)"003",
		comp_search_e_list,&ioffCur);
	if(ioffCur!=-1){
		pTemp=(struct TestItemStruct*)OPELIST(&TestHead,ioffCur);
		printf("the value is %s.\n",pTemp->sValue);
	}
	else printf("the value not found.\n");
		
	TravelEBin((void*)&TestHead,ioffRoot,print_item);
	
	ioffCur=-1;
	DeleteEBin((void*)&TestHead,&ioffRoot,(void*)"003",
		comp_search_e_list,&ioffCur);
	if(ioffCur!=-1){
		pEBin=(EBINTREE*)OPELIST(&TestHead,ioffCur);
		ioffCur=pEBin->ioffData;
		pTemp=(struct TestItemStruct*)OPELIST(&TestHead,ioffCur);
		printf("the value is %s,%ld.\n",pTemp->sValue,ioffCur);
	}
	else printf("the value delete error.\n");
	
	TravelEBin((void*)&TestHead,ioffRoot,print_item);

	
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
	
	return 0;
}
void PrintTestItemList(POINTER ioffHead)
{
	int i=0;
	struct TestItemStruct *pTemp;
	
	while(ioffHead!=-1){
		pTemp=(struct TestItemStruct*)OPELIST(&TestHead,ioffHead);
		
		printf("the %d value is %s.\n",i++,pTemp->sValue);
		
		ioffHead=OOELISTNXT(&TestHead,ioffHead);
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
	p->iShmID=100;
	p->iTotalLen=sizeof(struct ShmTestHead);
	GetHostTime(p->sUpdateTime);
	
	InitEShmCtrl(sizeof(struct TestItemStruct),10,(void*)p,
		((char*)(p->d0)-(char*)p),&(p->Item));

	InitEShmCtrl(sizeof(EBINTREE),10,(void*)p,
		((char*)(p->d1)-(char*)p),&(p->BinTree));

	InitEShmCtrl(sizeof(ETRIE),100,(void*)p,
		((char*)(p->d2)-(char*)p),&(p->Trie));
}


