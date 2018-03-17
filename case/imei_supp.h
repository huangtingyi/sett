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

/*����ṹ��������*/
struct ImeiUpStructOut{

#ifndef IMEI_UP_BUFLEN_OUT
#define IMEI_UP_BUFLEN_OUT		300
#endif

	struct ImeiUpStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ���к� */
	char    asRsSeq[IMEI_UP_BUFLEN_OUT][19];
		/* �û����� */
	char    asMsisdn[IMEI_UP_BUFLEN_OUT][21];
		/* IMEI�ţ��ֻ����Ӵ��� */
	char    asImei[IMEI_UP_BUFLEN_OUT][31];
		/* �����ƶ��û�ʶ���� */
	char    asImsi[IMEI_UP_BUFLEN_OUT][21];
		/* ͨ��ʱ�� */
	char    asCallstarttime[IMEI_UP_BUFLEN_OUT][15];
		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    asMatchitem[IMEI_UP_BUFLEN_OUT][2];
		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char    asType[IMEI_UP_BUFLEN_OUT][2];
		/*����*/
	char	asAreaID[IMEI_UP_BUFLEN_OUT][2];
	int	aiGroupID[IMEI_UP_BUFLEN_OUT];
		/* ��¼����ʱ�� */
	char    asCreatetime[IMEI_UP_BUFLEN_OUT][21];
};


/* ����ṹ��������*/
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
		/* ���к� */
	char    asRsSeq[IMEI_UP_BUFLEN_IN][19];
		/* �û����� */
	char    asMsisdn[IMEI_UP_BUFLEN_IN][21];
		/* IMEI�ţ��ֻ����Ӵ��� */
	char    asImei[IMEI_UP_BUFLEN_IN][31];
		/* �����ƶ��û�ʶ���� */
	char    asImsi[IMEI_UP_BUFLEN_IN][21];
		/* ͨ��ʱ�� */
	char    asCallstarttime[IMEI_UP_BUFLEN_IN][15];
		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    asMatchitem[IMEI_UP_BUFLEN_IN][2];
		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char    asType[IMEI_UP_BUFLEN_IN][2];
		/*����*/
	char	asAreaID[IMEI_UP_BUFLEN_IN][2];
	int	aiGroupID[IMEI_UP_BUFLEN_IN];
		/* ��¼����ʱ�� */
	char    asCreatetime[IMEI_UP_BUFLEN_IN][21];
};


/*�����ṹ����*/
struct ImeiUpStruct{

	struct ImeiUpStruct *pNext;
	char    sRsSeq[19];		/* ���к� */
	char    sMsisdn[21];		/* �û����� */
	char    sImei[31];		/* IMEI�ţ��ֻ����Ӵ��� */
	char    sImsi[21];		/* �����ƶ��û�ʶ���� */
	char    sCallstarttime[15];		/* ͨ��ʱ�� */
	char    sMatchitem[2];		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    sType[2];		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char	sAreaID[2];		/*����*/
	char    sCreatetime[21];		/* ��¼����ʱ�� */
	
	char	sFlag[2];
	int	iGroupID;
	
	struct ImeiUpStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FImeiUpStruct{

	char    sRsSeq[18];		/* ���к� */
	char    sMsisdn[20];		/* �û����� */
	char    sImei[30];		/* IMEI�ţ��ֻ����Ӵ��� */
	char    sImsi[20];		/* �����ƶ��û�ʶ���� */
	char    sCallstarttime[14];		/* ͨ��ʱ�� */
	char    sMatchitem[1];		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    sType[1];		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char	sAreaID[1];		/* ���� */
	char    sCreatetime[20];		/* ��¼����ʱ�� */
};


/*�������ݶ�̬��IMEI_UP���ýṹ���巽ʽȡ����*/
int EGetImeiUpToStruct(struct ImeiUpStruct *p,
	struct ImeiUpStructIn *pSource);
/**�Ա�IMEI_UP�������ͷź���**/
void DestroyImeiUp(struct ImeiUpStruct *ptHead);
/*�������ݽṹ����д��IMEI_UP*/
int EInsertStructToImeiUp(struct ImeiUpStruct *p,
	int iInsertFlag,struct ImeiUpStructOut *pTarget);
int GetRsSeq(char sValue[]);

/* ����ṹ��������*/
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
		/* �û����� */
	char    asMsisdn[IMEI_UP_BUFLEN_IN][21];
		/* IMEI�ţ��ֻ����Ӵ��� */
	char    asImei[IMEI_UP_BUFLEN_IN][31];
		/* �����ƶ��û�ʶ���� */
	char    asImsi[IMEI_UP_BUFLEN_IN][21];
	
};


/*�����ṹ����*/
struct ImeiUpStructX{

	struct ImeiUpStructX *pNext;
	char    sMsisdn[21];		/* �û����� */
	char    sImei[31];		/* IMEI�ţ��ֻ����Ӵ��� */
	char    sImsi[21];		/* �����ƶ��û�ʶ���� */

	struct ImeiUpStruct *pLoadNext;
};

/*�������ݶ�̬��IMEI_UP���ýṹ���巽ʽȡ����*/
int EGetImeiUpToStructX(struct ImeiUpStructX *p,
	struct ImeiUpStructXIn *pSource);
#endif
