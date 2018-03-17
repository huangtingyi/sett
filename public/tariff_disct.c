#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <trie.h>
#include <expr_supp.h>

#include "gen_supp.h"
#include "ticket_field.h"
#include "tariff_disct.h"
#include "param_intf.h"

struct TimeSpanDisctStruct *GetTimeSpanPoint(int i,
	struct TimeSpanDisctStruct *ptHead)
{
	struct TimeSpanDisctStruct *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

/*������Чʱ���ڵĻ���*/
		if(i<pTemp->iOffset1||i>=(pTemp->iOffset1+pTemp->iDuration1))
			continue;

/*������Ч�ڣ���OFFSET1�۳�*/
		if(pTemp->iOffset1>=0) i-=pTemp->iOffset1;
/*���������,������*/
		if(pTemp->iCycle!=-1) i=i%pTemp->iCycle;

		if(i>=pTemp->iOffset2&&i<(pTemp->iOffset2+pTemp->iDuration2))
			return pTemp;
	}
	return NULL;
}
int comp_time_span_list(LIST *pValue,LIST*pHead)
{

        struct TimeSpanStruct *pSource=(struct TimeSpanStruct *)pValue;
        struct TimeSpanStruct *pTarget=(struct TimeSpanStruct *)pHead;

        return pTarget->iBeginCnt-pSource->iBeginCnt;
}
struct TimeSpanStruct *GetTimeSpanList(struct TimeSpanDisctStruct *ptHead)
{
	int i;
	struct TimeSpanDisctStruct *ptPre,*ptCur;
	struct TimeSpanStruct *ptLkHead=NULL,*pTemp;

	if(ptHead==NULL) return NULL;

	ptPre=ptCur=NULL;

	/*����0��10000�ε�LIST����*/
	for(i=0;i<90000;i++){
		ptCur=GetTimeSpanPoint(i,ptHead);
		if(i==0){
			pTemp=(struct TimeSpanStruct *)malloc(sizeof(struct TimeSpanStruct));
			if(pTemp==NULL) return NULL;

			pTemp->iBeginCnt=0;
			pTemp->iEndCnt=	0;
			pTemp->pNext=NULL;
			pTemp->tBeginTime=0;
			pTemp->tEndTime=0;

			if(ptCur==NULL){
				pTemp->iMethod=	1;/*����*/
				pTemp->iRate=	1000;
			}
			else{
				pTemp->iMethod=atoi(ptCur->sMethod);
				pTemp->iRate=	ptCur->iRate;
			}
			ptPre=ptCur;
			continue;
		}
		if(ptCur!=ptPre){

			pTemp->iEndCnt=i;

			InsertListSort((LIST**)&ptLkHead,(LIST*)pTemp,
				comp_time_span_list);

			pTemp=(struct TimeSpanStruct *)malloc(sizeof(struct TimeSpanStruct));
			if(pTemp==NULL) return NULL;

			pTemp->iBeginCnt=i;
			pTemp->iEndCnt=i;
			pTemp->pNext=NULL;
			pTemp->tBeginTime=0;
			pTemp->tEndTime=0;
			if(ptCur==NULL){
				pTemp->iMethod=	1;/*����*/
				pTemp->iRate=	1000;
			}
			else{
				pTemp->iMethod=atoi(ptCur->sMethod);
				pTemp->iRate=	ptCur->iRate;
			}
			ptPre=ptCur;
		}
	}

/*�������һ��*/
	pTemp->iEndCnt=i;

	InsertListSort((LIST**)&ptLkHead,(LIST*)pTemp,
		comp_time_span_list);

	/*�������Ѿ�������pNext�������е�����*/
	/*�������ɵ�pLoadNext��������������*/
	pTemp=ptLkHead;
	ptLkHead=NULL;

	while(pTemp!=NULL){

		/*һ��һ��ȡ�����ɵ�pLoadNext��*/
		pTemp->pLoadNext=ptLkHead;
		ptLkHead=pTemp;

		pTemp=pTemp->pNext;
	}

        return ptLkHead;
}

int InitialTicketBasedDisct(struct TicketBasedDisctStruct *pTemp)
{
	time_t 	tBaseTime=0;
	char	sBaseTime[15],sTemp[15];

	/*���������ֶ�*/

/*������ЧʧЧʱ��*/
	pTemp->tEffDate=tGetTime(pTemp->sEffDate);
	pTemp->tExpDate=tGetTime(pTemp->sExpDate);

        /*���ɻ�׼ʱ��*/
	strcpy(sBaseTime,"19900101000000");/*����һ*/
	tBaseTime=tGetTime(sBaseTime);

	pTemp->iUnit=atoi(pTemp->sUnit);
	pTemp->iUnitOri=pTemp->iUnit;
	
	pTemp->tYear=-1;
	switch(pTemp->iUnit){
	case 3:/*��*/
		pTemp->iUnit=7*86400;
		pTemp->iBeginDate=(pTemp->iOffset1%8)*86400;
		pTemp->iEndDate=((pTemp->iOffset1+pTemp->iDuration1)%8)*86400;
	break;
	case 2:/*��*/
		pTemp->iUnit=86400;
		pTemp->iBeginDate=0;
		pTemp->iEndDate=86400;
	break;
	case 9:/*����,�����unit,begindate,enddate��Ҫ�����ʱ�����*/
		pTemp->tYear=0;
		pTemp->iBeginDate=pTemp->iOffset1%9999;
		pTemp->iEndDate=pTemp->iDuration1*86400;
	case 10:/*����,�����unit,begindate,enddate��Ҫ�����ʱ�����*/
		pTemp->tYear=0;
		pTemp->iBeginDate=pTemp->iOffset1*86400;;
		pTemp->iEndDate=(pTemp->iOffset1+pTemp->iDuration1)*86400;
		break;
	default:/*Ĭ��Ϊ��Ϊ����*/
		pTemp->iUnit=86400;
		pTemp->iBeginDate=0;
		pTemp->iEndDate=86400;
	break;
	}

	pTemp->tBaseTime=tBaseTime;

	strncpy(sTemp,sBaseTime,8);
	strcpy(sTemp+8,pTemp->sOffset2);
	pTemp->iBeginTime=tGetTime(sTemp)-tBaseTime;
	pTemp->iEndTime=	pTemp->iBeginTime+pTemp->iDuration2;

	pTemp->iMethod=atoi(pTemp->sMethod);

/*У�������ֶ�*/
	if(pTemp->iBeginDate>pTemp->iEndDate&&pTemp->tYear==-1){
		WriteAlertMsg("���ô���,OFFSET1+DURATION1��������.\n\
	TICKET_BASED_DISCT ID=%d,ϵͳ����.\n",pTemp->iTicketBasedDisctID);
		 return -1;
	}
	if(pTemp->iBeginTime<0){
		WriteAlertMsg("���ô���,OFFSET2��ʽ����hh24miss.\n\
	TICKET_BASED_DISCT ID=%d,ϵͳ����.\n",pTemp->iTicketBasedDisctID);
		 return -1;
	}
	if(pTemp->iEndTime>86400){
		WriteAlertMsg("���ô���,OFFSET2+DURATION2������.\n\
	TICKET_BASED_DISCT ID=%d,ϵͳ����.\n",pTemp->iTicketBasedDisctID);
		 return -1;
	}

	return 0;
}

int comp_insert_list_ticket_based_disct_e(LIST *pValue,LIST*pHead)
{
	struct TicketBasedDisctStruct *pSource=(struct TicketBasedDisctStruct *)pValue;
	struct TicketBasedDisctStruct *pTarget=(struct TicketBasedDisctStruct *)pHead;

	return pSource->iPriority-pTarget->iPriority;
}

void assign_insert_bintree_ticket_based_disct_e(void **ppHead,void *pData)
{
	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_ticket_based_disct_e);
}
struct TicketBasedDisctStruct *GetTicketBasedDisctList(int iDisctRuleID)
{

	struct TicketBasedDisctStruct *ptLkHead=NULL,*ptHead=NULL,*pTemp;

        if(SearchTicketBasedDisct(iDisctRuleID,&ptHead)==NOTFOUND)return NULL;


       	while(ptHead!=NULL){
       		pTemp=ptHead;
       		ptHead=ptHead->pNext;

		if(InitialTicketBasedDisct(pTemp)<0) continue;

		InsertListSort((LIST**)&ptLkHead,(LIST*)pTemp,
			comp_insert_list_ticket_based_disct_e);
	}

	return ptLkHead;
}
struct TimeSpanControlStruct *GetTimeSpanDisctList(int iDisctRuleID)
{
	struct TimeSpanControlStruct *pTemp;
	struct TimeSpanStruct *pTimeSpan;
	struct TicketBasedDisctStruct *pTicketBased;
	struct TimeSpanDisctStruct *ptHead=NULL;
	static struct TimeSpanStruct DefaultTimeSpan={NULL,0,10000,1,1000,0,0,0,0,NULL};

	if(SearchTimeSpanDisct(iDisctRuleID,&ptHead)==NOTFOUND)
		pTimeSpan=&DefaultTimeSpan;
	else
		pTimeSpan=GetTimeSpanList(ptHead);

	pTicketBased=GetTicketBasedDisctList(iDisctRuleID);

	if((pTemp=(struct TimeSpanControlStruct *)malloc(
		sizeof(struct TimeSpanControlStruct)))==NULL) return NULL;
	pTemp->pTimeSpan=	pTimeSpan;
	pTemp->pTicketBased=	pTicketBased;
	return pTemp;
}
int comp_insert_list_expr_def_e(LIST *pValue,LIST*pHead)
{
	struct ExprDefStruct *pSource=(struct ExprDefStruct *)pValue;
	struct ExprDefStruct *pTarget=(struct ExprDefStruct *)pHead;

	return pSource->iPriority-pTarget->iPriority;
}
struct	ExprDefStruct *GetExprDisctList(int iDisctRuleID)
{
	struct	ExprDefStruct *ptLkHead=NULL;
	struct	ExprDefStruct	*pExprDef;
	struct	ExprDisctStruct *ptHead=NULL,*pTemp;
	int	iOutputLen;
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];

	if(SearchExprDisct(iDisctRuleID,&ptHead)==NOTFOUND) return NULL;

	ERROR_EXIT((RegExprSupp()<0),"���س�ʼ������");

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(pExprDef==NULL) continue;

		pExprDef=PEXPRDEF(pTemp->iExprID);

		ERROR_EXIT((pExprDef==NULL),"���س�ʼ������");

		if(strcmp(pExprDef->sState,"A0A")!=0) continue;

		if(pExprDef->iCompileFlag==0){

			ERROR_EXIT((CompileExpr(pExprDef->sExpr,asVarOutput,
				&iOutputLen)<0),"��ʽ����ʧ��");

			pExprDef->pExprBuf=GetCompileResult();
			ERROR_EXIT((pExprDef->pExprBuf==NULL),"��ʽ��������ڴ�ʧ��");
			pExprDef->iCompileFlag=1;
		}

		pExprDef->iPriority=	pTemp->iPriority;
		strcpy(pExprDef->sParam,pTemp->sParam);

		InsertListSort((LIST**)&ptLkHead,(LIST*)pTemp,
			comp_insert_list_expr_def_e);
	}

	return ptLkHead;
}

struct DisctRuleMutexStruct *GetDisctRuleMutexList(int iDisctRuleID)
{
	struct DisctRuleMutexStruct *ptHead=NULL;

	if(SearchDisctRuleMutex(iDisctRuleID,&ptHead)==NOTFOUND)
		return NULL;
	return ptHead;
}
int comp_disct_rule_ticket01(LIST* pData)
{
	struct DisctRuleStruct *ptHead=(struct DisctRuleStruct *)pData;

	if((strcmp(ptHead->sDisctType,"00")==0)||
		(strcmp(ptHead->sDisctType,"01")==0)||
		(strcmp(ptHead->sDisctType,"10")==0))
		return 0;
	return 1;

}
int InitialDisctRule(struct DisctRuleStruct *pTemp)
{
	pTemp->tEffDate=tGetTime(pTemp->sEffDate);
	pTemp->tExpDate=tGetTime(pTemp->sExpDate);

	pTemp->iDisctType=atoi(pTemp->sDisctType);

	pTemp->pNext=NULL;


	pTemp->pMutex=GetDisctRuleMutexList(pTemp->iDisctRuleID);

	switch(pTemp->iDisctType){
	case 0:/*ʱ���Ż�*/
	case 1:/**�ֽ׶��Ż�*/
		pTemp->pDisct=(void*)GetTimeSpanDisctList(pTemp->iDisctRuleID);
		pTemp->Disct=	DisctTimeSpan;
	break;
	case 10:/*��ʽ�Ż�*/
		pTemp->pDisct=(void*)GetExprDisctList(pTemp->iDisctRuleID);
		pTemp->Disct=	DisctExpr;
	break;
	default:
		pTemp->pDisct=NULL;
		pTemp->Disct=NULL;
	}
	if(pTemp->pDisct==NULL) return -1;

	return 0;
}
void InsertDisctRuleCur(struct DisctRuleStruct **pptHead,
	struct DisctRuleStruct *pTemp)
{
	pTemp->pCurNext=*pptHead;
	*pptHead=	pTemp;
}
void ResetDisctRuleList(struct DisctRuleStruct *ptHead)
{
	while(ptHead!=NULL){
		PDISCTRULE(ptHead->iDisctRuleID)=NULL;
		ptHead=ptHead->pCurNext;
	}
}
void InsertDisctRuleTariffNxt(struct DisctRuleStruct **pptHead,
	struct DisctRuleStruct *pTemp)
{
	pTemp->pTariffNext=*pptHead;
	*pptHead=	pTemp;
}
struct DisctRuleStruct *InitDisctRuleList(int (*comp_fun)(LIST*))
{
	struct TollTariffStruct *pTariff;
	static struct DisctRuleStruct *ptLkHead=NULL,*ptHead=NULL,*pTemp;

	ResetDisctRuleList(ptLkHead);ptLkHead=NULL;

	if(SearchDisctRule(comp_fun,&ptHead)==NOTFOUND) return NULL;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(InitialDisctRule(pTemp)<0) continue;

		/*����û���ʷѵ��Żݹ��������*/
		if(pTemp->iTariffID<0) continue;
		
		if(SearchTollTariffSeqListID(PTOLLTARIFF(pTemp->iTariffID),
			pTemp->iTariffID,pTemp->iSeqNbr,&pTariff)==FOUND){
		
			/*���ʷѹ���*/
			InsertDisctRuleTariffNxt(&(pTariff->pDisctRule),pTemp);
			
			PDISCTRULE(pTemp->iDisctRuleID)=	pTemp;

			InsertDisctRuleCur(&ptLkHead,pTemp);
		}
	}
	return ptLkHead;
}

int comp_toll_tariff_ticket03(LIST* pData)
{
	struct TollTariffStruct *ptHead=(struct TollTariffStruct *)pData;

	if(strcmp(ptHead->sEffDate,ptHead->sExpDate)>=0) return 1;
	if(strcmp(ptHead->sTollType,"03")==0) return 0;
	return 1;
}
int comp_toll_tariff_ticket(LIST* pData)
{
	struct TollTariffStruct *ptHead=(struct TollTariffStruct *)pData;

	if(strcmp(ptHead->sEffDate,ptHead->sExpDate)>=0) return 1;
	return 0;
}
int InitialTollTariff(struct TollTariffStruct *pTemp)
{
	pTemp->tEffDate=tGetTime(pTemp->sEffDate);
	pTemp->tExpDate=tGetTime(pTemp->sExpDate);
	pTemp->iTollType=atoi(pTemp->sTollType);
	pTemp->iTariffType=atoi(pTemp->sTariffType);
	pTemp->tBeginTime=0;
	pTemp->tEndTime=0;
	pTemp->iCounts=0;
	pTemp->iAcctItemTypeID=0;
	pTemp->iFee=0;
	pTemp->iDisctFee=0;
	pTemp->iTicketItemTypeID=0;
	pTemp->pDisctRule=NULL;
	pTemp->pCurNext=NULL;
	if(pTemp->tEffDate>=pTemp->tExpDate) return -1;
	return 0;
}
void InsertTollTariffCur(struct TollTariffStruct **pptHead,
	struct TollTariffStruct *pTemp)
{
	pTemp->pCurNext=*pptHead;
	*pptHead=	pTemp;
}
void ResetTollTariffList(struct TollTariffStruct *ptHead)
{
	while(ptHead!=NULL){
		PTOLLTARIFF(ptHead->iTariffID)=NULL;
		ptHead=ptHead->pCurNext;
	}
}
int SearchTollTariffSeqListTime(struct TollTariffStruct *ptHead,
	char sStartTime[],struct TollTariffStruct **pptCur)
{
	*pptCur=NULL;

	while(ptHead!=NULL){
		MY_MATCH_ARCH(sStartTime,ptHead,pptCur);
		ptHead=ptHead->pSeqNext;
	}
	if((*pptCur)!=NULL) return FOUND;
	return NOTFOUND;
}
int SearchTollTariffSeqListID(struct TollTariffStruct *ptHead,
	int iTariffID,int iSeqNbr,struct TollTariffStruct **pptCur)
{
	*pptCur=NULL;

	while(ptHead!=NULL){
		if(iTariffID==ptHead->iTariffID&&
			iSeqNbr==ptHead->iSeqNbr){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pSeqNext;
	}
	return NOTFOUND;	
}
int comp_insert_mlist_toll_tariff_e(MLIST *pValue,MLIST*pHead)
{
	return comp_insert_list_toll_tariff_e((LIST*)pValue,(LIST*)pHead);
}
struct TollTariffStruct *InitTollTariffList()
{
	static struct TollTariffStruct *ptLkHead=NULL,*ptHead=NULL,*pTemp;
	
	ResetTollTariffList(ptLkHead);ptLkHead=NULL;

	if(SearchTollTariff(&ptHead)==NOTFOUND) return NULL;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(InitialTollTariff(pTemp)<0) continue;

		InsertMListSort((MLIST**)&PTOLLTARIFF(pTemp->iTariffID),
			(MLIST*)pTemp,comp_insert_mlist_toll_tariff_e,1);

		InsertTollTariffCur(&ptLkHead,pTemp);
	}

	InitDisctRuleList(comp_disct_rule_ticket01);

	return ptLkHead;
}
int comp_toll_tariff_list(LIST *pValue,LIST*pHead)
{
        struct TollTariffStruct *pSource=(struct TollTariffStruct *)pValue;
        struct TollTariffStruct *pTarget=(struct TollTariffStruct *)pHead;

        return pSource->tEffDate-pTarget->tEffDate;
}
/*����Ҫ������Tariff�б�*/
struct TollTariffStruct *GetTollTariffList(int iTicketTypeID,char sFieldType[])
{
	struct TollTariffStruct *pTollTariff=NULL;
	struct TollTariffStruct *p1=NULL,*p2=NULL,*p3=NULL,*p,*pt,**pp;
	struct TicketTypeTariffStruct *ptHead=NULL,*pTemp;

	if(SearchTicketTypeTariff(iTicketTypeID,&ptHead)!=FOUND)
		return NULL;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((pt=PTOLLTARIFF(pTemp->iTariffID))==NULL) continue;
		if(strcmp(pt->sFieldType,sFieldType)!=0) continue;

		while(pt!=NULL){
			p=pt;pt=pt->pSeqNext;

			p->iFee=p->iDisctFee=	0;
			p->iAcctItemTypeID=	pTemp->iAcctItemTypeID;
			p->iTicketItemTypeID=	pTemp->iAcctItemTypeID;
			p->pNext=p->pTariffNext=NULL;
	
			if(p->iTariffType==01)		pp=&p1;
			else if(p->iTariffType==02)	pp=&p2;
			else				pp=&p3;

			InsertListSort((LIST**)pp,(LIST*)p,comp_toll_tariff_list);
		}
	}

	if(p1!=NULL)	pTollTariff=p1;

	if(p2!=NULL){
		if(pTollTariff!=NULL)
			pTollTariff->pTariffNext=p2;
		else
			pTollTariff=p2;
	}
	if(p3!=NULL){
		if(pTollTariff!=NULL){
			if(pTollTariff->pTariffNext!=NULL)
				pTollTariff->pTariffNext->pTariffNext=p3;
			else
				pTollTariff->pTariffNext=p3;
		}
		else
			pTollTariff=p3;
	}
	return pTollTariff;
}
/*����Ҫ������Tariff�б�,����TARIFF_REF��*/
struct TollTariffStruct *GetTariffRefList(char sTariffRef[])
{
	struct TollTariffStruct *pTollTariff=NULL,*p,*pt;
	struct TollTariffStruct *ptHead=NULL,*pTemp;

	if(SearchTollTariffRef(sTariffRef,&ptHead)!=FOUND) return NULL;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((pt=PTOLLTARIFF(pTemp->iTariffID))==NULL) continue;
		
		while(pt!=NULL){
			p=pt;pt=pt->pSeqNext;

			p->iFee=p->iDisctFee=	0;
			p->iAcctItemTypeID=	0;
			p->iTicketItemTypeID=	0;
			p->pNext=p->pTariffNext=NULL;

			InsertListSort((LIST**)&pTollTariff,(LIST*)p,
				comp_toll_tariff_list);
		}
	}

	return pTollTariff;
}
/*ȡ���Ⱥ���
 0 �� 1�� 2Ԫ ������Ч*/
int GetPrecision(int k,int p)
{
	int j,l,l2;
	static int dividend[3]={1,10,100};

	if(p>2||p<=0) return k;

	l=dividend[p]/2;

	l2=l+l;

	j=(k+l)%l2;

	return (k + l - j);
}

void TicketTimeIntersectToTariff(time_t tStartTime,int iDuration,
	struct TollTariffStruct *pTollTariff)
{
	int	l,u,c;
	time_t	tTempBegin,tTempEnd;
	struct TollTariffStruct *ptHead,*pTemp;

	while(pTollTariff!=NULL){

		tTempBegin=	tStartTime;
		tTempEnd=	tStartTime+iDuration;
		ptHead=pTollTariff;

		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;

			pTemp->tBeginTime=MY_MAX(tTempBegin,pTemp->tEffDate);
			pTemp->tEndTime=MY_MIN(tTempEnd,pTemp->tExpDate);

			l=pTemp->tEndTime-pTemp->tBeginTime;
			if(l<=0) continue;

			u=pTemp->iSecPerCnt;
			c=(l+u-1)/u;

			pTemp->iFee=GetPrecision(pTemp->iRate*c,
				pTemp->iCalcPrecision);

			pTemp->iCounts=	c;
			pTemp->tEndTime=pTemp->tBeginTime+c*u;

			tTempBegin=pTemp->tEndTime;

			if(tTempBegin>=tTempEnd) break;
		}
		pTollTariff=pTollTariff->pTariffNext;
	}
}
void GetCalcFee(struct TollTariffStruct *pTollTariff,
	int *piRoamFee,int *piTollFee,int *piAddFee)
{
	struct TollTariffStruct *ptHead;

	*piRoamFee=*piTollFee=*piAddFee=0;

	while(pTollTariff!=NULL){

		ptHead=pTollTariff;

		while(ptHead!=NULL){
			if(ptHead->iTariffType==1)
				*piRoamFee+=ptHead->iFee-ptHead->iDisctFee;
			else if(ptHead->iTariffType==2)
				*piTollFee+=ptHead->iFee-ptHead->iDisctFee;
			else
				*piAddFee+=ptHead->iFee-ptHead->iDisctFee;
			ptHead=ptHead->pNext;
		}
		pTollTariff=pTollTariff->pTariffNext;
	}
}
void GetCalcFeeRate(struct TollTariffStruct *pTollTariff,
	int iValue,int *piRoamFee,int *piTollFee,int *piAddFee)
{
	int	c;
	struct TollTariffStruct *ptHead;

	*piRoamFee=*piTollFee=*piAddFee=0;

	while(pTollTariff!=NULL){

		ptHead=pTollTariff;

		while(ptHead!=NULL){
			
			c=(iValue+ptHead->iSecPerCnt-1)/ptHead->iSecPerCnt;
			
			if(ptHead->iTariffType==1)
				*piRoamFee+=c*(ptHead->iFee-ptHead->iDisctFee);
			else if(ptHead->iTariffType==2)
				*piTollFee+=c*(ptHead->iFee-ptHead->iDisctFee);
			else
				*piAddFee+=c*(ptHead->iFee-ptHead->iDisctFee);
			ptHead=ptHead->pNext;
		}
		pTollTariff=pTollTariff->pTariffNext;
	}
}
void GetCalcDisct(struct DisctRuleStruct *pDisctRule,int *piDisctFee)
{
	int iDisctFee=0;
	struct DisctRuleStruct *ptHead=pDisctRule;

	while(ptHead!=NULL){
		iDisctFee+=ptHead->iDisctFee;
		ptHead=ptHead->pNext;
	}
	*piDisctFee=iDisctFee;
}

struct DisctRuleStruct *GetDisctRuleList(int iTariffID,int iSeqNbr)
{
	struct DisctRuleStruct *pDisctRule=NULL,*ptHead,*pTemp;
	struct TollTariffStruct *pTariff;

	pTariff=PTOLLTARIFF(iTariffID);

	while(pTariff!=NULL){ 
		if(iSeqNbr==pTariff->iSeqNbr) break;
		pTariff=pTariff->pSeqNext;
	}

	if(pTariff==NULL) return NULL;

	ptHead=pTariff->pDisctRule;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pTariffNext;

		/*��ʼʱ�������ų�*/
		pTemp->iMutex=0;

		InsertList((LIST**)&pDisctRule,(LIST*)pTemp);
	}
	return pDisctRule;
}
int comp_insert_list_disct_rule_e(LIST *pValue,LIST*pHead)
{
	struct DisctRuleStruct *pSource=(struct DisctRuleStruct *)pValue;
	struct DisctRuleStruct *pTarget=(struct DisctRuleStruct *)pHead;

	return pSource->iPriority-pTarget->iPriority;
}
int comp_insert_list_disct_rule_t(LIST *pValue,LIST*pHead)
{
	struct DisctRuleStruct *pSource=(struct DisctRuleStruct *)pValue;
	struct DisctRuleStruct *pTarget=(struct DisctRuleStruct *)pHead;

	return pSource->tEffDate-pTarget->tEffDate;
}
void MutexDisctRule(struct DisctRuleStruct **ppDisctRule)
{

	struct DisctRuleStruct *ptHead=*ppDisctRule,*pTemp,*p;
	struct DisctRuleMutexStruct	*pMutex;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(pTemp->iMutex!=0) continue;

		pMutex=pTemp->pMutex;
		while(pMutex!=NULL){
			if((p=PDISCTRULE(pMutex->iExcludeDisctRuleID))!=NULL)
				p->iMutex=1;
			pMutex=pMutex->pNext;
		}
	}
	ptHead=*ppDisctRule;
	*ppDisctRule=NULL;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(pTemp->iMutex!=0) continue;
/*����disct_rule��Чʱ���Խ֮����ų����������*/
		InsertListSort((LIST**)ppDisctRule,(LIST*)pTemp,
			comp_insert_list_disct_rule_e);
	}
}
void TicketTimeIntersectToDisct(time_t tTempBegin,time_t tTempEnd,
	int u,int r,int rp,int cp,struct DisctRuleStruct **ppDisctRule)
{
	int c,l;
	time_t	b,e;
	struct DisctRuleStruct *ptHead=*ppDisctRule,*pTemp;

	*ppDisctRule=NULL;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		b=	MY_MAX(tTempBegin,pTemp->tEffDate);
		e=	MY_MIN(tTempEnd,pTemp->tExpDate);

		l=e-b;
		if(l<=0) continue;

		c=(l+u-1)/u;

		pTemp->iFee=GetPrecision(r*c,cp);
		pTemp->iDisctFee=0;
		pTemp->iCounts=		c;
		pTemp->iRatePrecision= rp;
		pTemp->iCalcPrecision= cp;
		pTemp->iSecPerCnt=	u;
		pTemp->iRate=		r;

		pTemp->tBeginTime=	b;
		pTemp->tEndTime=	b+c*u;

		InsertListSort((LIST**)ppDisctRule,(LIST*)pTemp,
			comp_insert_list_disct_rule_e);

		tTempBegin=pTemp->tEndTime;
		if(tTempBegin>=tTempEnd) break;
	}
}

void TicketTimeIntersectToTimeSpan(struct DisctRuleStruct *pDisctRule,
	struct TimeSpanStruct **ppTimeSpan)
{
	int iCounts=0;
	struct TimeSpanStruct *ptHead=*ppTimeSpan,*pTemp;

	*ppTimeSpan=NULL;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;

		if((pDisctRule->iCounts*pDisctRule->iSecPerCnt)<=pTemp->iEndCnt){

			pTemp->iCounts=pDisctRule->iCounts-iCounts;
			pTemp->tBeginTime=pDisctRule->tBeginTime+pTemp->iBeginCnt;
			pTemp->tEndTime=pDisctRule->tEndTime;

			/*����pTimeSpan����*/
			InsertList((LIST**)ppTimeSpan,(LIST*)pTemp);

			break;
		}

		pTemp->tBeginTime=pDisctRule->tBeginTime+pTemp->iBeginCnt;
		pTemp->tEndTime=pDisctRule->tBeginTime+pTemp->iEndCnt;

		pTemp->iCounts=(pTemp->iEndCnt-pTemp->iBeginCnt)/pDisctRule->iSecPerCnt;
		iCounts+=pTemp->iCounts;

		/*����pTimeSpan����*/
		InsertList((LIST**)ppTimeSpan,(LIST*)pTemp);
	}
}
void InitBaseItem(char sBaseDate[15],struct BaseYearStruct *po)
{
	bzero((void*)po,sizeof(struct BaseYearStruct));
	strcpy(po->sBaseDate,sBaseDate);
	strcpy(po->sBaseDate+8,"000000");
	po->tBeginDate=tGetTime(po->sBaseDate);
}
void InitEndDate(struct BaseYearStruct *ptHead,int iCnt)
{
	int i,j=0;
	struct BaseYearStruct *ptPre,*ptCur;
	
	ptPre=ptCur=ptHead;

	for(i=1;i<iCnt;i++){
		ptPre=ptHead+j;
		ptCur=ptPre+1;
		
		ptPre->tEndDate=ptCur->tBeginDate;
		j++;
	}
	ptCur->tEndDate=ptCur->tBeginDate+86400*3000;
}
int InitBaseYear(struct BaseYearStruct *ptHead)
{
	int i=0,iYear;
	char sTempDate[9];

	for(i=0;i<100;i++){
		iYear=1990+i;
		sprintf(sTempDate,"%4d0101",iYear);
		InitBaseItem(sTempDate,ptHead+i);
	}
	InitEndDate(ptHead,i);
	return i;
}
int InitBaseNian(struct BaseYearStruct *ptHead)
{
	int i=0;
/*1990��-99��*/
	InitBaseItem("19900127",ptHead+i); i++;
	InitBaseItem("19910215",ptHead+i); i++;
	InitBaseItem("19920204",ptHead+i); i++;
	InitBaseItem("19930123",ptHead+i); i++;
	InitBaseItem("19940210",ptHead+i); i++;
	InitBaseItem("19950131",ptHead+i); i++;
	InitBaseItem("19960219",ptHead+i); i++;
	InitBaseItem("19970207",ptHead+i); i++;
	InitBaseItem("19980128",ptHead+i); i++;
	InitBaseItem("19990216",ptHead+i); i++;
/*2000��-09��*/
	InitBaseItem("20000205",ptHead+i); i++;
	InitBaseItem("20010124",ptHead+i); i++;
	InitBaseItem("20020212",ptHead+i); i++;
	InitBaseItem("20030201",ptHead+i); i++;
	InitBaseItem("20040122",ptHead+i); i++;
	InitBaseItem("20050209",ptHead+i); i++;
	InitBaseItem("20060129",ptHead+i); i++;
	InitBaseItem("20070218",ptHead+i); i++;
	InitBaseItem("20080207",ptHead+i); i++;
	InitBaseItem("20090126",ptHead+i); i++;
/*2010��-19��*/
	InitBaseItem("20100214",ptHead+i); i++;
	InitBaseItem("20110203",ptHead+i); i++;
	InitBaseItem("20120123",ptHead+i); i++;
	InitBaseItem("20130210",ptHead+i); i++;
	InitBaseItem("20140131",ptHead+i); i++;
	InitBaseItem("20150219",ptHead+i); i++;
	InitBaseItem("20160208",ptHead+i); i++;
	InitBaseItem("20170128",ptHead+i); i++;
	InitBaseItem("20180216",ptHead+i); i++;
	InitBaseItem("20190205",ptHead+i); i++;
/*2020��-29��*/
	InitBaseItem("20200125",ptHead+i); i++;
	InitBaseItem("20210212",ptHead+i); i++;
	InitBaseItem("20220201",ptHead+i); i++;
	InitBaseItem("20230122",ptHead+i); i++;
	InitBaseItem("20240210",ptHead+i); i++;
	InitBaseItem("20250129",ptHead+i); i++;
	InitBaseItem("20260217",ptHead+i); i++;
	InitBaseItem("20270206",ptHead+i); i++;
	InitBaseItem("20280126",ptHead+i); i++;
	InitBaseItem("20290213",ptHead+i); i++;
/*2030��-39��*/
	InitBaseItem("20300203",ptHead+i); i++;
	InitBaseItem("20310123",ptHead+i); i++;
	InitBaseItem("20320211",ptHead+i); i++;
	InitBaseItem("20330131",ptHead+i); i++;
	InitBaseItem("20340219",ptHead+i); i++;
	InitBaseItem("20350208",ptHead+i); i++;
	InitBaseItem("20360128",ptHead+i); i++;
	InitBaseItem("20370215",ptHead+i); i++;
	InitBaseItem("20380204",ptHead+i); i++;
	InitBaseItem("20390124",ptHead+i); i++;
/*2040��-49��*/
	InitBaseItem("20400212",ptHead+i); i++;
	InitBaseItem("20410201",ptHead+i); i++;
	InitBaseItem("20420122",ptHead+i); i++;
	InitBaseItem("20430210",ptHead+i); i++;
	InitBaseItem("20440130",ptHead+i); i++;
	InitBaseItem("20450217",ptHead+i); i++;
	InitBaseItem("20460206",ptHead+i); i++;
	InitBaseItem("20470126",ptHead+i); i++;
	InitBaseItem("20480214",ptHead+i); i++;
	InitBaseItem("20490202",ptHead+i); i++;

	InitEndDate(ptHead,i);
	
	return i;
}
struct BaseYearStruct *GetBaseYear(struct BaseYearStruct *ptHead,
	int iTabLen,time_t tTempTime,struct BaseYearStruct **ppList)
{
	static int i=0,j=0,k,l;
	struct BaseYearStruct *pTemp=NULL;
	struct BaseYearStruct *pList=(*ppList);
	
	if(pList==NULL){

		for(i=0;i<iTabLen;i++){
			pTemp=ptHead+i;
			if(tTempTime>=pTemp->tBeginDate&&
				tTempTime<pTemp->tEndDate){
				j=i;
				pList=pTemp;
				break;
			}
		}
		if(j==iTabLen||j==0) return NULL;
		
		k=(iTabLen+1)/2;if(j>k)k=j;
		
		for(i=1;i<k;i++){
			
			l=j+i;
			if(l<iTabLen)
			    InsertList((LIST **)&pList,(LIST*)(ptHead+l));
			l=j-i;
			if(l>=0)
			    InsertList((LIST **)&pList,(LIST*)(ptHead+l));
			
		}
		ReverseList((LIST **)&pList);
		
		*ppList=pList;
		
		return pList;
	}
	pTemp=pList;
	while(pTemp!=NULL){
		if(tTempTime>=pTemp->tBeginDate&&tTempTime<pTemp->tEndDate)
			return pTemp;
		pTemp=pTemp->pNext;
	}
	return NULL;
}
int TicketBasedYearUnit(
	time_t tBeginTime,struct TicketBasedDisctStruct *pTicketBased)
{
	char	sTempDate[15];
	time_t  tYearTime;
	struct BaseYearStruct *pBaseYear;
	
	static int iYearCnt=0,iNianCnt=0;
	static struct BaseYearStruct asBaseYear[100],asBaseNian[100];
	static struct BaseYearStruct *pYear=NULL,*pNian=NULL;

	if(iNianCnt==0) iNianCnt=InitBaseNian(asBaseNian);
	if(iYearCnt==0) iYearCnt=InitBaseYear(asBaseYear);


	if(pTicketBased->iUnitOri==9){/*����*/

		pBaseYear=GetBaseYear(asBaseYear,iYearCnt,tBeginTime,&pYear);
		if(pBaseYear==NULL){
			pTicketBased->iUnit=-1;
			return false;
		}

		if(pTicketBased->tYear!=pBaseYear->tBeginDate){
		
			strncpy(sTempDate,pBaseYear->sBaseDate,8);
			sprintf(sTempDate+4,"%04d000000",pTicketBased->iOffset1);
			/*���������unit,begindate,enddate*/
			pTicketBased->iBeginDate=
				tGetTime(sTempDate)-pBaseYear->tBeginDate;
			pTicketBased->iUnit=
				pBaseYear->tBeginDate-pTicketBased->tBaseTime;
			pTicketBased->iEndDate=
				pTicketBased->iBeginDate+pTicketBased->iDuration1*86400;
			pTicketBased->tYear=pBaseYear->tBeginDate;
		}
	}
	else{		/*����*/
		pBaseYear=GetBaseYear(asBaseNian,iNianCnt,tBeginTime,&pNian);
		if(pBaseYear==NULL){
			pTicketBased->iUnit=-1;
			return false;
		}
		/*���������unit,begindate,enddate*/
		pTicketBased->iUnit=
			pBaseYear->tBeginDate-pTicketBased->tBaseTime;
		pTicketBased->tYear=pBaseYear->tBeginDate;

		if(pTicketBased->iOffset1<0){
			
			if(tBeginTime>=(pBaseYear->tEndDate-864000)){
		
				/*�ӽ�����ģ�����֮��,��ʱ�̿��ܱ���һ�������*/	
				tYearTime=pBaseYear->tEndDate-pBaseYear->tBeginDate;
				pTicketBased->iBeginDate=tYearTime+
					pTicketBased->iOffset1*86400;
			}
			else
				pTicketBased->iBeginDate=pTicketBased->iOffset1*86400;
		}
		else
			pTicketBased->iBeginDate=pTicketBased->iOffset1*86400;
					
		pTicketBased->iEndDate=pTicketBased->iBeginDate+
				pTicketBased->iDuration1*86400;
		
	}
	return true;
}
struct TicketBasedDisctStruct *GetTicketBased(
	struct TicketBasedDisctStruct *pTicketBasedCur,time_t tBeginTime)
{
	int iOffset;
	struct TicketBasedDisctStruct *pTicketBased;


	while(pTicketBasedCur!=NULL){

		pTicketBased=pTicketBasedCur;
		pTicketBasedCur=pTicketBasedCur->pNext;

/*������ЧʧЧʱ��*/
		if(tBeginTime<pTicketBased->tEffDate||
			tBeginTime>=pTicketBased->tExpDate||
			pTicketBased->iUnit==-1) continue;

		if(pTicketBased->tYear!=-1){/*˵��������Ϊ��λ*/
			if(TicketBasedYearUnit(tBeginTime,pTicketBased)!=true)
				continue;
		}
		iOffset=(tBeginTime-pTicketBased->tBaseTime)%pTicketBased->iUnit;

		if(iOffset<pTicketBased->iBeginDate||
			iOffset>=pTicketBased->iEndDate) continue;

		iOffset=iOffset%86400;

		if(iOffset>=pTicketBased->iBeginTime&&
			iOffset<pTicketBased->iEndTime)
			return pTicketBased;
	}
	return NULL;
}
/*	����һ��TIME_SPAN_ITEM�ķ���	*/
int MainTicketBasedDisct(struct TimeSpanStruct *pTimeSpan,
	struct TicketBasedDisctStruct *pTicketBased,
	struct DisctRuleStruct *pDisctRule)
{
	int iDisctFee=0,rp,r;
	int iSecPerCnt,iRate,iTempRate;

	time_t	tTempBegin,tTempEnd;

	struct TicketBasedDisctStruct *pTemp=NULL;
	
	r=	pDisctRule->iRate;
	rp=	pDisctRule->iRatePrecision;
	
	if(pTimeSpan->iMethod==1)
		iRate=GetPrecision(r*pTimeSpan->iRate/1000,rp);
	else
		iRate=pTimeSpan->iRate;

	tTempBegin=	pTimeSpan->tBeginTime;
	tTempEnd=	pTimeSpan->tEndTime;

	iSecPerCnt=pDisctRule->iSecPerCnt;

	do{
		if((pTemp=GetTicketBased(pTicketBased,tTempBegin))==NULL){

			iDisctFee+=iRate;
			tTempBegin+=iSecPerCnt;
			continue;

		}
		iTempRate=GetPrecision(pTemp->iRate*iRate/1000,rp);

		iDisctFee+=iTempRate;
		tTempBegin+=iSecPerCnt;

	}while(tTempBegin<tTempEnd);

	return	iDisctFee;
}
void DisctTimeSpan(struct DisctRuleStruct *p)
{
	int	iDisctFee=0,r,rp,cp,iRate;
	struct TimeSpanControlStruct	*pDisct;
	struct TimeSpanStruct	*pTimeSpan,*pTemp;
	struct TicketBasedDisctStruct	*pTicketBased;

	r=	p->iRate;
	rp=	p->iRatePrecision;
	cp=	p->iCalcPrecision;
	
	pDisct=(struct TimeSpanControlStruct	*)p->pDisct;
	pTimeSpan=	pDisct->pTimeSpan;
	pTicketBased=	pDisct->pTicketBased;

	pTemp=pTimeSpan;
	/*���ɷֽ׶�����*/
	TicketTimeIntersectToTimeSpan(p,&pTemp);

	if(pTicketBased==NULL){/*û��ʱ���Ż�*/

		while(pTemp!=NULL){
		/*Ŀǰֻ֧�ֱ���*/
			if(pTemp->iMethod==1)
				iRate=GetPrecision(r*pTemp->iRate/1000,rp);
			else
				iRate=pTemp->iRate;
			iDisctFee+=pTemp->iCounts*iRate;

			pTemp=pTemp->pNext;
		}
	}
	else{	/*����ʱ���Ż�,DISCT_RULE����ʱ�����*/

		while(pTemp!=NULL){

			iDisctFee+=MainTicketBasedDisct(pTemp,pTicketBased,p);
			pTemp=pTemp->pNext;
		}
	}
	p->iDisctFee=	GetPrecision(p->iFee-iDisctFee,cp);

}
void DisctExpr(struct DisctRuleStruct *p)
{
	p->iDisctFee=	0;
}
void DisctMain(struct TollTariffStruct *ptHead)
{
	struct TollTariffStruct *pTemp;
	struct DisctRuleStruct	*pDisctRule,*ptPre,*ptCur;

	while(ptHead!=NULL){
		pTemp=ptHead;
		while(pTemp!=NULL){
			/*����ʷ�����*/
			pDisctRule=GetDisctRuleList(pTemp->iTariffID,pTemp->iSeqNbr);
			/*ɾ������Ļ�������*/
			MutexDisctRule(&pDisctRule);
			/*��ʼ���Żݹ���ɾ��ʱ���޽�������*/
			TicketTimeIntersectToDisct(pTemp->tBeginTime,
				pTemp->tEndTime,pTemp->iSecPerCnt,pTemp->iRate,
				pTemp->iRatePrecision,pTemp->iCalcPrecision,
				&pDisctRule);
			/*ִ�������ѭ��*/
			ptCur=pDisctRule;
			while(ptCur!=NULL){
				ptPre=ptCur;
				ptCur=ptCur->pNext;
				ptPre->Disct(ptPre);
			}
			GetCalcDisct(pDisctRule,&(pTemp->iDisctFee));
			pTemp=pTemp->pNext;
		}
		ptHead=ptHead->pTariffNext;
	}
}

struct TollTariffStruct *GetTariffList(int iTicketTypeID,char sFieldType[],
	char sTariffType[])
{
	struct TollTariffStruct *pTollTariff=NULL,*p,*pt;
	struct TicketTypeTariffStruct *ptHead=NULL,*pTemp;

	if(SearchTicketTypeTariff(iTicketTypeID,&ptHead)!=FOUND)
		return NULL;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
			
		if((pt=PTOLLTARIFF(pTemp->iTariffID))==NULL) continue;
		if(strcmp(pt->sFieldType,sFieldType)!=0) continue;
		if(strcmp(pt->sTariffType,sTariffType)!=0) continue;
		
		while(pt!=NULL){
			p=pt;pt=pt->pSeqNext;

			p->iFee=p->iDisctFee=	0;
			p->iAcctItemTypeID=	pTemp->iAcctItemTypeID;;
			p->iTicketItemTypeID=	pTemp->iAcctItemTypeID;;
			p->pNext=p->pTariffNext=NULL;

			InsertListSort((LIST**)&pTollTariff,(LIST*)p,
				comp_toll_tariff_list);
		}
	}
	return pTollTariff;
}
