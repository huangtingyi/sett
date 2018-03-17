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

#include "stt_ticket.h"
#include "acct_supp.h"

int main(int argc, char **argv)
{
	int	iTacheID;
	char	sSourceID[31],sBelongCode[10],sSourcePath[128],sBackPath[128];
	char	sModule[10],sOperType[10],sFileType[10],sFilter[128];
	char	sItemTableName[60],sDateRule[13],sAppID[20],sTemp[10];

	if(argc!=13){
		printf("Usage %s sSourceID sSourcePath sFileType \
sFilter sBackPath sModule sBelongCode sItemTableName sDateRule \
sOperType sAppID iTacheID.\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	
	strcpy(sSourceID      ,argv[1]);
	strcpy(sSourcePath    ,argv[2]);
	strcpy(sFileType      ,argv[3]);
	strcpy(sFilter        ,argv[4]);
	strcpy(sBackPath      ,argv[5]);
	strcpy(sModule        ,argv[6]);
	strcpy(sBelongCode    ,argv[7]);
	strcpy(sItemTableName ,argv[8]);
	strcpy(sDateRule      ,argv[9]);sDateRule[12]=0;
	strcpy(sOperType      ,argv[10]);sOperType[3]=0;	TrimAll(sOperType);
	strcpy(sAppID         ,argv[11]);
	strcpy(sTemp       ,argv[12]);iTacheID=atoi(sTemp);
	

	RegularDir(sSourcePath);
	RegularDir(sBackPath);

	if(IsDir(sSourcePath)==false){
	        WriteAlertMsg("输入路径%s无效",sSourcePath);
	        return -1;
	}
/*如果备份目录为空，作为不备份处理*/
	if(IsDir(sBackPath)==false&&
		strcmp(sBackPath,"")!=0){
	        WriteAlertMsg("备份路径%s无效",sBackPath);
	        return -1;
	}

/**连接数据库***/	
	if(IniConnect("dataconnstr")<0) return -1;

/*共共享内存中获取必要的参数*/
	MoveAllShmToMem();

	if(AcctDBMain(sSourceID,sSourcePath,sFileType,sFilter,sBackPath,
		sModule,sBelongCode,sItemTableName,sDateRule,sOperType,
		sAppID,	iTacheID)<0){
		WriteAlertMsg("处理路径%s铁败.",sSourcePath);
	}

	DistroyAllMem();

	printf("累帐程序成功.\n");
	
	DisconnectDatabase();
	
	return 0;
}
