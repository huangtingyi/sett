#ifndef __STT_TICKET_H__
#define __STT_TICKET_H__

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <bintree.h>
#include <wwfile.h>
#include <ticket.h>

int InsertTicket(char sFileName[],char sTableName[],char sType[]);

int SttTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmscTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmspTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int GprsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int NsmsTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int PrepTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int Cdma1xTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*输出结构缓冲申明*/
struct PrepTicketStructOut{

#ifndef PREP_TICKET_BUFLEN_OUT
#define PREP_TICKET_BUFLEN_OUT		300
#endif

	struct PrepTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 呼叫类型 */
	char    asCallType[PREP_TICKET_BUFLEN_OUT][3];
		/* IMSI */
	char    asImsi[PREP_TICKET_BUFLEN_OUT][16];
		/* 用户号码 */
	char    asMsisdn[PREP_TICKET_BUFLEN_OUT][16];
		/* 对端号码 */
	char    asOtherParty[PREP_TICKET_BUFLEN_OUT][25];
		/* 应答时间 */
	char    asStartTime[PREP_TICKET_BUFLEN_OUT][15];
		/* 时长 */
	char    asDuration[PREP_TICKET_BUFLEN_OUT][7];
		/* MSC */
	char    asMsc[PREP_TICKET_BUFLEN_OUT][11];
		/* 入中继 */
	char    asTrunkIn[PREP_TICKET_BUFLEN_OUT][9];
		/* 出中继 */
	char    asTrunkOut[PREP_TICKET_BUFLEN_OUT][9];
		/* LAC */
	char    asLac[PREP_TICKET_BUFLEN_OUT][5];
		/* CELL_ID */
	char    asCellID[PREP_TICKET_BUFLEN_OUT][5];
		/* 对端LAC */
	char    asOtherLac[PREP_TICKET_BUFLEN_OUT][5];
		/* 对端CELL_ID */
	char    asOtherCellID[PREP_TICKET_BUFLEN_OUT][5];
		/* 业务类型 */
	char    asServiceType[PREP_TICKET_BUFLEN_OUT][4];
		/* 业务代码 */
	char    asServiceCode[PREP_TICKET_BUFLEN_OUT][5];
		/* 第三方号码 */
	char    asThirdParty[PREP_TICKET_BUFLEN_OUT][16];
		/* MSRN */
	char    asMsrn[PREP_TICKET_BUFLEN_OUT][13];
	
		/* 用户类型 */
	char    asUserType[PREP_TICKET_BUFLEN_OUT][2];
		/* 保留1 */
	char    asReserve1[PREP_TICKET_BUFLEN_OUT][3];

		/* 电子串号 */
	char    asEsn[PREP_TICKET_BUFLEN_OUT][16];

/*话单合并需要的字段*/	
	char    asScpFlag[PREP_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[PREP_TICKET_BUFLEN_OUT][2];
	
	char	asReserve[PREP_TICKET_BUFLEN_OUT][9];
	char	asErrCode[PREP_TICKET_BUFLEN_OUT][5];
	char	asFileName[PREP_TICKET_BUFLEN_OUT][20];
	char	asModule[PREP_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[PREP_TICKET_BUFLEN_OUT][6];
	char	asState[PREP_TICKET_BUFLEN_OUT][2];
		/* 处理日期 */
	char    asUpdateDate[PREP_TICKET_BUFLEN_OUT][15];
	char    asDealDate[PREP_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[PREP_TICKET_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct PrepTicketStructIn{

#ifndef PREP_TICKET_BUFLEN_IN
#define PREP_TICKET_BUFLEN_IN		300
#endif

	struct PrepTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 呼叫类型 */
	char    asCallType[PREP_TICKET_BUFLEN_IN][3];
		/* IMSI */
	char    asImsi[PREP_TICKET_BUFLEN_IN][16];
		/* 用户号码 */
	char    asMsisdn[PREP_TICKET_BUFLEN_IN][16];
		/* 对端号码 */
	char    asOtherParty[PREP_TICKET_BUFLEN_IN][25];
		/* 应答时间 */
	char    asStartTime[PREP_TICKET_BUFLEN_IN][15];
		/* 时长 */
	char    asDuration[PREP_TICKET_BUFLEN_IN][7];
		/* MSC */
	char    asMsc[PREP_TICKET_BUFLEN_IN][11];
		/* 入中继 */
	char    asTrunkIn[PREP_TICKET_BUFLEN_IN][9];
		/* 出中继 */
	char    asTrunkOut[PREP_TICKET_BUFLEN_IN][9];
		/* LAC */
	char    asLac[PREP_TICKET_BUFLEN_IN][5];
		/* CELL_ID */
	char    asCellID[PREP_TICKET_BUFLEN_IN][5];
		/* 对端LAC */
	char    asOtherLac[PREP_TICKET_BUFLEN_IN][5];
		/* 对端CELL_ID */
	char    asOtherCellID[PREP_TICKET_BUFLEN_IN][5];
		/* 业务类型 */
	char    asServiceType[PREP_TICKET_BUFLEN_IN][4];
		/* 业务代码 */
	char    asServiceCode[PREP_TICKET_BUFLEN_IN][5];
		/* 第三方号码 */
	char    asThirdParty[PREP_TICKET_BUFLEN_IN][16];
		/* MSRN */
	char    asMsrn[PREP_TICKET_BUFLEN_IN][13];
	
		/* 用户类型 */
	char    asUserType[PREP_TICKET_BUFLEN_IN][2];
		/* 保留1 */
	char    asReserve1[PREP_TICKET_BUFLEN_IN][3];
		/* 电子串号 */
	char    asEsn[PREP_TICKET_BUFLEN_IN][16];
/*话单合并需要的字段*/	
	char    asScpFlag[PREP_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[PREP_TICKET_BUFLEN_IN][2];
	
	char	asReserve[PREP_TICKET_BUFLEN_IN][9];
	char	asErrCode[PREP_TICKET_BUFLEN_IN][5];
	char	asFileName[PREP_TICKET_BUFLEN_IN][20];
	char	asModule[PREP_TICKET_BUFLEN_IN][4];
	char	asAreaCode[PREP_TICKET_BUFLEN_IN][6];
	char	asState[PREP_TICKET_BUFLEN_IN][2];
		/* 处理日期 */
	char    asUpdateDate[PREP_TICKET_BUFLEN_IN][15];
	char    asDealDate[PREP_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[PREP_TICKET_BUFLEN_IN][41];
	char	asRowID[PREP_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct PrepTicketStruct{

	struct PrepTicketStruct *pNext;
	char    sCallType[3];		/* 呼叫类型 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* 用户号码 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	char    sDuration[7];		/* 时长 */
	char    sMsc[11];		/* MSC */
	char    sTrunkIn[9];		/* 入中继 */
	char    sTrunkOut[9];		/* 出中继 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* 对端LAC */
	char    sOtherCellID[5];		/* 对端CELL_ID */
	char    sServiceType[4];		/* 业务类型 */
	char    sServiceCode[5];		/* 业务代码 */
	char    sThirdParty[16];		/* 第三方号码 */
	char    sMsrn[13];		/* MSRN */
	char    sUserType[2];		/* MSRN */
	char    sReserve1[3];		/* MSRN */
	char    sEsn[16];		/* 电子串号 */
	char	sScpFlag[2];
	char	sDeformFlag[2];
	char	sReserve[9];
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sDealDate[15];		/* 处理日期 */
	char	sUpdateDate[15];
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct PrepTicketStruct *pLoadNext;
};


/*批量数据动态从PREP_TICKET中用结构缓冲方式取数据*/
int EInsertStructToPrepTicket(struct PrepTicketStruct *p,
	int iInsertFlag,struct PrepTicketStructOut *pTarget);
int InsertPrepTicket(char sFileName[],char sTableName[]);
void mvitem_fmprepticket(struct FPrepTicketStruct *pi,int len,
	struct PrepTicketStruct *po);
int EGetPrepTicketToStruct(struct PrepTicketStruct *p,
	struct PrepTicketStructIn *pSource);
void mvitem_mfprepticket(struct PrepTicketStruct *pi,struct FPrepTicketStruct *po);

/*输出结构缓冲申明*/
struct SttTicketStructOut{

#ifndef STT_TICKET_BUFLEN_OUT
#define STT_TICKET_BUFLEN_OUT		300
#endif

	struct SttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类别 */
	int     aiTicketTypeID[STT_TICKET_BUFLEN_OUT];
		/* 呼叫类别 */
	char    asCallType[STT_TICKET_BUFLEN_OUT][3];
		/* 用户号码 */
	char    asMsisdn[STT_TICKET_BUFLEN_OUT][16];
		/* 对端区号 */
	char    asCalledCode[STT_TICKET_BUFLEN_OUT][6];
		/* 对端号码 */
	char    asOtherParty[STT_TICKET_BUFLEN_OUT][25];
		/* 结算归属地区号 */
	char    asVisitAreaCode[STT_TICKET_BUFLEN_OUT][6];
		/* 漫游通话费 */
	int     aiRoamFee[STT_TICKET_BUFLEN_OUT];
		/* 长途费 */
	int     aiTollFee[STT_TICKET_BUFLEN_OUT];
		/* 其他费 */
	int     aiAddFee[STT_TICKET_BUFLEN_OUT];
		/* 时长 */
	int     aiDuration[STT_TICKET_BUFLEN_OUT];
		/* 通话开始时间 */
	char    asStartTime[STT_TICKET_BUFLEN_OUT][15];
		/* 用户归属地 */
	char    asHomeAreaCode[STT_TICKET_BUFLEN_OUT][6];
		/* 漫游类别 */
	char    asRoamType[STT_TICKET_BUFLEN_OUT][2];
		/* 位置类别 */
	char    asDistanceType[STT_TICKET_BUFLEN_OUT][2];
		/* 对端类别 */
	char    asOppType[STT_TICKET_BUFLEN_OUT][2];
		/* 用户类别 */
	char    asUserType[STT_TICKET_BUFLEN_OUT][2];
		/* 话单分离标识 */
	char    asSplitRuleID[STT_TICKET_BUFLEN_OUT][5];
		/* 对端漫游类别 */
	char    asOppRoamType[STT_TICKET_BUFLEN_OUT][2];
		/* 业务类型 */
	char    asServiceType[STT_TICKET_BUFLEN_OUT][4];
		/* 业务代码 */
	char    asServiceCode[STT_TICKET_BUFLEN_OUT][5];
		/* 用户IMSI */
	char    asImsi[STT_TICKET_BUFLEN_OUT][16];
		/* 交换机标识 */
	char    asMsc[STT_TICKET_BUFLEN_OUT][16];
		/* 小区号 */
	char    asLac[STT_TICKET_BUFLEN_OUT][6];
		/* 蜂窝号 */
	char    asCellID[STT_TICKET_BUFLEN_OUT][6];
	
		/* 小区号 */
	char    asOtherLac[STT_TICKET_BUFLEN_OUT][6];
		/* 蜂窝号 */
	char    asOtherCellID[STT_TICKET_BUFLEN_OUT][6];
	
		/* 入中继 */
	char    asTrunkIn[STT_TICKET_BUFLEN_OUT][8];
		/* 出中继 */
	char    asTrunkOut[STT_TICKET_BUFLEN_OUT][8];
		/* 第三方号码 */
	char    asThirdParty[STT_TICKET_BUFLEN_OUT][16];
		/* 动态漫游号 */
	char    asMsrn[STT_TICKET_BUFLEN_OUT][13];
		/* 入中继类别 */
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_OUT];
		/* 出中继类别 */
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_OUT];
		/* 入中继运营商 */
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_OUT];
		/* 出中继运营商 */
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_OUT];
		/* 入中继长途类型标识 */
	char    asTrunkInType[STT_TICKET_BUFLEN_OUT][2];
		/* 出中继长途类型标识 */
	char    asTrunkOutType[STT_TICKET_BUFLEN_OUT][2];
		/* 主叫号头运营商 */
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_OUT];
		/* 被叫号头运营商 */
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_OUT];
		/* 主叫类型标识 */
	int     aiCallingTypeID[STT_TICKET_BUFLEN_OUT];
		/* 被叫类型标识 */
	int     aiCalledTypeID[STT_TICKET_BUFLEN_OUT];
		/* 处理日期 */
		
	int     aiCallingAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledAreaID[STT_TICKET_BUFLEN_OUT];
	char    asSplitType[STT_TICKET_BUFLEN_OUT][2];
	char    asCal[STT_TICKET_BUFLEN_OUT][2];
	char    asEsn[STT_TICKET_BUFLEN_OUT][16];
/*话单合并需要的字段*/	
	char    asScpFlag[STT_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_OUT][2];
	
	char	asReserve[STT_TICKET_BUFLEN_OUT][9];
	char	asBillMode[STT_TICKET_BUFLEN_OUT][4];
	
	char	asReserve1[STT_TICKET_BUFLEN_OUT][3];
	char	asRoamTariffType[STT_TICKET_BUFLEN_OUT][4];
	char	asTollTariffType[STT_TICKET_BUFLEN_OUT][4];
	char	asAddTariffType[STT_TICKET_BUFLEN_OUT][4];

	char	asErrCode[STT_TICKET_BUFLEN_OUT][5];
	char	asFileName[STT_TICKET_BUFLEN_OUT][20];
	char	asModule[STT_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[STT_TICKET_BUFLEN_OUT][6];
	
	char    asState[STT_TICKET_BUFLEN_OUT][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_OUT][15];

	char    asDealDate[STT_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[STT_TICKET_BUFLEN_OUT][41];
};

/* 输入结构缓冲申明*/
struct SttTicketStructIn{

#ifndef STT_TICKET_BUFLEN_IN
#define STT_TICKET_BUFLEN_IN		300
#endif

	struct SttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类别 */
	int     aiTicketTypeID[STT_TICKET_BUFLEN_IN];
		/* 呼叫类别 */
	char    asCallType[STT_TICKET_BUFLEN_IN][3];
		/* 用户号码 */
	char    asMsisdn[STT_TICKET_BUFLEN_IN][16];
		/* 对端区号 */
	char    asCalledCode[STT_TICKET_BUFLEN_IN][6];
		/* 对端号码 */
	char    asOtherParty[STT_TICKET_BUFLEN_IN][25];
		/* 结算归属地区号 */
	char    asVisitAreaCode[STT_TICKET_BUFLEN_IN][6];
		/* 漫游通话费 */
	int     aiRoamFee[STT_TICKET_BUFLEN_IN];
		/* 长途费 */
	int     aiTollFee[STT_TICKET_BUFLEN_IN];
		/* 其他费 */
	int     aiAddFee[STT_TICKET_BUFLEN_IN];
		/* 时长 */
	int     aiDuration[STT_TICKET_BUFLEN_IN];
		/* 通话开始时间 */
	char    asStartTime[STT_TICKET_BUFLEN_IN][15];
		/* 用户归属地 */
	char    asHomeAreaCode[STT_TICKET_BUFLEN_IN][6];
		/* 漫游类别 */
	char    asRoamType[STT_TICKET_BUFLEN_IN][2];
		/* 位置类别 */
	char    asDistanceType[STT_TICKET_BUFLEN_IN][2];
		/* 对端类别 */
	char    asOppType[STT_TICKET_BUFLEN_IN][2];
		/* 用户类别 */
	char    asUserType[STT_TICKET_BUFLEN_IN][2];
		/* 话单分离标识 */
	char    asSplitRuleID[STT_TICKET_BUFLEN_IN][5];
		/* 对端漫游类别 */
	char    asOppRoamType[STT_TICKET_BUFLEN_IN][2];
		/* 业务类型 */
	char    asServiceType[STT_TICKET_BUFLEN_IN][4];
		/* 业务代码 */
	char    asServiceCode[STT_TICKET_BUFLEN_IN][5];
		/* 用户IMSI */
	char    asImsi[STT_TICKET_BUFLEN_IN][16];
		/* 交换机标识 */
	char    asMsc[STT_TICKET_BUFLEN_IN][16];
		/* 小区号 */
	char    asLac[STT_TICKET_BUFLEN_IN][6];
		/* 蜂窝号 */
	char    asCellID[STT_TICKET_BUFLEN_IN][6];
		/* 对端LAC */
	char    asOtherLac[STT_TICKET_BUFLEN_IN][6];
		/* 对端CELLID */
	char    asOtherCellID[STT_TICKET_BUFLEN_IN][6];
		/* 入中继 */
	char    asTrunkIn[STT_TICKET_BUFLEN_IN][8];
		/* 出中继 */
	char    asTrunkOut[STT_TICKET_BUFLEN_IN][8];
		/* 第三方号码 */
	char    asThirdParty[STT_TICKET_BUFLEN_IN][16];
		/* 动态漫游号 */
	char    asMsrn[STT_TICKET_BUFLEN_IN][13];
		/* 入中继类别 */
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_IN];
		/* 出中继类别 */
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_IN];
		/* 入中继运营商 */
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_IN];
		/* 出中继运营商 */
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_IN];
		/* 入中继长途类型标识 */
	char    asTrunkInType[STT_TICKET_BUFLEN_IN][2];
		/* 出中继长途类型标识 */
	char    asTrunkOutType[STT_TICKET_BUFLEN_IN][2];
		/* 主叫号头运营商 */
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_IN];
		/* 被叫号头运营商 */
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_IN];
		/* 主叫类型标识 */
	int     aiCallingTypeID[STT_TICKET_BUFLEN_IN];
		/* 被叫类型标识 */
	int     aiCalledTypeID[STT_TICKET_BUFLEN_IN];
		/* 主叫营业区标识 */
	int     aiCallingAreaID[STT_TICKET_BUFLEN_IN];
		/* 被叫营业区标识 */
	int     aiCalledAreaID[STT_TICKET_BUFLEN_IN];
		/* 分离类型 */
	char    asSplitType[STT_TICKET_BUFLEN_IN][2];
	char    asCal[STT_TICKET_BUFLEN_IN][2];
	char    asEsn[STT_TICKET_BUFLEN_IN][16];
	
	char    asScpFlag[STT_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_IN][2];
	
	char	asReserve[STT_TICKET_BUFLEN_IN][9];
	char	asBillMode[STT_TICKET_BUFLEN_IN][4];
	
	char	asReserve1[STT_TICKET_BUFLEN_IN][3];
	char	asRoamTariffType[STT_TICKET_BUFLEN_IN][4];
	char	asTollTariffType[STT_TICKET_BUFLEN_IN][4];
	char	asAddTariffType[STT_TICKET_BUFLEN_IN][4];

	char	asErrCode[STT_TICKET_BUFLEN_IN][5];
	char	asFileName[STT_TICKET_BUFLEN_IN][20];
	char	asModule[STT_TICKET_BUFLEN_IN][4];
	char	asAreaCode[STT_TICKET_BUFLEN_IN][6];

	char    asState[STT_TICKET_BUFLEN_IN][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_IN][15];
		/* 处理日期 */
	char    asDealDate[STT_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[STT_TICKET_BUFLEN_IN][41];
	char	asRowID[STT_TICKET_BUFLEN_IN][19];
};
/*单个结构申明*/
struct SttTicketStruct{

	struct SttTicketStruct *pNext;
	int     iTicketTypeID;		/* 话单类别 */
	char    sCallType[3];		/* 呼叫类别 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sCalledCode[6];		/* 对端区号 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sVisitAreaCode[6];		/* 结算归属地区号 */
	int     iRoamFee;		/* 漫游通话费 */
	int     iTollFee;		/* 长途费 */
	int     iAddFee;		/* 其他费 */
	int     iDuration;		/* 时长 */
	char    sStartTime[15];		/* 通话开始时间 */
	char    sHomeAreaCode[6];		/* 用户归属地 */
	char    sRoamType[2];		/* 漫游类别 */
	char    sDistanceType[2];		/* 位置类别 */
	char    sOppType[2];		/* 对端类别 */
	char    sUserType[2];		/* 用户类别 */
	char    sSplitRuleID[5];		/* 话单分离标识 */
	char    sOppRoamType[2];		/* 对端漫游类别 */
	char    sServiceType[4];		/* 业务类型 */
	char    sServiceCode[5];		/* 业务代码 */
	char    sImsi[16];		/* 用户IMSI */
	char    sMsc[16];		/* 交换机标识 */
	char    sLac[6];		/* 小区号 */
	char    sCellID[6];		/* 蜂窝号 */
	
	char    sOtherLac[6];		/* 小区号 */
	char    sOtherCellID[6];	/* 蜂窝号 */
	
	char    sTrunkIn[8];		/* 入中继 */
	char    sTrunkOut[8];		/* 出中继 */
	char    sThirdParty[16];		/* 第三方号码 */
	char    sMsrn[13];		/* 动态漫游号 */
	int     iTrunkInTypeID;		/* 入中继类别 */
	int     iTrunkOutTypeID;		/* 出中继类别 */
	int     iTrunkInCarrierID;		/* 入中继运营商 */
	int     iTrunkOutCarrierID;		/* 出中继运营商 */
	char    sTrunkInType[2];		/* 入中继长途类型标识 */
	char    sTrunkOutType[2];		/* 出中继长途类型标识 */
	int     iCallingCarrierID;		/* 主叫号头运营商 */
	int     iCalledCarrierID;		/* 被叫号头运营商 */
	int     iCallingTypeID;		/* 主叫类型标识 */
	int     iCalledTypeID;		/* 被叫类型标识 */
	int	iCallingAreaID;
	int	iCalledAreaID;
	char	sSplitType[2];
	char	sCal[2];
	char	sEsn[16];
	char	sScpFlag[2];
	char	sDeformFlag[2];

	char	sReserve[9];
	char	sBillMode[4];
	
	char	sReserve1[3];
	char	sRoamTariffType[4];
	char	sTollTariffType[4];
	char	sAddTariffType[4];

	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];

	char	sState[2];
	char	sUpdateDate[15];
	char    sDealDate[15];		/* 处理日期 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct SttTicketStruct *pLoadNext;
};

int EInsertStructToSttTicket(struct SttTicketStruct *p,
        int iInsertFlag,struct SttTicketStructOut *pTarget);
int InsertSttTicket(char sFileName[],char sTableName[]);
void mvitem_fmsttticket(struct FSttTicketStruct *pi,int len,
	struct SttTicketStruct *po);
/*批量数据动态从STT_TICKET中用结构缓冲方式取数据*/
int EGetSttTicketToStruct(struct SttTicketStruct *p,
	struct SttTicketStructIn *pSource);
void mvitem_mfsttticket(struct SttTicketStruct *pi,struct FSttTicketStruct *po);

/*单个结构申明*/
struct RSttTicketStruct{

	struct RSttTicketStruct *pNext;
	char    sCallType[3];		/* CALL_TYPE */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* 用户号码 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	char    sDuration[7];		/* 时长 */
	char    sMsrn[13];		/* MSRN */
	char    sMsc[11];		/* MSC */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* 对端LAC */
	char    sOtherCellID[5];		/* 对端CELL_ID */
	char    sTrunkIn[9];		/* 入中继 */
	char    sTrunkOut[9];		/* 出中继 */
	char    sServiceType[4];		/* 业务类型 */
	char    sServiceCode[5];		/* 业务代码 */
	char    sThirdParty[16];		/* 第三方号码 */
	int     iTicketTypeID;		/* 话单类型 */
	int     iRoamFee;		/* 漫游费 */
	int     iTollFee;		/* 长途费 */
	int     iAddFee;		/* 其他费 */
	char    sHomeAreaCode[6];		/* 用户归属区号 */
	char    sVisitAreaCode[6];		/* 用户拜访区号 */
	char    sCalledCode[6];		/* 对端区号 */
	char    sRoamType[2];		/* 漫游类型 */
	char    sDistanceType[2];		/* 长途类型 */
	int     iTrunkInTypeID;		/* 入中继类型 */
	int     iTrunkOutTypeID;		/* 出中继类型 */
	int     iTrunkInCarrierID;		/* 入中继运营商 */
	int     iTrunkOutCarrierID;		/* 出中继运营商 */
	int     iCallingTypeID;		/* 主叫类型标识 */
	int     iCalledTypeID;		/* 被叫类型标识 */
	int     iCallingCarrierID;		/* 主叫号头运营商 */
	int     iCalledCarrierID;		/* 被叫号头运营商 */
	int     iCallingAreaID;		/* 主叫地区标识 */
	int     iCalledAreaID;		/* 被叫地区标识 */
	char    sSplitRuleID[5];		/* 分离规则标识 */
	char	sBillMode[4];
	char	sSplitType[2];		/*分离类别*/
	char	sEsn[16];
	char	sOppType[2];
	char	sUserType[2];
	char	sTrunkInType[2];
	char	sTrunkOutType[2];
	char	sCal[2];
	char	sScpFlag[2];
	char	sDeformFlag[2];
	char	sReserve[9];

	char	sReserve1[3];
	char	sRoamTariffType[4];
	char	sTollTariffType[4];
	char	sAddTariffType[4];

	char	sSourceID[41];
	char    sRowID[19];		/* 记录索引 */
	struct RSttTicketStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct RSttTicketStructIn{

#ifndef R_STT_TICKET_BUFLEN_IN
#define R_STT_TICKET_BUFLEN_IN		300
#endif

	struct RSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* CALL_TYPE */
	char    asCallType[R_STT_TICKET_BUFLEN_IN][3];
		/* IMSI */
	char    asImsi[R_STT_TICKET_BUFLEN_IN][16];
		/* 用户号码 */
	char    asMsisdn[R_STT_TICKET_BUFLEN_IN][16];
		/* 对端号码 */
	char    asOtherParty[R_STT_TICKET_BUFLEN_IN][25];
		/* 应答时间 */
	char    asStartTime[R_STT_TICKET_BUFLEN_IN][15];
		/* 时长 */
	char    asDuration[R_STT_TICKET_BUFLEN_IN][7];
		/* MSRN */
	char    asMsrn[R_STT_TICKET_BUFLEN_IN][13];
		/* MSC */
	char    asMsc[R_STT_TICKET_BUFLEN_IN][11];
		/* LAC */
	char    asLac[R_STT_TICKET_BUFLEN_IN][5];
		/* CELL_ID */
	char    asCellID[R_STT_TICKET_BUFLEN_IN][5];
		/* 对端LAC */
	char    asOtherLac[R_STT_TICKET_BUFLEN_IN][5];
		/* 对端CELL_ID */
	char    asOtherCellID[R_STT_TICKET_BUFLEN_IN][5];
		/* 入中继 */
	char    asTrunkIn[R_STT_TICKET_BUFLEN_IN][9];
		/* 出中继 */
	char    asTrunkOut[R_STT_TICKET_BUFLEN_IN][9];
		/* 业务类型 */
	char    asServiceType[R_STT_TICKET_BUFLEN_IN][4];
		/* 业务代码 */
	char    asServiceCode[R_STT_TICKET_BUFLEN_IN][5];
		/* 第三方号码 */
	char    asThirdParty[R_STT_TICKET_BUFLEN_IN][16];
		/* 话单类型 */
	int     aiTicketTypeID[R_STT_TICKET_BUFLEN_IN];
		/* 漫游费 */
	int     aiRoamFee[R_STT_TICKET_BUFLEN_IN];
		/* 长途费 */
	int     aiTollFee[R_STT_TICKET_BUFLEN_IN];
		/* 其他费 */
	int     aiAddFee[R_STT_TICKET_BUFLEN_IN];
		/* 用户归属区号 */
	char    asHomeAreaCode[R_STT_TICKET_BUFLEN_IN][6];
		/* 用户拜访区号 */
	char    asVisitAreaCode[R_STT_TICKET_BUFLEN_IN][6];
		/* 对端区号 */
	char    asCalledCode[R_STT_TICKET_BUFLEN_IN][6];
		/* 漫游类型 */
	char    asRoamType[R_STT_TICKET_BUFLEN_IN][2];
		/* 长途类型 */
	char    asDistanceType[R_STT_TICKET_BUFLEN_IN][2];
		/* 入中继类型 */
	int     aiTrunkInTypeID[R_STT_TICKET_BUFLEN_IN];
		/* 出中继类型 */
	int     aiTrunkOutTypeID[R_STT_TICKET_BUFLEN_IN];
		/* 入中继运营商 */
	int     aiTrunkInCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* 出中继运营商 */
	int     aiTrunkOutCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* 主叫类型标识 */
	int     aiCallingTypeID[R_STT_TICKET_BUFLEN_IN];
		/* 被叫类型标识 */
	int     aiCalledTypeID[R_STT_TICKET_BUFLEN_IN];
		/* 主叫号头运营商 */
	int     aiCallingCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* 被叫号头运营商 */
	int     aiCalledCarrierID[R_STT_TICKET_BUFLEN_IN];
		/* 主叫地区标识 */
	int     aiCallingAreaID[R_STT_TICKET_BUFLEN_IN];
		/* 被叫地区标识 */
	int     aiCalledAreaID[R_STT_TICKET_BUFLEN_IN];
		/* 分离规则标识 */
	char    asSplitRuleID[R_STT_TICKET_BUFLEN_IN][5];
	char	asBillMode[R_STT_TICKET_BUFLEN_IN][4];
	char	asSplitType[R_STT_TICKET_BUFLEN_IN][2];
	char	asEsn[R_STT_TICKET_BUFLEN_IN][16];
	char	asOppType[R_STT_TICKET_BUFLEN_IN][2];
	char	asUserType[R_STT_TICKET_BUFLEN_IN][2];
	char	asTrunkInType[R_STT_TICKET_BUFLEN_IN][2];
	char	asTrunkOutType[R_STT_TICKET_BUFLEN_IN][2];
	char	asCal[R_STT_TICKET_BUFLEN_IN][2];
	char	asScpFlag[R_STT_TICKET_BUFLEN_IN][2];
	char	asDeformFlag[R_STT_TICKET_BUFLEN_IN][2];
	char	asReserve[R_STT_TICKET_BUFLEN_IN][9];
	
	char	asReserve1[R_STT_TICKET_BUFLEN_IN][3];
	char	asRoamTariffType[R_STT_TICKET_BUFLEN_IN][4];
	char	asTollTariffType[R_STT_TICKET_BUFLEN_IN][4];
	char	asAddTariffType[R_STT_TICKET_BUFLEN_IN][4];

	char	asSourceID[R_STT_TICKET_BUFLEN_IN][41];
		/* 记录索引 */
	char    asRowID[R_STT_TICKET_BUFLEN_IN][19];
};


/*对数据的取出*/
/*批量数据动态从R_STT_TICKET中用结构缓冲方式取数据*/
int EGetRSttTicketToStruct(struct RSttTicketStruct *p,
	struct RSttTicketStructIn *pSource);
struct USttTicketStruct
{
	int	iTicketTypeID;
	int	iRoamFee;
	int	iTollFee;
	int	iAddFee;
	char	sHomeAreaCode[6];
	char	sVisitAreaCode[6];
	char	sCalledCode[6];
	char	sRoamType[2];
	char	sDistanceType[2];
	int	iTrunkInTypeID;
	int	iTrunkOutTypeID;
	int	iTrunkInCarrierID;
	int	iTrunkOutCarrierID;
	int	iCallingTypeID;
	int	iCalledTypeID;
	int	iCallingCarrierID;
	int	iCalledCarrierID;
	int	iCallingAreaID;
	int	iCalledAreaID;
	char	sSplitRuleID[5];
	char	sTrunkIn[8];
	char	sTrunkOut[8];
	char	sBillMode[4];
	char	sState[2];
	char	sRoamTariffType[4];
	char	sTollTariffType[4];
	char	sAddTariffType[4];
	char	sRowID[19];
	char	sMsisdn[16];
	char	sStartTime[15];
	int	iDuration;
	char	sMsrn[13];
	char	sCal[2];
	char	sUserType[2];
};
struct USttTicketStructUp
{
#ifndef STT_TICKET_BUFLEN_UP
#define STT_TICKET_BUFLEN_UP 	300
#endif
	int	iCurPos;
	char	sTableName[31];
	int	aiTicketTypeID[STT_TICKET_BUFLEN_UP];
	int	aiRoamFee[STT_TICKET_BUFLEN_UP];
	int	aiTollFee[STT_TICKET_BUFLEN_UP];
	int	aiAddFee[STT_TICKET_BUFLEN_UP];
	char	asHomeAreaCode[STT_TICKET_BUFLEN_UP][6];
	char	asVisitAreaCode[STT_TICKET_BUFLEN_UP][6];
	char	asCalledCode[STT_TICKET_BUFLEN_UP][6];
	char	asRoamType[STT_TICKET_BUFLEN_UP][2];
	char	asDistanceType[STT_TICKET_BUFLEN_UP][2];
	int	aiTrunkInTypeID[STT_TICKET_BUFLEN_UP];
	int	aiTrunkOutTypeID[STT_TICKET_BUFLEN_UP];
	int	aiTrunkInCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiTrunkOutCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiCallingTypeID[STT_TICKET_BUFLEN_UP];
	int	aiCalledTypeID[STT_TICKET_BUFLEN_UP];
	int	aiCallingCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiCalledCarrierID[STT_TICKET_BUFLEN_UP];
	int	aiCallingAreaID[STT_TICKET_BUFLEN_UP];
	int	aiCalledAreaID[STT_TICKET_BUFLEN_UP];
	char	asSplitRuleID[STT_TICKET_BUFLEN_UP][5];
	char	asTrunkIn[STT_TICKET_BUFLEN_UP][8];
	char	asTrunkOut[STT_TICKET_BUFLEN_UP][8];
	char	asBillMode[STT_TICKET_BUFLEN_UP][4];
	char	asState[STT_TICKET_BUFLEN_UP][2];

	char	asRoamTariffType[STT_TICKET_BUFLEN_UP][4];
	char	asTollTariffType[STT_TICKET_BUFLEN_UP][4];
	char	asAddTariffType[STT_TICKET_BUFLEN_UP][4];

	char	asRowID[STT_TICKET_BUFLEN_UP][19];
	char	asMsisdn[STT_TICKET_BUFLEN_UP][16];
	char	asStartTime[STT_TICKET_BUFLEN_UP][15];
	int	aiDuration[STT_TICKET_BUFLEN_UP];
	char	asMsrn[STT_TICKET_BUFLEN_UP][13];
	char	asCal[STT_TICKET_BUFLEN_UP][2];		
	char	asUserType[STT_TICKET_BUFLEN_UP][2];
};
int EUpdateStructToUSttTicket(struct USttTicketStruct *p,
	int iUpdateFlag,struct USttTicketStructUp *pTarget);

/*单个结构申明*/
struct UCommTicketStruct{

	struct UCommTicketStruct *pNext;
	char    sFileName[20];		/* 文件名 */
	char    sModule[4];		/* 模块名 */
	char    sAreaCode[6];		/* 区号 */
	char    sState[2];		/* 状态 */
	char    sUpdateDate[15];		/* 更新时间 */
	char	sRowID[19];
	struct UCommTicketStruct *pLoadNext;
};
struct UCommTicketStructUp
{
#ifndef U_COMM_TICKET_BUFLEN_UP
#define U_COMM_TICKET_BUFLEN_UP 	300
#endif
	int	iCurPos;
	char	sTableName[31];
		/* 文件名 */
	char    asFileName[U_COMM_TICKET_BUFLEN_UP][20];
		/* 模块名 */
	char    asModule[U_COMM_TICKET_BUFLEN_UP][4];
		/* 区号 */
	char    asAreaCode[U_COMM_TICKET_BUFLEN_UP][6];
		/* 状态 */
	char    asState[U_COMM_TICKET_BUFLEN_UP][2];
		/* 更新时间 */
	char    asUpdateDate[U_COMM_TICKET_BUFLEN_UP][15];
	char	asRowID[U_COMM_TICKET_BUFLEN_UP][19];
};
int EUpdateStructToUCommTicket(struct UCommTicketStruct *p,
	int iUpdateFlag,struct UCommTicketStructUp *pTarget);

/*******************************************/
struct UpTicketGStruct{
	struct UpTicketGStruct *pNext;
	char    sCallType[3];
	char    sMsisdn[25];
	char    sCalledCode[6];
	char    sOtherParty[25];
	char    sVisitAreaCode[6];
	int     iRoamFee;
	int     iTollFee;
	int     iAddFee;
	int     iDuration;
	char    sStartTime[15];
	char    sHomeAreaCode[6];
	char    sRoamType[2];
	char    sDistanceType[2];
	char    sUserType[2];
	char    sImsi[16];
	char    sMsrn[16];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sThirdParty[16];
	char    sServiceType[4];
	char    sServiceCode[5];
	char    sSupplementCode[16];
	char    sDealDate[15];
	char    sSourceID[21];
	char	sTrunkIn[9];
	char	sTrunkOut[9];
	char	sCityIn[4];
	char	sCityOut[4];
	char	sLandNetType[2];
};
/*输出结构缓冲申明*/
struct UpTicketGStructOut{

#ifndef UP_TICKET_G_BUFLEN_OUT
#define UP_TICKET_G_BUFLEN_OUT		1000
#endif

	struct UpTicketGStructOut *pNext;
	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asCallType[UP_TICKET_G_BUFLEN_OUT][3];
	char    asMsisdn[UP_TICKET_G_BUFLEN_OUT][25];
	char    asCalledCode[UP_TICKET_G_BUFLEN_OUT][6];
	char    asOtherParty[UP_TICKET_G_BUFLEN_OUT][25];
	char    asVisitAreaCode[UP_TICKET_G_BUFLEN_OUT][6];
	int     aiRoamFee[UP_TICKET_G_BUFLEN_OUT];
	int     aiTollFee[UP_TICKET_G_BUFLEN_OUT];
	int     aiAddFee[UP_TICKET_G_BUFLEN_OUT];
	int     aiDuration[UP_TICKET_G_BUFLEN_OUT];
	char    asStartTime[UP_TICKET_G_BUFLEN_OUT][15];
	char    asHomeAreaCode[UP_TICKET_G_BUFLEN_OUT][6];
	char    asRoamType[UP_TICKET_G_BUFLEN_OUT][2];
	char    asDistanceType[UP_TICKET_G_BUFLEN_OUT][2];
	char    asUserType[UP_TICKET_G_BUFLEN_OUT][2];
	char    asImsi[UP_TICKET_G_BUFLEN_OUT][16];
	char    asMsrn[UP_TICKET_G_BUFLEN_OUT][16];
	char    asMsc[UP_TICKET_G_BUFLEN_OUT][16];
	char    asLac[UP_TICKET_G_BUFLEN_OUT][6];
	char    asCellID[UP_TICKET_G_BUFLEN_OUT][6];
	char    asThirdParty[UP_TICKET_G_BUFLEN_OUT][16];
	char    asServiceType[UP_TICKET_G_BUFLEN_OUT][4];
	char    asServiceCode[UP_TICKET_G_BUFLEN_OUT][5];
	char    asSupplementCode[UP_TICKET_G_BUFLEN_OUT][16];
	char    asDealDate[UP_TICKET_G_BUFLEN_OUT][15];
	char    asSourceID[UP_TICKET_G_BUFLEN_OUT][21];
	char	asTrunkIn[UP_TICKET_G_BUFLEN_OUT][9];
	char	asTrunkOut[UP_TICKET_G_BUFLEN_OUT][9];
	char	asCityIn[UP_TICKET_G_BUFLEN_OUT][4];
	char	asCityOut[UP_TICKET_G_BUFLEN_OUT][4];
	char	asLandNetType[UP_TICKET_G_BUFLEN_OUT][2];
};

int EInsertStructToUpTicketG(struct UpTicketGStruct *p,int iInsertFlag,
	struct UpTicketGStructOut *pTarget);
int InsertGsmTicket(char sFileName[],char sTableName[]);
int InsertCdmaTicket(char sFileName[],char sTableName[]);


/*输出结构缓冲申明*/
struct T193TicketStructOut{

#ifndef T193_TICKET_BUFLEN_OUT
#define T193_TICKET_BUFLEN_OUT		300
#endif

	struct T193TicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* CALL_TYPE */
	char    asCallType[T193_TICKET_BUFLEN_OUT][3];
		/* 用户号码 */
	char    asMsisdn[T193_TICKET_BUFLEN_OUT][21];
		/* 对端号码 */
	char    asOtherParty[T193_TICKET_BUFLEN_OUT][21];
		/* 应答时间 */
	char    asStartTime[T193_TICKET_BUFLEN_OUT][15];
		/* 通话时长 */
	char    asDuration[T193_TICKET_BUFLEN_OUT][7];
		/* MSC */
	char    asMsc[T193_TICKET_BUFLEN_OUT][11];
		/* 入中继 */
	char    asTrunkIn[T193_TICKET_BUFLEN_OUT][9];
		/* 出中继 */
	char    asTrunkOut[T193_TICKET_BUFLEN_OUT][9];
		/* 用户区号 */
	char    asCallingAreaCode[T193_TICKET_BUFLEN_OUT][6];
		/* 对端区号 */
	char    asCalledAreaCode[T193_TICKET_BUFLEN_OUT][6];
	
	char    asHomeAreaCode[T193_TICKET_BUFLEN_OUT][6];
		/* 文件归属日期 */
	char    asDealDate[T193_TICKET_BUFLEN_OUT][15];
		/* 文件名 */
	char    asSourceID[T193_TICKET_BUFLEN_OUT][41];
};

/*单个结构申明*/
struct T193TicketStruct{

	struct T193TicketStruct *pNext;
	char    sCallType[3];		/* CALL_TYPE */
	char    sMsisdn[21];		/* 用户号码 */
	char    sOtherParty[21];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	char    sDuration[7];		/* 通话时长 */
	char    sMsc[11];		/* MSC */
	char    sTrunkIn[9];		/* 入中继 */
	char    sTrunkOut[9];		/* 出中继 */
	char    sCallingAreaCode[6];		/* 用户区号 */
	char    sCalledAreaCode[6];		/* 对端区号 */
	char	sHomeAreaCode[6];
	char    sDealDate[15];		/* 文件归属日期 */
	char    sSourceID[41];		/* 文件名 */
	struct T193TicketStruct *pLoadNext;
};



void mvitem_fmt193ticket(struct FT193TicketStruct *pi,struct T193TicketStruct *po);
int EInsertStructToT193Ticket(struct T193TicketStruct *p,
	int iInsertFlag,struct T193TicketStructOut *pTarget);
int Insert193Ticket(char sFileName[],char sTableName[]);


/*输出结构缓冲申明*/
struct SmscTicketStructOut{

#ifndef SMSC_TICKET_BUFLEN_OUT
#define SMSC_TICKET_BUFLEN_OUT		300
#endif

	struct SmscTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 呼叫类型 */
	char    asCallType[SMSC_TICKET_BUFLEN_OUT][3];
		/* 结算城市代码 */
	char    asCityCode[SMSC_TICKET_BUFLEN_OUT][6];
		/* 用户号码 */
	char    asMsisdn[SMSC_TICKET_BUFLEN_OUT][16];
		/* 对端号码 */
	char    asOtherParty[SMSC_TICKET_BUFLEN_OUT][25];
		/* 应答时间 */
	char    asStartTime[SMSC_TICKET_BUFLEN_OUT][15];
		/* 字节数 */
	char    asDuration[SMSC_TICKET_BUFLEN_OUT][7];
		/* 短信中心 */
	char    asMsc[SMSC_TICKET_BUFLEN_OUT][16];
		/* 短信网关 */
	char    asSmsp[SMSC_TICKET_BUFLEN_OUT][16];
		/* 用户类型 */
	char    asUserType[SMSC_TICKET_BUFLEN_OUT][2];
		/* 费用 */
	char    asFee[SMSC_TICKET_BUFLEN_OUT][7];
		/* 业务代码 */
	char    asServiceCode[SMSC_TICKET_BUFLEN_OUT][5];
	
	int	aiTicketTypeID[SMSC_TICKET_BUFLEN_OUT];

	char	asErrCode[SMSC_TICKET_BUFLEN_OUT][5];
	char	asFileName[SMSC_TICKET_BUFLEN_OUT][20];
	char	asModule[SMSC_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[SMSC_TICKET_BUFLEN_OUT][6];
	char	asState[SMSC_TICKET_BUFLEN_OUT][2];
		/* 处理日期 */
	char    asUpdateDate[SMSC_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMSC_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[SMSC_TICKET_BUFLEN_OUT][41];
};
/* 输入结构缓冲申明*/
struct SmscTicketStructIn{

#ifndef SMSC_TICKET_BUFLEN_IN
#define SMSC_TICKET_BUFLEN_IN		300
#endif

	struct SmscTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asCallType[SMSC_TICKET_BUFLEN_IN][3];
	char    asCityCode[SMSC_TICKET_BUFLEN_IN][6];
	char    asMsisdn[SMSC_TICKET_BUFLEN_IN][16];
	char    asOtherParty[SMSC_TICKET_BUFLEN_IN][25];
	char    asStartTime[SMSC_TICKET_BUFLEN_IN][15];
	char    asDuration[SMSC_TICKET_BUFLEN_IN][7];
	char    asMsc[SMSC_TICKET_BUFLEN_IN][16];
	char    asSmsp[SMSC_TICKET_BUFLEN_IN][16];
	char    asUserType[SMSC_TICKET_BUFLEN_IN][2];
	char    asFee[SMSC_TICKET_BUFLEN_IN][7];
	char    asServiceCode[SMSC_TICKET_BUFLEN_IN][5];
	
	int	aiTicketTypeID[SMSC_TICKET_BUFLEN_IN];

	char	asErrCode[SMSC_TICKET_BUFLEN_IN][5];
	char	asFileName[SMSC_TICKET_BUFLEN_IN][20];
	char	asModule[SMSC_TICKET_BUFLEN_IN][4];
	char	asAreaCode[SMSC_TICKET_BUFLEN_IN][6];
	char	asState[SMSC_TICKET_BUFLEN_IN][2];

	char    asUpdateDate[SMSC_TICKET_BUFLEN_IN][15];
	char    asDealDate[SMSC_TICKET_BUFLEN_IN][15];
	char    asSourceID[SMSC_TICKET_BUFLEN_IN][41];
	char	asRowID[SMSC_TICKET_BUFLEN_IN][19];
	
};
/*单个结构申明*/
struct SmscTicketStruct{

	struct SmscTicketStruct *pNext;
	char    sCallType[3];		/* 呼叫类型 */
	char    sCityCode[6];		/* 结算城市代码 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	char    sDuration[7];		/* 字节数 */
	char    sMsc[16];		/* 短信中心 */
	char    sSmsp[16];		/* 短信网关 */
	char    sUserType[2];		/* 用户类型 */
	char    sFee[7];		/* 费用 */
	char    sServiceCode[5];		/* 业务代码 */
	int	iTicketTypeID;
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];		/* 处理日期 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct SmscTicketStruct *pLoadNext;
};

int EInsertStructToSmscTicket(struct SmscTicketStruct *p,
	int iInsertFlag,struct SmscTicketStructOut *pTarget);
void mvitem_fmsmscticket(struct FSmscTicketStruct *pi,int len,
	struct SmscTicketStruct *po);
int InsertSmscTicket(char sFileName[],char sTableName[]);
/*批量数据动态从SMSC_TICKET中用结构缓冲方式取数据*/
int EGetSmscTicketToStruct(struct SmscTicketStruct *p,
	struct SmscTicketStructIn *pSource);
void mvitem_mfsmscticket(struct SmscTicketStruct *pi,struct FSmscTicketStruct *po);

/*输出结构缓冲申明*/
struct SmspTicketStructOut{

#ifndef SMSP_TICKET_BUFLEN_OUT
#define SMSP_TICKET_BUFLEN_OUT		300
#endif

	struct SmspTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 呼叫类型 */
	char    asCallType[SMSP_TICKET_BUFLEN_OUT][3];
		/* 结算城市代码 */
	char    asCityCode[SMSP_TICKET_BUFLEN_OUT][6];
		/* 用户号码 */
	char    asMsisdn[SMSP_TICKET_BUFLEN_OUT][16];
		/* 对端号码 */
	char    asOtherParty[SMSP_TICKET_BUFLEN_OUT][25];
		/* 应答时间 */
	char    asStartTime[SMSP_TICKET_BUFLEN_OUT][15];
		/* 字节数 */
	char    asDuration[SMSP_TICKET_BUFLEN_OUT][7];
		/* 短信中心 */
	char    asMsc[SMSP_TICKET_BUFLEN_OUT][16];
		/* 短信网关 */
	char    asSmsp[SMSP_TICKET_BUFLEN_OUT][16];
		/* 用户类型 */
	char    asUserType[SMSP_TICKET_BUFLEN_OUT][2];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_TICKET_BUFLEN_OUT][13];
		/* SP业务代码 */
	char    asSpServiceCode[SMSP_TICKET_BUFLEN_OUT][11];
		/* SP代码 */
	char    asSpCode[SMSP_TICKET_BUFLEN_OUT][6];
		/* 费用1 */
	char    asFee1[SMSP_TICKET_BUFLEN_OUT][7];
		/* 费用2 */
	char    asFee2[SMSP_TICKET_BUFLEN_OUT][7];
		/* 费用3 */
	char    asFee3[SMSP_TICKET_BUFLEN_OUT][7];
		/* 费用4 */
	char    asFee4[SMSP_TICKET_BUFLEN_OUT][7];
	char    asFee5[SMSP_TICKET_BUFLEN_OUT][9];
	char    asFee6[SMSP_TICKET_BUFLEN_OUT][9];
	int	aiTicketTypeID[SMSP_TICKET_BUFLEN_OUT];
	
	char	asErrCode[SMSP_TICKET_BUFLEN_OUT][5];
	char	asFileName[SMSP_TICKET_BUFLEN_OUT][20];
	char	asModule[SMSP_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[SMSP_TICKET_BUFLEN_OUT][6];
	char	asState[SMSP_TICKET_BUFLEN_OUT][2];

		/* 处理日期 */
	char    asUpdateDate[SMSP_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMSP_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[SMSP_TICKET_BUFLEN_OUT][41];
};


/*单个结构申明*/
struct SmspTicketStruct{

	struct SmspTicketStruct *pNext;
	char    sCallType[3];		/* 呼叫类型 */
	char    sCityCode[6];		/* 结算城市代码 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	char    sDuration[7];		/* 字节数 */
	char    sMsc[16];		/* 短信中心 */
	char    sSmsp[16];		/* 短信网关 */
	char    sUserType[2];		/* 用户类型 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	char    sSpServiceCode[11];		/* SP业务代码 */
	char    sSpCode[6];		/* SP代码 */
	char    sFee1[7];		/* 费用1 */
	char    sFee2[7];		/* 费用2 */
	char    sFee3[7];		/* 费用3 */
	char    sFee4[7];		/* 费用4 */
	char	sFee5[9];
	char	sFee6[9];
	int	iTicketTypeID;

	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];		/* 处理日期 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct SmspTicketStruct *pLoadNext;
};
/* 输入结构缓冲申明*/
struct SmspTicketStructIn{

#ifndef SMSP_TICKET_BUFLEN_IN
#define SMSP_TICKET_BUFLEN_IN		300
#endif

	struct SmspTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 呼叫类型 */
	char    asCallType[SMSP_TICKET_BUFLEN_IN][3];
		/* 结算城市代码 */
	char    asCityCode[SMSP_TICKET_BUFLEN_IN][6];
		/* 用户号码 */
	char    asMsisdn[SMSP_TICKET_BUFLEN_IN][16];
		/* 对端号码 */
	char    asOtherParty[SMSP_TICKET_BUFLEN_IN][25];
		/* 应答时间 */
	char    asStartTime[SMSP_TICKET_BUFLEN_IN][15];
		/* 字节数 */
	char    asDuration[SMSP_TICKET_BUFLEN_IN][7];
		/* 短信中心 */
	char    asMsc[SMSP_TICKET_BUFLEN_IN][16];
		/* 短信网关 */
	char    asSmsp[SMSP_TICKET_BUFLEN_IN][16];
		/* 用户类型 */
	char    asUserType[SMSP_TICKET_BUFLEN_IN][2];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_TICKET_BUFLEN_IN][13];
		/* SP业务代码 */
	char    asSpServiceCode[SMSP_TICKET_BUFLEN_IN][11];
		/* SP代码 */
	char    asSpCode[SMSP_TICKET_BUFLEN_IN][6];
		/* 费用1 */
	char    asFee1[SMSP_TICKET_BUFLEN_IN][7];
		/* 费用2 */
	char    asFee2[SMSP_TICKET_BUFLEN_IN][7];
		/* 费用3 */
	char    asFee3[SMSP_TICKET_BUFLEN_IN][7];
		/* 费用4 */
	char    asFee4[SMSP_TICKET_BUFLEN_IN][7];
	char    asFee5[SMSP_TICKET_BUFLEN_IN][9];	
	char    asFee6[SMSP_TICKET_BUFLEN_IN][9];                 
	int	aiTicketTypeID[SMSP_TICKET_BUFLEN_IN];
	
	char	asErrCode[SMSP_TICKET_BUFLEN_IN][5];
	char	asFileName[SMSP_TICKET_BUFLEN_IN][20];
	char	asModule[SMSP_TICKET_BUFLEN_IN][4];
	char	asAreaCode[SMSP_TICKET_BUFLEN_IN][6];
	char	asState[SMSP_TICKET_BUFLEN_IN][2];

		/* 处理日期 */
	char    asUpdateDate[SMSP_TICKET_BUFLEN_IN][15];
	char    asDealDate[SMSP_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[SMSP_TICKET_BUFLEN_IN][41];
	char	asRowID[SMSP_TICKET_BUFLEN_IN][19];
};
void mvitem_mfsmspticket(struct SmspTicketStruct *pi,struct FSmspTicketStruct *po);
/*批量数据结构缓冲写入SMSP_TICKET*/
int EInsertStructToSmspTicket(struct SmspTicketStruct *p,
	int iInsertFlag,struct SmspTicketStructOut *pTarget);
int InsertSmspTicket(char sFileName[],char sTableName[]);
/*批量数据动态从SMSP_TICKET中用结构缓冲方式取数据*/
int EGetSmspTicketToStruct(struct SmspTicketStruct *p,
	struct SmspTicketStructIn *pSource);
void mvitem_fmsmspticket(struct FSmspTicketStruct *pi,int len,
	struct SmspTicketStruct *po);

/*输出结构缓冲申明*/
struct GprsTicketStructOut{

#ifndef GPRS_TICKET_BUFLEN_OUT
#define GPRS_TICKET_BUFLEN_OUT		300
#endif

	struct GprsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 记录类型 */
	char    asRecordType[GPRS_TICKET_BUFLEN_OUT][3];
		/* 网络侧发起PDP上下文的标志 */
	char    asNiPdp[GPRS_TICKET_BUFLEN_OUT][2];
		/* 用户号码 */
	char    asMsisdn[GPRS_TICKET_BUFLEN_OUT][16];
		/* IMSI号码 */
	char    asImsi[GPRS_TICKET_BUFLEN_OUT][16];
		/* SGSN代码 */
	char    asSgsn[GPRS_TICKET_BUFLEN_OUT][9];
		/* 手机的网络能力 */
	char    asMsnc[GPRS_TICKET_BUFLEN_OUT][2];
		/* LAC */
	char    asLac[GPRS_TICKET_BUFLEN_OUT][5];
		/* 路由区域 */
	char    asRouteArea[GPRS_TICKET_BUFLEN_OUT][5];
		/* CELL_ID */
	char    asCellID[GPRS_TICKET_BUFLEN_OUT][5];
		/* PDP上下文的计费标识 */
	char    asChargingID[GPRS_TICKET_BUFLEN_OUT][9];
		/* GGSN */
	char    asGgsn[GPRS_TICKET_BUFLEN_OUT][9];
		/* APN的网络标识 */
	char    asApnNi[GPRS_TICKET_BUFLEN_OUT][64];
		/* APN的运营商标识 */
	char    asApnOi[GPRS_TICKET_BUFLEN_OUT][38];
		/* PDP类型 */
	char    asPdpType[GPRS_TICKET_BUFLEN_OUT][2];
		/* 终端的PDP地址 */
	char    asServedPdpAddress[GPRS_TICKET_BUFLEN_OUT][17];
		/* SGSN切换标识 */
	char    asSgsnChange[GPRS_TICKET_BUFLEN_OUT][2];
		/* 记录终止原因 */
	char    asCloseCause[GPRS_TICKET_BUFLEN_OUT][2];
		/* "S"，合并成功;"F"需要进一步合并;"N"，合并不正常等 */
	char    asResult[GPRS_TICKET_BUFLEN_OUT][2];
		/* 用户归属区号 */
	char    asHomeAreaCode[GPRS_TICKET_BUFLEN_OUT][10];
		/* 用户拜访 */
	char    asVisitAreaCode[GPRS_TICKET_BUFLEN_OUT][10];
		/* "00" 普通用户;"01" 预付费用户;"02" 卡类用户 */
	char    asUserType[GPRS_TICKET_BUFLEN_OUT][3];
		/* 费用类型 */
	char    asFeeType[GPRS_TICKET_BUFLEN_OUT][3];
		/* 漫游类型 */
	char    asRoamType[GPRS_TICKET_BUFLEN_OUT][2];
		/* 服务类型 */
	char    asServiceType[GPRS_TICKET_BUFLEN_OUT][4];
		/* 应答时间 */
	char    asStartTime[GPRS_TICKET_BUFLEN_OUT][15];
		/* 呼叫持续时间 */
	char    asCallDuration[GPRS_TICKET_BUFLEN_OUT][7];
		/* 资费1 */
	char    asTariff1[GPRS_TICKET_BUFLEN_OUT][2];
		/* 上行流量1 */
	char    asDataFlowup1[GPRS_TICKET_BUFLEN_OUT][11];
		/* 下行流量1 */
	char    asDataFlowdn1[GPRS_TICKET_BUFLEN_OUT][11];
		/* 持续时间1 */
	char    asDuration1[GPRS_TICKET_BUFLEN_OUT][7];
		/* 资费2 */
	char    asTariff2[GPRS_TICKET_BUFLEN_OUT][2];
		/* 上行流量2 */
	char    asDataFlowup2[GPRS_TICKET_BUFLEN_OUT][11];
		/* 下行流量2 */
	char    asDataFlowdn2[GPRS_TICKET_BUFLEN_OUT][11];
		/* 持续时间2 */
	char    asDuration2[GPRS_TICKET_BUFLEN_OUT][7];
		/* 资费3 */
	char    asTariff3[GPRS_TICKET_BUFLEN_OUT][2];
		/* 上行流量3 */
	char    asDataFlowup3[GPRS_TICKET_BUFLEN_OUT][11];
		/* 下行流量3 */
	char    asDataFlowdn3[GPRS_TICKET_BUFLEN_OUT][11];
		/* 持续时长3 */
	char    asDuration3[GPRS_TICKET_BUFLEN_OUT][7];
		/* 资费4 */
	char    asTariff4[GPRS_TICKET_BUFLEN_OUT][2];
		/* 上行流量4 */
	char    asDataFlowup4[GPRS_TICKET_BUFLEN_OUT][11];
		/* 下行流量4 */
	char    asDataFlowdn4[GPRS_TICKET_BUFLEN_OUT][11];
		/* 持续时长4 */
	char    asDuration4[GPRS_TICKET_BUFLEN_OUT][7];
		/* 资费5 */
	char    asTariff5[GPRS_TICKET_BUFLEN_OUT][2];
		/* 上行流量5 */
	char    asDataFlowup5[GPRS_TICKET_BUFLEN_OUT][11];
		/* 下行流量5 */
	char    asDataFlowdn5[GPRS_TICKET_BUFLEN_OUT][11];
		/* 持续时长5 */
	char    asDuration5[GPRS_TICKET_BUFLEN_OUT][7];
		/* 资费6 */
	char    asTariff6[GPRS_TICKET_BUFLEN_OUT][2];
		/* 上行流量6 */
	char    asDataFlowup6[GPRS_TICKET_BUFLEN_OUT][11];
		/* 下行流量6 */
	char    asDataFlowdn6[GPRS_TICKET_BUFLEN_OUT][11];
		/* 持续时长6 */
	char    asDuration6[GPRS_TICKET_BUFLEN_OUT][7];
		/* 基本通信费 */
	char    asCfee[GPRS_TICKET_BUFLEN_OUT][9];
		/* 费用1 */
	char    asFee1[GPRS_TICKET_BUFLEN_OUT][9];
		/* 费用2 */
	char    asFee2[GPRS_TICKET_BUFLEN_OUT][9];
		/* 费用3 */
	char    asFee3[GPRS_TICKET_BUFLEN_OUT][9];
		/* 总费用 */
	char    asTotalFee[GPRS_TICKET_BUFLEN_OUT][10];
	
	int	aiTicketTypeID[GPRS_TICKET_BUFLEN_OUT];
	char	asErrCode[GPRS_TICKET_BUFLEN_OUT][5];
	char	asFileName[GPRS_TICKET_BUFLEN_OUT][20];
	char	asModule[GPRS_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[GPRS_TICKET_BUFLEN_OUT][6];
	char	asState[GPRS_TICKET_BUFLEN_OUT][2];

		/* 处理日期 */
	char    asUpdateDate[GPRS_TICKET_BUFLEN_OUT][15];
	char    asDealDate[GPRS_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[GPRS_TICKET_BUFLEN_OUT][41];
};

/*单个结构申明*/
struct GprsTicketStruct{

	struct GprsTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sNiPdp[2];		/* 网络侧发起PDP上下文的标志 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sImsi[16];		/* IMSI号码 */
	char    sSgsn[9];		/* SGSN代码 */
	char    sMsnc[2];		/* 手机的网络能力 */
	char    sLac[5];		/* LAC */
	char    sRouteArea[5];		/* 路由区域 */
	char    sCellID[5];		/* CELL_ID */
	char    sChargingID[9];		/* PDP上下文的计费标识 */
	char    sGgsn[9];		/* GGSN */
	char    sApnNi[64];		/* APN的网络标识 */
	char    sApnOi[38];		/* APN的运营商标识 */
	char    sPdpType[2];		/* PDP类型 */
	char    sServedPdpAddress[17];		/* 终端的PDP地址 */
	char    sSgsnChange[2];		/* SGSN切换标识 */
	char    sCloseCause[2];		/* 记录终止原因 */
	char    sResult[2];		/* "S"，合并成功;"F"需要进一步合并;"N"，合并不正常等 */
	char    sHomeAreaCode[10];		/* 用户归属区号 */
	char    sVisitAreaCode[10];		/* 用户拜访 */
	char    sUserType[3];		/* "00" 普通用户;"01" 预付费用户;"02" 卡类用户 */
	char    sFeeType[3];		/* 费用类型 */
	char    sRoamType[2];		/* 漫游类型 */
	char    sServiceType[4];		/* 服务类型 */
	char    sStartTime[15];		/* 应答时间 */
	char    sCallDuration[7];		/* 呼叫持续时间 */
	char    sTariff1[2];		/* 资费1 */
	char    sDataFlowup1[11];		/* 上行流量1 */
	char    sDataFlowdn1[11];		/* 下行流量1 */
	char    sDuration1[7];		/* 持续时间1 */
	char    sTariff2[2];		/* 资费2 */
	char    sDataFlowup2[11];		/* 上行流量2 */
	char    sDataFlowdn2[11];		/* 下行流量2 */
	char    sDuration2[7];		/* 持续时间2 */
	char    sTariff3[2];		/* 资费3 */
	char    sDataFlowup3[11];		/* 上行流量3 */
	char    sDataFlowdn3[11];		/* 下行流量3 */
	char    sDuration3[7];		/* 持续时长3 */
	char    sTariff4[2];		/* 资费4 */
	char    sDataFlowup4[11];		/* 上行流量4 */
	char    sDataFlowdn4[11];		/* 下行流量4 */
	char    sDuration4[7];		/* 持续时长4 */
	char    sTariff5[2];		/* 资费5 */
	char    sDataFlowup5[11];		/* 上行流量5 */
	char    sDataFlowdn5[11];		/* 下行流量5 */
	char    sDuration5[7];		/* 持续时长5 */
	char    sTariff6[2];		/* 资费6 */
	char    sDataFlowup6[11];		/* 上行流量6 */
	char    sDataFlowdn6[11];		/* 下行流量6 */
	char    sDuration6[7];		/* 持续时长6 */
	char    sCfee[9];		/* 基本通信费 */
	char    sFee1[9];		/* 费用1 */
	char    sFee2[9];		/* 费用2 */
	char    sFee3[9];		/* 费用3 */
	char    sTotalFee[10];		/* 总费用 */
	int	iTicketTypeID;
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];		/* 处理日期 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct GprsTicketStruct *pLoadNext;
};
/* 输入结构缓冲申明*/
struct GprsTicketStructIn{

#ifndef GPRS_TICKET_BUFLEN_IN
#define GPRS_TICKET_BUFLEN_IN		300
#endif

	struct GprsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 记录类型 */
	char    asRecordType[GPRS_TICKET_BUFLEN_IN][3];
		/* 网络侧发起PDP上下文的标志 */
	char    asNiPdp[GPRS_TICKET_BUFLEN_IN][2];
		/* 用户号码 */
	char    asMsisdn[GPRS_TICKET_BUFLEN_IN][16];
		/* IMSI号码 */
	char    asImsi[GPRS_TICKET_BUFLEN_IN][16];
		/* SGSN代码 */
	char    asSgsn[GPRS_TICKET_BUFLEN_IN][9];
		/* 手机的网络能力 */
	char    asMsnc[GPRS_TICKET_BUFLEN_IN][2];
		/* LAC */
	char    asLac[GPRS_TICKET_BUFLEN_IN][5];
		/* 路由区域 */
	char    asRouteArea[GPRS_TICKET_BUFLEN_IN][5];
		/* CELL_ID */
	char    asCellID[GPRS_TICKET_BUFLEN_IN][5];
		/* PDP上下文的计费标识 */
	char    asChargingID[GPRS_TICKET_BUFLEN_IN][9];
		/* GGSN */
	char    asGgsn[GPRS_TICKET_BUFLEN_IN][9];
		/* APN的网络标识 */
	char    asApnNi[GPRS_TICKET_BUFLEN_IN][64];
		/* APN的运营商标识 */
	char    asApnOi[GPRS_TICKET_BUFLEN_IN][38];
		/* PDP类型 */
	char    asPdpType[GPRS_TICKET_BUFLEN_IN][2];
		/* 终端的PDP地址 */
	char    asServedPdpAddress[GPRS_TICKET_BUFLEN_IN][17];
		/* SGSN切换标识 */
	char    asSgsnChange[GPRS_TICKET_BUFLEN_IN][2];
		/* 记录终止原因 */
	char    asCloseCause[GPRS_TICKET_BUFLEN_IN][2];
		/* "S"，合并成功;"F"需要进一步合并;"N"，合并不正常等 */
	char    asResult[GPRS_TICKET_BUFLEN_IN][2];
		/* 用户归属区号 */
	char    asHomeAreaCode[GPRS_TICKET_BUFLEN_IN][10];
		/* 用户拜访 */
	char    asVisitAreaCode[GPRS_TICKET_BUFLEN_IN][10];
		/* "00" 普通用户;"01" 预付费用户;"02" 卡类用户 */
	char    asUserType[GPRS_TICKET_BUFLEN_IN][3];
		/* 费用类型 */
	char    asFeeType[GPRS_TICKET_BUFLEN_IN][3];
		/* 漫游类型 */
	char    asRoamType[GPRS_TICKET_BUFLEN_IN][2];
		/* 服务类型 */
	char    asServiceType[GPRS_TICKET_BUFLEN_IN][4];
		/* 应答时间 */
	char    asStartTime[GPRS_TICKET_BUFLEN_IN][15];
		/* 呼叫持续时间 */
	char    asCallDuration[GPRS_TICKET_BUFLEN_IN][7];
		/* 资费1 */
	char    asTariff1[GPRS_TICKET_BUFLEN_IN][2];
		/* 上行流量1 */
	char    asDataFlowup1[GPRS_TICKET_BUFLEN_IN][11];
		/* 下行流量1 */
	char    asDataFlowdn1[GPRS_TICKET_BUFLEN_IN][11];
		/* 持续时间1 */
	char    asDuration1[GPRS_TICKET_BUFLEN_IN][7];
		/* 资费2 */
	char    asTariff2[GPRS_TICKET_BUFLEN_IN][2];
		/* 上行流量2 */
	char    asDataFlowup2[GPRS_TICKET_BUFLEN_IN][11];
		/* 下行流量2 */
	char    asDataFlowdn2[GPRS_TICKET_BUFLEN_IN][11];
		/* 持续时间2 */
	char    asDuration2[GPRS_TICKET_BUFLEN_IN][7];
		/* 资费3 */
	char    asTariff3[GPRS_TICKET_BUFLEN_IN][2];
		/* 上行流量3 */
	char    asDataFlowup3[GPRS_TICKET_BUFLEN_IN][11];
		/* 下行流量3 */
	char    asDataFlowdn3[GPRS_TICKET_BUFLEN_IN][11];
		/* 持续时长3 */
	char    asDuration3[GPRS_TICKET_BUFLEN_IN][7];
		/* 资费4 */
	char    asTariff4[GPRS_TICKET_BUFLEN_IN][2];
		/* 上行流量4 */
	char    asDataFlowup4[GPRS_TICKET_BUFLEN_IN][11];
		/* 下行流量4 */
	char    asDataFlowdn4[GPRS_TICKET_BUFLEN_IN][11];
		/* 持续时长4 */
	char    asDuration4[GPRS_TICKET_BUFLEN_IN][7];
		/* 资费5 */
	char    asTariff5[GPRS_TICKET_BUFLEN_IN][2];
		/* 上行流量5 */
	char    asDataFlowup5[GPRS_TICKET_BUFLEN_IN][11];
		/* 下行流量5 */
	char    asDataFlowdn5[GPRS_TICKET_BUFLEN_IN][11];
		/* 持续时长5 */
	char    asDuration5[GPRS_TICKET_BUFLEN_IN][7];
		/* 资费6 */
	char    asTariff6[GPRS_TICKET_BUFLEN_IN][2];
		/* 上行流量6 */
	char    asDataFlowup6[GPRS_TICKET_BUFLEN_IN][11];
		/* 下行流量6 */
	char    asDataFlowdn6[GPRS_TICKET_BUFLEN_IN][11];
		/* 持续时长6 */
	char    asDuration6[GPRS_TICKET_BUFLEN_IN][7];
		/* 基本通信费 */
	char    asCfee[GPRS_TICKET_BUFLEN_IN][9];
		/* 费用1 */
	char    asFee1[GPRS_TICKET_BUFLEN_IN][9];
		/* 费用2 */
	char    asFee2[GPRS_TICKET_BUFLEN_IN][9];
		/* 费用3 */
	char    asFee3[GPRS_TICKET_BUFLEN_IN][9];
		/* 总费用 */
	char    asTotalFee[GPRS_TICKET_BUFLEN_IN][10];
	
	int	aiTicketTypeID[GPRS_TICKET_BUFLEN_IN];
	
	char	asErrCode[GPRS_TICKET_BUFLEN_IN][5];
	char	asFileName[GPRS_TICKET_BUFLEN_IN][20];
	char	asModule[GPRS_TICKET_BUFLEN_IN][4];
	char	asAreaCode[GPRS_TICKET_BUFLEN_IN][6];
	char	asState[GPRS_TICKET_BUFLEN_IN][2];

		/* 处理日期 */
	char    asUpdateDate[GPRS_TICKET_BUFLEN_IN][15];
	char    asDealDate[GPRS_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[GPRS_TICKET_BUFLEN_IN][41];
	char	asRowID[GPRS_TICKET_BUFLEN_IN][19];
};

void mvitem_fmgprsticket(struct FGprsTicketStruct *pi,int len,
	struct GprsTicketStruct *po);
/*批量数据结构缓冲写入GPRS_TICKET*/
int EInsertStructToGprsTicket(struct GprsTicketStruct *p,
	int iInsertFlag,struct GprsTicketStructOut *pTarget);
int InsertGprsTicket(char sFileName[],char sTableName[]);
/*批量数据动态从GPRS_TICKET中用结构缓冲方式取数据*/
int EGetGprsTicketToStruct(struct GprsTicketStruct *p,
	struct GprsTicketStructIn *pSource);
void mvitem_mfgprsticket(struct GprsTicketStruct *pi,struct FGprsTicketStruct *po);

/*输出结构缓冲申明*/
struct GprsTicketNewStructOut{

#ifndef GPRS_TICKET_NEW_BUFLEN_OUT
#define GPRS_TICKET_NEW_BUFLEN_OUT		300
#endif

	struct GprsTicketNewStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
					/*记录类型*/
	char    asRecordType[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*漫游类型*/
	char    asRoamType[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*手机终端的IMSI*/
	char    asImsi[GPRS_TICKET_NEW_BUFLEN_OUT][16];
					/*手机终端的ISDN*/
	char    asMsisdn[GPRS_TICKET_NEW_BUFLEN_OUT][16];
					/*本次会话起始SGSN IP地址*/
	char    asSgsn[GPRS_TICKET_NEW_BUFLEN_OUT][17];
					/*SGSN改变标识*/
	char    asSgsnChange[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*本次会话GGSN IP地址*/
	char    asGgsn[GPRS_TICKET_NEW_BUFLEN_OUT][17];
					/*手机终端PDP IP地址*/
	char    asServedPdpAddress[GPRS_TICKET_NEW_BUFLEN_OUT][17];
					/*接入点网络标识*/
	char    asApnNi[GPRS_TICKET_NEW_BUFLEN_OUT][64];
					/*接入点运营商标识*/
	char    asApnOi[GPRS_TICKET_NEW_BUFLEN_OUT][38];
					/*保留字段*/
	char    asReserv1[GPRS_TICKET_NEW_BUFLEN_OUT][15];
					/*呼叫总时长*/
	int     aiCallDuration[GPRS_TICKET_NEW_BUFLEN_OUT];
					/*局部类型标识符*/
	char    asPartialType[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*中断原因*/
	char    asCloseCause[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*本段会话连接开始时间*/
	char    asStartTime[GPRS_TICKET_NEW_BUFLEN_OUT][15];
					/*网络侧呼叫标志*/
	char    asNiPdp[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*PDP上下文计费标识*/
	char    asChargingID[GPRS_TICKET_NEW_BUFLEN_OUT][11];
					/*位置区号*/
	char    asLac[GPRS_TICKET_NEW_BUFLEN_OUT][6];
					/*小区标识*/
	char    asCellID[GPRS_TICKET_NEW_BUFLEN_OUT][6];
					/*漫游地城市代码*/
	char    asVisitCityCode[GPRS_TICKET_NEW_BUFLEN_OUT][4];
					/*保留字段*/
	char    asReserv2[GPRS_TICKET_NEW_BUFLEN_OUT][11];
					/*漫游地表述*/
	char    asRoamRemark[GPRS_TICKET_NEW_BUFLEN_OUT][11];
					/*手机串号*/
	char    asImei[GPRS_TICKET_NEW_BUFLEN_OUT][20];
					/*下行流量*/
	char    asDataFlowdn[GPRS_TICKET_NEW_BUFLEN_OUT][21];
					/*上行流量*/
	char    asDataFlowup[GPRS_TICKET_NEW_BUFLEN_OUT][21];
					/*计费项目*/
	char    asChargeItem[GPRS_TICKET_NEW_BUFLEN_OUT][2];
					/*计费取整*/
	char    asChargeUnit[GPRS_TICKET_NEW_BUFLEN_OUT][21];
					/*计费业务*/
	char    asChargeOperation[GPRS_TICKET_NEW_BUFLEN_OUT][3];
					/*费用*/
	int     aiTotalFee[GPRS_TICKET_NEW_BUFLEN_OUT];
					/*保留字段*/
	char    asReserv3[GPRS_TICKET_NEW_BUFLEN_OUT][64];
	char    asState[GPRS_TICKET_NEW_BUFLEN_OUT][2];
	char    asDealDate[GPRS_TICKET_NEW_BUFLEN_OUT][15];
	char    asSourceID[GPRS_TICKET_NEW_BUFLEN_OUT][31];
	char    asUpdateDate[GPRS_TICKET_NEW_BUFLEN_OUT][15];
};

/* 输入结构缓冲申明*/
struct GprsTicketNewStructIn{

#ifndef GPRS_TICKET_NEW_BUFLEN_IN
#define GPRS_TICKET_NEW_BUFLEN_IN		300
#endif

	struct GprsTicketNewStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
					/*记录类型*/
	char    asRecordType[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*漫游类型*/
	char    asRoamType[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*手机终端的IMSI*/
	char    asImsi[GPRS_TICKET_NEW_BUFLEN_IN][16];
					/*手机终端的ISDN*/
	char    asMsisdn[GPRS_TICKET_NEW_BUFLEN_IN][16];
					/*本次会话起始SGSN IP地址*/
	char    asSgsn[GPRS_TICKET_NEW_BUFLEN_IN][17];
					/*SGSN改变标识*/
	char    asSgsnChange[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*本次会话GGSN IP地址*/
	char    asGgsn[GPRS_TICKET_NEW_BUFLEN_IN][17];
					/*手机终端PDP IP地址*/
	char    asServedPdpAddress[GPRS_TICKET_NEW_BUFLEN_IN][17];
					/*接入点网络标识*/
	char    asApnNi[GPRS_TICKET_NEW_BUFLEN_IN][64];
					/*接入点运营商标识*/
	char    asApnOi[GPRS_TICKET_NEW_BUFLEN_IN][38];
					/*保留字段*/
	char    asReserv1[GPRS_TICKET_NEW_BUFLEN_IN][15];
					/*呼叫总时长*/
	int     aiCallDuration[GPRS_TICKET_NEW_BUFLEN_IN];
					/*局部类型标识符*/
	char    asPartialType[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*中断原因*/
	char    asCloseCause[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*本段会话连接开始时间*/
	char    asStartTime[GPRS_TICKET_NEW_BUFLEN_IN][15];
					/*网络侧呼叫标志*/
	char    asNiPdp[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*PDP上下文计费标识*/
	char    asChargingID[GPRS_TICKET_NEW_BUFLEN_IN][11];
					/*位置区号*/
	char    asLac[GPRS_TICKET_NEW_BUFLEN_IN][6];
					/*小区标识*/
	char    asCellID[GPRS_TICKET_NEW_BUFLEN_IN][6];
					/*漫游地城市代码*/
	char    asVisitCityCode[GPRS_TICKET_NEW_BUFLEN_IN][4];
					/*保留字段*/
	char    asReserv2[GPRS_TICKET_NEW_BUFLEN_IN][11];
					/*漫游地表述*/
	char    asRoamRemark[GPRS_TICKET_NEW_BUFLEN_IN][11];
					/*手机串号*/
	char    asImei[GPRS_TICKET_NEW_BUFLEN_IN][20];
					/*下行流量*/
	char    asDataFlowdn[GPRS_TICKET_NEW_BUFLEN_IN][21];
					/*上行流量*/
	char    asDataFlowup[GPRS_TICKET_NEW_BUFLEN_IN][21];
					/*计费项目*/
	char    asChargeItem[GPRS_TICKET_NEW_BUFLEN_IN][2];
					/*计费取整*/
	char    asChargeUnit[GPRS_TICKET_NEW_BUFLEN_IN][21];
					/*计费业务*/
	char    asChargeOperation[GPRS_TICKET_NEW_BUFLEN_IN][3];
					/*费用*/
	int     aiTotalFee[GPRS_TICKET_NEW_BUFLEN_IN];
					/*保留字段*/
	char    asReserv3[GPRS_TICKET_NEW_BUFLEN_IN][64];
	char    asState[GPRS_TICKET_NEW_BUFLEN_IN][2];
	char    asDealDate[GPRS_TICKET_NEW_BUFLEN_IN][15];
	char    asSourceID[GPRS_TICKET_NEW_BUFLEN_IN][31];
	char    asUpdateDate[GPRS_TICKET_NEW_BUFLEN_IN][15];
};

/*单个结构申明*/
struct GprsTicketNewStruct{

	struct GprsTicketNewStruct *pNext;
	char    sRecordType[3];				/*记录类型*/
	char    sRoamType[3];				/*漫游类型*/
	char    sImsi[16];				/*手机终端的IMSI*/
	char    sMsisdn[16];				/*手机终端的ISDN*/
	char    sSgsn[17];				/*本次会话起始SGSN IP地址*/
	char    sSgsnChange[2];				/*SGSN改变标识*/
	char    sGgsn[17];				/*本次会话GGSN IP地址*/
	char    sServedPdpAddress[17];				/*手机终端PDP IP地址*/
	char    sApnNi[64];				/*接入点网络标识*/
	char    sApnOi[38];				/*接入点运营商标识*/
	char    sReserv1[15];				/*保留字段*/
	int     iCallDuration;				/*呼叫总时长*/
	char    sPartialType[2];				/*局部类型标识符*/
	char    sCloseCause[3];				/*中断原因*/
	char    sStartTime[15];				/*本段会话连接开始时间*/
	char    sNiPdp[2];				/*网络侧呼叫标志*/
	char    sChargingID[11];				/*PDP上下文计费标识*/
	char    sLac[6];				/*位置区号*/
	char    sCellID[6];				/*小区标识*/
	char    sVisitCityCode[4];				/*漫游地城市代码*/
	char    sReserv2[11];				/*保留字段*/
	char    sRoamRemark[11];				/*漫游地表述*/
	char    sImei[20];				/*手机串号*/
	char    sDataFlowdn[21];				/*下行流量*/
	char    sDataFlowup[21];				/*上行流量*/
	char    sChargeItem[2];				/*计费项目*/
	char    sChargeUnit[21];				/*计费取整*/
	char    sChargeOperation[3];				/*计费业务*/
	int     iTotalFee;				/*费用*/
	char    sReserv3[64];				/*保留字段*/
	char    sState[2];
	char    sDealDate[15];
	char    sSourceID[31];
	char    sUpdateDate[15];
	struct GprsTicketNewStruct *pLoadNext;
};
/*单个文件结构申明*/
struct FGprsTicketNewStruct{

	char    sRecordType[2];				/*记录类型*/
	char    sRoamType[2];				/*漫游类型*/
	char    sImsi[15];				/*手机终端的IMSI*/
	char    sMsisdn[15];				/*手机终端的ISDN*/
	char    sSgsn[16];				/*本次会话起始SGSN IP地址*/
	char    sSgsnChange[1];				/*SGSN改变标识*/
	char    sGgsn[16];				/*本次会话GGSN IP地址*/
	char    sServedPdpAddress[16];				/*手机终端PDP IP地址*/
	char    sApnNi[63];				/*接入点网络标识*/
	char    sApnOi[37];				/*接入点运营商标识*/
	char    sReserv1[14];				/*保留字段*/
	char    sCallDuration[6];				/*呼叫总时长*/
	char    sPartialType[1];				/*局部类型标识符*/
	char    sCloseCause[2];				/*中断原因*/
	char    sStartTime[14];				/*本段会话连接开始时间*/
	char    sNiPdp[1];				/*网络侧呼叫标志*/
	char    sChargingID[10];				/*PDP上下文计费标识*/
	char    sLac[5];				/*位置区号*/
	char    sCellID[5];				/*小区标识*/
	char    sVisitCityCode[3];				/*漫游地城市代码*/
	char    sReserv2[10];				/*保留字段*/
	char    sRoamRemark[10];				/*漫游地表述*/
	char    sImei[19];				/*手机串号*/
	char    sDataFlowdn[20];				/*下行流量*/
	char    sDataFlowup[20];				/*上行流量*/
	char    sChargeItem[1];				/*计费项目*/
	char    sChargeUnit[20];				/*计费取整*/
	char    sChargeOperation[2];				/*计费业务*/
	char    sTotalFee[9];				/*费用*/
	char    sReserv3[63];				/*保留字段*/
	char    sState[1];
	char    sDealDate[14];
	char    sSourceID[30];
	char    sUpdateDate[14];
};
/*批量数据结构缓冲写入GPRS_TICKET_NEW*/
int EInsertStructToGprsTicketNew(struct GprsTicketNewStruct *p,
	int iInsertFlag,struct GprsTicketNewStructOut *pTarget);
/*批量数据动态从GPRS_TICKET_NEW中用结构缓冲方式取数据*/
int EGetGprsTicketNewToStruct(struct GprsTicketNewStruct *p,struct GprsTicketNewStructIn *pSource);
/*数据移动部分*/
void mvitem_fmgprsticketnew(struct FGprsTicketNewStruct *pi,struct GprsTicketNewStruct *po);
/*内存数据移动到文件记录到部分*/
void mvitem_mfgprsticketnew(struct GprsTicketNewStruct *pi,struct FGprsTicketNewStruct *po);
int InsertGprsTicketNew(char sFileName[],char sTableName[]);


/*输出结构缓冲申明*/
struct CdmaTicketStructOut{

#ifndef CDMA_TICKET_BUFLEN_OUT
#define CDMA_TICKET_BUFLEN_OUT		300
#endif

	struct CdmaTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 记录类型 */
	char    asRecordType[CDMA_TICKET_BUFLEN_OUT][3];
		/* 用户号码 */
	char    asMsisdn[CDMA_TICKET_BUFLEN_OUT][16];
		/* IMSI */
	char    asImsi[CDMA_TICKET_BUFLEN_OUT][16];
		/* 电子序列号 */
	char    asEsn[CDMA_TICKET_BUFLEN_OUT][16];
		/* 对端号码 */
	char    asOtherParty[CDMA_TICKET_BUFLEN_OUT][22];
		/* MSRN */
	char    asMsrn[CDMA_TICKET_BUFLEN_OUT][16];
		/* 第三方号码 */
	char    asThirdParty[CDMA_TICKET_BUFLEN_OUT][22];
		/* 应答时间 */
	char    asStartTime[CDMA_TICKET_BUFLEN_OUT][15];
		/* 时长 */
	char    asDuration[CDMA_TICKET_BUFLEN_OUT][7];
		/* 交换机 */
	char    asMsc[CDMA_TICKET_BUFLEN_OUT][11];
		/* LAC */
	char    asLac[CDMA_TICKET_BUFLEN_OUT][6];
		/* CELL_ID */
	char    asCellID[CDMA_TICKET_BUFLEN_OUT][6];
		/* 对端LAC */
	char    asOtherLac[CDMA_TICKET_BUFLEN_OUT][6];
		/* 对端CELL_ID */
	char    asOtherCellID[CDMA_TICKET_BUFLEN_OUT][6];
		/* 增值业务 */
	char    asAppendServiceCode[CDMA_TICKET_BUFLEN_OUT][3];
		/* 结束原因 */
	char    asEndReason[CDMA_TICKET_BUFLEN_OUT][2];
		/* 残缺标志 */
	char    asDeformityFlag[CDMA_TICKET_BUFLEN_OUT][2];
		/* 基本费 */
	char    asRoamFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* 基本计费时长 */
	char    asRoamDuration[CDMA_TICKET_BUFLEN_OUT][7];
		/* 基本多费率标识 */
	char    asRoamRateType[CDMA_TICKET_BUFLEN_OUT][2];
		/* 长途费 */
	char    asTollFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* 长途计费时长 */
	char    asTollDuration[CDMA_TICKET_BUFLEN_OUT][7];
		/* 长途多费率标识 */
	char    asTollFeeType[CDMA_TICKET_BUFLEN_OUT][2];
		/* 信息费 */
	char    asInfoFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* 其他费 */
	char    asOtherFee[CDMA_TICKET_BUFLEN_OUT][9];
		/* 对端归属城市代码 */
	char    asOppCityCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* 对端归属省代码 */
	char    asOppProvCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* 对端所在国代码 */
	char    asOppCountryCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* 长途类型 */
	char    asTollType[CDMA_TICKET_BUFLEN_OUT][2];
		/* 长途网类型 */
	char    asTollNetType[CDMA_TICKET_BUFLEN_OUT][2];
		/* 漫游类型 */
	char    asRoamType[CDMA_TICKET_BUFLEN_OUT][2];
		/* 通话地城市代码 */
	char    asVisitCityCode[CDMA_TICKET_BUFLEN_OUT][4];
		/* 入中继 */
	char    asTrunkIn[CDMA_TICKET_BUFLEN_OUT][9];
		/* 出中继 */
	char    asTrunkOut[CDMA_TICKET_BUFLEN_OUT][9];
		/* 用户类型 */
	char    asUserType[CDMA_TICKET_BUFLEN_OUT][2];
		/* 活动代码 */
	char    asActCode[CDMA_TICKET_BUFLEN_OUT][2];
		/* 业务代码 */
	char    asServiceCode[CDMA_TICKET_BUFLEN_OUT][3];
	char	asCalledType[CDMA_TICKET_BUFLEN_OUT][4];
	char	asHomeAreaCode[CDMA_TICKET_BUFLEN_OUT][11];
	char	asUserType1[CDMA_TICKET_BUFLEN_OUT][3];
	char	asReserve[CDMA_TICKET_BUFLEN_OUT][19];
	char    asUpdateDate[CDMA_TICKET_BUFLEN_OUT][15];
	char    asDealDate[CDMA_TICKET_BUFLEN_OUT][15];
	char    asSourceID[CDMA_TICKET_BUFLEN_OUT][41];
};
/*单个结构申明*/
struct CdmaTicketStruct{

	struct CdmaTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sImsi[16];		/* IMSI */
	char    sEsn[16];		/* 电子序列号 */
	char    sOtherParty[22];		/* 对端号码 */
	char    sMsrn[16];		/* MSRN */
	char    sThirdParty[22];		/* 第三方号码 */
	char    sStartTime[15];		/* 应答时间 */
	char    sDuration[7];		/* 时长 */
	char    sMsc[11];		/* 交换机 */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sOtherLac[6];		/* 对端LAC */
	char    sOtherCellID[6];		/* 对端CELL_ID */
	char    sAppendServiceCode[3];		/* 增值业务 */
	char    sEndReason[2];		/* 结束原因 */
	char    sDeformityFlag[2];		/* 残缺标志 */
	char    sRoamFee[9];		/* 基本费 */
	char    sRoamDuration[7];		/* 基本计费时长 */
	char    sRoamRateType[2];		/* 基本多费率标识 */
	char    sTollFee[9];		/* 长途费 */
	char    sTollDuration[7];		/* 长途计费时长 */
	char    sTollFeeType[2];		/* 长途多费率标识 */
	char    sInfoFee[9];		/* 信息费 */
	char    sOtherFee[9];		/* 其他费 */
	char    sOppCityCode[4];		/* 对端归属城市代码 */
	char    sOppProvCode[4];		/* 对端归属省代码 */
	char    sOppCountryCode[4];		/* 对端所在国代码 */
	char    sTollType[2];		/* 长途类型 */
	char    sTollNetType[2];		/* 长途网类型 */
	char    sRoamType[2];		/* 漫游类型 */
	char    sVisitCityCode[4];		/* 通话地城市代码 */
	char    sTrunkIn[9];		/* 入中继 */
	char    sTrunkOut[9];		/* 出中继 */
	char    sUserType[2];		/* 用户类型 */
	char    sActCode[2];		/* 活动代码 */
	char    sServiceCode[3];		/* 业务代码 */
	char	sCalledType[4];
	char	sHomeAreaCode[11];
	char	sUserType1[3];
	char	sReserve[19];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct CdmaTicketStruct *pLoadNext;
};

int EInsertStructToCdmaTicket(struct CdmaTicketStruct *p,
	int iInsertFlag,struct CdmaTicketStructOut *pTarget);
void mvitem_fmcdmaticketfj(struct FCdmaTicketFjStruct *pi,struct CdmaTicketStruct *po);
void mvitem_fmcdmaticketxj(struct FCdmaTicketXjStruct *pi,struct CdmaTicketStruct *po);
void mvitem_fmcdmaticket(struct FCdmaTicketStruct *pi,struct CdmaTicketStruct *po);
int InsertCdmaBillTicket(char sFileName[],char sTableName[]);

/*输出结构缓冲申明*/
struct Cdma1xTicketStructOut{

#ifndef CDMA1X_TICKET_BUFLEN_OUT
#define CDMA1X_TICKET_BUFLEN_OUT		300
#endif

	struct Cdma1xTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 记录类型 */
	char    asRecordType[CDMA1X_TICKET_BUFLEN_OUT][3];
		/* 序列号码 */
	char    asSeqNumber[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户手机号 */
	char    asMdn[CDMA1X_TICKET_BUFLEN_OUT][21];
		/* MSISDN */
	char    asMsisdn[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* 手机设备串号 */
	char    asEsn[CDMA1X_TICKET_BUFLEN_OUT][20];
		/* IP */
	char    asIp[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* 用户数据业务账号 */
	char    asNai[CDMA1X_TICKET_BUFLEN_OUT][65];
		/* 用户类别 */
	char    asUserType[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* 联通城市代码 */
	char    asNaiAreaCode[CDMA1X_TICKET_BUFLEN_OUT][4];
		/* 漫游类别:0＝本地；1＝省际漫入；2＝省际漫出;3＝国际漫入；4＝国际漫出（缺省：按
IMSI 进行漫游判断） */
	char    asRoamType[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* IP类别 */
	char    asIpTechType[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* 标识一个会话连接 */
	char    asAccountSessionID[CDMA1X_TICKET_BUFLEN_OUT][9];
		/* 标识一个PPP 连接 */
	char    asCorrelationID[CDMA1X_TICKET_BUFLEN_OUT][9];
		/* HA 的IP 地址 */
	char    asHaip[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* pdsnip */
	char    asPdsnip[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* 使用PCF 地址 */
	char    asPcfip[CDMA1X_TICKET_BUFLEN_OUT][16];
		/* SID NID BSC ID */
	char    asBsid[CDMA1X_TICKET_BUFLEN_OUT][13];
		/* 用户所在区域标识 */
	char    asUzid[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 固定为33 */
	char    asServiceOption[CDMA1X_TICKET_BUFLEN_OUT][3];
		/* 强制隧道类型 */
	char    asCompulsoryTunnel[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* 发送Accounting stop 的原因 */
	char    asEndRelease[CDMA1X_TICKET_BUFLEN_OUT][2];
		/* 发送给用户的字节数 */
	char    asDataCountTermination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户发起的字节数 */
	char    asDataCountOrigination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 被PDSN 丢弃的坏帧 */
	char    asBadFrameCount[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 会话开始的时间点 */
	char    asStartTime[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* 会话结束的时间点 */
	char    asStopTime[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* 会话时长 */
	char    asActiveTime[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 转换次数 */
	char    asActionCount[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户SDB接收字节数 */
	char    asSdbCountTermination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户SDB发送字节数 */
	char    asSdbCountOrigination[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户接收SDB次数 */
	char    asSdbTerminationnum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户发送SDB次数 */
	char    asSdbOriginationnum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* PDSN 收到的HDLC */
	char    asPdsnReceiveNum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户接收MIP 信令字节 */
	char    asMipReceiveNum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 用户发送MIP 信令字节 */
	char    asMipSendNum[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* IP 网络用户质量等级码 */
	char    asIpqos[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 无线链路质量等级码 */
	char    asAirlinkqos[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 基本费 */
	int     aiBaseCharge[CDMA1X_TICKET_BUFLEN_OUT];
		/* 流量费 */
	int     aiFluxCharge[CDMA1X_TICKET_BUFLEN_OUT];
		/* 其他费用 */
	int     aiOtherCharge[CDMA1X_TICKET_BUFLEN_OUT];
		/* 归属地城市代码 */
	char    asHomeCountryCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* 归属地运营商代码 */
	char    asHomeOperatorCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* 漫游地城市代码 */
	char    asVisitCountryCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* 漫游地运营商代码 */
	char    asVisitOperatoCode[CDMA1X_TICKET_BUFLEN_OUT][6];
		/* 资费规则标识 */
	char    asRatingRuleID[CDMA1X_TICKET_BUFLEN_OUT][9];
		/* 系统保留 */
	char    asNoused1[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 系统保留2 */
	char    asNoused2[CDMA1X_TICKET_BUFLEN_OUT][11];
		/* 系统保留3 */
	char    asNoused3[CDMA1X_TICKET_BUFLEN_OUT][11];
	
	int	aiTicketTypeID[CDMA1X_TICKET_BUFLEN_OUT];
	char	asHomeAreaCode[CDMA1X_TICKET_BUFLEN_OUT][6];
	char	asErrCode[CDMA1X_TICKET_BUFLEN_OUT][5];
	char	asFileName[CDMA1X_TICKET_BUFLEN_OUT][20];
	char	asModule[CDMA1X_TICKET_BUFLEN_OUT][4];
	char	asAreaCode[CDMA1X_TICKET_BUFLEN_OUT][6];
	char	asState[CDMA1X_TICKET_BUFLEN_OUT][2];

		/* 更新时间 */
	char    asUpdateDate[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* 处理时间 */
	char    asDealDate[CDMA1X_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[CDMA1X_TICKET_BUFLEN_OUT][41];
};
/*单个结构申明*/
struct Cdma1xTicketStruct{

	struct Cdma1xTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sSeqNumber[11];		/* 序列号码 */
	char    sMdn[21];		/* 用户手机号 */
	char    sMsisdn[16];		/* MSISDN */
	char    sEsn[20];		/* 手机设备串号 */
	char    sIp[16];		/* IP */
	char    sNai[65];		/* 用户数据业务账号 */
	char    sUserType[2];		/* 用户类别 */
	char    sNaiAreaCode[4];		/* 联通城市代码 */
	char    sRoamType[2];		/* 漫游类别:0＝本地；1＝省际漫入；2＝省际漫出;3＝国际漫入；
4＝国际漫出（缺省：按IMSI 进行漫游判断） */
	char    sIpTechType[2];		/* IP类别 */
	char    sAccountSessionID[9];		/* 标识一个会话连接 */
	char    sCorrelationID[9];		/* 标识一个PPP 连接 */
	char    sHaip[16];		/* HA 的IP 地址 */
	char    sPdsnip[16];		/* pdsnip */
	char    sPcfip[16];		/* 使用PCF 地址 */
	char    sBsid[13];		/* SID NID BSC ID */
	char    sUzid[11];		/* 用户所在区域标识 */
	char    sServiceOption[3];		/* 固定为33 */
	char    sCompulsoryTunnel[2];		/* 强制隧道类型 */
	char    sEndRelease[2];		/* 发送Accounting stop 的原因 */
	char    sDataCountTermination[11];		/* 发送给用户的字节数 */
	char    sDataCountOrigination[11];		/* 用户发起的字节数 */
	char    sBadFrameCount[11];		/* 被PDSN 丢弃的坏帧 */
	char    sStartTime[15];		/* 会话开始的时间点 */
	char    sStopTime[15];		/* 会话结束的时间点 */
	char    sActiveTime[11];		/* 会话时长 */
	char    sActionCount[11];		/* 转换次数 */
	char    sSdbCountTermination[11];		/* 用户SDB接收字节数 */
	char    sSdbCountOrigination[11];		/* 用户SDB发送字节数 */
	char    sSdbTerminationnum[11];		/* 用户接收SDB次数 */
	char    sSdbOriginationnum[11];		/* 用户发送SDB次数 */
	char    sPdsnReceiveNum[11];		/* PDSN 收到的HDLC */
	char    sMipReceiveNum[11];		/* 用户接收MIP 信令字节 */
	char    sMipSendNum[11];		/* 用户发送MIP 信令字节 */
	char    sIpqos[11];		/* IP 网络用户质量等级码 */
	char    sAirlinkqos[11];		/* 无线链路质量等级码 */
	int     iBaseCharge;		/* 基本费 */
	int     iFluxCharge;		/* 流量费 */
	int     iOtherCharge;		/* 其他费用 */
	char    sHomeCountryCode[6];		/* 归属地城市代码 */
	char    sHomeOperatorCode[6];		/* 归属地运营商代码 */
	char    sVisitCountryCode[6];		/* 漫游地城市代码 */
	char    sVisitOperatoCode[6];		/* 漫游地运营商代码 */
	char    sRatingRuleID[9];		/* 资费规则标识 */
	char    sNoused1[11];		/* 系统保留 */
	char    sNoused2[11];		/* 系统保留2 */
	char    sNoused3[11];		/* 系统保留3 */

	int	iTicketTypeID;
	char	sHomeAreaCode[6];
	char	sErrCode[5];
	char	sFileName[20];
	char	sModule[4];
	char	sAreaCode[6];
	char	sState[2];

	char    sUpdateDate[15];		/* 更新时间 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct Cdma1xTicketStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct Cdma1xTicketStructIn{

#ifndef CDMA1X_TICKET_BUFLEN_IN
#define CDMA1X_TICKET_BUFLEN_IN		300
#endif

	struct Cdma1xTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 记录类型 */
	char    asRecordType[CDMA1X_TICKET_BUFLEN_IN][3];
		/* 流水号 */
	char    asSeqNumber[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 用户手机号 */
	char    asMdn[CDMA1X_TICKET_BUFLEN_IN][21];
		/* 用户号码 */
	char    asMsisdn[CDMA1X_TICKET_BUFLEN_IN][16];
		/* 手机设备串号 */
	char    asEsn[CDMA1X_TICKET_BUFLEN_IN][20];
		/* IP */
	char    asIp[CDMA1X_TICKET_BUFLEN_IN][16];
		/* 用户数据业务账号 */
	char    asNai[CDMA1X_TICKET_BUFLEN_IN][65];
		/* 用户类别 */
	char    asUserType[CDMA1X_TICKET_BUFLEN_IN][2];
		/* 联通城市代码 */
	char    asNaiAreaCode[CDMA1X_TICKET_BUFLEN_IN][4];
		/* 漫游类别:0＝本地；1＝省际漫入；2＝省际漫出;3＝国际漫入；4＝国际漫出（缺省：按IMSI 进行漫游判断） */
	char    asRoamType[CDMA1X_TICKET_BUFLEN_IN][2];
		/* IP类别 */
	char    asIpTechType[CDMA1X_TICKET_BUFLEN_IN][2];
		/* 标识一个会话连接 */
	char    asAccountSessionID[CDMA1X_TICKET_BUFLEN_IN][9];
		/* 标识一个PPP 连接 */
	char    asCorrelationID[CDMA1X_TICKET_BUFLEN_IN][9];
		/* HA 的IP 地址 */
	char    asHaip[CDMA1X_TICKET_BUFLEN_IN][16];
		/* pdsnip */
	char    asPdsnip[CDMA1X_TICKET_BUFLEN_IN][16];
		/* 使用PCF 地址 */
	char    asPcfip[CDMA1X_TICKET_BUFLEN_IN][16];
		/* SID NID BSC ID */
	char    asBsid[CDMA1X_TICKET_BUFLEN_IN][13];
		/* 用户所在区域标识 */
	char    asUzid[CDMA1X_TICKET_BUFLEN_IN][11];
		/* CDMA 1X 数据业务为33 */
	char    asServiceOption[CDMA1X_TICKET_BUFLEN_IN][3];
		/* 强制隧道类型 */
	char    asCompulsoryTunnel[CDMA1X_TICKET_BUFLEN_IN][2];
		/* 发送Accounting stop 的原因 */
	char    asEndRelease[CDMA1X_TICKET_BUFLEN_IN][2];
		/* 发送给用户的字节数 */
	char    asDataCountTermination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 用户发起的字节数 */
	char    asDataCountOrigination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 被PDSN 丢弃的坏帧 */
	char    asBadFrameCount[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 会话开始的时间点 */
	char    asStartTime[CDMA1X_TICKET_BUFLEN_IN][15];
		/* 会话结束的时间点 */
	char    asStopTime[CDMA1X_TICKET_BUFLEN_IN][15];
		/* PCF 端统计的会话时长 */
	char    asActiveTime[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 状态转换的次数 */
	char    asActionCount[CDMA1X_TICKET_BUFLEN_IN][11];
		/* SDB接收字节数 */
	char    asSdbCountTermination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* SDB发送字节数 */
	char    asSdbCountOrigination[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 接收SDB次数 */
	char    asSdbTerminationnum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 发送SDB次数 */
	char    asSdbOriginationnum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* PDSN 收到的HDLC */
	char    asPdsnReceiveNum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 用户接收到的MIP 信令字节数 */
	char    asMipReceiveNum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 用户发送的MIP 信令字节数 */
	char    asMipSendNum[CDMA1X_TICKET_BUFLEN_IN][11];
		/* IP 网络的用户质量等级码 */
	char    asIpqos[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 无线链路质量等级码 */
	char    asAirlinkqos[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 基本费 */
	int     aiBaseCharge[CDMA1X_TICKET_BUFLEN_IN];
		/* 流量费 */
	int     aiFluxCharge[CDMA1X_TICKET_BUFLEN_IN];
		/* 其他费用 */
	int     aiOtherCharge[CDMA1X_TICKET_BUFLEN_IN];
		/* 归属地城市代码 */
	char    asHomeCountryCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* 归属地运营商代码 */
	char    asHomeOperatorCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* 漫游地城市代码 */
	char    asVisitCountryCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* 漫游地运营商代码 */
	char    asVisitOperatoCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* 资费规则标识 */
	char    asRatingRuleID[CDMA1X_TICKET_BUFLEN_IN][9];
		/* 系统保留 */
	char    asNoused1[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 系统保留2 */
	char    asNoused2[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 系统保留3 */
	char    asNoused3[CDMA1X_TICKET_BUFLEN_IN][11];
		/* 话单类型 */
	int     aiTicketTypeID[CDMA1X_TICKET_BUFLEN_IN];
		/* 用户归属 */
	char    asHomeAreaCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* 错误代码 */
	char    asErrCode[CDMA1X_TICKET_BUFLEN_IN][5];
		/* 文件名 */
	char    asFileName[CDMA1X_TICKET_BUFLEN_IN][20];
		/* 模块名 */
	char    asModule[CDMA1X_TICKET_BUFLEN_IN][4];
		/* 区号 */
	char    asAreaCode[CDMA1X_TICKET_BUFLEN_IN][6];
		/* 状态 */
	char    asState[CDMA1X_TICKET_BUFLEN_IN][2];
		/* 话单更新时间 */
	char    asUpdateDate[CDMA1X_TICKET_BUFLEN_IN][15];
		/* 话单处理时间 */
	char    asDealDate[CDMA1X_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[CDMA1X_TICKET_BUFLEN_IN][41];
	char	asRowID[CDMA1X_TICKET_BUFLEN_IN][19];
};

int EInsertStructToCdma1xTicket(struct Cdma1xTicketStruct *p,
	int iInsertFlag,struct Cdma1xTicketStructOut *pTarget);
void mvitem_fmcdma1xticket(struct FCdma1xTicketStruct *pi,int len,
	struct Cdma1xTicketStruct *po);
int InsertCdma1xTicket(char sFileName[],char sTableName[]);
/*批量数据动态从CDMA1X_TICKET中用结构缓冲方式取数据*/
int EGetCdma1xTicketToStruct(struct Cdma1xTicketStruct *p,
	struct Cdma1xTicketStructIn *pSource);
void mvitem_mfcdma1xticket(struct Cdma1xTicketStruct *pi,
	struct FCdma1xTicketStruct *po);


#define SCP_NIL		"0"	/*非智能网*/	
#define SCP_PPC		"1"     /*PPC*/
#define SCP_WVPN	"2"     /*WVPN*/
#define SCP_VOIP	"3"     /*VOIP*/
#define DEFORM_NORMAL	"0"     /*正常话单*/
#define DEFORM_BGN	"1"     /*开始话单*/
#define DEFORM_MID	"2"     /*中间话单*/
#define DEFORM_END	"3"     /*结束话单*/
#define STATE_NORMAL	"0"     /*正常或待合并*/
#define STATE_NOBILL	"1"     /*合并后待重批价*/
#define STATE_BILLED	"2"     /*已重批*/
#define STATE_COLEND	"3"     /*合并结束已出文件*/
#define STATE_MID	"4"     /*出文件中*/
#define STATE_RATED	"5"	/*已重出文件*/




/*输出结构缓冲申明*/
struct GsmRateTicketStructOut{

#ifndef GSM_TICKET_RATE_BUFLEN_OUT
#define GSM_TICKET_RATE_BUFLEN_OUT		300
#endif

	struct GsmRateTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单序列号 */
	char    asTicketID[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 手机号码 */
	char    asMsisdn[GSM_TICKET_RATE_BUFLEN_OUT][16];
		/* Imsi号码 */
	char    asImsi[GSM_TICKET_RATE_BUFLEN_OUT][16];
		/* 城市代码 */
	char    asCityCode[GSM_TICKET_RATE_BUFLEN_OUT][5];
		/* 月份 */
	char    asMonth[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* 计费月份 */
	char    asBillMonth[GSM_TICKET_RATE_BUFLEN_OUT][7];
		/* 呼叫类型 */
	char    asCallType[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* 呼叫日期 */
	char    asStartTime[GSM_TICKET_RATE_BUFLEN_OUT][15];
		/* 结束原因 */
	char    asEndReason[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 残缺标志 */
	char    asDeformFlag[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 对端号码 */
	char    asOtherParty[GSM_TICKET_RATE_BUFLEN_OUT][22];
		/* 对方地区代码 */
	char    asCalledCode[GSM_TICKET_RATE_BUFLEN_OUT][5];
		/* 通话时长 */
	int     aiDuration[GSM_TICKET_RATE_BUFLEN_OUT];
		/* 交换机代码 */
	char    asMsc[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 基站号 */
	char    asCellID[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* 对方基站号 */
	char    asOtherCellID[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* 入中继 */
	char    asTrunkIn[GSM_TICKET_RATE_BUFLEN_OUT][8];
		/* 出中继 */
	char    asTrunkOut[GSM_TICKET_RATE_BUFLEN_OUT][8];
		/* 长途类型 */
	char    asTollType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 漫游类型 */
	char    asRoamType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 长途网类型 */
	char    asTollNetType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 增值业务 */
	char    asValueAddBusi[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* 闭合用户群ID */
	char    asGroupID[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* 双方是同一闭合用户群 */
	char    asSameGroupFlag[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 所属局 */
	char    asHomeProvCode[GSM_TICKET_RATE_BUFLEN_OUT][4];
		/* 漫游局 */
	char    asVisitCityCode[GSM_TICKET_RATE_BUFLEN_OUT][4];
		/* B号码 */
	char    asThirdParty[GSM_TICKET_RATE_BUFLEN_OUT][16];
		/* 通话/承载业务类别 */
	char    asBusiType[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 通话/承载业务代码 */
	char    asBusiCode[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* 基本费 */
	char    asBaseFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 长途费 */
	char    asTollFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 长附费 */
	char    asTollAddFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 其他费 */
	char    asOtherFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 漫游费 */
	char    asRoamFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 附加费 */
	char    asAddFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 优惠基本费 */
	char    asDisctBaseFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 优惠长途费 */
	char    asDisctTollFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 优惠长附费 */
	char    asDisctTollAddFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 优惠其他费 */
	char    asDisctOtherFee[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* 附加业务活动码 */
	char    asSupplementActiveCode[GSM_TICKET_RATE_BUFLEN_OUT][2];
		/* 附加业务码 */
	char    asSupplementCode[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* 文件号 */
	char    asFileSeq[GSM_TICKET_RATE_BUFLEN_OUT][9];
		/* Called_type */
	char    asCalledType[GSM_TICKET_RATE_BUFLEN_OUT][4];
		/* Home_area_code */
	char    asHomeAreaCode[GSM_TICKET_RATE_BUFLEN_OUT][11];
		/* lac */
	char    asLac[GSM_TICKET_RATE_BUFLEN_OUT][6];
		/* User_type */
	char    asUserType[GSM_TICKET_RATE_BUFLEN_OUT][3];
		/* 保留字段 */
	char    asReserve[GSM_TICKET_RATE_BUFLEN_OUT][19];
	char    asUpdateDate[GSM_TICKET_RATE_BUFLEN_OUT][15];
	char    asDealDate[GSM_TICKET_RATE_BUFLEN_OUT][15];
	char    asSourceID[GSM_TICKET_RATE_BUFLEN_OUT][41];
};

/*单个结构申明*/
struct GsmRateTicketStruct{

	struct GsmRateTicketStruct *pNext;
	char    sTicketID[11];		/* 话单序列号 */
	char    sMsisdn[16];		/* 手机号码 */
	char    sImsi[16];		/* Imsi号码 */
	char    sCityCode[5];		/* 城市代码 */
	char    sMonth[3];		/* 月份 */
	char    sBillMonth[7];		/* 计费月份 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sStartTime[15];		/* 呼叫日期 */
	char    sEndReason[2];		/* 结束原因 */
	char    sDeformFlag[2];		/* 残缺标志 */
	char    sOtherParty[22];		/* 对端号码 */
	char    sCalledCode[5];		/* 对方地区代码 */
	int     iDuration;		/* 通话时长 */
	char    sMsc[11];		/* 交换机代码 */
	char    sCellID[6];		/* 基站号 */
	char    sOtherCellID[6];		/* 对方基站号 */
	char    sTrunkIn[8];		/* 入中继 */
	char    sTrunkOut[8];		/* 出中继 */
	char    sTollType[2];		/* 长途类型 */
	char    sRoamType[2];		/* 漫游类型 */
	char    sTollNetType[2];		/* 长途网类型 */
	char    sValueAddBusi[3];		/* 增值业务 */
	char    sGroupID[6];		/* 闭合用户群ID */
	char    sSameGroupFlag[2];		/* 双方是同一闭合用户群 */
	char    sHomeProvCode[4];		/* 所属局 */
	char    sVisitCityCode[4];		/* 漫游局 */
	char    sThirdParty[16];		/* B号码 */
	char    sBusiType[2];		/* 通话/承载业务类别 */
	char    sBusiCode[3];		/* 通话/承载业务代码 */
	char    sBaseFee[11];		/* 基本费 */
	char    sTollFee[11];		/* 长途费 */
	char    sTollAddFee[11];		/* 长附费 */
	char    sOtherFee[11];		/* 其他费 */
	char    sRoamFee[11];		/* 漫游费 */
	char    sAddFee[11];		/* 附加费 */
	char    sDisctBaseFee[11];		/* 优惠基本费 */
	char    sDisctTollFee[11];		/* 优惠长途费 */
	char    sDisctTollAddFee[11];		/* 优惠长附费 */
	char    sDisctOtherFee[11];		/* 优惠其他费 */
	char    sSupplementActiveCode[2];		/* 附加业务活动码 */
	char    sSupplementCode[3];		/* 附加业务码 */
	char    sFileSeq[9];		/* 文件号 */
	char    sCalledType[4];		/* Called_type */
	char    sHomeAreaCode[11];		/* Home_area_code */
	char    sLac[6];		/* lac */
	char    sUserType[3];		/* User_type */
	char    sReserve[19];		/* 保留字段 */
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct GsmRateTicketStruct *pLoadNext;
};

int EInsertStructToGsmRateTicket(struct GsmRateTicketStruct *p,
	int iInsertFlag,struct GsmRateTicketStructOut *pTarget);
void mvitem_fmgsmrateticket(struct FGsmRateTicketStruct *pi,
	struct GsmRateTicketStruct *po);
int InsertGsmBillTicket(char sFileName[],char sTableName[]);

/*输出结构缓冲申明*/
struct SmsRateTicketStructOut{

#ifndef SMS_RATE_TICKET_BUFLEN_OUT
#define SMS_RATE_TICKET_BUFLEN_OUT		300
#endif

	struct SmsRateTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[SMS_RATE_TICKET_BUFLEN_OUT][3];
	char    asCallType[SMS_RATE_TICKET_BUFLEN_OUT][2];
	char    asMsisdn[SMS_RATE_TICKET_BUFLEN_OUT][14];
	char    asUserType[SMS_RATE_TICKET_BUFLEN_OUT][2];
	char    asHomeAreaCode[SMS_RATE_TICKET_BUFLEN_OUT][5];
	char    asCallingNbr[SMS_RATE_TICKET_BUFLEN_OUT][14];
	char    asCalledNbr[SMS_RATE_TICKET_BUFLEN_OUT][14];
	char    asBusiCode[SMS_RATE_TICKET_BUFLEN_OUT][11];
	char    asFeeType[SMS_RATE_TICKET_BUFLEN_OUT][2];
	int     aiMsgLen[SMS_RATE_TICKET_BUFLEN_OUT];
	int     aiMsgCnt[SMS_RATE_TICKET_BUFLEN_OUT];
	char    asStartTime[SMS_RATE_TICKET_BUFLEN_OUT][15];
	int     aiBaseFee[SMS_RATE_TICKET_BUFLEN_OUT];
	int     aiInfoFee[SMS_RATE_TICKET_BUFLEN_OUT];
	int     aiInfoFeeType[SMS_RATE_TICKET_BUFLEN_OUT];
	char    asOriFileName[SMS_RATE_TICKET_BUFLEN_OUT][21];
	char    asReserve[SMS_RATE_TICKET_BUFLEN_OUT][21];
	char    asUpdateDate[SMS_RATE_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMS_RATE_TICKET_BUFLEN_OUT][15];
	char    asSourceID[SMS_RATE_TICKET_BUFLEN_OUT][41];
};

/*单个结构申明*/
struct SmsRateTicketStruct{

	struct SmsRateTicketStruct *pNext;
	char    sRecordType[3];
	char    sCallType[2];
	char    sMsisdn[14];
	char    sUserType[2];
	char    sHomeAreaCode[5];
	char    sCallingNbr[14];
	char    sCalledNbr[14];
	char    sBusiCode[11];
	char    sFeeType[2];
	int     iMsgLen;
	int     iMsgCnt;
	char    sStartTime[15];
	int     iBaseFee;
	int     iInfoFee;
	int     iInfoFeeType;
	char    sOriFileName[21];
	char    sReserve[21];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct SmsRateTicketStruct *pLoadNext;
};

void mvitem_fmsmsrateticket(struct FSmsRateTicketStruct *pi,
	struct SmsRateTicketStruct *po);
/*批量数据结构缓冲写入SMS_RATE_TICKET*/
int EInsertStructToSmsRateTicket(struct SmsRateTicketStruct *p,
	int iInsertFlag,struct SmsRateTicketStructOut *pTarget);
int InsertSmsBillTicket(char sFileName[],char sTableName[]);



/*输出结构缓冲申明*/
struct SmsupTicketStructOut{

#ifndef SMSUP_TICKET_BUFLEN_OUT
#define SMSUP_TICKET_BUFLEN_OUT		300
#endif

	struct SmsupTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[SMSUP_TICKET_BUFLEN_OUT][3];
	char    asMsgType[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asSpProvCode[SMSUP_TICKET_BUFLEN_OUT][4];
	int     aiSmg[SMSUP_TICKET_BUFLEN_OUT];
	int     aiSpCode[SMSUP_TICKET_BUFLEN_OUT];
	int     aiFwSmg[SMSUP_TICKET_BUFLEN_OUT];
	char    asFwSmgProv[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asStartTime[SMSUP_TICKET_BUFLEN_OUT][15];
	char    asMsgCnt[SMSUP_TICKET_BUFLEN_OUT][11];
	char    asBaseFee[SMSUP_TICKET_BUFLEN_OUT][13];
	char    asInfoFee[SMSUP_TICKET_BUFLEN_OUT][13];
	char    asHomeProvCode[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asFileType[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asReserve1[SMSUP_TICKET_BUFLEN_OUT][31];
	char    asState[SMSUP_TICKET_BUFLEN_OUT][4];
	char    asUpdateDate[SMSUP_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SMSUP_TICKET_BUFLEN_OUT][15];
	char    asSourceID[SMSUP_TICKET_BUFLEN_OUT][41];
	char    asCurFileName[SMSUP_TICKET_BUFLEN_OUT][31];
};


/*单个结构申明*/
struct SmsupTicketStruct{

	struct SmsupTicketStruct *pNext;
	char    sRecordType[3];
	char    sMsgType[4];
	char    sSpProvCode[4];
	int     iSmg;
	int     iSpCode;
	int     iFwSmg;
	char    sFwSmgProv[4];
	char    sStartTime[15];
	char    sMsgCnt[11];
	char    sBaseFee[13];
	char    sInfoFee[13];
	char    sHomeProvCode[4];
	char    sFileType[4];
	char    sReserve1[31];
	char    sState[4];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	char    sCurFileName[31];
	struct SmsupTicketStruct *pLoadNext;
};

void mvitem_fmsmsupticket(struct FSmsupTicketStruct *pi,struct SmsupTicketStruct *po);
/*批量数据结构缓冲写入SMSUP_TICKET*/
int EInsertStructToSmsupTicket(struct SmsupTicketStruct *p,
	int iInsertFlag,struct SmsupTicketStructOut *pTarget);
int InsertSmsupBillTicket(char sFileName[],char sTableName[]);

/*输出结构缓冲申明*/
struct SmsupIntfTicketStructOut{

#ifndef SMSUP_INTF_TICKET_BUFLEN_OUT
#define SMSUP_INTF_TICKET_BUFLEN_OUT		300
#endif

	struct SmsupIntfTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 数据记录标示 */
	char    asRecordType[SMSUP_INTF_TICKET_BUFLEN_OUT][3];
		/* 消息类型 */
	char    asMsgType[SMSUP_INTF_TICKET_BUFLEN_OUT][4];
		/* SP所属省代码 */
	int     aiSpProvCode[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* SP所属SMG代码 */
	int     aiSmg[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* SP代码 */
	int     aiSpCode[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* 前转网关代码 */
	int     aiFwSmg[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* 前转网关省代码 */
	int     aiFwSmgProv[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* 本次话单最早记录时间 */
	char    asMinStartTime[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
		/* 本次话单最晚记录时间 */
	char    asMaxStartTime[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
		/* 分公司出帐后的全国SP/CP应收帐数据的总MO/MO-F话单数 */
	char    asMoCnt1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的总MO/MO-F话单条数 */
	char    asMoCnt2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的总MT/MT-F话单数 */
	char    asMfCnt1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的总MT/MT-F话单条数 */
	char    asMfCnt2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的结算总费用 */
	char    asFee1[SMSUP_INTF_TICKET_BUFLEN_OUT][13];
		/* 分公司出帐后的全国SP/CP应收帐数据的结算总费用 */
	char    asFee2[SMSUP_INTF_TICKET_BUFLEN_OUT][13];
		/* 计费用户所属省代码 */
	int     aiHomeProvCode[SMSUP_INTF_TICKET_BUFLEN_OUT];
		/* 分公司出帐后的全国SP/CP应收帐数据的通信费总费用 */
	char    asRoamFee1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的通信总费用 */
	char    asRoamFee2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的信息费总费用 */
	char    asInfoFee1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的信息费总费用 */
	char    asInfoFee2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的不均衡通信费总费用 */
	char    asRoamNfee1[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 分公司出帐后的全国SP/CP应收帐数据的不均衡通信总费用 */
	char    asRoamNfee2[SMSUP_INTF_TICKET_BUFLEN_OUT][11];
		/* 保留1 */
	char    asReserve1[SMSUP_INTF_TICKET_BUFLEN_OUT][21];
	char    asState[SMSUP_INTF_TICKET_BUFLEN_OUT][4];
	char    asDealDate[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
	char    asUpdateDate[SMSUP_INTF_TICKET_BUFLEN_OUT][15];
	char    asSourceID[SMSUP_INTF_TICKET_BUFLEN_OUT][41];
};
/* 输入结构缓冲申明*/
struct SmsupIntfTicketStructIn{

#ifndef SMSUP_INTF_TICKET_BUFLEN_IN
#define SMSUP_INTF_TICKET_BUFLEN_IN		300
#endif

	struct SmsupIntfTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[SMSUP_INTF_TICKET_BUFLEN_IN][3];
	char    asMsgType[SMSUP_INTF_TICKET_BUFLEN_IN][4];
	int     aiSpProvCode[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiSmg[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiSpCode[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiFwSmg[SMSUP_INTF_TICKET_BUFLEN_IN];
	int     aiFwSmgProv[SMSUP_INTF_TICKET_BUFLEN_IN];
	char    asMinStartTime[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asMaxStartTime[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asMoCnt1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asMoCnt2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asMfCnt1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asMfCnt2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asFee1[SMSUP_INTF_TICKET_BUFLEN_IN][13];
	char    asFee2[SMSUP_INTF_TICKET_BUFLEN_IN][13];
	int     aiHomeProvCode[SMSUP_INTF_TICKET_BUFLEN_IN];
	char    asRoamFee1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asRoamFee2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asInfoFee1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asInfoFee2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asRoamNfee1[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asRoamNfee2[SMSUP_INTF_TICKET_BUFLEN_IN][11];
	char    asReserve1[SMSUP_INTF_TICKET_BUFLEN_IN][21];
	char    asState[SMSUP_INTF_TICKET_BUFLEN_IN][4];
	char    asUpdateDate[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asDealDate[SMSUP_INTF_TICKET_BUFLEN_IN][15];
	char    asSourceID[SMSUP_INTF_TICKET_BUFLEN_IN][41];
};


/*单个结构申明*/
struct SmsupIntfTicketStruct{

	struct SmsupIntfTicketStruct *pNext;
	char    sRecordType[3];		/* 数据记录标示 */
	char    sMsgType[4];		/* 消息类型 */
	int     iSpProvCode;		/* SP所属省代码 */
	int     iSmg;		/* SP所属SMG代码 */
	int     iSpCode;		/* SP代码 */
	int     iFwSmg;		/* 前转网关代码 */
	int     iFwSmgProv;		/* 前转网关省代码 */
	char    sMinStartTime[15];		/* 本次话单最早记录时间 */
	char    sMaxStartTime[15];		/* 本次话单最晚记录时间 */
	char    sMoCnt1[11];		/* 分公司出帐后的全国SP/CP应收帐数据的总MO/MO-F话单数 */
	char    sMoCnt2[11];		/* 分公司出帐后的全国SP/CP应收帐数据的总MO/MO-F话单条数 */
	char    sMfCnt1[11];		/* 分公司出帐后的全国SP/CP应收帐数据的总MT/MT-F话单数 */
	char    sMfCnt2[11];		/* 分公司出帐后的全国SP/CP应收帐数据的总MT/MT-F话单条数 */
	char    sFee1[13];		/* 分公司出帐后的全国SP/CP应收帐数据的结算总费用 */
	char    sFee2[13];		/* 分公司出帐后的全国SP/CP应收帐数据的结算总费用 */
	int     iHomeProvCode;		/* 计费用户所属省代码 */
	char    sRoamFee1[11];		/* 分公司出帐后的全国SP/CP应收帐数据的通信费总费用 */
	char    sRoamFee2[11];		/* 分公司出帐后的全国SP/CP应收帐数据的通信总费用 */
	char    sInfoFee1[11];		/* 分公司出帐后的全国SP/CP应收帐数据的信息费总费用 */
	char    sInfoFee2[11];		/* 分公司出帐后的全国SP/CP应收帐数据的信息费总费用 */
	char    sRoamNfee1[11];		/* 分公司出帐后的全国SP/CP应收帐数据的不均衡通信费总费用 */
	char    sRoamNfee2[11];		/* 分公司出帐后的全国SP/CP应收帐数据的不均衡通信总费用 */
	char    sReserve1[21];		/* 保留1 */
	char    sState[4];
	char    sDealDate[15];
	char    sUpdateDate[15];
	char    sSourceID[41];
	struct SmsupIntfTicketStruct *pLoadNext;
};

/*批量数据结构缓冲写入SMSUP_INTF_TICKET*/
int EInsertStructToSmsupIntfTicket(struct SmsupIntfTicketStruct *p,
	int iInsertFlag,struct SmsupIntfTicketStructOut *pTarget);
void mvitem_fmsmsupintfticket(struct FSmsupIntfTicketStruct *pi,
	struct SmsupIntfTicketStruct *po);
int InsertSmsupIntfTicket(char sFileName[],char sTableName[]);
int EGetSmsupIntfTicketToStruct(struct SmsupIntfTicketStruct *p,
	struct SmsupIntfTicketStructIn *pSource);
void mvitem_mfsmsupintfticket(struct SmsupIntfTicketStruct *pi,
	struct FSmsupIntfTicketStruct *po);

/*输出结构缓冲申明*/
struct RhjfTicketStructOut{

#ifndef RHJF_TICKET_BUFLEN_OUT
#define RHJF_TICKET_BUFLEN_OUT		300
#endif

	struct RhjfTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asCallType[RHJF_TICKET_BUFLEN_OUT][3];
	char    asTicketType[RHJF_TICKET_BUFLEN_OUT][3];
	char    asMsisdn[RHJF_TICKET_BUFLEN_OUT][16];
	char    asOtherParty[RHJF_TICKET_BUFLEN_OUT][31];
	char    asStartTime[RHJF_TICKET_BUFLEN_OUT][15];
	char    asDuration[RHJF_TICKET_BUFLEN_OUT][7];
	char    asMsc[RHJF_TICKET_BUFLEN_OUT][16];
	char    asTrunkIn[RHJF_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[RHJF_TICKET_BUFLEN_OUT][8];
	char    asBaseCharge[RHJF_TICKET_BUFLEN_OUT][9];
	char    asLandCharge[RHJF_TICKET_BUFLEN_OUT][9];
	char    asOtherCharge[RHJF_TICKET_BUFLEN_OUT][9];
	char    asLandType[RHJF_TICKET_BUFLEN_OUT][2];
	char    asVisitAreaCode[RHJF_TICKET_BUFLEN_OUT][6];
	char    asHomeAreaCode[RHJF_TICKET_BUFLEN_OUT][6];
	char    asCalledAreaCode[RHJF_TICKET_BUFLEN_OUT][6];
	char    asUpdateDate[RHJF_TICKET_BUFLEN_OUT][15];
	char    asDealDate[RHJF_TICKET_BUFLEN_OUT][15];
	char    asSourceID[RHJF_TICKET_BUFLEN_OUT][41];
};


/*单个结构申明*/
struct RhjfTicketStruct{

	struct RhjfTicketStruct *pNext;
	char    sCallType[3];
	char    sTicketType[3];
	char    sMsisdn[16];
	char    sOtherParty[31];
	char    sStartTime[15];
	char    sDuration[7];
	char    sMsc[16];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sBaseCharge[9];
	char    sLandCharge[9];
	char    sOtherCharge[9];
	char    sLandType[2];
	char    sVisitAreaCode[6];
	char    sHomeAreaCode[6];
	char    sCalledAreaCode[6];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct RhjfTicketStruct *pLoadNext;
};
/*批量数据结构缓冲写入RHJF_TICKET*/
int EInsertStructToRhjfTicket(struct RhjfTicketStruct *p,
	int iInsertFlag,struct RhjfTicketStructOut *pTarget);
void mvitem_fmrhjfticket(struct FRhjfTicketStruct *pi,struct RhjfTicketStruct *po);
int InsertRhjfBillTicket(char sFileName[],char sTableName[]);

/***********短信批价核心表*********************/
/*输出结构缓冲申明*/
struct SmsTicketStructOut{

#ifndef SMS_TICKET_BUFLEN_OUT
#define SMS_TICKET_BUFLEN_OUT		300
#endif

	struct SmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型标识 */
	int     aiTicketTypeID[SMS_TICKET_BUFLEN_OUT];
		/* 呼叫类型 */
	char     asCallType[SMS_TICKET_BUFLEN_OUT][3];
		/* 用户归属号码 */
	char    asHomeAreaCode[SMS_TICKET_BUFLEN_OUT][6];
		/* 用户号码 */
	char    asMsisdn[SMS_TICKET_BUFLEN_OUT][16];
		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    asCalledCode[SMS_TICKET_BUFLEN_OUT][6];
		/* 对端号码 */
	char    asOtherParty[SMS_TICKET_BUFLEN_OUT][25];
		/* 应答时间 */
	char    asStartTime[SMS_TICKET_BUFLEN_OUT][15];
		/* 消息长度 */
	int     aiMsgLen[SMS_TICKET_BUFLEN_OUT];
		/* 消息ID */
	char    asMsgID[SMS_TICKET_BUFLEN_OUT][31];
		/* 短信中心 */
	char    asSmsc[SMS_TICKET_BUFLEN_OUT][16];
		/* 短信网关 */
	char    asSmg[SMS_TICKET_BUFLEN_OUT][16];
		/* 前转短信网关 */
	char    asTsmg[SMS_TICKET_BUFLEN_OUT][16];
		/* G,C */
	char    asUserType[SMS_TICKET_BUFLEN_OUT][2];
		/* 对端类型 */
	char    asCalledType[SMS_TICKET_BUFLEN_OUT][3];

	char    asSpAccNbr[SMS_TICKET_BUFLEN_OUT][13];
		/* SP业务代码 */
	char    asSpServiceCode[SMS_TICKET_BUFLEN_OUT][11];
		/* SP代码 */
	char    asSpCode[SMS_TICKET_BUFLEN_OUT][6];
		/* 通信费 */
	int     aiBaseFee[SMS_TICKET_BUFLEN_OUT];
		/* 信息费 */
	int     aiInfoFee[SMS_TICKET_BUFLEN_OUT];
		/* 包月费 */
	int     aiRentFee[SMS_TICKET_BUFLEN_OUT];
		/* 其他费 */
	int     aiOtherFee[SMS_TICKET_BUFLEN_OUT];
		/* 结算收入 */
	int     aiInFee[SMS_TICKET_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutFee[SMS_TICKET_BUFLEN_OUT];

	char	asOriCallType[SMS_TICKET_BUFLEN_OUT][3];
	char	asReserve[SMS_TICKET_BUFLEN_OUT][11];

	char	asSpProvCode[SMS_TICKET_BUFLEN_OUT][4];
	char	asHomeProvCode[SMS_TICKET_BUFLEN_OUT][4];
	char	asScpFlag[SMS_TICKET_BUFLEN_OUT][2];
	int     aiCallingTypeID[SMS_TICKET_BUFLEN_OUT];
	char	asBillType[SMS_TICKET_BUFLEN_OUT][2];

		/* 错误代码 */
	char    asErrCode[SMS_TICKET_BUFLEN_OUT][5];
		/* 文件名 */
	char    asFileName[SMS_TICKET_BUFLEN_OUT][20];
		/* 模块 */
	char    asModule[SMS_TICKET_BUFLEN_OUT][4];
		/* 区号 */
	char    asAreaCode[SMS_TICKET_BUFLEN_OUT][6];
		/* 状态 */
	char    asState[SMS_TICKET_BUFLEN_OUT][2];
		/* 更新时间 */
	char    asUpdateDate[SMS_TICKET_BUFLEN_OUT][15];
		/* 处理时间 */
	char    asDealDate[SMS_TICKET_BUFLEN_OUT][15];
		/* 来源 */
	char    asSourceID[SMS_TICKET_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct SmsTicketStructIn{

#ifndef SMS_TICKET_BUFLEN_IN
#define SMS_TICKET_BUFLEN_IN		300
#endif

	struct SmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型标识 */
	int     aiTicketTypeID[SMS_TICKET_BUFLEN_IN];
		/* 呼叫类型 */
	char     asCallType[SMS_TICKET_BUFLEN_IN][3];
		/* 用户归属号码 */
	char    asHomeAreaCode[SMS_TICKET_BUFLEN_IN][6];
		/* 用户号码 */
	char    asMsisdn[SMS_TICKET_BUFLEN_IN][16];
		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    asCalledCode[SMS_TICKET_BUFLEN_IN][6];
		/* 对端号码 */
	char    asOtherParty[SMS_TICKET_BUFLEN_IN][25];
		/* 应答时间 */
	char    asStartTime[SMS_TICKET_BUFLEN_IN][15];
		/* 消息长度 */
	int     aiMsgLen[SMS_TICKET_BUFLEN_IN];
		/* 消息ID */
	char    asMsgID[SMS_TICKET_BUFLEN_IN][31];
		/* 短信中心 */
	char    asSmsc[SMS_TICKET_BUFLEN_IN][16];
		/* 短信网关 */
	char    asSmg[SMS_TICKET_BUFLEN_IN][16];
		/* 前转短信网关 */
	char    asTsmg[SMS_TICKET_BUFLEN_IN][16];
		/* G,C */
	char    asUserType[SMS_TICKET_BUFLEN_IN][2];
		/* 对端类型 */
	char    asCalledType[SMS_TICKET_BUFLEN_IN][3];

	char    asSpAccNbr[SMS_TICKET_BUFLEN_IN][13];
		/* SP业务代码 */
	char    asSpServiceCode[SMS_TICKET_BUFLEN_IN][11];
		/* SP代码 */
	char    asSpCode[SMS_TICKET_BUFLEN_IN][6];
		/* 通信费 */
	int     aiBaseFee[SMS_TICKET_BUFLEN_IN];
		/* 信息费 */
	int     aiInfoFee[SMS_TICKET_BUFLEN_IN];
		/* 包月费 */
	int     aiRentFee[SMS_TICKET_BUFLEN_IN];
		/* 其他费 */
	int     aiOtherFee[SMS_TICKET_BUFLEN_IN];
		/* 结算收入 */
	int     aiInFee[SMS_TICKET_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutFee[SMS_TICKET_BUFLEN_IN];

	char	asOriCallType[SMS_TICKET_BUFLEN_IN][3];
	char	asReserve[SMS_TICKET_BUFLEN_IN][11];

	char	asSpProvCode[SMS_TICKET_BUFLEN_IN][4];
	char	asHomeProvCode[SMS_TICKET_BUFLEN_IN][4];
	char	asScpFlag[SMS_TICKET_BUFLEN_IN][2];
	int     aiCallingTypeID[SMS_TICKET_BUFLEN_IN];
	char	asBillType[SMS_TICKET_BUFLEN_IN][2];

		/* 错误代码 */
	char    asErrCode[SMS_TICKET_BUFLEN_IN][5];
		/* 文件名 */
	char    asFileName[SMS_TICKET_BUFLEN_IN][20];
		/* 模块 */
	char    asModule[SMS_TICKET_BUFLEN_IN][4];
		/* 区号 */
	char    asAreaCode[SMS_TICKET_BUFLEN_IN][6];
		/* 状态 */
	char    asState[SMS_TICKET_BUFLEN_IN][2];
		/* 更新时间 */
	char    asUpdateDate[SMS_TICKET_BUFLEN_IN][15];
		/* 处理时间 */
	char    asDealDate[SMS_TICKET_BUFLEN_IN][15];
		/* 来源 */
	char    asSourceID[SMS_TICKET_BUFLEN_IN][41];
	char	asRowID[SMS_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct SmsTicketStruct{

	struct SmsTicketStruct *pNext;
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sHomeAreaCode[6];		/* 用户归属号码 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sCalledCode[6];		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	int     iMsgLen;		/* 消息长度 */
	char    sMsgID[31];		/* 消息ID */
	char    sSmsc[16];		/* 短信中心 */
	char    sSmg[16];		/* 短信网关 */
	char    sTsmg[16];		/* 前转短信网关 */
	char    sUserType[2];		/* G,C */
	char    sCalledType[3];		/* 对端类型 */
	char    sSpAccNbr[13];		/* SP业务代码 */
	char    sSpServiceCode[11];		/* SP业务代码 */
	char    sSpCode[6];		/* SP代码 */
	int     iBaseFee;		/* 通信费 */
	int     iInfoFee;		/* 信息费 */
	int     iRentFee;		/* 包月费 */
	int     iOtherFee;		/* 其他费 */
	int     iInFee;		/* 结算收入 */
	int     iOutFee;		/* 结算支出 */
	char	sOriCallType[3];
	char	sReserve[11];

	char	sSpProvCode[4];
	char	sHomeProvCode[4];
	char	sScpFlag[2];
	int     iCallingTypeID;
	char	sBillType[2];

	char    sErrCode[5];		/* 错误代码 */
	char    sFileName[20];		/* 文件名 */
	char    sModule[4];		/* 模块 */
	char    sAreaCode[6];		/* 区号 */
	char    sState[2];		/* 状态 */
	char    sUpdateDate[15];		/* 更新时间 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 来源 */
	char	sRowID[19];
	struct SmsTicketStruct *pLoadNext;
};

/*批量数据结构缓冲写入SMS_TICKET*/
int EInsertStructToSmsTicket(struct SmsTicketStruct *p,
	int iInsertFlag,struct SmsTicketStructOut *pTarget);
void mvitem_fmsmsticket(struct FSmsTicketStruct *pi,
	int len,struct SmsTicketStruct *po);
int InsertSmsTicket(char sFileName[],char sTableName[]);
/*批量数据动态从SMS_TICKET中用结构缓冲方式取数据*/
int EGetSmsTicketToStruct(struct SmsTicketStruct *p,
	struct SmsTicketStructIn *pSource);
void mvitem_mfsmsticket(struct SmsTicketStruct *pi,struct FSmsTicketStruct *po);


/* 输入结构缓冲申明*/
struct NsmsTicketStructIn{

#ifndef NSMS_TICKET_BUFLEN_IN
#define NSMS_TICKET_BUFLEN_IN		1000
#endif

	struct NsmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型标识 */
	int     aiTicketTypeID[NSMS_TICKET_BUFLEN_IN];
		/* 呼叫类型 */
	char    asCallType[NSMS_TICKET_BUFLEN_IN][3];
		/* 用户归属号码 */
	char    asHomeAreaCode[NSMS_TICKET_BUFLEN_IN][6];
		/* 用户号码 */
	char    asMsisdn[NSMS_TICKET_BUFLEN_IN][16];
		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    asCalledCode[NSMS_TICKET_BUFLEN_IN][6];
		/* 对端号码 */
	char    asOtherParty[NSMS_TICKET_BUFLEN_IN][25];
		/* 应答时间 */
	char    asStartTime[NSMS_TICKET_BUFLEN_IN][15];
		/* 消息长度 */
	int     aiMsgLen[NSMS_TICKET_BUFLEN_IN];
		/* 消息ID */
	char    asMsgID[NSMS_TICKET_BUFLEN_IN][31];
		/* 对端消息ID */
	char    asOppMsgID[NSMS_TICKET_BUFLEN_IN][31];
		/* 子业务类型 */
	char    asSubType[NSMS_TICKET_BUFLEN_IN][2];
		/* 短信中心 */
	char    asSmsc[NSMS_TICKET_BUFLEN_IN][16];
		/* 短信网关 */
	char    asSmg[NSMS_TICKET_BUFLEN_IN][16];
		/* 前转短信网关 */
	char    asTsmg[NSMS_TICKET_BUFLEN_IN][16];
		/* G,C */
	char    asUserType[NSMS_TICKET_BUFLEN_IN][2];
		/* 对端类型 */
	char    asCalledType[NSMS_TICKET_BUFLEN_IN][3];
		/* SP接入代码 */
	char    asSpAccNbr[NSMS_TICKET_BUFLEN_IN][13];
		/* SP业务代码 */
	char    asSpServiceCode[NSMS_TICKET_BUFLEN_IN][11];
		/* SP代码 */
	char    asSpCode[NSMS_TICKET_BUFLEN_IN][11];
		/* 通信费 */
	int     aiBaseFee[NSMS_TICKET_BUFLEN_IN];
		/* 信息费 */
	int     aiInfoFee[NSMS_TICKET_BUFLEN_IN];
		/* 包月费 */
	int     aiRentFee[NSMS_TICKET_BUFLEN_IN];
		/* 其他费 */
	int     aiOtherFee[NSMS_TICKET_BUFLEN_IN];
		/* 结算收入 */
	int     aiInFee[NSMS_TICKET_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutFee[NSMS_TICKET_BUFLEN_IN];
		/* 原呼叫类型 */
	char    asOriCallType[NSMS_TICKET_BUFLEN_IN][3];
		/* 保留 */
	char    asReserve[NSMS_TICKET_BUFLEN_IN][11];
		/* SP归属省代码 */
	char    asSpProvCode[NSMS_TICKET_BUFLEN_IN][4];
		/* 用户归属省代码 */
	char    asHomeProvCode[NSMS_TICKET_BUFLEN_IN][4];
		/* 智能网标志 */
	char    asScpFlag[NSMS_TICKET_BUFLEN_IN][2];
		/* 用户号头类型 */
	int     aiCallingTypeID[NSMS_TICKET_BUFLEN_IN];
		/* 计费类型 */
	char    asBillType[NSMS_TICKET_BUFLEN_IN][2];
		/* 错误代码 */
	char    asErrCode[NSMS_TICKET_BUFLEN_IN][5];
		/* 文件名 */
	char    asFileName[NSMS_TICKET_BUFLEN_IN][20];
		/* 模块 */
	char    asModule[NSMS_TICKET_BUFLEN_IN][4];
		/* 区号 */
	char    asAreaCode[NSMS_TICKET_BUFLEN_IN][6];
		/* 状态 */
	char    asState[NSMS_TICKET_BUFLEN_IN][2];
		/* 更新时间 */
	char    asUpdateDate[NSMS_TICKET_BUFLEN_IN][15];
		/* 处理时间 */
	char    asDealDate[NSMS_TICKET_BUFLEN_IN][15];
		/* 来源 */
	char    asSourceID[NSMS_TICKET_BUFLEN_IN][41];
	char	asRowID[NSMS_TICKET_BUFLEN_IN][19];
};


/*输出结构缓冲申明*/
struct NsmsTicketStructOut{

#ifndef NSMS_TICKET_BUFLEN_OUT
#define NSMS_TICKET_BUFLEN_OUT		1000
#endif

	struct NsmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型标识 */
	int     aiTicketTypeID[NSMS_TICKET_BUFLEN_OUT];
		/* 呼叫类型 */
	char    asCallType[NSMS_TICKET_BUFLEN_OUT][3];
		/* 用户归属号码 */
	char    asHomeAreaCode[NSMS_TICKET_BUFLEN_OUT][6];
		/* 用户号码 */
	char    asMsisdn[NSMS_TICKET_BUFLEN_OUT][16];
		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    asCalledCode[NSMS_TICKET_BUFLEN_OUT][6];
		/* 对端号码 */
	char    asOtherParty[NSMS_TICKET_BUFLEN_OUT][25];
		/* 应答时间 */
	char    asStartTime[NSMS_TICKET_BUFLEN_OUT][15];
		/* 消息长度 */
	int     aiMsgLen[NSMS_TICKET_BUFLEN_OUT];
		/* 消息ID */
	char    asMsgID[NSMS_TICKET_BUFLEN_OUT][31];
		/* 对端消息ID */
	char    asOppMsgID[NSMS_TICKET_BUFLEN_OUT][31];
		/* 子业务类型 */
	char    asSubType[NSMS_TICKET_BUFLEN_OUT][2];
		/* 短信中心 */
	char    asSmsc[NSMS_TICKET_BUFLEN_OUT][16];
		/* 短信网关 */
	char    asSmg[NSMS_TICKET_BUFLEN_OUT][16];
		/* 前转短信网关 */
	char    asTsmg[NSMS_TICKET_BUFLEN_OUT][16];
		/* G,C */
	char    asUserType[NSMS_TICKET_BUFLEN_OUT][2];
		/* 对端类型 */
	char    asCalledType[NSMS_TICKET_BUFLEN_OUT][3];
		/* SP接入代码 */
	char    asSpAccNbr[NSMS_TICKET_BUFLEN_OUT][13];
		/* SP业务代码 */
	char    asSpServiceCode[NSMS_TICKET_BUFLEN_OUT][11];
		/* SP代码 */
	char    asSpCode[NSMS_TICKET_BUFLEN_OUT][11];
		/* 通信费 */
	int     aiBaseFee[NSMS_TICKET_BUFLEN_OUT];
		/* 信息费 */
	int     aiInfoFee[NSMS_TICKET_BUFLEN_OUT];
		/* 包月费 */
	int     aiRentFee[NSMS_TICKET_BUFLEN_OUT];
		/* 其他费 */
	int     aiOtherFee[NSMS_TICKET_BUFLEN_OUT];
		/* 结算收入 */
	int     aiInFee[NSMS_TICKET_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutFee[NSMS_TICKET_BUFLEN_OUT];
		/* 原呼叫类型 */
	char    asOriCallType[NSMS_TICKET_BUFLEN_OUT][3];
		/* 保留 */
	char    asReserve[NSMS_TICKET_BUFLEN_OUT][11];
		/* SP归属省代码 */
	char    asSpProvCode[NSMS_TICKET_BUFLEN_OUT][4];
		/* 用户归属省代码 */
	char    asHomeProvCode[NSMS_TICKET_BUFLEN_OUT][4];
		/* 智能网标志 */
	char    asScpFlag[NSMS_TICKET_BUFLEN_OUT][2];
		/* 用户号头类型 */
	int     aiCallingTypeID[NSMS_TICKET_BUFLEN_OUT];
		/* 计费类型 */
	char    asBillType[NSMS_TICKET_BUFLEN_OUT][2];
		/* 错误代码 */
	char    asErrCode[NSMS_TICKET_BUFLEN_OUT][5];
		/* 文件名 */
	char    asFileName[NSMS_TICKET_BUFLEN_OUT][20];
		/* 模块 */
	char    asModule[NSMS_TICKET_BUFLEN_OUT][4];
		/* 区号 */
	char    asAreaCode[NSMS_TICKET_BUFLEN_OUT][6];
		/* 状态 */
	char    asState[NSMS_TICKET_BUFLEN_OUT][2];
		/* 更新时间 */
	char    asUpdateDate[NSMS_TICKET_BUFLEN_OUT][15];
		/* 处理时间 */
	char    asDealDate[NSMS_TICKET_BUFLEN_OUT][15];
		/* 来源 */
	char    asSourceID[NSMS_TICKET_BUFLEN_OUT][41];
};




/*单个结构申明*/
struct NsmsTicketStruct{

	struct NsmsTicketStruct *pNext;
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sHomeAreaCode[6];		/* 用户归属号码 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sCalledCode[6];		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	int     iMsgLen;		/* 消息长度 */
	char    sMsgID[31];		/* 消息ID */
	char    sOppMsgID[31];		/* 对端消息ID */
	char    sSubType[2];		/* 子业务类型 */
	char    sSmsc[16];		/* 短信中心 */
	char    sSmg[16];		/* 短信网关 */
	char    sTsmg[16];		/* 前转短信网关 */
	char    sUserType[2];		/* G,C */
	char    sCalledType[3];		/* 对端类型 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	char    sSpServiceCode[11];		/* SP业务代码 */
	char    sSpCode[11];		/* SP代码 */
	int     iBaseFee;		/* 通信费 */
	int     iInfoFee;		/* 信息费 */
	int     iRentFee;		/* 包月费 */
	int     iOtherFee;		/* 其他费 */
	int     iInFee;		/* 结算收入 */
	int     iOutFee;		/* 结算支出 */
	char    sOriCallType[3];		/* 原呼叫类型 */
	char    sReserve[11];		/* 保留 */
	char    sSpProvCode[4];		/* SP归属省代码 */
	char    sHomeProvCode[4];		/* 用户归属省代码 */
	char    sScpFlag[2];		/* 智能网标志 */
	int     iCallingTypeID;		/* 用户号头类型 */
	char    sBillType[2];		/* 计费类型 */
	char    sErrCode[5];		/* 错误代码 */
	char    sFileName[20];		/* 文件名 */
	char    sModule[4];		/* 模块 */
	char    sAreaCode[6];		/* 区号 */
	char    sState[2];		/* 状态 */
	char    sUpdateDate[15];		/* 更新时间 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 来源 */
	char	sRowID[19];
	struct NsmsTicketStruct *pLoadNext;
};




/*批量数据动态从NSMS_TICKET中用结构缓冲方式取数据*/
int EGetNsmsTicketToStruct(struct NsmsTicketStruct *p,
	struct NsmsTicketStructIn *pSource);
void mvitem_mfnsmsticket(struct NsmsTicketStruct *pi,
	struct FNsmsTicketStruct *po);
/*批量数据结构缓冲写入NSMS_TICKET*/
int EInsertStructToNsmsTicket(struct NsmsTicketStruct *p,
	int iInsertFlag,struct NsmsTicketStructOut *pTarget);
void mvitem_fmnsmsticket(struct FNsmsTicketStruct *pi,
	int len,struct NsmsTicketStruct *po);

int InsertNsmsTicket(char sFileName[],char sTableName[]);

/****以下是早期话单比对用的东西***/





/*输出结构缓冲申明*/
struct TelecomTicketStructOut{

#ifndef TELECOM_TICKET_BUFLEN_OUT
#define TELECOM_TICKET_BUFLEN_OUT		300
#endif

	struct TelecomTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 主叫区号 */
	char    asCallingAreaCode[TELECOM_TICKET_BUFLEN_OUT][10];
		/* 主叫号码 */
	char    asCallingNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* 被叫区号 */
	char    asCalledAreaCode[TELECOM_TICKET_BUFLEN_OUT][10];
		/* 被叫号码 */
	char    asCalledNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* 通话时间 */
	char    asStartTime[TELECOM_TICKET_BUFLEN_OUT][15];
		/* 通话时长 */
	int     aiDuration[TELECOM_TICKET_BUFLEN_OUT];
		/* 结算费用 */
	int     aiCharge[TELECOM_TICKET_BUFLEN_OUT];
		/* 结算帐目 */
	int     aiTalkTypeID[TELECOM_TICKET_BUFLEN_OUT];
		/* 原始主叫区号 */
	char    asOCallingNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* 原始被叫区号 */
	char    asOCalledNbr[TELECOM_TICKET_BUFLEN_OUT][25];
		/* 入中继 */
	char    asTrunkIn[TELECOM_TICKET_BUFLEN_OUT][8];
		/* 出中继 */
	char    asTrunkOut[TELECOM_TICKET_BUFLEN_OUT][8];
};


/* 输入结构缓冲申明*/
struct TelecomTicketStructIn{

#ifndef TELECOM_TICKET_BUFLEN_IN
#define TELECOM_TICKET_BUFLEN_IN		300
#endif

	struct TelecomTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 主叫区号 */
	char    asCallingAreaCode[TELECOM_TICKET_BUFLEN_IN][10];
		/* 主叫号码 */
	char    asCallingNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* 被叫区号 */
	char    asCalledAreaCode[TELECOM_TICKET_BUFLEN_IN][10];
		/* 被叫号码 */
	char    asCalledNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* 通话时间 */
	char    asStartTime[TELECOM_TICKET_BUFLEN_IN][15];
		/* 通话时长 */
	int     aiDuration[TELECOM_TICKET_BUFLEN_IN];
		/* 结算费用 */
	int     aiCharge[TELECOM_TICKET_BUFLEN_IN];
		/* 结算帐目 */
	int     aiTalkTypeID[TELECOM_TICKET_BUFLEN_IN];
		/* 原始主叫区号 */
	char    asOCallingNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* 原始被叫区号 */
	char    asOCalledNbr[TELECOM_TICKET_BUFLEN_IN][25];
		/* 入中继 */
	char    asTrunkIn[TELECOM_TICKET_BUFLEN_IN][8];
		/* 出中继 */
	char    asTrunkOut[TELECOM_TICKET_BUFLEN_IN][8];
};


/*单个结构申明*/
struct TelecomTicketStruct{

	struct TelecomTicketStruct *pNext;
	char    sCallingAreaCode[10];		/* 主叫区号 */
	char    sCallingNbr[25];		/* 主叫号码 */
	char    sCalledAreaCode[10];		/* 被叫区号 */
	char    sCalledNbr[25];		/* 被叫号码 */
	char    sStartTime[15];		/* 通话时间 */
	int     iDuration;		/* 通话时长 */
	int     iCharge;		/* 结算费用 */
	int     iTalkTypeID;		/* 结算帐目 */
	char    sOCallingNbr[25];		/* 原始主叫区号 */
	char    sOCalledNbr[25];		/* 原始被叫区号 */
	char    sTrunkIn[8];		/* 入中继 */
	char    sTrunkOut[8];		/* 出中继 */
	char	sState[1];	/*MODIFYHERE*/
	time_t	tStartTime;
	struct TelecomTicketStruct *pLoadNext;
};

/*批量数据动态从TELECOM_TICKET中用结构缓冲方式取数据*/
int EGetTelecomTicketToStruct(struct TelecomTicketStruct *p,
	struct TelecomTicketStructIn *pSource);
/*批量数据结构缓冲写入TELECOM_TICKET*/
int EInsertStructToTelecomTicket(struct TelecomTicketStruct *p,
	int iInsertFlag,struct TelecomTicketStructOut *pTarget);
	
/* 输入结构缓冲申明*/
struct DmpTicketStructIn{

#ifndef DMP_TICKET_BUFLEN_IN
#define DMP_TICKET_BUFLEN_IN		300
#endif

	struct DmpTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 呼叫类型 */
	char    asCallType[DMP_TICKET_BUFLEN_IN][3];
		/* 用户号码 */
	char    asMsisdn[DMP_TICKET_BUFLEN_IN][16];
		/* 对端号码 */
	char    asOtherParty[DMP_TICKET_BUFLEN_IN][41];
		/* 通话时间 */
	char    asStartTime[DMP_TICKET_BUFLEN_IN][15];
		/* 通话时长 */
	char    asDuration[DMP_TICKET_BUFLEN_IN][7];
		/* 通话位置 */
	char    asLocation[DMP_TICKET_BUFLEN_IN][41];
};


/*单个结构申明*/
struct DmpTicketStruct{

	struct DmpTicketStruct *pNext;
	char    sCallType[3];		/* 呼叫类型 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sOtherParty[41];		/* 对端号码 */
	char    sStartTime[15];		/* 通话时间 */
	char    sDuration[7];		/* 通话时长 */
	char    sLocation[41];		/* 通话位置 */
	struct DmpTicketStruct *pLoadNext;
};

/*批量数据动态从DMP_TICKET中用结构缓冲方式取数据*/
int EGetDmpTicketToStruct(struct DmpTicketStruct *p,
	struct DmpTicketStructIn *pSource);

/*********短信原始、短信统计、SP结算等****/
/* 输入结构缓冲申明*/
struct SmcdmaTicketStructIn{

#ifndef SMCDMA_TICKET_BUFLEN_IN
#define SMCDMA_TICKET_BUFLEN_IN		300
#endif

	struct SmcdmaTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 流水号 */
	char    asRecNo[SMCDMA_TICKET_BUFLEN_IN][16];
		/* 呼叫类型 */
	char    asCallType[SMCDMA_TICKET_BUFLEN_IN][3];
		/* 主叫号码 */
	char    asCallingNbr[SMCDMA_TICKET_BUFLEN_IN][25];
		/* 被叫号码 */
	char    asCalledNbr[SMCDMA_TICKET_BUFLEN_IN][25];
		/* 申请时间 */
	char    asRegisterTime[SMCDMA_TICKET_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asSendTime[SMCDMA_TICKET_BUFLEN_IN][15];
		/* 消息长度 */
	int     aiMsgLen[SMCDMA_TICKET_BUFLEN_IN];
		/* 短信发送状态 */
	char    asLastStatus[SMCDMA_TICKET_BUFLEN_IN][6];
		/* 业务类型 */
	char    asServiceType[SMCDMA_TICKET_BUFLEN_IN][4];
		/* 业务代码 */
	char    asServiceCode[SMCDMA_TICKET_BUFLEN_IN][5];
		/* 编码方式 */
	char    asLandType[SMCDMA_TICKET_BUFLEN_IN][2];
		/* 优先级 */
	char    asPriority[SMCDMA_TICKET_BUFLEN_IN][3];
};


/*单个结构申明*/
struct SmcdmaTicketStruct{

	struct SmcdmaTicketStruct *pNext;
	char    sRecNo[16];		/* 流水号 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sCallingNbr[25];		/* 主叫号码 */
	char    sCalledNbr[25];		/* 被叫号码 */
	char    sRegisterTime[15];		/* 申请时间 */
	char    sSendTime[15];		/* 处理结束时间 */
	int     iMsgLen;		/* 消息长度 */
	char    sLastStatus[6];		/* 短信发送状态 */
	char    sServiceType[4];		/* 业务类型 */
	char    sServiceCode[5];		/* 业务代码 */
	char    sLandType[2];		/* 编码方式 */
	char    sPriority[3];		/* 优先级 */
	struct SmcdmaTicketStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FSmcdmaTicketStruct{

	char    sRecNo[15];		/* 流水号 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sCallingNbr[24];		/* 主叫号码 */
	char    sCalledNbr[24];		/* 被叫号码 */
	char    sRegisterTime[14];		/* 申请时间 */
	char    sSendTime[14];		/* 处理结束时间 */
	char    sMsgLen[3];		/* 消息长度 */
	char    sLastStatus[5];		/* 短信发送状态 */
	char    sServiceType[3];		/* 业务类型 */
	char    sServiceCode[4];		/* 业务代码 */
	char    sLandType[1];		/* 编码方式 */
	char    sPriority[2];		/* 优先级 */
};
/*批量数据动态从SMCDMA_TICKET中用结构缓冲方式取数据*/
int EGetSmcdmaTicketToStruct(struct SmcdmaTicketStruct *p,
	struct SmcdmaTicketStructIn *pSource);
void mvitem_mfsmcdmaticket(struct SmcdmaTicketStruct *pi,struct FSmcdmaTicketStruct *po);

/* 输入结构缓冲申明*/
struct SmgsmTicketStructIn{

#ifndef SMGSM_TICKET_BUFLEN_IN
#define SMGSM_TICKET_BUFLEN_IN		300
#endif

	struct SmgsmTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 流水号 */
	char    asReqNo[SMGSM_TICKET_BUFLEN_IN][19];
		/* 消息标识 */
	char    asMsgID[SMGSM_TICKET_BUFLEN_IN][11];
		/* 主叫号码 */
	char    asCallingNbr[SMGSM_TICKET_BUFLEN_IN][21];
		/* CALLING_TON */
	char    asCallingTon[SMGSM_TICKET_BUFLEN_IN][4];
		/* CALLING_NPI */
	char    asCallingNpi[SMGSM_TICKET_BUFLEN_IN][4];
		/* 被叫号码 */
	char    asCalledNbr[SMGSM_TICKET_BUFLEN_IN][21];
		/* CALLED_TON */
	char    asCalledTon[SMGSM_TICKET_BUFLEN_IN][4];
		/* CALLED_NPI */
	char    asCalledNpi[SMGSM_TICKET_BUFLEN_IN][4];
		/* 申请时间 */
	char    asRegisterTime[SMGSM_TICKET_BUFLEN_IN][20];
		/* 发送结束时间 */
	char    asSendTime[SMGSM_TICKET_BUFLEN_IN][20];
		/* 优先级 */
	char    asPriority[SMGSM_TICKET_BUFLEN_IN][4];
		/* SSR */
	char    asSsr[SMGSM_TICKET_BUFLEN_IN][4];
		/* PID */
	char    asPid[SMGSM_TICKET_BUFLEN_IN][4];
		/* DCS */
	char    asDcs[SMGSM_TICKET_BUFLEN_IN][4];
		/* 消息长度 */
	int     aiMsgLen[SMGSM_TICKET_BUFLEN_IN];
		/* 发送最终状态 */
	char    asLastStatus[SMGSM_TICKET_BUFLEN_IN][4];
		/* 错误代码 */
	char    asErrCode[SMGSM_TICKET_BUFLEN_IN][4];
		/* 消息类型 */
	char    asMsgType[SMGSM_TICKET_BUFLEN_IN][5];
		/* 业务类型 */
	char    asServiceType[SMGSM_TICKET_BUFLEN_IN][6];
		/* PPS标志 */
	char    asPpsFlag[SMGSM_TICKET_BUFLEN_IN][2];
		/* ORG_ACCOUNT */
	char    asOrgAccount[SMGSM_TICKET_BUFLEN_IN][11];
		/* DEST_ACCOUNT */
	char    asDestAccount[SMGSM_TICKET_BUFLEN_IN][11];
		/* 鉴权结果 */
	char    asRightResult[SMGSM_TICKET_BUFLEN_IN][11];
		/* UDHI */
	char    asUdhi[SMGSM_TICKET_BUFLEN_IN][2];
		/* MR */
	char    asMr[SMGSM_TICKET_BUFLEN_IN][2];
		/* RN */
	char    asRn[SMGSM_TICKET_BUFLEN_IN][3];
		/* MN */
	char    asMn[SMGSM_TICKET_BUFLEN_IN][2];
		/* SN */
	char    asSn[SMGSM_TICKET_BUFLEN_IN][2];
};


/*单个结构申明*/
struct SmgsmTicketStruct{

	struct SmgsmTicketStruct *pNext;
	char    sReqNo[19];		/* 流水号 */
	char    sMsgID[11];		/* 消息标识 */
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCallingTon[4];		/* CALLING_TON */
	char    sCallingNpi[4];		/* CALLING_NPI */
	char    sCalledNbr[21];		/* 被叫号码 */
	char    sCalledTon[4];		/* CALLED_TON */
	char    sCalledNpi[4];		/* CALLED_NPI */
	char    sRegisterTime[20];		/* 申请时间 */
	char    sSendTime[20];		/* 发送结束时间 */
	char    sPriority[4];		/* 优先级 */
	char    sSsr[4];		/* SSR */
	char    sPid[4];		/* PID */
	char    sDcs[4];		/* DCS */
	int     iMsgLen;		/* 消息长度 */
	char    sLastStatus[4];		/* 发送最终状态 */
	char    sErrCode[4];		/* 错误代码 */
	char    sMsgType[5];		/* 消息类型 */
	char    sServiceType[6];		/* 业务类型 */
	char    sPpsFlag[2];		/* PPS标志 */
	char    sOrgAccount[11];		/* ORG_ACCOUNT */
	char    sDestAccount[11];		/* DEST_ACCOUNT */
	char    sRightResult[11];		/* 鉴权结果 */
	char    sUdhi[2];		/* UDHI */
	char    sMr[2];		/* MR */
	char    sRn[3];		/* RN */
	char    sMn[2];		/* MN */
	char    sSn[2];		/* SN */
	struct SmgsmTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSmgsmTicketStruct{

	char    sReqNo[18];		/* 流水号 */
	char    sMsgID[10];		/* 消息标识 */
	char    sCallingNbr[20];		/* 主叫号码 */
	char    sCallingTon[3];		/* CALLING_TON */
	char    sCallingNpi[3];		/* CALLING_NPI */
	char    sCalledNbr[20];		/* 被叫号码 */
	char    sCalledTon[3];		/* CALLED_TON */
	char    sCalledNpi[3];		/* CALLED_NPI */
	char    sRegisterTime[19];		/* 申请时间 */
	char    sSendTime[19];		/* 发送结束时间 */
	char    sPriority[3];		/* 优先级 */
	char    sSsr[3];		/* SSR */
	char    sPid[3];		/* PID */
	char    sDcs[3];		/* DCS */
	char    sMsgLen[3];		/* 消息长度 */
	char    sLastStatus[3];		/* 发送最终状态 */
	char    sErrCode[3];		/* 错误代码 */
	char    sMsgType[4];		/* 消息类型 */
	char    sServiceType[5];		/* 业务类型 */
	char    sPpsFlag[1];		/* PPS标志 */
	char    sOrgAccount[10];		/* ORG_ACCOUNT */
	char    sDestAccount[10];		/* DEST_ACCOUNT */
	char    sRightResult[10];		/* 鉴权结果 */
	char    sUdhi[1];		/* UDHI */
	char    sMr[1];		/* MR */
	char    sRn[2];		/* RN */
	char    sMn[1];		/* MN */
	char    sSn[1];		/* SN */
};

/*批量数据动态从SMGSM_TICKET中用结构缓冲方式取数据*/
int EGetSmgsmTicketToStruct(struct SmgsmTicketStruct *p,
	struct SmgsmTicketStructIn *pSource);
void mvitem_mfsmgsmticket(struct SmgsmTicketStruct *pi,struct FSmgsmTicketStruct *po);


/* 输入结构缓冲申明*/
struct SmmobTicketStructIn{

#ifndef SMMOB_TICKET_BUFLEN_IN
#define SMMOB_TICKET_BUFLEN_IN		300
#endif

	struct SmmobTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 流水号 */
	char    asRegNo[SMMOB_TICKET_BUFLEN_IN][31];
		/* 呼叫类型 */
	char    asCallType[SMMOB_TICKET_BUFLEN_IN][3];
		/* 用户类型 */
	char    asUserType[SMMOB_TICKET_BUFLEN_IN][2];
		/* 主叫号码 */
	char    asCallingNbr[SMMOB_TICKET_BUFLEN_IN][22];
		/* 被叫号码 */
	char    asCalledNbr[SMMOB_TICKET_BUFLEN_IN][22];
		/* 城市代码 */
	char    asCityCode[SMMOB_TICKET_BUFLEN_IN][4];
		/* 短信发送状态 */
	char    asLastStatus[SMMOB_TICKET_BUFLEN_IN][5];
		/* 短信长度 */
	int     aiMsgLen[SMMOB_TICKET_BUFLEN_IN];
		/* 短信网关代码 */
	char    asSmg[SMMOB_TICKET_BUFLEN_IN][6];
		/* 关联网关代码 */
	char    asTsmg[SMMOB_TICKET_BUFLEN_IN][6];
		/* 业务代码 */
	char    asServiceCode[SMMOB_TICKET_BUFLEN_IN][5];
		/* 短信中心 */
	char    asSmsc[SMMOB_TICKET_BUFLEN_IN][14];
		/* 申请时间 */
	char    asRegisterTime[SMMOB_TICKET_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asSendTime[SMMOB_TICKET_BUFLEN_IN][15];
		/* 保留 */
	char    asReserve[SMMOB_TICKET_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SmmobTicketStruct{

	struct SmmobTicketStruct *pNext;
	char    sRegNo[31];		/* 流水号 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sUserType[2];		/* 用户类型 */
	char    sCallingNbr[22];		/* 主叫号码 */
	char    sCalledNbr[22];		/* 被叫号码 */
	char    sCityCode[4];		/* 城市代码 */
	char    sLastStatus[5];		/* 短信发送状态 */
	int     iMsgLen;		/* 短信长度 */
	char    sSmg[6];		/* 短信网关代码 */
	char    sTsmg[6];		/* 关联网关代码 */
	char    sServiceCode[5];		/* 业务代码 */
	char    sSmsc[14];		/* 短信中心 */
	char    sRegisterTime[15];		/* 申请时间 */
	char    sSendTime[15];		/* 处理结束时间 */
	char    sReserve[15];		/* 保留 */
	struct SmmobTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSmmobTicketStruct{

	char    sRegNo[30];		/* 流水号 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sUserType[1];		/* 用户类型 */
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCalledNbr[21];		/* 被叫号码 */
	char    sCityCode[3];		/* 城市代码 */
	char    sLastStatus[4];		/* 短信发送状态 */
	char    sMsgLen[3];		/* 短信长度 */
	char    sSmg[5];		/* 短信网关代码 */
	char    sTsmg[5];		/* 关联网关代码 */
	char    sServiceCode[4];		/* 业务代码 */
	char    sSmsc[13];		/* 短信中心 */
	char    sRegisterTime[14];		/* 申请时间 */
	char    sSendTime[14];		/* 处理结束时间 */
	char    sReserve[14];		/* 保留 */
};


/*批量数据动态从SMMOB_TICKET中用结构缓冲方式取数据*/
int EGetSmmobTicketToStruct(struct SmmobTicketStruct *p,
	struct SmmobTicketStructIn *pSource);
void mvitem_mfsmmobticket(struct SmmobTicketStruct *pi,struct FSmmobTicketStruct *po);


/* 输入结构缓冲申明*/
struct SmtelTicketStructIn{

#ifndef SMTEL_TICKET_BUFLEN_IN
#define SMTEL_TICKET_BUFLEN_IN		300
#endif

	struct SmtelTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 流水号 */
	char    asRegNo[SMTEL_TICKET_BUFLEN_IN][31];
		/* 呼叫类型 */
	char    asCallType[SMTEL_TICKET_BUFLEN_IN][3];
		/* 用户类型 */
	char    asUserType[SMTEL_TICKET_BUFLEN_IN][2];
		/* 主叫号码 */
	char    asCallingNbr[SMTEL_TICKET_BUFLEN_IN][22];
		/* 被叫号码 */
	char    asCalledNbr[SMTEL_TICKET_BUFLEN_IN][22];
		/* 城市代码 */
	char    asCityCode[SMTEL_TICKET_BUFLEN_IN][4];
		/* 短信发送状态 */
	char    asLastStatus[SMTEL_TICKET_BUFLEN_IN][5];
		/* 短信长度 */
	int     aiMsgLen[SMTEL_TICKET_BUFLEN_IN];
		/* 短信网关代码 */
	char    asSmg[SMTEL_TICKET_BUFLEN_IN][7];
		/* 关联网关代码 */
	char    asTsmg[SMTEL_TICKET_BUFLEN_IN][7];
		/* 业务代码 */
	char    asServiceCode[SMTEL_TICKET_BUFLEN_IN][5];
		/* 短信中心 */
	char    asSmsc[SMTEL_TICKET_BUFLEN_IN][14];
		/* 申请时间 */
	char    asRegisterTime[SMTEL_TICKET_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asSendTime[SMTEL_TICKET_BUFLEN_IN][15];
		/* 保留 */
	char    asReserve[SMTEL_TICKET_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SmtelTicketStruct{

	struct SmtelTicketStruct *pNext;
	char    sRegNo[31];		/* 流水号 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sUserType[2];		/* 用户类型 */
	char    sCallingNbr[22];		/* 主叫号码 */
	char    sCalledNbr[22];		/* 被叫号码 */
	char    sCityCode[4];		/* 城市代码 */
	char    sLastStatus[5];		/* 短信发送状态 */
	int     iMsgLen;		/* 短信长度 */
	char    sSmg[7];		/* 短信网关代码 */
	char    sTsmg[7];		/* 关联网关代码 */
	char    sServiceCode[5];		/* 业务代码 */
	char    sSmsc[14];		/* 短信中心 */
	char    sRegisterTime[15];		/* 申请时间 */
	char    sSendTime[15];		/* 处理结束时间 */
	char    sReserve[15];		/* 保留 */
	struct SmtelTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSmtelTicketStruct{

	char    sRegNo[30];		/* 流水号 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sUserType[1];		/* 用户类型 */
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCalledNbr[21];		/* 被叫号码 */
	char    sCityCode[3];		/* 城市代码 */
	char    sLastStatus[4];		/* 短信发送状态 */
	char    sMsgLen[3];		/* 短信长度 */
	char    sSmg[6];		/* 短信网关代码 */
	char    sTsmg[6];		/* 关联网关代码 */
	char    sServiceCode[4];		/* 业务代码 */
	char    sSmsc[13];		/* 短信中心 */
	char    sRegisterTime[14];		/* 申请时间 */
	char    sSendTime[14];		/* 处理结束时间 */
	char    sReserve[14];		/* 保留 */
};


/*批量数据动态从SMTEL_TICKET中用结构缓冲方式取数据*/
int EGetSmtelTicketToStruct(struct SmtelTicketStruct *p,
	struct SmtelTicketStructIn *pSource);
void mvitem_mfsmtelticket(struct SmtelTicketStruct *pi,struct FSmtelTicketStruct *po);

/* 输入结构缓冲申明*/
struct Smsp1TicketStructIn{

#ifndef SMSP1_TICKET_BUFLEN_IN
#define SMSP1_TICKET_BUFLEN_IN		300
#endif

	struct Smsp1TicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 命令序列 */
	char    asRegNo[SMSP1_TICKET_BUFLEN_IN][31];
		/* 呼叫类型 */
	char    asCallType[SMSP1_TICKET_BUFLEN_IN][3];
		/* 用户类型 */
	char    asUserType[SMSP1_TICKET_BUFLEN_IN][2];
		/* 计费号码 */
	char    asMsisdn[SMSP1_TICKET_BUFLEN_IN][14];
		/* SP代码 */
	char    asSpCode[SMSP1_TICKET_BUFLEN_IN][6];
		/* SP归属网关代码 */
	char    asSpHomeSmg[SMSP1_TICKET_BUFLEN_IN][6];
		/* 被叫号码 */
	char    asOtherParty[SMSP1_TICKET_BUFLEN_IN][14];
		/* SP接入码 */
	char    asSpAccNbr[SMSP1_TICKET_BUFLEN_IN][13];
		/* 业务代码 */
	char    asServiceCode[SMSP1_TICKET_BUFLEN_IN][11];
		/* 用户计费类型 */
	char    asBillingType[SMSP1_TICKET_BUFLEN_IN][2];
		/* 信息费 */
	int     aiInfoFee[SMSP1_TICKET_BUFLEN_IN];
		/* 包月费 */
	int     aiRentFee[SMSP1_TICKET_BUFLEN_IN];
		/* 返还话费 */
	int     aiReturnFee[SMSP1_TICKET_BUFLEN_IN];
		/* 代收费标致 */
	char    asBillType[SMSP1_TICKET_BUFLEN_IN][2];
		/* MO，MT标志 */
	char    asMoFlag[SMSP1_TICKET_BUFLEN_IN][2];
		/* 发送状态 */
	char    asLastStatus[SMSP1_TICKET_BUFLEN_IN][5];
		/* 优先级 */
	char    asPriority[SMSP1_TICKET_BUFLEN_IN][2];
		/* 消息数 */
	int     aiMsgCnt[SMSP1_TICKET_BUFLEN_IN];
		/* 用户归属 */
	char    asHomeAreaCode[SMSP1_TICKET_BUFLEN_IN][5];
		/* 短信网关 */
	char    asSmg[SMSP1_TICKET_BUFLEN_IN][6];
		/* 关联网关 */
	char    asTsmg[SMSP1_TICKET_BUFLEN_IN][6];
		/* 短信中心 */
	char    asSmsc[SMSP1_TICKET_BUFLEN_IN][14];
		/* 申请时间 */
	char    asRegisterTime[SMSP1_TICKET_BUFLEN_IN][15];
		/* 短信发送时间 */
	char    asSendTime[SMSP1_TICKET_BUFLEN_IN][15];
		/* 保留 */
	char    asReserve[SMSP1_TICKET_BUFLEN_IN][28];
};


/*单个结构申明*/
struct Smsp1TicketStruct{

	struct Smsp1TicketStruct *pNext;
	char    sRegNo[31];		/* 命令序列 */
	char    sCallType[3];		/* 呼叫类型 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[14];		/* 计费号码 */
	char    sSpCode[6];		/* SP代码 */
	char    sSpHomeSmg[6];		/* SP归属网关代码 */
	char    sOtherParty[14];		/* 被叫号码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sServiceCode[11];		/* 业务代码 */
	char    sBillingType[2];		/* 用户计费类型 */
	int     iInfoFee;		/* 信息费 */
	int     iRentFee;		/* 包月费 */
	int     iReturnFee;		/* 返还话费 */
	char    sBillType[2];		/* 代收费标致 */
	char    sMoFlag[2];		/* MO，MT标志 */
	char    sLastStatus[5];		/* 发送状态 */
	char    sPriority[2];		/* 优先级 */
	int     iMsgCnt;		/* 消息数 */
	char    sHomeAreaCode[5];		/* 用户归属 */
	char    sSmg[6];		/* 短信网关 */
	char    sTsmg[6];		/* 关联网关 */
	char    sSmsc[14];		/* 短信中心 */
	char    sRegisterTime[15];		/* 申请时间 */
	char    sSendTime[15];		/* 短信发送时间 */
	char    sReserve[28];		/* 保留 */
	struct Smsp1TicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSmsp1TicketStruct{

	char    sRegNo[30];		/* 命令序列 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sUserType[1];		/* 用户类型 */
	char    sMsisdn[13];		/* 计费号码 */
	char    sSpCode[5];		/* SP代码 */
	char    sSpHomeSmg[5];		/* SP归属网关代码 */
	char    sOtherParty[13];		/* 被叫号码 */
	char    sSpAccNbr[12];		/* SP接入码 */
	char    sServiceCode[10];		/* 业务代码 */
	char    sBillingType[1];		/* 用户计费类型 */
	char    sInfoFee[6];		/* 信息费 */
	char    sRentFee[6];		/* 包月费 */
	char    sReturnFee[6];		/* 返还话费 */
	char    sBillType[1];		/* 代收费标致 */
	char    sMoFlag[1];		/* MO，MT标志 */
	char    sLastStatus[4];		/* 发送状态 */
	char    sPriority[1];		/* 优先级 */
	char    sMsgCnt[2];		/* 消息数 */
	char    sHomeAreaCode[4];		/* 用户归属 */
	char    sSmg[5];		/* 短信网关 */
	char    sTsmg[5];		/* 关联网关 */
	char    sSmsc[13];		/* 短信中心 */
	char    sRegisterTime[14];		/* 申请时间 */
	char    sSendTime[14];		/* 短信发送时间 */
	char    sReserve[27];		/* 保留 */
};

/*单个结构申明*/
struct Sp1xfjTicketStruct{

	struct Sp1xfjTicketStruct *pNext;
	char    sSeqNumber[11];
	char    sRecordType[2];
	char    sSpCode[9];
	char    sSpLoginName[33];
	char    sMsIpAddress[16];
	char    sSpSrvType[3];
	char    sSpSrvTypeName[41];
	char    sSpServiceType[3];
	char    sSpServiceCode[11];
	char    sSpServiceName[41];
	char    sContentCode[11];
	char    sContentName[41];
	char    sMsisdn[21];
	char    sImsi[16];
	char    sNai[33];
	char    sNaiDomain[33];
	char    sStartTime[15];
	char    sStopTime[15];
	char    sActionCount[11];
	char    sActiveTime[7];
	char    sDataCountTermination[11];
	char    sDataCountOrigination[11];
	char    sDataCountTotal[11];
	char    sPreDiscntFee[11];
	char    sPostDiscntFee[11];
	char    sDiscntFee[11];
	char    sRateUnit[5];
	char    sFeeType[5];
	char    sFeeRateDescCode[21];
	char    sDiscntDescCode[21];
	char    sUrl[301];
	char    sSysID[9];
	char    sSysIntraKey[31];
	char    sUserType[2];
	char    sOtherParty[21];
	char    sBillType[11];
	char    sNoused1[10];
	char    sNoused2[13];
	char    sNoused3[13];
	char    sNoused4[41];
	struct Sp1xfjTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSp1xfjTicketStruct{

	char    sSeqNumber[10];
	char    sRecordType[1];
	char    sSpCode[8];
	char    sSpLoginName[32];
	char    sMsIpAddress[15];
	char    sSpSrvType[2];
	char    sSpSrvTypeName[40];
	char    sSpServiceType[2];
	char    sSpServiceCode[10];
	char    sSpServiceName[40];
	char    sContentCode[10];
	char    sContentName[40];
	char    sMsisdn[20];
	char    sImsi[15];
	char    sNai[32];
	char    sNaiDomain[32];
	char    sStartTime[14];
	char    sStopTime[14];
	char    sActionCount[10];
	char    sActiveTime[6];
	char    sDataCountTermination[10];
	char    sDataCountOrigination[10];
	char    sDataCountTotal[10];
	char    sPreDiscntFee[10];
	char    sPostDiscntFee[10];
	char    sDiscntFee[10];
	char    sRateUnit[4];
	char    sFeeType[4];
	char    sFeeRateDescCode[20];
	char    sDiscntDescCode[20];
	char    sUrl[300];
	char    sSysID[8];
	char    sSysIntraKey[30];
	char    sUserType[1];
	char    sOtherParty[20];
	char    sBillType[10];
	char    sNoused1[9];
	char    sNoused2[12];
	char    sNoused3[12];
	char    sNoused4[40];
};


/* 输入结构缓冲申明*/
struct Sp1xfjTicketStructIn{

#ifndef SP1XFJ_TICKET_BUFLEN_IN
#define SP1XFJ_TICKET_BUFLEN_IN		1000
#endif

	struct Sp1xfjTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSeqNumber[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asRecordType[SP1XFJ_TICKET_BUFLEN_IN][2];
	char    asSpCode[SP1XFJ_TICKET_BUFLEN_IN][9];
	char    asSpLoginName[SP1XFJ_TICKET_BUFLEN_IN][33];
	char    asMsIpAddress[SP1XFJ_TICKET_BUFLEN_IN][16];
	char    asSpSrvType[SP1XFJ_TICKET_BUFLEN_IN][3];
	char    asSpSrvTypeName[SP1XFJ_TICKET_BUFLEN_IN][41];
	char    asSpServiceType[SP1XFJ_TICKET_BUFLEN_IN][3];
	char    asSpServiceCode[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asSpServiceName[SP1XFJ_TICKET_BUFLEN_IN][41];
	char    asContentCode[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asContentName[SP1XFJ_TICKET_BUFLEN_IN][41];
	char    asMsisdn[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asImsi[SP1XFJ_TICKET_BUFLEN_IN][16];
	char    asNai[SP1XFJ_TICKET_BUFLEN_IN][33];
	char    asNaiDomain[SP1XFJ_TICKET_BUFLEN_IN][33];
	char    asStartTime[SP1XFJ_TICKET_BUFLEN_IN][15];
	char    asStopTime[SP1XFJ_TICKET_BUFLEN_IN][15];
	char    asActionCount[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asActiveTime[SP1XFJ_TICKET_BUFLEN_IN][7];
	char    asDataCountTermination[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asDataCountOrigination[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asDataCountTotal[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asPreDiscntFee[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asPostDiscntFee[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asDiscntFee[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asRateUnit[SP1XFJ_TICKET_BUFLEN_IN][5];
	char    asFeeType[SP1XFJ_TICKET_BUFLEN_IN][5];
	char    asFeeRateDescCode[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asDiscntDescCode[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asUrl[SP1XFJ_TICKET_BUFLEN_IN][301];
	char    asSysID[SP1XFJ_TICKET_BUFLEN_IN][9];
	char    asSysIntraKey[SP1XFJ_TICKET_BUFLEN_IN][31];
	char    asUserType[SP1XFJ_TICKET_BUFLEN_IN][2];
	char    asOtherParty[SP1XFJ_TICKET_BUFLEN_IN][21];
	char    asBillType[SP1XFJ_TICKET_BUFLEN_IN][11];
	char    asNoused1[SP1XFJ_TICKET_BUFLEN_IN][10];
	char    asNoused2[SP1XFJ_TICKET_BUFLEN_IN][13];
	char    asNoused3[SP1XFJ_TICKET_BUFLEN_IN][13];
	char    asNoused4[SP1XFJ_TICKET_BUFLEN_IN][41];
};

/*单个结构申明*/
struct SmspfjTicketStruct{

	struct SmspfjTicketStruct *pNext;
	char    sBusiType[3];
	char    sCallType[2];
	char    sMsisdn[14];
	char    sUserType[2];
	char    sHomeAreaCode[5];
	char    sCallingNbr[14];
	char    sCalledNbr[14];
	char    sSpCode[11];
	char    sSpServiceCode[21];
	char    sFeeType[2];
	char    sDuration[5];
	char    sCnt[5];
	char    sStartTime[15];
	char    sBaseFee[7];
	char    sInfoFee[7];
	char    sRentFee[7];
	char    sInfoFeeType[3];
	char    sOriFileName[21];
	char    sReserve[21];
	struct SmspfjTicketStruct *pLoadNext;
};


/* 输入结构缓冲申明*/
struct SmspfjTicketStructIn{

#ifndef SMSPFJ_TICKET_BUFLEN_IN
#define SMSPFJ_TICKET_BUFLEN_IN		1000
#endif

	struct SmspfjTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asBusiType[SMSPFJ_TICKET_BUFLEN_IN][3];
	char    asCallType[SMSPFJ_TICKET_BUFLEN_IN][2];
	char    asMsisdn[SMSPFJ_TICKET_BUFLEN_IN][14];
	char    asUserType[SMSPFJ_TICKET_BUFLEN_IN][2];
	char    asHomeAreaCode[SMSPFJ_TICKET_BUFLEN_IN][5];
	char    asCallingNbr[SMSPFJ_TICKET_BUFLEN_IN][14];
	char    asCalledNbr[SMSPFJ_TICKET_BUFLEN_IN][14];
	char    asSpCode[SMSPFJ_TICKET_BUFLEN_IN][11];
	char    asSpServiceCode[SMSPFJ_TICKET_BUFLEN_IN][21];
	char    asFeeType[SMSPFJ_TICKET_BUFLEN_IN][2];
	char    asDuration[SMSPFJ_TICKET_BUFLEN_IN][5];
	char    asCnt[SMSPFJ_TICKET_BUFLEN_IN][5];
	char    asStartTime[SMSPFJ_TICKET_BUFLEN_IN][15];
	char    asBaseFee[SMSPFJ_TICKET_BUFLEN_IN][7];
	char    asInfoFee[SMSPFJ_TICKET_BUFLEN_IN][7];
	char    asRentFee[SMSPFJ_TICKET_BUFLEN_IN][7];
	char    asInfoFeeType[SMSPFJ_TICKET_BUFLEN_IN][3];
	char    asOriFileName[SMSPFJ_TICKET_BUFLEN_IN][21];
	char    asReserve[SMSPFJ_TICKET_BUFLEN_IN][21];
};


/*单个文件结构申明*/
struct FSmspfjTicketStruct{

	char    sBusiType[2];
	char    sCallType[1];
	char    sMsisdn[13];
	char    sUserType[1];
	char    sHomeAreaCode[4];
	char    sCallingNbr[13];
	char    sCalledNbr[13];
	char    sSpCode[10];
	char    sSpServiceCode[20];
	char    sFeeType[1];
	char    sDuration[4];
	char    sCnt[4];
	char    sStartTime[14];
	char    sBaseFee[6];
	char    sInfoFee[6];
	char    sRentFee[6];
	char    sInfoFeeType[2];
	char    sOriFileName[20];
	char    sReserve[20];
};

/*批量数据动态从SMSP1_TICKET中用结构缓冲方式取数据*/
int EGetSmsp1TicketToStruct(struct Smsp1TicketStruct *p,
	struct Smsp1TicketStructIn *pSource);
void mvitem_mfsmsp1ticket(struct Smsp1TicketStruct *pi,struct FSmsp1TicketStruct *po);

int EGetSp1xfjTicketToStruct(struct Sp1xfjTicketStruct *p,
	struct Sp1xfjTicketStructIn *pSource);
void mvitem_mfs1xfjticket(struct Sp1xfjTicketStruct *pi,struct FSp1xfjTicketStruct *po);

int EGetSmspfjTicketToStruct(struct SmspfjTicketStruct *p,
	struct SmspfjTicketStructIn *pSource);
void mvitem_mfsspfjticket(struct SmspfjTicketStruct *pi,struct FSmspfjTicketStruct *po);

int SmcdmaTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmgsmTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmmobTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmtelTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int Smsp1Ticket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int Sp1xfjTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SmspfjTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*单个结构申明*/
struct SmsStatStruct{

	struct SmsStatStruct *pNext;
	char    sRecordType[3];
	char    sCallType[2];
	char    sMsisdn[14];
	char    sUserType[2];
	char    sHomeAreaCode[5];
	char    sStartTime[15];
	int     iBaseFee;
	int     iInfoFee;
	char    sOriFileName[41];
};

/* 输入结构缓冲申明*/
struct SmsStatStructIn{

#ifndef SMS_STAT_BUFLEN_IN
#define SMS_STAT_BUFLEN_IN		1000
#endif

	struct SmsStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[256];
	char    asRecordType[SMS_STAT_BUFLEN_IN][3];
	char    asCallType[SMS_STAT_BUFLEN_IN][2];
	char    asMsisdn[SMS_STAT_BUFLEN_IN][14];
	char    asUserType[SMS_STAT_BUFLEN_IN][2];
	char    asHomeAreaCode[SMS_STAT_BUFLEN_IN][5];
	char    asStartTime[SMS_STAT_BUFLEN_IN][15];
	int     aiBaseFee[SMS_STAT_BUFLEN_IN];
	int     aiInfoFee[SMS_STAT_BUFLEN_IN];
	char    asOriFileName[SMS_STAT_BUFLEN_IN][41];
};

/*单个结构申明*/
struct SmsNbrStatStruct{

	struct SmsNbrStatStruct *pNext;
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sTicketType[3];		/* 00－G网网内 01－C网网内	02－移动互通 03－小灵通互通 04－国际短信 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[16];		/* 用户号码 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
};

/*单个结构申明*/
struct RSmsNbrStatStruct{

	struct RSmsNbrStatStruct *pNext;
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sTicketType[3];		/* 00－G网网内 01－C网网内	02－移动互通 03－小灵通互通 04－国际短信 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[16];		/* 用户号码 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	char    sRowID[19];		/* 记录索引 */
};

/*单个结构申明*/
struct USmsNbrStatStruct{

	struct USmsNbrStatStruct *pNext;
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sTicketType[3];		/* 00－G网网内 01－C网网内	02－移动互通 03－小灵通互通 04－国际短信 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[16];		/* 用户号码 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	char	sRowID[19];	
};

/*输出结构缓冲申明*/
struct USmsNbrStatStructUp{

#ifndef SMS_NBR_STAT_BUFLEN_UP
#define SMS_NBR_STAT_BUFLEN_UP		1000
#endif

	struct USmsNbrStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐务周期 */
	char    asBillingCycleID[SMS_NBR_STAT_BUFLEN_UP][7];
		/* 00－G网网内 01－C网网内	02－移动互通 03－小灵通互通 04－国际短信 */
	char    asTicketType[SMS_NBR_STAT_BUFLEN_UP][3];
		/* 用户类型 */
	char    asUserType[SMS_NBR_STAT_BUFLEN_UP][2];
		/* 用户号码 */
	char    asMsisdn[SMS_NBR_STAT_BUFLEN_UP][16];
		/* 总通信费 */
	int     aiTotalCommFee[SMS_NBR_STAT_BUFLEN_UP];
		/* 短信发次数 */
	int     aiMoCnt[SMS_NBR_STAT_BUFLEN_UP];
		/* 短信收次数 */
	int     aiMtCnt[SMS_NBR_STAT_BUFLEN_UP];
		/* 最早发送时间 */
	char    asMinStartTime[SMS_NBR_STAT_BUFLEN_UP][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMS_NBR_STAT_BUFLEN_UP][15];
		/* 号码归属局 */
	char    asHomeAreaCode[SMS_NBR_STAT_BUFLEN_UP][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMS_NBR_STAT_BUFLEN_UP][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMS_NBR_STAT_BUFLEN_UP][15];
	char	asRowID[SMS_NBR_STAT_BUFLEN_UP][19];	
};

/*输出结构缓冲申明*/
struct SmsNbrStatStructOut{

#ifndef SMS_NBR_STAT_BUFLEN_OUT
#define SMS_NBR_STAT_BUFLEN_OUT		1000
#endif

	struct SmsNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐务周期 */
	char    asBillingCycleID[SMS_NBR_STAT_BUFLEN_OUT][7];
		/* 00－G网网内 01－C网网内	02－移动互通 03－小灵通互通 04－国际短信 */
	char    asTicketType[SMS_NBR_STAT_BUFLEN_OUT][3];
		/* 用户类型 */
	char    asUserType[SMS_NBR_STAT_BUFLEN_OUT][2];
		/* 用户号码 */
	char    asMsisdn[SMS_NBR_STAT_BUFLEN_OUT][16];
		/* 总通信费 */
	int     aiTotalCommFee[SMS_NBR_STAT_BUFLEN_OUT];
		/* 短信发次数 */
	int     aiMoCnt[SMS_NBR_STAT_BUFLEN_OUT];
		/* 短信收次数 */
	int     aiMtCnt[SMS_NBR_STAT_BUFLEN_OUT];
		/* 最早发送时间 */
	char    asMinStartTime[SMS_NBR_STAT_BUFLEN_OUT][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMS_NBR_STAT_BUFLEN_OUT][15];
		/* 号码归属局 */
	char    asHomeAreaCode[SMS_NBR_STAT_BUFLEN_OUT][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMS_NBR_STAT_BUFLEN_OUT][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMS_NBR_STAT_BUFLEN_OUT][15];
};

/* 输入结构缓冲申明*/
struct SmsNbrStatStructIn{

#ifndef SMS_NBR_STAT_BUFLEN_IN
#define SMS_NBR_STAT_BUFLEN_IN		1000
#endif

	struct SmsNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐务周期 */
	char    asBillingCycleID[SMS_NBR_STAT_BUFLEN_IN][7];
		/* 00－G网网内 01－C网网内	02－移动互通 03－小灵通互通 04－国际短信 */
	char    asTicketType[SMS_NBR_STAT_BUFLEN_IN][3];
		/* 用户类型 */
	char    asUserType[SMS_NBR_STAT_BUFLEN_IN][2];
		/* 用户号码 */
	char    asMsisdn[SMS_NBR_STAT_BUFLEN_IN][16];
		/* 总通信费 */
	int     aiTotalCommFee[SMS_NBR_STAT_BUFLEN_IN];
		/* 短信发次数 */
	int     aiMoCnt[SMS_NBR_STAT_BUFLEN_IN];
		/* 短信收次数 */
	int     aiMtCnt[SMS_NBR_STAT_BUFLEN_IN];
		/* 最早发送时间 */
	char    asMinStartTime[SMS_NBR_STAT_BUFLEN_IN][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMS_NBR_STAT_BUFLEN_IN][15];
		/* 号码归属局 */
	char    asHomeAreaCode[SMS_NBR_STAT_BUFLEN_IN][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMS_NBR_STAT_BUFLEN_IN][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMS_NBR_STAT_BUFLEN_IN][15];
};

/* 输入结构缓冲申明*/
struct 	RSmsNbrStatStructIn{

#ifndef R_SMS_NBR_STAT_BUFLEN_IN
#define R_SMS_NBR_STAT_BUFLEN_IN		1000
#endif

	struct RSmsNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐务周期 */
	char    asBillingCycleID[R_SMS_NBR_STAT_BUFLEN_IN][7];
		/* 00－G网网内 01－C网网内	02－移动互通 03－小灵通互通 04－国际短信 */
	char    asTicketType[R_SMS_NBR_STAT_BUFLEN_IN][3];
		/* 用户类型 */
	char    asUserType[R_SMS_NBR_STAT_BUFLEN_IN][2];
		/* 用户号码 */
	char    asMsisdn[R_SMS_NBR_STAT_BUFLEN_IN][16];
		/* 总通信费 */
	int     aiTotalCommFee[R_SMS_NBR_STAT_BUFLEN_IN];
		/* 短信发次数 */
	int     aiMoCnt[R_SMS_NBR_STAT_BUFLEN_IN];
		/* 短信收次数 */
	int     aiMtCnt[R_SMS_NBR_STAT_BUFLEN_IN];
		/* 最早发送时间 */
	char    asMinStartTime[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* 号码归属局 */
	char    asHomeAreaCode[R_SMS_NBR_STAT_BUFLEN_IN][6];
		/* 记录生成日期 */
	char    asCreatedDate[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* 记录更新日期 */
	char    asUpdatedDate[R_SMS_NBR_STAT_BUFLEN_IN][15];
		/* 记录索引 */
	char    asRowID[R_SMS_NBR_STAT_BUFLEN_IN][19];
	
};


int EGetSmsStatToStruct(struct SmsStatStruct *p,struct SmsStatStructIn *pSource);
int EInsertStructToSmsNbrStat(struct SmsNbrStatStruct *p,
	int iInsertFlag,struct SmsNbrStatStructOut *pTarget);
int InsertSmsNbrStat(struct SmsNbrStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag);
int data_bintree_search_sms_nbr_stat(void *pValue,void*pData);
void assign_bintree_insert_sms_nbr_stat(void **ppData,void *pData);
int rdata_search_bintree_sms_nbr(void *pValue,void*pData);
void rassign_bintree_insert_sms_nbr(void **ppData,void *pData);
void assign_bintree_insert_sms_nbr(void **ppData,void *pData);
void InsertSmsNbrFee(void *pValue,void*pData);
int node_pthead_sms_stat_e(void **ppHead);
int SmsStatTicket2Bintree(BINTREE **ppRoot,char sTableName[],char sCondition[]);
int SmsNbrStatDataSum(BINTREE **ppRoot,struct SmsNbrStatStruct *pValue,
	char sBillingCycle[],char sTableName[]);
int EGetSmsNbrStatToStruct(struct RSmsNbrStatStruct *p,
	struct RSmsNbrStatStructIn *pSource);
int SmsNbrStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[]);
void mvitem_rsmsnbrstat(struct SmsNbrStatStruct *pi,struct RSmsNbrStatStruct *po);
void mvitem_usmsnbrstat(struct RSmsNbrStatStruct *pi,struct USmsNbrStatStruct *po);
void mvitem_smsnbrstat(struct RSmsNbrStatStruct *pi,struct SmsNbrStatStruct *po);
int UpdateSmsNbrStat(struct USmsNbrStatStruct *pSourcet,char sTableName[],
	int iUpdateFlag);
int EUpdateStructToUSmsNbrStat(struct USmsNbrStatStruct *p,
	int iUpdateFlag,struct USmsNbrStatStructUp *pTarget);


/*单个结构申明*/
struct SmspNbrRentStatStruct{

	struct SmspNbrRentStatStruct *pNext;
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sSpCode[6];		/* SP企业代码 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	char    sSpServiceCode[11];		/* SP企业业务代码 */
	char    sBillingType[3];		/* 计费类别 */
	int     iRentRate;		/* 月租费率 */
	char    sMoFlag[2];		/* MO标志 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	struct SmspNbrRentStatStruct *pLoadNext;
};



/*输出结构缓冲申明*/
struct SmspNbrRentStatStructOut{

#ifndef SMSP_NBR_RENT_STAT_BUFLEN_OUT
#define SMSP_NBR_RENT_STAT_BUFLEN_OUT		1000
#endif

	struct SmspNbrRentStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_NBR_RENT_STAT_BUFLEN_OUT][7];
		/* 用户类型 */
	char    asUserType[SMSP_NBR_RENT_STAT_BUFLEN_OUT][2];
		/* 用户号码 */
	char    asMsisdn[SMSP_NBR_RENT_STAT_BUFLEN_OUT][16];
		/* SP企业代码 */
	char    asSpCode[SMSP_NBR_RENT_STAT_BUFLEN_OUT][6];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_NBR_RENT_STAT_BUFLEN_OUT][13];
		/* SP企业业务代码 */
	char    asSpServiceCode[SMSP_NBR_RENT_STAT_BUFLEN_OUT][11];
		/* 计费类别 */
	char    asBillingType[SMSP_NBR_RENT_STAT_BUFLEN_OUT][3];
		/* 月租费率 */
	int     aiRentRate[SMSP_NBR_RENT_STAT_BUFLEN_OUT];
		/* MO标志 */
	char    asMoFlag[SMSP_NBR_RENT_STAT_BUFLEN_OUT][2];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_NBR_RENT_STAT_BUFLEN_OUT][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_NBR_RENT_STAT_BUFLEN_OUT][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_NBR_RENT_STAT_BUFLEN_OUT][15];
};




/* 输入结构缓冲申明*/
struct SmspNbrRentStatStructIn{

#ifndef SMSP_NBR_RENT_STAT_BUFLEN_IN
#define SMSP_NBR_RENT_STAT_BUFLEN_IN		1000
#endif

	struct SmspNbrRentStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_NBR_RENT_STAT_BUFLEN_IN][7];
		/* 用户类型 */
	char    asUserType[SMSP_NBR_RENT_STAT_BUFLEN_IN][2];
		/* 用户号码 */
	char    asMsisdn[SMSP_NBR_RENT_STAT_BUFLEN_IN][16];
		/* SP企业代码 */
	char    asSpCode[SMSP_NBR_RENT_STAT_BUFLEN_IN][6];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_NBR_RENT_STAT_BUFLEN_IN][13];
		/* SP企业业务代码 */
	char    asSpServiceCode[SMSP_NBR_RENT_STAT_BUFLEN_IN][11];
		/* 计费类别 */
	char    asBillingType[SMSP_NBR_RENT_STAT_BUFLEN_IN][3];
		/* 月租费率 */
	int     aiRentRate[SMSP_NBR_RENT_STAT_BUFLEN_IN];
		/* MO标志 */
	char    asMoFlag[SMSP_NBR_RENT_STAT_BUFLEN_IN][2];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_NBR_RENT_STAT_BUFLEN_IN][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_NBR_RENT_STAT_BUFLEN_IN][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_NBR_RENT_STAT_BUFLEN_IN][15];
};


int EInsertStructToSmspNbrRentStat(struct SmspNbrRentStatStruct *p,
	int iInsertFlag,struct SmspNbrRentStatStructOut *pTarget);
int InsertSmspNbrRentStat(struct SmspNbrRentStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag);
int SmsTicket2Bintree(BINTREE **ppRoot,BINTREE ** ppRootS,BINTREE ** ppRootN,
	char sTableName[],char sCondition[],char sStatType[]);
void assign_bintree_insert_smsp_nbr_rent_stat(void **ppData,void *pData);
int data_bintree_search_smsp_nbr_rent_stat(void *pValue,void*pData);
int data_bintree_search_smsp_nbr_rent(void *pValue,void*pData);
void assign_bintree_insert_smsp_nbr_rent(void **ppData,void *pData);
int SmspNbrRentStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[]);
int EGetSmspNbrRentStatToStruct(struct SmspNbrRentStatStruct *p,
	struct SmspNbrRentStatStructIn *pSource);
int SmspNbrRentStatDataSum(BINTREE **ppRoot,struct SmspNbrRentStatStruct *pValue,
	char sBillingCycle[],char sTableName[]);
	
	

/*单个结构申明*/
struct SmspSpStatStruct{

	struct SmspSpStatStruct *pNext;
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sUserType[2];		/* 用户类型 */
	char    sSpCode[6];		/* SP企业代码 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	int     iTotalCnt;		/* 总次数 */
	int     iTotalFee;		/* 总费用 */
	int     iTotalInfoFee;		/* 总信息费 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iTotalRentFee;		/* 总月租费 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	struct SmspSpStatStruct *pLoadNext;
};


/* 输入结构缓冲申明*/
struct SmspSpStatStructIn{

#ifndef SMSP_SP_STAT_BUFLEN_IN
#define SMSP_SP_STAT_BUFLEN_IN		1000
#endif

	struct SmspSpStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_SP_STAT_BUFLEN_IN][7];
		/* 用户类型 */
	char    asUserType[SMSP_SP_STAT_BUFLEN_IN][2];
		/* SP企业代码 */
	char    asSpCode[SMSP_SP_STAT_BUFLEN_IN][6];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_SP_STAT_BUFLEN_IN][13];
		/* 最早发送时间 */
	char    asMinStartTime[SMSP_SP_STAT_BUFLEN_IN][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMSP_SP_STAT_BUFLEN_IN][15];
		/* 短信发次数 */
	int     aiMoCnt[SMSP_SP_STAT_BUFLEN_IN];
		/* 短信收次数 */
	int     aiMtCnt[SMSP_SP_STAT_BUFLEN_IN];
		/* 总次数 */
	int     aiTotalCnt[SMSP_SP_STAT_BUFLEN_IN];
		/* 总费用 */
	int     aiTotalFee[SMSP_SP_STAT_BUFLEN_IN];
		/* 总信息费 */
	int     aiTotalInfoFee[SMSP_SP_STAT_BUFLEN_IN];
		/* 总通信费 */
	int     aiTotalCommFee[SMSP_SP_STAT_BUFLEN_IN];
		/* 总月租费 */
	int     aiTotalRentFee[SMSP_SP_STAT_BUFLEN_IN];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_SP_STAT_BUFLEN_IN][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_SP_STAT_BUFLEN_IN][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_SP_STAT_BUFLEN_IN][15];
};

/* 输入结构缓冲申明*/
struct RSmspSpStatStructIn{

#ifndef R_SMSP_SP_STAT_BUFLEN_IN
#define R_SMSP_SP_STAT_BUFLEN_IN		1000
#endif

	struct RSmspSpStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐务周期 */
	char    asBillingCycleID[R_SMSP_SP_STAT_BUFLEN_IN][7];
		/* 用户类型 */
	char    asUserType[R_SMSP_SP_STAT_BUFLEN_IN][2];
		/* SP企业代码 */
	char    asSpCode[R_SMSP_SP_STAT_BUFLEN_IN][6];
		/* SP接入代码 */
	char    asSpAccNbr[R_SMSP_SP_STAT_BUFLEN_IN][13];
		/* 最早发送时间 */
	char    asMinStartTime[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* 短信发次数 */
	int     aiMoCnt[R_SMSP_SP_STAT_BUFLEN_IN];
		/* 短信收次数 */
	int     aiMtCnt[R_SMSP_SP_STAT_BUFLEN_IN];
		/* 总次数 */
	int     aiTotalCnt[R_SMSP_SP_STAT_BUFLEN_IN];
		/* 总费用 */
	int     aiTotalFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* 总信息费 */
	int     aiTotalInfoFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* 总通信费 */
	int     aiTotalCommFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* 总月租费 */
	int     aiTotalRentFee[R_SMSP_SP_STAT_BUFLEN_IN];
		/* 号码归属局 */
	char    asHomeAreaCode[R_SMSP_SP_STAT_BUFLEN_IN][6];
		/* 记录生成日期 */
	char    asCreatedDate[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* 记录更新日期 */
	char    asUpdatedDate[R_SMSP_SP_STAT_BUFLEN_IN][15];
		/* 记录索引 */
	char    asRowID[R_SMS_NBR_STAT_BUFLEN_IN][19];	
};


/*输出结构缓冲申明*/
struct USmspSpStatStructUp{

#ifndef SMSP_SP_STAT_BUFLEN_UP
#define SMSP_SP_STAT_BUFLEN_UP		1000
#endif

	struct USmspSpStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_SP_STAT_BUFLEN_UP][7];
		/* 用户类型 */
	char    asUserType[SMSP_SP_STAT_BUFLEN_UP][2];
		/* SP企业代码 */
	char    asSpCode[SMSP_SP_STAT_BUFLEN_UP][6];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_SP_STAT_BUFLEN_UP][13];
		/* 最早发送时间 */
	char    asMinStartTime[SMSP_SP_STAT_BUFLEN_UP][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMSP_SP_STAT_BUFLEN_UP][15];
		/* 短信发次数 */
	int     aiMoCnt[SMSP_SP_STAT_BUFLEN_UP];
		/* 短信收次数 */
	int     aiMtCnt[SMSP_SP_STAT_BUFLEN_UP];
		/* 总次数 */
	int     aiTotalCnt[SMSP_SP_STAT_BUFLEN_UP];
		/* 总费用 */
	int     aiTotalFee[SMSP_SP_STAT_BUFLEN_UP];
		/* 总信息费 */
	int     aiTotalInfoFee[SMSP_SP_STAT_BUFLEN_UP];
		/* 总通信费 */
	int     aiTotalCommFee[SMSP_SP_STAT_BUFLEN_UP];
		/* 总月租费 */
	int     aiTotalRentFee[SMSP_SP_STAT_BUFLEN_UP];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_SP_STAT_BUFLEN_UP][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_SP_STAT_BUFLEN_UP][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_SP_STAT_BUFLEN_UP][15];
		/* 记录索引 */
	char    asRowID[SMSP_SP_STAT_BUFLEN_UP][19];	
};


/*单个结构申明*/
struct RSmspSpStatStruct{

	struct RSmspSpStatStruct *pNext;
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sUserType[2];		/* 用户类型 */
	char    sSpCode[6];		/* SP企业代码 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	int     iTotalCnt;		/* 总次数 */
	int     iTotalFee;		/* 总费用 */
	int     iTotalInfoFee;		/* 总信息费 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iTotalRentFee;		/* 总月租费 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	char    sRowID[19];		/* 记录索引 */	
	struct RSmspSpStatStruct *pLoadNext;
};

/*单个结构申明*/
struct USmspSpStatStruct{

	struct USmspSpStatStruct *pNext;
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sUserType[2];		/* 用户类型 */
	char    sSpCode[6];		/* SP企业代码 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	int     iTotalCnt;		/* 总次数 */
	int     iTotalFee;		/* 总费用 */
	int     iTotalInfoFee;		/* 总信息费 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iTotalRentFee;		/* 总月租费 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	char    sRowID[19];		/* 记录索引 */	
	struct USmspSpStatStruct *pLoadNext;
};


/*输出结构缓冲申明*/
struct SmspSpStatStructOut{

#ifndef SMSP_SP_STAT_BUFLEN_OUT
#define SMSP_SP_STAT_BUFLEN_OUT		1000
#endif

	struct SmspSpStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_SP_STAT_BUFLEN_OUT][7];
		/* 用户类型 */
	char    asUserType[SMSP_SP_STAT_BUFLEN_OUT][2];
		/* SP企业代码 */
	char    asSpCode[SMSP_SP_STAT_BUFLEN_OUT][6];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_SP_STAT_BUFLEN_OUT][13];
		/* 最早发送时间 */
	char    asMinStartTime[SMSP_SP_STAT_BUFLEN_OUT][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMSP_SP_STAT_BUFLEN_OUT][15];
		/* 短信发次数 */
	int     aiMoCnt[SMSP_SP_STAT_BUFLEN_OUT];
		/* 短信收次数 */
	int     aiMtCnt[SMSP_SP_STAT_BUFLEN_OUT];
		/* 总次数 */
	int     aiTotalCnt[SMSP_SP_STAT_BUFLEN_OUT];
		/* 总费用 */
	int     aiTotalFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* 总信息费 */
	int     aiTotalInfoFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* 总通信费 */
	int     aiTotalCommFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* 总月租费 */
	int     aiTotalRentFee[SMSP_SP_STAT_BUFLEN_OUT];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_SP_STAT_BUFLEN_OUT][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_SP_STAT_BUFLEN_OUT][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_SP_STAT_BUFLEN_OUT][15];
};




int SmspSpStatStructDataSum(BINTREE **ppRoot,struct SmspSpStatStruct *pValue,
	char sBillingCycle[],char sTableName[]);
int SmspSpStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[]);
int EGetSmspSpStatToStruct(struct RSmspSpStatStruct *p,
	struct RSmspSpStatStructIn *pSource);
void mvitem_smspspstat(struct RSmspSpStatStruct *pi,struct SmspSpStatStruct *po);
void mvitem_rsmspspstat(struct SmspSpStatStruct *pi,struct RSmspSpStatStruct *po);
void mvitem_usmspspstat(struct RSmspSpStatStruct *pi,struct USmspSpStatStruct *po);	
int EUpdateStructToUSmspSpStat(struct USmspSpStatStruct *p,
	int iUpdateFlag,struct USmspSpStatStructUp *pTarget);
int EInsertStructToSmspSpStat(struct SmspSpStatStruct *p,
	int iInsertFlag,struct SmspSpStatStructOut *pTarget);
int rdata_bintree_search_smsp_sp_stat(void *pValue,void*pData);
void rassign_bintree_insert_smsp_sp_stat(void **ppData,void *pData);
int data_bintree_search_smsp_sp_stat(void *pValue,void*pData);
void assign_bintree_insert_smsp_sp_stat(void **ppData,void *pData);
void InsertSmspSpFee(void *pValue,void*pData);
void InsertSmsNbrFeeTotal(void *pValue,void*pData);


/*单个结构申明*/
struct SmspNbrStatStruct{

	struct SmspNbrStatStruct *pNext;                              
	int     iTicketTypeID;		/* 话单类型标识 */            
	char    sBillingCycleID[7];		/* 帐务周期 */        
	char    sUserType[2];		/* 用户类型 */                
	char    sMsisdn[16];		/* 用户号码 */                
	int     iTotalFee;		/* 总费用 */                  
	int     iTotalInfoFee;		/* 总信息费 */                
	int     iTotalCommFee;		/* 总通信费 */                
	int     iTotalRentFee;		/* 总月租费 */                
	char    sSpCode[6];		/* SP企业代码 */              
	char    sSpServiceCode[11];		/* SP服务代码 */      
	char    sSpAccNbr[13];		/* SP接入代码 */              
	int     iMoCnt;		/* 短信发次数 */                      
	int     iMtCnt;		/* 短信收次数 */                      
	int     iTotalCnt;		/* 总次数 */                  
	char    sMinStartTime[15];		/* 最早发送时间 */    
	char    sMaxStartTime[15];		/* 最迟发送时间 */    
	char    sHomeAreaCode[6];		/* 号码归属局 */      
	char    sCreatedDate[15];		/* 记录生成日期 */    
	char    sUpdatedDate[15];		/* 记录更新日期 */    
	struct SmspNbrStatStruct *pLoadNext;                          
};

/*单个文件结构申明*/
struct FSmspNbrStatStruct{

	char    sTicketTypeID[4];
	char    sBillingCycleID[6];
	char    sUserType[1];
	char    sMsisdn[15];
	char    sTotalFee[9];
	char    sTotalInfoFee[9];
	char    sTotalCommFee[9];
	char    sTotalRentFee[9];
	char    sSpCode[5];
	char    sSpServiceCode[10];
	char    sSpAccNbr[12];
	char    sMoCnt[6];
	char    sMtCnt[6];
	char    sTotalCnt[6];
	char    sMinStartTime[14];
	char    sMaxStartTime[14];
	char    sHomeAreaCode[5];
	char    sCreatedDate[14];
	char    sUpdatedDate[14];
};

/*单个结构申明*/
struct RSmspNbrStatStruct{

	struct RSmspNbrStatStruct *pNext;
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[16];		/* 用户号码 */
	int     iTotalFee;		/* 总费用 */
	int     iTotalInfoFee;		/* 总信息费 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iTotalRentFee;		/* 总月租费 */
	char    sSpCode[6];		/* SP企业代码 */
	char    sSpServiceCode[11];		/* SP服务代码 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	int     iTotalCnt;		/* 总次数 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	char    sRowID[19];		/* 记录索引 */		
	struct RSmspNbrStatStruct *pLoadNext;
};

/*单个结构申明*/
struct USmspNbrStatStruct{

	struct USmspNbrStatStruct *pNext;
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sBillingCycleID[7];		/* 帐务周期 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[16];		/* 用户号码 */
	int     iTotalFee;		/* 总费用 */
	int     iTotalInfoFee;		/* 总信息费 */
	int     iTotalCommFee;		/* 总通信费 */
	int     iTotalRentFee;		/* 总月租费 */
	char    sSpCode[6];		/* SP企业代码 */
	char    sSpServiceCode[11];		/* SP服务代码 */
	char    sSpAccNbr[13];		/* SP接入代码 */
	int     iMoCnt;		/* 短信发次数 */
	int     iMtCnt;		/* 短信收次数 */
	int     iTotalCnt;		/* 总次数 */
	char    sMinStartTime[15];		/* 最早发送时间 */
	char    sMaxStartTime[15];		/* 最迟发送时间 */
	char    sHomeAreaCode[6];		/* 号码归属局 */
	char    sCreatedDate[15];		/* 记录生成日期 */
	char    sUpdatedDate[15];		/* 记录更新日期 */
	char    sRowID[19];		/* 记录索引 */		
	struct USmspNbrStatStruct *pLoadNext;
};



/* 输入结构缓冲申明*/
struct SmspNbrStatStructIn{

#ifndef SMSP_NBR_STAT_BUFLEN_IN
#define SMSP_NBR_STAT_BUFLEN_IN		1000
#endif

	struct SmspNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型标识 */
	int     aiTicketTypeID[SMSP_NBR_STAT_BUFLEN_IN];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_NBR_STAT_BUFLEN_IN][7];
		/* 用户类型 */
	char    asUserType[SMSP_NBR_STAT_BUFLEN_IN][2];
		/* 用户号码 */
	char    asMsisdn[SMSP_NBR_STAT_BUFLEN_IN][16];
		/* 总费用 */
	int     aiTotalFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* 总信息费 */
	int     aiTotalInfoFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* 总通信费 */
	int     aiTotalCommFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* 总月租费 */
	int     aiTotalRentFee[SMSP_NBR_STAT_BUFLEN_IN];
		/* SP企业代码 */
	char    asSpCode[SMSP_NBR_STAT_BUFLEN_IN][6];
		/* SP服务代码 */
	char    asSpServiceCode[SMSP_NBR_STAT_BUFLEN_IN][11];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_NBR_STAT_BUFLEN_IN][13];
		/* 短信发次数 */
	int     aiMoCnt[SMSP_NBR_STAT_BUFLEN_IN];
		/* 短信收次数 */
	int     aiMtCnt[SMSP_NBR_STAT_BUFLEN_IN];
		/* 总次数 */
	int     aiTotalCnt[SMSP_NBR_STAT_BUFLEN_IN];
		/* 最早发送时间 */
	char    asMinStartTime[SMSP_NBR_STAT_BUFLEN_IN][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMSP_NBR_STAT_BUFLEN_IN][15];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_NBR_STAT_BUFLEN_IN][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_NBR_STAT_BUFLEN_IN][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_NBR_STAT_BUFLEN_IN][15];
};


/* 输入结构缓冲申明*/
struct RSmspNbrStatStructIn{

#ifndef R_SMSP_NBR_STAT_BUFLEN_IN
#define R_SMSP_NBR_STAT_BUFLEN_IN		1000
#endif

	struct RSmspNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型标识 */
	int     aiTicketTypeID[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* 帐务周期 */
	char    asBillingCycleID[R_SMSP_NBR_STAT_BUFLEN_IN][7];
		/* 用户类型 */
	char    asUserType[R_SMSP_NBR_STAT_BUFLEN_IN][2];
		/* 用户号码 */
	char    asMsisdn[R_SMSP_NBR_STAT_BUFLEN_IN][16];
		/* 总费用 */
	int     aiTotalFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* 总信息费 */
	int     aiTotalInfoFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* 总通信费 */
	int     aiTotalCommFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* 总月租费 */
	int     aiTotalRentFee[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* SP企业代码 */
	char    asSpCode[R_SMSP_NBR_STAT_BUFLEN_IN][6];
		/* SP服务代码 */
	char    asSpServiceCode[R_SMSP_NBR_STAT_BUFLEN_IN][11];
		/* SP接入代码 */
	char    asSpAccNbr[R_SMSP_NBR_STAT_BUFLEN_IN][13];
		/* 短信发次数 */
	int     aiMoCnt[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* 短信收次数 */
	int     aiMtCnt[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* 总次数 */
	int     aiTotalCnt[R_SMSP_NBR_STAT_BUFLEN_IN];
		/* 最早发送时间 */
	char    asMinStartTime[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* 号码归属局 */
	char    asHomeAreaCode[R_SMSP_NBR_STAT_BUFLEN_IN][6];
		/* 记录生成日期 */
	char    asCreatedDate[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* 记录更新日期 */
	char    asUpdatedDate[R_SMSP_NBR_STAT_BUFLEN_IN][15];
		/* 记录索引 */
	char    asRowID[R_SMS_NBR_STAT_BUFLEN_IN][19];	
	
};


/*输出结构缓冲申明*/
struct SmspNbrStatStructOut{

#ifndef SMSP_NBR_STAT_BUFLEN_OUT
#define SMSP_NBR_STAT_BUFLEN_OUT		1000
#endif

	struct SmspNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型标识 */
	int     aiTicketTypeID[SMSP_NBR_STAT_BUFLEN_OUT];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_NBR_STAT_BUFLEN_OUT][7];
		/* 用户类型 */
	char    asUserType[SMSP_NBR_STAT_BUFLEN_OUT][2];
		/* 用户号码 */
	char    asMsisdn[SMSP_NBR_STAT_BUFLEN_OUT][16];
		/* 总费用 */
	int     aiTotalFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* 总信息费 */
	int     aiTotalInfoFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* 总通信费 */
	int     aiTotalCommFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* 总月租费 */
	int     aiTotalRentFee[SMSP_NBR_STAT_BUFLEN_OUT];
		/* SP企业代码 */
	char    asSpCode[SMSP_NBR_STAT_BUFLEN_OUT][6];
		/* SP服务代码 */
	char    asSpServiceCode[SMSP_NBR_STAT_BUFLEN_OUT][11];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_NBR_STAT_BUFLEN_OUT][13];
		/* 短信发次数 */
	int     aiMoCnt[SMSP_NBR_STAT_BUFLEN_OUT];
		/* 短信收次数 */
	int     aiMtCnt[SMSP_NBR_STAT_BUFLEN_OUT];
		/* 总次数 */
	int     aiTotalCnt[SMSP_NBR_STAT_BUFLEN_OUT];
		/* 最早发送时间 */
	char    asMinStartTime[SMSP_NBR_STAT_BUFLEN_OUT][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMSP_NBR_STAT_BUFLEN_OUT][15];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_NBR_STAT_BUFLEN_OUT][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_NBR_STAT_BUFLEN_OUT][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_NBR_STAT_BUFLEN_OUT][15];
};


/*输出结构缓冲申明*/
struct USmspNbrStatStructUp{

#ifndef SMSP_NBR_STAT_BUFLEN_UP
#define SMSP_NBR_STAT_BUFLEN_UP		1000
#endif

	struct USmspNbrStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型标识 */
	int     aiTicketTypeID[SMSP_NBR_STAT_BUFLEN_UP];
		/* 帐务周期 */
	char    asBillingCycleID[SMSP_NBR_STAT_BUFLEN_UP][7];
		/* 用户类型 */
	char    asUserType[SMSP_NBR_STAT_BUFLEN_UP][2];
		/* 用户号码 */
	char    asMsisdn[SMSP_NBR_STAT_BUFLEN_UP][16];
		/* 总费用 */
	int     aiTotalFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* 总信息费 */
	int     aiTotalInfoFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* 总通信费 */
	int     aiTotalCommFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* 总月租费 */
	int     aiTotalRentFee[SMSP_NBR_STAT_BUFLEN_UP];
		/* SP企业代码 */
	char    asSpCode[SMSP_NBR_STAT_BUFLEN_UP][6];
		/* SP服务代码 */
	char    asSpServiceCode[SMSP_NBR_STAT_BUFLEN_UP][11];
		/* SP接入代码 */
	char    asSpAccNbr[SMSP_NBR_STAT_BUFLEN_UP][13];
		/* 短信发次数 */
	int     aiMoCnt[SMSP_NBR_STAT_BUFLEN_UP];
		/* 短信收次数 */
	int     aiMtCnt[SMSP_NBR_STAT_BUFLEN_UP];
		/* 总次数 */
	int     aiTotalCnt[SMSP_NBR_STAT_BUFLEN_UP];
		/* 最早发送时间 */
	char    asMinStartTime[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* 最迟发送时间 */
	char    asMaxStartTime[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* 号码归属局 */
	char    asHomeAreaCode[SMSP_NBR_STAT_BUFLEN_UP][6];
		/* 记录生成日期 */
	char    asCreatedDate[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* 记录更新日期 */
	char    asUpdatedDate[SMSP_NBR_STAT_BUFLEN_UP][15];
		/* 记录索引 */
	char    asRowID[SMSP_NBR_STAT_BUFLEN_UP][19];	
	
};


int data_bintree_search_smsp_nbr_stat(void *pValue,void*pData);
void assign_bintree_insert_smsp_nbr_stat(void **ppData,void *pData);
int EGetSmspNbrStatToStruct(struct RSmspNbrStatStruct *p,
	struct RSmspNbrStatStructIn *pSource);
void mvitem_rsmspnbrstat(struct SmspNbrStatStruct *pi,struct RSmspNbrStatStruct *po);
void mvitem_usmspnbrstat(struct RSmspNbrStatStruct *pi,struct USmspNbrStatStruct *po);	
void mvitem_smspnbrstat(struct RSmspNbrStatStruct *pi,struct SmspNbrStatStruct *po);
int EInsertStructToSmspNbrStat(struct SmspNbrStatStruct *p,
	int iInsertFlag,struct SmspNbrStatStructOut *pTarget);
int EUpdateStructToSmspNbrStat(struct USmspNbrStatStruct *p,
	int iUpdateFlag,struct USmspNbrStatStructUp *pTarget);	
int rdata_bintree_search_smsp_nbr_stat(void *pValue,void*pData);
void rassign_bintree_insert_smsp_nbr_stat(void **ppData,void *pData);
void InsertSmspSpFeeTotal(void *pValue,void*pData);

void InsertSmspNbrFeeTotal(void *pValue,void*pData);
void InsertSmspNbrFee(void *pValue,void*pData);
void mvitem_mfsmspnbrstat(struct RSmspNbrStatStruct *pi,struct FSmspNbrStatStruct *po);	

/* 输入结构缓冲申明*/
struct SpAcctItemStructIn{

#ifndef SP_ACCT_ITEM_BUFLEN_IN
#define SP_ACCT_ITEM_BUFLEN_IN		300
#endif

	struct SpAcctItemStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[SP_ACCT_ITEM_BUFLEN_IN][16];
		/* 帐单归属帐期 */
	char    asBillingCycleID[SP_ACCT_ITEM_BUFLEN_IN][7];
		/* 实收帐期 */
	char    asPayCycleID[SP_ACCT_ITEM_BUFLEN_IN][7];
		/* SP代码 */
	char    asSpCode[SP_ACCT_ITEM_BUFLEN_IN][9];
		/* SP业务代码 */
	char    asSpServiceCode[SP_ACCT_ITEM_BUFLEN_IN][9];
		/* SP实收总费用 */
	char    asCharge[SP_ACCT_ITEM_BUFLEN_IN][11];
		/* 话单类型标识 */
	int     aiTicketTypeID[SP_ACCT_ITEM_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceCode[SP_ACCT_ITEM_BUFLEN_IN][2];
		/* 帐单销账时间 */
	char    asPayTime[SP_ACCT_ITEM_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SpAcctItemStruct{

	struct SpAcctItemStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sBillingCycleID[7];		/* 帐单归属帐期 */
	char    sPayCycleID[7];		/* 实收帐期 */
	char    sSpCode[9];		/* SP代码 */
	char    sSpServiceCode[9];		/* SP业务代码 */
	char    sCharge[11];		/* SP实收总费用 */
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sServiceCode[2];		/* 业务类型 */
	char    sPayTime[15];		/* 帐单销账时间 */
	struct SpAcctItemStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FSpAcctItemStruct{

	char    sMsisdn[15];
	char    sBillingCycleID[6];
	char    sPayCycleID[6];
	char    sSpCode[8];
	char    sSpServiceCode[8];
	char    sCharge[10];
	char    sTicketTypeID[4];
	char    sServiceCode[1];
	char    sPayTime[14];
};


/*输出结构缓冲申明*/
struct SpAcctItemStructOut{

#ifndef SP_ACCT_ITEM_BUFLEN_OUT
#define SP_ACCT_ITEM_BUFLEN_OUT		300
#endif

	struct SpAcctItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asMsisdn[SP_ACCT_ITEM_BUFLEN_OUT][16];
		/* 帐单归属帐期 */
	char    asBillingCycleID[SP_ACCT_ITEM_BUFLEN_OUT][7];
		/* 实收帐期 */
	char    asPayCycleID[SP_ACCT_ITEM_BUFLEN_OUT][7];
		/* SP代码 */
	char    asSpCode[SP_ACCT_ITEM_BUFLEN_OUT][9];
		/* SP业务代码 */
	char    asSpServiceCode[SP_ACCT_ITEM_BUFLEN_OUT][9];
		/* SP实收总费用 */
	char    asCharge[SP_ACCT_ITEM_BUFLEN_OUT][11];
		/* 话单类型标识 */
	int     aiTicketTypeID[SP_ACCT_ITEM_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceCode[SP_ACCT_ITEM_BUFLEN_OUT][2];
		/* 帐单销账时间 */
	char    asPayTime[SP_ACCT_ITEM_BUFLEN_OUT][15];
};

void DestroySpAcctItem(struct SpAcctItemStruct *ptHead);
int EGetSpAcctItemToStruct(struct SpAcctItemStruct *p,
	struct SpAcctItemStructIn *pSource);
int InitSpAcctItem(struct SpAcctItemStruct **pptHead,
	char sInputTable[]);
int EInsertStructToSpAcctItem(struct SpAcctItemStruct *p,        
	int iInsertFlag,struct SpAcctItemStructOut *pTarget);	
void mvitem_mfspacctitem(struct SpAcctItemStruct *pi,struct FSpAcctItemStruct *po);

int SmspNbrStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int SpAcctItem2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
/*输出结构缓冲申明*/
struct SmgTicketStructOut{

#ifndef SMG_TICKET_BUFLEN_OUT
#define SMG_TICKET_BUFLEN_OUT		300
#endif

	struct SmgTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 短消息标识 */
	char    asMessageID[SMG_TICKET_BUFLEN_OUT][21];
		/* 短消息类型 */
	char    asSmsType[SMG_TICKET_BUFLEN_OUT][2];
		/* 短消息子类型 */
	char    asSubType[SMG_TICKET_BUFLEN_OUT][2];
		/* 计费用户号码 */
	char    asMsisdn[SMG_TICKET_BUFLEN_OUT][22];
		/* SP号码 */
	char    asSpCode[SMG_TICKET_BUFLEN_OUT][11];
		/* 目的地号码 */
	char    asOtherParty[SMG_TICKET_BUFLEN_OUT][22];
		/* 业务代码 */
	char    asSpServiceCode[SMG_TICKET_BUFLEN_OUT][11];
		/* 用户计费类别 */
	char    asBillType[SMG_TICKET_BUFLEN_OUT][3];
		/* 信息费 */
	char    asInfoFee[SMG_TICKET_BUFLEN_OUT][7];
		/* 短消息发送优先级 */
	char    asPriority[SMG_TICKET_BUFLEN_OUT][2];
		/* 信息长度 */
	char    asMsgLen[SMG_TICKET_BUFLEN_OUT][4];
		/* 计费号码归属地的区号 */
	char    asHomeAreaCode[SMG_TICKET_BUFLEN_OUT][5];
		/* SMGW代码 */
	char    asSmg[SMG_TICKET_BUFLEN_OUT][7];
		/* 前转SMGW代码 */
	char    asTsmg[SMG_TICKET_BUFLEN_OUT][7];
		/* 短消息中心代码 */
	char    asSmc[SMG_TICKET_BUFLEN_OUT][7];
		/* 提交时间 */
	char    asRecvDateTime[SMG_TICKET_BUFLEN_OUT][15];
		/* 处理结束时间 */
	char    asDoneDateTime[SMG_TICKET_BUFLEN_OUT][15];
		/* SMGW分配短消息标识 */
	char    asMsgID[SMG_TICKET_BUFLEN_OUT][21];
		/* 异网之间的短消息标识 */
	char    asOppMsgID[SMG_TICKET_BUFLEN_OUT][21];
		/* 主叫用户号码 */
	char    asCallingNbr[SMG_TICKET_BUFLEN_OUT][22];
		/* 话单类型 */
	int     aiTicketTypeID[SMG_TICKET_BUFLEN_OUT];
		/* 状态 */
	char    asState[SMG_TICKET_BUFLEN_OUT][2];
		/* 处理时间 */
	char    asDealDate[SMG_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[SMG_TICKET_BUFLEN_OUT][31];
};
/* 输入结构缓冲申明*/
struct SmgTicketStructIn{

#ifndef SMG_TICKET_BUFLEN_IN
#define SMG_TICKET_BUFLEN_IN		300
#endif

	struct SmgTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 短消息标识 */
	char    asMessageID[SMG_TICKET_BUFLEN_IN][21];
		/* 短消息类型 */
	char    asSmsType[SMG_TICKET_BUFLEN_IN][2];
		/* 短消息子类型 */
	char    asSubType[SMG_TICKET_BUFLEN_IN][2];
		/* 计费用户号码 */
	char    asMsisdn[SMG_TICKET_BUFLEN_IN][22];
		/* SP号码 */
	char    asSpCode[SMG_TICKET_BUFLEN_IN][11];
		/* 目的地号码 */
	char    asOtherParty[SMG_TICKET_BUFLEN_IN][22];
		/* 业务代码 */
	char    asSpServiceCode[SMG_TICKET_BUFLEN_IN][11];
		/* 用户计费类别 */
	char    asBillType[SMG_TICKET_BUFLEN_IN][3];
		/* 信息费 */
	char    asInfoFee[SMG_TICKET_BUFLEN_IN][7];
		/* 短消息发送优先级 */
	char    asPriority[SMG_TICKET_BUFLEN_IN][2];
		/* 信息长度 */
	char    asMsgLen[SMG_TICKET_BUFLEN_IN][4];
		/* 计费号码归属地的区号 */
	char    asHomeAreaCode[SMG_TICKET_BUFLEN_IN][5];
		/* SMGW代码 */
	char    asSmg[SMG_TICKET_BUFLEN_IN][7];
		/* 前转SMGW代码 */
	char    asTsmg[SMG_TICKET_BUFLEN_IN][7];
		/* 短消息中心代码 */
	char    asSmc[SMG_TICKET_BUFLEN_IN][7];
		/* 提交时间 */
	char    asRecvDateTime[SMG_TICKET_BUFLEN_IN][15];
		/* 处理结束时间 */
	char    asDoneDateTime[SMG_TICKET_BUFLEN_IN][15];
		/* SMGW分配短消息标识 */
	char    asMsgID[SMG_TICKET_BUFLEN_IN][21];
		/* 异网之间的短消息标识 */
	char    asOppMsgID[SMG_TICKET_BUFLEN_IN][21];
		/* 主叫用户号码 */
	char    asCallingNbr[SMG_TICKET_BUFLEN_IN][22];
		/* 话单类型 */
	int     aiTicketTypeID[SMG_TICKET_BUFLEN_IN];
		/* 状态 */
	char    asState[SMG_TICKET_BUFLEN_IN][2];
		/* 处理时间 */
	char    asDealDate[SMG_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[SMG_TICKET_BUFLEN_IN][31];
	char	asRowID[SMG_TICKET_BUFLEN_IN][19];
};

/*单个结构申明*/
struct SmgTicketStruct{

	struct SmgTicketStruct *pNext;
	char    sMessageID[21];		/* 短消息标识 */
	char    sSmsType[2];		/* 短消息类型 */
	char    sSubType[2];		/* 短消息子类型 */
	char    sMsisdn[22];		/* 计费用户号码 */
	char    sSpCode[11];		/* SP号码 */
	char    sOtherParty[22];		/* 目的地号码 */
	char    sSpServiceCode[11];		/* 业务代码 */
	char    sBillType[3];		/* 用户计费类别 */
	char    sInfoFee[7];		/* 信息费 */
	char    sPriority[2];		/* 短消息发送优先级 */
	char    sMsgLen[4];		/* 信息长度 */
	char    sHomeAreaCode[5];		/* 计费号码归属地的区号 */
	char    sSmg[7];		/* SMGW代码 */
	char    sTsmg[7];		/* 前转SMGW代码 */
	char    sSmc[7];		/* 短消息中心代码 */
	char    sRecvDateTime[15];		/* 提交时间 */
	char    sDoneDateTime[15];		/* 处理结束时间 */
	char    sMsgID[21];		/* SMGW分配短消息标识 */
	char    sOppMsgID[21];		/* 异网之间的短消息标识 */
	char    sCallingNbr[22];		/* 主叫用户号码 */
	int     iTicketTypeID;		/* 话单类型 */
	char    sState[2];		/* 状态 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[31];		/* 文件来源 */
	char	sRowID[19];
	struct SmgTicketStruct *pLoadNext;
};

/*批量数据结构缓冲写入SMG_TICKET*/
int EInsertStructToSmgTicket(struct SmgTicketStruct *p,
	int iInsertFlag,struct SmgTicketStructOut *pTarget);
void mvitem_fmsmgticket(struct FSmgTicketStruct *pi,int len,
	struct SmgTicketStruct *po);
void mvitem_mfsmgticket(struct SmgTicketStruct *pi,
	struct FSmgTicketStruct *po);
int InsertSmgTicket(char sFileName[],char sTableName[]);
/*批量数据动态从SMG_TICKET中用结构缓冲方式取数据*/
int EGetSmgTicketToStruct(struct SmgTicketStruct *p,
	struct SmgTicketStructIn *pSource);
int SmgTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*输出结构缓冲申明*/
struct ZnwTicketStructOut{

#ifndef ZNW_TICKET_BUFLEN_OUT
#define ZNW_TICKET_BUFLEN_OUT		300
#endif

	struct ZnwTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型 */
	int     aiTicketTypeID[ZNW_TICKET_BUFLEN_OUT];
		/* 记录类型(0x国家骨干智能网1x省智能网华为2x省智能网华为贝尔) */
	char    asRecordType[ZNW_TICKET_BUFLEN_OUT][3];
		/* 流水号 */
	char    asStreamNumber[ZNW_TICKET_BUFLEN_OUT][11];
		/* 业务键 */
	char    asServiceKey[ZNW_TICKET_BUFLEN_OUT][11];
		/* 计费模式 */
	char    asBillingMode[ZNW_TICKET_BUFLEN_OUT][2];
		/* 计费记录标识 */
	char    asChargeRecordID[ZNW_TICKET_BUFLEN_OUT][9];
		/* 主叫用户号码 */
	char    asCallingNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* 被叫用户号码 */
	char    asCalledNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* 目标地址号码号码 */
	char    asTranslatedNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* 位置号码 */
	char    asLocationNbr[ZNW_TICKET_BUFLEN_OUT][11];
		/* 计费用户标志 */
	char    asBillingFlag[ZNW_TICKET_BUFLEN_OUT][5];
		/* 规定的计费号码 */
	char    asBillingNbr[ZNW_TICKET_BUFLEN_OUT][25];
		/* 开始通话时间 */
	char    asStartTime[ZNW_TICKET_BUFLEN_OUT][15];
		/* 通话结束时间 */
	char    asStopTime[ZNW_TICKET_BUFLEN_OUT][15];
		/* 通话时长 */
	int     aiDuration[ZNW_TICKET_BUFLEN_OUT];
		/* 通话话费 */
	int     aiTotalFee[ZNW_TICKET_BUFLEN_OUT];
		/* 承载能力 */
	char    asBearCapability[ZNW_TICKET_BUFLEN_OUT][3];
		/* 费率种类 */
	char    asTariffClass[ZNW_TICKET_BUFLEN_OUT][3];
		/* 计费号码属性 */
	char    asBillType[ZNW_TICKET_BUFLEN_OUT][5];
		/* 用户ID或批次信息 */
	char    asUserID[ZNW_TICKET_BUFLEN_OUT][11];
		/* 业务号码 */
	char    asServiceNbr[ZNW_TICKET_BUFLEN_OUT][29];
		/* 计次数 */
	int     aiCount[ZNW_TICKET_BUFLEN_OUT];
		/* 基本费 */
	int     aiBaseFee[ZNW_TICKET_BUFLEN_OUT];
		/* 奖励金额 */
	int     aiBountyFee[ZNW_TICKET_BUFLEN_OUT];
		/* 附加费 */
	int     aiAddFee[ZNW_TICKET_BUFLEN_OUT];
		/* 透明参数 */
	char    asTransParam[ZNW_TICKET_BUFLEN_OUT][31];
		/* 计费部分 */
	char    asCallparttobecharger[ZNW_TICKET_BUFLEN_OUT][33];
		/* scp序号 */
	char    asScpID[ZNW_TICKET_BUFLEN_OUT][11];
		/* 通话结束原因 */
	char    asCauseOfCallend[ZNW_TICKET_BUFLEN_OUT][5];
		/* 业务折扣率 */
	char    asServiceModulator[ZNW_TICKET_BUFLEN_OUT][5];
		/* 业务类型 */
	char    asServiceType[ZNW_TICKET_BUFLEN_OUT][3];
		/* 卡号 */
	char    asCardID[ZNW_TICKET_BUFLEN_OUT][31];
		/* 主叫归属地 */
	char    asHomeAreaCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* 被叫归属地 */
	char    asCalledCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* 计费区号 */
	char    asBillingAreaCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* 发卡地区代码 */
	char    asCardAreaCode[ZNW_TICKET_BUFLEN_OUT][6];
		/* 呼叫类型 */
	char    asDistanceType[ZNW_TICKET_BUFLEN_OUT][2];
		/* 原始话单文件名 */
	char    asOriFileName[ZNW_TICKET_BUFLEN_OUT][41];
		/* 状态 */
	char    asState[ZNW_TICKET_BUFLEN_OUT][2];
		/* 处理时间 */
	char    asDealDate[ZNW_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[ZNW_TICKET_BUFLEN_OUT][41];
};
/* 输入结构缓冲申明*/
struct ZnwTicketStructIn{

#ifndef ZNW_TICKET_BUFLEN_IN
#define ZNW_TICKET_BUFLEN_IN		300
#endif

	struct ZnwTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型 */
	int     aiTicketTypeID[ZNW_TICKET_BUFLEN_IN];
		/* 记录类型(0x国家骨干智能网1x省智能网华为2x省智能网华为贝尔) */
	char    asRecordType[ZNW_TICKET_BUFLEN_IN][3];
		/* 流水号 */
	char    asStreamNumber[ZNW_TICKET_BUFLEN_IN][11];
		/* 业务键 */
	char    asServiceKey[ZNW_TICKET_BUFLEN_IN][11];
		/* 计费模式 */
	char    asBillingMode[ZNW_TICKET_BUFLEN_IN][2];
		/* 计费记录标识 */
	char    asChargeRecordID[ZNW_TICKET_BUFLEN_IN][9];
		/* 主叫用户号码 */
	char    asCallingNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* 被叫用户号码 */
	char    asCalledNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* 目标地址号码号码 */
	char    asTranslatedNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* 位置号码 */
	char    asLocationNbr[ZNW_TICKET_BUFLEN_IN][11];
		/* 计费用户标志 */
	char    asBillingFlag[ZNW_TICKET_BUFLEN_IN][5];
		/* 规定的计费号码 */
	char    asBillingNbr[ZNW_TICKET_BUFLEN_IN][25];
		/* 开始通话时间 */
	char    asStartTime[ZNW_TICKET_BUFLEN_IN][15];
		/* 通话结束时间 */
	char    asStopTime[ZNW_TICKET_BUFLEN_IN][15];
		/* 通话时长 */
	int     aiDuration[ZNW_TICKET_BUFLEN_IN];
		/* 通话话费 */
	int     aiTotalFee[ZNW_TICKET_BUFLEN_IN];
		/* 承载能力 */
	char    asBearCapability[ZNW_TICKET_BUFLEN_IN][3];
		/* 费率种类 */
	char    asTariffClass[ZNW_TICKET_BUFLEN_IN][3];
		/* 计费号码属性 */
	char    asBillType[ZNW_TICKET_BUFLEN_IN][5];
		/* 用户ID或批次信息 */
	char    asUserID[ZNW_TICKET_BUFLEN_IN][11];
		/* 业务号码 */
	char    asServiceNbr[ZNW_TICKET_BUFLEN_IN][29];
		/* 计次数 */
	int     aiCount[ZNW_TICKET_BUFLEN_IN];
		/* 基本费 */
	int     aiBaseFee[ZNW_TICKET_BUFLEN_IN];
		/* 奖励金额 */
	int     aiBountyFee[ZNW_TICKET_BUFLEN_IN];
		/* 附加费 */
	int     aiAddFee[ZNW_TICKET_BUFLEN_IN];
		/* 透明参数 */
	char    asTransParam[ZNW_TICKET_BUFLEN_IN][31];
		/* 计费部分 */
	char    asCallparttobecharger[ZNW_TICKET_BUFLEN_IN][33];
		/* scp序号 */
	char    asScpID[ZNW_TICKET_BUFLEN_IN][11];
		/* 通话结束原因 */
	char    asCauseOfCallend[ZNW_TICKET_BUFLEN_IN][5];
		/* 业务折扣率 */
	char    asServiceModulator[ZNW_TICKET_BUFLEN_IN][5];
		/* 业务类型 */
	char    asServiceType[ZNW_TICKET_BUFLEN_IN][3];
		/* 卡号 */
	char    asCardID[ZNW_TICKET_BUFLEN_IN][31];
		/* 主叫归属地 */
	char    asHomeAreaCode[ZNW_TICKET_BUFLEN_IN][6];
		/* 被叫归属地 */
	char    asCalledCode[ZNW_TICKET_BUFLEN_IN][6];
		/* 计费区号 */
	char    asBillingAreaCode[ZNW_TICKET_BUFLEN_IN][6];
		/* 发卡地区代码 */
	char    asCardAreaCode[ZNW_TICKET_BUFLEN_IN][6];
		/* 呼叫类型 */
	char    asDistanceType[ZNW_TICKET_BUFLEN_IN][2];
		/* 原始话单文件名 */
	char    asOriFileName[ZNW_TICKET_BUFLEN_IN][41];
		/* 状态 */
	char    asState[ZNW_TICKET_BUFLEN_IN][2];
		/* 处理时间 */
	char    asDealDate[ZNW_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[ZNW_TICKET_BUFLEN_IN][41];
	char	asRowID[ZNW_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct ZnwTicketStruct{

	struct ZnwTicketStruct *pNext;
	int     iTicketTypeID;		/* 话单类型 */
	char    sRecordType[3];		
	/* 记录类型(0x国家骨干智能网1x省智能网华为2x省智能网华为贝尔) */
	char    sStreamNumber[11];		/* 流水号 */
	char    sServiceKey[11];		/* 业务键 */
	char    sBillingMode[2];		/* 计费模式 */
	char    sChargeRecordID[9];		/* 计费记录标识 */
	char    sCallingNbr[25];		/* 主叫用户号码 */
	char    sCalledNbr[25];		/* 被叫用户号码 */
	char    sTranslatedNbr[25];		/* 目标地址号码号码 */
	char    sLocationNbr[11];		/* 位置号码 */
	char    sBillingFlag[5];		/* 计费用户标志 */
	char    sBillingNbr[25];		/* 规定的计费号码 */
	char    sStartTime[15];		/* 开始通话时间 */
	char    sStopTime[15];		/* 通话结束时间 */
	int     iDuration;		/* 通话时长 */
	int     iTotalFee;		/* 通话话费 */
	char    sBearCapability[3];		/* 承载能力 */
	char    sTariffClass[3];		/* 费率种类 */
	char    sBillType[5];		/* 计费号码属性 */
	char    sUserID[11];		/* 用户ID或批次信息 */
	char    sServiceNbr[29];		/* 业务号码 */
	int     iCount;		/* 计次数 */
	int     iBaseFee;		/* 基本费 */
	int     iBountyFee;		/* 奖励金额 */
	int     iAddFee;		/* 附加费 */
	char    sTransParam[31];		/* 透明参数 */
	char    sCallparttobecharger[33];		/* 计费部分 */
	char    sScpID[11];		/* scp序号 */
	char    sCauseOfCallend[5];		/* 通话结束原因 */
	char    sServiceModulator[5];		/* 业务折扣率 */
	char    sServiceType[3];		/* 业务类型 */
	char    sCardID[31];		/* 卡号 */
	char    sHomeAreaCode[6];		/* 主叫归属地 */
	char    sCalledCode[6];		/* 被叫归属地 */
	char    sBillingAreaCode[6];		/* 计费区号 */
	char    sCardAreaCode[6];		/* 发卡地区代码 */
	char    sDistanceType[2];		/* 呼叫类型 */
	char    sOriFileName[41];		/* 原始话单文件名 */
	char    sState[2];		/* 状态 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct ZnwTicketStruct *pLoadNext;
};

int EInsertStructToZnwTicket(struct ZnwTicketStruct *p,
	int iInsertFlag,struct ZnwTicketStructOut *pTarget);
void mvitem_fmznwticket(struct FZnwTicketStruct *pi,struct ZnwTicketStruct *po);
void mvitem_mfznwticket(struct ZnwTicketStruct *pi,struct FZnwTicketStruct *po);
int InsertZnwTicket(char sFileName[],char sTableName[]);
int ZnwTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
/*批量数据动态从ZNW_TICKET中用结构缓冲方式取数据*/
int EGetZnwTicketToStruct(struct ZnwTicketStruct *p,
	struct ZnwTicketStructIn *pSource);

/*输出结构缓冲申明*/
struct IccTicketStructOut{

#ifndef ICC_TICKET_BUFLEN_OUT
#define ICC_TICKET_BUFLEN_OUT		300
#endif

	struct IccTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型 */
	int     aiTicketTypeID[ICC_TICKET_BUFLEN_OUT];
		/* 记录类型'20'出省漫游话单'21'省内话单(付费电话话单数据) */
	char    asRecordType[ICC_TICKET_BUFLEN_OUT][3];
		/* 话务省代码 */
	char    asProvinceCode[ICC_TICKET_BUFLEN_OUT][6];
		/* 话务地区代码 */
	char    asCallAreaCode[ICC_TICKET_BUFLEN_OUT][6];
		/* 卡号 */
	char    asCardID[ICC_TICKET_BUFLEN_OUT][31];
		/* 发卡省代码 */
	char    asCardProvinceCode[ICC_TICKET_BUFLEN_OUT][6];
		/* 发卡地区代码 */
	char    asCardAreaCode[ICC_TICKET_BUFLEN_OUT][6];
		/* 发卡县代码 */
	char    asCardAreaID[ICC_TICKET_BUFLEN_OUT][6];
		/* 主叫号码 */
	char    asCallingNbr[ICC_TICKET_BUFLEN_OUT][25];
		/* 被叫号码 */
	char    asCalledNbr[ICC_TICKET_BUFLEN_OUT][25];
		/* 归属帐期 */
	char    asBillingCycleID[ICC_TICKET_BUFLEN_OUT][7];
		/* 呼叫时间 */
	char    asStartTime[ICC_TICKET_BUFLEN_OUT][15];
		/* 呼叫时长 */
	int     aiDuration[ICC_TICKET_BUFLEN_OUT];
		/* 呼叫费用 */
	int     aiTotalFee[ICC_TICKET_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceType[ICC_TICKET_BUFLEN_OUT][3];
		/* 通话类型 */
	char    asDistanceType[ICC_TICKET_BUFLEN_OUT][2];
		/* 状态 */
	char    asState[ICC_TICKET_BUFLEN_OUT][2];
		/* 处理时间 */
	char    asDealDate[ICC_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[ICC_TICKET_BUFLEN_OUT][41];
};
/* 输入结构缓冲申明*/
struct IccTicketStructIn{

#ifndef ICC_TICKET_BUFLEN_IN
#define ICC_TICKET_BUFLEN_IN		300
#endif

	struct IccTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型 */
	int     aiTicketTypeID[ICC_TICKET_BUFLEN_IN];
		/* 记录类型'20'出省漫游话单'21'省内话单(付费电话话单数据) */
	char    asRecordType[ICC_TICKET_BUFLEN_IN][3];
		/* 话务省代码 */
	char    asProvinceCode[ICC_TICKET_BUFLEN_IN][6];
		/* 话务地区代码 */
	char    asCallAreaCode[ICC_TICKET_BUFLEN_IN][6];
		/* 卡号 */
	char    asCardID[ICC_TICKET_BUFLEN_IN][31];
		/* 发卡省代码 */
	char    asCardProvinceCode[ICC_TICKET_BUFLEN_IN][6];
		/* 发卡地区代码 */
	char    asCardAreaCode[ICC_TICKET_BUFLEN_IN][6];
		/* 发卡县代码 */
	char    asCardAreaID[ICC_TICKET_BUFLEN_IN][6];
		/* 主叫号码 */
	char    asCallingNbr[ICC_TICKET_BUFLEN_IN][25];
		/* 被叫号码 */
	char    asCalledNbr[ICC_TICKET_BUFLEN_IN][25];
		/* 归属帐期 */
	char    asBillingCycleID[ICC_TICKET_BUFLEN_IN][7];
		/* 呼叫时间 */
	char    asStartTime[ICC_TICKET_BUFLEN_IN][15];
		/* 呼叫时长 */
	int     aiDuration[ICC_TICKET_BUFLEN_IN];
		/* 呼叫费用 */
	int     aiTotalFee[ICC_TICKET_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceType[ICC_TICKET_BUFLEN_IN][3];
		/* 通话类型 */
	char    asDistanceType[ICC_TICKET_BUFLEN_IN][2];
		/* 状态 */
	char    asState[ICC_TICKET_BUFLEN_IN][2];
		/* 处理时间 */
	char    asDealDate[ICC_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[ICC_TICKET_BUFLEN_IN][41];
	char	asRowID[ICC_TICKET_BUFLEN_IN][19];
};



/*单个结构申明*/
struct IccTicketStruct{

	struct IccTicketStruct *pNext;
	int     iTicketTypeID;		/* 话单类型 */
	char    sRecordType[3];		
	/* 记录类型'20'出省漫游话单'21'省内话单(付费电话话单数据) */
	char    sProvinceCode[6];		/* 话务省代码 */
	char    sCallAreaCode[6];		/* 话务地区代码 */
	char    sCardID[31];		/* 卡号 */
	char    sCardProvinceCode[6];		/* 发卡省代码 */
	char    sCardAreaCode[6];		/* 发卡地区代码 */
	char    sCardAreaID[6];		/* 发卡县代码 */
	char    sCallingNbr[25];		/* 主叫号码 */
	char    sCalledNbr[25];		/* 被叫号码 */
	char    sBillingCycleID[7];		/* 归属帐期 */
	char    sStartTime[15];		/* 呼叫时间 */
	int     iDuration;		/* 呼叫时长 */
	int     iTotalFee;		/* 呼叫费用 */
	char    sServiceType[3];		/* 业务类型 */
	char    sDistanceType[2];		/* 通话类型 */
	char    sState[2];		/* 状态 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct IccTicketStruct *pLoadNext;
};
/*批量数据结构缓冲写入ICC_TICKET*/
int EInsertStructToIccTicket(struct IccTicketStruct *p,
	int iInsertFlag,struct IccTicketStructOut *pTarget);
void mvitem_fmiccticket(struct FIccTicketStruct *pi,struct IccTicketStruct *po);
void mvitem_mficcticket(struct IccTicketStruct *pi,struct FIccTicketStruct *po);
int InsertIccTicket(char sFileName[],char sTableName[]);
/*批量数据动态从ICC_TICKET中用结构缓冲方式取数据*/
int EGetIccTicketToStruct(struct IccTicketStruct *p,
	struct IccTicketStructIn *pSource);
int IccTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);


/*输出结构缓冲申明*/
struct InfoAcctStructOut{

#ifndef INFO_ACCT_BUFLEN_OUT
#define INFO_ACCT_BUFLEN_OUT		300
#endif

	struct InfoAcctStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型 */
	int     aiTicketTypeID[INFO_ACCT_BUFLEN_OUT];
		/* 省代码 */
	char    asProvinceID[INFO_ACCT_BUFLEN_OUT][6];
		/* 本地网代码 */
	char    asAreaCode[INFO_ACCT_BUFLEN_OUT][6];
		/* 记录总数 */
	int     aiTotalCnt[INFO_ACCT_BUFLEN_OUT];
		/* 金额总数分 */
	int     aiTotalFee[INFO_ACCT_BUFLEN_OUT];
		/* 合帐记录总数 */
	int     aiValidCnt[INFO_ACCT_BUFLEN_OUT];
		/* 合帐金额总数分 */
	int     aiValidFee[INFO_ACCT_BUFLEN_OUT];
		/* 不能合帐记录总数 */
	int     aiInvalidCnt[INFO_ACCT_BUFLEN_OUT];
		/* 不能合帐金额总数分 */
	char    asInvalidFee[INFO_ACCT_BUFLEN_OUT][10];
		/* 出帐月份 */
	char    asBillingCycleID[INFO_ACCT_BUFLEN_OUT][7];
		/* SP代码 */
	char    asSpCode[INFO_ACCT_BUFLEN_OUT][21];
		/* 本期回收金额中本帐期费用 */
	int     aiFee[INFO_ACCT_BUFLEN_OUT];
		/* 本期回收金额中历史欠费 */
	int     aiOweFee[INFO_ACCT_BUFLEN_OUT];
		/* 状态 */
	char    asState[INFO_ACCT_BUFLEN_OUT][2];
		/* 处理时间 */
	char    asDealDate[INFO_ACCT_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[INFO_ACCT_BUFLEN_OUT][41];
};
/* 输入结构缓冲申明*/
struct InfoAcctStructIn{

#ifndef INFO_ACCT_BUFLEN_IN
#define INFO_ACCT_BUFLEN_IN		300
#endif

	struct InfoAcctStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型 */
	int     aiTicketTypeID[INFO_ACCT_BUFLEN_IN];
		/* 省代码 */
	char    asProvinceID[INFO_ACCT_BUFLEN_IN][6];
		/* 本地网代码 */
	char    asAreaCode[INFO_ACCT_BUFLEN_IN][6];
		/* 记录总数 */
	int     aiTotalCnt[INFO_ACCT_BUFLEN_IN];
		/* 金额总数分 */
	int     aiTotalFee[INFO_ACCT_BUFLEN_IN];
		/* 合帐记录总数 */
	int     aiValidCnt[INFO_ACCT_BUFLEN_IN];
		/* 合帐金额总数分 */
	int     aiValidFee[INFO_ACCT_BUFLEN_IN];
		/* 不能合帐记录总数 */
	int     aiInvalidCnt[INFO_ACCT_BUFLEN_IN];
		/* 不能合帐金额总数分 */
	char    asInvalidFee[INFO_ACCT_BUFLEN_IN][10];
		/* 出帐月份 */
	char    asBillingCycleID[INFO_ACCT_BUFLEN_IN][7];
		/* SP代码 */
	char    asSpCode[INFO_ACCT_BUFLEN_IN][21];
		/* 本期回收金额中本帐期费用 */
	int     aiFee[INFO_ACCT_BUFLEN_IN];
		/* 本期回收金额中历史欠费 */
	int     aiOweFee[INFO_ACCT_BUFLEN_IN];
		/* 状态 */
	char    asState[INFO_ACCT_BUFLEN_IN][2];
		/* 处理时间 */
	char    asDealDate[INFO_ACCT_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[INFO_ACCT_BUFLEN_IN][41];
	char	asRowID[INFO_ACCT_BUFLEN_IN][19];
};



/*单个结构申明*/
struct InfoAcctStruct{

	struct InfoAcctStruct *pNext;
	int     iTicketTypeID;		/* 话单类型 */
	char    sProvinceID[6];		/* 省代码 */
	char    sAreaCode[6];		/* 本地网代码 */
	int     iTotalCnt;		/* 记录总数 */
	int     iTotalFee;		/* 金额总数分 */
	int     iValidCnt;		/* 合帐记录总数 */
	int     iValidFee;		/* 合帐金额总数分 */
	int     iInvalidCnt;		/* 不能合帐记录总数 */
	char    sInvalidFee[10];		/* 不能合帐金额总数分 */
	char    sBillingCycleID[7];		/* 出帐月份 */
	char    sSpCode[21];		/* SP代码 */
	int     iFee;		/* 本期回收金额中本帐期费用 */
	int     iOweFee;		/* 本期回收金额中历史欠费 */
	char    sState[2];		/* 状态 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 文件来源 */
	char	sRowID[19];
	struct InfoAcctStruct *pLoadNext;
};

void mvitem_fminfoacct(struct FInfoAcctStruct *pi,
	struct InfoAcctStruct *po);
void mvitem_mfinfoacct(struct InfoAcctStruct *pi,
	struct FInfoAcctStruct *po);
/*批量数据结构缓冲写入INFO_ACCT*/
int EInsertStructToInfoAcct(struct InfoAcctStruct *p,
	int iInsertFlag,struct InfoAcctStructOut *pTarget);
int InsertInfoAcct(char sFileName[],char sTableName[]);
/*批量数据动态从INFO_ACCT中用结构缓冲方式取数据*/
int EGetInfoAcctToStruct(struct InfoAcctStruct *p,
	struct InfoAcctStructIn *pSource);
int InfoAcct2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);


/*输出结构缓冲申明*/
struct InfoNbrAcctStructOut{

#ifndef INFO_NBR_ACCT_BUFLEN_OUT
#define INFO_NBR_ACCT_BUFLEN_OUT		300
#endif

	struct InfoNbrAcctStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型 */
	int     aiTicketTypeID[INFO_NBR_ACCT_BUFLEN_OUT];
		/* '00'无法合帐文件(各市到省)'01'详单文件(省到各市)'02'帐单文件(省中心到各市) */
	char    asRecordType[INFO_NBR_ACCT_BUFLEN_OUT][3];
		/* 主叫号码 */
	char    asCallingNbr[INFO_NBR_ACCT_BUFLEN_OUT][21];
		/* 业务接入号码 */
	char    asSpAccNbr[INFO_NBR_ACCT_BUFLEN_OUT][21];
		/* 使用的业务栏目编码 */
	char    asSpServiceCode[INFO_NBR_ACCT_BUFLEN_OUT][21];
		/* 次数 */
	int     aiCnt[INFO_NBR_ACCT_BUFLEN_OUT];
		/* 时长秒 */
	int     aiDuration[INFO_NBR_ACCT_BUFLEN_OUT];
		/* 金额分 */
	int     aiFee[INFO_NBR_ACCT_BUFLEN_OUT];
		/* 起始时间 */
	char    asStartTime[INFO_NBR_ACCT_BUFLEN_OUT][15];
		/* 号码类型 */
	int     aiCallingTypeID[INFO_NBR_ACCT_BUFLEN_OUT];
		/* 网络类型 */
	char    asNetType[INFO_NBR_ACCT_BUFLEN_OUT][2];
		/* 备注 */
	char    asNotes[INFO_NBR_ACCT_BUFLEN_OUT][61];
		/* 状态 */
	char    asState[INFO_NBR_ACCT_BUFLEN_OUT][2];
		/* 处理时间 */
	char    asDealDate[INFO_NBR_ACCT_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[INFO_NBR_ACCT_BUFLEN_OUT][41];
};

/*单个结构申明*/
struct InfoNbrAcctStruct{

	struct InfoNbrAcctStruct *pNext;
	int     iTicketTypeID;		/* 话单类型 */
	char    sRecordType[3];		
/* '00'无法合帐文件(各市到省)'01'详单文件(省到各市)'02'帐单文件(省中心到各市) */
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sSpAccNbr[21];		/* 业务接入号码 */
	char    sSpServiceCode[21];		/* 使用的业务栏目编码 */
	int     iCnt;		/* 次数 */
	int     iDuration;		/* 时长秒 */
	int     iFee;		/* 金额分 */
	char    sStartTime[15];		/* 起始时间 */
	int     iCallingTypeID;		/* 号码类型 */
	char    sNetType[2];		/* 网络类型 */
	char    sNotes[61];		/* 备注 */
	char    sState[2];		/* 状态 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 文件来源 */
	struct InfoNbrAcctStruct *pLoadNext;
};
void mvitem_fminfonbracct(struct FInfoNbrAcctStruct *pi,
	struct InfoNbrAcctStruct *po);
/*批量数据结构缓冲写入INFO_NBR_ACCT*/
int EInsertStructToInfoNbrAcct(struct InfoNbrAcctStruct *p,
	int iInsertFlag,struct InfoNbrAcctStructOut *pTarget);
int InsertInfoNbrAcct(char sFileName[],char sTableName[]);	


/*输出结构缓冲申明*/
struct NxRhjfTicketStructOut{

#ifndef NX_RHJF_TICKET_BUFLEN_OUT
#define NX_RHJF_TICKET_BUFLEN_OUT		300
#endif

	struct NxRhjfTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单记录标识 */
	char    asRecordType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* 主叫字冠 */
	char    asCallingRef[NX_RHJF_TICKET_BUFLEN_OUT][6];
		/* 主叫区号 */
	char    asCallingAreaCode[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* 主叫号码 */
	char    asCallingNbr[NX_RHJF_TICKET_BUFLEN_OUT][21];
		/* 被叫字冠 */
	char    asCalledRef[NX_RHJF_TICKET_BUFLEN_OUT][6];
		/* 被叫区号 */
	char    asCalledCode[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* 被叫号码 */
	char    asCalledNbr[NX_RHJF_TICKET_BUFLEN_OUT][21];
		/* 用户类型 */
	char    asUserType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* 主叫运营商类型 */
	char    asCallingCarrType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* 被叫运营商类型 */
	char    asCalledCarrType[NX_RHJF_TICKET_BUFLEN_OUT][3];
		/* 被叫区域代码 */
	char    asCalledAreaID[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* 业务类型 */
	char    asServiceType[NX_RHJF_TICKET_BUFLEN_OUT][2];
		/* 路由类型 */
	char    asRouteType[NX_RHJF_TICKET_BUFLEN_OUT][2];
		/* 卡号 */
	char    asCardNbr[NX_RHJF_TICKET_BUFLEN_OUT][31];
		/* 入中继 */
	char    asTrunkIn[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* 出中继 */
	char    asTrunkOut[NX_RHJF_TICKET_BUFLEN_OUT][11];
		/* 通话起始时间 */
	char    asStartTime[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* 通话终止时间 */
	char    asEndTime[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* 通话时长 */
	char    asDuration[NX_RHJF_TICKET_BUFLEN_OUT][9];
		/* 计费时长 */
	char    asChargeDuration[NX_RHJF_TICKET_BUFLEN_OUT][9];
		/* 基本费 */
	char    asBaseFee[NX_RHJF_TICKET_BUFLEN_OUT][13];
		/* 优惠费 */
	char    asDisctFee[NX_RHJF_TICKET_BUFLEN_OUT][13];
		/* 总费用 */
	char    asTotalFee[NX_RHJF_TICKET_BUFLEN_OUT][13];
		/* 更新时间 */
	char    asUpdateDate[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* 处理时间 */
	char    asDealDate[NX_RHJF_TICKET_BUFLEN_OUT][15];
		/* 数据来源 */
	char    asSourceID[NX_RHJF_TICKET_BUFLEN_OUT][41];
};

/*单个结构申明*/
struct NxRhjfTicketStruct{

	struct NxRhjfTicketStruct *pNext;
	char    sRecordType[3];		/* 话单记录标识 */
	char    sCallingRef[6];		/* 主叫字冠 */
	char    sCallingAreaCode[11];		/* 主叫区号 */
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCalledRef[6];		/* 被叫字冠 */
	char    sCalledCode[11];		/* 被叫区号 */
	char    sCalledNbr[21];		/* 被叫号码 */
	char    sUserType[3];		/* 用户类型 */
	char    sCallingCarrType[3];		/* 主叫运营商类型 */
	char    sCalledCarrType[3];		/* 被叫运营商类型 */
	char    sCalledAreaID[11];		/* 被叫区域代码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sRouteType[2];		/* 路由类型 */
	char    sCardNbr[31];		/* 卡号 */
	char    sTrunkIn[11];		/* 入中继 */
	char    sTrunkOut[11];		/* 出中继 */
	char    sStartTime[15];		/* 通话起始时间 */
	char    sEndTime[15];		/* 通话终止时间 */
	char    sDuration[9];		/* 通话时长 */
	char    sChargeDuration[9];		/* 计费时长 */
	char    sBaseFee[13];		/* 基本费 */
	char    sDisctFee[13];		/* 优惠费 */
	char    sTotalFee[13];		/* 总费用 */
	char    sUpdateDate[15];		/* 更新时间 */
	char    sDealDate[15];		/* 处理时间 */
	char    sSourceID[41];		/* 数据来源 */
	struct NxRhjfTicketStruct *pLoadNext;
};
void mvitem_fmnxrhjfticket(struct FNxRhjfTicketStruct *pi,struct NxRhjfTicketStruct *po);
/*批量数据结构缓冲写入NX_RHJF_TICKET*/
int EInsertStructToNxRhjfTicket(struct NxRhjfTicketStruct *p,
	int iInsertFlag,struct NxRhjfTicketStructOut *pTarget);
int InsertNxRhjfTicket(char sFileName[],char sTableName[]);


/*输出结构缓冲申明*/
struct ServCardStructOut{

#ifndef SERV_CARD_BUFLEN_OUT
#define SERV_CARD_BUFLEN_OUT		300
#endif

	struct ServCardStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 号码 */
	char    asAccNbr[SERV_CARD_BUFLEN_OUT][16];
		/* 区号 */
	char    asAreaCode[SERV_CARD_BUFLEN_OUT][6];
		/* 分公司名称 */
	char    asAreaCodeName[SERV_CARD_BUFLEN_OUT][21];
		/* 营业区名称 */
	char    asAreaName[SERV_CARD_BUFLEN_OUT][21];
		/* 客户名称 */
	char    asCustNane[SERV_CARD_BUFLEN_OUT][31];
		/* 号码类型'201'为201卡号码'202'为ic卡号码 */
	int     aiTypeID[SERV_CARD_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct ServCardStructIn{

#ifndef SERV_CARD_BUFLEN_IN
#define SERV_CARD_BUFLEN_IN		300
#endif

	struct ServCardStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 号码 */
	char    asAccNbr[SERV_CARD_BUFLEN_IN][16];
		/* 区号 */
	char    asAreaCode[SERV_CARD_BUFLEN_IN][6];
		/* 分公司名称 */
	char    asAreaCodeName[SERV_CARD_BUFLEN_IN][21];
		/* 营业区名称 */
	char    asAreaName[SERV_CARD_BUFLEN_IN][21];
		/* 客户名称 */
	char    asCustNane[SERV_CARD_BUFLEN_IN][31];
		/* 号码类型'201'为201卡号码'202'为ic卡号码 */
	int     aiTypeID[SERV_CARD_BUFLEN_IN];
};


/*单个结构申明*/
struct ServCardStruct{

	struct ServCardStruct *pNext;
	char    sAccNbr[16];		/* 号码 */
	char    sAreaCode[6];		/* 区号 */
	char    sAreaCodeName[21];		/* 分公司名称 */
	char    sAreaName[21];		/* 营业区名称 */
	char    sCustNane[31];		/* 客户名称 */
	int     iTypeID;		
	/* 号码类型'201'为201卡号码'202'为ic卡号码 */
	struct ServCardStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FServCardStruct{

	char    sAccNbr[15];		/* 号码 */
	char    sAreaCode[5];		/* 区号 */
	char    sAreaCodeName[20];		/* 分公司名称 */
	char    sAreaName[20];		/* 营业区名称 */
	char    sCustNane[30];		/* 客户名称 */
	char    sTypeID[4];		/* 号码类型'201'为201卡号码'202'为ic卡号码 */
};


/*批量数据结构缓冲写入SERV_CARD*/
int EInsertStructToServCard(struct ServCardStruct *p,
	int iInsertFlag,struct ServCardStructOut *pTarget);

/*批量数据动态从SERV_CARD中用结构缓冲方式取数据*/
int EGetServCardToStruct(struct ServCardStruct *p,
	struct ServCardStructIn *pSource);
void mvitem_fmservcard(struct FServCardStruct *pi,struct ServCardStruct *po);
void mvitem_mfservcard(struct ServCardStruct *pi,struct FServCardStruct *po);
int InsertServCard(char sFileName[],char sTableName[]);

int data_search_bintree_serv_card_e(void *pValue,void*pData);
void assign_insert_bintree_serv_card_e(void **ppData,void *pData);
void assign_insert_bintree_out_accnbr_e(void **ppData,void *pData);
int data_search_bintree_out_accnbr_e(void *pValue,void*pData);
int rdata_search_bintree_msisdn_stat_e(void *pValue,void*pData);
void assign_insert_bintree_msisdn_stat_e(void **ppData,void *pData);
int data_search_bintree_msisdn_stat_e(void *pValue,void*pData);
/*单个结构申明*/
struct OutAccNbrStruct{

	struct OutAccNbrStruct *pNext;
	char    sCustNane[31];		/* 客户名称 */
	char    sAreaCodeName[21];	/* 分公司名称 */
	char    sAreaName[21];		/* 营业区名称 */
	int	iUserCnt;		/*话机数量*/
	int	iUserFeeCnt;		/*发生通话费话机数量*/
	int	iUserLcCnt;		/*零次户数量*/
	int	iToTalFee;		/*客户发生总话务量*/
	int	iUserFee;		/*单机话务量*/
	char    sAreaCode[6];		/* 区号 */
	char    sAccNbr[16];		/* 号码 */
	int     iTypeID;		
	char	sOutFileName[30];	/*输出文件名*/
	/* 号码类型'201'为201卡号码'202'为ic卡号码 */
	struct OutAccNbrStruct *pLoadNext;
};

/*单个结构申明*/
struct NbrStatStruct{

	struct NbrStatStruct *pNext;
	char    sRecordType[3];		
/* 记录类型01零次02漏报03上报号码发生话费04上报号码总量05话务号码总量 */
/*06本月新增的客户07本月新增的零次户*/
	char    sAccNbr[16];		/* 号码 */
	char	sServiceType[11];	/* 000所有、xxx自定义 */
	char    sAreaCode[6];		/* 区号 */
	int	iToTalFee;		/*客户发生总话务量*/
	char    sBillingCycleID[7];	/* 帐单归属帐期 */	
	char	sOutFileName[30];	/*输出文件名*/
	struct NbrStatStruct *pLoadNext;
};
int data_search_bintree_nbr_stat_e(void *pValue,void*pData);

/*单个结构申明*/
struct MsisdnStatStruct{

	struct MsisdnStatStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sAreaCode[10];		/* 归属地区 */
	int     iAreaID;		/* 归属营业区 */
	char    sNetType[4];		
/* 'CT' 电信 'CNC' 网通,'CU' 联通,'CM' 移动,'IMS' IMSI,'ESN' 电子串号 */	
	char    sCallType[3];		/* 00所有、01主叫、02被叫、03呼转 */
	char    sServiceType[11];		/* 000所有、xxx自定义 */
	LONGINT iTotalDuration;		/* 总时长 */
	LONGINT iTotalMin;		/* 总分钟数*60 */
	int     iTotalCnt;		/* 总次数 */
	LONGINT iTotalFee1;		/* 总费用1 */
	LONGINT iTotalFee2;		/* 总费用2 */
	LONGINT iTotalFee3;		/* 总费用3 */
	char    sBillingCycleID[7];		/* 帐单归属帐期 */
	char    sRowID[19];             /* 记录索引 */
	struct MsisdnStatStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FMsisdnStatStruct{

	char    sMsisdn[15];
	char    sAreaCode[9];
	char    sAreaID[4];
	char    sNetType[3];
	char    sCallType[2];
	char    sServiceType[10];
	char    sTotalDuration[12];
	char    sTotalMin[12];
	char    sTotalCnt[9];
	char    sTotalFee1[12];
	char    sTotalFee2[12];
	char    sTotalFee3[12];
	char    sBillingCycleID[6];
};

/* 输入结构缓冲申明*/
struct MsisdnStatStructIn{

#ifndef MSISDN_STAT_BUFLEN_IN
#define MSISDN_STAT_BUFLEN_IN		300
#endif

	struct MsisdnStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[MSISDN_STAT_BUFLEN_IN][16];
		/* 归属地区 */
	char    asAreaCode[MSISDN_STAT_BUFLEN_IN][10];
		/* 归属营业区 */
	int     aiAreaID[MSISDN_STAT_BUFLEN_IN];
		/* 'CT' 电信 'CNC' 网通,'CU' 联通,'CM' 移动,'IMS' IMSI,'ESN' 电子串号 */
	char    asNetType[MSISDN_STAT_BUFLEN_IN][4];
		/* 00所有、01主叫、02被叫、03呼转 */
	char    asCallType[MSISDN_STAT_BUFLEN_IN][3];
		/* 000所有、xxx自定义 */
	char    asServiceType[MSISDN_STAT_BUFLEN_IN][11];
		/* 总时长 */
	LONGINT aiTotalDuration[MSISDN_STAT_BUFLEN_IN];
		/* 总分钟数*60 */
	LONGINT aiTotalMin[MSISDN_STAT_BUFLEN_IN];
		/* 总次数 */
	int     aiTotalCnt[MSISDN_STAT_BUFLEN_IN];
		/* 总费用1 */
	LONGINT aiTotalFee1[MSISDN_STAT_BUFLEN_IN];
		/* 总费用2 */
	LONGINT aiTotalFee2[MSISDN_STAT_BUFLEN_IN];
		/* 总费用3 */
	LONGINT aiTotalFee3[MSISDN_STAT_BUFLEN_IN];
		/* 帐单归属帐期 */
	char    asBillingCycleID[MSISDN_STAT_BUFLEN_IN][7];
	        /* 记录索引 */
        char    asRowID[MSISDN_STAT_BUFLEN_IN][19];
};

/*输出结构缓冲申明*/
struct MsisdnStatStructOut{

#ifndef MSISDN_STAT_BUFLEN_OUT
#define MSISDN_STAT_BUFLEN_OUT		300
#endif

	struct MsisdnStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asMsisdn[MSISDN_STAT_BUFLEN_OUT][16];
		/* 归属地区 */
	char    asAreaCode[MSISDN_STAT_BUFLEN_OUT][10];
		/* 归属营业区 */
	int     aiAreaID[MSISDN_STAT_BUFLEN_OUT];
		/* 'CT' 电信 'CNC' 网通,'CU' 联通,'CM' 移动,'IMS' IMSI,'ESN' 电子串号 */
	char    asNetType[MSISDN_STAT_BUFLEN_OUT][4];
		/* 00所有、01主叫、02被叫、03呼转 */
	char    asCallType[MSISDN_STAT_BUFLEN_OUT][3];
		/* 000所有、xxx自定义 */
	char    asServiceType[MSISDN_STAT_BUFLEN_OUT][11];
		/* 总时长 */
	LONGINT aiTotalDuration[MSISDN_STAT_BUFLEN_OUT];
		/* 总分钟数*60 */
	LONGINT aiTotalMin[MSISDN_STAT_BUFLEN_OUT];
		/* 总次数 */
	int     aiTotalCnt[MSISDN_STAT_BUFLEN_OUT];
		/* 总费用1 */
	LONGINT aiTotalFee1[MSISDN_STAT_BUFLEN_OUT];
		/* 总费用2 */
	LONGINT aiTotalFee2[MSISDN_STAT_BUFLEN_OUT];
		/* 总费用3 */
	LONGINT aiTotalFee3[MSISDN_STAT_BUFLEN_OUT];
		/* 帐单归属帐期 */
	char    asBillingCycleID[MSISDN_STAT_BUFLEN_OUT][7];
};


/*UP结构缓冲申明*/
struct MsisdnStatStructUp{

#ifndef MSISDN_STAT_BUFLEN_UP
#define MSISDN_STAT_BUFLEN_UP		300
#endif

	struct MsisdnStatStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asMsisdn[MSISDN_STAT_BUFLEN_UP][16];
		/* 归属地区 */
	char    asAreaCode[MSISDN_STAT_BUFLEN_UP][10];
		/* 归属营业区 */
	int     aiAreaID[MSISDN_STAT_BUFLEN_UP];
		/* 'CT' 电信 'CNC' 网通,'CU' 联通,'CM' 移动,'IMS' IMSI,'ESN' 电子串号 */
	char    asNetType[MSISDN_STAT_BUFLEN_UP][4];
		/* 00所有、01主叫、02被叫、03呼转 */
	char    asCallType[MSISDN_STAT_BUFLEN_UP][3];
		/* 000所有、xxx自定义 */
	char    asServiceType[MSISDN_STAT_BUFLEN_UP][11];
		/* 总时长 */
	LONGINT aiTotalDuration[MSISDN_STAT_BUFLEN_UP];
		/* 总分钟数 */
	LONGINT	aiTotalMin[MSISDN_STAT_BUFLEN_UP];
		/* 总次数 */
	int     aiTotalCnt[MSISDN_STAT_BUFLEN_UP];
		/* 总费用1 */
	LONGINT aiTotalFee1[MSISDN_STAT_BUFLEN_UP];
		/* 总费用2 */
	LONGINT aiTotalFee2[MSISDN_STAT_BUFLEN_UP];
		/* 总费用3 */
	LONGINT aiTotalFee3[MSISDN_STAT_BUFLEN_UP];
		/* 帐单归属帐期 */
	char    asBillingCycleID[MSISDN_STAT_BUFLEN_UP][7];
	char    asRowID[MSISDN_STAT_BUFLEN_UP][19];
};

/*批量数据结构缓冲写入MSISDN_STAT*/
int EInsertStructToMsisdnStat(struct MsisdnStatStruct *p,
	int iInsertFlag,struct MsisdnStatStructOut *pTarget);
/*批量数据动态从MSISDN_STAT中用结构缓冲方式取数据*/
int EGetMsisdnStatToStruct(struct MsisdnStatStruct *p,
	struct MsisdnStatStructIn *pSource);
/*批量数据结构缓冲更新MSISDN_STAT*/
int EUpdateStructToMsisdnStat(struct MsisdnStatStruct *p,
	int iUpdateFlag,struct MsisdnStatStructUp *pTarget);	
void mvitem_msisdnstat(struct MsisdnStatStruct *pi,struct MsisdnStatStruct *po);	
int data_search_bintree_msisdn_stat_e(void *pValue,void*pData);
void assign_insert_bintree_msisdn_stat_e(void **ppData,void *pData);

void mvitem_mfmsisdnstat(struct MsisdnStatStruct *pi,
	struct FMsisdnStatStruct *po);
int MsisdnStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/*单个结构申明*/
struct SettDayStruct{

	struct SettDayStruct *pNext;
	int     iRecordNumber;		/* 记录行号 */
	char    sHomeAreaCode[6];		/* 主叫本地网地区代码 */
	char    sCalledCode[6];		/* 被叫本地网地区代码 */
	char    sStartDate[9];		/* 通话日期 */
	char    sCallingCarrierID[6];		/* 主叫运营商标识 */
	char    sCalledCarrierID[6];		/* 被叫运营商标识 */
	char    sThirdCarrierID[6];		/* 转接运营商标识 */
	char    sSettCarrierID[6];		/* 结算运营商标识 */
	char    sSettType[13];		/* 结算项目标识 */
	char    sRoamType[2];		/* 移动漫游标志 */
	char    sTariffType[3];		/* 结算费率 */
	char    sCountyFlag[2];		/* 本地网区间 */
	char    sIpAccNbr[9];		/* IP接入号 */
	char    sDurationCnt[16];		/* 通话次数 */
	char    sDuration[16];		/* 通话时长 */
	char    sSettCnt[16];		/* 结算跳次 */
	char    sTotalFee[16];		/* 结算费用 */
	char    sCount[16];		/* 话单数 */
	struct SettDayStruct *pLoadNext;
};
/*单个结构申明*/
struct SettMonthStruct{

	struct SettMonthStruct *pNext;
	int     iRecordNumber;		/* 记录行号 */
	char    sVisitAreaCode[6];		/* 本地网地区代码 */
	char    sStatMonth[7];		/* 出帐月份 */
	char    sSettCarrierID[6];		/* 结算运营商标识 */
	char    sSettType[13];		/* 结算项目标识 */
	char    sDurationCnt[16];		/* 通话次数 */
	char    sDuration[16];		/* 通话时长 */
	char    sSettCnt[16];		/* 结算跳次 */
	char    sTotalFee[16];		/* 结算费用 */
	char    sCount[16];		/* 话单数 */
	struct SettMonthStruct *pLoadNext;
};

/*单个结构申明*/
struct CustCntStruct{

	struct CustCntStruct *pNext;
	int     iRecordNumber;		/* 记录行号 */
	char    sStatMonth[7];		/* 统计月份 */
	char    sOppCarrierID[6];		/* 其它运营商标识 */
	int     iCustCnt;		/* 客户数 */
	int     iAddCustCnt;		/* 新增客户数 */
	struct CustCntStruct *pLoadNext;
};


/*单个结构申明*/
struct SmsStatUpStruct{

	struct SmsStatUpStruct *pNext;
	char    sSettCapitalCode[4];		/* 结算省公司标识 */
	char    sBillType[2];		/* 记帐类型 */
	char    sBillingCycleID[7];		/* 实收月份 */
	char    sSettAreaCode[4];		/* 结算本地网标识 */
	char    sCallingCarrierID[3];		/* 主叫所属运营商标识 */
	char    sRecordType[4];		/* 记录类型 */
	char    sCalledCapitalCode[4];		/* 被叫所属省公司标识 */
	char    sCalledCarrierID[3];		/* 被叫所属运营商标识 */
	char    sSpCode[11];		/* SP企业编号 */
	char    sTotalCnt[16];		/* 总流量 */
	char    sTotalFee[16];		/* 总金额 */
	char    sFlag[2];		/* 调整标志 */
	char    sReserve[11];		/* 保留 */
	struct SmsStatUpStruct *pLoadNext;
};

struct SmsStatUpHeadStruct{
	
	struct SmsStatUpHeadStruct *pNext;
	char	sServiceCode[5];	/*业务代码*/
	char	CapitalCode[4];		/* 省公司标识 */
	char	sCreateDate[9];		/*文件创建日期*/
	int	iFileCnt;		/*有效记录数*/
	char	sTotalCnt[16];		/*总流量*/
	char	sTotalFee[16];		/*总金额*/
	char	sReserve[20];		/*保留*/
	struct SmsStatUpHeadStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FSettDayStruct{

	char    sRecordNumber[8];		/* 记录行号 */
	char    sHomeAreaCode[5];		/* 主叫本地网地区代码 */
	char    sCalledCode[5];		/* 被叫本地网地区代码 */
	char    sStartDate[8];		/* 通话日期 */
	char    sCallingCarrierID[5];		/* 主叫运营商标识 */
	char    sCalledCarrierID[5];		/* 被叫运营商标识 */
	char    sThirdCarrierID[5];		/* 转接运营商标识 */
	char    sSettCarrierID[5];		/* 结算运营商标识 */
	char    sSettType[12];		/* 结算项目标识 */
	char    sRoamType[1];		/* 移动漫游标志 */
	char    sTariffType[2];		/* 结算费率 */
	char    sCountyFlag[1];		/* 本地网区间 */
	char    sIpAccNbr[8];		/* IP接入号 */
	char    sDurationCnt[15];		/* 通话次数 */
	char    sDuration[15];		/* 通话时长 */
	char    sSettCnt[15];		/* 结算跳次 */
	char    sTotalFee[15];		/* 结算费用 */
	char    sCount[15];		/* 话单数 */
};


/*单个文件结构申明*/
struct FSettMonthStruct{

	char    sRecordNumber[8];		/* 记录行号 */
	char    sVisitAreaCode[5];		/* 本地网地区代码 */
	char    sStatMonth[6];		/* 出帐月份 */
	char    sSettCarrierID[5];		/* 结算运营商标识 */
	char    sSettType[12];		/* 结算项目标识 */
	char    sDurationCnt[15];		/* 通话次数 */
	char    sDuration[15];		/* 通话时长 */
	char    sSettCnt[15];		/* 结算跳次 */
	char    sTotalFee[15];		/* 结算费用 */
	char    sCount[15];		/* 话单数 */
};


/*单个文件结构申明*/
struct FCustCntStruct{

	char    sRecordNumber[8];		/* 记录行号 */
	char    sStatMonth[6];		/* 统计月份 */
	char    sOppCarrierID[5];		/* 其它运营商标识 */
	char    sCustCnt[8];		/* 客户数 */
	char    sAddCustCnt[8];		/* 新增客户数 */
};


/*单个文件结构申明*/
struct FSmsStatUpStruct{

	char    sSettCapitalCode[3];	/* 结算省公司标识 */
	char    sBillType[1];		/* 记帐类型 */
	char    sBillingCycleID[6];		/* 实收月份 */
	char    sSettAreaCode[3];		/* 结算本地网标识 */
	char    sCallingCarrierID[2];		/* 主叫所属运营商标识 */
	char    sRecordType[3];		/* 记录类型 */
	char    sCalledCapitalCode[3];		/* 被叫所属省公司标识 */
	char    sCalledCarrierID[2];		/* 被叫所属运营商标识 */
	char    sSpCode[10];		/* SP企业编号 */
	char    sTotalCnt[15];		/* 总流量 */
	char    sTotalFee[15];		/* 总金额 */
	char    sFlag[1];		/* 调整标志 */
	char    sReserve[10];		/* 保留 */
};

struct FSmsStatUpHeadStruct{

	char	sServiceCode[4];	/*业务代码*/
	char	CapitalCode[3];		/* 省公司标识 */
	char	sCreateDate[8];		/*文件创建日期*/
	char	sFileCnt[6];		/*有效记录数*/
	char	sTotalCnt[15];		/*总流量*/
	char	sTotalFee[15];		/*总金额*/
	char	sReserve[19];		/*保留*/
};



/*单个结构申明*/
struct SettTypeRelationStruct{

	struct SettTypeRelationStruct *pNext;
	int     iTicketTypeID;		/* 话单类型 */
	char    sSettType[13];		/* 结算项目标识 */
	char    sCarrierID[6];		/* 结算运营商标识 */
	char    sTariffType[3];		/* 结算费率 */
	int     iPriority;		/* 优先级 */
	char    sUserType[2];		/* 用户类型 */
	char    sCountyFlag[2];		/* 本地网区间标识 */
	char    sRemark[81];		/* 描述 */
	struct SettTypeRelationStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct SettTypeRelationStructIn{

#ifndef SETT_TYPE_RELATION_BUFLEN_IN
#define SETT_TYPE_RELATION_BUFLEN_IN		300
#endif

	struct SettTypeRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型 */
	int     aiTicketTypeID[SETT_TYPE_RELATION_BUFLEN_IN];
		/* 结算项目标识 */
	char    asSettType[SETT_TYPE_RELATION_BUFLEN_IN][13];
		/* 结算运营商标识 */
	char    asCarrierID[SETT_TYPE_RELATION_BUFLEN_IN][6];
		/* 结算费率 */
	char    asTariffType[SETT_TYPE_RELATION_BUFLEN_IN][3];
		/* 优先级 */
	int     aiPriority[SETT_TYPE_RELATION_BUFLEN_IN];
		/* 用户类型 */
	char    asUserType[SETT_TYPE_RELATION_BUFLEN_IN][2];
		/* 本地网区间标识 */
	char    asCountyFlag[SETT_TYPE_RELATION_BUFLEN_IN][2];
		/* 描述 */
	char    asRemark[SETT_TYPE_RELATION_BUFLEN_IN][81];
};



int EGetSettTypeRelationToStruct(struct SettTypeRelationStruct *p,
	struct SettTypeRelationStructIn *pSource);
	
void mvitem_mfsettday(struct SettDayStruct *pi,struct FSettDayStruct *po);
void mvitem_mfcustcnt(struct CustCntStruct *pi,struct FCustCntStruct *po);
int data_search_bintree_sett_type_r_e(void *pValue,void*pData);
void assign_insert_bintree_sett_type_r_e(void **ppData,void *pData);
int rdata_search_bintree_sett_type_r_e(void *pValue,void*pData);
int data_search_bintree_sett_day_e(void *pValue,void*pData);
void assign_insert_bintree_sett_day_e(void **ppData,void *pData);

void mvitem_mfsettmonth(struct SettMonthStruct *pi,
	struct FSettMonthStruct *po);
void mvitem_mfsmsstatup(struct SmsStatUpStruct *pi,
	struct FSmsStatUpStruct *po);
void mvitem_mfsmsstatuphead(struct SmsStatUpHeadStruct *pi,
	struct FSmsStatUpHeadStruct *po);

/*输出结构缓冲申明*/
struct SettSumDayStructOut{

#ifndef SETT_SUM_DAY_BUFLEN_OUT
#define SETT_SUM_DAY_BUFLEN_OUT		300
#endif

	struct SettSumDayStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 话单类型 */
	int     aiTicketTypeID[SETT_SUM_DAY_BUFLEN_OUT];
		/* 本地网标识 */
	char    asVisitAreaCode[SETT_SUM_DAY_BUFLEN_OUT][6];
		/* 统计月份 */
	char    asStatMonth[SETT_SUM_DAY_BUFLEN_OUT][7];
		/* 主叫归属地区 */
	char    asHomeAreaCode[SETT_SUM_DAY_BUFLEN_OUT][6];
		/* 被叫归属地区 */
	char    asCalledCode[SETT_SUM_DAY_BUFLEN_OUT][6];
		/* 通话日期 */
	char    asStartDate[SETT_SUM_DAY_BUFLEN_OUT][9];
		/* 主叫运营商标识 */
	int     aiCallingCarrierID[SETT_SUM_DAY_BUFLEN_OUT];
		/* 被叫运营商标识 */
	int     aiCalledCarrierID[SETT_SUM_DAY_BUFLEN_OUT];
		/* 转接运营商标识 */
	int     aiThirdCarrierID[SETT_SUM_DAY_BUFLEN_OUT];
		/* 移动漫游标志 */
	char    asUserType[SETT_SUM_DAY_BUFLEN_OUT][2];
		/* IP接入号 */
	char    asIpAccNbr[SETT_SUM_DAY_BUFLEN_OUT][9];
		/* 通话次数 */
	int     aiDurationCnt[SETT_SUM_DAY_BUFLEN_OUT];
		/* 通话时长 */
	int     aiDuration[SETT_SUM_DAY_BUFLEN_OUT];
		/* 结算跳次 */
	int     aiSettCnt[SETT_SUM_DAY_BUFLEN_OUT];
		/* 结算费用 */
	int     aiTotalFee[SETT_SUM_DAY_BUFLEN_OUT];
		/* 话单数 */
	int     aiCount[SETT_SUM_DAY_BUFLEN_OUT];
		/* 状态 */
	char    asState[SETT_SUM_DAY_BUFLEN_OUT][2];
		/* 处理时间 */
	char    asDealDate[SETT_SUM_DAY_BUFLEN_OUT][15];
};


/* 输入结构缓冲申明*/
struct SettSumDayStructIn{

#ifndef SETT_SUM_DAY_BUFLEN_IN
#define SETT_SUM_DAY_BUFLEN_IN		300
#endif

	struct SettSumDayStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类型 */
	int     aiTicketTypeID[SETT_SUM_DAY_BUFLEN_IN];
		/* 本地网标识 */
	char     asVisitAreaCode[SETT_SUM_DAY_BUFLEN_IN][6];
		/* 统计月份 */
	char    asStatMonth[SETT_SUM_DAY_BUFLEN_IN][7];
		/* 主叫归属地区 */
	char    asHomeAreaCode[SETT_SUM_DAY_BUFLEN_IN][6];
		/* 被叫归属地区 */
	char    asCalledCode[SETT_SUM_DAY_BUFLEN_IN][6];
		/* 通话日期 */
	char    asStartDate[SETT_SUM_DAY_BUFLEN_IN][9];
		/* 主叫运营商标识 */
	int     aiCallingCarrierID[SETT_SUM_DAY_BUFLEN_IN];
		/* 被叫运营商标识 */
	int     aiCalledCarrierID[SETT_SUM_DAY_BUFLEN_IN];
		/* 转接运营商标识 */
	int     aiThirdCarrierID[SETT_SUM_DAY_BUFLEN_IN];
		/* 移动漫游标志 */
	char    asUserType[SETT_SUM_DAY_BUFLEN_IN][2];
		/* IP接入号 */
	char    asIpAccNbr[SETT_SUM_DAY_BUFLEN_IN][9];
		/* 通话次数 */
	int     aiDurationCnt[SETT_SUM_DAY_BUFLEN_IN];
		/* 通话时长 */
	int     aiDuration[SETT_SUM_DAY_BUFLEN_IN];
		/* 结算跳次 */
	int     aiSettCnt[SETT_SUM_DAY_BUFLEN_IN];
		/* 结算费用 */
	int     aiTotalFee[SETT_SUM_DAY_BUFLEN_IN];
		/* 话单数 */
	int     aiCount[SETT_SUM_DAY_BUFLEN_IN];
		/* 状态 */
	char    asState[SETT_SUM_DAY_BUFLEN_IN][2];
		/* 处理时间 */
	char    asDealDate[SETT_SUM_DAY_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SettSumDayStruct{

	struct SettSumDayStruct *pNext;
	int     iTicketTypeID;		/* 话单类型 */
	char    sVisitAreaCode[6];		/* 本地网标识 */
	char    sStatMonth[7];		/* 统计月份 */
	char    sHomeAreaCode[6];		/* 主叫归属地区 */
	char    sCalledCode[6];		/* 被叫归属地区 */
	char    sStartDate[9];		/* 通话日期 */
	int     iCallingCarrierID;		/* 主叫运营商标识 */
	int     iCalledCarrierID;		/* 被叫运营商标识 */
	int     iThirdCarrierID;		/* 转接运营商标识 */
	char    sUserType[2];		/* 移动漫游标志 */
	char    sIpAccNbr[9];		/* IP接入号 */
	int     iDurationCnt;		/* 通话次数 */
	int     iDuration;		/* 通话时长 */
	int     iSettCnt;		/* 结算跳次 */
	int     iTotalFee;		/* 结算费用 */
	int     iCount;		/* 话单数 */
	char    sState[2];		/* 状态 */
	char    sDealDate[15];		/* 处理时间 */
	struct SettSumDayStruct *pLoadNext;
};


/*批量数据动态从SETT_SUM_DAY中用结构缓冲方式取数据*/
int EGetSettSumDayToStruct(struct SettSumDayStruct *p,
	struct SettSumDayStructIn *pSource);
/*批量数据结构缓冲写入SETT_SUM_DAY*/
int EInsertStructToSettSumDay(struct SettSumDayStruct *p,
	int iInsertFlag,struct SettSumDayStructOut *pTarget);


/* 输入结构缓冲申明*/
struct DownTollStatStructIn{

#ifndef DOWN_TOLL_STAT_BUFLEN_IN
#define DOWN_TOLL_STAT_BUFLEN_IN		300
#endif

	struct DownTollStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 主叫用户类别 */
	char    asCallingUserType[DOWN_TOLL_STAT_BUFLEN_IN][2];
		/* 入城市代码 */
	char    asInCityCode[DOWN_TOLL_STAT_BUFLEN_IN][4];
		/* 出城市代码 */
	char    asOutCityCout[DOWN_TOLL_STAT_BUFLEN_IN][4];
		/* 拨打本地GSM用户长途费用 */
	char    asTollFee1[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地GSM用户通话结算时长 */
	char    asDuration1[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地GSM用户呼叫次数 */
	char    asCnt1[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地CDMA用户长途费用 */
	char    asTollFee2[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地CDMA用户通话结算时长 */
	char    asDuration2[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地CDMA用户呼叫次数 */
	char    asCnt2[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地外网用户长途费用 */
	char    asTollFee3[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地外网用户通话结算时长 */
	char    asDuration3[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 拨打本地外网用户呼叫次数 */
	char    asCnt3[DOWN_TOLL_STAT_BUFLEN_IN][11];
		/* 结算月份 */
	char    asSettMonth[DOWN_TOLL_STAT_BUFLEN_IN][7];
};

/*单个结构申明*/
struct DownTollStatStruct{

	struct DownTollStatStruct *pNext;
	char    sCallingUserType[2];		/* 主叫用户类别 */
	char    sInCityCode[4];		/* 入城市代码 */
	char    sOutCityCout[4];		/* 出城市代码 */
	char    sTollFee1[11];		/* 拨打本地GSM用户长途费用 */
	char    sDuration1[11];		/* 拨打本地GSM用户通话结算时长 */
	char    sCnt1[11];		/* 拨打本地GSM用户呼叫次数 */
	char    sTollFee2[11];		/* 拨打本地CDMA用户长途费用 */
	char    sDuration2[11];		/* 拨打本地CDMA用户通话结算时长 */
	char    sCnt2[11];		/* 拨打本地CDMA用户呼叫次数 */
	char    sTollFee3[11];		/* 拨打本地外网用户长途费用 */
	char    sDuration3[11];		/* 拨打本地外网用户通话结算时长 */
	char    sCnt3[11];		/* 拨打本地外网用户呼叫次数 */
	char    sSettMonth[7];		/* 结算月份 */
	struct DownTollStatStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FDownTollStatStruct{

	char    sCallingUserType[1];		/* 主叫用户类别 */
	char    sInCityCode[3];		/* 入城市代码 */
	char    sOutCityCout[3];		/* 出城市代码 */
	char    sTollFee1[10];		/* 拨打本地GSM用户长途费用 */
	char    sDuration1[10];		/* 拨打本地GSM用户通话结算时长 */
	char    sCnt1[10];		/* 拨打本地GSM用户呼叫次数 */
	char    sTollFee2[10];		/* 拨打本地CDMA用户长途费用 */
	char    sDuration2[10];		/* 拨打本地CDMA用户通话结算时长 */
	char    sCnt2[10];		/* 拨打本地CDMA用户呼叫次数 */
	char    sTollFee3[10];		/* 拨打本地外网用户长途费用 */
	char    sDuration3[10];		/* 拨打本地外网用户通话结算时长 */
	char    sCnt3[10];		/* 拨打本地外网用户呼叫次数 */
	char    sSettMonth[6];		/* 结算月份 */
};

/* 输入结构缓冲申明*/
struct DownVoipStatStructIn{

#ifndef DOWN_VOIP_STAT_BUFLEN_IN
#define DOWN_VOIP_STAT_BUFLEN_IN		300
#endif

	struct DownVoipStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 主叫号码类别 */
	char    asCallingUserType[DOWN_VOIP_STAT_BUFLEN_IN][2];
		/* 入城市代码 */
	char    asInCityCode[DOWN_VOIP_STAT_BUFLEN_IN][4];
		/* 出城市代码 */
	char    asOutCityCout[DOWN_VOIP_STAT_BUFLEN_IN][4];
		/* 本省分发行卡类业务拨打异地GSM用户长途费用 */
	char    asTollFee1[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用本省分发行卡类业务拨打异地GSM用户结算时长 */
	char    asDuration1[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用本省分发行卡类业务拨打异地GSM用户呼叫次数 */
	char    asCnt1[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用省分发行卡类业务拨打异地CDMA用户长途费用 */
	char    asTollFee2[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用省分发行卡类业务拨打异地CDMA用户结算时长 */
	char    asDuration2[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用省分发行卡类业务拨打异地CDMA用户呼叫次数 */
	char    asCnt2[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用省分发行卡类业务拨打异地外网用户长途费用 */
	char    asTollFee3[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用省分发行卡类业务拨打异地外网用户结算时长 */
	char    asDuration3[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用省分发行卡类业务拨打异地外网用户呼叫次数 */
	char    asCnt3[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地GSM用户长途费用 */
	char    asTollFee4[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地GSM用户结算时长 */
	char    asDuration4[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地GSM用户呼叫次数 */
	char    asCnt4[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地CDAM用户长途费用 */
	char    asTollFee5[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地CDAM用户结算时长 */
	char    asDuration5[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地CDAM用户呼叫次数 */
	char    asCnt5[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地外网用户长途费用 */
	char    asTollFee6[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地外网用户结算时长 */
	char    asDuration6[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 使用语音专线业务拨打异地外网用户呼叫次数 */
	char    asCnt6[DOWN_VOIP_STAT_BUFLEN_IN][11];
		/* 结算月份 */
	char    asSettMonth[DOWN_VOIP_STAT_BUFLEN_IN][7];
};

/*单个结构申明*/
struct DownVoipStatStruct{

	struct DownVoipStatStruct *pNext;
	char    sCallingUserType[2];		/* 主叫号码类别 */
	char    sInCityCode[4];		/* 入城市代码 */
	char    sOutCityCout[4];		/* 出城市代码 */
	char    sTollFee1[11];		/* 本省分发行卡类业务拨打异地GSM用户长途费用 */
	char    sDuration1[11];		/* 使用本省分发行卡类业务拨打异地GSM用户结算时长 */
	char    sCnt1[11];		/* 使用本省分发行卡类业务拨打异地GSM用户呼叫次数 */
	char    sTollFee2[11];		/* 使用省分发行卡类业务拨打异地CDMA用户长途费用 */
	char    sDuration2[11];		/* 使用省分发行卡类业务拨打异地CDMA用户结算时长 */
	char    sCnt2[11];		/* 使用省分发行卡类业务拨打异地CDMA用户呼叫次数 */
	char    sTollFee3[11];		/* 使用省分发行卡类业务拨打异地外网用户长途费用 */
	char    sDuration3[11];		/* 使用省分发行卡类业务拨打异地外网用户结算时长 */
	char    sCnt3[11];		/* 使用省分发行卡类业务拨打异地外网用户呼叫次数 */
	char    sTollFee4[11];		/* 使用语音专线业务拨打异地GSM用户长途费用 */
	char    sDuration4[11];		/* 使用语音专线业务拨打异地GSM用户结算时长 */
	char    sCnt4[11];		/* 使用语音专线业务拨打异地GSM用户呼叫次数 */
	char    sTollFee5[11];		/* 使用语音专线业务拨打异地CDAM用户长途费用 */
	char    sDuration5[11];		/* 使用语音专线业务拨打异地CDAM用户结算时长 */
	char    sCnt5[11];		/* 使用语音专线业务拨打异地CDAM用户呼叫次数 */
	char    sTollFee6[11];		/* 使用语音专线业务拨打异地外网用户长途费用 */
	char    sDuration6[11];		/* 使用语音专线业务拨打异地外网用户结算时长 */
	char    sCnt6[11];		/* 使用语音专线业务拨打异地外网用户呼叫次数 */
	char    sSettMonth[7];		/* 结算月份 */
	struct DownVoipStatStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FDownVoipStatStruct{

	char    sCallingUserType[1];		/* 主叫号码类别 */
	char    sInCityCode[3];		/* 入城市代码 */
	char    sOutCityCout[3];		/* 出城市代码 */
	char    sTollFee1[10];		/* 本省分发行卡类业务拨打异地GSM用户长途费用 */
	char    sDuration1[10];		/* 使用本省分发行卡类业务拨打异地GSM用户结算时长 */
	char    sCnt1[10];		/* 使用本省分发行卡类业务拨打异地GSM用户呼叫次数 */
	char    sTollFee2[10];		/* 使用省分发行卡类业务拨打异地CDMA用户长途费用 */
	char    sDuration2[10];		/* 使用省分发行卡类业务拨打异地CDMA用户结算时长 */
	char    sCnt2[10];		/* 使用省分发行卡类业务拨打异地CDMA用户呼叫次数 */
	char    sTollFee3[10];		/* 使用省分发行卡类业务拨打异地外网用户长途费用 */
	char    sDuration3[10];		/* 使用省分发行卡类业务拨打异地外网用户结算时长 */
	char    sCnt3[10];		/* 使用省分发行卡类业务拨打异地外网用户呼叫次数 */
	char    sTollFee4[10];		/* 使用语音专线业务拨打异地GSM用户长途费用 */
	char    sDuration4[10];		/* 使用语音专线业务拨打异地GSM用户结算时长 */
	char    sCnt4[10];		/* 使用语音专线业务拨打异地GSM用户呼叫次数 */
	char    sTollFee5[10];		/* 使用语音专线业务拨打异地CDAM用户长途费用 */
	char    sDuration5[10];		/* 使用语音专线业务拨打异地CDAM用户结算时长 */
	char    sCnt5[10];		/* 使用语音专线业务拨打异地CDAM用户呼叫次数 */
	char    sTollFee6[10];		/* 使用语音专线业务拨打异地外网用户长途费用 */
	char    sDuration6[10];		/* 使用语音专线业务拨打异地外网用户结算时长 */
	char    sCnt6[10];		/* 使用语音专线业务拨打异地外网用户呼叫次数 */
	char    sSettMonth[6];		/* 结算月份 */
};

int EGetDownVoipStatToStruct(struct DownVoipStatStruct *p,
	struct DownVoipStatStructIn *pSource);
void mvitem_mfdownvoipstat(struct DownVoipStatStruct *pi,
	struct FDownVoipStatStruct *po);
int DownVoipStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
int EGetDownTollStatToStruct(struct DownTollStatStruct *p,
	struct DownTollStatStructIn *pSource);
void mvitem_mfdowntollstat(struct DownTollStatStruct *pi,
	struct FDownTollStatStruct *po);
int DownTollStat2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);
	
/* 输入结构缓冲申明*/
struct XStrTicketStructIn{

#ifndef X_STR_TICKET_BUFLEN_IN
#define X_STR_TICKET_BUFLEN_IN		300
#endif

	struct XStrTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[8192];/*将原来的SQL语句编写到这里*/
	char sCondition[32];  /*这里固定为空*/
		/* 通用串函数 */
	char    asXStr[X_STR_TICKET_BUFLEN_IN][4000];
		/* 来源 */
	char    asSourceID[X_STR_TICKET_BUFLEN_IN][41];
	char    asRowID[X_STR_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct XStrTicketStruct{

	struct XStrTicketStruct *pNext;
	char    sXStr[4000];		/* 通用串函数 */
	char    sSourceID[41];		/* 来源 */
	char	sRowID[19];
	struct XStrTicketStruct *pLoadNext;
};
/*批量数据动态从X_STR_TICKET中用结构缓冲方式取数据*/
int EGetXStrTicketToStruct(struct XStrTicketStruct *p,
	struct XStrTicketStructIn *pSource);
int XStrTicket2Str(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

/* 输入结构缓冲申明*/
struct MyTabColumnsStructIn{

#ifndef MY_TAB_COLUMNS_BUFLEN_IN
#define MY_TAB_COLUMNS_BUFLEN_IN		300
#endif

	struct MyTabColumnsStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[8192];/*将原来的SQL语句编写到这里*/
	char sCondition[32];  /*这里固定为空*/
		/* 表名 */
	char    asTableName[MY_TAB_COLUMNS_BUFLEN_IN][31];
		/* 字段类型 */
	char    asDataType[MY_TAB_COLUMNS_BUFLEN_IN][31];
		/* 字段名 */
	char    asColumnName[MY_TAB_COLUMNS_BUFLEN_IN][31];
		/* 字段长度 */
	int     aiLen[MY_TAB_COLUMNS_BUFLEN_IN];
		/* 字段保留（小数点后几位） */
	int     aiScale[MY_TAB_COLUMNS_BUFLEN_IN];
		/* 是否可空 */
	char    asNullable[MY_TAB_COLUMNS_BUFLEN_IN][2];
		/* 字段位置 */
	int     aiColumnID[MY_TAB_COLUMNS_BUFLEN_IN];
};


/*单个结构申明*/
struct MyTabColumnsStruct{

	struct MyTabColumnsStruct *pNext;
	char    sTableName[31];		/* 表名 */
	char    sDataType[31];		/* 字段类型 */
	char    sColumnName[31];		/* 字段名 */
	int     iLen;		/* 字段长度 */
	int     iScale;		/* 字段保留（小数点后几位） */
	char    sNullable[2];		/* 是否可空 */
	int     iColumnID;		/* 字段位置 */
	/*这两个字段由程序填写*/
	int	iOffset;	/*相对于头字段的偏移*/
	int	iSeq;		/*表示第N个字段*/
	struct MyTabColumnsStruct *pHead;/*原始字段*/
	
	struct MyTabColumnsStruct *pLoadNext;
};
/*批量数据动态从MY_TAB_COLUMNS中用结构缓冲方式取数据*/
int EGetMyTabColumnsToStruct(struct MyTabColumnsStruct *p,
	struct MyTabColumnsStructIn *pSource);
int InitMyTabColumns(char sTableName[],struct MyTabColumnsStruct **pptHead);

void GetSeleColumnStr(struct MyTabColumnsStruct *pTemp,char sOutput[]);
void GetXStrSqlStmt(struct MyTabColumnsStruct *ptHead,char sTableName[],
	char statement[]);
void GetXStrTableNameStmt(struct MyTabColumnsStruct *ptLkHead,
	char sTableName[],char sCondition[],char statement[]);
int GetXStrTableName(char sTableName[],char sCondition[],char statement[]);

int InitMyTabIoColumns(char sTableName[],struct MyTabColumnsStruct **pptHead);
void GetIoMyTabColumnList(struct MyTabColumnsStruct **pptHead,
	struct MyTabColumnsStruct **ppInList,
	struct MyTabColumnsStruct **ppOutList);
void SetMyTabColumnOffset(struct MyTabColumnsStruct *ptHead);
void LinkMyTabColumnHead(struct MyTabColumnsStruct *ptHead,
	struct MyTabColumnsStruct *ptLkHead);
void GetMyTabStr(struct MyTabColumnsStruct *ptHead,char sLine[],char sOutput[]);

void GetUpdColumnStr(struct MyTabColumnsStruct *pTemp,char sOutput[]);
void GetUpdSqlStmt(struct MyTabColumnsStruct *ptHead,char sTableName[],
	char statement[]);

#ifndef XSTR_BUFLEN_UP
#define XSTR_BUFLEN_UP 	1000
#endif

struct UStrStructUp
{
	int	iCurPos;
	char	sTableName[31];
	char	sStatement[4096];
	char	asRowID[XSTR_BUFLEN_UP][19];
	char	asXData[1];
};
int EUpdateXStr2Tab(char sXStr[],char sRowID[],
        int iUpdateFlag,struct MyTabColumnsStruct *ptHead,
	struct UStrStructUp *pTarget);
struct UStrStructUp *MallocUStrStructUp(struct MyTabColumnsStruct *ptHead);


/*输出结构缓冲申明*/
struct ErrTicketStructOut{

#ifndef ERR_TICKET_BUFLEN_OUT
#define ERR_TICKET_BUFLEN_OUT		300
#endif

	struct ErrTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* (B,二进制,T文本) */
	char    asRecordType[ERR_TICKET_BUFLEN_OUT][2];
		/* 呼叫类型 */
	char    asCallType[ERR_TICKET_BUFLEN_OUT][3];
		/* 计费号码 */
	char    asMsisdn[ERR_TICKET_BUFLEN_OUT][16];
		/* 对端号码 */
	char    asOtherParty[ERR_TICKET_BUFLEN_OUT][25];
		/* 通话起始时间 */
	char    asStartTime[ERR_TICKET_BUFLEN_OUT][15];
		/* 通话时长 */
	char    asDuration[ERR_TICKET_BUFLEN_OUT][7];
		/* IMSI */
	char    asImsi[ERR_TICKET_BUFLEN_OUT][16];
		/* 交换机 */
	char    asMsc[ERR_TICKET_BUFLEN_OUT][16];
		/* 保留1(业务相关) */
	char    asReserve1[ERR_TICKET_BUFLEN_OUT][21];
		/* 保留2(业务相关) */
	char    asReserve2[ERR_TICKET_BUFLEN_OUT][21];
		/* 保留3(业务相关) */
	char    asReserve3[ERR_TICKET_BUFLEN_OUT][31];
		/* 保留4(业务相关) */
	char    asReserve4[ERR_TICKET_BUFLEN_OUT][31];
		/* 采集来源 */
	char    asOriSourceID[ERR_TICKET_BUFLEN_OUT][7];
		/* 原始文件名 */
	char    asOriFileName[ERR_TICKET_BUFLEN_OUT][41];
		/* 错误文件行号 */
	int     aiLine[ERR_TICKET_BUFLEN_OUT];
		/* 错误代码 */
	char    asErrCode[ERR_TICKET_BUFLEN_OUT][5];
		/* 回收输出文件名 */
	char    asFileName[ERR_TICKET_BUFLEN_OUT][20];
		/* 业务类型(STTVIT等) */
	char    asModule[ERR_TICKET_BUFLEN_OUT][4];
		/* 区号 */
	char    asAreaCode[ERR_TICKET_BUFLEN_OUT][6];
		/* (0:生成,1:已回收,2:已处理) */
	char    asState[ERR_TICKET_BUFLEN_OUT][2];
		/* 回收或处理时间 */
	char    asUpdateDate[ERR_TICKET_BUFLEN_OUT][15];
		/* 入库时间 */
	char    asDealDate[ERR_TICKET_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[ERR_TICKET_BUFLEN_OUT][31];
		/* 二进制话单将翻译成ASCII，文本则为原始记录 */
	char    asErrRec[ERR_TICKET_BUFLEN_OUT][2049];
};


/* 输入结构缓冲申明*/
struct ErrTicketStructIn{

#ifndef ERR_TICKET_BUFLEN_IN
#define ERR_TICKET_BUFLEN_IN		300
#endif

	struct ErrTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* (B,二进制,T文本) */
	char    asRecordType[ERR_TICKET_BUFLEN_IN][2];
		/* 呼叫类型 */
	char    asCallType[ERR_TICKET_BUFLEN_IN][3];
		/* 计费号码 */
	char    asMsisdn[ERR_TICKET_BUFLEN_IN][16];
		/* 对端号码 */
	char    asOtherParty[ERR_TICKET_BUFLEN_IN][25];
		/* 通话起始时间 */
	char    asStartTime[ERR_TICKET_BUFLEN_IN][15];
		/* 通话时长 */
	char    asDuration[ERR_TICKET_BUFLEN_IN][7];
		/* IMSI */
	char    asImsi[ERR_TICKET_BUFLEN_IN][16];
		/* 交换机 */
	char    asMsc[ERR_TICKET_BUFLEN_IN][16];
		/* 保留1(业务相关) */
	char    asReserve1[ERR_TICKET_BUFLEN_IN][21];
		/* 保留2(业务相关) */
	char    asReserve2[ERR_TICKET_BUFLEN_IN][21];
		/* 保留3(业务相关) */
	char    asReserve3[ERR_TICKET_BUFLEN_IN][31];
		/* 保留4(业务相关) */
	char    asReserve4[ERR_TICKET_BUFLEN_IN][31];
		/* 采集来源 */
	char    asOriSourceID[ERR_TICKET_BUFLEN_IN][7];
		/* 原始文件名 */
	char    asOriFileName[ERR_TICKET_BUFLEN_IN][41];
		/* 错误文件行号 */
	int     aiLine[ERR_TICKET_BUFLEN_IN];
		/* 错误代码 */
	char    asErrCode[ERR_TICKET_BUFLEN_IN][5];
		/* 回收输出文件名 */
	char    asFileName[ERR_TICKET_BUFLEN_IN][20];
		/* 业务类型(STTVIT等) */
	char    asModule[ERR_TICKET_BUFLEN_IN][4];
		/* 区号 */
	char    asAreaCode[ERR_TICKET_BUFLEN_IN][6];
		/* (0:生成,1:已回收,2:已处理) */
	char    asState[ERR_TICKET_BUFLEN_IN][2];
		/* 回收或处理时间 */
	char    asUpdateDate[ERR_TICKET_BUFLEN_IN][15];
		/* 入库时间 */
	char    asDealDate[ERR_TICKET_BUFLEN_IN][15];
		/* 文件来源 */
	char    asSourceID[ERR_TICKET_BUFLEN_IN][31];
		/* 二进制话单将翻译成ASCII，文本则为原始记录 */
	char    asErrRec[ERR_TICKET_BUFLEN_IN][2049];

	char	asRowID[ERR_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct ErrTicketStruct{

	struct ErrTicketStruct *pNext;
	char    sRecordType[2];		/* (B,二进制,T文本) */
	char    sCallType[3];		/* 呼叫类型 */
	char    sMsisdn[16];		/* 计费号码 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 通话起始时间 */
	char    sDuration[7];		/* 通话时长 */
	char    sImsi[16];		/* IMSI */
	char    sMsc[16];		/* 交换机 */
	char    sReserve1[21];		/* 保留1(业务相关) */
	char    sReserve2[21];		/* 保留2(业务相关) */
	char    sReserve3[31];		/* 保留3(业务相关) */
	char    sReserve4[31];		/* 保留4(业务相关) */
	char    sOriSourceID[7];		/* 采集来源 */
	char    sOriFileName[41];		/* 原始文件名 */
	int     iLine;		/* 错误文件行号 */
	char    sErrCode[5];		/* 错误代码 */
	char    sFileName[20];		/* 回收输出文件名 */
	char    sModule[4];		/* 业务类型(STTVIT等) */
	char    sAreaCode[6];		/* 区号 */
	char    sState[2];		/* (0:生成,1:已回收,2:已处理) */
	char    sUpdateDate[15];		/* 回收或处理时间 */
	char    sDealDate[15];		/* 入库时间 */
	char    sSourceID[31];		/* 文件来源 */
	char    sErrRec[2049];		/* 二进制话单将翻译成ASCII，文本则为原始记录 */
	char	sRowID[19];
	struct ErrTicketStruct *pLoadNext;
};



void mvitem_fmolderrticket(struct FileControlStruct *pTemp,struct ErrTicketStruct *po);
void mvitem_fmerrticket(struct FileControlStruct *pTemp,struct ErrTicketStruct *po);
int InsertErrTicket(char sFileName[],char sTableName[]);
int EInsertStructToErrTicket(struct ErrTicketStruct *p,
	int iInsertFlag,struct ErrTicketStructOut *pTarget);
/*批量数据动态从ERR_TICKET中用结构缓冲方式取数据*/
int EGetErrTicketToStruct(struct ErrTicketStruct *p,
	struct ErrTicketStructIn *pSource);


/*输出结构缓冲申明*/
struct GprsZteIntfStructOut{

#ifndef GPRS_ZTE_INTF_BUFLEN_OUT
#define GPRS_ZTE_INTF_BUFLEN_OUT		300
#endif

	struct GprsZteIntfStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* SGSN记录类型 */
	char    asRecordType[GPRS_ZTE_INTF_BUFLEN_OUT][3];
		/* 网络侧发起PDP上下文的标志 */
	char    asNiPdp[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* 手机设备的IMS */
	char    asImsi[GPRS_ZTE_INTF_BUFLEN_OUT][16];
		/* 设备号 */
	char    asEsn[GPRS_ZTE_INTF_BUFLEN_OUT][21];
		/* 手机的ISDN号 */
	char    asMsisdn[GPRS_ZTE_INTF_BUFLEN_OUT][16];
		/* 发起本次通话的日期 */
	char    asStartTime[GPRS_ZTE_INTF_BUFLEN_OUT][15];
		/* 本次通话持续的时长 */
	int     aiCallDuration[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* 发起本次通话的SGSN地址 */
	char    asSgsnAddr[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* 小区代码 */
	int     aiCellID[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* 基站代码 */
	int     aiLac[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* PDP上下文的计费标识 */
	char    asChargingID[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 本次通话的GGSN地址 */
	char    asGgsnAddr[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* APN的网络标识 */
	char    asApnNi[GPRS_ZTE_INTF_BUFLEN_OUT][64];
		/* APN的运营商标识 */
	char    asApnOi[GPRS_ZTE_INTF_BUFLEN_OUT][38];
		/* PDP类型 */
	char    asPdpType[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* 终端的PDP地址 */
	char    asServedPdpAddress[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* SGSN改变标志 */
	int     aiSgsnChange[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* 记录终止原因 */
	int     aiCloseCause[GPRS_ZTE_INTF_BUFLEN_OUT];
		/* 记录是否完整 */
	char    asIntegrityFlag[GPRS_ZTE_INTF_BUFLEN_OUT][3];
		/* 业务类型 */
	char    asServiceType[GPRS_ZTE_INTF_BUFLEN_OUT][4];
		/* 用户类型 */
	char    asUserType[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* 上行的数据流量 */
	char    asDataFlowup1[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 下行的数据流量 */
	char    asDataFlowdn1[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 计费项目 */
	char    asBillItem[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* 计费业务 */
	char    asBillService[GPRS_ZTE_INTF_BUFLEN_OUT][3];
		/* 漫游类型 */
	char    asRoamType[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* 计费号码归属地 */
	char    asHomeAreaCode[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* 计费号码漫游地 */
	char    asVisitAreaCode[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* 时长单位数 */
	char    asDurationCnt[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 流量单位数 */
	char    asFlowCnt[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 时长单位 */
	char    asDurationUnit[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 计费单位 */
	char    asBillUnit[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 基本费用 */
	char    asCfee[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 流量费用 */
	char    asFee1[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 原始话单文件名信息 */
	char    asFileName[GPRS_ZTE_INTF_BUFLEN_OUT][21];
		/* 计费号码归属城市代码 */
	char    asHomeCityCode[GPRS_ZTE_INTF_BUFLEN_OUT][6];
		/* MS网络能力 */
	char    asMsnc[GPRS_ZTE_INTF_BUFLEN_OUT][9];
		/* 变化条件定义了容器关闭的原因 */
	char    asCloseCause1[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* GGSN的代号 */
	char    asGgsn[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* APN选择模式 */
	char    asApnMode[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* 计费特性标志 */
	char    asBillFlag[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* GSN IP地址 */
	char    asGsnIp[GPRS_ZTE_INTF_BUFLEN_OUT][17];
		/* 记录序列号 */
	char    asBillSeq[GPRS_ZTE_INTF_BUFLEN_OUT][9];
		/* sgsn_plmnid */
	char    asSgsnPlmnID[GPRS_ZTE_INTF_BUFLEN_OUT][8];
		/* 附加费用 */
	char    asFee2[GPRS_ZTE_INTF_BUFLEN_OUT][11];
		/* 路由区域 */
	char    asRouteArea[GPRS_ZTE_INTF_BUFLEN_OUT][5];
		/* 错误码 */
	char    asErrCode[GPRS_ZTE_INTF_BUFLEN_OUT][16];
		/* 状态 */
	char    asState[GPRS_ZTE_INTF_BUFLEN_OUT][2];
		/* 更新日期 */
	char    asUpdateDate[GPRS_ZTE_INTF_BUFLEN_OUT][15];
		/* 处理日期 */
	char    asDealDate[GPRS_ZTE_INTF_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[GPRS_ZTE_INTF_BUFLEN_OUT][41];
};
/*单个结构申明*/
struct GprsZteIntfStruct{

	struct GprsZteIntfStruct *pNext;
	char    sRecordType[3];		/* SGSN记录类型 */
	char    sNiPdp[2];		/* 网络侧发起PDP上下文的标志 */
	char    sImsi[16];		/* 手机设备的IMS */
	char    sEsn[21];		/* 设备号 */
	char    sMsisdn[16];		/* 手机的ISDN号 */
	char    sStartTime[15];		/* 发起本次通话的日期 */
	int     iCallDuration;		/* 本次通话持续的时长 */
	char    sSgsnAddr[17];		/* 发起本次通话的SGSN地址 */
	int     iCellID;		/* 小区代码 */
	int     iLac;		/* 基站代码 */
	char    sChargingID[11];		/* PDP上下文的计费标识 */
	char    sGgsnAddr[17];		/* 本次通话的GGSN地址 */
	char    sApnNi[64];		/* APN的网络标识 */
	char    sApnOi[38];		/* APN的运营商标识 */
	char    sPdpType[2];		/* PDP类型 */
	char    sServedPdpAddress[17];		/* 终端的PDP地址 */
	int     iSgsnChange;		/* SGSN改变标志 */
	int     iCloseCause;		/* 记录终止原因 */
	char    sIntegrityFlag[3];		/* 记录是否完整 */
	char    sServiceType[4];		/* 业务类型 */
	char    sUserType[2];		/* 用户类型 */
	char    sDataFlowup1[11];		/* 上行的数据流量 */
	char    sDataFlowdn1[11];		/* 下行的数据流量 */
	char    sBillItem[2];		/* 计费项目 */
	char    sBillService[3];		/* 计费业务 */
	char    sRoamType[2];		/* 漫游类型 */
	char    sHomeAreaCode[5];		/* 计费号码归属地 */
	char    sVisitAreaCode[5];		/* 计费号码漫游地 */
	char    sDurationCnt[11];		/* 时长单位数 */
	char    sFlowCnt[11];		/* 流量单位数 */
	char    sDurationUnit[11];		/* 时长单位 */
	char    sBillUnit[11];		/* 计费单位 */
	char    sCfee[11];		/* 基本费用 */
	char    sFee1[11];		/* 流量费用 */
	char    sFileName[21];		/* 原始话单文件名信息 */
	char    sHomeCityCode[6];		/* 计费号码归属城市代码 */
	char    sMsnc[9];		/* MS网络能力 */
	char    sCloseCause1[5];		/* 变化条件定义了容器关闭的原因 */
	char    sGgsn[11];		/* GGSN的代号 */
	char    sApnMode[2];		/* APN选择模式 */
	char    sBillFlag[2];		/* 计费特性标志 */
	char    sGsnIp[17];		/* GSN IP地址 */
	char    sBillSeq[9];		/* 记录序列号 */
	char    sSgsnPlmnID[8];		/* sgsn_plmnid */
	char    sFee2[11];		/* 附加费用 */
	char    sRouteArea[5];		/* 路由区域 */
	char    sErrCode[16];		/* 错误码 */
	char    sState[2];		/* 状态 */
	char    sUpdateDate[15];		/* 更新日期 */
	char    sDealDate[15];		/* 处理日期 */
	char    sSourceID[41];		/* 文件来源 */
	struct GprsZteIntfStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FGprsZteIntfStruct{

	char    sRecordType[2];		/* SGSN记录类型 */
	char    sNiPdp[1];		/* 网络侧发起PDP上下文的标志 */
	char    sImsi[15];		/* 手机设备的IMS */
	char    sEsn[20];		/* 设备号 */
	char    sMsisdn[15];		/* 手机的ISDN号 */
	char    sStartTime[14];		/* 发起本次通话的日期 */
	char    sCallDuration[6];		/* 本次通话持续的时长 */
	char    sSgsnAddr[16];		/* 发起本次通话的SGSN地址 */
	char    sCellID[5];		/* 小区代码 */
	char    sLac[5];		/* 基站代码 */
	char    sChargingID[10];		/* PDP上下文的计费标识 */
	char    sGgsnAddr[16];		/* 本次通话的GGSN地址 */
	char    sApnNi[63];		/* APN的网络标识 */
	char    sApnOi[37];		/* APN的运营商标识 */
	char    sPdpType[1];		/* PDP类型 */
	char    sServedPdpAddress[16];		/* 终端的PDP地址 */
	char    sSgsnChange[1];		/* SGSN改变标志 */
	char    sCloseCause[2];		/* 记录终止原因 */
	char    sIntegrityFlag[2];		/* 记录是否完整 */
	char    sServiceType[3];		/* 业务类型 */
	char    sUserType[1];		/* 用户类型 */
	char    sDataFlowup1[10];		/* 上行的数据流量 */
	char    sDataFlowdn1[10];		/* 下行的数据流量 */
	char    sBillItem[1];		/* 计费项目 */
	char    sBillService[2];		/* 计费业务 */
	char    sRoamType[1];		/* 漫游类型 */
	char    sHomeAreaCode[4];		/* 计费号码归属地 */
	char    sVisitAreaCode[4];		/* 计费号码漫游地 */
	char    sDurationCnt[10];		/* 时长单位数 */
	char    sFlowCnt[10];		/* 流量单位数 */
	char    sDurationUnit[10];		/* 时长单位 */
	char    sBillUnit[10];		/* 计费单位 */
	char    sCfee[10];		/* 基本费用 */
	char    sFee1[10];		/* 流量费用 */
	char    sFileName[20];		/* 原始话单文件名信息 */
	char    sHomeCityCode[5];		/* 计费号码归属城市代码 */
	char    sMsnc[8];		/* MS网络能力 */
	char    sCloseCause1[4];		/* 变化条件定义了容器关闭的原因 */
	char    sGgsn[10];		/* GGSN的代号 */
	char    sApnMode[1];		/* APN选择模式 */
	char    sBillFlag[1];		/* 计费特性标志 */
	char    sGsnIp[16];		/* GSN IP地址 */
	char    sBillSeq[8];		/* 记录序列号 */
	char    sSgsnPlmnID[7];		/* sgsn_plmnid */
	char    sFee2[10];		/* 附加费用 */
	char    sRouteArea[4];		/* 路由区域 */
	char    sErrCode[15];		/* 错误码 */
	char    sState[1];		/* 状态 */
	char    sUpdateDate[14];		/* 更新日期 */
	char    sDealDate[14];		/* 处理日期 */
	char    sSourceID[40];		/* 文件来源 */
};
void mvitem_fmgprszteintf(struct FGprsZteIntfStruct *pi,
	struct GprsZteIntfStruct *po);
/*批量数据结构缓冲写入GPRS_ZTE_INTF*/
int EInsertStructToGprsZteIntf(struct GprsZteIntfStruct *p,
	int iInsertFlag,struct GprsZteIntfStructOut *pTarget);
int InsertGprsZteIntf(char sFileName[],char sTableName[]);

/*输出结构缓冲申明*/
struct GprsStdIntfStructOut{

#ifndef GPRS_STD_INTF_BUFLEN_OUT
#define GPRS_STD_INTF_BUFLEN_OUT		300
#endif

	struct GprsStdIntfStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 记录类型 */
	char    asRecordType[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* 漫游类型 */
	char    asRoamType[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* 手机终端的IMSI */
	char    asImsi[GPRS_STD_INTF_BUFLEN_OUT][16];
		/* 手机终端的ISDN */
	char    asMsisdn[GPRS_STD_INTF_BUFLEN_OUT][16];
		/* 本次会话起始SGSNIP地址 */
	char    asSgsn[GPRS_STD_INTF_BUFLEN_OUT][17];
		/* SGSN改变标识 */
	char    asSgsnChange[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* 本次会话GGSNIP地址 */
	char    asGgsn[GPRS_STD_INTF_BUFLEN_OUT][17];
		/* 手机终端PDPIP地址 */
	char    asServedPdpAddress[GPRS_STD_INTF_BUFLEN_OUT][17];
		/* 接入点网络标识 */
	char    asApnNi[GPRS_STD_INTF_BUFLEN_OUT][64];
		/* 接入点运营商标识 */
	char    asApnOi[GPRS_STD_INTF_BUFLEN_OUT][38];
		/* 保留字段1 */
	char    asReserv1[GPRS_STD_INTF_BUFLEN_OUT][15];
		/* 呼叫总时长 */
	int     aiCallDuration[GPRS_STD_INTF_BUFLEN_OUT];
		/* 局部类型标识符 */
	char    asPartialType[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* 中断原因 */
	char    asCloseCause[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* 本段会话连接开始时间 */
	char    asStartTime[GPRS_STD_INTF_BUFLEN_OUT][15];
		/* 网络侧呼叫标志 */
	char    asNiPdp[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* PDP上下文计费标识 */
	char    asChargingID[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* 位置区号 */
	char    asLac[GPRS_STD_INTF_BUFLEN_OUT][6];
		/* 小区标识 */
	char    asCellID[GPRS_STD_INTF_BUFLEN_OUT][6];
		/* 漫游地城市代码 */
	char    asVisitCityCode[GPRS_STD_INTF_BUFLEN_OUT][4];
		/* 保留字段2 */
	char    asReserv2[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* 漫游地表述 */
	char    asRoamRemark[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* 手机串号 */
	char    asImei[GPRS_STD_INTF_BUFLEN_OUT][20];
		/* 下行流量 */
	char    asDataFlowdn[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* 上行流量 */
	char    asDataFlowup[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* 计费项目 */
	char    asChargeItem[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* 计费取整 */
	char    asChargeUnit[GPRS_STD_INTF_BUFLEN_OUT][11];
		/* 计费业务 */
	char    asChargeOperation[GPRS_STD_INTF_BUFLEN_OUT][3];
		/* 费用 */
	int     aiTotalFee[GPRS_STD_INTF_BUFLEN_OUT];
		/* 保留字段3 */
	char    asReserv3[GPRS_STD_INTF_BUFLEN_OUT][94];
		/* 状态 */
	char    asState[GPRS_STD_INTF_BUFLEN_OUT][2];
		/* 处理日期 */
	char    asDealDate[GPRS_STD_INTF_BUFLEN_OUT][15];
		/* 文件来源 */
	char    asSourceID[GPRS_STD_INTF_BUFLEN_OUT][41];
		/* 状态日期 */
	char    asUpdateDate[GPRS_STD_INTF_BUFLEN_OUT][15];
};
/*单个结构申明*/
struct GprsStdIntfStruct{

	struct GprsStdIntfStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sRoamType[3];		/* 漫游类型 */
	char    sImsi[16];		/* 手机终端的IMSI */
	char    sMsisdn[16];		/* 手机终端的ISDN */
	char    sSgsn[17];		/* 本次会话起始SGSNIP地址 */
	char    sSgsnChange[2];		/* SGSN改变标识 */
	char    sGgsn[17];		/* 本次会话GGSNIP地址 */
	char    sServedPdpAddress[17];		/* 手机终端PDPIP地址 */
	char    sApnNi[64];		/* 接入点网络标识 */
	char    sApnOi[38];		/* 接入点运营商标识 */
	char    sReserv1[15];		/* 保留字段1 */
	int     iCallDuration;		/* 呼叫总时长 */
	char    sPartialType[2];		/* 局部类型标识符 */
	char    sCloseCause[3];		/* 中断原因 */
	char    sStartTime[15];		/* 本段会话连接开始时间 */
	char    sNiPdp[2];		/* 网络侧呼叫标志 */
	char    sChargingID[11];		/* PDP上下文计费标识 */
	char    sLac[6];		/* 位置区号 */
	char    sCellID[6];		/* 小区标识 */
	char    sVisitCityCode[4];		/* 漫游地城市代码 */
	char    sReserv2[11];		/* 保留字段2 */
	char    sRoamRemark[11];		/* 漫游地表述 */
	char    sImei[20];		/* 手机串号 */
	char    sDataFlowdn[11];		/* 下行流量 */
	char    sDataFlowup[11];		/* 上行流量 */
	char    sChargeItem[2];		/* 计费项目 */
	char    sChargeUnit[11];		/* 计费取整 */
	char    sChargeOperation[3];		/* 计费业务 */
	int     iTotalFee;		/* 费用 */
	char    sReserv3[94];		/* 保留字段3 */
	char    sState[2];		/* 状态 */
	char    sDealDate[15];		/* 处理日期 */
	char    sSourceID[41];		/* 文件来源 */
	char    sUpdateDate[15];		/* 状态日期 */
	struct GprsStdIntfStruct *pLoadNext;
};
/*单个文件结构申明*/
struct FGprsStdIntfStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sRoamType[2];		/* 漫游类型 */
	char    sImsi[15];		/* 手机终端的IMSI */
	char    sMsisdn[15];		/* 手机终端的ISDN */
	char    sSgsn[16];		/* 本次会话起始SGSNIP地址 */
	char    sSgsnChange[1];		/* SGSN改变标识 */
	char    sGgsn[16];		/* 本次会话GGSNIP地址 */
	char    sServedPdpAddress[16];		/* 手机终端PDPIP地址 */
	char    sApnNi[63];		/* 接入点网络标识 */
	char    sApnOi[37];		/* 接入点运营商标识 */
	char    sReserv1[14];		/* 保留字段1 */
	char    sCallDuration[6];		/* 呼叫总时长 */
	char    sPartialType[1];		/* 局部类型标识符 */
	char    sCloseCause[2];		/* 中断原因 */
	char    sStartTime[14];		/* 本段会话连接开始时间 */
	char    sNiPdp[1];		/* 网络侧呼叫标志 */
	char    sChargingID[10];		/* PDP上下文计费标识 */
	char    sLac[5];		/* 位置区号 */
	char    sCellID[5];		/* 小区标识 */
	char    sVisitCityCode[3];		/* 漫游地城市代码 */
	char    sReserv2[10];		/* 保留字段2 */
	char    sRoamRemark[10];		/* 漫游地表述 */
	char    sImei[19];		/* 手机串号 */
	char    sDataFlowdn[10];		/* 下行流量 */
	char    sDataFlowup[10];		/* 上行流量 */
	char    sChargeItem[1];		/* 计费项目 */
	char    sChargeUnit[10];		/* 计费取整 */
	char    sChargeOperation[2];		/* 计费业务 */
	char    sTotalFee[9];		/* 费用 */
	char    sReserv3[93];		/* 保留字段3 */
	char    sState[1];		/* 状态 */
	char    sDealDate[14];		/* 处理日期 */
	char    sSourceID[40];		/* 文件来源 */
	char    sUpdateDate[14];		/* 状态日期 */
};
void mvitem_fmgprsstdintf(struct FGprsStdIntfStruct *pi,
	struct GprsStdIntfStruct *po);
/*批量数据结构缓冲写入GPRS_STD_INTF*/
int EInsertStructToGprsStdIntf(struct GprsStdIntfStruct *p,
	int iInsertFlag,struct GprsStdIntfStructOut *pTarget);
int InsertGprsStdIntf(char sFileName[],char sTableName[]);
	
#endif
