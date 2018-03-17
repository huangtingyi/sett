#ifndef __T130_SUPP_H__
#define __T130_SUPP_H__


/*�����ṹ����*/
struct AreaCodeStruct{

	struct AreaCodeStruct *pNext;
	char    sCityCode[4];		/* ���д��� */
	char    sAreaCodeZb[9];		/* �ܲ��·����� */
	char    sAreaCodeXt[9];		/* ��ϵͳ���� */
	struct AreaCodeStruct *pLoadNext;
};



/*�����ṹ����*/
struct MobileHeadStruct{

	struct MobileHeadStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sProvCode[4];		/* ʡ�ֹ�˾���� */
	char    sCityCode[4];		/* ���д��� */
	char    sAreaCode[9];		/* ��;���� */
	char    sTailHead[7];		/* H0H1H2H3 */
	char    sReserve[9];		/* δ�� */
	struct MobileHeadStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FMobileHeadStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sProvCode[3];		/* ʡ�ֹ�˾���� */
	char    sCityCode[3];		/* ���д��� */
	char    sAreaCode[8];		/* ��;���� */
	char    sTailHead[6];		/* H0H1H2H3 */
	char    sReserve[8];		/* δ�� */
};

/*����ͷ�ṹ����*/
struct HeadMobileHeadStruct{

	struct HeadMobileHeadStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sProvCode[4];		/* �·�ʡ�ֹ�˾���� */
	char    sHead[4];		/* ���š�ǰ׺ */
	char    sDate[9];		/* �ļ��������� */
	char    sSumCount[11];		/* �ܼ�¼�� */
	char    sReserve[5];		/* δ�� */
	struct HeadMobileHeadStruct *pLoadNext;
};


/*�����ļ�ͷ�ṹ����*/
struct FHeadMobileHeadStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sProvCode[3];		/* �·�ʡ�ֹ�˾���� */
	char    sHead[3];		/* ���š�ǰ׺ */
	char    sDate[8];		/* �ļ��������� */
	char    sSumCount[10];		/* �ܼ�¼�� */
	char    sReserve[4];		/* δ�� */

};



/* ����ṹ��������*/
struct OrdT130AreaCodeStructIn{

#ifndef ORD_T130_AREA_CODE_BUFLEN_IN
#define ORD_T130_AREA_CODE_BUFLEN_IN		300
#endif

	struct OrdT130AreaCodeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiHeadID[ORD_T130_AREA_CODE_BUFLEN_IN];
	int     aiSeqNbr[ORD_T130_AREA_CODE_BUFLEN_IN];
	char    asHead[ORD_T130_AREA_CODE_BUFLEN_IN][12];
	int     aiLen[ORD_T130_AREA_CODE_BUFLEN_IN];
	char    asAreaCode[ORD_T130_AREA_CODE_BUFLEN_IN][10];
	char    asHeadType[ORD_T130_AREA_CODE_BUFLEN_IN][2];
	char    asRemark[ORD_T130_AREA_CODE_BUFLEN_IN][61];
	char    asEffDate[ORD_T130_AREA_CODE_BUFLEN_IN][15];
	char    asExpDate[ORD_T130_AREA_CODE_BUFLEN_IN][15];
	char    asState[ORD_T130_AREA_CODE_BUFLEN_IN][4];
	char    asStateDate[ORD_T130_AREA_CODE_BUFLEN_IN][15];
	char    asCreatedDate[ORD_T130_AREA_CODE_BUFLEN_IN][15];
	int     aiStaffID[ORD_T130_AREA_CODE_BUFLEN_IN];
	char    asOrdType[ORD_T130_AREA_CODE_BUFLEN_IN][5];
	char    asOrdNbr[ORD_T130_AREA_CODE_BUFLEN_IN][31];
	int     aiOrdSeqNbr[ORD_T130_AREA_CODE_BUFLEN_IN];
	char    asOrdSourceID[ORD_T130_AREA_CODE_BUFLEN_IN][31];
	char    asComments[ORD_T130_AREA_CODE_BUFLEN_IN][101];
};


/*�����ṹ����*/
struct OrdT130AreaCodeStruct{

	struct OrdT130AreaCodeStruct *pNext;
	int     iHeadID;
	int     iSeqNbr;
	char    sHead[12];
	int     iLen;
	char    sAreaCode[10];
	char    sHeadType[2];
	char    sRemark[61];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	int     iStaffID;
	char    sOrdType[5];
	char    sOrdNbr[31];
	int     iOrdSeqNbr;
	char    sOrdSourceID[31];
	char    sComments[101];
	char	sRowID[19];
	struct OrdT130AreaCodeStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FOrdT130AreaCodeStruct{

	char    sHeadID[6];
	char    sSeqNbr[3];
	char    sHead[11];
	char    sLen[2];
	char    sAreaCode[9];
	char    sHeadType[1];
	char    sRemark[60];
	char    sEffDate[14];
	char    sExpDate[14];
	char    sState[3];
	char    sStateDate[14];
	char    sCreatedDate[14];
	char    sStaffID[6];
	char    sOrdType[4];
	char    sOrdNbr[30];
	char    sOrdSeqNbr[2];
	char    sOrdSourceID[30];
	char    sComments[100];
};


int GetAreaCode(struct MobileHeadStruct *pm,struct HeadMobileHeadStruct *ph,
	char sAreaCode[],char sRemark[]);
int PrintFile(struct OrdT130AreaCodeStruct *pSource,char sTargetName[]);
void mvitem_mft130areacode(struct OrdT130AreaCodeStruct *pi,struct FOrdT130AreaCodeStruct *po);
void mvitem_t130areacode(struct OrdT130AreaCodeStruct *pi,struct OrdT130AreaCodeStruct *po);
void mvitem_fmmobilehead(struct FMobileHeadStruct *pi,struct MobileHeadStruct *po);
void mvitem_fmheadmobilehead(struct FHeadMobileHeadStruct *pi,struct HeadMobileHeadStruct *po);
int data_search_bintree_AreaChk(void *pValue,void*pData);
void assign_insert_bintree_AreaChk(void **ppData,void *pData);
int GetOrdOrdT130AreaCode(struct MobileHeadStruct *pm,struct HeadMobileHeadStruct *ph,
	struct OrdT130AreaCodeStruct **pi);


/*����ṹ��������*/
struct OrdT130AreaCodeStructOut{

#ifndef ORD_T130_AREA_CODE_BUFLEN_OUT
#define ORD_T130_AREA_CODE_BUFLEN_OUT		300
#endif

	struct OrdT130AreaCodeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiHeadID[ORD_T130_AREA_CODE_BUFLEN_OUT];
	int     aiSeqNbr[ORD_T130_AREA_CODE_BUFLEN_OUT];
	char    asHead[ORD_T130_AREA_CODE_BUFLEN_OUT][12];
	int     aiLen[ORD_T130_AREA_CODE_BUFLEN_OUT];
	char    asAreaCode[ORD_T130_AREA_CODE_BUFLEN_OUT][10];
	char    asHeadType[ORD_T130_AREA_CODE_BUFLEN_OUT][2];
	char    asRemark[ORD_T130_AREA_CODE_BUFLEN_OUT][61];
	char    asEffDate[ORD_T130_AREA_CODE_BUFLEN_OUT][15];
	char    asExpDate[ORD_T130_AREA_CODE_BUFLEN_OUT][15];
	char    asState[ORD_T130_AREA_CODE_BUFLEN_OUT][4];
	char    asStateDate[ORD_T130_AREA_CODE_BUFLEN_OUT][15];
	char    asCreatedDate[ORD_T130_AREA_CODE_BUFLEN_OUT][15];
	int     aiStaffID[ORD_T130_AREA_CODE_BUFLEN_OUT];
	char    asOrdType[ORD_T130_AREA_CODE_BUFLEN_OUT][5];
	char    asOrdNbr[ORD_T130_AREA_CODE_BUFLEN_OUT][31];
	int     aiOrdSeqNbr[ORD_T130_AREA_CODE_BUFLEN_OUT];
	char    asOrdSourceID[ORD_T130_AREA_CODE_BUFLEN_OUT][31];
	char    asComments[ORD_T130_AREA_CODE_BUFLEN_OUT][101];
};



int EInsertStructToOrdT130AreaCode(struct OrdT130AreaCodeStruct *p,
	int iInsertFlag,struct OrdT130AreaCodeStructOut *pTarget);

/*����ṹ��������*/
struct T130AreaCodeChkStructOut{

#ifndef T130_AREA_CODE_CHK_BUFLEN_OUT
#define T130_AREA_CODE_CHK_BUFLEN_OUT		300
#endif

	struct T130AreaCodeChkStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiHeadID[T130_AREA_CODE_CHK_BUFLEN_OUT];
	int     aiSeqNbr[T130_AREA_CODE_CHK_BUFLEN_OUT];
	char    asHead[T130_AREA_CODE_CHK_BUFLEN_OUT][12];
	int     aiLen[T130_AREA_CODE_CHK_BUFLEN_OUT];
	char    asAreaCode[T130_AREA_CODE_CHK_BUFLEN_OUT][10];
	char    asHeadType[T130_AREA_CODE_CHK_BUFLEN_OUT][2];
	char    asRemark[T130_AREA_CODE_CHK_BUFLEN_OUT][61];
	char    asEffDate[T130_AREA_CODE_CHK_BUFLEN_OUT][15];
	char    asExpDate[T130_AREA_CODE_CHK_BUFLEN_OUT][15];
	char    asState[T130_AREA_CODE_CHK_BUFLEN_OUT][4];
	char    asStateDate[T130_AREA_CODE_CHK_BUFLEN_OUT][15];
	char    asCreatedDate[T130_AREA_CODE_CHK_BUFLEN_OUT][15];
};


/*����ṹ��������*/
struct T130AreaCodeChkStructUp{

#ifndef T130_AREA_CODE_CHK_BUFLEN_UP
#define T130_AREA_CODE_CHK_BUFLEN_UP		300
#endif

	struct T130AreaCodeChkStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiHeadID[T130_AREA_CODE_CHK_BUFLEN_UP];
	int     aiSeqNbr[T130_AREA_CODE_CHK_BUFLEN_UP];
	char    asHead[T130_AREA_CODE_CHK_BUFLEN_UP][12];
	int     aiLen[T130_AREA_CODE_CHK_BUFLEN_UP];
	char    asAreaCode[T130_AREA_CODE_CHK_BUFLEN_UP][10];
	char    asHeadType[T130_AREA_CODE_CHK_BUFLEN_UP][2];
	char    asRemark[T130_AREA_CODE_CHK_BUFLEN_UP][61];
	char    asEffDate[T130_AREA_CODE_CHK_BUFLEN_UP][15];
	char    asExpDate[T130_AREA_CODE_CHK_BUFLEN_UP][15];
	char    asState[T130_AREA_CODE_CHK_BUFLEN_UP][4];
	char    asStateDate[T130_AREA_CODE_CHK_BUFLEN_UP][15];
	char    asCreatedDate[T130_AREA_CODE_CHK_BUFLEN_UP][15];
	char	asRowID[T130_AREA_CODE_CHK_BUFLEN_UP][19];
};


/* ����ṹ��������*/
struct T130AreaCodeChkStructIn{

#ifndef T130_AREA_CODE_CHK_BUFLEN_IN
#define T130_AREA_CODE_CHK_BUFLEN_IN		300
#endif

	struct T130AreaCodeChkStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiHeadID[T130_AREA_CODE_CHK_BUFLEN_IN];
	int     aiSeqNbr[T130_AREA_CODE_CHK_BUFLEN_IN];
	char    asHead[T130_AREA_CODE_CHK_BUFLEN_IN][12];
	int     aiLen[T130_AREA_CODE_CHK_BUFLEN_IN];
	char    asAreaCode[T130_AREA_CODE_CHK_BUFLEN_IN][10];
	char    asHeadType[T130_AREA_CODE_CHK_BUFLEN_IN][2];
	char    asRemark[T130_AREA_CODE_CHK_BUFLEN_IN][61];
	char    asEffDate[T130_AREA_CODE_CHK_BUFLEN_IN][15];
	char    asExpDate[T130_AREA_CODE_CHK_BUFLEN_IN][15];
	char    asState[T130_AREA_CODE_CHK_BUFLEN_IN][4];
	char    asStateDate[T130_AREA_CODE_CHK_BUFLEN_IN][15];
	char    asCreatedDate[T130_AREA_CODE_CHK_BUFLEN_IN][15];
	char	asRowID[T130_AREA_CODE_CHK_BUFLEN_IN][19];
};



/*�����ṹ����*/
struct T130AreaCodeChkStruct{

	struct T130AreaCodeChkStruct *pNext;
	int     iHeadID;
	int     iSeqNbr;
	char    sHead[12];
	int     iLen;
	char    sAreaCode[10];
	char    sHeadType[2];
	char    sRemark[61];
	char    sEffDate[15];
	char    sExpDate[15];
	char    sState[4];
	char    sStateDate[15];
	char    sCreatedDate[15];
	char	sRowID[19];
	struct T130AreaCodeChkStruct *pLoadNext;
};



int EInsertStructToT130AreaCodeChk(struct T130AreaCodeChkStruct *p,
	int iInsertFlag,struct T130AreaCodeChkStructOut *pTarget);


int InsertOrdT130AreaCode(struct OrdT130AreaCodeStruct *pSource,char sTableName[]);
int InsertT130AreaCode(struct OrdT130AreaCodeStruct *pSource,
	char sTableName[],char sState[]);
int UpdateT130AreaCode(struct OrdT130AreaCodeStruct *pSource,
	char sTableName[],char sState[]);

void mvitem_ordtot130areacode(struct OrdT130AreaCodeStruct *pi,
	struct T130AreaCodeChkStruct *po);
int DealTable(struct OrdT130AreaCodeStruct *ptOut,
	struct OrdT130AreaCodeStruct *ptDel);	
	
int GetHeadId();
int EDeleteStructToT130AreaCode(struct T130AreaCodeChkStruct *p,
	int iDeleteFlag,struct T130AreaCodeChkStructDel *pTarget);
/*�������ݶ�̬��T130_AREA_CODE_CHK���ýṹ���巽ʽȡ����*/
int EGetT130AreaCodeChkToStruct(struct T130AreaCodeChkStruct *p,
	struct T130AreaCodeChkStructIn *pSource);	
void mvitem_ordt130areacode(struct OrdT130AreaCodeStruct *pi,struct OrdT130AreaCodeStruct *po);
void mvitem_mfordt130areacode(struct OrdT130AreaCodeStruct *pi,struct FOrdT130AreaCodeStruct *po);
void mvitem_fmheadmobilehead(struct FHeadMobileHeadStruct *pi,struct HeadMobileHeadStruct *po);
void mvitem_ordtot130areacode(struct OrdT130AreaCodeStruct *pi,struct T130AreaCodeChkStruct *po);

int DGetT130AreaCodeHeadID(struct OrdT130AreaCodeStruct *p);

#endif

