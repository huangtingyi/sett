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
	char	sSplitType[2];			/*��������*/
	struct  SplitRuleStruct *pSplitRule;	/*�������*/
	int	iCnt;
	struct	TableFileControlOutStruct	*pHead;	/*�������*/
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
	double	dBillFee;		/*Ӫ�����۷���*/
	double	dTicketAuditFee;	/*������������Ʒ���*/
	double	dAcctAuditFee;		/*�˵���������Ʒ���*/
	double	dAuditFee;		/*��˽��*/
	char	cDuraFlag;		/*1,��ʶiValue��ʱ��,0��ʾ��ʱ��*/
	char	cTicketAuditFlag;	/*��������Ʊ�־,0δ��ˣ�1�����,2���ʧ��*/
	char	cAcctAuditFlag;		/*�˵�����Ʊ�־,0δ��ˣ�1�����,2���ʧ��*/
	char	cAuditFlag;		/*���˱�־*/
	char	sRealBillingTypeID[11];/*ʵ������ײ�ID*/	
	int	iTicketTariffID;
	int	iAcctTariffID;		
	int	iTariffID;		/*�����ʷ�*/

};

struct SimpleTicketStruct{
	
	struct SimpleTicketStruct *pNext;

	char	sAreaCode[9];
	char 	sMsisdn[21];
	char	sOtherParty[21];
	char	sStartTime[15];	/*��ʼʱ�����Чʱ��*/
	char	sEndTime[15];	/*����ʱ���ʧЧʱ��*/
	int	iDuration;	/*ͨ��ʱ��*/
	char	cBillFlag;	
/*��������,ֻ���ض��������д�����,0Ϊ�������ۣ�1Ϊ�������ۣ���������*/
	char	cJoinDateFlag;/*������ʶ*/
	char	sSourceID[41];
	char	sRowID[19];
	
	char	sBillingTypeID[26];	/*��Ÿ����������ײ�ID*/
	
	int	iLen;
	void	*pData;		/*����ԭʼ����*/
	
	double 	dAllFee;	/*����ʱ���ã�Ϊ�������õ��ܺ�*/
	char  	cFlag;		/*״̬��ʶ*/
	struct SimpleItemStruct *pAuditList;	/*������Ŀ�������Ŀ��*/
	
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

����Ϊ�嵥���˲���

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

/*�޷�������ϸ*/
#define AUDIT_NOT_SUB_BILL	-10	/*���ײ�δ����*/
#define AUDIT_NOT_MAIN_BILL	-11	/*���ײ�δ����*/
#define AUDIT_NOT_T		-12	/*δ�����嵥���˹���*/
#define AUDIT_NOT_M		-13	/*δ�����嵥���˹������Ŀ����*/
#define AUDIT_NOT_D		-14	/*δ�����������*/
/*��ϸ��ʶ*/
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
	char	sMsisdn[21];	/*�����ֽڶ���,��24λ*/
	char	iFlag;
/*
�����Ż�ʱ��0���ǵ�ǰ��Ŀ,1��ǰ�������͵���Ŀ
�˵��ȶ�ʱBillAcct��
	    10,����ϵͳ����˵�;
	    1,����һ���˵�;
	    2,���ò����˵�;	��ʱiFee�ֶ���дAuditFee-iFee�ֶ�.
	    3,����ϵͳ����˵�.
*/
	char	iDetailFlag;	/*�ǹ鲢��Ŀ����״̬*/
/**
	 0,����һ���˵�
	 1,����ϵͳ���ô�������ϵͳ
	 -1,����ϵͳ���ô��ڻ���ϵͳ
	 
**/
	char	iNAuditFlag;	/*�޷�������ϸ*/
	char	sBillingTypeID[11];/*�ײ�ID*/
	char	iType;
/****
1	�������嵥��������Ŀ
2	�û����Ż������Ŀ
3	�˻����Ż������Ŀ
****/
	char	sAcctType[2];	/*��Ŀ����'T':Ϊ�嵥���˵���'M':Ϊ��Ŀ���˵�*/
	char	sState[2];	/*��Ŀ״̬,'0':����,'1'���*/
	char	sAreaCode[10];	/*�û���������*/
	int	iAcctItemTypeID;
	int	iAuditItemTypeID;/* ������ĿID */
	int	iAcctID;	/*��ĿID*/
	int	iDefaultAcctID;	/*��ĿID*/
	
	int	iFee;		/*��λΪ��*/
	int	iOppFee;	/*��һ������*/
	int	iTariffID;	/*��������ֶΣ����ڱ������õ���Ŀ�Ż�TARIFFID*/
	
	struct SimpleAcctItemStruct *pServList;	/*�û����˵��б�*/
	
	char	sSourceID[41];
	char	sRowID[19];
	struct SimpleAcctItemStruct *pLoadNext;
};

/*��ŵ�����Ŀ�Ż���*/
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
/*���Զ�����ȡ��չ������ֵ*/
int GetDefExtendAttrValue(char sAttrValue[],int iExtendAttrID,char sValue[]);

/*�������еõ�CODE���˻�����Ŀ�ܺ�*/
int GetAcctIDCodeBalance(int iAcctID,char sCode[]);
/*�������еõ�CODE���û�����Ŀ�ܺ�*/
int GetAccNbrSumBalance(char sAccNbr[],char sCode[]);
/*��ȡһ��ָ����Ŀ�ķ���*/
int GetAcctItemTypeIDCharge(int iAcctItemTypeID);

#endif

