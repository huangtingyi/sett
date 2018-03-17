#ifndef __UPDATA_TICKET_H__
#define __UPDATA_TICKET_H__

#include <stt_ticket.h>

/*�����ṹ����*/
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

/*�����ļ��ṹ����*/
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


/*�����ṹ����*/
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


/*�����ļ��ṹ����*/
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

/************************�������ݽṹ--�ܲ�Ҫ���ʽ�ĵ�****************************/
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

/*�����ṹ����*/
struct CriTicketStruct{

	struct CriTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sInCityCode[4];		/* ����ͨ�����д��� */
	char    sOutCityCode[4];		/* ����ͨ�����д��� */
	char    sLinkRef[7];		/* ���ο� */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* �û����� */
	char    sModifyTag[2];		/* �޸�ָʾ */
	char    sNbrType[2];		/* �������� */
	char    sNbrPlan[2];		/* ѡ�ŷ��� */
	char    sOtherParty[16];		/* �Զ˺��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sServiceCode[3];		/* ҵ����� */
	char    sDupServiceType[2];		/* ˫��ҵ������ */
	char    sDupServiceCode[3];		/* ˫��ҵ���� */
	char    sAckChannel[2];		/* Ҫ�������ͨ�� */
	char    sUseChannel[2];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[2];		/* ҵ��͸���� */
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
	char    sMsc[16];		/* MSC ��ʶ */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* �ƶ��豸����� */
	char    sStartDate[9];		/* ͨ������ */
	char    sStartTime[7];		/* ͨ����ʼʱ�� */
	char    sPayUnit[7];		/* ���ѵ�λ */
	char    sFlowRef[7];		/* �������ο� */
	char    sTollCode[2];		/* ��;�Ѵ��� */
	char    sOtherCode[3];		/* �������Ѵ��� */
	char    sRoamFee[10];		/* ���λ��� */
	char    sTollFee[7];		/* ��;���� */
	char    sOtherFee[7];		/* �������� */
	char    sPayItem[2];		/* �շѵ���Ŀ */
	struct CriTicketStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
struct FCriTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sInCityCode[3];		/* ����ͨ�����д��� */
	char    sOutCityCode[3];		/* ����ͨ�����д��� */
	char    sLinkRef[6];		/* ���ο� */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[15];		/* �û����� */
	char    sModifyTag[1];		/* �޸�ָʾ */
	char    sNbrType[1];		/* �������� */
	char    sNbrPlan[1];		/* ѡ�ŷ��� */
	char    sOtherParty[15];		/* �Զ˺��� */
	char    sServiceType[1];		/* ҵ������ */
	char    sServiceCode[2];		/* ҵ����� */
	char    sDupServiceType[1];		/* ˫��ҵ������ */
	char    sDupServiceCode[2];		/* ˫��ҵ���� */
	char    sAckChannel[1];		/* Ҫ�������ͨ�� */
	char    sUseChannel[1];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[1];		/* ҵ��͸���� */
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
	char    sMsc[15];		/* MSC ��ʶ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* �ƶ��豸����� */
	char    sStartDate[8];		/* ͨ������ */
	char    sStartTime[6];		/* ͨ����ʼʱ�� */
	char    sPayUnit[6];		/* ���ѵ�λ */
	char    sFlowRef[6];		/* �������ο� */
	char    sTollCode[1];		/* ��;�Ѵ��� */
	char    sOtherCode[2];		/* �������Ѵ��� */
	char    sRoamFee[9];		/* ���λ��� */
	char    sTollFee[6];		/* ��;���� */
	char    sOtherFee[6];		/* �������� */
	char    sPayItem[1];		/* �շѵ���Ŀ */
};

/*�����ṹ����*/
struct CiiTicketStruct{

	struct CiiTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sInCityCode[4];		/* ����ͨ�����д��� */
	char    sOutCityCode[4];		/* ����ͨ�����д��� */
	char    sLinkRef[7];		/* ���ο� */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* �û����� */
	char    sModifyTag[2];		/* �޸�ָʾ */
	char    sNbrType[2];		/* �������� */
	char    sNbrPlan[2];		/* ѡ�ŷ��� */
	char    sOtherParty[16];		/* �Զ˺��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sServiceCode[3];		/* ҵ����� */
	char    sDupServiceType[2];		/* ˫��ҵ������ */
	char    sDupServiceCode[3];		/* ˫��ҵ���� */
	char    sAckChannel[2];		/* Ҫ�������ͨ�� */
	char    sUseChannel[2];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[2];		/* ҵ��͸���� */
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
	char    sMsc[16];		/* MSC ��ʶ */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* �ƶ��豸����� */
	char    sStartDate[9];		/* ͨ������ */
	char    sStartTime[7];		/* ͨ����ʼʱ�� */
	char    sPayUnit[7];		/* ���ѵ�λ */
	char    sFlowRef[7];		/* �������ο� */
	char    sFee[10];		/* �ܻ��� */
	char    sPayItem[2];		/* �շѵ���Ŀ */
	struct CiiTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FCiiTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sInCityCode[3];		/* ����ͨ�����д��� */
	char    sOutCityCode[3];		/* ����ͨ�����д��� */
	char    sLinkRef[6];		/* ���ο� */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[15];		/* �û����� */
	char    sModifyTag[1];		/* �޸�ָʾ */
	char    sNbrType[1];		/* �������� */
	char    sNbrPlan[1];		/* ѡ�ŷ��� */
	char    sOtherParty[15];		/* �Զ˺��� */
	char    sServiceType[1];		/* ҵ������ */
	char    sServiceCode[2];		/* ҵ����� */
	char    sDupServiceType[1];		/* ˫��ҵ������ */
	char    sDupServiceCode[2];		/* ˫��ҵ���� */
	char    sAckChannel[1];		/* Ҫ�������ͨ�� */
	char    sUseChannel[1];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[1];		/* ҵ��͸���� */
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
	char    sMsc[15];		/* MSC ��ʶ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* �ƶ��豸����� */
	char    sStartDate[8];		/* ͨ������ */
	char    sStartTime[6];		/* ͨ����ʼʱ�� */
	char    sPayUnit[6];		/* ���ѵ�λ */
	char    sFlowRef[6];		/* �������ο� */
	char    sFee[9];		/* �ܻ��� */
	char    sPayItem[1];		/* �շѵ���Ŀ */
};

/*�����ṹ����*/
struct JriTicketStruct{

	struct JriTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sRetCode[2];		/* ������ */
	char    sErrCode[3];		/* ��¼����ԭ���� */
	char    sErrField[4];		/* �����ֶα�ʶ */
	char    sMsidTag[2];		/* MSID��ʶ */
	char    sMsid[16];		/* MSID */
	char    sMsisdnLen[3];		/* MSISDN���� */
	char    sMsisdn[16];		/* �û����� */
	char    sEsnTag[2];		/* ESN��ʶ */
	char    sEsn[20];		/* ESN */
	char    sVisitCityCode[4];		/* ���д��� */
	char    sTotalFee[11];		/* ˰���ܻ��� */
	char    sReserve1[2];		/* ϵͳ����1 */
	char    sProvTex[11];		/* ��ʡ˰�� */
	char    sReserve2[2];		/* ϵͳ����2 */
	char    sLocalTex[11];		/* �ܵط�˰�� */
	char    sReserve3[2];		/* ϵͳ����3 */
	char    sStartDate[7];		/* ͨ������ */
	char    sDirection[2];		/* ���з��� */
	char    sEndFlag[2];		/* ������ɱ�ʶ */
	char    sStopFlag[2];		/* ������ֹ��ʶ */
	char    sOtherPartyLen[3];		/* �Է����볤�� */
	char    sOtherParty[26];		/* �Է����� */
	char    sMsrnLen[3];		/* ��ʱ���볤�� */
	char    sMsrn[16];		/* ��ʱ���� */
	char    sReserve4[3];		/* ϵͳ����4 */
	char    sCellCode[12];		/* ���ѱ�ʶ */
	char    sMad[11];		/* MAD */
	char    sRoamStartTime[7];		/* ��������ʱ�� */
	char    sRoamBillDuration[7];		/* ���μƷ�ʱ�� */
	char    sRoamDuration[7];		/* ����ͨ��ʱ�� */
	char    sRoamTimeSpan[3];		/* ���η�����ʼʱ�� */
	char    sRoamTimeType[2];		/* ���ζ����ʱ�α�ʶ */
	char    sRoamFee[11];		/* ���η� */
	char    sReserve5[2];		/* ϵͳ����5 */
	char    sOtherFeeTag[3];		/* �������ñ�ʶ */
	char    sOtherFee[11];		/* �������� */
	char    sReserve6[2];		/* ϵͳ����6 */
	char    sReserve7[14];		/* ϵͳ����7 */
	char    sSpecialService[6];		/* �������ʹ�� */
	char    sOppCityCode[11];		/* �Է����ڵ� */
	char    sOppProvCode[4];		/* �Է�����ʡ */
	char    sOppCountryCode[4];		/* �Է����ڹ� */
	char    sTollStartTime[7];		/* ��;����ʱ�� */
	char    sTollBillDuration[7];		/* ��;�Ʒ�ʱ�� */
	char    sTollDuration[7];		/* ��;ͨ��ʱ�� */
	char    sTollFeeDesc[3];		/* ��;�ʷ����� */
	char    sTollTimeSpan[3];		/* ��;������ʼʱ�� */
	char    sTollTimeType[2];		/* ��;����ʱ�ʶ */
	char    sTollFee[11];		/* ��;�� */
	char    sReserve8[2];		/* ϵͳ����8 */
	char    sTollProvTex[11];		/* ��;ʡ˰�� */
	char    sReserve9[2];		/* ϵͳ����9 */
	char    sTollLocalTex[11];		/* ��;����˰ */
	char    sReserve10[2];		/* ϵͳ����10 */
	char    sTollNetOperator[6];		/* ��;�����ṩ��Ӫ�̱�ʶ */
	struct JriTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FJriTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sRetCode[1];		/* ������ */
	char    sErrCode[2];		/* ��¼����ԭ���� */
	char    sErrField[3];		/* �����ֶα�ʶ */
	char    sMsidTag[1];		/* MSID��ʶ */
	char    sMsid[15];		/* MSID */
	char    sMsisdnLen[2];		/* MSISDN���� */
	char    sMsisdn[15];		/* �û����� */
	char    sEsnTag[1];		/* ESN��ʶ */
	char    sEsn[19];		/* ESN */
	char    sVisitCityCode[3];		/* ���д��� */
	char    sTotalFee[10];		/* ˰���ܻ��� */
	char    sReserve1[1];		/* ϵͳ����1 */
	char    sProvTex[10];		/* ��ʡ˰�� */
	char    sReserve2[1];		/* ϵͳ����2 */
	char    sLocalTex[10];		/* �ܵط�˰�� */
	char    sReserve3[1];		/* ϵͳ����3 */
	char    sStartDate[6];		/* ͨ������ */
	char    sDirection[1];		/* ���з��� */
	char    sEndFlag[1];		/* ������ɱ�ʶ */
	char    sStopFlag[1];		/* ������ֹ��ʶ */
	char    sOtherPartyLen[2];		/* �Է����볤�� */
	char    sOtherParty[25];		/* �Է����� */
	char    sMsrnLen[2];		/* ��ʱ���볤�� */
	char    sMsrn[15];		/* ��ʱ���� */
	char    sReserve4[2];		/* ϵͳ����4 */
	char    sCellCode[11];		/* ���ѱ�ʶ */
	char    sMad[10];		/* MAD */
	char    sRoamStartTime[6];		/* ��������ʱ�� */
	char    sRoamBillDuration[6];		/* ���μƷ�ʱ�� */
	char    sRoamDuration[6];		/* ����ͨ��ʱ�� */
	char    sRoamTimeSpan[2];		/* ���η�����ʼʱ�� */
	char    sRoamTimeType[1];		/* ���ζ����ʱ�α�ʶ */
	char    sRoamFee[10];		/* ���η� */
	char    sReserve5[1];		/* ϵͳ����5 */
	char    sOtherFeeTag[2];		/* �������ñ�ʶ */
	char    sOtherFee[10];		/* �������� */
	char    sReserve6[1];		/* ϵͳ����6 */
	char    sReserve7[13];		/* ϵͳ����7 */
	char    sSpecialService[5];		/* �������ʹ�� */
	char    sOppCityCode[10];		/* �Է����ڵ� */
	char    sOppProvCode[3];		/* �Է�����ʡ */
	char    sOppCountryCode[3];		/* �Է����ڹ� */
	char    sTollStartTime[6];		/* ��;����ʱ�� */
	char    sTollBillDuration[6];		/* ��;�Ʒ�ʱ�� */
	char    sTollDuration[6];		/* ��;ͨ��ʱ�� */
	char    sTollFeeDesc[2];		/* ��;�ʷ����� */
	char    sTollTimeSpan[2];		/* ��;������ʼʱ�� */
	char    sTollTimeType[1];		/* ��;����ʱ�ʶ */
	char    sTollFee[10];		/* ��;�� */
	char    sReserve8[1];		/* ϵͳ����8 */
	char    sTollProvTex[10];		/* ��;ʡ˰�� */
	char    sReserve9[1];		/* ϵͳ����9 */
	char    sTollLocalTex[10];		/* ��;����˰ */
	char    sReserve10[1];		/* ϵͳ����10 */
	char    sTollNetOperator[5];		/* ��;�����ṩ��Ӫ�̱�ʶ */
};

/*�����ṹ����*/
struct JiiTicketStruct{

	struct JiiTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sRetCode[2];		/* ������ */
	char    sErrCode[3];		/* ��¼����ԭ���� */
	char    sErrField[4];		/* �����ֶα�ʶ */
	char    sMsidTag[2];		/* MSID��ʶ */
	char    sMsid[16];		/* MSID */
	char    sMsisdnLen[3];		/* MSISDN���� */
	char    sMsisdn[16];		/* �û����� */
	char    sEsnTag[2];		/* ESN��ʶ */
	char    sEsn[20];		/* ESN */
	char    sVisitCityCode[6];		/* ���д��� */
	char    sTotalFee[11];		/* ˰���ܻ��� */
	char    sReserve1[2];		/* ϵͳ����1 */
	char    sProvTex[11];		/* ��ʡ˰�� */
	char    sReserve2[2];		/* ϵͳ����2 */
	char    sLocalTex[11];		/* �ܵط�˰�� */
	char    sReserve3[2];		/* ϵͳ����3 */
	char    sStartDate[7];		/* ͨ������ */
	char    sDirection[2];		/* ���з��� */
	char    sEndFlag[2];		/* ������ɱ�ʶ */
	char    sStopFlag[2];		/* ������ֹ��ʶ */
	char    sOtherPartyLen[3];		/* �Է����볤�� */
	char    sOtherParty[26];		/* �Է����� */
	char    sMsrnLen[3];		/* ��ʱ���볤�� */
	char    sMsrn[16];		/* ��ʱ���� */
	char    sReserve4[3];		/* ϵͳ����4 */
	char    sCellCode[12];		/* ���ѱ�ʶ */
	char    sTimeZone[3];		/* ʱ����ʶ */
	char    sSummerTimeTag[2];		/* ����ʱ��ʶ */
	char    sMad[11];		/* MAD */
	char    sRoamStartTime[7];		/* ��������ʱ�� */
	char    sRoamBillDuration[7];		/* ���μƷ�ʱ�� */
	char    sRoamDuration[7];		/* ����ͨ��ʱ�� */
	char    sRoamTimeSpan[3];		/* ���η�����ʼʱ�� */
	char    sRoamTimeType[2];		/* ���ζ����ʱ�α�ʶ */
	char    sRoamFee[11];		/* ���η� */
	char    sReserve5[2];		/* ϵͳ����5 */
	char    sOtherFeeTag[3];		/* �������ñ�ʶ */
	char    sOtherFee[11];		/* �������� */
	char    sReserve6[2];		/* ϵͳ����6 */
	char    sReserve7[14];		/* ϵͳ����7 */
	char    sOppDesc[16];		/* ������������ */
	char    sSpecialService[6];		/* �������ʹ�� */
	char    sOppCityCode[11];		/* �Է����ڵ� */
	char    sOppProvCode[4];		/* �Է�����ʡ */
	char    sOppCountryCode[4];		/* �Է����ڹ� */
	char    sTollStartTime[7];		/* ��;����ʱ�� */
	char    sTollBillDuration[7];		/* ��;�Ʒ�ʱ�� */
	char    sTollDuration[7];		/* ��;ͨ��ʱ�� */
	char    sTollFeeDesc[3];		/* ��;�ʷ����� */
	char    sTollTimeSpan[3];		/* ��;������ʼʱ�� */
	char    sTollTimeType[2];		/* ��;����ʱ�ʶ */
	char    sTollFee[11];		/* ��;�� */
	char    sReserve8[2];		/* ϵͳ����8 */
	char    sTollProvTex[11];		/* ��;ʡ˰�� */
	char    sReserve9[2];		/* ϵͳ����9 */
	char    sTollLocalTex[11];		/* ��;����˰ */
	struct JiiTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FJiiTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sRetCode[1];		/* ������ */
	char    sErrCode[2];		/* ��¼����ԭ���� */
	char    sErrField[3];		/* �����ֶα�ʶ */
	char    sMsidTag[1];		/* MSID��ʶ */
	char    sMsid[15];		/* MSID */
	char    sMsisdnLen[2];		/* MSISDN���� */
	char    sMsisdn[15];		/* �û����� */
	char    sEsnTag[1];		/* ESN��ʶ */
	char    sEsn[19];		/* ESN */
	char    sVisitCityCode[5];		/* ���д��� */
	char    sTotalFee[10];		/* ˰���ܻ��� */
	char    sReserve1[1];		/* ϵͳ����1 */
	char    sProvTex[10];		/* ��ʡ˰�� */
	char    sReserve2[1];		/* ϵͳ����2 */
	char    sLocalTex[10];		/* �ܵط�˰�� */
	char    sReserve3[1];		/* ϵͳ����3 */
	char    sStartDate[6];		/* ͨ������ */
	char    sDirection[1];		/* ���з��� */
	char    sEndFlag[1];		/* ������ɱ�ʶ */
	char    sStopFlag[1];		/* ������ֹ��ʶ */
	char    sOtherPartyLen[2];		/* �Է����볤�� */
	char    sOtherParty[25];		/* �Է����� */
	char    sMsrnLen[2];		/* ��ʱ���볤�� */
	char    sMsrn[15];		/* ��ʱ���� */
	char    sReserve4[2];		/* ϵͳ����4 */
	char    sCellCode[11];		/* ���ѱ�ʶ */
	char    sTimeZone[2];		/* ʱ����ʶ */
	char    sSummerTimeTag[1];		/* ����ʱ��ʶ */
	char    sMad[10];		/* MAD */
	char    sRoamStartTime[6];		/* ��������ʱ�� */
	char    sRoamBillDuration[6];		/* ���μƷ�ʱ�� */
	char    sRoamDuration[6];		/* ����ͨ��ʱ�� */
	char    sRoamTimeSpan[2];		/* ���η�����ʼʱ�� */
	char    sRoamTimeType[1];		/* ���ζ����ʱ�α�ʶ */
	char    sRoamFee[10];		/* ���η� */
	char    sReserve5[1];		/* ϵͳ����5 */
	char    sOtherFeeTag[2];		/* �������ñ�ʶ */
	char    sOtherFee[10];		/* �������� */
	char    sReserve6[1];		/* ϵͳ����6 */
	char    sReserve7[13];		/* ϵͳ����7 */
	char    sOppDesc[15];		/* ������������ */
	char    sSpecialService[5];		/* �������ʹ�� */
	char    sOppCityCode[10];		/* �Է����ڵ� */
	char    sOppProvCode[3];		/* �Է�����ʡ */
	char    sOppCountryCode[3];		/* �Է����ڹ� */
	char    sTollStartTime[6];		/* ��;����ʱ�� */
	char    sTollBillDuration[6];		/* ��;�Ʒ�ʱ�� */
	char    sTollDuration[6];		/* ��;ͨ��ʱ�� */
	char    sTollFeeDesc[2];		/* ��;�ʷ����� */
	char    sTollTimeSpan[2];		/* ��;������ʼʱ�� */
	char    sTollTimeType[1];		/* ��;����ʱ�ʶ */
	char    sTollFee[10];		/* ��;�� */
	char    sReserve8[1];		/* ϵͳ����8 */
	char    sTollProvTex[10];		/* ��;ʡ˰�� */
	char    sReserve9[1];		/* ϵͳ����9 */
	char    sTollLocalTex[10];		/* ��;����˰ */
};

/*�����ṹ����*/
struct TrsTicketStruct{

	struct TrsTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sInCityCode[4];		/* ����ͨ�����д��� */
	char    sOutCityCode[4];		/* ����ͨ�����д��� */
	char    sLinkRef[7];		/* ���ο� */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sThirdParty[16];		/* ���к���A */
	char    sMsisdn[16];		/* �û����� */
	char    sOtherParty[16];		/* �Զ˺��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sServiceCode[3];		/* ҵ����� */
	char    sReserve2[10];		/* ϵͳ����2 */
	char    sMsc[16];		/* MSC ��ʶ */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* �ƶ��豸����� */
	char    sStartDate[9];		/* ͨ������ */
	char    sStartTime[7];		/* ͨ����ʼʱ�� */
	char    sPayUnit[7];		/* ���ѵ�λ */
	char    sReserve3[32];		/* ����3 */
	struct TrsTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FTrsTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sInCityCode[3];		/* ����ͨ�����д��� */
	char    sOutCityCode[3];		/* ����ͨ�����д��� */
	char    sLinkRef[6];		/* ���ο� */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sThirdParty[15];		/* ���к���A */
	char    sMsisdn[15];		/* �û����� */
	char    sOtherParty[15];		/* �Զ˺��� */
	char    sServiceType[1];		/* ҵ������ */
	char    sServiceCode[2];		/* ҵ����� */
	char    sReserve2[9];		/* ϵͳ����2 */
	char    sMsc[15];		/* MSC ��ʶ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* �ƶ��豸����� */
	char    sStartDate[8];		/* ͨ������ */
	char    sStartTime[6];		/* ͨ����ʼʱ�� */
	char    sPayUnit[6];		/* ���ѵ�λ */
	char    sReserve3[31];		/* ����3 */
};

/*�����ṹ����*/
struct RhjfHeadStruct{

	struct RhjfHeadStruct *pNext;
	char    sRecordType[3];       /*�������*/
	char    sCityCode[6];         /*�������Ŵ���*/
	char    sFileFlag[5];         /*�ļ���־ "RHJF" */
	char    sFileSeq[5];          /*�ļ����к�*/
	char    sFileVersion[3];      /*�ļ��汾�� "00" */
	char    sFileCreatDate[9];    /*�ļ���������*/
	char    sFirstCallDate[9];    /*�״�ͨ������*/
	char    sFirstCallTime[7];    /*�״�ͨ��ʱ��*/
	char    sLastCallDate[9];     /*ĩ��ͨ������*/
	char    sLastCallTime[7];     /*ĩ��ͨ��ʱ��*/
	char    sCallSumNbr[7];       /*ͨ���ܼ�¼��*/
	char    sCallSumFee[16];      /*�ܻ���*/
	char    sNouse[61];           /*δ��*/
	struct RhjfHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
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


/*�����ṹ����*/
struct RhjfBodyStruct{

	struct RhjfBodyStruct *pNext;
	char    sCallType[3];           /*�������� "00"*/
	char    sRecordType[3];         /*�������*/
	char    sCallingNbr[16];        /*�û�����*/
	char    sCalledNbr[31];         /*�Զ˺���*/
	char    sStartTime[15];         /*ͨ����ʼʱ��*/
	char    sDuration[7];           /*ͨ��ʱ��*/
	char    sSwitchNbr[16];         /*����������*/
	char    sTrunkIn[8];            /*���м�*/
	char    sTrunkOut[8];           /*���м�*/
	char    sBaseFee[9];            /*��������*/
	char    sLongFee[9];            /*��;����*/
	char    sOtherFee[9];           /*��������*/
	char    sDistanceType[2];       /*��;����*/
	char    sCallingAreaCode[6];    /*ͨ��������*/
	char    sBelongAreaCode[6];     /*����������*/
	char    sCalledAreaCode[6];     /*�Զ�����*/
	struct RhjfBodyStruct *pLoadNext;
};

/*�����ļ��ṹ����*/
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

/*�����ṹ����*/
struct GsmHeadStruct{

	struct GsmHeadStruct *pNext;
	char    sRecordType[3];		/* ��¼���� ���ػ���01������02 */
	char    sCityCode[4];		/* ���д��� ͬ��ͨ���д��� */
	int     iFileSeq;		/* �ļ����к� ��00000001��ʼ�������������� */
	char    sFileVer[3];		/* �ļ��汾�� 00 */
	char    sCreateDate[9];		/* �ļ��������� YYYYMMDD */
	int     iRecordCnt;		/* �ܼ�¼�� �Ҷ��룬��0�� */
	struct GsmHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FGsmHeadStruct{

	char    sRecordType[2];
	char    sCityCode[3];
	char    sFileSeq[8];
	char    sFileVer[2];
	char    sCreateDate[8];
	char    sRecordCnt[6];
};

/*�����ṹ����*/
struct SmsHeadStruct{

	struct SmsHeadStruct *pNext;
	char    sHeadTag[3];		/* ͷ��¼��ʶ	ͷ��¼Ӣ����д��ʶ��HEAD����HD��      */           
	char    sFileSeq[5];		/* �ļ����к�	�ļ����кţ����ļ����е����к���ͬ  */             
	char    sFileVer[3];		/* �ļ��汾��	Ŀǰ�汾�ţ���01����                  */           
	char    sCreateDate[9];		/* �ļ���������	YYYYMMDD                            */             
	char    sFirstCallDate[15];	/* ��һ����¼ʱ��	YYYYMMDDHHMMSS              */             
	char    sLastCallDate[15];	/* ��ĩ����¼ʱ��	YYYYMMDDHHMMSS              */             
	char    sRecordCnt[11];		/* �ܼ�¼��	�����׼�¼�� ����룬����ա�       */             
	char    sRoamFee[11];		/* ��ͨ�ŷ�	���ļ�������ͨ�ŷ�                  */             
	char    sInfoFee[11];		/* ����Ϣ��	���ļ���������Ϣ��                  */             
	char    sReserve[57];		/* ����		���ո��Ժ͵�����¼�ĳ�����ͬ��      */             
	struct SmsHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
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

/*�����ṹ����*/
struct NxRhjfHeadStruct{

	struct NxRhjfHeadStruct *pNext;
	char    sRecordType[3];		/* �׼�¼��ʶ */
	char    sPickID[6];		/* �ɼ���ID */
	char    sOriFileName[37];		/* ԭʼ�����ļ����� */
	int     iSeqNbr;		/* �ļ����к� */
	char    sVersion[2];		/* �汾���� */
	char    sCreatedDate[9];		/* �ļ��������� */
	char    sBeginTime[15];		/* �״�ͨ��ʱ�� */
	char    sEndTime[15];		/* ĩ��ͨ��ʱ�� */
	int     iTotalCnt;		/* �ܼ�¼�� */
	char    sTotalFee[13];		/* ��λ��������ң��� */
	char    sReserve[117];		/* ���� */
	struct NxRhjfHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FNxRhjfHeadStruct{

	char    sRecordType[2];		/* �׼�¼��ʶ */
	char    sPickID[5];		/* �ɼ���ID */
	char    sOriFileName[36];		/* ԭʼ�����ļ����� */
	char    sSeqNbr[4];		/* �ļ����к� */
	char    sVersion[1];		/* �汾���� */
	char    sCreatedDate[8];		/* �ļ��������� */
	char    sBeginTime[14];		/* �״�ͨ��ʱ�� */
	char    sEndTime[14];		/* ĩ��ͨ��ʱ�� */
	char    sTotalCnt[8];		/* �ܼ�¼�� */
	char    sTotalFee[12];		/* ��λ��������ң��� */
	char    sReserve[116];		/* ���� */
};
void mvitem_mfnxrhjfhead(struct NxRhjfHeadStruct *pi,struct FNxRhjfHeadStruct *po);


/*�����ṹ����*/
struct HbjsFileHeadStruct{

	struct HbjsFileHeadStruct *pNext;
	char    sFileName[61];		/* �ӿ������ļ����� */
	int     iTotalCnt;		/* �ļ��а����ļ�¼�� */
	char    sFirstCallDate[9];	/* ������ʼ���� */
	char    sFirstCallTime[7];	/* ������ʼʱ�� */
	char    sEndCallDate[9];	/* ������ֹ���� */
	char    sEndCallTime[7];	/* ������ֹʱ�� */
	char    sCreatedDate[15];	/* �ļ�������ʱ�� */
	struct HbjsFileHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FHbjsFileHeadStruct{

	char    sFileName[60];		/* �ӿ������ļ����� */
	char    sTotalCnt[9];		/* �ļ��а����ļ�¼�� */
	char    sFirstCallDate[8];	/* ������ʼ���� */
	char    sFirstCallTime[6];	/* ������ʼʱ�� */
	char    sEndCallDate[8];	/* ������ֹ���� */
	char    sEndCallTime[6];	/* ������ֹʱ�� */
	char    sCreatedDate[14];	/* �ļ�������ʱ�� */
};

/*�����ṹ����*/
struct SmgDTicketStruct{

	struct SmgDTicketStruct *pNext;
	char    sMessageID[22];		/* ����Ϣ��ʶ */
	char    sSmsType[3];		/* ����Ϣ���� */
	char    sSubType[3];		/* ����Ϣ������ */
	char    sMsisdn[23];		/* �Ʒ��û����� */
	char    sSpCode[12];		/* SP���� */
	char    sOtherParty[23];		/* Ŀ�ĵغ��� */
	char    sSpServiceCode[12];		/* ҵ����� */
	char    sBillType[4];		/* �û��Ʒ���� */
	char    sInfoFee[8];		/* ��Ϣ�� */
	char    sPriority[3];		/* ����Ϣ�������ȼ� */
	char    sMsgLen[5];		/* ��Ϣ���� */
	char    sHomeAreaCode[6];		/* �ƷѺ�������ص����� */
	char    sSmg[8];		/* SMGW���� */
	char    sTsmg[8];		/* ǰתSMGW���� */
	char    sSmc[8];		/* ����Ϣ���Ĵ��� */
	char    sRecvDateTime[16];		/* �ύʱ�� */
	char    sDoneDateTime[16];		/* ��������ʱ�� */
	char    sMsgID[22];		/* SMGW�������Ϣ��ʶ */
	char    sOppMsgID[22];		/* ����֮��Ķ���Ϣ��ʶ */
	char    sCallingNbr[22];		/* �����û����� */
	struct SmgDTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSmgDTicketStruct{

	char    sMessageID[21];		/* ����Ϣ��ʶ */
	char    sSmsType[2];		/* ����Ϣ���� */
	char    sSubType[2];		/* ����Ϣ������ */
	char    sMsisdn[22];		/* �Ʒ��û����� */
	char    sSpCode[11];		/* SP���� */
	char    sOtherParty[22];		/* Ŀ�ĵغ��� */
	char    sSpServiceCode[11];		/* ҵ����� */
	char    sBillType[3];		/* �û��Ʒ���� */
	char    sInfoFee[7];		/* ��Ϣ�� */
	char    sPriority[2];		/* ����Ϣ�������ȼ� */
	char    sMsgLen[4];		/* ��Ϣ���� */
	char    sHomeAreaCode[5];		/* �ƷѺ�������ص����� */
	char    sSmg[7];		/* SMGW���� */
	char    sTsmg[7];		/* ǰתSMGW���� */
	char    sSmc[7];		/* ����Ϣ���Ĵ��� */
	char    sRecvDateTime[15];		/* �ύʱ�� */
	char    sDoneDateTime[15];		/* ��������ʱ�� */
	char    sMsgID[21];		/* SMGW�������Ϣ��ʶ */
	char    sOppMsgID[21];		/* ����֮��Ķ���Ϣ��ʶ */
	char    sCallingNbr[21];		/* �����û����� */
};

void mvitem_mfsmgdticket(struct SmgDTicketStruct *pi,struct FSmgDTicketStruct *po);
void mvitem_fmsmgdticket(struct FSmgDTicketStruct *pi,struct SmgDTicketStruct *po);
void mvitem_mfsmgdhead(struct HbjsFileHeadStruct *pi,struct FHbjsFileHeadStruct *po);
/*�����ṹ����*/
struct ZnwSnIntfStruct{

	struct ZnwSnIntfStruct *pNext;
	char    sServiceKey[4];		/* ҵ��� */
	char    sStartTime[15];		/* ��ʼͨ��ʱ�� */
	char    sCallingNbr[25];		/* �����û����� */
	char    sCalledNbr[25];		/* �����û����� */
	char    sTranslatedNbr[25];		/* Ŀ���ַ������� */
	char    sBillingNbr[25];		/* �涨�ļƷѺ��� */
	char    sDuration[13];		/* ͨ��ʱ������ */
	int     iSecond;		/* ͨ��ʱ������һ���ӵ����� */
	char    sTotalFee[13];		/* ͨ������ */
	int     iBaseFee;		/* ������ */
	char    sTrunkIn[5];		/* ���м�Ⱥ�� */
	char    sTrunkOut[5];		/* ���м�Ⱥ�� */
	char    sMsc[2];		/* ������ */
	char    sTariffClass[3];		/* �������� */
	char    sReserve[3];		/* ���� */
	char    sGroupID[13];		/* ������Ϣ */
	char    sCardID[14];		/* ���� */
	struct ZnwSnIntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FZnwSnIntfStruct{

	char    sServiceKey[3];		/* ҵ��� */
	char    sStartTime[14];		/* ��ʼͨ��ʱ�� */
	char    sCallingNbr[24];		/* �����û����� */
	char    sCalledNbr[24];		/* �����û����� */
	char    sTranslatedNbr[24];		/* Ŀ���ַ������� */
	char    sBillingNbr[24];		/* �涨�ļƷѺ��� */
	char    sDuration[12];		/* ͨ��ʱ������ */
	char    sSecond[2];		/* ͨ��ʱ������һ���ӵ����� */
	char    sTotalFee[12];		/* ͨ������ */
	char    sBaseFee[8];		/* ������ */
	char    sTrunkIn[4];		/* ���м�Ⱥ�� */
	char    sTrunkOut[4];		/* ���м�Ⱥ�� */
	char    sMsc[1];		/* ������ */
	char    sTariffClass[2];		/* �������� */
	char    sReserve[2];		/* ���� */
	char    sGroupID[12];		/* ������Ϣ */
	char    sCardID[13];		/* ���� */
};
void mvitem_mfznwsnintf(struct ZnwSnIntfStruct *pi,struct FZnwSnIntfStruct *po);
void mvitem_fmznwsnintf(struct FZnwSnIntfStruct *pi,struct ZnwSnIntfStruct *po);

/*�����ṹ����*/
struct ZnwGjIntfStruct{

	struct ZnwGjIntfStruct *pNext;
	char    sStreamNumber[11];		/* ��ˮ�� */
	char    sServiceKey[11];		/* ҵ��� */
	char    sBillingMode[2];		/* �Ʒ�ģʽ */
	char    sChargeRecordID[9];		/* �ƷѼ�¼��ʶ */
	char    sCallingNbr[25];		/* �����û����� */
	char    sCalledNbr[25];		/* �����û����� */
	char    sTranslatedNbr[25];		/* Ŀ���ַ������� */
	char    sLocationNbr[5];		/* λ�ú��� */
	char    sBillingFlag[5];		/* �Ʒ��û���־ */
	char    sBillingNbr[25];		/* �涨�ļƷѺ��� */
	char    sStartTime[15];		/* ��ʼͨ��ʱ�� */
	char    sStopTime[15];		/* ͨ������ʱ�� */
	char    sDuration[11];		/* ͨ��ʱ�� */
	char    sTotalFee[11];		/* ͨ������ */
	char    sBearCapability[3];		/* �������� */
	char    sTariffClass[3];		/* �������� */
	char    sBillType[5];		/* �ƷѺ������� */
	char    sUserID[11];		/* �û�ID��������Ϣ */
	char    sServiceNbr[29];		/* ҵ����� */
	int     iCount;		/* �ƴ��� */
	char    sBaseFee[11];		/* ������ */
	char    sBountyFee[11];		/* ������� */
	char    sAddFee[11];		/* ���ӷ� */
	char    sTransParam[31];		/* ͸������ */
	char    sCallparttobecharger[33];		/* �ƷѲ��� */
	char    sScpID[11];		/* scp��� */
	char    sCauseOfCallend[5];		/* ͨ������ԭ�� */
	char    sServiceModulator[5];		/* ҵ���ۿ��� */
	char    sServiceType[3];		/* ҵ������ */
	char    sHomeAreaCode[11];		/* ���й����� */
	char    sCalledCode[11];		/* ���й����� */
	char    sBillingAreaCode[11];		/* �Ʒ����� */
	char    sOriFileName[65];		/* ԭʼ�����ļ��� */
	struct ZnwGjIntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FZnwGjIntfStruct{

	char    sStreamNumber[10];		/* ��ˮ�� */
	char    sServiceKey[10];		/* ҵ��� */
	char    sBillingMode[1];		/* �Ʒ�ģʽ */
	char    sChargeRecordID[8];		/* �ƷѼ�¼��ʶ */
	char    sCallingNbr[24];		/* �����û����� */
	char    sCalledNbr[24];		/* �����û����� */
	char    sTranslatedNbr[24];		/* Ŀ���ַ������� */
	char    sLocationNbr[4];		/* λ�ú��� */
	char    sBillingFlag[4];		/* �Ʒ��û���־ */
	char    sBillingNbr[24];		/* �涨�ļƷѺ��� */
	char    sStartTime[14];		/* ��ʼͨ��ʱ�� */
	char    sStopTime[14];		/* ͨ������ʱ�� */
	char    sDuration[10];		/* ͨ��ʱ�� */
	char    sTotalFee[10];		/* ͨ������ */
	char    sBearCapability[2];		/* �������� */
	char    sTariffClass[2];		/* �������� */
	char    sBillType[4];		/* �ƷѺ������� */
	char    sUserID[10];		/* �û�ID��������Ϣ */
	char    sServiceNbr[28];		/* ҵ����� */
	char    sCount[8];		/* �ƴ��� */
	char    sBaseFee[10];		/* ������ */
	char    sBountyFee[10];		/* ������� */
	char    sAddFee[10];		/* ���ӷ� */
	char    sTransParam[30];		/* ͸������ */
	char    sCallparttobecharger[32];		/* �ƷѲ��� */
	char    sScpID[10];		/* scp��� */
	char    sCauseOfCallend[4];		/* ͨ������ԭ�� */
	char    sServiceModulator[4];		/* ҵ���ۿ��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sHomeAreaCode[10];		/* ���й����� */
	char    sCalledCode[10];		/* ���й����� */
	char    sBillingAreaCode[10];		/* �Ʒ����� */
	char    sOriFileName[64];		/* ԭʼ�����ļ��� */
};

/*�����ṹ����*/
struct HbZnwGjFileHeadStruct{

	struct HbZnwGjFileHeadStruct *pNext;
	char    sTotalCnt[12];		/* �ļ��а����ļ�¼�� */
	char    sTotalDuration[12];	/* ��ʱ�� */
	char    sTotalFee[12];	/* �ܽ�� */
	struct HbZnwGjFileHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FHbZnwGjFileHeadStruct{

	char    sTotalCnt[11];		/* �ļ��а����ļ�¼�� */
	char    sTotalDuration[11];	/* ��ʱ�� */
	char    sTotalFee[11];	/* �ܽ�� */
};


/*�����ṹ����*/
struct ZnwGjAcctStruct{

	struct ZnwGjAcctStruct *pNext;
	char    sCallingNbr[21];		/* ҵ����� */
	char    sServiceKey[11];		/* ҵ��� */
	char    sCalledNbr[11];		/* ҵ������� */
	char    sBaseFee[11];		/* �������� */
	char    sAddFee[11];		/* ���ӷ��� */
	char    sLcnt[12];		/* ���ش��� */
	char    sLduration[12];		/* ����ʱ�� */
	char    sLfee[12];		/* ���ؽ�� */
	char    sNcnt[12];		/* ʡ�ڳ�;���� */
	char    sNduration[12];		/* ʡ�ڳ�;ʱ�� */
	char    sNfee[12];		/* ʡ�ڳ�;��� */
	char    sScnt[12];		/* ʡ�ʳ�;���� */
	char    sSduration[12];		/* ʡ�ʳ�;ʱ�� */
	char    sSfee[12];		/* ʡ�ʳ�;��� */
	char    sGcnt[12];		/* ���ʳ�;���� */
	char    sGduration[12];		/* ���ʳ�;ʱ�� */
	char    sGfee[12];		/* ���ʳ�;��� */
	char    sCnt[12];		/* �ϼƴ��� */
	char    sDuration[12];		/* �ϼ�ʱ�� */
	char    sFee[12];		/* �ϼƽ�� */
	struct ZnwGjAcctStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FZnwGjAcctStruct{

	char    sCallingNbr[20];		/* ҵ����� */
	char    sServiceKey[10];		/* ҵ��� */
	char    sCalledNbr[10];		/* ҵ������� */
	char    sBaseFee[10];		/* �������� */
	char    sAddFee[10];		/* ���ӷ��� */
	char    sLcnt[11];		/* ���ش��� */
	char    sLduration[11];		/* ����ʱ�� */
	char    sLfee[11];		/* ���ؽ�� */
	char    sNcnt[11];		/* ʡ�ڳ�;���� */
	char    sNduration[11];		/* ʡ�ڳ�;ʱ�� */
	char    sNfee[11];		/* ʡ�ڳ�;��� */
	char    sScnt[11];		/* ʡ�ʳ�;���� */
	char    sSduration[11];		/* ʡ�ʳ�;ʱ�� */
	char    sSfee[11];		/* ʡ�ʳ�;��� */
	char    sGcnt[11];		/* ���ʳ�;���� */
	char    sGduration[11];		/* ���ʳ�;ʱ�� */
	char    sGfee[11];		/* ���ʳ�;��� */
	char    sCnt[11];		/* �ϼƴ��� */
	char    sDuration[11];		/* �ϼ�ʱ�� */
	char    sFee[11];		/* �ϼƽ�� */
};


void mvitem_mfznwgjintf(struct ZnwGjIntfStruct *pi,struct FZnwGjIntfStruct *po);
void mvitem_fmznwgjintf(struct FZnwGjIntfStruct *pi,struct ZnwGjIntfStruct *po);
void mvitem_mfznwgjhead(struct HbZnwGjFileHeadStruct *pi,struct FHbZnwGjFileHeadStruct *po);



/*�����ṹ����*/
struct Znw52IntfStruct{

	struct Znw52IntfStruct *pNext;
	char    sCallingNbr[25];		/* �����û����� */
	char    sCalledNbr[25];		/* �����û����� */
	char    sTranslatedNbr[25];		/* Ŀ���ַ������� */
	char    sStartTime[15];		/* ��ʼͨ��ʱ�� */
	char    sStopTime[15];		/* ͨ������ʱ�� */
	char    sDuration[11];		/* ͨ��ʱ�� */
	char    sTotalFee[11];		/* ͨ������ */
	struct Znw52IntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FZnw52IntfStruct{

	char    sCallingNbr[24];		/* �����û����� */
	char    sCalledNbr[24];		/* �����û����� */
	char    sTranslatedNbr[24];		/* Ŀ���ַ������� */
	char    sStartTime[14];		/* ��ʼͨ��ʱ�� */
	char    sStopTime[14];		/* ͨ������ʱ�� */
	char    sDuration[10];		/* ͨ��ʱ�� */
	char    sTotalFee[10];		/* ͨ������ */
};

void mvitem_mfznw52intf(struct Znw52IntfStruct *pi,struct FZnw52IntfStruct *po);
void mvitem_fmznw52intf(struct FZnw52IntfStruct *pi,struct Znw52IntfStruct *po);

/*�����ṹ����*/
struct SpCdrSnIntfStruct{

	struct SpCdrSnIntfStruct *pNext;
	char    sCallingNbr[21];		/* ���к��� */
	char    sCalledNbr[11];		/* ҵ�������� */
	char    sServiceNbr[21];		/* ҵ����� */
	char    sStartTime[15];		/* ��ʼʱ�� */
	char    sDuration[12];		/* ʱ�� */
	char    sFee[12];		/* ��� */
	char    sNotes[21];		/* ��ע */
	char    sRate[16];		/* ���� */
	char    sSpNbr[10];		/* SP_CP��� */
	struct SpCdrSnIntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSpCdrSnIntfStruct{

	char    sCallingNbr[20];		/* ���к��� */
	char    sCalledNbr[10];		/* ҵ�������� */
	char    sServiceNbr[20];		/* ҵ����� */
	char    sStartTime[14];		/* ��ʼʱ�� */
	char    sDuration[11];		/* ʱ�� */
	char    sFee[11];		/* ��� */
	char    sNotes[20];		/* ��ע */
	char    sRate[15];		/* ���� */
	char    sSpNbr[9];		/* SP_CP��� */
};

void mvitem_mfspcdrsnintf(struct SpCdrSnIntfStruct *pi,struct FSpCdrSnIntfStruct *po);
void mvitem_fmspcdrsnintf(struct FSpCdrSnIntfStruct *pi,struct SpCdrSnIntfStruct *po);


/*�����ṹ����*/
struct SpCdrZbIntfStruct{

	struct SpCdrZbIntfStruct *pNext;
	char    sCallingNbr[21];		/* ���к��� */
	char    sCalledNbr[11];		/* ҵ�������� */
	char    sServiceNbr[21];		/* ҵ����� */
	char    sStartTime[15];		/* ��ʼʱ�� */
	char    sDuration[12];		/* ʱ�� */
	char    sFee[12];		/* ��� */
	struct SpCdrZbIntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSpCdrZbIntfStruct{

	char    sCallingNbr[20];		/* ���к��� */
	char    sCalledNbr[10];		/* ҵ�������� */
	char    sServiceNbr[20];		/* ҵ����� */
	char    sStartTime[14];		/* ��ʼʱ�� */
	char    sDuration[11];		/* ʱ�� */
	char    sFee[11];		/* ��� */
};

void mvitem_mfspcdrzbintf(struct SpCdrZbIntfStruct *pi,struct FSpCdrZbIntfStruct *po);
void mvitem_fmspcdrzbintf(struct FSpCdrZbIntfStruct *pi,struct SpCdrZbIntfStruct *po);

/*�����ṹ����*/
struct SpAcctSnIntfStruct{

	struct SpAcctSnIntfStruct *pNext;
	char    sProvinceName[5];		/* ʡ����(HEB) */
	char    sAreaCode[5];		/* ���������� */
	char    sSpNbr[10];		/* SP_CP��� */
	char    sCallingNbr[21];		/* ���к��� */
	char    sCalledNbr[11];		/* ҵ�������� */
	char    sCnt[12];		/* ���� */
	char    sDuration[12];		/* ʱ�� */
	char    sFee[12];		/* ��� */
	char    sRate[16];		/* ���� */
	char    sNotes[21];		/* ��ע */
	struct SpAcctSnIntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSpAcctSnIntfStruct{

	char    sProvinceName[4];		/* ʡ����(HEB) */
	char    sAreaCode[4];		/* ���������� */
	char    sSpNbr[9];		/* SP_CP��� */
	char    sCallingNbr[20];		/* ���к��� */
	char    sCalledNbr[10];		/* ҵ�������� */
	char    sCnt[11];		/* ���� */
	char    sDuration[11];		/* ʱ�� */
	char    sFee[11];		/* ��� */
	char    sRate[15];		/* ���� */
	char    sNotes[20];		/* ��ע */
};

void mvitem_mfspacctsnintf(struct SpAcctSnIntfStruct *pi,struct FSpAcctSnIntfStruct *po);
void mvitem_fmspacctsnintf(struct FSpAcctSnIntfStruct *pi,struct SpAcctSnIntfStruct *po);

void mvitem_mfznwgjacct(struct ZnwGjAcctStruct *pi,struct FZnwGjAcctStruct *po);
/*�����ṹ����*/
struct SpAcctZbIntfStruct{

	struct SpAcctZbIntfStruct *pNext;
	char    sCallingNbr[21];		/* ���к��� */
	char    sCalledNbr[11];		/* ҵ�������� */
	char    sCnt[12];		/* ���� */
	char    sDuration[12];		/* ʱ�� */
	char    sFee[12];		/* ��� */
	struct SpAcctZbIntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FSpAcctZbIntfStruct{

	char    sCallingNbr[20];		/* ���к��� */
	char    sCalledNbr[10];		/* ҵ�������� */
	char    sCnt[11];		/* ���� */
	char    sDuration[11];		/* ʱ�� */
	char    sFee[11];		/* ��� */
};

void mvitem_mfspacctzbintf(struct SpAcctZbIntfStruct *pi,struct FSpAcctZbIntfStruct *po);




/*�����ṹ����*/
struct NewCriTicketStruct{

	struct NewCriTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sInCityCode[4];		/* ����ͨ�����д��� */
	char    sOutCityCode[4];		/* ����ͨ�����д��� */
	char    sLinkRef[7];		/* ���ο� */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[26];		/* �û����� */
	char    sModifyTag[2];		/* �޸�ָʾ */
	char    sNbrType[2];		/* �������� */
	char    sNbrPlan[2];		/* ѡ�ŷ��� */
	char    sOtherParty[26];		/* �Զ˺��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sServiceCode[3];		/* ҵ����� */
	char    sDupServiceType[2];		/* ˫��ҵ������ */
	char    sDupServiceCode[3];		/* ˫��ҵ���� */
	char    sAckChannel[2];		/* Ҫ�������ͨ�� */
	char    sUseChannel[2];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[2];		/* ҵ��͸���� */
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
	char    sMsc[16];		/* MSC ��ʶ */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* �ƶ��豸����� */
	char    sStartDate[9];		/* ͨ������ */
	char    sStartTime[7];		/* ͨ����ʼʱ�� */
	char    sPayUnit[7];		/* ���ѵ�λ */
	char    sFlowRef[7];		/* �������ο� */
	char    sTollCode[2];		/* ��;�Ѵ��� */
	char    sOtherCode[3];		/* �������Ѵ��� */
	char    sRoamFee[10];		/* ���λ��� */
	char    sTollFee[7];		/* ��;���� */
	char    sOtherFee[7];		/* �������� */
	char    sPayItem[2];		/* �շѵ���Ŀ */
	char    sSystemType[2];		/* ϵͳ���ͱ�ʶ */
	char    sRateIndication[2];	/* ����ָʾ��ʶ */
	char    sHotBillingTag[2];	/* �ȼƷѱ�ʶ */
	char    sImei[26];		/* IMEI */
	char    sReserve2[31];		/* �����ֶ�1 */
	struct NewCriTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FNewCriTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sInCityCode[3];		/* ����ͨ�����д��� */
	char    sOutCityCode[3];		/* ����ͨ�����д��� */
	char    sLinkRef[6];		/* ���ο� */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[25];		/* �û����� */
	char    sModifyTag[1];		/* �޸�ָʾ */
	char    sNbrType[1];		/* �������� */
	char    sNbrPlan[1];		/* ѡ�ŷ��� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sServiceType[1];		/* ҵ������ */
	char    sServiceCode[2];		/* ҵ����� */
	char    sDupServiceType[1];		/* ˫��ҵ������ */
	char    sDupServiceCode[2];		/* ˫��ҵ���� */
	char    sAckChannel[1];		/* Ҫ�������ͨ�� */
	char    sUseChannel[1];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[1];		/* ҵ��͸���� */
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
	char    sMsc[15];		/* MSC ��ʶ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* �ƶ��豸����� */
	char    sStartDate[8];		/* ͨ������ */
	char    sStartTime[6];		/* ͨ����ʼʱ�� */
	char    sPayUnit[6];		/* ���ѵ�λ */
	char    sFlowRef[6];		/* �������ο� */
	char    sTollCode[1];		/* ��;�Ѵ��� */
	char    sOtherCode[2];		/* �������Ѵ��� */
	char    sRoamFee[9];		/* ���λ��� */
	char    sTollFee[6];		/* ��;���� */
	char    sOtherFee[6];		/* �������� */
	char    sPayItem[1];		/* �շѵ���Ŀ */
	char    sSystemType[1];		/* ϵͳ���ͱ�ʶ */
	char    sRateIndication[1];	/* ����ָʾ��ʶ */
	char    sHotBillingTag[1];	/* �ȼƷѱ�ʶ */
	char    sImei[25];		/* IMEI */
	char    sReserve2[30];		/* �����ֶ�1 */
};

/*�����ṹ����*/
struct NewCiiTicketStruct{

	struct NewCiiTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sInCityCode[4];		/* ����ͨ�����д��� */
	char    sOutCityCode[4];		/* ����ͨ�����д��� */
	char    sLinkRef[7];		/* ���ο� */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[26];		/* �û����� */
	char    sModifyTag[2];		/* �޸�ָʾ */
	char    sNbrType[2];		/* �������� */
	char    sNbrPlan[2];		/* ѡ�ŷ��� */
	char    sOtherParty[26];		/* �Զ˺��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sServiceCode[3];		/* ҵ����� */
	char    sDupServiceType[2];		/* ˫��ҵ������ */
	char    sDupServiceCode[3];		/* ˫��ҵ���� */
	char    sAckChannel[2];		/* Ҫ�������ͨ�� */
	char    sUseChannel[2];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[2];		/* ҵ��͸���� */
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
	char    sMsc[16];		/* MSC ��ʶ */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* �ƶ��豸����� */
	char    sStartDate[9];		/* ͨ������ */
	char    sStartTime[7];		/* ͨ����ʼʱ�� */
	char    sPayUnit[7];		/* ���ѵ�λ */
	char    sFlowRef[7];		/* �������ο� */
	char    sFee[10];		/* �ܻ��� */
	char    sPayItem[2];		/* �շѵ���Ŀ */
	char    sSystemType[2];		/* ϵͳ���ͱ�ʶ */
	char    sRateIndication[2];	/* ����ָʾ��ʶ */
	char    sHotBillingTag[2];	/* �ȼƷѱ�ʶ */
	char    sVhe[2];		/* VHE */
	char    sInterScpFlag[11];	/* ������������ʶ */
	char    sReserve2[17];		/* �����ֶ�1 */
	struct NewCiiTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FNewCiiTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sInCityCode[3];		/* ����ͨ�����д��� */
	char    sOutCityCode[3];		/* ����ͨ�����д��� */
	char    sLinkRef[6];		/* ���ο� */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sMsisdn[25];		/* �û����� */
	char    sModifyTag[1];		/* �޸�ָʾ */
	char    sNbrType[1];		/* �������� */
	char    sNbrPlan[1];		/* ѡ�ŷ��� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sServiceType[1];		/* ҵ������ */
	char    sServiceCode[2];		/* ҵ����� */
	char    sDupServiceType[1];		/* ˫��ҵ������ */
	char    sDupServiceCode[2];		/* ˫��ҵ���� */
	char    sAckChannel[1];		/* Ҫ�������ͨ�� */
	char    sUseChannel[1];		/* ʹ�õ�����ͨ�� */
	char    sTransparentFlag[1];		/* ҵ��͸���� */
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
	char    sMsc[15];		/* MSC ��ʶ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* �ƶ��豸����� */
	char    sStartDate[8];		/* ͨ������ */
	char    sStartTime[6];		/* ͨ����ʼʱ�� */
	char    sPayUnit[6];		/* ���ѵ�λ */
	char    sFlowRef[6];		/* �������ο� */
	char    sFee[9];		/* �ܻ��� */
	char    sPayItem[1];		/* �շѵ���Ŀ */
	char    sSystemType[1];		/* ϵͳ���ͱ�ʶ */
	char    sRateIndication[1];	/* ����ָʾ��ʶ */
	char    sHotBillingTag[1];	/* �ȼƷѱ�ʶ */
	char    sVhe[1];		/* VHE */
	char    sInterScpFlag[10];	/* ������������ʶ */
	char    sReserve2[16];		/* �����ֶ�1 */
};
/*�����ṹ����*/
struct NewTrsTicketStruct{

	struct NewTrsTicketStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sInCityCode[4];		/* ����ͨ�����д��� */
	char    sOutCityCode[4];		/* ����ͨ�����д��� */
	char    sLinkRef[7];		/* ���ο� */
	char    sReserve1[2];		/* RESERVE1 */
	char    sImsi[16];		/* IMSI */
	char    sThirdParty[26];		/* ���к���A */
	char    sMsisdn[26];		/* �û����� */
	char    sOtherParty[26];		/* �Զ˺��� */
	char    sServiceType[2];		/* ҵ������ */
	char    sServiceCode[3];		/* ҵ����� */
	char    sReserve2[10];		/* ϵͳ����2 */
	char    sMsc[16];		/* MSC ��ʶ */
	char    sLac[6];		/* LAC */
	char    sCellID[6];		/* CELL_ID */
	char    sServType[2];		/* �ƶ��豸����� */
	char    sStartDate[9];		/* ͨ������ */
	char    sStartTime[7];		/* ͨ����ʼʱ�� */
	char    sPayUnit[7];		/* ���ѵ�λ */
	char    sSystemType[2];		/* ϵͳ���ͱ�ʶ */
	char    sRateIndication[2];	/* ����ָʾ��ʶ */
	char    sHotBillingTag[2];	/* �ȼƷѱ�ʶ */
	char    sImei[26];		/* IMEI */
	char    sReserve3[52];		/* ����3 */
	struct NewTrsTicketStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FNewTrsTicketStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sInCityCode[3];		/* ����ͨ�����д��� */
	char    sOutCityCode[3];		/* ����ͨ�����д��� */
	char    sLinkRef[6];		/* ���ο� */
	char    sReserve1[1];		/* RESERVE1 */
	char    sImsi[15];		/* IMSI */
	char    sThirdParty[25];		/* ���к���A */
	char    sMsisdn[25];		/* �û����� */
	char    sOtherParty[25];		/* �Զ˺��� */
	char    sServiceType[1];		/* ҵ������ */
	char    sServiceCode[2];		/* ҵ����� */
	char    sReserve2[9];		/* ϵͳ����2 */
	char    sMsc[15];		/* MSC ��ʶ */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sServType[1];		/* �ƶ��豸����� */
	char    sStartDate[8];		/* ͨ������ */
	char    sStartTime[6];		/* ͨ����ʼʱ�� */
	char    sPayUnit[6];		/* ���ѵ�λ */
	char    sSystemType[1];		/* ϵͳ���ͱ�ʶ */
	char    sRateIndication[1];	/* ����ָʾ��ʶ */
	char    sHotBillingTag[1];	/* �ȼƷѱ�ʶ */
	char    sImei[25];		/* IMEI */
	char    sReserve3[51];		/* ����3 */
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

/*�����ṹ����*/
struct GprsHeadStruct{

	struct GprsHeadStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sProvCode[4];		/* ʡ�ִ��� */
	char    sFileFlag[5];		/* �ļ���־ */
	char    sFileSeq[5];		/* �ļ����к� */
	char    sFileVersion[3];		/* �ļ��汾�� */
	char    sFileCreatDate[9];		/* �ļ��������� */
	char    sFirstCallDate[9];		/* �״��������� */
	char    sFirstCallTime[7];		/* �״�����ʱ�� */
	char    sLastCallDate[9];		/* ĩ���������� */
	char    sLastCallTime[7];		/* ĩ������ʱ�� */
	char    sTotalCnt[11];		/* �ܼ�¼�� */
	char    sTotalFee[16];		/* �ܷ��� */
	char    sNouse[343];		/* δ�� */
	struct GprsHeadStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FGprsHeadStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sProvCode[3];		/* ʡ�ִ��� */
	char    sFileFlag[4];		/* �ļ���־ */
	char    sFileSeq[4];		/* �ļ����к� */
	char    sFileVersion[2];		/* �ļ��汾�� */
	char    sFileCreatDate[8];		/* �ļ��������� */
	char    sFirstCallDate[8];		/* �״��������� */
	char    sFirstCallTime[6];		/* �״�����ʱ�� */
	char    sLastCallDate[8];		/* ĩ���������� */
	char    sLastCallTime[6];		/* ĩ������ʱ�� */
	char    sTotalCnt[10];		/* �ܼ�¼�� */
	char    sTotalFee[15];		/* �ܷ��� */
	char    sNouse[342];		/* δ�� */
};

/*�����ṹ����*/
struct GprsTicketIntfStruct{

	struct GprsTicketIntfStruct *pNext;
	char    sRecordType[3];		/* ��¼���� */
	char    sRoamType[3];		/* �������� */
	char    sImsi[16];		/* �ֻ��ն˵�IMSI */
	char    sMsisdn[16];		/* �ֻ��ն˵�ISDN */
	char    sSgsn[17];		/* ���λỰ��ʼSGSNIP��ַ */
	char    sSgsnChange[2];		/* SGSN�ı��ʶ */
	char    sGgsn[17];		/* ���λỰGGSNIP��ַ */
	char    sServedPdpAddress[17];		/* �ֻ��ն�PDPIP��ַ */
	char    sApnNi[64];		/* ����������ʶ */
	char    sApnOi[38];		/* �������Ӫ�̱�ʶ */
	char    sReserv1[15];		/* �����ֶ�1 */
	char    sCallDuration[7];		/* ������ʱ�� */
	char    sPartialType[2];		/* �ֲ����ͱ�ʶ�� */
	char    sCloseCause[3];		/* �ж�ԭ�� */
	char    sStartTime[15];		/* ���λỰ���ӿ�ʼʱ�� */
	char    sNiPdp[2];		/* �������б�־ */
	char    sChargingID[11];		/* PDP�����ļƷѱ�ʶ */
	char    sLac[6];		/* λ������ */
	char    sCellID[6];		/* С����ʶ */
	char    sVisitCityCode[4];		/* ���εس��д��� */
	char    sReserv2[11];		/* �����ֶ�2 */
	char    sRoamRemark[11];		/* ���εر��� */
	char    sImei[20];		/* �ֻ����� */
	char    sDataFlowdn[11];		/* �������� */
	char    sDataFlowup[11];		/* �������� */
	char    sChargeItem[2];		/* �Ʒ���Ŀ */
	char    sChargeUnit[11];		/* �Ʒ�ȡ�� */
	char    sChargeOperation[3];		/* �Ʒ�ҵ�� */
	char    sTotalFee[10];		/* ���� */
	char    sReserv3[94];		/* �����ֶ�3 */
	struct GprsTicketIntfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FGprsTicketIntfStruct{

	char    sRecordType[2];		/* ��¼���� */
	char    sRoamType[2];		/* �������� */
	char    sImsi[15];		/* �ֻ��ն˵�IMSI */
	char    sMsisdn[15];		/* �ֻ��ն˵�ISDN */
	char    sSgsn[16];		/* ���λỰ��ʼSGSNIP��ַ */
	char    sSgsnChange[1];		/* SGSN�ı��ʶ */
	char    sGgsn[16];		/* ���λỰGGSNIP��ַ */
	char    sServedPdpAddress[16];		/* �ֻ��ն�PDPIP��ַ */
	char    sApnNi[63];		/* ����������ʶ */
	char    sApnOi[37];		/* �������Ӫ�̱�ʶ */
	char    sReserv1[14];		/* �����ֶ�1 */
	char    sCallDuration[6];		/* ������ʱ�� */
	char    sPartialType[1];		/* �ֲ����ͱ�ʶ�� */
	char    sCloseCause[2];		/* �ж�ԭ�� */
	char    sStartTime[14];		/* ���λỰ���ӿ�ʼʱ�� */
	char    sNiPdp[1];		/* �������б�־ */
	char    sChargingID[10];		/* PDP�����ļƷѱ�ʶ */
	char    sLac[5];		/* λ������ */
	char    sCellID[5];		/* С����ʶ */
	char    sVisitCityCode[3];		/* ���εس��д��� */
	char    sReserv2[10];		/* �����ֶ�2 */
	char    sRoamRemark[10];		/* ���εر��� */
	char    sImei[19];		/* �ֻ����� */
	char    sDataFlowdn[10];		/* �������� */
	char    sDataFlowup[10];		/* �������� */
	char    sChargeItem[1];		/* �Ʒ���Ŀ */
	char    sChargeUnit[10];		/* �Ʒ�ȡ�� */
	char    sChargeOperation[2];		/* �Ʒ�ҵ�� */
	char    sTotalFee[9];		/* ���� */
	char    sReserv3[93];		/* �����ֶ�3 */
};
void mvitem_mfgprshead(struct GprsHeadStruct *pi,struct FGprsHeadStruct *po);
void mvitem_mfgprsticketintf(struct GprsTicketIntfStruct *pi,struct FGprsTicketIntfStruct *po);


#include <bintree.h>

/*�ص�����*/
#define KEYLEN sizeof(unsigned char)*16
struct KeyStruct{
	unsigned char sKey[KEYLEN];/*Ϊ��ʡ�ռ䲻ʹ��char,��ʹ��unsigned char ����*/
	time_t tDateTime;/*time_t����ʱ�䣬�����ж�Щ�����Ƿ��Ѿ����ڲ���Ҫ����*/	
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
