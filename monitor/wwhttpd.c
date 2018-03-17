#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <signal.h>
#include <errno.h>
#include <sys/param.h>
#include <stdarg.h>
#include <sys/wait.h>

#include <sys/types.h>
#include <dirent.h>
#include <time.h>

#include <list.h>
#include <wwfile.h>

#include "wwhttpd.h"

/*��ʱ*/
int TIMEOUT=20;

int SendFile(int iSockFd,struct HttpRequestStruct *r,
	char sFileName[],char sMimeType[],int iSendHead);
void ProcAlarm(int signo);

/*�����ո񣬿ɸ�Ϊ��*/
void SkipBlank(char **pHead)
{
	char *p=(*pHead);

	while(isspace(*p)) p++;

	*pHead= p;
}

int ParseItem(char **ppDesc,char **ppBuff)
{
	char *pHead,*pCur;

	pHead=(*ppBuff);
	SkipBlank(&pHead);
	pCur= pHead;

	/*������"�ո�"Ϊ�����Ĵ�*/
	while(!isspace(*pCur)) pCur++;
	*pCur++= '\0';
	SkipBlank(&pCur);

	if((*ppDesc=strdup(pHead))==NULL) return -1;

	*ppBuff= pCur;

	return 0;
}
void SetTimeOut(int seconds)
{
	signal(SIGALRM,ProcAlarm);
	alarm(seconds);
}

void CleanTimeOut(void)
{
	alarm(0);
	signal(SIGALRM,SIG_IGN);
}

void ProcAlarm(int signo)
{
	CleanTimeOut();
	errno= ETIME;
}

int ParseRequestInfo(char **pptHead,struct HttpRequestStruct *r)
{
	char *p;

	/*����Method*/
	if(ParseItem(&(r->sMode),pptHead)!=0) return -1;

	/*�����ļ�����query_string,�ȱ�������query_string��
		Ȼ�󽫣���Ϊ\0,query_stringָ����������*/
	if(ParseItem(&(r->sFileName),pptHead)!=0) return -1;

	/*Query_String*/
	if((p=strchr(r->sFileName,'?'))!=NULL){
		*p++= '\0';
		r->sQryStr= p;
	}

	/*����http�汾��*/
	if(ParseItem(&(r->sVersion),pptHead)!=0) return -1;

	return 0;
}

int ParseRequestOptions(int iSockFd,char *pBuffer,int iBufLen,
	char **pptHead,struct HttpRequestStruct *r)
{
	struct nvlist *pTemp;
	char *p,*pLine=NULL;

	/*���û��ѡ����ֱ��pass*/
	if((*pptHead)==pBuffer+iBufLen) return 0;

	/*�˳���������������\r\n*/
	while(1){

		pLine= NULL;

		if((p=strstr((*pptHead),"\r\n"))!=NULL){
			*p=0;p+=2;/*ָ����һ��*/
			pLine=(*pptHead);
			(*pptHead)=p;
		}
		else{
			char *pTmp;
			int iRet,iLen;

			/*Buffer��û�ҵ�httpͷ�Ľ���\r\n���socket�ж�ȡ*/
			iLen=iBufLen-((*pptHead)-pBuffer);
			if(iLen==iBufLen) return -1;

			memmove(pBuffer,(*pptHead),iLen);
			(*pptHead)=pBuffer;
			pTmp= pBuffer + iLen;
			iLen= iBufLen - iLen;

			SetTimeOut(PARAMI("Timeout"));
			iRet= read(iSockFd,pTmp,iLen);
			CleanTimeOut();

			if(iRet<=0)return -1;
			pTmp[iRet]= '\0';
		}

		if(pLine==NULL)	continue;

		/*\r\n��ʾhttpͷ������ָ����ͬ��ȡ��ͷ����*/
		if(strlen(pLine)==0) break;

		/*������,����http options*/
		if((p=strstr(pLine,": "))!=NULL){

			*p=0;p+=2;

			if((pTemp=malloc(sizeof(struct nvlist)))==NULL){
				perror("Malloc");
				return -1;
			}

			pTemp->sName=	strdup(pLine);
			pTemp->sValue=	strdup(p);

			if(pTemp->sName==NULL||pTemp->sValue==NULL){
				free(pTemp->sValue);
				free(pTemp->sName);
				free(pTemp);
				return -1;
			}
			InsertList((LIST**)&(r->pOptList),(LIST*)pTemp);
			r->iOptCnt++;

		}
	}
	/*
	{

		struct nvlist *pTemp,*ptHead=r->pOptList;
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead= ptHead->pNext;
			printf("%d,itra:N%s\t\tV:%s\n",r->iOptCnt,pTemp->sName,pTemp->sValue);
		}
	}
	*/

	return 0;
}

void SendTxt(int iSockFd,const char *fmt,...)
{
	char buffer[2048];
	va_list ap;

	va_start(ap,fmt);
	vsnprintf(buffer,sizeof(buffer)-1,fmt,ap);
	va_end(ap);

	write(iSockFd,buffer,strlen(buffer));
}

void SendHead(int iSockFd,int iState,char sTitle[],char sMimeType[],int iBodyLen)
{
	if(!iState) iState=200;
	SendTxt(iSockFd,"HTTP/1.1 %d %s\r\n",iState,sTitle);
	SendTxt(iSockFd,"Server: %s\r\n",PARAM("ServerName"));
	if(iBodyLen>0)
		SendTxt(iSockFd,"Content-Length: %d\r\n",iBodyLen);
	SendTxt(iSockFd,"Content-Type: %s\r\n\r\n",sMimeType);
}
/**��һ����λ��16���Ƶ�ASCII��ת��Ϊһ��16������**/
int hex2int(char *pChars)
{
	int Hi,Lo,Result;

	Hi=pChars[0];
	if('0'<=Hi&&Hi<='9')	Hi-='0';
	else if('a'<=Hi&&Hi<='f')Hi-=('a'-10);
	else if('A'<=Hi&&Hi<='F')Hi-=('A'-10);

	Lo= pChars[1];
	if('0'<=Lo&&Lo<='9')	Lo-='0';
	else if('a'<=Lo&&Lo<='f')Lo-=('a'-10);
	else if('A'<=Lo&&Lo<='F')Lo-=('A'-10);


	Result=Lo+(16*Hi);

	return(Result);
}
void decodeurl(char *pEncoded)
{
	char *pDecoded;

	pDecoded=pEncoded;
	while(*pDecoded) {
		if(*pDecoded=='+') *pDecoded=' ';
		pDecoded++;
	}

	pDecoded=pEncoded;
	while(*pEncoded){
		if(*pEncoded=='%'){
			pEncoded++;
			if(isxdigit(pEncoded[0])&&isxdigit(pEncoded[1])){
				*pDecoded++=(char)hex2int(pEncoded);
				pEncoded+=2;
			}
		}
		else
			*pDecoded++=*pEncoded++;
	}
	*pDecoded='\0';
}

int ListDir(int iSockFd,struct HttpRequestStruct *r,char sDirName[])
{
	time_t t;
	struct stat sb;
	DIR *handle;
	struct dirent *dentry=NULL;
	char file[PATH_MAX+1],sDateTime[1024],showfile[1024];

	while((sDirName[strlen(sDirName)-1]=='\\')||(sDirName[strlen(sDirName)-1]=='/'))
	{ sDirName[strlen(sDirName)-1]='\0'; };

	t=time((time_t*)0);
	strftime(sDateTime,sizeof(sDateTime),"%b %d %H:%M:%S",localtime(&t));
	SendHead(iSockFd,200,"","text/html; charset=gb2312",-1);

	SendTxt(iSockFd,"<html><head><title>Index of %s</title>\
		<link href=\"/style/main.css\" rel=\"stylesheet\" type=\"text/css\">\
		</head><body>",r->sFileName);
	SendTxt(iSockFd,"<CENTER>\n<TABLE borderColor=#339933 cellSpacing=0 \
		borderColorDark=#ffffff cellPadding=0 align=center\
		 borderColorLight=#000000 border=1 WIDTH=90%%>\n");
	SendTxt(iSockFd,"<TR BGCOLOR=#0099000><TH COLSPAN=3><font color=white>Index of %s</font></TH></TR>\n",r->sFileName);
	SendTxt(iSockFd,"<TR BGCOLOR=#E0E0E0>");
	SendTxt(iSockFd,"<TH width=20%%>Filename</TH><TH width=10%%>Size</TH>");
	SendTxt(iSockFd,"<TH width=10%%>Date</TH></TR>\n");

        if((handle=opendir(sDirName))==NULL)return -1;

	while((dentry=readdir(handle))!=NULL) {
		snprintf(file,sizeof(file)-1,"%s/%s",sDirName,dentry->d_name);
		stat(file,&sb);
		if(strcmp(".",dentry->d_name)==0) continue;
		if(strcmp("..",dentry->d_name)==0) {
			SendTxt(iSockFd,"<TR BGCOLOR=#F0F0F0><TD COLSPAN=3><IMG SRC=/images/foldero.gif>");
			SendTxt(iSockFd,"<A HREF=%s/>Parent Directory</A></TD>\n",dentry->d_name);
			continue;
		}
		strftime(sDateTime,sizeof(sDateTime),"%Y-%m-%d %H:%M",localtime(&sb.st_mtime));
		memset(showfile,0,sizeof(showfile));
		snprintf(showfile,sizeof(showfile)-1,"%s",dentry->d_name);
		SendTxt(iSockFd,"<TR BGCOLOR=#F0F0F0><TD ALIGN=left NOWRAP>");

		if(sb.st_mode&S_IFDIR) {
			SendTxt(iSockFd,"<IMG SRC=/images/folder.gif>&nbsp;<A HREF=\"");
			SendTxt(iSockFd,"%s/",showfile);
			SendTxt(iSockFd,"\"/>%s/</A></TD>",dentry->d_name);
		}
		else {
			SendTxt(iSockFd,"<IMG SRC=/images/default.gif>&nbsp;<A HREF=\"");
			SendTxt(iSockFd,"%s",showfile);
			SendTxt(iSockFd,"\"/>%s</A></TD>",dentry->d_name);
		}
		if(sb.st_size>1048576) {
			SendTxt(iSockFd,"<TD ALIGN=right NOWRAP>%10.1f M</TD>\n",(float)sb.st_size/1048576.0);
		}
		else{
			SendTxt(iSockFd,"<TD ALIGN=right NOWRAP>%10.1f K</TD>\n",(float)sb.st_size/1024.0);
		}
		SendTxt(iSockFd,"<TD ALIGN=right NOWRAP>%s</TD></TR>\n",sDateTime);
	}
	closedir(handle);
	SendTxt(iSockFd,"</TABLE>\n");
	SendTxt(iSockFd,"</CENTER>\n");
	sprintf(file,"%s%s",PARAM("DocumentRoot"),"/inc/footer.inc");
	SendFile(iSockFd,r,file,"",0);
	return 0;
}

int SendFile(int iSockFd,struct HttpRequestStruct *r,char sFileName[],
	char sMimeType[],int iSendHead)
{
	FILE *fp;
	struct stat s;
	char *pBgn,*pEnd;
	char sBuffer[1024],sDefFile[PATH_MAX+1],sCtlFile[PATH_MAX+1];
	long iRet,lBgnPos=0L,lEndPos=0L;

	if(stat(sFileName,&s)!=0) return -1;

	/*Ŀ¼,����Ĭ�ϣ�û���ٿ��ܷ��г�Ŀ¼�������������*/
	/*
	�Ƿ���г�Ŀ¼��
	ListDir==0ʱĿ¼����list.allow�Ҳ�����list.rejectʱ�г�
	ListDir==1ʱ���ҽ���Ŀ¼����list.rejectʱ���г�
	����ֻҪĿ¼����list.reject�Ͳ��г�.List_Dir==0ʱĿ¼������list.allow������list.rejectʱ�г�
	*/
	if(s.st_mode&S_IFDIR){

		snprintf(sDefFile,PATH_MAX,"%s/%s",sFileName,PARAM("DirectoryIndex"));
		if(SendFile(iSockFd,r,sDefFile,sMimeType,1)!=0){
			/*�ܾ�����*/
			snprintf(sCtlFile,PATH_MAX,"%s/%s",sFileName,"list.reject");
			if(IsFile(sCtlFile)) return 403;

			snprintf(sCtlFile,PATH_MAX,"%s/%s",sFileName,"list.allow");
			if(strcmp(PARAM("ListDir"),"yes")==0)
				return ListDir(iSockFd,r,sFileName);
			if(strcmp(PARAM("ListDir"),"no")==0&&IsFile(sCtlFile))
				return ListDir(iSockFd,r,sFileName);
			else	return 403;
		}
		return 0;
	}

	/*��֧�ֶϵ�*/
	if(strlen(getValue(r->pOptList,"Range"))>5){
		pBgn=strchr(getValue(r->pOptList,"Range"),'=')+1;
		pEnd=strchr(getValue(r->pOptList,"Range"),'-')+1;
		lBgnPos=atol(pBgn);
		lEndPos=atol(pEnd);
	}

	if((fp=fopen(sFileName,"rb"))==NULL) return 404;

	if(lBgnPos>0L) fseek(fp,lBgnPos,SEEK_SET);

	if(iSendHead)
		SendHead(iSockFd,200,"",sMimeType,s.st_size-lBgnPos);

	do {
		iRet=fread(sBuffer,1,sizeof(sBuffer)-1,fp);
		if(iRet>0) write(iSockFd,sBuffer,iRet);

	}while(iRet>0);

	fclose(fp);

	return 0;
}
void AddEnv2List(char *envp[],char *envList[],int *piPos)
{
	int i=0,j=*piPos;
	
	while(envp[i]!=NULL){
		envList[j++]=strdup(envp[i++]);
	}
	*piPos=j;
}
int CallCGI(int iSockFd,struct HttpRequestStruct *r,
	char fileName[],char sMime[],char sAction[],char *envp[])
{
	size_t pid;
	char data[2048];
	int pipe1[2],pipe2[2],iRet;
	struct pipe_fd p,c;

	/*���õ�ǰ����Ŀ¼*/
	if(chdir(PARAM("DocumentRoot"))!=0)return 500;

	if(r->fp!=NULL)rewind(r->fp);

	if(pipe(pipe1)<0) perror("pipe1");
	if(pipe(pipe2)<0) perror("pipe2");

	p.r=pipe1[0]; c.w=pipe1[1];
	c.r=pipe2[0]; p.w=pipe2[1];

	pid=fork();
	if(pid<0)return 500;


	if(pid>0){
		close(c.r);
		close(c.w);
		/*SendHead(iSockFd,200,"","text/html;charset=gb2312",-1);*/
		/*SendTxt(iSockFd,"HTTP/1.1 200 OK\r\n\r\n");	*/
		/*SendTxt(iSockFd,"Connection: Close\r\n");	*/
		do {
			memset(data,0,sizeof(data));
			iRet=read(p.r,data,2047);
			data[iRet]=0;
			if(iRet>0)write(iSockFd,data,iRet);

		} while(iRet>0);

		close(p.r);
		close(p.w);
	}
	else{
		int i=0,ret;
		char *envList[300],sTemp[8192],*args[10];
		struct nvlist *ptHead,*pTemp;

		close(p.r);
		close(p.w);

		/*ע�⣺�˴�ֱ��ʹ����ʱ�ļ��ޣ�����pipe�ˣ��������ݸ���*/
		if(r->fp!=NULL)
			dup2(fileno(r->fp),fileno(stdin));
		dup2(c.w,fileno(stdout));
		dup2(c.w,fileno(stderr));


		/*memset(envList,0,sizeof(char *));*/

		ptHead= r->pOptList;
		while(ptHead!= NULL){
			pTemp= ptHead;
			ptHead= ptHead->pNext;
			if(pTemp->sName==NULL||pTemp->sValue==NULL) continue;
			sprintf(sTemp,"%s=%s",pTemp->sName,pTemp->sValue);
			envList[i++]=strdup(sTemp);
		}
		/*query string*/
		if(r->sQryStr!=NULL){
			envList[i]= malloc(strlen(r->sQryStr)
				+strlen("QUERY_STRING=")+1);
			sprintf(envList[i],"QUERY_STRING=%s",r->sQryStr);
			i++;
		}

		envList[i]= malloc(strlen(r->sFileName)
			+strlen("SCRIPT_NAME=")+1);
		sprintf(envList[i],"SCRIPT_NAME=%s",r->sFileName);
		i++;

		envList[i++]="GATEWAY_INTERFACE=CGI/1.1";
		envList[i++]="SERVER_PROTOCOL=HTTP/1.1";

		envList[i]= malloc(strlen(r->sMode)
			+strlen("REQUEST_METHOD=")+1);
		sprintf(envList[i],"REQUEST_METHOD=%s",r->sMode);
		i++;

		if(r->iPostDataLen>0){
			envList[i]= malloc(sizeof(int)+strlen("CONTENT_LENGTH=")+1);
			sprintf(envList[i],"CONTENT_LENGTH=%d",r->iPostDataLen);
			i++;

			envList[i]= malloc(strlen(getValue(r->pOptList,
				"Content-Type"))+strlen("CONTENT_TYPE=")+1);
			sprintf(envList[i],"CONTENT_TYPE=%s",getValue(
				r->pOptList,"Content-Type"));
			i++;
		}

		envList[i]= malloc(strlen(PARAM("DocumentRoot"))+strlen("DOCUMENT_ROOT=")+1);
		sprintf(envList[i],"DOCUMENT_ROOT=%s",PARAM("DocumentRoot"));
		i++;

		envList[i]= malloc(strlen(getValue(r->pOptList,"User-Agent"))+strlen("HTTP_USER_AGENT=")+1);
		sprintf(envList[i],"HTTP_USER_AGENT=%s",getValue(r->pOptList,"User-Agent"));
		i++;

		envList[i]= malloc(strlen(getValue(r->pOptList,"Cookie"))+strlen("HTTP_COOKIE=")+1);
		sprintf(envList[i],"HTTP_COOKIE=%s",getValue(r->pOptList,"Cookie"));
		i++;

		envList[i]= malloc(strlen(fileName)
			+strlen("SCRIPT_FILENAME=")+1);
		sprintf(envList[i],"SCRIPT_FILENAME=%s",fileName);
		i++;

		AddEnv2List(envp,envList,&i);

		envList[i]=NULL;

		args[0]=strdup(sAction);
		args[1]=strdup(fileName);
		args[2]=NULL;

		ret= execve(args[0],&args[0],&envList[0]);/*ʧ�ܲŷ���*/

		for(i=0; envList[i]; i++) free(envList[i]);

		SendError(iSockFd,r,500);

		close(c.r);
		close(c.w);
		exit(0);
	}

	/*post����,ʹ����ʱ�ļ�*/
/*	if(r->iPostDataLen>0) {
		int i,j;
		char PostData[20480];
		rewind(r->fp);
		while((i=fread(PostData,sizeof(PostData[0]),
			sizeof(PostData),r->fp))>0){
			j=write(p.w,PostData,i);

		}
		fclose(r->fp);
	}
*/
	return 0;
}

void SendError(int iSockFd,struct HttpRequestStruct *r,int iState)
{
	char sFileName[PATH_MAX+1];

	sprintf(sFileName,"%s/error/%d.htm",PARAM("DocumentRoot"),iState);

	SendHead(iSockFd,iState,"","text/html",-1);
	SendTxt(iSockFd,"<font color='black'>��������ʲô�����������ҳ����ˣ���<br>ִ������%s����,������룺%d<BR>ϵͳ��Ϣ:%s</font><br><hr><br>",
		r->sFileName,iState,strerror(errno));
	SendFile(iSockFd,r,sFileName,"text/html",0);
}

int ProcessRequest(int iSockFd,struct HttpRequestStruct *r,char *envp[])
{
	char sTmpName[PATH_MAX+1],*pBasePath,sRealPath[PATH_MAX+1],*p;
	char sExtName[32],*pMime,sAction[32],sMimeName[128];

	pBasePath=PARAM("DocumentRoot");

	decodeurl(r->sFileName);

	sprintf(sTmpName,"%s%s",pBasePath,r->sFileName);

	if((p=realpath(sTmpName,sRealPath))==NULL) return 404;

	if(strncmp(sRealPath,pBasePath,strlen(pBasePath))!=0) return 403;

	GetExtName(sRealPath,sExtName);
	/*�Ƿ�CGI*/
	snprintf(sAction,31,"A%s",sExtName);
	p=PARAM(sAction);

	/*MIME����*/
	if((pMime=PARAM(sExtName))!=NULL)
		strncpy(sMimeName,pMime,127);
	else	strcpy(sMimeName,"");

	/*��ͨ�ļ�ֱ�ӷ�������*/
	if(strlen(p)==0)
		return SendFile(iSockFd,r,sRealPath,sMimeName,1);

	/*CGI����*/
	return CallCGI(iSockFd,r,sRealPath,sMimeName,p,envp);
}



/**
wwHttpRequest��http��������
@iSockFd:�ͻ���SOCK
@sRequest:����ĵ�һ���Ѷ�ȡ������
  strstr("HTTP",sbuff),Ƕ����������ʹ��ͬһ�˿ڣ������������ж��Ƿ�http����
@iBuffLen:�Ѷ�ȡ�����ݵĳ���.
*/
#define MINLEN 8192
void wwHttpRequest(int iSockFd,char sIpAddr[],char sRequest[],int iBufLen,
	char *envp[])
{
	int iRet;
	char *pHead,*pBuffer;
	struct HttpRequestStruct r;

	bzero(&r,sizeof(struct HttpRequestStruct));

	/*����ͻ���IP������֤�á����޶�ĳЩip��ַ���ܷ���*/
	if((r.sClientIp=strdup(sIpAddr))==NULL){
		SendError(iSockFd,&r,500);
		return;
	}

	/*�����б�Ϊ��ʱ�����������IP�б����ʾ�ܾ�����*/
	if(strlen(PARAM("AllowIP"))!=0&&
		strstr(PARAM("AllowIP"),sIpAddr)==NULL){
		SendError(iSockFd,&r,403);
		return;
	}
	/*��������ڲ������б�Ҳ�ǲ��ɷ���.*/
	if(strstr(PARAM("NotAllowIP"),sIpAddr)!=NULL){
		SendError(iSockFd,&r,403);
		return;
	}

	/*���ƴ������*/
	if((pBuffer=strdup(sRequest))==NULL){
		SendError(iSockFd,&r,500);
		return;
	}
	pHead=pBuffer;

	/*
	puts(pHead);
	puts("DONE---------------------------------------------------");
	*/

	/*�������ύģʽ�����󴮣��汾��*/
	if(ParseRequestInfo(&pHead,&r)<0){
		SendError(iSockFd,&r,500);
		return;
	}

	/*����ѡ��*/
	if(ParseRequestOptions(iSockFd,pBuffer,iBufLen,&pHead,&r)<0){
		SendError(iSockFd,&r,500);
		return;
	}

	/*���post��ʽ�ύ����������*/
	if(strcasecmp(r.sMode,"POST")==0){
		char *p,PostData[8192];
		int iTmpBufLen,iContLen,iRet,i;

		p=getValue(r.pOptList,"Content-Length");
		iContLen= atoi(p);

		if(iContLen>0){
			r.iPostDataLen= iContLen;

			if((r.fp= tmpfile())==NULL){
				SendError(iSockFd,&r,500);
				return;
			}

			iTmpBufLen= iBufLen -(pHead -pBuffer);
			if(iTmpBufLen!= 0){
				i=fwrite(pHead,sizeof(pHead[0]),iTmpBufLen,r.fp);
			}

			while(iTmpBufLen<iContLen){
				/*todo:��ȡʣ���ֽ�*/
				SetTimeOut(PARAMI("Timeout"));
				iRet= read(iSockFd,PostData,sizeof(PostData));
				CleanTimeOut();
				iTmpBufLen+=iRet;
				i=fwrite(PostData,sizeof(PostData[0]),iRet,r.fp);
				/*
				printf("Wsize:%d,cnt:%d,READER:%d,READED:%d,TOT:%d\n",
					sizeof(PostData[0]),i,iRet,iTmpBufLen,iContLen);
				*/
			}
		}
	}

	/*��������*/
	if((iRet=ProcessRequest(iSockFd,&r,envp))!=0)
		SendError(iSockFd,&r,iRet);

}
