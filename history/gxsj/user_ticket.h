#ifndef __USER_TICKET_H__
#define __USER_TICKET_H__
/* 输入结构缓冲申明*/
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
		/* 客户编号 */
	LONGINT alCustomerNo[PAY_RELATION_BUFLEN_IN];
		/* 用户编号 */
	LONGINT alUserNo[PAY_RELATION_BUFLEN_IN];
		/* 费用代码 */
	char    asChargeCode[PAY_RELATION_BUFLEN_IN][6];
		/* 帐号生效时间 */
	char    asValidDate[PAY_RELATION_BUFLEN_IN][15];
		/* 帐号失效时间 */
	char    asInvalidDate[PAY_RELATION_BUFLEN_IN][15];
		/* 付费帐号 */
	LONGINT alPayNo[PAY_RELATION_BUFLEN_IN];
		/* 本地网 */
	char    asLocalNet[PAY_RELATION_BUFLEN_IN][7];
};

/*单个结构申明*/
struct PayRelationStruct{

	struct PayRelationStruct *pNext;
	LONGINT lCustomerNo;		/* 客户编号 */
	LONGINT lUserNo;		/* 用户编号 */
	char    sChargeCode[6];		/* 费用代码 */
	char    sValidDate[15];		/* 帐号生效时间 */
	char    sInvalidDate[15];		/* 帐号失效时间 */
	LONGINT lPayNo;		/* 付费帐号 */
	char    sLocalNet[7];		/* 本地网 */
	struct PayRelationStruct *pLoadNext;
};

int EGetPayRelationToStruct(struct PayRelationStruct *p,
	struct PayRelationStructIn *pSource);	
int InitPayRelation(struct PayRelationStruct **pptHead);
void DestroyPayRelation(struct PayRelationStruct *ptHead);

/* 输入结构缓冲申明*/
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
		/* 电信类型 */
	char    asTeleType[ATOM_BILL_INTF_BUFLEN_IN][6];
		/* 本地网 */
	char    asLocalNet[ATOM_BILL_INTF_BUFLEN_IN][7];
		/* 话费原子套餐 */
	char    asBillAtom[ATOM_BILL_INTF_BUFLEN_IN][6];
		/* 话单类型 */
	int     aiTicketTypeID[ATOM_BILL_INTF_BUFLEN_IN];
		/* 资费类型 */
	char    asType[ATOM_BILL_INTF_BUFLEN_IN][2];
		/* 费率 */
	LONGINT alRate[ATOM_BILL_INTF_BUFLEN_IN];
		/* 费率参数1 */
	int     aiParam1[ATOM_BILL_INTF_BUFLEN_IN];
		/* 费率参数2 */
	int     aiParam2[ATOM_BILL_INTF_BUFLEN_IN];
		/* 费率参数3 */
	int     aiParam3[ATOM_BILL_INTF_BUFLEN_IN];
		/* 描述 */
	char    asRemarks[ATOM_BILL_INTF_BUFLEN_IN][61];
};


/*单个结构申明*/
struct AtomBillIntfStruct{

	struct AtomBillIntfStruct *pNext;
	char    sTeleType[6];		/* 电信类型 */
	char    sLocalNet[7];		/* 本地网 */
	char    sBillAtom[6];		/* 话费原子套餐 */
	int     iTicketTypeID;		/* 话单类型 */
	char    sType[2];		/* 资费类型 */
	LONGINT lRate;		/* 费率 */
	int     iParam1;		/* 费率参数1 */
	int     iParam2;		/* 费率参数2 */
	int     iParam3;		/* 费率参数3 */
	char    sRemarks[61];		/* 描述 */
	struct AtomBillIntfStruct *pLoadNext;
};
int InitAtomBillIntf(struct AtomBillIntfStruct **pptHead);
void DestroyAtomBillIntf(struct AtomBillIntfStruct *ptHead);
int EGetAtomBillIntfToStruct(struct AtomBillIntfStruct *p,
	struct AtomBillIntfStructIn *pSource);
	
/* 输入结构缓冲申明*/
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
		/* 业务号码 */
	char    asDeviceNumber[INFO_LINE_BUFLEN_IN][21];
		/* 客户号 */
	LONGINT alCustomerNo[INFO_LINE_BUFLEN_IN];
		/* 用户号 */
	LONGINT alUserNo[INFO_LINE_BUFLEN_IN];
		/* 担保人号 */
	LONGINT alAssureNo[INFO_LINE_BUFLEN_IN];
		/* 用户密码 */
	char    asUserPwd[INFO_LINE_BUFLEN_IN][23];
		/* 客户类型（集团、单位、个人）code_kind */
	char    asKindCode[INFO_LINE_BUFLEN_IN][6];
		/* 用户状态 */
	char    asStatusCode[INFO_LINE_BUFLEN_IN][6];
		/* 用户套餐 */
	char    asUserDinner[INFO_LINE_BUFLEN_IN][6];
		/* 特服套餐 */
	char    asSpecDinner[INFO_LINE_BUFLEN_IN][6];
		/* 信用套餐 */
	char    asCreditDinner[INFO_LINE_BUFLEN_IN][6];
		/* 呼叫级别 */
	char    asCallLevel[INFO_LINE_BUFLEN_IN][6];
		/* 集团代码 */
	char    asGroupCode[INFO_LINE_BUFLEN_IN][6];
		/* 入网方式（公话、商话、中继）code_innet_type */
	char    asInNetType[INFO_LINE_BUFLEN_IN][7];
		/* 入网日期 */
	char    asInNetDate[INFO_LINE_BUFLEN_IN][15];
		/* 停机日期 */
	char    asStopDate[INFO_LINE_BUFLEN_IN][15];
		/* 部门 */
	char    asDeptNo[INFO_LINE_BUFLEN_IN][7];
		/* 本地网 */
	char    asLocalNet[INFO_LINE_BUFLEN_IN][7];
		/* 长号码 */
	char    asLongNumber[INFO_LINE_BUFLEN_IN][21];
		/* 备注 */
	char    asMemo[INFO_LINE_BUFLEN_IN][61];
		/* 操作员 */
	char    asOperNo[INFO_LINE_BUFLEN_IN][7];
		/* 操作员所在部门 */
	char    asOperDeptNo[INFO_LINE_BUFLEN_IN][7];
		/* 操作员本地网 */
	char    asOperLocalNet[INFO_LINE_BUFLEN_IN][7];
		/* 操作日期 */
	char    asOperDate[INFO_LINE_BUFLEN_IN][15];
		/* 标志 */
	char    asFlag[INFO_LINE_BUFLEN_IN][2];
		/* 装机类型(IC速拨电话、普通拨卡电话) code_fix_type */
	char    asFixType[INFO_LINE_BUFLEN_IN][6];
		/* 装机地址 */
	char    asFixAddress[INFO_LINE_BUFLEN_IN][101];
		/* 归属局code_home_bur */
	char    asHomeBur[INFO_LINE_BUFLEN_IN][7];
		/* 合同号(前台输入) */
	char    asContractNo[INFO_LINE_BUFLEN_IN][13];
};


/*单个结构申明*/
struct InfoLineStruct{

	struct InfoLineStruct *pNext;
	char    sDeviceNumber[21];		/* 业务号码 */
	LONGINT lCustomerNo;		/* 客户号 */
	LONGINT lUserNo;		/* 用户号 */
	LONGINT lAssureNo;		/* 担保人号 */
	char    sUserPwd[23];		/* 用户密码 */
	char    sKindCode[6];		/* 客户类型（集团、单位、个人）code_kind */
	char    sStatusCode[6];		/* 用户状态 */
	char    sUserDinner[6];		/* 用户套餐 */
	char    sSpecDinner[6];		/* 特服套餐 */
	char    sCreditDinner[6];		/* 信用套餐 */
	char    sCallLevel[6];		/* 呼叫级别 */
	char    sGroupCode[6];		/* 集团代码 */
	char    sInNetType[7];		/* 入网方式（公话、商话、中继）code_innet_type */
	char    sInNetDate[15];		/* 入网日期 */
	char    sStopDate[15];		/* 停机日期 */
	char    sDeptNo[7];		/* 部门 */
	char    sLocalNet[7];		/* 本地网 */
	char    sLongNumber[21];		/* 长号码 */
	char    sMemo[61];		/* 备注 */
	char    sOperNo[7];		/* 操作员 */
	char    sOperDeptNo[7];		/* 操作员所在部门 */
	char    sOperLocalNet[7];		/* 操作员本地网 */
	char    sOperDate[15];		/* 操作日期 */
	char    sFlag[2];		/* 标志 */
	char    sFixType[6];		/* 装机类型(IC速拨电话、普通拨卡电话) code_fix_type */
	char    sFixAddress[101];		/* 装机地址 */
	char    sHomeBur[7];		/* 归属局code_home_bur */
	char    sContractNo[13];		/* 合同号(前台输入) */
	struct InfoLineStruct *pLoadNext;
};
int InitInfoLine(struct InfoLineStruct **pptHead);
void DestroyInfoLine(struct InfoLineStruct *ptHead);
int EGetInfoLineToStruct(struct InfoLineStruct *p,
	struct InfoLineStructIn *pSource);
	
/* 输入结构缓冲申明*/
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


/*单个结构申明*/
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
	char    sRowID[19];		/* 记录索引 */
	struct DataTicketBStruct *pLoadNext;
};


/*单个文件结构申明*/
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
