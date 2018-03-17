#ifndef __SPZB_SUPP_H__
#define __SPZB_SUPP_H__

#include "stt_ticket.h"
#define IS_UNICOMCDMA(x)      IsDpAccNbr("unicomcdma",x)

/*单个结构申明*/
struct SmsTicketBStruct{

	struct SmsTicketBStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];	/* SP业务类型 */
	char    sCityCode[4];		/* 地市代码 */
	char	sNetTpye[2];		/*C CDMAG GSM*/
	char    sYsHdCnt[11];		/* 应收信息费的话单数量 */
	char    sYsFee[16];		/* 应收信息费 */
	char    sMoCnt[11];		/* MO_MOF数量 */
	char    sMtCnt[11];		/* MT_MTF数量 */
	char    sChkDate[11];		/* yyyymmddhh*/
	struct SmsTicketBStruct *pLoadNext;
};


/*单个结构申明*/
struct YsTicketUpHeadStruct{

	struct YsTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* 文件序列号 */
	char    sFileVersion[3];		/* 文件版本号 */
	char    sFileCreatDate[9];		/* 文件产生时间 */
	char    sProvCode[4];		/* 省分代码 */
	char    sBillingCycleID[7];		/* 帐期 */
	char    sTotalCnt[11];		/* 总记录数 */
	char    sTotalHdCnt[11];		/* 总应收信息费的话单数量 */
	char    sTotalFee[16];		/* 总应收信息费 */
	char    sTotalMoCnt[11];		/* 总MO_MOF数量 */
	char    sTotalMtCnt[11];		/* 总MT_MTF数量 */
	char    sTotalH20Cnt[11];		/* 总超过20条信息话单数量 */
	char    sTotalH20Fee[11];		/* 总超过20条信息费用 */
	char    sReserv2[19];		/* 系统保留2 */
	struct YsTicketUpHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FYsTicketUpHeadStruct{

	char    sFileSeq[4];		/* 文件序列号 */
	char    sFileVersion[2];		/* 文件版本号 */
	char    sFileCreatDate[8];		/* 文件产生时间 */
	char    sProvCode[3];		/* 省分代码 */
	char    sBillingCycleID[6];		/* 帐期 */
	char    sTotalCnt[10];		/* 总记录数 */
	char    sTotalHdCnt[10];		/* 总应收信息费的话单数量 */
	char    sTotalFee[15];		/* 总应收信息费 */
	char    sTotalMoCnt[10];		/* 总MO_MOF数量 */
	char    sTotalMtCnt[10];		/* 总MT_MTF数量 */
	char    sTotalH20Cnt[10];		/* 总超过20条信息话单数量 */
	char    sTotalH20Fee[10];		/* 总超过20条信息费用 */
	char    sReserv2[18];		/* 系统保留2 */
};




/*单个结构申明*/
struct OutYsTicketUpStruct{

	struct OutYsTicketUpStruct *pNext;
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sCityCode[4];		/* 地市代码 */
	char    sReserv1[5];		/* 系统保留1 */
	char    sReserv2[11];		/* 系统保留2 */
	char    sYsHdCnt[11];		/* 应收信息费的话单数量 */
	char    sYsFee[16];		/* 应收信息费 */
	char    sMoCnt[11];		/* MO_MOF数量 */
	char    sMtCnt[11];		/* MT_MTF数量 */
	char    sH20Cnt[11];		/* 超过20条信息话单数量 */
	char    sH20Fee[11];		/* 超过20条信息费用 */
	char    sReserv3[16];		/* 系统保留3 */
	char	sOutFileName[30];	/*输出文件名*/
	struct OutYsTicketUpStruct *pLoadNext;
};
/*单个结构申明*/
struct YsTicketUpStruct{

	struct YsTicketUpStruct *pNext;
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sCityCode[4];		/* 地市代码 */
	char    sReserv1[5];		/* 系统保留1 */
	char    sReserv2[11];		/* 系统保留2 */
	char    sYsHdCnt[11];		/* 应收信息费的话单数量 */
	char    sYsFee[16];		/* 应收信息费 */
	char    sMoCnt[11];		/* MO_MOF数量 */
	char    sMtCnt[11];		/* MT_MTF数量 */
	char    sH20Cnt[11];		/* 超过20条信息话单数量 */
	char    sH20Fee[11];		/* 超过20条信息费用 */
	char    sReserv3[16];		/* 系统保留3 */
	struct YsTicketUpStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FYsTicketUpStruct{

	char    sSpCode[5];		/* SP代码 */
	char    sSpAccNbr[12];		/* SP接入码 */
	char    sSpServiceType[2];		/* SP业务类型 */
	char    sCityCode[3];		/* 地市代码 */
	char    sReserv1[4];		/* 系统保留1 */
	char    sReserv2[10];		/* 系统保留2 */
	char    sYsHdCnt[10];		/* 应收信息费的话单数量 */
	char    sYsFee[15];		/* 应收信息费 */
	char    sMoCnt[10];		/* MO_MOF数量 */
	char    sMtCnt[10];		/* MT_MTF数量 */
	char    sH20Cnt[10];		/* 超过20条信息话单数量 */
	char    sH20Fee[10];		/* 超过20条信息费用 */
	char    sReserv3[15];		/* 系统保留3 */
};

int data_search_bintree_smsb_e(void *pValue,void*pData);
void assign_insert_bintree_smsb_e(void **ppData,void *pData);
int data_search_bintree_ysup_e(void *pValue,void*pData);
void assign_insert_bintree_ysup_e(void **ppData,void *pData);

void mvitem_mfysticketup(struct OutYsTicketUpStruct *pi,struct FYsTicketUpStruct *po);
void mvitem_mfysticketuphead(struct YsTicketUpHeadStruct *pi,
	struct FYsTicketUpHeadStruct *po);
/*单个结构申明*/
struct CxTicketDownStruct{

	struct CxTicketDownStruct *pNext;
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sCityCode[4];		/* 地市编码 */
	char    sBillingCycleID[7];		/* 应收帐期 */
	char    sReserv1[9];		/* 系统保留1 */
	char    sReserv2[11];		/* 系统保留2 */
	char    sReserv3[16];		/* 系统保留3 */
	struct CxTicketDownStruct *pLoadNext;
};


/* 输入结构缓冲申明*/
struct CxTicketDownStructIn{

#ifndef CX_TICKET_DOWN_BUFLEN_IN
#define CX_TICKET_DOWN_BUFLEN_IN		300
#endif

	struct CxTicketDownStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* SP代码 */
	char    asSpCode[CX_TICKET_DOWN_BUFLEN_IN][6];
		/* SP接入码 */
	char    asSpAccNbr[CX_TICKET_DOWN_BUFLEN_IN][13];
		/* SP业务类型 */
	char    asSpServiceType[CX_TICKET_DOWN_BUFLEN_IN][3];
		/* 地市编码 */
	char    asCityCode[CX_TICKET_DOWN_BUFLEN_IN][4];
		/* 应收帐期 */
	char    asBillingCycleID[CX_TICKET_DOWN_BUFLEN_IN][7];
		/* 系统保留1 */
	char    asReserv1[CX_TICKET_DOWN_BUFLEN_IN][9];
		/* 系统保留2 */
	char    asReserv2[CX_TICKET_DOWN_BUFLEN_IN][11];
		/* 系统保留3 */
	char    asReserv3[CX_TICKET_DOWN_BUFLEN_IN][16];
};

/*单个结构申明*/
struct RxTicketUpHeadStruct{

	struct RxTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* 文件序列号 */
	char    sFileVersion[3];		/* 文件版本号 */
	char    sFileCreatDate[9];		/* 文件产生日期 */
	char    sProvCode[4];		/* 省分代码 */
	char    sBillingCycleID[7];		/* 应收帐期 */
	char    sTotalRxCnt[11];		/* 剔除话单总记录数 */
	char    sTotalRxFee[16];		/* 剔除话单总费用 */
	char    sReserv[80];		/* 系统保留 */
	struct RxTicketUpHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FRxTicketUpHeadStruct{

	char    sFileSeq[4];		/* 文件序列号 */
	char    sFileVersion[2];		/* 文件版本号 */
	char    sFileCreatDate[8];		/* 文件产生日期 */
	char    sProvCode[3];		/* 省分代码 */
	char    sBillingCycleID[6];		/* 应收帐期 */
	char    sTotalRxCnt[10];		/* 剔除话单总记录数 */
	char    sTotalRxFee[15];		/* 剔除话单总费用 */
	char    sReserv[79];		/* 系统保留 */
};



/*单个结构申明*/
struct RxTicketUpStruct{

	struct RxTicketUpStruct *pNext;
	char    sTicketSeq[31];		/* 话单编号 */
	char    sSpCode[6];		/* SP代码 */
	char    sSpServiceCode[11];		/* SP业务代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sServiceType[3];		/* 业务类型 */
	char    sTicketType[3];		/* 话单类型 */
	char    sUserType[2];		/* 用户类型 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sVisitCityCode[4];		/* 用户归属地市代码 */
	char    sInfoFee[7];		/* 信息费费用 */
	char    sRecvTime[15];		/* 申请时间 */
	char    sDoneTime[15];		/* 处理结束时间 */
	char    sReserv1[11];		/* 系统保留1 */
	char    sRxReason[4];		/* 剔除话单原因 */
	struct RxTicketUpStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FRxTicketUpStruct{

	char    sTicketSeq[30];		/* 话单编号 */
	char    sSpCode[5];		/* SP代码 */
	char    sSpServiceCode[10];		/* SP业务代码 */
	char    sSpAccNbr[12];		/* SP接入码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sTicketType[2];		/* 话单类型 */
	char    sUserType[1];		/* 用户类型 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sVisitCityCode[3];		/* 用户归属地市代码 */
	char    sInfoFee[6];		/* 信息费费用 */
	char    sRecvTime[14];		/* 申请时间 */
	char    sDoneTime[14];		/* 处理结束时间 */
	char    sReserv1[10];		/* 系统保留1 */
	char    sRxReason[3];		/* 剔除话单原因 */
};


/*批量数据动态从CX_TICKET_DOWN中用结构缓冲方式取数据*/
int EGetCxTicketDownToStruct(struct CxTicketDownStruct *p,
	struct CxTicketDownStructIn *pSource);

int data_search_bintree_cx_down_e(void *pValue,void*pData);

void GetCxDown(struct SmsTicketStruct *pi,struct CxTicketDownStruct *po);

void mvitem_mfrxticketup(struct RxTicketUpStruct *pi,struct FRxTicketUpStruct *po);
void mvitem_mfrxticketuphead(struct RxTicketUpHeadStruct *pi,
	struct FRxTicketUpHeadStruct *po);
/*输出结构缓冲申明*/
struct SpTicketSjStructOut{

#ifndef SP_TICKET_SJ_BUFLEN_OUT
#define SP_TICKET_SJ_BUFLEN_OUT		300
#endif

	struct SpTicketSjStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asMsisdn[SP_TICKET_SJ_BUFLEN_OUT][16];
		/* 地市代码 */
	char    asHomeAreaCode[SP_TICKET_SJ_BUFLEN_OUT][6];
		/* SP代码 */
	char    asSpCode[SP_TICKET_SJ_BUFLEN_OUT][11];
		/* SP业务代码 */
	char    asSpServiceCode[SP_TICKET_SJ_BUFLEN_OUT][11];
		/* SP接入码 */
	char    asSpAccNbr[SP_TICKET_SJ_BUFLEN_OUT][13];
		/* SP业务类型 */
	char    asSpServiceType[SP_TICKET_SJ_BUFLEN_OUT][3];
		/* 实收信息费话单数量 */
	int     aiSjHdCnt[SP_TICKET_SJ_BUFLEN_OUT];
		/* SP实收费用 */
	int     aiSjFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* 退赔费 */
	int     aiTpFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* 违约扣款金额 */
	int     aiRenegeFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* 调帐金额 */
	int     aiAdjustFee[SP_TICKET_SJ_BUFLEN_OUT];
		/* 话单类型标识 */
	int     aiTicketTypeID[SP_TICKET_SJ_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceCode[SP_TICKET_SJ_BUFLEN_OUT][2];
		/* 帐单归属帐期 */
	char    asBillingCycleID[SP_TICKET_SJ_BUFLEN_OUT][7];
		/* 实收帐期 */
	char    asPayCycleID[SP_TICKET_SJ_BUFLEN_OUT][7];
		/* 帐单销账时间 */
	char    asPayTime[SP_TICKET_SJ_BUFLEN_OUT][15];
};


/*单个结构申明*/
struct SpTicketSjStruct{

	struct SpTicketSjStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sHomeAreaCode[6];		/* 地市代码 */
	char    sSpCode[11];		/* SP代码 */
	char    sSpServiceCode[11];		/* SP业务代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	int     iSjHdCnt;		/* 实收信息费话单数量 */
	int     iSjFee;		/* SP实收费用 */
	int     iTpFee;		/* 退赔费 */
	int     iRenegeFee;		/* 违约扣款金额 */
	int     iAdjustFee;		/* 调帐金额 */
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sServiceCode[2];		/* 业务类型 */
	char    sBillingCycleID[7];		/* 帐单归属帐期 */
	char    sPayCycleID[7];		/* 实收帐期 */
	char    sPayTime[15];		/* 帐单销账时间 */
	struct SpTicketSjStruct *pLoadNext;
};


/* 输入结构缓冲申明*/
struct SpTicketSjStructIn{

#ifndef SP_TICKET_SJ_BUFLEN_IN
#define SP_TICKET_SJ_BUFLEN_IN		300
#endif

	struct SpTicketSjStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[SP_TICKET_SJ_BUFLEN_IN][16];
		/* 地市代码 */
	char    asHomeAreaCode[SP_TICKET_SJ_BUFLEN_IN][6];
		/* SP代码 */
	char    asSpCode[SP_TICKET_SJ_BUFLEN_IN][11];
		/* SP业务代码 */
	char    asSpServiceCode[SP_TICKET_SJ_BUFLEN_IN][11];
		/* SP接入码 */
	char    asSpAccNbr[SP_TICKET_SJ_BUFLEN_IN][13];
		/* SP业务类型 */
	char    asSpServiceType[SP_TICKET_SJ_BUFLEN_IN][3];
		/* 实收信息费话单数量 */
	int     aiSjHdCnt[SP_TICKET_SJ_BUFLEN_IN];
		/* SP实收费用 */
	int     aiSjFee[SP_TICKET_SJ_BUFLEN_IN];
		/* 退赔费 */
	int     aiTpFee[SP_TICKET_SJ_BUFLEN_IN];
		/* 违约扣款金额 */
	int     aiRenegeFee[SP_TICKET_SJ_BUFLEN_IN];
		/* 调帐金额 */
	int     aiAdjustFee[SP_TICKET_SJ_BUFLEN_IN];
		/* 话单类型标识 */
	int     aiTicketTypeID[SP_TICKET_SJ_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceCode[SP_TICKET_SJ_BUFLEN_IN][2];
		/* 帐单归属帐期 */
	char    asBillingCycleID[SP_TICKET_SJ_BUFLEN_IN][7];
		/* 实收帐期 */
	char    asPayCycleID[SP_TICKET_SJ_BUFLEN_IN][7];
		/* 帐单销账时间 */
	char    asPayTime[SP_TICKET_SJ_BUFLEN_IN][15];
};


int EGetSpTicketSjToStruct(struct SpTicketSjStruct *p,
	struct SpTicketSjStructIn *pSource);
/*批量数据结构缓冲写入SP_TICKET_SJ*/
int EInsertStructToSpTicketSj(struct SpTicketSjStruct *p,
	int iInsertFlag,struct SpTicketSjStructOut *pTarget);

/*单个结构申明*/
struct SjTicketUpHeadStruct{

	struct SjTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* 文件序列号 */
	char    sFileVersion[3];		/* 文件版本号 */
	char    sFileCreatDate[9];		/* 文件产生时间 */
	char    sProvCode[4];		/* 省分代码 */
	char    sBillingCycleID[7];		/* 帐期 */
	char    sTotalCnt[11];		/* 总记录数 */
	char    sTotalHdCnt[11];		/* 总实收信息费的话单数量 */
	char    sTotalFee[16];		/* 总实收信息费 */
	char    sTotalTpFee[11];		/* 总退赔费 */
	char    sTotalRenegeFee[11];		/* 总违约扣款 */
	char    sTotalAdjustFee[11];		/* 总调帐金额 */
	char    sReserv3[11];		/* 系统保留3 */
	char    sReserv4[19];		/* 系统保留4 */
	struct SjTicketUpHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSjTicketUpHeadStruct{

	char    sFileSeq[4];		/* 文件序列号 */
	char    sFileVersion[2];		/* 文件版本号 */
	char    sFileCreatDate[8];		/* 文件产生时间 */
	char    sProvCode[3];		/* 省分代码 */
	char    sBillingCycleID[6];		/* 帐期 */
	char    sTotalCnt[10];		/* 总记录数 */
	char    sTotalHdCnt[10];		/* 总实收信息费的话单数量 */
	char    sTotalFee[15];		/* 总实收信息费 */
	char    sTotalTpFee[10];		/* 总退赔费 */
	char    sTotalRenegeFee[10];		/* 总违约扣款 */
	char    sTotalAdjustFee[10];		/* 总调帐金额 */
	char    sReserv3[10];		/* 系统保留3 */
	char    sReserv4[18];		/* 系统保留4 */
};


/*单个结构申明*/
struct SjTicketUpStruct{

	struct SjTicketUpStruct *pNext;
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sCityCode[4];		/* 地市代码 */
	char    sReserv1[5];		/* 系统保留1 */
	char    sReserv2[11];		/* 系统保留2 */
	char    sSjHdCnt[11];		/* 实收信息费的话单数量 */
	char    sSjFee[16];		/* 实收信息费 */
	char    sTpFee[11];		/* 退赔费 */
	char    sRenegeFee[11];		/* 违约扣款金额 */
	char    sAdjustFee[11];		/* 调帐金额 */
	char    sReserv5[11];		/* 系统保留5 */
	char    sReserv6[16];		/* 系统保留6 */
	struct SjTicketUpStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSjTicketUpStruct{

	char    sSpCode[5];		/* SP代码 */
	char    sSpAccNbr[12];		/* SP接入码 */
	char    sSpServiceType[2];		/* SP业务类型 */
	char    sCityCode[3];		/* 地市代码 */
	char    sReserv1[4];		/* 系统保留1 */
	char    sReserv2[10];		/* 系统保留2 */
	char    sSjHdCnt[10];		/* 实收信息费的话单数量 */
	char    sSjFee[15];		/* 实收信息费 */
	char    sTpFee[10];		/* 退赔费 */
	char    sRenegeFee[10];		/* 违约扣款金额 */
	char    sAdjustFee[10];		/* 调帐金额 */
	char    sReserv5[10];		/* 系统保留5 */
	char    sReserv6[15];		/* 系统保留6 */
};


int data_search_bintree_spsj_e(void *pValue,void*pData);
void assign_insert_bintree_spsj_e(void **ppData,void *pData);
void mvitem_mfsjticketup(struct SjTicketUpStruct *pi,struct FSjTicketUpStruct *po);
void mvitem_mfsjticketuphead(struct SjTicketUpHeadStruct *pi,
	struct FSjTicketUpHeadStruct *po);

/*输出结构缓冲申明*/
struct YssjChkStructOut{

#ifndef YSSJ_CHK_BUFLEN_OUT
#define YSSJ_CHK_BUFLEN_OUT		300
#endif

	struct YssjChkStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* SP代码 */
	char    asSpCode[YSSJ_CHK_BUFLEN_OUT][6];
		/* SP接入码 */
	char    asSpAccNbr[YSSJ_CHK_BUFLEN_OUT][13];
		/* SP业务类型 */
	char    asSpServiceType[YSSJ_CHK_BUFLEN_OUT][3];
		/* 地市代码 */
	char    asCityCode[YSSJ_CHK_BUFLEN_OUT][4];
		/* SP应收信息费 */
	char    asYsFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* 实收信息费 */
	char    asSjFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* 退赔费 */
	char    asTpFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* 违约扣款金额 */
	char    asRenegeFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* 调帐金额 */
	char    asAdjustFee[YSSJ_CHK_BUFLEN_OUT][13];
		/* 收回比例 */
	int     aiRate[YSSJ_CHK_BUFLEN_OUT];
		/* 归属帐期 */
	char    asBillingCycleID[YSSJ_CHK_BUFLEN_OUT][7];
};

/* 输入结构缓冲申明*/
struct YssjChkStructIn{

#ifndef YSSJ_CHK_BUFLEN_IN
#define YSSJ_CHK_BUFLEN_IN		300
#endif

	struct YssjChkStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* SP代码 */
	char    asSpCode[YSSJ_CHK_BUFLEN_IN][6];
		/* SP接入码 */
	char    asSpAccNbr[YSSJ_CHK_BUFLEN_IN][13];
		/* SP业务类型 */
	char    asSpServiceType[YSSJ_CHK_BUFLEN_IN][3];
		/* 地市代码 */
	char    asCityCode[YSSJ_CHK_BUFLEN_IN][4];
		/* SP应收信息费 */
	char    asYsFee[YSSJ_CHK_BUFLEN_IN][13];
		/* 实收信息费 */
	char    asSjFee[YSSJ_CHK_BUFLEN_IN][13];
		/* 退赔费 */
	char    asTpFee[YSSJ_CHK_BUFLEN_IN][13];
		/* 违约扣款金额 */
	char    asRenegeFee[YSSJ_CHK_BUFLEN_IN][13];
		/* 调帐金额 */
	char    asAdjustFee[YSSJ_CHK_BUFLEN_IN][13];
		/* 收回比例 */
	int     aiRate[YSSJ_CHK_BUFLEN_IN];
		/* 归属帐期 */
	char    asBillingCycleID[YSSJ_CHK_BUFLEN_IN][7];
};


/*单个结构申明*/
struct YssjChkStruct{

	struct YssjChkStruct *pNext;
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sCityCode[4];		/* 地市代码 */
	char    sYsFee[13];		/* SP应收信息费 */
	char    sSjFee[13];		/* 实收信息费 */
	char    sTpFee[13];		/* 退赔费 */
	char    sRenegeFee[13];		/* 违约扣款金额 */
	char    sAdjustFee[13];		/* 调帐金额 */
	int     iRate;		/* 收回比例 */
	char    sBillingCycleID[7];		/* 归属帐期 */
	struct YssjChkStruct *pLoadNext;
};


/*批量数据结构缓冲写入YSSJ_CHK*/
int EInsertStructToYssjChk(struct YssjChkStruct *p,
	int iInsertFlag,struct YssjChkStructOut *pTarget);

/*批量数据动态从YSSJ_CHK中用结构缓冲方式取数据*/
int EGetYssjChkToStruct(struct YssjChkStruct *p,
	struct YssjChkStructIn *pSource);
int data_search_bintree_yssjchk_e(void *pValue,void*pData);
void assign_insert_bintree_yssjchk_e(void **ppData,void *pData);
int data_search_bintree_yssjchk_s_e(void *pValue,void*pData);
void GetMxYssjChk(struct MxTicketUpStruct *pi,struct YssjChkStruct *po);
void GetTpYssjChk(struct TpTicketUpStruct *pi,struct YssjChkStruct *po);

/*单个结构申明*/
struct MxTicketUpHeadStruct{

	struct MxTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* 文件序列号 */
	char    sFileVersion[3];		/* 文件版本号 */
	char    sFileCreatDate[9];		/* 文件产生日期 */
	char    sProvCode[4];		/* 省分代码 */
	char    sBillingCycleID[7];		/* 实收帐期 */
	char    sTotalCnt[11];		/* 总记录数 */
	char    sMxFee[11];		/* 欠费总金额 */
	char    sReserv1[11];		/* 系统保留1 */
	char    sReserv2[16];		/* 系统保留2 */
	struct MxTicketUpHeadStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FMxTicketUpHeadStruct{

	char    sFileSeq[4];		/* 文件序列号 */
	char    sFileVersion[2];		/* 文件版本号 */
	char    sFileCreatDate[8];		/* 文件产生日期 */
	char    sProvCode[3];		/* 省分代码 */
	char    sBillingCycleID[6];		/* 实收帐期 */
	char    sTotalCnt[10];		/* 总记录数 */
	char    sMxFee[10];		/* 欠费总金额 */
	char    sReserv1[10];		/* 系统保留1 */
	char    sReserv2[15];		/* 系统保留2 */
};


/*单个结构申明*/
struct MxTicketUpStruct{

	struct MxTicketUpStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sVisitCityCode[4];		/* 用户归属地市代码 */
	char    sUserType[2];		/* 用户类型 */
	char    sSpCode[6];		/* SP代码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sMxFee[7];		/* 欠费金额 */
	char    sMxType[4];		/* 欠费类型 */
	char    sReserv1[9];		/* 系统保留1 */
	char    sReserv2[6];		/* 系统保留2 */
	char    sReserv3[11];		/* 系统保留3 */
	char    sReserv4[11];		/* 系统保留4 */
	struct MxTicketUpStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FMxTicketUpStruct{

	char    sMsisdn[15];		/* 用户号码 */
	char    sVisitCityCode[3];		/* 用户归属地市代码 */
	char    sUserType[1];		/* 用户类型 */
	char    sSpCode[5];		/* SP代码 */
	char    sSpServiceType[2];		/* SP业务类型 */
	char    sMxFee[6];		/* 欠费金额 */
	char    sMxType[3];		/* 欠费类型 */
	char    sReserv1[8];		/* 系统保留1 */
	char    sReserv2[5];		/* 系统保留2 */
	char    sReserv3[10];		/* 系统保留3 */
	char    sReserv4[10];		/* 系统保留4 */
};
/*输出结构缓冲申明*/
struct MxTicketUpStructOut{

#ifndef MX_TICKET_UP_BUFLEN_OUT
#define MX_TICKET_UP_BUFLEN_OUT		300
#endif

	struct MxTicketUpStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asMsisdn[MX_TICKET_UP_BUFLEN_OUT][16];
		/* 用户归属地市代码 */
	char    asVisitCityCode[MX_TICKET_UP_BUFLEN_OUT][4];
		/* 用户类型 */
	char    asUserType[MX_TICKET_UP_BUFLEN_OUT][2];
		/* SP代码 */
	char    asSpCode[MX_TICKET_UP_BUFLEN_OUT][6];
		/* SP业务类型 */
	char    asSpServiceType[MX_TICKET_UP_BUFLEN_OUT][3];
		/* 欠费金额 */
	char    asMxFee[MX_TICKET_UP_BUFLEN_OUT][7];
		/* 欠费类型 */
	char    asMxType[MX_TICKET_UP_BUFLEN_OUT][4];
		/* 系统保留1 */
	char    asReserv1[MX_TICKET_UP_BUFLEN_OUT][9];
		/* 系统保留2 */
	char    asReserv2[MX_TICKET_UP_BUFLEN_OUT][6];
		/* 系统保留3 */
	char    asReserv3[MX_TICKET_UP_BUFLEN_OUT][11];
		/* 系统保留4 */
	char    asReserv4[MX_TICKET_UP_BUFLEN_OUT][11];
};



/* 输入结构缓冲申明*/
struct MxTicketUpStructIn{

#ifndef MX_TICKET_UP_BUFLEN_IN
#define MX_TICKET_UP_BUFLEN_IN		300
#endif

	struct MxTicketUpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[MX_TICKET_UP_BUFLEN_IN][16];
		/* 用户归属地市代码 */
	char    asVisitCityCode[MX_TICKET_UP_BUFLEN_IN][4];
		/* 用户类型 */
	char    asUserType[MX_TICKET_UP_BUFLEN_IN][2];
		/* SP代码 */
	char    asSpCode[MX_TICKET_UP_BUFLEN_IN][6];
		/* SP业务类型 */
	char    asSpServiceType[MX_TICKET_UP_BUFLEN_IN][3];
		/* 欠费金额 */
	char    asMxFee[MX_TICKET_UP_BUFLEN_IN][7];
		/* 欠费类型 */
	char    asMxType[MX_TICKET_UP_BUFLEN_IN][4];
		/* 系统保留1 */
	char    asReserv1[MX_TICKET_UP_BUFLEN_IN][9];
		/* 系统保留2 */
	char    asReserv2[MX_TICKET_UP_BUFLEN_IN][6];
		/* 系统保留3 */
	char    asReserv3[MX_TICKET_UP_BUFLEN_IN][11];
		/* 系统保留4 */
	char    asReserv4[MX_TICKET_UP_BUFLEN_IN][11];
};
/*批量数据动态从MX_TICKET_UP中用结构缓冲方式取数据*/
int EGetMxTicketUpToStruct(struct MxTicketUpStruct *p,
	struct MxTicketUpStructIn *pSource);
/*批量数据结构缓冲写入MX_TICKET_UP*/
int EInsertStructToMxTicketUp(struct MxTicketUpStruct *p,
	int iInsertFlag,struct MxTicketUpStructOut *pTarget);

void mvitem_mfmxticketup(struct MxTicketUpStruct *pi,struct FMxTicketUpStruct *po);
void mvitem_mfmxticketuphead(struct MxTicketUpHeadStruct *pi,
	struct FMxTicketUpHeadStruct *po);
/*单个结构申明*/
struct TpTicketUpHeadStruct{

	struct TpTicketUpHeadStruct *pNext;
	char    sFileSeq[5];		/* 文件序列号 */
	char    sFileVersion[3];		/* 文件版本号 */
	char    sFileCreatDate[9];		/* 文件产生日期 */
	char    sProvCode[4];		/* 省分代码 */
	char    sBillingCycleID[7];		/* 帐期 */
	char    sTotalCnt[11];		/* 总记录数 */
	char    sTotalFee[11];		/* 总费用 */
	char    sReserv1[26];		/* 系统保留1 */
	struct TpTicketUpHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTpTicketUpHeadStruct{

	char    sFileSeq[4];		/* 文件序列号 */
	char    sFileVersion[2];		/* 文件版本号 */
	char    sFileCreatDate[8];		/* 文件产生日期 */
	char    sProvCode[3];		/* 省分代码 */
	char    sBillingCycleID[6];		/* 帐期 */
	char    sTotalCnt[10];		/* 总记录数 */
	char    sTotalFee[10];		/* 总费用 */
	char    sReserv1[25];		/* 系统保留1 */
};



/* 输入结构缓冲申明*/
struct TpTicketUpStructIn{

#ifndef TP_TICKET_UP_BUFLEN_IN
#define TP_TICKET_UP_BUFLEN_IN		300
#endif

	struct TpTicketUpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[TP_TICKET_UP_BUFLEN_IN][16];
		/* 用户归属地市代码 */
	char    asVisitCityCode[TP_TICKET_UP_BUFLEN_IN][4];
		/* 用户类型 */
	char    asUserType[TP_TICKET_UP_BUFLEN_IN][2];
		/* SP代码 */
	char    asSpCode[TP_TICKET_UP_BUFLEN_IN][6];
		/* SP业务类型 */
	char    asSpServiceType[TP_TICKET_UP_BUFLEN_IN][3];
		/* 退赔信息费 */
	char    asTpFee[TP_TICKET_UP_BUFLEN_IN][7];
		/* 退赔原因 */
	char    asTpReason[TP_TICKET_UP_BUFLEN_IN][4];
		/* 退赔业务发生日期 */
	char    asTpTime[TP_TICKET_UP_BUFLEN_IN][9];
		/* 系统保留1 */
	char    asReserv1[TP_TICKET_UP_BUFLEN_IN][6];
		/* 系统保留2 */
	char    asReserv2[TP_TICKET_UP_BUFLEN_IN][11];
		/* 系统保留3 */
	char    asReserv3[TP_TICKET_UP_BUFLEN_IN][11];
};


/*单个结构申明*/
struct TpTicketUpStruct{

	struct TpTicketUpStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sVisitCityCode[4];		/* 用户归属地市代码 */
	char    sUserType[2];		/* 用户类型 */
	char    sSpCode[6];		/* SP代码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sTpFee[7];		/* 退赔信息费 */
	char    sTpReason[4];		/* 退赔原因 */
	char    sTpTime[9];		/* 退赔业务发生日期 */
	char    sReserv1[6];		/* 系统保留1 */
	char    sReserv2[11];		/* 系统保留2 */
	char    sReserv3[11];		/* 系统保留3 */
	struct TpTicketUpStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTpTicketUpStruct{

	char    sMsisdn[15];		/* 用户号码 */
	char    sVisitCityCode[3];		/* 用户归属地市代码 */
	char    sUserType[1];		/* 用户类型 */
	char    sSpCode[5];		/* SP代码 */
	char    sSpServiceType[2];		/* SP业务类型 */
	char    sTpFee[6];		/* 退赔信息费 */
	char    sTpReason[3];		/* 退赔原因 */
	char    sTpTime[8];		/* 退赔业务发生日期 */
	char    sReserv1[5];		/* 系统保留1 */
	char    sReserv2[10];		/* 系统保留2 */
	char    sReserv3[10];		/* 系统保留3 */
};


/*批量数据动态从TP_TICKET_UP中用结构缓冲方式取数据*/
int EGetTpTicketUpToStruct(struct TpTicketUpStruct *p,
	struct TpTicketUpStructIn *pSource);
void mvitem_mftpticketup(struct TpTicketUpStruct *pi,struct FTpTicketUpStruct *po);
void mvitem_mftpticketuphead(struct TpTicketUpHeadStruct *pi,
	struct FTpTicketUpHeadStruct *po);

/* 输入结构缓冲申明*/
struct SpContactRelationStructIn{

#ifndef SP_CONTACT_RELATION_BUFLEN_IN
#define SP_CONTACT_RELATION_BUFLEN_IN		300
#endif

	struct SpContactRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 关系标识 */
	int     aiRelationID[SP_CONTACT_RELATION_BUFLEN_IN];
		/* 这里的合同和实际的合同有一些差异，这里的合同就是一个结算规则的意思 */
	int     aiContactID[SP_CONTACT_RELATION_BUFLEN_IN];
		/* SP代码 */
	char    asSpCode[SP_CONTACT_RELATION_BUFLEN_IN][21];
		/* SP业务代码 */
	char    asSpServiceCode[SP_CONTACT_RELATION_BUFLEN_IN][11];
		/* SP接入号码 */
	char    asSpAccNbr[SP_CONTACT_RELATION_BUFLEN_IN][13];
		/* 业务类型 */
	char    asServiceType[SP_CONTACT_RELATION_BUFLEN_IN][3];
		/* 描述 */
	char    asRemark[SP_CONTACT_RELATION_BUFLEN_IN][81];

	char	asEffDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	char	asExpDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	char	asState[SP_CONTACT_RELATION_BUFLEN_IN][4];
	char	asStateDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	char	asCreatedDate[SP_CONTACT_RELATION_BUFLEN_IN][15];
	
};


/*单个结构申明*/
struct SpContactRelationStruct{

	struct SpContactRelationStruct *pNext;
	int     iRelationID;		/* 关系标识 */
	int     iContactID;		/* 这里的合同和实际的合同有一些差异，这里的合同就是一个结算规则的意思 */
	char    sSpCode[21];		/* SP代码 */
	char    sSpServiceCode[11];		/* SP业务代码 */
	char    sSpAccNbr[13];		/* SP接入号码 */
	char    sServiceType[3];		/* 业务类型 */
	char    sRemark[81];		/* 描述 */

	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	
	struct SpContactRelationStruct *pLoadNext;
};


/*批量数据动态从SP_CONTACT_RELATION中用结构缓冲方式取数据*/
int EGetSpContactRelationToStruct(struct SpContactRelationStruct *p,
	struct SpContactRelationStructIn *pSource);
int SearchSpContactRelation(char sSpCode[],char	sSpServiceCode[],
char	sSpAccNbr[],char sStartTime[],struct SpContactRelationStruct **pptCur);

int data_search_bintree_sp_contact_relation_e(void *pValue,void*pData);

/*输出结构缓冲申明*/
struct SpAcctItemNewStructOut{

#ifndef SP_ACCT_ITEM_NEW_BUFLEN_OUT
#define SP_ACCT_ITEM_NEW_BUFLEN_OUT		300
#endif

	struct SpAcctItemNewStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asMsisdn[SP_ACCT_ITEM_NEW_BUFLEN_OUT][16];
		/* 号码归属地 */
	char    asHomeAreaCode[SP_ACCT_ITEM_NEW_BUFLEN_OUT][10];
		/* 帐单归属帐期 */
	char    asBillingCycleID[SP_ACCT_ITEM_NEW_BUFLEN_OUT][7];
		/* 实收帐期 */
	char    asPayCycleID[SP_ACCT_ITEM_NEW_BUFLEN_OUT][7];
		/* SP代码 */
	char    asSpCode[SP_ACCT_ITEM_NEW_BUFLEN_OUT][9];
		/* SP接入码 */
	char    asSpAccNbr[SP_ACCT_ITEM_NEW_BUFLEN_OUT][13];
		/* SP业务类型 */
	char    asSpServiceType[SP_ACCT_ITEM_NEW_BUFLEN_OUT][4];
		/* 话单数量 */
	int     aiRecCnt[SP_ACCT_ITEM_NEW_BUFLEN_OUT];
		/* SP实收总费用 */
	char    asCharge[SP_ACCT_ITEM_NEW_BUFLEN_OUT][11];
		/* 话单类型标识 */
	int     aiTicketTypeID[SP_ACCT_ITEM_NEW_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceCode[SP_ACCT_ITEM_NEW_BUFLEN_OUT][2];
		/* 帐单销账时间 */
	char    asPayTime[SP_ACCT_ITEM_NEW_BUFLEN_OUT][15];
};


/* 输入结构缓冲申明*/
struct SpAcctItemNewStructIn{

#ifndef SP_ACCT_ITEM_NEW_BUFLEN_IN
#define SP_ACCT_ITEM_NEW_BUFLEN_IN		300
#endif

	struct SpAcctItemNewStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[SP_ACCT_ITEM_NEW_BUFLEN_IN][16];
		/* 号码归属地 */
	char    asHomeAreaCode[SP_ACCT_ITEM_NEW_BUFLEN_IN][10];
		/* 帐单归属帐期 */
	char    asBillingCycleID[SP_ACCT_ITEM_NEW_BUFLEN_IN][7];
		/* 实收帐期 */
	char    asPayCycleID[SP_ACCT_ITEM_NEW_BUFLEN_IN][7];
		/* SP代码 */
	char    asSpCode[SP_ACCT_ITEM_NEW_BUFLEN_IN][9];
		/* SP接入码 */
	char    asSpAccNbr[SP_ACCT_ITEM_NEW_BUFLEN_IN][13];
		/* SP业务类型 */
	char    asSpServiceType[SP_ACCT_ITEM_NEW_BUFLEN_IN][4];
		/* 话单数量 */
	int     aiRecCnt[SP_ACCT_ITEM_NEW_BUFLEN_IN];
		/* SP实收总费用 */
	char    asCharge[SP_ACCT_ITEM_NEW_BUFLEN_IN][11];
		/* 话单类型标识 */
	int     aiTicketTypeID[SP_ACCT_ITEM_NEW_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceCode[SP_ACCT_ITEM_NEW_BUFLEN_IN][2];
		/* 帐单销账时间 */
	char    asPayTime[SP_ACCT_ITEM_NEW_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SpAcctItemNewStruct{

	struct SpAcctItemNewStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sHomeAreaCode[10];		/* 号码归属地 */
	char    sBillingCycleID[7];		/* 帐单归属帐期 */
	char    sPayCycleID[7];		/* 实收帐期 */
	char    sSpCode[9];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[4];		/* SP业务类型 */
	int     iRecCnt;		/* 话单数量 */
	char    sCharge[11];		/* SP实收总费用 */
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sServiceCode[2];		/* 业务类型 */
	char    sPayTime[15];		/* 帐单销账时间 */
	struct SpAcctItemNewStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSpAcctItemNewStruct{

	char    sMsisdn[15];		/* 用户号码 */
	char    sHomeAreaCode[9];		/* 号码归属地 */
	char    sBillingCycleID[6];		/* 帐单归属帐期 */
	char    sPayCycleID[6];		/* 实收帐期 */
	char    sSpCode[8];		/* SP代码 */
	char    sSpAccNbr[12];		/* SP接入码 */
	char    sSpServiceType[3];		/* SP业务类型 */
	char    sRecCnt[8];		/* 话单数量 */
	char    sCharge[10];		/* SP实收总费用 */
	char    sTicketTypeID[4];		/* 话单类型标识 */
	char    sServiceCode[1];		/* 业务类型 */
	char    sPayTime[14];		/* 帐单销账时间 */
};

/*批量数据动态从SP_ACCT_ITEM_NEW中用结构缓冲方式取数据*/
int EGetSpAcctItemNewToStruct(struct SpAcctItemNewStruct *p,
	struct SpAcctItemNewStructIn *pSource);
/*批量数据结构缓冲写入SP_ACCT_ITEM_NEW*/
int EInsertStructToSpAcctItemNew(struct SpAcctItemNewStruct *p,
	int iInsertFlag,struct SpAcctItemNewStructOut *pTarget);

int ChkSpCode(char sSpCode[],char sSpAccNbr[],char sSpServiceCode[]);

void SetHomeAreaCode(char sHomeAreaCodeIn[],char sHomeAreaCodeOut[]);
void SetSpAccNbr(struct SmsTicketStruct *pi);

/*输出结构缓冲申明*/
struct SpUserStatStructOut{

#ifndef SP_USER_STAT_BUFLEN_OUT
#define SP_USER_STAT_BUFLEN_OUT		300
#endif

	struct SpUserStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asMsisdn[SP_USER_STAT_BUFLEN_OUT][16];
		/* 用户归属地 */
	char    asHomeAreaCode[SP_USER_STAT_BUFLEN_OUT][6];
		/* 用户类型 */
	char    asUserType[SP_USER_STAT_BUFLEN_OUT][2];
		/* SP结算标识 */
	int     aiContactID[SP_USER_STAT_BUFLEN_OUT];
		/* SP代码 */
	char    asSpCode[SP_USER_STAT_BUFLEN_OUT][6];
		/* SP接入码 */
	char    asSpAccNbr[SP_USER_STAT_BUFLEN_OUT][13];
		/* SP服务代码 */
	char    asSpServiceCode[SP_USER_STAT_BUFLEN_OUT][21];
		/* 结算类型 */
	int     aiTicketTypeID[SP_USER_STAT_BUFLEN_OUT];
		/* 本地为XX */
	char    asSpServiceType[SP_USER_STAT_BUFLEN_OUT][3];
		/* SP应收通信费 */
	int     aiYsCommFee[SP_USER_STAT_BUFLEN_OUT];
		/* SP应收信息费 */
	int     aiYsInfoFee[SP_USER_STAT_BUFLEN_OUT];
		/* 实收信息费 */
	int     aiSjInfoFee[SP_USER_STAT_BUFLEN_OUT];
		/* 优惠金额 */
	int     aiDisctAmnt[SP_USER_STAT_BUFLEN_OUT];
		/* 退赔费 */
	int     aiTpFee[SP_USER_STAT_BUFLEN_OUT];
		/* 违约扣款金额 */
	int     aiRenegeFee[SP_USER_STAT_BUFLEN_OUT];
		/* 调帐金额 */
	int     aiAdjustFee[SP_USER_STAT_BUFLEN_OUT];
		/* 上行通信费 */
	int     aiUpCommFee[SP_USER_STAT_BUFLEN_OUT];
		/* 上行条数 */
	int     aiUpCnt[SP_USER_STAT_BUFLEN_OUT];
		/* 下行条数 */
	int     aiDownCnt[SP_USER_STAT_BUFLEN_OUT];
		/* 不均衡下行通信费 */
	int     aiDiffCommFee[SP_USER_STAT_BUFLEN_OUT];
		/* 欠费金额 */
	int     aiQfAmnt[SP_USER_STAT_BUFLEN_OUT];
		/* 实际坏帐率 */
	int     aiSjBadRate[SP_USER_STAT_BUFLEN_OUT];
		/* 结算支出 */
	int     aiOutFee[SP_USER_STAT_BUFLEN_OUT];
		/* 归属帐期 */
	char    asBillingCycleID[SP_USER_STAT_BUFLEN_OUT][7];
};

/* 输入结构缓冲申明*/
struct SpUserStatStructIn{

#ifndef SP_USER_STAT_BUFLEN_IN
#define SP_USER_STAT_BUFLEN_IN		300
#endif

	struct SpUserStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[SP_USER_STAT_BUFLEN_IN][16];
		/* 用户归属地 */
	char    asHomeAreaCode[SP_USER_STAT_BUFLEN_IN][6];
		/* 用户类型 */
	char    asUserType[SP_USER_STAT_BUFLEN_IN][2];
		/* SP结算标识 */
	int     aiContactID[SP_USER_STAT_BUFLEN_IN];
		/* SP代码 */
	char    asSpCode[SP_USER_STAT_BUFLEN_IN][6];
		/* SP接入码 */
	char    asSpAccNbr[SP_USER_STAT_BUFLEN_IN][13];
		/* SP服务代码 */
	char    asSpServiceCode[SP_USER_STAT_BUFLEN_IN][21];
		/* 结算类型 */
	int     aiTicketTypeID[SP_USER_STAT_BUFLEN_IN];
		/* 本地为XX */
	char    asSpServiceType[SP_USER_STAT_BUFLEN_IN][3];
		/* SP应收通信费 */
	int     aiYsCommFee[SP_USER_STAT_BUFLEN_IN];
		/* SP应收信息费 */
	int     aiYsInfoFee[SP_USER_STAT_BUFLEN_IN];
		/* 实收信息费 */
	int     aiSjInfoFee[SP_USER_STAT_BUFLEN_IN];
		/* 优惠金额 */
	int     aiDisctAmnt[SP_USER_STAT_BUFLEN_IN];
		/* 退赔费 */
	int     aiTpFee[SP_USER_STAT_BUFLEN_IN];
		/* 违约扣款金额 */
	int     aiRenegeFee[SP_USER_STAT_BUFLEN_IN];
		/* 调帐金额 */
	int     aiAdjustFee[SP_USER_STAT_BUFLEN_IN];
		/* 上行通信费 */
	int     aiUpCommFee[SP_USER_STAT_BUFLEN_IN];
		/* 上行条数 */
	int     aiUpCnt[SP_USER_STAT_BUFLEN_IN];
		/* 下行条数 */
	int     aiDownCnt[SP_USER_STAT_BUFLEN_IN];
		/* 不均衡下行通信费 */
	int     aiDiffCommFee[SP_USER_STAT_BUFLEN_IN];
		/* 欠费金额 */
	int     aiQfAmnt[SP_USER_STAT_BUFLEN_IN];
		/* 实际坏帐率 */
	int     aiSjBadRate[SP_USER_STAT_BUFLEN_IN];
		/* 结算支出 */
	int     aiOutFee[SP_USER_STAT_BUFLEN_IN];
		/* 归属帐期 */
	char    asBillingCycleID[SP_USER_STAT_BUFLEN_IN][7];
};


/*单个结构申明*/
struct SpUserStatStruct{

	struct SpUserStatStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sHomeAreaCode[6];		/* 用户归属地 */
	char    sUserType[2];		/* 用户类型 */
	int     iContactID;		/* SP结算标识 */
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceCode[21];		/* SP服务代码 */
	int     iTicketTypeID;		/* 结算类型 */
	char    sSpServiceType[3];		/* 本地为XX */
	int     iYsCommFee;		/* SP应收通信费 */
	int     iYsInfoFee;		/* SP应收信息费 */
	int     iSjInfoFee;		/* 实收信息费 */
	int     iDisctAmnt;		/* 优惠金额 */
	int     iTpFee;		/* 退赔费 */
	int     iRenegeFee;		/* 违约扣款金额 */
	int     iAdjustFee;		/* 调帐金额 */
	int     iUpCommFee;		/* 上行通信费 */
	int     iUpCnt;		/* 上行条数 */
	int     iDownCnt;		/* 下行条数 */
	int     iDiffCommFee;		/* 不均衡下行通信费 */
	int     iQfAmnt;		/* 欠费金额 */
	int     iSjBadRate;		/* 实际坏帐率 */
	int     iOutFee;		/* 结算支出 */
	char    sBillingCycleID[7];		/* 归属帐期 */
	struct SpUserStatStruct *pLoadNext;
};




/*批量数据结构缓冲写入SP_USER_STAT*/
int EInsertStructToSpUserStat(struct SpUserStatStruct *p,
	int iInsertFlag,struct SpUserStatStructOut *pTarget);


#endif

