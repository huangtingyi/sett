
#ifndef __PARAM_INTF_H__
#define __PARAM_INTF_H__

#include <hnixs.h>
#include <wwfile.h>
#include <list.h>
#include <gen_supp.h>

/*������Shm��MemTable*/
int MoveTableShmToList(char sTableName[31],struct FileControlStruct **pptHead);
int MoveShmToMem(int (*MInit)());

/*���ҺŶ�*/
int SearchT130AreaCode(char sAccNbr[13],char sStartTime[],
	struct T130AreaCodeStruct **ppCur);
int MInitT130AreaCode();

/**���ű����**/
int SearchAreaCodeDesc(char sAreaCode[],struct AreaCodeDescStruct **pptCur);
int MInitAreaCodeDesc();
int SearchCityCodeDesc(char sCityCode[],struct AreaCodeDescStruct **pptCur);
int MInitCityCodeDesc();
/*���ʵ�����Ӫ�̲���*/
int SearchTelecomCarrier(char sImsi[],char sMsc[],char sStartTime[],
	struct TelecomCarrierStruct **pptCur);
int MInitTelecomCarrier();

/*msc����*/
int SearchMsc(char sMsc[],struct MscStruct **pptCur);
int MInitMsc();

/*�������β���*/
int SearchAcrossCellCode(char sMsc[],char sLac[],char sCellID[],
	char sAreaCode[],char sStartTime[],struct AcrossCellCodeStruct **pptCur);
int MInitAcrossCellCode();

/*�м̱����*/
int SearchTrunk(char sMsc[],char sTrunk[],char sDirection[],
	char sStartTime[],struct TrunkStruct **pptCur);
int MInitTrunk();

/*��վ�����*/
int SearchCellCode(char sMsc[],char sLac[],char sCellID[],
	char sStartTime[],struct CellCodeStruct **pptCur);
int MInitCellCode();

/*�Ŷ���Ӫ�̱����*/
int SearchHeadCarr(char sHead[],char sAreaCode[],char sStartTime[],
	struct HeadCarrStruct **pptCur);
int MInitHeadCarr();

/**�������벿�ֱ�Ⱥ****/
int SearchTicketField(int iTicketFieldID,struct TicketFieldStruct **pptCur);
int MInitTicketField();

int SearchTicketFieldRule(int iID,char sUseType[],
	struct TicketFieldRuleStruct **pptCur);
int MInitTicketFieldRule();

int SearchTicketFieldValue(int iRuleID,struct TicketFieldValueStruct **pptCur);
int MInitTicketFieldValue();

int SearchSplitRule(int iTemplateRuleID,char sSplitType[],
	struct SplitRuleStruct **pptCur);
int GetTemplateSplitStr(char sTemplateRule[],char sSplitStr[]);
int MInitSplitRule();

/*�ʷ��Żݲ��ֱ�Ⱥ*/
int SearchTicketType(char sSplitType[],struct TicketTypeStruct **pptCur);
int MInitTicketType();
int SearchTicketTypeTariff(int iTicketTypeID,struct TicketTypeTariffStruct **pptCur);
int MInitTicketTypeTariff();
int SearchTicketBasedDisct(int iDisctRuleID,struct TicketBasedDisctStruct **pptCur);
int MInitTicketBasedDisct();
int SearchTimeSpanDisct(int iDisctRuleID,struct TimeSpanDisctStruct **pptCur);
int MInitTimeSpanDisct();
int SearchExprDisct(int iDisctRuleID,struct ExprDisctStruct **pptCur);
int MInitExprDisct();
int SearchDisctRuleMutex(int iDisctRuleID,struct DisctRuleMutexStruct **pptCur);
int MInitDisctRuleMutex();

int SearchDisctRule(int (*comp_fun)(LIST*),struct DisctRuleStruct **pptCur);
int SearchTollTariff(struct TollTariffStruct **pptCur);


void MoveAllShmToMem();
void DistroyAllMem();
/*�ؼ��ʷ��Żݲ���*/
#define MAXTARIFFID	100000
#define MAXDISCTRULEID	100000
#define MAXEXPRID	100000

#ifndef MAXACCTITEMTYPE
#define MAXACCTITEMTYPE	1000000
#endif

extern struct TollTariffStruct *apTollTariff[MAXTARIFFID];
extern struct DisctRuleStruct  *apDisctRule[MAXDISCTRULEID];
extern struct ExprDefStruct    *apExprDef[MAXEXPRID];
extern int  aiAcctItemTypeAnti[MAXACCTITEMTYPE];
extern char asAcctItemTypeKind[MAXACCTITEMTYPE];

#define PTOLLTARIFF(x)	(apTollTariff[x])
#define PDISCTRULE(x)	(apDisctRule[x])
#define PEXPRDEF(x)	(apExprDef[x])

int MInitTollTariff();
int MInitDisctRule();

int SearchExprDef(char sExprType[],struct ExprDefStruct **pptCur);
int MInitExprDef();
int MDestroyExprDef();

int SearchPickParam(int iGroupID,struct PickParamStruct **pptCur);
int MInitPickParam();
int MDestroyPickParam();

int SearchPrepParam(int iGroupID,struct PrepParamStruct **pptCur);
int MInitPrepParam();
int MDestroyPrepParam();

int SearchBillParam(char sAppCode[],int iGroupID,
	struct BillParamStruct **pptCur);
int MInitBillParam();
int MDestroyBillParam();

int SearchInstParam(int iGroupID,struct InstParamStruct **pptCur);
int MInitInstParam();
int MDestroyInstParam();

int SearchAcctParam(int iGroupID,struct AcctParamStruct **pptCur);
int MInitAcctParam();
int MDestroyAcctParam();

int SearchDispParam(int iGroupID,struct DispParamStruct **pptCur);
int MInitDispParam();
int MDestroyDispParam();

int SearchIntfParam(int iGroupID,struct IntfParamStruct **pptCur);
int MInitIntfParam();
int MDestroyIntfParam();

int SearchCommRange(char sTableName[],char sKey[],
	char sStartTime[],struct CommRangeStruct **pptCur);
int MInitCommRange();
int MDestroyCommRange();

int SearchSwitch(struct SwitchStruct **pptCur);
int MInitSwitch();
int MDestroySwitch();

int SearchCmdTemplate(int iSwitchTypeID,char sStandardCode[],
	struct CmdTemplateStruct **pptCur);
int MInitCmdTemplate();
int MDestroyCmdTemplate();

int SearchNbrHead(char sServiceType[],char sFieldType[],
	char sAccNbr[],struct NbrHeadStruct **pptCur);
int MInitNbrHead();
int MDestroyNbrHead();

int SearchAcctItemType(struct AcctItemTypeStruct **pptCur);
int MInitAcctItemType();
int MDestroyAcctItemType();

int SearchSettRule(int iTicketTypeID,char sTariffType[],char sStartTime[],
	struct SettRuleStruct **pptCur);
int MInitSettRule();
int MDestroySettRule();

int SearchSettCycle(char sModule[],int iSettCarrierID,
	struct SettCycleStruct **pptCur);
int MInitSettCycle();
int MDestroySettCycle();

int SearchSettCycleID(int iSettCycleID,struct SettCycleStruct **pptCur);
int MInitSettCycleID();
int MDestroySettCycleID();

int SearchLatn(int iLatnID,struct LatnStruct **pptCur);
int MInitLatn();
int MDestroyLatn();

int SearchPutParam(int iGroupID,struct PutParamStruct **pptCur);
int MInitPutParam();
int MDestroyPutParam();

int comp_insert_list_toll_tariff_e(LIST *pValue,LIST*pHead);
int SearchTollTariffRef(char sTariffRef[],struct TollTariffStruct **pptCur);
int MInitTollTariffRef();
int MDestroyTollTariffRef();

int SearchCommParam(int iGroupID,struct CommParamStruct **pptCur);
int MInitCommParam();
int MDestroyCommParam();

int SearchSettArea(int iAreaID,struct SettAreaStruct **pptCur);
int MInitSettArea();
int MDestroySettArea();
int GetPcbKey();

int data_search_bintree_pick_task_param_e(void *pValue,void*pData);
int SearchPickTaskParam(char sSourceID[],int iGroupID,
	struct PickTaskParamStruct **pptCur);
int MInitPickTaskParam();
int MDestroyPickTaskParam();

int data_search_bintree_prep_task_param_e(void *pValue,void*pData);
int SearchPrepTaskParam(char sSourceID[],int iGroupID,
	struct PrepTaskParamStruct **pptCur);
int MInitPrepTaskParam();
int MDestroyPrepTaskParam();

int data_search_bintree_bill_task_param_e(void *pValue,void*pData);
int SearchBillTaskParam(char sSourceID[],char sAppCode[],int iGroupID,
	struct BillTaskParamStruct **pptCur);
int MInitBillTaskParam();
int MDestroyBillTaskParam();

int data_search_bintree_acct_task_param_e(void *pValue,void*pData);
int SearchAcctTaskParam(char sSourceID[],int iGroupID,
	struct AcctTaskParamStruct **pptCur);
int MInitAcctTaskParam();
int MDestroyAcctTaskParam();

int data_search_bintree_inst_task_param_e(void *pValue,void*pData);
int SearchInstTaskParam(char sSourceID[],int iGroupID,
	struct InstTaskParamStruct **pptCur);
int MInitInstTaskParam();
int MDestroyInstTaskParam();

int data_search_bintree_flow_tache_e(void *pValue,void*pData);
int SearchFlowTache(int iTaskID,int iFlowID,
	struct FlowTacheStruct **pptCur);
int MInitFlowTache();
int MDestroyFlowTache();

int data_search_bintree_flow_task_e(void *pValue,void*pData);
int SearchFlowTask(int iParamID,struct FlowTaskStruct **pptCur);
int MInitFlowTask();
int MDestroyFlowTask();

int data_search_bintree_task_param_e(void *pValue,void*pData);
int SearchTaskParam(int iParamID,struct TaskParamStruct **pptCur);
int MInitTaskParam();
int MDestroyTaskParam();

int data_search_bintree_source_desc_e(void *pValue,void*pData);
int SearchSourceDesc(int iFlowID,struct SourceDescStruct **pptCur);
int MInitSourceDesc();
int MDestroySourceDesc();

int data_search_bintree_put_task_param_e(void *pValue,void*pData);
int SearchPutTaskParam(char sSourceID[],int iGroupID,
        struct PutTaskParamStruct **pptCur);
int MInitPutTaskParam();
int MDestroyPutTaskParam();

int data_search_bintree_recycle_task_param_e(void *pValue,void*pData);
int SearchRcylTaskParam(char sSourceID[],int iTaskSeqNbr,
	struct RcylTaskParamStruct **pptCur);
int MInitRcylTaskParam();
int MDestroyRcylTaskParam();

int data_search_bintree_intf_task_param_e(void *pValue,void*pData);
int SearchIntfTaskParam(char sSourceID[],int iGroupID,
        struct IntfTaskParamStruct **pptCur);
int MInitIntfTaskParam();
int MDestroyIntfTaskParam();

int data_search_bintree_roll_task_param_e(void *pValue,void*pData);
int SearchRollTaskParam(char sSourceID[],int iTaskSeqNbr,
        struct RollTaskParamStruct **pptCur);
int MInitRollTaskParam();
int MDestroyRollTaskParam();

int SearchRcylParam(char sSourceID[],int iTaskSeqNbr,struct RcylParamStruct **pptCur);
int MInitRcylParam();
int MDestroyRcylParam();

int SearchRollParam(char sSourceID[],int iTaskSeqNbr,struct RollParamStruct **pptCur);
int MInitRollParam();
int MDestroyRollParam();


#define NEW_FIELD_USE '1'
#define STATE_IS_USED(s)	(strcmp(s,"A0H")!=0)
#define STATE_IS_HIS(s)		(strcmp(s,"A0H")==0)
#define MY_MATCH_ARCH(s,p,pp) \
	if(strcmp((s),(p)->sEffDate)>=0&& \
		strcmp((s),(p)->sExpDate)<0){ \
		if(APPHOSTTIME[0]==0){ \
	/*����ǲ�������ʷʱ�����������õ�ֱ��ƥ��*/ \
			if(STATE_IS_USED((p)->sState)){ \
				*(pp)=(p); \
				return FOUND; \
			} \
	/*��ʷ����״̬��Чʱ���ڣ�����Ҫ����ʷ״̬��ֱ�Ӹ���*/ \
			if(strcmp((s),(p)->sStateDate)<0){ \
	/*����������������������ϴ����ԭ��������һ��ƥ���ϵ�ָ�룬 �����ƥ�䲻�����ƥ������*/ \
				if((*(pp))==NULL) *(pp)=(p); \
			} \
		} \
		else{ \
			if(STATE_IS_USED((p)->sState)){ \
				*(pp)=(p); \
	/*������ã��һָ���ʱ���ڽ���ʱ��֮���򷵻�*/ \
				if(strcmp(APPHOSTTIME,(p)->sCreatedDate)>=0) \
					return FOUND; \
	/*�������ʱ���ڽ���ʱ��֮����ֱ�ӷ���*/ \
				if(strcmp((s),(p)->sCreatedDate)>=0) \
					return FOUND; \
			} \
			else{ \
	/*���ģ����ʷ���������ģ��ʱ�������CD��SD֮�䣬��ƥ����*/ \
				if((strcmp(APPHOSTTIME,(p)->sCreatedDate)>=0&& \
					strcmp(APPHOSTTIME,(p)->sStateDate)<0)){ \
					*(pp)=(p); \
					return FOUND; \
				} \
	/*���ST��CD��SD֮�䣬�������ָ��������������ƥ�䲻�Ͼ������*/ \
				if(strcmp((s),(p)->sCreatedDate)>=0&& \
					strcmp((s),(p)->sStateDate)<0){ \
					if((*(pp))==NULL) *(pp)=(p); \
				} \
			} \
		} \
	}

#define MY_MAXS_LEN 12
#define MY_MAXM_LEN 40
#define MY_MAXL_LEN 80

/*��Щ�ṹ����֧�ֹ����ڴ��COMM_SEARCH�����㷨*/
struct SKeyValStruct{
	char	sKey[MY_MAXS_LEN+1];
	char	sVal[MY_MAXS_LEN+1];
};
struct MKeyValStruct{
	char	sKey[MY_MAXM_LEN+1];
	char	sVal[MY_MAXM_LEN+1];
};
struct LKeyValStruct{
	char	sKey[MY_MAXL_LEN+1];
	char	sVal[MY_MAXL_LEN+1];
};
struct ICommSearchStruct{
	POINTER ioffNext;		/* ָ��ƫ�� */
	int     iIntKey;		/* 0��ʶĬ��ֵ */
	int     iIntVal;		/* ����ֵ */
	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */
	char	sState[4];
	char	sStateDate[15];
	char	sCreatedDate[15];
	char    sTableName[31];		/* ���� */
	char	cType;			/* S С,M ��,L��*/
	char	sKey[MY_MAXL_LEN+1];	/*��ֵ*/
};

/*Ϊ����ӦHP���������ڴ�4�ֽڶ���ṹ��Ҫ���޸��˺�*/
#define _S_COMM_SEARCH_LEN (sizeof(struct ICommSearchStruct)-MY_MAXL_LEN-1+sizeof(struct SKeyValStruct))
#define _M_COMM_SEARCH_LEN (sizeof(struct ICommSearchStruct)-MY_MAXL_LEN-1+sizeof(struct MKeyValStruct))
#define _L_COMM_SEARCH_LEN (sizeof(struct ICommSearchStruct)-MY_MAXL_LEN-1+sizeof(struct LKeyValStruct))

#define S_COMM_SEARCH_LEN       ((_S_COMM_SEARCH_LEN+3)/4*4)
#define M_COMM_SEARCH_LEN       ((_M_COMM_SEARCH_LEN+3)/4*4)
#define L_COMM_SEARCH_LEN       ((_L_COMM_SEARCH_LEN+3)/4*4)

int data_search_bintree_comm_search_e(void *pValue,void*pData);

void GetStrValFromCS(struct ICommSearchStruct *pi,char sStrVal[]);
void GetStrValFromCSX(struct ICommSearchStruct *pi,int iMaxLen,char sStrVal[]);

int SearchCommBin(char sTableName[],int iIntKey,char sStrKey[],
	char sStartTime[],struct ICommSearchStruct **pptCur);
int SearchCommTrie(char sTableName[],int iIntKey,char sStrKey[],
	char sStartTime[],struct ICommSearchStruct **pptCur);

void CheckPcbShmValid();

extern void *PSHM;
extern int SHM_PCB_KEY,SEM_PCB_ID;

#endif
