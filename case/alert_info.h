#ifndef __ALERT_INFO_H__
#define __ALERT_INFO_H__

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

/*定义一个64位的类型*/
/*typedef long LONGINT;*/
/*ORACLE引用宏定义*/
#ifndef NoDataFetched
#define NoDataFetched (sqlca.sqlcode==1403||sqlca.sqlcode==100)
#endif
#ifndef FetchColNum
#define FetchColNum   (sqlca.sqlerrd[2])
#endif


/*单个结构申明*/
struct AlertInfoStruct{

	struct AlertInfoStruct *pNext;
	int     iAlertID;		/* 临时故障单的ID号 */
	char    sDeviceName[61];		/* 发生故障的设备 */
	char    sCategory[61];		/* 故障的类型 */
	int     iLevel1;		/* 故障的级别 */
	char    sObjectName[61];		/* 故障对象 */
	char    sDeviceIp[17];		/* 设备IP地址 */
	char    sRemark[513];		/* 故障描述 */
	char    sCreatedDate[15];		/* 故障设备的系统时间 */
	char    sDealDate[15];		/* ITO服务器接收故障的时间 */
	char    sAlertSource[101];		/* 事件来源 */
	char    sMsgID[101];		/* 消息号 */
	char    sSendState[2];		/* 0:未发送  1:已发送 */
	char    sSendDate[15];		/* 发送时间 */
	struct AlertInfoStruct *pLoadNext;
};



/*输出结构缓冲申明*/
struct AlertInfoStructOut{

#ifndef ALERT_INFO_BUFLEN_OUT
#define ALERT_INFO_BUFLEN_OUT		300
#endif

	struct AlertInfoStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 临时故障单的ID号 */
	int     aiAlertID[ALERT_INFO_BUFLEN_OUT];
		/* 发生故障的设备 */
	char    asDeviceName[ALERT_INFO_BUFLEN_OUT][61];
		/* 故障的类型 */
	char    asCategory[ALERT_INFO_BUFLEN_OUT][61];
		/* 故障的级别 */
	int     aiLevel1[ALERT_INFO_BUFLEN_OUT];
		/* 故障对象 */
	char    asObjectName[ALERT_INFO_BUFLEN_OUT][61];
		/* 设备IP地址 */
	char    asDeviceIp[ALERT_INFO_BUFLEN_OUT][17];
		/* 故障描述 */
	char    asRemark[ALERT_INFO_BUFLEN_OUT][513];
		/* 故障设备的系统时间 */
	char    asCreatedDate[ALERT_INFO_BUFLEN_OUT][15];
		/* ITO服务器接收故障的时间 */
	char    asDealDate[ALERT_INFO_BUFLEN_OUT][15];
		/* 事件来源 */
	char    asAlertSource[ALERT_INFO_BUFLEN_OUT][101];
		/* 消息号 */
	char    asMsgID[ALERT_INFO_BUFLEN_OUT][101];
		/* 0:未发送  1:已发送 */
	char    asSendState[ALERT_INFO_BUFLEN_OUT][2];
		/* 发送时间 */
	char    asSendDate[ALERT_INFO_BUFLEN_OUT][15];
};



/* 输入结构缓冲申明*/
struct AlertInfoStructIn{

#ifndef ALERT_INFO_BUFLEN_IN
#define ALERT_INFO_BUFLEN_IN		300
#endif

	struct AlertInfoStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 临时故障单的ID号 */
	int     aiAlertID[ALERT_INFO_BUFLEN_IN];
		/* 发生故障的设备 */
	char    asDeviceName[ALERT_INFO_BUFLEN_IN][61];
		/* 故障的类型 */
	char    asCategory[ALERT_INFO_BUFLEN_IN][61];
		/* 故障的级别 */
	int     aiLevel1[ALERT_INFO_BUFLEN_IN];
		/* 故障对象 */
	char    asObjectName[ALERT_INFO_BUFLEN_IN][61];
		/* 设备IP地址 */
	char    asDeviceIp[ALERT_INFO_BUFLEN_IN][17];
		/* 故障描述 */
	char    asRemark[ALERT_INFO_BUFLEN_IN][513];
		/* 故障设备的系统时间 */
	char    asCreatedDate[ALERT_INFO_BUFLEN_IN][15];
		/* ITO服务器接收故障的时间 */
	char    asDealDate[ALERT_INFO_BUFLEN_IN][15];
		/* 事件来源 */
	char    asAlertSource[ALERT_INFO_BUFLEN_IN][101];
		/* 消息号 */
	char    asMsgID[ALERT_INFO_BUFLEN_IN][101];
		/* 0:未发送  1:已发送 */
	char    asSendState[ALERT_INFO_BUFLEN_IN][2];
		/* 发送时间 */
	char    asSendDate[ALERT_INFO_BUFLEN_IN][15];
};


/*对数据的取出*/
/*批量数据动态从ALERT_INFO中用结构缓冲方式取数据*/
int EGetAlertInfoToStruct(struct AlertInfoStruct *p,
	struct AlertInfoStructIn *pSource);

/*对数据的写入*/
int EInsertStructToAlertInfo(struct AlertInfoStruct *p,
	int iInsertFlag,struct AlertInfoStructOut *pTarget);


#endif
