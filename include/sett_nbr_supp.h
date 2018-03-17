#ifndef __SETT_NBR_SUPP_H__
#define __SETT_NBR_SUPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <bintree.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <wwfile.h>



/*����ṹ��������*/
struct SettNbrStatStructOut{

#ifndef SETT_NBR_STAT_BUFLEN_OUT
#define SETT_NBR_STAT_BUFLEN_OUT		300
#endif

	struct SettNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������� */
	char    asAccNbr[SETT_NBR_STAT_BUFLEN_OUT][21];
		/* ��������� */
	char    asHomeAreaCode[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* �������ʡ */
	char    asProvCode[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* ��������� */
	char    asVisitAreaCode[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* ����רҵ */
	char    asNetType[SETT_NBR_STAT_BUFLEN_OUT][5];
		/* �������� */
	int     aiTicketTypeID[SETT_NBR_STAT_BUFLEN_OUT];
		/* ������ */
	int     aiCnt[SETT_NBR_STAT_BUFLEN_OUT];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_NBR_STAT_BUFLEN_OUT];	
		/* ��������� */
	int     aiSettMin[SETT_NBR_STAT_BUFLEN_OUT];
		/* �������� */
	char    asInFee[SETT_NBR_STAT_BUFLEN_OUT][13];
		/* ����֧�� */
	char    asOutFee[SETT_NBR_STAT_BUFLEN_OUT][13];
		/* ҵ������ */
	char    asServiceType[SETT_NBR_STAT_BUFLEN_OUT][4];
		/* ���˺������� */
	char    asNbrType[SETT_NBR_STAT_BUFLEN_OUT][5];
		/* �Զ˺������� */
	char    asOppNbrType[SETT_NBR_STAT_BUFLEN_OUT][5];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[SETT_NBR_STAT_BUFLEN_OUT];
		/* �Զ���Ӫ�̵����� */
	char    asOppArea[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* �Զ���Ӫ�̹���ʡ */
	char    asOppProv[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* �����ײ�ID */
	char    asBillingTypeID[SETT_NBR_STAT_BUFLEN_OUT][21];
		/* ����ά��1 */
	char    asReserve1[SETT_NBR_STAT_BUFLEN_OUT][11];
		/* ����ά��2 */
	char    asReserve2[SETT_NBR_STAT_BUFLEN_OUT][11];
		/* ����ά��3 */
	char    asReserve3[SETT_NBR_STAT_BUFLEN_OUT][11];
		/* �������� */
	char    asSettItemDate[SETT_NBR_STAT_BUFLEN_OUT][9];
		/* �������� */
	char    asBillingCycleID[SETT_NBR_STAT_BUFLEN_OUT][7];
};


/* ����ṹ��������*/
struct SettNbrStatStructIn{

#ifndef SETT_NBR_STAT_BUFLEN_IN
#define SETT_NBR_STAT_BUFLEN_IN		300
#endif

	struct SettNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ������� */
	char    asAccNbr[SETT_NBR_STAT_BUFLEN_IN][21];
		/* ��������� */
	char    asHomeAreaCode[SETT_NBR_STAT_BUFLEN_IN][6];
		/* �������ʡ */
	char    asProvCode[SETT_NBR_STAT_BUFLEN_IN][6];
		/* ��������� */
	char    asVisitAreaCode[SETT_NBR_STAT_BUFLEN_IN][6];
		/* ����רҵ */
	char    asNetType[SETT_NBR_STAT_BUFLEN_IN][5];
		/* �������� */
	int     aiTicketTypeID[SETT_NBR_STAT_BUFLEN_IN];
		/* ������ */
	int     aiCnt[SETT_NBR_STAT_BUFLEN_IN];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_NBR_STAT_BUFLEN_IN];	
		/* ��������� */
	int     aiSettMin[SETT_NBR_STAT_BUFLEN_IN];
		/* �������� */
	char    asInFee[SETT_NBR_STAT_BUFLEN_IN][13];
		/* ����֧�� */
	char    asOutFee[SETT_NBR_STAT_BUFLEN_IN][13];
		/* ҵ������ */
	char    asServiceType[SETT_NBR_STAT_BUFLEN_IN][4];
		/* ���˺������� */
	char    asNbrType[SETT_NBR_STAT_BUFLEN_IN][5];
		/* �Զ˺������� */
	char    asOppNbrType[SETT_NBR_STAT_BUFLEN_IN][5];
		/* �Զ���Ӫ�� */
	int     aiOppCarrID[SETT_NBR_STAT_BUFLEN_IN];
		/* �Զ���Ӫ�̵����� */
	char    asOppArea[SETT_NBR_STAT_BUFLEN_IN][6];
		/* �Զ���Ӫ�̹���ʡ */
	char    asOppProv[SETT_NBR_STAT_BUFLEN_IN][6];
		/* �����ײ�ID */
	char    asBillingTypeID[SETT_NBR_STAT_BUFLEN_IN][21];
		/* ����ά��1 */
	char    asReserve1[SETT_NBR_STAT_BUFLEN_IN][11];
		/* ����ά��2 */
	char    asReserve2[SETT_NBR_STAT_BUFLEN_IN][11];
		/* ����ά��3 */
	char    asReserve3[SETT_NBR_STAT_BUFLEN_IN][11];
		/* �������� */
	char    asSettItemDate[SETT_NBR_STAT_BUFLEN_IN][9];
		/* �������� */
	char    asBillingCycleID[SETT_NBR_STAT_BUFLEN_IN][7];
};


/*�����ṹ����*/
struct SettNbrStatStruct{

	struct SettNbrStatStruct *pNext;
	char    sAccNbr[21];		/* ������� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sProvCode[6];		/* �������ʡ */
	char    sVisitAreaCode[6];		/* ��������� */
	char    sNetType[5];		/* ����רҵ */
	int     iTicketTypeID;		/* �������� */
	int     iCnt;		/* ������ */
	int     iDuration;		/* ͨ��ʱ�� */	
	int     iSettMin;		/* ��������� */
	char    sInFee[13];		/* �������� */
	char    sOutFee[13];		/* ����֧�� */
	char    sServiceType[4];		/* ҵ������ */
	char    sNbrType[5];		/* ���˺������� */
	char    sOppNbrType[5];		/* �Զ˺������� */
	int     iOppCarrID;		/* �Զ���Ӫ�� */
	char    sOppArea[6];		/* �Զ���Ӫ�̵����� */
	char    sOppProv[6];		/* �Զ���Ӫ�̹���ʡ */
	char    sBillingTypeID[21];		/* �����ײ�ID */
	char    sReserve1[11];		/* ����ά��1 */
	char    sReserve2[11];		/* ����ά��2 */
	char    sReserve3[11];		/* ����ά��3 */
	char    sSettItemDate[9];		/* �������� */
	char    sBillingCycleID[7];		/* �������� */
	struct SettNbrStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettNbrStatStruct{

	char    sAccNbr[20];		/* ������� */
	char    sHomeAreaCode[5];		/* ��������� */
	char    sProvCode[5];		/* �������ʡ */
	char    sVisitAreaCode[5];		/* ��������� */
	char    sNetType[4];		/* ����רҵ */
	char    sTicketTypeID[4];		/* �������� */
	char    sCnt[9];		/* ������ */
	char    sDuration[9];		/* ͨ��ʱ�� */
	char    sSettMin[9];		/* ��������� */
	char    sInFee[12];		/* �������� */
	char    sOutFee[12];		/* ����֧�� */
	char    sServiceType[3];		/* ҵ������ */
	char    sNbrType[4];		/* ���˺������� */
	char    sOppNbrType[4];		/* �Զ˺������� */
	char    sOppCarrID[4];		/* �Զ���Ӫ�� */
	char    sOppArea[5];		/* �Զ���Ӫ�̵����� */
	char    sOppProv[5];		/* �Զ���Ӫ�̹���ʡ */
	char    sBillingTypeID[20];		/* �����ײ�ID */
	char    sReserve1[10];		/* ����ά��1 */
	char    sReserve2[10];		/* ����ά��2 */
	char    sReserve3[10];		/* ����ά��3 */
	char    sSettItemDate[8];		/* �������� */
	char    sBillingCycleID[6];		/* �������� */
};


/*�������ݶ�̬��SETT_NBR_STAT���ýṹ���巽ʽȡ����*/
int EGetSettNbrStatToStruct(struct SettNbrStatStruct *p,
	struct SettNbrStatStructIn *pSource);
void mvitem_settnbrstat(struct SettNbrStatStruct *pi,struct SettNbrStatStruct *po);
void mvitem_mfsettnbrstat(struct SettNbrStatStruct *pi,struct FSettNbrStatStruct *po);
void mvitem_fmsettnbrstat(struct FSettNbrStatStruct *pi,struct SettNbrStatStruct *po);

/*�������ݽṹ����д��SETT_NBR_STAT*/
int EInsertStructToSettNbrStat(struct SettNbrStatStruct *p,
	int iInsertFlag,struct SettNbrStatStructOut *pTarget);


int data_search_bintree_settnbrstat_e(void *pValue,void*pData);
void assign_insert_bintree_settnbrstat_e(void **ppData,void *pData);

void GetNbrType(char sAccNbr[],
	int iCarrierID,char sAreaCode[],char sOutNbrType[]);
void GetProvCode(char sAreaCode[],char sVisitAreaCode[],char sOutsProvCode[]);
int GetSttRes(char sAccNbr[],char sRawNbr[],
	char sAreaCode[],char sStartTime[],char sRes[]);
/*void ModifySttTicket(struct SttTicketStruct *pi);

int STT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int VIT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int TLR_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);	
int TLL_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int STP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int TLP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int SMS_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int SCX_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
*/


/*����ṹ��������*/
struct SettNbrStatLogStructOut{

#ifndef SETT_NBR_STAT_LOG_BUFLEN_OUT
#define SETT_NBR_STAT_LOG_BUFLEN_OUT		300
#endif

	struct SettNbrStatLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];

	char    asSourceTable[SETT_NBR_STAT_LOG_BUFLEN_OUT][31];
	char    asTargetTable[SETT_NBR_STAT_LOG_BUFLEN_OUT][31];
	char    asSettDate[SETT_NBR_STAT_LOG_BUFLEN_OUT][14];
	char	asServiceType[SETT_NBR_STAT_LOG_BUFLEN_OUT][9];
	char	asStatType[SETT_NBR_STAT_LOG_BUFLEN_OUT][9];
	int	aiGroupID[SETT_NBR_STAT_LOG_BUFLEN_OUT];
	char    asState[SETT_NBR_STAT_LOG_BUFLEN_OUT][2];
	char	asDealDate[SETT_NBR_STAT_LOG_BUFLEN_OUT][15];
};


/* ����ṹ��������*/
struct SettNbrStatLogStructIn{

#ifndef SETT_NBR_STAT_LOG_BUFLEN_IN
#define SETT_NBR_STAT_LOG_BUFLEN_IN		300
#endif

	struct SettNbrStatLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];

	char    asSourceTable[SETT_NBR_STAT_LOG_BUFLEN_IN][31];
	char    asTargetTable[SETT_NBR_STAT_LOG_BUFLEN_IN][31];
	char    asSettDate[SETT_NBR_STAT_LOG_BUFLEN_IN][14];
	char	asServiceType[SETT_NBR_STAT_LOG_BUFLEN_IN][9];
	char	asStatType[SETT_NBR_STAT_LOG_BUFLEN_IN][9];
	int	aiGroupID[SETT_NBR_STAT_LOG_BUFLEN_IN];
	char    asState[SETT_NBR_STAT_LOG_BUFLEN_IN][2];
	char	asDealDate[SETT_NBR_STAT_LOG_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SettNbrStatLogStruct{

	struct SettNbrStatLogStruct *pNext;
	char    sSourceTable[31];
	char    sTargetTable[31];
	char    sSettDate[15];
	char	sServiceType[9];
	char	sStatType[9];
	int	iGroupID;
	char    sState[2];
	char	sDealDate[15];
	struct SettNbrStatLogStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettNbrStatLogStruct{

	char    sSourceTable[30];
	char    sTargetTable[30];
	char    sSettDate[14];
	char	sServiceType[8];
	char	sStatType[8];
	char	sGroupID[8];
	char    sState[1];
	char	sDealDate[14];
};
int SDInsertStructToSettNbrStatLog(struct SettNbrStatLogStruct *p,char sTableName[]);
int SDGetSettNbrStatToStruct(struct SettNbrStatLogStruct *p,char sTableName[],char sCondition[]);
/*************2016.01.29**************/
int IsInNBR(char sMsisdn[]);


#endif

