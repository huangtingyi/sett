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
struct AlertInfoStruct{

	struct AlertInfoStruct *pNext;
	int     iAlertID;		/* ��ʱ���ϵ���ID�� */
	char    sDeviceName[61];		/* �������ϵ��豸 */
	char    sCategory[61];		/* ���ϵ����� */
	int     iLevel1;		/* ���ϵļ��� */
	char    sObjectName[61];		/* ���϶��� */
	char    sDeviceIp[17];		/* �豸IP��ַ */
	char    sRemark[513];		/* �������� */
	char    sCreatedDate[15];		/* �����豸��ϵͳʱ�� */
	char    sDealDate[15];		/* ITO���������չ��ϵ�ʱ�� */
	char    sAlertSource[101];		/* �¼���Դ */
	char    sMsgID[101];		/* ��Ϣ�� */
	char    sSendState[2];		/* 0:δ����  1:�ѷ��� */
	char    sSendDate[15];		/* ����ʱ�� */
	struct AlertInfoStruct *pLoadNext;
};



/*����ṹ��������*/
struct AlertInfoStructOut{

#ifndef ALERT_INFO_BUFLEN_OUT
#define ALERT_INFO_BUFLEN_OUT		300
#endif

	struct AlertInfoStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��ʱ���ϵ���ID�� */
	int     aiAlertID[ALERT_INFO_BUFLEN_OUT];
		/* �������ϵ��豸 */
	char    asDeviceName[ALERT_INFO_BUFLEN_OUT][61];
		/* ���ϵ����� */
	char    asCategory[ALERT_INFO_BUFLEN_OUT][61];
		/* ���ϵļ��� */
	int     aiLevel1[ALERT_INFO_BUFLEN_OUT];
		/* ���϶��� */
	char    asObjectName[ALERT_INFO_BUFLEN_OUT][61];
		/* �豸IP��ַ */
	char    asDeviceIp[ALERT_INFO_BUFLEN_OUT][17];
		/* �������� */
	char    asRemark[ALERT_INFO_BUFLEN_OUT][513];
		/* �����豸��ϵͳʱ�� */
	char    asCreatedDate[ALERT_INFO_BUFLEN_OUT][15];
		/* ITO���������չ��ϵ�ʱ�� */
	char    asDealDate[ALERT_INFO_BUFLEN_OUT][15];
		/* �¼���Դ */
	char    asAlertSource[ALERT_INFO_BUFLEN_OUT][101];
		/* ��Ϣ�� */
	char    asMsgID[ALERT_INFO_BUFLEN_OUT][101];
		/* 0:δ����  1:�ѷ��� */
	char    asSendState[ALERT_INFO_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asSendDate[ALERT_INFO_BUFLEN_OUT][15];
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
};


/*�����ݵ�ȡ��*/
/*�������ݶ�̬��ALERT_INFO���ýṹ���巽ʽȡ����*/
int EGetAlertInfoToStruct(struct AlertInfoStruct *p,
	struct AlertInfoStructIn *pSource);

/*�����ݵ�д��*/
int EInsertStructToAlertInfo(struct AlertInfoStruct *p,
	int iInsertFlag,struct AlertInfoStructOut *pTarget);


#endif
