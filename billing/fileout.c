#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwsupp.h>
#include <fileout.h>

void GetOutFileName(char sTargetName[],char sSuffix[],char sFileName[])
{
	sprintf(sFileName,"%s.%s.tmp",sTargetName,sSuffix);
}
struct MyFileOutStruct *GetFileOut(struct FileControlStruct **pptHead,
	char sTargetName[],char sSplitType[])
{
	struct FileControlStruct *ptHead=*pptHead;
	struct MyFileOutStruct *pTemp,Temp;
	char sFileName[256];
		
	while(ptHead!=NULL){
		pTemp=(struct MyFileOutStruct *)ptHead->pData;
		if(strcmp(sSplitType,pTemp->sSplitType)==0) return pTemp;
		ptHead=ptHead->pNext;
	}
	bzero((void*)&Temp,sizeof(struct MyFileOutStruct));
	
	Temp.pNext=NULL;
	strcpy(Temp.sSplitType,sSplitType);
	GetOutFileName(sTargetName,sSplitType,sFileName);
	
	if((Temp.fp=fopen(sFileName,"w"))==NULL) return NULL;
	
	if(item2list(pptHead,(void*)&Temp,sizeof(struct MyFileOutStruct))<0)
		return NULL;
	return (struct MyFileOutStruct *)((*pptHead)->pData);
}
void CloseFileOut(struct FileControlStruct *ptHead)
{
	struct FileControlStruct *pTemp;
	struct MyFileOutStruct *ptCur;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		ptCur=(struct MyFileOutStruct *)pTemp->pData;
		fclose(ptCur->fp);

		free(pTemp);
	}

}
void CloseFileOutAll(struct FileControlOutStruct *ptHead)
{
	struct FileControlOutStruct *pTemp;
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		CloseFileOut(pTemp->pHead);
		
		free(pTemp);
	}
}
/*控制文件支持*/
int Item2FileOut(struct FileControlStruct **ppHead,void *pData,int iLen,
	char sTargetName[],char sSplitType[])
{
	char sFileLine[8192];
	struct MyFileOutStruct *pTemp;

	if((pTemp=GetFileOut(ppHead,sTargetName,sSplitType))==NULL) return -1;

	memcpy((void*)sFileLine,pData,iLen);sFileLine[iLen]=0;
	
	if(fprintf(pTemp->fp,"%s",sFileLine)<0) return -1;
	
	return 0;
}
int Item2FileSplitOut(struct FileControlOutStruct **pptHead,void *pData,int l,
	char sBaseName[],char sTargetName[],char sSplitType[],
	struct TinyRollLogStruct **ppSumLog,char sSplitNew[],char msg[])
{
	char sSuffix[2],sFileName[128],sSuffixUse[21];
	int i,len,iCnt=0;
	struct FileControlOutStruct *pTemp=NULL;

	strcpy(msg,"");
	
	strcpy(sSuffixUse,sSplitType);
	if(strlen(SUFFIX_STR)!=0)strcpy(sSuffixUse,SUFFIX_STR);
		
	len=strlen(sSuffixUse);
	for(i=0;i<len;i++){
		sSuffix[0]=sSuffixUse[i];sSuffix[1]=0;
		if(SearchFileControlOut(*pptHead,sSuffix,&pTemp)==NOTFOUND){
			if((pTemp=malloc(sizeof(struct FileControlOutStruct)))==NULL){
				sprintf(msg,"分配  FileControlOut 错误");
				return -1;
			}
			strcpy(pTemp->sSuffix,sSuffix);
			pTemp->iCnt=0;
			pTemp->pNext=NULL;
			pTemp->pHead=NULL;
			InsertListTail((LIST**)pptHead,(LIST*)pTemp);
		}
		pTemp->iCnt++;iCnt++;
		if(Item2FileOut(&(pTemp->pHead),pData,l,sTargetName,
			sSuffix)<0){
			sprintf(msg,"生成正常话单链表错误");
			return -1;
		}
		GetOutFileName(sTargetName,sSuffix,sFileName);
		if(SumTinyRollLog(ppSumLog,sBaseName,sFileName,1)<0){
			sprintf(msg,"生成日志文件列表错误");
			return -1;
		}
		if(strstr(sSplitNew,sSuffix)==NULL) strcat(sSplitNew,sSuffix);
	}
	return iCnt;
}
