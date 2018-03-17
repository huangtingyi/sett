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
#include <param_intf.h>
#include "base_supp.h"
#include "dbsupp.h"
#include "stt_ticket.h"
#include "auditlog_supp.h"

int iCntAudit=0;/*ǰ�û����ܼ�¼��*/
struct PickLogStruct *pPickLog=NULL;
struct PrepLogStruct *pPrepLog=NULL;
struct PrepProcLogStruct *pPrepProcLog=NULL;
struct BillingLogStruct *pBillingLog=NULL;
struct BillingProcLogStruct *pBillingProcLog=NULL;
struct AcctLogStruct *pInsertLog=NULL;
struct AcctLogStruct *pAcctLog=NULL;
struct UpdataProcLogStruct *pUpdataProcLog=NULL;
struct UpdataLogStruct *pUpdataLog=NULL;
struct LogAuditStruct *pLogAll=NULL;
struct LogAuditDetailStruct *pLogDetailAll=NULL;

/*
auditverify.sh  �������(type) ������(serial_nbr) ���̱�ʶ(flow_id)  ǰ�û��ڱ�ʶ(pre_tache_id) ���ڱ�ʶ(tache_id) ����Դ(source_id) ��ʼʱ��(startDate) ����ʱ��(endDate) ��������(staffId)
*/

int comp_search_list_flow_tache_appid_e(void *pValue,LIST*pData)
{
	int res=0;
	struct FlowTacheStruct *pSource=(struct FlowTacheStruct *)pValue;
	struct FlowTacheStruct *pTarget=(struct FlowTacheStruct *)pData;

	if((res=pSource->iFlowID-pTarget->iFlowID)!=0) return res;
	return pSource->iTacheID-pTarget->iTacheID;
}

int GetAppID(int iFlowID,int iTacheID,
	struct FlowTacheStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct FlowTacheStruct *p=NULL,Temp;
	static struct FlowTacheStruct *pFlowTache=NULL;

	static struct FileControlStruct *pControl=NULL;

	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}

	if(iFirstFlag==true){

		struct FileControlStruct *pList=NULL,*pTemp;

		if(MoveTableShmToList("FLOW_TACHE",&pList)<0){
			WriteAlertMsg("���ʹ����ڴ��FLOW_TACHEʧ��");
			return -1;
		}
		pControl=pList;
		
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			p=(struct FlowTacheStruct *)(pTemp->pData);
			InsertList((LIST **)&pFlowTache,(LIST *)p);
		}
	
		
		iFirstFlag=false;
	}

	Temp.iFlowID=iFlowID;
	Temp.iTacheID=iTacheID;
	
	return SearchList((LIST*)pFlowTache,(void*)&Temp,(LIST**)pptCur,
		comp_search_list_flow_tache_appid_e);	
}

int GetTacheAppLog(struct AuditParamStruct *pAuditParam)
{
	struct FlowTacheStruct *pPreFlowTache=NULL,*pFlowTache=NULL;

	if(GetAppID(pAuditParam->iFlowID,pAuditParam->iPreTacheID,&pPreFlowTache)
		==NOTFOUND){
		WriteAlertMsg("����FLOW_TACHE����ʧ��");
		return -1;
	}
	if(GetAppID(pAuditParam->iFlowID,pAuditParam->iTacheID,&pFlowTache)
		==NOTFOUND){
		WriteAlertMsg("����FLOW_TACHE����ʧ��");
		return -1;
	}
	if(strncmp(pPreFlowTache->sAppID,"PICK",4)==0&&
		strncmp(pFlowTache->sAppID,"PREP",4)==0){
		strcpy(pAuditParam->sPreAppLog,"PICK_LOG");
		strcpy(pAuditParam->sAppLog,"PREP_PROC_LOG");
	}
	else if(strncmp(pPreFlowTache->sAppID,"PREP",4)==0&&
		strncmp(pFlowTache->sAppID,"BILLING",7)==0){
		strcpy(pAuditParam->sPreAppLog,"PREP_LOG");
		strcpy(pAuditParam->sAppLog,"BILLING_PROC_LOG");
	}
	else if(strncmp(pPreFlowTache->sAppID,"PREP",4)==0&&
		strncmp(pFlowTache->sAppID,"RATE",4)==0){
		strcpy(pAuditParam->sPreAppLog,"PREP_LOG");
		strcpy(pAuditParam->sAppLog,"BILLING_PROC_LOG");
	}
	else if(strncmp(pPreFlowTache->sAppID,"PREP",4)==0&&
		strncmp(pFlowTache->sAppID,"INST",4)==0){
		strcpy(pAuditParam->sPreAppLog,"PREP_LOG");
		strcpy(pAuditParam->sAppLog,"INSERT_LOG");
	}
	else if (strncmp(pPreFlowTache->sAppID,"BILLING",7)==0&&
		strncmp(pFlowTache->sAppID,"INST",4)==0){
		strcpy(pAuditParam->sPreAppLog,"BILLING_LOG");
		strcpy(pAuditParam->sAppLog,"INSERT_LOG");
	}
	/*�ӱ����������
	else if (strncmp(pPreFlowTache->sAppID,"BILLING",7)==0&&
		strncmp(pFlowTache->sAppID,"RATE",4)==0){
		strcpy(pAuditParam->sPreAppLog,"BILLING_LOG");
		strcpy(pAuditParam->sAppLog,"BILLING_PROC_LOG");
	}
	*/
	else if (strncmp(pPreFlowTache->sAppID,"RATE",4)==0&&
		strncmp(pFlowTache->sAppID,"INST",4)==0){
		strcpy(pAuditParam->sPreAppLog,"BILLING_LOG");
		strcpy(pAuditParam->sAppLog,"INSERT_LOG");
	}
	else if (strncmp(pPreFlowTache->sAppID,"BILLING",7)==0&&
		strncmp(pFlowTache->sAppID,"ACCT",4)==0){
		strcpy(pAuditParam->sPreAppLog,"BILLING_LOG");
		strcpy(pAuditParam->sAppLog,"ACCT_LOG");
	}
	else if (strncmp(pPreFlowTache->sAppID,"RATE",4)==0&&
		strncmp(pFlowTache->sAppID,"ACCT",4)==0){
		strcpy(pAuditParam->sPreAppLog,"BILLING_LOG");
		strcpy(pAuditParam->sAppLog,"ACCT_LOG");
	}
	else if (strncmp(pPreFlowTache->sAppID,"RATE",4)==0&&
		strncmp(pFlowTache->sAppID,"UPDATA",6)==0){
		strcpy(pAuditParam->sPreAppLog,"BILLING_LOG");
		strcpy(pAuditParam->sAppLog,"UPDATA_PROC_LOG");
	}
	else if (strncmp(pPreFlowTache->sAppID,"BILLING",7)==0&&
		strncmp(pFlowTache->sAppID,"UPDATA",6)==0){
		strcpy(pAuditParam->sPreAppLog,"BILLING_LOG");
		strcpy(pAuditParam->sAppLog,"UPDATA_PROC_LOG");
	}
	else if (strncmp(pPreFlowTache->sAppID,"UPDATA",6)==0&&
		strncmp(pFlowTache->sAppID,"ACCT",4)==0){
		strcpy(pAuditParam->sPreAppLog,"UPDATA_LOG");
		strcpy(pAuditParam->sAppLog,"ACCT_LOG");
	}
	else{
		WriteAlertMsg("��ѯ���̳���.\n");
		return -1;
	}

	return 0;
}

void GetCondition(struct AuditParamStruct *pAuditParam,char sPreAppCondition[],
	char sAppCondition[])
{
	/*Ĭ�ϣ�ȡdata_date*/
	sprintf(sPreAppCondition,"WHERE SOURCE_ID='%s'\n\
		AND to_char(DATA_DATE,'yyyymmdd')>='%s'\n\
		AND to_char(DATA_DATE,'yyyymmdd')<='%s'",
		pAuditParam->sSourceID,pAuditParam->sBeginDate,pAuditParam->sEndDate);
	sprintf(sAppCondition,"WHERE  SOURCE_ID='%s'\n\
		AND to_char(DATA_DATE,'yyyymmdd')>='%s'\n\
		AND to_char(DATA_DATE,'yyyymmdd')<='%s'",
		pAuditParam->sSourceID,pAuditParam->sBeginDate,pAuditParam->sEndDate);
	/*���⴦��*/
	/*ǰ�û���Ϊpick,�޷��ж��������ڣ����û�����ȫ����������*/
	if(strncmp(pAuditParam->sPreAppLog,"PICK",4)==0){
		sprintf(sPreAppCondition,"WHERE SOURCE_ID='%s'\n\
			AND to_char(DEAL_END_DATE,'yyyymmdd')>='%s'\n\
			AND to_char(DEAL_END_DATE,'yyyymmdd')<='%s'",
			pAuditParam->sSourceID,pAuditParam->sBeginDate,
			pAuditParam->sEndDate);
		sprintf(sAppCondition,"WHERE SOURCE_ID='%s'",
			pAuditParam->sSourceID);	
	}
	if(strncmp(pAuditParam->sAppLog,"BILLING_PROC_LOG",16)==0){
		sprintf(sAppCondition,"WHERE SOURCE_ID='%s'",
			pAuditParam->sSourceID);	
	}
	/*��������*/
	if(strncmp(pAuditParam->sPreAppLog,"BILLING_LOG",11)==0&&
		strncmp(pAuditParam->sAppLog,"ACCT_LOG",8)==0){
		sprintf(sPreAppCondition,"WHERE SOURCE_ID='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')>='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')<='%s'\n\
			AND FILE_NAME NOT LIKE '%%.X'",			
			pAuditParam->sSourceID,pAuditParam->sBeginDate,
			pAuditParam->sEndDate);
		sprintf(sAppCondition,"WHERE SOURCE_ID='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')>='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')<='%s'\n\
			AND FILE_NAME NOT LIKE '%%.X'",
			pAuditParam->sSourceID,pAuditParam->sBeginDate,
			pAuditParam->sEndDate);	
	}
	/*BILLING->UPDATA_INTF,updata_proc_logȡFILE_DATE*/
	if(strncmp(pAuditParam->sAppLog,"UPDATA_PROC_LOG",16)==0){
		sprintf(sPreAppCondition,"WHERE SOURCE_ID='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')>='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')<='%s'\n\
			AND FILE_NAME NOT LIKE '%%.X'",			
			pAuditParam->sSourceID,pAuditParam->sBeginDate,
			pAuditParam->sEndDate);
		sprintf(sAppCondition,"WHERE SUBSTR(ORI_FILE_NAME,1,6)='%s'",
			pAuditParam->sSourceID);	
	}
	/*UPDATA_INTF->ACCT*/
	if(strncmp(pAuditParam->sPreAppLog,"UPDATA_LOG",10)==0 &&
		strncmp(pAuditParam->sAppLog,"ACCT_LOG",8)==0){
		sprintf(sPreAppCondition,"WHERE SUBSTR(FILE_NAME,1,6)='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')>='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')<='%s'\n\
			AND FILE_NAME NOT LIKE '%%.X'",			
			pAuditParam->sSourceID,pAuditParam->sBeginDate,
			pAuditParam->sEndDate);
		sprintf(sAppCondition,"WHERE SOURCE_ID='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')>='%s'\n\
			AND to_char(DATA_DATE,'yyyymmdd')<='%s'\n\
			AND FILE_NAME NOT LIKE '%%.X'",			
			pAuditParam->sSourceID,pAuditParam->sBeginDate,
			pAuditParam->sEndDate);	
	}	
}

int MountLog(char sAppLog[],char sCondition[],int *pCnt)
{
	if(strncmp(sAppLog,"PICK_LOG",8)==0&&
		(*pCnt=MountPickLog(&pPickLog,sCondition))<0){
		WriteAlertMsg("����PICK_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"PREP_LOG",8)==0&&
		(*pCnt=MountPrepLog(&pPrepLog,sCondition))<0){
		WriteAlertMsg("����PREP_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"PREP_PROC_LOG",8)==0&&
		(*pCnt=MountPrepProcLog(&pPrepProcLog,sCondition))<0){
		WriteAlertMsg("����PREP_PROC_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"BILLING_LOG",11)==0&&
		(*pCnt=MountBillingLog(&pBillingLog,sCondition))<0){
		WriteAlertMsg("����BILLING_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"BILLING_PROC_LOG",16)==0&&
		(*pCnt=MountBillingProcLog(&pBillingProcLog,sCondition))<0){
		WriteAlertMsg("����BILLING_PROC_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"INSERT_LOG",10)==0&&
		(*pCnt=MountAcctLog(&pInsertLog,"INSERT_LOG",sCondition))<0){
		WriteAlertMsg("����INSERT_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"ACCT_LOG",8)==0&&
		(*pCnt=MountAcctLog(&pAcctLog,"ACCT_LOG",sCondition))<0){
		WriteAlertMsg("����ACCT_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"UPDATA_PROC_LOG",8)==0&&
		(*pCnt=MountUpdataProcLog(&pUpdataProcLog,sCondition))<0){
		WriteAlertMsg("����UPDATA_RPOC_LOGʧ��");
		return -1;
	}
	if(strncmp(sAppLog,"UPDATA_LOG",8)==0&&
		(*pCnt=MountUpdataLog(&pUpdataLog,sCondition))<0){
		WriteAlertMsg("����UPDATA_LOGʧ��");
		return -1;
	}
	return 0;
}

int MountTacheAppLog(struct AuditParamStruct *pAuditParam)
{
	int iCnt;
	char sPreAppCondition[512],sAppCondition[512];
	if(GetTacheAppLog(pAuditParam)<0)
		return -1;
	GetCondition(pAuditParam,sPreAppCondition,sAppCondition);
/*
	printf("sPreAppLog=%s\n",pAuditParam->sPreAppLog);
	printf("sPreAppCondition=%s\n",sPreAppCondition);
	printf("sAppLog=%s\n",pAuditParam->sAppLog);
	printf("sAppCondition=%s\n",sAppCondition);
*/
	if(MountLog(pAuditParam->sPreAppLog,sPreAppCondition,&iCnt)<0)return -1;
	iCntAudit=iCnt;
	if(MountLog(pAuditParam->sAppLog,sAppCondition,&iCnt)<0)return -1;

	return 0;
}

int comp_insert_list_stat_audit_e(LIST *pValue,LIST*pHead)
{
	int res=0;
	struct LogAuditStruct *pSource=(struct LogAuditStruct *)pValue;
	struct LogAuditStruct *pTarget=(struct LogAuditStruct *)pHead;

	if((res=pSource->iFlowID-pTarget->iFlowID)!=0) return res;
	if((res=pSource->iPreTacheID-pTarget->iPreTacheID)!=0) return res;
	if((res=pSource->iTacheID-pTarget->iTacheID)!=0) return res;
	if((res=strcmp(pSource->sType,pTarget->sType))!=0)
		return res;
	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0)
		return res;
	if((res=strcmp(pSource->sBeginDate,pTarget->sBeginDate))!=0)
		return res;
	if((res=strcmp(pSource->sEndDate,pTarget->sEndDate))!=0)
		return res;
	if((res=strcmp(pSource->sDataDate,pTarget->sDataDate))!=0)
		return res;
	if((res=pSource->iStaffID-pTarget->iStaffID)!=0) return res;
	if((res=strcmp(pSource->sSerialNbr,pTarget->sSerialNbr))!=0)
		return res;
	return res;
}

void sum_list_stat_audit_e(LIST *pHead,LIST*pValue)
{
	struct LogAuditStruct *pSource=(struct LogAuditStruct *)pValue;
	struct LogAuditStruct *pTarget=(struct LogAuditStruct *)pHead;

	pTarget->iAbnoCnt+=1;
	free(pSource);
}

void MakeCompNode(struct LogAuditDetailStruct *pSource,
	struct LogAuditStruct *pTarget)
{
	pTarget->iFlowID	=pSource->iFlowID		;
	pTarget->iPreTacheID	=pSource->iPreTacheID		;
	pTarget->iTacheID	=pSource->iTacheID		;
	strcpy(pTarget->sType,		pSource->sType);
	strcpy(pTarget->sSourceID,	pSource->sSourceID	);
	pTarget->iCnt=iCntAudit;
	pTarget->iAbnoCnt=1;
	strcpy(pTarget->sBeginDate,	pSource->sBeginDate	);
	strcpy(pTarget->sEndDate,	pSource->sEndDate	);
	strcpy(pTarget->sDataDate,	pSource->sDataDate	);
	pTarget->iStaffID	=pSource->iStaffID		;
	strcpy(pTarget->sSerialNbr,	pSource->sSerialNbr	);
}

int StatAudit(LIST *pData)
{
	struct LogAuditDetailStruct *pTemp=(struct LogAuditDetailStruct *)pData;
	struct LogAuditStruct *pCompTemp;
	if((pCompTemp=(struct LogAuditStruct*)
		malloc(sizeof(struct LogAuditStruct)))==NULL){
		WriteAlertMsg("�����ڴ� struct LogAuditStruct ʧ��.\n");
		return -1;
	}
	bzero((void*)pCompTemp,sizeof(struct LogAuditStruct));
	MakeCompNode(pTemp,pCompTemp);
	if(pTemp!=NULL){
		InsertListSumm((LIST**)&pLogAll,(LIST*)pCompTemp,
			comp_insert_list_stat_audit_e,
			sum_list_stat_audit_e);
	}
	return 0;
}

void MakeNoErrLog(struct LogAuditStruct *pTemp,struct AuditParamStruct *pAuditParam)
{
	pTemp->iFlowID=		pAuditParam->iFlowID;    
	pTemp->iPreTacheID=	pAuditParam->iPreTacheID;
	pTemp->iTacheID=	pAuditParam->iTacheID;
	strcpy(pTemp->sType,	"0");    
	strcpy(pTemp->sSourceID,pAuditParam->sSourceID);
	pTemp->iCnt=		iCntAudit;
	pTemp->iAbnoCnt=		0; 
	strcpy(pTemp->sBeginDate,pAuditParam->sBeginDate);
	strcpy(pTemp->sEndDate,	pAuditParam->sEndDate);  
	strcpy(pTemp->sDataDate,""); 
	pTemp->iStaffID=	pAuditParam->iStaffID;   
	strcpy(pTemp->sSerialNbr,pAuditParam->sSerialNbr);

}

int main(int argc,char *argv[])
{
	int iErrCnt=0;
	struct AuditParamStruct AuditParam;
	struct LogAuditStruct *pTemp;
	void (*AuditTache)();

/*auditverify.sh  �������(type) ������(serial_nbr) ���̱�ʶ(flow_id)  ǰ�û��ڱ�ʶ(pre_tache_id) ���ڱ�ʶ(tache_id) ����Դ(source_id) ��ʼʱ��(startDate) ����ʱ��(endDate) ��������(staffId)*/
	if(argc!=10){
		printf("Usage %s type serial_nbr flow_id pre_tache_id tache_id source_id begin_date end_date staff_id.\n",argv[0]);
		return -1;
	}


	InitAppRes(argv[0]);

	strcpy(AuditParam.sType,	argv[1]);
	strcpy(AuditParam.sSerialNbr,	argv[2]);
	AuditParam.iFlowID=		atoi(argv[3]);
	AuditParam.iPreTacheID=		atoi(argv[4]);
	AuditParam.iTacheID=		atoi(argv[5]);
	strcpy(AuditParam.sSourceID,	argv[6]);
	strcpy(AuditParam.sBeginDate,	argv[7]);
	strcpy(AuditParam.sEndDate,	argv[8]);
	AuditParam.iStaffID=		atoi(argv[9]);

	if(ConnectDataDB()<0) return -1;

	if(MountTacheAppLog(&AuditParam)<0){
		WriteAlertMsg("������־��ʧ��\n");
		return -1;
	};

	if(strcmp(AuditParam.sPreAppLog,"PICK_LOG")==0&&
		strcmp(AuditParam.sAppLog,"PREP_PROC_LOG")==0)
		AuditTache=AuditPickPrep;
	else if(strcmp(AuditParam.sPreAppLog,"PREP_LOG")==0&&
		strcmp(AuditParam.sAppLog,"BILLING_PROC_LOG")==0)
		AuditTache=AuditPrepBilling;
	else if(strcmp(AuditParam.sPreAppLog,"PREP_LOG")==0&&
		strcmp(AuditParam.sAppLog,"INSERT_LOG")==0)
		AuditTache=AuditPrepInsert;
	else if(strcmp(AuditParam.sPreAppLog,"BILLING_LOG")==0&&
		strcmp(AuditParam.sAppLog,"INSERT_LOG")==0)
		AuditTache=AuditBillingInsert;
	else if(strcmp(AuditParam.sPreAppLog,"BILLING_LOG")==0&&
		strcmp(AuditParam.sAppLog,"ACCT_LOG")==0)
		AuditTache=AuditBillingAcct;
	else if(strcmp(AuditParam.sPreAppLog,"BILLING_LOG")==0&&
		strcmp(AuditParam.sAppLog,"UPDATA_PROC_LOG")==0)
		AuditTache=AuditBillingUpdata;
	else if(strcmp(AuditParam.sPreAppLog,"UPDATA_LOG")==0&&
		strcmp(AuditParam.sAppLog,"ACCT_LOG")==0)
		AuditTache=AuditUpdataAcct;
	else{
		WriteAlertMsg("�޶�Ӧ��˴���ģ��\n");
		return -1;
	}

	(*AuditTache)(&AuditParam);

	TravelList((LIST*)pLogDetailAll,StatAudit);
	
	/*�޴���Ҳ���һ����Ϣ��log_audit*/
	iErrCnt=CountList((LIST*)pLogDetailAll);
	if(iErrCnt==0){
		if((pTemp=malloc(sizeof(struct LogAuditStruct)))==NULL){
			WriteAlertMsg("�����ڴ� LogAuditStruct ����");
			exit (1);
		}
		bzero((void*)pTemp,sizeof(struct LogAuditStruct));
		MakeNoErrLog(pTemp,&AuditParam);
		InsertList((LIST**)&pLogAll,(LIST*)pTemp);
	}

	if(InsertLogAuditDetail(pLogDetailAll)<0){
		WriteAlertMsg("дLOG_AUDIT_DETAIL��ʧ��\n");
		return -1;
	}
	if(InsertLogAudit(pLogAll)<0){
		WriteAlertMsg("дLOG_AUDIT��ʧ��\n");
		return -1;
	}

	DisconnectDatabase();
	
	printf("������Դ%sģ�����˹�����%d������\n",
		AuditParam.sSourceID,iErrCnt);
		
	return 0;
}
