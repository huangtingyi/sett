
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <trie.h>

#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <expr_supp.h>

#include "wwsupp.h"
#include "gen_supp.h"
#include "param_intf.h"
#include "ticket_field.h"
#include "tariff_disct.h"

struct CompileResultStruct
{
	struct CompileResultStruct *pNext;
	char sExprName[256];
	struct ExprBufStruct *pBuf;
};

struct RatePositionStruct RatePos;
struct RateTicketStruct RateTicket;

static struct TicketFieldRegStruct *pRegTicketField=NULL;


struct MobTicketStruct	*pTicketField;
struct TicketAnalyzeStruct TicketAnalyze;
void	*pTicketFieldCurValue=NULL;
struct TicketFieldRuleStruct *apSplitRule[MAXSPLITRULEID];
struct	FileControlListStruct *pFileControlList=NULL;
char SUFFIX_STR[21];/*��ʽ�Ľӿڱ���*/

void RegTotalFun();

struct FErrInfoStruct
{
	char    sErrCode[4];
	char    sFileName[19];
	char    sModule[3];
	char    sAreaCode[5];
};

void InitArraySplitRule(struct TicketFieldRuleStruct *ptHead)
{
	if(ptHead!=NULL){
		ERROR_EXIT((ptHead->iID<0||ptHead->iID>=MAXSPLITRULEID),
			 "���س�ʼ������--��ֵ�Ƿ�");
		PSPLITRULE(ptHead->iID)=ptHead;
	}	
	while(ptHead!=NULL){
		
		ERROR_EXIT((ptHead->iID<0||ptHead->iID>=MAXSPLITRULEID),
			 "���س�ʼ������--��ֵ�Ƿ�");		
		ERROR_EXIT(InitialTicketFieldRule(ptHead)<0,"���س�ʼ������");
		ptHead=ptHead->pNext;
	}
}

static void *GetTicketField_TICKET_TYPE_ID()
{
	return (void*)&(pTicketField->iTicketTypeID);
}
static void *GetTicketField_CALL_TYPE()
{
	return (void*)(pTicketField->sCallType);
}
static void *GetTicketField_MSISDN_LEN()
{
	return (void*)&(pTicketField->iMsisdnLen);
}
static void *GetTicketField_MSISDN()
{
	return (void*)(pTicketField->sMsisdn);
}

static void *GetTicketField_OTHER_PARTY_LEN()
{

	return (void*)&(pTicketField->iOtherPartyLen);
}
static void *GetTicketField_OTHER_PARTY()
{
	return (void*)(pTicketField->sOtherParty);
}
static void *GetTicketField_RAW_OTHER_PARTY()
{
	return (void*)(pTicketField->sRawOtherParty);
}
static void *GetTicketField_DURATION()
{
	return (void* )&(pTicketField->iDuration);
}
static void *GetTicketField_OPP_TYPE()
{
	return (void*)(pTicketField->sOppType);
}
static void *GetTicketField_ROAM_TYPE()
{
	return (void*)(pTicketField->sRoamType);
}
static void *GetTicketField_DISTANCE_TYPE()
{
	return (void*)(pTicketField->sDistanceType);
}
static void *GetTicketField_OPP_ROAM_TYPE()
{
	return (void*)(pTicketField->sOppRoamType);
}
static void *GetTicketField_USER_TYPE()
{
	return (void*)(pTicketField->sUserType);
}
static void *GetTicketField_IP_TYPE()
{
	return (void*)(pTicketField->sIpType);
}
static void *GetTicketField_TOLL_TYPE1()
{
	return (void*)(pTicketField->sTollType1);
}
static void *GetTicketField_TOLL_TYPE2()
{
	return (void*)(pTicketField->sTollType2);
}
static void *GetTicketField_HOME_TOLL_TYPE2()
{
	return (void*)(pTicketField->sHomeTollType2);
}
static void *GetTicketField_CALLED_CODE()
{
	return (void*)(pTicketField->sCalledCode);
}
static void *GetTicketField_VISIT_AREA_CODE()
{
	return (void*)(pTicketField->sVisitAreaCode);
}
static void *GetTicketField_HOME_AREA_CODE()
{
	return (void*)(pTicketField->sHomeAreaCode);
}
static void *GetTicketField_MSC()
{
	return (void*)(pTicketField->sMsc);
}
static void *GetTicketField_LAC()
{
	return (void*)(pTicketField->sLac);
}
static void *GetTicketField_CELL_ID()
{
	return (void*)(pTicketField->sCellID);
}
static void *GetTicketField_OTHER_LAC()
{
	return (void*)(pTicketField->sOtherLac);
}
static void *GetTicketField_OTHER_CELL_ID()
{
	return (void*)(pTicketField->sOtherCellID);
}
static void *GetTicketField_TRUNK_IN()  
{
	return (void*)(pTicketField->sTrunkIn);
}
static void *GetTicketField_TRUNK_OUT() 
{
	return (void*)(pTicketField->sTrunkOut);
}
static void *GetTicketField_SERVICE_TYPE()
{
	return (void*)(pTicketField->sServiceType);
}
static void *GetTicketField_SERVICE_CODE()
{
	return (void*)(pTicketField->sServiceCode);
}
static void *GetTicketField_CAL()
{
	return (void*)(pTicketField->sCal);
}
static void *GetTicketField_CALLING_CARRIER()
{
	return (void*)&(TicketAnalyze.iCallingCarrierID);
}
static void *GetTicketField_CALLED_CARRIER()
{
	return (void*)&(TicketAnalyze.iCalledCarrierID);
}
static void *GetTicketField_CALLING_TYPE()
{
	return (void*)&(TicketAnalyze.iCallingTypeID);
}
static void *GetTicketField_CALLED_TYPE()
{
	return (void*)&(TicketAnalyze.iCalledTypeID);
}
static void *GetTicketField_CALLING_AREA_ID()
{
	return (void*)&(TicketAnalyze.iCallingAreaID);
}
static void *GetTicketField_CALLED_AREA_ID()
{
	return (void*)&(TicketAnalyze.iCalledAreaID);
}
static void *GetTicketField_TRUNK_IN_TYPE()
{
	return (void*)&(TicketAnalyze.iTrunkInTypeID);
}
static void *GetTicketField_TRUNK_IN_CARRIER()
{
	return (void*)&(TicketAnalyze.iTrunkInCarrierID);
}
static void *GetTicketField_TRUNK_OUT_TYPE()
{
	return (void*)&(TicketAnalyze.iTrunkOutTypeID);
}
static void *GetTicketField_TRUNK_OUT_CARRIER()
{
	return (void*)&(TicketAnalyze.iTrunkOutCarrierID);
}

static void *GetTicketField_TRUNK_IN_OPP_TYPE()
{
	return (void*)&(TicketAnalyze.sTrunkInOppType);
}
static void *GetTicketField_TRUNK_OUT_OPP_TYPE()
{
	return (void*)&(TicketAnalyze.sTrunkOutOppType);
}
static void *GetTicketField_TRUNK_IN_OPP_AREA_CODE()
{
	return (void*)&(TicketAnalyze.sTrunkInOppAreaCode);
}
static void *GetTicketField_TRUNK_OUT_OPP_AREA_CODE()
{
	return (void*)&(TicketAnalyze.sTrunkOutOppAreaCode);
}
static void *GetTicketField_CALLING_COUNTY_FLAG()
{
	return (void*)&(TicketAnalyze.sCallingCountyFlag);
}
static void *GetTicketField_CALLED_COUNTY_FLAG()
{
	return (void*)&(TicketAnalyze.sCalledCountyFlag);
}
static void *GetTicketField_SAME_AREA_FLAG()
{
	return (void*)&(TicketAnalyze.sSameAreaFlag);
}
static void *GetTicketField_NEW_FIELD()
{
	return (void*)pTicketFieldCurValue;
}

static void RegDetailFun(char sGetValueFun[],void *(*GetTicketField)())
{
	struct TicketFieldRegStruct *pTemp;
	
	pTemp=(struct TicketFieldRegStruct*)
		malloc(sizeof(struct TicketFieldRegStruct));
		
	ERROR_EXIT(pTemp==NULL,"�����ڴ����");

	pTemp->pNext=NULL;
	strcpy(pTemp->sGetValueFun,sGetValueFun);
	pTemp->GetTicketField=GetTicketField;
	
	InsertList((LIST**)&pRegTicketField,(LIST*)pTemp);	
	
}
static struct TicketFieldRegStruct *GetTicketFieldReg(char sGetValueFun[])
{
	static int iFirstFlag=TRUE;
	struct TicketFieldRegStruct *ptHead;
	
	if(iFirstFlag==TRUE){/*ע�ắ��*/
		iFirstFlag=FALSE;
		RegTotalFun();
	}
	ptHead=pRegTicketField;
	while(ptHead!=NULL){
		if(strcmp(sGetValueFun,ptHead->sGetValueFun)==0){
			return ptHead;
		}			
		
		ptHead=ptHead->pNext;
	}
	return NULL;
}

void RegTotalFun()
{
	struct TicketFieldRegStruct *pTemp,*ptHead;
	
		/*������ǵ�һ�����ͷ�ԭ�ȵ�*/
	ptHead=pRegTicketField;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		free(pTemp);
	}
	pRegTicketField=NULL;
	
RegDetailFun("GetTicketField_TICKET_TYPE_ID",	GetTicketField_TICKET_TYPE_ID);
RegDetailFun("GetTicketField_CALL_TYPE",	GetTicketField_CALL_TYPE);
RegDetailFun("GetTicketField_CAL",		GetTicketField_CAL);
RegDetailFun("GetTicketField_MSISDN_LEN",	GetTicketField_MSISDN_LEN);
RegDetailFun("GetTicketField_MSISDN",		GetTicketField_MSISDN);
RegDetailFun("GetTicketField_OTHER_PARTY_LEN",	GetTicketField_OTHER_PARTY_LEN);
RegDetailFun("GetTicketField_OTHER_PARTY",	GetTicketField_OTHER_PARTY);
RegDetailFun("GetTicketField_RAW_OTHER_PARTY",	GetTicketField_RAW_OTHER_PARTY);
RegDetailFun("GetTicketField_DURATION",		GetTicketField_DURATION);
RegDetailFun("GetTicketField_OPP_TYPE",		GetTicketField_OPP_TYPE);
RegDetailFun("GetTicketField_ROAM_TYPE",	GetTicketField_ROAM_TYPE);
RegDetailFun("GetTicketField_DISTANCE_TYPE",	GetTicketField_DISTANCE_TYPE);
RegDetailFun("GetTicketField_OPP_ROAM_TYPE",	GetTicketField_OPP_ROAM_TYPE);
RegDetailFun("GetTicketField_USER_TYPE",	GetTicketField_USER_TYPE);

RegDetailFun("GetTicketField_IP_TYPE",		GetTicketField_IP_TYPE);
RegDetailFun("GetTicketField_TOLL_TYPE1",	GetTicketField_TOLL_TYPE1);
RegDetailFun("GetTicketField_TOLL_TYPE2",	GetTicketField_TOLL_TYPE2);

RegDetailFun("GetTicketField_VISIT_AREA_CODE",	GetTicketField_VISIT_AREA_CODE);
RegDetailFun("GetTicketField_HOME_AREA_CODE",	GetTicketField_HOME_AREA_CODE);
RegDetailFun("GetTicketField_MSC",		GetTicketField_MSC);

RegDetailFun("GetTicketField_LAC",		GetTicketField_LAC);
RegDetailFun("GetTicketField_CELL_ID",		GetTicketField_CELL_ID);
RegDetailFun("GetTicketField_OTHER_LAC",	GetTicketField_OTHER_LAC);
RegDetailFun("GetTicketField_OTHER_CELL_ID",	GetTicketField_OTHER_CELL_ID);

RegDetailFun("GetTicketField_TRUNK_IN",		GetTicketField_TRUNK_IN);  
RegDetailFun("GetTicketField_TRUNK_OUT",	GetTicketField_TRUNK_OUT);  
RegDetailFun("GetTicketField_SERVICE_TYPE",	GetTicketField_SERVICE_TYPE);
RegDetailFun("GetTicketField_SERVICE_CODE",	GetTicketField_SERVICE_CODE);
RegDetailFun("GetTicketField_CALLED_CODE",	GetTicketField_CALLED_CODE);

RegDetailFun("GetTicketField_CALLING_CARRIER",	GetTicketField_CALLING_CARRIER);
RegDetailFun("GetTicketField_CALLED_CARRIER",	GetTicketField_CALLED_CARRIER);
RegDetailFun("GetTicketField_CALLING_TYPE",	GetTicketField_CALLING_TYPE);
RegDetailFun("GetTicketField_CALLED_TYPE",	GetTicketField_CALLED_TYPE);

RegDetailFun("GetTicketField_CALLING_AREA_ID",	GetTicketField_CALLING_AREA_ID);
RegDetailFun("GetTicketField_CALLED_AREA_ID",	GetTicketField_CALLED_AREA_ID);

RegDetailFun("GetTicketField_TRUNK_IN_TYPE",	GetTicketField_TRUNK_IN_TYPE);
RegDetailFun("GetTicketField_TRUNK_IN_CARRIER",GetTicketField_TRUNK_IN_CARRIER);
RegDetailFun("GetTicketField_TRUNK_OUT_TYPE",	GetTicketField_TRUNK_OUT_TYPE);
RegDetailFun("GetTicketField_TRUNK_OUT_CARRIER",GetTicketField_TRUNK_OUT_CARRIER);

RegDetailFun("GetTicketField_TRUNK_IN_OPP_TYPE",GetTicketField_TRUNK_IN_OPP_TYPE);
RegDetailFun("GetTicketField_TRUNK_OUT_OPP_TYPE",GetTicketField_TRUNK_OUT_OPP_TYPE);

RegDetailFun("GetTicketField_TRUNK_IN_OPP_AREA_CODE",GetTicketField_TRUNK_IN_OPP_AREA_CODE);
RegDetailFun("GetTicketField_TRUNK_OUT_OPP_AREA_CODE",GetTicketField_TRUNK_OUT_OPP_AREA_CODE);

RegDetailFun("GetTicketField_CALLING_COUNTY_FLAG",GetTicketField_CALLING_COUNTY_FLAG);
RegDetailFun("GetTicketField_CALLED_COUNTY_FLAG",GetTicketField_CALLED_COUNTY_FLAG);
RegDetailFun("GetTicketField_SAME_AREA_FLAG",GetTicketField_SAME_AREA_FLAG);

RegDetailFun("GetTicketField_HOME_TOLL_TYPE2",	GetTicketField_HOME_TOLL_TYPE2);

}

TRIE *CreateTrieTicketFieldValue(struct TicketFieldValueStruct *pHead)
{
	TRIE *ptHead=NULL;
	struct TicketFieldValueStruct *pTemp;
	
	while(pHead!=NULL){
		pTemp=pHead;
		pHead=pHead->pNext;
		
		if(InsertTrie(&ptHead,pTemp->sValue,(void*)pTemp,
			assign_insert_trie)<0){
			WriteAlertMsg("malloc fail TicketFieldValueStruct");
			return NULL;
		}
	}	
	return ptHead;
}
/*******************************************************
һ����Χ������ƥ��(iValue between)
����ɸѡ�����ֵ(iEndPoint)����Сֵ(iStartPoint)
���ֻ��һ��ֵ����(iStartPoint)��ֻ��(iValue>=iStartPoint)��Ч
���(iStartPoint,iEndPoint)�����ڣ�
��(iEndPoint>=iValue>=iStartPoint)�������Ч
*******************************************************/
int SearchListTicketFieldValueINTEGER_RANG(void *pHead,void *pValue)
{
	int iValue=*((int *)pValue),iStartPoint,iEndPoint,iPos=0;

	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;

	if(pHead==NULL)	return FOUND;

	iStartPoint = iEndPoint = ptHead->iValue;

	while(ptHead!=NULL){

		iPos++;
		if(ptHead->iValue<iStartPoint) iStartPoint=ptHead->iValue;
		if(ptHead->iValue>iEndPoint) iEndPoint=ptHead->iValue;

		ptHead = ptHead->pNext;
	}

	if(iValue<iStartPoint) return NOTFOUND;

	if(iPos>1 && iValue>iEndPoint)	return NOTFOUND;

	return FOUND;
}
int SearchListTicketFieldValueINTEGER(void *pHead,void *pValue)
{
	int iValue=*((int *)pValue);
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;
		
	do{
		if(iValue==ptHead->iValue) return FOUND;
		ptHead=ptHead->pNext;
	}while(ptHead!=NULL);
	
	return NOTFOUND;
}
int SearchListTicketFieldValueINTEGERNOT(void *pHead,void *pValue)
{
	int iValue=*((int *)pValue);
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;
		
	do{
		if(iValue==ptHead->iValue) return NOTFOUND;
		ptHead=ptHead->pNext;
	}while(ptHead!=NULL);
	
	return FOUND;
}

int SearchListTicketFieldValueSTRINGFULL(void *pHead,void *pValue)
{
	char *sValue=(char*)pValue;
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;
		
	do{
		if(strcmp(sValue,ptHead->sValue)==0) return FOUND;
		ptHead=ptHead->pNext;
	
	}while(ptHead!=NULL);
	
	return NOTFOUND;
}
int SearchListTicketFieldValueSTRINGMAX(void *pHead,void *pValue)
{
	char *sValue=(char*)pValue;
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;
		
	do{
	
		if(strncmp(sValue,ptHead->sValue,ptHead->iValueLen)==0)
			return FOUND;
		
		ptHead=ptHead->pNext;
	
	}while(ptHead!=NULL);
	
	return NOTFOUND;
}

int SearchListTicketFieldValueSTRINGFULLNOT(void *pHead,void *pValue)
{
	char *sValue=(char*)pValue;
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;
		
	do{
			/*sValue not equal sth*/
		if(strcmp(sValue,ptHead->sValue)==0) return NOTFOUND;
		ptHead=ptHead->pNext;
	
	}while(ptHead!=NULL);
	
	return FOUND;
}
int SearchListTicketFieldValueSTRING_R_NOTLIKE(void *pHead,void *pValue)
{
	int len;
	char *sValue=(char*)pValue;
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;

	len=strlen(sValue);

	do{
			/*sValue not equal sth*/
		if(strcmp(sValue+len-ptHead->iValueLen,ptHead->sValue)==0)
			 return NOTFOUND;
		ptHead=ptHead->pNext;
	
	}while(ptHead!=NULL);
	
	return FOUND;
}
int SearchListTicketFieldValueSTRING_R_LIKE(void *pHead,void *pValue)
{
	int len;
	char *sValue=(char*)pValue;
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;
		
	len=strlen(sValue);

	do{
			/*sValue not equal sth*/
		if(strcmp(sValue+len-ptHead->iValueLen,ptHead->sValue)==0)
			 return FOUND;
		ptHead=ptHead->pNext;
	
	}while(ptHead!=NULL);
	
	return NOTFOUND;
}
int SearchListTicketFieldValueSTRINGMAXNOT(void *pHead,void *pValue)
{
	char *sValue=(char*)pValue;
	struct TicketFieldValueStruct *ptHead=(struct TicketFieldValueStruct *)pHead;
	
	if(pHead==NULL)	return FOUND;
		
	do{
			/*sValue not like sth*/
		if(strncmp(sValue,ptHead->sValue,ptHead->iValueLen)==0)
			return NOTFOUND;
		
		ptHead=ptHead->pNext;
	
	}while(ptHead!=NULL);
	
	return FOUND;
}

/*��ȫƥ���ַ�����*/
int SearchTrieTicketFieldValueFULL(void *pHead,void *pValue)
{
	struct	TicketFieldValueStruct *ptCur;
	
	char	*sValue=(char*)pValue;
	
	if(pHead==NULL)	return FOUND;
	

	if(SearchTrie((TRIE*)pHead,sValue,(void**)&ptCur)==NOTFOUND)
		return NOTFOUND;
		
	while(ptCur!=NULL){
		/*��ȫƥ���ַ�����*/
		if(strcmp(sValue,ptCur->sValue)==0)
			return FOUND;
		ptCur=ptCur->pNext;
	}
	return NOTFOUND;
}
/*���ƥ���ַ�����*/
int SearchTrieTicketFieldValueMAX(void *pHead,void *pValue)
{
	struct	TicketFieldValueStruct *ptCur;
	
	char	*sValue=(char*)pValue;
	
	if(pHead==NULL)	return FOUND;
	
	if(SearchTrie((TRIE*)pHead,sValue,(void**)&ptCur)==NOTFOUND)
		return NOTFOUND;
		
	while(ptCur!=NULL){
		/*���ƥ���ַ�����*/
		if(strncmp(sValue,ptCur->sValue,ptCur->iValueLen)==0)
			return FOUND;
		ptCur=ptCur->pNext;
	}
	return NOTFOUND;
}
int InitialTicketFieldRule(struct TicketFieldRuleStruct *pTemp)
{
	struct TicketFieldRegStruct *pRegTemp;
	struct TicketFieldStruct *pFieldTemp=NULL;
	struct TicketFieldValueStruct *pValueTemp=NULL;


	if(SearchTicketField(pTemp->iFieldID,&pFieldTemp)==NOTFOUND){
		WriteAlertMsg("�Ƿ�ƥ��TICKET_FIELD_RULE.FIELDID=%d δ����,ϵͳ����",
				pTemp->iFieldID);
		return -1;
	}
	pTemp->pTicketField=pFieldTemp;
	
	if(pFieldTemp->sUseType[0]!=NEW_FIELD_USE){
		if((pRegTemp=GetTicketFieldReg(pFieldTemp->sGetValueFun))==NULL){
			WriteAlertMsg("�Ƿ�ƥ�����TICKET_FIELD_RULE.RULE_ID=%d,δע�� ϵͳ����",
				pTemp->iRuleID);
			return -1;
		}
		pTemp->GetTicketField=pRegTemp->GetTicketField;
	}
	else/*���÷�*/
		pTemp->GetTicketField=GetTicketField_NEW_FIELD;


	if(SearchTicketFieldValue(pTemp->iRuleID,&pValueTemp)==NOTFOUND){
		WriteAlertMsg("�Ƿ�ƥ�����TICKET_FIELD_RULE.RULE_ID=%d,��ֵ ϵͳ����",
			pTemp->iRuleID);
		return -1;
	}

	switch (pTemp->sMethod[0]){
			
	case 'N':	/*��չ��ʽ�ַ������ƥ��*/
		pTemp->pData=(void*)CreateTrieTicketFieldValue(pValueTemp);
		pTemp->SearchRule=SearchTrieTicketFieldValueMAX;
	break;
	case 'D':	/*��չ��ʽ�ַ�����ȫƥ��*/
		pTemp->pData=(void*)CreateTrieTicketFieldValue(pValueTemp);
		pTemp->SearchRule=SearchTrieTicketFieldValueFULL;
	break;		
	case 'M':	/*�ַ������ƥ��*/
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueSTRINGMAX;
	break;
	case 'C':	/*�ַ�����ȫƥ��*/
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueSTRINGFULL;
	break;
	case 'L':	/*�ַ������ƥ��*/
		pTemp->pData=(void*)pValueTemp;
		pTemp->SearchRule=SearchListTicketFieldValueSTRINGMAXNOT;
	break;
	case 'B':	/*�ַ�����ȫƥ��*/
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueSTRINGFULLNOT;
	break;
	case 'I':
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueINTEGER;
	break;
	case 'O':
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueINTEGERNOT;
	break;
	case 'R':	/*��һ����Χ�ڵ�����ƥ��*/
		pTemp->pData=(void*)pValueTemp;
		pTemp->SearchRule=SearchListTicketFieldValueINTEGER_RANG;
	break;
	case 'J':
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueSTRING_R_LIKE;
	break;
	case 'K':
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueSTRING_R_NOTLIKE;
	break;
	default:/*Ĭ��Ϊ�ַ�����ȫƥ��*/
		pTemp->sMethod[0]='C';
		pTemp->pData=(void*)pValueTemp;			
		pTemp->SearchRule=SearchListTicketFieldValueSTRINGFULL;
	}
	return 0;	
}

/*����ӿڲ���*/

void InitialSplitRuleChildList(struct SplitRuleStruct *ptHead)
{
	struct SplitRuleStruct *pTemp=ptHead;
	struct TicketFieldRuleStruct *pTicketFieldRuleTemp=NULL;
	
	while(pTemp!=NULL){

		if(pTemp->pChild!=NULL)
			InitialSplitRuleChildList(pTemp->pChild);
	
		if(SearchTicketFieldRule(pTemp->iSplitRuleID,"S",
			&pTicketFieldRuleTemp)==NOTFOUND){
			pTemp=pTemp->pNext;
			continue;
		}
		InitArraySplitRule(pTicketFieldRuleTemp);
		
		pTemp=pTemp->pNext;
	}
}
/**��ȡָ���ķ�������б�����ʼ��������*/
struct SplitRuleStruct *GetSplitRuleList(int iTemplateRuleID,char sSplitType[])
{
	struct SplitRuleStruct *ptHead=NULL;
	
	if(SearchSplitRule(iTemplateRuleID,sSplitType,&ptHead)==NOTFOUND)
		return NULL;
	
	InitialSplitRuleChildList(ptHead);
	
	return ptHead;
}
/*�鿴����������Ƿ�ƥ��*/
int MatchTicketFieldRule(struct TicketFieldRuleStruct*ptHead)
{
	
	if(ptHead==NULL)	return FOUND;
	
	do{	/*ÿ���ֶ�ƥ���Ĺ�ϵΪ�ҵĹ�ϵ,ֻҪһ����ƥ�����Ҳ���*/
		pTicketFieldCurValue=ptHead->pTicketField->pValue;
		if(ptHead->SearchRule(ptHead->pData,ptHead->GetTicketField())
			==NOTFOUND) return NOTFOUND;
		ptHead=ptHead->pNext;
		
	}while(ptHead!=NULL);
	
	return FOUND;
}
/*����ָ������ƥ���������������*/
struct SplitRuleStruct *GetSplitRule(struct SplitRuleStruct *pTemp)
{
	struct SplitRuleStruct *pTmp;
	
	while(pTemp!=NULL){
	
		/*pNext�����Ѿ��������ȼ�������*/
		if(MatchTicketFieldRule(PSPLITRULE(pTemp->iSplitRuleID))
			==FOUND){
			
			if(pTemp->pChild==NULL)	return pTemp;
			if((pTmp=GetSplitRule(pTemp->pChild))!=NULL)
				return pTmp;
			if(PSPLITRULE(pTemp->iSplitRuleID)!=NULL&&
				pTemp->iTicketTypeID>=0)
				return pTemp;
		}
		pTemp=pTemp->pNext;
	}
	return NULL;
}
/*********�ʷ�֧�ֲ���*************/
void GetOppVisitAreaCode(char sMsrn[],char sCalledCode[],
	char sStartTime[],char sOppVisitAreaCode[])
{
	struct T130AreaCodeStruct *pT130;
	
	if(SearchT130AreaCode(sMsrn,sStartTime,&pT130)==FOUND)
		strcpy(sOppVisitAreaCode,pT130->sAreaCode);
	else
		strcpy(sOppVisitAreaCode,sCalledCode);
}
/*���ͬ�Ǽ��߽����α�ʶ*/
void GetTicketCal(struct MobTicketStruct *p)
{
	struct AcrossCellCodeStruct *pNoUse=NULL;
	
/*���ǼƷѻ�����û��CAL*/
	if(strcmp(p->sCallType,"01")!=0&&
		 strcmp(p->sCallType,"02")!=0&&
		 strcmp(p->sCallType,"03")!=0){
	
		 strcpy(p->sCal,CAL_NORMAL);
		 return ;
	}
	if(SearchAcrossCellCode(p->sMsc,p->sLac,p->sCellID,
		p->sHomeAreaCode,p->sStartTime,&pNoUse)==FOUND){
	
		strcpy(p->sCal,CAL_ACROSS);
		strcpy(p->sVisitAreaCode,p->sHomeAreaCode);
		return ;
	}
/*
0.�����л������ж�ͬ��
1.�Զ˷��ƶ��绰Ҳ���ж�ͬ��;
2.�Զ˷�����Ҳ���ж�ͬ��*/
	if(strcmp(p->sCallType,"01")!=0||
		!IS_MOB_NBR(p->sOtherParty)||
		strcmp(p->sCalledCode,p->sOppVisitAreaCode)==0){
		
		 strcpy(p->sCal,CAL_NORMAL);
		 return ;
	}
/*
1.�����û������Σ��Զ��û����ε����еĹ���;
2.���ε�ͬһ���ط����Ұݷõ�һ����ͬ��;*/
	if(strcmp(p->sVisitAreaCode,p->sOppVisitAreaCode)==0)
		strcpy(p->sCal,CAL_SAME);
	else
		strcpy(p->sCal,CAL_NORMAL);
}
int GetTotalType(struct MobTicketStruct *p)
{
	char *sVisitAreaCode,*sHomeAreaCode,*sCalledCode,*sOppVisitAreaCode;

	char *sRoamType,*sOppType,*sDistanceType,*sOppRoamType;

	struct AreaCodeDescStruct *PV, *PH,*PC,*PO;

	sVisitAreaCode=		p->sVisitAreaCode;
	sHomeAreaCode=		p->sHomeAreaCode;
	sCalledCode=		p->sCalledCode;
	sOppVisitAreaCode=	p->sOppVisitAreaCode;

	sRoamType=		p->sRoamType;
	sOppType=		p->sOppType;
	sDistanceType=		p->sDistanceType;
	sOppRoamType=		p->sOppRoamType;


	if(SearchAreaCodeDesc(sHomeAreaCode,	&PH)==NOTFOUND)
		return INVALID_AREA_CODE;

	if(SearchAreaCodeDesc(sVisitAreaCode,	&PV)==NOTFOUND)
		return INVALID_AREA_CODE;

	if(SearchAreaCodeDesc(sCalledCode,	&PC)==NOTFOUND)
		return INVALID_AREA_CODE;

	if(SearchAreaCodeDesc(sOppVisitAreaCode,&PO)==NOTFOUND)
		return INVALID_AREA_CODE;

	switch (PH->sType[0]){

	case DISTANCE_LOCAL_PROVINCE:/*ʡ���û�*/

	/*�û��������Զ˹����Ĺ�ϵ*/
		sOppType[0]=	PC->sType[0];
		if(strcmp(sHomeAreaCode,sCalledCode)==0)/*���غ���*/
			sOppType[0]=DISTANCE_LOCAL_CITY;/*�Զ�Ϊ����*/

	/*�û��������Զ˰ݷõĹ�ϵ*/
		sOppRoamType[0]= PO->sType[0];
		if(strcmp(sHomeAreaCode,sOppVisitAreaCode)==0)
			sOppRoamType[0]=DISTANCE_LOCAL_CITY;/*�Զ�Ϊ����*/

		switch (PV->sType[0]){

		case DISTANCE_LOCAL_PROVINCE:/*ʡ��*/

			if(strcmp(sHomeAreaCode,sVisitAreaCode)==0)/*����,������*/
				sRoamType[0]=	ROAM_LOCAL_CITY;
			else/*ʡ�������û�*/
				sRoamType[0]=ROAM_LOCAL_PROVINCE;

			sDistanceType[0]= PC->sType[0];

			/* ����ݷõأ��Զ˹����أ����۶Զ��Ƿ����Σ�����Ϊ�Ǳ���ͨ�� */
			if(strcmp(sVisitAreaCode,sCalledCode)==0)
				sDistanceType[0]=DISTANCE_LOCAL_CITY;

		break;

		case DISTANCE_PROVINCE: /*ʡ�ʳ���*/

			sRoamType[0]=ROAM_VISITING_PROVINCE;

	/*��ȡʡ�ʳ����û��� �û��ݷõ��Զ˹����Ĺ�ϵ*/
			sDistanceType[0]= PC->sType[0];
			if(sCalledCode[0]!= '0'){	/*�ǹ��ʸ۰�̨���ֵ���*/
				if(strcmp(PV->sCapitalAreaCode,PC->sCapitalAreaCode)==0){
					if(strcmp(sVisitAreaCode,sCalledCode)==0)
						sDistanceType[0]=DISTANCE_LOCAL_CITY;
					else
						sDistanceType[0]=DISTANCE_LOCAL_PROVINCE;
				}
				else
					sDistanceType[0]=DISTANCE_PROVINCE;
			}
		break;
		case DISTANCE_GAT:	/*�۰�̨����*/
			sRoamType[0]=ROAM_VISITING_GAT;

			if(strcmp(sVisitAreaCode,sCalledCode)==0)
				sDistanceType[0]=DISTANCE_LOCAL_CITY;
			else if(sOppType[0]!=DISTANCE_INTER)
				sDistanceType[0]=DISTANCE_GAT;
			else
				sDistanceType[0]=DISTANCE_INTER;
		break;
		case DISTANCE_INTER:	/*���ʳ���*/
			sRoamType[0]=ROAM_VISITING_INTER;

			sDistanceType[0]=DISTANCE_INTER;

		break;
		default:return INVALID_TYPE;
		}

	break;
	case DISTANCE_PROVINCE: /*ʡ���û�,ʡ������*/

		sRoamType[0]=ROAM_VISITED_PROVINCE;
		sOppType[0]=PC->sType[0];
		sOppRoamType[0]=PO->sType[0];

		sDistanceType[0]=PC->sType[0];
		if(strcmp(sVisitAreaCode,sCalledCode)==0)
			sDistanceType[0]=DISTANCE_LOCAL_CITY;
	break;
	case DISTANCE_GAT:/*�۰�̨�û�*/
		sRoamType[0]=ROAM_VISITED_GAT;

		sOppType[0]=PC->sType[0];
		sOppRoamType[0]=PO->sType[0];

		sDistanceType[0]=PC->sType[0];
		if(strcmp(sVisitAreaCode,sCalledCode)==0)
			sDistanceType[0]=DISTANCE_LOCAL_CITY;

	break;
	case DISTANCE_INTER:	/*�����û�*/
		sRoamType[0]=ROAM_VISITED_INTER;

		sOppType[0]=PC->sType[0];
		sOppRoamType[0]=PO->sType[0];

		sDistanceType[0]=PC->sType[0];
		if(strcmp(sVisitAreaCode,sCalledCode)==0)
			sDistanceType[0]=DISTANCE_LOCAL_CITY;

	break;
	default :return INVALID_TYPE;
	}

	strcpy(p->sIpType,	PC->sIpType);
	strcpy(p->sTollType1,	PC->sTollType1);
	strcpy(p->sTollType2,	PC->sTollType2);
	strcpy(p->sHomeTollType2,PH->sTollType2);

	return 0;
}
int InternationalImsi(char sImsi[])
{
	if(sImsi[0]==0) return false;

	if(strncmp(sImsi,"4600",4)!=0&&strncmp(sImsi,"4610",4)!=0)return true;

	return false;
}
int DomesticImsi(char sImsi[])
{
	if(sImsi[0]==0) return false;

	if(strncmp(sImsi,"4600",4)==0||strncmp(sImsi,"4610",4)==0)return true;

	return false;
}
void RegularAreaCode(char sInput[])
{
	int i,l=strlen(sInput);

	for(i=0;i<l;i++){
		if(sInput[i]<'0'||sInput[i]>'9'){
			sInput[i]=0;
			break;
		}
	}	
}
int GetSafetyTotalType(struct MobTicketStruct *p)
{
	int iRet;
	
	char sTempHomeAreaCode[10],sTempVisitAreaCode[10];
	char sTempCalledCode[10],sTempOppVisitAreaCode[10];
	
/*������������,����ȵ���һ�����Ŵ���������,ȷ��������ȷ*/
	strcpy(sTempHomeAreaCode,p->sHomeAreaCode);
	strcpy(sTempVisitAreaCode,p->sVisitAreaCode);
	strcpy(sTempCalledCode,p->sCalledCode);
	strcpy(sTempOppVisitAreaCode,p->sOppVisitAreaCode);
/*ת���������ŵ�����*/
	RegularAreaCode(p->sHomeAreaCode);
	RegularAreaCode(p->sVisitAreaCode);
	RegularAreaCode(p->sCalledCode);
	RegularAreaCode(p->sOppVisitAreaCode);

/*	GetTicketCal(p);*/
/**��ø������**/
	iRet=GetTotalType(p);
	
/*�ָ���������*/
	strcpy(p->sHomeAreaCode,sTempHomeAreaCode);
	strcpy(p->sVisitAreaCode,sTempVisitAreaCode);
	strcpy(p->sCalledCode,sTempCalledCode);
	strcpy(p->sOppVisitAreaCode,sTempOppVisitAreaCode);
	
	return iRet;
}
void GetAreaCountyFlag(int iAreaID,char sCountyFlag[])
{
	struct SettAreaStruct *pTemp;

	if(SearchSettArea(iAreaID,&pTemp)==FOUND)
		strcpy(sCountyFlag,pTemp->sCountyFlag);
	else	strcpy(sCountyFlag,"0");		
}
int AnalyzeTicketBase(struct MobTicketStruct *p,char sVisitAreaCode[],int iFlag)
{
	int iRet;
	char sType[2];

/*��ȡ�����ֶ�*/
	p->iMsisdnLen=		strlen(p->sMsisdn);
	p->iOtherPartyLen=	strlen(p->sOtherParty);
	p->tStartTime=		tGetTime(p->sStartTime);

/**������������дΪĬ����ֵ*/
	strcpy(p->sRoamTariffType,"000");
	strcpy(p->sTollTariffType,"000");
	strcpy(p->sAddTariffType,"000");

/*����Ϊ�յļƷѻ���*/
	if(iFlag==TRUE&&p->iMsisdnLen==0) return INVALID_T130;

/*��ȡ�ݷþ���Ϣ*/
	GetVisitAreaCode(sVisitAreaCode,p->sMsc,p->sTrunkIn,p->sTrunkOut,
		p->sLac,p->sCellID,p->sStartTime,iFlag,p->sVisitAreaCode);
/*��ȡ��������Ϣ*/
	if(GetHomeAreaCode(p->sMsisdn,p->sImsi,p->sVisitAreaCode,
		iFlag,p->sStartTime,&iRet,p->sHomeAreaCode)==NOTFOUND)
		return iRet;
/*���ݶԶ˺���ȷ���Զ�����*/
	if(GetCalledAreaCode(p->sCallType,p->sOtherParty,p->sVisitAreaCode,
		p->sStartTime,&iRet,p->sCalledCode)==NOTFOUND)
		return iRet;
	
	GetRawNbr(p->sMsisdn,p->sHomeAreaCode,p->sStartTime,p->sRawMsisdn);
	GetRawNbr(p->sOtherParty,p->sCalledCode,p->sStartTime,p->sRawOtherParty);
	
	GetOppVisitAreaCode(p->sMsrn,p->sCalledCode,
		p->sStartTime,p->sOppVisitAreaCode);
/*����ǼƷѣ���Ϊ��ת���������û�����Ϊʡ�ڣ����ݷ���Ϊ����*/
	if(iFlag&&strcmp(p->sCallType,"03")==0&&
		GetAreaType(p->sHomeAreaCode,sType)==FOUND){

		if(strcmp(sType,"2")==0)
			strcpy(p->sVisitAreaCode,p->sHomeAreaCode);
	}
/**��ȡ��������**/
	if(GetAcrossCal(p->sCallType,p->sMsc,p->sLac,p->sCellID,
		p->sHomeAreaCode,p->sStartTime,p->sCal)==NOTFOUND){
/**��ȡͬ�Ǳ�ʶ**/
		GetSameCal(p->sCallType,p->sOtherParty,p->sCalledCode,
			p->sVisitAreaCode,p->sOppVisitAreaCode,p->sCal);
	}
	else{	/*ֻ�мƷѱ�ʶΪ���ʱ������߽�����*/
		char sCapitalAreaCode[9];
		
		GetCapitalCode(p->sVisitAreaCode,sCapitalAreaCode);
		
		if(iFlag){
			/*ֻ���û������Ҳ������ŵĲ��̶��Ų��㽻������,
				���಻���н����������⴦��*/
			if(strcmp(p->sCallType,"01")==0&&
				(!IS_MOB_NBR(p->sOtherParty))&&
				strcmp(p->sOtherParty,p->sRawOtherParty)==0&&
				p->sRoamType[0]!='6')
				strcpy(p->sCal,CAL_ACROSS1);
			else
				strcpy(p->sVisitAreaCode,p->sHomeAreaCode);

			/*�Զ�Ϊ������룬Ҫ���߽����δ���,��931�������*/
			if(SpecialNbr(p->sOtherParty,p->sStartTime)==true||
				strcmp(sCapitalAreaCode,"931")==0)
				strcpy(p->sVisitAreaCode,p->sHomeAreaCode);
		}
	}
	return GetSafetyTotalType(p);
}
void AnalyzeTicketExtent(struct MobTicketStruct *p)
{
	int iFlag=0,i;
	struct AreaCodeDescStruct *pAreaCode=NULL;
	struct TrunkStruct *pTrunk=NULL;
	struct HeadCarrStruct	*pHeadCarr=NULL;
	char	sHomeAreaCode[10],sCalledCode[10];
	
	struct TicketAnalyzeStruct *pa=&TicketAnalyze;

/*������������,����ȵ���һ�����Ŵ���������,ȷ��������ȷ*/
	strcpy(sHomeAreaCode,	p->sHomeAreaCode);
	strcpy(sCalledCode,	p->sCalledCode);
	RegularAreaCode(sHomeAreaCode);
	RegularAreaCode(sCalledCode);

/*���ִ�й���ʽ������һ��Type�ĵ���*/
	if(i==0) GetSafetyTotalType(p);

	bzero((void*)&TicketAnalyze,sizeof(struct TicketAnalyzeStruct));

	if(SearchTrunk(p->sMsc,p->sTrunkIn,"I",p->sStartTime,&pTrunk)==FOUND){

		pa->iTrunkInTypeID=	pTrunk->iTrunkTypeID;
		pa->iTrunkInCarrierID=pTrunk->iSettCarrierID;
		strcpy(pa->sTrunkInOppAreaCode,pTrunk->sOppAreaCode);
		
		if(SearchAreaCodeDesc(pTrunk->sOppAreaCode,&pAreaCode)==FOUND)
			strcpy(pa->sTrunkInOppType,pAreaCode->sType);
		if(strcmp(p->sVisitAreaCode,pTrunk->sOppAreaCode)==0)
			pa->sTrunkInOppType[0]=DISTANCE_LOCAL_CITY;
	}
	
	if(SearchTrunk(p->sMsc,p->sTrunkOut,"O",p->sStartTime,&pTrunk)==FOUND){
		
		pa->iTrunkOutTypeID=	pTrunk->iTrunkTypeID;
		pa->iTrunkOutCarrierID=pTrunk->iSettCarrierID;
		strcpy(pa->sTrunkOutOppAreaCode,pTrunk->sOppAreaCode);

		if(SearchAreaCodeDesc(pTrunk->sOppAreaCode,&pAreaCode)==FOUND)
			strcpy(pa->sTrunkOutOppType,pAreaCode->sType);
		if(strcmp(p->sVisitAreaCode,pTrunk->sOppAreaCode)==0)
			pa->sTrunkOutOppType[0]=DISTANCE_LOCAL_CITY;
	}
	
	if(SearchHeadCarr(p->sMsisdn,"*",p->sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0) iFlag=true;
		else iFlag=false;
	}
	else iFlag=false;
	
	if(iFlag==true){
		pa->iCallingCarrierID=pHeadCarr->iSettCarrierID;
		pa->iCallingTypeID=	pHeadCarr->iTypeID;
		pa->iCallingAreaID=	pHeadCarr->iAreaID;
		pa->iAAreaID=		pHeadCarr->iSettAreaID;
	}
	else  if(SearchHeadCarr(p->sRawMsisdn,sHomeAreaCode,
		p->sStartTime,&pHeadCarr)==FOUND){
		pa->iCallingCarrierID=pHeadCarr->iSettCarrierID;
		pa->iCallingTypeID=	pHeadCarr->iTypeID;
		pa->iCallingAreaID=	pHeadCarr->iAreaID;
		pa->iAAreaID=		pHeadCarr->iSettAreaID;
	}
	else if(SearchHeadCarr(p->sRawMsisdn,"*",p->sStartTime,&pHeadCarr)==FOUND){
		pa->iCallingCarrierID=pHeadCarr->iSettCarrierID;
		pa->iCallingTypeID=	pHeadCarr->iTypeID;
		pa->iCallingAreaID=	pHeadCarr->iAreaID;
		pa->iAAreaID=		pHeadCarr->iSettAreaID;
	}
	else if(SearchHeadCarr(p->sMsisdn,"*",p->sStartTime,&pHeadCarr)==FOUND){
		pa->iCallingCarrierID=pHeadCarr->iSettCarrierID;
		pa->iCallingTypeID=	pHeadCarr->iTypeID;
		pa->iCallingAreaID=	pHeadCarr->iAreaID;
		pa->iAAreaID=		pHeadCarr->iSettAreaID;
	}
	
	if(SearchHeadCarr(p->sOtherParty,"*",p->sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0) iFlag=true;
		else iFlag=false;
	}
	else iFlag=false;
	
	if(iFlag==true){
		pa->iCalledCarrierID=	pHeadCarr->iSettCarrierID;
		pa->iCalledTypeID=	pHeadCarr->iTypeID;
		pa->iCalledAreaID=	pHeadCarr->iAreaID;
		pa->iBAreaID=		pHeadCarr->iSettAreaID;
	}
	else if(SearchHeadCarr(p->sRawOtherParty,sCalledCode,
		p->sStartTime,&pHeadCarr)==FOUND){
		pa->iCalledCarrierID=	pHeadCarr->iSettCarrierID;
		pa->iCalledTypeID=	pHeadCarr->iTypeID;
		pa->iCalledAreaID=	pHeadCarr->iAreaID;
		pa->iBAreaID=		pHeadCarr->iSettAreaID;
	}
	else if(SearchHeadCarr(p->sRawOtherParty,"*",p->sStartTime,&pHeadCarr)==FOUND){
		pa->iCalledCarrierID=	pHeadCarr->iSettCarrierID;
		pa->iCalledTypeID=	pHeadCarr->iTypeID;
		pa->iCalledAreaID=	pHeadCarr->iAreaID;
		pa->iBAreaID=		pHeadCarr->iSettAreaID;
	}
	else if(SearchHeadCarr(p->sOtherParty,"*",p->sStartTime,&pHeadCarr)==FOUND){
		pa->iCalledCarrierID=	pHeadCarr->iSettCarrierID;
		pa->iCalledTypeID=	pHeadCarr->iTypeID;
		pa->iCalledAreaID=	pHeadCarr->iAreaID;
		pa->iBAreaID=		pHeadCarr->iSettAreaID;
	}
	/*�������ر�ʶ*/

	/*����Ϊ���ز��б��ص��������0,1:����Ϊ9*/
	if(strcmp(p->sRoamType,"1")==0&&strcmp(p->sDistanceType,"1")==0&&
		pa->iCallingAreaID>0&&pa->iCalledAreaID>0){

		if(pa->iCallingAreaID==pa->iCalledAreaID)
			strcpy(pa->sSameAreaFlag,"0");
		else	strcpy(pa->sSameAreaFlag,"1");

		/*ֻҪ��һ���ĺ�ͷΪĬ�ϣ�δ���ã���Ϊ�л�*/
		if(pa->iCallingAreaID==9901||pa->iCalledAreaID==9901)
			strcpy(pa->sSameAreaFlag,"0");
	}
	else	strcpy(pa->sSameAreaFlag,"9");
	
	GetAreaCountyFlag(pa->iAAreaID,pa->sCallingCountyFlag);
	GetAreaCountyFlag(pa->iBAreaID,pa->sCalledCountyFlag);
}
/*
get_belong_code(msisdn);
get_city_code(area_code);
get_area_code(city_code);
get_area_type(area);
get_trunk_type(msc,trunk,direction);
get_trunk_area(msc,trunk,direction);
get_trunk_carrier(msc,trunk);
get_head_type(head,area);
get_head_carrier(head,area);
get_head_area(head,area);
get_imsi_area(imsi);
get_msc_area(msc);
get_lac_cell_area(msc,lac,cell_id);
get_across_cal(msc,lac,cell_id,home_area);
get_same_cal(call_type,other_party,called_code,visit_code,opp_vist_code);
get_home_area_code(msisdn,imsi,visit_code);
get_visit_area_code(msc,lac,cell_id,trunk_in,trunk_out,start_time,area_code);
get_called_area_code(other_party,visit_code);
=========================
getbinint(table_name,int_key,str_key,start_time);
getbinstr(table_name,int_key,str_key,start_time);
gettrieint(table_name,int_key,str_key,start_time);
gettriestr(table_name,int_key,str_key,start_time);
*/
int GetBelongCode(char sMsisdn[],char sStartTime[],char sBelongCode[])
{
	struct T130AreaCodeStruct *pT130=NULL;
	
	strcpy(sBelongCode,"");
	
	if(SearchT130AreaCode(sMsisdn,sStartTime,&pT130)==FOUND){
		strcpy(sBelongCode,pT130->sAreaCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetCityCode(char sAreaCode[],char sCityCode[])
{
	struct AreaCodeDescStruct *pTemp;
	
	strcpy(sCityCode,"");

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==FOUND){
		strcpy(sCityCode,pTemp->sCityCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetAreaType(char sAreaCode[],char sType[])
{
	struct AreaCodeDescStruct *pTemp;
	
	strcpy(sType,"");

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==FOUND){
		strcpy(sType,pTemp->sType);
		return FOUND;
	}
	return NOTFOUND;
}
int GetCapitalCode(char sAreaCode[],char sCapitalCode[])
{
	struct AreaCodeDescStruct *pTemp;
	
	strcpy(sCapitalCode,"");

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==FOUND){
		strcpy(sCapitalCode,pTemp->sCapitalAreaCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetCountryCode(char sAreaCode[],char sCountryCode[])
{
	struct AreaCodeDescStruct *pTemp;
	
	strcpy(sCountryCode,"");

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==FOUND){
		strcpy(sCountryCode,pTemp->sCountryCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetAreaCode(char sCityCode[],char sAreaCode[])
{
	struct AreaCodeDescStruct *pTemp;
	
	strcpy(sAreaCode,"");

	if(SearchCityCodeDesc(sCityCode,&pTemp)==FOUND){
		strcpy(sAreaCode,pTemp->sAreaCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetAreaIpType(char sAreaCode[],char sType[])
{
	struct AreaCodeDescStruct *pTemp;
	
	strcpy(sType,"");

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==FOUND){
		strcpy(sType,pTemp->sIpType);
		return FOUND;
	}
	return NOTFOUND;
}
int GetAreaTollType1(char sAreaCode[],char sType[])
{
	struct AreaCodeDescStruct *pTemp;

	strcpy(sType,"");

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==FOUND){
		strcpy(sType,pTemp->sTollType1);
		return FOUND;
	}
	return NOTFOUND;
}
int GetAreaTollType2(char sAreaCode[],char sType[])
{
	struct AreaCodeDescStruct *pTemp;
	
	strcpy(sType,"");

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==FOUND){
		strcpy(sType,pTemp->sTollType2);
		return FOUND;
	}
	return NOTFOUND;
}
int GetTrunkType(char sMsc[],char sTrunk[],char sStartTime[],
	char sDirection[],int *piTrunkTypeID)
{
	struct TrunkStruct *pTemp;
	
	*piTrunkTypeID=0;
	
	if(SearchTrunk(sMsc,sTrunk,sDirection,sStartTime,&pTemp)==FOUND){
		*piTrunkTypeID=pTemp->iTrunkTypeID;
		return FOUND;
	}
	return NOTFOUND;
}
int GetTrunkArea(char sMsc[],char sTrunk[],char sStartTime[],
	char sDirection[],char sAreaCode[])
{
	struct TrunkStruct *pTemp;
	
	strcpy(sAreaCode,"");
	
	if(SearchTrunk(sMsc,sTrunk,sDirection,sStartTime,&pTemp)==FOUND){
		strcpy(sAreaCode,pTemp->sOppAreaCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetTrunkCarrier(char sMsc[],char sTrunk[],char sStartTime[],
	char sDirection[],int *piCarrierID)
{
	struct TrunkStruct *pTemp;
	
	*piCarrierID=0;
	
	if(SearchTrunk(sMsc,sTrunk,sDirection,sStartTime,&pTemp)==FOUND){
		*piCarrierID=pTemp->iSettCarrierID;
		return FOUND;
	}
	return NOTFOUND;
}
int GetHeadComm(char sAccNbr[],char sRawNbr[],char sAreaCode[],char sStartTime[],
	void (*get_head_data)(void *pi,void *po),void *pData)
{
	struct HeadCarrStruct	*pHeadCarr;
	

	if(SearchHeadCarr(sAccNbr,"*",sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0){
			(*get_head_data)((void*)pHeadCarr,pData);
			return FOUND;
		}
	}
	if(SearchHeadCarr(sRawNbr,sAreaCode,sStartTime,&pHeadCarr)==FOUND){
		(*get_head_data)((void*)pHeadCarr,pData);
		return FOUND;
	}
	if(SearchHeadCarr(sRawNbr,"*",sStartTime,&pHeadCarr)==FOUND){
		(*get_head_data)((void*)pHeadCarr,pData);
		return FOUND;
	}
	if(SearchHeadCarr(sAccNbr,"*",sStartTime,&pHeadCarr)==FOUND){
		(*get_head_data)((void*)pHeadCarr,pData);
		return FOUND;
	}
	return NOTFOUND;
}
void get_head_data_type_id(void *pi,void *po)
{
	*((int*)po)=((struct HeadCarrStruct*)pi)->iTypeID;
}
void get_head_data_carrier_id(void *pi,void *po)
{
	*((int*)po)=((struct HeadCarrStruct*)pi)->iSettCarrierID;
}
void get_head_data_area_id(void *pi,void *po)
{
	*((int*)po)=((struct HeadCarrStruct*)pi)->iAreaID;
}
void get_head_data_type(void *pi,void *po)
{
	strcpy((char*)po,((struct HeadCarrStruct*)pi)->sType);
}
int GetHeadTypeID(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],int *piTypeID)
{
	*piTypeID=0;
	return GetHeadComm(sAccNbr,sRawNbr,sAreaCode,sStartTime,
		get_head_data_type_id,(void*)piTypeID);
}
int GetHeadType(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],char sType[])
{
	strcpy(sType,"");
	return GetHeadComm(sAccNbr,sRawNbr,sAreaCode,sStartTime,
		get_head_data_type,(void*)sType);
}
int GetHeadCarr(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],int *piCarrierID)
{
	*piCarrierID=0;
	return GetHeadComm(sAccNbr,sRawNbr,sAreaCode,sStartTime,
		get_head_data_carrier_id,(void*)piCarrierID);
}
int GetHeadArea(char sAccNbr[],char sRawNbr[],char sAreaCode[],
	char sStartTime[],int *piAreaID)
{
	*piAreaID=0;
	return GetHeadComm(sAccNbr,sRawNbr,sAreaCode,sStartTime,
		get_head_data_area_id,(void*)piAreaID);
}
int GetImsiArea(char sImsi[],char sMscType[],char sStartTime[],char sAreaCode[])
{
	struct TelecomCarrierStruct *pTemp=NULL;
	
	strcpy(sAreaCode,"");
	
	if(SearchTelecomCarrier(sImsi,sMscType,sStartTime,&pTemp)==FOUND){
		strcpy(sAreaCode,pTemp->sCountryAreaCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetMscArea(char sMsc[],char sAreaCode[])
{
	struct MscStruct *pTemp=NULL;
	
	strcpy(sAreaCode,"");
	
	if(SearchMsc(sMsc,&pTemp)==FOUND){
		strcpy(sAreaCode,pTemp->sAreaCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetMscType(char sMsc[],char sMscType[])
{
	struct MscStruct *pTemp=NULL;
	
	strcpy(sMscType,"");
	
	if(SearchMsc(sMsc,&pTemp)==FOUND){
		strcpy(sMscType,pTemp->sMscType);
		return FOUND;
	}
	return NOTFOUND;
}
int GetLacCellArea(char sMsc[],char sLac[],char sCellID[],char sStartTime[],
	char sAreaCode[])
{
	struct CellCodeStruct *pTemp=NULL;
	
	strcpy(sAreaCode,"");
	
	if(SearchCellCode(sMsc,sLac,sCellID,sStartTime,&pTemp)==FOUND){
		strcpy(sAreaCode,pTemp->sAreaCode);
		return FOUND;
	}
	return NOTFOUND;
}
int GetAcrossCal(char sCallType[],char sMsc[],char sLac[],char sCellID[],
	char sHomeAreaCode[],char sStartTime[],char sCal[])
{
	struct AcrossCellCodeStruct *pNoUse=NULL;
	
	char sTempHomeAreaCode[9];
	
	strcpy(sTempHomeAreaCode,sHomeAreaCode);
	
	RegularAreaCode(sTempHomeAreaCode);
	
	strcpy(sCal,CAL_NORMAL);
		 
	if(strcmp(sCallType,"01")!=0&&
		 strcmp(sCallType,"02")!=0&&
		 strcmp(sCallType,"03")!=0){
		 return NOTFOUND;
	}
	if(SearchAcrossCellCode(sMsc,sLac,sCellID,
		sTempHomeAreaCode,sStartTime,&pNoUse)==FOUND){
	
		strcpy(sCal,CAL_ACROSS);
		return FOUND;
	}
	return NOTFOUND;
}

int GetSameCal(char sCallType[],char sOtherParty[],char sCalledCode[],
	char sVisitAreaCode[],char sOppVisitAreaCode[],char sCal[])
{
	char sTempCalledCode[9],sTempVisitAreaCode[9],sTempOppVisitAreaCode[9];
	
	strcpy(sTempCalledCode,sCalledCode);
	strcpy(sTempVisitAreaCode,sVisitAreaCode);
	strcpy(sTempOppVisitAreaCode,sOppVisitAreaCode);

	RegularAreaCode(sTempCalledCode);
	RegularAreaCode(sTempVisitAreaCode);
	RegularAreaCode(sTempOppVisitAreaCode);
	
	strcpy(sCal,CAL_NORMAL);
	
	if(strcmp(sCallType,"01")!=0||
		!IS_MOB_NBR(sOtherParty)||
		strcmp(sTempCalledCode,sTempVisitAreaCode)==0){

		 return NOTFOUND;
	}
	if(strcmp(sTempVisitAreaCode,sTempOppVisitAreaCode)==0){
	
		strcpy(sCal,CAL_SAME);
		return FOUND;
	}
	return NOTFOUND;
}
int GetVisitAreaCode(char sVisitCode[],char sMsc[],
	char sTrunkIn[],char sTrunkOut[],char sLac[],char sCellID[],
	char sStartTime[],int iFlag,char sVisitAreaCode[])
{
	char	*pc,sDefVisitCode[10];
	struct MscStruct *pMsc=NULL;
	
	strcpy(sVisitAreaCode,"");
	
	pc=strchr(sVisitCode,':');

	if(pc==NULL)	pc=sVisitCode;
	else		pc++;

	strncpy(sDefVisitCode,pc,3); sDefVisitCode[3]=0;
		
	if(iFlag==true){/*�����õ���LAC��CELLID����*/
	
		struct CellCodeStruct *pCellCode=NULL;
		
		if(SearchCellCode(sMsc,sLac,sCellID,sStartTime,&pCellCode)==FOUND)
			strcpy(sVisitAreaCode,pCellCode->sAreaCode);
		else if(SearchMsc(sMsc,&pMsc)==FOUND)
			strcpy(sVisitAreaCode,pMsc->sAreaCode);
		else 
			strcpy(sVisitAreaCode,sDefVisitCode);
	}
	else{/*����������м�������*/
		int iRetIn,iRetOut;
		struct TrunkStruct *pTrunk=NULL;
		struct TrunkStruct *pTrunkIn=NULL,*pTrunkOut=NULL;

		iRetIn=SearchTrunk(sMsc,sTrunkIn,"I",sStartTime,&pTrunkIn);
		iRetOut=SearchTrunk(sMsc,sTrunkOut,"O",sStartTime,&pTrunkOut);
			
		if(iRetIn==FOUND){
			/*��Ӧ����������Ӫ�̽���ϵͳʱ��Ҫ����*/
			if(pTrunkIn->iSettCarrierID!=PRIMARY_CARRIER&&
				pTrunkIn->iSettCarrierID!=4)
				pTrunk=pTrunkIn;
		}
		if(iRetOut==FOUND){
			/*��Ӧ����������Ӫ�̽���ϵͳʱ��Ҫ����*/
			if(pTrunkOut->iSettCarrierID!=PRIMARY_CARRIER&&
				pTrunkOut->iSettCarrierID!=4)
				pTrunk=pTrunkOut;
		}
		/*���ȿ��Ƿ���ͨ�ͷ���ͨ���м̣�֮���ٿ�����ͨ�м�*/
		if(pTrunk==NULL&&iRetIn==FOUND){
			if(pTrunkIn->iSettCarrierID==4) pTrunk=pTrunkIn;
				
			/*���ǵ�������������G���������ںϣ�
			ԭSETT_CARRIER_IDΪ4�ģ����ڵ���ΪSETT_CARRIER_IDΪ3*/
			if(pTrunkIn->iTrunkTypeID>=3010&&
				pTrunkIn->iTrunkTypeID<=3013&&
				pTrunkIn->iSettCarrierID==PRIMARY_CARRIER)
				pTrunk=pTrunkIn;
		}
		if(pTrunk==NULL&&iRetOut==FOUND){
			if(pTrunkOut->iSettCarrierID==4) pTrunk=pTrunkOut;
				
			/*���ǵ�������������G���������ںϣ�
			ԭSETT_CARRIER_IDΪ4�ģ����ڵ���ΪSETT_CARRIER_IDΪ3*/
			if(pTrunkOut->iTrunkTypeID>=3010&&
				pTrunkOut->iTrunkTypeID<=3013&&
				pTrunkOut->iSettCarrierID==PRIMARY_CARRIER)
				pTrunk=pTrunkOut;
		}

		if(pTrunk!=NULL)
			strcpy(sVisitAreaCode,pTrunk->sOppAreaCode);
		else if(SearchMsc(sMsc,&pMsc)==FOUND)
			strcpy(sVisitAreaCode,pMsc->sAreaCode);
		else
			strcpy(sVisitAreaCode,sDefVisitCode);		
	}
	
	if(strlen(sVisitAreaCode)==0) return NOTFOUND;
	
	return FOUND;
}
int WantAdjust(char sMsisdn[])
{	
/*
	if(strncmp(sMsisdn,"193",3)==0||
		strncmp(sMsisdn,"179",3)==0) return TRUE;
*/
	if(sMsisdn[0]!='0') return FALSE;

	if(strncmp(sMsisdn,"0193",4)==0||
		strncmp(sMsisdn,"00193",5)==0||
		strncmp(sMsisdn,"000193",6)==0||
		strncmp(sMsisdn,"0179",4)==0||
		strncmp(sMsisdn,"00179",5)==0||
		strncmp(sMsisdn,"000179",6)==0) return TRUE;
	return FALSE;
}
int GetHomeAreaCode(char sMsisdn[],char sImsi[],char sVisitAreaCode[],
	int iFlag,char sStartTime[],int *piErrCode,char sHomeAreaCode[])
{
	char	sTempImsi[16],sMscType[2];
	struct T130AreaCodeStruct *pT130;
	struct AreaCodeDescStruct *pAreaCode;
	struct TelecomCarrierStruct *pTeleCarr;
	
	strcpy(sHomeAreaCode,"");
	*piErrCode=0;

	/*�ƶ����л��� �� ����IMSI��û��IMSI ����㻰��*/
	if(IS_MOB_NBR(sMsisdn)&&
		(iFlag==false||DomesticImsi(sImsi)||sImsi[0]==0)){
		
		if(SearchT130AreaCode(sMsisdn,sStartTime,&pT130)==NOTFOUND){
		
			int iTmp=0;
			
			GetHeadCarr(sMsisdn,sMsisdn,"",sStartTime,&iTmp);
			
			if(iTmp==PRIMARY_CARRIER&&iFlag==true){
				*piErrCode=INVALID_T130;
				return NOTFOUND;
			}
			if(iFlag==true)	strcpy(sHomeAreaCode,sVisitAreaCode);
			else	strcpy(sHomeAreaCode,DEF_DOMESTIC_AREA);
		}
		else
			strcpy(sHomeAreaCode,pT130->sAreaCode);
	}/*���ʻ���*/
	else if(InternationalImsi(sImsi)||(iFlag==true&&strlen(sImsi)==15)){
	
		if(InternationalImsi(sImsi)==FALSE){
			strcpy(sMscType,"C");
			strcpy(sTempImsi,sImsi+5);
		}
		else{
			strcpy(sMscType,"G");
			strcpy(sTempImsi,sImsi);
		}
		if(SearchTelecomCarrier(sTempImsi,sMscType,sStartTime,&pTeleCarr)
			==FOUND){
			strcpy(sHomeAreaCode,pTeleCarr->sCountryAreaCode);
			return FOUND;
		}
		strcpy(sMscType,"C");
		strcpy(sTempImsi,sImsi+5);
		
		if(SearchTelecomCarrier(sTempImsi,sMscType,sStartTime,&pTeleCarr)
			==FOUND){
			strcpy(sHomeAreaCode,pTeleCarr->sCountryAreaCode);
			return FOUND;
		}
		/*Ĭ��Ϊ�����ĺ���*/
		if(strncmp(sMsisdn,"886",3)==0)
			strcpy(sHomeAreaCode,"0886");
		else if(strncmp(sMsisdn,"853",3)==0)
			strcpy(sHomeAreaCode,"0853");
		else if(strncmp(sMsisdn,"852",3)==0)
			strcpy(sHomeAreaCode,"0852");
		else 	strcpy(sHomeAreaCode,DEF_INTERNATIONAL_AREA);
	
		if(WantAdjust(sMsisdn)&&iFlag)
			strcpy(sHomeAreaCode,sVisitAreaCode);
		if(InternationalImsi(sImsi)==FALSE){
			*piErrCode=INVALID_TELECOM_CARRIER;
			return NOTFOUND;
		}
		return FOUND;
		
	}
	else{
		char	*pMsisdn;
		if(strncmp(sMsisdn,"179",3)==0)pMsisdn=sMsisdn+5;
		else if(strncmp(sMsisdn,"193",3)==0)pMsisdn=sMsisdn+3;
		else if(strncmp(sMsisdn,"0193",4)==0)	pMsisdn=sMsisdn+4;
		else if(strncmp(sMsisdn,"0179",4)==0)	pMsisdn=sMsisdn+6;
		else pMsisdn=sMsisdn;
		
		if(strlen(sMsisdn)>8){

			int iLen;
			
			if(pMsisdn[0]=='0')iLen=1;
			else iLen=0;
			
			if(SearchAreaCodeDesc(pMsisdn+iLen,&pAreaCode)==FOUND)
				strcpy(sHomeAreaCode,pAreaCode->sAreaCode);
			else	/*�Բ����Ŷε�Ĭ��home*/
				strcpy(sHomeAreaCode,sVisitAreaCode);
		}
		else if(strncmp(sMsisdn,"0",1)==0){
			int iNoUse=0;
			
			if(GetCalledAreaCode("01",sMsisdn,sVisitAreaCode,
				sStartTime,&iNoUse,sHomeAreaCode)==NOTFOUND)
				strcpy(sHomeAreaCode,sVisitAreaCode);
		}
		else
			strcpy(sHomeAreaCode,sVisitAreaCode);

		/*Ĭ��17911,��193����Ĭ�Ϲ��ʴ�����*/
		if(strncmp(sMsisdn,"0017911",7)==0||
			strncmp(sMsisdn,"00017911",8)==0||
			strncmp(sMsisdn,"00193",5)==0||
			strncmp(sMsisdn,"000193",6)==0||
			strncmp(sMsisdn,"000196",6)==0||
			strncmp(sMsisdn,"000190",6)==0||
			strncmp(sMsisdn,"00179",5)==0) 
			strcpy(sHomeAreaCode,DEF_INTERNATIONAL_AREA);
		if(iFlag==true&&
			(strlen(sMsisdn)!=strlen(pMsisdn)||
			strcmp(sHomeAreaCode,DEF_INTERNATIONAL_AREA)==0))
			strcpy(sHomeAreaCode,sVisitAreaCode);
	}
	return FOUND;
}
/**
'R'	��ʾ��	17911��193��17909��96951��
'E'	�������0��00��000��123
'C'	��ͨ�� 	83352278��7534533��
'S'	�����ط���(�����ط���ҵ���ط������кŵ�)121��114��10000��1001��1860��12598��
'F'	����ط���110��119��120��122��
'X'	Ѱ����	128��129��191��192��

1.�жϺ����Ƿ�����ʾ�ſ�ͷ���������������ʾ��;
2.�жϺ����Ƿ�Ϊ����ط���Ѱ���������ط����̺��ط���������ţ�
	�ж�Ϊ0,00,000��ʱ�򣬱�������ȫƥ��;�жϲ�����ŵ�ʱ�����Ϊ��ȫƥ��;
	���öԶ˺�Ϊ����.
3.�жϺ����Ƿ�Ϊ13��013�����������ҺŶα���������;
4.�ж϶Զ˺����Ƿ���0��ͷ
���0��ͷ
	����������ſ�ͷ�������Ҳ���
		����Ǳ��л���ֱ��ȡ����;
		�ж��Ƿ�Ϊ��ѷ��ط���Ѱ�����ط���
			������ţ��Ⱥ��룬������򱾵�;
		�ж��Ƿ�Ϊ��ʾ�ſ�ͷ������ǣ����Ǳ���;
		�����׳��쳣.
	�ҵ���ֱ��ȡ�������.
��0��ͷ
	����>=5 <10
		��һ�����ſ�ͷ
			Ϊ����ط���Ѱ���������ط����̺��ط���������ţ�ƥ�������������
			�жϺ��볤���Ƿ�>=7������ֱ�Ӹ����������;
			������Ǳ���;
		������Ǳ���
	����>10λ������
		���ҵ����ž�ֱ��ok��;
		�Ҳ�������ֱ�ӱ���
        ����С��5λ
		ֱ��Ϊ����;
**/
int SpecialNbr(char sOtherParty[],char sStartTime[])
{
	struct HeadCarrStruct	*pHeadCarr=NULL;

	if(SearchHeadCarr(sOtherParty,"*",sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_ERR)==0||
			strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_SPEC)==0||
			strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_FREE)==0||
			strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_CALL)==0){
			return true;
		}
	}
	return false;
}
int RefNbr(char sOtherParty[],char sStartTime[])
{
	struct HeadCarrStruct	*pHeadCarr=NULL;

	if(SearchHeadCarr(sOtherParty,"*",sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0) return true;
	}
	return false;
}
/**˵��
	1.ֻ�����л����������⴦��;
	2.ֻ�Է�0��ͷ,��13,����ʾ��,�����⴦��;
	3.���ڶԶ˺�����2-8��ͷ�ģ��Զ�������ΪVISIT_AREA_CODE;
	4.������HEAD_CARR���в飬TYPE IN('S','F','E','X') �ĺ���::
		��ͨ�ط�������ط�����������롢Ѱ���ĺ��룬��Զ�������Ϊͨ����;
**/
int GetLocalCalledCode(char sCallType[],char sOtherParty[],char sStartTime[],
	char sVisitAreaCode[],char sCalledCode[])
{
/*�������л���,��0��ͷ,��13,��,193,��17911��ͷ�������⴦��*/
	if(strcmp(sCallType,"01")==0&&
		sOtherParty[0]!='0'&&
		IS_MOB_NBR(sOtherParty)==false&&
		RefNbr(sOtherParty,sStartTime)==false){

		if(sOtherParty[0]>='2'&&sOtherParty[0]<='8'){
			strcpy(sCalledCode,sVisitAreaCode);
			return true;
		}
		if(SpecialNbr(sOtherParty,sStartTime)==true){
			strcpy(sCalledCode,sVisitAreaCode);
			return true;
		}
	}
	return false;
}
int GetCalledAreaCode(char sCallType[],char sCalledNbr[],char sVisitAreaCode[],
	char sStartTime[],int *piErrCode,char sCalledAreaCode[])
{
	int  len,off;
	char *sOtherParty;
	struct T130AreaCodeStruct *pT130=NULL;
	struct AreaCodeDescStruct *pAreaCode=NULL;
	struct HeadCarrStruct	*pHeadCarr=NULL;


/*��ʼ������*/
	off=0;
	*piErrCode=0;
	strcpy(sCalledAreaCode,"");
/*��ȡ���صı��к�*/
	if(GetLocalCalledCode(sCallType,sCalledNbr,sStartTime,sVisitAreaCode,
		sCalledAreaCode)==true) return FOUND;

/*1.�жϺ����Ƿ�����ʾ�ſ�ͷ���������������ʾ��*/
	sOtherParty=sCalledNbr+off;
	if(SearchHeadCarr(sOtherParty,"*",sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0&&
			strncmp(pHeadCarr->sHead,"00",2)!=0)
			off+=strlen(pHeadCarr->sHead);
	}
/*2.�жϺ����Ƿ�Ϊ����ط���Ѱ���������ط���������ţ�*/
	sOtherParty=sCalledNbr+off;
	if(strlen(sOtherParty)==0){
		*piErrCode=off;
		strcpy(sCalledAreaCode,sVisitAreaCode);
		return FOUND;
	}
	if(SpecialNbr(sOtherParty,sStartTime)==true){
		*piErrCode=off;
		strcpy(sCalledAreaCode,sVisitAreaCode);
		return FOUND;
	}
/*3.�жϺ����Ƿ�Ϊ13��013�����������ҺŶα���������;*/
	if(IS_MOB_NBR(sOtherParty)){

		if(sOtherParty[0]=='0'){off++;sOtherParty++;}
		
		if(SearchT130AreaCode(sOtherParty,sStartTime,&pT130)==FOUND){
			strcpy(sCalledAreaCode,pT130->sAreaCode);
			return FOUND;
		}
		/*ע������Ĭ��Ϊ���غŶ�,��Ϊ��������ܴܺ�*/
		/*return INVALID_T130;*/
		*piErrCode=off;
		strcpy(sCalledAreaCode,sVisitAreaCode);
		return FOUND;
		
	}
/*4.�ж϶Զ˺����Ƿ���0��ͷ*/
	if(sOtherParty[0]=='0'){
		off++;
		sOtherParty++;
		if(SearchAreaCodeDesc(sOtherParty,&pAreaCode)==NOTFOUND){

			if(strcmp(sCallType,"02")==0){
				*piErrCode=off;
				strcpy(sCalledAreaCode,sVisitAreaCode);
				return FOUND;
			}
			if(SpecialNbr(sOtherParty,sStartTime)==true){
				*piErrCode=off;
				strcpy(sCalledAreaCode,sVisitAreaCode);
				return FOUND;
			}
			if(strlen(sOtherParty)<=5){
				*piErrCode=off;
				strcpy(sCalledAreaCode,sVisitAreaCode);
				return FOUND;
			}
			if(off>1){/*������������ֱ���Ҳ�����Ĭ�ϱ���*/
				*piErrCode=off;
				strcpy(sCalledAreaCode,sVisitAreaCode);
				return FOUND;
			}
			*piErrCode=INVALID_AREA_CODE;
			return NOTFOUND;
		}
		strcpy(sCalledAreaCode,pAreaCode->sAreaCode);
		*piErrCode=off;
		return FOUND;
	}
/*��0��ͷ*/
	len=strlen(sOtherParty);

	/*����>=5 <10*/	
	if(len>=5&&len<10){

		if(strcmp(sCallType,"02")!=0&&strcmp(sCallType,"03")!=0&&
			SearchHeadCarr(sOtherParty,sVisitAreaCode,
			sStartTime,&pHeadCarr)==FOUND){
			if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_CORR)==0){
				strcpy(sCalledAreaCode,sVisitAreaCode);
				*piErrCode=off;
				return FOUND;
			}
		}
		if(SearchAreaCodeDesc(sOtherParty,&pAreaCode)==FOUND){
			
			sOtherParty+=strlen(pAreaCode->sAreaCode);
			/*Ϊ����ط���Ѱ�����ط���������ţ�
				ƥ�������������*/
			if(SpecialNbr(sOtherParty,sStartTime)==true&&
				pAreaCode->sType[0]=='2'){
				strcpy(sCalledAreaCode,pAreaCode->sAreaCode);
				*piErrCode=off;
				return FOUND;
			}
			/*�жϺ��볤���Ƿ�>=7������ֱ�Ӹ����������;*/
			if(strlen(sOtherParty)>=7){
				strcpy(sCalledAreaCode,pAreaCode->sAreaCode);
				*piErrCode=off;
				return FOUND;
			}
			/*������Ǳ���;*/
		}
		/*������Ǳ���*/
		strcpy(sCalledAreaCode,sVisitAreaCode);
		*piErrCode=off;
		return FOUND;
	}
/*����>10λ������*/
	if(len>=10){
		if(SearchAreaCodeDesc(sOtherParty,&pAreaCode)==FOUND){
			off+=strlen(pAreaCode->sAreaCode);
			strcpy(sCalledAreaCode,pAreaCode->sAreaCode);
			*piErrCode=off;
			return FOUND;
		}
		/*������Ǳ���*/
		strcpy(sCalledAreaCode,sVisitAreaCode);
		*piErrCode=off;
		return FOUND;
	}
/*����С��5λ*/
	strcpy(sCalledAreaCode,sVisitAreaCode);
	*piErrCode=off;
	return FOUND;
}
int GetRawNbr(char sAccNbr[],char sAreaCode[],char sStartTime[],char sRawNbr[])
{
	int off=0,len,l,refLen=0;
	char *sOtherParty=sAccNbr;
	char sTempAreaCode[9],sLongAreaCode[9];
	struct HeadCarrStruct	*pHeadCarr=NULL;

/*�жϱ��غ���*/
	if(SearchHeadCarr(sOtherParty,sAreaCode,sStartTime,&pHeadCarr)==FOUND){

		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_CORR)==0){
			if((strlen(sOtherParty)==8&&pHeadCarr->iLen==8)||
				strlen(sOtherParty)==7){
				strcpy(sRawNbr,sOtherParty);
				return 0;
			}
		}
	}
	
	if(SearchHeadCarr(sOtherParty,"*",sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0&&
			strncmp(pHeadCarr->sHead,"00",2)!=0){
			refLen=strlen(pHeadCarr->sHead);
			off+=strlen(pHeadCarr->sHead);
		}
	}
	sOtherParty=sAccNbr+off;
	if(SpecialNbr(sOtherParty,sStartTime)==true){
		strcpy(sRawNbr,sOtherParty);
		return 0;
	}
	if(sOtherParty[0]=='0'){ off++;sOtherParty++;}
	if(IS_MOB_NBR(sOtherParty)&&sOtherParty[0]=='1'){
		strcpy(sRawNbr,sOtherParty);
		return 0;
	}

	strcpy(sTempAreaCode,sAreaCode);
	RegularAreaCode(sTempAreaCode);

	l=strlen(sTempAreaCode);
	len=strlen(sOtherParty);
	if(strncmp(sOtherParty,sTempAreaCode,l)==0){
	
		if(len-l>=7||sTempAreaCode[0]=='0'||
			SpecialNbr(sOtherParty+l,sStartTime)==true){
			strcpy(sRawNbr,sOtherParty+l);
			return 0;
		}
	}
	
	strcpy(sLongAreaCode,"0");
	strcat(sLongAreaCode,sTempAreaCode);
	
	if(strncmp(sAccNbr+refLen,sLongAreaCode,strlen(sLongAreaCode))==0){
		strcpy(sRawNbr,sAccNbr+refLen+strlen(sLongAreaCode));
		return 0;
	}

	strcpy(sRawNbr,sOtherParty);
	return 0;
}

int NewGetRawNbr(char sAccNbr[],char sAreaCode[],char sStartTime[],char sRawNbr[])
{
	int off=0,len,l,refLen=0;
	char *sOtherParty=sAccNbr;
	char sTempAreaCode[9],sLongAreaCode[9],sMsisdn[25],sBakNbr[25];
	struct HeadCarrStruct	*pHeadCarr=NULL;

	strcpy(sMsisdn,sAccNbr);
	if((strncmp(sAccNbr,"108",3)==0&&
		strlen(sAccNbr)==10)||
		(strncmp(sAccNbr,"201",3)==0&&
		strlen(sAccNbr)==13)||
		(strncmp(sAccNbr,"953",3)==0&&
		strlen(sAccNbr)==14)){
		strcpy(sMsisdn,"0");
		strcat(sMsisdn,sAccNbr);
	}
	sOtherParty=sMsisdn;
/*�жϱ��غ���*/
	if(SearchHeadCarr(sOtherParty,sAreaCode,sStartTime,&pHeadCarr)==FOUND){

		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_CORR)==0){
			if((strlen(sOtherParty)==8&&pHeadCarr->iLen==8)||
				strlen(sOtherParty)==7){
				strcpy(sRawNbr,sOtherParty);
				return 0;
			}
		}
	}
	
	if(SearchHeadCarr(sOtherParty,"*",sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0&&
			strncmp(pHeadCarr->sHead,"00",2)!=0){
			refLen=strlen(pHeadCarr->sHead);
			off+=strlen(pHeadCarr->sHead);
		}
	}
	sOtherParty=sMsisdn+off;
	if(SpecialNbr(sOtherParty,sStartTime)==true){
		l=strlen(sAreaCode);
		len=strlen(sOtherParty);
		if(strncmp(sOtherParty,sAreaCode,strlen(sAreaCode))==0&&
			sOtherParty[l]!='1'&&sOtherParty[l]!='9'){
			if((len-l)!=7&&(len-l)!=8){
				strcpy(sRawNbr,sOtherParty);
				return 0;
			}			
		}
		else{
			strcpy(sRawNbr,sOtherParty);
			return 0;
		}
	}
	
	strcpy(sBakNbr,sOtherParty);
	if(sOtherParty[0]=='0'){ off++;sOtherParty++;}
	if(IS_MOB_NBR(sOtherParty)&&sOtherParty[0]=='1'){
		strcpy(sRawNbr,sOtherParty);
		return 0;
	}

	strcpy(sTempAreaCode,sAreaCode);
	RegularAreaCode(sTempAreaCode);

	l=strlen(sTempAreaCode);
	len=strlen(sOtherParty);
	if(strncmp(sOtherParty,sTempAreaCode,l)==0){
	
		if(len-l>=7||sTempAreaCode[0]=='0'||
			SpecialNbr(sOtherParty+l,sStartTime)==true){
			strcpy(sRawNbr,sOtherParty+l);
			return 0;
		}
	}
	
	strcpy(sLongAreaCode,"0");
	strcat(sLongAreaCode,sTempAreaCode);
	
	if(strncmp(sMsisdn+refLen,sLongAreaCode,strlen(sLongAreaCode))==0){
		strcpy(sRawNbr,sMsisdn+refLen+strlen(sLongAreaCode));
		return 0;
	}

	strcpy(sRawNbr,sBakNbr);/*sOtherParty����ȥ��һ��0*/
	return 0;
}
struct FileControlListStruct *GetFileControlList(
	struct FileControlListStruct *ptHead, char sSplitType[2])
{
	while(ptHead!=NULL){
		if(strcmp(sSplitType,ptHead->sSplitType)==0)
			return ptHead;
		ptHead=ptHead->pNext;
	}
	return NULL;
}
void AnalyzeTemplateRule(char sTemplateRule[],int aiTemplateRule[])
{
	int iCnt,i;

	iCnt=ParseArgv(sTemplateRule,(int)(':'));
	for(i=0;i<iCnt;i++)
		aiTemplateRule[i]=atoi(ParseToken[i]);
	
	aiTemplateRule[i]=-1;
}

int InitFileControlList(char sTemplateRule[],char sSplitStr[],
	struct FileControlListStruct **pptHead)
{
	char	sSplitType[2];
	int iTemplateRuleID,aiTemplateRuleID[100];
	int i,j,l=strlen(sSplitStr);
	struct SplitRuleStruct *pTemp;
	struct FileControlListStruct *pList;
	struct	SplitRuleListStruct *pSplitRuleList;
	
	AnalyzeTemplateRule(sTemplateRule,aiTemplateRuleID);

	if(aiTemplateRuleID[0]<=0) return -1;

	*pptHead=NULL;
	
	for(i=0;i<l;i++){

		iTemplateRuleID=aiTemplateRuleID[0];
		sSplitType[0]=	sSplitStr[i];
		sSplitType[1]=	0;
		pTemp=		GetSplitRuleList(iTemplateRuleID,sSplitType);

		if((pList=(struct FileControlListStruct *)malloc(
			sizeof(struct FileControlListStruct)))==NULL) return -1;
		bzero((void*)pList,sizeof(struct FileControlListStruct));

		pList->pSplitRule=	pTemp;
		pList->iTemplateRuleID=	iTemplateRuleID;
		strcpy(pList->sSplitType,sSplitType);
		pList->pSplitRuleList=	NULL;
		pList->pHead=		NULL;

		InsertList((LIST**)pptHead,(LIST*)pList);
		j=1;
		while(aiTemplateRuleID[j]>0){

			pTemp=GetSplitRuleList(aiTemplateRuleID[j],sSplitType);
			
			if((pSplitRuleList=(struct SplitRuleListStruct *)
				malloc(sizeof(struct SplitRuleListStruct)))==NULL)
				return -1;
			bzero((void*)pSplitRuleList,sizeof(struct SplitRuleListStruct));
			pSplitRuleList->pSplitRule=pTemp;
			InsertListTail((LIST**)&(pList->pSplitRuleList),
				(LIST*)pSplitRuleList);
			j++;
		}
	}
	return 0;
}
void DestroyFileControlList(struct FileControlListStruct *ptHead)
{
	struct FileControlListStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		DestroyList((LIST*)pTemp->pSplitRuleList);
		free(pTemp);
	}
}
struct SplitRuleStruct *GetMultiSplitRule(struct FileControlListStruct *ptHead)
{

	struct SplitRuleStruct *pSplitRule,*pTemp;
	struct	SplitRuleListStruct *pSplitRuleList;

	if(ptHead==NULL) return NULL;

	pSplitRuleList=ptHead->pSplitRuleList;
	
	if((pSplitRule=GetSplitRule(ptHead->pSplitRule))==NULL) return NULL;
	
	while(pSplitRuleList!=NULL){
		if((pTemp=GetSplitRule(pSplitRuleList->pSplitRule))!=NULL)
			pSplitRule=pTemp;
		pSplitRuleList=pSplitRuleList->pNext;
	}
	return pSplitRule;
}
int mvitem2commerr(char sErrRec[],int l,int iErrCode,
	char sFileName[],char sModule[],char sAreaCode[],char sRecord[])
{
	int i;
	char	*pc,sTemp[40],sTempName[20];

	pc=sErrRec;

	strncpy(sTempName,sFileName,19);sTempName[19]=0;	
	sprintf(sTemp,"%04d%-19s%-3s%-5s",
		iErrCode,sFileName,sModule,sAreaCode);

	for(i=0;i<l;i++){
		if(pc[i]=='\n')	sRecord[i]=' ';
		else		sRecord[i]=pc[i];
	}
	memcpy((void*)(sRecord+l),(void*)sTemp,strlen(sTemp));
	l+=strlen(sTemp);
	sRecord[l++]='\n';
	sRecord[l]=0;
	return l;
}
int mvitem2err(char sErrRec[],int l,int iErrCode,char sRecord[])
{
	int i;
	char	*pc,sTemp[40];

	pc=sErrRec;
	
	sprintf(sTemp,"%04d",iErrCode);

	for(i=0;i<l;i++){
		if(pc[i]=='\n')	sRecord[i]=' ';
		else		sRecord[i]=pc[i];
	}
	memcpy((void*)(sRecord+l-sizeof(struct FErrInfoStruct)),
		(void*)sTemp,strlen(sTemp));
	sRecord[l++]='\n';
	sRecord[l]=0;
	return l;
}
int CalMainTicket(struct RateTicketStruct *p)
{
	time_t	tStartTime;
	int iRoamFee,iTollFee,iAddFee;
	struct TollTariffStruct *pTariff;
	
	tStartTime=tGetTime(p->sStartTime);

/*����ҵ������*/
	pTariff=GetTollTariffList(p->iTicketTypeID,FIELD_TYPE_DURATION);
	if(pTariff!=NULL){
		TicketTimeIntersectToTariff(tStartTime,p->iDuration,pTariff);
		DisctMain(pTariff);/*������һ�������Ż�*/
		GetCalcFee(pTariff,&p->iRoamFee,&p->iTollFee,&p->iAddFee);
	}

/*��ʱ���ֶΣ��Ʒ�*/
	iRoamFee=iTollFee=iAddFee=0;
	pTariff=GetTollTariffList(p->iTicketTypeID,FIELD_TYPE_FLOW1);
	if(pTariff!=NULL){
		TicketTimeIntersectToTariff(tStartTime,1,pTariff);
		DisctMain(pTariff);/*������һ�������Ż�*/
		GetCalcFeeRate(pTariff,p->iValue1,&iRoamFee,&iTollFee,&iAddFee);
		p->iRoamFee+=iRoamFee;p->iTollFee+=iTollFee;p->iAddFee+=iAddFee;
	}

/*��ʱ���ֶ�2�Ʒ�*/
	iRoamFee=iTollFee=iAddFee=0;
	pTariff=GetTollTariffList(p->iTicketTypeID,FIELD_TYPE_FLOW2);
	if(pTariff!=NULL){
		TicketTimeIntersectToTariff(tStartTime,1,pTariff);
		DisctMain(pTariff);/*������һ�������Ż�*/
		GetCalcFeeRate(pTariff,p->iValue2,&iRoamFee,&iTollFee,&iAddFee);
		p->iRoamFee+=iRoamFee;p->iTollFee+=iTollFee;p->iAddFee+=iAddFee;
	}
	return 0;
}
int CalMainTicketD(struct MobTicketStruct *p)
{
	int	iDuration;
	struct TollTariffStruct *pTariff;
	
	char sMscType[128];
	
	if(strcmp(p->sCallType,"07")==0||
		strcmp(p->sCallType,"08")==0) iDuration=1;
	else
		iDuration=p->iDuration;

	pTariff=GetTollTariffList(p->iTicketTypeID,FIELD_TYPE_DURATION);
	TicketTimeIntersectToTariff(p->tStartTime,iDuration,pTariff);
	
/*	DisctMain(pTariff);*//*������һ�������Ż�*/
/*	GetCalcFee(pTariff,&(p->iRoamFee),&(p->iTollFee),&(p->iAddFee));*/

	GetMscType(p->sMsc,sMscType);
	/*д���������������С����ʡ�����15���Ļ������Ż�*/
        if(strcmp(p->sSplitType,"C")==0&&
        	strcmp(p->sCallType,"01")==0&&
                p->sCalledCode[0]=='0'&&
                strstr("1,33,39,44,49,60,61,62,63,64,65,66,81,82",
                        p->sCalledCode+1)==NULL){
        	GetCalcFee(pTariff,&(p->iRoamFee),&(p->iTollFee),&(p->iAddFee));
        }
        else{
                DisctMain(pTariff);/*������һ�������Ż�*/
        	GetCalcFee(pTariff,&(p->iRoamFee),&(p->iTollFee),&(p->iAddFee));
        }
	
	return 0;
}
int CalTariffRef(char sStartTime[],int iValue,char sTariffRef[])
{
	time_t	tStartTime;
	int iRoamFee,iTollFee,iAddFee;
	struct TollTariffStruct *pTariff;

	tStartTime=tGetTime(sStartTime);
	pTariff=GetTariffRefList(sTariffRef);
	if(pTariff==NULL) return 0;

	if(strcmp(pTariff->sFieldType,FIELD_TYPE_DURATION)==0){

		TicketTimeIntersectToTariff(tStartTime,iValue,pTariff);
		DisctMain(pTariff);/*������һ�������Ż�*/
		GetCalcFee(pTariff,&iRoamFee,&iTollFee,&iAddFee);
	}
	else{
		TicketTimeIntersectToTariff(tStartTime,1,pTariff);
		DisctMain(pTariff);/*������һ�������Ż�*/
		GetCalcFeeRate(pTariff,iValue,&iRoamFee,&iTollFee,&iAddFee);
	}
	return iRoamFee+iTollFee+iAddFee;
}
int CalCommFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID,int iTariffType)
{

	time_t	tStartTime;
	int iFee,iRoamFee,iTollFee,iAddFee;
	struct TollTariffStruct *pTariff;
	
	tStartTime=tGetTime(sStartTime);

	iRoamFee=iTollFee=iAddFee=0;
	pTariff=GetTollTariffList(iTicketTypeID,sFieldType);
	if(pTariff==NULL) return 0;

	if(strcmp(sFieldType,FIELD_TYPE_DURATION)==0){/*ʱ������*/
		TicketTimeIntersectToTariff(tStartTime,iDuration,pTariff);
		DisctMain(pTariff);/*������һ�������Ż�*/
		GetCalcFee(pTariff,&iRoamFee,&iTollFee,&iAddFee);
	}
	else{/**��ʱ������*/
		TicketTimeIntersectToTariff(tStartTime,1,pTariff);
		DisctMain(pTariff);/*������һ�������Ż�*/
		GetCalcFeeRate(pTariff,iDuration,&iRoamFee,&iTollFee,&iAddFee);
	}
	if(iTariffType==1)	iFee=iRoamFee;
	else if(iTariffType==2) iFee=iTollFee;
	else 			iFee=iAddFee;
	return iFee;
}
int CalRoamFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID)
{
	return CalCommFee(sStartTime,iDuration,
		sFieldType,iTicketTypeID,01);
}
int CalTollFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID)
{
	return CalCommFee(sStartTime,iDuration,
		sFieldType,iTicketTypeID,02);
}
int CalAddFee(char sStartTime[],int iDuration,
	char sFieldType[],int iTicketTypeID)
{
	return CalCommFee(sStartTime,iDuration,
		sFieldType,iTicketTypeID,03);
}


int GetBinInt (char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],int *piIntVal)
{
	struct ICommSearchStruct *pTemp;
	
	*piIntVal=0;
	
	if(SearchCommBin(sTableName,iIntKey,sStrKey,sStartTime,&pTemp)
		==FOUND){
		*piIntVal=pTemp->iIntVal;
		return FOUND;
	}
	return NOTFOUND;
}
int GetBinStr (char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],char sStrVal[])
{
	struct ICommSearchStruct *pTemp;
	
	strcpy(sStrVal,"");
	
	if(SearchCommBin(sTableName,iIntKey,sStrKey,sStartTime,&pTemp)
		==FOUND){
		GetStrValFromCS(pTemp,sStrVal);
		return FOUND;
	}
	return NOTFOUND;
}
int GetTrieInt(char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],int *piIntVal)
{
	struct ICommSearchStruct *pTemp;
	
	*piIntVal=0;
	
	if(SearchCommTrie(sTableName,iIntKey,sStrKey,sStartTime,&pTemp)
		==FOUND){
		*piIntVal=pTemp->iIntVal;
		return FOUND;
	}
	return NOTFOUND;
}
int GetTrieStr(char sTableName[],int iIntKey,char sStrKey[],char sStartTime[],char sStrVal[])
{
	struct ICommSearchStruct *pTemp;
	
	strcpy(sStrVal,"");
	
	if(SearchCommTrie(sTableName,iIntKey,sStrKey,sStartTime,&pTemp)
		==FOUND){
		GetStrValFromCS(pTemp,sStrVal);
		return FOUND;
	}
	return NOTFOUND;
}
int GetRangeInt(char sTableName[],char sKey[],char sStartTime[],int *piIntVal)
{
	struct CommRangeStruct *pTemp;
	
	*piIntVal=0;
	
	if(SearchCommRange(sTableName,sKey,sStartTime,&pTemp)==FOUND){
		*piIntVal=pTemp->iIntVal;
		return FOUND;
	}
	return NOTFOUND;
}
int GetRangeStr(char sTableName[],char sKey[],char sStartTime[],char sStrVal[])
{
	struct CommRangeStruct *pTemp;
	
	strcpy(sStrVal,"");
	
	if(SearchCommRange(sTableName,sKey,sStartTime,&pTemp)==FOUND){
		strcpy(sStrVal,pTemp->sStrVal);
		return FOUND;
	}
	return NOTFOUND;
}
int i_getbelongcode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetBelongCode(p1,p2,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getcitycode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetCityCode(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getareatype(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetAreaType(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getareaiptype(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetAreaIpType(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getareatolltype1(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetAreaTollType1(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getareatolltype2(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetAreaTollType2(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getareacountyflag(int d1,int r)
{
	char sTemp[128];
	int   i1=GetIntVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetAreaCountyFlag(i1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getcapitalcode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetCapitalCode(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getcountrycode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetCountryCode(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getareacode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetAreaCode(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_gettrunktype(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetTrunkType(p1,p2,p3,p4,(int*)pr);
	
	return 0;
}
int i_gettrunkarea(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
		
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetTrunkArea(p1,p2,p3,p4,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_gettrunkcarrier(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetTrunkCarrier(p1,p2,p3,p4,(int*)pr);
	
	return 0;
}
int i_getheadtypeid(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetHeadTypeID(p1,p2,p3,p4,(int*)pr);
	
	return 0;
}
int i_getheadtype(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
		
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetHeadType(p1,p2,p3,p4,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getheadcarr(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetHeadCarr(p1,p2,p3,p4,(int*)pr);
	
	return 0;
}
int i_getheadarea(int d1,int r)
{

	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetHeadArea(p1,p2,p3,p4,(int*)pr);

	return 0;
}
int i_getimsiarea(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetImsiArea(p1,p2,p3,sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getmscarea(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetMscArea(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getmsctype(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetMscType(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getlaccellarea(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetLacCellArea(p1,p2,p3,p4,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getacrosscal(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	char *p5=GetStrVariant(CODE_VARBUF,d1+4);
	char *p6=GetStrVariant(CODE_VARBUF,d1+5);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetAcrossCal(p1,p2,p3,p4,p5,p6,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getsamecal(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	char *p5=GetStrVariant(CODE_VARBUF,d1+4);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetSameCal(p1,p2,p3,p4,p5,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getvisitareacode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	char *p5=GetStrVariant(CODE_VARBUF,d1+4);
	char *p6=GetStrVariant(CODE_VARBUF,d1+5);
	char *p7=GetStrVariant(CODE_VARBUF,d1+6);
	int  i=GetIntVariant(CODE_VARBUF,d1+7);
		
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetVisitAreaCode(p1,p2,p3,p4,p5,p6,p7,i,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_gethomeareacode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	int  j,i=GetIntVariant(CODE_VARBUF,d1+3);
	char *p5=GetStrVariant(CODE_VARBUF,d1+4);
	
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetHomeAreaCode(p1,p2,p3,i,p5,&j,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getcalledareacode(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	int  j;
		
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetCalledAreaCode(p1,p2,p3,p4,&j,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_getrawnbr(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	

	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetRawNbr(p1,p2,p3,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_bindratepos(int d1,int r)
{
	
	bzero((void*)&RatePos,sizeof(struct RatePositionStruct));
	
	RatePos.iStartTimePos=CODE_VARBUF[d1].iParam;
	RatePos.iDurationPos=	CODE_VARBUF[d1+1].iParam;
	RatePos.iValue1Pos=	CODE_VARBUF[d1+2].iParam;
	RatePos.iValue2Pos=	CODE_VARBUF[d1+3].iParam;

	RatePos.iTicketTypeIDPos=CODE_VARBUF[d1+4].iParam;
	RatePos.iRoamFeePos=	CODE_VARBUF[d1+5].iParam;
	RatePos.iTollFeePos=	CODE_VARBUF[d1+6].iParam;
	RatePos.iAddFeePos=	CODE_VARBUF[d1+7].iParam;
	
	CODE_VARBUF[r].cType=VARTYPE_INT;

	return 0;
}
int i_getbinint(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int   i2=GetIntVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetBinInt(p1,i2,p3,p4,(int*)pr);
	
	return 0;
}
int i_getbinstr(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int   i2=GetIntVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
		
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetBinStr(p1,i2,p3,p4,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_gettrieint(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int   i2=GetIntVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetTrieInt(p1,i2,p3,p4,(int*)pr);
	
	return 0;
}
int i_gettriestr(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int   i2=GetIntVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
		
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetTrieStr(p1,i2,p3,p4,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}


int i_getrangeint(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	
	char *pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	GetRangeInt(p1,p2,p3,(int*)pr);
	
	return 0;
}
int i_getrangestr(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
		
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetRangeStr(p1,p2,p3,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_calfixfee(int d1,int r)/*RATE_TYPE==00*/
{
	
	int   iValue=GetIntVariant(CODE_VARBUF,d1);
	int   iUnit=GetIntVariant(CODE_VARBUF,d1+1);
	int   iRate=GetIntVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=(iValue+iUnit-1)/iUnit*iRate;
	
	return 0;
}

int i_callatnfee(int d1,int r)/**RATE_TYPE=01*/
{
	
	int   iValue=GetIntVariant(CODE_VARBUF,d1);
	int   iUnit=GetIntVariant(CODE_VARBUF,d1+1);
	int   iRate=GetIntVariant(CODE_VARBUF,d1+2);
	int   iParam1=GetIntVariant(CODE_VARBUF,d1+3);/*ǰn���ӣ��룩*/
	int   iParam2=GetIntVariant(CODE_VARBUF,d1+4);/*ǰn���Ӷ���Ǯ���壩*/


	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=iParam2;
	if(iValue>iParam1)
		CODE_VARBUF[r].u.iValue+=(iValue-iParam1+iUnit-1)/iUnit*iRate;
	return 0;
}
int i_calmainticket(int d1,int r)
{
	char *sStartTime=GetStrVariant(CODE_VARBUF,d1);
	int   iDuration=GetIntVariant(CODE_VARBUF,d1+1);
	int   iValue1=GetIntVariant(CODE_VARBUF,d1+2);
	int   iValue2=GetIntVariant(CODE_VARBUF,d1+3);
	int   iTicketTypeID=GetIntVariant(CODE_VARBUF,d1+4);
	
	struct RateTicketStruct Temp;
	
	
	strcpy(Temp.sStartTime,	sStartTime);
	Temp.iDuration=	iDuration;
	Temp.iValue1=	iValue1;
	Temp.iValue2=	iValue2;
	Temp.iTicketTypeID=	iTicketTypeID;

	CalMainTicket(&Temp);
	
	CODE_VARBUF[r].cType=VARTYPE_STRUCT;
	
	return AssignMemchar2Varchar(&(CODE_VARBUF[r].u.sValue),(char*)&Temp,
		sizeof(struct RateTicketStruct));
}
int i_gettickettypeid(int d1,int r)
{
	char *sSplitType=GetStrVariant(CODE_VARBUF,d1);
	
	struct FileControlListStruct *pList;
	struct SplitRuleStruct *pSplitRule=NULL;

	GetSysVar(pExprBuf,false);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=-1;
	
	pList=GetFileControlList(pFileControlList,sSplitType);
	if((pSplitRule=GetMultiSplitRule(pList))!=NULL)
		CODE_VARBUF[r].u.iValue=pSplitRule->iTicketTypeID;
	return 0;
}
int i_getsplitruleid(int d1,int r)
{
	char *sSplitType=GetStrVariant(CODE_VARBUF,d1);
	
	struct FileControlListStruct *pList;
	struct SplitRuleStruct *pSplitRule=NULL;

	GetSysVar(pExprBuf,false);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=-1;
	
	pList=GetFileControlList(pFileControlList,sSplitType);
	if((pSplitRule=GetMultiSplitRule(pList))!=NULL)
		CODE_VARBUF[r].u.iValue=pSplitRule->iSplitRuleID;
	return 0;
}

int i_getroamfee(int d1,int r)
{
	struct RateTicketStruct *p;
	
	p=(struct RateTicketStruct*)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=p->iRoamFee;
	return 0;
}
int i_gettollfee(int d1,int r)
{
	struct RateTicketStruct *p;
	
	p=(struct RateTicketStruct*)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=p->iTollFee;
	return 0;
}

int i_getaddfee(int d1,int r)
{
	struct RateTicketStruct *p;
	
	p=(struct RateTicketStruct*)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=p->iAddFee;
	return 0;
}
int i_caltariffref(int d1,int r)
{
	char *sStartTime=GetStrVariant(CODE_VARBUF,d1);
	int   iValue=GetIntVariant(CODE_VARBUF,d1+1);
	char *sTariffRef=GetStrVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=CalTariffRef(sStartTime,
		iValue,sTariffRef);
	return 0;
}
int i_calroamfee(int d1,int r)
{
	char *sStartTime=GetStrVariant(CODE_VARBUF,d1);
	int   iDuration=GetIntVariant(CODE_VARBUF,d1+1);
	char *sFieldType=GetStrVariant(CODE_VARBUF,d1+2);
	int   iTicketTypeID=GetIntVariant(CODE_VARBUF,d1+3);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=CalRoamFee(sStartTime,iDuration,
		sFieldType,iTicketTypeID);
	return 0;
}
int i_caltollfee(int d1,int r)
{
	char *sStartTime=GetStrVariant(CODE_VARBUF,d1);
	int   iDuration=GetIntVariant(CODE_VARBUF,d1+1);
	char *sFieldType=GetStrVariant(CODE_VARBUF,d1+2);
	int   iTicketTypeID=GetIntVariant(CODE_VARBUF,d1+3);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=CalTollFee(sStartTime,iDuration,
		sFieldType,iTicketTypeID);
	return 0;
}
int i_caladdfee(int d1,int r)
{
	char *sStartTime=GetStrVariant(CODE_VARBUF,d1);
	int   iDuration=GetIntVariant(CODE_VARBUF,d1+1);
	char *sFieldType=GetStrVariant(CODE_VARBUF,d1+2);
	int   iTicketTypeID=GetIntVariant(CODE_VARBUF,d1+3);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=CalAddFee(sStartTime,iDuration,
		sFieldType,iTicketTypeID);
	return 0;
}
/*�ж��ƶ���������*/
int i_ismobnbr(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IS_MOB_NBR(p1))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}
int i_ismobimsi(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IS_MOB_IMSI(p1))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}
int i_ismobilegsm(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IS_MOBILE_GSM(p1))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}
int i_isunicomgsm(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IS_UNICOM_GSM(p1))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}
int i_isunicomcdma(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IS_UNICOM_CDMA(p1))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}

int i_isunicomwcdma(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IS_UNICOM_WCDMA(p1))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}
int i_ismobiletd(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IS_MOBILE_TD(p1))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}

int i_isdpaccnbrx(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IsDpAccNbrX(p1,p2))	
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}


void RegRateExprFun()
{
RegFunItem("getbelongcode",	i_getbelongcode,	"22",'2','f');
RegFunItem("getcitycode",	i_getcitycode,		"2",'2','f');
RegFunItem("getareacode",	i_getareacode,		"2",'2','f');
RegFunItem("gettrunktype",	i_gettrunktype,		"2222",'1','f');
RegFunItem("gettrunkarea",	i_gettrunkarea,		"2222",'2','f');
RegFunItem("gettrunkcarrier",	i_gettrunkcarrier,	"2222",'1','f');
RegFunItem("gettrunkcarr",	i_gettrunkcarrier,	"2222",'1','f');
RegFunItem("getheadtypeid",	i_getheadtypeid,	"2222",'1','f');
RegFunItem("getheadtype",	i_getheadtype,		"2222",'2','f');
RegFunItem("getheadcarrier",	i_getheadcarr,		"2222",'1','f');
RegFunItem("getheadcarr",	i_getheadcarr,		"2222",'1','f');
RegFunItem("getheadarea",	i_getheadarea,		"2222",'1','f');
RegFunItem("getimsiarea",	i_getimsiarea,		"222",'2','f');
RegFunItem("getmscarea",	i_getmscarea,		"2",'2','f');
RegFunItem("getmsctype",	i_getmsctype,		"2",'2','f');
RegFunItem("getlaccellarea",	i_getlaccellarea,	"2222",'2','f');
RegFunItem("getacrosscal",	i_getacrosscal,		"222222",'2','f');
RegFunItem("getsamecal",	i_getsamecal,		"22222",'2','f');
RegFunItem("getvisitareacode",	i_getvisitareacode,	"22222221",'2','f');
RegFunItem("gethomeareacode",	i_gethomeareacode,	"22212",'2','f');
RegFunItem("getcalledareacode",	i_getcalledareacode,	"2222",'2','f');
RegFunItem("getrawnbr",		i_getrawnbr,		"222",'2','f');
RegFunItem("bindratepos",	i_bindratepos,		"21111111",'1','F');

RegFunItem("getbinint",		i_getbinint,		"2122",'1','f');
RegFunItem("getbinstr",		i_getbinstr,		"2122",'2','f');
RegFunItem("gettrieint",	i_gettrieint,		"2122",'1','f');
RegFunItem("gettriestr",	i_gettriestr,		"2122",'2','f');
/*2009.07.08,���ǵ��������еĹ�ʽ�����أ�����ע����4������*/
RegFunItem("getlbinint",	i_getbinint,		"2122",'1','f');
RegFunItem("getlbinstr",	i_getbinstr,		"2122",'2','f');
RegFunItem("getltrieint",	i_gettrieint,		"2122",'1','f');
RegFunItem("getltriestr",	i_gettriestr,		"2122",'2','f');

RegFunItem("getrangeint",	i_getrangeint,		"222",'1','f');
RegFunItem("getrangestr",	i_getrangestr,		"222",'2','f');

RegFunItem("getareatype",	i_getareatype,		"2",'2','f');
RegFunItem("getcountrycode",	i_getcountrycode,	"2",'2','f');
RegFunItem("getcapitalcode",	i_getcapitalcode,	"2",'2','f');

RegFunItem("getareaiptype",	i_getareaiptype,	"2",'2','f');
RegFunItem("getareatolltype1",	i_getareatolltype1,	"2",'2','f');
RegFunItem("getareatolltype2",	i_getareatolltype2,	"2",'2','f');
RegFunItem("getareacountyflag",	i_getareacountyflag,	"1",'2','f');

RegFunItem("calfixfee",		i_calfixfee,		"111",'1','f');
RegFunItem("callatnfee",	i_callatnfee,		"11111",'1','f');

RegFunItem("calmainticket",	i_calmainticket,	"21111",'4','f');
RegFunItem("gettickettype",	i_gettickettypeid,	"2",'1','f');
RegFunItem("gettickettypeid",	i_gettickettypeid,	"2",'1','f');
RegFunItem("getsplitruleid",	i_getsplitruleid,	"2",'1','f');
RegFunItem("getroamfee",	i_getroamfee,		"4",'1','f');
RegFunItem("gettollfee",	i_gettollfee,		"4",'1','f');
RegFunItem("getaddfee",		i_getaddfee,		"4",'1','f');
RegFunItem("caltariffref",	i_caltariffref,		"212",'1','f');
RegFunItem("calbasefee",	i_calroamfee,		"2121",'1','f');
RegFunItem("calroamfee",	i_calroamfee,		"2121",'1','f');
RegFunItem("caltollfee",	i_caltollfee,		"2121",'1','f');
RegFunItem("caladdfee",		i_caladdfee,		"2121",'1','f');

RegFunItem("ismobnbr"		,i_ismobnbr	,"2",'1','f');
RegFunItem("ismobimsi"		,i_ismobimsi  	,"2",'1','f');
RegFunItem("ismobilegsm"	,i_ismobilegsm	,"2",'1','f');
RegFunItem("isunicomgsm"	,i_isunicomgsm	,"2",'1','f');
RegFunItem("isunicomcdma"	,i_isunicomcdma	,"2",'1','f');
RegFunItem("ismobiletd"		,i_ismobiletd	,"2",'1','f');
RegFunItem("isunicomwcdma"	,i_isunicomwcdma,"2",'1','f');
RegFunItem("isdpaccnbrx"	,i_isdpaccnbrx,"22",'1','f');
}

/****ֻ������,
f.call_type
f.imsi
f.msisdn
f.other_party
f.third_party
f.raw_other_party
f.start_time
f.duration
f.msc
f.lac
f.cell_id
f.other_lac
f.other_cell_id
f.service_type
f.service_code
=======================
	�ɶ���д����..
f.roam_type
f.distance_type
f.opp_type
f.opp_roam_type
f.user_type
f.ip_type
f.toll_type1
f.toll_type2
f.cal
f.called_code
f.visit_area_code
f.home_area_code
f.trunk_in
f.trunk_out
****************/
void get_call_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sCallType);
}
void get_imsi(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sImsi);
}
void get_msisdn(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sMsisdn);
}
void get_raw_msisdn(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sRawMsisdn);
}
void get_other_party(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sOtherParty);
}
void get_third_party(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sThirdParty);
}
void get_raw_other_party(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sRawOtherParty);
}
void get_start_time(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sStartTime);
}
void get_duration(int iParam,void *p)
{
	(*(int*)p)=pTicketField->iDuration;
}
void get_msc(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sMsc);
}
void get_lac(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sLac);
}
void get_cell_id(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sCellID);
}
void get_other_lac(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sOtherLac);
}
void get_other_cell_id(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sOtherCellID);
}
void get_service_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sServiceType);
}
void get_service_code(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sServiceCode);
}

/*�������*/
void get_roam_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sRoamType);
}
void get_distance_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sDistanceType);
}
void get_opp_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sOppType);
}
void get_opp_roam_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sOppRoamType);
}
void get_user_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sUserType);
}
void get_ip_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sIpType);
}
void get_toll_type1(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sTollType1);
}
void get_toll_type2(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sTollType2);
}
void get_called_code(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sCalledCode);
}
void get_cal(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sCal);
}
void get_visit_area_code(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sVisitAreaCode);
}
void get_home_area_code(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sHomeAreaCode);
}
void get_trunk_in(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sTrunkIn);
}
void get_trunk_out(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sTrunkOut);
}
void get_x_roam_fee(int iParam,void *p)
{
	(*(int*)p)=0;
}
void get_x_roam_valid(int iParam,void *p)
{
	(*(int*)p)=0;
}
void get_x_toll_fee(int iParam,void *p)
{
	(*(int*)p)=0;
}
void get_x_toll_valid(int iParam,void *p)
{
	(*(int*)p)=0;
}
void get_x_add_fee(int iParam,void *p)
{
	(*(int*)p)=0;
}
void get_x_add_valid(int iParam,void *p)
{
	(*(int*)p)=0;
}
void get_scp_flag(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sScpFlag);
}
void get_deform_flag(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sDeformFlag);
}
void get_roam_tariff_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sRoamTariffType);
}
void get_toll_tariff_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sTollTariffType);
}
void get_add_tariff_type(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,pTicketField->sAddTariffType);
}

/**�������***/
void put_roam_type(int iParam,void *p)
{
	strncpy(pTicketField->sRoamType,GetVarcharData(*(char **)p),1);
}
void put_distance_type(int iParam,void *p)
{
	strncpy(pTicketField->sDistanceType,GetVarcharData(*(char **)p),1);
}
void put_opp_type(int iParam,void *p)
{
	strncpy(pTicketField->sOppType,GetVarcharData(*(char **)p),1);
}
void put_opp_roam_type(int iParam,void *p)
{
	strncpy(pTicketField->sOppRoamType,GetVarcharData(*(char **)p),1);
}
void put_user_type(int iParam,void *p)
{
	strncpy(pTicketField->sUserType,GetVarcharData(*(char **)p),1);
}
void put_ip_type(int iParam,void *p)
{
	strncpy(pTicketField->sIpType,GetVarcharData(*(char **)p),1);
}
void put_toll_type1(int iParam,void *p)
{
	strncpy(pTicketField->sTollType1,GetVarcharData(*(char **)p),1);
}
void put_toll_type2(int iParam,void *p)
{
	strncpy(pTicketField->sTollType2,GetVarcharData(*(char **)p),1);
}
void put_cal(int iParam,void *p)
{
	strncpy(pTicketField->sCal,GetVarcharData(*(char **)p),1);
}
void put_called_code(int iParam,void *p)
{
	strncpy(pTicketField->sCalledCode,GetVarcharData(*(char **)p),5);
}
void put_visit_area_code(int iParam,void *p)
{
	strncpy(pTicketField->sVisitAreaCode,GetVarcharData(*(char **)p),5);
}
void put_home_area_code(int iParam,void *p)
{
	strncpy(pTicketField->sHomeAreaCode,GetVarcharData(*(char **)p),5);
}
void put_trunk_in(int iParam,void *p)
{
	strncpy(pTicketField->sTrunkIn,GetVarcharData(*(char **)p),7);
}
void put_trunk_out(int iParam,void *p)
{
	strncpy(pTicketField->sTrunkOut,GetVarcharData(*(char **)p),7);
}
void put_x_roam_fee(int iParam,void *p)
{
	pTicketField->x.iRoamFee=(*(int*)p);
}
void put_x_roam_valid(int iParam,void *p)
{
	pTicketField->x.iRoamValid=(*(int*)p);
}
void put_x_toll_fee(int iParam,void *p)
{
	pTicketField->x.iTollFee=(*(int*)p);
}
void put_x_toll_valid(int iParam,void *p)
{
	pTicketField->x.iTollValid=(*(int*)p);
}
void put_x_add_fee(int iParam,void *p)
{
	pTicketField->x.iAddFee=(*(int*)p);
}
void put_x_add_valid(int iParam,void *p)
{
	pTicketField->x.iAddValid=(*(int*)p);
}
void put_roam_tariff_type(int iParam,void *p)
{
	strncpy(pTicketField->sRoamTariffType,GetVarcharData(*(char **)p),3);
}
void put_toll_tariff_type(int iParam,void *p)
{
	strncpy(pTicketField->sTollTariffType,GetVarcharData(*(char **)p),3);
}
void put_add_tariff_type(int iParam,void *p)
{
	strncpy(pTicketField->sAddTariffType,GetVarcharData(*(char **)p),3);
}

void get_ticket_type_id(int iParam,void *p)
{
	(*(int*)p)=pTicketField->iTicketTypeID;
}
void put_ticket_type_id(int iParam,void *p)
{
	pTicketField->iTicketTypeID=(*(int*)p);
}
void get_split_rule_id(int iParam,void *p)
{
	(*(int*)p)=pTicketField->iSplitRuleID;
}
void put_split_rule_id(int iParam,void *p)
{
	pTicketField->iSplitRuleID=(*(int*)p);
}

void RegModiVar()
{
RegVarItem(get_call_type,	NULL, VARTYPE_STR,'f',"f.call_type");
RegVarItem(get_imsi, 		NULL, VARTYPE_STR,'f',"f.imsi");
RegVarItem(get_msisdn, 		NULL, VARTYPE_STR,'f',"f.msisdn");
RegVarItem(get_raw_msisdn, 	NULL, VARTYPE_STR,'f',"f.raw_msisdn");
RegVarItem(get_other_party,	NULL, VARTYPE_STR,'f',"f.other_party");
RegVarItem(get_third_party,	NULL, VARTYPE_STR,'f',"f.third_party");
RegVarItem(get_raw_other_party, NULL, VARTYPE_STR,'f',"f.raw_other_party");
RegVarItem(get_start_time,	NULL, VARTYPE_STR,'f',"f.start_time");
RegVarItem(get_duration,	NULL, VARTYPE_INT,'f',"f.duration");
RegVarItem(get_msc,		NULL, VARTYPE_STR,'f',"f.msc");
RegVarItem(get_lac,		NULL, VARTYPE_STR,'f',"f.lac");
RegVarItem(get_cell_id,		NULL, VARTYPE_STR,'f',"f.cell_id");
RegVarItem(get_other_lac,	NULL, VARTYPE_STR,'f',"f.other_lac");
RegVarItem(get_other_cell_id,	NULL, VARTYPE_STR,'f',"f.other_cell_id");
RegVarItem(get_service_type,	NULL, VARTYPE_STR,'f',"f.service_type");
RegVarItem(get_service_code,	NULL, VARTYPE_STR,'f',"f.service_code");
/*20060324�����������ֶ�*/
RegVarItem(get_scp_flag,	NULL, VARTYPE_STR,'f',"f.scp_flag");
RegVarItem(get_deform_flag,	NULL, VARTYPE_STR,'f',"f.deform_flag");

RegVarItem(get_roam_type,	put_roam_type,		VARTYPE_STR,'f',"f.roam_type");
RegVarItem(get_distance_type,	put_distance_type,	VARTYPE_STR,'f',"f.distance_type");
RegVarItem(get_opp_type,	put_opp_type,		VARTYPE_STR,'f',"f.opp_type");
RegVarItem(get_opp_roam_type,	put_opp_roam_type,	VARTYPE_STR,'f',"f.opp_roam_type");
RegVarItem(get_user_type,	put_user_type,		VARTYPE_STR,'f',"f.user_type");
RegVarItem(get_ip_type,		put_ip_type,		VARTYPE_STR,'f',"f.ip_type");
RegVarItem(get_toll_type1,	put_toll_type1,		VARTYPE_STR,'f',"f.toll_type1");
RegVarItem(get_toll_type2,	put_toll_type2,		VARTYPE_STR,'f',"f.toll_type2");
RegVarItem(get_cal,		put_cal,		VARTYPE_STR,'f',"f.cal");
RegVarItem(get_called_code,	put_called_code,	VARTYPE_STR,'f',"f.called_code");
RegVarItem(get_visit_area_code,	put_visit_area_code,	VARTYPE_STR,'f',"f.visit_area_code");
RegVarItem(get_home_area_code,	put_home_area_code,	VARTYPE_STR,'f',"f.home_area_code");
RegVarItem(get_trunk_in,	put_trunk_in,		VARTYPE_STR,'f',"f.trunk_in");
RegVarItem(get_trunk_out,	put_trunk_out,		VARTYPE_STR,'f',"f.trunk_out");

RegVarItem(get_x_roam_fee,	put_x_roam_fee,		VARTYPE_INT,'f',"f.x_roam_fee");
RegVarItem(get_x_roam_valid,	put_x_roam_valid,	VARTYPE_INT,'f',"f.x_roam_valid");
RegVarItem(get_x_toll_fee,	put_x_toll_fee,		VARTYPE_INT,'f',"f.x_toll_fee");
RegVarItem(get_x_toll_valid,	put_x_toll_valid,	VARTYPE_INT,'f',"f.x_toll_valid");
RegVarItem(get_x_add_fee,	put_x_add_fee,		VARTYPE_INT,'f',"f.x_add_fee");
RegVarItem(get_x_add_valid,	put_x_add_valid,	VARTYPE_INT,'f',"f.x_add_valid");

RegVarItem(get_roam_tariff_type,put_roam_tariff_type,	VARTYPE_STR,'f',"f.roam_tariff_type");
RegVarItem(get_toll_tariff_type,put_toll_tariff_type,	VARTYPE_STR,'f',"f.toll_tariff_type");
RegVarItem(get_add_tariff_type, put_add_tariff_type,	VARTYPE_STR,'f',"f.add_tariff_type");

RegVarItem(get_ticket_type_id,	put_ticket_type_id,VARTYPE_INT,'f',"f.ticket_type_id");
RegVarItem(get_split_rule_id,	put_split_rule_id,VARTYPE_INT,'f',"f.split_rule_id");

}

void GetBillExpr(char sTemplateStr[],int iFlag,char sExprName[])
{
	char sPath[256],sTemp[256];

	GetBillHome(sPath);
	
	strcpy(sTemp,sTemplateStr);
	Replace(sTemp,':','_');

	if(iFlag==true)	
		sprintf(sExprName,"%sexpr/template_%s.bil.expr",sPath,sTemp);
	else		
		sprintf(sExprName,"%sexpr/template_%s.stt.expr",sPath,sTemp);
}
int MyReadExprFileToBuf(char sFileName[],int iMaxLen,char sInput[],
	char msg[])
{
	int l;
	FILE *fp;
	
	strcpy(msg,"");
	
	if(IsFile(sFileName)==FALSE) return 1;

	if((l=FileSize(sFileName))>=iMaxLen){
		sprintf(msg,"�ļ�%s����%d�ֽ�",sFileName,iMaxLen);
		return -1;
	}
	if((fp=fopen(sFileName,"r"))==NULL){
		sprintf(msg,"���ļ�%sʧ��",sFileName);
		return -1;
	}
	if(fread(sInput,l,1,fp)!=1){
		sprintf(msg,"���ļ�%sʧ��",sFileName);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);
	return 0;
}
int SearchFileControlOut(struct FileControlOutStruct *ptHead,char sSuffix[2],
	struct FileControlOutStruct **pptCur)
{
	*pptCur=NULL;

	while(ptHead!=NULL){
		if(strcmp(sSuffix,ptHead->sSuffix)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
static int Item2OutListSupp(struct FileControlOutStruct **pptHead,char sStr[],
	char sRecord[],int l,char sSplitNew[],char sMsg[])
{
	char sSuffix[2];
	int i,len,iCnt=0;
	struct FileControlOutStruct *pTemp=NULL;

	strcpy(sMsg,"");

	len=strlen(sStr);
	for(i=0;i<len;i++){
		sSuffix[0]=sStr[i];sSuffix[1]=0;
		if(SearchFileControlOut(*pptHead,sSuffix,&pTemp)==NOTFOUND){
			if((pTemp=malloc(sizeof(struct FileControlOutStruct)))==NULL){
				sprintf(sMsg,"����  FileControlOut ����");
				return -1;
			}
			strcpy(pTemp->sSuffix,sSuffix);
			pTemp->iCnt=0;
			pTemp->pNext=NULL;
			pTemp->pHead=NULL;
			InsertListTail((LIST**)pptHead,(LIST*)pTemp);
		}
		pTemp->iCnt++;iCnt++;
		if(item2list(&(pTemp->pHead),sRecord,l)<0){
			sprintf(sMsg,"�������������������");
			return -1;
		}
		if(strstr(sSplitNew,sSuffix)==NULL) strcat(sSplitNew,sSuffix);
	}
	return iCnt;
}
int Item2OutList(struct FileControlOutStruct **pptHead,char sSplitType[],
	char sRecord[],int l,char sSplitNew[],char sMsg[])
{
	char sSuffixUse[21];

	strcpy(sSuffixUse,sSplitType);
	
	if(strlen(SUFFIX_STR)!=0)
		strcpy(sSuffixUse,SUFFIX_STR);

	return Item2OutListSupp(pptHead,sSuffixUse,sRecord,l,sSplitNew,sMsg);
}
int Item2OutListX(struct FileControlOutStruct **pptHead,char sStr[],
	char sRecord[],int l,char sSplitNew[],char sMsg[])
{
	return Item2OutListSupp(pptHead,sStr,sRecord,l,sSplitNew,sMsg);
}
int OutItem2File(struct FileControlOutStruct *pTemp,char sNormalDir[],
	char sRawName[])
{
	char sNormalName[256];

	ReverseList((LIST**)&(pTemp->pHead));

	sprintf(sNormalName,"%s%s.%s.tmp",sNormalDir,sRawName,pTemp->sSuffix);
	if(list2file(&(pTemp->pHead),sNormalName)<0){
		printf("д���������ļ�%sʧ��.\n",sNormalName);
		return -1;
	}
	return 0;
}
int OutList2File(struct FileControlOutStruct *pList,char sNormalDir[],
	char sRawName[],char sSplitStr[])
{
	struct FileControlOutStruct *ptHead,*pTemp;
/*�������һ�����*/
	ptHead=pList;
		
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(OutItem2File(pTemp,sNormalDir,sRawName)<0) return -1;

		if(strchr(sSplitStr,pTemp->sSuffix[0])==NULL)
			strcat(sSplitStr,pTemp->sSuffix);
		free(pTemp);
	}
	return 0;
}
/*��һ��FileControlOut�ӵ�����һ��FileControlOut����*/
void AddItem2OutList(struct FileControlOutStruct **pptHead,
	struct FileControlOutStruct *ptHead)
{
	struct FileControlOutStruct *pTemp,*p=NULL;
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		/*��������ģ����Ҫ���ͬ���Ķ���,��ӵ�һ��*/
		if(SearchFileControlOut(*pptHead,pTemp->sSuffix,&p)==FOUND){
			AppendListTail((LIST**)&p->pHead,(LIST*)pTemp->pHead);
			free(pTemp);
		}
		else	InsertListTail((LIST**)pptHead,(LIST*)pTemp);
	}		
}
/*��CtlListת��ΪOutList*/
void CVCtlList2OutList(struct FileControlListStruct *pList,
	struct FileControlOutStruct **pptHead)
{
	struct FileControlOutStruct *ptLkHead=NULL;
	struct FileControlListStruct *ptHead,*pTemp;

	ptHead=pList;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(pTemp->iCnt!=0) AddItem2OutList(&ptLkHead,pTemp->pHead);

	}
	*pptHead=ptLkHead;
}
int SearchCompileBuf(struct CompileResultStruct *ptHead,char sExprName[256],
	struct CompileResultStruct **pptCur)
{
	while(ptHead!=NULL){
		if(strcmp(sExprName,ptHead->sExprName)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
int GetCompileBuf(struct CompileResultStruct **pptHead,
	char sExprName[256],char msg[],struct ExprBufStruct **pptCur)
{
	int i,l;
	char sInput[EXPRLEN];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	struct CompileResultStruct *pTemp=NULL;

	*pptCur=NULL;

	if(SearchCompileBuf(*pptHead,sExprName,&pTemp)==NOTFOUND){

		if((pTemp=(struct CompileResultStruct *)malloc(
			sizeof(struct CompileResultStruct)))==NULL){
			sprintf(msg,"�����ڴ�ʧ��");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct CompileResultStruct));
		strcpy(pTemp->sExprName,sExprName);
		InsertList((LIST**)pptHead,(LIST*)pTemp);

		if((i=MyReadExprFileToBuf(sExprName,EXPRLEN,
			sInput,msg))!=0) return i;

		RegPrepVar();
		RegRateExprFun();
		CheckSysVar=CheckPrepVar;
		RegModiVar();
		
		if((i=CompileExpr(sInput,asVarOutput,&l))<0){
			
			sprintf(msg,"���빫ʽ%s����::\n%s",
				sExprName,pExprBuf->sErrorMsg);
			return -1;
		}
		if((pTemp->pBuf=GetCompileResult())==NULL){
			sprintf(msg,"��ȡ������ʧ��");
			return -1;
		}
	}
	*pptCur=pTemp->pBuf;
	return 0;
}

int ModifyTicket(char sTemplateStr[],int f,char sModule[],
	char sSplitType[],char msg[])
{
	int i;
	char	sExprName[256],sTemp[256];
	static struct CompileResultStruct *ptHead=NULL;
	static struct ExprBufStruct *pBuf=NULL;
	
	strcpy(SUFFIX_STR,"");
	strcpy(msg,"");

	GetBillExpr(sTemplateStr,f,sExprName);
	
	if((i=GetCompileBuf(&ptHead,sExprName,msg,&pBuf))!=0) return i;
	
	if(pBuf==NULL) return 1;
	
	set_str_value("$SPLITTYPE",pBuf,sSplitType);
	set_str_value("$MODULE",pBuf,sModule);

	if(ExecCode(pBuf)<0){
		sprintf(msg,"ִ�й�ʽ%sʧ��",sExprName);
		return -1;
	}
	get_str_value("$SUFFIXSTR",pBuf,sTemp);
	GetFixStrX(sTemp,0,20,SUFFIX_STR);
		
	return 0;
}
void ModifyTicketFee(char sTemplateRule[],int f,char sModule[],
	char sSplitType[],struct MobTicketStruct *p)
{
	int i=0;
	char msg[1024];
char *asAnti="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	strcpy(p->sBillMode,"000");

	p->x.iRoamValid=p->x.iTollValid=p->x.iAddValid=0;
	if((i=ModifyTicket(sTemplateRule,f,sModule,sSplitType,msg))<0){
		WriteAlertPrint(msg);
		exit(-1);
	}

	if(p->x.iRoamValid!=0){
		i=p->x.iRoamValid%62;
		p->iRoamFee=p->x.iRoamFee;
		p->sBillMode[0]=asAnti[i];
	}
	if(p->x.iTollValid!=0){
		i=p->x.iTollValid%62;
		p->iTollFee=p->x.iTollFee;
		p->sBillMode[1]=asAnti[i];
	}
	if(p->x.iAddValid!=0){
		i=p->x.iAddValid%62;
		p->iAddFee=p->x.iAddFee;
		p->sBillMode[2]=asAnti[i];
	}
	
/*
1.ȡ�����Ǳ���Ӫ�̵ĺ��룬����MSISDN����OTHER_PARTY,
������ƶ�������ȥ��0,����ǹ̶�������ȥ�����ţ������������ֱ��ȥ�����ţ�
����������.
2.ACC_NBR����ֶ��ڻ�������ʱ��ֱ������MSRN�ֶ�;
3.�ڻ������У���MSRN����MSISDNʱ��CAL='1',��MSRN����OTHER_PARTYʱ��CAL='2' 
������CAL='3'
4.ֻ���������������
*/
	char sAccNbr[25],sRawMsisdn[15],sRawOtherParty[25],sCal[2];
	struct TicketAnalyzeStruct *pa=&TicketAnalyze;
	
	NewGetRawNbr(p->sMsisdn,p->sHomeAreaCode,p->sStartTime,sRawMsisdn);
	NewGetRawNbr(p->sOtherParty,p->sCalledCode,p->sStartTime,sRawOtherParty);
	
	
	if(f==false&&strncmp(sModule,"ST",2)==0){

		strcpy(sAccNbr,"");
	/*�����������*/
		if(p->iTicketTypeID>0&&
			strcmp(p->sUserType,"P")==0){

			if(pa->iTrunkInCarrierID==4)
				strcpy(sAccNbr,sRawMsisdn);
			else if(pa->iTrunkOutCarrierID==4)
				strcpy(sAccNbr,sRawOtherParty);
			else{
				if(p->iAddFee>p->iTollFee)
					strcpy(sAccNbr,sRawOtherParty);
				if(p->iAddFee<p->iTollFee)
					strcpy(sAccNbr,sRawMsisdn);
				else if((pa->iCallingCarrierID==3||
					pa->iCallingCarrierID==4)&&
					pa->iCallingTypeID!=3001)
					strcpy(sAccNbr,sRawMsisdn);
				else if((pa->iCalledCarrierID==3||
					pa->iCalledCarrierID==4)&&
					pa->iCalledTypeID!=3001)
					strcpy(sAccNbr,sRawOtherParty);
				else
					strcpy(sAccNbr,"NOTFOUND");
			}
		}		
		else if(p->iTicketTypeID>0){
		/*GSM�������*/				
			if(pa->iTrunkInCarrierID==3)
				strcpy(sAccNbr,sRawMsisdn);
			else if(pa->iTrunkOutCarrierID==3)
				strcpy(sAccNbr,sRawOtherParty);
			else{
				if(p->iAddFee>p->iTollFee)
					strcpy(sAccNbr,sRawOtherParty);
				if(p->iAddFee<p->iTollFee)
					strcpy(sAccNbr,sRawMsisdn);
				else if(pa->iCallingCarrierID==3&&
					pa->iCallingTypeID!=3001)
					strcpy(sAccNbr,sRawMsisdn);
				else if(pa->iCalledCarrierID==3&&
					pa->iCalledTypeID!=3001)
					strcpy(sAccNbr,sRawOtherParty);
				else
					strcpy(sAccNbr,"NOTFOUND");
			}
		}

		
		if(strcmp(sAccNbr,sRawMsisdn)==0)
			strcpy(sCal,"1");
		else if(strcmp(sAccNbr,sRawOtherParty)==0)
			strcpy(sCal,"2");
		else	strcpy(sCal,"3");
		
		strncpy(p->sMsrn,sCal,1);
		strncpy(p->sMsrn+1,sAccNbr,11);
		p->sMsrn[12]=0;
	}
	
}         
          
int WantTransKey(char sKey[])
{
	if(IS_MOB_NBR(sKey)&&strlen(sKey)==7) return true;
	if(strncmp(sKey,"4600",4)==0&&strlen(sKey)==15) return true;
	return false;
}
void TransKey(char sKey[])
{
	char sHostTime[15],sTemp[15],sRes[16];
	struct T130AreaCodeStruct *pT130=NULL;
	struct AreaCodeDescStruct *pTemp=NULL;

	GetHostTime(sHostTime);
	if(IS_MOB_NBR(sKey)&&strlen(sKey)==7){
		if(SearchT130AreaCode(sKey,sHostTime,&pT130)==FOUND){
			if(SearchAreaCodeDesc(pT130->sAreaCode,&pTemp)==FOUND)
				strcpy(sKey,pTemp->sCityCode);
		}
	}
	
	/*ΪCDMA1X��������.*/
	if(strncmp(sKey,"4600",4)==0&&strlen(sKey)==15){
		strcpy(sTemp,sKey+4);
		sTemp[7]=0;
		strcpy(sRes,sKey);
		if(GetBinStr("IMSI_AREA_CODE_1X",-1,sTemp,sHostTime,sRes)==FOUND)
			GetCityCode(sRes,sKey);
	}
}
int Insert2SplitList(struct SplitStruct **pptHead,
	struct FileControlStruct *pData,char sKey[])
{
	
	struct SplitStruct *ptHead=*pptHead,*pTemp=NULL;
	
	if((pTemp=SearchKeyNode(sKey,ptHead))==NULL){
		if((pTemp=malloc(sizeof(struct SplitStruct)))==NULL){
			WriteAlertMsg("Ϊ�ڵ������ڴ�ʧ��.\n");
			return -1;
		}
		strcpy(pTemp->sKey,sKey);
		pTemp->pData=NULL;
		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	
	/*�������ڴ�*/
	InsertList((LIST**)&(pTemp->pData),(LIST*)pData);	
		
	return 0;
}
struct SplitStruct *SearchKeyNode(char sKey[],struct SplitStruct *ptHead)
{
	while(ptHead!=NULL){
		if(strcmp(sKey,ptHead->sKey)==0) return ptHead;
		ptHead=ptHead->pNext;
	}
	return NULL;	
}
/*�任����������������ᵹ��*/
int FileControl2SplitList(struct FileControlStruct *ptHead,
	int iStartPos,int iKeyLen,struct SplitStruct **ppList)
{
	char sKey[128];
	struct FileControlStruct *pTemp;

	*ppList=NULL;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		memcpy(sKey,(char *)(pTemp->pData)+iStartPos,iKeyLen);
		sKey[iKeyLen]='\0';
		TrimAll(sKey);
		
		if(WantTransKey(sKey)) TransKey(sKey);
				
		if(Insert2SplitList(ppList,pTemp,sKey)<0) return -1;
	}
	return 0;
}
int OutSplitItem2File(struct FileControlOutStruct *pTemp,char sNormalDir[],
	char sRawName[],int iPos,int iLen,struct FileControlStruct **ppLog)
{
	int iCnt=0;
	char sNormalName[256],sRecord[256];
	struct FileControlStruct *pLog=NULL;
	struct SplitStruct *pSplit=NULL,*pPre,*pCur;

	if(FileControl2SplitList(pTemp->pHead,iPos,iLen,&pSplit)<0){
		WriteAlertMsg("ת������ʧ��");
		return -1;
	}

	pCur=pSplit;
	while(pCur!=NULL){
		pPre=pCur;
		pCur=pCur->pNext;

		sprintf(sNormalName,"%s%s.%s.%s.tmp",sNormalDir,
			sRawName,pTemp->sSuffix,pPre->sKey);
	
		iCnt=CountList((LIST*)pPre->pData);

		if(list2file(&(pPre->pData),sNormalName)<0){
			WriteAlertMsg("д���������ļ�%sʧ��",sNormalName);
			return -1;
		}
		/*����־д�������ļ���*/
		sprintf(sRecord,"%s\t%s\t%d\n",pTemp->sSuffix,pPre->sKey,iCnt);
		
		if(item2list(&pLog,(void*)sRecord,strlen(sRecord))<0){
			WriteAlertMsg("����pLog����ʧ��");
			return -1;
		}
		free(pPre);
	}

	AppendListTail((LIST**)&pLog,(LIST*)(*ppLog));

	*ppLog=pLog;

	return 0;
}
int OutSplitList2File(struct FileControlOutStruct *pList,char sNormalDir[],
	char sRawName[],char sSource[],int iWantCtl,
	char sSplit[],int iPos,int iLen,char sSplitStr[])
{
	char sFileSplit[256];
	struct FileControlStruct *pLog=NULL;
	struct FileControlOutStruct *ptHead,*pTemp;

	if(iLen<=0||strlen(sSplit)==0)
		return OutList2File(pList,sNormalDir,sRawName,sSplitStr);

/*�������һ�����*/
	ptHead=pList;
		
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
	
		/*���Ҫ��iPos��iLen���ָ��ļ�*/
		if(strchr(sSplit,pTemp->sSuffix[0])!=NULL){
			if(OutSplitItem2File(pTemp,sNormalDir,sRawName,
				iPos,iLen,&pLog)<0) return -1;
		}
		else{/*�������Ҫ�ָ������ticket_field.c�ļ��ں��������*/
			if(OutItem2File(pTemp,sNormalDir,sRawName)<0)
				return -1;
		}
		if(strchr(sSplitStr,pTemp->sSuffix[0])==NULL)
			strcat(sSplitStr,pTemp->sSuffix);
	}
	if(pLog!=NULL){
		if(iWantCtl==true){
			GetFileSplit(sSource,sRawName,sFileSplit);
			ReverseList((LIST**)&pLog);
			if(list2file(&pLog,sFileSplit)<0){
				WriteAlertMsg("дFILESPLIT�ļ�ʧ��",sFileSplit);
				return -1;
			}
		}
		else	listfree(&pLog);
	}
	return 0;

}
int WriteTicketToFile(struct FileControlListStruct *pList,char sNormalDir[],
	char sBaseName[],char sSource[],int iWantCtl,
	char sSplit[],int iPos,int iLen,char sSplitStr[])
{
	char sRawName[128];
	struct FileControlOutStruct *ptLkHead=NULL;

	strcpy(sRawName,sBaseName);

/*	if((pc=strchr(sRawName,'.'))!=NULL) *pc=0;*/
	
	CVCtlList2OutList(pList,&ptLkHead);
	
	return OutSplitList2File(ptLkHead,sNormalDir,sRawName,
		sSource,iWantCtl,sSplit,iPos,iLen,sSplitStr);
}

int PrintTicket(struct MobTicketStruct *p,char sSplitType[2],char sRecord[])
{
	int l=0;
	struct TicketAnalyzeStruct *q=&TicketAnalyze;
	
	p->sMsrn[12]=0;

	if(p->iRoamFee>=99999) p->iRoamFee=0;
	if(p->iTollFee>=9999999) p->iTollFee=0;
	if(p->iAddFee>=99999) 	p->iAddFee=0;
	if(p->iDuration>=999999) p->iDuration=0;

	l+=sprintf(sRecord+l,"%04d%-2s%-15s%-5s%-24s",
		p->iTicketTypeID,p->sCallType,p->sMsisdn,
		p->sCalledCode,p->sOtherParty);
	l+=sprintf(sRecord+l,"%-5s%05d%07d%05d%06d%-14s",
		p->sVisitAreaCode,p->iRoamFee,p->iTollFee,
		p->iAddFee,p->iDuration,p->sStartTime);
	l+=sprintf(sRecord+l,"%-5s%1s%1s%1s%1s%04d%1s",
		p->sHomeAreaCode,p->sRoamType,p->sDistanceType,
		p->sOppType,p->sUserType,p->iSplitRuleID,p->sOppRoamType);
	LeftPad(p->sServiceType,3,'0');
	LeftPad(p->sServiceCode,4,'0');
	l+=sprintf(sRecord+l,"%3s%4s",
		p->sServiceType,p->sServiceCode);
	l+=sprintf(sRecord+l,"%-15s%-15s%-5s%-5s%-5s%-5s%-7s%-7s%-15s%-12s",
		p->sImsi,p->sMsc,p->sLac,p->sCellID,p->sOtherLac,p->sOtherCellID,
		p->sTrunkIn,p->sTrunkOut,p->sThirdParty,p->sMsrn);
	l+=sprintf(sRecord+l,"%04d%04d%04d%04d%1s%1s%04d%04d%04d%04d%04d%04d",
		q->iTrunkInTypeID,q->iTrunkOutTypeID,
		q->iTrunkInCarrierID,q->iTrunkOutCarrierID,
		q->sTrunkInOppType,q->sTrunkOutOppType,
		q->iCallingCarrierID,q->iCalledCarrierID,
		q->iCallingTypeID,q->iCalledTypeID,
		q->iCallingAreaID,q->iCalledAreaID);
	l+=sprintf(sRecord+l,"%1s%-1s%-15s%-1s%-1s%-8s%-3s",
		p->sSplitType,p->sCal,p->sEsn,p->sScpFlag,
		p->sDeformFlag,p->sReserve,p->sBillMode);
	l+=sprintf(sRecord+l,"%-2s%-3s%-3s%-3s",p->sReserve1,
		p->sRoamTariffType,p->sTollTariffType,p->sAddTariffType);
	l+=sprintf(sRecord+l,"%04d%-19s%-3s%-5s\n",
		atoi(p->sErrCode),p->sFileName,p->sModule,p->sAreaCode);

/*	l+=sprintf(sRecord+l,"%1s%-1s%-15s%-1s%-1s%-8s%-3s%04d%-19s%-3s%-5s",
		p->sSplitType,p->sCal,p->sEsn,p->sScpFlag,
		p->sDeformFlag,p->sReserve,p->sBillMode,
		atoi(p->sErrCode),p->sFileName,p->sModule,p->sAreaCode);
	l+=sprintf(sRecord+l,"%-2s%-3s%-3s%-3s\n",p->sReserve1,
		p->sRoamTariffType,p->sTollTariffType,p->sAddTariffType);
*/
/**
	if ( l!=248 ){
		printf("heheeheh.\n");
	}
**/
	return l;
}
int PrintTicketDel(struct MobTicketStruct *pn,struct RSttTicketStruct *p,
	char sRecord[])
{
	int l=0;
	char sBillMode[4];
	
	strcpy(sBillMode,"BLR");
	
	p->sMsrn[12]=0;

	
	l+=sprintf(sRecord+l,"%04d%-2s%-15s%-5s%-24s",
		p->iTicketTypeID,p->sCallType,p->sMsisdn,
		p->sCalledCode,p->sOtherParty);
	l+=sprintf(sRecord+l,"%-5s%5d%7d%5d%06d%-14s",
		p->sVisitAreaCode,p->iRoamFee,p->iTollFee,
		p->iAddFee,atoi(p->sDuration),p->sStartTime);
	l+=sprintf(sRecord+l,"%-5s%1s%1s%1s%1s%04d%1s",
		p->sHomeAreaCode,p->sRoamType,p->sDistanceType,
		p->sOppType,p->sUserType,atoi(p->sSplitRuleID)," ");
	LeftPad(p->sServiceType,3,'0');
	LeftPad(p->sServiceCode,4,'0');
	l+=sprintf(sRecord+l,"%3s%4s",
		p->sServiceType,p->sServiceCode);
	l+=sprintf(sRecord+l,"%-15s%-15s%-5s%-5s%-5s%-5s%-7s%-7s%-15s%-12s",
		p->sImsi,p->sMsc,p->sLac,p->sCellID,p->sOtherLac,p->sOtherCellID,
		p->sTrunkIn,p->sTrunkOut,p->sThirdParty,p->sMsrn);
	l+=sprintf(sRecord+l,"%04d%04d%04d%04d%1s%1s%04d%04d%04d%04d%04d%04d",
		p->iTrunkInTypeID,p->iTrunkOutTypeID,
		p->iTrunkInCarrierID,p->iTrunkOutCarrierID,
		p->sTrunkInType,p->sTrunkOutType,
		p->iCallingCarrierID,p->iCalledCarrierID,
		p->iCallingTypeID,p->iCalledTypeID,
		p->iCallingAreaID,p->iCalledAreaID);

	l+=sprintf(sRecord+l,"%1s%-1s%-15s%-1s%-1s%-8s%-3s",
		p->sSplitType,p->sCal,p->sEsn,p->sScpFlag,
		p->sDeformFlag,p->sReserve,sBillMode);
	l+=sprintf(sRecord+l,"%-2s%-3s%-3s%-3s",p->sReserve1,
		p->sRoamTariffType,p->sTollTariffType,p->sAddTariffType);
	l+=sprintf(sRecord+l,"%04d%-19s%-3s%-5s\n",
		atoi(pn->sErrCode),pn->sFileName,pn->sModule,pn->sAreaCode);
/*		
	l+=sprintf(sRecord+l,"%1s%-1s%-15s%-1s%-1s%-8s%-3s%04d%-19s%-3s%-5s",
		p->sSplitType,p->sCal,p->sEsn,p->sScpFlag,
		p->sDeformFlag,p->sReserve,sBillMode,
		atoi(pn->sErrCode),pn->sFileName,pn->sModule,pn->sAreaCode);

	l+=sprintf(sRecord+l,"%-2s%-3s%-3s%-3s\n",p->sReserve1,
		p->sRoamTariffType,p->sTollTariffType,p->sAddTariffType);
*/
	return l;
}

/*������������������������ticket.c��*/
void AnalyzeUserType(char sUserType[],struct MobTicketStruct *p)
{
	if(strcmp(sUserType,"U")!=0){
		strcpy(p->sUserType,sUserType);
		return;
	}
	if(IS_UNICOM_CDMA(p->sMsisdn)||IS_UNICOM_CDMA(p->sOtherParty))
		strcpy(p->sUserType,"C");
	else
		strcpy(p->sUserType,"G");
}
void PreModifyTicket(struct MobTicketStruct *p,int iFlag)
{
	/*�ƷѺ�ת�������⴦��*/
	if(iFlag==true&&strcmp(p->sUserType,"C")==0&&
		strcmp(p->sCallType,"03")==0&&p->sRoamType[0]=='2'){
		p->sDistanceType[0]=p->sOppType[0];
		strcpy(p->sVisitAreaCode,p->sHomeAreaCode);
	}
	if(strncmp(p->sVisitAreaCode,"90",2)==0||
		strncmp(p->sVisitAreaCode,"99",2)==0||
		strncmp(p->sVisitAreaCode,"31",2)==0||
		strncmp(p->sVisitAreaCode,"33",2)==0){

		if(iFlag==true){
			if(strcmp(p->sUserType,"C")==0&&
				strncmp(p->sRawOtherParty,"10157",5)==0){
				
				strcpy(p->sCalledCode,"991");
				if(strcmp(p->sVisitAreaCode,p->sCalledCode)==0)
					p->sDistanceType[0]='1';
				else
					p->sDistanceType[0]='2';
			}
			/*�½������ϴ��·����⴦��*/
			if(strcmp(p->sCallType,"01")==0&&
				p->sOtherParty[0]!='0'&&
				IS_MOB_NBR(p->sOtherParty)==false&&
				SpecialNbr(p->sOtherParty,p->sStartTime)!=true){

				char sTemp[32];
				struct AreaCodeDescStruct *pAreaCode=NULL;
			
				if(SearchAreaCodeDesc(p->sOtherParty,
					&pAreaCode)==NOTFOUND) return;
					
				if(SpecialNbr(p->sOtherParty+
					strlen(pAreaCode->sAreaCode),
					p->sStartTime)==false) return;

				if(strlen(p->sOtherParty)>=strlen(pAreaCode->sAreaCode)+3){
					/*���Զ˺���ǰ��0*/
					strcpy(sTemp,"0");
					strcat(sTemp,p->sOtherParty);
					strcpy(p->sOtherParty,sTemp);
				}
			}
		}
		else{/*���㲿��*/
			char	sTemp[15];
			struct MscStruct *pMsc;
			struct TrunkStruct *pTrunk;

			if(SearchMsc(p->sMsc,&pMsc)==NOTFOUND) return;
			if(strcmp(pMsc->sMscType,"ZTE123")!=0) return;

			sTemp[0]=0;

		/*�������м̴�ESN�ֶ����һ���*/
			if(strcmp(p->sTrunkIn,DEF_TRUNK)==0||
				strcmp(p->sTrunkIn,"0000")==0||
				strcmp(p->sTrunkOut,DEF_TRUNK)==0||
				strcmp(p->sTrunkOut,"0000")==0){

				char *pc;
		/*�����','�ָ�ESN˵����������Ĭ�ϣ�����ȡ���м���ȡ���м�*/
				if((pc=strchr(p->sEsn,','))!=NULL){

					strncpy(p->sTrunkIn,p->sEsn,pc-p->sEsn);
					p->sTrunkIn[pc-p->sEsn]=0;
					AllTrim(p->sTrunkIn);

					strncpy(p->sTrunkOut,pc+1,7);
					p->sTrunkOut[7]=0;
					AllTrim(p->sTrunkOut);									
				}
				else{/*�ĸ���Ĭ���м̾ͻ����ĸ�*/
					if(strcmp(p->sTrunkIn,DEF_TRUNK)==0||
						strcmp(p->sTrunkIn,"0000")==0){
						strncpy(p->sTrunkIn,p->sEsn,7);
						p->sTrunkIn[7]=0;
						AllTrim(p->sTrunkIn);
					}
					else{
						strncpy(p->sTrunkOut,p->sEsn,7);
						p->sTrunkOut[7]=0;
						AllTrim(p->sTrunkOut);
					}
				}
			}

			if(SearchTrunk(p->sMsc,p->sTrunkIn,"I",
				p->sStartTime,&pTrunk)==NOTFOUND){
				strcat(sTemp,p->sTrunkIn);
				strcpy(p->sTrunkIn,DEF_TRUNK);
			}
			if(SearchTrunk(p->sMsc,p->sTrunkOut,"O",
				p->sStartTime,&pTrunk)==NOTFOUND){

				if(strlen(sTemp)>0) strcat(sTemp,",");
				strcat(sTemp,p->sTrunkOut);
				strcpy(p->sTrunkOut,DEF_TRUNK);
			}
			if(strlen(sTemp)!=0)strcpy(p->sEsn,	sTemp);
		}
	}
}

int IsDpAccNbrX(char sDp[],char sAccNbr[])
{
/*Я�Ź�����Ӫ�̵��ж�
	if(strcmp(sDp,"mobnbr")!=0&&strcmp(sDp,"mobimsi")!=0){
		struct ICommSearchStruct *pTemp;
		char sHostTime[15],sHeadDp[20];
		GetHostTime(sHostTime);
		
		if(SearchCommTrie("NP_TC_HEADDP",0,sAccNbr,sHostTime,&pTemp)
			==FOUND){
			GetStrValFromCS(pTemp,sHeadDp);
			if(strcmp(sDp,sHeadDp)==0)return true;
			else return false;
		}
	}
*/	
	
	return IsDpAccNbr(sDp,sAccNbr);
	
}

