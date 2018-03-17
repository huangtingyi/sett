#ifndef _HIGH_SUPP_H_
#define _HIGH_SUPP_H_


/*---------�������ִ��� imei_up.txt----------*/

/*����ṹ��������*/
struct ImeiUpStructOut{

#ifndef IMEI_UP_BUFLEN_OUT
#define IMEI_UP_BUFLEN_OUT		300
#endif

	struct ImeiUpStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ���к� */
	char    asRsSeq[IMEI_UP_BUFLEN_OUT][19];
		/* �û����� */
	char    asMsisdn[IMEI_UP_BUFLEN_OUT][21];
		/* IMEI�ţ��ֻ����Ӵ��� */
	char    asImei[IMEI_UP_BUFLEN_OUT][31];
		/* �����ƶ��û�ʶ���� */
	char    asImsi[IMEI_UP_BUFLEN_OUT][21];
		/* ͨ��ʱ�� */
	char    asCallstarttime[IMEI_UP_BUFLEN_OUT][15];
		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    asMatchitem[IMEI_UP_BUFLEN_OUT][2];
		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char    asType[IMEI_UP_BUFLEN_OUT][2];
		/* ��¼����ʱ�� */
	char    asCreatetime[IMEI_UP_BUFLEN_OUT][21];
};


/* ����ṹ��������*/
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
		/* ���к� */
	char    asRsSeq[IMEI_UP_BUFLEN_IN][19];
		/* �û����� */
	char    asMsisdn[IMEI_UP_BUFLEN_IN][21];
		/* IMEI�ţ��ֻ����Ӵ��� */
	char    asImei[IMEI_UP_BUFLEN_IN][31];
		/* �����ƶ��û�ʶ���� */
	char    asImsi[IMEI_UP_BUFLEN_IN][21];
		/* ͨ��ʱ�� */
	char    asCallstarttime[IMEI_UP_BUFLEN_IN][15];
		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    asMatchitem[IMEI_UP_BUFLEN_IN][2];
		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char    asType[IMEI_UP_BUFLEN_IN][2];
		/* ��¼����ʱ�� */
	char    asCreatetime[IMEI_UP_BUFLEN_IN][21];
};


/*�����ṹ����*/
struct ImeiUpStruct{

	struct ImeiUpStruct *pNext;
	char    sRsSeq[19];		/* ���к� */
	char    sMsisdn[21];		/* �û����� */
	char    sImei[31];		/* IMEI�ţ��ֻ����Ӵ��� */
	char    sImsi[21];		/* �����ƶ��û�ʶ���� */
	char    sCallstarttime[15];		/* ͨ��ʱ�� */
	char    sMatchitem[2];		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    sType[2];		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char    sCreatetime[21];		/* ��¼����ʱ�� */
	struct ImeiUpStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FImeiUpStruct{

	char    sRsSeq[18];		/* ���к� */
	char    sMsisdn[20];		/* �û����� */
	char    sImei[30];		/* IMEI�ţ��ֻ����Ӵ��� */
	char    sImsi[20];		/* �����ƶ��û�ʶ���� */
	char    sCallstarttime[14];		/* ͨ��ʱ�� */
	char    sMatchitem[1];		/* ƥ������1��BSS2����ע��3�����롡4������ */
	char    sType[1];		/* �������ͣ�����ʾ��ʡ������ʾ���� */
	char    sCreatetime[20];		/* ��¼����ʱ�� */
};


/*�������ݶ�̬��IMEI_UP���ýṹ���巽ʽȡ����*/
int EGetImeiUpToStruct(struct ImeiUpStruct *p,
	struct ImeiUpStructIn *pSource);


/*---------�������ִ��� pstn_detail_ticket.txt----------*/

/*����ṹ��������*/
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
	int     aiSdr[PSTN_DETAIL_TICKET_BUFLEN_OUT];
	char    asState[PSTN_DETAIL_TICKET_BUFLEN_OUT][3];
	char    asFileName[PSTN_DETAIL_TICKET_BUFLEN_OUT][33];
	char	asRowID[PSTN_DETAIL_TICKET_BUFLEN_OUT][19];
};


/* ����ṹ��������*/
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
	int     aiSdr[PSTN_DETAIL_TICKET_BUFLEN_IN];
	char    asState[PSTN_DETAIL_TICKET_BUFLEN_IN][3];
	char    asFileName[PSTN_DETAIL_TICKET_BUFLEN_IN][33];
	char	asRowID[PSTN_DETAIL_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
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
	int     iSdr;
	char    sState[3];
	char    sFileName[33];
	char	sRowID[19];
	struct PstnDetailTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
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
	char    sSdr[9];
};

/*�������ݶ�̬��PSTN_DETAIL_TICKET���ýṹ���巽ʽȡ����*/
int EGetPstnDetailTicketToStruct(struct PstnDetailTicketStruct *p,
	struct PstnDetailTicketStructIn *pSource);
/*ʱ������*/
int EGetPstnDetailTicketToStructByDate(struct PstnDetailTicketStruct *p,
	struct PstnDetailTicketStructIn *pSource);
void mvitem_fmpstndetailticket(struct FPstnDetailTicketStruct *pi,struct PstnDetailTicketStruct *po);	
/*�������ݽṹ����д��PSTN_DETAIL_TICKET*/
int EInsertStructToPstnDetailTicket(struct PstnDetailTicketStruct *p,
	int iInsertFlag,struct PstnDetailTicketStructOut *pTarget);
/*����STATE��1��ʾ��ͳ��*/
int EUpdateStructToPstnDetailTicket(struct PstnDetailTicketStruct *p,
	int iInsertFlag,struct PstnDetailTicketStructOut *pTarget);
	


/*---------�������ִ��� detail_stat_report.txt----------*/

/*����ṹ��������*/
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
	char    asSdr[DETAIL_STAT_REPORT_BUFLEN_OUT][13];
};


/* ����ṹ��������*/
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
	char    asSdr[DETAIL_STAT_REPORT_BUFLEN_IN][13];
};


/*�����ṹ����*/
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
	char    sSdr[13];
	struct DetailStatReportStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
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
	char    sSdr[12];
};


/*�������ݶ�̬��DETAIL_STAT_REPORT���ýṹ���巽ʽȡ����*/
int EGetDetailStatReportToStruct(struct DetailStatReportStruct *p,
	struct DetailStatReportStructIn *pSource);

/*�������ݽṹ����д��DETAIL_STAT_REPORT*/
int EInsertStructToDetailStatReport(struct DetailStatReportStruct *p,
	int iInsertFlag,struct DetailStatReportStructOut *pTarget);


/*---------�������ִ��� high_ticket_log.txt----------*/

/*����ṹ��������*/
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


/* ����ṹ��������*/
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


/*�����ṹ����*/
struct HighTicketLogStruct{

	struct HighTicketLogStruct *pNext;
	int     iHighTicketSeq;
	char    sFileName[33];
	char    sFileDate[9];
	char    sDealTime[15];
	char    sState[2];
	struct HighTicketLogStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FHighTicketLogStruct{

	char    sHighTicketSeq[9];
	char    sFileName[32];
	char    sFileDate[8];
	char    sDealTime[14];
	char    sState[1];
};
/*�������ݴ��ö�̬SQL��HIGH_TICKET_LOGȡ����*/
int SDGetHighTicketLogToStruct(struct HighTicketLogStruct *p,char sTableName[],char sCondition[]);
/*�������ݶ�̬SQL��HIGH_TICKET_LOGд����*/
int SDInsertStructToHighTicketLog(struct HighTicketLogStruct *p,char sTableName[]);




#endif
