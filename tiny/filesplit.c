#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <bintree.h>
#include <wwdir.h>
#include <wwcoding.h>
#include <ticket_field.h>
#include <param_intf.h>


int main(int argc,char **argv)
{
	char sTargetPath[256],sFileName[256];
	char *p,sOutFileName[256],sBaseName[256];
	int iStartPos,iKeyLen;
	struct FileControlStruct *ptLkHead = NULL;	
	struct SplitStruct *ptHead=NULL,*pTemp=NULL;
	
	if (argc!=5){
		printf("Usage:%s InputFile TargetPath "
			"iStartPos iLength(128Max)\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sTargetPath,argv[2]);
	iStartPos=atoi(argv[3]);
	iKeyLen=atoi(argv[4]);

	if (iStartPos<=0||iKeyLen==0){
		WriteAlertMsg("��ʼ���ȴ���");
		return -1;
	}

	if(IsFile(sFileName)==FALSE){
		WriteAlertMsg("�����ļ�%s��Ч",sFileName);
		return -1;
	}
	
	RegularDir( sTargetPath );
	if(IsDir(sTargetPath)==FALSE){
		WriteAlertMsg("���Ŀ¼%s��Ч",sTargetPath);
		return -1;
	}
	
	GetBaseName(sFileName,sBaseName);
	if((p=strstr(sBaseName,".tmp"))!=NULL)	*p='\0';

	/*�����ļ����ڴ�����*/
	if(TxtFileToList(sFileName,&ptLkHead )<0){
		WriteAlertMsg("�����ļ�%s���ڴ�ʧ��.",sFileName);
		WriteErrStackAlert();
		return -1;
	}
	if(FileControl2SplitList(ptLkHead,iStartPos,iKeyLen,&ptHead)<0){
		WriteAlertMsg("ת������ʧ��");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
	
		sprintf( sOutFileName, "%s%s.%s",
			sTargetPath,sBaseName,pTemp->sKey );	
		if(list2fileln(&(pTemp->pData),sOutFileName) < 0){
			WriteAlertMsg("д����ļ���%s����",sOutFileName);
			continue;
		}
	
		WriteProcPrint("д����ļ� %s �ɹ�",sOutFileName);
	}

	return 0;
	
}

