/*---------����ʵ�ִ��� serv_product.pc----------*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <servproduct.h>
#include <hnixs.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwshm.h>
#include <wwsem.h>
#include <interface.h>

extern struct ShmServProductHead 	SERVPRODUCT;
static struct StatServProductHead	STAT_SERVPRODUCT;

static void mvitem_servproduct(struct ServProductStruct *pi,struct IServProductStruct *po);

/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_servid(LIST *ptHead);
static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_servid(LIST *ptHead);

/*��ָ��������SERVPRODUCT���¼MOUNT���ڴ���,
��ͳ��SERVPRODUCT�����Ϣ��STAT_SERVPRODUCT�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingServProductToMem(int iUpdateFlag);
static int ItemBuildServProductShmIndex(POINTER ioffsetNew);

static int assign_servproduct_servid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************������֧�ֺ���***************
********************************************************/

/*���SERVSHM�������ԣ��������ͷŲ������·���*/
/*������ֵ -1 ��Ҫ�ؽ� 0 ��Ҫ�ؽ����Ʊ����Ѿ����ڴ�SERV��*/
int CheckShmServProductEffect()
{
	if(InitShmServProduct()<0){		

		FreeShm(SERVPRODUCTDATAKEY);
		FreeShm(SERVPRODUCTNODEKEY);
		
		return FALSE;
	}	
	return TRUE;
}

void DestroyServProductStatList()
{
	struct ServProductStruct *ptCur,*ptPre;
	ptCur=STAT_SERVPRODUCT.pServProductList;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		free(ptPre);
	}
	STAT_SERVPRODUCT.pServProductList=NULL;
}

/*��ָ��������SERVPRODUCT���¼MOUNT���ڴ���,
��ͳ��SERVPRODUCT�����Ϣ��STAT_SERVPRODUCT�ṹ����Ҫ��
������,���������Ľڵ�����*/
static int MountingServProductToMem(int iUpdateFlag)
{
	
	int res;
	struct ServProductStructIn TempSource;
	struct ServProductStruct *p;

	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);

/*��ʼ��ȫ�ֽṹ*/
	DestroyServProductStatList();
	
	bzero((void *)&STAT_SERVPRODUCT,sizeof(struct StatServProductHead));
	STAT_SERVPRODUCT.pServIDTrie=	NULL;

	STAT_SERVPRODUCT.pServProductList=	NULL;
	strcpy(STAT_SERVPRODUCT.sUpdateTime,sOracleTime);

	bzero((void*)&TempSource,sizeof(struct ServProductStructIn));
	strcpy(TempSource.sTableName,"SERV_PRODUCT");

	if(iUpdateFlag){
		sprintf(sCondition,"\n\
		WHERE SERV_ID IN ( \n\
			SELECT  SERV_ID FROM SERV_PRODUCT\n\
			WHERE STATE_DATE>=to_date('%s','YYYYMMDDHH24MISS')\n\
		) AND \n\
		(STATE!='F0H' OR \n\
			STATE='F0H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300) AND\n\
		PRODUCT_ID IN ( \n\
			SELECT PRODUCT_ID FROM PRODUCT WHERE TARIFF_FLAG='1')\n\
		",SERVPRODUCT.sUpdateTime,STAT_SERVPRODUCT.sUpdateTime);
	}
	else{
		sprintf(sCondition,"\n\
		WHERE  \n\
			PRODUCT_ID IN ( \n\
				SELECT PRODUCT_ID FROM PRODUCT \n\
				WHERE TARIFF_FLAG='1') AND\n\
			STATE!='F0H' OR \n\
			(STATE='F0H' AND \n\
			STATE_DATE>to_date('%s','yyyymmddhh24miss')-300)\n\
		",STAT_SERVPRODUCT.sUpdateTime);
	}

	printf("the condition is %s.\n",sCondition);

	strcpy(TempSource.sCondition,sCondition);
	TempSource.iFirstFlag=TRUE;
	TempSource.iBufEmpty=TRUE;

	do{
		if((p=(struct ServProductStruct*)malloc(sizeof(struct ServProductStruct)))==NULL){
			
			DestroyServProductStatList();
			WriteAlertMsg("�ڴ������� struct ServProductStruct");
			return -1;
		}
		if((res=EGetServProductToStruct(p,&TempSource))<0){
			
			DestroyServProductStatList();
			
			WriteAlertMsg("��ȡ���ݿ����ݴ���");
			return -1;
		}		
		if(res==FALSE){
			free(p);
			break;
		}
	        if(p->iProductID<0){
			free(p);
			continue;
		}	
		InsertList((LIST**)(&(STAT_SERVPRODUCT.pServProductList)),(LIST*)p);
		STAT_SERVPRODUCT.iServProductCnt++;
		if(STAT_SERVPRODUCT.iServProductCnt%10000==0){
			printf("mounting SERVPRODUCT count %d.\n",
				STAT_SERVPRODUCT.iServProductCnt);
			WriteProcMsg("mounting SERVPRODUCT count %d",
				STAT_SERVPRODUCT.iServProductCnt);
		}
	}while(1);

	printf("����SERVPRODUCT�����ݽ���,��¼��%d.\n",
		STAT_SERVPRODUCT.iServProductCnt);

	WriteProcMsg("����SERVPRODUCT�����ݽ���,��¼��%d",
		STAT_SERVPRODUCT.iServProductCnt);

	strcpy(SERVPRODUCT.sUpdateTime,STAT_SERVPRODUCT.sUpdateTime);

	return 0;
}

/*�����½ڵ㺯��*/
int MountingUpdatedServProductToMem()
{
	return MountingServProductToMem(TRUE);
}

/*�������нڵ㵽�ڴ�*/
int MountingTotalServProductToMem()
{
	return MountingServProductToMem(FALSE);
}

/*ͳ�ƽڵ���֧�ֺ���,ֻ�ǹ���,���⸲��PNEXT*/
static void assign_list(void **pp,void *p)
{
	*pp=p;
}

static int build_insert_trie_servid(LIST *ptHead)
{
	struct ServProductStruct *p=(struct ServProductStruct *)ptHead;
	return InsertTrie(&(STAT_SERVPRODUCT.pServIDTrie),p->sServID,
		(void *)p,assign_list);
}

int BuildServProductTemporaryPrimaryIndex()
{
	
	STAT_SERVPRODUCT.pServIDTrie=NULL;
	
	STAT_SERVPRODUCT.iServIDNodeCnt=TravelList((LIST*)(STAT_SERVPRODUCT.pServProductList),
		build_insert_trie_servid);
	
	return STAT_SERVPRODUCT.iServIDNodeCnt;
}

int DestroyServProductTemporaryPrimaryIndex()
{
	int iCnt;
	
	iCnt= DestroyTrie(STAT_SERVPRODUCT.pServIDTrie);
	
	STAT_SERVPRODUCT.pServIDTrie=NULL;	
	STAT_SERVPRODUCT.iServIDNodeCnt=0;
	
	return iCnt;
}

int CountingServProductCurDeleteRecord()
{
	int iNodeCnt,iDeleteCnt=0;
	
	POINTER ioffsetCur;
	
	struct IServProductStruct *pTemp,*pNoUse;
	TRIE *ptHead;
	time_t tOracleTime;
	
	
	tOracleTime=tGetTime(STAT_SERVPRODUCT.sUpdateTime);
	
	if((iNodeCnt=BuildServProductTemporaryPrimaryIndex())<0){
		
		/*ɾ�����ܷ�����ڴ�*/
		DestroyServProductTemporaryPrimaryIndex();
		
		WriteAlertMsg("������ʱ���ؼ�����������");
		return -1;
	}
	ptHead=STAT_SERVPRODUCT.pServIDTrie;
	ioffsetCur=SERVPRODUCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVPRODUCTTRIEEXT(ioffsetCur);
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
	
	if(iNodeCnt!=DestroyServProductTemporaryPrimaryIndex()){
		WriteAlertMsg("ɾ����ʱ���ؼ�����������");
		return -1;
	}
	return iDeleteCnt;
}

int CountingServProductIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingServProductCurDeleteRecord())<0) return -1;
	
	/*����,��ǰʹ�ÿռ�-��̭�ռ�+���ӿռ�*/
	return SERVPRODUCT.iCurDataCnt-iDeleteCnt+STAT_SERVPRODUCT.iServProductCnt;	
}

int GetServProductTotalBufRecord()
{
	return SERVPRODUCT.iDataBufLen;
}

/*ͳ�ƽڵ���֧�ֺ���*/
static void assign_do_nothing(void **pp,void *p)
{
}

static int count_insert_trie_servid(LIST *ptHead)
{
	struct ServProductStruct *p=(struct ServProductStruct *)ptHead;
	return InsertTrie(&(STAT_SERVPRODUCT.pServIDTrie),p->sServID,
		(void *)p,assign_do_nothing);
}

int CountingServProductIncrementNode()
{
	int iTempCnt;
	
	POINTER ioffsetCur;
	
	struct IServProductStruct *pTemp;

/***�û���ʶSERV_ID����****/

	STAT_SERVPRODUCT.pServIDTrie=NULL;
	STAT_SERVPRODUCT.iServIDNodeCnt=0;

	ioffsetCur=SERVPRODUCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVPRODUCTTRIEEXT(ioffsetCur);
		
		if((iTempCnt=InsertTrie(&(STAT_SERVPRODUCT.pServIDTrie),
			pTemp->sServID,(void *)pTemp,
			assign_do_nothing))<0){
			
			DestroyTrie(STAT_SERVPRODUCT.pServIDTrie);
			STAT_SERVPRODUCT.pServIDTrie=NULL;
			STAT_SERVPRODUCT.iServIDNodeCnt=0;
			
			WriteAlertMsg("ͳ������SERV_SERVID�����ڵ����");
			return -1;
		}
		
		STAT_SERVPRODUCT.iServIDNodeCnt+=iTempCnt;
		ioffsetCur=pTemp->NextOffset;
		
	}
	if((iTempCnt=TravelList((LIST*)(STAT_SERVPRODUCT.pServProductList),
		count_insert_trie_servid))<0){
		
		DestroyTrie(STAT_SERVPRODUCT.pServIDTrie);
		STAT_SERVPRODUCT.pServIDTrie=NULL;
		STAT_SERVPRODUCT.iServIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERVPR_SERVID�����ڵ����");
		return -1;
	}
	STAT_SERVPRODUCT.iServIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_SERVPRODUCT.pServIDTrie);
	STAT_SERVPRODUCT.pServIDTrie=NULL;
	
	iTempCnt=STAT_SERVPRODUCT.iServIDNodeCnt;
	
	printf("SERVPRODUCT��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	WriteProcMsg("SERVPRODUCT��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;
}

int GetServProductTotalBufNode()
{
	return SERVPRODUCT.iNodeBufLen;
}

int LockServProductShm()
{
	if(ServProductSemWorking()==FALSE) return -1;
	
	Lock(SERVPRODUCT.iLockGrpID,0);
	
	return 0;
}

void UnlockServProductShm()
{
	Unlock(SERVPRODUCT.iLockGrpID,0);
}

void TruncateServProductShmIndexAndRetriveNode()
{
	POINTER ioffsetCur,ioffsetPre;
	
	/*��������ڵ�*/
	SERVPRODUCT.ioffsetServID=-1; 
	
	ioffsetPre=-1;
	ioffsetCur=SERVPRODUCT.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=SERVPRODUCTTRIENODE(ioffsetPre)->NextOffset;
	}
	if(ioffsetPre==-1)/*������ֱ�Ӹ�ֵ,����ҵ�����ĩβ*/
		SERVPRODUCT.ioffsetFreeNode=SERVPRODUCT.ioffsetCurNode;
	else
		SERVPRODUCTTRIENODE(ioffsetPre)->NextOffset=SERVPRODUCT.ioffsetCurNode;
	
	/*��յ�ǰ����,���ﲻҪ��ʼ���ڵ�*/
	SERVPRODUCT.ioffsetCurNode=-1;
	SERVPRODUCT.iCurNodeCnt=0;
}

/*�����Ϊ��ָ��˳���������*/
static int comp_shm_servproduct_servid(POINTER ioffsetValue,POINTER ioffsetHead)
{
	int res;
	struct IServProductStruct *pSource=SERVPRODUCTTRIEEXT(ioffsetValue);
	struct IServProductStruct *pTarget=SERVPRODUCTTRIEEXT(ioffsetHead);

	if((res=pSource->iProductID-pTarget->iProductID)!=0) return res;
			/*״̬����֤F0A���*/
        if((res=strcmp(pTarget->sState,pSource->sState))!=0) return res;

	return strcmp(pSource->sStateDate,pTarget->sStateDate);
}
static POINTER *get_next_shm_servproduct_servid(POINTER ioffsetHead)
{
        return &(NEXT_SERVPRODUCT__SERVID(ioffsetHead));
}
static int assign_servproduct_servid(POINTER *pioffsetHead,POINTER ioffsetValue)
{
        InsertListSortE(pioffsetHead,ioffsetValue,
                comp_shm_servproduct_servid,get_next_shm_servproduct_servid);
	return 0;
}

static int ItemBuildServProductShmIndex(POINTER ioffsetNew)
{
	int iTempCnt,iNodeCnt=0;
	TRIEEXT *pNodeSeg=SERVPRODUCT.pNode;
	struct IServProductStruct *pTemp;
	
	pTemp=SERVPRODUCTTRIEEXT(ioffsetNew);
		/*����SERV_ID����*/
	iTempCnt=InsertTrieE(&SERVPRODUCT.ioffsetServID,pNodeSeg,
		pTemp->sServID,	&(SERVPRODUCT.ioffsetFreeNode),
		&(SERVPRODUCT.ioffsetCurNode),ioffsetNew,
		assign_servproduct_servid);
		
	if(iTempCnt<0){WriteAlertMsg("�߼�����"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}

int RebuildServProductShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IServProductStruct *pTemp;
	
	/*����ǰ����ȡ��,�����,ͬʱ�������ݽڵ���Ϊ0*/
	ioffsetCur=SERVPRODUCT.ioffsetCurData;
	SERVPRODUCT.ioffsetCurData=-1;
	SERVPRODUCT.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=SERVPRODUCTTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*���Ҫ��̭�ļ�¼,��ֱ�Ӳ������ݿ�������*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp��SERVTRIEEXT(ioffsetNew)�ǵ�Ч��*/
			pTemp->NextOffset=SERVPRODUCT.ioffsetFreeData;
			SERVPRODUCT.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		
		if((iTempCnt=ItemBuildServProductShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		SERVPRODUCT.iCurNodeCnt+=iTempCnt;

		/*�������ٲ��뵽��ǰ�ڴ�������*/
		pTemp->NextOffset=SERVPRODUCT.ioffsetCurData;
		SERVPRODUCT.ioffsetCurData=ioffsetNew;
		/*ͳ�Ʊ�����¼��++*/
		SERVPRODUCT.iCurDataCnt++;
		
	}
	
	return 0;
}


/************����ˢ��һ�麯�����****����Ϊ��ȫˢ��֧�ֺ���*/

static void mvitem_servproduct(struct ServProductStruct *pi,struct IServProductStruct *po)
{
/*�ȳ�ʼ��SERVPRODUCT��Ľṹ*/

	po->ioffsetSAS[0]=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*�����ƶ�����*/
	po->iProductID=			pi->iProductID;
	
	strcpy(po->sServID,		pi->sServID);

	po->iServSeqNbr=		pi->iServSeqNbr;
	po->iSeqNbr=			pi->iSeqNbr;
	po->iProductTypeID=		pi->iProductTypeID;
	po->iProductQuantity=	pi->iProductQuantity;

	strcpy(po->sState,		pi->sState);
	strcpy(po->sStateDate,	pi->sStateDate);
	strcpy(po->sExpDate,	pi->sExpDate);
}

int BuildServProductMemListIndexAndMoveToShm()
{
	int iTempCnt;
	POINTER ioffsetNew;
	struct ServProductStruct *ptCur,*ptPre=NULL;
	
	
	ptCur=STAT_SERVPRODUCT.pServProductList;
	if(ptCur==NULL) return 0;
	
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		ioffsetNew=SERVPRODUCT.ioffsetFreeData;
		if(ioffsetNew==-1) {WriteAlertMsg("�߼�����"); return -1;}
		
		SERVPRODUCT.ioffsetFreeData=SERVPRODUCTTRIEEXT(ioffsetNew)->NextOffset;
		
		/*�������ƶ����ڴ���*/
		mvitem_servproduct(ptPre,SERVPRODUCTTRIEEXT(ioffsetNew));
		
		if((iTempCnt=ItemBuildServProductShmIndex(ioffsetNew))<0) return -1;
		
		/*ͳ�ƽڵ�����*/
		SERVPRODUCT.iCurNodeCnt+=iTempCnt;

		/*�������ٲ��뵽��ǰ�ڴ�������*/
		SERVPRODUCTTRIEEXT(ioffsetNew)->NextOffset=SERVPRODUCT.ioffsetCurData;
		SERVPRODUCT.ioffsetCurData=ioffsetNew;
		
		/*ͳ�Ʊ�����¼��++*/
		SERVPRODUCT.iCurDataCnt++;
	}
	
	return 0;
}

int ServProductSemWorking()
{
	int iSemID;
	
	/*���ָ���źŵƲ�����,������ɾ��*/
	if((iSemID=semget(SERVPRODUCTSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("����SERVPRODUCT�źŵ��쳣��ɾ��.\n");
		
		return FALSE;
	}
	if(errno!=EEXIST){
		printf("����SERVPRODUCT�źŵ�ʧ��");
		return FALSE;
	}
	return TRUE;
}

int ClientServProductUnmountNotify()
{
	if(ShmServProductHeadValid()){
		SERVPRODUCT.iShmID=SERVPRODUCT.pHead->iShmID;
		SERVPRODUCT.pHead->iShmID=-1;
	}
	return 0;
}

int ClientServProductConnectNotify()
{
	return UpdateShmHead(SERVPRODUCTDATAKEY,-1);
}

int CountingServProductTotalRecord()
{
	return STAT_SERVPRODUCT.iServProductCnt;
}

int StatServProductTotalNode()
{
	int iTempCnt;
	
	if((iTempCnt=TravelList((LIST*)(STAT_SERVPRODUCT.pServProductList),
		count_insert_trie_servid))<0){
		
		DestroyTrie(STAT_SERVPRODUCT.pServIDTrie);
		STAT_SERVPRODUCT.pServIDTrie=NULL;
		STAT_SERVPRODUCT.iServIDNodeCnt=0;
			
		WriteAlertMsg("ͳ�������������SERVPRODUCT_SERVID��������");
		return -1;
	}
	STAT_SERVPRODUCT.iServIDNodeCnt+=iTempCnt;
	
	iTempCnt=STAT_SERVPRODUCT.iServIDNodeCnt;
	
	printf("SERVPRODUCT��������������%d,ռ���ڴ�%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));

	WriteProcMsg("SERVPRODUCT��������������%d,ռ���ڴ�%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;	
}

int InitServProductControlRecord()
{
	int iErrCode,i;
	
	SERVPRODUCT.ioffsetServID=-1; 
	
	SERVPRODUCT.ioffsetFreeNode=-1;	/*�ڵ��������ͷָ��*/
	SERVPRODUCT.ioffsetFreeData=-1;	/*��¼��������ָ��*/
	
	SERVPRODUCT.ioffsetCurData=-1;	/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	SERVPRODUCT.ioffsetNewData=-1;	/*��¼���������ݵĹ������������*/
	
	SERVPRODUCT.ioffsetCurNode=-1;	/*��¼��ǰ�������Ѿ��洢����������*/
	
	SERVPRODUCT.iCurDataCnt=0;	/*��ǰ���ݼ�¼��*/
	SERVPRODUCT.iCurNodeCnt=0;	/*��ǰ������¼��*/
	
	SERVPRODUCT.iDataBufLen=(STAT_SERVPRODUCT.iServProductCnt+1000)*120/100;/*�ܼ�¼����*/
	SERVPRODUCT.iNodeBufLen=(STAT_SERVPRODUCT.iServIDNodeCnt+1000)*120/100;	/*�������ڵ����*/
	
	SERVPRODUCT.iLockGrpID=giLockGrpID;	/*�ڴ�����ʶ*/
	
	strcpy(SERVPRODUCT.sUpdateTime,STAT_SERVPRODUCT.sUpdateTime);/*�ϴθ���ʱ��*/
	
	/*���乲���ڴ�,����ʼ��*/
	SERVPRODUCT.pHead=(struct ShmServProductHead *)CreateShmInitHead(
		SERVPRODUCTDATAKEY,
		SERVPRODUCT.iDataBufLen*sizeof(struct IServProductStruct)+
		sizeof(struct ShmServProductHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�SERVDATEʧ��");
		return -1;
	}
	
	SERVPRODUCT.pData=(struct IServProductStruct*)(SERVPRODUCT.pHead+1);

	SERVPRODUCT.pNode=(TRIEEXT*)AllocShm(SERVPRODUCTNODEKEY,
		SERVPRODUCT.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("���乲���ڴ�SERVNODEʧ��");
		return -1;
	}
	
/*���������ڴ������������еĽڵ����ӵ�δ�õ����ݽڵ�������*/
	/*��βָ��Ϊ-1*/
	for(i=SERVPRODUCT.iDataBufLen-1;i>=0;i--){
		SERVPRODUCT.pData[i].NextOffset=SERVPRODUCT.ioffsetFreeData;
		SERVPRODUCT.ioffsetFreeData=i;
	}
	for(i=SERVPRODUCT.iNodeBufLen-1;i>=0;i--)	{		
		SERVPRODUCT.pNode[i].NextOffset=SERVPRODUCT.ioffsetFreeNode;
		SERVPRODUCT.ioffsetFreeNode=i;		
	}
	
	return 0;
}

void CopyServProductControlToShm()
{
	SERVPRODUCT.iShmID=SERVPRODUCT.pHead->iShmID;
	SERVPRODUCT.iTotalLen=SERVPRODUCT.pHead->iTotalLen;
	
	memcpy((void*)(SERVPRODUCT.pHead),&SERVPRODUCT,sizeof(struct ShmServProductHead));
}
