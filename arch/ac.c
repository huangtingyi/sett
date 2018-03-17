/*---------����ʵ�ִ��� acct.pc----------*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <acct.h>
#include <hnixs.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwshm.h>
#include <wwsem.h>
#include <interface.h>


extern struct ShmAcctHead 	ACCT;
static struct StatAcctHead	STAT_ACCT;

static void mvitem_acct(struct AcctStruct *pi,struct IAcctStruct *po);

/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_acctid(LIST *ptHead);
static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_acctid(LIST *ptHead);

/*��ָ��������ACCT���¼MOUNT���ڴ���,
��ͳ��ACCT�����Ϣ��STAT_ACCT�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingAcctToMem(int iUpdateFlag);
static int ItemBuildAcctShmIndex(POINTER ioffsetNew);

static int assign_acct_acctid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************������֧�ֺ���***************
********************************************************/




/*���ACCTSHM�������ԣ��������ͷŲ������·���*/
/*������ֵ -1 ��Ҫ�ؽ� 0 ��Ҫ�ؽ����Ʊ����Ѿ����ڴ�ACCT��*/
int CheckShmAcctEffect()
{
	if(InitShmAcct()<0){		

		FreeShm(ACCTDATAKEY);
		FreeShm(ACCTNODEKEY);		
		
		return FALSE;
	}	
	return TRUE;
}

void DestroyAcctStatList()
{
	struct AcctStruct *ptCur,*ptPre;
	ptCur=STAT_ACCT.pAcctList;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		free(ptPre);
	}
	STAT_ACCT.pAcctList=NULL;
}

/*��ָ��������ACCT���¼MOUNT���ڴ���,
��ͳ��ACCT�����Ϣ��STAT_ACCT�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingAcctToMem(int iUpdateFlag)
{
	
	int res;
	struct AcctStructIn TempSource;

	struct AcctStruct *p;


	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);
	
/*��ʼ��ȫ�ֽṹ*/

	DestroyAcctStatList();
	
	bzero((void *)&STAT_ACCT,sizeof(struct StatAcctHead));
	STAT_ACCT.pAcctIDTrie=	NULL;

	STAT_ACCT.pAcctList=	NULL;
	strcpy(STAT_ACCT.sUpdateTime,sOracleTime);


	bzero((void*)&TempSource,sizeof(struct AcctStructIn));
	strcpy(TempSource.sTableName,"ACCT");

	if(iUpdateFlag){
		sprintf(sCondition,"\n\
		WHERE  ACCT_ID IN ( \n\
			SELECT ACCT_ID FROM ACCT\n\
			WHERE STATE_DATE>=to_date('%s','YYYYMMDDHH24MISS')\n\
		) AND \n\
		(STATE!='10H' OR \n\
			STATE='10H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300)\n\
		",ACCT.sUpdateTime,STAT_ACCT.sUpdateTime);
	}
	else{
		sprintf(sCondition,"\n\
		WHERE (STATE!='10H' OR \n\
			(STATE='10H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300))\n\
		",STAT_ACCT.sUpdateTime);
	}

	printf("the condition is %s.\n", sCondition);

	strcpy(TempSource.sCondition,sCondition);
	TempSource.iFirstFlag=TRUE;
	TempSource.iBufEmpty=TRUE;

	do{
		if((p=(struct AcctStruct*)malloc(sizeof(struct AcctStruct)))==NULL){
			
			DestroyAcctStatList();
			WriteAlertMsg("�ڴ������� struct AcctStruct");
			return -1;
		}
		if((res=EGetAcctToStruct(p,&TempSource))<0){
			
			DestroyAcctStatList();
			
			WriteAlertMsg("��ȡ���ݿ����ݴ���");
			return -1;
		}		
		if(res==FALSE){
			free(p);
			break;
		}
	        	
		InsertList((LIST**)(&(STAT_ACCT.pAcctList)),(LIST*)p);
		STAT_ACCT.iAcctCnt++;
		if(STAT_ACCT.iAcctCnt%10000==0){
			printf("mounting ACCT count %d.\n",STAT_ACCT.iAcctCnt);
			WriteProcMsg("mounting ACCT count %d",
				STAT_ACCT.iAcctCnt);
		}
	}while(1);

	printf("����ACCT�����ݽ���,��¼��%d.\n",STAT_ACCT.iAcctCnt);
	WriteProcMsg("����ACCT�����ݽ���,��¼��%d",STAT_ACCT.iAcctCnt);

	strcpy(ACCT.sUpdateTime,STAT_ACCT.sUpdateTime);

	return 0;
}

/*�����½ڵ㺯��*/
int MountingUpdatedAcctToMem()
{
	return MountingAcctToMem(TRUE);
}

/*�������нڵ㵽�ڴ�*/
int MountingTotalAcctToMem()
{
	return MountingAcctToMem(FALSE);
}
/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_list(void **pp,void *p)
{
	*pp=p;
}
static int build_insert_trie_acctid(LIST *ptHead)
{
	struct AcctStruct *p=(struct AcctStruct *)ptHead;
	return InsertTrie(&(STAT_ACCT.pAcctIDTrie),p->sAcctID,
		(void *)p,assign_list);
}
int BuildAcctTemporaryPrimaryIndex()
{
	
	STAT_ACCT.pAcctIDTrie=NULL;
	
	STAT_ACCT.iAcctIDNodeCnt=TravelList((LIST*)(STAT_ACCT.pAcctList),
		build_insert_trie_acctid);
	
	return STAT_ACCT.iAcctIDNodeCnt;
	
}
int DestroyAcctTemporaryPrimaryIndex()
{
	int iCnt;
	
	iCnt= DestroyTrie(STAT_ACCT.pAcctIDTrie);
	
	STAT_ACCT.pAcctIDTrie=NULL;	
	STAT_ACCT.iAcctIDNodeCnt=0;
	
	return iCnt;
	
}

int CountingAcctCurDeleteRecord()
{
	int iNodeCnt,iDeleteCnt=0;
	
	POINTER ioffsetCur;
	
	struct IAcctStruct *pTemp,*pNoUse;
	TRIE *ptHead;
	time_t tOracleTime;
	
	
	tOracleTime=tGetTime(STAT_ACCT.sUpdateTime);
	
	if((iNodeCnt=BuildAcctTemporaryPrimaryIndex())<0){
		
		/*ɾ�����ܷ�����ڴ�*/
		DestroyAcctTemporaryPrimaryIndex();
		
		WriteAlertMsg("������ʱ���ؼ�����������");
		return -1;
	}
	ptHead=STAT_ACCT.pAcctIDTrie;
	ioffsetCur=ACCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=ACCTTRIEEXT(ioffsetCur);
		/*����ڱ����������Ѿ�����,��ֱ������Ϊɾ��*/
		if(SearchTrieF(ptHead,pTemp->sAcctID,(void*)&pNoUse)==FOUND){
			iDeleteCnt++;
			pTemp->cDeleteFlag=DELETE_RECORD;
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		/*���ü�¼��ֱ������*/
		if(strcmp(pTemp->sState,"10H")!=0){
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
	
	if(iNodeCnt!=DestroyAcctTemporaryPrimaryIndex()){
		WriteAlertMsg("ɾ����ʱ���ؼ�����������");
		return -1;
	}
	return iDeleteCnt;
	
}
int CountingAcctIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingAcctCurDeleteRecord())<0) return -1;
	
	/*����,��ǰʹ�ÿռ�-��̭�ռ�+���ӿռ�*/
	return ACCT.iCurDataCnt-iDeleteCnt+STAT_ACCT.iAcctCnt;	
}
int GetAcctTotalBufRecord()
{
	return ACCT.iDataBufLen;
}

/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_do_nothing(void **pp,void *p)
{
}

static int count_insert_trie_acctid(LIST *ptHead)
{
	struct AcctStruct *p=(struct AcctStruct *)ptHead;
	return InsertTrie(&(STAT_ACCT.pAcctIDTrie),p->sAcctID,
		(void *)p,assign_do_nothing);
}

int CountingAcctIncrementNode()
{
	int iTempCnt;
	
	POINTER ioffsetCur;
	
	struct IAcctStruct *pTemp;

/***�˻���ʶACCT_ID����****/

	STAT_ACCT.pAcctIDTrie=NULL;
	STAT_ACCT.iAcctIDNodeCnt=0;

	ioffsetCur=ACCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=ACCTTRIEEXT(ioffsetCur);
		
		if((iTempCnt=InsertTrie(&(STAT_ACCT.pAcctIDTrie),
			pTemp->sAcctID,(void *)pTemp,
			assign_do_nothing))<0){
			
			DestroyTrie(STAT_ACCT.pAcctIDTrie);
			STAT_ACCT.pAcctIDTrie=NULL;
			STAT_ACCT.iAcctIDNodeCnt=0;
			
			WriteAlertMsg("ͳ�Ʒ�������ACCT_ACCTID�����ڵ����");
			return -1;
		}
		
		STAT_ACCT.iAcctIDNodeCnt+=iTempCnt;
		ioffsetCur=pTemp->NextOffset;
		
	}
	if((iTempCnt=TravelList((LIST*)(STAT_ACCT.pAcctList),
		count_insert_trie_acctid))<0){
		
		DestroyTrie(STAT_ACCT.pAcctIDTrie);
		STAT_ACCT.pAcctIDTrie=NULL;
		STAT_ACCT.iAcctIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������ACCT_ACCTID�����ڵ����");
		return -1;
	}
	STAT_ACCT.iAcctIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_ACCT.pAcctIDTrie);
	STAT_ACCT.pAcctIDTrie=NULL;
	
	printf("ACCT��ACCT_ID�����ڵ���%d,ռ���ڴ�%dM.\n",
		STAT_ACCT.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_ACCT.iAcctIDNodeCnt/1024/1024));

	WriteProcMsg("ACCT��ACCT_ID�����ڵ���%d,ռ���ڴ�%dM",
		STAT_ACCT.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_ACCT.iAcctIDNodeCnt/1024/1024));

	
	iTempCnt=STAT_ACCT.iAcctIDNodeCnt;
	
	printf("ACCT��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("ACCT��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;
}

int GetAcctTotalBufNode()
{
	return ACCT.iNodeBufLen;
}

int LockAcctShm()
{
	
	if(AcctSemWorking()==FALSE) return -1;
	
	Lock(ACCT.iLockGrpID,0);
	
	return 0;
}

void UnlockAcctShm()
{
	Unlock(ACCT.iLockGrpID,0);
}

void TruncateAcctShmIndexAndRetriveNode()
{
	POINTER ioffsetCur,ioffsetPre;
	
	/*��������ڵ�*/
	ACCT.ioffsetAcctID=-1; 
	
	ioffsetPre=-1;
	ioffsetCur=ACCT.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=ACCTTRIENODE(ioffsetPre)->NextOffset;
	}
	if(ioffsetPre==-1)/*������ֱ�Ӹ�ֵ,����ҵ�����ĩβ*/
		ACCT.ioffsetFreeNode=ACCT.ioffsetCurNode;
	else
		ACCTTRIENODE(ioffsetPre)->NextOffset=ACCT.ioffsetCurNode;
	
	/*��յ�ǰ����,���ﲻҪ��ʼ���ڵ�*/
	ACCT.ioffsetCurNode=-1;
	ACCT.iCurNodeCnt=0;
}
static int comp_shm_acct_acctid(POINTER ioffsetValue,POINTER ioffsetHead)
{
	return ACCTTRIEEXT(ioffsetValue)->iAcctSeqNbr-
		ACCTTRIEEXT(ioffsetHead)->iAcctSeqNbr;
}
static POINTER *get_next_shm_acct_acctid(POINTER ioffsetHead)
{
	return &(NEXT_ACCT__ACCTID(ioffsetHead));
}
/*�����Ϊ��ָ��˳���������*/
static int assign_acct_acctid(POINTER *pioffsetHead,POINTER ioffsetValue)
{
	InsertListSortE(pioffsetHead,ioffsetValue,
		comp_shm_acct_acctid,get_next_shm_acct_acctid);
	return 0;
}

static int ItemBuildAcctShmIndex(POINTER ioffsetNew)
{
	int iTempCnt,iNodeCnt=0;
	TRIEEXT *pNodeSeg=ACCT.pNode;
	struct IAcctStruct *pTemp;
	
	pTemp=ACCTTRIEEXT(ioffsetNew);
	
		/*����ACCT_ID����*/
	iTempCnt=InsertTrieE(&ACCT.ioffsetAcctID,pNodeSeg,
		pTemp->sAcctID,	&(ACCT.ioffsetFreeNode),
		&(ACCT.ioffsetCurNode),ioffsetNew,
		assign_acct_acctid);
		
	if(iTempCnt<0){WriteAlertMsg("�߼�����"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}

int RebuildAcctShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IAcctStruct *pTemp;
	
	
	/*����ǰ����ȡ��,�����,ͬʱ�������ݽڵ���Ϊ0*/
	ioffsetCur=ACCT.ioffsetCurData;
	ACCT.ioffsetCurData=-1;
	ACCT.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=ACCTTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*���Ҫ��̭�ļ�¼,��ֱ�Ӳ������ݿ�������*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp��ACCTTRIEEXT(ioffsetNew)�ǵ�Ч��*/
			pTemp->NextOffset=ACCT.ioffsetFreeData;
			ACCT.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		
		if((iTempCnt=ItemBuildAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		ACCT.iCurNodeCnt+=iTempCnt;

		/*�������ٲ��뵽��ǰ�ڴ�������*/
		pTemp->NextOffset=ACCT.ioffsetCurData;
		ACCT.ioffsetCurData=ioffsetNew;
		/*ͳ�Ʊ�����¼��++*/
		ACCT.iCurDataCnt++;
		
	}
	
	return 0;
}


/************����ˢ��һ�麯�����****����Ϊ��ȫˢ��֧�ֺ���*/

static void mvitem_acct(struct AcctStruct *pi,struct IAcctStruct *po)
{
/*�ȳ�ʼ��ACCT��Ľṹ*/

	po->ioffsetSAS[0]=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*�����ƶ�����*/
	strcpy(po->sAcctID, pi->sAcctID);
	
	po->iAcctSeqNbr  = pi->iAcctSeqNbr;
	po->iBranchID    = pi->iBranchID;
	
	strcpy(po->sPaymentMethod, pi->sPaymentMethod);
	strcpy(po->sAcctNbr, pi->sAcctNbr);
	strcpy(po->sBankAcct, pi->sBankAcct);

	po->iQuota       = pi->iQuota;
	po->iCreditGrade = pi->iCreditGrade;
	po->iBalance     = pi->iBalance;
	po->iChange      = pi->iChange;

	strcpy(po->sCreatedDate, pi->sCreatedDate);
	strcpy(po->sState, pi->sState);
	strcpy(po->sStateDate, pi->sStateDate);
	
}

int BuildAcctMemListIndexAndMoveToShm()
{
	int iTempCnt;
	POINTER ioffsetNew;
	struct AcctStruct *ptCur,*ptPre=NULL;
	
	ptCur=STAT_ACCT.pAcctList;
	if(ptCur==NULL) return 0;
	
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		ioffsetNew=ACCT.ioffsetFreeData;
		if(ioffsetNew==-1) {WriteAlertMsg("�߼�����"); return -1;}
		
		ACCT.ioffsetFreeData=ACCTTRIEEXT(ioffsetNew)->NextOffset;
		
		/*�������ƶ����ڴ���*/
		mvitem_acct(ptPre,ACCTTRIEEXT(ioffsetNew));
		
		if((iTempCnt=ItemBuildAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		ACCT.iCurNodeCnt+=iTempCnt;


		/*�������ٲ��뵽��ǰ�ڴ�������*/
		ACCTTRIEEXT(ioffsetNew)->NextOffset=ACCT.ioffsetCurData;
		ACCT.ioffsetCurData=ioffsetNew;
		
		/*ͳ�Ʊ�����¼��++*/
		ACCT.iCurDataCnt++;
		
	}
	
	return 0;
}

int AcctSemWorking()
{
	int iSemID;
	
	/*���ָ���źŵƲ�����,������ɾ��*/
	if((iSemID=semget(ACCTSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("����ACCT�źŵ��쳣��ɾ��.\n");
		
		return FALSE;
	}
	if(errno!=EEXIST){
		printf("����ACCT�źŵ�ʧ��.\n");
		return FALSE;
	}
	return TRUE;
}

int ClientAcctUnmountNotify()
{
	if(ShmAcctHeadValid()){
		ACCT.iShmID=ACCT.pHead->iShmID;
		ACCT.pHead->iShmID=-1;
	}
	return 0;
}

int ClientAcctConnectNotify()
{
	return UpdateShmHead(ACCTDATAKEY,-1);
}

int CountingAcctTotalRecord()
{
	return STAT_ACCT.iAcctCnt;
}

int StatAcctTotalNode()
{
	int iTempCnt;
	
	if((iTempCnt=TravelList((LIST*)(STAT_ACCT.pAcctList),
		count_insert_trie_acctid))<0){
		
		DestroyTrie(STAT_ACCT.pAcctIDTrie);
		STAT_ACCT.pAcctIDTrie=NULL;
		STAT_ACCT.iAcctIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������ACCT_ACCTID�����ڵ����");
		return -1;
	}
	STAT_ACCT.iAcctIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_ACCT.pAcctIDTrie);
	STAT_ACCT.pAcctIDTrie=NULL;
	
	iTempCnt=STAT_ACCT.iAcctIDNodeCnt;
	
	printf("ACCT��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("ACCT��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;	
}

int InitAcctControlRecord()
{
	int iErrCode,i;
	
	ACCT.ioffsetAcctID=-1; 
	
	ACCT.ioffsetFreeNode=-1;	/*�ڵ��������ͷָ��*/
	ACCT.ioffsetFreeData=-1;	/*��¼��������ָ��*/
	
	ACCT.ioffsetCurData=-1;		/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	ACCT.ioffsetNewData=-1;		/*��¼���������ݵĹ������������*/
	
	ACCT.ioffsetCurNode=-1;		/*��¼��ǰ�������Ѿ��洢����������*/
	
	ACCT.iCurDataCnt=0;		/*��ǰ���ݼ�¼��*/
	ACCT.iCurNodeCnt=0;		/*��ǰ������¼��*/
	
	ACCT.iDataBufLen=(STAT_ACCT.iAcctCnt+1000)*120/100;/*�ܼ�¼����*/
	ACCT.iNodeBufLen=(STAT_ACCT.iAcctIDNodeCnt+1000)*120/100;	/*�������ڵ����*/
	
	ACCT.iLockGrpID=giLockGrpID;	/*�ڴ�����ʶ*/
	
	strcpy(ACCT.sUpdateTime,STAT_ACCT.sUpdateTime);/*�ϴθ���ʱ��*/
	

	/*���乲���ڴ�,����ʼ��*/
	ACCT.pHead=(struct ShmAcctHead *)CreateShmInitHead(ACCTDATAKEY,
		ACCT.iDataBufLen*sizeof(struct IAcctStruct)+
		sizeof(struct ShmAcctHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�ACCTDATAʧ��");
		return -1;
	}
	
	ACCT.pData=(struct IAcctStruct*)(ACCT.pHead+1);


	ACCT.pNode=(TRIEEXT*)AllocShm(ACCTNODEKEY,
		ACCT.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�ACCTNODEʧ��");
		return -1;
	}
	
/*���������ڴ������������еĽڵ����ӵ�δ�õ����ݽڵ�������*/
	/*��βָ��Ϊ-1*/
	for(i=ACCT.iDataBufLen-1;i>=0;i--){
		ACCT.pData[i].NextOffset=ACCT.ioffsetFreeData;
		ACCT.ioffsetFreeData=i;
	}
	for(i=ACCT.iNodeBufLen-1;i>=0;i--)	{		
		ACCT.pNode[i].NextOffset=ACCT.ioffsetFreeNode;
		ACCT.ioffsetFreeNode=i;		
	}
	
	return 0;
}

void CopyAcctControlToShm()
{
	ACCT.iShmID=ACCT.pHead->iShmID;
	ACCT.iTotalLen=ACCT.pHead->iTotalLen;
	
	memcpy((void*)(ACCT.pHead),&ACCT,sizeof(struct ShmAcctHead));
}
