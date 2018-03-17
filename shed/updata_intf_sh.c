#include <stdio.h>
#include <stdlib.h>

#include <wwcoding.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwdb.h>
#include <dbsupp.h>

#include <param_intf.h>

#include "appsupp.h"
#include "stt_ticket.h"

char UPDATAINTF[256];
int InitUpdataIntfCtl();

int InitUpdataIntfCtl()
{
	char sPath[256];

	GetBillHome(sPath);
	
	sprintf(UPDATAINTF,"%sbin/updata_intf",sPath);
	
	if(IsFile(UPDATAINTF)==FALSE){
		printf("输入文件%s无效.\n",UPDATAINTF);
		return -1;
	}
	return 0;
}


int main( int argc, char **argv )
{
	int iGroupID;
	char sFileName[256],sCommand[1024],sLine[1024];
	struct IntfParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc!=3){
		printf("Usage %s shm|updata_intf.ini|flowxxxx GroupID.\n",argv[0]);
		return -1;
	}	
	
	InitAppRes("updata_intf.sh");

	strcpy(sFileName,argv[1]);
	iGroupID = atoi(argv[2]);
	
	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*初始化UPDATA_INTF应用位置*/
	if(InitUpdataIntfCtl()<0) return -1;

/*将需要处理的参数获取到 链表中*/
	if(GetIntfParamList(sFileName,iGroupID,&ptHead)<0) return -1;


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
		if(IsDir(pTemp->sNormalPath)==false){
		        printALERT("输入路径%s无效",pTemp->sNormalPath);
		        return -1;
		}

	/*调用updata_intf程序*/
		sprintf(sCommand,"%s %s %s %s %s %s \"%s\" %d %s %s %d",
			UPDATAINTF,pTemp->sFileType,pTemp->sSourcePath,
			pTemp->sBackPath,pTemp->sNormalPath,pTemp->sNormalPath,
			pTemp->sFilter,pTemp->iDelay,pTemp->sCityCode,
			pTemp->sAppID,pTemp->iTacheID);
		if(exec2str(sCommand,sLine)!=0){
	
			printALERT("执行命令 %s 失败",sCommand);
			return -1;
		}		
		if(WantQuit()==true){
			WriteProcMsg("接收到退出信号，程序退出");
			break;
		}
		printNORMAL("成功处理目录 %s 输出 %s",pTemp->sSourcePath,sLine);
	}
	
	DestroyList((LIST*)ptLkHead);
	
	return 0;
}

