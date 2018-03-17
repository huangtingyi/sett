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
	
/*拿到COMM_SEARCH的两张表*/
	if(SearchMemTable(pList,"COMM_SEARCH_BIN",&pbMem)!=FOUND){
		WriteAlertPrint("程序逻辑错误，系统应注册COMM_SEARCH_BIN表.");
		return -1;
	}
	if(SearchMemTable(pList,"COMM_SEARCH_TRIE",&ptMem)!=FOUND){
		WriteAlertPrint("程序逻辑错误，系统应注册COMM_SEARCH_TRIE表.");
		return -1;
	}
	bzero((void*)pc,sizeof(struct ShmCscStruct));
	pc->iofftRoot=pc->ioffbRoot=-1;
	
/*计算内存大小*/
	if(CalcCommSearchBin(pbMem,&(pc->ibCnt),&(pc->isCnt),&(pc->imCnt),
		&(pc->ilCnt))<0){
		WriteAlertPrint("计算COMM_SEARCH_BIN需要的节点数失败.");
		return -1;
	}
	pc->bBytes=pc->isCnt*S_COMM_SEARCH_LEN+pc->imCnt*M_COMM_SEARCH_LEN+
		pc->ilCnt*L_COMM_SEARCH_LEN;
		
	if(CalcCommSearchTrie(ptMem,&(pc->itCnt),&(pc->isCnt),&(pc->imCnt),
		&(pc->ilCnt))<0){
		WriteAlertPrint("计算COMM_SEARCH_TRIE需要的节点数失败.");
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
		printf("注册函数失败.\n");
		return -1;
	}
	if(DataToMemTable(pShmRegList,&pMemTableList)<0){
		printf("加载参数表到本地内存失败.\n");
		return -1;
	}

	WriteProcPrint("所有数据加载到本地内存.");
	
	if(InitMemCsc(pMemTableList,&CSC)<0) return -1;

	WriteProcPrint("计算CSC内存结构完毕.");

	SHM_PCB_KEY=GetPcbKey();
	if((SEM_PCB_ID=AttachSem(SHM_PCB_KEY))<0){
		if((SEM_PCB_ID=CreateSem(SHM_PCB_KEY,1))<0){
			WriteAlertPrint("建立共享内存锁%d失败.",SHM_PCB_KEY);
			return -1;
		}
	}
	
	/*为了避免在等待20秒param_supp进程被杀掉的死锁，用LockSafe*/
	LockSafe(SEM_PCB_ID,0);
	/*为了使大多数实时进程和参数刷新主任务冲突，这里等待20秒*/
	sleep(20);
	UnlockSafe(SEM_PCB_ID,0);
	
	/*在实际对共享内存数据结构更新时不能用LockSafe,因为共享内存更新过程
	中的数据的引用是不安全的，宁可死锁也不能造成数据引用错误*/
	Lock(SEM_PCB_ID,0);
	if((PSHM=AttachShm(SHM_PCB_KEY,&iErrCode,NULL))==NULL){
		/*建立共享内存初始结构,并使PSHM指向共享内存*/
		if(BuildShmInit(pMemTableList,&CSC)<0){
			WriteAlertPrint("初始化共享内存失败.");
			Unlock(SEM_PCB_ID,0);
			return -1;
		}
	}
	
	if(MemTableToShm(pMemTableList,&CSC)<0){

		/*可能是参数数据增加太多，必须重新构建共享内存*/
		DetachShm(PSHM);PSHM=NULL;
		DestroyShm(SHM_PCB_KEY);
		/*建立共享内存初始结构,并使PSHM指向共享内存*/
		if(BuildShmInit(pMemTableList,&CSC)<0){
			WriteAlertPrint("初始化共享内存失败.");
			Unlock(SEM_PCB_ID,0);
			return -1;
		}
		if(MemTableToShm(pMemTableList,&CSC)<0){
			WriteAlertPrint("参数加载到共享内存失败.");
			return -1;
			Unlock(SEM_PCB_ID,0);
		}
	}

	Unlock(SEM_PCB_ID,0);
	
	DetachShm(PSHM);PSHM=NULL;

	DisconnectDatabase();
	
	WriteProcPrint("刷新共享内存参数成功.");
	
	return 0;
}
