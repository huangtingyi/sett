#ifndef __TLL_DAT_STAT_SUPP_H__
#define __TLL_DAT_STAT_SUPP_H__

#include "toll_voip193_supp.h"

/*����ṹ��������*/
struct SttSjStructOut{

#ifndef STT_SJ_BUFLEN_OUT
#define STT_SJ_BUFLEN_OUT		300
#endif

	struct SttSjStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ���к��� */
	char    asCallingNbr[STT_SJ_BUFLEN_OUT][21];
		/* �������� */
	char    asCallingAreaCode[STT_SJ_BUFLEN_OUT][6];
		/* �����û����� */
	char    asCallingUserType[STT_SJ_BUFLEN_OUT][2];
		/* ���к��� */
	char    asCalledNbr[STT_SJ_BUFLEN_OUT][25];
		/* �������� */
	char    asVisitAreaCode[STT_SJ_BUFLEN_OUT][6];
		/* �����û����� */
	char    asCalledUserType[STT_SJ_BUFLEN_OUT][2];
		/* ͨ����ʼʱ�� */
	char    asStartTime[STT_SJ_BUFLEN_OUT][15];
		/* ͨ��ʱ�� */
	int     aiDuration[STT_SJ_BUFLEN_OUT];
		/* ��;�� */
	int     aiTollFee[STT_SJ_BUFLEN_OUT];
};


/* ����ṹ��������*/
struct SttSjStructIn{

#ifndef STT_SJ_BUFLEN_IN
#define STT_SJ_BUFLEN_IN		300
#endif

	struct SttSjStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ���к��� */
	char    asCallingNbr[STT_SJ_BUFLEN_IN][21];
		/* �������� */
	char    asCallingAreaCode[STT_SJ_BUFLEN_IN][6];
		/* �����û����� */
	char    asCallingUserType[STT_SJ_BUFLEN_IN][2];
		/* ���к��� */
	char    asCalledNbr[STT_SJ_BUFLEN_IN][25];
		/* �������� */
	char    asVisitAreaCode[STT_SJ_BUFLEN_IN][6];
		/* �����û����� */
	char    asCalledUserType[STT_SJ_BUFLEN_IN][2];
		/* ͨ����ʼʱ�� */
	char    asStartTime[STT_SJ_BUFLEN_IN][15];
		/* ͨ��ʱ�� */
	int     aiDuration[STT_SJ_BUFLEN_IN];
		/* ��;�� */
	int     aiTollFee[STT_SJ_BUFLEN_IN];
};


/*�����ṹ����*/
struct SttSjStruct{

	struct SttSjStruct *pNext;
	char    sCallingNbr[31];		/* ���к��� */
	char    sCallingAreaCode[6];		/* �������� */
	char    sCallingUserType[2];		/* �����û����� */
	char    sCalledNbr[21];		/* ���к��� */
	char    sVisitAreaCode[6];		/* �������� */
	char    sCalledUserType[2];		/* �����û����� */
	char    sStartTime[15];		/* ͨ����ʼʱ�� */
	int     iDuration;		/* ͨ��ʱ�� */
	int     iTollFee;		/* ��;�� */
	struct SttSjStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSttSjStruct{

	char    sCallingNbr[30];		/* ���к��� */
	char    sCallingAreaCode[5];		/* �������� */
	char    sCallingUserType[1];		/* �����û����� */
	char    sCalledNbr[20];		/* ���к��� */
	char    sVisitAreaCode[5];		/* �������� */
	char    sCalledUserType[1];		/* �����û����� */
	char    sStartTime[14];		/* ͨ����ʼʱ�� */
	char    sDuration[6];		/* ͨ��ʱ�� */
	char    sTollFee[8];		/* ��;�� */
};

/*�������ݶ�̬��STT_SJ���ýṹ���巽ʽȡ����*/
int EGetSttSjToStruct(struct SttSjStruct *p,
	struct SttSjStructIn *pSource);

static int aiCapitalAreaCode[31]=
{
       10,20,21,22,23,24,25,27,28,29,311,351,
       371,431,451,471,531,551,571,591,731,771,
       791,851,871,891,898,931,951,971,991
};


int EInsertStructToMobCalledStat(struct MobCalledStatStruct *p,
	int iInsertFlag,struct MobCalledStatStructOut *pTarget);	


#endif
