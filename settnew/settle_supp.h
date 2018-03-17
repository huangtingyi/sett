#ifndef _DETAIL_SUPP_H_
#define _DETAIL_SUPP_H_


/*输出结构缓冲申明*/
struct TemplateSmsMmsTicketStructOut{

#ifndef TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT
#define TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT		300
#endif

	struct TemplateSmsMmsTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asSettLatnID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][2];
	int     aiReportItemID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT];
	char    asProdID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][11];
	char    asCallType[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][2];
	char    asHomeAreaCode[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][6];
	char    asMsisdn[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][16];
	char    asOppAreaCode[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][16];
	char    asStartTime[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][15];
	int     aiSettFee[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT];
	char    asMy3gFlag[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][2];
	char    asOpp3gFlag[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][2];
	char    asMyCarrID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][2];
	char    asOppCarrID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][2];
	char    asServFlag[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][2];
	char    asFileName[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][61];
	char    asGroupID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
struct TemplateSmsMmsTicketStructIn{

#ifndef TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN
#define TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN		300
#endif

	struct TemplateSmsMmsTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSettLatnID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][2];
	int     aiReportItemID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN];
	char    asProdID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][11];
	char    asCallType[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][2];
	char    asHomeAreaCode[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][6];
	char    asMsisdn[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][16];
	char    asOppAreaCode[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][6];
	char    asOtherParty[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][16];
	char    asStartTime[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][15];
	int     aiSettFee[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN];
	char    asMy3gFlag[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][2];
	char    asOpp3gFlag[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][2];
	char    asMyCarrID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][2];
	char    asOppCarrID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][2];
	char    asServFlag[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][2];
	char    asFileName[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][61];
	char    asGroupID[TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN][3];
};


/*单个结构申明*/
struct TemplateSmsMmsTicketStruct{

	struct TemplateSmsMmsTicketStruct *pNext;
	char    sSettLatnID[2];
	int     iReportItemID;
	char    sProdID[11];
	char    sCallType[2];
	char    sHomeAreaCode[6];
	char    sMsisdn[16];
	char    sOppAreaCode[6];
	char    sOtherParty[16];
	char    sStartTime[15];
	int     iSettFee;
	char    sMy3gFlag[2];
	char    sOpp3gFlag[2];
	char    sMyCarrID[2];
	char    sOppCarrID[2];
	char    sServFlag[2];
	char    sFileName[61];
	char	sOppNbrType[2];
	char	sMyNbrType[2];
	char    sGroupID[3];
	struct TemplateSmsMmsTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTemplateSmsMmsTicketStruct{

	char    sSettLatnID[1];
	char    sReportItemID[8];
	char    sProdID[10];
	char    sCallType[1];
	char    sHomeAreaCode[5];
	char    sMsisdn[15];
	char    sOppAreaCode[5];
	char    sOtherParty[15];
	char    sStartTime[14];
	char    sSettFee[9];
	char    sMy3gFlag[1];
	char    sOpp3gFlag[1];
	char    sMyCarrID[1];
	char    sOppCarrID[1];
	char    sServFlag[1];
	char    sFileName[60];
	char    sGroupID[2];
};

struct FTemplateSmsTicketStruct{

	char    sSettLatnID[1];
	char    sReportItemID[8];
	char    sProdID[10];
	char    sCallType[1];
	char    sHomeAreaCode[5];
	char    sMsisdn[15];
	char    sOppAreaCode[5];
	char    sOtherParty[15];
	char    sStartTime[14];
	char    sSettFee[9];
	char    sMy3gFlag[1];
	char    sOpp3gFlag[1];
	char    sMyCarrID[1];
	char    sOppCarrID[1];
	char    sServFlag[1];
	char    sFileName[60];
	char    sGroupID[2];
};
/*批量数据动态从TEMPLATE_SMS_MMS_TICKET中用结构缓冲方式取数据*/
int EGetTemplateSmsMmsTicketToStruct(struct TemplateSmsMmsTicketStruct *p,
	struct TemplateSmsMmsTicketStructIn *pSource);
void mvitem_fmtemplatesmsmmsticket(struct FTemplateSmsMmsTicketStruct *pi,
	struct TemplateSmsMmsTicketStruct *po);
/**对表TEMPLATE_SMS_MMS_TICKET的链表释放函数**/
void DestroyTemplateSmsMmsTicket(struct TemplateSmsMmsTicketStruct *ptHead);
/*批量数据结构缓冲写入TEMPLATE_SMS_MMS_TICKET*/
int EInsertStructToTemplateSmsMmsTicket(struct TemplateSmsMmsTicketStruct *p,
	int iInsertFlag,struct TemplateSmsMmsTicketStructOut *pTarget);


/*---------基本部分代码 template_stt_ticket.txt----------*/

/*输出结构缓冲申明*/
struct TemplateSttTicketStructOut{

#ifndef TEMPLATE_STT_TICKET_BUFLEN_OUT
#define TEMPLATE_STT_TICKET_BUFLEN_OUT		300
#endif

	struct TemplateSttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asSettLatnID[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	int     aiReportItemID[TEMPLATE_STT_TICKET_BUFLEN_OUT];
	char    asProdID[TEMPLATE_STT_TICKET_BUFLEN_OUT][11];
	char    asCallType[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asHomeAreaCode[TEMPLATE_STT_TICKET_BUFLEN_OUT][6];
	char    asMsisdn[TEMPLATE_STT_TICKET_BUFLEN_OUT][16];
	char    asOppAreaCode[TEMPLATE_STT_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[TEMPLATE_STT_TICKET_BUFLEN_OUT][16];
	char    asStartTime[TEMPLATE_STT_TICKET_BUFLEN_OUT][15];
	int     aiDuration[TEMPLATE_STT_TICKET_BUFLEN_OUT];
	int     aiSettFee[TEMPLATE_STT_TICKET_BUFLEN_OUT];
	char    asMyDistanceType[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asOppDistanceType[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asMyNbrType[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asOppNbrType[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asMy3gFlag[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asOpp3gFlag[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asMsc[TEMPLATE_STT_TICKET_BUFLEN_OUT][11];
	char    asTrunkIn[TEMPLATE_STT_TICKET_BUFLEN_OUT][8];
	char    asTrunkOut[TEMPLATE_STT_TICKET_BUFLEN_OUT][8];
	char    asTrunkInCarrID[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asTrunkOutCarrID[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asMyCarrID[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asOppCarrID[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	int     aiMyAreaID[TEMPLATE_STT_TICKET_BUFLEN_OUT];
	int     aiOppAreaID[TEMPLATE_STT_TICKET_BUFLEN_OUT];
	char    asServFlag[TEMPLATE_STT_TICKET_BUFLEN_OUT][2];
	char    asFileName[TEMPLATE_STT_TICKET_BUFLEN_OUT][61];
	char    asGroupID[TEMPLATE_STT_TICKET_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
struct TemplateSttTicketStructIn{

#ifndef TEMPLATE_STT_TICKET_BUFLEN_IN
#define TEMPLATE_STT_TICKET_BUFLEN_IN		300
#endif

	struct TemplateSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[64];
	char sCondition[1024];
	char    asSettLatnID[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	int     aiReportItemID[TEMPLATE_STT_TICKET_BUFLEN_IN];
	char    asProdID[TEMPLATE_STT_TICKET_BUFLEN_IN][11];
	char    asCallType[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asHomeAreaCode[TEMPLATE_STT_TICKET_BUFLEN_IN][6];
	char    asMsisdn[TEMPLATE_STT_TICKET_BUFLEN_IN][16];
	char    asOppAreaCode[TEMPLATE_STT_TICKET_BUFLEN_IN][6];
	char    asOtherParty[TEMPLATE_STT_TICKET_BUFLEN_IN][16];
	char    asStartTime[TEMPLATE_STT_TICKET_BUFLEN_IN][15];
	int     aiDuration[TEMPLATE_STT_TICKET_BUFLEN_IN];
	int     aiSettFee[TEMPLATE_STT_TICKET_BUFLEN_IN];
	char    asMyDistanceType[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asOppDistanceType[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asMyNbrType[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asOppNbrType[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asMy3gFlag[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asOpp3gFlag[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asMsc[TEMPLATE_STT_TICKET_BUFLEN_IN][11];
	char    asTrunkIn[TEMPLATE_STT_TICKET_BUFLEN_IN][8];
	char    asTrunkOut[TEMPLATE_STT_TICKET_BUFLEN_IN][8];
	char    asTrunkInCarrID[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asTrunkOutCarrID[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asMyCarrID[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asOppCarrID[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	int     aiMyAreaID[TEMPLATE_STT_TICKET_BUFLEN_IN];
	int     aiOppAreaID[TEMPLATE_STT_TICKET_BUFLEN_IN];
	char    asServFlag[TEMPLATE_STT_TICKET_BUFLEN_IN][2];
	char    asFileName[TEMPLATE_STT_TICKET_BUFLEN_IN][61];
	char    asGroupID[TEMPLATE_STT_TICKET_BUFLEN_IN][3];
};


/*单个结构申明*/
struct TemplateSttTicketStruct{

	struct TemplateSttTicketStruct *pNext;
	char    sSettLatnID[2];
	int     iReportItemID;
	char    sProdID[11];
	char    sCallType[2];
	char    sHomeAreaCode[6];
	char    sMsisdn[16];
	char    sOppAreaCode[6];
	char    sOtherParty[16];
	char    sStartTime[15];
	int     iDuration;
	int     iSettFee;
	char    sMyDistanceType[2];
	char    sOppDistanceType[2];
	char    sMyNbrType[2];
	char    sOppNbrType[2];
	char    sMy3gFlag[2];
	char    sOpp3gFlag[2];
	char    sMsc[11];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sTrunkInCarrID[2];
	char    sTrunkOutCarrID[2];
	char    sMyCarrID[2];
	char    sOppCarrID[2];
	int     iMyAreaID;
	int     iOppAreaID;
	char    sServFlag[2];
	char    sFileName[61];
	char    sGroupID[3];
	struct TemplateSttTicketStruct *pLoadNext;
};


/*批量数据动态从TEMPLATE_STT_TICKET中用结构缓冲方式取数据*/
int EGetTemplateSttTicketToStruct(struct TemplateSttTicketStruct *p,
	struct TemplateSttTicketStructIn *pSource);
/*批量数据结构缓冲写入TEMPLATE_STT_TICKET*/
int EInsertStructToTemplateSttTicket(struct TemplateSttTicketStruct *p,
	int iInsertFlag,struct TemplateSttTicketStructOut *pTarget);
	
/*--------- ----------*/
/*输出结构缓冲申明*/
struct TTemplateYdGwUeStructOut{

#ifndef T_TEMPLATE_YD_GW_UE_BUFLEN_OUT
#define T_TEMPLATE_YD_GW_UE_BUFLEN_OUT		300
#endif

	struct TTemplateYdGwUeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[256];
	char    asUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asProdID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asStartTime[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][15];
	char    asEndTime[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][15];
	char    asRateTime[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][15];
	char    asOperationTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][9];
	char    asCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCalledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asBilledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asThirdNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	int     aiCallingAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiCalledAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asInTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asOutTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	int     aiRawUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asRawUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiRateUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asIsFree[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	int     aiRateUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asCalledAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asCallingRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCalledRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCallingRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asCalledRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asTotalDueAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiProdInstID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiRateID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asUpFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asDuration[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asDownFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asFileName[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][61];
	char    asTotalFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asStatus[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][4];
	int     aiBillCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asCurrBalance[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiCreateCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asRateKey1[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asRateKey2[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asRateKey3[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	int     aiPureCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiFileClassID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asExceptionType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][6];
	char    asOrigUsageTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][13];
	int     aiTotalDueUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asStlAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asPostFlag[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	int     aiIsPrepay[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	int     aiParentFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asTableName[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCalledCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asSwitchCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asDurationMinnum[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asDurationSec6[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asInTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asOutTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asCallingNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCalledNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asCalledGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][16];
	char    asStlObject[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asProdPropID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCallingSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asCalledSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	int     aiStlDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asPreCallType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asTurnCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][51];
	char    asTurnCodeCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asTurnCodeProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	int     aiTurnCodeCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT];
	char    asTurnCodeOperationTypeGrade[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asTurnType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asTurnCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	char    asSecondCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asSecondCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asSecondCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asSecondCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asPreCallParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asPreCallSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asPreCallSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	char    asPreCallSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asPreCallUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asTurnParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asTurnSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asTurnSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][5];
	char    asTurnSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char    asTurnUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][19];
	char    asInTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asOutTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asInTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asOutTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCallingNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCalledNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCallingDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asCalledDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asSecondSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][21];
	char    asSecondCallingRoamnumber[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][31];
	char    asViewCall[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][11];
	char	asGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
struct TTemplateYdGwUeStructIn{

#ifndef T_TEMPLATE_YD_GW_UE_BUFLEN_IN
#define T_TEMPLATE_YD_GW_UE_BUFLEN_IN		300
#endif

	struct TTemplateYdGwUeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[256];
	char sCondition[1024];
	char    asUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asProdID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asStartTime[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][15];
	char    asEndTime[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][15];
	char    asRateTime[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][15];
	char    asOperationTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][9];
	char    asCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCalledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asBilledNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asThirdNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	int     aiCallingAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiCalledAreaID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asInTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asOutTrunkNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	int     aiRawUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asRawUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiRateUnitType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asIsFree[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	int     aiRateUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asCalledAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asCallingRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCalledRoamNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCallingRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asCalledRoamAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asTotalDueAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiProdInstID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiRateID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asUpFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asDuration[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asDownFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asFileName[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][61];
	char    asTotalFlux[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asStatus[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][4];
	int     aiBillCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asCurrBalance[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiCreateCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asRateKey1[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asRateKey2[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asRateKey3[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	int     aiPureCycleSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiFileClassID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asExceptionType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][6];
	char    asOrigUsageTypeID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][13];
	int     aiTotalDueUnits[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asStlAmount[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asPostFlag[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	int     aiIsPrepay[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	int     aiParentFileID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asTableName[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCalledCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asSwitchCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asDurationMinnum[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asDurationSec6[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asInTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asOutTrunkGroup[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asCallingNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCalledNumberCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asCalledGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][16];
	char    asStlObject[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asProdPropID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCallingSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asCalledSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	int     aiStlDirection[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asPreCallType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asTurnCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][51];
	char    asTurnCodeCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asTurnCodeProvinceID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	int     aiTurnCodeCityID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN];
	char    asTurnCodeOperationTypeGrade[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asTurnType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asTurnCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	char    asSecondCallingNumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asSecondCallingAreaCode[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asSecondCallingGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asSecondCallingCompanyID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asPreCallParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asPreCallSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asPreCallSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	char    asPreCallSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asPreCallUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asTurnParentCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asTurnSubCdrID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asTurnSubCdrNum[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][5];
	char    asTurnSubCdrSeq[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char    asTurnUsageEventID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][19];
	char    asInTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asOutTrunkGenre[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asInTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asOutTrunkNetType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCallingNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCalledNumberType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCallingDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asCalledDomainID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asSecondSubType[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][21];
	char    asSecondCallingRoamnumber[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][31];
	char    asViewCall[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][11];
	char	asGroupID[T_TEMPLATE_YD_GW_UE_BUFLEN_IN][3];
};

/*单个结构申明*/
struct TTemplateYdGwUeStruct{

	struct TTemplateYdGwUeStruct *pNext;
	char    sUsageEventID[19];
	char    sProdID[11];
	char    sStartTime[15];
	char    sEndTime[15];
	char    sRateTime[15];
	char    sOperationTypeID[9];
	char    sCallingNumber[31];
	char    sCalledNumber[31];
	char    sBilledNumber[31];
	char    sThirdNumber[31];
	int     iCallingAreaID;
	int     iCalledAreaID;
	char    sInTrunkNumber[21];
	char    sOutTrunkNumber[21];
	int     iRawUnitType;
	char    sRawUnits[19];
	int     iRateUnitType;
	char    sIsFree[21];
	int     iRateUnits;
	char    sCallingAreaCode[11];
	char    sCalledAreaCode[11];
	char    sCallingRoamNumber[31];
	char    sCalledRoamNumber[31];
	char    sCallingRoamAreaCode[11];
	char    sCalledRoamAreaCode[11];
	char    sTotalDueAmount[19];
	int     iProdInstID;
	int     iRateID;
	char    sUpFlux[19];
	char    sDuration[19];
	int     iCityID;
	char    sDownFlux[19];
	char    sFileName[61];
	char    sTotalFlux[19];
	char    sStatus[4];
	int     iBillCycleSeq;
	char    sCurrBalance[19];
	int     iCreateCycleSeq;
	char    sRateKey1[31];
	char    sRateKey2[31];
	char    sRateKey3[31];
	int     iPureCycleSeq;
	int     iDirection;
	int     iFileClassID;
	char    sExceptionType[6];
	char    sOrigUsageTypeID[13];
	int     iTotalDueUnits;
	char    sStlAmount[19];
	char    sPostFlag[5];
	int     iIsPrepay;
	int     iFileID;
	int     iParentFileID;
	char    sTableName[31];
	char    sCallingCompanyID[19];
	char    sCalledCompanyID[19];
	char    sSwitchCompanyID[19];
	char    sProvinceID[21];
	char    sDurationMinnum[19];
	char    sDurationSec6[19];
	char    sInTrunkGroup[16];
	char    sOutTrunkGroup[16];
	char    sCallingNumberCompanyID[19];
	char    sCalledNumberCompanyID[19];
	char    sCallingGroupID[16];
	char    sCalledGroupID[16];
	char    sStlObject[19];
	char    sProdPropID[19];
	char    sCallingSubType[19];
	char    sCalledSubType[19];
	int     iStlDirection;
	char    sPreCallType[31];
	char    sTurnCode[51];
	char    sTurnCodeCompanyID[11];
	char    sTurnCodeProvinceID[21];
	int     iTurnCodeCityID;
	char    sTurnCodeOperationTypeGrade[31];
	char    sTurnType[31];
	char    sTurnCdrID[5];
	char    sSecondCallingNumber[31];
	char    sSecondCallingAreaCode[11];
	char    sSecondCallingGroupID[31];
	char    sSecondCallingCompanyID[11];
	char    sPreCallParentCdrID[21];
	char    sPreCallSubCdrID[21];
	char    sPreCallSubCdrNum[5];
	char    sPreCallSubCdrSeq[11];
	char    sPreCallUsageEventID[19];
	char    sTurnParentCdrID[21];
	char    sTurnSubCdrID[21];
	char    sTurnSubCdrNum[5];
	char    sTurnSubCdrSeq[11];
	char    sTurnUsageEventID[19];
	char    sInTrunkGenre[21];
	char    sOutTrunkGenre[21];
	char    sInTrunkNetType[21];
	char    sOutTrunkNetType[21];
	char    sCallingNumberType[21];
	char    sCalledNumberType[21];
	char    sCallingDomainID[21];
	char    sCalledDomainID[21];
	char    sSecondSubType[21];
	char    sSecondCallingRoamnumber[31];
	char    sViewCall[11];
	char	sGroupID[3];
	struct TTemplateYdGwUeStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTTemplateYdGwUeStruct{

	char    sUsageEventID[18];
	char    sProdID[10];
	char    sStartTime[14];
	char    sEndTime[14];
	char    sRateTime[14];
	char    sOperationTypeID[8];
	char    sCallingNumber[30];
	char    sCalledNumber[30];
	char    sBilledNumber[30];
	char    sThirdNumber[30];
	char    sCallingAreaID[8];
	char    sCalledAreaID[8];
	char    sInTrunkNumber[20];
	char    sOutTrunkNumber[20];
	char    sRawUnitType[4];
	char    sRawUnits[18];
	char    sRateUnitType[4];
	char    sIsFree[20];
	char    sRateUnits[8];
	char    sCallingAreaCode[10];
	char    sCalledAreaCode[10];
	char    sCallingRoamNumber[30];
	char    sCalledRoamNumber[30];
	char    sCallingRoamAreaCode[10];
	char    sCalledRoamAreaCode[10];
	char    sTotalDueAmount[18];
	char    sProdInstID[8];
	char    sRateID[8];
	char    sUpFlux[18];
	char    sDuration[18];
	char    sCityID[8];
	char    sDownFlux[18];
	char    sFileName[60];
	char    sTotalFlux[18];
	char    sStatus[3];
	char    sBillCycleSeq[8];
	char    sCurrBalance[18];
	char    sCreateCycleSeq[8];
	char    sRateKey1[30];
	char    sRateKey2[30];
	char    sRateKey3[30];
	char    sPureCycleSeq[8];
	char    sDirection[1];
	char    sFileClassID[8];
	char    sExceptionType[5];
	char    sOrigUsageTypeID[12];
	char    sTotalDueUnits[8];
	char    sStlAmount[18];
	char    sPostFlag[4];
	char    sIsPrepay[1];
	char    sFileID[9];
	char    sParentFileID[9];
	char    sTableName[30];
	char    sCallingCompanyID[18];
	char    sCalledCompanyID[18];
	char    sSwitchCompanyID[18];
	char    sProvinceID[20];
	char    sDurationMinnum[18];
	char    sDurationSec6[18];
	char    sInTrunkGroup[15];
	char    sOutTrunkGroup[15];
	char    sCallingNumberCompanyID[18];
	char    sCalledNumberCompanyID[18];
	char    sCallingGroupID[15];
	char    sCalledGroupID[15];
	char    sStlObject[18];
	char    sProdPropID[18];
	char    sCallingSubType[18];
	char    sCalledSubType[18];
	char    sStlDirection[1];
	char    sPreCallType[30];
	char    sTurnCode[50];
	char    sTurnCodeCompanyID[10];
	char    sTurnCodeProvinceID[20];
	char    sTurnCodeCityID[8];
	char    sTurnCodeOperationTypeGrade[30];
	char    sTurnType[30];
	char    sTurnCdrID[4];
	char    sSecondCallingNumber[30];
	char    sSecondCallingAreaCode[10];
	char    sSecondCallingGroupID[30];
	char    sSecondCallingCompanyID[10];
	char    sPreCallParentCdrID[20];
	char    sPreCallSubCdrID[20];
	char    sPreCallSubCdrNum[4];
	char    sPreCallSubCdrSeq[10];
	char    sPreCallUsageEventID[18];
	char    sTurnParentCdrID[20];
	char    sTurnSubCdrID[20];
	char    sTurnSubCdrNum[4];
	char    sTurnSubCdrSeq[10];
	char    sTurnUsageEventID[18];
	char    sInTrunkGenre[20];
	char    sOutTrunkGenre[20];
	char    sInTrunkNetType[20];
	char    sOutTrunkNetType[20];
	char    sCallingNumberType[20];
	char    sCalledNumberType[20];
	char    sCallingDomainID[20];
	char    sCalledDomainID[20];
	char    sSecondSubType[20];
	char    sSecondCallingRoamnumber[30];
	char    sViewCall[10];
};

/*批量数据动态从T_TEMPLATE_YD_GW_UE中用结构缓冲方式取数据*/
int EGetTTemplateYdGwUeToStruct(struct TTemplateYdGwUeStruct *p,
	struct TTemplateYdGwUeStructIn *pSource);
void mvitem_fmttemplateydgwue(struct FTTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po);


/*自定义结构体*/
struct TableNameBinTreeStruct{
	
	char    sTableName[31];
	BINTREE *ptRoot;
	
};


/*---------基本部分代码 SETT_BILL_STOR_LOG.txt----------*/
/*输出结构缓冲申明*/
struct SettBillStorLogStructOut{

#ifndef SETT_BILL_STOR_LOG_BUFLEN_OUT
#define SETT_BILL_STOR_LOG_BUFLEN_OUT		300
#endif

	struct SettBillStorLogStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiSettBillStorSeq[SETT_BILL_STOR_LOG_BUFLEN_OUT];
	char    asFileName[SETT_BILL_STOR_LOG_BUFLEN_OUT][65];
	char    asFileDate[SETT_BILL_STOR_LOG_BUFLEN_OUT][9];
	char    asDealTime[SETT_BILL_STOR_LOG_BUFLEN_OUT][15];
	char    asState[SETT_BILL_STOR_LOG_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct SettBillStorLogStructIn{

#ifndef SETT_BILL_STOR_LOG_BUFLEN_IN
#define SETT_BILL_STOR_LOG_BUFLEN_IN		300
#endif

	struct SettBillStorLogStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiSettBillStorSeq[SETT_BILL_STOR_LOG_BUFLEN_IN];
	char    asFileName[SETT_BILL_STOR_LOG_BUFLEN_IN][65];
	char    asFileDate[SETT_BILL_STOR_LOG_BUFLEN_IN][9];
	char    asDealTime[SETT_BILL_STOR_LOG_BUFLEN_IN][15];
	char    asState[SETT_BILL_STOR_LOG_BUFLEN_IN][2];
};


/*单个结构申明*/
struct SettBillStorLogStruct{

	struct SettBillStorLogStruct *pNext;
	int     iSettBillStorSeq;
	char    sFileName[65];
	char    sFileDate[9];
	char    sDealTime[15];
	char    sState[2];
	struct SettBillStorLogStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSettBillStorLogStruct{

	char    sSettBillStorSeq[9];
	char    sFileName[64];
	char    sFileDate[8];
	char    sDealTime[14];
	char    sState[1];
};
int SDInsertStructToSettBillStorLog(struct SettBillStorLogStruct *p,char sTableName[]);
int SDGetSettBillStorLogToStruct(struct SettBillStorLogStruct *p,char sTableName[],char sCondition[]);



/*---------基本部分代码 template_mid_stt_ticket.txt----------*/

/*输出结构缓冲申明*/
struct TemplateMidSttTicketStructOut{

#ifndef TEMPLATE_MID_STT_TICKET_BUFLEN_OUT
#define TEMPLATE_MID_STT_TICKET_BUFLEN_OUT		300
#endif

	struct TemplateMidSttTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asSettLatnID[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	int     aiReportItemID[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT];
	char    asProdID[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][11];
	char    asCallType[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asHomeAreaCode[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][6];
	char    asMsisdn[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][16];
	char    asOppAreaCode[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][6];
	char    asOtherParty[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][16];
	char    asSettDate[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][15];
	int     aiCnt[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT];
	int     aiDuration[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT];
	int     aiSettDuration[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT];
	int     aiSettFee[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT];
	char    asMyDistanceType[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asOppDistanceType[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asMyNbrType[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asOppNbrType[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asMy3gFlag[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asOpp3gFlag[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asMyCarrID[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asOppCarrID[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asServFlag[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][2];
	char    asGroupID[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][3];
	char    asOtherGroupID[TEMPLATE_MID_STT_TICKET_BUFLEN_OUT][3];
};


/* 输入结构缓冲申明*/
struct TemplateMidSttTicketStructIn{

#ifndef TEMPLATE_MID_STT_TICKET_BUFLEN_IN
#define TEMPLATE_MID_STT_TICKET_BUFLEN_IN		300
#endif

	struct TemplateMidSttTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[64];
	char sCondition[1024];
	char    asSettLatnID[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	int     aiReportItemID[TEMPLATE_MID_STT_TICKET_BUFLEN_IN];
	char    asProdID[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][11];
	char    asCallType[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asHomeAreaCode[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][6];
	char    asMsisdn[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][16];
	char    asOppAreaCode[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][6];
	char    asOtherParty[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][16];
	char    asSettDate[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][15];
	int     aiCnt[TEMPLATE_MID_STT_TICKET_BUFLEN_IN];
	int     aiDuration[TEMPLATE_MID_STT_TICKET_BUFLEN_IN];
	int     aiSettDuration[TEMPLATE_MID_STT_TICKET_BUFLEN_IN];
	int     aiSettFee[TEMPLATE_MID_STT_TICKET_BUFLEN_IN];
	char    asMyDistanceType[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asOppDistanceType[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asMyNbrType[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asOppNbrType[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asMy3gFlag[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asOpp3gFlag[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asMyCarrID[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asOppCarrID[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asServFlag[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][2];
	char    asGroupID[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][3];
	char    asOtherGroupID[TEMPLATE_MID_STT_TICKET_BUFLEN_IN][3];
};


/*单个结构申明*/
struct TemplateMidSttTicketStruct{

	struct TemplateMidSttTicketStruct *pNext;
	char    sSettLatnID[2];
	int     iReportItemID;
	char    sProdID[11];
	char    sCallType[2];
	char    sHomeAreaCode[6];
	char    sMsisdn[16];
	char    sOppAreaCode[6];
	char    sOtherParty[16];
	char    sSettDate[15];
	int     iCnt;
	int     iDuration;
	int     iSettDuration;
	int     iSettFee;
	char    sMyDistanceType[2];
	char    sOppDistanceType[2];
	char    sMyNbrType[2];
	char    sOppNbrType[2];
	char    sMy3gFlag[2];
	char    sOpp3gFlag[2];
	char    sMyCarrID[2];
	char    sOppCarrID[2];
	char    sServFlag[2];
	char    sGroupID[3];
	char    sOtherGroupID[3];
	struct TemplateMidSttTicketStruct *pLoadNext;
};



/*批量数据动态从TEMPLATE_MID_STT_TICKET中用结构缓冲方式取数据*/
int EGetTemplateMidSttTicketToStruct(struct TemplateMidSttTicketStruct *p,
	struct TemplateMidSttTicketStructIn *pSource);
/*批量数据结构缓冲写入TEMPLATE_MID_STT_TICKET*/
int EInsertStructToTemplateMidSttTicket(struct TemplateMidSttTicketStruct *p,
	int iInsertFlag,struct TemplateMidSttTicketStructOut *pTarget);
	

/*---------基本部分代码 an_stat_ununsal_ticket.txt----------*/

/*输出结构缓冲申明*/
struct AnStatUnunsalTicketStructOut{

#ifndef AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT
#define AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT		300
#endif

	struct AnStatUnunsalTicketStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asHomeAreaCode[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT][6];
	char    asMsisdn[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT][16];
	char    asSettDate[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT][15];
	int     aiCnt[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT];
	int     aiDuration[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT];
	int     aiSettDuration[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT];
	int     aiInFee[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT];
	int     aiOutFee[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT];
	char    asMyNbrType[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT][2];
	char    asMy3gFlag[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT][2];
	char    asMyCarrID[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT][2];
	char    asServFlag[AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct AnStatUnunsalTicketStructIn{

#ifndef AN_STAT_UNUNSAL_TICKET_BUFLEN_IN
#define AN_STAT_UNUNSAL_TICKET_BUFLEN_IN		300
#endif

	struct AnStatUnunsalTicketStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asHomeAreaCode[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN][6];
	char    asMsisdn[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN][16];
	char    asSettDate[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN][15];
	int     aiCnt[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN];
	int     aiDuration[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN];
	int     aiSettDuration[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN];
	int     aiInFee[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN];
	int     aiOutFee[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN];
	char    asMyNbrType[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN][2];
	char    asMy3gFlag[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN][2];
	char    asMyCarrID[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN][2];
	char    asServFlag[AN_STAT_UNUNSAL_TICKET_BUFLEN_IN][2];
};


/*单个结构申明*/
struct AnStatUnunsalTicketStruct{

	struct AnStatUnunsalTicketStruct *pNext;
	char    sHomeAreaCode[6];
	char    sMsisdn[16];
	char    sSettDate[15];
	int     iCnt;
	int     iDuration;
	int     iSettDuration;
	int     iInFee;
	int     iOutFee;
	char    sMyNbrType[2];
	char    sMy3gFlag[2];
	char    sMyCarrID[2];
	char    sServFlag[2];
	struct AnStatUnunsalTicketStruct *pLoadNext;
};

/*批量数据动态从AN_STAT_UNUNSAL_TICKET中用结构缓冲方式取数据*/
int EGetAnStatUnunsalTicketToStruct(struct AnStatUnunsalTicketStruct *p,
	struct AnStatUnunsalTicketStructIn *pSource);
/*批量数据结构缓冲写入AN_STAT_UNUNSAL_TICKET*/
int EInsertStructToAnStatUnunsalTicket(struct AnStatUnunsalTicketStruct *p,
	int iInsertFlag,struct AnStatUnunsalTicketStructOut *pTarget);




/*---------基本部分代码 template_stt_trend.txt----------*/

/*输出结构缓冲申明*/
struct TemplateSttTrendStructOut{

#ifndef TEMPLATE_STT_TREND_BUFLEN_OUT
#define TEMPLATE_STT_TREND_BUFLEN_OUT		300
#endif

	struct TemplateSttTrendStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asSettLatnID[TEMPLATE_STT_TREND_BUFLEN_OUT][2];
	int     aiReportItemID[TEMPLATE_STT_TREND_BUFLEN_OUT];
	char    asSettDate[TEMPLATE_STT_TREND_BUFLEN_OUT][15];
	int     aiCnt[TEMPLATE_STT_TREND_BUFLEN_OUT];
	char    asDuration[TEMPLATE_STT_TREND_BUFLEN_OUT][13];
	char    asSettDuration[TEMPLATE_STT_TREND_BUFLEN_OUT][13];
	char    asInFee[TEMPLATE_STT_TREND_BUFLEN_OUT][13];
	char    asOutFee[TEMPLATE_STT_TREND_BUFLEN_OUT][13];
	char    asMyNbrType[TEMPLATE_STT_TREND_BUFLEN_OUT][2];
	char    asMy3gFlag[TEMPLATE_STT_TREND_BUFLEN_OUT][2];
	char    asOppCarrID[TEMPLATE_STT_TREND_BUFLEN_OUT][2];
	char    asOpp3gFlag[TEMPLATE_STT_TREND_BUFLEN_OUT][2];
	char    asServFlag[TEMPLATE_STT_TREND_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct TemplateSttTrendStructIn{

#ifndef TEMPLATE_STT_TREND_BUFLEN_IN
#define TEMPLATE_STT_TREND_BUFLEN_IN		300
#endif

	struct TemplateSttTrendStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSettLatnID[TEMPLATE_STT_TREND_BUFLEN_IN][2];
	int     aiReportItemID[TEMPLATE_STT_TREND_BUFLEN_IN];
	char    asSettDate[TEMPLATE_STT_TREND_BUFLEN_IN][15];
	int     aiCnt[TEMPLATE_STT_TREND_BUFLEN_IN];
	char    asDuration[TEMPLATE_STT_TREND_BUFLEN_IN][13];
	char    asSettDuration[TEMPLATE_STT_TREND_BUFLEN_IN][13];
	char    asInFee[TEMPLATE_STT_TREND_BUFLEN_IN][13];
	char    asOutFee[TEMPLATE_STT_TREND_BUFLEN_IN][13];
	char    asMyNbrType[TEMPLATE_STT_TREND_BUFLEN_IN][2];
	char    asMy3gFlag[TEMPLATE_STT_TREND_BUFLEN_IN][2];
	char    asOppCarrID[TEMPLATE_STT_TREND_BUFLEN_IN][2];
	char    asOpp3gFlag[TEMPLATE_STT_TREND_BUFLEN_IN][2];
	char    asServFlag[TEMPLATE_STT_TREND_BUFLEN_IN][2];
};


/*单个结构申明*/
struct TemplateSttTrendStruct{

	struct TemplateSttTrendStruct *pNext;
	char    sSettLatnID[2];
	int     iReportItemID;
	char    sSettDate[15];
	int     iCnt;
	char    sDuration[13];
	char    sSettDuration[13];
	char    sInFee[13];
	char    sOutFee[13];
	char    sMyNbrType[2];
	char    sMy3gFlag[2];
	char    sOppCarrID[2];
	char    sOpp3gFlag[2];
	char    sServFlag[2];
	struct TemplateSttTrendStruct *pLoadNext;
};
/*批量数据动态从TEMPLATE_STT_TREND中用结构缓冲方式取数据*/
int EGetTemplateSttTrendToStruct(struct TemplateSttTrendStruct *p,
	struct TemplateSttTrendStructIn *pSource);
/*批量数据结构缓冲写入TEMPLATE_STT_TREND*/
int EInsertStructToTemplateSttTrend(struct TemplateSttTrendStruct *p,
	int iInsertFlag,struct TemplateSttTrendStructOut *pTarget);




/*---------基本部分代码 an_sett_top_500_tw.txt----------*/

/*输出结构缓冲申明*/
struct AnSettTop500TwStructOut{

#ifndef AN_SETT_TOP_500_TW_BUFLEN_OUT
#define AN_SETT_TOP_500_TW_BUFLEN_OUT		300
#endif

	struct AnSettTop500TwStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asSettLatnID[AN_SETT_TOP_500_TW_BUFLEN_OUT][2];
	char    asCallType[AN_SETT_TOP_500_TW_BUFLEN_OUT][2];
	char    asOppAreaCode[AN_SETT_TOP_500_TW_BUFLEN_OUT][6];
	char    asOtherParty[AN_SETT_TOP_500_TW_BUFLEN_OUT][16];
	char    asSettDate[AN_SETT_TOP_500_TW_BUFLEN_OUT][15];
	int     aiCnt[AN_SETT_TOP_500_TW_BUFLEN_OUT];
	int     aiDuration[AN_SETT_TOP_500_TW_BUFLEN_OUT];
	int     aiSettDuration[AN_SETT_TOP_500_TW_BUFLEN_OUT];
	int     aiSettFee[AN_SETT_TOP_500_TW_BUFLEN_OUT];
	char    asOppNbrType[AN_SETT_TOP_500_TW_BUFLEN_OUT][2];
	char    asMy3gFlag[AN_SETT_TOP_500_TW_BUFLEN_OUT][2];
	char    asOpp3gFlag[AN_SETT_TOP_500_TW_BUFLEN_OUT][2];
	char    asMyCarrID[AN_SETT_TOP_500_TW_BUFLEN_OUT][2];
	char    asOppCarrID[AN_SETT_TOP_500_TW_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct AnSettTop500TwStructIn{

#ifndef AN_SETT_TOP_500_TW_BUFLEN_IN
#define AN_SETT_TOP_500_TW_BUFLEN_IN		300
#endif

	struct AnSettTop500TwStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSettLatnID[AN_SETT_TOP_500_TW_BUFLEN_IN][2];
	char    asCallType[AN_SETT_TOP_500_TW_BUFLEN_IN][2];
	char    asOppAreaCode[AN_SETT_TOP_500_TW_BUFLEN_IN][6];
	char    asOtherParty[AN_SETT_TOP_500_TW_BUFLEN_IN][16];
	char    asSettDate[AN_SETT_TOP_500_TW_BUFLEN_IN][15];
	int     aiCnt[AN_SETT_TOP_500_TW_BUFLEN_IN];
	int     aiDuration[AN_SETT_TOP_500_TW_BUFLEN_IN];
	int     aiSettDuration[AN_SETT_TOP_500_TW_BUFLEN_IN];
	int     aiSettFee[AN_SETT_TOP_500_TW_BUFLEN_IN];
	char    asOppNbrType[AN_SETT_TOP_500_TW_BUFLEN_IN][2];
	char    asMy3gFlag[AN_SETT_TOP_500_TW_BUFLEN_IN][2];
	char    asOpp3gFlag[AN_SETT_TOP_500_TW_BUFLEN_IN][2];
	char    asMyCarrID[AN_SETT_TOP_500_TW_BUFLEN_IN][2];
	char    asOppCarrID[AN_SETT_TOP_500_TW_BUFLEN_IN][2];
};


/*单个结构申明*/
struct AnSettTop500TwStruct{

	struct AnSettTop500TwStruct *pNext;
	char    sSettLatnID[2];
	char    sCallType[2];
	char    sOppAreaCode[6];
	char    sOtherParty[16];
	char    sSettDate[15];
	int     iCnt;
	int     iDuration;
	int     iSettDuration;
	int     iSettFee;
	char    sOppNbrType[2];
	char    sMy3gFlag[2];
	char    sOpp3gFlag[2];
	char    sMyCarrID[2];
	char    sOppCarrID[2];
	struct AnSettTop500TwStruct *pLoadNext;
};

/*批量数据动态从AN_SETT_TOP_500_TW中用结构缓冲方式取数据*/
int EGetAnSettTop500TwToStruct(struct AnSettTop500TwStruct *p,
	struct AnSettTop500TwStructIn *pSource);
/*批量数据结构缓冲写入AN_SETT_TOP_500_TW*/
int EInsertStructToAnSettTop500Tw(struct AnSettTop500TwStruct *p,
	int iInsertFlag,struct AnSettTop500TwStructOut *pTarget);

/*---------基本部分代码 an_sett_top_500_lt.txt----------*/

/*输出结构缓冲申明*/
struct AnSettTop500LtStructOut{

#ifndef AN_SETT_TOP_500_LT_BUFLEN_OUT
#define AN_SETT_TOP_500_LT_BUFLEN_OUT		300
#endif

	struct AnSettTop500LtStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asSettLatnID[AN_SETT_TOP_500_LT_BUFLEN_OUT][2];
	char    asCallType[AN_SETT_TOP_500_LT_BUFLEN_OUT][2];
	char    asHomeAreaCode[AN_SETT_TOP_500_LT_BUFLEN_OUT][6];
	char    asMsisdn[AN_SETT_TOP_500_LT_BUFLEN_OUT][16];
	char    asSettDate[AN_SETT_TOP_500_LT_BUFLEN_OUT][15];
	int     aiCnt[AN_SETT_TOP_500_LT_BUFLEN_OUT];
	int     aiDuration[AN_SETT_TOP_500_LT_BUFLEN_OUT];
	int     aiSettDuration[AN_SETT_TOP_500_LT_BUFLEN_OUT];
	int     aiSettFee[AN_SETT_TOP_500_LT_BUFLEN_OUT];
	char    asMyNbrType[AN_SETT_TOP_500_LT_BUFLEN_OUT][2];
	char    asMy3gFlag[AN_SETT_TOP_500_LT_BUFLEN_OUT][2];
	char    asMyCarrID[AN_SETT_TOP_500_LT_BUFLEN_OUT][2];
	char    asServFlag[AN_SETT_TOP_500_LT_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct AnSettTop500LtStructIn{

#ifndef AN_SETT_TOP_500_LT_BUFLEN_IN
#define AN_SETT_TOP_500_LT_BUFLEN_IN		300
#endif

	struct AnSettTop500LtStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asSettLatnID[AN_SETT_TOP_500_LT_BUFLEN_IN][2];
	char    asCallType[AN_SETT_TOP_500_LT_BUFLEN_IN][2];
	char    asHomeAreaCode[AN_SETT_TOP_500_LT_BUFLEN_IN][6];
	char    asMsisdn[AN_SETT_TOP_500_LT_BUFLEN_IN][16];
	char    asSettDate[AN_SETT_TOP_500_LT_BUFLEN_IN][15];
	int     aiCnt[AN_SETT_TOP_500_LT_BUFLEN_IN];
	int     aiDuration[AN_SETT_TOP_500_LT_BUFLEN_IN];
	int     aiSettDuration[AN_SETT_TOP_500_LT_BUFLEN_IN];
	int     aiSettFee[AN_SETT_TOP_500_LT_BUFLEN_IN];
	char    asMyNbrType[AN_SETT_TOP_500_LT_BUFLEN_IN][2];
	char    asMy3gFlag[AN_SETT_TOP_500_LT_BUFLEN_IN][2];
	char    asMyCarrID[AN_SETT_TOP_500_LT_BUFLEN_IN][2];
	char    asServFlag[AN_SETT_TOP_500_LT_BUFLEN_IN][2];
};


/*单个结构申明*/
struct AnSettTop500LtStruct{

	struct AnSettTop500LtStruct *pNext;
	char    sSettLatnID[2];
	char    sCallType[2];
	char    sHomeAreaCode[6];
	char    sMsisdn[16];
	char    sSettDate[15];
	int     iCnt;
	int     iDuration;
	int     iSettDuration;
	int     iSettFee;
	char    sMyNbrType[2];
	char    sMy3gFlag[2];
	char    sMyCarrID[2];
	char    sServFlag[2];
	struct AnSettTop500LtStruct *pLoadNext;
};
/*批量数据动态从AN_SETT_TOP_500_LT中用结构缓冲方式取数据*/
int EGetAnSettTop500LtToStruct(struct AnSettTop500LtStruct *p,
	struct AnSettTop500LtStructIn *pSource);
/*批量数据结构缓冲写入AN_SETT_TOP_500_LT*/
int EInsertStructToAnSettTop500Lt(struct AnSettTop500LtStruct *p,
	int iInsertFlag,struct AnSettTop500LtStructOut *pTarget);

/*参数部分*/

/*输出结构缓冲申明*/
struct TStReportGroupMemberStructOut{

#ifndef T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT
#define T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT		300
#endif

	struct TStReportGroupMemberStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiProvinceID[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT];
	int     aiGroupID[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT];
	char    asMemberType[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT][21];
	char    asMemberValue[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT][21];
	int     aiMemberOrder[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT];
	int     aiReportSeq[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT];
	char    asRateDesc[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT][257];
	char    asSettleDesc[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT][257];
	char    asMemberName[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT][201];
	char    asNetType[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT][3];
	char    asOppCarrierID[T_ST_REPORT_GROUP_MEMBER_BUFLEN_OUT][5];
};


/* 输入结构缓冲申明*/
struct TStReportGroupMemberStructIn{

#ifndef T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN
#define T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN		300
#endif

	struct TStReportGroupMemberStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiProvinceID[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN];
	int     aiGroupID[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN];
	char    asMemberType[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN][21];
	char    asMemberValue[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN][21];
	int     aiMemberOrder[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN];
	int     aiReportSeq[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN];
	char    asRateDesc[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN][257];
	char    asSettleDesc[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN][257];
	char    asMemberName[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN][201];
	char    asNetType[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN][3];
	char    asOppCarrierID[T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN][5];
};


/*单个结构申明*/
struct TStReportGroupMemberStruct{

	struct TStReportGroupMemberStruct *pNext;
	int     iProvinceID;
	int     iGroupID;
	char    sMemberType[21];
	char    sMemberValue[21];
	int     iMemberOrder;
	int     iReportSeq;
	char    sRateDesc[257];
	char    sSettleDesc[257];
	char    sMemberName[201];
	char    sNetType[3];
	char    sOppCarrierID[5];
	struct TStReportGroupMemberStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTStReportGroupMemberStruct{

	char    sProvinceID[4];
	char    sGroupID[8];
	char    sMemberType[20];
	char    sMemberValue[20];
	char    sMemberOrder[6];
	char    sReportSeq[8];
	char    sRateDesc[256];
	char    sSettleDesc[256];
	char    sMemberName[200];
	char    sNetType[2];
	char    sOppCarrierID[4];
};
/*批量数据动态从T_ST_REPORT_GROUP_MEMBER中用结构缓冲方式取数据*/
int EGetTStReportGroupMemberToStruct(struct TStReportGroupMemberStruct *p,
	struct TStReportGroupMemberStructIn *pSource);
int InitTStReportGroupMember(struct TStReportGroupMemberStruct **pptHead);

/*输出结构缓冲申明*/
struct TicketTypeMapStructOut{

#ifndef TICKET_TYPE_MAP_BUFLEN_OUT
#define TICKET_TYPE_MAP_BUFLEN_OUT		300
#endif

	struct TicketTypeMapStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	int     aiReportItemID[TICKET_TYPE_MAP_BUFLEN_OUT];
	char    asProdID[TICKET_TYPE_MAP_BUFLEN_OUT][11];
	char    asInTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_OUT][2];
	char    asOutTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_OUT][2];
	char    asCallType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    asFlag[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* 费用类型,0是支出, 1是收入 */
	char    asFeeType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
		/* 产品类型,1是本地结算, 0是其他 */
	char    asProdType[TICKET_TYPE_MAP_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct TicketTypeMapStructIn{

#ifndef TICKET_TYPE_MAP_BUFLEN_IN
#define TICKET_TYPE_MAP_BUFLEN_IN		300
#endif

	struct TicketTypeMapStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiReportItemID[TICKET_TYPE_MAP_BUFLEN_IN];
	char    asProdID[TICKET_TYPE_MAP_BUFLEN_IN][11];
	char    asInTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_IN][2];
	char    asOutTrunkCarrID[TICKET_TYPE_MAP_BUFLEN_IN][2];
	char    asCallType[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    asFlag[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* 费用类型,0是支出, 1是收入 */
	char    asFeeType[TICKET_TYPE_MAP_BUFLEN_IN][2];
		/* 产品类型,1是本地结算, 0是其他 */
	char    asProdType[TICKET_TYPE_MAP_BUFLEN_IN][2];
};


/*单个结构申明*/
struct TicketTypeMapStruct{

	struct TicketTypeMapStruct *pNext;
	int     iReportItemID;
	char    sProdID[11];
	char    sInTrunkCarrID[2];
	char    sOutTrunkCarrID[2];
	char    sCallType[2];
	char    sFlag[2];		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    sFeeType[2];		/* 费用类型,0是支出, 1是收入 */
	char    sProdType[2];		/* 产品类型,1是本地结算, 0是其他 */
	struct TicketTypeMapStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTicketTypeMapStruct{

	char    sReportItemID[8];
	char    sProdID[10];
	char    sInTrunkCarrID[1];
	char    sOutTrunkCarrID[1];
	char    sCallType[1];
	char    sFlag[1];		/* 入库标识:1代表IP，2代表近端，3代表转接 */
	char    sFeeType[1];		/* 费用类型,0是支出, 1是收入 */
	char    sProdType[1];		/* 产品类型,1是本地结算, 0是其他 */
};

/*批量数据动态从TICKET_TYPE_MAP中用结构缓冲方式取数据*/
int EGetTicketTypeMapToStruct(struct TicketTypeMapStruct *p,
	struct TicketTypeMapStructIn *pSource);
int InitTicketTypeMap(struct TicketTypeMapStruct **pptHead);

/*输出结构缓冲申明*/
struct NbrTypeFilterCfgStructOut{

#ifndef NBR_TYPE_FILTER_CFG_BUFLEN_OUT
#define NBR_TYPE_FILTER_CFG_BUFLEN_OUT		300
#endif

	struct NbrTypeFilterCfgStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asNbrType[NBR_TYPE_FILTER_CFG_BUFLEN_OUT][2];
	char    asTypeName[NBR_TYPE_FILTER_CFG_BUFLEN_OUT][51];
	char    asRemark[NBR_TYPE_FILTER_CFG_BUFLEN_OUT][401];
	char    asCarrierID[NBR_TYPE_FILTER_CFG_BUFLEN_OUT][2];
};


/* 输入结构缓冲申明*/
struct NbrTypeFilterCfgStructIn{

#ifndef NBR_TYPE_FILTER_CFG_BUFLEN_IN
#define NBR_TYPE_FILTER_CFG_BUFLEN_IN		300
#endif

	struct NbrTypeFilterCfgStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asNbrType[NBR_TYPE_FILTER_CFG_BUFLEN_IN][2];
	char    asTypeName[NBR_TYPE_FILTER_CFG_BUFLEN_IN][51];
	char    asRemark[NBR_TYPE_FILTER_CFG_BUFLEN_IN][401];
	char    asCarrierID[NBR_TYPE_FILTER_CFG_BUFLEN_IN][2];
};


/*单个结构申明*/
struct NbrTypeFilterCfgStruct{

	struct NbrTypeFilterCfgStruct *pNext;
	char    sNbrType[2];
	char    sTypeName[51];
	char    sRemark[401];
	char    sCarrierID[2];
	struct NbrTypeFilterCfgStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FNbrTypeFilterCfgStruct{

	char    sNbrType[1];
	char    sTypeName[50];
	char    sRemark[400];
	char    sCarrierID[1];
};
/*批量数据动态从NBR_TYPE_FILTER_CFG中用结构缓冲方式取数据*/
int EGetNbrTypeFilterCfgToStruct(struct NbrTypeFilterCfgStruct *p,
	struct NbrTypeFilterCfgStructIn *pSource);
int InitNbrTypeFilterCfg(struct NbrTypeFilterCfgStruct **pptHead);



#endif
