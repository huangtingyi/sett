/*---------����ʵ�ִ��� serv.pc----------*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <serv.h>
#include <trie.h>
#include <hnixs.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwshm.h>
#include <wwsem.h>
#include <interface.h>

extern struct ShmServHead 	SERV;

static struct StatServHead	STAT_SERV;

static void mvitem_serv(struct ServStruct *pi,struct IServStruct *po);

/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_servid(LIST *ptHead);

static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_servid(LIST *ptHead);
static int count_insert_trie_imsi(LIST *ptHead);
static int count_insert_trie_accnbr(LIST *ptHead);
static int count_insert_trie_acctid(LIST *ptHead);

/*��ָ��������SERV���¼MOUNT���ڴ���,
��ͳ��SERV�����Ϣ��STAT_SERV�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingServToMem(int iUpdateFlag);
static int ItemBuildServShmIndex(POINTER ioffsetNew);

static int assign_serv_servid(POINTER *pioffsetHead,POINTER ioffsetValue);
static int assign_serv_imsi(POINTER *pioffsetHead,POINTER ioffsetValue);
static int assign_serv_accnbr(POINTER *pioffsetHead,POINTER ioffsetValue);
static int assign_serv_acctid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************������֧�ֺ���***************
********************************************************/




/*���SERVSHM�������ԣ��������ͷŲ������·���*/
/*������ֵ -1 ��Ҫ�ؽ� 0 ��Ҫ�ؽ����Ʊ����Ѿ����ڴ�SERV��*/
int CheckShmServEffect()
{
	if(InitShmServ()<0){		

		FreeShm(SERVDATAKEY);
		FreeShm(SERVNODEKEY);		
		
		return FALSE;
	}	
	return TRUE;
}

void DestroyServStatList()
{
	struct ServStruct *ptCur,*ptPre;
	ptCur=STAT_SERV.pServList;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		free(ptPre);
	}
	STAT_SERV.pServList=NULL;
}

/*��ָ��������SERV���¼MOUNT���ڴ���,
��ͳ��SERV�����Ϣ��STAT_SERV�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingServToMem(int iUpdateFlag)
{
	
	int res;
	struct ServStructIn TempSource;

	struct ServStruct *p;


	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);
	
/*��ʼ��ȫ�ֽṹ*/

	DestroyServStatList();
	
	bzero((void *)&STAT_SERV,sizeof(struct StatServHead));
	STAT_SERV.pServIDTrie=	NULL;
	STAT_SERV.pImsiTrie=	NULL;
	STAT_SERV.pAccNbrTrie=	NULL;
	STAT_SERV.pAcctIDTrie=	NULL;
	STAT_SERV.pServList=	NULL;
	strcpy(STAT_SERV.sUpdateTime,sOracleTime);


	bzero((void*)&TempSource,sizeof(struct ServStructIn));
	strcpy(TempSource.sTableName,"SERV");

	if(iUpdateFlag){
		sprintf(sCondition,"\n\
		WHERE SERV_ID IN ( \n\
			SELECT SERV_ID FROM SERV\n\
			WHERE STATE_DATE>=to_date('%s','YYYYMMDDHH24MISS')\n\
			UNION \n\
			SELECT SERV_ID FROM SERV_PRODUCT\n\
			WHERE STATE_DATE>=to_date('%s','YYYYMMDDHH24MISS')\n\
		) AND \n\
		(STATE!='F0H' OR \n\
			STATE='F0H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300)\n\
		",SERV.sUpdateTime,SERV.sUpdateTime,STAT_SERV.sUpdateTime);
	
	}
	else{
		sprintf(sCondition,"\n\
		WHERE (STATE!='F0H' OR \n\
			(STATE='F0H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300))\n\
		",STAT_SERV.sUpdateTime);
		
	}


	printf("the condition is %s.\n",sCondition);
	strcpy(TempSource.sCondition,sCondition);
	TempSource.iFirstFlag=TRUE;
	TempSource.iBufEmpty=TRUE;

	do{
		if((p=(struct ServStruct*)malloc(sizeof(struct ServStruct)))==NULL){
			
			DestroyServStatList();
			WriteAlertMsg("�ڴ������� struct ServStruct");
			return -1;
		}
		if((res=EGetServToStruct(p,&TempSource))<0){
			
			DestroyServStatList();
			
			WriteAlertMsg("��ȡ���ݿ����ݴ���");
			return -1;
		}		
		if(res==FALSE){
			free(p);
			break;
		}
	        	
		InsertList((LIST**)(&(STAT_SERV.pServList)),(LIST*)p);
		STAT_SERV.iServCnt++;
		if(STAT_SERV.iServCnt%10000==0){
			printf("mounting SERV count %d.\n",
				STAT_SERV.iServCnt);
			WriteProcMsg("mounting SERV count %d.\n",
				STAT_SERV.iServCnt);
		}
	}while(1);

	printf("����SERV�����ݽ���,��¼��%d.\n",STAT_SERV.iServCnt);
	WriteProcMsg("����SERV�����ݽ���,��¼��%d",STAT_SERV.iServCnt);

	/*******ˢ�¸���ʱ��***/
	strcpy(SERV.sUpdateTime,STAT_SERV.sUpdateTime);

	return 0;
}

/*�����½ڵ㺯��*/
int MountingUpdatedServToMem()
{
	
	return MountingServToMem(TRUE);
}

/*�������нڵ㵽�ڴ�*/
int MountingTotalServToMem()
{
	return MountingServToMem(FALSE);
}
/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_list(void **pp,void *p)
{
	*pp=p;
}
static int build_insert_trie_servid(LIST *ptHead)
{
	struct ServStruct *p=(struct ServStruct *)ptHead;
	return InsertTrie(&(STAT_SERV.pServIDTrie),p->sServID,
		(void *)p,assign_list);
}
int BuildServTemporaryPrimaryIndex()
{
	
	STAT_SERV.pServIDTrie=NULL;
	
	STAT_SERV.iServIDNodeCnt=TravelList((LIST*)(STAT_SERV.pServList),
		build_insert_trie_servid);
	
	return STAT_SERV.iServIDNodeCnt;
	
}
int DestroyServTemporaryPrimaryIndex()
{
	int iCnt;
	
	iCnt= DestroyTrie(STAT_SERV.pServIDTrie);
	
	STAT_SERV.pServIDTrie=NULL;	
	STAT_SERV.iServIDNodeCnt=0;
	
	return iCnt;
	
}

int CountingServCurDeleteRecord()
{
	int iNodeCnt,iDeleteCnt=0;
	
	POINTER ioffsetCur;
	
	struct IServStruct *pTemp,*pNoUse;
	TRIE *ptHead;
	time_t tOracleTime;
	
	
	tOracleTime=tGetTime(STAT_SERV.sUpdateTime);
	
	if((iNodeCnt=BuildServTemporaryPrimaryIndex())<0){
		
		/*ɾ�����ܷ�����ڴ�*/
		DestroyServTemporaryPrimaryIndex();
		
		WriteAlertMsg("������ʱ���ؼ�����������");
		return -1;
	}
	ptHead=STAT_SERV.pServIDTrie;
	ioffsetCur=SERV.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVTRIEEXT(ioffsetCur);
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
	
	if(iNodeCnt!=DestroyServTemporaryPrimaryIndex()){
		WriteAlertMsg("ɾ����ʱ���ؼ�����������");
		return -1;
	}
	return iDeleteCnt;
	
}
int CountingServIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingServCurDeleteRecord())<0) return -1;
	
	/*����,��ǰʹ�ÿռ�-��̭�ռ�+���ӿռ�*/
	return SERV.iCurDataCnt-iDeleteCnt+STAT_SERV.iServCnt;	
}
int GetServTotalBufRecord()
{
	return SERV.iDataBufLen;
}
/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_do_nothing(void **pp,void *p)
{
}

static int count_insert_trie_servid(LIST *ptHead)
{
	struct ServStruct *p=(struct ServStruct *)ptHead;
	return InsertTrie(&(STAT_SERV.pServIDTrie),p->sServID,
		(void *)p,assign_do_nothing);
}

static int count_insert_trie_imsi(LIST *ptHead)
{
	struct ServStruct *p=(struct ServStruct *)ptHead;
	return InsertTrie(&(STAT_SERV.pImsiTrie),p->sImsi,
		(void *)p,assign_do_nothing);
}
static int count_insert_trie_accnbr(LIST *ptHead)
{
	struct ServStruct *p=(struct ServStruct *)ptHead;
	return InsertTrie(&(STAT_SERV.pAccNbrTrie),p->sAccNbr,(void *)p,
		assign_do_nothing);
}
static int count_insert_trie_acctid(LIST *ptHead)
{
	struct ServStruct *p=(struct ServStruct *)ptHead;
	return InsertTrie(&(STAT_SERV.pAcctIDTrie),p->sDefaultAcctID,(void *)p,
		assign_do_nothing);
}

int CountingServIncrementNode()
{
	int iTempCnt;
	
	POINTER ioffsetCur;
	
	struct IServStruct *pTemp;

/***�û���ʶSERV_ID����****/

	STAT_SERV.pServIDTrie=NULL;
	STAT_SERV.iServIDNodeCnt=0;

	ioffsetCur=SERV.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVTRIEEXT(ioffsetCur);
		
		if((iTempCnt=InsertTrie(&(STAT_SERV.pServIDTrie),
			pTemp->sServID,(void *)pTemp,
			assign_do_nothing))<0){
			
			DestroyTrie(STAT_SERV.pServIDTrie);
			STAT_SERV.pServIDTrie=NULL;
			STAT_SERV.iServIDNodeCnt=0;
			
			WriteAlertMsg("ͳ�Ʒ�������SERV_SERVID�����ڵ����");
			return -1;
		}
		
		STAT_SERV.iServIDNodeCnt+=iTempCnt;
		ioffsetCur=pTemp->NextOffset;
		
	}
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_servid))<0){
		
		DestroyTrie(STAT_SERV.pServIDTrie);
		STAT_SERV.pServIDTrie=NULL;
		STAT_SERV.iServIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_SERVID�����ڵ����");
		return -1;
	}
	STAT_SERV.iServIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pServIDTrie);
	STAT_SERV.pServIDTrie=NULL;
	
	printf("SERV��SERV_ID�����ڵ���%d,ռ���ڴ�%dM.\n",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

	WriteProcMsg("SERV��SERV_ID�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

/*****����ACC_NBR����**/
	STAT_SERV.pAccNbrTrie=NULL;
	STAT_SERV.iAccNbrNodeCnt=0;
	

	ioffsetCur=SERV.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVTRIEEXT(ioffsetCur);
		
		if((iTempCnt=InsertTrie(&(STAT_SERV.pAccNbrTrie),
			pTemp->sAccNbr,(void *)pTemp,
			assign_do_nothing))<0){
			
			DestroyTrie(STAT_SERV.pAccNbrTrie);
			STAT_SERV.pAccNbrTrie=NULL;
			STAT_SERV.iAccNbrNodeCnt=0;
			
			WriteAlertMsg("ͳ�Ʒ�������SERV_ACCNBR�����ڵ����");
			return -1;
		}
		
		STAT_SERV.iAccNbrNodeCnt+=iTempCnt;
		ioffsetCur=pTemp->NextOffset;
		
	}
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_accnbr))<0){
		DestroyTrie(STAT_SERV.pAccNbrTrie);
		STAT_SERV.pAccNbrTrie=NULL;
		STAT_SERV.iAccNbrNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_ACCNBR�����ڵ����");
		return -1;
	}
	STAT_SERV.iAccNbrNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pAccNbrTrie);
	STAT_SERV.pAccNbrTrie=NULL;
	
	printf("SERV��ACC_NBR�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));
	
	WriteProcMsg("SERV��ACC_NBR�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));
	
/*****����IMSI����******/
	STAT_SERV.pImsiTrie=NULL;
	STAT_SERV.iImsiNodeCnt=0;
	

	ioffsetCur=SERV.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVTRIEEXT(ioffsetCur);
		
		if((iTempCnt=InsertTrie(&(STAT_SERV.pImsiTrie),
			pTemp->sImsi,(void *)pTemp,
			assign_do_nothing))<0){
			
			DestroyTrie(STAT_SERV.pImsiTrie);
			STAT_SERV.pImsiTrie=NULL;
			STAT_SERV.iImsiNodeCnt=0;
			
			WriteAlertMsg("ͳ�Ʒ�������SERV_IMSI�����ڵ����");
			return -1;
		}
		
		STAT_SERV.iImsiNodeCnt+=iTempCnt;
		ioffsetCur=pTemp->NextOffset;
		
	}
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_imsi))<0){
			
		DestroyTrie(STAT_SERV.pImsiTrie);
		STAT_SERV.pImsiTrie=NULL;
		STAT_SERV.iImsiNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_IMSI�����ڵ����");
		return -1;
	}
	STAT_SERV.iImsiNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pImsiTrie);
	STAT_SERV.pImsiTrie=NULL;
	
	printf("SERV��IMSI�����ڵ���%d,ռ���ڴ�%dM.\n",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));
	
	WriteProcMsg("SERV��IMSI�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));

	

/*****����ACCT_ID����**/
	STAT_SERV.pAcctIDTrie=NULL;
	STAT_SERV.iAcctIDNodeCnt=0;
	

	ioffsetCur=SERV.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVTRIEEXT(ioffsetCur);
		
		if((iTempCnt=InsertTrie(&(STAT_SERV.pAcctIDTrie),
			pTemp->sDefaultAcctID,(void *)pTemp,
			assign_do_nothing))<0){
			
			DestroyTrie(STAT_SERV.pAcctIDTrie);
			STAT_SERV.pAcctIDTrie=NULL;
			STAT_SERV.iAcctIDNodeCnt=0;
			
			WriteAlertMsg("ͳ�Ʒ�������SERV_ACCTID�����ڵ����");
			return -1;
		}
		
		STAT_SERV.iAcctIDNodeCnt+=iTempCnt;
		ioffsetCur=pTemp->NextOffset;
		
	}
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_acctid))<0){
		DestroyTrie(STAT_SERV.pAcctIDTrie);
		STAT_SERV.pAcctIDTrie=NULL;
		STAT_SERV.iAcctIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_ACCTID�����ڵ����");
		return -1;
	}
	STAT_SERV.iAcctIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_SERV.pAcctIDTrie);
	STAT_SERV.pAcctIDTrie=NULL;
	
	printf("SERV��ACCT_ID�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	WriteProcMsg("SERV��ACCT_ID�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	iTempCnt=STAT_SERV.iServIDNodeCnt+
		STAT_SERV.iAccNbrNodeCnt+
		STAT_SERV.iImsiNodeCnt+
		STAT_SERV.iAcctIDNodeCnt;
	
	printf("SERV��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("SERV��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;
}
int GetServTotalBufNode()
{
	return SERV.iNodeBufLen;
}

int LockServShm()
{
	
	if(ServSemWorking()==FALSE) return -1;
	
	Lock(SERV.iLockGrpID,0);
	
	return 0;
}
void UnlockServShm()
{
	Unlock(SERV.iLockGrpID,0);
}
void TruncateServShmIndexAndRetriveNode()
{
	POINTER ioffsetCur,ioffsetPre;
	
	/*��������ڵ�*/
	SERV.ioffsetAccNbr=-1;
	SERV.ioffsetServID=-1; 
	SERV.ioffsetImsi=-1;
	SERV.ioffsetAcctID=-1;
	
	/****ѭ���������ļ�ĩβ***/
	ioffsetPre=-1;
	ioffsetCur=SERV.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=SERVTRIENODE(ioffsetPre)->NextOffset;
	}
	
	if(ioffsetPre==-1)/*������ֱ�Ӹ�ֵ,����ҵ�����ĩβ*/
		SERV.ioffsetFreeNode=SERV.ioffsetCurNode;
	else
		SERVTRIENODE(ioffsetPre)->NextOffset=SERV.ioffsetCurNode;
	
	/*��յ�ǰ����,���ﲻҪ��ʼ���ڵ�*/
	SERV.ioffsetCurNode=-1;
	SERV.iCurNodeCnt=0;
}


/*�����Ϊ��ָ��˳���������*/
static int comp_shm_serv_servid(POINTER ioffsetValue,POINTER ioffsetHead)
{
	return SERVTRIEEXT(ioffsetValue)->iServSeqNbr-
		SERVTRIEEXT(ioffsetHead)->iServSeqNbr;
}
static POINTER *get_next_shm_serv_servid(POINTER ioffsetHead)
{
	return &(NEXT_SERV__SERVID(ioffsetHead));
}
static int assign_serv_servid(POINTER *pioffsetHead,POINTER ioffsetValue)
{
	InsertListSortE(pioffsetHead,ioffsetValue,
		comp_shm_serv_servid,get_next_shm_serv_servid);
	return 0;
}

static int comp_shm_serv_accnbr(POINTER ioffsetValue,POINTER ioffsetHead)
{
	int res;
	struct IServStruct *pSource=SERVTRIEEXT(ioffsetValue);
	struct IServStruct *pTarget=SERVTRIEEXT(ioffsetHead);
	
	if((res=strcmp(pSource->sStateDate,pTarget->sStateDate))!=0)return res;
	return pSource->iServSeqNbr-pTarget->iServSeqNbr;
}
static POINTER *get_next_shm_serv_accnbr(POINTER ioffsetHead)
{
	return &(NEXT_SERV__ACCNBR(ioffsetHead));
}
static int assign_serv_accnbr(POINTER *pioffsetHead,POINTER ioffsetValue)
{
	InsertListSortE(pioffsetHead,ioffsetValue,
		comp_shm_serv_accnbr,get_next_shm_serv_accnbr);
	return 0;
}

static int comp_shm_serv_imsi(POINTER ioffsetValue,POINTER ioffsetHead)
{
	int res;
	struct IServStruct *pSource=SERVTRIEEXT(ioffsetValue);
	struct IServStruct *pTarget=SERVTRIEEXT(ioffsetHead);
	
	if((res=strcmp(pSource->sStateDate,pTarget->sStateDate))!=0)return res;
	return pSource->iServSeqNbr-pTarget->iServSeqNbr;
}
static POINTER *get_next_shm_serv_imsi(POINTER ioffsetHead)
{
	return &(NEXT_SERV__IMSI(ioffsetHead));
}
static int assign_serv_imsi(POINTER *pioffsetHead,POINTER ioffsetValue)
{
	InsertListSortE(pioffsetHead,ioffsetValue,
		comp_shm_serv_imsi,get_next_shm_serv_imsi);
	return 0;
}
static int comp_shm_serv_acctid(POINTER ioffsetValue,POINTER ioffsetHead)
{
	int res;
	struct IServStruct *pSource=SERVTRIEEXT(ioffsetValue);
	struct IServStruct *pTarget=SERVTRIEEXT(ioffsetHead);
	
	if((res=strcmp(pSource->sServID,pTarget->sServID))!=0)return res;
	return pSource->iServSeqNbr-pTarget->iServSeqNbr;
}
static POINTER *get_next_shm_serv_acctid(POINTER ioffsetHead)
{
	return &(NEXT_SERV__ACCTID(ioffsetHead));
}
static int assign_serv_acctid(POINTER *pioffsetHead,POINTER ioffsetValue)
{
	InsertListSortE(pioffsetHead,ioffsetValue,
		comp_shm_serv_acctid,get_next_shm_serv_acctid);
	return 0;
}

static int ItemBuildServShmIndex(POINTER ioffsetNew)
{
	int iTempCnt,iNodeCnt=0;
	TRIEEXT *pNodeSeg=SERV.pNode;
	struct IServStruct *pTemp;
	
	pTemp=SERVTRIEEXT(ioffsetNew);
	
		/*����SERV_ID����*/
	iTempCnt=InsertTrieE(&SERV.ioffsetServID,pNodeSeg,
		pTemp->sServID,	&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_servid);
		
	if(iTempCnt<0){WriteAlertMsg("�߼�����"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
		
		/*����ACC_NBR����*/
	iTempCnt=InsertTrieE(&SERV.ioffsetAccNbr,pNodeSeg,
		pTemp->sAccNbr,	&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_accnbr);
		
	if(iTempCnt<0){WriteAlertMsg("�߼�����"); return -1;}

	iNodeCnt+=iTempCnt;

		/*����ACCT_ID����*/
	iTempCnt=InsertTrieE(&SERV.ioffsetAcctID,pNodeSeg,
		pTemp->sDefaultAcctID,&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_acctid);
		
	if(iTempCnt<0){WriteAlertMsg("�߼�����"); return -1;}

	iNodeCnt+=iTempCnt;

		/*���Խ����յ�IMSI�ŵ�����*/	
	if(pTemp->sImsi[0]=='*' || pTemp->sImsi[0]=='0') return iNodeCnt;
	
	/*����IMSI����*/
	iTempCnt=InsertTrieE(&SERV.ioffsetImsi,pNodeSeg,
		pTemp->sImsi,&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_imsi);
		
	if(iTempCnt<0){WriteAlertMsg("�߼�����"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}
int RebuildServShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IServStruct *pTemp;
	
	/*����ǰ����ȡ��,�����,ͬʱ�������ݽڵ���Ϊ0*/
	ioffsetCur=SERV.ioffsetCurData;
	SERV.ioffsetCurData=-1;
	SERV.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=SERVTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*���Ҫ��̭�ļ�¼,��ֱ�Ӳ������ݿ�������*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp��SERVTRIEEXT(ioffsetNew)�ǵ�Ч��*/
			pTemp->NextOffset=SERV.ioffsetFreeData;
			SERV.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		pTemp->ioffsetSAS[1]=-1;
		pTemp->ioffsetSAS[2]=-1;
		pTemp->ioffsetSAS[3]=-1;
		
		if((iTempCnt=ItemBuildServShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		SERV.iCurNodeCnt+=iTempCnt;

		/*�������ٲ��뵽��ǰ�ڴ�������*/
		pTemp->NextOffset=SERV.ioffsetCurData;
		SERV.ioffsetCurData=ioffsetNew;
		/*ͳ�Ʊ�����¼��++*/
		SERV.iCurDataCnt++;
		
	}
	
	return 0;
	
	
}


/************����ˢ��һ�麯�����****����Ϊ��ȫˢ��֧�ֺ���*/

static void mvitem_serv(struct ServStruct *pi,struct IServStruct *po)
{
/*�ȳ�ʼ��SERV��Ľṹ*/

	po->ioffsetSAS[0]=-1;
	po->ioffsetSAS[1]=-1;
	po->ioffsetSAS[2]=-1;
	po->ioffsetSAS[3]=-1;
	
	
	po->iTServCatgID=-1;
	po->iAServCatgID=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*�����ƶ�����*/
		strcpy(po->sServID,		pi->sServID);

		po->iServSeqNbr=		pi->iServSeqNbr;

		po->iBillingTypeID=		pi->iBillingTypeID;
		po->iServTypeID=		pi->iServTypeID;
		po->iAreaID=			pi->iAreaID;

		strcpy(po->sAccNbrStateID,	pi->sAccNbrStateID);

		po->iStopTypeID=		pi->iStopTypeID;
		po->iCycleTypeID=		pi->iCycleTypeID;
		po->iCentrexID=			pi->iCentrexID;
		po->iInNetType=			pi->iInNetType;

		strcpy(po->sAccNbr,		pi->sAccNbr);
		strcpy(po->sImsi,		pi->sImsi);
		strcpy(po->sDefaultAcctID,	pi->sDefaultAcctID);

		po->iQuota=			pi->iQuota;

		po->iSiteID=			pi->iSiteID;

		strcpy(po->sCompletedDate,	pi->sCompletedDate);
		strcpy(po->sCreatedDate,	pi->sCreatedDate);

		po->iCreditGrade=		pi->iCreditGrade;

		strcpy(po->sState,		pi->sState);
		strcpy(po->sStateDate,		pi->sStateDate);
		
		po->iVipFlag=			pi->iVipFlag;
}

int BuildServMemListIndexAndMoveToShm()
{
	int iTempCnt;
	POINTER ioffsetNew;
	struct ServStruct *ptCur,*ptPre=NULL;
	
	
	ptCur=STAT_SERV.pServList;
	if(ptCur==NULL) return 0;
	
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		ioffsetNew=SERV.ioffsetFreeData;
		if(ioffsetNew==-1) {WriteAlertMsg("�߼�����"); return -1;}
		
		SERV.ioffsetFreeData=SERVTRIEEXT(ioffsetNew)->NextOffset;
		
		/*�������ƶ����ڴ���*/
		mvitem_serv(ptPre,SERVTRIEEXT(ioffsetNew));
		
		
		if((iTempCnt=ItemBuildServShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		SERV.iCurNodeCnt+=iTempCnt;


		/*�������ٲ��뵽��ǰ�ڴ�������*/
		SERVTRIEEXT(ioffsetNew)->NextOffset=SERV.ioffsetCurData;
		SERV.ioffsetCurData=ioffsetNew;
		
		/*ͳ�Ʊ�����¼��++*/
		SERV.iCurDataCnt++;
		
	}
	
	return 0;
}
int ServSemWorking()
{
	int iSemID;
	
	/*���ָ���źŵƲ�����,������ɾ��*/
	if((iSemID=semget(SERVSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("����SERV�źŵ��쳣��ɾ��.\n");
		
		return FALSE;
	}
	if(errno!=EEXIST) return FALSE;
	
	return TRUE;
}
int ClientServUnmountNotify()
{
	if(ShmServHeadValid()){
		SERV.iShmID=SERV.pHead->iShmID;
		SERV.pHead->iShmID=-1;
	}
	return 0;
}
int ClientServConnectNotify()
{
	return UpdateShmHead(SERVDATAKEY,-1);
}

int CountingServTotalRecord()
{
	return STAT_SERV.iServCnt;
}
int StatServTotalNode()
{
	int iTempCnt;

/***ͳ��SERVID����***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_servid))<0){
		
		DestroyTrie(STAT_SERV.pServIDTrie);
		STAT_SERV.pServIDTrie=NULL;
		STAT_SERV.iServIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_SERVID�����ڵ����");
		return -1;
	}
	STAT_SERV.iServIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pServIDTrie);
	STAT_SERV.pServIDTrie=NULL;
	
	printf("SERV��SERV_ID�����ڵ���%d,ռ���ڴ�%dM.\n",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

	WriteProcMsg("SERV��SERV_ID�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

/***ͳ��ACC_NBR����***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_accnbr))<0){
		
		DestroyTrie(STAT_SERV.pAccNbrTrie);
		STAT_SERV.pAccNbrTrie=NULL;
		STAT_SERV.iAccNbrNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_ACCNBR�����ڵ����");
		return -1;
	}
	STAT_SERV.iAccNbrNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pAccNbrTrie);
	STAT_SERV.pAccNbrTrie=NULL;
	
	printf("SERV��ACC_NBR�����ڵ���%d,ռ���ڴ�%dM.\n",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));

	WriteProcMsg("SERV��ACC_NBR�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));
/***ͳ��IMSI����***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_imsi))<0){
		
		DestroyTrie(STAT_SERV.pImsiTrie);
		STAT_SERV.pImsiTrie=NULL;
		STAT_SERV.iImsiNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_IMSI�����ڵ����");
		return -1;
	}
	STAT_SERV.iImsiNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pImsiTrie);
	STAT_SERV.pImsiTrie=NULL;
	
	printf("SERV��IMSI�����ڵ���%d,ռ���ڴ�%dM.\n",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));
	
	WriteProcMsg("SERV��IMSI�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));
/***ͳ��ACCT_ID����***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_acctid))<0){
		
		DestroyTrie(STAT_SERV.pAcctIDTrie);
		STAT_SERV.pAcctIDTrie=NULL;
		STAT_SERV.iAcctIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERV_ACCTID�����ڵ����");
		return -1;
	}
	STAT_SERV.iAcctIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pAcctIDTrie);
	STAT_SERV.pAcctIDTrie=NULL;
	
	printf("SERV��ACCTID�����ڵ���%d,ռ���ڴ�%dM.\n",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	WriteProcMsg("SERV��ACCTID�����ڵ���%d,ռ���ڴ�%dM",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	iTempCnt=STAT_SERV.iServIDNodeCnt+
		STAT_SERV.iAccNbrNodeCnt+
		STAT_SERV.iImsiNodeCnt+
		STAT_SERV.iAcctIDNodeCnt;
	
	printf("SERV��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("SERV��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;	
}
int InitServControlRecord()
{
	int iErrCode,i;
	
	SERV.ioffsetAccNbr=-1;
	SERV.ioffsetServID=-1; 
	SERV.ioffsetImsi=-1;
	SERV.ioffsetAcctID=-1;
	
	SERV.ioffsetFreeNode=-1;	/*�ڵ��������ͷָ��*/
	SERV.ioffsetFreeData=-1;	/*��¼��������ָ��*/
	
	SERV.ioffsetCurData=-1;		/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	SERV.ioffsetNewData=-1;		/*��¼���������ݵĹ������������*/
	
	SERV.ioffsetCurNode=-1;		/*��¼��ǰ�������Ѿ��洢����������*/
	
	SERV.iCurDataCnt=0;		/*��ǰ���ݼ�¼��*/
	SERV.iCurNodeCnt=0;		/*��ǰ������¼��*/
	
	SERV.iDataBufLen=(STAT_SERV.iServCnt+1000)*120/100;/*�ܼ�¼����*/
	SERV.iNodeBufLen=(STAT_SERV.iServIDNodeCnt+
			STAT_SERV.iAccNbrNodeCnt+
			STAT_SERV.iImsiNodeCnt+
			STAT_SERV.iAcctIDNodeCnt+1000)*120/100;/*�������ڵ���*/
	
	pprintf(0,0,"��Ҫ��SERV�����ڴ���%dM,������Ϊ%ldM.\n",
		SERV.iDataBufLen*sizeof(struct IServStruct)/1024/1024,
		SERV.iNodeBufLen*sizeof(TRIEEXT)/1024/1024);
	
	SERV.iLockGrpID=giLockGrpID;	/*�ڴ�����ʶ*/
	
	strcpy(SERV.sUpdateTime,STAT_SERV.sUpdateTime);/*�ϴθ���ʱ��*/
	
	/*struct  IServStruct *pData;*/	/*���ݶε�ַ*/
	/*TRIEEXT *pNode;	*/		/*�����ڵ�ָ��*/
	/*struct  ShmServHead *pHead;*/  /*����ͷ��ַ*/
	
	
	

	/*���乲���ڴ�,����ʼ��*/
	SERV.pHead=(struct ShmServHead *)CreateShmInitHead(SERVDATAKEY,
		SERV.iDataBufLen*sizeof(struct IServStruct)+
		sizeof(struct ShmServHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�SERVDATAʧ��");
		return -1;
	}
	
	SERV.pData=(struct IServStruct*)(SERV.pHead+1);


	SERV.pNode=(TRIEEXT*)AllocShm(SERVNODEKEY,
		SERV.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�SERVNODEʧ��");
		return -1;
	}
	
/*���������ڴ������������еĽڵ����ӵ�δ�õ����ݽڵ�������*/
	/*��βָ��Ϊ-1*/
	for(i=SERV.iDataBufLen-1;i>=0;i--){
		SERV.pData[i].NextOffset=SERV.ioffsetFreeData;
		SERV.ioffsetFreeData=i;
	}
	for(i=SERV.iNodeBufLen-1;i>=0;i--)	{		
		SERV.pNode[i].NextOffset=SERV.ioffsetFreeNode;
		SERV.ioffsetFreeNode=i;		
	}
	
	return 0;
		
}

void CopyServControlToShm()
{
	SERV.iShmID=SERV.pHead->iShmID;
	SERV.iTotalLen=SERV.pHead->iTotalLen;

	memcpy((void*)(SERV.pHead),&SERV,sizeof(struct ShmServHead));
}
