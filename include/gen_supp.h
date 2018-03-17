#ifndef __GEN_SUPP_H__
#define __GEN_SUPP_H__

/*��Ҫ�޸ĵĽṹ��
TICKET_FIELD_RULE��TICKET_FIELD_VALUE��
TOLL_TARIFF��DISCT_RULE��TICKET_BASED_DISCT,EXPR_DEF*/
/*�����ṹ������ticket_field.h��tariff_disct.h��*/

/* ����ṹ��������*/
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
		/* MSC���� */
	char    asMsc[ACROSS_CELL_CODE_BUFLEN_IN][11];
		/* LAC���� */
	char    asLac[ACROSS_CELL_CODE_BUFLEN_IN][5];
		/* CELL���� */
	char    asCellID[ACROSS_CELL_CODE_BUFLEN_IN][5];
		/* ���� */
	char    asAcrossAreaCode[ACROSS_CELL_CODE_BUFLEN_IN][10];
		/* ���� */
	char    asRemark[ACROSS_CELL_CODE_BUFLEN_IN][61];
	
	char	asEffDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
	char	asExpDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
	char	asState[ACROSS_CELL_CODE_BUFLEN_IN][4];
	char	asStateDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
	char	asCreatedDate[ACROSS_CELL_CODE_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct AcrossCellCodeStruct{

	struct AcrossCellCodeStruct *pNext;
	int	iAcrossCodeID;
	int	iSeqNbr;
	char    sMsc[11];		/* MSC���� */
	char    sLac[5];		/* LAC���� */
	char    sCellID[5];		/* CELL���� */
	char    sAcrossAreaCode[10];		/* ���� */
	char    sRemark[61];		/* ���� */

	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];

	struct AcrossCellCodeStruct *pLoadNext;
};



/*�����ݵ�ȡ��*/
/*�������ݶ�̬��ACROSS_CELL_CODE���ýṹ���巽ʽȡ����*/
int EGetAcrossCellCodeToStruct(struct AcrossCellCodeStruct *p,
	struct AcrossCellCodeStructIn *pSource);
void DestroyAcrossCellCode(struct AcrossCellCodeStruct *ptHead);
int InitAcrossCellCode(struct AcrossCellCodeStruct **pptHead);

/* ����ṹ��������*/
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
		/* ���� */
	char    asAreaCode[AREA_CODE_DESC_BUFLEN_IN][10];
		/* ʡ������ */
	char    asCapitalAreaCode[AREA_CODE_DESC_BUFLEN_IN][10];
		/* ����ʡ���� */
	char    asProvinceName[AREA_CODE_DESC_BUFLEN_IN][41];
		/* ���� */
	char    asRemark[AREA_CODE_DESC_BUFLEN_IN][61];
		/* ��ͨ���д��� */
	char    asCityCode[AREA_CODE_DESC_BUFLEN_IN][4];
		/* ���Ҵ��� */
	char    asCountryCode[AREA_CODE_DESC_BUFLEN_IN][4];
	char    asType[AREA_CODE_DESC_BUFLEN_IN][2];
	char    asIpType[AREA_CODE_DESC_BUFLEN_IN][2];
	char    asTollType1[AREA_CODE_DESC_BUFLEN_IN][2];
	char    asTollType2[AREA_CODE_DESC_BUFLEN_IN][2];

};


/*�����ṹ����*/
struct AreaCodeDescStruct{

	struct AreaCodeDescStruct *pNext;
	char    sAreaCode[10];		/* ���� */
	char    sCapitalAreaCode[10];		/* ʡ������ */
	char    sProvinceName[41];		/* ����ʡ���� */
	char    sRemark[61];		/* ���� */
	char    sCityCode[4];		/* ��ͨ���д��� */
	char    sCountryCode[4];		/* ���Ҵ��� */
	char    sType[2];
	char	sIpType[2];
	char	sTollType1[2];
	char	sTollType2[2];
	struct AreaCodeDescStruct *pLoadNext;
};

/*�������ݶ�̬��AREA_CODE_DESC���ýṹ���巽ʽȡ����*/
int EGetAreaCodeDescToStruct(struct AreaCodeDescStruct *p,
	struct AreaCodeDescStructIn *pSource);
/**�Ա�AREA_CODE_DESC�������ͷź���**/
void DestroyAreaCodeDesc(struct AreaCodeDescStruct *ptHead);
int InitAreaCodeDesc(struct AreaCodeDescStruct **pptHead);


/*�����ṹ����*/
struct T130AreaCodeStruct{

	struct T130AreaCodeStruct *pNext;
	int     iHeadID;		/* ��ͷ��ʶ */
	int	iSeqNbr;
	char    sHead[12];		/* ��ͷ */
	int     iLen;		/* ƥ�䳤�� */
	char    sAreaCode[10];		/* ���� */
	char    sHeadType[2];		/* ��ͷ��� */	
	
	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct T130AreaCodeStruct *pLoadNext;
};

/* ����ṹ��������*/
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
		/* ��ͷ��ʶ */
	int     aiHeadID[T130_AREA_CODE_BUFLEN_IN];
	int	aiSeqNbr[T130_AREA_CODE_BUFLEN_IN];
		/* ��ͷ */
	char    asHead[T130_AREA_CODE_BUFLEN_IN][12];
		/* ƥ�䳤�� */
	int     aiLen[T130_AREA_CODE_BUFLEN_IN];
		/* ���� */
	char    asAreaCode[T130_AREA_CODE_BUFLEN_IN][10];
		/* ��ͷ��� */
	char    asHeadType[T130_AREA_CODE_BUFLEN_IN][2];	
	
	char	asEffDate[T130_AREA_CODE_BUFLEN_IN][15];
	char	asExpDate[T130_AREA_CODE_BUFLEN_IN][15];
	char	asState[T130_AREA_CODE_BUFLEN_IN][4];
	char	asStateDate[T130_AREA_CODE_BUFLEN_IN][15];
	char	asCreatedDate[T130_AREA_CODE_BUFLEN_IN][15];
};


/*�������ݶ�̬��T130_AREA_CODE���ýṹ���巽ʽȡ����*/
int EGetT130AreaCodeToStruct(struct T130AreaCodeStruct *p,
	struct T130AreaCodeStructIn *pSource);
/**�Ա�T130_AREA_CODE�������ͷź���**/
void DestroyT130AreaCode(struct T130AreaCodeStruct *ptHead);
int InitT130AreaCode(struct T130AreaCodeStruct **pptHead);


/*�����ṹ����*/
struct TrunkStruct{

	struct TrunkStruct *pNext;
	int     iTrunkID;		/* �м̱�ʶ */
	int     iSeqNbr;		/* �м̱䶯��ˮ */
	int     iTrunkTypeID;		/* �м�����ʶ */
	int     iSettCarrierID;		/* ��������ʶ */
	char    sOppAreaCode[10];		/* ���� */
	char    sDirection[2];		/* ���� */
	char    sMsc[11];		/* MSC���� */
	char    sTrunk[8];		/* �м̴��� */
	char    sTrunkName[61];		/* �м����� */
	
	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];

	struct TrunkStruct *pLoadNext;
};


/* ����ṹ��������*/
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
		/* �м̱�ʶ */
	int     aiTrunkID[TRUNK_BUFLEN_IN];
		/* �м̱䶯��ˮ */
	int     aiSeqNbr[TRUNK_BUFLEN_IN];
		/* �м�����ʶ */
	int     aiTrunkTypeID[TRUNK_BUFLEN_IN];
		/* ��������ʶ */
	int     aiSettCarrierID[TRUNK_BUFLEN_IN];
		/* ���� */
	char    asOppAreaCode[TRUNK_BUFLEN_IN][10];
		/* ���� */
	char    asDirection[TRUNK_BUFLEN_IN][2];
		/* MSC���� */
	char    asMsc[TRUNK_BUFLEN_IN][11];
		/* �м̴��� */
	char    asTrunk[TRUNK_BUFLEN_IN][8];
		/* �м����� */
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


/*�����ṹ����*/
struct MscStruct{

	struct MscStruct *pNext;
	char    sMsc[11];		/* MSC���� */
	char	sMscType[7];
	char    sAreaCode[10];		/* ���� */
	char    sRemark[61];		/* ���� */
	struct MscStruct *pLoadNext;
};
/* ����ṹ��������*/
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
		/* MSC���� */
	char    asMsc[MSC_BUFLEN_IN][11];
	char	asMscType[MSC_BUFLEN_IN][7];
		/* ���� */
	char    asAreaCode[MSC_BUFLEN_IN][10];
		/* ���� */
	char    asRemark[MSC_BUFLEN_IN][61];
};
/*�������ݶ�̬��MSC���ýṹ���巽ʽȡ����*/
int EGetMscToStruct(struct MscStruct *p,
	struct MscStructIn *pSource);
void DestroyMsc(struct MscStruct *ptHead);
int InitMsc(struct MscStruct **pptHead);


/*�����ṹ����*/
struct TelecomCarrierStruct{

	struct TelecomCarrierStruct *pNext;
	int	iHeadID;
	int	iSeqNbr;
	char    sMsc[11];		/* ����MSC */
	char    sImsiHead[12];		/* Imsi��ͷ */
	char    sCountryAreaCode[6];		/* ���Ҵ��� */
	char    sCountryFlag[2];		/* ���ҵ�����ʶ */
	
	char	sEffDate[15];
	char	sExpDate[15];
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	
	struct TelecomCarrierStruct *pLoadNext;
};
/* ����ṹ��������*/
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
		/* ����MSC */
	char    asMsc[TELECOM_CARRIER_BUFLEN_IN][11];
		/* Imsi��ͷ */
	char    asImsiHead[TELECOM_CARRIER_BUFLEN_IN][12];
		/* ���Ҵ��� */
	char    asCountryAreaCode[TELECOM_CARRIER_BUFLEN_IN][6];
		/* ���ҵ�����ʶ */
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

/* ����ṹ��������*/
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
		/* �ֶα�ʶ */
	int     aiFieldID[TICKET_FIELD_BUFLEN_IN];
		/* 'T'���������⻰���ʷ�,'S'�����ڻ�������,'*'������ */
	char    asFieldType[TICKET_FIELD_BUFLEN_IN][2];
		/* ��ȡ������ */
	char    asGetValueFun[TICKET_FIELD_BUFLEN_IN][61];
	
	int     aiFormatID[TICKET_FIELD_BUFLEN_IN];
	char    asDataType[TICKET_FIELD_BUFLEN_IN][2];
	char    asUseType[TICKET_FIELD_BUFLEN_IN][2];
		/* ���� */
	char    asRemark[TICKET_FIELD_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct TicketFieldStruct{

	struct TicketFieldStruct *pNext;
	int     iFieldID;		/* �ֶα�ʶ */
	char    sFieldType[2];		/* 'T'���������⻰���ʷ�,'S'�����ڻ�������,'*'������ */
	char    sGetValueFun[61];		/* ��ȡ������ */
	int     iFormatID;
	char    sDataType[2];
	char    sUseType[2];
	char    sRemark[41];		/* ���� */
	char	*pValue;
	struct TicketFieldStruct *pLoadNext;
};
int EGetTicketFieldToStruct(struct TicketFieldStruct *p,
	struct TicketFieldStructIn *pSource);
void DestroyTicketField(struct TicketFieldStruct *ptHead);
int InitTicketField(struct TicketFieldStruct **pptHead);

/* ����ṹ��������*/
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
		/* �����ʶ */
	int     aiRuleID[TICKET_FIELD_RULE_BUFLEN_IN];
		/* �ֶα�ʶ */
	int     aiFieldID[TICKET_FIELD_RULE_BUFLEN_IN];
		/* ���ȼ� */
	int     aiPriority[TICKET_FIELD_RULE_BUFLEN_IN];
		/* ���ñ�ʶ */
	int     aiID[TICKET_FIELD_RULE_BUFLEN_IN];
		/* 'S' ���е�ID��ʾ������������ķ����ʶ 'T'����ID��ʾ���⻰����ʽ���TARIFF_EXPR_ID 
*/
	char    asUseType[TICKET_FIELD_RULE_BUFLEN_IN][2];
		/* ƥ����� */
	char    asMethod[TICKET_FIELD_RULE_BUFLEN_IN][2];
		/* ���� */
	char    asRemark[TICKET_FIELD_RULE_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct TicketFieldRuleStruct{

	struct TicketFieldRuleStruct *pNext;
	int     iRuleID;		/* �����ʶ */
	int     iFieldID;		/* �ֶα�ʶ */
	int     iPriority;		/* ���ȼ� */
	int     iID;		/* ���ñ�ʶ */
	char    sUseType[2];		
/* 'S' ���е�ID��ʾ������������ķ����ʶ 'T'����ID��ʾ���⻰��
��ʽ���TARIFF_EXPR_ID */
	char    sMethod[2];		/* ƥ����� */
	char    sRemark[41];		/* ���� */
	struct TicketFieldRuleStruct *pLoadNext;

/*---------�ֹ����ӵ�һ���Ա��ʼ------------------------*/
	struct TicketFieldStruct *pTicketField;
	void 	*pData;
	void *  (*GetTicketField)();	/*ȡƥ��ֵ����*/
	int	(*SearchRule)(void *,void *);/*����ƥ���㷨*/
/*---------�ֹ����ӵ�һ���Ա����------------------------*/
};
int EGetTicketFieldRuleToStruct(struct TicketFieldRuleStruct *p,
	struct TicketFieldRuleStructIn *pSource);
void DestroyTicketFieldRule(struct TicketFieldRuleStruct *ptHead);
int InitTicketFieldRule(struct TicketFieldRuleStruct **pptHead);

/* ����ṹ��������*/
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
		/* ������� */
	int     aiSeq[TICKET_FIELD_VALUE_BUFLEN_IN];
		/* �����ʶ */
	int     aiRuleID[TICKET_FIELD_VALUE_BUFLEN_IN];
		/* ��ֵ */
	char    asValue[TICKET_FIELD_VALUE_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct TicketFieldValueStruct{

	struct TicketFieldValueStruct *pNext;
	int     iSeq;		/* ������� */
	int     iRuleID;		/* �����ʶ */
	char    sValue[41];		/* ��ֵ */
	struct TicketFieldValueStruct *pLoadNext;
	
/*---------�ֹ����ӵ�һ���Ա��ʼ------------------------*/
	int	iValueLen;	
	int	iValue;
/*---------�ֹ����ӵ�һ���Ա����------------------------*/
	
};
int EGetTicketFieldValueToStruct(struct TicketFieldValueStruct *p,
	struct TicketFieldValueStructIn *pSource);
void DestroyTicketFieldValue(struct TicketFieldValueStruct *ptHead);
int InitTicketFieldValue(struct TicketFieldValueStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��������ʶ */
	int     aiSplitRuleID[SPLIT_RULE_BUFLEN_IN];
		/* ����ģ���ʶ */
	int     aiTemplateRuleID[SPLIT_RULE_BUFLEN_IN];
		/* �������ȼ� */
	int     aiPriority[SPLIT_RULE_BUFLEN_IN];
		/* 'B'������,'S'������ */
	char    asSplitType[SPLIT_RULE_BUFLEN_IN][2];
		/* ��������ʶ */
	int     aiTicketTypeID[SPLIT_RULE_BUFLEN_IN];
		/* 0������ 1 Ҫ���� */
	int     aiTariffFlag[SPLIT_RULE_BUFLEN_IN];
	int     aiLay[SPLIT_RULE_BUFLEN_IN];
	char    asLeaveFlag[SPLIT_RULE_BUFLEN_IN][2];
	int     aiParentID[SPLIT_RULE_BUFLEN_IN];
		/* ���� */
	char    asRemark[SPLIT_RULE_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct SplitRuleStruct{

	struct SplitRuleStruct *pNext;
	int     iSplitRuleID;		/* ��������ʶ */
	int     iTemplateRuleID;		/* ����ģ���ʶ */
	int     iPriority;		/* �������ȼ� */
	char    sSplitType[2];		/* 'B'������,'S'������ */
	int     iTicketTypeID;		/* ��������ʶ */
	int     iTariffFlag;		/* 0������ 1 Ҫ���� */
	int	iLay;
	char    sLeaveFlag[2];
	int	iParentID;
	char    sRemark[41];		/* ���� */
	struct SplitRuleStruct *pChild;	 /*�ӽڵ�*/
	struct SplitRuleStruct *pLoadNext;
};
int EGetSplitRuleToStruct(struct SplitRuleStruct *p,
	struct SplitRuleStructIn *pSource);
void DestroySplitRule(struct SplitRuleStruct *ptHead);
int InitSplitRule(struct SplitRuleStruct **pptHead);

/* ����ṹ��������*/
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
		/* Ψһ�Ա�ʶ */
	int     aiTariffID[TOLL_TARIFF_BUFLEN_IN];
	int	aiSeqNbr[TOLL_TARIFF_BUFLEN_IN];
	char	asTariffRef[TOLL_TARIFF_BUFLEN_IN][21];
		/* �ʷ����� */
	char    asTollType[TOLL_TARIFF_BUFLEN_IN][3];
		/* �Ƕ��ʷѵĻ���'���������ʷ�','��;�ʷ�','�����ʷ�' */
	char    asTariffType[TOLL_TARIFF_BUFLEN_IN][3];
	char    asFieldType[TOLL_TARIFF_BUFLEN_IN][2];
	int	aiLatnID[TOLL_TARIFF_BUFLEN_IN];
		/* �����ƴε����� */
	int     aiSecPerCnt[TOLL_TARIFF_BUFLEN_IN];
		/* ���� */
	int     aiRate[TOLL_TARIFF_BUFLEN_IN];
		/* ���ʾ�ȷ��λ�� */
	int     aiRatePrecision[TOLL_TARIFF_BUFLEN_IN];
		/* ����ʱ��ȷ��λ�� */
	int     aiCalcPrecision[TOLL_TARIFF_BUFLEN_IN];
		/* ���� */
	char    asRemark[TOLL_TARIFF_BUFLEN_IN][61];
		/* ��Чʱ�� */
	char    asEffDate[TOLL_TARIFF_BUFLEN_IN][15];
		/* ʧЧʱ�� */
	char    asExpDate[TOLL_TARIFF_BUFLEN_IN][15];
	char	asState[TOLL_TARIFF_BUFLEN_IN][4];
	char	asStateDate[TOLL_TARIFF_BUFLEN_IN][15];
	char	asCreatedDate[TOLL_TARIFF_BUFLEN_IN][15];

};


/*�����ṹ����*/
struct TollTariffStruct{
	struct TollTariffStruct *pNext;
	struct TollTariffStruct *pSeqNext;	/*���TOLLTARIFFָ������NXT*/
	int     iTariffID;		/* Ψһ�Ա�ʶ */
	int	iSeqNbr;
	char	sTariffRef[21];
	char    sTollType[3];		/* �ʷ����� */
	char    sTariffType[3];		/* �Ƕ��ʷѵĻ���'���������ʷ�','��;�ʷ�','�����ʷ�' */
	char    sFieldType[2];		
	int	iLatnID;
	int     iSecPerCnt;		/* �����ƴε����� */
	int     iRate;		/* ���� */
	int     iRatePrecision;		/* ���ʾ�ȷ��λ�� */
	int     iCalcPrecision;		/* ����ʱ��ȷ��λ�� */
	char    sRemark[61];		/* ���� */
	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct TollTariffStruct *pLoadNext;
	
	int	iTollType;	
	int	iTariffType;

	time_t  tEffDate;		
	time_t  tExpDate;
	
	time_t	tBeginTime;		/*�ʷѻ�����ʼ	
					����ʱ�����ʷ�ʱ�佻��{��ǰ} */
	time_t	tEndTime;		/* �ʷѻ�����ֹ */
	
	int	iCounts;		/* �ƷѴ��� */
	
	int	iAcctItemTypeID;	/*�Ʒ���Ŀ����*/
	int	iFee;			/* ��������*/	
	int	iDisctFee;		/* �����Żݴ��۵��ķ���*/
	int	iTicketItemTypeID;	/*�Żݺ�����������Ŀ*/
	
	struct DisctRuleStruct	*pDisctRule;	
		/*���ʷѶ�Ӧ���Żݹ���,InitTollTariffList��������ȥ��*/
	struct TollTariffStruct *pCurNext;	/*��ŵ�ǰ���̵��ʷ��б�*/
	struct TollTariffStruct *pTariffNext;	/*��pNext���ʹ�ã��������*/
};
int EGetTollTariffToStruct(struct TollTariffStruct *p,
	struct TollTariffStructIn *pSource);
void DestroyTollTariff(struct TollTariffStruct *ptHead);
int InitTollTariff(struct TollTariffStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��ʽ��ʶ */
	int     aiExprID[EXPR_DEF_BUFLEN_IN];
		/* ��ʽ��� */
	char    asExprType[EXPR_DEF_BUFLEN_IN][3];
		/* ������,�����,ʹ����,ע�� */
	char    asState[EXPR_DEF_BUFLEN_IN][4];
		/* ���� */
	char    asRemark[EXPR_DEF_BUFLEN_IN][61];
		/* ��ʽ���ʽ */
	char    asExpr[EXPR_DEF_BUFLEN_IN][4001];
		/* ����˵�� */
	char    asComments[EXPR_DEF_BUFLEN_IN][101];
		/* ��������ʶ */
	int     aiLatnID[EXPR_DEF_BUFLEN_IN];
};


/*�����ṹ����*/
struct ExprDefStruct{

	struct ExprDefStruct *pNext;
	int     iExprID;		/* ��ʽ��ʶ */
	char    sExprType[3];		/* ��ʽ��� */
	char    sState[4];		/* ������,�����,ʹ����,ע�� */
	char    sRemark[61];		/* ���� */
	char    sExpr[4001];		/* ��ʽ���ʽ */
	char    sComments[101];		/* ����˵�� */
	int     iLatnID;		/* ��������ʶ */
	struct ExprDefStruct *pLoadNext;
/**�޸Ŀ�ʼ**/
	int	iCompileFlag;
	int	iPriority;
	char	sParam[41];
	struct	ExprBufStruct *pExprBuf;
/**�޸Ľ���*/
	
};
int EGetExprDefToStruct(struct ExprDefStruct *p,
	struct ExprDefStructIn *pSource);
void DestroyExprDef(struct ExprDefStruct *ptHead);
int InitExprDef(struct ExprDefStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��ʽ�Żݱ�ʶ */
	int     aiExprDisctID[EXPR_DISCT_BUFLEN_IN];
		/* ��ʽ��ʶ */
	int     aiExprID[EXPR_DISCT_BUFLEN_IN];
		/* �Żݹ����ʶ */
	int     aiDisctRuleID[EXPR_DISCT_BUFLEN_IN];
		/* ���ȼ���0������� 1����� */
	int     aiPriority[EXPR_DISCT_BUFLEN_IN];
		/* ���� */
	char    asRemark[EXPR_DISCT_BUFLEN_IN][101];
		/* ��ʽ���� */
	char    asParam[EXPR_DISCT_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct ExprDisctStruct{

	struct ExprDisctStruct *pNext;
	int     iExprDisctID;		/* ��ʽ�Żݱ�ʶ */
	int     iExprID;		/* ��ʽ��ʶ */
	int     iDisctRuleID;		/* �Żݹ����ʶ */
	int     iPriority;		/* ���ȼ���0������� 1����� */
	char    sRemark[101];		/* ���� */
	char    sParam[41];		/* ��ʽ���� */
	struct ExprDisctStruct *pLoadNext;
};
int EGetExprDisctToStruct(struct ExprDisctStruct *p,
	struct ExprDisctStructIn *pSource);
void DestroyExprDisct(struct ExprDisctStruct *ptHead);
int InitExprDisct(struct ExprDisctStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��ͷ */
	char    asHead[HEAD_CARR_BUFLEN_IN][16];
		/* ���� */
	char    asAreaCode[HEAD_CARR_BUFLEN_IN][6];
	
	int     aiAreaID[HEAD_CARR_BUFLEN_IN];
	int     aiSettAreaID[HEAD_CARR_BUFLEN_IN];
		/* ��������ʶ */
	int     aiSettCarrierID[HEAD_CARR_BUFLEN_IN];
		/* ����ʶ */
	int     aiTypeID[HEAD_CARR_BUFLEN_IN];
	
	char    asType[HEAD_CARR_BUFLEN_IN][2];
		/* ƥ�䳤�� */
	int     aiLen[HEAD_CARR_BUFLEN_IN];
		/* ���� */
	char    asRemark[HEAD_CARR_BUFLEN_IN][61];
	
	char	asEffDate[HEAD_CARR_BUFLEN_IN][15];
	char	asExpDate[HEAD_CARR_BUFLEN_IN][15];
	char	asState[HEAD_CARR_BUFLEN_IN][4];
	char	asStateDate[HEAD_CARR_BUFLEN_IN][15];
	char	asCreatedDate[HEAD_CARR_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct HeadCarrStruct{

	struct HeadCarrStruct *pNext;
	
	int	iHeadID;
	int	iSeqNbr;

	char    sHead[16];		/* ��ͷ */
	char    sAreaCode[6];		/* ���� */
	int	iAreaID;		
	int	iSettAreaID;
	int     iSettCarrierID;		/* ��������ʶ */
	int     iTypeID;		/* ����ʶ */
	char	sType[2];
	int     iLen;		/* ƥ�䳤�� */	
	char    sRemark[61];		/* ���� */

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

/* ����ṹ��������*/
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
		/* �굥�Żݱ�ʶ */
	int     aiTicketBasedDisctID[TICKET_BASED_DISCT_BUFLEN_IN];
		/* �Żݹ����ʶ */
	int     aiDisctRuleID[TICKET_BASED_DISCT_BUFLEN_IN];
		/* ʱ�䵥λ */
	char    asUnit[TICKET_BASED_DISCT_BUFLEN_IN][3];
		/* ����ƫ������ */
	int     aiOffset1[TICKET_BASED_DISCT_BUFLEN_IN];
		/* �������� */
	int     aiDuration1[TICKET_BASED_DISCT_BUFLEN_IN];
		/* ÿ��ƫ���� */
	char    asOffset2[TICKET_BASED_DISCT_BUFLEN_IN][7];
		/* �������� */
	int     aiDuration2[TICKET_BASED_DISCT_BUFLEN_IN];
		/* �Żݷ��� */
	char    asMethod[TICKET_BASED_DISCT_BUFLEN_IN][3];
		/* �Żݱ��� */
	int     aiRate[TICKET_BASED_DISCT_BUFLEN_IN];
		/* ���ȼ��� */
	int     aiPriority[TICKET_BASED_DISCT_BUFLEN_IN];
		/* ��Чʱ�� */
	char    asEffDate[TICKET_BASED_DISCT_BUFLEN_IN][15];
		/* ʧЧʱ�� */
	char    asExpDate[TICKET_BASED_DISCT_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct TicketBasedDisctStruct{

	struct TicketBasedDisctStruct *pNext;
	int     iTicketBasedDisctID;		/* �굥�Żݱ�ʶ */
	int     iDisctRuleID;		/* �Żݹ����ʶ */
	char    sUnit[3];		/* ʱ�䵥λ */
	int     iOffset1;		/* ����ƫ������ */
	int     iDuration1;		/* �������� */
	char    sOffset2[7];		/* ÿ��ƫ���� */
	int     iDuration2;		/* �������� */
	char    sMethod[3];		/* �Żݷ��� */
	int     iRate;		/* �Żݱ��� */
	int     iPriority;		/* ���ȼ��� */

	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */

	struct TicketBasedDisctStruct *pLoadNext;

/***�޸Ŀ�ʼ*******/	
	int	iMethod;
	int	iUnit;				/* ֻ֧���ܺ��� */
	time_t	tBaseTime;			/* ��׼���� */
	
	int	iBeginDate;			/* �������տ�ʼ���� */
	int	iEndDate;			/* ����������ֹ���� */	
	
	int	iBeginTime;			/* ������Ч��ʼ���� */
	int	iEndTime;			/* ������Ч��ֹ���� */

	time_t  tEffDate;			/*��Ч��ʼʱ��*/
	time_t  tExpDate;			/*��Ч����ʱ��*/
	
	time_t  tYear;
	int	iUnitOri;
/***�޸Ľ���**/

};
int EGetTicketBasedDisctToStruct(struct TicketBasedDisctStruct *p,
	struct TicketBasedDisctStructIn *pSource);
void DestroyTicketBasedDisct(struct TicketBasedDisctStruct *ptHead);
int InitTicketBasedDisct(struct TicketBasedDisctStruct **pptHead);


/* ����ṹ��������*/
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
		/* ��������ʶ */
	int     aiTicketTypeID[TICKET_TYPE_BUFLEN_IN];
	char	asTariffType[TICKET_TYPE_BUFLEN_IN][3];
	char	asFeeType[TICKET_TYPE_BUFLEN_IN][5];
		/* ��������ʶ */
	int     aiSettCarrierID[TICKET_TYPE_BUFLEN_IN];
		/* ������� */
	char    asSplitType[TICKET_TYPE_BUFLEN_IN][2];
	char    asServType[TICKET_TYPE_BUFLEN_IN][5];
	int	aiFormatID[TICKET_TYPE_BUFLEN_IN];
		/* �����˹��ڷ�����ϸ�������,�͵��ŷ�����𡢳��ص��ŷ������λ�á����д����й� */
	char    asRemark[TICKET_TYPE_BUFLEN_IN][81];
};


/*�����ṹ����*/
struct TicketTypeStruct{

	struct TicketTypeStruct *pNext;
	int     iTicketTypeID;		/* ��������ʶ */
	char	sTariffType[3];
	char	sFeeType[5];
	int     iSettCarrierID;		/* ��������ʶ */
	char    sSplitType[2];		/* ������� */
	char	sServType[5];
	int	iFormatID;
	char    sRemark[81];		/* �����˹��ڷ�����ϸ�������,�͵��ŷ�����𡢳��ص��ŷ������
λ�á����д����й� */
	struct TicketTypeStruct *pLoadNext;
};
int EGetTicketTypeToStruct(struct TicketTypeStruct *p,
	struct TicketTypeStructIn *pSource);
void DestroyTicketType(struct TicketTypeStruct *ptHead);
int InitTicketType(struct TicketTypeStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��������ʶ */
	int     aiTicketTypeID[TICKET_TYPE_TARIFF_BUFLEN_IN];
		/* Ψһ�Ա�ʶ */
	int     aiTariffID[TICKET_TYPE_TARIFF_BUFLEN_IN];
		/* ��ϵ״̬ */
	char    asState[TICKET_TYPE_TARIFF_BUFLEN_IN][4];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[TICKET_TYPE_TARIFF_BUFLEN_IN];
};


/*�����ṹ����*/
struct TicketTypeTariffStruct{

	struct TicketTypeTariffStruct *pNext;
	int     iTicketTypeID;		/* ��������ʶ */
	int     iTariffID;		/* Ψһ�Ա�ʶ */
	char    sState[4];		/* ��ϵ״̬ */
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	struct TicketTypeTariffStruct *pLoadNext;
};
int EGetTicketTypeTariffToStruct(struct TicketTypeTariffStruct *p,
	struct TicketTypeTariffStructIn *pSource);
void DestroyTicketTypeTariff(struct TicketTypeTariffStruct *ptHead);
int InitTicketTypeTariff(struct TicketTypeTariffStruct **pptHead);

/* ����ṹ��������*/
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
		/* �ֽ׶��Żݱ�ʶ */
	int     aiTimeSpanDisctID[TIME_SPAN_DISCT_BUFLEN_IN];
		/* �Żݹ����ʶ */
	int     aiDisctRuleID[TIME_SPAN_DISCT_BUFLEN_IN];
		/* ���ȼ��� */
	int     aiPriority[TIME_SPAN_DISCT_BUFLEN_IN];
		/* �ۿ����ÿ�ʼ�� */
	int     aiOffset1[TIME_SPAN_DISCT_BUFLEN_IN];
		/* �ۿ����ó������� */
	int     aiDuration1[TIME_SPAN_DISCT_BUFLEN_IN];
		/* ����ʱ�������� */
	int     aiCycle[TIME_SPAN_DISCT_BUFLEN_IN];
		/* ����ʱ����ƫ�Ʒ��� */
	int     aiOffset2[TIME_SPAN_DISCT_BUFLEN_IN];
		/* ���ڳ���ʱ������λ���� */
	int     aiDuration2[TIME_SPAN_DISCT_BUFLEN_IN];
		/* �Żݷ�������̶����ʣ��ۿۡ� */
	char    asMethod[TIME_SPAN_DISCT_BUFLEN_IN][3];
		/* ���� */
	int     aiRate[TIME_SPAN_DISCT_BUFLEN_IN];
};


/*�����ṹ����*/
struct TimeSpanDisctStruct{

	struct TimeSpanDisctStruct *pNext;
	int     iTimeSpanDisctID;		/* �ֽ׶��Żݱ�ʶ */
	int     iDisctRuleID;		/* �Żݹ����ʶ */
	int     iPriority;		/* ���ȼ��� */
	int     iOffset1;		/* �ۿ����ÿ�ʼ�� */
	int     iDuration1;		/* �ۿ����ó������� */
	int     iCycle;		/* ����ʱ�������� */
	int     iOffset2;		/* ����ʱ����ƫ�Ʒ��� */
	int     iDuration2;		/* ���ڳ���ʱ������λ���� */
	char    sMethod[3];		/* �Żݷ�������̶����ʣ��ۿۡ� */
	int     iRate;		/* ���� */
	struct TimeSpanDisctStruct *pLoadNext;
};
int EGetTimeSpanDisctToStruct(struct TimeSpanDisctStruct *p,
	struct TimeSpanDisctStructIn *pSource);
void DestroyTimeSpanDisct(struct TimeSpanDisctStruct *ptHead);
int InitTimeSpanDisct(struct TimeSpanDisctStruct **pptHead);

/* ����ṹ��������*/
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
		/* �Żݹ����ʶ */
	int     aiDisctRuleID[DISCT_RULE_BUFLEN_IN];
		/* 00�������ֽ׶��Żݡ�01������ʱ���Żݡ�10�ʵ���һ���Żݡ�  11�ʵ������Ż� */
	char    asDisctType[DISCT_RULE_BUFLEN_IN][3];
		/* �Ż���Դ��ʶ�����Żݹ������Ե��Ż�Э���ʶ���Ż��ļ���ʶ�ȡ� */
	int	aiTariffID[DISCT_RULE_BUFLEN_IN];
	int	aiSeqNbr[DISCT_RULE_BUFLEN_IN];
	int     aiSourceID[DISCT_RULE_BUFLEN_IN];
		/* ��������ʶ */
	int     aiLatnID[DISCT_RULE_BUFLEN_IN];
		/* ���ȼ� */
	int     aiPriority[DISCT_RULE_BUFLEN_IN];
		/* ��Чʱ�� */
	char    asEffDate[DISCT_RULE_BUFLEN_IN][15];
		/* ʧЧʱ�� */
	char    asExpDate[DISCT_RULE_BUFLEN_IN][15];
		/* �������� */
	char    asRuleName[DISCT_RULE_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct DisctRuleStruct{

	struct DisctRuleStruct *pNext;	/*�����Ż�*/
	int     iDisctRuleID;		/* �Żݹ����ʶ */
	char    sDisctType[3];		/* 00�������ֽ׶��Żݡ�01������ʱ���Żݡ�10�ʵ���һ���Żݡ�  11�ʵ������Ż� */
	int	iTariffID;		/* �ʷѱ�ʶ������*/
	int	iSeqNbr;
	int     iSourceID;		/* �Ż���Դ��ʶ�����Żݹ������Ե��Ż�Э���ʶ���Ż��ļ���ʶ�ȡ� */
	int     iLatnID;		/* ��������ʶ */
	int     iPriority;		/* ���ȼ� */
	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */
	char    sRuleName[41];		/* �������� */
	struct DisctRuleStruct *pLoadNext;
	
	int	iDisctType;	
	time_t	tEffDate;
	time_t	tExpDate;
	
	int     iSecPerCnt;		/* �����ƴε����� */
	int	iCounts;		/* ����*/
	int     iRate;			/* ���� */
	int     iRatePrecision;		/* ���ʾ�ȷ��λ�� */
	int     iCalcPrecision;		/* ����ʱ��ȷ��λ�� */
	int	iFee;			/* ��������*/	
	int	iDisctFee;		/* �����Żݴ��۵��ķ���*/
	
	time_t	tBeginTime;
	time_t	tEndTime;
	
	void (*Disct)(struct DisctRuleStruct *);
	
	int	iMutex;		/*0��ʾû�б��ų⣬1��ʾ���ų�*/
	struct	DisctRuleMutexStruct *pMutex;
	void	*pDisct;
	struct DisctRuleStruct *pTariffNext;/*����TOLL_TARIFF�µĶ���*/
	struct DisctRuleStruct *pCurNext;/*��ŵ�ǰ���̵��Żݹ�������*/
};



int EGetDisctRuleToStruct(struct DisctRuleStruct *p,
	struct DisctRuleStructIn *pSource);
void DestroyDisctRule(struct DisctRuleStruct *ptHead);
int InitDisctRule(struct DisctRuleStruct **pptHead);

/* ����ṹ��������*/
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
		/* MSC���� */
	char    asMsc[CELL_CODE_BUFLEN_IN][11];
		/* LAC���� */
	char    asLac[CELL_CODE_BUFLEN_IN][5];
		/* CELL���� */
	char    asCellID[CELL_CODE_BUFLEN_IN][5];
		/* �������� */
	char    asAreaCode[CELL_CODE_BUFLEN_IN][6];
		/* ���� */
	char    asRemark[CELL_CODE_BUFLEN_IN][61];
	
	char	asEffDate[CELL_CODE_BUFLEN_IN][15];
	char	asExpDate[CELL_CODE_BUFLEN_IN][15];
	char	asState[CELL_CODE_BUFLEN_IN][4];
	char	asStateDate[CELL_CODE_BUFLEN_IN][15];
	char	asCreatedDate[CELL_CODE_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct CellCodeStruct{

	struct CellCodeStruct *pNext;
	int	iCellCodeID;
	int	iSeqNbr;
	char    sMsc[11];		/* MSC���� */
	char    sLac[5];		/* LAC���� */
	char    sCellID[5];		/* CELL���� */
	char    sAreaCode[6];		/* �������� */
	char    sRemark[61];		/* ���� */
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

/* ����ṹ��������*/
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
		/* �Żݹ����ʶ */
	int     aiDisctRuleID[DISCT_RULE_MUTEX_BUFLEN_IN];
		/* �ų��Żݹ��� */
	int     aiExcludeDisctRuleID[DISCT_RULE_MUTEX_BUFLEN_IN];
};


/*�����ṹ����*/
struct DisctRuleMutexStruct{

	struct DisctRuleMutexStruct *pNext;
	int     iDisctRuleID;		/* �Żݹ����ʶ */
	int     iExcludeDisctRuleID;		/* �ų��Żݹ��� */
	struct DisctRuleMutexStruct *pLoadNext;
};
int EGetDisctRuleMutexToStruct(struct DisctRuleMutexStruct *p,
	struct DisctRuleMutexStructIn *pSource);
void DestroyDisctRuleMutex(struct DisctRuleMutexStruct *ptHead);
int InitDisctRuleMutex(struct DisctRuleMutexStruct **pptHead);


/* ����ṹ��������*/
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
		/* ��� */
	int     aiGroupID[DISP_PARAM_BUFLEN_IN];
		/* ����ԴĿ¼ */
	char    asSourcePath[DISP_PARAM_BUFLEN_IN][81];
	char	asFilter[DISP_PARAM_BUFLEN_IN][21];
		/* ����Ŀ��Ŀ¼1 */
	char    asDestPath1[DISP_PARAM_BUFLEN_IN][81];
		/* ����Ŀ��Ŀ¼2 */
	char    asDestPath2[DISP_PARAM_BUFLEN_IN][81];
		/* ����Ŀ��Ŀ¼3 */
	char    asDestPath3[DISP_PARAM_BUFLEN_IN][81];
		/* ����Ŀ��Ŀ¼4 */
	char    asDestPath4[DISP_PARAM_BUFLEN_IN][81];
		/* ����ͣ״̬ */
	char    asState[DISP_PARAM_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct DispParamStruct{

	struct DispParamStruct *pNext;
	int     iGroupID;		/* ��� */
	char    sSourcePath[81];	/* ����ԴĿ¼ */
	char	sFilter[21];
	char    sDestPath1[81];		/* ����Ŀ��Ŀ¼1 */
	char    sDestPath2[81];		/* ����Ŀ��Ŀ¼2 */
	char    sDestPath3[81];		/* ����Ŀ��Ŀ¼3 */
	char    sDestPath4[81];		/* ����Ŀ��Ŀ¼4 */
	char    sState[2];		/* ����ͣ״̬ */
	struct DispParamStruct *pLoadNext;
};

/*�������ݶ�̬��DISP_PARAM���ýṹ���巽ʽȡ����*/
int EGetDispParamToStruct(struct DispParamStruct *p,
	struct DispParamStructIn *pSource);
/**�Ա�DISP_PARAM�������ͷź���**/
void DestroyDispParam(struct DispParamStruct *ptHead);
int InitDispParam(struct DispParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[INST_PARAM_BUFLEN_IN][7];
		/* Ⱥ���ʶ */
	int     aiGroupID[INST_PARAM_BUFLEN_IN];
		/* ���� */
	char    asFileType[INST_PARAM_BUFLEN_IN][6];
	char    asOperType[INST_PARAM_BUFLEN_IN][4];
		/* ���ڹ��� */
	char    asDateRule[INST_PARAM_BUFLEN_IN][13];
		/* Դ·�� */
	char    asSourcePath[INST_PARAM_BUFLEN_IN][81];
		/* ƥ����� */
	char    asFilter[INST_PARAM_BUFLEN_IN][21];
		/* ����·�� */
	char    asBackPath[INST_PARAM_BUFLEN_IN][81];
		/* ���ݹ������� */
	char    asBelongCode[INST_PARAM_BUFLEN_IN][6];
		/* ģ�� */
	char    asModule[INST_PARAM_BUFLEN_IN][4];
		/* ��ͣ״̬ */
	char    asState[INST_PARAM_BUFLEN_IN][2];
		/* Ӧ�ñ�ʶ */
	char    asAppID[INST_PARAM_BUFLEN_IN][11];
		/* ���ڱ�ʶ */
	int     aiTacheID[INST_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct InstParamStruct{

	struct InstParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sFileType[6];		/* ���� */
	char    sOperType[4];
	char    sDateRule[13];		/* ���ڹ��� */
	char    sSourcePath[81];		/* Դ·�� */
	char    sFilter[21];		/* ƥ����� */
	char    sBackPath[81];		/* ����·�� */
	char    sBelongCode[6];		/* ���ݹ������� */
	char    sModule[4];		/* ģ�� */
	char    sState[2];		/* ��ͣ״̬ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iTacheID;		/* ���ڱ�ʶ */
	struct InstParamStruct *pLoadNext;
};

/*�������ݶ�̬��INST_PARAM���ýṹ���巽ʽȡ����*/
int EGetInstParamToStruct(struct InstParamStruct *p,
	struct InstParamStructIn *pSource);
/**�Ա�INST_PARAM�������ͷź���**/
void DestroyInstParam(struct InstParamStruct *ptHead);
int InitInstParam(struct InstParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[PICK_PARAM_BUFLEN_IN][7];
		/* Ⱥ���ʶ */
	int     aiGroupID[PICK_PARAM_BUFLEN_IN];
		/* �Զ�·�� */
	char    asOppPath[PICK_PARAM_BUFLEN_IN][81];
		/* �Զ˱���·�� */
	char    asOppBkupPath[PICK_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asLocalPath[PICK_PARAM_BUFLEN_IN][81];
		/* ����IP */
	char    asIp[PICK_PARAM_BUFLEN_IN][17];
		/* �û��� */
	char    asUserName[PICK_PARAM_BUFLEN_IN][21];
		/* ���� */
	char    asPasswd[PICK_PARAM_BUFLEN_IN][21];
		/* ƥ��ģʽ */
	char    asFilter[PICK_PARAM_BUFLEN_IN][21];
		/* ԭʼ���ƫ�� */
	int     aiSeqOff[PICK_PARAM_BUFLEN_IN];
		/* ԭʼ��ų��� */
	int     aiSeqLen[PICK_PARAM_BUFLEN_IN];
		/* ɾ������ */
	char    asDeleteType[PICK_PARAM_BUFLEN_IN][2];
	int     aiChkDays[PICK_PARAM_BUFLEN_IN];
		/* �����ʽ���� */
	char    asOutType[PICK_PARAM_BUFLEN_IN][6];
		/* ״̬ */
	char    asState[PICK_PARAM_BUFLEN_IN][2];
		/* Ӧ�ñ�ʶ */
	char    asAppID[PICK_PARAM_BUFLEN_IN][11];
		/* ���ڱ�ʶ */
	int     aiTacheID[PICK_PARAM_BUFLEN_IN];
	
};


/*�����ṹ����*/
struct PickParamStruct{

	struct PickParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sOppPath[81];		/* �Զ�·�� */
	char    sOppBkupPath[81];		/* �Զ˱���·�� */
	char    sLocalPath[81];		/* ����·�� */
	char    sIp[17];		/* ����IP */
	char    sUserName[21];		/* �û��� */
	char    sPasswd[21];		/* ���� */
	char    sFilter[21];		/* ƥ��ģʽ */
	int     iSeqOff;		/* ԭʼ���ƫ�� */
	int     iSeqLen;		/* ԭʼ��ų��� */
	char    sDeleteType[2];		/* ɾ������ */
	int	iChkDays;
	char    sOutType[6];		/* �����ʽ���� */
	char	sState[2];
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iTacheID;		/* ���ڱ�ʶ */
	struct PickParamStruct *pLoadNext;
};


/*�������ݶ�̬��PICK_PARAM���ýṹ���巽ʽȡ����*/
int EGetPickParamToStruct(struct PickParamStruct *p,
	struct PickParamStructIn *pSource);
/**�Ա�PICK_PARAM�������ͷź���**/
void DestroyPickParam(struct PickParamStruct *ptHead);
int InitPickParam(struct PickParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[PREP_PARAM_BUFLEN_IN][7];
		/* Ⱥ���ʶ */
	int     aiGroupID[PREP_PARAM_BUFLEN_IN];
		/* ��������ʶ */
	char    asMsc[PREP_PARAM_BUFLEN_IN][16];
		/* ���� */
	char    asAreaCode[PREP_PARAM_BUFLEN_IN][6];
		/* ��ʽ�ļ� */
	char    asExprFile[PREP_PARAM_BUFLEN_IN][81];
		/* ģʽ */
	char    asFilter[PREP_PARAM_BUFLEN_IN][21];
		/* Դ·�� */
	char    asSourcePath[PREP_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asBackPath[PREP_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asNormalPath[PREP_PARAM_BUFLEN_IN][81];
		/* ģ�� */
	char    asModule[PREP_PARAM_BUFLEN_IN][4];
	
	char    asSplit[PREP_PARAM_BUFLEN_IN][11];
	int     aiStartPos[PREP_PARAM_BUFLEN_IN];
	int     aiKeyLen[PREP_PARAM_BUFLEN_IN];
	char    asChkMod[PREP_PARAM_BUFLEN_IN][4];

	char	asUserType[PREP_PARAM_BUFLEN_IN][2];

		/* �������� */
	char    asInType[PREP_PARAM_BUFLEN_IN][6];
		/* ������� */
	char    asOutType[PREP_PARAM_BUFLEN_IN][6];
		/* ��ͣ״̬ */
	char    asState[PREP_PARAM_BUFLEN_IN][2];
		/* Ӧ�ñ�ʶ */
	char    asAppID[PREP_PARAM_BUFLEN_IN][11];
		/* ���ڱ�ʶ */
	int     aiTacheID[PREP_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct PrepParamStruct{

	struct PrepParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sMsc[16];		/* ��������ʶ */
	char    sAreaCode[6];		/* ���� */
	char    sExprFile[81];		/* ��ʽ�ļ� */
	char    sFilter[21];		/* ģʽ */
	char    sSourcePath[81];		/* Դ·�� */
	char    sBackPath[81];		/* ����·�� */
	char    sNormalPath[81];		/* ����·�� */
	char    sErrPath[81];		/* �쳣·�� */
	char    sModule[4];		/* ģ�� */
	
	char    sSplit[11];
	int     iStartPos;
	int     iKeyLen;
	char    sChkMod[4];
	
	char    sUserType[2];

	char	sInType[6];
	char	sOutType[6];
	char    sState[2];		/* ��ͣ״̬ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iTacheID;		/* ���ڱ�ʶ */
	struct PrepParamStruct *pLoadNext;
};

/*�������ݶ�̬��PREP_PARAM���ýṹ���巽ʽȡ����*/
int EGetPrepParamToStruct(struct PrepParamStruct *p,
	struct PrepParamStructIn *pSource);
/**�Ա�PREP_PARAM�������ͷź���**/
void DestroyPrepParam(struct PrepParamStruct *ptHead);
int InitPrepParam(struct PrepParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[BILL_PARAM_BUFLEN_IN][7];
	char	asAppCode[BILL_PARAM_BUFLEN_IN][9];
		/* Ⱥ���ʶ */
	int     aiGroupID[BILL_PARAM_BUFLEN_IN];
		/* ģʽ */
	char    asFilter[BILL_PARAM_BUFLEN_IN][21];
		/* Դ·�� */
	char    asSourcePath[BILL_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asBackPath[BILL_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asNormalPath[BILL_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asErrPath[BILL_PARAM_BUFLEN_IN][81];
	char	asUserType[BILL_PARAM_BUFLEN_IN][41];
		/* ģ���ʶ */
	char    asTemplateID[BILL_PARAM_BUFLEN_IN][81];
		/* ���봮 */
	char    asSplitStr[BILL_PARAM_BUFLEN_IN][11];
		/* �ļ��������� */
	char    asBelongCode[BILL_PARAM_BUFLEN_IN][6];
		/* ģ�� */
	char    asModule[BILL_PARAM_BUFLEN_IN][4];

	char    asSplit[BILL_PARAM_BUFLEN_IN][10];
	int	aiStartPos[BILL_PARAM_BUFLEN_IN];
	int	aiKeyLen[BILL_PARAM_BUFLEN_IN];
	char    asBatchFlag[BILL_PARAM_BUFLEN_IN][2];

	char    asInType[BILL_PARAM_BUFLEN_IN][6];
	char    asOutType[BILL_PARAM_BUFLEN_IN][6];
		/* ��ͣ״̬ */
	char    asState[BILL_PARAM_BUFLEN_IN][2];
		/* Ӧ�ñ�ʶ */
	char    asAppID[BILL_PARAM_BUFLEN_IN][11];
		/* ���ڱ�ʶ */
	int     aiTacheID[BILL_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct BillParamStruct{

	struct BillParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	char	sAppCode[9];
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sFilter[21];		/* ģʽ */
	char    sSourcePath[81];		/* Դ·�� */
	char    sBackPath[81];		/* ����·�� */
	char    sNormalPath[81];		/* ����·�� */
	char    sErrPath[81];		/* ����·�� */
	char	sUserType[41];
	char    sTemplateID[81];		/* ģ���ʶ */
	char    sSplitStr[11];		/* ���봮 */
	char    sBelongCode[6];		/* �ļ��������� */
	char    sModule[4];		/* ģ�� */
	char    sSplit[10];
	int	iStartPos;
	int	iKeyLen;
	char	sBatchFlag[2];
	char	sInType[6];
	char	sOutType[6];
	char    sState[2];		/* ��ͣ״̬ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iTacheID;		/* ���ڱ�ʶ */
	struct BillParamStruct *pLoadNext;
};

/*�������ݶ�̬��BILL_PARAM���ýṹ���巽ʽȡ����*/
int EGetBillParamToStruct(struct BillParamStruct *p,
	struct BillParamStructIn *pSource);
/**�Ա�BILL_PARAM�������ͷź���**/
void DestroyBillParam(struct BillParamStruct *ptHead);
int InitBillParam(struct BillParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ���� */
	char    asTableName[COMM_SEARCH_BUFLEN_IN][31];
		/* B��BINTREE,T��TRIE���� */
	char    asMethod[COMM_SEARCH_BUFLEN_IN][2];
		/* 0��ʶĬ��ֵ */
	int     aiIntKey[COMM_SEARCH_BUFLEN_IN];
		/* �ַ����� */
	char    asStrKey[COMM_SEARCH_BUFLEN_IN][81];
		/* ����ֵ */
	int     aiIntVal[COMM_SEARCH_BUFLEN_IN];
		/* �ַ���ֵ */
	char    asStrVal[COMM_SEARCH_BUFLEN_IN][81];
		/* ��Чʱ�� */
	char    asEffDate[COMM_SEARCH_BUFLEN_IN][15];
		/* ʧЧʱ�� */
	char    asExpDate[COMM_SEARCH_BUFLEN_IN][15];
	
	char	asState[COMM_SEARCH_BUFLEN_IN][4];
	char	asStateDate[COMM_SEARCH_BUFLEN_IN][15];
	char	asCreatedDate[COMM_SEARCH_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct CommSearchStruct{

	struct CommSearchStruct *pNext;
	char    sTableName[31];		/* ���� */
	char    sMethod[2];	/*B��BINTREE,T��TRIE����,b LBINTREE,t LTRIE*/
	int     iIntKey;		/* 0��ʶĬ��ֵ */
	char    sStrKey[81];		/* �ַ����� */
	int     iIntVal;		/* ����ֵ */
	char    sStrVal[81];		/* �ַ���ֵ */
	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */

	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct CommSearchStruct *pLoadNext;
};

int EGetCommSearchToStruct(struct CommSearchStruct *p,
	struct CommSearchStructIn *pSource);
/**�Ա�COMM_SEARCH�������ͷź���**/
void DestroyCommSearch(struct CommSearchStruct *ptHead);
int InitCommSearch(struct CommSearchStruct **pptHead,char sMethod[]);
int InitCommSearchBin(struct CommSearchStruct **pptHead);
int InitCommSearchTrie(struct CommSearchStruct **pptHead);

/* ����ṹ��������*/
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
		/* ���� */
	char    asTableName[COMM_RANGE_BUFLEN_IN][31];
		/* ��ʼ�� */
	char    asBgnKey[COMM_RANGE_BUFLEN_IN][21];
		/* ��ֹ�� */
	char    asEndKey[COMM_RANGE_BUFLEN_IN][21];
		/* ����ֵ */	
	int     aiIntVal[COMM_RANGE_BUFLEN_IN];
		/* �ַ���ֵ */
	char    asStrVal[COMM_RANGE_BUFLEN_IN][41];
		/* ��Чʱ�� */
	char    asEffDate[COMM_RANGE_BUFLEN_IN][15];
		/* ʧЧʱ�� */
	char    asExpDate[COMM_RANGE_BUFLEN_IN][15];

	char	asState[COMM_RANGE_BUFLEN_IN][4];
	char	asStateDate[COMM_RANGE_BUFLEN_IN][15];
	char	asCreatedDate[COMM_RANGE_BUFLEN_IN][15];
};

/*�����ṹ����*/
struct CommRangeStruct{

	struct CommRangeStruct *pNext;
	char    sTableName[31];		/* ���� */
	char    sBgnKey[21];		/* ��ʼ�� */
	char    sEndKey[21];		/* ��ֹ�� */
	int     iIntVal;		/* ����ֵ */
	char    sStrVal[41];		/* �ַ���ֵ */
	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct CommRangeStruct *pLoadNext;
};

int EGetCommRangeToStruct(struct CommRangeStruct *p,
	struct CommRangeStructIn *pSource);
void DestroyCommRange(struct CommRangeStruct *ptHead);
int InitCommRange(struct CommRangeStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��������ʶ */
	int     aiSwitchID[SWITCH_BUFLEN_IN];
		/* ���ͱ�ʶ */
	int     aiTypeID[SWITCH_BUFLEN_IN];
		/* �����ڲ������ã�����һ����Ľ��������岻ȷ�� */
	char    asAreaCode[SWITCH_BUFLEN_IN][6];
		/* IP:ͨ��IP��ʽ��SERIAL:���� */
	char    asMethod[SWITCH_BUFLEN_IN][7];
		/* ��METHOD=IP��ʱ�򣬱�ʶSOCKETЭ��IP������Ϊ�������IP */
	char    asIp[SWITCH_BUFLEN_IN][16];
		/* ��METHOD=IP��ʱ�򣬱�ʶSOCKETЭ��˿ڣ�����Ϊ������Ķ˿� */
	int     aiPort[SWITCH_BUFLEN_IN];
	char    asUserName[SWITCH_BUFLEN_IN][31];
	char    asPassword[SWITCH_BUFLEN_IN][31];
		/* ���� */
	char    asRemark[SWITCH_BUFLEN_IN][61];
};


/*�����ṹ����*/
struct SwitchStruct{

	struct SwitchStruct *pNext;
	int     iSwitchID;		/* ��������ʶ */
	int     iTypeID;		/* ���ͱ�ʶ */
	char    sAreaCode[6];		/* �����ڲ������ã�����һ����Ľ��������岻ȷ�� */
	char    sMethod[7];		/* IP:ͨ��IP��ʽ��SERIAL:���� */
	char    sIp[16];		/* ��METHOD=IP��ʱ�򣬱�ʶSOCKETЭ��IP������Ϊ�������IP */
	int     iPort;		/* ��METHOD=IP��ʱ�򣬱�ʶSOCKETЭ��˿ڣ�����Ϊ������Ķ˿� */
	char	sUserName[31];
	char	sPassword[31];
	char    sRemark[61];		/* ���� */
	struct SwitchStruct *pLoadNext;
};

/*�������ݶ�̬��SWITCH���ýṹ���巽ʽȡ����*/
int EGetSwitchToStruct(struct SwitchStruct *p,
	struct SwitchStructIn *pSource);
/**�Ա�SWITCH�������ͷź���**/
void DestroySwitch(struct SwitchStruct *ptHead);
int InitSwitch(struct SwitchStruct **pptHead);

/* ����ṹ��������*/
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
		/* ģ���ʶ */
	int     aiTemplateID[CMD_TEMPLATE_BUFLEN_IN];
		/* �������ͱ�ʶ */
	int     aiCmdTypeID[CMD_TEMPLATE_BUFLEN_IN];
		/* ��׼���� */
	char    asStandardCode[CMD_TEMPLATE_BUFLEN_IN][31];
		/* ���������ͱ�ʶ */
	int     aiSwitchTypeID[CMD_TEMPLATE_BUFLEN_IN];
		/* ģ������ű� */
	char    asCmdText[CMD_TEMPLATE_BUFLEN_IN][61];
		/* ���� */
	char    asRemark[CMD_TEMPLATE_BUFLEN_IN][61];
};


/*�����ṹ����*/
struct CmdTemplateStruct{

	struct CmdTemplateStruct *pNext;
	int     iTemplateID;		/* ģ���ʶ */
	int     iCmdTypeID;		/* �������ͱ�ʶ */
	char    sStandardCode[31];		/* ��׼���� */
	int     iSwitchTypeID;		/* ���������ͱ�ʶ */
	char    sCmdText[61];		/* ģ������ű� */
	char    sRemark[61];		/* ���� */
	struct CmdTemplateStruct *pLoadNext;
};

/*�������ݶ�̬��CMD_TEMPLATE���ýṹ���巽ʽȡ����*/
int EGetCmdTemplateToStruct(struct CmdTemplateStruct *p,
	struct CmdTemplateStructIn *pSource);
void DestroyCmdTemplate(struct CmdTemplateStruct *ptHead);
int InitCmdTemplate(struct CmdTemplateStruct **pptHead);

/* ����ṹ��������*/
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
		/* ҵ������ */
	char    asServiceType[NBR_HEAD_BUFLEN_IN][11];
		/* �Ŷ� */
	char    asHead[NBR_HEAD_BUFLEN_IN][13];
		/* ACCNBR��ʾ����,IMSI��ʾIMSI,ESN��ʾ���Ӵ��� */
	char    asFieldType[NBR_HEAD_BUFLEN_IN][7];
		/* ��������ʶ */
	int     aiSwitchID[NBR_HEAD_BUFLEN_IN];
};


/*�����ṹ����*/
struct NbrHeadStruct{

	struct NbrHeadStruct *pNext;
	char    sServiceType[11];		/* ҵ������ */
	char    sHead[13];		/* �Ŷ� */
	char    sFieldType[7];		/* ACCNBR��ʾ����,IMSI��ʾIMSI,ESN��ʾ���Ӵ��� */
	int     iSwitchID;		/* ��������ʶ */
	struct NbrHeadStruct *pLoadNext;
};
/*�������ݶ�̬��NBR_HEAD���ýṹ���巽ʽȡ����*/
int EGetNbrHeadToStruct(struct NbrHeadStruct *p,
	struct NbrHeadStructIn *pSource);
void DestroyNbrHead(struct NbrHeadStruct *ptHead);
int InitNbrHead(struct NbrHeadStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[ACCT_ITEM_TYPE_BUFLEN_IN];
		/* ��Ŀ���࣬����a_acct_item_type_kind B-������ĿD-������Ŀ */
	char    asAcctItemTypeKind[ACCT_ITEM_TYPE_BUFLEN_IN][2];
		/* ���� */
	char    asAcctItemName[ACCT_ITEM_TYPE_BUFLEN_IN][61];
		/* ��׼���� */
	char    asStandardCode[ACCT_ITEM_TYPE_BUFLEN_IN][11];
		/* �鲢��Ŀ��ʶ */
	int     aiSummaryItemID[ACCT_ITEM_TYPE_BUFLEN_IN];
};


/*�����ṹ����*/
struct AcctItemTypeStruct{

	struct AcctItemTypeStruct *pNext;
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	char    sAcctItemTypeKind[2];		
/* ��Ŀ���࣬����a_acct_item_type_kind B-������ĿD-������Ŀ */
	char    sAcctItemName[61];		/* ���� */
	char    sStandardCode[11];		/* ��׼���� */
	int     iSummaryItemID;		/* �鲢��Ŀ��ʶ */
	struct AcctItemTypeStruct *pLoadNext;
};
/*�������ݶ�̬��ACCT_ITEM_TYPE���ýṹ���巽ʽȡ����*/
int EGetAcctItemTypeToStruct(struct AcctItemTypeStruct *p,
	struct AcctItemTypeStructIn *pSource);
int InitAcctItemType(struct AcctItemTypeStruct **pptHead);
void DestroyAcctItemType(struct AcctItemTypeStruct *ptHead);


/* ����ṹ��������*/
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
		/* ��������ʶ */
	int     aiSettRuleID[SETT_RULE_BUFLEN_IN];
	int     aiSeqNbr[SETT_RULE_BUFLEN_IN];
		/* �������ͱ�ʶ */
	int     aiTicketTypeID[SETT_RULE_BUFLEN_IN];
		/* �ʷ����� */
	char    asTariffType[SETT_RULE_BUFLEN_IN][3];
		/* 'C' ���ν��� ��P' ���ٷֱȽ��� 'D' ��ʱ������ 'F' �������� 'R' ʵ�ս��� */
	char    asMethod[SETT_RULE_BUFLEN_IN][2];
		/* ������� */
	int     aiOppCarrierID[SETT_RULE_BUFLEN_IN];
		/* ������Ŀ���� */
	int     aiAcctItemTypeID[SETT_RULE_BUFLEN_IN];
		/* ������� */
	int     aiRate[SETT_RULE_BUFLEN_IN];
		/* ��ε�λ */
	int     aiSecPerCnt[SETT_RULE_BUFLEN_IN];
		/* ��Чʱ�� */
	char    asEffDate[SETT_RULE_BUFLEN_IN][15];
		/* ʧЧʱ�� */
	char    asExpDate[SETT_RULE_BUFLEN_IN][15];
	char    asState[SETT_RULE_BUFLEN_IN][4];
	char    asStateDate[SETT_RULE_BUFLEN_IN][15];
	char    asCreatedDate[SETT_RULE_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct SettRuleStruct{

	struct SettRuleStruct *pNext;
	int     iSettRuleID;		/* ��������ʶ */
	int	iSeqNbr;
	int     iTicketTypeID;		/* �������ͱ�ʶ */
	char    sTariffType[3];		/* �ʷ����� */
	char    sMethod[2];		/* 'C' ���ν��� ��P' ���ٷֱȽ��� 'D' ��ʱ������ 'F' �������� 'R' ʵ�ս��� */
	int     iOppCarrierID;		/* ������� */
	int     iAcctItemTypeID;		/* ������Ŀ���� */
	int     iRate;		/* ������� */
	int     iSecPerCnt;		/* ��ε�λ */
	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	struct SettRuleStruct *pLoadNext;
};
/*�������ݶ�̬��SETT_RULE���ýṹ���巽ʽȡ����*/
int EGetSettRuleToStruct(struct SettRuleStruct *p,
	struct SettRuleStructIn *pSource);
/**�Ա�SETT_RULE�������ͷź���**/
void DestroySettRule(struct SettRuleStruct *ptHead);
int InitSettRule(struct SettRuleStruct **pptHead);

/* ����ṹ��������*/
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
		/* �������ڱ�ʶ�� */
	int     aiSettCycleID[SETT_CYCLE_BUFLEN_IN];
		/* �������ڱ�ʶ */
	int     aiCycleTypeID[SETT_CYCLE_BUFLEN_IN];
		/* ��ϵͳģ�� */
	char    asModule[SETT_CYCLE_BUFLEN_IN][4];
		/* ��������ʶ */
	int     aiSettCarrierID[SETT_CYCLE_BUFLEN_IN];
		/* �������ڿ�ʼ���� */
	char    asCycleBeginDate[SETT_CYCLE_BUFLEN_IN][15];
		/* �������ڽ������� */
	char    asCycleEndDate[SETT_CYCLE_BUFLEN_IN][15];
		/* ״̬ */
	char    asState[SETT_CYCLE_BUFLEN_IN][4];
		/* �����·� */
	char    asMonth[SETT_CYCLE_BUFLEN_IN][3];
		/* ���� */
	char    asRemark[SETT_CYCLE_BUFLEN_IN][61];
};


/*�����ṹ����*/
struct SettCycleStruct{

	struct SettCycleStruct *pNext;
	int     iSettCycleID;		/* �������ڱ�ʶ�� */
	int     iCycleTypeID;		/* �������ڱ�ʶ */
	char    sModule[4];		/* ��ϵͳģ�� */
	int     iSettCarrierID;		/* ��������ʶ */
	char    sCycleBeginDate[15];		/* �������ڿ�ʼ���� */
	char    sCycleEndDate[15];		/* �������ڽ������� */
	char    sState[4];		/* ״̬ */
	char    sMonth[3];		/* �����·� */
	char    sRemark[61];		/* ���� */
	struct SettCycleStruct *pLoadNext;
};

/*�������ݶ�̬��SETT_CYCLE���ýṹ���巽ʽȡ����*/
int EGetSettCycleToStruct(struct SettCycleStruct *p,
	struct SettCycleStructIn *pSource);
/**�Ա�SETT_CYCLE�������ͷź���**/
void DestroySettCycle(struct SettCycleStruct *ptHead);
int InitSettCycle(struct SettCycleStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��������ʶ */
	int     aiLatnID[LATN_BUFLEN_IN];
		/* ���� */
	char    asName[LATN_BUFLEN_IN][21];
		/* ��׼���� */
	char    asStandardCode[LATN_BUFLEN_IN][5];
		/* �������� */
	char    asAreaCode[LATN_BUFLEN_IN][6];
};


/*�����ṹ����*/
struct LatnStruct{

	struct LatnStruct *pNext;
	int     iLatnID;		/* ��������ʶ */
	char    sName[21];		/* ���� */
	char    sStandardCode[5];		/* ��׼���� */
	char    sAreaCode[6];		/* �������� */
	struct LatnStruct *pLoadNext;
};


/*�������ݶ�̬��LATN���ýṹ���巽ʽȡ����*/
int EGetLatnToStruct(struct LatnStruct *p,
	struct LatnStructIn *pSource);
/**�Ա�LATN�������ͷź���**/
void DestroyLatn(struct LatnStruct *ptHead);
int InitLatn(struct LatnStruct **pptHead);


/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[PUT_PARAM_BUFLEN_IN][7];
		/* Ⱥ���ʶ */
	int     aiGroupID[PUT_PARAM_BUFLEN_IN];
		/* �Զ�·�� */
	char    asOppPath[PUT_PARAM_BUFLEN_IN][81];
		/* ���˱���·�� */
	char    asLocalBkupPath[PUT_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asLocalPath[PUT_PARAM_BUFLEN_IN][81];
		/* ����IP */
	char    asIp[PUT_PARAM_BUFLEN_IN][17];
		/* �û��� */
	char    asUserName[PUT_PARAM_BUFLEN_IN][21];
		/* ���� */
	char    asPasswd[PUT_PARAM_BUFLEN_IN][21];
		/* ƥ��ģʽ */
	char    asFilter[PUT_PARAM_BUFLEN_IN][21];
	
	int	aiSeqOff[PUT_PARAM_BUFLEN_IN];
	int	aiSeqLen[PUT_PARAM_BUFLEN_IN];
	char	asDeleteType[PUT_PARAM_BUFLEN_IN][2];
	int	aiChkDays[PUT_PARAM_BUFLEN_IN];

		/* ����������ļ��� */
	char    asFileType[PUT_PARAM_BUFLEN_IN][6];
		/* ��ͣ״̬ */
	char    asState[PUT_PARAM_BUFLEN_IN][2];
	
	char    asAppID[PUT_PARAM_BUFLEN_IN][11];
	int     aiTacheID[PUT_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct PutParamStruct{

	struct PutParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sOppPath[81];		/* �Զ�·�� */
	char    sLocalBkupPath[81];		/* ���˱���·�� */
	char    sLocalPath[81];		/* ����·�� */
	char    sIp[17];		/* ����IP */
	char    sUserName[21];		/* �û��� */
	char    sPasswd[21];		/* ���� */
	char    sFilter[21];		/* ƥ��ģʽ */
	int	iSeqOff;
	int	iSeqLen;
	char	sDeleteType[2];
	int	iChkDays;
	char    sFileType[6];		/* �ļ����� */
	char    sState[2];		/* ��ͣ״̬ */
	char	sAppID[11];
	int	iTacheID;
	struct PutParamStruct *pLoadNext;
};
/*�������ݶ�̬��PUT_PARAM���ýṹ���巽ʽȡ����*/
int EGetPutParamToStruct(struct PutParamStruct *p,
	struct PutParamStructIn *pSource);
/**�Ա�PUT_PARAM�������ͷź���**/
void DestroyPutParam(struct PutParamStruct *ptHead);
int InitPutParam(struct PutParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[COMM_PARAM_BUFLEN_IN][7];
		/* ��� */
	int     aiGroupID[COMM_PARAM_BUFLEN_IN];
		/* ģ��� */
	char    asModule[COMM_PARAM_BUFLEN_IN][4];
		/* ԴĿ¼ */
	char    asSourcePath[COMM_PARAM_BUFLEN_IN][81];
		/* �ļ�ƥ��ģʽ */
	char    asFilter[COMM_PARAM_BUFLEN_IN][21];
		/* ����Ŀ¼ */
	char    asBackupPath[COMM_PARAM_BUFLEN_IN][81];
		/* ���Ŀ¼ */
	char    asTargetPath[COMM_PARAM_BUFLEN_IN][81];
		/* ָ����$BILLHOME/bin�µ�����. ����ĸ�ʽ�� ./cmd source_path filter back_path 
target_path  append_arg */
	char    asCmd[COMM_PARAM_BUFLEN_IN][81];
	char    asInType[COMM_PARAM_BUFLEN_IN][6];
	char    asOutType[COMM_PARAM_BUFLEN_IN][6];
		/* ��Ϊĩβ�ģ������ */
	char    asAppendArg[COMM_PARAM_BUFLEN_IN][101];
};


/*�����ṹ����*/
struct CommParamStruct{

	struct CommParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	int     iGroupID;		/* ��� */
	char    sModule[4];		/* ģ��� */
	char    sSourcePath[81];		/* ԴĿ¼ */
	char    sFilter[21];		/* �ļ�ƥ��ģʽ */
	char    sBackupPath[81];		/* ����Ŀ¼ */
	char    sTargetPath[81];		/* ���Ŀ¼ */
	char    sCmd[81];
	char    sInType[81];
	char    sOutType[81];
	/* ָ����$BILLHOME/bin�µ�����. ����ĸ�ʽ�� 
	./cmd source_path filter back_path target_path  append_arg */
	char    sAppendArg[101];		/* ��Ϊĩβ�ģ������ */
	struct CommParamStruct *pLoadNext;
};
/*�������ݶ�̬��COMM_PARAM���ýṹ���巽ʽȡ����*/
int EGetCommParamToStruct(struct CommParamStruct *p,
	struct CommParamStructIn *pSource);
/**�Ա�COMM_PARAM�������ͷź���**/
void DestroyCommParam(struct CommParamStruct *ptHead);
int InitCommParam(struct CommParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* Ӫҵ����ʶ */
	int     aiSettAreaID[SETT_AREA_BUFLEN_IN];
		/* ��������ʶ */
	int     aiLatnID[SETT_AREA_BUFLEN_IN];
		/* '0' ����'1'�� */
	char    asCountyFlag[SETT_AREA_BUFLEN_IN][2];
		/* ���� */
	char    asName[SETT_AREA_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct SettAreaStruct{

	struct SettAreaStruct *pNext;
	int     iSettAreaID;		/* Ӫҵ����ʶ */
	int     iLatnID;		/* ��������ʶ */
	char    sCountyFlag[2];		/* '0' ����'1'�� */
	char    sName[41];		/* ���� */
	struct SettAreaStruct *pLoadNext;
};
/*�������ݶ�̬��SETT_AREA���ýṹ���巽ʽȡ����*/
int EGetSettAreaToStruct(struct SettAreaStruct *p,struct SettAreaStructIn *pSource);
/**�Ա�AREA�������ͷź���**/
void DestroySettArea(struct SettAreaStruct *ptHead);
int InitSettArea(struct SettAreaStruct **pptHead);

/* ����ṹ��������*/
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
		/* Ӧ�ñ�ʶ */
	char    asAppID[FLOW_APP_BUFLEN_IN][11];
		/* Ӧ�ñ��� */
	char    asAppCode[FLOW_APP_BUFLEN_IN][9];
		/* 0��ʼӦ��,1�м�Ӧ��,2��ֹӦ�� */
	char    asAppType[FLOW_APP_BUFLEN_IN][2];
		/* Ӧ������ */
	char    asName[FLOW_APP_BUFLEN_IN][21];
};


/*�����ṹ����*/
struct FlowAppStruct{

	struct FlowAppStruct *pNext;
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	char    sAppCode[9];		/* Ӧ�ñ��� */
	char    sAppType[2];		/* 0��ʼӦ��,1�м�Ӧ��,2��ֹӦ�� */
	char    sName[21];		/* Ӧ������ */
	struct FlowAppStruct *pLoadNext;
};
/*�������ݶ�̬��FLOW_APP���ýṹ���巽ʽȡ����*/
int EGetFlowAppToStruct(struct FlowAppStruct *p,
	struct FlowAppStructIn *pSource);
/**�Ա�FLOW_APP�������ͷź���**/
void DestroyFlowApp(struct FlowAppStruct *ptHead);
int InitFlowApp(struct FlowAppStruct **pptHead);

/* ����ṹ��������*/
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
		/* �����ʶ */
	int     aiTaskID[FLOW_TASK_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGrpTaskID[FLOW_TASK_BUFLEN_IN];
		/* �������ʶ0������,1�� */
	char    asGrpFlag[FLOW_TASK_BUFLEN_IN][2];
		/* Ӧ�ñ�ʶ */
	char    asAppID[FLOW_TASK_BUFLEN_IN][11];
		/* ������ʶ */
	int     aiParamID[FLOW_TASK_BUFLEN_IN];
		/* �������� */
	char    asName[FLOW_TASK_BUFLEN_IN][41];
};
/*�����ṹ����*/
struct FlowTaskStruct{

	struct FlowTaskStruct *pNext;
	int     iTaskID;		/* �����ʶ */
	int     iGrpTaskID;		/* Ⱥ���ʶ */
	char    sGrpFlag[2];		/* �������ʶ0������,1�� */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iParamID;		/* ������ʶ */
	char    sName[41];		/* �������� */
	struct FlowTaskStruct *pLoadNext;
};
/*�������ݶ�̬��FLOW_TASK���ýṹ���巽ʽȡ����*/
int EGetFlowTaskToStruct(struct FlowTaskStruct *p,
	struct FlowTaskStructIn *pSource);
/**�Ա�FLOW_TASK�������ͷź���**/
void DestroyFlowTask(struct FlowTaskStruct *ptHead);
int InitFlowTask(struct FlowTaskStruct **pptHead);

/* ����ṹ��������*/
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
		/* ���ڱ�ʶ */
	int     aiTacheID[FLOW_TACHE_BUFLEN_IN];
		/* ǰ�û��ڱ�ʶ */
	int     aiPreTacheID[FLOW_TACHE_BUFLEN_IN];
		/* ǰ�û������ */
	int     aiPreSeqNbr[FLOW_TACHE_BUFLEN_IN];
		/* ���̱�ʶ */
	int     aiFlowID[FLOW_TACHE_BUFLEN_IN];
		/* �����ʶ */
	int     aiTaskID[FLOW_TACHE_BUFLEN_IN];
		/* Ӧ�ñ�ʶ */
	char    asAppID[FLOW_TACHE_BUFLEN_IN][11];
	
	char    asPreIntfType[FLOW_TACHE_BUFLEN_IN][2];
	char    asDataDealType[FLOW_TACHE_BUFLEN_IN][3];
};
/*�����ṹ����*/
struct FlowTacheStruct{

	struct FlowTacheStruct *pNext;
	int     iTacheID;		/* ���ڱ�ʶ */
	int     iPreTacheID;		/* ǰ�û��ڱ�ʶ */
	int     iPreSeqNbr;		/* ǰ�û������ */
	int     iFlowID;		/* ���̱�ʶ */
	int     iTaskID;		/* �����ʶ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	char    sPreIntfType[2];
	char    sDataDealType[3];
	struct FlowTacheStruct *pLoadNext;
};
/*�������ݶ�̬��FLOW_TACHE���ýṹ���巽ʽȡ����*/
int EGetFlowTacheToStruct(struct FlowTacheStruct *p,
	struct FlowTacheStructIn *pSource);
/**�Ա�FLOW_TACHE�������ͷź���**/
void DestroyFlowTache(struct FlowTacheStruct *ptHead);
int InitFlowTache(struct FlowTacheStruct **pptHead);

/* ����ṹ��������*/
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
		/* ������ʶ */
	int     aiParamID[TASK_PARAM_BUFLEN_IN];
		/* Ӧ�ñ�ʶ */
	char    asAppID[TASK_PARAM_BUFLEN_IN][11];
		/* �������·�� */
	char    asInPath[TASK_PARAM_BUFLEN_IN][61];
		/* �������·�� */
	char    asBakPath[TASK_PARAM_BUFLEN_IN][61];
		/* ������·�� */
	char    asOutPath[TASK_PARAM_BUFLEN_IN][61];
		/* �����ļ�ģʽ */
	char    asInFilter[TASK_PARAM_BUFLEN_IN][61];
		/* ����ļ�ģʽ */
	char    asOutFilter[TASK_PARAM_BUFLEN_IN][61];
		/* �����ʽ���� */
	char    asInType[TASK_PARAM_BUFLEN_IN][6];
		/* �����ʽ���� */
	char    asOutType[TASK_PARAM_BUFLEN_IN][6];
};
/*�����ṹ����*/
struct TaskParamStruct{

	struct TaskParamStruct *pNext;
	int     iParamID;		/* ������ʶ */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	char    sInPath[61];		/* �������·�� */
	char    sBakPath[61];		/* �������·�� */
	char    sOutPath[61];		/* ������·�� */
	char    sInFilter[61];		/* �����ļ�ģʽ */
	char    sOutFilter[61];	/* ����ļ�ģʽ */
	char    sInType[6];		/* �����ʽ���� */
	char    sOutType[6];		/* �����ʽ���� */
	struct TaskParamStruct *pLoadNext;
};
/*�������ݶ�̬��TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetTaskParamToStruct(struct TaskParamStruct *p,
	struct TaskParamStructIn *pSource);
/**�Ա�TASK_PARAM�������ͷź���**/
void DestroyTaskParam(struct TaskParamStruct *ptHead);
int InitTaskParam(struct TaskParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* �䶯��� */
	int     aiSeqNbr[ACCT_TASK_PARAM_BUFLEN_IN];
		/* ������ʶ */
	int     aiParamID[ACCT_TASK_PARAM_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGroupID[ACCT_TASK_PARAM_BUFLEN_IN];
	char    asOperType[ACCT_TASK_PARAM_BUFLEN_IN][4];
		/* ���ڹ��� */
	char    asDateRule[ACCT_TASK_PARAM_BUFLEN_IN][13];
		/* ���ݹ������� */
	char    asBelongCode[ACCT_TASK_PARAM_BUFLEN_IN][6];
		/* ģ�� */
	char    asModule[ACCT_TASK_PARAM_BUFLEN_IN][4];
	char    asEffDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
	char    asState[ACCT_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[ACCT_TASK_PARAM_BUFLEN_IN][15];
};
/*�����ṹ����*/
struct AcctTaskParamStruct{

	struct AcctTaskParamStruct *pNext;
	char    sSourceID[7];
	int     iParamID;		/* ������ʶ */
	int     iSeqNbr;		/* �䶯��� */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sOperType[4];
	char    sDateRule[13];		/* ���ڹ��� */
	char    sBelongCode[6];		/* ���ݹ������� */
	char    sModule[4];		/* ģ�� */
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct AcctTaskParamStruct *pLoadNext;
};
/*�������ݶ�̬��ACCT_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetAcctTaskParamToStruct(struct AcctTaskParamStruct *p,
	struct AcctTaskParamStructIn *pSource);
/**�Ա�ACCT_TASK_PARAM�������ͷź���**/
void DestroyAcctTaskParam(struct AcctTaskParamStruct *ptHead);
int InitAcctTaskParam(struct AcctTaskParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* �䶯��� */
	int     aiSeqNbr[BILL_TASK_PARAM_BUFLEN_IN];
		/* ������ʶ */
	int     aiParamID[BILL_TASK_PARAM_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGroupID[BILL_TASK_PARAM_BUFLEN_IN];
		/* ��ʽ�ļ����û����� */
	char    asUserType[BILL_TASK_PARAM_BUFLEN_IN][41];
		/* ģ���ʶ */
	char    asTemplateID[BILL_TASK_PARAM_BUFLEN_IN][81];
		/* ���봮 */
	char    asSplitStr[BILL_TASK_PARAM_BUFLEN_IN][11];
		/* �ļ��������� */
	char    asBelongCode[BILL_TASK_PARAM_BUFLEN_IN][6];
		/* ģ�� */
	char    asModule[BILL_TASK_PARAM_BUFLEN_IN][4];
	char    asSplit[BILL_TASK_PARAM_BUFLEN_IN][10];
		/* �ַ���ƫ�� */
	int     aiStartPos[BILL_TASK_PARAM_BUFLEN_IN];
		/* ���� */
	int     aiKeyLen[BILL_TASK_PARAM_BUFLEN_IN];
	char    asBatchFlag[BILL_TASK_PARAM_BUFLEN_IN][2];
	
	char    asEffDate[BILL_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[BILL_TASK_PARAM_BUFLEN_IN][15];
	char    asState[BILL_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[BILL_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[BILL_TASK_PARAM_BUFLEN_IN][15];
};
/*�����ṹ����*/
struct BillTaskParamStruct{

	struct BillTaskParamStruct *pNext;
	char    sSourceID[7];
	char    sAppCode[9];
	int     iSeqNbr;		/* �䶯��� */
	int     iParamID;		/* ������ʶ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sUserType[41];		/* ��ʽ�ļ����û����� */
	char    sTemplateID[81];		/* ģ���ʶ */
	char    sSplitStr[11];		/* ���봮 */
	char    sBelongCode[6];		/* �ļ��������� */
	char    sModule[4];		/* ģ�� */
	char    sSplit[10];
	int     iStartPos;		/* �ַ���ƫ�� */
	int     iKeyLen;		/* ���� */
	char    sBatchFlag[2];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct BillTaskParamStruct *pLoadNext;
};
/*�������ݶ�̬��BILL_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetBillTaskParamToStruct(struct BillTaskParamStruct *p,
	struct BillTaskParamStructIn *pSource);
/**�Ա�BILL_TASK_PARAM�������ͷź���**/
void DestroyBillTaskParam(struct BillTaskParamStruct *ptHead);
int InitBillTaskParam(struct BillTaskParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* �䶯��� */
	int     aiSeqNbr[INST_TASK_PARAM_BUFLEN_IN];
		/* ������ʶ */
	int     aiParamID[INST_TASK_PARAM_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGroupID[INST_TASK_PARAM_BUFLEN_IN];
	char    asOperType[INST_TASK_PARAM_BUFLEN_IN][4];
		/* ���ڹ��� */
	char    asDateRule[INST_TASK_PARAM_BUFLEN_IN][13];
		/* ���ݹ������� */
	char    asBelongCode[INST_TASK_PARAM_BUFLEN_IN][6];
		/* ģ�� */
	char    asModule[INST_TASK_PARAM_BUFLEN_IN][4];
	char    asEffDate[INST_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[INST_TASK_PARAM_BUFLEN_IN][15];
	char    asState[INST_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[INST_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[INST_TASK_PARAM_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct InstTaskParamStruct{

	struct InstTaskParamStruct *pNext;
	char    sSourceID[7];
	int     iSeqNbr;		/* �䶯��� */
	int     iParamID;		/* ������ʶ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sOperType[4];
	char    sDateRule[13];		/* ���ڹ��� */
	char    sBelongCode[6];		/* ���ݹ������� */
	char    sModule[4];		/* ģ�� */
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct InstTaskParamStruct *pLoadNext;
};
/*�������ݶ�̬��INST_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetInstTaskParamToStruct(struct InstTaskParamStruct *p,
	struct InstTaskParamStructIn *pSource);
/**�Ա�INST_TASK_PARAM�������ͷź���**/
void DestroyInstTaskParam(struct InstTaskParamStruct *ptHead);
int InitInstTaskParam(struct InstTaskParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* �䶯��� */
	int     aiSeqNbr[INTF_TASK_PARAM_BUFLEN_IN];
		/* ������ʶ */
	int     aiParamID[INTF_TASK_PARAM_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGroupID[INTF_TASK_PARAM_BUFLEN_IN];
		/* �� */
	int     aiDelay[INTF_TASK_PARAM_BUFLEN_IN];
		/* ���д��� */
	char    asCityCode[INTF_TASK_PARAM_BUFLEN_IN][4];
	char    asFilter[INTF_TASK_PARAM_BUFLEN_IN][61];
	char    asFileType[INTF_TASK_PARAM_BUFLEN_IN][6];
	char    asEffDate[INTF_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[INTF_TASK_PARAM_BUFLEN_IN][15];
	char    asState[INTF_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[INTF_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[INTF_TASK_PARAM_BUFLEN_IN][15];
};
/*�����ṹ����*/
struct IntfTaskParamStruct{

	struct IntfTaskParamStruct *pNext;
	char	sSourceID[7];
	int     iSeqNbr;		/* �䶯��� */
	int     iParamID;		/* ������ʶ */
	int     iGroupID;		/* Ⱥ���ʶ */
	int     iDelay;			/* �� */
	char    sCityCode[4];		/* ���д��� */
	char    sFilter[61];		/* ����ģʽ */
	char	sFileType[6];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct IntfTaskParamStruct *pLoadNext;
};
/*�������ݶ�̬��INTF_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetIntfTaskParamToStruct(struct IntfTaskParamStruct *p,
	struct IntfTaskParamStructIn *pSource);
/**�Ա�INTF_TASK_PARAM�������ͷź���**/
void DestroyIntfTaskParam(struct IntfTaskParamStruct *ptHead);
int InitIntfTaskParam(struct IntfTaskParamStruct **pptHead);


/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[PICK_TASK_PARAM_BUFLEN_IN][7];
		/* �䶯��ˮ */
	int     aiSeqNbr[PICK_TASK_PARAM_BUFLEN_IN];
		/* ������ʶ */
	int     aiParamID[PICK_TASK_PARAM_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGroupID[PICK_TASK_PARAM_BUFLEN_IN];
		/* �Զ�·�� */
	char    asOppPath[PICK_TASK_PARAM_BUFLEN_IN][81];
		/* �Զ˱���·�� */
	char    asOppBkupPath[PICK_TASK_PARAM_BUFLEN_IN][81];
		/* ����IP */
	char    asIp[PICK_TASK_PARAM_BUFLEN_IN][17];
		/* �û��� */
	char    asUserName[PICK_TASK_PARAM_BUFLEN_IN][21];
		/* ���� */
	char    asPasswd[PICK_TASK_PARAM_BUFLEN_IN][21];
		/* ƥ��ģʽ */
	char    asFilter[PICK_TASK_PARAM_BUFLEN_IN][21];
		/* ԭʼ���ƫ�� */
	int     aiSeqOff[PICK_TASK_PARAM_BUFLEN_IN];
		/* ԭʼ��ų��� */
	int     aiSeqLen[PICK_TASK_PARAM_BUFLEN_IN];
		/* ɾ������ */
	char    asDeleteType[PICK_TASK_PARAM_BUFLEN_IN][2];
	int     aiChkDays[PICK_TASK_PARAM_BUFLEN_IN];

	char    asEffDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	char    asState[PICK_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[PICK_TASK_PARAM_BUFLEN_IN][15];
	
};


/*�����ṹ����*/
struct PickTaskParamStruct{

	struct PickTaskParamStruct *pNext;
	char	sSourceID[7];
	int     iSeqNbr;		/* �䶯��ˮ */
	int     iParamID;		/* ������ʶ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sOppPath[81];		/* �Զ�·�� */
	char    sOppBkupPath[81];		/* �Զ˱���·�� */
	char    sIp[17];		/* ����IP */
	char    sUserName[21];		/* �û��� */
	char    sPasswd[21];		/* ���� */
	char    sFilter[21];		/* ƥ��ģʽ */
	int     iSeqOff;		/* ԭʼ���ƫ�� */
	int     iSeqLen;		/* ԭʼ��ų��� */
	char    sDeleteType[2];		/* ɾ������ */
	int	iChkDays;
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];

	struct PickTaskParamStruct *pLoadNext;
};
/*�������ݶ�̬��PICK_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetPickTaskParamToStruct(struct PickTaskParamStruct *p,
	struct PickTaskParamStructIn *pSource);
/**�Ա�PICK_TASK_PARAM�������ͷź���**/
void DestroyPickTaskParam(struct PickTaskParamStruct *ptHead);
int InitPickTaskParam(struct PickTaskParamStruct **pptHead);


/* ����ṹ��������*/
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
		/* �䶯��� */
	int     aiSeqNbr[PREP_TASK_PARAM_BUFLEN_IN];
		/* ������ʶ */
	int     aiParamID[PREP_TASK_PARAM_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGroupID[PREP_TASK_PARAM_BUFLEN_IN];
		/* ��������ʶ */
	char    asMsc[PREP_TASK_PARAM_BUFLEN_IN][16];
		/* ���� */
	char    asAreaCode[PREP_TASK_PARAM_BUFLEN_IN][6];
		/* ��ʽ�ļ� */
	char    asExprFile[PREP_TASK_PARAM_BUFLEN_IN][81];
		/* ģ�� */
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


/*�����ṹ����*/
struct PrepTaskParamStruct{

	struct PrepTaskParamStruct *pNext;
	char    sSourceID[7];
	int     iSeqNbr;		/* �䶯��� */
	int     iParamID;		/* ������ʶ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sMsc[16];		/* ��������ʶ */
	char    sAreaCode[6];		/* ���� */
	char    sExprFile[81];		/* ��ʽ�ļ� */
	char    sModule[4];		/* ģ�� */

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

/*�������ݶ�̬��PREP_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetPrepTaskParamToStruct(struct PrepTaskParamStruct *p,
	struct PrepTaskParamStructIn *pSource);
/**�Ա�PREP_TASK_PARAM�������ͷź���**/
void DestroyPrepTaskParam(struct PrepTaskParamStruct *ptHead);
int InitPrepTaskParam(struct PrepTaskParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* �䶯��� */
	int     aiSeqNbr[PUT_TASK_PARAM_BUFLEN_IN];
		/* ������ʶ */
	int     aiParamID[PUT_TASK_PARAM_BUFLEN_IN];
		/* Ⱥ���ʶ */
	int     aiGroupID[PUT_TASK_PARAM_BUFLEN_IN];
		/* �Զ�·�� */
	char    asOppPath[PUT_TASK_PARAM_BUFLEN_IN][81];
		/* ����IP */
	char    asIp[PUT_TASK_PARAM_BUFLEN_IN][17];
		/* �û��� */
	char    asUserName[PUT_TASK_PARAM_BUFLEN_IN][21];
		/* ���� */
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
/*�����ṹ����*/
struct PutTaskParamStruct{

	struct PutTaskParamStruct *pNext;
	char	sSourceID[7];
	int     iSeqNbr;		/* �䶯��� */
	int     iParamID;		/* ������ʶ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sOppPath[81];		/* �Զ�·�� */
	char    sIp[17];		/* ����IP */
	char    sUserName[21];		/* �û��� */
	char    sPasswd[21];		/* ���� */
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
/*�������ݶ�̬��PUT_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetPutTaskParamToStruct(struct PutTaskParamStruct *p,
	struct PutTaskParamStructIn *pSource);
/**�Ա�PUT_TASK_PARAM�������ͷź���**/
void DestroyPutTaskParam(struct PutTaskParamStruct *ptHead);
int InitPutTaskParam(struct PutTaskParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ������ʶ */
	int     aiParamID[RCYL_TASK_PARAM_BUFLEN_IN];
		/* ������ */
	char    asTableName[RCYL_TASK_PARAM_BUFLEN_IN][31];
		/* �������� */
	char    asCondition[RCYL_TASK_PARAM_BUFLEN_IN][61];
		/* ��ʽ�ļ� */
	char    asExprFile[RCYL_TASK_PARAM_BUFLEN_IN][41];
		/* ����ģ�� */
	char    asTemplateID[RCYL_TASK_PARAM_BUFLEN_IN][11];
		/* ���봮 */
	char    asSplitStr[RCYL_TASK_PARAM_BUFLEN_IN][11];
		/* ���� */
	char    asVisitCode[RCYL_TASK_PARAM_BUFLEN_IN][10];
		/* ģ��� */
	char    asModule[RCYL_TASK_PARAM_BUFLEN_IN][4];
	char    asEffDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
	char    asExpDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
	char    asState[RCYL_TASK_PARAM_BUFLEN_IN][4];
	char    asStateDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
	char    asCreatedDate[RCYL_TASK_PARAM_BUFLEN_IN][15];
};
/*�����ṹ����*/
struct RcylTaskParamStruct{

	struct RcylTaskParamStruct *pNext;
	char	sSourceID[7];
	int	iTaskSeqNbr;
	int	iSeqNbr;
	int     iParamID;		/* ������ʶ */
	char    sTableName[31];		/* ������ */
	char    sCondition[61];		/* �������� */
	char    sExprFile[41];		/* ��ʽ�ļ� */
	char    sTemplateID[11];		/* ����ģ�� */
	char    sSplitStr[11];		/* ���봮 */
	char    sVisitCode[10];		/* ���� */
	char    sModule[4];		/* ģ��� */
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	struct RcylTaskParamStruct *pLoadNext;
};
/*�������ݶ�̬��RCYL_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetRcylTaskParamToStruct(struct RcylTaskParamStruct *p,
	struct RcylTaskParamStructIn *pSource);
/**�Ա�RCYL_TASK_PARAM�������ͷź���**/
void DestroyRcylTaskParam(struct RcylTaskParamStruct *ptHead);
int InitRcylTaskParam(struct RcylTaskParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ������ʶ */
	int     aiParamID[ROLL_TASK_PARAM_BUFLEN_IN];
		/* ������ */
	char    asTableName[ROLL_TASK_PARAM_BUFLEN_IN][31];
		/* ����ģ�� */
	char    asTemplateID[ROLL_TASK_PARAM_BUFLEN_IN][11];
		/* �������� */
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


/*�����ṹ����*/
struct RollTaskParamStruct{

	struct RollTaskParamStruct *pNext;
	char	sSourceID[7];
	int	iTaskSeqNbr;
	int	iSeqNbr;
	int     iParamID;		/* ������ʶ */
	char    sTableName[31];		/* ������ */
	char    sTemplateID[11];		/* ����ģ�� */
	char    sCondition[61];		/* �������� */
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
/*�������ݶ�̬��ROLL_TASK_PARAM���ýṹ���巽ʽȡ����*/
int EGetRollTaskParamToStruct(struct RollTaskParamStruct *p,
	struct RollTaskParamStructIn *pSource);
/**�Ա�ROLL_TASK_PARAM�������ͷź���**/
void DestroyRollTaskParam(struct RollTaskParamStruct *ptHead);
int InitRollTaskParam(struct RollTaskParamStruct **pptHead);


/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[ACCT_PARAM_BUFLEN_IN][7];
		/* Ⱥ���ʶ */
	int     aiGroupID[ACCT_PARAM_BUFLEN_IN];
		/* ���� */
	char    asFileType[ACCT_PARAM_BUFLEN_IN][6];
	char    asOperType[ACCT_PARAM_BUFLEN_IN][4];
		/* ���ڹ��� */
	char    asDateRule[ACCT_PARAM_BUFLEN_IN][13];
		/* Դ·�� */
	char    asSourcePath[ACCT_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asBackPath[ACCT_PARAM_BUFLEN_IN][81];
		/* ƥ����� */
	char    asFilter[ACCT_PARAM_BUFLEN_IN][21];
		/* ���ݹ������� */
	char    asBelongCode[ACCT_PARAM_BUFLEN_IN][6];
		/* ģ�� */
	char    asModule[ACCT_PARAM_BUFLEN_IN][4];
	
	char    asState[ACCT_PARAM_BUFLEN_IN][2];
		/* Ӧ�ñ�ʶ */
	char    asAppID[ACCT_PARAM_BUFLEN_IN][11];
		/* ���ڱ�ʶ */
	int     aiTacheID[ACCT_PARAM_BUFLEN_IN];
};
/*�����ṹ����*/
struct AcctParamStruct{

	struct AcctParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sFileType[6];		/* ���� */
	char    sOperType[4];
	char    sDateRule[13];		/* ���ڹ��� */
	char    sSourcePath[81];		/* Դ·�� */
	char    sBackPath[81];		/* ����·�� */
	char    sFilter[21];		/* ƥ����� */
	char    sBelongCode[6];		/* ���ݹ������� */
	char    sModule[4];		/* ģ�� */
	char	sState[2];
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iTacheID;		/* ���ڱ�ʶ */
	struct AcctParamStruct *pLoadNext;
};
/*�������ݶ�̬��ACCT_PARAM���ýṹ���巽ʽȡ����*/
int EGetAcctParamToStruct(struct AcctParamStruct *p,
	struct AcctParamStructIn *pSource);
/**�Ա�ACCT_PARAM�������ͷź���**/
void DestroyAcctParam(struct AcctParamStruct *ptHead);
int InitAcctParam(struct AcctParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* Ⱥ���ʶ */
	int     aiGroupID[INTF_PARAM_BUFLEN_IN];
		/* Դ·�� */
	char    asSourcePath[INTF_PARAM_BUFLEN_IN][81];
		/* ����·�� */
	char    asBackPath[INTF_PARAM_BUFLEN_IN][81];
		/* ���Ŀ¼ */
	char    asNormalPath[INTF_PARAM_BUFLEN_IN][81];
		/* ģʽ */
	char    asFilter[INTF_PARAM_BUFLEN_IN][21];
		/* ʱ�� */
	int     aiDelay[INTF_PARAM_BUFLEN_IN];
		/* ���д��� */
	char    asCityCode[INTF_PARAM_BUFLEN_IN][4];
		/* �����ļ����� */
	char    asFileType[INTF_PARAM_BUFLEN_IN][6];
	char	asState[INTF_PARAM_BUFLEN_IN][2];
	
	char	asAppID[INTF_PARAM_BUFLEN_IN][11];
	int     aiTacheID[INTF_PARAM_BUFLEN_IN];

};
/*�����ṹ����*/
struct IntfParamStruct{

	struct IntfParamStruct *pNext;
	char    sSourceID[7];
	int     iGroupID;		/* Ⱥ���ʶ */
	char    sSourcePath[81];		/* Դ·�� */
	char    sBackPath[81];		/* ����·�� */
	char    sNormalPath[81];		/* ���Ŀ¼ */
	char    sFilter[21];		/* ģʽ */
	int     iDelay;		/* ʱ�� */
	char    sCityCode[4];		/* ���д��� */
	char    sFileType[6];		/* �����ļ����� */
	char	sState[2];
	char	sAppID[11];
	int	iTacheID;
	struct IntfParamStruct *pLoadNext;
};

/*�������ݶ�̬��INTF_PARAM���ýṹ���巽ʽȡ����*/
int EGetIntfParamToStruct(struct IntfParamStruct *p,
	struct IntfParamStructIn *pSource);
/**�Ա�INTF_PARAM�������ͷź���**/
void DestroyIntfParam(struct IntfParamStruct *ptHead);
int InitIntfParam(struct IntfParamStruct **pptHead);
/* ����ṹ��������*/
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
		/* ��Դ��ʶ */
	char    asSourceID[RCYL_PARAM_BUFLEN_IN][7];
	int     aiTaskSeqNbr[INTF_PARAM_BUFLEN_IN];
		/* ���� */
	char    asTableName[RCYL_PARAM_BUFLEN_IN][31];
		/* �������� */
	char    asCondition[RCYL_PARAM_BUFLEN_IN][61];
		/* ��ʽ�ļ� */
	char    asExprFile[RCYL_PARAM_BUFLEN_IN][41];
		/* ����ģ�� */
	char    asTemplateID[RCYL_PARAM_BUFLEN_IN][11];
		/* ���Ŀ¼ */
	char    asNormalPath[RCYL_PARAM_BUFLEN_IN][81];
		/* ���봮 */
	char    asSplitStr[RCYL_PARAM_BUFLEN_IN][11];
		/* ���� */
	char    asVisitCode[RCYL_PARAM_BUFLEN_IN][10];
		/* ģ��� */
	char    asModule[RCYL_PARAM_BUFLEN_IN][4];
		/* ����ļ����� */
	char    asFileType[RCYL_PARAM_BUFLEN_IN][6];
	char	asAppID[INTF_PARAM_BUFLEN_IN][11];
	int     aiTacheID[INTF_PARAM_BUFLEN_IN];
	
};
/*�����ṹ����*/
struct RcylParamStruct{

	struct RcylParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ��ʶ */
	int     iTaskSeqNbr;
	char    sTableName[31];		/* ���� */
	char    sCondition[61];		/* �������� */
	char    sExprFile[41];		/* ��ʽ�ļ� */
	char    sTemplateID[11];		/* ����ģ�� */
	char    sNormalPath[81];		/* ���Ŀ¼ */
	char    sSplitStr[11];		/* ���봮 */
	char    sVisitCode[10];		/* ���� */
	char    sModule[4];		/* ģ��� */
	char    sFileType[6];		/* ����ļ����� */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iTacheID;		/* ���ڱ�ʶ */
	struct RcylParamStruct *pLoadNext;
};
/*�������ݶ�̬��RCYL_PARAM���ýṹ���巽ʽȡ����*/
int EGetRcylParamToStruct(struct RcylParamStruct *p,
	struct RcylParamStructIn *pSource);
/**�Ա�RCYL_PARAM�������ͷź���**/
void DestroyRcylParam(struct RcylParamStruct *ptHead);
int InitRcylParam(struct RcylParamStruct **pptHead);


/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[ROLL_PARAM_BUFLEN_IN][7];
	int     aiTaskSeqNbr[ROLL_PARAM_BUFLEN_IN];
		/* ������� */
	char    asTableName[ROLL_PARAM_BUFLEN_IN][31];
		/* �������� */
	char    asCondition[ROLL_PARAM_BUFLEN_IN][61];
	char	asUserType[ROLL_PARAM_BUFLEN_IN][41];
		/* ����ģ���ʶ */
	char    asTemplateID[ROLL_PARAM_BUFLEN_IN][11];
		/* ���Ŀ¼ */
	char    asNormalPath[ROLL_PARAM_BUFLEN_IN][81];
	char	asSplitType[ROLL_PARAM_BUFLEN_IN][2];
	char	asVisitCode[ROLL_PARAM_BUFLEN_IN][10];
	char	asModule[ROLL_PARAM_BUFLEN_IN][4];
		/* ����ļ����� */
	char    asFileType[ROLL_PARAM_BUFLEN_IN][6];
		/* Ӧ�ñ�ʶ */
	char    asAppID[ROLL_PARAM_BUFLEN_IN][11];
		/* ���ڱ�ʶ */
	int     aiTacheID[ROLL_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct RollParamStruct{

	struct RollParamStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	int     iTaskSeqNbr;
	char    sTableName[31];		/* ������� */
	char    sCondition[61];		/* �������� */
	char	sUserType[41];
	char    sTemplateID[11];		/* ����ģ���ʶ */
	char    sNormalPath[81];		/* ���Ŀ¼ */
	char	sSplitType[2];
	char	sVisitCode[10];
	char	sModule[4];
	char    sFileType[6];		/* ����ļ����� */
	char    sAppID[11];		/* Ӧ�ñ�ʶ */
	int     iTacheID;		/* ���ڱ�ʶ */
	struct RollParamStruct *pLoadNext;
};

/*�������ݶ�̬��ROLL_PARAM���ýṹ���巽ʽȡ����*/
int EGetRollParamToStruct(struct RollParamStruct *p,
	struct RollParamStructIn *pSource);
/**�Ա�ROLL_PARAM�������ͷź���**/
void DestroyRollParam(struct RollParamStruct *ptHead);
int InitRollParam(struct RollParamStruct **pptHead);


/* ����ṹ��������*/
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
		/* ��Դ */
	char    asSourceID[SOURCE_DESC_BUFLEN_IN][7];
	char    asSourceType[SOURCE_DESC_BUFLEN_IN][2];
		/* ˵�� */
	char    asRemark[SOURCE_DESC_BUFLEN_IN][41];
		/* ��������ʶ */
	int     aiLatnID[SOURCE_DESC_BUFLEN_IN];
		/* ԭ�ļ�ģʽ */
	char    asFilter[SOURCE_DESC_BUFLEN_IN][21];
		/* ��Դ�ļ����� */
	char    asFileType[SOURCE_DESC_BUFLEN_IN][6];
		/* ���̱�ʶ */
	int     aiFlowID[SOURCE_DESC_BUFLEN_IN];
};


/*�����ṹ����*/
struct SourceDescStruct{

	struct SourceDescStruct *pNext;
	char    sSourceID[7];		/* ��Դ */
	char    sSourceType[2];
	char    sRemark[41];		/* ˵�� */
	int     iLatnID;		/* ��������ʶ */
	char    sFilter[21];		/* Դģʽ */
	char    sFileType[6];		/* ��Դ�ļ����� */
	int     iFlowID;		/* ���̱�ʶ */
	struct SourceDescStruct *pLoadNext;
};
/*�������ݶ�̬��SOURCE_DESC���ýṹ���巽ʽȡ����*/
int EGetSourceDescToStruct(struct SourceDescStruct *p,
	struct SourceDescStructIn *pSource);
/**�Ա�SOURCE_DESC�������ͷź���**/
void DestroySourceDesc(struct SourceDescStruct *ptHead);
int InitSourceDesc(struct SourceDescStruct **pptHead);


#endif
