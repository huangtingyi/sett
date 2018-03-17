#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <wwdb.h>

int main(int argc,char *argv[])
{
	int i;
	char sFileName[256],sTargetName[256];
	char sSourceID[20],sSplit[20],sModule[10],sPrefix[30];
	char sErrPath[256],sNormalPath[256],sCommand[1024];
	struct TinySplitStruct *pTinySplit=NULL,*ptPre,*ptCur;

	if(argc!=8){
		printf("usage %s sourceid,fileName split ndir edir module prefix.\n",argv[0]);
		return -1;
	}
	
	strcpy(sSourceID,argv[1]);
	strcpy(sFileName,argv[2]);
	strcpy(sSplit,argv[3]);
	strcpy(sNormalPath,argv[4]);
	strcpy(sErrPath,argv[5]);
	strcpy(sModule,argv[6]);
	strcpy(sPrefix,argv[7]);sPrefix[19]=0;
	RightPad(sPrefix,19,'0');
	
	AllTrim(sFileName);
	AllTrim(sSplit);
	AllTrim(sNormalPath);
	AllTrim(sErrPath);
	AllTrim(sModule);
	AllTrim(sPrefix);
	/*���Ŀ¼�Ƿ���Ч����Ч��������*/
	CheckDir(sNormalPath);
	
	/*��ȡ�����ļ�*/
	if(InitTinySplitList(sSourceID,sFileName,&pTinySplit)<0) return -1;

/*�޸������ļ�������ʽ�ļ���*/
	for(i=0;i<strlen(sSplit);i++){

		if(sSplit[i]=='a'){
			sprintf(sTargetName,"%s%s.%s.BIL.%c",sErrPath,
				sPrefix,sModule,sSplit[i]);
			sprintf(sCommand,"mv %s%s.%c.tmp %s",sErrPath,
				sFileName,sSplit[i],sTargetName);
/*���ⲻͬĿ¼����ͬ�ļ���,���������ͬһ��Ŀ¼,���ļ�����ͻ�Ĵ���,���ﲻ����쳣*/
			system(sCommand);
			continue;
		}
		
		if(SearchTinySplit(pTinySplit,sSplit[i])==FOUND){
			ptCur=pTinySplit;
			while(ptCur!=NULL){
				ptPre=ptCur;
				ptCur=ptCur->pNext;
				if(sSplit[i]!=ptPre->sSplitType[0]) continue;
				
				sprintf(sTargetName,"%s%s.%s.BIL.%c.%s",
					sNormalPath,sPrefix,sModule,sSplit[i],ptPre->sKey);
				sprintf(sCommand,"mv %s%s.%c.%s.tmp %s",sNormalPath,
					sFileName,sSplit[i],ptPre->sKey,sTargetName);
				if(system(sCommand)!=0){
					printf("ִ��%sʧ��",sCommand);
					return -1;
				}
			}
		}
		else{
			sprintf(sTargetName,"%s%s.%s.BIL.%c",sNormalPath,
				sPrefix,sModule,sSplit[i]);

			sprintf(sCommand,"mv %s%s.%c.tmp %s",sNormalPath,
				sFileName,sSplit[i],sTargetName);
			if(system(sCommand)!=0){
				printf("ִ��%sʧ��",sCommand);
				return -1;
			}
		}	
	}
	
	DestroyList((LIST*)pTinySplit);
	RemoveFileSplit(sSourceID,sFileName);
	
	return 0;
}

