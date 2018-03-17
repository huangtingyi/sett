#ifndef __PICK_SH_H__
#define __PICK_SH_H__


struct PickCtlStruct
{
	int pid;
	int iFlag;/*false,²»Ð´pick.sh.XXXXXX.log,true,Ð´*/
	char sBillHome[256];
	char sAppHome[256];
	char sFileName[256];
	char sTargetTemp[256];

	char sFtpNList[256];
	char sFileNameList[256];
	char sFileSize[256];
	char sFtpSize[256];
	char sFtpGet[256];
	char sFtpRename[256];
	char sFtpDelete[256];
	char sPickDup[256];
	char sDirNameList[256];
	char sFtpDList[256];

};

#endif

