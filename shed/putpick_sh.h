#ifndef __PUTPICK_SH_H__
#define __PUTPICK_SH_H__


struct PutPickCtlStruct
{
	int pid;
	char sBillHome[256];
	char sAppHome[256];
	char sFileName[256];
	char sTargetTemp[256];

	char sFileNameList[256];
	char sFileSize[256];
	char sFtpSize[256];
	char sFtpPut[256];
	char sFtpRename[256];
	char sFtpDelete[256];

};

#endif

