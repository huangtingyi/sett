#ifndef __KPISTAT_SUPP_H__
#define __KPISTAT_SUPP_H__

#define	PICKFILECNT	2010201	/*PM-02-01-02-01	�ڲ��������ڳɹ�ȡ���ļ�������*/
#define	PICKLOCALINTV	2010202	/*PM-02-01-02-02	��������������Ч�����ļ��������ʱ��*/
#define	PICKBYTECNT	2010203	/*PM-02-01-02-03	��һ�����������ڲɼ��������ļ��ֽ�����*/
#define	PICKBRIDGEINTV	2010204	/*PM-02-01-02-04	�ڽ��������ɻ����ļ�ʱ����ɼ��������ɼ���ɵ�ʱ���*/
#define PICKOVERSTOCK	2010101	/*PM-02-01-01-01	�ڽ������ļ���ѹ����*/
#define PICKHOSTCHK	20101011/*ͨѶ��·״̬�Ƿ�����P1*/

#define	PREPRECCNT  	2020101	/*KPI_ID:PM-02-02-01-01	Ԥ����:����������Ԥ�����ܻ�������*/
#define	PREPERRCNT  	2020102	/*KPI_ID:PM-02-02-01-02	Ԥ����:����������Ԥ�������*/
#define	PREPDUPCNT	2020103	/*KPI_ID:PM-02-02-01-03	Ԥ����:�����������ص�����*/
#define	PREPOVERSTOCK	2020104	/*KPI_ID:PM-02-02-01-04	Ԥ����:���������ڻ�ѹ�Ĵ������ļ���*/
#define	PREPDELAYTIME	2020105	/*KPI_ID:PM-02-02-01-05	Ԥ����:�ɼ����ʱ�䣨P1������������Ԥ�������ʱ��(P2)���*/
#define	PREPPROCRATE  	2020106	/*KPI_ID:PM-02-02-01-06	Ԥ����:��λʱ�䴦��������*/

#define	BILLRECCNT  	2020201	/*KPI_ID:PM-02-02-02-01	����:�������������۵Ļ���������*/
#define	BILLERRCNT  	2020202	/*KPI_ID:PM-02-02-02-02	����:����������һ�����۵��쳣������*/
#define	BILLPROCRATE  	2020203	/*KPI_ID:PM-02-02-02-03	����:һ�δ�����ܻ�����������ʱ��ı�ֵ*/
#define	BILLOVERSTOCK	2020204	/*KPI_ID:PM-02-02-02-04	����:���������ڻ�ѹ�Ĵ������ļ���*/

#define	INSTPROCRATE  	2020401	/*KPI_ID:PM-02-02-04-01	���:һ�δ�����ܻ�����������ʱ��ı�ֵ*/
#define	INSTFILECNT  	2020402	/*KPI_ID:PM-02-02-04-02	���:��������������ļ���*/
#define	INSTRECCNT  	2020403	/*KPI_ID:PM-02-02-04-03	���:������������⻰����*/
#define	INSTOVERSTOCK	2020404	/*KPI_ID:PM-02-02-04-04	���:���������ڻ�ѹ�Ĵ������ļ���*/

#define SETTITEMDU 	9999900/*KPI_ID:PM-99-99-99-00	�ս�:SETT_ITEMͨ��ʱ��*/
#define SETTITEMSD	9999901/*KPI_ID:PM-99-99-99-01	�ս�:SETT_ITEM����ʱ��*/
#define SETTITEMIC 	9999902/*KPI_ID:PM-99-99-99-02	�ս�:SETT_ITEM��ͨ����*/
#define SETTITEMOC 	9999903/*KPI_ID:PM-99-99-99-03	�ս�:SETT_ITEM��֧ͨ��*/
#define SETTITEMTC 	9999904/*KPI_ID:PM-99-99-99-04	�ս�:SETT_ITEM��������*/

#define UPFILECNT	2030101 /*KPI_ID:PM-02-03-01-01       �����ϴ��ļ���*/      
#define UPRECORDCNT	2030102 /*KPI_ID:PM-02-03-01-02       �����ϴ���������*/    
#define LATEUPFILECNT	2030103 /*KPI_ID:PM-02-03-01-03       �ٴ����ļ���*/        
#define LATEUPRECCNT	2030104 /*KPI_ID:PM-02-03-01-04       �ٴ�������*/          
#define DOWNLOSEFCNT	2030105 /*KPI_ID:PM-02-03-01-05       ���ν����ļ���ʧ��*/  
#define DOWNFILECNT	2030106 /*KPI_ID:PM-02-03-01-06       ���յ������ļ���*/    
#define ERRFILECNT	2030107 /*KPI_ID:PM-02-03-01-07       �ϴ��˻صĴ����ļ���*/
#define JRIERRCNT	2030108 /*KPI_ID:PM-02-03-01-08       �ϴ��˻صĴ���*/    
#define JIIERRCNT	2030109 /*KPI_ID:PM-02-03-01-08       �ϴ��˻صĴ���*/   
#define CRIERRCNT	2030110 /*KPI_ID:PM-02-03-01-08       �ϴ��˻صĴ���*/   
#define CIIERRCNT	2030111 /*KPI_ID:PM-02-03-01-08       �ϴ��˻صĴ���*/   

/* ����ṹ��������*/
struct KpiDimensionStructIn{

#ifndef KPI_DIMENSION_BUFLEN_IN
#define KPI_DIMENSION_BUFLEN_IN		300
#endif

	struct KpiDimensionStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ά�ȱ�ʶ */
	int     aiDimensionID[KPI_DIMENSION_BUFLEN_IN];
		/* ����ά�ȱ�ʶ */
	int     aiParentID[KPI_DIMENSION_BUFLEN_IN];
		/* ά�ȴ��� */
	char    asDimension[KPI_DIMENSION_BUFLEN_IN][11];
		/* ά������ */
	char    asDimensionType[KPI_DIMENSION_BUFLEN_IN][5];
		/* ���� */
	char    asRemark[KPI_DIMENSION_BUFLEN_IN][41];
		/* ��� */
	int     aiLay[KPI_DIMENSION_BUFLEN_IN];
		/* Ҷ�ڵ��ʶ */
	char    asLeaveFlag[KPI_DIMENSION_BUFLEN_IN][2];
};


/*�����ṹ����*/
struct KpiDimensionStruct{

	struct KpiDimensionStruct *pNext;
	int     iDimensionID;		/* ά�ȱ�ʶ */
	int     iParentID;		/* ����ά�ȱ�ʶ */
	char    sDimension[11];		/* ά�ȴ��� */
	char    sDimensionType[5];		/* ά������ */
	char    sRemark[41];		/* ���� */
	int     iLay;		/* ��� */
	char    sLeaveFlag[2];		/* Ҷ�ڵ��ʶ */
	struct KpiDimensionStruct *pLoadNext;
};


/*�����ṹ����*/
struct KpiLibStruct{

	struct KpiLibStruct *pNext;
	char    sKpiID[21];		/* KPI��ʶ */
	int     iDimensionID1;		/* ά�ȱ�ʶ1 */
	int     iDimensionID2;		/* ά�ȱ�ʶ2 */
	int     iValue;		/* ָ��ֵ */
	char    sKpiDate[15];		/* ָ������ */
	char    sBeginTime[15];		/* ָ����ʼʱ�� */
	char    sEndTime[15];		/* ָ����ֹʱ�� */
	char    sCreatedDate[15];		/* ָ������ʱ�� */
	struct KpiLibStruct *pLoadNext;
};
int InsertKpiRecord(struct KpiLibStruct **pptKpiRecord);
/*�������ݶ�̬��KPI_DIMENSION���ýṹ���巽ʽȡ����*/
int EGetKpiDimensionToStruct(struct KpiDimensionStruct *p,
	struct KpiDimensionStructIn *pSource);
/**�Ա�KPI_DIMENSION�������ͷź���**/
void DestroyKpiDimension(struct KpiDimensionStruct *ptHead);
int InitKpiDimension(struct KpiDimensionStruct **pptHead);
int SearchDimensionID(struct KpiDimensionStruct **pptHead,char sDimension[]);
void cv_kpilib(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct *pTemp,char sKpiID[],char sSourceID[],int iValue,
	char sKpiDate[],char sBeginTime[],char sEndTime[],char sCreatedDate[]);

/*ÿ��һ�Σ�ȡǰһ�����ݡ�*/
int GenSettItem(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[],char sAcctType[]);
int GenPickFileCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenPickLocalIntv(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenPickByteCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenPrepRecCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenPrepErrCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenPrepDelayTime(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenPrepProcRate(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenBillRecCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenBillErrCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenBillProcRate(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenInstProcRate(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenInstFileCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenInstRecCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenUpErrCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[],char sFileFlag[]);
int GenUpDownFileCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);
int GenUpDownRecCnt(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[]);

void PrintBillingData(char sStamp[],char sCondition[],FILE *fp);

#endif
