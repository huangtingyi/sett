#ifndef	__TABLE_FIELD_H__
#define __TABLE_FIELD_H__

#include <param_intf.h>
#include <stt_ticket.h>
#include <wwfile.h>
#include "wwsupp.h"
#include "extend_supp.h"
#include "extend_intf.h"

struct TableFieldRegStruct
{
	struct TableFieldRegStruct *pNext;
	char	sGetValueFun[61];
	void	*(*GetTableField)();
};
struct SplitRuleStruct *GetTableSplitRuleList(int iTemplateRuleID,char sSplitType[]);
int newMatchTableFieldRule_t(struct TableFieldRuleStruct *ptHead);
struct SplitRuleStruct *GetTableSplitRule(struct SplitRuleStruct *pTemp);

#define MAXSPLITRULEID	10000
extern struct TableFieldRuleStruct *apSplitRule[MAXSPLITRULEID];
#define PSPLITRULE(x)	(apSplitRule[x])

int GetExtendAttrValue(char sAttrValue[],int iAttrID,int iExtendSeq,
	char sExtendAttrValue[]);

int InitialTableFieldRule(struct TableFieldRuleStruct *pTemp);
int GetTableFieldIndex(char sFieldName[]);

struct TableFileControlOutStruct
{
	struct TableFileControlOutStruct *pNext;
	int  iCnt;
	char sSuffix[2];
	struct FileControlStruct *pHead;
};
struct	TableFileControlListStruct
{
	struct	TableFileControlListStruct *pNext;		
	int	iTemplateRuleID;
	char	sSplitType[2];			/*分离类型*/
	struct  SplitRuleStruct *pSplitRule;	/*分离规则*/
	int	iCnt;
	struct	TableFileControlOutStruct	*pHead;	/*输出话单*/
	char	sDealBeginDate[15];
	char	sDealEndDate[15];
};

#define FIELD_TYPE_DURATION	"0"
#define FIELD_TYPE_FLOW1	"1"
#define FIELD_TYPE_FLOW2	"2"

int InitTableFiledColumns(struct TableFileControlListStruct *ptHead);

struct TableFileControlListStruct *GetFileControlList_t(
	struct TableFileControlListStruct *ptHead, char sSplitType[2]);
int InitTableFileControlList(int iTemplateRuleID,char sSplitStr[],
	struct TableFileControlListStruct **pptHead);

struct SplitRuleStruct *GetNewSplitRule(struct SplitRuleStruct *ptHead);
struct SplitRuleStruct *GetMultiNewSplitRule(struct TableFileControlListStruct *ptHead);

void DestroyTableFileControlList(struct TableFileControlListStruct *ptHead);

struct SimpleItemStruct{
	
	struct SimpleItemStruct *pNext;
	int	iFeeFieldID;
	int	iMeasureFieldID;
	int	iAcctItemTypeID;
	int	iDetailItemTypeID;
	int	iValue;
	double	dBillFee;		/*营账批价费用*/
	double	dTicketAuditFee;	/*话单级规则审计费用*/
	double	dAcctAuditFee;		/*账单级规则审计费用*/
	double	dAuditFee;		/*审核结果*/
	char	cDuraFlag;		/*1,标识iValue是时长,0表示非时长*/
	char	cTicketAuditFlag;	/*话单级审计标志,0未审核，1已审核,2审核失败*/
	char	cAcctAuditFlag;		/*账单稽审计标志,0未审核，1已审核,2审核失败*/
	char	cAuditFlag;		/*稽核标志*/
	char	sRealBillingTypeID[11];/*实际算费套餐ID*/	
	int	iTicketTariffID;
	int	iAcctTariffID;		
	int	iTariffID;		/*适用资费*/

};

struct SimpleTicketStruct{
	
	struct SimpleTicketStruct *pNext;

	char	sAreaCode[9];
	char 	sMsisdn[21];
	char	sOtherParty[21];
	char	sStartTime[15];	/*起始时间或生效时间*/
	char	sEndTime[15];	/*结束时间或失效时间*/
	int	iDuration;	/*通话时长*/
	char	cBillFlag;	
/*批价类型,只有特定话单才有此类型,0为正常批价，1为特殊批价，其它待定*/
	char	cJoinDateFlag;/*入网标识*/
	char	sSourceID[41];
	char	sRowID[19];
	
	char	sBillingTypeID[26];	/*存放该条话单的套餐ID*/
	
	int	iLen;
	void	*pData;		/*话单原始数据*/
	
	double 	dAllFee;	/*测试时候用，为各个费用的总和*/
	char  	cFlag;		/*状态标识*/
	struct SimpleItemStruct *pAuditList;	/*话单账目、审计账目项*/
	
	struct SimpleTicketStruct *pLoadNext;
};

int LikeComp(char sAttrValue[],char CompKey[]);

int IsTabColUseInSplitRuleList(struct TabColumnsStruct *pCol,int iFormatID,
	struct SplitRuleStruct *pList);
int IsTabColUseInCtrlList(struct TabColumnsStruct *pCol,int iFormatID,
	struct TableFileControlListStruct *pList);

int SearchTableFieldByFormatColumnName(int iFormatID,char sColumnName[],
	struct TableFieldStruct **pptCur);
int GetFieldIDByFormatColumnName(int iFormatID,char sColumnName[]);

struct TabColumnsStruct* GetTabColumnsAndInit(int iTemplateID,int iFormatID,
	struct TableFileControlListStruct *pList);

void GetColumnStrVal(struct TabColumnsStruct * p,char sOriLine[],
	char sAttrValue[]);
void GetColumnStrValFromList(char sColumnName[],struct TabColumnsStruct *pMyTab,
	char sOriLine[],char sValue[]);


/************************************************************

以上为清单稽核部分

**************************************************************/
#define	BILL_ACCT_MORE		0
#define BILL_ACCT_AUDIT_SAME	1
#define BILL_ACCT_AUDIT_SAME1	11
#define BILL_ACCT_AUDIT_DIFF	2
#define AUDIT_ACCT_MORE		3
#define AUDIT_NOT		4
#define BILL_ACCT_ERROR 	-100
#define	AUDIT_CFG_NOTFULL	5
#define	BILL_CFG_NOTFULL	6
#define AUDIT_ACCT_NEW		7
#define AUDIT_ACCT_NEW_OLD	8

/*无法稽核明细*/
#define AUDIT_NOT_SUB_BILL	-10	/*子套餐未配置*/
#define AUDIT_NOT_MAIN_BILL	-11	/*主套餐未配置*/
#define AUDIT_NOT_T		-12	/*未配置清单稽核规则*/
#define AUDIT_NOT_M		-13	/*未配置清单稽核规则或账目规则*/
#define AUDIT_NOT_D		-14	/*未配置账务规则*/
/*明细标识*/
#define AUDIT_FEE_EQUAL		0
#define AUDIT_FEE_LARGE		1
#define AUDIT_FEE_SMALL		-1

#define TYPE_CDR_ORI_TYPE	1
#define TYPE_RENT_TYPE		4
#define TYPE_NBR_DISCT_TYPE	2
#define TYPE_ACCT_DISCT_TYPE	3

struct SimpleAcctItemStruct
{
	struct SimpleAcctItemStruct *pNext;
	char	sMsisdn[21];	/*考虑字节对齐,用24位*/
	char	iFlag;
/*
账务优惠时：0，非当前账目,1当前条件类型的账目
账单比对时BillAcct表：
	    10,账务系统多出账单;
	    1,费用一致账单;
	    2,费用差异账单;	这时iFee字段填写AuditFee-iFee字段.
	    3,稽核系统多出账单.
*/
	char	iDetailFlag;	/*非归并账目差异状态*/
/**
	 0,费用一致账单
	 1,稽核系统费用大于账务系统
	 -1,账务系统费用大于稽核系统
	 
**/
	char	iNAuditFlag;	/*无法稽核明细*/
	char	sBillingTypeID[11];/*套餐ID*/
	char	iType;
/****
1	来自于清单的输入账目
2	用户级优惠输出账目
3	账户级优惠输出账目
****/
	char	sAcctType[2];	/*账目类型'T':为清单级账单，'M':为账目级账单*/
	char	sState[2];	/*账目状态,'0':正常,'1'免费*/
	char	sAreaCode[10];	/*用户归属区号*/
	int	iAcctItemTypeID;
	int	iAuditItemTypeID;/* 稽核账目ID */
	int	iAcctID;	/*账目ID*/
	int	iDefaultAcctID;	/*账目ID*/
	
	int	iFee;		/*单位为厘*/
	int	iOppFee;	/*另一方费用*/
	int	iTariffID;	/*设计冗余字段，用于保存适用的账目优惠TARIFFID*/
	
	struct SimpleAcctItemStruct *pServList;	/*用户级账单列表*/
	
	char	sSourceID[41];
	char	sRowID[19];
	struct SimpleAcctItemStruct *pLoadNext;
};

/*存放的是账目优惠中*/
extern struct SimpleAcctItemStruct *gServItemList;
extern BINTREE *gAcctIDCodeRoot;

void SetTableFieldSetAuditTime(char sAuditTime[]);
void SetSimpleAcctItemAndMsisdn(struct SimpleAcctItemStruct *p);
void SetSimpleAcctItemAndAcctID(struct SimpleAcctItemStruct *p);
void RegAuditAcctExprFun();

int GetAcctItemSummaryValue(int *piAcctItemTypeID,int *piCharge,char sState[2]);
void SetAcctItemSummaryValue(int iAcctItemTypeID,int iCharge,char sState[2]);
int GetComplexSummaryCharge(char sComplexsCode[]);
void GetComplexSummaryName(char sComplexsCode[],char sSummaryName[]);

struct TabColumnsStruct* GetAllTabColumnsList(int iTemplateID);
void InitAllTabColumnsForSplit(struct TabColumnsStruct *ptLkHead,
	int iFormatID,struct TableFileControlListStruct *pList);
void InsertSplitRuleLoadNextHead(struct SplitRuleStruct **pptHead,
	struct SplitRuleStruct *pValue);
/*从自定义表获取扩展属性数值*/
int GetDefExtendAttrValue(char sAttrValue[],int iExtendAttrID,char sValue[]);

/*从链表中得到CODE的账户级账目总和*/
int GetAcctIDCodeBalance(int iAcctID,char sCode[]);
/*从链表中得到CODE的用户级账目总和*/
int GetAccNbrSumBalance(char sAccNbr[],char sCode[]);
/*获取一个指定账目的费用*/
int GetAcctItemTypeIDCharge(int iAcctItemTypeID);

#endif

