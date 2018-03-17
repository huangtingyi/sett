#ifndef __WWDIR_H__
#define __WWDIR_H__
#include <dirent.h>
#include <wwfile.h>
void RegularDir(char sPath[]);
int CheckDir(char sPath[]);
DIR *OpenDir(char sPath[]);
void CloseDir(DIR *dp);
int ReadDir(DIR *dp,char sName[]);
int IsDir(char sName[]);
int dir2list_o(char sSourcePath[],char sFilter[],
	struct FileControlStruct **pptHead);
struct MyFileNameStruct
{
	struct MyFileNameStruct *pNext;
	time_t	tModifyTime;
	char	sBaseName[128];
};
int dir2list(char sSourcePath[],char sFilter[],
	struct FileControlStruct **pptHead);

#endif
