#ifndef __TICKET_H__
#define __TICKET_H__

/*�����ļ��ṹ����*/
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
/*�����ļ��ṹ����*/
struct FSttTicketStruct{

	char    sTicketTypeID[4];		/* ������� */
	char    sCallType[2];		/* ������� */
	char    sMsisdn[15];		/* �û����� */
	char    sCalledCode[5];		/* �Զ����� */
	char    sOtherParty[24];		/* �Զ˺��� */
	char    sVisitAreaCode[5];		/* ������������� */
	char    sRoamFee[5];		/* ����ͨ���� */
	char    sTollFee[7];		/* ��;�� */
	char    sAddFee[5];		/* ������ */
	char    sDuration[6];		/* ʱ�� */
	char    sStartTime[14];		/* ͨ����ʼʱ�� */
	char    sHomeAreaCode[5];		/* �û������� */
	char    sRoamType[1];		/* ������� */
	char    sDistanceType[1];		/* λ����� */
	char    sOppType[1];		/* �Զ���� */
	char    sUserType[1];		/* �û���� */
	char    sSplitRuleID[4];		/* ���������ʶ */
	char    sOppRoamType[1];		/* �Զ�������� */
	char    sServiceType[3];		/* ҵ������ */
	char    sServiceCode[4];		/* ҵ����� */
	char    sImsi[15];		/* �û�IMSI */
	char    sMsc[15];		/* ��������ʶ */
	char    sLac[5];		/* С���� */
	char    sCellID[5];		/* ���Ѻ� */
	char    sOtherLac[5];		/* С���� */
	char    sOtherCellID[5];	/* ���Ѻ� */
	char    sTrunkIn[7];		/* ���м� */
	char    sTrunkOut[7];		/* ���м� */
	char    sThirdParty[15];		/* ���������� */
	char    sMsrn[12];		/* ��̬���κ� */
	char    sTrunkInTypeID[4];		/* ���м���� */
	char    sTrunkOutTypeID[4];		/* ���м���� */
	char    sTrunkInCarrierID[4];		/* ���м���Ӫ�� */
	char    sTrunkOutCarrierID[4];		/* ���м���Ӫ�� */
	char    sTrunkInType[1];		/* ���м̳�;���ͱ�ʶ */
	char    sTrunkOutType[1];		/* ���м̳�;���ͱ�ʶ */
	char    sCallingCarrierID[4];		/* ���к�ͷ��Ӫ�� */
	char    sCalledCarrierID[4];		/* ���к�ͷ��Ӫ�� */
	char    sCallingTypeID[4];		/* �������ͱ�ʶ */
	char    sCalledTypeID[4];		/* �������ͱ�ʶ */
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
/*�����ļ��ṹ����*/
struct FT193TicketStruct{

	char    sCallType[2];		/* CALL_TYPE */
	char    sMsisdn[20];		/* �û����� */
	char    sOtherParty[20];		/* �Զ˺��� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sDuration[6];		/* ͨ��ʱ�� */
	char    sMsc[10];		/* MSC */
	char    sTrunkIn[8];		/* ���м� */
	char    sTrunkOut[8];		/* ���м� */
	char    sCallingAreaCode[5];		/* �û����� */
	char    sCalledAreaCode[5];		/* �Զ����� */
};
struct FSmscTicketStruct{
	char    sCallType[2];		/* �������� */
	char    sCityCode[5];		/* ������д��� */
	char    sMsisdn[15];		/* �û����� */
	char    sOtherParty[24];		/* �Զ˺��� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sDuration[6];		/* ͨ��ʱ�� */
	char    sMsc[15];		/* �������� */
	char    sSmsp[15];		/* �������� */
	char    sUserType[1];		/* �û����� */
	char    sFee[6];		/* ���� */
	char    sServiceCode[4];	/* ҵ����� */
	char	sTicketTypeID[4];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*�����ļ��ṹ����*/
struct FSmspTicketStruct{

	char    sCallType[2];		/* �������� */
	char    sCityCode[5];		/* ������д��� */
	char    sMsisdn[15];		/* �û����� */
	char    sOtherParty[24];		/* �Զ˺��� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sDuration[6];		/* �ֽ��� */
	char    sMsc[15];		/* �������� */
	char    sSmsp[15];		/* �������� */
	char    sUserType[1];		/* �û����� */
	char    sSpAccNbr[12];		/* SP������� */
	char    sSpServiceCode[10];		/* SPҵ����� */
	char    sSpCode[5];		/* SP���� */
	char    sFee1[6];		/* ����1 */
	char    sFee2[6];		/* ����2 */
	char    sFee3[6];		/* ����3 */
	char    sFee4[6];		/* ����4 */  
	char	sFee5[8];		/* ����5 */
	char	sFee6[8];		/* ����6 */
	char	sTicketTypeID[4];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*�����ļ��ṹ����*/
struct FGprsTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sNiPdp[1];		/* ����෢��PDP�����ĵı�־ */
	char    sMsisdn[15];		/* �û����� */
	char    sImsi[15];		/* IMSI���� */
	char    sSgsn[8];		/* SGSN���� */
	char    sMsnc[1];		/* �ֻ����������� */
	char    sLac[4];		/* LAC */
	char    sRouteArea[4];		/* ·������ */
	char    sCellID[4];		/* CELL_ID */
	char    sChargingID[8];		/* PDP�����ĵļƷѱ�ʶ */
	char    sGgsn[8];		/* GGSN */
	char    sApnNi[63];		/* APN�������ʶ */
	char    sApnOi[37];		/* APN����Ӫ�̱�ʶ */
	char    sPdpType[1];		/* PDP���� */
	char    sServedPdpAddress[16];	/* �ն˵�PDP��ַ */
	char    sSgsnChange[1];		/* SGSN�л���ʶ */
	char    sCloseCause[1];		/* ��¼��ֹԭ�� */
	char    sResult[1];		/* "S"���ϲ��ɹ�;"F"��Ҫ��һ���ϲ�;"N"���ϲ��������� */
	char    sHomeAreaCode[9];	/* �û��������� */
	char    sVisitAreaCode[9];	/* �û��ݷ� */
	char    sUserType[2];		/* "00" ��ͨ�û�;"01" Ԥ�����û�;"02" �����û� */
	char    sFeeType[2];		/* �������� */
	char    sRoamType[1];		/* �������� */
	char    sServiceType[3];	/* �������� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sCallDuration[6];	/* ���г���ʱ�� */
	char    sTariff1[1];		/* �ʷ�1 */
	char    sDataFlowup1[10];	/* ��������1 */
	char    sDataFlowdn1[10];	/* ��������1 */
	char    sDuration1[6];		/* ����ʱ��1 */
	char    sTariff2[1];		/* �ʷ�2 */
	char    sDataFlowup2[10];		/* ��������2 */
	char    sDataFlowdn2[10];		/* ��������2 */
	char    sDuration2[6];		/* ����ʱ��2 */
	char    sTariff3[1];		/* �ʷ�3 */
	char    sDataFlowup3[10];		/* ��������3 */
	char    sDataFlowdn3[10];		/* ��������3 */
	char    sDuration3[6];		/* ����ʱ��3 */
	char    sTariff4[1];		/* �ʷ�4 */
	char    sDataFlowup4[10];		/* ��������4 */
	char    sDataFlowdn4[10];		/* ��������4 */
	char    sDuration4[6];		/* ����ʱ��4 */
	char    sTariff5[1];		/* �ʷ�5 */
	char    sDataFlowup5[10];		/* ��������5 */
	char    sDataFlowdn5[10];		/* ��������5 */
	char    sDuration5[6];		/* ����ʱ��5 */
	char    sTariff6[1];		/* �ʷ�6 */
	char    sDataFlowup6[10];		/* ��������6 */
	char    sDataFlowdn6[10];		/* ��������6 */
	char    sDuration6[6];		/* ����ʱ��6 */
	char    sCfee[8];		/* ����ͨ�ŷ� */
	char    sFee1[8];		/* ����1 */
	char    sFee2[8];		/* ����2 */
	char    sFee3[8];		/* ����3 */
	char    sTotalFee[9];		/* �ܷ��� */
	char	sTicketTypeID[4];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};
/*�����ļ��ṹ����*/
struct FCdmaTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sMsisdn[15];		/* �û����� */
	char    sImsi[15];		/* IMSI */
	char    sEsn[15];		/* �������к� */
	char    sOtherParty[21];		/* �Զ˺��� */
	char    sMsrn[15];		/* MSRN */
	char    sThirdParty[21];		/* ���������� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sDuration[6];		/* ʱ�� */
	char    sMsc[10];		/* ������ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* �Զ�LAC */
	char    sOtherCellID[5];		/* �Զ�CELL_ID */
	char    sAppendServiceCode[2];		/* ��ֵҵ�� */
	char    sEndReason[1];		/* ����ԭ�� */
	char    sDeformityFlag[1];		/* ��ȱ��־ */
	char    sRoamFee[8];		/* ������ */
	char    sRoamDuration[6];		/* �����Ʒ�ʱ�� */
	char    sRoamRateType[1];		/* ��������ʱ�ʶ */
	char    sTollFee[8];		/* ��;�� */
	char    sTollDuration[6];		/* ��;�Ʒ�ʱ�� */
	char    sTollFeeType[1];		/* ��;����ʱ�ʶ */
	char    sInfoFee[8];		/* ��Ϣ�� */
	char    sOtherFee[8];		/* ������ */
	char    sOppCityCode[3];		/* �Զ˹������д��� */
	char    sOppProvCode[3];		/* �Զ˹���ʡ���� */
	char    sOppCountryCode[3];		/* �Զ����ڹ����� */
	char    sTollType[1];		/* ��;���� */
	char    sTollNetType[1];		/* ��;������ */
	char    sRoamType[1];		/* �������� */
	char    sVisitCityCode[3];		/* ͨ���س��д��� */
	char    sTrunkIn[8];		/* ���м� */
	char    sTrunkOut[8];		/* ���м� */
	char    sUserType[1];		/* �û����� */
	char    sActCode[1];		/* ����� */
	char    sServiceCode[2];		/* ҵ����� */
	char	sCalledType[3];
	char	sHomeAreaCode[10];
	char	sUserType1[2];
	char	sReserve[18];
};
/*�����ļ��ṹ����*/
struct FCdmaTicketFjStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sMsisdn[11];		/* �û����� */
	char    sImsi[15];		/* IMSI */
	char    sEsn[11];		/* �������к� */
	char    sOtherParty[21];		/* �Զ˺��� */
	char    sMsrn[15];		/* MSRN */
	char    sThirdParty[21];		/* ���������� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sDuration[6];		/* ʱ�� */
	char    sMsc[10];		/* ������ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* �Զ�LAC */
	char    sOtherCellID[5];		/* �Զ�CELL_ID */
	char    sAppendServiceCode[2];		/* ��ֵҵ�� */
	char    sEndReason[1];		/* ����ԭ�� */
	char    sDeformityFlag[1];		/* ��ȱ��־ */
	char    sRoamFee[8];		/* ������ */
	char    sRoamDuration[6];		/* �����Ʒ�ʱ�� */
	char    sRoamRateType[1];		/* ��������ʱ�ʶ */
	char    sTollFee[8];		/* ��;�� */
	char    sTollDuration[6];		/* ��;�Ʒ�ʱ�� */
	char    sTollFeeType[1];		/* ��;����ʱ�ʶ */
	char    sInfoFee[8];		/* ��Ϣ�� */
	char    sOtherFee[8];		/* ������ */
	char    sOppCityCode[3];		/* �Զ˹������д��� */
	char    sOppProvCode[3];		/* �Զ˹���ʡ���� */
	char    sOppCountryCode[3];		/* �Զ����ڹ����� */
	char    sTollType[1];		/* ��;���� */
	char    sTollNetType[1];		/* ��;������ */
	char    sRoamType[1];		/* �������� */
	char    sVisitCityCode[3];		/* ͨ���س��д��� */
	char    sTrunkIn[8];		/* ���м� */
	char    sTrunkOut[8];		/* ���м� */
	char    sUserType[1];		/* �û����� */
	char    sActCode[1];		/* ����� */
	char    sServiceCode[2];		/* ҵ����� */
};
/*�����ļ��ṹ����*/
struct FCdmaTicketXjStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sMsisdn[11];		/* �û����� */
	char    sImsi[15];		/* IMSI */
	char    sEsn[11];		/* �������к� */
	char    sOtherParty[21];		/* �Զ˺��� */
	char    sMsrn[15];		/* MSRN */
	char    sThirdParty[21];		/* ���������� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sDuration[6];		/* ʱ�� */
	char    sMsc[10];		/* ������ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* �Զ�LAC */
	char    sOtherCellID[5];		/* �Զ�CELL_ID */
	char    sAppendServiceCode[2];		/* ��ֵҵ�� */
	char    sEndReason[1];		/* ����ԭ�� */
	char    sDeformityFlag[1];		/* ��ȱ��־ */
	char    sRoamFee[8];		/* ������ */
	char    sRoamDuration[6];		/* �����Ʒ�ʱ�� */
	char    sRoamRateType[1];		/* ��������ʱ�ʶ */
	char    sTollFee[8];		/* ��;�� */
	char    sTollDuration[6];		/* ��;�Ʒ�ʱ�� */
	char    sTollFeeType[1];		/* ��;����ʱ�ʶ */
	char    sInfoFee[8];		/* ��Ϣ�� */
	char    sOtherFee[8];		/* ������ */
	char    sOppCityCode[3];		/* �Զ˹������д��� */
	char    sOppProvCode[3];		/* �Զ˹���ʡ���� */
	char    sOppCountryCode[3];		/* �Զ����ڹ����� */
	char    sTollType[1];		/* ��;���� */
	char    sTollNetType[1];		/* ��;������ */
	char    sRoamType[1];		/* �������� */
	char    sVisitCityCode[3];		/* ͨ���س��д��� */
	char    sUserType[1];		/* �û����� */
	char    sActCode[1];		/* ����� */
	char    sServiceCode[2];		/* ҵ����� */
};
/*�����ļ��ṹ����*/
struct FCdma1xTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sSeqNumber[10];		/* ���к��� */
	char    sMdn[20];		/* �û��ֻ��� */
	char    sMsisdn[15];		/* MSISDN */
	char    sEsn[19];		/* �ֻ��豸���� */
	char    sIp[15];		/* IP */
	char    sNai[64];		/* �û�����ҵ���˺� */
	char    sUserType[1];		/* �û���� */
	char    sNaiAreaCode[3];		/* ��ͨ���д��� */
	char    sRoamType[1];		/* �������:0�����أ�1��ʡ�����룻2��ʡ������;3���������룻
4������������ȱʡ����IMSI ���������жϣ� */
	char    sIpTechType[1];		/* IP��� */
	char    sAccountSessionID[8];		/* ��ʶһ���Ự���� */
	char    sCorrelationID[8];		/* ��ʶһ��PPP ���� */
	char    sHaip[15];		/* HA ��IP ��ַ */
	char    sPdsnip[15];		/* pdsnip */
	char    sPcfip[15];		/* ʹ��PCF ��ַ */
	char    sBsid[12];		/* SID NID BSC ID */
	char    sUzid[10];		/* �û����������ʶ */
	char    sServiceOption[2];		/* �̶�Ϊ33 */
	char    sCompulsoryTunnel[1];		/* ǿ��������� */
	char    sEndRelease[1];		/* ����Accounting stop ��ԭ�� */
	char    sDataCountTermination[10];		/* ���͸��û����ֽ��� */
	char    sDataCountOrigination[10];		/* �û�������ֽ��� */
	char    sBadFrameCount[10];		/* ��PDSN �����Ļ�֡ */
	char    sStartTime[14];		/* �Ự��ʼ��ʱ��� */
	char    sStopTime[14];		/* �Ự������ʱ��� */
	char    sActiveTime[10];		/* �Ựʱ�� */
	char    sActionCount[10];		/* ת������ */
	char    sSdbCountTermination[10];		/* �û�SDB�����ֽ��� */
	char    sSdbCountOrigination[10];		/* �û�SDB�����ֽ��� */
	char    sSdbTerminationnum[10];		/* �û�����SDB���� */
	char    sSdbOriginationnum[10];		/* �û�����SDB���� */
	char    sPdsnReceiveNum[10];		/* PDSN �յ���HDLC */
	char    sMipReceiveNum[10];		/* �û�����MIP �����ֽ� */
	char    sMipSendNum[10];		/* �û�����MIP �����ֽ� */
	char    sIpqos[10];		/* IP �����û������ȼ��� */
	char    sAirlinkqos[10];		/* ������·�����ȼ��� */
	char    sBaseCharge[8];		/* ������ */
	char    sFluxCharge[8];		/* ������ */
	char    sOtherCharge[8];		/* �������� */
	char    sHomeCountryCode[5];		/* �����س��д��� */
	char    sHomeOperatorCode[5];		/* ��������Ӫ�̴��� */
	char    sVisitCountryCode[5];		/* ���εس��д��� */
	char    sVisitOperatoCode[5];		/* ���ε���Ӫ�̴��� */
	char    sRatingRuleID[8];		/* �ʷѹ����ʶ */
	char    sNoused1[10];		/* ϵͳ���� */
	char    sNoused2[10];		/* ϵͳ����2 */
	char    sNoused3[10];		/* ϵͳ����3 */
	char	sTicketTypeID[4];
	char	sHomeAreaCode[5];
	char	sErrCode[4];
	char	sFileName[19];
	char	sModule[3];
	char	sAreaCode[5];
};

/*�����ļ��ṹ����*/
struct FGsmRateTicketStruct{

	char    sTicketID[10];		/* �������к� */
	char    sMsisdn[15];		/* �ֻ����� */
	char    sImsi[15];		/* Imsi���� */
	char    sCityCode[4];		/* ���д��� */
	char    sMonth[2];		/* �·� */
	char    sBillMonth[6];		/* �Ʒ��·� */
	char    sCallType[2];		/* �������� */
	char    sStartTime[14];		/* �������� */
	char    sEndReason[1];		/* ����ԭ�� */
	char    sDeformFlag[1];		/* ��ȱ��־ */
	char    sOtherParty[21];		/* �Զ˺��� */
	char    sCalledCode[4];		/* �Է��������� */
	char    sDuration[6];		/* ͨ��ʱ�� */
	char    sMsc[10];		/* ���������� */
	char    sCellID[5];		/* ��վ�� */
	char    sOtherCellID[5];		/* �Է���վ�� */
	char    sTrunkIn[7];		/* ���м� */
	char    sTrunkOut[7];		/* ���м� */
	char    sTollType[1];		/* ��;���� */
	char    sRoamType[1];		/* �������� */
	char    sTollNetType[1];		/* ��;������ */
	char    sValueAddBusi[2];		/* ��ֵҵ�� */
	char    sGroupID[5];		/* �պ��û�ȺID */
	char    sSameGroupFlag[1];		/* ˫����ͬһ�պ��û�Ⱥ */
	char    sHomeProvCode[3];		/* ������ */
	char    sVisitCityCode[3];		/* ���ξ� */
	char    sThirdParty[15];		/* B���� */
	char    sBusiType[1];		/* ͨ��/����ҵ����� */
	char    sBusiCode[2];		/* ͨ��/����ҵ����� */
	char    sBaseFee[10];		/* ������ */
	char    sTollFee[10];		/* ��;�� */
	char    sTollAddFee[10];		/* ������ */
	char    sOtherFee[10];		/* ������ */
	char    sRoamFee[10];		/* ���η� */
	char    sAddFee[10];		/* ���ӷ� */
	char    sDisctBaseFee[10];		/* �Żݻ����� */
	char    sDisctTollFee[10];		/* �Żݳ�;�� */
	char    sDisctTollAddFee[10];		/* �Żݳ����� */
	char    sDisctOtherFee[10];		/* �Ż������� */
	char    sSupplementActiveCode[1];		/* ����ҵ���� */
	char    sSupplementCode[2];		/* ����ҵ���� */
	char    sFileSeq[8];		/* �ļ��� */
	char    sCalledType[3];		/* Called_type */
	char    sHomeAreaCode[10];		/* Home_area_code */
	char    sLac[5];		/* lac */
	char    sUserType[2];		/* User_type */
	char    sReserve[18];		/* �����ֶ� */
};
/*�����ļ��ṹ����*/
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
/*�����ļ��ṹ����*/
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
/*�����ļ��ṹ����*/
struct FSmsupIntfTicketStruct{

	char    sRecordType[2];		/* ���ݼ�¼��ʾ */
	char    sMsgType[3];		/* ��Ϣ���� */
	char    sSpProvCode[3];		/* SP����ʡ���� */
	char    sSmg[5];		/* SP����SMG���� */
	char    sSpCode[5];		/* SP���� */
	char    sFwSmg[5];		/* ǰת���ش��� */
	char    sFwSmgProv[3];		/* ǰת����ʡ���� */
	char    sMinStartTime[14];		/* ���λ��������¼ʱ�� */
	char    sMaxStartTime[14];		/* ���λ��������¼ʱ�� */
	char    sMoCnt1[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MO/MO-F������ */
	char    sMoCnt2[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MO/MO-F�������� */
	char    sMfCnt1[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MT/MT-F������ */
	char    sMfCnt2[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���MT/MT-F�������� */
	char    sFee1[12];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĽ����ܷ��� */
	char    sFee2[12];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĽ����ܷ��� */
	char    sHomeProvCode[3];		/* �Ʒ��û�����ʡ���� */
	char    sRoamFee1[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ�ͨ�ŷ��ܷ��� */
	char    sRoamFee2[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ�ͨ���ܷ��� */
	char    sInfoFee1[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���Ϣ���ܷ��� */
	char    sInfoFee2[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵ���Ϣ���ܷ��� */
	char    sRoamNfee1[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĲ�����ͨ�ŷ��ܷ��� */
	char    sRoamNfee2[10];		/* �ֹ�˾���ʺ��ȫ��SP/CPӦ�������ݵĲ�����ͨ���ܷ��� */
	char    sReserve1[20];		/* ����1 */
};
/*�����ļ��ṹ����*/
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

/*�����ļ��ṹ����*/
struct FSmsTicketStruct{

	char    sTicketTypeID[4];	/* �������ͱ�ʶ */
	char    sCallType[2];		/* �������� */
	char    sHomeAreaCode[5];	/* �û��������� */
	char    sMsisdn[15];		/* �û����� */
	char    sCalledCode[5];		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    sOtherParty[24];	/* �Զ˺��� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sMsgLen[4];		/* ��Ϣ���� */
	char    sMsgID[30];		/* ��ϢID */
	char    sSmsc[15];		/* �������� */
	char    sSmg[15];		/* �������� */
	char    sTsmg[15];		/* ǰת�������� */
	char    sUserType[1];		/* G,C */
	char    sCalledType[2];		/* �Զ����� */
	char	sSpAccNbr[12];		/* SP������� */
	char    sSpServiceCode[10];	/* SPҵ����� */
	char    sSpCode[5];		/* SP���� */
	char    sBaseFee[8];		/* ͨ�ŷ� */
	char    sInfoFee[8];		/* ��Ϣ�� */
	char    sRentFee[8];		/* ���·� */
	char    sOtherFee[8];		/* ������ */
	char    sInFee[8];		/* �������� */
	char    sOutFee[8];		/* ����֧�� */
	char	sOriCallType[2];
	char	sReserve[10];
	char	sSpProvCode[3];
	char	sHomeProvCode[3];
	char	sScpFlag[1];
	char    sCallingTypeID[4];
	char	sBillType[1];
	char    sErrCode[4];		/* ������� */
	char    sFileName[19];		/* �ļ��� */
	char    sModule[3];		/* ģ�� */
	char    sAreaCode[5];		/* ���� */
};

/*�����ļ��ṹ����*/
struct FNsmsTicketStruct{

	char    sTicketTypeID[4];		/* �������ͱ�ʶ */
	char    sCallType[2];		/* �������� */
	char    sHomeAreaCode[5];		/* �û��������� */
	char    sMsisdn[15];		/* �û����� */
	char    sCalledCode[5];		/* ���Ϊ����ҵ����Ϊǰת���ع����������� */
	char    sOtherParty[24];		/* �Զ˺��� */
	char    sStartTime[14];		/* Ӧ��ʱ�� */
	char    sMsgLen[4];		/* ��Ϣ���� */
	char    sMsgID[30];		/* ��ϢID */
	char    sOppMsgID[30];		/* �Զ���ϢID */
	char    sSubType[1];		/* ��ҵ������ */
	char    sSmsc[15];		/* �������� */
	char    sSmg[15];		/* �������� */
	char    sTsmg[15];		/* ǰת�������� */
	char    sUserType[1];		/* G,C */
	char    sCalledType[2];		/* �Զ����� */
	char    sSpAccNbr[12];		/* SP������� */
	char    sSpServiceCode[10];		/* SPҵ����� */
	char    sSpCode[10];		/* SP���� */
	char    sBaseFee[8];		/* ͨ�ŷ� */
	char    sInfoFee[8];		/* ��Ϣ�� */
	char    sRentFee[8];		/* ���·� */
	char    sOtherFee[8];		/* ������ */
	char    sInFee[8];		/* �������� */
	char    sOutFee[8];		/* ����֧�� */
	char    sOriCallType[2];		/* ԭ�������� */
	char    sReserve[10];		/* ���� */
	char    sSpProvCode[3];		/* SP����ʡ���� */
	char    sHomeProvCode[3];		/* �û�����ʡ���� */
	char    sScpFlag[1];		/* ��������־ */
	char    sCallingTypeID[4];		/* �û���ͷ���� */
	char    sBillType[1];		/* �Ʒ����� */
	char    sErrCode[4];		/* ������� */
	char    sFileName[19];		/* �ļ��� */
	char    sModule[3];		/* ģ�� */
	char    sAreaCode[5];		/* ���� */
};

/*�����ļ��ṹ����*/
struct FSmgTicketStruct{

	char    sMessageID[20];		/* ����Ϣ��ʶ */
	char    sSmsType[1];		/* ����Ϣ���� */
	char    sSubType[1];		/* ����Ϣ������ */
	char    sMsisdn[21];		/* �Ʒ��û����� */
	char    sSpCode[10];		/* SP���� */
	char    sOtherParty[21];		/* Ŀ�ĵغ��� */
	char    sSpServiceCode[10];		/* ҵ����� */
	char    sBillType[2];		/* �û��Ʒ���� */
	char    sInfoFee[6];		/* ��Ϣ�� */
	char    sPriority[1];		/* ����Ϣ�������ȼ� */
	char    sMsgLen[3];		/* ��Ϣ���� */
	char    sHomeAreaCode[4];		/* �ƷѺ�������ص����� */
	char    sSmg[6];		/* SMGW���� */
	char    sTsmg[6];		/* ǰתSMGW���� */
	char    sSmc[6];		/* ����Ϣ���Ĵ��� */
	char    sRecvDateTime[14];		/* �ύʱ�� */
	char    sDoneDateTime[14];		/* �������ʱ�� */
	char    sMsgID[20];		/* SMGW�������Ϣ��ʶ */
	char    sOppMsgID[20];		/* ����֮��Ķ���Ϣ��ʶ */
	char    sCallingNbr[21];		/* �����û����� */
	char    sTicketTypeID[4];		/* �������� */
};
/*�����ļ��ṹ����*/
struct FZnwTicketStruct{

	char    sTicketTypeID[4];		/* �������� */
	char    sRecordType[2];		/* ��¼����(0x���ҹǸ�������1xʡ��������Ϊ2xʡ��������Ϊ����) */
	char    sStreamNumber[10];		/* ��ˮ�� */
	char    sServiceKey[10];		/* ҵ��� */
	char    sBillingMode[1];		/* �Ʒ�ģʽ */
	char    sChargeRecordID[8];		/* �ƷѼ�¼��ʶ */
	char    sCallingNbr[24];		/* �����û����� */
	char    sCalledNbr[24];		/* �����û����� */
	char    sTranslatedNbr[24];		/* Ŀ���ַ������� */
	char    sLocationNbr[10];		/* λ�ú��� */
	char    sBillingFlag[4];		/* �Ʒ��û���־ */
	char    sBillingNbr[24];		/* �涨�ļƷѺ��� */
	char    sStartTime[14];		/* ��ʼͨ��ʱ�� */
	char    sStopTime[14];		/* ͨ������ʱ�� */
	char    sDuration[9];		/* ͨ��ʱ�� */
	char    sTotalFee[9];		/* ͨ������ */
	char    sBearCapability[2];		/* �������� */
	char    sTariffClass[2];		/* �������� */
	char    sBillType[4];		/* �ƷѺ������� */
	char    sUserID[10];		/* �û�ID��������Ϣ */
	char    sServiceNbr[28];		/* ҵ����� */
	char    sCount[8];		/* �ƴ��� */
	char    sBaseFee[9];		/* ������ */
	char    sBountyFee[9];		/* ������� */
	char    sAddFee[9];		/* ���ӷ� */
	char    sTransParam[30];		/* ͸������ */
	char    sCallparttobecharger[32];		/* �ƷѲ��� */
	char    sScpID[10];		/* scp��� */
	char    sCauseOfCallend[4];		/* ͨ������ԭ�� */
	char    sServiceModulator[4];		/* ҵ���ۿ��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sCardID[30];		/* ���� */
	char    sHomeAreaCode[5];		/* ���й����� */
	char    sCalledCode[5];		/* ���й����� */
	char    sBillingAreaCode[5];		/* �Ʒ����� */
	char    sCardAreaCode[5];		/* ������������ */
	char    sDistanceType[1];		/* �������� */
	char    sOriFileName[40];		/* ԭʼ�����ļ��� */
};
/*�����ļ��ṹ����*/
struct FIccTicketStruct{

	char    sTicketTypeID[4];		/* �������� */
	char    sRecordType[2];		/* ��¼����'20'��ʡ���λ���'21'ʡ�ڻ���(���ѵ绰��������) */
	char    sProvinceCode[5];		/* ����ʡ���� */
	char    sCallAreaCode[5];		/* ����������� */
	char    sCardID[30];		/* ���� */
	char    sCardProvinceCode[5];		/* ����ʡ���� */
	char    sCardAreaCode[5];		/* ������������ */
	char    sCardAreaID[5];		/* �����ش��� */
	char    sCallingNbr[24];		/* ���к��� */
	char    sCalledNbr[24];		/* ���к��� */
	char    sBillingCycleID[6];		/* �������� */
	char    sStartTime[14];		/* ����ʱ�� */
	char    sDuration[9];		/* ����ʱ�� */
	char    sTotalFee[9];		/* ���з��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sDistanceType[1];		/* ͨ������ */
};
/*�����ļ��ṹ����*/
struct FInfoAcctStruct{

	char    sTicketTypeID[4];		/* �������� */
	char    sProvinceID[5];		/* ʡ���� */
	char    sAreaCode[5];		/* ���������� */
	char    sTotalCnt[9];		/* ��¼���� */
	char    sTotalFee[9];		/* ��������� */
	char    sValidCnt[9];		/* ���ʼ�¼���� */
	char    sValidFee[9];		/* ���ʽ�������� */
	char    sInvalidCnt[9];		/* ���ܺ��ʼ�¼���� */
	char    sInvalidFee[9];		/* ���ܺ��ʽ�������� */
	char    sBillingCycleID[6];		/* �����·� */
	char    sSpCode[20];		/* SP���� */
	char    sFee[9];		/* ���ڻ��ս���б����ڷ��� */
	char    sOweFee[9];		/* ���ڻ��ս������ʷǷ�� */
};

/*�����ļ��ṹ����*/
struct FInfoNbrAcctStruct{

	char    sTicketTypeID[4];		/* �������� */
	char    sRecordType[2];		
/* '00'�޷������ļ�(���е�ʡ)'01'�굥�ļ�(ʡ������)'02'�ʵ��ļ�(ʡ���ĵ�����) */
	char    sCallingNbr[20];		/* ���к��� */
	char    sSpAccNbr[20];		/* ҵ�������� */
	char    sSpServiceCode[20];		/* ʹ�õ�ҵ����Ŀ���� */
	char    sCnt[9];		/* ���� */
	char    sDuration[9];		/* ʱ���� */
	char    sFee[9];		/* ���� */
	char    sStartTime[14];		/* ��ʼʱ�� */
	char    sCallingTypeID[4];		/* �������� */
	char    sNetType[1];		/* �������� */
	char    sNotes[60];		/* ��ע */
};
/*�����ļ��ṹ����*/
struct FNxRhjfTicketStruct{

	char    sRecordType[2];		/* ������¼��ʶ */
	char    sCallingRef[5];		/* �����ֹ� */
	char    sCallingAreaCode[10];		/* �������� */
	char    sCallingNbr[20];		/* ���к��� */
	char    sCalledRef[5];		/* �����ֹ� */
	char    sCalledCode[10];		/* �������� */
	char    sCalledNbr[20];		/* ���к��� */
	char    sUserType[2];		/* �û����� */
	char    sCallingCarrType[2];		/* ������Ӫ������ */
	char    sCalledCarrType[2];		/* ������Ӫ������ */
	char    sCalledAreaID[10];		/* ����������� */
	char    sServiceType[1];		/* ҵ������ */
	char    sRouteType[1];		/* ·������ */
	char    sCardNbr[30];		/* ���� */
	char    sTrunkIn[10];		/* ���м� */
	char    sTrunkOut[10];		/* ���м� */
	char    sStartTime[14];		/* ͨ����ʼʱ�� */
	char    sEndTime[14];		/* ͨ����ֹʱ�� */
	char    sDuration[8];		/* ͨ��ʱ�� */
	char    sChargeDuration[8];		/* �Ʒ�ʱ�� */
	char    sBaseFee[12];		/* ������ */
	char    sDisctFee[12];		/* �Żݷ� */
	char    sTotalFee[12];		/* �ܷ��� */
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

/*�����ļ��ṹ����*/
struct FOldErrTicketStruct{

	char    sRecordType[1];		/* (B,������,T�ı�) */
	char    sCallType[2];		/* �������� */
	char    sMsisdn[15];		/* �ƷѺ��� */
	char    sOtherParty[24];		/* �Զ˺��� */
	char    sStartTime[14];		/* ͨ����ʼʱ�� */
	char    sDuration[6];		/* ͨ��ʱ�� */
	char    sImsi[15];		/* IMSI */
	char    sMsc[15];		/* ������ */
	char    sReserve1[20];		/* ����1(ҵ�����) */
	char    sReserve2[20];		/* ����2(ҵ�����) */
	char    sReserve3[30];		/* ����3(ҵ�����) */
	char    sReserve4[30];		/* ����4(ҵ�����) */
	char    sSourceID[6];		/* �ɼ���Դ */
	char    sFileName[40];		/* ԭʼ�ļ��� */
	char    sErrCode[4];		/* ������� */
	char    sLine[8];		/* �����ļ��к� */
	char    sModule[3];		/* ҵ������(STTVIT��) */
	char    sState[1];		/* (0:����,1:�ѻ���,2:�Ѵ���) */
	char    sUpdateDate[14];		/* ���ջ���ʱ�� */
	char    sDealDate[14];		/* ���ʱ�� */
	char    sErrRec[2048];		/* �����ƻ����������ASCII���ı���Ϊԭʼ��¼ */
};

/*�����ļ��ṹ����*/
struct FErrTicketStruct{

	char    sRecordType[1];		/* (B,������,T�ı�) */
	char    sCallType[2];		/* �������� */
	char    sMsisdn[15];		/* �ƷѺ��� */
	char    sOtherParty[24];		/* �Զ˺��� */
	char    sStartTime[14];		/* ͨ����ʼʱ�� */
	char    sDuration[6];		/* ͨ��ʱ�� */
	char    sImsi[15];		/* IMSI */
	char    sMsc[15];		/* ������ */
	char    sReserve1[20];		/* ����1(ҵ�����) */
	char    sReserve2[20];		/* ����2(ҵ�����) */
	char    sReserve3[30];		/* ����3(ҵ�����) */
	char    sReserve4[30];		/* ����4(ҵ�����) */
	char    sOriSourceID[6];		/* �ɼ���Դ */
	char    sOriFileName[40];		/* ԭʼ�ļ��� */
	char    sLine[8];		/* �����ļ��к� */
	char    sErrCode[4];		/* ������� */
	char    sFileName[19];		/* ��������ļ��� */
	char    sModule[3];		/* ҵ������(STTVIT��) */
	char    sAreaCode[5];		/* ���� */
	char    sState[1];		/* (0:����,1:�ѻ���,2:�Ѵ���) */
	char    sErrRec[2048];		/* �����ƻ����������ASCII���ı���Ϊԭʼ��¼ */
};

#endif
