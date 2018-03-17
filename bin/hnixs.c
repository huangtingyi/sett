#include "hnixs.h"
#include "wwfile.h"

struct ResourceStruct	AppRes;

/*内存、文件、申明、时间、异常、调试的函数封装；*/

void *hmalloc(size_t size)
{
	void *ptr;

	if((ptr=malloc(size))!=NULL){
		AppRes.m_iMemBytes+=size;
		return ptr;
	}
	return NULL;

}
/*内存、文件、申明、时间、异常、调试的函数封装；*/

void *nmalloc(size_t size)
{
	void *ptr;

	if((ptr=malloc(size))==NULL){

		/*增加异常处理这里，程序退出*/
		printf("程序已经占用内存%dM,再分配%d字节的内存时失败.",
			(int)AppRes.m_iMemBytes/1024,(int)size);
		exit(1);
	}

	AppRes.m_iMemBytes+=size;
	return ptr;

}

int4b hfree(void *ptr,size_t size)
{
	if(ptr!=NULL){
		free(ptr);
		AppRes.m_iMemBytes-=size;
		return (int4b)size;
	}
	/*调试时候，异常释放内存*/
	return 0;
}

FILE *hfopen (const char *path, const char *mode)
{
	FILE *fp;

	if((fp=fopen( path, mode ))==NULL) return NULL;
	
	AppRes.m_iOpenFiles++;

	return fp;
}
int hfclose( FILE *stream)
{
	if(fclose(stream)==0){
		AppRes.m_iOpenFiles--;
		return 0;
	}
	return -1;
}

char *hfgets(char *s, int size, FILE *stream)
{
	return fgets(s,size,stream);
}
int hfputs(const char *s, FILE *stream)
{
	return fputs(s,stream);
}

size_t  hfread(  void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	return fread(ptr,size,nmemb,stream);
}
size_t hfwrite( const void *ptr, size_t size, size_t nmemb,FILE *stream)
{
	return fwrite(ptr,size,nmemb,stream);
}

int hfseek( FILE *stream, long offset, int whence)
{
	return fseek(stream,offset,whence);
}
static time_t tGetTime(char sAnswerTime[15])
{
	char sTempYear[5],sTempMon[3],sTempMDay[3],sTempHour[3],
	     sTempMin[3],sTempSec[3];
	struct tm s;
	time_t t_ret;

	bzero(&s,sizeof(struct tm));

	strncpy(sTempYear,sAnswerTime,4);sTempYear[4]=0;
	sTempMon[0]=sAnswerTime[4];
	sTempMon[1]=sAnswerTime[5]; sTempMon[2]=0;

	sTempMDay[0]=sAnswerTime[6];
	sTempMDay[1]=sAnswerTime[7]; sTempMDay[2]=0;

	sTempHour[0]=sAnswerTime[8];
	sTempHour[1]=sAnswerTime[9]; sTempHour[2]=0;

	sTempMin[0]=sAnswerTime[10];
	sTempMin[1]=sAnswerTime[11]; sTempMin[2]=0;

	sTempSec[0]=sAnswerTime[12];
	sTempSec[1]=sAnswerTime[13]; sTempSec[2]=0;

	s.tm_year=atoi(sTempYear)-1900;
	if(s.tm_year<=0)	return -1;

	s.tm_mon=atoi(sTempMon)-1;
	if(s.tm_mon<0||s.tm_mon>11) return -1;

	s.tm_mday=atoi(sTempMDay);
	if(s.tm_mday<1||s.tm_mday>31) return -1;

	s.tm_hour=atoi(sTempHour);
	if(s.tm_hour<0||s.tm_hour>23) return -1;

	s.tm_min=atoi(sTempMin);
	if(s.tm_min<0||s.tm_min>59) return -1;

	s.tm_sec=atoi(sTempSec);
	if(s.tm_sec<0||s.tm_sec>59) return -1;

	s.tm_isdst=0;

	t_ret=mktime(&s);

	if(t_ret==-1) return -1;

	return t_ret;
}
int InitAppRes(char sAppName[])
{
	char *env,sBaseName[128];
	
	strcpy(AppRes.sSysName,"bill");
	GetBaseName(sAppName,sBaseName);
	strcpy(AppRes.sAppName,sBaseName);

	strcpy(AppRes.sHostTime,"");
        if((env=getenv("BILLTIME"))!=NULL){
        	if(tGetTime(env)!=-1)
        		strcpy(AppRes.sHostTime,env);
        }
/**如果不是恢复历史状态，则直接设为空
        if(strlen(AppRes.sHostTime)==0)
        	GetHostTime(AppRes.sHostTime);
**/     
	if((env=getenv("TICKETROOT"))!=NULL){
		int l;
		strcpy(AppRes.sTicketRoot,env);
		l=strlen(env);
		if(AppRes.sTicketRoot[l-1]!='\\'){
			AppRes.sTicketRoot[l-1]='\\';
			AppRes.sTicketRoot[l]=0;
		}
	}
	else
		strcpy(AppRes.sTicketRoot,"/ticket/");
	
	return 0;
}
