#ifndef	__TICKET_FIELD_H__
#define __TICKET_FIELD_H__

#include <param_intf.h>
#include <stt_ticket.h>
#include "wwsupp.h"

struct XRateStruct
{
	int iRoamValid;
	int iRoamFee;
	int iTollValid;
	int iTollFee;
	int iAddValid;
	int iAddFee;
};
struct MobTicketStruct{

	struct MobTicketStruct *pNext;

	int     iTicketTypeID;
	char	sCallType[3];
	char    sMsisdn[16];
	char    sCalledCode[6];
	char    sOtherParty[25];
	char    sVisitAreaCode[6];
	int     iRoamFee;
	int     iTollFee;
	int     iAddFee;
	int     iRoamDisct;
	int     iTollDisct;
	int     iAddDisct;
	int     iDuration;
	char    sStartTime[15];
	char    sHomeAreaCode[6];
	char    sOppType[2];
	char    sRoamType[2];
	char    sDistanceType[2];
	char	sOppRoamType[2];
	char    sUserType[2];
	
	int	iSplitRuleID;

	char    sImsi[16];
	char    sCal[2];
	char    sState[2];
	char    sMsrn[16];
	char    sMsc[16];
	char    sLac[6];
	char	sCellID[6];
	char    sOtherLac[6];
	char	sOtherCellID[6];
	char    sTrunkIn[9];
	char    sTrunkOut[9];

	char    sThirdParty[16];

	char	sServiceType[4];
	char	sServiceCode[5];

	char	sOppVisitAreaCode[5];	/*对端漫游地区号*/

	int	iMsisdnLen;		/*用户号码长度话单分离用*/
	int	iOtherPartyLen;		/*对端号码长度话单分离用*/
	time_t	tStartTime;		/*开始时间*/
	char	sRawMsisdn[16];		/*用户号码*/
	char	sRawOtherParty[25];	/*对端号码*/
	char	sSplitType[2];
	char	sCallingNbr[16];
	char	sCalledNbr[25];
	char	sInCityCode[6];
	char	sOutCityCode[6];
	char	sTollType[2];
	char	sEsn[21];
	char	sCallingCity[4];
	char	sCalledCity[4];
	char	sCalledProv[4];
	char	sCalledNation[4];
	char	sAppendService[4];
/*这里将保留字段拆开了*/
	char	sScpFlag[2];
	char	sDeformFlag[2];
	char	sReserve[9];
	struct  XRateStruct x;
	char	sBillMode[4];
	char    sIpType[2];
	char    sTollType1[2];
	char    sTollType2[2];
	char	sHomeTollType2[2];

	char	sReserve1[3];
	char	sRoamTariffType[4];
	char	sTollTariffType[4];
	char	sAddTariffType[4];

	char    sErrCode[5];
	char    sFileName[20];
	char    sModule[4];
	char    sAreaCode[6];

	struct MobTicketStruct *pLoadNext;

};

struct TicketAnalyzeStruct
{
	int	iTrunkInTypeID;
	int	iTrunkInCarrierID;
	char	sTrunkInOppType[2];
	int	iTrunkOutTypeID;
	int	iTrunkOutCarrierID;
	char	sTrunkOutOppType[2];
	int	iCallingTypeID;
	int	iCallingCarrierID;
	int	iCallingAreaID;
	int	iCalledTypeID;
	int	iCalledCarrierID;
	int	iCalledAreaID;
	int	iAAreaID;
	int	iBAreaID;
	char	sTrunkInOppAreaCode[6];
	char	sTrunkOutOppAreaCode[6];
	char	sCallingCountyFlag[2];
	char	sCalledCountyFlag[2];
	char	sSameAreaFlag[2];
};

struct TicketFieldRegStruct
{
	struct TicketFieldRegStruct *pNext;
	char	sGetValueFun[61];
	void	*(*GetTicketField)();
};
struct SplitRuleStruct *GetSplitRuleList(int iTemplateRuleID,char sSplitType[]);
int MatchTicketFieldRule(struct TicketFieldRuleStruct*ptHead);
struct SplitRuleStruct *GetSplitRule(struct SplitRuleStruct *pTemp);

extern struct MobTicketStruct	*pTicketField;
extern struct TicketAnalyzeStruct TicketAnalyze;
#define MAXSPLITRULEID	10000
extern struct TicketFieldRuleStruct *apSplitRule[MAXSPLITRULEID];
extern 	struct	FileControlListStruct *pFileControlList;
#define PSPLITRULE(x)	(apSplitRule[x])
extern char SUFFIX_STR[21];

/*********资费支持部分*************/
#define	DISTANCE_LOCAL_CITY	'1'
#define DISTANCE_LOCAL_PROVINCE	'2'
#define	DISTANCE_PROVINCE	'3'
#define DISTANCE_GAT		'4'
#define DISTANCE_INTER		'5'

#define	ROAM_LOCAL_CITY		'1'
#define ROAM_LOCAL_PROVINCE	'2'
#define	ROAM_VISITING_PROVINCE	'3'
#define ROAM_VISITING_GAT	'4'
#define ROAM_VISITING_INTER	'5'
#define ROAM_VISITED_PROVINCE	'6'
#define ROAM_VISITED_GAT	'7'
#define ROAM_VISITED_INTER	'8'

#define INVALID_MSC		-1
#define INVALID_AREA_CODE	-2
#define INVALID_TELECOM_CARRIER	-3
#define INVALID_T130		-4
#define INVALID_CELL_CODE	-5
#define INVALID_TYPE		-6
#define INVALID_SPLIT_RULE	-7

#define CAL_NORMAL	"0"
#define CAL_ACROSS	"1"
#define CAL_SAME	"2"
#define CAL_ACROSS1	"3"



void GetOppVisitAreaCode(char sMsrn[],char sCalledCode[],
	char sStartTime[],char sOppVisitAreaCode[]);
void GetTicketCal(struct MobTicketStruct *p);
int GetTotalType(struct MobTicketStruct *p);
int AnalyzeTicketBase(struct MobTicketStruct *p,char sVisitAreaCode[],int iFlag);
void AnalyzeTicketExtent(struct MobTicketStruct *p);
int InitialTicketFieldRule(struct TicketFieldRuleStruct *pTemp);

/*基础批价公式支持函数*/
int GetBelongCode(char sMsisdn[],char sStartTime[],char sBelongCode[]);
int GetCityCode(char sAreaCode[],char sCityCode[]);
int GetAreaCode(char sCityCode[],char sAreaCode[]);
int GetTrunkType(char sMsc[],char sTrunk[],char sStartTime[],
	char sDirection[],int *piTrunkTypeID);
int GetTrunkArea(char sMsc[],char sTrunk[],char sStartTime[],
	char sDirection[],char sAreaCode[]);
int GetTrunkCarrier(char sMsc[],char sTrunk[],char sStartTime[],
	char sDirection[],int *piCarrierID);
int GetHeadTypeID(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],int *piTypeID);
int GetHeadType(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],char sType[]);
int GetHeadCarr(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],int *piCarrierID);
int GetHeadArea(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],int *piAreaID);
int GetImsiArea(char sImsi[],char sMscType[],char sStartTime[],char sAreaCode[]);
int GetMscArea(char sMsc[],char sAreaCode[]);
int GetLacCellArea(char sMsc[],char sLac[],char sCellID[],
	char sStartTime[],char sAreaCode[]);
int GetAcrossCal(char sCallType[],char sMsc[],char sLac[],char sCellID[],
	char sHomeAreaCode[],char sStartTime[],char sCal[]);
int GetSameCal(char sCallType[],char sOtherParty[],char sCalledCode[],
	char sVisitAreaCode[],char sOppVisitAreaCode[],char sCal[]);
int GetVisitAreaCode(char sVisitCode[],char sMsc[],
	char sTrunkIn[],char sTrunkOut[],char sLac[],char sCellID[],
	char sStartTime[],int iFlag,char sVisitAreaCode[]);
int GetHomeAreaCode(char sMsisdn[],char sImsi[],char sVisitAreaCode[],
	int iFlag,char sStartTime[],int *piErrCode,char sHomeAreaCode[]);
int SpecialNbr(char sOtherParty[],char sStartTime[]);
int GetCalledAreaCode(char sCallType[],char sCalledNbr[],
	char sVisitAreaCode[],char sStartTime[],int *piErrCode,char sCalledAreaCode[]);
int GetRawNbr(char sAccNbr[],char sAreaCode[],char sStartTime[],char sRawNbr[]);

int GetCountryCode(char sAreaCode[],char sCountryCode[]);
int GetCapitalCode(char sAreaCode[],char sCapitalCode[]);
int GetAreaType(char sAreaCode[],char sType[]);
int GetMscType(char sMsc[],char sMscType[]);

int GetAreaIpType(char sAreaCode[],char sType[]);
int GetAreaTollType1(char sAreaCode[],char sType[]);
int GetAreaTollType2(char sAreaCode[],char sType[]);

int GetBinInt (char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],int *piIntVal);
int GetBinStr (char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],char sStrVal[]);
int GetTrieInt(char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],int *piIntVal);
int GetTrieStr(char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],char sStrVal[]);

void GetAreaCountyFlag(int iAreaID,char sCountyFlag[]);

struct RateTicketStruct
{
	char	sStartTime[15];
	int	iDuration;
	int	iValue1;
	int	iValue2;
	int	iTicketTypeID;
	int	iRoamFee;
	int	iTollFee;
	int	iAddFee;
};
struct RatePositionStruct
{
	int	iStartTimePos;
	int	iDurationPos;
	int	iValue1Pos;
	int	iValue2Pos;
	int	iTicketTypeIDPos;
	int	iRoamFeePos;
	int	iTollFeePos;
	int	iAddFeePos;
};
extern struct RatePositionStruct RatePos;
extern struct RateTicketStruct RateTicket;
/*
RegFunItem("getbelongcode",	i_getbelongcode,	"2",'2','f');
RegFunItem("getcitycode",	i_getcitycode,		"2",'2','f');
RegFunItem("getareacode",	i_getareacode,		"2",'2','f');
RegFunItem("gettrunktype",	i_gettrunktype,		"2222",'1','f');
RegFunItem("gettrunkarea",	i_gettrunkarea,		"2222",'2','f');
RegFunItem("gettrunkcarrier",	i_gettrunkcarrier,	"2222",'1','f');
RegFunItem("gettrunkcarr",	i_gettrunkcarrier,	"2222",'1','f');
RegFunItem("getheadtype",	i_getheadtype,		"222",'1','f');
RegFunItem("getheadcarrier",	i_getheadcarr,		"222",'1','f');
RegFunItem("getheadcarr",	i_getheadcarr,		"222",'1','f');
RegFunItem("getheadarea",	i_getheadarea,		"222",'1','f');
RegFunItem("getimsiarea",	i_getimsiarea,		"2",'2','f');
RegFunItem("getmscarea",	i_getmscarea,		"2",'2','f');
RegFunItem("getlaccellarea",	i_getlaccellarea,	"222",'2','f');
RegFunItem("getacrosscal",	i_getacrosscal,		"22222",'2','f');
RegFunItem("getsamecal",	i_getsamecal,		"22222",'2','f');
RegFunItem("getvisitareacode",	i_getvisitareacode,	"22222221",'2','f');
RegFunItem("gethomeareacode",	i_gethomeareacode,	"2221",'2','f');
RegFunItem("getcalledareacode",	i_getcalledareacode,	"222",'2','f');
RegFunItem("getrawnbr",		i_getrawnbr,		"22",'2','f');
*/
void RegRateExprFun();

#define DEF_INTERNATIONAL_AREA	"09999"
#define DEF_DOMESTIC_AREA	"99900"
#define PRIMARY_CARRIER		3
#define DEF_TRUNK		"XXXX"

#define HEAD_CARR_TYPE_REF	"R"
#define HEAD_CARR_TYPE_ERR	"E"
#define HEAD_CARR_TYPE_CORR	"C"
#define HEAD_CARR_TYPE_SPEC	"S"
#define HEAD_CARR_TYPE_FREE	"F"
#define HEAD_CARR_TYPE_CALL	"X"

void RegModiVar();
int MyReadExprFileToBuf(char sFileName[],int iMaxLen,char sInput[],
	char sMessage[]);
void InitSuffixUse(char sSplitType[]);
int ModifyTicket(char sTemplateStr[],int iFlag,char sModule[],
	char sSplitType[],char sMessage[]);
void ModifyTicketFee(char sTemplateStr[],int iFlag,char sModule[],
	char sSplitType[],struct MobTicketStruct *p);


struct	SplitRuleListStruct
{
	struct  SplitRuleListStruct *pNext;
	int	iTemplateRuleID;
	struct  SplitRuleStruct *pSplitRule;	/*分离规则*/
};
struct FileControlOutStruct
{
	struct FileControlOutStruct *pNext;
	int  iCnt;
	char sSuffix[2];
	struct FileControlStruct *pHead;
};
struct	FileControlListStruct
{
	struct	FileControlListStruct *pNext;		
	int	iTemplateRuleID;
	char	sSplitType[2];				/*分离类型*/
	struct  SplitRuleStruct *pSplitRule;	/*分离规则*/
	struct  SplitRuleListStruct *pSplitRuleList;/*分离规则*/
	int	iCnt;
	struct	FileControlOutStruct	*pHead;	/*输出话单*/
	char	sDealBeginDate[15];
	char	sDealEndDate[15];
};
int SearchFileControlOut(struct FileControlOutStruct *ptHead,char sSuffix[2],
	struct FileControlOutStruct **pptCur);
int Item2OutList(struct FileControlOutStruct **pptHead,char sSplitType[],
	char sRecord[],int l,char sSplitNew[],char sMsg[]);
int Item2OutListX(struct FileControlOutStruct **pptHead,char sStr[],
	char sRecord[],int l,char sSplitNew[],char sMsg[]);
int OutItem2File(struct FileControlOutStruct *pTemp,char sNormalDir[],
	char sRawName[]);
int OutList2File(struct FileControlOutStruct *pList,char sNormalDir[],
	char sRawName[],char sSplitStr[]);
/*将一个FileControlOut加到另外一个FileControlOut链表*/
void AddItem2OutList(struct FileControlOutStruct **pptHead,
	struct FileControlOutStruct *ptHead);
/*将CtlList转换为OutList*/
void CVCtlList2OutList(struct FileControlListStruct *pList,
	struct FileControlOutStruct **pptHead);

#define FIELD_TYPE_DURATION	"0"
#define FIELD_TYPE_FLOW1	"1"
#define FIELD_TYPE_FLOW2	"2"

struct FileControlListStruct *GetFileControlList(
	struct FileControlListStruct *ptHead, char sSplitType[2]);
void AnalyzeTemplateRule(char sTemplateRule[],int aiTemplateRule[]);
int InitFileControlList(char sTemplateRule[],char sSplitStr[],
	struct FileControlListStruct **pptHead);
struct SplitRuleStruct *GetMultiSplitRule(struct FileControlListStruct *ptHead);
int mvitem2commerr(char sErrRec[],int l,int iErrCode,
	char sFileName[],char sModule[],char sAreaCode[],char sRecord[]);
int mvitem2err(char sErrRec[],int l,int iErrCode,char sRecord[]);
int CalMainTicket(struct RateTicketStruct *p);
int CalMainTicketD(struct MobTicketStruct *p);
int CalTariffRef(char sStartTime[],int iValue,char sTariffRef[]);
int CalCommFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID,int iTariffType);
int CalRoamFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID);
int CalTollFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID);
int CalAddFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID);
void DestroyFileControlList(struct FileControlListStruct *ptHead);

int OutSplitList2File(struct FileControlOutStruct *pList,char sNormalDir[],
	char sRawName[],char sSource[],int iWantCtl,
	char sSplit[],int iPos,int iLen,char sSplitStr[]);

struct SplitStruct{
	struct SplitStruct *pNext;
	char sKey[128];
	struct FileControlStruct *pData;
};

int Insert2SplitList(struct SplitStruct **pptHead,
	struct FileControlStruct *pData,char sKey[]);
struct SplitStruct *SearchKeyNode(char sKey[],struct SplitStruct *ptHead);
int WantTransKey(char sKey[]);
void TransKey(char sKey[]);
/*变换链表，这个函数话单会倒序*/
int FileControl2SplitList(struct FileControlStruct *ptHead,
	int iStartPos,int iKeyLen,struct SplitStruct **ppList);
int WriteTicketToFile(struct FileControlListStruct *pList,char sNormalDir[],
	char sBaseName[],char sSource[],int iWantCtl,
	char sSplit[],int iPos,int iLen,char sSplitStr[]);

void AnalyzeUserType(char sUserType[],struct MobTicketStruct *p);
void PreModifyTicket(struct MobTicketStruct *p,int iFlag);

int PrintTicket(struct MobTicketStruct *p,char sSplitType[2],char sRecord[]);
int PrintTicketDel(struct MobTicketStruct *pn,struct RSttTicketStruct *po,
	char sRecord[]);

int IsDpAccNbrX(char sHeadDp[],char sAccNbr[]);

#define IS_MOBILE_GSM(x) 	IsDpAccNbrX("mobilegsm",x)
#define IS_UNICOM_GSM(x) 	IsDpAccNbrX("unicomgsm",x)
#define IS_UNICOM_CDMA(x) 	IsDpAccNbrX("unicomcdma",x)
#define IS_MOBILE_TD(x) 	IsDpAccNbrX("mobiletd",x)
#define IS_UNICOM_WCDMA(x) 	IsDpAccNbrX("unicomwcdma",x)


void RegularAreaCode(char sInput[]);
int NewGetRawNbr(char sAccNbr[],char sAreaCode[],char sStartTime[],char sRawNbr[]);


#endif

