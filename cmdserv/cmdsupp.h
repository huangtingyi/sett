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
	char	sHeadIdentify[3];	/*�̶�Ϊ"MHF"*/
	char	sVersion[5];		/*�̶�Ϊ"00001"*/
	char	sOppSysCode[8];		/*�̶�Ϊ"        "*/
	char	sMySysCode[8];		/*�̶�Ϊ"        "*/
	char	sRequestTime[14];
	char	sSerialNbr[16];
	char	sPriority[2];
	char	sFileFlag[1];		/*��Ϣ��0,�ļ�Ϊ1*/
	char	sCmdType[6];		
	char	sBodyLen[6];
};
struct	CdmaCmdTailStruct
{
	char	sTailIdentify[3];	/*�̶�Ϊ"MNF"*/
	char	cReturn;		/*�̶�Ϊ"\n"*/
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
	POINTER ioffNext;	/*����ָ��*/
	char	sIp[16];	/*��ִ�˿�*/
	int	iPork;		/*���ظ�Ӫ�ʵĶ˿�*/
	int	iHeartByte;	/*0,SERVER֪ͨ������Ӧ��1 CLIENT��Ӧ,*/
	pid_t	pid;		/*������̱�ʶ*/
};
struct IAgentStruct
{
	POINTER ioffNext;	/*����ָ��*/
	int	iIndex;
	int	iSwitchID;
	int	iCmdBufLen;
	char	sUserName[64];
	char	sPassword[64];	
	char	sAreaCode[6];
	char	sIp[16];	/*����Ŀ��IP*/
	int	iPort;		/*����Ŀ��˿�*/
	int	iLock;		/*0������1��*/
	int	iHeartByte;	/*0,SERVER֪ͨ������Ӧ��1 CLIENT��Ӧ,*/
	pid_t	pid;		/*������̱�ʶ*/
	int	iCmdCnt;	/*�������*/

	POINTER	ioffWaitCmd;	/*�ȴ���ִ����*/
	POINTER	ioffCmd;	/*��������*/
	
	POINTER icurCmd;	/*��ǰ�����������*/

};
/*�����ڴ�Ŀ��ƽṹ*/
struct MemCmdStruct
{
	int	iTotalLen;	/*SHM��ǰ��С*/
	int	iCmdBufLen;
	int	iAdaptBufLen;	/*���Adapt����*/
	int	iAgentBufLen;	/*���������,<=20*/
};

int InitCmdTab();
int DestroyCmdTab();
int GetReserveAgentCnt();
int GetAgentCmdBuf();
int GetMaxAdaptCnt();
int GetCmdShmKey();
int CalcNeedCmdShm(struct MemCmdStruct *ptHead);
/*��һ�ν����ṹ����ʼ��pMem��pShm����pMem�ṹ��Ա*/
int InitialCmdMemShm(struct MemCmdStruct *pMem);
/*��pSwitch��ʼ��pIAgent,����pAgent��Ӧ��Cmd�����ʼ��*/
void InitialAgentItem(struct SwitchStruct *ptHead,
	struct IAgentStruct  *pItem);
int ConnectCmdShmAndInitMem();
int BuildCmdShmInit();
int SwitchInShm(struct SwitchStruct *ptHead);
int IncreaseCmdShmInit();

int AdaptNotifyCmdServer(int iMsg);
int GetAdaptNotify();

/*�¼�����,CMDSERVER��Ӧ,��Ϣ��SIGUSR1*/
#define	ADAPT_DATA_REACH	1	/*Ӫ�����ݵ���*/
#define AGENT_HLR_RESPOND	1	/*���������ݵ���*/

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

/*ȫ�ֱ�����ʼ*/
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
	int	iLock;		/*0������1��*/
	int	iHeartBeat;	/*����*/
	int	iCmdAdaptEvent;	/*Adapt�¼�*/
	POINTER ioffFree;	/*��������*/
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

#define RT_SUC		0	/*����ָ��ִ�гɹ�   */
#define RT_CREATE_ERR	1	/*��ͨ���ô�         */
#define RT_TIMEOUT	2	/*����ָ�ʱ��     */
#define RT_MDN_EXIST	3	/*MDN���Ѵ���        */
#define RT_IMSI_EXIST	4	/*IMSI���Ѵ���       */
#define RT_MDN_NOTFOUND	5	/*MDN��δ�ҵ�        */
#define RT_IMSI_NOTFOUND	6	/*IMSI��δ�ҵ�       */
#define RT_PIC_EXIST	7	/*PIC���Ѵ���        */
#define RT_PIC_NOTFOUND	8	/*PIC��δ�ҵ�        */
#define RT_ESN_EXIST	9	/*ESN���Ѵ���        */
#define RT_ESN_NOTFOUND	10	/*ESNδ�ҵ�          */
#define RT_OTHER_ERR	100	/*�������ʹ���       */

#endif

