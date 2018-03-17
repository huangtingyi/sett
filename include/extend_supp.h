#ifndef __EXTEND_SUPP_H__
#define __EXTEND_SUPP_H__

#include <hnixs.h>
#include <wwfile.h>
#include <list.h>
#include <trie.h>


/* 输入结构缓冲申明*/
struct ExtendAttrDefRelationStructIn{

#ifndef EXTEND_ATTR_DEF_RELATION_BUFLEN_IN
#define EXTEND_ATTR_DEF_RELATION_BUFLEN_IN		300
#endif

	struct ExtendAttrDefRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiExtendAttrID[EXTEND_ATTR_DEF_RELATION_BUFLEN_IN];
	char    asAttrKey[EXTEND_ATTR_DEF_RELATION_BUFLEN_IN][41];
	char    asMethod[EXTEND_ATTR_DEF_RELATION_BUFLEN_IN][3];
	char    asTypeValue[EXTEND_ATTR_DEF_RELATION_BUFLEN_IN][21];
	int     aiPriority[EXTEND_ATTR_DEF_RELATION_BUFLEN_IN];
};


/*单个结构申明*/
struct ExtendAttrDefRelationStruct{

	struct ExtendAttrDefRelationStruct *pNext;
	int     iExtendAttrID;
	char    sAttrKey[41];
	char    sMethod[3];
	char    sTypeValue[21];
	int     iPriority;
	struct ExtendAttrDefRelationStruct *pLoadNext;
};

/*批量数据动态从EXTEND_ATTR_DEF_RELATION中用结构缓冲方式取数据*/
int EGetExtendAttrDefRelationToStruct(struct ExtendAttrDefRelationStruct *p,
	struct ExtendAttrDefRelationStructIn *pSource);
/**对表EXTEND_ATTR_DEF_RELATION的链表释放函数**/
void DestroyExtendAttrDefRelation(struct ExtendAttrDefRelationStruct *ptHead);
int InitExtendAttrDefRelation(struct ExtendAttrDefRelationStruct **pptHead);

/* 输入结构缓冲申明*/
struct ExtendAttrStructIn{

#ifndef EXTEND_ATTR_BUFLEN_IN
#define EXTEND_ATTR_BUFLEN_IN		300
#endif

	struct ExtendAttrStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiExtendAttrID[EXTEND_ATTR_BUFLEN_IN];
	int     aiAttrID[EXTEND_ATTR_BUFLEN_IN];
	int     aiExtendSeq[EXTEND_ATTR_BUFLEN_IN];
	char    asName[EXTEND_ATTR_BUFLEN_IN][41];
	char    asRemark[EXTEND_ATTR_BUFLEN_IN][401];
		/* 标识 */
	char    asFlag[EXTEND_ATTR_BUFLEN_IN][2];
		/* 查找方法 */
	char    asSearchMethod[EXTEND_ATTR_BUFLEN_IN][21];
		/* 值域SQL */
	char    asValueSql[EXTEND_ATTR_BUFLEN_IN][201];

};


/*单个结构申明*/
struct ExtendAttrStruct{

	struct ExtendAttrStruct *pNext;
	int     iExtendAttrID;
	int     iAttrID;
	int     iExtendSeq;
	char    sName[41];
	char    sRemark[401];
	char    sFlag[2];		/* 标识 */
	char    sSearchMethod[21];		/* 查找方法 */
	char    sValueSql[201];		/* 值域SQL */

	struct ExtendAttrStruct *pLoadNext;
};

/*批量数据动态从EXTEND_ATTR中用结构缓冲方式取数据*/
int EGetExtendAttrToStruct(struct ExtendAttrStruct *p,
	struct ExtendAttrStructIn *pSource);
/**对表EXTEND_ATTR的链表释放函数**/
void DestroyExtendAttr(struct ExtendAttrStruct *ptHead);
int InitExtendAttr(struct ExtendAttrStruct **pptHead);

/* 输入结构缓冲申明*/
struct ExtendAttrValueStructIn{

#ifndef EXTEND_ATTR_VALUE_BUFLEN_IN
#define EXTEND_ATTR_VALUE_BUFLEN_IN		300
#endif

	struct ExtendAttrValueStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiValueID[EXTEND_ATTR_VALUE_BUFLEN_IN];
	int     aiExtendAttrID[EXTEND_ATTR_VALUE_BUFLEN_IN];
	char    asValue[EXTEND_ATTR_VALUE_BUFLEN_IN][21];
	char    asName[EXTEND_ATTR_VALUE_BUFLEN_IN][41];
	char    asRemark[EXTEND_ATTR_VALUE_BUFLEN_IN][401];
	char    asEffDate[EXTEND_ATTR_VALUE_BUFLEN_IN][15];
	char    asStdCode[EXTEND_ATTR_VALUE_BUFLEN_IN][21];
};


/*单个结构申明*/
struct ExtendAttrValueStruct{

	struct ExtendAttrValueStruct *pNext;
	int	iValueID;
	int     iExtendAttrID;
	char    sValue[21];
	char    sName[41];
	char    sRemark[401];
	char    sEffDate[15];
	char	sStdCode[21];
	struct ExtendAttrValueStruct *pLoadNext;
};



/*批量数据动态从EXTEND_ATTR_VALUE中用结构缓冲方式取数据*/
int EGetExtendAttrValueToStruct(struct ExtendAttrValueStruct *p,
	struct ExtendAttrValueStructIn *pSource);
/**对表EXTEND_ATTR_VALUE的链表释放函数**/
void DestroyExtendAttrValue(struct ExtendAttrValueStruct *ptHead);
int InitExtendAttrValue(struct ExtendAttrValueStruct **pptHead);

/* 输入结构缓冲申明*/
struct AttrStructIn{

#ifndef ATTR_BUFLEN_IN
#define ATTR_BUFLEN_IN		300
#endif

	struct AttrStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiAttrID[ATTR_BUFLEN_IN];
	char    asName[ATTR_BUFLEN_IN][41];
	char    asGrade[ATTR_BUFLEN_IN][2];
	char    asValueType[ATTR_BUFLEN_IN][2];
	char    asValueSql[ATTR_BUFLEN_IN][201];
	char	asStdCode[ATTR_BUFLEN_IN][9];
};


/*单个结构申明*/
struct AttrStruct{

	struct AttrStruct *pNext;
	int     iAttrID;
	char    sName[41];
	char    sGrade[2];
	char    sValueType[2];
	char    sValueSql[201];
	char	sStdCode[9];
	
	int	iFlag;	/*加载标识,仅枚举值时有效,0,未加载数据,1已加载数据*/
	TRIE	*pTrie; /*value,name的键树*/
	struct AttrStruct *pLoadNext;
};

/*批量数据动态从ATTR中用结构缓冲方式取数据*/
int EGetAttrToStruct(struct AttrStruct *p,struct AttrStructIn *pSource);
/**对表ATTR的链表释放函数**/
void DestroyAttr(struct AttrStruct *ptHead);
int InitAttr(struct AttrStruct **pptHead);

/* 输入结构缓冲申明*/
struct TableFormatStructIn{

#ifndef TABLE_FORMAT_BUFLEN_IN
#define TABLE_FORMAT_BUFLEN_IN		300
#endif

	struct TableFormatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 话单格式标识 */
	int     aiFormatID[TABLE_FORMAT_BUFLEN_IN];
		/* 描述 */
	char    asRemark[TABLE_FORMAT_BUFLEN_IN][41];
		/* 模版标识 */
	int     aiTemplateID[TABLE_FORMAT_BUFLEN_IN];
};


/*单个结构申明*/
struct TableFormatStruct{

	struct TableFormatStruct *pNext;
	int     iFormatID;		/* 话单格式标识 */
	char    sRemark[41];		/* 描述 */
	int     iTemplateID;		/* 模版标识 */
	struct TableFormatStruct *pLoadNext;
};


/*批量数据动态从TABLE_FORMAT中用结构缓冲方式取数据*/
int EGetTableFormatToStruct(struct TableFormatStruct *p,
	struct TableFormatStructIn *pSource);
/**对表TABLE_FORMAT的链表释放函数**/
void DestroyTableFormat(struct TableFormatStruct *ptHead);
int InitTableFormat(struct TableFormatStruct **pptHead);

/* 输入结构缓冲申明*/
struct TabTemplateStructIn{

#ifndef TAB_TEMPLATE_BUFLEN_IN
#define TAB_TEMPLATE_BUFLEN_IN		300
#endif

	struct TabTemplateStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiTemplateID[TAB_TEMPLATE_BUFLEN_IN];
	int     aiFormatID[TAB_TEMPLATE_BUFLEN_IN];
	char    asTemplateName[TAB_TEMPLATE_BUFLEN_IN][31];
	char    asTemplateRemark[TAB_TEMPLATE_BUFLEN_IN][61];
};


/*单个结构申明*/
struct TabTemplateStruct{

	struct TabTemplateStruct *pNext;
	int     iTemplateID;
	int     iFormatID;
	char    sTemplateName[31];
	char    sTemplateRemark[61];
	struct TabTemplateStruct *pLoadNext;
};


/*批量数据动态从TAB_TEMPLATE中用结构缓冲方式取数据*/
int EGetTabTemplateToStruct(struct TabTemplateStruct *p,
	struct TabTemplateStructIn *pSource);
/**对表TAB_TEMPLATE的链表释放函数**/
void DestroyTabTemplate(struct TabTemplateStruct *ptHead);
int InitTabTemplate(struct TabTemplateStruct **pptHead);

/* 输入结构缓冲申明*/
struct TabColumnsStructIn{

#ifndef TAB_COLUMNS_BUFLEN_IN
#define TAB_COLUMNS_BUFLEN_IN		300
#endif

	struct TabColumnsStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 字段标识 */
	int     aiColumnID[TAB_COLUMNS_BUFLEN_IN];
		/* 模版表标识 */
	int     aiTemplateID[TAB_COLUMNS_BUFLEN_IN];
		/* 字段名称 */
	char    asColumnName[TAB_COLUMNS_BUFLEN_IN][41];
		/* 数据类型 */
	char    asDataType[TAB_COLUMNS_BUFLEN_IN][31];
		/* 字段长度 */
	int     aiLen[TAB_COLUMNS_BUFLEN_IN];
		/* 字段说明 */
	char    asColumnRemark[TAB_COLUMNS_BUFLEN_IN][61];
		/* 字段精度 */
	int     aiScale[TAB_COLUMNS_BUFLEN_IN];
		/* 能否为空 */
	char    asNullable[TAB_COLUMNS_BUFLEN_IN][2];
		/* 字段序号 */
	int     aiColumnSeq[TAB_COLUMNS_BUFLEN_IN];
	
};


/*单个结构申明*/
struct TabColumnsStruct{

	struct TabColumnsStruct *pNext;
	int     iColumnID;		/* 字段标识 */
	int     iTemplateID;		/* 模版表标识 */
	char    sColumnName[41];		/* 字段名称 */
	char    sDataType[31];		/* 数据类型 */
	int     iLen;		/* 字段长度 */
	char    sColumnRemark[61];		/* 字段说明 */
	int     iScale;		/* 字段精度 */
	char    sNullable[2];		/* 能否为空 */
	int     iColumnSeq;		/* 字段序号 */
	
	/*后面增加的*/
	int     iOffset;        /*相对于头字段的偏移*/
        int     iSeq;           /*表示第N个字段*/
        int	iPos;		/*存放的是字段在TFIELD的偏移量*/
        int	iState;		/*1为该字段被分离模板使用到，0为未使用*/
        
        struct TabColumnsStruct *pHead;/*原始字段*/
        
	struct TabColumnsStruct *pLoadNext;
};


/*批量数据动态从TAB_COLUMNS中用结构缓冲方式取数据*/
int EGetTabColumnsToStruct(struct TabColumnsStruct *p,
	struct TabColumnsStructIn *pSource);
/**对表TAB_COLUMNS的链表释放函数**/
void DestroyTabColumns(struct TabColumnsStruct *ptHead);
int InitTabColumns(struct TabColumnsStruct **pptHead);

/* 输入结构缓冲申明*/
struct TabTemplateRealStructIn{

#ifndef TAB_TEMPLATE_REAL_BUFLEN_IN
#define TAB_TEMPLATE_REAL_BUFLEN_IN		300
#endif

	struct TabTemplateRealStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 模版表标识 */
	int     aiTemplateID[TAB_TEMPLATE_REAL_BUFLEN_IN];
		/* 实际表名称 */
	char    asRealName[TAB_TEMPLATE_REAL_BUFLEN_IN][60];
		/* 实际表说明 */
	char    asRealRemark[TAB_TEMPLATE_REAL_BUFLEN_IN][41];
};


/*单个结构申明*/
struct TabTemplateRealStruct{

	struct TabTemplateRealStruct *pNext;
	int     iTemplateID;		/* 模版表标识 */
	char    sRealName[60];		/* 实际表名称 */
	char    sRealRemark[41];		/* 实际表说明 */
	struct TabTemplateRealStruct *pLoadNext;
};

/*批量数据动态从TAB_TEMPLATE_REAL中用结构缓冲方式取数据*/
int EGetTabTemplateRealToStruct(struct TabTemplateRealStruct *p,
	struct TabTemplateRealStructIn *pSource);
/**对表TAB_TEMPLATE_REAL的链表释放函数**/
void DestroyTabTemplateReal(struct TabTemplateRealStruct *ptHead);
int InitTabTemplateReal(struct TabTemplateRealStruct **pptHead);

/* 输入结构缓冲申明*/
struct PromiseElementStructIn{

#ifndef PROMISE_ELEMENT_BUFLEN_IN
#define PROMISE_ELEMENT_BUFLEN_IN		300
#endif

	struct PromiseElementStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 要素ID */
	int     aiPromiseElementID[PROMISE_ELEMENT_BUFLEN_IN];
		/*主承诺要素ID*/
	int	aiPrimaryElementID[PROMISE_ELEMENT_BUFLEN_IN];
		/* 服务类型 */
	char    asServiceType[PROMISE_ELEMENT_BUFLEN_IN][5];
		/* '0' 标识针对所有用户的承诺，'1'标识针对特定用户的承诺 */
	char    asAffectType[PROMISE_ELEMENT_BUFLEN_IN][2];
		/* 承诺类型 */
	char    asPromiseType[PROMISE_ELEMENT_BUFLEN_IN][2];
		/* 用于业务宣传 */
	char    asName[PROMISE_ELEMENT_BUFLEN_IN][41];
		/* 要素全称 */
	char    asStdName[PROMISE_ELEMENT_BUFLEN_IN][81];
		/* 要素详述 */
	char    asRemark[PROMISE_ELEMENT_BUFLEN_IN][401];
		/* 费率单位（默认） */
	char    asRateUnit[PROMISE_ELEMENT_BUFLEN_IN][2];
		/* 展示序号 */
	int     aiDisplaySeq[PROMISE_ELEMENT_BUFLEN_IN];
	int	aiPriority[PROMISE_ELEMENT_BUFLEN_IN];
};

#define	PRIORITY_ALL_FEE_HIGHEST	1
#define	PRIORITY_ALL_FEE_HIGHER		2
#define	PRIORITY_THIS_FEE_HIGHEST	3
#define	PRIORITY_THIS_FEE_HIGHER	4
#define	PRIORITY_THIS_FEE_MIDDLE	5
#define	PRIORITY_THIS_FEE_LOW		6

#define BILL_GRADE_SUB_BILL_TYPE	1
#define BILL_GRADE_BILL_TYPE		2
#define BILL_GRADE_SERV_TYPE		3
#define BILL_GRADE_COMMON		4
#define BILL_GRADE_OTHER		5

/*单个结构申明*/
struct PromiseElementStruct{

	struct PromiseElementStruct *pNext;
	int     iPromiseElementID;		/* 要素ID */
	int	iPrimaryElementID;		/*主承诺要素ID*/
	char    sServiceType[5];		/* 服务类型 */
	char    sAffectType[2];		/* '0' 标识针对所有用户的承诺，'1'标识针对特定用户的承诺 */
	char    sPromiseType[2];		/* 承诺类型 */
	char    sName[41];		/* 用于业务宣传 */
	char    sStdName[81];		/* 要素全称 */
	char    sRemark[401];		/* 要素详述 */
	char    sRateUnit[2];		/* 费率单位（默认） */
	int     iDisplaySeq;		/* 展示序号 */
	
/*
V 名称		备注
1 全费最优	全费用最优先，所有费用排他性优先;
2 全费较优	全费用较优先，除了全费用最优先，所有费用排他性优先;
3 最优		配置的费用排他性优先；
4 较优		配置的费用除了最优先，排他性比较优先；
5 普通		配置的费率除了0-3级别，按费率低为原则;
6 不优先	配置的费率优先级最低.*/
	
	int	iPriority;
/*
V 套餐优先级
1 子套餐级
2 主套餐级
3 业务品牌级
4 通用资费级
5 不相关承诺要素
*/
	int	iBillGrade;
	
	struct PromiseElementStruct *pLoadNext;
};


/*批量数据动态从PROMISE_ELEMENT中用结构缓冲方式取数据*/
int EGetPromiseElementToStruct(struct PromiseElementStruct *p,
	struct PromiseElementStructIn *pSource);
/**对表PROMISE_ELEMENT的链表释放函数**/
void DestroyPromiseElement(struct PromiseElementStruct *ptHead);
int InitPromiseElement(struct PromiseElementStruct **pptHead);

/* 输入结构缓冲申明*/
struct PromiseTariffStructIn{

#ifndef PROMISE_TARIFF_BUFLEN_IN
#define PROMISE_TARIFF_BUFLEN_IN		300
#endif

	struct PromiseTariffStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 承诺费率标识 */
	int     aiTariffID[PROMISE_TARIFF_BUFLEN_IN];
		/* 要素ID */
	int     aiPromiseElementID[PROMISE_TARIFF_BUFLEN_IN];
		/* 计量分段ID */
	int     aiMeasureSpanID[PROMISE_TARIFF_BUFLEN_IN];
		/* 计费时段组ID */
	int     aiTimeSpanGrpID[PROMISE_TARIFF_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[PROMISE_TARIFF_BUFLEN_IN][21];
		/* T 表示话单级承诺,A 表示账单级承诺 */
	char    asPromiseType[PROMISE_TARIFF_BUFLEN_IN][2];
		/* 展示序号 */
	int     aiDisplaySeq[PROMISE_TARIFF_BUFLEN_IN];
		/* 如果AREA_CODE为"*"表示对全省 */
	char    asAreaCode[PROMISE_TARIFF_BUFLEN_IN][10];
		/* 费率(元次) */
	double  adRate[PROMISE_TARIFF_BUFLEN_IN];
		/* 费率单位 */
	char    asRateUnit[PROMISE_TARIFF_BUFLEN_IN][2];
		/* 'A0A' 再用，‘A0X'注销，'A0H'历史 */
	char	asRateMethod[PROMISE_TARIFF_BUFLEN_IN][2];
	
	int	aiRateID[PROMISE_TARIFF_BUFLEN_IN];
	
	char    asState[PROMISE_TARIFF_BUFLEN_IN][4];
		/* 账目类型标识 */
	int     aiAcctItemTypeID[PROMISE_TARIFF_BUFLEN_IN];
		/* 通话区域类型标识 */
	int     aiCallAreaTypeID[PROMISE_TARIFF_BUFLEN_IN];
};


/*单个结构申明*/
struct PromiseTariffStruct{

	struct PromiseTariffStruct *pNext;
	int     iTariffID;		/* 承诺费率标识 */
	int     iPromiseElementID;		/* 要素ID */
	int     iMeasureSpanID;		/* 计量分段ID */
	int     iTimeSpanGrpID;		/* 计费时段组ID */
	char    sBillingTypeID[21];		/* 套餐ID */
	char    sPromiseType[2];		/* T 表示话单级承诺,A 表示账单级承诺 */
	int     iDisplaySeq;		/* 展示序号 */
	char    sAreaCode[10];		/* 如果AREA_CODE为"*"表示对全省 */
	double  dRate;			/* 费率(元次) */
	char    sRateUnit[2];		/* 费率单位 */
	char	sRateMethod[2];		
/* 费率应用方法'R'直接取RATE值,'P'表示PARAM_CODE_DESC.PARAM_ID,
	'E'表示PARAM_EXPR_DESC.EXPR_ID */
	int	iRateID;		/* 费率参数编码 */
	char    sState[4];		/* 'A0A' 再用，‘A0X'注销，'A0H'历史 */
	int     iAcctItemTypeID;		/* 账目类型标识 */
	int     iCallAreaTypeID;		/* 通话区域类型标识 */
	struct PromiseTariffStruct *pLoadNext;
	
	int	iMeasureSpanTypeID;
	int	iTimeSpanTypeID;

	struct MeasureSpanStruct *pMeasureSpan;
	struct TimeSpanGrpStruct *pTimeSpanGrp;

	int	iRateUnit;
	double  dAdjustRate;			/* 调整后费率(元次) */
	int	iPriority;			/*取优先级*/
	int	iElementPriority;		/*要素优先级*/
	int	iBillGrade;			/*套餐优先级*/
	char	sEffectType[2];			/*作用类型*/

	struct PromiseTariffStruct *pTariff;
};

/*批量数据动态从PROMISE_TARIFF中用结构缓冲方式取数据*/
int EGetPromiseTariffToStruct(struct PromiseTariffStruct *p,
	struct PromiseTariffStructIn *pSource);
/**对表PROMISE_TARIFF的链表释放函数**/
void DestroyPromiseTariff(struct PromiseTariffStruct *ptHead);
int InitPromiseTariff(struct PromiseTariffStruct **pptHead);

/* 输入结构缓冲申明*/
struct MeasureFieldFeeStructIn{

#ifndef MEASURE_FIELD_FEE_BUFLEN_IN
#define MEASURE_FIELD_FEE_BUFLEN_IN		300
#endif

	struct MeasureFieldFeeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 程序对字段标识有约束 */
	int     aiMeasureFieldID[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* 程序对字段标识有约束 */
	int     aiFeeFieldID[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* 账目类型标识 */
	int     aiAcctItemTypeID[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* 费用字段序列号 */
	int	aiFeeFieldIDSeq[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* 话单格式标识 */
	int	aiFormatID[MEASURE_FIELD_FEE_BUFLEN_IN];
};


/*单个结构申明*/
struct MeasureFieldFeeStruct{

	struct MeasureFieldFeeStruct *pNext;
	int     iMeasureFieldID;		/* 程序对字段标识有约束 */
	int     iFeeFieldID;			/* 程序对字段标识有约束 */
	int     iAcctItemTypeID;		/* 账目类型标识 */
	int	iFeeFieldIDSeq;		/* 费用字段序列号 */
	int	iFormatID;		/* 话单格式标识 */
	struct MeasureFieldFeeStruct *pLoadNext;
};

/*批量数据动态从MEASURE_FIELD_FEE中用结构缓冲方式取数据*/
int EGetMeasureFieldFeeToStruct(struct MeasureFieldFeeStruct *p,
	struct MeasureFieldFeeStructIn *pSource);
/**对表MEASURE_FIELD_FEE的链表释放函数**/
void DestroyMeasureFieldFee(struct MeasureFieldFeeStruct *ptHead);
int InitMeasureFieldFee(struct MeasureFieldFeeStruct **pptHead);



/* 输入结构缓冲申明*/
struct MeasureSpanStructIn{

#ifndef MEASURE_SPAN_BUFLEN_IN
#define MEASURE_SPAN_BUFLEN_IN		300
#endif

	struct MeasureSpanStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 计量分段ID */
	int     aiMeasureSpanID[MEASURE_SPAN_BUFLEN_IN];
		/* 分段类型标识 */
	int     aiMeasureSpanTypeID[MEASURE_SPAN_BUFLEN_IN];
		/* 分段起始量 */
	int     aiBeginCnt[MEASURE_SPAN_BUFLEN_IN];
		/* 分段终止量 */
	int     aiEndCnt[MEASURE_SPAN_BUFLEN_IN];
		/* 分段名称 */
	char    asName[MEASURE_SPAN_BUFLEN_IN][41];
		/* 服务类型 */
	char    asServiceType[MEASURE_SPAN_BUFLEN_IN][5];
		/* T 单条记录内使用,A月统计汇总信息分段 */
	char    asUseType[MEASURE_SPAN_BUFLEN_IN][2];
	char	asRateUnit[MEASURE_SPAN_BUFLEN_IN][2];
};


/*单个结构申明*/
struct MeasureSpanStruct{

	struct MeasureSpanStruct *pNext;
	int     iMeasureSpanID;		/* 计量分段ID */
	int     iMeasureSpanTypeID;		/* 分段类型标识 */
	int     iBeginCnt;		/* 分段起始量 */
	int     iEndCnt;		/* 分段终止量 */
	char    sName[41];		/* 分段名称 */
	char    sServiceType[5];		/* 服务类型 */
	char    sUseType[2];		/* T 单条记录内使用,A月统计汇总信息分段 */
	char	sRateUnit[2];		/*单位*/
	int	iBeginValue;
	int 	iEndValue;
	struct MeasureSpanStruct *pLoadNext;
};
/*批量数据动态从MEASURE_SPAN中用结构缓冲方式取数据*/
int EGetMeasureSpanToStruct(struct MeasureSpanStruct *p,
	struct MeasureSpanStructIn *pSource);
/**对表MEASURE_SPAN的链表释放函数**/
void DestroyMeasureSpan(struct MeasureSpanStruct *ptHead);
int InitMeasureSpan(struct MeasureSpanStruct **pptHead);



/* 输入结构缓冲申明*/
struct TimeSpanGrpStructIn{

#ifndef TIME_SPAN_GRP_BUFLEN_IN
#define TIME_SPAN_GRP_BUFLEN_IN		300
#endif

	struct TimeSpanGrpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 计费时段组ID */
	int     aiTimeSpanGrpID[TIME_SPAN_GRP_BUFLEN_IN];
		/* 时段类型标识 */
	int     aiTimeSpanTypeID[TIME_SPAN_GRP_BUFLEN_IN];
		/*时段条件标识*/
	char	asConditionType[TIME_SPAN_GRP_BUFLEN_IN][2];
		/* 名称 */
	char    asName[TIME_SPAN_GRP_BUFLEN_IN][41];
	
	int     aiTimeSpanID[TIME_SPAN_GRP_BUFLEN_IN];
	char    asBeginTime[TIME_SPAN_GRP_BUFLEN_IN][7];
	char    asEndTime[TIME_SPAN_GRP_BUFLEN_IN][7];
	char    asDateType[TIME_SPAN_GRP_BUFLEN_IN][2];
	char	asBeginFlag[TIME_SPAN_GRP_BUFLEN_IN][2];
};


/*单个结构申明*/
struct TimeSpanGrpStruct{

	struct TimeSpanGrpStruct *pNext;
	int     iTimeSpanGrpID;		/* 计费时段组ID */
	int     iTimeSpanTypeID;		/* 时段类型标识 */
	char	sConditionType[2];	
/*时段条件标识，'A' 都成立,'B' 只有主套餐有该时段时子套餐才有效*/
	char    sName[41];		/* 名称 */

	int	iTimeSpanID;
	char	sBeginTime[7];
	char	sEndTime[7];
/*W :工作日期，H:法定节假日,A:所有日期*/
	char	sDateType[2];
	char	sBeginFlag[2];

	int	iBeginTime;	/*离每天零时的秒数*/
	int	iEndTime;	/*离每天零时的秒数*/

	struct TimeSpanGrpStruct *pLoadNext;
};
/*批量数据动态从TIME_SPAN_GRP中用结构缓冲方式取数据*/
int EGetTimeSpanGrpToStruct(struct TimeSpanGrpStruct *p,
	struct TimeSpanGrpStructIn *pSource);
/**对表TIME_SPAN_GRP的链表释放函数**/
void DestroyTimeSpanGrp(struct TimeSpanGrpStruct *ptHead);
int InitTimeSpanGrp(struct TimeSpanGrpStruct **pptHead);

/* 输入结构缓冲申明*/
struct ValueNameStructIn{

#ifndef VALUE_NAME_BUFLEN_IN
#define VALUE_NAME_BUFLEN_IN		300
#endif

	struct ValueNameStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[2048];
	char sCondition[1024];
	
	char	asValue[VALUE_NAME_BUFLEN_IN][32];
	char	asName[VALUE_NAME_BUFLEN_IN][32];
};
struct ValueNameStruct{
	
	struct ValueNameStruct *pNext;
	char	sValue[32];	/*具体值*/
	char	sName[32];	/*具体值名称*/
	int	iValueLen;
	struct ValueNameStruct *pLoadNext;
};
int EGetValueNameToStruct(struct ValueNameStruct *p,
	struct ValueNameStructIn *pSource);
TRIE *GetValueNameTrie(char sMicro[],char sSql[]);

int GetFormatIDByTemplateRuleID(int iTemplateRuleID);
int GetTemplateIDByFormatID(int iFormatID);


/* 输入结构缓冲申明*/
struct HolidayStructIn{

#ifndef HOLIDAY_BUFLEN_IN
#define HOLIDAY_BUFLEN_IN		300
#endif

	struct HolidayStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
/* 日期 */
	char    asDates[HOLIDAY_BUFLEN_IN][15];
	char    asType[HOLIDAY_BUFLEN_IN][13];
	char    asRemark[HOLIDAY_BUFLEN_IN][41];
};


/*单个结构申明*/
struct HolidayStruct{

	struct HolidayStruct *pNext;
	char	sDates[15];
	char	sType[13];
	char	sRemark[41];
	
	char	cDateType;
	time_t tDates;

	struct HolidayStruct *pLoadNext;
};

/*批量数据动态从TIME_SPAN_GRP中用结构缓冲方式取数据*/
int EGetHolidayToStruct(struct HolidayStruct *p,
	struct HolidayStructIn *pSource);
/**对表TIME_SPAN_GRP的链表释放函数**/
void DestroyHoliday(struct HolidayStruct *ptHead);
int InitHoliday(struct HolidayStruct **pptHead);


/*输出结构缓冲申明*/
struct AcctItemStructOut{

#ifndef ACCT_ITEM_BUFLEN_OUT
#define ACCT_ITEM_BUFLEN_OUT		300
#endif

	struct AcctItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐目流水 */
	char    asAcctItemID[ACCT_ITEM_BUFLEN_OUT][13];
		/* 接入号码号 */
	char    asAccNbr[ACCT_ITEM_BUFLEN_OUT][21];
		/* 帐目类别 */
	int     aiAcctItemTypeID[ACCT_ITEM_BUFLEN_OUT];
		/* 费用 */
	int     aiCharge[ACCT_ITEM_BUFLEN_OUT];
		/* 归属地市 */
	char    asAreaCode[ACCT_ITEM_BUFLEN_OUT][10];
		/* 处理状态 */
	char    asState[ACCT_ITEM_BUFLEN_OUT][2];
		/* 帐务周期 */
	int     aiBillingCycleID[ACCT_ITEM_BUFLEN_OUT];
		/* 帐目归属日期 */
	char    asAcctItemDate[ACCT_ITEM_BUFLEN_OUT][15];
		/* 账目类别 */
	char	asAcctType[ACCT_ITEM_BUFLEN_OUT][2];
		/* 稽核账目ID */
	int	aiAuditItemTypeID[ACCT_ITEM_BUFLEN_OUT];
	int	aiAcctID[ACCT_ITEM_BUFLEN_OUT];
	int	aiDefaultAcctID[ACCT_ITEM_BUFLEN_OUT];
	
	char    asAuditState[ACCT_ITEM_BUFLEN_OUT][2];
	char    asAuditDetailState[ACCT_ITEM_BUFLEN_OUT][6];
	char    asAuditDate[ACCT_ITEM_BUFLEN_OUT][15];
	int     aiAuditDiffFee[ACCT_ITEM_BUFLEN_OUT];
	char    asAuditInfo[ACCT_ITEM_BUFLEN_OUT][161];
	char    asOriAcctItemID[ACCT_ITEM_BUFLEN_OUT][16];
	char    asAuditBillingTypeID[ACCT_ITEM_BUFLEN_OUT][21];
	char    asAuditAreaCode[ACCT_ITEM_BUFLEN_OUT][6];
	int     aiAuditTariffId1[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditTariffId2[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditTariffId3[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditFee1[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditFee2[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditFee3[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditOriFee1[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditOriFee2[ACCT_ITEM_BUFLEN_OUT];
	int     aiAuditOriFee3[ACCT_ITEM_BUFLEN_OUT];
	char    asAuditType1[ACCT_ITEM_BUFLEN_OUT][21];
	char    asAuditType2[ACCT_ITEM_BUFLEN_OUT][21];
	char    asAuditType3[ACCT_ITEM_BUFLEN_OUT][21];

};


/* 输入结构缓冲申明*/
struct AcctItemStructIn{

#ifndef ACCT_ITEM_BUFLEN_IN
#define ACCT_ITEM_BUFLEN_IN		300
#endif

	struct AcctItemStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐目流水 */
	char    asAcctItemID[ACCT_ITEM_BUFLEN_IN][13];
		/* 接入号码号 */
	char    asAccNbr[ACCT_ITEM_BUFLEN_IN][21];
		/* 帐目类别 */
	int     aiAcctItemTypeID[ACCT_ITEM_BUFLEN_IN];
		/* 费用 ,单位为厘*/
	int     aiCharge[ACCT_ITEM_BUFLEN_IN];
		/* 归属地市 */
	char    asAreaCode[ACCT_ITEM_BUFLEN_IN][10];
		/* 账目状态,'0'基本账目,'1'优惠账目,1时，charge为负*/
	char    asState[ACCT_ITEM_BUFLEN_IN][2];
		/* 帐务周期 */
	int     aiBillingCycleID[ACCT_ITEM_BUFLEN_IN];
		/* 帐目归属日期 */
	char    asAcctItemDate[ACCT_ITEM_BUFLEN_IN][15];
		/* 稽核账目ID */
	int	aiAuditItemTypeID[ACCT_ITEM_BUFLEN_IN];
		/* 账目类别 */
	char	asAcctType[ACCT_ITEM_BUFLEN_IN][2];
		/* 账目ID */
	int	aiAcctID[ACCT_ITEM_BUFLEN_IN];
	int	aiDefaultAcctID[ACCT_ITEM_BUFLEN_IN];
	
	
};
/* 输入结构缓冲申明*/
struct AcctItemAllFieldStructIn{

#ifndef ACCT_ITEM_ALL_BUFLEN_IN
#define ACCT_ITEM_ALL_BUFLEN_IN		300
#endif

	struct AcctItemAllFieldStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐目流水 */
	char    asAcctItemID[ACCT_ITEM_ALL_BUFLEN_IN][13];
		/* 接入号码号 */
	char    asAccNbr[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* 帐目类别 */
	int     aiAcctItemTypeID[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 费用 */
	int    aiCharge[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 归属地市 */
	char    asAreaCode[ACCT_ITEM_ALL_BUFLEN_IN][10];
		/* 处理状态 */
	char    asState[ACCT_ITEM_ALL_BUFLEN_IN][2];
		/* 帐务周期 */
	int     aiBillingCycleID[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 帐目归属日期 */
	char    asAcctItemDate[ACCT_ITEM_ALL_BUFLEN_IN][15];
		/* 稽核账目ID */
	int     aiAuditItemTypeID[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 'P' 所有费用审核且一致; 'F' 所有费用审核，存在不一致;'X' 存在费用未审核到字段. */
	char    asAuditState[ACCT_ITEM_ALL_BUFLEN_IN][2];
		/* 每一个字符，对应一个费用审核信息.'E' 审核完全一致'L' 审核费用比原费用少'G' 审核费用比原费用高'N' 未配置审核规则,该字段未审核到. */
	char    asAuditDetailState[ACCT_ITEM_ALL_BUFLEN_IN][6];
		/* 稽核日期 */
	char    asAuditDate[ACCT_ITEM_ALL_BUFLEN_IN][15];
		/* 单位为厘，表示稽核结果总费用－原系统生成费用 */
	int    aiAuditDiffFee[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 稽核结果输出中文信息 */
	char    asAuditInfo[ACCT_ITEM_ALL_BUFLEN_IN][161];
		/* 原始帐目流水对应计费帐户费用明细的编号 */
	char    asOriAcctItemID[ACCT_ITEM_ALL_BUFLEN_IN][16];
		/* 稽核号码套餐类型 */
	char    asAuditBillingTypeID[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* 稽核号码归属地 */
	char    asAuditAreaCode[ACCT_ITEM_ALL_BUFLEN_IN][6];
		/* 稽核资费一ID */
	int     aiAuditTariffId1[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 稽核资费二ID */
	int     aiAuditTariffId2[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 稽核资费三ID */
	int     aiAuditTariffId3[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 稽核费用一 */
	int    aiAuditFee1[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 稽核费用二 */
	int    aiAuditFee2[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 稽核费用三 */
	int    aiAuditFee3[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 对方费用一 */
	int    aiAuditOriFee1[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 对方费用二 */
	int    aiAuditOriFee2[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 对方费用三 */
	int    aiAuditOriFee3[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 稽核套餐一 */
	char    asAuditType1[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* 稽核套餐二 */
	char    asAuditType2[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* 稽核套餐三 */
	char    asAuditType3[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* 账单类型：A为帐务优惠，T为清单级账目，M为租费类账目 */
	char    asAcctType[ACCT_ITEM_ALL_BUFLEN_IN][2];
		/* 账目ID */
	int     aiAcctID[ACCT_ITEM_ALL_BUFLEN_IN];
	int     aiDefaultAcctID[ACCT_ITEM_ALL_BUFLEN_IN];

};

/*单个结构申明*/
struct AcctItemStruct
{
	struct AcctItemStruct *pNext;
		
	char    sAcctItemID[13];		/* 帐目流水 */
	char    sAccNbr[21];		/* 接入号码号 */
	int     iAcctItemTypeID;		/* 帐目类别 */
	int     iCharge;		/* 费用 */
	char    sAreaCode[10];		/* 归属地市 */
	char    sState[2];		/* 账目状态,'0'基本账目,'1'优惠账目,1时，charge为负*/
	int     iBillingCycleID;		/* 帐务周期 */
	char    sAcctItemDate[15];		/* 帐目归属日期 */
	int	iAuditItemTypeID;			/* 稽核账目ID */
	char	sAcctType[2];		/* 账目类别 */
	int	iAcctID;		/* 账目ID */
	int	iDefaultAcctID;		/* 账目ID */
	
	char    sAuditState[2];
	char    sAuditDetailState[6];
	char    sAuditDate[15];
	int     iAuditDiffFee;
	char    sAuditInfo[161];
	char    sOriAcctItemID[16];
	char    sAuditBillingTypeID[21];
	char    sAuditAreaCode[6];
	int     iAuditTariffId1;
	int     iAuditTariffId2;
	int     iAuditTariffId3;
	int     iAuditFee1;
	int     iAuditFee2;
	int     iAuditFee3;
	int     iAuditOriFee1;
	int     iAuditOriFee2;
	int     iAuditOriFee3;
	char    sAuditType1[21];
	char    sAuditType2[21];
	char    sAuditType3[21];

	
	struct AcctItemStruct *pLoadNext;
};

/*批量数据动态从ACCT_ITEM中用结构缓冲方式取数据*/
int EGetAcctItemToStruct(struct AcctItemStruct *p,
	struct AcctItemStructIn *pSource);
/*批量数据动态从ACCT_ITEM中用结构缓冲方式取数据*/
int EGetAcctItemAllFieldToStruct(struct AcctItemStruct *p,
	struct AcctItemAllFieldStructIn *pSource);
/*批量数据结构缓冲写入ACCT_ITEM*/
int EInsertStructToAcctItem(struct AcctItemStruct *p,
	int iInsertFlag,struct AcctItemStructOut *pTarget);

/* 输入结构缓冲申明*/
struct AuditParamStructIn{

#ifndef AUDIT_PARAM_BUFLEN_IN
#define AUDIT_PARAM_BUFLEN_IN		300
#endif

	struct AuditParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 业务类型 */
	char    asServiceType[AUDIT_PARAM_BUFLEN_IN][5];
		/* 'D'　每日稽核,'P' 预出账稽核,'A' 账后稽核 */
	char    asAuditType[AUDIT_PARAM_BUFLEN_IN][2];
	int     aiSeq[AUDIT_PARAM_BUFLEN_IN];
		/* 表名中的 @MM@表示月份,@DD@表示日期,@YYYY@、@YY@表示年份 */
	char    asAuditTableName[AUDIT_PARAM_BUFLEN_IN][41];
		/* 'A'稽核账单表,'T'稽核话单表 */
	char    asTableType[AUDIT_PARAM_BUFLEN_IN][2];
		/* 分离模板标识 */
	int     aiTemplateRuleID[AUDIT_PARAM_BUFLEN_IN];
		/* 无分区，则这个字段为空 */
	char    asPartSplitType[AUDIT_PARAM_BUFLEN_IN][2];
		/* 表模板类型 */
	int     aiTemplateID[AUDIT_PARAM_BUFLEN_IN];
		/* 话单格式类型 */
	int     aiFormatID[AUDIT_PARAM_BUFLEN_IN];
		/* 状态：0表示正常状态，1表示注销状态*/
	char	asState[AUDIT_PARAM_BUFLEN_IN][2];
		/* 相关性分析的分离模板 */
	int	aiCrRuleID[AUDIT_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct AuditParamStruct{

	struct AuditParamStruct *pNext;
	char    sServiceType[5];	/* 业务类型 */
	char    sAuditType[2];		/* 'D'　每日稽核,'P' 预出账稽核,'A' 账后稽核 */
	int	iSeq;
	char    sAuditTableName[41];	/* 表名中的 @MM@表示月份,@DD@表示日期,@YYYY@、@YY@表示年份 */
	char    sTableType[2];		/* 'A'稽核账单表,'T'稽核话单表 */
	int     iTemplateRuleID;	/* 分离模板标识 */
	char    sPartSplitType[2];	/* 无分区，则这个字段为空 */
	int     iTemplateID;		/* 表模板类型 */
	int     iFormatID;		/* 话单格式类型 */
	char	sState[2];		/* 状态：0表示正常状态，1表示注销状态*/
	int	iCrRuleID;		/* 相关性分析的分离模板 */
	struct AuditParamStruct *pLoadNext;
};

/*批量数据动态从AUDIT_PARAM中用结构缓冲方式取数据*/
int EGetAuditParamToStruct(struct AuditParamStruct *p,
	struct AuditParamStructIn *pSource);
/**对表AUDIT_PARAM的链表释放函数**/
void DestroyAuditParam(struct AuditParamStruct *ptHead);
int InitAuditParam(struct AuditParamStruct **pptHead,char sAuditType[]);

/* 输入结构缓冲申明*/
struct AuditItemTypeStructIn{

#ifndef AUDIT_ITEM_TYPE_BUFLEN_IN
#define AUDIT_ITEM_TYPE_BUFLEN_IN		300
#endif

	struct AuditItemTypeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 稽核账目ID */
	int     aiAuditItemTypeID[AUDIT_ITEM_TYPE_BUFLEN_IN];
		/* 账目名称 */
	char    asName[AUDIT_ITEM_TYPE_BUFLEN_IN][129];
};


/*单个结构申明*/
struct AuditItemTypeStruct{

	struct AuditItemTypeStruct *pNext;
	int     iAuditItemTypeID;		/* 稽核账目ID */
	char    sName[129];		/* 账目名称 */
	struct AuditItemTypeStruct *pLoadNext;
};
/*批量数据动态从AUDIT_ITEM_TYPE中用结构缓冲方式取数据*/
int EGetAuditItemTypeToStruct(struct AuditItemTypeStruct *p,
	struct AuditItemTypeStructIn *pSource);
/**对表AUDIT_ITEM_TYPE的链表释放函数**/
void DestroyAuditItemType(struct AuditItemTypeStruct *ptHead);
int InitAuditItemType(struct AuditItemTypeStruct **pptHead);

/* 输入结构缓冲申明*/
struct AuditItemRelationStructIn{

#ifndef AUDIT_ITEM_RELATION_BUFLEN_IN
#define AUDIT_ITEM_RELATION_BUFLEN_IN		300
#endif

	struct AuditItemRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 基准账目ID */
	int     aiAcctItemTypeID[AUDIT_ITEM_RELATION_BUFLEN_IN];
		/* 稽核账目关系 */
	int     aiAuditItemTypeID[AUDIT_ITEM_RELATION_BUFLEN_IN];
};


/*单个结构申明*/
struct AuditItemRelationStruct{

	struct AuditItemRelationStruct *pNext;
	int     iAcctItemTypeID;		/* 基准账目ID */
	int     iAuditItemTypeID;		/* 稽核账目关系 */
	struct AuditItemRelationStruct *pLoadNext;
};

/*批量数据动态从AUDIT_ITEM_RELATION中用结构缓冲方式取数据*/
int EGetAuditItemRelationToStruct(struct AuditItemRelationStruct *p,
	struct AuditItemRelationStructIn *pSource);
/**对表AUDIT_ITEM_RELATION的链表释放函数**/
void DestroyAuditItemRelation(struct AuditItemRelationStruct *ptHead);
int InitAuditItemRelation(struct AuditItemRelationStruct **pptHead);

/* 输入结构缓冲申明*/
struct TemplateMsisdnParamStructIn{

#ifndef TEMPLATE_MSISDN_PARAM_BUFLEN_IN
#define TEMPLATE_MSISDN_PARAM_BUFLEN_IN		300
#endif

	struct TemplateMsisdnParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 计费号码 */
	char    asMsisdn[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][21];
		/* 参数代码 */
	char    asParamCode[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][21];
		/* 参数值 */
	char    asParamValue[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][21];
		/* 计费月份 */
	char    asBillingMonth[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][7];
};


/*单个结构申明*/
struct TemplateMsisdnParamStruct{

	struct TemplateMsisdnParamStruct *pNext;
	char    sMsisdn[21];		/* 计费号码 */
	char    sParamCode[21];		/* 参数代码 */
	char    sParamValue[21];		/* 参数值 */
	char    sBillingMonth[7];		/* 计费月份 */
	struct TemplateMsisdnParamStruct *pLoadNext;
};

/*批量数据动态从TEMPLATE_MSISDN_PARAM中用结构缓冲方式取数据*/
int EGetTemplateMsisdnParamToStruct(struct TemplateMsisdnParamStruct *p,
	struct TemplateMsisdnParamStructIn *pSource);
/**对表TEMPLATE_MSISDN_PARAM的链表释放函数**/
void DestroyTemplateMsisdnParam(struct TemplateMsisdnParamStruct *ptHead);
/* 输入结构缓冲申明*/
struct ParamCodeDescStructIn{

#ifndef PARAM_CODE_DESC_BUFLEN_IN
#define PARAM_CODE_DESC_BUFLEN_IN		300
#endif

	struct ParamCodeDescStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 参数代码 */
	char    asParamCode[PARAM_CODE_DESC_BUFLEN_IN][21];
		/* 归属套餐 */
	char    asBillingTypeID[PARAM_CODE_DESC_BUFLEN_IN][21];
		/* 描述 */
	char    asRemark[PARAM_CODE_DESC_BUFLEN_IN][61];
};


/*单个结构申明*/
struct ParamCodeDescStruct{

	struct ParamCodeDescStruct *pNext;
	char    sParamCode[21];		/* 参数代码 */
	char    sBillingTypeID[21];		/* 归属套餐 */
	char    sRemark[61];		/* 描述 */
	struct ParamCodeDescStruct *pLoadNext;
};
/*批量数据动态从PARAM_CODE_DESC中用结构缓冲方式取数据*/
int EGetParamCodeDescToStruct(struct ParamCodeDescStruct *p,
	struct ParamCodeDescStructIn *pSource);
/**对表PARAM_CODE_DESC的链表释放函数**/
void DestroyParamCodeDesc(struct ParamCodeDescStruct *ptHead);

/*获取ACCT_ITEM_ID序列号*/
int GetAcctItemIDSeq();

/*输出结构缓冲申明*/
struct BasMsisdnStructOut{

#ifndef BAS_MSISDN_BUFLEN_OUT
#define BAS_MSISDN_BUFLEN_OUT		300
#endif

	struct BasMsisdnStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asMsisdn[BAS_MSISDN_BUFLEN_OUT][21];
	int     aiCnt[BAS_MSISDN_BUFLEN_OUT];
	int     aiSubscriptionID[BAS_MSISDN_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct BasMsisdnStructIn{

#ifndef BAS_MSISDN_BUFLEN_IN
#define BAS_MSISDN_BUFLEN_IN		300
#endif

	struct BasMsisdnStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asMsisdn[BAS_MSISDN_BUFLEN_IN][21];
	int     aiCnt[BAS_MSISDN_BUFLEN_IN];
	int     aiSubscriptionID[BAS_MSISDN_BUFLEN_IN];
};


/*单个结构申明*/
struct BasMsisdnStruct{

	struct BasMsisdnStruct *pNext;
	char    sMsisdn[21];
	int     iCnt;
	int     iSubscriptionID;
	struct BasMsisdnStruct *pLoadNext;
};
/*批量数据动态从BAS_MSISDN中用结构缓冲方式取数据*/
int EGetBasMsisdnToStruct(struct BasMsisdnStruct *p,
	struct BasMsisdnStructIn *pSource);
/**对表BAS_MSISDN的链表释放函数**/
void DestroyBasMsisdn(struct BasMsisdnStruct *ptHead);
int InitBasMsisdn(char sTableName[],struct BasMsisdnStruct **pptHead);


/* 输入结构缓冲申明*/
struct PromiseExprParamStructIn{

#ifndef PROMISE_EXPR_PARAM_BUFLEN_IN
#define PROMISE_EXPR_PARAM_BUFLEN_IN		300
#endif

	struct PromiseExprParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[PROMISE_EXPR_PARAM_BUFLEN_IN][21];
		/* 公式ID */
	int     aiExprID[PROMISE_EXPR_PARAM_BUFLEN_IN];
		/* 参数个数 */
	int     aiParamCnt[PROMISE_EXPR_PARAM_BUFLEN_IN];
		/* 公式参数 */
	char    asParamValue[PROMISE_EXPR_PARAM_BUFLEN_IN][201];
		/* 批价方法：'E'：区分到套餐级的资费公式参数，'F'：区分到号码级的资费公式参数 */
	char    asRateMethod[PROMISE_EXPR_PARAM_BUFLEN_IN][2];
	int     aiParamID[PROMISE_EXPR_PARAM_BUFLEN_IN];
	char    asFParamFmt[PROMISE_EXPR_PARAM_BUFLEN_IN][201];
};


/*单个结构申明*/
struct PromiseExprParamStruct{

	struct PromiseExprParamStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iExprID;		/* 公式ID */
	int     iParamCnt;		/* 参数个数 */
	char    sParamValue[201];		/* 公式参数 */
	char    sRateMethod[2];		
/* 批价方法：'E'：区分到套餐级的资费公式参数，'F'：区分到号码级的资费公式参数 */
	int     iParamID;
	char    sFParamFmt[201];
	struct PromiseExprParamStruct *pLoadNext;
};

/*批量数据动态从PROMISE_EXPR_PARAM中用结构缓冲方式取数据*/
int EGetPromiseExprParamToStruct(struct PromiseExprParamStruct *p,
	struct PromiseExprParamStructIn *pSource);
/**对表PROMISE_EXPR_PARAM的链表释放函数**/
void DestroyPromiseExprParam(struct PromiseExprParamStruct *ptHead);
int InitPromiseExprParam(struct PromiseExprParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct PromiseExprMsisdnParamStructIn{

#ifndef PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN
#define PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN		300
#endif

	struct PromiseExprMsisdnParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][21];
		/* 参数个数 */
	int     aiParamCnt[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN];
		/* 公式参数 */
	char    asParamValue[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][201];
		/* 计费号码 */
	char    asMsisdn[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][21];
		/* 参数生效时间 */
	char	asActiveDate[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][15];
		/* 参数失效时间 */	
	char	asInactiveDate[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][15];
};


/*单个结构申明*/
struct PromiseExprMsisdnParamStruct{

	struct PromiseExprMsisdnParamStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iParamCnt;		/* 参数个数 */
	char    sParamValue[201];		/* 公式参数 */
	char    sMsisdn[21];		/* 计费号码 */
	char	sActiveDate[15];	/* 参数生效时间 */
	char	sInactiveDate[15];	/* 参数失效时间 */
	struct PromiseExprMsisdnParamStruct *pLoadNext;
};


/*批量数据动态从PROMISE_EXPR_MSISDN_PARAM中用结构缓冲方式取数据*/
int EGetPromiseExprMsisdnParamToStruct(struct PromiseExprMsisdnParamStruct *p,
	struct PromiseExprMsisdnParamStructIn *pSource);
/**对表PROMISE_EXPR_MSISDN_PARAM的链表释放函数**/
void DestroyPromiseExprMsisdnParam(struct PromiseExprMsisdnParamStruct *ptHead);
int InitPromiseExprMsisdnParam(struct PromiseExprMsisdnParamStruct **pptHead);

/* 输入结构缓冲申明*/
struct PromiseExprStructIn{

#ifndef PROMISE_EXPR_BUFLEN_IN
#define PROMISE_EXPR_BUFLEN_IN		300
#endif

	struct PromiseExprStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 公式ID */
	int     aiExprID[PROMISE_EXPR_BUFLEN_IN];
		/* 参数串名，为空则为不带参数 */
	char    asParamNameStr[PROMISE_EXPR_BUFLEN_IN][201];
		/* 业务描述 */
	char    asRemark[PROMISE_EXPR_BUFLEN_IN][401];
	char	asSetDetail[PROMISE_EXPR_BUFLEN_IN][3001];
		/* 公式 */
	char    asExpr[PROMISE_EXPR_BUFLEN_IN][4001];
		/* 公式类型 */
	char 	asPromiseType[PROMISE_EXPR_BUFLEN_IN][2];
		/* 名称 */
	char	asName[PROMISE_EXPR_BUFLEN_IN][41];
};


/*单个结构申明*/
struct PromiseExprStruct{

	struct PromiseExprStruct *pNext;
	int     iExprID;		/* 公式ID */
	char    sParamNameStr[201];		/* 参数串名，为空则为不带参数 */
	char    sRemark[401];		/* 业务描述 */
	char	sSetDetail[3001];
	char    sExpr[4001];		/* 公式 */
	char 	sPromiseType[2];	/* 公式类型 */
	char	sName[41];		/* 名称 */
	struct PromiseExprStruct *pLoadNext;
};
/*批量数据动态从PROMISE_EXPR中用结构缓冲方式取数据*/
int EGetPromiseExprToStruct(struct PromiseExprStruct *p,
	struct PromiseExprStructIn *pSource);
/**对表PROMISE_EXPR的链表释放函数**/
void DestroyPromiseExpr(struct PromiseExprStruct *ptHead);
int InitPromiseExpr(struct PromiseExprStruct **pptHead);

/* 输入结构缓冲申明*/
struct MonthFeeTariffStructIn{

#ifndef MONTH_FEE_TARIFF_BUFLEN_IN
#define MONTH_FEE_TARIFF_BUFLEN_IN		300
#endif

	struct MonthFeeTariffStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[MONTH_FEE_TARIFF_BUFLEN_IN][21];
		/* 归属区 */
	char	asAreaCode[MONTH_FEE_TARIFF_BUFLEN_IN][10];	
		/* 类型：‘Z'，’T'，‘Y' */
	char    asType[MONTH_FEE_TARIFF_BUFLEN_IN][2];
		/* 单位：’Y'年，‘S' 季，‘M'月 */
	char    asUnit[MONTH_FEE_TARIFF_BUFLEN_IN][2];
		/* 半月入网标识：’0'为全月，'1'为半月 */
	char    asHalfMonthFlag[MONTH_FEE_TARIFF_BUFLEN_IN][2];
		/* 费率 */
	double  adRate[MONTH_FEE_TARIFF_BUFLEN_IN];
};


/*单个结构申明*/
struct MonthFeeTariffStruct{

	struct MonthFeeTariffStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	char	sAreaCode[10];		/* 归属区 */
	char    sType[2];		/* 类型：‘Z'，’T'，‘Y' */
	char    sUnit[2];		/* 单位：’Y'年，‘S' 季，‘M'月 */
	char    sHalfMonthFlag[2];		/* 半月入网标识：’0'为全月，'1'为半月 */
	double  dRate;		/* 费率 */
	
	int	iRateUnit;
	struct MonthFeeTariffStruct *pLoadNext;
};

/*批量数据动态从MONTH_FEE_TARIFF中用结构缓冲方式取数据*/
int EGetMonthFeeTariffToStruct(struct MonthFeeTariffStruct *p,
	struct MonthFeeTariffStructIn *pSource);
/**对表MONTH_FEE_TARIFF的链表释放函数**/
void DestroyMonthFeeTariff(struct MonthFeeTariffStruct *ptHead);
int InitMonthFeeTariff(struct MonthFeeTariffStruct **pptHead);

/* 输入结构缓冲申明*/
struct PromiseExprStateReasonStructIn{

#ifndef PROMISE_EXPR_STATE_REASON_BUFLEN_IN
#define PROMISE_EXPR_STATE_REASON_BUFLEN_IN		300
#endif

	struct PromiseExprStateReasonStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 公式ID */
	int     aiExprID[PROMISE_EXPR_STATE_REASON_BUFLEN_IN];
		/* 运行状态编号 */
	int     aiStateSeq[PROMISE_EXPR_STATE_REASON_BUFLEN_IN];
		/* 运行状态原因 */
	char    asStateSeqReason[PROMISE_EXPR_STATE_REASON_BUFLEN_IN][401];
		/* 名称 */
	char	asName[PROMISE_EXPR_STATE_REASON_BUFLEN_IN][41];
};

/*单个结构申明*/
struct PromiseExprStateReasonStruct{

	struct PromiseExprStateReasonStruct *pNext;
	int     iExprID;		/* 公式ID */
	int     iStateSeq;		/* 运行状态编号 */
	char    sStateSeqReason[401];		/* 运行状态原因 */
	char	sName[41];		/* 名称 */
	struct PromiseExprStateReasonStruct *pLoadNext;
};

/*批量数据动态从PROMISE_EXPR_STATE_REASON中用结构缓冲方式取数据*/
int EGetPromiseExprStateReasonToStruct(struct PromiseExprStateReasonStruct *p,
	struct PromiseExprStateReasonStructIn *pSource);
/**对表PROMISE_EXPR_STATE_REASON的链表释放函数**/
void DestroyPromiseExprStateReason(struct PromiseExprStateReasonStruct *ptHead);
int InitPromiseExprStateReason(struct PromiseExprStateReasonStruct **pptHead);

/*输出结构缓冲申明*/
struct AuditNumResStructOut{

#ifndef TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT
#define TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT		300
#endif

	struct AuditNumResStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户归属地 */
	char    asAreaCode[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][10];
		/* 当TABLE_TYPE='A'时，该字段为账号下的任意一个号码 */
	char    asAccNbr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][21];
		/* 记录类型 */
	char    asRecordType[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][2];
		/* 审核日期 */
	char    asAuditDate[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][15];
		/* 'P','F' */
	char    asAuditState[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][2];
		/* 规则串 */
	char    asAuditRuleStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][201];
	char    asAuditInfo[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][2001];
	char	asAuditAllTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][201];
	char	asAuditDiffTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][201];

};

/* 输入结构缓冲申明*/
struct AuditNumResStructIn{

#ifndef TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN
#define TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN		300
#endif

	struct AuditNumResStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户归属地 */
	char    asAreaCode[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][10];
		/* 当TABLE_TYPE='A'时，该字段为账号下的任意一个号码 */
	char    asAccNbr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][21];
		/* 记录类型 */
	char    asRecordType[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][2];
		/* 审核日期 */
	char    asAuditDate[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][15];
		/* 'P','F' */
	char    asAuditState[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][2];
		/* 规则串 */
	char    asAuditRuleStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][201];
	char    asAuditInfo[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][2001];
	char	asAuditAllTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][201];
	char	asAuditDiffTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][201];

};


/*单个结构申明*/
struct AuditNumResStruct{

	struct AuditNumResStruct *pNext;
	char    sAreaCode[10];		/* 用户归属地 */
	char    sAccNbr[21];		/* 当TABLE_TYPE='A'时，该字段为账号下的任意一个号码 */
	char    sRecordType[2];		/* 记录类型 */
	char    sAuditDate[15];		/* 审核日期 */
	char    sAuditState[2];		/* 'P','F' */
	char    sAuditRuleStr[201];		/* 规则串 */
	char    sAuditInfo[2001];
	char	sAuditAllTypeStr[201];
	char	sAuditDiffTypeStr[201];
	
	char	sRowID[20];
	char	sSourceID[41];

	struct AuditNumResStruct *pLoadNext;
};
/*批量数据动态从TEMPLATE_AUDIT_NUM_RES中用结构缓冲方式取数据*/
int EGetAuditNumResToStruct(struct AuditNumResStruct *p,
	struct AuditNumResStructIn *pSource);
/**对表TEMPLATE_AUDIT_NUM_RES的链表释放函数**/
void DestroyAuditNumRes(struct AuditNumResStruct *ptHead);
int InitAuditNumRes(struct AuditNumResStruct **pptHead);
/*批量数据结构缓冲写入TEMPLATE_AUDIT_NUM_RES*/
int EInsertStructToAuditNumRes(struct AuditNumResStruct *p,
	int iInsertFlag,struct AuditNumResStructOut *pTarget);

/*输出结构缓冲申明*/
struct PromiseTariffCommentsStructOut{

#ifndef PROMISE_TARIFF_COMMENTS_BUFLEN_OUT
#define PROMISE_TARIFF_COMMENTS_BUFLEN_OUT		300
#endif

	struct PromiseTariffCommentsStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asBillingTypeID[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][21];
	int     aiPromiseElementID[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT];
		/* 资费集合串 */
	char    asTariffIDStr[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][201];
	char    asComments[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][4001];
		/* 状态 */
	char    asState[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][4];
		/* 生成时间 */
	char    asCreatedDate[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][15];
		/* 变更时间 */
	char    asStateDate[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][15];
};


/* 输入结构缓冲申明*/
struct PromiseTariffCommentsStructIn{

#ifndef PROMISE_TARIFF_COMMENTS_BUFLEN_IN
#define PROMISE_TARIFF_COMMENTS_BUFLEN_IN		300
#endif

	struct PromiseTariffCommentsStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asBillingTypeID[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][21];
	int     aiPromiseElementID[PROMISE_TARIFF_COMMENTS_BUFLEN_IN];
		/* 资费集合串 */
	char    asTariffIDStr[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][201];
	char    asComments[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][4001];
		/* 状态 */
	char    asState[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][4];
		/* 生成时间 */
	char    asCreatedDate[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][15];
		/* 变更时间 */
	char    asStateDate[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][15];
};


/*单个结构申明*/
struct PromiseTariffCommentsStruct{

	struct PromiseTariffCommentsStruct *pNext;
	char    sBillingTypeID[21];
	int     iPromiseElementID;
	char    sTariffIDStr[201];		/* 资费集合串 */
	char    sComments[4001];
	char    sState[4];		/* 状态 */
	char    sCreatedDate[15];		/* 生成时间 */
	char    sStateDate[15];		/* 变更时间 */
	struct PromiseTariffCommentsStruct *pLoadNext;
};
/*批量数据动态从PROMISE_TARIFF_COMMENTS中用结构缓冲方式取数据*/
int EGetPromiseTariffCommentsToStruct(struct PromiseTariffCommentsStruct *p,
	struct PromiseTariffCommentsStructIn *pSource);
/**对表PROMISE_TARIFF_COMMENTS的链表释放函数**/
void DestroyPromiseTariffComments(struct PromiseTariffCommentsStruct *ptHead);
/*批量数据结构缓冲写入PROMISE_TARIFF_COMMENTS*/
int EInsertStructToPromiseTariffComments(struct PromiseTariffCommentsStruct *p,
	int iInsertFlag,struct PromiseTariffCommentsStructOut *pTarget);

/*输出结构缓冲申明*/
struct AcctItemTypeRelationStructOut{

#ifndef ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT
#define ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT		300
#endif

	struct AcctItemTypeRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 账目类型ID */
	int     aiAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
		/* 帐务系统科目ID */
	int     aiSubjectID[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
	int     aiOriAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
		/* 类型 ‘T’ 详单类帐目‘M’ 租类帐目‘I’增值代收类帐目‘A’优惠类帐目‘O’优惠后续处理的帐目 */
	char    asCatg[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct AcctItemTypeRelationStructIn{

#ifndef ACCT_ITEM_TYPE_RELATION_BUFLEN_IN
#define ACCT_ITEM_TYPE_RELATION_BUFLEN_IN		300
#endif

	struct AcctItemTypeRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 账目类型ID */
	int     aiAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
		/* 帐务系统科目ID */
	int     aiSubjectID[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
	int     aiOriAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
		/* 类型 ‘T’ 详单类帐目‘M’ 租类帐目‘I’增值代收类帐目‘A’优惠类帐目‘O’优惠后续处理的帐目 */
	char    asCatg[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN][2];
};


/*单个结构申明*/
struct AcctItemTypeRelationStruct{

	struct AcctItemTypeRelationStruct *pNext;
	int     iAcctItemTypeID;		/* 账目类型ID */
	int     iSubjectID;		/* 帐务系统科目ID */
	int     iOriAcctItemTypeID;
	char    sCatg[2];		/* 类型 ‘T’ 详单类帐目‘M’ 租类帐目‘I’增值代收类帐目‘A’优惠类帐目‘O’优惠后续处理的帐目 */
	struct AcctItemTypeRelationStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAcctItemTypeRelationStruct{

	char    sAcctItemTypeID[8];		/* 账目类型ID */
	char    sSubjectID[8];		/* 帐务系统科目ID */
	char    sOriAcctItemTypeID[8];
	char    sCatg[1];		/* 类型 ‘T’ 详单类帐目‘M’ 租类帐目‘I’增值代收类帐目‘A’优惠类帐目‘O’优惠后续处理的帐目 */
};


/*批量数据动态从ACCT_ITEM_TYPE_RELATION中用结构缓冲方式取数据*/
int EGetAcctItemTypeRelationToStruct(struct AcctItemTypeRelationStruct *p,
	struct AcctItemTypeRelationStructIn *pSource);
/**对表ACCT_ITEM_TYPE_RELATION的链表释放函数**/
void DestroyAcctItemTypeRelation(struct AcctItemTypeRelationStruct *ptHead);
int InitAcctItemTypeRelation(struct AcctItemTypeRelationStruct **pptHead);
/*输出结构缓冲申明*/
struct AccSubjectItemStructOut{

#ifndef ACC_SUBJECT_ITEM_BUFLEN_OUT
#define ACC_SUBJECT_ITEM_BUFLEN_OUT		300
#endif

	struct AccSubjectItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asAccNbr[ACC_SUBJECT_ITEM_BUFLEN_OUT][21];
		/* 用户订购标识 */
	int     aiSubscriptionID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* 账户ID */
	int     aiAccountID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* 账户ID */
	int     aiDefaultAccountID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* 科目ID */
	int     aiSubjectID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* 科目费用 */
	int    aiTotalFee[ACC_SUBJECT_ITEM_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct AccSubjectItemStructIn{

#ifndef ACC_SUBJECT_ITEM_BUFLEN_IN
#define ACC_SUBJECT_ITEM_BUFLEN_IN		300
#endif

	struct AccSubjectItemStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asAccNbr[ACC_SUBJECT_ITEM_BUFLEN_IN][21];
		/* 用户订购标识 */
	int     aiSubscriptionID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* 账户ID */
	int     aiAccountID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* 账户ID */
	int     aiDefaultAccountID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* 科目ID */
	int     aiSubjectID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* 科目费用 */
	int    aiTotalFee[ACC_SUBJECT_ITEM_BUFLEN_IN];
};


/*单个结构申明*/
struct AccSubjectItemStruct{

	struct AccSubjectItemStruct *pNext;
	char    sAccNbr[21];		/* 用户号码 */
	int     iSubscriptionID;		/* 用户订购标识 */
	int     iAccountID;		/* 账户ID */
	int     iDefaultAccountID;		/* 账户ID */
	int     iSubjectID;		/* 科目ID */
	int    iTotalFee;		/* 科目费用 */
	
/*扩展使用*/
	int iAcctItemTypeID;		/*该科目所对应的账目*/
	struct AccSubjectItemStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAccSubjectItemStruct{

	char    sAccNbr[20];		/* 用户号码 */
	char    sSubscriptionID[9];		/* 用户订购标识 */
	char    sAccountID[9];		/* 账户ID */
	char    sDefaultAccountID[9];		/* 账户ID */
	char    sSubjectID[8];		/* 科目ID */
	char    sTotalFee[15];		/* 科目费用 */
};


/*批量数据动态从ACC_SUBJECT_ITEM中用结构缓冲方式取数据*/
int EGetAccSubjectItemToStruct(struct AccSubjectItemStruct *p,
	struct AccSubjectItemStructIn *pSource);
/**对表ACC_SUBJECT_ITEM的链表释放函数**/
void DestroyAccSubjectItem(struct AccSubjectItemStruct *ptHead);
int InitAccSubjectItem(struct AccSubjectItemStruct **pptHead);

/*输出结构缓冲申明*/
struct AccSubjectStructOut{

#ifndef ACC_SUBJECT_BUFLEN_OUT
#define ACC_SUBJECT_BUFLEN_OUT		300
#endif

	struct AccSubjectStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiSubjectID[ACC_SUBJECT_BUFLEN_OUT];
	char    asSubjectName[ACC_SUBJECT_BUFLEN_OUT][65];
	char    asSubjectDesc[ACC_SUBJECT_BUFLEN_OUT][256];
	int     aiDisplayUnit[ACC_SUBJECT_BUFLEN_OUT];
	char    asUnitName[ACC_SUBJECT_BUFLEN_OUT][11];
	int     aiSubjectType[ACC_SUBJECT_BUFLEN_OUT];
	int     aiSubjectAttr[ACC_SUBJECT_BUFLEN_OUT];
	int     aiSubjectMode[ACC_SUBJECT_BUFLEN_OUT];
	char    asOperatorID[ACC_SUBJECT_BUFLEN_OUT][13];
	char    asOfficeID[ACC_SUBJECT_BUFLEN_OUT][11];
	char    asCreateTime[ACC_SUBJECT_BUFLEN_OUT][15];
};


/* 输入结构缓冲申明*/
struct AccSubjectStructIn{

#ifndef ACC_SUBJECT_BUFLEN_IN
#define ACC_SUBJECT_BUFLEN_IN		300
#endif

	struct AccSubjectStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiSubjectID[ACC_SUBJECT_BUFLEN_IN];
	char    asSubjectName[ACC_SUBJECT_BUFLEN_IN][65];
	char    asSubjectDesc[ACC_SUBJECT_BUFLEN_IN][256];
	int     aiDisplayUnit[ACC_SUBJECT_BUFLEN_IN];
	char    asUnitName[ACC_SUBJECT_BUFLEN_IN][11];
	int     aiSubjectType[ACC_SUBJECT_BUFLEN_IN];
	int     aiSubjectAttr[ACC_SUBJECT_BUFLEN_IN];
	int     aiSubjectMode[ACC_SUBJECT_BUFLEN_IN];
	char    asOperatorID[ACC_SUBJECT_BUFLEN_IN][13];
	char    asOfficeID[ACC_SUBJECT_BUFLEN_IN][11];
	char    asCreateTime[ACC_SUBJECT_BUFLEN_IN][15];
};


/*单个结构申明*/
struct AccSubjectStruct{

	struct AccSubjectStruct *pNext;
	int     iSubjectID;
	char    sSubjectName[65];
	char    sSubjectDesc[256];
	int     iDisplayUnit;
	char    sUnitName[11];
	int     iSubjectType;
	int     iSubjectAttr;
	int     iSubjectMode;
	char    sOperatorID[13];
	char    sOfficeID[11];
	char    sCreateTime[15];
	struct AccSubjectStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FAccSubjectStruct{

	char    sSubjectID[8];
	char    sSubjectName[64];
	char    sSubjectDesc[255];
	char    sDisplayUnit[8];
	char    sUnitName[10];
	char    sSubjectType[2];
	char    sSubjectAttr[2];
	char    sSubjectMode[2];
	char    sOperatorID[12];
	char    sOfficeID[10];
	char    sCreateTime[14];
};


/*批量数据动态从ACC_SUBJECT中用结构缓冲方式取数据*/
int EGetAccSubjectToStruct(struct AccSubjectStruct *p,
	struct AccSubjectStructIn *pSource);
/**对表ACC_SUBJECT的链表释放函数**/
void DestroyAccSubject(struct AccSubjectStruct *ptHead);
int InitAccSubject(struct AccSubjectStruct **pptHead);


/* 输入结构缓冲申明*/
struct UserAuditTaskStructIn{

#ifndef USER_AUDIT_TASK_BUFLEN_IN
#define USER_AUDIT_TASK_BUFLEN_IN		300
#endif

	struct UserAuditTaskStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asTaskID[USER_AUDIT_TASK_BUFLEN_IN][5];
		/* 任务名称 */
	char    asTaskName[USER_AUDIT_TASK_BUFLEN_IN][41];
		/* 工号 */
	int     aiStaffID[USER_AUDIT_TASK_BUFLEN_IN];
		/* 月份 */
	char    asMonth[USER_AUDIT_TASK_BUFLEN_IN][7];
		/* 稽核类型 */
	char    asAuditType[USER_AUDIT_TASK_BUFLEN_IN][2];
		/* 序列 */
	int     aiSeq[USER_AUDIT_TASK_BUFLEN_IN];
		/* 账单稽核状态:  N未稽核((稽核脚本未运行或未运行成功,无法提取报表)   S已稽核(稽核脚本已跑,可以提取报表) */
	char    asTaskState[USER_AUDIT_TASK_BUFLEN_IN][2];
		/* 地市 */
	char    asAreaCode[USER_AUDIT_TASK_BUFLEN_IN][6];
		/* 运行结果日志 */
	char    asRunLog[USER_AUDIT_TASK_BUFLEN_IN][4001];
		/* 清单稽核状态    (N未执行清单稽核,S已稽核.) */
	char    asTaskState2[USER_AUDIT_TASK_BUFLEN_IN][2];
};


/*单个结构申明*/
struct UserAuditTaskStruct{

	struct UserAuditTaskStruct *pNext;
	char    sTaskID[5];
	char    sTaskName[41];		/* 任务名称 */
	int     iStaffID;		/* 工号 */
	char    sMonth[7];		/* 月份 */
	char    sAuditType[2];		/* 稽核类型 */
	int     iSeq;		/* 序列 */
	char    sTaskState[2];		/* 账单稽核状态:  N未稽核((稽核脚本未运行或未运行成功,无法提取报表)   S已稽核(稽核脚本已跑,可以提取报表) */
	char    sAreaCode[6];		/* 地市 */
	char    sRunLog[4001];		/* 运行结果日志 */
	char    sTaskState2[2];		/* 清单稽核状态    (N未执行清单稽核,S已稽核.) */
	struct UserAuditTaskStruct *pLoadNext;
};
/*批量数据动态从USER_AUDIT_TASK中用结构缓冲方式取数据*/
int EGetUserAuditTaskToStruct(struct UserAuditTaskStruct *p,
	struct UserAuditTaskStructIn *pSource);
/**对表USER_AUDIT_TASK的链表释放函数**/
void DestroyUserAuditTask(struct UserAuditTaskStruct *ptHead);	

/* 输入结构缓冲申明*/
struct UserAttentionBillStructIn{

#ifndef USER_ATTENTION_BILL_BUFLEN_IN
#define USER_ATTENTION_BILL_BUFLEN_IN		300
#endif

	struct UserAttentionBillStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asTaskID[USER_ATTENTION_BILL_BUFLEN_IN][5];
		/* 套餐ID */
	char    asBillingTypeID[USER_ATTENTION_BILL_BUFLEN_IN][21];
		/* 'B'表示主产品套餐'b'表示子产品套餐 'S'表示业务品牌 */
	char    asCatg[USER_ATTENTION_BILL_BUFLEN_IN][2];
		/* M 主流业务; N 近期新业务、新规则; O 其他特别关注 */
	char    asExtraType[USER_ATTENTION_BILL_BUFLEN_IN][2];
		/* 套餐抽取用户个数类型:A 所有,      D 默认个数 */
	char    asExtraCount[USER_ATTENTION_BILL_BUFLEN_IN][2];
		/* 报表展示: A 全部展示;     T  展示典型 */
	char    asShowType[USER_ATTENTION_BILL_BUFLEN_IN][3];
		/* 稽核状态 N为不稽核，Y为稽核状态 */
	char    asAuditState[USER_ATTENTION_BILL_BUFLEN_IN][2];
};


/*单个结构申明*/
struct UserAttentionBillStruct{

	struct UserAttentionBillStruct *pNext;
	char    sTaskID[5];
	char    sBillingTypeID[21];		/* 套餐ID */
	char    sCatg[2];		/* 'B'表示主产品套餐'b'表示子产品套餐 'S'表示业务品牌 */
	char    sExtraType[2];		/* M 主流业务; N 近期新业务、新规则; O 其他特别关注 */
	char    sExtraCount[2];		/* 套餐抽取用户个数类型:A 所有,      D 默认个数 */
	char    sShowType[3];		/* 报表展示: A 全部展示;     T  展示典型 */
	char	sAuditState[2];		/* 稽核状态 N为不稽核，Y为稽核状态 */
	int	iFlag;			/* 1为处理过的套餐，0为未处理过的套餐 */
	
	struct UserAttentionBillStruct *pLoadNext;
};
/*批量数据动态从USER_ATTENTION_BILL中用结构缓冲方式取数据*/
int EGetUserAttentionBillToStruct(struct UserAttentionBillStruct *p,
	struct UserAttentionBillStructIn *pSource);
/**对表USER_ATTENTION_BILL的链表释放函数**/
void DestroyUserAttentionBill(struct UserAttentionBillStruct *ptHead);

/* 输入结构缓冲申明*/
struct UserAttentionMsisdnStructIn{

#ifndef USER_ATTENTION_MSISDN_BUFLEN_IN
#define USER_ATTENTION_MSISDN_BUFLEN_IN		300
#endif

	struct UserAttentionMsisdnStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 工号 */
	int     aiStaffID[USER_ATTENTION_MSISDN_BUFLEN_IN];
		/* 关注号码 */
	char    asMsisdn[USER_ATTENTION_MSISDN_BUFLEN_IN][21];
		/* 号码相关套餐ID */
	char    asBillingTypeID[USER_ATTENTION_MSISDN_BUFLEN_IN][21];
		/* Y:要稽核.X :不稽核 */
	char    asState[USER_ATTENTION_MSISDN_BUFLEN_IN][2];
		/* 建立时间 */
	char    asCreateDate[USER_ATTENTION_MSISDN_BUFLEN_IN][15];
		/* 状态时间(改变) */
	char    asStateDate[USER_ATTENTION_MSISDN_BUFLEN_IN][15];
		/* 号码审核状态  (  C刚生成;  F 非员工地市号码 ;  N 无资料;  P合格号码;X 号码与套餐ID无对应关系) */
	char    asCheckState[USER_ATTENTION_MSISDN_BUFLEN_IN][2];
		/* 批次ID */
	char	asTaskID[USER_ATTENTION_MSISDN_BUFLEN_IN][5];
};


/*单个结构申明*/
struct UserAttentionMsisdnStruct{

	struct UserAttentionMsisdnStruct *pNext;
	int     iStaffID;		/* 工号 */
	char    sMsisdn[21];		/* 关注号码 */
	char    sBillingTypeID[21];		/* 号码相关套餐ID */
	char    sState[2];		/* Y:要稽核.X :不稽核 */
	char    sCreateDate[15];		/* 建立时间 */
	char    sStateDate[15];		/* 状态时间(改变) */
	char    sCheckState[2];		/* 号码审核状态  (  C刚生成;  F 非员工地市号码 ;  N 无资料;  P合格号码;X 号码与套餐ID无对应关系) */
	char	sTaskID[5];		/* 批次ID */
	struct UserAttentionMsisdnStruct *pLoadNext;
};
/*批量数据动态从USER_ATTENTION_MSISDN中用结构缓冲方式取数据*/
int EGetUserAttentionMsisdnToStruct(struct UserAttentionMsisdnStruct *p,
	struct UserAttentionMsisdnStructIn *pSource);
/**对表USER_ATTENTION_MSISDN的链表释放函数**/
void DestroyUserAttentionMsisdn(struct UserAttentionMsisdnStruct *ptHead);

/* 输入结构缓冲申明*/
struct AuditTaskReportDataStructIn{

#ifndef AUDIT_TASK_REPORT_DATA_BUFLEN_IN
#define AUDIT_TASK_REPORT_DATA_BUFLEN_IN		300
#endif

	struct AuditTaskReportDataStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 任务ID */
	char    asTaskID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][5];
		/* 抽检类型 */
	char    asExtraType[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* 业务(规则)编码 */
	char    asBillingTypeID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][21];
		/* 典型号码 */
	char    asTypicalMsisdn[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][21];
		/* 账户 */
	int     aiAcctID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN];
		/* 业务说明(全) */
	char    asBillingRule[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* 'P','F' */
	char    asAuditState[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* 问题(或疑问）说明 */
	char    asProblem[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][3001];
		/* 计费方账单账户下各用户的明细 (从SEQ取, report_acct_detail_seq) */
	int     aiAcctDetailID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN];
		/* (账户级总差异) */
	char    asAcctDiffDetail[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* 用户相关规则 */
	char    asUserRule[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* 省分核查回复 */
	char    asProvReply[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2001];
		/* 地市复核结果 */
	char    asCityCheckResult[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2001];
		/* 'B'关注套餐,'M'关注用户 */
	char    asAttentionType[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* 产生问题套餐列表 */
	char    asProblemBill[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][1001];
		/* 产生问题套餐iD列表 */
	char    asProblemBillID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][201];
	char    asAcctDiffDetail2[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* Y 已分析; N或空为未分析 */
	char	asAnlyzeFlag[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* 数据生成时间 */
	char	asDataDate[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][15];
};


/*输出结构缓冲申明*/
struct AuditTaskReportDataStructOut{

#ifndef AUDIT_TASK_REPORT_DATA_BUFLEN_OUT
#define AUDIT_TASK_REPORT_DATA_BUFLEN_OUT		300
#endif

	struct AuditTaskReportDataStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 任务ID */
	char    asTaskID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][5];
		/* 抽检类型 */
	char    asExtraType[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* 业务(规则)编码 */
	char    asBillingTypeID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][21];
		/* 典型号码 */
	char    asTypicalMsisdn[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][21];
		/* 账户 */
	int     aiAcctID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT];
		/* 业务说明(全) */
	char    asBillingRule[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* 'P','F' */
	char    asAuditState[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* 问题(或疑问）说明 */
	char    asProblem[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][3001];
		/* 计费方账单账户下各用户的明细 (从SEQ取, report_acct_detail_seq) */
	int     aiAcctDetailID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT];
		/* (账户级总差异) */
	char    asAcctDiffDetail[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* 用户相关规则 */
	char    asUserRule[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* 省分核查回复 */
	char    asProvReply[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2001];
		/* 地市复核结果 */
	char    asCityCheckResult[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2001];
		/* 'B'关注套餐,'M'关注用户 */
	char    asAttentionType[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* 产生问题套餐列表 */
	char    asProblemBill[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][1001];
		/* 产生问题套餐iD列表 */
	char    asProblemBillID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][201];
	char    asAcctDiffDetail2[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* Y 已分析; N或空为未分析 */
	char	asAnlyzeFlag[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* 数据生成时间 */
	char	asDataDate[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][15];			
};
/*单个结构申明*/
struct AuditTaskReportDataStruct{

	struct AuditTaskReportDataStruct *pNext;
	char    sTaskID[5];		/* 任务ID */
	char    sExtraType[2];		/* 抽检类型 */
	char    sBillingTypeID[21];		/* 业务(规则)编码 */
	char    sTypicalMsisdn[21];		/* 典型号码 */
	int     iAcctID;		/* 账户 */
	char    sBillingRule[4001];		/* 业务说明(全) */
	char    sAuditState[2];		/* 'P','F' */
	char    sProblem[3001];		/* 问题(或疑问）说明 */
	int     iAcctDetailID;		/* 计费方账单账户下各用户的明细 (从SEQ取, report_acct_detail_seq) */
	char    sAcctDiffDetail[4001];		/* (账户级总差异) */
	char    sUserRule[4001];		/* 用户相关规则 */
	char    sProvReply[2001];		/* 省分核查回复 */
	char    sCityCheckResult[2001];		/* 地市复核结果 */
	char    sAttentionType[2];		/* 'B'关注套餐,'M'关注用户 */
	char    sProblemBill[1001];		/* 产生问题套餐列表 */
	char    sProblemBillID[201];		/* 产生问题套餐iD列表 */
	char	sAcctDiffDetail2[4001];
	char	sAnlyzeFlag[2];			/* Y 已分析; N或空为未分析 */
	char	sDataDate[15];			/* 数据生成时间 */
	struct AuditTaskReportDataStruct *pLoadNext;
};
/*批量数据动态从AUDIT_TASK_REPORT_DATA中用结构缓冲方式取数据*/
int EGetAuditTaskReportDataToStruct(struct AuditTaskReportDataStruct *p,
	struct AuditTaskReportDataStructIn *pSource);
/*批量数据结构缓冲写入AUDIT_TASK_REPORT_DATA*/
int EInsertStructToAuditTaskReportData(struct AuditTaskReportDataStruct *p,
	int iInsertFlag,struct AuditTaskReportDataStructOut *pTarget);
/**对表AUDIT_TASK_REPORT_DATA的链表释放函数**/
void DestroyAuditTaskReportData(struct AuditTaskReportDataStruct *ptHead);

/*输出结构缓冲申明*/
struct AuditAcctDetailStructOut{

#ifndef AUDIT_ACCT_DETAIL_BUFLEN_OUT
#define AUDIT_ACCT_DETAIL_BUFLEN_OUT		300
#endif

	struct AuditAcctDetailStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 任务ID */
	char    asTaskID[AUDIT_ACCT_DETAIL_BUFLEN_OUT][5];
		/* 参照audit_task_report_data.acct_detail_id */
	int     aiDetailID[AUDIT_ACCT_DETAIL_BUFLEN_OUT];
		/* 用户号码 */
	char    asMsisdn[AUDIT_ACCT_DETAIL_BUFLEN_OUT][21];
		/* 明细内容 */
	char    asContent[AUDIT_ACCT_DETAIL_BUFLEN_OUT][4001];
		/* 差异标识:   Y 有差异,N 无差异(是跟据AUD表中所有帐目都相等判断), E (无法判断) */
	char    asDiffFlag[AUDIT_ACCT_DETAIL_BUFLEN_OUT][2];
};



/* 输入结构缓冲申明*/
struct AuditAcctDetailStructIn{

#ifndef AUDIT_ACCT_DETAIL_BUFLEN_IN
#define AUDIT_ACCT_DETAIL_BUFLEN_IN		300
#endif

	struct AuditAcctDetailStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 任务ID */
	char    asTaskID[AUDIT_ACCT_DETAIL_BUFLEN_IN][5];
		/* 参照audit_task_report_data.acct_detail_id */
	int     aiDetailID[AUDIT_ACCT_DETAIL_BUFLEN_IN];
		/* 用户号码 */
	char    asMsisdn[AUDIT_ACCT_DETAIL_BUFLEN_IN][21];
		/* 明细内容 */
	char    asContent[AUDIT_ACCT_DETAIL_BUFLEN_IN][4001];
		/* 差异标识:   Y 有差异,N 无差异(是跟据AUD表中所有帐目都相等判断), E (无法判断) */
	char    asDiffFlag[AUDIT_ACCT_DETAIL_BUFLEN_IN][2];
};


/*单个结构申明*/
struct AuditAcctDetailStruct{

	struct AuditAcctDetailStruct *pNext;
	char    sTaskID[5];		/* 任务ID */
	int     iDetailID;		/* 参照audit_task_report_data.acct_detail_id */
	char    sMsisdn[21];		/* 用户号码 */
	char    sContent[4001];		/* 明细内容 */
	char    sDiffFlag[2];		/* 差异标识:   Y 有差异,N 无差异(是跟据AUD表中所有帐目都相等判断), E (无法判断) */
	struct AuditAcctDetailStruct *pLoadNext;
};

/*批量数据动态从AUDIT_ACCT_DETAIL中用结构缓冲方式取数据*/
int EGetAuditAcctDetailToStruct(struct AuditAcctDetailStruct *p,
	struct AuditAcctDetailStructIn *pSource);
/*批量数据结构缓冲写入AUDIT_ACCT_DETAIL*/
int EInsertStructToAuditAcctDetail(struct AuditAcctDetailStruct *p,
	int iInsertFlag,struct AuditAcctDetailStructOut *pTarget);
/**对表AUDIT_ACCT_DETAIL的链表释放函数**/
void DestroyAuditAcctDetail(struct AuditAcctDetailStruct *ptHead);

/* 输入结构缓冲申明*/
struct MuOtherStructIn{

#ifndef MU_OTHER_BUFLEN_IN
#define MU_OTHER_BUFLEN_IN		300
#endif

	struct MuOtherStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiMuID[MU_OTHER_BUFLEN_IN];
	char    asMuName[MU_OTHER_BUFLEN_IN][65];
	char    asMuDesc[MU_OTHER_BUFLEN_IN][1025];
	int     aiComponentID[MU_OTHER_BUFLEN_IN];
	int     aiMemberID[MU_OTHER_BUFLEN_IN];
	char    asMemberName[MU_OTHER_BUFLEN_IN][101];
	int     aiMemberType[MU_OTHER_BUFLEN_IN];
	char    asDateActive[MU_OTHER_BUFLEN_IN][15];
	char    asDateInactive[MU_OTHER_BUFLEN_IN][15];
};


/*单个结构申明*/
struct MuOtherStruct{

	struct MuOtherStruct *pNext;
	int     iMuID;
	char    sMuName[65];
	char    sMuDesc[1025];
	int     iComponentID;
	int     iMemberID;
	char    sMemberName[101];
	int     iMemberType;
	char    sDateActive[15];
	char    sDateInactive[15];
	struct MuOtherStruct *pLoadNext;
};
/*批量数据动态从MU_OTHER中用结构缓冲方式取数据*/
int EGetMuOtherToStruct(struct MuOtherStruct *p,
	struct MuOtherStructIn *pSource);
/**对表MU_OTHER的链表释放函数**/
void DestroyMuOther(struct MuOtherStruct *ptHead);

struct ExtractDefStruct{

	struct ExtractDefStruct *pNext;
	char    sAccNbr[21];		/* 号码 */
	int     iSubscriptionID;		/* 订购标识 */
	int     iAcctID;		/* 帐户 */
	char    sRegionID[2];		/* 地市 */
	char    sBillingTypeID[11];		/* 套餐 */
	char    sCatg[2];		/* 套餐类型*/
	int	iDiffProtry;		/* 差异等级，只有在生成报表时候用到 */
	struct ExtractDefStruct *pLoadNext;
};

/*稽核日志*/
/*输出结构缓冲申明*/
struct UserAuditLogStructOut{

#ifndef USER_AUDIT_LOG_BUFLEN_OUT
#define USER_AUDIT_LOG_BUFLEN_OUT		300
#endif

	struct UserAuditLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 任务ID */
	char    asTaskID[USER_AUDIT_LOG_BUFLEN_OUT][5];
		/* A:账单稽核任务,   T 清单稽核任务 */
	char    asType[USER_AUDIT_LOG_BUFLEN_OUT][2];
		/* 任务名称 */
	char    asTaskName[USER_AUDIT_LOG_BUFLEN_OUT][41];
		/* 工号 */
	int     aiStaffID[USER_AUDIT_LOG_BUFLEN_OUT];
		/* 地区 */
	char    asAreaCode[USER_AUDIT_LOG_BUFLEN_OUT][6];
		/* 稽核月份 */
	char    asMonth[USER_AUDIT_LOG_BUFLEN_OUT][7];
		/* 稽核类型 */
	char    asAuditType[USER_AUDIT_LOG_BUFLEN_OUT][2];
		/* 关注号码个数 */
	int     aiMsisdnCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* 关注套餐个数 */
	int     aiBillCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* 关注号码列表 */
	char    asMsisdnList[USER_AUDIT_LOG_BUFLEN_OUT][4001];
		/* 关注套餐列表 */
	char    asBillList[USER_AUDIT_LOG_BUFLEN_OUT][4001];
		/* 稽核日志 */
	char    asRunLog[USER_AUDIT_LOG_BUFLEN_OUT][4001];
		/* 操作时间 */
	char    asRunTime[USER_AUDIT_LOG_BUFLEN_OUT][15];
		/* 差异个数 */
	int	aiDiffCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* 用户总数 */
	int 	aiAllCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* 操作标志，P为成功，F为失败 */
	char	asAuditState[USER_AUDIT_LOG_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct UserAuditLogStructIn{

#ifndef USER_AUDIT_LOG_BUFLEN_IN
#define USER_AUDIT_LOG_BUFLEN_IN		300
#endif

	struct UserAuditLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 任务ID */
	char    asTaskID[USER_AUDIT_LOG_BUFLEN_IN][5];
		/* A:账单稽核任务,   T 清单稽核任务 */
	char    asType[USER_AUDIT_LOG_BUFLEN_IN][2];
		/* 任务名称 */
	char    asTaskName[USER_AUDIT_LOG_BUFLEN_IN][41];
		/* 工号 */
	int     aiStaffID[USER_AUDIT_LOG_BUFLEN_IN];
		/* 地区 */
	char    asAreaCode[USER_AUDIT_LOG_BUFLEN_IN][6];
		/* 稽核月份 */
	char    asMonth[USER_AUDIT_LOG_BUFLEN_IN][7];
		/* 稽核类型 */
	char    asAuditType[USER_AUDIT_LOG_BUFLEN_IN][2];
		/* 关注号码个数 */
	int     aiMsisdnCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* 关注套餐个数 */
	int     aiBillCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* 关注号码列表 */
	char    asMsisdnList[USER_AUDIT_LOG_BUFLEN_IN][4001];
		/* 关注套餐列表 */
	char    asBillList[USER_AUDIT_LOG_BUFLEN_IN][4001];
		/* 稽核日志 */
	char    asRunLog[USER_AUDIT_LOG_BUFLEN_IN][4001];
		/* 操作时间 */
	char    asRunTime[USER_AUDIT_LOG_BUFLEN_IN][15];
		/* 差异个数 */
	int	aiDiffCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* 用户总数 */
	int 	aiAllCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* 操作标志，P为成功，F为失败 */
	char	asAuditState[USER_AUDIT_LOG_BUFLEN_IN][2];
};


/*单个结构申明*/
struct UserAuditLogStruct{

	struct UserAuditLogStruct *pNext;
	char    sTaskID[5];		/* 任务ID */
	char    sType[2];		/* A:账单稽核任务,   T 清单稽核任务 */
	char    sTaskName[41];		/* 任务名称 */
	int     iStaffID;		/* 工号 */
	char    sAreaCode[6];		/* 地区 */
	char    sMonth[7];		/* 稽核月份 */
	char    sAuditType[2];		/* 稽核类型 */
	int     iMsisdnCount;		/* 关注号码个数 */
	int     iBillCount;		/* 关注套餐个数 */
	char    sMsisdnList[4001];		/* 关注号码列表 */
	char    sBillList[4001];		/* 关注套餐列表 */
	char    sRunLog[4001];		/* 稽核日志 */
	char    sRunTime[15];		/* 操作时间 */
	int	iDiffCount;		/* 差异个数 */
	int 	iAllCount;		/* 用户总数 */
	char	sAuditState[2];		/* 操作标志，P为成功，F为失败 */
	struct UserAuditLogStruct *pLoadNext;
};

/*批量数据动态从USER_AUDIT_LOG中用结构缓冲方式取数据*/
int EGetUserAuditLogToStruct(struct UserAuditLogStruct *p,
	struct UserAuditLogStructIn *pSource);
/**对表USER_AUDIT_LOG的链表释放函数**/
void DestroyUserAuditLog(struct UserAuditLogStruct *ptHead);
/*批量数据结构缓冲写入USER_AUDIT_LOG*/
int EInsertStructToUserAuditLog(struct UserAuditLogStruct *p,
	int iInsertFlag,struct UserAuditLogStructOut *pTarget);




/****************************套餐相关性分析部分***************

有四部分数据：
第一：基础参数数据
第二：套餐基础指标参数数据
第三：用户基础指标参数数据
第四：相应指标数据

***************************************************************/


/******************第一部分*******************************

这里为基础指标参数
指标承诺要素与原承诺要素关系、指标账目类型与原账目类型关系、
业务模式与承诺费率关系、指标承诺要素、指标帐目类型、指标业务类型、
业务实现模式
***********************************************************/
/*输出结构缓冲申明*/
struct CrPromiseElementRelationStructOut{

#ifndef CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT
#define CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT		300
#endif

	struct CrPromiseElementRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 指标承诺要素ID */
	int     aiCrPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT];
		/* 承诺要素ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrPromiseElementRelationStructIn{

#ifndef CR_PROMISE_ELEMENT_RELATION_BUFLEN_IN
#define CR_PROMISE_ELEMENT_RELATION_BUFLEN_IN		300
#endif

	struct CrPromiseElementRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 指标承诺要素ID */
	int     aiCrPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_IN];
		/* 承诺要素ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_IN];
};


/*单个结构申明*/
struct CrPromiseElementRelationStruct{

	struct CrPromiseElementRelationStruct *pNext;
	int     iCrPromiseElementID;		/* 指标承诺要素ID */
	int     iPromiseElementID;		/* 承诺要素ID */
	struct CrPromiseElementRelationStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrPromiseElementRelationStruct{

	char    sCrPromiseElementID[6];		/* 指标承诺要素ID */
	char    sPromiseElementID[6];		/* 承诺要素ID */
};


/*批量数据动态从CR_PROMISE_ELEMENT_RELATION中用结构缓冲方式取数据*/
int EGetCrPromiseElementRelationToStruct(struct CrPromiseElementRelationStruct *p,
	struct CrPromiseElementRelationStructIn *pSource);
/**对表CR_PROMISE_ELEMENT_RELATION的链表释放函数**/
void DestroyCrPromiseElementRelation(struct CrPromiseElementRelationStruct *ptHead);
int InitCrPromiseElementRelation(struct CrPromiseElementRelationStruct **pptHead);

/*输出结构缓冲申明*/
struct CrAcctItemTypeRelationStructOut{

#ifndef CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT
#define CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT		300
#endif

	struct CrAcctItemTypeRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 指标账目类型ID */
	int     aiCrAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
		/* 账目类型ID */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrAcctItemTypeRelationStructIn{

#ifndef CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_IN
#define CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_IN		300
#endif

	struct CrAcctItemTypeRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 指标账目类型ID */
	int     aiCrAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
		/* 账目类型ID */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
};


/*单个结构申明*/
struct CrAcctItemTypeRelationStruct{

	struct CrAcctItemTypeRelationStruct *pNext;
	int     iCrAcctItemTypeID;		/* 指标账目类型ID */
	int     iAcctItemTypeID;		/* 账目类型ID */
	struct CrAcctItemTypeRelationStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrAcctItemTypeRelationStruct{

	char    sCrAcctItemTypeID[6];		/* 指标账目类型ID */
	char    sAcctItemTypeID[6];		/* 账目类型ID */
};


/*批量数据动态从CR_ACCT_ITEM_TYPE_RELATION中用结构缓冲方式取数据*/
int EGetCrAcctItemTypeRelationToStruct(struct CrAcctItemTypeRelationStruct *p,
	struct CrAcctItemTypeRelationStructIn *pSource);
/**对表CR_ACCT_ITEM_TYPE_RELATION的链表释放函数**/
void DestroyCrAcctItemTypeRelation(struct CrAcctItemTypeRelationStruct *ptHead);
int InitCrAcctItemTypeRelation(struct CrAcctItemTypeRelationStruct **pptHead);

/*输出结构缓冲申明*/
struct CrPatternTariffRelationStructOut{

#ifndef CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT
#define CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT		300
#endif

	struct CrPatternTariffRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 模式ID */
	int     aiPatternID[CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT];
		/* 资费ID */
	int     aiTariffID[CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrPatternTariffRelationStructIn{

#ifndef CR_PATTERN_TARIFF_RELATION_BUFLEN_IN
#define CR_PATTERN_TARIFF_RELATION_BUFLEN_IN		300
#endif

	struct CrPatternTariffRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 模式ID */
	int     aiPatternID[CR_PATTERN_TARIFF_RELATION_BUFLEN_IN];
		/* 资费ID */
	int     aiTariffID[CR_PATTERN_TARIFF_RELATION_BUFLEN_IN];
};


/*单个结构申明*/
struct CrPatternTariffRelationStruct{

	struct CrPatternTariffRelationStruct *pNext;
	int     iPatternID;		/* 模式ID */
	int     iTariffID;		/* 资费ID */
	struct CrPatternTariffRelationStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrPatternTariffRelationStruct{

	char    sPatternID[6];		/* 模式ID */
	char    sTariffID[6];		/* 资费ID */
};


/*批量数据动态从CR_PATTERN_TARIFF_RELATION中用结构缓冲方式取数据*/
int EGetCrPatternTariffRelationToStruct(struct CrPatternTariffRelationStruct *p,
	struct CrPatternTariffRelationStructIn *pSource);
/**对表CR_PATTERN_TARIFF_RELATION的链表释放函数**/
void DestroyCrPatternTariffRelation(struct CrPatternTariffRelationStruct *ptHead);
int InitCrPatternTariffRelation(struct CrPatternTariffRelationStruct **pptHead);

/*输出结构缓冲申明*/
struct CrPromiseElementStructOut{

#ifndef CR_PROMISE_ELEMENT_BUFLEN_OUT
#define CR_PROMISE_ELEMENT_BUFLEN_OUT		300
#endif

	struct CrPromiseElementStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 指标要素ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_BUFLEN_OUT];
		/* 父要素ID */
	int     aiParentID[CR_PROMISE_ELEMENT_BUFLEN_OUT];
		/* 要素名称 */
	char    asName[CR_PROMISE_ELEMENT_BUFLEN_OUT][41];
		/* 叶子标识 */
	char    asLeaveFlag[CR_PROMISE_ELEMENT_BUFLEN_OUT][2];
		/* 层次 */
	int     aiLay[CR_PROMISE_ELEMENT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrPromiseElementStructIn{

#ifndef CR_PROMISE_ELEMENT_BUFLEN_IN
#define CR_PROMISE_ELEMENT_BUFLEN_IN		300
#endif

	struct CrPromiseElementStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 指标要素ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_BUFLEN_IN];
		/* 父要素ID */
	int     aiParentID[CR_PROMISE_ELEMENT_BUFLEN_IN];
		/* 要素名称 */
	char    asName[CR_PROMISE_ELEMENT_BUFLEN_IN][41];
		/* 叶子标识 */
	char    asLeaveFlag[CR_PROMISE_ELEMENT_BUFLEN_IN][2];
		/* 层次 */
	int     aiLay[CR_PROMISE_ELEMENT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrPromiseElementStruct{

	struct CrPromiseElementStruct *pNext;
	int     iPromiseElementID;		/* 指标要素ID */
	int     iParentID;		/* 父要素ID */
	char    sName[41];		/* 要素名称 */
	char    sLeaveFlag[2];		/* 叶子标识 */
	int     iLay;		/* 层次 */
	struct CrPromiseElementStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrPromiseElementStruct{

	char    sPromiseElementID[6];		/* 指标要素ID */
	char    sParentID[6];		/* 父要素ID */
	char    sName[40];		/* 要素名称 */
	char    sLeaveFlag[1];		/* 叶子标识 */
	char    sLay[1];		/* 层次 */
};


/*批量数据动态从CR_PROMISE_ELEMENT中用结构缓冲方式取数据*/
int EGetCrPromiseElementToStruct(struct CrPromiseElementStruct *p,
	struct CrPromiseElementStructIn *pSource);
/**对表CR_PROMISE_ELEMENT的链表释放函数**/
void DestroyCrPromiseElement(struct CrPromiseElementStruct *ptHead);
int InitCrPromiseElement(struct CrPromiseElementStruct **pptHead);

/*输出结构缓冲申明*/
struct CrServiceTypeStructOut{

#ifndef CR_SERVICE_TYPE_BUFLEN_OUT
#define CR_SERVICE_TYPE_BUFLEN_OUT		300
#endif

	struct CrServiceTypeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 指标业务类型ID */
	int     aiServiceTypeID[CR_SERVICE_TYPE_BUFLEN_OUT];
		/* 父业务类型ID */
	int     aiParentID[CR_SERVICE_TYPE_BUFLEN_OUT];
		/* 名称 */
	char    asName[CR_SERVICE_TYPE_BUFLEN_OUT][81];
		/* 叶子标识 */
	char    asLeaveFlag[CR_SERVICE_TYPE_BUFLEN_OUT][2];
		/* 层次 */
	int     aiLay[CR_SERVICE_TYPE_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrServiceTypeStructIn{

#ifndef CR_SERVICE_TYPE_BUFLEN_IN
#define CR_SERVICE_TYPE_BUFLEN_IN		300
#endif

	struct CrServiceTypeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 指标业务类型ID */
	int     aiServiceTypeID[CR_SERVICE_TYPE_BUFLEN_IN];
		/* 父业务类型ID */
	int     aiParentID[CR_SERVICE_TYPE_BUFLEN_IN];
		/* 名称 */
	char    asName[CR_SERVICE_TYPE_BUFLEN_IN][81];
		/* 叶子标识 */
	char    asLeaveFlag[CR_SERVICE_TYPE_BUFLEN_IN][2];
		/* 层次 */
	int     aiLay[CR_SERVICE_TYPE_BUFLEN_IN];
};


/*单个结构申明*/
struct CrServiceTypeStruct{

	struct CrServiceTypeStruct *pNext;
	int     iServiceTypeID;		/* 指标业务类型ID */
	int     iParentID;		/* 父业务类型ID */
	char    sName[81];		/* 名称 */
	char    sLeaveFlag[2];		/* 叶子标识 */
	int     iLay;		/* 层次 */
	struct CrServiceTypeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrServiceTypeStruct{

	char    sServiceTypeID[6];		/* 指标业务类型ID */
	char    sParentID[6];		/* 父业务类型ID */
	char    sName[80];		/* 名称 */
	char    sLeaveFlag[1];		/* 叶子标识 */
	char    sLay[1];		/* 层次 */
};


/*批量数据动态从CR_SERVICE_TYPE中用结构缓冲方式取数据*/
int EGetCrServiceTypeToStruct(struct CrServiceTypeStruct *p,
	struct CrServiceTypeStructIn *pSource);
/**对表CR_SERVICE_TYPE的链表释放函数**/
void DestroyCrServiceType(struct CrServiceTypeStruct *ptHead);
int InitCrServiceType(struct CrServiceTypeStruct **pptHead);

/*输出结构缓冲申明*/
struct CrServiceImplPatternStructOut{

#ifndef CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT
#define CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT		300
#endif

	struct CrServiceImplPatternStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 模式ID */
	int     aiPatternID[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT];
		/* 父模式ID */
	int     aiParentID[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT];
		/* 名称 */
	char    asName[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT][81];
		/* 叶子标识 */
	char    asLeaveFlag[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT][2];
		/* 层次 */
	int     aiLay[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrServiceImplPatternStructIn{

#ifndef CR_SERVICE_IMPL_PATTERN_BUFLEN_IN
#define CR_SERVICE_IMPL_PATTERN_BUFLEN_IN		300
#endif

	struct CrServiceImplPatternStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 模式ID */
	int     aiPatternID[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN];
		/* 父模式ID */
	int     aiParentID[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN];
		/* 名称 */
	char    asName[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN][81];
		/* 叶子标识 */
	char    asLeaveFlag[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN][2];
		/* 层次 */
	int     aiLay[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN];
};


/*单个结构申明*/
struct CrServiceImplPatternStruct{

	struct CrServiceImplPatternStruct *pNext;
	int     iPatternID;		/* 模式ID */
	int     iParentID;		/* 父模式ID */
	char    sName[81];		/* 名称 */
	char    sLeaveFlag[2];		/* 叶子标识 */
	int     iLay;		/* 层次 */
	struct CrServiceImplPatternStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrServiceImplPatternStruct{

	char    sPatternID[8];		/* 模式ID */
	char    sParentID[8];		/* 父模式ID */
	char    sName[80];		/* 名称 */
	char    sLeaveFlag[1];		/* 叶子标识 */
	char    sLay[1];		/* 层次 */
};


/*批量数据动态从CR_SERVICE_IMPL_PATTERN中用结构缓冲方式取数据*/
int EGetCrServiceImplPatternToStruct(struct CrServiceImplPatternStruct *p,
	struct CrServiceImplPatternStructIn *pSource);
/**对表CR_SERVICE_IMPL_PATTERN的链表释放函数**/
void DestroyCrServiceImplPattern(struct CrServiceImplPatternStruct *ptHead);
int InitCrServiceImplPattern(struct CrServiceImplPatternStruct **pptHead);

/*******************第二部分数据*************************

套餐(承诺要素)指标关系、套餐(账目类型)指标关系
套餐(业务类型)指标关系、套餐(业务实现模式)指标关系

**************************************************************/
/*输出结构缓冲申明*/
struct CrBillPromiseEleRltStructOut{

#ifndef CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT
#define CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT		300
#endif

	struct CrBillPromiseEleRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][21];
		/* 指标要素ID */
	int     aiPromiseElementID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrBillPromiseEleRltStructIn{

#ifndef CR_BILL_PROMISE_ELE_RLT_BUFLEN_IN
#define CR_BILL_PROMISE_ELE_RLT_BUFLEN_IN		300
#endif

	struct CrBillPromiseEleRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_IN][21];
		/* 指标要素ID */
	int     aiPromiseElementID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrBillPromiseEleRltStruct{

	struct CrBillPromiseEleRltStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iPromiseElementID;		/* 指标要素ID */
	struct CrBillPromiseEleRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillPromiseEleRltStruct{

	char    sBillingTypeID[20];		/* 套餐ID */
	char    sPromiseElementID[8];		/* 指标要素ID */
};


/*批量数据动态从CR_BILL_PROMISE_ELE_RLT中用结构缓冲方式取数据*/
int EGetCrBillPromiseEleRltToStruct(struct CrBillPromiseEleRltStruct *p,
	struct CrBillPromiseEleRltStructIn *pSource);
/**对表CR_BILL_PROMISE_ELE_RLT的链表释放函数**/
void DestroyCrBillPromiseEleRlt(struct CrBillPromiseEleRltStruct *ptHead);
int InitCrBillPromiseEleRlt(struct CrBillPromiseEleRltStruct **pptHead);
/*批量数据结构缓冲写入CR_BILL_PROMISE_ELE_RLT*/
int EInsertStructToCrBillPromiseEleRlt(struct CrBillPromiseEleRltStruct *p,
	int iInsertFlag,struct CrBillPromiseEleRltStructOut *pTarget);
	
/*输出结构缓冲申明*/
struct CrBillAcctItemRltStructOut{

#ifndef CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT
#define CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT		300
#endif

	struct CrBillAcctItemRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][21];
		/* 指标帐目类型ID */
	int     aiAcctItemTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrBillAcctItemRltStructIn{

#ifndef CR_BILL_ACCT_ITEM_RLT_BUFLEN_IN
#define CR_BILL_ACCT_ITEM_RLT_BUFLEN_IN		300
#endif

	struct CrBillAcctItemRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_IN][21];
		/* 指标帐目类型ID */
	int     aiAcctItemTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrBillAcctItemRltStruct{

	struct CrBillAcctItemRltStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iAcctItemTypeID;		/* 指标帐目类型ID */
	struct CrBillAcctItemRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillAcctItemRltStruct{

	char    sBillingTypeID[20];		/* 套餐ID */
	char    sAcctItemTypeID[8];		/* 指标帐目类型ID */
};


/*批量数据动态从CR_BILL_ACCT_ITEM_RLT中用结构缓冲方式取数据*/
int EGetCrBillAcctItemRltToStruct(struct CrBillAcctItemRltStruct *p,
	struct CrBillAcctItemRltStructIn *pSource);
/**对表CR_BILL_ACCT_ITEM_RLT的链表释放函数**/
void DestroyCrBillAcctItemRlt(struct CrBillAcctItemRltStruct *ptHead);
int InitCrBillAcctItemRlt(struct CrBillAcctItemRltStruct **pptHead);
/*批量数据结构缓冲写入CR_BILL_ACCT_ITEM_RLT*/
int EInsertStructToCrBillAcctItemRlt(struct CrBillAcctItemRltStruct *p,
	int iInsertFlag,struct CrBillAcctItemRltStructOut *pTarget);
/*输出结构缓冲申明*/
struct CrBillPatternRltStructOut{

#ifndef CR_BILL_PATTERN_RLT_BUFLEN_OUT
#define CR_BILL_PATTERN_RLT_BUFLEN_OUT		300
#endif

	struct CrBillPatternRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_PATTERN_RLT_BUFLEN_OUT][21];
		/* 模式ID */
	int     aiPatternID[CR_BILL_PATTERN_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrBillPatternRltStructIn{

#ifndef CR_BILL_PATTERN_RLT_BUFLEN_IN
#define CR_BILL_PATTERN_RLT_BUFLEN_IN		300
#endif

	struct CrBillPatternRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_PATTERN_RLT_BUFLEN_IN][21];
		/* 模式ID */
	int     aiPatternID[CR_BILL_PATTERN_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrBillPatternRltStruct{

	struct CrBillPatternRltStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iPatternID;		/* 模式ID */
	struct CrBillPatternRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillPatternRltStruct{

	char    sBillingTypeID[20];		/* 套餐ID */
	char    sPatternID[8];		/* 模式ID */
};


/*批量数据动态从CR_BILL_PATTERN_RLT中用结构缓冲方式取数据*/
int EGetCrBillPatternRltToStruct(struct CrBillPatternRltStruct *p,
	struct CrBillPatternRltStructIn *pSource);
/**对表CR_BILL_PATTERN_RLT的链表释放函数**/
void DestroyCrBillPatternRlt(struct CrBillPatternRltStruct *ptHead);
int InitCrBillPatternRlt(struct CrBillPatternRltStruct **pptHead);
/*批量数据结构缓冲写入CR_BILL_PATTERN_RLT*/
int EInsertStructToCrBillPatternRlt(struct CrBillPatternRltStruct *p,
	int iInsertFlag,struct CrBillPatternRltStructOut *pTarget);

/*输出结构缓冲申明*/
struct CrBillServTypeRltStructOut{

#ifndef CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT
#define CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT		300
#endif

	struct CrBillServTypeRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT][21];
		/* 指标业务类型ID */
	int     aiServiceTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrBillServTypeRltStructIn{

#ifndef CR_BILL_SERV_TYPE_RLT_BUFLEN_IN
#define CR_BILL_SERV_TYPE_RLT_BUFLEN_IN		300
#endif

	struct CrBillServTypeRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_IN][21];
		/* 指标业务类型ID */
	int     aiServiceTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrBillServTypeRltStruct{

	struct CrBillServTypeRltStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iServiceTypeID;		/* 指标业务类型ID */
	struct CrBillServTypeRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillServTypeRltStruct{

	char    sBillingTypeID[20];		/* 套餐ID */
	char    sServiceTypeID[8];		/* 指标业务类型ID */
};


/*批量数据动态从CR_BILL_SERV_TYPE_RLT中用结构缓冲方式取数据*/
int EGetCrBillServTypeRltToStruct(struct CrBillServTypeRltStruct *p,
	struct CrBillServTypeRltStructIn *pSource);
/**对表CR_BILL_SERV_TYPE_RLT的链表释放函数**/
void DestroyCrBillServTypeRlt(struct CrBillServTypeRltStruct *ptHead);
int InitCrBillServTypeRlt(struct CrBillServTypeRltStruct **pptHead);
/*批量数据结构缓冲写入CR_BILL_SERV_TYPE_RLT*/
int EInsertStructToCrBillServTypeRlt(struct CrBillServTypeRltStruct *p,
	int iInsertFlag,struct CrBillServTypeRltStructOut *pTarget);

/****************第三部分数据***************************

用户套餐(承诺要素)指标关系、用户套餐(账目类型)指标关系
用户套餐(业务类型)指标关系、用户套餐(业务实现模式)指标关系

*******************************************************/

/*输出结构缓冲申明*/
struct CrUserBillPromiseEleRltStructOut{

#ifndef USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT
#define USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillPromiseEleRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 账号或用户号码 */
	char    asAccNbr[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
		/* 套餐ID */
	char    asBillingTypeID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][21];
		/* 指标要素ID */
	int     aiPromiseElementID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][2];
		/* 使用量 */
	int     aiUsage[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
		/* 权重 */
	int     aiWeight[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrUserBillPromiseEleRltStructIn{

#ifndef USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN
#define USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN		300
#endif

	struct CrUserBillPromiseEleRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 账号或用户号码 */
	char    asAccNbr[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN][21];
		/* 指标要素ID */
	int     aiPromiseElementID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN][2];
		/* 使用量 */
	int     aiUsage[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
		/* 权重 */
	int     aiWeight[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrUserBillPromiseEleRltStruct{

	struct CrUserBillPromiseEleRltStruct *pNext;
	char    sAccNbr[21];		/* 账号或用户号码 */
	int	iSubscriptionID;	/* 用户订购标识，如果为账户则订购标识为0 */
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iPromiseElementID;		/* 指标要素ID */
	char    sRelationType[2];		/* A 账户关系   M 用户套餐 关系 */
	int     iUsage;		/* 使用量 */
	int     iWeight;		/* 权重 */
	struct CrUserBillPromiseEleRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrUserBillPromiseEleRltStruct{

	char    sAccNbr[20];		/* 账号或用户号码 */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sPromiseElementID[6];		/* 指标要素ID */
	char    sRelationType[1];		/* A 账户关系   M 用户套餐 关系 */
	char    sUsage[9];		/* 使用量 */
	char    sWeight[4];		/* 权重 */
};


/*批量数据动态从USER_BILL_PROMISE_ELE_RLT中用结构缓冲方式取数据*/
int EGetUserBillPromiseEleRltToStruct(struct CrUserBillPromiseEleRltStruct *p,
	struct CrUserBillPromiseEleRltStructIn *pSource);
/**对表USER_BILL_PROMISE_ELE_RLT的链表释放函数**/
void DestroyUserBillPromiseEleRlt(struct CrUserBillPromiseEleRltStruct *ptHead);
int InitUserBillPromiseEleRlt(struct CrUserBillPromiseEleRltStruct **pptHead);
/*批量数据结构缓冲写入USER_BILL_PROMISE_ELE_RLT*/
int EInsertStructToUserBillPromiseEleRlt(struct CrUserBillPromiseEleRltStruct *p,
	int iInsertFlag,struct CrUserBillPromiseEleRltStructOut *pTarget);

/*输出结构缓冲申明*/
struct CrUserBillAcctItemRltStructOut{

#ifndef CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT
#define CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillAcctItemRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 账号或用户号码 */
	char    asAccNbr[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
		/* 套餐ID */
	char    asBillingTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][21];
		/* 指标账目类型ID */
	int     aiAcctItemTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][2];
		/* 使用量 */
	int     aiUsage[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
		/* 权重 */
	int     aiWeight[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrUserBillAcctItemRltStructIn{

#ifndef CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN
#define CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN		300
#endif

	struct CrUserBillAcctItemRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 账号或用户号码 */
	char    asAccNbr[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN][21];
		/* 指标账目类型ID */
	int     aiAcctItemTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN][2];
		/* 使用量 */
	int     aiUsage[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
		/* 权重 */
	int     aiWeight[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrUserBillAcctItemRltStruct{

	struct CrUserBillAcctItemRltStruct *pNext;
	char    sAccNbr[21];		/* 账号或用户号码 */
	int	iSubscriptionID;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iAcctItemTypeID;		/* 指标账目类型ID */
	char    sRelationType[2];		/* A 账户关系   M 用户套餐 关系 */
	int     iUsage;		/* 使用量 */
	int     iWeight;		/* 权重 */
	struct CrUserBillAcctItemRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrUserBillAcctItemRltStruct{

	char    sAccNbr[20];		/* 账号或用户号码 */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sAcctItemTypeID[8];		/* 指标账目类型ID */
	char    sRelationType[1];		/* A 账户关系   M 用户套餐 关系 */
	char    sUsage[9];		/* 使用量 */
	char    sWeight[4];		/* 权重 */
};


/*批量数据动态从CR_USER_BILL_ACCT_ITEM_RLT中用结构缓冲方式取数据*/
int EGetCrUserBillAcctItemRltToStruct(struct CrUserBillAcctItemRltStruct *p,
	struct CrUserBillAcctItemRltStructIn *pSource);
/**对表CR_USER_BILL_ACCT_ITEM_RLT的链表释放函数**/
void DestroyCrUserBillAcctItemRlt(struct CrUserBillAcctItemRltStruct *ptHead);
int InitCrUserBillAcctItemRlt(struct CrUserBillAcctItemRltStruct **pptHead);
/*批量数据结构缓冲写入CR_USER_BILL_ACCT_ITEM_RLT*/
int EInsertStructToCrUserBillAcctItemRlt(struct CrUserBillAcctItemRltStruct *p,
	int iInsertFlag,struct CrUserBillAcctItemRltStructOut *pTarget);

/*输出结构缓冲申明*/
struct CrUserBillServiceTypeRltStructOut{

#ifndef CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT
#define CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillServiceTypeRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 账号或用户号码 */
	char    asAccNbr[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
		/* 套餐ID */
	char    asBillingTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT][21];
		/* 指标业务类型ID */
	int     aiServiceTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT][2];
		/* 使用量 */
	int     aiUsage[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
		/* 权重 */
	int     aiWeight[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrUserBillServiceTypeRltStructIn{

#ifndef CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN
#define CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN		300
#endif

	struct CrUserBillServiceTypeRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 账号或用户号码 */
	char    asAccNbr[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN][21];
		/* 指标业务类型ID */
	int     aiServiceTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN][2];
		/* 使用量 */
	int     aiUsage[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
		/* 权重 */
	int     aiWeight[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrUserBillServiceTypeRltStruct{

	struct CrUserBillServiceTypeRltStruct *pNext;
	char    sAccNbr[21];		/* 账号或用户号码 */
	int	iSubscriptionID;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iServiceTypeID;		/* 指标业务类型ID */
	char    sRelationType[2];		/* A 账户关系   M 用户套餐 关系 */
	int     iUsage;		/* 使用量 */
	int     iWeight;		/* 权重 */
	struct CrUserBillServiceTypeRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrUserBillServiceTypeRltStruct{

	char    sAccNbr[20];		/* 账号或用户号码 */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sServiceTypeID[8];		/* 指标业务类型ID */
	char    sRelationType[1];		/* A 账户关系   M 用户套餐 关系 */
	char    sUsage[9];		/* 使用量 */
	char    sWeight[4];		/* 权重 */
};


/*批量数据动态从CR_USER_BILL_SERVICE_TYPE_RLT中用结构缓冲方式取数据*/
int EGetCrUserBillServiceTypeRltToStruct(struct CrUserBillServiceTypeRltStruct *p,
	struct CrUserBillServiceTypeRltStructIn *pSource);
/**对表CR_USER_BILL_SERVICE_TYPE_RLT的链表释放函数**/
void DestroyCrUserBillServiceTypeRlt(struct CrUserBillServiceTypeRltStruct *ptHead);
int InitCrUserBillServiceTypeRlt(struct CrUserBillServiceTypeRltStruct **pptHead);
/*批量数据结构缓冲写入CR_USER_BILL_SERVICE_TYPE_RLT*/
int EInsertStructToCrUserBillServiceTypeRlt(struct CrUserBillServiceTypeRltStruct *p,
	int iInsertFlag,struct CrUserBillServiceTypeRltStructOut *pTarget);

/*输出结构缓冲申明*/
struct CrUserBillPatternRltStructOut{

#ifndef CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT
#define CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillPatternRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 账号或用户号码 */
	char    asAccNbr[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
		/* 套餐ID */
	char    asBillingTypeID[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT][21];
		/* 模式ID */
	int     aiPatternID[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT][2];
		/* 使用量 */
	int     aiUsage[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
		/* 权重 */
	int     aiWeight[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrUserBillPatternRltStructIn{

#ifndef CR_USER_BILL_PATTERN_RLT_BUFLEN_IN
#define CR_USER_BILL_PATTERN_RLT_BUFLEN_IN		300
#endif

	struct CrUserBillPatternRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 账号或用户号码 */
	char    asAccNbr[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN][21];
		/* 用户订购标识，如果为账户则订购标识为0 */
	int	aiSubscriptionID[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN][21];
		/* 模式ID */
	int     aiPatternID[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
		/* A 账户关系   M 用户套餐 关系 */
	char    asRelationType[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN][2];
		/* 使用量 */
	int     aiUsage[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
		/* 权重 */
	int     aiWeight[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrUserBillPatternRltStruct{

	struct CrUserBillPatternRltStruct *pNext;
	char    sAccNbr[21];		/* 账号或用户号码 */
	int	iSubscriptionID;
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iPatternID;		/* 模式ID */
	char    sRelationType[2];		/* A 账户关系   M 用户套餐 关系 */
	int     iUsage;		/* 使用量 */
	int     iWeight;		/* 权重 */
	struct CrUserBillPatternRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrUserBillPatternRltStruct{

	char    sAccNbr[20];		/* 账号或用户号码 */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sPatternID[8];		/* 模式ID */
	char    sRelationType[1];		/* A 账户关系   M 用户套餐 关系 */
	char    sUsage[9];		/* 使用量 */
	char    sWeight[4];		/* 权重 */
};


/*批量数据动态从CR_USER_BILL_PATTERN_RLT中用结构缓冲方式取数据*/
int EGetCrUserBillPatternRltToStruct(struct CrUserBillPatternRltStruct *p,
	struct CrUserBillPatternRltStructIn *pSource);
/**对表CR_USER_BILL_PATTERN_RLT的链表释放函数**/
void DestroyCrUserBillPatternRlt(struct CrUserBillPatternRltStruct *ptHead);
int InitCrUserBillPatternRlt(struct CrUserBillPatternRltStruct **pptHead);
/*批量数据结构缓冲写入CR_USER_BILL_PATTERN_RLT*/
int EInsertStructToCrUserBillPatternRlt(struct CrUserBillPatternRltStruct *p,
	int iInsertFlag,struct CrUserBillPatternRltStructOut *pTarget);


/*输出结构缓冲申明*/
struct CrMsisdnStatStructOut{

#ifndef CR_MSISDN_STAT_BUFLEN_OUT
#define CR_MSISDN_STAT_BUFLEN_OUT		300
#endif

	struct CrMsisdnStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 统计标识ID */
	char    asCrMsisdnStatID[CR_MSISDN_STAT_BUFLEN_OUT][13];
		/* 用户号码 */
	char    asMsisdn[CR_MSISDN_STAT_BUFLEN_OUT][21];
		/* 用户归属区号 */
	char    asAreaCode[CR_MSISDN_STAT_BUFLEN_OUT][10];
		/* 用户订购标识 */
	int     aiSubscriptionID[CR_MSISDN_STAT_BUFLEN_OUT];
		/* 套餐ID */
	char    asBillingTypeID[CR_MSISDN_STAT_BUFLEN_OUT][21];
		/* 业务类型 */
	char    asServiceType[CR_MSISDN_STAT_BUFLEN_OUT][11];
		/* 指标ID */
	int     aiIndexID[CR_MSISDN_STAT_BUFLEN_OUT];
		/* 话单数 */
	int     aiTotalCnt[CR_MSISDN_STAT_BUFLEN_OUT];
		/* 使用量 */
	char    asAmount[CR_MSISDN_STAT_BUFLEN_OUT][13];
		/* 使用量类型 K ，M 等等 */
	char    asAmountUnit[CR_MSISDN_STAT_BUFLEN_OUT][2];
		/* 计费费用 */
	char    asCharge[CR_MSISDN_STAT_BUFLEN_OUT][13];
		/* 平均费率 */
	double  adRate[CR_MSISDN_STAT_BUFLEN_OUT];
		/* 费率单位 */
	char    asRateUnit[CR_MSISDN_STAT_BUFLEN_OUT][2];
		/* (费率)档位ID */
	int     aiXGradeID[CR_MSISDN_STAT_BUFLEN_OUT];
		/* 权重占比 */
	int     aiWeight[CR_MSISDN_STAT_BUFLEN_OUT];
		/* 分摊信息 */
	char	asApportInfo[CR_MSISDN_STAT_BUFLEN_OUT][2001];
};


/* 输入结构缓冲申明*/
struct CrMsisdnStatStructIn{

#ifndef CR_MSISDN_STAT_BUFLEN_IN
#define CR_MSISDN_STAT_BUFLEN_IN		300
#endif

	struct CrMsisdnStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 统计标识ID */
	char    asCrMsisdnStatID[CR_MSISDN_STAT_BUFLEN_IN][13];
		/* 用户号码 */
	char    asMsisdn[CR_MSISDN_STAT_BUFLEN_IN][21];
		/* 用户归属区号 */
	char    asAreaCode[CR_MSISDN_STAT_BUFLEN_IN][10];
		/* 用户订购标识 */
	int     aiSubscriptionID[CR_MSISDN_STAT_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[CR_MSISDN_STAT_BUFLEN_IN][21];
		/* 业务类型 */
	char    asServiceType[CR_MSISDN_STAT_BUFLEN_IN][11];
		/* 指标ID */
	int     aiIndexID[CR_MSISDN_STAT_BUFLEN_IN];
		/* 话单数 */
	int     aiTotalCnt[CR_MSISDN_STAT_BUFLEN_IN];
		/* 使用量 */
	char    asAmount[CR_MSISDN_STAT_BUFLEN_IN][13];
		/* 使用量类型 K ，M 等等 */
	char    asAmountUnit[CR_MSISDN_STAT_BUFLEN_IN][2];
		/* 计费费用 */
	char    asCharge[CR_MSISDN_STAT_BUFLEN_IN][13];
		/* 平均费率 */
	double  adRate[CR_MSISDN_STAT_BUFLEN_IN];
		/* 费率单位 */
	char    asRateUnit[CR_MSISDN_STAT_BUFLEN_IN][2];
		/* (费率)档位ID */
	int     aiXGradeID[CR_MSISDN_STAT_BUFLEN_IN];
		/* 权重占比 */
	int     aiWeight[CR_MSISDN_STAT_BUFLEN_IN];
		/* 分摊信息 */
	char	asApportInfo[CR_MSISDN_STAT_BUFLEN_IN][2001];	
};


/*单个结构申明*/
struct CrMsisdnStatStruct{

	struct CrMsisdnStatStruct *pNext;
/*	char    sCrMsisdnStatID[13];*/		/* 统计标识ID */
	char    sMsisdn[21];		/* 用户号码 */
	char    sAreaCode[10];		/* 用户归属区号 */
	int     iSubscriptionID;		/* 用户订购标识 */
	char    sBillingTypeID[21];		/* 套餐ID */
	char    sServiceType[11];		/* 业务类型 */
	int     iIndexID;		/* 指标ID */
	int     iTotalCnt;		/* 话单数 */
	int	iVolume;		/* 使用量 */
	char    sVolumeUnit[2];		/* 使用量类型 K ，M 等等 */
	int     iCharge;		/* 计费费用 */
	double  dRate;			/* 平均费率 */
	char    sRateUnit[2];		/* 费率单位 */
	char    sXGradeID[7];		/* (费率)档位ID */
	char    sYGradeID[7];		/* (使用量)档位ID */
	int     iWeight;		/* 权重占比 */
	int	iApportFee;		/* 分摊的费用 */
	/*char	sApportInfo[2001];*/	/* 分摊信息 */
	char	sIndexCatg[2];		/* 指标类型 */
	char	sBillingTypeCatg[2];	/* 产品类型 */
	
	struct CrMsisdnStatStruct *pLoadNext;
	
/*新统计流程*/
/*	int	iAccountID;	*/	/* 账户ID */
	int 	iAcctItemTypeID;	/* 账目ID */
	char	sSubServiceCode[11];	/* 子业务类型 */
	char	sApportType[2];		/* 分摊类型 */
	char	cApprotFlag;		/* 摊分标识 */
	int	iTotalFee;		/* 统计费用 */
};


/*单个文件结构申明*/
struct FCrMsisdnStatStruct{

	char    sCrMsisdnStatID[12];		/* 统计标识ID */
	char    sMsisdn[20];		/* 用户号码 */
	char    sAreaCode[9];		/* 用户归属区号 */
	char    sSubscriptionID[9];		/* 用户订购标识 */
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sServiceType[10];		/* 业务类型 */
	char    sIndexID[4];		/* 指标ID */
	char    sTotalCnt[9];		/* 话单数 */
	char    sVolume[12];		/* 使用量 */
	char    sVolumeUnit[1];		/* 使用量类型 K ，M 等等 */
	char    sCharge[12];		/* 计费费用 */
	char    sRate[8];		/* 平均费率 */
	char    sRateUnit[1];		/* 费率单位 */
	char    sXGradeID[6];		/* (费率)档位ID */
	char    sWeight[4];		/* 权重占比 */
/*虚拟字段*/
	char	sCfee[12];		/* 第一费用 */
	char	sLfee[12];		/* 第二费用 */
};
/*单个文件结构申明*/
struct FCrMsisdnStatStructX{

	char    sCrMsisdnStatID[12];		/* 统计标识ID */
	char    sMsisdn[20];		/* 用户号码 */
	char    sAreaCode[9];		/* 用户归属区号 */
	char    sSubscriptionID[9];		/* 用户订购标识 */
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sServiceType[10];		/* 业务类型 */
	char    sIndexID[4];		/* 指标ID */
	char    sTotalCnt[9];		/* 话单数 */
	char    sVolume[12];		/* 使用量 */
	char    sVolumeUnit[1];		/* 使用量类型 K ，M 等等 */
	char    sCharge[12];		/* 计费费用 */
	char    sRate[9];		/* 平均费率 */
	char    sRateUnit[1];		/* 费率单位 */
	char    sXGradeID[6];		/* (费率)档位ID */
	char    sWeight[12];		/* 权重占比 */
	char    sApportFee[12];		/* 分摊费用 */
	char    sYGradeID[6];		/* (使用量)档位ID */
	char    sIndexCatg[1];		/* 指标类型 */
	char    sBillingTypeCatg[1];		/* 套餐类型 */
};



/*批量数据动态从CR_MSISDN_STAT中用结构缓冲方式取数据*/
int EGetCrMsisdnStatToStruct(struct CrMsisdnStatStruct *p,
	struct CrMsisdnStatStructIn *pSource);
/**对表CR_MSISDN_STAT的链表释放函数**/
void DestroyCrMsisdnStat(struct CrMsisdnStatStruct *ptHead);
/*批量数据结构缓冲写入CR_MSISDN_STAT*/
int EInsertStructToCrMsisdnStat(struct CrMsisdnStatStruct *p,
	int iInsertFlag,struct CrMsisdnStatStructOut *pTarget);
void mvitem_fmcrmsisdnstat(struct FCrMsisdnStatStruct *pi,struct CrMsisdnStatStruct *po);
void mvitem_mfcrmsisdnstat(struct CrMsisdnStatStruct *pi,struct FCrMsisdnStatStruct *po);
/*输出结构缓冲申明*/
struct CrBillingTypeStatStructOut{

#ifndef CR_BILLING_TYPE_STAT_BUFLEN_OUT
#define CR_BILLING_TYPE_STAT_BUFLEN_OUT		300
#endif

	struct CrBillingTypeStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 统计标识ID */
	char    asCrBillingTypeStatID[CR_BILLING_TYPE_STAT_BUFLEN_OUT][13];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILLING_TYPE_STAT_BUFLEN_OUT][21];
		/* 套餐归属区号 */
	char    asAreaCode[CR_BILLING_TYPE_STAT_BUFLEN_OUT][10];
		/* 业务类型 */
	char    asServiceType[CR_BILLING_TYPE_STAT_BUFLEN_OUT][11];
		/* 指标ID */
	int     aiIndexID[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* 话单数 */
	int     aiTotalCnt[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* 使用量 */
	char    asAmount[CR_BILLING_TYPE_STAT_BUFLEN_OUT][13];
		/* 使用量类型 K ，M 等等 */
	char    asAmountUnit[CR_BILLING_TYPE_STAT_BUFLEN_OUT][2];
		/* 计费费用 */
	char    asCharge[CR_BILLING_TYPE_STAT_BUFLEN_OUT][13];
		/* 平均费率 */
	double  adRate[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* 费率单位 */
	char    asRateUnit[CR_BILLING_TYPE_STAT_BUFLEN_OUT][2];
		/* (费率)档位ID */
	int     aiXGradeID[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* (使用量)档位ID */
	int     aiYGradeID[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* 权重占比 */
	int     aiWeight[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrBillingTypeStatStructIn{

#ifndef CR_BILLING_TYPE_STAT_BUFLEN_IN
#define CR_BILLING_TYPE_STAT_BUFLEN_IN		300
#endif

	struct CrBillingTypeStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 统计标识ID */
	char    asCrBillingTypeStatID[CR_BILLING_TYPE_STAT_BUFLEN_IN][13];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILLING_TYPE_STAT_BUFLEN_IN][21];
		/* 套餐归属区号 */
	char    asAreaCode[CR_BILLING_TYPE_STAT_BUFLEN_IN][10];
		/* 业务类型 */
	char    asServiceType[CR_BILLING_TYPE_STAT_BUFLEN_IN][11];
		/* 指标ID */
	int     aiIndexID[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* 话单数 */
	int     aiTotalCnt[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* 使用量 */
	char    asAmount[CR_BILLING_TYPE_STAT_BUFLEN_IN][13];
		/* 使用量类型 K ，M 等等 */
	char    asAmountUnit[CR_BILLING_TYPE_STAT_BUFLEN_IN][2];
		/* 计费费用 */
	char    asCharge[CR_BILLING_TYPE_STAT_BUFLEN_IN][13];
		/* 平均费率 */
	int     aiRate[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* 费率单位 */
	char    asRateUnit[CR_BILLING_TYPE_STAT_BUFLEN_IN][2];
		/* (费率)档位ID */
	int     aiXGradeID[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* (使用量)档位ID */
	int     aiYGradeID[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* 权重占比 */
	int     aiWeight[CR_BILLING_TYPE_STAT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrBillingTypeStatStruct{

	struct CrBillingTypeStatStruct *pNext;
	char    sCrBillingTypeStatID[13];		/* 统计标识ID */
	char    sBillingTypeID[21];		/* 套餐ID */
	char    sAreaCode[10];		/* 套餐归属区号 */
	char    sServiceType[11];		/* 业务类型 */
	int     iIndexID;		/* 指标ID */
	int     iTotalCnt;		/* 话单数 */
	int     iAmount;		/* 使用量 */
	char    sAmountUnit[2];		/* 使用量类型 K ，M 等等 */
	int	iCharge;		/* 计费费用 */
	double  dRate;			/* 平均费率 */
	double  dAmountRate;		/* 平均使用量 */
	char    sRateUnit[2];		/* 费率单位 */
	char    sXGradeID[7];		/* (费率)档位ID */
	char    sYGradeID[7];		/* (使用量)档位ID */
	int     iWeight;		/* 权重占比 */
	int	iApportFee;		/* 摊分到的费用 */
	int	iUserCnt;		/* 用户数 */
	char	sIndexCatg[2];		/* 指标类型 */
	

	struct CrBillingTypeStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillingTypeStatStruct{

	char    sCrBillingTypeStatID[12];		/* 统计标识ID */
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sAreaCode[9];		/* 套餐归属区号 */
	char    sServiceType[10];		/* 业务类型 */
	char    sIndexID[4];		/* 指标ID */
	char    sTotalCnt[9];		/* 话单数 */
	char    sAmount[12];		/* 使用量 */
	char    sAmountUnit[1];		/* 使用量类型 K ，M 等等 */
	char    sCharge[12];		/* 计费费用 */
	char    sRate[8];		/* 平均费率 */
	char    sRateUnit[1];		/* 费率单位 */
	char    sXGradeID[6];		/* (费率)档位ID */
	char    sYGradeID[6];		/* (使用量)档位ID */
	char    sWeight[4];		/* 权重占比 */
};


/*批量数据动态从CR_BILLING_TYPE_STAT中用结构缓冲方式取数据*/
int EGetCrBillingTypeStatToStruct(struct CrBillingTypeStatStruct *p,
	struct CrBillingTypeStatStructIn *pSource);
/**对表CR_BILLING_TYPE_STAT的链表释放函数**/
void DestroyCrBillingTypeStat(struct CrBillingTypeStatStruct *ptHead);
/*批量数据结构缓冲写入CR_BILLING_TYPE_STAT*/
int EInsertStructToCrBillingTypeStat(struct CrBillingTypeStatStruct *p,
	int iInsertFlag,struct CrBillingTypeStatStructOut *pTarget);

/*输出结构缓冲申明*/
struct CrPromiseAcctRelationStructOut{

#ifndef CR_PROMISE_ACCT_RELATION_BUFLEN_OUT
#define CR_PROMISE_ACCT_RELATION_BUFLEN_OUT		300
#endif

	struct CrPromiseAcctRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 旧承诺要素ID */
	int     aiPromiseElementID[CR_PROMISE_ACCT_RELATION_BUFLEN_OUT];
		/* 账目类型ID */
	int     aiAcctItemTypeID[CR_PROMISE_ACCT_RELATION_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrPromiseAcctRelationStructIn{

#ifndef CR_PROMISE_ACCT_RELATION_BUFLEN_IN
#define CR_PROMISE_ACCT_RELATION_BUFLEN_IN		300
#endif

	struct CrPromiseAcctRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 旧承诺要素ID */
	int     aiPromiseElementID[CR_PROMISE_ACCT_RELATION_BUFLEN_IN];
		/* 账目类型ID */
	int     aiAcctItemTypeID[CR_PROMISE_ACCT_RELATION_BUFLEN_IN];
};


/*单个结构申明*/
struct CrPromiseAcctRelationStruct{

	struct CrPromiseAcctRelationStruct *pNext;
	int     iPromiseElementID;		/* 旧承诺要素ID */
	int     iAcctItemTypeID;		/* 账目类型ID */
	struct CrPromiseAcctRelationStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrPromiseAcctRelationStruct{

	char    sPromiseElementID[4];		/* 旧承诺要素ID */
	char    sAcctItemTypeID[6];		/* 账目类型ID */
};


/*批量数据动态从CR_PROMISE_ACCT_RELATION中用结构缓冲方式取数据*/
int EGetCrPromiseAcctRelationToStruct(struct CrPromiseAcctRelationStruct *p,
	struct CrPromiseAcctRelationStructIn *pSource);
/**对表CR_PROMISE_ACCT_RELATION的链表释放函数**/
void DestroyCrPromiseAcctRelation(struct CrPromiseAcctRelationStruct *ptHead);
int InitCrPromiseAcctRelation(struct CrPromiseAcctRelationStruct **pptHead);

/*输出结构缓冲申明*/
struct CrAcctItemTypeStructOut{

#ifndef CR_ACCT_ITEM_TYPE_BUFLEN_OUT
#define CR_ACCT_ITEM_TYPE_BUFLEN_OUT		300
#endif

	struct CrAcctItemTypeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_BUFLEN_OUT];
		/* 名称 */
	char    asAcctItemName[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][61];
		/* 业务类型 */
	char    asServiceType[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][5];
		/* cr_子业务类型 */
	char    asSubServiceCode[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][9];
		/* 分摊类型 A :直接对到一个指标 B:直接对到多个指标 C:(单业务)且要结合套餐才能确定所对的指标  D:(多业务)且要结合套餐才能确定所对的指标 */
	char    asApportionType[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][2];
		/* 分摊优先级 */
	int     aiPriority[CR_ACCT_ITEM_TYPE_BUFLEN_OUT];
		/* 费用来源字段序号 */
	int     aiFeeSeq[CR_ACCT_ITEM_TYPE_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrAcctItemTypeStructIn{

#ifndef CR_ACCT_ITEM_TYPE_BUFLEN_IN
#define CR_ACCT_ITEM_TYPE_BUFLEN_IN		300
#endif

	struct CrAcctItemTypeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_BUFLEN_IN];
		/* 名称 */
	char    asAcctItemName[CR_ACCT_ITEM_TYPE_BUFLEN_IN][61];
		/* 业务类型 */
	char    asServiceType[CR_ACCT_ITEM_TYPE_BUFLEN_IN][5];
		/* cr_子业务类型 */
	char    asSubServiceCode[CR_ACCT_ITEM_TYPE_BUFLEN_IN][9];
		/* 分摊类型 A :直接对到一个指标 B:直接对到多个指标 C:(单业务)且要结合套餐才能确定所对的指标  D:(多业务)且要结合套餐才能确定所对的指标 */
	char    asApportionType[CR_ACCT_ITEM_TYPE_BUFLEN_IN][2];
		/* 分摊优先级 */
	int     aiPriority[CR_ACCT_ITEM_TYPE_BUFLEN_IN];
		/* 费用来源字段序号 */
	int     aiFeeSeq[CR_ACCT_ITEM_TYPE_BUFLEN_IN];
};


/*单个结构申明*/
struct CrAcctItemTypeStruct{

	struct CrAcctItemTypeStruct *pNext;
	int     iAcctItemTypeID;		/* 帐目类型标识 */
	char    sAcctItemName[61];		/* 名称 */
	char    sServiceType[5];		/* 业务类型 */
	char    sSubServiceCode[9];		/* cr_子业务类型 */
	char    sApportionType[2];		/* 分摊类型 A :直接对到一个指标 B:直接对到多个指标 C:(单业务)且要结合套餐才能确定所对的指标  D:(多业务)且要结合套餐才能确定所对的指标 */
	int     iPriority;		/* 分摊优先级 */
	int     iFeeSeq;		/* 费用来源字段序号 */
	struct CrAcctItemTypeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrAcctItemTypeStruct{

	char    sAcctItemTypeID[6];		/* 帐目类型标识 */
	char    sAcctItemName[60];		/* 名称 */
	char    sServiceType[4];		/* 业务类型 */
	char    sSubServiceCode[8];		/* cr_子业务类型 */
	char    sApportionType[1];		/* 分摊类型 A :直接对到一个指标 B:直接对到多个指标 C:(单业务)且要结合套餐才能确定所对的指标  D:(多业务)且要结合套餐才能确定所对的指标 */
	char    sPriority[2];		/* 分摊优先级 */
	char    sFeeSeq[1];		/* 费用来源字段序号 */
};


/*批量数据动态从CR_ACCT_ITEM_TYPE中用结构缓冲方式取数据*/
int EGetCrAcctItemTypeToStruct(struct CrAcctItemTypeStruct *p,
	struct CrAcctItemTypeStructIn *pSource);
/**对表CR_ACCT_ITEM_TYPE的链表释放函数**/
void DestroyCrAcctItemType(struct CrAcctItemTypeStruct *ptHead);
int InitCrAcctItemType(struct CrAcctItemTypeStruct **pptHead);

/*输出结构缓冲申明*/
struct CrSubServiceCodeStructOut{

#ifndef CR_SUB_SERVICE_CODE_BUFLEN_OUT
#define CR_SUB_SERVICE_CODE_BUFLEN_OUT		300
#endif

	struct CrSubServiceCodeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiSubServiceID[CR_SUB_SERVICE_CODE_BUFLEN_OUT];
	char    asSubServiceCode[CR_SUB_SERVICE_CODE_BUFLEN_OUT][9];
	char    asName[CR_SUB_SERVICE_CODE_BUFLEN_OUT][31];
	char    asServiceType[CR_SUB_SERVICE_CODE_BUFLEN_OUT][5];
};


/* 输入结构缓冲申明*/
struct CrSubServiceCodeStructIn{

#ifndef CR_SUB_SERVICE_CODE_BUFLEN_IN
#define CR_SUB_SERVICE_CODE_BUFLEN_IN		300
#endif

	struct CrSubServiceCodeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiSubServiceID[CR_SUB_SERVICE_CODE_BUFLEN_IN];
	char    asSubServiceCode[CR_SUB_SERVICE_CODE_BUFLEN_IN][9];
	char    asName[CR_SUB_SERVICE_CODE_BUFLEN_IN][31];
	char    asServiceType[CR_SUB_SERVICE_CODE_BUFLEN_IN][5];
};


/*单个结构申明*/
struct CrSubServiceCodeStruct{

	struct CrSubServiceCodeStruct *pNext;
	int     iSubServiceID;
	char    sSubServiceCode[9];
	char    sName[31];
	char    sServiceType[5];
	struct CrSubServiceCodeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrSubServiceCodeStruct{

	char    sSubServiceID[4];
	char    sSubServiceCode[8];
	char    sName[30];
	char    sServiceType[4];
};


/*批量数据动态从CR_SUB_SERVICE_CODE中用结构缓冲方式取数据*/
int EGetCrSubServiceCodeToStruct(struct CrSubServiceCodeStruct *p,
	struct CrSubServiceCodeStructIn *pSource);
/**对表CR_SUB_SERVICE_CODE的链表释放函数**/
void DestroyCrSubServiceCode(struct CrSubServiceCodeStruct *ptHead);
int InitCrSubServiceCode(struct CrSubServiceCodeStruct **pptHead);


/*输出结构缓冲申明*/
struct CrAcctIndexRltStructOut{

#ifndef CR_ACCT_INDEX_RLT_BUFLEN_OUT
#define CR_ACCT_INDEX_RLT_BUFLEN_OUT		300
#endif

	struct CrAcctIndexRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
		/* 指标要素ID */
	int     aiIndexID[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceType[CR_ACCT_INDEX_RLT_BUFLEN_OUT][5];
		/* 子业务类型 */
	char    asSubServiceCode[CR_ACCT_INDEX_RLT_BUFLEN_OUT][9];
		/* 分摊类型 */
	char    asApportionType[CR_ACCT_INDEX_RLT_BUFLEN_OUT][2];
		/* 费用来源字段序号 */
	int     aiFeeSeq[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
		/* 分摊比例 */
	int	aiPercent[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrAcctIndexRltStructIn{

#ifndef CR_ACCT_INDEX_RLT_BUFLEN_IN
#define CR_ACCT_INDEX_RLT_BUFLEN_IN		300
#endif

	struct CrAcctIndexRltStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_ACCT_INDEX_RLT_BUFLEN_IN];
		/* 指标要素ID */
	int     aiIndexID[CR_ACCT_INDEX_RLT_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceType[CR_ACCT_INDEX_RLT_BUFLEN_IN][5];
		/* 子业务类型 */
	char    asSubServiceCode[CR_ACCT_INDEX_RLT_BUFLEN_IN][9];
		/* 分摊类型 */
	char    asApportionType[CR_ACCT_INDEX_RLT_BUFLEN_IN][2];
		/* 费用来源字段序号 */
	int     aiFeeSeq[CR_ACCT_INDEX_RLT_BUFLEN_IN];
		/* 分摊比例 */
	int	aiPercent[CR_ACCT_INDEX_RLT_BUFLEN_IN];
};



/*单个结构申明*/
struct CrAcctIndexRltStruct{

	struct CrAcctIndexRltStruct *pNext;
	int     iAcctItemTypeID;		/* 帐目类型标识 */
	int     iIndexID;		/* 指标要素ID */
	int	iPercent;		/* 分摊比例 */
/*扩展字段*/
	int	iIndexAmount;		/* 指标在这个账目下的使用量 */
	int	iIndexFee;		/* 指标在这个账目下的费用量 */
	struct CrAcctIndexRltStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrAcctIndexRltStruct{

	char    sAcctItemTypeID[6];		/* 帐目类型标识 */
	char    sIndexID[4];		/* 指标要素ID */
	char    sServiceType[4];		/* 业务类型 */
	char    sSubServiceCode[8];		/* 子业务类型 */
	char    sApportionType[1];		/* 分摊类型 */
	char    sFeeSeq[1];		/* 费用来源字段序号 */
	char	sPercent[3];
};

/*批量数据动态从CR_ACCT_INDEX_RLT中用结构缓冲方式取数据*/
int EGetCrAcctIndexRltToStruct(struct CrAcctIndexRltStruct *p,
	struct CrAcctIndexRltStructIn *pSource);
/**对表CR_ACCT_INDEX_RLT的链表释放函数**/
void DestroyCrAcctIndexRlt(struct CrAcctIndexRltStruct *ptHead);
int InitCrAcctIndexRlt(struct CrAcctIndexRltStruct **pptHead);

/*获取CR_MSISDN_STAT_SEQ序列号*/
int GetCrMsisdnStatSeq();
/*获取CR_BILL_TYPE_STAT_SEQ序列号*/
int GetCrBillingTypeStatSeq();


/*输出结构缓冲申明*/
struct CrIndexGradeDescStructOut{

#ifndef CR_INDEX_GRADE_DESC_BUFLEN_OUT
#define CR_INDEX_GRADE_DESC_BUFLEN_OUT		300
#endif

	struct CrIndexGradeDescStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 档位ID */
	char    asGradeID[CR_INDEX_GRADE_DESC_BUFLEN_OUT][7];
		/* 名称 */
	char    asName[CR_INDEX_GRADE_DESC_BUFLEN_OUT][61];
		/* 说明 */
	char    asRemark[CR_INDEX_GRADE_DESC_BUFLEN_OUT][501];
		/* 指标要素ID */
	int     aiIndexID[CR_INDEX_GRADE_DESC_BUFLEN_OUT];
		/* 'S'业务量等级，'R'费率等级 */
	char    asType[CR_INDEX_GRADE_DESC_BUFLEN_OUT][2];
		/* 起始值 */
	int     aiBgnVal[CR_INDEX_GRADE_DESC_BUFLEN_OUT];
		/* 终止值 */
	int     aiEndVal[CR_INDEX_GRADE_DESC_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrIndexGradeDescStructIn{

#ifndef CR_INDEX_GRADE_DESC_BUFLEN_IN
#define CR_INDEX_GRADE_DESC_BUFLEN_IN		300
#endif

	struct CrIndexGradeDescStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 档位ID */
	char    asGradeID[CR_INDEX_GRADE_DESC_BUFLEN_IN][7];
		/* 名称 */
	char    asName[CR_INDEX_GRADE_DESC_BUFLEN_IN][61];
		/* 说明 */
	char    asRemark[CR_INDEX_GRADE_DESC_BUFLEN_IN][501];
		/* 指标要素ID */
	int     aiIndexID[CR_INDEX_GRADE_DESC_BUFLEN_IN];
		/* 'S'业务量等级，'R'费率等级 */
	char    asType[CR_INDEX_GRADE_DESC_BUFLEN_IN][2];
		/* 起始值 */
	int     aiBgnVal[CR_INDEX_GRADE_DESC_BUFLEN_IN];
		/* 终止值 */
	int     aiEndVal[CR_INDEX_GRADE_DESC_BUFLEN_IN];
};


/*单个结构申明*/
struct CrIndexGradeDescStruct{

	struct CrIndexGradeDescStruct *pNext;
	char    sGradeID[7];		/* 档位ID */
	char    sName[61];		/* 名称 */
	char    sRemark[501];		/* 说明 */
	int     iIndexID;		/* 指标要素ID */
	char    sType[2];		/* 'S'业务量等级，'R'费率等级 */
	int     iBgnVal;		/* 起始值 */
	int     iEndVal;		/* 终止值 */
	struct CrIndexGradeDescStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrIndexGradeDescStruct{

	char    sGradeID[6];		/* 档位ID */
	char    sName[60];		/* 名称 */
	char    sRemark[500];		/* 说明 */
	char    sIndexID[4];		/* 指标要素ID */
	char    sType[1];		/* 'S'业务量等级，'R'费率等级 */
	char    sBgnVal[9];		/* 起始值 */
	char    sEndVal[9];		/* 终止值 */
};


/*批量数据动态从CR_INDEX_GRADE_DESC中用结构缓冲方式取数据*/
int EGetCrIndexGradeDescToStruct(struct CrIndexGradeDescStruct *p,
	struct CrIndexGradeDescStructIn *pSource);
/**对表CR_INDEX_GRADE_DESC的链表释放函数**/
void DestroyCrIndexGradeDesc(struct CrIndexGradeDescStruct *ptHead);
int InitCrIndexGradeDesc(struct CrIndexGradeDescStruct **pptHead);

/*输出结构缓冲申明*/
struct CrBillTypeAcctApprStructOut{

#ifndef CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT
#define CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT		300
#endif

	struct CrBillTypeAcctApprStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT][21];
		/* 分摊标识 */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* 'P' 按业务量比例分摊,'S'手工设置分摊比例,'E'公式制定 */
	char    asMethod[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT][5];
		/* 参数串 */
	char    asParamStr[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT][121];
};


/* 输入结构缓冲申明*/
struct CrBillTypeAcctApprStructIn{

#ifndef CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN
#define CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN		300
#endif

	struct CrBillTypeAcctApprStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN][21];
		/* 分摊标识 */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN];
		/* 'P' 按业务量比例分摊,'S'手工设置分摊比例,'E'公式制定 */
	char    asMethod[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN][5];
		/* 参数串 */
	char    asParamStr[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN][121];
};


/*单个结构申明*/
struct CrBillTypeAcctApprStruct{

	struct CrBillTypeAcctApprStruct *pNext;
	int     iAcctItemTypeID;		/* 帐目类型标识 */
	char    sBillingTypeID[21];		/* 套餐ID */
	int     iApprID;		/* 分摊标识 */
	char    sMethod[5];		/* 'P' 按业务量比例分摊,'S'手工设置分摊比例,'E'公式制定 */
	char    sParamStr[121];		/* 参数串 */
	struct CrBillTypeAcctApprStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillTypeAcctApprStruct{

	char    sAcctItemTypeID[6];		/* 帐目类型标识 */
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sApprID[6];		/* 分摊标识 */
	char    sMethod[4];		/* 'P' 按业务量比例分摊,'S'手工设置分摊比例,'E'公式制定 */
	char    sParamStr[120];		/* 参数串 */
};


/*批量数据动态从CR_BILL_TYPE_ACCT_APPR中用结构缓冲方式取数据*/
int EGetCrBillTypeAcctApprToStruct(struct CrBillTypeAcctApprStruct *p,
	struct CrBillTypeAcctApprStructIn *pSource);
/**对表CR_BILL_TYPE_ACCT_APPR的链表释放函数**/
void DestroyCrBillTypeAcctAppr(struct CrBillTypeAcctApprStruct *ptHead);
int InitCrBillTypeAcctAppr(struct CrBillTypeAcctApprStruct **pptHead);

/*输出结构缓冲申明*/
struct CrBillTypeAcctApprParamStructOut{

#ifndef CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT
#define CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT		300
#endif

	struct CrBillTypeAcctApprParamStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 指标标识 */
	int     aiIndexID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* 分摊标识 */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* 分摊比例 */
	int     aiPercent[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrBillTypeAcctApprParamStructIn{

#ifndef CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN
#define CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN		300
#endif

	struct CrBillTypeAcctApprParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 指标标识 */
	int     aiIndexID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* 分摊标识 */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* 分摊比例 */
	int     aiPercent[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct CrBillTypeAcctApprParamStruct{

	struct CrBillTypeAcctApprParamStruct *pNext;
	int     iIndexID;		/* 指标标识 */
	int     iApprID;		/* 分摊标识 */
	int     iPercent;		/* 分摊比例 */
	
/*扩展需要*/
	int	iTotalFee;		/* 计费费用 */
	int	iTotalAmount;		/* 计费使用量 */
	char	cLastFlag;		/*最后一个处理,用于做误差处理,'0'为不是最后一个，'1'为最后一个*/
	struct CrBillTypeAcctApprParamStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillTypeAcctApprParamStruct{

	char    sIndexID[4];		/* 指标标识 */
	char    sApprID[6];		/* 分摊标识 */
	char    sPercent[3];		/* 分摊比例 */
};


/*批量数据动态从CR_BILL_TYPE_ACCT_APPR_PARAM中用结构缓冲方式取数据*/
int EGetCrBillTypeAcctApprParamToStruct(struct CrBillTypeAcctApprParamStruct *p,
	struct CrBillTypeAcctApprParamStructIn *pSource);
/**对表CR_BILL_TYPE_ACCT_APPR_PARAM的链表释放函数**/
void DestroyCrBillTypeAcctApprParam(struct CrBillTypeAcctApprParamStruct *ptHead);
int InitCrBillTypeAcctApprParam(struct CrBillTypeAcctApprParamStruct **pptHead);

/*输出结构缓冲申明*/
struct CrServiceTypeAcctApprStructOut{

#ifndef CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT
#define CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT		300
#endif

	struct CrServiceTypeAcctApprStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	int     aiServiceApprID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* 套餐ID */
	char    asBillingTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT][21];
		/* P:按比例分摊 V:按具体值分摊 */
	char    asMethod[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct CrServiceTypeAcctApprStructIn{

#ifndef CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN
#define CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN		300
#endif

	struct CrServiceTypeAcctApprStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	int     aiServiceApprID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN];
		/* 套餐ID */
	char    asBillingTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN][21];
		/* P:按比例分摊 V:按具体值分摊 */
	char    asMethod[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN][2];
};


/*单个结构申明*/
struct CrServiceTypeAcctApprStruct{

	struct CrServiceTypeAcctApprStruct *pNext;
	int     iServiceApprID;		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	int     iAcctItemTypeID;		/* 帐目类型标识 */
	char    sBillingTypeID[21];		/* 套餐ID */
	char    sMethod[2];		/* P:按比例分摊 V:按具体值分摊 */
	
	struct CrServiceTypeAcctApprStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrServiceTypeAcctApprStruct{

	char    sServiceApprID[4];		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	char    sAcctItemTypeID[6];		/* 帐目类型标识 */
	char    sBillingTypeID[20];		/* 套餐ID */
	char    sMethod[1];		/* P:按比例分摊 V:按具体值分摊 */
};


/*批量数据动态从CR_SERVICE_TYPE_ACCT_APPR中用结构缓冲方式取数据*/
int EGetCrServiceTypeAcctApprToStruct(struct CrServiceTypeAcctApprStruct *p,
	struct CrServiceTypeAcctApprStructIn *pSource);
/**对表CR_SERVICE_TYPE_ACCT_APPR的链表释放函数**/
void DestroyCrServiceTypeAcctAppr(struct CrServiceTypeAcctApprStruct *ptHead);
int InitCrServiceTypeAcctAppr(struct CrServiceTypeAcctApprStruct **pptHead);

/*输出结构缓冲申明*/
struct CrServTypeAcctApprParamStructOut{

#ifndef CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT
#define CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT		300
#endif

	struct CrServTypeAcctApprParamStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	int     aiServiceApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* 分摊标识 */
	int     aiApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceType[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT][5];
		/* 分摊值(比例) */
	int     aiValue[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrServTypeAcctApprParamStructIn{

#ifndef CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN
#define CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN		300
#endif

	struct CrServTypeAcctApprParamStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	int     aiServiceApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* 分摊标识 */
	int     aiApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceType[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN][5];
		/* 分摊值(比例) */
	int     aiValue[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
};


/*单个结构申明*/
struct CrServTypeAcctApprParamStruct{

	struct CrServTypeAcctApprParamStruct *pNext;
	int     iServiceApprID;		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	int     iApprID;		/* 分摊标识 */
	char    sServiceType[5];		/* 业务类型 */
	int     iValue;		/* 分摊值(比例) */
	
/*扩展字段*/
	int	iCharge;	/*业务营帐费用*/
	int	iAmount;	/*业务使用量*/
	int	iTotalFee;		/*被分摊到的这个业务的总费用*/
	char	cLastFlag;		/*最后一个处理,用于做误差处理,'0'为不是最后一个，'1'为最后一个*/
	struct CrServTypeAcctApprParamStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrServTypeAcctApprParamStruct{

	char    sServiceApprID[4];		/* 账目分摊到业务的方法(先摊到业务,然后对各业务再摊到指标) */
	char    sApprID[6];		/* 分摊标识 */
	char    sServiceType[4];		/* 业务类型 */
	char    sValue[8];		/* 分摊值(比例) */
};


/*批量数据动态从CR_SERV_TYPE_ACCT_APPR_PARAM中用结构缓冲方式取数据*/
int EGetCrServTypeAcctApprParamToStruct(struct CrServTypeAcctApprParamStruct *p,
	struct CrServTypeAcctApprParamStructIn *pSource);
/**对表CR_SERV_TYPE_ACCT_APPR_PARAM的链表释放函数**/
void DestroyCrServTypeAcctApprParam(struct CrServTypeAcctApprParamStruct *ptHead);
int InitCrServTypeAcctApprParam(struct CrServTypeAcctApprParamStruct **pptHead);

/*输出结构缓冲申明*/
struct CrServiceIndexStructOut{

#ifndef CR_SERVICE_INDEX_BUFLEN_OUT
#define CR_SERVICE_INDEX_BUFLEN_OUT		300
#endif

	struct CrServiceIndexStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 指标要素ID */
	int     aiIndexID[CR_SERVICE_INDEX_BUFLEN_OUT];
		/* 用于业务宣传 */
	char    asName[CR_SERVICE_INDEX_BUFLEN_OUT][41];
		/* 叶子标识 */
	char    asLeaveFlag[CR_SERVICE_INDEX_BUFLEN_OUT][2];
		/* 层次 */
	int     aiLay[CR_SERVICE_INDEX_BUFLEN_OUT];
		/* 父指标要素ID */
	int     aiParentID[CR_SERVICE_INDEX_BUFLEN_OUT];
		/* 业务类型 */
	char    asServiceType[CR_SERVICE_INDEX_BUFLEN_OUT][5];
		/* '0'　一般指标 'X'叠加指标 */
	char    asType[CR_SERVICE_INDEX_BUFLEN_OUT][2];
		/* 参考PROMISE_ELEMENT.RATE_UNIT字段取值 */
	char    asUnit[CR_SERVICE_INDEX_BUFLEN_OUT][2];
		/* CATG='F'表示分摊费用，CATG＝'D'表示，清单统计业务量 */
	char	asCatg[CR_SERVICE_INDEX_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct CrServiceIndexStructIn{

#ifndef CR_SERVICE_INDEX_BUFLEN_IN
#define CR_SERVICE_INDEX_BUFLEN_IN		300
#endif

	struct CrServiceIndexStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 指标要素ID */
	int     aiIndexID[CR_SERVICE_INDEX_BUFLEN_IN];
		/* 用于业务宣传 */
	char    asName[CR_SERVICE_INDEX_BUFLEN_IN][41];
		/* 叶子标识 */
	char    asLeaveFlag[CR_SERVICE_INDEX_BUFLEN_IN][2];
		/* 层次 */
	int     aiLay[CR_SERVICE_INDEX_BUFLEN_IN];
		/* 父指标要素ID */
	int     aiParentID[CR_SERVICE_INDEX_BUFLEN_IN];
		/* 业务类型 */
	char    asServiceType[CR_SERVICE_INDEX_BUFLEN_IN][5];
		/* '0'　一般指标 'X'叠加指标 */
	char    asType[CR_SERVICE_INDEX_BUFLEN_IN][2];
		/* 参考PROMISE_ELEMENT.RATE_UNIT字段取值 */
	char    asUnit[CR_SERVICE_INDEX_BUFLEN_IN][2];
		/* CATG='F'表示分摊费用，CATG＝'D'表示，清单统计业务量 */
	char	asCatg[CR_SERVICE_INDEX_BUFLEN_IN][2];
};


/*单个结构申明*/
struct CrServiceIndexStruct{

	struct CrServiceIndexStruct *pNext;
	int     iIndexID;		/* 指标要素ID */
	char    sName[41];		/* 用于业务宣传 */
	char    sLeaveFlag[2];		/* 叶子标识 */
	int     iLay;		/* 层次 */
	int     iParentID;		/* 父指标要素ID */
	char    sServiceType[5];		/* 业务类型 */
	char    sType[2];		/* '0'　一般指标 'X'叠加指标 */
	char    sUnit[2];		/* 参考PROMISE_ELEMENT.RATE_UNIT字段取值 */
	char	sCatg[2];		/* CATG='F'表示分摊费用，CATG＝'D'表示，清单统计业务量 */
	struct CrServiceIndexStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrServiceIndexStruct{

	char    sIndexID[4];		/* 指标要素ID */
	char    sName[40];		/* 用于业务宣传 */
	char    sLeaveFlag[1];		/* 叶子标识 */
	char    sLay[1];		/* 层次 */
	char    sParentID[4];		/* 父指标要素ID */
	char    sServiceType[4];		/* 业务类型 */
	char    sType[1];		/* '0'　一般指标 'X'叠加指标 */
	char    sUnit[1];		/* 参考PROMISE_ELEMENT.RATE_UNIT字段取值 */
	char	sCatg[1];		/* CATG='F'表示分摊费用，CATG＝'D'表示，清单统计业务量 */
};


/*批量数据动态从CR_SERVICE_INDEX中用结构缓冲方式取数据*/
int EGetCrServiceIndexToStruct(struct CrServiceIndexStruct *p,
	struct CrServiceIndexStructIn *pSource);
/**对表CR_SERVICE_INDEX的链表释放函数**/
void DestroyCrServiceIndex(struct CrServiceIndexStruct *ptHead);
int InitCrServiceIndex(struct CrServiceIndexStruct **pptHead);

/*输出结构缓冲申明*/
struct CrPackageTariffIDStructOut{

#ifndef CR_PACKAGE_TARIFF_ID_BUFLEN_OUT
#define CR_PACKAGE_TARIFF_ID_BUFLEN_OUT		300
#endif

	struct CrPackageTariffIDStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asBillingTypeID[CR_PACKAGE_TARIFF_ID_BUFLEN_OUT][21];
	char    asServiceType[CR_PACKAGE_TARIFF_ID_BUFLEN_OUT][5];
	int     aiTariffID[CR_PACKAGE_TARIFF_ID_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrPackageTariffIDStructIn{

#ifndef CR_PACKAGE_TARIFF_ID_BUFLEN_IN
#define CR_PACKAGE_TARIFF_ID_BUFLEN_IN		300
#endif

	struct CrPackageTariffIDStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asBillingTypeID[CR_PACKAGE_TARIFF_ID_BUFLEN_IN][21];
	char    asServiceType[CR_PACKAGE_TARIFF_ID_BUFLEN_IN][5];
	int     aiTariffID[CR_PACKAGE_TARIFF_ID_BUFLEN_IN];
};


/*单个结构申明*/
struct CrPackageTariffIDStruct{

	struct CrPackageTariffIDStruct *pNext;
	char    sBillingTypeID[21];
	char    sServiceType[5];
	int     iTariffID;
	struct CrPackageTariffIDStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrPackageTariffIDStruct{

	char    sBillingTypeID[20];
	char    sServiceType[4];
	char    sTariffID[6];
};


/*批量数据动态从CR_PACKAGE_TARIFF_ID中用结构缓冲方式取数据*/
int EGetCrPackageTariffIDToStruct(struct CrPackageTariffIDStruct *p,
	struct CrPackageTariffIDStructIn *pSource);
/**对表CR_PACKAGE_TARIFF_ID的链表释放函数**/
void DestroyCrPackageTariffID(struct CrPackageTariffIDStruct *ptHead);
int InitCrPackageTariffID(struct CrPackageTariffIDStruct **pptHead);

/*输出结构缓冲申明*/
struct CrIndexYGradeStructOut{

#ifndef CR_INDEX_Y_GRADE_BUFLEN_OUT
#define CR_INDEX_Y_GRADE_BUFLEN_OUT		300
#endif

	struct CrIndexYGradeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asBillingTypeID[CR_INDEX_Y_GRADE_BUFLEN_OUT][21];
	char    asServiceType[CR_INDEX_Y_GRADE_BUFLEN_OUT][11];
	int     aiIndexID[CR_INDEX_Y_GRADE_BUFLEN_OUT];
	char    asIndexUnit[CR_INDEX_Y_GRADE_BUFLEN_OUT][2];
	char    asYGradeID[CR_INDEX_Y_GRADE_BUFLEN_OUT][7];
	double     adUsrPct[CR_INDEX_Y_GRADE_BUFLEN_OUT];
	double     adIncPct[CR_INDEX_Y_GRADE_BUFLEN_OUT];
	double     adAvgVolume[CR_INDEX_Y_GRADE_BUFLEN_OUT];
	char    asCatg[CR_INDEX_Y_GRADE_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct CrIndexYGradeStructIn{

#ifndef CR_INDEX_Y_GRADE_BUFLEN_IN
#define CR_INDEX_Y_GRADE_BUFLEN_IN		300
#endif

	struct CrIndexYGradeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asBillingTypeID[CR_INDEX_Y_GRADE_BUFLEN_IN][21];
	char    asServiceType[CR_INDEX_Y_GRADE_BUFLEN_IN][11];
	int     aiIndexID[CR_INDEX_Y_GRADE_BUFLEN_IN];
	char    asIndexUnit[CR_INDEX_Y_GRADE_BUFLEN_IN][2];
	char    asYGradeID[CR_INDEX_Y_GRADE_BUFLEN_IN][7];
	double     adUsrPct[CR_INDEX_Y_GRADE_BUFLEN_IN];
	double     adIncPct[CR_INDEX_Y_GRADE_BUFLEN_IN];
	double     adAvgVolume[CR_INDEX_Y_GRADE_BUFLEN_IN];
	char    asCatg[CR_INDEX_Y_GRADE_BUFLEN_IN][2];
};


/*单个结构申明*/
struct CrIndexYGradeStruct{

	struct CrIndexYGradeStruct *pNext;
	char    sBillingTypeID[21];
	char    sServiceType[11];
	int     iIndexID;
	char    sIndexUnit[2];
	char    sYGradeID[7];
	double  dUsrPct;
	double  dIncPct;
	double  dAvgVolume;
	char    sCatg[2];
	char	sAreaCode[11];
	double  dAvgRate;
	
/*扩展需求*/
	double	dServicePct;	/*整个业务的比重*/
	double  dServiceIncPct;	/*指标占这个业务内的比重*/
	double	iVolume;
	double	iApportFee;
	int	iUserCnt;
	double dCorrelationCoefficent;/*这个套餐这个指标这个档位的相关性系数*/
	double dAvg_w;/*平均权重*/
	
	struct CrIndexYGradeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrIndexYGradeStruct{

	char    sBillingTypeID[20];
	char    sServiceType[10];
	char    sIndexID[4];
	char    sIndexUnit[1];
	char    sYGradeID[6];
	char    sUsrPct[8];
	char    sIncPct[8];
	char    sAvgVolume[8];
	char    sCatg[1];
};


/*批量数据动态从CR_INDEX_Y_GRADE中用结构缓冲方式取数据*/
int EGetCrIndexYGradeToStruct(struct CrIndexYGradeStruct *p,
	struct CrIndexYGradeStructIn *pSource);
/**对表CR_INDEX_Y_GRADE的链表释放函数**/
void DestroyCrIndexYGrade(struct CrIndexYGradeStruct *ptHead);
int InitCrIndexYGrade(struct CrIndexYGradeStruct **pptHead);

/*输出结构缓冲申明*/
struct CrIndexXGradeStructOut{

#ifndef CR_INDEX_X_GRADE_BUFLEN_OUT
#define CR_INDEX_X_GRADE_BUFLEN_OUT		300
#endif

	struct CrIndexXGradeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asBillingTypeID[CR_INDEX_X_GRADE_BUFLEN_OUT][21];
	char    asServiceType[CR_INDEX_X_GRADE_BUFLEN_OUT][11];
	int     aiIndexID[CR_INDEX_X_GRADE_BUFLEN_OUT];
	char    asIndexUnit[CR_INDEX_X_GRADE_BUFLEN_OUT][2];
	char    asXGradeID[CR_INDEX_X_GRADE_BUFLEN_OUT][7];
	double     adUsrPct[CR_INDEX_X_GRADE_BUFLEN_OUT];
	double     adIncPct[CR_INDEX_X_GRADE_BUFLEN_OUT];
	double     adAvgVolume[CR_INDEX_X_GRADE_BUFLEN_OUT];
	char    asCatg[CR_INDEX_X_GRADE_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct CrIndexXGradeStructIn{

#ifndef CR_INDEX_X_GRADE_BUFLEN_IN
#define CR_INDEX_X_GRADE_BUFLEN_IN		300
#endif

	struct CrIndexXGradeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asBillingTypeID[CR_INDEX_X_GRADE_BUFLEN_IN][21];
	char    asServiceType[CR_INDEX_X_GRADE_BUFLEN_IN][11];
	int     aiIndexID[CR_INDEX_X_GRADE_BUFLEN_IN];
	char    asIndexUnit[CR_INDEX_X_GRADE_BUFLEN_IN][2];
	char    asXGradeID[CR_INDEX_X_GRADE_BUFLEN_IN][7];
	double  adUsrPct[CR_INDEX_X_GRADE_BUFLEN_IN];
	double  adIncPct[CR_INDEX_X_GRADE_BUFLEN_IN];
	double  adAvgVolume[CR_INDEX_X_GRADE_BUFLEN_IN];
	char    asCatg[CR_INDEX_X_GRADE_BUFLEN_IN][2];
};


/*单个结构申明*/
struct CrIndexXGradeStruct{

	struct CrIndexXGradeStruct *pNext;
	char    sBillingTypeID[21];
	char    sServiceType[11];
	int     iIndexID;
	char    sIndexUnit[2];
	char    sXGradeID[7];
	double  dUsrPct;
	double  dIncPct;/*指标占整个套餐的比重*/
	double  dAvgVolume;
	char    sCatg[2];
	double  dAvgRate;
	char	sAreaCode[11];
	
/*扩展字段*/
	double	dServicePct;	/*整个业务的比重*/
	double  dServiceIncPct;	/*指标占这个业务内的比重*/
	double iVolume;
	double iApportFee;
	int iUserCnt;
	double dCorrelationCoefficent;/*这个套餐这个指标这个档位的相关性系数*/
	double dAvg_w;/*平均权重*/
	
	struct CrIndexXGradeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrIndexXGradeStruct{

	char    sBillingTypeID[20];
	char    sServiceType[10];
	char    sIndexID[4];
	char    sIndexUnit[1];
	char    sXGradeID[6];
	char    sUsrPct[8];
	char    sIncPct[8];
	char    sAvgVolume[8];
	char    sCatg[1];
};



/*批量数据动态从CR_INDEX_X_GRADE中用结构缓冲方式取数据*/
int EGetCrIndexXGradeToStruct(struct CrIndexXGradeStruct *p,
	struct CrIndexXGradeStructIn *pSource);
/**对表CR_INDEX_X_GRADE的链表释放函数**/
void DestroyCrIndexXGrade(struct CrIndexXGradeStruct *ptHead);
int InitCrIndexXGrade(struct CrIndexXGradeStruct **pptHead);

/*输出结构缓冲申明*/
struct CrBillingTypeCorrelationStructOut{

#ifndef CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT
#define CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT		300
#endif

	struct CrBillingTypeCorrelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 编码要求: C1111 */
	char    asTaskID[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][6];
		/* 套餐ID和相关套餐ID必须同属于主套餐或子套餐 */
	char    asBillingTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][21];
		/* 相关套餐ID */
	char    asCorrelationTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][21];
		/* 套餐类型 */
	char    asCatg[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][2];
		/* 用户归属地 */
	char    asAreaCode[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][10];
		/* R客户费率感知相关,P客户消费习惯相关 */
	char    asCorrelationType[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][2];
		/* 相关系数取值范围，0-1,０表示不相关，1表示全相关。 */
	double  adCorrelationCoefficent[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrBillingTypeCorrelationStructIn{

#ifndef CR_BILLING_TYPE_CORRELATION_BUFLEN_IN
#define CR_BILLING_TYPE_CORRELATION_BUFLEN_IN		300
#endif

	struct CrBillingTypeCorrelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 编码要求: C1111 */
	char    asTaskID[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][6];
		/* 套餐ID和相关套餐ID必须同属于主套餐或子套餐 */
	char    asBillingTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][21];
		/* 相关套餐ID */
	char    asCorrelationTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][21];
		/* 套餐类型 */
	char    asCatg[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][2];
		/* 用户归属地 */
	char    asAreaCode[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][10];
		/* R客户费率感知相关,P客户消费习惯相关 */
	char    asCorrelationType[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][2];
		/* 相关系数取值范围，0-1,０表示不相关，1表示全相关。 */
	double  adCorrelationCoefficent[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN];
};


/*单个结构申明*/
struct CrBillingTypeCorrelationStruct{

	struct CrBillingTypeCorrelationStruct *pNext;
	char    sTaskID[6];		/* 编码要求: C1111 */
	char    sBillingTypeID[21];		/* 套餐ID和相关套餐ID必须同属于主套餐或子套餐 */
	char    sCorrelationTypeID[21];		/* 相关套餐ID */
	char    sCatg[2];		/* 套餐类型 */
	char    sAreaCode[10];		/* 用户归属地 */
	char    sCorrelationType[2];		/* R客户费率感知相关,P客户消费习惯相关 */
	double  dCorrelationCoefficent;		/* 相关系数取值范围，0-1,０表示不相关，1表示全相关。 */
	char	sCorGrade[2];
	char	sCorInfo[2001];
	struct CrBillingTypeCorrelationStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrBillingTypeCorrelationStruct{

	char    sTaskID[5];		/* 编码要求: C1111 */
	char    sBillingTypeID[20];		/* 套餐ID和相关套餐ID必须同属于主套餐或子套餐 */
	char    sCorrelationTypeID[20];		/* 相关套餐ID */
	char    sCatg[1];		/* 套餐类型 */
	char    sAreaCode[9];		/* 用户归属地 */
	char    sCorrelationType[1];		/* R客户费率感知相关,P客户消费习惯相关 */
	char    sCorrelationCoefficent[3];		/* 相关系数取值范围，0-1,０表示不相关，1表示全相关。 */
};


/*批量数据动态从CR_BILLING_TYPE_CORRELATION中用结构缓冲方式取数据*/
int EGetCrBillingTypeCorrelationToStruct(struct CrBillingTypeCorrelationStruct *p,
	struct CrBillingTypeCorrelationStructIn *pSource);
/**对表CR_BILLING_TYPE_CORRELATION的链表释放函数**/
void DestroyCrBillingTypeCorrelation(struct CrBillingTypeCorrelationStruct *ptHead);
int InitCrBillingTypeCorrelation(struct CrBillingTypeCorrelationStruct **pptHead);


/*输出结构缓冲申明*/
struct BillingTypeStructOut{

#ifndef BILLING_TYPE_BUFLEN_OUT
#define BILLING_TYPE_BUFLEN_OUT		300
#endif

	struct BillingTypeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 套餐ID */
	char    asBillingTypeID[BILLING_TYPE_BUFLEN_OUT][21];
		/* 套餐模板ID */
	char    asTemplateID[BILLING_TYPE_BUFLEN_OUT][21];
		/* 套餐描述 */
	char    asRemark[BILLING_TYPE_BUFLEN_OUT][61];
		/* 类型,'B'表示主产品套餐,'b'表示子产品套餐,'S'表示业务品牌,'v'表示 VPN编号 */
	char    asCatg[BILLING_TYPE_BUFLEN_OUT][2];
		/* 业务品牌 */
	char    asServTypeID[BILLING_TYPE_BUFLEN_OUT][21];
		/* 实现模式(子产品套餐才有值) */
	char    asImplPattern[BILLING_TYPE_BUFLEN_OUT][5];
		/* 作用业务(子产品套餐才有值) */
	char    asAffectService[BILLING_TYPE_BUFLEN_OUT][5];
		/* 批价方式(T仅有清单批价规则,M清单规则及账务规则,D仅有账务优惠规则) */
	char    asMethod[BILLING_TYPE_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct BillingTypeStructIn{

#ifndef BILLING_TYPE_BUFLEN_IN
#define BILLING_TYPE_BUFLEN_IN		300
#endif

	struct BillingTypeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 套餐ID */
	char    asBillingTypeID[BILLING_TYPE_BUFLEN_IN][21];
		/* 套餐模板ID */
	char    asTemplateID[BILLING_TYPE_BUFLEN_IN][21];
		/* 套餐描述 */
	char    asRemark[BILLING_TYPE_BUFLEN_IN][61];
		/* 类型,'B'表示主产品套餐,'b'表示子产品套餐,'S'表示业务品牌,'v'表示 VPN编号 */
	char    asCatg[BILLING_TYPE_BUFLEN_IN][2];
		/* 业务品牌 */
	char    asServTypeID[BILLING_TYPE_BUFLEN_IN][21];
		/* 实现模式(子产品套餐才有值) */
	char    asImplPattern[BILLING_TYPE_BUFLEN_IN][5];
		/* 作用业务(子产品套餐才有值) */
	char    asAffectService[BILLING_TYPE_BUFLEN_IN][5];
		/* 批价方式(T仅有清单批价规则,M清单规则及账务规则,D仅有账务优惠规则) */
	char    asMethod[BILLING_TYPE_BUFLEN_IN][2];
};


/*单个结构申明*/
struct BillingTypeStruct{

	struct BillingTypeStruct *pNext;
	char    sBillingTypeID[21];		/* 套餐ID */
	char    sTemplateID[21];		/* 套餐模板ID */
	char    sRemark[61];		/* 套餐描述 */
	char    sCatg[2];		/* 类型,'B'表示主产品套餐,'b'表示子产品套餐,'S'表示业务品牌,'v'表示 VPN编号 */
	char    sServTypeID[21];		/* 业务品牌 */
	char    sImplPattern[5];		/* 实现模式(子产品套餐才有值) */
	char    sAffectService[5];		/* 作用业务(子产品套餐才有值) */
	char    sMethod[2];		/* 批价方式(T仅有清单批价规则,M清单规则及账务规则,D仅有账务优惠规则) */
	struct BillingTypeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FBillingTypeStruct{

	char    sBillingTypeID[20];		/* 套餐ID */
	char    sTemplateID[20];		/* 套餐模板ID */
	char    sRemark[60];		/* 套餐描述 */
	char    sCatg[1];		/* 类型,'B'表示主产品套餐,'b'表示子产品套餐,'S'表示业务品牌,'v'表示 VPN编号 */
	char    sServTypeID[20];		/* 业务品牌 */
	char    sImplPattern[4];		/* 实现模式(子产品套餐才有值) */
	char    sAffectService[4];		/* 作用业务(子产品套餐才有值) */
	char    sMethod[1];		/* 批价方式(T仅有清单批价规则,M清单规则及账务规则,D仅有账务优惠规则) */
};

/*批量数据动态从BILLING_TYPE中用结构缓冲方式取数据*/
int EGetBillingTypeToStruct(struct BillingTypeStruct *p,
	struct BillingTypeStructIn *pSource);
/**对表BILLING_TYPE的链表释放函数**/
void DestroyBillingType(struct BillingTypeStruct *ptHead);
int InitBillingType(struct BillingTypeStruct **pptHead);

/********************套餐相关性分析，这里为从新的统计表出用户统计数据*****************************/

/*输出结构缓冲申明*/
struct CrUserStatStructOut{

#ifndef CR_USER_STAT_BUFLEN_OUT
#define CR_USER_STAT_BUFLEN_OUT		300
#endif

	struct CrUserStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asAccNbr[CR_USER_STAT_BUFLEN_OUT][21];
		/* 用户归属区 */
	char    asHomeAreaCode[CR_USER_STAT_BUFLEN_OUT][6];
		/* 用户订购标识 */
	int    aiSubscriptionID[CR_USER_STAT_BUFLEN_OUT];
		/* 业务类型 */
	char     asServiceType[CR_USER_STAT_BUFLEN_OUT][5];
		/* 通话类型 */
	char    asCallType[CR_USER_STAT_BUFLEN_OUT][3];
		/* 基本业务码 */
	char    asServiceCode[CR_USER_STAT_BUFLEN_OUT][5];
		/* 本端用户类型 */
	int     aiHomePartyType[CR_USER_STAT_BUFLEN_OUT];
		/* 对端用户类型 */
	int     aiOtherPartyType[CR_USER_STAT_BUFLEN_OUT];
		/* 长途类型 */
	char    asTollType[CR_USER_STAT_BUFLEN_OUT][5];
		/* 漫游类型 */
	char    asRoamType[CR_USER_STAT_BUFLEN_OUT][5];
		/* 套餐ID/子产品ID/活动ID*/
	char    asBillingTypeID[CR_USER_STAT_BUFLEN_OUT][11];
		/* 计费单价编码ID*/
	int    aiDescriptionID[CR_USER_STAT_BUFLEN_OUT];
		/* 科目ID */
	int    aiSubjectID[CR_USER_STAT_BUFLEN_OUT];
		/* 话单数 */
	int    aiCdrCount[CR_USER_STAT_BUFLEN_OUT];
		/* 业务量 */
	int    aiCdrVolume[CR_USER_STAT_BUFLEN_OUT];
		/* 业务量单位 */
	int    asVolumeUnit[CR_USER_STAT_BUFLEN_OUT][2];
		/* 计费金额 */
	int    aiBillFee[CR_USER_STAT_BUFLEN_OUT];
		/* 账户ID */
	int     aiAccountID[CR_USER_STAT_BUFLEN_OUT];
	int     aiProductClass[CR_USER_STAT_BUFLEN_OUT];
	int     aiOtherPartyHead[CR_USER_STAT_BUFLEN_OUT];
	int     aiComponentID[CR_USER_STAT_BUFLEN_OUT];

};


/* 输入结构缓冲申明*/
struct CrUserStatStructIn{

#ifndef CR_USER_STAT_BUFLEN_IN
#define CR_USER_STAT_BUFLEN_IN		300
#endif

	struct CrUserStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asAccNbr[CR_USER_STAT_BUFLEN_IN][21];
		/* 用户归属区 */
	char    asHomeAreaCode[CR_USER_STAT_BUFLEN_IN][6];
		/* 用户订购标识 */
	int    aiSubscriptionID[CR_USER_STAT_BUFLEN_IN];
		/* 业务类型 */
	char     asServiceType[CR_USER_STAT_BUFLEN_IN][5];
		/* 通话类型 */
	char    asCallType[CR_USER_STAT_BUFLEN_IN][3];
		/* 基本业务码 */
	char    asServiceCode[CR_USER_STAT_BUFLEN_IN][5];
		/* 本端用户类型 */
	int     aiHomePartyType[CR_USER_STAT_BUFLEN_IN];
		/* 对端用户类型 */
	int     aiOtherPartyType[CR_USER_STAT_BUFLEN_IN];
		/* 长途类型 */
	char    asTollType[CR_USER_STAT_BUFLEN_IN][5];
		/* 漫游类型 */
	char    asRoamType[CR_USER_STAT_BUFLEN_IN][5];
		/* 套餐ID/子产品ID/活动ID*/
	char    asBillingTypeID[CR_USER_STAT_BUFLEN_IN][11];
		/* 计费单价编码ID*/
	int    aiDescriptionID[CR_USER_STAT_BUFLEN_IN];
		/* 科目ID */
	int    aiSubjectID[CR_USER_STAT_BUFLEN_IN];
		/* 话单数 */
	int    aiCdrCount[CR_USER_STAT_BUFLEN_IN];
		/* 业务量 */
	int    aiCdrVolume[CR_USER_STAT_BUFLEN_IN];
		/* 业务量单位 */
	char    asVolumeUnit[CR_USER_STAT_BUFLEN_IN][2];
		/* 计费金额 */
	int    aiBillFee[CR_USER_STAT_BUFLEN_IN];
		/* 账户ID */
	int     aiAccountID[CR_USER_STAT_BUFLEN_IN];
	int     aiProductClass[CR_USER_STAT_BUFLEN_IN];
	int     aiOtherPartyHead[CR_USER_STAT_BUFLEN_IN];
	int     aiComponentID[CR_USER_STAT_BUFLEN_IN];

};


/*单个结构申明*/
struct CrUserStatStruct{

	struct CrUserStatStruct *pNext;
	
	char    sAccNbr[21];		/* 用户号码 */
	char    sHomeAreaCode[6];		/* 用户归属区 */
	int     iSubscriptionID;		/* 用户订购标识 */
	char    sServiceType[5];		/* 业务类型 */
	char    sCallType[3];		/* 通话类型 */
	char    sServiceCode[5];		/* 基本业务码 */
	int     iHomePartyType;		/* 本端用户类型 */
	int     iOtherPartyType;		/* 对端用户类型 */
	char    sTollType[5];		/* 长途类型 */
	char    sRoamType[5];		/* 漫游类型 */
	char    sBillingTypeID[11];		/* 套餐ID/子产品ID/活动ID*/
	int     iDescriptionID;		/* 计费单价编码ID*/
	int     iSubjectID;		/* 科目ID */
	int     iCdrCount;		/* 话单数 */
	int     iCdrVolume;		/* 业务量 */
	char    sVolumeUnit[2];		/* 业务量单位 */
	int     iBillFee;		/* 计费金额 */
	int     iAccountID;		/* 账户ID */
	int     iProductClass;
	int     iOtherPartyHead;
	int     iComponentID;
	struct CrUserStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrUserStatStruct{

	char    sAccNbr[20];		/* 用户号码 */
	char    sHomeAreaCode[5];		/* 用户归属区 */
	char    sSubscriptionID[10];		/* 用户订购标识 */
	char    sServiceType[4];		/* 业务类型 */
	char    sCallType[2];		/* 通话类型 */
	char    sServiceCode[4];		/* 基本业务码 */
	char    sHomePartyType[4];		/* 本端用户类型 */
	char    sOtherPartyType[4];		/* 对端用户类型 */
	char    sTollType[4];		/* 长途类型 */
	char    sRoamType[4];		/* 漫游类型 */
	char    sBillingTypeID[10];		/* 套餐ID/子产品ID/活动ID*/
	char    sDescriptionID[10];		/* 计费单价编码ID*/
	char    sSubjectID[10];		/* 科目ID */
	char    sCdrCount[10];		/* 话单数 */
	char    sCdrVolume[10];		/* 业务量 */
	char    sVolumeUnit[1];		/* 业务量单位 */
	char    sBillFee[10];		/* 计费金额 */
	char    sAccountID[9];		/* 账户ID */
	char    sProductClass[9];
	char    sOtherPartyHead[9];
	char    sComponentID[9];
};

/*输出结构缓冲申明*/
struct CrAcctItemStatStructOut{

#ifndef CR_ACCT_ITEM_STAT_BUFLEN_OUT
#define CR_ACCT_ITEM_STAT_BUFLEN_OUT		300
#endif

	struct CrAcctItemStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 用户号码 */
	char    asAccNbr[CR_ACCT_ITEM_STAT_BUFLEN_OUT][21];
		/* 用户归属区号 */
	char    asAreaCode[CR_ACCT_ITEM_STAT_BUFLEN_OUT][6];
		/* 用户订购标识 */
	int     aiSubscriptionID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* 帐户ID */
	int     aiAccountID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* 业务类型 */
	int     aiServiceType[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* 套餐ID/子产品ID/活动ID */
	char    asBillingTypeID[CR_ACCT_ITEM_STAT_BUFLEN_OUT][11];
		/* 计费单价编码ID */
	int     aiDescriptionID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* 科目ID */
	int     aiSubjectID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* 计费金额 */
	int     aiBillFee[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* 优惠金额 */
	int     aiDisctFee[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct CrAcctItemStatStructIn{

#ifndef CR_ACCT_ITEM_STAT_BUFLEN_IN
#define CR_ACCT_ITEM_STAT_BUFLEN_IN		300
#endif

	struct CrAcctItemStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asAccNbr[CR_ACCT_ITEM_STAT_BUFLEN_IN][21];
		/* 用户归属区号 */
	char    asAreaCode[CR_ACCT_ITEM_STAT_BUFLEN_IN][6];
		/* 用户订购标识 */
	int     aiSubscriptionID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* 帐户ID */
	int     aiAccountID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* 业务类型 */
	int     aiServiceType[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* 套餐ID/子产品ID/活动ID */
	char    asBillingTypeID[CR_ACCT_ITEM_STAT_BUFLEN_IN][11];
		/* 计费单价编码ID */
	int     aiDescriptionID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* 科目ID */
	int     aiSubjectID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* 计费金额 */
	int     aiBillFee[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* 优惠金额 */
	int     aiDisctFee[CR_ACCT_ITEM_STAT_BUFLEN_IN];
};


/*单个结构申明*/
struct CrAcctItemStatStruct{

	struct CrAcctItemStatStruct *pNext;
	char    sAccNbr[21];		/* 用户号码 */
	char    sAreaCode[6];		/* 用户归属区号 */
	int	iSubscriptionID;		/* 用户订购标识 */
	int    	iAccountID;		/* 帐户ID */
	int     iServiceType;		/* 业务类型 */
	char    sBillingTypeID[11];		/* 套餐ID/子产品ID/活动ID */
	int    	iDescriptionID;		/* 计费单价编码ID */
	int    	iSubjectID;		/* 科目ID */
	int    	iBillFee;		/* 计费金额 */
	int    	iDisctFee;		/* 优惠金额 */
	
/*扩展需要*/
	int 	iAcctItemTypeID;	/* 账目ID */
	int	iTotalFee;		/* 账目被分摊费用 */
	char	sApportType[2];		/* 分摊类型 */
	int	iPriority;		/* 分摊优先级 */
	char	sServiceType[11];	/* 业务类型 */
	char	sSubServiceCode[11];	/* 子业务类型 */
	struct CrAcctItemStatStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCrAcctItemStatStruct{

	char    sAccNbr[20];		/* 用户号码 */
	char    sAreaCode[5];		/* 用户归属区号 */
	char    sSubscriptionID[10];		/* 用户订购标识 */
	char    sAccountID[10];		/* 帐户ID */
	char    sServiceType[4];		/* 业务类型 */
	char    sBillingTypeID[10];		/* 套餐ID/子产品ID/活动ID */
	char    sDescriptionID[10];		/* 计费单价编码ID */
	char    sSubjectID[10];		/* 科目ID */
	char    sBillFee[10];		/* 计费金额 */
	char    sDisctFee[10];		/* 优惠金额 */
};


/*批量数据动态从CR_ACCT_ITEM_STAT中用结构缓冲方式取数据*/
int EGetCrAcctItemStatToStruct(struct CrAcctItemStatStruct *p,
	struct CrAcctItemStatStructIn *pSource);
/**对表CR_ACCT_ITEM_STAT的链表释放函数**/
void DestroyCrAcctItemStat(struct CrAcctItemStatStruct *ptHead);
int InitCrAcctItemStat(struct CrAcctItemStatStruct **pptHead);



#endif
