#include "hnixs.h"
#include "wwfile.h"
#include "wwtiny.h"
#include "wwdir.h"
#include "list.h"
#include "wwcoding.h"
#include "wwlog.h"

static struct ErrStackStruct ErrStack;
int iQuitFlag=false;

void hosttime2asc(char sTime[])
{
	time_t	tTime;
        struct tm *tm1;

	time(&tTime);
        tm1= localtime(&tTime);

        sprintf(sTime,"%04d%02d%02d %02d:%02d:%02d",
		tm1->tm_year+1900,tm1->tm_mon+1,
		tm1->tm_mday,tm1->tm_hour,tm1->tm_min,tm1->tm_sec);
}
void GetBillHome(char sPath[])
{
	char *env;

	if((env=getenv("BILLHOME"))==NULL)
		strcpy(sPath,"/home/bill/");
	else
		strcpy(sPath,env);
	RegularDir(sPath);
}
void GetAppHome(char sPath[])
{
	char *env;

	if((env=getenv("APPHOME"))==NULL)
		strcpy(sPath,"/home/bill/");
	else
		strcpy(sPath,env);
	RegularDir(sPath);
}
void InitLogPath(char sPath[])
{
	GetAppHome(sPath);
	strcat(sPath,"log/");
}
void GetIniName(char sPath[])
{
	GetAppHome(sPath);
	strcat(sPath,"shell/bill.ini");
}
void WriteAlertMsg(char *fmt,...)
{
	va_list	argptr;
	int iErrCode;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];

	/*保留错误现场*/
	iErrCode=errno;
	/* 2002/05/31 清除上次的错误代码 */
	errno=0;

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	sprintf(sFileName,"%salert_%s.log",sPath,AppRes.sSysName);
	if(AppRes.sSysName[0]==0)
		sprintf(sFileName,"%salert_bill.log",sPath);

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	if(PrintLog(sFileName,"%s-[%s]-[%d]->%s\n",
		sHostTime,AppRes.sAppName,getpid(),sMessage)<0)
		WriteProcMsg("错误记录告警文件%s",sFileName);		

	WriteProcMsg(sMessage);
}
void WriteAlertPrint(char *fmt,...)
{
	va_list	argptr;
	int iErrCode;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];

	/*保留错误现场*/
	iErrCode=errno;
	/* 2002/05/31 清除上次的错误代码 */
	errno=0;

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	sprintf(sFileName,"%salert_%s.log",sPath,AppRes.sSysName);
	if(AppRes.sSysName[0]==0)
		sprintf(sFileName,"%salert_bill.log",sPath);

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	printf("%s\n",sMessage);

	if(PrintLog(sFileName,"%s-[%s]-[%d]->%s\n",
		sHostTime,AppRes.sAppName,getpid(),sMessage)<0)
		WriteProcMsg("错误记录告警文件%s",sFileName);

	WriteProcMsg(sMessage);
}

void WriteProcMsg(char *fmt,...)
{
	va_list	argptr;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];


	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	if(RLike(AppRes.sAppName,".sh")==true)
		sprintf(sFileName,"%s%s.log",sPath,AppRes.sAppName);
	else if(AppRes.sAppName[0]!=0)
		sprintf(sFileName,"%s%s.trc",sPath,AppRes.sAppName);
	else	sprintf(sFileName,"%sother.trc",sPath);


	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	PrintLog(sFileName,"%s-[%d]-[%d]->%s\n",
		sHostTime,AppRes.iSID,getpid(),sMessage);
}
void WriteProcPrint(char *fmt,...)
{
	va_list	argptr;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];


	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	if(RLike(AppRes.sAppName,".sh")==true)
		sprintf(sFileName,"%s%s.log",sPath,AppRes.sAppName);
	else if(AppRes.sAppName[0]!=0)
		sprintf(sFileName,"%s%s.trc",sPath,AppRes.sAppName);
	else	sprintf(sFileName,"%sother.trc",sPath);

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	printf("%s\n",sMessage);

	PrintLog(sFileName,"%s-[%d]-[%d]->%s\n",
		sHostTime,AppRes.iSID,getpid(),sMessage);
}

void pprintf(int iErrCode,int iAlarmFlag,char *fmt,...)
{
	va_list	argptr;
	char sHostTime[100],sMessage[8192];
	static int iFirstFlag=TRUE;
	static char sPath[256],sFileName[256];


	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		InitLogPath(sPath);
	}

	sprintf(sFileName,"%s%s_%d_%d.trc",
		sPath,AppRes.sAppName,AppRes.iSID,getpid());

	hosttime2asc(sHostTime);

	va_start(argptr, fmt);
	vsprintf(sMessage,fmt, argptr);
	va_end(argptr);

	PrintLog(sFileName,"%s-->代码%d,告警%d,%s\n",
		sHostTime,iErrCode,iAlarmFlag,sMessage);
}
void fs_printf(FILE *fp,char *fmt,...)
{
	va_list argptr;
	char sTemp[4096];

	va_start(argptr, fmt);
	vsprintf(sTemp,fmt,argptr);
	va_end(argptr);

	fprintf(fp,"%s",sTemp);

	printf("%s",sTemp);
}
void __PrintErr(char sFileName[],int iLine,char sMessage[])
{
	WriteAlertMsg("文件%s,行数%d,消息%s",
			sFileName,iLine,sMessage);
}
void __PrintNormal(char sFileName[],int iLine,char sMessage[])
{
	WriteProcMsg("文件%s,行数%d,消息%s",
			sFileName,iLine,sMessage);
}
void CleanErrStack()
{
	memset((void*)&ErrStack,0,sizeof(struct ErrStackStruct));
}
void ResetErrStack()
{
	ErrStack.iPos=0;
}
void __PushErrStack(char sFileName[],int iLine,char sMessage[])
{
	int i;

	if(ErrStack.iPos>=ERRSTACKLEN){
		WriteAlertMsg("错误栈溢出");
		WriteErrStackAlert();
		exit(1);
	}
	i=ErrStack.iPos;
	sprintf(ErrStack.sMessage[i++],"文件%s,行数%d,消息%s",
		sFileName,iLine,sMessage);
	ErrStack.iPos=i;

	WriteAlertMsg("文件%s,行数%d,消息%s",
		sFileName,iLine,sMessage);
	ErrStack.iPos=0;
}

void WriteErrStackAlert()
{
	int i,l=0;
	char sTemp[8192];

	if(ErrStack.iPos==0) return;

	strcpy(sTemp,"");
	for(i=0;i<ErrStack.iPos;i++){
		l+=sprintf(sTemp+l,"\n%d,%s",i,ErrStack.sMessage[i]);
		if(l>8192-1024){
			sprintf(sTemp+l,"\n......");
			break;
		}
	}
	WriteAlertMsg(sTemp);
}
void WriteErrStackNormal()
{
	int i,l=0;
	char sTemp[8192];

	if(ErrStack.iPos==0) return;

	strcpy(sTemp,"");
	for(i=0;i<ErrStack.iPos;i++){
		l+=sprintf(sTemp+l,"\n%d,%s",i,ErrStack.sMessage[i]);
		if(l>8192-1024){
			sprintf(sTemp+l,"\n......");
			break;
		}
	}
	WriteProcMsg(sTemp);
}

void NotifyQuit(int signo)
{
	iQuitFlag=true;
}
int WantQuit()
{
	return iQuitFlag;
}
