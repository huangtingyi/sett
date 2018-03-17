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

/*�����ṹ����*/
struct TpUpStruct{

	struct TpUpStruct *pNext;
	char    sMsisdn[16];		/* �û����� */
	char    sVisitCityCode[4];	/* �û��������д��� */
	char    sSpCode[6];		/* SP���� */
	char    sSpAccNbr[13];		/* SP������ */
	char    sSpServiceType[3];	/* SPҵ������ */
	int     iTpFee;			/* ������Ϣ�� */
	struct TpUpStruct *pLoadNext;
};

void mvitem_tpticketup2tpup(struct TpTicketUpStruct *pi,
	struct TpUpStruct *po);
	
int data_search_bintree_tp_up_e(void *pValue,void*pData);
void assign_insert_bintree_tp_up_e(void **ppData,void *pData);

int MountTpTicketUp2Bin(BINTREE **ppRoot,char sTableName[])
{
	int iCnt=0;
	
	struct TpTicketUpStruct Temp;
	struct TpTicketUpStructIn TempIn;
	
	struct TpUpStruct tpup;
	
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,"");

	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetTpTicketUpToStruct(&Temp,&TempIn)){
		
		mvitem_tpticketup2tpup(&Temp,&tpup);
		
		if(InsertBin(ppRoot,(void *)&tpup,
			data_search_bintree_tp_up_e,
			assign_insert_bintree_tp_up_e)<0){
			WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
			return -1;
		}
		if(++iCnt%10000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("���ر�%s��¼����ϣ��ܼ�¼��%d",TempIn.sTableName,iCnt);
	return 0;	
}

int data_search_bintree_tp_up_e(void *pValue,void*pData)
{               	
	struct TpUpStruct *pSource=(struct TpUpStruct *)pValue;
	struct TpUpStruct *pTarget=(struct TpUpStruct *)pData;
	int res=0;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) 
		return res;	
	if((res=strcmp(pSource->sVisitCityCode,pTarget->sVisitCityCode))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) 
		return res;

	return res;
}
void assign_insert_bintree_tp_up_e(void **ppData,void *pData)
{
	struct TpUpStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct TpUpStruct));
		ERROR_EXIT(pTemp==NULL,"����TpUpStruct�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct TpUpStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	pTemp->iTpFee+=((struct TpUpStruct*)pData)->iTpFee;

}
void mvitem_tpticketup2tpup(struct TpTicketUpStruct *pi,
	struct TpUpStruct *po)
{
	char sSStartTime[15];
	struct SpContactRelationStruct *pS=NULL;

	bzero((void*)po,sizeof(struct TpUpStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sVisitCityCode,pi->sVisitCityCode);
	strcpy(po->sSpCode,pi->sSpCode);
	strcpy(po->sSpServiceType,pi->sSpServiceType);
	
	po->iTpFee=atoi(pi->sTpFee);
	
	strcpy(sSStartTime,pi->sTpTime);
	strcpy(sSStartTime+8,"000000");sSStartTime[14]=0;

/*ȡ��sp����*/
	if(SearchSpContactRelation(po->sSpCode,"","SS",
		sSStartTime,&pS)==NOTFOUND)
		strcpy(po->sSpAccNbr,"");
	else	strcpy(po->sSpAccNbr,pS->sSpAccNbr);

}
void mvitem_spacctitemnew2tp(struct SpAcctItemNewStruct *pi,
	struct TpUpStruct *po)
{
	bzero((void*)po,sizeof(struct TpTicketUpStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sVisitCityCode,pi->sHomeAreaCode);	
	strcpy(po->sSpCode,pi->sSpCode);
	strcpy(po->sSpAccNbr,pi->sSpAccNbr);	
	strcpy(po->sSpServiceType,pi->sSpServiceType);
}
void mvitem_spacctitemnew2spsj(struct TpUpStruct *ps,
	struct SpAcctItemNewStruct *pi,struct SpTicketSjStruct *po)
{
	bzero((void*)po,sizeof(struct SpTicketSjStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sHomeAreaCode,pi->sHomeAreaCode);
	strcpy(po->sSpCode,	pi->sSpCode);
	strcpy(po->sSpServiceType,pi->sSpServiceType);
	strcpy(po->sSpAccNbr,pi->sSpAccNbr);
	
	po->iSjHdCnt=pi->iRecCnt;
	po->iSjFee=atoi(pi->sCharge);
	po->iTicketTypeID=pi->iTicketTypeID;

	strcpy(po->sServiceCode,pi->sServiceCode);
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);	
	strcpy(po->sPayCycleID,	pi->sPayCycleID);
	strcpy(po->sPayTime,    pi->sPayTime);
	
	if(ps!=NULL){
		po->iTpFee=ps->iTpFee;
	}	
}

int main(int argc,char *argv[])
{
	int iTotalCnt=0,iCnt=0;
	char sInputTable[31],sOutputTable[31],sTpTable[31],sCondition[256];
	BINTREE *pRoot=NULL;
	
	struct SpAcctItemNewStruct Temp;
	struct SpAcctItemNewStructIn TempIn;
	
	struct TpUpStruct *pTemp=NULL,s;
	
	struct SpTicketSjStruct spticketsj;
	struct SpTicketSjStructOut TempOut;

	if(argc!=5){
		printf("Usage %s sp_acct_item_detailzb_xx wherecause sp_ticket_sj_xx tp_ticket_up_xx.\n",argv[0]);
		return -1;
	}

	InitAppRes(argv[0]);
	strcpy(sInputTable,argv[1]);Upper(sInputTable);
	strcpy(sCondition,argv[2]);Upper(sCondition);
	strcpy(sOutputTable,argv[3]);Upper(sOutputTable);
	strcpy(sTpTable,argv[4]);Upper(sTpTable);
	
	if(ConnectDataDB()<0) return -1;
	
	/*�����������ݵ�BINTREE*/
	if(MountTpTicketUp2Bin(&pRoot,sTpTable)<0) return -1;


	/*��ʵ��ȡ��*/
	bzero((void*)&TempIn,sizeof(struct SpAcctItemNewStructIn));
	strcpy(TempIn.sTableName,sInputTable);
	sprintf(TempIn.sCondition,sCondition);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	
	bzero((void*)&TempOut,sizeof(struct SpTicketSjStructOut));
	strcpy(TempOut.sTableName,sOutputTable);

	/*��ȡ����ѭ������ʵ������ȡ����,�����*/
	while(EGetSpAcctItemNewToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;
		
		mvitem_spacctitemnew2tp(&Temp,&s);

/*������Դ���ΥԼ�ۿ���͵��ʽ������������⴦��*/

		/*���Ҽ�¼�Ƿ���������*/
		if((SearchBin(pRoot,(void*)&s,
			data_search_bintree_tp_up_e,
			(void**)&pTemp))==NOTFOUND){
		/*δ�ҵ������¼*/
			mvitem_spacctitemnew2spsj(NULL,&Temp,&spticketsj);
			
			spticketsj.iTpFee=0;
			iTotalCnt++;
			if(EInsertStructToSpTicketSj(&spticketsj,FALSE,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				return -1;
			}
			continue;
		}
		
		mvitem_spacctitemnew2spsj(pTemp,&Temp,&spticketsj);
			
		iTotalCnt++;
		if(EInsertStructToSpTicketSj(&spticketsj,FALSE,&TempOut)<0){
			WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
			return -1;
		}
		if(++iCnt%10000==0){
			if(EInsertStructToSpTicketSj(NULL,true,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				return -1;
			}
			WriteProcMsg("�����¼��%d,�����¼��%d",iCnt,iTotalCnt);
			CommitWork();
		}
		
	}

	if(EInsertStructToSpTicketSj(NULL,true,&TempOut)<0){
		printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
		return -1;
	}
	WriteProcMsg("������ϣ��������¼��%d,�����¼��%d",iCnt,iTotalCnt);
	printf("������ϣ��������¼��%d,�����¼��%d.\n",iCnt,iTotalCnt);
	CommitWork();

	DisconnectDatabase();
	return 0;	
}
