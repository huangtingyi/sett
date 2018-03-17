#ifndef _HIGH_SUPP_H_
#define _HIGH_SUPP_H_


/*---------基本部分代码 imei_up.txt----------*/

/*输出结构缓冲申明*/
struct ImeiUpStructOut{

#ifndef IMEI_UP_BUFLEN_OUT
#define IMEI_UP_BUFLEN_OUT		300
#endif

	struct ImeiUpStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 序列号 */
	char    asRsSeq[IMEI_UP_BUFLEN_OUT][19];
		/* 用户号码 */
	char    asMsisdn[IMEI_UP_BUFLEN_OUT][21];
		/* IMEI号，手机电子串号 */
	char    asImei[IMEI_UP_BUFLEN_OUT][31];
		/* 国际移动用户识别码 */
	char    asImsi[IMEI_UP_BUFLEN_OUT][21];
		/* 通话时间 */
	char    asCallstarttime[IMEI_UP_BUFLEN_OUT][15];
		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    asMatchitem[IMEI_UP_BUFLEN_OUT][2];
		/* 数据类型：１表示本省，２表示漫游 */
	char    asType[IMEI_UP_BUFLEN_OUT][2];
		/* 记录处理时间 */
	char    asCreatetime[IMEI_UP_BUFLEN_OUT][21];
};


/* 输入结构缓冲申明*/
struct ImeiUpStructIn{

#ifndef IMEI_UP_BUFLEN_IN
#define IMEI_UP_BUFLEN_IN		300
#endif

	struct ImeiUpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 序列号 */
	char    asRsSeq[IMEI_UP_BUFLEN_IN][19];
		/* 用户号码 */
	char    asMsisdn[IMEI_UP_BUFLEN_IN][21];
		/* IMEI号，手机电子串号 */
	char    asImei[IMEI_UP_BUFLEN_IN][31];
		/* 国际移动用户识别码 */
	char    asImsi[IMEI_UP_BUFLEN_IN][21];
		/* 通话时间 */
	char    asCallstarttime[IMEI_UP_BUFLEN_IN][15];
		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    asMatchitem[IMEI_UP_BUFLEN_IN][2];
		/* 数据类型：１表示本省，２表示漫游 */
	char    asType[IMEI_UP_BUFLEN_IN][2];
		/* 记录处理时间 */
	char    asCreatetime[IMEI_UP_BUFLEN_IN][21];
};


/*单个结构申明*/
struct ImeiUpStruct{

	struct ImeiUpStruct *pNext;
	char    sRsSeq[19];		/* 序列号 */
	char    sMsisdn[21];		/* 用户号码 */
	char    sImei[31];		/* IMEI号，手机电子串号 */
	char    sImsi[21];		/* 国际移动用户识别码 */
	char    sCallstarttime[15];		/* 通话时间 */
	char    sMatchitem[2];		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    sType[2];		/* 数据类型：１表示本省，２表示漫游 */
	char    sCreatetime[21];		/* 记录处理时间 */
	struct ImeiUpStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FImeiUpStruct{

	char    sRsSeq[18];		/* 序列号 */
	char    sMsisdn[20];		/* 用户号码 */
	char    sImei[30];		/* IMEI号，手机电子串号 */
	char    sImsi[20];		/* 国际移动用户识别码 */
	char    sCallstarttime[14];		/* 通话时间 */
	char    sMatchitem[1];		/* 匹配属性1：BSS2：自注册3：漫入　4：漫出 */
	char    sType[1];		/* 数据类型：１表示本省，２表示漫游 */
	char    sCreatetime[20];		/* 记录处理时间 */
};


/*批量数据动态从IMEI_UP中用结构缓冲方式取数据*/
int EGetImeiUpToStruct(struct ImeiUpStruct *p,
	struct ImeiUpStructIn *pSource);


/*---------基本部分代码 pstn_detail_ticket.txt----------*/

/*输出结构缓冲申明*/
struct PstnDetailTicketStructOut{

#ifndef PSTN_DETAIL_TICKET_BUFLEN_OUT
#define PSTN_DETAIL_TICKET_BUFLEN_OUT		300
#endif

	struct PstnDetailTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asCompany[PSTN_DETAIL_TICKET_BUFLEN_OUT][6];
	char    asReference[PSTN_DETAIL_TICKET_BUFLEN_OUT][7];
	char    asNone[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asImsi[PSTN_DETAIL_TICKET_BUFLEN_OUT][16];
	char    asCallingNbr[PSTN_DETAIL_TICKET_BUFLEN_OUT][26];
	char    asModifyIns[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asNumberType[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asPickProgram[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asCalledNbr[PSTN_DETAIL_TICKET_BUFLEN_OUT][26];
	char    asServiceType[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asServiceNbr[PSTN_DETAIL_TICKET_BUFLEN_OUT][9];
	char    asDualType[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asDualNbr[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asReqChannel[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asUseChannel[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asServiceTran[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asActivityCode1[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asAddActivityCode1[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asActivityCode2[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asAddActivityCode2[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asActivityCode3[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asAddActivityCode3[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asActivityCode4[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asAddActivityCode4[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asActivityCode5[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asAddActivityCode5[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asMsc[PSTN_DETAIL_TICKET_BUFLEN_OUT][16];
	char    asLac[PSTN_DETAIL_TICKET_BUFLEN_OUT][6];
	char    asCellularSigns[PSTN_DETAIL_TICKET_BUFLEN_OUT][6];
	char    asMobileCode[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asCallTime[PSTN_DETAIL_TICKET_BUFLEN_OUT][15];
	char    asPayUnits[PSTN_DETAIL_TICKET_BUFLEN_OUT][7];
	char    asAmountData[PSTN_DETAIL_TICKET_BUFLEN_OUT][7];
	int     aiTollFee[PSTN_DETAIL_TICKET_BUFLEN_OUT];
	char    asTollProjects[PSTN_DETAIL_TICKET_BUFLEN_OUT][2];
	char    asTaxRate[PSTN_DETAIL_TICKET_BUFLEN_OUT][11];
	char    asRate1[PSTN_DETAIL_TICKET_BUFLEN_OUT][11];
	char    asRetention[PSTN_DETAIL_TICKET_BUFLEN_OUT][18];
	char    asRate2[PSTN_DETAIL_TICKET_BUFLEN_OUT][11];
	char    asSdr[PSTN_DETAIL_TICKET_BUFLEN_OUT][16];
	char    asState[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asFileName[PSTN_DETAIL_TICKET_BUFLEN_OUT][33];
	char	asRowID[PSTN_DETAIL_TICKET_BUFLEN_OUT][19];
};


/* 输入结构缓冲申明*/
struct PstnDetailTicketStructIn{

#ifndef PSTN_DETAIL_TICKET_BUFLEN_IN
#define PSTN_DETAIL_TICKET_BUFLEN_IN		300
#endif

	struct PstnDetailTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asCompany[PSTN_DETAIL_TICKET_BUFLEN_IN][6];
	char    asReference[PSTN_DETAIL_TICKET_BUFLEN_IN][7];
	char    asNone[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asImsi[PSTN_DETAIL_TICKET_BUFLEN_IN][16];
	char    asCallingNbr[PSTN_DETAIL_TICKET_BUFLEN_IN][26];
	char    asModifyIns[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asNumberType[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asPickProgram[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asCalledNbr[PSTN_DETAIL_TICKET_BUFLEN_IN][26];
	char    asServiceType[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asServiceNbr[PSTN_DETAIL_TICKET_BUFLEN_IN][9];
	char    asDualType[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asDualNbr[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asReqChannel[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asUseChannel[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asServiceTran[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asActivityCode1[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asAddActivityCode1[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asActivityCode2[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asAddActivityCode2[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asActivityCode3[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asAddActivityCode3[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asActivityCode4[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asAddActivityCode4[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asActivityCode5[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asAddActivityCode5[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asMsc[PSTN_DETAIL_TICKET_BUFLEN_IN][16];
	char    asLac[PSTN_DETAIL_TICKET_BUFLEN_IN][6];
	char    asCellularSigns[PSTN_DETAIL_TICKET_BUFLEN_IN][6];
	char    asMobileCode[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asCallTime[PSTN_DETAIL_TICKET_BUFLEN_IN][15];
	char    asPayUnits[PSTN_DETAIL_TICKET_BUFLEN_IN][7];
	char    asAmountData[PSTN_DETAIL_TICKET_BUFLEN_IN][7];
	int     aiTollFee[PSTN_DETAIL_TICKET_BUFLEN_IN];
	char    asTollProjects[PSTN_DETAIL_TICKET_BUFLEN_IN][2];
	char    asTaxRate[PSTN_DETAIL_TICKET_BUFLEN_IN][11];
	char    asRate1[PSTN_DETAIL_TICKET_BUFLEN_IN][11];
	char    asRetention[PSTN_DETAIL_TICKET_BUFLEN_IN][18];
	char    asRate2[PSTN_DETAIL_TICKET_BUFLEN_IN][11];
	char    asSdr[PSTN_DETAIL_TICKET_BUFLEN_IN][16];
	char    asState[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asFileName[PSTN_DETAIL_TICKET_BUFLEN_IN][33];
	char	asRowID[PSTN_DETAIL_TICKET_BUFLEN_IN][19];
};


/*单个结构申明*/
struct PstnDetailTicketStruct{

	struct PstnDetailTicketStruct *pNext;
	char    sRecordType[3];
	char    sCompany[6];
	char    sReference[7];
	char    sNone[2];
	char    sImsi[16];
	char    sCallingNbr[26];
	char    sModifyIns[2];
	char    sNumberType[2];
	char    sPickProgram[2];
	char    sCalledNbr[26];
	char    sServiceType[2];
	char    sServiceNbr[9];
	char    sDualType[2];
	char    sDualNbr[3];
	char    sReqChannel[2];
	char    sUseChannel[2];
	char    sServiceTran[2];
	char    sActivityCode1[2];
	char    sAddActivityCode1[3];
	char    sActivityCode2[2];
	char    sAddActivityCode2[3];
	char    sActivityCode3[2];
	char    sAddActivityCode3[3];
	char    sActivityCode4[2];
	char    sAddActivityCode4[3];
	char    sActivityCode5[2];
	char    sAddActivityCode5[3];
	char    sMsc[16];
	char    sLac[6];
	char    sCellularSigns[6];
	char    sMobileCode[2];
	char    sCallTime[15];
	char    sPayUnits[7];
	char    sAmountData[7];
	int     iTollFee;
	char    sTollProjects[2];
	char    sTaxRate[11];
	char    sRate1[11];
	char    sRetention[18];
	char    sRate2[11];
	char    sSdr[16];
	char    sState[3];
	char    sFileName[33];
	char	sRowID[19];
	struct PstnDetailTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FPstnDetailTicketStruct{

	char    sRecordType[2];
	char    sCompany[5];
	char    sReference[6];
	char    sNone[1];
	char    sImsi[15];
	char    sCallingNbr[25];
	char    sModifyIns[1];
	char    sNumberType[1];
	char    sPickProgram[1];
	char    sCalledNbr[25];
	char    sServiceType[1];
	char    sServiceNbr[8];
	char    sDualType[1];
	char    sDualNbr[2];
	char    sReqChannel[1];
	char    sUseChannel[1];
	char    sServiceTran[1];
	char    sActivityCode1[1];
	char    sAddActivityCode1[2];
	char    sActivityCode2[1];
	char    sAddActivityCode2[2];
	char    sActivityCode3[1];
	char    sAddActivityCode3[2];
	char    sActivityCode4[1];
	char    sAddActivityCode4[2];
	char    sActivityCode5[1];
	char    sAddActivityCode5[2];
	char    sMsc[15];
	char    sLac[5];
	char    sCellularSigns[5];
	char    sMobileCode[1];
	char    sCallTime[14];
	char    sPayUnits[6];
	char    sAmountData[6];
	char    sTollFee[9];
	char    sTollProjects[1];
	char    sTaxRate[10];
	char    sRate1[10];
	char    sRetention[17];
	char    sRate2[10];
	char    sSdr[15];
};

/*批量数据动态从PSTN_DETAIL_TICKET中用结构缓冲方式取数据*/
int EGetPstnDetailTicketToStruct(struct PstnDetailTicketStruct *p,
	struct PstnDetailTicketStructIn *pSource);
/*时间条件*/
int EGetPstnDetailTicketToStructByDate(struct PstnDetailTicketStruct *p,
	struct PstnDetailTicketStructIn *pSource);
void mvitem_fmpstndetailticket(struct FPstnDetailTicketStruct *pi,struct PstnDetailTicketStruct *po);	
/*批量数据结构缓冲写入PSTN_DETAIL_TICKET*/
int EInsertStructToPstnDetailTicket(struct PstnDetailTicketStruct *p,
	int iInsertFlag,struct PstnDetailTicketStructOut *pTarget);
/*更新STATE，1表示已统计*/
int EUpdateStructToPstnDetailTicket(struct PstnDetailTicketStruct *p,
	int iInsertFlag,struct PstnDetailTicketStructOut *pTarget);
	


/*---------基本部分代码 detail_stat_report.txt----------*/

/*输出结构缓冲申明*/
struct DetailStatReportStructOut{

#ifndef DETAIL_STAT_REPORT_BUFLEN_OUT
#define DETAIL_STAT_REPORT_BUFLEN_OUT		300
#endif

	struct DetailStatReportStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[DETAIL_STAT_REPORT_BUFLEN_OUT][3];
	char    asCompany[DETAIL_STAT_REPORT_BUFLEN_OUT][6];
	char    asImsi[DETAIL_STAT_REPORT_BUFLEN_OUT][16];
	char    asCallingNbr[DETAIL_STAT_REPORT_BUFLEN_OUT][26];
	char    asNumberType[DETAIL_STAT_REPORT_BUFLEN_OUT][2];
	char    asCalledNbr[DETAIL_STAT_REPORT_BUFLEN_OUT][26];
	char    asServiceType[DETAIL_STAT_REPORT_BUFLEN_OUT][2];
	char    asServiceNbr[DETAIL_STAT_REPORT_BUFLEN_OUT][9];
	char    asDualType[DETAIL_STAT_REPORT_BUFLEN_OUT][2];
	char    asDualNbr[DETAIL_STAT_REPORT_BUFLEN_OUT][3];
	char    asMsc[DETAIL_STAT_REPORT_BUFLEN_OUT][16];
	char    asLac[DETAIL_STAT_REPORT_BUFLEN_OUT][6];
	char    asMobileCode[DETAIL_STAT_REPORT_BUFLEN_OUT][2];
	char    asCallTime[DETAIL_STAT_REPORT_BUFLEN_OUT][15];
	char    asPayUnits[DETAIL_STAT_REPORT_BUFLEN_OUT][7];
	char    asAmountData[DETAIL_STAT_REPORT_BUFLEN_OUT][7];
	char    asTollProjects[DETAIL_STAT_REPORT_BUFLEN_OUT][2];
	char    asRate1[DETAIL_STAT_REPORT_BUFLEN_OUT][11];
	char    asRate2[DETAIL_STAT_REPORT_BUFLEN_OUT][11];
	char    asCnt[DETAIL_STAT_REPORT_BUFLEN_OUT][13];
	char    asTollFee[DETAIL_STAT_REPORT_BUFLEN_OUT][13];
	char    asSdr[DETAIL_STAT_REPORT_BUFLEN_OUT][16];
};


/* 输入结构缓冲申明*/
struct DetailStatReportStructIn{

#ifndef DETAIL_STAT_REPORT_BUFLEN_IN
#define DETAIL_STAT_REPORT_BUFLEN_IN		300
#endif

	struct DetailStatReportStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[DETAIL_STAT_REPORT_BUFLEN_IN][3];
	char    asCompany[DETAIL_STAT_REPORT_BUFLEN_IN][6];
	char    asImsi[DETAIL_STAT_REPORT_BUFLEN_IN][16];
	char    asCallingNbr[DETAIL_STAT_REPORT_BUFLEN_IN][26];
	char    asNumberType[DETAIL_STAT_REPORT_BUFLEN_IN][2];
	char    asCalledNbr[DETAIL_STAT_REPORT_BUFLEN_IN][26];
	char    asServiceType[DETAIL_STAT_REPORT_BUFLEN_IN][2];
	char    asServiceNbr[DETAIL_STAT_REPORT_BUFLEN_IN][9];
	char    asDualType[DETAIL_STAT_REPORT_BUFLEN_IN][2];
	char    asDualNbr[DETAIL_STAT_REPORT_BUFLEN_IN][3];
	char    asMsc[DETAIL_STAT_REPORT_BUFLEN_IN][16];
	char    asLac[DETAIL_STAT_REPORT_BUFLEN_IN][6];
	char    asMobileCode[DETAIL_STAT_REPORT_BUFLEN_IN][2];
	char    asCallTime[DETAIL_STAT_REPORT_BUFLEN_IN][15];
	char    asPayUnits[DETAIL_STAT_REPORT_BUFLEN_IN][7];
	char    asAmountData[DETAIL_STAT_REPORT_BUFLEN_IN][7];
	char    asTollProjects[DETAIL_STAT_REPORT_BUFLEN_IN][2];
	char    asRate1[DETAIL_STAT_REPORT_BUFLEN_IN][11];
	char    asRate2[DETAIL_STAT_REPORT_BUFLEN_IN][11];
	char    asCnt[DETAIL_STAT_REPORT_BUFLEN_IN][13];
	char    asTollFee[DETAIL_STAT_REPORT_BUFLEN_IN][13];
	char    asSdr[DETAIL_STAT_REPORT_BUFLEN_IN][16];
};


/*单个结构申明*/
struct DetailStatReportStruct{

	struct DetailStatReportStruct *pNext;
	char    sRecordType[3];
	char    sCompany[6];
	char    sImsi[16];
	char    sCallingNbr[26];
	char    sNumberType[2];
	char    sCalledNbr[26];
	char    sServiceType[2];
	char    sServiceNbr[9];
	char    sDualType[2];
	char    sDualNbr[3];
	char    sMsc[16];
	char    sLac[6];
	char    sMobileCode[2];
	char    sCallTime[15];
	char    sPayUnits[7];
	char    sAmountData[7];
	char    sTollProjects[2];
	char    sRate1[11];
	char    sRate2[11];
	char    sCnt[13];
	char    sTollFee[13];
	char    sSdr[16];
	struct DetailStatReportStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FDetailStatReportStruct{

	char    sRecordType[2];
	char    sCompany[5];
	char    sImsi[15];
	char    sCallingNbr[25];
	char    sNumberType[1];
	char    sCalledNbr[25];
	char    sServiceType[1];
	char    sServiceNbr[8];
	char    sDualType[1];
	char    sDualNbr[2];
	char    sMsc[15];
	char    sLac[5];
	char    sMobileCode[1];
	char    sCallTime[14];
	char    sPayUnits[6];
	char    sAmountData[6];
	char    sTollProjects[1];
	char    sRate1[10];
	char    sRate2[10];
	char    sCnt[12];
	char    sTollFee[12];
	char    sSdr[15];
};


/*批量数据动态从DETAIL_STAT_REPORT中用结构缓冲方式取数据*/
int EGetDetailStatReportToStruct(struct DetailStatReportStruct *p,
	struct DetailStatReportStructIn *pSource);

/*批量数据结构缓冲写入DETAIL_STAT_REPORT*/
int EInsertStructToDetailStatReport(struct DetailStatReportStruct *p,
	int iInsertFlag,struct DetailStatReportStructOut *pTarget);


/*---------基本部分代码 high_ticket_log.txt----------*/

/*输出结构缓冲申明*/
struct HighTicketLogStructOut{

#ifndef HIGH_TICKET_LOG_BUFLEN_OUT
#define HIGH_TICKET_LOG_BUFLEN_OUT		300
#endif

	struct HighTicketLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiHighTicketSeq[HIGH_TICKET_LOG_BUFLEN_OUT];
	char    asFileName[HIGH_TICKET_LOG_BUFLEN_OUT][33];
	char    asFileDate[HIGH_TICKET_LOG_BUFLEN_OUT][9];
	char    asDealTime[HIGH_TICKET_LOG_BUFLEN_OUT][15];
	char    asState[HIGH_TICKET_LOG_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct HighTicketLogStructIn{

#ifndef HIGH_TICKET_LOG_BUFLEN_IN
#define HIGH_TICKET_LOG_BUFLEN_IN		300
#endif

	struct HighTicketLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiHighTicketSeq[HIGH_TICKET_LOG_BUFLEN_IN];
	char    asFileName[HIGH_TICKET_LOG_BUFLEN_IN][33];
	char    asFileDate[HIGH_TICKET_LOG_BUFLEN_IN][9];
	char    asDealTime[HIGH_TICKET_LOG_BUFLEN_IN][15];
	char    asState[HIGH_TICKET_LOG_BUFLEN_IN][2];
};


/*单个结构申明*/
struct HighTicketLogStruct{

	struct HighTicketLogStruct *pNext;
	int     iHighTicketSeq;
	char    sFileName[33];
	char    sFileDate[9];
	char    sDealTime[15];
	char    sState[2];
	struct HighTicketLogStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FHighTicketLogStruct{

	char    sHighTicketSeq[9];
	char    sFileName[32];
	char    sFileDate[8];
	char    sDealTime[14];
	char    sState[1];
};
/*单条数据从用动态SQL从HIGH_TICKET_LOG取数据*/
int SDGetHighTicketLogToStruct(struct HighTicketLogStruct *p,char sTableName[],char sCondition[]);
/*单条数据动态SQL向HIGH_TICKET_LOG写数据*/
int SDInsertStructToHighTicketLog(struct HighTicketLogStruct *p,char sTableName[]);


/*---------基本部分代码 srt_ticket_03.txt----------*/

/*输出结构缓冲申明*/
struct SrtTicket03StructOut{

#ifndef SRT_TICKET_03_BUFLEN_OUT
#define SRT_TICKET_03_BUFLEN_OUT		300
#endif

	struct SrtTicket03StructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiTicketTypeID[SRT_TICKET_03_BUFLEN_OUT];
	char    asCallType[SRT_TICKET_03_BUFLEN_OUT][3];
	char    asMsisdn[SRT_TICKET_03_BUFLEN_OUT][16];
	char    asCalledCode[SRT_TICKET_03_BUFLEN_OUT][6];
	char    asOtherParty[SRT_TICKET_03_BUFLEN_OUT][25];
	char    asVisitAreaCode[SRT_TICKET_03_BUFLEN_OUT][6];
	int     aiRoamFee[SRT_TICKET_03_BUFLEN_OUT];
	int     aiTollFee[SRT_TICKET_03_BUFLEN_OUT];
	int     aiAddFee[SRT_TICKET_03_BUFLEN_OUT];
	int     aiDuration[SRT_TICKET_03_BUFLEN_OUT];
	char    asStartTime[SRT_TICKET_03_BUFLEN_OUT][15];
	char    asHomeAreaCode[SRT_TICKET_03_BUFLEN_OUT][6];
	char    asRoamType[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asDistanceType[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asOppType[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asUserType[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asSplitRuleID[SRT_TICKET_03_BUFLEN_OUT][5];
	char    asOppRoamType[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asServiceType[SRT_TICKET_03_BUFLEN_OUT][4];
	char    asServiceCode[SRT_TICKET_03_BUFLEN_OUT][5];
	char    asImsi[SRT_TICKET_03_BUFLEN_OUT][16];
	char    asMsc[SRT_TICKET_03_BUFLEN_OUT][16];
	char    asLac[SRT_TICKET_03_BUFLEN_OUT][6];
	char    asCellID[SRT_TICKET_03_BUFLEN_OUT][6];
	char    asOtherLac[SRT_TICKET_03_BUFLEN_OUT][6];
	char    asOtherCellID[SRT_TICKET_03_BUFLEN_OUT][6];
	char    asTrunkIn[SRT_TICKET_03_BUFLEN_OUT][8];
	char    asTrunkOut[SRT_TICKET_03_BUFLEN_OUT][8];
	char    asThirdParty[SRT_TICKET_03_BUFLEN_OUT][16];
	char    asMsrn[SRT_TICKET_03_BUFLEN_OUT][13];
	int     aiTrunkInTypeID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiTrunkOutTypeID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiTrunkInCarrierID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiTrunkOutCarrierID[SRT_TICKET_03_BUFLEN_OUT];
	char    asTrunkInType[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asTrunkOutType[SRT_TICKET_03_BUFLEN_OUT][2];
	int     aiCallingCarrierID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiCalledCarrierID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiCallingTypeID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiCalledTypeID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiCallingAreaID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiCalledAreaID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiASettAreaID[SRT_TICKET_03_BUFLEN_OUT];
	int     aiBSettAreaID[SRT_TICKET_03_BUFLEN_OUT];
	char    asSplitType[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asCal[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asEsn[SRT_TICKET_03_BUFLEN_OUT][16];
	char    asScpFlag[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asDeformFlag[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asReserve[SRT_TICKET_03_BUFLEN_OUT][9];
	char    asBillMode[SRT_TICKET_03_BUFLEN_OUT][4];
	char    asReserve1[SRT_TICKET_03_BUFLEN_OUT][3];
	char    asRoamTariffType[SRT_TICKET_03_BUFLEN_OUT][4];
	char    asTollTariffType[SRT_TICKET_03_BUFLEN_OUT][4];
	char    asAddTariffType[SRT_TICKET_03_BUFLEN_OUT][4];
	char    asErrCode[SRT_TICKET_03_BUFLEN_OUT][5];
	char    asFileName[SRT_TICKET_03_BUFLEN_OUT][20];
	char    asModule[SRT_TICKET_03_BUFLEN_OUT][4];
	char    asAreaCode[SRT_TICKET_03_BUFLEN_OUT][6];
	char    asState[SRT_TICKET_03_BUFLEN_OUT][2];
	char    asUpdateDate[SRT_TICKET_03_BUFLEN_OUT][15];
	char    asDealDate[SRT_TICKET_03_BUFLEN_OUT][15];
	char    asSourceID[SRT_TICKET_03_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct SrtTicket03StructIn{

#ifndef SRT_TICKET_03_BUFLEN_IN
#define SRT_TICKET_03_BUFLEN_IN		300
#endif

	struct SrtTicket03StructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[128];
	char sCondition[4096];
	int     aiTicketTypeID[SRT_TICKET_03_BUFLEN_IN];
	char    asCallType[SRT_TICKET_03_BUFLEN_IN][3];
	char    asMsisdn[SRT_TICKET_03_BUFLEN_IN][16];
	char    asCalledCode[SRT_TICKET_03_BUFLEN_IN][6];
	char    asOtherParty[SRT_TICKET_03_BUFLEN_IN][25];
	char    asVisitAreaCode[SRT_TICKET_03_BUFLEN_IN][6];
	int     aiRoamFee[SRT_TICKET_03_BUFLEN_IN];
	int     aiTollFee[SRT_TICKET_03_BUFLEN_IN];
	int     aiAddFee[SRT_TICKET_03_BUFLEN_IN];
	int     aiDuration[SRT_TICKET_03_BUFLEN_IN];
	char    asStartTime[SRT_TICKET_03_BUFLEN_IN][15];
	char    asHomeAreaCode[SRT_TICKET_03_BUFLEN_IN][6];
	char    asRoamType[SRT_TICKET_03_BUFLEN_IN][2];
	char    asDistanceType[SRT_TICKET_03_BUFLEN_IN][2];
	char    asOppType[SRT_TICKET_03_BUFLEN_IN][2];
	char    asUserType[SRT_TICKET_03_BUFLEN_IN][2];
	char    asSplitRuleID[SRT_TICKET_03_BUFLEN_IN][5];
	char    asOppRoamType[SRT_TICKET_03_BUFLEN_IN][2];
	char    asServiceType[SRT_TICKET_03_BUFLEN_IN][4];
	char    asServiceCode[SRT_TICKET_03_BUFLEN_IN][5];
	char    asImsi[SRT_TICKET_03_BUFLEN_IN][16];
	char    asMsc[SRT_TICKET_03_BUFLEN_IN][16];
	char    asLac[SRT_TICKET_03_BUFLEN_IN][6];
	char    asCellID[SRT_TICKET_03_BUFLEN_IN][6];
	char    asOtherLac[SRT_TICKET_03_BUFLEN_IN][6];
	char    asOtherCellID[SRT_TICKET_03_BUFLEN_IN][6];
	char    asTrunkIn[SRT_TICKET_03_BUFLEN_IN][8];
	char    asTrunkOut[SRT_TICKET_03_BUFLEN_IN][8];
	char    asThirdParty[SRT_TICKET_03_BUFLEN_IN][16];
	char    asMsrn[SRT_TICKET_03_BUFLEN_IN][13];
	int     aiTrunkInTypeID[SRT_TICKET_03_BUFLEN_IN];
	int     aiTrunkOutTypeID[SRT_TICKET_03_BUFLEN_IN];
	int     aiTrunkInCarrierID[SRT_TICKET_03_BUFLEN_IN];
	int     aiTrunkOutCarrierID[SRT_TICKET_03_BUFLEN_IN];
	char    asTrunkInType[SRT_TICKET_03_BUFLEN_IN][2];
	char    asTrunkOutType[SRT_TICKET_03_BUFLEN_IN][2];
	int     aiCallingCarrierID[SRT_TICKET_03_BUFLEN_IN];
	int     aiCalledCarrierID[SRT_TICKET_03_BUFLEN_IN];
	int     aiCallingTypeID[SRT_TICKET_03_BUFLEN_IN];
	int     aiCalledTypeID[SRT_TICKET_03_BUFLEN_IN];
	int     aiCallingAreaID[SRT_TICKET_03_BUFLEN_IN];
	int     aiCalledAreaID[SRT_TICKET_03_BUFLEN_IN];
	int     aiASettAreaID[SRT_TICKET_03_BUFLEN_IN];
	int     aiBSettAreaID[SRT_TICKET_03_BUFLEN_IN];
	char    asSplitType[SRT_TICKET_03_BUFLEN_IN][2];
	char    asCal[SRT_TICKET_03_BUFLEN_IN][2];
	char    asEsn[SRT_TICKET_03_BUFLEN_IN][16];
	char    asScpFlag[SRT_TICKET_03_BUFLEN_IN][2];
	char    asDeformFlag[SRT_TICKET_03_BUFLEN_IN][2];
	char    asReserve[SRT_TICKET_03_BUFLEN_IN][9];
	char    asBillMode[SRT_TICKET_03_BUFLEN_IN][4];
	char    asReserve1[SRT_TICKET_03_BUFLEN_IN][3];
	char    asRoamTariffType[SRT_TICKET_03_BUFLEN_IN][4];
	char    asTollTariffType[SRT_TICKET_03_BUFLEN_IN][4];
	char    asAddTariffType[SRT_TICKET_03_BUFLEN_IN][4];
	char    asErrCode[SRT_TICKET_03_BUFLEN_IN][5];
	char    asFileName[SRT_TICKET_03_BUFLEN_IN][20];
	char    asModule[SRT_TICKET_03_BUFLEN_IN][4];
	char    asAreaCode[SRT_TICKET_03_BUFLEN_IN][6];
	char    asState[SRT_TICKET_03_BUFLEN_IN][2];
	char    asUpdateDate[SRT_TICKET_03_BUFLEN_IN][15];
	char    asDealDate[SRT_TICKET_03_BUFLEN_IN][15];
	char    asSourceID[SRT_TICKET_03_BUFLEN_IN][41];
};


/*单个结构申明*/
struct SrtTicket03Struct{

	struct SrtTicket03Struct *pNext;
	int     iTicketTypeID;
	char    sCallType[3];
	char    sMsisdn[16];
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
	char    sOppType[2];
	char    sUserType[2];
	char    sSplitRuleID[5];
	char    sOppRoamType[2];
	char    sServiceType[4];
	char    sServiceCode[5];
	char    sImsi[16];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sOtherLac[6];
	char    sOtherCellID[6];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sThirdParty[16];
	char    sMsrn[13];
	int     iTrunkInTypeID;
	int     iTrunkOutTypeID;
	int     iTrunkInCarrierID;
	int     iTrunkOutCarrierID;
	char    sTrunkInType[2];
	char    sTrunkOutType[2];
	int     iCallingCarrierID;
	int     iCalledCarrierID;
	int     iCallingTypeID;
	int     iCalledTypeID;
	int     iCallingAreaID;
	int     iCalledAreaID;
	int     iASettAreaID;
	int     iBSettAreaID;
	char    sSplitType[2];
	char    sCal[2];
	char    sEsn[16];
	char    sScpFlag[2];
	char    sDeformFlag[2];
	char    sReserve[9];
	char    sBillMode[4];
	char    sReserve1[3];
	char    sRoamTariffType[4];
	char    sTollTariffType[4];
	char    sAddTariffType[4];
	char    sErrCode[5];
	char    sFileName[20];
	char    sModule[4];
	char    sAreaCode[6];
	char    sState[2];
	char    sUpdateDate[15];
	char    sDealDate[15];
	char    sSourceID[41];
	struct SrtTicket03Struct *pLoadNext;
};


/*单个文件结构申明*/
struct FSrtTicket03Struct{

	char    sTicketTypeID[4];
	char    sCallType[2];
	char    sMsisdn[15];
	char    sCalledCode[5];
	char    sOtherParty[24];
	char    sVisitAreaCode[5];
	char    sRoamFee[5];
	char    sTollFee[7];
	char    sAddFee[5];
	char    sDuration[6];
	char    sStartTime[14];
	char    sHomeAreaCode[5];
	char    sRoamType[1];
	char    sDistanceType[1];
	char    sOppType[1];
	char    sUserType[1];
	char    sSplitRuleID[4];
	char    sOppRoamType[1];
	char    sServiceType[3];
	char    sServiceCode[4];
	char    sImsi[15];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sOtherLac[5];
	char    sOtherCellID[5];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sThirdParty[15];
	char    sMsrn[12];
	char    sTrunkInTypeID[4];
	char    sTrunkOutTypeID[4];
	char    sTrunkInCarrierID[4];
	char    sTrunkOutCarrierID[4];
	char    sTrunkInType[1];
	char    sTrunkOutType[1];
	char    sCallingCarrierID[4];
	char    sCalledCarrierID[4];
	char    sCallingTypeID[4];
	char    sCalledTypeID[4];
	char    sCallingAreaID[4];
	char    sCalledAreaID[4];
	char    sASettAreaID[4];
	char    sBSettAreaID[4];
	char    sSplitType[1];
	char    sCal[1];
	char    sEsn[15];
	char    sScpFlag[1];
	char    sDeformFlag[1];
	char    sReserve[8];
	char    sBillMode[3];
	char    sReserve1[2];
	char    sRoamTariffType[3];
	char    sTollTariffType[3];
	char    sAddTariffType[3];
	char    sErrCode[4];
	char    sFileName[19];
	char    sModule[3];
	char    sAreaCode[5];
	char    sState[1];
	char    sUpdateDate[14];
	char    sDealDate[14];
	char    sSourceID[40];
};


/*批量数据动态从SRT_TICKET_03中用结构缓冲方式取数据*/
int EGetSrtTicket03ToStruct(struct SrtTicket03Struct *p,
	struct SrtTicket03StructIn *pSource);




#endif
