#ifndef __STT_TICKET_H__
#define __STT_TICKET_H__

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <bintree.h>
#include <wwfile.h>
#include <ticket.h>

int InsertTicket(char sFileName[],char sTableName[],char sType[]);

int SttTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmscTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmspTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int GprsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int NsmsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int PrepTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int Cdma1xTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*����ṹ��������*/
struct PrepTicketStructOut{

#ifndef PREP_TICKET_BUFLEN_OUT
#define PREP_TICKET_BUFLEN_OUT		300
#endif

	struct PrepTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asCallType[PREP_TICKET_BUFLEN_OUT][3];
		/* IMSI */
	char    asImsi[PREP_TICKET_BUFLEN_OUT][16];
		/* �û����� */
	char    asMsisdn[PREP_TICKET_BUFLEN_OUT][16];
		/* �Զ˺��� */
	char    asOtherParty[PREP_TICKET_BUFLEN_OUT][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[PREP_TICKET_BUFLEN_OUT][15];
		/* ʱ�� */
	char    asDuration[PREP_TICKET_BUFLEN_OUT][7];
		/* MSC */
	char    asMsc[PREP_TICKET_BUFLEN_OUT][11];
		/* ���м� */
	char    asTrunkIn[PREP_TICKET_BUFLEN_OUT][9];
		/* ���м� */
	char    asTrunkOut[PREP_TICKET_BUFLEN_OUT][9];
		/* LAC */
	char    asLac[PREP_TICKET_BUFLEN_OUT][5];
		/* CELL_ID */
	char    asCellID[PREP_TICKET_BUFLEN_OUT][5];
		/* �Զ�LAC */
	char    asOtherLac[PREP_TICKET_BUFLEN_OUT][5];
		/* �Զ�CELL_ID */
	char    asOtherCellID[PREP_TICKET_BUFLEN_OUT][5];
		/* ҵ������ */
	char    asServiceType[PREP_TICKET_BUFLEN_OUT][4];
		/* ҵ����� */
	char    asServiceCode[PREP_TICKET_BUFLEN_OUT][5];
		/* ���������� */
	char    asThirdParty[PREP_TICKET_BUFLEN_OUT][16];
		/* MSRN */
	char    asMsrn[PREP_TICKET_BUFLEN_OUT][13];
	
		/* �û����� */
	char    asUserType[PREP_TICKET_BUFLEN_OUT][2];
		/* ����1 */
	char    asReserve1[PREP_TICKET_BUFLEN_OUT][3];

		/* ���Ӵ��� */
	char    asEsn[PREP_TICKET_BUFLEN_OUT][16];

/*�����ϲ���Ҫ���ֶ�*/	
	char    asScpFlag[PREP_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[PREP_TICKET_BUFLEN_OUT][2];
	
	char	asReserve[PREP_TICKET_BUFLEN_OUT][9];
	char	asErrCode[PREP_TICKET_BUFLEN_OUT][5];
	char	asFileName[PREP_TICKET_BUFLEN_OUT][20];
	char	asModule[PREP_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[PREP_TICKET_BUFLEN_OUT][6];
	char	asState[PREP_TICKET_BUFLEN_OUT][2];
		/* �������� */
	char    asUpdateDate[PREP_TICKET_BUFLEN_OUT][15];
	char    asDealDate[PREP_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[PREP_TICKET_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct PrepTicketStructIn{

#ifndef PREP_TICKET_BUFLEN_IN
#define PREP_TICKET_BUFLEN_IN		300
#endif

	struct PrepTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asCallType[PREP_TICKET_BUFLEN_IN][3];
		/* IMSI */
	char    asImsi[PREP_TICKET_BUFLEN_IN][16];
		/* �û����� */
	char    asMsisdn[PREP_TICKET_BUFLEN_IN][16];
		/* �Զ˺��� */
	char    asOtherParty[PREP_TICKET_BUFLEN_IN][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[PREP_TICKET_BUFLEN_IN][15];
		/* ʱ�� */
	char    asDuration[PREP_TICKET_BUFLEN_IN][7];
		/* MSC */
	char    asMsc[PREP_TICKET_BUFLEN_IN][11];
		/* ���м� */
	char    asTrunkIn[PREP_TICKET_BUFLEN_IN][9];
		/* ���м� */
	char    asTrunkOut[PREP_TICKET_BUFLEN_IN][9];
		/* LAC */
	char    asLac[PREP_TICKET_BUFLEN_IN][5];
		/* CELL_ID */
	char    asCellID[PREP_TICKET_BUFLEN_IN][5];
		/* �Զ�LAC */
	char    asOtherLac[PREP_TICKET_BUFLEN_IN][5];
		/* �Զ�CELL_ID */
	char    asOtherCellID[PREP_TICKET_BUFLEN_IN][5];
		/* ҵ������ */
	char    asServiceType[PREP_TICKET_BUFLEN_IN][4];
		/* ҵ����� */
	char    asServiceCode[PREP_TICKET_BUFLEN_IN][5];
		/* ���������� */
	char    asThirdParty[PREP_TICKET_BUFLEN_IN][16];
		/* MSRN */
	char    asMsrn[PREP_TICKET_BUFLEN_IN][13];
	
		/* �û����� */
	char    asUserType[PREP_TICKET_BUFLEN_IN][2];
		/* ����1 */
	char    asReserve1[PREP_TICKET_BUFLEN_IN][3];
		/* ���Ӵ��� */
	char    asEsn[PREP_TICKET_BUFLEN_IN][16];
/*�����ϲ���Ҫ���ֶ�*/	
	char    asScpFlag[PREP_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[PREP_TICKET_BUFLEN_IN][2];
	
	char	asReserve[PREP_TICKET_BUFLEN_IN][9];
	char	asErrCode[PREP_TICKET_BUFLEN_IN][5];
	char	asFileName[PREP_TICKET_BUFLEN_IN][20];
	char	asModule[PREP_TICKET_BUFLEN_IN][4];
	char	asAreaCode[PREP_TICKET_BUFLEN_IN][6];
	char	asState[PREP_TICKET_BUFLEN_IN][2];
		/* �������� */
	char    asUpdateDate[PREP_TICKET_BUFLEN_IN][15];
	char    asDealDate[PREP_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[PREP_TICKET_BUFLEN_IN][41];
	char	asRowID[PREP_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct PrepTicketStruct{

	struct PrepTicketStruct *pNext;
	char    sCallType[3];		/* �������� */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* �û����� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	char    sDuration[7];		/* ʱ�� */
	char    sMsc[11];		/* MSC */
	char    sTrunkIn[9];		/* ���м� */
	char    sTrunkOut[9];		/* ���м� */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* �Զ�LAC */
	char    sOtherCellID[5];		/* �Զ�CELL_ID */
	char    sServiceType[4];		/* ҵ������ */
	char    sServiceCode[5];		/* ҵ����� */
	char    sThirdParty[16];		/* ���������� */
	char    sMsrn[13];		/* MSRN */
	char    sUserType[2];		/* MSRN */
	char    sReserve1[3];		/* MSRN */
	char    sEsn[16];		/* ���Ӵ��� */
	char	sScpFlag[2];
	char	sDeformFlag[2];
	char	sReserve[9];
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sDealDate[15];		/* �������� */
	char	sUpdateDate[15];
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct PrepTicketStruct *pLoadNext;
};


/*�������ݶ�̬��PREP_TICKET���ýṹ���巽ʽȡ����*/
int EInsertStructToPrepTicket(struct PrepTicketStruct *p,
	int iInsertFlag,struct PrepTicketStructOut *pTarget);
int InsertPrepTicket(char sFileName[],char sTableName[]);
void mvitem_fmprepticket(struct FPrepTicketStruct *pi,int len,
	struct PrepTicketStruct *po);
int EGetPrepTicketToStruct(struct PrepTicketStruct *p,
	struct PrepTicketStructIn *pSource);
void mvitem_mfprepticket(struct PrepTicketStruct *pi,struct FPrepTicketStruct *po);

/*����ṹ��������*/
struct SttTicketStructOut{

#ifndef STT_TICKET_BUFLEN_OUT
#define STT_TICKET_BUFLEN_OUT		300
#endif

	struct SttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������� */
	int     aiTicketTypeID[STT_TICKET_BUFLEN_OUT];
		/* ������� */
	char    asCallType[STT_TICKET_BUFLEN_OUT][3];
		/* �û����� */
	char    asMsisdn[STT_TICKET_BUFLEN_OUT][16];
		/* �Զ����� */
	char    asCalledCode[STT_TICKET_BUFLEN_OUT][6];
		/* �Զ˺��� */
	char    asOtherParty[STT_TICKET_BUFLEN_OUT][25];
		/* ������������� */
	char    asVisitAreaCode[STT_TICKET_BUFLEN_OUT][6];
		/* ����ͨ���� */
	int     aiRoamFee[STT_TICKET_BUFLEN_OUT];
		/* ��;�� */
	int     aiTollFee[STT_TICKET_BUFLEN_OUT];
		/* ������ */
	int     aiAddFee[STT_TICKET_BUFLEN_OUT];
		/* ʱ�� */
	int     aiDuration[STT_TICKET_BUFLEN_OUT];
		/* ͨ����ʼʱ�� */
	char    asStartTime[STT_TICKET_BUFLEN_OUT][15];
		/* �û������� */
	char    asHomeAreaCode[STT_TICKET_BUFLEN_OUT][6];
		/* ������� */
	char    asRoamType[STT_TICKET_BUFLEN_OUT][2];
		/* λ����� */
	char    asDistanceType[STT_TICKET_BUFLEN_OUT][2];
		/* �Զ���� */
	char    asOppType[STT_TICKET_BUFLEN_OUT][2];
		/* �û���� */
	char    asUserType[STT_TICKET_BUFLEN_OUT][2];
		/* ���������ʶ */
	char    asSplitRuleID[STT_TICKET_BUFLEN_OUT][5];
		/* �Զ�������� */
	char    asOppRoamType[STT_TICKET_BUFLEN_OUT][2];
		/* ҵ������ */
	char    asServiceType[STT_TICKET_BUFLEN_OUT][4];
		/* ҵ����� */
	char    asServiceCode[STT_TICKET_BUFLEN_OUT][5];
		/* �û�IMSI */
	char    asImsi[STT_TICKET_BUFLEN_OUT][16];
		/* ��������ʶ */
	char    asMsc[STT_TICKET_BUFLEN_OUT][16];
		/* С���� */
	char    asLac[STT_TICKET_BUFLEN_OUT][6];
		/* ���Ѻ� */
	char    asCellID[STT_TICKET_BUFLEN_OUT][6];
	
		/* С���� */
	char    asOtherLac[STT_TICKET_BUFLEN_OUT][6];
		/* ���Ѻ� */
	char    asOtherCellID[STT_TICKET_BUFLEN_OUT][6];
	
		/* ���м� */
	char    asTrunkIn[STT_TICKET_BUFLEN_OUT][8];
		/* ���м� */
	char    asTrunkOut[STT_TICKET_BUFLEN_OUT][8];
		/* ���������� */
	char    asThirdParty[STT_TICKET_BUFLEN_OUT][16];
		/* ��̬���κ� */
	char    asMsrn[STT_TICKET_BUFLEN_OUT][13];
		/* ���м���� */
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_OUT];
		/* ���м���� */
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_OUT];
		/* ���м���Ӫ�� */
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_OUT];
		/* ���м���Ӫ�� */
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_OUT];
		/* ���м̳�;���ͱ�ʶ */
	char    asTrunkInType[STT_TICKET_BUFLEN_OUT][2];
		/* ���м̳�;���ͱ�ʶ */
	char    asTrunkOutType[STT_TICKET_BUFLEN_OUT][2];
		/* ���к�ͷ��Ӫ�� */
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_OUT];
		/* ���к�ͷ��Ӫ�� */
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_OUT];
		/* �������ͱ�ʶ */
	int     aiCallingTypeID[STT_TICKET_BUFLEN_OUT];
		/* �������ͱ�ʶ */
	int     aiCalledTypeID[STT_TICKET_BUFLEN_OUT];
		/* �������� */
		
	int     aiCallingAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledAreaID[STT_TICKET_BUFLEN_OUT];
	char    asSplitType[STT_TICKET_BUFLEN_OUT][2];
	char    asCal[STT_TICKET_BUFLEN_OUT][2];
	char    asEsn[STT_TICKET_BUFLEN_OUT][16];
/*�����ϲ���Ҫ���ֶ�*/	
	char    asScpFlag[STT_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_OUT][2];
	
	char	asReserve[STT_TICKET_BUFLEN_OUT][9];
	char	asBillMode[STT_TICKET_BUFLEN_OUT][4];
	
	char	asReserve1[STT_TICKET_BUFLEN_OUT][3];
	char	asRoamTariffType[STT_TICKET_BUFLEN_OUT][4];
	char	asTollTariffType[STT_TICKET_BUFLEN_OUT][4];
	char	asAddTariffType[STT_TICKET_BUFLEN_OUT][4];

	char	asErrCode[STT_TICKET_BUFLEN_OUT][5];
	char	asFileName[STT_TICKET_BUFLEN_OUT][20];
	char	asModule[STT_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[STT_TICKET_BUFLEN_OUT][6];
	
	char    asState[STT_TICKET_BUFLEN_OUT][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_OUT][15];

	char    asDealDate[STT_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[STT_TICKET_BUFLEN_OUT][41];
};

/* ����ṹ��������*/
struct SttTicketStructIn{

#ifndef STT_TICKET_BUFLEN_IN
#define STT_TICKET_BUFLEN_IN		300
#endif

	struct SttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ������� */
	int     aiTicketTypeID[STT_TICKET_BUFLEN_IN];
		/* ������� */
	char    asCallType[STT_TICKET_BUFLEN_IN][3];
		/* �û����� */
	char    asMsisdn[STT_TICKET_BUFLEN_IN][16];
		/* �Զ����� */
	char    asCalledCode[STT_TICKET_BUFLEN_IN][6];
		/* �Զ˺��� */
	char    asOtherParty[STT_TICKET_BUFLEN_IN][25];
		/* ������������� */
	char    asVisitAreaCode[STT_TICKET_BUFLEN_IN][6];
		/* ����ͨ���� */
	int     aiRoamFee[STT_TICKET_BUFLEN_IN];
		/* ��;�� */
	int     aiTollFee[STT_TICKET_BUFLEN_IN];
		/* ������ */
	int     aiAddFee[STT_TICKET_BUFLEN_IN];
		/* ʱ�� */
	int     aiDuration[STT_TICKET_BUFLEN_IN];
		/* ͨ����ʼʱ�� */
	char    asStartTime[STT_TICKET_BUFLEN_IN][15];
		/* �û������� */
	char    asHomeAreaCode[STT_TICKET_BUFLEN_IN][6];
		/* ������� */
	char    asRoamType[STT_TICKET_BUFLEN_IN][2];
		/* λ����� */
	char    asDistanceType[STT_TICKET_BUFLEN_IN][2];
		/* �Զ���� */
	char    asOppType[STT_TICKET_BUFLEN_IN][2];
		/* �û���� */
	char    asUserType[STT_TICKET_BUFLEN_IN][2];
		/* ���������ʶ */
	char    asSplitRuleID[STT_TICKET_BUFLEN_IN][5];
		/* �Զ�������� */
	char    asOppRoamType[STT_TICKET_BUFLEN_IN][2];
		/* ҵ������ */
	char    asServiceType[STT_TICKET_BUFLEN_IN][4];
		/* ҵ����� */
	char    asServiceCode[STT_TICKET_BUFLEN_IN][5];
		/* �û�IMSI */
	char    asImsi[STT_TICKET_BUFLEN_IN][16];
		/* ��������ʶ */
	char    asMsc[STT_TICKET_BUFLEN_IN][16];
		/* С���� */
	char    asLac[STT_TICKET_BUFLEN_IN][6];
		/* ���Ѻ� */
	char    asCellID[STT_TICKET_BUFLEN_IN][6];
		/* �Զ�LAC */
	char    asOtherLac[STT_TICKET_BUFLEN_IN][6];
		/* �Զ�CELLID */
	char    asOtherCellID[STT_TICKET_BUFLEN_IN][6];
		/* ���м� */
	char    asTrunkIn[STT_TICKET_BUFLEN_IN][8];
		/* ���м� */
	char    asTrunkOut[STT_TICKET_BUFLEN_IN][8];
		/* ���������� */
	char    asThirdParty[STT_TICKET_BUFLEN_IN][16];
		/* ��̬���κ� */
	char    asMsrn[STT_TICKET_BUFLEN_IN][13];
		/* ���м���� */
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_IN];
		/* ���м���� */
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_IN];
		/* ���м���Ӫ�� */
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_IN];
		/* ���м���Ӫ�� */
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_IN];
		/* ���м̳�;���ͱ�ʶ */
	char    asTrunkInType[STT_TICKET_BUFLEN_IN][2];
		/* ���м̳�;���ͱ�ʶ */
	char    asTrunkOutType[STT_TICKET_BUFLEN_IN][2];
		/* ���к�ͷ��Ӫ�� */
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_IN];
		/* ���к�ͷ��Ӫ�� */
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_IN];
		/* �������ͱ�ʶ */
	int     aiCallingTypeID[STT_TICKET_BUFLEN_IN];
		/* �������ͱ�ʶ */
	int     aiCalledTypeID[STT_TICKET_BUFLEN_IN];
		/* ����Ӫҵ����ʶ */
	int     aiCallingAreaID[STT_TICKET_BUFLEN_IN];
		/* ����Ӫҵ����ʶ */
	int     aiCalledAreaID[STT_TICKET_BUFLEN_IN];
		/* �������� */
	char    asSplitType[STT_TICKET_BUFLEN_IN][2];
	char    asCal[STT_TICKET_BUFLEN_IN][2];
	char    asEsn[STT_TICKET_BUFLEN_IN][16];
	
	char    asScpFlag[STT_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_IN][2];
	
	char	asReserve[STT_TICKET_BUFLEN_IN][9];
	char	asBillMode[STT_TICKET_BUFLEN_IN][4];
	
	char	asReserve1[STT_TICKET_BUFLEN_IN][3];
	char	asRoamTariffType[STT_TICKET_BUFLEN_IN][4];
	char	asTollTariffType[STT_TICKET_BUFLEN_IN][4];
	char	asAddTariffType[STT_TICKET_BUFLEN_IN][4];

	char	asErrCode[STT_TICKET_BUFLEN_IN][5];
	char	asFileName[STT_TICKET_BUFLEN_IN][20];
	char	asModule[STT_TICKET_BUFLEN_IN][4];
	char	asAreaCode[STT_TICKET_BUFLEN_IN][6];

	char    asState[STT_TICKET_BUFLEN_IN][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_IN][15];
		/* �������� */
	char    asDealDate[STT_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[STT_TICKET_BUFLEN_IN][41];
	char	asRowID[STT_TICKET_BUFLEN_IN][19];
};
/*�����ṹ����*/
struct SttTicketStruct{

	struct SttTicketStruct *pNext;
	int     iTicketTypeID;		/* ������� */
	char    sCallType[3];		/* ������� */
	char    sMsisdn[16];		/* �û����� */
	char    sCalledCode[6];		/* �Զ����� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sVisitAreaCode[6];		/* ������������� */
	int     iRoamFee;		/* ����ͨ���� */
	int     iTollFee;		/* ��;�� */
	int     iAddFee;		/* ������ */
	int     iDuration;		/* ʱ�� */
	char    sStartTime[15];		/* ͨ����ʼʱ�� */
	char    sHomeAreaCode[6];		/* �û������� */
	char    sRoamType[2];		/* ������� */
	char    sDistanceType[2];		/* λ����� */
	char    sOppType[2];		/* �Զ���� */
	char    sUserType[2];		/* �û���� */
	char    sSplitRuleID[5];		/* ���������ʶ */
	char    sOppRoamType[2];		/* �Զ�������� */
	char    sServiceType[4];		/* ҵ������ */
	char    sServiceCode[5];		/* ҵ����� */
	char    sImsi[16];		/* �û�IMSI */
	char    sMsc[16];		/* ��������ʶ */
	char    sLac[6];		/* С���� */
	char    sCellID[6];		/* ���Ѻ� */
	
	char    sOtherLac[6];		/* С���� */
	char    sOtherCellID[6];	/* ���Ѻ� */
	
	char    sTrunkIn[8];		/* ���м� */
	char    sTrunkOut[8];		/* ���м� */
	char    sThirdParty[16];		/* ���������� */
	char    sMsrn[13];		/* ��̬���κ� */
	int     iTrunkInTypeID;		/* ���м���� */
	int     iTrunkOutTypeID;		/* ���м���� */
	int     iTrunkInCarrierID;		/* ���м���Ӫ�� */
	int     iTrunkOutCarrierID;		/* ���м���Ӫ�� */
	char    sTrunkInType[2];		/* ���м̳�;���ͱ�ʶ */
	char    sTrunkOutType[2];		/* ���м̳�;���ͱ�ʶ */
	int     iCallingCarrierID;		/* ���к�ͷ��Ӫ�� */
	int     iCalledCarrierID;		/* ���к�ͷ��Ӫ�� */
	int     iCallingTypeID;		/* �������ͱ�ʶ */
	int     iCalledTypeID;		/* �������ͱ�ʶ */
	int	iCallingAreaID;
	int	iCalledAreaID;
	char	sSplitType[2];
	char	sCal[2];
	char	sEsn[16];
	char	sScpFlag[2];
	char	sDeformFlag[2];

	char	sReserve[9];
	char	sBillMode[4];
	
	char	sReserve1[3];
	char	sRoamTariffType[4];
	char	sTollTariffType[4];
	char	sAddTariffType[4];

	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];

	char	sState[2];
	char	sUpdateDate[15];
	char    sDealDate[15];		/* �������� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct SttTicketStruct *pLoadNext;
};

int EInsertStructToSttTicket(struct SttTicketStruct *p,
        int iInsertFlag,struct SttTicketStructOut *pTarget);
int InsertSttTicket(char sFileName[],char sTableName[]);
void mvitem_fmsttticket(struct FSttTicketStruct *pi,int len,
	struct SttTicketStruct *po);
/*�������ݶ�̬��STT_TICKET���ýṹ���巽ʽȡ����*/
int EGetSttTicketToStruct(struct SttTicketStruct *p,
	struct SttTicketStructIn *pSource);
void mvitem_mfsttticket(struct SttTicketStruct *pi,struct FSttTicketStruct *po);

/*�����ṹ����*/
struct RSttTicketStruct{

	struct RSttTicketStruct *pNext;
	char    sCallType[3];		/* CALL_TYPE */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* �û����� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	char    sDuration[7];		/* ʱ�� */
	char    sMsrn[13];		/* MSRN */
	char    sMsc[11];		/* MSC */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* �Զ�LAC */
	char    sOtherCellID[5];		/* �Զ�CELL_ID */
	char    sTrunkIn[9];		/* ���м� */
	char    sTrunkOut[9];		/* ���м� */
	char    sServiceType[4];		/* ҵ������ */
	char    sServiceCode[5];		/* ҵ����� */
	char    sThirdParty[16];		/* ���������� */
	int     iTicketTypeID;		/* �������� */
	int     iRoamFee;		/* ���η� */
	int     iTollFee;		/* ��;�� */
	int     iAddFee;		/* ������ */
	char    sHomeAreaCode[6];		/* �û��������� */
	char    sVisitAreaCode[6];		/* �û��ݷ����� */
	char    sCalledCode[6];		/* �Զ����� */
	char    sRoamType[2];		/* �������� */
	char    sDistanceType[2];		/* ��;���� */
	int     iTrunkInTypeID;		/* ���м����� */
	int     iTrunkOutTypeID;		/* ���м����� */
	int     iTrunkInCarrierID;		/* ���м���Ӫ�� */
	int     iTrunkOutCarrierID;		/* ���м���Ӫ�� */
	int     iCallingTypeID;		/* �������ͱ�ʶ */
	int     iCalledTypeID;		/* �������ͱ�ʶ */
	int     iCallingCarrierID;		/* ���к�ͷ��Ӫ�� */
	int     iCalledCarrierID;		/* ���к�ͷ��Ӫ�� */
	int     iCallingAreaID;		/* ���е�����ʶ */
	int     iCalledAreaID;		/* ���е�����ʶ */
	char    sSplitRuleID[5];		/* ��������ʶ */
	char	sBillMode[4];
	char	sSplitType[2];		/*�������*/
	char	sEsn[16];
	char	sOppType[2];
	char	sUserType[2];
	char	sTrunkInType[2];
	char	sTrunkOutType[2];
	char	sCal[2];
	char	sScpFlag[2];
	char	sDeformFlag[2];
	char	sReserve[9];

	char	sReserve1[3];
	char	sRoamTariffType[4];
	char	sTollTariffType[4];
	char	sAddTariffType[4];

	char	sSourceID[41];
	char    sRowID[19];		/* ��¼���� */
	struct RSttTicketStruct *pLoadNext;
};

/* ����ṹ��������*/
struct RSttTicketStructIn{

#ifndef R_STT_TICKET_BUFLEN_IN
#define R_STT_TICKET_BUFLEN_IN		300
#endif

	struct RSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* CALL_TYPE */
	char    asCallType[R_STT_TICKET_BUFLEN_IN][3];
		/* IMSI */
	char    asImsi[R_STT_TICKET_BUFLEN_IN][16];
		/* �û����� */
	char    asMsisdn[R_STT_TICKET_BUFLEN_IN][16];
		/* �Զ˺��� */
	char    asOtherParty[R_STT_TICKET_BUFLEN_IN][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[R_STT_TICKET_BUFLEN_IN][15];
		/* ʱ�� */
	char    asDuration[R_STT_TICKET_BUFLEN_IN][7];
		/* MSRN */
	char    asMsrn[R_STT_TICKET_BUFLEN_IN][13];
		/* MSC */
	char    asMsc[R_STT_TICKET_BUFLEN_IN][11];
		/* LAC */
	char    asLac[R_STT_TICKET_BUFLEN_IN][5];
		/* CELL_ID */
	char    asCellID[R_STT_TICKET_BUFLEN_IN][5];
		/* �Զ�LAC */
	char    asOtherLac[R_STT_TICKET_BUFLEN_IN][5];
		/* �Զ�CELL_ID */
	char    asOtherCellID[R_STT_TICKET_BUFLEN_IN][5];
		/* ���м� */
	char    asTrunkIn[R_STT_TICKET_BUFLEN_IN][9];
		/* ���м� */
	char    asTrunkOut[R_STT_TICKET_BUFLEN_IN][9];
		/* ҵ������ */
	char    asServiceType[R_STT_TICKET_BUFLEN_IN][4];
		/* ҵ����� */
	char    asServiceCode[R_STT_TICKET_BUFLEN_IN][5];
		/* ���������� */
	char    asThirdParty[R_STT_TICKET_BUFLEN_IN][16];
		/* �������� */
	int     aiTicketTypeID[R_STT_TICKET_BUFLEN_IN];
		/* ���η� */
	int     aiRoamFee[R_STT_TICKET_BUFLEN_IN];
		/* ��;�� */
	int     aiTollFee[R_STT_TICKET_BUFLEN_IN];
		/* ������ */
	int     aiAddFee[R_STT_TICKET_BUFLEN_IN];
		/* �û��������� */
	char    asHomeAreaCode[R_STT_TICKET_BUFLEN_IN][6];
		/* �û��ݷ����� */
	char    asVisitAreaCode[R_STT_TICKET_BUFLEN_IN][6];
		/* �Զ����� */
	char    asCalledCode[R_STT_TICKET_BUFLEN_IN][6];
		/* �������� */
	char    asRoamType[R_STT_TICKET_BUFLEN_IN][2];
		/* ��;���� */
	char    asDistanceType[R_STT_TICKET_BUFLEN_IN][2];
		/* ���м����� */
	int     aiTrunkInTypeID[R_STT_TICKET_BUFLEN_IN];
		/* ���м����� */
	int     aiTrunkOutTypeID[R_STT_TICKET_BUFLEN_IN];
		/* ���м���Ӫ�� */
	int     aiTrunkInCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* ���м���Ӫ�� */
	int     aiTrunkOutCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* �������ͱ�ʶ */
	int     aiCallingTypeID[R_STT_TICKET_BUFLEN_IN];
		/* �������ͱ�ʶ */
	int     aiCalledTypeID[R_STT_TICKET_BUFLEN_IN];
		/* ���к�ͷ��Ӫ�� */
	int     aiCallingCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* ���к�ͷ��Ӫ�� */
	int     aiCalledCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* ���е�����ʶ */
	int     aiCallingAreaID[R_STT_TICKET_BUFLEN_IN];
		/* ���е�����ʶ */
	int     aiCalledAreaID[R_STT_TICKET_BUFLEN_IN];
		/* ��������ʶ */
	char    asSplitRuleID[R_STT_TICKET_BUFLEN_IN][5];
	char	asBillMode[R_STT_TICKET_BUFLEN_IN][4];
	char	asSplitType[R_STT_TICKET_BUFLEN_IN][2];
	char	asEsn[R_STT_TICKET_BUFLEN_IN][16];
	char	asOppType[R_STT_TICKET_BUFLEN_IN][2];
	char	asUserType[R_STT_TICKET_BUFLEN_IN][2];
	char	asTrunkInType[R_STT_TICKET_BUFLEN_IN][2];
	char	asTrunkOutType[R_STT_TICKET_BUFLEN_IN][2];
	char	asCal[R_STT_TICKET_BUFLEN_IN][2];
	char	asScpFlag[R_STT_TICKET_BUFLEN_IN][2];
	char	asDeformFlag[R_STT_TICKET_BUFLEN_IN][2];
	char	asReserve[R_STT_TICKET_BUFLEN_IN][9];
	
	char	asReserve1[R_STT_TICKET_BUFLEN_IN][3];
	char	asRoamTariffType[R_STT_TICKET_BUFLEN_IN][4];
	char	asTollTariffType[R_STT_TICKET_BUFLEN_IN][4];
	char	asAddTariffType[R_STT_TICKET_BUFLEN_IN][4];

	char	asSourceID[R_STT_TICKET_BUFLEN_IN][41];
		/* ��¼���� */
	char    asRowID[R_STT_TICKET_BUFLEN_IN][19];
};


/*�����ݵ�ȡ��*/
/*�������ݶ�̬��R_STT_TICKET���ýṹ���巽ʽȡ����*/
int EGetRSttTicketToStruct(struct RSttTicketStruct *p,
	struct RSttTicketStructIn *pSource);
struct USttTicketStruct
{
	int	iTicketTypeID;
	int	iRoamFee;
	int	iTollFee;
	int	iAddFee;
	char	sHomeAreaCode[6];
	char	sVisitAreaCode[6];
	char	sCalledCode[6];
	char	sRoamType[2];
	char	sDistanceType[2];
	int	iTrunkInTypeID;
	int	iTrunkOutTypeID;
	int	iTrunkInCarrierID;
	int	iTrunkOutCarrierID;
	int	iCallingTypeID;
	int	iCalledTypeID;
	int	iCallingCarrierID;
	int	iCalledCarrierID;
	int	iCallingAreaID;
	int	iCalledAreaID;
	char	sSplitRuleID[5];
	char	sTrunkIn[8];
	char	sTrunkOut[8];
	char	sBillMode[4];
	char	sState[2];
	char	sRoamTariffType[4];
	char	sTollTariffType[4];
	char	sAddTariffType[4];
	char	sRowID[19];
	char	sMsisdn[16];
	char	sStartTime[15];
	int	iDuration;
	char	sMsrn[13];
	char	sCal[2];
	char	sUserType[2];
};
struct USttTicketStructUp
{
#ifndef STT_TICKET_BUFLEN_UP
#define STT_TICKET_BUFLEN_UP 	300
#endif
	int	iCurPos;
	char	sTableName[31];
	int	aiTicketTypeID[STT_TICKET_BUFLEN_UP];
	int	aiRoamFee[STT_TICKET_BUFLEN_UP];
	int	aiTollFee[STT_TICKET_BUFLEN_UP];
	int	aiAddFee[STT_TICKET_BUFLEN_UP];
	char	asHomeAreaCode[STT_TICKET_BUFLEN_UP][6];
	char	asVisitAreaCode[STT_TICKET_BUFLEN_UP][6];
	char	asCalledCode[STT_TICKET_BUFLEN_UP][6];
	char	asRoamType[STT_TICKET_BUFLEN_UP][2];
	char	asDistanceType[STT_TICKET_BUFLEN_UP][2];
	int	aiTrunkInTypeID[STT_TICKET_BUFLEN_UP];
	int	aiTrunkOutTypeID[STT_TICKET_BUFLEN_UP];
	int	aiTrunkInCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiTrunkOutCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiCallingTypeID[STT_TICKET_BUFLEN_UP];
	int	aiCalledTypeID[STT_TICKET_BUFLEN_UP];
	int	aiCallingCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiCalledCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiCallingAreaID[STT_TICKET_BUFLEN_UP];
	int	aiCalledAreaID[STT_TICKET_BUFLEN_UP];
	char	asSplitRuleID[STT_TICKET_BUFLEN_UP][5];
	char	asTrunkIn[STT_TICKET_BUFLEN_UP][8];
	char	asTrunkOut[STT_TICKET_BUFLEN_UP][8];
	char	asBillMode[STT_TICKET_BUFLEN_UP][4];
	char	asState[STT_TICKET_BUFLEN_UP][2];

	char	asRoamTariffType[STT_TICKET_BUFLEN_UP][4];
	char	asTollTariffType[STT_TICKET_BUFLEN_UP][4];
	char	asAddTariffType[STT_TICKET_BUFLEN_UP][4];

	char	asRowID[STT_TICKET_BUFLEN_UP][19];
	char	asMsisdn[STT_TICKET_BUFLEN_UP][16];
	char	asStartTime[STT_TICKET_BUFLEN_UP][15];
	int	aiDuration[STT_TICKET_BUFLEN_UP];
	char	asMsrn[STT_TICKET_BUFLEN_UP][13];
	char	asCal[STT_TICKET_BUFLEN_UP][2];		
	char	asUserType[STT_TICKET_BUFLEN_UP][2];
};
int EUpdateStructToUSttTicket(struct USttTicketStruct *p,
	int iUpdateFlag,struct USttTicketStructUp *pTarget);

/*�����ṹ����*/
struct UCommTicketStruct{

	struct UCommTicketStruct *pNext;
	char    sFileName[20];		/* �ļ��� */
	char    sModule[4];		/* ģ���� */
	char    sAreaCode[6];		/* ���� */
	char    sState[2];		/* ״̬ */
	char    sUpdateDate[15];		/* ����ʱ�� */
	char	sRowID[19];
	struct UCommTicketStruct *pLoadNext;
};
struct UCommTicketStructUp
{
#ifndef U_COMM_TICKET_BUFLEN_UP
#define U_COMM_TICKET_BUFLEN_UP 	300
#endif
	int	iCurPos;
	char	sTableName[31];
		/* �ļ��� */
	char    asFileName[U_COMM_TICKET_BUFLEN_UP][20];
		/* ģ���� */
	char    asModule[U_COMM_TICKET_BUFLEN_UP][4];
		/* ���� */
	char    asAreaCode[U_COMM_TICKET_BUFLEN_UP][6];
		/* ״̬ */
	char    asState[U_COMM_TICKET_BUFLEN_UP][2];
		/* ����ʱ�� */
	char    asUpdateDate[U_COMM_TICKET_BUFLEN_UP][15];
	char	asRowID[U_COMM_TICKET_BUFLEN_UP][19];
};
int EUpdateStructToUCommTicket(struct UCommTicketStruct *p,
	int iUpdateFlag,struct UCommTicketStructUp *pTarget);

/*******************************************/
struct UpTicketGStruct{
	struct UpTicketGStruct *pNext;
	char    sCallType[3];
	char    sMsisdn[25];
	char    sCalledCode[6];
	char    sOtherParty[25];
	char    sVisitAreaCode[6];
	int     iRoamFee;
	int     iTollFee;
	int     iAddFee;
	int     iDuration;
	char    sStartTime[15];
	char    sHomeAreaCode[6];
	char    sRoamType[2];
	char    sDistanceType[2];
	char    sUserType[2];
	char    sImsi[16];
	char    sMsrn[16];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sThirdParty[16];
	char    sServiceType[4];
	char    sServiceCode[5];
	char    sSupplementCode[16];
	char    sDealDate[15];
	char    sSourceID[21];
	char	sTrunkIn[9];
	char	sTrunkOut[9];
	char	sCityIn[4];
	char	sCityOut[4];
	char	sLandNetType[2];
};
/*����ṹ��������*/
struct UpTicketGStructOut{

#ifndef UP_TICKET_G_BUFLEN_OUT
#define UP_TICKET_G_BUFLEN_OUT		1000
#endif

	struct UpTicketGStructOut *pNext;
	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asCallType[UP_TICKET_G_BUFLEN_OUT][3];
	char    asMsisdn[UP_TICKET_G_BUFLEN_OUT][25];
	char    asCalledCode[UP_TICKET_G_BUFLEN_OUT][6];
	char    asOtherParty[UP_TICKET_G_BUFLEN_OUT][25];
	char    asVisitAreaCode[UP_TICKET_G_BUFLEN_OUT][6];
	int     aiRoamFee[UP_TICKET_G_BUFLEN_OUT];
	int     aiTollFee[UP_TICKET_G_BUFLEN_OUT];
	int     aiAddFee[UP_TICKET_G_BUFLEN_OUT];
	int     aiDuration[UP_TICKET_G_BUFLEN_OUT];
	char    asStartTime[UP_TICKET_G_BUFLEN_OUT][15];
	char    asHomeAreaCode[UP_TICKET_G_BUFLEN_OUT][6];
	char    asRoamType[UP_TICKET_G_BUFLEN_OUT][2];
	char    asDistanceType[UP_TICKET_G_BUFLEN_OUT][2];
	char    asUserType[UP_TICKET_G_BUFLEN_OUT][2];
	char    asImsi[UP_TICKET_G_BUFLEN_OUT][16];
	char    asMsrn[UP_TICKET_G_BUFLEN_OUT][16];
	char    asMsc[UP_TICKET_G_BUFLEN_OUT][16];
	char    asLac[UP_TICKET_G_BUFLEN_OUT][6];
	char    asCellID[UP_TICKET_G_BUFLEN_OUT][6];
	char    asThirdParty[UP_TICKET_G_BUFLEN_OUT][16];
	char    asServiceType[UP_TICKET_G_BUFLEN_OUT][4];
	char    asServiceCode[UP_TICKET_G_BUFLEN_OUT][5];
	char    asSupplementCode[UP_TICKET_G_BUFLEN_OUT][16];
	char    asDealDate[UP_TICKET_G_BUFLEN_OUT][15];
	char    asSourceID[UP_TICKET_G_BUFLEN_OUT][21];
	char	asTrunkIn[UP_TICKET_G_BUFLEN_OUT][9];
	char	asTrunkOut[UP_TICKET_G_BUFLEN_OUT][9];
	char	asCityIn[UP_TICKET_G_BUFLEN_OUT][4];
	char	asCityOut[UP_TICKET_G_BUFLEN_OUT][4];
	char	asLandNetType[UP_TICKET_G_BUFLEN_OUT][2];
};

int EInsertStructToUpTicketG(struct UpTicketGStruct *p,int iInsertFlag,
	struct UpTicketGStructOut *pTarget);
int InsertGsmTicket(char sFileName[],char sTableName[]);
int InsertCdmaTicket(char sFileName[],char sTableName[]);


/*����ṹ��������*/
struct T193TicketStructOut{

#ifndef T193_TICKET_BUFLEN_OUT
#define T193_TICKET_BUFLEN_OUT		300
#endif

	struct T193TicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* CALL_TYPE */
	char    asCallType[T193_TICKET_BUFLEN_OUT][3];
		/* �û����� */
	char    asMsisdn[T193_TICKET_BUFLEN_OUT][21];
		/* �Զ˺��� */
	char    asOtherParty[T193_TICKET_BUFLEN_OUT][21];
		/* Ӧ��ʱ�� */
	char    asStartTime[T193_TICKET_BUFLEN_OUT][15];
		/* ͨ��ʱ�� */
	char    asDuration[T193_TICKET_BUFLEN_OUT][7];
		/* MSC */
	char    asMsc[T193_TICKET_BUFLEN_OUT][11];
		/* ���м� */
	char    asTrunkIn[T193_TICKET_BUFLEN_OUT][9];
		/* ���м� */
	char    asTrunkOut[T193_TICKET_BUFLEN_OUT][9];
		/* �û����� */
	char    asCallingAreaCode[T193_TICKET_BUFLEN_OUT][6];
		/* �Զ����� */
	char    asCalledAreaCode[T193_TICKET_BUFLEN_OUT][6];
	
	char    asHomeAreaCode[T193_TICKET_BUFLEN_OUT][6];
		/* �ļ��������� */
	char    asDealDate[T193_TICKET_BUFLEN_OUT][15];
		/* �ļ��� */
	char    asSourceID[T193_TICKET_BUFLEN_OUT][41];
};

/*�����ṹ����*/
struct T193TicketStruct{

	struct T193TicketStruct *pNext;
	char    sCallType[3];		/* CALL_TYPE */
	char    sMsisdn[21];		/* �û����� */
	char    sOtherParty[21];		/* �Զ˺��� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	char    sDuration[7];		/* ͨ��ʱ�� */
	char    sMsc[11];		/* MSC */
	char    sTrunkIn[9];		/* ���м� */
	char    sTrunkOut[9];		/* ���м� */
	char    sCallingAreaCode[6];		/* �û����� */
	char    sCalledAreaCode[6];		/* �Զ����� */
	char	sHomeAreaCode[6];
	char    sDealDate[15];		/* �ļ��������� */
	char    sSourceID[41];		/* �ļ��� */
	struct T193TicketStruct *pLoadNext;
};



void mvitem_fmt193ticket(struct FT193TicketStruct *pi,struct T193TicketStruct *po);
int EInsertStructToT193Ticket(struct T193TicketStruct *p,
	int iInsertFlag,struct T193TicketStructOut *pTarget);
int Insert193Ticket(char sFileName[],char sTableName[]);


/*����ṹ��������*/
struct SmscTicketStructOut{

#ifndef SMSC_TICKET_BUFLEN_OUT
#define SMSC_TICKET_BUFLEN_OUT		300
#endif

	struct SmscTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asCallType[SMSC_TICKET_BUFLEN_OUT][3];
		/* ������д��� */
	char    asCityCode[SMSC_TICKET_BUFLEN_OUT][6];
		/* �û����� */
	char    asMsisdn[SMSC_TICKET_BUFLEN_OUT][16];
		/* �Զ˺��� */
	char    asOtherParty[SMSC_TICKET_BUFLEN_OUT][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[SMSC_TICKET_BUFLEN_OUT][15];
		/* �ֽ��� */
	char    asDuration[SMSC_TICKET_BUFLEN_OUT][7];
		/* �������� */
	char    asMsc[SMSC_TICKET_BUFLEN_OUT][16];
		/* �������� */
	char    asSmsp[SMSC_TICKET_BUFLEN_OUT][16];
		/* �û����� */
	char    asUserType[SMSC_TICKET_BUFLEN_OUT][2];
		/* ���� */
	char    asFee[SMSC_TICKET_BUFLEN_OUT][7];
		/* ҵ����� */
	char    asServiceCode[SMSC_TICKET_BUFLEN_OUT][5];
	
	int	aiTicketTypeID[SMSC_TICKET_BUFLEN_OUT];

	char	asErrCode[SMSC_TICKET_BUFLEN_OUT][5];
	char	asFileName[SMSC_TICKET_BUFLEN_OUT][20];
	char	asModule[SMSC_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[SMSC_TICKET_BUFLEN_OUT][6];
	char	asState[SMSC_TICKET_BUFLEN_OUT][2];
		/* �������� */
	char    asUpdateDate[SMSC_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMSC_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[SMSC_TICKET_BUFLEN_OUT][41];
};
/* ����ṹ��������*/
struct SmscTicketStructIn{

#ifndef SMSC_TICKET_BUFLEN_IN
#define SMSC_TICKET_BUFLEN_IN		300
#endif

	struct SmscTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asCallType[SMSC_TICKET_BUFLEN_IN][3];
	char    asCityCode[SMSC_TICKET_BUFLEN_IN][6];
	char    asMsisdn[SMSC_TICKET_BUFLEN_IN][16];
	char    asOtherParty[SMSC_TICKET_BUFLEN_IN][25];
	char    asStartTime[SMSC_TICKET_BUFLEN_IN][15];
	char    asDuration[SMSC_TICKET_BUFLEN_IN][7];
	char    asMsc[SMSC_TICKET_BUFLEN_IN][16];
	char    asSmsp[SMSC_TICKET_BUFLEN_IN][16];
	char    asUserType[SMSC_TICKET_BUFLEN_IN][2];
	char    asFee[SMSC_TICKET_BUFLEN_IN][7];
	char    asServiceCode[SMSC_TICKET_BUFLEN_IN][5];
	
	int	aiTicketTypeID[SMSC_TICKET_BUFLEN_IN];

	char	asErrCode[SMSC_TICKET_BUFLEN_IN][5];
	char	asFileName[SMSC_TICKET_BUFLEN_IN][20];
	char	asModule[SMSC_TICKET_BUFLEN_IN][4];
	char	asAreaCode[SMSC_TICKET_BUFLEN_IN][6];
	char	asState[SMSC_TICKET_BUFLEN_IN][2];

	char    asUpdateDate[SMSC_TICKET_BUFLEN_IN][15];
	char    asDealDate[SMSC_TICKET_BUFLEN_IN][15];
	char    asSourceID[SMSC_TICKET_BUFLEN_IN][41];
	char	asRowID[SMSC_TICKET_BUFLEN_IN][19];
	
};
/*�����ṹ����*/
struct SmscTicketStruct{

	struct SmscTicketStruct *pNext;
	char    sCallType[3];		/* �������� */
	char    sCityCode[6];		/* ������д��� */
	char    sMsisdn[16];		/* �û����� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	char    sDuration[7];		/* �ֽ��� */
	char    sMsc[16];		/* �������� */
	char    sSmsp[16];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sFee[7];		/* ���� */
	char    sServiceCode[5];		/* ҵ����� */
	int	iTicketTypeID;
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];		/* �������� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct SmscTicketStruct *pLoadNext;
};

int EInsertStructToSmscTicket(struct SmscTicketStruct *p,
	int iInsertFlag,struct SmscTicketStructOut *pTarget);
void mvitem_fmsmscticket(struct FSmscTicketStruct *pi,int len,
	struct SmscTicketStruct *po);
int InsertSmscTicket(char sFileName[],char sTableName[]);
/*�������ݶ�̬��SMSC_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmscTicketToStruct(struct SmscTicketStruct *p,
	struct SmscTicketStructIn *pSource);
void mvitem_mfsmscticket(struct SmscTicketStruct *pi,struct FSmscTicketStruct *po);

/*����ṹ��������*/
struct SmspTicketStructOut{

#ifndef SMSP_TICKET_BUFLEN_OUT
#define SMSP_TICKET_BUFLEN_OUT		300
#endif

	struct SmspTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asCallType[SMSP_TICKET_BUFLEN_OUT][3];
		/* ������д��� */
	char    asCityCode[SMSP_TICKET_BUFLEN_OUT][6];
		/* �û����� */
	char    asMsisdn[SMSP_TICKET_BUFLEN_OUT][16];
		/* �Զ˺��� */
	char    asOtherParty[SMSP_TICKET_BUFLEN_OUT][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[SMSP_TICKET_BUFLEN_OUT][15];
		/* �ֽ��� */
	char    asDuration[SMSP_TICKET_BUFLEN_OUT][7];
		/* �������� */
	char    asMsc[SMSP_TICKET_BUFLEN_OUT][16];
		/* �������� */
	char    asSmsp[SMSP_TICKET_BUFLEN_OUT][16];
		/* �û����� */
	char    asUserType[SMSP_TICKET_BUFLEN_OUT][2];
		/* SP������� */
	char    asSpAccNbr[SMSP_TICKET_BUFLEN_OUT][13];
		/* SPҵ����� */
	char    asSpServiceCode[SMSP_TICKET_BUFLEN_OUT][11];
		/* SP���� */
	char    asSpCode[SMSP_TICKET_BUFLEN_OUT][6];
		/* ����1 */
	char    asFee1[SMSP_TICKET_BUFLEN_OUT][7];
		/* ����2 */
	char    asFee2[SMSP_TICKET_BUFLEN_OUT][7];
		/* ����3 */
	char    asFee3[SMSP_TICKET_BUFLEN_OUT][7];
		/* ����4 */
	char    asFee4[SMSP_TICKET_BUFLEN_OUT][7];
	char    asFee5[SMSP_TICKET_BUFLEN_OUT][9];
	char    asFee6[SMSP_TICKET_BUFLEN_OUT][9];
	int	aiTicketTypeID[SMSP_TICKET_BUFLEN_OUT];
	
	char	asErrCode[SMSP_TICKET_BUFLEN_OUT][5];
	char	asFileName[SMSP_TICKET_BUFLEN_OUT][20];
	char	asModule[SMSP_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[SMSP_TICKET_BUFLEN_OUT][6];
	char	asState[SMSP_TICKET_BUFLEN_OUT][2];

		/* �������� */
	char    asUpdateDate[SMSP_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMSP_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[SMSP_TICKET_BUFLEN_OUT][41];
};


/*�����ṹ����*/
struct SmspTicketStruct{

	struct SmspTicketStruct *pNext;
	char    sCallType[3];		/* �������� */
	char    sCityCode[6];		/* ������д��� */
	char    sMsisdn[16];		/* �û����� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	char    sDuration[7];		/* �ֽ��� */
	char    sMsc[16];		/* �������� */
	char    sSmsp[16];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sSpAccNbr[13];		/* SP������� */
	char    sSpServiceCode[11];		/* SPҵ����� */
	char    sSpCode[6];		/* SP���� */
	char    sFee1[7];		/* ����1 */
	char    sFee2[7];		/* ����2 */
	char    sFee3[7];		/* ����3 */
	char    sFee4[7];		/* ����4 */
	char	sFee5[9];
	char	sFee6[9];
	int	iTicketTypeID;

	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];		/* �������� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct SmspTicketStruct *pLoadNext;
};
/* ����ṹ��������*/
struct SmspTicketStructIn{

#ifndef SMSP_TICKET_BUFLEN_IN
#define SMSP_TICKET_BUFLEN_IN		300
#endif

	struct SmspTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asCallType[SMSP_TICKET_BUFLEN_IN][3];
		/* ������д��� */
	char    asCityCode[SMSP_TICKET_BUFLEN_IN][6];
		/* �û����� */
	char    asMsisdn[SMSP_TICKET_BUFLEN_IN][16];
		/* �Զ˺��� */
	char    asOtherParty[SMSP_TICKET_BUFLEN_IN][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[SMSP_TICKET_BUFLEN_IN][15];
		/* �ֽ��� */
	char    asDuration[SMSP_TICKET_BUFLEN_IN][7];
		/* �������� */
	char    asMsc[SMSP_TICKET_BUFLEN_IN][16];
		/* �������� */
	char    asSmsp[SMSP_TICKET_BUFLEN_IN][16];
		/* �û����� */
	char    asUserType[SMSP_TICKET_BUFLEN_IN][2];
		/* SP������� */
	char    asSpAccNbr[SMSP_TICKET_BUFLEN_IN][13];
		/* SPҵ����� */
	char    asSpServiceCode[SMSP_TICKET_BUFLEN_IN][11];
		/* SP���� */
	char    asSpCode[SMSP_TICKET_BUFLEN_IN][6];
		/* ����1 */
	char    asFee1[SMSP_TICKET_BUFLEN_IN][7];
		/* ����2 */
	char    asFee2[SMSP_TICKET_BUFLEN_IN][7];
		/* ����3 */
	char    asFee3[SMSP_TICKET_BUFLEN_IN][7];
		/* ����4 */
	char    asFee4[SMSP_TICKET_BUFLEN_IN][7];
	char    asFee5[SMSP_TICKET_BUFLEN_IN][9];	
	char    asFee6[SMSP_TICKET_BUFLEN_IN][9];                 
	int	aiTicketTypeID[SMSP_TICKET_BUFLEN_IN];
	
	char	asErrCode[SMSP_TICKET_BUFLEN_IN][5];
	char	asFileName[SMSP_TICKET_BUFLEN_IN][20];
	char	asModule[SMSP_TICKET_BUFLEN_IN][4];
	char	asAreaCode[SMSP_TICKET_BUFLEN_IN][6];
	char	asState[SMSP_TICKET_BUFLEN_IN][2];

		/* �������� */
	char    asUpdateDate[SMSP_TICKET_BUFLEN_IN][15];
	char    asDealDate[SMSP_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[SMSP_TICKET_BUFLEN_IN][41];
	char	asRowID[SMSP_TICKET_BUFLEN_IN][19];
};
void mvitem_mfsmspticket(struct SmspTicketStruct *pi,struct FSmspTicketStruct *po);
/*�������ݽṹ����д��SMSP_TICKET*/
int EInsertStructToSmspTicket(struct SmspTicketStruct *p,
	int iInsertFlag,struct SmspTicketStructOut *pTarget);
int InsertSmspTicket(char sFileName[],char sTableName[]);
/*�������ݶ�̬��SMSP_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmspTicketToStruct(struct SmspTicketStruct *p,
	struct SmspTicketStructIn *pSource);
void mvitem_fmsmspticket(struct FSmspTicketStruct *pi,int len,
	struct SmspTicketStruct *po);

/*����ṹ��������*/
struct GprsTicketStructOut{

#ifndef GPRS_TICKET_BUFLEN_OUT
#define GPRS_TICKET_BUFLEN_OUT		300
#endif

	struct GprsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��¼���� */
	char    asRecordType[GPRS_TICKET_BUFLEN_OUT][3];
		/* ����෢��PDP�����ĵı�־ */
	char    asNiPdp[GPRS_TICKET_BUFLEN_OUT][2];
		/* �û����� */
	char    asMsisdn[GPRS_TICKET_BUFLEN_OUT][16];
		/* IMSI���� */
	char    asImsi[GPRS_TICKET_BUFLEN_OUT][16];
		/* SGSN���� */
	char    asSgsn[GPRS_TICKET_BUFLEN_OUT][9];
		/* �ֻ����������� */
	char    asMsnc[GPRS_TICKET_BUFLEN_OUT][2];
		/* LAC */
	char    asLac[GPRS_TICKET_BUFLEN_OUT][5];
		/* ·������ */
	char    asRouteArea[GPRS_TICKET_BUFLEN_OUT][5];
		/* CELL_ID */
	char    asCellID[GPRS_TICKET_BUFLEN_OUT][5];
		/* PDP�����ĵļƷѱ�ʶ */
	char    asChargingID[GPRS_TICKET_BUFLEN_OUT][9];
		/* GGSN */
	char    asGgsn[GPRS_TICKET_BUFLEN_OUT][9];
		/* APN�������ʶ */
	char    asApnNi[GPRS_TICKET_BUFLEN_OUT][64];
		/* APN����Ӫ�̱�ʶ */
	char    asApnOi[GPRS_TICKET_BUFLEN_OUT][38];
		/* PDP���� */
	char    asPdpType[GPRS_TICKET_BUFLEN_OUT][2];
		/* �ն˵�PDP��ַ */
	char    asServedPdpAddress[GPRS_TICKET_BUFLEN_OUT][17];
		/* SGSN�л���ʶ */
	char    asSgsnChange[GPRS_TICKET_BUFLEN_OUT][2];
		/* ��¼��ֹԭ�� */
	char    asCloseCause[GPRS_TICKET_BUFLEN_OUT][2];
		/* "S"���ϲ��ɹ�;"F"��Ҫ��һ���ϲ�;"N"���ϲ��������� */
	char    asResult[GPRS_TICKET_BUFLEN_OUT][2];
		/* �û��������� */
	char    asHomeAreaCode[GPRS_TICKET_BUFLEN_OUT][10];
		/* �û��ݷ� */
	char    asVisitAreaCode[GPRS_TICKET_BUFLEN_OUT][10];
		/* "00" ��ͨ�û�;"01" Ԥ�����û�;"02" �����û� */
	char    asUserType[GPRS_TICKET_BUFLEN_OUT][3];
		/* �������� */
	char    asFeeType[GPRS_TICKET_BUFLEN_OUT][3];
		/* �������� */
	char    asRoamType[GPRS_TICKET_BUFLEN_OUT][2];
		/* �������� */
	char    asServiceType[GPRS_TICKET_BUFLEN_OUT][4];
		/* Ӧ��ʱ�� */
	char    asStartTime[GPRS_TICKET_BUFLEN_OUT][15];
		/* ���г���ʱ�� */
	char    asCallDuration[GPRS_TICKET_BUFLEN_OUT][7];
		/* �ʷ�1 */
	char    asTariff1[GPRS_TICKET_BUFLEN_OUT][2];
		/* ��������1 */
	char    asDataFlowup1[GPRS_TICKET_BUFLEN_OUT][11];
		/* ��������1 */
	char    asDataFlowdn1[GPRS_TICKET_BUFLEN_OUT][11];
		/* ����ʱ��1 */
	char    asDuration1[GPRS_TICKET_BUFLEN_OUT][7];
		/* �ʷ�2 */
	char    asTariff2[GPRS_TICKET_BUFLEN_OUT][2];
		/* ��������2 */
	char    asDataFlowup2[GPRS_TICKET_BUFLEN_OUT][11];
		/* ��������2 */
	char    asDataFlowdn2[GPRS_TICKET_BUFLEN_OUT][11];
		/* ����ʱ��2 */
	char    asDuration2[GPRS_TICKET_BUFLEN_OUT][7];
		/* �ʷ�3 */
	char    asTariff3[GPRS_TICKET_BUFLEN_OUT][2];
		/* ��������3 */
	char    asDataFlowup3[GPRS_TICKET_BUFLEN_OUT][11];
		/* ��������3 */
	char    asDataFlowdn3[GPRS_TICKET_BUFLEN_OUT][11];
		/* ����ʱ��3 */
	char    asDuration3[GPRS_TICKET_BUFLEN_OUT][7];
		/* �ʷ�4 */
	char    asTariff4[GPRS_TICKET_BUFLEN_OUT][2];
		/* ��������4 */
	char    asDataFlowup4[GPRS_TICKET_BUFLEN_OUT][11];
		/* ��������4 */
	char    asDataFlowdn4[GPRS_TICKET_BUFLEN_OUT][11];
		/* ����ʱ��4 */
	char    asDuration4[GPRS_TICKET_BUFLEN_OUT][7];
		/* �ʷ�5 */
	char    asTariff5[GPRS_TICKET_BUFLEN_OUT][2];
		/* ��������5 */
	char    asDataFlowup5[GPRS_TICKET_BUFLEN_OUT][11];
		/* ��������5 */
	char    asDataFlowdn5[GPRS_TICKET_BUFLEN_OUT][11];
		/* ����ʱ��5 */
	char    asDuration5[GPRS_TICKET_BUFLEN_OUT][7];
		/* �ʷ�6 */
	char    asTariff6[GPRS_TICKET_BUFLEN_OUT][2];
		/* ��������6 */
	char    asDataFlowup6[GPRS_TICKET_BUFLEN_OUT][11];
		/* ��������6 */
	char    asDataFlowdn6[GPRS_TICKET_BUFLEN_OUT][11];
		/* ����ʱ��6 */
	char    asDuration6[GPRS_TICKET_BUFLEN_OUT][7];
		/* ����ͨ�ŷ� */
	char    asCfee[GPRS_TICKET_BUFLEN_OUT][9];
		/* ����1 */
	char    asFee1[GPRS_TICKET_BUFLEN_OUT][9];
		/* ����2 */
	char    asFee2[GPRS_TICKET_BUFLEN_OUT][9];
		/* ����3 */
	char    asFee3[GPRS_TICKET_BUFLEN_OUT][9];
		/* �ܷ��� */
	char    asTotalFee[GPRS_TICKET_BUFLEN_OUT][10];
	
	int	aiTicketTypeID[GPRS_TICKET_BUFLEN_OUT];
	char	asErrCode[GPRS_TICKET_BUFLEN_OUT][5];
	char	asFileName[GPRS_TICKET_BUFLEN_OUT][20];
	char	asModule[GPRS_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[GPRS_TICKET_BUFLEN_OUT][6];
	char	asState[GPRS_TICKET_BUFLEN_OUT][2];

		/* �������� */
	char    asUpdateDate[GPRS_TICKET_BUFLEN_OUT][15];
	char    asDealDate[GPRS_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[GPRS_TICKET_BUFLEN_OUT][41];
};

/*�����ṹ����*/
struct GprsTicketStruct{

	struct GprsTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sNiPdp[2];		/* ����෢��PDP�����ĵı�־ */
	char    sMsisdn[16];		/* �û����� */
	char    sImsi[16];		/* IMSI���� */
	char    sSgsn[9];		/* SGSN���� */
	char    sMsnc[2];		/* �ֻ����������� */
	char    sLac[5];		/* LAC */
	char    sRouteArea[5];		/* ·������ */
	char    sCellID[5];		/* CELL_ID */
	char    sChargingID[9];		/* PDP�����ĵļƷѱ�ʶ */
	char    sGgsn[9];		/* GGSN */
	char    sApnNi[64];		/* APN�������ʶ */
	char    sApnOi[38];		/* APN����Ӫ�̱�ʶ */
	char    sPdpType[2];		/* PDP���� */
	char    sServedPdpAddress[17];		/* �ն˵�PDP��ַ */
	char    sSgsnChange[2];		/* SGSN�л���ʶ */
	char    sCloseCause[2];		/* ��¼��ֹԭ�� */
	char    sResult[2];		/* "S"���ϲ��ɹ�;"F"��Ҫ��һ���ϲ�;"N"���ϲ��������� */
	char    sHomeAreaCode[10];		/* �û��������� */
	char    sVisitAreaCode[10];		/* �û��ݷ� */
	char    sUserType[3];		/* "00" ��ͨ�û�;"01" Ԥ�����û�;"02" �����û� */
	char    sFeeType[3];		/* �������� */
	char    sRoamType[2];		/* �������� */
	char    sServiceType[4];		/* �������� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	char    sCallDuration[7];		/* ���г���ʱ�� */
	char    sTariff1[2];		/* �ʷ�1 */
	char    sDataFlowup1[11];		/* ��������1 */
	char    sDataFlowdn1[11];		/* ��������1 */
	char    sDuration1[7];		/* ����ʱ��1 */
	char    sTariff2[2];		/* �ʷ�2 */
	char    sDataFlowup2[11];		/* ��������2 */
	char    sDataFlowdn2[11];		/* ��������2 */
	char    sDuration2[7];		/* ����ʱ��2 */
	char    sTariff3[2];		/* �ʷ�3 */
	char    sDataFlowup3[11];		/* ��������3 */
	char    sDataFlowdn3[11];		/* ��������3 */
	char    sDuration3[7];		/* ����ʱ��3 */
	char    sTariff4[2];		/* �ʷ�4 */
	char    sDataFlowup4[11];		/* ��������4 */
	char    sDataFlowdn4[11];		/* ��������4 */
	char    sDuration4[7];		/* ����ʱ��4 */
	char    sTariff5[2];		/* �ʷ�5 */
	char    sDataFlowup5[11];		/* ��������5 */
	char    sDataFlowdn5[11];		/* ��������5 */
	char    sDuration5[7];		/* ����ʱ��5 */
	char    sTariff6[2];		/* �ʷ�6 */
	char    sDataFlowup6[11];		/* ��������6 */
	char    sDataFlowdn6[11];		/* ��������6 */
	char    sDuration6[7];		/* ����ʱ��6 */
	char    sCfee[9];		/* ����ͨ�ŷ� */
	char    sFee1[9];		/* ����1 */
	char    sFee2[9];		/* ����2 */
	char    sFee3[9];		/* ����3 */
	char    sTotalFee[10];		/* �ܷ��� */
	int	iTicketTypeID;
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];		/* �������� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct GprsTicketStruct *pLoadNext;
};
/* ����ṹ��������*/
struct GprsTicketStructIn{

#ifndef GPRS_TICKET_BUFLEN_IN
#define GPRS_TICKET_BUFLEN_IN		300
#endif

	struct GprsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��¼���� */
	char    asRecordType[GPRS_TICKET_BUFLEN_IN][3];
		/* ����෢��PDP�����ĵı�־ */
	char    asNiPdp[GPRS_TICKET_BUFLEN_IN][2];
		/* �û����� */
	char    asMsisdn[GPRS_TICKET_BUFLEN_IN][16];
		/* IMSI���� */
	char    asImsi[GPRS_TICKET_BUFLEN_IN][16];
		/* SGSN���� */
	char    asSgsn[GPRS_TICKET_BUFLEN_IN][9];
		/* �ֻ����������� */
	char    asMsnc[GPRS_TICKET_BUFLEN_IN][2];
		/* LAC */
	char    asLac[GPRS_TICKET_BUFLEN_IN][5];
		/* ·������ */
	char    asRouteArea[GPRS_TICKET_BUFLEN_IN][5];
		/* CELL_ID */
	char    asCellID[GPRS_TICKET_BUFLEN_IN][5];
		/* PDP�����ĵļƷѱ�ʶ */
	char    asChargingID[GPRS_TICKET_BUFLEN_IN][9];
		/* GGSN */
	char    asGgsn[GPRS_TICKET_BUFLEN_IN][9];
		/* APN�������ʶ */
	char    asApnNi[GPRS_TICKET_BUFLEN_IN][64];
		/* APN����Ӫ�̱�ʶ */
	char    asApnOi[GPRS_TICKET_BUFLEN_IN][38];
		/* PDP���� */
	char    asPdpType[GPRS_TICKET_BUFLEN_IN][2];
		/* �ն˵�PDP��ַ */
	char    asServedPdpAddress[GPRS_TICKET_BUFLEN_IN][17];
		/* SGSN�л���ʶ */
	char    asSgsnChange[GPRS_TICKET_BUFLEN_IN][2];
		/* ��¼��ֹԭ�� */
	char    asCloseCause[GPRS_TICKET_BUFLEN_IN][2];
		/* "S"���ϲ��ɹ�;"F"��Ҫ��һ���ϲ�;"N"���ϲ��������� */
	char    asResult[GPRS_TICKET_BUFLEN_IN][2];
		/* �û��������� */
	char    asHomeAreaCode[GPRS_TICKET_BUFLEN_IN][10];
		/* �û��ݷ� */
	char    asVisitAreaCode[GPRS_TICKET_BUFLEN_IN][10];
		/* "00" ��ͨ�û�;"01" Ԥ�����û�;"02" �����û� */
	char    asUserType[GPRS_TICKET_BUFLEN_IN][3];
		/* �������� */
	char    asFeeType[GPRS_TICKET_BUFLEN_IN][3];
		/* �������� */
	char    asRoamType[GPRS_TICKET_BUFLEN_IN][2];
		/* �������� */
	char    asServiceType[GPRS_TICKET_BUFLEN_IN][4];
		/* Ӧ��ʱ�� */
	char    asStartTime[GPRS_TICKET_BUFLEN_IN][15];
		/* ���г���ʱ�� */
	char    asCallDuration[GPRS_TICKET_BUFLEN_IN][7];
		/* �ʷ�1 */
	char    asTariff1[GPRS_TICKET_BUFLEN_IN][2];
		/* ��������1 */
	char    asDataFlowup1[GPRS_TICKET_BUFLEN_IN][11];
		/* ��������1 */
	char    asDataFlowdn1[GPRS_TICKET_BUFLEN_IN][11];
		/* ����ʱ��1 */
	char    asDuration1[GPRS_TICKET_BUFLEN_IN][7];
		/* �ʷ�2 */
	char    asTariff2[GPRS_TICKET_BUFLEN_IN][2];
		/* ��������2 */
	char    asDataFlowup2[GPRS_TICKET_BUFLEN_IN][11];
		/* ��������2 */
	char    asDataFlowdn2[GPRS_TICKET_BUFLEN_IN][11];
		/* ����ʱ��2 */
	char    asDuration2[GPRS_TICKET_BUFLEN_IN][7];
		/* �ʷ�3 */
	char    asTariff3[GPRS_TICKET_BUFLEN_IN][2];
		/* ��������3 */
	char    asDataFlowup3[GPRS_TICKET_BUFLEN_IN][11];
		/* ��������3 */
	char    asDataFlowdn3[GPRS_TICKET_BUFLEN_IN][11];
		/* ����ʱ��3 */
	char    asDuration3[GPRS_TICKET_BUFLEN_IN][7];
		/* �ʷ�4 */
	char    asTariff4[GPRS_TICKET_BUFLEN_IN][2];
		/* ��������4 */
	char    asDataFlowup4[GPRS_TICKET_BUFLEN_IN][11];
		/* ��������4 */
	char    asDataFlowdn4[GPRS_TICKET_BUFLEN_IN][11];
		/* ����ʱ��4 */
	char    asDuration4[GPRS_TICKET_BUFLEN_IN][7];
		/* �ʷ�5 */
	char    asTariff5[GPRS_TICKET_BUFLEN_IN][2];
		/* ��������5 */
	char    asDataFlowup5[GPRS_TICKET_BUFLEN_IN][11];
		/* ��������5 */
	char    asDataFlowdn5[GPRS_TICKET_BUFLEN_IN][11];
		/* ����ʱ��5 */
	char    asDuration5[GPRS_TICKET_BUFLEN_IN][7];
		/* �ʷ�6 */
	char    asTariff6[GPRS_TICKET_BUFLEN_IN][2];
		/* ��������6 */
	char    asDataFlowup6[GPRS_TICKET_BUFLEN_IN][11];
		/* ��������6 */
	char    asDataFlowdn6[GPRS_TICKET_BUFLEN_IN][11];
		/* ����ʱ��6 */
	char    asDuration6[GPRS_TICKET_BUFLEN_IN][7];
		/* ����ͨ�ŷ� */
	char    asCfee[GPRS_TICKET_BUFLEN_IN][9];
		/* ����1 */
	char    asFee1[GPRS_TICKET_BUFLEN_IN][9];
		/* ����2 */
	char    asFee2[GPRS_TICKET_BUFLEN_IN][9];
		/* ����3 */
	char    asFee3[GPRS_TICKET_BUFLEN_IN][9];
		/* �ܷ��� */
	char    asTotalFee[GPRS_TICKET_BUFLEN_IN][10];
	
	int	aiTicketTypeID[GPRS_TICKET_BUFLEN_IN];
	
	char	asErrCode[GPRS_TICKET_BUFLEN_IN][5];
	char	asFileName[GPRS_TICKET_BUFLEN_IN][20];
	char	asModule[GPRS_TICKET_BUFLEN_IN][4];
	char	asAreaCode[GPRS_TICKET_BUFLEN_IN][6];
	char	asState[GPRS_TICKET_BUFLEN_IN][2];

		/* �������� */
	char    asUpdateDate[GPRS_TICKET_BUFLEN_IN][15];
	char    asDealDate[GPRS_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[GPRS_TICKET_BUFLEN_IN][41];
	char	asRowID[GPRS_TICKET_BUFLEN_IN][19];
};

void mvitem_fmgprsticket(struct FGprsTicketStruct *pi,int len,
	struct GprsTicketStruct *po);
/*�������ݽṹ����д��GPRS_TICKET*/
int EInsertStructToGprsTicket(struct GprsTicketStruct *p,
	int iInsertFlag,struct GprsTicketStructOut *pTarget);
int InsertGprsTicket(char sFileName[],char sTableName[]);
/*�������ݶ�̬��GPRS_TICKET���ýṹ���巽ʽȡ����*/
int EGetGprsTicketToStruct(struct GprsTicketStruct *p,
	struct GprsTicketStructIn *pSource);
void mvitem_mfgprsticket(struct GprsTicketStruct *pi,struct FGprsTicketStruct *po);

/*����ṹ��������*/
struct GprsTicketNewStructOut{

#ifndef GPRS_TICKET_NEW_BUFLEN_OUT
#define GPRS_TICKET_NEW_BUFLEN_OUT		300
#endif

	struct GprsTicketNewStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
					/*��¼����*/
	char    asRecordType[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*��������*/
	char    asRoamType[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*�ֻ��ն˵�IMSI*/
	char    asImsi[GPRS_TICKET_NEW_BUFLEN_OUT][16];
					/*�ֻ��ն˵�ISDN*/
	char    asMsisdn[GPRS_TICKET_NEW_BUFLEN_OUT][16];
					/*���λỰ��ʼSGSN IP��ַ*/
	char    asSgsn[GPRS_TICKET_NEW_BUFLEN_OUT][17];
					/*SGSN�ı��ʶ*/
	char    asSgsnChange[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*���λỰGGSN IP��ַ*/
	char    asGgsn[GPRS_TICKET_NEW_BUFLEN_OUT][17];
					/*�ֻ��ն�PDP IP��ַ*/
	char    asServedPdpAddress[GPRS_TICKET_NEW_BUFLEN_OUT][17];
					/*����������ʶ*/
	char    asApnNi[GPRS_TICKET_NEW_BUFLEN_OUT][64];
					/*�������Ӫ�̱�ʶ*/
	char    asApnOi[GPRS_TICKET_NEW_BUFLEN_OUT][38];
					/*�����ֶ�*/
	char    asReserv1[GPRS_TICKET_NEW_BUFLEN_OUT][15];
					/*������ʱ��*/
	int     aiCallDuration[GPRS_TICKET_NEW_BUFLEN_OUT];
					/*�ֲ����ͱ�ʶ��*/
	char    asPartialType[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*�ж�ԭ��*/
	char    asCloseCause[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*���λỰ���ӿ�ʼʱ��*/
	char    asStartTime[GPRS_TICKET_NEW_BUFLEN_OUT][15];
					/*�������б�־*/
	char    asNiPdp[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*PDP�����ļƷѱ�ʶ*/
	char    asChargingID[GPRS_TICKET_NEW_BUFLEN_OUT][11];
					/*λ������*/
	char    asLac[GPRS_TICKET_NEW_BUFLEN_OUT][6];
					/*С����ʶ*/
	char    asCellID[GPRS_TICKET_NEW_BUFLEN_OUT][6];
					/*���εس��д���*/
	char    asVisitCityCode[GPRS_TICKET_NEW_BUFLEN_OUT][4];
					/*�����ֶ�*/
	char    asReserv2[GPRS_TICKET_NEW_BUFLEN_OUT][11];
					/*���εر���*/
	char    asRoamRemark[GPRS_TICKET_NEW_BUFLEN_OUT][11];
					/*�ֻ�����*/
	char    asImei[GPRS_TICKET_NEW_BUFLEN_OUT][20];
					/*��������*/
	char    asDataFlowdn[GPRS_TICKET_NEW_BUFLEN_OUT][21];
					/*��������*/
	char    asDataFlowup[GPRS_TICKET_NEW_BUFLEN_OUT][21];
					/*�Ʒ���Ŀ*/
	char    asChargeItem[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*�Ʒ�ȡ��*/
	char    asChargeUnit[GPRS_TICKET_NEW_BUFLEN_OUT][21];
					/*�Ʒ�ҵ��*/
	char    asChargeOperation[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*����*/
	int     aiTotalFee[GPRS_TICKET_NEW_BUFLEN_OUT];
					/*�����ֶ�*/
	char    asReserv3[GPRS_TICKET_NEW_BUFLEN_OUT][64];
	char    asState[GPRS_TICKET_NEW_BUFLEN_OUT][2];
	char    asDealDate[GPRS_TICKET_NEW_BUFLEN_OUT][15];
	char    asSourceID[GPRS_TICKET_NEW_BUFLEN_OUT][31];
	char    asUpdateDate[GPRS_TICKET_NEW_BUFLEN_OUT][15];
};

/* ����ṹ��������*/
struct GprsTicketNewStructIn{

#ifndef GPRS_TICKET_NEW_BUFLEN_IN
#define GPRS_TICKET_NEW_BUFLEN_IN		300
#endif

	struct GprsTicketNewStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
					/*��¼����*/
	char    asRecordType[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*��������*/
	char    asRoamType[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*�ֻ��ն˵�IMSI*/
	char    asImsi[GPRS_TICKET_NEW_BUFLEN_IN][16];
					/*�ֻ��ն˵�ISDN*/
	char    asMsisdn[GPRS_TICKET_NEW_BUFLEN_IN][16];
					/*���λỰ��ʼSGSN IP��ַ*/
	char    asSgsn[GPRS_TICKET_NEW_BUFLEN_IN][17];
					/*SGSN�ı��ʶ*/
	char    asSgsnChange[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*���λỰGGSN IP��ַ*/
	char    asGgsn[GPRS_TICKET_NEW_BUFLEN_IN][17];
					/*�ֻ��ն�PDP IP��ַ*/
	char    asServedPdpAddress[GPRS_TICKET_NEW_BUFLEN_IN][17];
					/*����������ʶ*/
	char    asApnNi[GPRS_TICKET_NEW_BUFLEN_IN][64];
					/*�������Ӫ�̱�ʶ*/
	char    asApnOi[GPRS_TICKET_NEW_BUFLEN_IN][38];
					/*�����ֶ�*/
	char    asReserv1[GPRS_TICKET_NEW_BUFLEN_IN][15];
					/*������ʱ��*/
	int     aiCallDuration[GPRS_TICKET_NEW_BUFLEN_IN];
					/*�ֲ����ͱ�ʶ��*/
	char    asPartialType[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*�ж�ԭ��*/
	char    asCloseCause[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*���λỰ���ӿ�ʼʱ��*/
	char    asStartTime[GPRS_TICKET_NEW_BUFLEN_IN][15];
					/*�������б�־*/
	char    asNiPdp[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*PDP�����ļƷѱ�ʶ*/
	char    asChargingID[GPRS_TICKET_NEW_BUFLEN_IN][11];
					/*λ������*/
	char    asLac[GPRS_TICKET_NEW_BUFLEN_IN][6];
					/*С����ʶ*/
	char    asCellID[GPRS_TICKET_NEW_BUFLEN_IN][6];
					/*���εس��д���*/
	char    asVisitCityCode[GPRS_TICKET_NEW_BUFLEN_IN][4];
					/*�����ֶ�*/
	char    asReserv2[GPRS_TICKET_NEW_BUFLEN_IN][11];
					/*���εر���*/
	char    asRoamRemark[GPRS_TICKET_NEW_BUFLEN_IN][11];
					/*�ֻ�����*/
	char    asImei[GPRS_TICKET_NEW_BUFLEN_IN][20];
					/*��������*/
	char    asDataFlowdn[GPRS_TICKET_NEW_BUFLEN_IN][21];
					/*��������*/
	char    asDataFlowup[GPRS_TICKET_NEW_BUFLEN_IN][21];
					/*�Ʒ���Ŀ*/
	char    asChargeItem[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*�Ʒ�ȡ��*/
	char    asChargeUnit[GPRS_TICKET_NEW_BUFLEN_IN][21];
					/*�Ʒ�ҵ��*/
	char    asChargeOperation[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*����*/
	int     aiTotalFee[GPRS_TICKET_NEW_BUFLEN_IN];
					/*�����ֶ�*/
	char    asReserv3[GPRS_TICKET_NEW_BUFLEN_IN][64];
	char    asState[GPRS_TICKET_NEW_BUFLEN_IN][2];
	char    asDealDate[GPRS_TICKET_NEW_BUFLEN_IN][15];
	char    asSourceID[GPRS_TICKET_NEW_BUFLEN_IN][31];
	char    asUpdateDate[GPRS_TICKET_NEW_BUFLEN_IN][15];
};

/*�����ṹ����*/
struct GprsTicketNewStruct{

	struct GprsTicketNewStruct *pNext;
	char    sRecordType[3];				/*��¼����*/
	char    sRoamType[3];				/*��������*/
	char    sImsi[16];				/*�ֻ��ն˵�IMSI*/
	char    sMsisdn[16];				/*�ֻ��ն˵�ISDN*/
	char    sSgsn[17];				/*���λỰ��ʼSGSN IP��ַ*/
	char    sSgsnChange[2];				/*SGSN�ı��ʶ*/
	char    sGgsn[17];				/*���λỰGGSN IP��ַ*/
	char    sServedPdpAddress[17];				/*�ֻ��ն�PDP IP��ַ*/
	char    sApnNi[64];				/*����������ʶ*/
	char    sApnOi[38];				/*�������Ӫ�̱�ʶ*/
	char    sReserv1[15];				/*�����ֶ�*/
	int     iCallDuration;				/*������ʱ��*/
	char    sPartialType[2];				/*�ֲ����ͱ�ʶ��*/
	char    sCloseCause[3];				/*�ж�ԭ��*/
	char    sStartTime[15];				/*���λỰ���ӿ�ʼʱ��*/
	char    sNiPdp[2];				/*�������б�־*/
	char    sChargingID[11];				/*PDP�����ļƷѱ�ʶ*/
	char    sLac[6];				/*λ������*/
	char    sCellID[6];				/*С����ʶ*/
	char    sVisitCityCode[4];				/*���εس��д���*/
	char    sReserv2[11];				/*�����ֶ�*/
	char    sRoamRemark[11];				/*���εر���*/
	char    sImei[20];				/*�ֻ�����*/
	char    sDataFlowdn[21];				/*��������*/
	char    sDataFlowup[21];				/*��������*/
	char    sChargeItem[2];				/*�Ʒ���Ŀ*/
	char    sChargeUnit[21];				/*�Ʒ�ȡ��*/
	char    sChargeOperation[3];				/*�Ʒ�ҵ��*/
	int     iTotalFee;				/*����*/
	char    sReserv3[64];				/*�����ֶ�*/
	char    sState[2];
	char    sDealDate[15];
	char    sSourceID[31];
	char    sUpdateDate[15];
	struct GprsTicketNewStruct *pLoadNext;
};
/*�����ļ��ṹ����*/
struct FGprsTicketNewStruct{

	char    sRecordType[2];				/*��¼����*/
	char    sRoamType[2];				/*��������*/
	char    sImsi[15];				/*�ֻ��ն˵�IMSI*/
	char    sMsisdn[15];				/*�ֻ��ն˵�ISDN*/
	char    sSgsn[16];				/*���λỰ��ʼSGSN IP��ַ*/
	char    sSgsnChange[1];				/*SGSN�ı��ʶ*/
	char    sGgsn[16];				/*���λỰGGSN IP��ַ*/
	char    sServedPdpAddress[16];				/*�ֻ��ն�PDP IP��ַ*/
	char    sApnNi[63];				/*����������ʶ*/
	char    sApnOi[37];				/*�������Ӫ�̱�ʶ*/
	char    sReserv1[14];				/*�����ֶ�*/
	char    sCallDuration[6];				/*������ʱ��*/
	char    sPartialType[1];				/*�ֲ����ͱ�ʶ��*/
	char    sCloseCause[2];				/*�ж�ԭ��*/
	char    sStartTime[14];				/*���λỰ���ӿ�ʼʱ��*/
	char    sNiPdp[1];				/*�������б�־*/
	char    sChargingID[10];				/*PDP�����ļƷѱ�ʶ*/
	char    sLac[5];				/*λ������*/
	char    sCellID[5];				/*С����ʶ*/
	char    sVisitCityCode[3];				/*���εس��д���*/
	char    sReserv2[10];				/*�����ֶ�*/
	char    sRoamRemark[10];				/*���εر���*/
	char    sImei[19];				/*�ֻ�����*/
	char    sDataFlowdn[20];				/*��������*/
	char    sDataFlowup[20];				/*��������*/
	char    sChargeItem[1];				/*�Ʒ���Ŀ*/
	char    sChargeUnit[20];				/*�Ʒ�ȡ��*/
	char    sChargeOperation[2];				/*�Ʒ�ҵ��*/
	char    sTotalFee[9];				/*����*/
	char    sReserv3[63];				/*�����ֶ�*/
	char    sState[1];
	char    sDealDate[14];
	char    sSourceID[30];
	char    sUpdateDate[14];
};
/*�������ݽṹ����д��GPRS_TICKET_NEW*/
int EInsertStructToGprsTicketNew(struct GprsTicketNewStruct *p,
	int iInsertFlag,struct GprsTicketNewStructOut *pTarget);
/*�������ݶ�̬��GPRS_TICKET_NEW���ýṹ���巽ʽȡ����*/
int EGetGprsTicketNewToStruct(struct GprsTicketNewStruct *p,struct GprsTicketNewStructIn *pSource);
/*�����ƶ�����*/
void mvitem_fmgprsticketnew(struct FGprsTicketNewStruct *pi,struct GprsTicketNewStruct *po);
/*�ڴ������ƶ����ļ���¼������*/
void mvitem_mfgprsticketnew(struct GprsTicketNewStruct *pi,struct FGprsTicketNewStruct *po);
int InsertGprsTicketNew(char sFileName[],char sTableName[]);


/*����ṹ��������*/
struct CdmaTicketStructOut{

#ifndef CDMA_TICKET_BUFLEN_OUT
#define CDMA_TICKET_BUFLEN_OUT		300
#endif

	struct CdmaTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��¼���� */
	char    asRecordType[CDMA_TICKET_BUFLEN_OUT][3];
		/* �û����� */
	char    asMsisdn[CDMA_TICKET_BUFLEN_OUT][16];
		/* IMSI */
	char    asImsi[CDMA_TICKET_BUFLEN_OUT][16];
		/* �������к� */
	char    asEsn[CDMA_TICKET_BUFLEN_OUT][16];
		/* �Զ˺��� */
	char    asOtherParty[CDMA_TICKET_BUFLEN_OUT][22];
		/* MSRN */
	char    asMsrn[CDMA_TICKET_BUFLEN_OUT][16];
		/* ���������� */
	char    asThirdParty[CDMA_TICKET_BUFLEN_OUT][22];
		/* Ӧ��ʱ�� */
	char    asStartTime[CDMA_TICKET_BUFLEN_OUT][15];
		/* ʱ�� */
	char    asDuration[CDMA_TICKET_BUFLEN_OUT][7];
		/* ������ */
	char    asMsc[CDMA_TICKET_BUFLEN_OUT][11];
		/* LAC */
	char    asLac[CDMA_TICKET_BUFLEN_OUT][6];
		/* CELL_ID */
	char    asCellID[CDMA_TICKET_BUFLEN_OUT][6];
		/* �Զ�LAC */
	char    asOtherLac[CDMA_TICKET_BUFLEN_OUT][6];
		/* �Զ�CELL_ID */
	char    asOtherCellID[CDMA_TICKET_BUFLEN_OUT][6];
		/* ��ֵҵ�� */
	char    asAppendServiceCode[CDMA_TICKET_BUFLEN_OUT][3];
		/* ����ԭ�� */
	char    asEndReason[CDMA_TICKET_BUFLEN_OUT][2];
		/* ��ȱ��־ */
	char    asDeformityFlag[CDMA_TICKET_BUFLEN_OUT][2];
		/* ������ */
	char    asRoamFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* �����Ʒ�ʱ�� */
	char    asRoamDuration[CDMA_TICKET_BUFLEN_OUT][7];
		/* ��������ʱ�ʶ */
	char    asRoamRateType[CDMA_TICKET_BUFLEN_OUT][2];
		/* ��;�� */
	char    asTollFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* ��;�Ʒ�ʱ�� */
	char    asTollDuration[CDMA_TICKET_BUFLEN_OUT][7];
		/* ��;����ʱ�ʶ */
	char    asTollFeeType[CDMA_TICKET_BUFLEN_OUT][2];
		/* ��Ϣ�� */
	char    asInfoFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* ������ */
	char    asOtherFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* �Զ˹������д��� */
	char    asOppCityCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* �Զ˹���ʡ���� */
	char    asOppProvCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* �Զ����ڹ����� */
	char    asOppCountryCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* ��;���� */
	char    asTollType[CDMA_TICKET_BUFLEN_OUT][2];
		/* ��;������ */
	char    asTollNetType[CDMA_TICKET_BUFLEN_OUT][2];
		/* �������� */
	char    asRoamType[CDMA_TICKET_BUFLEN_OUT][2];
		/* ͨ���س��д��� */
	char    asVisitCityCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* ���м� */
	char    asTrunkIn[CDMA_TICKET_BUFLEN_OUT][9];
		/* ���м� */
	char    asTrunkOut[CDMA_TICKET_BUFLEN_OUT][9];
		/* �û����� */
	char    asUserType[CDMA_TICKET_BUFLEN_OUT][2];
		/* ����� */
	char    asActCode[CDMA_TICKET_BUFLEN_OUT][2];
		/* ҵ����� */
	char    asServiceCode[CDMA_TICKET_BUFLEN_OUT][3];
	char	asCalledType[CDMA_TICKET_BUFLEN_OUT][4];
	char	asHomeAreaCode[CDMA_TICKET_BUFLEN_OUT][11];
	char	asUserType1[CDMA_TICKET_BUFLEN_OUT][3];
	char	asReserve[CDMA_TICKET_BUFLEN_OUT][19];
	char    asUpdateDate[CDMA_TICKET_BUFLEN_OUT][15];
	char    asDealDate[CDMA_TICKET_BUFLEN_OUT][15];
	char    asSourceID[CDMA_TICKET_BUFLEN_OUT][41];
};
/*�����ṹ����*/
struct CdmaTicketStruct{

	struct CdmaTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sMsisdn[16];		/* �û����� */
	char    sImsi[16];		/* IMSI */
	char    sEsn[16];		/* �������к� */
	char    sOtherParty[22];		/* �Զ˺��� */
	char    sMsrn[16];		/* MSRN */
	char    sThirdParty[22];		/* ���������� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	char    sDuration[7];		/* ʱ�� */
	char    sMsc[11];		/* ������ */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sOtherLac[6];		/* �Զ�LAC */
	char    sOtherCellID[6];		/* �Զ�CELL_ID */
	char    sAppendServiceCode[3];		/* ��ֵҵ�� */
	char    sEndReason[2];		/* ����ԭ�� */
	char    sDeformityFlag[2];		/* ��ȱ��־ */
	char    sRoamFee[9];		/* ������ */
	char    sRoamDuration[7];		/* �����Ʒ�ʱ�� */
	char    sRoamRateType[2];		/* ��������ʱ�ʶ */
	char    sTollFee[9];		/* ��;�� */
	char    sTollDuration[7];		/* ��;�Ʒ�ʱ�� */
	char    sTollFeeType[2];		/* ��;����ʱ�ʶ */
	char    sInfoFee[9];		/* ��Ϣ�� */
	char    sOtherFee[9];		/* ������ */
	char    sOppCityCode[4];		/* �Զ˹������д��� */
	char    sOppProvCode[4];		/* �Զ˹���ʡ���� */
	char    sOppCountryCode[4];		/* �Զ����ڹ����� */
	char    sTollType[2];		/* ��;���� */
	char    sTollNetType[2];		/* ��;������ */
	char    sRoamType[2];		/* �������� */
	char    sVisitCityCode[4];		/* ͨ���س��д��� */
	char    sTrunkIn[9];		/* ���м� */
	char    sTrunkOut[9];		/* ���м� */
	char    sUserType[2];		/* �û����� */
	char    sActCode[2];		/* ����� */
	char    sServiceCode[3];		/* ҵ����� */
	char	sCalledType[4];
	char	sHomeAreaCode[11];
	char	sUserType1[3];
	char	sReserve[19];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct CdmaTicketStruct *pLoadNext;
};

int EInsertStructToCdmaTicket(struct CdmaTicketStruct *p,
	int iInsertFlag,struct CdmaTicketStructOut *pTarget);
void mvitem_fmcdmaticketfj(struct FCdmaTicketFjStruct *pi,struct CdmaTicketStruct *po);
void mvitem_fmcdmaticketxj(struct FCdmaTicketXjStruct *pi,struct CdmaTicketStruct *po);
void mvitem_fmcdmaticket(struct FCdmaTicketStruct *pi,struct CdmaTicketStruct *po);
int InsertCdmaBillTicket(char sFileName[],char sTableName[]);

/*����ṹ��������*/
struct Cdma1xTicketStructOut{

#ifndef CDMA1X_TICKET_BUFLEN_OUT
#define CDMA1X_TICKET_BUFLEN_OUT		300
#endif

	struct Cdma1xTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��¼���� */
	char    asRecordType[CDMA1X_TICKET_BUFLEN_OUT][3];
		/* ���к��� */
	char    asSeqNumber[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û��ֻ��� */
	char    asMdn[CDMA1X_TICKET_BUFLEN_OUT][21];
		/* MSISDN */
	char    asMsisdn[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* �ֻ��豸���� */
	char    asEsn[CDMA1X_TICKET_BUFLEN_OUT][20];
		/* IP */
	char    asIp[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* �û�����ҵ���˺� */
	char    asNai[CDMA1X_TICKET_BUFLEN_OUT][65];
		/* �û���� */
	char    asUserType[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* ��ͨ���д��� */
	char    asNaiAreaCode[CDMA1X_TICKET_BUFLEN_OUT][4];
		/* �������:0�����أ�1��ʡ�����룻2��ʡ������;3���������룻4������������ȱʡ����
IMSI ���������жϣ� */
	char    asRoamType[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* IP��� */
	char    asIpTechType[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* ��ʶһ���Ự���� */
	char    asAccountSessionID[CDMA1X_TICKET_BUFLEN_OUT][9];
		/* ��ʶһ��PPP ���� */
	char    asCorrelationID[CDMA1X_TICKET_BUFLEN_OUT][9];
		/* HA ��IP ��ַ */
	char    asHaip[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* pdsnip */
	char    asPdsnip[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* ʹ��PCF ��ַ */
	char    asPcfip[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* SID NID BSC ID */
	char    asBsid[CDMA1X_TICKET_BUFLEN_OUT][13];
		/* �û����������ʶ */
	char    asUzid[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �̶�Ϊ33 */
	char    asServiceOption[CDMA1X_TICKET_BUFLEN_OUT][3];
		/* ǿ���������� */
	char    asCompulsoryTunnel[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* ����Accounting stop ��ԭ�� */
	char    asEndRelease[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* ���͸��û����ֽ��� */
	char    asDataCountTermination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û�������ֽ��� */
	char    asDataCountOrigination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* ��PDSN �����Ļ�֡ */
	char    asBadFrameCount[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �Ự��ʼ��ʱ��� */
	char    asStartTime[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* �Ự������ʱ��� */
	char    asStopTime[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* �Ựʱ�� */
	char    asActiveTime[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* ת������ */
	char    asActionCount[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û�SDB�����ֽ��� */
	char    asSdbCountTermination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û�SDB�����ֽ��� */
	char    asSdbCountOrigination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û�����SDB���� */
	char    asSdbTerminationnum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û�����SDB���� */
	char    asSdbOriginationnum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* PDSN �յ���HDLC */
	char    asPdsnReceiveNum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û�����MIP �����ֽ� */
	char    asMipReceiveNum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* �û�����MIP �����ֽ� */
	char    asMipSendNum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* IP �����û������ȼ��� */
	char    asIpqos[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* ������·�����ȼ��� */
	char    asAirlinkqos[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* ������ */
	int     aiBaseCharge[CDMA1X_TICKET_BUFLEN_OUT];
		/* ������ */
	int     aiFluxCharge[CDMA1X_TICKET_BUFLEN_OUT];
		/* �������� */
	int     aiOtherCharge[CDMA1X_TICKET_BUFLEN_OUT];
		/* �����س��д��� */
	char    asHomeCountryCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* ��������Ӫ�̴��� */
	char    asHomeOperatorCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* ���εس��д��� */
	char    asVisitCountryCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* ���ε���Ӫ�̴��� */
	char    asVisitOperatoCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* �ʷѹ����ʶ */
	char    asRatingRuleID[CDMA1X_TICKET_BUFLEN_OUT][9];
		/* ϵͳ���� */
	char    asNoused1[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* ϵͳ����2 */
	char    asNoused2[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* ϵͳ����3 */
	char    asNoused3[CDMA1X_TICKET_BUFLEN_OUT][11];
	
	int	aiTicketTypeID[CDMA1X_TICKET_BUFLEN_OUT];
	char	asHomeAreaCode[CDMA1X_TICKET_BUFLEN_OUT][6];
	char	asErrCode[CDMA1X_TICKET_BUFLEN_OUT][5];
	char	asFileName[CDMA1X_TICKET_BUFLEN_OUT][20];
	char	asModule[CDMA1X_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[CDMA1X_TICKET_BUFLEN_OUT][6];
	char	asState[CDMA1X_TICKET_BUFLEN_OUT][2];

		/* ����ʱ�� */
	char    asUpdateDate[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* ����ʱ�� */
	char    asDealDate[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[CDMA1X_TICKET_BUFLEN_OUT][41];
};
/*�����ṹ����*/
struct Cdma1xTicketStruct{

	struct Cdma1xTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sSeqNumber[11];		/* ���к��� */
	char    sMdn[21];		/* �û��ֻ��� */
	char    sMsisdn[16];		/* MSISDN */
	char    sEsn[20];		/* �ֻ��豸���� */
	char    sIp[16];		/* IP */
	char    sNai[65];		/* �û�����ҵ���˺� */
	char    sUserType[2];		/* �û���� */
	char    sNaiAreaCode[4];		/* ��ͨ���д��� */
	char    sRoamType[2];		/* �������:0�����أ�1��ʡ�����룻2��ʡ������;3���������룻
4������������ȱʡ����IMSI ���������жϣ� */
	char    sIpTechType[2];		/* IP��� */
	char    sAccountSessionID[9];		/* ��ʶһ���Ự���� */
	char    sCorrelationID[9];		/* ��ʶһ��PPP ���� */
	char    sHaip[16];		/* HA ��IP ��ַ */
	char    sPdsnip[16];		/* pdsnip */
	char    sPcfip[16];		/* ʹ��PCF ��ַ */
	char    sBsid[13];		/* SID NID BSC ID */
	char    sUzid[11];		/* �û����������ʶ */
	char    sServiceOption[3];		/* �̶�Ϊ33 */
	char    sCompulsoryTunnel[2];		/* ǿ���������� */
	char    sEndRelease[2];		/* ����Accounting stop ��ԭ�� */
	char    sDataCountTermination[11];		/* ���͸��û����ֽ��� */
	char    sDataCountOrigination[11];		/* �û�������ֽ��� */
	char    sBadFrameCount[11];		/* ��PDSN �����Ļ�֡ */
	char    sStartTime[15];		/* �Ự��ʼ��ʱ��� */
	char    sStopTime[15];		/* �Ự������ʱ��� */
	char    sActiveTime[11];		/* �Ựʱ�� */
	char    sActionCount[11];		/* ת������ */
	char    sSdbCountTermination[11];		/* �û�SDB�����ֽ��� */
	char    sSdbCountOrigination[11];		/* �û�SDB�����ֽ��� */
	char    sSdbTerminationnum[11];		/* �û�����SDB���� */
	char    sSdbOriginationnum[11];		/* �û�����SDB���� */
	char    sPdsnReceiveNum[11];		/* PDSN �յ���HDLC */
	char    sMipReceiveNum[11];		/* �û�����MIP �����ֽ� */
	char    sMipSendNum[11];		/* �û�����MIP �����ֽ� */
	char    sIpqos[11];		/* IP �����û������ȼ��� */
	char    sAirlinkqos[11];		/* ������·�����ȼ��� */
	int     iBaseCharge;		/* ������ */
	int     iFluxCharge;		/* ������ */
	int     iOtherCharge;		/* �������� */
	char    sHomeCountryCode[6];		/* �����س��д��� */
	char    sHomeOperatorCode[6];		/* ��������Ӫ�̴��� */
	char    sVisitCountryCode[6];		/* ���εس��д��� */
	char    sVisitOperatoCode[6];		/* ���ε���Ӫ�̴��� */
	char    sRatingRuleID[9];		/* �ʷѹ����ʶ */
	char    sNoused1[11];		/* ϵͳ���� */
	char    sNoused2[11];		/* ϵͳ����2 */
	char    sNoused3[11];		/* ϵͳ����3 */

	int	iTicketTypeID;
	char	sHomeAreaCode[6];
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];

	char    sUpdateDate[15];		/* ����ʱ�� */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct Cdma1xTicketStruct *pLoadNext;
};

/* ����ṹ��������*/
struct Cdma1xTicketStructIn{

#ifndef CDMA1X_TICKET_BUFLEN_IN
#define CDMA1X_TICKET_BUFLEN_IN		300
#endif

	struct Cdma1xTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��¼���� */
	char    asRecordType[CDMA1X_TICKET_BUFLEN_IN][3];
		/* ��ˮ�� */
	char    asSeqNumber[CDMA1X_TICKET_BUFLEN_IN][11];
		/* �û��ֻ��� */
	char    asMdn[CDMA1X_TICKET_BUFLEN_IN][21];
		/* �û����� */
	char    asMsisdn[CDMA1X_TICKET_BUFLEN_IN][16];
		/* �ֻ��豸���� */
	char    asEsn[CDMA1X_TICKET_BUFLEN_IN][20];
		/* IP */
	char    asIp[CDMA1X_TICKET_BUFLEN_IN][16];
		/* �û�����ҵ���˺� */
	char    asNai[CDMA1X_TICKET_BUFLEN_IN][65];
		/* �û���� */
	char    asUserType[CDMA1X_TICKET_BUFLEN_IN][2];
		/* ��ͨ���д��� */
	char    asNaiAreaCode[CDMA1X_TICKET_BUFLEN_IN][4];
		/* �������:0�����أ�1��ʡ�����룻2��ʡ������;3���������룻4������������ȱʡ����IMSI ���������жϣ� */
	char    asRoamType[CDMA1X_TICKET_BUFLEN_IN][2];
		/* IP��� */
	char    asIpTechType[CDMA1X_TICKET_BUFLEN_IN][2];
		/* ��ʶһ���Ự���� */
	char    asAccountSessionID[CDMA1X_TICKET_BUFLEN_IN][9];
		/* ��ʶһ��PPP ���� */
	char    asCorrelationID[CDMA1X_TICKET_BUFLEN_IN][9];
		/* HA ��IP ��ַ */
	char    asHaip[CDMA1X_TICKET_BUFLEN_IN][16];
		/* pdsnip */
	char    asPdsnip[CDMA1X_TICKET_BUFLEN_IN][16];
		/* ʹ��PCF ��ַ */
	char    asPcfip[CDMA1X_TICKET_BUFLEN_IN][16];
		/* SID NID BSC ID */
	char    asBsid[CDMA1X_TICKET_BUFLEN_IN][13];
		/* �û����������ʶ */
	char    asUzid[CDMA1X_TICKET_BUFLEN_IN][11];
		/* CDMA 1X ����ҵ��Ϊ33 */
	char    asServiceOption[CDMA1X_TICKET_BUFLEN_IN][3];
		/* ǿ���������� */
	char    asCompulsoryTunnel[CDMA1X_TICKET_BUFLEN_IN][2];
		/* ����Accounting stop ��ԭ�� */
	char    asEndRelease[CDMA1X_TICKET_BUFLEN_IN][2];
		/* ���͸��û����ֽ��� */
	char    asDataCountTermination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* �û�������ֽ��� */
	char    asDataCountOrigination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ��PDSN �����Ļ�֡ */
	char    asBadFrameCount[CDMA1X_TICKET_BUFLEN_IN][11];
		/* �Ự��ʼ��ʱ��� */
	char    asStartTime[CDMA1X_TICKET_BUFLEN_IN][15];
		/* �Ự������ʱ��� */
	char    asStopTime[CDMA1X_TICKET_BUFLEN_IN][15];
		/* PCF ��ͳ�ƵĻỰʱ�� */
	char    asActiveTime[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ״̬ת���Ĵ��� */
	char    asActionCount[CDMA1X_TICKET_BUFLEN_IN][11];
		/* SDB�����ֽ��� */
	char    asSdbCountTermination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* SDB�����ֽ��� */
	char    asSdbCountOrigination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ����SDB���� */
	char    asSdbTerminationnum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ����SDB���� */
	char    asSdbOriginationnum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* PDSN �յ���HDLC */
	char    asPdsnReceiveNum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* �û����յ���MIP �����ֽ��� */
	char    asMipReceiveNum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* �û����͵�MIP �����ֽ��� */
	char    asMipSendNum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* IP ������û������ȼ��� */
	char    asIpqos[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ������·�����ȼ��� */
	char    asAirlinkqos[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ������ */
	int     aiBaseCharge[CDMA1X_TICKET_BUFLEN_IN];
		/* ������ */
	int     aiFluxCharge[CDMA1X_TICKET_BUFLEN_IN];
		/* �������� */
	int     aiOtherCharge[CDMA1X_TICKET_BUFLEN_IN];
		/* �����س��д��� */
	char    asHomeCountryCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* ��������Ӫ�̴��� */
	char    asHomeOperatorCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* ���εس��д��� */
	char    asVisitCountryCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* ���ε���Ӫ�̴��� */
	char    asVisitOperatoCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* �ʷѹ����ʶ */
	char    asRatingRuleID[CDMA1X_TICKET_BUFLEN_IN][9];
		/* ϵͳ���� */
	char    asNoused1[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ϵͳ����2 */
	char    asNoused2[CDMA1X_TICKET_BUFLEN_IN][11];
		/* ϵͳ����3 */
	char    asNoused3[CDMA1X_TICKET_BUFLEN_IN][11];
		/* �������� */
	int     aiTicketTypeID[CDMA1X_TICKET_BUFLEN_IN];
		/* �û����� */
	char    asHomeAreaCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* ������� */
	char    asErrCode[CDMA1X_TICKET_BUFLEN_IN][5];
		/* �ļ��� */
	char    asFileName[CDMA1X_TICKET_BUFLEN_IN][20];
		/* ģ���� */
	char    asModule[CDMA1X_TICKET_BUFLEN_IN][4];
		/* ���� */
	char    asAreaCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* ״̬ */
	char    asState[CDMA1X_TICKET_BUFLEN_IN][2];
		/* ��������ʱ�� */
	char    asUpdateDate[CDMA1X_TICKET_BUFLEN_IN][15];
		/* ��������ʱ�� */
	char    asDealDate[CDMA1X_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[CDMA1X_TICKET_BUFLEN_IN][41];
	char	asRowID[CDMA1X_TICKET_BUFLEN_IN][19];
};

int EInsertStructToCdma1xTicket(struct Cdma1xTicketStruct *p,
	int iInsertFlag,struct Cdma1xTicketStructOut *pTarget);
void mvitem_fmcdma1xticket(struct FCdma1xTicketStruct *pi,int len,
	struct Cdma1xTicketStruct *po);
int InsertCdma1xTicket(char sFileName[],char sTableName[]);
/*�������ݶ�̬��CDMA1X_TICKET���ýṹ���巽ʽȡ����*/
int EGetCdma1xTicketToStruct(struct Cdma1xTicketStruct *p,
	struct Cdma1xTicketStructIn *pSource);
void mvitem_mfcdma1xticket(struct Cdma1xTicketStruct *pi,
	struct FCdma1xTicketStruct *po);


#define SCP_NIL		"0"	/*��������*/	
#define SCP_PPC		"1"     /*PPC*/
#define SCP_WVPN	"2"     /*WVPN*/
#define SCP_VOIP	"3"     /*VOIP*/
#define DEFORM_NORMAL	"0"     /*��������*/
#define DEFORM_BGN	"1"     /*��ʼ����*/
#define DEFORM_MID	"2"     /*�м仰��*/
#define DEFORM_END	"3"     /*��������*/
#define STATE_NORMAL	"0"     /*��������ϲ�*/
#define STATE_NOBILL	"1"     /*�ϲ����������*/
#define STATE_BILLED	"2"     /*������*/
#define STATE_COLEND	"3"     /*�ϲ������ѳ��ļ�*/
#define STATE_MID	"4"     /*���ļ���*/
#define STATE_RATED	"5"	/*���س��ļ�*/




/*����ṹ��������*/
struct GsmRateTicketStructOut{

#ifndef GSM_TICKET_RATE_BUFLEN_OUT
#define GSM_TICKET_RATE_BUFLEN_OUT		300
#endif

	struct GsmRateTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������к� */
	char    asTicketID[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* �ֻ����� */
	char    asMsisdn[GSM_TICKET_RATE_BUFLEN_OUT][16];
		/* Imsi���� */
	char    asImsi[GSM_TICKET_RATE_BUFLEN_OUT][16];
		/* ���д��� */
	char    asCityCode[GSM_TICKET_RATE_BUFLEN_OUT][5];
		/* �·� */
	char    asMonth[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* �Ʒ��·� */
	char    asBillMonth[GSM_TICKET_RATE_BUFLEN_OUT][7];
		/* �������� */
	char    asCallType[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* �������� */
	char    asStartTime[GSM_TICKET_RATE_BUFLEN_OUT][15];
		/* ����ԭ�� */
	char    asEndReason[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* ��ȱ��־ */
	char    asDeformFlag[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* �Զ˺��� */
	char    asOtherParty[GSM_TICKET_RATE_BUFLEN_OUT][22];
		/* �Է��������� */
	char    asCalledCode[GSM_TICKET_RATE_BUFLEN_OUT][5];
		/* ͨ��ʱ�� */
	int     aiDuration[GSM_TICKET_RATE_BUFLEN_OUT];
		/* ���������� */
	char    asMsc[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* ��վ�� */
	char    asCellID[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* �Է���վ�� */
	char    asOtherCellID[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* ���м� */
	char    asTrunkIn[GSM_TICKET_RATE_BUFLEN_OUT][8];
		/* ���м� */
	char    asTrunkOut[GSM_TICKET_RATE_BUFLEN_OUT][8];
		/* ��;���� */
	char    asTollType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* �������� */
	char    asRoamType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* ��;������ */
	char    asTollNetType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* ��ֵҵ�� */
	char    asValueAddBusi[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* �պ��û�ȺID */
	char    asGroupID[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* ˫����ͬһ�պ��û�Ⱥ */
	char    asSameGroupFlag[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* ������ */
	char    asHomeProvCode[GSM_TICKET_RATE_BUFLEN_OUT][4];
		/* ���ξ� */
	char    asVisitCityCode[GSM_TICKET_RATE_BUFLEN_OUT][4];
		/* B���� */
	char    asThirdParty[GSM_TICKET_RATE_BUFLEN_OUT][16];
		/* ͨ��/����ҵ����� */
	char    asBusiType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* ͨ��/����ҵ����� */
	char    asBusiCode[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* ������ */
	char    asBaseFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* ��;�� */
	char    asTollFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* ������ */
	char    asTollAddFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* ������ */
	char    asOtherFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* ���η� */
	char    asRoamFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* ���ӷ� */
	char    asAddFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* �Żݻ����� */
	char    asDisctBaseFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* �Żݳ�;�� */
	char    asDisctTollFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* �Żݳ����� */
	char    asDisctTollAddFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* �Ż������� */
	char    asDisctOtherFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* ����ҵ���� */
	char    asSupplementActiveCode[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* ����ҵ���� */
	char    asSupplementCode[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* �ļ��� */
	char    asFileSeq[GSM_TICKET_RATE_BUFLEN_OUT][9];
		/* Called_type */
	char    asCalledType[GSM_TICKET_RATE_BUFLEN_OUT][4];
		/* Home_area_code */
	char    asHomeAreaCode[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* lac */
	char    asLac[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* User_type */
	char    asUserType[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* �����ֶ� */
	char    asReserve[GSM_TICKET_RATE_BUFLEN_OUT][19];
	char    asUpdateDate[GSM_TICKET_RATE_BUFLEN_OUT][15];
	char    asDealDate[GSM_TICKET_RATE_BUFLEN_OUT][15];
	char    asSourceID[GSM_TICKET_RATE_BUFLEN_OUT][41];
};

/*�����ṹ����*/
struct GsmRateTicketStruct{

	struct GsmRateTicketStruct *pNext;
	char    sTicketID[11];		/* �������к� */
	char    sMsisdn[16];		/* �ֻ����� */
	char    sImsi[16];		/* Imsi���� */
	char    sCityCode[5];		/* ���д��� */
	char    sMonth[3];		/* �·� */
	char    sBillMonth[7];		/* �Ʒ��·� */
	char    sCallType[3];		/* �������� */
	char    sStartTime[15];		/* �������� */
	char    sEndReason[2];		/* ����ԭ�� */
	char    sDeformFlag[2];		/* ��ȱ��־ */
	char    sOtherParty[22];		/* �Զ˺��� */
	char    sCalledCode[5];		/* �Է��������� */
	int     iDuration;		/* ͨ��ʱ�� */
	char    sMsc[11];		/* ���������� */
	char    sCellID[6];		/* ��վ�� */
	char    sOtherCellID[6];		/* �Է���վ�� */
	char    sTrunkIn[8];		/* ���м� */
	char    sTrunkOut[8];		/* ���м� */
	char    sTollType[2];		/* ��;���� */
	char    sRoamType[2];		/* �������� */
	char    sTollNetType[2];		/* ��;������ */
	char    sValueAddBusi[3];		/* ��ֵҵ�� */
	char    sGroupID[6];		/* �պ��û�ȺID */
	char    sSameGroupFlag[2];		/* ˫����ͬһ�պ��û�Ⱥ */
	char    sHomeProvCode[4];		/* ������ */
	char    sVisitCityCode[4];		/* ���ξ� */
	char    sThirdParty[16];		/* B���� */
	char    sBusiType[2];		/* ͨ��/����ҵ����� */
	char    sBusiCode[3];		/* ͨ��/����ҵ����� */
	char    sBaseFee[11];		/* ������ */
	char    sTollFee[11];		/* ��;�� */
	char    sTollAddFee[11];		/* ������ */
	char    sOtherFee[11];		/* ������ */
	char    sRoamFee[11];		/* ���η� */
	char    sAddFee[11];		/* ���ӷ� */
	char    sDisctBaseFee[11];		/* �Żݻ����� */
	char    sDisctTollFee[11];		/* �Żݳ�;�� */
	char    sDisctTollAddFee[11];		/* �Żݳ����� */
	char    sDisctOtherFee[11];		/* �Ż������� */
	char    sSupplementActiveCode[2];		/* ����ҵ���� */
	char    sSupplementCode[3];		/* ����ҵ���� */
	char    sFileSeq[9];		/* �ļ��� */
	char    sCalledType[4];		/* Called_type */
	char    sHomeAreaCode[11];		/* Home_area_code */
	char    sLac[6];		/* lac */
	char    sUserType[3];		/* User_type */
	char    sReserve[19];		/* �����ֶ� */
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct GsmRateTicketStruct *pLoadNext;
};

int EInsertStructToGsmRateTicket(struct GsmRateTicketStruct *p,
	int iInsertFlag,struct GsmRateTicketStructOut *pTarget);
void mvitem_fmgsmrateticket(struct FGsmRateTicketStruct *pi,
	struct GsmRateTicketStruct *po);
int InsertGsmBillTicket(char sFileName[],char sTableName[]);

/*����ṹ��������*/
struct SmsRateTicketStructOut{

#ifndef SMS_RATE_TICKET_BUFLEN_OUT
#define SMS_RATE_TICKET_BUFLEN_OUT		300
#endif

	struct SmsRateTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[SMS_RATE_TICKET_BUFLEN_OUT][3];
	char    asCallType[SMS_RATE_TICKET_BUFLEN_OUT][2];
	char    asMsisdn[SMS_RATE_TICKET_BUFLEN_OUT][14];
	char    asUserType[SMS_RATE_TICKET_BUFLEN_OUT][2];
	char    asHomeAreaCode[SMS_RATE_TICKET_BUFLEN_OUT][5];
	char    asCallingNbr[SMS_RATE_TICKET_BUFLEN_OUT][14];
	char    asCalledNbr[SMS_RATE_TICKET_BUFLEN_OUT][14];
	char    asBusiCode[SMS_RATE_TICKET_BUFLEN_OUT][11];
	char    asFeeType[SMS_RATE_TICKET_BUFLEN_OUT][2];
	int     aiMsgLen[SMS_RATE_TICKET_BUFLEN_OUT];
	int     aiMsgCnt[SMS_RATE_TICKET_BUFLEN_OUT];
	char    asStartTime[SMS_RATE_TICKET_BUFLEN_OUT][15];
	int     aiBaseFee[SMS_RATE_TICKET_BUFLEN_OUT];
	int     aiInfoFee[SMS_RATE_TICKET_BUFLEN_OUT];
	int     aiInfoFeeType[SMS_RATE_TICKET_BUFLEN_OUT];
	char    asOriFileName[SMS_RATE_TICKET_BUFLEN_OUT][21];
	char    asReserve[SMS_RATE_TICKET_BUFLEN_OUT][21];
	char    asUpdateDate[SMS_RATE_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMS_RATE_TICKET_BUFLEN_OUT][15];
	char    asSourceID[SMS_RATE_TICKET_BUFLEN_OUT][41];
};

/*�����ṹ����*/
struct SmsRateTicketStruct{

	struct SmsRateTicketStruct *pNext;
	char    sRecordType[3];
	char    sCallType[2];
	char    sMsisdn[14];
	char    sUserType[2];
	char    sHomeAreaCode[5];
	char    sCallingNbr[14];
	char    sCalledNbr[14];
	char    sBusiCode[11];
	char    sFeeType[2];
	int     iMsgLen;
	int     iMsgCnt;
	char    sStartTime[15];
	int     iBaseFee;
	int     iInfoFee;
	int     iInfoFeeType;
	char    sOriFileName[21];
	char    sReserve[21];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct SmsRateTicketStruct *pLoadNext;
};

void mvitem_fmsmsrateticket(struct FSmsRateTicketStruct *pi,
	struct SmsRateTicketStruct *po);
/*�������ݽṹ����д��SMS_RATE_TICKET*/
int EInsertStructToSmsRateTicket(struct SmsRateTicketStruct *p,
	int iInsertFlag,struct SmsRateTicketStructOut *pTarget);
int InsertSmsBillTicket(char sFileName[],char sTableName[]);



/*����ṹ��������*/
struct SmsupTicketStructOut{

#ifndef SMSUP_TICKET_BUFLEN_OUT
#define SMSUP_TICKET_BUFLEN_OUT		300
#endif

	struct SmsupTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[SMSUP_TICKET_BUFLEN_OUT][3];
	char    asMsgType[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asSpProvCode[SMSUP_TICKET_BUFLEN_OUT][4];
	int     aiSmg[SMSUP_TICKET_BUFLEN_OUT];
	int     aiSpCode[SMSUP_TICKET_BUFLEN_OUT];
	int     aiFwSmg[SMSUP_TICKET_BUFLEN_OUT];
	char    asFwSmgProv[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asStartTime[SMSUP_TICKET_BUFLEN_OUT][15];
	char    asMsgCnt[SMSUP_TICKET_BUFLEN_OUT][11];
	char    asBaseFee[SMSUP_TICKET_BUFLEN_OUT][13];
	char    asInfoFee[SMSUP_TICKET_BUFLEN_OUT][13];
	char    asHomeProvCode[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asFileType[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asReserve1[SMSUP_TICKET_BUFLEN_OUT][31];
	char    asState[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asUpdateDate[SMSUP_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMSUP_TICKET_BUFLEN_OUT][15];
	char    asSourceID[SMSUP_TICKET_BUFLEN_OUT][41];
	char    asCurFileName[SMSUP_TICKET_BUFLEN_OUT][31];
};


/*�����ṹ����*/
struct SmsupTicketStruct{

	struct SmsupTicketStruct *pNext;
	char    sRecordType[3];
	char    sMsgType[4];
	char    sSpProvCode[4];
	int     iSmg;
	int     iSpCode;
	int     iFwSmg;
	char    sFwSmgProv[4];
	char    sStartTime[15];
	char    sMsgCnt[11];
	char    sBaseFee[13];
	char    sInfoFee[13];
	char    sHomeProvCode[4];
	char    sFileType[4];
	char    sReserve1[31];
	char    sState[4];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	char    sCurFileName[31];
	struct SmsupTicketStruct *pLoadNext;
};

void mvitem_fmsmsupticket(struct FSmsupTicketStruct *pi,struct SmsupTicketStruct *po);
/*�������ݽṹ����д��SMSUP_TICKET*/
int EInsertStructToSmsupTicket(struct SmsupTicketStruct *p,
	int iInsertFlag,struct SmsupTicketStructOut *pTarget);
int InsertSmsupBillTicket(char sFileName[],char sTableName[]);

/*����ṹ��������*/
struct SmsupIntfTicketStructOut{

#ifndef SMSUP_INTF_TICKET_BUFLEN_OUT
#define SMSUP_INTF_TICKET_BUFLEN_OUT		300
#endif

	struct SmsupIntfTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ���ݼ�¼��ʾ */
	char    asRecordType[SMSUP_INTF_TICKET_BUFLEN_OUT][3];
		/* ��Ϣ���� */
	char    asMsgType[SMSUP_INTF_TICKET_BUFLEN_OUT][4];
		/* SP����ʡ���� */
	int     aiSpProvCode[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* SP����SMG���� */
	int     aiSmg[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* SP���� */
	int     aiSpCode[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* ǰת���ش��� */
	int     aiFwSmg[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* ǰת����ʡ���� */
	int     aiFwSmgProv[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* ���λ��������¼ʱ�� */
	char    asMinStartTime[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
		/* ���λ���������¼ʱ�� */
	char    asMaxStartTime[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MO/MO-F������ */
	char    asMoCnt1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MO/MO-F�������� */
	char    asMoCnt2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MT/MT-F������ */
	char    asMfCnt1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MT/MT-F�������� */
	char    asMfCnt2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĽ����ܷ��� */
	char    asFee1[SMSUP_INTF_TICKET_BUFLEN_OUT][13];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĽ����ܷ��� */
	char    asFee2[SMSUP_INTF_TICKET_BUFLEN_OUT][13];
		/* �Ʒ��û�����ʡ���� */
	int     aiHomeProvCode[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ�ͨ�ŷ��ܷ��� */
	char    asRoamFee1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ�ͨ���ܷ��� */
	char    asRoamFee2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���Ϣ���ܷ��� */
	char    asInfoFee1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���Ϣ���ܷ��� */
	char    asInfoFee2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĲ�����ͨ�ŷ��ܷ��� */
	char    asRoamNfee1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĲ�����ͨ���ܷ��� */
	char    asRoamNfee2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* ����1 */
	char    asReserve1[SMSUP_INTF_TICKET_BUFLEN_OUT][21];
	char    asState[SMSUP_INTF_TICKET_BUFLEN_OUT][4];
	char    asDealDate[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
	char    asUpdateDate[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
	char    asSourceID[SMSUP_INTF_TICKET_BUFLEN_OUT][41];
};
/* ����ṹ��������*/
struct SmsupIntfTicketStructIn{

#ifndef SMSUP_INTF_TICKET_BUFLEN_IN
#define SMSUP_INTF_TICKET_BUFLEN_IN		300
#endif

	struct SmsupIntfTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[SMSUP_INTF_TICKET_BUFLEN_IN][3];
	char    asMsgType[SMSUP_INTF_TICKET_BUFLEN_IN][4];
	int     aiSpProvCode[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiSmg[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiSpCode[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiFwSmg[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiFwSmgProv[SMSUP_INTF_TICKET_BUFLEN_IN];
	char    asMinStartTime[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asMaxStartTime[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asMoCnt1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asMoCnt2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asMfCnt1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asMfCnt2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asFee1[SMSUP_INTF_TICKET_BUFLEN_IN][13];
	char    asFee2[SMSUP_INTF_TICKET_BUFLEN_IN][13];
	int     aiHomeProvCode[SMSUP_INTF_TICKET_BUFLEN_IN];
	char    asRoamFee1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asRoamFee2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asInfoFee1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asInfoFee2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asRoamNfee1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asRoamNfee2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asReserve1[SMSUP_INTF_TICKET_BUFLEN_IN][21];
	char    asState[SMSUP_INTF_TICKET_BUFLEN_IN][4];
	char    asUpdateDate[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asDealDate[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asSourceID[SMSUP_INTF_TICKET_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct SmsupIntfTicketStruct{

	struct SmsupIntfTicketStruct *pNext;
	char    sRecordType[3];		/* ���ݼ�¼��ʾ */
	char    sMsgType[4];		/* ��Ϣ���� */
	int     iSpProvCode;		/* SP����ʡ���� */
	int     iSmg;		/* SP����SMG���� */
	int     iSpCode;		/* SP���� */
	int     iFwSmg;		/* ǰת���ش��� */
	int     iFwSmgProv;		/* ǰת����ʡ���� */
	char    sMinStartTime[15];		/* ���λ��������¼ʱ�� */
	char    sMaxStartTime[15];		/* ���λ���������¼ʱ�� */
	char    sMoCnt1[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MO/MO-F������ */
	char    sMoCnt2[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MO/MO-F�������� */
	char    sMfCnt1[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MT/MT-F������ */
	char    sMfCnt2[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MT/MT-F�������� */
	char    sFee1[13];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĽ����ܷ��� */
	char    sFee2[13];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĽ����ܷ��� */
	int     iHomeProvCode;		/* �Ʒ��û�����ʡ���� */
	char    sRoamFee1[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ�ͨ�ŷ��ܷ��� */
	char    sRoamFee2[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ�ͨ���ܷ��� */
	char    sInfoFee1[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���Ϣ���ܷ��� */
	char    sInfoFee2[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���Ϣ���ܷ��� */
	char    sRoamNfee1[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĲ�����ͨ�ŷ��ܷ��� */
	char    sRoamNfee2[11];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĲ�����ͨ���ܷ��� */
	char    sReserve1[21];		/* ����1 */
	char    sState[4];
	char    sDealDate[15];
	char    sUpdateDate[15];
	char    sSourceID[41];
	struct SmsupIntfTicketStruct *pLoadNext;
};

/*�������ݽṹ����д��SMSUP_INTF_TICKET*/
int EInsertStructToSmsupIntfTicket(struct SmsupIntfTicketStruct *p,
	int iInsertFlag,struct SmsupIntfTicketStructOut *pTarget);
void mvitem_fmsmsupintfticket(struct FSmsupIntfTicketStruct *pi,
	struct SmsupIntfTicketStruct *po);
int InsertSmsupIntfTicket(char sFileName[],char sTableName[]);
int EGetSmsupIntfTicketToStruct(struct SmsupIntfTicketStruct *p,
	struct SmsupIntfTicketStructIn *pSource);
void mvitem_mfsmsupintfticket(struct SmsupIntfTicketStruct *pi,
	struct FSmsupIntfTicketStruct *po);

/*����ṹ��������*/
struct RhjfTicketStructOut{

#ifndef RHJF_TICKET_BUFLEN_OUT
#define RHJF_TICKET_BUFLEN_OUT		300
#endif

	struct RhjfTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asCallType[RHJF_TICKET_BUFLEN_OUT][3];
	char    asTicketType[RHJF_TICKET_BUFLEN_OUT][3];
	char    asMsisdn[RHJF_TICKET_BUFLEN_OUT][16];
	char    asOtherParty[RHJF_TICKET_BUFLEN_OUT][31];
	char    asStartTime[RHJF_TICKET_BUFLEN_OUT][15];
	char    asDuration[RHJF_TICKET_BUFLEN_OUT][7];
	char    asMsc[RHJF_TICKET_BUFLEN_OUT][16];
	char    asTrunkIn[RHJF_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[RHJF_TICKET_BUFLEN_OUT][8];
	char    asBaseCharge[RHJF_TICKET_BUFLEN_OUT][9];
	char    asLandCharge[RHJF_TICKET_BUFLEN_OUT][9];
	char    asOtherCharge[RHJF_TICKET_BUFLEN_OUT][9];
	char    asLandType[RHJF_TICKET_BUFLEN_OUT][2];
	char    asVisitAreaCode[RHJF_TICKET_BUFLEN_OUT][6];
	char    asHomeAreaCode[RHJF_TICKET_BUFLEN_OUT][6];
	char    asCalledAreaCode[RHJF_TICKET_BUFLEN_OUT][6];
	char    asUpdateDate[RHJF_TICKET_BUFLEN_OUT][15];
	char    asDealDate[RHJF_TICKET_BUFLEN_OUT][15];
	char    asSourceID[RHJF_TICKET_BUFLEN_OUT][41];
};


/*�����ṹ����*/
struct RhjfTicketStruct{

	struct RhjfTicketStruct *pNext;
	char    sCallType[3];
	char    sTicketType[3];
	char    sMsisdn[16];
	char    sOtherParty[31];
	char    sStartTime[15];
	char    sDuration[7];
	char    sMsc[16];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sBaseCharge[9];
	char    sLandCharge[9];
	char    sOtherCharge[9];
	char    sLandType[2];
	char    sVisitAreaCode[6];
	char    sHomeAreaCode[6];
	char    sCalledAreaCode[6];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct RhjfTicketStruct *pLoadNext;
};
/*�������ݽṹ����д��RHJF_TICKET*/
int EInsertStructToRhjfTicket(struct RhjfTicketStruct *p,
	int iInsertFlag,struct RhjfTicketStructOut *pTarget);
void mvitem_fmrhjfticket(struct FRhjfTicketStruct *pi,struct RhjfTicketStruct *po);
int InsertRhjfBillTicket(char sFileName[],char sTableName[]);

/***********�������ۺ��ı�*********************/
/*����ṹ��������*/
struct SmsTicketStructOut{

#ifndef SMS_TICKET_BUFLEN_OUT
#define SMS_TICKET_BUFLEN_OUT		300
#endif

	struct SmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SMS_TICKET_BUFLEN_OUT];
		/* �������� */
	char     asCallType[SMS_TICKET_BUFLEN_OUT][3];
		/* �û��������� */
	char    asHomeAreaCode[SMS_TICKET_BUFLEN_OUT][6];
		/* �û����� */
	char    asMsisdn[SMS_TICKET_BUFLEN_OUT][16];
		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    asCalledCode[SMS_TICKET_BUFLEN_OUT][6];
		/* �Զ˺��� */
	char    asOtherParty[SMS_TICKET_BUFLEN_OUT][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[SMS_TICKET_BUFLEN_OUT][15];
		/* ��Ϣ���� */
	int     aiMsgLen[SMS_TICKET_BUFLEN_OUT];
		/* ��ϢID */
	char    asMsgID[SMS_TICKET_BUFLEN_OUT][31];
		/* �������� */
	char    asSmsc[SMS_TICKET_BUFLEN_OUT][16];
		/* �������� */
	char    asSmg[SMS_TICKET_BUFLEN_OUT][16];
		/* ǰת�������� */
	char    asTsmg[SMS_TICKET_BUFLEN_OUT][16];
		/* G,C */
	char    asUserType[SMS_TICKET_BUFLEN_OUT][2];
		/* �Զ����� */
	char    asCalledType[SMS_TICKET_BUFLEN_OUT][3];

	char    asSpAccNbr[SMS_TICKET_BUFLEN_OUT][13];
		/* SPҵ����� */
	char    asSpServiceCode[SMS_TICKET_BUFLEN_OUT][11];
		/* SP���� */
	char    asSpCode[SMS_TICKET_BUFLEN_OUT][6];
		/* ͨ�ŷ� */
	int     aiBaseFee[SMS_TICKET_BUFLEN_OUT];
		/* ��Ϣ�� */
	int     aiInfoFee[SMS_TICKET_BUFLEN_OUT];
		/* ���·� */
	int     aiRentFee[SMS_TICKET_BUFLEN_OUT];
		/* ������ */
	int     aiOtherFee[SMS_TICKET_BUFLEN_OUT];
		/* �������� */
	int     aiInFee[SMS_TICKET_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutFee[SMS_TICKET_BUFLEN_OUT];

	char	asOriCallType[SMS_TICKET_BUFLEN_OUT][3];
	char	asReserve[SMS_TICKET_BUFLEN_OUT][11];

	char	asSpProvCode[SMS_TICKET_BUFLEN_OUT][4];
	char	asHomeProvCode[SMS_TICKET_BUFLEN_OUT][4];
	char	asScpFlag[SMS_TICKET_BUFLEN_OUT][2];
	int     aiCallingTypeID[SMS_TICKET_BUFLEN_OUT];
	char	asBillType[SMS_TICKET_BUFLEN_OUT][2];

		/* ������� */
	char    asErrCode[SMS_TICKET_BUFLEN_OUT][5];
		/* �ļ��� */
	char    asFileName[SMS_TICKET_BUFLEN_OUT][20];
		/* ģ�� */
	char    asModule[SMS_TICKET_BUFLEN_OUT][4];
		/* ���� */
	char    asAreaCode[SMS_TICKET_BUFLEN_OUT][6];
		/* ״̬ */
	char    asState[SMS_TICKET_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asUpdateDate[SMS_TICKET_BUFLEN_OUT][15];
		/* ����ʱ�� */
	char    asDealDate[SMS_TICKET_BUFLEN_OUT][15];
		/* ��Դ */
	char    asSourceID[SMS_TICKET_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct SmsTicketStructIn{

#ifndef SMS_TICKET_BUFLEN_IN
#define SMS_TICKET_BUFLEN_IN		300
#endif

	struct SmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SMS_TICKET_BUFLEN_IN];
		/* �������� */
	char     asCallType[SMS_TICKET_BUFLEN_IN][3];
		/* �û��������� */
	char    asHomeAreaCode[SMS_TICKET_BUFLEN_IN][6];
		/* �û����� */
	char    asMsisdn[SMS_TICKET_BUFLEN_IN][16];
		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    asCalledCode[SMS_TICKET_BUFLEN_IN][6];
		/* �Զ˺��� */
	char    asOtherParty[SMS_TICKET_BUFLEN_IN][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[SMS_TICKET_BUFLEN_IN][15];
		/* ��Ϣ���� */
	int     aiMsgLen[SMS_TICKET_BUFLEN_IN];
		/* ��ϢID */
	char    asMsgID[SMS_TICKET_BUFLEN_IN][31];
		/* �������� */
	char    asSmsc[SMS_TICKET_BUFLEN_IN][16];
		/* �������� */
	char    asSmg[SMS_TICKET_BUFLEN_IN][16];
		/* ǰת�������� */
	char    asTsmg[SMS_TICKET_BUFLEN_IN][16];
		/* G,C */
	char    asUserType[SMS_TICKET_BUFLEN_IN][2];
		/* �Զ����� */
	char    asCalledType[SMS_TICKET_BUFLEN_IN][3];

	char    asSpAccNbr[SMS_TICKET_BUFLEN_IN][13];
		/* SPҵ����� */
	char    asSpServiceCode[SMS_TICKET_BUFLEN_IN][11];
		/* SP���� */
	char    asSpCode[SMS_TICKET_BUFLEN_IN][6];
		/* ͨ�ŷ� */
	int     aiBaseFee[SMS_TICKET_BUFLEN_IN];
		/* ��Ϣ�� */
	int     aiInfoFee[SMS_TICKET_BUFLEN_IN];
		/* ���·� */
	int     aiRentFee[SMS_TICKET_BUFLEN_IN];
		/* ������ */
	int     aiOtherFee[SMS_TICKET_BUFLEN_IN];
		/* �������� */
	int     aiInFee[SMS_TICKET_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutFee[SMS_TICKET_BUFLEN_IN];

	char	asOriCallType[SMS_TICKET_BUFLEN_IN][3];
	char	asReserve[SMS_TICKET_BUFLEN_IN][11];

	char	asSpProvCode[SMS_TICKET_BUFLEN_IN][4];
	char	asHomeProvCode[SMS_TICKET_BUFLEN_IN][4];
	char	asScpFlag[SMS_TICKET_BUFLEN_IN][2];
	int     aiCallingTypeID[SMS_TICKET_BUFLEN_IN];
	char	asBillType[SMS_TICKET_BUFLEN_IN][2];

		/* ������� */
	char    asErrCode[SMS_TICKET_BUFLEN_IN][5];
		/* �ļ��� */
	char    asFileName[SMS_TICKET_BUFLEN_IN][20];
		/* ģ�� */
	char    asModule[SMS_TICKET_BUFLEN_IN][4];
		/* ���� */
	char    asAreaCode[SMS_TICKET_BUFLEN_IN][6];
		/* ״̬ */
	char    asState[SMS_TICKET_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asUpdateDate[SMS_TICKET_BUFLEN_IN][15];
		/* ����ʱ�� */
	char    asDealDate[SMS_TICKET_BUFLEN_IN][15];
		/* ��Դ */
	char    asSourceID[SMS_TICKET_BUFLEN_IN][41];
	char	asRowID[SMS_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct SmsTicketStruct{

	struct SmsTicketStruct *pNext;
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sCallType[3];		/* �������� */
	char    sHomeAreaCode[6];		/* �û��������� */
	char    sMsisdn[16];		/* �û����� */
	char    sCalledCode[6];		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	int     iMsgLen;		/* ��Ϣ���� */
	char    sMsgID[31];		/* ��ϢID */
	char    sSmsc[16];		/* �������� */
	char    sSmg[16];		/* �������� */
	char    sTsmg[16];		/* ǰת�������� */
	char    sUserType[2];		/* G,C */
	char    sCalledType[3];		/* �Զ����� */
	char    sSpAccNbr[13];		/* SPҵ����� */
	char    sSpServiceCode[11];		/* SPҵ����� */
	char    sSpCode[6];		/* SP���� */
	int     iBaseFee;		/* ͨ�ŷ� */
	int     iInfoFee;		/* ��Ϣ�� */
	int     iRentFee;		/* ���·� */
	int     iOtherFee;		/* ������ */
	int     iInFee;		/* �������� */
	int     iOutFee;		/* ����֧�� */
	char	sOriCallType[3];
	char	sReserve[11];

	char	sSpProvCode[4];
	char	sHomeProvCode[4];
	char	sScpFlag[2];
	int     iCallingTypeID;
	char	sBillType[2];

	char    sErrCode[5];		/* ������� */
	char    sFileName[20];		/* �ļ��� */
	char    sModule[4];		/* ģ�� */
	char    sAreaCode[6];		/* ���� */
	char    sState[2];		/* ״̬ */
	char    sUpdateDate[15];		/* ����ʱ�� */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* ��Դ */
	char	sRowID[19];
	struct SmsTicketStruct *pLoadNext;
};

/*�������ݽṹ����д��SMS_TICKET*/
int EInsertStructToSmsTicket(struct SmsTicketStruct *p,
	int iInsertFlag,struct SmsTicketStructOut *pTarget);
void mvitem_fmsmsticket(struct FSmsTicketStruct *pi,
	int len,struct SmsTicketStruct *po);
int InsertSmsTicket(char sFileName[],char sTableName[]);
/*�������ݶ�̬��SMS_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmsTicketToStruct(struct SmsTicketStruct *p,
	struct SmsTicketStructIn *pSource);
void mvitem_mfsmsticket(struct SmsTicketStruct *pi,struct FSmsTicketStruct *po);


/* ����ṹ��������*/
struct NsmsTicketStructIn{

#ifndef NSMS_TICKET_BUFLEN_IN
#define NSMS_TICKET_BUFLEN_IN		1000
#endif

	struct NsmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[NSMS_TICKET_BUFLEN_IN];
		/* �������� */
	char    asCallType[NSMS_TICKET_BUFLEN_IN][3];
		/* �û��������� */
	char    asHomeAreaCode[NSMS_TICKET_BUFLEN_IN][6];
		/* �û����� */
	char    asMsisdn[NSMS_TICKET_BUFLEN_IN][16];
		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    asCalledCode[NSMS_TICKET_BUFLEN_IN][6];
		/* �Զ˺��� */
	char    asOtherParty[NSMS_TICKET_BUFLEN_IN][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[NSMS_TICKET_BUFLEN_IN][15];
		/* ��Ϣ���� */
	int     aiMsgLen[NSMS_TICKET_BUFLEN_IN];
		/* ��ϢID */
	char    asMsgID[NSMS_TICKET_BUFLEN_IN][31];
		/* �Զ���ϢID */
	char    asOppMsgID[NSMS_TICKET_BUFLEN_IN][31];
		/* ��ҵ������ */
	char    asSubType[NSMS_TICKET_BUFLEN_IN][2];
		/* �������� */
	char    asSmsc[NSMS_TICKET_BUFLEN_IN][16];
		/* �������� */
	char    asSmg[NSMS_TICKET_BUFLEN_IN][16];
		/* ǰת�������� */
	char    asTsmg[NSMS_TICKET_BUFLEN_IN][16];
		/* G,C */
	char    asUserType[NSMS_TICKET_BUFLEN_IN][2];
		/* �Զ����� */
	char    asCalledType[NSMS_TICKET_BUFLEN_IN][3];
		/* SP������� */
	char    asSpAccNbr[NSMS_TICKET_BUFLEN_IN][13];
		/* SPҵ����� */
	char    asSpServiceCode[NSMS_TICKET_BUFLEN_IN][11];
		/* SP���� */
	char    asSpCode[NSMS_TICKET_BUFLEN_IN][11];
		/* ͨ�ŷ� */
	int     aiBaseFee[NSMS_TICKET_BUFLEN_IN];
		/* ��Ϣ�� */
	int     aiInfoFee[NSMS_TICKET_BUFLEN_IN];
		/* ���·� */
	int     aiRentFee[NSMS_TICKET_BUFLEN_IN];
		/* ������ */
	int     aiOtherFee[NSMS_TICKET_BUFLEN_IN];
		/* �������� */
	int     aiInFee[NSMS_TICKET_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutFee[NSMS_TICKET_BUFLEN_IN];
		/* ԭ�������� */
	char    asOriCallType[NSMS_TICKET_BUFLEN_IN][3];
		/* ���� */
	char    asReserve[NSMS_TICKET_BUFLEN_IN][11];
		/* SP����ʡ���� */
	char    asSpProvCode[NSMS_TICKET_BUFLEN_IN][4];
		/* �û�����ʡ���� */
	char    asHomeProvCode[NSMS_TICKET_BUFLEN_IN][4];
		/* ��������־ */
	char    asScpFlag[NSMS_TICKET_BUFLEN_IN][2];
		/* �û���ͷ���� */
	int     aiCallingTypeID[NSMS_TICKET_BUFLEN_IN];
		/* �Ʒ����� */
	char    asBillType[NSMS_TICKET_BUFLEN_IN][2];
		/* ������� */
	char    asErrCode[NSMS_TICKET_BUFLEN_IN][5];
		/* �ļ��� */
	char    asFileName[NSMS_TICKET_BUFLEN_IN][20];
		/* ģ�� */
	char    asModule[NSMS_TICKET_BUFLEN_IN][4];
		/* ���� */
	char    asAreaCode[NSMS_TICKET_BUFLEN_IN][6];
		/* ״̬ */
	char    asState[NSMS_TICKET_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asUpdateDate[NSMS_TICKET_BUFLEN_IN][15];
		/* ����ʱ�� */
	char    asDealDate[NSMS_TICKET_BUFLEN_IN][15];
		/* ��Դ */
	char    asSourceID[NSMS_TICKET_BUFLEN_IN][41];
	char	asRowID[NSMS_TICKET_BUFLEN_IN][19];
};


/*����ṹ��������*/
struct NsmsTicketStructOut{

#ifndef NSMS_TICKET_BUFLEN_OUT
#define NSMS_TICKET_BUFLEN_OUT		1000
#endif

	struct NsmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[NSMS_TICKET_BUFLEN_OUT];
		/* �������� */
	char    asCallType[NSMS_TICKET_BUFLEN_OUT][3];
		/* �û��������� */
	char    asHomeAreaCode[NSMS_TICKET_BUFLEN_OUT][6];
		/* �û����� */
	char    asMsisdn[NSMS_TICKET_BUFLEN_OUT][16];
		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    asCalledCode[NSMS_TICKET_BUFLEN_OUT][6];
		/* �Զ˺��� */
	char    asOtherParty[NSMS_TICKET_BUFLEN_OUT][25];
		/* Ӧ��ʱ�� */
	char    asStartTime[NSMS_TICKET_BUFLEN_OUT][15];
		/* ��Ϣ���� */
	int     aiMsgLen[NSMS_TICKET_BUFLEN_OUT];
		/* ��ϢID */
	char    asMsgID[NSMS_TICKET_BUFLEN_OUT][31];
		/* �Զ���ϢID */
	char    asOppMsgID[NSMS_TICKET_BUFLEN_OUT][31];
		/* ��ҵ������ */
	char    asSubType[NSMS_TICKET_BUFLEN_OUT][2];
		/* �������� */
	char    asSmsc[NSMS_TICKET_BUFLEN_OUT][16];
		/* �������� */
	char    asSmg[NSMS_TICKET_BUFLEN_OUT][16];
		/* ǰת�������� */
	char    asTsmg[NSMS_TICKET_BUFLEN_OUT][16];
		/* G,C */
	char    asUserType[NSMS_TICKET_BUFLEN_OUT][2];
		/* �Զ����� */
	char    asCalledType[NSMS_TICKET_BUFLEN_OUT][3];
		/* SP������� */
	char    asSpAccNbr[NSMS_TICKET_BUFLEN_OUT][13];
		/* SPҵ����� */
	char    asSpServiceCode[NSMS_TICKET_BUFLEN_OUT][11];
		/* SP���� */
	char    asSpCode[NSMS_TICKET_BUFLEN_OUT][11];
		/* ͨ�ŷ� */
	int     aiBaseFee[NSMS_TICKET_BUFLEN_OUT];
		/* ��Ϣ�� */
	int     aiInfoFee[NSMS_TICKET_BUFLEN_OUT];
		/* ���·� */
	int     aiRentFee[NSMS_TICKET_BUFLEN_OUT];
		/* ������ */
	int     aiOtherFee[NSMS_TICKET_BUFLEN_OUT];
		/* �������� */
	int     aiInFee[NSMS_TICKET_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutFee[NSMS_TICKET_BUFLEN_OUT];
		/* ԭ�������� */
	char    asOriCallType[NSMS_TICKET_BUFLEN_OUT][3];
		/* ���� */
	char    asReserve[NSMS_TICKET_BUFLEN_OUT][11];
		/* SP����ʡ���� */
	char    asSpProvCode[NSMS_TICKET_BUFLEN_OUT][4];
		/* �û�����ʡ���� */
	char    asHomeProvCode[NSMS_TICKET_BUFLEN_OUT][4];
		/* ��������־ */
	char    asScpFlag[NSMS_TICKET_BUFLEN_OUT][2];
		/* �û���ͷ���� */
	int     aiCallingTypeID[NSMS_TICKET_BUFLEN_OUT];
		/* �Ʒ����� */
	char    asBillType[NSMS_TICKET_BUFLEN_OUT][2];
		/* ������� */
	char    asErrCode[NSMS_TICKET_BUFLEN_OUT][5];
		/* �ļ��� */
	char    asFileName[NSMS_TICKET_BUFLEN_OUT][20];
		/* ģ�� */
	char    asModule[NSMS_TICKET_BUFLEN_OUT][4];
		/* ���� */
	char    asAreaCode[NSMS_TICKET_BUFLEN_OUT][6];
		/* ״̬ */
	char    asState[NSMS_TICKET_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asUpdateDate[NSMS_TICKET_BUFLEN_OUT][15];
		/* ����ʱ�� */
	char    asDealDate[NSMS_TICKET_BUFLEN_OUT][15];
		/* ��Դ */
	char    asSourceID[NSMS_TICKET_BUFLEN_OUT][41];
};




/*�����ṹ����*/
struct NsmsTicketStruct{

	struct NsmsTicketStruct *pNext;
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sCallType[3];		/* �������� */
	char    sHomeAreaCode[6];		/* �û��������� */
	char    sMsisdn[16];		/* �û����� */
	char    sCalledCode[6];		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sStartTime[15];		/* Ӧ��ʱ�� */
	int     iMsgLen;		/* ��Ϣ���� */
	char    sMsgID[31];		/* ��ϢID */
	char    sOppMsgID[31];		/* �Զ���ϢID */
	char    sSubType[2];		/* ��ҵ������ */
	char    sSmsc[16];		/* �������� */
	char    sSmg[16];		/* �������� */
	char    sTsmg[16];		/* ǰת�������� */
	char    sUserType[2];		/* G,C */
	char    sCalledType[3];		/* �Զ����� */
	char    sSpAccNbr[13];		/* SP������� */
	char    sSpServiceCode[11];		/* SPҵ����� */
	char    sSpCode[11];		/* SP���� */
	int     iBaseFee;		/* ͨ�ŷ� */
	int     iInfoFee;		/* ��Ϣ�� */
	int     iRentFee;		/* ���·� */
	int     iOtherFee;		/* ������ */
	int     iInFee;		/* �������� */
	int     iOutFee;		/* ����֧�� */
	char    sOriCallType[3];		/* ԭ�������� */
	char    sReserve[11];		/* ���� */
	char    sSpProvCode[4];		/* SP����ʡ���� */
	char    sHomeProvCode[4];		/* �û�����ʡ���� */
	char    sScpFlag[2];		/* ��������־ */
	int     iCallingTypeID;		/* �û���ͷ���� */
	char    sBillType[2];		/* �Ʒ����� */
	char    sErrCode[5];		/* ������� */
	char    sFileName[20];		/* �ļ��� */
	char    sModule[4];		/* ģ�� */
	char    sAreaCode[6];		/* ���� */
	char    sState[2];		/* ״̬ */
	char    sUpdateDate[15];		/* ����ʱ�� */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* ��Դ */
	char	sRowID[19];
	struct NsmsTicketStruct *pLoadNext;
};




/*�������ݶ�̬��NSMS_TICKET���ýṹ���巽ʽȡ����*/
int EGetNsmsTicketToStruct(struct NsmsTicketStruct *p,
	struct NsmsTicketStructIn *pSource);
void mvitem_mfnsmsticket(struct NsmsTicketStruct *pi,
	struct FNsmsTicketStruct *po);
/*�������ݽṹ����д��NSMS_TICKET*/
int EInsertStructToNsmsTicket(struct NsmsTicketStruct *p,
	int iInsertFlag,struct NsmsTicketStructOut *pTarget);
void mvitem_fmnsmsticket(struct FNsmsTicketStruct *pi,
	int len,struct NsmsTicketStruct *po);

int InsertNsmsTicket(char sFileName[],char sTableName[]);

/****���������ڻ����ȶ��õĶ���***/





/*����ṹ��������*/
struct TelecomTicketStructOut{

#ifndef TELECOM_TICKET_BUFLEN_OUT
#define TELECOM_TICKET_BUFLEN_OUT		300
#endif

	struct TelecomTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asCallingAreaCode[TELECOM_TICKET_BUFLEN_OUT][10];
		/* ���к��� */
	char    asCallingNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* �������� */
	char    asCalledAreaCode[TELECOM_TICKET_BUFLEN_OUT][10];
		/* ���к��� */
	char    asCalledNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* ͨ��ʱ�� */
	char    asStartTime[TELECOM_TICKET_BUFLEN_OUT][15];
		/* ͨ��ʱ�� */
	int     aiDuration[TELECOM_TICKET_BUFLEN_OUT];
		/* ������� */
	int     aiCharge[TELECOM_TICKET_BUFLEN_OUT];
		/* ������Ŀ */
	int     aiTalkTypeID[TELECOM_TICKET_BUFLEN_OUT];
		/* ԭʼ�������� */
	char    asOCallingNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* ԭʼ�������� */
	char    asOCalledNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* ���м� */
	char    asTrunkIn[TELECOM_TICKET_BUFLEN_OUT][8];
		/* ���м� */
	char    asTrunkOut[TELECOM_TICKET_BUFLEN_OUT][8];
};


/* ����ṹ��������*/
struct TelecomTicketStructIn{

#ifndef TELECOM_TICKET_BUFLEN_IN
#define TELECOM_TICKET_BUFLEN_IN		300
#endif

	struct TelecomTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asCallingAreaCode[TELECOM_TICKET_BUFLEN_IN][10];
		/* ���к��� */
	char    asCallingNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* �������� */
	char    asCalledAreaCode[TELECOM_TICKET_BUFLEN_IN][10];
		/* ���к��� */
	char    asCalledNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* ͨ��ʱ�� */
	char    asStartTime[TELECOM_TICKET_BUFLEN_IN][15];
		/* ͨ��ʱ�� */
	int     aiDuration[TELECOM_TICKET_BUFLEN_IN];
		/* ������� */
	int     aiCharge[TELECOM_TICKET_BUFLEN_IN];
		/* ������Ŀ */
	int     aiTalkTypeID[TELECOM_TICKET_BUFLEN_IN];
		/* ԭʼ�������� */
	char    asOCallingNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* ԭʼ�������� */
	char    asOCalledNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* ���м� */
	char    asTrunkIn[TELECOM_TICKET_BUFLEN_IN][8];
		/* ���м� */
	char    asTrunkOut[TELECOM_TICKET_BUFLEN_IN][8];
};


/*�����ṹ����*/
struct TelecomTicketStruct{

	struct TelecomTicketStruct *pNext;
	char    sCallingAreaCode[10];		/* �������� */
	char    sCallingNbr[25];		/* ���к��� */
	char    sCalledAreaCode[10];		/* �������� */
	char    sCalledNbr[25];		/* ���к��� */
	char    sStartTime[15];		/* ͨ��ʱ�� */
	int     iDuration;		/* ͨ��ʱ�� */
	int     iCharge;		/* ������� */
	int     iTalkTypeID;		/* ������Ŀ */
	char    sOCallingNbr[25];		/* ԭʼ�������� */
	char    sOCalledNbr[25];		/* ԭʼ�������� */
	char    sTrunkIn[8];		/* ���м� */
	char    sTrunkOut[8];		/* ���м� */
	char	sState[1];	/*MODIFYHERE*/
	time_t	tStartTime;
	struct TelecomTicketStruct *pLoadNext;
};

/*�������ݶ�̬��TELECOM_TICKET���ýṹ���巽ʽȡ����*/
int EGetTelecomTicketToStruct(struct TelecomTicketStruct *p,
	struct TelecomTicketStructIn *pSource);
/*�������ݽṹ����д��TELECOM_TICKET*/
int EInsertStructToTelecomTicket(struct TelecomTicketStruct *p,
	int iInsertFlag,struct TelecomTicketStructOut *pTarget);
	
/* ����ṹ��������*/
struct DmpTicketStructIn{

#ifndef DMP_TICKET_BUFLEN_IN
#define DMP_TICKET_BUFLEN_IN		300
#endif

	struct DmpTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asCallType[DMP_TICKET_BUFLEN_IN][3];
		/* �û����� */
	char    asMsisdn[DMP_TICKET_BUFLEN_IN][16];
		/* �Զ˺��� */
	char    asOtherParty[DMP_TICKET_BUFLEN_IN][41];
		/* ͨ��ʱ�� */
	char    asStartTime[DMP_TICKET_BUFLEN_IN][15];
		/* ͨ��ʱ�� */
	char    asDuration[DMP_TICKET_BUFLEN_IN][7];
		/* ͨ��λ�� */
	char    asLocation[DMP_TICKET_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct DmpTicketStruct{

	struct DmpTicketStruct *pNext;
	char    sCallType[3];		/* �������� */
	char    sMsisdn[16];		/* �û����� */
	char    sOtherParty[41];		/* �Զ˺��� */
	char    sStartTime[15];		/* ͨ��ʱ�� */
	char    sDuration[7];		/* ͨ��ʱ�� */
	char    sLocation[41];		/* ͨ��λ�� */
	struct DmpTicketStruct *pLoadNext;
};

/*�������ݶ�̬��DMP_TICKET���ýṹ���巽ʽȡ����*/
int EGetDmpTicketToStruct(struct DmpTicketStruct *p,
	struct DmpTicketStructIn *pSource);

/*********����ԭʼ������ͳ�ơ�SP�����****/
/* ����ṹ��������*/
struct SmcdmaTicketStructIn{

#ifndef SMCDMA_TICKET_BUFLEN_IN
#define SMCDMA_TICKET_BUFLEN_IN		300
#endif

	struct SmcdmaTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��ˮ�� */
	char    asRecNo[SMCDMA_TICKET_BUFLEN_IN][16];
		/* �������� */
	char    asCallType[SMCDMA_TICKET_BUFLEN_IN][3];
		/* ���к��� */
	char    asCallingNbr[SMCDMA_TICKET_BUFLEN_IN][25];
		/* ���к��� */
	char    asCalledNbr[SMCDMA_TICKET_BUFLEN_IN][25];
		/* ����ʱ�� */
	char    asRegisterTime[SMCDMA_TICKET_BUFLEN_IN][15];
		/* ��������ʱ�� */
	char    asSendTime[SMCDMA_TICKET_BUFLEN_IN][15];
		/* ��Ϣ���� */
	int     aiMsgLen[SMCDMA_TICKET_BUFLEN_IN];
		/* ���ŷ���״̬ */
	char    asLastStatus[SMCDMA_TICKET_BUFLEN_IN][6];
		/* ҵ������ */
	char    asServiceType[SMCDMA_TICKET_BUFLEN_IN][4];
		/* ҵ����� */
	char    asServiceCode[SMCDMA_TICKET_BUFLEN_IN][5];
		/* ���뷽ʽ */
	char    asLandType[SMCDMA_TICKET_BUFLEN_IN][2];
		/* ���ȼ� */
	char    asPriority[SMCDMA_TICKET_BUFLEN_IN][3];
};


/*�����ṹ����*/
struct SmcdmaTicketStruct{

	struct SmcdmaTicketStruct *pNext;
	char    sRecNo[16];		/* ��ˮ�� */
	char    sCallType[3];		/* �������� */
	char    sCallingNbr[25];		/* ���к��� */
	char    sCalledNbr[25];		/* ���к��� */
	char    sRegisterTime[15];		/* ����ʱ�� */
	char    sSendTime[15];		/* ��������ʱ�� */
	int     iMsgLen;		/* ��Ϣ���� */
	char    sLastStatus[6];		/* ���ŷ���״̬ */
	char    sServiceType[4];		/* ҵ������ */
	char    sServiceCode[5];		/* ҵ����� */
	char    sLandType[2];		/* ���뷽ʽ */
	char    sPriority[3];		/* ���ȼ� */
	struct SmcdmaTicketStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FSmcdmaTicketStruct{

	char    sRecNo[15];		/* ��ˮ�� */
	char    sCallType[2];		/* �������� */
	char    sCallingNbr[24];		/* ���к��� */
	char    sCalledNbr[24];		/* ���к��� */
	char    sRegisterTime[14];		/* ����ʱ�� */
	char    sSendTime[14];		/* ��������ʱ�� */
	char    sMsgLen[3];		/* ��Ϣ���� */
	char    sLastStatus[5];		/* ���ŷ���״̬ */
	char    sServiceType[3];		/* ҵ������ */
	char    sServiceCode[4];		/* ҵ����� */
	char    sLandType[1];		/* ���뷽ʽ */
	char    sPriority[2];		/* ���ȼ� */
};
/*�������ݶ�̬��SMCDMA_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmcdmaTicketToStruct(struct SmcdmaTicketStruct *p,
	struct SmcdmaTicketStructIn *pSource);
void mvitem_mfsmcdmaticket(struct SmcdmaTicketStruct *pi,struct FSmcdmaTicketStruct *po);

/* ����ṹ��������*/
struct SmgsmTicketStructIn{

#ifndef SMGSM_TICKET_BUFLEN_IN
#define SMGSM_TICKET_BUFLEN_IN		300
#endif

	struct SmgsmTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��ˮ�� */
	char    asReqNo[SMGSM_TICKET_BUFLEN_IN][19];
		/* ��Ϣ��ʶ */
	char    asMsgID[SMGSM_TICKET_BUFLEN_IN][11];
		/* ���к��� */
	char    asCallingNbr[SMGSM_TICKET_BUFLEN_IN][21];
		/* CALLING_TON */
	char    asCallingTon[SMGSM_TICKET_BUFLEN_IN][4];
		/* CALLING_NPI */
	char    asCallingNpi[SMGSM_TICKET_BUFLEN_IN][4];
		/* ���к��� */
	char    asCalledNbr[SMGSM_TICKET_BUFLEN_IN][21];
		/* CALLED_TON */
	char    asCalledTon[SMGSM_TICKET_BUFLEN_IN][4];
		/* CALLED_NPI */
	char    asCalledNpi[SMGSM_TICKET_BUFLEN_IN][4];
		/* ����ʱ�� */
	char    asRegisterTime[SMGSM_TICKET_BUFLEN_IN][20];
		/* ���ͽ���ʱ�� */
	char    asSendTime[SMGSM_TICKET_BUFLEN_IN][20];
		/* ���ȼ� */
	char    asPriority[SMGSM_TICKET_BUFLEN_IN][4];
		/* SSR */
	char    asSsr[SMGSM_TICKET_BUFLEN_IN][4];
		/* PID */
	char    asPid[SMGSM_TICKET_BUFLEN_IN][4];
		/* DCS */
	char    asDcs[SMGSM_TICKET_BUFLEN_IN][4];
		/* ��Ϣ���� */
	int     aiMsgLen[SMGSM_TICKET_BUFLEN_IN];
		/* ��������״̬ */
	char    asLastStatus[SMGSM_TICKET_BUFLEN_IN][4];
		/* ������� */
	char    asErrCode[SMGSM_TICKET_BUFLEN_IN][4];
		/* ��Ϣ���� */
	char    asMsgType[SMGSM_TICKET_BUFLEN_IN][5];
		/* ҵ������ */
	char    asServiceType[SMGSM_TICKET_BUFLEN_IN][6];
		/* PPS��־ */
	char    asPpsFlag[SMGSM_TICKET_BUFLEN_IN][2];
		/* ORG_ACCOUNT */
	char    asOrgAccount[SMGSM_TICKET_BUFLEN_IN][11];
		/* DEST_ACCOUNT */
	char    asDestAccount[SMGSM_TICKET_BUFLEN_IN][11];
		/* ��Ȩ��� */
	char    asRightResult[SMGSM_TICKET_BUFLEN_IN][11];
		/* UDHI */
	char    asUdhi[SMGSM_TICKET_BUFLEN_IN][2];
		/* MR */
	char    asMr[SMGSM_TICKET_BUFLEN_IN][2];
		/* RN */
	char    asRn[SMGSM_TICKET_BUFLEN_IN][3];
		/* MN */
	char    asMn[SMGSM_TICKET_BUFLEN_IN][2];
		/* SN */
	char    asSn[SMGSM_TICKET_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct SmgsmTicketStruct{

	struct SmgsmTicketStruct *pNext;
	char    sReqNo[19];		/* ��ˮ�� */
	char    sMsgID[11];		/* ��Ϣ��ʶ */
	char    sCallingNbr[21];		/* ���к��� */
	char    sCallingTon[4];		/* CALLING_TON */
	char    sCallingNpi[4];		/* CALLING_NPI */
	char    sCalledNbr[21];		/* ���к��� */
	char    sCalledTon[4];		/* CALLED_TON */
	char    sCalledNpi[4];		/* CALLED_NPI */
	char    sRegisterTime[20];		/* ����ʱ�� */
	char    sSendTime[20];		/* ���ͽ���ʱ�� */
	char    sPriority[4];		/* ���ȼ� */
	char    sSsr[4];		/* SSR */
	char    sPid[4];		/* PID */
	char    sDcs[4];		/* DCS */
	int     iMsgLen;		/* ��Ϣ���� */
	char    sLastStatus[4];		/* ��������״̬ */
	char    sErrCode[4];		/* ������� */
	char    sMsgType[5];		/* ��Ϣ���� */
	char    sServiceType[6];		/* ҵ������ */
	char    sPpsFlag[2];		/* PPS��־ */
	char    sOrgAccount[11];		/* ORG_ACCOUNT */
	char    sDestAccount[11];		/* DEST_ACCOUNT */
	char    sRightResult[11];		/* ��Ȩ��� */
	char    sUdhi[2];		/* UDHI */
	char    sMr[2];		/* MR */
	char    sRn[3];		/* RN */
	char    sMn[2];		/* MN */
	char    sSn[2];		/* SN */
	struct SmgsmTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSmgsmTicketStruct{

	char    sReqNo[18];		/* ��ˮ�� */
	char    sMsgID[10];		/* ��Ϣ��ʶ */
	char    sCallingNbr[20];		/* ���к��� */
	char    sCallingTon[3];		/* CALLING_TON */
	char    sCallingNpi[3];		/* CALLING_NPI */
	char    sCalledNbr[20];		/* ���к��� */
	char    sCalledTon[3];		/* CALLED_TON */
	char    sCalledNpi[3];		/* CALLED_NPI */
	char    sRegisterTime[19];		/* ����ʱ�� */
	char    sSendTime[19];		/* ���ͽ���ʱ�� */
	char    sPriority[3];		/* ���ȼ� */
	char    sSsr[3];		/* SSR */
	char    sPid[3];		/* PID */
	char    sDcs[3];		/* DCS */
	char    sMsgLen[3];		/* ��Ϣ���� */
	char    sLastStatus[3];		/* ��������״̬ */
	char    sErrCode[3];		/* ������� */
	char    sMsgType[4];		/* ��Ϣ���� */
	char    sServiceType[5];		/* ҵ������ */
	char    sPpsFlag[1];		/* PPS��־ */
	char    sOrgAccount[10];		/* ORG_ACCOUNT */
	char    sDestAccount[10];		/* DEST_ACCOUNT */
	char    sRightResult[10];		/* ��Ȩ��� */
	char    sUdhi[1];		/* UDHI */
	char    sMr[1];		/* MR */
	char    sRn[2];		/* RN */
	char    sMn[1];		/* MN */
	char    sSn[1];		/* SN */
};

/*�������ݶ�̬��SMGSM_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmgsmTicketToStruct(struct SmgsmTicketStruct *p,
	struct SmgsmTicketStructIn *pSource);
void mvitem_mfsmgsmticket(struct SmgsmTicketStruct *pi,struct FSmgsmTicketStruct *po);


/* ����ṹ��������*/
struct SmmobTicketStructIn{

#ifndef SMMOB_TICKET_BUFLEN_IN
#define SMMOB_TICKET_BUFLEN_IN		300
#endif

	struct SmmobTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��ˮ�� */
	char    asRegNo[SMMOB_TICKET_BUFLEN_IN][31];
		/* �������� */
	char    asCallType[SMMOB_TICKET_BUFLEN_IN][3];
		/* �û����� */
	char    asUserType[SMMOB_TICKET_BUFLEN_IN][2];
		/* ���к��� */
	char    asCallingNbr[SMMOB_TICKET_BUFLEN_IN][22];
		/* ���к��� */
	char    asCalledNbr[SMMOB_TICKET_BUFLEN_IN][22];
		/* ���д��� */
	char    asCityCode[SMMOB_TICKET_BUFLEN_IN][4];
		/* ���ŷ���״̬ */
	char    asLastStatus[SMMOB_TICKET_BUFLEN_IN][5];
		/* ���ų��� */
	int     aiMsgLen[SMMOB_TICKET_BUFLEN_IN];
		/* �������ش��� */
	char    asSmg[SMMOB_TICKET_BUFLEN_IN][6];
		/* �������ش��� */
	char    asTsmg[SMMOB_TICKET_BUFLEN_IN][6];
		/* ҵ����� */
	char    asServiceCode[SMMOB_TICKET_BUFLEN_IN][5];
		/* �������� */
	char    asSmsc[SMMOB_TICKET_BUFLEN_IN][14];
		/* ����ʱ�� */
	char    asRegisterTime[SMMOB_TICKET_BUFLEN_IN][15];
		/* ��������ʱ�� */
	char    asSendTime[SMMOB_TICKET_BUFLEN_IN][15];
		/* ���� */
	char    asReserve[SMMOB_TICKET_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SmmobTicketStruct{

	struct SmmobTicketStruct *pNext;
	char    sRegNo[31];		/* ��ˮ�� */
	char    sCallType[3];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sCallingNbr[22];		/* ���к��� */
	char    sCalledNbr[22];		/* ���к��� */
	char    sCityCode[4];		/* ���д��� */
	char    sLastStatus[5];		/* ���ŷ���״̬ */
	int     iMsgLen;		/* ���ų��� */
	char    sSmg[6];		/* �������ش��� */
	char    sTsmg[6];		/* �������ش��� */
	char    sServiceCode[5];		/* ҵ����� */
	char    sSmsc[14];		/* �������� */
	char    sRegisterTime[15];		/* ����ʱ�� */
	char    sSendTime[15];		/* ��������ʱ�� */
	char    sReserve[15];		/* ���� */
	struct SmmobTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSmmobTicketStruct{

	char    sRegNo[30];		/* ��ˮ�� */
	char    sCallType[2];		/* �������� */
	char    sUserType[1];		/* �û����� */
	char    sCallingNbr[21];		/* ���к��� */
	char    sCalledNbr[21];		/* ���к��� */
	char    sCityCode[3];		/* ���д��� */
	char    sLastStatus[4];		/* ���ŷ���״̬ */
	char    sMsgLen[3];		/* ���ų��� */
	char    sSmg[5];		/* �������ش��� */
	char    sTsmg[5];		/* �������ش��� */
	char    sServiceCode[4];		/* ҵ����� */
	char    sSmsc[13];		/* �������� */
	char    sRegisterTime[14];		/* ����ʱ�� */
	char    sSendTime[14];		/* ��������ʱ�� */
	char    sReserve[14];		/* ���� */
};


/*�������ݶ�̬��SMMOB_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmmobTicketToStruct(struct SmmobTicketStruct *p,
	struct SmmobTicketStructIn *pSource);
void mvitem_mfsmmobticket(struct SmmobTicketStruct *pi,struct FSmmobTicketStruct *po);


/* ����ṹ��������*/
struct SmtelTicketStructIn{

#ifndef SMTEL_TICKET_BUFLEN_IN
#define SMTEL_TICKET_BUFLEN_IN		300
#endif

	struct SmtelTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��ˮ�� */
	char    asRegNo[SMTEL_TICKET_BUFLEN_IN][31];
		/* �������� */
	char    asCallType[SMTEL_TICKET_BUFLEN_IN][3];
		/* �û����� */
	char    asUserType[SMTEL_TICKET_BUFLEN_IN][2];
		/* ���к��� */
	char    asCallingNbr[SMTEL_TICKET_BUFLEN_IN][22];
		/* ���к��� */
	char    asCalledNbr[SMTEL_TICKET_BUFLEN_IN][22];
		/* ���д��� */
	char    asCityCode[SMTEL_TICKET_BUFLEN_IN][4];
		/* ���ŷ���״̬ */
	char    asLastStatus[SMTEL_TICKET_BUFLEN_IN][5];
		/* ���ų��� */
	int     aiMsgLen[SMTEL_TICKET_BUFLEN_IN];
		/* �������ش��� */
	char    asSmg[SMTEL_TICKET_BUFLEN_IN][7];
		/* �������ش��� */
	char    asTsmg[SMTEL_TICKET_BUFLEN_IN][7];
		/* ҵ����� */
	char    asServiceCode[SMTEL_TICKET_BUFLEN_IN][5];
		/* �������� */
	char    asSmsc[SMTEL_TICKET_BUFLEN_IN][14];
		/* ����ʱ�� */
	char    asRegisterTime[SMTEL_TICKET_BUFLEN_IN][15];
		/* ��������ʱ�� */
	char    asSendTime[SMTEL_TICKET_BUFLEN_IN][15];
		/* ���� */
	char    asReserve[SMTEL_TICKET_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SmtelTicketStruct{

	struct SmtelTicketStruct *pNext;
	char    sRegNo[31];		/* ��ˮ�� */
	char    sCallType[3];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sCallingNbr[22];		/* ���к��� */
	char    sCalledNbr[22];		/* ���к��� */
	char    sCityCode[4];		/* ���д��� */
	char    sLastStatus[5];		/* ���ŷ���״̬ */
	int     iMsgLen;		/* ���ų��� */
	char    sSmg[7];		/* �������ش��� */
	char    sTsmg[7];		/* �������ش��� */
	char    sServiceCode[5];		/* ҵ����� */
	char    sSmsc[14];		/* �������� */
	char    sRegisterTime[15];		/* ����ʱ�� */
	char    sSendTime[15];		/* ��������ʱ�� */
	char    sReserve[15];		/* ���� */
	struct SmtelTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSmtelTicketStruct{

	char    sRegNo[30];		/* ��ˮ�� */
	char    sCallType[2];		/* �������� */
	char    sUserType[1];		/* �û����� */
	char    sCallingNbr[21];		/* ���к��� */
	char    sCalledNbr[21];		/* ���к��� */
	char    sCityCode[3];		/* ���д��� */
	char    sLastStatus[4];		/* ���ŷ���״̬ */
	char    sMsgLen[3];		/* ���ų��� */
	char    sSmg[6];		/* �������ش��� */
	char    sTsmg[6];		/* �������ش��� */
	char    sServiceCode[4];		/* ҵ����� */
	char    sSmsc[13];		/* �������� */
	char    sRegisterTime[14];		/* ����ʱ�� */
	char    sSendTime[14];		/* ��������ʱ�� */
	char    sReserve[14];		/* ���� */
};


/*�������ݶ�̬��SMTEL_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmtelTicketToStruct(struct SmtelTicketStruct *p,
	struct SmtelTicketStructIn *pSource);
void mvitem_mfsmtelticket(struct SmtelTicketStruct *pi,struct FSmtelTicketStruct *po);

/* ����ṹ��������*/
struct Smsp1TicketStructIn{

#ifndef SMSP1_TICKET_BUFLEN_IN
#define SMSP1_TICKET_BUFLEN_IN		300
#endif

	struct Smsp1TicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asRegNo[SMSP1_TICKET_BUFLEN_IN][31];
		/* �������� */
	char    asCallType[SMSP1_TICKET_BUFLEN_IN][3];
		/* �û����� */
	char    asUserType[SMSP1_TICKET_BUFLEN_IN][2];
		/* �ƷѺ��� */
	char    asMsisdn[SMSP1_TICKET_BUFLEN_IN][14];
		/* SP���� */
	char    asSpCode[SMSP1_TICKET_BUFLEN_IN][6];
		/* SP�������ش��� */
	char    asSpHomeSmg[SMSP1_TICKET_BUFLEN_IN][6];
		/* ���к��� */
	char    asOtherParty[SMSP1_TICKET_BUFLEN_IN][14];
		/* SP������ */
	char    asSpAccNbr[SMSP1_TICKET_BUFLEN_IN][13];
		/* ҵ����� */
	char    asServiceCode[SMSP1_TICKET_BUFLEN_IN][11];
		/* �û��Ʒ����� */
	char    asBillingType[SMSP1_TICKET_BUFLEN_IN][2];
		/* ��Ϣ�� */
	int     aiInfoFee[SMSP1_TICKET_BUFLEN_IN];
		/* ���·� */
	int     aiRentFee[SMSP1_TICKET_BUFLEN_IN];
		/* �������� */
	int     aiReturnFee[SMSP1_TICKET_BUFLEN_IN];
		/* ���շѱ��� */
	char    asBillType[SMSP1_TICKET_BUFLEN_IN][2];
		/* MO��MT��־ */
	char    asMoFlag[SMSP1_TICKET_BUFLEN_IN][2];
		/* ����״̬ */
	char    asLastStatus[SMSP1_TICKET_BUFLEN_IN][5];
		/* ���ȼ� */
	char    asPriority[SMSP1_TICKET_BUFLEN_IN][2];
		/* ��Ϣ�� */
	int     aiMsgCnt[SMSP1_TICKET_BUFLEN_IN];
		/* �û����� */
	char    asHomeAreaCode[SMSP1_TICKET_BUFLEN_IN][5];
		/* �������� */
	char    asSmg[SMSP1_TICKET_BUFLEN_IN][6];
		/* �������� */
	char    asTsmg[SMSP1_TICKET_BUFLEN_IN][6];
		/* �������� */
	char    asSmsc[SMSP1_TICKET_BUFLEN_IN][14];
		/* ����ʱ�� */
	char    asRegisterTime[SMSP1_TICKET_BUFLEN_IN][15];
		/* ���ŷ���ʱ�� */
	char    asSendTime[SMSP1_TICKET_BUFLEN_IN][15];
		/* ���� */
	char    asReserve[SMSP1_TICKET_BUFLEN_IN][28];
};


/*�����ṹ����*/
struct Smsp1TicketStruct{

	struct Smsp1TicketStruct *pNext;
	char    sRegNo[31];		/* �������� */
	char    sCallType[3];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[14];		/* �ƷѺ��� */
	char    sSpCode[6];		/* SP���� */
	char    sSpHomeSmg[6];		/* SP�������ش��� */
	char    sOtherParty[14];		/* ���к��� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sServiceCode[11];		/* ҵ����� */
	char    sBillingType[2];		/* �û��Ʒ����� */
	int     iInfoFee;		/* ��Ϣ�� */
	int     iRentFee;		/* ���·� */
	int     iReturnFee;		/* �������� */
	char    sBillType[2];		/* ���շѱ��� */
	char    sMoFlag[2];		/* MO��MT��־ */
	char    sLastStatus[5];		/* ����״̬ */
	char    sPriority[2];		/* ���ȼ� */
	int     iMsgCnt;		/* ��Ϣ�� */
	char    sHomeAreaCode[5];		/* �û����� */
	char    sSmg[6];		/* �������� */
	char    sTsmg[6];		/* �������� */
	char    sSmsc[14];		/* �������� */
	char    sRegisterTime[15];		/* ����ʱ�� */
	char    sSendTime[15];		/* ���ŷ���ʱ�� */
	char    sReserve[28];		/* ���� */
	struct Smsp1TicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSmsp1TicketStruct{

	char    sRegNo[30];		/* �������� */
	char    sCallType[2];		/* �������� */
	char    sUserType[1];		/* �û����� */
	char    sMsisdn[13];		/* �ƷѺ��� */
	char    sSpCode[5];		/* SP���� */
	char    sSpHomeSmg[5];		/* SP�������ش��� */
	char    sOtherParty[13];		/* ���к��� */
	char    sSpAccNbr[12];		/* SP������ */
	char    sServiceCode[10];		/* ҵ����� */
	char    sBillingType[1];		/* �û��Ʒ����� */
	char    sInfoFee[6];		/* ��Ϣ�� */
	char    sRentFee[6];		/* ���·� */
	char    sReturnFee[6];		/* �������� */
	char    sBillType[1];		/* ���շѱ��� */
	char    sMoFlag[1];		/* MO��MT��־ */
	char    sLastStatus[4];		/* ����״̬ */
	char    sPriority[1];		/* ���ȼ� */
	char    sMsgCnt[2];		/* ��Ϣ�� */
	char    sHomeAreaCode[4];		/* �û����� */
	char    sSmg[5];		/* �������� */
	char    sTsmg[5];		/* �������� */
	char    sSmsc[13];		/* �������� */
	char    sRegisterTime[14];		/* ����ʱ�� */
	char    sSendTime[14];		/* ���ŷ���ʱ�� */
	char    sReserve[27];		/* ���� */
};

/*�����ṹ����*/
struct Sp1xfjTicketStruct{

	struct Sp1xfjTicketStruct *pNext;
	char    sSeqNumber[11];
	char    sRecordType[2];
	char    sSpCode[9];
	char    sSpLoginName[33];
	char    sMsIpAddress[16];
	char    sSpSrvType[3];
	char    sSpSrvTypeName[41];
	char    sSpServiceType[3];
	char    sSpServiceCode[11];
	char    sSpServiceName[41];
	char    sContentCode[11];
	char    sContentName[41];
	char    sMsisdn[21];
	char    sImsi[16];
	char    sNai[33];
	char    sNaiDomain[33];
	char    sStartTime[15];
	char    sStopTime[15];
	char    sActionCount[11];
	char    sActiveTime[7];
	char    sDataCountTermination[11];
	char    sDataCountOrigination[11];
	char    sDataCountTotal[11];
	char    sPreDiscntFee[11];
	char    sPostDiscntFee[11];
	char    sDiscntFee[11];
	char    sRateUnit[5];
	char    sFeeType[5];
	char    sFeeRateDescCode[21];
	char    sDiscntDescCode[21];
	char    sUrl[301];
	char    sSysID[9];
	char    sSysIntraKey[31];
	char    sUserType[2];
	char    sOtherParty[21];
	char    sBillType[11];
	char    sNoused1[10];
	char    sNoused2[13];
	char    sNoused3[13];
	char    sNoused4[41];
	struct Sp1xfjTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSp1xfjTicketStruct{

	char    sSeqNumber[10];
	char    sRecordType[1];
	char    sSpCode[8];
	char    sSpLoginName[32];
	char    sMsIpAddress[15];
	char    sSpSrvType[2];
	char    sSpSrvTypeName[40];
	char    sSpServiceType[2];
	char    sSpServiceCode[10];
	char    sSpServiceName[40];
	char    sContentCode[10];
	char    sContentName[40];
	char    sMsisdn[20];
	char    sImsi[15];
	char    sNai[32];
	char    sNaiDomain[32];
	char    sStartTime[14];
	char    sStopTime[14];
	char    sActionCount[10];
	char    sActiveTime[6];
	char    sDataCountTermination[10];
	char    sDataCountOrigination[10];
	char    sDataCountTotal[10];
	char    sPreDiscntFee[10];
	char    sPostDiscntFee[10];
	char    sDiscntFee[10];
	char    sRateUnit[4];
	char    sFeeType[4];
	char    sFeeRateDescCode[20];
	char    sDiscntDescCode[20];
	char    sUrl[300];
	char    sSysID[8];
	char    sSysIntraKey[30];
	char    sUserType[1];
	char    sOtherParty[20];
	char    sBillType[10];
	char    sNoused1[9];
	char    sNoused2[12];
	char    sNoused3[12];
	char    sNoused4[40];
};


/* ����ṹ��������*/
struct Sp1xfjTicketStructIn{

#ifndef SP1XFJ_TICKET_BUFLEN_IN
#define SP1XFJ_TICKET_BUFLEN_IN		1000
#endif

	struct Sp1xfjTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSeqNumber[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asRecordType[SP1XFJ_TICKET_BUFLEN_IN][2];
	char    asSpCode[SP1XFJ_TICKET_BUFLEN_IN][9];
	char    asSpLoginName[SP1XFJ_TICKET_BUFLEN_IN][33];
	char    asMsIpAddress[SP1XFJ_TICKET_BUFLEN_IN][16];
	char    asSpSrvType[SP1XFJ_TICKET_BUFLEN_IN][3];
	char    asSpSrvTypeName[SP1XFJ_TICKET_BUFLEN_IN][41];
	char    asSpServiceType[SP1XFJ_TICKET_BUFLEN_IN][3];
	char    asSpServiceCode[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asSpServiceName[SP1XFJ_TICKET_BUFLEN_IN][41];
	char    asContentCode[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asContentName[SP1XFJ_TICKET_BUFLEN_IN][41];
	char    asMsisdn[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asImsi[SP1XFJ_TICKET_BUFLEN_IN][16];
	char    asNai[SP1XFJ_TICKET_BUFLEN_IN][33];
	char    asNaiDomain[SP1XFJ_TICKET_BUFLEN_IN][33];
	char    asStartTime[SP1XFJ_TICKET_BUFLEN_IN][15];
	char    asStopTime[SP1XFJ_TICKET_BUFLEN_IN][15];
	char    asActionCount[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asActiveTime[SP1XFJ_TICKET_BUFLEN_IN][7];
	char    asDataCountTermination[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asDataCountOrigination[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asDataCountTotal[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asPreDiscntFee[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asPostDiscntFee[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asDiscntFee[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asRateUnit[SP1XFJ_TICKET_BUFLEN_IN][5];
	char    asFeeType[SP1XFJ_TICKET_BUFLEN_IN][5];
	char    asFeeRateDescCode[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asDiscntDescCode[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asUrl[SP1XFJ_TICKET_BUFLEN_IN][301];
	char    asSysID[SP1XFJ_TICKET_BUFLEN_IN][9];
	char    asSysIntraKey[SP1XFJ_TICKET_BUFLEN_IN][31];
	char    asUserType[SP1XFJ_TICKET_BUFLEN_IN][2];
	char    asOtherParty[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asBillType[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asNoused1[SP1XFJ_TICKET_BUFLEN_IN][10];
	char    asNoused2[SP1XFJ_TICKET_BUFLEN_IN][13];
	char    asNoused3[SP1XFJ_TICKET_BUFLEN_IN][13];
	char    asNoused4[SP1XFJ_TICKET_BUFLEN_IN][41];
};

/*�����ṹ����*/
struct SmspfjTicketStruct{

	struct SmspfjTicketStruct *pNext;
	char    sBusiType[3];
	char    sCallType[2];
	char    sMsisdn[14];
	char    sUserType[2];
	char    sHomeAreaCode[5];
	char    sCallingNbr[14];
	char    sCalledNbr[14];
	char    sSpCode[11];
	char    sSpServiceCode[21];
	char    sFeeType[2];
	char    sDuration[5];
	char    sCnt[5];
	char    sStartTime[15];
	char    sBaseFee[7];
	char    sInfoFee[7];
	char    sRentFee[7];
	char    sInfoFeeType[3];
	char    sOriFileName[21];
	char    sReserve[21];
	struct SmspfjTicketStruct *pLoadNext;
};


/* ����ṹ��������*/
struct SmspfjTicketStructIn{

#ifndef SMSPFJ_TICKET_BUFLEN_IN
#define SMSPFJ_TICKET_BUFLEN_IN		1000
#endif

	struct SmspfjTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asBusiType[SMSPFJ_TICKET_BUFLEN_IN][3];
	char    asCallType[SMSPFJ_TICKET_BUFLEN_IN][2];
	char    asMsisdn[SMSPFJ_TICKET_BUFLEN_IN][14];
	char    asUserType[SMSPFJ_TICKET_BUFLEN_IN][2];
	char    asHomeAreaCode[SMSPFJ_TICKET_BUFLEN_IN][5];
	char    asCallingNbr[SMSPFJ_TICKET_BUFLEN_IN][14];
	char    asCalledNbr[SMSPFJ_TICKET_BUFLEN_IN][14];
	char    asSpCode[SMSPFJ_TICKET_BUFLEN_IN][11];
	char    asSpServiceCode[SMSPFJ_TICKET_BUFLEN_IN][21];
	char    asFeeType[SMSPFJ_TICKET_BUFLEN_IN][2];
	char    asDuration[SMSPFJ_TICKET_BUFLEN_IN][5];
	char    asCnt[SMSPFJ_TICKET_BUFLEN_IN][5];
	char    asStartTime[SMSPFJ_TICKET_BUFLEN_IN][15];
	char    asBaseFee[SMSPFJ_TICKET_BUFLEN_IN][7];
	char    asInfoFee[SMSPFJ_TICKET_BUFLEN_IN][7];
	char    asRentFee[SMSPFJ_TICKET_BUFLEN_IN][7];
	char    asInfoFeeType[SMSPFJ_TICKET_BUFLEN_IN][3];
	char    asOriFileName[SMSPFJ_TICKET_BUFLEN_IN][21];
	char    asReserve[SMSPFJ_TICKET_BUFLEN_IN][21];
};


/*�����ļ��ṹ����*/
struct FSmspfjTicketStruct{

	char    sBusiType[2];
	char    sCallType[1];
	char    sMsisdn[13];
	char    sUserType[1];
	char    sHomeAreaCode[4];
	char    sCallingNbr[13];
	char    sCalledNbr[13];
	char    sSpCode[10];
	char    sSpServiceCode[20];
	char    sFeeType[1];
	char    sDuration[4];
	char    sCnt[4];
	char    sStartTime[14];
	char    sBaseFee[6];
	char    sInfoFee[6];
	char    sRentFee[6];
	char    sInfoFeeType[2];
	char    sOriFileName[20];
	char    sReserve[20];
};

/*�������ݶ�̬��SMSP1_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmsp1TicketToStruct(struct Smsp1TicketStruct *p,
	struct Smsp1TicketStructIn *pSource);
void mvitem_mfsmsp1ticket(struct Smsp1TicketStruct *pi,struct FSmsp1TicketStruct *po);

int EGetSp1xfjTicketToStruct(struct Sp1xfjTicketStruct *p,
	struct Sp1xfjTicketStructIn *pSource);
void mvitem_mfs1xfjticket(struct Sp1xfjTicketStruct *pi,struct FSp1xfjTicketStruct *po);

int EGetSmspfjTicketToStruct(struct SmspfjTicketStruct *p,
	struct SmspfjTicketStructIn *pSource);
void mvitem_mfsspfjticket(struct SmspfjTicketStruct *pi,struct FSmspfjTicketStruct *po);

int SmcdmaTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmgsmTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmmobTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmtelTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int Smsp1Ticket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int Sp1xfjTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmspfjTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*�����ṹ����*/
struct SmsStatStruct{

	struct SmsStatStruct *pNext;
	char    sRecordType[3];
	char    sCallType[2];
	char    sMsisdn[14];
	char    sUserType[2];
	char    sHomeAreaCode[5];
	char    sStartTime[15];
	int     iBaseFee;
	int     iInfoFee;
	char    sOriFileName[41];
};

/* ����ṹ��������*/
struct SmsStatStructIn{

#ifndef SMS_STAT_BUFLEN_IN
#define SMS_STAT_BUFLEN_IN		1000
#endif

	struct SmsStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[256];
	char    asRecordType[SMS_STAT_BUFLEN_IN][3];
	char    asCallType[SMS_STAT_BUFLEN_IN][2];
	char    asMsisdn[SMS_STAT_BUFLEN_IN][14];
	char    asUserType[SMS_STAT_BUFLEN_IN][2];
	char    asHomeAreaCode[SMS_STAT_BUFLEN_IN][5];
	char    asStartTime[SMS_STAT_BUFLEN_IN][15];
	int     aiBaseFee[SMS_STAT_BUFLEN_IN];
	int     aiInfoFee[SMS_STAT_BUFLEN_IN];
	char    asOriFileName[SMS_STAT_BUFLEN_IN][41];
};

/*�����ṹ����*/
struct SmsNbrStatStruct{

	struct SmsNbrStatStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sTicketType[3];		/* 00��G������ 01��C������	02���ƶ���ͨ 03��С��ͨ��ͨ 04�����ʶ��� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[16];		/* �û����� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
};

/*�����ṹ����*/
struct RSmsNbrStatStruct{

	struct RSmsNbrStatStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sTicketType[3];		/* 00��G������ 01��C������	02���ƶ���ͨ 03��С��ͨ��ͨ 04�����ʶ��� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[16];		/* �û����� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	char    sRowID[19];		/* ��¼���� */
};

/*�����ṹ����*/
struct USmsNbrStatStruct{

	struct USmsNbrStatStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sTicketType[3];		/* 00��G������ 01��C������	02���ƶ���ͨ 03��С��ͨ��ͨ 04�����ʶ��� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[16];		/* �û����� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	char	sRowID[19];	
};

/*����ṹ��������*/
struct USmsNbrStatStructUp{

#ifndef SMS_NBR_STAT_BUFLEN_UP
#define SMS_NBR_STAT_BUFLEN_UP		1000
#endif

	struct USmsNbrStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asBillingCycleID[SMS_NBR_STAT_BUFLEN_UP][7];
		/* 00��G������ 01��C������	02���ƶ���ͨ 03��С��ͨ��ͨ 04�����ʶ��� */
	char    asTicketType[SMS_NBR_STAT_BUFLEN_UP][3];
		/* �û����� */
	char    asUserType[SMS_NBR_STAT_BUFLEN_UP][2];
		/* �û����� */
	char    asMsisdn[SMS_NBR_STAT_BUFLEN_UP][16];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMS_NBR_STAT_BUFLEN_UP];
		/* ���ŷ����� */
	int     aiMoCnt[SMS_NBR_STAT_BUFLEN_UP];
		/* �����մ��� */
	int     aiMtCnt[SMS_NBR_STAT_BUFLEN_UP];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMS_NBR_STAT_BUFLEN_UP][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMS_NBR_STAT_BUFLEN_UP][15];
		/* ��������� */
	char    asHomeAreaCode[SMS_NBR_STAT_BUFLEN_UP][6];
		/* ��¼�������� */
	char    asCreatedDate[SMS_NBR_STAT_BUFLEN_UP][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMS_NBR_STAT_BUFLEN_UP][15];
	char	asRowID[SMS_NBR_STAT_BUFLEN_UP][19];	
};

/*����ṹ��������*/
struct SmsNbrStatStructOut{

#ifndef SMS_NBR_STAT_BUFLEN_OUT
#define SMS_NBR_STAT_BUFLEN_OUT		1000
#endif

	struct SmsNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asBillingCycleID[SMS_NBR_STAT_BUFLEN_OUT][7];
		/* 00��G������ 01��C������	02���ƶ���ͨ 03��С��ͨ��ͨ 04�����ʶ��� */
	char    asTicketType[SMS_NBR_STAT_BUFLEN_OUT][3];
		/* �û����� */
	char    asUserType[SMS_NBR_STAT_BUFLEN_OUT][2];
		/* �û����� */
	char    asMsisdn[SMS_NBR_STAT_BUFLEN_OUT][16];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMS_NBR_STAT_BUFLEN_OUT];
		/* ���ŷ����� */
	int     aiMoCnt[SMS_NBR_STAT_BUFLEN_OUT];
		/* �����մ��� */
	int     aiMtCnt[SMS_NBR_STAT_BUFLEN_OUT];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMS_NBR_STAT_BUFLEN_OUT][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMS_NBR_STAT_BUFLEN_OUT][15];
		/* ��������� */
	char    asHomeAreaCode[SMS_NBR_STAT_BUFLEN_OUT][6];
		/* ��¼�������� */
	char    asCreatedDate[SMS_NBR_STAT_BUFLEN_OUT][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMS_NBR_STAT_BUFLEN_OUT][15];
};

/* ����ṹ��������*/
struct SmsNbrStatStructIn{

#ifndef SMS_NBR_STAT_BUFLEN_IN
#define SMS_NBR_STAT_BUFLEN_IN		1000
#endif

	struct SmsNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asBillingCycleID[SMS_NBR_STAT_BUFLEN_IN][7];
		/* 00��G������ 01��C������	02���ƶ���ͨ 03��С��ͨ��ͨ 04�����ʶ��� */
	char    asTicketType[SMS_NBR_STAT_BUFLEN_IN][3];
		/* �û����� */
	char    asUserType[SMS_NBR_STAT_BUFLEN_IN][2];
		/* �û����� */
	char    asMsisdn[SMS_NBR_STAT_BUFLEN_IN][16];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMS_NBR_STAT_BUFLEN_IN];
		/* ���ŷ����� */
	int     aiMoCnt[SMS_NBR_STAT_BUFLEN_IN];
		/* �����մ��� */
	int     aiMtCnt[SMS_NBR_STAT_BUFLEN_IN];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMS_NBR_STAT_BUFLEN_IN][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMS_NBR_STAT_BUFLEN_IN][15];
		/* ��������� */
	char    asHomeAreaCode[SMS_NBR_STAT_BUFLEN_IN][6];
		/* ��¼�������� */
	char    asCreatedDate[SMS_NBR_STAT_BUFLEN_IN][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMS_NBR_STAT_BUFLEN_IN][15];
};

/* ����ṹ��������*/
struct 	RSmsNbrStatStructIn{

#ifndef R_SMS_NBR_STAT_BUFLEN_IN
#define R_SMS_NBR_STAT_BUFLEN_IN		1000
#endif

	struct RSmsNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asBillingCycleID[R_SMS_NBR_STAT_BUFLEN_IN][7];
		/* 00��G������ 01��C������	02���ƶ���ͨ 03��С��ͨ��ͨ 04�����ʶ��� */
	char    asTicketType[R_SMS_NBR_STAT_BUFLEN_IN][3];
		/* �û����� */
	char    asUserType[R_SMS_NBR_STAT_BUFLEN_IN][2];
		/* �û����� */
	char    asMsisdn[R_SMS_NBR_STAT_BUFLEN_IN][16];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[R_SMS_NBR_STAT_BUFLEN_IN];
		/* ���ŷ����� */
	int     aiMoCnt[R_SMS_NBR_STAT_BUFLEN_IN];
		/* �����մ��� */
	int     aiMtCnt[R_SMS_NBR_STAT_BUFLEN_IN];
		/* ���緢��ʱ�� */
	char    asMinStartTime[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* ��������� */
	char    asHomeAreaCode[R_SMS_NBR_STAT_BUFLEN_IN][6];
		/* ��¼�������� */
	char    asCreatedDate[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* ��¼�������� */
	char    asUpdatedDate[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* ��¼���� */
	char    asRowID[R_SMS_NBR_STAT_BUFLEN_IN][19];
	
};


int EGetSmsStatToStruct(struct SmsStatStruct *p,struct SmsStatStructIn *pSource);
int EInsertStructToSmsNbrStat(struct SmsNbrStatStruct *p,
	int iInsertFlag,struct SmsNbrStatStructOut *pTarget);
int InsertSmsNbrStat(struct SmsNbrStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag);
int data_bintree_search_sms_nbr_stat(void *pValue,void*pData);
void assign_bintree_insert_sms_nbr_stat(void **ppData,void *pData);
int rdata_search_bintree_sms_nbr(void *pValue,void*pData);
void rassign_bintree_insert_sms_nbr(void **ppData,void *pData);
void assign_bintree_insert_sms_nbr(void **ppData,void *pData);
void InsertSmsNbrFee(void *pValue,void*pData);
int node_pthead_sms_stat_e(void **ppHead);
int SmsStatTicket2Bintree(BINTREE **ppRoot,char sTableName[],char sCondition[]);
int SmsNbrStatDataSum(BINTREE **ppRoot,struct SmsNbrStatStruct *pValue,
	char sBillingCycle[],char sTableName[]);
int EGetSmsNbrStatToStruct(struct RSmsNbrStatStruct *p,
	struct RSmsNbrStatStructIn *pSource);
int SmsNbrStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[]);
void mvitem_rsmsnbrstat(struct SmsNbrStatStruct *pi,struct RSmsNbrStatStruct *po);
void mvitem_usmsnbrstat(struct RSmsNbrStatStruct *pi,struct USmsNbrStatStruct *po);
void mvitem_smsnbrstat(struct RSmsNbrStatStruct *pi,struct SmsNbrStatStruct *po);
int UpdateSmsNbrStat(struct USmsNbrStatStruct *pSourcet,char sTableName[],
	int iUpdateFlag);
int EUpdateStructToUSmsNbrStat(struct USmsNbrStatStruct *p,
	int iUpdateFlag,struct USmsNbrStatStructUp *pTarget);


/*�����ṹ����*/
struct SmspNbrRentStatStruct{

	struct SmspNbrRentStatStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[16];		/* �û����� */
	char    sSpCode[6];		/* SP��ҵ���� */
	char    sSpAccNbr[13];		/* SP������� */
	char    sSpServiceCode[11];		/* SP��ҵҵ����� */
	char    sBillingType[3];		/* �Ʒ���� */
	int     iRentRate;		/* ������� */
	char    sMoFlag[2];		/* MO��־ */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	struct SmspNbrRentStatStruct *pLoadNext;
};



/*����ṹ��������*/
struct SmspNbrRentStatStructOut{

#ifndef SMSP_NBR_RENT_STAT_BUFLEN_OUT
#define SMSP_NBR_RENT_STAT_BUFLEN_OUT		1000
#endif

	struct SmspNbrRentStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asBillingCycleID[SMSP_NBR_RENT_STAT_BUFLEN_OUT][7];
		/* �û����� */
	char    asUserType[SMSP_NBR_RENT_STAT_BUFLEN_OUT][2];
		/* �û����� */
	char    asMsisdn[SMSP_NBR_RENT_STAT_BUFLEN_OUT][16];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_NBR_RENT_STAT_BUFLEN_OUT][6];
		/* SP������� */
	char    asSpAccNbr[SMSP_NBR_RENT_STAT_BUFLEN_OUT][13];
		/* SP��ҵҵ����� */
	char    asSpServiceCode[SMSP_NBR_RENT_STAT_BUFLEN_OUT][11];
		/* �Ʒ���� */
	char    asBillingType[SMSP_NBR_RENT_STAT_BUFLEN_OUT][3];
		/* ������� */
	int     aiRentRate[SMSP_NBR_RENT_STAT_BUFLEN_OUT];
		/* MO��־ */
	char    asMoFlag[SMSP_NBR_RENT_STAT_BUFLEN_OUT][2];
		/* ��������� */
	char    asHomeAreaCode[SMSP_NBR_RENT_STAT_BUFLEN_OUT][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_NBR_RENT_STAT_BUFLEN_OUT][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_NBR_RENT_STAT_BUFLEN_OUT][15];
};




/* ����ṹ��������*/
struct SmspNbrRentStatStructIn{

#ifndef SMSP_NBR_RENT_STAT_BUFLEN_IN
#define SMSP_NBR_RENT_STAT_BUFLEN_IN		1000
#endif

	struct SmspNbrRentStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asBillingCycleID[SMSP_NBR_RENT_STAT_BUFLEN_IN][7];
		/* �û����� */
	char    asUserType[SMSP_NBR_RENT_STAT_BUFLEN_IN][2];
		/* �û����� */
	char    asMsisdn[SMSP_NBR_RENT_STAT_BUFLEN_IN][16];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_NBR_RENT_STAT_BUFLEN_IN][6];
		/* SP������� */
	char    asSpAccNbr[SMSP_NBR_RENT_STAT_BUFLEN_IN][13];
		/* SP��ҵҵ����� */
	char    asSpServiceCode[SMSP_NBR_RENT_STAT_BUFLEN_IN][11];
		/* �Ʒ���� */
	char    asBillingType[SMSP_NBR_RENT_STAT_BUFLEN_IN][3];
		/* ������� */
	int     aiRentRate[SMSP_NBR_RENT_STAT_BUFLEN_IN];
		/* MO��־ */
	char    asMoFlag[SMSP_NBR_RENT_STAT_BUFLEN_IN][2];
		/* ��������� */
	char    asHomeAreaCode[SMSP_NBR_RENT_STAT_BUFLEN_IN][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_NBR_RENT_STAT_BUFLEN_IN][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_NBR_RENT_STAT_BUFLEN_IN][15];
};


int EInsertStructToSmspNbrRentStat(struct SmspNbrRentStatStruct *p,
	int iInsertFlag,struct SmspNbrRentStatStructOut *pTarget);
int InsertSmspNbrRentStat(struct SmspNbrRentStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag);
int SmsTicket2Bintree(BINTREE **ppRoot,BINTREE ** ppRootS,BINTREE ** ppRootN,
	char sTableName[],char sCondition[],char sStatType[]);
void assign_bintree_insert_smsp_nbr_rent_stat(void **ppData,void *pData);
int data_bintree_search_smsp_nbr_rent_stat(void *pValue,void*pData);
int data_bintree_search_smsp_nbr_rent(void *pValue,void*pData);
void assign_bintree_insert_smsp_nbr_rent(void **ppData,void *pData);
int SmspNbrRentStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[]);
int EGetSmspNbrRentStatToStruct(struct SmspNbrRentStatStruct *p,
	struct SmspNbrRentStatStructIn *pSource);
int SmspNbrRentStatDataSum(BINTREE **ppRoot,struct SmspNbrRentStatStruct *pValue,
	char sBillingCycle[],char sTableName[]);
	
	

/*�����ṹ����*/
struct SmspSpStatStruct{

	struct SmspSpStatStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sSpCode[6];		/* SP��ҵ���� */
	char    sSpAccNbr[13];		/* SP������� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	int     iTotalCnt;		/* �ܴ��� */
	int     iTotalFee;		/* �ܷ��� */
	int     iTotalInfoFee;		/* ����Ϣ�� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iTotalRentFee;		/* ������� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	struct SmspSpStatStruct *pLoadNext;
};


/* ����ṹ��������*/
struct SmspSpStatStructIn{

#ifndef SMSP_SP_STAT_BUFLEN_IN
#define SMSP_SP_STAT_BUFLEN_IN		1000
#endif

	struct SmspSpStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asBillingCycleID[SMSP_SP_STAT_BUFLEN_IN][7];
		/* �û����� */
	char    asUserType[SMSP_SP_STAT_BUFLEN_IN][2];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_SP_STAT_BUFLEN_IN][6];
		/* SP������� */
	char    asSpAccNbr[SMSP_SP_STAT_BUFLEN_IN][13];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMSP_SP_STAT_BUFLEN_IN][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMSP_SP_STAT_BUFLEN_IN][15];
		/* ���ŷ����� */
	int     aiMoCnt[SMSP_SP_STAT_BUFLEN_IN];
		/* �����մ��� */
	int     aiMtCnt[SMSP_SP_STAT_BUFLEN_IN];
		/* �ܴ��� */
	int     aiTotalCnt[SMSP_SP_STAT_BUFLEN_IN];
		/* �ܷ��� */
	int     aiTotalFee[SMSP_SP_STAT_BUFLEN_IN];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[SMSP_SP_STAT_BUFLEN_IN];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMSP_SP_STAT_BUFLEN_IN];
		/* ������� */
	int     aiTotalRentFee[SMSP_SP_STAT_BUFLEN_IN];
		/* ��������� */
	char    asHomeAreaCode[SMSP_SP_STAT_BUFLEN_IN][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_SP_STAT_BUFLEN_IN][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_SP_STAT_BUFLEN_IN][15];
};

/* ����ṹ��������*/
struct RSmspSpStatStructIn{

#ifndef R_SMSP_SP_STAT_BUFLEN_IN
#define R_SMSP_SP_STAT_BUFLEN_IN		1000
#endif

	struct RSmspSpStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asBillingCycleID[R_SMSP_SP_STAT_BUFLEN_IN][7];
		/* �û����� */
	char    asUserType[R_SMSP_SP_STAT_BUFLEN_IN][2];
		/* SP��ҵ���� */
	char    asSpCode[R_SMSP_SP_STAT_BUFLEN_IN][6];
		/* SP������� */
	char    asSpAccNbr[R_SMSP_SP_STAT_BUFLEN_IN][13];
		/* ���緢��ʱ�� */
	char    asMinStartTime[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* ���ŷ����� */
	int     aiMoCnt[R_SMSP_SP_STAT_BUFLEN_IN];
		/* �����մ��� */
	int     aiMtCnt[R_SMSP_SP_STAT_BUFLEN_IN];
		/* �ܴ��� */
	int     aiTotalCnt[R_SMSP_SP_STAT_BUFLEN_IN];
		/* �ܷ��� */
	int     aiTotalFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* ������� */
	int     aiTotalRentFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* ��������� */
	char    asHomeAreaCode[R_SMSP_SP_STAT_BUFLEN_IN][6];
		/* ��¼�������� */
	char    asCreatedDate[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* ��¼�������� */
	char    asUpdatedDate[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* ��¼���� */
	char    asRowID[R_SMS_NBR_STAT_BUFLEN_IN][19];	
};


/*����ṹ��������*/
struct USmspSpStatStructUp{

#ifndef SMSP_SP_STAT_BUFLEN_UP
#define SMSP_SP_STAT_BUFLEN_UP		1000
#endif

	struct USmspSpStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asBillingCycleID[SMSP_SP_STAT_BUFLEN_UP][7];
		/* �û����� */
	char    asUserType[SMSP_SP_STAT_BUFLEN_UP][2];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_SP_STAT_BUFLEN_UP][6];
		/* SP������� */
	char    asSpAccNbr[SMSP_SP_STAT_BUFLEN_UP][13];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMSP_SP_STAT_BUFLEN_UP][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMSP_SP_STAT_BUFLEN_UP][15];
		/* ���ŷ����� */
	int     aiMoCnt[SMSP_SP_STAT_BUFLEN_UP];
		/* �����մ��� */
	int     aiMtCnt[SMSP_SP_STAT_BUFLEN_UP];
		/* �ܴ��� */
	int     aiTotalCnt[SMSP_SP_STAT_BUFLEN_UP];
		/* �ܷ��� */
	int     aiTotalFee[SMSP_SP_STAT_BUFLEN_UP];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[SMSP_SP_STAT_BUFLEN_UP];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMSP_SP_STAT_BUFLEN_UP];
		/* ������� */
	int     aiTotalRentFee[SMSP_SP_STAT_BUFLEN_UP];
		/* ��������� */
	char    asHomeAreaCode[SMSP_SP_STAT_BUFLEN_UP][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_SP_STAT_BUFLEN_UP][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_SP_STAT_BUFLEN_UP][15];
		/* ��¼���� */
	char    asRowID[SMSP_SP_STAT_BUFLEN_UP][19];	
};


/*�����ṹ����*/
struct RSmspSpStatStruct{

	struct RSmspSpStatStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sSpCode[6];		/* SP��ҵ���� */
	char    sSpAccNbr[13];		/* SP������� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	int     iTotalCnt;		/* �ܴ��� */
	int     iTotalFee;		/* �ܷ��� */
	int     iTotalInfoFee;		/* ����Ϣ�� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iTotalRentFee;		/* ������� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	char    sRowID[19];		/* ��¼���� */	
	struct RSmspSpStatStruct *pLoadNext;
};

/*�����ṹ����*/
struct USmspSpStatStruct{

	struct USmspSpStatStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sSpCode[6];		/* SP��ҵ���� */
	char    sSpAccNbr[13];		/* SP������� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	int     iTotalCnt;		/* �ܴ��� */
	int     iTotalFee;		/* �ܷ��� */
	int     iTotalInfoFee;		/* ����Ϣ�� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iTotalRentFee;		/* ������� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	char    sRowID[19];		/* ��¼���� */	
	struct USmspSpStatStruct *pLoadNext;
};


/*����ṹ��������*/
struct SmspSpStatStructOut{

#ifndef SMSP_SP_STAT_BUFLEN_OUT
#define SMSP_SP_STAT_BUFLEN_OUT		1000
#endif

	struct SmspSpStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asBillingCycleID[SMSP_SP_STAT_BUFLEN_OUT][7];
		/* �û����� */
	char    asUserType[SMSP_SP_STAT_BUFLEN_OUT][2];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_SP_STAT_BUFLEN_OUT][6];
		/* SP������� */
	char    asSpAccNbr[SMSP_SP_STAT_BUFLEN_OUT][13];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMSP_SP_STAT_BUFLEN_OUT][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMSP_SP_STAT_BUFLEN_OUT][15];
		/* ���ŷ����� */
	int     aiMoCnt[SMSP_SP_STAT_BUFLEN_OUT];
		/* �����մ��� */
	int     aiMtCnt[SMSP_SP_STAT_BUFLEN_OUT];
		/* �ܴ��� */
	int     aiTotalCnt[SMSP_SP_STAT_BUFLEN_OUT];
		/* �ܷ��� */
	int     aiTotalFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* ������� */
	int     aiTotalRentFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* ��������� */
	char    asHomeAreaCode[SMSP_SP_STAT_BUFLEN_OUT][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_SP_STAT_BUFLEN_OUT][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_SP_STAT_BUFLEN_OUT][15];
};




int SmspSpStatStructDataSum(BINTREE **ppRoot,struct SmspSpStatStruct *pValue,
	char sBillingCycle[],char sTableName[]);
int SmspSpStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[]);
int EGetSmspSpStatToStruct(struct RSmspSpStatStruct *p,
	struct RSmspSpStatStructIn *pSource);
void mvitem_smspspstat(struct RSmspSpStatStruct *pi,struct SmspSpStatStruct *po);
void mvitem_rsmspspstat(struct SmspSpStatStruct *pi,struct RSmspSpStatStruct *po);
void mvitem_usmspspstat(struct RSmspSpStatStruct *pi,struct USmspSpStatStruct *po);	
int EUpdateStructToUSmspSpStat(struct USmspSpStatStruct *p,
	int iUpdateFlag,struct USmspSpStatStructUp *pTarget);
int EInsertStructToSmspSpStat(struct SmspSpStatStruct *p,
	int iInsertFlag,struct SmspSpStatStructOut *pTarget);
int rdata_bintree_search_smsp_sp_stat(void *pValue,void*pData);
void rassign_bintree_insert_smsp_sp_stat(void **ppData,void *pData);
int data_bintree_search_smsp_sp_stat(void *pValue,void*pData);
void assign_bintree_insert_smsp_sp_stat(void **ppData,void *pData);
void InsertSmspSpFee(void *pValue,void*pData);
void InsertSmsNbrFeeTotal(void *pValue,void*pData);


/*�����ṹ����*/
struct SmspNbrStatStruct{

	struct SmspNbrStatStruct *pNext;                              
	int     iTicketTypeID;		/* �������ͱ�ʶ */            
	char    sBillingCycleID[7];		/* �������� */        
	char    sUserType[2];		/* �û����� */                
	char    sMsisdn[16];		/* �û����� */                
	int     iTotalFee;		/* �ܷ��� */                  
	int     iTotalInfoFee;		/* ����Ϣ�� */                
	int     iTotalCommFee;		/* ��ͨ�ŷ� */                
	int     iTotalRentFee;		/* ������� */                
	char    sSpCode[6];		/* SP��ҵ���� */              
	char    sSpServiceCode[11];		/* SP������� */      
	char    sSpAccNbr[13];		/* SP������� */              
	int     iMoCnt;		/* ���ŷ����� */                      
	int     iMtCnt;		/* �����մ��� */                      
	int     iTotalCnt;		/* �ܴ��� */                  
	char    sMinStartTime[15];		/* ���緢��ʱ�� */    
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */    
	char    sHomeAreaCode[6];		/* ��������� */      
	char    sCreatedDate[15];		/* ��¼�������� */    
	char    sUpdatedDate[15];		/* ��¼�������� */    
	struct SmspNbrStatStruct *pLoadNext;                          
};

/*�����ļ��ṹ����*/
struct FSmspNbrStatStruct{

	char    sTicketTypeID[4];
	char    sBillingCycleID[6];
	char    sUserType[1];
	char    sMsisdn[15];
	char    sTotalFee[9];
	char    sTotalInfoFee[9];
	char    sTotalCommFee[9];
	char    sTotalRentFee[9];
	char    sSpCode[5];
	char    sSpServiceCode[10];
	char    sSpAccNbr[12];
	char    sMoCnt[6];
	char    sMtCnt[6];
	char    sTotalCnt[6];
	char    sMinStartTime[14];
	char    sMaxStartTime[14];
	char    sHomeAreaCode[5];
	char    sCreatedDate[14];
	char    sUpdatedDate[14];
};

/*�����ṹ����*/
struct RSmspNbrStatStruct{

	struct RSmspNbrStatStruct *pNext;
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sBillingCycleID[7];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[16];		/* �û����� */
	int     iTotalFee;		/* �ܷ��� */
	int     iTotalInfoFee;		/* ����Ϣ�� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iTotalRentFee;		/* ������� */
	char    sSpCode[6];		/* SP��ҵ���� */
	char    sSpServiceCode[11];		/* SP������� */
	char    sSpAccNbr[13];		/* SP������� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	int     iTotalCnt;		/* �ܴ��� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	char    sRowID[19];		/* ��¼���� */		
	struct RSmspNbrStatStruct *pLoadNext;
};

/*�����ṹ����*/
struct USmspNbrStatStruct{

	struct USmspNbrStatStruct *pNext;
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sBillingCycleID[7];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[16];		/* �û����� */
	int     iTotalFee;		/* �ܷ��� */
	int     iTotalInfoFee;		/* ����Ϣ�� */
	int     iTotalCommFee;		/* ��ͨ�ŷ� */
	int     iTotalRentFee;		/* ������� */
	char    sSpCode[6];		/* SP��ҵ���� */
	char    sSpServiceCode[11];		/* SP������� */
	char    sSpAccNbr[13];		/* SP������� */
	int     iMoCnt;		/* ���ŷ����� */
	int     iMtCnt;		/* �����մ��� */
	int     iTotalCnt;		/* �ܴ��� */
	char    sMinStartTime[15];		/* ���緢��ʱ�� */
	char    sMaxStartTime[15];		/* ��ٷ���ʱ�� */
	char    sHomeAreaCode[6];		/* ��������� */
	char    sCreatedDate[15];		/* ��¼�������� */
	char    sUpdatedDate[15];		/* ��¼�������� */
	char    sRowID[19];		/* ��¼���� */		
	struct USmspNbrStatStruct *pLoadNext;
};



/* ����ṹ��������*/
struct SmspNbrStatStructIn{

#ifndef SMSP_NBR_STAT_BUFLEN_IN
#define SMSP_NBR_STAT_BUFLEN_IN		1000
#endif

	struct SmspNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SMSP_NBR_STAT_BUFLEN_IN];
		/* �������� */
	char    asBillingCycleID[SMSP_NBR_STAT_BUFLEN_IN][7];
		/* �û����� */
	char    asUserType[SMSP_NBR_STAT_BUFLEN_IN][2];
		/* �û����� */
	char    asMsisdn[SMSP_NBR_STAT_BUFLEN_IN][16];
		/* �ܷ��� */
	int     aiTotalFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* ������� */
	int     aiTotalRentFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_NBR_STAT_BUFLEN_IN][6];
		/* SP������� */
	char    asSpServiceCode[SMSP_NBR_STAT_BUFLEN_IN][11];
		/* SP������� */
	char    asSpAccNbr[SMSP_NBR_STAT_BUFLEN_IN][13];
		/* ���ŷ����� */
	int     aiMoCnt[SMSP_NBR_STAT_BUFLEN_IN];
		/* �����մ��� */
	int     aiMtCnt[SMSP_NBR_STAT_BUFLEN_IN];
		/* �ܴ��� */
	int     aiTotalCnt[SMSP_NBR_STAT_BUFLEN_IN];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMSP_NBR_STAT_BUFLEN_IN][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMSP_NBR_STAT_BUFLEN_IN][15];
		/* ��������� */
	char    asHomeAreaCode[SMSP_NBR_STAT_BUFLEN_IN][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_NBR_STAT_BUFLEN_IN][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_NBR_STAT_BUFLEN_IN][15];
};


/* ����ṹ��������*/
struct RSmspNbrStatStructIn{

#ifndef R_SMSP_NBR_STAT_BUFLEN_IN
#define R_SMSP_NBR_STAT_BUFLEN_IN		1000
#endif

	struct RSmspNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* �������� */
	char    asBillingCycleID[R_SMSP_NBR_STAT_BUFLEN_IN][7];
		/* �û����� */
	char    asUserType[R_SMSP_NBR_STAT_BUFLEN_IN][2];
		/* �û����� */
	char    asMsisdn[R_SMSP_NBR_STAT_BUFLEN_IN][16];
		/* �ܷ��� */
	int     aiTotalFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* ������� */
	int     aiTotalRentFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* SP��ҵ���� */
	char    asSpCode[R_SMSP_NBR_STAT_BUFLEN_IN][6];
		/* SP������� */
	char    asSpServiceCode[R_SMSP_NBR_STAT_BUFLEN_IN][11];
		/* SP������� */
	char    asSpAccNbr[R_SMSP_NBR_STAT_BUFLEN_IN][13];
		/* ���ŷ����� */
	int     aiMoCnt[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* �����մ��� */
	int     aiMtCnt[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* �ܴ��� */
	int     aiTotalCnt[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* ���緢��ʱ�� */
	char    asMinStartTime[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* ��������� */
	char    asHomeAreaCode[R_SMSP_NBR_STAT_BUFLEN_IN][6];
		/* ��¼�������� */
	char    asCreatedDate[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* ��¼�������� */
	char    asUpdatedDate[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* ��¼���� */
	char    asRowID[R_SMS_NBR_STAT_BUFLEN_IN][19];	
	
};


/*����ṹ��������*/
struct SmspNbrStatStructOut{

#ifndef SMSP_NBR_STAT_BUFLEN_OUT
#define SMSP_NBR_STAT_BUFLEN_OUT		1000
#endif

	struct SmspNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SMSP_NBR_STAT_BUFLEN_OUT];
		/* �������� */
	char    asBillingCycleID[SMSP_NBR_STAT_BUFLEN_OUT][7];
		/* �û����� */
	char    asUserType[SMSP_NBR_STAT_BUFLEN_OUT][2];
		/* �û����� */
	char    asMsisdn[SMSP_NBR_STAT_BUFLEN_OUT][16];
		/* �ܷ��� */
	int     aiTotalFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* ������� */
	int     aiTotalRentFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_NBR_STAT_BUFLEN_OUT][6];
		/* SP������� */
	char    asSpServiceCode[SMSP_NBR_STAT_BUFLEN_OUT][11];
		/* SP������� */
	char    asSpAccNbr[SMSP_NBR_STAT_BUFLEN_OUT][13];
		/* ���ŷ����� */
	int     aiMoCnt[SMSP_NBR_STAT_BUFLEN_OUT];
		/* �����մ��� */
	int     aiMtCnt[SMSP_NBR_STAT_BUFLEN_OUT];
		/* �ܴ��� */
	int     aiTotalCnt[SMSP_NBR_STAT_BUFLEN_OUT];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMSP_NBR_STAT_BUFLEN_OUT][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMSP_NBR_STAT_BUFLEN_OUT][15];
		/* ��������� */
	char    asHomeAreaCode[SMSP_NBR_STAT_BUFLEN_OUT][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_NBR_STAT_BUFLEN_OUT][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_NBR_STAT_BUFLEN_OUT][15];
};


/*����ṹ��������*/
struct USmspNbrStatStructUp{

#ifndef SMSP_NBR_STAT_BUFLEN_UP
#define SMSP_NBR_STAT_BUFLEN_UP		1000
#endif

	struct USmspNbrStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SMSP_NBR_STAT_BUFLEN_UP];
		/* �������� */
	char    asBillingCycleID[SMSP_NBR_STAT_BUFLEN_UP][7];
		/* �û����� */
	char    asUserType[SMSP_NBR_STAT_BUFLEN_UP][2];
		/* �û����� */
	char    asMsisdn[SMSP_NBR_STAT_BUFLEN_UP][16];
		/* �ܷ��� */
	int     aiTotalFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* ����Ϣ�� */
	int     aiTotalInfoFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* ��ͨ�ŷ� */
	int     aiTotalCommFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* ������� */
	int     aiTotalRentFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* SP��ҵ���� */
	char    asSpCode[SMSP_NBR_STAT_BUFLEN_UP][6];
		/* SP������� */
	char    asSpServiceCode[SMSP_NBR_STAT_BUFLEN_UP][11];
		/* SP������� */
	char    asSpAccNbr[SMSP_NBR_STAT_BUFLEN_UP][13];
		/* ���ŷ����� */
	int     aiMoCnt[SMSP_NBR_STAT_BUFLEN_UP];
		/* �����մ��� */
	int     aiMtCnt[SMSP_NBR_STAT_BUFLEN_UP];
		/* �ܴ��� */
	int     aiTotalCnt[SMSP_NBR_STAT_BUFLEN_UP];
		/* ���緢��ʱ�� */
	char    asMinStartTime[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* ��ٷ���ʱ�� */
	char    asMaxStartTime[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* ��������� */
	char    asHomeAreaCode[SMSP_NBR_STAT_BUFLEN_UP][6];
		/* ��¼�������� */
	char    asCreatedDate[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* ��¼�������� */
	char    asUpdatedDate[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* ��¼���� */
	char    asRowID[SMSP_NBR_STAT_BUFLEN_UP][19];	
	
};


int data_bintree_search_smsp_nbr_stat(void *pValue,void*pData);
void assign_bintree_insert_smsp_nbr_stat(void **ppData,void *pData);
int EGetSmspNbrStatToStruct(struct RSmspNbrStatStruct *p,
	struct RSmspNbrStatStructIn *pSource);
void mvitem_rsmspnbrstat(struct SmspNbrStatStruct *pi,struct RSmspNbrStatStruct *po);
void mvitem_usmspnbrstat(struct RSmspNbrStatStruct *pi,struct USmspNbrStatStruct *po);	
void mvitem_smspnbrstat(struct RSmspNbrStatStruct *pi,struct SmspNbrStatStruct *po);
int EInsertStructToSmspNbrStat(struct SmspNbrStatStruct *p,
	int iInsertFlag,struct SmspNbrStatStructOut *pTarget);
int EUpdateStructToSmspNbrStat(struct USmspNbrStatStruct *p,
	int iUpdateFlag,struct USmspNbrStatStructUp *pTarget);	
int rdata_bintree_search_smsp_nbr_stat(void *pValue,void*pData);
void rassign_bintree_insert_smsp_nbr_stat(void **ppData,void *pData);
void InsertSmspSpFeeTotal(void *pValue,void*pData);

void InsertSmspNbrFeeTotal(void *pValue,void*pData);
void InsertSmspNbrFee(void *pValue,void*pData);
void mvitem_mfsmspnbrstat(struct RSmspNbrStatStruct *pi,struct FSmspNbrStatStruct *po);	

/* ����ṹ��������*/
struct SpAcctItemStructIn{

#ifndef SP_ACCT_ITEM_BUFLEN_IN
#define SP_ACCT_ITEM_BUFLEN_IN		300
#endif

	struct SpAcctItemStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �û����� */
	char    asMsisdn[SP_ACCT_ITEM_BUFLEN_IN][16];
		/* �ʵ��������� */
	char    asBillingCycleID[SP_ACCT_ITEM_BUFLEN_IN][7];
		/* ʵ������ */
	char    asPayCycleID[SP_ACCT_ITEM_BUFLEN_IN][7];
		/* SP���� */
	char    asSpCode[SP_ACCT_ITEM_BUFLEN_IN][9];
		/* SPҵ����� */
	char    asSpServiceCode[SP_ACCT_ITEM_BUFLEN_IN][9];
		/* SPʵ���ܷ��� */
	char    asCharge[SP_ACCT_ITEM_BUFLEN_IN][11];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SP_ACCT_ITEM_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceCode[SP_ACCT_ITEM_BUFLEN_IN][2];
		/* �ʵ�����ʱ�� */
	char    asPayTime[SP_ACCT_ITEM_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SpAcctItemStruct{

	struct SpAcctItemStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sBillingCycleID[7];		/* �ʵ��������� */
	char    sPayCycleID[7];		/* ʵ������ */
	char    sSpCode[9];		/* SP���� */
	char    sSpServiceCode[9];		/* SPҵ����� */
	char    sCharge[11];		/* SPʵ���ܷ��� */
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sServiceCode[2];		/* ҵ������ */
	char    sPayTime[15];		/* �ʵ�����ʱ�� */
	struct SpAcctItemStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FSpAcctItemStruct{

	char    sMsisdn[15];
	char    sBillingCycleID[6];
	char    sPayCycleID[6];
	char    sSpCode[8];
	char    sSpServiceCode[8];
	char    sCharge[10];
	char    sTicketTypeID[4];
	char    sServiceCode[1];
	char    sPayTime[14];
};


/*����ṹ��������*/
struct SpAcctItemStructOut{

#ifndef SP_ACCT_ITEM_BUFLEN_OUT
#define SP_ACCT_ITEM_BUFLEN_OUT		300
#endif

	struct SpAcctItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asMsisdn[SP_ACCT_ITEM_BUFLEN_OUT][16];
		/* �ʵ��������� */
	char    asBillingCycleID[SP_ACCT_ITEM_BUFLEN_OUT][7];
		/* ʵ������ */
	char    asPayCycleID[SP_ACCT_ITEM_BUFLEN_OUT][7];
		/* SP���� */
	char    asSpCode[SP_ACCT_ITEM_BUFLEN_OUT][9];
		/* SPҵ����� */
	char    asSpServiceCode[SP_ACCT_ITEM_BUFLEN_OUT][9];
		/* SPʵ���ܷ��� */
	char    asCharge[SP_ACCT_ITEM_BUFLEN_OUT][11];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SP_ACCT_ITEM_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceCode[SP_ACCT_ITEM_BUFLEN_OUT][2];
		/* �ʵ�����ʱ�� */
	char    asPayTime[SP_ACCT_ITEM_BUFLEN_OUT][15];
};

void DestroySpAcctItem(struct SpAcctItemStruct *ptHead);
int EGetSpAcctItemToStruct(struct SpAcctItemStruct *p,
	struct SpAcctItemStructIn *pSource);
int InitSpAcctItem(struct SpAcctItemStruct **pptHead,
	char sInputTable[]);
int EInsertStructToSpAcctItem(struct SpAcctItemStruct *p,        
	int iInsertFlag,struct SpAcctItemStructOut *pTarget);	
void mvitem_mfspacctitem(struct SpAcctItemStruct *pi,struct FSpAcctItemStruct *po);

int SmspNbrStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SpAcctItem2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
/*����ṹ��������*/
struct SmgTicketStructOut{

#ifndef SMG_TICKET_BUFLEN_OUT
#define SMG_TICKET_BUFLEN_OUT		300
#endif

	struct SmgTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����Ϣ��ʶ */
	char    asMessageID[SMG_TICKET_BUFLEN_OUT][21];
		/* ����Ϣ���� */
	char    asSmsType[SMG_TICKET_BUFLEN_OUT][2];
		/* ����Ϣ������ */
	char    asSubType[SMG_TICKET_BUFLEN_OUT][2];
		/* �Ʒ��û����� */
	char    asMsisdn[SMG_TICKET_BUFLEN_OUT][22];
		/* SP���� */
	char    asSpCode[SMG_TICKET_BUFLEN_OUT][11];
		/* Ŀ�ĵغ��� */
	char    asOtherParty[SMG_TICKET_BUFLEN_OUT][22];
		/* ҵ����� */
	char    asSpServiceCode[SMG_TICKET_BUFLEN_OUT][11];
		/* �û��Ʒ���� */
	char    asBillType[SMG_TICKET_BUFLEN_OUT][3];
		/* ��Ϣ�� */
	char    asInfoFee[SMG_TICKET_BUFLEN_OUT][7];
		/* ����Ϣ�������ȼ� */
	char    asPriority[SMG_TICKET_BUFLEN_OUT][2];
		/* ��Ϣ���� */
	char    asMsgLen[SMG_TICKET_BUFLEN_OUT][4];
		/* �ƷѺ�������ص����� */
	char    asHomeAreaCode[SMG_TICKET_BUFLEN_OUT][5];
		/* SMGW���� */
	char    asSmg[SMG_TICKET_BUFLEN_OUT][7];
		/* ǰתSMGW���� */
	char    asTsmg[SMG_TICKET_BUFLEN_OUT][7];
		/* ����Ϣ���Ĵ��� */
	char    asSmc[SMG_TICKET_BUFLEN_OUT][7];
		/* �ύʱ�� */
	char    asRecvDateTime[SMG_TICKET_BUFLEN_OUT][15];
		/* ��������ʱ�� */
	char    asDoneDateTime[SMG_TICKET_BUFLEN_OUT][15];
		/* SMGW�������Ϣ��ʶ */
	char    asMsgID[SMG_TICKET_BUFLEN_OUT][21];
		/* ����֮��Ķ���Ϣ��ʶ */
	char    asOppMsgID[SMG_TICKET_BUFLEN_OUT][21];
		/* �����û����� */
	char    asCallingNbr[SMG_TICKET_BUFLEN_OUT][22];
		/* �������� */
	int     aiTicketTypeID[SMG_TICKET_BUFLEN_OUT];
		/* ״̬ */
	char    asState[SMG_TICKET_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asDealDate[SMG_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[SMG_TICKET_BUFLEN_OUT][31];
};
/* ����ṹ��������*/
struct SmgTicketStructIn{

#ifndef SMG_TICKET_BUFLEN_IN
#define SMG_TICKET_BUFLEN_IN		300
#endif

	struct SmgTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ����Ϣ��ʶ */
	char    asMessageID[SMG_TICKET_BUFLEN_IN][21];
		/* ����Ϣ���� */
	char    asSmsType[SMG_TICKET_BUFLEN_IN][2];
		/* ����Ϣ������ */
	char    asSubType[SMG_TICKET_BUFLEN_IN][2];
		/* �Ʒ��û����� */
	char    asMsisdn[SMG_TICKET_BUFLEN_IN][22];
		/* SP���� */
	char    asSpCode[SMG_TICKET_BUFLEN_IN][11];
		/* Ŀ�ĵغ��� */
	char    asOtherParty[SMG_TICKET_BUFLEN_IN][22];
		/* ҵ����� */
	char    asSpServiceCode[SMG_TICKET_BUFLEN_IN][11];
		/* �û��Ʒ���� */
	char    asBillType[SMG_TICKET_BUFLEN_IN][3];
		/* ��Ϣ�� */
	char    asInfoFee[SMG_TICKET_BUFLEN_IN][7];
		/* ����Ϣ�������ȼ� */
	char    asPriority[SMG_TICKET_BUFLEN_IN][2];
		/* ��Ϣ���� */
	char    asMsgLen[SMG_TICKET_BUFLEN_IN][4];
		/* �ƷѺ�������ص����� */
	char    asHomeAreaCode[SMG_TICKET_BUFLEN_IN][5];
		/* SMGW���� */
	char    asSmg[SMG_TICKET_BUFLEN_IN][7];
		/* ǰתSMGW���� */
	char    asTsmg[SMG_TICKET_BUFLEN_IN][7];
		/* ����Ϣ���Ĵ��� */
	char    asSmc[SMG_TICKET_BUFLEN_IN][7];
		/* �ύʱ�� */
	char    asRecvDateTime[SMG_TICKET_BUFLEN_IN][15];
		/* ��������ʱ�� */
	char    asDoneDateTime[SMG_TICKET_BUFLEN_IN][15];
		/* SMGW�������Ϣ��ʶ */
	char    asMsgID[SMG_TICKET_BUFLEN_IN][21];
		/* ����֮��Ķ���Ϣ��ʶ */
	char    asOppMsgID[SMG_TICKET_BUFLEN_IN][21];
		/* �����û����� */
	char    asCallingNbr[SMG_TICKET_BUFLEN_IN][22];
		/* �������� */
	int     aiTicketTypeID[SMG_TICKET_BUFLEN_IN];
		/* ״̬ */
	char    asState[SMG_TICKET_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asDealDate[SMG_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[SMG_TICKET_BUFLEN_IN][31];
	char	asRowID[SMG_TICKET_BUFLEN_IN][19];
};

/*�����ṹ����*/
struct SmgTicketStruct{

	struct SmgTicketStruct *pNext;
	char    sMessageID[21];		/* ����Ϣ��ʶ */
	char    sSmsType[2];		/* ����Ϣ���� */
	char    sSubType[2];		/* ����Ϣ������ */
	char    sMsisdn[22];		/* �Ʒ��û����� */
	char    sSpCode[11];		/* SP���� */
	char    sOtherParty[22];		/* Ŀ�ĵغ��� */
	char    sSpServiceCode[11];		/* ҵ����� */
	char    sBillType[3];		/* �û��Ʒ���� */
	char    sInfoFee[7];		/* ��Ϣ�� */
	char    sPriority[2];		/* ����Ϣ�������ȼ� */
	char    sMsgLen[4];		/* ��Ϣ���� */
	char    sHomeAreaCode[5];		/* �ƷѺ�������ص����� */
	char    sSmg[7];		/* SMGW���� */
	char    sTsmg[7];		/* ǰתSMGW���� */
	char    sSmc[7];		/* ����Ϣ���Ĵ��� */
	char    sRecvDateTime[15];		/* �ύʱ�� */
	char    sDoneDateTime[15];		/* ��������ʱ�� */
	char    sMsgID[21];		/* SMGW�������Ϣ��ʶ */
	char    sOppMsgID[21];		/* ����֮��Ķ���Ϣ��ʶ */
	char    sCallingNbr[22];		/* �����û����� */
	int     iTicketTypeID;		/* �������� */
	char    sState[2];		/* ״̬ */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[31];		/* �ļ���Դ */
	char	sRowID[19];
	struct SmgTicketStruct *pLoadNext;
};

/*�������ݽṹ����д��SMG_TICKET*/
int EInsertStructToSmgTicket(struct SmgTicketStruct *p,
	int iInsertFlag,struct SmgTicketStructOut *pTarget);
void mvitem_fmsmgticket(struct FSmgTicketStruct *pi,int len,
	struct SmgTicketStruct *po);
void mvitem_mfsmgticket(struct SmgTicketStruct *pi,
	struct FSmgTicketStruct *po);
int InsertSmgTicket(char sFileName[],char sTableName[]);
/*�������ݶ�̬��SMG_TICKET���ýṹ���巽ʽȡ����*/
int EGetSmgTicketToStruct(struct SmgTicketStruct *p,
	struct SmgTicketStructIn *pSource);
int SmgTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*����ṹ��������*/
struct ZnwTicketStructOut{

#ifndef ZNW_TICKET_BUFLEN_OUT
#define ZNW_TICKET_BUFLEN_OUT		300
#endif

	struct ZnwTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	int     aiTicketTypeID[ZNW_TICKET_BUFLEN_OUT];
		/* ��¼����(0x���ҹǸ�������1xʡ��������Ϊ2xʡ��������Ϊ����) */
	char    asRecordType[ZNW_TICKET_BUFLEN_OUT][3];
		/* ��ˮ�� */
	char    asStreamNumber[ZNW_TICKET_BUFLEN_OUT][11];
		/* ҵ��� */
	char    asServiceKey[ZNW_TICKET_BUFLEN_OUT][11];
		/* �Ʒ�ģʽ */
	char    asBillingMode[ZNW_TICKET_BUFLEN_OUT][2];
		/* �ƷѼ�¼��ʶ */
	char    asChargeRecordID[ZNW_TICKET_BUFLEN_OUT][9];
		/* �����û����� */
	char    asCallingNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* �����û����� */
	char    asCalledNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* Ŀ���ַ������� */
	char    asTranslatedNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* λ�ú��� */
	char    asLocationNbr[ZNW_TICKET_BUFLEN_OUT][11];
		/* �Ʒ��û���־ */
	char    asBillingFlag[ZNW_TICKET_BUFLEN_OUT][5];
		/* �涨�ļƷѺ��� */
	char    asBillingNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* ��ʼͨ��ʱ�� */
	char    asStartTime[ZNW_TICKET_BUFLEN_OUT][15];
		/* ͨ������ʱ�� */
	char    asStopTime[ZNW_TICKET_BUFLEN_OUT][15];
		/* ͨ��ʱ�� */
	int     aiDuration[ZNW_TICKET_BUFLEN_OUT];
		/* ͨ������ */
	int     aiTotalFee[ZNW_TICKET_BUFLEN_OUT];
		/* �������� */
	char    asBearCapability[ZNW_TICKET_BUFLEN_OUT][3];
		/* �������� */
	char    asTariffClass[ZNW_TICKET_BUFLEN_OUT][3];
		/* �ƷѺ������� */
	char    asBillType[ZNW_TICKET_BUFLEN_OUT][5];
		/* �û�ID��������Ϣ */
	char    asUserID[ZNW_TICKET_BUFLEN_OUT][11];
		/* ҵ����� */
	char    asServiceNbr[ZNW_TICKET_BUFLEN_OUT][29];
		/* �ƴ��� */
	int     aiCount[ZNW_TICKET_BUFLEN_OUT];
		/* ������ */
	int     aiBaseFee[ZNW_TICKET_BUFLEN_OUT];
		/* ������� */
	int     aiBountyFee[ZNW_TICKET_BUFLEN_OUT];
		/* ���ӷ� */
	int     aiAddFee[ZNW_TICKET_BUFLEN_OUT];
		/* ͸������ */
	char    asTransParam[ZNW_TICKET_BUFLEN_OUT][31];
		/* �ƷѲ��� */
	char    asCallparttobecharger[ZNW_TICKET_BUFLEN_OUT][33];
		/* scp��� */
	char    asScpID[ZNW_TICKET_BUFLEN_OUT][11];
		/* ͨ������ԭ�� */
	char    asCauseOfCallend[ZNW_TICKET_BUFLEN_OUT][5];
		/* ҵ���ۿ��� */
	char    asServiceModulator[ZNW_TICKET_BUFLEN_OUT][5];
		/* ҵ������ */
	char    asServiceType[ZNW_TICKET_BUFLEN_OUT][3];
		/* ���� */
	char    asCardID[ZNW_TICKET_BUFLEN_OUT][31];
		/* ���й����� */
	char    asHomeAreaCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* ���й����� */
	char    asCalledCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* �Ʒ����� */
	char    asBillingAreaCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* ������������ */
	char    asCardAreaCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* �������� */
	char    asDistanceType[ZNW_TICKET_BUFLEN_OUT][2];
		/* ԭʼ�����ļ��� */
	char    asOriFileName[ZNW_TICKET_BUFLEN_OUT][41];
		/* ״̬ */
	char    asState[ZNW_TICKET_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asDealDate[ZNW_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[ZNW_TICKET_BUFLEN_OUT][41];
};
/* ����ṹ��������*/
struct ZnwTicketStructIn{

#ifndef ZNW_TICKET_BUFLEN_IN
#define ZNW_TICKET_BUFLEN_IN		300
#endif

	struct ZnwTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	int     aiTicketTypeID[ZNW_TICKET_BUFLEN_IN];
		/* ��¼����(0x���ҹǸ�������1xʡ��������Ϊ2xʡ��������Ϊ����) */
	char    asRecordType[ZNW_TICKET_BUFLEN_IN][3];
		/* ��ˮ�� */
	char    asStreamNumber[ZNW_TICKET_BUFLEN_IN][11];
		/* ҵ��� */
	char    asServiceKey[ZNW_TICKET_BUFLEN_IN][11];
		/* �Ʒ�ģʽ */
	char    asBillingMode[ZNW_TICKET_BUFLEN_IN][2];
		/* �ƷѼ�¼��ʶ */
	char    asChargeRecordID[ZNW_TICKET_BUFLEN_IN][9];
		/* �����û����� */
	char    asCallingNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* �����û����� */
	char    asCalledNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* Ŀ���ַ������� */
	char    asTranslatedNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* λ�ú��� */
	char    asLocationNbr[ZNW_TICKET_BUFLEN_IN][11];
		/* �Ʒ��û���־ */
	char    asBillingFlag[ZNW_TICKET_BUFLEN_IN][5];
		/* �涨�ļƷѺ��� */
	char    asBillingNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* ��ʼͨ��ʱ�� */
	char    asStartTime[ZNW_TICKET_BUFLEN_IN][15];
		/* ͨ������ʱ�� */
	char    asStopTime[ZNW_TICKET_BUFLEN_IN][15];
		/* ͨ��ʱ�� */
	int     aiDuration[ZNW_TICKET_BUFLEN_IN];
		/* ͨ������ */
	int     aiTotalFee[ZNW_TICKET_BUFLEN_IN];
		/* �������� */
	char    asBearCapability[ZNW_TICKET_BUFLEN_IN][3];
		/* �������� */
	char    asTariffClass[ZNW_TICKET_BUFLEN_IN][3];
		/* �ƷѺ������� */
	char    asBillType[ZNW_TICKET_BUFLEN_IN][5];
		/* �û�ID��������Ϣ */
	char    asUserID[ZNW_TICKET_BUFLEN_IN][11];
		/* ҵ����� */
	char    asServiceNbr[ZNW_TICKET_BUFLEN_IN][29];
		/* �ƴ��� */
	int     aiCount[ZNW_TICKET_BUFLEN_IN];
		/* ������ */
	int     aiBaseFee[ZNW_TICKET_BUFLEN_IN];
		/* ������� */
	int     aiBountyFee[ZNW_TICKET_BUFLEN_IN];
		/* ���ӷ� */
	int     aiAddFee[ZNW_TICKET_BUFLEN_IN];
		/* ͸������ */
	char    asTransParam[ZNW_TICKET_BUFLEN_IN][31];
		/* �ƷѲ��� */
	char    asCallparttobecharger[ZNW_TICKET_BUFLEN_IN][33];
		/* scp��� */
	char    asScpID[ZNW_TICKET_BUFLEN_IN][11];
		/* ͨ������ԭ�� */
	char    asCauseOfCallend[ZNW_TICKET_BUFLEN_IN][5];
		/* ҵ���ۿ��� */
	char    asServiceModulator[ZNW_TICKET_BUFLEN_IN][5];
		/* ҵ������ */
	char    asServiceType[ZNW_TICKET_BUFLEN_IN][3];
		/* ���� */
	char    asCardID[ZNW_TICKET_BUFLEN_IN][31];
		/* ���й����� */
	char    asHomeAreaCode[ZNW_TICKET_BUFLEN_IN][6];
		/* ���й����� */
	char    asCalledCode[ZNW_TICKET_BUFLEN_IN][6];
		/* �Ʒ����� */
	char    asBillingAreaCode[ZNW_TICKET_BUFLEN_IN][6];
		/* ������������ */
	char    asCardAreaCode[ZNW_TICKET_BUFLEN_IN][6];
		/* �������� */
	char    asDistanceType[ZNW_TICKET_BUFLEN_IN][2];
		/* ԭʼ�����ļ��� */
	char    asOriFileName[ZNW_TICKET_BUFLEN_IN][41];
		/* ״̬ */
	char    asState[ZNW_TICKET_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asDealDate[ZNW_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[ZNW_TICKET_BUFLEN_IN][41];
	char	asRowID[ZNW_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct ZnwTicketStruct{

	struct ZnwTicketStruct *pNext;
	int     iTicketTypeID;		/* �������� */
	char    sRecordType[3];		
	/* ��¼����(0x���ҹǸ�������1xʡ��������Ϊ2xʡ��������Ϊ����) */
	char    sStreamNumber[11];		/* ��ˮ�� */
	char    sServiceKey[11];		/* ҵ��� */
	char    sBillingMode[2];		/* �Ʒ�ģʽ */
	char    sChargeRecordID[9];		/* �ƷѼ�¼��ʶ */
	char    sCallingNbr[25];		/* �����û����� */
	char    sCalledNbr[25];		/* �����û����� */
	char    sTranslatedNbr[25];		/* Ŀ���ַ������� */
	char    sLocationNbr[11];		/* λ�ú��� */
	char    sBillingFlag[5];		/* �Ʒ��û���־ */
	char    sBillingNbr[25];		/* �涨�ļƷѺ��� */
	char    sStartTime[15];		/* ��ʼͨ��ʱ�� */
	char    sStopTime[15];		/* ͨ������ʱ�� */
	int     iDuration;		/* ͨ��ʱ�� */
	int     iTotalFee;		/* ͨ������ */
	char    sBearCapability[3];		/* �������� */
	char    sTariffClass[3];		/* �������� */
	char    sBillType[5];		/* �ƷѺ������� */
	char    sUserID[11];		/* �û�ID��������Ϣ */
	char    sServiceNbr[29];		/* ҵ����� */
	int     iCount;		/* �ƴ��� */
	int     iBaseFee;		/* ������ */
	int     iBountyFee;		/* ������� */
	int     iAddFee;		/* ���ӷ� */
	char    sTransParam[31];		/* ͸������ */
	char    sCallparttobecharger[33];		/* �ƷѲ��� */
	char    sScpID[11];		/* scp��� */
	char    sCauseOfCallend[5];		/* ͨ������ԭ�� */
	char    sServiceModulator[5];		/* ҵ���ۿ��� */
	char    sServiceType[3];		/* ҵ������ */
	char    sCardID[31];		/* ���� */
	char    sHomeAreaCode[6];		/* ���й����� */
	char    sCalledCode[6];		/* ���й����� */
	char    sBillingAreaCode[6];		/* �Ʒ����� */
	char    sCardAreaCode[6];		/* ������������ */
	char    sDistanceType[2];		/* �������� */
	char    sOriFileName[41];		/* ԭʼ�����ļ��� */
	char    sState[2];		/* ״̬ */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct ZnwTicketStruct *pLoadNext;
};

int EInsertStructToZnwTicket(struct ZnwTicketStruct *p,
	int iInsertFlag,struct ZnwTicketStructOut *pTarget);
void mvitem_fmznwticket(struct FZnwTicketStruct *pi,struct ZnwTicketStruct *po);
void mvitem_mfznwticket(struct ZnwTicketStruct *pi,struct FZnwTicketStruct *po);
int InsertZnwTicket(char sFileName[],char sTableName[]);
int ZnwTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
/*�������ݶ�̬��ZNW_TICKET���ýṹ���巽ʽȡ����*/
int EGetZnwTicketToStruct(struct ZnwTicketStruct *p,
	struct ZnwTicketStructIn *pSource);

/*����ṹ��������*/
struct IccTicketStructOut{

#ifndef ICC_TICKET_BUFLEN_OUT
#define ICC_TICKET_BUFLEN_OUT		300
#endif

	struct IccTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	int     aiTicketTypeID[ICC_TICKET_BUFLEN_OUT];
		/* ��¼����'20'��ʡ���λ���'21'ʡ�ڻ���(���ѵ绰��������) */
	char    asRecordType[ICC_TICKET_BUFLEN_OUT][3];
		/* ����ʡ���� */
	char    asProvinceCode[ICC_TICKET_BUFLEN_OUT][6];
		/* ����������� */
	char    asCallAreaCode[ICC_TICKET_BUFLEN_OUT][6];
		/* ���� */
	char    asCardID[ICC_TICKET_BUFLEN_OUT][31];
		/* ����ʡ���� */
	char    asCardProvinceCode[ICC_TICKET_BUFLEN_OUT][6];
		/* ������������ */
	char    asCardAreaCode[ICC_TICKET_BUFLEN_OUT][6];
		/* �����ش��� */
	char    asCardAreaID[ICC_TICKET_BUFLEN_OUT][6];
		/* ���к��� */
	char    asCallingNbr[ICC_TICKET_BUFLEN_OUT][25];
		/* ���к��� */
	char    asCalledNbr[ICC_TICKET_BUFLEN_OUT][25];
		/* �������� */
	char    asBillingCycleID[ICC_TICKET_BUFLEN_OUT][7];
		/* ����ʱ�� */
	char    asStartTime[ICC_TICKET_BUFLEN_OUT][15];
		/* ����ʱ�� */
	int     aiDuration[ICC_TICKET_BUFLEN_OUT];
		/* ���з��� */
	int     aiTotalFee[ICC_TICKET_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceType[ICC_TICKET_BUFLEN_OUT][3];
		/* ͨ������ */
	char    asDistanceType[ICC_TICKET_BUFLEN_OUT][2];
		/* ״̬ */
	char    asState[ICC_TICKET_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asDealDate[ICC_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[ICC_TICKET_BUFLEN_OUT][41];
};
/* ����ṹ��������*/
struct IccTicketStructIn{

#ifndef ICC_TICKET_BUFLEN_IN
#define ICC_TICKET_BUFLEN_IN		300
#endif

	struct IccTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	int     aiTicketTypeID[ICC_TICKET_BUFLEN_IN];
		/* ��¼����'20'��ʡ���λ���'21'ʡ�ڻ���(���ѵ绰��������) */
	char    asRecordType[ICC_TICKET_BUFLEN_IN][3];
		/* ����ʡ���� */
	char    asProvinceCode[ICC_TICKET_BUFLEN_IN][6];
		/* ����������� */
	char    asCallAreaCode[ICC_TICKET_BUFLEN_IN][6];
		/* ���� */
	char    asCardID[ICC_TICKET_BUFLEN_IN][31];
		/* ����ʡ���� */
	char    asCardProvinceCode[ICC_TICKET_BUFLEN_IN][6];
		/* ������������ */
	char    asCardAreaCode[ICC_TICKET_BUFLEN_IN][6];
		/* �����ش��� */
	char    asCardAreaID[ICC_TICKET_BUFLEN_IN][6];
		/* ���к��� */
	char    asCallingNbr[ICC_TICKET_BUFLEN_IN][25];
		/* ���к��� */
	char    asCalledNbr[ICC_TICKET_BUFLEN_IN][25];
		/* �������� */
	char    asBillingCycleID[ICC_TICKET_BUFLEN_IN][7];
		/* ����ʱ�� */
	char    asStartTime[ICC_TICKET_BUFLEN_IN][15];
		/* ����ʱ�� */
	int     aiDuration[ICC_TICKET_BUFLEN_IN];
		/* ���з��� */
	int     aiTotalFee[ICC_TICKET_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceType[ICC_TICKET_BUFLEN_IN][3];
		/* ͨ������ */
	char    asDistanceType[ICC_TICKET_BUFLEN_IN][2];
		/* ״̬ */
	char    asState[ICC_TICKET_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asDealDate[ICC_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[ICC_TICKET_BUFLEN_IN][41];
	char	asRowID[ICC_TICKET_BUFLEN_IN][19];
};



/*�����ṹ����*/
struct IccTicketStruct{

	struct IccTicketStruct *pNext;
	int     iTicketTypeID;		/* �������� */
	char    sRecordType[3];		
	/* ��¼����'20'��ʡ���λ���'21'ʡ�ڻ���(���ѵ绰��������) */
	char    sProvinceCode[6];		/* ����ʡ���� */
	char    sCallAreaCode[6];		/* ����������� */
	char    sCardID[31];		/* ���� */
	char    sCardProvinceCode[6];		/* ����ʡ���� */
	char    sCardAreaCode[6];		/* ������������ */
	char    sCardAreaID[6];		/* �����ش��� */
	char    sCallingNbr[25];		/* ���к��� */
	char    sCalledNbr[25];		/* ���к��� */
	char    sBillingCycleID[7];		/* �������� */
	char    sStartTime[15];		/* ����ʱ�� */
	int     iDuration;		/* ����ʱ�� */
	int     iTotalFee;		/* ���з��� */
	char    sServiceType[3];		/* ҵ������ */
	char    sDistanceType[2];		/* ͨ������ */
	char    sState[2];		/* ״̬ */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct IccTicketStruct *pLoadNext;
};
/*�������ݽṹ����д��ICC_TICKET*/
int EInsertStructToIccTicket(struct IccTicketStruct *p,
	int iInsertFlag,struct IccTicketStructOut *pTarget);
void mvitem_fmiccticket(struct FIccTicketStruct *pi,struct IccTicketStruct *po);
void mvitem_mficcticket(struct IccTicketStruct *pi,struct FIccTicketStruct *po);
int InsertIccTicket(char sFileName[],char sTableName[]);
/*�������ݶ�̬��ICC_TICKET���ýṹ���巽ʽȡ����*/
int EGetIccTicketToStruct(struct IccTicketStruct *p,
	struct IccTicketStructIn *pSource);
int IccTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);


/*����ṹ��������*/
struct InfoAcctStructOut{

#ifndef INFO_ACCT_BUFLEN_OUT
#define INFO_ACCT_BUFLEN_OUT		300
#endif

	struct InfoAcctStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	int     aiTicketTypeID[INFO_ACCT_BUFLEN_OUT];
		/* ʡ���� */
	char    asProvinceID[INFO_ACCT_BUFLEN_OUT][6];
		/* ���������� */
	char    asAreaCode[INFO_ACCT_BUFLEN_OUT][6];
		/* ��¼���� */
	int     aiTotalCnt[INFO_ACCT_BUFLEN_OUT];
		/* ��������� */
	int     aiTotalFee[INFO_ACCT_BUFLEN_OUT];
		/* ���ʼ�¼���� */
	int     aiValidCnt[INFO_ACCT_BUFLEN_OUT];
		/* ���ʽ�������� */
	int     aiValidFee[INFO_ACCT_BUFLEN_OUT];
		/* ���ܺ��ʼ�¼���� */
	int     aiInvalidCnt[INFO_ACCT_BUFLEN_OUT];
		/* ���ܺ��ʽ�������� */
	char    asInvalidFee[INFO_ACCT_BUFLEN_OUT][10];
		/* �����·� */
	char    asBillingCycleID[INFO_ACCT_BUFLEN_OUT][7];
		/* SP���� */
	char    asSpCode[INFO_ACCT_BUFLEN_OUT][21];
		/* ���ڻ��ս���б����ڷ��� */
	int     aiFee[INFO_ACCT_BUFLEN_OUT];
		/* ���ڻ��ս������ʷǷ�� */
	int     aiOweFee[INFO_ACCT_BUFLEN_OUT];
		/* ״̬ */
	char    asState[INFO_ACCT_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asDealDate[INFO_ACCT_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[INFO_ACCT_BUFLEN_OUT][41];
};
/* ����ṹ��������*/
struct InfoAcctStructIn{

#ifndef INFO_ACCT_BUFLEN_IN
#define INFO_ACCT_BUFLEN_IN		300
#endif

	struct InfoAcctStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	int     aiTicketTypeID[INFO_ACCT_BUFLEN_IN];
		/* ʡ���� */
	char    asProvinceID[INFO_ACCT_BUFLEN_IN][6];
		/* ���������� */
	char    asAreaCode[INFO_ACCT_BUFLEN_IN][6];
		/* ��¼���� */
	int     aiTotalCnt[INFO_ACCT_BUFLEN_IN];
		/* ��������� */
	int     aiTotalFee[INFO_ACCT_BUFLEN_IN];
		/* ���ʼ�¼���� */
	int     aiValidCnt[INFO_ACCT_BUFLEN_IN];
		/* ���ʽ�������� */
	int     aiValidFee[INFO_ACCT_BUFLEN_IN];
		/* ���ܺ��ʼ�¼���� */
	int     aiInvalidCnt[INFO_ACCT_BUFLEN_IN];
		/* ���ܺ��ʽ�������� */
	char    asInvalidFee[INFO_ACCT_BUFLEN_IN][10];
		/* �����·� */
	char    asBillingCycleID[INFO_ACCT_BUFLEN_IN][7];
		/* SP���� */
	char    asSpCode[INFO_ACCT_BUFLEN_IN][21];
		/* ���ڻ��ս���б����ڷ��� */
	int     aiFee[INFO_ACCT_BUFLEN_IN];
		/* ���ڻ��ս������ʷǷ�� */
	int     aiOweFee[INFO_ACCT_BUFLEN_IN];
		/* ״̬ */
	char    asState[INFO_ACCT_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asDealDate[INFO_ACCT_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[INFO_ACCT_BUFLEN_IN][41];
	char	asRowID[INFO_ACCT_BUFLEN_IN][19];
};



/*�����ṹ����*/
struct InfoAcctStruct{

	struct InfoAcctStruct *pNext;
	int     iTicketTypeID;		/* �������� */
	char    sProvinceID[6];		/* ʡ���� */
	char    sAreaCode[6];		/* ���������� */
	int     iTotalCnt;		/* ��¼���� */
	int     iTotalFee;		/* ��������� */
	int     iValidCnt;		/* ���ʼ�¼���� */
	int     iValidFee;		/* ���ʽ�������� */
	int     iInvalidCnt;		/* ���ܺ��ʼ�¼���� */
	char    sInvalidFee[10];		/* ���ܺ��ʽ�������� */
	char    sBillingCycleID[7];		/* �����·� */
	char    sSpCode[21];		/* SP���� */
	int     iFee;		/* ���ڻ��ս���б����ڷ��� */
	int     iOweFee;		/* ���ڻ��ս������ʷǷ�� */
	char    sState[2];		/* ״̬ */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* �ļ���Դ */
	char	sRowID[19];
	struct InfoAcctStruct *pLoadNext;
};

void mvitem_fminfoacct(struct FInfoAcctStruct *pi,
	struct InfoAcctStruct *po);
void mvitem_mfinfoacct(struct InfoAcctStruct *pi,
	struct FInfoAcctStruct *po);
/*�������ݽṹ����д��INFO_ACCT*/
int EInsertStructToInfoAcct(struct InfoAcctStruct *p,
	int iInsertFlag,struct InfoAcctStructOut *pTarget);
int InsertInfoAcct(char sFileName[],char sTableName[]);
/*�������ݶ�̬��INFO_ACCT���ýṹ���巽ʽȡ����*/
int EGetInfoAcctToStruct(struct InfoAcctStruct *p,
	struct InfoAcctStructIn *pSource);
int InfoAcct2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);


/*����ṹ��������*/
struct InfoNbrAcctStructOut{

#ifndef INFO_NBR_ACCT_BUFLEN_OUT
#define INFO_NBR_ACCT_BUFLEN_OUT		300
#endif

	struct InfoNbrAcctStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	int     aiTicketTypeID[INFO_NBR_ACCT_BUFLEN_OUT];
		/* '00'�޷������ļ�(���е�ʡ)'01'�굥�ļ�(ʡ������)'02'�ʵ��ļ�(ʡ���ĵ�����) */
	char    asRecordType[INFO_NBR_ACCT_BUFLEN_OUT][3];
		/* ���к��� */
	char    asCallingNbr[INFO_NBR_ACCT_BUFLEN_OUT][21];
		/* ҵ�������� */
	char    asSpAccNbr[INFO_NBR_ACCT_BUFLEN_OUT][21];
		/* ʹ�õ�ҵ����Ŀ���� */
	char    asSpServiceCode[INFO_NBR_ACCT_BUFLEN_OUT][21];
		/* ���� */
	int     aiCnt[INFO_NBR_ACCT_BUFLEN_OUT];
		/* ʱ���� */
	int     aiDuration[INFO_NBR_ACCT_BUFLEN_OUT];
		/* ���� */
	int     aiFee[INFO_NBR_ACCT_BUFLEN_OUT];
		/* ��ʼʱ�� */
	char    asStartTime[INFO_NBR_ACCT_BUFLEN_OUT][15];
		/* �������� */
	int     aiCallingTypeID[INFO_NBR_ACCT_BUFLEN_OUT];
		/* �������� */
	char    asNetType[INFO_NBR_ACCT_BUFLEN_OUT][2];
		/* ��ע */
	char    asNotes[INFO_NBR_ACCT_BUFLEN_OUT][61];
		/* ״̬ */
	char    asState[INFO_NBR_ACCT_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asDealDate[INFO_NBR_ACCT_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[INFO_NBR_ACCT_BUFLEN_OUT][41];
};

/*�����ṹ����*/
struct InfoNbrAcctStruct{

	struct InfoNbrAcctStruct *pNext;
	int     iTicketTypeID;		/* �������� */
	char    sRecordType[3];		
/* '00'�޷������ļ�(���е�ʡ)'01'�굥�ļ�(ʡ������)'02'�ʵ��ļ�(ʡ���ĵ�����) */
	char    sCallingNbr[21];		/* ���к��� */
	char    sSpAccNbr[21];		/* ҵ�������� */
	char    sSpServiceCode[21];		/* ʹ�õ�ҵ����Ŀ���� */
	int     iCnt;		/* ���� */
	int     iDuration;		/* ʱ���� */
	int     iFee;		/* ���� */
	char    sStartTime[15];		/* ��ʼʱ�� */
	int     iCallingTypeID;		/* �������� */
	char    sNetType[2];		/* �������� */
	char    sNotes[61];		/* ��ע */
	char    sState[2];		/* ״̬ */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* �ļ���Դ */
	struct InfoNbrAcctStruct *pLoadNext;
};
void mvitem_fminfonbracct(struct FInfoNbrAcctStruct *pi,
	struct InfoNbrAcctStruct *po);
/*�������ݽṹ����д��INFO_NBR_ACCT*/
int EInsertStructToInfoNbrAcct(struct InfoNbrAcctStruct *p,
	int iInsertFlag,struct InfoNbrAcctStructOut *pTarget);
int InsertInfoNbrAcct(char sFileName[],char sTableName[]);	


/*����ṹ��������*/
struct NxRhjfTicketStructOut{

#ifndef NX_RHJF_TICKET_BUFLEN_OUT
#define NX_RHJF_TICKET_BUFLEN_OUT		300
#endif

	struct NxRhjfTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������¼��ʶ */
	char    asRecordType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* �����ֹ� */
	char    asCallingRef[NX_RHJF_TICKET_BUFLEN_OUT][6];
		/* �������� */
	char    asCallingAreaCode[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* ���к��� */
	char    asCallingNbr[NX_RHJF_TICKET_BUFLEN_OUT][21];
		/* �����ֹ� */
	char    asCalledRef[NX_RHJF_TICKET_BUFLEN_OUT][6];
		/* �������� */
	char    asCalledCode[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* ���к��� */
	char    asCalledNbr[NX_RHJF_TICKET_BUFLEN_OUT][21];
		/* �û����� */
	char    asUserType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* ������Ӫ������ */
	char    asCallingCarrType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* ������Ӫ������ */
	char    asCalledCarrType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* ����������� */
	char    asCalledAreaID[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* ҵ������ */
	char    asServiceType[NX_RHJF_TICKET_BUFLEN_OUT][2];
		/* ·������ */
	char    asRouteType[NX_RHJF_TICKET_BUFLEN_OUT][2];
		/* ���� */
	char    asCardNbr[NX_RHJF_TICKET_BUFLEN_OUT][31];
		/* ���м� */
	char    asTrunkIn[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* ���м� */
	char    asTrunkOut[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* ͨ����ʼʱ�� */
	char    asStartTime[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* ͨ����ֹʱ�� */
	char    asEndTime[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* ͨ��ʱ�� */
	char    asDuration[NX_RHJF_TICKET_BUFLEN_OUT][9];
		/* �Ʒ�ʱ�� */
	char    asChargeDuration[NX_RHJF_TICKET_BUFLEN_OUT][9];
		/* ������ */
	char    asBaseFee[NX_RHJF_TICKET_BUFLEN_OUT][13];
		/* �Żݷ� */
	char    asDisctFee[NX_RHJF_TICKET_BUFLEN_OUT][13];
		/* �ܷ��� */
	char    asTotalFee[NX_RHJF_TICKET_BUFLEN_OUT][13];
		/* ����ʱ�� */
	char    asUpdateDate[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* ����ʱ�� */
	char    asDealDate[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* ������Դ */
	char    asSourceID[NX_RHJF_TICKET_BUFLEN_OUT][41];
};

/*�����ṹ����*/
struct NxRhjfTicketStruct{

	struct NxRhjfTicketStruct *pNext;
	char    sRecordType[3];		/* ������¼��ʶ */
	char    sCallingRef[6];		/* �����ֹ� */
	char    sCallingAreaCode[11];		/* �������� */
	char    sCallingNbr[21];		/* ���к��� */
	char    sCalledRef[6];		/* �����ֹ� */
	char    sCalledCode[11];		/* �������� */
	char    sCalledNbr[21];		/* ���к��� */
	char    sUserType[3];		/* �û����� */
	char    sCallingCarrType[3];		/* ������Ӫ������ */
	char    sCalledCarrType[3];		/* ������Ӫ������ */
	char    sCalledAreaID[11];		/* ����������� */
	char    sServiceType[2];		/* ҵ������ */
	char    sRouteType[2];		/* ·������ */
	char    sCardNbr[31];		/* ���� */
	char    sTrunkIn[11];		/* ���м� */
	char    sTrunkOut[11];		/* ���м� */
	char    sStartTime[15];		/* ͨ����ʼʱ�� */
	char    sEndTime[15];		/* ͨ����ֹʱ�� */
	char    sDuration[9];		/* ͨ��ʱ�� */
	char    sChargeDuration[9];		/* �Ʒ�ʱ�� */
	char    sBaseFee[13];		/* ������ */
	char    sDisctFee[13];		/* �Żݷ� */
	char    sTotalFee[13];		/* �ܷ��� */
	char    sUpdateDate[15];		/* ����ʱ�� */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sSourceID[41];		/* ������Դ */
	struct NxRhjfTicketStruct *pLoadNext;
};
void mvitem_fmnxrhjfticket(struct FNxRhjfTicketStruct *pi,struct NxRhjfTicketStruct *po);
/*�������ݽṹ����д��NX_RHJF_TICKET*/
int EInsertStructToNxRhjfTicket(struct NxRhjfTicketStruct *p,
	int iInsertFlag,struct NxRhjfTicketStructOut *pTarget);
int InsertNxRhjfTicket(char sFileName[],char sTableName[]);


/*����ṹ��������*/
struct ServCardStructOut{

#ifndef SERV_CARD_BUFLEN_OUT
#define SERV_CARD_BUFLEN_OUT		300
#endif

	struct ServCardStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ���� */
	char    asAccNbr[SERV_CARD_BUFLEN_OUT][16];
		/* ���� */
	char    asAreaCode[SERV_CARD_BUFLEN_OUT][6];
		/* �ֹ�˾���� */
	char    asAreaCodeName[SERV_CARD_BUFLEN_OUT][21];
		/* Ӫҵ������ */
	char    asAreaName[SERV_CARD_BUFLEN_OUT][21];
		/* �ͻ����� */
	char    asCustNane[SERV_CARD_BUFLEN_OUT][31];
		/* ��������'201'Ϊ201������'202'Ϊic������ */
	int     aiTypeID[SERV_CARD_BUFLEN_OUT];
};


/* ����ṹ��������*/
struct ServCardStructIn{

#ifndef SERV_CARD_BUFLEN_IN
#define SERV_CARD_BUFLEN_IN		300
#endif

	struct ServCardStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ���� */
	char    asAccNbr[SERV_CARD_BUFLEN_IN][16];
		/* ���� */
	char    asAreaCode[SERV_CARD_BUFLEN_IN][6];
		/* �ֹ�˾���� */
	char    asAreaCodeName[SERV_CARD_BUFLEN_IN][21];
		/* Ӫҵ������ */
	char    asAreaName[SERV_CARD_BUFLEN_IN][21];
		/* �ͻ����� */
	char    asCustNane[SERV_CARD_BUFLEN_IN][31];
		/* ��������'201'Ϊ201������'202'Ϊic������ */
	int     aiTypeID[SERV_CARD_BUFLEN_IN];
};


/*�����ṹ����*/
struct ServCardStruct{

	struct ServCardStruct *pNext;
	char    sAccNbr[16];		/* ���� */
	char    sAreaCode[6];		/* ���� */
	char    sAreaCodeName[21];		/* �ֹ�˾���� */
	char    sAreaName[21];		/* Ӫҵ������ */
	char    sCustNane[31];		/* �ͻ����� */
	int     iTypeID;		
	/* ��������'201'Ϊ201������'202'Ϊic������ */
	struct ServCardStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FServCardStruct{

	char    sAccNbr[15];		/* ���� */
	char    sAreaCode[5];		/* ���� */
	char    sAreaCodeName[20];		/* �ֹ�˾���� */
	char    sAreaName[20];		/* Ӫҵ������ */
	char    sCustNane[30];		/* �ͻ����� */
	char    sTypeID[4];		/* ��������'201'Ϊ201������'202'Ϊic������ */
};


/*�������ݽṹ����д��SERV_CARD*/
int EInsertStructToServCard(struct ServCardStruct *p,
	int iInsertFlag,struct ServCardStructOut *pTarget);

/*�������ݶ�̬��SERV_CARD���ýṹ���巽ʽȡ����*/
int EGetServCardToStruct(struct ServCardStruct *p,
	struct ServCardStructIn *pSource);
void mvitem_fmservcard(struct FServCardStruct *pi,struct ServCardStruct *po);
void mvitem_mfservcard(struct ServCardStruct *pi,struct FServCardStruct *po);
int InsertServCard(char sFileName[],char sTableName[]);

int data_search_bintree_serv_card_e(void *pValue,void*pData);
void assign_insert_bintree_serv_card_e(void **ppData,void *pData);
void assign_insert_bintree_out_accnbr_e(void **ppData,void *pData);
int data_search_bintree_out_accnbr_e(void *pValue,void*pData);
int rdata_search_bintree_msisdn_stat_e(void *pValue,void*pData);
void assign_insert_bintree_msisdn_stat_e(void **ppData,void *pData);
int data_search_bintree_msisdn_stat_e(void *pValue,void*pData);
/*�����ṹ����*/
struct OutAccNbrStruct{

	struct OutAccNbrStruct *pNext;
	char    sCustNane[31];		/* �ͻ����� */
	char    sAreaCodeName[21];	/* �ֹ�˾���� */
	char    sAreaName[21];		/* Ӫҵ������ */
	int	iUserCnt;		/*��������*/
	int	iUserFeeCnt;		/*����ͨ���ѻ�������*/
	int	iUserLcCnt;		/*��λ�����*/
	int	iToTalFee;		/*�ͻ������ܻ�����*/
	int	iUserFee;		/*����������*/
	char    sAreaCode[6];		/* ���� */
	char    sAccNbr[16];		/* ���� */
	int     iTypeID;		
	char	sOutFileName[30];	/*����ļ���*/
	/* ��������'201'Ϊ201������'202'Ϊic������ */
	struct OutAccNbrStruct *pLoadNext;
};

/*�����ṹ����*/
struct NbrStatStruct{

	struct NbrStatStruct *pNext;
	char    sRecordType[3];		
/* ��¼����01���02©��03�ϱ����뷢������04�ϱ���������05����������� */
/*06���������Ŀͻ�07������������λ�*/
	char    sAccNbr[16];		/* ���� */
	char	sServiceType[11];	/* 000���С�xxx�Զ��� */
	char    sAreaCode[6];		/* ���� */
	int	iToTalFee;		/*�ͻ������ܻ�����*/
	char    sBillingCycleID[7];	/* �ʵ��������� */	
	char	sOutFileName[30];	/*����ļ���*/
	struct NbrStatStruct *pLoadNext;
};
int data_search_bintree_nbr_stat_e(void *pValue,void*pData);

/*�����ṹ����*/
struct MsisdnStatStruct{

	struct MsisdnStatStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sAreaCode[10];		/* �������� */
	int     iAreaID;		/* ����Ӫҵ�� */
	char    sNetType[4];		
/* 'CT' ���� 'CNC' ��ͨ,'CU' ��ͨ,'CM' �ƶ�,'IMS' IMSI,'ESN' ���Ӵ��� */	
	char    sCallType[3];		/* 00���С�01���С�02���С�03��ת */
	char    sServiceType[11];		/* 000���С�xxx�Զ��� */
	LONGINT iTotalDuration;		/* ��ʱ�� */
	LONGINT iTotalMin;		/* �ܷ�����*60 */
	int     iTotalCnt;		/* �ܴ��� */
	LONGINT iTotalFee1;		/* �ܷ���1 */
	LONGINT iTotalFee2;		/* �ܷ���2 */
	LONGINT iTotalFee3;		/* �ܷ���3 */
	char    sBillingCycleID[7];		/* �ʵ��������� */
	char    sRowID[19];             /* ��¼���� */
	struct MsisdnStatStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FMsisdnStatStruct{

	char    sMsisdn[15];
	char    sAreaCode[9];
	char    sAreaID[4];
	char    sNetType[3];
	char    sCallType[2];
	char    sServiceType[10];
	char    sTotalDuration[12];
	char    sTotalMin[12];
	char    sTotalCnt[9];
	char    sTotalFee1[12];
	char    sTotalFee2[12];
	char    sTotalFee3[12];
	char    sBillingCycleID[6];
};

/* ����ṹ��������*/
struct MsisdnStatStructIn{

#ifndef MSISDN_STAT_BUFLEN_IN
#define MSISDN_STAT_BUFLEN_IN		300
#endif

	struct MsisdnStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �û����� */
	char    asMsisdn[MSISDN_STAT_BUFLEN_IN][16];
		/* �������� */
	char    asAreaCode[MSISDN_STAT_BUFLEN_IN][10];
		/* ����Ӫҵ�� */
	int     aiAreaID[MSISDN_STAT_BUFLEN_IN];
		/* 'CT' ���� 'CNC' ��ͨ,'CU' ��ͨ,'CM' �ƶ�,'IMS' IMSI,'ESN' ���Ӵ��� */
	char    asNetType[MSISDN_STAT_BUFLEN_IN][4];
		/* 00���С�01���С�02���С�03��ת */
	char    asCallType[MSISDN_STAT_BUFLEN_IN][3];
		/* 000���С�xxx�Զ��� */
	char    asServiceType[MSISDN_STAT_BUFLEN_IN][11];
		/* ��ʱ�� */
	LONGINT aiTotalDuration[MSISDN_STAT_BUFLEN_IN];
		/* �ܷ�����*60 */
	LONGINT aiTotalMin[MSISDN_STAT_BUFLEN_IN];
		/* �ܴ��� */
	int     aiTotalCnt[MSISDN_STAT_BUFLEN_IN];
		/* �ܷ���1 */
	LONGINT aiTotalFee1[MSISDN_STAT_BUFLEN_IN];
		/* �ܷ���2 */
	LONGINT aiTotalFee2[MSISDN_STAT_BUFLEN_IN];
		/* �ܷ���3 */
	LONGINT aiTotalFee3[MSISDN_STAT_BUFLEN_IN];
		/* �ʵ��������� */
	char    asBillingCycleID[MSISDN_STAT_BUFLEN_IN][7];
	        /* ��¼���� */
        char    asRowID[MSISDN_STAT_BUFLEN_IN][19];
};

/*����ṹ��������*/
struct MsisdnStatStructOut{

#ifndef MSISDN_STAT_BUFLEN_OUT
#define MSISDN_STAT_BUFLEN_OUT		300
#endif

	struct MsisdnStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asMsisdn[MSISDN_STAT_BUFLEN_OUT][16];
		/* �������� */
	char    asAreaCode[MSISDN_STAT_BUFLEN_OUT][10];
		/* ����Ӫҵ�� */
	int     aiAreaID[MSISDN_STAT_BUFLEN_OUT];
		/* 'CT' ���� 'CNC' ��ͨ,'CU' ��ͨ,'CM' �ƶ�,'IMS' IMSI,'ESN' ���Ӵ��� */
	char    asNetType[MSISDN_STAT_BUFLEN_OUT][4];
		/* 00���С�01���С�02���С�03��ת */
	char    asCallType[MSISDN_STAT_BUFLEN_OUT][3];
		/* 000���С�xxx�Զ��� */
	char    asServiceType[MSISDN_STAT_BUFLEN_OUT][11];
		/* ��ʱ�� */
	LONGINT aiTotalDuration[MSISDN_STAT_BUFLEN_OUT];
		/* �ܷ�����*60 */
	LONGINT aiTotalMin[MSISDN_STAT_BUFLEN_OUT];
		/* �ܴ��� */
	int     aiTotalCnt[MSISDN_STAT_BUFLEN_OUT];
		/* �ܷ���1 */
	LONGINT aiTotalFee1[MSISDN_STAT_BUFLEN_OUT];
		/* �ܷ���2 */
	LONGINT aiTotalFee2[MSISDN_STAT_BUFLEN_OUT];
		/* �ܷ���3 */
	LONGINT aiTotalFee3[MSISDN_STAT_BUFLEN_OUT];
		/* �ʵ��������� */
	char    asBillingCycleID[MSISDN_STAT_BUFLEN_OUT][7];
};


/*UP�ṹ��������*/
struct MsisdnStatStructUp{

#ifndef MSISDN_STAT_BUFLEN_UP
#define MSISDN_STAT_BUFLEN_UP		300
#endif

	struct MsisdnStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asMsisdn[MSISDN_STAT_BUFLEN_UP][16];
		/* �������� */
	char    asAreaCode[MSISDN_STAT_BUFLEN_UP][10];
		/* ����Ӫҵ�� */
	int     aiAreaID[MSISDN_STAT_BUFLEN_UP];
		/* 'CT' ���� 'CNC' ��ͨ,'CU' ��ͨ,'CM' �ƶ�,'IMS' IMSI,'ESN' ���Ӵ��� */
	char    asNetType[MSISDN_STAT_BUFLEN_UP][4];
		/* 00���С�01���С�02���С�03��ת */
	char    asCallType[MSISDN_STAT_BUFLEN_UP][3];
		/* 000���С�xxx�Զ��� */
	char    asServiceType[MSISDN_STAT_BUFLEN_UP][11];
		/* ��ʱ�� */
	LONGINT aiTotalDuration[MSISDN_STAT_BUFLEN_UP];
		/* �ܷ����� */
	LONGINT	aiTotalMin[MSISDN_STAT_BUFLEN_UP];
		/* �ܴ��� */
	int     aiTotalCnt[MSISDN_STAT_BUFLEN_UP];
		/* �ܷ���1 */
	LONGINT aiTotalFee1[MSISDN_STAT_BUFLEN_UP];
		/* �ܷ���2 */
	LONGINT aiTotalFee2[MSISDN_STAT_BUFLEN_UP];
		/* �ܷ���3 */
	LONGINT aiTotalFee3[MSISDN_STAT_BUFLEN_UP];
		/* �ʵ��������� */
	char    asBillingCycleID[MSISDN_STAT_BUFLEN_UP][7];
	char    asRowID[MSISDN_STAT_BUFLEN_UP][19];
};

/*�������ݽṹ����д��MSISDN_STAT*/
int EInsertStructToMsisdnStat(struct MsisdnStatStruct *p,
	int iInsertFlag,struct MsisdnStatStructOut *pTarget);
/*�������ݶ�̬��MSISDN_STAT���ýṹ���巽ʽȡ����*/
int EGetMsisdnStatToStruct(struct MsisdnStatStruct *p,
	struct MsisdnStatStructIn *pSource);
/*�������ݽṹ�������MSISDN_STAT*/
int EUpdateStructToMsisdnStat(struct MsisdnStatStruct *p,
	int iUpdateFlag,struct MsisdnStatStructUp *pTarget);	
void mvitem_msisdnstat(struct MsisdnStatStruct *pi,struct MsisdnStatStruct *po);	
int data_search_bintree_msisdn_stat_e(void *pValue,void*pData);
void assign_insert_bintree_msisdn_stat_e(void **ppData,void *pData);

void mvitem_mfmsisdnstat(struct MsisdnStatStruct *pi,
	struct FMsisdnStatStruct *po);
int MsisdnStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*�����ṹ����*/
struct SettDayStruct{

	struct SettDayStruct *pNext;
	int     iRecordNumber;		/* ��¼�к� */
	char    sHomeAreaCode[6];		/* ���б������������� */
	char    sCalledCode[6];		/* ���б������������� */
	char    sStartDate[9];		/* ͨ������ */
	char    sCallingCarrierID[6];		/* ������Ӫ�̱�ʶ */
	char    sCalledCarrierID[6];		/* ������Ӫ�̱�ʶ */
	char    sThirdCarrierID[6];		/* ת����Ӫ�̱�ʶ */
	char    sSettCarrierID[6];		/* ������Ӫ�̱�ʶ */
	char    sSettType[13];		/* ������Ŀ��ʶ */
	char    sRoamType[2];		/* �ƶ����α�־ */
	char    sTariffType[3];		/* ������� */
	char    sCountyFlag[2];		/* ���������� */
	char    sIpAccNbr[9];		/* IP����� */
	char    sDurationCnt[16];		/* ͨ������ */
	char    sDuration[16];		/* ͨ��ʱ�� */
	char    sSettCnt[16];		/* �������� */
	char    sTotalFee[16];		/* ������� */
	char    sCount[16];		/* ������ */
	struct SettDayStruct *pLoadNext;
};
/*�����ṹ����*/
struct SettMonthStruct{

	struct SettMonthStruct *pNext;
	int     iRecordNumber;		/* ��¼�к� */
	char    sVisitAreaCode[6];		/* �������������� */
	char    sStatMonth[7];		/* �����·� */
	char    sSettCarrierID[6];		/* ������Ӫ�̱�ʶ */
	char    sSettType[13];		/* ������Ŀ��ʶ */
	char    sDurationCnt[16];		/* ͨ������ */
	char    sDuration[16];		/* ͨ��ʱ�� */
	char    sSettCnt[16];		/* �������� */
	char    sTotalFee[16];		/* ������� */
	char    sCount[16];		/* ������ */
	struct SettMonthStruct *pLoadNext;
};

/*�����ṹ����*/
struct CustCntStruct{

	struct CustCntStruct *pNext;
	int     iRecordNumber;		/* ��¼�к� */
	char    sStatMonth[7];		/* ͳ���·� */
	char    sOppCarrierID[6];		/* ������Ӫ�̱�ʶ */
	int     iCustCnt;		/* �ͻ��� */
	int     iAddCustCnt;		/* �����ͻ��� */
	struct CustCntStruct *pLoadNext;
};


/*�����ṹ����*/
struct SmsStatUpStruct{

	struct SmsStatUpStruct *pNext;
	char    sSettCapitalCode[4];		/* ����ʡ��˾��ʶ */
	char    sBillType[2];		/* �������� */
	char    sBillingCycleID[7];		/* ʵ���·� */
	char    sSettAreaCode[4];		/* ���㱾������ʶ */
	char    sCallingCarrierID[3];		/* ����������Ӫ�̱�ʶ */
	char    sRecordType[4];		/* ��¼���� */
	char    sCalledCapitalCode[4];		/* ��������ʡ��˾��ʶ */
	char    sCalledCarrierID[3];		/* ����������Ӫ�̱�ʶ */
	char    sSpCode[11];		/* SP��ҵ��� */
	char    sTotalCnt[16];		/* ������ */
	char    sTotalFee[16];		/* �ܽ�� */
	char    sFlag[2];		/* ������־ */
	char    sReserve[11];		/* ���� */
	struct SmsStatUpStruct *pLoadNext;
};

struct SmsStatUpHeadStruct{
	
	struct SmsStatUpHeadStruct *pNext;
	char	sServiceCode[5];	/*ҵ�����*/
	char	CapitalCode[4];		/* ʡ��˾��ʶ */
	char	sCreateDate[9];		/*�ļ���������*/
	int	iFileCnt;		/*��Ч��¼��*/
	char	sTotalCnt[16];		/*������*/
	char	sTotalFee[16];		/*�ܽ��*/
	char	sReserve[20];		/*����*/
	struct SmsStatUpHeadStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FSettDayStruct{

	char    sRecordNumber[8];		/* ��¼�к� */
	char    sHomeAreaCode[5];		/* ���б������������� */
	char    sCalledCode[5];		/* ���б������������� */
	char    sStartDate[8];		/* ͨ������ */
	char    sCallingCarrierID[5];		/* ������Ӫ�̱�ʶ */
	char    sCalledCarrierID[5];		/* ������Ӫ�̱�ʶ */
	char    sThirdCarrierID[5];		/* ת����Ӫ�̱�ʶ */
	char    sSettCarrierID[5];		/* ������Ӫ�̱�ʶ */
	char    sSettType[12];		/* ������Ŀ��ʶ */
	char    sRoamType[1];		/* �ƶ����α�־ */
	char    sTariffType[2];		/* ������� */
	char    sCountyFlag[1];		/* ���������� */
	char    sIpAccNbr[8];		/* IP����� */
	char    sDurationCnt[15];		/* ͨ������ */
	char    sDuration[15];		/* ͨ��ʱ�� */
	char    sSettCnt[15];		/* �������� */
	char    sTotalFee[15];		/* ������� */
	char    sCount[15];		/* ������ */
};


/*�����ļ��ṹ����*/
struct FSettMonthStruct{

	char    sRecordNumber[8];		/* ��¼�к� */
	char    sVisitAreaCode[5];		/* �������������� */
	char    sStatMonth[6];		/* �����·� */
	char    sSettCarrierID[5];		/* ������Ӫ�̱�ʶ */
	char    sSettType[12];		/* ������Ŀ��ʶ */
	char    sDurationCnt[15];		/* ͨ������ */
	char    sDuration[15];		/* ͨ��ʱ�� */
	char    sSettCnt[15];		/* �������� */
	char    sTotalFee[15];		/* ������� */
	char    sCount[15];		/* ������ */
};


/*�����ļ��ṹ����*/
struct FCustCntStruct{

	char    sRecordNumber[8];		/* ��¼�к� */
	char    sStatMonth[6];		/* ͳ���·� */
	char    sOppCarrierID[5];		/* ������Ӫ�̱�ʶ */
	char    sCustCnt[8];		/* �ͻ��� */
	char    sAddCustCnt[8];		/* �����ͻ��� */
};


/*�����ļ��ṹ����*/
struct FSmsStatUpStruct{

	char    sSettCapitalCode[3];	/* ����ʡ��˾��ʶ */
	char    sBillType[1];		/* �������� */
	char    sBillingCycleID[6];		/* ʵ���·� */
	char    sSettAreaCode[3];		/* ���㱾������ʶ */
	char    sCallingCarrierID[2];		/* ����������Ӫ�̱�ʶ */
	char    sRecordType[3];		/* ��¼���� */
	char    sCalledCapitalCode[3];		/* ��������ʡ��˾��ʶ */
	char    sCalledCarrierID[2];		/* ����������Ӫ�̱�ʶ */
	char    sSpCode[10];		/* SP��ҵ��� */
	char    sTotalCnt[15];		/* ������ */
	char    sTotalFee[15];		/* �ܽ�� */
	char    sFlag[1];		/* ������־ */
	char    sReserve[10];		/* ���� */
};

struct FSmsStatUpHeadStruct{

	char	sServiceCode[4];	/*ҵ�����*/
	char	CapitalCode[3];		/* ʡ��˾��ʶ */
	char	sCreateDate[8];		/*�ļ���������*/
	char	sFileCnt[6];		/*��Ч��¼��*/
	char	sTotalCnt[15];		/*������*/
	char	sTotalFee[15];		/*�ܽ��*/
	char	sReserve[19];		/*����*/
};



/*�����ṹ����*/
struct SettTypeRelationStruct{

	struct SettTypeRelationStruct *pNext;
	int     iTicketTypeID;		/* �������� */
	char    sSettType[13];		/* ������Ŀ��ʶ */
	char    sCarrierID[6];		/* ������Ӫ�̱�ʶ */
	char    sTariffType[3];		/* ������� */
	int     iPriority;		/* ���ȼ� */
	char    sUserType[2];		/* �û����� */
	char    sCountyFlag[2];		/* �����������ʶ */
	char    sRemark[81];		/* ���� */
	struct SettTypeRelationStruct *pLoadNext;
};

/* ����ṹ��������*/
struct SettTypeRelationStructIn{

#ifndef SETT_TYPE_RELATION_BUFLEN_IN
#define SETT_TYPE_RELATION_BUFLEN_IN		300
#endif

	struct SettTypeRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	int     aiTicketTypeID[SETT_TYPE_RELATION_BUFLEN_IN];
		/* ������Ŀ��ʶ */
	char    asSettType[SETT_TYPE_RELATION_BUFLEN_IN][13];
		/* ������Ӫ�̱�ʶ */
	char    asCarrierID[SETT_TYPE_RELATION_BUFLEN_IN][6];
		/* ������� */
	char    asTariffType[SETT_TYPE_RELATION_BUFLEN_IN][3];
		/* ���ȼ� */
	int     aiPriority[SETT_TYPE_RELATION_BUFLEN_IN];
		/* �û����� */
	char    asUserType[SETT_TYPE_RELATION_BUFLEN_IN][2];
		/* �����������ʶ */
	char    asCountyFlag[SETT_TYPE_RELATION_BUFLEN_IN][2];
		/* ���� */
	char    asRemark[SETT_TYPE_RELATION_BUFLEN_IN][81];
};



int EGetSettTypeRelationToStruct(struct SettTypeRelationStruct *p,
	struct SettTypeRelationStructIn *pSource);
	
void mvitem_mfsettday(struct SettDayStruct *pi,struct FSettDayStruct *po);
void mvitem_mfcustcnt(struct CustCntStruct *pi,struct FCustCntStruct *po);
int data_search_bintree_sett_type_r_e(void *pValue,void*pData);
void assign_insert_bintree_sett_type_r_e(void **ppData,void *pData);
int rdata_search_bintree_sett_type_r_e(void *pValue,void*pData);
int data_search_bintree_sett_day_e(void *pValue,void*pData);
void assign_insert_bintree_sett_day_e(void **ppData,void *pData);

void mvitem_mfsettmonth(struct SettMonthStruct *pi,
	struct FSettMonthStruct *po);
void mvitem_mfsmsstatup(struct SmsStatUpStruct *pi,
	struct FSmsStatUpStruct *po);
void mvitem_mfsmsstatuphead(struct SmsStatUpHeadStruct *pi,
	struct FSmsStatUpHeadStruct *po);

/*����ṹ��������*/
struct SettSumDayStructOut{

#ifndef SETT_SUM_DAY_BUFLEN_OUT
#define SETT_SUM_DAY_BUFLEN_OUT		300
#endif

	struct SettSumDayStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	int     aiTicketTypeID[SETT_SUM_DAY_BUFLEN_OUT];
		/* ��������ʶ */
	char    asVisitAreaCode[SETT_SUM_DAY_BUFLEN_OUT][6];
		/* ͳ���·� */
	char    asStatMonth[SETT_SUM_DAY_BUFLEN_OUT][7];
		/* ���й������� */
	char    asHomeAreaCode[SETT_SUM_DAY_BUFLEN_OUT][6];
		/* ���й������� */
	char    asCalledCode[SETT_SUM_DAY_BUFLEN_OUT][6];
		/* ͨ������ */
	char    asStartDate[SETT_SUM_DAY_BUFLEN_OUT][9];
		/* ������Ӫ�̱�ʶ */
	int     aiCallingCarrierID[SETT_SUM_DAY_BUFLEN_OUT];
		/* ������Ӫ�̱�ʶ */
	int     aiCalledCarrierID[SETT_SUM_DAY_BUFLEN_OUT];
		/* ת����Ӫ�̱�ʶ */
	int     aiThirdCarrierID[SETT_SUM_DAY_BUFLEN_OUT];
		/* �ƶ����α�־ */
	char    asUserType[SETT_SUM_DAY_BUFLEN_OUT][2];
		/* IP����� */
	char    asIpAccNbr[SETT_SUM_DAY_BUFLEN_OUT][9];
		/* ͨ������ */
	int     aiDurationCnt[SETT_SUM_DAY_BUFLEN_OUT];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_SUM_DAY_BUFLEN_OUT];
		/* �������� */
	int     aiSettCnt[SETT_SUM_DAY_BUFLEN_OUT];
		/* ������� */
	int     aiTotalFee[SETT_SUM_DAY_BUFLEN_OUT];
		/* ������ */
	int     aiCount[SETT_SUM_DAY_BUFLEN_OUT];
		/* ״̬ */
	char    asState[SETT_SUM_DAY_BUFLEN_OUT][2];
		/* ����ʱ�� */
	char    asDealDate[SETT_SUM_DAY_BUFLEN_OUT][15];
};


/* ����ṹ��������*/
struct SettSumDayStructIn{

#ifndef SETT_SUM_DAY_BUFLEN_IN
#define SETT_SUM_DAY_BUFLEN_IN		300
#endif

	struct SettSumDayStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	int     aiTicketTypeID[SETT_SUM_DAY_BUFLEN_IN];
		/* ��������ʶ */
	char     asVisitAreaCode[SETT_SUM_DAY_BUFLEN_IN][6];
		/* ͳ���·� */
	char    asStatMonth[SETT_SUM_DAY_BUFLEN_IN][7];
		/* ���й������� */
	char    asHomeAreaCode[SETT_SUM_DAY_BUFLEN_IN][6];
		/* ���й������� */
	char    asCalledCode[SETT_SUM_DAY_BUFLEN_IN][6];
		/* ͨ������ */
	char    asStartDate[SETT_SUM_DAY_BUFLEN_IN][9];
		/* ������Ӫ�̱�ʶ */
	int     aiCallingCarrierID[SETT_SUM_DAY_BUFLEN_IN];
		/* ������Ӫ�̱�ʶ */
	int     aiCalledCarrierID[SETT_SUM_DAY_BUFLEN_IN];
		/* ת����Ӫ�̱�ʶ */
	int     aiThirdCarrierID[SETT_SUM_DAY_BUFLEN_IN];
		/* �ƶ����α�־ */
	char    asUserType[SETT_SUM_DAY_BUFLEN_IN][2];
		/* IP����� */
	char    asIpAccNbr[SETT_SUM_DAY_BUFLEN_IN][9];
		/* ͨ������ */
	int     aiDurationCnt[SETT_SUM_DAY_BUFLEN_IN];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_SUM_DAY_BUFLEN_IN];
		/* �������� */
	int     aiSettCnt[SETT_SUM_DAY_BUFLEN_IN];
		/* ������� */
	int     aiTotalFee[SETT_SUM_DAY_BUFLEN_IN];
		/* ������ */
	int     aiCount[SETT_SUM_DAY_BUFLEN_IN];
		/* ״̬ */
	char    asState[SETT_SUM_DAY_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asDealDate[SETT_SUM_DAY_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SettSumDayStruct{

	struct SettSumDayStruct *pNext;
	int     iTicketTypeID;		/* �������� */
	char    sVisitAreaCode[6];		/* ��������ʶ */
	char    sStatMonth[7];		/* ͳ���·� */
	char    sHomeAreaCode[6];		/* ���й������� */
	char    sCalledCode[6];		/* ���й������� */
	char    sStartDate[9];		/* ͨ������ */
	int     iCallingCarrierID;		/* ������Ӫ�̱�ʶ */
	int     iCalledCarrierID;		/* ������Ӫ�̱�ʶ */
	int     iThirdCarrierID;		/* ת����Ӫ�̱�ʶ */
	char    sUserType[2];		/* �ƶ����α�־ */
	char    sIpAccNbr[9];		/* IP����� */
	int     iDurationCnt;		/* ͨ������ */
	int     iDuration;		/* ͨ��ʱ�� */
	int     iSettCnt;		/* �������� */
	int     iTotalFee;		/* ������� */
	int     iCount;		/* ������ */
	char    sState[2];		/* ״̬ */
	char    sDealDate[15];		/* ����ʱ�� */
	struct SettSumDayStruct *pLoadNext;
};


/*�������ݶ�̬��SETT_SUM_DAY���ýṹ���巽ʽȡ����*/
int EGetSettSumDayToStruct(struct SettSumDayStruct *p,
	struct SettSumDayStructIn *pSource);
/*�������ݽṹ����д��SETT_SUM_DAY*/
int EInsertStructToSettSumDay(struct SettSumDayStruct *p,
	int iInsertFlag,struct SettSumDayStructOut *pTarget);


/* ����ṹ��������*/
struct DownTollStatStructIn{

#ifndef DOWN_TOLL_STAT_BUFLEN_IN
#define DOWN_TOLL_STAT_BUFLEN_IN		300
#endif

	struct DownTollStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �����û���� */
	char    asCallingUserType[DOWN_TOLL_STAT_BUFLEN_IN][2];
		/* ����д��� */
	char    asInCityCode[DOWN_TOLL_STAT_BUFLEN_IN][4];
		/* �����д��� */
	char    asOutCityCout[DOWN_TOLL_STAT_BUFLEN_IN][4];
		/* ���򱾵�GSM�û���;���� */
	char    asTollFee1[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵�GSM�û�ͨ������ʱ�� */
	char    asDuration1[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵�GSM�û����д��� */
	char    asCnt1[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵�CDMA�û���;���� */
	char    asTollFee2[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵�CDMA�û�ͨ������ʱ�� */
	char    asDuration2[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵�CDMA�û����д��� */
	char    asCnt2[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵������û���;���� */
	char    asTollFee3[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵������û�ͨ������ʱ�� */
	char    asDuration3[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* ���򱾵������û����д��� */
	char    asCnt3[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* �����·� */
	char    asSettMonth[DOWN_TOLL_STAT_BUFLEN_IN][7];
};

/*�����ṹ����*/
struct DownTollStatStruct{

	struct DownTollStatStruct *pNext;
	char    sCallingUserType[2];		/* �����û���� */
	char    sInCityCode[4];		/* ����д��� */
	char    sOutCityCout[4];		/* �����д��� */
	char    sTollFee1[11];		/* ���򱾵�GSM�û���;���� */
	char    sDuration1[11];		/* ���򱾵�GSM�û�ͨ������ʱ�� */
	char    sCnt1[11];		/* ���򱾵�GSM�û����д��� */
	char    sTollFee2[11];		/* ���򱾵�CDMA�û���;���� */
	char    sDuration2[11];		/* ���򱾵�CDMA�û�ͨ������ʱ�� */
	char    sCnt2[11];		/* ���򱾵�CDMA�û����д��� */
	char    sTollFee3[11];		/* ���򱾵������û���;���� */
	char    sDuration3[11];		/* ���򱾵������û�ͨ������ʱ�� */
	char    sCnt3[11];		/* ���򱾵������û����д��� */
	char    sSettMonth[7];		/* �����·� */
	struct DownTollStatStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FDownTollStatStruct{

	char    sCallingUserType[1];		/* �����û���� */
	char    sInCityCode[3];		/* ����д��� */
	char    sOutCityCout[3];		/* �����д��� */
	char    sTollFee1[10];		/* ���򱾵�GSM�û���;���� */
	char    sDuration1[10];		/* ���򱾵�GSM�û�ͨ������ʱ�� */
	char    sCnt1[10];		/* ���򱾵�GSM�û����д��� */
	char    sTollFee2[10];		/* ���򱾵�CDMA�û���;���� */
	char    sDuration2[10];		/* ���򱾵�CDMA�û�ͨ������ʱ�� */
	char    sCnt2[10];		/* ���򱾵�CDMA�û����д��� */
	char    sTollFee3[10];		/* ���򱾵������û���;���� */
	char    sDuration3[10];		/* ���򱾵������û�ͨ������ʱ�� */
	char    sCnt3[10];		/* ���򱾵������û����д��� */
	char    sSettMonth[6];		/* �����·� */
};

/* ����ṹ��������*/
struct DownVoipStatStructIn{

#ifndef DOWN_VOIP_STAT_BUFLEN_IN
#define DOWN_VOIP_STAT_BUFLEN_IN		300
#endif

	struct DownVoipStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ���к������ */
	char    asCallingUserType[DOWN_VOIP_STAT_BUFLEN_IN][2];
		/* ����д��� */
	char    asInCityCode[DOWN_VOIP_STAT_BUFLEN_IN][4];
		/* �����д��� */
	char    asOutCityCout[DOWN_VOIP_STAT_BUFLEN_IN][4];
		/* ��ʡ�ַ��п���ҵ�񲦴����GSM�û���;���� */
	char    asTollFee1[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ�ñ�ʡ�ַ��п���ҵ�񲦴����GSM�û�����ʱ�� */
	char    asDuration1[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ�ñ�ʡ�ַ��п���ҵ�񲦴����GSM�û����д��� */
	char    asCnt1[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û���;���� */
	char    asTollFee2[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û�����ʱ�� */
	char    asDuration2[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û����д��� */
	char    asCnt2[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û���;���� */
	char    asTollFee3[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û�����ʱ�� */
	char    asDuration3[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û����д��� */
	char    asCnt3[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴����GSM�û���;���� */
	char    asTollFee4[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴����GSM�û�����ʱ�� */
	char    asDuration4[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴����GSM�û����д��� */
	char    asCnt4[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴����CDAM�û���;���� */
	char    asTollFee5[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴����CDAM�û�����ʱ�� */
	char    asDuration5[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴����CDAM�û����д��� */
	char    asCnt5[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴���������û���;���� */
	char    asTollFee6[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴���������û�����ʱ�� */
	char    asDuration6[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* ʹ������ר��ҵ�񲦴���������û����д��� */
	char    asCnt6[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* �����·� */
	char    asSettMonth[DOWN_VOIP_STAT_BUFLEN_IN][7];
};

/*�����ṹ����*/
struct DownVoipStatStruct{

	struct DownVoipStatStruct *pNext;
	char    sCallingUserType[2];		/* ���к������ */
	char    sInCityCode[4];		/* ����д��� */
	char    sOutCityCout[4];		/* �����д��� */
	char    sTollFee1[11];		/* ��ʡ�ַ��п���ҵ�񲦴����GSM�û���;���� */
	char    sDuration1[11];		/* ʹ�ñ�ʡ�ַ��п���ҵ�񲦴����GSM�û�����ʱ�� */
	char    sCnt1[11];		/* ʹ�ñ�ʡ�ַ��п���ҵ�񲦴����GSM�û����д��� */
	char    sTollFee2[11];		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û���;���� */
	char    sDuration2[11];		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û�����ʱ�� */
	char    sCnt2[11];		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û����д��� */
	char    sTollFee3[11];		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û���;���� */
	char    sDuration3[11];		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û�����ʱ�� */
	char    sCnt3[11];		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û����д��� */
	char    sTollFee4[11];		/* ʹ������ר��ҵ�񲦴����GSM�û���;���� */
	char    sDuration4[11];		/* ʹ������ר��ҵ�񲦴����GSM�û�����ʱ�� */
	char    sCnt4[11];		/* ʹ������ר��ҵ�񲦴����GSM�û����д��� */
	char    sTollFee5[11];		/* ʹ������ר��ҵ�񲦴����CDAM�û���;���� */
	char    sDuration5[11];		/* ʹ������ר��ҵ�񲦴����CDAM�û�����ʱ�� */
	char    sCnt5[11];		/* ʹ������ר��ҵ�񲦴����CDAM�û����д��� */
	char    sTollFee6[11];		/* ʹ������ר��ҵ�񲦴���������û���;���� */
	char    sDuration6[11];		/* ʹ������ר��ҵ�񲦴���������û�����ʱ�� */
	char    sCnt6[11];		/* ʹ������ר��ҵ�񲦴���������û����д��� */
	char    sSettMonth[7];		/* �����·� */
	struct DownVoipStatStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FDownVoipStatStruct{

	char    sCallingUserType[1];		/* ���к������ */
	char    sInCityCode[3];		/* ����д��� */
	char    sOutCityCout[3];		/* �����д��� */
	char    sTollFee1[10];		/* ��ʡ�ַ��п���ҵ�񲦴����GSM�û���;���� */
	char    sDuration1[10];		/* ʹ�ñ�ʡ�ַ��п���ҵ�񲦴����GSM�û�����ʱ�� */
	char    sCnt1[10];		/* ʹ�ñ�ʡ�ַ��п���ҵ�񲦴����GSM�û����д��� */
	char    sTollFee2[10];		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û���;���� */
	char    sDuration2[10];		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û�����ʱ�� */
	char    sCnt2[10];		/* ʹ��ʡ�ַ��п���ҵ�񲦴����CDMA�û����д��� */
	char    sTollFee3[10];		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û���;���� */
	char    sDuration3[10];		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û�����ʱ�� */
	char    sCnt3[10];		/* ʹ��ʡ�ַ��п���ҵ�񲦴���������û����д��� */
	char    sTollFee4[10];		/* ʹ������ר��ҵ�񲦴����GSM�û���;���� */
	char    sDuration4[10];		/* ʹ������ר��ҵ�񲦴����GSM�û�����ʱ�� */
	char    sCnt4[10];		/* ʹ������ר��ҵ�񲦴����GSM�û����д��� */
	char    sTollFee5[10];		/* ʹ������ר��ҵ�񲦴����CDAM�û���;���� */
	char    sDuration5[10];		/* ʹ������ר��ҵ�񲦴����CDAM�û�����ʱ�� */
	char    sCnt5[10];		/* ʹ������ר��ҵ�񲦴����CDAM�û����д��� */
	char    sTollFee6[10];		/* ʹ������ר��ҵ�񲦴���������û���;���� */
	char    sDuration6[10];		/* ʹ������ר��ҵ�񲦴���������û�����ʱ�� */
	char    sCnt6[10];		/* ʹ������ר��ҵ�񲦴���������û����д��� */
	char    sSettMonth[6];		/* �����·� */
};

int EGetDownVoipStatToStruct(struct DownVoipStatStruct *p,
	struct DownVoipStatStructIn *pSource);
void mvitem_mfdownvoipstat(struct DownVoipStatStruct *pi,
	struct FDownVoipStatStruct *po);
int DownVoipStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int EGetDownTollStatToStruct(struct DownTollStatStruct *p,
	struct DownTollStatStructIn *pSource);
void mvitem_mfdowntollstat(struct DownTollStatStruct *pi,
	struct FDownTollStatStruct *po);
int DownTollStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
	
/* ����ṹ��������*/
struct XStrTicketStructIn{

#ifndef X_STR_TICKET_BUFLEN_IN
#define X_STR_TICKET_BUFLEN_IN		300
#endif

	struct XStrTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[8192];/*��ԭ����SQL����д������*/
	char sCondition[32];  /*����̶�Ϊ��*/
		/* ͨ�ô����� */
	char    asXStr[X_STR_TICKET_BUFLEN_IN][4000];
		/* ��Դ */
	char    asSourceID[X_STR_TICKET_BUFLEN_IN][41];
	char    asRowID[X_STR_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct XStrTicketStruct{

	struct XStrTicketStruct *pNext;
	char    sXStr[4000];		/* ͨ�ô����� */
	char    sSourceID[41];		/* ��Դ */
	char	sRowID[19];
	struct XStrTicketStruct *pLoadNext;
};
/*�������ݶ�̬��X_STR_TICKET���ýṹ���巽ʽȡ����*/
int EGetXStrTicketToStruct(struct XStrTicketStruct *p,
	struct XStrTicketStructIn *pSource);
int XStrTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/* ����ṹ��������*/
struct MyTabColumnsStructIn{

#ifndef MY_TAB_COLUMNS_BUFLEN_IN
#define MY_TAB_COLUMNS_BUFLEN_IN		300
#endif

	struct MyTabColumnsStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[8192];/*��ԭ����SQL����д������*/
	char sCondition[32];  /*����̶�Ϊ��*/
		/* ���� */
	char    asTableName[MY_TAB_COLUMNS_BUFLEN_IN][31];
		/* �ֶ����� */
	char    asDataType[MY_TAB_COLUMNS_BUFLEN_IN][31];
		/* �ֶ��� */
	char    asColumnName[MY_TAB_COLUMNS_BUFLEN_IN][31];
		/* �ֶγ��� */
	int     aiLen[MY_TAB_COLUMNS_BUFLEN_IN];
		/* �ֶα�����С�����λ�� */
	int     aiScale[MY_TAB_COLUMNS_BUFLEN_IN];
		/* �Ƿ�ɿ� */
	char    asNullable[MY_TAB_COLUMNS_BUFLEN_IN][2];
		/* �ֶ�λ�� */
	int     aiColumnID[MY_TAB_COLUMNS_BUFLEN_IN];
};


/*�����ṹ����*/
struct MyTabColumnsStruct{

	struct MyTabColumnsStruct *pNext;
	char    sTableName[31];		/* ���� */
	char    sDataType[31];		/* �ֶ����� */
	char    sColumnName[31];		/* �ֶ��� */
	int     iLen;		/* �ֶγ��� */
	int     iScale;		/* �ֶα�����С�����λ�� */
	char    sNullable[2];		/* �Ƿ�ɿ� */
	int     iColumnID;		/* �ֶ�λ�� */
	/*�������ֶ��ɳ�����д*/
	int	iOffset;	/*�����ͷ�ֶε�ƫ��*/
	int	iSeq;		/*��ʾ��N���ֶ�*/
	struct MyTabColumnsStruct *pHead;/*ԭʼ�ֶ�*/
	
	struct MyTabColumnsStruct *pLoadNext;
};
/*�������ݶ�̬��MY_TAB_COLUMNS���ýṹ���巽ʽȡ����*/
int EGetMyTabColumnsToStruct(struct MyTabColumnsStruct *p,
	struct MyTabColumnsStructIn *pSource);
int InitMyTabColumns(char sTableName[],struct MyTabColumnsStruct **pptHead);

void GetSeleColumnStr(struct MyTabColumnsStruct *pTemp,char sOutput[]);
void GetXStrSqlStmt(struct MyTabColumnsStruct *ptHead,char sTableName[],
	char statement[]);
void GetXStrTableNameStmt(struct MyTabColumnsStruct *ptLkHead,
	char sTableName[],char sCondition[],char statement[]);
int GetXStrTableName(char sTableName[],char sCondition[],char statement[]);

int InitMyTabIoColumns(char sTableName[],struct MyTabColumnsStruct **pptHead);
void GetIoMyTabColumnList(struct MyTabColumnsStruct **pptHead,
	struct MyTabColumnsStruct **ppInList,
	struct MyTabColumnsStruct **ppOutList);
void SetMyTabColumnOffset(struct MyTabColumnsStruct *ptHead);
void LinkMyTabColumnHead(struct MyTabColumnsStruct *ptHead,
	struct MyTabColumnsStruct *ptLkHead);
void GetMyTabStr(struct MyTabColumnsStruct *ptHead,char sLine[],char sOutput[]);

void GetUpdColumnStr(struct MyTabColumnsStruct *pTemp,char sOutput[]);
void GetUpdSqlStmt(struct MyTabColumnsStruct *ptHead,char sTableName[],
	char statement[]);

#ifndef XSTR_BUFLEN_UP
#define XSTR_BUFLEN_UP 	1000
#endif

struct UStrStructUp
{
	int	iCurPos;
	char	sTableName[31];
	char	sStatement[4096];
	char	asRowID[XSTR_BUFLEN_UP][19];
	char	asXData[1];
};
int EUpdateXStr2Tab(char sXStr[],char sRowID[],
        int iUpdateFlag,struct MyTabColumnsStruct *ptHead,
	struct UStrStructUp *pTarget);
struct UStrStructUp *MallocUStrStructUp(struct MyTabColumnsStruct *ptHead);


/*����ṹ��������*/
struct ErrTicketStructOut{

#ifndef ERR_TICKET_BUFLEN_OUT
#define ERR_TICKET_BUFLEN_OUT		300
#endif

	struct ErrTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* (B,������,T�ı�) */
	char    asRecordType[ERR_TICKET_BUFLEN_OUT][2];
		/* �������� */
	char    asCallType[ERR_TICKET_BUFLEN_OUT][3];
		/* �ƷѺ��� */
	char    asMsisdn[ERR_TICKET_BUFLEN_OUT][16];
		/* �Զ˺��� */
	char    asOtherParty[ERR_TICKET_BUFLEN_OUT][25];
		/* ͨ����ʼʱ�� */
	char    asStartTime[ERR_TICKET_BUFLEN_OUT][15];
		/* ͨ��ʱ�� */
	char    asDuration[ERR_TICKET_BUFLEN_OUT][7];
		/* IMSI */
	char    asImsi[ERR_TICKET_BUFLEN_OUT][16];
		/* ������ */
	char    asMsc[ERR_TICKET_BUFLEN_OUT][16];
		/* ����1(ҵ�����) */
	char    asReserve1[ERR_TICKET_BUFLEN_OUT][21];
		/* ����2(ҵ�����) */
	char    asReserve2[ERR_TICKET_BUFLEN_OUT][21];
		/* ����3(ҵ�����) */
	char    asReserve3[ERR_TICKET_BUFLEN_OUT][31];
		/* ����4(ҵ�����) */
	char    asReserve4[ERR_TICKET_BUFLEN_OUT][31];
		/* �ɼ���Դ */
	char    asOriSourceID[ERR_TICKET_BUFLEN_OUT][7];
		/* ԭʼ�ļ��� */
	char    asOriFileName[ERR_TICKET_BUFLEN_OUT][41];
		/* �����ļ��к� */
	int     aiLine[ERR_TICKET_BUFLEN_OUT];
		/* ������� */
	char    asErrCode[ERR_TICKET_BUFLEN_OUT][5];
		/* ��������ļ��� */
	char    asFileName[ERR_TICKET_BUFLEN_OUT][20];
		/* ҵ������(STTVIT��) */
	char    asModule[ERR_TICKET_BUFLEN_OUT][4];
		/* ���� */
	char    asAreaCode[ERR_TICKET_BUFLEN_OUT][6];
		/* (0:����,1:�ѻ���,2:�Ѵ���) */
	char    asState[ERR_TICKET_BUFLEN_OUT][2];
		/* ���ջ���ʱ�� */
	char    asUpdateDate[ERR_TICKET_BUFLEN_OUT][15];
		/* ���ʱ�� */
	char    asDealDate[ERR_TICKET_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[ERR_TICKET_BUFLEN_OUT][31];
		/* �����ƻ����������ASCII���ı���Ϊԭʼ��¼ */
	char    asErrRec[ERR_TICKET_BUFLEN_OUT][2049];
};


/* ����ṹ��������*/
struct ErrTicketStructIn{

#ifndef ERR_TICKET_BUFLEN_IN
#define ERR_TICKET_BUFLEN_IN		300
#endif

	struct ErrTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* (B,������,T�ı�) */
	char    asRecordType[ERR_TICKET_BUFLEN_IN][2];
		/* �������� */
	char    asCallType[ERR_TICKET_BUFLEN_IN][3];
		/* �ƷѺ��� */
	char    asMsisdn[ERR_TICKET_BUFLEN_IN][16];
		/* �Զ˺��� */
	char    asOtherParty[ERR_TICKET_BUFLEN_IN][25];
		/* ͨ����ʼʱ�� */
	char    asStartTime[ERR_TICKET_BUFLEN_IN][15];
		/* ͨ��ʱ�� */
	char    asDuration[ERR_TICKET_BUFLEN_IN][7];
		/* IMSI */
	char    asImsi[ERR_TICKET_BUFLEN_IN][16];
		/* ������ */
	char    asMsc[ERR_TICKET_BUFLEN_IN][16];
		/* ����1(ҵ�����) */
	char    asReserve1[ERR_TICKET_BUFLEN_IN][21];
		/* ����2(ҵ�����) */
	char    asReserve2[ERR_TICKET_BUFLEN_IN][21];
		/* ����3(ҵ�����) */
	char    asReserve3[ERR_TICKET_BUFLEN_IN][31];
		/* ����4(ҵ�����) */
	char    asReserve4[ERR_TICKET_BUFLEN_IN][31];
		/* �ɼ���Դ */
	char    asOriSourceID[ERR_TICKET_BUFLEN_IN][7];
		/* ԭʼ�ļ��� */
	char    asOriFileName[ERR_TICKET_BUFLEN_IN][41];
		/* �����ļ��к� */
	int     aiLine[ERR_TICKET_BUFLEN_IN];
		/* ������� */
	char    asErrCode[ERR_TICKET_BUFLEN_IN][5];
		/* ��������ļ��� */
	char    asFileName[ERR_TICKET_BUFLEN_IN][20];
		/* ҵ������(STTVIT��) */
	char    asModule[ERR_TICKET_BUFLEN_IN][4];
		/* ���� */
	char    asAreaCode[ERR_TICKET_BUFLEN_IN][6];
		/* (0:����,1:�ѻ���,2:�Ѵ���) */
	char    asState[ERR_TICKET_BUFLEN_IN][2];
		/* ���ջ���ʱ�� */
	char    asUpdateDate[ERR_TICKET_BUFLEN_IN][15];
		/* ���ʱ�� */
	char    asDealDate[ERR_TICKET_BUFLEN_IN][15];
		/* �ļ���Դ */
	char    asSourceID[ERR_TICKET_BUFLEN_IN][31];
		/* �����ƻ����������ASCII���ı���Ϊԭʼ��¼ */
	char    asErrRec[ERR_TICKET_BUFLEN_IN][2049];

	char	asRowID[ERR_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct ErrTicketStruct{

	struct ErrTicketStruct *pNext;
	char    sRecordType[2];		/* (B,������,T�ı�) */
	char    sCallType[3];		/* �������� */
	char    sMsisdn[16];		/* �ƷѺ��� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sStartTime[15];		/* ͨ����ʼʱ�� */
	char    sDuration[7];		/* ͨ��ʱ�� */
	char    sImsi[16];		/* IMSI */
	char    sMsc[16];		/* ������ */
	char    sReserve1[21];		/* ����1(ҵ�����) */
	char    sReserve2[21];		/* ����2(ҵ�����) */
	char    sReserve3[31];		/* ����3(ҵ�����) */
	char    sReserve4[31];		/* ����4(ҵ�����) */
	char    sOriSourceID[7];		/* �ɼ���Դ */
	char    sOriFileName[41];		/* ԭʼ�ļ��� */
	int     iLine;		/* �����ļ��к� */
	char    sErrCode[5];		/* ������� */
	char    sFileName[20];		/* ��������ļ��� */
	char    sModule[4];		/* ҵ������(STTVIT��) */
	char    sAreaCode[6];		/* ���� */
	char    sState[2];		/* (0:����,1:�ѻ���,2:�Ѵ���) */
	char    sUpdateDate[15];		/* ���ջ���ʱ�� */
	char    sDealDate[15];		/* ���ʱ�� */
	char    sSourceID[31];		/* �ļ���Դ */
	char    sErrRec[2049];		/* �����ƻ����������ASCII���ı���Ϊԭʼ��¼ */
	char	sRowID[19];
	struct ErrTicketStruct *pLoadNext;
};



void mvitem_fmolderrticket(struct FileControlStruct *pTemp,struct ErrTicketStruct *po);
void mvitem_fmerrticket(struct FileControlStruct *pTemp,struct ErrTicketStruct *po);
int InsertErrTicket(char sFileName[],char sTableName[]);
int EInsertStructToErrTicket(struct ErrTicketStruct *p,
	int iInsertFlag,struct ErrTicketStructOut *pTarget);
/*�������ݶ�̬��ERR_TICKET���ýṹ���巽ʽȡ����*/
int EGetErrTicketToStruct(struct ErrTicketStruct *p,
	struct ErrTicketStructIn *pSource);


/*����ṹ��������*/
struct GprsZteIntfStructOut{

#ifndef GPRS_ZTE_INTF_BUFLEN_OUT
#define GPRS_ZTE_INTF_BUFLEN_OUT		300
#endif

	struct GprsZteIntfStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* SGSN��¼���� */
	char    asRecordType[GPRS_ZTE_INTF_BUFLEN_OUT][3];
		/* ����෢��PDP�����ĵı�־ */
	char    asNiPdp[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* �ֻ��豸��IMS */
	char    asImsi[GPRS_ZTE_INTF_BUFLEN_OUT][16];
		/* �豸�� */
	char    asEsn[GPRS_ZTE_INTF_BUFLEN_OUT][21];
		/* �ֻ���ISDN�� */
	char    asMsisdn[GPRS_ZTE_INTF_BUFLEN_OUT][16];
		/* ���𱾴�ͨ�������� */
	char    asStartTime[GPRS_ZTE_INTF_BUFLEN_OUT][15];
		/* ����ͨ��������ʱ�� */
	int     aiCallDuration[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* ���𱾴�ͨ����SGSN��ַ */
	char    asSgsnAddr[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* С������ */
	int     aiCellID[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* ��վ���� */
	int     aiLac[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* PDP�����ĵļƷѱ�ʶ */
	char    asChargingID[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* ����ͨ����GGSN��ַ */
	char    asGgsnAddr[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* APN�������ʶ */
	char    asApnNi[GPRS_ZTE_INTF_BUFLEN_OUT][64];
		/* APN����Ӫ�̱�ʶ */
	char    asApnOi[GPRS_ZTE_INTF_BUFLEN_OUT][38];
		/* PDP���� */
	char    asPdpType[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* �ն˵�PDP��ַ */
	char    asServedPdpAddress[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* SGSN�ı��־ */
	int     aiSgsnChange[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* ��¼��ֹԭ�� */
	int     aiCloseCause[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* ��¼�Ƿ����� */
	char    asIntegrityFlag[GPRS_ZTE_INTF_BUFLEN_OUT][3];
		/* ҵ������ */
	char    asServiceType[GPRS_ZTE_INTF_BUFLEN_OUT][4];
		/* �û����� */
	char    asUserType[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* ���е��������� */
	char    asDataFlowup1[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* ���е��������� */
	char    asDataFlowdn1[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* �Ʒ���Ŀ */
	char    asBillItem[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* �Ʒ�ҵ�� */
	char    asBillService[GPRS_ZTE_INTF_BUFLEN_OUT][3];
		/* �������� */
	char    asRoamType[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* �ƷѺ�������� */
	char    asHomeAreaCode[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* �ƷѺ������ε� */
	char    asVisitAreaCode[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* ʱ����λ�� */
	char    asDurationCnt[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* ������λ�� */
	char    asFlowCnt[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* ʱ����λ */
	char    asDurationUnit[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* �Ʒѵ�λ */
	char    asBillUnit[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* �������� */
	char    asCfee[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* �������� */
	char    asFee1[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* ԭʼ�����ļ�����Ϣ */
	char    asFileName[GPRS_ZTE_INTF_BUFLEN_OUT][21];
		/* �ƷѺ���������д��� */
	char    asHomeCityCode[GPRS_ZTE_INTF_BUFLEN_OUT][6];
		/* MS�������� */
	char    asMsnc[GPRS_ZTE_INTF_BUFLEN_OUT][9];
		/* �仯���������������رյ�ԭ�� */
	char    asCloseCause1[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* GGSN�Ĵ��� */
	char    asGgsn[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* APNѡ��ģʽ */
	char    asApnMode[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* �Ʒ����Ա�־ */
	char    asBillFlag[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* GSN IP��ַ */
	char    asGsnIp[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* ��¼���к� */
	char    asBillSeq[GPRS_ZTE_INTF_BUFLEN_OUT][9];
		/* sgsn_plmnid */
	char    asSgsnPlmnID[GPRS_ZTE_INTF_BUFLEN_OUT][8];
		/* ���ӷ��� */
	char    asFee2[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* ·������ */
	char    asRouteArea[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* ������ */
	char    asErrCode[GPRS_ZTE_INTF_BUFLEN_OUT][16];
		/* ״̬ */
	char    asState[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* �������� */
	char    asUpdateDate[GPRS_ZTE_INTF_BUFLEN_OUT][15];
		/* �������� */
	char    asDealDate[GPRS_ZTE_INTF_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[GPRS_ZTE_INTF_BUFLEN_OUT][41];
};
/*�����ṹ����*/
struct GprsZteIntfStruct{

	struct GprsZteIntfStruct *pNext;
	char    sRecordType[3];		/* SGSN��¼���� */
	char    sNiPdp[2];		/* ����෢��PDP�����ĵı�־ */
	char    sImsi[16];		/* �ֻ��豸��IMS */
	char    sEsn[21];		/* �豸�� */
	char    sMsisdn[16];		/* �ֻ���ISDN�� */
	char    sStartTime[15];		/* ���𱾴�ͨ�������� */
	int     iCallDuration;		/* ����ͨ��������ʱ�� */
	char    sSgsnAddr[17];		/* ���𱾴�ͨ����SGSN��ַ */
	int     iCellID;		/* С������ */
	int     iLac;		/* ��վ���� */
	char    sChargingID[11];		/* PDP�����ĵļƷѱ�ʶ */
	char    sGgsnAddr[17];		/* ����ͨ����GGSN��ַ */
	char    sApnNi[64];		/* APN�������ʶ */
	char    sApnOi[38];		/* APN����Ӫ�̱�ʶ */
	char    sPdpType[2];		/* PDP���� */
	char    sServedPdpAddress[17];		/* �ն˵�PDP��ַ */
	int     iSgsnChange;		/* SGSN�ı��־ */
	int     iCloseCause;		/* ��¼��ֹԭ�� */
	char    sIntegrityFlag[3];		/* ��¼�Ƿ����� */
	char    sServiceType[4];		/* ҵ������ */
	char    sUserType[2];		/* �û����� */
	char    sDataFlowup1[11];		/* ���е��������� */
	char    sDataFlowdn1[11];		/* ���е��������� */
	char    sBillItem[2];		/* �Ʒ���Ŀ */
	char    sBillService[3];		/* �Ʒ�ҵ�� */
	char    sRoamType[2];		/* �������� */
	char    sHomeAreaCode[5];		/* �ƷѺ�������� */
	char    sVisitAreaCode[5];		/* �ƷѺ������ε� */
	char    sDurationCnt[11];		/* ʱ����λ�� */
	char    sFlowCnt[11];		/* ������λ�� */
	char    sDurationUnit[11];		/* ʱ����λ */
	char    sBillUnit[11];		/* �Ʒѵ�λ */
	char    sCfee[11];		/* �������� */
	char    sFee1[11];		/* �������� */
	char    sFileName[21];		/* ԭʼ�����ļ�����Ϣ */
	char    sHomeCityCode[6];		/* �ƷѺ���������д��� */
	char    sMsnc[9];		/* MS�������� */
	char    sCloseCause1[5];		/* �仯���������������رյ�ԭ�� */
	char    sGgsn[11];		/* GGSN�Ĵ��� */
	char    sApnMode[2];		/* APNѡ��ģʽ */
	char    sBillFlag[2];		/* �Ʒ����Ա�־ */
	char    sGsnIp[17];		/* GSN IP��ַ */
	char    sBillSeq[9];		/* ��¼���к� */
	char    sSgsnPlmnID[8];		/* sgsn_plmnid */
	char    sFee2[11];		/* ���ӷ��� */
	char    sRouteArea[5];		/* ·������ */
	char    sErrCode[16];		/* ������ */
	char    sState[2];		/* ״̬ */
	char    sUpdateDate[15];		/* �������� */
	char    sDealDate[15];		/* �������� */
	char    sSourceID[41];		/* �ļ���Դ */
	struct GprsZteIntfStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FGprsZteIntfStruct{

	char    sRecordType[2];		/* SGSN��¼���� */
	char    sNiPdp[1];		/* ����෢��PDP�����ĵı�־ */
	char    sImsi[15];		/* �ֻ��豸��IMS */
	char    sEsn[20];		/* �豸�� */
	char    sMsisdn[15];		/* �ֻ���ISDN�� */
	char    sStartTime[14];		/* ���𱾴�ͨ�������� */
	char    sCallDuration[6];		/* ����ͨ��������ʱ�� */
	char    sSgsnAddr[16];		/* ���𱾴�ͨ����SGSN��ַ */
	char    sCellID[5];		/* С������ */
	char    sLac[5];		/* ��վ���� */
	char    sChargingID[10];		/* PDP�����ĵļƷѱ�ʶ */
	char    sGgsnAddr[16];		/* ����ͨ����GGSN��ַ */
	char    sApnNi[63];		/* APN�������ʶ */
	char    sApnOi[37];		/* APN����Ӫ�̱�ʶ */
	char    sPdpType[1];		/* PDP���� */
	char    sServedPdpAddress[16];		/* �ն˵�PDP��ַ */
	char    sSgsnChange[1];		/* SGSN�ı��־ */
	char    sCloseCause[2];		/* ��¼��ֹԭ�� */
	char    sIntegrityFlag[2];		/* ��¼�Ƿ����� */
	char    sServiceType[3];		/* ҵ������ */
	char    sUserType[1];		/* �û����� */
	char    sDataFlowup1[10];		/* ���е��������� */
	char    sDataFlowdn1[10];		/* ���е��������� */
	char    sBillItem[1];		/* �Ʒ���Ŀ */
	char    sBillService[2];		/* �Ʒ�ҵ�� */
	char    sRoamType[1];		/* �������� */
	char    sHomeAreaCode[4];		/* �ƷѺ�������� */
	char    sVisitAreaCode[4];		/* �ƷѺ������ε� */
	char    sDurationCnt[10];		/* ʱ����λ�� */
	char    sFlowCnt[10];		/* ������λ�� */
	char    sDurationUnit[10];		/* ʱ����λ */
	char    sBillUnit[10];		/* �Ʒѵ�λ */
	char    sCfee[10];		/* �������� */
	char    sFee1[10];		/* �������� */
	char    sFileName[20];		/* ԭʼ�����ļ�����Ϣ */
	char    sHomeCityCode[5];		/* �ƷѺ���������д��� */
	char    sMsnc[8];		/* MS�������� */
	char    sCloseCause1[4];		/* �仯���������������رյ�ԭ�� */
	char    sGgsn[10];		/* GGSN�Ĵ��� */
	char    sApnMode[1];		/* APNѡ��ģʽ */
	char    sBillFlag[1];		/* �Ʒ����Ա�־ */
	char    sGsnIp[16];		/* GSN IP��ַ */
	char    sBillSeq[8];		/* ��¼���к� */
	char    sSgsnPlmnID[7];		/* sgsn_plmnid */
	char    sFee2[10];		/* ���ӷ��� */
	char    sRouteArea[4];		/* ·������ */
	char    sErrCode[15];		/* ������ */
	char    sState[1];		/* ״̬ */
	char    sUpdateDate[14];		/* �������� */
	char    sDealDate[14];		/* �������� */
	char    sSourceID[40];		/* �ļ���Դ */
};
void mvitem_fmgprszteintf(struct FGprsZteIntfStruct *pi,
	struct GprsZteIntfStruct *po);
/*�������ݽṹ����д��GPRS_ZTE_INTF*/
int EInsertStructToGprsZteIntf(struct GprsZteIntfStruct *p,
	int iInsertFlag,struct GprsZteIntfStructOut *pTarget);
int InsertGprsZteIntf(char sFileName[],char sTableName[]);

/*����ṹ��������*/
struct GprsStdIntfStructOut{

#ifndef GPRS_STD_INTF_BUFLEN_OUT
#define GPRS_STD_INTF_BUFLEN_OUT		300
#endif

	struct GprsStdIntfStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��¼���� */
	char    asRecordType[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* �������� */
	char    asRoamType[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* �ֻ��ն˵�IMSI */
	char    asImsi[GPRS_STD_INTF_BUFLEN_OUT][16];
		/* �ֻ��ն˵�ISDN */
	char    asMsisdn[GPRS_STD_INTF_BUFLEN_OUT][16];
		/* ���λỰ��ʼSGSNIP��ַ */
	char    asSgsn[GPRS_STD_INTF_BUFLEN_OUT][17];
		/* SGSN�ı��ʶ */
	char    asSgsnChange[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* ���λỰGGSNIP��ַ */
	char    asGgsn[GPRS_STD_INTF_BUFLEN_OUT][17];
		/* �ֻ��ն�PDPIP��ַ */
	char    asServedPdpAddress[GPRS_STD_INTF_BUFLEN_OUT][17];
		/* ����������ʶ */
	char    asApnNi[GPRS_STD_INTF_BUFLEN_OUT][64];
		/* �������Ӫ�̱�ʶ */
	char    asApnOi[GPRS_STD_INTF_BUFLEN_OUT][38];
		/* �����ֶ�1 */
	char    asReserv1[GPRS_STD_INTF_BUFLEN_OUT][15];
		/* ������ʱ�� */
	int     aiCallDuration[GPRS_STD_INTF_BUFLEN_OUT];
		/* �ֲ����ͱ�ʶ�� */
	char    asPartialType[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* �ж�ԭ�� */
	char    asCloseCause[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* ���λỰ���ӿ�ʼʱ�� */
	char    asStartTime[GPRS_STD_INTF_BUFLEN_OUT][15];
		/* �������б�־ */
	char    asNiPdp[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* PDP�����ļƷѱ�ʶ */
	char    asChargingID[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* λ������ */
	char    asLac[GPRS_STD_INTF_BUFLEN_OUT][6];
		/* С����ʶ */
	char    asCellID[GPRS_STD_INTF_BUFLEN_OUT][6];
		/* ���εس��д��� */
	char    asVisitCityCode[GPRS_STD_INTF_BUFLEN_OUT][4];
		/* �����ֶ�2 */
	char    asReserv2[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* ���εر��� */
	char    asRoamRemark[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* �ֻ����� */
	char    asImei[GPRS_STD_INTF_BUFLEN_OUT][20];
		/* �������� */
	char    asDataFlowdn[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* �������� */
	char    asDataFlowup[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* �Ʒ���Ŀ */
	char    asChargeItem[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* �Ʒ�ȡ�� */
	char    asChargeUnit[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* �Ʒ�ҵ�� */
	char    asChargeOperation[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* ���� */
	int     aiTotalFee[GPRS_STD_INTF_BUFLEN_OUT];
		/* �����ֶ�3 */
	char    asReserv3[GPRS_STD_INTF_BUFLEN_OUT][94];
		/* ״̬ */
	char    asState[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* �������� */
	char    asDealDate[GPRS_STD_INTF_BUFLEN_OUT][15];
		/* �ļ���Դ */
	char    asSourceID[GPRS_STD_INTF_BUFLEN_OUT][41];
		/* ״̬���� */
	char    asUpdateDate[GPRS_STD_INTF_BUFLEN_OUT][15];
};
/*�����ṹ����*/
struct GprsStdIntfStruct{

	struct GprsStdIntfStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sRoamType[3];		/* �������� */
	char    sImsi[16];		/* �ֻ��ն˵�IMSI */
	char    sMsisdn[16];		/* �ֻ��ն˵�ISDN */
	char    sSgsn[17];		/* ���λỰ��ʼSGSNIP��ַ */
	char    sSgsnChange[2];		/* SGSN�ı��ʶ */
	char    sGgsn[17];		/* ���λỰGGSNIP��ַ */
	char    sServedPdpAddress[17];		/* �ֻ��ն�PDPIP��ַ */
	char    sApnNi[64];		/* ����������ʶ */
	char    sApnOi[38];		/* �������Ӫ�̱�ʶ */
	char    sReserv1[15];		/* �����ֶ�1 */
	int     iCallDuration;		/* ������ʱ�� */
	char    sPartialType[2];		/* �ֲ����ͱ�ʶ�� */
	char    sCloseCause[3];		/* �ж�ԭ�� */
	char    sStartTime[15];		/* ���λỰ���ӿ�ʼʱ�� */
	char    sNiPdp[2];		/* �������б�־ */
	char    sChargingID[11];		/* PDP�����ļƷѱ�ʶ */
	char    sLac[6];		/* λ������ */
	char    sCellID[6];		/* С����ʶ */
	char    sVisitCityCode[4];		/* ���εس��д��� */
	char    sReserv2[11];		/* �����ֶ�2 */
	char    sRoamRemark[11];		/* ���εر��� */
	char    sImei[20];		/* �ֻ����� */
	char    sDataFlowdn[11];		/* �������� */
	char    sDataFlowup[11];		/* �������� */
	char    sChargeItem[2];		/* �Ʒ���Ŀ */
	char    sChargeUnit[11];		/* �Ʒ�ȡ�� */
	char    sChargeOperation[3];		/* �Ʒ�ҵ�� */
	int     iTotalFee;		/* ���� */
	char    sReserv3[94];		/* �����ֶ�3 */
	char    sState[2];		/* ״̬ */
	char    sDealDate[15];		/* �������� */
	char    sSourceID[41];		/* �ļ���Դ */
	char    sUpdateDate[15];		/* ״̬���� */
	struct GprsStdIntfStruct *pLoadNext;
};
/*�����ļ��ṹ����*/
struct FGprsStdIntfStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sRoamType[2];		/* �������� */
	char    sImsi[15];		/* �ֻ��ն˵�IMSI */
	char    sMsisdn[15];		/* �ֻ��ն˵�ISDN */
	char    sSgsn[16];		/* ���λỰ��ʼSGSNIP��ַ */
	char    sSgsnChange[1];		/* SGSN�ı��ʶ */
	char    sGgsn[16];		/* ���λỰGGSNIP��ַ */
	char    sServedPdpAddress[16];		/* �ֻ��ն�PDPIP��ַ */
	char    sApnNi[63];		/* ����������ʶ */
	char    sApnOi[37];		/* �������Ӫ�̱�ʶ */
	char    sReserv1[14];		/* �����ֶ�1 */
	char    sCallDuration[6];		/* ������ʱ�� */
	char    sPartialType[1];		/* �ֲ����ͱ�ʶ�� */
	char    sCloseCause[2];		/* �ж�ԭ�� */
	char    sStartTime[14];		/* ���λỰ���ӿ�ʼʱ�� */
	char    sNiPdp[1];		/* �������б�־ */
	char    sChargingID[10];		/* PDP�����ļƷѱ�ʶ */
	char    sLac[5];		/* λ������ */
	char    sCellID[5];		/* С����ʶ */
	char    sVisitCityCode[3];		/* ���εس��д��� */
	char    sReserv2[10];		/* �����ֶ�2 */
	char    sRoamRemark[10];		/* ���εر��� */
	char    sImei[19];		/* �ֻ����� */
	char    sDataFlowdn[10];		/* �������� */
	char    sDataFlowup[10];		/* �������� */
	char    sChargeItem[1];		/* �Ʒ���Ŀ */
	char    sChargeUnit[10];		/* �Ʒ�ȡ�� */
	char    sChargeOperation[2];		/* �Ʒ�ҵ�� */
	char    sTotalFee[9];		/* ���� */
	char    sReserv3[93];		/* �����ֶ�3 */
	char    sState[1];		/* ״̬ */
	char    sDealDate[14];		/* �������� */
	char    sSourceID[40];		/* �ļ���Դ */
	char    sUpdateDate[14];		/* ״̬���� */
};
void mvitem_fmgprsstdintf(struct FGprsStdIntfStruct *pi,
	struct GprsStdIntfStruct *po);
/*�������ݽṹ����д��GPRS_STD_INTF*/
int EInsertStructToGprsStdIntf(struct GprsStdIntfStruct *p,
	int iInsertFlag,struct GprsStdIntfStructOut *pTarget);
int InsertGprsStdIntf(char sFileName[],char sTableName[]);
	
#endif