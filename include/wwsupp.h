#ifndef __WWSUPP_H__
#define __WWSUPP_H__

#include <wwfile.h>

int FileModifyDiff(char sFileName[]);
int FileModifyDate(char sFileName[],char sModifyDate[]);
int FileBackupDate(char sFileName[],char sDateRule[],char sBackupDate[]);
int ParseTabArg(char sRecord[]);
int GetFtpDirSize(char sRecord[]);
void GetFtpFileName(char sRecord[],char sFilter[],char sFileName[]);

void GetFileSplit(char sSource[],char sRawName[],char sFileSplit[]);
struct TinySplitStruct
{
	struct TinySplitStruct *pNext;
	char sSplitType[2];
	char sKey[10];
	int  iCnt;
};
void mvitem_ctl2tinysplit(struct FileControlStruct *pi,
	struct TinySplitStruct *po);
int InitTinySplitList(char sSource[],char sBaseName[],
	struct TinySplitStruct **pptHead);
int SearchTinySplit(struct TinySplitStruct *ptHead,char cSplitType);
void RemoveFileSplit(char sSource[],char sBaseName[]);

struct TinyRollLogStruct
{
	struct TinyRollLogStruct *pNext;
	char	sOriFileName[41];
	char	sFileName[41];
	int	iCnt;
};
int SearchTinyRollLog(struct TinyRollLogStruct *ptHead,char sOriFileName[],
	char sFileName[], struct TinyRollLogStruct **pptCur);
int SumTinyRollLog(struct TinyRollLogStruct **pptHead,
	char sOriFileName[],char sFileName[],int iCnt);
void GetRollLogCtl(char sRawName[],char sRollLogCtl[]);
void RemoveRollLogCtl(char sBaseName[]);
int WriteRollLogCtl(struct TinyRollLogStruct *ptHead,char sFileName[]);
int InitRollLogCtl(char sBaseName[],struct TinyRollLogStruct **pptHead);

int WantCtl(char sAppName[]);

void GetLogLock(char sStep[],char sSourceID[],char sDate[],
	char sLockName[]);
int LockLog(char sLockName[],char msg[]);
void UnlockLog(char sLockName[]);

/*判断是否是内部文件名,文件名::$SOURCEYYYYMMDDNNNNN.开头*/
int IsInternalName(char sBaseName[]);

int IsDpAccNbr(char sHeadDp[],char sAccNbr[]);

#define IS_MOB_NBR(x) 		IsDpAccNbr("mobnbr",x)
#define IS_MOB_IMSI(x)  	IsDpAccNbr("mobimsi",x)

struct AppNextStruct
{
	struct AppNextStruct *pNext;
	char sPath[81];
	char sFilter[21];
	char sTaskName[32];
	char sAppCodeGrp[30];
	char sTask[256];
};

int SearchAppNext(struct AppNextStruct *ptHead,char sPath[],char sFilter[],
	char sTaskName[],char sAppCodeGrp[]);
void ReadTaskInfo(char sCtlName[],char sSourceID[],int *ppid,char sTaskTime[]);
/*2009.09.08写信息文件，对字段有数值的情况下覆盖*/
void WriteTaskInfo(char sCtlName[],char sSourceID[],char sTaskPid[],
	char sTaskTime[]);

void GetAppCode(char sTask[],char sAppCode[]);
int GetAppGrp(char sTask[]);
void GetAppNextFileName(char sTask[],char sFileName[]);
void GetAppCurFileName(char sTask[],char sFileName[]);

time_t GetStartupTimeInterval(int iCycle,int iOffset);

#endif
