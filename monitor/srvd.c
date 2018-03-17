#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#ifndef _FD_SET
#include <sys/select.h>
#endif
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include "srvd.h"
#include "list.h"
#include "wwfile.h"
#include "wwtiny.h"
#include "hnixs.h"
#include "wwlog.h"
#include "wwnet.h"

#include "wwhttpd.h"

void catch_sig_term(int sig)
{
	WriteProcMsg("monitor:catchsig(%d) happen!\n",sig);
	printf("monitor:catchsig(%d) happen!\n",sig);
        WriteProcMsg("monitor:遇到某些错误，进程退出 \n");
        printf("monitor:遇到某些错误，进程退出 \n");
        exit(0);
}

int main(int argc,char *argv[],char *envp[])
{
	char sBuff[MAXLEN];
	struct sockaddr_in client_addr_in;
	int sd,cd,port,iRet,len,client_addr_in_len=sizeof(client_addr_in);

	if(argc!=2){
		printf("Usage: %s httpd.conf\n",argv[0]);
		return -1;
	}

	InitAppRes(argv[0]);

	InitParamFileName(argv[1]);

	/**检查参数合法性*******/
	if(IsFile(argv[1])==FALSE){
		printf("输入配置文件%s无效.\n",argv[1]);
		return -1;
	}

	if((port=PARAMI("port"))==0) port=PORT;

	/*初始化服务器*/
	if((sd=InitTcpServer(port,10))==-1){

  		perror("InitTcpServer");
  		exit(1);
	}

	/*****************2004.02.05***************************/
	signal(SIGCLD,SIG_IGN);
	signal(SIGTERM,catch_sig_term);
	signal(SIGKILL,catch_sig_term);
	signal(SIGPIPE,SIG_IGN);
	signal(SIGSEGV,catch_sig_term);
	signal(SIGQUIT,catch_sig_term);
	signal(SIGTERM,catch_sig_term);
	signal(SIGABRT,catch_sig_term);
	signal(SIGSTOP,catch_sig_term);
	signal(SIGINT,catch_sig_term);
	/*****************2004.02.05**************************/

	while(1){

		if((cd=accept(sd,(struct sockaddr *)&client_addr_in,
			&client_addr_in_len))==-1){
			perror("accept");
			return -1;
		}

		if(fork()==0){

			if((iRet=fork())!=0) exit(0);

			close(sd);
			if((len=recv(cd,&sBuff,sizeof(sBuff),0))<=0){
				perror("RECV");
				exit(-1);
			}
			wwHttpRequest(cd,inet_ntoa(client_addr_in.sin_addr),
				sBuff,len,envp);
			exit(0);
		}
		wait(&iRet);
		close(cd);
	}

	close(sd);
  	return 0;
}
