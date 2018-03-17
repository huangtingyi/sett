#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE *fp = NULL;
	int iMaxSeq=0,iCurSeq =0,i;
	char sSeq[100],sBuffer[1024],sFileName[256];

	
	if(argc!=2){
		printf("Usage %s SeqFileName\n",argv[0]);
		return -1;
	}

	bzero(sSeq,sizeof(sSeq));

	strncpy(sFileName,argv[1],255);sFileName[255]=0;
	
	if((fp=fopen(sFileName,"r"))==NULL){
		perror("打开文件错误");
		return -1;
	}

	while(fgets(sBuffer,1024,fp)!=NULL){

		if(strlen(sBuffer)==1)continue;/*just \n*/

		iCurSeq = atoi(sBuffer);

		if(iCurSeq>0&&iCurSeq<=100){
			if(iCurSeq>iMaxSeq)iMaxSeq=iCurSeq;
			sSeq[iCurSeq]='1';
		}
	}
	
	/*输出*/
	for(i=1;i<=iMaxSeq;i++){
		if(sSeq[i]==0)
			printf("%03d\n",i);
	}
	
	fclose(fp);
	return 0;
}
