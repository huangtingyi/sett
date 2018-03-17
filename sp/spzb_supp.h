#ifndef __SPZB_SUPP_H__
#define __SPZB_SUPP_H__

#include "stt_ticket.h"
#define IS_UNICOMCDMA(x)      IsDpAccNbr("unicomcdma",x)

/*�����ṹ����*/
struct SmsTicketBStruct{

	struct SmsTicketBStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];	/* SPҵ������ */
	char    sCityCode[4];		/* ���д��� */
	char	sNetTpye[2];		/*C CDMAG GSM*/
	char    sYsHdCnt[11];		/* Ӧ����Ϣ�ѵĻ������� */
	char    sYsFee[16];		/* Ӧ����Ϣ�� */
	char    sMoCnt[11];		/* MO_MOF���� */
	char    sMtCnt[11];		/* MT_MTF���� */
	char    sChkDate[11];		/* yyyymmddhh*/
	struct SmsTicketBStruct *pLoadNext;
};


/*�����ṹ����*/
struct YsTicketUpHeadStruct{

	struct YsTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* �ļ����к� */
	char    sFileVersion[3];		/* �ļ��汾�� */
	char    sFileCreatDate[9];		/* �ļ�����ʱ�� */
	char    sProvCode[4];		/* ʡ�ִ��� */
	char    sBillingCycleID[7];		/* ���� */
	char    sTotalCnt[11];		/* �ܼ�¼�� */
	char    sTotalHdCnt[11];		/* ��Ӧ����Ϣ�ѵĻ������� */
	char    sTotalFee[16];		/* ��Ӧ����Ϣ�� */
	char    sTotalMoCnt[11];		/* ��MO_MOF���� */
	char    sTotalMtCnt[11];		/* ��MT_MTF���� */
	char    sTotalH20Cnt[11];		/* �ܳ���20����Ϣ�������� */
	char    sTotalH20Fee[11];		/* �ܳ���20����Ϣ���� */
	char    sReserv2[19];		/* ϵͳ����2 */
	struct YsTicketUpHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FYsTicketUpHeadStruct{

	char    sFileSeq[4];		/* �ļ����к� */
	char    sFileVersion[2];		/* �ļ��汾�� */
	char    sFileCreatDate[8];		/* �ļ�����ʱ�� */
	char    sProvCode[3];		/* ʡ�ִ��� */
	char    sBillingCycleID[6];		/* ���� */
	char    sTotalCnt[10];		/* �ܼ�¼�� */
	char    sTotalHdCnt[10];		/* ��Ӧ����Ϣ�ѵĻ������� */
	char    sTotalFee[15];		/* ��Ӧ����Ϣ�� */
	char    sTotalMoCnt[10];		/* ��MO_MOF���� */
	char    sTotalMtCnt[10];		/* ��MT_MTF���� */
	char    sTotalH20Cnt[10];		/* �ܳ���20����Ϣ�������� */
	char    sTotalH20Fee[10];		/* �ܳ���20����Ϣ���� */
	char    sReserv2[18];		/* ϵͳ����2 */
};




/*�����ṹ����*/
struct OutYsTicketUpStruct{

	struct OutYsTicketUpStruct *pNext;
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sCityCode[4];		/* ���д��� */
	char    sReserv1[5];		/* ϵͳ����1 */
	char    sReserv2[11];		/* ϵͳ����2 */
	char    sYsHdCnt[11];		/* Ӧ����Ϣ�ѵĻ������� */
	char    sYsFee[16];		/* Ӧ����Ϣ�� */
	char    sMoCnt[11];		/* MO_MOF���� */
	char    sMtCnt[11];		/* MT_MTF���� */
	char    sH20Cnt[11];		/* ����20����Ϣ�������� */
	char    sH20Fee[11];		/* ����20����Ϣ���� */
	char    sReserv3[16];		/* ϵͳ����3 */
	char	sOutFileName[30];	/*����ļ���*/
	struct OutYsTicketUpStruct *pLoadNext;
};
/*�����ṹ����*/
struct YsTicketUpStruct{

	struct YsTicketUpStruct *pNext;
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sCityCode[4];		/* ���д��� */
	char    sReserv1[5];		/* ϵͳ����1 */
	char    sReserv2[11];		/* ϵͳ����2 */
	char    sYsHdCnt[11];		/* Ӧ����Ϣ�ѵĻ������� */
	char    sYsFee[16];		/* Ӧ����Ϣ�� */
	char    sMoCnt[11];		/* MO_MOF���� */
	char    sMtCnt[11];		/* MT_MTF���� */
	char    sH20Cnt[11];		/* ����20����Ϣ�������� */
	char    sH20Fee[11];		/* ����20����Ϣ���� */
	char    sReserv3[16];		/* ϵͳ����3 */
	struct YsTicketUpStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FYsTicketUpStruct{

	char    sSpCode[5];		/* SP���� */
	char    sSpAccNbr[12];		/* SP������ */
	char    sSpServiceType[2];		/* SPҵ������ */
	char    sCityCode[3];		/* ���д��� */
	char    sReserv1[4];		/* ϵͳ����1 */
	char    sReserv2[10];		/* ϵͳ����2 */
	char    sYsHdCnt[10];		/* Ӧ����Ϣ�ѵĻ������� */
	char    sYsFee[15];		/* Ӧ����Ϣ�� */
	char    sMoCnt[10];		/* MO_MOF���� */
	char    sMtCnt[10];		/* MT_MTF���� */
	char    sH20Cnt[10];		/* ����20����Ϣ�������� */
	char    sH20Fee[10];		/* ����20����Ϣ���� */
	char    sReserv3[15];		/* ϵͳ����3 */
};

int data_search_bintree_smsb_e(void *pValue,void*pData);
void assign_insert_bintree_smsb_e(void **ppData,void *pData);
int data_search_bintree_ysup_e(void *pValue,void*pData);
void assign_insert_bintree_ysup_e(void **ppData,void *pData);

void mvitem_mfysticketup(struct OutYsTicketUpStruct *pi,struct FYsTicketUpStruct *po);
void mvitem_mfysticketuphead(struct YsTicketUpHeadStruct *pi,
	struct FYsTicketUpHeadStruct *po);
/*�����ṹ����*/
struct CxTicketDownStruct{

	struct CxTicketDownStruct *pNext;
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sCityCode[4];		/* ���б��� */
	char    sBillingCycleID[7];		/* Ӧ������ */
	char    sReserv1[9];		/* ϵͳ����1 */
	char    sReserv2[11];		/* ϵͳ����2 */
	char    sReserv3[16];		/* ϵͳ����3 */
	struct CxTicketDownStruct *pLoadNext;
};


/* ����ṹ��������*/
struct CxTicketDownStructIn{

#ifndef CX_TICKET_DOWN_BUFLEN_IN
#define CX_TICKET_DOWN_BUFLEN_IN		300
#endif

	struct CxTicketDownStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* SP���� */
	char    asSpCode[CX_TICKET_DOWN_BUFLEN_IN][6];
		/* SP������ */
	char    asSpAccNbr[CX_TICKET_DOWN_BUFLEN_IN][13];
		/* SPҵ������ */
	char    asSpServiceType[CX_TICKET_DOWN_BUFLEN_IN][3];
		/* ���б��� */
	char    asCityCode[CX_TICKET_DOWN_BUFLEN_IN][4];
		/* Ӧ������ */
	char    asBillingCycleID[CX_TICKET_DOWN_BUFLEN_IN][7];
		/* ϵͳ����1 */
	char    asReserv1[CX_TICKET_DOWN_BUFLEN_IN][9];
		/* ϵͳ����2 */
	char    asReserv2[CX_TICKET_DOWN_BUFLEN_IN][11];
		/* ϵͳ����3 */
	char    asReserv3[CX_TICKET_DOWN_BUFLEN_IN][16];
};

/*�����ṹ����*/
struct RxTicketUpHeadStruct{

	struct RxTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* �ļ����к� */
	char    sFileVersion[3];		/* �ļ��汾�� */
	char    sFileCreatDate[9];		/* �ļ��������� */
	char    sProvCode[4];		/* ʡ�ִ��� */
	char    sBillingCycleID[7];		/* Ӧ������ */
	char    sTotalRxCnt[11];		/* �޳������ܼ�¼�� */
	char    sTotalRxFee[16];		/* �޳������ܷ��� */
	char    sReserv[80];		/* ϵͳ���� */
	struct RxTicketUpHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FRxTicketUpHeadStruct{

	char    sFileSeq[4];		/* �ļ����к� */
	char    sFileVersion[2];		/* �ļ��汾�� */
	char    sFileCreatDate[8];		/* �ļ��������� */
	char    sProvCode[3];		/* ʡ�ִ��� */
	char    sBillingCycleID[6];		/* Ӧ������ */
	char    sTotalRxCnt[10];		/* �޳������ܼ�¼�� */
	char    sTotalRxFee[15];		/* �޳������ܷ��� */
	char    sReserv[79];		/* ϵͳ���� */
};



/*�����ṹ����*/
struct RxTicketUpStruct{

	struct RxTicketUpStruct *pNext;
	char    sTicketSeq[31];		/* ������� */
	char    sSpCode[6];		/* SP���� */
	char    sSpServiceCode[11];		/* SPҵ����� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sServiceType[3];		/* ҵ������ */
	char    sTicketType[3];		/* �������� */
	char    sUserType[2];		/* �û����� */
	char    sMsisdn[16];		/* �û����� */
	char    sVisitCityCode[4];		/* �û��������д��� */
	char    sInfoFee[7];		/* ��Ϣ�ѷ��� */
	char    sRecvTime[15];		/* ����ʱ�� */
	char    sDoneTime[15];		/* �������ʱ�� */
	char    sReserv1[11];		/* ϵͳ����1 */
	char    sRxReason[4];		/* �޳�����ԭ�� */
	struct RxTicketUpStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FRxTicketUpStruct{

	char    sTicketSeq[30];		/* ������� */
	char    sSpCode[5];		/* SP���� */
	char    sSpServiceCode[10];		/* SPҵ����� */
	char    sSpAccNbr[12];		/* SP������ */
	char    sServiceType[2];		/* ҵ������ */
	char    sTicketType[2];		/* �������� */
	char    sUserType[1];		/* �û����� */
	char    sMsisdn[15];		/* �û����� */
	char    sVisitCityCode[3];		/* �û��������д��� */
	char    sInfoFee[6];		/* ��Ϣ�ѷ��� */
	char    sRecvTime[14];		/* ����ʱ�� */
	char    sDoneTime[14];		/* �������ʱ�� */
	char    sReserv1[10];		/* ϵͳ����1 */
	char    sRxReason[3];		/* �޳�����ԭ�� */
};


/*�������ݶ�̬��CX_TICKET_DOWN���ýṹ���巽ʽȡ����*/
int EGetCxTicketDownToStruct(struct CxTicketDownStruct *p,
	struct CxTicketDownStructIn *pSource);

int data_search_bintree_cx_down_e(void *pValue,void*pData);

void GetCxDown(struct SmsTicketStruct *pi,struct CxTicketDownStruct *po);

void mvitem_mfrxticketup(struct RxTicketUpStruct *pi,struct FRxTicketUpStruct *po);
void mvitem_mfrxticketuphead(struct RxTicketUpHeadStruct *pi,
	struct FRxTicketUpHeadStruct *po);
/*����ṹ��������*/
struct SpTicketSjStructOut{

#ifndef SP_TICKET_SJ_BUFLEN_OUT
#define SP_TICKET_SJ_BUFLEN_OUT		300
#endif

	struct SpTicketSjStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asMsisdn[SP_TICKET_SJ_BUFLEN_OUT][16];
		/* ���д��� */
	char    asHomeAreaCode[SP_TICKET_SJ_BUFLEN_OUT][6];
		/* SP���� */
	char    asSpCode[SP_TICKET_SJ_BUFLEN_OUT][11];
		/* SPҵ����� */
	char    asSpServiceCode[SP_TICKET_SJ_BUFLEN_OUT][11];
		/* SP������ */
	char    asSpAccNbr[SP_TICKET_SJ_BUFLEN_OUT][13];
		/* SPҵ������ */
	char    asSpServiceType[SP_TICKET_SJ_BUFLEN_OUT][3];
		/* ʵ����Ϣ�ѻ������� */
	int     aiSjHdCnt[SP_TICKET_SJ_BUFLEN_OUT];
		/* SPʵ�շ��� */
	int     aiSjFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* ����� */
	int     aiTpFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* ΥԼ�ۿ��� */
	int     aiRenegeFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* ���ʽ�� */
	int     aiAdjustFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SP_TICKET_SJ_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceCode[SP_TICKET_SJ_BUFLEN_OUT][2];
		/* �ʵ��������� */
	char    asBillingCycleID[SP_TICKET_SJ_BUFLEN_OUT][7];
		/* ʵ������ */
	char    asPayCycleID[SP_TICKET_SJ_BUFLEN_OUT][7];
		/* �ʵ�����ʱ�� */
	char    asPayTime[SP_TICKET_SJ_BUFLEN_OUT][15];
};


/*�����ṹ����*/
struct SpTicketSjStruct{

	struct SpTicketSjStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sHomeAreaCode[6];		/* ���д��� */
	char    sSpCode[11];		/* SP���� */
	char    sSpServiceCode[11];		/* SPҵ����� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];		/* SPҵ������ */
	int     iSjHdCnt;		/* ʵ����Ϣ�ѻ������� */
	int     iSjFee;		/* SPʵ�շ��� */
	int     iTpFee;		/* ����� */
	int     iRenegeFee;		/* ΥԼ�ۿ��� */
	int     iAdjustFee;		/* ���ʽ�� */
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sServiceCode[2];		/* ҵ������ */
	char    sBillingCycleID[7];		/* �ʵ��������� */
	char    sPayCycleID[7];		/* ʵ������ */
	char    sPayTime[15];		/* �ʵ�����ʱ�� */
	struct SpTicketSjStruct *pLoadNext;
};


/* ����ṹ��������*/
struct SpTicketSjStructIn{

#ifndef SP_TICKET_SJ_BUFLEN_IN
#define SP_TICKET_SJ_BUFLEN_IN		300
#endif

	struct SpTicketSjStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �û����� */
	char    asMsisdn[SP_TICKET_SJ_BUFLEN_IN][16];
		/* ���д��� */
	char    asHomeAreaCode[SP_TICKET_SJ_BUFLEN_IN][6];
		/* SP���� */
	char    asSpCode[SP_TICKET_SJ_BUFLEN_IN][11];
		/* SPҵ����� */
	char    asSpServiceCode[SP_TICKET_SJ_BUFLEN_IN][11];
		/* SP������ */
	char    asSpAccNbr[SP_TICKET_SJ_BUFLEN_IN][13];
		/* SPҵ������ */
	char    asSpServiceType[SP_TICKET_SJ_BUFLEN_IN][3];
		/* ʵ����Ϣ�ѻ������� */
	int     aiSjHdCnt[SP_TICKET_SJ_BUFLEN_IN];
		/* SPʵ�շ��� */
	int     aiSjFee[SP_TICKET_SJ_BUFLEN_IN];
		/* ����� */
	int     aiTpFee[SP_TICKET_SJ_BUFLEN_IN];
		/* ΥԼ�ۿ��� */
	int     aiRenegeFee[SP_TICKET_SJ_BUFLEN_IN];
		/* ���ʽ�� */
	int     aiAdjustFee[SP_TICKET_SJ_BUFLEN_IN];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SP_TICKET_SJ_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceCode[SP_TICKET_SJ_BUFLEN_IN][2];
		/* �ʵ��������� */
	char    asBillingCycleID[SP_TICKET_SJ_BUFLEN_IN][7];
		/* ʵ������ */
	char    asPayCycleID[SP_TICKET_SJ_BUFLEN_IN][7];
		/* �ʵ�����ʱ�� */
	char    asPayTime[SP_TICKET_SJ_BUFLEN_IN][15];
};


int EGetSpTicketSjToStruct(struct SpTicketSjStruct *p,
	struct SpTicketSjStructIn *pSource);
/*�������ݽṹ����д��SP_TICKET_SJ*/
int EInsertStructToSpTicketSj(struct SpTicketSjStruct *p,
	int iInsertFlag,struct SpTicketSjStructOut *pTarget);

/*�����ṹ����*/
struct SjTicketUpHeadStruct{

	struct SjTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* �ļ����к� */
	char    sFileVersion[3];		/* �ļ��汾�� */
	char    sFileCreatDate[9];		/* �ļ�����ʱ�� */
	char    sProvCode[4];		/* ʡ�ִ��� */
	char    sBillingCycleID[7];		/* ���� */
	char    sTotalCnt[11];		/* �ܼ�¼�� */
	char    sTotalHdCnt[11];		/* ��ʵ����Ϣ�ѵĻ������� */
	char    sTotalFee[16];		/* ��ʵ����Ϣ�� */
	char    sTotalTpFee[11];		/* ������� */
	char    sTotalRenegeFee[11];		/* ��ΥԼ�ۿ� */
	char    sTotalAdjustFee[11];		/* �ܵ��ʽ�� */
	char    sReserv3[11];		/* ϵͳ����3 */
	char    sReserv4[19];		/* ϵͳ����4 */
	struct SjTicketUpHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSjTicketUpHeadStruct{

	char    sFileSeq[4];		/* �ļ����к� */
	char    sFileVersion[2];		/* �ļ��汾�� */
	char    sFileCreatDate[8];		/* �ļ�����ʱ�� */
	char    sProvCode[3];		/* ʡ�ִ��� */
	char    sBillingCycleID[6];		/* ���� */
	char    sTotalCnt[10];		/* �ܼ�¼�� */
	char    sTotalHdCnt[10];		/* ��ʵ����Ϣ�ѵĻ������� */
	char    sTotalFee[15];		/* ��ʵ����Ϣ�� */
	char    sTotalTpFee[10];		/* ������� */
	char    sTotalRenegeFee[10];		/* ��ΥԼ�ۿ� */
	char    sTotalAdjustFee[10];		/* �ܵ��ʽ�� */
	char    sReserv3[10];		/* ϵͳ����3 */
	char    sReserv4[18];		/* ϵͳ����4 */
};


/*�����ṹ����*/
struct SjTicketUpStruct{

	struct SjTicketUpStruct *pNext;
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sCityCode[4];		/* ���д��� */
	char    sReserv1[5];		/* ϵͳ����1 */
	char    sReserv2[11];		/* ϵͳ����2 */
	char    sSjHdCnt[11];		/* ʵ����Ϣ�ѵĻ������� */
	char    sSjFee[16];		/* ʵ����Ϣ�� */
	char    sTpFee[11];		/* ����� */
	char    sRenegeFee[11];		/* ΥԼ�ۿ��� */
	char    sAdjustFee[11];		/* ���ʽ�� */
	char    sReserv5[11];		/* ϵͳ����5 */
	char    sReserv6[16];		/* ϵͳ����6 */
	struct SjTicketUpStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSjTicketUpStruct{

	char    sSpCode[5];		/* SP���� */
	char    sSpAccNbr[12];		/* SP������ */
	char    sSpServiceType[2];		/* SPҵ������ */
	char    sCityCode[3];		/* ���д��� */
	char    sReserv1[4];		/* ϵͳ����1 */
	char    sReserv2[10];		/* ϵͳ����2 */
	char    sSjHdCnt[10];		/* ʵ����Ϣ�ѵĻ������� */
	char    sSjFee[15];		/* ʵ����Ϣ�� */
	char    sTpFee[10];		/* ����� */
	char    sRenegeFee[10];		/* ΥԼ�ۿ��� */
	char    sAdjustFee[10];		/* ���ʽ�� */
	char    sReserv5[10];		/* ϵͳ����5 */
	char    sReserv6[15];		/* ϵͳ����6 */
};


int data_search_bintree_spsj_e(void *pValue,void*pData);
void assign_insert_bintree_spsj_e(void **ppData,void *pData);
void mvitem_mfsjticketup(struct SjTicketUpStruct *pi,struct FSjTicketUpStruct *po);
void mvitem_mfsjticketuphead(struct SjTicketUpHeadStruct *pi,
	struct FSjTicketUpHeadStruct *po);

/*����ṹ��������*/
struct YssjChkStructOut{

#ifndef YSSJ_CHK_BUFLEN_OUT
#define YSSJ_CHK_BUFLEN_OUT		300
#endif

	struct YssjChkStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* SP���� */
	char    asSpCode[YSSJ_CHK_BUFLEN_OUT][6];
		/* SP������ */
	char    asSpAccNbr[YSSJ_CHK_BUFLEN_OUT][13];
		/* SPҵ������ */
	char    asSpServiceType[YSSJ_CHK_BUFLEN_OUT][3];
		/* ���д��� */
	char    asCityCode[YSSJ_CHK_BUFLEN_OUT][4];
		/* SPӦ����Ϣ�� */
	char    asYsFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* ʵ����Ϣ�� */
	char    asSjFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* ����� */
	char    asTpFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* ΥԼ�ۿ��� */
	char    asRenegeFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* ���ʽ�� */
	char    asAdjustFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* �ջر��� */
	int     aiRate[YSSJ_CHK_BUFLEN_OUT];
		/* �������� */
	char    asBillingCycleID[YSSJ_CHK_BUFLEN_OUT][7];
};

/* ����ṹ��������*/
struct YssjChkStructIn{

#ifndef YSSJ_CHK_BUFLEN_IN
#define YSSJ_CHK_BUFLEN_IN		300
#endif

	struct YssjChkStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* SP���� */
	char    asSpCode[YSSJ_CHK_BUFLEN_IN][6];
		/* SP������ */
	char    asSpAccNbr[YSSJ_CHK_BUFLEN_IN][13];
		/* SPҵ������ */
	char    asSpServiceType[YSSJ_CHK_BUFLEN_IN][3];
		/* ���д��� */
	char    asCityCode[YSSJ_CHK_BUFLEN_IN][4];
		/* SPӦ����Ϣ�� */
	char    asYsFee[YSSJ_CHK_BUFLEN_IN][13];
		/* ʵ����Ϣ�� */
	char    asSjFee[YSSJ_CHK_BUFLEN_IN][13];
		/* ����� */
	char    asTpFee[YSSJ_CHK_BUFLEN_IN][13];
		/* ΥԼ�ۿ��� */
	char    asRenegeFee[YSSJ_CHK_BUFLEN_IN][13];
		/* ���ʽ�� */
	char    asAdjustFee[YSSJ_CHK_BUFLEN_IN][13];
		/* �ջر��� */
	int     aiRate[YSSJ_CHK_BUFLEN_IN];
		/* �������� */
	char    asBillingCycleID[YSSJ_CHK_BUFLEN_IN][7];
};


/*�����ṹ����*/
struct YssjChkStruct{

	struct YssjChkStruct *pNext;
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sCityCode[4];		/* ���д��� */
	char    sYsFee[13];		/* SPӦ����Ϣ�� */
	char    sSjFee[13];		/* ʵ����Ϣ�� */
	char    sTpFee[13];		/* ����� */
	char    sRenegeFee[13];		/* ΥԼ�ۿ��� */
	char    sAdjustFee[13];		/* ���ʽ�� */
	int     iRate;		/* �ջر��� */
	char    sBillingCycleID[7];		/* �������� */
	struct YssjChkStruct *pLoadNext;
};


/*�������ݽṹ����д��YSSJ_CHK*/
int EInsertStructToYssjChk(struct YssjChkStruct *p,
	int iInsertFlag,struct YssjChkStructOut *pTarget);

/*�������ݶ�̬��YSSJ_CHK���ýṹ���巽ʽȡ����*/
int EGetYssjChkToStruct(struct YssjChkStruct *p,
	struct YssjChkStructIn *pSource);
int data_search_bintree_yssjchk_e(void *pValue,void*pData);
void assign_insert_bintree_yssjchk_e(void **ppData,void *pData);
int data_search_bintree_yssjchk_s_e(void *pValue,void*pData);
void GetMxYssjChk(struct MxTicketUpStruct *pi,struct YssjChkStruct *po);
void GetTpYssjChk(struct TpTicketUpStruct *pi,struct YssjChkStruct *po);

/*�����ṹ����*/
struct MxTicketUpHeadStruct{

	struct MxTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* �ļ����к� */
	char    sFileVersion[3];		/* �ļ��汾�� */
	char    sFileCreatDate[9];		/* �ļ��������� */
	char    sProvCode[4];		/* ʡ�ִ��� */
	char    sBillingCycleID[7];		/* ʵ������ */
	char    sTotalCnt[11];		/* �ܼ�¼�� */
	char    sMxFee[11];		/* Ƿ���ܽ�� */
	char    sReserv1[11];		/* ϵͳ����1 */
	char    sReserv2[16];		/* ϵͳ����2 */
	struct MxTicketUpHeadStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FMxTicketUpHeadStruct{

	char    sFileSeq[4];		/* �ļ����к� */
	char    sFileVersion[2];		/* �ļ��汾�� */
	char    sFileCreatDate[8];		/* �ļ��������� */
	char    sProvCode[3];		/* ʡ�ִ��� */
	char    sBillingCycleID[6];		/* ʵ������ */
	char    sTotalCnt[10];		/* �ܼ�¼�� */
	char    sMxFee[10];		/* Ƿ���ܽ�� */
	char    sReserv1[10];		/* ϵͳ����1 */
	char    sReserv2[15];		/* ϵͳ����2 */
};


/*�����ṹ����*/
struct MxTicketUpStruct{

	struct MxTicketUpStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sVisitCityCode[4];		/* �û��������д��� */
	char    sUserType[2];		/* �û����� */
	char    sSpCode[6];		/* SP���� */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sMxFee[7];		/* Ƿ�ѽ�� */
	char    sMxType[4];		/* Ƿ������ */
	char    sReserv1[9];		/* ϵͳ����1 */
	char    sReserv2[6];		/* ϵͳ����2 */
	char    sReserv3[11];		/* ϵͳ����3 */
	char    sReserv4[11];		/* ϵͳ����4 */
	struct MxTicketUpStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FMxTicketUpStruct{

	char    sMsisdn[15];		/* �û����� */
	char    sVisitCityCode[3];		/* �û��������д��� */
	char    sUserType[1];		/* �û����� */
	char    sSpCode[5];		/* SP���� */
	char    sSpServiceType[2];		/* SPҵ������ */
	char    sMxFee[6];		/* Ƿ�ѽ�� */
	char    sMxType[3];		/* Ƿ������ */
	char    sReserv1[8];		/* ϵͳ����1 */
	char    sReserv2[5];		/* ϵͳ����2 */
	char    sReserv3[10];		/* ϵͳ����3 */
	char    sReserv4[10];		/* ϵͳ����4 */
};
/*����ṹ��������*/
struct MxTicketUpStructOut{

#ifndef MX_TICKET_UP_BUFLEN_OUT
#define MX_TICKET_UP_BUFLEN_OUT		300
#endif

	struct MxTicketUpStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asMsisdn[MX_TICKET_UP_BUFLEN_OUT][16];
		/* �û��������д��� */
	char    asVisitCityCode[MX_TICKET_UP_BUFLEN_OUT][4];
		/* �û����� */
	char    asUserType[MX_TICKET_UP_BUFLEN_OUT][2];
		/* SP���� */
	char    asSpCode[MX_TICKET_UP_BUFLEN_OUT][6];
		/* SPҵ������ */
	char    asSpServiceType[MX_TICKET_UP_BUFLEN_OUT][3];
		/* Ƿ�ѽ�� */
	char    asMxFee[MX_TICKET_UP_BUFLEN_OUT][7];
		/* Ƿ������ */
	char    asMxType[MX_TICKET_UP_BUFLEN_OUT][4];
		/* ϵͳ����1 */
	char    asReserv1[MX_TICKET_UP_BUFLEN_OUT][9];
		/* ϵͳ����2 */
	char    asReserv2[MX_TICKET_UP_BUFLEN_OUT][6];
		/* ϵͳ����3 */
	char    asReserv3[MX_TICKET_UP_BUFLEN_OUT][11];
		/* ϵͳ����4 */
	char    asReserv4[MX_TICKET_UP_BUFLEN_OUT][11];
};



/* ����ṹ��������*/
struct MxTicketUpStructIn{

#ifndef MX_TICKET_UP_BUFLEN_IN
#define MX_TICKET_UP_BUFLEN_IN		300
#endif

	struct MxTicketUpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �û����� */
	char    asMsisdn[MX_TICKET_UP_BUFLEN_IN][16];
		/* �û��������д��� */
	char    asVisitCityCode[MX_TICKET_UP_BUFLEN_IN][4];
		/* �û����� */
	char    asUserType[MX_TICKET_UP_BUFLEN_IN][2];
		/* SP���� */
	char    asSpCode[MX_TICKET_UP_BUFLEN_IN][6];
		/* SPҵ������ */
	char    asSpServiceType[MX_TICKET_UP_BUFLEN_IN][3];
		/* Ƿ�ѽ�� */
	char    asMxFee[MX_TICKET_UP_BUFLEN_IN][7];
		/* Ƿ������ */
	char    asMxType[MX_TICKET_UP_BUFLEN_IN][4];
		/* ϵͳ����1 */
	char    asReserv1[MX_TICKET_UP_BUFLEN_IN][9];
		/* ϵͳ����2 */
	char    asReserv2[MX_TICKET_UP_BUFLEN_IN][6];
		/* ϵͳ����3 */
	char    asReserv3[MX_TICKET_UP_BUFLEN_IN][11];
		/* ϵͳ����4 */
	char    asReserv4[MX_TICKET_UP_BUFLEN_IN][11];
};
/*�������ݶ�̬��MX_TICKET_UP���ýṹ���巽ʽȡ����*/
int EGetMxTicketUpToStruct(struct MxTicketUpStruct *p,
	struct MxTicketUpStructIn *pSource);
/*�������ݽṹ����д��MX_TICKET_UP*/
int EInsertStructToMxTicketUp(struct MxTicketUpStruct *p,
	int iInsertFlag,struct MxTicketUpStructOut *pTarget);

void mvitem_mfmxticketup(struct MxTicketUpStruct *pi,struct FMxTicketUpStruct *po);
void mvitem_mfmxticketuphead(struct MxTicketUpHeadStruct *pi,
	struct FMxTicketUpHeadStruct *po);
/*�����ṹ����*/
struct TpTicketUpHeadStruct{

	struct TpTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* �ļ����к� */
	char    sFileVersion[3];		/* �ļ��汾�� */
	char    sFileCreatDate[9];		/* �ļ��������� */
	char    sProvCode[4];		/* ʡ�ִ��� */
	char    sBillingCycleID[7];		/* ���� */
	char    sTotalCnt[11];		/* �ܼ�¼�� */
	char    sTotalFee[11];		/* �ܷ��� */
	char    sReserv1[26];		/* ϵͳ����1 */
	struct TpTicketUpHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FTpTicketUpHeadStruct{

	char    sFileSeq[4];		/* �ļ����к� */
	char    sFileVersion[2];		/* �ļ��汾�� */
	char    sFileCreatDate[8];		/* �ļ��������� */
	char    sProvCode[3];		/* ʡ�ִ��� */
	char    sBillingCycleID[6];		/* ���� */
	char    sTotalCnt[10];		/* �ܼ�¼�� */
	char    sTotalFee[10];		/* �ܷ��� */
	char    sReserv1[25];		/* ϵͳ����1 */
};



/* ����ṹ��������*/
struct TpTicketUpStructIn{

#ifndef TP_TICKET_UP_BUFLEN_IN
#define TP_TICKET_UP_BUFLEN_IN		300
#endif

	struct TpTicketUpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �û����� */
	char    asMsisdn[TP_TICKET_UP_BUFLEN_IN][16];
		/* �û��������д��� */
	char    asVisitCityCode[TP_TICKET_UP_BUFLEN_IN][4];
		/* �û����� */
	char    asUserType[TP_TICKET_UP_BUFLEN_IN][2];
		/* SP���� */
	char    asSpCode[TP_TICKET_UP_BUFLEN_IN][6];
		/* SPҵ������ */
	char    asSpServiceType[TP_TICKET_UP_BUFLEN_IN][3];
		/* ������Ϣ�� */
	char    asTpFee[TP_TICKET_UP_BUFLEN_IN][7];
		/* ����ԭ�� */
	char    asTpReason[TP_TICKET_UP_BUFLEN_IN][4];
		/* ����ҵ�������� */
	char    asTpTime[TP_TICKET_UP_BUFLEN_IN][9];
		/* ϵͳ����1 */
	char    asReserv1[TP_TICKET_UP_BUFLEN_IN][6];
		/* ϵͳ����2 */
	char    asReserv2[TP_TICKET_UP_BUFLEN_IN][11];
		/* ϵͳ����3 */
	char    asReserv3[TP_TICKET_UP_BUFLEN_IN][11];
};


/*�����ṹ����*/
struct TpTicketUpStruct{

	struct TpTicketUpStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sVisitCityCode[4];		/* �û��������д��� */
	char    sUserType[2];		/* �û����� */
	char    sSpCode[6];		/* SP���� */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sTpFee[7];		/* ������Ϣ�� */
	char    sTpReason[4];		/* ����ԭ�� */
	char    sTpTime[9];		/* ����ҵ�������� */
	char    sReserv1[6];		/* ϵͳ����1 */
	char    sReserv2[11];		/* ϵͳ����2 */
	char    sReserv3[11];		/* ϵͳ����3 */
	struct TpTicketUpStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FTpTicketUpStruct{

	char    sMsisdn[15];		/* �û����� */
	char    sVisitCityCode[3];		/* �û��������д��� */
	char    sUserType[1];		/* �û����� */
	char    sSpCode[5];		/* SP���� */
	char    sSpServiceType[2];		/* SPҵ������ */
	char    sTpFee[6];		/* ������Ϣ�� */
	char    sTpReason[3];		/* ����ԭ�� */
	char    sTpTime[8];		/* ����ҵ�������� */
	char    sReserv1[5];		/* ϵͳ����1 */
	char    sReserv2[10];		/* ϵͳ����2 */
	char    sReserv3[10];		/* ϵͳ����3 */
};


/*�������ݶ�̬��TP_TICKET_UP���ýṹ���巽ʽȡ����*/
int EGetTpTicketUpToStruct(struct TpTicketUpStruct *p,
	struct TpTicketUpStructIn *pSource);
void mvitem_mftpticketup(struct TpTicketUpStruct *pi,struct FTpTicketUpStruct *po);
void mvitem_mftpticketuphead(struct TpTicketUpHeadStruct *pi,
	struct FTpTicketUpHeadStruct *po);

/* ����ṹ��������*/
struct SpContactRelationStructIn{

#ifndef SP_CONTACT_RELATION_BUFLEN_IN
#define SP_CONTACT_RELATION_BUFLEN_IN		300
#endif

	struct SpContactRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ��ϵ��ʶ */
	int     aiRelationID[SP_CONTACT_RELATION_BUFLEN_IN];
		/* ����ĺ�ͬ��ʵ�ʵĺ�ͬ��һЩ���죬����ĺ�ͬ����һ������������˼ */
	int     aiContactID[SP_CONTACT_RELATION_BUFLEN_IN];
		/* SP���� */
	char    asSpCode[SP_CONTACT_RELATION_BUFLEN_IN][21];
		/* SPҵ����� */
	char    asSpServiceCode[SP_CONTACT_RELATION_BUFLEN_IN][11];
		/* SP������� */
	char    asSpAccNbr[SP_CONTACT_RELATION_BUFLEN_IN][13];
		/* ҵ������ */
	char    asServiceType[SP_CONTACT_RELATION_BUFLEN_IN][3];
		/* ���� */
	char    asRemark[SP_CONTACT_RELATION_BUFLEN_IN][81];

	char	asEffDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	char	asExpDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	char	asState[SP_CONTACT_RELATION_BUFLEN_IN][4];
	char	asStateDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	char	asCreatedDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	
};


/*�����ṹ����*/
struct SpContactRelationStruct{

	struct SpContactRelationStruct *pNext;
	int     iRelationID;		/* ��ϵ��ʶ */
	int     iContactID;		/* ����ĺ�ͬ��ʵ�ʵĺ�ͬ��һЩ���죬����ĺ�ͬ����һ������������˼ */
	char    sSpCode[21];		/* SP���� */
	char    sSpServiceCode[11];		/* SPҵ����� */
	char    sSpAccNbr[13];		/* SP������� */
	char    sServiceType[3];		/* ҵ������ */
	char    sRemark[81];		/* ���� */

	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	
	struct SpContactRelationStruct *pLoadNext;
};


/*�������ݶ�̬��SP_CONTACT_RELATION���ýṹ���巽ʽȡ����*/
int EGetSpContactRelationToStruct(struct SpContactRelationStruct *p,
	struct SpContactRelationStructIn *pSource);
int SearchSpContactRelation(char sSpCode[],char	sSpServiceCode[],
char	sSpAccNbr[],char sStartTime[],struct SpContactRelationStruct **pptCur);

int data_search_bintree_sp_contact_relation_e(void *pValue,void*pData);

/*����ṹ��������*/
struct SpAcctItemNewStructOut{

#ifndef SP_ACCT_ITEM_NEW_BUFLEN_OUT
#define SP_ACCT_ITEM_NEW_BUFLEN_OUT		300
#endif

	struct SpAcctItemNewStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asMsisdn[SP_ACCT_ITEM_NEW_BUFLEN_OUT][16];
		/* ��������� */
	char    asHomeAreaCode[SP_ACCT_ITEM_NEW_BUFLEN_OUT][10];
		/* �ʵ��������� */
	char    asBillingCycleID[SP_ACCT_ITEM_NEW_BUFLEN_OUT][7];
		/* ʵ������ */
	char    asPayCycleID[SP_ACCT_ITEM_NEW_BUFLEN_OUT][7];
		/* SP���� */
	char    asSpCode[SP_ACCT_ITEM_NEW_BUFLEN_OUT][9];
		/* SP������ */
	char    asSpAccNbr[SP_ACCT_ITEM_NEW_BUFLEN_OUT][13];
		/* SPҵ������ */
	char    asSpServiceType[SP_ACCT_ITEM_NEW_BUFLEN_OUT][4];
		/* �������� */
	int     aiRecCnt[SP_ACCT_ITEM_NEW_BUFLEN_OUT];
		/* SPʵ���ܷ��� */
	char    asCharge[SP_ACCT_ITEM_NEW_BUFLEN_OUT][11];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SP_ACCT_ITEM_NEW_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceCode[SP_ACCT_ITEM_NEW_BUFLEN_OUT][2];
		/* �ʵ�����ʱ�� */
	char    asPayTime[SP_ACCT_ITEM_NEW_BUFLEN_OUT][15];
};


/* ����ṹ��������*/
struct SpAcctItemNewStructIn{

#ifndef SP_ACCT_ITEM_NEW_BUFLEN_IN
#define SP_ACCT_ITEM_NEW_BUFLEN_IN		300
#endif

	struct SpAcctItemNewStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �û����� */
	char    asMsisdn[SP_ACCT_ITEM_NEW_BUFLEN_IN][16];
		/* ��������� */
	char    asHomeAreaCode[SP_ACCT_ITEM_NEW_BUFLEN_IN][10];
		/* �ʵ��������� */
	char    asBillingCycleID[SP_ACCT_ITEM_NEW_BUFLEN_IN][7];
		/* ʵ������ */
	char    asPayCycleID[SP_ACCT_ITEM_NEW_BUFLEN_IN][7];
		/* SP���� */
	char    asSpCode[SP_ACCT_ITEM_NEW_BUFLEN_IN][9];
		/* SP������ */
	char    asSpAccNbr[SP_ACCT_ITEM_NEW_BUFLEN_IN][13];
		/* SPҵ������ */
	char    asSpServiceType[SP_ACCT_ITEM_NEW_BUFLEN_IN][4];
		/* �������� */
	int     aiRecCnt[SP_ACCT_ITEM_NEW_BUFLEN_IN];
		/* SPʵ���ܷ��� */
	char    asCharge[SP_ACCT_ITEM_NEW_BUFLEN_IN][11];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SP_ACCT_ITEM_NEW_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceCode[SP_ACCT_ITEM_NEW_BUFLEN_IN][2];
		/* �ʵ�����ʱ�� */
	char    asPayTime[SP_ACCT_ITEM_NEW_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SpAcctItemNewStruct{

	struct SpAcctItemNewStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sHomeAreaCode[10];		/* ��������� */
	char    sBillingCycleID[7];		/* �ʵ��������� */
	char    sPayCycleID[7];		/* ʵ������ */
	char    sSpCode[9];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[4];		/* SPҵ������ */
	int     iRecCnt;		/* �������� */
	char    sCharge[11];		/* SPʵ���ܷ��� */
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sServiceCode[2];		/* ҵ������ */
	char    sPayTime[15];		/* �ʵ�����ʱ�� */
	struct SpAcctItemNewStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSpAcctItemNewStruct{

	char    sMsisdn[15];		/* �û����� */
	char    sHomeAreaCode[9];		/* ��������� */
	char    sBillingCycleID[6];		/* �ʵ��������� */
	char    sPayCycleID[6];		/* ʵ������ */
	char    sSpCode[8];		/* SP���� */
	char    sSpAccNbr[12];		/* SP������ */
	char    sSpServiceType[3];		/* SPҵ������ */
	char    sRecCnt[8];		/* �������� */
	char    sCharge[10];		/* SPʵ���ܷ��� */
	char    sTicketTypeID[4];		/* �������ͱ�ʶ */
	char    sServiceCode[1];		/* ҵ������ */
	char    sPayTime[14];		/* �ʵ�����ʱ�� */
};

/*�������ݶ�̬��SP_ACCT_ITEM_NEW���ýṹ���巽ʽȡ����*/
int EGetSpAcctItemNewToStruct(struct SpAcctItemNewStruct *p,
	struct SpAcctItemNewStructIn *pSource);
/*�������ݽṹ����д��SP_ACCT_ITEM_NEW*/
int EInsertStructToSpAcctItemNew(struct SpAcctItemNewStruct *p,
	int iInsertFlag,struct SpAcctItemNewStructOut *pTarget);

int ChkSpCode(char sSpCode[],char sSpAccNbr[],char sSpServiceCode[]);

void SetHomeAreaCode(char sHomeAreaCodeIn[],char sHomeAreaCodeOut[]);
void SetSpAccNbr(struct SmsTicketStruct *pi);

/*����ṹ��������*/
struct SpUserStatStructOut{

#ifndef SP_USER_STAT_BUFLEN_OUT
#define SP_USER_STAT_BUFLEN_OUT		300
#endif

	struct SpUserStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asMsisdn[SP_USER_STAT_BUFLEN_OUT][16];
		/* �û������� */
	char    asHomeAreaCode[SP_USER_STAT_BUFLEN_OUT][6];
		/* �û����� */
	char    asUserType[SP_USER_STAT_BUFLEN_OUT][2];
		/* SP�����ʶ */
	int     aiContactID[SP_USER_STAT_BUFLEN_OUT];
		/* SP���� */
	char    asSpCode[SP_USER_STAT_BUFLEN_OUT][6];
		/* SP������ */
	char    asSpAccNbr[SP_USER_STAT_BUFLEN_OUT][13];
		/* SP������� */
	char    asSpServiceCode[SP_USER_STAT_BUFLEN_OUT][21];
		/* �������� */
	int     aiTicketTypeID[SP_USER_STAT_BUFLEN_OUT];
		/* ����ΪXX */
	char    asSpServiceType[SP_USER_STAT_BUFLEN_OUT][3];
		/* SPӦ��ͨ�ŷ� */
	int     aiYsCommFee[SP_USER_STAT_BUFLEN_OUT];
		/* SPӦ����Ϣ�� */
	int     aiYsInfoFee[SP_USER_STAT_BUFLEN_OUT];
		/* ʵ����Ϣ�� */
	int     aiSjInfoFee[SP_USER_STAT_BUFLEN_OUT];
		/* �Żݽ�� */
	int     aiDisctAmnt[SP_USER_STAT_BUFLEN_OUT];
		/* ����� */
	int     aiTpFee[SP_USER_STAT_BUFLEN_OUT];
		/* ΥԼ�ۿ��� */
	int     aiRenegeFee[SP_USER_STAT_BUFLEN_OUT];
		/* ���ʽ�� */
	int     aiAdjustFee[SP_USER_STAT_BUFLEN_OUT];
		/* ����ͨ�ŷ� */
	int     aiUpCommFee[SP_USER_STAT_BUFLEN_OUT];
		/* �������� */
	int     aiUpCnt[SP_USER_STAT_BUFLEN_OUT];
		/* �������� */
	int     aiDownCnt[SP_USER_STAT_BUFLEN_OUT];
		/* ����������ͨ�ŷ� */
	int     aiDiffCommFee[SP_USER_STAT_BUFLEN_OUT];
		/* Ƿ�ѽ�� */
	int     aiQfAmnt[SP_USER_STAT_BUFLEN_OUT];
		/* ʵ�ʻ����� */
	int     aiSjBadRate[SP_USER_STAT_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutFee[SP_USER_STAT_BUFLEN_OUT];
		/* �������� */
	char    asBillingCycleID[SP_USER_STAT_BUFLEN_OUT][7];
};

/* ����ṹ��������*/
struct SpUserStatStructIn{

#ifndef SP_USER_STAT_BUFLEN_IN
#define SP_USER_STAT_BUFLEN_IN		300
#endif

	struct SpUserStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �û����� */
	char    asMsisdn[SP_USER_STAT_BUFLEN_IN][16];
		/* �û������� */
	char    asHomeAreaCode[SP_USER_STAT_BUFLEN_IN][6];
		/* �û����� */
	char    asUserType[SP_USER_STAT_BUFLEN_IN][2];
		/* SP�����ʶ */
	int     aiContactID[SP_USER_STAT_BUFLEN_IN];
		/* SP���� */
	char    asSpCode[SP_USER_STAT_BUFLEN_IN][6];
		/* SP������ */
	char    asSpAccNbr[SP_USER_STAT_BUFLEN_IN][13];
		/* SP������� */
	char    asSpServiceCode[SP_USER_STAT_BUFLEN_IN][21];
		/* �������� */
	int     aiTicketTypeID[SP_USER_STAT_BUFLEN_IN];
		/* ����ΪXX */
	char    asSpServiceType[SP_USER_STAT_BUFLEN_IN][3];
		/* SPӦ��ͨ�ŷ� */
	int     aiYsCommFee[SP_USER_STAT_BUFLEN_IN];
		/* SPӦ����Ϣ�� */
	int     aiYsInfoFee[SP_USER_STAT_BUFLEN_IN];
		/* ʵ����Ϣ�� */
	int     aiSjInfoFee[SP_USER_STAT_BUFLEN_IN];
		/* �Żݽ�� */
	int     aiDisctAmnt[SP_USER_STAT_BUFLEN_IN];
		/* ����� */
	int     aiTpFee[SP_USER_STAT_BUFLEN_IN];
		/* ΥԼ�ۿ��� */
	int     aiRenegeFee[SP_USER_STAT_BUFLEN_IN];
		/* ���ʽ�� */
	int     aiAdjustFee[SP_USER_STAT_BUFLEN_IN];
		/* ����ͨ�ŷ� */
	int     aiUpCommFee[SP_USER_STAT_BUFLEN_IN];
		/* �������� */
	int     aiUpCnt[SP_USER_STAT_BUFLEN_IN];
		/* �������� */
	int     aiDownCnt[SP_USER_STAT_BUFLEN_IN];
		/* ����������ͨ�ŷ� */
	int     aiDiffCommFee[SP_USER_STAT_BUFLEN_IN];
		/* Ƿ�ѽ�� */
	int     aiQfAmnt[SP_USER_STAT_BUFLEN_IN];
		/* ʵ�ʻ����� */
	int     aiSjBadRate[SP_USER_STAT_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutFee[SP_USER_STAT_BUFLEN_IN];
		/* �������� */
	char    asBillingCycleID[SP_USER_STAT_BUFLEN_IN][7];
};


/*�����ṹ����*/
struct SpUserStatStruct{

	struct SpUserStatStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sHomeAreaCode[6];		/* �û������� */
	char    sUserType[2];		/* �û����� */
	int     iContactID;		/* SP�����ʶ */
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceCode[21];		/* SP������� */
	int     iTicketTypeID;		/* �������� */
	char    sSpServiceType[3];		/* ����ΪXX */
	int     iYsCommFee;		/* SPӦ��ͨ�ŷ� */
	int     iYsInfoFee;		/* SPӦ����Ϣ�� */
	int     iSjInfoFee;		/* ʵ����Ϣ�� */
	int     iDisctAmnt;		/* �Żݽ�� */
	int     iTpFee;		/* ����� */
	int     iRenegeFee;		/* ΥԼ�ۿ��� */
	int     iAdjustFee;		/* ���ʽ�� */
	int     iUpCommFee;		/* ����ͨ�ŷ� */
	int     iUpCnt;		/* �������� */
	int     iDownCnt;		/* �������� */
	int     iDiffCommFee;		/* ����������ͨ�ŷ� */
	int     iQfAmnt;		/* Ƿ�ѽ�� */
	int     iSjBadRate;		/* ʵ�ʻ����� */
	int     iOutFee;		/* ����֧�� */
	char    sBillingCycleID[7];		/* �������� */
	struct SpUserStatStruct *pLoadNext;
};




/*�������ݽṹ����д��SP_USER_STAT*/
int EInsertStructToSpUserStat(struct SpUserStatStruct *p,
	int iInsertFlag,struct SpUserStatStructOut *pTarget);


#endif

