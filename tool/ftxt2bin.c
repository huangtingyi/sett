#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <hnixs.h>
#include <wwcoding.h>
#include <wwtiny.h>
#include <wwfile.h>

int main(int argc,char *argv[])
{
	int lPre=0,lCur=0,iRecCnt=0,iCnt=0;
	char sSourceName[256],sTargetName[256],sInput[4096],sOutput[1024];
	struct FileControlStruct *ptHead=NULL,*ptLkHead=NULL,*pTemp,*pList=NULL;
	
        if(argc!=3){
                printf("Usage: %s sourcename targetname.\n",argv[0]);
                return -1;
        }

	strcpy(sSourceName,argv[1]);
	strcpy(sTargetName,argv[2]);
	
	if(TxtFileToList(sSourceName,&ptLkHead)<0){
		printf("�ļ�%s���ص��ڴ����.\n",sSourceName);
		return -1;
	}

	ptHead=ptLkHead;
	while(ptHead!=NULL){

		iRecCnt++;
		iCnt++;

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(pTemp->iLen>sizeof(sInput)){
			printf("��%d����¼����������%d�ֽ�,Ϊ%d.\n",
				iRecCnt,sizeof(sInput),pTemp->iLen);
			return -1;
		}
		
		strncpy(sInput,(char*)pTemp->pData,pTemp->iLen);
		sInput[pTemp->iLen]=0;
		AllTrim(sInput);
		
		free(pTemp);

		if(!IsAllHex(sInput)){
			printf("��%d����¼���Ϸ����ı���ϢӦΪ16��������ʵ��Ϊ\n%s\n",
				iRecCnt,sInput);
			return -1;
		}

		lCur=asc_hex2hbcd(sInput,(unsigned char*)sOutput);
		if(lPre==0)lPre=lCur;
		
		if(lCur!=lPre){
			printf("��%d����¼���Ȳ��Ϸ���Ӧ��Ϊ%d��,ʵ��Ϊ%d����ʵ��Ϊ\n%s\n",
				iRecCnt,lPre,lCur,sInput);
			return -1;
		}
		
		if(item2list(&pList,(void*)sOutput,lCur)<0){
			printf("����FileControl�б����.\n");
			return -1;
		}
	}
	
	ReverseList((LIST**)&pList);
	
	if(list2file(&pList,sTargetName)<0){
		printf("д�ļ�%sʧ��.\n",sTargetName);
		return -1;
	}
	printf("�ɹ���%s�ļ�ת��Ϊ%s�ļ�",sSourceName,sTargetName);

	return 0;
}

