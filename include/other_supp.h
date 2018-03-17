#ifndef __OTHER_SUPP_H__
#define __OTHER_SUPP_H__

/*����ṹ��������*/
struct ChkSttTicketStructOut{

#ifndef CHK_STT_TICKET_BUFLEN_OUT
#define CHK_STT_TICKET_BUFLEN_OUT		300
#endif

	struct ChkSttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������ID */
	char    asTicketTypeID[CHK_STT_TICKET_BUFLEN_OUT][11];
		/* �������� */
	char    asCallType[CHK_STT_TICKET_BUFLEN_OUT][3];
		/* ���к��� */
	char    asMsisdn[CHK_STT_TICKET_BUFLEN_OUT][31];
		/* ���к��� */
	char    asOtherParty[CHK_STT_TICKET_BUFLEN_OUT][31];
		/* ͨ��ʱ�� */
	char    asStartTime[CHK_STT_TICKET_BUFLEN_OUT][21];
		/* ͨ��ʱ�� */
	int     aiDuration[CHK_STT_TICKET_BUFLEN_OUT];
		/* ������ */
	char    asMsc[CHK_STT_TICKET_BUFLEN_OUT][21];
		/* ���м� */
	char    asTrunkIn[CHK_STT_TICKET_BUFLEN_OUT][21];
		/* ���м� */
	char    asTrunkOut[CHK_STT_TICKET_BUFLEN_OUT][21];
	char    asType[CHK_STT_TICKET_BUFLEN_OUT][2];
	char    asSerialNbr[CHK_STT_TICKET_BUFLEN_OUT][21];
	char	asRowID[CHK_STT_TICKET_BUFLEN_OUT][19];
};


/* ����ṹ��������*/
struct ChkSttTicketStructIn{

#ifndef CHK_STT_TICKET_BUFLEN_IN
#define CHK_STT_TICKET_BUFLEN_IN		300
#endif

	struct ChkSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������ID */
	char    asTicketTypeID[CHK_STT_TICKET_BUFLEN_IN][11];
		/* �������� */
	char    asCallType[CHK_STT_TICKET_BUFLEN_IN][3];
		/* ���к��� */
	char    asMsisdn[CHK_STT_TICKET_BUFLEN_IN][31];
		/* ���к��� */
	char    asOtherParty[CHK_STT_TICKET_BUFLEN_IN][31];
		/* ͨ��ʱ�� */
	char    asStartTime[CHK_STT_TICKET_BUFLEN_IN][21];
		/* ͨ��ʱ�� */
	int     aiDuration[CHK_STT_TICKET_BUFLEN_IN];
		/* ������ */
	char    asMsc[CHK_STT_TICKET_BUFLEN_IN][21];
		/* ���м� */
	char    asTrunkIn[CHK_STT_TICKET_BUFLEN_IN][21];
		/* ���м� */
	char    asTrunkOut[CHK_STT_TICKET_BUFLEN_IN][21];
	char    asType[CHK_STT_TICKET_BUFLEN_IN][2];
	char    asSerialNbr[CHK_STT_TICKET_BUFLEN_IN][21];
	char	asRowID[CHK_STT_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct ChkSttTicketStruct{

	struct ChkSttTicketStruct *pNext;
	char    sTicketTypeID[11];		/* �������ID */
	char    sCallType[3];		/* �������� */
	char    sMsisdn[31];		/* ���к��� */
	char    sOtherParty[31];		/* ���к��� */
	char    sStartTime[21];		/* ͨ��ʱ�� */
	int     iDuration;		/* ͨ��ʱ�� */
	char    sMsc[21];		/* ������ */
	char    sTrunkIn[21];		/* ���м� */
	char    sTrunkOut[21];		/* ���м� */
	char    sType[2];
	char    sSerialNbr[21];
	char	sRowID[19];
	struct ChkSttTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FChkSttTicketStruct{

	char    sTicketTypeID[10];		/* �������ID */
	char    sCallType[2];		/* �������� */
	char    sMsisdn[30];		/* ���к��� */
	char    sOtherParty[30];		/* ���к��� */
	char    sStartTime[20];		/* ͨ��ʱ�� */
	char    sDuration[6];		/* ͨ��ʱ�� */
	char    sMsc[20];		/* ������ */
	char    sTrunkIn[20];		/* ���м� */
	char    sTrunkOut[20];		/* ���м� */
	char    sType[1];
	char    sSerialNbr[20];
};
struct ChkSttTicketStructUp
{
#ifndef CHK_STT_TICKET_BUFLEN_UP
#define CHK_STT_TICKET_BUFLEN_UP 	300
#endif
	int	iCurPos;
	char	sTableName[31];
		/* ���� */
	char    asType[CHK_STT_TICKET_BUFLEN_UP][2];
		/* ���к� */
	char    asSerialNbr[CHK_STT_TICKET_BUFLEN_UP][21];
	char	asRowID[CHK_STT_TICKET_BUFLEN_UP][19];
};

/*�������ݶ�̬��CHK_STT_TICKET���ýṹ���巽ʽȡ����*/
int EGetChkSttTicketToStruct(struct ChkSttTicketStruct *p,
	struct ChkSttTicketStructIn *pSource);
/*�������ݽṹ����д��CHK_STT_TICKET*/
int EInsertStructToChkSttTicket(struct ChkSttTicketStruct *p,
	int iInsertFlag,struct ChkSttTicketStructOut *pTarget);
int EUpdateStructToChkSttTicket(struct ChkSttTicketStruct *p,
	int iUpdateFlag,struct ChkSttTicketStructUp *pTarget);

#endif

