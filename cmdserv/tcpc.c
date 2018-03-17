#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "wwlog.h"
#include "wwfile.h"
#include "wwnet.h"

int	giSockFd;

int CmdLineBegin(int i)
{
	if(i==0) return true;
	return false;
}
void SetCmdLineBegin(int *pi)
{
	*pi=0;
}
int InputStringIsNull(char sTemp[])
{
	if(strlen(sTemp)==0) return true;
	return false;
}
void GetTcpCurStr(struct TcpConnectStruct *ptHead,char sTcpCur[128])
{
	int i=0;
	char sTemp[128];
	
	strcpy(sTcpCur,"");
	
	while(ptHead!=NULL){
		if(i==0)
			sprintf(sTemp,"%s:%d",ptHead->sIp,ptHead->iPort);
		else
			sprintf(sTemp,">%s:%d",ptHead->sIp,ptHead->iPort);
		
		if((strlen(sTcpCur)+strlen(sTemp))>120){
			strcpy(sTcpCur+120-strlen(sTemp),"...");
			strcat(sTcpCur,sTemp);
		}
		else
			strcat(sTcpCur,sTemp);
		i++;
		ptHead=ptHead->pNext;
	}
}
int AddTcpConnect(char sIp[16],int iPort,
	struct TcpConnectStruct **pptHead)
{
	struct TcpConnectStruct *pTemp;
	
	if((pTemp=malloc(sizeof(struct TcpConnectStruct)))==NULL){
		printf("malloc TcpConnectStruct error.\n");
		return -1;
	}
	bzero((void*)pTemp,sizeof(struct TcpConnectStruct));
	strcpy(pTemp->sIp,sIp);
	pTemp->iPort=	iPort;
	InsertListTail((LIST**)pptHead,(LIST*)pTemp);
	return 0;
}
void ReadSockMsg(int v)
{

	static int iLock=0,n;
	char buf[1024];
	
	if(iLock) return;
	
	iLock=1;

	if(CanReadFD(giSockFd)){
		do{
			n=wwfdgets(buf,1024,giSockFd);

			if(n<=0) break;
			buf[n]=0;
			printf("back::%d,%s\n",n,buf);
		}while(1);
		printf(">\n");
	}
	iLock=0;
}
/*
int InitTimer()
{
	struct itimerval timerv,old_timer;
	struct sigaction siga;

	siga.sa_handler= ReadSockMsg;
	siga.sa_flags= 0;
	
	memset(&siga.sa_mask,0,sizeof(sigset_t));
	
	sigaction(SIGALRM,&siga,NULL);
	
	timerv.it_interval.tv_sec= 0;
	timerv.it_interval.tv_usec= 500000;
	timerv.it_value= timerv.it_interval;
	
	if(setitimer(ITIMER_REAL,&timerv,&old_timer)) {
		fprintf(stderr,"TIMER: setitimer call failed!\n");
		perror("setitimer");
		return -1;
	}	
	return 0;
}
*/
int main()
{
	fd_set iFdSet,iPreFdSet;
	char	sTemp[1024],sFileName[256];
	int iRet,iMaxSockFd,iSockFd,l,fd,n,i=0,iPos=0;/*��ʾ��ǰ���ļ�fpλ��*/
	FILE *fp,*fpA[256];
	char	sTcpCur[128];
	struct TcpConnectStruct *pTcpCur=NULL;
	struct FileControlStruct *ptHead=NULL,*pTemp;
	
	char	sIp[16];
	int	iPort;
	
	strcpy(sIp,"10.206.13.166");
	strcpy(sIp,"130.38.8.99");
	iPort=7788;
	
	iSockFd=ConnectTcpServer(sIp,iPort);
	giSockFd=iSockFd;
	
/*	InitTimer();*/
	
	AddTcpConnect(sIp,iPort,&pTcpCur);
	GetTcpCurStr(pTcpCur,sTcpCur);
	
	InitialFDSET(&iFdSet);
	AddItem2FDSET(&iFdSet,iSockFd);
	iMaxSockFd=iSockFd+1;
	
	fp=fpA[0]=stdin;
	
	while(1){
		/*��������ʼ���ӡ��ʾ��*/
		if(CmdLineBegin(i)){
			ReadSockMsg(0);
			printf("%s>",sTcpCur);
		}		
		wwfgets(sTemp,1024,fp);
		
		
		if(feof(fp)&&strlen(sTemp)==0){
			if(iPos>=1){
				fclose(fp);
				iPos=iPos-1;
				fp=fpA[iPos];
			}
			continue;
		}
		/*�жϿ��ַ������*/
		if(InputStringIsNull(sTemp))continue;
		
		/*�����һ����������һ���ļ�*/
		if(sTemp[0]=='@'){
			if(CmdLineBegin(i)!=true){
				printf("CLIENT: @ �ַ������������еĿ�ʼ.\n");
				SetCmdLineBegin(&i);
				continue;
			}
			/*�������п�ʼ�������ļ�*/
			strcpy(sFileName,sTemp+1);
			l=strlen(sFileName);
			if(sFileName[l-1]==';')sFileName[l-1]=0;
			if((fp=fopen(sFileName,"r"))==NULL){
				printf("CLIENT: ���ļ�%sʧ��.\n",sFileName);
				SetCmdLineBegin(&i);
				fp=fpA[iPos];
				continue;
			}
			/*���ļ������������fp*/
			iPos++;
			if(iPos>=255){
				printf("�򿪵��ļ�������.\n");
				return -1;
			}
			fpA[iPos]=fp;
			continue;
		}

		/*�ж��˳������*/
		if(CmdLineBegin(i)&&
			(strcmp(sTemp,"quit")==0||strcmp(sTemp,"exit")==0))
			return 0;
		/*�������м����б�*/
		l=strlen(sTemp);
		if(item2list(&ptHead,sTemp,l)<0){
			printf("%s�ӵ�����ʧ��.\n");
			return -1;
		}
		/*���һ���������,�����һ��Ϊ;���ߵ���Ϊ/����Ϊ�������*/
		if(sTemp[l-1]==';'/*||sTemp[l-1]=='/'&&l==1*/){

			/*���������*/
			ReverseList((LIST**)&ptHead);
			fd=dup(iSockFd);
			printf("the cur fd=%d.\n",fd);
			if(list2fdln(&ptHead,fd)<0){
				printf("д��������ʧ��.\n");
				return -1;
			}
			SetCmdLineBegin(&i);
			continue;
		}
		/*���һ���ļ������ý���*/
		if(feof(fp)){
			/*�������ǿ�������ʧ��*/
			if(ptHead!=NULL)listfree(&ptHead);
			SetCmdLineBegin(&i);
			if(iPos>0){
				fclose(fp);
				iPos=iPos-1;
				fp=fpA[iPos];
			}
		}
		i++;
	}
	
	DisconnectTcpServer(iSockFd);
	
	return 0;
}
