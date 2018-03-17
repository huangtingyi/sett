#ifndef __BIINTF_NBR_SUPP_H__
#define __BIINTF_NBR_SUPP_H__


/*����ṹ��������*/
struct SettNbrIntfFjbiStructOut{

#ifndef SETT_NBR_INTF_FJBI_BUFLEN_OUT
#define SETT_NBR_INTF_FJBI_BUFLEN_OUT		300
#endif

	struct SettNbrIntfFjbiStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asBillingCycleID[SETT_NBR_INTF_FJBI_BUFLEN_OUT][7];
		/* ��������� */
	char    asVisitAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* ������� */
	char    asAccNbr[SETT_NBR_INTF_FJBI_BUFLEN_OUT][25];
		/* ���к�������� */
	char    asHomeAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* ���к�������� */
	char    asOppAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* ����ͨ���� */
	char    asRoamAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_OUT][6];
		/* ���к�����Ӫ�� */
	int     aiHomeCarrID[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ���к�����Ӫ�� */
	int     aiOppCarrID[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ���з������ */
	int     aiCallDirection[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* �������� */
	int     aiTicketTypeID[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ������ */
	int     aiCnt[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ����ʱ�� */
	int     aiFeeDuration[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* �������� */
	int     aiInFee[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ����֧�� */
	int     aiOutFee[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceType[SETT_NBR_INTF_FJBI_BUFLEN_OUT][4];
		/* �����û��������� */
	char    asNbrType[SETT_NBR_INTF_FJBI_BUFLEN_OUT][5];
		/* �Է��û��������� */
	char    asOppNbrType[SETT_NBR_INTF_FJBI_BUFLEN_OUT][5];
		/* ������֧��ʶ */
	int     aiSettFlag[SETT_NBR_INTF_FJBI_BUFLEN_OUT];
		/* ����ά��1 */
	char    asReserve1[SETT_NBR_INTF_FJBI_BUFLEN_OUT][11];
		/* ����ά��2 */
	char    asReserve2[SETT_NBR_INTF_FJBI_BUFLEN_OUT][11];
		/* ����ʱ�� */
	char    asDealDate[SETT_NBR_INTF_FJBI_BUFLEN_OUT][15];
};


/* ����ṹ��������*/
struct SettNbrIntfFjbiStructIn{

#ifndef SETT_NBR_INTF_FJBI_BUFLEN_IN
#define SETT_NBR_INTF_FJBI_BUFLEN_IN		300
#endif

	struct SettNbrIntfFjbiStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asBillingCycleID[SETT_NBR_INTF_FJBI_BUFLEN_IN][7];
		/* ��������� */
	char    asVisitAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* ������� */
	char    asAccNbr[SETT_NBR_INTF_FJBI_BUFLEN_IN][25];
		/* ���к�������� */
	char    asHomeAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* ���к�������� */
	char    asOppAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* ����ͨ���� */
	char    asRoamAreaCode[SETT_NBR_INTF_FJBI_BUFLEN_IN][6];
		/* ���к�����Ӫ�� */
	int     aiHomeCarrID[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ���к�����Ӫ�� */
	int     aiOppCarrID[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ���з������ */
	int     aiCallDirection[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* �������� */
	int     aiTicketTypeID[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ������ */
	int     aiCnt[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ͨ��ʱ�� */
	int     aiDuration[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ����ʱ�� */
	int     aiFeeDuration[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* �������� */
	int     aiInFee[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ����֧�� */
	int     aiOutFee[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceType[SETT_NBR_INTF_FJBI_BUFLEN_IN][4];
		/* �����û��������� */
	char    asNbrType[SETT_NBR_INTF_FJBI_BUFLEN_IN][5];
		/* �Է��û��������� */
	char    asOppNbrType[SETT_NBR_INTF_FJBI_BUFLEN_IN][5];
		/* ������֧��ʶ */
	int     aiSettFlag[SETT_NBR_INTF_FJBI_BUFLEN_IN];
		/* ����ά��1 */
	char    asReserve1[SETT_NBR_INTF_FJBI_BUFLEN_IN][11];
		/* ����ά��2 */
	char    asReserve2[SETT_NBR_INTF_FJBI_BUFLEN_IN][11];
		/* ����ʱ�� */
	char    asDealDate[SETT_NBR_INTF_FJBI_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SettNbrIntfFjbiStruct{

	struct SettNbrIntfFjbiStruct *pNext;
	char    sBillingCycleID[7];		/* �������� */
	char    sVisitAreaCode[6];		/* ��������� */
	char    sAccNbr[25];		/* ������� */
	char    sHomeAreaCode[6];		/* ���к�������� */
	char    sOppAreaCode[6];		/* ���к�������� */
	char    sRoamAreaCode[6];		/* ����ͨ���� */
	int     iHomeCarrID;		/* ���к�����Ӫ�� */
	int     iOppCarrID;		/* ���к�����Ӫ�� */
	int     iCallDirection;		/* ���з������ */
	int     iTicketTypeID;		/* �������� */
	int     iCnt;		/* ������ */
	int     iDuration;		/* ͨ��ʱ�� */
	int     iFeeDuration;		/* ����ʱ�� */
	int     iInFee;		/* �������� */
	int     iOutFee;		/* ����֧�� */
	char    sServiceType[4];		/* ҵ������ */
	char    sNbrType[5];		/* �����û��������� */
	char    sOppNbrType[5];		/* �Է��û��������� */
	int     iSettFlag;		/* ������֧��ʶ */
	char    sReserve1[11];		/* ����ά��1 */
	char    sReserve2[11];		/* ����ά��2 */
	char    sDealDate[15];		/* ����ʱ�� */
	struct SettNbrIntfFjbiStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettNbrIntfFjbiStruct{

	char    sBillingCycleID[6];		/* �������� */
	char    sVisitAreaCode[5];		/* ��������� */
	char    sAccNbr[24];		/* ������� */
	char    sHomeAreaCode[5];		/* ���к�������� */
	char    sOppAreaCode[5];		/* ���к�������� */
	char    sRoamAreaCode[5];		/* ����ͨ���� */
	char    sHomeCarrID[4];		/* ���к�����Ӫ�� */
	char    sOppCarrID[4];		/* ���к�����Ӫ�� */
	char    sCallDirection[4];		/* ���з������ */
	char    sTicketTypeID[4];		/* �������� */
	char    sCnt[9];		/* ������ */
	char    sDuration[9];		/* ͨ��ʱ�� */
	char    sFeeDuration[9];		/* ����ʱ�� */
	char    sInFee[9];		/* �������� */
	char    sOutFee[9];		/* ����֧�� */
	char    sServiceType[3];		/* ҵ������ */
	char    sNbrType[4];		/* �����û��������� */
	char    sOppNbrType[4];		/* �Է��û��������� */
	char    sSettFlag[4];		/* ������֧��ʶ */
	char    sReserve1[10];		/* ����ά��1 */
	char    sReserve2[10];		/* ����ά��2 */
	char    sDealDate[14];		/* ����ʱ�� */
};
/*�������ݶ�̬��SETT_NBR_INTF_FJBI���ýṹ���巽ʽȡ����*/
int EGetSettNbrIntfFjbiToStruct(struct SettNbrIntfFjbiStruct *p,
	struct SettNbrIntfFjbiStructIn *pSource);
/*�������ݽṹ����д��SETT_NBR_INTF_FJBI*/
int EInsertStructToSettNbrIntfFjbi(struct SettNbrIntfFjbiStruct *p,
	int iInsertFlag,struct SettNbrIntfFjbiStructOut *pTarget);
void mvitem_settnbrintffjbi(struct SettNbrIntfFjbiStruct *pi,struct SettNbrIntfFjbiStruct *po);

#endif
