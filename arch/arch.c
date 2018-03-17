#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "serv.h"
#include "acct.h"
#include "servacct.h"
#include "servproduct.h"

#include <hnixs.h>
#include <wwdb.h>
#include <wwcoding.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <wwsem.h>
#include <interface.h>

/*****资料更新通用过程加载函数指针***/

int (*CheckShmEffect)();
void (*DestroyStatList)();
int (*MountingUpdatedToMem)();
int (*MountingTotalToMem)();
int (*BuildTemporaryPrimaryIndex)();
int (*DestroyTemporaryPrimaryIndex)();
int (*CountingCurDeleteRecord)();
int (*CountingIncrementRecord)();
int (*GetTotalBufRecord)();
int (*CountingIncrementNode)();
int (*GetTotalBufNode)();
int (*LockArchShm)();
void (*UnlockArchShm)();
void (*TruncateShmIndexAndRetriveNode)();
int (*RebuildShmCurIndexAndRetriveExpireRecord)();
int (*BuildMemListIndexAndMoveToShm)();
int (*SemWorking)();
int (*ClientUnmountNotify)();
int (*ClientConnectNotify)();
int (*CountingTotalRecord)();
int (*StatTotalNode)();
int (*InitControlRecord)();
void (*CopyControlToShm)();
int  (*DetachArchShm)();



void InitServSupportInterface();
void InitAcctSupportInterface();
void InitServAcctSupportInterface();
void InitServProductSupportInterface();

int giLockGrpID,giSemKey,giShmDataKey,giShmNodeKey;
int giRespondEvent,giDelayCounter,giAbort,giUpdateResult;
int giRebuildFlag;

extern int errno;


#define LOADSERV	1
#define LOADSERVACCT	2
#define LOADSERVPRODUCT 3
#define LOADACCT	4
#define INCREMENTUPDATE	1
#define WHOLEUPDATE	2


int Usage(int argc,char **argv)
{
	printf("Usage: %s [option]\n",argv[0]);
	printf("       -t|-T n    n 设定的定时时间.\n");
	printf("       -r|-R      清除共享内存和信号量.\n");
	printf("       -l|-L      加载资料参数 serv servacct servproduct acct.\n");
	printf("       -h|-H      帮助.\n");          
	return 0;
}

int IncrementUpdateShmArch()
{
	int iNodeBufLen,iNodeNeed;
	time_t	tBeginLoadTime,tEndLoadTime,tBeginUpdateTime,tEndUpdateTime;

	time(&tBeginLoadTime);

	/**一般该错误是数据库无法连接，故不退出*/
	
	if(MountingUpdatedToMem()<0){
		WriteAlertMsg("加载更新资料参数错误");
		return 0;
	}
	
	printf("加载更新资料参数成功.\n");
	WriteProcMsg("加载更新资料参数成功");
	
/*	if(BuildTemporaryPrimaryIndex()<0){
		pprintf(0,0,"为资料主关键字建立内存索引失败.\n");
		return -1;
	}
*/	
/*	if((iTempCnt=CountingCurDeleteRecord())<0){
		pprintf(0,0,"为共享内存资料统计并删除记录失败.\n");
		return -1;
	}
*/
	/**只要输出异常然后等待刷新过程*/
	iNodeBufLen=GetTotalBufRecord();	
	iNodeNeed=CountingIncrementRecord();
	
	if(iNodeBufLen<iNodeNeed){
		giRebuildFlag=WHOLEUPDATE;
		return 0;
	}
	printf("统计需要索引节点数%d,索引缓冲大小%d.\n",iNodeNeed,iNodeBufLen);
	WriteProcMsg("统计需要索引节点数%d,索引缓冲大小%d",
		iNodeNeed,iNodeBufLen);
	
	if(GetTotalBufNode()<CountingIncrementNode()){
		giRebuildFlag=WHOLEUPDATE;
		return 0;
	}
	
	time(&tEndLoadTime);
	
	LockArchShm();

	pprintf(0,0,"共享内存加锁.........................进程不能退出.\n");
	
	if(ClientUnmountNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS程序没有相应该程序(increase)");
		WriteAlertMsg("共享内存解锁(更新失败)...........进程可退出.");
		return -1;
	}
	
	time(&tBeginUpdateTime);

	pprintf(0,0,"通知其他应用程序脱离用户资料连接成功.\n");
	
	TruncateShmIndexAndRetriveNode();
	pprintf(0,0,"删除共享内存原有索引节点成功.\n");
	
	if(RebuildShmCurIndexAndRetriveExpireRecord()<0){
		UnlockArchShm();
		WriteAlertMsg("为目前共享内存建立索引或删除过期记录错误");
		WriteAlertMsg("共享内存解锁(更新失败)...........进程可退出");
		return -1;
	}
	pprintf(0,0,"为目前共享内存建立索引、删除过期记录成功.\n");
	
	if(BuildMemListIndexAndMoveToShm()<0){
		UnlockArchShm();
		WriteAlertMsg("为本地资料链表建立索引-并移动到共享内存失败");
		WriteAlertMsg("共享内存解锁(更新失败)...........进程可退出");
		return -1;
	}

	DestroyStatList();
	
	CopyControlToShm();
	

	if(ClientConnectNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS程序没有正常启动(increase)");
		WriteAlertMsg("共享内存解锁(更新失败)...........进程可退出");
		return -1;
	}
	
	pprintf(0,0,"通知其他应用程序连接用户资料连接成功.\n");
	UnlockArchShm();
	pprintf(0,0,"共享内存解锁(更新成功)...........进程可退出.\n");

	time(&tEndUpdateTime);

	pprintf(0,0,"资料增量更新完毕,加载用%d秒,更新用%d秒,总用%d秒.\n",
		tEndLoadTime-tBeginLoadTime,
		tEndUpdateTime-tBeginUpdateTime,
		tEndUpdateTime-tBeginLoadTime);

	return 0;
}

int WholeUpdateShmArch()
{
	time_t	tBeginLoadTime,tEndLoadTime,tBeginUpdateTime,tEndUpdateTime;

	time(&tBeginLoadTime);

	if(SemWorking()==FALSE){
		
		if((giLockGrpID=CreateSemX(giSemKey,1))<0){
			/**获取内存锁失败*/
			WriteAlertMsg("获取共享内存锁失败");
			return -1;
		}
		
		giRebuildFlag=WHOLEUPDATE;
		return 0;
	}
	
	if(MountingTotalToMem()<0){
		WriteAlertMsg("完全加载资料参数错误");
		return 0;
	}

	time(&tEndLoadTime);
	
	LockArchShm();
	pprintf(0,0,"共享内存加锁.........................进程不能退出.\n");
	
	if(ClientUnmountNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS程序没有相应该程序");
		return -1;
	}

	time(&tBeginUpdateTime);
	
	pprintf(0,0,"通知其他应用程序脱离用户资料连接成功.\n");
	
	if(StatTotalNode()<0){
		UnlockArchShm();
		WriteAlertMsg("链表索引记录统计错误");
		WriteAlertMsg("共享内存加锁(载入失败)........进程退出");
		return -1;
	}
	pprintf(0,0,"本地链表索引记录统计成功.\n");
	
/*	
	该统计可以不要，因为在加载MOUNTING的时候已经将
	数据记录数放在STAT_ARCH全局结构中了
	if(CountingTotalRecord()<0){
		pprintf(0,0,"链表数据记录统计错误.\n");
		UnlockArchShm();
		pprintf(0,0,"共享内存加锁(载入失败)........进程退出.");
		return -1;
	}
	
*/
	if(InitControlRecord()<0){
		UnlockArchShm();
		WriteAlertMsg("分配共享内存错误");
		WriteAlertMsg("共享内存加锁(载入失败)........进程退出");
		return -1;
	}
	
	pprintf(0,0,"分配并初始化共享内存成功.\n");
	
	if(BuildMemListIndexAndMoveToShm()<0){
		UnlockArchShm();
		WriteAlertMsg("为本地资料链表建立索引-并移动到共享内存失败");
		WriteAlertMsg("共享内存加锁(载入失败)........进程退出");
		return -1;
	}

	DestroyStatList();
	
	pprintf(0,0,"为本地资料链表建立索引-并移动到共享内存成功.\n");
	
	CopyControlToShm();
	
	if(ClientConnectNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS程序没有正常启动");
		WriteAlertMsg("共享内存加锁(载入失败)........进程退出");
		return -1;
	}
	
	pprintf(0,0,"通知其他应用程序连接用户资料连接成功.\n");
	
	UnlockArchShm();
	pprintf(0,0,"共享内存加锁(载入成功)........进程退出.\n");

	time(&tEndUpdateTime);

	pprintf(0,0,"资料完全更新完毕,加载用%d秒,更新用%d秒,总用%d秒.\n",
		tEndLoadTime-tBeginLoadTime,
		tEndUpdateTime-tBeginUpdateTime,
		tEndUpdateTime-tBeginLoadTime);
	
	return 0;
	
}

int main(int argc ,char *argv[])
{
	int iLoadType,iSemID;
        char   sTarget[2048]; 
        time_t	tPreTime,tCurTime;
	
	giRebuildFlag = FALSE;
	
	
	if(ExistOtherOption(argc,argv,"bBrRlLHh?")==TRUE||
		ExistOption(argc,argv,"Hh?")==TRUE){
		Usage(argc, argv);
		return 0;	
	}
	
	if(ExistOption(argc,argv,"rR")==TRUE)	giRebuildFlag = WHOLEUPDATE;
	
	SearchOptionStr(argc,argv,"lL",sTarget);

	printf(">应用程序启动\n");
	ConnectArchDB();
	
	if(strcmp(sTarget,"serv")==0)
		iLoadType=LOADSERV;
	else if(strcmp(sTarget,"servacct")==0)
		iLoadType=LOADSERVACCT;
	else if (strcmp(sTarget,"servproduct")==0)
		iLoadType=LOADSERVPRODUCT;
	else if (strcmp(sTarget,"acct")==0)
		iLoadType=LOADACCT;
	else {
		pprintf(0,0,"参数选项L或l后必须为 serv servacct servproduct或acct.\n");
		/*脱离监控*/
		return 0;
	}
	
	switch ( iLoadType ) {
	
	case LOADSERV:
		InitServSupportInterface();
	break;
		
	case LOADSERVACCT:
		InitServAcctSupportInterface();
	break;
	
	case LOADSERVPRODUCT:
		InitServProductSupportInterface();
	break;
	
	case LOADACCT:
		InitAcctSupportInterface();
	break;
	
	}

	giAbort = FALSE;
	
	while(1){
		

		giRespondEvent=FALSE;
		
		if(CheckShmEffect()!=TRUE||SemWorking()!=TRUE||
			giRebuildFlag==WHOLEUPDATE){
			
			giRebuildFlag = FALSE;	
			FreeShm(giShmDataKey);
			FreeShm(giShmNodeKey);
			if((iSemID=semget(giSemKey,0,0x400|IPC_CREAT|IPC_EXCL))>=0)
				semctl(iSemID,0,IPC_RMID);
				
			giUpdateResult=WholeUpdateShmArch();
		}
		else{
			giRebuildFlag = FALSE;
			giUpdateResult=IncrementUpdateShmArch();
		}

		
		giRespondEvent=TRUE;
		
		/*延迟一小时*/
		giDelayCounter=0;
		
		time(&tPreTime);
		while(giAbort==FALSE){
			
			time(&tCurTime);
			if((tCurTime-tPreTime)>3600||giUpdateResult<0||
				giRebuildFlag!=FALSE) break;
			
			sleep(60);
			
			giDelayCounter++;
		}

#ifdef QHJF
		if(DetachArchShm()<0){
			WriteAlertMsg("脱离共享内存失败x,程序退出");
			exit(1);
		}
#endif
		
		if(giAbort==TRUE||giUpdateResult<0) break;
		
			
	}
	
	if(giUpdateResult<0){
		WriteAlertMsg("刷新共享内存错误，程序退出");
	}
	else{
		WriteAlertMsg("接收到退出命令，程序退出");
	}
		/*脱离监控*/
	return 0;
} 

int OnIncrementUpdateArch()
{
	
	if(giRespondEvent==TRUE)		
		giRebuildFlag=INCREMENTUPDATE;
	else
		WriteAlertMsg("正在更新命令过程中，不需要刷新");
		
	return 0;
}
int OnWholeUpdateArch()
{
	
	if(giRespondEvent==TRUE)
		giRebuildFlag=WHOLEUPDATE;
	else
		WriteAlertMsg("正在更新命令过程中，不需要重建");
	
	return 0;
}
int OnShutDownArch()
{
	giAbort = TRUE;
	return 0;
}
void InitServSupportInterface()
{
	
	giShmDataKey=SERVDATAKEY;
	giShmNodeKey=SERVNODEKEY;
	giSemKey=SERVSEMKEY;
		
	CheckShmEffect=				CheckShmServEffect;
	DestroyStatList=                        DestroyServStatList;
	MountingUpdatedToMem=                   MountingUpdatedServToMem;
	MountingTotalToMem=                     MountingTotalServToMem;
	BuildTemporaryPrimaryIndex=             BuildServTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=       	DestroyServTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingServCurDeleteRecord;
	CountingIncrementRecord=                CountingServIncrementRecord;
	GetTotalBufRecord=                      GetServTotalBufRecord;
	CountingIncrementNode=                  CountingServIncrementNode;
	GetTotalBufNode=                        GetServTotalBufNode;
	LockArchShm=                            LockServShm;
	UnlockArchShm=                          UnlockServShm;
	TruncateShmIndexAndRetriveNode=         TruncateServShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildServShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=           BuildServMemListIndexAndMoveToShm;
	SemWorking=                             ServSemWorking;
	ClientUnmountNotify=                    ClientServUnmountNotify;
	ClientConnectNotify=                    ClientServConnectNotify;
	CountingTotalRecord=                    CountingServTotalRecord;
	StatTotalNode=                      StatServTotalNode;
	InitControlRecord=                      InitServControlRecord;
	CopyControlToShm=                       CopyServControlToShm;
	DetachArchShm=				DetachShmServ;
}

void InitServAcctSupportInterface()
{
	giShmDataKey=SERVACCTDATAKEY;
	giShmNodeKey=SERVACCTNODEKEY;
	giSemKey=SERVACCTSEMKEY;
		
	CheckShmEffect=				CheckShmServAcctEffect;
	DestroyStatList=                        DestroyServAcctStatList;
	MountingUpdatedToMem=                   MountingUpdatedServAcctToMem;
	MountingTotalToMem=                     MountingTotalServAcctToMem;
	BuildTemporaryPrimaryIndex=             BuildServAcctTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=       	DestroyServAcctTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingServAcctCurDeleteRecord;
	CountingIncrementRecord=                CountingServAcctIncrementRecord;
	GetTotalBufRecord=                      GetServAcctTotalBufRecord;
	CountingIncrementNode=                  CountingServAcctIncrementNode;
	GetTotalBufNode=                        GetServAcctTotalBufNode;
	LockArchShm=                            LockServAcctShm;
	UnlockArchShm=                          UnlockServAcctShm;
	TruncateShmIndexAndRetriveNode=         TruncateServAcctShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildServAcctShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=          BuildServAcctMemListIndexAndMoveToShm;
	SemWorking=                             ServAcctSemWorking;
	ClientUnmountNotify=                    ClientServAcctUnmountNotify;
	ClientConnectNotify=                    ClientServAcctConnectNotify;
	CountingTotalRecord=                    CountingServAcctTotalRecord;
	StatTotalNode=                      StatServAcctTotalNode;
	InitControlRecord=                      InitServAcctControlRecord;
	CopyControlToShm=                       CopyServAcctControlToShm;
	DetachArchShm=				DetachShmServAcct;
}

void InitServProductSupportInterface()
{
	giShmDataKey=SERVPRODUCTDATAKEY;
	giShmNodeKey=SERVPRODUCTNODEKEY;
	giSemKey=SERVPRODUCTSEMKEY;
		
		
	CheckShmEffect=				CheckShmServProductEffect;
	DestroyStatList=                        DestroyServProductStatList;
	MountingUpdatedToMem=                   MountingUpdatedServProductToMem;
	MountingTotalToMem=                     MountingTotalServProductToMem;
	BuildTemporaryPrimaryIndex=             BuildServProductTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=       	DestroyServProductTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingServProductCurDeleteRecord;
	CountingIncrementRecord=                CountingServProductIncrementRecord;
	GetTotalBufRecord=                      GetServProductTotalBufRecord;
	CountingIncrementNode=                  CountingServProductIncrementNode;
	GetTotalBufNode=                        GetServProductTotalBufNode;
	LockArchShm=                            LockServProductShm;
	UnlockArchShm=                          UnlockServProductShm;
	TruncateShmIndexAndRetriveNode=         TruncateServProductShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildServProductShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=           BuildServProductMemListIndexAndMoveToShm;
	SemWorking=                             ServProductSemWorking;
	ClientUnmountNotify=                    ClientServProductUnmountNotify;
	ClientConnectNotify=                    ClientServProductConnectNotify;
	CountingTotalRecord=                    CountingServProductTotalRecord;
	StatTotalNode=                      StatServProductTotalNode;
	InitControlRecord=                      InitServProductControlRecord;
	CopyControlToShm=                       CopyServProductControlToShm;
	DetachArchShm=				DetachShmServProduct;
}

void InitAcctSupportInterface()
{
	giShmDataKey=ACCTDATAKEY;
	giShmNodeKey=ACCTNODEKEY;
	giSemKey=ACCTSEMKEY;
		
	CheckShmEffect=				CheckShmAcctEffect;
	DestroyStatList=                        DestroyAcctStatList;
	MountingUpdatedToMem=                   MountingUpdatedAcctToMem;
	MountingTotalToMem=                     MountingTotalAcctToMem;
	BuildTemporaryPrimaryIndex=             BuildAcctTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=           DestroyAcctTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingAcctCurDeleteRecord;
	CountingIncrementRecord=                CountingAcctIncrementRecord;
	GetTotalBufRecord=                      GetAcctTotalBufRecord;
	CountingIncrementNode=                  CountingAcctIncrementNode;
	GetTotalBufNode=                        GetAcctTotalBufNode;
	LockArchShm=                            LockAcctShm;
	UnlockArchShm=                          UnlockAcctShm;
	TruncateShmIndexAndRetriveNode=         TruncateAcctShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildAcctShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=           BuildAcctMemListIndexAndMoveToShm;
	SemWorking=                             AcctSemWorking;
	ClientUnmountNotify=                    ClientAcctUnmountNotify;
	ClientConnectNotify=                    ClientAcctConnectNotify;
	CountingTotalRecord=                    CountingAcctTotalRecord;
	StatTotalNode=                      StatAcctTotalNode;
	InitControlRecord=                      InitAcctControlRecord;
	CopyControlToShm=                       CopyAcctControlToShm;
	DetachArchShm=				DetachShmAcct;
}



/*

一、刷新过程:

0.(在检测时做了)获取共享内存内数据 ---不在CHECK内得到,要检测UPDATE_TIME的合法性
	RetrieveControlFromShm();
1.加载数据到本地链表(不加载指定条件的数据)。	
	MountingUpdatedToMem();	
	MountingToMem();
2 建立临时主关键字索引
	BuildTemporaryPrimaryIndex();
	
3 统计ioffsetCurData上与链表内主关键字相同的记录数,
	和指定条件的数据,设置标识(cDeleteFlag)。 	
	CountingCurDeleteRecord(数据库系统时间)

4 统计的到的总记录数如果大于总数据空间大小,则重建空间.(链表记录+统计的记录)			
	CountingIncrementRecord();
	GetTotalBufRecord();
																									
5 统计ioffsetCurData和LIST内的需要的索引NODE记录,如果大于iNodeBufLen,则重新建空间.		
	CountingIncrementNode();
	DestroyCountingNodeIndex();

6 加锁											
	LockArchShm();
6.5.通知断开连接资料
	ClientUnmountNotify();
	失败则解锁离开,提示请启动CMS.
	UnlockArchShm();
		
7 清空当前ioffsetCurNode索引,并将索引节点挂在ioffsetFreeNode中.				
	TruncateShmIndexAndRetriveNode();

8 遍历ioffsetCurData,将不在i本地链表中的数据节点插入到索引树中(指定标识的数据节点),		
	RebuildShmCurIndexAndRetriveExpireRecord();
	A)将满足一定条件的内存直接挂入ioffsetFreeData.

9 遍历本地链表,将数据移动到ioffsetFreeData并插入到ioffsetCurData,同时建立索引.		
	BuildMemListIndexAndMoveToShm();

10.拷贝控制结构到共享内存.				
	CopyControlToShm();
10.5通知连接资料
	ClientConnectNotify();
11 解锁	
	UnlockArchShm();


----注意插入索引时,按照指定的顺序排序

二、建立过程.

1 锁不存;用指定KEY,GET一下如果失败,	则建立该锁,调用重建过程.
	SemWorking();

2.加载数据到本地链表(不加载指定条件的数据)。		
	MountingTotalToMem();	
	MountingToMem();
	
3. 加锁							
	LockArchShm();

4.通知断开连接资料
	ClientUnmountNotify();
	失败则解锁离开,提示请启动CMS.
	UnlockArchShm();
		
5.统计的到的总记录数如果大于总数据空间大小,则重建空间.(链表记录)
	----直接取MountingToMem();的结果
6.统计链表内需要的NODE节点大小.	
	StatTotalNode();
7.初始化需要的控制结构、初始化ioffsetFreeData和ioffsetFreeNode表.
	InitControlRecord();
8.遍历本地链表,将数据移动到ioffsetFreeData并插入到ioffsetCurData,同时建立索引. ====
	BuildMemListIndexAndMoveToShm();
9.拷贝控制结构到共享内存.				
	CopyControlToShm();
10.通知连接资料
	ClientConnectNotify();
11.失败则解锁离开,提示请启动CMS.
	UnlockArchShm();
	
12.解锁


三、主过程

	循环:
	while(1){
		
		接收命令标识=FALSE;
		
		(检测锁存在及共享内存存在?) 
			if(CheckShmServEffect()==TRUE&&SemWorking()==TRUE)
		存在:刷新过程;
		否则:建立过程;
		
		脱离共享内存	HP问题.
		
		接收命令标识=TRUE;
		等待1小时
		if(如果退出标识==TRUE)
			break;
	}
	
	消息一:刷新命令
		如果(接收命令标识==TRUE);
			接收命令标识=FALSE;
			刷新过程;
			接收命令标识=TRUE;
		否则:
			响应不可刷新命令;
	消息二:重建命令
		如果(接收命令标识==TRUE);
			接收命令标识=FALSE;
			重建过程;
			接收命令标识=TRUE;
		否则:
			响应不可重建命令;
	消息二:退出命令
		设置退出标识 =TRUE;
*/
