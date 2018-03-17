#ifndef __SRTINFO_H__
#define __SRTINFO_H__
/*---------�������ִ��� srt_ticket.txt----------*/

/*����ṹ��������*/
struct SrtTicketStructOut{

#ifndef SRT_TICKET_BUFLEN_OUT
#define SRT_TICKET_BUFLEN_OUT		300
#endif

	struct SrtTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[63];
	int     aiTicketTypeID[SRT_TICKET_BUFLEN_OUT];
	char    asCallType[SRT_TICKET_BUFLEN_OUT][3];
	char    asMsisdn[SRT_TICKET_BUFLEN_OUT][16];
	char    asCalledCode[SRT_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[SRT_TICKET_BUFLEN_OUT][25];
	char    asVisitAreaCode[SRT_TICKET_BUFLEN_OUT][6];
	int     aiRoamFee[SRT_TICKET_BUFLEN_OUT];
	int     aiTollFee[SRT_TICKET_BUFLEN_OUT];
	int     aiAddFee[SRT_TICKET_BUFLEN_OUT];
	int     aiDuration[SRT_TICKET_BUFLEN_OUT];
	char    asStartTime[SRT_TICKET_BUFLEN_OUT][15];
	char    asHomeAreaCode[SRT_TICKET_BUFLEN_OUT][6];
	char    asRoamType[SRT_TICKET_BUFLEN_OUT][2];
	char    asDistanceType[SRT_TICKET_BUFLEN_OUT][2];
	char    asOppType[SRT_TICKET_BUFLEN_OUT][2];
	char    asUserType[SRT_TICKET_BUFLEN_OUT][2];
	char    asSplitRuleID[SRT_TICKET_BUFLEN_OUT][5];
	char    asOppRoamType[SRT_TICKET_BUFLEN_OUT][2];
	char    asServiceType[SRT_TICKET_BUFLEN_OUT][4];
	char    asServiceCode[SRT_TICKET_BUFLEN_OUT][5];
	char    asImsi[SRT_TICKET_BUFLEN_OUT][16];
	char    asMsc[SRT_TICKET_BUFLEN_OUT][16];
	char    asLac[SRT_TICKET_BUFLEN_OUT][6];
	char    asCellID[SRT_TICKET_BUFLEN_OUT][6];
	char    asOtherLac[SRT_TICKET_BUFLEN_OUT][6];
	char    asOtherCellID[SRT_TICKET_BUFLEN_OUT][6];
	char    asTrunkIn[SRT_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[SRT_TICKET_BUFLEN_OUT][8];
	char    asThirdParty[SRT_TICKET_BUFLEN_OUT][16];
	char    asMsrn[SRT_TICKET_BUFLEN_OUT][13];
	int     aiTrunkInTypeID[SRT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutTypeID[SRT_TICKET_BUFLEN_OUT];
	int     aiTrunkInCarrierID[SRT_TICKET_BUFLEN_OUT];
	int     aiTrunkOutCarrierID[SRT_TICKET_BUFLEN_OUT];
	char    asTrunkInType[SRT_TICKET_BUFLEN_OUT][2];
	char    asTrunkOutType[SRT_TICKET_BUFLEN_OUT][2];
	int     aiCallingCarrierID[SRT_TICKET_BUFLEN_OUT];
	int     aiCalledCarrierID[SRT_TICKET_BUFLEN_OUT];
	int     aiCallingTypeID[SRT_TICKET_BUFLEN_OUT];
	int     aiCalledTypeID[SRT_TICKET_BUFLEN_OUT];
	int     aiCallingAreaID[SRT_TICKET_BUFLEN_OUT];
	int     aiCalledAreaID[SRT_TICKET_BUFLEN_OUT];
	int     aiASettAreaID[SRT_TICKET_BUFLEN_OUT];
	int     aiBSettAreaID[SRT_TICKET_BUFLEN_OUT];
	char    asSplitType[SRT_TICKET_BUFLEN_OUT][2];
	char    asCal[SRT_TICKET_BUFLEN_OUT][2];
	char    asEsn[SRT_TICKET_BUFLEN_OUT][16];
	char    asScpFlag[SRT_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[SRT_TICKET_BUFLEN_OUT][2];
	char    asReserve[SRT_TICKET_BUFLEN_OUT][9];
	char    asBillMode[SRT_TICKET_BUFLEN_OUT][4];
	char    asReserve1[SRT_TICKET_BUFLEN_OUT][3];
	char    asRoamTariffType[SRT_TICKET_BUFLEN_OUT][4];
	char    asTollTariffType[SRT_TICKET_BUFLEN_OUT][4];
	char    asAddTariffType[SRT_TICKET_BUFLEN_OUT][4];
	char    asErrCode[SRT_TICKET_BUFLEN_OUT][5];
	char    asFileName[SRT_TICKET_BUFLEN_OUT][20];
	char    asModule[SRT_TICKET_BUFLEN_OUT][4];
	char    asAreaCode[SRT_TICKET_BUFLEN_OUT][6];
	char    asState[SRT_TICKET_BUFLEN_OUT][2];
	char    asUpdateDate[SRT_TICKET_BUFLEN_OUT][15];
	char    asDealDate[SRT_TICKET_BUFLEN_OUT][15];
	char    asSourceID[SRT_TICKET_BUFLEN_OUT][41];
	char	asRowID[SRT_TICKET_BUFLEN_OUT][19];
};


/* ����ṹ��������*/
struct SrtTicketStructIn{

#ifndef SRT_TICKET_BUFLEN_IN
#define SRT_TICKET_BUFLEN_IN		300
#endif

	struct SrtTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[63];
	char sCondition[1024];
	int     aiTicketTypeID[SRT_TICKET_BUFLEN_IN];
	char    asCallType[SRT_TICKET_BUFLEN_IN][3];
	char    asMsisdn[SRT_TICKET_BUFLEN_IN][16];
	char    asCalledCode[SRT_TICKET_BUFLEN_IN][6];
	char    asOtherParty[SRT_TICKET_BUFLEN_IN][25];
	char    asVisitAreaCode[SRT_TICKET_BUFLEN_IN][6];
	int     aiRoamFee[SRT_TICKET_BUFLEN_IN];
	int     aiTollFee[SRT_TICKET_BUFLEN_IN];
	int     aiAddFee[SRT_TICKET_BUFLEN_IN];
	int     aiDuration[SRT_TICKET_BUFLEN_IN];
	char    asStartTime[SRT_TICKET_BUFLEN_IN][15];
	char    asHomeAreaCode[SRT_TICKET_BUFLEN_IN][6];
	char    asRoamType[SRT_TICKET_BUFLEN_IN][2];
	char    asDistanceType[SRT_TICKET_BUFLEN_IN][2];
	char    asOppType[SRT_TICKET_BUFLEN_IN][2];
	char    asUserType[SRT_TICKET_BUFLEN_IN][2];
	char    asSplitRuleID[SRT_TICKET_BUFLEN_IN][5];
	char    asOppRoamType[SRT_TICKET_BUFLEN_IN][2];
	char    asServiceType[SRT_TICKET_BUFLEN_IN][4];
	char    asServiceCode[SRT_TICKET_BUFLEN_IN][5];
	char    asImsi[SRT_TICKET_BUFLEN_IN][16];
	char    asMsc[SRT_TICKET_BUFLEN_IN][16];
	char    asLac[SRT_TICKET_BUFLEN_IN][6];
	char    asCellID[SRT_TICKET_BUFLEN_IN][6];
	char    asOtherLac[SRT_TICKET_BUFLEN_IN][6];
	char    asOtherCellID[SRT_TICKET_BUFLEN_IN][6];
	char    asTrunkIn[SRT_TICKET_BUFLEN_IN][8];
	char    asTrunkOut[SRT_TICKET_BUFLEN_IN][8];
	char    asThirdParty[SRT_TICKET_BUFLEN_IN][16];
	char    asMsrn[SRT_TICKET_BUFLEN_IN][13];
	int     aiTrunkInTypeID[SRT_TICKET_BUFLEN_IN];
	int     aiTrunkOutTypeID[SRT_TICKET_BUFLEN_IN];
	int     aiTrunkInCarrierID[SRT_TICKET_BUFLEN_IN];
	int     aiTrunkOutCarrierID[SRT_TICKET_BUFLEN_IN];
	char    asTrunkInType[SRT_TICKET_BUFLEN_IN][2];
	char    asTrunkOutType[SRT_TICKET_BUFLEN_IN][2];
	int     aiCallingCarrierID[SRT_TICKET_BUFLEN_IN];
	int     aiCalledCarrierID[SRT_TICKET_BUFLEN_IN];
	int     aiCallingTypeID[SRT_TICKET_BUFLEN_IN];
	int     aiCalledTypeID[SRT_TICKET_BUFLEN_IN];
	int     aiCallingAreaID[SRT_TICKET_BUFLEN_IN];
	int     aiCalledAreaID[SRT_TICKET_BUFLEN_IN];
	int     aiASettAreaID[SRT_TICKET_BUFLEN_IN];
	int     aiBSettAreaID[SRT_TICKET_BUFLEN_IN];
	char    asSplitType[SRT_TICKET_BUFLEN_IN][2];
	char    asCal[SRT_TICKET_BUFLEN_IN][2];
	char    asEsn[SRT_TICKET_BUFLEN_IN][16];
	char    asScpFlag[SRT_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[SRT_TICKET_BUFLEN_IN][2];
	char    asReserve[SRT_TICKET_BUFLEN_IN][9];
	char    asBillMode[SRT_TICKET_BUFLEN_IN][4];
	char    asReserve1[SRT_TICKET_BUFLEN_IN][3];
	char    asRoamTariffType[SRT_TICKET_BUFLEN_IN][4];
	char    asTollTariffType[SRT_TICKET_BUFLEN_IN][4];
	char    asAddTariffType[SRT_TICKET_BUFLEN_IN][4];
	char    asErrCode[SRT_TICKET_BUFLEN_IN][5];
	char    asFileName[SRT_TICKET_BUFLEN_IN][20];
	char    asModule[SRT_TICKET_BUFLEN_IN][4];
	char    asAreaCode[SRT_TICKET_BUFLEN_IN][6];
	char    asState[SRT_TICKET_BUFLEN_IN][2];
	char    asUpdateDate[SRT_TICKET_BUFLEN_IN][15];
	char    asDealDate[SRT_TICKET_BUFLEN_IN][15];
	char    asSourceID[SRT_TICKET_BUFLEN_IN][41];
	char	asRowID[SRT_TICKET_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct SrtTicketStruct{

	struct SrtTicketStruct *pNext;
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
	char	sRowID[19];
	
	struct SrtTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSrtTicketStruct{

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
/*�������ݶ�̬��SRT_TICKET���ýṹ���巽ʽȡ����*/
int EGetSrtTicketToStruct(struct SrtTicketStruct *p,
	struct SrtTicketStructIn *pSource);
	
void mvitem_srtticket(struct SrtTicketStruct *pi,struct SrtTicketStruct *po);

void mvitem_fmsrtticket(struct FSrtTicketStruct *pi,struct SrtTicketStruct *po);

void mvitem_mfsrtticket(struct SrtTicketStruct *pi,struct FSrtTicketStruct *po);

/**�Ա�SRT_TICKET�������ͷź���**/
void DestroySrtTicket(struct SrtTicketStruct *ptHead);

int InitSrtTicket(struct SrtTicketStruct **pptHead);

/*�������ݽṹ����д��SRT_TICKET*/
int EInsertStructToSrtTicket(struct SrtTicketStruct *p,
	int iInsertFlag,struct SrtTicketStructOut *pTarget);
	
	
/******************************************************************************/
/*---------�������ִ��� sett_item_control_day.txt----------*/

/*����ṹ��������*/
struct SettItemControlDayStructOut{

#ifndef SETT_ITEM_CONTROL_DAY_BUFLEN_OUT
#define SETT_ITEM_CONTROL_DAY_BUFLEN_OUT		300
#endif

	struct SettItemControlDayStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ͳ������ */
	char    asStatDate[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][9];
		/* ҵ������ */
	char    asSettType[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* �������� */
	char    asCallType[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][3];
		/* �û����� */
	char    asUserType[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* �������� */
	char    asRomeType[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* ��;���� */
	char    asDistanceType[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* �Զ˺�������� */
	char    asCalledCode[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* �û����λ��߽���� */
	char    asVisitAreaCode[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* ������������ */
	char    asHomeAreaCode[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* ���������Ӫ�� */
	int     aiCallingCarrierID[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT];
		/* �Զ˺�����Ӫ�� */
	int     aiCalledCarrierID[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT];
		/* �Զ��û����� */
	char    asCalledUserType[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][6];
		/* ������ */
	int     aiCnt[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT];
		/* ͨ��ʱ�� */
	char    asDuration[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][13];
		/* ����ʱ�� */
	char    asSettDuration[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][13];
		/* �������� */
	char    asInFee[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][13];
		/* ����֧�� */
	char    asOutFee[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT][13];
		/* �������� */
	int     aiTicketTypeID[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT];
		/* ��ƷID */
	int     aiProductID[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT];
		/* ��Ʒ���� */
	int     aiProductType[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT];
		/* Ʒ�� */
	int     aiBrandID[SETT_ITEM_CONTROL_DAY_BUFLEN_OUT];
};


/* ����ṹ��������*/
struct SettItemControlDayStructIn{

#ifndef SETT_ITEM_CONTROL_DAY_BUFLEN_IN
#define SETT_ITEM_CONTROL_DAY_BUFLEN_IN		300
#endif

	struct SettItemControlDayStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ͳ������ */
	char    asStatDate[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][9];
		/* ҵ������ */
	char    asSettType[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* �������� */
	char    asCallType[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][3];
		/* �û����� */
	char    asUserType[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* �������� */
	char    asRomeType[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* ��;���� */
	char    asDistanceType[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* �Զ˺�������� */
	char    asCalledCode[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* �û����λ��߽���� */
	char    asVisitAreaCode[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* ������������ */
	char    asHomeAreaCode[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* ���������Ӫ�� */
	int     aiCallingCarrierID[SETT_ITEM_CONTROL_DAY_BUFLEN_IN];
		/* �Զ˺�����Ӫ�� */
	int     aiCalledCarrierID[SETT_ITEM_CONTROL_DAY_BUFLEN_IN];
		/* �Զ��û����� */
	char    asCalledUserType[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][6];
		/* ������ */
	int     aiCnt[SETT_ITEM_CONTROL_DAY_BUFLEN_IN];
		/* ͨ��ʱ�� */
	char    asDuration[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][13];
		/* ����ʱ�� */
	char    asSettDuration[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][13];
		/* �������� */
	char    asInFee[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][13];
		/* ����֧�� */
	char    asOutFee[SETT_ITEM_CONTROL_DAY_BUFLEN_IN][13];
		/* �������� */
	int     aiTicketTypeID[SETT_ITEM_CONTROL_DAY_BUFLEN_IN];
		/* ��ƷID */
	int     aiProductID[SETT_ITEM_CONTROL_DAY_BUFLEN_IN];
		/* ��Ʒ���� */
	int     aiProductType[SETT_ITEM_CONTROL_DAY_BUFLEN_IN];
		/* Ʒ�� */
	int     aiBrandID[SETT_ITEM_CONTROL_DAY_BUFLEN_IN];
};


/*�����ṹ����*/
struct SettItemControlDayStruct{

	struct SettItemControlDayStruct *pNext;
	char    sStatDate[9];		/* ͳ������ */
	char    sSettType[6];		/* ҵ������ */
	char    sCallType[3];		/* �������� */
	char    sUserType[6];		/* �û����� */
	char    sRomeType[6];		/* �������� */
	char    sDistanceType[6];		/* ��;���� */
	char    sCalledCode[6];		/* �Զ˺�������� */
	char    sVisitAreaCode[6];	/* �û����λ��߽���� */
	char    sHomeAreaCode[6];	/* ������������ */
	int     iCallingCarrierID;	/* ���������Ӫ�� */
	int     iCalledCarrierID;	/* �Զ˺�����Ӫ�� */
	char    sCalledUserType[6];	/* �Զ��û����� */
	int     iCnt;			/* ������ */
	char    sDuration[13];		/* ͨ��ʱ�� */
	char    sSettDuration[13];	/* ����ʱ�� */
	char    sInFee[13];		/* �������� */
	char    sOutFee[13];		/* ����֧�� */
	int     iTicketTypeID;		/* �������� */
	int     iProductID;		/* ��ƷID */
	int     iProductType;		/* ��Ʒ���� */
	int     iBrandID;		/* Ʒ�� */
	char 	sHead[16];
	char    sStatFee[2];
	int  	iSettCarrID[2];
	struct SettItemControlDayStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettItemControlDayStruct{

	char    sStatDate[8];		/* ͳ������ */
	char    sSettType[5];		/* ҵ������ */
	char    sCallType[2];		/* �������� */
	char    sUserType[5];		/* �û����� */
	char    sRomeType[5];		/* �������� */
	char    sDistanceType[5];		/* ��;���� */
	char    sCalledCode[5];		/* �Զ˺�������� */
	char    sVisitAreaCode[5];		/* �û����λ��߽���� */
	char    sHomeAreaCode[5];		/* ������������ */
	char    sCallingCarrierID[4];		/* ���������Ӫ�� */
	char    sCalledCarrierID[4];		/* �Զ˺�����Ӫ�� */
	char    sCalledUserType[5];		/* �Զ��û����� */
	char    sCnt[8];		/* ������ */
	char    sDuration[12];		/* ͨ��ʱ�� */
	char    sSettDuration[12];		/* ����ʱ�� */
	char    sInFee[12];		/* �������� */
	char    sOutFee[12];		/* ����֧�� */
	char    sTicketTypeID[4];		/* �������� */
	char    sProductID[8];		/* ��ƷID */
	char    sProductType[8];		/* ��Ʒ���� */
	char    sBrandID[6];		/* Ʒ�� */
};
/*�������ݶ�̬��SETT_ITEM_CONTROL_DAY���ýṹ���巽ʽȡ����*/
int EGetSettItemControlDayToStruct(struct SettItemControlDayStruct *p,
	struct SettItemControlDayStructIn *pSource);
	
void mvitem_settitemcontrolday(struct SettItemControlDayStruct *pi,struct SettItemControlDayStruct *po);

void mvitem_fmsettitemcontrolday(struct FSettItemControlDayStruct *pi,struct SettItemControlDayStruct *po);

void mvitem_mfsettitemcontrolday(struct SettItemControlDayStruct *pi,struct FSettItemControlDayStruct *po);

/**�Ա�SETT_ITEM_CONTROL_DAY�������ͷź���**/
void DestroySettItemControlDay(struct SettItemControlDayStruct *ptHead);

int InitSettItemControlDay(struct SettItemControlDayStruct **pptHead);

/*�������ݽṹ����д��SETT_ITEM_CONTROL_DAY*/
int EInsertStructToSettItemControlDay(struct SettItemControlDayStruct *p,
	int iInsertFlag,struct SettItemControlDayStructOut *pTarget);


/*******************************************************************************/

/*---------�������ִ��� sett_item_control_all.txt----------*/

/*����ṹ��������*/
struct SettItemControlAllStructOut{

#ifndef SETT_ITEM_CONTROL_ALL_BUFLEN_OUT
#define SETT_ITEM_CONTROL_ALL_BUFLEN_OUT		300
#endif

	struct SettItemControlAllStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ͳ������ */
	char    asStatDate[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][9];
		/* ҵ������ */
	char    asSettType[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* �������� */
	char    asCallType[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][3];
		/* �û����� */
	char    asUserType[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* �������� */
	char    asRoamType[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* ��;���� */
	char    asDistanceType[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* �Զ˺�������� */
	char    asCalledCode[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* �û����λ��߽���� */
	char    asVisitAreaCode[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* ������������ */
	char    asHomeAreaCode[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* ���������Ӫ�� */
	int     aiCallingCarrierID[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* �Զ˺�����Ӫ�� */
	int     aiCalledCarrierID[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* �Զ��û����� */
	char    asCalledUserType[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][6];
		/* ������ */
	int     aiCnt[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ͨ��ʱ�� */
	char    asDuration[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ����ʱ�� */
	char    asSettDuration[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �������� */
	char    asInFee[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ����֧�� */
	char    asOutFee[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �������� */
	int     aiTicketTypeID[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ��ƷID */
	int     aiProductID[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ��Ʒ���� */
	int     aiProductType[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* Ʒ�� */
	int     aiBrandID[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ����ͬ���ջ����� */
	int     aiCnt1[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ����ͬ����ͨ��ʱ�� */
	char    asDuration1[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ����ͬ���ս���ʱ�� */
	char    asSettDuration1[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ����ͬ���ս������� */
	char    asInFee1[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ����ͬ���ս���֧�� */
	char    asOutFee1[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���ջ����ջ����� */
	int     aiCnt2[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ���ջ�����ͨ��ʱ�� */
	char    asDuration2[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���ջ����ս���ʱ�� */
	char    asSettDuration2[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���ջ����ս������� */
	char    asInFee2[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���ջ����ս���֧�� */
	char    asOutFee2[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ������� */
	int     aiCnt3[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* �����վ�ͨ��ʱ�� */
	char    asDuration3[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ�����ʱ�� */
	char    asSettDuration3[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ��������� */
	char    asInFee3[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ�����֧�� */
	char    asOutFee3[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ������� */
	int     aiCnt4[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* �����վ�ͨ��ʱ�� */
	char    asDuration4[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ�����ʱ�� */
	char    asSettDuration4[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ��������� */
	char    asInFee4[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* �����վ�����֧�� */
	char    asOutFee4[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܻ����� */
	int     aiCnt5[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ���»���ͨ��ʱ�� */
	char    asDuration5[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܽ���ʱ�� */
	char    asSettDuration5[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܽ������� */
	char    asInFee5[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܽ���֧�� */
	char    asOutFee5[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܻ����� */
	int     aiCnt6[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ���»���ͨ��ʱ�� */
	char    asDuration6[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܽ���ʱ�� */
	char    asSettDuration6[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܽ������� */
	char    asInFee6[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ���»��ܽ���֧�� */
	char    asOutFee6[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ȥ��ͬ�»��ܻ����� */
	int     aiCnt7[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT];
		/* ȥ��ͬ�»���ͨ��ʱ�� */
	char    asDuration7[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ȥ��ͬ�»��ܽ���ʱ�� */
	char    asSettDuration7[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ȥ��ͬ�»��ܽ������� */
	char    asInFee7[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
		/* ȥ��ͬ�»��ܽ���֧�� */
	char    asOutFee7[SETT_ITEM_CONTROL_ALL_BUFLEN_OUT][13];
};


/* ����ṹ��������*/
struct SettItemControlAllStructIn{

#ifndef SETT_ITEM_CONTROL_ALL_BUFLEN_IN
#define SETT_ITEM_CONTROL_ALL_BUFLEN_IN		300
#endif

	struct SettItemControlAllStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ͳ������ */
	char    asStatDate[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][9];
		/* ҵ������ */
	char    asSettType[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* �������� */
	char    asCallType[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][3];
		/* �û����� */
	char    asUserType[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* �������� */
	char    asRoamType[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* ��;���� */
	char    asDistanceType[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* �Զ˺�������� */
	char    asCalledCode[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* �û����λ��߽���� */
	char    asVisitAreaCode[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* ������������ */
	char    asHomeAreaCode[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* ���������Ӫ�� */
	int     aiCallingCarrierID[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* �Զ˺�����Ӫ�� */
	int     aiCalledCarrierID[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* �Զ��û����� */
	char    asCalledUserType[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][6];
		/* ������ */
	int     aiCnt[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ͨ��ʱ�� */
	char    asDuration[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ����ʱ�� */
	char    asSettDuration[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �������� */
	char    asInFee[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ����֧�� */
	char    asOutFee[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �������� */
	int     aiTicketTypeID[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ��ƷID */
	int     aiProductID[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ��Ʒ���� */
	int     aiProductType[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* Ʒ�� */
	int     aiBrandID[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ����ͬ���ջ����� */
	int     aiCnt1[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ����ͬ����ͨ��ʱ�� */
	char    asDuration1[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ����ͬ���ս���ʱ�� */
	char    asSettDuration1[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ����ͬ���ս������� */
	char    asInFee1[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ����ͬ���ս���֧�� */
	char    asOutFee1[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���ջ����ջ����� */
	int     aiCnt2[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ���ջ�����ͨ��ʱ�� */
	char    asDuration2[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���ջ����ս���ʱ�� */
	char    asSettDuration2[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���ջ����ս������� */
	char    asInFee2[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���ջ����ս���֧�� */
	char    asOutFee2[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ������� */
	int     aiCnt3[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* �����վ�ͨ��ʱ�� */
	char    asDuration3[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ�����ʱ�� */
	char    asSettDuration3[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ��������� */
	char    asInFee3[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ�����֧�� */
	char    asOutFee3[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ������� */
	int     aiCnt4[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* �����վ�ͨ��ʱ�� */
	char    asDuration4[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ�����ʱ�� */
	char    asSettDuration4[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ��������� */
	char    asInFee4[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* �����վ�����֧�� */
	char    asOutFee4[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܻ����� */
	int     aiCnt5[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ���»���ͨ��ʱ�� */
	char    asDuration5[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܽ���ʱ�� */
	char    asSettDuration5[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܽ������� */
	char    asInFee5[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܽ���֧�� */
	char    asOutFee5[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܻ����� */
	int     aiCnt6[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ���»���ͨ��ʱ�� */
	char    asDuration6[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܽ���ʱ�� */
	char    asSettDuration6[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܽ������� */
	char    asInFee6[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ���»��ܽ���֧�� */
	char    asOutFee6[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ȥ��ͬ�»��ܻ����� */
	int     aiCnt7[SETT_ITEM_CONTROL_ALL_BUFLEN_IN];
		/* ȥ��ͬ�»���ͨ��ʱ�� */
	char    asDuration7[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ȥ��ͬ�»��ܽ���ʱ�� */
	char    asSettDuration7[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ȥ��ͬ�»��ܽ������� */
	char    asInFee7[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
		/* ȥ��ͬ�»��ܽ���֧�� */
	char    asOutFee7[SETT_ITEM_CONTROL_ALL_BUFLEN_IN][13];
};


/*�����ṹ����*/
struct SettItemControlAllStruct{

	struct SettItemControlAllStruct *pNext;
	char    sStatDate[9];		/* ͳ������ */
	char    sSettType[6];		/* ҵ������ */
	char    sCallType[3];		/* �������� */
	char    sUserType[6];		/* �û����� */
	char    sRoamType[6];		/* �������� */
	char    sDistanceType[6];		/* ��;���� */
	char    sCalledCode[6];		/* �Զ˺�������� */
	char    sVisitAreaCode[6];		/* �û����λ��߽���� */
	char    sHomeAreaCode[6];		/* ������������ */
	int     iCallingCarrierID;		/* ���������Ӫ�� */
	int     iCalledCarrierID;		/* �Զ˺�����Ӫ�� */
	char    sCalledUserType[6];		/* �Զ��û����� */
	int     iCnt;		/* ������ */
	char    sDuration[13];		/* ͨ��ʱ�� */
	char    sSettDuration[13];		/* ����ʱ�� */
	char    sInFee[13];		/* �������� */
	char    sOutFee[13];		/* ����֧�� */
	int     iTicketTypeID;		/* �������� */
	int     iProductID;		/* ��ƷID */
	int     iProductType;		/* ��Ʒ���� */
	int     iBrandID;		/* Ʒ�� */
	int     iCnt1;		/* ����ͬ���ջ����� */
	char    sDuration1[13];		/* ����ͬ����ͨ��ʱ�� */
	char    sSettDuration1[13];		/* ����ͬ���ս���ʱ�� */
	char    sInFee1[13];		/* ����ͬ���ս������� */
	char    sOutFee1[13];		/* ����ͬ���ս���֧�� */
	int     iCnt2;		/* ���ջ����ջ����� */
	char    sDuration2[13];		/* ���ջ�����ͨ��ʱ�� */
	char    sSettDuration2[13];		/* ���ջ����ս���ʱ�� */
	char    sInFee2[13];		/* ���ջ����ս������� */
	char    sOutFee2[13];		/* ���ջ����ս���֧�� */
	int     iCnt3;		/* �����վ������� */
	char    sDuration3[13];		/* �����վ�ͨ��ʱ�� */
	char    sSettDuration3[13];		/* �����վ�����ʱ�� */
	char    sInFee3[13];		/* �����վ��������� */
	char    sOutFee3[13];		/* �����վ�����֧�� */
	int     iCnt4;		/* �����վ������� */
	char    sDuration4[13];		/* �����վ�ͨ��ʱ�� */
	char    sSettDuration4[13];		/* �����վ�����ʱ�� */
	char    sInFee4[13];		/* �����վ��������� */
	char    sOutFee4[13];		/* �����վ�����֧�� */
	int     iCnt5;		/* ���»��ܻ����� */
	char    sDuration5[13];		/* ���»���ͨ��ʱ�� */
	char    sSettDuration5[13];		/* ���»��ܽ���ʱ�� */
	char    sInFee5[13];		/* ���»��ܽ������� */
	char    sOutFee5[13];		/* ���»��ܽ���֧�� */
	int     iCnt6;		/* ���»��ܻ����� */
	char    sDuration6[13];		/* ���»���ͨ��ʱ�� */
	char    sSettDuration6[13];		/* ���»��ܽ���ʱ�� */
	char    sInFee6[13];		/* ���»��ܽ������� */
	char    sOutFee6[13];		/* ���»��ܽ���֧�� */
	int     iCnt7;		/* ȥ��ͬ�»��ܻ����� */
	char    sDuration7[13];		/* ȥ��ͬ�»���ͨ��ʱ�� */
	char    sSettDuration7[13];		/* ȥ��ͬ�»��ܽ���ʱ�� */
	char    sInFee7[13];		/* ȥ��ͬ�»��ܽ������� */
	char    sOutFee7[13];		/* ȥ��ͬ�»��ܽ���֧�� */
	struct SettItemControlAllStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSettItemControlAllStruct{

	char    sStatDate[8];		/* ͳ������ */
	char    sSettType[5];		/* ҵ������ */
	char    sCallType[2];		/* �������� */
	char    sUserType[5];		/* �û����� */
	char    sRoamType[5];		/* �������� */
	char    sDistanceType[5];		/* ��;���� */
	char    sCalledCode[5];		/* �Զ˺�������� */
	char    sVisitAreaCode[5];		/* �û����λ��߽���� */
	char    sHomeAreaCode[5];		/* ������������ */
	char    sCallingCarrierID[4];		/* ���������Ӫ�� */
	char    sCalledCarrierID[4];		/* �Զ˺�����Ӫ�� */
	char    sCalledUserType[5];		/* �Զ��û����� */
	char    sCnt[8];		/* ������ */
	char    sDuration[12];		/* ͨ��ʱ�� */
	char    sSettDuration[12];		/* ����ʱ�� */
	char    sInFee[12];		/* �������� */
	char    sOutFee[12];		/* ����֧�� */
	char    sTicketTypeID[4];		/* �������� */
	char    sProductID[8];		/* ��ƷID */
	char    sProductType[8];		/* ��Ʒ���� */
	char    sBrandID[6];		/* Ʒ�� */
	char    sCnt1[8];		/* ����ͬ���ջ����� */
	char    sDuration1[12];		/* ����ͬ����ͨ��ʱ�� */
	char    sSettDuration1[12];		/* ����ͬ���ս���ʱ�� */
	char    sInFee1[12];		/* ����ͬ���ս������� */
	char    sOutFee1[12];		/* ����ͬ���ս���֧�� */
	char    sCnt2[8];		/* ���ջ����ջ����� */
	char    sDuration2[12];		/* ���ջ�����ͨ��ʱ�� */
	char    sSettDuration2[12];		/* ���ջ����ս���ʱ�� */
	char    sInFee2[12];		/* ���ջ����ս������� */
	char    sOutFee2[12];		/* ���ջ����ս���֧�� */
	char    sCnt3[8];		/* �����վ������� */
	char    sDuration3[12];		/* �����վ�ͨ��ʱ�� */
	char    sSettDuration3[12];		/* �����վ�����ʱ�� */
	char    sInFee3[12];		/* �����վ��������� */
	char    sOutFee3[12];		/* �����վ�����֧�� */
	char    sCnt4[8];		/* �����վ������� */
	char    sDuration4[12];		/* �����վ�ͨ��ʱ�� */
	char    sSettDuration4[12];		/* �����վ�����ʱ�� */
	char    sInFee4[12];		/* �����վ��������� */
	char    sOutFee4[12];		/* �����վ�����֧�� */
	char    sCnt5[8];		/* ���»��ܻ����� */
	char    sDuration5[12];		/* ���»���ͨ��ʱ�� */
	char    sSettDuration5[12];		/* ���»��ܽ���ʱ�� */
	char    sInFee5[12];		/* ���»��ܽ������� */
	char    sOutFee5[12];		/* ���»��ܽ���֧�� */
	char    sCnt6[8];		/* ���»��ܻ����� */
	char    sDuration6[12];		/* ���»���ͨ��ʱ�� */
	char    sSettDuration6[12];		/* ���»��ܽ���ʱ�� */
	char    sInFee6[12];		/* ���»��ܽ������� */
	char    sOutFee6[12];		/* ���»��ܽ���֧�� */
	char    sCnt7[8];		/* ȥ��ͬ�»��ܻ����� */
	char    sDuration7[12];		/* ȥ��ͬ�»���ͨ��ʱ�� */
	char    sSettDuration7[12];		/* ȥ��ͬ�»��ܽ���ʱ�� */
	char    sInFee7[12];		/* ȥ��ͬ�»��ܽ������� */
	char    sOutFee7[12];		/* ȥ��ͬ�»��ܽ���֧�� */
};

/*�������ݶ�̬��SETT_ITEM_CONTROL_ALL���ýṹ���巽ʽȡ����*/
int EGetSettItemControlAllToStruct(struct SettItemControlAllStruct *p,
	struct SettItemControlAllStructIn *pSource);

void mvitem_settitemcontrolall(struct SettItemControlAllStruct *pi,struct SettItemControlAllStruct *po);

void mvitem_fmsettitemcontrolall(struct FSettItemControlAllStruct *pi,struct SettItemControlAllStruct *po);

void mvitem_mfsettitemcontrolall(struct SettItemControlAllStruct *pi,struct FSettItemControlAllStruct *po);

/**�Ա�SETT_ITEM_CONTROL_ALL�������ͷź���**/
void DestroySettItemControlAll(struct SettItemControlAllStruct *ptHead);

int InitSettItemControlAll(struct SettItemControlAllStruct **pptHead);

/*�������ݽṹ����д��SETT_ITEM_CONTROL_ALL*/
int EInsertStructToSettItemControlAll(struct SettItemControlAllStruct *p,
	int iInsertFlag,struct SettItemControlAllStructOut *pTarget);
/*******************************************************************************/

/*---------�������ִ��� pstn_tll_ticket.txt----------*/

/*����ṹ��������*/
struct PstnTllTicketStructOut{

#ifndef PSTN_TLL_TICKET_BUFLEN_OUT
#define PSTN_TLL_TICKET_BUFLEN_OUT		300
#endif

	struct PstnTllTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[63];
	int     aiTicketTypeID[PSTN_TLL_TICKET_BUFLEN_OUT];
	char    asCallType[PSTN_TLL_TICKET_BUFLEN_OUT][3];
	char    asMsisdn[PSTN_TLL_TICKET_BUFLEN_OUT][16];
	char    asCalledCode[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[PSTN_TLL_TICKET_BUFLEN_OUT][25];
	char    asVisitAreaCode[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	int     aiRoamFee[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiTollFee[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiAddFee[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiDuration[PSTN_TLL_TICKET_BUFLEN_OUT];
	char    asStartTime[PSTN_TLL_TICKET_BUFLEN_OUT][15];
	char    asHomeAreaCode[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	char    asRoamType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asDistanceType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asOppType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asUserType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asSplitRuleID[PSTN_TLL_TICKET_BUFLEN_OUT][5];
	char    asOppRoamType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asServiceType[PSTN_TLL_TICKET_BUFLEN_OUT][4];
	char    asServiceCode[PSTN_TLL_TICKET_BUFLEN_OUT][5];
	char    asImsi[PSTN_TLL_TICKET_BUFLEN_OUT][16];
	char    asMsc[PSTN_TLL_TICKET_BUFLEN_OUT][16];
	char    asLac[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	char    asCellID[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	char    asOtherLac[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	char    asOtherCellID[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	char    asTrunkIn[PSTN_TLL_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[PSTN_TLL_TICKET_BUFLEN_OUT][8];
	char    asThirdParty[PSTN_TLL_TICKET_BUFLEN_OUT][16];
	char    asMsrn[PSTN_TLL_TICKET_BUFLEN_OUT][13];
	int     aiTrunkInTypeID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiTrunkOutTypeID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiTrunkInCarrierID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiTrunkOutCarrierID[PSTN_TLL_TICKET_BUFLEN_OUT];
	char    asTrunkInType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asTrunkOutType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	int     aiCallingCarrierID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiCalledCarrierID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiCallingTypeID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiCalledTypeID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiCallingAreaID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiCalledAreaID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiASettAreaID[PSTN_TLL_TICKET_BUFLEN_OUT];
	int     aiBSettAreaID[PSTN_TLL_TICKET_BUFLEN_OUT];
	char    asSplitType[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asCal[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asEsn[PSTN_TLL_TICKET_BUFLEN_OUT][16];
	char    asScpFlag[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asDeformFlag[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asReserve[PSTN_TLL_TICKET_BUFLEN_OUT][9];
	char    asBillMode[PSTN_TLL_TICKET_BUFLEN_OUT][4];
	char    asReserve1[PSTN_TLL_TICKET_BUFLEN_OUT][3];
	char    asRoamTariffType[PSTN_TLL_TICKET_BUFLEN_OUT][4];
	char    asTollTariffType[PSTN_TLL_TICKET_BUFLEN_OUT][4];
	char    asAddTariffType[PSTN_TLL_TICKET_BUFLEN_OUT][4];
	char    asErrCode[PSTN_TLL_TICKET_BUFLEN_OUT][5];
	char    asFileName[PSTN_TLL_TICKET_BUFLEN_OUT][20];
	char    asModule[PSTN_TLL_TICKET_BUFLEN_OUT][4];
	char    asAreaCode[PSTN_TLL_TICKET_BUFLEN_OUT][6];
	char    asState[PSTN_TLL_TICKET_BUFLEN_OUT][2];
	char    asUpdateDate[PSTN_TLL_TICKET_BUFLEN_OUT][15];
	char    asDealDate[PSTN_TLL_TICKET_BUFLEN_OUT][15];
	char    asSourceID[PSTN_TLL_TICKET_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct PstnTllTicketStructIn{

#ifndef PSTN_TLL_TICKET_BUFLEN_IN
#define PSTN_TLL_TICKET_BUFLEN_IN		300
#endif

	struct PstnTllTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[63];
	char sCondition[1024];
	int     aiTicketTypeID[PSTN_TLL_TICKET_BUFLEN_IN];
	char    asCallType[PSTN_TLL_TICKET_BUFLEN_IN][3];
	char    asMsisdn[PSTN_TLL_TICKET_BUFLEN_IN][16];
	char    asCalledCode[PSTN_TLL_TICKET_BUFLEN_IN][6];
	char    asOtherParty[PSTN_TLL_TICKET_BUFLEN_IN][25];
	char    asVisitAreaCode[PSTN_TLL_TICKET_BUFLEN_IN][6];
	int     aiRoamFee[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiTollFee[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiAddFee[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiDuration[PSTN_TLL_TICKET_BUFLEN_IN];
	char    asStartTime[PSTN_TLL_TICKET_BUFLEN_IN][15];
	char    asHomeAreaCode[PSTN_TLL_TICKET_BUFLEN_IN][6];
	char    asRoamType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asDistanceType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asOppType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asUserType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asSplitRuleID[PSTN_TLL_TICKET_BUFLEN_IN][5];
	char    asOppRoamType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asServiceType[PSTN_TLL_TICKET_BUFLEN_IN][4];
	char    asServiceCode[PSTN_TLL_TICKET_BUFLEN_IN][5];
	char    asImsi[PSTN_TLL_TICKET_BUFLEN_IN][16];
	char    asMsc[PSTN_TLL_TICKET_BUFLEN_IN][16];
	char    asLac[PSTN_TLL_TICKET_BUFLEN_IN][6];
	char    asCellID[PSTN_TLL_TICKET_BUFLEN_IN][6];
	char    asOtherLac[PSTN_TLL_TICKET_BUFLEN_IN][6];
	char    asOtherCellID[PSTN_TLL_TICKET_BUFLEN_IN][6];
	char    asTrunkIn[PSTN_TLL_TICKET_BUFLEN_IN][8];
	char    asTrunkOut[PSTN_TLL_TICKET_BUFLEN_IN][8];
	char    asThirdParty[PSTN_TLL_TICKET_BUFLEN_IN][16];
	char    asMsrn[PSTN_TLL_TICKET_BUFLEN_IN][13];
	int     aiTrunkInTypeID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiTrunkOutTypeID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiTrunkInCarrierID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiTrunkOutCarrierID[PSTN_TLL_TICKET_BUFLEN_IN];
	char    asTrunkInType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asTrunkOutType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	int     aiCallingCarrierID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiCalledCarrierID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiCallingTypeID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiCalledTypeID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiCallingAreaID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiCalledAreaID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiASettAreaID[PSTN_TLL_TICKET_BUFLEN_IN];
	int     aiBSettAreaID[PSTN_TLL_TICKET_BUFLEN_IN];
	char    asSplitType[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asCal[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asEsn[PSTN_TLL_TICKET_BUFLEN_IN][16];
	char    asScpFlag[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asDeformFlag[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asReserve[PSTN_TLL_TICKET_BUFLEN_IN][9];
	char    asBillMode[PSTN_TLL_TICKET_BUFLEN_IN][4];
	char    asReserve1[PSTN_TLL_TICKET_BUFLEN_IN][3];
	char    asRoamTariffType[PSTN_TLL_TICKET_BUFLEN_IN][4];
	char    asTollTariffType[PSTN_TLL_TICKET_BUFLEN_IN][4];
	char    asAddTariffType[PSTN_TLL_TICKET_BUFLEN_IN][4];
	char    asErrCode[PSTN_TLL_TICKET_BUFLEN_IN][5];
	char    asFileName[PSTN_TLL_TICKET_BUFLEN_IN][20];
	char    asModule[PSTN_TLL_TICKET_BUFLEN_IN][4];
	char    asAreaCode[PSTN_TLL_TICKET_BUFLEN_IN][6];
	char    asState[PSTN_TLL_TICKET_BUFLEN_IN][2];
	char    asUpdateDate[PSTN_TLL_TICKET_BUFLEN_IN][15];
	char    asDealDate[PSTN_TLL_TICKET_BUFLEN_IN][15];
	char    asSourceID[PSTN_TLL_TICKET_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct PstnTllTicketStruct{

	struct PstnTllTicketStruct *pNext;
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
	struct PstnTllTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FPstnTllTicketStruct{

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
/*�������ݶ�̬��PSTN_TLL_TICKET���ýṹ���巽ʽȡ����*/
int EGetPstnTllTicketToStruct(struct PstnTllTicketStruct *p,
	struct PstnTllTicketStructIn *pSource);

void mvitem_pstntllticket(struct PstnTllTicketStruct *pi,struct PstnTllTicketStruct *po);

void mvitem_fmpstntllticket(struct FPstnTllTicketStruct *pi,struct PstnTllTicketStruct *po);

void mvitem_mfpstntllticket(struct PstnTllTicketStruct *pi,struct FPstnTllTicketStruct *po);

/**�Ա�PSTN_TLL_TICKET�������ͷź���**/
void DestroyPstnTllTicket(struct PstnTllTicketStruct *ptHead);

int InitPstnTllTicket(struct PstnTllTicketStruct **pptHead);

/*�������ݽṹ����д��PSTN_TLL_TICKET*/
int EInsertStructToPstnTllTicket(struct PstnTllTicketStruct *p,
	int iInsertFlag,struct PstnTllTicketStructOut *pTarget);


/**************************************************************************/


/*---------�������ִ��� dw_sus_voiticket_ds.txt----------*/

/*����ṹ��������*/
struct DwSusVoiticketDsStructOut{

#ifndef DW_SUS_VOITICKET_DS_BUFLEN_OUT
#define DW_SUS_VOITICKET_DS_BUFLEN_OUT		300
#endif

	struct DwSusVoiticketDsStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[63];
	char    asSvcid[DW_SUS_VOITICKET_DS_BUFLEN_OUT][2];
	char    asAccNbr[DW_SUS_VOITICKET_DS_BUFLEN_OUT][21];
	char    asCallType[DW_SUS_VOITICKET_DS_BUFLEN_OUT][3];
	char    asRoamType[DW_SUS_VOITICKET_DS_BUFLEN_OUT][3];
	char    asDistanceType[DW_SUS_VOITICKET_DS_BUFLEN_OUT][3];
	char    asDealerCode[DW_SUS_VOITICKET_DS_BUFLEN_OUT][3];
	char    asAreaID[DW_SUS_VOITICKET_DS_BUFLEN_OUT][4];
	char    asVisitAreaCode[DW_SUS_VOITICKET_DS_BUFLEN_OUT][11];
	int     aiTimeSect[DW_SUS_VOITICKET_DS_BUFLEN_OUT];
	char    asMsc[DW_SUS_VOITICKET_DS_BUFLEN_OUT][16];
	char    asLac[DW_SUS_VOITICKET_DS_BUFLEN_OUT][6];
	char    asCellID[DW_SUS_VOITICKET_DS_BUFLEN_OUT][21];
	char    asOtherParty[DW_SUS_VOITICKET_DS_BUFLEN_OUT][26];
	char    asCalledHomeCode[DW_SUS_VOITICKET_DS_BUFLEN_OUT][9];
	char    asSumTollCharge[DW_SUS_VOITICKET_DS_BUFLEN_OUT][13];
	char    asSumBasDura[DW_SUS_VOITICKET_DS_BUFLEN_OUT][13];
	char    asSumDura[DW_SUS_VOITICKET_DS_BUFLEN_OUT][13];
	char    asSumTimes[DW_SUS_VOITICKET_DS_BUFLEN_OUT][13];
	char    asCallDate[DW_SUS_VOITICKET_DS_BUFLEN_OUT][9];
};


/* ����ṹ��������*/
struct DwSusVoiticketDsStructIn{

#ifndef DW_SUS_VOITICKET_DS_BUFLEN_IN
#define DW_SUS_VOITICKET_DS_BUFLEN_IN		300
#endif

	struct DwSusVoiticketDsStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[63];
	char sCondition[1024];
	char    asSvcid[DW_SUS_VOITICKET_DS_BUFLEN_IN][2];
	char    asAccNbr[DW_SUS_VOITICKET_DS_BUFLEN_IN][21];
	char    asCallType[DW_SUS_VOITICKET_DS_BUFLEN_IN][3];
	char    asRoamType[DW_SUS_VOITICKET_DS_BUFLEN_IN][3];
	char    asDistanceType[DW_SUS_VOITICKET_DS_BUFLEN_IN][3];
	char    asDealerCode[DW_SUS_VOITICKET_DS_BUFLEN_IN][3];
	char    asAreaID[DW_SUS_VOITICKET_DS_BUFLEN_IN][4];
	char    asVisitAreaCode[DW_SUS_VOITICKET_DS_BUFLEN_IN][11];
	int     aiTimeSect[DW_SUS_VOITICKET_DS_BUFLEN_IN];
	char    asMsc[DW_SUS_VOITICKET_DS_BUFLEN_IN][16];
	char    asLac[DW_SUS_VOITICKET_DS_BUFLEN_IN][6];
	char    asCellID[DW_SUS_VOITICKET_DS_BUFLEN_IN][21];
	char    asOtherParty[DW_SUS_VOITICKET_DS_BUFLEN_IN][26];
	char    asCalledHomeCode[DW_SUS_VOITICKET_DS_BUFLEN_IN][9];
	char    asSumTollCharge[DW_SUS_VOITICKET_DS_BUFLEN_IN][13];
	char    asSumBasDura[DW_SUS_VOITICKET_DS_BUFLEN_IN][13];
	char    asSumDura[DW_SUS_VOITICKET_DS_BUFLEN_IN][13];
	char    asSumTimes[DW_SUS_VOITICKET_DS_BUFLEN_IN][13];
	char    asCallDate[DW_SUS_VOITICKET_DS_BUFLEN_IN][9];
};


/*�����ṹ����*/
struct DwSusVoiticketDsStruct{

	struct DwSusVoiticketDsStruct *pNext;
	char    sSvcid[2];
	char    sAccNbr[21];
	char    sCallType[3];
	char    sRoamType[3];
	char    sDistanceType[3];
	char    sDealerCode[3];
	char    sAreaID[4];
	char    sVisitAreaCode[11];
	int     iTimeSect;
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[21];
	char    sOtherParty[26];
	char    sCalledHomeCode[9];
	char    sSumTollCharge[13];
	char    sSumBasDura[13];
	char    sSumDura[13];
	char    sSumTimes[13];
	char    sCallDate[9];
	struct DwSusVoiticketDsStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FDwSusVoiticketDsStruct{

	char    sSvcid[1];
	char    sAccNbr[20];
	char    sCallType[2];
	char    sRoamType[2];
	char    sDistanceType[2];
	char    sDealerCode[2];
	char    sAreaID[3];
	char    sVisitAreaCode[10];
	char    sTimeSect[2];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[20];
	char    sOtherParty[25];
	char    sCalledHomeCode[8];
	char    sSumTollCharge[12];
	char    sSumBasDura[12];
	char    sSumDura[12];
	char    sSumTimes[12];
	char    sCallDate[8];
};
/*�������ݶ�̬��DW_SUS_VOITICKET_DS���ýṹ���巽ʽȡ����*/
int EGetDwSusVoiticketDsToStruct(struct DwSusVoiticketDsStruct *p,
	struct DwSusVoiticketDsStructIn *pSource);
	
void mvitem_dwsusvoiticketds(struct DwSusVoiticketDsStruct *pi,struct DwSusVoiticketDsStruct *po);

void mvitem_fmdwsusvoiticketds(struct FDwSusVoiticketDsStruct *pi,struct DwSusVoiticketDsStruct *po);

void mvitem_mfdwsusvoiticketds(struct DwSusVoiticketDsStruct *pi,struct FDwSusVoiticketDsStruct *po);

/**�Ա�DW_SUS_VOITICKET_DS�������ͷź���**/
void DestroyDwSusVoiticketDs(struct DwSusVoiticketDsStruct *ptHead);

int InitDwSusVoiticketDs(struct DwSusVoiticketDsStruct **pptHead);

/*�������ݽṹ����д��DW_SUS_VOITICKET_DS*/
int EInsertStructToDwSusVoiticketDs(struct DwSusVoiticketDsStruct *p,
	int iInsertFlag,struct DwSusVoiticketDsStructOut *pTarget);	
	
/*---------�������ִ��� tll_intf_wnj.txt----------*/

/*����ṹ��������*/
struct TllIntfWnjStructOut{

#ifndef TLL_INTF_WNJ_BUFLEN_OUT
#define TLL_INTF_WNJ_BUFLEN_OUT		300
#endif

	struct TllIntfWnjStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[63];
	char    asCallingNbr[TLL_INTF_WNJ_BUFLEN_OUT][21];
	char    asCallingAreaCode[TLL_INTF_WNJ_BUFLEN_OUT][6];
	char    asCallingUserType[TLL_INTF_WNJ_BUFLEN_OUT][2];
	char    asCalledNbr[TLL_INTF_WNJ_BUFLEN_OUT][25];
	char    asVisitAreaCode[TLL_INTF_WNJ_BUFLEN_OUT][6];
	char    asCalledUserType[TLL_INTF_WNJ_BUFLEN_OUT][2];
	char    asStartTime[TLL_INTF_WNJ_BUFLEN_OUT][15];
	int     aiDuration[TLL_INTF_WNJ_BUFLEN_OUT];
	int     aiTollFee[TLL_INTF_WNJ_BUFLEN_OUT];
};


/* ����ṹ��������*/
struct TllIntfWnjStructIn{

#ifndef TLL_INTF_WNJ_BUFLEN_IN
#define TLL_INTF_WNJ_BUFLEN_IN		300
#endif

	struct TllIntfWnjStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[63];
	char sCondition[1024];
	char    asCallingNbr[TLL_INTF_WNJ_BUFLEN_IN][21];
	char    asCallingAreaCode[TLL_INTF_WNJ_BUFLEN_IN][6];
	char    asCallingUserType[TLL_INTF_WNJ_BUFLEN_IN][2];
	char    asCalledNbr[TLL_INTF_WNJ_BUFLEN_IN][25];
	char    asVisitAreaCode[TLL_INTF_WNJ_BUFLEN_IN][6];
	char    asCalledUserType[TLL_INTF_WNJ_BUFLEN_IN][2];
	char    asStartTime[TLL_INTF_WNJ_BUFLEN_IN][15];
	int     aiDuration[TLL_INTF_WNJ_BUFLEN_IN];
	int     aiTollFee[TLL_INTF_WNJ_BUFLEN_IN];
};


/*�����ṹ����*/
struct TllIntfWnjStruct{

	struct TllIntfWnjStruct *pNext;
	char    sCallingNbr[21];
	char    sCallingAreaCode[6];
	char    sCallingUserType[2];
	char    sCalledNbr[25];
	char    sVisitAreaCode[6];
	char    sCalledUserType[2];
	char    sStartTime[15];
	int     iDuration;
	int     iTollFee;
	struct TllIntfWnjStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FTllIntfWnjStruct{

	char    sCallingNbr[20];
	char    sCallingAreaCode[5];
	char    sCallingUserType[1];
	char    sCalledNbr[24];
	char    sVisitAreaCode[5];
	char    sCalledUserType[1];
	char    sStartTime[14];
	char    sDuration[6];
	char    sTollFee[8];
};
/*�������ݶ�̬��TLL_INTF_WNJ���ýṹ���巽ʽȡ����*/
int EGetTllIntfWnjToStruct(struct TllIntfWnjStruct *p,
	struct TllIntfWnjStructIn *pSource);
	
void mvitem_tllintfwnj(struct TllIntfWnjStruct *pi,struct TllIntfWnjStruct *po);

void mvitem_fmtllintfwnj(struct FTllIntfWnjStruct *pi,struct TllIntfWnjStruct *po);

void mvitem_mftllintfwnj(struct TllIntfWnjStruct *pi,struct FTllIntfWnjStruct *po);

/**�Ա�TLL_INTF_WNJ�������ͷź���**/
void DestroyTllIntfWnj(struct TllIntfWnjStruct *ptHead);

int InitTllIntfWnj(struct TllIntfWnjStruct **pptHead);

/*�������ݽṹ����д��TLL_INTF_WNJ*/
int EInsertStructToTllIntfWnj(struct TllIntfWnjStruct *p,
	int iInsertFlag,struct TllIntfWnjStructOut *pTarget);
/**************************************************************************/

/*---------�������ִ��� stt_ticket_all.txt----------*/

/*����ṹ��������*/
struct SttTicketAllStructOut{

#ifndef STT_TICKET_ALL_BUFLEN_OUT
#define STT_TICKET_ALL_BUFLEN_OUT		300
#endif

	struct SttTicketAllStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[64];
	int     aiTicketTypeID[STT_TICKET_ALL_BUFLEN_OUT];
	char    asCallType[STT_TICKET_ALL_BUFLEN_OUT][3];
	char    asMsisdn[STT_TICKET_ALL_BUFLEN_OUT][16];
	char    asCalledCode[STT_TICKET_ALL_BUFLEN_OUT][6];
	char    asOtherParty[STT_TICKET_ALL_BUFLEN_OUT][25];
	char    asVisitAreaCode[STT_TICKET_ALL_BUFLEN_OUT][6];
	int     aiRoamFee[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiTollFee[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiAddFee[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiDuration[STT_TICKET_ALL_BUFLEN_OUT];
	char    asStartTime[STT_TICKET_ALL_BUFLEN_OUT][15];
	char    asHomeAreaCode[STT_TICKET_ALL_BUFLEN_OUT][6];
	char    asRoamType[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asDistanceType[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asOppType[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asUserType[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asSplitRuleID[STT_TICKET_ALL_BUFLEN_OUT][5];
	char    asOppRoamType[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asServiceType[STT_TICKET_ALL_BUFLEN_OUT][4];
	char    asServiceCode[STT_TICKET_ALL_BUFLEN_OUT][5];
	char    asImsi[STT_TICKET_ALL_BUFLEN_OUT][16];
	char    asMsc[STT_TICKET_ALL_BUFLEN_OUT][16];
	char    asLac[STT_TICKET_ALL_BUFLEN_OUT][6];
	char    asCellID[STT_TICKET_ALL_BUFLEN_OUT][6];
	char    asOtherLac[STT_TICKET_ALL_BUFLEN_OUT][6];
	char    asOtherCellID[STT_TICKET_ALL_BUFLEN_OUT][6];
	char    asTrunkIn[STT_TICKET_ALL_BUFLEN_OUT][8];
	char    asTrunkOut[STT_TICKET_ALL_BUFLEN_OUT][8];
	char    asThirdParty[STT_TICKET_ALL_BUFLEN_OUT][16];
	char    asMsrn[STT_TICKET_ALL_BUFLEN_OUT][13];
	int     aiTrunkInTypeID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiTrunkOutTypeID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiTrunkInCarrierID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiTrunkOutCarrierID[STT_TICKET_ALL_BUFLEN_OUT];
	char    asTrunkInType[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asTrunkOutType[STT_TICKET_ALL_BUFLEN_OUT][2];
	int     aiCallingCarrierID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiCalledCarrierID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiCallingTypeID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiCalledTypeID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiCallingAreaID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiCalledAreaID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiASettAreaID[STT_TICKET_ALL_BUFLEN_OUT];
	int     aiBSettAreaID[STT_TICKET_ALL_BUFLEN_OUT];
	char    asSplitType[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asCal[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asEsn[STT_TICKET_ALL_BUFLEN_OUT][16];
	char    asScpFlag[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asDeformFlag[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asReserve[STT_TICKET_ALL_BUFLEN_OUT][9];
	char    asBillMode[STT_TICKET_ALL_BUFLEN_OUT][4];
	char    asReserve1[STT_TICKET_ALL_BUFLEN_OUT][3];
	char    asRoamTariffType[STT_TICKET_ALL_BUFLEN_OUT][4];
	char    asTollTariffType[STT_TICKET_ALL_BUFLEN_OUT][4];
	char    asAddTariffType[STT_TICKET_ALL_BUFLEN_OUT][4];
	char    asErrCode[STT_TICKET_ALL_BUFLEN_OUT][5];
	char    asFileName[STT_TICKET_ALL_BUFLEN_OUT][20];
	char    asModule[STT_TICKET_ALL_BUFLEN_OUT][4];
	char    asAreaCode[STT_TICKET_ALL_BUFLEN_OUT][6];
	char    asState[STT_TICKET_ALL_BUFLEN_OUT][2];
	char    asUpdateDate[STT_TICKET_ALL_BUFLEN_OUT][15];
	char    asDealDate[STT_TICKET_ALL_BUFLEN_OUT][15];
	char    asSourceID[STT_TICKET_ALL_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct SttTicketAllStructIn{

#ifndef STT_TICKET_ALL_BUFLEN_IN
#define STT_TICKET_ALL_BUFLEN_IN		300
#endif

	struct SttTicketAllStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[64];
	char sCondition[1024];
	int     aiTicketTypeID[STT_TICKET_ALL_BUFLEN_IN];
	char    asCallType[STT_TICKET_ALL_BUFLEN_IN][3];
	char    asMsisdn[STT_TICKET_ALL_BUFLEN_IN][16];
	char    asCalledCode[STT_TICKET_ALL_BUFLEN_IN][6];
	char    asOtherParty[STT_TICKET_ALL_BUFLEN_IN][25];
	char    asVisitAreaCode[STT_TICKET_ALL_BUFLEN_IN][6];
	int     aiRoamFee[STT_TICKET_ALL_BUFLEN_IN];
	int     aiTollFee[STT_TICKET_ALL_BUFLEN_IN];
	int     aiAddFee[STT_TICKET_ALL_BUFLEN_IN];
	int     aiDuration[STT_TICKET_ALL_BUFLEN_IN];
	char    asStartTime[STT_TICKET_ALL_BUFLEN_IN][15];
	char    asHomeAreaCode[STT_TICKET_ALL_BUFLEN_IN][6];
	char    asRoamType[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asDistanceType[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asOppType[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asUserType[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asSplitRuleID[STT_TICKET_ALL_BUFLEN_IN][5];
	char    asOppRoamType[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asServiceType[STT_TICKET_ALL_BUFLEN_IN][4];
	char    asServiceCode[STT_TICKET_ALL_BUFLEN_IN][5];
	char    asImsi[STT_TICKET_ALL_BUFLEN_IN][16];
	char    asMsc[STT_TICKET_ALL_BUFLEN_IN][16];
	char    asLac[STT_TICKET_ALL_BUFLEN_IN][6];
	char    asCellID[STT_TICKET_ALL_BUFLEN_IN][6];
	char    asOtherLac[STT_TICKET_ALL_BUFLEN_IN][6];
	char    asOtherCellID[STT_TICKET_ALL_BUFLEN_IN][6];
	char    asTrunkIn[STT_TICKET_ALL_BUFLEN_IN][8];
	char    asTrunkOut[STT_TICKET_ALL_BUFLEN_IN][8];
	char    asThirdParty[STT_TICKET_ALL_BUFLEN_IN][16];
	char    asMsrn[STT_TICKET_ALL_BUFLEN_IN][13];
	int     aiTrunkInTypeID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiTrunkOutTypeID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiTrunkInCarrierID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiTrunkOutCarrierID[STT_TICKET_ALL_BUFLEN_IN];
	char    asTrunkInType[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asTrunkOutType[STT_TICKET_ALL_BUFLEN_IN][2];
	int     aiCallingCarrierID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiCalledCarrierID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiCallingTypeID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiCalledTypeID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiCallingAreaID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiCalledAreaID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiASettAreaID[STT_TICKET_ALL_BUFLEN_IN];
	int     aiBSettAreaID[STT_TICKET_ALL_BUFLEN_IN];
	char    asSplitType[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asCal[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asEsn[STT_TICKET_ALL_BUFLEN_IN][16];
	char    asScpFlag[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asDeformFlag[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asReserve[STT_TICKET_ALL_BUFLEN_IN][9];
	char    asBillMode[STT_TICKET_ALL_BUFLEN_IN][4];
	char    asReserve1[STT_TICKET_ALL_BUFLEN_IN][3];
	char    asRoamTariffType[STT_TICKET_ALL_BUFLEN_IN][4];
	char    asTollTariffType[STT_TICKET_ALL_BUFLEN_IN][4];
	char    asAddTariffType[STT_TICKET_ALL_BUFLEN_IN][4];
	char    asErrCode[STT_TICKET_ALL_BUFLEN_IN][5];
	char    asFileName[STT_TICKET_ALL_BUFLEN_IN][20];
	char    asModule[STT_TICKET_ALL_BUFLEN_IN][4];
	char    asAreaCode[STT_TICKET_ALL_BUFLEN_IN][6];
	char    asState[STT_TICKET_ALL_BUFLEN_IN][2];
	char    asUpdateDate[STT_TICKET_ALL_BUFLEN_IN][15];
	char    asDealDate[STT_TICKET_ALL_BUFLEN_IN][15];
	char    asSourceID[STT_TICKET_ALL_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct SttTicketAllStruct{

	struct SttTicketAllStruct *pNext;
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
	struct SttTicketAllStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSttTicketAllStruct{

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

/*�������ݶ�̬��STT_TICKET_ALL���ýṹ���巽ʽȡ����*/
int EGetSttTicketAllToStruct(struct SttTicketAllStruct *p,
	struct SttTicketAllStructIn *pSource);
	
void mvitem_sttticketall(struct SttTicketAllStruct *pi,struct SttTicketAllStruct *po);

void mvitem_fmsttticketall(struct FSttTicketAllStruct *pi,struct SttTicketAllStruct *po);

void mvitem_mfsttticketall(struct SttTicketAllStruct *pi,struct FSttTicketAllStruct *po);

/**�Ա�STT_TICKET_ALL�������ͷź���**/
void DestroySttTicketAll(struct SttTicketAllStruct *ptHead);

int InitSttTicketAll(struct SttTicketAllStruct **pptHead);

/*�������ݽṹ����д��STT_TICKET_ALL*/
int EInsertStructToSttTicketAll(struct SttTicketAllStruct *p,
	int iInsertFlag,struct SttTicketAllStructOut *pTarget);
#endif
	