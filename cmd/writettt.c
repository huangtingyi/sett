#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwtiny.h>
#include <wwfile.h>
#include "ftam.h"

int main(int argc,char *argv[])
{
	FILE *fp;
	int iSeq;
	char	sDate[15],sTargetName[256];
	struct TtcofStruct Temp;
	struct FTttcofStruct FTtt;
	
	
	if(argc!=4){
		printf("usage %s seq createdate tttfile.\n",argv[0]);
		return -1;
	}
	
	iSeq=atoi(argv[1]);
	strncpy(sDate,argv[2],14);sDate[14]=0;
	strcpy(sTargetName,argv[3]);

/*检查参数合法性*/
	if(iSeq<1||iSeq>=MAX_FILE_SEQ){
		printf("seq=%d 数值必须在%d和%d之间.\n",iSeq,1,MAX_FILE_SEQ);
		return -1;
	}
	if(tGetTime(sDate)<0){
		printf("date=%s 必须是一个合法日期yyyymmddhh24miss.\n",sDate);
		return -1;
	}
	if(FileSize(sTargetName)!=sizeof(struct FTttcofStruct)*MAX_FILE_SEQ){
		printf("文件%s字节数为%d,应该字节数为%d.\n",
			sTargetName,FileSize(sTargetName),
			sizeof(struct FTttcofStruct)*MAX_FILE_SEQ);
		return -1;
	}
/**固定填写交换机生成文件3分钟后做为采集时间*/
	AddMinutes(sDate,3);

/*定将参数转换为指定格式*/
	Temp.iSeq=	iSeq;
	strcpy(Temp.sStatus,"2");
	strcpy(Temp.sDate,sDate);
	mvitem_tt2ttt(&Temp,&FTtt);
	
/*打开文件并定位到指定位置*/
	if((fp=fopen(sTargetName,"r+"))==NULL){
		printf("打开文件%s追加写失败.\n",sTargetName);
		return -1;
	}
	if(fseek(fp,iSeq*sizeof(struct FTttcofStruct),SEEK_SET)==-1){
		printf("定位文件%s失败,pos=%d.\n",sTargetName,
			iSeq*sizeof(struct FTttcofStruct));
		fclose(fp);
		return -1;
	}
	if(fwrite((void*)&FTtt,sizeof(struct FTttcofStruct),1,fp)!=1){
		printf("写文件%s失败.\n",sTargetName);
		return -1;
	}
	fclose(fp);
	return 0;
}

