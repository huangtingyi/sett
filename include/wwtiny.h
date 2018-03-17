#ifndef __WWTINY_H__
#define __WWTINY_H__

#include <time.h>
#include "datatype.h"

time_t tGetTime(char sAnswerTime[15]);
int sFormatTime( time_t ttime,char sTime[15]);
int ArcTime(time_t t,char sTime[15]);
int ChkTime(char sAnswerTime[15]);
int ChkDate(char sDate[9]);
int GetHostTime(char sHostTime[15]);
time_t tGetHostTime();

int LeapYear(char sTempDate[15]);

/* ��YYYYMMDDHH24MISS��ʽ���ִ�����iSecs��(��ֵʱ����ʾ��) */
int AddTimes(char sTempDate[15], int iOffset);
int AddMinutes(char sTempDate[15], int iOffset);
int AddHours(char sTempDate[15], int iOffset);

int AddDates(char sTempDate[15], int iOffset);
int AddDays(char sTempDate[15], int iOffset);
int AddWeeks(char sTempDate[15], int iOffset);
int AddTen(char sTempDate[15]);

int AddMonths(char sTempDate[15], int iOffset);
int AddQuarters(char sTempDate[15], int iOffset);
int AddYears(char sTempDate[15], int iOffset);

/*yyyymmddhh24miss----------->yyyy/mm/dd hh24:mi:ss*/
/*ע�Ȿ�������Ӵ�������*/
int formatdatetime_simp_compl(char sAnswerTime[],char sOutput[]);
/*yyyy/mm/dd hh24:mi:ss------>yyyymmddhh24miss*/
/*ע�Ȿ�������Ӵ�������*/
int formatdatetime_compl_simp(char sAnswerTime[],char sOutput[]);
/*yyyy-mm-dd hh24:mi:ss------>yyyymmddhh24miss*/
/*ע�Ȿ�������Ӵ�������*/
int formatdatetime_long_simp(char sAnswerTime[],char sOutput[]);
/*yyyy-mm-dd------>yyyymmdd*/
int formatdate_long_simp(char sAnswerTime[],char sOutput[]);
/*hh24:mi:ss------>hh24miss*/
int formattime_long_simp(char sAnswerTime[],char sOutput[]);

void TrimLeft(char * s);
void TrimRight(char * s);
void AllTrim(char *s);
void TrimDate(char sDate[15]);

void TrimLeftX(char * s,char X);
void TrimRightX(char *s,char X);
void TrimAllX(char *s,char X);
void RightPad(char sTemp[],int iLen,char c);
void LeftPad(char sTemp[],int iLen,char c);
void TrimAllS(char *s,char *S);
void TrimAll(char *s);
void Upper(char *s);
void Lower(char *s);
void WaitSec(int iSec);
int  Str2Int(char sTemp[]);

int SearchOffString(char sRecord[],int iOffset,int iSeparator,char sTemp[]);
int ParseArgv(char sRecord[], int chr);

/*�ж��Ƿ���������ѡ��,TRUE����,FALSE������*/
int ExistOtherOption(int argc,char *argv[],char sOptionFilter[]);
/*�Ƿ����ĳ��ѡ�� TRUE����,FALSE������*/
int ExistOption(int argc,char *argv[],char sOptionFilter[]);
/*��ȡĳѡ���Ƿ����,FOUND,NOTFOUND,ѡ���Ĵ�����*/
int SearchOptionStr(int argc,char *argv[],char sOptionFilter[],char sOption[]);
/*��ȡĳѡ���Ƿ����,FOUND,NOTFOUND,ѡ���Ĵ�����*/
int SearchOptionInt(int argc,char *argv[],char sOptionFilter[],int *piOption);

int LLike(char sInput[],char sVal[]);
int RLike(char sInput[],char sVal[]);

#define PARSE_ARRAY_LEN 50
#define PARSE_ITEM_LEN  60
extern char ParseToken[PARSE_ARRAY_LEN][PARSE_ITEM_LEN];

void ReverseAll(char *s);
void DelSubStr(char sInput[],char sSub[]);
void Replace(char sInput[],char x,char y);
void ReplaceStr(char sInput[],char x[],char y[]);

int Like(char sStr[],char P[]);
int LikeX(char sStr[],char P[]);

int HostTimeEff(char sEffDate[],char sExpDate[]);



#endif
