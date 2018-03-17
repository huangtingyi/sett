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
	char	sIp[16];		/*营帐接口客户端的IP*/
	char	sUserName[128];
	char	sPassword[128];
	int	iFailTimes;		/*失败次数,最大为３次*/
	int	iMaxSec;		/*监听端口的超时秒数*/
	pid_t	pid;			/*服务守护进程的PID*/
	char	sConnectTime[15]; 	/*accept时间*/
	char	sLastRequestTime[15];	/*服务申请时间*/
	char	sLastAnswerTime[15];	/*服务响应时间*/
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
	char	sIp[16];/*服务器本身的IP*/
	int	iPort;  /*服务器本身的监听端口*/
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
/*建立Tcp服务并监听*/
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
Socket client 结构
 
 以下说明MainLoop事情为系统默认时有效：
 iBlock 设置是否阻塞
    0(default):非阻塞
    1：阻塞
 当iBlock设置为阻塞状态时iSelectTime无效。
 当iSelectTime设置为0时不管iBlock何值，socket为阻塞状态。
 TerminateFlag 为 MainLoop出标记,不为0时退出循环
 OnDataRecv事情触发时数据已经被读入到缓冲区中，
 如果需要定义可读或可写事件可以设定OnRead及OnWrite事件，但OnRead事件与OnDataRecv互斥
 OnRead事件设定时OnDataRecv将不会被触发.
 OnError事件触发时，返回值为0时将不退出MainLoop(已经重新连接并设置iSocketFd或执行了其它操作)
 	否则将以返回值退出MainLoop
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
	
	/*MainLoop退出标记,不为0时退出循环*/
	int iTerminate;	

	/*可以定制但一般情况下不需要设置这个值*/
	int (*ClientSockProcMain)( struct ClientSockStruct *Socket);
	/*可以自定义读写事件*/
	int (*OnRead)(struct ClientSockStruct *Socket);
	int (*OnWrite)(struct ClientSockStruct *Socket);

	/*以下无需手工设置*/	
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
	pid_t	pid;	/*服务守护进程的PID*/	
};

struct ServerSockStruct{
	
	char sIp[16];
	int iPort;
	int iBlock;
	int iSelectTime;
	int iAllowConnect; /*允许连接数*/
	/*MainLoop退出标记,不为0时退出循环*/
	int iTerminate;
	
	/*客户端链表*/
	struct ClientSockList *ClientList;
	
	/*客户端事件处理*/
	struct ClientSockStruct ClientEvent;
		
	void (*OnClientConnect)( struct ServerSockStruct *Socket,
		struct ClientSockList *Client); /*处理CLIENT链接后的fork等*/
	int (*OnListen)(struct ServerSockStruct *Socket);
	int (*OnError)(struct ServerSockStruct *Socket);
	int (*OnTimeOut)(struct ServerSockStruct *Socket);
	int (*ProcCmd)(struct ServerSockStruct *Socket);
		
	/*详细解释见ClientSocket中的说明*/
	int (*ServerSockProcMain)(struct ServerSockStruct *Socket);

	/*以下无需手工设置*/	
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

