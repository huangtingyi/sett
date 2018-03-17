#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "netagent.h"
#include "common.h"


struct HostList local;
struct HostList *pHostList = NULL;

/**
   ���ܣ���ĳ������������Ϣ��
   ���أ�0��ʾ���ͳɹ���1��ʾʧ�ܣ�
   ʹ��connect���Ʊ�֤���ͳɹ���
   ��TCPЭ�鲻ͬ��UDP��connect()��û�����������������֡�UDP�Ƿ����ӵģ�
   ʵ����Ҳ���������ӵġ�ʹ�����ӵ�UDP��kernel����ֱ�ӷ��ش�����Ϣ���û�����
   �Ӷ���������û�н��յ����ݶ����µ���recvfrom()һֱ�ȴ���ȥ��
   ����ȥ����ͻ�����û�з�Ӧһ����   
*/
int request(char sIp[], int iPort, char sMsg[],...)
{
	char sMessage[MAX_MSG_SIZE+1];
        int iSockFd,n;        
        va_list argptr;
        struct sockaddr_in  servaddr;
 
        /* init servaddr */
        bzero(&servaddr, sizeof(struct sockaddr_in));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(iPort);
        /*
        if(inet_pton(AF_INET, sIp, &servaddr.sin_addr) <= 0)
        {
                DoLog("[%s] is not a valid IPaddress\n", sIp);
                return -1;
        }
        */
         
        iSockFd = socket(AF_INET, SOCK_DGRAM, 0);
        /*������ӵ����������Ա�֤��Ϣ���ͳɹ������ɹ�����-1*/
        /* connect to server */
        if(connect(iSockFd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in)) == -1)
        {
                perror("���ӷ���������");
                return -1;
        }        
        
        /*�������봮*/
	memset(sMessage,0,MAX_MSG_SIZE);
	va_start(argptr, sMsg);
	vsprintf( sMessage, sMsg, argptr);
	va_end(argptr);
	sMessage[MAX_MSG_SIZE] = 0;
	if (strlen(sMessage)==0)
		return 0;        
        
        printf("to:[%s] {%s}\n", sIp, sMessage);
        sendto(iSockFd, sMessage, strlen(sMessage),0,NULL,0);
        n = recvfrom(iSockFd, sMessage, MAX_MSG_SIZE,0,NULL,NULL);
        if(n == -1)
        {
                perror("�������ͨ�Ŵ���");
                return -1;
        }
        sMessage[n] = 0;
        /*fputs(sMessage, stdout);        */
                        
        close(iSockFd);
        
       	return 0;	
        
}

struct HostList *SearchHost(char sIpAddr[],struct HostList *ptHead)
{

	while ( ptHead != NULL ){
		if (strncmp(ptHead->sIpAddr,sIpAddr,strlen(ptHead->sIpAddr))==0)
			return ptHead;
		ptHead = ptHead->pNext;
	}
	
	return NULL;
}

int ProcessMessage(int iSockFd, struct sockaddr_in *pCliAddr,
	 socklen_t iCliLen,char sMessage[])
{
	FILE *fp;
	int i,t,iFnReq,iFn,iRet;
	char sFileName[256],sSh[256];
	char *sFieldRet[2],*sIpFields[2],*sReqFields[2],*sReqTmpFields[2];
	char *sCmdFields[MAX_CMD_CNT],sTemp[MAX_MSG_SIZE],sTempMsg[MAX_MSG_SIZE];
	char *ReqIpAddr=NULL;
	struct HostList *pHost = NULL,*pReqHost=NULL,TempHost;
	
	memset(&TempHost,0,sizeof(struct HostList));
	bzero(sTemp,0);
	bzero(sTempMsg,0);
	
	ReqIpAddr=inet_ntoa(pCliAddr->sin_addr);
	DoLog("ReqAddr:%s\n",ReqIpAddr);	
	pReqHost=SearchHost(ReqIpAddr,pHostList);
	if (pReqHost == NULL){
		strcpy(TempHost.sIpAddr,ReqIpAddr);
		TempHost.iPort = SERV_PORT;
		pReqHost = &TempHost;				
	}	
	DoLog("ReqAddr:%s\n",pReqHost->sIpAddr);
	/*if (t>1){
		DoLog("FirstCount:%d\n",t);
		DoLog("FirstField:%s\n",sIpFields[0]);
		DoLog("Last:%s\n",sIpFields[1]);
	}
	*/	
	printf("\n");
	strcpy(sTemp,sMessage);
	sTemp[MAX_MSG_SIZE] = 0;
	if (strlen(sTemp)==0) return 0;
	/*������ֵ*/
	if (strncmp(sTemp,"RET:",4)==0){
		DoLog("����ֵ��%s\n",sTemp);
		iFnReq = split(sTemp, sFieldRet,2, RET_SP);
		DoLog("%s::%s\n",sFieldRet[0],sFieldRet[1]);
		iFnReq = split(sFieldRet[1], sReqTmpFields,2, "#");
		AllTrim(sReqTmpFields[0]);
		if (strlen(sReqTmpFields[0])>0){
			pHost = NULL;
			pHost = SearchHost(sReqTmpFields[0],pHostList);
			if (pHost == NULL){
				strcpy(TempHost.sIpAddr,sReqTmpFields[0]);
				TempHost.iPort = SERV_PORT;
				pHost = &TempHost;				
			}			
			DoLog("IP:%s Port:%d\n",pHost->sIpAddr,pHost->iPort);			
			if (strlen(sReqTmpFields[1])>0)
				request(pHost->sIpAddr,pHost->iPort,
				"%s%s%s",sFieldRet[0],RET_SP,sReqTmpFields[1]);
			if (strlen(sReqTmpFields[1])==0)
				request(pHost->sIpAddr,pHost->iPort,sFieldRet[0]);			
		}
		else
			DoLog("���ս����%s\n",sFieldRet[0]);
		return 0;
	}
	
	/*��������*/
	printf("Recv:%s\n",sTemp);
	sFieldRet[0]=NULL;
	sFieldRet[1]=NULL;
	iFnReq = split(sTemp, sFieldRet,2, RET_SP);
	bzero(sTempMsg,0);
	strcpy(sTempMsg,sTemp);
	iFn = split(sFieldRet[0], sIpFields,2, REQ_SP);
	AllTrim(sIpFields[0]);
	/*����ڵ�Ϊ������*/
	if (strncmp(sIpFields[0],local.sIpAddr,strlen(local.sIpAddr)) == 0){
		DoLog("����������!!\n");
		t = split(sIpFields[0], sReqFields,2, IP2CMD_SP);
		DoLog("\tFirstField:%s\n",sReqFields[0]);
		DoLog("\tLast:%s\n",sReqFields[1]);
		t = split(sReqFields[1], sCmdFields,MAX_CMD_CNT, CMD_SP);
		sprintf(sFileName,"./shell%d%d%d.lst",getpid(),getppid(),t);
		fp = fopen(sFileName,"w");
		for ( i=0; i<t; i++){
			fwrite( sCmdFields[i],strlen(sCmdFields[i]), 1, fp);
			fwrite( "\n",strlen("\n"), 1, fp);
		}
		fclose(fp);
		sprintf(sSh,"sh %s",sFileName);
		iRet = system(sSh);
		unlink(sFileName);
		if (iRet != 0){
			request(pReqHost->sIpAddr,pReqHost->iPort,"RET:�ڵ�%sִ������ʧ�ܣ�%s%s",local.sIpAddr,RET_SP,sFieldRet[1]);	
			return -1;
		}
		/*DoLog(":%s--%s\n",sIpFields[1],sIpFields[1]);*/
		if (sIpFields != NULL){
			if ((strncmp(sIpFields[1],RET_SP,1)!=0)&&(strlen(sIpFields[1])>0)&&((strstr(sIpFields[1],IP2CMD_SP)!=NULL)||
				(strstr(sIpFields[1],REQ_SP)!=NULL))){
				sprintf(sTemp,"%s%s%s",sIpFields[1],RET_SP,sFieldRet[1]);
				ProcessMessage(iSockFd, pCliAddr, iCliLen, sTemp);
				return 0;
			}
		}
		request(pReqHost->sIpAddr,pReqHost->iPort,"RET:���սڵ�%s�����ɹ�%s%s",local.sIpAddr,RET_SP,sFieldRet[1]);	
		return 0;   
	}
	pHost = SearchHost(sIpFields[0],pHostList);
	
	/*�Ǳ�����*/	
	/*һ.�������ɴ�����,���͵�Ŀ������*/
	if (pHost != NULL){
		DoLog("Ŀ������[%s]�ɴ�!!\n",pHost->sIpAddr);
		if (request(pHost->sIpAddr,pHost->iPort,"%s%s%s#%s",sTempMsg,RET_SP,pReqHost->sIpAddr,sFieldRet[1])==0){
			DoLog("ת����Ϣ��%s:%d............�ɹ�!\n",pHost->sIpAddr,pHost->iPort);
		}
		else
			request(pReqHost->sIpAddr,pReqHost->iPort,"RET:%s��%sת������ʧ�ܣ�%s%s",local.sIpAddr,pHost->sIpAddr,RET_SP,sFieldRet[1]);
	}
	
	/*��.���������ɴ�������㲥*/
	if (pHost == NULL){
		int iRet;
		DoLog("Ŀ���������ɴ�㲥��Ϣ!!!\n");
		iRet = SendToAllServer(pHostList,local.sIpAddr,pReqHost->sIpAddr,
			"%s%s%s#%s",sTempMsg,RET_SP,pReqHost->sIpAddr,sFieldRet[1]);
		if (iRet==-1){
			DoLog("%s����Ŀ���������ɴ����ʧ��!!!\n",sFieldRet[1]);
			request(pReqHost->sIpAddr,pReqHost->iPort,"RET:%s������Ŀ�����������ɴ%s%s",local.sIpAddr,RET_SP,sFieldRet[1]);
		}
	}	
	return 0;
}
void do_Action(int iSockFd, struct sockaddr_in *pCliAddr, socklen_t iCliLen)
{
        int		n;
        socklen_t	iLen;
        char		mesg[MAX_MSG_SIZE];
 
        while( 1 )
        {
                iLen = iCliLen;
                bzero(mesg,MAX_MSG_SIZE);
                /* �ȴ���������*/
                n = recvfrom(iSockFd, mesg, MAX_MSG_SIZE, 0, pCliAddr, &iLen);
                DoLog("CliAddr:%s\n",inet_ntoa(pCliAddr->sin_addr));
                mesg[n] = 0;
                AllTrim(mesg);
                /*������Ӧ*/
		sendto(iSockFd, "back\n", n, 0, (struct sockaddr *)pCliAddr, iLen);
                /*���ܴ���*/
                
                if ((strstr(mesg,IP2CMD_SP)!=NULL)||(strstr(mesg,REQ_SP)!=NULL)
                	||(strstr(mesg,"RET:")!=NULL)){
                	int ret;
                	
			if ((ret=fork())==0){			
			
				if((ret=fork())!=0) exit(0);                	
                	
                		ProcessMessage(iSockFd,pCliAddr, iLen,mesg); 
                		exit(0); 
                	}
                	
                	wait(&ret);
                	
                	continue;
                }
		printf("һ����Ϣ:%s\n",mesg);
        }
}
int Parse_Host(char sLine[],struct HostList *pHost)
{
#define MNF_FIELD 3
	int t,i;
	char *fields[MNF_FIELD];
		
	memset(pHost,0,sizeof(struct HostList));
	
	t = split(sLine, fields, MNF_FIELD, ":");		
	AllTrim(fields[0]);
	strncpy(pHost->sIpAddr,fields[0],15);
	for (i = 0;  i < strlen(fields[1]);  i++)                               
		if (!isdigit(*(fields[1] + i)))                                       
			break;                                                                     
	AllTrim(fields[1]);                                                                         
	if (i == strlen(fields[1]))                                             
		pHost->iPort = atoi(fields[1]);
	else {                                                                         
		DoLog("������%s��%s����ָ����[%s]����һ����Ч�˿�!\n",
			fields[0],fields[2],fields[1]);                       
		return -1;                                                                 
	}
	return 0;
}
int LoadHostList(char sFileName[],struct HostList **pptHead)
{
	int n,iPos;
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct HostList *pHostTmp=NULL;
	
	/*���ļ����ݵ��ú������ص��ڴ�*/	
	if((n=file2list(sFileName,0,-1,0,&ptHead))<0){
		DoLog("�����ļ�%s���ڴ�ʧ��.\n",sFileName);
		return -1;
	}

	while ( ptHead !=NULL ){
		
		pTemp = ptHead;
		ptHead = ptHead->pNext;
		AllTrim(pTemp->pData);
	        if (strlen(pTemp->pData)==0)
	        	continue;
		if (strncmp(pTemp->pData,"#",1)==0){
		        if (strncmp(pTemp->pData,"#local",6)==0)
		          iPos=1;
			/*DoLog("Common:%s\n",pTemp->pData);*/
			continue;
		}
	        /*ip:port:comment*/       
	        if (iPos==1){
	        	iPos = 0;
			DoLog("LocalIP:%s\n",pTemp->pData);	
	        	if (Parse_Host(pTemp->pData,&local)==-1){
	                	DoLog("������ַ��˿����ô��󣬳�����ֹ��\n");
	                	exit(-1);
	        	}
	        	DoLog("����%s:%d..................�ɹ�!\n",local.sIpAddr,local.iPort);
	        	continue;
	        }
	        
		pHostTmp = malloc(sizeof(struct HostList));
		if ( pHostTmp== NULL){
			DoLog("Ϊ��¼[%s]�����ڴ�ʧ�ܣ������˼�¼��\n",pTemp->pData);
			continue;	
		}        
	        memset(pHostTmp,0,sizeof(struct HostList));
        	if (Parse_Host(pTemp->pData,pHostTmp)==-1){
                	DoLog("������¼[%s]ʧ�ܣ������˼�¼��\n",pTemp->pData);
                	continue;
        	}
        	InsertList((LIST **)pptHead, (LIST *)pHostTmp);	        
		DoLog("����%s:%d..................�ɹ�!\n",pHostTmp->sIpAddr,pHostTmp->iPort);
	}	
	return 0;
}

int SendToAllServer(struct HostList *pHostList,
	char sExceptHost1[],char sExceptHost2[],char sMsg[],...)
{
	int iSuccCnt = 0;
	char sMessage[MAX_MSG_SIZE+1];     
        va_list argptr;	
	struct HostList *ptHead=pHostList,*pTemp=NULL;    
	
	while (ptHead != NULL){
		
		pTemp = ptHead;
		ptHead = ptHead->pNext;
		
		if (sExceptHost1 != NULL){
			if (strncmp(sExceptHost1,pTemp->sIpAddr,strlen(pTemp->sIpAddr))==0)
				continue;
		}
		
		if (sExceptHost2 != NULL){
			if (strncmp(sExceptHost2,pTemp->sIpAddr,strlen(pTemp->sIpAddr))==0)
				continue;
		}
		
		if (strncmp("127.0.0.1",pTemp->sIpAddr,strlen(pTemp->sIpAddr))==0)
			continue;	
				
	        /*�������봮*/
		memset(sMessage,0,MAX_MSG_SIZE);
		va_start(argptr, sMsg);
		vsprintf( sMessage, sMsg, argptr);
		va_end(argptr);
		sMessage[MAX_MSG_SIZE] = 0;
		DoLog("��������%s:%d\n",pTemp->sIpAddr,pTemp->iPort);		
		if (request(pTemp->sIpAddr,pTemp->iPort,sMessage)==0){
			DoLog("������Ϣ��%s:%d............�ɹ�!\n",pTemp->sIpAddr,pTemp->iPort);
			iSuccCnt++;
			continue;
		}
		DoLog("������Ϣ��%s:%d............ʧ��!!!!!\n",pTemp->sIpAddr,pTemp->iPort);		
	}
	if (iSuccCnt>0) return 0;
	return -1;
	
}
int main(int argc,char **argv)
{
        int iSockFd,iPort=8888;
        char sFileName[256];
        struct sockaddr_in servaddr, cliaddr;
 
	if (argc!=3){
		printf("Usage %s port IpFile.%d\n",argv[0],argc);
		exit(0);
	}
	    
	iPort = atoi(argv[1]);
 	strcpy(sFileName,argv[2]);
 	
	if(IsFile(sFileName)==FALSE){
		DoLog("�����ļ�%s��Ч.\n",sFileName);
		return -1;
	}
	
 	 /* create a socket */
        iSockFd = socket(AF_INET, SOCK_DGRAM, 0);
 
        /* init servaddr */
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(SERV_PORT);
 
        /* bind address and port to socket */
        if(bind(iSockFd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        {
                perror("bind error");
                exit(1);
        }
	DoLog("-------------------------���ط������б�-------------------------\n");
	LoadHostList(sFileName,&pHostList);	
	DoLog("-------------------------������������-------------------------\n");
	SendToAllServer(pHostList,local.sIpAddr,"127.0.0.1","Hi,I'm up now!");

        do_Action(iSockFd, &cliaddr, sizeof(cliaddr));
 
        return 0;
}

