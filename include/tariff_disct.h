#ifndef	__TARIFF_DISCT_H__
#define __TARIFF_DISCT_H__

#include <list.h>
#include <param_intf.h>
#include <ticket_field.h>
#include <gen_supp.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

struct TimeSpanStruct
{
	struct TimeSpanStruct *pNext;
	
	int	iBeginCnt;	/*生效开始次数*/
	int	iEndCnt;	/*生效终止次数*/
	
	int	iMethod;	/*方法*/
	int	iRate;
	int	iAcctItemTypeID;
	
	time_t	tBeginTime;	/*临时话单开始时间*/
	time_t	tEndTime;	/*临时话单终止时间*/
	int	iCounts;
	
	struct TimeSpanStruct *pLoadNext;
};
struct TimeSpanControlStruct
{
	struct TimeSpanStruct 		*pTimeSpan;
	struct TicketBasedDisctStruct 	*pTicketBased;
};
struct TicketBasedDisctStruct *GetTicketBasedDisctList(int iDisctRuleID);
struct TimeSpanControlStruct *GetTimeSpanDisctList(int iDisctRuleID);
struct ExprDefStruct *GetExprDisctList(int iDisctRuleID);
struct DisctRuleMutexStruct *GetDisctRuleMutexList(int iDisctRuleID);

int comp_disct_rule_ticket01(LIST* pData);
int InitialDisctRule(struct DisctRuleStruct *pTemp);
struct DisctRuleStruct *InitDisctRuleList(int (*comp_fun)(LIST*));
void ResetDisctRuleList(struct DisctRuleStruct *ptHead);

int comp_toll_tariff_ticket03(LIST* pData);
int comp_toll_tariff_ticket(LIST* pData);
struct TollTariffStruct *InitTollTariffList();
void ResetTollTariffList(struct TollTariffStruct *ptHead);

int GetPrecision(int k,int p);

int SearchTollTariffSeqListTime(struct TollTariffStruct *ptHead,
	char sStartTime[],struct TollTariffStruct **pptCur);
int SearchTollTariffSeqListID(struct TollTariffStruct *ptHead,
	int iTariffID,int iSeqNbr,struct TollTariffStruct **pptCur);


struct TollTariffStruct *GetTollTariffList(int iTicketTypeID,char sFieldType[]);
/*按照要求生成Tariff列表,根据TARIFF_REF串*/
struct TollTariffStruct *GetTariffRefList(char sTariffRef[]);
void TicketTimeIntersectToTariff(time_t tStartTime,int iDuration,
	struct TollTariffStruct *pTollTariff);
void GetCalcFee(struct TollTariffStruct *pTollTariff,
	int *piRoamFee,int *piTollFee,int *piAddFee);
void GetCalcDisct(struct DisctRuleStruct *pDisctRule,int *piDisctFee);

int GetPrecision(int k,int p);
void TicketTimeIntersectToTariff(time_t tStartTime,int iDuration,
	struct TollTariffStruct *pTollTariff);
struct DisctRuleStruct *GetDisctRuleList(int iTariffID,int iSeqNbr);
void MutexDisctRule(struct DisctRuleStruct **ppDisctRule);
void TicketTimeIntersectToTimeSpan(struct DisctRuleStruct *pDisctRule,
	struct TimeSpanStruct **ppTimeSpan);
struct TicketBasedDisctStruct *GetTicketBased(
	struct TicketBasedDisctStruct *pTicketBased,time_t tBeginTime);
int MainTicketBasedDisct(struct TimeSpanStruct *pTimeSpan,
	struct TicketBasedDisctStruct *pTicketBased,
	struct DisctRuleStruct *pDisctRule);
void DisctTimeSpan(struct DisctRuleStruct *p);
void DisctExpr(struct DisctRuleStruct *p);

void DisctMain(struct TollTariffStruct *ptHead);

struct BaseYearStruct
{
	struct BaseYearStruct *pNext;
	char sBaseDate[15];
	time_t tBeginDate;
	time_t tEndDate;
};
void InitBaseItem(char sBaseDate[15],struct BaseYearStruct *po);
int InitBaseYear(struct BaseYearStruct *ptHead);
int InitBaseNian(struct BaseYearStruct *ptHead);
int TicketBasedYearUnit(
	time_t tBeginTime,struct TicketBasedDisctStruct *pTicketBased);

void GetCalcFeeRate(struct TollTariffStruct *pTollTariff,
	int iValue,int *piRoamFee,int *piTollFee,int *piAddFee);
struct TollTariffStruct *GetTariffList(int iTicketTypeID,char sFieldType[],
	char sTariffType[]);

#endif


