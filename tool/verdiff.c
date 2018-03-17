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
		printf("用法:程序名 在线路径 版本路径 结果路径.\n");
		printf("例如: %s src srv srd\n",argv[0]);
		exit(1);
	}
	if(IsDirectory(argv[1])==FALSE||IsDirectory(argv[2])==FALSE||
		IsDirectory(argv[3])==FALSE){
		printf("输入后三个参数某个不是路径");
		exit(1);
	}
	
	strcpy(sSourceDir,argv[1]);
	strcpy(sTargetDir,argv[2]);
	strcpy(sResultDir,argv[3]);
	
	ConvertDirLast(sSourceDir);
	ConvertDirLast(sTargetDir);
	ConvertDirLast(sResultDir);
	
	printf("开始版本检测....\n");
	if((fp=fopen("copy.sh","w"))==NULL){
		printf("打开文件copy.sh错误.\n");
		exit(1);
	}
	
	printf("初始化在线程序路径信息....\n");
	if((DP=opendir(sSourceDir))==NULL){
		printf("打开目录%s错误.\n",sSourceDir);
		exit(1);
	}
	if(CreateDirList(DP,sSourceDir,&pSourceItem)<0){
		printf("生成目录%s列表错误.\n",sSourceDir);
		exit(1);
	}
	closedir(DP);
	
	printf("初始化版本程序路径信息....\n");
	if((DP=opendir(sTargetDir))==NULL){
		printf("打开目录%s错误.\n",sSourceDir);
		exit(1);
	}
	if(CreateDirList(DP,sTargetDir,&pTargetItem)<0){
		printf("生成目录%s列表错误.\n",sTargetDir);
		exit(1);
	}
	closedir(DP);
	
	printf("相同文件检查:......\n");
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
			perror("错误信息");
			printf("执行命令 %s　失败.\n",statement);
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
			printf("发现文件 %s 和　%s　文件不一致.\n",sSourceName,sTargetName);
			fprintf(fp,"cp %s %s;\n",sTargetName,sSourceName);
		}
		
		pTemp=pTemp->pNext;
	}
	fprintf(fp,"###------ copy different file end.\n");

	printf("在线多余文件列表检查:......\n");
	fprintf(fp,"###------ remove increase file begin.\n");
	pTemp=pSourceItem;
	while(pTemp!=NULL){
		if(pTemp->iExistFlag==0){
			iIncreaseCnt++;
			printf("在线多余文件%s/%s.\n",
				pTemp->sRelaDir,pTemp->sName);
			fprintf(fp,"rm %s/%s;\n",pTemp->sRelaDir,pTemp->sName);
		}
		pTemp=pTemp->pNext;
	}
	fprintf(fp,"###----------- remove increase file end.\n");
	
	
	printf("版本新增文件列表检查:......\n");
	
	fprintf(fp,"###----------- copy new file begin.\n");
	pTemp=pTargetItem;
	while(pTemp!=NULL){
		if(pTemp->iExistFlag!=0){
			pTemp=pTemp->pNext;
			continue;
		}
		iNewCnt++;
		printf("版本新增文件%s/%s.\n",pTemp->sRelaDir,pTemp->sName);
		
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

	printf("版本检查完毕:.\n");
	printf("在线文件多出%d个,版本文件增加%d个,%d个文件完全一致,%d个文件不一致.\n",
		iIncreaseCnt,iNewCnt,iCnt,iErrCnt);
	printf("更新脚本见copy.sh,不一致程序详细内容见%s目录.\n",sResultDir);
		
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
/*后台程序*/
	if(RLike(sTempName,".pc")==true||
		RLike(sTempName,".c")==true||
		RLike(sTempName,".h")==true||
		RLike(sTempName,".sh")==true||
		RLike(sTempName,".expr")==true||
		RLike(sTempName,".in")==true||
		RLike(sTempName,".pl")==true||
		LLike(sTempName,"make")==true||
		LLike(sTempName,"Make")==true) return true;
/*JAVA程序*/
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
	
		/*是目录本身或上级目录则继续**/
		if(strcmp(dp->d_name,".")==0||
			strcmp(dp->d_name,"..")==0)
			continue;

		/*拼凑文件名*/
		strcpy(sTempName,sRelaDir);
		strcat(sTempName,"/");
		strcat(sTempName,dp->d_name);
	
		if(IsDirectory(sTempName)){

			DIR	*TP;
			struct DirectoryItemStruct *ptHead=NULL;

			/*这个目录下没东西*/
			if((TP=opendir(sTempName))==NULL)
				continue;
			
			if(CreateDirList(TP,sTempName,&ptHead)<0)
				return -1;
			/*将临时链表合并到输出链表中*/	
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
