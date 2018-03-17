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

#include "stt_ticket.h"
#include "ticket_field.h"
#include "spzb_supp.h"

BINTREE *pRootsj=NULL;
BINTREE *pRootchkys=NULL;
BINTREE *pRootchksj=NULL;
struct MxTicketUpStruct *pstat=NULL;
struct YssjChkStruct *ptchk=NULL;

void mvitem_spsjticketup2mxup(struct SpTicketSjStruct *pi,
	struct MxTicketUpStruct *po);
void mvitem_smspnbrstat2mxup(struct RSmspNbrStatStruct *pi,
	struct MxTicketUpStruct *po);
void mvitem_mxticketup(struct MxTicketUpStruct *pi,
	struct MxTicketUpStruct *po);
int data_search_bintree_mx_up_e(void *pValue,void*pData);
void assign_insert_bintree_mx_up_e(void **ppData,void *pData);


void mvitem_spsjticketup2yssjchk(struct SpTicketSjStruct *pi,
	struct YssjChkStruct *po);
void mvitem_smspnbrstat2yssjchk(struct RSmspNbrStatStruct *pi,
	struct YssjChkStruct *po);
void mvitem_yssjchk(struct YssjChkStruct *pi,struct YssjChkStruct *po);	
void mvitem_yssjchk2s(struct YssjChkStruct *pi,
	struct YssjChkStruct *po);

int MountSpTicketSj2Bin(BINTREE **ppRoot,char sTableName[])
{
	int iCnt=0;
	
	struct SpTicketSjStruct Temp;
	struct SpTicketSjStructIn TempIn;
	
	struct MxTicketUpStruct mxup;
	struct YssjChkStruct yssjchk;
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,"");

	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSpTicketSjToStruct(&Temp,&TempIn)){
		
		if(ChkSpCode(Temp.sSpCode,Temp.sSpAccNbr,"")<0)continue;
/*Ƿ���嵥��*/
		mvitem_spsjticketup2mxup(&Temp,&mxup);
		
		if(InsertBin(ppRoot,(void *)&mxup,
			data_search_bintree_mx_up_e,
			assign_insert_bintree_mx_up_e)<0){
			WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
			return -1;
		}
/*Ӧ��ʵ�պ˶Ա�*/
		mvitem_spsjticketup2yssjchk(&Temp,&yssjchk);

		if(InsertBin(&pRootchksj,(void *)&yssjchk,
			data_search_bintree_yssjchk_e,
			assign_insert_bintree_yssjchk_e)<0){
			WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
			return -1;
		}

		if(++iCnt%10000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("���ر�%s��¼����ϣ��ܼ�¼��%d",TempIn.sTableName,iCnt);
	return iCnt;	
}

int data_search_bintree_mx_up_e(void *pValue,void*pData)
{               	
	struct MxTicketUpStruct *pSource=(struct MxTicketUpStruct *)pValue;
	struct MxTicketUpStruct *pTarget=(struct MxTicketUpStruct *)pData;
	int res=0;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) 
		return res;	
	if((res=strcmp(pSource->sVisitCityCode,pTarget->sVisitCityCode))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) 
		return res;

	return res;
}
void assign_insert_bintree_mx_up_e(void **ppData,void *pData)
{
	int iMxFee=0;
	
	struct MxTicketUpStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct MxTicketUpStruct));
		ERROR_EXIT(pTemp==NULL,"����MxTicketUpStruct�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct MxTicketUpStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	
	iMxFee=atoi(pTemp->sMxFee)+
		atoi(((struct MxTicketUpStruct*)pData)->sMxFee);
	
	sprintf(pTemp->sMxFee,	"%d",iMxFee);

}


void mvitem_spsjticketup2mxup(struct SpTicketSjStruct *pi,
	struct MxTicketUpStruct *po)
{
	bzero((void*)po,sizeof(struct MxTicketUpStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sVisitCityCode,pi->sHomeAreaCode);
	strncpy(po->sSpCode,pi->sSpCode,5);
	strcpy(po->sSpServiceType,pi->sSpServiceType);
	
	sprintf(po->sMxFee,	"%d",pi->iSjFee+pi->iTpFee);
	
}
void mvitem_spsjticketup2yssjchk(struct SpTicketSjStruct *pi,
	struct YssjChkStruct *po)
{
	bzero((void*)po,sizeof(struct YssjChkStruct));

	strncpy(po->sSpCode,pi->sSpCode,5);
	strcpy(po->sSpAccNbr,pi->sSpAccNbr);
	strcpy(po->sSpServiceType,pi->sSpServiceType);
	strcpy(po->sCityCode,pi->sHomeAreaCode);

	strcpy(po->sYsFee,"0");
	sprintf(po->sSjFee,	"%d",pi->iSjFee);
	sprintf(po->sTpFee,	"%d",pi->iTpFee);
	sprintf(po->sRenegeFee,	"%d",pi->iRenegeFee);
	sprintf(po->sAdjustFee,	"%d",pi->iAdjustFee);

	po->iRate=0;
	
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);
}
int MountSmspNbrStat2Bin(BINTREE **ppRoot,char sTableName[],char sBillingCycleID[])
{
	int iCnt=0;
	
	struct RSmspNbrStatStruct Temp;
	struct RSmspNbrStatStructIn TempIn;
	
	struct MxTicketUpStruct mxup;
	struct YssjChkStruct	yssjchk;
	
	strcpy(TempIn.sTableName,sTableName);

	sprintf(TempIn.sCondition,"\n\
		WHERE BILLING_CYCLE_ID='%s'",sBillingCycleID);
	
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSmspNbrStatToStruct(&Temp,&TempIn)){

		if(ChkSpCode(Temp.sSpCode,Temp.sSpAccNbr,"")<0)continue;
/*Ƿ���嵥��*/
		mvitem_smspnbrstat2mxup(&Temp,&mxup);
		
		if(InsertBin(ppRoot,(void *)&mxup,
			data_search_bintree_mx_up_e,
			assign_insert_bintree_mx_up_e)<0){
			WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
			return -1;
		}
		
/*Ӧ��ʵ�պ˶Ա�*/
		mvitem_smspnbrstat2yssjchk(&Temp,&yssjchk);

		if(InsertBin(&pRootchkys,(void *)&yssjchk,
			data_search_bintree_yssjchk_e,
			assign_insert_bintree_yssjchk_e)<0){
			WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
			return -1;
		}
		
		if(++iCnt%10000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("���ر�%s��¼����ϣ��ܼ�¼��%d",TempIn.sTableName,iCnt);
	return iCnt;	
}

void mvitem_smspnbrstat2mxup(struct RSmspNbrStatStruct *pi,
	struct MxTicketUpStruct *po)
{
	char sSStartTime[15];
	struct SpContactRelationStruct *pS=NULL;

	bzero((void*)po,sizeof(struct MxTicketUpStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	SetHomeAreaCode(pi->sHomeAreaCode,po->sVisitCityCode);
	strcpy(po->sSpCode,pi->sSpCode);

/*ȡ��sp����*/
	strcpy(po->sSpServiceType,pi->sHomeAreaCode+3);
	if(strlen(po->sSpServiceType)!=2){
		strcpy(sSStartTime,pi->sBillingCycleID);
		strcpy(sSStartTime+6,"02000000");sSStartTime[14]=0;
		
		if(SearchSpContactRelation(pi->sSpCode,"",
			pi->sSpAccNbr,sSStartTime,&pS)==NOTFOUND)
			strcpy(po->sSpServiceType,"90");
		else	strcpy(po->sSpServiceType,pS->sServiceType);
	}

	sprintf(po->sMxFee,"%d",pi->iTotalInfoFee+pi->iTotalRentFee);
	
}
void mvitem_smspnbrstat2yssjchk(struct RSmspNbrStatStruct *pi,
	struct YssjChkStruct *po)
{
	char sSStartTime[15];
	struct SpContactRelationStruct *pS=NULL;

	bzero((void*)po,sizeof(struct YssjChkStruct));
	
	strcpy(po->sSpCode,pi->sSpCode);
	strcpy(po->sSpAccNbr,pi->sSpAccNbr);
	
/*ȡ��sp����*/
	strcpy(po->sSpServiceType,pi->sHomeAreaCode+3);
	if(strlen(po->sSpServiceType)!=2){
		strcpy(sSStartTime,pi->sBillingCycleID);
		strcpy(sSStartTime+6,"02000000");sSStartTime[14]=0;
		
		if(SearchSpContactRelation(pi->sSpCode,"",
			pi->sSpAccNbr,sSStartTime,&pS)==NOTFOUND)
			strcpy(po->sSpServiceType,"90");
		else	strcpy(po->sSpServiceType,pS->sServiceType);
	}
	
	SetHomeAreaCode(pi->sHomeAreaCode,po->sCityCode);
	
	sprintf(po->sYsFee,"%d",pi->iTotalInfoFee+pi->iTotalRentFee);
	strcpy(po->sSjFee,"0");
	strcpy(po->sTpFee,"0");
	po->iRate=0;

	strcpy(po->sBillingCycleID,pi->sBillingCycleID);
}
void mvitem_mx2mxs(struct MxTicketUpStruct *pi,
	struct MxTicketUpStruct *po)
{
	bzero((void*)po,sizeof(struct MxTicketUpStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sVisitCityCode,pi->sVisitCityCode);	
	strcpy(po->sSpCode,pi->sSpCode);
	strcpy(po->sSpServiceType,pi->sSpServiceType);
}
void mvitem_mxticketup(struct MxTicketUpStruct *pi,struct MxTicketUpStruct *po)
{/*�����ƶ�����*/

	bzero((void*)po,sizeof(struct MxTicketUpStruct));

		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpServiceType,	pi->sSpServiceType,2);
		strncpy(po->sMxFee,		pi->sMxFee,6);
		strncpy(po->sMxType,		pi->sMxType,3);
		strncpy(po->sReserv1,		pi->sReserv1,8);
		strncpy(po->sReserv2,		pi->sReserv2,5);
		strncpy(po->sReserv3,		pi->sReserv3,10);
		strncpy(po->sReserv4,		pi->sReserv4,10);
}

int DealMx(struct MxTicketUpStruct *pi,char sOutTableName[])
{
	int iTotalCnt=0,iCnt=0,iFee=0;
	struct MxTicketUpStruct *ptHead,*pTemp;
	struct MxTicketUpStruct s,mxup,*pHead=NULL;

	static int iFirstFlag=true;
        static struct MxTicketUpStructOut TempOut;
        
	if(iFirstFlag==true){
		bzero((void*)&TempOut,sizeof(struct MxTicketUpStructOut));
		strcpy(TempOut.sTableName,sOutTableName);
		iFirstFlag=false;
	}
	
	ptHead=pi;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_mx2mxs(pTemp,&s);
		mvitem_mxticketup(pTemp,&mxup);
		
		strcpy(mxup.sUserType,"0");
		
		/*���Ҽ�¼�Ƿ���ʵ����*/
		if((SearchBin(pRootsj,(void*)&s,
			data_search_bintree_mx_up_e,
			(void**)&pHead))==NOTFOUND){
		/*δ�ҵ�ʵ�ռ�¼Ϊȫ��Ƿ��,����Ϊ0�Ĳ����*/
			
			if(atoi(pTemp->sMxFee)==0)continue;
			iTotalCnt++;
			strcpy(mxup.sMxType,"000");
			
			if(EInsertStructToMxTicketUp(&mxup,FALSE,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
				return -1;
			}
			continue;
		}
		iFee=atoi(pTemp->sMxFee)-atoi(pHead->sMxFee);
		
		/*ȫ���ջط���*/
		if(iFee==0)continue;
		
		sprintf(mxup.sMxFee,"%d",iFee);
		/*����Ƿ��*/
		if(iFee>0)strcpy(mxup.sMxType,"001");
		else	strcpy(mxup.sMxType,"002");
		
		iTotalCnt++;
		if(EInsertStructToMxTicketUp(&mxup,FALSE,&TempOut)<0){
			WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
			printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
			return -1;
		}
		if(++iCnt%10000==0){
			if(EInsertStructToMxTicketUp(NULL,true,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
				return -1;
			}
			WriteProcMsg("������¼��%d,�����¼��%d",iCnt,iTotalCnt);
			CommitWork();
		}
		

	}
	
	if(EInsertStructToMxTicketUp(NULL,true,&TempOut)<0){
		printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
		return -1;
	}
	WriteProcMsg("������ϣ���������¼��%d,�����%s��¼��%d",iCnt,sOutTableName,iTotalCnt);
	printf("������ϣ���������¼��%d,�����%s��¼��%d.\n",iCnt,sOutTableName,iTotalCnt);
	
	CommitWork();

	return 0;
}

void mvitem_yssjchk2s(struct YssjChkStruct *pi,
	struct YssjChkStruct *po)
{
	bzero((void*)po,sizeof(struct YssjChkStruct));
	
	strcpy(po->sSpCode,pi->sSpCode);
	strcpy(po->sSpAccNbr,pi->sSpAccNbr);	
	strcpy(po->sSpServiceType,pi->sSpServiceType);
	strcpy(po->sCityCode,pi->sCityCode);
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);
}
void mvitem_yssjchk(struct YssjChkStruct *pi,struct YssjChkStruct *po)
{/*�����ƶ�����*/

	bzero((void*)po,sizeof(struct YssjChkStruct));

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sSpServiceType,	pi->sSpServiceType,2);
		strncpy(po->sCityCode,		pi->sCityCode,3);
		strncpy(po->sYsFee,		pi->sYsFee,12);
		strncpy(po->sSjFee,		pi->sSjFee,12);
		strncpy(po->sTpFee,		pi->sTpFee,12);

		po->iRate=			pi->iRate;

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
}

int DealYssjChk(struct YssjChkStruct *pi,char sOutTableName[])
{
	int iTotalCnt=0,iCnt=0,iRate=0;
	double	dRate;
	struct YssjChkStruct *ptHead,*pTemp;
	struct YssjChkStruct s,yssjchk,*pHead=NULL;

	static int iFirstFlag=true;
        static struct YssjChkStructOut TempOut;
        
	if(iFirstFlag==true){
		bzero((void*)&TempOut,sizeof(struct YssjChkStructOut));
		strcpy(TempOut.sTableName,sOutTableName);
		iFirstFlag=false;
	}
	
	ptHead=pi;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_yssjchk2s(pTemp,&s);
		mvitem_yssjchk(pTemp,&yssjchk);
		
	
		/*���Ҽ�¼�Ƿ���ʵ����*/
		if((SearchBin(pRootchksj,(void*)&s,
			data_search_bintree_yssjchk_e,
			(void**)&pHead))==NOTFOUND){
		/*δ�ҵ�ʵ�ռ�¼*/
			
			iTotalCnt++;
			if(atoi(pTemp->sYsFee)==0)yssjchk.iRate=0;
			else yssjchk.iRate=1000;
			
			if(EInsertStructToYssjChk(&yssjchk,FALSE,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
				return -1;
			}
			continue;
		}
		iRate=atoi(pTemp->sYsFee)-atoi(pHead->sSjFee)-atoi(pHead->sTpFee);
		
		if(iRate==0){
			yssjchk.iRate=0;
		}
		else if(iRate<0){
			yssjchk.iRate=-999;
		}
		else{
			dRate=iRate*1.0/atoi(pTemp->sYsFee);
			yssjchk.iRate=dRate*1000;
		}
	
		strcpy(yssjchk.sSjFee,		pHead->sSjFee);
		strcpy(yssjchk.sTpFee,		pHead->sTpFee);

		iTotalCnt++;
		if(EInsertStructToYssjChk(&yssjchk,FALSE,&TempOut)<0){
			WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
			printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
			return -1;			
		}
		if(++iCnt%10000==0){
			if(EInsertStructToYssjChk(NULL,true,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
				return -1;
			}
			WriteProcMsg("������¼��%d,�����¼��%d",iCnt,iTotalCnt);
			CommitWork();
		}
		

	}
	
	if(EInsertStructToYssjChk(NULL,true,&TempOut)<0){
		printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
		return -1;
	}
	WriteProcMsg("������ϣ���������¼��%d,�����%s��¼��%d",iCnt,sOutTableName,iTotalCnt);
	printf("������ϣ���������¼��%d,�����%s��¼��%d.\n",iCnt,sOutTableName,iTotalCnt);
	
	CommitWork();

	return 0;
}

int link_stat(void **ppData)
{
	InsertList((LIST**)&pstat,(LIST*)(*ppData));
	return 0;
}
int link_chkys(void **ppData)
{
	InsertList((LIST**)&ptchk,(LIST*)(*ppData));
	return 0;
}
int main(int argc,char *argv[])
{
	char sSpSjTable[31],sOutputTable[31],sBillingCycleID[7];
	
	BINTREE *pRootstat=NULL;
	
	if(argc!=4){
		printf("Usage %s sp_ticket_sj_xx mx_ticket_up_xx BillingCycleID .\n",argv[0]);
		return -1;
	}

	InitAppRes(argv[0]);
	strcpy(sSpSjTable,argv[1]);Upper(sSpSjTable);
	strcpy(sOutputTable,argv[2]);Upper(sOutputTable);
	strcpy(sBillingCycleID,argv[3]);sBillingCycleID[6]=0;

	
	if(ConnectDataDB()<0) return -1;

/*����Ӧ��ͳ�����ݵ�BINTREE*/
	if(MountSmspNbrStat2Bin(&pRootstat,"SMSP_NBR_STAT_ZB",sBillingCycleID)<=0) return -1;
	
/*����ʵ�����ݵ�BINTREE*/
	if(MountSpTicketSj2Bin(&pRootsj,sSpSjTable)<=0) return -1;

/*Ӧ��ͳ�����ݹҵ�pstat��*/
	TravelBin(pRootstat,link_stat);

/*�õ�Ƿ�����ݲ��������*/
	DealMx(pstat,sOutputTable);

/*Ӧ��chk�ҵ�ptchk��*/
	TravelBin(pRootchkys,link_chkys);

/*�õ�Ӧ��ʵ�պ˶����ݲ��������*/
	DealYssjChk(ptchk,"YSSJ_CHK");


	DisconnectDatabase();
	return 0;	
}