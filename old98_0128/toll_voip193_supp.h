#ifndef __TOLLVOIP193_H__
#define __TOLLVOIP193_H__

/*单个文件头记录结构申明*/
struct FileHeadStruct{

	char    sType[3];		/*记录类型*/
	char    sCompanyCode[4];	/*省分公司代码*/
	char    sFileType[4];		/*文件标志*/
	char    sFileSeq[4];		/*文件序列号*/
	char    sFileVersion[3];	/*文件版本号*/
	char    sFileCreateDate[9];	/*文件产生日期*/
	char    sTotalRecord[7];	/*总记录数*/
	char    sTotalFee[16];		/*总话费*/
	char	sSpace[55];		/*空格*/

};
/*Toll文件体记录结构申明*/
struct TollRecordStruct{

	struct TollRecordStruct *pNext;

	char	sInCityCode[5];		/*入联通网城市代码*/
	char	sOutCityCode[5];	/*出联通网城市代码*/
	int	iTollFee1;		/*长途话费(1)*/
	int	iDuration1;		/*长途时长(1)*/
	int	iCnt1;			/*呼叫次数(1)*/
	int	iTollFee2;		/*长途话费(2)*/
	int	iDuration2;		/*长途时长(2)*/
	int	iCnt2;			/*呼叫次数(2)*/
	int	iTollFee3;		/*长途话费(3)*/
	int	iDuration3;		/*长途时长(3)*/
	int	iCnt3;			/*呼叫次数(3)*/
};
/*Voip193文件体记录结构申明*/
struct Voip193RecordStruct{

	struct Voip193RecordStruct *pNext;

	char	sInCityCode[5];		/*入联通网城市代码*/
	char	sOutCityCode[5];	/*出联通网城市代码*/
	int	iTollFee1;		/*长途话费(1)*/
	int	iDuration1;		/*长途时长(1)*/
	int	iCnt1;			/*呼叫次数(1)*/
	int	iTollFee2;		/*长途话费(2)*/
	int	iDuration2;		/*长途时长(2)*/
	int	iCnt2;			/*呼叫次数(2)*/
	int	iTollFee3;		/*长途话费(3)*/
	int	iDuration3;		/*长途时长(3)*/
	int	iCnt3;			/*呼叫次数(3)*/
	int	iTollFee4;		/*长途话费(1)*/
	int	iDuration4;		/*长途时长(1)*/
	int	iCnt4;			/*呼叫次数(1)*/
	int	iTollFee5;		/*长途话费(2)*/
	int	iDuration5;		/*长途时长(2)*/
	int	iCnt5;			/*呼叫次数(2)*/
	int	iTollFee6;		/*长途话费(3)*/
	int	iDuration6;		/*长途时长(3)*/
	int	iCnt6;			/*呼叫次数(3)*/
};

/*输出结构缓冲申明*/
struct MobCalledStatStructOut{

#ifndef MOB_CALLED_STAT_BUFLEN_OUT
#define MOB_CALLED_STAT_BUFLEN_OUT		300
#endif

	struct MobCalledStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 主叫区号 */
	char    asCallingAreaCode[MOB_CALLED_STAT_BUFLEN_OUT][10];
		/* 被叫区号 */
	char    asCalledAreaCode[MOB_CALLED_STAT_BUFLEN_OUT][10];
		/* 主叫类型 */
	char    asCallingType[MOB_CALLED_STAT_BUFLEN_OUT][2];
		/* 被叫类型 */
	char    asCalledType[MOB_CALLED_STAT_BUFLEN_OUT][2];
		/* 长途费 */
	char    asTollFee[MOB_CALLED_STAT_BUFLEN_OUT][13];
		/* 计费时长 */
	char    asTollSec[MOB_CALLED_STAT_BUFLEN_OUT][13];
		/* 话单条数 */
	int     aiCnt[MOB_CALLED_STAT_BUFLEN_OUT];
		/* 结算月份 */
	char    asSettMonth[MOB_CALLED_STAT_BUFLEN_OUT][7];
		/* 处理日期 */
	char    asDealDate[MOB_CALLED_STAT_BUFLEN_OUT][15];
};

/* 输入结构缓冲申明*/
struct MobCalledStatStructIn{

#ifndef MOB_CALLED_STAT_BUFLEN_IN
#define MOB_CALLED_STAT_BUFLEN_IN		300
#endif

	struct MobCalledStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 必须为外省用户 */
	char    asCallingAreaCode[MOB_CALLED_STAT_BUFLEN_IN][10];
		/* 必须为省内用户，按VISIT_AREA_CODE统计 */
	char    asCalledAreaCode[MOB_CALLED_STAT_BUFLEN_IN][10];
		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    asCallingType[MOB_CALLED_STAT_BUFLEN_IN][2];
		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    asCalledType[MOB_CALLED_STAT_BUFLEN_IN][2];
		/* 长途费 */
	char    asTollFee[MOB_CALLED_STAT_BUFLEN_IN][13];
		/* 6秒累计 */
	char    asTollSec[MOB_CALLED_STAT_BUFLEN_IN][13];
		/* 呼叫次数 */
	int     aiCnt[MOB_CALLED_STAT_BUFLEN_IN];
		/* 统计月份 */
	char    asSettMonth[MOB_CALLED_STAT_BUFLEN_IN][7];
		/* 处理时间 */
	char    asDealDate[MOB_CALLED_STAT_BUFLEN_IN][15];
};


/*单个结构申明*/
struct MobCalledStatStruct{

	struct MobCalledStatStruct *pNext;
	char    sCallingAreaCode[10];		/* 必须为外省用户 */
	char    sCalledAreaCode[10];		/* 必须为省内用户，按VISIT_AREA_CODE统计 */
	char    sCallingType[2];		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    sCalledType[2];		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    sTollFee[13];		/* 长途费 */
	char    sTollSec[13];		/* 6秒累计 */
	int     iCnt;		/* 呼叫次数 */
	char    sSettMonth[7];		/* 统计月份 */
	char    sDealDate[15];		/* 处理时间 */
	struct MobCalledStatStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
struct DataCallingStatStructIn{

#ifndef DATA_CALLING_STAT_BUFLEN_IN
#define DATA_CALLING_STAT_BUFLEN_IN		300
#endif

	struct DataCallingStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 必须为外省用户 */
	char    asCallingAreaCode[DATA_CALLING_STAT_BUFLEN_IN][10];
		/* 必须为省内用户，按VISIT_AREA_CODE统计 */
	char    asCalledAreaCode[DATA_CALLING_STAT_BUFLEN_IN][10];
		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    asCallingType[DATA_CALLING_STAT_BUFLEN_IN][2];
		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    asCalledType[DATA_CALLING_STAT_BUFLEN_IN][2];
		/* 'I':VOIP,'1':193 */
	char    asCallingNetType[DATA_CALLING_STAT_BUFLEN_IN][2];
		/* CARD:'省分发行卡类业务',LINE:'语音专线业务' */
	char    asServiceType[DATA_CALLING_STAT_BUFLEN_IN][5];
		/* 长途费 */
	char    asTollFee[DATA_CALLING_STAT_BUFLEN_IN][13];
		/* 6秒累计 */
	char    asTollSec[DATA_CALLING_STAT_BUFLEN_IN][13];
		/* 呼叫次数 */
	int     aiCnt[DATA_CALLING_STAT_BUFLEN_IN];
		/* 统计月份 */
	char    asSettMonth[DATA_CALLING_STAT_BUFLEN_IN][7];
		/* 处理时间 */
	char    asDealDate[DATA_CALLING_STAT_BUFLEN_IN][15];
};


/*单个结构申明*/
struct DataCallingStatStruct{

	struct DataCallingStatStruct *pNext;
	char    sCallingAreaCode[10];		/* 必须为外省用户 */
	char    sCalledAreaCode[10];		/* 必须为省内用户，按VISIT_AREA_CODE统计 */
	char    sCallingType[2];		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    sCalledType[2];		/* 'G':G网络,'C':C网,'X' :外网运营商 */
	char    sCallingNetType[2];		/* 'I':VOIP,'1':193 */
	char    sServiceType[5];		/* CARD:'省分发行卡类业务',LINE:'语音专线业务' */
	char    sTollFee[13];		/* 长途费 */
	char    sTollSec[13];		/* 6秒累计 */
	int     iCnt;		/* 呼叫次数 */
	char    sSettMonth[7];		/* 统计月份 */
	char    sDealDate[15];		/* 处理时间 */
	struct DataCallingStatStruct *pLoadNext;
};

int EGetDataCallingStatToStruct(struct DataCallingStatStruct *p,
	struct DataCallingStatStructIn *pSource);
int EGetMobCalledStatToStruct(struct MobCalledStatStruct *p,
	struct MobCalledStatStructIn *pSource);
void mvitem_voip193recordstruct(struct DataCallingStatStruct *pi,
	struct Voip193RecordStruct *po);
void mvitem_tollrecordstruct(struct MobCalledStatStruct *pi,
	struct TollRecordStruct *po);
int GenCityCode(char sAreaCode[],char sCityCode[]);	
/*Voip193文件体记录结构申明*/
struct DVoip193RecordStruct{

	struct DVoip193RecordStruct *pNext;

	char	sInCityCode[5];		/*入联通网城市代码*/
	char	sOutCityCode[5];	/*出联通网城市代码*/
	int	iTollFee1;		/*长途话费(1)*/
	int	iDuration1;		/*长途时长(1)*/
	int	iCnt1;			/*呼叫次数(1)*/
	int	iTollFee2;		/*长途话费(2)*/
	int	iDuration2;		/*长途时长(2)*/
	int	iCnt2;			/*呼叫次数(2)*/
	int	iTollFee3;		/*长途话费(3)*/
	int	iDuration3;		/*长途时长(3)*/
	int	iCnt3;			/*呼叫次数(3)*/
};

	
#endif
