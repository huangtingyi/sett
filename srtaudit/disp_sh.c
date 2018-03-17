#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <param_intf.h>

int ProcessMain( struct DispParamStruct *pParam,char sType[])
{
	int l=0;
	int iCnt=0;
	char sFileName[256],sTempName[256];
	char sCommand[10240],sRCommand[10240];
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;

/*����һ���ļ��б�*/
	if(dir2list(pParam->sSourcePath,pParam->sFilter,&ptHead)<0){
		printALERT("�����ļ��б�ʧ�� %s %s",
			pParam->sSourcePath,pParam->sFilter);
		return -1;
	}

	ptLkHead=ptHead;

	/*�ƶ��ļ�*/
	while( ptHead != NULL ){

		pTemp = ptHead;
		ptHead = ptHead->pNext;

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		
		
		/*sprintf(sTempName,"%s.tmp",sFileName);
		if((iCnt=InsertTicket(sTempName,sTableName,sType))<0){
			printALERT("�Ա�%s ����ļ�%sʧ��",sTableName,sFileName);
			return -1;
		}*/
		iCnt++;
		printNORMAL("���ļ�%s�ַ��ɹ�",sTempName);
	}
	listfree(&ptLkHead);
	return 0;
}
int MyChkDir(char sPath[])
{
	if(strcmp(sPath,"/nil/")==0) return -1;
	return CheckDir(sPath);
}
int main( int argc, char **argv )
{
	int iRet,iGroupID;
	char sFileName[256],sType[3];
	struct DispParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;

	if(argc!=4){
		printf("Usage %s disp.ini GroupID Type.\n",argv[0]);
		return -1;
	}

	InitAppRes("lindb.sh");

	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	strcpy(sType,argv[3]);
	
/*����Ҫ����Ĳ�����ȡ�� ������*/
	if(GetDispParamList(sFileName,iGroupID,&ptHead)<0) return -1;

	ptLkHead= ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*�������Ϸ��ԡ�*/

		if(IsDir(pTemp->sSourcePath)==FALSE){
			printALERT("����Ŀ¼%s��Ч.",pTemp->sSourcePath);
			continue;
		}

		/*Ŀ��Ŀ¼����������,����/nilĿ¼*/
		if(MyChkDir(pTemp->sDestPath1)<0)strcpy(pTemp->sDestPath1,"");
		if(MyChkDir(pTemp->sDestPath2)<0)strcpy(pTemp->sDestPath2,"");
		if(MyChkDir(pTemp->sDestPath3)<0)strcpy(pTemp->sDestPath3,"");
		if(MyChkDir(pTemp->sDestPath4)<0)strcpy(pTemp->sDestPath4,"");

		iRet=ProcessMain(pTemp,sType);

		if(iRet<0){
			printALERT("�ַ��ļ�ʧ��!");
			return -1;
		}
		if(iRet>0) break;
	}

	DestroyList((LIST*)ptLkHead);

	return 0;
}

