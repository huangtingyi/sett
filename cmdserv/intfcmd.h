#ifndef __INTF_CMD_H__
#define __INTF_CMD_H__

#include <list.h>

/*�����ṹ����*/
struct IntfCmdStruct{

	struct IntfCmdStruct *pNext;
	char    sSerialNbr[41];		/* ������ˮ */
	int     iStaffID;		/* Ա������ */
	char    sImsi[16];		/* �û�IMSI */
	char    sMsisdn[16];		/* �û����� */
	char    sEsn[16];		/* ���Ӵ��� */
	char    sServiceType[7];		/* ����ҵ����� */
	char    sCmdType[21];		/* ��׼�������� */
	int     iFailTimes;		/* ʧ�ܴ��� */
	int     iSwitchID;		/* ��������ʶ */
	int     iPriority;		/* �������ȼ� */
	char    sOrderLine[257];		/* ������ */
	char    sStdInfoLine[257];		/* ��׼��Ϣ�� */
	char    sCmdLine[257];		/* ������ */
	char    sBackLine[257];		/* �����ִ�� */
	char	sOriBackLine[513];	/*ԭʼ��������ִ����*/
	char    sDealBeginTime[15];		/* ����ʼʱ�� */
	char    sDealEndTime[15];		/* �������ʱ�� */
	char    sState[4];		/* ����״̬ */
	int	iModify;
	int	iRetCode;		/*���ش���*/
	struct IntfCmdStruct *pLoadNext;
};

/*����ṹ��������*/
struct IntfCmdStructOut{

#ifndef INTF_CMD_BUFLEN_OUT
#define INTF_CMD_BUFLEN_OUT		300
#endif

	struct IntfCmdStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������ˮ */
	char    asSerialNbr[INTF_CMD_BUFLEN_OUT][41];
		/* Ա������ */
	int     aiStaffID[INTF_CMD_BUFLEN_OUT];
		/* �û�IMSI */
	char    asImsi[INTF_CMD_BUFLEN_OUT][16];
		/* �û����� */
	char    asMsisdn[INTF_CMD_BUFLEN_OUT][16];
		/* ���Ӵ��� */
	char    asEsn[INTF_CMD_BUFLEN_OUT][16];
		/* ����ҵ����� */
	char    asServiceType[INTF_CMD_BUFLEN_OUT][7];
		/* ��׼�������� */
	char    asCmdType[INTF_CMD_BUFLEN_OUT][21];
		/* ʧ�ܴ��� */
	int     aiFailTimes[INTF_CMD_BUFLEN_OUT];
		/* ��������ʶ */
	int     aiSwitchID[INTF_CMD_BUFLEN_OUT];
		/* �������ȼ� */
	int     aiPriority[INTF_CMD_BUFLEN_OUT];
		/* ������ */
	char    asOrderLine[INTF_CMD_BUFLEN_OUT][257];
		/* ��׼��Ϣ�� */
	char    asStdInfoLine[INTF_CMD_BUFLEN_OUT][257];
		/* ������ */
	char    asCmdLine[INTF_CMD_BUFLEN_OUT][257];
		/* �����ִ�� */
	char    asBackLine[INTF_CMD_BUFLEN_OUT][257];
		/*ԭʼ��������ִ����*/
	char	asOriBackLine[INTF_CMD_BUFLEN_OUT][513];	
		/* ����ʼʱ�� */
	char    asDealBeginTime[INTF_CMD_BUFLEN_OUT][15];
		/* �������ʱ�� */
	char    asDealEndTime[INTF_CMD_BUFLEN_OUT][15];
		/* ����״̬ */
	char    asState[INTF_CMD_BUFLEN_OUT][4];
};


/* ����ṹ��������*/
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
		/* ������ˮ */
	char    asSerialNbr[INTF_CMD_BUFLEN_IN][41];
		/* Ա������ */
	int     aiStaffID[INTF_CMD_BUFLEN_IN];
		/* �û�IMSI */
	char    asImsi[INTF_CMD_BUFLEN_IN][16];
		/* �û����� */
	char    asMsisdn[INTF_CMD_BUFLEN_IN][16];
		/* ���Ӵ��� */
	char    asEsn[INTF_CMD_BUFLEN_IN][16];
		/* ����ҵ����� */
	char    asServiceType[INTF_CMD_BUFLEN_IN][7];
		/* ��׼�������� */
	char    asCmdType[INTF_CMD_BUFLEN_IN][21];
		/* ʧ�ܴ��� */
	int     aiFailTimes[INTF_CMD_BUFLEN_IN];
		/* ��������ʶ */
	int     aiSwitchID[INTF_CMD_BUFLEN_IN];
		/* �������ȼ� */
	int     aiPriority[INTF_CMD_BUFLEN_IN];
		/* ������ */
	char    asOrderLine[INTF_CMD_BUFLEN_IN][257];
		/* ��׼��Ϣ�� */
	char    asStdInfoLine[INTF_CMD_BUFLEN_IN][257];
		/* ������ */
	char    asCmdLine[INTF_CMD_BUFLEN_IN][257];
		/* �����ִ�� */
	char    asBackLine[INTF_CMD_BUFLEN_IN][257];
		/*ԭʼ��������ִ����*/
	char    asOriBackLine[INTF_CMD_BUFLEN_IN][513];
		/* ����ʼʱ�� */
	char    asDealBeginTime[INTF_CMD_BUFLEN_IN][15];
		/* �������ʱ�� */
	char    asDealEndTime[INTF_CMD_BUFLEN_IN][15];
		/* ����״̬ */
	char    asState[INTF_CMD_BUFLEN_IN][4];
};
/*�������ݶ�̬SQL��INTF_CMDд����*/
int SDInsertStructToIntfCmd(struct IntfCmdStruct *p,char sTableName[]);
int EGetIntfCmdToStruct(struct IntfCmdStruct *p,
	struct IntfCmdStructIn *pSource);
int EInsertStructToIntfCmd(struct IntfCmdStruct *p,
	int iInsertFlag,struct IntfCmdStructOut *pTarget);
	
int InitIntfCmd(struct IntfCmdStruct **pptHead,char sCondition[256]);

struct IIntfCmdStruct
{
	POINTER ioffNext;		/*����ָ��*/
	POINTER icmdNext;		/*����ָ��,ͬһ��������*/
	char    sSerialNbr[41];		/* ������ˮ */
	int     iStaffID;		/* Ա������ */
	char    sImsi[16];		/* �û�IMSI */
	char    sMsisdn[16];		/* �û����� */
	char    sEsn[16];		/* ���Ӵ��� */
	char    sServiceType[7];	/* ����ҵ����� */
	char    sCmdType[21];		/* ��׼�������� */
	int     iFailTimes;		/* ʧ�ܴ��� */
	int     iSwitchID;		/* ��������ʶ */
	int     iPriority;		/* �������ȼ� */
	char    sOrderLine[257];	/* ������ */
	char    sStdInfoLine[257];	/* ��׼��Ϣ�� */
	char    sCmdLine[257];	/* ������ */
	char    sBackLine[257];		/* �����ִ�� */
	char    sOriBackLine[513];		/* �����ִ�� */
	char    sDealBeginTime[15];	/* ����ʼʱ�� */
	char    sDealEndTime[15];	/* �������ʱ�� */
	char    sState[4];		/* ����״̬ */
	int	iModify;
	int	iRetCode;		/*���ش���*/
};
/*����ṹ��������*/
struct IntfCmdStructUp{

#ifndef INTF_CMD_BUFLEN_UP
#define INTF_CMD_BUFLEN_UP		300
#endif

	struct IntfCmdStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������ˮ */
	char    asSerialNbr[INTF_CMD_BUFLEN_UP][41];
		/* ʧ�ܴ��� */
	int     aiFailTimes[INTF_CMD_BUFLEN_UP];
		/* ��������ʶ */
	int     aiSwitchID[INTF_CMD_BUFLEN_UP];
		/* ������ */
	char    asCmdLine[INTF_CMD_BUFLEN_UP][257];
		/* �����ִ�� */
	char    asBackLine[INTF_CMD_BUFLEN_UP][257];
		/* �����ִ�� */
	char    asOriBackLine[INTF_CMD_BUFLEN_UP][513];
		/* ����ʼʱ�� */
	char    asDealBeginTime[INTF_CMD_BUFLEN_UP][15];
		/* �������ʱ�� */
	char    asDealEndTime[INTF_CMD_BUFLEN_UP][15];
		/* ����״̬ */
	char    asState[INTF_CMD_BUFLEN_UP][4];
};
void mvitem_intf2i(struct IntfCmdStruct *pi,struct IIntfCmdStruct *po);
void mvitem_intf2m(struct IIntfCmdStruct *pi,struct IntfCmdStruct *po);
int EUpdateStructToUIntfCmd(struct IntfCmdStruct *p,
	int iUpdateFlag,struct IntfCmdStructUp *pTarget);

#define	COMMAND_STATE_NEW	"I0N"	/*������*/
#define	COMMAND_STATE_IN	"I0I"	/*�Ѿ��ӵ������ڴ���*/
#define	COMMAND_STATE_WAIT	"I0W"	/*�ȴ�ָ���*/
#define	COMMAND_STATE_ERR	"I0E"	/*ָ���ʧ��*/
#define	COMMAND_STATE_SUC	"I0S"	/*ָ��سɹ� */
#define	COMMAND_STATE_FAIL	"I0F"	/*ָ�����ʧ��*/
#define	COMMAND_STATE_MUTEX	"I0M"	/*ָ��ų�*/
#define	COMMAND_STATE_HIS	"I0H"	/*ָ���ѷ���Ӫ�ʣ����鵵*/

#define	MSC_REQ_CMD		"11"	/*��������������*/
#define	SYS_REQ_CMD		"12"	/*����ָ��ϵͳ��������*/
#define MSC_ACK_CMD		"21"	/*������Ӧ��ת������*/
#define	SYS_ACK_CMD		"22" 	/*ϵͳӦ��ת������*/

#endif

