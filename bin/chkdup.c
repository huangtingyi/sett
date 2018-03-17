#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwsem.h>
#include <wwshm.h>
#include <list.h>
#include <bintree.h>
#include <trie.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwdb.h>

int ChkDupMain(char sModule[],char sSourceID[],char sSourceName[],
	char sTargetDir[],char msg[]);

int main(int argc,char *argv[])
{
	char msg[512],sAppID[40];
	char sModule[4],sSourceID[7],sSourceName[256],sTargetDir[80];
	
	if(argc!=5){
		printf("Usage %s module sourceid sourcename targetdir.\n",argv[0]);
		return -1;
	}

	strncpy(sModule,argv[1],3);sModule[3]=0;
	strcpy(sSourceID, argv[2]);
	strcpy(sSourceName,argv[3]);
	strcpy(sTargetDir,argv[4]);

	GetBaseName(argv[0],sAppID);
	strcat(sAppID,"_");strcat(sAppID,sModule);
	InitAppRes(sAppID);

	RegularDir(sTargetDir);

	if(IniConnect("dupconnstr")<0){
		WriteAlertPrint("重单检查,连结数据库dupconnstr失败");
		return -1;
	}

	if(ChkDupMain(sModule,sSourceID,sSourceName,sTargetDir,msg)<0){
		WriteAlertPrint("重单检查%s,文件为%s,程序退出",msg,sSourceName);
		RollbackWorkRelease();
		return -1;
	}
	CommitWorkRelease();
	printf("%s\n",msg);
	return 0;
	
}
