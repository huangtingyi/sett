#ifndef __WWNET_H__
#define __WWNET_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
/*
#ifndef _MY_FDSET
#include <sys/select.h>
#endif
*/
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MY_FDSET fd_set

struct TcpConnectStruct
{
	struct TcpConnectStruct *pNext;
	char	sIp[16];
	int	iPort;
};
struct TcpClientStruct
{
	struct TcpClientStruct *pNext;
	int	iSockFd;
	char	sIp[16];		/*Ӫ�ʽӿڿͻ��˵�IP*/
	char	sUserName[128];
	char	sPassword[128];
	int	iFailTimes;		/*ʧ�ܴ���,���Ϊ����*/
	int	iMaxSec;		/*�����˿ڵĳ�ʱ����*/
	pid_t	pid;			/*�����ػ����̵�PID*/
	char	sConnectTime[15]; 	/*acceptʱ��*/
	char	sLastRequestTime[15];	/*��������ʱ��*/
	char	sLastAnswerTime[15];	/*������Ӧʱ��*/
	void	(*OnTimeOut)(struct TcpClientStruct *);
	int	(*OnConnectAuth)(struct TcpClientStruct *);
	int	(*OnDataRecv)(struct TcpClientStruct *);
	int	(*OnConnect)();
	int	(*OnDisconnect)();

	MY_FDSET iFdSet;
	int	iMaxSockFd;
	
	struct	FileControlStruct *pRead;
	struct	FileControlStruct *pWrite;
};
struct TcpServerStruct 
{
	int	iSockFd;
	int	iChildFlag;
	int	iMaxConnect;
	int	iMaxSec;
	char	sIp[16];/*�����������IP*/
	int	iPort;  /*����������ļ����˿�*/
	void	(*OnTimeOut)(struct TcpServerStruct *);
	void	(*InitialClient)(struct TcpClientStruct *);
	struct TcpClientStruct *pHead;
};

void InitMySet(MY_FDSET *piFdSet);
void Item2MySet(MY_FDSET *piFdSet,int iSockFd);
int SearchMySet(MY_FDSET *piFdSet,int iSockFd);
void DeleteMySet(MY_FDSET *piFdSet,int iSockFd);

int FD_DataReady(int iFd);
int WaitMySetRead(int iMaxFd,int iMaxSec,MY_FDSET *piFdSet);
int WaitMySetWrite(int iMaxFd,int iMaxSec,MY_FDSET *piFdSet);
int WaitMySetAll(int iMaxFd,int iMaxSec,
	MY_FDSET *piReadFdSet,MY_FDSET *piWriteFdSet,MY_FDSET *piErrFdSet);
/*����Tcp���񲢼���*/
struct TcpServerStruct *CreateTcpServer(int iPort,int iChildFlag,
	int iMaxConn,int iMaxSec,void (*OnTimeOut)(struct TcpServerStruct *),
	void (*InitialClient)(struct TcpClientStruct *));
int TcpServerRun(struct TcpServerStruct *ptHead);

int ConnectTcpServer(char sIp[],int iPort);
int DisconnectTcpServer(int iSockFd);
int CloseSockFd(int iSockFd);

void tcp_server_time_out(struct TcpServerStruct *ptHead);
void tcp_client_time_out(struct TcpClientStruct *ptHead);
int  tcp_connect_auth(struct TcpClientStruct *ptHead);
int  tcp_data_recv(struct TcpClientStruct *ptHead);
int  tcp_data_send(struct TcpClientStruct *ptHead);
void tcp_initial_client(struct TcpClientStruct *ptHead);

int SockSendBuf( int iSockFd, char sMsg[] ,int iLen);

/*
Socket client �ṹ
 
 ����˵��MainLoop����ΪϵͳĬ��ʱ��Ч��
 iBlock �����Ƿ�����
    0(default):������
    1������
 ��iBlock����Ϊ����״̬ʱiSelectTime��Ч��
 ��iSelectTime����Ϊ0ʱ����iBlock��ֵ��socketΪ����״̬��
 TerminateFlag Ϊ MainLoop�����,��Ϊ0ʱ�˳�ѭ��
 OnDataRecv���鴥��ʱ�����Ѿ������뵽�������У�
 �����Ҫ����ɶ����д�¼������趨OnRead��OnWrite�¼�����OnRead�¼���OnDataRecv����
 OnRead�¼��趨ʱOnDataRecv�����ᱻ����.
 OnError�¼�����ʱ������ֵΪ0ʱ�����˳�MainLoop(�Ѿ��������Ӳ�����iSocketFd��ִ������������)
 	�����Է���ֵ�˳�MainLoop
*/

struct ClientSockStruct
{
	char sIp[16];
	int iPort;
	int iBlock;
	int iSelectTime;	
	
	int (*OnConnect)( struct ClientSockStruct *Socket);
	int (*OnDisconnect)(struct ClientSockStruct *Socket);
	int (*OnDataRecv)(struct ClientSockStruct *Socket,char sData[],int iLen);
	int (*OnError)( struct ClientSockStruct *Socket);
	int (*OnTimeOut)( struct ClientSockStruct *Socket);	
	int (*ProcCmd)( struct ClientSockStruct *Socket);
	
	/*MainLoop�˳����,��Ϊ0ʱ�˳�ѭ��*/
	int iTerminate;	

	/*���Զ��Ƶ�һ������²���Ҫ�������ֵ*/
	int (*ClientSockProcMain)( struct ClientSockStruct *Socket);
	/*�����Զ����д�¼�*/
	int (*OnRead)(struct ClientSockStruct *Socket);
	int (*OnWrite)(struct ClientSockStruct *Socket);

	/*���������ֹ�����*/	
	int iSockFd;
	int iConnected;

};

struct ClientSockStruct *NewClientSocket( char sIp[], int iPort, int iSTime);
int InitClientSocket(struct ClientSockStruct *Socket,char sIp[],int iPort,int iSTime);
int ClientSockConnect(struct ClientSockStruct *Socket);
int ClientSockDisconnect(struct ClientSockStruct *Socket);
int SockSendData (int iSockFd, char sBuffer[], int iLen);
int SockRecvData (int iSockFd, char sBuffer[], int iMaxLen);
int ClientSockProcMain (struct ClientSockStruct *Socket);

struct ClientSockList{
	struct ClientSockList *pNext;
	int iSockFd;
	char sIp[16];
	pid_t	pid;	/*�����ػ����̵�PID*/	
};

struct ServerSockStruct{
	
	char sIp[16];
	int iPort;
	int iBlock;
	int iSelectTime;
	int iAllowConnect; /*����������*/
	/*MainLoop�˳����,��Ϊ0ʱ�˳�ѭ��*/
	int iTerminate;
	
	/*�ͻ�������*/
	struct ClientSockList *ClientList;
	
	/*�ͻ����¼�����*/
	struct ClientSockStruct ClientEvent;
		
	void (*OnClientConnect)( struct ServerSockStruct *Socket,
		struct ClientSockList *Client); /*����CLIENT���Ӻ��fork��*/
	int (*OnListen)(struct ServerSockStruct *Socket);
	int (*OnError)(struct ServerSockStruct *Socket);
	int (*OnTimeOut)(struct ServerSockStruct *Socket);
	int (*ProcCmd)(struct ServerSockStruct *Socket);
		
	/*��ϸ���ͼ�ClientSocket�е�˵��*/
	int (*ServerSockProcMain)(struct ServerSockStruct *Socket);

	/*���������ֹ�����*/	
	int iSockFd;
	int iListen;
	int iClientNumber;
};

int ServerSockListen(struct ServerSockStruct *Socket,char sIp[],int iPort,
	int iAllowConnect,int iSTime);
int ServerSockProcMain(struct ServerSockStruct *Socket);
void ServerOnClientConnect(struct ServerSockStruct *Socket,
	struct ClientSockList *Client);

int InitTcpServer(int iPort,int iMaxConnect);

#endif

