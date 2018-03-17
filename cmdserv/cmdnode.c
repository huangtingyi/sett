#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "list.h"
#include "wwfile.h"
#include "wwnet.h"

int cmd_node_on_client_write(struct TcpClientStruct *ptHead)
{
	int n;
	char buf[1024];
	struct FileControlStruct *pTemp=NULL;
		
	printf("client write event arrive.\n");
	
	n=recv(ptHead->iSockFd,buf,1024,0);
	
	if(n<1024) buf[n]=0;
	else buf[1023]=0;
	
	printf(" recive message::|%s|.%s\n",buf,ptHead->sIp);

	if(n>0){
		if(item2list(&pTemp,buf,n)<0){
			printf("%s¼Óµ½Á´±íÊ§°Ü.\n",buf);
			return -1;
		}
	
		if(list2fd(&pTemp,dup(ptHead->iSockFd))<0){
			printf("Ð´ÃüÁîÇëÇóÊ§°Ü.\n");
			return -1;
		}
	}

	return n;
}
void my_initial_client(struct TcpClientStruct *ptHead)
{
	ptHead->OnTimeOut	=tcp_client_time_out;
	ptHead->OnConnectAuth	=NULL;
	ptHead->OnDataRecv	=cmd_node_on_client_write;
	ptHead->OnConnect	=NULL;
	ptHead->OnDisconnect	=NULL;
}


int main(int argc,char *argv[])
{
	int	iPort;
	struct TcpServerStruct *pServer=NULL;

	if(argc!=2){
		printf("Usage: %s port.\n",argv[0]);
		return 0;
	}
	
	iPort=atoi(argv[1]);
	
	pServer=CreateTcpServer(iPort,false,5,3,
		tcp_server_time_out,my_initial_client);
	
	TcpServerRun(pServer);
	
	return 0;
}
