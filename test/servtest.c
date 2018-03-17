#include <stdlib.h>
#include <stdio.h>
#include  <wwnet.h>

int OnConnect( struct ClientSockStruct *Socket )
{
	puts("OnConnect");
	return 0;
}
int OnDisconnect( struct ClientSockStruct *Socket )
{
	puts("OnDisconnect");
	return 0;
}
int OnDataRecv( struct ClientSockStruct *Socket, char sData[], int iLen )
{
	puts("onDataAvalible");
	puts(sData);
	return 0;
}
int OnError( struct ClientSockStruct *Socket )
{
	puts("OnError");
	return 0;
}
int OnTimeOut( struct ClientSockStruct *Socket )
{
	puts("OnTimeOut");
	return 0;
}
int ProcessCommand( struct ClientSockStruct *Socket )
{
	puts("ProcessCommand");
	SockSendData( Socket->iSockFd, "GET /\n", -1 );
	return 0;
}
                    
int ServOnError( struct ServerSockStruct *Socket )
{
	puts("ServoOnError ");
	return 0;
}
int ServOnTimeOut( struct ServerSockStruct *Socket )
{
	puts("ServoOnTimeOut ");
	return 0;
}
int ServonProcessCommand( struct ServerSockStruct *Socket )
{
	puts("ServoProcessCommand ");
	return 0;
}
int main( int argc, char **argv )
{
	struct ServerSockStruct serv;
	struct ClientSockStruct *ClientSocket = &(serv.ClientEvent);
	
	
	ServerSockListen( &serv, "127.0.0.1", 7799, 100, 20 );

	/*子进程处理*/
	InitClientSocket( ClientSocket, "127.0.0.1", 0, 20 );
	
	ClientSocket->OnConnect		= OnConnect;
	ClientSocket->OnDisconnect	= OnDisconnect;
	ClientSocket->OnError		= OnError;
	ClientSocket->OnDataRecv	= OnDataRecv;
	ClientSocket->OnTimeOut		= OnTimeOut;
	ClientSocket->ProcCmd	= ProcessCommand;	
	
	serv.OnClientConnect	= ServerOnClientConnect;
	serv.OnError		= ServOnError;
	serv.OnTimeOut		= ServOnTimeOut;
	serv.ProcCmd	= ServonProcessCommand;
	
	ServerSockProcMain( &serv );
	
	return 0;
}

