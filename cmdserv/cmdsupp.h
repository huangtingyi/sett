#ifndef __CMD_SUPP_H__
#define __CMD_SUPP_H__

#include <wwshm.h>
#include <list.h>
#include <gen_supp.h>
#include <intfcmd.h>

struct InfoItemStruct
{
	struct InfoItemStruct *pNext;
	char	sName[61];
	char	sValue[61];
};
struct	CdmaCmdHeadStruct
{
	char	sHeadIdentify[3];	/*固定为"MHF"*/
	char	sVersion[5];		/*固定为"00001"*/
	char	sOppSysCode[8];		/*固定为"        "*/
	char	sMySysCode[8];		/*固定为"        "*/
	char	sRequestTime[14];
	char	sSerialNbr[16];
	char	sPriority[2];
	char	sFileFlag[1];		/*消息包0,文件为1*/
	char	sCmdType[6];		
	char	sBodyLen[6];
};
struct	CdmaCmdTailStruct
{
	char	sTailIdentify[3];	/*固定为"MNF"*/
	char	cReturn;		/*固定为"\n"*/
};


int CheckPack(char sInput[],int l,char sErrMsg[]);
struct InfoItemStruct *GenInfoItemList(char sInfoLine[],
	char cSepItem,char cSepVal);
void GenInfoLine(struct InfoItemStruct *ptHead,char cSepItem,char cSepVal,
	char sInfoLine[256]);
void GetInfoItemValue(struct InfoItemStruct *ptHead,char sName[],
	char sValue[]);

struct IAdaptStruct
{
	POINTER ioffNext;	/*链表指针*/
	char	sIp[16];	/*回执端口*/
	int	iPork;		/*返回给营帐的端口*/
	int	iHeartByte;	/*0,SERVER通知命令响应，1 CLIENT响应,*/
	pid_t	pid;		/*代理进程标识*/
};
struct IAgentStruct
{
	POINTER ioffNext;	/*链表指针*/
	int	iIndex;
	int	iSwitchID;
	int	iCmdBufLen;
	char	sUserName[64];
	char	sPassword[64];	
	char	sAreaCode[6];
	char	sIp[16];	/*命令目标IP*/
	int	iPort;		/*命令目标端口*/
	int	iLock;		/*0无锁，1锁*/
	int	iHeartByte;	/*0,SERVER通知命令响应，1 CLIENT响应,*/
	pid_t	pid;		/*代理进程标识*/
	int	iCmdCnt;	/*命令个数*/

	POINTER	ioffWaitCmd;	/*等待回执链表*/
	POINTER	ioffCmd;	/*缓冲链表*/
	
	POINTER icurCmd;	/*当前处理完毕命令*/

};
/*本地内存的控制结构*/
struct MemCmdStruct
{
	int	iTotalLen;	/*SHM当前大小*/
	int	iCmdBufLen;
	int	iAdaptBufLen;	/*最大Adapt个数*/
	int	iAgentBufLen;	/*最大代理个数,<=20*/
};

int InitCmdTab();
int DestroyCmdTab();
int GetReserveAgentCnt();
int GetAgentCmdBuf();
int GetMaxAdaptCnt();
int GetCmdShmKey();
int CalcNeedCmdShm(struct MemCmdStruct *ptHead);
/*第一次建立结构，初始化pMem和pShm，用pMem结构成员*/
int InitialCmdMemShm(struct MemCmdStruct *pMem);
/*用pSwitch初始化pIAgent,并将pAgent对应的Cmd链表初始化*/
void InitialAgentItem(struct SwitchStruct *ptHead,
	struct IAgentStruct  *pItem);
int ConnectCmdShmAndInitMem();
int BuildCmdShmInit();
int SwitchInShm(struct SwitchStruct *ptHead);
int IncreaseCmdShmInit();

int AdaptNotifyCmdServer(int iMsg);
int GetAdaptNotify();

/*事件定义,CMDSERVER响应,消息在SIGUSR1*/
#define	ADAPT_DATA_REACH	1	/*营帐数据到来*/
#define AGENT_HLR_RESPOND	1	/*交换机数据到来*/

struct SwitchStatStruct
{
	struct SwitchStatStruct *pNext;
	struct IntfCmdStruct *pHead;
	int iSwitchID;
	int iFreeCmdCnt;
};
void LockCmdShm();
void UnlockCmdShm();

struct SwitchStatStruct *GetSwitchStatList();

void HeartBeatServer();
int IsCmdServRun();
void LockAgent(struct IAgentStruct *pAgent);
void UnlockAgent(struct IAgentStruct *pAgent);

/*全局变量开始*/
struct CmdLineStruct
{
	char	sCmdType[2];
	char	cLR1;
	char	sCmdPosInfo[10];
	char	cLR2;
};
#define CMDSTATE_SUC 'S'
#define CMDSTATE_ERR 'E'

int SearchShmCmd(char sSerialNbr[],POINTER ioffHead,POINTER *pioffCur);
void ResetRecvBufAndResult();
void AnalizeCmdResult();
int  ProcCmdEnd();
int  ProcFailureCmd(char sMsg[]);
int GetCmdLen(struct IIntfCmdStruct *pCmd,int iCurPos);
int GetCmdCnt(struct IIntfCmdStruct *pCmd);
void GetCmdType(struct IIntfCmdStruct *pCmd,
	char sCmdType[]);
void GetCmd(struct IIntfCmdStruct *pCmd,int iCurCnt,
	char sCmd[]);
void GetShmCmdSend(int iSockFd);
int SearchShmAgent(int iSwitchID,POINTER ioffHead,POINTER *pioffCur);
struct IAgentStruct *GetShmAgent(int iSwitchID);

struct CmdResultStruct
{
	int iCmdCnt;
	int iCurCmd;
	int	aiCmdRetCode[20];
	char	sCmdState[20];
	char	asCmdMsg[20][256];
	char	sRecvBuf[8192];
};
struct ShmCmdHead
{
	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];

	struct ShmCtrlStruct Adapt;
	struct ShmCtrlStruct Agent;
	struct ShmCtrlStruct IntfCmd;

	POINTER ioffAdapt;
	POINTER ioffAgent;

	int	iCmdBufLen;
	int	iLock;		/*0无锁，1锁*/
	int	iHeartBeat;	/*心跳*/
	int	iCmdAdaptEvent;	/*Adapt事件*/
	POINTER ioffFree;	/*空闲区域*/
};
extern struct CmdResultStruct CmdResult;
extern struct IIntfCmdStruct Intf;
extern struct ShmCmdHead *PSHMCMD;

#define INSERT_SHMCMD_LIST(h,v) InsertEList((void*)PSHMCMD,h,v)
#define INSERT_SHMCMD_LIST_TAIL(h,v) InsertEListTail((void*)PSHMCMD,h,v)
#define DELETE_SHMCMD_LIST(h,v) DeleteEList((void*)PSHMCMD,h,v)
#define OPSHMCMD(o)		((char*)PSHMCMD+(o))
#define OONXTSHMCMD(o) 		OOELISTNXT((void*)PSHMCMD,o)


int  AnswerCdmaMsg(int iSockFd,char sCmd[],char sCmdType[],
	char sMsg[],int iFlag);
int  AnswerCdmaIntf(int iSockFd,char sCmd[],char sCmdType[],
	char sReturn[]);
#define CDMA_BACK_BUF	64*1024

#define RT_SUC		0	/*联机指令执行成功   */
#define RT_CREATE_ERR	1	/*开通配置错         */
#define RT_TIMEOUT	2	/*联机指令超时错     */
#define RT_MDN_EXIST	3	/*MDN号已存在        */
#define RT_IMSI_EXIST	4	/*IMSI号已存在       */
#define RT_MDN_NOTFOUND	5	/*MDN号未找到        */
#define RT_IMSI_NOTFOUND	6	/*IMSI号未找到       */
#define RT_PIC_EXIST	7	/*PIC号已存在        */
#define RT_PIC_NOTFOUND	8	/*PIC号未找到        */
#define RT_ESN_EXIST	9	/*ESN号已存在        */
#define RT_ESN_NOTFOUND	10	/*ESN未找到          */
#define RT_OTHER_ERR	100	/*其他类型错误       */

#endif

