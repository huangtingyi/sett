#ifndef __USER_TICKET_H__
#define __USER_TICKET_H__
/* ����ṹ��������*/
struct PayRelationStructIn{

#ifndef PAY_RELATION_BUFLEN_IN
#define PAY_RELATION_BUFLEN_IN		300
#endif

	struct PayRelationStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �ͻ���� */
	LONGINT alCustomerNo[PAY_RELATION_BUFLEN_IN];
		/* �û���� */
	LONGINT alUserNo[PAY_RELATION_BUFLEN_IN];
		/* ���ô��� */
	char    asChargeCode[PAY_RELATION_BUFLEN_IN][6];
		/* �ʺ���Чʱ�� */
	char    asValidDate[PAY_RELATION_BUFLEN_IN][15];
		/* �ʺ�ʧЧʱ�� */
	char    asInvalidDate[PAY_RELATION_BUFLEN_IN][15];
		/* �����ʺ� */
	LONGINT alPayNo[PAY_RELATION_BUFLEN_IN];
		/* ������ */
	char    asLocalNet[PAY_RELATION_BUFLEN_IN][7];
};

/*�����ṹ����*/
struct PayRelationStruct{

	struct PayRelationStruct *pNext;
	LONGINT lCustomerNo;		/* �ͻ���� */
	LONGINT lUserNo;		/* �û���� */
	char    sChargeCode[6];		/* ���ô��� */
	char    sValidDate[15];		/* �ʺ���Чʱ�� */
	char    sInvalidDate[15];		/* �ʺ�ʧЧʱ�� */
	LONGINT lPayNo;		/* �����ʺ� */
	char    sLocalNet[7];		/* ������ */
	struct PayRelationStruct *pLoadNext;
};

int EGetPayRelationToStruct(struct PayRelationStruct *p,
	struct PayRelationStructIn *pSource);	
int InitPayRelation(struct PayRelationStruct **pptHead);
void DestroyPayRelation(struct PayRelationStruct *ptHead);

/* ����ṹ��������*/
struct AtomBillIntfStructIn{

#ifndef ATOM_BILL_INTF_BUFLEN_IN
#define ATOM_BILL_INTF_BUFLEN_IN		300
#endif

	struct AtomBillIntfStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �������� */
	char    asTeleType[ATOM_BILL_INTF_BUFLEN_IN][6];
		/* ������ */
	char    asLocalNet[ATOM_BILL_INTF_BUFLEN_IN][7];
		/* ����ԭ���ײ� */
	char    asBillAtom[ATOM_BILL_INTF_BUFLEN_IN][6];
		/* �������� */
	int     aiTicketTypeID[ATOM_BILL_INTF_BUFLEN_IN];
		/* �ʷ����� */
	char    asType[ATOM_BILL_INTF_BUFLEN_IN][2];
		/* ���� */
	LONGINT alRate[ATOM_BILL_INTF_BUFLEN_IN];
		/* ���ʲ���1 */
	int     aiParam1[ATOM_BILL_INTF_BUFLEN_IN];
		/* ���ʲ���2 */
	int     aiParam2[ATOM_BILL_INTF_BUFLEN_IN];
		/* ���ʲ���3 */
	int     aiParam3[ATOM_BILL_INTF_BUFLEN_IN];
		/* ���� */
	char    asRemarks[ATOM_BILL_INTF_BUFLEN_IN][61];
};


/*�����ṹ����*/
struct AtomBillIntfStruct{

	struct AtomBillIntfStruct *pNext;
	char    sTeleType[6];		/* �������� */
	char    sLocalNet[7];		/* ������ */
	char    sBillAtom[6];		/* ����ԭ���ײ� */
	int     iTicketTypeID;		/* �������� */
	char    sType[2];		/* �ʷ����� */
	LONGINT lRate;		/* ���� */
	int     iParam1;		/* ���ʲ���1 */
	int     iParam2;		/* ���ʲ���2 */
	int     iParam3;		/* ���ʲ���3 */
	char    sRemarks[61];		/* ���� */
	struct AtomBillIntfStruct *pLoadNext;
};
int InitAtomBillIntf(struct AtomBillIntfStruct **pptHead);
void DestroyAtomBillIntf(struct AtomBillIntfStruct *ptHead);
int EGetAtomBillIntfToStruct(struct AtomBillIntfStruct *p,
	struct AtomBillIntfStructIn *pSource);
	
/* ����ṹ��������*/
struct InfoLineStructIn{

#ifndef INFO_LINE_BUFLEN_IN
#define INFO_LINE_BUFLEN_IN		300
#endif

	struct InfoLineStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ҵ����� */
	char    asDeviceNumber[INFO_LINE_BUFLEN_IN][21];
		/* �ͻ��� */
	LONGINT alCustomerNo[INFO_LINE_BUFLEN_IN];
		/* �û��� */
	LONGINT alUserNo[INFO_LINE_BUFLEN_IN];
		/* �����˺� */
	LONGINT alAssureNo[INFO_LINE_BUFLEN_IN];
		/* �û����� */
	char    asUserPwd[INFO_LINE_BUFLEN_IN][23];
		/* �ͻ����ͣ����š���λ�����ˣ�code_kind */
	char    asKindCode[INFO_LINE_BUFLEN_IN][6];
		/* �û�״̬ */
	char    asStatusCode[INFO_LINE_BUFLEN_IN][6];
		/* �û��ײ� */
	char    asUserDinner[INFO_LINE_BUFLEN_IN][6];
		/* �ط��ײ� */
	char    asSpecDinner[INFO_LINE_BUFLEN_IN][6];
		/* �����ײ� */
	char    asCreditDinner[INFO_LINE_BUFLEN_IN][6];
		/* ���м��� */
	char    asCallLevel[INFO_LINE_BUFLEN_IN][6];
		/* ���Ŵ��� */
	char    asGroupCode[INFO_LINE_BUFLEN_IN][6];
		/* ������ʽ���������̻����м̣�code_innet_type */
	char    asInNetType[INFO_LINE_BUFLEN_IN][7];
		/* �������� */
	char    asInNetDate[INFO_LINE_BUFLEN_IN][15];
		/* ͣ������ */
	char    asStopDate[INFO_LINE_BUFLEN_IN][15];
		/* ���� */
	char    asDeptNo[INFO_LINE_BUFLEN_IN][7];
		/* ������ */
	char    asLocalNet[INFO_LINE_BUFLEN_IN][7];
		/* ������ */
	char    asLongNumber[INFO_LINE_BUFLEN_IN][21];
		/* ��ע */
	char    asMemo[INFO_LINE_BUFLEN_IN][61];
		/* ����Ա */
	char    asOperNo[INFO_LINE_BUFLEN_IN][7];
		/* ����Ա���ڲ��� */
	char    asOperDeptNo[INFO_LINE_BUFLEN_IN][7];
		/* ����Ա������ */
	char    asOperLocalNet[INFO_LINE_BUFLEN_IN][7];
		/* �������� */
	char    asOperDate[INFO_LINE_BUFLEN_IN][15];
		/* ��־ */
	char    asFlag[INFO_LINE_BUFLEN_IN][2];
		/* װ������(IC�ٲ��绰����ͨ�����绰) code_fix_type */
	char    asFixType[INFO_LINE_BUFLEN_IN][6];
		/* װ����ַ */
	char    asFixAddress[INFO_LINE_BUFLEN_IN][101];
		/* ������code_home_bur */
	char    asHomeBur[INFO_LINE_BUFLEN_IN][7];
		/* ��ͬ��(ǰ̨����) */
	char    asContractNo[INFO_LINE_BUFLEN_IN][13];
};


/*�����ṹ����*/
struct InfoLineStruct{

	struct InfoLineStruct *pNext;
	char    sDeviceNumber[21];		/* ҵ����� */
	LONGINT lCustomerNo;		/* �ͻ��� */
	LONGINT lUserNo;		/* �û��� */
	LONGINT lAssureNo;		/* �����˺� */
	char    sUserPwd[23];		/* �û����� */
	char    sKindCode[6];		/* �ͻ����ͣ����š���λ�����ˣ�code_kind */
	char    sStatusCode[6];		/* �û�״̬ */
	char    sUserDinner[6];		/* �û��ײ� */
	char    sSpecDinner[6];		/* �ط��ײ� */
	char    sCreditDinner[6];		/* �����ײ� */
	char    sCallLevel[6];		/* ���м��� */
	char    sGroupCode[6];		/* ���Ŵ��� */
	char    sInNetType[7];		/* ������ʽ���������̻����м̣�code_innet_type */
	char    sInNetDate[15];		/* �������� */
	char    sStopDate[15];		/* ͣ������ */
	char    sDeptNo[7];		/* ���� */
	char    sLocalNet[7];		/* ������ */
	char    sLongNumber[21];		/* ������ */
	char    sMemo[61];		/* ��ע */
	char    sOperNo[7];		/* ����Ա */
	char    sOperDeptNo[7];		/* ����Ա���ڲ��� */
	char    sOperLocalNet[7];		/* ����Ա������ */
	char    sOperDate[15];		/* �������� */
	char    sFlag[2];		/* ��־ */
	char    sFixType[6];		/* װ������(IC�ٲ��绰����ͨ�����绰) code_fix_type */
	char    sFixAddress[101];		/* װ����ַ */
	char    sHomeBur[7];		/* ������code_home_bur */
	char    sContractNo[13];		/* ��ͬ��(ǰ̨����) */
	struct InfoLineStruct *pLoadNext;
};
int InitInfoLine(struct InfoLineStruct **pptHead);
void DestroyInfoLine(struct InfoLineStruct *ptHead);
int EGetInfoLineToStruct(struct InfoLineStruct *p,
	struct InfoLineStructIn *pSource);
	
/* ����ṹ��������*/
struct DataTicketBStructIn{

#ifndef DATA_TICKET_B_BUFLEN_IN
#define DATA_TICKET_B_BUFLEN_IN		300
#endif

	struct DataTicketBStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asMscAreaCode[DATA_TICKET_B_BUFLEN_IN][6];
	char    asMsc[DATA_TICKET_B_BUFLEN_IN][6];
	char    asRecordType[DATA_TICKET_B_BUFLEN_IN][3];
	char    asCallingHead[DATA_TICKET_B_BUFLEN_IN][6];
	char    asHomeAreaCode[DATA_TICKET_B_BUFLEN_IN][11];
	char    asCallingNbr[DATA_TICKET_B_BUFLEN_IN][31];
	char    asCallingDistanceType[DATA_TICKET_B_BUFLEN_IN][2];
	char    asCallingCarrierID[DATA_TICKET_B_BUFLEN_IN][3];
	char    asCallingServiceClass[DATA_TICKET_B_BUFLEN_IN][3];
	char    asCallingServiceDivision[DATA_TICKET_B_BUFLEN_IN][3];
	char    asOriCallingNbr[DATA_TICKET_B_BUFLEN_IN][31];
	char    asCalledNbrHead[DATA_TICKET_B_BUFLEN_IN][6];
	char    asCalledCode[DATA_TICKET_B_BUFLEN_IN][11];
	char    asCalledNbr[DATA_TICKET_B_BUFLEN_IN][31];
	char    asCalledDistanceType[DATA_TICKET_B_BUFLEN_IN][2];
	char    asCalledCarrierID[DATA_TICKET_B_BUFLEN_IN][3];
	char    asCalledServiceClass[DATA_TICKET_B_BUFLEN_IN][3];
	char    asCalledServiceDivision[DATA_TICKET_B_BUFLEN_IN][3];
	char    asOriCalledNbr[DATA_TICKET_B_BUFLEN_IN][31];
	char    asUserType[DATA_TICKET_B_BUFLEN_IN][3];
	char    asCalledZoneCode[DATA_TICKET_B_BUFLEN_IN][11];
	char    asServiceType[DATA_TICKET_B_BUFLEN_IN][3];
	char    asNetType[DATA_TICKET_B_BUFLEN_IN][4];
	char    asCardID[DATA_TICKET_B_BUFLEN_IN][31];
	char    asTrunkIn[DATA_TICKET_B_BUFLEN_IN][21];
	char    asTrunkOut[DATA_TICKET_B_BUFLEN_IN][21];
	char    asStartDate[DATA_TICKET_B_BUFLEN_IN][9];
	char    asStartTime[DATA_TICKET_B_BUFLEN_IN][7];
	char    asStopDate[DATA_TICKET_B_BUFLEN_IN][9];
	char    asStopTime[DATA_TICKET_B_BUFLEN_IN][7];
	int     aiDuration[DATA_TICKET_B_BUFLEN_IN];
	int     aiCallDuration[DATA_TICKET_B_BUFLEN_IN];
	char    asBillingType[DATA_TICKET_B_BUFLEN_IN][20];
	int     aiCount[DATA_TICKET_B_BUFLEN_IN];
	int     aiBaseTollCharge[DATA_TICKET_B_BUFLEN_IN];
	int     aiDisctTollCharge[DATA_TICKET_B_BUFLEN_IN];
	int     aiTollCharge[DATA_TICKET_B_BUFLEN_IN];
	int     aiBaseRoamCharge[DATA_TICKET_B_BUFLEN_IN];
	int     aiDisctRoamCharge[DATA_TICKET_B_BUFLEN_IN];
	int     aiRoamCharge[DATA_TICKET_B_BUFLEN_IN];
	LONGINT alTotalCharge[DATA_TICKET_B_BUFLEN_IN];
	char    asCallingCityCode[DATA_TICKET_B_BUFLEN_IN][4];
	char    asFileName[DATA_TICKET_B_BUFLEN_IN][51];
	int     aiErrID[DATA_TICKET_B_BUFLEN_IN];
	char    asCardType[DATA_TICKET_B_BUFLEN_IN][3];
	char    asRoamType[DATA_TICKET_B_BUFLEN_IN][2];
	char    asDistanceType[DATA_TICKET_B_BUFLEN_IN][2];
	char    asOppIpType[DATA_TICKET_B_BUFLEN_IN][2];
	char    asOppTollType1[DATA_TICKET_B_BUFLEN_IN][2];
	char    asOppTollType2[DATA_TICKET_B_BUFLEN_IN][2];
	int     aiCallingTypeID[DATA_TICKET_B_BUFLEN_IN];
	int     aiCalledTypeID[DATA_TICKET_B_BUFLEN_IN];
	int     aiTicketTypeID[DATA_TICKET_B_BUFLEN_IN];
	int     aiRoamFee[DATA_TICKET_B_BUFLEN_IN];
	int     aiTollFee[DATA_TICKET_B_BUFLEN_IN];
	int     aiAddFee[DATA_TICKET_B_BUFLEN_IN];
	int     aiOriTypeID[DATA_TICKET_B_BUFLEN_IN];
	int     aiRoamOri[DATA_TICKET_B_BUFLEN_IN];
	int     aiTollOri[DATA_TICKET_B_BUFLEN_IN];
	int     aiAddOri[DATA_TICKET_B_BUFLEN_IN];
	char    asCallGrpType[DATA_TICKET_B_BUFLEN_IN][2];
	char    asRowID[DATA_TICKET_B_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct DataTicketBStruct{

	struct DataTicketBStruct *pNext;
	char    sMscAreaCode[6];
	char    sMsc[6];
	char    sRecordType[3];
	char    sCallingHead[6];
	char    sHomeAreaCode[11];
	char    sCallingNbr[31];
	char    sCallingDistanceType[2];
	char    sCallingCarrierID[3];
	char    sCallingServiceClass[3];
	char    sCallingServiceDivision[3];
	char    sOriCallingNbr[31];
	char    sCalledNbrHead[6];
	char    sCalledCode[11];
	char    sCalledNbr[31];
	char    sCalledDistanceType[2];
	char    sCalledCarrierID[3];
	char    sCalledServiceClass[3];
	char    sCalledServiceDivision[3];
	char    sOriCalledNbr[31];
	char    sUserType[3];
	char    sCalledZoneCode[11];
	char    sServiceType[3];
	char    sNetType[4];
	char    sCardID[31];
	char    sTrunkIn[21];
	char    sTrunkOut[21];
	char    sStartDate[9];
	char    sStartTime[7];
	char    sStopDate[9];
	char    sStopTime[7];
	int     iDuration;
	int     iCallDuration;
	char    sBillingType[20];
	int     iCount;
	int     iBaseTollCharge;
	int     iDisctTollCharge;
	int     iTollCharge;
	int     iBaseRoamCharge;
	int     iDisctRoamCharge;
	int     iRoamCharge;
	LONGINT lTotalCharge;
	char    sCallingCityCode[4];
	char    sFileName[51];
	int     iErrID;
	char    sCardType[3];
	char    sRoamType[2];
	char    sDistanceType[2];
	char    sOppIpType[2];
	char    sOppTollType1[2];
	char    sOppTollType2[2];
	int     iCallingTypeID;
	int     iCalledTypeID;
	int     iTicketTypeID;
	int     iRoamFee;
	int     iTollFee;
	int     iAddFee;
	int     iOriTypeID;
	int     iRoamOri;
	int     iTollOri;
	int     iAddOri;
	char    sCallGrpType[2];
	char    sRowID[19];		/* ��¼���� */
	struct DataTicketBStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FDataTicketBStruct{

	char    sMscAreaCode[5];
	char    sMsc[5];
	char    sRecordType[2];
	char    sCallingHead[5];
	char    sHomeAreaCode[10];
	char    sCallingNbr[30];
	char    sCallingDistanceType[1];
	char    sCallingCarrierID[2];
	char    sCallingServiceClass[2];
	char    sCallingServiceDivision[2];
	char    sOriCallingNbr[30];
	char    sCalledNbrHead[5];
	char    sCalledCode[10];
	char    sCalledNbr[30];
	char    sCalledDistanceType[1];
	char    sCalledCarrierID[2];
	char    sCalledServiceClass[2];
	char    sCalledServiceDivision[2];
	char    sOriCalledNbr[30];
	char    sUserType[2];
	char    sCalledZoneCode[10];
	char    sServiceType[2];
	char    sNetType[3];
	char    sCardID[30];
	char    sTrunkIn[20];
	char    sTrunkOut[20];
	char    sStartDate[8];
	char    sStartTime[6];
	char    sStopDate[8];
	char    sStopTime[6];
	char    sDuration[8];
	char    sCallDuration[8];
	char    sBillingType[19];
	char    sCount[6];
	char    sBaseTollCharge[8];
	char    sDisctTollCharge[8];
	char    sTollCharge[8];
	char    sBaseRoamCharge[8];
	char    sDisctRoamCharge[8];
	char    sRoamCharge[8];
	char    sTotalCharge[10];
	char    sCallingCityCode[3];
	char    sFileName[50];
	char    sErrID[4];
	char    sCardType[2];
	char    sRoamType[1];
	char    sDistanceType[1];
	char    sOppIpType[1];
	char    sOppTollType1[1];
	char    sOppTollType2[1];
	char    sCallingTypeID[4];
	char    sCalledTypeID[4];
	char    sTicketTypeID[4];
	char    sRoamFee[8];
	char    sTollFee[8];
	char    sAddFee[8];
	char    sOriTypeID[4];
	char    sRoamOri[8];
	char    sTollOri[8];
	char    sAddOri[8];
	char    sCallGrpType[1];
};

void mvitem_mfdataticketb(struct DataTicketBStruct *pi,struct FDataTicketBStruct *po);
void mvitem_fmdataticketb(struct FDataTicketBStruct *pi,struct DataTicketBStruct *po);
int EGetDataTicketBToStruct(struct DataTicketBStruct *p,
	struct DataTicketBStructIn *pSource);

struct UDataTicketBStruct
{
	struct UDataTicketBStruct *pNext;
	char    sRoamType[2];
	char    sDistanceType[2];
	char    sOppIpType[2];
	char    sOppTollType1[2];
	char    sOppTollType2[2];
	int     iCallingTypeID;
	int     iCalledTypeID;
	int     iTicketTypeID;
	int     iRoamFee;
	int     iTollFee;
	int     iAddFee;
	int     iOriTypeID;
	int     iRoamOri;
	int     iTollOri;
	int     iAddOri;
	char    sCallGrpType[2];
	char    sRowID[19];
	struct UDataTicketBStruct *pLoadNext;
};

struct UDataTicketBStructUp
{
#ifndef DATA_TICKET_B_BUFLEN_OUT
#define DATA_TICKET_B_BUFLEN_OUT		300
#endif
	int	iCurPos;
	char	sTableName[31];	
	char    asRoamType[DATA_TICKET_B_BUFLEN_OUT][2];
	char    asDistanceType[DATA_TICKET_B_BUFLEN_OUT][2];
	char    asOppIpType[DATA_TICKET_B_BUFLEN_OUT][2];
	char    asOppTollType1[DATA_TICKET_B_BUFLEN_OUT][2];
	char    asOppTollType2[DATA_TICKET_B_BUFLEN_OUT][2];
	int     aiCallingTypeID[DATA_TICKET_B_BUFLEN_OUT];
	int     aiCalledTypeID[DATA_TICKET_B_BUFLEN_OUT];
	int     aiTicketTypeID[DATA_TICKET_B_BUFLEN_OUT];
	int     aiRoamFee[DATA_TICKET_B_BUFLEN_OUT];
	int     aiTollFee[DATA_TICKET_B_BUFLEN_OUT];
	int     aiAddFee[DATA_TICKET_B_BUFLEN_OUT];
	int     aiOriTypeID[DATA_TICKET_B_BUFLEN_OUT];
	int     aiRoamOri[DATA_TICKET_B_BUFLEN_OUT];
	int     aiTollOri[DATA_TICKET_B_BUFLEN_OUT];
	int     aiAddOri[DATA_TICKET_B_BUFLEN_OUT];
	char    asCallGrpType[DATA_TICKET_B_BUFLEN_OUT][2];
	char    asRowID[DATA_TICKET_B_BUFLEN_OUT][19];
};
int EUpdateStructToUDataTicketB(struct UDataTicketBStruct *p,
	int iUpdateFlag,struct UDataTicketBStructUp *pTarget); 
void mvitem_dataticketb2up(struct DataTicketBStruct *pi,struct UDataTicketBStruct *po);
#endif
