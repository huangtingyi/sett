#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <bintree.h>

#include "imei_supp.h"

FILE *fp;
int pid=0,iSeq=1;
char sgFileName[128];

struct ImeiIniStruct
{
	struct ImeiIniStruct *pNext;
	
	int 	iGroupID;
	char	sSourceID[10];
	char	sFilter[20];
	char	sSourcePath[128];
	char	sOutPath[128];
	char	sFileType[2];
	char	sDeleteType[2];
	struct ImeiIniStruct *pLoadNext;
};

int GenImeiUpPrepFileName(char sFileName[])
{
	char sHostTime[15];
	GetHostTime(sHostTime);
	strcpy(sFileName,"PREP");
	sprintf(sFileName,"/ticket/work/Imei_prep/PREP%d%s%06d.P",pid,sHostTime,iSeq);
	iSeq++;
}

int data_search_bintree_imei_up_e(void *pValue,void*pData)
{
	int res=0;
	
	struct ImeiUpStruct *pSource=(struct ImeiUpStruct *)pValue;
	struct ImeiUpStruct *pTarget=(struct ImeiUpStruct *)pData;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	
	return 0;
}

int SearchImeiUpItem(struct ImeiUpStruct *p,BINTREE *ptRoot)
{
	struct ImeiUpStruct *ptHead,*pTemp;
	
	if(SearchBin(ptRoot,(void*)p,data_search_bintree_imei_up_e,
		(void**)&ptHead)==NOTFOUND) return NOTFOUND;
	
	while(ptHead!=NULL){
		if(strcmp(ptHead->sImei,p->sImei)==0&&
			strcmp(ptHead->sImsi,p->sImsi)==0)
			return FOUND;
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void mvitem_str2imeiben(char sLine[],struct ImeiUpStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct ImeiUpStruct));
	
	memcpy(sTemp,sLine+17,15);sTemp[15]=0;AllTrim(sTemp);
/*	printf("%s ",sTemp);*/
	strcpy(p->sMsisdn,sTemp);
	memcpy(sTemp,sLine+155,15);sTemp[15]=0;AllTrim(sTemp);
/*	printf("%s ",sTemp);*/
	strcpy(p->sImei,sTemp);
	memcpy(sTemp,sLine+2,15);sTemp[15]=0;AllTrim(sTemp);
/*	printf("%s ",sTemp);*/
	strcpy(p->sImsi,sTemp);
	memcpy(sTemp,sLine+56,14);sTemp[14]=0;AllTrim(sTemp);
/*	printf("%s ",sTemp);*/
	strcpy(p->sCallstarttime,sTemp);
	memcpy(sTemp,sLine+152,1);sTemp[1]=0;AllTrim(sTemp);
/*	printf("%s.\n",sTemp);*/
	strcpy(p->sAreaID,sTemp);

}

/*批量加载文件数据*/
int FTxtFile2PrepFile(char sPathFileName[],BINTREE **pptRoot)
{
	char	sTemp[1024],sCondition[2000],sBuf[1024],sType[2],sMatchitem[2];
	struct ImeiUpStruct Temp,*pImeiUp,*pImeiList=NULL;
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	static int iTotalCnt=0;
	
	strcpy(sMatchitem,"");
	strcpy(sType,"1");
	if(RLike(sPathFileName,"C")==true){
		strcpy(sMatchitem,"3");
		strcpy(sType,"2");
	}
	
	if(TxtFileToList(sPathFileName,&ptHead)<0) return -1;
/*备份链表*/
	ptLkHead=ptHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
		mvitem_str2imeiben(sTemp,&Temp);
		
		if(SearchImeiUpItem(&Temp,*pptRoot)==FOUND) continue;

		if((pImeiUp=(struct ImeiUpStruct*)malloc(
			sizeof(struct ImeiUpStruct)))==NULL) return -1;

		memcpy((void*)pImeiUp,(void*)&Temp,sizeof(struct ImeiUpStruct));
		pImeiUp->pNext=NULL;
		pImeiUp->pLoadNext=NULL;
		if(InsertBin(pptRoot,(void*)pImeiUp,data_search_bintree_imei_up_e,
			assign_insert_bintree)<0) return -1;
		
		sprintf(sBuf,"%-16s%-16s%-16s%15s%2s%2s%2s\n",Temp.sMsisdn,Temp.sImei,
			Temp.sImsi,Temp.sCallstarttime,Temp.sAreaID,sMatchitem,sType);

		if(WriteFile(fp,(void*)sBuf,strlen(sBuf))<0) return -1;
		
		if((++iTotalCnt)%5000==0){
			CloseFile(fp);
			GenImeiUpPrepFileName(sgFileName);
			if(ptHead!=NULL) fp=OpenFileWrite(sgFileName);
		}
	}
	listfree(&ptLkHead);
}
void mvitem_str2imeiini(char sLine[],struct ImeiIniStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct ImeiIniStruct));

	p->pNext=NULL;

	GetTabStr(sLine,0,sTemp);AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

	GetTabStrX(sLine,1,6,p->sSourceID);	AllTrim(p->sSourceID);
	GetTabStrX(sLine,2,20,p->sFilter);	AllTrim(p->sFilter);
	GetTabStrX(sLine,3,80,p->sSourcePath);	RegularDir(p->sSourcePath);
	GetTabStrX(sLine,4,80,p->sOutPath);	RegularDir(p->sOutPath);
	GetTabStrX(sLine,5,1,p->sFileType);	AllTrim(p->sFileType);
	GetTabStrX(sLine,6,1,p->sDeleteType);	AllTrim(p->sDeleteType);

}
int FInitImei2DbIni2List(char sFileName[],int iGroupID,struct ImeiIniStruct **pptHead)
{
	char	sTemp[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	ImeiIniStruct *ptPre=NULL,*ptCur=NULL,Temp;


/*释放上次循环分配的内存*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;
/*备份链表*/
	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
/*		if(strchr(sTemp,'#')!=NULL) continue;*/
		if(sTemp[0]=='#') continue;
		
/*将行记录转换结构格式*/
		mvitem_str2imeiini(sTemp,&Temp);
/*去掉不属于指定组的记录*/
		if(iGroupID!=Temp.iGroupID) continue;

		if((ptCur=(struct ImeiIniStruct*)malloc(
			sizeof(struct ImeiIniStruct)))==NULL){
			WriteAlertPrint("分配内存 ImeiIniStruct 失败,退出!");
			return -1;
		}

		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct ImeiIniStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	
/*返回链表*/
	*pptHead=ptPre;

	return 0;
}
int free_list_imei_up_e(void **pData)
{
	struct ImeiIniStruct *ptHead=(struct ImeiIniStruct*)*pData,*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		free(pTemp);
		pTemp=NULL;
	}
	return 0;
}

int main(int argc,char **argv)
{
	char sSourcePath[128],sFileName[128],sPathFileName[128],sIniFileName[128];
	int iGroupID;
	struct FileControlStruct *ptHead=NULL,*pTemp=NULL,*ptLkHead=NULL;
	struct ImeiIniStruct *pIniList=NULL,*pIniTmp;
	BINTREE *ptRoot=NULL;
	
	if(argc!=3){
		printf("Usage : %s inifile groupid.\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	pid=getpid();
	strcpy(sIniFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	
	if(FInitImei2DbIni2List(sIniFileName,iGroupID,&pIniList)<0) return -1;
	
while(pIniList!=NULL){
	pIniTmp=pIniList;
	pIniList=pIniList->pNext;
	
	ptHead=NULL;
	/*生成要处理的文件列表*/
	if(dir2list(pIniTmp->sSourcePath,pIniTmp->sFilter,&ptHead)<0){
		WriteAlertMsg("获取要处理的文件列表失败，进程退出");
		return -1;
	}
	if(ptHead==NULL) continue;

	GenImeiUpPrepFileName(sgFileName);
	fp=OpenFileWrite(sgFileName);

	ptLkHead=ptHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);
		
		sprintf(sPathFileName,"%s%s",pIniTmp->sSourcePath,sFileName);
		if(IsFile(sPathFileName)==0) continue;
		
		if(FTxtFile2PrepFile(sPathFileName,&ptRoot)<0) return -1;
		
		WriteProcMsg("完成文件 %s 的转化.",sFileName);
		execcmd("rm -f %s",sPathFileName);
	}
	CloseFile(fp);
	WriteProcPrint("处理点 %s 完成.",pIniTmp->sSourcePath);
	listfree(&ptLkHead);
	TravelBin(ptRoot,free_list_imei_up_e);
	DestroyBin(ptRoot);
	ptRoot=NULL;
}
	return 0;
}

