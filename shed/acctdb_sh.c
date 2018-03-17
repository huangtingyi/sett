#include <stdio.h>
#include <stdlib.h>

#include <wwcoding.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>

#include <param_intf.h>

#include "appsupp.h"
#include "stt_ticket.h"
#include "acct_supp.h"

int main( int argc, char **argv )
{
	int iGroupID;
	char sFileName[256];
	struct AcctParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc!=3){
		printf("Usage %s shm|acctdb.ini|flowxxxx GroupID.\n",argv[0]);
		return -1;
	}	
	
	InitAppRes("acctdb.sh");

	strcpy(sFileName,argv[1]);
	iGroupID = atoi(argv[2]);
	
	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*共共享内存中获取必要的参数*/
	MoveAllShmToMem();

/*将需要处理的参数获取到 链表中*/
	if(GetAcctParamList(sFileName,iGroupID,&ptHead)<0) return -1;

	if(ConnectDataDB()<0){
		printALERT("连结数据库失败");
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(IsDir(pTemp->sSourcePath)==false){
		        printALERT("输入路径%s无效",pTemp->sSourcePath);
		        return -1;
		}
	/*如果备份目录为空，作为不备份处理*/
		if(IsDir(pTemp->sBackPath)==false&&
			strcmp(pTemp->sBackPath,"")!=0){
		        printALERT("备份路径%s无效",pTemp->sBackPath);
		        return -1;
		}

		if(AcctDBMain(pTemp->sSourceID,pTemp->sSourcePath,
			pTemp->sFileType,pTemp->sFilter,pTemp->sBackPath,
			pTemp->sModule,pTemp->sBelongCode,"SETT_ITEM",
			pTemp->sDateRule,pTemp->sOperType,pTemp->sAppID,
			pTemp->iTacheID)<0){
			printALERT("处理路径%s失败.",pTemp->sSourcePath);
			continue;
		}
				
		if(WantQuit()==true)break;
	}
	
	DestroyList((LIST*)ptLkHead);

	DistroyAllMem();

	DisconnectDatabase();
	
	return 0;
}

