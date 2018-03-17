#ifndef __EXPR_VAR_H__
#define __EXPR_VAR_H__

#include <wwcoding.h>

#define MAXFIELDNUM	10000

/*�����ֶ�*/
struct ETicketFieldStruct
{
	struct ETicketFieldStruct *pNext; /*��������ָ��*/
	int	iIndex;
	char	sName[64];	/*�ֶ���*/
	char	cType;/*'1',����,'2',�ַ���*/
	int	iLen; /*�ֶγ���*/
	union {
		int	iValue;
		char	sValue[4096];
		char	*pValue;
		double	dValue;
	} u;				/*��ʽִ��ʱ��д*/
	char	cCur;	/*1�ڵ�ǰ��������0���ڵ�ǰ��������*/
	char	cStd;	/*1�ڵ�ǰ��������0���ڵ�ǰ��������*/
	struct ETicketFieldStruct *pCur; /*��ǰ����ָ��*/
	struct ETicketFieldStruct *pStd;	/*�����������*/
	char	sDefaultValue[4096];	/*Ĭ�ϴ�ֵ,��ʽ����ʱ��д*/
	char	sFormatStr[32];		/*��ʽ��,��ʽ����ʱ��д*/
	struct PositionStruct Pos;
};
/*ͨ�û���*/
struct 	TicketStruct
{
	int	iOriLen;
	char	sOri[4096];
	int	iStdLen;
	char	sStd[4096];
	int	iPos;
	struct ETicketFieldStruct *pCur;	  /*��ǰ����������,��ʽִ��ʱ����*/
	struct ETicketFieldStruct *pStd;	  /*��׼����������,��ʽ����ʱ����*/
	struct ETicketFieldStruct *pAll;	  /*�����ֶε�����,ϵͳ��ʼ���ǽ���*/
	struct ETicketFieldStruct TicketFieldArray[MAXFIELDNUM];
};

int CheckPrepVar(char sVar[],char *pcType);
int AddTicketField(char sVar[],char cType);
void InitTicket();
void ResetTicket();
void ResetTicketStd();
void InsertTicketAll(struct ETicketFieldStruct *p);
void InsertTicketCur(struct ETicketFieldStruct *p);
void InsertTicketStd(struct ETicketFieldStruct *p);
void InsertTicketStdTail(struct ETicketFieldStruct *p);
void GenStdTicket();

void RegPrepVar();

void get_t_integer(int iParam,void *p);
void get_t_string(int iParam,void *p);
void put_t_integer(int iParam,void *p);
void put_t_string(int iParam,void *p);

extern int	iFixFlag,iTailPos;
extern char	FILE_HEAD[4096],FILE_TAIL[4096];
extern struct 	TicketStruct TICKET;
#define TFIELD	TICKET.TicketFieldArray
#ifndef MAXACCTITEMTYPE
#define MAXACCTITEMTYPE	1000000
#endif
int CheckAcctItemVar(char sSymbol[],char *pcType);
void RegAcctItemVar();
int GetAcctItemValue(int *piAcctItemTypeID,int *piCharge,char sState[2]);
void SetAcctItemValue(int iAcctItemTypeID,int iCharge,char sState[2]);
void InitExprIntfVar();


void IGetAcctItemCharge(int iParam,int *piOut);
void GetAcctItemCharge(int iParam,void *p);
void IGetAcctItemState(int iParam,char sState[]);
void GetAcctItemState(int iParam,void *p);
void IPutAcctItemCharge(int iParam,int iValue);
void PutAcctItemCharge(int iParam,void *p);
void IPutAcctItemState(int iParam,char sState[]);
void PutAcctItemState(int iParam,void *p);


#endif

