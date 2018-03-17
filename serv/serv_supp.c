#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <trie.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

#include "dbsupp.h"
#include "stt_ticket.h"
#include "simple_serv.h"
#include "serv_intf.h"

int SimpleServ2List(struct SimpleServStruct **pptHead,char sTableName[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct SimpleServStruct Temp;
        static struct SimpleServStructIn TempIn;
        
        struct SimpleServStruct *pTemp,*ptHead=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
        	strcpy(TempIn.sCondition,"");
		iFirstFlag=false;
	}

        /*ȡ�����м�¼���ض�����*/
        while(EGetSimpleServToStruct(&Temp,&TempIn)){
        	
        	if((pTemp=malloc(sizeof(struct SimpleServStruct)))==NULL)
        		return -1;
        	memcpy((void*)pTemp,(void*)&Temp,
        		sizeof(struct SimpleServStruct));
		iCnt++;
		InsertList((LIST**)&ptHead,(LIST*)pTemp);
        }
        
        *pptHead=ptHead;

	return iCnt;
}
int CountTrieNode(struct SimpleServStruct *ptHead,char str[])
{
	int j=0,k;
	
	TRIE *pTmp=NULL;
	struct SimpleServStruct Tmp;
	
	bzero((void*)&Tmp,sizeof(struct SimpleServStruct));
	
	while(ptHead!=NULL){
		if(strcmp(str,"MSISDN")==0){
			k=InsertTrie(&pTmp,ptHead->sMsisdn,(void*)&Tmp,
				assign_insert_trie);
		}
		else{
			if(strcmp(ptHead->sImsi,"000000000000000")==0){
				k=0;
			}
			else{
				k=InsertTrie(&pTmp,ptHead->sImsi,(void*)&Tmp,
					assign_insert_trie);
			}
		}
		if(k<0) return -1;
	
		j+=k;
		ptHead=ptHead->pNext;
	}
	
	DestroyTrie(pTmp);

	return j;
}

struct FMemStruct SERV;
struct ShmServHead *PSHMSERV;

void InitServHeadInfo(struct ShmServHead* pi,int iRecCnt,int iNodeCnt,
	struct ShmServHead* po)
{
	POINTER ioffset=0;

	ioffset=sizeof(struct FShmStruct)+sizeof(struct ShmServHead);

	memcpy((void*)po,(void*)pi,sizeof(struct ShmServHead));

	ioffset+=InitFShmCtrl(sizeof(ETRIE),iNodeCnt,
		(void*)&SERV,ioffset,&(po->TrieNode));

	ioffset+=InitFShmCtrl(sizeof(struct ISimpleServStruct),iRecCnt,
		(void*)&SERV,ioffset,&(po->TrieData));
}
POINTER MallocTrieData()
{
	return MallocFItem((void*)&SERV,&PSHMSERV->TrieData);
}
void mvitem_simpleserv2shm(struct SimpleServStruct *pi,
	struct ISimpleServStruct*po)
{
	bzero((void*)po,sizeof(struct ISimpleServStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sImsi,pi->sImsi);
	strcpy(po->sState,pi->sState);
	strcpy(po->sBillingTypeID,pi->sBillingTypeID);
	strcpy(po->sReserve,pi->sReserve);
	strcpy(po->sCreatedDate,pi->sCreatedDate);
}
void assign_insert_simple_serv_trie(POINTER *pioffHead,POINTER ioffValue)
{
	InsertFList((void*)&SERV,pioffHead,ioffValue);
}
int main(int argc, char **argv)
{
	void *pShm;
	int iRecCnt,iNodeCnt;
	char sTableName[31];
	POINTER ioffset=0,ioffTmp;
	struct ShmServHead Temp;
	struct ISimpleServStruct *p;
	struct 	SimpleServStruct *ptHead=NULL,*ptlkHead=NULL,*pTemp;


	if(argc!=2){
		printf("Usage %s simple_serv_xx .\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	
	strcpy(sTableName,argv[1]);Upper(sTableName);	
	        
/**�������ݿ�***/
	if(ConnectDataDB()<0) return -1;

/**ͳ�Ƴ��û����ϼ�¼������Ҫ�����ڵ���**/
	iRecCnt=SimpleServ2List(&ptHead,sTableName);
	CommitWork();
	DisconnectDatabase();
	
/**sMsisdn����**/
	iNodeCnt=CountTrieNode(ptHead,"MSISDN");
	
	iRecCnt+=10000;
	iNodeCnt+=10000;

	WriteProcPrint("�������������Ҫ%d����¼��%d������Msisdn",
		iRecCnt,iNodeCnt);
	
	bzero((void*)&Temp,sizeof(struct ShmServHead));
	Temp.iShmKey=SIMPLE_SERV_KEY;
	Temp.iBlockLen=512*1024*1024;
	Temp.iTotalLen=iNodeCnt*sizeof(ETRIE)+
		iRecCnt*sizeof(struct ISimpleServStruct);
	Temp.ioffTrie=-1;

	WriteProcPrint("�ܼ���Ҫ%ld�ֽڹ����ڴ�",Temp.iTotalLen);

	if((pShm=CreateMultiShm(Temp.iShmKey,(POINTER)Temp.iTotalLen,
		(POINTER)Temp.iBlockLen,&SERV))==NULL){
		WriteAlertPrint("�ص���鴴��%d key�Ĺ����ڴ�ʧ��",
			SIMPLE_SERV_KEY);
		RollbackWorkRelease();
		return -1;
	}
	ioffset=sizeof(struct FShmStruct);
	PSHMSERV=(struct ShmServHead *)OPELIST(pShm,ioffset);
	
	InitServHeadInfo(&Temp,iRecCnt,iNodeCnt,PSHMSERV);
	
	ptlkHead=ptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if((ioffTmp=MallocTrieData())<0) return -1;

		p=(struct ISimpleServStruct*)OPSERV(ioffTmp);

		mvitem_simpleserv2shm(pTemp,p);
	
		if(InsertFTrie((void*)&SERV,&(PSHMSERV->ioffTrie),
			pTemp->sMsisdn,&(PSHMSERV->TrieNode),ioffTmp,
			assign_insert_simple_serv_trie)<0){
			printf("�Ƶ������ڴ�����ʧ��");
			return -1;
		}
	}
	WriteProcPrint("���������ڴ�ṹ�ɹ�Msisdn");
	
/**sImsi����**/
	ptHead=ptlkHead;
	iNodeCnt=CountTrieNode(ptHead,"IMSI");
	
	iNodeCnt+=10000;

	if(iNodeCnt==10000){
		WriteProcPrint("0������Imsi,û���������ڴ�ṹ");
		return 0;
	}
	
	WriteProcPrint("�������������Ҫ%d����¼��%d������Imsi",
		iRecCnt,iNodeCnt);
	
	bzero((void*)&Temp,sizeof(struct ShmServHead));
	Temp.iShmKey=SIMPLE_SERV_KEYI;
	Temp.iBlockLen=512*1024*1024;
	Temp.iTotalLen=iNodeCnt*sizeof(ETRIE)+
		iRecCnt*sizeof(struct ISimpleServStruct);
	Temp.ioffTrie=-1;

	WriteProcPrint("�ܼ���Ҫ%ld�ֽڹ����ڴ�",Temp.iTotalLen);

	if((pShm=CreateMultiShm(Temp.iShmKey,(POINTER)Temp.iTotalLen,
		(POINTER)Temp.iBlockLen,&SERV))==NULL){
		WriteAlertPrint("�ص���鴴��%d key�Ĺ����ڴ�ʧ��",
			SIMPLE_SERV_KEYI);
		RollbackWorkRelease();
		return -1;
	}
	ioffset=sizeof(struct FShmStruct);
	PSHMSERV=(struct ShmServHead *)OPELIST(pShm,ioffset);
	
	InitServHeadInfo(&Temp,iRecCnt,iNodeCnt,PSHMSERV);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->sImsi,"000000000000000")==0)continue;
		
		if((ioffTmp=MallocTrieData())<0) return -1;

		p=(struct ISimpleServStruct*)OPSERV(ioffTmp);

		mvitem_simpleserv2shm(pTemp,p);
	
		if(InsertFTrie((void*)&SERV,&(PSHMSERV->ioffTrie),
			pTemp->sImsi,&(PSHMSERV->TrieNode),ioffTmp,
			assign_insert_simple_serv_trie)<0){
			printf("�Ƶ������ڴ�����ʧ��");
			return -1;
		}
	}
	WriteProcPrint("���������ڴ�ṹ�ɹ�Imsi");	
	return 0;
}
