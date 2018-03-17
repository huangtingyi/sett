/*---------函数实现代码 serv.pc----------*/
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

/*统计节点数支持函数*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_servid(LIST *ptHead);

static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_servid(LIST *ptHead);
static int count_insert_trie_imsi(LIST *ptHead);
static int count_insert_trie_accnbr(LIST *ptHead);
static int count_insert_trie_acctid(LIST *ptHead);

/*将指定条件的SERV表记录MOUNT到内存中,
并统计SERV表的信息到STAT_SERV结构中主要是
数据数,各个索引的节点数等*/
static int MountingServToMem(int iUpdateFlag);
static int ItemBuildServShmIndex(POINTER ioffsetNew);

static int assign_serv_servid(POINTER *pioffsetHead,POINTER ioffsetValue);
static int assign_serv_imsi(POINTER *pioffsetHead,POINTER ioffsetValue);
static int assign_serv_accnbr(POINTER *pioffsetHead,POINTER ioffsetValue);
static int assign_serv_acctid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************以下是支持函数***************
********************************************************/




/*检查SERVSHM的完整性，不对则释放并，重新分配*/
/*返回数值 -1 需要重建 0 不要重建控制变量已经在内存SERV中*/
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

/*将指定条件的SERV表记录MOUNT到内存中,
并统计SERV表的信息到STAT_SERV结构中主要是
数据数,各个索引的节点数等*/
static int MountingServToMem(int iUpdateFlag)
{
	
	int res;
	struct ServStructIn TempSource;

	struct ServStruct *p;


	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);
	
/*初始化全局结构*/

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
			WriteAlertMsg("内存分配错误 struct ServStruct");
			return -1;
		}
		if((res=EGetServToStruct(p,&TempSource))<0){
			
			DestroyServStatList();
			
			WriteAlertMsg("获取数据库数据错误");
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

	printf("加载SERV表数据结束,记录数%d.\n",STAT_SERV.iServCnt);
	WriteProcMsg("加载SERV表数据结束,记录数%d",STAT_SERV.iServCnt);

	/*******刷新更新时间***/
	strcpy(SERV.sUpdateTime,STAT_SERV.sUpdateTime);

	return 0;
}

/*加载新节点函数*/
int MountingUpdatedServToMem()
{
	
	return MountingServToMem(TRUE);
}

/*加载所有节点到内存*/
int MountingTotalServToMem()
{
	return MountingServToMem(FALSE);
}
/*统计节点数支持函数*/
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
		
		/*删除可能分配的内存*/
		DestroyServTemporaryPrimaryIndex();
		
		WriteAlertMsg("建立临时主关键字索引错误");
		return -1;
	}
	ptHead=STAT_SERV.pServIDTrie;
	ioffsetCur=SERV.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVTRIEEXT(ioffsetCur);
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
	
	if(iNodeCnt!=DestroyServTemporaryPrimaryIndex()){
		WriteAlertMsg("删除临时主关键字索引错误");
		return -1;
	}
	return iDeleteCnt;
	
}
int CountingServIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingServCurDeleteRecord())<0) return -1;
	
	/*返回,当前使用空间-淘汰空间+增加空间*/
	return SERV.iCurDataCnt-iDeleteCnt+STAT_SERV.iServCnt;	
}
int GetServTotalBufRecord()
{
	return SERV.iDataBufLen;
}
/*统计节点数支持函数*/
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

/***用户标识SERV_ID索引****/

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
			
			WriteAlertMsg("统计服务资料SERV_SERVID索引节点错误");
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
			
		WriteAlertMsg("统计链表服务资料SERV_SERVID索引节点错误");
		return -1;
	}
	STAT_SERV.iServIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pServIDTrie);
	STAT_SERV.pServIDTrie=NULL;
	
	printf("SERV表SERV_ID索引节点数%d,占用内存%dM.\n",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

	WriteProcMsg("SERV表SERV_ID索引节点数%d,占用内存%dM",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

/*****号码ACC_NBR索引**/
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
			
			WriteAlertMsg("统计服务资料SERV_ACCNBR索引节点错误");
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
			
		WriteAlertMsg("统计链表服务资料SERV_ACCNBR索引节点错误");
		return -1;
	}
	STAT_SERV.iAccNbrNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pAccNbrTrie);
	STAT_SERV.pAccNbrTrie=NULL;
	
	printf("SERV表ACC_NBR索引节点数%d,占用内存%dM",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));
	
	WriteProcMsg("SERV表ACC_NBR索引节点数%d,占用内存%dM",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));
	
/*****号码IMSI索引******/
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
			
			WriteAlertMsg("统计服务资料SERV_IMSI索引节点错误");
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
			
		WriteAlertMsg("统计链表服务资料SERV_IMSI索引节点错误");
		return -1;
	}
	STAT_SERV.iImsiNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pImsiTrie);
	STAT_SERV.pImsiTrie=NULL;
	
	printf("SERV表IMSI索引节点数%d,占用内存%dM.\n",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));
	
	WriteProcMsg("SERV表IMSI索引节点数%d,占用内存%dM",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));

	

/*****号码ACCT_ID索引**/
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
			
			WriteAlertMsg("统计服务资料SERV_ACCTID索引节点错误");
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
			
		WriteAlertMsg("统计链表服务资料SERV_ACCTID索引节点错误");
		return -1;
	}
	STAT_SERV.iAcctIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_SERV.pAcctIDTrie);
	STAT_SERV.pAcctIDTrie=NULL;
	
	printf("SERV表ACCT_ID索引节点数%d,占用内存%dM",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	WriteProcMsg("SERV表ACCT_ID索引节点数%d,占用内存%dM",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	iTempCnt=STAT_SERV.iServIDNodeCnt+
		STAT_SERV.iAccNbrNodeCnt+
		STAT_SERV.iImsiNodeCnt+
		STAT_SERV.iAcctIDNodeCnt;
	
	printf("SERV表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("SERV表所有索引总数%d,占用内存%dM",
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
	
	/*清空索引节点*/
	SERV.ioffsetAccNbr=-1;
	SERV.ioffsetServID=-1; 
	SERV.ioffsetImsi=-1;
	SERV.ioffsetAcctID=-1;
	
	/****循环遍历到文件末尾***/
	ioffsetPre=-1;
	ioffsetCur=SERV.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=SERVTRIENODE(ioffsetPre)->NextOffset;
	}
	
	if(ioffsetPre==-1)/*空链表直接赋值,否则挂到链表末尾*/
		SERV.ioffsetFreeNode=SERV.ioffsetCurNode;
	else
		SERVTRIENODE(ioffsetPre)->NextOffset=SERV.ioffsetCurNode;
	
	/*清空当前链表,这里不要初始化节点*/
	SERV.ioffsetCurNode=-1;
	SERV.iCurNodeCnt=0;
}


/*必须该为按指定顺序挂入链表*/
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
	
		/*插入SERV_ID索引*/
	iTempCnt=InsertTrieE(&SERV.ioffsetServID,pNodeSeg,
		pTemp->sServID,	&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_servid);
		
	if(iTempCnt<0){WriteAlertMsg("逻辑错误"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
		
		/*插入ACC_NBR索引*/
	iTempCnt=InsertTrieE(&SERV.ioffsetAccNbr,pNodeSeg,
		pTemp->sAccNbr,	&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_accnbr);
		
	if(iTempCnt<0){WriteAlertMsg("逻辑错误"); return -1;}

	iNodeCnt+=iTempCnt;

		/*插入ACCT_ID索引*/
	iTempCnt=InsertTrieE(&SERV.ioffsetAcctID,pNodeSeg,
		pTemp->sDefaultAcctID,&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_acctid);
		
	if(iTempCnt<0){WriteAlertMsg("逻辑错误"); return -1;}

	iNodeCnt+=iTempCnt;

		/*忽略建立空的IMSI号的索引*/	
	if(pTemp->sImsi[0]=='*' || pTemp->sImsi[0]=='0') return iNodeCnt;
	
	/*插入IMSI索引*/
	iTempCnt=InsertTrieE(&SERV.ioffsetImsi,pNodeSeg,
		pTemp->sImsi,&(SERV.ioffsetFreeNode),
		&(SERV.ioffsetCurNode),ioffsetNew,
		assign_serv_imsi);
		
	if(iTempCnt<0){WriteAlertMsg("逻辑错误"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}
int RebuildServShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IServStruct *pTemp;
	
	/*将当前链表取出,并清空,同时设置数据节点数为0*/
	ioffsetCur=SERV.ioffsetCurData;
	SERV.ioffsetCurData=-1;
	SERV.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=SERVTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*如果要淘汰的记录,则直接插入数据空闲链表*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp和SERVTRIEEXT(ioffsetNew)是等效的*/
			pTemp->NextOffset=SERV.ioffsetFreeData;
			SERV.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		pTemp->ioffsetSAS[1]=-1;
		pTemp->ioffsetSAS[2]=-1;
		pTemp->ioffsetSAS[3]=-1;
		
		if((iTempCnt=ItemBuildServShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		SERV.iCurNodeCnt+=iTempCnt;

		/*将数据再插入到当前内存链表中*/
		pTemp->NextOffset=SERV.ioffsetCurData;
		SERV.ioffsetCurData=ioffsetNew;
		/*统计表话单记录数++*/
		SERV.iCurDataCnt++;
		
	}
	
	return 0;
	
	
}


/************增量刷新一组函数完毕****以下为完全刷新支持函数*/

static void mvitem_serv(struct ServStruct *pi,struct IServStruct *po)
{
/*先初始化SERV表的结构*/

	po->ioffsetSAS[0]=-1;
	po->ioffsetSAS[1]=-1;
	po->ioffsetSAS[2]=-1;
	po->ioffsetSAS[3]=-1;
	
	
	po->iTServCatgID=-1;
	po->iAServCatgID=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*数据移动部分*/
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
		if(ioffsetNew==-1) {WriteAlertMsg("逻辑错误"); return -1;}
		
		SERV.ioffsetFreeData=SERVTRIEEXT(ioffsetNew)->NextOffset;
		
		/*将数据移动到内存中*/
		mvitem_serv(ptPre,SERVTRIEEXT(ioffsetNew));
		
		
		if((iTempCnt=ItemBuildServShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		SERV.iCurNodeCnt+=iTempCnt;


		/*将数据再插入到当前内存链表中*/
		SERVTRIEEXT(ioffsetNew)->NextOffset=SERV.ioffsetCurData;
		SERV.ioffsetCurData=ioffsetNew;
		
		/*统计表话单记录数++*/
		SERV.iCurDataCnt++;
		
	}
	
	return 0;
}
int ServSemWorking()
{
	int iSemID;
	
	/*如果指定信号灯不存在,则建立后删除*/
	if((iSemID=semget(SERVSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("建立SERV信号灯异常被删除.\n");
		
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

/***统计SERVID索引***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_servid))<0){
		
		DestroyTrie(STAT_SERV.pServIDTrie);
		STAT_SERV.pServIDTrie=NULL;
		STAT_SERV.iServIDNodeCnt=0;
			
		WriteAlertMsg("统计链表服务资料SERV_SERVID索引节点错误");
		return -1;
	}
	STAT_SERV.iServIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pServIDTrie);
	STAT_SERV.pServIDTrie=NULL;
	
	printf("SERV表SERV_ID索引节点数%d,占用内存%dM.\n",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

	WriteProcMsg("SERV表SERV_ID索引节点数%d,占用内存%dM",
		STAT_SERV.iServIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iServIDNodeCnt/1024/1024));

/***统计ACC_NBR索引***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_accnbr))<0){
		
		DestroyTrie(STAT_SERV.pAccNbrTrie);
		STAT_SERV.pAccNbrTrie=NULL;
		STAT_SERV.iAccNbrNodeCnt=0;
			
		WriteAlertMsg("统计链表服务资料SERV_ACCNBR索引节点错误");
		return -1;
	}
	STAT_SERV.iAccNbrNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pAccNbrTrie);
	STAT_SERV.pAccNbrTrie=NULL;
	
	printf("SERV表ACC_NBR索引节点数%d,占用内存%dM.\n",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));

	WriteProcMsg("SERV表ACC_NBR索引节点数%d,占用内存%dM",
		STAT_SERV.iAccNbrNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAccNbrNodeCnt/1024/1024));
/***统计IMSI索引***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_imsi))<0){
		
		DestroyTrie(STAT_SERV.pImsiTrie);
		STAT_SERV.pImsiTrie=NULL;
		STAT_SERV.iImsiNodeCnt=0;
			
		WriteAlertMsg("统计链表服务资料SERV_IMSI索引节点错误");
		return -1;
	}
	STAT_SERV.iImsiNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pImsiTrie);
	STAT_SERV.pImsiTrie=NULL;
	
	printf("SERV表IMSI索引节点数%d,占用内存%dM.\n",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));
	
	WriteProcMsg("SERV表IMSI索引节点数%d,占用内存%dM",
		STAT_SERV.iImsiNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iImsiNodeCnt/1024/1024));
/***统计ACCT_ID索引***/	
	if((iTempCnt=TravelList((LIST*)(STAT_SERV.pServList),
		count_insert_trie_acctid))<0){
		
		DestroyTrie(STAT_SERV.pAcctIDTrie);
		STAT_SERV.pAcctIDTrie=NULL;
		STAT_SERV.iAcctIDNodeCnt=0;
			
		WriteAlertMsg("统计链表服务资料SERV_ACCTID索引节点错误");
		return -1;
	}
	STAT_SERV.iAcctIDNodeCnt+=iTempCnt;
	
	
	DestroyTrie(STAT_SERV.pAcctIDTrie);
	STAT_SERV.pAcctIDTrie=NULL;
	
	printf("SERV表ACCTID索引节点数%d,占用内存%dM.\n",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	WriteProcMsg("SERV表ACCTID索引节点数%d,占用内存%dM",
		STAT_SERV.iAcctIDNodeCnt,
		(int)(sizeof(TRIEEXT)*STAT_SERV.iAcctIDNodeCnt/1024/1024));
	
	iTempCnt=STAT_SERV.iServIDNodeCnt+
		STAT_SERV.iAccNbrNodeCnt+
		STAT_SERV.iImsiNodeCnt+
		STAT_SERV.iAcctIDNodeCnt;
	
	printf("SERV表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	WriteProcMsg("SERV表所有索引总数%d,占用内存%dM",
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
	
	SERV.ioffsetFreeNode=-1;	/*节点空闲链表头指针*/
	SERV.ioffsetFreeData=-1;	/*记录空闲数据指针*/
	
	SERV.ioffsetCurData=-1;		/*记录当前共享中已经存储数据的链表*/
	SERV.ioffsetNewData=-1;		/*记录新增加数据的共享的数据链表*/
	
	SERV.ioffsetCurNode=-1;		/*记录当前共享中已经存储索引的链表*/
	
	SERV.iCurDataCnt=0;		/*当前数据记录数*/
	SERV.iCurNodeCnt=0;		/*当前索引记录数*/
	
	SERV.iDataBufLen=(STAT_SERV.iServCnt+1000)*120/100;/*总记录个数*/
	SERV.iNodeBufLen=(STAT_SERV.iServIDNodeCnt+
			STAT_SERV.iAccNbrNodeCnt+
			STAT_SERV.iImsiNodeCnt+
			STAT_SERV.iAcctIDNodeCnt+1000)*120/100;/*总索引节点数*/
	
	pprintf(0,0,"需要的SERV数据内存量%dM,索引量为%ldM.\n",
		SERV.iDataBufLen*sizeof(struct IServStruct)/1024/1024,
		SERV.iNodeBufLen*sizeof(TRIEEXT)/1024/1024);
	
	SERV.iLockGrpID=giLockGrpID;	/*内存锁标识*/
	
	strcpy(SERV.sUpdateTime,STAT_SERV.sUpdateTime);/*上次更新时间*/
	
	/*struct  IServStruct *pData;*/	/*数据段地址*/
	/*TRIEEXT *pNode;	*/		/*索引节点指针*/
	/*struct  ShmServHead *pHead;*/  /*控制头地址*/
	
	
	

	/*分配共享内存,并初始化*/
	SERV.pHead=(struct ShmServHead *)CreateShmInitHead(SERVDATAKEY,
		SERV.iDataBufLen*sizeof(struct IServStruct)+
		sizeof(struct ShmServHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存SERVDATA失败");
		return -1;
	}
	
	SERV.pData=(struct IServStruct*)(SERV.pHead+1);


	SERV.pNode=(TRIEEXT*)AllocShm(SERVNODEKEY,
		SERV.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存SERVNODE失败");
		return -1;
	}
	
/*遍历共享内存数据区将所有的节点连接到未用的数据节点链表内*/
	/*结尾指针为-1*/
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
