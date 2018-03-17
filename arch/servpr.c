/*---------函数实现代码 serv_product.pc----------*/
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

/*统计节点数支持函数*/
static void assign_list(void **pp,void *p);
static int build_insert_trie_servid(LIST *ptHead);
static void assign_do_nothing(void **pp,void *p);
static int count_insert_trie_servid(LIST *ptHead);

/*将指定条件的SERVPRODUCT表记录MOUNT到内存中,
并统计SERVPRODUCT表的信息到STAT_SERVPRODUCT结构中主要是
数据数,各个索引的节点数等*/
static int MountingServProductToMem(int iUpdateFlag);
static int ItemBuildServProductShmIndex(POINTER ioffsetNew);

static int assign_servproduct_servid(POINTER *pioffsetHead,POINTER ioffsetValue);


/********************************************************
**************************以下是支持函数***************
********************************************************/

/*检查SERVSHM的完整性，不对则释放并，重新分配*/
/*返回数值 -1 需要重建 0 不要重建控制变量已经在内存SERV中*/
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

/*将指定条件的SERVPRODUCT表记录MOUNT到内存中,
并统计SERVPRODUCT表的信息到STAT_SERVPRODUCT结构中主要是
数据数,各个索引的节点数等*/
static int MountingServProductToMem(int iUpdateFlag)
{
	
	int res;
	struct ServProductStructIn TempSource;
	struct ServProductStruct *p;

	char sOracleTime[15];
	char sCondition[1024];
	
	
	GetHostTime(sOracleTime);

/*初始化全局结构*/
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
			WriteAlertMsg("内存分配错误 struct ServProductStruct");
			return -1;
		}
		if((res=EGetServProductToStruct(p,&TempSource))<0){
			
			DestroyServProductStatList();
			
			WriteAlertMsg("获取数据库数据错误");
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

	printf("加载SERVPRODUCT表数据结束,记录数%d.\n",
		STAT_SERVPRODUCT.iServProductCnt);

	WriteProcMsg("加载SERVPRODUCT表数据结束,记录数%d",
		STAT_SERVPRODUCT.iServProductCnt);

	strcpy(SERVPRODUCT.sUpdateTime,STAT_SERVPRODUCT.sUpdateTime);

	return 0;
}

/*加载新节点函数*/
int MountingUpdatedServProductToMem()
{
	return MountingServProductToMem(TRUE);
}

/*加载所有节点到内存*/
int MountingTotalServProductToMem()
{
	return MountingServProductToMem(FALSE);
}

/*统计节点数支持函数,只是挂入,避免覆盖PNEXT*/
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
		
		/*删除可能分配的内存*/
		DestroyServProductTemporaryPrimaryIndex();
		
		WriteAlertMsg("建立临时主关键字索引错误");
		return -1;
	}
	ptHead=STAT_SERVPRODUCT.pServIDTrie;
	ioffsetCur=SERVPRODUCT.ioffsetCurData;
	
	while(ioffsetCur!=-1){
		
		pTemp=SERVPRODUCTTRIEEXT(ioffsetCur);
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
	
	if(iNodeCnt!=DestroyServProductTemporaryPrimaryIndex()){
		WriteAlertMsg("删除临时主关键字索引错误");
		return -1;
	}
	return iDeleteCnt;
}

int CountingServProductIncrementRecord()
{
	int iDeleteCnt;
	
	if((iDeleteCnt=CountingServProductCurDeleteRecord())<0) return -1;
	
	/*返回,当前使用空间-淘汰空间+增加空间*/
	return SERVPRODUCT.iCurDataCnt-iDeleteCnt+STAT_SERVPRODUCT.iServProductCnt;	
}

int GetServProductTotalBufRecord()
{
	return SERVPRODUCT.iDataBufLen;
}

/*统计节点数支持函数*/
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

/***用户标识SERV_ID索引****/

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
			
			WriteAlertMsg("统计资料SERV_SERVID索引节点错误");
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
			
		WriteAlertMsg("统计链表服务资料SERVPR_SERVID索引节点错误");
		return -1;
	}
	STAT_SERVPRODUCT.iServIDNodeCnt+=iTempCnt;
	
	DestroyTrie(STAT_SERVPRODUCT.pServIDTrie);
	STAT_SERVPRODUCT.pServIDTrie=NULL;
	
	iTempCnt=STAT_SERVPRODUCT.iServIDNodeCnt;
	
	printf("SERVPRODUCT表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	WriteProcMsg("SERVPRODUCT表所有索引总数%d,占用内存%dM",
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
	
	/*清空索引节点*/
	SERVPRODUCT.ioffsetServID=-1; 
	
	ioffsetPre=-1;
	ioffsetCur=SERVPRODUCT.ioffsetFreeNode;
	while(ioffsetCur!=-1){
		ioffsetPre=ioffsetCur;
		ioffsetCur=SERVPRODUCTTRIENODE(ioffsetPre)->NextOffset;
	}
	if(ioffsetPre==-1)/*空链表直接赋值,否则挂到链表末尾*/
		SERVPRODUCT.ioffsetFreeNode=SERVPRODUCT.ioffsetCurNode;
	else
		SERVPRODUCTTRIENODE(ioffsetPre)->NextOffset=SERVPRODUCT.ioffsetCurNode;
	
	/*清空当前链表,这里不要初始化节点*/
	SERVPRODUCT.ioffsetCurNode=-1;
	SERVPRODUCT.iCurNodeCnt=0;
}

/*必须该为按指定顺序挂入链表*/
static int comp_shm_servproduct_servid(POINTER ioffsetValue,POINTER ioffsetHead)
{
	int res;
	struct IServProductStruct *pSource=SERVPRODUCTTRIEEXT(ioffsetValue);
	struct IServProductStruct *pTarget=SERVPRODUCTTRIEEXT(ioffsetHead);

	if((res=pSource->iProductID-pTarget->iProductID)!=0) return res;
			/*状态倒序保证F0A最后*/
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
		/*插入SERV_ID索引*/
	iTempCnt=InsertTrieE(&SERVPRODUCT.ioffsetServID,pNodeSeg,
		pTemp->sServID,	&(SERVPRODUCT.ioffsetFreeNode),
		&(SERVPRODUCT.ioffsetCurNode),ioffsetNew,
		assign_servproduct_servid);
		
	if(iTempCnt<0){WriteAlertMsg("逻辑错误"); return -1;}
		
	iNodeCnt+=iTempCnt;
		
	return iNodeCnt;		
}

int RebuildServProductShmCurIndexAndRetriveExpireRecord()
{
	int iTempCnt;
	
	POINTER ioffsetCur,ioffsetNew;	
	struct IServProductStruct *pTemp;
	
	/*将当前链表取出,并清空,同时设置数据节点数为0*/
	ioffsetCur=SERVPRODUCT.ioffsetCurData;
	SERVPRODUCT.ioffsetCurData=-1;
	SERVPRODUCT.iCurDataCnt=0;
	
	while(ioffsetCur!=-1){
		
		ioffsetNew=ioffsetCur;
		pTemp=SERVPRODUCTTRIEEXT(ioffsetNew);
		ioffsetCur=pTemp->NextOffset;
		
		/*如果要淘汰的记录,则直接插入数据空闲链表*/
		if(pTemp->cDeleteFlag==DELETE_RECORD){
			
			/*pTemp和SERVTRIEEXT(ioffsetNew)是等效的*/
			pTemp->NextOffset=SERVPRODUCT.ioffsetFreeData;
			SERVPRODUCT.ioffsetFreeData=ioffsetNew;
			continue;
		}
		
		pTemp->ioffsetSAS[0]=-1;
		
		if((iTempCnt=ItemBuildServProductShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		SERVPRODUCT.iCurNodeCnt+=iTempCnt;

		/*将数据再插入到当前内存链表中*/
		pTemp->NextOffset=SERVPRODUCT.ioffsetCurData;
		SERVPRODUCT.ioffsetCurData=ioffsetNew;
		/*统计表话单记录数++*/
		SERVPRODUCT.iCurDataCnt++;
		
	}
	
	return 0;
}


/************增量刷新一组函数完毕****以下为完全刷新支持函数*/

static void mvitem_servproduct(struct ServProductStruct *pi,struct IServProductStruct *po)
{
/*先初始化SERVPRODUCT表的结构*/

	po->ioffsetSAS[0]=-1;
	
	po->cDeleteFlag=STORE_RECORD;

/*数据移动部分*/
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
		if(ioffsetNew==-1) {WriteAlertMsg("逻辑错误"); return -1;}
		
		SERVPRODUCT.ioffsetFreeData=SERVPRODUCTTRIEEXT(ioffsetNew)->NextOffset;
		
		/*将数据移动到内存中*/
		mvitem_servproduct(ptPre,SERVPRODUCTTRIEEXT(ioffsetNew));
		
		if((iTempCnt=ItemBuildServProductShmIndex(ioffsetNew))<0) return -1;
		
		/*统计节点增加*/
		SERVPRODUCT.iCurNodeCnt+=iTempCnt;

		/*将数据再插入到当前内存链表中*/
		SERVPRODUCTTRIEEXT(ioffsetNew)->NextOffset=SERVPRODUCT.ioffsetCurData;
		SERVPRODUCT.ioffsetCurData=ioffsetNew;
		
		/*统计表话单记录数++*/
		SERVPRODUCT.iCurDataCnt++;
	}
	
	return 0;
}

int ServProductSemWorking()
{
	int iSemID;
	
	/*如果指定信号灯不存在,则建立后删除*/
	if((iSemID=semget(SERVPRODUCTSEMKEY,0,0x400|IPC_CREAT|IPC_EXCL))>=0){
		semctl(iSemID,0,IPC_RMID);
		
		printf("建立SERVPRODUCT信号灯异常被删除.\n");
		
		return FALSE;
	}
	if(errno!=EEXIST){
		printf("建立SERVPRODUCT信号灯失败");
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
			
		WriteAlertMsg("统计链表服务资料SERVPRODUCT_SERVID索引错误");
		return -1;
	}
	STAT_SERVPRODUCT.iServIDNodeCnt+=iTempCnt;
	
	iTempCnt=STAT_SERVPRODUCT.iServIDNodeCnt;
	
	printf("SERVPRODUCT表所有索引总数%d,占用内存%dM.\n",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));

	WriteProcMsg("SERVPRODUCT表所有索引总数%d,占用内存%dM",
		iTempCnt,(int)(sizeof(TRIEEXT)*iTempCnt/1024/1024));
	
	return iTempCnt;	
}

int InitServProductControlRecord()
{
	int iErrCode,i;
	
	SERVPRODUCT.ioffsetServID=-1; 
	
	SERVPRODUCT.ioffsetFreeNode=-1;	/*节点空闲链表头指针*/
	SERVPRODUCT.ioffsetFreeData=-1;	/*记录空闲数据指针*/
	
	SERVPRODUCT.ioffsetCurData=-1;	/*记录当前共享中已经存储数据的链表*/
	SERVPRODUCT.ioffsetNewData=-1;	/*记录新增加数据的共享的数据链表*/
	
	SERVPRODUCT.ioffsetCurNode=-1;	/*记录当前共享中已经存储索引的链表*/
	
	SERVPRODUCT.iCurDataCnt=0;	/*当前数据记录数*/
	SERVPRODUCT.iCurNodeCnt=0;	/*当前索引记录数*/
	
	SERVPRODUCT.iDataBufLen=(STAT_SERVPRODUCT.iServProductCnt+1000)*120/100;/*总记录个数*/
	SERVPRODUCT.iNodeBufLen=(STAT_SERVPRODUCT.iServIDNodeCnt+1000)*120/100;	/*总索引节点个数*/
	
	SERVPRODUCT.iLockGrpID=giLockGrpID;	/*内存锁标识*/
	
	strcpy(SERVPRODUCT.sUpdateTime,STAT_SERVPRODUCT.sUpdateTime);/*上次更新时间*/
	
	/*分配共享内存,并初始化*/
	SERVPRODUCT.pHead=(struct ShmServProductHead *)CreateShmInitHead(
		SERVPRODUCTDATAKEY,
		SERVPRODUCT.iDataBufLen*sizeof(struct IServProductStruct)+
		sizeof(struct ShmServProductHead),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存SERVDATE失败");
		return -1;
	}
	
	SERVPRODUCT.pData=(struct IServProductStruct*)(SERVPRODUCT.pHead+1);

	SERVPRODUCT.pNode=(TRIEEXT*)AllocShm(SERVPRODUCTNODEKEY,
		SERVPRODUCT.iNodeBufLen*sizeof(TRIEEXT),&iErrCode);
	if(iErrCode){
		WriteAlertMsg("分配共享内存SERVNODE失败");
		return -1;
	}
	
/*遍历共享内存数据区将所有的节点连接到未用的数据节点链表内*/
	/*结尾指针为-1*/
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
