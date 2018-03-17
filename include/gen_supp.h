#ifndef __GEN_SUPP_H__
#define __GEN_SUPP_H__

/*主要修改的结构有
TICKET_FIELD_RULE、TICKET_FIELD_VALUE、
TOLL_TARIFF、DISCT_RULE、TICKET_BASED_DISCT,EXPR_DEF*/
/*辅助结构定义在ticket_field.h和tariff_disct.h中*/

/* 输入结构缓冲申明*/
struct AcrossCellCodeStructIn{

#ifndef ACROSS_CELL_CODE_BUFLEN_IN
#define ACROSS_CELL_CODE_BUFLEN_IN		300
#endif

	struct AcrossCellCodeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];

	int	aiAcrossCodeID[ACROSS_CELL_CODE_BUFLEN_IN];
	int	aiSeqNbr[ACROSS_CELL_CODE_BUFLEN_IN];
		/* MSC编码 */
	char    asMsc[ACROSS_CELL_CODE_BUFLEN_IN][11];
		/* LAC编码 */
	char    asLac[ACROSS_CELL_CODE_BUFLEN_IN][5];
		/* CELL编码 */
	char    asCellID[ACROSS_CELL_CODE_BUFLEN_IN][5];
		/* 区号 */
	char    asAcrossAreaCode[ACROSS_CELL_CODE_BUFLEN_IN][10];
		/* 描述 */
	char    asRemark[ACROSS_CELL_CODE_BUFLEN_IN][61];
	
	char	asEffDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
	char	asExpDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
	char	asState[ACROSS_CELL_CODE_BUFLEN_IN][4];
	char	asStateDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
	char	asCreatedDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
};


/*单个结构申明*/
struct AcrossCellCodeStruct{

	struct AcrossCellCodeStruct *pNext;
	int	iAcrossCodeID;
	int	iSeqNbr;
	char    sMsc[11];		/* MSC编码 */
	char    sLac[5];		/* LAC编码 */
	char    sCellID[5];		/* CELL编码 */
	char    sAcrossAreaCode[10];		/* 区号 */
	char    sRemark[61];		/* 描述 */

	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];

	struct AcrossCellCodeStruct *pLoadNext;
};



/*对数据的取出*/
/*批量数据动态从ACROSS_CELL_CODE中用结构缓冲方式取数据*/
int EGetAcrossCellCodeToStruct(struct AcrossCellCodeStruct *p,
	struct AcrossCellCodeStructIn *pSource);
void DestroyAcrossCellCode(struct AcrossCellCodeStruct *ptHead);
int InitAcrossCellCode(struct AcrossCellCodeStruct **pptHead);

/* 输入结构缓冲申明*/
struct AreaCodeDescStructIn{

#ifndef AREA_CODE_DESC_BUFLEN_IN
#define AREA_CODE_DESC_BUFLEN_IN		300
#endif

	struct AreaCodeDescStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 区号 */
	char    asAreaCode[AREA_CODE_DESC_BUFLEN_IN][10];
		/* 省会区号 */
	char    asCapitalAreaCode[AREA_CODE_DESC_BUFLEN_IN][10];
		/* 归属省代码 */
	char    asProvinceName[AREA_CODE_DESC_BUFLEN_IN][41];
		/* 描述 */
	char    asRemark[AREA_CODE_DESC_BUFLEN_IN][61];
		/* 联通城市代码 */
	char    asCityCode[AREA_CODE_DESC_BUFLEN_IN][4];
		/* 国家代码 */
	char    asCountryCode[AREA_CODE_DESC_BUFLEN_IN][4];
	char    asType[AREA_CODE_DESC_BUFLEN_IN][2];
	char    asIpType[AREA_CODE_DESC_BUFLEN_IN][2];
	char    asTollType1[AREA_CODE_DESC_BUFLEN_IN][2];
	char    asTollType2[AREA_CODE_DESC_BUFLEN_IN][2];

};


/*单个结构申明*/
struct AreaCodeDescStruct{

	struct AreaCodeDescStruct *pNext;
	char    sAreaCode[10];		/* 区号 */
	char    sCapitalAreaCode[10];		/* 省会区号 */
	char    sProvinceName[41];		/* 归属省代码 */
	char    sRemark[61];		/* 描述 */
	char    sCityCode[4];		/* 联通城市代码 */
	char    sCountryCode[4];		/* 国家代码 */
	char    sType[2];
	char	sIpType[2];
	char	sTollType1[2];
	char	sTollType2[2];
	struct AreaCodeDescStruct *pLoadNext;
};

/*批量数据动态从AREA_CODE_DESC中用结构缓冲方式取数据*/
int EGetAreaCodeDescToStruct(struct AreaCodeDescStruct *p,
	struct AreaCodeDescStructIn *pSource);
/**对表AREA_CODE_DESC的链表释放函数**/
void DestroyAreaCodeDesc(struct AreaCodeDescStruct *ptHead);
int InitAreaCodeDesc(struct AreaCodeDescStruct **pptHead);


/*单个结构申明*/
struct T130AreaCodeStruct{

	struct T130AreaCodeStruct *pNext;
	int     iHeadID;		/* 号头标识 */
	int	iSeqNbr;
	char    sHead[12];		/* 号头 */
	int     iLen;		/* 匹配长度 */
	char    sAreaCode[10];		/* 区号 */
	char    sHeadType[2];		/* 号头类别 */	
	
	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct T130AreaCodeStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct T130AreaCodeStructIn{

#ifndef T130_AREA_CODE_BUFLEN_IN
#define T130_AREA_CODE_BUFLEN_IN		300
#endif

	struct T130AreaCodeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 号头标识 */
	int     aiHeadID[T130_AREA_CODE_BUFLEN_IN];
	int	aiSeqNbr[T130_AREA_CODE_BUFLEN_IN];
		/* 号头 */
	char    asHead[T130_AREA_CODE_BUFLEN_IN][12];
		/* 匹配长度 */
	int     aiLen[T130_AREA_CODE_BUFLEN_IN];
		/* 区号 */
	char    asAreaCode[T130_AREA_CODE_BUFLEN_IN][10];
		/* 号头类别 */
	char    asHeadType[T130_AREA_CODE_BUFLEN_IN][2];	
	
	char	asEffDate[T130_AREA_CODE_BUFLEN_IN][15];
	char	asExpDate[T130_AREA_CODE_BUFLEN_IN][15];
	char	asState[T130_AREA_CODE_BUFLEN_IN][4];
	char	asStateDate[T130_AREA_CODE_BUFLEN_IN][15];
	char	asCreatedDate[T130_AREA_CODE_BUFLEN_IN][15];
};


/*批量数据动态从T130_AREA_CODE中用结构缓冲方式取数据*/
int EGetT130AreaCodeToStruct(struct T130AreaCodeStruct *p,
	struct T130AreaCodeStructIn *pSource);
/**对表T130_AREA_CODE的链表释放函数**/
void DestroyT130AreaCode(struct T130AreaCodeStruct *ptHead);
int InitT130AreaCode(struct T130AreaCodeStruct **pptHead);


/*单个结构申明*/
struct TrunkStruct{

	struct TrunkStruct *pNext;
	int     iTrunkID;		/* 中继标识 */
	int     iSeqNbr;		/* 中继变动流水 */
	int     iTrunkTypeID;		/* 中继类别标识 */
	int     iSettCarrierID;		/* 结算对象标识 */
	char    sOppAreaCode[10];		/* 区号 */
	char    sDirection[2];		/* 方向 */
	char    sMsc[11];		/* MSC编码 */
	char    sTrunk[8];		/* 中继代号 */
	char    sTrunkName[61];		/* 中继名称 */
	
	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];

	struct TrunkStruct *pLoadNext;
};


/* 输入结构缓冲申明*/
struct TrunkStructIn{

#ifndef TRUNK_BUFLEN_IN
#define TRUNK_BUFLEN_IN		300
#endif

	struct TrunkStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 中继标识 */
	int     aiTrunkID[TRUNK_BUFLEN_IN];
		/* 中继变动流水 */
	int     aiSeqNbr[TRUNK_BUFLEN_IN];
		/* 中继类别标识 */
	int     aiTrunkTypeID[TRUNK_BUFLEN_IN];
		/* 结算对象标识 */
	int     aiSettCarrierID[TRUNK_BUFLEN_IN];
		/* 区号 */
	char    asOppAreaCode[TRUNK_BUFLEN_IN][10];
		/* 方向 */
	char    asDirection[TRUNK_BUFLEN_IN][2];
		/* MSC编码 */
	char    asMsc[TRUNK_BUFLEN_IN][11];
		/* 中继代号 */
	char    asTrunk[TRUNK_BUFLEN_IN][8];
		/* 中继名称 */
	char    asTrunkName[TRUNK_BUFLEN_IN][61];

	char	asEffDate[TRUNK_BUFLEN_IN][15];
	char	asExpDate[TRUNK_BUFLEN_IN][15];
	char	asState[TRUNK_BUFLEN_IN][4];
	char	asStateDate[TRUNK_BUFLEN_IN][15];
	char	asCreatedDate[TRUNK_BUFLEN_IN][15];
};

int EGetTrunkToStruct(struct TrunkStruct *p,
	struct TrunkStructIn *pSource);
void DestroyTrunk(struct TrunkStruct *ptHead);
int InitTrunk(struct TrunkStruct **pptHead);


/*单个结构申明*/
struct MscStruct{

	struct MscStruct *pNext;
	char    sMsc[11];		/* MSC编码 */
	char	sMscType[7];
	char    sAreaCode[10];		/* 区号 */
	char    sRemark[61];		/* 描述 */
	struct MscStruct *pLoadNext;
};
/* 输入结构缓冲申明*/
struct MscStructIn{

#ifndef MSC_BUFLEN_IN
#define MSC_BUFLEN_IN		300
#endif

	struct MscStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* MSC编码 */
	char    asMsc[MSC_BUFLEN_IN][11];
	char	asMscType[MSC_BUFLEN_IN][7];
		/* 区号 */
	char    asAreaCode[MSC_BUFLEN_IN][10];
		/* 描述 */
	char    asRemark[MSC_BUFLEN_IN][61];
};
/*批量数据动态从MSC中用结构缓冲方式取数据*/
int EGetMscToStruct(struct MscStruct *p,
	struct MscStructIn *pSource);
void DestroyMsc(struct MscStruct *ptHead);
int InitMsc(struct MscStruct **pptHead);


/*单个结构申明*/
struct TelecomCarrierStruct{

	struct TelecomCarrierStruct *pNext;
	int	iHeadID;
	int	iSeqNbr;
	char    sMsc[11];		/* 国外MSC */
	char    sImsiHead[12];		/* Imsi号头 */
	char    sCountryAreaCode[6];		/* 国家代码 */
	char    sCountryFlag[2];		/* 国家地区标识 */
	
	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	
	struct TelecomCarrierStruct *pLoadNext;
};
/* 输入结构缓冲申明*/
struct TelecomCarrierStructIn{

#ifndef TELECOM_CARRIER_BUFLEN_IN
#define TELECOM_CARRIER_BUFLEN_IN		300
#endif

	struct TelecomCarrierStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	
	int	aiHeadID[TELECOM_CARRIER_BUFLEN_IN];
	int	aiSeqNbr[TELECOM_CARRIER_BUFLEN_IN];
		/* 国外MSC */
	char    asMsc[TELECOM_CARRIER_BUFLEN_IN][11];
		/* Imsi号头 */
	char    asImsiHead[TELECOM_CARRIER_BUFLEN_IN][12];
		/* 国家代码 */
	char    asCountryAreaCode[TELECOM_CARRIER_BUFLEN_IN][6];
		/* 国家地区标识 */
	char    asCountryFlag[TELECOM_CARRIER_BUFLEN_IN][2];
	
	char	asEffDate[TELECOM_CARRIER_BUFLEN_IN][15];
	char	asExpDate[TELECOM_CARRIER_BUFLEN_IN][15];
	char	asState[TELECOM_CARRIER_BUFLEN_IN][4];
	char	asStateDate[TELECOM_CARRIER_BUFLEN_IN][15];
	char	asCreatedDate[TELECOM_CARRIER_BUFLEN_IN][15];
};
int EGetTelecomCarrierToStruct(struct TelecomCarrierStruct *p,
	struct TelecomCarrierStructIn *pSource);
void DestroyTelecomCarrier(struct TelecomCarrierStruct *ptHead);
int InitTelecomCarrier(struct TelecomCarrierStruct **pptHead);

/* 输入结构缓冲申明*/
struct TicketFieldStructIn{

#ifndef TICKET_FIELD_BUFLEN_IN
#define TICKET_FIELD_BUFLEN_IN		300
#endif

	struct TicketFieldStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 字段标识 */
	int     aiFieldID[TICKET_FIELD_BUFLEN_IN];
		/* 'T'适用于特殊话单资费,'S'适用于话单分离,'*'都适用 */
	char    asFieldType[TICKET_FIELD_BUFLEN_IN][2];
		/* 获取函数串 */
	char    asGetValueFun[TICKET_FIELD_BUFLEN_IN][61];
	
	int     aiFormatID[TICKET_FIELD_BUFLEN_IN];
	char    asDataType[TICKET_FIELD_BUFLEN_IN][2];
	char    asUseType[TICKET_FIELD_BUFLEN_IN][2];
		/* 描述 */
	char    asRemark[TICKET_FIELD_BUFLEN_IN][41];
};


/*单个结构申明*/
struct TicketFieldStruct{

	struct TicketFieldStruct *pNext;
	int     iFieldID;		/* 字段标识 */
	char    sFieldType[2];		/* 'T'适用于特殊话单资费,'S'适用于话单分离,'*'都适用 */
	char    sGetValueFun[61];		/* 获取函数串 */
	int     iFormatID;
	char    sDataType[2];
	char    sUseType[2];
	char    sRemark[41];		/* 描述 */
	char	*pValue;
	struct TicketFieldStruct *pLoadNext;
};
int EGetTicketFieldToStruct(struct TicketFieldStruct *p,
	struct TicketFieldStructIn *pSource);
void DestroyTicketField(struct TicketFieldStruct *ptHead);
int InitTicketField(struct TicketFieldStruct **pptHead);

/* 输入结构缓冲申明*/
struct TicketFieldRuleStructIn{

#ifndef TICKET_FIELD_RULE_BUFLEN_IN
#define TICKET_FIELD_RULE_BUFLEN_IN		300
#endif

	struct TicketFieldRuleStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 规则标识 */
	int     aiRuleID[TICKET_FIELD_RULE_BUFLEN_IN];
		/* 字段标识 */
	int     aiFieldID[TICKET_FIELD_RULE_BUFLEN_IN];
		/* 优先级 */
	int     aiPriority[TICKET_FIELD_RULE_BUFLEN_IN];
		/* 引用标识 */
	int     aiID[TICKET_FIELD_RULE_BUFLEN_IN];
		/* 'S' 表中的ID表示话单分离规则表的分离标识 'T'表中ID表示特殊话单公式表的TARIFF_EXPR_ID 
*/
	char    asUseType[TICKET_FIELD_RULE_BUFLEN_IN][2];
		/* 匹配规则 */
	char    asMethod[TICKET_FIELD_RULE_BUFLEN_IN][2];
		/* 描述 */
	char    asRemark[TICKET_FIELD_RULE_BUFLEN_IN][41];
};


/*单个结构申明*/
struct TicketFieldRuleStruct{

	struct TicketFieldRuleStruct *pNext;
	int     iRuleID;		/* 规则标识 */
	int     iFieldID;		/* 字段标识 */
	int     iPriority;		/* 优先级 */
	int     iID;		/* 引用标识 */
	char    sUseType[2];		
/* 'S' 表中的ID表示话单分离规则表的分离标识 'T'表中ID表示特殊话单
公式表的TARIFF_EXPR_ID */
	char    sMethod[2];		/* 匹配规则 */
	char    sRemark[41];		/* 描述 */
	struct TicketFieldRuleStruct *pLoadNext;

/*---------手工增加的一组成员开始------------------------*/
	struct TicketFieldStruct *pTicketField;
	void 	*pData;
	void *  (*GetTicketField)();	/*取匹配值函数*/
	int	(*SearchRule)(void *,void *);/*具体匹配算法*/
/*---------手工增加的一组成员结束------------------------*/
};
int EGetTicketFieldRuleToStruct(struct TicketFieldRuleStruct *p,
	struct TicketFieldRuleStructIn *pSource);
void DestroyTicketFieldRule(struct TicketFieldRuleStruct *ptHead);
int InitTicketFieldRule(struct TicketFieldRuleStruct **pptHead);

/* 输入结构缓冲申明*/
struct TicketFieldValueStructIn{

#ifndef TICKET_FIELD_VALUE_BUFLEN_IN
#define TICKET_FIELD_VALUE_BUFLEN_IN		300
#endif

	struct TicketFieldValueStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 规则序号 */
	int     aiSeq[TICKET_FIELD_VALUE_BUFLEN_IN];
		/* 规则标识 */
	int     aiRuleID[TICKET_FIELD_VALUE_BUFLEN_IN];
		/* 数值 */
	char    asValue[TICKET_FIELD_VALUE_BUFLEN_IN][41];
};


/*单个结构申明*/
struct TicketFieldValueStruct{

	struct TicketFieldValueStruct *pNext;
	int     iSeq;		/* 规则序号 */
	int     iRuleID;		/* 规则标识 */
	char    sValue[41];		/* 数值 */
	struct TicketFieldValueStruct *pLoadNext;
	
/*---------手工增加的一组成员开始------------------------*/
	int	iValueLen;	
	int	iValue;
/*---------手工增加的一组成员结束------------------------*/
	
};
int EGetTicketFieldValueToStruct(struct TicketFieldValueStruct *p,
	struct TicketFieldValueStructIn *pSource);
void DestroyTicketFieldValue(struct TicketFieldValueStruct *ptHead);
int InitTicketFieldValue(struct TicketFieldValueStruct **pptHead);

/* 输入结构缓冲申明*/
struct SplitRuleStructIn{

#ifndef SPLIT_RULE_BUFLEN_IN
#define SPLIT_RULE_BUFLEN_IN		300
#endif

	struct SplitRuleStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 分离规则标识 */
	int     aiSplitRuleID[SPLIT_RULE_BUFLEN_IN];
		/* 规则模版标识 */
	int     aiTemplateRuleID[SPLIT_RULE_BUFLEN_IN];
		/* 分离优先级 */
	int     aiPriority[SPLIT_RULE_BUFLEN_IN];
		/* 'B'批价用,'S'结算用 */
	char    asSplitType[SPLIT_RULE_BUFLEN_IN][2];
		/* 话单类别标识 */
	int     aiTicketTypeID[SPLIT_RULE_BUFLEN_IN];
		/* 0不批价 1 要批价 */
	int     aiTariffFlag[SPLIT_RULE_BUFLEN_IN];
	int     aiLay[SPLIT_RULE_BUFLEN_IN];
	char    asLeaveFlag[SPLIT_RULE_BUFLEN_IN][2];
	int     aiParentID[SPLIT_RULE_BUFLEN_IN];
		/* 描述 */
	char    asRemark[SPLIT_RULE_BUFLEN_IN][41];
};


/*单个结构申明*/
struct SplitRuleStruct{

	struct SplitRuleStruct *pNext;
	int     iSplitRuleID;		/* 分离规则标识 */
	int     iTemplateRuleID;		/* 规则模版标识 */
	int     iPriority;		/* 分离优先级 */
	char    sSplitType[2];		/* 'B'批价用,'S'结算用 */
	int     iTicketTypeID;		/* 话单类别标识 */
	int     iTariffFlag;		/* 0不批价 1 要批价 */
	int	iLay;
	char    sLeaveFlag[2];
	int	iParentID;
	char    sRemark[41];		/* 描述 */
	struct SplitRuleStruct *pChild;	 /*子节点*/
	struct SplitRuleStruct *pLoadNext;
};
int EGetSplitRuleToStruct(struct SplitRuleStruct *p,
	struct SplitRuleStructIn *pSource);
void DestroySplitRule(struct SplitRuleStruct *ptHead);
int InitSplitRule(struct SplitRuleStruct **pptHead);

/* 输入结构缓冲申明*/
struct TollTariffStructIn{

#ifndef TOLL_TARIFF_BUFLEN_IN
#define TOLL_TARIFF_BUFLEN_IN		300
#endif

	struct TollTariffStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 唯一性标识 */
	int     aiTariffID[TOLL_TARIFF_BUFLEN_IN];
	int	aiSeqNbr[TOLL_TARIFF_BUFLEN_IN];
	char	asTariffRef[TOLL_TARIFF_BUFLEN_IN][21];
		/* 资费类型 */
	char    asTollType[TOLL_TARIFF_BUFLEN_IN][3];
		/* 是对资费的划分'基本接入资费','长途资费','附加资费' */
	char    asTariffType[TOLL_TARIFF_BUFLEN_IN][3];
	char    asFieldType[TOLL_TARIFF_BUFLEN_IN][2];
	int	aiLatnID[TOLL_TARIFF_BUFLEN_IN];
		/* 话单计次的秒数 */
	int     aiSecPerCnt[TOLL_TARIFF_BUFLEN_IN];
		/* 费率 */
	int     aiRate[TOLL_TARIFF_BUFLEN_IN];
		/* 费率精确的位数 */
	int     aiRatePrecision[TOLL_TARIFF_BUFLEN_IN];
		/* 计算时精确的位数 */
	int     aiCalcPrecision[TOLL_TARIFF_BUFLEN_IN];
		/* 描述 */
	char    asRemark[TOLL_TARIFF_BUFLEN_IN][61];
		/* 生效时间 */
	char    asEffDate[TOLL_TARIFF_BUFLEN_IN][15];
		/* 失效时间 */
	char    asExpDate[TOLL_TARIFF_BUFLEN_IN][15];
	char	asState[TOLL_TARIFF_BUFLEN_IN][4];
	char	asStateDate[TOLL_TARIFF_BUFLEN_IN][15];
	char	asCreatedDate[TOLL_TARIFF_BUFLEN_IN][15];

};


/*单个结构申明*/
struct TollTariffStruct{
	struct TollTariffStruct *pNext;
	struct TollTariffStruct *pSeqNext;	/*存放TOLLTARIFF指针数组NXT*/
	int     iTariffID;		/* 唯一性标识 */
	int	iSeqNbr;
	char	sTariffRef[21];
	char    sTollType[3];		/* 资费类型 */
	char    sTariffType[3];		/* 是对资费的划分'基本接入资费','长途资费','附加资费' */
	char    sFieldType[2];		
	int	iLatnID;
	int     iSecPerCnt;		/* 话单计次的秒数 */
	int     iRate;		/* 费率 */
	int     iRatePrecision;		/* 费率精确的位数 */
	int     iCalcPrecision;		/* 计算时精确的位数 */
	char    sRemark[61];		/* 描述 */
	char    sEffDate[15];		/* 生效时间 */
	char    sExpDate[15];		/* 失效时间 */
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct TollTariffStruct *pLoadNext;
	
	int	iTollType;	
	int	iTariffType;

	time_t  tEffDate;		
	time_t  tExpDate;
	
	time_t	tBeginTime;		/*资费话单起始	
					话单时间与资费时间交集{从前} */
	time_t	tEndTime;		/* 资费话单终止 */
	
	int	iCounts;		/* 计费次数 */
	
	int	iAcctItemTypeID;	/*计费帐目类型*/
	int	iFee;			/* 话单费用*/	
	int	iDisctFee;		/* 话单优惠打折掉的费用*/
	int	iTicketItemTypeID;	/*优惠后整体体现帐目*/
	
	struct DisctRuleStruct	*pDisctRule;	
		/*该资费对应的优惠规则,InitTollTariffList函数挂上去的*/
	struct TollTariffStruct *pCurNext;	/*存放当前进程的资费列表*/
	struct TollTariffStruct *pTariffNext;	/*和pNext混合使用，用于算费*/
};
int EGetTollTariffToStruct(struct TollTariffStruct *p,
	struct TollTariffStructIn *pSource);
void DestroyTollTariff(struct TollTariffStruct *ptHead);
int InitTollTariff(struct TollTariffStruct **pptHead);

/* 输入结构缓冲申明*/
struct ExprDefStructIn{

#ifndef EXPR_DEF_BUFLEN_IN
#define EXPR_DEF_BUFLEN_IN		300
#endif

	struct ExprDefStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 公式标识 */
	int     aiExprID[EXPR_DEF_BUFLEN_IN];
		/* 公式类别 */
	char    asExprType[EXPR_DEF_BUFLEN_IN][3];
		/* 刚生成,编译过,使用中,注销 */
	char    asState[EXPR_DEF_BUFLEN_IN][4];
		/* 描述 */
	char    asRemark[EXPR_DEF_BUFLEN_IN][61];
		/* 公式表达式 */
	char    asExpr[EXPR_DEF_BUFLEN_IN][4001];
		/* 参数说明 */
	char    asComments[EXPR_DEF_BUFLEN_IN][101];
		/* 本地网标识 */
	int     aiLatnID[EXPR_DEF_BUFLEN_IN];
};


/*单个结构申明*/
struct ExprDefStruct{

	struct ExprDefStruct *pNext;
	int     iExprID;		/* 公式标识 */
	char    sExprType[3];		/* 公式类别 */
	char    sState[4];		/* 刚生成,编译过,使用中,注销 */
	char    sRemark[61];		/* 描述 */
	char    sExpr[4001];		/* 公式表达式 */
	char    sComments[101];		/* 参数说明 */
	int     iLatnID;		/* 本地网标识 */
	struct ExprDefStruct *pLoadNext;
/**修改开始**/
	int	iCompileFlag;
	int	iPriority;
	char	sParam[41];
	struct	ExprBufStruct *pExprBuf;
/**修改结束*/
	
};
int EGetExprDefToStruct(struct ExprDefStruct *p,
	struct ExprDefStructIn *pSource);
void DestroyExprDef(struct ExprDefStruct *ptHead);
int InitExprDef(struct ExprDefStruct **pptHead);

/* 输入结构缓冲申明*/
struct ExprDisctStructIn{

#ifndef EXPR_DISCT_BUFLEN_IN
#define EXPR_DISCT_BUFLEN_IN		300
#endif

	struct ExprDisctStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 公式优惠标识 */
	int     aiExprDisctID[EXPR_DISCT_BUFLEN_IN];
		/* 公式标识 */
	int     aiExprID[EXPR_DISCT_BUFLEN_IN];
		/* 优惠规则标识 */
	int     aiDisctRuleID[EXPR_DISCT_BUFLEN_IN];
		/* 优先级别，0最高先算 1其次算 */
	int     aiPriority[EXPR_DISCT_BUFLEN_IN];
		/* 描述 */
	char    asRemark[EXPR_DISCT_BUFLEN_IN][101];
		/* 公式参数 */
	char    asParam[EXPR_DISCT_BUFLEN_IN][41];
};


/*单个结构申明*/
struct ExprDisctStruct{

	struct ExprDisctStruct *pNext;
	int     iExprDisctID;		/* 公式优惠标识 */
	int     iExprID;		/* 公式标识 */
	int     iDisctRuleID;		/* 优惠规则标识 */
	int     iPriority;		/* 优先级别，0最高先算 1其次算 */
	char    sRemark[101];		/* 描述 */
	char    sParam[41];		/* 公式参数 */
	struct ExprDisctStruct *pLoadNext;
};
int EGetExprDisctToStruct(struct ExprDisctStruct *p,
	struct ExprDisctStructIn *pSource);
void DestroyExprDisct(struct ExprDisctStruct *ptHead);
int InitExprDisct(struct ExprDisctStruct **pptHead);

/* 输入结构缓冲申明*/
struct HeadCarrStructIn{

#ifndef HEAD_CARR_BUFLEN_IN
#define HEAD_CARR_BUFLEN_IN		300
#endif

	struct HeadCarrStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	
	int	aiHeadID[HEAD_CARR_BUFLEN_IN];
	int	aiSeqNbr[HEAD_CARR_BUFLEN_IN];
		/* 号头 */
	char    asHead[HEAD_CARR_BUFLEN_IN][16];
		/* 区号 */
	char    asAreaCode[HEAD_CARR_BUFLEN_IN][6];
	
	int     aiAreaID[HEAD_CARR_BUFLEN_IN];
	int     aiSettAreaID[HEAD_CARR_BUFLEN_IN];
		/* 结算对象标识 */
	int     aiSettCarrierID[HEAD_CARR_BUFLEN_IN];
		/* 类别标识 */
	int     aiTypeID[HEAD_CARR_BUFLEN_IN];
	
	char    asType[HEAD_CARR_BUFLEN_IN][2];
		/* 匹配长度 */
	int     aiLen[HEAD_CARR_BUFLEN_IN];
		/* 描述 */
	char    asRemark[HEAD_CARR_BUFLEN_IN][61];
	
	char	asEffDate[HEAD_CARR_BUFLEN_IN][15];
	char	asExpDate[HEAD_CARR_BUFLEN_IN][15];
	char	asState[HEAD_CARR_BUFLEN_IN][4];
	char	asStateDate[HEAD_CARR_BUFLEN_IN][15];
	char	asCreatedDate[HEAD_CARR_BUFLEN_IN][15];
};


/*单个结构申明*/
struct HeadCarrStruct{

	struct HeadCarrStruct *pNext;
	
	int	iHeadID;
	int	iSeqNbr;

	char    sHead[16];		/* 号头 */
	char    sAreaCode[6];		/* 区号 */
	int	iAreaID;		
	int	iSettAreaID;
	int     iSettCarrierID;		/* 结算对象标识 */
	int     iTypeID;		/* 类别标识 */
	char	sType[2];
	int     iLen;		/* 匹配长度 */	
	char    sRemark[61];		/* 描述 */

	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];

	struct HeadCarrStruct *pLoadNext;
};

int EGetHeadCarrToStruct(struct HeadCarrStruct *p,
	struct HeadCarrStructIn *pSource);
void DestroyHeadCarr(struct HeadCarrStruct *ptHead);
int InitHeadCarr(struct HeadCarrStruct **pptHead);

/* 输入结构缓冲申明*/
struct TicketBasedDisctStructIn{

#ifndef TICKET_BASED_DISCT_BUFLEN_IN
#define TICKET_BASED_DISCT_BUFLEN_IN		300
#endif

	struct TicketBasedDisctStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 详单优惠标识 */
	int     aiTicketBasedDisctID[TICKET_BASED_DISCT_BUFLEN_IN];
		/* 优惠规则标识 */
	int     aiDisctRuleID[TICKET_BASED_DISCT_BUFLEN_IN];
		/* 时间单位 */
	char    asUnit[TICKET_BASED_DISCT_BUFLEN_IN][3];
		/* 周期偏移天数 */
	int     aiOffset1[TICKET_BASED_DISCT_BUFLEN_IN];
		/* 持续天数 */
	int     aiDuration1[TICKET_BASED_DISCT_BUFLEN_IN];
		/* 每日偏移秒 */
	char    asOffset2[TICKET_BASED_DISCT_BUFLEN_IN][7];
		/* 持续秒数 */
	int     aiDuration2[TICKET_BASED_DISCT_BUFLEN_IN];
		/* 优惠方法 */
	char    asMethod[TICKET_BASED_DISCT_BUFLEN_IN][3];
		/* 优惠比率 */
	int     aiRate[TICKET_BASED_DISCT_BUFLEN_IN];
		/* 优先级别 */
	int     aiPriority[TICKET_BASED_DISCT_BUFLEN_IN];
		/* 生效时间 */
	char    asEffDate[TICKET_BASED_DISCT_BUFLEN_IN][15];
		/* 失效时间 */
	char    asExpDate[TICKET_BASED_DISCT_BUFLEN_IN][15];
};


/*单个结构申明*/
struct TicketBasedDisctStruct{

	struct TicketBasedDisctStruct *pNext;
	int     iTicketBasedDisctID;		/* 详单优惠标识 */
	int     iDisctRuleID;		/* 优惠规则标识 */
	char    sUnit[3];		/* 时间单位 */
	int     iOffset1;		/* 周期偏移天数 */
	int     iDuration1;		/* 持续天数 */
	char    sOffset2[7];		/* 每日偏移秒 */
	int     iDuration2;		/* 持续秒数 */
	char    sMethod[3];		/* 优惠方法 */
	int     iRate;		/* 优惠比率 */
	int     iPriority;		/* 优先级别 */

	char    sEffDate[15];		/* 生效时间 */
	char    sExpDate[15];		/* 失效时间 */

	struct TicketBasedDisctStruct *pLoadNext;

/***修改开始*******/	
	int	iMethod;
	int	iUnit;				/* 只支持周和日 */
	time_t	tBaseTime;			/* 基准日期 */
	
	int	iBeginDate;			/* 周期内日开始秒数 */
	int	iEndDate;			/* 周期内日终止秒数 */	
	
	int	iBeginTime;			/* 日内有效开始秒数 */
	int	iEndTime;			/* 日内有效终止秒数 */

	time_t  tEffDate;			/*生效开始时间*/
	time_t  tExpDate;			/*生效结束时间*/
	
	time_t  tYear;
	int	iUnitOri;
/***修改结束**/

};
int EGetTicketBasedDisctToStruct(struct TicketBasedDisctStruct *p,
	struct TicketBasedDisctStructIn *pSource);
void DestroyTicketBasedDisct(struct TicketBasedDisctStruct *ptHead);
int InitTicketBasedDisct(struct TicketBasedDisctStruct **pptHead);


/* 输入结构缓冲申明*/
struct TicketTypeStructIn{

#ifndef TICKET_TYPE_BUFLEN_IN
#define TICKET_TYPE_BUFLEN_IN		300
#endif

	struct TicketTypeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类别标识 */
	int     aiTicketTypeID[TICKET_TYPE_BUFLEN_IN];
	char	asTariffType[TICKET_TYPE_BUFLEN_IN][3];
	char	asFeeType[TICKET_TYPE_BUFLEN_IN][5];
		/* 结算对象标识 */
	int     aiSettCarrierID[TICKET_TYPE_BUFLEN_IN];
		/* 分离类别 */
	char    asSplitType[TICKET_TYPE_BUFLEN_IN][2];
	char    asServType[TICKET_TYPE_BUFLEN_IN][5];
	int	aiFormatID[TICKET_TYPE_BUFLEN_IN];
		/* 定义了关于费率最细呼叫类别,和电信服务类别、承载电信服务、相对位置、呼叫大类有关 */
	char    asRemark[TICKET_TYPE_BUFLEN_IN][81];
};


/*单个结构申明*/
struct TicketTypeStruct{

	struct TicketTypeStruct *pNext;
	int     iTicketTypeID;		/* 话单类别标识 */
	char	sTariffType[3];
	char	sFeeType[5];
	int     iSettCarrierID;		/* 结算对象标识 */
	char    sSplitType[2];		/* 分离类别 */
	char	sServType[5];
	int	iFormatID;
	char    sRemark[81];		/* 定义了关于费率最细呼叫类别,和电信服务类别、承载电信服务、相对
位置、呼叫大类有关 */
	struct TicketTypeStruct *pLoadNext;
};
int EGetTicketTypeToStruct(struct TicketTypeStruct *p,
	struct TicketTypeStructIn *pSource);
void DestroyTicketType(struct TicketTypeStruct *ptHead);
int InitTicketType(struct TicketTypeStruct **pptHead);

/* 输入结构缓冲申明*/
struct TicketTypeTariffStructIn{

#ifndef TICKET_TYPE_TARIFF_BUFLEN_IN
#define TICKET_TYPE_TARIFF_BUFLEN_IN		300
#endif

	struct TicketTypeTariffStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单类别标识 */
	int     aiTicketTypeID[TICKET_TYPE_TARIFF_BUFLEN_IN];
		/* 唯一性标识 */
	int     aiTariffID[TICKET_TYPE_TARIFF_BUFLEN_IN];
		/* 关系状态 */
	char    asState[TICKET_TYPE_TARIFF_BUFLEN_IN][4];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[TICKET_TYPE_TARIFF_BUFLEN_IN];
};


/*单个结构申明*/
struct TicketTypeTariffStruct{

	struct TicketTypeTariffStruct *pNext;
	int     iTicketTypeID;		/* 话单类别标识 */
	int     iTariffID;		/* 唯一性标识 */
	char    sState[4];		/* 关系状态 */
	int     iAcctItemTypeID;		/* 帐目类型标识 */
	struct TicketTypeTariffStruct *pLoadNext;
};
int EGetTicketTypeTariffToStruct(struct TicketTypeTariffStruct *p,
	struct TicketTypeTariffStructIn *pSource);
void DestroyTicketTypeTariff(struct TicketTypeTariffStruct *ptHead);
int InitTicketTypeTariff(struct TicketTypeTariffStruct **pptHead);

/* 输入结构缓冲申明*/
struct TimeSpanDisctStructIn{

#ifndef TIME_SPAN_DISCT_BUFLEN_IN
#define TIME_SPAN_DISCT_BUFLEN_IN		300
#endif

	struct TimeSpanDisctStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 分阶段优惠标识 */
	int     aiTimeSpanDisctID[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 优惠规则标识 */
	int     aiDisctRuleID[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 优先级别 */
	int     aiPriority[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 折扣作用开始数 */
	int     aiOffset1[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 折扣作用持续分钟 */
	int     aiDuration1[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 作用时间内周期 */
	int     aiCycle[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 作用时间内偏移分钟 */
	int     aiOffset2[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 周期持续时长，单位分钟 */
	int     aiDuration2[TIME_SPAN_DISCT_BUFLEN_IN];
		/* 优惠方法，如固定费率，折扣。 */
	char    asMethod[TIME_SPAN_DISCT_BUFLEN_IN][3];
		/* 比率 */
	int     aiRate[TIME_SPAN_DISCT_BUFLEN_IN];
};


/*单个结构申明*/
struct TimeSpanDisctStruct{

	struct TimeSpanDisctStruct *pNext;
	int     iTimeSpanDisctID;		/* 分阶段优惠标识 */
	int     iDisctRuleID;		/* 优惠规则标识 */
	int     iPriority;		/* 优先级别 */
	int     iOffset1;		/* 折扣作用开始数 */
	int     iDuration1;		/* 折扣作用持续分钟 */
	int     iCycle;		/* 作用时间内周期 */
	int     iOffset2;		/* 作用时间内偏移分钟 */
	int     iDuration2;		/* 周期持续时长，单位分钟 */
	char    sMethod[3];		/* 优惠方法，如固定费率，折扣。 */
	int     iRate;		/* 比率 */
	struct TimeSpanDisctStruct *pLoadNext;
};
int EGetTimeSpanDisctToStruct(struct TimeSpanDisctStruct *p,
	struct TimeSpanDisctStructIn *pSource);
void DestroyTimeSpanDisct(struct TimeSpanDisctStruct *ptHead);
int InitTimeSpanDisct(struct TimeSpanDisctStruct **pptHead);

/* 输入结构缓冲申明*/
struct DisctRuleStructIn{

#ifndef DISCT_RULE_BUFLEN_IN
#define DISCT_RULE_BUFLEN_IN		300
#endif

	struct DisctRuleStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 优惠规则标识 */
	int     aiDisctRuleID[DISCT_RULE_BUFLEN_IN];
		/* 00话单级分阶段优惠、01话单级时段优惠、10帐单级一般优惠、  11帐单总量优惠 */
	char    asDisctType[DISCT_RULE_BUFLEN_IN][3];
		/* 优惠来源标识，如优惠规则来自的优惠协议标识、优惠文件标识等。 */
	int	aiTariffID[DISCT_RULE_BUFLEN_IN];
	int	aiSeqNbr[DISCT_RULE_BUFLEN_IN];
	int     aiSourceID[DISCT_RULE_BUFLEN_IN];
		/* 本地网标识 */
	int     aiLatnID[DISCT_RULE_BUFLEN_IN];
		/* 优先级 */
	int     aiPriority[DISCT_RULE_BUFLEN_IN];
		/* 生效时间 */
	char    asEffDate[DISCT_RULE_BUFLEN_IN][15];
		/* 失效时间 */
	char    asExpDate[DISCT_RULE_BUFLEN_IN][15];
		/* 规则名称 */
	char    asRuleName[DISCT_RULE_BUFLEN_IN][41];
};


/*单个结构申明*/
struct DisctRuleStruct{

	struct DisctRuleStruct *pNext;	/*用于优惠*/
	int     iDisctRuleID;		/* 优惠规则标识 */
	char    sDisctType[3];		/* 00话单级分阶段优惠、01话单级时段优惠、10帐单级一般优惠、  11帐单总量优惠 */
	int	iTariffID;		/* 资费标识，新增*/
	int	iSeqNbr;
	int     iSourceID;		/* 优惠来源标识，如优惠规则来自的优惠协议标识、优惠文件标识等。 */
	int     iLatnID;		/* 本地网标识 */
	int     iPriority;		/* 优先级 */
	char    sEffDate[15];		/* 生效时间 */
	char    sExpDate[15];		/* 失效时间 */
	char    sRuleName[41];		/* 规则名称 */
	struct DisctRuleStruct *pLoadNext;
	
	int	iDisctType;	
	time_t	tEffDate;
	time_t	tExpDate;
	
	int     iSecPerCnt;		/* 话单计次的秒数 */
	int	iCounts;		/* 次数*/
	int     iRate;			/* 费率 */
	int     iRatePrecision;		/* 费率精确的位数 */
	int     iCalcPrecision;		/* 计算时精确的位数 */
	int	iFee;			/* 话单费用*/	
	int	iDisctFee;		/* 话单优惠打折掉的费用*/
	
	time_t	tBeginTime;
	time_t	tEndTime;
	
	void (*Disct)(struct DisctRuleStruct *);
	
	int	iMutex;		/*0表示没有被排斥，1表示被排斥*/
	struct	DisctRuleMutexStruct *pMutex;
	void	*pDisct;
	struct DisctRuleStruct *pTariffNext;/*挂在TOLL_TARIFF下的东西*/
	struct DisctRuleStruct *pCurNext;/*存放当前进程的优惠规则链表*/
};



int EGetDisctRuleToStruct(struct DisctRuleStruct *p,
	struct DisctRuleStructIn *pSource);
void DestroyDisctRule(struct DisctRuleStruct *ptHead);
int InitDisctRule(struct DisctRuleStruct **pptHead);

/* 输入结构缓冲申明*/
struct CellCodeStructIn{

#ifndef CELL_CODE_BUFLEN_IN
#define CELL_CODE_BUFLEN_IN		300
#endif

	struct CellCodeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int	aiCellCodeID[CELL_CODE_BUFLEN_IN];
	int	aiSeqNbr[CELL_CODE_BUFLEN_IN];
		/* MSC编码 */
	char    asMsc[CELL_CODE_BUFLEN_IN][11];
		/* LAC编码 */
	char    asLac[CELL_CODE_BUFLEN_IN][5];
		/* CELL编码 */
	char    asCellID[CELL_CODE_BUFLEN_IN][5];
		/* 归属区号 */
	char    asAreaCode[CELL_CODE_BUFLEN_IN][6];
		/* 描述 */
	char    asRemark[CELL_CODE_BUFLEN_IN][61];
	
	char	asEffDate[CELL_CODE_BUFLEN_IN][15];
	char	asExpDate[CELL_CODE_BUFLEN_IN][15];
	char	asState[CELL_CODE_BUFLEN_IN][4];
	char	asStateDate[CELL_CODE_BUFLEN_IN][15];
	char	asCreatedDate[CELL_CODE_BUFLEN_IN][15];
};


/*单个结构申明*/
struct CellCodeStruct{

	struct CellCodeStruct *pNext;
	int	iCellCodeID;
	int	iSeqNbr;
	char    sMsc[11];		/* MSC编码 */
	char    sLac[5];		/* LAC编码 */
	char    sCellID[5];		/* CELL编码 */
	char    sAreaCode[6];		/* 归属区号 */
	char    sRemark[61];		/* 描述 */
	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct CellCodeStruct *pLoadNext;
};
int EGetCellCodeToStruct(struct CellCodeStruct *p,
	struct CellCodeStructIn *pSource);
void DestroyCellCode(struct CellCodeStruct *ptHead);
int InitCellCode(struct CellCodeStruct **pptHead);

/* 输入结构缓冲申明*/
struct DisctRuleMutexStructIn{

#ifndef DISCT_RULE_MUTEX_BUFLEN_IN
#define DISCT_RULE_MUTEX_BUFLEN_IN		300
#endif

	struct DisctRuleMutexStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 优惠规则标识 */
	int     aiDisctRuleID[DISCT_RULE_MUTEX_BUFLEN_IN];
		/* 排斥优惠规则 */
	int     aiExcludeDisctRuleID[DISCT_RULE_MUTEX_BUFLEN_IN];
};


/*单个结构申明*/
struct DisctRuleMutexStruct{

	struct DisctRuleMutexStruct *pNext;
	int     iDisctRuleID;		/* 优惠规则标识 */
	int     iExcludeDisctRuleID;		/* 排斥优惠规则 */
	struct DisctRuleMutexStruct *pLoadNext;
};
int EGetDisctRuleMutexToStruct(struct DisctRuleMutexStruct *p,
	struct DisctRuleMutexStructIn *pSource);
void DestroyDisctRuleMutex(struct DisctRuleMutexStruct *ptHead);
int InitDisctRuleMutex(struct DisctRuleMutexStruct **pptHead);


/* 输入结构缓冲申明*/
struct DispParamStructIn{

#ifndef DISP_PARAM_BUFLEN_IN
#define DISP_PARAM_BUFLEN_IN		300
#endif

	struct DispParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 组号 */
	int     aiGroupID[DISP_PARAM_BUFLEN_IN];
		/* 发送源目录 */
	char    asSourcePath[DISP_PARAM_BUFLEN_IN][81];
	char	asFilter[DISP_PARAM_BUFLEN_IN][21];
		/* 发送目的目录1 */
	char    asDestPath1[DISP_PARAM_BUFLEN_IN][81];
		/* 发送目的目录2 */
	char    asDestPath2[DISP_PARAM_BUFLEN_IN][81];
		/* 发送目的目录3 */
	char    asDestPath3[DISP_PARAM_BUFLEN_IN][81];
		/* 发送目的目录4 */
	char    asDestPath4[DISP_PARAM_BUFLEN_IN][81];
		/* 启动停状态 */
	char    asState[DISP_PARAM_BUFLEN_IN][2];
};


/*单个结构申明*/
struct DispParamStruct{

	struct DispParamStruct *pNext;
	int     iGroupID;		/* 组号 */
	char    sSourcePath[81];	/* 发送源目录 */
	char	sFilter[21];
	char    sDestPath1[81];		/* 发送目的目录1 */
	char    sDestPath2[81];		/* 发送目的目录2 */
	char    sDestPath3[81];		/* 发送目的目录3 */
	char    sDestPath4[81];		/* 发送目的目录4 */
	char    sState[2];		/* 启动停状态 */
	struct DispParamStruct *pLoadNext;
};

/*批量数据动态从DISP_PARAM中用结构缓冲方式取数据*/
int EGetDispParamToStruct(struct DispParamStruct *p,
	struct DispParamStructIn *pSource);
/**对表DISP_PARAM的链表释放函数**/
void DestroyDispParam(struct DispParamStruct *ptHead);
int InitDispParam(struct DispParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct InstParamStructIn{

#ifndef INST_PARAM_BUFLEN_IN
#define INST_PARAM_BUFLEN_IN		300
#endif

	struct InstParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[INST_PARAM_BUFLEN_IN][7];
		/* 群组标识 */
	int     aiGroupID[INST_PARAM_BUFLEN_IN];
		/* 类型 */
	char    asFileType[INST_PARAM_BUFLEN_IN][6];
	char    asOperType[INST_PARAM_BUFLEN_IN][4];
		/* 日期规则 */
	char    asDateRule[INST_PARAM_BUFLEN_IN][13];
		/* 源路径 */
	char    asSourcePath[INST_PARAM_BUFLEN_IN][81];
		/* 匹配规则 */
	char    asFilter[INST_PARAM_BUFLEN_IN][21];
		/* 备份路径 */
	char    asBackPath[INST_PARAM_BUFLEN_IN][81];
		/* 数据归属地区 */
	char    asBelongCode[INST_PARAM_BUFLEN_IN][6];
		/* 模块 */
	char    asModule[INST_PARAM_BUFLEN_IN][4];
		/* 启停状态 */
	char    asState[INST_PARAM_BUFLEN_IN][2];
		/* 应用标识 */
	char    asAppID[INST_PARAM_BUFLEN_IN][11];
		/* 环节标识 */
	int     aiTacheID[INST_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct InstParamStruct{

	struct InstParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	int     iGroupID;		/* 群组标识 */
	char    sFileType[6];		/* 类型 */
	char    sOperType[4];
	char    sDateRule[13];		/* 日期规则 */
	char    sSourcePath[81];		/* 源路径 */
	char    sFilter[21];		/* 匹配规则 */
	char    sBackPath[81];		/* 备份路径 */
	char    sBelongCode[6];		/* 数据归属地区 */
	char    sModule[4];		/* 模块 */
	char    sState[2];		/* 启停状态 */
	char    sAppID[11];		/* 应用标识 */
	int     iTacheID;		/* 环节标识 */
	struct InstParamStruct *pLoadNext;
};

/*批量数据动态从INST_PARAM中用结构缓冲方式取数据*/
int EGetInstParamToStruct(struct InstParamStruct *p,
	struct InstParamStructIn *pSource);
/**对表INST_PARAM的链表释放函数**/
void DestroyInstParam(struct InstParamStruct *ptHead);
int InitInstParam(struct InstParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct PickParamStructIn{

#ifndef PICK_PARAM_BUFLEN_IN
#define PICK_PARAM_BUFLEN_IN		300
#endif

	struct PickParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[PICK_PARAM_BUFLEN_IN][7];
		/* 群组标识 */
	int     aiGroupID[PICK_PARAM_BUFLEN_IN];
		/* 对端路径 */
	char    asOppPath[PICK_PARAM_BUFLEN_IN][81];
		/* 对端备份路径 */
	char    asOppBkupPath[PICK_PARAM_BUFLEN_IN][81];
		/* 本端路径 */
	char    asLocalPath[PICK_PARAM_BUFLEN_IN][81];
		/* 主机IP */
	char    asIp[PICK_PARAM_BUFLEN_IN][17];
		/* 用户名 */
	char    asUserName[PICK_PARAM_BUFLEN_IN][21];
		/* 口令 */
	char    asPasswd[PICK_PARAM_BUFLEN_IN][21];
		/* 匹配模式 */
	char    asFilter[PICK_PARAM_BUFLEN_IN][21];
		/* 原始序号偏移 */
	int     aiSeqOff[PICK_PARAM_BUFLEN_IN];
		/* 原始序号长度 */
	int     aiSeqLen[PICK_PARAM_BUFLEN_IN];
		/* 删除类型 */
	char    asDeleteType[PICK_PARAM_BUFLEN_IN][2];
	int     aiChkDays[PICK_PARAM_BUFLEN_IN];
		/* 输出格式类型 */
	char    asOutType[PICK_PARAM_BUFLEN_IN][6];
		/* 状态 */
	char    asState[PICK_PARAM_BUFLEN_IN][2];
		/* 应用标识 */
	char    asAppID[PICK_PARAM_BUFLEN_IN][11];
		/* 环节标识 */
	int     aiTacheID[PICK_PARAM_BUFLEN_IN];
	
};


/*单个结构申明*/
struct PickParamStruct{

	struct PickParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	int     iGroupID;		/* 群组标识 */
	char    sOppPath[81];		/* 对端路径 */
	char    sOppBkupPath[81];		/* 对端备份路径 */
	char    sLocalPath[81];		/* 本端路径 */
	char    sIp[17];		/* 主机IP */
	char    sUserName[21];		/* 用户名 */
	char    sPasswd[21];		/* 口令 */
	char    sFilter[21];		/* 匹配模式 */
	int     iSeqOff;		/* 原始序号偏移 */
	int     iSeqLen;		/* 原始序号长度 */
	char    sDeleteType[2];		/* 删除类型 */
	int	iChkDays;
	char    sOutType[6];		/* 输出格式类型 */
	char	sState[2];
	char    sAppID[11];		/* 应用标识 */
	int     iTacheID;		/* 环节标识 */
	struct PickParamStruct *pLoadNext;
};


/*批量数据动态从PICK_PARAM中用结构缓冲方式取数据*/
int EGetPickParamToStruct(struct PickParamStruct *p,
	struct PickParamStructIn *pSource);
/**对表PICK_PARAM的链表释放函数**/
void DestroyPickParam(struct PickParamStruct *ptHead);
int InitPickParam(struct PickParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct PrepParamStructIn{

#ifndef PREP_PARAM_BUFLEN_IN
#define PREP_PARAM_BUFLEN_IN		300
#endif

	struct PrepParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[PREP_PARAM_BUFLEN_IN][7];
		/* 群组标识 */
	int     aiGroupID[PREP_PARAM_BUFLEN_IN];
		/* 交换机标识 */
	char    asMsc[PREP_PARAM_BUFLEN_IN][16];
		/* 区号 */
	char    asAreaCode[PREP_PARAM_BUFLEN_IN][6];
		/* 公式文件 */
	char    asExprFile[PREP_PARAM_BUFLEN_IN][81];
		/* 模式 */
	char    asFilter[PREP_PARAM_BUFLEN_IN][21];
		/* 源路径 */
	char    asSourcePath[PREP_PARAM_BUFLEN_IN][81];
		/* 备份路径 */
	char    asBackPath[PREP_PARAM_BUFLEN_IN][81];
		/* 正常路径 */
	char    asNormalPath[PREP_PARAM_BUFLEN_IN][81];
		/* 模块 */
	char    asModule[PREP_PARAM_BUFLEN_IN][4];
	
	char    asSplit[PREP_PARAM_BUFLEN_IN][11];
	int     aiStartPos[PREP_PARAM_BUFLEN_IN];
	int     aiKeyLen[PREP_PARAM_BUFLEN_IN];
	char    asChkMod[PREP_PARAM_BUFLEN_IN][4];

	char	asUserType[PREP_PARAM_BUFLEN_IN][2];

		/* 输入类型 */
	char    asInType[PREP_PARAM_BUFLEN_IN][6];
		/* 输出类型 */
	char    asOutType[PREP_PARAM_BUFLEN_IN][6];
		/* 启停状态 */
	char    asState[PREP_PARAM_BUFLEN_IN][2];
		/* 应用标识 */
	char    asAppID[PREP_PARAM_BUFLEN_IN][11];
		/* 环节标识 */
	int     aiTacheID[PREP_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct PrepParamStruct{

	struct PrepParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	int     iGroupID;		/* 群组标识 */
	char    sMsc[16];		/* 交换机标识 */
	char    sAreaCode[6];		/* 区号 */
	char    sExprFile[81];		/* 公式文件 */
	char    sFilter[21];		/* 模式 */
	char    sSourcePath[81];		/* 源路径 */
	char    sBackPath[81];		/* 备份路径 */
	char    sNormalPath[81];		/* 正常路径 */
	char    sErrPath[81];		/* 异常路径 */
	char    sModule[4];		/* 模块 */
	
	char    sSplit[11];
	int     iStartPos;
	int     iKeyLen;
	char    sChkMod[4];
	
	char    sUserType[2];

	char	sInType[6];
	char	sOutType[6];
	char    sState[2];		/* 启停状态 */
	char    sAppID[11];		/* 应用标识 */
	int     iTacheID;		/* 环节标识 */
	struct PrepParamStruct *pLoadNext;
};

/*批量数据动态从PREP_PARAM中用结构缓冲方式取数据*/
int EGetPrepParamToStruct(struct PrepParamStruct *p,
	struct PrepParamStructIn *pSource);
/**对表PREP_PARAM的链表释放函数**/
void DestroyPrepParam(struct PrepParamStruct *ptHead);
int InitPrepParam(struct PrepParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct BillParamStructIn{

#ifndef BILL_PARAM_BUFLEN_IN
#define BILL_PARAM_BUFLEN_IN		300
#endif

	struct BillParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[BILL_PARAM_BUFLEN_IN][7];
	char	asAppCode[BILL_PARAM_BUFLEN_IN][9];
		/* 群组标识 */
	int     aiGroupID[BILL_PARAM_BUFLEN_IN];
		/* 模式 */
	char    asFilter[BILL_PARAM_BUFLEN_IN][21];
		/* 源路径 */
	char    asSourcePath[BILL_PARAM_BUFLEN_IN][81];
		/* 备份路径 */
	char    asBackPath[BILL_PARAM_BUFLEN_IN][81];
		/* 正常路径 */
	char    asNormalPath[BILL_PARAM_BUFLEN_IN][81];
		/* 错误路径 */
	char    asErrPath[BILL_PARAM_BUFLEN_IN][81];
	char	asUserType[BILL_PARAM_BUFLEN_IN][41];
		/* 模版标识 */
	char    asTemplateID[BILL_PARAM_BUFLEN_IN][81];
		/* 分离串 */
	char    asSplitStr[BILL_PARAM_BUFLEN_IN][11];
		/* 文件归属地区 */
	char    asBelongCode[BILL_PARAM_BUFLEN_IN][6];
		/* 模块 */
	char    asModule[BILL_PARAM_BUFLEN_IN][4];

	char    asSplit[BILL_PARAM_BUFLEN_IN][10];
	int	aiStartPos[BILL_PARAM_BUFLEN_IN];
	int	aiKeyLen[BILL_PARAM_BUFLEN_IN];
	char    asBatchFlag[BILL_PARAM_BUFLEN_IN][2];

	char    asInType[BILL_PARAM_BUFLEN_IN][6];
	char    asOutType[BILL_PARAM_BUFLEN_IN][6];
		/* 启停状态 */
	char    asState[BILL_PARAM_BUFLEN_IN][2];
		/* 应用标识 */
	char    asAppID[BILL_PARAM_BUFLEN_IN][11];
		/* 环节标识 */
	int     aiTacheID[BILL_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct BillParamStruct{

	struct BillParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	char	sAppCode[9];
	int     iGroupID;		/* 群组标识 */
	char    sFilter[21];		/* 模式 */
	char    sSourcePath[81];		/* 源路径 */
	char    sBackPath[81];		/* 备份路径 */
	char    sNormalPath[81];		/* 正常路径 */
	char    sErrPath[81];		/* 错误路径 */
	char	sUserType[41];
	char    sTemplateID[81];		/* 模版标识 */
	char    sSplitStr[11];		/* 分离串 */
	char    sBelongCode[6];		/* 文件归属地区 */
	char    sModule[4];		/* 模块 */
	char    sSplit[10];
	int	iStartPos;
	int	iKeyLen;
	char	sBatchFlag[2];
	char	sInType[6];
	char	sOutType[6];
	char    sState[2];		/* 启停状态 */
	char    sAppID[11];		/* 应用标识 */
	int     iTacheID;		/* 环节标识 */
	struct BillParamStruct *pLoadNext;
};

/*批量数据动态从BILL_PARAM中用结构缓冲方式取数据*/
int EGetBillParamToStruct(struct BillParamStruct *p,
	struct BillParamStructIn *pSource);
/**对表BILL_PARAM的链表释放函数**/
void DestroyBillParam(struct BillParamStruct *ptHead);
int InitBillParam(struct BillParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct CommSearchStructIn{

#ifndef COMM_SEARCH_BUFLEN_IN
#define COMM_SEARCH_BUFLEN_IN		300
#endif

	struct CommSearchStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 表名 */
	char    asTableName[COMM_SEARCH_BUFLEN_IN][31];
		/* B用BINTREE,T用TRIE查找 */
	char    asMethod[COMM_SEARCH_BUFLEN_IN][2];
		/* 0标识默认值 */
	int     aiIntKey[COMM_SEARCH_BUFLEN_IN];
		/* 字符串键 */
	char    asStrKey[COMM_SEARCH_BUFLEN_IN][81];
		/* 整数值 */
	int     aiIntVal[COMM_SEARCH_BUFLEN_IN];
		/* 字符串值 */
	char    asStrVal[COMM_SEARCH_BUFLEN_IN][81];
		/* 生效时间 */
	char    asEffDate[COMM_SEARCH_BUFLEN_IN][15];
		/* 失效时间 */
	char    asExpDate[COMM_SEARCH_BUFLEN_IN][15];
	
	char	asState[COMM_SEARCH_BUFLEN_IN][4];
	char	asStateDate[COMM_SEARCH_BUFLEN_IN][15];
	char	asCreatedDate[COMM_SEARCH_BUFLEN_IN][15];
};


/*单个结构申明*/
struct CommSearchStruct{

	struct CommSearchStruct *pNext;
	char    sTableName[31];		/* 表名 */
	char    sMethod[2];	/*B用BINTREE,T用TRIE查找,b LBINTREE,t LTRIE*/
	int     iIntKey;		/* 0标识默认值 */
	char    sStrKey[81];		/* 字符串键 */
	int     iIntVal;		/* 整数值 */
	char    sStrVal[81];		/* 字符串值 */
	char    sEffDate[15];		/* 生效时间 */
	char    sExpDate[15];		/* 失效时间 */

	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct CommSearchStruct *pLoadNext;
};

int EGetCommSearchToStruct(struct CommSearchStruct *p,
	struct CommSearchStructIn *pSource);
/**对表COMM_SEARCH的链表释放函数**/
void DestroyCommSearch(struct CommSearchStruct *ptHead);
int InitCommSearch(struct CommSearchStruct **pptHead,char sMethod[]);
int InitCommSearchBin(struct CommSearchStruct **pptHead);
int InitCommSearchTrie(struct CommSearchStruct **pptHead);

/* 输入结构缓冲申明*/
struct CommRangeStructIn{

#ifndef COMM_RANGE_BUFLEN_IN
#define COMM_RANGE_BUFLEN_IN		300
#endif

	struct CommRangeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 表名 */
	char    asTableName[COMM_RANGE_BUFLEN_IN][31];
		/* 起始键 */
	char    asBgnKey[COMM_RANGE_BUFLEN_IN][21];
		/* 中止键 */
	char    asEndKey[COMM_RANGE_BUFLEN_IN][21];
		/* 整数值 */	
	int     aiIntVal[COMM_RANGE_BUFLEN_IN];
		/* 字符串值 */
	char    asStrVal[COMM_RANGE_BUFLEN_IN][41];
		/* 生效时间 */
	char    asEffDate[COMM_RANGE_BUFLEN_IN][15];
		/* 失效时间 */
	char    asExpDate[COMM_RANGE_BUFLEN_IN][15];

	char	asState[COMM_RANGE_BUFLEN_IN][4];
	char	asStateDate[COMM_RANGE_BUFLEN_IN][15];
	char	asCreatedDate[COMM_RANGE_BUFLEN_IN][15];
};

/*单个结构申明*/
struct CommRangeStruct{

	struct CommRangeStruct *pNext;
	char    sTableName[31];		/* 表名 */
	char    sBgnKey[21];		/* 起始键 */
	char    sEndKey[21];		/* 中止键 */
	int     iIntVal;		/* 整数值 */
	char    sStrVal[41];		/* 字符串值 */
	char    sEffDate[15];		/* 生效时间 */
	char    sExpDate[15];		/* 失效时间 */
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct CommRangeStruct *pLoadNext;
};

int EGetCommRangeToStruct(struct CommRangeStruct *p,
	struct CommRangeStructIn *pSource);
void DestroyCommRange(struct CommRangeStruct *ptHead);
int InitCommRange(struct CommRangeStruct **pptHead);

/* 输入结构缓冲申明*/
struct SwitchStructIn{

#ifndef SWITCH_BUFLEN_IN
#define SWITCH_BUFLEN_IN		300
#endif

	struct SwitchStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 交换机标识 */
	int     aiSwitchID[SWITCH_BUFLEN_IN];
		/* 类型标识 */
	int     aiTypeID[SWITCH_BUFLEN_IN];
		/* 仅用于参数配置，对于一覆多的交换机含义不确切 */
	char    asAreaCode[SWITCH_BUFLEN_IN][6];
		/* IP:通过IP方式，SERIAL:串口 */
	char    asMethod[SWITCH_BUFLEN_IN][7];
		/* 当METHOD=IP的时候，标识SOCKET协议IP，否则为代理机的IP */
	char    asIp[SWITCH_BUFLEN_IN][16];
		/* 当METHOD=IP的时候，标识SOCKET协议端口，否则为代理机的端口 */
	int     aiPort[SWITCH_BUFLEN_IN];
	char    asUserName[SWITCH_BUFLEN_IN][31];
	char    asPassword[SWITCH_BUFLEN_IN][31];
		/* 描述 */
	char    asRemark[SWITCH_BUFLEN_IN][61];
};


/*单个结构申明*/
struct SwitchStruct{

	struct SwitchStruct *pNext;
	int     iSwitchID;		/* 交换机标识 */
	int     iTypeID;		/* 类型标识 */
	char    sAreaCode[6];		/* 仅用于参数配置，对于一覆多的交换机含义不确切 */
	char    sMethod[7];		/* IP:通过IP方式，SERIAL:串口 */
	char    sIp[16];		/* 当METHOD=IP的时候，标识SOCKET协议IP，否则为代理机的IP */
	int     iPort;		/* 当METHOD=IP的时候，标识SOCKET协议端口，否则为代理机的端口 */
	char	sUserName[31];
	char	sPassword[31];
	char    sRemark[61];		/* 描述 */
	struct SwitchStruct *pLoadNext;
};

/*批量数据动态从SWITCH中用结构缓冲方式取数据*/
int EGetSwitchToStruct(struct SwitchStruct *p,
	struct SwitchStructIn *pSource);
/**对表SWITCH的链表释放函数**/
void DestroySwitch(struct SwitchStruct *ptHead);
int InitSwitch(struct SwitchStruct **pptHead);

/* 输入结构缓冲申明*/
struct CmdTemplateStructIn{

#ifndef CMD_TEMPLATE_BUFLEN_IN
#define CMD_TEMPLATE_BUFLEN_IN		300
#endif

	struct CmdTemplateStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 模版标识 */
	int     aiTemplateID[CMD_TEMPLATE_BUFLEN_IN];
		/* 命令类型标识 */
	int     aiCmdTypeID[CMD_TEMPLATE_BUFLEN_IN];
		/* 标准编码 */
	char    asStandardCode[CMD_TEMPLATE_BUFLEN_IN][31];
		/* 交换机类型标识 */
	int     aiSwitchTypeID[CMD_TEMPLATE_BUFLEN_IN];
		/* 模版解析脚本 */
	char    asCmdText[CMD_TEMPLATE_BUFLEN_IN][61];
		/* 描述 */
	char    asRemark[CMD_TEMPLATE_BUFLEN_IN][61];
};


/*单个结构申明*/
struct CmdTemplateStruct{

	struct CmdTemplateStruct *pNext;
	int     iTemplateID;		/* 模版标识 */
	int     iCmdTypeID;		/* 命令类型标识 */
	char    sStandardCode[31];		/* 标准编码 */
	int     iSwitchTypeID;		/* 交换机类型标识 */
	char    sCmdText[61];		/* 模版解析脚本 */
	char    sRemark[61];		/* 描述 */
	struct CmdTemplateStruct *pLoadNext;
};

/*批量数据动态从CMD_TEMPLATE中用结构缓冲方式取数据*/
int EGetCmdTemplateToStruct(struct CmdTemplateStruct *p,
	struct CmdTemplateStructIn *pSource);
void DestroyCmdTemplate(struct CmdTemplateStruct *ptHead);
int InitCmdTemplate(struct CmdTemplateStruct **pptHead);

/* 输入结构缓冲申明*/
struct NbrHeadStructIn{

#ifndef NBR_HEAD_BUFLEN_IN
#define NBR_HEAD_BUFLEN_IN		300
#endif

	struct NbrHeadStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 业务类型 */
	char    asServiceType[NBR_HEAD_BUFLEN_IN][11];
		/* 号段 */
	char    asHead[NBR_HEAD_BUFLEN_IN][13];
		/* ACCNBR表示号码,IMSI表示IMSI,ESN表示电子串号 */
	char    asFieldType[NBR_HEAD_BUFLEN_IN][7];
		/* 交换机标识 */
	int     aiSwitchID[NBR_HEAD_BUFLEN_IN];
};


/*单个结构申明*/
struct NbrHeadStruct{

	struct NbrHeadStruct *pNext;
	char    sServiceType[11];		/* 业务类型 */
	char    sHead[13];		/* 号段 */
	char    sFieldType[7];		/* ACCNBR表示号码,IMSI表示IMSI,ESN表示电子串号 */
	int     iSwitchID;		/* 交换机标识 */
	struct NbrHeadStruct *pLoadNext;
};
/*批量数据动态从NBR_HEAD中用结构缓冲方式取数据*/
int EGetNbrHeadToStruct(struct NbrHeadStruct *p,
	struct NbrHeadStructIn *pSource);
void DestroyNbrHead(struct NbrHeadStruct *ptHead);
int InitNbrHead(struct NbrHeadStruct **pptHead);

/* 输入结构缓冲申明*/
struct AcctItemTypeStructIn{

#ifndef ACCT_ITEM_TYPE_BUFLEN_IN
#define ACCT_ITEM_TYPE_BUFLEN_IN		300
#endif

	struct AcctItemTypeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[ACCT_ITEM_TYPE_BUFLEN_IN];
		/* 帐目分类，引用a_acct_item_type_kind B-基本帐目D-衍生帐目 */
	char    asAcctItemTypeKind[ACCT_ITEM_TYPE_BUFLEN_IN][2];
		/* 名称 */
	char    asAcctItemName[ACCT_ITEM_TYPE_BUFLEN_IN][61];
		/* 标准编码 */
	char    asStandardCode[ACCT_ITEM_TYPE_BUFLEN_IN][11];
		/* 归并帐目标识 */
	int     aiSummaryItemID[ACCT_ITEM_TYPE_BUFLEN_IN];
};


/*单个结构申明*/
struct AcctItemTypeStruct{

	struct AcctItemTypeStruct *pNext;
	int     iAcctItemTypeID;		/* 帐目类型标识 */
	char    sAcctItemTypeKind[2];		
/* 帐目分类，引用a_acct_item_type_kind B-基本帐目D-衍生帐目 */
	char    sAcctItemName[61];		/* 名称 */
	char    sStandardCode[11];		/* 标准编码 */
	int     iSummaryItemID;		/* 归并帐目标识 */
	struct AcctItemTypeStruct *pLoadNext;
};
/*批量数据动态从ACCT_ITEM_TYPE中用结构缓冲方式取数据*/
int EGetAcctItemTypeToStruct(struct AcctItemTypeStruct *p,
	struct AcctItemTypeStructIn *pSource);
int InitAcctItemType(struct AcctItemTypeStruct **pptHead);
void DestroyAcctItemType(struct AcctItemTypeStruct *ptHead);


/* 输入结构缓冲申明*/
struct SettRuleStructIn{

#ifndef SETT_RULE_BUFLEN_IN
#define SETT_RULE_BUFLEN_IN		300
#endif

	struct SettRuleStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 结算规则标识 */
	int     aiSettRuleID[SETT_RULE_BUFLEN_IN];
	int     aiSeqNbr[SETT_RULE_BUFLEN_IN];
		/* 话单类型标识 */
	int     aiTicketTypeID[SETT_RULE_BUFLEN_IN];
		/* 资费类型 */
	char    asTariffType[SETT_RULE_BUFLEN_IN][3];
		/* 'C' 按次结算 ‘P' 按百分比结算 'D' 按时长结算 'F' 流量结算 'R' 实收结算 */
	char    asMethod[SETT_RULE_BUFLEN_IN][2];
		/* 结算对象 */
	int     aiOppCarrierID[SETT_RULE_BUFLEN_IN];
		/* 结算帐目类型 */
	int     aiAcctItemTypeID[SETT_RULE_BUFLEN_IN];
		/* 结算费率 */
	int     aiRate[SETT_RULE_BUFLEN_IN];
		/* 结次单位 */
	int     aiSecPerCnt[SETT_RULE_BUFLEN_IN];
		/* 生效时间 */
	char    asEffDate[SETT_RULE_BUFLEN_IN][15];
		/* 失效时间 */
	char    asExpDate[SETT_RULE_BUFLEN_IN][15];
	char    asState[SETT_RULE_BUFLEN_IN][4];
	char    asStateDate[SETT_RULE_BUFLEN_IN][15];
	char    asCreatedDate[SETT_RULE_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SettRuleStruct{

	struct SettRuleStruct *pNext;
	int     iSettRuleID;		/* 结算规则标识 */
	int	iSeqNbr;
	int     iTicketTypeID;		/* 话单类型标识 */
	char    sTariffType[3];		/* 资费类型 */
	char    sMethod[2];		/* 'C' 按次结算 ‘P' 按百分比结算 'D' 按时长结算 'F' 流量结算 'R' 实收结算 */
	int     iOppCarrierID;		/* 结算对象 */
	int     iAcctItemTypeID;		/* 结算帐目类型 */
	int     iRate;		/* 结算费率 */
	int     iSecPerCnt;		/* 结次单位 */
	char    sEffDate[15];		/* 生效时间 */
	char    sExpDate[15];		/* 失效时间 */
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct SettRuleStruct *pLoadNext;
};
/*批量数据动态从SETT_RULE中用结构缓冲方式取数据*/
int EGetSettRuleToStruct(struct SettRuleStruct *p,
	struct SettRuleStructIn *pSource);
/**对表SETT_RULE的链表释放函数**/
void DestroySettRule(struct SettRuleStruct *ptHead);
int InitSettRule(struct SettRuleStruct **pptHead);

/* 输入结构缓冲申明*/
struct SettCycleStructIn{

#ifndef SETT_CYCLE_BUFLEN_IN
#define SETT_CYCLE_BUFLEN_IN		300
#endif

	struct SettCycleStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐务周期标识号 */
	int     aiSettCycleID[SETT_CYCLE_BUFLEN_IN];
		/* 帐务周期标识 */
	int     aiCycleTypeID[SETT_CYCLE_BUFLEN_IN];
		/* 子系统模块 */
	char    asModule[SETT_CYCLE_BUFLEN_IN][4];
		/* 结算对象标识 */
	int     aiSettCarrierID[SETT_CYCLE_BUFLEN_IN];
		/* 帐务周期开始日期 */
	char    asCycleBeginDate[SETT_CYCLE_BUFLEN_IN][15];
		/* 帐务周期结束日期 */
	char    asCycleEndDate[SETT_CYCLE_BUFLEN_IN][15];
		/* 状态 */
	char    asState[SETT_CYCLE_BUFLEN_IN][4];
		/* 结算月份 */
	char    asMonth[SETT_CYCLE_BUFLEN_IN][3];
		/* 描述 */
	char    asRemark[SETT_CYCLE_BUFLEN_IN][61];
};


/*单个结构申明*/
struct SettCycleStruct{

	struct SettCycleStruct *pNext;
	int     iSettCycleID;		/* 帐务周期标识号 */
	int     iCycleTypeID;		/* 帐务周期标识 */
	char    sModule[4];		/* 子系统模块 */
	int     iSettCarrierID;		/* 结算对象标识 */
	char    sCycleBeginDate[15];		/* 帐务周期开始日期 */
	char    sCycleEndDate[15];		/* 帐务周期结束日期 */
	char    sState[4];		/* 状态 */
	char    sMonth[3];		/* 结算月份 */
	char    sRemark[61];		/* 描述 */
	struct SettCycleStruct *pLoadNext;
};

/*批量数据动态从SETT_CYCLE中用结构缓冲方式取数据*/
int EGetSettCycleToStruct(struct SettCycleStruct *p,
	struct SettCycleStructIn *pSource);
/**对表SETT_CYCLE的链表释放函数**/
void DestroySettCycle(struct SettCycleStruct *ptHead);
int InitSettCycle(struct SettCycleStruct **pptHead);

/* 输入结构缓冲申明*/
struct LatnStructIn{

#ifndef LATN_BUFLEN_IN
#define LATN_BUFLEN_IN		300
#endif

	struct LatnStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 本地网标识 */
	int     aiLatnID[LATN_BUFLEN_IN];
		/* 名称 */
	char    asName[LATN_BUFLEN_IN][21];
		/* 标准编码 */
	char    asStandardCode[LATN_BUFLEN_IN][5];
		/* 归属区号 */
	char    asAreaCode[LATN_BUFLEN_IN][6];
};


/*单个结构申明*/
struct LatnStruct{

	struct LatnStruct *pNext;
	int     iLatnID;		/* 本地网标识 */
	char    sName[21];		/* 名称 */
	char    sStandardCode[5];		/* 标准编码 */
	char    sAreaCode[6];		/* 归属区号 */
	struct LatnStruct *pLoadNext;
};


/*批量数据动态从LATN中用结构缓冲方式取数据*/
int EGetLatnToStruct(struct LatnStruct *p,
	struct LatnStructIn *pSource);
/**对表LATN的链表释放函数**/
void DestroyLatn(struct LatnStruct *ptHead);
int InitLatn(struct LatnStruct **pptHead);


/* 输入结构缓冲申明*/
struct PutParamStructIn{

#ifndef PUT_PARAM_BUFLEN_IN
#define PUT_PARAM_BUFLEN_IN		300
#endif

	struct PutParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[PUT_PARAM_BUFLEN_IN][7];
		/* 群组标识 */
	int     aiGroupID[PUT_PARAM_BUFLEN_IN];
		/* 对端路径 */
	char    asOppPath[PUT_PARAM_BUFLEN_IN][81];
		/* 本端备份路径 */
	char    asLocalBkupPath[PUT_PARAM_BUFLEN_IN][81];
		/* 本端路径 */
	char    asLocalPath[PUT_PARAM_BUFLEN_IN][81];
		/* 主机IP */
	char    asIp[PUT_PARAM_BUFLEN_IN][17];
		/* 用户名 */
	char    asUserName[PUT_PARAM_BUFLEN_IN][21];
		/* 口令 */
	char    asPasswd[PUT_PARAM_BUFLEN_IN][21];
		/* 匹配模式 */
	char    asFilter[PUT_PARAM_BUFLEN_IN][21];
	
	int	aiSeqOff[PUT_PARAM_BUFLEN_IN];
	int	aiSeqLen[PUT_PARAM_BUFLEN_IN];
	char	asDeleteType[PUT_PARAM_BUFLEN_IN][2];
	int	aiChkDays[PUT_PARAM_BUFLEN_IN];

		/* 单次最大处理文件数 */
	char    asFileType[PUT_PARAM_BUFLEN_IN][6];
		/* 启停状态 */
	char    asState[PUT_PARAM_BUFLEN_IN][2];
	
	char    asAppID[PUT_PARAM_BUFLEN_IN][11];
	int     aiTacheID[PUT_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct PutParamStruct{

	struct PutParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	int     iGroupID;		/* 群组标识 */
	char    sOppPath[81];		/* 对端路径 */
	char    sLocalBkupPath[81];		/* 本端备份路径 */
	char    sLocalPath[81];		/* 本端路径 */
	char    sIp[17];		/* 主机IP */
	char    sUserName[21];		/* 用户名 */
	char    sPasswd[21];		/* 口令 */
	char    sFilter[21];		/* 匹配模式 */
	int	iSeqOff;
	int	iSeqLen;
	char	sDeleteType[2];
	int	iChkDays;
	char    sFileType[6];		/* 文件类型 */
	char    sState[2];		/* 启停状态 */
	char	sAppID[11];
	int	iTacheID;
	struct PutParamStruct *pLoadNext;
};
/*批量数据动态从PUT_PARAM中用结构缓冲方式取数据*/
int EGetPutParamToStruct(struct PutParamStruct *p,
	struct PutParamStructIn *pSource);
/**对表PUT_PARAM的链表释放函数**/
void DestroyPutParam(struct PutParamStruct *ptHead);
int InitPutParam(struct PutParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct CommParamStructIn{

#ifndef COMM_PARAM_BUFLEN_IN
#define COMM_PARAM_BUFLEN_IN		300
#endif

	struct CommParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[COMM_PARAM_BUFLEN_IN][7];
		/* 组号 */
	int     aiGroupID[COMM_PARAM_BUFLEN_IN];
		/* 模块号 */
	char    asModule[COMM_PARAM_BUFLEN_IN][4];
		/* 源目录 */
	char    asSourcePath[COMM_PARAM_BUFLEN_IN][81];
		/* 文件匹配模式 */
	char    asFilter[COMM_PARAM_BUFLEN_IN][21];
		/* 备份目录 */
	char    asBackupPath[COMM_PARAM_BUFLEN_IN][81];
		/* 输出目录 */
	char    asTargetPath[COMM_PARAM_BUFLEN_IN][81];
		/* 指的是$BILLHOME/bin下的命令. 命令的格式是 ./cmd source_path filter back_path 
target_path  append_arg */
	char    asCmd[COMM_PARAM_BUFLEN_IN][81];
	char    asInType[COMM_PARAM_BUFLEN_IN][6];
	char    asOutType[COMM_PARAM_BUFLEN_IN][6];
		/* 做为末尾的ｎ个参数 */
	char    asAppendArg[COMM_PARAM_BUFLEN_IN][101];
};


/*单个结构申明*/
struct CommParamStruct{

	struct CommParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	int     iGroupID;		/* 组号 */
	char    sModule[4];		/* 模块号 */
	char    sSourcePath[81];		/* 源目录 */
	char    sFilter[21];		/* 文件匹配模式 */
	char    sBackupPath[81];		/* 备份目录 */
	char    sTargetPath[81];		/* 输出目录 */
	char    sCmd[81];
	char    sInType[81];
	char    sOutType[81];
	/* 指的是$BILLHOME/bin下的命令. 命令的格式是 
	./cmd source_path filter back_path target_path  append_arg */
	char    sAppendArg[101];		/* 做为末尾的ｎ个参数 */
	struct CommParamStruct *pLoadNext;
};
/*批量数据动态从COMM_PARAM中用结构缓冲方式取数据*/
int EGetCommParamToStruct(struct CommParamStruct *p,
	struct CommParamStructIn *pSource);
/**对表COMM_PARAM的链表释放函数**/
void DestroyCommParam(struct CommParamStruct *ptHead);
int InitCommParam(struct CommParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct SettAreaStructIn{

#ifndef SETT_AREA_BUFLEN_IN
#define SETT_AREA_BUFLEN_IN		300
#endif

	struct SettAreaStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 营业区标识 */
	int     aiSettAreaID[SETT_AREA_BUFLEN_IN];
		/* 本地网标识 */
	int     aiLatnID[SETT_AREA_BUFLEN_IN];
		/* '0' 区　'1'县 */
	char    asCountyFlag[SETT_AREA_BUFLEN_IN][2];
		/* 名称 */
	char    asName[SETT_AREA_BUFLEN_IN][41];
};


/*单个结构申明*/
struct SettAreaStruct{

	struct SettAreaStruct *pNext;
	int     iSettAreaID;		/* 营业区标识 */
	int     iLatnID;		/* 本地网标识 */
	char    sCountyFlag[2];		/* '0' 区　'1'县 */
	char    sName[41];		/* 名称 */
	struct SettAreaStruct *pLoadNext;
};
/*批量数据动态从SETT_AREA中用结构缓冲方式取数据*/
int EGetSettAreaToStruct(struct SettAreaStruct *p,struct SettAreaStructIn *pSource);
/**对表AREA的链表释放函数**/
void DestroySettArea(struct SettAreaStruct *ptHead);
int InitSettArea(struct SettAreaStruct **pptHead);

/* 输入结构缓冲申明*/
struct FlowAppStructIn{

#ifndef FLOW_APP_BUFLEN_IN
#define FLOW_APP_BUFLEN_IN		300
#endif

	struct FlowAppStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 应用标识 */
	char    asAppID[FLOW_APP_BUFLEN_IN][11];
		/* 应用编码 */
	char    asAppCode[FLOW_APP_BUFLEN_IN][9];
		/* 0起始应用,1中间应用,2终止应用 */
	char    asAppType[FLOW_APP_BUFLEN_IN][2];
		/* 应用名称 */
	char    asName[FLOW_APP_BUFLEN_IN][21];
};


/*单个结构申明*/
struct FlowAppStruct{

	struct FlowAppStruct *pNext;
	char    sAppID[11];		/* 应用标识 */
	char    sAppCode[9];		/* 应用编码 */
	char    sAppType[2];		/* 0起始应用,1中间应用,2终止应用 */
	char    sName[21];		/* 应用名称 */
	struct FlowAppStruct *pLoadNext;
};
/*批量数据动态从FLOW_APP中用结构缓冲方式取数据*/
int EGetFlowAppToStruct(struct FlowAppStruct *p,
	struct FlowAppStructIn *pSource);
/**对表FLOW_APP的链表释放函数**/
void DestroyFlowApp(struct FlowAppStruct *ptHead);
int InitFlowApp(struct FlowAppStruct **pptHead);

/* 输入结构缓冲申明*/
struct FlowTaskStructIn{

#ifndef FLOW_TASK_BUFLEN_IN
#define FLOW_TASK_BUFLEN_IN		300
#endif

	struct FlowTaskStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 任务标识 */
	int     aiTaskID[FLOW_TASK_BUFLEN_IN];
		/* 群组标识 */
	int     aiGrpTaskID[FLOW_TASK_BUFLEN_IN];
		/* 任务组标识0，非组,1组 */
	char    asGrpFlag[FLOW_TASK_BUFLEN_IN][2];
		/* 应用标识 */
	char    asAppID[FLOW_TASK_BUFLEN_IN][11];
		/* 参数标识 */
	int     aiParamID[FLOW_TASK_BUFLEN_IN];
		/* 任务名称 */
	char    asName[FLOW_TASK_BUFLEN_IN][41];
};
/*单个结构申明*/
struct FlowTaskStruct{

	struct FlowTaskStruct *pNext;
	int     iTaskID;		/* 任务标识 */
	int     iGrpTaskID;		/* 群组标识 */
	char    sGrpFlag[2];		/* 任务组标识0，非组,1组 */
	char    sAppID[11];		/* 应用标识 */
	int     iParamID;		/* 参数标识 */
	char    sName[41];		/* 任务名称 */
	struct FlowTaskStruct *pLoadNext;
};
/*批量数据动态从FLOW_TASK中用结构缓冲方式取数据*/
int EGetFlowTaskToStruct(struct FlowTaskStruct *p,
	struct FlowTaskStructIn *pSource);
/**对表FLOW_TASK的链表释放函数**/
void DestroyFlowTask(struct FlowTaskStruct *ptHead);
int InitFlowTask(struct FlowTaskStruct **pptHead);

/* 输入结构缓冲申明*/
struct FlowTacheStructIn{

#ifndef FLOW_TACHE_BUFLEN_IN
#define FLOW_TACHE_BUFLEN_IN		300
#endif

	struct FlowTacheStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 环节标识 */
	int     aiTacheID[FLOW_TACHE_BUFLEN_IN];
		/* 前置环节标识 */
	int     aiPreTacheID[FLOW_TACHE_BUFLEN_IN];
		/* 前置环节序号 */
	int     aiPreSeqNbr[FLOW_TACHE_BUFLEN_IN];
		/* 流程标识 */
	int     aiFlowID[FLOW_TACHE_BUFLEN_IN];
		/* 任务标识 */
	int     aiTaskID[FLOW_TACHE_BUFLEN_IN];
		/* 应用标识 */
	char    asAppID[FLOW_TACHE_BUFLEN_IN][11];
	
	char    asPreIntfType[FLOW_TACHE_BUFLEN_IN][2];
	char    asDataDealType[FLOW_TACHE_BUFLEN_IN][3];
};
/*单个结构申明*/
struct FlowTacheStruct{

	struct FlowTacheStruct *pNext;
	int     iTacheID;		/* 环节标识 */
	int     iPreTacheID;		/* 前置环节标识 */
	int     iPreSeqNbr;		/* 前置环节序号 */
	int     iFlowID;		/* 流程标识 */
	int     iTaskID;		/* 任务标识 */
	char    sAppID[11];		/* 应用标识 */
	char    sPreIntfType[2];
	char    sDataDealType[3];
	struct FlowTacheStruct *pLoadNext;
};
/*批量数据动态从FLOW_TACHE中用结构缓冲方式取数据*/
int EGetFlowTacheToStruct(struct FlowTacheStruct *p,
	struct FlowTacheStructIn *pSource);
/**对表FLOW_TACHE的链表释放函数**/
void DestroyFlowTache(struct FlowTacheStruct *ptHead);
int InitFlowTache(struct FlowTacheStruct **pptHead);

/* 输入结构缓冲申明*/
struct TaskParamStructIn{

#ifndef TASK_PARAM_BUFLEN_IN
#define TASK_PARAM_BUFLEN_IN		300
#endif

	struct TaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 参数标识 */
	int     aiParamID[TASK_PARAM_BUFLEN_IN];
		/* 应用标识 */
	char    asAppID[TASK_PARAM_BUFLEN_IN][11];
		/* 输入相对路径 */
	char    asInPath[TASK_PARAM_BUFLEN_IN][61];
		/* 备份相对路径 */
	char    asBakPath[TASK_PARAM_BUFLEN_IN][61];
		/* 输出相对路径 */
	char    asOutPath[TASK_PARAM_BUFLEN_IN][61];
		/* 输入文件模式 */
	char    asInFilter[TASK_PARAM_BUFLEN_IN][61];
		/* 输出文件模式 */
	char    asOutFilter[TASK_PARAM_BUFLEN_IN][61];
		/* 输入格式类型 */
	char    asInType[TASK_PARAM_BUFLEN_IN][6];
		/* 输出格式类型 */
	char    asOutType[TASK_PARAM_BUFLEN_IN][6];
};
/*单个结构申明*/
struct TaskParamStruct{

	struct TaskParamStruct *pNext;
	int     iParamID;		/* 参数标识 */
	char    sAppID[11];		/* 应用标识 */
	char    sInPath[61];		/* 输入相对路径 */
	char    sBakPath[61];		/* 备份相对路径 */
	char    sOutPath[61];		/* 输出相对路径 */
	char    sInFilter[61];		/* 输入文件模式 */
	char    sOutFilter[61];	/* 输出文件模式 */
	char    sInType[6];		/* 输入格式类型 */
	char    sOutType[6];		/* 输出格式类型 */
	struct TaskParamStruct *pLoadNext;
};
/*批量数据动态从TASK_PARAM中用结构缓冲方式取数据*/
int EGetTaskParamToStruct(struct TaskParamStruct *p,
	struct TaskParamStructIn *pSource);
/**对表TASK_PARAM的链表释放函数**/
void DestroyTaskParam(struct TaskParamStruct *ptHead);
int InitTaskParam(struct TaskParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct AcctTaskParamStructIn{

#ifndef ACCT_TASK_PARAM_BUFLEN_IN
#define ACCT_TASK_PARAM_BUFLEN_IN		300
#endif

	struct AcctTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[ACCT_TASK_PARAM_BUFLEN_IN][7];
		/* 变动序号 */
	int     aiSeqNbr[ACCT_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[ACCT_TASK_PARAM_BUFLEN_IN];
		/* 群组标识 */
	int     aiGroupID[ACCT_TASK_PARAM_BUFLEN_IN];
	char    asOperType[ACCT_TASK_PARAM_BUFLEN_IN][4];
		/* 日期规则 */
	char    asDateRule[ACCT_TASK_PARAM_BUFLEN_IN][13];
		/* 数据归属地区 */
	char    asBelongCode[ACCT_TASK_PARAM_BUFLEN_IN][6];
		/* 模块 */
	char    asModule[ACCT_TASK_PARAM_BUFLEN_IN][4];
	char    asEffDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
	char    asState[ACCT_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
};
/*单个结构申明*/
struct AcctTaskParamStruct{

	struct AcctTaskParamStruct *pNext;
	char    sSourceID[7];
	int     iParamID;		/* 参数标识 */
	int     iSeqNbr;		/* 变动序号 */
	int     iGroupID;		/* 群组标识 */
	char    sOperType[4];
	char    sDateRule[13];		/* 日期规则 */
	char    sBelongCode[6];		/* 数据归属地区 */
	char    sModule[4];		/* 模块 */
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct AcctTaskParamStruct *pLoadNext;
};
/*批量数据动态从ACCT_TASK_PARAM中用结构缓冲方式取数据*/
int EGetAcctTaskParamToStruct(struct AcctTaskParamStruct *p,
	struct AcctTaskParamStructIn *pSource);
/**对表ACCT_TASK_PARAM的链表释放函数**/
void DestroyAcctTaskParam(struct AcctTaskParamStruct *ptHead);
int InitAcctTaskParam(struct AcctTaskParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct BillTaskParamStructIn{

#ifndef BILL_TASK_PARAM_BUFLEN_IN
#define BILL_TASK_PARAM_BUFLEN_IN		300
#endif

	struct BillTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[BILL_TASK_PARAM_BUFLEN_IN][7];
	char    asAppCode[BILL_TASK_PARAM_BUFLEN_IN][9];
		/* 变动序号 */
	int     aiSeqNbr[BILL_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[BILL_TASK_PARAM_BUFLEN_IN];
		/* 群组标识 */
	int     aiGroupID[BILL_TASK_PARAM_BUFLEN_IN];
		/* 公式文件或用户类型 */
	char    asUserType[BILL_TASK_PARAM_BUFLEN_IN][41];
		/* 模版标识 */
	char    asTemplateID[BILL_TASK_PARAM_BUFLEN_IN][81];
		/* 分离串 */
	char    asSplitStr[BILL_TASK_PARAM_BUFLEN_IN][11];
		/* 文件归属地区 */
	char    asBelongCode[BILL_TASK_PARAM_BUFLEN_IN][6];
		/* 模块 */
	char    asModule[BILL_TASK_PARAM_BUFLEN_IN][4];
	char    asSplit[BILL_TASK_PARAM_BUFLEN_IN][10];
		/* 分发键偏移 */
	int     aiStartPos[BILL_TASK_PARAM_BUFLEN_IN];
		/* 长度 */
	int     aiKeyLen[BILL_TASK_PARAM_BUFLEN_IN];
	char    asBatchFlag[BILL_TASK_PARAM_BUFLEN_IN][2];
	
	char    asEffDate[BILL_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[BILL_TASK_PARAM_BUFLEN_IN][15];
	char    asState[BILL_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[BILL_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[BILL_TASK_PARAM_BUFLEN_IN][15];
};
/*单个结构申明*/
struct BillTaskParamStruct{

	struct BillTaskParamStruct *pNext;
	char    sSourceID[7];
	char    sAppCode[9];
	int     iSeqNbr;		/* 变动序号 */
	int     iParamID;		/* 参数标识 */
	int     iGroupID;		/* 群组标识 */
	char    sUserType[41];		/* 公式文件或用户类型 */
	char    sTemplateID[81];		/* 模版标识 */
	char    sSplitStr[11];		/* 分离串 */
	char    sBelongCode[6];		/* 文件归属地区 */
	char    sModule[4];		/* 模块 */
	char    sSplit[10];
	int     iStartPos;		/* 分发键偏移 */
	int     iKeyLen;		/* 长度 */
	char    sBatchFlag[2];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct BillTaskParamStruct *pLoadNext;
};
/*批量数据动态从BILL_TASK_PARAM中用结构缓冲方式取数据*/
int EGetBillTaskParamToStruct(struct BillTaskParamStruct *p,
	struct BillTaskParamStructIn *pSource);
/**对表BILL_TASK_PARAM的链表释放函数**/
void DestroyBillTaskParam(struct BillTaskParamStruct *ptHead);
int InitBillTaskParam(struct BillTaskParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct InstTaskParamStructIn{

#ifndef INST_TASK_PARAM_BUFLEN_IN
#define INST_TASK_PARAM_BUFLEN_IN		300
#endif

	struct InstTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[INST_TASK_PARAM_BUFLEN_IN][7];
		/* 变动序号 */
	int     aiSeqNbr[INST_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[INST_TASK_PARAM_BUFLEN_IN];
		/* 群组标识 */
	int     aiGroupID[INST_TASK_PARAM_BUFLEN_IN];
	char    asOperType[INST_TASK_PARAM_BUFLEN_IN][4];
		/* 日期规则 */
	char    asDateRule[INST_TASK_PARAM_BUFLEN_IN][13];
		/* 数据归属地区 */
	char    asBelongCode[INST_TASK_PARAM_BUFLEN_IN][6];
		/* 模块 */
	char    asModule[INST_TASK_PARAM_BUFLEN_IN][4];
	char    asEffDate[INST_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[INST_TASK_PARAM_BUFLEN_IN][15];
	char    asState[INST_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[INST_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[INST_TASK_PARAM_BUFLEN_IN][15];
};


/*单个结构申明*/
struct InstTaskParamStruct{

	struct InstTaskParamStruct *pNext;
	char    sSourceID[7];
	int     iSeqNbr;		/* 变动序号 */
	int     iParamID;		/* 参数标识 */
	int     iGroupID;		/* 群组标识 */
	char    sOperType[4];
	char    sDateRule[13];		/* 日期规则 */
	char    sBelongCode[6];		/* 数据归属地区 */
	char    sModule[4];		/* 模块 */
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct InstTaskParamStruct *pLoadNext;
};
/*批量数据动态从INST_TASK_PARAM中用结构缓冲方式取数据*/
int EGetInstTaskParamToStruct(struct InstTaskParamStruct *p,
	struct InstTaskParamStructIn *pSource);
/**对表INST_TASK_PARAM的链表释放函数**/
void DestroyInstTaskParam(struct InstTaskParamStruct *ptHead);
int InitInstTaskParam(struct InstTaskParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct IntfTaskParamStructIn{

#ifndef INTF_TASK_PARAM_BUFLEN_IN
#define INTF_TASK_PARAM_BUFLEN_IN		300
#endif

	struct IntfTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[INTF_TASK_PARAM_BUFLEN_IN][7];
		/* 变动序号 */
	int     aiSeqNbr[INTF_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[INTF_TASK_PARAM_BUFLEN_IN];
		/* 群组标识 */
	int     aiGroupID[INTF_TASK_PARAM_BUFLEN_IN];
		/* 秒 */
	int     aiDelay[INTF_TASK_PARAM_BUFLEN_IN];
		/* 城市代码 */
	char    asCityCode[INTF_TASK_PARAM_BUFLEN_IN][4];
	char    asFilter[INTF_TASK_PARAM_BUFLEN_IN][61];
	char    asFileType[INTF_TASK_PARAM_BUFLEN_IN][6];
	char    asEffDate[INTF_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[INTF_TASK_PARAM_BUFLEN_IN][15];
	char    asState[INTF_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[INTF_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[INTF_TASK_PARAM_BUFLEN_IN][15];
};
/*单个结构申明*/
struct IntfTaskParamStruct{

	struct IntfTaskParamStruct *pNext;
	char	sSourceID[7];
	int     iSeqNbr;		/* 变动序号 */
	int     iParamID;		/* 参数标识 */
	int     iGroupID;		/* 群组标识 */
	int     iDelay;			/* 秒 */
	char    sCityCode[4];		/* 城市代码 */
	char    sFilter[61];		/* 输入模式 */
	char	sFileType[6];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct IntfTaskParamStruct *pLoadNext;
};
/*批量数据动态从INTF_TASK_PARAM中用结构缓冲方式取数据*/
int EGetIntfTaskParamToStruct(struct IntfTaskParamStruct *p,
	struct IntfTaskParamStructIn *pSource);
/**对表INTF_TASK_PARAM的链表释放函数**/
void DestroyIntfTaskParam(struct IntfTaskParamStruct *ptHead);
int InitIntfTaskParam(struct IntfTaskParamStruct **pptHead);


/* 输入结构缓冲申明*/
struct PickTaskParamStructIn{

#ifndef PICK_TASK_PARAM_BUFLEN_IN
#define PICK_TASK_PARAM_BUFLEN_IN		300
#endif

	struct PickTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[PICK_TASK_PARAM_BUFLEN_IN][7];
		/* 变动流水 */
	int     aiSeqNbr[PICK_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[PICK_TASK_PARAM_BUFLEN_IN];
		/* 群组标识 */
	int     aiGroupID[PICK_TASK_PARAM_BUFLEN_IN];
		/* 对端路径 */
	char    asOppPath[PICK_TASK_PARAM_BUFLEN_IN][81];
		/* 对端备份路径 */
	char    asOppBkupPath[PICK_TASK_PARAM_BUFLEN_IN][81];
		/* 主机IP */
	char    asIp[PICK_TASK_PARAM_BUFLEN_IN][17];
		/* 用户名 */
	char    asUserName[PICK_TASK_PARAM_BUFLEN_IN][21];
		/* 口令 */
	char    asPasswd[PICK_TASK_PARAM_BUFLEN_IN][21];
		/* 匹配模式 */
	char    asFilter[PICK_TASK_PARAM_BUFLEN_IN][21];
		/* 原始序号偏移 */
	int     aiSeqOff[PICK_TASK_PARAM_BUFLEN_IN];
		/* 原始序号长度 */
	int     aiSeqLen[PICK_TASK_PARAM_BUFLEN_IN];
		/* 删除类型 */
	char    asDeleteType[PICK_TASK_PARAM_BUFLEN_IN][2];
	int     aiChkDays[PICK_TASK_PARAM_BUFLEN_IN];

	char    asEffDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	char    asState[PICK_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	
};


/*单个结构申明*/
struct PickTaskParamStruct{

	struct PickTaskParamStruct *pNext;
	char	sSourceID[7];
	int     iSeqNbr;		/* 变动流水 */
	int     iParamID;		/* 参数标识 */
	int     iGroupID;		/* 群组标识 */
	char    sOppPath[81];		/* 对端路径 */
	char    sOppBkupPath[81];		/* 对端备份路径 */
	char    sIp[17];		/* 主机IP */
	char    sUserName[21];		/* 用户名 */
	char    sPasswd[21];		/* 口令 */
	char    sFilter[21];		/* 匹配模式 */
	int     iSeqOff;		/* 原始序号偏移 */
	int     iSeqLen;		/* 原始序号长度 */
	char    sDeleteType[2];		/* 删除类型 */
	int	iChkDays;
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];

	struct PickTaskParamStruct *pLoadNext;
};
/*批量数据动态从PICK_TASK_PARAM中用结构缓冲方式取数据*/
int EGetPickTaskParamToStruct(struct PickTaskParamStruct *p,
	struct PickTaskParamStructIn *pSource);
/**对表PICK_TASK_PARAM的链表释放函数**/
void DestroyPickTaskParam(struct PickTaskParamStruct *ptHead);
int InitPickTaskParam(struct PickTaskParamStruct **pptHead);


/* 输入结构缓冲申明*/
struct PrepTaskParamStructIn{

#ifndef PREP_TASK_PARAM_BUFLEN_IN
#define PREP_TASK_PARAM_BUFLEN_IN		300
#endif

	struct PrepTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[PREP_TASK_PARAM_BUFLEN_IN][7];
		/* 变动序号 */
	int     aiSeqNbr[PREP_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[PREP_TASK_PARAM_BUFLEN_IN];
		/* 群组标识 */
	int     aiGroupID[PREP_TASK_PARAM_BUFLEN_IN];
		/* 交换机标识 */
	char    asMsc[PREP_TASK_PARAM_BUFLEN_IN][16];
		/* 区号 */
	char    asAreaCode[PREP_TASK_PARAM_BUFLEN_IN][6];
		/* 公式文件 */
	char    asExprFile[PREP_TASK_PARAM_BUFLEN_IN][81];
		/* 模块 */
	char    asModule[PREP_TASK_PARAM_BUFLEN_IN][4];
	
	char    asSplit[PREP_TASK_PARAM_BUFLEN_IN][11];
	int     aiStartPos[PREP_TASK_PARAM_BUFLEN_IN];
	int     aiKeyLen[PREP_TASK_PARAM_BUFLEN_IN];
	char    asChkMod[PREP_TASK_PARAM_BUFLEN_IN][4];

	char    asUserType[PREP_TASK_PARAM_BUFLEN_IN][2];

	char    asEffDate[PREP_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[PREP_TASK_PARAM_BUFLEN_IN][15];
	char    asState[PREP_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[PREP_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[PREP_TASK_PARAM_BUFLEN_IN][15];
};


/*单个结构申明*/
struct PrepTaskParamStruct{

	struct PrepTaskParamStruct *pNext;
	char    sSourceID[7];
	int     iSeqNbr;		/* 变动序号 */
	int     iParamID;		/* 参数标识 */
	int     iGroupID;		/* 群组标识 */
	char    sMsc[16];		/* 交换机标识 */
	char    sAreaCode[6];		/* 区号 */
	char    sExprFile[81];		/* 公式文件 */
	char    sModule[4];		/* 模块 */

	char    sSplit[11];
	int     iStartPos;
	int     iKeyLen;
	char    sChkMod[4];
	char    sUserType[4];

	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct PrepTaskParamStruct *pLoadNext;
};

/*批量数据动态从PREP_TASK_PARAM中用结构缓冲方式取数据*/
int EGetPrepTaskParamToStruct(struct PrepTaskParamStruct *p,
	struct PrepTaskParamStructIn *pSource);
/**对表PREP_TASK_PARAM的链表释放函数**/
void DestroyPrepTaskParam(struct PrepTaskParamStruct *ptHead);
int InitPrepTaskParam(struct PrepTaskParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct PutTaskParamStructIn{

#ifndef PUT_TASK_PARAM_BUFLEN_IN
#define PUT_TASK_PARAM_BUFLEN_IN		300
#endif

	struct PutTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[PUT_TASK_PARAM_BUFLEN_IN][7];
		/* 变动序号 */
	int     aiSeqNbr[PUT_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[PUT_TASK_PARAM_BUFLEN_IN];
		/* 群组标识 */
	int     aiGroupID[PUT_TASK_PARAM_BUFLEN_IN];
		/* 对端路径 */
	char    asOppPath[PUT_TASK_PARAM_BUFLEN_IN][81];
		/* 主机IP */
	char    asIp[PUT_TASK_PARAM_BUFLEN_IN][17];
		/* 用户名 */
	char    asUserName[PUT_TASK_PARAM_BUFLEN_IN][21];
		/* 口令 */
	char    asPasswd[PUT_TASK_PARAM_BUFLEN_IN][21];
	
	char	asFilter[PUT_TASK_PARAM_BUFLEN_IN][21];
	int	aiSeqOff[PUT_TASK_PARAM_BUFLEN_IN];
	int	aiSeqLen[PUT_TASK_PARAM_BUFLEN_IN];
	char	asDeleteType[PUT_TASK_PARAM_BUFLEN_IN][2];
	int	aiChkDays[PUT_TASK_PARAM_BUFLEN_IN];

	char    asEffDate[PUT_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[PUT_TASK_PARAM_BUFLEN_IN][15];
	char    asState[PUT_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[PUT_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[PUT_TASK_PARAM_BUFLEN_IN][15];
};
/*单个结构申明*/
struct PutTaskParamStruct{

	struct PutTaskParamStruct *pNext;
	char	sSourceID[7];
	int     iSeqNbr;		/* 变动序号 */
	int     iParamID;		/* 参数标识 */
	int     iGroupID;		/* 群组标识 */
	char    sOppPath[81];		/* 对端路径 */
	char    sIp[17];		/* 主机IP */
	char    sUserName[21];		/* 用户名 */
	char    sPasswd[21];		/* 口令 */
	char	sFilter[21];
	int	iSeqOff;
	int	iSeqLen;
	char	sDeleteType[2];
	int	iChkDays;
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct PutTaskParamStruct *pLoadNext;
};
/*批量数据动态从PUT_TASK_PARAM中用结构缓冲方式取数据*/
int EGetPutTaskParamToStruct(struct PutTaskParamStruct *p,
	struct PutTaskParamStructIn *pSource);
/**对表PUT_TASK_PARAM的链表释放函数**/
void DestroyPutTaskParam(struct PutTaskParamStruct *ptHead);
int InitPutTaskParam(struct PutTaskParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct RcylTaskParamStructIn{

#ifndef RCYL_TASK_PARAM_BUFLEN_IN
#define RCYL_TASK_PARAM_BUFLEN_IN		300
#endif

	struct RcylTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[RCYL_TASK_PARAM_BUFLEN_IN][7];
	int     aiTaskSeqNbr[RCYL_TASK_PARAM_BUFLEN_IN];
	int     aiSeqNbr[RCYL_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[RCYL_TASK_PARAM_BUFLEN_IN];
		/* 表名字 */
	char    asTableName[RCYL_TASK_PARAM_BUFLEN_IN][31];
		/* 回退条件 */
	char    asCondition[RCYL_TASK_PARAM_BUFLEN_IN][61];
		/* 公式文件 */
	char    asExprFile[RCYL_TASK_PARAM_BUFLEN_IN][41];
		/* 分离模版 */
	char    asTemplateID[RCYL_TASK_PARAM_BUFLEN_IN][11];
		/* 分离串 */
	char    asSplitStr[RCYL_TASK_PARAM_BUFLEN_IN][11];
		/* 区号 */
	char    asVisitCode[RCYL_TASK_PARAM_BUFLEN_IN][10];
		/* 模块号 */
	char    asModule[RCYL_TASK_PARAM_BUFLEN_IN][4];
	char    asEffDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
	char    asState[RCYL_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
};
/*单个结构申明*/
struct RcylTaskParamStruct{

	struct RcylTaskParamStruct *pNext;
	char	sSourceID[7];
	int	iTaskSeqNbr;
	int	iSeqNbr;
	int     iParamID;		/* 参数标识 */
	char    sTableName[31];		/* 表名字 */
	char    sCondition[61];		/* 回退条件 */
	char    sExprFile[41];		/* 公式文件 */
	char    sTemplateID[11];		/* 分离模版 */
	char    sSplitStr[11];		/* 分离串 */
	char    sVisitCode[10];		/* 区号 */
	char    sModule[4];		/* 模块号 */
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct RcylTaskParamStruct *pLoadNext;
};
/*批量数据动态从RCYL_TASK_PARAM中用结构缓冲方式取数据*/
int EGetRcylTaskParamToStruct(struct RcylTaskParamStruct *p,
	struct RcylTaskParamStructIn *pSource);
/**对表RCYL_TASK_PARAM的链表释放函数**/
void DestroyRcylTaskParam(struct RcylTaskParamStruct *ptHead);
int InitRcylTaskParam(struct RcylTaskParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct RollTaskParamStructIn{

#ifndef ROLL_TASK_PARAM_BUFLEN_IN
#define ROLL_TASK_PARAM_BUFLEN_IN		300
#endif

	struct RollTaskParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[ROLL_TASK_PARAM_BUFLEN_IN][7];
	int     aiTaskSeqNbr[ROLL_TASK_PARAM_BUFLEN_IN];
	int     aiSeqNbr[ROLL_TASK_PARAM_BUFLEN_IN];
		/* 参数标识 */
	int     aiParamID[ROLL_TASK_PARAM_BUFLEN_IN];
		/* 表名字 */
	char    asTableName[ROLL_TASK_PARAM_BUFLEN_IN][31];
		/* 分离模版 */
	char    asTemplateID[ROLL_TASK_PARAM_BUFLEN_IN][11];
		/* 回退条件 */
	char    asCondition[ROLL_TASK_PARAM_BUFLEN_IN][61];
	char	asUserType[ROLL_TASK_PARAM_BUFLEN_IN][41];
	char	asSplitType[ROLL_TASK_PARAM_BUFLEN_IN][2];
	char	asVisitCode[ROLL_TASK_PARAM_BUFLEN_IN][10];
	char	asModule[ROLL_TASK_PARAM_BUFLEN_IN][4];
	char    asEffDate[ROLL_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[ROLL_TASK_PARAM_BUFLEN_IN][15];
	char    asState[ROLL_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[ROLL_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[ROLL_TASK_PARAM_BUFLEN_IN][15];
};


/*单个结构申明*/
struct RollTaskParamStruct{

	struct RollTaskParamStruct *pNext;
	char	sSourceID[7];
	int	iTaskSeqNbr;
	int	iSeqNbr;
	int     iParamID;		/* 参数标识 */
	char    sTableName[31];		/* 表名字 */
	char    sTemplateID[11];		/* 分离模版 */
	char    sCondition[61];		/* 回退条件 */
	char	sUserType[41];
	char	sSplitType[2];
	char	sVisitCode[10];
	char	sModule[4];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct RollTaskParamStruct *pLoadNext;
};
/*批量数据动态从ROLL_TASK_PARAM中用结构缓冲方式取数据*/
int EGetRollTaskParamToStruct(struct RollTaskParamStruct *p,
	struct RollTaskParamStructIn *pSource);
/**对表ROLL_TASK_PARAM的链表释放函数**/
void DestroyRollTaskParam(struct RollTaskParamStruct *ptHead);
int InitRollTaskParam(struct RollTaskParamStruct **pptHead);


/* 输入结构缓冲申明*/
struct AcctParamStructIn{

#ifndef ACCT_PARAM_BUFLEN_IN
#define ACCT_PARAM_BUFLEN_IN		300
#endif

	struct AcctParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[ACCT_PARAM_BUFLEN_IN][7];
		/* 群组标识 */
	int     aiGroupID[ACCT_PARAM_BUFLEN_IN];
		/* 类型 */
	char    asFileType[ACCT_PARAM_BUFLEN_IN][6];
	char    asOperType[ACCT_PARAM_BUFLEN_IN][4];
		/* 日期规则 */
	char    asDateRule[ACCT_PARAM_BUFLEN_IN][13];
		/* 源路径 */
	char    asSourcePath[ACCT_PARAM_BUFLEN_IN][81];
		/* 备份路径 */
	char    asBackPath[ACCT_PARAM_BUFLEN_IN][81];
		/* 匹配规则 */
	char    asFilter[ACCT_PARAM_BUFLEN_IN][21];
		/* 数据归属地区 */
	char    asBelongCode[ACCT_PARAM_BUFLEN_IN][6];
		/* 模块 */
	char    asModule[ACCT_PARAM_BUFLEN_IN][4];
	
	char    asState[ACCT_PARAM_BUFLEN_IN][2];
		/* 应用标识 */
	char    asAppID[ACCT_PARAM_BUFLEN_IN][11];
		/* 环节标识 */
	int     aiTacheID[ACCT_PARAM_BUFLEN_IN];
};
/*单个结构申明*/
struct AcctParamStruct{

	struct AcctParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	int     iGroupID;		/* 群组标识 */
	char    sFileType[6];		/* 类型 */
	char    sOperType[4];
	char    sDateRule[13];		/* 日期规则 */
	char    sSourcePath[81];		/* 源路径 */
	char    sBackPath[81];		/* 备份路径 */
	char    sFilter[21];		/* 匹配规则 */
	char    sBelongCode[6];		/* 数据归属地区 */
	char    sModule[4];		/* 模块 */
	char	sState[2];
	char    sAppID[11];		/* 应用标识 */
	int     iTacheID;		/* 环节标识 */
	struct AcctParamStruct *pLoadNext;
};
/*批量数据动态从ACCT_PARAM中用结构缓冲方式取数据*/
int EGetAcctParamToStruct(struct AcctParamStruct *p,
	struct AcctParamStructIn *pSource);
/**对表ACCT_PARAM的链表释放函数**/
void DestroyAcctParam(struct AcctParamStruct *ptHead);
int InitAcctParam(struct AcctParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct IntfParamStructIn{

#ifndef INTF_PARAM_BUFLEN_IN
#define INTF_PARAM_BUFLEN_IN		300
#endif

	struct IntfParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSourceID[INTF_PARAM_BUFLEN_IN][7];
		/* 群组标识 */
	int     aiGroupID[INTF_PARAM_BUFLEN_IN];
		/* 源路径 */
	char    asSourcePath[INTF_PARAM_BUFLEN_IN][81];
		/* 备份路径 */
	char    asBackPath[INTF_PARAM_BUFLEN_IN][81];
		/* 输出目录 */
	char    asNormalPath[INTF_PARAM_BUFLEN_IN][81];
		/* 模式 */
	char    asFilter[INTF_PARAM_BUFLEN_IN][21];
		/* 时延 */
	int     aiDelay[INTF_PARAM_BUFLEN_IN];
		/* 城市代码 */
	char    asCityCode[INTF_PARAM_BUFLEN_IN][4];
		/* 处理文件类型 */
	char    asFileType[INTF_PARAM_BUFLEN_IN][6];
	char	asState[INTF_PARAM_BUFLEN_IN][2];
	
	char	asAppID[INTF_PARAM_BUFLEN_IN][11];
	int     aiTacheID[INTF_PARAM_BUFLEN_IN];

};
/*单个结构申明*/
struct IntfParamStruct{

	struct IntfParamStruct *pNext;
	char    sSourceID[7];
	int     iGroupID;		/* 群组标识 */
	char    sSourcePath[81];		/* 源路径 */
	char    sBackPath[81];		/* 备份路径 */
	char    sNormalPath[81];		/* 输出目录 */
	char    sFilter[21];		/* 模式 */
	int     iDelay;		/* 时延 */
	char    sCityCode[4];		/* 城市代码 */
	char    sFileType[6];		/* 处理文件类型 */
	char	sState[2];
	char	sAppID[11];
	int	iTacheID;
	struct IntfParamStruct *pLoadNext;
};

/*批量数据动态从INTF_PARAM中用结构缓冲方式取数据*/
int EGetIntfParamToStruct(struct IntfParamStruct *p,
	struct IntfParamStructIn *pSource);
/**对表INTF_PARAM的链表释放函数**/
void DestroyIntfParam(struct IntfParamStruct *ptHead);
int InitIntfParam(struct IntfParamStruct **pptHead);
/* 输入结构缓冲申明*/
struct RcylParamStructIn{

#ifndef RCYL_PARAM_BUFLEN_IN
#define RCYL_PARAM_BUFLEN_IN		300
#endif

	struct RcylParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源标识 */
	char    asSourceID[RCYL_PARAM_BUFLEN_IN][7];
	int     aiTaskSeqNbr[INTF_PARAM_BUFLEN_IN];
		/* 表名 */
	char    asTableName[RCYL_PARAM_BUFLEN_IN][31];
		/* 回退条件 */
	char    asCondition[RCYL_PARAM_BUFLEN_IN][61];
		/* 公式文件 */
	char    asExprFile[RCYL_PARAM_BUFLEN_IN][41];
		/* 分离模版 */
	char    asTemplateID[RCYL_PARAM_BUFLEN_IN][11];
		/* 输出目录 */
	char    asNormalPath[RCYL_PARAM_BUFLEN_IN][81];
		/* 分离串 */
	char    asSplitStr[RCYL_PARAM_BUFLEN_IN][11];
		/* 区号 */
	char    asVisitCode[RCYL_PARAM_BUFLEN_IN][10];
		/* 模块号 */
	char    asModule[RCYL_PARAM_BUFLEN_IN][4];
		/* 输出文件类型 */
	char    asFileType[RCYL_PARAM_BUFLEN_IN][6];
	char	asAppID[INTF_PARAM_BUFLEN_IN][11];
	int     aiTacheID[INTF_PARAM_BUFLEN_IN];
	
};
/*单个结构申明*/
struct RcylParamStruct{

	struct RcylParamStruct *pNext;
	char    sSourceID[7];		/* 来源标识 */
	int     iTaskSeqNbr;
	char    sTableName[31];		/* 表名 */
	char    sCondition[61];		/* 回退条件 */
	char    sExprFile[41];		/* 公式文件 */
	char    sTemplateID[11];		/* 分离模版 */
	char    sNormalPath[81];		/* 输出目录 */
	char    sSplitStr[11];		/* 分离串 */
	char    sVisitCode[10];		/* 区号 */
	char    sModule[4];		/* 模块号 */
	char    sFileType[6];		/* 输出文件类型 */
	char    sAppID[11];		/* 应用标识 */
	int     iTacheID;		/* 环节标识 */
	struct RcylParamStruct *pLoadNext;
};
/*批量数据动态从RCYL_PARAM中用结构缓冲方式取数据*/
int EGetRcylParamToStruct(struct RcylParamStruct *p,
	struct RcylParamStructIn *pSource);
/**对表RCYL_PARAM的链表释放函数**/
void DestroyRcylParam(struct RcylParamStruct *ptHead);
int InitRcylParam(struct RcylParamStruct **pptHead);


/* 输入结构缓冲申明*/
struct RollParamStructIn{

#ifndef ROLL_PARAM_BUFLEN_IN
#define ROLL_PARAM_BUFLEN_IN		300
#endif

	struct RollParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[ROLL_PARAM_BUFLEN_IN][7];
	int     aiTaskSeqNbr[ROLL_PARAM_BUFLEN_IN];
		/* 输入表名 */
	char    asTableName[ROLL_PARAM_BUFLEN_IN][31];
		/* 回退条件 */
	char    asCondition[ROLL_PARAM_BUFLEN_IN][61];
	char	asUserType[ROLL_PARAM_BUFLEN_IN][41];
		/* 分离模版标识 */
	char    asTemplateID[ROLL_PARAM_BUFLEN_IN][11];
		/* 输出目录 */
	char    asNormalPath[ROLL_PARAM_BUFLEN_IN][81];
	char	asSplitType[ROLL_PARAM_BUFLEN_IN][2];
	char	asVisitCode[ROLL_PARAM_BUFLEN_IN][10];
	char	asModule[ROLL_PARAM_BUFLEN_IN][4];
		/* 输出文件类型 */
	char    asFileType[ROLL_PARAM_BUFLEN_IN][6];
		/* 应用标识 */
	char    asAppID[ROLL_PARAM_BUFLEN_IN][11];
		/* 环节标识 */
	int     aiTacheID[ROLL_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct RollParamStruct{

	struct RollParamStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	int     iTaskSeqNbr;
	char    sTableName[31];		/* 输入表名 */
	char    sCondition[61];		/* 回退条件 */
	char	sUserType[41];
	char    sTemplateID[11];		/* 分离模版标识 */
	char    sNormalPath[81];		/* 输出目录 */
	char	sSplitType[2];
	char	sVisitCode[10];
	char	sModule[4];
	char    sFileType[6];		/* 输出文件类型 */
	char    sAppID[11];		/* 应用标识 */
	int     iTacheID;		/* 环节标识 */
	struct RollParamStruct *pLoadNext;
};

/*批量数据动态从ROLL_PARAM中用结构缓冲方式取数据*/
int EGetRollParamToStruct(struct RollParamStruct *p,
	struct RollParamStructIn *pSource);
/**对表ROLL_PARAM的链表释放函数**/
void DestroyRollParam(struct RollParamStruct *ptHead);
int InitRollParam(struct RollParamStruct **pptHead);


/* 输入结构缓冲申明*/
struct SourceDescStructIn{

#ifndef SOURCE_DESC_BUFLEN_IN
#define SOURCE_DESC_BUFLEN_IN		300
#endif

	struct SourceDescStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 来源 */
	char    asSourceID[SOURCE_DESC_BUFLEN_IN][7];
	char    asSourceType[SOURCE_DESC_BUFLEN_IN][2];
		/* 说明 */
	char    asRemark[SOURCE_DESC_BUFLEN_IN][41];
		/* 本地网标识 */
	int     aiLatnID[SOURCE_DESC_BUFLEN_IN];
		/* 原文件模式 */
	char    asFilter[SOURCE_DESC_BUFLEN_IN][21];
		/* 来源文件类型 */
	char    asFileType[SOURCE_DESC_BUFLEN_IN][6];
		/* 流程标识 */
	int     aiFlowID[SOURCE_DESC_BUFLEN_IN];
};


/*单个结构申明*/
struct SourceDescStruct{

	struct SourceDescStruct *pNext;
	char    sSourceID[7];		/* 来源 */
	char    sSourceType[2];
	char    sRemark[41];		/* 说明 */
	int     iLatnID;		/* 本地网标识 */
	char    sFilter[21];		/* 源模式 */
	char    sFileType[6];		/* 来源文件类型 */
	int     iFlowID;		/* 流程标识 */
	struct SourceDescStruct *pLoadNext;
};
/*批量数据动态从SOURCE_DESC中用结构缓冲方式取数据*/
int EGetSourceDescToStruct(struct SourceDescStruct *p,
	struct SourceDescStructIn *pSource);
/**对表SOURCE_DESC的链表释放函数**/
void DestroySourceDesc(struct SourceDescStruct *ptHead);
int InitSourceDesc(struct SourceDescStruct **pptHead);


#endif
