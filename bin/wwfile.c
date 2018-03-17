#include <unistd.h>
#include "hnixs.h"
#include "list.h"
#include <wwlog.h>
#include <sys/ioctl.h>
#include "wwdir.h"
#include "wwnet.h"
#include "wwtiny.h"
#include "wwfile.h"

struct FileSwitchStruct *pFileSwitchList=NULL;
char sParaFileName[256];

FILE *OpenFileRead(char sFileName[])
{
	return hfopen(sFileName,"rb");
}
FILE *OpenFileWrite(char sFileName[])
{
	return hfopen(sFileName,"w");
}
FILE *OpenFileAppend(char sFileName[])
{
	return hfopen(sFileName,"a");
}

void CloseFile(FILE *fp)
{
	hfclose(fp);
}

int SeekFile(FILE *fp,int4b iPos)
{
	if(fseek(fp,iPos,SEEK_SET)==-1)
		return -1;
	return 0;
}

void SetBufferFile(FILE *fp,int4b iSize,char sBuffer[])
{
	setvbuf(fp,sBuffer,_IOFBF,iSize);
}

int ReadFile(FILE *fp,void *Buf, int iSize)
{
	if(fread(Buf,iSize,1,fp)!=1)
		return -1;
	return 0;
}

int WriteFile(FILE *fp,void *Buf, int iSize)
{
	if(fwrite(Buf,iSize,1,fp)!=1)
		return -1;
	return 0;
}

int Print2File(FILE *fp,char *fmt, ...)
{
	int4b l;

	char sMessage[8192];
	va_list	argptr;

	va_start(argptr, fmt);
	if((l=vsprintf(sMessage,fmt, argptr))<0){
		va_end(argptr);
		return -1;
	}
	va_end(argptr);

	if(l!=fprintf(fp,sMessage))
		return -1;

	return 0;
}

int ReadLine(FILE *fp,char *Buf, int4b iMax)
{
	if(fgets(Buf,iMax,fp)==NULL)
		return -1;
	return 0;
}

int WriteLine(FILE *fp,char *Buf)
{

	if(fputs(Buf,fp)==EOF)
		return -1;
	return 0;
}


int4b FileSize(char sFileName[])
{
	struct	stat s;

	if(stat(sFileName, &s)<0)return -1;

	return (int4b)s.st_size;
}
time_t FileModifyTime(char sFileName[])
{
	struct	stat s;

	if(stat(sFileName, &s)<0)return -1;

	return s.st_mtime;
}
int4b FileLine(char sFileName[])
{
	FILE* fp;
	int iCount=0;

	if((fp=fopen(sFileName,"r"))==NULL) return -1;

	while(!feof(fp))
		if(fgetc(fp)=='\n') iCount++;
	fclose(fp);
	return iCount;
}
int IsFile(char sName[])
{
	FILE *fp;

	if((fp=fopen(sName,"r"))==NULL) return FALSE;
	fclose(fp);

	return TRUE;
}
int Rename(char sTempName[],char sTargetName[])
{
	if(rename(sTempName,sTargetName)!=0) return -1;
	return 0;
}
int Remove(char sFileName[])
{
	if(unlink(sFileName)!=0) return -1;
	return 0;
}
int AddFileExtName(char sFileName[],char sExt[])
{
	char sTargetName[256];
	sprintf(sTargetName,"%s.%s",sFileName,sExt);
	
	return Rename(sFileName,sTargetName);
}
int PrintLog(char sFileName[],char *fmt, ...)
{
	int4b l;
	FILE *fp;

	char sMessage[8192];
	va_list	argptr;

	if((fp=OpenFileAppend(sFileName))==NULL)
		return -1;

	va_start(argptr, fmt);
	if((l=vsprintf(sMessage,fmt, argptr))<0){
		va_end(argptr);
		CloseFile(fp);
		return -1;
	}
	va_end(argptr);

	if(l!=fprintf(fp,sMessage)){
		CloseFile(fp);
		return -1;
	}

	CloseFile(fp);

	return 0;
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
int item2listtail(struct FileControlStruct **ppHead,void *pData,int iLen)
{
	struct FileControlStruct *pTemp,*ptHead;

	if((pTemp=malloc(sizeof(struct FileControlStruct)+iLen))==NULL){
		listfree(ppHead);
		return -1;
	}

	pTemp->pData=(void*)(pTemp+1);

	pTemp->pNext=NULL;
	pTemp->iLen=iLen;
	memcpy(pTemp->pData,pData,iLen);

	if(*ppHead==NULL){
		InsertList((LIST**)ppHead,(LIST*)pTemp);
		return 0;
	}
	ptHead=*ppHead;
	while(ptHead->pNext!=NULL) ptHead=ptHead->pNext;

	InsertList((LIST**)&(ptHead->pNext),(LIST*)pTemp);

	return 0;
}
int item2errorlist(struct FileControlStruct **ppHead,char sCode[5],
	void *pData,int iLen)
{

	struct FileControlStruct *pTemp;

	if((pTemp=malloc(sizeof(struct FileControlStruct)+iLen))==NULL){
		listfree(ppHead);
		return -1;
	}

	pTemp->pData=(void*)(pTemp+1);

	pTemp->pNext=NULL;
	pTemp->iLen=iLen;


	memcpy(pTemp->pData,pData,iLen-5);
	memcpy((char*)(pTemp->pData)+iLen-5,(void *)sCode,4);

	((char*)(pTemp->pData))[iLen-1]='\n';

	InsertList((LIST**)ppHead,(LIST*)pTemp);

	return 0;
}
/*控制文件支持*/
int item2List(LIST **ppHead,LIST *pData,int l)
{
	LIST *pTemp;

	if((pTemp=(LIST*)malloc(l))==NULL) return -1;

	memcpy((void*)pTemp,(void*)pData,l);

	InsertList(ppHead,pTemp);

	return 0;
}
int item2ListTail(LIST **ppHead,LIST *pData,int l)
{
	LIST *pTemp,*ptHead;

	if((pTemp=(LIST*)malloc(l))==NULL) return -1;

	memcpy((void*)pTemp,(void*)pData,l);


	if(*ppHead==NULL){
		InsertList((LIST**)ppHead,(LIST*)pTemp);
		return 0;
	}
	ptHead=*ppHead;
	while(ptHead->pNext!=NULL) ptHead=ptHead->pNext;

	InsertList((LIST**)&(ptHead->pNext),(LIST*)pTemp);

	return 0;
}
int list2fpcomm(struct FileControlStruct **pptHead,FILE *fp,int type)
{
#define FILEBUFLEN	1024*1024
	int iCnt=0,iLen;
	char sFileBuffer[FILEBUFLEN],sFileLine[8192],sTail[2];
	struct FileControlStruct *pTemp,*ptHead=(*pptHead);

	if(ptHead==NULL){
		fclose(fp);
		return 0;
	}

	if(type==RETURN_INTERNAL){iLen=0;sTail[0]=sTail[1]=0;}
	else if(type==RETURN_UNIX){iLen=1;sTail[0]='\n';sTail[1]=0;}
	else{iLen=2;sTail[0]='\r';sTail[1]='\n';}

	setvbuf(fp,sFileBuffer,_IOFBF,FILEBUFLEN);

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		memcpy((void*)sFileLine,pTemp->pData,pTemp->iLen);
		sFileLine[pTemp->iLen] =sTail[0];
		sFileLine[pTemp->iLen+1] =sTail[1];
		if(fwrite(sFileLine,pTemp->iLen+iLen,1,fp)!=1){

			listfree(pptHead);
			fclose(fp);
			return -1;
		}
		iCnt++;
	}
	listfree(pptHead);
	fclose(fp);
	return iCnt;
}
int list2filecomm(struct FileControlStruct **pptHead,char sFileName[],
	int type)
{
	FILE *fp;
	int iCnt=0;

	/* 2001/10/08 zsx Add  */
	if(strchr(sFileName,'/')!=NULL){
		if(CheckDir(sFileName) < 0){
			listfree(pptHead);
			return -1;
		}
	}

	if((fp=fopen(sFileName,"w"))==NULL){
		listfree(pptHead);
		perror(sFileName);
		return -1;
	}
	iCnt=list2fpcomm(pptHead,fp,type);

	return iCnt;
}
int list2fdcomm(struct FileControlStruct **pptHead,int iFd,int type)
{
	int iCnt;
	FILE *fp;

	if(*pptHead==NULL) return 0;

	if((fp=fdopen(iFd,"w"))==NULL){
		listfree(pptHead);
		printf("打开文件描述符 %d错误.\n",iFd);
		return -1;
	}
	iCnt=list2fpcomm(pptHead,fp,type);

	return iCnt;
}
int list2fdln(struct FileControlStruct **pptHead,int iFd)
{
	return list2fdcomm(pptHead,iFd,RETURN_UNIX);
}
int list2fdlrn(struct FileControlStruct **pptHead,int iFd)
{
	return list2fdcomm(pptHead,iFd,RETURN_DOS);
}
int list2fd(struct FileControlStruct **pptHead,int iFd)
{
	return list2fdcomm(pptHead,iFd,RETURN_INTERNAL);
}
int list2file(struct FileControlStruct **pptHead,char sFileName[])
{
	return list2filecomm(pptHead,sFileName,RETURN_INTERNAL);
}
int list2fileln(struct FileControlStruct **pptHead,char sFileName[])
{
	return list2filecomm(pptHead,sFileName,RETURN_UNIX);
}
int list2filelrn(struct FileControlStruct **pptHead,char sFileName[])
{
	return list2filecomm(pptHead,sFileName,RETURN_DOS);
}
int wwfgets(char sRecord[],int iBufLen,FILE* fp)
{
	int i=0;

	while(!feof(fp)){
		sRecord[i]=fgetc(fp);
		if(sRecord[i]=='\r') continue;
		if (sRecord[i]=='\n') break;
		i++;
		if (i>=iBufLen) break;
	}
	sRecord[i]=0;
	return i;
}
int fdgetc(int fd)
{
	char sTemp[1];

	read(fd,sTemp,1);

	return (int )sTemp[0];
}
int wwfdgets(char sRecord[],int iBufLen,int fd)
{
	int i=0;

	while(FD_DataReady(fd)){
		if(read(fd,&sRecord[i],1)==0) break;
		if(sRecord[i]=='\r') continue;
		if (sRecord[i]=='\n') break;
		i++;
		if (i>=iBufLen) break;
	}
	sRecord[i]=0;
	return i;
}
/*
iRecLen<0	表示文本
iRecLen>0	定长文件
*/
int file2list(char sFileName[],int iHeadLen,int iRecLen,
	int iTailLen,struct FileControlStruct **pptHead)
{
#define FILEBUFLEN	1024*1024
#define RECLEN		8192

	FILE *fp;
	int iCnt=0,l,iSize;
	char	sRecord[RECLEN],sFileBuffer[FILEBUFLEN];
	struct FileControlStruct *ptHead=NULL;

	*pptHead=NULL;

	if(iRecLen>0){
		ERROR_RETURNB((iRecLen>=RECLEN),
			"参数长度%d,大于最大长度%d，非法调用",iRecLen,RECLEN);
		ERROR_RETURNA(((iSize=FileSize(sFileName))<0),
			"文件%s不可访问-STAT",sFileName);
/*
		ERROR_RETURNC((iSize%iRecLen!=0)&&iHeadLen!=0,
			"文件%s字节数目%d,记录数%d不匹配",
			sFileName,iSize,iRecLen);
*/
	}
	ERROR_RETURNA(((fp=fopen(sFileName,"r"))==NULL),
		"文件%s不可访问-FOPENREAD",sFileName);
	l=iRecLen;

	setvbuf(fp,sFileBuffer,_IOFBF,FILEBUFLEN);
	if(iHeadLen>0)/*如果需要跳过文件头则跳吧*/
		fseek(fp,iHeadLen,SEEK_SET);

	while(!feof(fp)){

		if(iRecLen>0){
			fread((void*)sRecord,iRecLen,1,fp);
		}
		else{
			l=wwfgets(sRecord,RECLEN,fp);
			ERROR_RETURNA((l<0),"文件%s 非文本文件",sFileName);
			if(l==0) continue;
			sRecord[RECLEN-1]=0;
		}

		if(feof(fp)) break;

		if(item2list(&ptHead,(void *)sRecord,l)<0){
			PushErrStackB("内存错误FILECONTROL文件%s长度%d",
				sFileName,l);
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
long WriteListFilePos(char sFileName[],struct FileControlStruct *p,long iPos)
{
	FILE *fp;
	struct FileControlStruct *ptHead=p,*pTemp;

	if(iPos==0){
		if((fp=fopen(sFileName,"wb"))==NULL){
			WriteAlertMsg("建立文件%s错误",sFileName);
			WriteAlertMsg("可能没有权限,或路径不存在");
			perror(sFileName);
			return -1;
		}
	}
	else{
		if((fp=fopen(sFileName,"r+"))==NULL){
			WriteAlertMsg("追加文件%s错误",sFileName);
			WriteAlertMsg("可能文件被以外删除,不存在文件");
			perror(sFileName);
			return -1;
		}
	}

	if(fseek(fp,iPos,SEEK_SET)==-1){
		WriteAlertMsg("定位文件%s错误,%ld", sFileName,iPos);
		fclose(fp);
		return -1;
	}

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(fwrite(pTemp->pData,pTemp->iLen,1,fp)!=1){

			fclose(fp);
			return -1;
		}
		iPos+=pTemp->iLen;
	}

	fclose(fp);

	return iPos;
}

/*定位写文件支持*/
void InsertFileSwitch(struct FileSwitchStruct *ptCur)
{
	ptCur->pNext=pFileSwitchList;
	pFileSwitchList=ptCur;
}
int SearchFileSwitch(struct FileSwitchStruct *pTemp,
	struct FileSwitchStruct **pptCur)
{
	struct FileSwitchStruct *ptHead=pFileSwitchList;

	*pptCur=NULL;
	while(ptHead!=NULL){
		if(pTemp->iSourceID==ptHead->iSourceID&&
			strcmp(pTemp->sCurFileName,ptHead->sCurFileName)==0&&
			strcmp(pTemp->sStep,ptHead->sStep)==0){

			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void ArchFileSwitch(struct FileSwitchStruct *ptCur)
{
	ptCur->iLastPos=ptCur->iPos;
	ptCur->iLastHandleCnt=ptCur->iHandleCnt;
}
void ResetFileSwitch(struct FileSwitchStruct *ptCur)
{
	ptCur->iPos=ptCur->iLastPos;
	ptCur->iHandleCnt=ptCur->iLastHandleCnt;
}
void GetBaseName(char sFileName[],char sBaseName[])
{
	char *p;

	if((p=(char *)strrchr(sFileName,'/')) != NULL)
		strcpy(sBaseName,p+1);
	else	strcpy(sBaseName,sFileName);
}
void GetBaseNameX(char sFileName[],char sBaseName[])
{
	GetBaseName(sFileName,sBaseName);

	if(RLike(sBaseName,".tmp")) sBaseName[strlen(sBaseName)-4]=0;
}
void GetExtName(char sFileName[],char sExtName[])
{
	char *pc;

	if((pc=strrchr(sFileName,'.'))!=NULL){
		pc++;
		strcpy(sExtName,pc);
	}
	else	strcpy(sExtName,"");
}
void GetPathName(char sFileName[],char sPathName[])
{
	char *p;

	if((p=(char *)strrchr(sFileName,'/')) != NULL){
		strncpy(sPathName,sFileName,p-sFileName+1);
		sPathName[p-sFileName+1]=0;
	}
	else	strcpy(sPathName,"");
}

/* 读取配置表中的数据 */
/*配置表的写法如下*/
/*
{cdmabilling} #BLOCK
[login]        #sSection
loginname= cdma            #sItem and sResult
*/
int ReadString(char *sFilename,char *sBlock,char *sSection,char *sItem,char *sResult)
{
   FILE * fpINI;
   char  sLine[256];
   char *sTemp,*pTemp;

   strcpy(sResult,"");

   fpINI = fopen(sFilename ,"r");
   if(fpINI == NULL)    return -1;

   while(1){
   	fgets(sLine,256,fpINI);
   	if(feof(fpINI)){
   		fclose(fpINI);
   		return 0;
   	}
   	sTemp = sLine;
   	while( (*sTemp)==' ' || (*sTemp)=='\t' )
   	  sTemp++;      /*skip space and tabs*/
   	if( *sTemp != '{' || *(sTemp+1)!='$')
   	  continue;
   	sTemp++;
   	sTemp++;
   	if(strncasecmp(sTemp,sBlock,strlen(sBlock))!=0)
   	  continue;
   	sTemp+=strlen(sBlock);
   	if(*sTemp!='}')
   	  continue;

   	/*block has beed found*/
   	while(1){
   		fgets(sLine,256,fpINI);
   		if(feof(fpINI)){
   			fclose(fpINI);
   			return 0;
   		}
   		sTemp =  sLine;
   		while( (*sTemp)==' '|| (*sTemp)=='\t')
   		  sTemp++;

   		if( *sTemp == '{' && *(sTemp+1)=='$'){
   			fclose(fpINI);
   			return 0;       /*this is the next block*/
   		}
   		if( *sTemp!='[')
   		  continue;
   		sTemp++;
   		if(strncasecmp(sTemp,sSection,strlen(sSection))!=0)
   		  continue;

   		sTemp+=strlen(sSection);
   		if( *sTemp !=']')
   		  continue;

   		while(1){
   			strcpy(sLine,"");
   			fgets(sLine,256,fpINI);
   			sTemp = sLine;

   			while( *sTemp==' '|| *sTemp=='\t')
   			  sTemp++;

   			if(*sTemp == '[' || (*sTemp=='{' && *(sTemp+1)=='$') ){
   				fclose(fpINI);
   				return 0;
   			}

   			if(strncasecmp(sTemp,sItem,strlen(sItem))!=0){
	   			if(feof(fpINI)){
   					fclose(fpINI);
   					return 0;
   				}
   			  	continue;
   			}
   			sTemp+=strlen(sItem);

   			while( *sTemp == ' '||*sTemp=='\t')
   			  sTemp++;

   			if(*sTemp!= '=' ){
	   			if(feof(fpINI)){
   					fclose(fpINI);
   					return 0;
   				}
   			  	continue;
   			}
   			sTemp++;

   			fclose(fpINI);

   		/* add by hty trim and ignore comment. */
   		        pTemp=strchr(sTemp,'#');
                        if(pTemp!=NULL)*pTemp=0;

   		        pTemp=strchr(sTemp,'\n');
                        if(pTemp!=NULL)*pTemp=0;

                        AllTrim(sTemp);
                /* add ok */
                        strcpy(sResult,sTemp);
   			return 1;
   		}
   	}
   }
   return 0;
}
int GetTtyName(char sName[])
{
	FILE *fp;
	char sTemp[256];

	strcpy(sName,"");
	if((fp=popen("tty","r"))==NULL)
		return -1;
	fgets(sTemp,sizeof(sTemp),fp);
	fclose(fp);
	sTemp[strlen(sTemp)-1]=0;/*去掉回车*/

	strcpy(sName,sTemp);

	return 0;
}
FILE *RedirectFp(FILE *fp,char sName[])
{
	return freopen(sName,"w",fp);
}
int GetSockBufLen(int iSockFd)
{
	int iLen=0;

	if(ioctl(iSockFd,FIONREAD,&iLen)==-1) return -1;

	return iLen;
}

int exec2str(char sCommand[256],char sReturn[1024])
{
	FILE *fp;
	int l;

	strcpy(sReturn,"");

	fp=popen(sCommand,"r");
	l=fread(sReturn,1,1024,fp);
	if(l<0||l>=1024) return -1;
	sReturn[l]=0;

	return pclose(fp);
}
int exec2list(char sCommand[256],struct FileControlStruct **pptHead)
{
	FILE *fp;
	int l;
	char sRecord[1024];

	*pptHead=NULL;

	fp=popen(sCommand,"r");

	while(!feof(fp)){
		if((l=wwfgets(sRecord,1024,fp))==0) continue;
		if(!isascii(sRecord[0])) continue;
		if(item2list(pptHead,(void*)sRecord,l)<0) return -1;
	}

	ReverseList((LIST**)pptHead);

	if((l=pclose(fp))!=0) listfree(pptHead);
	
	return l;
}
int FileLines(char sFileName[])
{
	char sCommand[1024],sInput[1024];

	if(FileSize(sFileName)<0) return -1;

	sprintf(sCommand,"wc -l %s",sFileName);

	if(exec2str(sCommand,sInput)!=0) return -1;

	return atoi(sInput);

}
int execcmd(char *fmt,...)
{
	va_list	argptr;
	char sCommand[1024];

	va_start(argptr, fmt);
	vsprintf(sCommand,fmt, argptr);
	va_end(argptr);

	return system(sCommand);
}
int PrintTiny(char sFileName[],char *fmt, ...)
{
	FILE *fp;

	char sMessage[8192];
	va_list	argptr;

	if((fp=fopen(sFileName,"w"))==NULL)
		return -1;

	va_start(argptr, fmt);
	if(vsprintf(sMessage,fmt, argptr)<0){
		va_end(argptr);
		fclose(fp);
		return -1;
	}
	fprintf(fp,sMessage);

	va_end(argptr);
	fclose(fp);
	return 0;
}
int PatternMatch(char sFileName[],char sFilter[])
{
	char sCommand[256],sResult[1024];

/*做一个异常检测*/
	if(strlen(sFileName)==0||
		strlen(sFilter)==0) return false;

	sprintf(sCommand,"case %s in %s) echo \"1\" ;; *) echo \"0\";; esac",
		sFileName,sFilter);
	
	if(exec2str(sCommand,sResult)!=0) return false;
	if(atoi(sResult)==1) return true;
	return false;
}

int ReadFileToBuf(char sFileName[],int iMaxLen,char sInput[],char sMessage[])
{
	int l;
	FILE *fp;
	
	strcpy(sMessage,"");
	
	if(IsFile(sFileName)==FALSE){
		sprintf(sMessage,"文件 %s不存在",sFileName);
		return -1;
	}

	if((l=FileSize(sFileName))>=iMaxLen){
		sprintf(sMessage,"文件%s超过%d字节",sFileName,iMaxLen);
		return -1;
	}
	if((fp=fopen(sFileName,"r"))==NULL){
		sprintf(sMessage,"打开文件%s失败",sFileName);
		return -1;
	}
	if(fread(sInput,l,1,fp)!=1){
		sprintf(sMessage,"读文件%s失败",sFileName);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);
	return l;
}
int PingIpOk(char sIp[])
{
	char sResult[1024],sCommand[256];
		
	sprintf(sCommand,"ping -c 2 %s | grep 100%c | wc -l 2>/dev/null",
		sIp,'%');
	exec2str(sCommand,sResult);
	if(atoi(sResult)==0) return true;
	return false;
}

int TxtFileToList(char sFileName[],struct FileControlStruct **pptHead)
{
	return file2list(sFileName,0,-1,0,pptHead);
}
int TxtFileToListX(char sFileName[],int iHead,int iTail,
	struct FileControlStruct **pptHead)
{
	struct FileControlStruct *ptLkHead=NULL,*pHead,*pTail,*pTemp;
	

	if(file2list(sFileName,0,-1,0,&ptLkHead)<0) return -1;
	
	pHead=*pptHead=ptLkHead;
	if(pHead==NULL) return -1;
	
	if(iHead!=0){
		*pptHead=pHead->pNext;
		free(pHead);
	}
	
	pTail=*pptHead;
	
	if(pTail==NULL) return 0;
	
	while(pTail->pNext!=NULL) pTail=pTail->pNext;
	
	if(iTail!=0){
		pTemp=*pptHead;
		if(pTemp!=pTail){
			while(pTemp->pNext!=pTail)pTemp=pTemp->pNext;
			pTemp->pNext=NULL;
		}
		else	*pptHead=NULL;

		free(pTail);
	}
	return 0;
}
int TxtttFileToList(char sFileName[],struct FileControlStruct **pptHead)
{
	int	iPos=0,iCnt=0,iRecLen;
	char	sRecord[8192],sTemp[128];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pBlockHead=NULL,*pRecord=NULL;

	ERROR_RETURNA(file2list(sFileName,0,-1,0,&pBlockHead)<0,
		"文件%s导入链表错误",sFileName);
	
	ptHead=pBlockHead;
	
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iRecLen=pTemp->iLen;
		strncpy(sTemp,(char*)(pTemp->pData),pTemp->iLen);
		strncpy(sRecord+iPos,sTemp,iRecLen);
		
		iPos+=iRecLen; 
		/*行行间目前用'|'间隔*/
		strcpy(sRecord+iPos,"|");
		iPos++;
		if(iPos>2048){
			PushErrStackB("文件%s长度%d,过长",
				sFileName,iPos);
			return -1;
		}
			
		iCnt++;
			
	}
	
	sRecord[iPos]='\n';
	iPos++;

	if(item2list(&pRecord,(void *)sRecord,iPos)<0){
		listfree(&pBlockHead);
		listfree(&pRecord);
		PushErrStackB("分配内存错误文件%s长度%d",
			sFileName,iRecLen);
		return -1;
	}

	
	listfree(&pBlockHead);
	
	ReverseList((LIST**)&pRecord);
	
	*pptHead=pRecord;
	
	return iCnt;		
}
int BinFixFileToList(char sFileName[],int iHeadLen,int iRecLen,int iTailLen,
	struct FileControlStruct **pptHead)
{
	return file2list(sFileName,iHeadLen,iRecLen,iTailLen,pptHead);
}
int BlkFixFileToList(char sFileName[],int iHeadLen,int iRecLen,int iTailLen,
	struct FileControlStruct **pptHead)
{
	int	iPos,iCnt=0;
	char	sRecord[8192];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pBlockHead=NULL,*pRecord=NULL;

	ERROR_RETURNA(file2list(sFileName,0,2048,0,&pBlockHead)<0,
		"文件%s导入链表错误",sFileName);
	
	ptHead=pBlockHead;
	
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iPos=iHeadLen;
		while(iPos<pTemp->iLen){
			
			if((iPos+iRecLen)>pTemp->iLen) break;
			
			memcpy((void*)sRecord,(char*)(pTemp->pData)+iPos,iRecLen);
			iPos+=iRecLen;
			
			if(item2list(&pRecord,(void *)sRecord,iRecLen)<0){
				listfree(&pBlockHead);
				listfree(&pRecord);
				PushErrStackB("分配内存错误文件%s长度%d",
					sFileName,iRecLen);
				return -1;
			}
			iCnt++;
		}
			
	}
	
	listfree(&pBlockHead);
	
	ReverseList((LIST**)&pRecord);
	
	*pptHead=pRecord;
	
	return iCnt;	
}
int AsnFileToList(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead)
{
	int	iPos,iRet,iCnt=0,iRecLen;
	char	sRecord[8192];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pBlockHead=NULL,*pRecord=NULL;
	
	*pptHead=NULL;
	
	if(DynFileToBlockHead(sFileName,pFormat,&pBlockHead)<0) return -1;	

	ptHead=pBlockHead;
	
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iPos=0;
		while(iPos<pTemp->iLen){
			
			iRet=GetAsnRecord(iPos,pTemp->iLen,
				pTemp->pData,sRecord,&iRecLen);
			if(iRet<0){
				listfree(&pBlockHead);
				listfree(&pRecord);
				if(pFormat->Blk.iRecLen>0){
					PushErrStackB("文件%s位置%d话单错误",
						sFileName,iCnt*pFormat->Blk.iRecLen+iPos);
				}
				else{
					PushErrStackC("文件%s的第%d块,偏移%d位置话单错误",
						sFileName,iCnt,iPos);
				}
				return -1;
			}
			/*遇到块结束*/
			if(iRet==BLOCK_TAIL) break;
			
			iPos+=iRecLen;
			
			if(item2list(&pRecord,(void *)sRecord,iRecLen)<0){
				listfree(&pBlockHead);
				listfree(&pRecord);
				PushErrStackB("分配内存错误文件%s长度%d",
					sFileName,iRecLen);
				return -1;
			}
			iCnt++;
		}
			
	}
	
	listfree(&pBlockHead);
	
	ReverseList((LIST**)&pRecord);
	
	*pptHead=pRecord;
	
	return iCnt;
}
int AsnHwFileToList(char sFileName[],struct FileControlStruct **pptHead)
{
	FILE *fp;
	int	iPos,iRet,iCnt=0,iRecLen,l,iErrCode=0;
	char	sRecord[8192];
	unsigned char *p=NULL,*pBody;/*这里必须是UNSIGNED CHAR,涉及无符号数的比较*/
	struct AsnStruct a1,a2;
	struct FileControlStruct *pRecord=NULL;
	
	*pptHead=NULL;

	if((l=FileSize(sFileName))<=0) return -1;

        ERROR_RETURNA(((fp=fopen(sFileName,"r"))==NULL),
                "文件%s不可访问-FOPENREAD",sFileName);

	/*分配内存*/
	if((p=malloc(l*2))==NULL) return -1;

	bzero((void*)p,l*2);

	/*将pBody指向特定区域*/
	pBody=p+l;

        fread((void*)p,l,1,fp);
	fclose(fp);

	/*作简单的格式校验,话单必须是30...A3:00*/
	if(!(p[0]==0x30&&p[l-2]==0xA3&&p[l-1]==0x00)){
		printf("华为ASN格式非法,文件必须为30开头且为A3:00结束");
		return -1;
	}

	/*构造ASN解码的链表*/
	a1.pNext=&a2;	a1.iTag= 0x30;	a1.iTagType=0;
	a2.pNext=NULL;	a2.iTag= 0xA1;	a2.iTagType=0;

	if(AsnItem(p,&a1,IA5STRING,pBody,l,&iErrCode)!=FOUND) return -1;
	
	iPos=0;
	while(iPos<l){
			
		iRet=GetAsnRecord(iPos,l,pBody,sRecord,&iRecLen);

		if(iRet<0){
			/*遇到块结束*/
			if(iRet==BLOCK_TAIL) break;
			
			return -1;
		}
		iPos+=iRecLen;
			
		if(item2list(&pRecord,(void *)sRecord,iRecLen)<0){
			listfree(&pRecord);
			PushErrStackB("分配内存错误文件%s长度%d",
				sFileName,iRecLen);
			return -1;
		}
		iCnt++;
			
	}
	
	ReverseList((LIST**)&pRecord);
	
	*pptHead=pRecord;
	
	free(p);

	return iCnt;
}
int NortelFileToList(char sFileName[],struct FileControlStruct **pptHead)
{
	char	*buf;
	int	iPos,iCnt=0,iRecLen,iBlockLen;
	char	sRecord[8192];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pBlockHead=NULL,*pRecord=NULL;
	
	*pptHead=NULL;
	
	ERROR_RETURNA(file2list(sFileName,0,2048,0,&pBlockHead)<0,
		"文件%s导入链表错误",sFileName);
	
	ptHead=pBlockHead;
	
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iPos=0;
		buf=(char*)(pTemp->pData);
		HEX_OCTET_INT4B(buf,2,(void*)&iBlockLen);
		ERROR_RETURNA((iBlockLen>pTemp->iLen),
			"错误块长度%d",iBlockLen);
		iPos+=4;

		while(iPos<iBlockLen){

			HEX_OCTET_INT4B(buf+iPos,2,(void*)&iRecLen);
			if((iRecLen+iPos)>iBlockLen){
				listfree(&pBlockHead);
				listfree(&pRecord);
				PushErrStackB("文件%s位置%d话单错误",
					sFileName,iCnt*2048+iPos);
				return -1;
			}
			iPos+=4;
			iRecLen-=4;
			memcpy((void*)sRecord,(void*)(buf+iPos),iRecLen);
			if(item2list(&pRecord,(void *)sRecord,iRecLen)<0){
				listfree(&pBlockHead);
				listfree(&pRecord);
				PushErrStackB("分配内存错误文件%s长度%d",
					sFileName,iRecLen);
				return -1;
			}
			iPos+=iRecLen;
			iCnt++;
		}
			
	}
	
	listfree(&pBlockHead);
	
	ReverseList((LIST**)&pRecord);
	
	*pptHead=pRecord;
	
	return iCnt;
}

struct LinkProtocalStruct
{
	char sSourceMac[6];
	char sTargetMac[6];
	char sProtocalId[2];
};
struct IpProtocalStruct
{
	char sVerId[2];
	char sPacketLen[2];
	char sIdentifier[2];
	char sFlagFragmentOff[2];
	char sTimeToLive[1];
	char sProtocal[1];
	char sHeadCheckSum[2];
	char sSourceAddress[4];
	char sTargetAddress[4];
};
struct TcpProtocalStruct
{
	char sSourcePort[2];
	char sTargetPort[2];
	char sSeqNo[4];
	char sConfirmNo[4];
	char sHeadLen[1];
	char sFlagSet[1];
	char sWinSize[2];
	char sCheckSum[2];
	char sCriticalPointer[2];
};
int CheckNextPacketOffset(char *p,int iMaxSize,int *piRecLen)
{
	int i=0;
	
	struct LinkProtocalStruct *pl;
	struct IpProtocalStruct   *pi;
	struct TcpProtocalStruct  *pt;
	
	while(i<iMaxSize){
		pl=(struct LinkProtocalStruct *)(p+i);
		if(pl->sProtocalId[0]!=0x08||pl->sProtocalId[1]!=0x0){
			i++;
			continue;
		}
		pi=(struct IpProtocalStruct   *)(p+i+14);
		if(pi->sVerId[0]!=0x45||pi->sVerId[1]!=0x0){
			i++;
			continue;
		}
		*piRecLen+=i;
		return 0;
	}
	return -1;
}
int DynBlockToList(struct FileControlStruct *pTemp,
	struct BlkFmtStruct *pFormat,struct FileControlStruct **pptHead)
{
	int iCnt=0,iPos,iRecLen,iOff=0;
	struct FileControlStruct *ptHead=NULL;
	char *p=(char*)(pTemp->pData);
	
	iPos=pFormat->iHeadLen;
	
	while(iPos<pTemp->iLen){
		
		if(pFormat->iRecLen<=0){
			
			iOff=(pFormat->iLenInHd==0)?iPos:0;
			
			if(pFormat->GetLen((uint1b*)(p+iOff+pFormat->iLenOff),
				pFormat->iLenLen,&iRecLen)<0){

				listfree(&ptHead);
				PushErrStackB("取记录长度错误,偏移%d长度%d",
					pFormat->iLenOff,pFormat->iLenLen);
				return -1;
			}
			if(iRecLen==0){
				pFormat->GetLen((uint1b*)(p+iOff+pFormat->iLenOff)-2,
					pFormat->iLenLen,&iRecLen);
				iPos-=2;
			}
			if(pFormat->pParam!=NULL)/*如果需要转换则转换一下*/
				decodei2i((struct DecodeParamStruct *)(pFormat->pParam),
					iRecLen,(char*)&iRecLen);
		/*	
			if(CheckNextPacketOffset(p+iPos+iRecLen,50,&iRecLen)<0)
				iRecLen+=34;
		*/	
			if(iRecLen<=0||iRecLen>10*1024){
				iPos++;
				/** NOKIA 'ffff','29ff'属于空话单*/
				/*if(iRecLen!=65535){
					printf("hello. iRecLen=%d,iPos=%d,iCnt=%d\n",
					iRecLen,iPos,iCnt);
				}*/
				continue;
			}
		}
		else
			iRecLen=pFormat->iRecLen;

		/*块尾判断,直接跳过*/
		if((iPos+iRecLen)>pTemp->iLen)break;

		if(item2list(&ptHead,(void *)(p+iPos),iRecLen)<0){
			listfree(&ptHead);
			PushErrStackA("分配内存错误长度%d",iRecLen);
			return -1;
		}
		
		iPos+=iRecLen;
		iCnt++;
		
	}
/*将新的话单挂到链表头*/
	if(ptHead==NULL) return 0;
	
	pTemp=ptHead;
	while(pTemp->pNext!=NULL)
		pTemp=pTemp->pNext;
	
	pTemp->pNext=*pptHead;
	*pptHead=ptHead;

	return iCnt;
}
int DynFileToBlockHead(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead)
{
	int	l;
	FILE	*fp;
	char	*p;
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pBlockHead=NULL,*pRecord=NULL;

	l=FileSize(sFileName);	
	ERROR_RETURNA((p=malloc(l))==NULL,"分配字节数为%d的内存失败",l);
	
	ERROR_RETURNA(((fp=fopen(sFileName,"r"))==NULL),
		"文件%s不可访问-FOPENREAD",sFileName);
	fread((void*)p,l,1,fp);
	if(item2list(&pBlockHead,(void *)p,l)<0){
		PushErrStackB("内存错误FILECONTROL文件%s长度%d",
			sFileName,l);
		free(p);
		fclose(fp);
		return -1;
	}
	free(p);
	fclose(fp);
	
	if(pFormat->Blk.iHeadLen!=-1){
		
		ptHead=pBlockHead;
		
		while(ptHead!=NULL){
	
			pTemp=ptHead;
			ptHead=ptHead->pNext;

			if(DynBlockToList(pTemp,&(pFormat->Blk),&pRecord)<0){
				listfree(&pBlockHead);
				listfree(&pRecord);
				PushErrStackB("分配内存错误文件%s长度%d",
					sFileName,pTemp->iLen);
			}
		}
		listfree(&pBlockHead);
		ReverseList((LIST**)&pRecord);
		pBlockHead=pRecord;
		pRecord=NULL;
		
	}
	*pptHead=pBlockHead;
	return 0;
}
int BinDynFileToList(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead)
{
	int	iCnt=0,l;
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pBlockHead=NULL,*pRecord=NULL;

	if(DynFileToBlockHead(sFileName,pFormat,&pBlockHead)<0) return -1;
	
	ptHead=pBlockHead;
	
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((l=DynBlockToList(pTemp,&(pFormat->Rec),&pRecord))<0){
			listfree(&pBlockHead);
			listfree(&pRecord);
			PushErrStackB("分配内存错误文件%s长度%d",
					sFileName,pTemp->iLen);
		}
		iCnt+=l;	
	}
	
	listfree(&pBlockHead);
	
	ReverseList((LIST**)&pRecord);
	
	*pptHead=pRecord;
	
	return iCnt;
}
int BlkDynFileToList(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead)
{
	int	iCnt=0,l;
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pBlockHead=NULL,*pRecord=NULL;


	ERROR_RETURNA(file2list(sFileName,0,2048,0,&pBlockHead)<0,
		"文件%s导入链表错误",sFileName);
	
	ptHead=pBlockHead;
	
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((l=DynBlockToList(pTemp,&(pFormat->Rec),&pRecord))<0){
			listfree(&pBlockHead);
			listfree(&pRecord);
			PushErrStackB("分配内存错误文件%s长度%d",
					sFileName,pTemp->iLen);
			return -1;
		}
		iCnt+=l;	
	}
	
	listfree(&pBlockHead);
	
	ReverseList((LIST**)&pRecord);
	
	*pptHead=pRecord;
	
	return iCnt;
}
void InitParamFileName(char sName[])
{
	strcpy(sParaFileName,sName);
}
char *getParam(const char sName[])
{
	static int iFirst=0;
	static struct nvlist *param=NULL;
	
	if(iFirst==0){
		if(strlen(sParaFileName)==0)
			strcpy(sParaFileName,"./httpd.conf");
		InitParam2NvList(sParaFileName,&param);
		iFirst= 1;
	}
		
	return (char *)getValue(param,sName);
}

char *getValue(struct nvlist *ptHead,const char sName[])
{
	while(ptHead!= NULL){
		
#ifdef DEBUG
		printf("name:%s  value:%s\n",ptHead->sName,ptHead->sValue);
#endif
		
		if(strcasecmp(ptHead->sName,sName)==0){

			return ptHead->sValue;
			break;
		}
		
		ptHead= ptHead->pNext;
	}
	
	return "";
	
}

int InitParam2NvList(char sFileName[],struct nvlist **pptHead)
{
	FILE *fp;
	char sBuff[2048],*p;
	struct nvlist *pTemp;
	
	if((fp=fopen(sFileName,"r"))==NULL){
		printf("打开文件%s失败，请确认文件是否存在！\n",sFileName);
		exit(-1);
	}
	
	while(fgets(sBuff,2048,fp)!= NULL){

	/***去掉行尾回车换行**/
		if(sBuff[strlen(sBuff)-1]=='\n') sBuff[strlen(sBuff)-1]=0;
		if(sBuff[strlen(sBuff)-1]=='\r') sBuff[strlen(sBuff)-1]=0;
	/***去注释行**/		
		if(sBuff[0]==';') continue;
	/***去掉空行*/
		if(strlen(sBuff)==0) continue;
	/***去掉没有=的行*/
		if((p=strstr(sBuff,"="))==NULL) continue;
	/**跳过=号**/
		*p=0; p++;
	/*规格化左又字符串*/
		AllTrim(sBuff);AllTrim(p);
		
		if((pTemp=malloc(sizeof(struct nvlist)))==NULL){
			puts("分配内存失败！");
			exit(-1);
		}
				
		pTemp->sName=strdup(sBuff);
		pTemp->sValue=strdup(p);
		
		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	fclose(fp);
	
	return 0;
}
#ifdef DEBUG
int main()
{
	char sValue[255];	
	puts(PARAM("localip"));
	return 0;
}
#endif

void GetBaseNameFromCtl(struct FileControlStruct *pTemp,char sBaseName[])
{
	int l;
	char sTempName[128];

	if(pTemp->iLen>127) 
		l=127;
	else	l=pTemp->iLen;

	strncpy(sTempName,(char*)pTemp->pData,l);
	sTempName[l]=0;

	AllTrim(sTempName);

	strcpy(sBaseName,sTempName);
}

/*将文件内容读到字符串中，将文件内容的全部读到字符串内，
并在最后添加\0作为结束，如果文件内容有\0则也会读入，在使用的时候
要结合FileSize函数来拿到文件内容的\0后的东西*/
int file2str(char sFileName[],char str[])
{
	int i=0;
	FILE* fp;

	str[i]=0;

	if((fp=fopen(sFileName,"r"))==NULL) return -1;
	
	while(1){
		str[i]=fgetc(fp);
		if(feof(fp)) break;
		i++;
	}

	str[i]=0;

	fclose(fp);

	return i;
}
/*将以\0为结束符的字符串的信息写到特定的文件中，将文件内容覆盖*/
int str2file(char str[],char sFileName[])
{

	int i=0;
	FILE* fp;

	i==strlen(str);

	if((fp=fopen(sFileName,"w"))==NULL) return -1;

	if(fwrite(str,i,1,fp)!=1) return -1;

	fclose(fp);

	return 0;
}
