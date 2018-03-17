#ifndef __MSISDN_IMSI_H__
#define __MSISDN_IMSI_H__

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <bintree.h>
#include <wwfile.h>
#include <ticket.h>

/*����ṹ��������*/
struct MsisdnImsiStatStructOut{

#ifndef MSISDN_IMSI_STAT_BUFLEN_OUT
#define MSISDN_IMSI_STAT_BUFLEN_OUT		300
#endif

	struct MsisdnImsiStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asMsisdn[MSISDN_IMSI_STAT_BUFLEN_OUT][16];
	char    asImsi[MSISDN_IMSI_STAT_BUFLEN_OUT][16];
	char    asScpFlag[MSISDN_IMSI_STAT_BUFLEN_OUT][2];
	char	asRowID[MSISDN_IMSI_STAT_BUFLEN_OUT][19];
};


/* ����ṹ��������*/
struct MsisdnImsiStatStructIn{

#ifndef MSISDN_IMSI_STAT_BUFLEN_IN
#define MSISDN_IMSI_STAT_BUFLEN_IN		300
#endif

	struct MsisdnImsiStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asMsisdn[MSISDN_IMSI_STAT_BUFLEN_IN][16];
	char    asImsi[MSISDN_IMSI_STAT_BUFLEN_IN][16];
	char    asScpFlag[MSISDN_IMSI_STAT_BUFLEN_IN][2];
	char	asRowID[MSISDN_IMSI_STAT_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct MsisdnImsiStatStruct{

	struct MsisdnImsiStatStruct *pNext;
	char    sMsisdn[16];
	char    sImsi[16];
	char    sScpFlag[2];
	char	sRowID[19];
	struct MsisdnImsiStatStruct *pLoadNext;
};
/*�����ṹ����*/
struct MsisdnImsiStatHHStruct{

	struct MsisdnImsiStatHHStruct *pNext;
	char    sMsisdn[16];
	char    sImsi[16];
	char    sScpFlag[2];
	char    sHh[3];
	char	sRowID[19];
	struct MsisdnImsiStatHHStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FMsisdnImsiStatStruct{

	char    sMsisdn[15];
	char    sImsi[15];
	char    sScpFlag[1];
};

/*�������ݶ�̬��MSISDN_IMSI_STAT���ýṹ���巽ʽȡ����*/
int EGetMsisdnImsiStatToStruct(struct MsisdnImsiStatStruct *p,
	struct MsisdnImsiStatStructIn *pSource);

/**�Ա�MSISDN_IMSI_STAT�������ͷź���**/
void DestroyMsisdnImsiStat(struct MsisdnImsiStatStruct *ptHead);

/*�������ݽṹ����д��MSISDN_IMSI_STAT*/
int EInsertStructToMsisdnImsiStat(struct MsisdnImsiStatStruct *p,
	int iInsertFlag,struct MsisdnImsiStatStructOut *pTarget);
/*��������*/
int UpdateDateToMsisdnImsiStat(struct MsisdnImsiStatStruct *p,
	int iUpdateFlag,struct MsisdnImsiStatStructOut *pTarget);



#endif
