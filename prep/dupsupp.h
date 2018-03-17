#ifndef __DUPSUPP__
#define __DUPSUPP__

/*����ṹ��������*/
struct DupTicketStructOut{

#ifndef DUP_TICKET_BUFLEN_OUT
#define DUP_TICKET_BUFLEN_OUT		300
#endif

	struct DupTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asCallType[DUP_TICKET_BUFLEN_OUT][3];
		/* �û����� */
	char    asMsisdn[DUP_TICKET_BUFLEN_OUT][13];
		/* �Զ˺��� */
	char    asOtherParty[DUP_TICKET_BUFLEN_OUT][21];
		/* Ӧ��ʱ��Сʱ */
	char    asHour[DUP_TICKET_BUFLEN_OUT][3];
		/* Ӧ��ʱ����� */
	char    asMiss[DUP_TICKET_BUFLEN_OUT][5];
		/* ͨ��ʱ�� */
	char    asDuration[DUP_TICKET_BUFLEN_OUT][7];
		/* �ļ���Դ */
	char    asSourceID[DUP_TICKET_BUFLEN_OUT][31];
};


/* ����ṹ��������*/
struct DupTicketStructIn{

#ifndef DUP_TICKET_BUFLEN_IN
#define DUP_TICKET_BUFLEN_IN		300
#endif

	struct DupTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asCallType[DUP_TICKET_BUFLEN_IN][3];
		/* �û����� */
	char    asMsisdn[DUP_TICKET_BUFLEN_IN][13];
		/* �Զ˺��� */
	char    asOtherParty[DUP_TICKET_BUFLEN_IN][21];
		/* Ӧ��ʱ��Сʱ */
	char    asHour[DUP_TICKET_BUFLEN_IN][3];
		/* Ӧ��ʱ����� */
	char    asMiss[DUP_TICKET_BUFLEN_IN][5];
		/* ͨ��ʱ�� */
	char    asDuration[DUP_TICKET_BUFLEN_IN][7];
		/* �ļ���Դ */
	char    asSourceID[DUP_TICKET_BUFLEN_IN][31];
};


/*�����ṹ����*/
struct DupTicketStruct{

	struct DupTicketStruct *pNext;
	char    sCallType[3];		/* �������� */
	char    sMsisdn[13];		/* �û����� */
	char    sOtherParty[21];	/* �Զ˺��� */
	char    sHour[3];		/* Ӧ��ʱ��Сʱ */
	char    sMiss[5];		/* Ӧ��ʱ����� */
	char    sDuration[7];		/* ͨ��ʱ�� */
	char    sSourceID[31];		/* �ļ���Դ */
	
	char	sStartTime[15];		/*MODIFY HERE*/

	time_t	tStartTime;
	int	iDuration;
	int	iDupFlag;
	void	*pOri;
	struct DupTicketStruct *pLoadNext;
};
int EGetDupTicketToStruct(struct DupTicketStruct *p,
	struct DupTicketStructIn *pSource);
int InitDupTicket(char sDataDate[],char sModule[],char sTablespaceName[],
	struct DupTicketStruct **pptHead);
int EInsertStructToDupTicket(struct DupTicketStruct *p,
	int iInsertFlag,struct DupTicketStructOut *pTarget);


/*����ṹ��������*/
struct HourNodeStructOut{

#ifndef HOUR_NODE_BUFLEN_OUT
#define HOUR_NODE_BUFLEN_OUT		300
#endif

	struct HourNodeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ģ�� */
	char    asModule[HOUR_NODE_BUFLEN_OUT][4];
		/* �ļ�����(Сʱ) */
	char    asDataDate[HOUR_NODE_BUFLEN_OUT][15];
		/* ������Сʱ�� */
	int	aiMinAcrossBeginTime[HOUR_NODE_BUFLEN_OUT];
		/* �������ʱ�� */
	int	aiMaxAcrossEndTime[HOUR_NODE_BUFLEN_OUT];
		/* ��¼�� */
	int     aiRecordCnt[HOUR_NODE_BUFLEN_OUT];
		/* �ڵ��� */
	int     aiNodeCnt[HOUR_NODE_BUFLEN_OUT];
		/* ������ */
	int     aiReadTimes[HOUR_NODE_BUFLEN_OUT];
		/* д���� */
	int     aiWriteTimes[HOUR_NODE_BUFLEN_OUT];
		/* �����ؽ����� */
	int     aiRebuildTimes[HOUR_NODE_BUFLEN_OUT];
		/* ����״̬ */
	char    asState[HOUR_NODE_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
struct HourNodeStructIn{

#ifndef HOUR_NODE_BUFLEN_IN
#define HOUR_NODE_BUFLEN_IN		300
#endif

	struct HourNodeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ģ�� */
	char    asModule[HOUR_NODE_BUFLEN_IN][4];
		/* �ļ�����(Сʱ) */
	char    asDataDate[HOUR_NODE_BUFLEN_IN][15];
		/* ������Сʱ�� */
	int	aiMinAcrossBeginTime[HOUR_NODE_BUFLEN_IN];
		/* �������ʱ�� */
	int	aiMaxAcrossEndTime[HOUR_NODE_BUFLEN_IN];
		/* ��¼�� */
	int     aiRecordCnt[HOUR_NODE_BUFLEN_IN];
		/* �ڵ��� */
	int     aiNodeCnt[HOUR_NODE_BUFLEN_IN];
		/* ������ */
	int     aiReadTimes[HOUR_NODE_BUFLEN_IN];
		/* д���� */
	int     aiWriteTimes[HOUR_NODE_BUFLEN_IN];
		/* �����ؽ����� */
	int     aiRebuildTimes[HOUR_NODE_BUFLEN_IN];
		/* ����״̬ */
	char    asState[HOUR_NODE_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct HourNodeStruct{

	struct HourNodeStruct *pNext;
	char    sModule[4];		/* ģ�� */
	char    sDataDate[15];		/* �ļ�����(Сʱ) */
	int	iMinAcrossBeginTime;		/* ������Сʱ�� */
	int	iMaxAcrossEndTime;		/* �������ʱ�� */
	int     iRecordCnt;		/* ��¼�� */
	int     iNodeCnt;		/* �ڵ��� */
	int     iReadTimes;		/* ������ */
	int     iWriteTimes;		/* д���� */
	int     iRebuildTimes;		/* �����ؽ����� */
	char    sState[2];		/* ����״̬ */
	struct HourNodeStruct *pLoadNext;
};

/*����ṹ��������*/
struct HourNodeStructUp{

#ifndef HOUR_NODE_BUFLEN_UP
#define HOUR_NODE_BUFLEN_UP		300
#endif

	struct HourNodeStructOut *pNext;

	int iCurPos;
	char sTableName[31];
	char    asModule[HOUR_NODE_BUFLEN_UP][4];
	char    asDataDate[HOUR_NODE_BUFLEN_UP][15];
	int	aiMinAcrossBeginTime[HOUR_NODE_BUFLEN_UP];
	int	aiMaxAcrossEndTime[HOUR_NODE_BUFLEN_UP];
	int     aiRecordCnt[HOUR_NODE_BUFLEN_UP];
	int     aiNodeCnt[HOUR_NODE_BUFLEN_UP];
	int     aiReadTimes[HOUR_NODE_BUFLEN_UP];
	int     aiWriteTimes[HOUR_NODE_BUFLEN_UP];
	int     aiRebuildTimes[HOUR_NODE_BUFLEN_UP];
	char    asState[HOUR_NODE_BUFLEN_UP][2];
};


/*�������ݶ�̬��HOUR_NODE���ýṹ���巽ʽȡ����*/
int EGetHourNodeToStruct(struct HourNodeStruct *p,
	struct HourNodeStructIn *pSource);
/*�������ݽṹ����д��HOUR_NODE*/
int EInsertStructToHourNode(struct HourNodeStruct *p,
	int iInsertFlag,struct HourNodeStructOut *pTarget);
void DestroyHourNode(struct HourNodeStruct *ptHead);
int InitHourNode(char sModule[],char sBeginDate[],char sEndDate[],
	struct HourNodeStruct **pptHead);
	
int EUpdateStructToHourNode(struct HourNodeStruct *p,
	int iUpdateFlag,struct HourNodeStructUp *pTarget);


#endif

