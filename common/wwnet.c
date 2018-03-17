#include <assert.h>
#include "hnixs.h"
#include "list.h"
#include "wwlog.h"
#include "wwtiny.h"
#include "wwfile.h"
#include "wwnet.h"

void tcp_server_time_out(struct TcpServerStruct *ptHead)
{
	sleep(ptHead->iMaxSec);
}
void tcp_client_time_out(struct TcpClientStruct *ptHead)
{
	sleep(ptHead->iMaxSec);
}
int tcp_connect_auth(struct TcpClientStruct *ptHead)
{
	return true;
}
int tcp_data_recv(struct TcpClientStruct *ptHead)
{
	int n;
	
	n=send(ptHead->iSockFd,"hello", strlen("hello"),0);
	return n;
}
void tcp_initial_client(struct TcpClientStruct *ptHead)
{
	ptHead->OnTimeOut	=tcp_client_time_out;
	ptHead->OnConnectAuth	=tcp_connect_auth;
	ptHead->OnDataRecv	=tcp_data_recv;
}
void InitMySet(MY_FDSET *piFdSet)
{
	FD_ZERO(piFdSet);
}
void Item2MySet(MY_FDSET *piFdSet,int iSockFd)
{
	FD_SET(iSockFd, piFdSet); 
}
int SearchMySet(MY_FDSET *piFdSet,int iSockFd)
{
	if(FD_ISSET(iSockFd,piFdSet)) return FOUND;
	return NOTFOUND;
}
void DeleteMySet(MY_FDSET *piFdSet,int iSockFd)
{
	FD_CLR(iSockFd,piFdSet);
}
int FD_DataReady(int iFd)
{
	int i,iRet;
	MY_FDSET iFdSet;
	struct timeval tTimeValue;

	int iMaxFd=iFd+1;

	InitMySet(&iFdSet);
	Item2MySet(&iFdSet,iFd);

	bzero((void*)&tTimeValue,sizeof(struct timeval));
	tTimeValue.tv_sec=	0;
	tTimeValue.tv_usec=	1;

	iRet=select(iMaxFd,&iFdSet,NULL,NULL,&tTimeValue);

	if(iRet>0&&SearchMySet(&iFdSet,iFd)==FOUND) i=true;
	else	 i=false;

	DeleteMySet(&iFdSet,iFd);
	return i;
}
int WaitMySetRead(int iMaxFd,int iMaxSec,MY_FDSET *piFdSet)
{
	int i;
	struct timeval tTimeValue;

	bzero((void*)&tTimeValue,sizeof(struct timeval));
	tTimeValue.tv_sec=	iMaxSec;
	tTimeValue.tv_usec=	0;

	i=select(iMaxFd,piFdSet,NULL,NULL,&tTimeValue);

	return i;
}
int WaitMySetWrite(int iMaxFd,int iMaxSec,MY_FDSET *piFdSet)
{
	int i;
	struct timeval tTimeValue;

	bzero((void*)&tTimeValue,sizeof(struct timeval));
	tTimeValue.tv_sec=	iMaxSec;
	tTimeValue.tv_usec=	0;

	i=select(iMaxFd,NULL,piFdSet,NULL,&tTimeValue);

	return i;
}
int WaitMySetAll(int iMaxFd,int iMaxSec,
	MY_FDSET *piReadFdSet,MY_FDSET *piWriteFdSet,MY_FDSET *piErrFdSet)
{
	int i;
	struct timeval tTimeValue;

	bzero((void*)&tTimeValue,sizeof(struct timeval));
	tTimeValue.tv_sec=	iMaxSec;
	tTimeValue.tv_usec=	0;

	i=select(iMaxFd,piReadFdSet,piWriteFdSet,piErrFdSet,&tTimeValue);

	return i;
}
/*����Tcp���񲢼���*/
struct TcpServerStruct *CreateTcpServer(int iPort,int iChildFlag,
	int iMaxConn,int iMaxSec,void (*OnTimeOut)(struct TcpServerStruct *),
	void (*InitialClient)(struct TcpClientStruct *))
{
	int 	iSockFd;
	struct sockaddr_in sMyAddr;
	struct TcpServerStruct *ptHead;
  
	if ((iSockFd=socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("socket!");
		/*д����sockʧ����־*/
		return NULL;
  	}
  
	bzero((void*)&sMyAddr,sizeof(struct sockaddr_in));
	sMyAddr.sin_family = AF_INET;
	sMyAddr.sin_port = htons( iPort );
	sMyAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(iSockFd,(struct sockaddr*)&sMyAddr,
		sizeof(struct sockaddr_in))==-1){
		perror("bind");
		/*дSOCK�󶨴�����־*/
		close(iSockFd);
		return NULL;
	}
  
	if (listen(iSockFd,5)==-1){
  		perror("listen");
  		/*д��ͣʧ����־*/
		close(iSockFd);
  		return NULL;
	}

	if((ptHead=(struct TcpServerStruct*)
		malloc(sizeof(struct TcpServerStruct)))==NULL){
		/*��ӡ�����ڴ���Ϣ*/
		close(iSockFd);
		return NULL;
	}

	bzero((void*)ptHead,sizeof(struct TcpServerStruct));
	ptHead->iSockFd=	iSockFd;
	ptHead->iChildFlag=	iChildFlag;
	ptHead->iMaxConnect=	iMaxConn;
	ptHead->iMaxSec=	iMaxSec;
	strncpy(ptHead->sIp,	inet_ntoa(sMyAddr.sin_addr),15);
	ptHead->sIp[15]=0;
	AllTrim(ptHead->sIp);
	ptHead->iPort=		iPort;
	ptHead->OnTimeOut=	OnTimeOut;
	ptHead->InitialClient=	InitialClient;

	return ptHead;
}
static struct TcpClientStruct *MyTcpConnectAccept(struct TcpServerStruct *ptHead)
{
	int iAddrLen;
	int iNewSockFd;
	struct sockaddr_in sPeerAddr;
	struct TcpClientStruct *pTemp;

	iNewSockFd=accept(ptHead->iSockFd,
		(struct sockaddr *)&sPeerAddr,&iAddrLen);
	
	if(iNewSockFd==-1){
		printf("accept error.\n");
		return NULL;
	}
	
	printf("client connect arrive.\n");
	
	if((pTemp=malloc(sizeof(struct TcpClientStruct)))==NULL){
		printf("malloc error.\n");
		return NULL;
	}
	bzero((void*)pTemp,sizeof(struct TcpClientStruct));
	pTemp->iSockFd=iNewSockFd;
	pTemp->iMaxSec=	ptHead->iMaxSec;

	GetHostTime(pTemp->sConnectTime);
	strcpy(pTemp->sLastRequestTime,pTemp->sConnectTime);
	strcpy(pTemp->sLastAnswerTime,pTemp->sConnectTime);

	strncpy(pTemp->sIp,inet_ntoa(sPeerAddr.sin_addr),15);
	pTemp->sIp[15]=0;
	AllTrim(pTemp->sIp);
	
	InsertList((LIST**)&(ptHead->pHead),(LIST*)pTemp);

	return pTemp;
}
static int MyTcpRespondMain(struct TcpClientStruct *ptHead)
{
	int	i,iRet;
	MY_FDSET iPreFdSet;
		
	while(1){

		InitMySet(&(ptHead->iFdSet));
		Item2MySet(&(ptHead->iFdSet),ptHead->iSockFd);
		ptHead->iMaxSockFd=ptHead->iSockFd;

		iPreFdSet=ptHead->iFdSet;

		iRet=WaitMySetRead(ptHead->iMaxSockFd+1,
			ptHead->iMaxSec,&iPreFdSet);
		if(iRet<0) return -1;
		if(iRet==0){
                        if(ptHead->OnTimeOut!=NULL)
                                ptHead->OnTimeOut(ptHead);
			continue;
		}
		
		if(SearchMySet(&iPreFdSet,ptHead->iSockFd)!=FOUND)
			continue;

		if(ptHead->OnDataRecv!=NULL){
			/*����recv���������������Զ˶Ͽ�����ʱ������0*/
			i=ptHead->OnDataRecv(ptHead);
			if(i<=0) return i;

		}
	}	
	return 0;
}
static void MyCheckTcpClientList(struct TcpClientStruct **pptHead)
{
	int i=0,pid;
	struct TcpClientStruct *ptHead=*pptHead,*pTemp;
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		pid=waitpid(pTemp->pid,&i,WNOHANG);
		/*�����δ�˳��򷵻�0*/
		if(pid==0) continue;
		
		DeleteList((LIST**)pptHead,(LIST*)pTemp);
		free(pTemp);
		
		if(pid==pTemp->pid){
		
			if(WIFEXITED(i)){
				/*����Ҫд��־*/
				if( WEXITSTATUS(i)==0) i=i;/*д�����˳���־*/
				else i=i;	/*д�쳣�˳���־*/
			}
		}
	}
}
int TcpServerRun(struct TcpServerStruct *ptHead)
{
	MY_FDSET iFdSet,iPreFdSet;
	int iRet,iMaxSockFd;
	struct TcpClientStruct *pTemp;

	InitMySet(&iFdSet);
	Item2MySet(&iFdSet,ptHead->iSockFd);
	iMaxSockFd=ptHead->iSockFd+1;
	
	while(1){
		iPreFdSet=iFdSet;
		iRet=WaitMySetRead(iMaxSockFd,ptHead->iMaxSec,&iPreFdSet);
		
		if(iRet<0) return -1;

		if(iRet==0){
			/*�����˳��Ľ��̣��ڷ�����������*/
			MyCheckTcpClientList(&(ptHead->pHead));
			/*����һ������еĶ���*/
			if(ptHead->OnTimeOut!=NULL)
				ptHead->OnTimeOut(ptHead);
			else
				sleep(1);
			continue;
		}

		/*����������¼���ֱ���˳���*/
		if(SearchMySet(&iPreFdSet,ptHead->iSockFd)!=FOUND) continue;
	
		/*������Ǳ�sock���¼�*/
		if((pTemp=MyTcpConnectAccept(ptHead))==NULL){
			perror("connect reaching");
			return -1;
		}
		/*���ÿͻ�����Ӧ�ĺ�����
		IDLE��READ��WRITE��IDENTIFY*/
		ptHead->InitialClient(pTemp);

		/*��ʼ�����ӽ���*/
		if(ptHead->iChildFlag==true){
			if((pTemp->pid=fork())<0){
				WriteAlertMsg("�����ӽ��̴���,�������˳�");
				exit(1);
			}
		}
		else	pTemp->pid=0;
		
		/*�������Ҫ�ӽ��̾������ӽ��̽�����Ӧѭ����
			����ǲ���Ҫ�ӽ������ø����̽�����Ӧѭ��*/
		if((ptHead->iChildFlag==true&&pTemp->pid==0)||
			ptHead->iChildFlag==false){
				
			/*�رո��׼���ͣ���̵�sock*/
			DisconnectTcpServer(ptHead->iSockFd);

			/*����Э��δ��֤ͨ��*/
			if(pTemp->OnConnectAuth!=NULL){
				/*�����Ȩʧ�����˳�*/
				if(pTemp->OnConnectAuth(pTemp)==false){
					SockSendBuf(pTemp->iSockFd,"����˼�Ȩʧ��",-1);
					CloseSockFd(pTemp->iSockFd);
					exit(0);
				}
			}
			/*�����Ҫ��ʼ�����ҳ�ʼ��ʧ�����˳�*/
			if(pTemp->OnConnect!=NULL){
				if(pTemp->OnConnect()<0){
					SockSendBuf(pTemp->iSockFd,"��ʼ��ʧ��",-1);
					CloseSockFd(pTemp->iSockFd);
					exit(0);
				}
			}
			/*�ӽ���ѭ��*/
			MyTcpRespondMain(pTemp);
			
			if(pTemp->OnDisconnect!=NULL)pTemp->OnDisconnect();
			
			/*�ر��ӽ��̵�ͨ�Ŷ˿�*/
			CloseSockFd(pTemp->iSockFd);
			/*�ӽ��̳ɹ�����*/
			exit(0);
		}
		/*д����������־;;;;*/
		/*������ֱ�ӹر��½����ӵ�sock�˿�*/
		CloseSockFd(pTemp->iSockFd);
	}
	return 0;
}
int ConnectTcpServer(char sIp[],int iPort)
{
	int 	iSockFd;
	struct sockaddr_in sServAddr;
  
	if ((iSockFd=socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("socket!");
		return -1;
  	}
	bzero((void*)&sServAddr,sizeof(struct sockaddr_in));
	sServAddr.sin_family = AF_INET;
	sServAddr.sin_port = htons( iPort );
	sServAddr.sin_addr.s_addr = inet_addr(sIp);
	if(connect(iSockFd,(struct sockaddr*)&sServAddr,
		sizeof(struct sockaddr_in))<0){
		perror("connect");
		/*д���ӷ���������ʧ����־*/
		close(iSockFd);
		return -1;
	}
	return iSockFd;	
}
int DisconnectTcpServer(int iSockFd)
{
	return close(iSockFd);
}
int CloseSockFd(int iSockFd)
{
	return close(iSockFd);
}
int SockSendBuf( int iSockFd, char sMsg[] ,int iLen)
{
	int i,iRet;

	i = iLen;
	if ( i == -1 ) 
		i = strlen( sMsg );
		
	iRet = write( iSockFd, sMsg, i );
	
	return 0;
}

/*
    ��todo:��ʼ��ע�ͱ�ʾδ��ɣ����д����ֵĵط�
    ��done:��ʼ��ע�ͱ�ʾtodo:������״̬�Ѿ���Ϊ���/ȷ��
*/

int InitClientSocket( struct ClientSockStruct *Socket, char sIp[], int iPort, int iSTime )
{
	memset( Socket, 0, sizeof( struct ClientSockStruct ) );
	
	strcpy( Socket-> sIp, sIp );
	Socket->iPort = iPort;
	Socket->iSelectTime = iSTime;

	return 0;
}

int ClientSockConnect ( struct ClientSockStruct *Socket )
{
	int iRet;
	
	iRet = ConnectTcpServer( Socket->sIp, Socket->iPort );
	if ( iRet < 0 ) return iRet;
	
	Socket->iSockFd = iRet;
	Socket->iConnected = 1;
	
	if ( Socket->OnConnect )
		Socket->OnConnect( Socket );
	
	return Socket->iSockFd;
}

int ClientSockDisconnect ( struct ClientSockStruct *Socket )
{
	if ( Socket->iConnected != 1 ) 
		return 0;

	if ( Socket->OnDisconnect )
		return Socket->OnDisconnect( Socket );
		
	/*todo:�Ƿ���Ҫ�ڴ˹ر�sockfd������connected�أ�
		������Ҫ����OnDisconnect�ķ���ֵ���ж��������?
		�ж������ӣ�	
	*/
		
	return 0;

}

int SockSendData ( int iSockFd, char sBuffer[], int iLen )
{
	int iSendedLen,iSendLen = iLen;
	
	if ( iLen ==  -1 )
		iSendLen = strlen( sBuffer );
	
	if ( iSendLen == 0 )
		return 0;
	
	iSendedLen = write( iSockFd, sBuffer, iSendLen );
	
	if ( iSendedLen <0 || iSendedLen !=  iSendLen )
		return -1;
	
	return iSendedLen;	
}

int SockRecvData ( int iSockFd, char sBuffer[], int iMaxLen )
{
	int iReadLen;
	
	sBuffer[0] = '\0';
	
	/*todo:iMaxLen==-1ʱ�����⴦��*/

	if ( iMaxLen == 0 )
		return 0;
	
	iReadLen = read( iSockFd, sBuffer, iMaxLen );
	
	return iReadLen;		
		
}

int ClientSockProcMain(struct ClientSockStruct *Socket)
{
	char sBuffer[8192];
	MY_FDSET iFdSet,iPreFdSet;
	int iRet,i,iMaxSec,iLen,iMaxFd = Socket->iSockFd+1;
	
	if (Socket->iConnected==0) return 0;
	
	/*done:assert����ָ���ĺ���ָ��*/
	assert( Socket->ProcCmd );
	assert( Socket->OnError );
	assert( Socket->OnTimeOut );
	assert( Socket->OnDisconnect );
	assert( Socket->OnDataRecv );
	assert( Socket->OnConnect );			
	
	/*�Ѷ���MainLoop*/
	if (Socket->ClientSockProcMain)
		return Socket->ClientSockProcMain(Socket);
	
	InitMySet( &iFdSet );
	Item2MySet( &iFdSet, Socket->iSockFd );

	while(Socket->iTerminate==0){
		
		iPreFdSet=iFdSet;
		
		if ( Socket->iConnected == 0 ) return 0;
		
		Socket->ProcCmd( Socket );
		
		iMaxSec = Socket->iSelectTime;
		if ( Socket->iBlock == 1 ) iMaxSec = 0;
		
		iRet=WaitMySetRead( iMaxFd, iMaxSec, &iPreFdSet);
		
		if(iRet<0){
			perror("select");
		ErrorHandle:
			DeleteMySet( &iFdSet, Socket->iSockFd );
			
			i = Socket->OnError( Socket );
			if ( i != 0 ) return -1;
			
			Item2MySet( &iFdSet, Socket->iSockFd );
			iMaxFd = Socket->iSockFd+1;
			continue;
		}
		if(iRet==0){
			Socket->OnTimeOut( Socket );
			continue;
		}
		/*�����ݹ���*/
		if(SearchMySet( &iFdSet, Socket->iSockFd)==FOUND){
			if (Socket->OnRead==NULL){
				iLen=SockRecvData(Socket->iSockFd,sBuffer,
					sizeof( sBuffer )-1);

				/*�Է��Ͽ�*/
				if(iLen==0)
					return Socket->OnDisconnect(Socket);

				/*����*/
				if(iLen<0) goto ErrorHandle;

				sBuffer[iLen]=0;
				Socket->OnDataRecv(Socket,sBuffer,iLen);
			}
			else
				Socket->OnRead( Socket );
		}
	}
	
	return 0;
}

struct ClientSockStruct *NewClientSocket( char sIp[], int iPort, int iSTime )
{
	struct ClientSockStruct *pRes = NULL;
	
	pRes = malloc(sizeof( struct ClientSockStruct ) );
	if ( pRes == NULL ){
                puts("Ϊ�ڵ�����ڴ�ʧ��!\n");
                WriteErrStackAlert();
                exit(-1);
	}	
	
	InitClientSocket( pRes, sIp, iPort, iSTime );
	
	return pRes;
}

int ServerSockListen(struct ServerSockStruct *Socket,char sIp[],int iPort,
	int iAllowConnect, int iSTime)
{
	int 	iSockFd;
	struct sockaddr_in sMyAddr;
  	
	memset( Socket, 0, sizeof( struct ServerSockStruct ) );
	
	strcpy( Socket-> sIp, sIp );
	Socket->iPort = iPort;
	Socket->iSelectTime = iSTime;
	Socket->iAllowConnect = iAllowConnect;	

	if ((iSockFd=socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("socket!");
		return -1;
  	}
	bzero((void*)&sMyAddr,sizeof(struct sockaddr_in));
	sMyAddr.sin_family = AF_INET;
	sMyAddr.sin_port = htons( Socket->iPort );
	sMyAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(iSockFd,(struct sockaddr*)&sMyAddr,
		sizeof(struct sockaddr_in))==-1){
		perror("bind");
		close(iSockFd);
		return -1;
	}
  
	if (listen(iSockFd,5)==-1){
  		perror("listen");
		close(iSockFd);
  		return -1;
	}
	
	Socket->iListen = 1;
	Socket->iSockFd = iSockFd;
	
	if(Socket->OnListen) Socket->OnListen(Socket);
	
	return 0;
}

static struct ClientSockList *ServerSockAccept( struct ServerSockStruct *Socket )
{
	int iAddrLen;
	int iNewSockFd;
	struct sockaddr_in sPeerAddr;
	struct ClientSockList *pTemp;

	iNewSockFd=accept(Socket->iSockFd,(struct sockaddr *)&sPeerAddr,
		&iAddrLen);
	
	if(iNewSockFd==-1){
		printf("accept error.\n");
		return NULL;
	}
	
	if((Socket->iClientNumber+1)>Socket->iAllowConnect){
		puts("���������������");
		close( iNewSockFd );
		return NULL;
	}
	
	if((pTemp=malloc(sizeof(struct ClientSockList)))==NULL){
		printf("malloc error.\n");
		return NULL;
	}
	bzero((void*)pTemp,sizeof(struct ClientSockList));
	pTemp->iSockFd=iNewSockFd;
	
	strncpy(pTemp->sIp,inet_ntoa(sPeerAddr.sin_addr),15);
	pTemp->sIp[15]=0;
	AllTrim(pTemp->sIp);
	
	InsertList((LIST**)&(Socket->ClientList),(LIST*)pTemp);
	
	Socket->iClientNumber++;

	return pTemp;	
}

static void CleanClientList( struct ClientSockList  **pptHead ) 
{ 
	int  i=0,iRet; 
	struct ClientSockList *ptHead=(*pptHead),*pTemp;
	
	while(ptHead!=NULL){
		
		pTemp = ptHead;
		ptHead = ptHead->pNext;
		
		printf("pid:%d\n", pTemp->pid );
		/*����Ƿ��˳������˳�������*/
		 
		if( ( iRet = waitpid(pTemp->pid,&i,WNOHANG) ) == 0 ) continue;
		
		printf("iRet:%d\n",iRet);
		
		if(WIFEXITED(i)){
			/*����Ҫд��־*/
			if( WEXITSTATUS(i)==0) i=i;/*д�����˳���־*/
			else i=i;	/*д�쳣�˳���־*/
			DeleteList((LIST**)pptHead,(LIST*)pTemp);
			free(pTemp);
		}
	}
}

int ServerSockProcMain ( struct ServerSockStruct *Socket )
{
	MY_FDSET iFdSet,iPreFdSet;
	struct ClientSockList *pTemp;
	int i,iRet,iMaxSec,iMaxSockFd;

	InitMySet(&iFdSet);
	Item2MySet(&iFdSet,Socket->iSockFd);
	iMaxSockFd=Socket->iSockFd+1;
		
	while( Socket->iTerminate == 0 ){
		
		iPreFdSet=iFdSet;
		
		if ( Socket->iListen == 0 ) return 0;
		
		Socket->ProcCmd(Socket);		
		
		iMaxSec = Socket->iSelectTime;
		if ( Socket->iBlock == 1 ) iMaxSec = 0;
			
		iRet=WaitMySetRead( iMaxSockFd, iMaxSec, &iPreFdSet);
		
		switch(iRet){
		case -1:
			perror("select");
			DeleteMySet( &iFdSet, Socket->iSockFd );
			
			i = Socket->OnError( Socket );
			if ( i != 0 ) return -1;
			
			Item2MySet( &iFdSet, Socket->iSockFd );
			iMaxSockFd = Socket->iSockFd+1;
			continue;
			
			break;
		case 0:
			/*�����˳��Ľ��̣��ڷ�����������*/
			CleanClientList(&(Socket->ClientList));

			Socket->OnTimeOut( Socket );
							
			break;
		default:
			/*����������¼���ֱ���˳���*/
			if(SearchMySet(&iPreFdSet, Socket->iSockFd)!=FOUND)
				break;

			/*�пͻ�������*/
			if((pTemp=ServerSockAccept(Socket))==NULL) break;
			
			/*��δ���*/
			Socket->OnClientConnect(Socket,pTemp);
			
			break;			
		}
	}
	return 0;		
}


/*onClientConnectʾ��*/
void ServerOnClientConnect(struct ServerSockStruct *Socket,
	struct ClientSockList *Client)
{
	struct ClientSockStruct *ClientSocket = &( Socket->ClientEvent );

	if(( Client->pid = fork( ) )<0){
		WriteAlertMsg("�����ӽ��̴���,�������˳�");
		exit(1);
	}
	
	/* parent */
	if ( Client->pid != 0 ) return;
				
	/*�رո��׼���ͣ���̵�sock*/
	DisconnectTcpServer( Socket->iSockFd );
	
	/*��Ϊģ��ͻ��ˣ����Բ���Ҫ���ӣ����������±�־*/
	ClientSocket->iSockFd = Client->iSockFd;
	ClientSocket->iConnected = true;

	ClientSockProcMain( ClientSocket );
	
	exit(0);
}

int InitTcpServer(int iPort,int iMaxConnect)
{
	int fd;
	struct sockaddr_in sMyAddr;

	if((fd=socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket!");
		return -1;
  	}

	sMyAddr.sin_family= AF_INET;
	sMyAddr.sin_port= htons(iPort);
	sMyAddr.sin_addr.s_addr= htonl(INADDR_ANY);
	bzero(&(sMyAddr.sin_zero),sizeof(sMyAddr.sin_zero));

	if(bind(fd,(struct sockaddr *)&sMyAddr,
		sizeof(struct sockaddr_in))==-1){
		perror("bind");
		return -1;
	}

	if(listen(fd,iMaxConnect)==-1){
  		perror("LISTEN");
  		return -1;
	}

	return fd;
}
