#ifndef __HNIXS_H__
#define __HNIXS_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef OS_UNIX
#include <sys/errno.h>
#include <sys/stat.h>
#endif
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

#include "datatype.h"

struct ResourceStruct
{
	int8b m_iMemBytes;
	int4b m_iOpenFiles;
	char	sSysName[128];
	char	sAppName[128];
	int	iSID;
	char	sHostTime[15];
	char	sTicketRoot[64];
};



/*内存，建议只使用以下函数建立及释放动态内存*/
void *hmalloc(size_t size);
int4b hfree(void *ptr,size_t size);

/*文件，建议只使用以下函数操作文件*/
FILE *hfopen (const char *path, const char *mode);
int hfclose( FILE *stream);

char *hfgets(char *s, int size, FILE *stream);
int hfputs(const char *s, FILE *stream);

size_t  hfread(  void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t hfwrite( const void *ptr, size_t size, size_t nmemb,FILE *stream);

int hfseek( FILE *stream, long offset, int whence);

#define  hfprintf	fprintf
#define	 hfscanf	fscanf 


extern struct ResourceStruct   AppRes;

#define APPHOSTTIME AppRes.sHostTime

int InitAppRes(char sAppName[]);
int  daemon_start(int ignsigcld);

#define PROC_NORMAL_EXIT(x)		WIFEXITED(x)	/*进程是否推出*/
#define PROC_EXIT_CODE(x)		WEXITSTATUS(x)	/*进程返回值*/
#define PROC_SIGNAL_EXIT(x)		WIFSIGNALED(x)	/*子进程收到信号推出*/
#define PROC_EXIT_SIGNAL(x)		WTERMSIG(x)	/*进程被中止的信号代码*/
#define PROC_STOP(x)			WIFSTOPPED(x)	/*子进程状态*/
#define PROC_STOP_SIGNAL(x)		WSTOPSIG(x)	/*导致进程中止的信号*/
#define PROC_RUNNING(x)			WIFCONTINUED(x)	/*子进程活动状态*/
#define PROC_CORE(x)			WCOREDUMP(x)	/*进程是否CORE出了*/


#endif

