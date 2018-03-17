#ifndef __SETT_NBR_SUPP_H__
#define __SETT_NBR_SUPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <bintree.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <wwfile.h>



/*输出结构缓冲申明*/
struct SettNbrStatStructOut{

#ifndef SETT_NBR_STAT_BUFLEN_OUT
#define SETT_NBR_STAT_BUFLEN_OUT		300
#endif

	struct SettNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算号码 */
	char    asAccNbr[SETT_NBR_STAT_BUFLEN_OUT][21];
		/* 号码归属地 */
	char    asHomeAreaCode[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* 号码归属省 */
	char    asProvCode[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* 结算地区号 */
	char    asVisitAreaCode[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* 核算专业 */
	char    asNetType[SETT_NBR_STAT_BUFLEN_OUT][5];
		/* 结算类型 */
	int     aiTicketTypeID[SETT_NBR_STAT_BUFLEN_OUT];
		/* 话单数 */
	int     aiCnt[SETT_NBR_STAT_BUFLEN_OUT];
		/* 通话时长 */
	int     aiDuration[SETT_NBR_STAT_BUFLEN_OUT];	
		/* 结算分钟数 */
	int     aiSettMin[SETT_NBR_STAT_BUFLEN_OUT];
		/* 结算收入 */
	char    asInFee[SETT_NBR_STAT_BUFLEN_OUT][13];
		/* 结算支出 */
	char    asOutFee[SETT_NBR_STAT_BUFLEN_OUT][13];
		/* 业务类型 */
	char    asServiceType[SETT_NBR_STAT_BUFLEN_OUT][4];
		/* 本端号码类型 */
	char    asNbrType[SETT_NBR_STAT_BUFLEN_OUT][5];
		/* 对端号码类型 */
	char    asOppNbrType[SETT_NBR_STAT_BUFLEN_OUT][5];
		/* 对端运营商 */
	int     aiOppCarrID[SETT_NBR_STAT_BUFLEN_OUT];
		/* 对端运营商地区号 */
	char    asOppArea[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* 对端运营商归属省 */
	char    asOppProv[SETT_NBR_STAT_BUFLEN_OUT][6];
		/* 号码套餐ID */
	char    asBillingTypeID[SETT_NBR_STAT_BUFLEN_OUT][21];
		/* 保留维度1 */
	char    asReserve1[SETT_NBR_STAT_BUFLEN_OUT][11];
		/* 保留维度2 */
	char    asReserve2[SETT_NBR_STAT_BUFLEN_OUT][11];
		/* 保留维度3 */
	char    asReserve3[SETT_NBR_STAT_BUFLEN_OUT][11];
		/* 结算日期 */
	char    asSettItemDate[SETT_NBR_STAT_BUFLEN_OUT][9];
		/* 结算账期 */
	char    asBillingCycleID[SETT_NBR_STAT_BUFLEN_OUT][7];
};


/* 输入结构缓冲申明*/
struct SettNbrStatStructIn{

#ifndef SETT_NBR_STAT_BUFLEN_IN
#define SETT_NBR_STAT_BUFLEN_IN		300
#endif

	struct SettNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 结算号码 */
	char    asAccNbr[SETT_NBR_STAT_BUFLEN_IN][21];
		/* 号码归属地 */
	char    asHomeAreaCode[SETT_NBR_STAT_BUFLEN_IN][6];
		/* 号码归属省 */
	char    asProvCode[SETT_NBR_STAT_BUFLEN_IN][6];
		/* 结算地区号 */
	char    asVisitAreaCode[SETT_NBR_STAT_BUFLEN_IN][6];
		/* 核算专业 */
	char    asNetType[SETT_NBR_STAT_BUFLEN_IN][5];
		/* 结算类型 */
	int     aiTicketTypeID[SETT_NBR_STAT_BUFLEN_IN];
		/* 话单数 */
	int     aiCnt[SETT_NBR_STAT_BUFLEN_IN];
		/* 通话时长 */
	int     aiDuration[SETT_NBR_STAT_BUFLEN_IN];	
		/* 结算分钟数 */
	int     aiSettMin[SETT_NBR_STAT_BUFLEN_IN];
		/* 结算收入 */
	char    asInFee[SETT_NBR_STAT_BUFLEN_IN][13];
		/* 结算支出 */
	char    asOutFee[SETT_NBR_STAT_BUFLEN_IN][13];
		/* 业务类型 */
	char    asServiceType[SETT_NBR_STAT_BUFLEN_IN][4];
		/* 本端号码类型 */
	char    asNbrType[SETT_NBR_STAT_BUFLEN_IN][5];
		/* 对端号码类型 */
	char    asOppNbrType[SETT_NBR_STAT_BUFLEN_IN][5];
		/* 对端运营商 */
	int     aiOppCarrID[SETT_NBR_STAT_BUFLEN_IN];
		/* 对端运营商地区号 */
	char    asOppArea[SETT_NBR_STAT_BUFLEN_IN][6];
		/* 对端运营商归属省 */
	char    asOppProv[SETT_NBR_STAT_BUFLEN_IN][6];
		/* 号码套餐ID */
	char    asBillingTypeID[SETT_NBR_STAT_BUFLEN_IN][21];
		/* 保留维度1 */
	char    asReserve1[SETT_NBR_STAT_BUFLEN_IN][11];
		/* 保留维度2 */
	char    asReserve2[SETT_NBR_STAT_BUFLEN_IN][11];
		/* 保留维度3 */
	char    asReserve3[SETT_NBR_STAT_BUFLEN_IN][11];
		/* 结算日期 */
	char    asSettItemDate[SETT_NBR_STAT_BUFLEN_IN][9];
		/* 结算账期 */
	char    asBillingCycleID[SETT_NBR_STAT_BUFLEN_IN][7];
};


/*单个结构申明*/
struct SettNbrStatStruct{

	struct SettNbrStatStruct *pNext;
	char    sAccNbr[21];		/* 结算号码 */
	char    sHomeAreaCode[6];		/* 号码归属地 */
	char    sProvCode[6];		/* 号码归属省 */
	char    sVisitAreaCode[6];		/* 结算地区号 */
	char    sNetType[5];		/* 核算专业 */
	int     iTicketTypeID;		/* 结算类型 */
	int     iCnt;		/* 话单数 */
	int     iDuration;		/* 通话时长 */	
	int     iSettMin;		/* 结算分钟数 */
	char    sInFee[13];		/* 结算收入 */
	char    sOutFee[13];		/* 结算支出 */
	char    sServiceType[4];		/* 业务类型 */
	char    sNbrType[5];		/* 本端号码类型 */
	char    sOppNbrType[5];		/* 对端号码类型 */
	int     iOppCarrID;		/* 对端运营商 */
	char    sOppArea[6];		/* 对端运营商地区号 */
	char    sOppProv[6];		/* 对端运营商归属省 */
	char    sBillingTypeID[21];		/* 号码套餐ID */
	char    sReserve1[11];		/* 保留维度1 */
	char    sReserve2[11];		/* 保留维度2 */
	char    sReserve3[11];		/* 保留维度3 */
	char    sSettItemDate[9];		/* 结算日期 */
	char    sBillingCycleID[7];		/* 结算账期 */
	struct SettNbrStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettNbrStatStruct{

	char    sAccNbr[20];		/* 结算号码 */
	char    sHomeAreaCode[5];		/* 号码归属地 */
	char    sProvCode[5];		/* 号码归属省 */
	char    sVisitAreaCode[5];		/* 结算地区号 */
	char    sNetType[4];		/* 核算专业 */
	char    sTicketTypeID[4];		/* 结算类型 */
	char    sCnt[9];		/* 话单数 */
	char    sDuration[9];		/* 通话时长 */
	char    sSettMin[9];		/* 结算分钟数 */
	char    sInFee[12];		/* 结算收入 */
	char    sOutFee[12];		/* 结算支出 */
	char    sServiceType[3];		/* 业务类型 */
	char    sNbrType[4];		/* 本端号码类型 */
	char    sOppNbrType[4];		/* 对端号码类型 */
	char    sOppCarrID[4];		/* 对端运营商 */
	char    sOppArea[5];		/* 对端运营商地区号 */
	char    sOppProv[5];		/* 对端运营商归属省 */
	char    sBillingTypeID[20];		/* 号码套餐ID */
	char    sReserve1[10];		/* 保留维度1 */
	char    sReserve2[10];		/* 保留维度2 */
	char    sReserve3[10];		/* 保留维度3 */
	char    sSettItemDate[8];		/* 结算日期 */
	char    sBillingCycleID[6];		/* 结算账期 */
};


/*批量数据动态从SETT_NBR_STAT中用结构缓冲方式取数据*/
int EGetSettNbrStatToStruct(struct SettNbrStatStruct *p,
	struct SettNbrStatStructIn *pSource);
void mvitem_settnbrstat(struct SettNbrStatStruct *pi,struct SettNbrStatStruct *po);
void mvitem_mfsettnbrstat(struct SettNbrStatStruct *pi,struct FSettNbrStatStruct *po);
void mvitem_fmsettnbrstat(struct FSettNbrStatStruct *pi,struct SettNbrStatStruct *po);

/*批量数据结构缓冲写入SETT_NBR_STAT*/
int EInsertStructToSettNbrStat(struct SettNbrStatStruct *p,
	int iInsertFlag,struct SettNbrStatStructOut *pTarget);


int data_search_bintree_settnbrstat_e(void *pValue,void*pData);
void assign_insert_bintree_settnbrstat_e(void **ppData,void *pData);

void GetNbrType(char sAccNbr[],
	int iCarrierID,char sAreaCode[],char sOutNbrType[]);
void GetProvCode(char sAreaCode[],char sVisitAreaCode[],char sOutsProvCode[]);
int GetSttRes(char sAccNbr[],char sRawNbr[],
	char sAreaCode[],char sStartTime[],char sRes[]);
/*void ModifySttTicket(struct SttTicketStruct *pi);

int STT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int VIT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int TLR_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);	
int TLL_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int STP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int TLP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int SMS_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int SCX_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
*/


/*输出结构缓冲申明*/
struct SettNbrStatLogStructOut{

#ifndef SETT_NBR_STAT_LOG_BUFLEN_OUT
#define SETT_NBR_STAT_LOG_BUFLEN_OUT		300
#endif

	struct SettNbrStatLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];

	char    asSourceTable[SETT_NBR_STAT_LOG_BUFLEN_OUT][31];
	char    asTargetTable[SETT_NBR_STAT_LOG_BUFLEN_OUT][31];
	char    asSettDate[SETT_NBR_STAT_LOG_BUFLEN_OUT][14];
	char	asServiceType[SETT_NBR_STAT_LOG_BUFLEN_OUT][9];
	char	asStatType[SETT_NBR_STAT_LOG_BUFLEN_OUT][9];
	int	aiGroupID[SETT_NBR_STAT_LOG_BUFLEN_OUT];
	char    asState[SETT_NBR_STAT_LOG_BUFLEN_OUT][2];
	char	asDealDate[SETT_NBR_STAT_LOG_BUFLEN_OUT][15];
};


/* 输入结构缓冲申明*/
struct SettNbrStatLogStructIn{

#ifndef SETT_NBR_STAT_LOG_BUFLEN_IN
#define SETT_NBR_STAT_LOG_BUFLEN_IN		300
#endif

	struct SettNbrStatLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];

	char    asSourceTable[SETT_NBR_STAT_LOG_BUFLEN_IN][31];
	char    asTargetTable[SETT_NBR_STAT_LOG_BUFLEN_IN][31];
	char    asSettDate[SETT_NBR_STAT_LOG_BUFLEN_IN][14];
	char	asServiceType[SETT_NBR_STAT_LOG_BUFLEN_IN][9];
	char	asStatType[SETT_NBR_STAT_LOG_BUFLEN_IN][9];
	int	aiGroupID[SETT_NBR_STAT_LOG_BUFLEN_IN];
	char    asState[SETT_NBR_STAT_LOG_BUFLEN_IN][2];
	char	asDealDate[SETT_NBR_STAT_LOG_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SettNbrStatLogStruct{

	struct SettNbrStatLogStruct *pNext;
	char    sSourceTable[31];
	char    sTargetTable[31];
	char    sSettDate[15];
	char	sServiceType[9];
	char	sStatType[9];
	int	iGroupID;
	char    sState[2];
	char	sDealDate[15];
	struct SettNbrStatLogStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettNbrStatLogStruct{

	char    sSourceTable[30];
	char    sTargetTable[30];
	char    sSettDate[14];
	char	sServiceType[8];
	char	sStatType[8];
	char	sGroupID[8];
	char    sState[1];
	char	sDealDate[14];
};
int SDInsertStructToSettNbrStatLog(struct SettNbrStatLogStruct *p,char sTableName[]);
int SDGetSettNbrStatToStruct(struct SettNbrStatLogStruct *p,char sTableName[],char sCondition[]);
/*************2016.01.29**************/
int IsInNBR(char sMsisdn[]);


#endif

