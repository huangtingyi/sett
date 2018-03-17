#ifndef __INTF_CMD_H__
#define __INTF_CMD_H__

#include <list.h>

/*单个结构申明*/
struct IntfCmdStruct{

	struct IntfCmdStruct *pNext;
	char    sSerialNbr[41];		/* 工单流水 */
	int     iStaffID;		/* 员工工号 */
	char    sImsi[16];		/* 用户IMSI */
	char    sMsisdn[16];		/* 用户号码 */
	char    sEsn[16];		/* 电子串号 */
	char    sServiceType[7];		/* 工单业务大类 */
	char    sCmdType[21];		/* 标准命令类型 */
	int     iFailTimes;		/* 失败次数 */
	int     iSwitchID;		/* 交换机标识 */
	int     iPriority;		/* 工单优先级 */
	char    sOrderLine[257];		/* 工单行 */
	char    sStdInfoLine[257];		/* 标准信息行 */
	char    sCmdLine[257];		/* 命令行 */
	char    sBackLine[257];		/* 命令回执行 */
	char	sOriBackLine[513];	/*原始交换机回执工单*/
	char    sDealBeginTime[15];		/* 处理开始时间 */
	char    sDealEndTime[15];		/* 处理结束时间 */
	char    sState[4];		/* 工单状态 */
	int	iModify;
	int	iRetCode;		/*返回代码*/
	struct IntfCmdStruct *pLoadNext;
};

/*输出结构缓冲申明*/
struct IntfCmdStructOut{

#ifndef INTF_CMD_BUFLEN_OUT
#define INTF_CMD_BUFLEN_OUT		300
#endif

	struct IntfCmdStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 工单流水 */
	char    asSerialNbr[INTF_CMD_BUFLEN_OUT][41];
		/* 员工工号 */
	int     aiStaffID[INTF_CMD_BUFLEN_OUT];
		/* 用户IMSI */
	char    asImsi[INTF_CMD_BUFLEN_OUT][16];
		/* 用户号码 */
	char    asMsisdn[INTF_CMD_BUFLEN_OUT][16];
		/* 电子串号 */
	char    asEsn[INTF_CMD_BUFLEN_OUT][16];
		/* 工单业务大类 */
	char    asServiceType[INTF_CMD_BUFLEN_OUT][7];
		/* 标准命令类型 */
	char    asCmdType[INTF_CMD_BUFLEN_OUT][21];
		/* 失败次数 */
	int     aiFailTimes[INTF_CMD_BUFLEN_OUT];
		/* 交换机标识 */
	int     aiSwitchID[INTF_CMD_BUFLEN_OUT];
		/* 工单优先级 */
	int     aiPriority[INTF_CMD_BUFLEN_OUT];
		/* 工单行 */
	char    asOrderLine[INTF_CMD_BUFLEN_OUT][257];
		/* 标准信息行 */
	char    asStdInfoLine[INTF_CMD_BUFLEN_OUT][257];
		/* 命令行 */
	char    asCmdLine[INTF_CMD_BUFLEN_OUT][257];
		/* 命令回执行 */
	char    asBackLine[INTF_CMD_BUFLEN_OUT][257];
		/*原始交换机回执工单*/
	char	asOriBackLine[INTF_CMD_BUFLEN_OUT][513];	
		/* 处理开始时间 */
	char    asDealBeginTime[INTF_CMD_BUFLEN_OUT][15];
		/* 处理结束时间 */
	char    asDealEndTime[INTF_CMD_BUFLEN_OUT][15];
		/* 工单状态 */
	char    asState[INTF_CMD_BUFLEN_OUT][4];
};


/* 输入结构缓冲申明*/
struct IntfCmdStructIn{

#ifndef INTF_CMD_BUFLEN_IN
#define INTF_CMD_BUFLEN_IN		300
#endif

	struct IntfCmdStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 工单流水 */
	char    asSerialNbr[INTF_CMD_BUFLEN_IN][41];
		/* 员工工号 */
	int     aiStaffID[INTF_CMD_BUFLEN_IN];
		/* 用户IMSI */
	char    asImsi[INTF_CMD_BUFLEN_IN][16];
		/* 用户号码 */
	char    asMsisdn[INTF_CMD_BUFLEN_IN][16];
		/* 电子串号 */
	char    asEsn[INTF_CMD_BUFLEN_IN][16];
		/* 工单业务大类 */
	char    asServiceType[INTF_CMD_BUFLEN_IN][7];
		/* 标准命令类型 */
	char    asCmdType[INTF_CMD_BUFLEN_IN][21];
		/* 失败次数 */
	int     aiFailTimes[INTF_CMD_BUFLEN_IN];
		/* 交换机标识 */
	int     aiSwitchID[INTF_CMD_BUFLEN_IN];
		/* 工单优先级 */
	int     aiPriority[INTF_CMD_BUFLEN_IN];
		/* 工单行 */
	char    asOrderLine[INTF_CMD_BUFLEN_IN][257];
		/* 标准信息行 */
	char    asStdInfoLine[INTF_CMD_BUFLEN_IN][257];
		/* 命令行 */
	char    asCmdLine[INTF_CMD_BUFLEN_IN][257];
		/* 命令回执行 */
	char    asBackLine[INTF_CMD_BUFLEN_IN][257];
		/*原始交换机回执工单*/
	char    asOriBackLine[INTF_CMD_BUFLEN_IN][513];
		/* 处理开始时间 */
	char    asDealBeginTime[INTF_CMD_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asDealEndTime[INTF_CMD_BUFLEN_IN][15];
		/* 工单状态 */
	char    asState[INTF_CMD_BUFLEN_IN][4];
};
/*单条数据动态SQL向INTF_CMD写数据*/
int SDInsertStructToIntfCmd(struct IntfCmdStruct *p,char sTableName[]);
int EGetIntfCmdToStruct(struct IntfCmdStruct *p,
	struct IntfCmdStructIn *pSource);
int EInsertStructToIntfCmd(struct IntfCmdStruct *p,
	int iInsertFlag,struct IntfCmdStructOut *pTarget);
	
int InitIntfCmd(struct IntfCmdStruct **pptHead,char sCondition[256]);

struct IIntfCmdStruct
{
	POINTER ioffNext;		/*链表指针*/
	POINTER icmdNext;		/*链表指针,同一工单联表*/
	char    sSerialNbr[41];		/* 工单流水 */
	int     iStaffID;		/* 员工工号 */
	char    sImsi[16];		/* 用户IMSI */
	char    sMsisdn[16];		/* 用户号码 */
	char    sEsn[16];		/* 电子串号 */
	char    sServiceType[7];	/* 工单业务大类 */
	char    sCmdType[21];		/* 标准命令类型 */
	int     iFailTimes;		/* 失败次数 */
	int     iSwitchID;		/* 交换机标识 */
	int     iPriority;		/* 工单优先级 */
	char    sOrderLine[257];	/* 工单行 */
	char    sStdInfoLine[257];	/* 标准信息行 */
	char    sCmdLine[257];	/* 命令行 */
	char    sBackLine[257];		/* 命令回执行 */
	char    sOriBackLine[513];		/* 命令回执行 */
	char    sDealBeginTime[15];	/* 处理开始时间 */
	char    sDealEndTime[15];	/* 处理结束时间 */
	char    sState[4];		/* 工单状态 */
	int	iModify;
	int	iRetCode;		/*返回代码*/
};
/*输出结构缓冲申明*/
struct IntfCmdStructUp{

#ifndef INTF_CMD_BUFLEN_UP
#define INTF_CMD_BUFLEN_UP		300
#endif

	struct IntfCmdStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 工单流水 */
	char    asSerialNbr[INTF_CMD_BUFLEN_UP][41];
		/* 失败次数 */
	int     aiFailTimes[INTF_CMD_BUFLEN_UP];
		/* 交换机标识 */
	int     aiSwitchID[INTF_CMD_BUFLEN_UP];
		/* 命令行 */
	char    asCmdLine[INTF_CMD_BUFLEN_UP][257];
		/* 命令回执行 */
	char    asBackLine[INTF_CMD_BUFLEN_UP][257];
		/* 命令回执行 */
	char    asOriBackLine[INTF_CMD_BUFLEN_UP][513];
		/* 处理开始时间 */
	char    asDealBeginTime[INTF_CMD_BUFLEN_UP][15];
		/* 处理结束时间 */
	char    asDealEndTime[INTF_CMD_BUFLEN_UP][15];
		/* 工单状态 */
	char    asState[INTF_CMD_BUFLEN_UP][4];
};
void mvitem_intf2i(struct IntfCmdStruct *pi,struct IIntfCmdStruct *po);
void mvitem_intf2m(struct IIntfCmdStruct *pi,struct IntfCmdStruct *po);
int EUpdateStructToUIntfCmd(struct IntfCmdStruct *p,
	int iUpdateFlag,struct IntfCmdStructUp *pTarget);

#define	COMMAND_STATE_NEW	"I0N"	/*待处理*/
#define	COMMAND_STATE_IN	"I0I"	/*已经加到共享内存中*/
#define	COMMAND_STATE_WAIT	"I0W"	/*等待指令返回*/
#define	COMMAND_STATE_ERR	"I0E"	/*指令返回失败*/
#define	COMMAND_STATE_SUC	"I0S"	/*指令返回成功 */
#define	COMMAND_STATE_FAIL	"I0F"	/*指令分析失败*/
#define	COMMAND_STATE_MUTEX	"I0M"	/*指令被排斥*/
#define	COMMAND_STATE_HIS	"I0H"	/*指令已返回营帐，待归档*/

#define	MSC_REQ_CMD		"11"	/*交换机请求命令*/
#define	SYS_REQ_CMD		"12"	/*联机指令系统请求命令*/
#define MSC_ACK_CMD		"21"	/*交换机应答转换命令*/
#define	SYS_ACK_CMD		"22" 	/*系统应答转换命令*/

#endif

