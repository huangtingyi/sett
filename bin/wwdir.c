#include "hnixs.h"
#include "list.h"
#include "bintree.h"
#include "wwtiny.h"
#include "wwdir.h"

void RegularDir(char sPath[])
{
	if(RLike(sPath,"/")==false) strcat(sPath,"/");
}

int CheckDir(char sPath[])
{

	struct stat Buffer;
	char sPathName[256], *pTemp, sCommand[1024];

	if((pTemp=strrchr(sPath, '/'))==NULL){
		perror(sPath);
		return -1;
	}

	strncpy(sPathName,sPath,pTemp-sPath+1);

	sPathName[pTemp-sPath+1]=0;

	if(stat(sPathName, &Buffer) < 0){
		switch(errno){
			case EACCES:
				printf("û��%s�ķ���Ȩ��.\n", sPathName);
				return -1;
			case ENAMETOOLONG:
				printf("·��%s̫��.\n", sPathName);
				return -1;
			case ENOENT:
				break;			/* ·�������� */
			case ENOTDIR:
				printf("%s����·��.\n", sPathName);
				return -1;
			default:
				perror(sPathName);
				return -1;
		}
	}
	else
		return 0;              /* ·���Ѵ��� */

	if(strlen(sPathName)>0&&sPathName[0]=='/'){
		sprintf(sCommand,"mkdir -p %s",sPathName);

		if(system(sCommand)==0) return 0;
	}

	return -1;
}

DIR *OpenDir(char sPath[])
{
	DIR *dp;
	
	if((dp=opendir(sPath))==NULL)
		return NULL;
	return dp;
}

void CloseDir(DIR *dp)
{
	closedir(dp);
}

int ReadDir(DIR *dp,char sName[])
{
	struct dirent *d;

	if(dp==NULL) return -1;

	strcpy(sName,"");

	if((d = readdir(dp))==NULL)
		return -1;

	strcpy(sName,d->d_name);

	return 0;
}

int IsDir(char sName[])
{
	DIR *P;
	
	if((P=opendir(sName))==NULL) return FALSE;
	closedir(P);
	
	return TRUE;
}
void DeleteSubdirFileName(struct FileControlStruct **pptHead)
{
	char sFileName[256];
	
	struct FileControlStruct *ptLkHead=NULL,*ptHead,*pTemp;
	
	ptHead=*pptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
	/*�ļ���̫���϶��ǲ��е�*/		
		if(pTemp->iLen>=256){
			free(pTemp);
			continue;
		}

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		TrimAll(sFileName);
	/*����ļ������зǷ��Ķ�������Ҳ�ǲ�Ҫ��*/
		if(strchr(sFileName,'/')!=NULL||
			strchr(sFileName,'\\')!=NULL){
			free(pTemp);
			continue;
		}
		InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	*pptHead=ptLkHead;
}
int list2basename(struct FileControlStruct **pptHead)
{
	char sTemp[1024],sBaseName[1024];
	struct FileControlStruct *ptHead=(*pptHead),*ptLkHead=NULL,*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		
		AllTrim(sTemp);
		GetBaseName(sTemp,sBaseName);
		
		if(item2list(&ptLkHead,(void*)sBaseName,strlen(sBaseName))<0)
			return -1;
		free(pTemp);
	}
	ReverseList((LIST**)&ptLkHead);

	*pptHead=ptLkHead;
	return 0;
}
/*��Ŀ¼���ļ���ȡ��������*/	
int dir2list_o(char sSourcePath[],char sFilter[],
	struct FileControlStruct **pptHead)
{
	char sCommand[256];

	*pptHead=NULL;

	if(IsDir(sSourcePath)==false){
		printf("·��%s��Ч.\n",sSourcePath);
		return -1;
	}
	RegularDir(sSourcePath);

	if(strlen(sFilter)!=0)
		sprintf(sCommand,"ls -rt %s%s 2>/dev/null",sSourcePath,sFilter);
	else	sprintf(sCommand,"ls -rt %s 2>/dev/null",sSourcePath);
	
	if(exec2list(sCommand,pptHead)!=0){
		
		if(strlen(sFilter)==0){
			printf("ִ��%s����ʧ��.\n",sCommand);
			return -1;
		}
		sprintf(sCommand,"find %s -name \"%s\" | sed s,%s,,",
			sSourcePath,sFilter,sSourcePath);
		if(exec2list(sCommand,pptHead)!=0){
			printf("ִ��%s����ʧ��.\n",sCommand);
			return -1;
		}
		/*��������Ŀ¼���ļ���ɾһ��*/
		DeleteSubdirFileName(pptHead);
	}
	/*���п��ܴ��ڵ�Ŀ¼ɾ��*/
	return list2basename(pptHead);
}

/*���ļ����޸�ʱ���С��������*/
struct MyFileNameStruct *pMyNameList=NULL;
int data_search_bintree_modify_time(void *pValue,void*pData)
{
	int res=0;
	
	struct MyFileNameStruct *pSource=(struct MyFileNameStruct *)pValue;
	struct MyFileNameStruct *pTarget=(struct MyFileNameStruct *)pData;
	
	if((res=(pSource->tModifyTime-pTarget->tModifyTime))!=0) return res;

	return strcmp(pSource->sBaseName,pTarget->sBaseName);
}
int add_my_name_list(void **pptHead)
{
	struct MyFileNameStruct *ptHead=(struct MyFileNameStruct *)*pptHead;
	struct MyFileNameStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		InsertList((LIST**)&pMyNameList,(LIST*)pTemp);
	}
	return 0;
}
int dir2list(char sSourcePath[],char sFilter[],
	struct FileControlStruct **pptHead)
{
	DIR *DP;
	struct dirent *dp;
	struct stat Stat;
	BINTREE *pRoot=NULL;
	struct MyFileNameStruct *pTemp,*ptHead;
	char sTempName[1024];

	*pptHead=NULL;
	pRoot=NULL;

	if((DP=opendir(sSourcePath))==NULL){
		printf("��Ŀ¼%s����.\n",sSourcePath);
		return -1;
	}

	while((dp=readdir(DP))!=NULL){
		/*��Ŀ¼������ϼ�Ŀ¼�����**/
		if(strcmp(dp->d_name,".")==0||
			strcmp(dp->d_name,"..")==0)
			continue;
		
		/*�ļ�ģʽƥ�䲻�ϻ��ļ���̫���򲻼���*/
		if(LikeX(dp->d_name,sFilter)==false||
			strlen(dp->d_name)>=128) continue;

		/*ƴ���ļ���*/
		strcpy(sTempName,sSourcePath);
		strcat(sTempName,"/");
		strcat(sTempName,dp->d_name);

		if(stat(sTempName,&Stat)!=0) continue;
		
		/*�������һ������ļ�����*/
		if(!S_ISREG(Stat.st_mode)) continue;

		if((pTemp=malloc(sizeof(struct MyFileNameStruct)))==NULL){
			printf("�����ڴ�ʧ��,MyFileNameStruct.\n");
			closedir(DP);
			return -1;
		}

		bzero((void*)pTemp,sizeof(struct MyFileNameStruct));
		
		pTemp->tModifyTime=Stat.st_mtime;
		strcpy(pTemp->sBaseName,dp->d_name);
		
		/*���ļ�����*/
		if(InsertBin(&pRoot,(void *)pTemp,
			data_search_bintree_modify_time,
			assign_insert_bintree)<0){
			printf("�����ڴ�ʧ��,BINTREE.\n");
			closedir(DP);
			return -1;
		}
	}
	closedir(DP);

	pMyNameList=NULL;
	TravelBin(pRoot,add_my_name_list);
	
	/*�ͷ��ڴ�*/
	DestroyBin(pRoot);
	
	/*��pMyNameList�е����ݼӵ�����б���*/
	ptHead=pMyNameList;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(item2list(pptHead,(void*)pTemp->sBaseName,
			strlen(pTemp->sBaseName))<0){
			DestroyList((LIST*)(*pptHead));
			DestroyList((LIST*)pMyNameList);
			printf("�����ڴ�ʧ��.\n");
			return -1;
		}
	}
	
	DestroyList((LIST*)pMyNameList);

	return 0;
}
