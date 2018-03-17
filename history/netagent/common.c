#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include "common.h"

void GetDataTime(char sFormat[],char sTime[])
{
	time_t	tTime;
        struct tm *tm1;

	time(&tTime);
        tm1= localtime(&tTime);	
        sprintf(sTime,sFormat,
        	tm1->tm_year+1900,tm1->tm_mon+1,tm1->tm_mday,
        	tm1->tm_hour,tm1->tm_min,tm1->tm_sec);	
}
/*本函数在wwlog.c中实现，因为其加了static所以在外部无法访问，所以复制一份！*/
void hosttime2asc(char sTime[])
{
	GetDataTime("%04d%02d%02d %02d:%02d:%02d",sTime);
}

int PrintLog(char sFileName[],char *fmt, ...)
{
	int l;
	FILE *fp;

	char sMessage[8192];
	va_list	argptr;

	if((fp=fopen(sFileName,"a"))==NULL) 
		return -1;

	va_start(argptr, fmt);
	if((l=vsprintf(sMessage,fmt, argptr))<0){
		va_end(argptr);
		fclose(fp);
		return -1;
	}
	va_end(argptr);

	if(l!=fprintf(fp,sMessage)){
		fclose(fp);
		return -1;
	}

	fclose(fp);

	return 0;
}

/*需要定制格式所以对日志操作重新定义而未使用wwlog中的功能*/
void DoLog(char *fmt,...)
{	
	va_list	argptr;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=0;
	static char sFileName[81];
	
	if(iFirstFlag==0){
		iFirstFlag=0;
		/*InitLogPath(sPath);*/
	}

	sprintf(sFileName,"%s/%s.log",
		".","cmd");
		/*AppRes.sAppName);*/

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);
	
	/*PrintLog(sFileName,"%s %s\n",
		sHostTime,sMessage);	*/
	printf("[%s]%s",sHostTime,sMessage);
}

int IsFile(char sName[])
{
	FILE *fp;
	
	if((fp=fopen(sName,"r"))==NULL) return 0;
	fclose(fp);
	
	return 1;
}

void AllTrim(char *s)
{
	int i=0;

	if(s[0]!=' ') goto trimall_next;

	while (s[i]==' ') i++;

	strcpy(s,s+i);

trimall_next:
	i = strlen(s)-1;
	
	while ( (i>=0) && (s[i]==' ') )	i--;

	s[i+1]='\0';
}

/*直接将数据插入头节点*/
void InsertList(LIST **pptHead,LIST *p)
{
	p->pNext=	*pptHead;
	*pptHead=	p;
}

/*控制文件支持*/
int item2list(struct FileControlStruct **ppHead,void *pData,int iLen)
{
	struct FileControlStruct *pTemp;

	if((pTemp=malloc(sizeof(struct FileControlStruct)+iLen))==NULL){
		listfree(ppHead);
		return -1;
	}

	pTemp->pData=(void*)(pTemp+1);

	pTemp->pNext=NULL;
	pTemp->iLen=iLen;
	memcpy(pTemp->pData,pData,iLen);

	InsertList((LIST**)ppHead,(LIST*)pTemp);

	return 0;
}

int listfree(struct FileControlStruct **pptHead)
{

	int iCnt=0;
	struct FileControlStruct *ptPre,*ptCur=(*pptHead);


	while(ptCur!=NULL){

		ptPre=ptCur;
		ptCur=ptCur->pNext;

		free(ptPre);
		iCnt++;
	}

	*pptHead=NULL;

	return iCnt;
}

void ReverseList(LIST **pptHead)
{
	LIST *pPre,*pCur;
	
	pCur=*pptHead;
	*pptHead=NULL;
	
	while(pCur!=NULL){
		pPre=pCur;
		pCur=pCur->pNext;
		InsertList(pptHead,pPre);
	}
}

int file2list(char sFileName[],int iHeadLen,int iRecLen,
	int iTailLen,struct FileControlStruct **pptHead)
{
#define FILEBUFLEN	1024*1024
#define RECLEN		8192

	FILE *fp;
	int iCnt=0,l;
	char	sRecord[RECLEN],sFileBuffer[FILEBUFLEN];
	struct FileControlStruct *ptHead=NULL;

	*pptHead=NULL;

	if((fp=fopen(sFileName,"r"))==NULL)
		return -1;	
	l=iRecLen;
	
	setvbuf(fp,sFileBuffer,_IOFBF,FILEBUFLEN);
	if(iHeadLen>0)/*如果需要跳过文件头则跳吧*/
		fseek(fp,iHeadLen,SEEK_SET);

	while(!feof(fp)){

		if(iRecLen>0){
			fread((void*)sRecord,iRecLen,1,fp);
		}
		else{
			fgets(sRecord,RECLEN,fp);
			sRecord[RECLEN-1]=0;
			l=strlen(sRecord);
		}
		
		if(feof(fp)) break;
		
		if(item2list(&ptHead,(void *)sRecord,l)<0){
			fclose(fp);
			listfree(&ptHead);
			return -1;
		}
		iCnt++;
	}
	fclose(fp);

	ReverseList((LIST**)&ptHead);
	
	*pptHead=ptHead;
	
	return iCnt;
}
