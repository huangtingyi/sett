#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <dbsupp.h>


/*生成目标文件*/
int main(int argc,char *argv[])
{
	int iMaxDelayMin,iDelayMin,iDelaySec;
	char	sSourceID[10],sTempDate[15];
	
	if(argc !=3 ){
		printf("Usage %s sourceid delaymin\n",argv[0]);
		return -1;		
	}
/*初始化参数部分*/
	strcpy(sSourceID,argv[1]);
	iMaxDelayMin=atoi(argv[2]);

	if(IniConnect("dataconnstr")<0){
		printf("无法连接数据库.\n");
		return -1;
	}
	GetPickLogDelay(sSourceID,sTempDate,&iDelaySec);
	
	iDelayMin=iDelaySec/60;
	
	DisconnectDatabase();
	
	if(sTempDate[0]=='0'||iDelayMin<iMaxDelayMin) return 0;
	 
	printf("采集已经停止运行%d小时%d分钟,最近采集时间%s.\n",
		iDelayMin/60,iDelayMin%60,sTempDate);
			
	return 0;
}

