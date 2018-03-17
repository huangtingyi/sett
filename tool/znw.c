#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


int main(int argc,char *argv[])
{
	int iCnt=0;
	FILE *fpIn,*fpOut;
	char *pc,sFileName[256],sTargetName[256],sRec[8192];

	if(argc!=2){
		printf("Usage %s file\n",argv[0]);
		return -1;
	}
	strcpy(sFileName,argv[1]);
	sprintf(sTargetName,"%s.tmp",sFileName);

	if((fpIn=fopen(sFileName,"r"))==NULL) return -1;
	if((fpOut=fopen(sTargetName,"w"))==NULL) return -1;

	while(!feof(fpIn)){
		fgets(sRec,8192,fpIn);
		if(feof(fpIn)) break;
		
		if((pc=strchr(sRec,'|'))==NULL) continue;

		fprintf(fpOut,"%d%s",++iCnt,pc);

	}
	fclose(fpIn);
	fclose(fpOut);
	
	return 0;
}
