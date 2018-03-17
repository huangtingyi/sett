#ifndef __SV_EVENT_TEMP_H__
#define __SV_EVENT_TEMP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sqlca.h>
#include <datatype.h>
#include <trie.h>
#include <list.h>
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
struct SvEventTempStruct{

	struct SvEventTempStruct *pNext;
	char    sTmpID[17];		/* 临时故障单的ID号 */
	char    sTmpDeviceName[513];		/* 发生故障的设备。在ito browser中表示为node */
	char    sTmpCategory[257];		/* 故障的类型，在ito browser中表示为object。 */
	int     iTmpSeverity;		/* 故障的级别 */
	char    sTmpObject[513];		/* 故障对象 */
	char    sTmpIpAddress[61];		/* 设备IP地址 */
	char    sTmpContent[4001];		/* 故障描述，在ito browser 中表示为message text。 */
	char    sTmpCreatedTime[15];		/* 故障发生的时间(故障设备的系统时间) */
	char    sTmpReceivedTime[15];		/* ITO服务器接收故障的时间 */
	char    sMessageNumber[73];		/* 消息号 */
	char    sEventSource[201];		/* 事件来源 */
	struct SvEventTempStruct *pLoadNext;
};



/*输出结构缓冲申明*/
struct SvEventTempStructOut{

#ifndef SV_EVENT_TEMP_BUFLEN_OUT
#define SV_EVENT_TEMP_BUFLEN_OUT		300
#endif

	struct SvEventTempStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 临时故障单的ID号 */
	char    asTmpID[SV_EVENT_TEMP_BUFLEN_OUT][17];
		/* 发生故障的设备。在ito browser中表示为node */
	char    asTmpDeviceName[SV_EVENT_TEMP_BUFLEN_OUT][513];
		/* 故障的类型，在ito browser中表示为object。 */
	char    asTmpCategory[SV_EVENT_TEMP_BUFLEN_OUT][257];
		/* 故障的级别 */
	int     aiTmpSeverity[SV_EVENT_TEMP_BUFLEN_OUT];
		/* 故障对象 */
	char    asTmpObject[SV_EVENT_TEMP_BUFLEN_OUT][513];
		/* 设备IP地址 */
	char    asTmpIpAddress[SV_EVENT_TEMP_BUFLEN_OUT][61];
		/* 故障描述，在ito browser 中表示为message text。 */
	char    asTmpContent[SV_EVENT_TEMP_BUFLEN_OUT][4001];
		/* 故障发生的时间(故障设备的系统时间) */
	char    asTmpCreatedTime[SV_EVENT_TEMP_BUFLEN_OUT][15];
		/* ITO服务器接收故障的时间 */
	char    asTmpReceivedTime[SV_EVENT_TEMP_BUFLEN_OUT][15];
		/* 消息号 */
	char    asMessageNumber[SV_EVENT_TEMP_BUFLEN_OUT][73];
		/* 事件来源 */
	char    asEventSource[SV_EVENT_TEMP_BUFLEN_OUT][201];
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
	char	asRowID[ALERT_INFO_BUFLEN_IN][19];
};

/*单个结构申明*/
struct UAlertInfoStruct{

	struct UAlertInfoStruct *pNext;
	int     iAlertID;
	char    sDeviceName[61];
	char    sCategory[61];
	int     iLevel1;
	char    sObjectName[61];
	char    sDeviceIp[17];
	char    sRemark[513];
	char    sCreatedDate[15];
	char    sDealDate[15];
	char    sAlertSource[101];
	char    sMsgID[101];
	char    sSendState[2];
	char    sSendDate[15];
	char	sRowID[19];
	struct UAlertInfoStruct *pLoadNext;
};      

struct UAlertInfoStructUp
{       
#ifndef ALERT_INFO_BUFLEN_UP
#define ALERT_INFO_BUFLEN_UP 	300
#endif  
	int	iCurPos;
	char	sTableName[31];
	
	int     aiAlertID[ALERT_INFO_BUFLEN_UP];
	char    asDeviceName[ALERT_INFO_BUFLEN_UP][61];
	char    asCategory[ALERT_INFO_BUFLEN_UP][61];
	int     aiLevel1[ALERT_INFO_BUFLEN_UP];
	char    asObjectName[ALERT_INFO_BUFLEN_UP][61];
	char    asDeviceIp[ALERT_INFO_BUFLEN_UP][17];
	char    asRemark[ALERT_INFO_BUFLEN_UP][513];
	char    asCreatedDate[ALERT_INFO_BUFLEN_UP][15];
	char    asDealDate[ALERT_INFO_BUFLEN_UP][15];
	char    asAlertSource[ALERT_INFO_BUFLEN_UP][101];
	char    asMsgID[ALERT_INFO_BUFLEN_UP][101];
	char    asSendState[ALERT_INFO_BUFLEN_UP][2];
	char    asSendDate[ALERT_INFO_BUFLEN_UP][15];
	char	asRowID[ALERT_INFO_BUFLEN_UP][19];
};

/*对数据的取出*/
/*批量数据动态从ALERT_INFO中用结构缓冲方式取数据*/
int EGetUAlertInfoToStruct(struct UAlertInfoStruct *p,
	struct AlertInfoStructIn *pSource);

/*对数据的写入*/
int EInsertStructToSvEventTemp(struct SvEventTempStruct *p,
	int iInsertFlag,struct SvEventTempStructOut *pTarget);
	
/*批量数据结构缓冲写入ALERT_INFO*/
int EUpdateStructToUAlertInfo(struct UAlertInfoStruct *p,
	int iUpdateFlag,struct UAlertInfoStructUp *pTarget);

#endif
