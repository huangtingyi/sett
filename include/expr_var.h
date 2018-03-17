#ifndef __EXPR_VAR_H__
#define __EXPR_VAR_H__

#include <wwcoding.h>

#define MAXFIELDNUM	10000

/*话单字段*/
struct ETicketFieldStruct
{
	struct ETicketFieldStruct *pNext; /*空闲链表指针*/
	int	iIndex;
	char	sName[64];	/*字段名*/
	char	cType;/*'1',整数,'2',字符串*/
	int	iLen; /*字段长度*/
	union {
		int	iValue;
		char	sValue[4096];
		char	*pValue;
		double	dValue;
	} u;				/*公式执行时填写*/
	char	cCur;	/*1在当前话单链表，0不在当前话单链表*/
	char	cStd;	/*1在当前话单链表，0不在当前话单链表*/
	struct ETicketFieldStruct *pCur; /*当前话单指针*/
	struct ETicketFieldStruct *pStd;	/*输出话单链表*/
	char	sDefaultValue[4096];	/*默认串值,公式编译时填写*/
	char	sFormatStr[32];		/*格式串,公式编译时填写*/
	struct PositionStruct Pos;
};
/*通用话单*/
struct 	TicketStruct
{
	int	iOriLen;
	char	sOri[4096];
	int	iStdLen;
	char	sStd[4096];
	int	iPos;
	struct ETicketFieldStruct *pCur;	  /*当前话单域链表,公式执行时建立*/
	struct ETicketFieldStruct *pStd;	  /*标准话单域链表,公式编译时建立*/
	struct ETicketFieldStruct *pAll;	  /*所有字段的链表,系统初始化是建立*/
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

