#ifndef __UP_BAKE_H__
#define __UP_BACK_H__

#include <strings.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

#define TESTING			/*测试使用*/
/*#define XINJIANG		  新疆使用*/
#define	FUJIAN			/*福建使用*/

#define MAXRECNUM	100000
#define PATHLEN		101
#define FILENAMELEN	256
#define TICKETBUFSIZE	540

#define	PATH_UP		1	/*上传总部的漫游文件*/
#define	PATH_REPORT	2	/*上传总部的高额文件*/

#define PATH_GSM	3	/*GSM一批漫游文件*/
#define PATH_CDMA	4	/*CDMA一批漫游文件*/
#define	PATH_RETURN	5	/*回执文件*/

#define	PATH_WORK	6	/*工作时目录*/
#define	PATH_BAK	7	/*备份目录*/
#define PATH_ERR	8	/*一批或回执的错误文件*/
#define	PATH_LOG	9	/*错误日志目录*/

/*错误记录的错误码定义*/
#define ERR_TOO_LATE_REC	-0x01	/*记录迟了30天以上（包括30天）*/
#define ERR_FEE_IS_ZERO		-0x02	/*主被叫记录(非呼转记录)的话费为0*/
#define ERR_DFHM		-0x03	/*C网对方号码有非数字字符，被丢弃*/
#define WARNING_MSID		0x01	/*C网国内漫游的MSID不是以46003打头，置成46003*/
#define WARNING_MSID_LEN	0x02	/*C网国内漫游的MSID只有10位，补充46003*/
#define WARNING_17911		0x03	/*G网漫游的CalledNbr以17911打头,被截*/
#define WARNING_CALLEDNBR	0x04	/*G网漫游的不是17911打头的CalledNbr长度大于15位，取后15位*/

/*全局变量*/
char sLogFile[FILENAMELEN];

/*用于记录首次通话和末次通话*/
struct call_times{
	char First_gn[15];
	char Last_gn[15];
	char First_gj[15];
	char Last_gj[15];
};

/*文件列表结构*/
struct file_list{
	char sFileName[31];
	char sPathOut[PATHLEN];
	struct file_list* pNext;
	
	char sFileOut[31];
	int iSize;
	int iRecCount;
	char sFileDate[15];
};

/*G网国内漫游上传数据的首记录结构*/
typedef struct _buf_up_cri_head_{
	char RecType[2];	/*记录类型*/
	char FilialeCode[3];	/*省分公司代码*/
	char FileSymbol[3];	/*文件标志*/
	char FileSerial[5];	/*文件序列号*/
	char FileVersion[2];	/*文件版本号*/
	char FileDate[8];	/*文件产生日期*/
	char FirstCallDate[8];	/*首次通话日期*/
	char FirstCallTime[6];	/*首次通话时间*/
	char LastCallDate[8];	/*末次通话日期*/
	char LastCallTime[6];	/*末次通话时间*/
	char RecCount[6];	/*通话总记录数*/
	char TotalFee[15];	/*总话费*/
	char Reserved[92];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_cri_head_buf;

/*G网国际漫游上传数据的首记录结构*/
typedef struct _buf_up_cii_head_{
	char RecType[2];	/*记录类型*/
	char FilialeCode[3];	/*省分公司代码*/
	char FileSymbol[3];	/*文件标志*/
	char FileSerial[5];	/*文件序列号*/
	char FileVersion[2];	/*文件版本号*/
	char FileDate[8];	/*文件产生日期*/
	char FirstCallDate[8];	/*首次通话日期*/
	char FirstCallTime[6];	/*首次通话时间*/
	char LastCallDate[8];	/*末次通话日期*/
	char LastCallTime[6];	/*末次通话时间*/
	char RecCount[6];	/*通话总记录数*/
	char TotalFee[15];	/*总话费*/
	char Reserved[77];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_cii_head_buf;

/*G网国内漫游上传数据的主/被叫记录结构*/
typedef struct _buf_up_cri_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char ChangeFlag[1];	/*修改指示*/
	char NumType[1];	/*号码类型*/
	char NumPick[1];	/*选号方案*/
	char CalledNum[15];	/*被叫号码*/
	char ServiceType[1];	/*业务类型*/
	char ServiceCode[2];	/*业务码*/
	char ServiceType2[1];	/*双重业务类型*/
	char ServiceCode2[2];	/*双重业务码*/
	char ChannelReq[1];	/*要求的收音通道*/
	char ChannelUsed[1];	/*使用的收音通道*/
	char ServiceTrans[1];	/*业务透明性*/
				/*附加业务事件*/
	char FunctionCode1[1];	/*活动码1*/
	char AppendCode1[2];	/*附加业务码1*/
	char FunctionCode2[1];	/*活动码2*/
	char AppendCode2[2];	/*附加业务码2*/
	char FunctionCode3[1];	/*活动码3*/
	char AppendCode3[2];	/*附加业务码3*/
	char FunctionCode4[1];	/*活动码4*/
	char AppendCode4[2];	/*附加业务码4*/
	char FunctionCode5[1];	/*活动码5*/
	char AppendCode5[2];	/*附加业务码5*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char DataAmountRef[6];	/*数据量参考*/
	char LandChargeCode[1];	/*长途费代码*/
	char OtherChargeCode[2];/*其他话费代码*/
	char RoamCharge[9];	/*漫游话费*/
	char LandCharge[6];	/*长途话费*/
	char OtherCharge[6];	/*其他话费*/
	char ChargeItem[1];	/*收费的项目*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_cri_buf;

/*G网国内漫游上传数据的主/被叫记录结构*/
typedef struct _buf_up_cri_x_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char ChangeFlag[1];	/*修改指示*/
	char NumType[1];	/*号码类型*/
	char NumPick[1];	/*选号方案*/
	char CalledNum[15];	/*被叫号码*/
	char ServiceType[1];	/*业务类型*/
	char ServiceCode[2];	/*业务码*/
	char ServiceType2[1];	/*双重业务类型*/
	char ServiceCode2[2];	/*双重业务码*/
	char ChannelReq[1];	/*要求的收音通道*/
	char ChannelUsed[1];	/*使用的收音通道*/
	char ServiceTrans[1];	/*业务透明性*/
				/*附加业务事件*/
	char FunctionCode1[1];	/*活动码1*/
	char AppendCode1[2];	/*附加业务码1*/
	char FunctionCode2[1];	/*活动码2*/
	char AppendCode2[2];	/*附加业务码2*/
	char FunctionCode3[1];	/*活动码3*/
	char AppendCode3[2];	/*附加业务码3*/
	char FunctionCode4[1];	/*活动码4*/
	char AppendCode4[2];	/*附加业务码4*/
	char FunctionCode5[1];	/*活动码5*/
	char AppendCode5[2];	/*附加业务码5*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char DataAmountRef[6];	/*数据量参考*/
	char LandChargeCode[1];	/*长途费代码*/
	char OtherChargeCode[2];/*其他话费代码*/
	char RoamCharge[9];	/*漫游话费*/
	char LandCharge[6];	/*长途话费*/
	char OtherCharge[6];	/*其他话费*/
	char ChargeItem[1];	/*收费的项目*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
	char HotBillingTag[1];	/*hot_billing_tag*/
	char Imei[25];		/*imei*/
	char Reserve2[30];	/*reserve2*/
}up_cri_buf_x;
/*G网国内漫游上传数据的呼转记录结构*/
typedef struct _buf_up_cri_hz_x_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char NumB[15];		/*B号码*/
	char CalledNum[15];	/*被叫号码*/
	char FunctionCode[1];	/*活动码1*/
	char AppendCode[2];	/*附加业务码1*/
	char Reserved2[9];	/*未用*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char Reserved3[31];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
	char Imei[25];		/*imei*/
	char Reserve3[51];	/*reserve3*/
}up_cri_hz_buf_x;
/*G网国际漫游上传记录结构*/
typedef struct _buf_up_cii_x_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char ChangeFlag[1];	/*修改指示*/
	char NumType[1];	/*号码类型*/
	char NumPick[1];	/*选号方案*/
	char CalledNum[15];	/*被叫号码*/
	char ServiceType[1];	/*业务类型*/
	char ServiceCode[2];	/*业务码*/
	char ServiceType2[1];	/*双重业务类型*/
	char ServiceCode2[2];	/*双重业务码*/
	char ChannelReq[1];	/*要求的收音通道*/
	char ChannelUsed[1];	/*使用的收音通道*/
	char ServiceTrans[1];	/*业务透明性*/
				/*附加业务事件*/
	char FunctionCode1[1];	/*活动码1*/
	char AppendCode1[2];	/*附加业务码1*/
	char FunctionCode2[1];	/*活动码2*/
	char AppendCode2[2];	/*附加业务码2*/
	char FunctionCode3[1];	/*活动码3*/
	char AppendCode3[2];	/*附加业务码3*/
	char FunctionCode4[1];	/*活动码4*/
	char AppendCode4[2];	/*附加业务码4*/
	char FunctionCode5[1];	/*活动码5*/
	char AppendCode5[2];	/*附加业务码5*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char DataAmountRef[6];	/*数据量参考*/
	char Charges[9];	/*话费*/
	char ChargeItem[1];	/*收费的项目*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
	char Vhe[1];		/*vhe*/
	char InterScpFlag[10];	/*inter_scp_flag*/
	char Reserve2[16];	/*reserve2*/
}up_cii_buf_x;

/*G网国内漫游上传数据的呼转记录结构*/
typedef struct _buf_up_cri_hz_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char NumB[15];		/*B号码*/
	char CalledNum[15];	/*被叫号码*/
	char FunctionCode[1];	/*活动码1*/
	char AppendCode[2];	/*附加业务码1*/
	char Reserved2[9];	/*未用*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char Reserved3[31];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_cri_hz_buf;

/*G网国内漫游上传数据的附加业务记录结构*/
typedef struct _buf_up_cri_fj_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char BaseService[15];	/*基本业务码*/
	char AppendCode[2];	/*附加业务码*/
	char FunctionCode[1];	/*活动码*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char Reserved[15];	/*未用*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char TotalCharge[9];	/*话费*/
	char ChargeItem[1];	/*收费的项目*/
	char Reserved2[37];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_cri_fj_buf;

/*G网国际漫游上传数据的附加业务记录结构*/
typedef struct _buf_up_cii_fj_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char BaseService[15];	/*基本业务码*/
	char AppendCode[2];	/*附加业务码*/
	char FunctionCode[1];	/*活动码*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CalledNum[15];	/*未用*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char TotalCharge[9];	/*话费*/
	char ChargeItem[1];	/*收费的项目*/
	char Reserved2[22];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_cii_fj_buf;

/*G网漫游上传数据的增值业务记录结构*/
typedef struct _buf_up_gsm_zz_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char ValueRaiseCode[8];	/*增值业务码*/
	char Duration[6];	/*付费单位*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char TotalCharge[6];	/*话费*/
	char ChargeItem[1];	/*收费的项目*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_gsm_zz_buf;

/*G网国际漫游上传记录结构*/
typedef struct _buf_up_cii_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[15];	/*主叫号码*/
	char ChangeFlag[1];	/*修改指示*/
	char NumType[1];	/*号码类型*/
	char NumPick[1];	/*选号方案*/
	char CalledNum[15];	/*被叫号码*/
	char ServiceType[1];	/*业务类型*/
	char ServiceCode[2];	/*业务码*/
	char ServiceType2[1];	/*双重业务类型*/
	char ServiceCode2[2];	/*双重业务码*/
	char ChannelReq[1];	/*要求的收音通道*/
	char ChannelUsed[1];	/*使用的收音通道*/
	char ServiceTrans[1];	/*业务透明性*/
				/*附加业务事件*/
	char FunctionCode1[1];	/*活动码1*/
	char AppendCode1[2];	/*附加业务码1*/
	char FunctionCode2[1];	/*活动码2*/
	char AppendCode2[2];	/*附加业务码2*/
	char FunctionCode3[1];	/*活动码3*/
	char AppendCode3[2];	/*附加业务码3*/
	char FunctionCode4[1];	/*活动码4*/
	char AppendCode4[2];	/*附加业务码4*/
	char FunctionCode5[1];	/*活动码5*/
	char AppendCode5[2];	/*附加业务码5*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char DataAmountRef[6];	/*数据量参考*/
	char Charges[9];	/*话费*/
	char ChargeItem[1];	/*收费的项目*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_cii_buf;

/*C网漫游上传数据的首记录结构*/
typedef struct _buf_up_cdma_head_{
	char RecType[2];	/*记录类型*/
	char FileDate[6];	/*文件产生日期*/
	char FileSerial[3];	/*文件序列号*/
	char FilialeCode[3];	/*省分代码*/
	char FileType[3];	/*文件类型*/
	char RecVersion[2];	/*记录版本号*/
	char BackFlag;	/*回执标识*/
	char RefuseReasion[2];	/*文件拒绝原因码*/
	char FileComment;	/*文件内容*/
	char BackLine;	/*回车*/
	char NewLine;	/*换行*/
}up_cdma_head_buf;

/*C网国内漫游上传数据的尾记录结构*/
typedef struct _buf_up_jri_end_{
	char RecType[2];	/*记录类型*/
	char FileDate[6];	/*文件产生日期*/
	char FileSerial[3];	/*文件序列号*/
	char FilialeCode[3];	/*省分代码*/
	char FileType[3];	/*文件类型*/
	char RecCount[5];	/*总记录数*/
	char TotalCharge[12];	/*税后总话费*/
	char RecCount2[5];	/*上传总记录数*/
	char TotalCharge2[12];	/*上传税后总话费*/
	char BackLine;	/*回车*/
	char NewLine;	/*换行*/
}up_jri_end_buf;

/*C网国际漫游上传数据的尾记录结构*/
typedef struct _buf_up_jii_end_{
	char RecType[2];	/*记录类型*/
	char FileDate[6];	/*文件产生日期*/
	char FileSerial[3];	/*文件序列号*/
	char FilialeCode[3];	/*省分代码*/
	char FileType[3];	/*文件类型*/
	char RecCount[4];	/*总记录数*/
	char TotalCharge[12];	/*税后总话费*/
	char RecCount2[4];	/*上传总记录数*/
	char TotalCharge2[12];	/*上传税后总话费*/
	char BackLine;	/*回车*/
	char NewLine;	/*换行*/
}up_jii_end_buf;

/*C网国内漫游上传数据的记录结构*/
typedef struct _buf_up_jri_{
	char RecType[2];	/*记录类型*/
	char RetCode;	/*返回码*/
	char ErrCode[2];	/*记录错误原因码*/
	char ErrField[3];	/*错误字段标识*/
	char MSIDFlag;	/*MSID标识*/
	char MSID[15];		/*MSID*/
	char MSSISDN_MDNLen[2];	/*MSISDN/MDN长度*/
	char MSSISDN_MDN[15];	/*MSISDN/MDN*/
	char ESN_IMEIFlag;	/*ESN/IMEI 标识*/
	char ESN_IMEI[19];	/*ESN/IMEI*/
	char CityCode[3];	/*城市代码*/
	char TotalCharge[10];	/*税后总话费*/
	char Reserved1;	/*系统保留*/
	char TotalTaxP[10];	/*总省税金*/
	char Reserved2;	/*系统保留*/
	char TotalTaxL[10];	/*总地方税金*/
	char Reserved3;	/*系统保留*/
	char CallDate[6];	/*通话日期*/
	char CallDirect;	/*呼叫方向*/
	char CallFinishFlag;	/*呼叫完成标识*/
	char CallStopFlag;	/*呼叫终止标识*/
	char OppNumLen[2];	/*对方号码长度*/
	char OppNum[25];	/*对方号码*/
	char TempNumLen[2];	/*临时号码长度*/
	char TempNum[15];	/*临时号码*/
	char Reserved4[2];	/*系统保留*/
	char CellOri_A[11];	/*蜂窝标识*/
	char MAD[10];		/*MAD*/
	char RoamLinkTime[6];	/*漫游连接时间*/
	char RoamFeeTime[6];	/*漫游计费时长*/
	char RoamCallTime[6];	/*漫游通话时长*/
	char RoamFeePeriod[2];	/*漫游费率起始时段*/
	char RoamFeeMPeriod;	/*漫游多费率时段标识*/
	char RoamCharge[10];	/*漫游费*/
	char Reserved5;	/*系统保留*/
	char OtherChargeFlag[2];/*其他费用标识*/
	char OtherCharge[10];	/*其他费用*/
	char Reserved6;	/*系统保留*/
	char Reserved7[13];	/*系统保留*/
	char SpecService[5];	/*特殊服务使用*/
	char OppCity[10];	/*对方所在地*/
	char OppProvince[3];	/*对方所在省*/
	char OppNation[3];	/*对方所在国*/
	char LDLinkTime[6];	/*长途连接时间*/
	char LDFeeTime[6];	/*长途计费时长*/
	char LDCallTime[6];	/*长途通话时长*/
	char LDFeeDescribe[2];	/*长途资费描述*/
	char LDFeePeriod[2];	/*长途费率起始时段*/
	char LandMoreFlag;	/*长途多费率标识*/
	char LandCharge[10];	/*长途费*/
	char Reserved8;	/*系统保留*/
	char LandTaxP[10];	/*长途省税金*/
	char Reserved9;	/*系统保留*/
	char LandTaxL[10];	/*长途本地税*/
	char Reserved10;	/*系统保留*/
	char NetProviderSign[5];/*长途网络提供运营商标识*/
	char BackLine;	/*回车*/
	char NewLine;	/*换行*/
}up_jri_buf;

/*C网国际漫游上传数据的记录结构*/
typedef struct _buf_up_jii_{
	char RecType[2];	/*记录类型*/
	char RetCode;		/*返回码*/
	char ErrCode[2];	/*记录错误原因码*/
	char ErrField[3];	/*错误字段标识*/
	char MSIDFlag;		/*MSID标识*/
	char MSID[15];		/*MSID*/
	char MSSISDN_MDNLen[2];	/*MSISDN/MDN长度*/
	char MSSISDN_MDN[15];	/*MSISDN/MDN*/
	char ESN_IMEIFlag;	/*ESN/IMEI 标识*/
	char ESN_IMEI[19];	/*ESN/IMEI*/
	char SID_BID[5];	/*城市代码或漫游运营商SID/BID*/
	char TotalCharge[10];	/*税后总话费*/
	char Reserved1;		/*系统保留*/
	char TotalTaxP[10];	/*总省税金*/
	char Reserved2;	/*系统保留*/
	char TotalTaxL[10];	/*总地方税金*/
	char Reserved3;	/*系统保留*/
	char CallDate[6];	/*通话日期*/
	char CallDirect;	/*呼叫方向*/
	char CallFinishFlag;	/*呼叫完成标识*/
	char CallStopFlag;	/*呼叫终止标识*/
	char OppNumLen[2];	/*对方号码长度*/
	char OppNum[25];	/*对方号码*/
	char TempNumLen[2];	/*临时号码长度*/
	char TempNum[15];	/*临时号码*/
	char Reserved4[2];	/*系统保留*/
	char CellOri_A[11];	/*蜂窝标识*/
	char TimeZoneFlag[2];	/*时区标识*/
	char DSTFlag;	/*夏令时（daylight saving time）标识*/
	char MAD[10];		/*MAD*/
	char RoamLinkTime[6];	/*漫游连接时间*/
	char RoamFeeTime[6];	/*漫游计费时长*/
	char RoamCallTime[6];	/*漫游通话时长*/
	char RoamFeePeriod[2];	/*漫游费率起始时段*/
	char RoamFeeMPeriod;	/*漫游多费率时段标识*/
	char RoamCharge[10];	/*漫游费*/
	char Reserved5;	/*系统保留*/
	char OtherChargeFlag[2];/*其他费用标识*/
	char OtherCharge[10];	/*其他费用*/
	char Reserved6;	/*系统保留*/
	char Reserved7[13];	/*系统保留*/
	char NumTextDes[15];	/*号码文字描述*/
	char SpecService[5];	/*特殊服务使用*/
	char OppCity[10];	/*对方所在地*/
	char OppProvince[3];	/*对方所在省*/
	char OppNation[3];	/*对方所在国*/
	char LDLinkTime[6];	/*长途连接时间*/
	char LDFeeTime[6];	/*长途计费时长*/
	char LDCallTime[6];	/*长途通话时长*/
	char LDFeeDescribe[2];	/*长途资费描述*/
	char LDFeePeriod[2];	/*长途费率起始时段*/
	char LandMoreFlag;	/*长途多费率标识*/
	char LandCharge[10];	/*长途费*/
	char Reserved8;	/*系统保留*/
	char LandTaxP[10];	/*长途州/省税*/
	char Reserved9;	/*系统保留*/
	char LandTaxL[10];	/*长途本地或其他税*/
	char BackLine;	/*回车*/
	char NewLine;	/*换行*/
}up_jii_buf;

/*高额上传数据的首记录结构（G网国内）*/
typedef struct _buf_up_cfi_head_{
	char RecType[2];	/*记录类型*/    
	char FilialeCode[3];	/*省分公司代码*/
	char Verson[2];		/*文件版本号*/  
	char FileTime[14];	/*文件产生时间*/
	char RecCount[6];	/*总记录数*/    
	char TotalFee[15];	/*总话费*/      
	char Reserved[14];	/*未用*/        
	char BackLine;		/*回车*/        
	char NewLine;		/*换行*/        
}up_cfi_head_buf;

/*高额上传数据的记录结构（G网国内）*/
typedef struct _buf_up_cfi_{
	char RecType[2];	/*记录类型*/
	char FilialeCode[3];	/*省分公司代码*/
	char Imsi[15];		/*IMSI*/
	char FirstCallTime[14];	/*首次通话日期*/
	char LastCallTime[14];	/*末次通话日期*/
	char TotalFee[8];	/*通话总金额*/
	char BackLine;		/*回车*/
	char NewLine;		/*换行*/
}up_cfi_buf;

/*一批后的C网首记录格式*/
typedef struct _c_ticket_head_buf_{
	char sRecType[2];	/*记录类型*/
	char sCityCode[3];	/*地市代码*/
	char sFileFlag[4];	/*文件标志*/
	char sSerial[4];	/*文件序列号*/
	char sVersion[2];	/*文件版本号*/
	char sFileDate[8];	/*文件产生日期*/
	char sFirstCallDate[8];	/*首次通话日期*/
	char sFirstCallTime[6];	/*首次通话时间*/
	char sLastCallDate[8];	/*末次通话日期*/
	char sLastCallTime[6];	/*末次通话时间*/
	char sTotalRecCount[6];	/*通话总记录数*/
	char sTotalCharge[15];	/*总话费（厘）*/
	char sRevered[105];	/*未用*/
	char cNewLine;		/*换行*/
}c_ticket_head_buf;

/*一批后的C网记录格式*/
struct FCdmaBillStruct{
	char sCallType[2];	/*呼叫类型,定义改变*/ 
	char sCallingNbr[15];	/*计费号码*/
	char sMinImsi[15];	/*MIN/IMSI号*/
	char sEsn[15];		/*电子序列号*/
	char sCalledNbr[21];	/*对端号码*/
	char sTldn[15];		/*临时本地目录号*/
	char sThirdNbr[21];	/*第三方号码*/
	char sStartTime[14];	/*通话起始时间*/
	char sDuration[6];	/*通话时长*/
	char sSwitchID[10];	/*交换机代码*/
	char sLacA[5];		/*本方初始位置LAC号*/
	char sCellA[5];	/*本方初始位置蜂窝（基站）号*/
	char sLacB[5];		/*对方初始位置LAC号*/
	char sCellB[5];	/*对方初始位置蜂窝（基站）号*/
	char sValueRaise[2];	/*增值业务*/
	char cEndReason;	/*结束原因*/
	char cDeformityFlag;	/*残缺标志*/
	char sBaseCharge[8];	/*基本费用*/
	char sBaseDuration[6];	/*基本计费时长*/
	char cMoreRateFlag;	/*多费率标识*/
	char sLandCharge[8];	/*长途费用*/
	char sLandDuration[6];	/*长途计费时长*/
	char cLandMoreFlag;	/*长途多费率标识*/
	char sInfoCharge[8];	/*信息费用*/
	char sOtherCharge[8];	/*其它费用*/
	char sCalledCity[3];	/*对方所在地*/
	char sCalledProvince[3];/*对方所在省*/
	char sCalledNation[3];	/*对方所在国*/
	char cLandType;		/*长途类型*/
	char cLandNetType;	/*长途网类型*/
	char cRoamType;		/*漫游类型*/
	char sCallingCity[3];	/*通话地*/
	char sUserType[1];
	char sServiceType[3];
	char sServiceCode[4];
};
/*一批后的G网记录格式(新疆)*/
struct XJGsmBillStruct{
	char	sCallType[2];
	char	sCallingNbr[15];
	char	sImsi[15];
	char	sCalledNbr[18];
	char	cFeeItem;
	char	sStartTime[14];
	char	sDuration[6];
	char	sMsc[15];
	char	sLac[5];
	char	sCell_A[5];
	char	sCell_B[5];
	char	sTrunkIn[7];
	char	sTrunkOut[7];
	char	sBelongArea[3];
	char	sCallingArea[3];
	char	sCityIn[3];
	char	sCityOut[3];
	char	cRoamType;
	char	cLandType;
	char	sCallType2[3];
	char	sRoamFee[10];
	char	sLandFee[10];
	char	sAddFee[10];
	char	sOtherFee[10];
	char	sForeignLandFee[10];
	char	sAdditionalFee[10];
	char	sLink[6];
	char	cServiceType;
	char	sServiceCode[2];
	char	sRecType[2];
	char	sBaseCode[15];
	char	cFunctionCode1;
	char	sAppendCode1[2];
	char	cFunctionCode2;
	char	sAppendCode2[2];
	char	cFunctionCode3;
	char	sAppendCode3[2];
	char	cFunctionCode4;
	char	sAppendCode4[2];
	char	cFunctionCode5;
	char	sAppendCode5[2];
	char	sCugId[5];
	char	cIsSameCug;
	char	cModifyFlag;
	char	cNumChoose;
	char	cServiceType2;
	char	sServiceCode2[2];
	char	sNumB[15];
	char	cChannelReq;
	char	cChannelUsed;
	char	cServiceTrans;
	char	sFlowCount[6];
	char	sMsisdn[15];
	char	cCalledNbrType;
	char	cMobileType;
	char	sOtherFeeCode[2];
	char	sValueRaiseCode[8];
	char	cNewLine;
};

/*输出结构缓冲申明*/
struct VisitGsmupCriStructOut{

#ifndef VISIT_GSMUP_CRI_02_BUFLEN_OUT
#define VISIT_GSMUP_CRI_02_BUFLEN_OUT		300
#endif

	struct VisitGsmupCriStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asInCityCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][4];
	char    asOutCityCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][4];
	char	asScpFlagID[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asLinkRef[VISIT_GSMUP_CRI_02_BUFLEN_OUT][6];
	char    asReserve1[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asImsi[VISIT_GSMUP_CRI_02_BUFLEN_OUT][16];
	char    asMsisdn[VISIT_GSMUP_CRI_02_BUFLEN_OUT][26];
	char    asModifyTag[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asNbrType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asNbrPlan[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asOtherParty[VISIT_GSMUP_CRI_02_BUFLEN_OUT][26];
	char    asServiceType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asDupServiceType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asDupServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAckChannel[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asUseChannel[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asTransparentFlag[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asAct1[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode1[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct2[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode2[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct3[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode3[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct4[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode4[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct5[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode5[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asMsc[VISIT_GSMUP_CRI_02_BUFLEN_OUT][16];
	char    asLac[VISIT_GSMUP_CRI_02_BUFLEN_OUT][6];
	char    asCellID[VISIT_GSMUP_CRI_02_BUFLEN_OUT][6];
	char    asServType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asStartDate[VISIT_GSMUP_CRI_02_BUFLEN_OUT][9];
	char    asStartTime[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asPayUnit[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asFlowRef[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asTollCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asOtherCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asRoamFee[VISIT_GSMUP_CRI_02_BUFLEN_OUT][10];
	char    asTollFee[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asOtherFee[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asPayItem[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asSystemType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asRateIndication[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asHotBillingTag[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asImei[VISIT_GSMUP_CRI_02_BUFLEN_OUT][26];
	char    asReserve2[VISIT_GSMUP_CRI_02_BUFLEN_OUT][31];
	char	asSourceID[VISIT_GSMUP_CRI_02_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct VisitGsmupCriStructIn{

#ifndef VISIT_GSMUP_CRI_02_BUFLEN_IN
#define VISIT_GSMUP_CRI_02_BUFLEN_IN		300
#endif

	struct VisitGsmupCriStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asInCityCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][4];
	char    asOutCityCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][4];
	char	asScpFlagID[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asLinkRef[VISIT_GSMUP_CRI_02_BUFLEN_IN][6];
	char    asReserve1[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asImsi[VISIT_GSMUP_CRI_02_BUFLEN_IN][16];
	char    asMsisdn[VISIT_GSMUP_CRI_02_BUFLEN_IN][26];
	char    asModifyTag[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asNbrType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asNbrPlan[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asOtherParty[VISIT_GSMUP_CRI_02_BUFLEN_IN][26];
	char    asServiceType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asDupServiceType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asDupServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAckChannel[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asUseChannel[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asTransparentFlag[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asAct1[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode1[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct2[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode2[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct3[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode3[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct4[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode4[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct5[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode5[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asMsc[VISIT_GSMUP_CRI_02_BUFLEN_IN][16];
	char    asLac[VISIT_GSMUP_CRI_02_BUFLEN_IN][6];
	char    asCellID[VISIT_GSMUP_CRI_02_BUFLEN_IN][6];
	char    asServType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asStartDate[VISIT_GSMUP_CRI_02_BUFLEN_IN][9];
	char    asStartTime[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asPayUnit[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asFlowRef[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asTollCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asOtherCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asRoamFee[VISIT_GSMUP_CRI_02_BUFLEN_IN][10];
	char    asTollFee[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asOtherFee[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asPayItem[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asSystemType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asRateIndication[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asHotBillingTag[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asImei[VISIT_GSMUP_CRI_02_BUFLEN_IN][26];
	char    asReserve2[VISIT_GSMUP_CRI_02_BUFLEN_IN][41];
	char	asSourceID[VISIT_GSMUP_CRI_02_BUFLEN_IN][31];
};


/*单个结构申明*/
struct VisitGsmupCriStruct{

	struct VisitGsmupCriStruct *pNext;
	char    sRecordType[3];
	char    sInCityCode[4];
	char    sOutCityCode[4];
	char	sScpFlagID[2];
	char    sLinkRef[6];
	char    sReserve1[2];
	char    sImsi[16];
	char    sMsisdn[26];
	char    sModifyTag[2];
	char    sNbrType[2];
	char    sNbrPlan[2];
	char    sOtherParty[26];
	char    sServiceType[2];
	char    sServiceCode[3];
	char    sDupServiceType[2];
	char    sDupServiceCode[3];
	char    sAckChannel[2];
	char    sUseChannel[2];
	char    sTransparentFlag[2];
	char    sAct1[2];
	char    sCode1[3];
	char    sAct2[2];
	char    sCode2[3];
	char    sAct3[2];
	char    sCode3[3];
	char    sAct4[2];
	char    sCode4[3];
	char    sAct5[2];
	char    sCode5[3];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sServType[2];
	char    sStartDate[9];
	char    sStartTime[7];
	char    sPayUnit[7];
	char    sFlowRef[7];
	char    sTollCode[2];
	char    sOtherCode[3];
	char    sRoamFee[10];
	char    sTollFee[7];
	char    sOtherFee[7];
	char    sPayItem[2];
	char    sSystemType[2];
	char    sRateIndication[2];
	char    sHotBillingTag[2];
	char    sImei[26];
	char    sReserve2[31];
	char	sSourceID[41];
	struct VisitGsmupCriStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FVisitGsmupCriStruct{

	char    sRecordType[2];
	char    sInCityCode[3];
	char    sOutCityCode[3];
	char    sLinkRef[6];
	char    sReserve1[1];
	char    sImsi[15];
	char    sMsisdn[25];
	char    sModifyTag[1];
	char    sNbrType[1];
	char    sNbrPlan[1];
	char    sOtherParty[25];
	char    sServiceType[1];
	char    sServiceCode[2];
	char    sDupServiceType[1];
	char    sDupServiceCode[2];
	char    sAckChannel[1];
	char    sUseChannel[1];
	char    sTransparentFlag[1];
	char    sAct1[1];
	char    sCode1[2];
	char    sAct2[1];
	char    sCode2[2];
	char    sAct3[1];
	char    sCode3[2];
	char    sAct4[1];
	char    sCode4[2];
	char    sAct5[1];
	char    sCode5[2];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sServType[1];
	char    sStartDate[8];
	char    sStartTime[6];
	char    sPayUnit[6];
	char    sFlowRef[6];
	char    sTollCode[1];
	char    sOtherCode[2];
	char    sRoamFee[9];
	char    sTollFee[6];
	char    sOtherFee[6];
	char    sPayItem[1];
	char    sSystemType[1];
	char    sRateIndication[1];
	char    sHotBillingTag[1];
	char    sImei[25];
	char    sReserve2[30];
	char	sSourceID[40];
};

/*批量数据结构缓冲写入VISIT_GSMUP_CRI_02*/
int EInsertStructToVisitGsmupCri(struct VisitGsmupCriStruct *p,
	int iInsertFlag,struct VisitGsmupCriStructOut *pTarget);

/*输出结构缓冲申明*/
struct VisitGsmupCricfStructOut{

#ifndef VISIT_GSMUP_CRICF_02_BUFLEN_OUT
#define VISIT_GSMUP_CRICF_02_BUFLEN_OUT		300
#endif

	struct VisitGsmupCricfStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][3];
	char    asInCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][4];
	char    asOutCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][4];
	char	asScpFlagID[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asLinkRef[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][6];
	char    asReserve1[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asImsi[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][16];
	char    asThirdParty[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asMsisdn[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asOtherParty[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asServiceType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asServiceCode[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][3];
	char    asReserve2[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][10];
	char    asMsc[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][16];
	char    asLac[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][6];
	char    asCellID[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][6];
	char    asServType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asStartDate[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][9];
	char    asStartTime[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][7];
	char    asPayUnit[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][7];
	char    asSystemType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asRateIndication[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asHotBillingTag[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asImei[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asReserve3[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][52];
	char	asSourceID[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct VisitGsmupCricfStructIn{

#ifndef VISIT_GSMUP_CRICF_02_BUFLEN_IN
#define VISIT_GSMUP_CRICF_02_BUFLEN_IN		300
#endif

	struct VisitGsmupCricfStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][3];
	char    asInCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_IN][4];
	char    asOutCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_IN][4];
	char	asScpFlagID[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asLinkRef[VISIT_GSMUP_CRICF_02_BUFLEN_IN][6];
	char    asReserve1[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asImsi[VISIT_GSMUP_CRICF_02_BUFLEN_IN][16];
	char    asThirdParty[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asMsisdn[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asOtherParty[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asServiceType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asServiceCode[VISIT_GSMUP_CRICF_02_BUFLEN_IN][3];
	char    asReserve2[VISIT_GSMUP_CRICF_02_BUFLEN_IN][10];
	char    asMsc[VISIT_GSMUP_CRICF_02_BUFLEN_IN][16];
	char    asLac[VISIT_GSMUP_CRICF_02_BUFLEN_IN][6];
	char    asCellID[VISIT_GSMUP_CRICF_02_BUFLEN_IN][6];
	char    asServType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asStartDate[VISIT_GSMUP_CRICF_02_BUFLEN_IN][9];
	char    asStartTime[VISIT_GSMUP_CRICF_02_BUFLEN_IN][7];
	char    asPayUnit[VISIT_GSMUP_CRICF_02_BUFLEN_IN][7];
	char    asSystemType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asRateIndication[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asHotBillingTag[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asImei[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asReserve3[VISIT_GSMUP_CRICF_02_BUFLEN_IN][52];
	char	asSourceID[VISIT_GSMUP_CRICF_02_BUFLEN_IN][41];
};


/*单个结构申明*/
struct VisitGsmupCricfStruct{

	struct VisitGsmupCricfStruct *pNext;
	char    sRecordType[3];
	char    sInCityCode[4];
	char    sOutCityCode[4];
	char	sScpFlagID[2];
	char    sLinkRef[6];
	char    sReserve1[2];
	char    sImsi[16];
	char    sThirdParty[26];
	char    sMsisdn[26];
	char    sOtherParty[26];
	char    sServiceType[2];
	char    sServiceCode[3];
	char    sReserve2[10];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sServType[2];
	char    sStartDate[9];
	char    sStartTime[7];
	char    sPayUnit[7];
	char    sSystemType[2];
	char    sRateIndication[2];
	char    sHotBillingTag[2];
	char    sImei[26];
	char    sReserve3[52];
	char	sSourceID[41];
	struct VisitGsmupCricfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FVisitGsmupCricfStruct{

	char    sRecordType[2];
	char    sInCityCode[3];
	char    sOutCityCode[3];
	char    sLinkRef[6];
	char    sReserve1[1];
	char    sImsi[15];
	char    sThirdParty[25];
	char    sMsisdn[25];
	char    sOtherParty[25];
	char    sServiceType[1];
	char    sServiceCode[2];
	char    sReserve2[9];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sServType[1];
	char    sStartDate[8];
	char    sStartTime[6];
	char    sPayUnit[6];
	char    sSystemType[1];
	char    sRateIndication[1];
	char    sHotBillingTag[1];
	char    sImei[25];
	char    sReserve3[51];
	char	sSourceID[40];
};

/*批量数据结构缓冲写入VISIT_GSMUP_CRICF_02*/
int EInsertStructToVisitGsmupCricf(struct VisitGsmupCricfStruct *p,
	int iInsertFlag,struct VisitGsmupCricfStructOut *pTarget);

/*输出结构缓冲申明*/
struct VisitGsmupCiiStructOut{

#ifndef VISIT_GSMUP_CII_02_BUFLEN_OUT
#define VISIT_GSMUP_CII_02_BUFLEN_OUT		300
#endif

	struct VisitGsmupCiiStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asInCityCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][4];
	char    asOutCityCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][4];
	char    asLinkRef[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asReserve1[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asImsi[VISIT_GSMUP_CII_02_BUFLEN_OUT][16];
	char    asMsisdn[VISIT_GSMUP_CII_02_BUFLEN_OUT][26];
	char    asModifyTag[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asNbrType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asNbrPlan[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asOtherParty[VISIT_GSMUP_CII_02_BUFLEN_OUT][26];
	char    asServiceType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asServiceCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asDupServiceType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asDupServiceCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAckChannel[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asUseChannel[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asTransparentFlag[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asAct1[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode1[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct2[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode2[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct3[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode3[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct4[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode4[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct5[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode5[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asMsc[VISIT_GSMUP_CII_02_BUFLEN_OUT][16];
	char    asLac[VISIT_GSMUP_CII_02_BUFLEN_OUT][6];
	char    asCellID[VISIT_GSMUP_CII_02_BUFLEN_OUT][6];
	char    asServType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asStartDate[VISIT_GSMUP_CII_02_BUFLEN_OUT][9];
	char    asStartTime[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asPayUnit[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asFlowRef[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asFee[VISIT_GSMUP_CII_02_BUFLEN_OUT][10];
	char    asPayItem[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asSystemType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asRateIndication[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asHotBillingTag[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asVhe[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asInterScpFlag[VISIT_GSMUP_CII_02_BUFLEN_OUT][11];
	char    asReserve2[VISIT_GSMUP_CII_02_BUFLEN_OUT][17];
	char	asSourceID[VISIT_GSMUP_CII_02_BUFLEN_OUT][41];
};


/* 输入结构缓冲申明*/
struct VisitGsmupCiiStructIn{

#ifndef VISIT_GSMUP_CII_02_BUFLEN_IN
#define VISIT_GSMUP_CII_02_BUFLEN_IN		300
#endif

	struct VisitGsmupCiiStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asInCityCode[VISIT_GSMUP_CII_02_BUFLEN_IN][4];
	char    asOutCityCode[VISIT_GSMUP_CII_02_BUFLEN_IN][4];
	char    asLinkRef[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asReserve1[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asImsi[VISIT_GSMUP_CII_02_BUFLEN_IN][16];
	char    asMsisdn[VISIT_GSMUP_CII_02_BUFLEN_IN][26];
	char    asModifyTag[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asNbrType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asNbrPlan[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asOtherParty[VISIT_GSMUP_CII_02_BUFLEN_IN][26];
	char    asServiceType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asServiceCode[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asDupServiceType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asDupServiceCode[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAckChannel[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asUseChannel[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asTransparentFlag[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asAct1[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode1[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct2[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode2[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct3[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode3[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct4[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode4[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct5[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode5[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asMsc[VISIT_GSMUP_CII_02_BUFLEN_IN][16];
	char    asLac[VISIT_GSMUP_CII_02_BUFLEN_IN][6];
	char    asCellID[VISIT_GSMUP_CII_02_BUFLEN_IN][6];
	char    asServType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asStartDate[VISIT_GSMUP_CII_02_BUFLEN_IN][9];
	char    asStartTime[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asPayUnit[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asFlowRef[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asFee[VISIT_GSMUP_CII_02_BUFLEN_IN][10];
	char    asPayItem[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asSystemType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asRateIndication[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asHotBillingTag[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asVhe[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asInterScpFlag[VISIT_GSMUP_CII_02_BUFLEN_IN][11];
	char    asReserve2[VISIT_GSMUP_CII_02_BUFLEN_IN][17];
	char	asSourceID[VISIT_GSMUP_CII_02_BUFLEN_IN][41];
};


/*单个结构申明*/
struct VisitGsmupCiiStruct{

	struct VisitGsmupCiiStruct *pNext;
	char    sRecordType[3];
	char    sInCityCode[4];
	char    sOutCityCode[4];
	char    sLinkRef[7];
	char    sReserve1[2];
	char    sImsi[16];
	char    sMsisdn[26];
	char    sModifyTag[2];
	char    sNbrType[2];
	char    sNbrPlan[2];
	char    sOtherParty[26];
	char    sServiceType[2];
	char    sServiceCode[3];
	char    sDupServiceType[2];
	char    sDupServiceCode[3];
	char    sAckChannel[2];
	char    sUseChannel[2];
	char    sTransparentFlag[2];
	char    sAct1[2];
	char    sCode1[3];
	char    sAct2[2];
	char    sCode2[3];
	char    sAct3[2];
	char    sCode3[3];
	char    sAct4[2];
	char    sCode4[3];
	char    sAct5[2];
	char    sCode5[3];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sServType[2];
	char    sStartDate[9];
	char    sStartTime[7];
	char    sPayUnit[7];
	char    sFlowRef[7];
	char    sFee[10];
	char    sPayItem[2];
	char    sSystemType[2];
	char    sRateIndication[2];
	char    sHotBillingTag[2];
	char    sVhe[2];
	char    sInterScpFlag[11];
	char    sReserve2[17];
	char	sSourceID[41];
	struct VisitGsmupCiiStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FVisitGsmupCiiStruct{

	char    sRecordType[2];
	char    sInCityCode[3];
	char    sOutCityCode[3];
	char    sLinkRef[6];
	char    sReserve1[1];
	char    sImsi[15];
	char    sMsisdn[25];
	char    sModifyTag[1];
	char    sNbrType[1];
	char    sNbrPlan[1];
	char    sOtherParty[25];
	char    sServiceType[1];
	char    sServiceCode[2];
	char    sDupServiceType[1];
	char    sDupServiceCode[2];
	char    sAckChannel[1];
	char    sUseChannel[1];
	char    sTransparentFlag[1];
	char    sAct1[1];
	char    sCode1[2];
	char    sAct2[1];
	char    sCode2[2];
	char    sAct3[1];
	char    sCode3[2];
	char    sAct4[1];
	char    sCode4[2];
	char    sAct5[1];
	char    sCode5[2];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sServType[1];
	char    sStartDate[8];
	char    sStartTime[6];
	char    sPayUnit[6];
	char    sFlowRef[6];
	char    sFee[9];
	char    sPayItem[1];
	char    sSystemType[1];
	char    sRateIndication[1];
	char    sHotBillingTag[1];
	char    sVhe[1];
	char    sInterScpFlag[10];
	char    sReserve2[16];
	char 	sSourceID[40];
};

/*批量数据结构缓冲写入VISIT_GSMUP_CII_02*/
int EInsertStructToVisitGsmupCii(struct VisitGsmupCiiStruct *p,
	int iInsertFlag,struct VisitGsmupCiiStructOut *pTarget);


#endif

