#ifndef __FILEOUT_H__
#define __FILEOUT_H__

#include <wwfile.h>
#include <ticket_field.h>

struct MyFileOutStruct
{
	struct MyFileOutStruct *pNext;
	char 	sSplitType[2];
	FILE *fp;
};

void GetOutFileName(char sTargetName[],char sSuffix[],char sFileName[]);
struct MyFileOutStruct *GetFileOut(struct FileControlStruct **pptHead,
	char sTargetName[],char sSplitType[]);
void CloseFileOut(struct FileControlStruct *ptHead);
void CloseFileOutAll(struct FileControlOutStruct *ptHead);

/*控制文件支持*/
int Item2FileOut(struct FileControlStruct **ppHead,void *pData,int iLen,
	char sTargetName[],char sSplitType[]);
int Item2FileSplitOut(struct FileControlOutStruct **pptHead,void *pData,int l,
	char sBaseName[],char sTargetName[],char sSplitType[],
	struct TinyRollLogStruct **ppSumLog,char sSplitNew[],char msg[]);

#endif
