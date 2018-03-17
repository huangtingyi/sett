#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#include <errno.h>

#ifndef TIOCNOTTY
#define TIOCNOTTY     _IO('t', 113)
#endif

#define  TCP_PROTO      "tcp"

int iProxyPort;                 /* port to listen for proxy connections on */
struct sockaddr_in sHostAddr;    /* host addr assembled from gethostbyname() */

extern int errno;              /* defined by libc.a */
extern char *sys_errlist[];    /* defined by libc.a */
void reap_status (int i)
{
}
void errorout (char *msg)
{
	FILE *console;

	console = fopen("/dev/console","a");
	fprintf(console,"proxyd: %s\r\n",msg);
	fclose(console);
	exit(1);
}
void parse_args (int argc,char *argv[])
{
	int i;
	struct hostent *hostp;
	struct servent *servp;
	unsigned long inaddr;
	struct {
		char iProxyPort [16];
		char isolated_host [64];
		char service_name [32];
	} pargs;


	if (argc < 4) {
		printf("usage:  %s <proxy-port> <host> <service-name|port-number>\r\n",
	         argv[0]);
		exit(1);
	}

	strcpy(pargs.iProxyPort,argv[1]);
	strcpy(pargs.isolated_host,argv[2]);
	strcpy(pargs.service_name,argv[3]);

	for (i = 0;  i < strlen(pargs.iProxyPort);  i++){
	  	if (!isdigit(*(pargs.iProxyPort + i))){
	  		printf("%s: invalid proxy port\r\n",pargs.iProxyPort);
	 		exit(0);
	  	}
	}
	iProxyPort = htons(atoi(pargs.iProxyPort));

	bzero(&sHostAddr,sizeof(sHostAddr));
	sHostAddr.sin_family = AF_INET;

	if((inaddr=inet_addr(pargs.isolated_host))!=INADDR_NONE)
		bcopy(&inaddr,&sHostAddr.sin_addr,sizeof(inaddr));
	else if((hostp = gethostbyname(pargs.isolated_host))!= NULL)
		bcopy(hostp->h_addr,&sHostAddr.sin_addr,hostp->h_length);
	else {
		printf("%s: unknown host\r\n",pargs.isolated_host);
		exit(1);
	}

	if((servp = getservbyname(pargs.service_name,TCP_PROTO))!=NULL)
		sHostAddr.sin_port = servp->s_port;
	else if(atoi(pargs.service_name)>0)
		sHostAddr.sin_port = htons(atoi(pargs.service_name));
	else {
		printf("%s: invalid/unknown service name or port number\r\n",
		pargs.service_name);
		exit(1);
	}
}

void daemonize (int servfd)
{
	int childpid, fd, len;

	/* ignore terminal I/O, stop signals */
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTTIN,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);

	/* fork to put us in the background (whether or not the user
	   specified '&' on the command line */

	if((childpid = fork())<0) {
		fprintf(stderr,"failed to fork first child\r\n");
		exit(1);
	}

	if(childpid>0)exit(0);    /* terminate parent, continue in child */

	/* dissociate from process group */
	if(setpgrp()<0) {
		fprintf(stderr,"failed to become process group leader\r\n");
		exit(1);
	}

/* lose controlling terminal */
	if((fd=open("/dev/tty",O_RDWR))>=0) {
		ioctl(fd,TIOCNOTTY,NULL);
		close(fd);
	}

/* close any open file descriptors */
	len=getdtablesize();

	for(fd=0;fd<len;fd++){
		if (fd != servfd)close(fd);
	}

/* set working directory to / to allow filesystems to be unmounted */
	chdir("/");
	/* clear the inherited umask */
	umask(0);
	/* setup zombie prevention */
	signal(SIGCLD,reap_status);

}

void do_proxy (int usersockfd)
{
	int isosockfd;
	fd_set rdfdset;
	int connstat,iolen;
	char buf [2048];

	/* open a socket to connect to the isolated host */
	if ((isosockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	  	errorout("failed to create socket to host");

	/* attempt a connection */
	connstat = connect(isosockfd,
		(struct sockaddr *) &sHostAddr,sizeof(sHostAddr));

	switch (connstat) {
		case 0:   break;
		case ETIMEDOUT:
		case ECONNREFUSED:
		case ENETUNREACH:
			strcpy(buf,sys_errlist[errno]);
			strcat(buf,"\r\n");
			write(usersockfd,buf,strlen(buf));
			close(usersockfd);
			exit(1);/* die peacefully if we can't establish a connection */
			break;
		default:
			errorout("failed to connect to host");
	}

	/* now we're connected, serve fall into the data echo loop */
	while (1) {
		/* Select for readability on either of our two sockets */
		FD_ZERO(&rdfdset);
		FD_SET(usersockfd,&rdfdset);
		FD_SET(isosockfd,&rdfdset);

		if(select(FD_SETSIZE,&rdfdset,NULL,NULL,NULL) < 0)
			errorout("select failed");

		/* is the client sending data? */
		if (FD_ISSET(usersockfd,&rdfdset)) {
			 /* zero length means the client disconnected */
			if ((iolen = read(usersockfd,buf,sizeof(buf))) <= 0)
				break;  
			/* copy to host -- blocking semantics */
			write(isosockfd,buf,iolen);   
		}

		/* is the host sending data? */
		if (FD_ISSET(isosockfd,&rdfdset)) {
			 /* zero length means the host disconnected */
			if ((iolen = read(isosockfd,buf,sizeof(buf))) <= 0)
				break;  
			/* copy to client -- blocking semantics */
			write(usersockfd,buf,iolen);  
		}
	}

	/* we're done with the sockets */
	close(isosockfd);
	close(usersockfd);
}


int main (int argc,char *argv[])
{
	int iClientLen;
	int childpid;
	int sockfd, newsockfd;
	struct sockaddr_in sServAddr, sClientAddr;

	parse_args(argc,argv);


/* prepare an address struct to listen for connections */
/*初始化一个地址结构给监听连结*/
	bzero((char *)&sServAddr, sizeof(struct sockaddr_in));
	sServAddr.sin_family = AF_INET;
	sServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sServAddr.sin_port = iProxyPort;

/* get a socket... */
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
		fprintf(stderr,"failed to create server socket\r\n");
		exit(1);
	}
/* ...and bind our address and port to it */
	if(bind(sockfd,(struct sockaddr*) &sServAddr,
		sizeof(struct sockaddr_in))<0){
		fprintf(stderr,"faild to bind server socket to specified port\r\n");
		exit(1);
	}
/* get ready to accept with at most 5 clients waiting to connect */
	listen(sockfd,5);

/* turn ourselves into a daemon */
	daemonize(sockfd);

/* fall into a loop to accept new connections and spawn children */
	while(1){

 /* accept the next connection */
		iClientLen = sizeof(sClientAddr);

		newsockfd = accept(sockfd,
			(struct sockaddr*)&sClientAddr,&iClientLen);
/* a signal might interrupt our accept() call */
 		if(newsockfd<0&&errno==EINTR)   continue;

/* something quite amiss -- kill the server */
   		if(newsockfd<0) errorout("failed to accept connection");

/* fork a child to handle this connection */
		if ((childpid=fork())== 0){
			close(sockfd);
			do_proxy(newsockfd);
			exit(0);
		}
    /* if fork() failed, the connection is silently dropped -- oops! */
		close(newsockfd);
  	}
  	return 0;
}


