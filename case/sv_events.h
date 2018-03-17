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

/*����һ��64λ������*/
/*typedef long LONGINT;*/
/*ORACLE���ú궨��*/
#ifndef NoDataFetched
#define NoDataFetched (sqlca.sqlcode==1403||sqlca.sqlcode==100)
#endif
#ifndef FetchColNum
#define FetchColNum   (sqlca.sqlerrd[2])
#endif


/*�����ṹ����*/
struct SvEventTempStruct{

	struct SvEventTempStruct *pNext;
	char    sTmpID[17];		/* ��ʱ���ϵ���ID�� */
	char    sTmpDeviceName[513];		/* �������ϵ��豸����ito browser�б�ʾΪnode */
	char    sTmpCategory[257];		/* ���ϵ����ͣ���ito browser�б�ʾΪobject�� */
	int     iTmpSeverity;		/* ���ϵļ��� */
	char    sTmpObject[513];		/* ���϶��� */
	char    sTmpIpAddress[61];		/* �豸IP��ַ */
	char    sTmpContent[4001];		/* ������������ito browser �б�ʾΪmessage text�� */
	char    sTmpCreatedTime[15];		/* ���Ϸ�����ʱ��(�����豸��ϵͳʱ��) */
	char    sTmpReceivedTime[15];		/* ITO���������չ��ϵ�ʱ�� */
	char    sMessageNumber[73];		/* ��Ϣ�� */
	char    sEventSource[201];		/* �¼���Դ */
	struct SvEventTempStruct *pLoadNext;
};



/*����ṹ��������*/
struct SvEventTempStructOut{

#ifndef SV_EVENT_TEMP_BUFLEN_OUT
#define SV_EVENT_TEMP_BUFLEN_OUT		300
#endif

	struct SvEventTempStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��ʱ���ϵ���ID�� */
	char    asTmpID[SV_EVENT_TEMP_BUFLEN_OUT][17];
		/* �������ϵ��豸����ito browser�б�ʾΪnode */
	char    asTmpDeviceName[SV_EVENT_TEMP_BUFLEN_OUT][513];
		/* ���ϵ����ͣ���ito browser�б�ʾΪobject�� */
	char    asTmpCategory[SV_EVENT_TEMP_BUFLEN_OUT][257];
		/* ���ϵļ��� */
	int     aiTmpSeverity[SV_EVENT_TEMP_BUFLEN_OUT];
		/* ���϶��� */
	char    asTmpObject[SV_EVENT_TEMP_BUFLEN_OUT][513];
		/* �豸IP��ַ */
	char    asTmpIpAddress[SV_EVENT_TEMP_BUFLEN_OUT][61];
		/* ������������ito browser �б�ʾΪmessage text�� */
	char    asTmpContent[SV_EVENT_TEMP_BUFLEN_OUT][4001];
		/* ���Ϸ�����ʱ��(�����豸��ϵͳʱ��) */
	char    asTmpCreatedTime[SV_EVENT_TEMP_BUFLEN_OUT][15];
		/* ITO���������չ��ϵ�ʱ�� */
	char    asTmpReceivedTime[SV_EVENT_TEMP_BUFLEN_OUT][15];
		/* ��Ϣ�� */
	char    asMessageNumber[SV_EVENT_TEMP_BUFLEN_OUT][73];
		/* �¼���Դ */
	char    asEventSource[SV_EVENT_TEMP_BUFLEN_OUT][201];
};


/* ����ṹ��������*/
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
		/* ��ʱ���ϵ���ID�� */
	int     aiAlertID[ALERT_INFO_BUFLEN_IN];
		/* �������ϵ��豸 */
	char    asDeviceName[ALERT_INFO_BUFLEN_IN][61];
		/* ���ϵ����� */
	char    asCategory[ALERT_INFO_BUFLEN_IN][61];
		/* ���ϵļ��� */
	int     aiLevel1[ALERT_INFO_BUFLEN_IN];
		/* ���϶��� */
	char    asObjectName[ALERT_INFO_BUFLEN_IN][61];
		/* �豸IP��ַ */
	char    asDeviceIp[ALERT_INFO_BUFLEN_IN][17];
		/* �������� */
	char    asRemark[ALERT_INFO_BUFLEN_IN][513];
		/* �����豸��ϵͳʱ�� */
	char    asCreatedDate[ALERT_INFO_BUFLEN_IN][15];
		/* ITO���������չ��ϵ�ʱ�� */
	char    asDealDate[ALERT_INFO_BUFLEN_IN][15];
		/* �¼���Դ */
	char    asAlertSource[ALERT_INFO_BUFLEN_IN][101];
		/* ��Ϣ�� */
	char    asMsgID[ALERT_INFO_BUFLEN_IN][101];
		/* 0:δ����  1:�ѷ��� */
	char    asSendState[ALERT_INFO_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asSendDate[ALERT_INFO_BUFLEN_IN][15];
	char	asRowID[ALERT_INFO_BUFLEN_IN][19];
};

/*�����ṹ����*/
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

/*�����ݵ�ȡ��*/
/*�������ݶ�̬��ALERT_INFO���ýṹ���巽ʽȡ����*/
int EGetUAlertInfoToStruct(struct UAlertInfoStruct *p,
	struct AlertInfoStructIn *pSource);

/*�����ݵ�д��*/
int EInsertStructToSvEventTemp(struct SvEventTempStruct *p,
	int iInsertFlag,struct SvEventTempStructOut *pTarget);
	
/*�������ݽṹ����д��ALERT_INFO*/
int EUpdateStructToUAlertInfo(struct UAlertInfoStruct *p,
	int iUpdateFlag,struct UAlertInfoStructUp *pTarget);

#endif
