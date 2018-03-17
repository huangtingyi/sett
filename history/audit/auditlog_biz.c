#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <gen_supp.h>
#include <param_intf.h>
#include "base_supp.h"
#include "dbsupp.h"
#include "stt_ticket.h"
#include "auditlog_supp.h"

extern struct PickLogStruct *pPickLog;
extern struct PrepLogStruct *pPrepLog;
extern struct PrepProcLogStruct *pPrepProcLog;
extern struct BillingLogStruct *pBillingLog;
extern struct BillingProcLogStruct *pBillingProcLog;
extern struct AcctLogStruct *pInsertLog;
extern struct AcctLogStruct *pAcctLog;
extern struct UpdataProcLogStruct *pUpdataProcLog;
extern struct UpdataLogStruct *pUpdataLog;
extern struct LogAuditStruct *pLogAll;            
extern struct LogAuditDetailStruct *pLogDetailAll;

void MakePickPrepProcNode(struct PickLogStruct *pSource,
	struct PrepProcLogStruct *pTarget)
{
	bzero((void*)pTarget,sizeof(struct PrepProcLogStruct));
	strcpy(pTarget->sFileName,pSource->sFileName);
}

void MakePrepBillingProcNode(struct PrepLogStruct *pSource,
	struct BillingProcLogStruct *pTarget)
{
	bzero((void*)pTarget,sizeof(struct BillingProcLogStruct));
	strcpy(pTarget->sFileName,pSource->sFileName);
}

void MakeBillingAcctNode(struct BillingLogStruct *pSource,
	struct AcctLogStruct *pTarget)
{
	bzero((void*)pTarget,sizeof(struct AcctLogStruct));
	strcpy(pTarget->sFileName,pSource->sFileName);
}

void MakePrepInsertNode(struct PrepLogStruct *pSource,
	struct AcctLogStruct *pTarget)
{
	bzero((void*)pTarget,sizeof(struct AcctLogStruct));
	strcpy(pTarget->sFileName,pSource->sFileName);
}

void MakeBillingUpdataProcNode(struct BillingLogStruct *pSource,
	struct UpdataProcLogStruct *pTarget)
{
	bzero((void*)pTarget,sizeof(struct AcctLogStruct));
	strcpy(pTarget->sOriFileName,pSource->sFileName);
}

void MakeUpdataAcctNode(struct UpdataLogStruct *pSource,
	struct AcctLogStruct *pTarget)
{
	bzero((void*)pTarget,sizeof(struct AcctLogStruct));
	strcpy(pTarget->sFileName,pSource->sFileName);
}

int comp_search_list_prep_proc_log_e(void *pValue,LIST*pHead)
{
	struct PrepProcLogStruct *pSource=(struct PrepProcLogStruct *)pValue;
	struct PrepProcLogStruct *pTarget=(struct PrepProcLogStruct *)pHead;
	int res=0;

	if((res=strcmp(pSource->sFileName,pTarget->sFileName))!=0)
		return res;

	return res;
}

int comp_search_list_billing_proc_log_e(void *pValue,LIST*pHead)
{
	struct BillingProcLogStruct *pSource=(struct BillingProcLogStruct *)pValue;
	struct BillingProcLogStruct *pTarget=(struct BillingProcLogStruct *)pHead;
	int res=0;

	if((res=strcmp(pSource->sFileName,pTarget->sFileName))!=0)
		return res;

	return res;
}

int comp_search_list_acct_log_e(void *pValue,LIST*pHead)
{
	struct AcctLogStruct *pSource=(struct AcctLogStruct *)pValue;
	struct AcctLogStruct *pTarget=(struct AcctLogStruct *)pHead;
	int res=0;

	if((res=strcmp(pSource->sFileName,pTarget->sFileName))!=0)
		return res;

	return res;
}

int comp_search_list_updata_proc_log_e(void *pValue,LIST*pHead)
{
	struct UpdataProcLogStruct *pSource=(struct UpdataProcLogStruct *)pValue;
	struct UpdataProcLogStruct *pTarget=(struct UpdataProcLogStruct *)pHead;
	int res=0;

	if((res=strcmp(pSource->sOriFileName,pTarget->sOriFileName))!=0)
		return res;

	return res;
}

/*PICK-PREP,�ļ���С��һ��*/
void AuditPickPrepType1(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct PickLogStruct *pPickRec,
	struct PrepProcLogStruct *pPrepProcRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pPrepProcRec->iTacheID;
	strcpy(pLogDetail->sSourceID,	pPickRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pPickRec->sFileName);
	pLogDetail->iByte=		pPickRec->iByte;
	strcpy(pLogDetail->sType,"1");/*�ļ���С��һ��*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	"");
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

/*PICK-PREP,δ�����ļ�*/
void AuditPickPrepType2(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct PickLogStruct *pPickRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pPickRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pPickRec->sFileName);
	pLogDetail->iByte=		pPickRec->iByte;
	strcpy(pLogDetail->sType,	"2");/*�ļ�δ����*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	"");
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

void AuditPickPrep(struct AuditParamStruct *pAuditParam)
{
	struct PickLogStruct *ptCur,*ptPre;
	struct PrepProcLogStruct SearchTemp,*pTemp=NULL;
	struct LogAuditDetailStruct *pLogDetailTemp;

	ptCur=pPickLog;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		MakePickPrepProcNode(ptPre,&SearchTemp);

		if(SearchList((LIST*)pPrepProcLog,(void*)&SearchTemp,(LIST**)&pTemp,
			comp_search_list_prep_proc_log_e)==NOTFOUND){

			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditPickPrepType2(pLogDetailTemp,pAuditParam,ptPre);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
		else if(ptPre->iByte!=pTemp->iByte){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditPickPrepType1(pLogDetailTemp,pAuditParam,ptPre,pTemp);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);
		}
	}
}


/*PREP-BILLING,�ļ���С��һ��*/
void AuditPrepBillingType1(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct PrepLogStruct *pPrepRec,
	struct BillingProcLogStruct *pBillingProcRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pPrepRec->iTacheID;
	pLogDetail->iTacheID=		pBillingProcRec->iTacheID;
	strcpy(pLogDetail->sSourceID,	pPrepRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pPrepRec->sFileName);
	pLogDetail->iByte=		pBillingProcRec->iByte;
	pLogDetail->iCnt=		pPrepRec->iCnt;
	strcpy(pLogDetail->sType,	"1");/*�ļ���¼����һ��*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pPrepRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

/*PREP-BILLING,δ�����ļ�*/
void AuditPrepBillingType2(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct PrepLogStruct *pPrepRec)
{
	pLogDetail->iFlowID=pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,pPrepRec->sSourceID);
	strcpy(pLogDetail->sFileName,pPrepRec->sFileName);
	/*pLogDetail->iByte=0;*/
	pLogDetail->iCnt=pPrepRec->iCnt;
	strcpy(pLogDetail->sType,"2");/*�ļ�δ����*/
	strcpy(pLogDetail->sBeginDate,pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,pPrepRec->sDataDate);
	pLogDetail->iStaffID=pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,pAuditParam->sSerialNbr);
}

void AuditPrepBilling(struct AuditParamStruct *pAuditParam)
{
	struct PrepLogStruct *ptCur,*ptPre;
	struct BillingProcLogStruct SearchTemp,*pTemp=NULL;
	struct LogAuditDetailStruct *pLogDetailTemp;

	ptCur=pPrepLog;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		MakePrepBillingProcNode(ptPre,&SearchTemp);
		/*û�ҵ����û��ڵĶ�Ӧ�ڵ㣬�ļ�δ����*/
		if(SearchList((LIST*)pBillingProcLog,(void*)&SearchTemp,(LIST**)&pTemp,
			comp_search_list_billing_proc_log_e)==NOTFOUND){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditPrepBillingType2(pLogDetailTemp,pAuditParam,ptPre);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
		/*�ļ���¼����һ��*/
		else if(ptPre->iCnt!=pTemp->iCnt){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditPrepBillingType1(pLogDetailTemp,pAuditParam,ptPre,pTemp);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);
		}
	}
}

/*BILLING-INSERT,�ļ���С��һ��*/
void AuditBillingInsertType1(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct BillingLogStruct *pBillingRec,
	struct AcctLogStruct *pInsertRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pBillingRec->iTacheID;
	pLogDetail->iTacheID=		pInsertRec->iTacheID;
	strcpy(pLogDetail->sSourceID,	pBillingRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pBillingRec->sFileName);
	pLogDetail->iByte=		pInsertRec->iByte;
	pLogDetail->iCnt=		pBillingRec->iCnt;
	strcpy(pLogDetail->sType,	"1");/*�ļ���¼����һ��*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pInsertRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

/*BILLING-INSERT,δ�����ļ�*/
void AuditBillingInsertType2(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct BillingLogStruct *pBillingRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pBillingRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pBillingRec->sFileName);
	/*pLogDetail->iByte=		pBillingRec->iByte;*/
	pLogDetail->iCnt=		pBillingRec->iCnt;
	strcpy(pLogDetail->sType,	"2");/*�ļ�δ����*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pBillingRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

void AuditBillingInsert(struct AuditParamStruct *pAuditParam)
{
	struct BillingLogStruct *ptCur,*ptPre;
	struct AcctLogStruct SearchTemp,*pTemp=NULL;
	struct LogAuditDetailStruct *pLogDetailTemp;

	ptCur=pBillingLog;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		MakeBillingAcctNode(ptPre,&SearchTemp);
		/*û�ҵ����û��ڵĶ�Ӧ�ڵ㣬�ļ�δ����*/
		if(SearchList((LIST*)pInsertLog,(void*)&SearchTemp,(LIST**)&pTemp,
			comp_search_list_acct_log_e)==NOTFOUND){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditBillingInsertType2(pLogDetailTemp,pAuditParam,ptPre);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
		/*�ļ���¼����һ��*/
		else if(ptPre->iCnt!=pTemp->iCnt){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditBillingInsertType1(pLogDetailTemp,pAuditParam,ptPre,pTemp);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);
		}
	}
}

/*PREP-INSERT,�ļ���С��һ��*/
void AuditPrepInsertType1(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct PrepLogStruct *pPrepRec,
	struct AcctLogStruct *pInsertRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pPrepRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pPrepRec->sFileName);
	pLogDetail->iByte=		pInsertRec->iByte;
	pLogDetail->iCnt=		pPrepRec->iCnt;
	strcpy(pLogDetail->sType,	"1");/*�ļ���¼����һ��*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pInsertRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

/*PREP-INSERT,δ�����ļ�*/
void AuditPrepInsertType2(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct PrepLogStruct *pPrepRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pPrepRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pPrepRec->sFileName);
	/*pLogDetail->iByte=		pPrepRec->iByte;*/
	pLogDetail->iCnt=		pPrepRec->iCnt;
	strcpy(pLogDetail->sType,	"2");/*�ļ�δ����*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pPrepRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

void AuditPrepInsert(struct AuditParamStruct *pAuditParam)
{
	struct PrepLogStruct *ptCur,*ptPre;
	struct AcctLogStruct SearchTemp,*pTemp=NULL;
	struct LogAuditDetailStruct *pLogDetailTemp;

	ptCur=pPrepLog;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		MakePrepInsertNode(ptPre,&SearchTemp);
		/*û�ҵ����û��ڵĶ�Ӧ�ڵ㣬�ļ�δ����*/
		if(SearchList((LIST*)pInsertLog,(void*)&SearchTemp,(LIST**)&pTemp,
			comp_search_list_acct_log_e)==NOTFOUND){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditPrepInsertType2(pLogDetailTemp,pAuditParam,ptPre);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
		/*�ļ���¼����һ��*/
		else if(ptPre->iCnt!=pTemp->iCnt){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditPrepInsertType1(pLogDetailTemp,pAuditParam,ptPre,pTemp);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
	}
}

/*BILLING--ACCT,�ļ���С��һ��*/
void AuditBillingAcctType1(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct BillingLogStruct *pBillingRec,
	struct AcctLogStruct *pAcctRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pBillingRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pBillingRec->sFileName);
	pLogDetail->iByte=		pAcctRec->iByte;
	pLogDetail->iCnt=		pBillingRec->iCnt;
	strcpy(pLogDetail->sType,	"1");/*�ļ���¼����һ��*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pAcctRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

/*BILLING--ACCT,δ�����ļ�*/
void AuditBillingAcctType2(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct BillingLogStruct *pBillingRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pBillingRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pBillingRec->sFileName);
	/*pLogDetail->iByte=		pBillingRec->iByte;*/
	pLogDetail->iCnt=		pBillingRec->iCnt;
	strcpy(pLogDetail->sType,	"2");/*�ļ�δ����*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pBillingRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

void AuditBillingAcct(struct AuditParamStruct *pAuditParam)
{
	struct BillingLogStruct *ptCur,*ptPre;
	struct AcctLogStruct SearchTemp,*pTemp=NULL;
	struct LogAuditDetailStruct *pLogDetailTemp;

	ptCur=pBillingLog;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		MakeBillingAcctNode(ptPre,&SearchTemp);
		/*û�ҵ����û��ڵĶ�Ӧ�ڵ㣬�ļ�δ����*/
		if(SearchList((LIST*)pAcctLog,(void*)&SearchTemp,(LIST**)&pTemp,
			comp_search_list_acct_log_e)==NOTFOUND){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditBillingAcctType2(pLogDetailTemp,pAuditParam,ptPre);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
		/*�ļ���¼����һ��*/
		else if(ptPre->iCnt!=pTemp->iCnt){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditBillingAcctType1(pLogDetailTemp,pAuditParam,ptPre,pTemp);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);
		}
	}
}

/*BILLING--UPDATA,�ļ���С��һ��*/
void AuditBillingUpdataType1(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct BillingLogStruct *pBillingRec,
	struct UpdataProcLogStruct *pUpdataProcRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pBillingRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pBillingRec->sFileName);
	pLogDetail->iByte=		pUpdataProcRec->iByte;
	pLogDetail->iCnt=		pUpdataProcRec->iRecCnt;
	strcpy(pLogDetail->sType,	"1");/*�ļ���¼����һ��*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pUpdataProcRec->sFileDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

/*BILLING--UPDATA,δ�����ļ�*/
void AuditBillingUpdataType2(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct BillingLogStruct *pBillingRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pBillingRec->sSourceID);
	strcpy(pLogDetail->sFileName,	pBillingRec->sFileName);
	/*pLogDetail->iByte=		pBillingRec->iByte;*/
	pLogDetail->iCnt=		pBillingRec->iCnt;
	strcpy(pLogDetail->sType,	"2");/*�ļ�δ����*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pBillingRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

void AuditBillingUpdata(struct AuditParamStruct *pAuditParam)
{
	struct BillingLogStruct *ptCur,*ptPre;
	struct UpdataProcLogStruct SearchTemp,*pTemp=NULL;
	struct LogAuditDetailStruct *pLogDetailTemp;

	ptCur=pBillingLog;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		MakeBillingUpdataProcNode(ptPre,&SearchTemp);
		/*û�ҵ����û��ڵĶ�Ӧ�ڵ㣬�ļ�δ����*/
		if(SearchList((LIST*)pUpdataProcLog,(void*)&SearchTemp,(LIST**)&pTemp,
			comp_search_list_updata_proc_log_e)==NOTFOUND){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditBillingUpdataType2(pLogDetailTemp,pAuditParam,ptPre);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
		/*�ļ���¼����һ��*/
		else if(ptPre->iCnt!=pTemp->iRecCnt){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditBillingUpdataType1(pLogDetailTemp,pAuditParam,ptPre,pTemp);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);
		}
	}
}

/*UPDATA_INTF-->ACCT,�ļ���С��һ��*/
void AuditUpdataAcctType1(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct UpdataLogStruct *pUpdataRec,
	struct AcctLogStruct *pAcctRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pAuditParam->sSourceID);
	strcpy(pLogDetail->sFileName,	pUpdataRec->sFileName);
	pLogDetail->iByte=		pAcctRec->iByte;
	pLogDetail->iCnt=		pAcctRec->iCnt;
	strcpy(pLogDetail->sType,	"1");/*�ļ���¼����һ��*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pAcctRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

/*UPDATA_INTF-->ACCT,δ�����ļ�*/
void AuditUpdataAcctType2(struct LogAuditDetailStruct *pLogDetail,
	struct AuditParamStruct *pAuditParam,struct UpdataLogStruct *pUpdataRec)
{
	pLogDetail->iFlowID=		pAuditParam->iFlowID;
	pLogDetail->iPreTacheID=	pAuditParam->iPreTacheID;
	pLogDetail->iTacheID=		pAuditParam->iTacheID;
	strcpy(pLogDetail->sSourceID,	pAuditParam->sSourceID);
	strcpy(pLogDetail->sFileName,	pUpdataRec->sFileName);
	/*pLogDetail->iByte=		pUpdataRec->iByte;*/
	pLogDetail->iCnt=		pUpdataRec->iRecCnt;
	strcpy(pLogDetail->sType,	"2");/*�ļ�δ����*/
	strcpy(pLogDetail->sBeginDate,	pAuditParam->sBeginDate);
	strcpy(pLogDetail->sEndDate,	pAuditParam->sEndDate);
	strcpy(pLogDetail->sDataDate,	pUpdataRec->sDataDate);
	pLogDetail->iStaffID=		pAuditParam->iStaffID;
	strcpy(pLogDetail->sSerialNbr,	pAuditParam->sSerialNbr);
}

void AuditUpdataAcct(struct AuditParamStruct *pAuditParam)
{
	struct UpdataLogStruct *ptCur,*ptPre;
	struct AcctLogStruct SearchTemp,*pTemp=NULL;
	struct LogAuditDetailStruct *pLogDetailTemp;

	ptCur=pUpdataLog;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		MakeUpdataAcctNode(ptPre,&SearchTemp);
		/*û�ҵ����û��ڵĶ�Ӧ�ڵ㣬�ļ�δ����*/
		if(SearchList((LIST*)pAcctLog,(void*)&SearchTemp,(LIST**)&pTemp,
			comp_search_list_acct_log_e)==NOTFOUND){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditUpdataAcctType2(pLogDetailTemp,pAuditParam,ptPre);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);

		}
		/*�ļ���¼����һ��*/
		else if(ptPre->iRecCnt!=pTemp->iCnt){
			if((pLogDetailTemp=malloc(sizeof(struct LogAuditDetailStruct)))==NULL){
				WriteAlertMsg("�����ڴ� LogAuditDetailStruct ����");
				exit (1);
			}
			bzero((void*)pLogDetailTemp,sizeof(struct LogAuditDetailStruct));
			AuditUpdataAcctType1(pLogDetailTemp,pAuditParam,ptPre,pTemp);
			InsertList((LIST**)&pLogDetailAll,(LIST*)pLogDetailTemp);
		}
	}
}
