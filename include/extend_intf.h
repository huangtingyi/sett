#ifndef __EXTEND_INTF_H__
#define __EXTEND_INTF_H__

#include <hnixs.h>
#include <wwfile.h>
#include <list.h>

#include <gen_supp.h>
#include <stt_ticket.h>
#include "extend_supp.h"

/*查找相应的扩展属性*/
int SearchExtendAttrWithiAttrID(int iAttrID,struct ExtendAttrStruct **pptCur);
int SearchExtendAttr(int iAttrID,int iExtendSeq,struct ExtendAttrStruct **pptCur);
int MInitExtendAttr();
int MDestroyExtendAttr();
/*查找相应的扩展属性值ID的定义关系*/
int SearchExtendAttrDefRelation(char sAttrValue[],int iExtendAttrID,
	struct ExtendAttrDefRelationStruct **pptCur);
int MInitExtendAttrDefRelation();
int MDestroyExtendAttrDefRelation();
/*查找相应的扩展属性值ID的定义*/
int SearchExtendAttrValue(int iValueID,struct ExtendAttrValueStruct **pptCur);
int SearchExtendAttrValueStd(char sStdCode[],
	struct ExtendAttrValueStruct **pptCur);
int MInitExtendAttrValue();
int MDestroyExtendAttrValue();

/*查找相应的属性ID*/
int SearchAttr(char sStdCode[],struct AttrStruct **pptCur);
int MInitAttr();
int MDestroyAttr();
/*表格格式*/
int SearchTableFormat(int iFormatID,struct TableFormatStruct **pptCur);
int MInitTableFormat();
int MDestroyTableFormat();
/*表格模板*/
int SearchTabTemplate(int iTemplateID,struct TabTemplateStruct **pptCur);
int MInitTabTemplate();
int MDestroyTabTemplate();
/**/
int SearchTabTemplateReal(char sRealName[],struct TabTemplateRealStruct **pptCur);
int MInitTabTemplateReal();
int MDestroyTabTemplateReal();
/*表格字段*/
int SearchTabColumnsX(int iTemplateID,char sColumnsName[],struct TabColumnsStruct **pptCur);
int SearchTabColumns(int iTemplateID,char sColumnsName[],struct TabColumnsStruct **pptCur);
int MInitTabColumns();
int MDestroyTabColumns();
/*承诺要素*/
int SearchPromiseElement(int iElementID,char sType[],
	struct PromiseElementStruct **pptCur);

int MInitPromiseElement();
int MDestroyPromiseElement();
/*承诺资费*/
int SearchPromiseTariff(int iPromiseElementID,char sBillingTypeID[],
	char sAreaCode[],char sPromiseType[],struct PromiseTariffStruct **pptCur);
int MInitPromiseTariff();
int MDestroyPromiseTariff();

int SearchPromiseTariffX(char sBillingTypeID[],struct PromiseTariffStruct **pptCur);
int SearchPromiseTariffBilling(int iTariffID,struct PromiseTariffStruct **pptCur);

/*计费分段表*/
int SearchMeasureSpan(int iMeasureSpanID,struct MeasureSpanStruct **pptCur);
int MInitMeasureSpan();
int MDestroyMeasureSpan();
/*计费分段费率表*/
int SearchMeasureFieldFee(int iFeeFieldID,struct MeasureFieldFeeStruct **pptCur);
int MInitMeasureFieldFee();
int MDestroyMeasureFieldFee();
/*查找IFORMAT的TABLEFIELD*/
int SearchTableFieldFormatList(int iFormatID,struct TableFieldStruct **pptCur);
/*计费时段组表*/
int SearchTimeSpanGrp(int iTimeSpanGrpID,struct TimeSpanGrpStruct **pptCur);
int MInitTimeSpanGrp();
int MDestroyTimeSpanGrp();
/*计费时段组关系表*/

/*稽核账目表*/
int SearchAuditItemType(int iAuditItemTypeID,struct AuditItemTypeStruct **pptCur);
int MInitAuditItemType();
int MDestroyAuditItemType();
/*稽核账目和基准账目关系*/
int SearchAuditItemRelation(int iAcctItemTypeID,struct AuditItemRelationStruct **pptCur);
int MInitAuditItemRelation();
int MDestroyAuditItemRelation();

/*承诺公式参数*/
int SearchPromiseExprParam(int iParamID,struct PromiseExprParamStruct **pptCur);
int MInitPromiseExprParam();
int MDestroyPromiseExprParam();

/*承诺公式号码参数*/
int SearchPromiseExprMsisdnParam(char sBillingTypeID[],char sMsisdn[],
	struct PromiseExprMsisdnParamStruct **pptCur);
int MInitPromiseExprMsisdnParam();
int MDestroyPromiseExprMsisdnParam();

/*承诺公式*/
int SearchPromiseExpr(int iExprID,struct PromiseExprStruct **pptCur);
int MInitPromiseExpr();
int MDestroyPromiseExpr();
/*月租费资费*/
int SearchMonthFeeTariff(char sBillingTypeID[],int iPromiseElementID,
	char sHlafMonthFlag[],char sAreaCode[],
	struct MonthFeeTariffStruct **pptCur);
int MInitMonthFeeTariff();
int MDestroyMonthFeeTariff();
/*公式运行状态原因*/
int SearchPromiseExprStateReason(int iExprID,int iStateSeq,
	struct PromiseExprStateReasonStruct **pptCur);
int MInitPromiseExprStateReason();
int MDestroyPromiseExprStateReason();

/*账目科目关系表*/

int SearchAcctItemTypeRelation(int iSubjectID,struct AcctItemTypeRelationStruct **pptCur);
int MInitAcctItemTypeRelation();
int MDestroyAcctItemTypeRelation();

/*科目表*/
int SearchAccSubject(int iSubjectID,struct AccSubjectStruct **pptCur);
int MInitAccSubject();
int MDestroyAccSubject();

/*将TabColumnsStruct 转成MyTabColumnsStruct*/
struct MyTabColumnsStruct * CreateMyTabColumnsList(struct TabColumnsStruct *ptHead);
void GetTableNameStmt(struct TabColumnsStruct *ptLkHead,
	char sTableName[],char sCondition[],char statement[]);
void SetTabColumnOffset(struct TabColumnsStruct *ptHead);
int SumTabColumnLen(struct TabColumnsStruct *ptHead);
void LinkTabColumnHead(struct TabColumnsStruct *ptHead,
	struct TabColumnsStruct *ptLkHead);
int GetRateUnit(char cRateUnit);

struct MeasureSpanStruct* GetMeasureSpanSet(int iMeasureSpanTypeID);
struct TimeSpanGrpStruct* GetTimeSpanGrpSet(int iTimeSpanTypeID);
int CheckMeasureTimeSpanWhole(struct PromiseTariffStruct *p,
	struct PromiseTariffStruct *ptHead);
int GetMeasureSpanType(int iMeasureSpanID);
int GetTimeSpanType(int iTimeSpanGrpID);

struct MeasureSpanStruct *GetMeasureSpan(int iMeasureSpanID);
struct TimeSpanGrpStruct *GetTimeSpanGrp(int iTimeSpanGrpID);


int SearchHoliday(time_t tCurDate,struct HolidayStruct **pptCur);
int MInitHoliday();
int MDestroyHoliday();

/*2010.11.23这里为套餐相关性分析部分*/
int SearchCrPromiseElementRelation(int iCrPromiseElementID,
	struct CrPromiseElementRelationStruct **pptCur);
int MInitCrPromiseElementRelation();
int MDestroyCrPromiseElementRelation();

int SearchCrAcctItemTypeRelation(int iCrAcctItemTypeID,
	struct CrAcctItemTypeRelationStruct **pptCur);
int MInitCrAcctItemTypeRelation();
int MDestroyCrAcctItemTypeRelation();

int SearchCrPatternTariffRelation(int iPatternID,
	struct CrPatternTariffRelationStruct **pptCur);
int MInitCrPatternTariffRelation();
int MDestroyCrPatternTariffRelation();

int SearchCrPromiseElement(int iPromiseElementID,
	struct CrPromiseElementStruct **pptCur);
int MInitCrPromiseElement();
int MDestroyCrPromiseElement();

int SearchCrAcctItemType(int iAcctItemTypeID,struct CrAcctItemTypeStruct **pptCur);
int MInitCrAcctItemType();
int MDestroyCrAcctItemType();

int SearchCrServiceType(int iServiceTypeID,struct CrServiceTypeStruct **pptCur);
int MInitCrServiceType();
int MDestroyCrServiceType();

int SearchCrServiceImplPattern(int iPatternID,struct CrServiceImplPatternStruct **pptCur);
int MInitCrServiceImplPattern();
int MDestroyCrServiceImplPattern();

int SearchCrPromiseAcctRelation(int iAcctItemTypeID,struct CrPromiseAcctRelationStruct **pptCur);
int MInitCrPromiseAcctRelation();
int MDestroyCrPromiseAcctRelation();

int SearchCrBillPromiseEleRlt(char sBillingTypeID[],struct CrBillPromiseEleRltStruct **pptCur);
int MInitCrBillPromiseEleRlt();
int MDestroyCrBillPromiseEleRlt();

int SearchCrBillAcctItemRlt(char sBillingTypeID[],struct CrBillAcctItemRltStruct **pptCur);
int MInitCrBillAcctItemRlt();
int MDestroyCrBillAcctItemRlt();

int SearchCrBillPatternRlt(char sBillingTypeID[],struct CrBillPatternRltStruct **pptCur);
int MInitCrBillPatternRlt();
int MDestroyCrBillPatternRlt();

int SearchCrBillServTypeRlt(char sBillingTypeID[],struct CrBillServTypeRltStruct **pptCur);
int MInitCrBillServTypeRlt();
int MDestroyCrBillServTypeRlt();

int SearchCrAcctIndexRlt(int iAcctItemTypeID,struct CrAcctIndexRltStruct **pptCur);
int MInitCrAcctIndexRlt();
int MDestroyCrAcctIndexRlt();

/*账目分摊方法*/
int SearchCrBillTypeAcctAppr(int iAcctItemTypeID,char sBillingTypeID[],
	struct CrBillTypeAcctApprStruct **pptCur);
int MInitCrBillTypeAcctAppr();
int MDestroyCrBillTypeAcctAppr();

int SearchBillTypeAcctApprParam(int iApprID,struct CrBillTypeAcctApprParamStruct **pptCur);
int MInitBillTypeAcctApprParam();
int MDestroyBillTypeAcctApprParam();

int SearchCrServiceTypeAcctAppr(int iAcctItemTypeID,char sBillingTypeID[],
	struct CrServiceTypeAcctApprStruct **pptCur);
int MInitCrServiceTypeAcctAppr();
int MDestroyCrServiceTypeAcctAppr();

int SearchCrServTypeAcctApprParam(int iServiceApprID,struct CrServTypeAcctApprParamStruct **pptCur);
int MInitCrServTypeAcctApprParam();
int MDestroyCrServTypeAcctApprParam();

int SearchCrSubServiceCode(int iApprID,struct CrSubServiceCodeStruct **pptCur);
int MInitCrSubServiceCode();
int MDestroyCrSubServiceCode();

int SearchCrServiceIndex(int iIndexID,struct CrServiceIndexStruct **pptCur);
int MInitCrServiceIndex();
int MDestroyCrServiceIndex();

int SearchCrIndexGradeDesc(int iIndexID,struct CrIndexGradeDescStruct **pptCur);
int MInitCrIndexGradeDesc();
int MDestroyCrIndexGradeDesc();

int data_search_bintree_cr_package_tariff_id_e(void *pValue,void *pData);
int SearchCrPackageTariffID(char sBillingTypeID[],struct CrPackageTariffIDStruct **pptCur);
int MInitCrPackageTariffID();
int MDestroyCrPackageTariffID();

int SearchBillingType(char sBillingTypeID[],struct BillingTypeStruct **pptCur);
int MInitBillingType();
int MDestroyBillingType();

#endif
