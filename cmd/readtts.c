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
		printf("�ļ� %s ���ȷǷ� %d,Ҫ�󳤶�Ϊ%d.\n",sSourceName,
			FileSize(sSourceName),
			sizeof(struct FTtscofStruct)*MAX_FILE_SEQ);
		return -1;
	}
/*���ļ����뻺����*/
	if((fp=fopen(sSourceName,"r"))==NULL){
		printf("���ļ�%s��ʧ��.\n",sSourceName);
		return -1;
	}
	fread((void*)&asTts[0],sizeof(struct FTtscofStruct),MAX_FILE_SEQ,fp);
	fclose(fp);
/*���ṹת����ʽ*/
	for(i=1;i<MAX_FILE_SEQ;i++)
		mvitem_tts2tt(&asTts[i],i,&asTt[i]);

/*��ת����Ķ������������ļ���*/
	if((fp=fopen(sTargetName,"w"))==NULL){
		printf("���ļ�%sдʧ��.\n",sTargetName);
		return -1;
	}
/*��һ��ѭ��д�ļ�*/
	for(i=1;i<MAX_FILE_SEQ;i++){

		p=&asTt[i];
		/*ֻȡ������ϴ��ɼ����ļ�*/
		if(strcmp(p->sStatus,"1")==0)
			fprintf(fp,"CF%04d.DAT\t%s\t%04d\n",i,p->sDate,i);
	}
	fclose(fp);
	
	return 0;
}
