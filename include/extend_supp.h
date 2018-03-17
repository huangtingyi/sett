#ifndef __EXTEND_SUPP_H__
#define __EXTEND_SUPP_H__

#include <hnixs.h>
#include <wwfile.h>
#include <list.h>
#include <trie.h>


/* ����ṹ��������*/
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


/*�����ṹ����*/
struct ExtendAttrDefRelationStruct{

	struct ExtendAttrDefRelationStruct *pNext;
	int     iExtendAttrID;
	char    sAttrKey[41];
	char    sMethod[3];
	char    sTypeValue[21];
	int     iPriority;
	struct ExtendAttrDefRelationStruct *pLoadNext;
};

/*�������ݶ�̬��EXTEND_ATTR_DEF_RELATION���ýṹ���巽ʽȡ����*/
int EGetExtendAttrDefRelationToStruct(struct ExtendAttrDefRelationStruct *p,
	struct ExtendAttrDefRelationStructIn *pSource);
/**�Ա�EXTEND_ATTR_DEF_RELATION�������ͷź���**/
void DestroyExtendAttrDefRelation(struct ExtendAttrDefRelationStruct *ptHead);
int InitExtendAttrDefRelation(struct ExtendAttrDefRelationStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��ʶ */
	char    asFlag[EXTEND_ATTR_BUFLEN_IN][2];
		/* ���ҷ��� */
	char    asSearchMethod[EXTEND_ATTR_BUFLEN_IN][21];
		/* ֵ��SQL */
	char    asValueSql[EXTEND_ATTR_BUFLEN_IN][201];

};


/*�����ṹ����*/
struct ExtendAttrStruct{

	struct ExtendAttrStruct *pNext;
	int     iExtendAttrID;
	int     iAttrID;
	int     iExtendSeq;
	char    sName[41];
	char    sRemark[401];
	char    sFlag[2];		/* ��ʶ */
	char    sSearchMethod[21];		/* ���ҷ��� */
	char    sValueSql[201];		/* ֵ��SQL */

	struct ExtendAttrStruct *pLoadNext;
};

/*�������ݶ�̬��EXTEND_ATTR���ýṹ���巽ʽȡ����*/
int EGetExtendAttrToStruct(struct ExtendAttrStruct *p,
	struct ExtendAttrStructIn *pSource);
/**�Ա�EXTEND_ATTR�������ͷź���**/
void DestroyExtendAttr(struct ExtendAttrStruct *ptHead);
int InitExtendAttr(struct ExtendAttrStruct **pptHead);

/* ����ṹ��������*/
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


/*�����ṹ����*/
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



/*�������ݶ�̬��EXTEND_ATTR_VALUE���ýṹ���巽ʽȡ����*/
int EGetExtendAttrValueToStruct(struct ExtendAttrValueStruct *p,
	struct ExtendAttrValueStructIn *pSource);
/**�Ա�EXTEND_ATTR_VALUE�������ͷź���**/
void DestroyExtendAttrValue(struct ExtendAttrValueStruct *ptHead);
int InitExtendAttrValue(struct ExtendAttrValueStruct **pptHead);

/* ����ṹ��������*/
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


/*�����ṹ����*/
struct AttrStruct{

	struct AttrStruct *pNext;
	int     iAttrID;
	char    sName[41];
	char    sGrade[2];
	char    sValueType[2];
	char    sValueSql[201];
	char	sStdCode[9];
	
	int	iFlag;	/*���ر�ʶ,��ö��ֵʱ��Ч,0,δ��������,1�Ѽ�������*/
	TRIE	*pTrie; /*value,name�ļ���*/
	struct AttrStruct *pLoadNext;
};

/*�������ݶ�̬��ATTR���ýṹ���巽ʽȡ����*/
int EGetAttrToStruct(struct AttrStruct *p,struct AttrStructIn *pSource);
/**�Ա�ATTR�������ͷź���**/
void DestroyAttr(struct AttrStruct *ptHead);
int InitAttr(struct AttrStruct **pptHead);

/* ����ṹ��������*/
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
		/* ������ʽ��ʶ */
	int     aiFormatID[TABLE_FORMAT_BUFLEN_IN];
		/* ���� */
	char    asRemark[TABLE_FORMAT_BUFLEN_IN][41];
		/* ģ���ʶ */
	int     aiTemplateID[TABLE_FORMAT_BUFLEN_IN];
};


/*�����ṹ����*/
struct TableFormatStruct{

	struct TableFormatStruct *pNext;
	int     iFormatID;		/* ������ʽ��ʶ */
	char    sRemark[41];		/* ���� */
	int     iTemplateID;		/* ģ���ʶ */
	struct TableFormatStruct *pLoadNext;
};


/*�������ݶ�̬��TABLE_FORMAT���ýṹ���巽ʽȡ����*/
int EGetTableFormatToStruct(struct TableFormatStruct *p,
	struct TableFormatStructIn *pSource);
/**�Ա�TABLE_FORMAT�������ͷź���**/
void DestroyTableFormat(struct TableFormatStruct *ptHead);
int InitTableFormat(struct TableFormatStruct **pptHead);

/* ����ṹ��������*/
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


/*�����ṹ����*/
struct TabTemplateStruct{

	struct TabTemplateStruct *pNext;
	int     iTemplateID;
	int     iFormatID;
	char    sTemplateName[31];
	char    sTemplateRemark[61];
	struct TabTemplateStruct *pLoadNext;
};


/*�������ݶ�̬��TAB_TEMPLATE���ýṹ���巽ʽȡ����*/
int EGetTabTemplateToStruct(struct TabTemplateStruct *p,
	struct TabTemplateStructIn *pSource);
/**�Ա�TAB_TEMPLATE�������ͷź���**/
void DestroyTabTemplate(struct TabTemplateStruct *ptHead);
int InitTabTemplate(struct TabTemplateStruct **pptHead);

/* ����ṹ��������*/
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
		/* �ֶα�ʶ */
	int     aiColumnID[TAB_COLUMNS_BUFLEN_IN];
		/* ģ����ʶ */
	int     aiTemplateID[TAB_COLUMNS_BUFLEN_IN];
		/* �ֶ����� */
	char    asColumnName[TAB_COLUMNS_BUFLEN_IN][41];
		/* �������� */
	char    asDataType[TAB_COLUMNS_BUFLEN_IN][31];
		/* �ֶγ��� */
	int     aiLen[TAB_COLUMNS_BUFLEN_IN];
		/* �ֶ�˵�� */
	char    asColumnRemark[TAB_COLUMNS_BUFLEN_IN][61];
		/* �ֶξ��� */
	int     aiScale[TAB_COLUMNS_BUFLEN_IN];
		/* �ܷ�Ϊ�� */
	char    asNullable[TAB_COLUMNS_BUFLEN_IN][2];
		/* �ֶ���� */
	int     aiColumnSeq[TAB_COLUMNS_BUFLEN_IN];
	
};


/*�����ṹ����*/
struct TabColumnsStruct{

	struct TabColumnsStruct *pNext;
	int     iColumnID;		/* �ֶα�ʶ */
	int     iTemplateID;		/* ģ����ʶ */
	char    sColumnName[41];		/* �ֶ����� */
	char    sDataType[31];		/* �������� */
	int     iLen;		/* �ֶγ��� */
	char    sColumnRemark[61];		/* �ֶ�˵�� */
	int     iScale;		/* �ֶξ��� */
	char    sNullable[2];		/* �ܷ�Ϊ�� */
	int     iColumnSeq;		/* �ֶ���� */
	
	/*�������ӵ�*/
	int     iOffset;        /*�����ͷ�ֶε�ƫ��*/
        int     iSeq;           /*��ʾ��N���ֶ�*/
        int	iPos;		/*��ŵ����ֶ���TFIELD��ƫ����*/
        int	iState;		/*1Ϊ���ֶα�����ģ��ʹ�õ���0Ϊδʹ��*/
        
        struct TabColumnsStruct *pHead;/*ԭʼ�ֶ�*/
        
	struct TabColumnsStruct *pLoadNext;
};


/*�������ݶ�̬��TAB_COLUMNS���ýṹ���巽ʽȡ����*/
int EGetTabColumnsToStruct(struct TabColumnsStruct *p,
	struct TabColumnsStructIn *pSource);
/**�Ա�TAB_COLUMNS�������ͷź���**/
void DestroyTabColumns(struct TabColumnsStruct *ptHead);
int InitTabColumns(struct TabColumnsStruct **pptHead);

/* ����ṹ��������*/
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
		/* ģ����ʶ */
	int     aiTemplateID[TAB_TEMPLATE_REAL_BUFLEN_IN];
		/* ʵ�ʱ����� */
	char    asRealName[TAB_TEMPLATE_REAL_BUFLEN_IN][60];
		/* ʵ�ʱ�˵�� */
	char    asRealRemark[TAB_TEMPLATE_REAL_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct TabTemplateRealStruct{

	struct TabTemplateRealStruct *pNext;
	int     iTemplateID;		/* ģ����ʶ */
	char    sRealName[60];		/* ʵ�ʱ����� */
	char    sRealRemark[41];		/* ʵ�ʱ�˵�� */
	struct TabTemplateRealStruct *pLoadNext;
};

/*�������ݶ�̬��TAB_TEMPLATE_REAL���ýṹ���巽ʽȡ����*/
int EGetTabTemplateRealToStruct(struct TabTemplateRealStruct *p,
	struct TabTemplateRealStructIn *pSource);
/**�Ա�TAB_TEMPLATE_REAL�������ͷź���**/
void DestroyTabTemplateReal(struct TabTemplateRealStruct *ptHead);
int InitTabTemplateReal(struct TabTemplateRealStruct **pptHead);

/* ����ṹ��������*/
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
		/* Ҫ��ID */
	int     aiPromiseElementID[PROMISE_ELEMENT_BUFLEN_IN];
		/*����ŵҪ��ID*/
	int	aiPrimaryElementID[PROMISE_ELEMENT_BUFLEN_IN];
		/* �������� */
	char    asServiceType[PROMISE_ELEMENT_BUFLEN_IN][5];
		/* '0' ��ʶ��������û��ĳ�ŵ��'1'��ʶ����ض��û��ĳ�ŵ */
	char    asAffectType[PROMISE_ELEMENT_BUFLEN_IN][2];
		/* ��ŵ���� */
	char    asPromiseType[PROMISE_ELEMENT_BUFLEN_IN][2];
		/* ����ҵ������ */
	char    asName[PROMISE_ELEMENT_BUFLEN_IN][41];
		/* Ҫ��ȫ�� */
	char    asStdName[PROMISE_ELEMENT_BUFLEN_IN][81];
		/* Ҫ������ */
	char    asRemark[PROMISE_ELEMENT_BUFLEN_IN][401];
		/* ���ʵ�λ��Ĭ�ϣ� */
	char    asRateUnit[PROMISE_ELEMENT_BUFLEN_IN][2];
		/* չʾ��� */
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

/*�����ṹ����*/
struct PromiseElementStruct{

	struct PromiseElementStruct *pNext;
	int     iPromiseElementID;		/* Ҫ��ID */
	int	iPrimaryElementID;		/*����ŵҪ��ID*/
	char    sServiceType[5];		/* �������� */
	char    sAffectType[2];		/* '0' ��ʶ��������û��ĳ�ŵ��'1'��ʶ����ض��û��ĳ�ŵ */
	char    sPromiseType[2];		/* ��ŵ���� */
	char    sName[41];		/* ����ҵ������ */
	char    sStdName[81];		/* Ҫ��ȫ�� */
	char    sRemark[401];		/* Ҫ������ */
	char    sRateUnit[2];		/* ���ʵ�λ��Ĭ�ϣ� */
	int     iDisplaySeq;		/* չʾ��� */
	
/*
V ����		��ע
1 ȫ������	ȫ���������ȣ����з�������������;
2 ȫ�ѽ���	ȫ���ý����ȣ�����ȫ���������ȣ����з�������������;
3 ����		���õķ������������ȣ�
4 ����		���õķ��ó��������ȣ������ԱȽ����ȣ�
5 ��ͨ		���õķ��ʳ���0-3���𣬰����ʵ�Ϊԭ��;
6 ������	���õķ������ȼ����.*/
	
	int	iPriority;
/*
V �ײ����ȼ�
1 ���ײͼ�
2 ���ײͼ�
3 ҵ��Ʒ�Ƽ�
4 ͨ���ʷѼ�
5 ����س�ŵҪ��
*/
	int	iBillGrade;
	
	struct PromiseElementStruct *pLoadNext;
};


/*�������ݶ�̬��PROMISE_ELEMENT���ýṹ���巽ʽȡ����*/
int EGetPromiseElementToStruct(struct PromiseElementStruct *p,
	struct PromiseElementStructIn *pSource);
/**�Ա�PROMISE_ELEMENT�������ͷź���**/
void DestroyPromiseElement(struct PromiseElementStruct *ptHead);
int InitPromiseElement(struct PromiseElementStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��ŵ���ʱ�ʶ */
	int     aiTariffID[PROMISE_TARIFF_BUFLEN_IN];
		/* Ҫ��ID */
	int     aiPromiseElementID[PROMISE_TARIFF_BUFLEN_IN];
		/* �����ֶ�ID */
	int     aiMeasureSpanID[PROMISE_TARIFF_BUFLEN_IN];
		/* �Ʒ�ʱ����ID */
	int     aiTimeSpanGrpID[PROMISE_TARIFF_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[PROMISE_TARIFF_BUFLEN_IN][21];
		/* T ��ʾ��������ŵ,A ��ʾ�˵�����ŵ */
	char    asPromiseType[PROMISE_TARIFF_BUFLEN_IN][2];
		/* չʾ��� */
	int     aiDisplaySeq[PROMISE_TARIFF_BUFLEN_IN];
		/* ���AREA_CODEΪ"*"��ʾ��ȫʡ */
	char    asAreaCode[PROMISE_TARIFF_BUFLEN_IN][10];
		/* ����(Ԫ��) */
	double  adRate[PROMISE_TARIFF_BUFLEN_IN];
		/* ���ʵ�λ */
	char    asRateUnit[PROMISE_TARIFF_BUFLEN_IN][2];
		/* 'A0A' ���ã���A0X'ע����'A0H'��ʷ */
	char	asRateMethod[PROMISE_TARIFF_BUFLEN_IN][2];
	
	int	aiRateID[PROMISE_TARIFF_BUFLEN_IN];
	
	char    asState[PROMISE_TARIFF_BUFLEN_IN][4];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[PROMISE_TARIFF_BUFLEN_IN];
		/* ͨ���������ͱ�ʶ */
	int     aiCallAreaTypeID[PROMISE_TARIFF_BUFLEN_IN];
};


/*�����ṹ����*/
struct PromiseTariffStruct{

	struct PromiseTariffStruct *pNext;
	int     iTariffID;		/* ��ŵ���ʱ�ʶ */
	int     iPromiseElementID;		/* Ҫ��ID */
	int     iMeasureSpanID;		/* �����ֶ�ID */
	int     iTimeSpanGrpID;		/* �Ʒ�ʱ����ID */
	char    sBillingTypeID[21];		/* �ײ�ID */
	char    sPromiseType[2];		/* T ��ʾ��������ŵ,A ��ʾ�˵�����ŵ */
	int     iDisplaySeq;		/* չʾ��� */
	char    sAreaCode[10];		/* ���AREA_CODEΪ"*"��ʾ��ȫʡ */
	double  dRate;			/* ����(Ԫ��) */
	char    sRateUnit[2];		/* ���ʵ�λ */
	char	sRateMethod[2];		
/* ����Ӧ�÷���'R'ֱ��ȡRATEֵ,'P'��ʾPARAM_CODE_DESC.PARAM_ID,
	'E'��ʾPARAM_EXPR_DESC.EXPR_ID */
	int	iRateID;		/* ���ʲ������� */
	char    sState[4];		/* 'A0A' ���ã���A0X'ע����'A0H'��ʷ */
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	int     iCallAreaTypeID;		/* ͨ���������ͱ�ʶ */
	struct PromiseTariffStruct *pLoadNext;
	
	int	iMeasureSpanTypeID;
	int	iTimeSpanTypeID;

	struct MeasureSpanStruct *pMeasureSpan;
	struct TimeSpanGrpStruct *pTimeSpanGrp;

	int	iRateUnit;
	double  dAdjustRate;			/* ���������(Ԫ��) */
	int	iPriority;			/*ȡ���ȼ�*/
	int	iElementPriority;		/*Ҫ�����ȼ�*/
	int	iBillGrade;			/*�ײ����ȼ�*/
	char	sEffectType[2];			/*��������*/

	struct PromiseTariffStruct *pTariff;
};

/*�������ݶ�̬��PROMISE_TARIFF���ýṹ���巽ʽȡ����*/
int EGetPromiseTariffToStruct(struct PromiseTariffStruct *p,
	struct PromiseTariffStructIn *pSource);
/**�Ա�PROMISE_TARIFF�������ͷź���**/
void DestroyPromiseTariff(struct PromiseTariffStruct *ptHead);
int InitPromiseTariff(struct PromiseTariffStruct **pptHead);

/* ����ṹ��������*/
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
		/* ������ֶα�ʶ��Լ�� */
	int     aiMeasureFieldID[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* ������ֶα�ʶ��Լ�� */
	int     aiFeeFieldID[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* �����ֶ����к� */
	int	aiFeeFieldIDSeq[MEASURE_FIELD_FEE_BUFLEN_IN];
		/* ������ʽ��ʶ */
	int	aiFormatID[MEASURE_FIELD_FEE_BUFLEN_IN];
};


/*�����ṹ����*/
struct MeasureFieldFeeStruct{

	struct MeasureFieldFeeStruct *pNext;
	int     iMeasureFieldID;		/* ������ֶα�ʶ��Լ�� */
	int     iFeeFieldID;			/* ������ֶα�ʶ��Լ�� */
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	int	iFeeFieldIDSeq;		/* �����ֶ����к� */
	int	iFormatID;		/* ������ʽ��ʶ */
	struct MeasureFieldFeeStruct *pLoadNext;
};

/*�������ݶ�̬��MEASURE_FIELD_FEE���ýṹ���巽ʽȡ����*/
int EGetMeasureFieldFeeToStruct(struct MeasureFieldFeeStruct *p,
	struct MeasureFieldFeeStructIn *pSource);
/**�Ա�MEASURE_FIELD_FEE�������ͷź���**/
void DestroyMeasureFieldFee(struct MeasureFieldFeeStruct *ptHead);
int InitMeasureFieldFee(struct MeasureFieldFeeStruct **pptHead);



/* ����ṹ��������*/
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
		/* �����ֶ�ID */
	int     aiMeasureSpanID[MEASURE_SPAN_BUFLEN_IN];
		/* �ֶ����ͱ�ʶ */
	int     aiMeasureSpanTypeID[MEASURE_SPAN_BUFLEN_IN];
		/* �ֶ���ʼ�� */
	int     aiBeginCnt[MEASURE_SPAN_BUFLEN_IN];
		/* �ֶ���ֹ�� */
	int     aiEndCnt[MEASURE_SPAN_BUFLEN_IN];
		/* �ֶ����� */
	char    asName[MEASURE_SPAN_BUFLEN_IN][41];
		/* �������� */
	char    asServiceType[MEASURE_SPAN_BUFLEN_IN][5];
		/* T ������¼��ʹ��,A��ͳ�ƻ�����Ϣ�ֶ� */
	char    asUseType[MEASURE_SPAN_BUFLEN_IN][2];
	char	asRateUnit[MEASURE_SPAN_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct MeasureSpanStruct{

	struct MeasureSpanStruct *pNext;
	int     iMeasureSpanID;		/* �����ֶ�ID */
	int     iMeasureSpanTypeID;		/* �ֶ����ͱ�ʶ */
	int     iBeginCnt;		/* �ֶ���ʼ�� */
	int     iEndCnt;		/* �ֶ���ֹ�� */
	char    sName[41];		/* �ֶ����� */
	char    sServiceType[5];		/* �������� */
	char    sUseType[2];		/* T ������¼��ʹ��,A��ͳ�ƻ�����Ϣ�ֶ� */
	char	sRateUnit[2];		/*��λ*/
	int	iBeginValue;
	int 	iEndValue;
	struct MeasureSpanStruct *pLoadNext;
};
/*�������ݶ�̬��MEASURE_SPAN���ýṹ���巽ʽȡ����*/
int EGetMeasureSpanToStruct(struct MeasureSpanStruct *p,
	struct MeasureSpanStructIn *pSource);
/**�Ա�MEASURE_SPAN�������ͷź���**/
void DestroyMeasureSpan(struct MeasureSpanStruct *ptHead);
int InitMeasureSpan(struct MeasureSpanStruct **pptHead);



/* ����ṹ��������*/
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
		/* �Ʒ�ʱ����ID */
	int     aiTimeSpanGrpID[TIME_SPAN_GRP_BUFLEN_IN];
		/* ʱ�����ͱ�ʶ */
	int     aiTimeSpanTypeID[TIME_SPAN_GRP_BUFLEN_IN];
		/*ʱ��������ʶ*/
	char	asConditionType[TIME_SPAN_GRP_BUFLEN_IN][2];
		/* ���� */
	char    asName[TIME_SPAN_GRP_BUFLEN_IN][41];
	
	int     aiTimeSpanID[TIME_SPAN_GRP_BUFLEN_IN];
	char    asBeginTime[TIME_SPAN_GRP_BUFLEN_IN][7];
	char    asEndTime[TIME_SPAN_GRP_BUFLEN_IN][7];
	char    asDateType[TIME_SPAN_GRP_BUFLEN_IN][2];
	char	asBeginFlag[TIME_SPAN_GRP_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct TimeSpanGrpStruct{

	struct TimeSpanGrpStruct *pNext;
	int     iTimeSpanGrpID;		/* �Ʒ�ʱ����ID */
	int     iTimeSpanTypeID;		/* ʱ�����ͱ�ʶ */
	char	sConditionType[2];	
/*ʱ��������ʶ��'A' ������,'B' ֻ�����ײ��и�ʱ��ʱ���ײͲ���Ч*/
	char    sName[41];		/* ���� */

	int	iTimeSpanID;
	char	sBeginTime[7];
	char	sEndTime[7];
/*W :�������ڣ�H:�����ڼ���,A:��������*/
	char	sDateType[2];
	char	sBeginFlag[2];

	int	iBeginTime;	/*��ÿ����ʱ������*/
	int	iEndTime;	/*��ÿ����ʱ������*/

	struct TimeSpanGrpStruct *pLoadNext;
};
/*�������ݶ�̬��TIME_SPAN_GRP���ýṹ���巽ʽȡ����*/
int EGetTimeSpanGrpToStruct(struct TimeSpanGrpStruct *p,
	struct TimeSpanGrpStructIn *pSource);
/**�Ա�TIME_SPAN_GRP�������ͷź���**/
void DestroyTimeSpanGrp(struct TimeSpanGrpStruct *ptHead);
int InitTimeSpanGrp(struct TimeSpanGrpStruct **pptHead);

/* ����ṹ��������*/
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
	char	sValue[32];	/*����ֵ*/
	char	sName[32];	/*����ֵ����*/
	int	iValueLen;
	struct ValueNameStruct *pLoadNext;
};
int EGetValueNameToStruct(struct ValueNameStruct *p,
	struct ValueNameStructIn *pSource);
TRIE *GetValueNameTrie(char sMicro[],char sSql[]);

int GetFormatIDByTemplateRuleID(int iTemplateRuleID);
int GetTemplateIDByFormatID(int iFormatID);


/* ����ṹ��������*/
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
/* ���� */
	char    asDates[HOLIDAY_BUFLEN_IN][15];
	char    asType[HOLIDAY_BUFLEN_IN][13];
	char    asRemark[HOLIDAY_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct HolidayStruct{

	struct HolidayStruct *pNext;
	char	sDates[15];
	char	sType[13];
	char	sRemark[41];
	
	char	cDateType;
	time_t tDates;

	struct HolidayStruct *pLoadNext;
};

/*�������ݶ�̬��TIME_SPAN_GRP���ýṹ���巽ʽȡ����*/
int EGetHolidayToStruct(struct HolidayStruct *p,
	struct HolidayStructIn *pSource);
/**�Ա�TIME_SPAN_GRP�������ͷź���**/
void DestroyHoliday(struct HolidayStruct *ptHead);
int InitHoliday(struct HolidayStruct **pptHead);


/*����ṹ��������*/
struct AcctItemStructOut{

#ifndef ACCT_ITEM_BUFLEN_OUT
#define ACCT_ITEM_BUFLEN_OUT		300
#endif

	struct AcctItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ŀ��ˮ */
	char    asAcctItemID[ACCT_ITEM_BUFLEN_OUT][13];
		/* �������� */
	char    asAccNbr[ACCT_ITEM_BUFLEN_OUT][21];
		/* ��Ŀ��� */
	int     aiAcctItemTypeID[ACCT_ITEM_BUFLEN_OUT];
		/* ���� */
	int     aiCharge[ACCT_ITEM_BUFLEN_OUT];
		/* �������� */
	char    asAreaCode[ACCT_ITEM_BUFLEN_OUT][10];
		/* ����״̬ */
	char    asState[ACCT_ITEM_BUFLEN_OUT][2];
		/* �������� */
	int     aiBillingCycleID[ACCT_ITEM_BUFLEN_OUT];
		/* ��Ŀ�������� */
	char    asAcctItemDate[ACCT_ITEM_BUFLEN_OUT][15];
		/* ��Ŀ��� */
	char	asAcctType[ACCT_ITEM_BUFLEN_OUT][2];
		/* ������ĿID */
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


/* ����ṹ��������*/
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
		/* ��Ŀ��ˮ */
	char    asAcctItemID[ACCT_ITEM_BUFLEN_IN][13];
		/* �������� */
	char    asAccNbr[ACCT_ITEM_BUFLEN_IN][21];
		/* ��Ŀ��� */
	int     aiAcctItemTypeID[ACCT_ITEM_BUFLEN_IN];
		/* ���� ,��λΪ��*/
	int     aiCharge[ACCT_ITEM_BUFLEN_IN];
		/* �������� */
	char    asAreaCode[ACCT_ITEM_BUFLEN_IN][10];
		/* ��Ŀ״̬,'0'������Ŀ,'1'�Ż���Ŀ,1ʱ��chargeΪ��*/
	char    asState[ACCT_ITEM_BUFLEN_IN][2];
		/* �������� */
	int     aiBillingCycleID[ACCT_ITEM_BUFLEN_IN];
		/* ��Ŀ�������� */
	char    asAcctItemDate[ACCT_ITEM_BUFLEN_IN][15];
		/* ������ĿID */
	int	aiAuditItemTypeID[ACCT_ITEM_BUFLEN_IN];
		/* ��Ŀ��� */
	char	asAcctType[ACCT_ITEM_BUFLEN_IN][2];
		/* ��ĿID */
	int	aiAcctID[ACCT_ITEM_BUFLEN_IN];
	int	aiDefaultAcctID[ACCT_ITEM_BUFLEN_IN];
	
	
};
/* ����ṹ��������*/
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
		/* ��Ŀ��ˮ */
	char    asAcctItemID[ACCT_ITEM_ALL_BUFLEN_IN][13];
		/* �������� */
	char    asAccNbr[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* ��Ŀ��� */
	int     aiAcctItemTypeID[ACCT_ITEM_ALL_BUFLEN_IN];
		/* ���� */
	int    aiCharge[ACCT_ITEM_ALL_BUFLEN_IN];
		/* �������� */
	char    asAreaCode[ACCT_ITEM_ALL_BUFLEN_IN][10];
		/* ����״̬ */
	char    asState[ACCT_ITEM_ALL_BUFLEN_IN][2];
		/* �������� */
	int     aiBillingCycleID[ACCT_ITEM_ALL_BUFLEN_IN];
		/* ��Ŀ�������� */
	char    asAcctItemDate[ACCT_ITEM_ALL_BUFLEN_IN][15];
		/* ������ĿID */
	int     aiAuditItemTypeID[ACCT_ITEM_ALL_BUFLEN_IN];
		/* 'P' ���з��������һ��; 'F' ���з�����ˣ����ڲ�һ��;'X' ���ڷ���δ��˵��ֶ�. */
	char    asAuditState[ACCT_ITEM_ALL_BUFLEN_IN][2];
		/* ÿһ���ַ�����Ӧһ�����������Ϣ.'E' �����ȫһ��'L' ��˷��ñ�ԭ������'G' ��˷��ñ�ԭ���ø�'N' δ������˹���,���ֶ�δ��˵�. */
	char    asAuditDetailState[ACCT_ITEM_ALL_BUFLEN_IN][6];
		/* �������� */
	char    asAuditDate[ACCT_ITEM_ALL_BUFLEN_IN][15];
		/* ��λΪ�壬��ʾ���˽���ܷ��ã�ԭϵͳ���ɷ��� */
	int    aiAuditDiffFee[ACCT_ITEM_ALL_BUFLEN_IN];
		/* ���˽�����������Ϣ */
	char    asAuditInfo[ACCT_ITEM_ALL_BUFLEN_IN][161];
		/* ԭʼ��Ŀ��ˮ��Ӧ�Ʒ��ʻ�������ϸ�ı�� */
	char    asOriAcctItemID[ACCT_ITEM_ALL_BUFLEN_IN][16];
		/* ���˺����ײ����� */
	char    asAuditBillingTypeID[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* ���˺�������� */
	char    asAuditAreaCode[ACCT_ITEM_ALL_BUFLEN_IN][6];
		/* �����ʷ�һID */
	int     aiAuditTariffId1[ACCT_ITEM_ALL_BUFLEN_IN];
		/* �����ʷѶ�ID */
	int     aiAuditTariffId2[ACCT_ITEM_ALL_BUFLEN_IN];
		/* �����ʷ���ID */
	int     aiAuditTariffId3[ACCT_ITEM_ALL_BUFLEN_IN];
		/* ���˷���һ */
	int    aiAuditFee1[ACCT_ITEM_ALL_BUFLEN_IN];
		/* ���˷��ö� */
	int    aiAuditFee2[ACCT_ITEM_ALL_BUFLEN_IN];
		/* ���˷����� */
	int    aiAuditFee3[ACCT_ITEM_ALL_BUFLEN_IN];
		/* �Է�����һ */
	int    aiAuditOriFee1[ACCT_ITEM_ALL_BUFLEN_IN];
		/* �Է����ö� */
	int    aiAuditOriFee2[ACCT_ITEM_ALL_BUFLEN_IN];
		/* �Է������� */
	int    aiAuditOriFee3[ACCT_ITEM_ALL_BUFLEN_IN];
		/* �����ײ�һ */
	char    asAuditType1[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* �����ײͶ� */
	char    asAuditType2[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* �����ײ��� */
	char    asAuditType3[ACCT_ITEM_ALL_BUFLEN_IN][21];
		/* �˵����ͣ�AΪ�����Żݣ�TΪ�嵥����Ŀ��MΪ�������Ŀ */
	char    asAcctType[ACCT_ITEM_ALL_BUFLEN_IN][2];
		/* ��ĿID */
	int     aiAcctID[ACCT_ITEM_ALL_BUFLEN_IN];
	int     aiDefaultAcctID[ACCT_ITEM_ALL_BUFLEN_IN];

};

/*�����ṹ����*/
struct AcctItemStruct
{
	struct AcctItemStruct *pNext;
		
	char    sAcctItemID[13];		/* ��Ŀ��ˮ */
	char    sAccNbr[21];		/* �������� */
	int     iAcctItemTypeID;		/* ��Ŀ��� */
	int     iCharge;		/* ���� */
	char    sAreaCode[10];		/* �������� */
	char    sState[2];		/* ��Ŀ״̬,'0'������Ŀ,'1'�Ż���Ŀ,1ʱ��chargeΪ��*/
	int     iBillingCycleID;		/* �������� */
	char    sAcctItemDate[15];		/* ��Ŀ�������� */
	int	iAuditItemTypeID;			/* ������ĿID */
	char	sAcctType[2];		/* ��Ŀ��� */
	int	iAcctID;		/* ��ĿID */
	int	iDefaultAcctID;		/* ��ĿID */
	
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

/*�������ݶ�̬��ACCT_ITEM���ýṹ���巽ʽȡ����*/
int EGetAcctItemToStruct(struct AcctItemStruct *p,
	struct AcctItemStructIn *pSource);
/*�������ݶ�̬��ACCT_ITEM���ýṹ���巽ʽȡ����*/
int EGetAcctItemAllFieldToStruct(struct AcctItemStruct *p,
	struct AcctItemAllFieldStructIn *pSource);
/*�������ݽṹ����д��ACCT_ITEM*/
int EInsertStructToAcctItem(struct AcctItemStruct *p,
	int iInsertFlag,struct AcctItemStructOut *pTarget);

/* ����ṹ��������*/
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
		/* ҵ������ */
	char    asServiceType[AUDIT_PARAM_BUFLEN_IN][5];
		/* 'D'��ÿ�ջ���,'P' Ԥ���˻���,'A' �˺���� */
	char    asAuditType[AUDIT_PARAM_BUFLEN_IN][2];
	int     aiSeq[AUDIT_PARAM_BUFLEN_IN];
		/* �����е� @MM@��ʾ�·�,@DD@��ʾ����,@YYYY@��@YY@��ʾ��� */
	char    asAuditTableName[AUDIT_PARAM_BUFLEN_IN][41];
		/* 'A'�����˵���,'T'���˻����� */
	char    asTableType[AUDIT_PARAM_BUFLEN_IN][2];
		/* ����ģ���ʶ */
	int     aiTemplateRuleID[AUDIT_PARAM_BUFLEN_IN];
		/* �޷�����������ֶ�Ϊ�� */
	char    asPartSplitType[AUDIT_PARAM_BUFLEN_IN][2];
		/* ��ģ������ */
	int     aiTemplateID[AUDIT_PARAM_BUFLEN_IN];
		/* ������ʽ���� */
	int     aiFormatID[AUDIT_PARAM_BUFLEN_IN];
		/* ״̬��0��ʾ����״̬��1��ʾע��״̬*/
	char	asState[AUDIT_PARAM_BUFLEN_IN][2];
		/* ����Է����ķ���ģ�� */
	int	aiCrRuleID[AUDIT_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct AuditParamStruct{

	struct AuditParamStruct *pNext;
	char    sServiceType[5];	/* ҵ������ */
	char    sAuditType[2];		/* 'D'��ÿ�ջ���,'P' Ԥ���˻���,'A' �˺���� */
	int	iSeq;
	char    sAuditTableName[41];	/* �����е� @MM@��ʾ�·�,@DD@��ʾ����,@YYYY@��@YY@��ʾ��� */
	char    sTableType[2];		/* 'A'�����˵���,'T'���˻����� */
	int     iTemplateRuleID;	/* ����ģ���ʶ */
	char    sPartSplitType[2];	/* �޷�����������ֶ�Ϊ�� */
	int     iTemplateID;		/* ��ģ������ */
	int     iFormatID;		/* ������ʽ���� */
	char	sState[2];		/* ״̬��0��ʾ����״̬��1��ʾע��״̬*/
	int	iCrRuleID;		/* ����Է����ķ���ģ�� */
	struct AuditParamStruct *pLoadNext;
};

/*�������ݶ�̬��AUDIT_PARAM���ýṹ���巽ʽȡ����*/
int EGetAuditParamToStruct(struct AuditParamStruct *p,
	struct AuditParamStructIn *pSource);
/**�Ա�AUDIT_PARAM�������ͷź���**/
void DestroyAuditParam(struct AuditParamStruct *ptHead);
int InitAuditParam(struct AuditParamStruct **pptHead,char sAuditType[]);

/* ����ṹ��������*/
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
		/* ������ĿID */
	int     aiAuditItemTypeID[AUDIT_ITEM_TYPE_BUFLEN_IN];
		/* ��Ŀ���� */
	char    asName[AUDIT_ITEM_TYPE_BUFLEN_IN][129];
};


/*�����ṹ����*/
struct AuditItemTypeStruct{

	struct AuditItemTypeStruct *pNext;
	int     iAuditItemTypeID;		/* ������ĿID */
	char    sName[129];		/* ��Ŀ���� */
	struct AuditItemTypeStruct *pLoadNext;
};
/*�������ݶ�̬��AUDIT_ITEM_TYPE���ýṹ���巽ʽȡ����*/
int EGetAuditItemTypeToStruct(struct AuditItemTypeStruct *p,
	struct AuditItemTypeStructIn *pSource);
/**�Ա�AUDIT_ITEM_TYPE�������ͷź���**/
void DestroyAuditItemType(struct AuditItemTypeStruct *ptHead);
int InitAuditItemType(struct AuditItemTypeStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��׼��ĿID */
	int     aiAcctItemTypeID[AUDIT_ITEM_RELATION_BUFLEN_IN];
		/* ������Ŀ��ϵ */
	int     aiAuditItemTypeID[AUDIT_ITEM_RELATION_BUFLEN_IN];
};


/*�����ṹ����*/
struct AuditItemRelationStruct{

	struct AuditItemRelationStruct *pNext;
	int     iAcctItemTypeID;		/* ��׼��ĿID */
	int     iAuditItemTypeID;		/* ������Ŀ��ϵ */
	struct AuditItemRelationStruct *pLoadNext;
};

/*�������ݶ�̬��AUDIT_ITEM_RELATION���ýṹ���巽ʽȡ����*/
int EGetAuditItemRelationToStruct(struct AuditItemRelationStruct *p,
	struct AuditItemRelationStructIn *pSource);
/**�Ա�AUDIT_ITEM_RELATION�������ͷź���**/
void DestroyAuditItemRelation(struct AuditItemRelationStruct *ptHead);
int InitAuditItemRelation(struct AuditItemRelationStruct **pptHead);

/* ����ṹ��������*/
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
		/* �ƷѺ��� */
	char    asMsisdn[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][21];
		/* �������� */
	char    asParamCode[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][21];
		/* ����ֵ */
	char    asParamValue[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][21];
		/* �Ʒ��·� */
	char    asBillingMonth[TEMPLATE_MSISDN_PARAM_BUFLEN_IN][7];
};


/*�����ṹ����*/
struct TemplateMsisdnParamStruct{

	struct TemplateMsisdnParamStruct *pNext;
	char    sMsisdn[21];		/* �ƷѺ��� */
	char    sParamCode[21];		/* �������� */
	char    sParamValue[21];		/* ����ֵ */
	char    sBillingMonth[7];		/* �Ʒ��·� */
	struct TemplateMsisdnParamStruct *pLoadNext;
};

/*�������ݶ�̬��TEMPLATE_MSISDN_PARAM���ýṹ���巽ʽȡ����*/
int EGetTemplateMsisdnParamToStruct(struct TemplateMsisdnParamStruct *p,
	struct TemplateMsisdnParamStructIn *pSource);
/**�Ա�TEMPLATE_MSISDN_PARAM�������ͷź���**/
void DestroyTemplateMsisdnParam(struct TemplateMsisdnParamStruct *ptHead);
/* ����ṹ��������*/
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
		/* �������� */
	char    asParamCode[PARAM_CODE_DESC_BUFLEN_IN][21];
		/* �����ײ� */
	char    asBillingTypeID[PARAM_CODE_DESC_BUFLEN_IN][21];
		/* ���� */
	char    asRemark[PARAM_CODE_DESC_BUFLEN_IN][61];
};


/*�����ṹ����*/
struct ParamCodeDescStruct{

	struct ParamCodeDescStruct *pNext;
	char    sParamCode[21];		/* �������� */
	char    sBillingTypeID[21];		/* �����ײ� */
	char    sRemark[61];		/* ���� */
	struct ParamCodeDescStruct *pLoadNext;
};
/*�������ݶ�̬��PARAM_CODE_DESC���ýṹ���巽ʽȡ����*/
int EGetParamCodeDescToStruct(struct ParamCodeDescStruct *p,
	struct ParamCodeDescStructIn *pSource);
/**�Ա�PARAM_CODE_DESC�������ͷź���**/
void DestroyParamCodeDesc(struct ParamCodeDescStruct *ptHead);

/*��ȡACCT_ITEM_ID���к�*/
int GetAcctItemIDSeq();

/*����ṹ��������*/
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


/* ����ṹ��������*/
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


/*�����ṹ����*/
struct BasMsisdnStruct{

	struct BasMsisdnStruct *pNext;
	char    sMsisdn[21];
	int     iCnt;
	int     iSubscriptionID;
	struct BasMsisdnStruct *pLoadNext;
};
/*�������ݶ�̬��BAS_MSISDN���ýṹ���巽ʽȡ����*/
int EGetBasMsisdnToStruct(struct BasMsisdnStruct *p,
	struct BasMsisdnStructIn *pSource);
/**�Ա�BAS_MSISDN�������ͷź���**/
void DestroyBasMsisdn(struct BasMsisdnStruct *ptHead);
int InitBasMsisdn(char sTableName[],struct BasMsisdnStruct **pptHead);


/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[PROMISE_EXPR_PARAM_BUFLEN_IN][21];
		/* ��ʽID */
	int     aiExprID[PROMISE_EXPR_PARAM_BUFLEN_IN];
		/* �������� */
	int     aiParamCnt[PROMISE_EXPR_PARAM_BUFLEN_IN];
		/* ��ʽ���� */
	char    asParamValue[PROMISE_EXPR_PARAM_BUFLEN_IN][201];
		/* ���۷�����'E'�����ֵ��ײͼ����ʷѹ�ʽ������'F'�����ֵ����뼶���ʷѹ�ʽ���� */
	char    asRateMethod[PROMISE_EXPR_PARAM_BUFLEN_IN][2];
	int     aiParamID[PROMISE_EXPR_PARAM_BUFLEN_IN];
	char    asFParamFmt[PROMISE_EXPR_PARAM_BUFLEN_IN][201];
};


/*�����ṹ����*/
struct PromiseExprParamStruct{

	struct PromiseExprParamStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iExprID;		/* ��ʽID */
	int     iParamCnt;		/* �������� */
	char    sParamValue[201];		/* ��ʽ���� */
	char    sRateMethod[2];		
/* ���۷�����'E'�����ֵ��ײͼ����ʷѹ�ʽ������'F'�����ֵ����뼶���ʷѹ�ʽ���� */
	int     iParamID;
	char    sFParamFmt[201];
	struct PromiseExprParamStruct *pLoadNext;
};

/*�������ݶ�̬��PROMISE_EXPR_PARAM���ýṹ���巽ʽȡ����*/
int EGetPromiseExprParamToStruct(struct PromiseExprParamStruct *p,
	struct PromiseExprParamStructIn *pSource);
/**�Ա�PROMISE_EXPR_PARAM�������ͷź���**/
void DestroyPromiseExprParam(struct PromiseExprParamStruct *ptHead);
int InitPromiseExprParam(struct PromiseExprParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][21];
		/* �������� */
	int     aiParamCnt[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN];
		/* ��ʽ���� */
	char    asParamValue[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][201];
		/* �ƷѺ��� */
	char    asMsisdn[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][21];
		/* ������Чʱ�� */
	char	asActiveDate[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][15];
		/* ����ʧЧʱ�� */	
	char	asInactiveDate[PROMISE_EXPR_MSISDN_PARAM_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct PromiseExprMsisdnParamStruct{

	struct PromiseExprMsisdnParamStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iParamCnt;		/* �������� */
	char    sParamValue[201];		/* ��ʽ���� */
	char    sMsisdn[21];		/* �ƷѺ��� */
	char	sActiveDate[15];	/* ������Чʱ�� */
	char	sInactiveDate[15];	/* ����ʧЧʱ�� */
	struct PromiseExprMsisdnParamStruct *pLoadNext;
};


/*�������ݶ�̬��PROMISE_EXPR_MSISDN_PARAM���ýṹ���巽ʽȡ����*/
int EGetPromiseExprMsisdnParamToStruct(struct PromiseExprMsisdnParamStruct *p,
	struct PromiseExprMsisdnParamStructIn *pSource);
/**�Ա�PROMISE_EXPR_MSISDN_PARAM�������ͷź���**/
void DestroyPromiseExprMsisdnParam(struct PromiseExprMsisdnParamStruct *ptHead);
int InitPromiseExprMsisdnParam(struct PromiseExprMsisdnParamStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��ʽID */
	int     aiExprID[PROMISE_EXPR_BUFLEN_IN];
		/* ����������Ϊ����Ϊ�������� */
	char    asParamNameStr[PROMISE_EXPR_BUFLEN_IN][201];
		/* ҵ������ */
	char    asRemark[PROMISE_EXPR_BUFLEN_IN][401];
	char	asSetDetail[PROMISE_EXPR_BUFLEN_IN][3001];
		/* ��ʽ */
	char    asExpr[PROMISE_EXPR_BUFLEN_IN][4001];
		/* ��ʽ���� */
	char 	asPromiseType[PROMISE_EXPR_BUFLEN_IN][2];
		/* ���� */
	char	asName[PROMISE_EXPR_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct PromiseExprStruct{

	struct PromiseExprStruct *pNext;
	int     iExprID;		/* ��ʽID */
	char    sParamNameStr[201];		/* ����������Ϊ����Ϊ�������� */
	char    sRemark[401];		/* ҵ������ */
	char	sSetDetail[3001];
	char    sExpr[4001];		/* ��ʽ */
	char 	sPromiseType[2];	/* ��ʽ���� */
	char	sName[41];		/* ���� */
	struct PromiseExprStruct *pLoadNext;
};
/*�������ݶ�̬��PROMISE_EXPR���ýṹ���巽ʽȡ����*/
int EGetPromiseExprToStruct(struct PromiseExprStruct *p,
	struct PromiseExprStructIn *pSource);
/**�Ա�PROMISE_EXPR�������ͷź���**/
void DestroyPromiseExpr(struct PromiseExprStruct *ptHead);
int InitPromiseExpr(struct PromiseExprStruct **pptHead);

/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[MONTH_FEE_TARIFF_BUFLEN_IN][21];
		/* ������ */
	char	asAreaCode[MONTH_FEE_TARIFF_BUFLEN_IN][10];	
		/* ���ͣ���Z'����T'����Y' */
	char    asType[MONTH_FEE_TARIFF_BUFLEN_IN][2];
		/* ��λ����Y'�꣬��S' ������M'�� */
	char    asUnit[MONTH_FEE_TARIFF_BUFLEN_IN][2];
		/* ����������ʶ����0'Ϊȫ�£�'1'Ϊ���� */
	char    asHalfMonthFlag[MONTH_FEE_TARIFF_BUFLEN_IN][2];
		/* ���� */
	double  adRate[MONTH_FEE_TARIFF_BUFLEN_IN];
};


/*�����ṹ����*/
struct MonthFeeTariffStruct{

	struct MonthFeeTariffStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	char	sAreaCode[10];		/* ������ */
	char    sType[2];		/* ���ͣ���Z'����T'����Y' */
	char    sUnit[2];		/* ��λ����Y'�꣬��S' ������M'�� */
	char    sHalfMonthFlag[2];		/* ����������ʶ����0'Ϊȫ�£�'1'Ϊ���� */
	double  dRate;		/* ���� */
	
	int	iRateUnit;
	struct MonthFeeTariffStruct *pLoadNext;
};

/*�������ݶ�̬��MONTH_FEE_TARIFF���ýṹ���巽ʽȡ����*/
int EGetMonthFeeTariffToStruct(struct MonthFeeTariffStruct *p,
	struct MonthFeeTariffStructIn *pSource);
/**�Ա�MONTH_FEE_TARIFF�������ͷź���**/
void DestroyMonthFeeTariff(struct MonthFeeTariffStruct *ptHead);
int InitMonthFeeTariff(struct MonthFeeTariffStruct **pptHead);

/* ����ṹ��������*/
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
		/* ��ʽID */
	int     aiExprID[PROMISE_EXPR_STATE_REASON_BUFLEN_IN];
		/* ����״̬��� */
	int     aiStateSeq[PROMISE_EXPR_STATE_REASON_BUFLEN_IN];
		/* ����״̬ԭ�� */
	char    asStateSeqReason[PROMISE_EXPR_STATE_REASON_BUFLEN_IN][401];
		/* ���� */
	char	asName[PROMISE_EXPR_STATE_REASON_BUFLEN_IN][41];
};

/*�����ṹ����*/
struct PromiseExprStateReasonStruct{

	struct PromiseExprStateReasonStruct *pNext;
	int     iExprID;		/* ��ʽID */
	int     iStateSeq;		/* ����״̬��� */
	char    sStateSeqReason[401];		/* ����״̬ԭ�� */
	char	sName[41];		/* ���� */
	struct PromiseExprStateReasonStruct *pLoadNext;
};

/*�������ݶ�̬��PROMISE_EXPR_STATE_REASON���ýṹ���巽ʽȡ����*/
int EGetPromiseExprStateReasonToStruct(struct PromiseExprStateReasonStruct *p,
	struct PromiseExprStateReasonStructIn *pSource);
/**�Ա�PROMISE_EXPR_STATE_REASON�������ͷź���**/
void DestroyPromiseExprStateReason(struct PromiseExprStateReasonStruct *ptHead);
int InitPromiseExprStateReason(struct PromiseExprStateReasonStruct **pptHead);

/*����ṹ��������*/
struct AuditNumResStructOut{

#ifndef TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT
#define TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT		300
#endif

	struct AuditNumResStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û������� */
	char    asAreaCode[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][10];
		/* ��TABLE_TYPE='A'ʱ�����ֶ�Ϊ�˺��µ�����һ������ */
	char    asAccNbr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][21];
		/* ��¼���� */
	char    asRecordType[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][2];
		/* ������� */
	char    asAuditDate[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][15];
		/* 'P','F' */
	char    asAuditState[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][2];
		/* ���� */
	char    asAuditRuleStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][201];
	char    asAuditInfo[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][2001];
	char	asAuditAllTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][201];
	char	asAuditDiffTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_OUT][201];

};

/* ����ṹ��������*/
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
		/* �û������� */
	char    asAreaCode[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][10];
		/* ��TABLE_TYPE='A'ʱ�����ֶ�Ϊ�˺��µ�����һ������ */
	char    asAccNbr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][21];
		/* ��¼���� */
	char    asRecordType[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][2];
		/* ������� */
	char    asAuditDate[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][15];
		/* 'P','F' */
	char    asAuditState[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][2];
		/* ���� */
	char    asAuditRuleStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][201];
	char    asAuditInfo[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][2001];
	char	asAuditAllTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][201];
	char	asAuditDiffTypeStr[TEMPLATE_AUDIT_NUM_RES_BUFLEN_IN][201];

};


/*�����ṹ����*/
struct AuditNumResStruct{

	struct AuditNumResStruct *pNext;
	char    sAreaCode[10];		/* �û������� */
	char    sAccNbr[21];		/* ��TABLE_TYPE='A'ʱ�����ֶ�Ϊ�˺��µ�����һ������ */
	char    sRecordType[2];		/* ��¼���� */
	char    sAuditDate[15];		/* ������� */
	char    sAuditState[2];		/* 'P','F' */
	char    sAuditRuleStr[201];		/* ���� */
	char    sAuditInfo[2001];
	char	sAuditAllTypeStr[201];
	char	sAuditDiffTypeStr[201];
	
	char	sRowID[20];
	char	sSourceID[41];

	struct AuditNumResStruct *pLoadNext;
};
/*�������ݶ�̬��TEMPLATE_AUDIT_NUM_RES���ýṹ���巽ʽȡ����*/
int EGetAuditNumResToStruct(struct AuditNumResStruct *p,
	struct AuditNumResStructIn *pSource);
/**�Ա�TEMPLATE_AUDIT_NUM_RES�������ͷź���**/
void DestroyAuditNumRes(struct AuditNumResStruct *ptHead);
int InitAuditNumRes(struct AuditNumResStruct **pptHead);
/*�������ݽṹ����д��TEMPLATE_AUDIT_NUM_RES*/
int EInsertStructToAuditNumRes(struct AuditNumResStruct *p,
	int iInsertFlag,struct AuditNumResStructOut *pTarget);

/*����ṹ��������*/
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
		/* �ʷѼ��ϴ� */
	char    asTariffIDStr[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][201];
	char    asComments[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][4001];
		/* ״̬ */
	char    asState[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][4];
		/* ����ʱ�� */
	char    asCreatedDate[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][15];
		/* ���ʱ�� */
	char    asStateDate[PROMISE_TARIFF_COMMENTS_BUFLEN_OUT][15];
};


/* ����ṹ��������*/
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
		/* �ʷѼ��ϴ� */
	char    asTariffIDStr[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][201];
	char    asComments[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][4001];
		/* ״̬ */
	char    asState[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][4];
		/* ����ʱ�� */
	char    asCreatedDate[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][15];
		/* ���ʱ�� */
	char    asStateDate[PROMISE_TARIFF_COMMENTS_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct PromiseTariffCommentsStruct{

	struct PromiseTariffCommentsStruct *pNext;
	char    sBillingTypeID[21];
	int     iPromiseElementID;
	char    sTariffIDStr[201];		/* �ʷѼ��ϴ� */
	char    sComments[4001];
	char    sState[4];		/* ״̬ */
	char    sCreatedDate[15];		/* ����ʱ�� */
	char    sStateDate[15];		/* ���ʱ�� */
	struct PromiseTariffCommentsStruct *pLoadNext;
};
/*�������ݶ�̬��PROMISE_TARIFF_COMMENTS���ýṹ���巽ʽȡ����*/
int EGetPromiseTariffCommentsToStruct(struct PromiseTariffCommentsStruct *p,
	struct PromiseTariffCommentsStructIn *pSource);
/**�Ա�PROMISE_TARIFF_COMMENTS�������ͷź���**/
void DestroyPromiseTariffComments(struct PromiseTariffCommentsStruct *ptHead);
/*�������ݽṹ����д��PROMISE_TARIFF_COMMENTS*/
int EInsertStructToPromiseTariffComments(struct PromiseTariffCommentsStruct *p,
	int iInsertFlag,struct PromiseTariffCommentsStructOut *pTarget);

/*����ṹ��������*/
struct AcctItemTypeRelationStructOut{

#ifndef ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT
#define ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT		300
#endif

	struct AcctItemTypeRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ŀ����ID */
	int     aiAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
		/* ����ϵͳ��ĿID */
	int     aiSubjectID[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
	int     aiOriAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
		/* ���� ��T�� �굥����Ŀ��M�� ������Ŀ��I����ֵ��������Ŀ��A���Ż�����Ŀ��O���Żݺ����������Ŀ */
	char    asCatg[ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
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
		/* ��Ŀ����ID */
	int     aiAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
		/* ����ϵͳ��ĿID */
	int     aiSubjectID[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
	int     aiOriAcctItemTypeID[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
		/* ���� ��T�� �굥����Ŀ��M�� ������Ŀ��I����ֵ��������Ŀ��A���Ż�����Ŀ��O���Żݺ����������Ŀ */
	char    asCatg[ACCT_ITEM_TYPE_RELATION_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct AcctItemTypeRelationStruct{

	struct AcctItemTypeRelationStruct *pNext;
	int     iAcctItemTypeID;		/* ��Ŀ����ID */
	int     iSubjectID;		/* ����ϵͳ��ĿID */
	int     iOriAcctItemTypeID;
	char    sCatg[2];		/* ���� ��T�� �굥����Ŀ��M�� ������Ŀ��I����ֵ��������Ŀ��A���Ż�����Ŀ��O���Żݺ����������Ŀ */
	struct AcctItemTypeRelationStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FAcctItemTypeRelationStruct{

	char    sAcctItemTypeID[8];		/* ��Ŀ����ID */
	char    sSubjectID[8];		/* ����ϵͳ��ĿID */
	char    sOriAcctItemTypeID[8];
	char    sCatg[1];		/* ���� ��T�� �굥����Ŀ��M�� ������Ŀ��I����ֵ��������Ŀ��A���Ż�����Ŀ��O���Żݺ����������Ŀ */
};


/*�������ݶ�̬��ACCT_ITEM_TYPE_RELATION���ýṹ���巽ʽȡ����*/
int EGetAcctItemTypeRelationToStruct(struct AcctItemTypeRelationStruct *p,
	struct AcctItemTypeRelationStructIn *pSource);
/**�Ա�ACCT_ITEM_TYPE_RELATION�������ͷź���**/
void DestroyAcctItemTypeRelation(struct AcctItemTypeRelationStruct *ptHead);
int InitAcctItemTypeRelation(struct AcctItemTypeRelationStruct **pptHead);
/*����ṹ��������*/
struct AccSubjectItemStructOut{

#ifndef ACC_SUBJECT_ITEM_BUFLEN_OUT
#define ACC_SUBJECT_ITEM_BUFLEN_OUT		300
#endif

	struct AccSubjectItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asAccNbr[ACC_SUBJECT_ITEM_BUFLEN_OUT][21];
		/* �û�������ʶ */
	int     aiSubscriptionID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* �˻�ID */
	int     aiAccountID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* �˻�ID */
	int     aiDefaultAccountID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* ��ĿID */
	int     aiSubjectID[ACC_SUBJECT_ITEM_BUFLEN_OUT];
		/* ��Ŀ���� */
	int    aiTotalFee[ACC_SUBJECT_ITEM_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �û����� */
	char    asAccNbr[ACC_SUBJECT_ITEM_BUFLEN_IN][21];
		/* �û�������ʶ */
	int     aiSubscriptionID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* �˻�ID */
	int     aiAccountID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* �˻�ID */
	int     aiDefaultAccountID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* ��ĿID */
	int     aiSubjectID[ACC_SUBJECT_ITEM_BUFLEN_IN];
		/* ��Ŀ���� */
	int    aiTotalFee[ACC_SUBJECT_ITEM_BUFLEN_IN];
};


/*�����ṹ����*/
struct AccSubjectItemStruct{

	struct AccSubjectItemStruct *pNext;
	char    sAccNbr[21];		/* �û����� */
	int     iSubscriptionID;		/* �û�������ʶ */
	int     iAccountID;		/* �˻�ID */
	int     iDefaultAccountID;		/* �˻�ID */
	int     iSubjectID;		/* ��ĿID */
	int    iTotalFee;		/* ��Ŀ���� */
	
/*��չʹ��*/
	int iAcctItemTypeID;		/*�ÿ�Ŀ����Ӧ����Ŀ*/
	struct AccSubjectItemStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FAccSubjectItemStruct{

	char    sAccNbr[20];		/* �û����� */
	char    sSubscriptionID[9];		/* �û�������ʶ */
	char    sAccountID[9];		/* �˻�ID */
	char    sDefaultAccountID[9];		/* �˻�ID */
	char    sSubjectID[8];		/* ��ĿID */
	char    sTotalFee[15];		/* ��Ŀ���� */
};


/*�������ݶ�̬��ACC_SUBJECT_ITEM���ýṹ���巽ʽȡ����*/
int EGetAccSubjectItemToStruct(struct AccSubjectItemStruct *p,
	struct AccSubjectItemStructIn *pSource);
/**�Ա�ACC_SUBJECT_ITEM�������ͷź���**/
void DestroyAccSubjectItem(struct AccSubjectItemStruct *ptHead);
int InitAccSubjectItem(struct AccSubjectItemStruct **pptHead);

/*����ṹ��������*/
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


/* ����ṹ��������*/
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


/*�����ṹ����*/
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


/*�����ļ��ṹ����*/
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


/*�������ݶ�̬��ACC_SUBJECT���ýṹ���巽ʽȡ����*/
int EGetAccSubjectToStruct(struct AccSubjectStruct *p,
	struct AccSubjectStructIn *pSource);
/**�Ա�ACC_SUBJECT�������ͷź���**/
void DestroyAccSubject(struct AccSubjectStruct *ptHead);
int InitAccSubject(struct AccSubjectStruct **pptHead);


/* ����ṹ��������*/
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
		/* �������� */
	char    asTaskName[USER_AUDIT_TASK_BUFLEN_IN][41];
		/* ���� */
	int     aiStaffID[USER_AUDIT_TASK_BUFLEN_IN];
		/* �·� */
	char    asMonth[USER_AUDIT_TASK_BUFLEN_IN][7];
		/* �������� */
	char    asAuditType[USER_AUDIT_TASK_BUFLEN_IN][2];
		/* ���� */
	int     aiSeq[USER_AUDIT_TASK_BUFLEN_IN];
		/* �˵�����״̬:  Nδ����((���˽ű�δ���л�δ���гɹ�,�޷���ȡ����)   S�ѻ���(���˽ű�����,������ȡ����) */
	char    asTaskState[USER_AUDIT_TASK_BUFLEN_IN][2];
		/* ���� */
	char    asAreaCode[USER_AUDIT_TASK_BUFLEN_IN][6];
		/* ���н����־ */
	char    asRunLog[USER_AUDIT_TASK_BUFLEN_IN][4001];
		/* �嵥����״̬    (Nδִ���嵥����,S�ѻ���.) */
	char    asTaskState2[USER_AUDIT_TASK_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct UserAuditTaskStruct{

	struct UserAuditTaskStruct *pNext;
	char    sTaskID[5];
	char    sTaskName[41];		/* �������� */
	int     iStaffID;		/* ���� */
	char    sMonth[7];		/* �·� */
	char    sAuditType[2];		/* �������� */
	int     iSeq;		/* ���� */
	char    sTaskState[2];		/* �˵�����״̬:  Nδ����((���˽ű�δ���л�δ���гɹ�,�޷���ȡ����)   S�ѻ���(���˽ű�����,������ȡ����) */
	char    sAreaCode[6];		/* ���� */
	char    sRunLog[4001];		/* ���н����־ */
	char    sTaskState2[2];		/* �嵥����״̬    (Nδִ���嵥����,S�ѻ���.) */
	struct UserAuditTaskStruct *pLoadNext;
};
/*�������ݶ�̬��USER_AUDIT_TASK���ýṹ���巽ʽȡ����*/
int EGetUserAuditTaskToStruct(struct UserAuditTaskStruct *p,
	struct UserAuditTaskStructIn *pSource);
/**�Ա�USER_AUDIT_TASK�������ͷź���**/
void DestroyUserAuditTask(struct UserAuditTaskStruct *ptHead);	

/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[USER_ATTENTION_BILL_BUFLEN_IN][21];
		/* 'B'��ʾ����Ʒ�ײ�'b'��ʾ�Ӳ�Ʒ�ײ� 'S'��ʾҵ��Ʒ�� */
	char    asCatg[USER_ATTENTION_BILL_BUFLEN_IN][2];
		/* M ����ҵ��; N ������ҵ���¹���; O �����ر��ע */
	char    asExtraType[USER_ATTENTION_BILL_BUFLEN_IN][2];
		/* �ײͳ�ȡ�û���������:A ����,      D Ĭ�ϸ��� */
	char    asExtraCount[USER_ATTENTION_BILL_BUFLEN_IN][2];
		/* ����չʾ: A ȫ��չʾ;     T  չʾ���� */
	char    asShowType[USER_ATTENTION_BILL_BUFLEN_IN][3];
		/* ����״̬ NΪ�����ˣ�YΪ����״̬ */
	char    asAuditState[USER_ATTENTION_BILL_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct UserAttentionBillStruct{

	struct UserAttentionBillStruct *pNext;
	char    sTaskID[5];
	char    sBillingTypeID[21];		/* �ײ�ID */
	char    sCatg[2];		/* 'B'��ʾ����Ʒ�ײ�'b'��ʾ�Ӳ�Ʒ�ײ� 'S'��ʾҵ��Ʒ�� */
	char    sExtraType[2];		/* M ����ҵ��; N ������ҵ���¹���; O �����ر��ע */
	char    sExtraCount[2];		/* �ײͳ�ȡ�û���������:A ����,      D Ĭ�ϸ��� */
	char    sShowType[3];		/* ����չʾ: A ȫ��չʾ;     T  չʾ���� */
	char	sAuditState[2];		/* ����״̬ NΪ�����ˣ�YΪ����״̬ */
	int	iFlag;			/* 1Ϊ��������ײͣ�0Ϊδ��������ײ� */
	
	struct UserAttentionBillStruct *pLoadNext;
};
/*�������ݶ�̬��USER_ATTENTION_BILL���ýṹ���巽ʽȡ����*/
int EGetUserAttentionBillToStruct(struct UserAttentionBillStruct *p,
	struct UserAttentionBillStructIn *pSource);
/**�Ա�USER_ATTENTION_BILL�������ͷź���**/
void DestroyUserAttentionBill(struct UserAttentionBillStruct *ptHead);

/* ����ṹ��������*/
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
		/* ���� */
	int     aiStaffID[USER_ATTENTION_MSISDN_BUFLEN_IN];
		/* ��ע���� */
	char    asMsisdn[USER_ATTENTION_MSISDN_BUFLEN_IN][21];
		/* ��������ײ�ID */
	char    asBillingTypeID[USER_ATTENTION_MSISDN_BUFLEN_IN][21];
		/* Y:Ҫ����.X :������ */
	char    asState[USER_ATTENTION_MSISDN_BUFLEN_IN][2];
		/* ����ʱ�� */
	char    asCreateDate[USER_ATTENTION_MSISDN_BUFLEN_IN][15];
		/* ״̬ʱ��(�ı�) */
	char    asStateDate[USER_ATTENTION_MSISDN_BUFLEN_IN][15];
		/* �������״̬  (  C������;  F ��Ա�����к��� ;  N ������;  P�ϸ����;X �������ײ�ID�޶�Ӧ��ϵ) */
	char    asCheckState[USER_ATTENTION_MSISDN_BUFLEN_IN][2];
		/* ����ID */
	char	asTaskID[USER_ATTENTION_MSISDN_BUFLEN_IN][5];
};


/*�����ṹ����*/
struct UserAttentionMsisdnStruct{

	struct UserAttentionMsisdnStruct *pNext;
	int     iStaffID;		/* ���� */
	char    sMsisdn[21];		/* ��ע���� */
	char    sBillingTypeID[21];		/* ��������ײ�ID */
	char    sState[2];		/* Y:Ҫ����.X :������ */
	char    sCreateDate[15];		/* ����ʱ�� */
	char    sStateDate[15];		/* ״̬ʱ��(�ı�) */
	char    sCheckState[2];		/* �������״̬  (  C������;  F ��Ա�����к��� ;  N ������;  P�ϸ����;X �������ײ�ID�޶�Ӧ��ϵ) */
	char	sTaskID[5];		/* ����ID */
	struct UserAttentionMsisdnStruct *pLoadNext;
};
/*�������ݶ�̬��USER_ATTENTION_MSISDN���ýṹ���巽ʽȡ����*/
int EGetUserAttentionMsisdnToStruct(struct UserAttentionMsisdnStruct *p,
	struct UserAttentionMsisdnStructIn *pSource);
/**�Ա�USER_ATTENTION_MSISDN�������ͷź���**/
void DestroyUserAttentionMsisdn(struct UserAttentionMsisdnStruct *ptHead);

/* ����ṹ��������*/
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
		/* ����ID */
	char    asTaskID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][5];
		/* ������� */
	char    asExtraType[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* ҵ��(����)���� */
	char    asBillingTypeID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][21];
		/* ���ͺ��� */
	char    asTypicalMsisdn[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][21];
		/* �˻� */
	int     aiAcctID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN];
		/* ҵ��˵��(ȫ) */
	char    asBillingRule[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* 'P','F' */
	char    asAuditState[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* ����(�����ʣ�˵�� */
	char    asProblem[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][3001];
		/* �Ʒѷ��˵��˻��¸��û�����ϸ (��SEQȡ, report_acct_detail_seq) */
	int     aiAcctDetailID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN];
		/* (�˻����ܲ���) */
	char    asAcctDiffDetail[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* �û���ع��� */
	char    asUserRule[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* ʡ�ֺ˲�ظ� */
	char    asProvReply[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2001];
		/* ���и��˽�� */
	char    asCityCheckResult[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2001];
		/* 'B'��ע�ײ�,'M'��ע�û� */
	char    asAttentionType[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* ���������ײ��б� */
	char    asProblemBill[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][1001];
		/* ���������ײ�iD�б� */
	char    asProblemBillID[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][201];
	char    asAcctDiffDetail2[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][4001];
		/* Y �ѷ���; N���Ϊδ���� */
	char	asAnlyzeFlag[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][2];
		/* ��������ʱ�� */
	char	asDataDate[AUDIT_TASK_REPORT_DATA_BUFLEN_IN][15];
};


/*����ṹ��������*/
struct AuditTaskReportDataStructOut{

#ifndef AUDIT_TASK_REPORT_DATA_BUFLEN_OUT
#define AUDIT_TASK_REPORT_DATA_BUFLEN_OUT		300
#endif

	struct AuditTaskReportDataStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����ID */
	char    asTaskID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][5];
		/* ������� */
	char    asExtraType[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* ҵ��(����)���� */
	char    asBillingTypeID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][21];
		/* ���ͺ��� */
	char    asTypicalMsisdn[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][21];
		/* �˻� */
	int     aiAcctID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT];
		/* ҵ��˵��(ȫ) */
	char    asBillingRule[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* 'P','F' */
	char    asAuditState[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* ����(�����ʣ�˵�� */
	char    asProblem[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][3001];
		/* �Ʒѷ��˵��˻��¸��û�����ϸ (��SEQȡ, report_acct_detail_seq) */
	int     aiAcctDetailID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT];
		/* (�˻����ܲ���) */
	char    asAcctDiffDetail[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* �û���ع��� */
	char    asUserRule[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* ʡ�ֺ˲�ظ� */
	char    asProvReply[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2001];
		/* ���и��˽�� */
	char    asCityCheckResult[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2001];
		/* 'B'��ע�ײ�,'M'��ע�û� */
	char    asAttentionType[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* ���������ײ��б� */
	char    asProblemBill[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][1001];
		/* ���������ײ�iD�б� */
	char    asProblemBillID[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][201];
	char    asAcctDiffDetail2[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][4001];
		/* Y �ѷ���; N���Ϊδ���� */
	char	asAnlyzeFlag[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][2];
		/* ��������ʱ�� */
	char	asDataDate[AUDIT_TASK_REPORT_DATA_BUFLEN_OUT][15];			
};
/*�����ṹ����*/
struct AuditTaskReportDataStruct{

	struct AuditTaskReportDataStruct *pNext;
	char    sTaskID[5];		/* ����ID */
	char    sExtraType[2];		/* ������� */
	char    sBillingTypeID[21];		/* ҵ��(����)���� */
	char    sTypicalMsisdn[21];		/* ���ͺ��� */
	int     iAcctID;		/* �˻� */
	char    sBillingRule[4001];		/* ҵ��˵��(ȫ) */
	char    sAuditState[2];		/* 'P','F' */
	char    sProblem[3001];		/* ����(�����ʣ�˵�� */
	int     iAcctDetailID;		/* �Ʒѷ��˵��˻��¸��û�����ϸ (��SEQȡ, report_acct_detail_seq) */
	char    sAcctDiffDetail[4001];		/* (�˻����ܲ���) */
	char    sUserRule[4001];		/* �û���ع��� */
	char    sProvReply[2001];		/* ʡ�ֺ˲�ظ� */
	char    sCityCheckResult[2001];		/* ���и��˽�� */
	char    sAttentionType[2];		/* 'B'��ע�ײ�,'M'��ע�û� */
	char    sProblemBill[1001];		/* ���������ײ��б� */
	char    sProblemBillID[201];		/* ���������ײ�iD�б� */
	char	sAcctDiffDetail2[4001];
	char	sAnlyzeFlag[2];			/* Y �ѷ���; N���Ϊδ���� */
	char	sDataDate[15];			/* ��������ʱ�� */
	struct AuditTaskReportDataStruct *pLoadNext;
};
/*�������ݶ�̬��AUDIT_TASK_REPORT_DATA���ýṹ���巽ʽȡ����*/
int EGetAuditTaskReportDataToStruct(struct AuditTaskReportDataStruct *p,
	struct AuditTaskReportDataStructIn *pSource);
/*�������ݽṹ����д��AUDIT_TASK_REPORT_DATA*/
int EInsertStructToAuditTaskReportData(struct AuditTaskReportDataStruct *p,
	int iInsertFlag,struct AuditTaskReportDataStructOut *pTarget);
/**�Ա�AUDIT_TASK_REPORT_DATA�������ͷź���**/
void DestroyAuditTaskReportData(struct AuditTaskReportDataStruct *ptHead);

/*����ṹ��������*/
struct AuditAcctDetailStructOut{

#ifndef AUDIT_ACCT_DETAIL_BUFLEN_OUT
#define AUDIT_ACCT_DETAIL_BUFLEN_OUT		300
#endif

	struct AuditAcctDetailStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����ID */
	char    asTaskID[AUDIT_ACCT_DETAIL_BUFLEN_OUT][5];
		/* ����audit_task_report_data.acct_detail_id */
	int     aiDetailID[AUDIT_ACCT_DETAIL_BUFLEN_OUT];
		/* �û����� */
	char    asMsisdn[AUDIT_ACCT_DETAIL_BUFLEN_OUT][21];
		/* ��ϸ���� */
	char    asContent[AUDIT_ACCT_DETAIL_BUFLEN_OUT][4001];
		/* �����ʶ:   Y �в���,N �޲���(�Ǹ���AUD����������Ŀ������ж�), E (�޷��ж�) */
	char    asDiffFlag[AUDIT_ACCT_DETAIL_BUFLEN_OUT][2];
};



/* ����ṹ��������*/
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
		/* ����ID */
	char    asTaskID[AUDIT_ACCT_DETAIL_BUFLEN_IN][5];
		/* ����audit_task_report_data.acct_detail_id */
	int     aiDetailID[AUDIT_ACCT_DETAIL_BUFLEN_IN];
		/* �û����� */
	char    asMsisdn[AUDIT_ACCT_DETAIL_BUFLEN_IN][21];
		/* ��ϸ���� */
	char    asContent[AUDIT_ACCT_DETAIL_BUFLEN_IN][4001];
		/* �����ʶ:   Y �в���,N �޲���(�Ǹ���AUD����������Ŀ������ж�), E (�޷��ж�) */
	char    asDiffFlag[AUDIT_ACCT_DETAIL_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct AuditAcctDetailStruct{

	struct AuditAcctDetailStruct *pNext;
	char    sTaskID[5];		/* ����ID */
	int     iDetailID;		/* ����audit_task_report_data.acct_detail_id */
	char    sMsisdn[21];		/* �û����� */
	char    sContent[4001];		/* ��ϸ���� */
	char    sDiffFlag[2];		/* �����ʶ:   Y �в���,N �޲���(�Ǹ���AUD����������Ŀ������ж�), E (�޷��ж�) */
	struct AuditAcctDetailStruct *pLoadNext;
};

/*�������ݶ�̬��AUDIT_ACCT_DETAIL���ýṹ���巽ʽȡ����*/
int EGetAuditAcctDetailToStruct(struct AuditAcctDetailStruct *p,
	struct AuditAcctDetailStructIn *pSource);
/*�������ݽṹ����д��AUDIT_ACCT_DETAIL*/
int EInsertStructToAuditAcctDetail(struct AuditAcctDetailStruct *p,
	int iInsertFlag,struct AuditAcctDetailStructOut *pTarget);
/**�Ա�AUDIT_ACCT_DETAIL�������ͷź���**/
void DestroyAuditAcctDetail(struct AuditAcctDetailStruct *ptHead);

/* ����ṹ��������*/
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


/*�����ṹ����*/
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
/*�������ݶ�̬��MU_OTHER���ýṹ���巽ʽȡ����*/
int EGetMuOtherToStruct(struct MuOtherStruct *p,
	struct MuOtherStructIn *pSource);
/**�Ա�MU_OTHER�������ͷź���**/
void DestroyMuOther(struct MuOtherStruct *ptHead);

struct ExtractDefStruct{

	struct ExtractDefStruct *pNext;
	char    sAccNbr[21];		/* ���� */
	int     iSubscriptionID;		/* ������ʶ */
	int     iAcctID;		/* �ʻ� */
	char    sRegionID[2];		/* ���� */
	char    sBillingTypeID[11];		/* �ײ� */
	char    sCatg[2];		/* �ײ�����*/
	int	iDiffProtry;		/* ����ȼ���ֻ�������ɱ���ʱ���õ� */
	struct ExtractDefStruct *pLoadNext;
};

/*������־*/
/*����ṹ��������*/
struct UserAuditLogStructOut{

#ifndef USER_AUDIT_LOG_BUFLEN_OUT
#define USER_AUDIT_LOG_BUFLEN_OUT		300
#endif

	struct UserAuditLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����ID */
	char    asTaskID[USER_AUDIT_LOG_BUFLEN_OUT][5];
		/* A:�˵���������,   T �嵥�������� */
	char    asType[USER_AUDIT_LOG_BUFLEN_OUT][2];
		/* �������� */
	char    asTaskName[USER_AUDIT_LOG_BUFLEN_OUT][41];
		/* ���� */
	int     aiStaffID[USER_AUDIT_LOG_BUFLEN_OUT];
		/* ���� */
	char    asAreaCode[USER_AUDIT_LOG_BUFLEN_OUT][6];
		/* �����·� */
	char    asMonth[USER_AUDIT_LOG_BUFLEN_OUT][7];
		/* �������� */
	char    asAuditType[USER_AUDIT_LOG_BUFLEN_OUT][2];
		/* ��ע������� */
	int     aiMsisdnCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* ��ע�ײ͸��� */
	int     aiBillCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* ��ע�����б� */
	char    asMsisdnList[USER_AUDIT_LOG_BUFLEN_OUT][4001];
		/* ��ע�ײ��б� */
	char    asBillList[USER_AUDIT_LOG_BUFLEN_OUT][4001];
		/* ������־ */
	char    asRunLog[USER_AUDIT_LOG_BUFLEN_OUT][4001];
		/* ����ʱ�� */
	char    asRunTime[USER_AUDIT_LOG_BUFLEN_OUT][15];
		/* ������� */
	int	aiDiffCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* �û����� */
	int 	aiAllCount[USER_AUDIT_LOG_BUFLEN_OUT];
		/* ������־��PΪ�ɹ���FΪʧ�� */
	char	asAuditState[USER_AUDIT_LOG_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
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
		/* ����ID */
	char    asTaskID[USER_AUDIT_LOG_BUFLEN_IN][5];
		/* A:�˵���������,   T �嵥�������� */
	char    asType[USER_AUDIT_LOG_BUFLEN_IN][2];
		/* �������� */
	char    asTaskName[USER_AUDIT_LOG_BUFLEN_IN][41];
		/* ���� */
	int     aiStaffID[USER_AUDIT_LOG_BUFLEN_IN];
		/* ���� */
	char    asAreaCode[USER_AUDIT_LOG_BUFLEN_IN][6];
		/* �����·� */
	char    asMonth[USER_AUDIT_LOG_BUFLEN_IN][7];
		/* �������� */
	char    asAuditType[USER_AUDIT_LOG_BUFLEN_IN][2];
		/* ��ע������� */
	int     aiMsisdnCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* ��ע�ײ͸��� */
	int     aiBillCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* ��ע�����б� */
	char    asMsisdnList[USER_AUDIT_LOG_BUFLEN_IN][4001];
		/* ��ע�ײ��б� */
	char    asBillList[USER_AUDIT_LOG_BUFLEN_IN][4001];
		/* ������־ */
	char    asRunLog[USER_AUDIT_LOG_BUFLEN_IN][4001];
		/* ����ʱ�� */
	char    asRunTime[USER_AUDIT_LOG_BUFLEN_IN][15];
		/* ������� */
	int	aiDiffCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* �û����� */
	int 	aiAllCount[USER_AUDIT_LOG_BUFLEN_IN];
		/* ������־��PΪ�ɹ���FΪʧ�� */
	char	asAuditState[USER_AUDIT_LOG_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct UserAuditLogStruct{

	struct UserAuditLogStruct *pNext;
	char    sTaskID[5];		/* ����ID */
	char    sType[2];		/* A:�˵���������,   T �嵥�������� */
	char    sTaskName[41];		/* �������� */
	int     iStaffID;		/* ���� */
	char    sAreaCode[6];		/* ���� */
	char    sMonth[7];		/* �����·� */
	char    sAuditType[2];		/* �������� */
	int     iMsisdnCount;		/* ��ע������� */
	int     iBillCount;		/* ��ע�ײ͸��� */
	char    sMsisdnList[4001];		/* ��ע�����б� */
	char    sBillList[4001];		/* ��ע�ײ��б� */
	char    sRunLog[4001];		/* ������־ */
	char    sRunTime[15];		/* ����ʱ�� */
	int	iDiffCount;		/* ������� */
	int 	iAllCount;		/* �û����� */
	char	sAuditState[2];		/* ������־��PΪ�ɹ���FΪʧ�� */
	struct UserAuditLogStruct *pLoadNext;
};

/*�������ݶ�̬��USER_AUDIT_LOG���ýṹ���巽ʽȡ����*/
int EGetUserAuditLogToStruct(struct UserAuditLogStruct *p,
	struct UserAuditLogStructIn *pSource);
/**�Ա�USER_AUDIT_LOG�������ͷź���**/
void DestroyUserAuditLog(struct UserAuditLogStruct *ptHead);
/*�������ݽṹ����д��USER_AUDIT_LOG*/
int EInsertStructToUserAuditLog(struct UserAuditLogStruct *p,
	int iInsertFlag,struct UserAuditLogStructOut *pTarget);




/****************************�ײ�����Է�������***************

���Ĳ������ݣ�
��һ��������������
�ڶ����ײͻ���ָ���������
�������û�����ָ���������
���ģ���Ӧָ������

***************************************************************/


/******************��һ����*******************************

����Ϊ����ָ�����
ָ���ŵҪ����ԭ��ŵҪ�ع�ϵ��ָ����Ŀ������ԭ��Ŀ���͹�ϵ��
ҵ��ģʽ���ŵ���ʹ�ϵ��ָ���ŵҪ�ء�ָ����Ŀ���͡�ָ��ҵ�����͡�
ҵ��ʵ��ģʽ
***********************************************************/
/*����ṹ��������*/
struct CrPromiseElementRelationStructOut{

#ifndef CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT
#define CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT		300
#endif

	struct CrPromiseElementRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ָ���ŵҪ��ID */
	int     aiCrPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT];
		/* ��ŵҪ��ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ָ���ŵҪ��ID */
	int     aiCrPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_IN];
		/* ��ŵҪ��ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_RELATION_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrPromiseElementRelationStruct{

	struct CrPromiseElementRelationStruct *pNext;
	int     iCrPromiseElementID;		/* ָ���ŵҪ��ID */
	int     iPromiseElementID;		/* ��ŵҪ��ID */
	struct CrPromiseElementRelationStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrPromiseElementRelationStruct{

	char    sCrPromiseElementID[6];		/* ָ���ŵҪ��ID */
	char    sPromiseElementID[6];		/* ��ŵҪ��ID */
};


/*�������ݶ�̬��CR_PROMISE_ELEMENT_RELATION���ýṹ���巽ʽȡ����*/
int EGetCrPromiseElementRelationToStruct(struct CrPromiseElementRelationStruct *p,
	struct CrPromiseElementRelationStructIn *pSource);
/**�Ա�CR_PROMISE_ELEMENT_RELATION�������ͷź���**/
void DestroyCrPromiseElementRelation(struct CrPromiseElementRelationStruct *ptHead);
int InitCrPromiseElementRelation(struct CrPromiseElementRelationStruct **pptHead);

/*����ṹ��������*/
struct CrAcctItemTypeRelationStructOut{

#ifndef CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT
#define CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT		300
#endif

	struct CrAcctItemTypeRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ָ����Ŀ����ID */
	int     aiCrAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
		/* ��Ŀ����ID */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ָ����Ŀ����ID */
	int     aiCrAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
		/* ��Ŀ����ID */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_RELATION_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrAcctItemTypeRelationStruct{

	struct CrAcctItemTypeRelationStruct *pNext;
	int     iCrAcctItemTypeID;		/* ָ����Ŀ����ID */
	int     iAcctItemTypeID;		/* ��Ŀ����ID */
	struct CrAcctItemTypeRelationStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrAcctItemTypeRelationStruct{

	char    sCrAcctItemTypeID[6];		/* ָ����Ŀ����ID */
	char    sAcctItemTypeID[6];		/* ��Ŀ����ID */
};


/*�������ݶ�̬��CR_ACCT_ITEM_TYPE_RELATION���ýṹ���巽ʽȡ����*/
int EGetCrAcctItemTypeRelationToStruct(struct CrAcctItemTypeRelationStruct *p,
	struct CrAcctItemTypeRelationStructIn *pSource);
/**�Ա�CR_ACCT_ITEM_TYPE_RELATION�������ͷź���**/
void DestroyCrAcctItemTypeRelation(struct CrAcctItemTypeRelationStruct *ptHead);
int InitCrAcctItemTypeRelation(struct CrAcctItemTypeRelationStruct **pptHead);

/*����ṹ��������*/
struct CrPatternTariffRelationStructOut{

#ifndef CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT
#define CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT		300
#endif

	struct CrPatternTariffRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ģʽID */
	int     aiPatternID[CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT];
		/* �ʷ�ID */
	int     aiTariffID[CR_PATTERN_TARIFF_RELATION_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ģʽID */
	int     aiPatternID[CR_PATTERN_TARIFF_RELATION_BUFLEN_IN];
		/* �ʷ�ID */
	int     aiTariffID[CR_PATTERN_TARIFF_RELATION_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrPatternTariffRelationStruct{

	struct CrPatternTariffRelationStruct *pNext;
	int     iPatternID;		/* ģʽID */
	int     iTariffID;		/* �ʷ�ID */
	struct CrPatternTariffRelationStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrPatternTariffRelationStruct{

	char    sPatternID[6];		/* ģʽID */
	char    sTariffID[6];		/* �ʷ�ID */
};


/*�������ݶ�̬��CR_PATTERN_TARIFF_RELATION���ýṹ���巽ʽȡ����*/
int EGetCrPatternTariffRelationToStruct(struct CrPatternTariffRelationStruct *p,
	struct CrPatternTariffRelationStructIn *pSource);
/**�Ա�CR_PATTERN_TARIFF_RELATION�������ͷź���**/
void DestroyCrPatternTariffRelation(struct CrPatternTariffRelationStruct *ptHead);
int InitCrPatternTariffRelation(struct CrPatternTariffRelationStruct **pptHead);

/*����ṹ��������*/
struct CrPromiseElementStructOut{

#ifndef CR_PROMISE_ELEMENT_BUFLEN_OUT
#define CR_PROMISE_ELEMENT_BUFLEN_OUT		300
#endif

	struct CrPromiseElementStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ָ��Ҫ��ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_BUFLEN_OUT];
		/* ��Ҫ��ID */
	int     aiParentID[CR_PROMISE_ELEMENT_BUFLEN_OUT];
		/* Ҫ������ */
	char    asName[CR_PROMISE_ELEMENT_BUFLEN_OUT][41];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_PROMISE_ELEMENT_BUFLEN_OUT][2];
		/* ��� */
	int     aiLay[CR_PROMISE_ELEMENT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ָ��Ҫ��ID */
	int     aiPromiseElementID[CR_PROMISE_ELEMENT_BUFLEN_IN];
		/* ��Ҫ��ID */
	int     aiParentID[CR_PROMISE_ELEMENT_BUFLEN_IN];
		/* Ҫ������ */
	char    asName[CR_PROMISE_ELEMENT_BUFLEN_IN][41];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_PROMISE_ELEMENT_BUFLEN_IN][2];
		/* ��� */
	int     aiLay[CR_PROMISE_ELEMENT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrPromiseElementStruct{

	struct CrPromiseElementStruct *pNext;
	int     iPromiseElementID;		/* ָ��Ҫ��ID */
	int     iParentID;		/* ��Ҫ��ID */
	char    sName[41];		/* Ҫ������ */
	char    sLeaveFlag[2];		/* Ҷ�ӱ�ʶ */
	int     iLay;		/* ��� */
	struct CrPromiseElementStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrPromiseElementStruct{

	char    sPromiseElementID[6];		/* ָ��Ҫ��ID */
	char    sParentID[6];		/* ��Ҫ��ID */
	char    sName[40];		/* Ҫ������ */
	char    sLeaveFlag[1];		/* Ҷ�ӱ�ʶ */
	char    sLay[1];		/* ��� */
};


/*�������ݶ�̬��CR_PROMISE_ELEMENT���ýṹ���巽ʽȡ����*/
int EGetCrPromiseElementToStruct(struct CrPromiseElementStruct *p,
	struct CrPromiseElementStructIn *pSource);
/**�Ա�CR_PROMISE_ELEMENT�������ͷź���**/
void DestroyCrPromiseElement(struct CrPromiseElementStruct *ptHead);
int InitCrPromiseElement(struct CrPromiseElementStruct **pptHead);

/*����ṹ��������*/
struct CrServiceTypeStructOut{

#ifndef CR_SERVICE_TYPE_BUFLEN_OUT
#define CR_SERVICE_TYPE_BUFLEN_OUT		300
#endif

	struct CrServiceTypeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ָ��ҵ������ID */
	int     aiServiceTypeID[CR_SERVICE_TYPE_BUFLEN_OUT];
		/* ��ҵ������ID */
	int     aiParentID[CR_SERVICE_TYPE_BUFLEN_OUT];
		/* ���� */
	char    asName[CR_SERVICE_TYPE_BUFLEN_OUT][81];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_SERVICE_TYPE_BUFLEN_OUT][2];
		/* ��� */
	int     aiLay[CR_SERVICE_TYPE_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ָ��ҵ������ID */
	int     aiServiceTypeID[CR_SERVICE_TYPE_BUFLEN_IN];
		/* ��ҵ������ID */
	int     aiParentID[CR_SERVICE_TYPE_BUFLEN_IN];
		/* ���� */
	char    asName[CR_SERVICE_TYPE_BUFLEN_IN][81];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_SERVICE_TYPE_BUFLEN_IN][2];
		/* ��� */
	int     aiLay[CR_SERVICE_TYPE_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrServiceTypeStruct{

	struct CrServiceTypeStruct *pNext;
	int     iServiceTypeID;		/* ָ��ҵ������ID */
	int     iParentID;		/* ��ҵ������ID */
	char    sName[81];		/* ���� */
	char    sLeaveFlag[2];		/* Ҷ�ӱ�ʶ */
	int     iLay;		/* ��� */
	struct CrServiceTypeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrServiceTypeStruct{

	char    sServiceTypeID[6];		/* ָ��ҵ������ID */
	char    sParentID[6];		/* ��ҵ������ID */
	char    sName[80];		/* ���� */
	char    sLeaveFlag[1];		/* Ҷ�ӱ�ʶ */
	char    sLay[1];		/* ��� */
};


/*�������ݶ�̬��CR_SERVICE_TYPE���ýṹ���巽ʽȡ����*/
int EGetCrServiceTypeToStruct(struct CrServiceTypeStruct *p,
	struct CrServiceTypeStructIn *pSource);
/**�Ա�CR_SERVICE_TYPE�������ͷź���**/
void DestroyCrServiceType(struct CrServiceTypeStruct *ptHead);
int InitCrServiceType(struct CrServiceTypeStruct **pptHead);

/*����ṹ��������*/
struct CrServiceImplPatternStructOut{

#ifndef CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT
#define CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT		300
#endif

	struct CrServiceImplPatternStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ģʽID */
	int     aiPatternID[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT];
		/* ��ģʽID */
	int     aiParentID[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT];
		/* ���� */
	char    asName[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT][81];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT][2];
		/* ��� */
	int     aiLay[CR_SERVICE_IMPL_PATTERN_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ģʽID */
	int     aiPatternID[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN];
		/* ��ģʽID */
	int     aiParentID[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN];
		/* ���� */
	char    asName[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN][81];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN][2];
		/* ��� */
	int     aiLay[CR_SERVICE_IMPL_PATTERN_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrServiceImplPatternStruct{

	struct CrServiceImplPatternStruct *pNext;
	int     iPatternID;		/* ģʽID */
	int     iParentID;		/* ��ģʽID */
	char    sName[81];		/* ���� */
	char    sLeaveFlag[2];		/* Ҷ�ӱ�ʶ */
	int     iLay;		/* ��� */
	struct CrServiceImplPatternStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrServiceImplPatternStruct{

	char    sPatternID[8];		/* ģʽID */
	char    sParentID[8];		/* ��ģʽID */
	char    sName[80];		/* ���� */
	char    sLeaveFlag[1];		/* Ҷ�ӱ�ʶ */
	char    sLay[1];		/* ��� */
};


/*�������ݶ�̬��CR_SERVICE_IMPL_PATTERN���ýṹ���巽ʽȡ����*/
int EGetCrServiceImplPatternToStruct(struct CrServiceImplPatternStruct *p,
	struct CrServiceImplPatternStructIn *pSource);
/**�Ա�CR_SERVICE_IMPL_PATTERN�������ͷź���**/
void DestroyCrServiceImplPattern(struct CrServiceImplPatternStruct *ptHead);
int InitCrServiceImplPattern(struct CrServiceImplPatternStruct **pptHead);

/*******************�ڶ���������*************************

�ײ�(��ŵҪ��)ָ���ϵ���ײ�(��Ŀ����)ָ���ϵ
�ײ�(ҵ������)ָ���ϵ���ײ�(ҵ��ʵ��ģʽ)ָ���ϵ

**************************************************************/
/*����ṹ��������*/
struct CrBillPromiseEleRltStructOut{

#ifndef CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT
#define CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT		300
#endif

	struct CrBillPromiseEleRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][21];
		/* ָ��Ҫ��ID */
	int     aiPromiseElementID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_IN][21];
		/* ָ��Ҫ��ID */
	int     aiPromiseElementID[CR_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrBillPromiseEleRltStruct{

	struct CrBillPromiseEleRltStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iPromiseElementID;		/* ָ��Ҫ��ID */
	struct CrBillPromiseEleRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillPromiseEleRltStruct{

	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sPromiseElementID[8];		/* ָ��Ҫ��ID */
};


/*�������ݶ�̬��CR_BILL_PROMISE_ELE_RLT���ýṹ���巽ʽȡ����*/
int EGetCrBillPromiseEleRltToStruct(struct CrBillPromiseEleRltStruct *p,
	struct CrBillPromiseEleRltStructIn *pSource);
/**�Ա�CR_BILL_PROMISE_ELE_RLT�������ͷź���**/
void DestroyCrBillPromiseEleRlt(struct CrBillPromiseEleRltStruct *ptHead);
int InitCrBillPromiseEleRlt(struct CrBillPromiseEleRltStruct **pptHead);
/*�������ݽṹ����д��CR_BILL_PROMISE_ELE_RLT*/
int EInsertStructToCrBillPromiseEleRlt(struct CrBillPromiseEleRltStruct *p,
	int iInsertFlag,struct CrBillPromiseEleRltStructOut *pTarget);
	
/*����ṹ��������*/
struct CrBillAcctItemRltStructOut{

#ifndef CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT
#define CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT		300
#endif

	struct CrBillAcctItemRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][21];
		/* ָ����Ŀ����ID */
	int     aiAcctItemTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_IN][21];
		/* ָ����Ŀ����ID */
	int     aiAcctItemTypeID[CR_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrBillAcctItemRltStruct{

	struct CrBillAcctItemRltStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iAcctItemTypeID;		/* ָ����Ŀ����ID */
	struct CrBillAcctItemRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillAcctItemRltStruct{

	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sAcctItemTypeID[8];		/* ָ����Ŀ����ID */
};


/*�������ݶ�̬��CR_BILL_ACCT_ITEM_RLT���ýṹ���巽ʽȡ����*/
int EGetCrBillAcctItemRltToStruct(struct CrBillAcctItemRltStruct *p,
	struct CrBillAcctItemRltStructIn *pSource);
/**�Ա�CR_BILL_ACCT_ITEM_RLT�������ͷź���**/
void DestroyCrBillAcctItemRlt(struct CrBillAcctItemRltStruct *ptHead);
int InitCrBillAcctItemRlt(struct CrBillAcctItemRltStruct **pptHead);
/*�������ݽṹ����д��CR_BILL_ACCT_ITEM_RLT*/
int EInsertStructToCrBillAcctItemRlt(struct CrBillAcctItemRltStruct *p,
	int iInsertFlag,struct CrBillAcctItemRltStructOut *pTarget);
/*����ṹ��������*/
struct CrBillPatternRltStructOut{

#ifndef CR_BILL_PATTERN_RLT_BUFLEN_OUT
#define CR_BILL_PATTERN_RLT_BUFLEN_OUT		300
#endif

	struct CrBillPatternRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_PATTERN_RLT_BUFLEN_OUT][21];
		/* ģʽID */
	int     aiPatternID[CR_BILL_PATTERN_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_PATTERN_RLT_BUFLEN_IN][21];
		/* ģʽID */
	int     aiPatternID[CR_BILL_PATTERN_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrBillPatternRltStruct{

	struct CrBillPatternRltStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iPatternID;		/* ģʽID */
	struct CrBillPatternRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillPatternRltStruct{

	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sPatternID[8];		/* ģʽID */
};


/*�������ݶ�̬��CR_BILL_PATTERN_RLT���ýṹ���巽ʽȡ����*/
int EGetCrBillPatternRltToStruct(struct CrBillPatternRltStruct *p,
	struct CrBillPatternRltStructIn *pSource);
/**�Ա�CR_BILL_PATTERN_RLT�������ͷź���**/
void DestroyCrBillPatternRlt(struct CrBillPatternRltStruct *ptHead);
int InitCrBillPatternRlt(struct CrBillPatternRltStruct **pptHead);
/*�������ݽṹ����д��CR_BILL_PATTERN_RLT*/
int EInsertStructToCrBillPatternRlt(struct CrBillPatternRltStruct *p,
	int iInsertFlag,struct CrBillPatternRltStructOut *pTarget);

/*����ṹ��������*/
struct CrBillServTypeRltStructOut{

#ifndef CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT
#define CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT		300
#endif

	struct CrBillServTypeRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT][21];
		/* ָ��ҵ������ID */
	int     aiServiceTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_IN][21];
		/* ָ��ҵ������ID */
	int     aiServiceTypeID[CR_BILL_SERV_TYPE_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrBillServTypeRltStruct{

	struct CrBillServTypeRltStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iServiceTypeID;		/* ָ��ҵ������ID */
	struct CrBillServTypeRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillServTypeRltStruct{

	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sServiceTypeID[8];		/* ָ��ҵ������ID */
};


/*�������ݶ�̬��CR_BILL_SERV_TYPE_RLT���ýṹ���巽ʽȡ����*/
int EGetCrBillServTypeRltToStruct(struct CrBillServTypeRltStruct *p,
	struct CrBillServTypeRltStructIn *pSource);
/**�Ա�CR_BILL_SERV_TYPE_RLT�������ͷź���**/
void DestroyCrBillServTypeRlt(struct CrBillServTypeRltStruct *ptHead);
int InitCrBillServTypeRlt(struct CrBillServTypeRltStruct **pptHead);
/*�������ݽṹ����д��CR_BILL_SERV_TYPE_RLT*/
int EInsertStructToCrBillServTypeRlt(struct CrBillServTypeRltStruct *p,
	int iInsertFlag,struct CrBillServTypeRltStructOut *pTarget);

/****************������������***************************

�û��ײ�(��ŵҪ��)ָ���ϵ���û��ײ�(��Ŀ����)ָ���ϵ
�û��ײ�(ҵ������)ָ���ϵ���û��ײ�(ҵ��ʵ��ģʽ)ָ���ϵ

*******************************************************/

/*����ṹ��������*/
struct CrUserBillPromiseEleRltStructOut{

#ifndef USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT
#define USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillPromiseEleRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �˺Ż��û����� */
	char    asAccNbr[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
		/* �ײ�ID */
	char    asBillingTypeID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][21];
		/* ָ��Ҫ��ID */
	int     aiPromiseElementID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT][2];
		/* ʹ���� */
	int     aiUsage[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
		/* Ȩ�� */
	int     aiWeight[USER_BILL_PROMISE_ELE_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �˺Ż��û����� */
	char    asAccNbr[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN][21];
		/* ָ��Ҫ��ID */
	int     aiPromiseElementID[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN][2];
		/* ʹ���� */
	int     aiUsage[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
		/* Ȩ�� */
	int     aiWeight[USER_BILL_PROMISE_ELE_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrUserBillPromiseEleRltStruct{

	struct CrUserBillPromiseEleRltStruct *pNext;
	char    sAccNbr[21];		/* �˺Ż��û����� */
	int	iSubscriptionID;	/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iPromiseElementID;		/* ָ��Ҫ��ID */
	char    sRelationType[2];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	int     iUsage;		/* ʹ���� */
	int     iWeight;		/* Ȩ�� */
	struct CrUserBillPromiseEleRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrUserBillPromiseEleRltStruct{

	char    sAccNbr[20];		/* �˺Ż��û����� */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sPromiseElementID[6];		/* ָ��Ҫ��ID */
	char    sRelationType[1];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    sUsage[9];		/* ʹ���� */
	char    sWeight[4];		/* Ȩ�� */
};


/*�������ݶ�̬��USER_BILL_PROMISE_ELE_RLT���ýṹ���巽ʽȡ����*/
int EGetUserBillPromiseEleRltToStruct(struct CrUserBillPromiseEleRltStruct *p,
	struct CrUserBillPromiseEleRltStructIn *pSource);
/**�Ա�USER_BILL_PROMISE_ELE_RLT�������ͷź���**/
void DestroyUserBillPromiseEleRlt(struct CrUserBillPromiseEleRltStruct *ptHead);
int InitUserBillPromiseEleRlt(struct CrUserBillPromiseEleRltStruct **pptHead);
/*�������ݽṹ����д��USER_BILL_PROMISE_ELE_RLT*/
int EInsertStructToUserBillPromiseEleRlt(struct CrUserBillPromiseEleRltStruct *p,
	int iInsertFlag,struct CrUserBillPromiseEleRltStructOut *pTarget);

/*����ṹ��������*/
struct CrUserBillAcctItemRltStructOut{

#ifndef CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT
#define CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillAcctItemRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �˺Ż��û����� */
	char    asAccNbr[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
		/* �ײ�ID */
	char    asBillingTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][21];
		/* ָ����Ŀ����ID */
	int     aiAcctItemTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT][2];
		/* ʹ���� */
	int     aiUsage[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
		/* Ȩ�� */
	int     aiWeight[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �˺Ż��û����� */
	char    asAccNbr[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN][21];
		/* ָ����Ŀ����ID */
	int     aiAcctItemTypeID[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN][2];
		/* ʹ���� */
	int     aiUsage[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
		/* Ȩ�� */
	int     aiWeight[CR_USER_BILL_ACCT_ITEM_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrUserBillAcctItemRltStruct{

	struct CrUserBillAcctItemRltStruct *pNext;
	char    sAccNbr[21];		/* �˺Ż��û����� */
	int	iSubscriptionID;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iAcctItemTypeID;		/* ָ����Ŀ����ID */
	char    sRelationType[2];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	int     iUsage;		/* ʹ���� */
	int     iWeight;		/* Ȩ�� */
	struct CrUserBillAcctItemRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrUserBillAcctItemRltStruct{

	char    sAccNbr[20];		/* �˺Ż��û����� */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sAcctItemTypeID[8];		/* ָ����Ŀ����ID */
	char    sRelationType[1];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    sUsage[9];		/* ʹ���� */
	char    sWeight[4];		/* Ȩ�� */
};


/*�������ݶ�̬��CR_USER_BILL_ACCT_ITEM_RLT���ýṹ���巽ʽȡ����*/
int EGetCrUserBillAcctItemRltToStruct(struct CrUserBillAcctItemRltStruct *p,
	struct CrUserBillAcctItemRltStructIn *pSource);
/**�Ա�CR_USER_BILL_ACCT_ITEM_RLT�������ͷź���**/
void DestroyCrUserBillAcctItemRlt(struct CrUserBillAcctItemRltStruct *ptHead);
int InitCrUserBillAcctItemRlt(struct CrUserBillAcctItemRltStruct **pptHead);
/*�������ݽṹ����д��CR_USER_BILL_ACCT_ITEM_RLT*/
int EInsertStructToCrUserBillAcctItemRlt(struct CrUserBillAcctItemRltStruct *p,
	int iInsertFlag,struct CrUserBillAcctItemRltStructOut *pTarget);

/*����ṹ��������*/
struct CrUserBillServiceTypeRltStructOut{

#ifndef CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT
#define CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillServiceTypeRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �˺Ż��û����� */
	char    asAccNbr[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
		/* �ײ�ID */
	char    asBillingTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT][21];
		/* ָ��ҵ������ID */
	int     aiServiceTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT][2];
		/* ʹ���� */
	int     aiUsage[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
		/* Ȩ�� */
	int     aiWeight[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �˺Ż��û����� */
	char    asAccNbr[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN][21];
		/* ָ��ҵ������ID */
	int     aiServiceTypeID[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN][2];
		/* ʹ���� */
	int     aiUsage[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
		/* Ȩ�� */
	int     aiWeight[CR_USER_BILL_SERVICE_TYPE_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrUserBillServiceTypeRltStruct{

	struct CrUserBillServiceTypeRltStruct *pNext;
	char    sAccNbr[21];		/* �˺Ż��û����� */
	int	iSubscriptionID;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iServiceTypeID;		/* ָ��ҵ������ID */
	char    sRelationType[2];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	int     iUsage;		/* ʹ���� */
	int     iWeight;		/* Ȩ�� */
	struct CrUserBillServiceTypeRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrUserBillServiceTypeRltStruct{

	char    sAccNbr[20];		/* �˺Ż��û����� */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sServiceTypeID[8];		/* ָ��ҵ������ID */
	char    sRelationType[1];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    sUsage[9];		/* ʹ���� */
	char    sWeight[4];		/* Ȩ�� */
};


/*�������ݶ�̬��CR_USER_BILL_SERVICE_TYPE_RLT���ýṹ���巽ʽȡ����*/
int EGetCrUserBillServiceTypeRltToStruct(struct CrUserBillServiceTypeRltStruct *p,
	struct CrUserBillServiceTypeRltStructIn *pSource);
/**�Ա�CR_USER_BILL_SERVICE_TYPE_RLT�������ͷź���**/
void DestroyCrUserBillServiceTypeRlt(struct CrUserBillServiceTypeRltStruct *ptHead);
int InitCrUserBillServiceTypeRlt(struct CrUserBillServiceTypeRltStruct **pptHead);
/*�������ݽṹ����д��CR_USER_BILL_SERVICE_TYPE_RLT*/
int EInsertStructToCrUserBillServiceTypeRlt(struct CrUserBillServiceTypeRltStruct *p,
	int iInsertFlag,struct CrUserBillServiceTypeRltStructOut *pTarget);

/*����ṹ��������*/
struct CrUserBillPatternRltStructOut{

#ifndef CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT
#define CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT		300
#endif

	struct CrUserBillPatternRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �˺Ż��û����� */
	char    asAccNbr[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
		/* �ײ�ID */
	char    asBillingTypeID[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT][21];
		/* ģʽID */
	int     aiPatternID[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT][2];
		/* ʹ���� */
	int     aiUsage[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
		/* Ȩ�� */
	int     aiWeight[CR_USER_BILL_PATTERN_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �˺Ż��û����� */
	char    asAccNbr[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN][21];
		/* �û�������ʶ�����Ϊ�˻��򶩹���ʶΪ0 */
	int	aiSubscriptionID[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN][21];
		/* ģʽID */
	int     aiPatternID[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    asRelationType[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN][2];
		/* ʹ���� */
	int     aiUsage[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
		/* Ȩ�� */
	int     aiWeight[CR_USER_BILL_PATTERN_RLT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrUserBillPatternRltStruct{

	struct CrUserBillPatternRltStruct *pNext;
	char    sAccNbr[21];		/* �˺Ż��û����� */
	int	iSubscriptionID;
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iPatternID;		/* ģʽID */
	char    sRelationType[2];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	int     iUsage;		/* ʹ���� */
	int     iWeight;		/* Ȩ�� */
	struct CrUserBillPatternRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrUserBillPatternRltStruct{

	char    sAccNbr[20];		/* �˺Ż��û����� */
	char	sSubscriptionID[9];
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sPatternID[8];		/* ģʽID */
	char    sRelationType[1];		/* A �˻���ϵ   M �û��ײ� ��ϵ */
	char    sUsage[9];		/* ʹ���� */
	char    sWeight[4];		/* Ȩ�� */
};


/*�������ݶ�̬��CR_USER_BILL_PATTERN_RLT���ýṹ���巽ʽȡ����*/
int EGetCrUserBillPatternRltToStruct(struct CrUserBillPatternRltStruct *p,
	struct CrUserBillPatternRltStructIn *pSource);
/**�Ա�CR_USER_BILL_PATTERN_RLT�������ͷź���**/
void DestroyCrUserBillPatternRlt(struct CrUserBillPatternRltStruct *ptHead);
int InitCrUserBillPatternRlt(struct CrUserBillPatternRltStruct **pptHead);
/*�������ݽṹ����д��CR_USER_BILL_PATTERN_RLT*/
int EInsertStructToCrUserBillPatternRlt(struct CrUserBillPatternRltStruct *p,
	int iInsertFlag,struct CrUserBillPatternRltStructOut *pTarget);


/*����ṹ��������*/
struct CrMsisdnStatStructOut{

#ifndef CR_MSISDN_STAT_BUFLEN_OUT
#define CR_MSISDN_STAT_BUFLEN_OUT		300
#endif

	struct CrMsisdnStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ͳ�Ʊ�ʶID */
	char    asCrMsisdnStatID[CR_MSISDN_STAT_BUFLEN_OUT][13];
		/* �û����� */
	char    asMsisdn[CR_MSISDN_STAT_BUFLEN_OUT][21];
		/* �û��������� */
	char    asAreaCode[CR_MSISDN_STAT_BUFLEN_OUT][10];
		/* �û�������ʶ */
	int     aiSubscriptionID[CR_MSISDN_STAT_BUFLEN_OUT];
		/* �ײ�ID */
	char    asBillingTypeID[CR_MSISDN_STAT_BUFLEN_OUT][21];
		/* ҵ������ */
	char    asServiceType[CR_MSISDN_STAT_BUFLEN_OUT][11];
		/* ָ��ID */
	int     aiIndexID[CR_MSISDN_STAT_BUFLEN_OUT];
		/* ������ */
	int     aiTotalCnt[CR_MSISDN_STAT_BUFLEN_OUT];
		/* ʹ���� */
	char    asAmount[CR_MSISDN_STAT_BUFLEN_OUT][13];
		/* ʹ�������� K ��M �ȵ� */
	char    asAmountUnit[CR_MSISDN_STAT_BUFLEN_OUT][2];
		/* �Ʒѷ��� */
	char    asCharge[CR_MSISDN_STAT_BUFLEN_OUT][13];
		/* ƽ������ */
	double  adRate[CR_MSISDN_STAT_BUFLEN_OUT];
		/* ���ʵ�λ */
	char    asRateUnit[CR_MSISDN_STAT_BUFLEN_OUT][2];
		/* (����)��λID */
	int     aiXGradeID[CR_MSISDN_STAT_BUFLEN_OUT];
		/* Ȩ��ռ�� */
	int     aiWeight[CR_MSISDN_STAT_BUFLEN_OUT];
		/* ��̯��Ϣ */
	char	asApportInfo[CR_MSISDN_STAT_BUFLEN_OUT][2001];
};


/* ����ṹ��������*/
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
		/* ͳ�Ʊ�ʶID */
	char    asCrMsisdnStatID[CR_MSISDN_STAT_BUFLEN_IN][13];
		/* �û����� */
	char    asMsisdn[CR_MSISDN_STAT_BUFLEN_IN][21];
		/* �û��������� */
	char    asAreaCode[CR_MSISDN_STAT_BUFLEN_IN][10];
		/* �û�������ʶ */
	int     aiSubscriptionID[CR_MSISDN_STAT_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[CR_MSISDN_STAT_BUFLEN_IN][21];
		/* ҵ������ */
	char    asServiceType[CR_MSISDN_STAT_BUFLEN_IN][11];
		/* ָ��ID */
	int     aiIndexID[CR_MSISDN_STAT_BUFLEN_IN];
		/* ������ */
	int     aiTotalCnt[CR_MSISDN_STAT_BUFLEN_IN];
		/* ʹ���� */
	char    asAmount[CR_MSISDN_STAT_BUFLEN_IN][13];
		/* ʹ�������� K ��M �ȵ� */
	char    asAmountUnit[CR_MSISDN_STAT_BUFLEN_IN][2];
		/* �Ʒѷ��� */
	char    asCharge[CR_MSISDN_STAT_BUFLEN_IN][13];
		/* ƽ������ */
	double  adRate[CR_MSISDN_STAT_BUFLEN_IN];
		/* ���ʵ�λ */
	char    asRateUnit[CR_MSISDN_STAT_BUFLEN_IN][2];
		/* (����)��λID */
	int     aiXGradeID[CR_MSISDN_STAT_BUFLEN_IN];
		/* Ȩ��ռ�� */
	int     aiWeight[CR_MSISDN_STAT_BUFLEN_IN];
		/* ��̯��Ϣ */
	char	asApportInfo[CR_MSISDN_STAT_BUFLEN_IN][2001];	
};


/*�����ṹ����*/
struct CrMsisdnStatStruct{

	struct CrMsisdnStatStruct *pNext;
/*	char    sCrMsisdnStatID[13];*/		/* ͳ�Ʊ�ʶID */
	char    sMsisdn[21];		/* �û����� */
	char    sAreaCode[10];		/* �û��������� */
	int     iSubscriptionID;		/* �û�������ʶ */
	char    sBillingTypeID[21];		/* �ײ�ID */
	char    sServiceType[11];		/* ҵ������ */
	int     iIndexID;		/* ָ��ID */
	int     iTotalCnt;		/* ������ */
	int	iVolume;		/* ʹ���� */
	char    sVolumeUnit[2];		/* ʹ�������� K ��M �ȵ� */
	int     iCharge;		/* �Ʒѷ��� */
	double  dRate;			/* ƽ������ */
	char    sRateUnit[2];		/* ���ʵ�λ */
	char    sXGradeID[7];		/* (����)��λID */
	char    sYGradeID[7];		/* (ʹ����)��λID */
	int     iWeight;		/* Ȩ��ռ�� */
	int	iApportFee;		/* ��̯�ķ��� */
	/*char	sApportInfo[2001];*/	/* ��̯��Ϣ */
	char	sIndexCatg[2];		/* ָ������ */
	char	sBillingTypeCatg[2];	/* ��Ʒ���� */
	
	struct CrMsisdnStatStruct *pLoadNext;
	
/*��ͳ������*/
/*	int	iAccountID;	*/	/* �˻�ID */
	int 	iAcctItemTypeID;	/* ��ĿID */
	char	sSubServiceCode[11];	/* ��ҵ������ */
	char	sApportType[2];		/* ��̯���� */
	char	cApprotFlag;		/* ̯�ֱ�ʶ */
	int	iTotalFee;		/* ͳ�Ʒ��� */
};


/*�����ļ��ṹ����*/
struct FCrMsisdnStatStruct{

	char    sCrMsisdnStatID[12];		/* ͳ�Ʊ�ʶID */
	char    sMsisdn[20];		/* �û����� */
	char    sAreaCode[9];		/* �û��������� */
	char    sSubscriptionID[9];		/* �û�������ʶ */
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sServiceType[10];		/* ҵ������ */
	char    sIndexID[4];		/* ָ��ID */
	char    sTotalCnt[9];		/* ������ */
	char    sVolume[12];		/* ʹ���� */
	char    sVolumeUnit[1];		/* ʹ�������� K ��M �ȵ� */
	char    sCharge[12];		/* �Ʒѷ��� */
	char    sRate[8];		/* ƽ������ */
	char    sRateUnit[1];		/* ���ʵ�λ */
	char    sXGradeID[6];		/* (����)��λID */
	char    sWeight[4];		/* Ȩ��ռ�� */
/*�����ֶ�*/
	char	sCfee[12];		/* ��һ���� */
	char	sLfee[12];		/* �ڶ����� */
};
/*�����ļ��ṹ����*/
struct FCrMsisdnStatStructX{

	char    sCrMsisdnStatID[12];		/* ͳ�Ʊ�ʶID */
	char    sMsisdn[20];		/* �û����� */
	char    sAreaCode[9];		/* �û��������� */
	char    sSubscriptionID[9];		/* �û�������ʶ */
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sServiceType[10];		/* ҵ������ */
	char    sIndexID[4];		/* ָ��ID */
	char    sTotalCnt[9];		/* ������ */
	char    sVolume[12];		/* ʹ���� */
	char    sVolumeUnit[1];		/* ʹ�������� K ��M �ȵ� */
	char    sCharge[12];		/* �Ʒѷ��� */
	char    sRate[9];		/* ƽ������ */
	char    sRateUnit[1];		/* ���ʵ�λ */
	char    sXGradeID[6];		/* (����)��λID */
	char    sWeight[12];		/* Ȩ��ռ�� */
	char    sApportFee[12];		/* ��̯���� */
	char    sYGradeID[6];		/* (ʹ����)��λID */
	char    sIndexCatg[1];		/* ָ������ */
	char    sBillingTypeCatg[1];		/* �ײ����� */
};



/*�������ݶ�̬��CR_MSISDN_STAT���ýṹ���巽ʽȡ����*/
int EGetCrMsisdnStatToStruct(struct CrMsisdnStatStruct *p,
	struct CrMsisdnStatStructIn *pSource);
/**�Ա�CR_MSISDN_STAT�������ͷź���**/
void DestroyCrMsisdnStat(struct CrMsisdnStatStruct *ptHead);
/*�������ݽṹ����д��CR_MSISDN_STAT*/
int EInsertStructToCrMsisdnStat(struct CrMsisdnStatStruct *p,
	int iInsertFlag,struct CrMsisdnStatStructOut *pTarget);
void mvitem_fmcrmsisdnstat(struct FCrMsisdnStatStruct *pi,struct CrMsisdnStatStruct *po);
void mvitem_mfcrmsisdnstat(struct CrMsisdnStatStruct *pi,struct FCrMsisdnStatStruct *po);
/*����ṹ��������*/
struct CrBillingTypeStatStructOut{

#ifndef CR_BILLING_TYPE_STAT_BUFLEN_OUT
#define CR_BILLING_TYPE_STAT_BUFLEN_OUT		300
#endif

	struct CrBillingTypeStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ͳ�Ʊ�ʶID */
	char    asCrBillingTypeStatID[CR_BILLING_TYPE_STAT_BUFLEN_OUT][13];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILLING_TYPE_STAT_BUFLEN_OUT][21];
		/* �ײ͹������� */
	char    asAreaCode[CR_BILLING_TYPE_STAT_BUFLEN_OUT][10];
		/* ҵ������ */
	char    asServiceType[CR_BILLING_TYPE_STAT_BUFLEN_OUT][11];
		/* ָ��ID */
	int     aiIndexID[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* ������ */
	int     aiTotalCnt[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* ʹ���� */
	char    asAmount[CR_BILLING_TYPE_STAT_BUFLEN_OUT][13];
		/* ʹ�������� K ��M �ȵ� */
	char    asAmountUnit[CR_BILLING_TYPE_STAT_BUFLEN_OUT][2];
		/* �Ʒѷ��� */
	char    asCharge[CR_BILLING_TYPE_STAT_BUFLEN_OUT][13];
		/* ƽ������ */
	double  adRate[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* ���ʵ�λ */
	char    asRateUnit[CR_BILLING_TYPE_STAT_BUFLEN_OUT][2];
		/* (����)��λID */
	int     aiXGradeID[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* (ʹ����)��λID */
	int     aiYGradeID[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
		/* Ȩ��ռ�� */
	int     aiWeight[CR_BILLING_TYPE_STAT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ͳ�Ʊ�ʶID */
	char    asCrBillingTypeStatID[CR_BILLING_TYPE_STAT_BUFLEN_IN][13];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILLING_TYPE_STAT_BUFLEN_IN][21];
		/* �ײ͹������� */
	char    asAreaCode[CR_BILLING_TYPE_STAT_BUFLEN_IN][10];
		/* ҵ������ */
	char    asServiceType[CR_BILLING_TYPE_STAT_BUFLEN_IN][11];
		/* ָ��ID */
	int     aiIndexID[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* ������ */
	int     aiTotalCnt[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* ʹ���� */
	char    asAmount[CR_BILLING_TYPE_STAT_BUFLEN_IN][13];
		/* ʹ�������� K ��M �ȵ� */
	char    asAmountUnit[CR_BILLING_TYPE_STAT_BUFLEN_IN][2];
		/* �Ʒѷ��� */
	char    asCharge[CR_BILLING_TYPE_STAT_BUFLEN_IN][13];
		/* ƽ������ */
	int     aiRate[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* ���ʵ�λ */
	char    asRateUnit[CR_BILLING_TYPE_STAT_BUFLEN_IN][2];
		/* (����)��λID */
	int     aiXGradeID[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* (ʹ����)��λID */
	int     aiYGradeID[CR_BILLING_TYPE_STAT_BUFLEN_IN];
		/* Ȩ��ռ�� */
	int     aiWeight[CR_BILLING_TYPE_STAT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrBillingTypeStatStruct{

	struct CrBillingTypeStatStruct *pNext;
	char    sCrBillingTypeStatID[13];		/* ͳ�Ʊ�ʶID */
	char    sBillingTypeID[21];		/* �ײ�ID */
	char    sAreaCode[10];		/* �ײ͹������� */
	char    sServiceType[11];		/* ҵ������ */
	int     iIndexID;		/* ָ��ID */
	int     iTotalCnt;		/* ������ */
	int     iAmount;		/* ʹ���� */
	char    sAmountUnit[2];		/* ʹ�������� K ��M �ȵ� */
	int	iCharge;		/* �Ʒѷ��� */
	double  dRate;			/* ƽ������ */
	double  dAmountRate;		/* ƽ��ʹ���� */
	char    sRateUnit[2];		/* ���ʵ�λ */
	char    sXGradeID[7];		/* (����)��λID */
	char    sYGradeID[7];		/* (ʹ����)��λID */
	int     iWeight;		/* Ȩ��ռ�� */
	int	iApportFee;		/* ̯�ֵ��ķ��� */
	int	iUserCnt;		/* �û��� */
	char	sIndexCatg[2];		/* ָ������ */
	

	struct CrBillingTypeStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillingTypeStatStruct{

	char    sCrBillingTypeStatID[12];		/* ͳ�Ʊ�ʶID */
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sAreaCode[9];		/* �ײ͹������� */
	char    sServiceType[10];		/* ҵ������ */
	char    sIndexID[4];		/* ָ��ID */
	char    sTotalCnt[9];		/* ������ */
	char    sAmount[12];		/* ʹ���� */
	char    sAmountUnit[1];		/* ʹ�������� K ��M �ȵ� */
	char    sCharge[12];		/* �Ʒѷ��� */
	char    sRate[8];		/* ƽ������ */
	char    sRateUnit[1];		/* ���ʵ�λ */
	char    sXGradeID[6];		/* (����)��λID */
	char    sYGradeID[6];		/* (ʹ����)��λID */
	char    sWeight[4];		/* Ȩ��ռ�� */
};


/*�������ݶ�̬��CR_BILLING_TYPE_STAT���ýṹ���巽ʽȡ����*/
int EGetCrBillingTypeStatToStruct(struct CrBillingTypeStatStruct *p,
	struct CrBillingTypeStatStructIn *pSource);
/**�Ա�CR_BILLING_TYPE_STAT�������ͷź���**/
void DestroyCrBillingTypeStat(struct CrBillingTypeStatStruct *ptHead);
/*�������ݽṹ����д��CR_BILLING_TYPE_STAT*/
int EInsertStructToCrBillingTypeStat(struct CrBillingTypeStatStruct *p,
	int iInsertFlag,struct CrBillingTypeStatStructOut *pTarget);

/*����ṹ��������*/
struct CrPromiseAcctRelationStructOut{

#ifndef CR_PROMISE_ACCT_RELATION_BUFLEN_OUT
#define CR_PROMISE_ACCT_RELATION_BUFLEN_OUT		300
#endif

	struct CrPromiseAcctRelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �ɳ�ŵҪ��ID */
	int     aiPromiseElementID[CR_PROMISE_ACCT_RELATION_BUFLEN_OUT];
		/* ��Ŀ����ID */
	int     aiAcctItemTypeID[CR_PROMISE_ACCT_RELATION_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �ɳ�ŵҪ��ID */
	int     aiPromiseElementID[CR_PROMISE_ACCT_RELATION_BUFLEN_IN];
		/* ��Ŀ����ID */
	int     aiAcctItemTypeID[CR_PROMISE_ACCT_RELATION_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrPromiseAcctRelationStruct{

	struct CrPromiseAcctRelationStruct *pNext;
	int     iPromiseElementID;		/* �ɳ�ŵҪ��ID */
	int     iAcctItemTypeID;		/* ��Ŀ����ID */
	struct CrPromiseAcctRelationStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrPromiseAcctRelationStruct{

	char    sPromiseElementID[4];		/* �ɳ�ŵҪ��ID */
	char    sAcctItemTypeID[6];		/* ��Ŀ����ID */
};


/*�������ݶ�̬��CR_PROMISE_ACCT_RELATION���ýṹ���巽ʽȡ����*/
int EGetCrPromiseAcctRelationToStruct(struct CrPromiseAcctRelationStruct *p,
	struct CrPromiseAcctRelationStructIn *pSource);
/**�Ա�CR_PROMISE_ACCT_RELATION�������ͷź���**/
void DestroyCrPromiseAcctRelation(struct CrPromiseAcctRelationStruct *ptHead);
int InitCrPromiseAcctRelation(struct CrPromiseAcctRelationStruct **pptHead);

/*����ṹ��������*/
struct CrAcctItemTypeStructOut{

#ifndef CR_ACCT_ITEM_TYPE_BUFLEN_OUT
#define CR_ACCT_ITEM_TYPE_BUFLEN_OUT		300
#endif

	struct CrAcctItemTypeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_BUFLEN_OUT];
		/* ���� */
	char    asAcctItemName[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][61];
		/* ҵ������ */
	char    asServiceType[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][5];
		/* cr_��ҵ������ */
	char    asSubServiceCode[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][9];
		/* ��̯���� A :ֱ�ӶԵ�һ��ָ�� B:ֱ�ӶԵ����ָ�� C:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ��  D:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ�� */
	char    asApportionType[CR_ACCT_ITEM_TYPE_BUFLEN_OUT][2];
		/* ��̯���ȼ� */
	int     aiPriority[CR_ACCT_ITEM_TYPE_BUFLEN_OUT];
		/* ������Դ�ֶ���� */
	int     aiFeeSeq[CR_ACCT_ITEM_TYPE_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_ACCT_ITEM_TYPE_BUFLEN_IN];
		/* ���� */
	char    asAcctItemName[CR_ACCT_ITEM_TYPE_BUFLEN_IN][61];
		/* ҵ������ */
	char    asServiceType[CR_ACCT_ITEM_TYPE_BUFLEN_IN][5];
		/* cr_��ҵ������ */
	char    asSubServiceCode[CR_ACCT_ITEM_TYPE_BUFLEN_IN][9];
		/* ��̯���� A :ֱ�ӶԵ�һ��ָ�� B:ֱ�ӶԵ����ָ�� C:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ��  D:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ�� */
	char    asApportionType[CR_ACCT_ITEM_TYPE_BUFLEN_IN][2];
		/* ��̯���ȼ� */
	int     aiPriority[CR_ACCT_ITEM_TYPE_BUFLEN_IN];
		/* ������Դ�ֶ���� */
	int     aiFeeSeq[CR_ACCT_ITEM_TYPE_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrAcctItemTypeStruct{

	struct CrAcctItemTypeStruct *pNext;
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	char    sAcctItemName[61];		/* ���� */
	char    sServiceType[5];		/* ҵ������ */
	char    sSubServiceCode[9];		/* cr_��ҵ������ */
	char    sApportionType[2];		/* ��̯���� A :ֱ�ӶԵ�һ��ָ�� B:ֱ�ӶԵ����ָ�� C:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ��  D:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ�� */
	int     iPriority;		/* ��̯���ȼ� */
	int     iFeeSeq;		/* ������Դ�ֶ���� */
	struct CrAcctItemTypeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrAcctItemTypeStruct{

	char    sAcctItemTypeID[6];		/* ��Ŀ���ͱ�ʶ */
	char    sAcctItemName[60];		/* ���� */
	char    sServiceType[4];		/* ҵ������ */
	char    sSubServiceCode[8];		/* cr_��ҵ������ */
	char    sApportionType[1];		/* ��̯���� A :ֱ�ӶԵ�һ��ָ�� B:ֱ�ӶԵ����ָ�� C:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ��  D:(��ҵ��)��Ҫ����ײͲ���ȷ�����Ե�ָ�� */
	char    sPriority[2];		/* ��̯���ȼ� */
	char    sFeeSeq[1];		/* ������Դ�ֶ���� */
};


/*�������ݶ�̬��CR_ACCT_ITEM_TYPE���ýṹ���巽ʽȡ����*/
int EGetCrAcctItemTypeToStruct(struct CrAcctItemTypeStruct *p,
	struct CrAcctItemTypeStructIn *pSource);
/**�Ա�CR_ACCT_ITEM_TYPE�������ͷź���**/
void DestroyCrAcctItemType(struct CrAcctItemTypeStruct *ptHead);
int InitCrAcctItemType(struct CrAcctItemTypeStruct **pptHead);

/*����ṹ��������*/
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


/* ����ṹ��������*/
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


/*�����ṹ����*/
struct CrSubServiceCodeStruct{

	struct CrSubServiceCodeStruct *pNext;
	int     iSubServiceID;
	char    sSubServiceCode[9];
	char    sName[31];
	char    sServiceType[5];
	struct CrSubServiceCodeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrSubServiceCodeStruct{

	char    sSubServiceID[4];
	char    sSubServiceCode[8];
	char    sName[30];
	char    sServiceType[4];
};


/*�������ݶ�̬��CR_SUB_SERVICE_CODE���ýṹ���巽ʽȡ����*/
int EGetCrSubServiceCodeToStruct(struct CrSubServiceCodeStruct *p,
	struct CrSubServiceCodeStructIn *pSource);
/**�Ա�CR_SUB_SERVICE_CODE�������ͷź���**/
void DestroyCrSubServiceCode(struct CrSubServiceCodeStruct *ptHead);
int InitCrSubServiceCode(struct CrSubServiceCodeStruct **pptHead);


/*����ṹ��������*/
struct CrAcctIndexRltStructOut{

#ifndef CR_ACCT_INDEX_RLT_BUFLEN_OUT
#define CR_ACCT_INDEX_RLT_BUFLEN_OUT		300
#endif

	struct CrAcctIndexRltStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
		/* ָ��Ҫ��ID */
	int     aiIndexID[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceType[CR_ACCT_INDEX_RLT_BUFLEN_OUT][5];
		/* ��ҵ������ */
	char    asSubServiceCode[CR_ACCT_INDEX_RLT_BUFLEN_OUT][9];
		/* ��̯���� */
	char    asApportionType[CR_ACCT_INDEX_RLT_BUFLEN_OUT][2];
		/* ������Դ�ֶ���� */
	int     aiFeeSeq[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
		/* ��̯���� */
	int	aiPercent[CR_ACCT_INDEX_RLT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_ACCT_INDEX_RLT_BUFLEN_IN];
		/* ָ��Ҫ��ID */
	int     aiIndexID[CR_ACCT_INDEX_RLT_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceType[CR_ACCT_INDEX_RLT_BUFLEN_IN][5];
		/* ��ҵ������ */
	char    asSubServiceCode[CR_ACCT_INDEX_RLT_BUFLEN_IN][9];
		/* ��̯���� */
	char    asApportionType[CR_ACCT_INDEX_RLT_BUFLEN_IN][2];
		/* ������Դ�ֶ���� */
	int     aiFeeSeq[CR_ACCT_INDEX_RLT_BUFLEN_IN];
		/* ��̯���� */
	int	aiPercent[CR_ACCT_INDEX_RLT_BUFLEN_IN];
};



/*�����ṹ����*/
struct CrAcctIndexRltStruct{

	struct CrAcctIndexRltStruct *pNext;
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	int     iIndexID;		/* ָ��Ҫ��ID */
	int	iPercent;		/* ��̯���� */
/*��չ�ֶ�*/
	int	iIndexAmount;		/* ָ���������Ŀ�µ�ʹ���� */
	int	iIndexFee;		/* ָ���������Ŀ�µķ����� */
	struct CrAcctIndexRltStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrAcctIndexRltStruct{

	char    sAcctItemTypeID[6];		/* ��Ŀ���ͱ�ʶ */
	char    sIndexID[4];		/* ָ��Ҫ��ID */
	char    sServiceType[4];		/* ҵ������ */
	char    sSubServiceCode[8];		/* ��ҵ������ */
	char    sApportionType[1];		/* ��̯���� */
	char    sFeeSeq[1];		/* ������Դ�ֶ���� */
	char	sPercent[3];
};

/*�������ݶ�̬��CR_ACCT_INDEX_RLT���ýṹ���巽ʽȡ����*/
int EGetCrAcctIndexRltToStruct(struct CrAcctIndexRltStruct *p,
	struct CrAcctIndexRltStructIn *pSource);
/**�Ա�CR_ACCT_INDEX_RLT�������ͷź���**/
void DestroyCrAcctIndexRlt(struct CrAcctIndexRltStruct *ptHead);
int InitCrAcctIndexRlt(struct CrAcctIndexRltStruct **pptHead);

/*��ȡCR_MSISDN_STAT_SEQ���к�*/
int GetCrMsisdnStatSeq();
/*��ȡCR_BILL_TYPE_STAT_SEQ���к�*/
int GetCrBillingTypeStatSeq();


/*����ṹ��������*/
struct CrIndexGradeDescStructOut{

#ifndef CR_INDEX_GRADE_DESC_BUFLEN_OUT
#define CR_INDEX_GRADE_DESC_BUFLEN_OUT		300
#endif

	struct CrIndexGradeDescStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��λID */
	char    asGradeID[CR_INDEX_GRADE_DESC_BUFLEN_OUT][7];
		/* ���� */
	char    asName[CR_INDEX_GRADE_DESC_BUFLEN_OUT][61];
		/* ˵�� */
	char    asRemark[CR_INDEX_GRADE_DESC_BUFLEN_OUT][501];
		/* ָ��Ҫ��ID */
	int     aiIndexID[CR_INDEX_GRADE_DESC_BUFLEN_OUT];
		/* 'S'ҵ�����ȼ���'R'���ʵȼ� */
	char    asType[CR_INDEX_GRADE_DESC_BUFLEN_OUT][2];
		/* ��ʼֵ */
	int     aiBgnVal[CR_INDEX_GRADE_DESC_BUFLEN_OUT];
		/* ��ֵֹ */
	int     aiEndVal[CR_INDEX_GRADE_DESC_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ��λID */
	char    asGradeID[CR_INDEX_GRADE_DESC_BUFLEN_IN][7];
		/* ���� */
	char    asName[CR_INDEX_GRADE_DESC_BUFLEN_IN][61];
		/* ˵�� */
	char    asRemark[CR_INDEX_GRADE_DESC_BUFLEN_IN][501];
		/* ָ��Ҫ��ID */
	int     aiIndexID[CR_INDEX_GRADE_DESC_BUFLEN_IN];
		/* 'S'ҵ�����ȼ���'R'���ʵȼ� */
	char    asType[CR_INDEX_GRADE_DESC_BUFLEN_IN][2];
		/* ��ʼֵ */
	int     aiBgnVal[CR_INDEX_GRADE_DESC_BUFLEN_IN];
		/* ��ֵֹ */
	int     aiEndVal[CR_INDEX_GRADE_DESC_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrIndexGradeDescStruct{

	struct CrIndexGradeDescStruct *pNext;
	char    sGradeID[7];		/* ��λID */
	char    sName[61];		/* ���� */
	char    sRemark[501];		/* ˵�� */
	int     iIndexID;		/* ָ��Ҫ��ID */
	char    sType[2];		/* 'S'ҵ�����ȼ���'R'���ʵȼ� */
	int     iBgnVal;		/* ��ʼֵ */
	int     iEndVal;		/* ��ֵֹ */
	struct CrIndexGradeDescStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrIndexGradeDescStruct{

	char    sGradeID[6];		/* ��λID */
	char    sName[60];		/* ���� */
	char    sRemark[500];		/* ˵�� */
	char    sIndexID[4];		/* ָ��Ҫ��ID */
	char    sType[1];		/* 'S'ҵ�����ȼ���'R'���ʵȼ� */
	char    sBgnVal[9];		/* ��ʼֵ */
	char    sEndVal[9];		/* ��ֵֹ */
};


/*�������ݶ�̬��CR_INDEX_GRADE_DESC���ýṹ���巽ʽȡ����*/
int EGetCrIndexGradeDescToStruct(struct CrIndexGradeDescStruct *p,
	struct CrIndexGradeDescStructIn *pSource);
/**�Ա�CR_INDEX_GRADE_DESC�������ͷź���**/
void DestroyCrIndexGradeDesc(struct CrIndexGradeDescStruct *ptHead);
int InitCrIndexGradeDesc(struct CrIndexGradeDescStruct **pptHead);

/*����ṹ��������*/
struct CrBillTypeAcctApprStructOut{

#ifndef CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT
#define CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT		300
#endif

	struct CrBillTypeAcctApprStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT][21];
		/* ��̯��ʶ */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* 'P' ��ҵ����������̯,'S'�ֹ����÷�̯����,'E'��ʽ�ƶ� */
	char    asMethod[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT][5];
		/* ������ */
	char    asParamStr[CR_BILL_TYPE_ACCT_APPR_BUFLEN_OUT][121];
};


/* ����ṹ��������*/
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
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN][21];
		/* ��̯��ʶ */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN];
		/* 'P' ��ҵ����������̯,'S'�ֹ����÷�̯����,'E'��ʽ�ƶ� */
	char    asMethod[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN][5];
		/* ������ */
	char    asParamStr[CR_BILL_TYPE_ACCT_APPR_BUFLEN_IN][121];
};


/*�����ṹ����*/
struct CrBillTypeAcctApprStruct{

	struct CrBillTypeAcctApprStruct *pNext;
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	char    sBillingTypeID[21];		/* �ײ�ID */
	int     iApprID;		/* ��̯��ʶ */
	char    sMethod[5];		/* 'P' ��ҵ����������̯,'S'�ֹ����÷�̯����,'E'��ʽ�ƶ� */
	char    sParamStr[121];		/* ������ */
	struct CrBillTypeAcctApprStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillTypeAcctApprStruct{

	char    sAcctItemTypeID[6];		/* ��Ŀ���ͱ�ʶ */
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sApprID[6];		/* ��̯��ʶ */
	char    sMethod[4];		/* 'P' ��ҵ����������̯,'S'�ֹ����÷�̯����,'E'��ʽ�ƶ� */
	char    sParamStr[120];		/* ������ */
};


/*�������ݶ�̬��CR_BILL_TYPE_ACCT_APPR���ýṹ���巽ʽȡ����*/
int EGetCrBillTypeAcctApprToStruct(struct CrBillTypeAcctApprStruct *p,
	struct CrBillTypeAcctApprStructIn *pSource);
/**�Ա�CR_BILL_TYPE_ACCT_APPR�������ͷź���**/
void DestroyCrBillTypeAcctAppr(struct CrBillTypeAcctApprStruct *ptHead);
int InitCrBillTypeAcctAppr(struct CrBillTypeAcctApprStruct **pptHead);

/*����ṹ��������*/
struct CrBillTypeAcctApprParamStructOut{

#ifndef CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT
#define CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT		300
#endif

	struct CrBillTypeAcctApprParamStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ָ���ʶ */
	int     aiIndexID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* ��̯��ʶ */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* ��̯���� */
	int     aiPercent[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ָ���ʶ */
	int     aiIndexID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* ��̯��ʶ */
	int     aiApprID[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* ��̯���� */
	int     aiPercent[CR_BILL_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrBillTypeAcctApprParamStruct{

	struct CrBillTypeAcctApprParamStruct *pNext;
	int     iIndexID;		/* ָ���ʶ */
	int     iApprID;		/* ��̯��ʶ */
	int     iPercent;		/* ��̯���� */
	
/*��չ��Ҫ*/
	int	iTotalFee;		/* �Ʒѷ��� */
	int	iTotalAmount;		/* �Ʒ�ʹ���� */
	char	cLastFlag;		/*���һ������,����������,'0'Ϊ�������һ����'1'Ϊ���һ��*/
	struct CrBillTypeAcctApprParamStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillTypeAcctApprParamStruct{

	char    sIndexID[4];		/* ָ���ʶ */
	char    sApprID[6];		/* ��̯��ʶ */
	char    sPercent[3];		/* ��̯���� */
};


/*�������ݶ�̬��CR_BILL_TYPE_ACCT_APPR_PARAM���ýṹ���巽ʽȡ����*/
int EGetCrBillTypeAcctApprParamToStruct(struct CrBillTypeAcctApprParamStruct *p,
	struct CrBillTypeAcctApprParamStructIn *pSource);
/**�Ա�CR_BILL_TYPE_ACCT_APPR_PARAM�������ͷź���**/
void DestroyCrBillTypeAcctApprParam(struct CrBillTypeAcctApprParamStruct *ptHead);
int InitCrBillTypeAcctApprParam(struct CrBillTypeAcctApprParamStruct **pptHead);

/*����ṹ��������*/
struct CrServiceTypeAcctApprStructOut{

#ifndef CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT
#define CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT		300
#endif

	struct CrServiceTypeAcctApprStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	int     aiServiceApprID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT];
		/* �ײ�ID */
	char    asBillingTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT][21];
		/* P:��������̯ V:������ֵ��̯ */
	char    asMethod[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
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
		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	int     aiServiceApprID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN];
		/* �ײ�ID */
	char    asBillingTypeID[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN][21];
		/* P:��������̯ V:������ֵ��̯ */
	char    asMethod[CR_SERVICE_TYPE_ACCT_APPR_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct CrServiceTypeAcctApprStruct{

	struct CrServiceTypeAcctApprStruct *pNext;
	int     iServiceApprID;		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	char    sBillingTypeID[21];		/* �ײ�ID */
	char    sMethod[2];		/* P:��������̯ V:������ֵ��̯ */
	
	struct CrServiceTypeAcctApprStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrServiceTypeAcctApprStruct{

	char    sServiceApprID[4];		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	char    sAcctItemTypeID[6];		/* ��Ŀ���ͱ�ʶ */
	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sMethod[1];		/* P:��������̯ V:������ֵ��̯ */
};


/*�������ݶ�̬��CR_SERVICE_TYPE_ACCT_APPR���ýṹ���巽ʽȡ����*/
int EGetCrServiceTypeAcctApprToStruct(struct CrServiceTypeAcctApprStruct *p,
	struct CrServiceTypeAcctApprStructIn *pSource);
/**�Ա�CR_SERVICE_TYPE_ACCT_APPR�������ͷź���**/
void DestroyCrServiceTypeAcctAppr(struct CrServiceTypeAcctApprStruct *ptHead);
int InitCrServiceTypeAcctAppr(struct CrServiceTypeAcctApprStruct **pptHead);

/*����ṹ��������*/
struct CrServTypeAcctApprParamStructOut{

#ifndef CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT
#define CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT		300
#endif

	struct CrServTypeAcctApprParamStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	int     aiServiceApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* ��̯��ʶ */
	int     aiApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceType[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT][5];
		/* ��ֵ̯(����) */
	int     aiValue[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	int     aiServiceApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* ��̯��ʶ */
	int     aiApprID[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceType[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN][5];
		/* ��ֵ̯(����) */
	int     aiValue[CR_SERV_TYPE_ACCT_APPR_PARAM_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrServTypeAcctApprParamStruct{

	struct CrServTypeAcctApprParamStruct *pNext;
	int     iServiceApprID;		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	int     iApprID;		/* ��̯��ʶ */
	char    sServiceType[5];		/* ҵ������ */
	int     iValue;		/* ��ֵ̯(����) */
	
/*��չ�ֶ�*/
	int	iCharge;	/*ҵ��Ӫ�ʷ���*/
	int	iAmount;	/*ҵ��ʹ����*/
	int	iTotalFee;		/*����̯�������ҵ����ܷ���*/
	char	cLastFlag;		/*���һ������,����������,'0'Ϊ�������һ����'1'Ϊ���һ��*/
	struct CrServTypeAcctApprParamStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrServTypeAcctApprParamStruct{

	char    sServiceApprID[4];		/* ��Ŀ��̯��ҵ��ķ���(��̯��ҵ��,Ȼ��Ը�ҵ����̯��ָ��) */
	char    sApprID[6];		/* ��̯��ʶ */
	char    sServiceType[4];		/* ҵ������ */
	char    sValue[8];		/* ��ֵ̯(����) */
};


/*�������ݶ�̬��CR_SERV_TYPE_ACCT_APPR_PARAM���ýṹ���巽ʽȡ����*/
int EGetCrServTypeAcctApprParamToStruct(struct CrServTypeAcctApprParamStruct *p,
	struct CrServTypeAcctApprParamStructIn *pSource);
/**�Ա�CR_SERV_TYPE_ACCT_APPR_PARAM�������ͷź���**/
void DestroyCrServTypeAcctApprParam(struct CrServTypeAcctApprParamStruct *ptHead);
int InitCrServTypeAcctApprParam(struct CrServTypeAcctApprParamStruct **pptHead);

/*����ṹ��������*/
struct CrServiceIndexStructOut{

#ifndef CR_SERVICE_INDEX_BUFLEN_OUT
#define CR_SERVICE_INDEX_BUFLEN_OUT		300
#endif

	struct CrServiceIndexStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ָ��Ҫ��ID */
	int     aiIndexID[CR_SERVICE_INDEX_BUFLEN_OUT];
		/* ����ҵ������ */
	char    asName[CR_SERVICE_INDEX_BUFLEN_OUT][41];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_SERVICE_INDEX_BUFLEN_OUT][2];
		/* ��� */
	int     aiLay[CR_SERVICE_INDEX_BUFLEN_OUT];
		/* ��ָ��Ҫ��ID */
	int     aiParentID[CR_SERVICE_INDEX_BUFLEN_OUT];
		/* ҵ������ */
	char    asServiceType[CR_SERVICE_INDEX_BUFLEN_OUT][5];
		/* '0'��һ��ָ�� 'X'����ָ�� */
	char    asType[CR_SERVICE_INDEX_BUFLEN_OUT][2];
		/* �ο�PROMISE_ELEMENT.RATE_UNIT�ֶ�ȡֵ */
	char    asUnit[CR_SERVICE_INDEX_BUFLEN_OUT][2];
		/* CATG='F'��ʾ��̯���ã�CATG��'D'��ʾ���嵥ͳ��ҵ���� */
	char	asCatg[CR_SERVICE_INDEX_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
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
		/* ָ��Ҫ��ID */
	int     aiIndexID[CR_SERVICE_INDEX_BUFLEN_IN];
		/* ����ҵ������ */
	char    asName[CR_SERVICE_INDEX_BUFLEN_IN][41];
		/* Ҷ�ӱ�ʶ */
	char    asLeaveFlag[CR_SERVICE_INDEX_BUFLEN_IN][2];
		/* ��� */
	int     aiLay[CR_SERVICE_INDEX_BUFLEN_IN];
		/* ��ָ��Ҫ��ID */
	int     aiParentID[CR_SERVICE_INDEX_BUFLEN_IN];
		/* ҵ������ */
	char    asServiceType[CR_SERVICE_INDEX_BUFLEN_IN][5];
		/* '0'��һ��ָ�� 'X'����ָ�� */
	char    asType[CR_SERVICE_INDEX_BUFLEN_IN][2];
		/* �ο�PROMISE_ELEMENT.RATE_UNIT�ֶ�ȡֵ */
	char    asUnit[CR_SERVICE_INDEX_BUFLEN_IN][2];
		/* CATG='F'��ʾ��̯���ã�CATG��'D'��ʾ���嵥ͳ��ҵ���� */
	char	asCatg[CR_SERVICE_INDEX_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct CrServiceIndexStruct{

	struct CrServiceIndexStruct *pNext;
	int     iIndexID;		/* ָ��Ҫ��ID */
	char    sName[41];		/* ����ҵ������ */
	char    sLeaveFlag[2];		/* Ҷ�ӱ�ʶ */
	int     iLay;		/* ��� */
	int     iParentID;		/* ��ָ��Ҫ��ID */
	char    sServiceType[5];		/* ҵ������ */
	char    sType[2];		/* '0'��һ��ָ�� 'X'����ָ�� */
	char    sUnit[2];		/* �ο�PROMISE_ELEMENT.RATE_UNIT�ֶ�ȡֵ */
	char	sCatg[2];		/* CATG='F'��ʾ��̯���ã�CATG��'D'��ʾ���嵥ͳ��ҵ���� */
	struct CrServiceIndexStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrServiceIndexStruct{

	char    sIndexID[4];		/* ָ��Ҫ��ID */
	char    sName[40];		/* ����ҵ������ */
	char    sLeaveFlag[1];		/* Ҷ�ӱ�ʶ */
	char    sLay[1];		/* ��� */
	char    sParentID[4];		/* ��ָ��Ҫ��ID */
	char    sServiceType[4];		/* ҵ������ */
	char    sType[1];		/* '0'��һ��ָ�� 'X'����ָ�� */
	char    sUnit[1];		/* �ο�PROMISE_ELEMENT.RATE_UNIT�ֶ�ȡֵ */
	char	sCatg[1];		/* CATG='F'��ʾ��̯���ã�CATG��'D'��ʾ���嵥ͳ��ҵ���� */
};


/*�������ݶ�̬��CR_SERVICE_INDEX���ýṹ���巽ʽȡ����*/
int EGetCrServiceIndexToStruct(struct CrServiceIndexStruct *p,
	struct CrServiceIndexStructIn *pSource);
/**�Ա�CR_SERVICE_INDEX�������ͷź���**/
void DestroyCrServiceIndex(struct CrServiceIndexStruct *ptHead);
int InitCrServiceIndex(struct CrServiceIndexStruct **pptHead);

/*����ṹ��������*/
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


/* ����ṹ��������*/
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


/*�����ṹ����*/
struct CrPackageTariffIDStruct{

	struct CrPackageTariffIDStruct *pNext;
	char    sBillingTypeID[21];
	char    sServiceType[5];
	int     iTariffID;
	struct CrPackageTariffIDStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrPackageTariffIDStruct{

	char    sBillingTypeID[20];
	char    sServiceType[4];
	char    sTariffID[6];
};


/*�������ݶ�̬��CR_PACKAGE_TARIFF_ID���ýṹ���巽ʽȡ����*/
int EGetCrPackageTariffIDToStruct(struct CrPackageTariffIDStruct *p,
	struct CrPackageTariffIDStructIn *pSource);
/**�Ա�CR_PACKAGE_TARIFF_ID�������ͷź���**/
void DestroyCrPackageTariffID(struct CrPackageTariffIDStruct *ptHead);
int InitCrPackageTariffID(struct CrPackageTariffIDStruct **pptHead);

/*����ṹ��������*/
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


/* ����ṹ��������*/
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


/*�����ṹ����*/
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
	
/*��չ����*/
	double	dServicePct;	/*����ҵ��ı���*/
	double  dServiceIncPct;	/*ָ��ռ���ҵ���ڵı���*/
	double	iVolume;
	double	iApportFee;
	int	iUserCnt;
	double dCorrelationCoefficent;/*����ײ����ָ�������λ�������ϵ��*/
	double dAvg_w;/*ƽ��Ȩ��*/
	
	struct CrIndexYGradeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
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


/*�������ݶ�̬��CR_INDEX_Y_GRADE���ýṹ���巽ʽȡ����*/
int EGetCrIndexYGradeToStruct(struct CrIndexYGradeStruct *p,
	struct CrIndexYGradeStructIn *pSource);
/**�Ա�CR_INDEX_Y_GRADE�������ͷź���**/
void DestroyCrIndexYGrade(struct CrIndexYGradeStruct *ptHead);
int InitCrIndexYGrade(struct CrIndexYGradeStruct **pptHead);

/*����ṹ��������*/
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


/* ����ṹ��������*/
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


/*�����ṹ����*/
struct CrIndexXGradeStruct{

	struct CrIndexXGradeStruct *pNext;
	char    sBillingTypeID[21];
	char    sServiceType[11];
	int     iIndexID;
	char    sIndexUnit[2];
	char    sXGradeID[7];
	double  dUsrPct;
	double  dIncPct;/*ָ��ռ�����ײ͵ı���*/
	double  dAvgVolume;
	char    sCatg[2];
	double  dAvgRate;
	char	sAreaCode[11];
	
/*��չ�ֶ�*/
	double	dServicePct;	/*����ҵ��ı���*/
	double  dServiceIncPct;	/*ָ��ռ���ҵ���ڵı���*/
	double iVolume;
	double iApportFee;
	int iUserCnt;
	double dCorrelationCoefficent;/*����ײ����ָ�������λ�������ϵ��*/
	double dAvg_w;/*ƽ��Ȩ��*/
	
	struct CrIndexXGradeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
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



/*�������ݶ�̬��CR_INDEX_X_GRADE���ýṹ���巽ʽȡ����*/
int EGetCrIndexXGradeToStruct(struct CrIndexXGradeStruct *p,
	struct CrIndexXGradeStructIn *pSource);
/**�Ա�CR_INDEX_X_GRADE�������ͷź���**/
void DestroyCrIndexXGrade(struct CrIndexXGradeStruct *ptHead);
int InitCrIndexXGrade(struct CrIndexXGradeStruct **pptHead);

/*����ṹ��������*/
struct CrBillingTypeCorrelationStructOut{

#ifndef CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT
#define CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT		300
#endif

	struct CrBillingTypeCorrelationStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ����Ҫ��: C1111 */
	char    asTaskID[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][6];
		/* �ײ�ID������ײ�ID����ͬ�������ײͻ����ײ� */
	char    asBillingTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][21];
		/* ����ײ�ID */
	char    asCorrelationTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][21];
		/* �ײ����� */
	char    asCatg[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][2];
		/* �û������� */
	char    asAreaCode[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][10];
		/* R�ͻ����ʸ�֪���,P�ͻ�����ϰ����� */
	char    asCorrelationType[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT][2];
		/* ���ϵ��ȡֵ��Χ��0-1,����ʾ����أ�1��ʾȫ��ء� */
	double  adCorrelationCoefficent[CR_BILLING_TYPE_CORRELATION_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* ����Ҫ��: C1111 */
	char    asTaskID[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][6];
		/* �ײ�ID������ײ�ID����ͬ�������ײͻ����ײ� */
	char    asBillingTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][21];
		/* ����ײ�ID */
	char    asCorrelationTypeID[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][21];
		/* �ײ����� */
	char    asCatg[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][2];
		/* �û������� */
	char    asAreaCode[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][10];
		/* R�ͻ����ʸ�֪���,P�ͻ�����ϰ����� */
	char    asCorrelationType[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN][2];
		/* ���ϵ��ȡֵ��Χ��0-1,����ʾ����أ�1��ʾȫ��ء� */
	double  adCorrelationCoefficent[CR_BILLING_TYPE_CORRELATION_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrBillingTypeCorrelationStruct{

	struct CrBillingTypeCorrelationStruct *pNext;
	char    sTaskID[6];		/* ����Ҫ��: C1111 */
	char    sBillingTypeID[21];		/* �ײ�ID������ײ�ID����ͬ�������ײͻ����ײ� */
	char    sCorrelationTypeID[21];		/* ����ײ�ID */
	char    sCatg[2];		/* �ײ����� */
	char    sAreaCode[10];		/* �û������� */
	char    sCorrelationType[2];		/* R�ͻ����ʸ�֪���,P�ͻ�����ϰ����� */
	double  dCorrelationCoefficent;		/* ���ϵ��ȡֵ��Χ��0-1,����ʾ����أ�1��ʾȫ��ء� */
	char	sCorGrade[2];
	char	sCorInfo[2001];
	struct CrBillingTypeCorrelationStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrBillingTypeCorrelationStruct{

	char    sTaskID[5];		/* ����Ҫ��: C1111 */
	char    sBillingTypeID[20];		/* �ײ�ID������ײ�ID����ͬ�������ײͻ����ײ� */
	char    sCorrelationTypeID[20];		/* ����ײ�ID */
	char    sCatg[1];		/* �ײ����� */
	char    sAreaCode[9];		/* �û������� */
	char    sCorrelationType[1];		/* R�ͻ����ʸ�֪���,P�ͻ�����ϰ����� */
	char    sCorrelationCoefficent[3];		/* ���ϵ��ȡֵ��Χ��0-1,����ʾ����أ�1��ʾȫ��ء� */
};


/*�������ݶ�̬��CR_BILLING_TYPE_CORRELATION���ýṹ���巽ʽȡ����*/
int EGetCrBillingTypeCorrelationToStruct(struct CrBillingTypeCorrelationStruct *p,
	struct CrBillingTypeCorrelationStructIn *pSource);
/**�Ա�CR_BILLING_TYPE_CORRELATION�������ͷź���**/
void DestroyCrBillingTypeCorrelation(struct CrBillingTypeCorrelationStruct *ptHead);
int InitCrBillingTypeCorrelation(struct CrBillingTypeCorrelationStruct **pptHead);


/*����ṹ��������*/
struct BillingTypeStructOut{

#ifndef BILLING_TYPE_BUFLEN_OUT
#define BILLING_TYPE_BUFLEN_OUT		300
#endif

	struct BillingTypeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �ײ�ID */
	char    asBillingTypeID[BILLING_TYPE_BUFLEN_OUT][21];
		/* �ײ�ģ��ID */
	char    asTemplateID[BILLING_TYPE_BUFLEN_OUT][21];
		/* �ײ����� */
	char    asRemark[BILLING_TYPE_BUFLEN_OUT][61];
		/* ����,'B'��ʾ����Ʒ�ײ�,'b'��ʾ�Ӳ�Ʒ�ײ�,'S'��ʾҵ��Ʒ��,'v'��ʾ VPN��� */
	char    asCatg[BILLING_TYPE_BUFLEN_OUT][2];
		/* ҵ��Ʒ�� */
	char    asServTypeID[BILLING_TYPE_BUFLEN_OUT][21];
		/* ʵ��ģʽ(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    asImplPattern[BILLING_TYPE_BUFLEN_OUT][5];
		/* ����ҵ��(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    asAffectService[BILLING_TYPE_BUFLEN_OUT][5];
		/* ���۷�ʽ(T�����嵥���۹���,M�嵥�����������,D���������Żݹ���) */
	char    asMethod[BILLING_TYPE_BUFLEN_OUT][2];
};


/* ����ṹ��������*/
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
		/* �ײ�ID */
	char    asBillingTypeID[BILLING_TYPE_BUFLEN_IN][21];
		/* �ײ�ģ��ID */
	char    asTemplateID[BILLING_TYPE_BUFLEN_IN][21];
		/* �ײ����� */
	char    asRemark[BILLING_TYPE_BUFLEN_IN][61];
		/* ����,'B'��ʾ����Ʒ�ײ�,'b'��ʾ�Ӳ�Ʒ�ײ�,'S'��ʾҵ��Ʒ��,'v'��ʾ VPN��� */
	char    asCatg[BILLING_TYPE_BUFLEN_IN][2];
		/* ҵ��Ʒ�� */
	char    asServTypeID[BILLING_TYPE_BUFLEN_IN][21];
		/* ʵ��ģʽ(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    asImplPattern[BILLING_TYPE_BUFLEN_IN][5];
		/* ����ҵ��(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    asAffectService[BILLING_TYPE_BUFLEN_IN][5];
		/* ���۷�ʽ(T�����嵥���۹���,M�嵥�����������,D���������Żݹ���) */
	char    asMethod[BILLING_TYPE_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct BillingTypeStruct{

	struct BillingTypeStruct *pNext;
	char    sBillingTypeID[21];		/* �ײ�ID */
	char    sTemplateID[21];		/* �ײ�ģ��ID */
	char    sRemark[61];		/* �ײ����� */
	char    sCatg[2];		/* ����,'B'��ʾ����Ʒ�ײ�,'b'��ʾ�Ӳ�Ʒ�ײ�,'S'��ʾҵ��Ʒ��,'v'��ʾ VPN��� */
	char    sServTypeID[21];		/* ҵ��Ʒ�� */
	char    sImplPattern[5];		/* ʵ��ģʽ(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    sAffectService[5];		/* ����ҵ��(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    sMethod[2];		/* ���۷�ʽ(T�����嵥���۹���,M�嵥�����������,D���������Żݹ���) */
	struct BillingTypeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FBillingTypeStruct{

	char    sBillingTypeID[20];		/* �ײ�ID */
	char    sTemplateID[20];		/* �ײ�ģ��ID */
	char    sRemark[60];		/* �ײ����� */
	char    sCatg[1];		/* ����,'B'��ʾ����Ʒ�ײ�,'b'��ʾ�Ӳ�Ʒ�ײ�,'S'��ʾҵ��Ʒ��,'v'��ʾ VPN��� */
	char    sServTypeID[20];		/* ҵ��Ʒ�� */
	char    sImplPattern[4];		/* ʵ��ģʽ(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    sAffectService[4];		/* ����ҵ��(�Ӳ�Ʒ�ײͲ���ֵ) */
	char    sMethod[1];		/* ���۷�ʽ(T�����嵥���۹���,M�嵥�����������,D���������Żݹ���) */
};

/*�������ݶ�̬��BILLING_TYPE���ýṹ���巽ʽȡ����*/
int EGetBillingTypeToStruct(struct BillingTypeStruct *p,
	struct BillingTypeStructIn *pSource);
/**�Ա�BILLING_TYPE�������ͷź���**/
void DestroyBillingType(struct BillingTypeStruct *ptHead);
int InitBillingType(struct BillingTypeStruct **pptHead);

/********************�ײ�����Է���������Ϊ���µ�ͳ�Ʊ���û�ͳ������*****************************/

/*����ṹ��������*/
struct CrUserStatStructOut{

#ifndef CR_USER_STAT_BUFLEN_OUT
#define CR_USER_STAT_BUFLEN_OUT		300
#endif

	struct CrUserStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asAccNbr[CR_USER_STAT_BUFLEN_OUT][21];
		/* �û������� */
	char    asHomeAreaCode[CR_USER_STAT_BUFLEN_OUT][6];
		/* �û�������ʶ */
	int    aiSubscriptionID[CR_USER_STAT_BUFLEN_OUT];
		/* ҵ������ */
	char     asServiceType[CR_USER_STAT_BUFLEN_OUT][5];
		/* ͨ������ */
	char    asCallType[CR_USER_STAT_BUFLEN_OUT][3];
		/* ����ҵ���� */
	char    asServiceCode[CR_USER_STAT_BUFLEN_OUT][5];
		/* �����û����� */
	int     aiHomePartyType[CR_USER_STAT_BUFLEN_OUT];
		/* �Զ��û����� */
	int     aiOtherPartyType[CR_USER_STAT_BUFLEN_OUT];
		/* ��;���� */
	char    asTollType[CR_USER_STAT_BUFLEN_OUT][5];
		/* �������� */
	char    asRoamType[CR_USER_STAT_BUFLEN_OUT][5];
		/* �ײ�ID/�Ӳ�ƷID/�ID*/
	char    asBillingTypeID[CR_USER_STAT_BUFLEN_OUT][11];
		/* �Ʒѵ��۱���ID*/
	int    aiDescriptionID[CR_USER_STAT_BUFLEN_OUT];
		/* ��ĿID */
	int    aiSubjectID[CR_USER_STAT_BUFLEN_OUT];
		/* ������ */
	int    aiCdrCount[CR_USER_STAT_BUFLEN_OUT];
		/* ҵ���� */
	int    aiCdrVolume[CR_USER_STAT_BUFLEN_OUT];
		/* ҵ������λ */
	int    asVolumeUnit[CR_USER_STAT_BUFLEN_OUT][2];
		/* �Ʒѽ�� */
	int    aiBillFee[CR_USER_STAT_BUFLEN_OUT];
		/* �˻�ID */
	int     aiAccountID[CR_USER_STAT_BUFLEN_OUT];
	int     aiProductClass[CR_USER_STAT_BUFLEN_OUT];
	int     aiOtherPartyHead[CR_USER_STAT_BUFLEN_OUT];
	int     aiComponentID[CR_USER_STAT_BUFLEN_OUT];

};


/* ����ṹ��������*/
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
		/* �û����� */
	char    asAccNbr[CR_USER_STAT_BUFLEN_IN][21];
		/* �û������� */
	char    asHomeAreaCode[CR_USER_STAT_BUFLEN_IN][6];
		/* �û�������ʶ */
	int    aiSubscriptionID[CR_USER_STAT_BUFLEN_IN];
		/* ҵ������ */
	char     asServiceType[CR_USER_STAT_BUFLEN_IN][5];
		/* ͨ������ */
	char    asCallType[CR_USER_STAT_BUFLEN_IN][3];
		/* ����ҵ���� */
	char    asServiceCode[CR_USER_STAT_BUFLEN_IN][5];
		/* �����û����� */
	int     aiHomePartyType[CR_USER_STAT_BUFLEN_IN];
		/* �Զ��û����� */
	int     aiOtherPartyType[CR_USER_STAT_BUFLEN_IN];
		/* ��;���� */
	char    asTollType[CR_USER_STAT_BUFLEN_IN][5];
		/* �������� */
	char    asRoamType[CR_USER_STAT_BUFLEN_IN][5];
		/* �ײ�ID/�Ӳ�ƷID/�ID*/
	char    asBillingTypeID[CR_USER_STAT_BUFLEN_IN][11];
		/* �Ʒѵ��۱���ID*/
	int    aiDescriptionID[CR_USER_STAT_BUFLEN_IN];
		/* ��ĿID */
	int    aiSubjectID[CR_USER_STAT_BUFLEN_IN];
		/* ������ */
	int    aiCdrCount[CR_USER_STAT_BUFLEN_IN];
		/* ҵ���� */
	int    aiCdrVolume[CR_USER_STAT_BUFLEN_IN];
		/* ҵ������λ */
	char    asVolumeUnit[CR_USER_STAT_BUFLEN_IN][2];
		/* �Ʒѽ�� */
	int    aiBillFee[CR_USER_STAT_BUFLEN_IN];
		/* �˻�ID */
	int     aiAccountID[CR_USER_STAT_BUFLEN_IN];
	int     aiProductClass[CR_USER_STAT_BUFLEN_IN];
	int     aiOtherPartyHead[CR_USER_STAT_BUFLEN_IN];
	int     aiComponentID[CR_USER_STAT_BUFLEN_IN];

};


/*�����ṹ����*/
struct CrUserStatStruct{

	struct CrUserStatStruct *pNext;
	
	char    sAccNbr[21];		/* �û����� */
	char    sHomeAreaCode[6];		/* �û������� */
	int     iSubscriptionID;		/* �û�������ʶ */
	char    sServiceType[5];		/* ҵ������ */
	char    sCallType[3];		/* ͨ������ */
	char    sServiceCode[5];		/* ����ҵ���� */
	int     iHomePartyType;		/* �����û����� */
	int     iOtherPartyType;		/* �Զ��û����� */
	char    sTollType[5];		/* ��;���� */
	char    sRoamType[5];		/* �������� */
	char    sBillingTypeID[11];		/* �ײ�ID/�Ӳ�ƷID/�ID*/
	int     iDescriptionID;		/* �Ʒѵ��۱���ID*/
	int     iSubjectID;		/* ��ĿID */
	int     iCdrCount;		/* ������ */
	int     iCdrVolume;		/* ҵ���� */
	char    sVolumeUnit[2];		/* ҵ������λ */
	int     iBillFee;		/* �Ʒѽ�� */
	int     iAccountID;		/* �˻�ID */
	int     iProductClass;
	int     iOtherPartyHead;
	int     iComponentID;
	struct CrUserStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrUserStatStruct{

	char    sAccNbr[20];		/* �û����� */
	char    sHomeAreaCode[5];		/* �û������� */
	char    sSubscriptionID[10];		/* �û�������ʶ */
	char    sServiceType[4];		/* ҵ������ */
	char    sCallType[2];		/* ͨ������ */
	char    sServiceCode[4];		/* ����ҵ���� */
	char    sHomePartyType[4];		/* �����û����� */
	char    sOtherPartyType[4];		/* �Զ��û����� */
	char    sTollType[4];		/* ��;���� */
	char    sRoamType[4];		/* �������� */
	char    sBillingTypeID[10];		/* �ײ�ID/�Ӳ�ƷID/�ID*/
	char    sDescriptionID[10];		/* �Ʒѵ��۱���ID*/
	char    sSubjectID[10];		/* ��ĿID */
	char    sCdrCount[10];		/* ������ */
	char    sCdrVolume[10];		/* ҵ���� */
	char    sVolumeUnit[1];		/* ҵ������λ */
	char    sBillFee[10];		/* �Ʒѽ�� */
	char    sAccountID[9];		/* �˻�ID */
	char    sProductClass[9];
	char    sOtherPartyHead[9];
	char    sComponentID[9];
};

/*����ṹ��������*/
struct CrAcctItemStatStructOut{

#ifndef CR_ACCT_ITEM_STAT_BUFLEN_OUT
#define CR_ACCT_ITEM_STAT_BUFLEN_OUT		300
#endif

	struct CrAcctItemStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �û����� */
	char    asAccNbr[CR_ACCT_ITEM_STAT_BUFLEN_OUT][21];
		/* �û��������� */
	char    asAreaCode[CR_ACCT_ITEM_STAT_BUFLEN_OUT][6];
		/* �û�������ʶ */
	int     aiSubscriptionID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* �ʻ�ID */
	int     aiAccountID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* ҵ������ */
	int     aiServiceType[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* �ײ�ID/�Ӳ�ƷID/�ID */
	char    asBillingTypeID[CR_ACCT_ITEM_STAT_BUFLEN_OUT][11];
		/* �Ʒѵ��۱���ID */
	int     aiDescriptionID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* ��ĿID */
	int     aiSubjectID[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* �Ʒѽ�� */
	int     aiBillFee[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
		/* �Żݽ�� */
	int     aiDisctFee[CR_ACCT_ITEM_STAT_BUFLEN_OUT];
};


/* ����ṹ��������*/
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
		/* �û����� */
	char    asAccNbr[CR_ACCT_ITEM_STAT_BUFLEN_IN][21];
		/* �û��������� */
	char    asAreaCode[CR_ACCT_ITEM_STAT_BUFLEN_IN][6];
		/* �û�������ʶ */
	int     aiSubscriptionID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* �ʻ�ID */
	int     aiAccountID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* ҵ������ */
	int     aiServiceType[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* �ײ�ID/�Ӳ�ƷID/�ID */
	char    asBillingTypeID[CR_ACCT_ITEM_STAT_BUFLEN_IN][11];
		/* �Ʒѵ��۱���ID */
	int     aiDescriptionID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* ��ĿID */
	int     aiSubjectID[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* �Ʒѽ�� */
	int     aiBillFee[CR_ACCT_ITEM_STAT_BUFLEN_IN];
		/* �Żݽ�� */
	int     aiDisctFee[CR_ACCT_ITEM_STAT_BUFLEN_IN];
};


/*�����ṹ����*/
struct CrAcctItemStatStruct{

	struct CrAcctItemStatStruct *pNext;
	char    sAccNbr[21];		/* �û����� */
	char    sAreaCode[6];		/* �û��������� */
	int	iSubscriptionID;		/* �û�������ʶ */
	int    	iAccountID;		/* �ʻ�ID */
	int     iServiceType;		/* ҵ������ */
	char    sBillingTypeID[11];		/* �ײ�ID/�Ӳ�ƷID/�ID */
	int    	iDescriptionID;		/* �Ʒѵ��۱���ID */
	int    	iSubjectID;		/* ��ĿID */
	int    	iBillFee;		/* �Ʒѽ�� */
	int    	iDisctFee;		/* �Żݽ�� */
	
/*��չ��Ҫ*/
	int 	iAcctItemTypeID;	/* ��ĿID */
	int	iTotalFee;		/* ��Ŀ����̯���� */
	char	sApportType[2];		/* ��̯���� */
	int	iPriority;		/* ��̯���ȼ� */
	char	sServiceType[11];	/* ҵ������ */
	char	sSubServiceCode[11];	/* ��ҵ������ */
	struct CrAcctItemStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCrAcctItemStatStruct{

	char    sAccNbr[20];		/* �û����� */
	char    sAreaCode[5];		/* �û��������� */
	char    sSubscriptionID[10];		/* �û�������ʶ */
	char    sAccountID[10];		/* �ʻ�ID */
	char    sServiceType[4];		/* ҵ������ */
	char    sBillingTypeID[10];		/* �ײ�ID/�Ӳ�ƷID/�ID */
	char    sDescriptionID[10];		/* �Ʒѵ��۱���ID */
	char    sSubjectID[10];		/* ��ĿID */
	char    sBillFee[10];		/* �Ʒѽ�� */
	char    sDisctFee[10];		/* �Żݽ�� */
};


/*�������ݶ�̬��CR_ACCT_ITEM_STAT���ýṹ���巽ʽȡ����*/
int EGetCrAcctItemStatToStruct(struct CrAcctItemStatStruct *p,
	struct CrAcctItemStatStructIn *pSource);
/**�Ա�CR_ACCT_ITEM_STAT�������ͷź���**/
void DestroyCrAcctItemStat(struct CrAcctItemStatStruct *ptHead);
int InitCrAcctItemStat(struct CrAcctItemStatStruct **pptHead);



#endif
