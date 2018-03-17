#ifndef __DUPSUPP__
#define __DUPSUPP__

/*输出结构缓冲申明*/
struct DupTicketStructOut{

#ifndef DUP_TICKET_BUFLEN_OUT
#define DUP_TICKET_BUFLEN_OUT		300
#endif

	struct DupTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 呼叫类型 */
	char    asCallType[DUP_TICKET_BUFLEN_OUT][3];
		/* 用户号码 */
	char    asMsisdn[DUP_TICKET_BUFLEN_OUT][13];
		/* 对端号码 */
	char    asOtherParty[DUP_TICKET_BUFLEN_OUT][21];
		/* 应答时间小时 */
	char    asHour[DUP_TICKET_BUFLEN_OUT][3];
		/* 应答时间分秒 */
	char    asMiss[DUP_TICKET_BUFLEN_OUT][5];
		/* 通话时长 */
	char    asDuration[DUP_TICKET_BUFLEN_OUT][7];
		/* 文件来源 */
	char    asSourceID[DUP_TICKET_BUFLEN_OUT][31];
};


/* 输入结构缓冲申明*/
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
		/* 呼叫类型 */
	char    asCallType[DUP_TICKET_BUFLEN_IN][3];
		/* 用户号码 */
	char    asMsisdn[DUP_TICKET_BUFLEN_IN][13];
		/* 对端号码 */
	char    asOtherParty[DUP_TICKET_BUFLEN_IN][21];
		/* 应答时间小时 */
	char    asHour[DUP_TICKET_BUFLEN_IN][3];
		/* 应答时间分秒 */
	char    asMiss[DUP_TICKET_BUFLEN_IN][5];
		/* 通话时长 */
	char    asDuration[DUP_TICKET_BUFLEN_IN][7];
		/* 文件来源 */
	char    asSourceID[DUP_TICKET_BUFLEN_IN][31];
};


/*单个结构申明*/
struct DupTicketStruct{

	struct DupTicketStruct *pNext;
	char    sCallType[3];		/* 呼叫类型 */
	char    sMsisdn[13];		/* 用户号码 */
	char    sOtherParty[21];	/* 对端号码 */
	char    sHour[3];		/* 应答时间小时 */
	char    sMiss[5];		/* 应答时间分秒 */
	char    sDuration[7];		/* 通话时长 */
	char    sSourceID[31];		/* 文件来源 */
	
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


/*输出结构缓冲申明*/
struct HourNodeStructOut{

#ifndef HOUR_NODE_BUFLEN_OUT
#define HOUR_NODE_BUFLEN_OUT		300
#endif

	struct HourNodeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 模块 */
	char    asModule[HOUR_NODE_BUFLEN_OUT][4];
		/* 文件日期(小时) */
	char    asDataDate[HOUR_NODE_BUFLEN_OUT][15];
		/* 交叉最小时间 */
	int	aiMinAcrossBeginTime[HOUR_NODE_BUFLEN_OUT];
		/* 交叉最大时间 */
	int	aiMaxAcrossEndTime[HOUR_NODE_BUFLEN_OUT];
		/* 记录数 */
	int     aiRecordCnt[HOUR_NODE_BUFLEN_OUT];
		/* 节点数 */
	int     aiNodeCnt[HOUR_NODE_BUFLEN_OUT];
		/* 读次数 */
	int     aiReadTimes[HOUR_NODE_BUFLEN_OUT];
		/* 写次数 */
	int     aiWriteTimes[HOUR_NODE_BUFLEN_OUT];
		/* 索引重建次数 */
	int     aiRebuildTimes[HOUR_NODE_BUFLEN_OUT];
		/* 处理状态 */
	char    asState[HOUR_NODE_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
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
		/* 模块 */
	char    asModule[HOUR_NODE_BUFLEN_IN][4];
		/* 文件日期(小时) */
	char    asDataDate[HOUR_NODE_BUFLEN_IN][15];
		/* 交叉最小时间 */
	int	aiMinAcrossBeginTime[HOUR_NODE_BUFLEN_IN];
		/* 交叉最大时间 */
	int	aiMaxAcrossEndTime[HOUR_NODE_BUFLEN_IN];
		/* 记录数 */
	int     aiRecordCnt[HOUR_NODE_BUFLEN_IN];
		/* 节点数 */
	int     aiNodeCnt[HOUR_NODE_BUFLEN_IN];
		/* 读次数 */
	int     aiReadTimes[HOUR_NODE_BUFLEN_IN];
		/* 写次数 */
	int     aiWriteTimes[HOUR_NODE_BUFLEN_IN];
		/* 索引重建次数 */
	int     aiRebuildTimes[HOUR_NODE_BUFLEN_IN];
		/* 处理状态 */
	char    asState[HOUR_NODE_BUFLEN_IN][2];
};


/*单个结构申明*/
struct HourNodeStruct{

	struct HourNodeStruct *pNext;
	char    sModule[4];		/* 模块 */
	char    sDataDate[15];		/* 文件日期(小时) */
	int	iMinAcrossBeginTime;		/* 交叉最小时间 */
	int	iMaxAcrossEndTime;		/* 交叉最大时间 */
	int     iRecordCnt;		/* 记录数 */
	int     iNodeCnt;		/* 节点数 */
	int     iReadTimes;		/* 读次数 */
	int     iWriteTimes;		/* 写次数 */
	int     iRebuildTimes;		/* 索引重建次数 */
	char    sState[2];		/* 处理状态 */
	struct HourNodeStruct *pLoadNext;
};

/*输出结构缓冲申明*/
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


/*批量数据动态从HOUR_NODE中用结构缓冲方式取数据*/
int EGetHourNodeToStruct(struct HourNodeStruct *p,
	struct HourNodeStructIn *pSource);
/*批量数据结构缓冲写入HOUR_NODE*/
int EInsertStructToHourNode(struct HourNodeStruct *p,
	int iInsertFlag,struct HourNodeStructOut *pTarget);
void DestroyHourNode(struct HourNodeStruct *ptHead);
int InitHourNode(char sModule[],char sBeginDate[],char sEndDate[],
	struct HourNodeStruct **pptHead);
	
int EUpdateStructToHourNode(struct HourNodeStruct *p,
	int iUpdateFlag,struct HourNodeStructUp *pTarget);


#endif

