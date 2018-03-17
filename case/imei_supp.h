#ifndef __IMEI_SUPP_H__
#define __IMEI_SUPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sqlca.h>
#include <datatype.h>
#include <trie.h>
#include <list.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

/*输出结构缓冲申明*/
struct ImeiUpStructOut{

#ifndef IMEI_UP_BUFLEN_OUT
#define IMEI_UP_BUFLEN_OUT		300
#endif

	struct ImeiUpStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 序列号 */
	char    asRsSeq[IMEI_UP_BUFLEN_OUT][19];
		/* 用户号码 */
	char    asMsisdn[IMEI_UP_BUFLEN_OUT][21];
		/* IMEI号，手机电子串号 */
	char    asImei[IMEI_UP_BUFLEN_OUT][31];
		/* 国际移动用户识别码 */
	char    asImsi[IMEI_UP_BUFLEN_OUT][21];
		/* 通话时间 */
	char    asCallstarttime[IMEI_UP_BUFLEN_OUT][15];
		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    asMatchitem[IMEI_UP_BUFLEN_OUT][2];
		/* 数据类型：１表示本省，２表示漫游 */
	char    asType[IMEI_UP_BUFLEN_OUT][2];
		/*地市*/
	char	asAreaID[IMEI_UP_BUFLEN_OUT][2];
	int	aiGroupID[IMEI_UP_BUFLEN_OUT];
		/* 记录处理时间 */
	char    asCreatetime[IMEI_UP_BUFLEN_OUT][21];
};


/* 输入结构缓冲申明*/
struct ImeiUpStructIn{

#ifndef IMEI_UP_BUFLEN_IN
#define IMEI_UP_BUFLEN_IN		300
#endif

	struct ImeiUpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[4096];
		/* 序列号 */
	char    asRsSeq[IMEI_UP_BUFLEN_IN][19];
		/* 用户号码 */
	char    asMsisdn[IMEI_UP_BUFLEN_IN][21];
		/* IMEI号，手机电子串号 */
	char    asImei[IMEI_UP_BUFLEN_IN][31];
		/* 国际移动用户识别码 */
	char    asImsi[IMEI_UP_BUFLEN_IN][21];
		/* 通话时间 */
	char    asCallstarttime[IMEI_UP_BUFLEN_IN][15];
		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    asMatchitem[IMEI_UP_BUFLEN_IN][2];
		/* 数据类型：１表示本省，２表示漫游 */
	char    asType[IMEI_UP_BUFLEN_IN][2];
		/*地市*/
	char	asAreaID[IMEI_UP_BUFLEN_IN][2];
	int	aiGroupID[IMEI_UP_BUFLEN_IN];
		/* 记录处理时间 */
	char    asCreatetime[IMEI_UP_BUFLEN_IN][21];
};


/*单个结构申明*/
struct ImeiUpStruct{

	struct ImeiUpStruct *pNext;
	char    sRsSeq[19];		/* 序列号 */
	char    sMsisdn[21];		/* 用户号码 */
	char    sImei[31];		/* IMEI号，手机电子串号 */
	char    sImsi[21];		/* 国际移动用户识别码 */
	char    sCallstarttime[15];		/* 通话时间 */
	char    sMatchitem[2];		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    sType[2];		/* 数据类型：１表示本省，２表示漫游 */
	char	sAreaID[2];		/*地市*/
	char    sCreatetime[21];		/* 记录处理时间 */
	
	char	sFlag[2];
	int	iGroupID;
	
	struct ImeiUpStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FImeiUpStruct{

	char    sRsSeq[18];		/* 序列号 */
	char    sMsisdn[20];		/* 用户号码 */
	char    sImei[30];		/* IMEI号，手机电子串号 */
	char    sImsi[20];		/* 国际移动用户识别码 */
	char    sCallstarttime[14];		/* 通话时间 */
	char    sMatchitem[1];		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    sType[1];		/* 数据类型：１表示本省，２表示漫游 */
	char	sAreaID[1];		/* 地市 */
	char    sCreatetime[20];		/* 记录处理时间 */
};


/*批量数据动态从IMEI_UP中用结构缓冲方式取数据*/
int EGetImeiUpToStruct(struct ImeiUpStruct *p,
	struct ImeiUpStructIn *pSource);
/**对表IMEI_UP的链表释放函数**/
void DestroyImeiUp(struct ImeiUpStruct *ptHead);
/*批量数据结构缓冲写入IMEI_UP*/
int EInsertStructToImeiUp(struct ImeiUpStruct *p,
	int iInsertFlag,struct ImeiUpStructOut *pTarget);
int GetRsSeq(char sValue[]);

/* 输入结构缓冲申明*/
struct ImeiUpStructXIn{

#ifndef IMEI_UP_BUFLEN_IN
#define IMEI_UP_BUFLEN_IN		300
#endif

	struct ImeiUpStructXIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[4096];
		/* 用户号码 */
	char    asMsisdn[IMEI_UP_BUFLEN_IN][21];
		/* IMEI号，手机电子串号 */
	char    asImei[IMEI_UP_BUFLEN_IN][31];
		/* 国际移动用户识别码 */
	char    asImsi[IMEI_UP_BUFLEN_IN][21];
	
};


/*单个结构申明*/
struct ImeiUpStructX{

	struct ImeiUpStructX *pNext;
	char    sMsisdn[21];		/* 用户号码 */
	char    sImei[31];		/* IMEI号，手机电子串号 */
	char    sImsi[21];		/* 国际移动用户识别码 */

	struct ImeiUpStruct *pLoadNext;
};

/*批量数据动态从IMEI_UP中用结构缓冲方式取数据*/
int EGetImeiUpToStructX(struct ImeiUpStructX *p,
	struct ImeiUpStructXIn *pSource);
#endif
