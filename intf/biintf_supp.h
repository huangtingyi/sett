#ifndef __BIINTF_SUPP_H__
#define __BIINTF_SUPP_H__

/* 输入结构缓冲申明*/
struct BiintfSttStructIn{

#ifndef BIINTF_STT_BUFLEN_IN
#define BIINTF_STT_BUFLEN_IN		300
#endif

	struct BiintfSttStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiCounts[BIINTF_STT_BUFLEN_IN];
	int     aiFeeIn[BIINTF_STT_BUFLEN_IN];
	int     aiFeeOut[BIINTF_STT_BUFLEN_IN];
	int     aiFeeDuration[BIINTF_STT_BUFLEN_IN];
	int     aiDuration[BIINTF_STT_BUFLEN_IN];
	char    asNbrAreaCode[BIINTF_STT_BUFLEN_IN][6];
	char    asVisitAreaCode[BIINTF_STT_BUFLEN_IN][6];
	char    asCallingNbr[BIINTF_STT_BUFLEN_IN][25];
	char    asDistanceType[BIINTF_STT_BUFLEN_IN][2];
	char    asRoamType[BIINTF_STT_BUFLEN_IN][2];
	int     aiCalledCarrierID[BIINTF_STT_BUFLEN_IN];
	char    asCallDirection[BIINTF_STT_BUFLEN_IN][2];
	int     aiTicketTypeID[BIINTF_STT_BUFLEN_IN];
};

/*单个结构申明*/
struct BiintfSttStruct{

	struct BiintfSttStruct *pNext;
	int     iCounts;
	int     iFeeIn;
	int     iFeeOut;
	int     iFeeDuration;
	int     iDuration;
	char    sNbrAreaCode[6];
	char    sVisitAreaCode[6];
	char    sCallingNbr[25];
	char    sDistanceType[2];
	char    sRoamType[2];
	int     iCalledCarrierID;
	char    sCallDirection[2];
	int     iTicketTypeID;
	struct BiintfSttStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct BiintfTllStructIn{

#ifndef BIINTF_TLL_BUFLEN_IN
#define BIINTF_TLL_BUFLEN_IN		300
#endif

	struct BiintfTllStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiCounts[BIINTF_TLL_BUFLEN_IN];
	int     aiFeeIn[BIINTF_TLL_BUFLEN_IN];
	int     aiFeeOut[BIINTF_TLL_BUFLEN_IN];
	int     aiFeeDuration[BIINTF_TLL_BUFLEN_IN];
	int     aiDuration[BIINTF_TLL_BUFLEN_IN];
	int     aiRoamFee[BIINTF_TLL_BUFLEN_IN];
	int     aiTollFee[BIINTF_TLL_BUFLEN_IN];
	char    asNbrAreaCode[BIINTF_TLL_BUFLEN_IN][6];
	char    asVisitAreaCode[BIINTF_TLL_BUFLEN_IN][6];
	char    asCallingNbr[BIINTF_TLL_BUFLEN_IN][25];
	char    asDistanceType[BIINTF_TLL_BUFLEN_IN][2];
	char    asRoamType[BIINTF_TLL_BUFLEN_IN][2];
	int     aiOppCarrierID[BIINTF_TLL_BUFLEN_IN];
	char    asCallDirection[BIINTF_TLL_BUFLEN_IN][2];
	int     aiTicketTypeID[BIINTF_TLL_BUFLEN_IN];
};


/*单个结构申明*/
struct BiintfTllStruct{

	struct BiintfTllStruct *pNext;
	int     iCounts;
	int     iFeeIn;
	int     iFeeOut;
	int     iFeeDuration;
	int     iDuration;
	int     iRoamFee;
	int     iTollFee;
	char    sNbrAreaCode[6];
	char    sVisitAreaCode[6];
	char    sCallingNbr[25];
	char    sDistanceType[2];
	char    sRoamType[2];
	int     iOppCarrierID;
	char    sCallDirection[2];
	int     iTicketTypeID;
	struct BiintfTllStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct BiintfSrtStructIn{

#ifndef BIINTF_SRT_BUFLEN_IN
#define BIINTF_SRT_BUFLEN_IN		300
#endif

	struct BiintfSrtStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiCounts[BIINTF_SRT_BUFLEN_IN];
	int     aiFeeIn[BIINTF_SRT_BUFLEN_IN];
	int     aiFeeOut[BIINTF_SRT_BUFLEN_IN];
	int     aiFeeDuration[BIINTF_SRT_BUFLEN_IN];
	int     aiDuration[BIINTF_SRT_BUFLEN_IN];
	int     aiRoamFee[BIINTF_SRT_BUFLEN_IN];
	int     aiTollFee[BIINTF_SRT_BUFLEN_IN];
	char    asVisitAreaCode[BIINTF_SRT_BUFLEN_IN][6];
	char    asCallingNbr[BIINTF_SRT_BUFLEN_IN][16];
	char    asDistanceType[BIINTF_SRT_BUFLEN_IN][2];
	char    asRoamType[BIINTF_SRT_BUFLEN_IN][2];
	int     aiSettCarrierID[BIINTF_SRT_BUFLEN_IN];
	char    asCallDirection[BIINTF_SRT_BUFLEN_IN][2];
	int     aiTicketTypeID[BIINTF_SRT_BUFLEN_IN];
};


/*单个结构申明*/
struct BiintfSrtStruct{

	struct BiintfSrtStruct *pNext;
	int     iCounts;
	int     iFeeIn;
	int     iFeeOut;
	int     iFeeDuration;
	int     iDuration;
	int     iRoamFee;
	int     iTollFee;
	char    sVisitAreaCode[6];
	char    sCallingNbr[16];
	char    sDistanceType[2];
	char    sRoamType[2];
	int     iSettCarrierID;
	char    sCallDirection[2];
	int     iTicketTypeID;
	struct BiintfSrtStruct *pLoadNext;
};


/* 输入结构缓冲申明*/
struct BiintfVitStructIn{

#ifndef BIINTF_VIT_BUFLEN_IN
#define BIINTF_VIT_BUFLEN_IN		300
#endif

	struct BiintfVitStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiCallTimes[BIINTF_VIT_BUFLEN_IN];
	int     aiCounts[BIINTF_VIT_BUFLEN_IN];
	int     aiDuration[BIINTF_VIT_BUFLEN_IN];
	int     aiTollDuration[BIINTF_VIT_BUFLEN_IN];
	int     aiRoamDuration[BIINTF_VIT_BUFLEN_IN];
	char    asVisitAreaCode[BIINTF_VIT_BUFLEN_IN][6];
	char    asCellID[BIINTF_VIT_BUFLEN_IN][21];
	char    asCallType[BIINTF_VIT_BUFLEN_IN][3];
	char    asDistanceType[BIINTF_VIT_BUFLEN_IN][2];
	char    asRoamType[BIINTF_VIT_BUFLEN_IN][2];
	char    asStartDate[BIINTF_VIT_BUFLEN_IN][9];
	char    asTimePeriod[BIINTF_VIT_BUFLEN_IN][5];
	int     aiOppCarrierID[BIINTF_VIT_BUFLEN_IN];
};


/*单个结构申明*/
struct BiintfVitStruct{

	struct BiintfVitStruct *pNext;
	int     iCallTimes;
	int     iCounts;
	int     iDuration;
	int     iTollDuration;
	int     iRoamDuration;
	char    sVisitAreaCode[6];
	char    sCellID[21];
	char    sCallType[3];
	char    sDistanceType[2];
	char    sRoamType[2];
	char    sStartDate[9];
	char    sTimePeriod[5];
	int     iOppCarrierID;
	struct BiintfVitStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct BiintfSpStructIn{

#ifndef BIINTF_SP_BUFLEN_IN
#define BIINTF_SP_BUFLEN_IN		300
#endif

	struct BiintfSpStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	int     aiCounts[BIINTF_SP_BUFLEN_IN];
	int     aiFee[BIINTF_SP_BUFLEN_IN];
	char    asCityCode[BIINTF_SP_BUFLEN_IN][6];
	char    asMsisdn[BIINTF_SP_BUFLEN_IN][16];
	char    asUserType[BIINTF_SP_BUFLEN_IN][2];
	char    asSpAccNbr[BIINTF_SP_BUFLEN_IN][10];
	char    asSpCode[BIINTF_SP_BUFLEN_IN][6];
	int     aiTicketTypeID[BIINTF_SP_BUFLEN_IN];
};


/*单个结构申明*/
struct BiintfSpStruct{

	struct BiintfSpStruct *pNext;
	int     iCounts;
	int     iFee;
	char    sCityCode[6];
	char    sMsisdn[16];
	char    sUserType[2];
	char    sSpAccNbr[10];
	char    sSpCode[6];
	int     iTicketTypeID;
	struct BiintfSpStruct *pLoadNext;
};

/*批量数据动态从BIINTF_STT中用结构缓冲方式取数据*/
int EGetBiintfSttToStruct(struct BiintfSttStruct *p,
	struct BiintfSttStructIn *pSource);
/*批量数据动态从BIINTF_TLL中用结构缓冲方式取数据*/
int EGetBiintfTllToStruct(struct BiintfTllStruct *p,
	struct BiintfTllStructIn *pSource);
/*批量数据动态从BIINTF_SRT中用结构缓冲方式取数据*/
int EGetBiintfSrtToStruct(struct BiintfSrtStruct *p,
	struct BiintfSrtStructIn *pSource);
/*批量数据动态从BIINTF_VIT中用结构缓冲方式取数据*/
int EGetBiintfVitToStruct(struct BiintfVitStruct *p,
	struct BiintfVitStructIn *pSource);
/*批量数据动态从BIINTF_SP中用结构缓冲方式取数据*/
int EGetBiintfSpToStruct(struct BiintfSpStruct *p,
	struct BiintfSpStructIn *pSource);

int EGetBiintfSttToStruct4fj(struct BiintfSttStruct *p,
	struct BiintfSttStructIn *pSource);
int EGetBiintfTllToStruct4fj(struct BiintfTllStruct *p,
	struct BiintfTllStructIn *pSource);

#endif
