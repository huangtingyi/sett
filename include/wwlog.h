#ifndef __WWLOG_H__
#define __WWLOG_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	ERRSTACKLEN	100
struct ErrStackStruct
{
	int	iPos;
	char	sMessage[ERRSTACKLEN][1024];
};
void hosttime2asc(char sTime[]);
void WriteAlertMsg(char *fmt,...);
void WriteProcMsg(char *fmt,...);
void WriteAlertPrint(char *fmt,...);
void WriteProcPrint(char *fmt,...);
void pprintf(int iErrCode,int iAlarmFlag,char *fmt,...);
void fs_printf(FILE *fp,char *fmt,...);
void __PrintErr(char sFileName[],int iLine,char sMessage[]);
void __PrintNormal(char sFileName[],int iLine,char sMessage[]);

void WriteErrStackAlert();
void WriteErrStackNormal();

void CleanErrStack();
void ResetErrStack();
void GetBillHome(char sPath[]);
void GetAppHome(char sPath[]);
void GetIniName(char sPath[]);

void __PushErrStack(char sFileName[],int iLine,char sMessage[]);


#define PrintErr(x)	__PrintErr(__FILE__,__LINE__,x)
#define PrintErrA(s,a)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a);\
			PrintErr(sTemp);\
	}
#define PrintErrB(s,a,b)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,d);\
			PrintErr(sTemp);\
	}
#define PrintErrC(s,a,b,c)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,b,c);\
			PrintErr(sTemp);\
	}
#define PrintErrD(s,a,b,c,d)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,b,c,d);\
			PrintErr(sTemp);\
	}
	
#define PrintNormal(x)  __PrintNormal(__FILE__,__LINE__,x)
#define PrintNormalA(s,a)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a);\
			PrintNormal(sTemp);\
	}
#define PrintNormalB(s,a,b)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,d);\
			PrintNormal(sTemp);\
	}
#define PrintNormalC(s,a,b,c)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,b,c);\
			PrintNormal(sTemp);\
	}
#define PrintNormalD(s,a,b,c,d)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,b,c,d);\
			PrintNormal(sTemp);\
	}
#define PushErrStack(x) __PushErrStack(__FILE__,__LINE__,x)
#define PushErrStackA(s,a)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a);\
			PushErrStack(sTemp);\
	}
#define PushErrStackB(s,a,b)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,b);\
			PushErrStack(sTemp);\
	}
#define PushErrStackC(s,a,b,c)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,b,c);\
			PushErrStack(sTemp);\
	}
#define PushErrStackD(s,a,b,c,d)	{\
			char sTemp[1024];\
			sprintf(sTemp,s,a,b,c,d);\
			PushErrStack(sTemp);\
	}
#define ERROR_RETURNZ(x,y)	{\
		if(x){\
			PushErrStack(y);\
			return -1;\
		}\
			}
#define ERROR_RETURNA(x,y,a)	{\
		if(x){\
			PushErrStackA(y,a);\
			return -1;\
		}\
			}
#define ERROR_RETURNB(x,y,a,b)	{\
		if(x){\
			PushErrStackB(y,a,b);\
			return -1;\
		}\
			}
#define ERROR_RETURNC(x,y,a,b,c) {\
		if(x){\
			PushErrStackC(y,a,b,c);\
			return -1;\
		}\
			}
#define ERROR_RETURND(x,y,a,b,c,d) {\
		if(x){\
			PushErrStackD(y,a,b,c,d);\
			return -1;\
		}\
			}
#define ERROR_EXIT(x,y)	{\
		if(x){\
			PushErrStack(y);\
			WriteErrStackAlert();\
			exit(1);\
		}\
			}
#define ERROR_EXITDB(x,y)	{\
		if(x){\
			PushErrStack(y);\
			WriteErrStackAlert();\
			DisconnectDatabase();\
			exit(1);\
		}\
			}

#define ERROR_RETURN(x)	{\
		if(x){\
			return -1;\
		}\
			}
#define NORMAL_RETURN(x)	{\
		if(x){\
			return 0;\
		}\
			}
#define EXCEPT_RETURN(x)	{\
		if(x){\
			return 1;\
		}\
			}			
void InitLogPath(char sPath[]);

void NotifyQuit(int signo);
int WantQuit();

#endif
