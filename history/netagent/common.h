#ifndef __COMMON_H__
#define __COMMON_H__

#ifndef TRUE
#define TRUE		1
#endif

#ifndef FALSE
#define FALSE		0
#endif

typedef struct __List__
{
	struct __List__ *pNext;
} LIST;

struct FileControlStruct
{
	struct FileControlStruct *pNext;
	int	iLen;
	void	*pData;
};

void GetDataTime(char sFormat[],char sTime[]);
void hosttime2asc(char sTime[]);
void DoLog(char *fmt,...);
int IsFile(char sName[]);
void AllTrim(char *s);
void InsertList(LIST **pptHead,LIST *p);
int item2list(struct FileControlStruct **ppHead,void *pData,int iLen);
int listfree(struct FileControlStruct **pptHead);
void ReverseList(LIST **pptHead);
int file2list(char sFileName[],int iHeadLen,int iRecLen,
	int iTailLen,struct FileControlStruct **pptHead);

#endif
