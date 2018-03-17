#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwfile.h>
#include "ftam.h"

int main(int argc,char *argv[])
{
	int i;
	FILE *fp;
	char	sSourceName[256],sTargetName[256];
	struct FTtscofStruct	asTts[MAX_FILE_SEQ];
	struct TtcofStruct	*p,asTt[MAX_FILE_SEQ];

	
	if(argc!=3){
		printf("usage %s ttsname targetname\n",argv[0]);
		return -1;
	}
	
	strcpy(sSourceName,argv[1]);
	strcpy(sTargetName,argv[2]);
	
	if(FileSize(sSourceName)!=sizeof(struct FTtscofStruct)*MAX_FILE_SEQ){
		printf("文件 %s 长度非法 %d,要求长度为%d.\n",sSourceName,
			FileSize(sSourceName),
			sizeof(struct FTtscofStruct)*MAX_FILE_SEQ);
		return -1;
	}
/*将文件读入缓冲区*/
	if((fp=fopen(sSourceName,"r"))==NULL){
		printf("打开文件%s读失败.\n",sSourceName);
		return -1;
	}
	fread((void*)&asTts[0],sizeof(struct FTtscofStruct),MAX_FILE_SEQ,fp);
	fclose(fp);
/*将结构转换格式*/
	for(i=1;i<MAX_FILE_SEQ;i++)
		mvitem_tts2tt(&asTts[i],i,&asTt[i]);

/*将转换后的东西输出到输出文件中*/
	if((fp=fopen(sTargetName,"w"))==NULL){
		printf("打开文件%s写失败.\n",sTargetName);
		return -1;
	}
/*做一个循环写文件*/
	for(i=1;i<MAX_FILE_SEQ;i++){

		p=&asTt[i];
		/*只取生成完毕待采集的文件*/
		if(strcmp(p->sStatus,"1")==0)
			fprintf(fp,"CF%04d.DAT\t%s\t%04d\n",i,p->sDate,i);
	}
	fclose(fp);
	
	return 0;
}
