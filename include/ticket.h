#ifndef __TICKET_H__
#define __TICKET_H__

/*单个文件结构申明*/
struct FPrepTicketStruct{

	char    sCallType[2];
	char    sImsi[15];
	char    sMsisdn[15];
	char    sOtherParty[24];
	char    sStartTime[14];
	char    sDuration[6];
	char    sMsc[10];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sLac[4];
	char    sCellID[4];
	char    sOtherLac[4];
	char    sOtherCellID[4];
	char    sServiceType[3];
	char    sServiceCode[4];
	char    sThirdParty[15];
	char    sMsrn[12];
	char	sUserType[1];
	char	sReserve1[2];
	char    sEsn[15];
	char	sScpFlag[1];
	char	sDeformFlag[1];
	char	sReserve[8];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*单个文件结构申明*/
struct FSttTicketStruct{

	char    sTicketTypeID[4];		/* 话单类别 */
	char    sCallType[2];		/* 呼叫类别 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sCalledCode[5];		/* 对端区号 */
	char    sOtherParty[24];		/* 对端号码 */
	char    sVisitAreaCode[5];		/* 结算归属地区号 */
	char    sRoamFee[5];		/* 漫游通话费 */
	char    sTollFee[7];		/* 长途费 */
	char    sAddFee[5];		/* 其他费 */
	char    sDuration[6];		/* 时长 */
	char    sStartTime[14];		/* 通话开始时间 */
	char    sHomeAreaCode[5];		/* 用户归属地 */
	char    sRoamType[1];		/* 漫游类别 */
	char    sDistanceType[1];		/* 位置类别 */
	char    sOppType[1];		/* 对端类别 */
	char    sUserType[1];		/* 用户类别 */
	char    sSplitRuleID[4];		/* 话单分离标识 */
	char    sOppRoamType[1];		/* 对端漫游类别 */
	char    sServiceType[3];		/* 业务类型 */
	char    sServiceCode[4];		/* 业务代码 */
	char    sImsi[15];		/* 用户IMSI */
	char    sMsc[15];		/* 交换机标识 */
	char    sLac[5];		/* 小区号 */
	char    sCellID[5];		/* 蜂窝号 */
	char    sOtherLac[5];		/* 小区号 */
	char    sOtherCellID[5];	/* 蜂窝号 */
	char    sTrunkIn[7];		/* 入中继 */
	char    sTrunkOut[7];		/* 出中继 */
	char    sThirdParty[15];		/* 第三方号码 */
	char    sMsrn[12];		/* 动态漫游号 */
	char    sTrunkInTypeID[4];		/* 入中继类别 */
	char    sTrunkOutTypeID[4];		/* 出中继类别 */
	char    sTrunkInCarrierID[4];		/* 入中继运营商 */
	char    sTrunkOutCarrierID[4];		/* 出中继运营商 */
	char    sTrunkInType[1];		/* 入中继长途类型标识 */
	char    sTrunkOutType[1];		/* 出中继长途类型标识 */
	char    sCallingCarrierID[4];		/* 主叫号头运营商 */
	char    sCalledCarrierID[4];		/* 被叫号头运营商 */
	char    sCallingTypeID[4];		/* 主叫类型标识 */
	char    sCalledTypeID[4];		/* 被叫类型标识 */
	char	sCallingAreaID[4];
	char	sCalledAreaID[4];
	char	sSplitType[1];
	char	sCal[1];
	char	sEsn[15];
	char	sScpFlag[1];
	char	sDeformFlag[1];
	char	sReserve[8];
	char	sBillMode[3];
	char	sReserve1[2];
	char	sRoamTariffType[3];
	char	sTollTariffType[3];
	char	sAddTariffType[3];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*单个文件结构申明*/
struct FT193TicketStruct{

	char    sCallType[2];		/* CALL_TYPE */
	char    sMsisdn[20];		/* 用户号码 */
	char    sOtherParty[20];		/* 对端号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sDuration[6];		/* 通话时长 */
	char    sMsc[10];		/* MSC */
	char    sTrunkIn[8];		/* 入中继 */
	char    sTrunkOut[8];		/* 出中继 */
	char    sCallingAreaCode[5];		/* 用户区号 */
	char    sCalledAreaCode[5];		/* 对端区号 */
};
struct FSmscTicketStruct{
	char    sCallType[2];		/* 呼叫类型 */
	char    sCityCode[5];		/* 结算城市代码 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sOtherParty[24];		/* 对端号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sDuration[6];		/* 通话时长 */
	char    sMsc[15];		/* 短信中心 */
	char    sSmsp[15];		/* 短信网关 */
	char    sUserType[1];		/* 用户类型 */
	char    sFee[6];		/* 费用 */
	char    sServiceCode[4];	/* 业务代码 */
	char	sTicketTypeID[4];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*单个文件结构申明*/
struct FSmspTicketStruct{

	char    sCallType[2];		/* 呼叫类型 */
	char    sCityCode[5];		/* 结算城市代码 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sOtherParty[24];		/* 对端号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sDuration[6];		/* 字节数 */
	char    sMsc[15];		/* 短信中心 */
	char    sSmsp[15];		/* 短信网关 */
	char    sUserType[1];		/* 用户类型 */
	char    sSpAccNbr[12];		/* SP接入代码 */
	char    sSpServiceCode[10];		/* SP业务代码 */
	char    sSpCode[5];		/* SP代码 */
	char    sFee1[6];		/* 费用1 */
	char    sFee2[6];		/* 费用2 */
	char    sFee3[6];		/* 费用3 */
	char    sFee4[6];		/* 费用4 */  
	char	sFee5[8];		/* 费用5 */
	char	sFee6[8];		/* 费用6 */
	char	sTicketTypeID[4];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*单个文件结构申明*/
struct FGprsTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sNiPdp[1];		/* 网络侧发起PDP上下文的标志 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sImsi[15];		/* IMSI号码 */
	char    sSgsn[8];		/* SGSN代码 */
	char    sMsnc[1];		/* 手机的网络能力 */
	char    sLac[4];		/* LAC */
	char    sRouteArea[4];		/* 路由区域 */
	char    sCellID[4];		/* CELL_ID */
	char    sChargingID[8];		/* PDP上下文的计费标识 */
	char    sGgsn[8];		/* GGSN */
	char    sApnNi[63];		/* APN的网络标识 */
	char    sApnOi[37];		/* APN的运营商标识 */
	char    sPdpType[1];		/* PDP类型 */
	char    sServedPdpAddress[16];	/* 终端的PDP地址 */
	char    sSgsnChange[1];		/* SGSN切换标识 */
	char    sCloseCause[1];		/* 记录终止原因 */
	char    sResult[1];		/* "S"，合并成功;"F"需要进一步合并;"N"，合并不正常等 */
	char    sHomeAreaCode[9];	/* 用户归属区号 */
	char    sVisitAreaCode[9];	/* 用户拜访 */
	char    sUserType[2];		/* "00" 普通用户;"01" 预付费用户;"02" 卡类用户 */
	char    sFeeType[2];		/* 费用类型 */
	char    sRoamType[1];		/* 漫游类型 */
	char    sServiceType[3];	/* 服务类型 */
	char    sStartTime[14];		/* 应答时间 */
	char    sCallDuration[6];	/* 呼叫持续时间 */
	char    sTariff1[1];		/* 资费1 */
	char    sDataFlowup1[10];	/* 上行流量1 */
	char    sDataFlowdn1[10];	/* 下行流量1 */
	char    sDuration1[6];		/* 持续时间1 */
	char    sTariff2[1];		/* 资费2 */
	char    sDataFlowup2[10];		/* 上行流量2 */
	char    sDataFlowdn2[10];		/* 下行流量2 */
	char    sDuration2[6];		/* 持续时间2 */
	char    sTariff3[1];		/* 资费3 */
	char    sDataFlowup3[10];		/* 上行流量3 */
	char    sDataFlowdn3[10];		/* 下行流量3 */
	char    sDuration3[6];		/* 持续时长3 */
	char    sTariff4[1];		/* 资费4 */
	char    sDataFlowup4[10];		/* 上行流量4 */
	char    sDataFlowdn4[10];		/* 下行流量4 */
	char    sDuration4[6];		/* 持续时长4 */
	char    sTariff5[1];		/* 资费5 */
	char    sDataFlowup5[10];		/* 上行流量5 */
	char    sDataFlowdn5[10];		/* 下行流量5 */
	char    sDuration5[6];		/* 持续时长5 */
	char    sTariff6[1];		/* 资费6 */
	char    sDataFlowup6[10];		/* 上行流量6 */
	char    sDataFlowdn6[10];		/* 下行流量6 */
	char    sDuration6[6];		/* 持续时长6 */
	char    sCfee[8];		/* 基本通信费 */
	char    sFee1[8];		/* 费用1 */
	char    sFee2[8];		/* 费用2 */
	char    sFee3[8];		/* 费用3 */
	char    sTotalFee[9];		/* 总费用 */
	char	sTicketTypeID[4];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*单个文件结构申明*/
struct FCdmaTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sImsi[15];		/* IMSI */
	char    sEsn[15];		/* 电子序列号 */
	char    sOtherParty[21];		/* 对端号码 */
	char    sMsrn[15];		/* MSRN */
	char    sThirdParty[21];		/* 第三方号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sDuration[6];		/* 时长 */
	char    sMsc[10];		/* 交换机 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* 对端LAC */
	char    sOtherCellID[5];		/* 对端CELL_ID */
	char    sAppendServiceCode[2];		/* 增值业务 */
	char    sEndReason[1];		/* 结束原因 */
	char    sDeformityFlag[1];		/* 残缺标志 */
	char    sRoamFee[8];		/* 基本费 */
	char    sRoamDuration[6];		/* 基本计费时长 */
	char    sRoamRateType[1];		/* 基本多费率标识 */
	char    sTollFee[8];		/* 长途费 */
	char    sTollDuration[6];		/* 长途计费时长 */
	char    sTollFeeType[1];		/* 长途多费率标识 */
	char    sInfoFee[8];		/* 信息费 */
	char    sOtherFee[8];		/* 其他费 */
	char    sOppCityCode[3];		/* 对端归属城市代码 */
	char    sOppProvCode[3];		/* 对端归属省代码 */
	char    sOppCountryCode[3];		/* 对端所在国代码 */
	char    sTollType[1];		/* 长途类型 */
	char    sTollNetType[1];		/* 长途网类型 */
	char    sRoamType[1];		/* 漫游类型 */
	char    sVisitCityCode[3];		/* 通话地城市代码 */
	char    sTrunkIn[8];		/* 入中继 */
	char    sTrunkOut[8];		/* 出中继 */
	char    sUserType[1];		/* 用户类型 */
	char    sActCode[1];		/* 活动代码 */
	char    sServiceCode[2];		/* 业务代码 */
	char	sCalledType[3];
	char	sHomeAreaCode[10];
	char	sUserType1[2];
	char	sReserve[18];
};
/*单个文件结构申明*/
struct FCdmaTicketFjStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sMsisdn[11];		/* 用户号码 */
	char    sImsi[15];		/* IMSI */
	char    sEsn[11];		/* 电子序列号 */
	char    sOtherParty[21];		/* 对端号码 */
	char    sMsrn[15];		/* MSRN */
	char    sThirdParty[21];		/* 第三方号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sDuration[6];		/* 时长 */
	char    sMsc[10];		/* 交换机 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* 对端LAC */
	char    sOtherCellID[5];		/* 对端CELL_ID */
	char    sAppendServiceCode[2];		/* 增值业务 */
	char    sEndReason[1];		/* 结束原因 */
	char    sDeformityFlag[1];		/* 残缺标志 */
	char    sRoamFee[8];		/* 基本费 */
	char    sRoamDuration[6];		/* 基本计费时长 */
	char    sRoamRateType[1];		/* 基本多费率标识 */
	char    sTollFee[8];		/* 长途费 */
	char    sTollDuration[6];		/* 长途计费时长 */
	char    sTollFeeType[1];		/* 长途多费率标识 */
	char    sInfoFee[8];		/* 信息费 */
	char    sOtherFee[8];		/* 其他费 */
	char    sOppCityCode[3];		/* 对端归属城市代码 */
	char    sOppProvCode[3];		/* 对端归属省代码 */
	char    sOppCountryCode[3];		/* 对端所在国代码 */
	char    sTollType[1];		/* 长途类型 */
	char    sTollNetType[1];		/* 长途网类型 */
	char    sRoamType[1];		/* 漫游类型 */
	char    sVisitCityCode[3];		/* 通话地城市代码 */
	char    sTrunkIn[8];		/* 入中继 */
	char    sTrunkOut[8];		/* 出中继 */
	char    sUserType[1];		/* 用户类型 */
	char    sActCode[1];		/* 活动代码 */
	char    sServiceCode[2];		/* 业务代码 */
};
/*单个文件结构申明*/
struct FCdmaTicketXjStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sMsisdn[11];		/* 用户号码 */
	char    sImsi[15];		/* IMSI */
	char    sEsn[11];		/* 电子序列号 */
	char    sOtherParty[21];		/* 对端号码 */
	char    sMsrn[15];		/* MSRN */
	char    sThirdParty[21];		/* 第三方号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sDuration[6];		/* 时长 */
	char    sMsc[10];		/* 交换机 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* 对端LAC */
	char    sOtherCellID[5];		/* 对端CELL_ID */
	char    sAppendServiceCode[2];		/* 增值业务 */
	char    sEndReason[1];		/* 结束原因 */
	char    sDeformityFlag[1];		/* 残缺标志 */
	char    sRoamFee[8];		/* 基本费 */
	char    sRoamDuration[6];		/* 基本计费时长 */
	char    sRoamRateType[1];		/* 基本多费率标识 */
	char    sTollFee[8];		/* 长途费 */
	char    sTollDuration[6];		/* 长途计费时长 */
	char    sTollFeeType[1];		/* 长途多费率标识 */
	char    sInfoFee[8];		/* 信息费 */
	char    sOtherFee[8];		/* 其他费 */
	char    sOppCityCode[3];		/* 对端归属城市代码 */
	char    sOppProvCode[3];		/* 对端归属省代码 */
	char    sOppCountryCode[3];		/* 对端所在国代码 */
	char    sTollType[1];		/* 长途类型 */
	char    sTollNetType[1];		/* 长途网类型 */
	char    sRoamType[1];		/* 漫游类型 */
	char    sVisitCityCode[3];		/* 通话地城市代码 */
	char    sUserType[1];		/* 用户类型 */
	char    sActCode[1];		/* 活动代码 */
	char    sServiceCode[2];		/* 业务代码 */
};
/*单个文件结构申明*/
struct FCdma1xTicketStruct{

	char    sRecordType[2];		/* 记录类型 */
	char    sSeqNumber[10];		/* 序列号码 */
	char    sMdn[20];		/* 用户手机号 */
	char    sMsisdn[15];		/* MSISDN */
	char    sEsn[19];		/* 手机设备串号 */
	char    sIp[15];		/* IP */
	char    sNai[64];		/* 用户数据业务账号 */
	char    sUserType[1];		/* 用户类别 */
	char    sNaiAreaCode[3];		/* 联通城市代码 */
	char    sRoamType[1];		/* 漫游类别:0＝本地；1＝省际漫入；2＝省际漫出;3＝国际漫入；
4＝国际漫出（缺省：按IMSI 进行漫游判断） */
	char    sIpTechType[1];		/* IP类别 */
	char    sAccountSessionID[8];		/* 标识一个会话连接 */
	char    sCorrelationID[8];		/* 标识一个PPP 连接 */
	char    sHaip[15];		/* HA 的IP 地址 */
	char    sPdsnip[15];		/* pdsnip */
	char    sPcfip[15];		/* 使用PCF 地址 */
	char    sBsid[12];		/* SID NID BSC ID */
	char    sUzid[10];		/* 用户所在区域标识 */
	char    sServiceOption[2];		/* 固定为33 */
	char    sCompulsoryTunnel[1];		/* 强制隧道类型 */
	char    sEndRelease[1];		/* 发送Accounting stop 的原因 */
	char    sDataCountTermination[10];		/* 发送给用户的字节数 */
	char    sDataCountOrigination[10];		/* 用户发起的字节数 */
	char    sBadFrameCount[10];		/* 被PDSN 丢弃的坏帧 */
	char    sStartTime[14];		/* 会话开始的时间点 */
	char    sStopTime[14];		/* 会话结束的时间点 */
	char    sActiveTime[10];		/* 会话时长 */
	char    sActionCount[10];		/* 转换次数 */
	char    sSdbCountTermination[10];		/* 用户SDB接收字节数 */
	char    sSdbCountOrigination[10];		/* 用户SDB发送字节数 */
	char    sSdbTerminationnum[10];		/* 用户接收SDB次数 */
	char    sSdbOriginationnum[10];		/* 用户发送SDB次数 */
	char    sPdsnReceiveNum[10];		/* PDSN 收到的HDLC */
	char    sMipReceiveNum[10];		/* 用户接收MIP 信令字节 */
	char    sMipSendNum[10];		/* 用户发送MIP 信令字节 */
	char    sIpqos[10];		/* IP 网络用户质量等级码 */
	char    sAirlinkqos[10];		/* 无线链路质量等级码 */
	char    sBaseCharge[8];		/* 基本费 */
	char    sFluxCharge[8];		/* 流量费 */
	char    sOtherCharge[8];		/* 其他费用 */
	char    sHomeCountryCode[5];		/* 归属地城市代码 */
	char    sHomeOperatorCode[5];		/* 归属地运营商代码 */
	char    sVisitCountryCode[5];		/* 漫游地城市代码 */
	char    sVisitOperatoCode[5];		/* 漫游地运营商代码 */
	char    sRatingRuleID[8];		/* 资费规则标识 */
	char    sNoused1[10];		/* 系统保留 */
	char    sNoused2[10];		/* 系统保留2 */
	char    sNoused3[10];		/* 系统保留3 */
	char	sTicketTypeID[4];
	char	sHomeAreaCode[5];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};

/*单个文件结构申明*/
struct FGsmRateTicketStruct{

	char    sTicketID[10];		/* 话单序列号 */
	char    sMsisdn[15];		/* 手机号码 */
	char    sImsi[15];		/* Imsi号码 */
	char    sCityCode[4];		/* 城市代码 */
	char    sMonth[2];		/* 月份 */
	char    sBillMonth[6];		/* 计费月份 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sStartTime[14];		/* 呼叫日期 */
	char    sEndReason[1];		/* 结束原因 */
	char    sDeformFlag[1];		/* 残缺标志 */
	char    sOtherParty[21];		/* 对端号码 */
	char    sCalledCode[4];		/* 对方地区代码 */
	char    sDuration[6];		/* 通话时长 */
	char    sMsc[10];		/* 交换机代码 */
	char    sCellID[5];		/* 基站号 */
	char    sOtherCellID[5];		/* 对方基站号 */
	char    sTrunkIn[7];		/* 入中继 */
	char    sTrunkOut[7];		/* 出中继 */
	char    sTollType[1];		/* 长途类型 */
	char    sRoamType[1];		/* 漫游类型 */
	char    sTollNetType[1];		/* 长途网类型 */
	char    sValueAddBusi[2];		/* 增值业务 */
	char    sGroupID[5];		/* 闭合用户群ID */
	char    sSameGroupFlag[1];		/* 双方是同一闭合用户群 */
	char    sHomeProvCode[3];		/* 所属局 */
	char    sVisitCityCode[3];		/* 漫游局 */
	char    sThirdParty[15];		/* B号码 */
	char    sBusiType[1];		/* 通话/承载业务类别 */
	char    sBusiCode[2];		/* 通话/承载业务代码 */
	char    sBaseFee[10];		/* 基本费 */
	char    sTollFee[10];		/* 长途费 */
	char    sTollAddFee[10];		/* 长附费 */
	char    sOtherFee[10];		/* 其他费 */
	char    sRoamFee[10];		/* 漫游费 */
	char    sAddFee[10];		/* 附加费 */
	char    sDisctBaseFee[10];		/* 优惠基本费 */
	char    sDisctTollFee[10];		/* 优惠长途费 */
	char    sDisctTollAddFee[10];		/* 优惠长附费 */
	char    sDisctOtherFee[10];		/* 优惠其他费 */
	char    sSupplementActiveCode[1];		/* 附加业务活动码 */
	char    sSupplementCode[2];		/* 附加业务码 */
	char    sFileSeq[8];		/* 文件号 */
	char    sCalledType[3];		/* Called_type */
	char    sHomeAreaCode[10];		/* Home_area_code */
	char    sLac[5];		/* lac */
	char    sUserType[2];		/* User_type */
	char    sReserve[18];		/* 保留字段 */
};
/*单个文件结构申明*/
struct FSmsRateTicketStruct{

	char    sRecordType[2];
	char    sCallType[1];
	char    sMsisdn[13];
	char    sUserType[1];
	char    sHomeAreaCode[4];
	char    sCallingNbr[13];
	char    sCalledNbr[13];
	char    sBusiCode[10];
	char    sFeeType[1];
	char    sMsgLen[4];
	char    sMsgCnt[4];
	char    sStartTime[14];
	char    sBaseFee[6];
	char    sInfoFee[6];
	char    sInfoFeeType[2];
	char    sOriFileName[20];
	char    sReserve[20];
};
/*单个文件结构申明*/
struct FSmsupTicketStruct{

	char    sRecordType[2];
	char    sMsgType[3];
	char    sSpProvCode[3];
	char    sSmg[5];
	char    sSpCode[5];
	char    sFwSmg[5];
	char    sFwSmgProv[3];
	char    sStartTime[14];
	char    sMsgCnt[10];
	char    sBaseFee[12];
	char    sInfoFee[12];
	char    sHomeProvCode[3];
	char    sFileType[3];
	char    sReserve1[30];
	char    sState[3];
};
/*单个文件结构申明*/
struct FSmsupIntfTicketStruct{

	char    sRecordType[2];		/* 数据记录标示 */
	char    sMsgType[3];		/* 消息类型 */
	char    sSpProvCode[3];		/* SP所属省代码 */
	char    sSmg[5];		/* SP所属SMG代码 */
	char    sSpCode[5];		/* SP代码 */
	char    sFwSmg[5];		/* 前转网关代码 */
	char    sFwSmgProv[3];		/* 前转网关省代码 */
	char    sMinStartTime[14];		/* 本次话单最早记录时间 */
	char    sMaxStartTime[14];		/* 本次话单最晚记录时间 */
	char    sMoCnt1[10];		/* 分公司出帐后的全国SP/CP应收帐数据的总MO/MO-F话单数 */
	char    sMoCnt2[10];		/* 分公司出帐后的全国SP/CP应收帐数据的总MO/MO-F话单条数 */
	char    sMfCnt1[10];		/* 分公司出帐后的全国SP/CP应收帐数据的总MT/MT-F话单数 */
	char    sMfCnt2[10];		/* 分公司出帐后的全国SP/CP应收帐数据的总MT/MT-F话单条数 */
	char    sFee1[12];		/* 分公司出帐后的全国SP/CP应收帐数据的结算总费用 */
	char    sFee2[12];		/* 分公司出帐后的全国SP/CP应收帐数据的结算总费用 */
	char    sHomeProvCode[3];		/* 计费用户所属省代码 */
	char    sRoamFee1[10];		/* 分公司出帐后的全国SP/CP应收帐数据的通信费总费用 */
	char    sRoamFee2[10];		/* 分公司出帐后的全国SP/CP应收帐数据的通信总费用 */
	char    sInfoFee1[10];		/* 分公司出帐后的全国SP/CP应收帐数据的信息费总费用 */
	char    sInfoFee2[10];		/* 分公司出帐后的全国SP/CP应收帐数据的信息费总费用 */
	char    sRoamNfee1[10];		/* 分公司出帐后的全国SP/CP应收帐数据的不均衡通信费总费用 */
	char    sRoamNfee2[10];		/* 分公司出帐后的全国SP/CP应收帐数据的不均衡通信总费用 */
	char    sReserve1[20];		/* 保留1 */
};
/*单个文件结构申明*/
struct FRhjfTicketStruct{

	char    sCallType[2];
	char    sTicketType[2];
	char    sMsisdn[15];
	char    sOtherParty[30];
	char    sStartTime[14];
	char    sDuration[6];
	char    sMsc[15];
	char    sTrunkIn[7];
	char    sTrunkOut[7];
	char    sBaseCharge[8];
	char    sLandCharge[8];
	char    sOtherCharge[8];
	char    sLandType[1];
	char    sVisitAreaCode[5];
	char    sHomeAreaCode[5];
	char    sCalledAreaCode[5];
};

/*单个文件结构申明*/
struct FSmsTicketStruct{

	char    sTicketTypeID[4];	/* 话单类型标识 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sHomeAreaCode[5];	/* 用户归属号码 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sCalledCode[5];		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    sOtherParty[24];	/* 对端号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sMsgLen[4];		/* 消息长度 */
	char    sMsgID[30];		/* 消息ID */
	char    sSmsc[15];		/* 短信中心 */
	char    sSmg[15];		/* 短信网关 */
	char    sTsmg[15];		/* 前转短信网关 */
	char    sUserType[1];		/* G,C */
	char    sCalledType[2];		/* 对端类型 */
	char	sSpAccNbr[12];		/* SP接入代码 */
	char    sSpServiceCode[10];	/* SP业务代码 */
	char    sSpCode[5];		/* SP代码 */
	char    sBaseFee[8];		/* 通信费 */
	char    sInfoFee[8];		/* 信息费 */
	char    sRentFee[8];		/* 包月费 */
	char    sOtherFee[8];		/* 其他费 */
	char    sInFee[8];		/* 结算收入 */
	char    sOutFee[8];		/* 结算支出 */
	char	sOriCallType[2];
	char	sReserve[10];
	char	sSpProvCode[3];
	char	sHomeProvCode[3];
	char	sScpFlag[1];
	char    sCallingTypeID[4];
	char	sBillType[1];
	char    sErrCode[4];		/* 错误代码 */
	char    sFileName[19];		/* 文件名 */
	char    sModule[3];		/* 模块 */
	char    sAreaCode[5];		/* 区号 */
};

/*单个文件结构申明*/
struct FNsmsTicketStruct{

	char    sTicketTypeID[4];		/* 话单类型标识 */
	char    sCallType[2];		/* 呼叫类型 */
	char    sHomeAreaCode[5];		/* 用户归属号码 */
	char    sMsisdn[15];		/* 用户号码 */
	char    sCalledCode[5];		/* 如果为在信业务，则为前转网关归属地区区号 */
	char    sOtherParty[24];		/* 对端号码 */
	char    sStartTime[14];		/* 应答时间 */
	char    sMsgLen[4];		/* 消息长度 */
	char    sMsgID[30];		/* 消息ID */
	char    sOppMsgID[30];		/* 对端消息ID */
	char    sSubType[1];		/* 子业务类型 */
	char    sSmsc[15];		/* 短信中心 */
	char    sSmg[15];		/* 短信网关 */
	char    sTsmg[15];		/* 前转短信网关 */
	char    sUserType[1];		/* G,C */
	char    sCalledType[2];		/* 对端类型 */
	char    sSpAccNbr[12];		/* SP接入代码 */
	char    sSpServiceCode[10];		/* SP业务代码 */
	char    sSpCode[10];		/* SP代码 */
	char    sBaseFee[8];		/* 通信费 */
	char    sInfoFee[8];		/* 信息费 */
	char    sRentFee[8];		/* 包月费 */
	char    sOtherFee[8];		/* 其他费 */
	char    sInFee[8];		/* 结算收入 */
	char    sOutFee[8];		/* 结算支出 */
	char    sOriCallType[2];		/* 原呼叫类型 */
	char    sReserve[10];		/* 保留 */
	char    sSpProvCode[3];		/* SP归属省代码 */
	char    sHomeProvCode[3];		/* 用户归属省代码 */
	char    sScpFlag[1];		/* 智能网标志 */
	char    sCallingTypeID[4];		/* 用户号头类型 */
	char    sBillType[1];		/* 计费类型 */
	char    sErrCode[4];		/* 错误代码 */
	char    sFileName[19];		/* 文件名 */
	char    sModule[3];		/* 模块 */
	char    sAreaCode[5];		/* 区号 */
};

/*单个文件结构申明*/
struct FSmgTicketStruct{

	char    sMessageID[20];		/* 短消息标识 */
	char    sSmsType[1];		/* 短消息类型 */
	char    sSubType[1];		/* 短消息子类型 */
	char    sMsisdn[21];		/* 计费用户号码 */
	char    sSpCode[10];		/* SP号码 */
	char    sOtherParty[21];		/* 目的地号码 */
	char    sSpServiceCode[10];		/* 业务代码 */
	char    sBillType[2];		/* 用户计费类别 */
	char    sInfoFee[6];		/* 信息费 */
	char    sPriority[1];		/* 短消息发送优先级 */
	char    sMsgLen[3];		/* 信息长度 */
	char    sHomeAreaCode[4];		/* 计费号码归属地的区号 */
	char    sSmg[6];		/* SMGW代码 */
	char    sTsmg[6];		/* 前转SMGW代码 */
	char    sSmc[6];		/* 短消息中心代码 */
	char    sRecvDateTime[14];		/* 提交时间 */
	char    sDoneDateTime[14];		/* 处理结束时间 */
	char    sMsgID[20];		/* SMGW分配短消息标识 */
	char    sOppMsgID[20];		/* 异网之间的短消息标识 */
	char    sCallingNbr[21];		/* 主叫用户号码 */
	char    sTicketTypeID[4];		/* 话单类型 */
};
/*单个文件结构申明*/
struct FZnwTicketStruct{

	char    sTicketTypeID[4];		/* 话单类型 */
	char    sRecordType[2];		/* 记录类型(0x国家骨干智能网1x省智能网华为2x省智能网华为贝尔) */
	char    sStreamNumber[10];		/* 流水号 */
	char    sServiceKey[10];		/* 业务键 */
	char    sBillingMode[1];		/* 计费模式 */
	char    sChargeRecordID[8];		/* 计费记录标识 */
	char    sCallingNbr[24];		/* 主叫用户号码 */
	char    sCalledNbr[24];		/* 被叫用户号码 */
	char    sTranslatedNbr[24];		/* 目标地址号码号码 */
	char    sLocationNbr[10];		/* 位置号码 */
	char    sBillingFlag[4];		/* 计费用户标志 */
	char    sBillingNbr[24];		/* 规定的计费号码 */
	char    sStartTime[14];		/* 开始通话时间 */
	char    sStopTime[14];		/* 通话结束时间 */
	char    sDuration[9];		/* 通话时长 */
	char    sTotalFee[9];		/* 通话话费 */
	char    sBearCapability[2];		/* 承载能力 */
	char    sTariffClass[2];		/* 费率种类 */
	char    sBillType[4];		/* 计费号码属性 */
	char    sUserID[10];		/* 用户ID或批次信息 */
	char    sServiceNbr[28];		/* 业务号码 */
	char    sCount[8];		/* 计次数 */
	char    sBaseFee[9];		/* 基本费 */
	char    sBountyFee[9];		/* 奖励金额 */
	char    sAddFee[9];		/* 附加费 */
	char    sTransParam[30];		/* 透明参数 */
	char    sCallparttobecharger[32];		/* 计费部分 */
	char    sScpID[10];		/* scp序号 */
	char    sCauseOfCallend[4];		/* 通话结束原因 */
	char    sServiceModulator[4];		/* 业务折扣率 */
	char    sServiceType[2];		/* 业务类型 */
	char    sCardID[30];		/* 卡号 */
	char    sHomeAreaCode[5];		/* 主叫归属地 */
	char    sCalledCode[5];		/* 被叫归属地 */
	char    sBillingAreaCode[5];		/* 计费区号 */
	char    sCardAreaCode[5];		/* 发卡地区代码 */
	char    sDistanceType[1];		/* 呼叫类型 */
	char    sOriFileName[40];		/* 原始话单文件名 */
};
/*单个文件结构申明*/
struct FIccTicketStruct{

	char    sTicketTypeID[4];		/* 话单类型 */
	char    sRecordType[2];		/* 记录类型'20'出省漫游话单'21'省内话单(付费电话话单数据) */
	char    sProvinceCode[5];		/* 话务省代码 */
	char    sCallAreaCode[5];		/* 话务地区代码 */
	char    sCardID[30];		/* 卡号 */
	char    sCardProvinceCode[5];		/* 发卡省代码 */
	char    sCardAreaCode[5];		/* 发卡地区代码 */
	char    sCardAreaID[5];		/* 发卡县代码 */
	char    sCallingNbr[24];		/* 主叫号码 */
	char    sCalledNbr[24];		/* 被叫号码 */
	char    sBillingCycleID[6];		/* 归属帐期 */
	char    sStartTime[14];		/* 呼叫时间 */
	char    sDuration[9];		/* 呼叫时长 */
	char    sTotalFee[9];		/* 呼叫费用 */
	char    sServiceType[2];		/* 业务类型 */
	char    sDistanceType[1];		/* 通话类型 */
};
/*单个文件结构申明*/
struct FInfoAcctStruct{

	char    sTicketTypeID[4];		/* 话单类型 */
	char    sProvinceID[5];		/* 省代码 */
	char    sAreaCode[5];		/* 本地网代码 */
	char    sTotalCnt[9];		/* 记录总数 */
	char    sTotalFee[9];		/* 金额总数分 */
	char    sValidCnt[9];		/* 合帐记录总数 */
	char    sValidFee[9];		/* 合帐金额总数分 */
	char    sInvalidCnt[9];		/* 不能合帐记录总数 */
	char    sInvalidFee[9];		/* 不能合帐金额总数分 */
	char    sBillingCycleID[6];		/* 出帐月份 */
	char    sSpCode[20];		/* SP代码 */
	char    sFee[9];		/* 本期回收金额中本帐期费用 */
	char    sOweFee[9];		/* 本期回收金额中历史欠费 */
};

/*单个文件结构申明*/
struct FInfoNbrAcctStruct{

	char    sTicketTypeID[4];		/* 话单类型 */
	char    sRecordType[2];		
/* '00'无法合帐文件(各市到省)'01'详单文件(省到各市)'02'帐单文件(省中心到各市) */
	char    sCallingNbr[20];		/* 主叫号码 */
	char    sSpAccNbr[20];		/* 业务接入号码 */
	char    sSpServiceCode[20];		/* 使用的业务栏目编码 */
	char    sCnt[9];		/* 次数 */
	char    sDuration[9];		/* 时长秒 */
	char    sFee[9];		/* 金额分 */
	char    sStartTime[14];		/* 起始时间 */
	char    sCallingTypeID[4];		/* 号码类型 */
	char    sNetType[1];		/* 网络类型 */
	char    sNotes[60];		/* 备注 */
};
/*单个文件结构申明*/
struct FNxRhjfTicketStruct{

	char    sRecordType[2];		/* 话单记录标识 */
	char    sCallingRef[5];		/* 主叫字冠 */
	char    sCallingAreaCode[10];		/* 主叫区号 */
	char    sCallingNbr[20];		/* 主叫号码 */
	char    sCalledRef[5];		/* 被叫字冠 */
	char    sCalledCode[10];		/* 被叫区号 */
	char    sCalledNbr[20];		/* 被叫号码 */
	char    sUserType[2];		/* 用户类型 */
	char    sCallingCarrType[2];		/* 主叫运营商类型 */
	char    sCalledCarrType[2];		/* 被叫运营商类型 */
	char    sCalledAreaID[10];		/* 被叫区域代码 */
	char    sServiceType[1];		/* 业务类型 */
	char    sRouteType[1];		/* 路由类型 */
	char    sCardNbr[30];		/* 卡号 */
	char    sTrunkIn[10];		/* 入中继 */
	char    sTrunkOut[10];		/* 出中继 */
	char    sStartTime[14];		/* 通话起始时间 */
	char    sEndTime[14];		/* 通话终止时间 */
	char    sDuration[8];		/* 通话时长 */
	char    sChargeDuration[8];		/* 计费时长 */
	char    sBaseFee[12];		/* 基本费 */
	char    sDisctFee[12];		/* 优惠费 */
	char    sTotalFee[12];		/* 总费用 */
};


struct DupKeyStruct
{
	struct DupKeyStruct *pNext;
	
	char	sCallType[3];
	char    sMsisdn[16];
	char    sOtherParty[25];
	int     iDuration;
	char    sStartTime[15];
	void	*pData;
};

/*单个文件结构申明*/
struct FOldErrTicketStruct{

	char    sRecordType[1];		/* (B,二进制,T文本) */
	char    sCallType[2];		/* 呼叫类型 */
	char    sMsisdn[15];		/* 计费号码 */
	char    sOtherParty[24];		/* 对端号码 */
	char    sStartTime[14];		/* 通话起始时间 */
	char    sDuration[6];		/* 通话时长 */
	char    sImsi[15];		/* IMSI */
	char    sMsc[15];		/* 交换机 */
	char    sReserve1[20];		/* 保留1(业务相关) */
	char    sReserve2[20];		/* 保留2(业务相关) */
	char    sReserve3[30];		/* 保留3(业务相关) */
	char    sReserve4[30];		/* 保留4(业务相关) */
	char    sSourceID[6];		/* 采集来源 */
	char    sFileName[40];		/* 原始文件名 */
	char    sErrCode[4];		/* 错误代码 */
	char    sLine[8];		/* 错误文件行号 */
	char    sModule[3];		/* 业务类型(STTVIT等) */
	char    sState[1];		/* (0:生成,1:已回收,2:已处理) */
	char    sUpdateDate[14];		/* 回收或处理时间 */
	char    sDealDate[14];		/* 入库时间 */
	char    sErrRec[2048];		/* 二进制话单将翻译成ASCII，文本则为原始记录 */
};

/*单个文件结构申明*/
struct FErrTicketStruct{

	char    sRecordType[1];		/* (B,二进制,T文本) */
	char    sCallType[2];		/* 呼叫类型 */
	char    sMsisdn[15];		/* 计费号码 */
	char    sOtherParty[24];		/* 对端号码 */
	char    sStartTime[14];		/* 通话起始时间 */
	char    sDuration[6];		/* 通话时长 */
	char    sImsi[15];		/* IMSI */
	char    sMsc[15];		/* 交换机 */
	char    sReserve1[20];		/* 保留1(业务相关) */
	char    sReserve2[20];		/* 保留2(业务相关) */
	char    sReserve3[30];		/* 保留3(业务相关) */
	char    sReserve4[30];		/* 保留4(业务相关) */
	char    sOriSourceID[6];		/* 采集来源 */
	char    sOriFileName[40];		/* 原始文件名 */
	char    sLine[8];		/* 错误文件行号 */
	char    sErrCode[4];		/* 错误代码 */
	char    sFileName[19];		/* 回收输出文件名 */
	char    sModule[3];		/* 业务类型(STTVIT等) */
	char    sAreaCode[5];		/* 区号 */
	char    sState[1];		/* (0:生成,1:已回收,2:已处理) */
	char    sErrRec[2048];		/* 二进制话单将翻译成ASCII，文本则为原始记录 */
};

#endif
