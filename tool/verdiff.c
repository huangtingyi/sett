#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <list.h>
#include <hnixs.h>
#include <wwtiny.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE 
#define FALSE 0
#endif

struct DirectoryItemStruct
{
	struct DirectoryItemStruct *pNext;
	char	sRelaDir[120];
	char	sName[120];
	int	iExistFlag;
};

int CreateDirList(DIR *DP,char sRelaDir[120],struct DirectoryItemStruct **pptHead);
int IsDirectory(char sName[]);
void ConvertDirLast(char sDir[]);
int FileInTarget(char sTargetName[120],struct DirectoryItemStruct *ptHead)
{
	char	sTempName[120];
	
	while(ptHead!=NULL){
		strcpy(sTempName,ptHead->sRelaDir);
		strcat(sTempName,"/");
		strcat(sTempName,ptHead->sName);
		
		if(strcmp(sTargetName,sTempName)==0){
			ptHead->iExistFlag=true;
			return true;
		}
		ptHead=ptHead->pNext;
	}
	return false;
}
int main(int argc,char *argv[])
{
	int i,iErrCnt=0,iCnt=0,iIncreaseCnt=0,iNewCnt=0;
	DIR *DP;
	FILE *fp;
	struct  stat s;
	
	struct DirectoryItemStruct *pSourceItem=NULL;
	struct DirectoryItemStruct *pTargetItem=NULL,*pTemp;
	
	char statement[256];
	char sSourceDir[120],sTargetDir[120],sResultDir[120],sRelaDirStr[120];
	char sSourceName[120],sTargetName[120],sResultName[120],sRelaDir[120];
	
	if(argc!=4){
		printf("�÷�:������ ����·�� �汾·�� ���·��.\n");
		printf("����: %s src srv srd\n",argv[0]);
		exit(1);
	}
	if(IsDirectory(argv[1])==FALSE||IsDirectory(argv[2])==FALSE||
		IsDirectory(argv[3])==FALSE){
		printf("�������������ĳ������·��");
		exit(1);
	}
	
	strcpy(sSourceDir,argv[1]);
	strcpy(sTargetDir,argv[2]);
	strcpy(sResultDir,argv[3]);
	
	ConvertDirLast(sSourceDir);
	ConvertDirLast(sTargetDir);
	ConvertDirLast(sResultDir);
	
	printf("��ʼ�汾���....\n");
	if((fp=fopen("copy.sh","w"))==NULL){
		printf("���ļ�copy.sh����.\n");
		exit(1);
	}
	
	printf("��ʼ�����߳���·����Ϣ....\n");
	if((DP=opendir(sSourceDir))==NULL){
		printf("��Ŀ¼%s����.\n",sSourceDir);
		exit(1);
	}
	if(CreateDirList(DP,sSourceDir,&pSourceItem)<0){
		printf("����Ŀ¼%s�б����.\n",sSourceDir);
		exit(1);
	}
	closedir(DP);
	
	printf("��ʼ���汾����·����Ϣ....\n");
	if((DP=opendir(sTargetDir))==NULL){
		printf("��Ŀ¼%s����.\n",sSourceDir);
		exit(1);
	}
	if(CreateDirList(DP,sTargetDir,&pTargetItem)<0){
		printf("����Ŀ¼%s�б����.\n",sTargetDir);
		exit(1);
	}
	closedir(DP);
	
	printf("��ͬ�ļ����:......\n");
	fprintf(fp,"###------ copy different file begin.\n");
	pTemp=pSourceItem;
	while(pTemp!=NULL){

		if(strcmp(pTemp->sRelaDir,sSourceDir)!=0)
			strcpy(sRelaDir,pTemp->sRelaDir+strlen(sSourceDir)+1);
		else
			strcpy(sRelaDir,"");
		
		strcpy(sRelaDirStr,sRelaDir);
		for(i=0;i<strlen(sRelaDirStr);i++)
			if(sRelaDirStr[i]=='/')sRelaDirStr[i]='_';
		
		if(strlen(sRelaDir)!=0){
			sprintf(sSourceName,"%s/%s/%s",
				sSourceDir,sRelaDir,pTemp->sName);
			sprintf(sTargetName,"%s/%s/%s",
				sTargetDir,sRelaDir,pTemp->sName);
		}
		else{
			sprintf(sSourceName,"%s/%s",sSourceDir,pTemp->sName);
			sprintf(sTargetName,"%s/%s",sTargetDir,pTemp->sName);
		}
	
		sprintf(sResultName,"%s/%s.%s",
			sResultDir,pTemp->sName,sRelaDirStr);
		
		if(FileInTarget(sTargetName,pTargetItem)==FALSE){
			pTemp=pTemp->pNext;
			continue;
		}
		pTemp->iExistFlag=true;
		
		sprintf (statement,"diff %s %s > %s  2>/dev/null",
			sSourceName,sTargetName,sResultName);
		if(PROC_EXIT_CODE(system(statement))>1){
			perror("������Ϣ");
			printf("ִ������ %s��ʧ��.\n",statement);
			exit(1);
		}
		bzero((void*)&s,sizeof(struct stat));
		stat(sResultName, &s);

		if(s.st_size==0){
			iCnt++;
			sprintf (statement,"rm %s 2>/dev/null",sResultName);
			system(statement);
		}
		else{
			iErrCnt++;
			printf("�����ļ� %s �͡�%s���ļ���һ��.\n",sSourceName,sTargetName);
			fprintf(fp,"cp %s %s;\n",sTargetName,sSourceName);
		}
		
		pTemp=pTemp->pNext;
	}
	fprintf(fp,"###------ copy different file end.\n");

	printf("���߶����ļ��б���:......\n");
	fprintf(fp,"###------ remove increase file begin.\n");
	pTemp=pSourceItem;
	while(pTemp!=NULL){
		if(pTemp->iExistFlag==0){
			iIncreaseCnt++;
			printf("���߶����ļ�%s/%s.\n",
				pTemp->sRelaDir,pTemp->sName);
			fprintf(fp,"rm %s/%s;\n",pTemp->sRelaDir,pTemp->sName);
		}
		pTemp=pTemp->pNext;
	}
	fprintf(fp,"###----------- remove increase file end.\n");
	
	
	printf("�汾�����ļ��б���:......\n");
	
	fprintf(fp,"###----------- copy new file begin.\n");
	pTemp=pTargetItem;
	while(pTemp!=NULL){
		if(pTemp->iExistFlag!=0){
			pTemp=pTemp->pNext;
			continue;
		}
		iNewCnt++;
		printf("�汾�����ļ�%s/%s.\n",pTemp->sRelaDir,pTemp->sName);
		
		if(strcmp(pTemp->sRelaDir,sTargetDir)!=0)
			strcpy(sRelaDir,pTemp->sRelaDir+strlen(sTargetDir)+1);
		else	strcpy(sRelaDir,"");
			
		if(strlen(sRelaDir)!=0){
			sprintf(sSourceName,"%s/%s/%s",
				sSourceDir,sRelaDir,pTemp->sName);
			sprintf(sTargetName,"%s/%s/%s",
				sTargetDir,sRelaDir,pTemp->sName);
		}
		else{
			sprintf(sSourceName,"%s/%s",sSourceDir,pTemp->sName);
			sprintf(sTargetName,"%s/%s",sTargetDir,pTemp->sName);
		}

		fprintf(fp,"cp %s %s;\n",sTargetName,sSourceName);

		pTemp=pTemp->pNext;
	}
	fprintf(fp,"###----------- copy new file end.\n");
	
	fclose(fp);

	printf("�汾������:.\n");
	printf("�����ļ����%d��,�汾�ļ�����%d��,%d���ļ���ȫһ��,%d���ļ���һ��.\n",
		iIncreaseCnt,iNewCnt,iCnt,iErrCnt);
	printf("���½ű���copy.sh,��һ�³�����ϸ���ݼ�%sĿ¼.\n",sResultDir);
		
	return 0;
}


void ConvertDirLast(char sDir[])
{
	if(sDir[0]==0) return;
	
	if(sDir[strlen(sDir)-1]=='/'||
		sDir[strlen(sDir)-1]=='\\') sDir[strlen(sDir)]=0;
}
int IsDirectory(char sName[])
{
	DIR *P;
	
	if((P=opendir(sName))==NULL) return FALSE;
	closedir(P);
	
	return TRUE;
}
int WantDiff(char sTempName[])
{
/*��̨����*/
	if(RLike(sTempName,".pc")==true||
		RLike(sTempName,".c")==true||
		RLike(sTempName,".h")==true||
		RLike(sTempName,".sh")==true||
		RLike(sTempName,".expr")==true||
		RLike(sTempName,".in")==true||
		RLike(sTempName,".pl")==true||
		LLike(sTempName,"make")==true||
		LLike(sTempName,"Make")==true) return true;
/*JAVA����*/
	if(RLike(sTempName,".java")==true||
		RLike(sTempName,".jsp")==true||
		RLike(sTempName,".html")==true||
		RLike(sTempName,".htm")==true||
		RLike(sTempName,".xml")==true||
		RLike(sTempName,".properties")==true) return true;

	return false;
}
int CreateDirList(DIR *DP,char sRelaDir[120],struct DirectoryItemStruct **pptHead)
{
	char sTempName[1024];
	struct dirent *dp;
	struct DirectoryItemStruct *pTemp=NULL;

	while((dp = readdir(DP))!=NULL){
	
		/*��Ŀ¼������ϼ�Ŀ¼�����**/
		if(strcmp(dp->d_name,".")==0||
			strcmp(dp->d_name,"..")==0)
			continue;

		/*ƴ���ļ���*/
		strcpy(sTempName,sRelaDir);
		strcat(sTempName,"/");
		strcat(sTempName,dp->d_name);
	
		if(IsDirectory(sTempName)){

			DIR	*TP;
			struct DirectoryItemStruct *ptHead=NULL;

			/*���Ŀ¼��û����*/
			if((TP=opendir(sTempName))==NULL)
				continue;
			
			if(CreateDirList(TP,sTempName,&ptHead)<0)
				return -1;
			/*����ʱ����ϲ������������*/	
			while(ptHead!=NULL){
				pTemp=ptHead;
				ptHead=ptHead->pNext;
				InsertList((LIST**)pptHead,(LIST*)pTemp);
			}

			continue;
		}
		
		if(WantDiff(dp->d_name)==false) continue;

		if((pTemp=malloc(sizeof(struct DirectoryItemStruct)))==NULL){
			printf("error malloc DirectoryItemStruct.\n");
			return -1;
		}

		bzero((void*)pTemp,sizeof(struct DirectoryItemStruct));
		strcpy(pTemp->sRelaDir,sRelaDir);
		strcpy(pTemp->sName,	dp->d_name);

		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	return 0;
}
