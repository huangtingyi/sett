#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wwnet.h>
#include "wwtelnet.h"

void OnDataRecv( struct TelnetStruct *serv, char sData[] )
{
	puts("onDataAvaliable--------------------------");
	puts(sData);
	sleep(1);
}
void OnLogin( struct TelnetStruct *serv, char sData[] )
{
	puts("OnLogin");
}
void OnTimeOut( struct TelnetStruct *serv )
{
	puts("OnTimeOut");
}
void OnError( struct TelnetStruct *serv, char sMsg[], int iErrNo )
{
	puts("OnError");
	puts(sMsg);
}
void ProcCommand( struct TelnetStruct *serv )
{
	puts("onProcCommand");
	SockSendBuf( serv->iSockFd ,"./a.sh\n",-1);
}

void OnDisconnect( struct TelnetStruct *serv )
{
	puts("OnDisconnect");
}


int main( int argc, char *argv[] )
{                       
	struct TelnetStruct serv;
	
	TelnetInitial( &serv, "130.38.8.99",23,"bill","hell",
			"login","assword","Welcome");
			
	serv.OnLogined = OnLogin;
	serv.OnTimeOut = OnTimeOut;
	serv.OnError = OnError;
	serv.ProcCmd = ProcCommand;
	serv.OnDataRecv = OnDataRecv;
	serv.OnDisconnect = OnDisconnect;
		
	TelnetProcMain( &serv );
	
	return 0;
}
