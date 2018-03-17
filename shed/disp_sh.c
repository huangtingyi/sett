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

#include <appsupp.h>

int ProcessMain( struct DispParamStruct *pParam)
{
	int l=0;
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

		/*����ļ��ձ��޸��򲻴���*/
		sprintf(sTempName,"%s%s",pParam->sSourcePath,sFileName);

		if(FileModifyDiff(sTempName)<1) continue;

		/*Ϊ�˰�ȫ��������������*/
		sCommand[0]=sRCommand[0]=0;
		
		/*��������,���ɹ���ɾ��Դ�ļ�*/
		l=0;
		if(strlen(pParam->sDestPath1)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath1);
		}
		if(strlen(pParam->sDestPath2)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath2);

		}
		if(strlen(pParam->sDestPath3)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath3);

		}
		if(strlen(pParam->sDestPath4)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath4);
		}
	/*ȥ������&&*/
		if(RLike(sCommand,"&&"))
			sCommand[strlen(sCommand)-2]=0;
		
		/*ʧ�ָܻ�����*/
		l=0;
		if(strlen(pParam->sDestPath1)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath1,sFileName);
		if(strlen(pParam->sDestPath2)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath2,sFileName);
		if(strlen(pParam->sDestPath3)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath3,sFileName);
		if(strlen(pParam->sDestPath4)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath4,sFileName);

	/*ȥ������&&*/
		if(RLike(sRCommand,"&&"))
			sRCommand[strlen(sRCommand)-2]=0;

		/*ȫ���ɹ���ɾ���ļ�,���ĳ��ʧ�ܣ�ɾ���Ѿ��ַ����ļ���*/
		if(system(sCommand)!=0){

			printALERT("ִ��%sʧ��",sCommand);
			system(sRCommand);
			listfree(&ptLkHead);
			return -1;
		}
		sprintf(sCommand,"rm -f %s",sTempName);
		system(sCommand);

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
	char sFileName[256];
	struct DispParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;

	if(argc!=3){
		printf("Usage %s disp.ini GroupID.\n",argv[0]);
		return -1;
	}

	InitAppRes("disp.sh");

	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);

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

		iRet=ProcessMain(pTemp);

		if(iRet<0){
			printALERT("�ַ��ļ�ʧ��!");
			return -1;
		}
		if(iRet>0) break;
	}

	DestroyList((LIST*)ptLkHead);

	return 0;
}

