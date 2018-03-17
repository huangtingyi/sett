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
				printf("没有%s的访问权限.\n", sPathName);
				return -1;
			case ENAMETOOLONG:
				printf("路径%s太长.\n", sPathName);
				return -1;
			case ENOENT:
				break;			/* 路径不存在 */
			case ENOTDIR:
				printf("%s不是路径.\n", sPathName);
				return -1;
			default:
				perror(sPathName);
				return -1;
		}
	}
	else
		return 0;              /* 路径已存在 */

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
	/*文件名太长肯定是不行地*/		
		if(pTemp->iLen>=256){
			free(pTemp);
			continue;
		}

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		TrimAll(sFileName);
	/*如果文件名中有非法的东西，则也是不要的*/
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
/*将目录的文件名取到链表中*/	
int dir2list_o(char sSourcePath[],char sFilter[],
	struct FileControlStruct **pptHead)
{
	char sCommand[256];

	*pptHead=NULL;

	if(IsDir(sSourcePath)==false){
		printf("路径%s无效.\n",sSourcePath);
		return -1;
	}
	RegularDir(sSourcePath);

	if(strlen(sFilter)!=0)
		sprintf(sCommand,"ls -rt %s%s 2>/dev/null",sSourcePath,sFilter);
	else	sprintf(sCommand,"ls -rt %s 2>/dev/null",sSourcePath);
	
	if(exec2list(sCommand,pptHead)!=0){
		
		if(strlen(sFilter)==0){
			printf("执行%s命令失败.\n",sCommand);
			return -1;
		}
		sprintf(sCommand,"find %s -name \"%s\" | sed s,%s,,",
			sSourcePath,sFilter,sSourcePath);
		if(exec2list(sCommand,pptHead)!=0){
			printf("执行%s命令失败.\n",sCommand);
			return -1;
		}
		/*将包含子目录的文件名删一下*/
		DeleteSubdirFileName(pptHead);
	}
	/*将有可能存在的目录删除*/
	return list2basename(pptHead);
}

/*让文件从修改时间从小到大排序*/
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
		printf("打开目录%s错误.\n",sSourcePath);
		return -1;
	}

	while((dp=readdir(DP))!=NULL){
		/*是目录本身或上级目录则继续**/
		if(strcmp(dp->d_name,".")==0||
			strcmp(dp->d_name,"..")==0)
			continue;
		
		/*文件模式匹配不上或文件名太长则不加载*/
		if(LikeX(dp->d_name,sFilter)==false||
			strlen(dp->d_name)>=128) continue;

		/*拼凑文件名*/
		strcpy(sTempName,sSourcePath);
		strcat(sTempName,"/");
		strcat(sTempName,dp->d_name);

		if(stat(sTempName,&Stat)!=0) continue;
		
		/*如果不是一个规格文件则不行*/
		if(!S_ISREG(Stat.st_mode)) continue;

		if((pTemp=malloc(sizeof(struct MyFileNameStruct)))==NULL){
			printf("分配内存失败,MyFileNameStruct.\n");
			closedir(DP);
			return -1;
		}

		bzero((void*)pTemp,sizeof(struct MyFileNameStruct));
		
		pTemp->tModifyTime=Stat.st_mtime;
		strcpy(pTemp->sBaseName,dp->d_name);
		
		/*将文件内容*/
		if(InsertBin(&pRoot,(void *)pTemp,
			data_search_bintree_modify_time,
			assign_insert_bintree)<0){
			printf("分配内存失败,BINTREE.\n");
			closedir(DP);
			return -1;
		}
	}
	closedir(DP);

	pMyNameList=NULL;
	TravelBin(pRoot,add_my_name_list);
	
	/*释放内存*/
	DestroyBin(pRoot);
	
	/*将pMyNameList中的内容加到输出列表中*/
	ptHead=pMyNameList;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(item2list(pptHead,(void*)pTemp->sBaseName,
			strlen(pTemp->sBaseName))<0){
			DestroyList((LIST*)(*pptHead));
			DestroyList((LIST*)pMyNameList);
			printf("分配内存失败.\n");
			return -1;
		}
	}
	
	DestroyList((LIST*)pMyNameList);

	return 0;
}
