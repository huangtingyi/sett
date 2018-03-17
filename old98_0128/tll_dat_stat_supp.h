#ifndef __TLL_DAT_STAT_SUPP_H__
#define __TLL_DAT_STAT_SUPP_H__

#include "toll_voip193_supp.h"

/*输出结构缓冲申明*/
struct SttSjStructOut{

#ifndef STT_SJ_BUFLEN_OUT
#define STT_SJ_BUFLEN_OUT		300
#endif

	struct SttSjStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 主叫号码 */
	char    asCallingNbr[STT_SJ_BUFLEN_OUT][21];
		/* 主叫区号 */
	char    asCallingAreaCode[STT_SJ_BUFLEN_OUT][6];
		/* 主叫用户类型 */
	char    asCallingUserType[STT_SJ_BUFLEN_OUT][2];
		/* 被叫号码 */
	char    asCalledNbr[STT_SJ_BUFLEN_OUT][25];
		/* 被叫区号 */
	char    asVisitAreaCode[STT_SJ_BUFLEN_OUT][6];
		/* 被叫用户类型 */
	char    asCalledUserType[STT_SJ_BUFLEN_OUT][2];
		/* 通话开始时间 */
	char    asStartTime[STT_SJ_BUFLEN_OUT][15];
		/* 通话时长 */
	int     aiDuration[STT_SJ_BUFLEN_OUT];
		/* 长途费 */
	int     aiTollFee[STT_SJ_BUFLEN_OUT];
};


/* 输入结构缓冲申明*/
struct SttSjStructIn{

#ifndef STT_SJ_BUFLEN_IN
#define STT_SJ_BUFLEN_IN		300
#endif

	struct SttSjStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 主叫号码 */
	char    asCallingNbr[STT_SJ_BUFLEN_IN][21];
		/* 主叫区号 */
	char    asCallingAreaCode[STT_SJ_BUFLEN_IN][6];
		/* 主叫用户类型 */
	char    asCallingUserType[STT_SJ_BUFLEN_IN][2];
		/* 被叫号码 */
	char    asCalledNbr[STT_SJ_BUFLEN_IN][25];
		/* 被叫区号 */
	char    asVisitAreaCode[STT_SJ_BUFLEN_IN][6];
		/* 被叫用户类型 */
	char    asCalledUserType[STT_SJ_BUFLEN_IN][2];
		/* 通话开始时间 */
	char    asStartTime[STT_SJ_BUFLEN_IN][15];
		/* 通话时长 */
	int     aiDuration[STT_SJ_BUFLEN_IN];
		/* 长途费 */
	int     aiTollFee[STT_SJ_BUFLEN_IN];
};


/*单个结构申明*/
struct SttSjStruct{

	struct SttSjStruct *pNext;
	char    sCallingNbr[31];		/* 主叫号码 */
	char    sCallingAreaCode[6];		/* 主叫区号 */
	char    sCallingUserType[2];		/* 主叫用户类型 */
	char    sCalledNbr[21];		/* 被叫号码 */
	char    sVisitAreaCode[6];		/* 被叫区号 */
	char    sCalledUserType[2];		/* 被叫用户类型 */
	char    sStartTime[15];		/* 通话开始时间 */
	int     iDuration;		/* 通话时长 */
	int     iTollFee;		/* 长途费 */
	struct SttSjStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSttSjStruct{

	char    sCallingNbr[30];		/* 主叫号码 */
	char    sCallingAreaCode[5];		/* 主叫区号 */
	char    sCallingUserType[1];		/* 主叫用户类型 */
	char    sCalledNbr[20];		/* 被叫号码 */
	char    sVisitAreaCode[5];		/* 被叫区号 */
	char    sCalledUserType[1];		/* 被叫用户类型 */
	char    sStartTime[14];		/* 通话开始时间 */
	char    sDuration[6];		/* 通话时长 */
	char    sTollFee[8];		/* 长途费 */
};

/*批量数据动态从STT_SJ中用结构缓冲方式取数据*/
int EGetSttSjToStruct(struct SttSjStruct *p,
	struct SttSjStructIn *pSource);

static int aiCapitalAreaCode[31]=
{
       10,20,21,22,23,24,25,27,28,29,311,351,
       371,431,451,471,531,551,571,591,731,771,
       791,851,871,891,898,931,951,971,991
};


int EInsertStructToMobCalledStat(struct MobCalledStatStruct *p,
	int iInsertFlag,struct MobCalledStatStructOut *pTarget);	


#endif
