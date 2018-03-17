/*---------����ʵ�ִ��� serv_product.pc----------*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <servacct.h>
#include <hnixs.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwshm.h>
#include <wwsem.h>
#include <interface.h>


extern struct ShmServAcctHead SERVACCT;

static struct StatServAcctHead	STAT_SERVACCT;

static void mvitem_servacct(struct ServAcctStruct *pi,struct IServAcctStruct *po);

/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_servid(LIST *ptHead);
static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_servid(LIST *ptHead);

/*��ָ��������SERVACCT���¼MOUNT���ڴ���,
��ͳ��SERVACCT�����Ϣ��STAT_SERVACCT�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingServAcctToMem(int iUpdateFlag);
static int ItemBuildServAcctShmIndex(POINTER ioffsetNew);

static int assign_servacct_servid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************������֧�ֺ���*****************
********************************************************/




/*���SERVACCTSHM�������ԣ��������ͷŲ������·���*/
/*������ֵ -1 ��Ҫ�ؽ� 0 ��Ҫ�ؽ����Ʊ����Ѿ����ڴ�SERVACCT��*/
int CheckShmServAcctEffect()
{
	if(InitShmServAcct()<0){		

		FreeShm(SERVACCTDATAKEY);
		FreeShm(SERVACCTNODEKEY);		
		
		return FALSE;
	}	
	return TRUE;
}

void DestroyServAcctStatList()
{
	struct ServAcctStruct *ptCur,*ptPre;
	ptCur=STAT_SERVACCT.pServAcctList;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		free(ptPre);
	}
	STAT_SERVACCT.pServAcctList=NULL;
}

/*��ָ��������SERVACCT���¼MOUNT���ڴ���,
��ͳ��SERVACCT�����Ϣ��STAT_SERVACCT�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingServAcctToMem(int iUpdateFlag)
{
	
	int res;
	struct ServAcctStructIn TempSource;

	struct ServAcctStruct *p;


	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);
	
/*��ʼ��ȫ�ֽṹ*/

	DestroyServAcctStatList();
	
	bzero((void *)&STAT_SERVACCT,sizeof(struct StatServAcctHead));
	STAT_SERVACCT.pServIDTrie=	NULL;

	STAT_SERVACCT.pServAcctList=	NULL;
	strcpy(STAT_SERVACCT.sUpdateTime,sOracleTime);

	bzero((void*)&TempSource,sizeof(struct ServAcctStructIn));
	strcpy(TempSource.sTableName,"SERV_ACCT");

	if(iUpdateFlag){
		sprintf(sCondition,"\n\
		WHERE SERV_ID IN ( \n\
			SELECT SERV_ID FROM SERV_ACCT\n\
			WHERE STATE_DATE>=to_date('%s','YYYYMMDDHH24MISS')\n\
		) AND \n\
		(STATE!='F0H' OR \n\
			STATE='F0H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300)\n\
		",SERVACCT.sUpdateTime,STAT_SERVACCT.sUpdateTime);
	}
	else{
		sprintf(sCondition,"\n\
		WHERE STATE!='F0H' OR \n\
			(STATE='F0H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300)\n\
		",STAT_SERVACCT.sUpdateTime);
	}

	strcpy(TempSource.sCondition,sCondition);
	TempSource.iFirstFlag=TRUE;
	TempSource.iBufEmpty=TRUE;

	do{
		if((p=(struct ServAcctStruct*)malloc(sizeof(struct ServAcctStruct)))==NULL){
			
			DestroyServAcctStatList();
			WriteAlertMsg("�ڴ������� struct ServAcctStruct");
			return -1;
		}
		if((res=EGetServAcctToStruct(p,&TempSource))<0){
			
			DestroyServAcctStatList();
			
			WriteAlertMsg("��ȡ���ݿ����ݴ���");
			return -1;
		}		
		if(res==FALSE){
			free(p);
			break;
		}

	       	if(p->iAcctItemTypeID<0){
			free(p);
			continue;	
		} 
		InsertList((LIST**)(&(STAT_SERVACCT.pServAcctList)),(LIST*)p);
		STAT_SERVACCT.iServAcctCnt++;
		if(STAT_SERVACCT.iServAcctCnt%10000==0){
			printf("mounting SERVACCT count %d.\n",
				STAT_SERVACCT.iServAcctCnt);
			WriteProcMsg("mounting SERVACCT count %d",
				STAT_SERVACCT.iServAcctCnt);
		}
	}while(1);

	printf("����SERVACCT�����ݽ���,��¼��%d.\n",STAT_SERVACCT.iServAcctCnt);
	WriteProcMsg("����SERVACCT�����ݽ���,��¼��%d",
		STAT_SERVACCT.iServAcctCnt);

	strcpy(SERVACCT.sUpdateTime,STAT_SERVACCT.sUpdateTime);

	return 0;
}

/*�����½ڵ㺯��*/
int MountingUpdatedServAcctToMem()
{
	return MountingServAcctToMem(TRUE);
}

/*�������нڵ㵽�ڴ�*/
int MountingTotalServAcctToMem()
{
	return MountingServAcctToMem(FALSE);
}

/*ͳ�ƽڵ���֧�ֺ���,ֻ�ǹ���,���⸲��PNEXT*/
static void assign_list(void **pp,void *p)
{
	*pp=p;
}

static int build_insert_trie_servid(LIST *ptHead)
{
	struct ServAcctStruct *p=(struct ServAcctStruct *)ptHead;
	return InsertTrie(&(STAT_SERVACCT.pServIDTrie),p->sServID,
		(void *)p,assign_list);
}

int BuildServAcctTemporaryPrimaryIndex()
{
	
	STAT_SERVACCT.pServIDTrie=NULL;
	
	STAT_SERVACCT.iServIDNodeCnt=TravelList((LIST*)(STAT_SERVACCT.pServAcctList),
		build_insert_trie_servid);
	
	return STAT_SERVACCT.iServIDNodeCnt;
}

int DestroyServAcctTemporaryPrimaryIndex()
{
	int iCnt;
	
	iCnt= DestroyTrie(STAT_SERVACCT.pServIDTrie);
	
	STAT_SERVACCT.pServIDTrie=NULL;	
	STAT_SERVACCT.iServIDNodeCnt=0;
	
	return iCnt;
}

int CountingServAcctCurDeleteRecord()
{
	int iNodeCnt,iDeleteCnt=0;
	
	POINTER ioffsetCur;
	
	struct IServAcctStruct *pTemp,*pNoUse;
	TRIE *ptHead;
	time_t tOracleTime;
	
	
	tOracleTime=tGetTime(STAT_SERVACCT.sUpdateTime);
	
	if((iNodeCnt=BuildServAcctTemporaryPrimaryIndex())<0){
		
		/*ɾ�����ܷ�����ڴ�*/
		DestroyServAcctTemporaryPrimaryIndex();
		
		WriteAlertMsg("������ʱ���ؼ�����������");
		return -1;
	}
	ptHead=STAT_SERVACCT.pServIDTrie;
	ioffsetCur=SERVACCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVACCTTRIEEXT(ioffsetCur);
		/*����ڱ����������Ѿ�����,��ֱ������Ϊɾ��*/
		if(SearchTrieF(ptHead,pTemp->sServID,(void*)&pNoUse)==FOUND){
			iDeleteCnt++;
			pTemp->cDeleteFlag=DELETE_RECORD;
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		/*���ü�¼��ֱ������*/
		if(strcmp(pTemp->sState,"F0H")!=0){
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		/*300��ǰ�����ݿ϶�ɾ��*/
		if((tOracleTime-tGetTime(pTemp->sStateDate))/86400>300){
			iDeleteCnt++;
			pTemp->cDeleteFlag=DELETE_RECORD;
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		
		ioffsetCur=pTemp->NextOffset;
	}
	
	if(iNodeCnt!=DestroyServAcctTemporaryPrimaryIndex()){
		WriteAlertMsg("ɾ����ʱ���ؼ�����������");
		return -1;
	}
	return iDeleteCnt;
}

int CountingServAcctIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingServAcctCurDeleteRecord())<0) return -1;
	
	/*����,��ǰʹ�ÿռ�-��̭�ռ�+���ӿռ�*/
	return SERVACCT.iCurDataCnt-iDeleteCnt+STAT_SERVACCT.iServAcctCnt;	
}

int GetServAcctTotalBufRecord()
{
	return SERVACCT.iDataBufLen;
}

/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_do_nothing(void **pp,void *p)
{
}

static int count_insert_trie_servid(LIST *ptHead)
{
	struct ServAcctStruct *p=(struct ServAcctStruct *)ptHead;
	return InsertTrie(&(STAT_SERVACCT.pServIDTrie),p->sServID,
		(void *)p,assign_do_nothing);
}

int CountingServAcctIncrementNode()
{
	int iTempCnt;
	
	POINTER ioffsetCur;
	
	struct IServAcctStruct *pTemp;

/***�û���ʶSERV_ID����****/

	STAT_SERVACCT.pServIDTrie=NULL;
	STAT_SERVACCT.iServIDNodeCnt=0;

	ioffsetCur=SERVACCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVACCTTRIEEXT(ioffsetCur);
		
		if((iTempCnt=InsertTrie(&(STAT_SERVACCT.pServIDTrie),
			pTemp->sServID,(void *)pTemp,
			assign_do_nothing))<0){
			
			DestroyTrie(STAT_SERVACCT.pServIDTrie);
			STAT_SERVACCT.pServIDTrie=NULL;
			STAT_SERVACCT.iServIDNodeCnt=0;
			
			WriteAlertMsg("ͳ������SERVACCT_SERVID�����ڵ����");
			return -1;
		}
		
		STAT_SERVACCT.iServIDNodeCnt+=iTempCnt;
		ioffsetCur=pTemp->NextOffset;
		
	}
	if((iTempCnt=TravelList((LIST*)(STAT_SERVACCT.pServAcctList),
		count_insert_trie_servid))<0){
		
		DestroyTrie(STAT_SERVACCT.pServIDTrie);
		STAT_SERVACCT.pServIDTrie=NULL;
		STAT_SERVACCT.iServIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERVACCT_SERVID�����ڵ����");
		return -1;
	}
	STAT_SERVACCT.iServIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERVACCT.pServIDTrie);
	STAT_SERVACCT.pServIDTrie=NULL;
	
	iTempCnt=STAT_SERVACCT.iServIDNodeCnt;
	
	printf("SERVACCT��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("SERVACCT��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;
}

int GetServAcctTotalBufNode()
{
	return SERVACCT.iNodeBufLen;
}

int LockServAcctShm()
{
	
	if(ServAcctSemWorking()==FALSE) return -1;
	
	Lock(SERVACCT.iLockGrpID,0);
	
	return 0;
}

void UnlockServAcctShm()
{
	Unlock(SERVACCT.iLockGrpID,0);
}

void TruncateServAcctShmIndexAndRetriveNode()
{
	POINTER ioffsetCur,ioffsetPre;
	
	/*��������ڵ�*/
	SERVACCT.ioffsetServID=-1; 
	
	ioffsetPre=-1;
	ioffsetCur=SERVACCT.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=SERVACCTTRIENODE(ioffsetPre)->NextOffset;
	}
	if(ioffsetPre==-1)/*������ֱ�Ӹ�ֵ,����ҵ�����ĩβ*/
		SERVACCT.ioffsetFreeNode=SERVACCT.ioffsetCurNode;
	else
		SERVACCTTRIENODE(ioffsetPre)->NextOffset=SERVACCT.ioffsetCurNode;
	
	/*��յ�ǰ����,���ﲻҪ��ʼ���ڵ�*/
	SERVACCT.ioffsetCurNode=-1;
	SERVACCT.iCurNodeCnt=0;
}
static int comp_shm_servacct_servid(POINTER ioffsetValue,POINTER ioffsetHead)
{
	int res;
	struct IServAcctStruct *pSource=SERVACCTTRIEEXT(ioffsetValue);
	struct IServAcctStruct *pTarget=SERVACCTTRIEEXT(ioffsetHead);

        if((res=strcmp(pSource->sStateDate,pTarget->sStateDate))!=0)return res;
        return pSource->iServSeqNbr-pTarget->iServSeqNbr;

}
static POINTER *get_next_shm_servacct_servid(POINTER ioffsetHead)
{
	return &(NEXT_SERVACCT__SERVID(ioffsetHead));
}
/*�����Ϊ��ָ��˳���������*/
static int assign_servacct_servid(POINTER *pioffsetHead,POINTER ioffsetValue)
{
	InsertListSortE(pioffsetHead,ioffsetValue,
		comp_shm_servacct_servid,get_next_shm_servacct_servid);
	return 0;
}

static int ItemBuildServAcctShmIndex(POINTER ioffsetNew)
{
	int iTempCnt,iNodeCnt=0;
	TRIEEXT *pNodeSeg=SERVACCT.pNode;
	struct IServAcctStruct *pTemp;
	
	pTemp=SERVACCTTRIEEXT(ioffsetNew);
	
		/*����SERV_ID����*/
	iTempCnt=InsertTrieE(&SERVACCT.ioffsetServID,pNodeSeg,
		pTemp->sServID,	&(SERVACCT.ioffsetFreeNode),
		&(SERVACCT.ioffsetCurNode),ioffsetNew,
		assign_servacct_servid);
		
	if(iTempCnt<0){WriteAlertMsg("�߼�����"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}

int RebuildServAcctShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IServAcctStruct *pTemp;
	
	/*����ǰ����ȡ��,�����,ͬʱ�������ݽڵ���Ϊ0*/
	ioffsetCur=SERVACCT.ioffsetCurData;
	SERVACCT.ioffsetCurData=-1;
	SERVACCT.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=SERVACCTTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*���Ҫ��̭�ļ�¼,��ֱ�Ӳ������ݿ�������*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp��SERVTRIEEXT(ioffsetNew)�ǵ�Ч��*/
			pTemp->NextOffset=SERVACCT.ioffsetFreeData;
			SERVACCT.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		
		if((iTempCnt=ItemBuildServAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		SERVACCT.iCurNodeCnt+=iTempCnt;

		/*�������ٲ��뵽��ǰ�ڴ�������*/
		pTemp->NextOffset=SERVACCT.ioffsetCurData;
		SERVACCT.ioffsetCurData=ioffsetNew;
		/*ͳ�Ʊ�����¼��++*/
		SERVACCT.iCurDataCnt++;
	}
	
	return 0;
}

/************����ˢ��һ�麯�����****����Ϊ��ȫˢ��֧�ֺ���*/

static void mvitem_servacct(struct ServAcctStruct *pi,struct IServAcctStruct *po)
{
/*�ȳ�ʼ��SERVACCT��Ľṹ*/

	po->ioffsetSAS[0]=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*�����ƶ�����*/
	strcpy(po->sAcctID,		pi->sAcctID);

	po->iAcctSeqNbr=		pi->iAcctSeqNbr;
	po->iAcctItemTypeID=	pi->iAcctItemTypeID;

	strcpy(po->sServID,		pi->sServID);

	po->iServSeqNbr=		pi->iServSeqNbr;

	strcpy(po->sState,		pi->sState);
	strcpy(po->sStateDate,	pi->sStateDate);
}

int BuildServAcctMemListIndexAndMoveToShm()
{
	int iTempCnt;
	POINTER ioffsetNew;
	struct ServAcctStruct *ptCur,*ptPre=NULL;
	
	
	ptCur=STAT_SERVACCT.pServAcctList;
	if(ptCur==NULL) return 0;
	
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		ioffsetNew=SERVACCT.ioffsetFreeData;
		if(ioffsetNew==-1) {WriteAlertMsg("�߼�����"); return -1;}
		
		SERVACCT.ioffsetFreeData=SERVACCTTRIEEXT(ioffsetNew)->NextOffset;
		
		/*�������ƶ����ڴ���*/
		mvitem_servacct(ptPre,SERVACCTTRIEEXT(ioffsetNew));
		
		if((iTempCnt=ItemBuildServAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		SERVACCT.iCurNodeCnt+=iTempCnt;

		/*�������ٲ��뵽��ǰ�ڴ�������*/
		SERVACCTTRIEEXT(ioffsetNew)->NextOffset=SERVACCT.ioffsetCurData;
		SERVACCT.ioffsetCurData=ioffsetNew;
		
		/*ͳ�Ʊ�����¼��++*/
		SERVACCT.iCurDataCnt++;
		
	}
	
	return 0;
}

int ServAcctSemWorking()
{
	int iSemID;
	
	/*���ָ���źŵƲ�����,������ɾ��*/
	if((iSemID=semget(SERVACCTSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("����SERVACCT�źŵ��쳣��ɾ��.\n");
		
		return FALSE;
	}
	if(errno!=EEXIST){
		printf("����SERVACCT�źŵ�ʧ��.\n");
		return FALSE;
	}
	return TRUE;
}
int ClientServAcctUnmountNotify()
{
	if(ShmServAcctHeadValid()){
		SERVACCT.iShmID=SERVACCT.pHead->iShmID;
		SERVACCT.pHead->iShmID=-1;
	}
	return 0;
}
int ClientServAcctConnectNotify()
{
	return UpdateShmHead(SERVACCTDATAKEY,-1);
}

int CountingServAcctTotalRecord()
{
	return STAT_SERVACCT.iServAcctCnt;
}

int StatServAcctTotalNode()
{
	int iTempCnt;
	
	if((iTempCnt=TravelList((LIST*)(STAT_SERVACCT.pServAcctList),
		count_insert_trie_servid))<0){
		
		DestroyTrie(STAT_SERVACCT.pServIDTrie);
		STAT_SERVACCT.pServIDTrie=NULL;
		STAT_SERVACCT.iServIDNodeCnt=0;
			
		WriteAlertMsg("ͳ����������SERVACCT_SERVID�����ڵ����");
		return -1;
	}
	STAT_SERVACCT.iServIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_SERVACCT.pServIDTrie);
	STAT_SERVACCT.pServIDTrie=NULL;
	
	iTempCnt=STAT_SERVACCT.iServIDNodeCnt;
	
	printf("SERVACCT��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	WriteProcMsg("SERVACCT��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;	
}

int InitServAcctControlRecord()
{
	int iErrCode,i;
	
	SERVACCT.ioffsetServID=-1; 
	
	SERVACCT.ioffsetFreeNode=-1;	/*�ڵ��������ͷָ��*/
	SERVACCT.ioffsetFreeData=-1;	/*��¼��������ָ��*/
	
	SERVACCT.ioffsetCurData=-1;	/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	SERVACCT.ioffsetNewData=-1;	/*��¼���������ݵĹ������������*/
	
	SERVACCT.ioffsetCurNode=-1;	/*��¼��ǰ�������Ѿ��洢����������*/
	
	SERVACCT.iCurDataCnt=0;		/*��ǰ���ݼ�¼��*/
	SERVACCT.iCurNodeCnt=0;		/*��ǰ������¼��*/
	
	SERVACCT.iDataBufLen=(STAT_SERVACCT.iServAcctCnt+1000)*120/100;/*�ܼ�¼����*/
	SERVACCT.iNodeBufLen=(STAT_SERVACCT.iServIDNodeCnt+1000)*120/100;	/*�������ڵ����*/
	
	SERVACCT.iLockGrpID=giLockGrpID;	/*�ڴ�����ʶ*/
	
	strcpy(SERVACCT.sUpdateTime,STAT_SERVACCT.sUpdateTime);/*�ϴθ���ʱ��*/
	
	/*���乲���ڴ�,����ʼ��*/
	SERVACCT.pHead=(struct ShmServAcctHead *)CreateShmInitHead(
		SERVACCTDATAKEY,
		SERVACCT.iDataBufLen*sizeof(struct IServAcctStruct)+
		sizeof(struct ShmServAcctHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�SERVACCTDATAʧ��");
		return -1;
	}
	
	SERVACCT.pData=(struct IServAcctStruct*)(SERVACCT.pHead+1);

	SERVACCT.pNode=(TRIEEXT*)AllocShm(SERVACCTNODEKEY,
		SERVACCT.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�SERVACCTNODEʧ��");
		return -1;
	}
	
/*���������ڴ������������еĽڵ����ӵ�δ�õ����ݽڵ�������*/
	/*��βָ��Ϊ-1*/
	for(i=SERVACCT.iDataBufLen-1;i>=0;i--){
		SERVACCT.pData[i].NextOffset=SERVACCT.ioffsetFreeData;
		SERVACCT.ioffsetFreeData=i;
	}
	for(i=SERVACCT.iNodeBufLen-1;i>=0;i--)	{		
		SERVACCT.pNode[i].NextOffset=SERVACCT.ioffsetFreeNode;
		SERVACCT.ioffsetFreeNode=i;		
	}
	
	return 0;
}

void CopyServAcctControlToShm()
{
	SERVACCT.iShmID=SERVACCT.pHead->iShmID;
	SERVACCT.iTotalLen=SERVACCT.pHead->iTotalLen;
	
	memcpy((void*)(SERVACCT.pHead),&SERVACCT,sizeof(struct ShmServAcctHead));
}
