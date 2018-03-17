/*---------函数实现代码 acct.pc----------*/
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

/*统计节点数支持函数*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_acctid(LIST *ptHead);
static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_acctid(LIST *ptHead);

/*将指定条件的ACCT表记录MOUNT到内存中,
并统计ACCT表的信息到STAT_ACCT结构中主要是
数据数,各个索引的节点数等*/
static int MountingAcctToMem(int iUpdateFlag);
static int ItemBuildAcctShmIndex(POINTER ioffsetNew);

static int assign_acct_acctid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************以下是支持函数***************
********************************************************/




/*检查ACCTSHM的完整性，不对则释放并，重新分配*/
/*返回数值 -1 需要重建 0 不要重建控制变量已经在内存ACCT中*/
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

/*将指定条件的ACCT表记录MOUNT到内存中,
并统计ACCT表的信息到STAT_ACCT结构中主要是
数据数,各个索引的节点数等*/
static int MountingAcctToMem(int iUpdateFlag)
{
	
	int res;
	struct AcctStructIn TempSource;

	struct AcctStruct *p;


	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);
	
/*初始化全局结构*/

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
			WriteAlertMsg("内存分配错误 struct AcctStruct");
			return -1;
		}
		if((res=EGetAcctToStruct(p,&TempSource))<0){
			
			DestroyAcctStatList();
			
			WriteAlertMsg("获取数据库数据错误");
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

	printf("加载ACCT表数据结束,记录数%d.\n",STAT_ACCT.iAcctCnt);
	WriteProcMsg("加载ACCT表数据结束,记录数%d",STAT_ACCT.iAcctCnt);

	strcpy(ACCT.sUpdateTime,STAT_ACCT.sUpdateTime);

	return 0;
}

/*加载新节点函数*/
int MountingUpdatedAcctToMem()
{
	return MountingAcctToMem(TRUE);
}

/*加载所有节点到内存*/
int MountingTotalAcctToMem()
{
	return MountingAcctToMem(FALSE);
}
/*统计节点数支持函数*/
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
		
		/*删除可能分配的内存*/
		DestroyAcctTemporaryPrimaryIndex();
		
		WriteAlertMsg("建立临时主关键字索引错误");
		return -1;
	}
	ptHead=STAT_ACCT.pAcctIDTrie;
	ioffsetCur=ACCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=ACCTTRIEEXT(ioffsetCur);
		/*如果在本地链表中已经存在,则直接设置为删除*/
		if(SearchTrieF(ptHead,pTemp->sAcctID,(void*)&pNoUse)==FOUND){
			iDeleteCnt++;
			pTemp->cDeleteFlag=DELETE_RECORD;
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		/*在用记录则直接跳过*/
		if(strcmp(pTemp->sState,"10H")!=0){
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		/*300天前的数据肯定删除*/
		if((tOracleTime-tGetTime(pTemp->sStateDate))/86400>300){
			iDeleteCnt++;
			pTemp->cDeleteFlag=DELETE_RECORD;
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		
		ioffsetCur=pTemp->NextOffset;
		
	}
	
	if(iNodeCnt!=DestroyAcctTemporaryPrimaryIndex()){
		WriteAlertMsg("删除临时主关键字索引错误");
		return -1;
	}
	return iDeleteCnt;
	
}
int CountingAcctIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingAcctCurDeleteRecord())<0) return -1;
	
	/*返回,当前使用空间-淘汰空间+增加空间*/
	return ACCT.iCurDataCnt-iDeleteCnt+STAT_ACCT.iAcctCnt;	
}
int GetAcctTotalBufRecord()
{
	return ACCT.iDataBufLen;
}

/*统计节点数支持函数*/
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

/***账户标识ACCT_ID索引****/

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
			
			WriteAlertMsg("统计服务资料ACCT_ACCTID索引节点错误");
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
			
		WriteAlertMsg("统计链表服务资料ACCT_ACCTID索引节点错误");
		return -1;
	}
	STAT_ACCT.iAcctIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_ACCT.pAcctIDTrie);
	STAT_ACCT.pAcctIDTrie=NULL;
	
	printf("ACCT表ACCT_ID索引节点数%d,占用内存%dM.\n",
		STAT_ACCT.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_ACCT.iAcctIDNodeCnt/1024/1024));

	WriteProcMsg("ACCT表ACCT_ID索引节点数%d,占用内存%dM",
		STAT_ACCT.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_ACCT.iAcctIDNodeCnt/1024/1024));

	
	iTempCnt=STAT_ACCT.iAcctIDNodeCnt;
	
	printf("ACCT表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("ACCT表所有索引总数%d,占用内存%dM",
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
	
	/*清空索引节点*/
	ACCT.ioffsetAcctID=-1; 
	
	ioffsetPre=-1;
	ioffsetCur=ACCT.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=ACCTTRIENODE(ioffsetPre)->NextOffset;
	}
	if(ioffsetPre==-1)/*空链表直接赋值,否则挂到链表末尾*/
		ACCT.ioffsetFreeNode=ACCT.ioffsetCurNode;
	else
		ACCTTRIENODE(ioffsetPre)->NextOffset=ACCT.ioffsetCurNode;
	
	/*清空当前链表,这里不要初始化节点*/
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
/*必须该为按指定顺序挂入链表*/
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
	
		/*插入ACCT_ID索引*/
	iTempCnt=InsertTrieE(&ACCT.ioffsetAcctID,pNodeSeg,
		pTemp->sAcctID,	&(ACCT.ioffsetFreeNode),
		&(ACCT.ioffsetCurNode),ioffsetNew,
		assign_acct_acctid);
		
	if(iTempCnt<0){WriteAlertMsg("逻辑错误"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}

int RebuildAcctShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IAcctStruct *pTemp;
	
	
	/*将当前链表取出,并清空,同时设置数据节点数为0*/
	ioffsetCur=ACCT.ioffsetCurData;
	ACCT.ioffsetCurData=-1;
	ACCT.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=ACCTTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*如果要淘汰的记录,则直接插入数据空闲链表*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp和ACCTTRIEEXT(ioffsetNew)是等效的*/
			pTemp->NextOffset=ACCT.ioffsetFreeData;
			ACCT.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		
		if((iTempCnt=ItemBuildAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		ACCT.iCurNodeCnt+=iTempCnt;

		/*将数据再插入到当前内存链表中*/
		pTemp->NextOffset=ACCT.ioffsetCurData;
		ACCT.ioffsetCurData=ioffsetNew;
		/*统计表话单记录数++*/
		ACCT.iCurDataCnt++;
		
	}
	
	return 0;
}


/************增量刷新一组函数完毕****以下为完全刷新支持函数*/

static void mvitem_acct(struct AcctStruct *pi,struct IAcctStruct *po)
{
/*先初始化ACCT表的结构*/

	po->ioffsetSAS[0]=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*数据移动部分*/
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
		if(ioffsetNew==-1) {WriteAlertMsg("逻辑错误"); return -1;}
		
		ACCT.ioffsetFreeData=ACCTTRIEEXT(ioffsetNew)->NextOffset;
		
		/*将数据移动到内存中*/
		mvitem_acct(ptPre,ACCTTRIEEXT(ioffsetNew));
		
		if((iTempCnt=ItemBuildAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		ACCT.iCurNodeCnt+=iTempCnt;


		/*将数据再插入到当前内存链表中*/
		ACCTTRIEEXT(ioffsetNew)->NextOffset=ACCT.ioffsetCurData;
		ACCT.ioffsetCurData=ioffsetNew;
		
		/*统计表话单记录数++*/
		ACCT.iCurDataCnt++;
		
	}
	
	return 0;
}

int AcctSemWorking()
{
	int iSemID;
	
	/*如果指定信号灯不存在,则建立后删除*/
	if((iSemID=semget(ACCTSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("建立ACCT信号灯异常被删除.\n");
		
		return FALSE;
	}
	if(errno!=EEXIST){
		printf("建立ACCT信号灯失败.\n");
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
			
		WriteAlertMsg("统计链表服务资料ACCT_ACCTID索引节点错误");
		return -1;
	}
	STAT_ACCT.iAcctIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_ACCT.pAcctIDTrie);
	STAT_ACCT.pAcctIDTrie=NULL;
	
	iTempCnt=STAT_ACCT.iAcctIDNodeCnt;
	
	printf("ACCT表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("ACCT表所有索引总数%d,占用内存%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;	
}

int InitAcctControlRecord()
{
	int iErrCode,i;
	
	ACCT.ioffsetAcctID=-1; 
	
	ACCT.ioffsetFreeNode=-1;	/*节点空闲链表头指针*/
	ACCT.ioffsetFreeData=-1;	/*记录空闲数据指针*/
	
	ACCT.ioffsetCurData=-1;		/*记录当前共享中已经存储数据的链表*/
	ACCT.ioffsetNewData=-1;		/*记录新增加数据的共享的数据链表*/
	
	ACCT.ioffsetCurNode=-1;		/*记录当前共享中已经存储索引的链表*/
	
	ACCT.iCurDataCnt=0;		/*当前数据记录数*/
	ACCT.iCurNodeCnt=0;		/*当前索引记录数*/
	
	ACCT.iDataBufLen=(STAT_ACCT.iAcctCnt+1000)*120/100;/*总记录个数*/
	ACCT.iNodeBufLen=(STAT_ACCT.iAcctIDNodeCnt+1000)*120/100;	/*总索引节点个数*/
	
	ACCT.iLockGrpID=giLockGrpID;	/*内存锁标识*/
	
	strcpy(ACCT.sUpdateTime,STAT_ACCT.sUpdateTime);/*上次更新时间*/
	

	/*分配共享内存,并初始化*/
	ACCT.pHead=(struct ShmAcctHead *)CreateShmInitHead(ACCTDATAKEY,
		ACCT.iDataBufLen*sizeof(struct IAcctStruct)+
		sizeof(struct ShmAcctHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存ACCTDATA失败");
		return -1;
	}
	
	ACCT.pData=(struct IAcctStruct*)(ACCT.pHead+1);


	ACCT.pNode=(TRIEEXT*)AllocShm(ACCTNODEKEY,
		ACCT.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存ACCTNODE失败");
		return -1;
	}
	
/*遍历共享内存数据区将所有的节点连接到未用的数据节点链表内*/
	/*结尾指针为-1*/
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
