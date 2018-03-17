#include <stdio.h>
#include <stdlib.h>

#include <wwnet.h>

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
	puts("OnDataRecv");
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


int main( int argc, char **argv )
{
	struct ClientSockStruct Socket;
	
	InitClientSocket( &Socket, "130.38.8.110", 80, 20 );
	
	Socket.OnConnect	= OnConnect;
	Socket.OnDisconnect	= OnDisconnect;
	Socket.OnDataRecv	= OnDataRecv;
	Socket.OnError		= OnError;
	Socket.OnTimeOut	= OnTimeOut;
	Socket.ProcCmd	= ProcessCommand;
		
	ClientSockConnect ( &Socket );
	
	ClientSockProcMain( &Socket );
	
	return 0;
}

