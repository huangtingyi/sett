#!/bin/sh

if [ $# -gt 2 ]; then
	echo "Usage $0 [clean|installxxxx] [sybase|oracle]"
	exit 1
fi

makeflag=$1
dbopt=$2

COMPILER="cc"
CFLAGS="-g -Ae +u1 +DD64"

ccdvproc()
{
	cat > ccdv.c << 'EOF'
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SETCOLOR_SUCCESS	(ASNIESC ? "\033\1331;32m" : "")
#define SETCOLOR_FAILURE	(ASNIESC ? "\033\1331;31m" : "")
#define SETCOLOR_WARNING	(ASNIESC ? "\033\1331;33m" : "")
#define SETCOLOR_NORMAL		(ASNIESC ? "\033\1330;39m" : "")

#define INDENT 2

int ASNIESC = 0;
#define TERMS "vt100:vt102:vt220:vt320:xterm:ansi:linux:scoterm:scoansi:dtterm:cons25:cygwin"

const char *Basename(const char *path);
int Precompiler(char sCommand[]);
void CloseStdin();

void TransTarget(char sTarget[])
{
	char *pc,sTemp[8192];
	if((pc=strrchr(sTarget,'='))!=NULL)	pc++;
	else pc=sTarget;
	
	strcpy(sTemp,pc);
	strcpy(sTarget,sTemp);
}
int Precompiler(char sCommand[])
{
	if(strstr(Basename(sCommand),"proc")!=NULL||
		strstr(Basename(sCommand),"cpre")!=NULL) return 1;
	return 0;
}
const char *Basename(const char *path)
{
	const char *cp;
	cp = strrchr(path,'/');
	if (cp == NULL)
		return (path);
	return (cp+1);
}

const char *Extension(const char *path)
{
	const char *cp = path;

	cp=strrchr(path, '.');
	if (cp == NULL)	return ("");
	return (cp);
}	/* Extension */

void DumpFormattedOutput(char sCommand[],int iDispCol,
	char *pHead,int iExitCode)
{
	int curcol,i;
	char *cp,*saved,spaces[8 + 1] = "        ";

	curcol = 0;
	saved = NULL;
	
	if(Precompiler(sCommand)&&iExitCode==0){free(pHead); return;}
	
	for(cp=pHead;;cp++) {
		if(*cp=='\0') {
			if(saved==NULL) break;
			cp= saved;
			saved=NULL;
		}
		if (*cp == '\r')continue;
		
		if (*cp=='\t') {
			saved = cp+1;
			cp=spaces+8-(8-((curcol-INDENT-1)%8));
		}
		if(curcol==0){
			for(i=INDENT;--i>=0;)
				putchar(' ');
			curcol=INDENT;
		}
		putchar(*cp);
		if (++curcol==(iDispCol-1)) {
			putchar('\n');
			curcol=0;
		}
		else if(*cp=='\n')curcol=0;
	}
	free(pHead);
}

int Wait(int pid)
{
	int pid1,i;

	do{
		i=0;
		pid1 =(int)waitpid(pid,&i,0);
		/*子进程没有推出或者中断则继续等子进程*/
	}while(((pid1>=0)&&(!WIFEXITED(i)))||((pid1<0)&&(errno==EINTR)));
	
	if (WIFEXITED(i))
		return WEXITSTATUS(i);
	return -1;
}
void SubTimeVal(struct timeval *t1, struct timeval *t0,struct timeval *tdiff)
{
	tdiff->tv_sec=	t1->tv_sec-t0->tv_sec;
	tdiff->tv_usec= t1->tv_usec-t0->tv_usec;

	if (tdiff->tv_usec < 0) {
		tdiff->tv_sec--;
		tdiff->tv_usec += 1000000;
	}
}
char trailcp()
{
	static int i=0;
	static char *trail= "/-\\|";

	if(trail[i]=='\0')i=0;

	return trail[i++];
}

int ProcTty(int fd,char sAction[],char sTarget[],char sArgStr[],
	int pid,char **ppHead)
{
	int iExitCode,iRet;
	char *pHead=NULL;
	int iBufByte,iLen,iPos=0,iBufLen=0;

	char sTemp[71];
	fd_set fdset1,fdset0;
	struct timeval now, tnext, tleft;

	*ppHead=NULL;
	
	/*打印运行命令提示*/
	sprintf(sTemp,"%s%s%s... ", sAction,sTarget[0]? " " : "",sTarget);
	printf("\r%-70s%-9s", sTemp, "");
	fflush(stdout);

	/*初始化定时器及定时间隔*/
	gettimeofday(&now,NULL);
	tnext = now;
	tnext.tv_sec++;
	tleft.tv_sec = 1;
	tleft.tv_usec = 0;
	
	/*设置描述符集*/
	FD_ZERO(&fdset0);
	FD_SET(fd,&fdset0);

	while(1){
		/*如果是第一次或者缓冲区满则扩展已分配的内存*/
		if(iBufLen==0||iPos==(iBufLen-1)) {
			if ((pHead=realloc(pHead,iBufLen+8192))==NULL){
				perror("ccdv: realloc");
				return -1;
			}
			iBufLen+=8192;
		}
		while(1){
			fdset1=fdset0;
			iRet=select(fd+1,&fdset1,NULL,NULL,&tleft);
			if(iRet<0){/*如果没有SELECT到数据且不是中断则退出*/
				if(errno!=EINTR){
					perror("ccdv: select");
					return -1;
				}
				continue;
			}
			/*有1个文件描述符被SELECT到则读数据去*/
			if (iRet==1)break;

			/*如果时间片用完则打印进度*/
			gettimeofday(&now,NULL);
			if ((now.tv_sec>tnext.tv_sec)|| 
				(now.tv_sec==tnext.tv_sec&& 
				 now.tv_usec>=tnext.tv_usec)){

				tnext=now;tnext.tv_sec++;
				tleft.tv_sec=1;tleft.tv_usec=0;
				
				printf("\r%-71s%c%-7s",sTemp,trailcp(),"");
				fflush(stdout);
			}
			else/*时间片没有用完则将定时器时间扣除*/
				SubTimeVal(&tnext,&now,&tleft);
		}
		iBufByte=iBufLen-iPos-1;
		iLen=read(fd,pHead+iPos,iBufByte);
	
		if(iLen<0) {
			/*如果是系统中断返回则继续读*/
			if(errno==EINTR)continue;

			perror("ccdv: read");
			return -1;
		}
		if(iLen==0) break;
		
		iPos+=iLen;pHead[iPos]=0;
	}
	sprintf(sTemp,"%s%s%s: ",sAction,sTarget[0]?" ":"",sTarget);
	if((iExitCode=Wait(pid))==0){
		printf("\r%-70s",sTemp);

		printf("[%s%s%s]",iPos<4?
		    SETCOLOR_SUCCESS:SETCOLOR_WARNING,"OK",SETCOLOR_NORMAL);
		printf("%-5s\n", " ");
	}
	else{
		printf("\r%-70s",sTemp);
		printf("[%s%s%s]",SETCOLOR_FAILURE,"ERROR",SETCOLOR_NORMAL);
		printf("%-2s\n", " ");
	}

	fflush(stdout);

	*ppHead=pHead;
	
	if(iExitCode!=0) return 1;
	return 0;
}

int ProcAll(int fd,char sAction[],char sTarget[],char sArgStr[],
	int pid,char **ppHead)
{
	int iExitCode;
	char *pHead=NULL;
	size_t iBufByte,iLen,iPos=0,iBufLen=0;

	*ppHead=NULL;
	/*打印基本处理信息*/
	printf("%s%s%s.\n",sAction,sTarget[0]?" ":"",sTarget);
	fflush(stdout);

	/*循环将文件描述符中数据统统地读到pHead内存结构中*/
	while(1){
		/*如果是第一次或者缓冲区满则扩展已分配的内存*/
		if(iBufLen==0||iPos==(iBufLen-1)) {
			if ((pHead=realloc(pHead,iBufLen+8192))==NULL){
				perror("ccdv: realloc");
				return -1;
			}
			iBufLen+=8192;
		}
		iBufByte=iBufLen-iPos-1;
		iLen=read(fd,pHead+iPos,iBufByte);
	
		if(iLen<0) {
			/*如果是系统中断返回则继续读*/
			if(errno==EINTR)continue;

			perror("ccdv: read");
			return -1;
		}
		if(iLen==0) break;
		
		iPos+=iLen;pHead[iPos]=0;
	}
	
	*ppHead=pHead;
	
	iExitCode=Wait(pid);
	
	if(iExitCode!=0) return 1;
	return 0;
}


void Usage(void)
{
	fprintf(stderr, "Usage: ccdv compiler FLAGS...\n\n");
	fprintf(stderr, "I wrote this to reduce the deluge Make \
output to make finding actual problems\n");
	fprintf(stderr, "easier.  It is intended to be invoked from \
Makefiles, like this.  Instead of:\n\n");
	fprintf(stderr, "\t.c.o:\n");
	fprintf(stderr, "\t\t$(CC) $(CFLAGS) $(DEFS) $(CPPFLAGS) $< -c\n");
	fprintf(stderr, "\nRewrite your rule so it looks like:\n\n");
	fprintf(stderr, "\t.c.o:\n");
	fprintf(stderr, "\t\t@ccdv $(CC) $(CFLAGS) $(DEFS) $(CPPFLAGS) $< -c\n\n");
	fprintf(stderr, "ccdv 1.0.0 is Free under the GNU Public License!\n");
	exit(1);
}	/* Usage */
void CloseStdin()
{
	int fd;

	close(0);
	fd=open("/dev/null",O_RDWR,00666);
	if(fd!=0){dup2(fd,0);close(fd);}
}
int GetDispCol()
{
	return 	(getenv("COLUMNS") != NULL)?atoi(getenv("COLUMNS")):80;
}
int main(int argc, char **argv)
{
	int aiPipe[2],fd,i,iLen,l,iDispCol,childpid=0,iExitCode;
	char *pHead=NULL;
	char sAction[8192],sTarget[8192],sTemp[8192];
	char sCommand[8192],sQuote[2],sArgStr[8192];

	if (argc < 2)	Usage();

	ASNIESC=(getenv("TERM")!=NULL)&&(strstr(TERMS,getenv("TERM"))!=NULL);
	iDispCol=GetDispCol();

	/*根据参数初始化,action,target,command,argstr变量*/
	strcpy(sCommand,argv[1]);
	sprintf(sAction,"Running %s",Basename(argv[1]));
	for (l=0,i=1;i<argc;i++) {
		
		strcpy(sQuote,(strchr(argv[i],' ')!=NULL)?"\"":"");
		l+=sprintf(sArgStr+l,"%s%s%s%s%s",(i==1)?"":" ",
			sQuote,argv[i],sQuote,(i==(argc-1))?"\n":"");

		if((strcmp(argv[i],"-o")==0)&&((i+1)<argc)) {
			if (strcasecmp(Extension(argv[i+1]),".o") != 0){
				strcpy(sAction, "Linking");
				strcpy(sTarget,Basename(argv[i+1]));
			}
			continue;
		} 
		if(strchr("-+/",(int)argv[i][0])!=NULL) continue;
		
		if(strncasecmp(Extension(argv[i]),".c",2)==0||
			strncasecmp(Extension(argv[i]),".pc",3)==0||
			strncasecmp(Extension(argv[i]),".cp",3)==0){

			strcpy(sTarget,Basename(argv[i]));
			if(Precompiler(sCommand)){
				strcpy(sAction, "Precompiling");
				TransTarget(sTarget);
			}
			else
				strcpy(sAction, "Compiling");

		}
		else if((i==1)&&(strcmp(Basename(argv[i]),"ar")==0))
			strcpy(sAction, "Creating library");		
		else if(strcasecmp(Extension(argv[i]), ".a")==0&&
			strcmp(Basename(argv[1]),"ar")==0)
			strcpy(sTarget,Basename(argv[i]));
	}

	/*创建管道*/
	if (pipe(aiPipe) < 0) {
		perror("ccdv:pipe");
		exit(1);
	}
	/*关闭标准输入*/
	CloseStdin();

	/*建立子进程，失败则退出*/
	if((childpid=(int)fork())<0){
		close(aiPipe[0]);
		close(aiPipe[1]);
		perror("ccdv: fork");
		exit(1);
	}
	
	if(childpid==0){
		/* 进入子进程 */
		close(aiPipe[0]);	/*关闭子进程的管道输出端*/
		if (aiPipe[1]!=1) {	/*将标准输出定位到管道的输入*/
			dup2(aiPipe[1],1);
			close(aiPipe[1]);
		}
		dup2(1,2);		/*将标准错误输出定位到管道的输入*/
		/*运行这个命令*/
		execvp(argv[1],argv+1);
		perror(argv[1]);
		exit(0);
	}

	/* 这里是父进程 */
	close(aiPipe[1]);	/* 关闭管道的输入端口*/
	fd = aiPipe[0];		/* 将管道的输出端指到文件中 */

	if(isatty(1)) 
		iExitCode=ProcTty(fd,sAction,sTarget,sArgStr,childpid,&pHead);
	else 
		iExitCode=ProcAll(fd,sAction,sTarget,sArgStr,childpid,&pHead);
	if(iExitCode<0) goto panic;
	DumpFormattedOutput(sCommand,iDispCol,pHead,iExitCode);
	close(fd);
	exit(0);
panic:
	DumpFormattedOutput(sCommand,iDispCol,pHead,iExitCode);
	while ((iLen=read(fd,sTemp,(size_t)sizeof(sTemp)))>0)
		(void)write(2,sTemp,(size_t)iLen);
	close(fd);
	exit(Wait(childpid));
}
EOF
	$COMPILER $CFLAGS -o "ccdv" "ccdv.c" >/dev/null 2>&1
	rm -f ccdv.c ccdv.o ccdv.c.gz.uu ccdv.c.gz
}
linkfile()
{
	sourcepath=$1
	targetpath=`pwd`/$2
	targetfile=$3
	if [ -L $targetpath/$targetfile ]; then
		rm -f $targetpath/$targetfile;
	fi
	if [ -f $sourcepath/$targetfile ]; then
		ln -s $sourcepath/$targetfile $targetpath/$targetfile
	fi
}
unlinkfile()
{
	targetpath=`pwd`/$1
	targetfile=$2
	if [ -L $targetpath/$targetfile ]; then
		rm -f $targetpath/$targetfile;
	fi
}
linkdb()
{
	case $dbopt in
	sybase)
		sourcepath=`pwd`/db/sybase
		;;
	*)
		sourcepath=`pwd`/db/oracle
		;;
	esac
	linkfile $sourcepath makebss Make.defines
	linkfile $sourcepath makebss sybopts.sh
	linkfile $sourcepath include exutils.h
	linkfile $sourcepath common exutils.c
	linkfile $sourcepath include wwdb.h
	linkfile $sourcepath common wwdb.pc
	linkfile $sourcepath common dbsupp.pc
	linkfile $sourcepath public gen_supp.pc
	linkfile $sourcepath db highcharge.pc  
	linkfile $sourcepath db tollcomm.pc
	linkfile $sourcepath db stt_ticket.pc
	linkfile $sourcepath db sett_item.pc 
}
unlinkdb()
{
	unlinkfile makebss Make.defines
	unlinkfile makebss sybopts.sh
	unlinkfile include exutils.h
	unlinkfile common exutils.c
	unlinkfile include wwdb.h
	unlinkfile common wwdb.pc
	unlinkfile common dbsupp.pc
	unlinkfile public gen_supp.pc
	unlinkfile db highcharge.pc  
	unlinkfile db tollcomm.pc
	unlinkfile db stt_ticket.pc
	unlinkfile db sett_item.pc 
}
	
makedir()
{
	dir=$1
	case $dbopt in
	sybase*) 
		if [ $dir = "arch" -o $dir = "cmdserv" ]; then return; fi
		if [ $dir = "dup" ]; then return; fi
	;;
	*)
	;;
	esac
	case $makeflag in 
	clean*)
		cd $dir
		make clean;
		cd ..
		;;
	*)
		cd $dir
		make clean;
		make -e all;
		cd ..
		;;
	esac
}
installdir()
{
	dir=$1
	
	case $makeflag in 
	install*)
		prj=`echo $makeflag | sed s/install//`
		echo "install $dir ..."
		sleep 1
		case $dir in
		bin)
			[ -d ../bin ] || mkdir ../bin
			cp -r bin/* ../bin
			;;
		shell)
			[ -d ../shell ] || mkdir ../shell
			cp -r shell/* ../shell
			[ -d local/$prj ] && cp local/$prj/*.sh ../shell
			;;
		expr)
			[ -d ../expr ] || mkdir ../expr
			cp -r expr/* ../expr
			[ -d local/$prj ] && cp local/$prj/*.expr ../expr
			;;
		local)
			[ -d ../shell ] || mkdir ../shell
			[ -d local/$prj ] && cp local/$prj/*.lst ../shell
			[ -d local/$prj ] && cp local/$prj/*.ini ../shell
			;;
		*)
			;;
		esac
		echo "install $dir ended ..."
		;;
	*)
		;;
	esac
}
main()
{
	ccdvproc
	case $makeflag in 
	install*)
		installdir bin
		installdir shell
		installdir expr
		installdir local
		[ -d ../ctl ] || mkdir ../ctl
		[ -d ../work ] || mkdir ../work
		[ -d ../log ] || mkdir ../log
		;;
	*)
		makedir common
		makedir public
		makedir arch 
		makedir db
		makedir	prep
		makedir billing
		makedir tool
		makedir	case
		makedir	cmd
		makedir chk
		makedir monitor
		makedir test
		makedir tiny
		makedir cmdserv
		makedir shed
		makedir	kpi
		makedir	stat
		makedir	intf
		[ "X$makeflag" = "Xcleanall" ] && rm -f ccdv;
		;;
	esac
}
main
exit 0
