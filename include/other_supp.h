#ifndef __OTHER_SUPP_H__
#define __OTHER_SUPP_H__

/*输出结构缓冲申明*/
struct ChkSttTicketStructOut{

#ifndef CHK_STT_TICKET_BUFLEN_OUT
#define CHK_STT_TICKET_BUFLEN_OUT		300
#endif

	struct ChkSttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类别ID */
	char    asTicketTypeID[CHK_STT_TICKET_BUFLEN_OUT][11];
		/* 呼叫类型 */
	char    asCallType[CHK_STT_TICKET_BUFLEN_OUT][3];
		/* 主叫号码 */
	char    asMsisdn[CHK_STT_TICKET_BUFLEN_OUT][31];
		/* 被叫号码 */
	char    asOtherParty[CHK_STT_TICKET_BUFLEN_OUT][31];
		/* 通话时间 */
	char    asStartTime[CHK_STT_TICKET_BUFLEN_OUT][21];
		/* 通话时长 */
	int     aiDuration[CHK_STT_TICKET_BUFLEN_OUT];
		/* 交换机 */
	char    asMsc[CHK_STT_TICKET_BUFLEN_OUT][21];
		/* 入中继 */
	char    asTrunkIn[CHK_STT_TICKET_BUFLEN_OUT][21];
		/* 出中继 */
	char    asTrunkOut[CHK_STT_TICKET_BUFLEN_OUT][21];
	char    asType[CHK_STT_TICKET_BUFLEN_OUT][2];
	char    asSerialNbr[CHK_STT_TICKET_BUFLEN_OUT][21];
	char	asRowID[CHK_STT_TICKET_BUFLEN_OUT][19];
};


/* 输入结构缓冲申明*/
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
		/* 话单类别ID */
	char    asTicketTypeID[CHK_STT_TICKET_BUFLEN_IN][11];
		/* 呼叫类型 */
	char    asCallType[CHK_STT_TICKET_BUFLEN_IN][3];
		/* 主叫号码 */
	char    asMsisdn[CHK_STT_TICKET_BUFLEN_IN][31];
		/* 被叫号码 */
	char    asOtherParty[CHK_STT_TICKET_BUFLEN_IN][31];
		/* 通话时间 */
	char    asStartTime[CHK_STT_TICKET_BUFLEN_IN][21];
		/* 通话时长 */
	int     aiDuration[CHK_STT_TICKET_BUFLEN_IN];
		/* 交换机 */
	char    asMsc[CHK_STT_TICKET_BUFLEN_IN][21];
		/* 入中继 */
	char    asTrunkIn[CHK_STT_TICKET_BUFLEN_IN][21];
		/* 出中继 */
	char    asTrunkOut[CHK_STT_TICKET_BUFLEN_IN][21];
	char    asType[CHK_STT_TICKET_BUFLEN_IN][2];
	char    asSerialNbr[CHK_STT_TICKET_BUFLEN_IN][21];
	char	asRowID[CHK_STT_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct ChkSttTicketStruct{

	struct ChkSttTicketStruct *pNext;
	char    sTicketTypeID[11];		/* 话单类别ID */
	char    sCallType[3];		/* 呼叫类型 */
	char    sMsisdn[31];		/* 主叫号码 */
	char    sOtherParty[31];		/* 被叫号码 */
	char    sStartTime[21];		/* 通话时间 */
	int     iDuration;		/* 通话时长 */
	char    sMsc[21];		/* 交换机 */
	char    sTrunkIn[21];		/* 入中继 */
	char    sTrunkOut[21];		/* 出中继 */
	char    sType[2];
	char    sSerialNbr[21];
	char	sRowID[19];
	struct ChkSttTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FChkSttTicketStruct{

	char    sTicketTypeID[10];		/* 话单类别ID */
	char    sCallType[2];		/* 呼叫类型 */
	char    sMsisdn[30];		/* 主叫号码 */
	char    sOtherParty[30];		/* 被叫号码 */
	char    sStartTime[20];		/* 通话时间 */
	char    sDuration[6];		/* 通话时长 */
	char    sMsc[20];		/* 交换机 */
	char    sTrunkIn[20];		/* 入中继 */
	char    sTrunkOut[20];		/* 出中继 */
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
		/* 类型 */
	char    asType[CHK_STT_TICKET_BUFLEN_UP][2];
		/* 序列号 */
	char    asSerialNbr[CHK_STT_TICKET_BUFLEN_UP][21];
	char	asRowID[CHK_STT_TICKET_BUFLEN_UP][19];
};

/*批量数据动态从CHK_STT_TICKET中用结构缓冲方式取数据*/
int EGetChkSttTicketToStruct(struct ChkSttTicketStruct *p,
	struct ChkSttTicketStructIn *pSource);
/*批量数据结构缓冲写入CHK_STT_TICKET*/
int EInsertStructToChkSttTicket(struct ChkSttTicketStruct *p,
	int iInsertFlag,struct ChkSttTicketStructOut *pTarget);
int EUpdateStructToChkSttTicket(struct ChkSttTicketStruct *p,
	int iUpdateFlag,struct ChkSttTicketStructUp *pTarget);

#endif

