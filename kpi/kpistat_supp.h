#ifndef __KPISTAT_SUPP_H__
#define __KPISTAT_SUPP_H__

#define	PICKFILECNT	2010201	/*PM-02-01-02-01	在采样周期内成功取得文件的数量*/
#define	PICKLOCALINTV	2010202	/*PM-02-01-02-02	产生连续两个有效数据文件的最大间隔时间*/
#define	PICKBYTECNT	2010203	/*PM-02-01-02-03	在一个采样周期内采集的所有文件字节总数*/
#define	PICKBRIDGEINTV	2010204	/*PM-02-01-02-04	在交换侧生成话单文件时间与采集机话单采集完成的时间差*/
#define PICKOVERSTOCK	2010101	/*PM-02-01-01-01	在交换侧文件积压个数*/
#define PICKHOSTCHK	20101011/*通讯链路状态是否正常P1*/

#define	PREPRECCNT  	2020101	/*KPI_ID:PM-02-02-01-01	预处理:采样周期内预处理总话单数量*/
#define	PREPERRCNT  	2020102	/*KPI_ID:PM-02-02-01-02	预处理:采样周期内预处理错单数*/
#define	PREPDUPCNT	2020103	/*KPI_ID:PM-02-02-01-03	预处理:采样周期内重单数量*/
#define	PREPOVERSTOCK	2020104	/*KPI_ID:PM-02-02-01-04	预处理:采样周期内积压的待处理文件数*/
#define	PREPDELAYTIME	2020105	/*KPI_ID:PM-02-02-01-05	预处理:采集完成时间（P1）到正常话单预处理完成时间(P2)间隔*/
#define	PREPPROCRATE  	2020106	/*KPI_ID:PM-02-02-01-06	预处理:单位时间处理话单数量*/

#define	BILLRECCNT  	2020201	/*KPI_ID:PM-02-02-02-01	批价:采样周期内批价的话单总数量*/
#define	BILLERRCNT  	2020202	/*KPI_ID:PM-02-02-02-02	批价:采样周期内一次批价的异常话单数*/
#define	BILLPROCRATE  	2020203	/*KPI_ID:PM-02-02-02-03	批价:一次处理的总话单量和所耗时间的比值*/
#define	BILLOVERSTOCK	2020204	/*KPI_ID:PM-02-02-02-04	批价:采样周期内积压的待处理文件数*/

#define	INSTPROCRATE  	2020401	/*KPI_ID:PM-02-02-04-01	入库:一次处理的总话单量和所耗时间的比值*/
#define	INSTFILECNT  	2020402	/*KPI_ID:PM-02-02-04-02	入库:采样周期内入库文件数*/
#define	INSTRECCNT  	2020403	/*KPI_ID:PM-02-02-04-03	入库:采样周期内入库话单数*/
#define	INSTOVERSTOCK	2020404	/*KPI_ID:PM-02-02-04-04	入库:采样周期内积压的待处理文件数*/

#define SETTITEMDU 	9999900/*KPI_ID:PM-99-99-99-00	日结:SETT_ITEM通话时长*/
#define SETTITEMSD	9999901/*KPI_ID:PM-99-99-99-01	日结:SETT_ITEM结算时长*/
#define SETTITEMIC 	9999902/*KPI_ID:PM-99-99-99-02	日结:SETT_ITEM联通收入*/
#define SETTITEMOC 	9999903/*KPI_ID:PM-99-99-99-03	日结:SETT_ITEM联通支出*/
#define SETTITEMTC 	9999904/*KPI_ID:PM-99-99-99-04	日结:SETT_ITEM话单张数*/

#define UPFILECNT	2030101 /*KPI_ID:PM-02-03-01-01       漫游上传文件数*/      
#define UPRECORDCNT	2030102 /*KPI_ID:PM-02-03-01-02       漫游上传话单总数*/    
#define LATEUPFILECNT	2030103 /*KPI_ID:PM-02-03-01-03       迟传的文件数*/        
#define LATEUPRECCNT	2030104 /*KPI_ID:PM-02-03-01-04       迟传话单数*/          
#define DOWNLOSEFCNT	2030105 /*KPI_ID:PM-02-03-01-05       漫游接收文件丢失数*/  
#define DOWNFILECNT	2030106 /*KPI_ID:PM-02-03-01-06       接收的漫游文件数*/    
#define ERRFILECNT	2030107 /*KPI_ID:PM-02-03-01-07       上传退回的错误文件数*/
#define JRIERRCNT	2030108 /*KPI_ID:PM-02-03-01-08       上传退回的错单数*/    
#define JIIERRCNT	2030109 /*KPI_ID:PM-02-03-01-08       上传退回的错单数*/   
#define CRIERRCNT	2030110 /*KPI_ID:PM-02-03-01-08       上传退回的错单数*/   
#define CIIERRCNT	2030111 /*KPI_ID:PM-02-03-01-08       上传退回的错单数*/   

/* 输入结构缓冲申明*/
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
		/* 维度标识 */
	int     aiDimensionID[KPI_DIMENSION_BUFLEN_IN];
		/* 归属维度标识 */
	int     aiParentID[KPI_DIMENSION_BUFLEN_IN];
		/* 维度代码 */
	char    asDimension[KPI_DIMENSION_BUFLEN_IN][11];
		/* 维度类型 */
	char    asDimensionType[KPI_DIMENSION_BUFLEN_IN][5];
		/* 描述 */
	char    asRemark[KPI_DIMENSION_BUFLEN_IN][41];
		/* 层次 */
	int     aiLay[KPI_DIMENSION_BUFLEN_IN];
		/* 叶节点标识 */
	char    asLeaveFlag[KPI_DIMENSION_BUFLEN_IN][2];
};


/*单个结构申明*/
struct KpiDimensionStruct{

	struct KpiDimensionStruct *pNext;
	int     iDimensionID;		/* 维度标识 */
	int     iParentID;		/* 归属维度标识 */
	char    sDimension[11];		/* 维度代码 */
	char    sDimensionType[5];		/* 维度类型 */
	char    sRemark[41];		/* 描述 */
	int     iLay;		/* 层次 */
	char    sLeaveFlag[2];		/* 叶节点标识 */
	struct KpiDimensionStruct *pLoadNext;
};


/*单个结构申明*/
struct KpiLibStruct{

	struct KpiLibStruct *pNext;
	char    sKpiID[21];		/* KPI标识 */
	int     iDimensionID1;		/* 维度标识1 */
	int     iDimensionID2;		/* 维度标识2 */
	int     iValue;		/* 指标值 */
	char    sKpiDate[15];		/* 指标日期 */
	char    sBeginTime[15];		/* 指标起始时间 */
	char    sEndTime[15];		/* 指标终止时间 */
	char    sCreatedDate[15];		/* 指标生成时间 */
	struct KpiLibStruct *pLoadNext;
};
int InsertKpiRecord(struct KpiLibStruct **pptKpiRecord);
/*批量数据动态从KPI_DIMENSION中用结构缓冲方式取数据*/
int EGetKpiDimensionToStruct(struct KpiDimensionStruct *p,
	struct KpiDimensionStructIn *pSource);
/**对表KPI_DIMENSION的链表释放函数**/
void DestroyKpiDimension(struct KpiDimensionStruct *ptHead);
int InitKpiDimension(struct KpiDimensionStruct **pptHead);
int SearchDimensionID(struct KpiDimensionStruct **pptHead,char sDimension[]);
void cv_kpilib(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct *pTemp,char sKpiID[],char sSourceID[],int iValue,
	char sKpiDate[],char sBeginTime[],char sEndTime[],char sCreatedDate[]);

/*每日一次，取前一天数据。*/
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
