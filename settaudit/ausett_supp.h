#ifndef _AUSETT_SUPP_H_
#define _AUSETT_SUPP_H_


/*---------�������ִ��� report_item_config.txt----------*/

/*����ṹ��������*/
struct ReportItemConfigStructOut{

#ifndef REPORT_ITEM_CONFIG_BUFLEN_OUT
#define REPORT_ITEM_CONFIG_BUFLEN_OUT		300
#endif

	struct ReportItemConfigStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[64];
		/* �����ǰ6λ����ID������λ��ID�� */
	int     aiReportItemID[REPORT_ITEM_CONFIG_BUFLEN_OUT];
		/* 0��֧��, 1������, *���޼�¼, 2��ֻͳ�� */
	char    asFeeType[REPORT_ITEM_CONFIG_BUFLEN_OUT][3];
		/* �������� */
	char    asTicketTypeID[REPORT_ITEM_CONFIG_BUFLEN_OUT][31];
		/* �����ֶ� */
	char    asColumnName[REPORT_ITEM_CONFIG_BUFLEN_OUT][31];
		/* ֵ */
	char    asColumnValue[REPORT_ITEM_CONFIG_BUFLEN_OUT][61];
		/* �ֶο��ƺ�����1Ϊin��2Ϊ not in  ... */
	int     aiColumnCtrl[REPORT_ITEM_CONFIG_BUFLEN_OUT];
		/* �������ͣ�GSM��������������Ź��� 10,�����cdma 11,���ƶ� 12,����ͨ 13;������������������Ź��� 20,�����cdma 21, ���ƶ� 22,����ͨ 23�� */
	char    asSettType[REPORT_ITEM_CONFIG_BUFLEN_OUT][6];
};


/* ����ṹ��������*/
struct ReportItemConfigStructIn{

#ifndef REPORT_ITEM_CONFIG_BUFLEN_IN
#define REPORT_ITEM_CONFIG_BUFLEN_IN		300
#endif

	struct ReportItemConfigStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[64];
	char sCondition[1024];
		/* �����ǰ6λ����ID������λ��ID�� */
	int     aiReportItemID[REPORT_ITEM_CONFIG_BUFLEN_IN];
		/* 0��֧��, 1������, *���޼�¼, 2��ֻͳ�� */
	char    asFeeType[REPORT_ITEM_CONFIG_BUFLEN_IN][3];
		/* �������� */
	char    asTicketTypeID[REPORT_ITEM_CONFIG_BUFLEN_IN][31];
		/* �����ֶ� */
	char    asColumnName[REPORT_ITEM_CONFIG_BUFLEN_IN][31];
		/* ֵ */
	char    asColumnValue[REPORT_ITEM_CONFIG_BUFLEN_IN][61];
		/* �ֶο��ƺ�����1Ϊin��2Ϊ not in  ... */
	int     aiColumnCtrl[REPORT_ITEM_CONFIG_BUFLEN_IN];
		/* �������ͣ�GSM��������������Ź��� 10,�����cdma 11,���ƶ� 12,����ͨ 13;������������������Ź��� 20,�����cdma 21, ���ƶ� 22,����ͨ 23�� */
	char    asSettType[REPORT_ITEM_CONFIG_BUFLEN_IN][6];
};


/*�����ṹ����*/
struct ReportItemConfigStruct{

	struct ReportItemConfigStruct *pNext;
	int     iReportItemID;		/* �����ǰ6λ����ID������λ��ID�� */
	char    sFeeType[3];		/* 0��֧��, 1������, *���޼�¼, 2��ֻͳ�� */
	char    sTicketTypeID[31];		/* �������� */
	char    sColumnName[31];		/* �����ֶ� */
	char    sColumnValue[61];		/* ֵ */
	int     iColumnCtrl;		/* �ֶο��ƺ�����1Ϊin��2Ϊ not in  ... */
	char    sSettType[6];		/* �������ͣ�GSM��������������Ź��� 10,�����cdma 11,���ƶ� 12,����ͨ 13;������������������Ź��� 20,�����cdma 21, ���ƶ� 22,����ͨ 23�� */
	struct ReportItemConfigStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FReportItemConfigStruct{

	char    sReportItemID[8];		/* �����ǰ6λ����ID������λ��ID�� */
	char    sFeeType[2];		/* 0��֧��, 1������, *���޼�¼, 2��ֻͳ�� */
	char    sTicketTypeID[30];		/* �������� */
	char    sColumnName[30];		/* �����ֶ� */
	char    sColumnValue[60];		/* ֵ */
	char    sColumnCtrl[3];		/* �ֶο��ƺ�����1Ϊin��2Ϊ not in  ... */
	char    sSettType[5];		/* �������ͣ�GSM��������������Ź��� 10,�����cdma 11,���ƶ� 12,����ͨ 13;������������������Ź��� 20,�����cdma 21, ���ƶ� 22,����ͨ 23�� */
};
void mvitem_fmreportitemconfig(struct FReportItemConfigStruct *pi,struct ReportItemConfigStruct *po);
/*�������ݶ�̬��REPORT_ITEM_CONFIG���ýṹ���巽ʽȡ����*/
int EGetReportItemConfigToStruct(struct ReportItemConfigStruct *p,
	struct ReportItemConfigStructIn *pSource);



/*---------�������ִ��� stt_ticket.txt----------*/

/*����ṹ��������*/
struct SttTicketStructOut{

#ifndef STT_TICKET_BUFLEN_OUT
#define STT_TICKET_BUFLEN_OUT		300
#endif

	struct SttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiTicketTypeID[STT_TICKET_BUFLEN_OUT];
	char    asCallType[STT_TICKET_BUFLEN_OUT][3];
	char    asMsisdn[STT_TICKET_BUFLEN_OUT][16];
	char    asCalledCode[STT_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[STT_TICKET_BUFLEN_OUT][25];
	char    asVisitAreaCode[STT_TICKET_BUFLEN_OUT][6];
	int     aiRoamFee[STT_TICKET_BUFLEN_OUT];
	int     aiTollFee[STT_TICKET_BUFLEN_OUT];
	int     aiAddFee[STT_TICKET_BUFLEN_OUT];
	int     aiDuration[STT_TICKET_BUFLEN_OUT];
	char    asStartTime[STT_TICKET_BUFLEN_OUT][15];
	char    asHomeAreaCode[STT_TICKET_BUFLEN_OUT][6];
	char    asRoamType[STT_TICKET_BUFLEN_OUT][2];
	char    asDistanceType[STT_TICKET_BUFLEN_OUT][2];
	char    asOppType[STT_TICKET_BUFLEN_OUT][2];
	char    asUserType[STT_TICKET_BUFLEN_OUT][2];
	char    asSplitRuleID[STT_TICKET_BUFLEN_OUT][5];
	char    asOppRoamType[STT_TICKET_BUFLEN_OUT][2];
	char    asServiceType[STT_TICKET_BUFLEN_OUT][4];
	char    asServiceCode[STT_TICKET_BUFLEN_OUT][5];
	char    asImsi[STT_TICKET_BUFLEN_OUT][16];
	char    asMsc[STT_TICKET_BUFLEN_OUT][16];
	char    asLac[STT_TICKET_BUFLEN_OUT][6];
	char    asCellID[STT_TICKET_BUFLEN_OUT][6];
	char    asOtherLac[STT_TICKET_BUFLEN_OUT][6];
	char    asOtherCellID[STT_TICKET_BUFLEN_OUT][6];
	char    asTrunkIn[STT_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[STT_TICKET_BUFLEN_OUT][8];
	char    asThirdParty[STT_TICKET_BUFLEN_OUT][16];
	char    asMsrn[STT_TICKET_BUFLEN_OUT][13];
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_OUT];
	char    asTrunkInType[STT_TICKET_BUFLEN_OUT][2];
	char    asTrunkOutType[STT_TICKET_BUFLEN_OUT][2];
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_OUT];
	int     aiCallingTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledTypeID[STT_TICKET_BUFLEN_OUT];
	int     aiCallingAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiCalledAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiASettAreaID[STT_TICKET_BUFLEN_OUT];
	int     aiBSettAreaID[STT_TICKET_BUFLEN_OUT];
	char    asSplitType[STT_TICKET_BUFLEN_OUT][2];
	char    asCal[STT_TICKET_BUFLEN_OUT][2];
	char    asEsn[STT_TICKET_BUFLEN_OUT][16];
	char    asScpFlag[STT_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_OUT][2];
	char    asReserve[STT_TICKET_BUFLEN_OUT][9];
	char    asBillMode[STT_TICKET_BUFLEN_OUT][4];
	char    asReserve1[STT_TICKET_BUFLEN_OUT][3];
	char    asRoamTariffType[STT_TICKET_BUFLEN_OUT][4];
	char    asTollTariffType[STT_TICKET_BUFLEN_OUT][4];
	char    asAddTariffType[STT_TICKET_BUFLEN_OUT][4];
	char    asErrCode[STT_TICKET_BUFLEN_OUT][5];
	char    asFileName[STT_TICKET_BUFLEN_OUT][20];
	char    asModule[STT_TICKET_BUFLEN_OUT][4];
	char    asAreaCode[STT_TICKET_BUFLEN_OUT][6];
	char    asState[STT_TICKET_BUFLEN_OUT][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_OUT][15];
	char    asDealDate[STT_TICKET_BUFLEN_OUT][15];
	char    asSourceID[STT_TICKET_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct SttTicketStructIn{

#ifndef STT_TICKET_BUFLEN_IN
#define STT_TICKET_BUFLEN_IN		300
#endif

	struct SttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[128];
	char sCondition[1024];
	int     aiTicketTypeID[STT_TICKET_BUFLEN_IN];
	char    asCallType[STT_TICKET_BUFLEN_IN][3];
	char    asMsisdn[STT_TICKET_BUFLEN_IN][16];
	char    asCalledCode[STT_TICKET_BUFLEN_IN][6];
	char    asOtherParty[STT_TICKET_BUFLEN_IN][25];
	char    asVisitAreaCode[STT_TICKET_BUFLEN_IN][6];
	int     aiRoamFee[STT_TICKET_BUFLEN_IN];
	int     aiTollFee[STT_TICKET_BUFLEN_IN];
	int     aiAddFee[STT_TICKET_BUFLEN_IN];
	int     aiDuration[STT_TICKET_BUFLEN_IN];
	char    asStartTime[STT_TICKET_BUFLEN_IN][15];
	char    asHomeAreaCode[STT_TICKET_BUFLEN_IN][6];
	char    asRoamType[STT_TICKET_BUFLEN_IN][2];
	char    asDistanceType[STT_TICKET_BUFLEN_IN][2];
	char    asOppType[STT_TICKET_BUFLEN_IN][2];
	char    asUserType[STT_TICKET_BUFLEN_IN][2];
	char    asSplitRuleID[STT_TICKET_BUFLEN_IN][5];
	char    asOppRoamType[STT_TICKET_BUFLEN_IN][2];
	char    asServiceType[STT_TICKET_BUFLEN_IN][4];
	char    asServiceCode[STT_TICKET_BUFLEN_IN][5];
	char    asImsi[STT_TICKET_BUFLEN_IN][16];
	char    asMsc[STT_TICKET_BUFLEN_IN][16];
	char    asLac[STT_TICKET_BUFLEN_IN][6];
	char    asCellID[STT_TICKET_BUFLEN_IN][6];
	char    asOtherLac[STT_TICKET_BUFLEN_IN][6];
	char    asOtherCellID[STT_TICKET_BUFLEN_IN][6];
	char    asTrunkIn[STT_TICKET_BUFLEN_IN][8];
	char    asTrunkOut[STT_TICKET_BUFLEN_IN][8];
	char    asThirdParty[STT_TICKET_BUFLEN_IN][16];
	char    asMsrn[STT_TICKET_BUFLEN_IN][13];
	int     aiTrunkInTypeID[STT_TICKET_BUFLEN_IN];
	int     aiTrunkOutTypeID[STT_TICKET_BUFLEN_IN];
	int     aiTrunkInCarrierID[STT_TICKET_BUFLEN_IN];
	int     aiTrunkOutCarrierID[STT_TICKET_BUFLEN_IN];
	char    asTrunkInType[STT_TICKET_BUFLEN_IN][2];
	char    asTrunkOutType[STT_TICKET_BUFLEN_IN][2];
	int     aiCallingCarrierID[STT_TICKET_BUFLEN_IN];
	int     aiCalledCarrierID[STT_TICKET_BUFLEN_IN];
	int     aiCallingTypeID[STT_TICKET_BUFLEN_IN];
	int     aiCalledTypeID[STT_TICKET_BUFLEN_IN];
	int     aiCallingAreaID[STT_TICKET_BUFLEN_IN];
	int     aiCalledAreaID[STT_TICKET_BUFLEN_IN];
	int     aiASettAreaID[STT_TICKET_BUFLEN_IN];
	int     aiBSettAreaID[STT_TICKET_BUFLEN_IN];
	char    asSplitType[STT_TICKET_BUFLEN_IN][2];
	char    asCal[STT_TICKET_BUFLEN_IN][2];
	char    asEsn[STT_TICKET_BUFLEN_IN][16];
	char    asScpFlag[STT_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[STT_TICKET_BUFLEN_IN][2];
	char    asReserve[STT_TICKET_BUFLEN_IN][9];
	char    asBillMode[STT_TICKET_BUFLEN_IN][4];
	char    asReserve1[STT_TICKET_BUFLEN_IN][3];
	char    asRoamTariffType[STT_TICKET_BUFLEN_IN][4];
	char    asTollTariffType[STT_TICKET_BUFLEN_IN][4];
	char    asAddTariffType[STT_TICKET_BUFLEN_IN][4];
	char    asErrCode[STT_TICKET_BUFLEN_IN][5];
	char    asFileName[STT_TICKET_BUFLEN_IN][20];
	char    asModule[STT_TICKET_BUFLEN_IN][4];
	char    asAreaCode[STT_TICKET_BUFLEN_IN][6];
	char    asState[STT_TICKET_BUFLEN_IN][2];
	char    asUpdateDate[STT_TICKET_BUFLEN_IN][15];
	char    asDealDate[STT_TICKET_BUFLEN_IN][15];
	char    asSourceID[STT_TICKET_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct SttTicketStruct{

	struct SttTicketStruct *pNext;
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
	struct SttTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSttTicketStruct{

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
/*�������ݶ�̬��STT_TICKET���ýṹ���巽ʽȡ����*/
int EGetSttTicketToStruct_t(struct SttTicketStruct *p,
	struct SttTicketStructIn *pSource);
void mvitem_fmtemplatesttticket(struct FSttTicketStruct *pi,struct SttTicketStruct *po);
int InitSttTicket(struct SttTicketStruct **pptHead);


/*---------�������ִ��� au_sett_log.txt----------*/

/*����ṹ��������*/
struct AuSettLogStructOut{

#ifndef AU_SETT_LOG_BUFLEN_OUT
#define AU_SETT_LOG_BUFLEN_OUT		300
#endif

	struct AuSettLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������� */
	char    asDealTable[AU_SETT_LOG_BUFLEN_OUT][41];
		/* ��������� */
	char    asOutTableIn[AU_SETT_LOG_BUFLEN_OUT][41];
		/* ֧������� */
	char    asOutTableOut[AU_SETT_LOG_BUFLEN_OUT][41];
		/* ����ʱ�� */
	char    asDataDate[AU_SETT_LOG_BUFLEN_OUT][15];
		/* ����ʱ�� */
	char    asDealDate[AU_SETT_LOG_BUFLEN_OUT][15];
		/* P0F:����ʧ��  P0S:����ɹ�  60A:������ */
	char    asDealState[AU_SETT_LOG_BUFLEN_OUT][4];
};


/* ����ṹ��������*/
struct AuSettLogStructIn{

#ifndef AU_SETT_LOG_BUFLEN_IN
#define AU_SETT_LOG_BUFLEN_IN		300
#endif

	struct AuSettLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ������� */
	char    asDealTable[AU_SETT_LOG_BUFLEN_IN][41];
		/* ��������� */
	char    asOutTableIn[AU_SETT_LOG_BUFLEN_IN][41];
		/* ֧������� */
	char    asOutTableOut[AU_SETT_LOG_BUFLEN_IN][41];
		/* ����ʱ�� */
	char    asDataDate[AU_SETT_LOG_BUFLEN_IN][15];
		/* ����ʱ�� */
	char    asDealDate[AU_SETT_LOG_BUFLEN_IN][15];
		/* P0F:����ʧ��  P0S:����ɹ�  60A:������ */
	char    asDealState[AU_SETT_LOG_BUFLEN_IN][4];
};


/*�����ṹ����*/
struct AuSettLogStruct{

	struct AuSettLogStruct *pNext;
	char    sDealTable[41];		/* ������� */
	char    sOutTableIn[41];		/* ��������� */
	char    sOutTableOut[41];		/* ֧������� */
	char    sDataDate[15];		/* ����ʱ�� */
	char    sDealDate[15];		/* ����ʱ�� */
	char    sDealState[4];		/* P0F:����ʧ��  P0S:����ɹ�  60A:������ */
	struct AuSettLogStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FAuSettLogStruct{

	char    sDealTable[40];		/* ������� */
	char    sOutTableIn[40];		/* ��������� */
	char    sOutTableOut[40];		/* ֧������� */
	char    sDataDate[14];		/* ����ʱ�� */
	char    sDealDate[14];		/* ����ʱ�� */
	char    sDealState[3];		/* P0F:����ʧ��  P0S:����ɹ�  60A:������ */
};





/*---------�������ִ��� ���� ֧�� ���õĽṹ��----------*/

/*����ṹ��������*/
struct AuSettNbrStatStructOut{

#ifndef AU_SETT_NBR_STAT_BUFLEN_OUT
#define AU_SETT_NBR_STAT_BUFLEN_OUT		300
#endif

	struct AuSettNbrStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asAccNbr[AU_SETT_NBR_STAT_BUFLEN_OUT][21];
	char    asHomeAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_NBR_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_NBR_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_NBR_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_NBR_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asBillingCycleID[AU_SETT_NBR_STAT_BUFLEN_OUT][7];
	int     aiCnt[AU_SETT_NBR_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_NBR_STAT_BUFLEN_OUT];
};


/* ����ṹ��������*/
struct AuSettNbrStatStructIn{

#ifndef AU_SETT_NBR_STAT_BUFLEN_IN
#define AU_SETT_NBR_STAT_BUFLEN_IN		300
#endif

	struct AuSettNbrStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asAccNbr[AU_SETT_NBR_STAT_BUFLEN_IN][21];
	char    asHomeAreaCode[AU_SETT_NBR_STAT_BUFLEN_IN][6];
	char    asVisitAreaCode[AU_SETT_NBR_STAT_BUFLEN_IN][6];
	char    asCalledCode[AU_SETT_NBR_STAT_BUFLEN_IN][6];
	char    asNetType[AU_SETT_NBR_STAT_BUFLEN_IN][2];
	int     aiReportItemID[AU_SETT_NBR_STAT_BUFLEN_IN];
	char    asSettType[AU_SETT_NBR_STAT_BUFLEN_IN][3];
	char    asSettNbrType[AU_SETT_NBR_STAT_BUFLEN_IN][4];
	char    asSettCarrID[AU_SETT_NBR_STAT_BUFLEN_IN][2];
	char    asMsc[AU_SETT_NBR_STAT_BUFLEN_IN][16];
	char    asTrunkIn[AU_SETT_NBR_STAT_BUFLEN_IN][8];
	char    asTrunkOut[AU_SETT_NBR_STAT_BUFLEN_IN][8];
	char    asTrunkCarrierID[AU_SETT_NBR_STAT_BUFLEN_IN][2];
	char    asBillingCycleID[AU_SETT_NBR_STAT_BUFLEN_IN][7];
	int     aiCnt[AU_SETT_NBR_STAT_BUFLEN_IN];
	int     aiSettMin[AU_SETT_NBR_STAT_BUFLEN_IN];
	double    adFee[AU_SETT_NBR_STAT_BUFLEN_IN];
	double    adDuration[AU_SETT_NBR_STAT_BUFLEN_IN];
	char	asRowID[AU_SETT_NBR_STAT_BUFLEN_IN][19];

};


/*�����ṹ����*/
struct AuSettNbrStatStruct{

	struct AuSettNbrStatStruct *pNext;
	char    sAccNbr[21];
	char    sHomeAreaCode[6];
	char    sVisitAreaCode[6];
	char    sCalledCode[6];
	char    sNetType[2];
	int     iReportItemID;
	char    sSettType[3];
	char    sSettNbrType[4];
	char    sSettCarrID[2];
	char    sMsc[16];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sTrunkCarrierID[2];
	char    sBillingCycleID[7];
	int     iCnt;
	int     iSettMin;
	double    dFee;
	double    dDuration;
	
	int	iInFlag;	/*����:1  ֧��:0*/
	char	sRowID[19];
	struct AuSettNbrStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FAuSettNbrStatStruct{

	char    sAccNbr[20];
	char    sHomeAreaCode[5];
	char    sVisitAreaCode[5];
	char    sCalledCode[5];
	char    sNetType[1];
	char    sReportItemID[4];
	char    sSettType[2];
	char    sSettNbrType[3];
	char    sSettCarrID[1];
	char    sMsc[15];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sTrunkCarrierID[1];
	char    sBillingCycleID[6];
	char    sCnt[9];
	char    sSettMin[9];
	char    sFee[12];
	char    sDuration[12];
};

/*---------�������ִ��� au_sett_stat.txt----------*/

/*����ṹ��������*/
struct AuSettStatStructOut{

#ifndef AU_SETT_STAT_BUFLEN_OUT
#define AU_SETT_STAT_BUFLEN_OUT		300
#endif

	struct AuSettStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asHomeAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asSettItemDate[AU_SETT_STAT_BUFLEN_OUT][9];
	char    asBillingCycleID[AU_SETT_STAT_BUFLEN_OUT][7];
	int     aiCnt[AU_SETT_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_STAT_BUFLEN_OUT];
};


/* ����ṹ��������*/
struct AuSettStatStructIn{

#ifndef AU_SETT_STAT_BUFLEN_IN
#define AU_SETT_STAT_BUFLEN_IN		300
#endif

	struct AuSettStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asHomeAreaCode[AU_SETT_STAT_BUFLEN_IN][6];
	char    asVisitAreaCode[AU_SETT_STAT_BUFLEN_IN][6];
	char    asCalledCode[AU_SETT_STAT_BUFLEN_IN][6];
	char    asNetType[AU_SETT_STAT_BUFLEN_IN][2];
	int     aiReportItemID[AU_SETT_STAT_BUFLEN_IN];
	char    asSettType[AU_SETT_STAT_BUFLEN_IN][3];
	char    asSettNbrType[AU_SETT_STAT_BUFLEN_IN][4];
	char    asSettCarrID[AU_SETT_STAT_BUFLEN_IN][2];
	char    asMsc[AU_SETT_STAT_BUFLEN_IN][16];
	char    asTrunkIn[AU_SETT_STAT_BUFLEN_IN][8];
	char    asTrunkOut[AU_SETT_STAT_BUFLEN_IN][8];
	char    asTrunkCarrierID[AU_SETT_STAT_BUFLEN_IN][2];
	char    asSettItemDate[AU_SETT_STAT_BUFLEN_IN][9];
	char    asBillingCycleID[AU_SETT_STAT_BUFLEN_IN][7];
	int     aiCnt[AU_SETT_STAT_BUFLEN_IN];
	int     aiSettMin[AU_SETT_STAT_BUFLEN_IN];
	double    adFee[AU_SETT_STAT_BUFLEN_IN];
	double    adDuration[AU_SETT_STAT_BUFLEN_IN];
	char	asRowID[AU_SETT_STAT_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct AuSettStatStruct{

	struct AuSettStatStruct *pNext;
	char    sHomeAreaCode[6];
	char    sVisitAreaCode[6];
	char    sCalledCode[6];
	char    sNetType[2];
	int     iReportItemID;
	char    sSettType[3];
	char    sSettNbrType[4];
	char    sSettCarrID[2];
	char    sMsc[16];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sTrunkCarrierID[2];
	char    sSettItemDate[9];
	char    sBillingCycleID[7];
	int     iCnt;
	int     iSettMin;
	double    dFee;
	double    dDuration;
	int	iInFlag;
	char	sRowID[19];
	struct AuSettStatStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FAuSettStatStruct{

	char    sHomeAreaCode[5];
	char    sVisitAreaCode[5];
	char    sCalledCode[5];
	char    sNetType[1];
	char    sReportItemID[4];
	char    sSettType[2];
	char    sSettNbrType[3];
	char    sSettCarrID[1];
	char    sMsc[15];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sTrunkCarrierID[1];
	char    sSettItemDate[8];
	char    sBillingCycleID[6];
	char    sCnt[9];
	char    sSettMin[9];
	char    sFee[12];
	char    sDuration[12];
};



/*----------------------��������ṹ---------------------------------------*/
/*���½ṹ��������*/
struct AuSettNbrStatStructUpdOut{

#ifndef AU_SETT_NBR_STAT_BUFLEN_OUT
#define AU_SETT_NBR_STAT_BUFLEN_OUT		300
#endif

	struct AuSettNbrStatStructUpOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
/*	
	char    asAccNbr[AU_SETT_NBR_STAT_BUFLEN_OUT][21];
	char    asHomeAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_NBR_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_NBR_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_NBR_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_NBR_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_NBR_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_NBR_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_NBR_STAT_BUFLEN_OUT][2];
	char    asBillingCycleID[AU_SETT_NBR_STAT_BUFLEN_OUT][7];
*/
	int     aiCnt[AU_SETT_NBR_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_NBR_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_NBR_STAT_BUFLEN_OUT];
	char	asRowID[AU_SETT_NBR_STAT_BUFLEN_OUT][19];
};

/*����ṹ��������*/
struct AuSettStatStructUpdOut{

#ifndef AU_SETT_STAT_BUFLEN_OUT
#define AU_SETT_STAT_BUFLEN_OUT		300
#endif

	struct AuSettStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
/*
	char    asHomeAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asVisitAreaCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asCalledCode[AU_SETT_STAT_BUFLEN_OUT][6];
	char    asNetType[AU_SETT_STAT_BUFLEN_OUT][2];
	int     aiReportItemID[AU_SETT_STAT_BUFLEN_OUT];
	char    asSettType[AU_SETT_STAT_BUFLEN_OUT][3];
	char    asSettNbrType[AU_SETT_STAT_BUFLEN_OUT][4];
	char    asSettCarrID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asMsc[AU_SETT_STAT_BUFLEN_OUT][16];
	char    asTrunkIn[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkOut[AU_SETT_STAT_BUFLEN_OUT][8];
	char    asTrunkCarrierID[AU_SETT_STAT_BUFLEN_OUT][2];
	char    asSettItemDate[AU_SETT_STAT_BUFLEN_OUT][9];
	char    asBillingCycleID[AU_SETT_STAT_BUFLEN_OUT][7];
*/
	int     aiCnt[AU_SETT_STAT_BUFLEN_OUT];
	int     aiSettMin[AU_SETT_STAT_BUFLEN_OUT];
	double    adFee[AU_SETT_STAT_BUFLEN_OUT];
	double    adDuration[AU_SETT_STAT_BUFLEN_OUT];
	char	asRowID[AU_SETT_STAT_BUFLEN_OUT][19];
};



/*�������ݶ�̬��AU_SETT_LOG���ýṹ���巽ʽȡ����*/
int EGetAuSettLogToStruct(struct AuSettLogStruct *p,struct AuSettLogStructIn *pSource);
void mvitem_fmausettlog(struct FAuSettLogStruct *pi,struct AuSettLogStruct *po);
/*�������ݽṹ����д��AU_SETT_LOG*/
int EInsertStructToAuSettLog(struct AuSettLogStruct *p,int iInsertFlag,struct AuSettLogStructOut *pTarget);

/*�������ݶ�̬��AU_SETT_NBR_IN_STAT���ýṹ���巽ʽȡ����*/
int EGetAuSettNbrInStatToStruct(struct AuSettNbrStatStruct *p,struct AuSettNbrStatStructIn *pSource);
void mvitem_fmausettnbrstat(struct FAuSettNbrStatStruct *pi,struct AuSettNbrStatStruct *po);
/*�������ݽṹ����д��AU_SETT_NBR_IN_STAT*/
int EInsertStructToAuSettNbrInStat(struct AuSettNbrStatStruct *p,int iInsertFlag,struct AuSettNbrStatStructOut *pTarget);

/*�������ݶ�̬��AU_SETT_NBR_OUT_STAT���ýṹ���巽ʽȡ����*/
int EGetAuSettNbrOutStatToStruct(struct AuSettNbrStatStruct *p,struct AuSettNbrStatStructIn *pSource);
void mvitem_fmausettnbrstat(struct FAuSettNbrStatStruct *pi,struct AuSettNbrStatStruct *po);
/*�������ݽṹ����д��AU_SETT_NBR_OUT_STAT*/
int EInsertStructToAuSettNbrOutStat(struct AuSettNbrStatStruct *p,int iInsertFlag,struct AuSettNbrStatStructOut *pTarget);



/*�������ݶ�̬��AU_SETT_IN_STAT���ýṹ���巽ʽȡ����*/
int EGetAuSettInStatToStruct(struct AuSettStatStruct *p,struct AuSettStatStructIn *pSource);
void mvitem_fmausettstat(struct FAuSettStatStruct *pi,struct AuSettStatStruct *po);
/*�������ݽṹ����д��AU_SETT_IN_STAT*/
int EInsertStructToAuSettInStat(struct AuSettStatStruct *p,int iInsertFlag,struct AuSettStatStructOut *pTarget);

/*�������ݶ�̬��AU_SETT_OUT_STAT���ýṹ���巽ʽȡ����*/
int EGetAuSettOutStatToStruct(struct AuSettStatStruct *p,struct AuSettStatStructIn *pSource);
/*�������ݽṹ����д��AU_SETT_OUT_STAT*/
int EInsertStructToAuSettOutStat(struct AuSettStatStruct *p,int iInsertFlag,struct AuSettStatStructOut *pTarget);



/*�������ݽṹ�������AU_SETT_NBR_IN_STAT*/
int EUpDateStructToAuSettNbrInStat(struct AuSettNbrStatStruct *p,
	int iUpdateFlag,struct AuSettNbrStatStructUpdOut *pTarget);
/*�������ݽṹ�������AU_SETT_NBR_OUT_STAT*/
int EUpDateStructToAuSettNbrOutStat(struct AuSettNbrStatStruct *p,
	int iUpdateFlag,struct AuSettNbrStatStructUpdOut *pTarget);
/*�������ݽṹ�������AU_SETT_IN_STAT*/
int EUpDateStructToAuSettInStat(struct AuSettStatStruct *p,
	int iUpdateFlag,struct AuSettStatStructUpdOut *pTarget);
/*�������ݽṹ�������AU_SETT_OUT_STAT*/
int EUpDateStructToAuSettOutStat(struct AuSettStatStruct *p,
	int iUpdateFlag,struct AuSettStatStructUpdOut *pTarget);

#endif

