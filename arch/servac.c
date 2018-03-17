/*---------函数实现代码 serv_product.pc----------*/
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

/*统计节点数支持函数*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_servid(LIST *ptHead);
static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_servid(LIST *ptHead);

/*将指定条件的SERVACCT表记录MOUNT到内存中,
并统计SERVACCT表的信息到STAT_SERVACCT结构中主要是
数据数,各个索引的节点数等*/
static int MountingServAcctToMem(int iUpdateFlag);
static int ItemBuildServAcctShmIndex(POINTER ioffsetNew);

static int assign_servacct_servid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************以下是支持函数*****************
********************************************************/




/*检查SERVACCTSHM的完整性，不对则释放并，重新分配*/
/*返回数值 -1 需要重建 0 不要重建控制变量已经在内存SERVACCT中*/
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

/*将指定条件的SERVACCT表记录MOUNT到内存中,
并统计SERVACCT表的信息到STAT_SERVACCT结构中主要是
数据数,各个索引的节点数等*/
static int MountingServAcctToMem(int iUpdateFlag)
{
	
	int res;
	struct ServAcctStructIn TempSource;

	struct ServAcctStruct *p;


	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);
	
/*初始化全局结构*/

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
			WriteAlertMsg("内存分配错误 struct ServAcctStruct");
			return -1;
		}
		if((res=EGetServAcctToStruct(p,&TempSource))<0){
			
			DestroyServAcctStatList();
			
			WriteAlertMsg("获取数据库数据错误");
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

	printf("加载SERVACCT表数据结束,记录数%d.\n",STAT_SERVACCT.iServAcctCnt);
	WriteProcMsg("加载SERVACCT表数据结束,记录数%d",
		STAT_SERVACCT.iServAcctCnt);

	strcpy(SERVACCT.sUpdateTime,STAT_SERVACCT.sUpdateTime);

	return 0;
}

/*加载新节点函数*/
int MountingUpdatedServAcctToMem()
{
	return MountingServAcctToMem(TRUE);
}

/*加载所有节点到内存*/
int MountingTotalServAcctToMem()
{
	return MountingServAcctToMem(FALSE);
}

/*统计节点数支持函数,只是挂入,避免覆盖PNEXT*/
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
		
		/*删除可能分配的内存*/
		DestroyServAcctTemporaryPrimaryIndex();
		
		WriteAlertMsg("建立临时主关键字索引错误");
		return -1;
	}
	ptHead=STAT_SERVACCT.pServIDTrie;
	ioffsetCur=SERVACCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVACCTTRIEEXT(ioffsetCur);
		/*如果在本地链表中已经存在,则直接设置为删除*/
		if(SearchTrieF(ptHead,pTemp->sServID,(void*)&pNoUse)==FOUND){
			iDeleteCnt++;
			pTemp->cDeleteFlag=DELETE_RECORD;
			ioffsetCur=pTemp->NextOffset;
			continue;
		}
		/*在用记录则直接跳过*/
		if(strcmp(pTemp->sState,"F0H")!=0){
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
	
	if(iNodeCnt!=DestroyServAcctTemporaryPrimaryIndex()){
		WriteAlertMsg("删除临时主关键字索引错误");
		return -1;
	}
	return iDeleteCnt;
}

int CountingServAcctIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingServAcctCurDeleteRecord())<0) return -1;
	
	/*返回,当前使用空间-淘汰空间+增加空间*/
	return SERVACCT.iCurDataCnt-iDeleteCnt+STAT_SERVACCT.iServAcctCnt;	
}

int GetServAcctTotalBufRecord()
{
	return SERVACCT.iDataBufLen;
}

/*统计节点数支持函数*/
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

/***用户标识SERV_ID索引****/

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
			
			WriteAlertMsg("统计资料SERVACCT_SERVID索引节点错误");
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
			
		WriteAlertMsg("统计链表服务资料SERVACCT_SERVID索引节点错误");
		return -1;
	}
	STAT_SERVACCT.iServIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERVACCT.pServIDTrie);
	STAT_SERVACCT.pServIDTrie=NULL;
	
	iTempCnt=STAT_SERVACCT.iServIDNodeCnt;
	
	printf("SERVACCT表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("SERVACCT表所有索引总数%d,占用内存%dM",
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
	
	/*清空索引节点*/
	SERVACCT.ioffsetServID=-1; 
	
	ioffsetPre=-1;
	ioffsetCur=SERVACCT.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=SERVACCTTRIENODE(ioffsetPre)->NextOffset;
	}
	if(ioffsetPre==-1)/*空链表直接赋值,否则挂到链表末尾*/
		SERVACCT.ioffsetFreeNode=SERVACCT.ioffsetCurNode;
	else
		SERVACCTTRIENODE(ioffsetPre)->NextOffset=SERVACCT.ioffsetCurNode;
	
	/*清空当前链表,这里不要初始化节点*/
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
/*必须该为按指定顺序挂入链表*/
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
	
		/*插入SERV_ID索引*/
	iTempCnt=InsertTrieE(&SERVACCT.ioffsetServID,pNodeSeg,
		pTemp->sServID,	&(SERVACCT.ioffsetFreeNode),
		&(SERVACCT.ioffsetCurNode),ioffsetNew,
		assign_servacct_servid);
		
	if(iTempCnt<0){WriteAlertMsg("逻辑错误"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}

int RebuildServAcctShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IServAcctStruct *pTemp;
	
	/*将当前链表取出,并清空,同时设置数据节点数为0*/
	ioffsetCur=SERVACCT.ioffsetCurData;
	SERVACCT.ioffsetCurData=-1;
	SERVACCT.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=SERVACCTTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*如果要淘汰的记录,则直接插入数据空闲链表*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp和SERVTRIEEXT(ioffsetNew)是等效的*/
			pTemp->NextOffset=SERVACCT.ioffsetFreeData;
			SERVACCT.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		
		if((iTempCnt=ItemBuildServAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		SERVACCT.iCurNodeCnt+=iTempCnt;

		/*将数据再插入到当前内存链表中*/
		pTemp->NextOffset=SERVACCT.ioffsetCurData;
		SERVACCT.ioffsetCurData=ioffsetNew;
		/*统计表话单记录数++*/
		SERVACCT.iCurDataCnt++;
	}
	
	return 0;
}

/************增量刷新一组函数完毕****以下为完全刷新支持函数*/

static void mvitem_servacct(struct ServAcctStruct *pi,struct IServAcctStruct *po)
{
/*先初始化SERVACCT表的结构*/

	po->ioffsetSAS[0]=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*数据移动部分*/
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
		if(ioffsetNew==-1) {WriteAlertMsg("逻辑错误"); return -1;}
		
		SERVACCT.ioffsetFreeData=SERVACCTTRIEEXT(ioffsetNew)->NextOffset;
		
		/*将数据移动到内存中*/
		mvitem_servacct(ptPre,SERVACCTTRIEEXT(ioffsetNew));
		
		if((iTempCnt=ItemBuildServAcctShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		SERVACCT.iCurNodeCnt+=iTempCnt;

		/*将数据再插入到当前内存链表中*/
		SERVACCTTRIEEXT(ioffsetNew)->NextOffset=SERVACCT.ioffsetCurData;
		SERVACCT.ioffsetCurData=ioffsetNew;
		
		/*统计表话单记录数++*/
		SERVACCT.iCurDataCnt++;
		
	}
	
	return 0;
}

int ServAcctSemWorking()
{
	int iSemID;
	
	/*如果指定信号灯不存在,则建立后删除*/
	if((iSemID=semget(SERVACCTSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("建立SERVACCT信号灯异常被删除.\n");
		
		return FALSE;
	}
	if(errno!=EEXIST){
		printf("建立SERVACCT信号灯失败.\n");
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
			
		WriteAlertMsg("统计链表资料SERVACCT_SERVID索引节点错误");
		return -1;
	}
	STAT_SERVACCT.iServIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_SERVACCT.pServIDTrie);
	STAT_SERVACCT.pServIDTrie=NULL;
	
	iTempCnt=STAT_SERVACCT.iServIDNodeCnt;
	
	printf("SERVACCT表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	WriteProcMsg("SERVACCT表所有索引总数%d,占用内存%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;	
}

int InitServAcctControlRecord()
{
	int iErrCode,i;
	
	SERVACCT.ioffsetServID=-1; 
	
	SERVACCT.ioffsetFreeNode=-1;	/*节点空闲链表头指针*/
	SERVACCT.ioffsetFreeData=-1;	/*记录空闲数据指针*/
	
	SERVACCT.ioffsetCurData=-1;	/*记录当前共享中已经存储数据的链表*/
	SERVACCT.ioffsetNewData=-1;	/*记录新增加数据的共享的数据链表*/
	
	SERVACCT.ioffsetCurNode=-1;	/*记录当前共享中已经存储索引的链表*/
	
	SERVACCT.iCurDataCnt=0;		/*当前数据记录数*/
	SERVACCT.iCurNodeCnt=0;		/*当前索引记录数*/
	
	SERVACCT.iDataBufLen=(STAT_SERVACCT.iServAcctCnt+1000)*120/100;/*总记录个数*/
	SERVACCT.iNodeBufLen=(STAT_SERVACCT.iServIDNodeCnt+1000)*120/100;	/*总索引节点个数*/
	
	SERVACCT.iLockGrpID=giLockGrpID;	/*内存锁标识*/
	
	strcpy(SERVACCT.sUpdateTime,STAT_SERVACCT.sUpdateTime);/*上次更新时间*/
	
	/*分配共享内存,并初始化*/
	SERVACCT.pHead=(struct ShmServAcctHead *)CreateShmInitHead(
		SERVACCTDATAKEY,
		SERVACCT.iDataBufLen*sizeof(struct IServAcctStruct)+
		sizeof(struct ShmServAcctHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存SERVACCTDATA失败");
		return -1;
	}
	
	SERVACCT.pData=(struct IServAcctStruct*)(SERVACCT.pHead+1);

	SERVACCT.pNode=(TRIEEXT*)AllocShm(SERVACCTNODEKEY,
		SERVACCT.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存SERVACCTNODE失败");
		return -1;
	}
	
/*遍历共享内存数据区将所有的节点连接到未用的数据节点链表内*/
	/*结尾指针为-1*/
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
