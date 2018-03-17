#ifndef __WWFILE_H__
#define __WWFILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <datatype.h>
#include <list.h>
#include <wwcoding.h>

FILE *OpenFileRead(char sFileName[]);
FILE *OpenFileWrite(char sFileName[]);
FILE *OpenFileAppend(char sFileName[]);
void CloseFile(FILE *fp);
int SeekFile(FILE *fp,int4b iPos);
void SetBufferFile(FILE *fp,int4b iSize,char sBuffer[]);
int ReadFile(FILE*fp,void *Buf, int iSize);
int WriteFile(FILE *fp,void *Buf, int iSize);
int4b FileSize(char sFileName[]);
int4b FileLine(char sFileName[]);
time_t FileModifyTime(char sFileName[]);
int IsFile(char sName[]);
int Rename(char sTempName[],char sTargetName[]);
int Remove(char sFileName[]);

int AddFileExtName(char sFileName[],char sExt[]);

int PrintLog(char sFileName[],char *fmt, ...);

struct FileControlStruct
{
	struct FileControlStruct *pNext;
	int	iLen;
	void	*pData;
};
#define RETURN_INTERNAL	0
#define	RETURN_UNIX	1
#define RETURN_DOS	2

int list2fpcomm(struct FileControlStruct **pptHead,FILE *fp,int type);

int list2filecomm(struct FileControlStruct **pptHead,char sFileName[],int type);
int list2file(struct FileControlStruct **pptHead,char sFileName[]);
int list2fileln(struct FileControlStruct **pptHead,char sFileName[]);
int list2filelrn(struct FileControlStruct **pptHead,char sFileName[]);

int list2fdcomm(struct FileControlStruct **pptHead,int iFd,int type);
int list2fd(struct FileControlStruct **pptHead,int iFd);
int list2fdlrn(struct FileControlStruct **pptHead,int iFd);
int list2fdln(struct FileControlStruct **pptHead,int iFd);

int item2errorlist(struct FileControlStruct **ppHead,char sCode[5],
	void *pData,int iLen);
int item2list(struct FileControlStruct **ppHead,void *pData,int iLen);
int item2listtail(struct FileControlStruct **ppHead,void *pData,int iLen);
int listfree(struct FileControlStruct **pptHead);
int file2list(char sFileName[],int iHeadLen,int iRecLen,
	int iTailLen,struct FileControlStruct **pptHead);

int item2List(LIST **ppHead,LIST *pData,int l);
int item2ListTail(LIST **ppHead,LIST *pData,int l);

struct FileSwitchStruct
{
	struct FileSwitchStruct *pNext;
	long	iPos;		/*文件位置指针,POS==-1表示待CNT*/
	long	iLastPos;
	int	iHandleCnt;	/*前次文件位置*/
	int	iLastHandleCnt;	/*最后一个文件处理前记录数*/
	int	iCurCnt;
	int	iSourceID;
	char	sCurFileName[31];
	char	sStep[2];
	char	sHostDate[15];
	struct FileSwitchStruct *pLoadNext;
};
void InsertFileSwitch(struct FileSwitchStruct *ptCur);
/*跳过文件的前几条记录体,忽略头记录*/
long SwitchFilePos(char sFileName[],int iCnt);
long WriteListFilePos(char sFileName[],struct FileControlStruct *p,long iPos);

void GetBaseName(char sFileName[],char sBaseName[]);
void GetBaseNameX(char sFileName[],char sBaseName[]);
void GetExtName(char sFileName[],char sExtName[]);
void GetPathName(char sFileName[],char sPathName[]);
int ReadString(char *sFilename,char *sBlock,char *sSection,char *sItem,char *sResult);

int GetTtyName(char sName[]);
FILE *RedirectFp(FILE *fp,char sName[]);

int fdgetc(int fd);
int wwfdgets(char sRecord[],int iBufLen,int fd);
int GetSockBufLen(int iSockFd);

int exec2str(char sCommand[256],char sReturn[1024]);
int exec2list(char sCommand[256],struct FileControlStruct **pptHead);

int FileLines(char sFileName[]);
int execcmd(char *fmt,...);
int PrintTiny(char sFileName[],char *fmt, ...);
int PatternMatch(char sFileName[],char sFilter[]);
int ReadFileToBuf(char sFileName[],int iMaxLen,char sInput[],char sMessage[]);
int PingIpOk(char sIp[]);

int DynBlockToList(struct FileControlStruct *pTemp,
	struct BlkFmtStruct *pFormat,struct FileControlStruct **pptHead);
int DynFileToBlockHead(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead);

int TxtFileToList(char sFileName[],struct FileControlStruct **pptHead);
int TxtFileToListX(char sFileName[],int iHead,int iTail,
	struct FileControlStruct **pptHead);
int TxtttFileToList(char sFileName[],struct FileControlStruct **pptHead);
int BinFixFileToList(char sFileName[],int iHeadLen,int iRecLen,int iTailLen,
	struct FileControlStruct **pptHead);
int BlkFixFileToList(char sFileName[],int iHeadLen,int iRecLen,int iTailLen,
	struct FileControlStruct **pptHead);
int AsnFileToList(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead);
int AsnHwFileToList(char sFileName[],struct FileControlStruct **pptHead);

int NortelFileToList(char sFileName[],struct FileControlStruct **pptHead);

int DynBlkToList(struct FileControlStruct *pTemp,
	struct FileFormatStruct *pFormat,struct FileControlStruct **pptHead);
int BinDynFileToList(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead);
int BlkDynFileToList(char sFileName[],struct FileFormatStruct *pFormat,
	struct FileControlStruct **pptHead);
struct nvlist{

	struct nvlist *pNext;
	
	char *sName;
	char *sValue;
};

void InitParamFileName(char sName[]);
char *getParam(const char sName[]);
char *getValue(struct nvlist *ptHead,const char sName[]);
int InitParam2NvList(char sFileName[],struct nvlist **pptHead);

#define PARAM(a)  getParam(a)
#define PARAMI(a) atoi(getParam(a))

#ifndef PATH_MAX
#define PATH_MAX 255
#endif

void GetBaseNameFromCtl(struct FileControlStruct *pTemp,char sBaseName[]);

/*将文件内容读到字符串中，将文件内容的全部读到字符串内，
并在最后添加\0作为结束，如果文件内容有\0则也会读入，在使用的时候
要结合FileSize函数来拿到文件内容的\0后的东西*/
int file2str(char sFileName[],char str[]);
/*将以\0为结束符的字符串的信息写到特定的文件中，将文件内容覆盖*/
int str2file(char str[],char sFileName[]);

#endif
