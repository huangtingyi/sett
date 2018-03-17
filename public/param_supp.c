#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <bintree.h>
#include <trie.h>
#include <wwsem.h>
#include <wwshm.h>

#include "gen_supp.h"
#include "base_supp.h"
#include "param_intf.h"


int InitMemCsc(struct MemTableStruct *pList,struct ShmCscStruct *pc)
{
	struct MemTableStruct *pbMem,*ptMem;
	
/*�õ�COMM_SEARCH�����ű�*/
	if(SearchMemTable(pList,"COMM_SEARCH_BIN",&pbMem)!=FOUND){
		WriteAlertPrint("�����߼�����ϵͳӦע��COMM_SEARCH_BIN��.");
		return -1;
	}
	if(SearchMemTable(pList,"COMM_SEARCH_TRIE",&ptMem)!=FOUND){
		WriteAlertPrint("�����߼�����ϵͳӦע��COMM_SEARCH_TRIE��.");
		return -1;
	}
	bzero((void*)pc,sizeof(struct ShmCscStruct));
	pc->iofftRoot=pc->ioffbRoot=-1;
	
/*�����ڴ��С*/
	if(CalcCommSearchBin(pbMem,&(pc->ibCnt),&(pc->isCnt),&(pc->imCnt),
		&(pc->ilCnt))<0){
		WriteAlertPrint("����COMM_SEARCH_BIN��Ҫ�Ľڵ���ʧ��.");
		return -1;
	}
	pc->bBytes=pc->isCnt*S_COMM_SEARCH_LEN+pc->imCnt*M_COMM_SEARCH_LEN+
		pc->ilCnt*L_COMM_SEARCH_LEN;
		
	if(CalcCommSearchTrie(ptMem,&(pc->itCnt),&(pc->isCnt),&(pc->imCnt),
		&(pc->ilCnt))<0){
		WriteAlertPrint("����COMM_SEARCH_TRIE��Ҫ�Ľڵ���ʧ��.");
		return -1;
	}

	pc->tBytes=pc->isCnt*S_COMM_SEARCH_LEN+pc->imCnt*M_COMM_SEARCH_LEN+
		pc->ilCnt*L_COMM_SEARCH_LEN-pc->bBytes;
	
	pc->bBytes+=pc->ibCnt*sizeof(EBINTREE);
	pc->tBytes+=pc->itCnt*sizeof(ETRIE);

	return 0;
}
int main(int argc,char *argv[])
{
	int	iErrCode=0;
	struct ShmCscStruct CSC;
	struct ShmTableRegStruct *pShmRegList=NULL;
	struct MemTableStruct *pMemTableList=NULL;
		
	InitAppRes(argv[0]);
	
	if(IniConnect("paramconnstr")<0) return -1;
	
	if(RegTotalShmTab(&pShmRegList)<0){
		printf("ע�ắ��ʧ��.\n");
		return -1;
	}
	if(DataToMemTable(pShmRegList,&pMemTableList)<0){
		printf("���ز����������ڴ�ʧ��.\n");
		return -1;
	}

	WriteProcPrint("�������ݼ��ص������ڴ�.");
	
	if(InitMemCsc(pMemTableList,&CSC)<0) return -1;

	WriteProcPrint("����CSC�ڴ�ṹ���.");

	SHM_PCB_KEY=GetPcbKey();
	if((SEM_PCB_ID=AttachSem(SHM_PCB_KEY))<0){
		if((SEM_PCB_ID=CreateSem(SHM_PCB_KEY,1))<0){
			WriteAlertPrint("���������ڴ���%dʧ��.",SHM_PCB_KEY);
			return -1;
		}
	}
	
	/*Ϊ�˱����ڵȴ�20��param_supp���̱�ɱ������������LockSafe*/
	LockSafe(SEM_PCB_ID,0);
	/*Ϊ��ʹ�����ʵʱ���̺Ͳ���ˢ���������ͻ������ȴ�20��*/
	sleep(20);
	UnlockSafe(SEM_PCB_ID,0);
	
	/*��ʵ�ʶԹ����ڴ����ݽṹ����ʱ������LockSafe,��Ϊ�����ڴ���¹���
	�е����ݵ������ǲ���ȫ�ģ���������Ҳ��������������ô���*/
	Lock(SEM_PCB_ID,0);
	if((PSHM=AttachShm(SHM_PCB_KEY,&iErrCode,NULL))==NULL){
		/*���������ڴ��ʼ�ṹ,��ʹPSHMָ�����ڴ�*/
		if(BuildShmInit(pMemTableList,&CSC)<0){
			WriteAlertPrint("��ʼ�������ڴ�ʧ��.");
			Unlock(SEM_PCB_ID,0);
			return -1;
		}
	}
	
	if(MemTableToShm(pMemTableList,&CSC)<0){

		/*�����ǲ�����������̫�࣬�������¹��������ڴ�*/
		DetachShm(PSHM);PSHM=NULL;
		DestroyShm(SHM_PCB_KEY);
		/*���������ڴ��ʼ�ṹ,��ʹPSHMָ�����ڴ�*/
		if(BuildShmInit(pMemTableList,&CSC)<0){
			WriteAlertPrint("��ʼ�������ڴ�ʧ��.");
			Unlock(SEM_PCB_ID,0);
			return -1;
		}
		if(MemTableToShm(pMemTableList,&CSC)<0){
			WriteAlertPrint("�������ص������ڴ�ʧ��.");
			return -1;
			Unlock(SEM_PCB_ID,0);
		}
	}

	Unlock(SEM_PCB_ID,0);
	
	DetachShm(PSHM);PSHM=NULL;

	DisconnectDatabase();
	
	WriteProcPrint("ˢ�¹����ڴ�����ɹ�.");
	
	return 0;
}
