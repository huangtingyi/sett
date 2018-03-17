/*---------����ʵ�ִ��� unicom_ticket.pc----------*/
#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>
#include "param_intf.h"
#include "wwshm.h"
#include "stt_ticket.h"

BINTREE *pRoot=NULL;
BINTREE *pRootS=NULL;
BINTREE *pRootN=NULL;

BINTREE *pSmsRoot=NULL;
BINTREE *pSpRootS=NULL;
BINTREE *pSpRootN=NULL;

struct SmsNbrStatStruct *ptSmHead=NULL;
struct SmspNbrRentStatStruct *ptNRHead=NULL;
struct SmspSpStatStruct *ptSPHead=NULL;
struct SmspNbrStatStruct *ptNPHead=NULL;

int (*Stat2Bintree)(BINTREE **ppRoot,char sTableName[],char sBillingCycle[]);
int (*node_head_e)(void **ppHead);

int UpdateSmspSpStat(struct USmspSpStatStruct *pSourcet,char sTableName[],
	int iUpdateFlag);
int UpdateSmspNbrStat(struct USmspNbrStatStruct *pSourcet,char sTableName[],
	int iUpdateFlag);
int InsertSmspSpStat(struct SmspSpStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag);
int InsertSmspNbrStat(struct SmspNbrStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag);

int SmsNbrStatDataSum(BINTREE **ppRoot,struct SmsNbrStatStruct *pValue,
	char sBillingCycle[],char sTableName[])
{
	static struct SmsNbrStatStruct TempStat,*pTemp,*ptHead=NULL;
	static struct RSmsNbrStatStruct TempR;
	static struct USmsNbrStatStruct *pHead=NULL,TempUp;
	int iCnt=0,iUpdateCnt=0;
	
	ptHead=pValue;
	
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_rsmsnbrstat(pTemp,&TempR);
		strcpy(TempR.sBillingCycleID,sBillingCycle);
		
		if(SearchBin(*ppRoot,&TempR,
			rdata_search_bintree_sms_nbr,
			(void **)&pHead)==FOUND){
			InsertSmsNbrFeeTotal(&TempR,pHead);

			/*�Ƚ�ʱ��*/
			if(strcmp(pHead->sMinStartTime,TempR.sMinStartTime)>0)
				strcpy(TempR.sMinStartTime,pHead->sMinStartTime);
			if(strcmp(pHead->sMaxStartTime,TempR.sMinStartTime)<0)
				strcpy(TempR.sMaxStartTime,pHead->sMinStartTime);
			strcpy(TempR.sRowID,pHead->sRowID);
			mvitem_usmsnbrstat(&TempR,&TempUp);
			iUpdateCnt++;
			if(UpdateSmsNbrStat(&TempUp,sTableName,FALSE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			if(iUpdateCnt%10000==0){ 
				if(UpdateSmsNbrStat(NULL,sTableName,TRUE)<0){
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				printf("��ǰ���ͳ�Ƽ�¼��%d.\n",iUpdateCnt);
				WriteProcMsg("��ǰ���ͳ�Ƽ�¼��%d.",iUpdateCnt);
				CommitWork();			
			}
			
		}
		else{
			mvitem_smsnbrstat(&TempR,&TempStat);

			if(InsertSmsNbrStat(&TempStat,sTableName,sBillingCycle,FALSE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			iCnt++;
			if(iCnt%10000==0){ 
				if(InsertSmsNbrStat(NULL,sTableName,NULL,TRUE)<0){
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				printf("��ǰ���ͳ�Ƽ�¼��%d.\n",iCnt);
				WriteProcMsg("��ǰ���ͳ�Ƽ�¼��%d.",iCnt);
				CommitWork();			
			}
		}
	}
	if(InsertSmsNbrStat(NULL,sTableName,NULL,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}	
	if(UpdateSmsNbrStat(NULL,sTableName,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	printf("ͳ�����, %d ������%s ��, %d ����¼����%s ��.\n",
		iCnt,sTableName,iUpdateCnt,sTableName);
	WriteProcMsg("ͳ�����, %d ������%s ��, %d ����¼����%s ��.",
		iCnt,sTableName,iUpdateCnt,sTableName);
	CommitWork();

	return 0;

}

int SmspNbrStatStructDataSum(BINTREE **ppRoot,struct SmspNbrStatStruct *pValue,
	char sBillingCycle[],char sTableName[])
{
	static struct SmspNbrStatStruct TempStat,*pTemp,*ptHead=NULL;
	static struct RSmspNbrStatStruct TempR;
	static struct USmspNbrStatStruct *pHead=NULL,TempUp;
	int iCnt=0,iUpdateCnt=0;
	
	ptHead=pValue;
	
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_rsmspnbrstat(pTemp,&TempR);
		strcpy(TempR.sBillingCycleID,sBillingCycle);
		
		if(SearchBin(*ppRoot,&TempR,
			rdata_bintree_search_smsp_nbr_stat,
			(void **)&pHead)==FOUND){
			
			InsertSmspNbrFeeTotal(&TempR,pHead);
			
			/*�Ƚ�ʱ��*/
			if(strcmp(pHead->sMinStartTime,TempR.sMinStartTime)>0)
				strcpy(TempR.sMinStartTime,pHead->sMinStartTime);
			if(strcmp(pHead->sMaxStartTime,TempR.sMinStartTime)<0)
				strcpy(TempR.sMaxStartTime,pHead->sMinStartTime);
			strcpy(TempR.sRowID,pHead->sRowID);
			mvitem_usmspnbrstat(&TempR,&TempUp);
			iUpdateCnt++;
			if(UpdateSmspNbrStat(&TempUp,sTableName,FALSE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			if(iUpdateCnt%10000==0){ 
				if(UpdateSmspNbrStat(NULL,sTableName,TRUE)<0){
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				printf("��ǰ���ͳ�Ƽ�¼��%d.\n",iUpdateCnt);
				WriteProcMsg("��ǰ���ͳ�Ƽ�¼��%d.",iUpdateCnt);
				CommitWork();			
			}
			
		}
		else{
			mvitem_smspnbrstat(&TempR,&TempStat);
			if(InsertSmspNbrStat(&TempStat,sTableName,sBillingCycle,FALSE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			iCnt++;
			if(iCnt%10000==0){ 
				if(InsertSmspNbrStat(NULL,sTableName,NULL,TRUE)<0){
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				printf("��ǰ���ͳ�Ƽ�¼��%d.\n",iCnt);
				WriteProcMsg("��ǰ���ͳ�Ƽ�¼��%d.",iCnt);
				CommitWork();			
			}
		}
	}
	if(InsertSmspNbrStat(NULL,sTableName,NULL,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}	
	if(UpdateSmspNbrStat(NULL,sTableName,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	printf("ͳ�����, %d ������%s ��, %d ����¼����%s ��.\n",
		iCnt,sTableName,iUpdateCnt,sTableName);
	WriteProcMsg("ͳ�����, %d ������%s ��, %d ����¼����%s ��.",
		iCnt,sTableName,iUpdateCnt,sTableName);
	CommitWork();

	return 0;

}

int SmspSpStatStructDataSum(BINTREE **ppRoot,struct SmspSpStatStruct *pValue,
	char sBillingCycle[],char sTableName[])
{
	static struct SmspSpStatStruct TempStat,*pTemp,*ptHead=NULL;
	static struct RSmspSpStatStruct TempR;
	static struct USmspSpStatStruct *pHead=NULL,TempUp;
	int iCnt=0,iUpdateCnt=0;
	
	ptHead=pValue;
	
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_rsmspspstat(pTemp,&TempR);
		strcpy(TempR.sBillingCycleID,sBillingCycle);
		
		if(SearchBin(*ppRoot,&TempR,
			rdata_bintree_search_smsp_sp_stat,
			(void **)&pHead)==FOUND){
			
			InsertSmspSpFeeTotal(&TempR,pHead);
			
			/*�Ƚ�ʱ��*/
			if(strcmp(pHead->sMinStartTime,TempR.sMinStartTime)>0)
				strcpy(TempR.sMinStartTime,pHead->sMinStartTime);
			if(strcmp(pHead->sMaxStartTime,TempR.sMinStartTime)<0)
				strcpy(TempR.sMaxStartTime,pHead->sMinStartTime);
			strcpy(TempR.sRowID,pHead->sRowID);
			mvitem_usmspspstat(&TempR,&TempUp);
			iUpdateCnt++;
			if(UpdateSmspSpStat(&TempUp,sTableName,FALSE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			if(iUpdateCnt%10000==0){ 
				if(UpdateSmspSpStat(NULL,sTableName,TRUE)<0){
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				printf("��ǰ���ͳ�Ƽ�¼��%d.\n",iUpdateCnt);
				WriteProcMsg("��ǰ���ͳ�Ƽ�¼��%d.",iUpdateCnt);
				CommitWork();			
			}
			
		}
		else{
			mvitem_smspspstat(&TempR,&TempStat);
			if(InsertSmspSpStat(&TempStat,sTableName,sBillingCycle,FALSE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			iCnt++;
			if(iCnt%10000==0){ 
				if(InsertSmspSpStat(NULL,sTableName,NULL,TRUE)<0){
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				printf("��ǰ���ͳ�Ƽ�¼��%d.\n",iCnt);
				WriteProcMsg("��ǰ���ͳ�Ƽ�¼��%d.",iCnt);
				CommitWork();			
			}
		}
	}
	if(InsertSmspSpStat(NULL,sTableName,NULL,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}	
	if(UpdateSmspSpStat(NULL,sTableName,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	printf("ͳ�����, %d ������%s ��, %d ����¼����%s ��.\n",
		iCnt,sTableName,iUpdateCnt,sTableName);
	WriteProcMsg("ͳ�����, %d ������%s ��, %d ����¼����%s ��.",
		iCnt,sTableName,iUpdateCnt,sTableName);
	CommitWork();

	return 0;

}


int SmspNbrRentStatDataSum(BINTREE **ppRoot,struct SmspNbrRentStatStruct *pValue,
	char sBillingCycle[],char sTableName[])
{
	static struct SmspNbrRentStatStruct *pTemp,*pHead=NULL,*ptHead=NULL;
	int iCnt=0;

	ptHead=pValue;
	
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
	
		strcpy(pTemp->sBillingCycleID,sBillingCycle);

		if(SearchBin(*ppRoot,pTemp,
			data_bintree_search_smsp_nbr_rent,
			(void **)&pHead)==NOTFOUND){

			if(InsertSmspNbrRentStat(pTemp,sTableName,sBillingCycle,FALSE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			iCnt++;
			if(iCnt%10000==0){ 
				if(InsertSmspNbrRentStat(NULL,sTableName,NULL,TRUE)<0){
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				printf("��ǰ���ͳ�Ƽ�¼��%d.\n",iCnt);
				WriteProcMsg("��ǰ���ͳ�Ƽ�¼��%d.",iCnt);
				CommitWork();			
			}
		}
	}
	if(InsertSmspNbrRentStat(NULL,sTableName,NULL,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}	
	printf("ͳ�����, %d ������%s ��.\n",iCnt,sTableName);
	WriteProcMsg("ͳ�����, %d ������%s ��.",iCnt,sTableName);
	CommitWork();			

	return 0;
}


int SmsNbrStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[])
{
	static int iFirstFlag=true;
        static struct RSmsNbrStatStruct Temp;
        static struct RSmsNbrStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition," WHERE BILLING_CYCLE_ID ='%s' ",sBillingCycle);

		iFirstFlag=false;
	}
        /*ȡ�����м�¼���ض�����*/
        while(EGetSmsNbrStatToStruct(&Temp,&TempIn)){
		/*����SmsNbrStatStruct*/
                if(InsertBin(ppRoot,&Temp,
			rdata_search_bintree_sms_nbr,
			rassign_bintree_insert_sms_nbr)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
        }
	return 0;
}

int SmspNbrStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[])
{
	static int iFirstFlag=true;
        static struct RSmspNbrStatStruct Temp;
        static struct RSmspNbrStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition," WHERE BILLING_CYCLE_ID ='%s' ",sBillingCycle);

		iFirstFlag=false;
	}
        /*ȡ�����м�¼���ض�����*/
        while(EGetSmspNbrStatToStruct(&Temp,&TempIn)){
		/*����RSmspNbrStatStruct*/
                if(InsertBin(ppRoot,&Temp,
			rdata_bintree_search_smsp_nbr_stat,
			rassign_bintree_insert_smsp_nbr_stat)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
        }
	return 0;
}

int SmspSpStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[])
{
	static int iFirstFlag=true;
        static struct RSmspSpStatStruct Temp;
        static struct RSmspSpStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition," WHERE BILLING_CYCLE_ID ='%s' ",sBillingCycle);

		iFirstFlag=false;
	}
        /*ȡ�����м�¼���ض�����*/
        while(EGetSmspSpStatToStruct(&Temp,&TempIn)){
		/*����SmspSpStatStruct*/
                if(InsertBin(ppRoot,&Temp,
			rdata_bintree_search_smsp_sp_stat,
			rassign_bintree_insert_smsp_sp_stat)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
        }
	return 0;
}

int SmspNbrRentStat2Bintree(BINTREE **ppRoot,char sTableName[],char sBillingCycle[])
{
	static int iFirstFlag=true;
        static struct SmspNbrRentStatStruct Temp;
        static struct SmspNbrRentStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition," WHERE BILLING_CYCLE_ID ='%s' ",sBillingCycle);

		iFirstFlag=false;
	}
        /*ȡ�����м�¼���ض�����*/
        while(EGetSmspNbrRentStatToStruct(&Temp,&TempIn)){
		/*����SmspNbrRentStatStruct*/
                if(InsertBin(ppRoot,&Temp,
			data_bintree_search_smsp_nbr_rent,
			assign_bintree_insert_smsp_nbr_rent)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
        }
	return 0;
}

int SmsTicket2Bintree(BINTREE **ppRoot,BINTREE ** ppRootS,BINTREE ** ppRootN,
	char sTableName[],char sCondition[],char sStatType[])
{
	static int iFirstFlag=true;
        static struct SmsTicketStruct Temp;
        static struct SmsTicketStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);

		iFirstFlag=false;
	}

        /*ȡ�����м�¼���ض�����*/
        while(EGetSmsTicketToStruct(&Temp,&TempIn)){

		if(strcmp(Temp.sCallType,"08")==0)
			strcpy(Temp.sCallType,"1");
		else 	if(strcmp(Temp.sCallType,"07")==0)
			strcpy(Temp.sCallType,"0");
		else 	strcpy(Temp.sCallType,"0");
		/*����SmspNbrRentStatStruct*/
		if(strncmp(sStatType,"1",1)==0||strncmp(sStatType,"0",1)==0){
	                if(InsertBin(ppRoot,&Temp,
				data_bintree_search_smsp_nbr_rent_stat,
				assign_bintree_insert_smsp_nbr_rent_stat)<0){
				WriteAlertMsg("SmspNbrRentStat����BINTREEʧ��");
				return -1;
			}
		}
		/*����SmspSpStatStruct*/
		if(strncmp(sStatType,"2",1)==0||strncmp(sStatType,"0",1)==0){
	                if(InsertBin(ppRootS,&Temp,
				data_bintree_search_smsp_sp_stat,
				assign_bintree_insert_smsp_sp_stat)<0){
				WriteAlertMsg("SmspSpStat����BINTREEʧ��");
				return -1;
			}
		}
		/*����SmspNbrStatStruct*/
		if(strncmp(sStatType,"3",1)==0||
			strncmp(sStatType,"4",1)==0||
			strncmp(sStatType,"0",1)==0){	
			
			if(strncmp(sStatType,"4",1)==0){
				strcpy(Temp.sHomeAreaCode+3,Temp.sSpProvCode);
			}
	                if(InsertBin(ppRootN,&Temp,
				data_bintree_search_smsp_nbr_stat,
				assign_bintree_insert_smsp_nbr_stat)<0){
				WriteAlertMsg("SmspNbrStat����BINTREEʧ��");
				return -1;
			}
		}
        }
	return 0;
}

int SmsStatTicket2Bintree(BINTREE **ppRoot,char sTableName[],char sCondition[])
{
	static int iFirstFlag=true;
        static struct SmsStatStruct Temp;
        static struct SmsStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);

		iFirstFlag=false;
	}

        /*ȡ�����м�¼���ض�����*/
        while(EGetSmsStatToStruct(&Temp,&TempIn)){

		if(strcmp(Temp.sRecordType,"01")==0)
			strcpy(Temp.sRecordType,"00");
		else 	if(strcmp(Temp.sRecordType,"02")==0)
			strcpy(Temp.sRecordType,"01");
		else 	if(strcmp(Temp.sRecordType,"03")==0)
			strcpy(Temp.sRecordType,"02");
		else 	if(strcmp(Temp.sRecordType,"04")==0)
			strcpy(Temp.sRecordType,"03");
		else	strcpy(Temp.sRecordType,"04");

                if(InsertBin(ppRoot,&Temp,
			data_bintree_search_sms_nbr_stat,
			assign_bintree_insert_sms_nbr_stat)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
        }
	return 0;
}
void InsertSmspSpFeeTotal(void *pValue,void*pData)
{

	struct RSmspSpStatStruct *pTemp=(struct RSmspSpStatStruct *)pValue;
	struct RSmspSpStatStruct    *pRecordFee=(struct RSmspSpStatStruct *)pData;

	int iTotalFee,iMoCnt,iMtCnt,iTotalCnt;
	int iTotalInfoFee,iTotalCommFee,iTotalRentFee;
	
	iMoCnt=pRecordFee->iMoCnt;
	iMtCnt=pRecordFee->iMtCnt;
        iTotalCnt=pRecordFee->iTotalCnt;
	iTotalFee=pRecordFee->iTotalFee;
	iTotalInfoFee=pRecordFee->iTotalInfoFee;
	iTotalCommFee=pRecordFee->iTotalCommFee;
	iTotalRentFee=pRecordFee->iTotalRentFee;
	
	pTemp->iMoCnt		+=iMoCnt;
	pTemp->iMtCnt		+=iMtCnt;
	pTemp->iTotalCnt	+=iTotalCnt;
	pTemp->iTotalFee	+=iTotalFee;
	pTemp->iTotalInfoFee	+=iTotalInfoFee;
	pTemp->iTotalCommFee	+=iTotalCommFee;
	pTemp->iTotalRentFee	+=iTotalRentFee;
}

/*�ۼӼ�¼*/
void InsertSmspSpFee(void *pValue,void*pData)
{

	struct SmspSpStatStruct *pTemp=(struct SmspSpStatStruct *)pValue;
	struct SmsTicketStruct    *pRecordFee=(struct SmsTicketStruct *)pData;

	int iTotalFee,iMoCnt,iMtCnt,iTotalCnt;
	int iTotalInfoFee,iTotalCommFee,iTotalRentFee;
	
       	if(strcmp(pRecordFee->sCallType,"0")==0){iMoCnt=1;iMtCnt=0;}
        	else {iMoCnt=0;iMtCnt=1;}

        iTotalCnt=iMoCnt+iMtCnt;
	iTotalFee=pRecordFee->iBaseFee+pRecordFee->iInfoFee+
		pRecordFee->iRentFee+pRecordFee->iOtherFee;
	iTotalInfoFee=pRecordFee->iInfoFee;
	iTotalCommFee=pRecordFee->iBaseFee;
	iTotalRentFee=pRecordFee->iRentFee;
	
	pTemp->iMoCnt		+=iMoCnt;
	pTemp->iMtCnt		+=iMtCnt;
	pTemp->iTotalCnt	+=iTotalCnt;
	pTemp->iTotalFee	+=iTotalFee;
	pTemp->iTotalInfoFee	+=iTotalInfoFee;
	pTemp->iTotalCommFee	+=iTotalCommFee;
	pTemp->iTotalRentFee	+=iTotalRentFee;
}

void InsertSmspNbrFeeTotal(void *pValue,void*pData)
{

	struct RSmspNbrStatStruct *pTemp=(struct RSmspNbrStatStruct *)pValue;
	struct RSmspNbrStatStruct    *pRecordFee=(struct RSmspNbrStatStruct *)pData;

	int iTotalFee,iMoCnt,iMtCnt,iTotalCnt;
	int iTotalInfoFee,iTotalCommFee,iTotalRentFee;
	
	iMoCnt=pRecordFee->iMoCnt;
	iMtCnt=pRecordFee->iMtCnt;
        iTotalCnt=pRecordFee->iTotalCnt;
	iTotalFee=pRecordFee->iTotalFee;
	iTotalInfoFee=pRecordFee->iTotalInfoFee;
	iTotalCommFee=pRecordFee->iTotalCommFee;
	iTotalRentFee=pRecordFee->iTotalRentFee;
	
	pTemp->iMoCnt		+=iMoCnt;
	pTemp->iMtCnt		+=iMtCnt;
	pTemp->iTotalCnt	+=iTotalCnt;
	pTemp->iTotalFee	+=iTotalFee;
	pTemp->iTotalInfoFee	+=iTotalInfoFee;
	pTemp->iTotalCommFee	+=iTotalCommFee;
	pTemp->iTotalRentFee	+=iTotalRentFee;
}

/*�ۼӼ�¼*/
void InsertSmspNbrFee(void *pValue,void*pData)
{

	struct SmspNbrStatStruct *pTemp=(struct SmspNbrStatStruct *)pValue;
	struct SmsTicketStruct    *pRecordFee=(struct SmsTicketStruct *)pData;

	int iTotalFee,iMoCnt,iMtCnt,iTotalCnt;
	int iTotalInfoFee,iTotalCommFee,iTotalRentFee;
	
       	if(strcmp(pRecordFee->sCallType,"0")==0){iMoCnt=1;iMtCnt=0;}
        	else {iMoCnt=0;iMtCnt=1;}

        iTotalCnt=iMoCnt+iMtCnt;
	iTotalFee=pRecordFee->iBaseFee+pRecordFee->iInfoFee+
		pRecordFee->iRentFee+pRecordFee->iOtherFee;
	iTotalInfoFee=pRecordFee->iInfoFee;
	iTotalCommFee=pRecordFee->iBaseFee;
	iTotalRentFee=pRecordFee->iRentFee;
	
	pTemp->iMoCnt		+=iMoCnt;
	pTemp->iMtCnt		+=iMtCnt;
	pTemp->iTotalCnt	+=iTotalCnt;
	pTemp->iTotalFee	+=iTotalFee;
	pTemp->iTotalInfoFee	+=iTotalInfoFee;
	pTemp->iTotalCommFee	+=iTotalCommFee;
	pTemp->iTotalRentFee	+=iTotalRentFee;
}

/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int rdata_bintree_search_smsp_nbr_stat(void *pValue,void*pData)
{
	struct RSmspNbrStatStruct *pSource=(struct RSmspNbrStatStruct *)pValue;
	struct RSmspNbrStatStruct *pTarget=(struct RSmspNbrStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
 	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
 	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpServiceCode,pTarget->sSpServiceCode))!=0) return res;
 	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;

	return res;

}

/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int data_bintree_search_smsp_nbr_stat(void *pValue,void*pData)
{
	struct SmsTicketStruct *pSource=(struct SmsTicketStruct *)pValue;
	struct SmspNbrStatStruct *pTarget=(struct SmspNbrStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
 	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
 	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
	if((res=strcmp(pSource->sSpServiceCode,pTarget->sSpServiceCode))!=0) return res;
 	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;

	return res;

}

/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int data_bintree_search_smsp_sp_stat(void *pValue,void*pData)
{
	struct SmsTicketStruct *pSource=(struct SmsTicketStruct *)pValue;
	struct SmspSpStatStruct *pTarget=(struct SmspSpStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

 	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
 	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;

	return res;

}
/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int rdata_bintree_search_smsp_sp_stat(void *pValue,void*pData)
{
	struct RSmspSpStatStruct *pSource=(struct RSmspSpStatStruct *)pValue;
	struct RSmspSpStatStruct *pTarget=(struct RSmspSpStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

 	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
 	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;

	return res;

}
/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void rassign_bintree_insert_smsp_nbr_stat(void **ppData,void *pData)
{
	struct RSmspNbrStatStruct *pValue=(struct RSmspNbrStatStruct *)pData;
	struct RSmspNbrStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct RSmspNbrStatStruct));
		ERROR_EXIT(pTemp==NULL,"����RSmspNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct RSmspNbrStatStruct));

		pTemp->iTicketTypeID=pValue->iTicketTypeID;
        	strcpy(pTemp->sUserType,pValue->sUserType);
        	strcpy(pTemp->sMsisdn,pValue->sMsisdn);
		strcpy(pTemp->sSpCode,pValue->sSpCode);
		strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
		strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
		strcpy(pTemp->sMinStartTime,pValue->sMinStartTime);
		strcpy(pTemp->sMaxStartTime,pValue->sMaxStartTime);
		strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
		
		InsertSmspNbrFeeTotal(pTemp,pValue);
		
		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);
	
	pTemp->iTicketTypeID=pValue->iTicketTypeID;
        strcpy(pTemp->sUserType,pValue->sUserType);
        strcpy(pTemp->sMsisdn,pValue->sMsisdn);
	strcpy(pTemp->sSpCode,pValue->sSpCode);
	strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
	strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
	
	
	InsertSmspNbrFeeTotal(pTemp,pValue);
	/*�Ƚ�ʱ��*/
	if(strcmp(pTemp->sMinStartTime,pValue->sMinStartTime)>0)
		strcpy(pTemp->sMinStartTime,pValue->sMinStartTime);
	if(strcmp(pTemp->sMaxStartTime,pValue->sMaxStartTime)<0)
		strcpy(pTemp->sMaxStartTime,pValue->sMaxStartTime);
	
}

/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void assign_bintree_insert_smsp_nbr_stat(void **ppData,void *pData)
{
	struct SmsTicketStruct *pValue=(struct SmsTicketStruct *)pData;
	struct SmspNbrStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SmspNbrStatStruct));
		ERROR_EXIT(pTemp==NULL,"����SmsNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct SmspNbrStatStruct));


		pTemp->iTicketTypeID=pValue->iTicketTypeID;
        	strcpy(pTemp->sUserType,pValue->sUserType);
        	strcpy(pTemp->sMsisdn,pValue->sMsisdn);
		strcpy(pTemp->sSpCode,pValue->sSpCode);
		strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
		strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
		strcpy(pTemp->sMinStartTime,pValue->sStartTime);
		strcpy(pTemp->sMaxStartTime,pValue->sStartTime);
		strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
		
		InsertSmspNbrFee(pTemp,pValue);
		
		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);

	pTemp->iTicketTypeID=pValue->iTicketTypeID;
       	strcpy(pTemp->sUserType,pValue->sUserType);
       	strcpy(pTemp->sMsisdn,pValue->sMsisdn);
	strcpy(pTemp->sSpCode,pValue->sSpCode);
	strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
	strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
	
	InsertSmspNbrFee(pTemp,pValue);
	/*�Ƚ�ʱ��*/
	if(strcmp(pTemp->sMinStartTime,pValue->sStartTime)>0)
		strcpy(pTemp->sMinStartTime,pValue->sStartTime);
	if(strcmp(pTemp->sMaxStartTime,pValue->sStartTime)<0)
		strcpy(pTemp->sMaxStartTime,pValue->sStartTime);
	
}

/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void rassign_bintree_insert_smsp_sp_stat(void **ppData,void *pData)
{
	struct RSmspSpStatStruct *pValue=(struct RSmspSpStatStruct *)pData;
	struct RSmspSpStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct RSmspSpStatStruct));
		ERROR_EXIT(pTemp==NULL,"����SmsNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct RSmspSpStatStruct));


        	strcpy(pTemp->sUserType,pValue->sUserType);
		strcpy(pTemp->sSpCode,pValue->sSpCode);
		strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
		strcpy(pTemp->sMinStartTime,pValue->sMinStartTime);
		strcpy(pTemp->sMaxStartTime,pValue->sMinStartTime);
		strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
		
		InsertSmspSpFeeTotal(pTemp,pValue);
		
		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);

        strcpy(pTemp->sUserType,pValue->sUserType);
	strcpy(pTemp->sSpCode,pValue->sSpCode);
	strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
	
	InsertSmspSpFeeTotal(pTemp,pValue);
	/*�Ƚ�ʱ��*/
	if(strcmp(pTemp->sMinStartTime,pValue->sMinStartTime)>0)
		strcpy(pTemp->sMinStartTime,pValue->sMinStartTime);
	if(strcmp(pTemp->sMaxStartTime,pValue->sMaxStartTime)<0)
		strcpy(pTemp->sMaxStartTime,pValue->sMaxStartTime);
	
}


/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void assign_bintree_insert_smsp_sp_stat(void **ppData,void *pData)
{
	struct SmsTicketStruct *pValue=(struct SmsTicketStruct *)pData;
	struct SmspSpStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SmspSpStatStruct));
		ERROR_EXIT(pTemp==NULL,"����SmsNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct SmspSpStatStruct));


        	strcpy(pTemp->sUserType,pValue->sUserType);
		strcpy(pTemp->sSpCode,pValue->sSpCode);
		strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
		strcpy(pTemp->sMinStartTime,pValue->sStartTime);
		strcpy(pTemp->sMaxStartTime,pValue->sStartTime);
		strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
		
		InsertSmspSpFee(pTemp,pValue);
		
		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);

        strcpy(pTemp->sUserType,pValue->sUserType);
	strcpy(pTemp->sSpCode,pValue->sSpCode);
	strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
	
	InsertSmspSpFee(pTemp,pValue);
	/*�Ƚ�ʱ��*/
	if(strcmp(pTemp->sMinStartTime,pValue->sStartTime)>0)
		strcpy(pTemp->sMinStartTime,pValue->sStartTime);
	if(strcmp(pTemp->sMaxStartTime,pValue->sStartTime)<0)
		strcpy(pTemp->sMaxStartTime,pValue->sStartTime);
	
}





/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int data_bintree_search_smsp_nbr_rent_stat(void *pValue,void*pData)
{
	struct SmsTicketStruct *pSource=(struct SmsTicketStruct *)pValue;
	struct SmspNbrRentStatStruct *pTarget=(struct SmspNbrRentStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

	if((res=strcmp(pSource->sCallType,pTarget->sMoFlag))!=0) return res;
 	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
 	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
 	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
 	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
 	if((res=strcmp(pSource->sSpServiceCode,pTarget->sSpServiceCode))!=0) return res;
 	if((res=strcmp(pSource->sBillType,pTarget->sBillingType))!=0) return res;
 	if((res=pSource->iRentFee-pTarget->iRentRate)!=0) return res;

	return res;

}
/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void assign_bintree_insert_smsp_nbr_rent_stat(void **ppData,void *pData)
{
	struct SmsTicketStruct *pValue=(struct SmsTicketStruct *)pData;
	struct SmspNbrRentStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SmspNbrRentStatStruct));
		ERROR_EXIT(pTemp==NULL,"����SmsNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct SmspNbrRentStatStruct));


		strcpy(pTemp->sMoFlag,pValue->sCallType);
		strcpy(pTemp->sMsisdn,pValue->sMsisdn);
		strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
        	strcpy(pTemp->sUserType,pValue->sUserType);
		strcpy(pTemp->sSpCode,pValue->sSpCode);
		strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
		strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
		strcpy(pTemp->sBillingType,pValue->sBillType);
		pTemp->iRentRate=pValue->iRentFee;
		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);
	strcpy(pTemp->sMoFlag,pValue->sCallType);
	strcpy(pTemp->sMsisdn,pValue->sMsisdn);
	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
        strcpy(pTemp->sUserType,pValue->sUserType);
	strcpy(pTemp->sSpCode,pValue->sSpCode);
	strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
	strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
	strcpy(pTemp->sBillingType,pValue->sBillType);
	pTemp->iRentRate=pValue->iRentFee;
}



/*�ۼӼ�¼*/
void InsertSmsNbrFee(void *pValue,void*pData)
{

	struct SmsNbrStatStruct *pTemp=(struct SmsNbrStatStruct *)pValue;
	struct SmsStatStruct    *pRecordFee=(struct SmsStatStruct *)pData;

	int iTotalCommFee,iMoCnt,iMtCnt;

       	if(strcmp(pRecordFee->sCallType,"0")==0){iMoCnt=1;iMtCnt=0;}
        	else {iMoCnt=0;iMtCnt=1;}
        	
	iTotalCommFee=pRecordFee->iBaseFee+pRecordFee->iInfoFee;
	pTemp->iMoCnt		+=iMoCnt;
	pTemp->iMtCnt		+=iMtCnt;
	pTemp->iTotalCommFee	+=iTotalCommFee;
}
/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int data_bintree_search_sms_nbr_stat(void *pValue,void*pData)
{
	struct SmsStatStruct *pSource=(struct SmsStatStruct *)pValue;
	struct SmsNbrStatStruct *pTarget=(struct SmsNbrStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
 	if((res=strcmp(pSource->sRecordType,pTarget->sTicketType))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
 	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;

	return res;

}
/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void assign_bintree_insert_sms_nbr_stat(void **ppData,void *pData)
{
	struct SmsStatStruct *pValue=(struct SmsStatStruct *)pData;
	struct SmsNbrStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SmsNbrStatStruct));
		ERROR_EXIT(pTemp==NULL,"����SmsNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct SmsNbrStatStruct));


		/*strcpy(pTemp->sBillingCycleID,sBillingCycle);*/
		strcpy(pTemp->sTicketType,pValue->sRecordType);
		strcpy(pTemp->sUserType,pValue->sUserType);
		strcpy(pTemp->sMsisdn,pValue->sMsisdn);
        	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);

		InsertSmsNbrFee(pTemp,pValue);

		strcpy(pTemp->sMinStartTime,pValue->sStartTime);
		strcpy(pTemp->sMaxStartTime,pValue->sStartTime);


		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);
	/*strcpy(pTemp->sBillingCycleID,sBillingCycle);*/
	strcpy(pTemp->sTicketType,pValue->sRecordType);
	strcpy(pTemp->sUserType,pValue->sUserType);
	strcpy(pTemp->sMsisdn,pValue->sMsisdn);
        strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);

	InsertSmsNbrFee(pTemp,pValue);

	/*�Ƚ�ʱ��*/
	if(strcmp(pTemp->sMinStartTime,pValue->sStartTime)>0)
		strcpy(pTemp->sMinStartTime,pValue->sStartTime);
	if(strcmp(pTemp->sMaxStartTime,pValue->sStartTime)<0)
		strcpy(pTemp->sMaxStartTime,pValue->sStartTime);

}

int InsertSmspNbrRentStat(struct SmspNbrRentStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag)
{
	static struct SmspNbrRentStatStructOut TempOut;
	static int iFirstFlag=TRUE;
	char sHostDate[15];

	GetHostTime(sHostDate);

	if(iInsertFlag!=TRUE){
		strcpy(pSourcet->sCreatedDate,sHostDate);
		strcpy(pSourcet->sUpdatedDate,sHostDate);
		strcpy(pSourcet->sBillingCycleID,sBillingCycle);
	}
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct SmspNbrRentStatStructOut));
		strcpy(TempOut.sTableName,sTableName);
	}

	return EInsertStructToSmspNbrRentStat(pSourcet,iInsertFlag,&TempOut);
}

int InsertSmsNbrStat(struct SmsNbrStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag)
{
	static struct SmsNbrStatStructOut TempOut;
	static int iFirstFlag=TRUE;
	char sHostDate[15];

	GetHostTime(sHostDate);

	if(iInsertFlag!=TRUE){
		strcpy(pSourcet->sCreatedDate,sHostDate);
		strcpy(pSourcet->sUpdatedDate,sHostDate);
		strcpy(pSourcet->sBillingCycleID,sBillingCycle);
	}

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct SmsNbrStatStructOut));
		strcpy(TempOut.sTableName,sTableName);
	}

	return EInsertStructToSmsNbrStat(pSourcet,iInsertFlag,&TempOut);
}

int InsertSmspNbrStat(struct SmspNbrStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag)
{
	static struct SmspNbrStatStructOut TempOut;
	static int iFirstFlag=TRUE;
	char sHostDate[15];

	GetHostTime(sHostDate);

	if(iInsertFlag!=TRUE){
		strcpy(pSourcet->sCreatedDate,sHostDate);
		strcpy(pSourcet->sUpdatedDate,sHostDate);
		strcpy(pSourcet->sBillingCycleID,sBillingCycle);
	}

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct SmspNbrStatStructOut));
		strcpy(TempOut.sTableName,sTableName);
	}

	return EInsertStructToSmspNbrStat(pSourcet,iInsertFlag,&TempOut);
}


int InsertSmspSpStat(struct SmspSpStatStruct *pSourcet,char sTableName[],
	char sBillingCycle[],int iInsertFlag)
{
	static struct SmspSpStatStructOut TempOut;
	static int iFirstFlag=TRUE;
	char sHostDate[15];

	GetHostTime(sHostDate);

	if(iInsertFlag!=TRUE){
		strcpy(pSourcet->sCreatedDate,sHostDate);
		strcpy(pSourcet->sUpdatedDate,sHostDate);
		strcpy(pSourcet->sBillingCycleID,sBillingCycle);
	}

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct SmspSpStatStructOut));
		strcpy(TempOut.sTableName,sTableName);
	}

	return EInsertStructToSmspSpStat(pSourcet,iInsertFlag,&TempOut);
}

int UpdateSmspNbrStat(struct USmspNbrStatStruct *pSourcet,char sTableName[],
	int iUpdateFlag)
{
	static struct USmspNbrStatStructUp TempUp;
	static int iFirstFlag=TRUE;

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempUp,sizeof(struct USmspNbrStatStructUp));
		strcpy(TempUp.sTableName,sTableName);
	}

	return EUpdateStructToSmspNbrStat(pSourcet,iUpdateFlag,&TempUp);
}


int UpdateSmspSpStat(struct USmspSpStatStruct *pSourcet,char sTableName[],
	int iUpdateFlag)
{
	static struct USmspSpStatStructUp TempUp;
	static int iFirstFlag=TRUE;

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempUp,sizeof(struct USmspSpStatStructUp));
		strcpy(TempUp.sTableName,sTableName);
	}

	return EUpdateStructToUSmspSpStat(pSourcet,iUpdateFlag,&TempUp);
}
int UpdateSmsNbrStat(struct USmsNbrStatStruct *pSourcet,char sTableName[],
	int iUpdateFlag)
{
	static struct USmsNbrStatStructUp TempUp;
	static int iFirstFlag=TRUE;

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempUp,sizeof(struct USmsNbrStatStructUp));
		strcpy(TempUp.sTableName,sTableName);
	}

	return EUpdateStructToUSmsNbrStat(pSourcet,iUpdateFlag,&TempUp);
}
/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int rdata_search_bintree_sms_nbr(void *pValue,void*pData)
{
	struct RSmsNbrStatStruct *pSource=(struct RSmsNbrStatStruct *)pValue;
	struct RSmsNbrStatStruct *pTarget=(struct RSmsNbrStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

	if((res=strcmp(pSource->sTicketType,	pTarget->sTicketType))!=0) return res;
 	if((res=strcmp(pSource->sUserType,	pTarget->sUserType))!=0) return res;
	if((res=strcmp(pSource->sMsisdn,	pTarget->sMsisdn))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,	pTarget->sHomeAreaCode))!=0) return res;

	return res;

}

/*�ۼӼ�¼*/
void InsertSmsNbrFeeTotal(void *pValue,void*pData)
{

	struct SmsNbrStatStruct *pTemp=(struct SmsNbrStatStruct *)pValue;
	struct SmsNbrStatStruct    *pRecordFee=(struct SmsNbrStatStruct *)pData;

	pTemp->iMoCnt		+=pRecordFee->iMoCnt;
	pTemp->iMtCnt		+=pRecordFee->iMtCnt;
	pTemp->iTotalCommFee	+=pRecordFee->iTotalCommFee;
}
/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void rassign_bintree_insert_sms_nbr(void **ppData,void *pData)
{
	struct RSmsNbrStatStruct *pValue=(struct RSmsNbrStatStruct *)pData;
	struct RSmsNbrStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct RSmsNbrStatStruct));
		ERROR_EXIT(pTemp==NULL,"����RSmsNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct RSmsNbrStatStruct));

		/*strcpy(pTemp->sBillingCycleID,pValue->sBillingCycleID);*/
		strcpy(pTemp->sTicketType,pValue->sTicketType);
		strcpy(pTemp->sUserType,pValue->sUserType);
		strcpy(pTemp->sMsisdn,pValue->sMsisdn);
        	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);

		InsertSmsNbrFeeTotal(pTemp,pValue);

		strcpy(pTemp->sMinStartTime,pValue->sMinStartTime);
		strcpy(pTemp->sMaxStartTime,pValue->sMinStartTime);
		strcpy(pTemp->sRowID,pValue->sRowID);
		

		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);
	/*strcpy(pTemp->sBillingCycleID,pValue->sBillingCycleID);*/
	strcpy(pTemp->sTicketType,pValue->sTicketType);
	strcpy(pTemp->sUserType,pValue->sUserType);
	strcpy(pTemp->sMsisdn,pValue->sMsisdn);
        strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
	strcpy(pTemp->sRowID,pValue->sRowID);
	
	InsertSmsNbrFeeTotal(pTemp,pValue);

	/*�Ƚ�ʱ��*/
	if(strcmp(pTemp->sMinStartTime,pValue->sMinStartTime)>0)
		strcpy(pTemp->sMinStartTime,pValue->sMinStartTime);
	if(strcmp(pTemp->sMaxStartTime,pValue->sMinStartTime)<0)
		strcpy(pTemp->sMaxStartTime,pValue->sMinStartTime);

}

/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/

/*�ú�������SearchBinTree�Ƚ��������ݣ�����1���ͱ��ȽϽڵ����ݴ�С*/
int data_bintree_search_smsp_nbr_rent(void *pValue,void*pData)
{
	struct SmspNbrRentStatStruct *pSource=(struct SmspNbrRentStatStruct *)pValue;
	struct SmspNbrRentStatStruct *pTarget=(struct SmspNbrRentStatStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;
	
	if((res=strcmp(pSource->sMoFlag,pTarget->sMoFlag))!=0) return res;
 	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
 	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
 	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
 	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) return res;
 	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) return res;
 	if((res=strcmp(pSource->sSpServiceCode,pTarget->sSpServiceCode))!=0) return res;
 	if((res=strcmp(pSource->sBillingType,pTarget->sBillingType))!=0) return res;
 	if((res=pSource->iRentRate-pTarget->iRentRate)!=0) return res;

	return res;

}
/*�ú������ڽ��������ݼ��ص�ƽ���������*/
/*pHeadָ��ָ������ݲ�Ϊ��*/
void assign_bintree_insert_smsp_nbr_rent(void **ppData,void *pData)
{
	struct SmspNbrRentStatStruct *pValue=(struct SmspNbrRentStatStruct *)pData;
	struct SmspNbrRentStatStruct *pTemp;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SmspNbrRentStatStruct));
		ERROR_EXIT(pTemp==NULL,"����SmsNbrStatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct SmspNbrRentStatStruct));

		
		strcpy(pTemp->sMoFlag,pValue->sMoFlag);
		strcpy(pTemp->sMsisdn,pValue->sMsisdn);
		strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
        	strcpy(pTemp->sUserType,pValue->sUserType);
		strcpy(pTemp->sSpCode,pValue->sSpCode);
		strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
		strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
		strcpy(pTemp->sBillingType,pValue->sBillingType);
        	pTemp->iRentRate=pValue->iRentRate;

		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧ�ۼӷ���*/
	pTemp=(*ppData);
	strcpy(pTemp->sMoFlag,pValue->sMoFlag);
	strcpy(pTemp->sMsisdn,pValue->sMsisdn);
	strcpy(pTemp->sHomeAreaCode,pValue->sHomeAreaCode);
        strcpy(pTemp->sUserType,pValue->sUserType);
	strcpy(pTemp->sSpCode,pValue->sSpCode);
	strcpy(pTemp->sSpAccNbr,pValue->sSpAccNbr);
	strcpy(pTemp->sSpServiceCode,pValue->sSpServiceCode);
	strcpy(pTemp->sBillingType,pValue->sBillingType);
        pTemp->iRentRate=pValue->iRentRate;
}

int node_head_smsp_nbr_stat_e(void **ppHead)
{
	struct SmspNbrStatStruct *ptHead,*pTemp;
	
	pTemp=(*ppHead);
	while(pTemp!=NULL){

		ptHead=pTemp;
		pTemp=pTemp->pNext;

		InsertList((LIST**)&ptNPHead,(LIST*)ptHead);
	}
	return 0;
}

int node_head_smsp_sp_stat_e(void **ppHead)
{
	struct SmspSpStatStruct *ptHead,*pTemp;
	
	pTemp=(*ppHead);
	while(pTemp!=NULL){

		ptHead=pTemp;
		pTemp=pTemp->pNext;

		InsertList((LIST**)&ptSPHead,(LIST*)ptHead);
	}
	return 0;
}

int node_head_smsp_nbr_rent_stat_e(void **ppHead)
{
	struct SmspNbrRentStatStruct *ptHead,*pTemp;
	
	pTemp=(*ppHead);
	while(pTemp!=NULL){

		ptHead=pTemp;
		pTemp=pTemp->pNext;

		InsertList((LIST**)&ptNRHead,(LIST*)ptHead);
	}
	return 0;
}

int node_head_sms_nbr_stat_e(void **ppHead)
{
	struct SmsNbrStatStruct *pPre,*ptCur;
	
	ptCur=(*ppHead);
	while(ptCur!=NULL){

		pPre=ptCur;
		ptCur=ptCur->pNext;

		InsertList((LIST**)&ptSmHead,(LIST*)pPre);
	}
	return 0;
}
int main(int argc,char *argv[])
{
	char sType[1],sCondition[256],sStatType[1];
	char sBillingCycle[6],sTableName[30],sSourceTableName[30];
	
	if(argc!=6){
		printf("�÷���%s tablename wherecause sType[M,P] billingcycleid sStatType.\n",argv[0]);
		printf("sStatType:1 ��ʾͳ��SMSP_NBR_RENT_STAT.\n");
		printf("sStatType:2 ��ʾͳ��SMSP_SP_STAT.\n");
		printf("sStatType:3 ��ʾͳ��SMSP_NBR_STAT.\n");
		printf("sStatType:0 ��ʾȫ��ͳ��.\n");
		printf("sStatType:4 ��ʾͳ��SMSP_NBR_STAT_ZB.\n");
		exit(1);
	}
	
	InitAppRes(argv[0]);
	IniConnect("dataconnstr");

	strcpy(sSourceTableName,argv[1]);
	strcpy(sCondition,argv[2]);
        Upper(sSourceTableName);

	strcpy(sType,argv[3]);
	strcpy(sBillingCycle,argv[4]);
	Upper(sBillingCycle);
	sBillingCycle[6]=0;
		
	strcpy(sStatType,argv[5]);

	if(strncmp(sStatType,"3",1)==0){
		strcpy(sTableName,"SMSP_NBR_STAT");
	}

	if(strncmp(sStatType,"4",1)==0){
		strcpy(sTableName,"SMSP_NBR_STAT_ZB");
	}

	if(strncmp(sType,"M",1)==0){
		strcpy(sTableName,"SMS_NBR_STAT");
		node_head_e=node_head_sms_nbr_stat_e;
		Stat2Bintree=SmsNbrStat2Bintree;

		/*���ݼ���*/
		if(SmsStatTicket2Bintree(&pRoot,sSourceTableName,sCondition)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
		/*�������ŵ�������*/
		ptSmHead=NULL;
	        TravelBin(pRoot,node_head_e);
		/*��ƽ��������ͷ�*/
	        DestroyBin(pRoot);
	        
		/*����ͳ�Ʊ�����*/
		if(Stat2Bintree(&pSmsRoot,sTableName,sBillingCycle)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}

		/*���ݽ��кϲ���updata���ݺ�insert����*/	
		if(SmsNbrStatDataSum(&pSmsRoot,ptSmHead,
			sBillingCycle,sTableName)<0){
			printf("дͳ�Ʊ� %s ����.\n",sTableName);
			return -1;
		};
		DestroyBin(pSmsRoot);
	}
	else if(strncmp(sType,"P",1)==0){
	
	/*��ͳ�ƻ������ݼ���*/
		if(SmsTicket2Bintree(&pRoot,&pRootS,&pRootN,
			sSourceTableName,sCondition,sStatType)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
	/*��spͳ��a�����ŵ�������*/
		if(strncmp(sStatType,"1",1)==0||strncmp(sStatType,"0",1)==0){
			ptNRHead=NULL;
			node_head_e=node_head_smsp_nbr_rent_stat_e;
		        TravelBin(pRoot,node_head_e);
			/*��ƽ��������ͷ�*/
		        DestroyBin(pRoot);
		/*����ͳ��a����*/
		        strcpy(sTableName,"SMSP_NBR_RENT_STAT");
			Stat2Bintree=SmspNbrRentStat2Bintree;
			/*����ͳ�Ʊ�����*/
			if(Stat2Bintree(&pSmsRoot,sTableName,sBillingCycle)<0){
				WriteAlertMsg("����BINTREEʧ��");
				return -1;
			}
			/*���ݽ��кϲ���insert����*/	
			if(SmspNbrRentStatDataSum(&pSmsRoot,ptNRHead,sBillingCycle,sTableName)<0){
				printf("дͳ�Ʊ� %s ����.\n",sTableName);
				return -1;
			}
			DestroyBin(pSmsRoot);
		}
	/*��spͳ��b�����ŵ�������*/
		if(strncmp(sStatType,"2",1)==0||strncmp(sStatType,"0",1)==0){	
			ptSPHead=NULL;			        
			node_head_e=node_head_smsp_sp_stat_e;
		        TravelBin(pRootS,node_head_e);
			/*��ƽ��������ͷ�*/
		        DestroyBin(pRootS);
		/*����ͳ��b����*/
			strcpy(sTableName,"SMSP_SP_STAT");
			Stat2Bintree=SmspSpStat2Bintree;
			/*����ͳ�Ʊ�����*/
			if(Stat2Bintree(&pSpRootS,sTableName,sBillingCycle)<0){
				WriteAlertMsg("����BINTREEʧ��");
				return -1;
			}
			
			/*���ݽ��кϲ���insert����*/	
			if(SmspSpStatStructDataSum(&pSpRootS,ptSPHead,sBillingCycle,sTableName)<0){
				printf("дͳ�Ʊ� %s ����.\n",sTableName);
				return -1;
			}
			DestroyBin(pSpRootS);
		}
	/*��spͳ��c�����ŵ�������*/
		if(strncmp(sStatType,"3",1)==0||
			strncmp(sStatType,"4",1)==0||
			strncmp(sStatType,"0",1)==0){	
			ptNPHead=NULL;			        
			node_head_e=node_head_smsp_nbr_stat_e;
		        TravelBin(pRootN,node_head_e);
			/*��ƽ��������ͷ�*/
		        DestroyBin(pRootN);
		/*����ͳ��c����*/
			Stat2Bintree=SmspNbrStat2Bintree;
			/*����ͳ�Ʊ�����*/
			if(Stat2Bintree(&pSpRootN,sTableName,sBillingCycle)<0){
				WriteAlertMsg("����BINTREEʧ��");
				return -1;
			}
			
			/*���ݽ��кϲ���insert����*/	
			if(SmspNbrStatStructDataSum(&pSpRootN,ptNPHead,sBillingCycle,sTableName)<0){
				printf("дͳ�Ʊ� %s ����.\n",sTableName);
				return -1;
			}
			
			DestroyBin(pSpRootN);
		}	        
	}
	else{
		printf("sType=%s ������\n",sType);
		return -1;
	}
	CommitWorkRelease();	
	
	DisconnectDatabase();
	return 0;
}
