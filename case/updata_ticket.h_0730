#ifndef __UPDATA_TICKET_H__
#define __UPDATA_TICKET_H__

#include <stt_ticket.h>

/*单个结构申明*/
struct CdmaheadStruct{

	struct CdmaheadStruct *pNext;
	char    sRecordType[3];
	char    sCityCode[4];
	char    sFileTag[5];
	char    sFileSeq[5];
	char    sFileVer[3];
	char    sCreatedDate[9];
	char    sFirstCallDate[9];
	char    sFirstCallTime[7];
	char    sEndCallDate[9];
	char    sEndCallTime[7];
	int     iAllRecords;
	char    sAllDurations[16];
	char    sNoused[106];
	char    sBackSpace[2];
	struct CdmaheadStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FCdmaheadStruct{

	char    sRecordType[2];
	char    sCityCode[3];
	char    sFileTag[4];
	char    sFileSeq[4];
	char    sFileVer[2];
	char    sCreatedDate[8];
	char    sFirstCallDate[8];
	char    sFirstCallTime[6];
	char    sEndCallDate[8];
	char    sEndCallTime[6];
	char    sAllRecords[6];
	char    sAllDurations[15];
	char    sNoused[105];
	char    sBackSpace[1];
};


/*单个结构申明*/
struct Cdma1xheadStruct{

	struct Cdma1xheadStruct *pNext;
	char    sRecordType[3];
	char    sFileSeq[5];
	char    sFileVer[3];
	char    sAaaSyscode[4];
	char    sCityCode[4];
	char    sCreatedDate[9];
	char    sFirstCallDate[9];
	char    sFirstCallTime[7];
	char    sEndCallDate[9];
	char    sEndCallTime[7];
	char    sAllRecords[11];
	char    sAllDurations[11];
	char    sNoused[419];
	/*char    sSbackspace1[2];*/
	struct Cdma1xheadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCdma1xheadStruct{

	char    sRecordType[2];
	char    sFileSeq[4];
	char    sFileVer[2];
	char    sAaaSyscode[3];
	char    sCityCode[3];
	char    sCreatedDate[8];
	char    sFirstCallDate[8];
	char    sFirstCallTime[6];
	char    sEndCallDate[8];
	char    sEndCallTime[6];
	char    sAllRecords[10];
	char    sAllDurations[10];
	char    sNoused[418];
	/*char    sSbackspace1[1];*/
};

/************************定义数据结构--总部要求格式文档****************************/
struct CDMA1X_RECD{
	char RecordType[2];
	char SequenceNum[10];
	char MDN[20];
	char MSID[15];
	char ESN[19];
	char IP [15];
	char NAI[64];
	char UserType[1];
	char NAIAreaCode[3];
	char RoamType[1];
	char IPTechType[1];
	char AccountSessionId[8];
	char CorrelationId[8];
	char HaIP[15];
	char PDSNIP[15];
	char PCFIP[15];
	char BSID[12];
	char UZID[10];
	char ServiceOption[2];
	char CompulsoryTunnel[1];
	char EndRelease[1];
	char DataCountTermination[10];
	char DataCountOrigination[10];
	char BadFrameCount[10];
	char StartTime[14];
	char StopTime[14];
	char ActiveTime[10];
	char ActiveCount[10];
	char SDBCountTermination[10];
	char SDBCountOrigination[10];
	char SDBTerminationNum[10];
	char SDBOriginationNum[10];
	char PDSNReceiveNum[10];
	char MIPReceiveNum[10];
	char MIPSendNum[10];
	char IPQos[10];
	char AirLinkQos[10];
	char BaseCharge[8];
	char FluxCharge[8];
	char OtherCharge[8];
	char NoUsed1[10];
	char NoUsed2[10];
	char NoUsed3[10];
};

/*单个结构申明*/
struct CriTicketStruct{

	struct CriTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sInCityCode[4];		/* 入联通网城市代码 */
	char    sOutCityCode[4];		/* 出联通网城市代码 */
	char    sLinkRef[7];		/* 链参考 */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* 用户号码 */
	char    sModifyTag[2];		/* 修改指示 */
	char    sNbrType[2];		/* 号码类型 */
	char    sNbrPlan[2];		/* 选号方案 */
	char    sOtherParty[16];		/* 对端号码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sServiceCode[3];		/* 业务代码 */
	char    sDupServiceType[2];		/* 双重业务类型 */
	char    sDupServiceCode[3];		/* 双重业务码 */
	char    sAckChannel[2];		/* 要求的收音通道 */
	char    sUseChannel[2];		/* 使用的收音通道 */
	char    sTransparentFlag[2];		/* 业务透明性 */
	char    sAct1[2];		/* ACT1 */
	char    sCode1[3];		/* CODE1 */
	char    sAct2[2];		/* ACT2 */
	char    sCode2[3];		/* CODE2 */
	char    sAct3[2];		/* ACT3 */
	char    sCode3[3];		/* CODE3 */
	char    sAct4[2];		/* ACT4 */
	char    sCode4[3];		/* CODE4 */
	char    sAct5[2];		/* ACT5 */
	char    sCode5[3];		/* CODE5 */
	char    sMsc[16];		/* MSC 标识 */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* 移动设备类别码 */
	char    sStartDate[9];		/* 通话日期 */
	char    sStartTime[7];		/* 通话起始时间 */
	char    sPayUnit[7];		/* 付费单位 */
	char    sFlowRef[7];		/* 数据量参考 */
	char    sTollCode[2];		/* 长途费代码 */
	char    sOtherCode[3];		/* 其他话费代码 */
	char    sRoamFee[10];		/* 漫游话费 */
	char    sTollFee[7];		/* 长途话费 */
	char    sOtherFee[7];		/* 其他话费 */
	char    sPayItem[2];		/* 收费的项目 */
	struct CriTicketStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FCriTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sInCityCode[3];		/* 入联通网城市代码 */
	char    sOutCityCode[3];		/* 出联通网城市代码 */
	char    sLinkRef[6];		/* 链参考 */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[15];		/* 用户号码 */
	char    sModifyTag[1];		/* 修改指示 */
	char    sNbrType[1];		/* 号码类型 */
	char    sNbrPlan[1];		/* 选号方案 */
	char    sOtherParty[15];		/* 对端号码 */
	char    sServiceType[1];		/* 业务类型 */
	char    sServiceCode[2];		/* 业务代码 */
	char    sDupServiceType[1];		/* 双重业务类型 */
	char    sDupServiceCode[2];		/* 双重业务码 */
	char    sAckChannel[1];		/* 要求的收音通道 */
	char    sUseChannel[1];		/* 使用的收音通道 */
	char    sTransparentFlag[1];		/* 业务透明性 */
	char    sAct1[1];		/* ACT1 */
	char    sCode1[2];		/* CODE1 */
	char    sAct2[1];		/* ACT2 */
	char    sCode2[2];		/* CODE2 */
	char    sAct3[1];		/* ACT3 */
	char    sCode3[2];		/* CODE3 */
	char    sAct4[1];		/* ACT4 */
	char    sCode4[2];		/* CODE4 */
	char    sAct5[1];		/* ACT5 */
	char    sCode5[2];		/* CODE5 */
	char    sMsc[15];		/* MSC 标识 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* 移动设备类别码 */
	char    sStartDate[8];		/* 通话日期 */
	char    sStartTime[6];		/* 通话起始时间 */
	char    sPayUnit[6];		/* 付费单位 */
	char    sFlowRef[6];		/* 数据量参考 */
	char    sTollCode[1];		/* 长途费代码 */
	char    sOtherCode[2];		/* 其他话费代码 */
	char    sRoamFee[9];		/* 漫游话费 */
	char    sTollFee[6];		/* 长途话费 */
	char    sOtherFee[6];		/* 其他话费 */
	char    sPayItem[1];		/* 收费的项目 */
};

/*单个结构申明*/
struct CiiTicketStruct{

	struct CiiTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sInCityCode[4];		/* 入联通网城市代码 */
	char    sOutCityCode[4];		/* 出联通网城市代码 */
	char    sLinkRef[7];		/* 链参考 */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* 用户号码 */
	char    sModifyTag[2];		/* 修改指示 */
	char    sNbrType[2];		/* 号码类型 */
	char    sNbrPlan[2];		/* 选号方案 */
	char    sOtherParty[16];		/* 对端号码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sServiceCode[3];		/* 业务代码 */
	char    sDupServiceType[2];		/* 双重业务类型 */
	char    sDupServiceCode[3];		/* 双重业务码 */
	char    sAckChannel[2];		/* 要求的收音通道 */
	char    sUseChannel[2];		/* 使用的收音通道 */
	char    sTransparentFlag[2];		/* 业务透明性 */
	char    sAct1[2];		/* ACT1 */
	char    sCode1[3];		/* CODE1 */
	char    sAct2[2];		/* ACT2 */
	char    sCode2[3];		/* CODE2 */
	char    sAct3[2];		/* ACT3 */
	char    sCode3[3];		/* CODE3 */
	char    sAct4[2];		/* ACT4 */
	char    sCode4[3];		/* CODE4 */
	char    sAct5[2];		/* ACT5 */
	char    sCode5[3];		/* CODE5 */
	char    sMsc[16];		/* MSC 标识 */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* 移动设备类别码 */
	char    sStartDate[9];		/* 通话日期 */
	char    sStartTime[7];		/* 通话起始时间 */
	char    sPayUnit[7];		/* 付费单位 */
	char    sFlowRef[7];		/* 数据量参考 */
	char    sFee[10];		/* 总话费 */
	char    sPayItem[2];		/* 收费的项目 */
	struct CiiTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FCiiTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sInCityCode[3];		/* 入联通网城市代码 */
	char    sOutCityCode[3];		/* 出联通网城市代码 */
	char    sLinkRef[6];		/* 链参考 */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[15];		/* 用户号码 */
	char    sModifyTag[1];		/* 修改指示 */
	char    sNbrType[1];		/* 号码类型 */
	char    sNbrPlan[1];		/* 选号方案 */
	char    sOtherParty[15];		/* 对端号码 */
	char    sServiceType[1];		/* 业务类型 */
	char    sServiceCode[2];		/* 业务代码 */
	char    sDupServiceType[1];		/* 双重业务类型 */
	char    sDupServiceCode[2];		/* 双重业务码 */
	char    sAckChannel[1];		/* 要求的收音通道 */
	char    sUseChannel[1];		/* 使用的收音通道 */
	char    sTransparentFlag[1];		/* 业务透明性 */
	char    sAct1[1];		/* ACT1 */
	char    sCode1[2];		/* CODE1 */
	char    sAct2[1];		/* ACT2 */
	char    sCode2[2];		/* CODE2 */
	char    sAct3[1];		/* ACT3 */
	char    sCode3[2];		/* CODE3 */
	char    sAct4[1];		/* ACT4 */
	char    sCode4[2];		/* CODE4 */
	char    sAct5[1];		/* ACT5 */
	char    sCode5[2];		/* CODE5 */
	char    sMsc[15];		/* MSC 标识 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* 移动设备类别码 */
	char    sStartDate[8];		/* 通话日期 */
	char    sStartTime[6];		/* 通话起始时间 */
	char    sPayUnit[6];		/* 付费单位 */
	char    sFlowRef[6];		/* 数据量参考 */
	char    sFee[9];		/* 总话费 */
	char    sPayItem[1];		/* 收费的项目 */
};

/*单个结构申明*/
struct JriTicketStruct{

	struct JriTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sRetCode[2];		/* 返回码 */
	char    sErrCode[3];		/* 记录错误原因码 */
	char    sErrField[4];		/* 错误字段标识 */
	char    sMsidTag[2];		/* MSID标识 */
	char    sMsid[16];		/* MSID */
	char    sMsisdnLen[3];		/* MSISDN长度 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sEsnTag[2];		/* ESN标识 */
	char    sEsn[20];		/* ESN */
	char    sVisitCityCode[4];		/* 城市代码 */
	char    sTotalFee[11];		/* 税后总话费 */
	char    sReserve1[2];		/* 系统保留1 */
	char    sProvTex[11];		/* 总省税金 */
	char    sReserve2[2];		/* 系统保留2 */
	char    sLocalTex[11];		/* 总地方税金 */
	char    sReserve3[2];		/* 系统保留3 */
	char    sStartDate[7];		/* 通话日期 */
	char    sDirection[2];		/* 呼叫方向 */
	char    sEndFlag[2];		/* 呼叫完成标识 */
	char    sStopFlag[2];		/* 呼叫终止标识 */
	char    sOtherPartyLen[3];		/* 对方号码长度 */
	char    sOtherParty[26];		/* 对方号码 */
	char    sMsrnLen[3];		/* 临时号码长度 */
	char    sMsrn[16];		/* 临时号码 */
	char    sReserve4[3];		/* 系统保留4 */
	char    sCellCode[12];		/* 蜂窝标识 */
	char    sMad[11];		/* MAD */
	char    sRoamStartTime[7];		/* 漫游连接时间 */
	char    sRoamBillDuration[7];		/* 漫游计费时长 */
	char    sRoamDuration[7];		/* 漫游通话时长 */
	char    sRoamTimeSpan[3];		/* 漫游费率起始时段 */
	char    sRoamTimeType[2];		/* 漫游多费率时段标识 */
	char    sRoamFee[11];		/* 漫游费 */
	char    sReserve5[2];		/* 系统保留5 */
	char    sOtherFeeTag[3];		/* 其他费用标识 */
	char    sOtherFee[11];		/* 其他费用 */
	char    sReserve6[2];		/* 系统保留6 */
	char    sReserve7[14];		/* 系统保留7 */
	char    sSpecialService[6];		/* 特殊服务使用 */
	char    sOppCityCode[11];		/* 对方所在地 */
	char    sOppProvCode[4];		/* 对方所在省 */
	char    sOppCountryCode[4];		/* 对方所在国 */
	char    sTollStartTime[7];		/* 长途连接时间 */
	char    sTollBillDuration[7];		/* 长途计费时长 */
	char    sTollDuration[7];		/* 长途通话时长 */
	char    sTollFeeDesc[3];		/* 长途资费描述 */
	char    sTollTimeSpan[3];		/* 长途费率起始时段 */
	char    sTollTimeType[2];		/* 长途多费率标识 */
	char    sTollFee[11];		/* 长途费 */
	char    sReserve8[2];		/* 系统保留8 */
	char    sTollProvTex[11];		/* 长途省税金 */
	char    sReserve9[2];		/* 系统保留9 */
	char    sTollLocalTex[11];		/* 长途本地税 */
	char    sReserve10[2];		/* 系统保留10 */
	char    sTollNetOperator[6];		/* 长途网络提供运营商标识 */
	struct JriTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FJriTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sRetCode[1];		/* 返回码 */
	char    sErrCode[2];		/* 记录错误原因码 */
	char    sErrField[3];		/* 错误字段标识 */
	char    sMsidTag[1];		/* MSID标识 */
	char    sMsid[15];		/* MSID */
	char    sMsisdnLen[2];		/* MSISDN长度 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sEsnTag[1];		/* ESN标识 */
	char    sEsn[19];		/* ESN */
	char    sVisitCityCode[3];		/* 城市代码 */
	char    sTotalFee[10];		/* 税后总话费 */
	char    sReserve1[1];		/* 系统保留1 */
	char    sProvTex[10];		/* 总省税金 */
	char    sReserve2[1];		/* 系统保留2 */
	char    sLocalTex[10];		/* 总地方税金 */
	char    sReserve3[1];		/* 系统保留3 */
	char    sStartDate[6];		/* 通话日期 */
	char    sDirection[1];		/* 呼叫方向 */
	char    sEndFlag[1];		/* 呼叫完成标识 */
	char    sStopFlag[1];		/* 呼叫终止标识 */
	char    sOtherPartyLen[2];		/* 对方号码长度 */
	char    sOtherParty[25];		/* 对方号码 */
	char    sMsrnLen[2];		/* 临时号码长度 */
	char    sMsrn[15];		/* 临时号码 */
	char    sReserve4[2];		/* 系统保留4 */
	char    sCellCode[11];		/* 蜂窝标识 */
	char    sMad[10];		/* MAD */
	char    sRoamStartTime[6];		/* 漫游连接时间 */
	char    sRoamBillDuration[6];		/* 漫游计费时长 */
	char    sRoamDuration[6];		/* 漫游通话时长 */
	char    sRoamTimeSpan[2];		/* 漫游费率起始时段 */
	char    sRoamTimeType[1];		/* 漫游多费率时段标识 */
	char    sRoamFee[10];		/* 漫游费 */
	char    sReserve5[1];		/* 系统保留5 */
	char    sOtherFeeTag[2];		/* 其他费用标识 */
	char    sOtherFee[10];		/* 其他费用 */
	char    sReserve6[1];		/* 系统保留6 */
	char    sReserve7[13];		/* 系统保留7 */
	char    sSpecialService[5];		/* 特殊服务使用 */
	char    sOppCityCode[10];		/* 对方所在地 */
	char    sOppProvCode[3];		/* 对方所在省 */
	char    sOppCountryCode[3];		/* 对方所在国 */
	char    sTollStartTime[6];		/* 长途连接时间 */
	char    sTollBillDuration[6];		/* 长途计费时长 */
	char    sTollDuration[6];		/* 长途通话时长 */
	char    sTollFeeDesc[2];		/* 长途资费描述 */
	char    sTollTimeSpan[2];		/* 长途费率起始时段 */
	char    sTollTimeType[1];		/* 长途多费率标识 */
	char    sTollFee[10];		/* 长途费 */
	char    sReserve8[1];		/* 系统保留8 */
	char    sTollProvTex[10];		/* 长途省税金 */
	char    sReserve9[1];		/* 系统保留9 */
	char    sTollLocalTex[10];		/* 长途本地税 */
	char    sReserve10[1];		/* 系统保留10 */
	char    sTollNetOperator[5];		/* 长途网络提供运营商标识 */
};

/*单个结构申明*/
struct JiiTicketStruct{

	struct JiiTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sRetCode[2];		/* 返回码 */
	char    sErrCode[3];		/* 记录错误原因码 */
	char    sErrField[4];		/* 错误字段标识 */
	char    sMsidTag[2];		/* MSID标识 */
	char    sMsid[16];		/* MSID */
	char    sMsisdnLen[3];		/* MSISDN长度 */
	char    sMsisdn[16];		/* 用户号码 */
	char    sEsnTag[2];		/* ESN标识 */
	char    sEsn[20];		/* ESN */
	char    sVisitCityCode[6];		/* 城市代码 */
	char    sTotalFee[11];		/* 税后总话费 */
	char    sReserve1[2];		/* 系统保留1 */
	char    sProvTex[11];		/* 总省税金 */
	char    sReserve2[2];		/* 系统保留2 */
	char    sLocalTex[11];		/* 总地方税金 */
	char    sReserve3[2];		/* 系统保留3 */
	char    sStartDate[7];		/* 通话日期 */
	char    sDirection[2];		/* 呼叫方向 */
	char    sEndFlag[2];		/* 呼叫完成标识 */
	char    sStopFlag[2];		/* 呼叫终止标识 */
	char    sOtherPartyLen[3];		/* 对方号码长度 */
	char    sOtherParty[26];		/* 对方号码 */
	char    sMsrnLen[3];		/* 临时号码长度 */
	char    sMsrn[16];		/* 临时号码 */
	char    sReserve4[3];		/* 系统保留4 */
	char    sCellCode[12];		/* 蜂窝标识 */
	char    sTimeZone[3];		/* 时区标识 */
	char    sSummerTimeTag[2];		/* 夏令时标识 */
	char    sMad[11];		/* MAD */
	char    sRoamStartTime[7];		/* 漫游连接时间 */
	char    sRoamBillDuration[7];		/* 漫游计费时长 */
	char    sRoamDuration[7];		/* 漫游通话时长 */
	char    sRoamTimeSpan[3];		/* 漫游费率起始时段 */
	char    sRoamTimeType[2];		/* 漫游多费率时段标识 */
	char    sRoamFee[11];		/* 漫游费 */
	char    sReserve5[2];		/* 系统保留5 */
	char    sOtherFeeTag[3];		/* 其他费用标识 */
	char    sOtherFee[11];		/* 其他费用 */
	char    sReserve6[2];		/* 系统保留6 */
	char    sReserve7[14];		/* 系统保留7 */
	char    sOppDesc[16];		/* 号码文字描述 */
	char    sSpecialService[6];		/* 特殊服务使用 */
	char    sOppCityCode[11];		/* 对方所在地 */
	char    sOppProvCode[4];		/* 对方所在省 */
	char    sOppCountryCode[4];		/* 对方所在国 */
	char    sTollStartTime[7];		/* 长途连接时间 */
	char    sTollBillDuration[7];		/* 长途计费时长 */
	char    sTollDuration[7];		/* 长途通话时长 */
	char    sTollFeeDesc[3];		/* 长途资费描述 */
	char    sTollTimeSpan[3];		/* 长途费率起始时段 */
	char    sTollTimeType[2];		/* 长途多费率标识 */
	char    sTollFee[11];		/* 长途费 */
	char    sReserve8[2];		/* 系统保留8 */
	char    sTollProvTex[11];		/* 长途省税金 */
	char    sReserve9[2];		/* 系统保留9 */
	char    sTollLocalTex[11];		/* 长途本地税 */
	struct JiiTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FJiiTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sRetCode[1];		/* 返回码 */
	char    sErrCode[2];		/* 记录错误原因码 */
	char    sErrField[3];		/* 错误字段标识 */
	char    sMsidTag[1];		/* MSID标识 */
	char    sMsid[15];		/* MSID */
	char    sMsisdnLen[2];		/* MSISDN长度 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sEsnTag[1];		/* ESN标识 */
	char    sEsn[19];		/* ESN */
	char    sVisitCityCode[5];		/* 城市代码 */
	char    sTotalFee[10];		/* 税后总话费 */
	char    sReserve1[1];		/* 系统保留1 */
	char    sProvTex[10];		/* 总省税金 */
	char    sReserve2[1];		/* 系统保留2 */
	char    sLocalTex[10];		/* 总地方税金 */
	char    sReserve3[1];		/* 系统保留3 */
	char    sStartDate[6];		/* 通话日期 */
	char    sDirection[1];		/* 呼叫方向 */
	char    sEndFlag[1];		/* 呼叫完成标识 */
	char    sStopFlag[1];		/* 呼叫终止标识 */
	char    sOtherPartyLen[2];		/* 对方号码长度 */
	char    sOtherParty[25];		/* 对方号码 */
	char    sMsrnLen[2];		/* 临时号码长度 */
	char    sMsrn[15];		/* 临时号码 */
	char    sReserve4[2];		/* 系统保留4 */
	char    sCellCode[11];		/* 蜂窝标识 */
	char    sTimeZone[2];		/* 时区标识 */
	char    sSummerTimeTag[1];		/* 夏令时标识 */
	char    sMad[10];		/* MAD */
	char    sRoamStartTime[6];		/* 漫游连接时间 */
	char    sRoamBillDuration[6];		/* 漫游计费时长 */
	char    sRoamDuration[6];		/* 漫游通话时长 */
	char    sRoamTimeSpan[2];		/* 漫游费率起始时段 */
	char    sRoamTimeType[1];		/* 漫游多费率时段标识 */
	char    sRoamFee[10];		/* 漫游费 */
	char    sReserve5[1];		/* 系统保留5 */
	char    sOtherFeeTag[2];		/* 其他费用标识 */
	char    sOtherFee[10];		/* 其他费用 */
	char    sReserve6[1];		/* 系统保留6 */
	char    sReserve7[13];		/* 系统保留7 */
	char    sOppDesc[15];		/* 号码文字描述 */
	char    sSpecialService[5];		/* 特殊服务使用 */
	char    sOppCityCode[10];		/* 对方所在地 */
	char    sOppProvCode[3];		/* 对方所在省 */
	char    sOppCountryCode[3];		/* 对方所在国 */
	char    sTollStartTime[6];		/* 长途连接时间 */
	char    sTollBillDuration[6];		/* 长途计费时长 */
	char    sTollDuration[6];		/* 长途通话时长 */
	char    sTollFeeDesc[2];		/* 长途资费描述 */
	char    sTollTimeSpan[2];		/* 长途费率起始时段 */
	char    sTollTimeType[1];		/* 长途多费率标识 */
	char    sTollFee[10];		/* 长途费 */
	char    sReserve8[1];		/* 系统保留8 */
	char    sTollProvTex[10];		/* 长途省税金 */
	char    sReserve9[1];		/* 系统保留9 */
	char    sTollLocalTex[10];		/* 长途本地税 */
};

/*单个结构申明*/
struct TrsTicketStruct{

	struct TrsTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sInCityCode[4];		/* 入联通网城市代码 */
	char    sOutCityCode[4];		/* 出联通网城市代码 */
	char    sLinkRef[7];		/* 链参考 */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sThirdParty[16];		/* 主叫号码A */
	char    sMsisdn[16];		/* 用户号码 */
	char    sOtherParty[16];		/* 对端号码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sServiceCode[3];		/* 业务代码 */
	char    sReserve2[10];		/* 系统保留2 */
	char    sMsc[16];		/* MSC 标识 */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* 移动设备类别码 */
	char    sStartDate[9];		/* 通话日期 */
	char    sStartTime[7];		/* 通话起始时间 */
	char    sPayUnit[7];		/* 付费单位 */
	char    sReserve3[32];		/* 保留3 */
	struct TrsTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FTrsTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sInCityCode[3];		/* 入联通网城市代码 */
	char    sOutCityCode[3];		/* 出联通网城市代码 */
	char    sLinkRef[6];		/* 链参考 */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sThirdParty[15];		/* 主叫号码A */
	char    sMsisdn[15];		/* 用户号码 */
	char    sOtherParty[15];		/* 对端号码 */
	char    sServiceType[1];		/* 业务类型 */
	char    sServiceCode[2];		/* 业务代码 */
	char    sReserve2[9];		/* 系统保留2 */
	char    sMsc[15];		/* MSC 标识 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* 移动设备类别码 */
	char    sStartDate[8];		/* 通话日期 */
	char    sStartTime[6];		/* 通话起始时间 */
	char    sPayUnit[6];		/* 付费单位 */
	char    sReserve3[31];		/* 保留3 */
};

/*单个结构申明*/
struct RhjfHeadStruct{

	struct RhjfHeadStruct *pNext;
	char    sRecordType[3];       /*话单类别*/
	char    sCityCode[6];         /*城市区号代码*/
	char    sFileFlag[5];         /*文件标志 "RHJF" */
	char    sFileSeq[5];          /*文件序列号*/
	char    sFileVersion[3];      /*文件版本号 "00" */
	char    sFileCreatDate[9];    /*文件产生日期*/
	char    sFirstCallDate[9];    /*首次通话日期*/
	char    sFirstCallTime[7];    /*首次通话时间*/
	char    sLastCallDate[9];     /*末次通话日期*/
	char    sLastCallTime[7];     /*末次通话时间*/
	char    sCallSumNbr[7];       /*通话总记录数*/
	char    sCallSumFee[16];      /*总话费*/
	char    sNouse[61];           /*未用*/
	struct RhjfHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FRhjfHeadStruct{

	char    sRecordType[2];
	char    sCityCode[5];
	char    sFileFlag[4];
	char    sFileSeq[4];
	char    sFileVersion[2];
	char    sFileCreatDate[8];
	char    sFirstCallDate[8];
	char    sFirstCallTime[6];
	char    sLastCallDate[8];
	char    sLastCallTime[6];
	char    sCallSumNbr[6];
	char    sCallSumFee[15];
	char    sNouse[60];
};


/*单个结构申明*/
struct RhjfBodyStruct{

	struct RhjfBodyStruct *pNext;
	char    sCallType[3];           /*呼叫类型 "00"*/
	char    sRecordType[3];         /*话单类别*/
	char    sCallingNbr[16];        /*用户号码*/
	char    sCalledNbr[31];         /*对端号码*/
	char    sStartTime[15];         /*通话开始时间*/
	char    sDuration[7];           /*通话时长*/
	char    sSwitchNbr[16];         /*交换机代码*/
	char    sTrunkIn[8];            /*入中继*/
	char    sTrunkOut[8];           /*出中继*/
	char    sBaseFee[9];            /*基本费用*/
	char    sLongFee[9];            /*长途费用*/
	char    sOtherFee[9];           /*其他费用*/
	char    sDistanceType[2];       /*长途类型*/
	char    sCallingAreaCode[6];    /*通话地区号*/
	char    sBelongAreaCode[6];     /*归属地区号*/
	char    sCalledAreaCode[6];     /*对端区号*/
	struct RhjfBodyStruct *pLoadNext;
};

/*单个文件结构申明*/
struct FRhjfBodyStruct{

	char    sCallType[2];
	char    sRecordType[2];
	char    sCallingNbr[15];
	char    sCalledNbr[30];
	char    sStartTime[14];
	char    sDuration[6];
	char    sSwitchNbr[15];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sBaseFee[8];
	char    sLongFee[8];
	char    sOtherFee[8];
	char    sDistanceType[1];
	char    sCallingAreaCode[5];
	char    sBelongAreaCode[5];
	char    sCalledAreaCode[5];
};

/*单个结构申明*/
struct GsmHeadStruct{

	struct GsmHeadStruct *pNext;
	char    sRecordType[3];		/* 记录类型 本地话单01、漫游02 */
	char    sCityCode[4];		/* 地市代码 同联通城市代码 */
	int     iFileSeq;		/* 文件序列号 从00000001开始排序，排满后重置 */
	char    sFileVer[3];		/* 文件版本号 00 */
	char    sCreateDate[9];		/* 文件产生日期 YYYYMMDD */
	int     iRecordCnt;		/* 总记录数 右对齐，左补0。 */
	struct GsmHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FGsmHeadStruct{

	char    sRecordType[2];
	char    sCityCode[3];
	char    sFileSeq[8];
	char    sFileVer[2];
	char    sCreateDate[8];
	char    sRecordCnt[6];
};

/*单个结构申明*/
struct SmsHeadStruct{

	struct SmsHeadStruct *pNext;
	char    sHeadTag[3];		/* 头记录标识	头记录英文缩写标识（HEAD）“HD”      */           
	char    sFileSeq[5];		/* 文件序列号	文件序列号，和文件名中的序列号相同  */             
	char    sFileVer[3];		/* 文件版本号	目前版本号＝“01”。                  */           
	char    sCreateDate[9];		/* 文件产生日期	YYYYMMDD                            */             
	char    sFirstCallDate[15];	/* 第一条记录时间	YYYYMMDDHHMMSS              */             
	char    sLastCallDate[15];	/* 最末条记录时间	YYYYMMDDHHMMSS              */             
	char    sRecordCnt[11];		/* 总记录数	不含首记录。 左对齐，右填空。       */             
	char    sRoamFee[11];		/* 总通信费	本文件包含总通信费                  */             
	char    sInfoFee[11];		/* 总信息费	本文件包含总信息费                  */             
	char    sReserve[57];		/* 保留		补空格以和单条记录的长度相同。      */             
	struct SmsHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSmsHeadStruct{

	char    sHeadTag[2];		
	char    sFileSeq[4];		
	char    sFileVer[2];		
	char    sCreateDate[8];		
	char    sFirstCallDate[14];	
	char    sLastCallDate[14];	
	char    sRecordCnt[10];		
	char    sRoamFee[10];		
	char    sInfoFee[10];		
	char    sReserve[56];		
};

void mvitem_fmcdmahead(struct FCdmaheadStruct *pi,struct CdmaheadStruct *po);
void mvitem_mfcdmahead(struct CdmaheadStruct *pi,struct FCdmaheadStruct *po);
void DestroyCdmahead(struct CdmaheadStruct *ptHead);

void mvitem_fmcdma1xhead(struct FCdma1xheadStruct *pi,struct Cdma1xheadStruct *po);
void mvitem_mfcdma1xhead(struct Cdma1xheadStruct *pi,struct FCdma1xheadStruct *po);
void DestroyCdma1xhead(struct Cdma1xheadStruct *ptHead);

void DestroyCriTicket(struct CriTicketStruct *ptHead);
void mvitem_mfcriticket(struct CriTicketStruct *pi,struct FCriTicketStruct *po);
void mvitem_fmcriticket(struct FCriTicketStruct *pi,struct CriTicketStruct *po);

void DestroyCiiTicket(struct CiiTicketStruct *ptHead);
void mvitem_mfciiticket(struct CiiTicketStruct *pi,struct FCiiTicketStruct *po);
void mvitem_fmciiticket(struct FCiiTicketStruct *pi,struct CiiTicketStruct *po);

void DestroyJriTicket(struct JriTicketStruct *ptHead);
void mvitem_mfjriticket(struct JriTicketStruct *pi,struct FJriTicketStruct *po);
void mvitem_fmjriticket(struct FJriTicketStruct *pi,struct JriTicketStruct *po);

void DestroyJiiTicket(struct JiiTicketStruct *ptHead);
void mvitem_mfjiiticket(struct JiiTicketStruct *pi,struct FJiiTicketStruct *po);
void mvitem_fmjiiticket(struct FJiiTicketStruct *pi,struct JiiTicketStruct *po);

void DestroyTrsTicket(struct TrsTicketStruct *ptHead);
void mvitem_mftrsticket(struct TrsTicketStruct *pi,struct FTrsTicketStruct *po);
void mvitem_fmtrsticket(struct FTrsTicketStruct *pi,struct TrsTicketStruct *po);


void mvitem_mfrhjfbody(struct RhjfBodyStruct *pi,struct FRhjfBodyStruct *po);
void mvitem_fmrhjfbody(struct FRhjfBodyStruct *pi,struct RhjfBodyStruct *po);
void mvitem_mfrhjfhead(struct RhjfHeadStruct *pi,struct FRhjfHeadStruct *po);
void mvitem_fmrhjfhead(struct FRhjfHeadStruct *pi,struct RhjfHeadStruct *po);

void mvitem_mfgsmhead(struct GsmHeadStruct *pi,struct FGsmHeadStruct *po);
void mvitem_fmgsmhead(struct FGsmHeadStruct *pi,struct GsmHeadStruct *po);

void mvitem_mfsmshead(struct SmsHeadStruct *pi,struct FSmsHeadStruct *po);
void mvitem_fmsmshead(struct FSmsHeadStruct *pi,struct SmsHeadStruct *po);

/*单个结构申明*/
struct NxRhjfHeadStruct{

	struct NxRhjfHeadStruct *pNext;
	char    sRecordType[3];		/* 首记录标识 */
	char    sPickID[6];		/* 采集点ID */
	char    sOriFileName[37];		/* 原始话单文件名字 */
	int     iSeqNbr;		/* 文件序列号 */
	char    sVersion[2];		/* 版本号码 */
	char    sCreatedDate[9];		/* 文件产生日期 */
	char    sBeginTime[15];		/* 首次通话时间 */
	char    sEndTime[15];		/* 末次通话时间 */
	int     iTotalCnt;		/* 总记录数 */
	char    sTotalFee[13];		/* 单位：（人民币）分 */
	char    sReserve[117];		/* 保留 */
	struct NxRhjfHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FNxRhjfHeadStruct{

	char    sRecordType[2];		/* 首记录标识 */
	char    sPickID[5];		/* 采集点ID */
	char    sOriFileName[36];		/* 原始话单文件名字 */
	char    sSeqNbr[4];		/* 文件序列号 */
	char    sVersion[1];		/* 版本号码 */
	char    sCreatedDate[8];		/* 文件产生日期 */
	char    sBeginTime[14];		/* 首次通话时间 */
	char    sEndTime[14];		/* 末次通话时间 */
	char    sTotalCnt[8];		/* 总记录数 */
	char    sTotalFee[12];		/* 单位：（人民币）分 */
	char    sReserve[116];		/* 保留 */
};
void mvitem_mfnxrhjfhead(struct NxRhjfHeadStruct *pi,struct FNxRhjfHeadStruct *po);


/*单个结构申明*/
struct HbjsFileHeadStruct{

	struct HbjsFileHeadStruct *pNext;
	char    sFileName[61];		/* 接口数据文件名称 */
	int     iTotalCnt;		/* 文件中包含的记录数 */
	char    sFirstCallDate[9];	/* 数据起始日期 */
	char    sFirstCallTime[7];	/* 数据起始时间 */
	char    sEndCallDate[9];	/* 数据终止日期 */
	char    sEndCallTime[7];	/* 数据终止时间 */
	char    sCreatedDate[15];	/* 文件的生成时间 */
	struct HbjsFileHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FHbjsFileHeadStruct{

	char    sFileName[60];		/* 接口数据文件名称 */
	char    sTotalCnt[9];		/* 文件中包含的记录数 */
	char    sFirstCallDate[8];	/* 数据起始日期 */
	char    sFirstCallTime[6];	/* 数据起始时间 */
	char    sEndCallDate[8];	/* 数据终止日期 */
	char    sEndCallTime[6];	/* 数据终止时间 */
	char    sCreatedDate[14];	/* 文件的生成时间 */
};

/*单个结构申明*/
struct SmgDTicketStruct{

	struct SmgDTicketStruct *pNext;
	char    sMessageID[22];		/* 短消息标识 */
	char    sSmsType[3];		/* 短消息类型 */
	char    sSubType[3];		/* 短消息子类型 */
	char    sMsisdn[23];		/* 计费用户号码 */
	char    sSpCode[12];		/* SP号码 */
	char    sOtherParty[23];		/* 目的地号码 */
	char    sSpServiceCode[12];		/* 业务代码 */
	char    sBillType[4];		/* 用户计费类别 */
	char    sInfoFee[8];		/* 信息费 */
	char    sPriority[3];		/* 短消息发送优先级 */
	char    sMsgLen[5];		/* 信息长度 */
	char    sHomeAreaCode[6];		/* 计费号码归属地的区号 */
	char    sSmg[8];		/* SMGW代码 */
	char    sTsmg[8];		/* 前转SMGW代码 */
	char    sSmc[8];		/* 短消息中心代码 */
	char    sRecvDateTime[16];		/* 提交时间 */
	char    sDoneDateTime[16];		/* 处理结束时间 */
	char    sMsgID[22];		/* SMGW分配短消息标识 */
	char    sOppMsgID[22];		/* 异网之间的短消息标识 */
	char    sCallingNbr[22];		/* 主叫用户号码 */
	struct SmgDTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSmgDTicketStruct{

	char    sMessageID[21];		/* 短消息标识 */
	char    sSmsType[2];		/* 短消息类型 */
	char    sSubType[2];		/* 短消息子类型 */
	char    sMsisdn[22];		/* 计费用户号码 */
	char    sSpCode[11];		/* SP号码 */
	char    sOtherParty[22];		/* 目的地号码 */
	char    sSpServiceCode[11];		/* 业务代码 */
	char    sBillType[3];		/* 用户计费类别 */
	char    sInfoFee[7];		/* 信息费 */
	char    sPriority[2];		/* 短消息发送优先级 */
	char    sMsgLen[4];		/* 信息长度 */
	char    sHomeAreaCode[5];		/* 计费号码归属地的区号 */
	char    sSmg[7];		/* SMGW代码 */
	char    sTsmg[7];		/* 前转SMGW代码 */
	char    sSmc[7];		/* 短消息中心代码 */
	char    sRecvDateTime[15];		/* 提交时间 */
	char    sDoneDateTime[15];		/* 处理结束时间 */
	char    sMsgID[21];		/* SMGW分配短消息标识 */
	char    sOppMsgID[21];		/* 异网之间的短消息标识 */
	char    sCallingNbr[21];		/* 主叫用户号码 */
};

void mvitem_mfsmgdticket(struct SmgDTicketStruct *pi,struct FSmgDTicketStruct *po);
void mvitem_fmsmgdticket(struct FSmgDTicketStruct *pi,struct SmgDTicketStruct *po);
void mvitem_mfsmgdhead(struct HbjsFileHeadStruct *pi,struct FHbjsFileHeadStruct *po);
/*单个结构申明*/
struct ZnwSnIntfStruct{

	struct ZnwSnIntfStruct *pNext;
	char    sServiceKey[4];		/* 业务键 */
	char    sStartTime[15];		/* 开始通话时间 */
	char    sCallingNbr[25];		/* 主叫用户号码 */
	char    sCalledNbr[25];		/* 被叫用户号码 */
	char    sTranslatedNbr[25];		/* 目标地址号码号码 */
	char    sBillingNbr[25];		/* 规定的计费号码 */
	char    sDuration[13];		/* 通话时长分钟 */
	int     iSecond;		/* 通话时长不足一分钟的秒数 */
	char    sTotalFee[13];		/* 通话话费 */
	int     iBaseFee;		/* 基本费 */
	char    sTrunkIn[5];		/* 入中继群号 */
	char    sTrunkOut[5];		/* 出中继群号 */
	char    sMsc[2];		/* 交换机 */
	char    sTariffClass[3];		/* 费率种类 */
	char    sReserve[3];		/* 备用 */
	char    sGroupID[13];		/* 批次信息 */
	char    sCardID[14];		/* 卡号 */
	struct ZnwSnIntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FZnwSnIntfStruct{

	char    sServiceKey[3];		/* 业务键 */
	char    sStartTime[14];		/* 开始通话时间 */
	char    sCallingNbr[24];		/* 主叫用户号码 */
	char    sCalledNbr[24];		/* 被叫用户号码 */
	char    sTranslatedNbr[24];		/* 目标地址号码号码 */
	char    sBillingNbr[24];		/* 规定的计费号码 */
	char    sDuration[12];		/* 通话时长分钟 */
	char    sSecond[2];		/* 通话时长不足一分钟的秒数 */
	char    sTotalFee[12];		/* 通话话费 */
	char    sBaseFee[8];		/* 基本费 */
	char    sTrunkIn[4];		/* 入中继群号 */
	char    sTrunkOut[4];		/* 出中继群号 */
	char    sMsc[1];		/* 交换机 */
	char    sTariffClass[2];		/* 费率种类 */
	char    sReserve[2];		/* 备用 */
	char    sGroupID[12];		/* 批次信息 */
	char    sCardID[13];		/* 卡号 */
};
void mvitem_mfznwsnintf(struct ZnwSnIntfStruct *pi,struct FZnwSnIntfStruct *po);
void mvitem_fmznwsnintf(struct FZnwSnIntfStruct *pi,struct ZnwSnIntfStruct *po);

/*单个结构申明*/
struct ZnwGjIntfStruct{

	struct ZnwGjIntfStruct *pNext;
	char    sStreamNumber[11];		/* 流水号 */
	char    sServiceKey[11];		/* 业务键 */
	char    sBillingMode[2];		/* 计费模式 */
	char    sChargeRecordID[9];		/* 计费记录标识 */
	char    sCallingNbr[25];		/* 主叫用户号码 */
	char    sCalledNbr[25];		/* 被叫用户号码 */
	char    sTranslatedNbr[25];		/* 目标地址号码号码 */
	char    sLocationNbr[5];		/* 位置号码 */
	char    sBillingFlag[5];		/* 计费用户标志 */
	char    sBillingNbr[25];		/* 规定的计费号码 */
	char    sStartTime[15];		/* 开始通话时间 */
	char    sStopTime[15];		/* 通话结束时间 */
	char    sDuration[11];		/* 通话时长 */
	char    sTotalFee[11];		/* 通话话费 */
	char    sBearCapability[3];		/* 承载能力 */
	char    sTariffClass[3];		/* 费率种类 */
	char    sBillType[5];		/* 计费号码属性 */
	char    sUserID[11];		/* 用户ID或批次信息 */
	char    sServiceNbr[29];		/* 业务号码 */
	int     iCount;		/* 计次数 */
	char    sBaseFee[11];		/* 基本费 */
	char    sBountyFee[11];		/* 奖励金额 */
	char    sAddFee[11];		/* 附加费 */
	char    sTransParam[31];		/* 透明参数 */
	char    sCallparttobecharger[33];		/* 计费部分 */
	char    sScpID[11];		/* scp序号 */
	char    sCauseOfCallend[5];		/* 通话结束原因 */
	char    sServiceModulator[5];		/* 业务折扣率 */
	char    sServiceType[3];		/* 业务类型 */
	char    sHomeAreaCode[11];		/* 主叫归属地 */
	char    sCalledCode[11];		/* 被叫归属地 */
	char    sBillingAreaCode[11];		/* 计费区号 */
	char    sOriFileName[65];		/* 原始话单文件名 */
	struct ZnwGjIntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FZnwGjIntfStruct{

	char    sStreamNumber[10];		/* 流水号 */
	char    sServiceKey[10];		/* 业务键 */
	char    sBillingMode[1];		/* 计费模式 */
	char    sChargeRecordID[8];		/* 计费记录标识 */
	char    sCallingNbr[24];		/* 主叫用户号码 */
	char    sCalledNbr[24];		/* 被叫用户号码 */
	char    sTranslatedNbr[24];		/* 目标地址号码号码 */
	char    sLocationNbr[4];		/* 位置号码 */
	char    sBillingFlag[4];		/* 计费用户标志 */
	char    sBillingNbr[24];		/* 规定的计费号码 */
	char    sStartTime[14];		/* 开始通话时间 */
	char    sStopTime[14];		/* 通话结束时间 */
	char    sDuration[10];		/* 通话时长 */
	char    sTotalFee[10];		/* 通话话费 */
	char    sBearCapability[2];		/* 承载能力 */
	char    sTariffClass[2];		/* 费率种类 */
	char    sBillType[4];		/* 计费号码属性 */
	char    sUserID[10];		/* 用户ID或批次信息 */
	char    sServiceNbr[28];		/* 业务号码 */
	char    sCount[8];		/* 计次数 */
	char    sBaseFee[10];		/* 基本费 */
	char    sBountyFee[10];		/* 奖励金额 */
	char    sAddFee[10];		/* 附加费 */
	char    sTransParam[30];		/* 透明参数 */
	char    sCallparttobecharger[32];		/* 计费部分 */
	char    sScpID[10];		/* scp序号 */
	char    sCauseOfCallend[4];		/* 通话结束原因 */
	char    sServiceModulator[4];		/* 业务折扣率 */
	char    sServiceType[2];		/* 业务类型 */
	char    sHomeAreaCode[10];		/* 主叫归属地 */
	char    sCalledCode[10];		/* 被叫归属地 */
	char    sBillingAreaCode[10];		/* 计费区号 */
	char    sOriFileName[64];		/* 原始话单文件名 */
};

/*单个结构申明*/
struct HbZnwGjFileHeadStruct{

	struct HbZnwGjFileHeadStruct *pNext;
	char    sTotalCnt[12];		/* 文件中包含的记录数 */
	char    sTotalDuration[12];	/* 总时长 */
	char    sTotalFee[12];	/* 总金额 */
	struct HbZnwGjFileHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FHbZnwGjFileHeadStruct{

	char    sTotalCnt[11];		/* 文件中包含的记录数 */
	char    sTotalDuration[11];	/* 总时长 */
	char    sTotalFee[11];	/* 总金额 */
};


/*单个结构申明*/
struct ZnwGjAcctStruct{

	struct ZnwGjAcctStruct *pNext;
	char    sCallingNbr[21];		/* 业务号码 */
	char    sServiceKey[11];		/* 业务键 */
	char    sCalledNbr[11];		/* 业务接入码 */
	char    sBaseFee[11];		/* 基本费用 */
	char    sAddFee[11];		/* 附加费用 */
	char    sLcnt[12];		/* 本地次数 */
	char    sLduration[12];		/* 本地时长 */
	char    sLfee[12];		/* 本地金额 */
	char    sNcnt[12];		/* 省内长途次数 */
	char    sNduration[12];		/* 省内长途时长 */
	char    sNfee[12];		/* 省内长途金额 */
	char    sScnt[12];		/* 省际长途次数 */
	char    sSduration[12];		/* 省际长途时长 */
	char    sSfee[12];		/* 省际长途金额 */
	char    sGcnt[12];		/* 国际长途次数 */
	char    sGduration[12];		/* 国际长途时长 */
	char    sGfee[12];		/* 国际长途金额 */
	char    sCnt[12];		/* 合计次数 */
	char    sDuration[12];		/* 合计时长 */
	char    sFee[12];		/* 合计金额 */
	struct ZnwGjAcctStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FZnwGjAcctStruct{

	char    sCallingNbr[20];		/* 业务号码 */
	char    sServiceKey[10];		/* 业务键 */
	char    sCalledNbr[10];		/* 业务接入码 */
	char    sBaseFee[10];		/* 基本费用 */
	char    sAddFee[10];		/* 附加费用 */
	char    sLcnt[11];		/* 本地次数 */
	char    sLduration[11];		/* 本地时长 */
	char    sLfee[11];		/* 本地金额 */
	char    sNcnt[11];		/* 省内长途次数 */
	char    sNduration[11];		/* 省内长途时长 */
	char    sNfee[11];		/* 省内长途金额 */
	char    sScnt[11];		/* 省际长途次数 */
	char    sSduration[11];		/* 省际长途时长 */
	char    sSfee[11];		/* 省际长途金额 */
	char    sGcnt[11];		/* 国际长途次数 */
	char    sGduration[11];		/* 国际长途时长 */
	char    sGfee[11];		/* 国际长途金额 */
	char    sCnt[11];		/* 合计次数 */
	char    sDuration[11];		/* 合计时长 */
	char    sFee[11];		/* 合计金额 */
};


void mvitem_mfznwgjintf(struct ZnwGjIntfStruct *pi,struct FZnwGjIntfStruct *po);
void mvitem_fmznwgjintf(struct FZnwGjIntfStruct *pi,struct ZnwGjIntfStruct *po);
void mvitem_mfznwgjhead(struct HbZnwGjFileHeadStruct *pi,struct FHbZnwGjFileHeadStruct *po);



/*单个结构申明*/
struct Znw52IntfStruct{

	struct Znw52IntfStruct *pNext;
	char    sCallingNbr[25];		/* 主叫用户号码 */
	char    sCalledNbr[25];		/* 被叫用户号码 */
	char    sTranslatedNbr[25];		/* 目标地址号码号码 */
	char    sStartTime[15];		/* 开始通话时间 */
	char    sStopTime[15];		/* 通话结束时间 */
	char    sDuration[11];		/* 通话时长 */
	char    sTotalFee[11];		/* 通话话费 */
	struct Znw52IntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FZnw52IntfStruct{

	char    sCallingNbr[24];		/* 主叫用户号码 */
	char    sCalledNbr[24];		/* 被叫用户号码 */
	char    sTranslatedNbr[24];		/* 目标地址号码号码 */
	char    sStartTime[14];		/* 开始通话时间 */
	char    sStopTime[14];		/* 通话结束时间 */
	char    sDuration[10];		/* 通话时长 */
	char    sTotalFee[10];		/* 通话话费 */
};

void mvitem_mfznw52intf(struct Znw52IntfStruct *pi,struct FZnw52IntfStruct *po);
void mvitem_fmznw52intf(struct FZnw52IntfStruct *pi,struct Znw52IntfStruct *po);

/*单个结构申明*/
struct SpCdrSnIntfStruct{

	struct SpCdrSnIntfStruct *pNext;
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCalledNbr[11];		/* 业务接入号码 */
	char    sServiceNbr[21];		/* 业务号码 */
	char    sStartTime[15];		/* 起始时间 */
	char    sDuration[12];		/* 时长 */
	char    sFee[12];		/* 金额 */
	char    sNotes[21];		/* 备注 */
	char    sRate[16];		/* 费率 */
	char    sSpNbr[10];		/* SP_CP编号 */
	struct SpCdrSnIntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSpCdrSnIntfStruct{

	char    sCallingNbr[20];		/* 主叫号码 */
	char    sCalledNbr[10];		/* 业务接入号码 */
	char    sServiceNbr[20];		/* 业务号码 */
	char    sStartTime[14];		/* 起始时间 */
	char    sDuration[11];		/* 时长 */
	char    sFee[11];		/* 金额 */
	char    sNotes[20];		/* 备注 */
	char    sRate[15];		/* 费率 */
	char    sSpNbr[9];		/* SP_CP编号 */
};

void mvitem_mfspcdrsnintf(struct SpCdrSnIntfStruct *pi,struct FSpCdrSnIntfStruct *po);
void mvitem_fmspcdrsnintf(struct FSpCdrSnIntfStruct *pi,struct SpCdrSnIntfStruct *po);


/*单个结构申明*/
struct SpCdrZbIntfStruct{

	struct SpCdrZbIntfStruct *pNext;
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCalledNbr[11];		/* 业务接入号码 */
	char    sServiceNbr[21];		/* 业务号码 */
	char    sStartTime[15];		/* 起始时间 */
	char    sDuration[12];		/* 时长 */
	char    sFee[12];		/* 金额 */
	struct SpCdrZbIntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSpCdrZbIntfStruct{

	char    sCallingNbr[20];		/* 主叫号码 */
	char    sCalledNbr[10];		/* 业务接入号码 */
	char    sServiceNbr[20];		/* 业务号码 */
	char    sStartTime[14];		/* 起始时间 */
	char    sDuration[11];		/* 时长 */
	char    sFee[11];		/* 金额 */
};

void mvitem_mfspcdrzbintf(struct SpCdrZbIntfStruct *pi,struct FSpCdrZbIntfStruct *po);
void mvitem_fmspcdrzbintf(struct FSpCdrZbIntfStruct *pi,struct SpCdrZbIntfStruct *po);

/*单个结构申明*/
struct SpAcctSnIntfStruct{

	struct SpAcctSnIntfStruct *pNext;
	char    sProvinceName[5];		/* 省代码(HEB) */
	char    sAreaCode[5];		/* 本地网代码 */
	char    sSpNbr[10];		/* SP_CP编号 */
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCalledNbr[11];		/* 业务接入号码 */
	char    sCnt[12];		/* 次数 */
	char    sDuration[12];		/* 时长 */
	char    sFee[12];		/* 金额 */
	char    sRate[16];		/* 费率 */
	char    sNotes[21];		/* 备注 */
	struct SpAcctSnIntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSpAcctSnIntfStruct{

	char    sProvinceName[4];		/* 省代码(HEB) */
	char    sAreaCode[4];		/* 本地网代码 */
	char    sSpNbr[9];		/* SP_CP编号 */
	char    sCallingNbr[20];		/* 主叫号码 */
	char    sCalledNbr[10];		/* 业务接入号码 */
	char    sCnt[11];		/* 次数 */
	char    sDuration[11];		/* 时长 */
	char    sFee[11];		/* 金额 */
	char    sRate[15];		/* 费率 */
	char    sNotes[20];		/* 备注 */
};

void mvitem_mfspacctsnintf(struct SpAcctSnIntfStruct *pi,struct FSpAcctSnIntfStruct *po);
void mvitem_fmspacctsnintf(struct FSpAcctSnIntfStruct *pi,struct SpAcctSnIntfStruct *po);

void mvitem_mfznwgjacct(struct ZnwGjAcctStruct *pi,struct FZnwGjAcctStruct *po);
/*单个结构申明*/
struct SpAcctZbIntfStruct{

	struct SpAcctZbIntfStruct *pNext;
	char    sCallingNbr[21];		/* 主叫号码 */
	char    sCalledNbr[11];		/* 业务接入号码 */
	char    sCnt[12];		/* 次数 */
	char    sDuration[12];		/* 时长 */
	char    sFee[12];		/* 金额 */
	struct SpAcctZbIntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FSpAcctZbIntfStruct{

	char    sCallingNbr[20];		/* 主叫号码 */
	char    sCalledNbr[10];		/* 业务接入号码 */
	char    sCnt[11];		/* 次数 */
	char    sDuration[11];		/* 时长 */
	char    sFee[11];		/* 金额 */
};

void mvitem_mfspacctzbintf(struct SpAcctZbIntfStruct *pi,struct FSpAcctZbIntfStruct *po);




/*单个结构申明*/
struct NewCriTicketStruct{

	struct NewCriTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sInCityCode[4];		/* 入联通网城市代码 */
	char    sOutCityCode[4];		/* 出联通网城市代码 */
	char    sLinkRef[7];		/* 链参考 */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[26];		/* 用户号码 */
	char    sModifyTag[2];		/* 修改指示 */
	char    sNbrType[2];		/* 号码类型 */
	char    sNbrPlan[2];		/* 选号方案 */
	char    sOtherParty[26];		/* 对端号码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sServiceCode[3];		/* 业务代码 */
	char    sDupServiceType[2];		/* 双重业务类型 */
	char    sDupServiceCode[3];		/* 双重业务码 */
	char    sAckChannel[2];		/* 要求的收音通道 */
	char    sUseChannel[2];		/* 使用的收音通道 */
	char    sTransparentFlag[2];		/* 业务透明性 */
	char    sAct1[2];		/* ACT1 */
	char    sCode1[3];		/* CODE1 */
	char    sAct2[2];		/* ACT2 */
	char    sCode2[3];		/* CODE2 */
	char    sAct3[2];		/* ACT3 */
	char    sCode3[3];		/* CODE3 */
	char    sAct4[2];		/* ACT4 */
	char    sCode4[3];		/* CODE4 */
	char    sAct5[2];		/* ACT5 */
	char    sCode5[3];		/* CODE5 */
	char    sMsc[16];		/* MSC 标识 */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* 移动设备类别码 */
	char    sStartDate[9];		/* 通话日期 */
	char    sStartTime[7];		/* 通话起始时间 */
	char    sPayUnit[7];		/* 付费单位 */
	char    sFlowRef[7];		/* 数据量参考 */
	char    sTollCode[2];		/* 长途费代码 */
	char    sOtherCode[3];		/* 其他话费代码 */
	char    sRoamFee[10];		/* 漫游话费 */
	char    sTollFee[7];		/* 长途话费 */
	char    sOtherFee[7];		/* 其他话费 */
	char    sPayItem[2];		/* 收费的项目 */
	char    sSystemType[2];		/* 系统类型标识 */
	char    sRateIndication [2];	/* 速率指示标识 */
	char    sHotBillingTag[2];	/* 热计费标识 */
	char    sImei[26];		/* IMEI */
	char    sReserve2[31];		/* 保留字段1 */
	struct NewCriTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FNewCriTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sInCityCode[3];		/* 入联通网城市代码 */
	char    sOutCityCode[3];		/* 出联通网城市代码 */
	char    sLinkRef[6];		/* 链参考 */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[25];		/* 用户号码 */
	char    sModifyTag[1];		/* 修改指示 */
	char    sNbrType[1];		/* 号码类型 */
	char    sNbrPlan[1];		/* 选号方案 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sServiceType[1];		/* 业务类型 */
	char    sServiceCode[2];		/* 业务代码 */
	char    sDupServiceType[1];		/* 双重业务类型 */
	char    sDupServiceCode[2];		/* 双重业务码 */
	char    sAckChannel[1];		/* 要求的收音通道 */
	char    sUseChannel[1];		/* 使用的收音通道 */
	char    sTransparentFlag[1];		/* 业务透明性 */
	char    sAct1[1];		/* ACT1 */
	char    sCode1[2];		/* CODE1 */
	char    sAct2[1];		/* ACT2 */
	char    sCode2[2];		/* CODE2 */
	char    sAct3[1];		/* ACT3 */
	char    sCode3[2];		/* CODE3 */
	char    sAct4[1];		/* ACT4 */
	char    sCode4[2];		/* CODE4 */
	char    sAct5[1];		/* ACT5 */
	char    sCode5[2];		/* CODE5 */
	char    sMsc[15];		/* MSC 标识 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* 移动设备类别码 */
	char    sStartDate[8];		/* 通话日期 */
	char    sStartTime[6];		/* 通话起始时间 */
	char    sPayUnit[6];		/* 付费单位 */
	char    sFlowRef[6];		/* 数据量参考 */
	char    sTollCode[1];		/* 长途费代码 */
	char    sOtherCode[2];		/* 其他话费代码 */
	char    sRoamFee[9];		/* 漫游话费 */
	char    sTollFee[6];		/* 长途话费 */
	char    sOtherFee[6];		/* 其他话费 */
	char    sPayItem[1];		/* 收费的项目 */
	char    sSystemType[1];		/* 系统类型标识 */
	char    sRateIndication [1];	/* 速率指示标识 */
	char    sHotBillingTag[1];	/* 热计费标识 */
	char    sImei[25];		/* IMEI */
	char    sReserve2[30];		/* 保留字段1 */
};

/*单个结构申明*/
struct NewCiiTicketStruct{

	struct NewCiiTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sInCityCode[4];		/* 入联通网城市代码 */
	char    sOutCityCode[4];		/* 出联通网城市代码 */
	char    sLinkRef[7];		/* 链参考 */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[26];		/* 用户号码 */
	char    sModifyTag[2];		/* 修改指示 */
	char    sNbrType[2];		/* 号码类型 */
	char    sNbrPlan[2];		/* 选号方案 */
	char    sOtherParty[26];		/* 对端号码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sServiceCode[3];		/* 业务代码 */
	char    sDupServiceType[2];		/* 双重业务类型 */
	char    sDupServiceCode[3];		/* 双重业务码 */
	char    sAckChannel[2];		/* 要求的收音通道 */
	char    sUseChannel[2];		/* 使用的收音通道 */
	char    sTransparentFlag[2];		/* 业务透明性 */
	char    sAct1[2];		/* ACT1 */
	char    sCode1[3];		/* CODE1 */
	char    sAct2[2];		/* ACT2 */
	char    sCode2[3];		/* CODE2 */
	char    sAct3[2];		/* ACT3 */
	char    sCode3[3];		/* CODE3 */
	char    sAct4[2];		/* ACT4 */
	char    sCode4[3];		/* CODE4 */
	char    sAct5[2];		/* ACT5 */
	char    sCode5[3];		/* CODE5 */
	char    sMsc[16];		/* MSC 标识 */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* 移动设备类别码 */
	char    sStartDate[9];		/* 通话日期 */
	char    sStartTime[7];		/* 通话起始时间 */
	char    sPayUnit[7];		/* 付费单位 */
	char    sFlowRef[7];		/* 数据量参考 */
	char    sFee[10];		/* 总话费 */
	char    sPayItem[2];		/* 收费的项目 */
	char    sReserve2[31];		/* 保留字段1 */
	struct NewCiiTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FNewCiiTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sInCityCode[3];		/* 入联通网城市代码 */
	char    sOutCityCode[3];		/* 出联通网城市代码 */
	char    sLinkRef[6];		/* 链参考 */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[25];		/* 用户号码 */
	char    sModifyTag[1];		/* 修改指示 */
	char    sNbrType[1];		/* 号码类型 */
	char    sNbrPlan[1];		/* 选号方案 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sServiceType[1];		/* 业务类型 */
	char    sServiceCode[2];		/* 业务代码 */
	char    sDupServiceType[1];		/* 双重业务类型 */
	char    sDupServiceCode[2];		/* 双重业务码 */
	char    sAckChannel[1];		/* 要求的收音通道 */
	char    sUseChannel[1];		/* 使用的收音通道 */
	char    sTransparentFlag[1];		/* 业务透明性 */
	char    sAct1[1];		/* ACT1 */
	char    sCode1[2];		/* CODE1 */
	char    sAct2[1];		/* ACT2 */
	char    sCode2[2];		/* CODE2 */
	char    sAct3[1];		/* ACT3 */
	char    sCode3[2];		/* CODE3 */
	char    sAct4[1];		/* ACT4 */
	char    sCode4[2];		/* CODE4 */
	char    sAct5[1];		/* ACT5 */
	char    sCode5[2];		/* CODE5 */
	char    sMsc[15];		/* MSC 标识 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* 移动设备类别码 */
	char    sStartDate[8];		/* 通话日期 */
	char    sStartTime[6];		/* 通话起始时间 */
	char    sPayUnit[6];		/* 付费单位 */
	char    sFlowRef[6];		/* 数据量参考 */
	char    sFee[9];		/* 总话费 */
	char    sPayItem[1];		/* 收费的项目 */
	char    sReserve2[30];		/* 保留字段1 */
};
/*单个结构申明*/
struct NewTrsTicketStruct{

	struct NewTrsTicketStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sInCityCode[4];		/* 入联通网城市代码 */
	char    sOutCityCode[4];		/* 出联通网城市代码 */
	char    sLinkRef[7];		/* 链参考 */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sThirdParty[26];		/* 主叫号码A */
	char    sMsisdn[26];		/* 用户号码 */
	char    sOtherParty[26];		/* 对端号码 */
	char    sServiceType[2];		/* 业务类型 */
	char    sServiceCode[3];		/* 业务代码 */
	char    sReserve2[10];		/* 系统保留2 */
	char    sMsc[16];		/* MSC 标识 */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* 移动设备类别码 */
	char    sStartDate[9];		/* 通话日期 */
	char    sStartTime[7];		/* 通话起始时间 */
	char    sPayUnit[7];		/* 付费单位 */
	char    sSystemType[2];		/* 系统类型标识 */
	char    sRateIndication [2];	/* 速率指示标识 */
	char    sHotBillingTag[2];	/* 热计费标识 */
	char    sImei[26];		/* IMEI */
	char    sReserve3[52];		/* 保留3 */
	struct NewTrsTicketStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FNewTrsTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sInCityCode[3];		/* 入联通网城市代码 */
	char    sOutCityCode[3];		/* 出联通网城市代码 */
	char    sLinkRef[6];		/* 链参考 */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sThirdParty[25];		/* 主叫号码A */
	char    sMsisdn[25];		/* 用户号码 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sServiceType[1];		/* 业务类型 */
	char    sServiceCode[2];		/* 业务代码 */
	char    sReserve2[9];		/* 系统保留2 */
	char    sMsc[15];		/* MSC 标识 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* 移动设备类别码 */
	char    sStartDate[8];		/* 通话日期 */
	char    sStartTime[6];		/* 通话起始时间 */
	char    sPayUnit[6];		/* 付费单位 */
	char    sSystemType[1];		/* 系统类型标识 */
	char    sRateIndication [1];	/* 速率指示标识 */
	char    sHotBillingTag[1];	/* 热计费标识 */
	char    sImei[25];		/* IMEI */
	char    sReserve3[51];		/* 保留3 */
};

void NewDestroyCriTicket(struct NewCriTicketStruct *ptHead);
void Newmvitem_mfcriticket(struct NewCriTicketStruct *pi,struct FNewCriTicketStruct *po);
void Newmvitem_fmcriticket(struct FNewCriTicketStruct *pi,struct NewCriTicketStruct *po);

void NewDestroyCiiTicket(struct NewCiiTicketStruct *ptHead);
void Newmvitem_mfciiticket(struct NewCiiTicketStruct *pi,struct FNewCiiTicketStruct *po);
void Newmvitem_fmciiticket(struct FNewCiiTicketStruct *pi,struct NewCiiTicketStruct *po);

void NewDestroyTrsTicket(struct NewTrsTicketStruct *ptHead);
void Newmvitem_mftrsticket(struct NewTrsTicketStruct *pi,struct FNewTrsTicketStruct *po);
void Newmvitem_fmtrsticket(struct FNewTrsTicketStruct *pi,struct NewTrsTicketStruct *po);

/*单个结构申明*/
struct GprsHeadStruct{

	struct GprsHeadStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sProvCode[4];		/* 省分代码 */
	char    sFileFlag[5];		/* 文件标志 */
	char    sFileSeq[5];		/* 文件序列号 */
	char    sFileVersion[3];		/* 文件版本号 */
	char    sFileCreatDate[9];		/* 文件产生日期 */
	char    sFirstCallDate[9];		/* 首次连接日期 */
	char    sFirstCallTime[7];		/* 首次连接时间 */
	char    sLastCallDate[9];		/* 末次连接日期 */
	char    sLastCallTime[7];		/* 末次连接时间 */
	char    sTotalCnt[11];		/* 总记录数 */
	char    sTotalFee[16];		/* 总费用 */
	char    sNouse[343];		/* 未用 */
	struct GprsHeadStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FGprsHeadStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sProvCode[3];		/* 省分代码 */
	char    sFileFlag[4];		/* 文件标志 */
	char    sFileSeq[4];		/* 文件序列号 */
	char    sFileVersion[2];		/* 文件版本号 */
	char    sFileCreatDate[8];		/* 文件产生日期 */
	char    sFirstCallDate[8];		/* 首次连接日期 */
	char    sFirstCallTime[6];		/* 首次连接时间 */
	char    sLastCallDate[8];		/* 末次连接日期 */
	char    sLastCallTime[6];		/* 末次连接时间 */
	char    sTotalCnt[10];		/* 总记录数 */
	char    sTotalFee[15];		/* 总费用 */
	char    sNouse[342];		/* 未用 */
};

/*单个结构申明*/
struct GprsTicketIntfStruct{

	struct GprsTicketIntfStruct *pNext;
	char    sRecordType[3];		/* 记录类型 */
	char    sRoamType[3];		/* 漫游类型 */
	char    sImsi[16];		/* 手机终端的IMSI */
	char    sMsisdn[16];		/* 手机终端的ISDN */
	char    sSgsn[17];		/* 本次会话起始SGSNIP地址 */
	char    sSgsnChange[2];		/* SGSN改变标识 */
	char    sGgsn[17];		/* 本次会话GGSNIP地址 */
	char    sServedPdpAddress[17];		/* 手机终端PDPIP地址 */
	char    sApnNi[64];		/* 接入点网络标识 */
	char    sApnOi[38];		/* 接入点运营商标识 */
	char    sReserv1[15];		/* 保留字段1 */
	char    sCallDuration[7];		/* 呼叫总时长 */
	char    sPartialType[2];		/* 局部类型标识符 */
	char    sCloseCause[3];		/* 中断原因 */
	char    sStartTime[15];		/* 本段会话连接开始时间 */
	char    sNiPdp[2];		/* 网络侧呼叫标志 */
	char    sChargingID[11];		/* PDP上下文计费标识 */
	char    sLac[6];		/* 位置区号 */
	char    sCellID[6];		/* 小区标识 */
	char    sVisitCityCode[4];		/* 漫游地城市代码 */
	char    sReserv2[11];		/* 保留字段2 */
	char    sRoamRemark[11];		/* 漫游地表述 */
	char    sImei[20];		/* 手机串号 */
	char    sDataFlowdn[11];		/* 下行流量 */
	char    sDataFlowup[11];		/* 上行流量 */
	char    sChargeItem[2];		/* 计费项目 */
	char    sChargeUnit[11];		/* 计费取整 */
	char    sChargeOperation[3];		/* 计费业务 */
	char    sTotalFee[10];		/* 费用 */
	char    sReserv3[94];		/* 保留字段3 */
	struct GprsTicketIntfStruct *pLoadNext;
};


/*单个文件结构申明*/
struct FGprsTicketIntfStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sRoamType[2];		/* 漫游类型 */
	char    sImsi[15];		/* 手机终端的IMSI */
	char    sMsisdn[15];		/* 手机终端的ISDN */
	char    sSgsn[16];		/* 本次会话起始SGSNIP地址 */
	char    sSgsnChange[1];		/* SGSN改变标识 */
	char    sGgsn[16];		/* 本次会话GGSNIP地址 */
	char    sServedPdpAddress[16];		/* 手机终端PDPIP地址 */
	char    sApnNi[63];		/* 接入点网络标识 */
	char    sApnOi[37];		/* 接入点运营商标识 */
	char    sReserv1[14];		/* 保留字段1 */
	char    sCallDuration[6];		/* 呼叫总时长 */
	char    sPartialType[1];		/* 局部类型标识符 */
	char    sCloseCause[2];		/* 中断原因 */
	char    sStartTime[14];		/* 本段会话连接开始时间 */
	char    sNiPdp[1];		/* 网络侧呼叫标志 */
	char    sChargingID[10];		/* PDP上下文计费标识 */
	char    sLac[5];		/* 位置区号 */
	char    sCellID[5];		/* 小区标识 */
	char    sVisitCityCode[3];		/* 漫游地城市代码 */
	char    sReserv2[10];		/* 保留字段2 */
	char    sRoamRemark[10];		/* 漫游地表述 */
	char    sImei[19];		/* 手机串号 */
	char    sDataFlowdn[10];		/* 下行流量 */
	char    sDataFlowup[10];		/* 上行流量 */
	char    sChargeItem[1];		/* 计费项目 */
	char    sChargeUnit[10];		/* 计费取整 */
	char    sChargeOperation[2];		/* 计费业务 */
	char    sTotalFee[9];		/* 费用 */
	char    sReserv3[93];		/* 保留字段3 */
};
void mvitem_mfgprshead(struct GprsHeadStruct *pi,struct FGprsHeadStruct *po);
void mvitem_mfgprsticketintf(struct GprsTicketIntfStruct *pi,struct FGprsTicketIntfStruct *po);


#include <bintree.h>

/*重单处理*/
#define KEYLEN sizeof(unsigned char)*16
struct KeyStruct{
	unsigned char sKey[KEYLEN];/*为节省空间不使用char,而使用unsigned char 保存*/
	time_t tDateTime;/*time_t保存时间，用于判断些数据是否已经过期不需要判重*/	
};

struct KeyStruct *MakeDupKey(char sDateTime[],char *pcFmt,...);
int SaveKeytoFile(BINTREE **pptRoot,char sFileName[]);
int LoadKeyFromFile(BINTREE **pptRoot,const char sFileName[],
	int (*hook_load_file)(struct KeyStruct *pNode));
int IsDupTicket(BINTREE *pRoot,struct KeyStruct *pNode);
int AddKeyToFile(struct KeyStruct *pTmpNode, BINTREE **pptRoot);
int delete_overtime_ticket(struct KeyStruct *pNode);
struct KeyStruct *MakeDupKey(char sDateTime[],char *fmt,...);
int MD5(char sOutput[],char *fmt,...);



#endif

