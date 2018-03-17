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
#include "wwsupp.h"


BINTREE *pRootys=NULL;
BINTREE *pRootsj=NULL;
BINTREE *pRootdisct=NULL;

char STYPE[31],SOUTPUTTABLE[31];
static int iTotalCnt=0,iSjCnt=0,iDisctCnt=0;


void mvitem_spsjticketup2spuserstat(struct SpTicketSjStruct *pi,
	struct SpUserStatStruct *po);
void mvitem_smspnbrstat2spuserstat(struct RSmspNbrStatStruct *pi,
	struct SpUserStatStruct *po);
void mvitem_spuserstat(struct SpUserStatStruct *pi,
	struct SpUserStatStruct *po);
void mvitem_spuserstatsj(struct SpUserStatStruct *pi,
	struct SpUserStatStruct *po);
void mvitem_spacctitem2spuserstat(struct SpAcctItemStruct *pi,
	struct SpUserStatStruct *po);

int data_search_bintree_spstatzb_e(void *pValue,void*pData)
{               	
	struct SpUserStatStruct *pSource=(struct SpUserStatStruct *)pValue;
	struct SpUserStatStruct *pTarget=(struct SpUserStatStruct *)pData;
	int res=0;

	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) 
		return res;
	if((res=(pSource->iContactID-pTarget->iContactID))!=0) 
		return res;	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) 
		return res;	
	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) 
		return res;	
	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0) 
		return res;	
	if((res=strcmp(pSource->sSpServiceCode,pTarget->sSpServiceCode))!=0)
		return res;	
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) 
		return res;	
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0) 
		return res;	
	
	return res;
}

void assign_insert_bintree_spstatzb_e(void **ppData,void *pData)
{

	struct SpUserStatStruct *pTemp,*ptHead;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SpUserStatStruct));
		ERROR_EXIT(pTemp==NULL,"����SpUserStatStruct�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct SpUserStatStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
		ptHead=(struct SpUserStatStruct *)pData;
		
		pTemp->iYsCommFee+=ptHead->iYsCommFee;
		pTemp->iYsInfoFee+=ptHead->iYsInfoFee;
		pTemp->iSjInfoFee+=ptHead->iSjInfoFee;
		pTemp->iDisctAmnt+=ptHead->iDisctAmnt;
		pTemp->iTpFee+=ptHead->iTpFee;
		pTemp->iRenegeFee+=ptHead->iRenegeFee;
		pTemp->iAdjustFee+=ptHead->iAdjustFee;
		pTemp->iUpCommFee+=ptHead->iUpCommFee;
		pTemp->iUpCnt+=ptHead->iUpCnt;
		pTemp->iDownCnt+=ptHead->iDownCnt;

}
int data_search_bintree_spstatbd_e(void *pValue,void *pData)
{
        struct SpUserStatStruct *pSource=(struct SpUserStatStruct *)pValue;
        struct SpUserStatStruct *pTarget=(struct SpUserStatStruct *)pData;

/*���ݱȽϲ���*/
	return pSource->iContactID-pTarget->iContactID;
}

void assign_insert_bintree_spstatbd_e(void **pptHead,void *pData)
{
	struct SpUserStatStruct *pTemp;
			
	if((pTemp=malloc(sizeof(struct SpUserStatStruct)))==NULL){
		WriteAlertPrint("�����ڴ� SpUserStatStruct ����");
		exit (1);
	}
	memcpy((void*)pTemp,pData,sizeof(struct SpUserStatStruct));
	InsertList((LIST**)pptHead,(LIST*)pTemp);

}

int MountSpTicketSj2Bin(char sTableName[])
{
	int iCnt=0,iTotalCntSj=0;
	
	struct SpTicketSjStruct Temp;
	struct SpTicketSjStructIn TempIn;
	
	struct SpUserStatStruct s,*pHead=NULL;
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,"");

	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSpTicketSjToStruct(&Temp,&TempIn)){
		
		iTotalCntSj++;
		
		if(ChkSpCode(Temp.sSpCode,Temp.sSpAccNbr,"")<0)continue;
		
		mvitem_spsjticketup2spuserstat(&Temp,&s);

	
		/*���Ҽ�¼�Ƿ���Ӧ�ռ�¼��*/
		if((SearchBin(pRootys,(void*)&s,
			data_search_bintree_spstatzb_e,
			(void**)&pHead))==NOTFOUND){
			continue;
		}
		
		if(pHead->iYsInfoFee==0)continue;
		if(pHead->iSjInfoFee!=0)continue;
		
		pHead->iSjInfoFee	=Temp.iSjFee;
		pHead->iTpFee		=Temp.iTpFee;
		pHead->iRenegeFee	=Temp.iRenegeFee;
		pHead->iAdjustFee	=Temp.iAdjustFee;
	
		if(++iCnt%30000==0)
			WriteProcMsg("���ر�%s��¼��%d,�ϲ���Ӧ����ϸ%d",TempIn.sTableName,iTotalCntSj,iCnt);
			
	}
	WriteProcMsg("���ر�%s��¼�����,�ܼ�¼��%d,�ϲ���Ӧ����ϸ%d",TempIn.sTableName,iTotalCntSj,iCnt);
	return iCnt;	
}


void mvitem_spsjticketup2spuserstat(struct SpTicketSjStruct *pi,
	struct SpUserStatStruct *po)
{
	bzero((void*)po,sizeof(struct SpUserStatStruct));

	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sHomeAreaCode,pi->sHomeAreaCode);
	
	if(IS_UNICOMCDMA(pi->sMsisdn))
		strcpy(po->sUserType,"C");
	else 	strcpy(po->sUserType,"G");
	
	po->iContactID=0;
	
	strncpy(po->sSpCode,pi->sSpCode,5);
	strcpy(po->sSpAccNbr,pi->sSpAccNbr);
	strcpy(po->sSpServiceCode,"");
	
	po->iTicketTypeID=pi->iTicketTypeID;
	
	strcpy(po->sSpServiceType,pi->sSpServiceType);
	
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);

}


void FmtSpAcctItem(struct SpAcctItemStruct *pData)
{
	if(strcmp(pData->sSpCode,"-1")==0)strcpy(pData->sSpCode,"");
	if(strcmp(pData->sSpServiceCode,"-1")==0)strcpy(pData->sSpServiceCode,"");

}

int MountSpAcctItem2Bin(char sTableName[],BINTREE **ppRoot)
{
	int iCnt=0;
	
	struct SpAcctItemStruct Temp;
	struct SpAcctItemStructIn TempIn;
	
	struct SpUserStatStruct s,*pHead=NULL;
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,"");

	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSpAcctItemToStruct(&Temp,&TempIn)){

		if(strcmp(Temp.sSpCode,"99999")==0&&
			(strcmp(Temp.sSpServiceCode,"99999")==0||
			strcmp(Temp.sSpServiceCode,"99998")==0))continue;

		FmtSpAcctItem(&Temp);
		if(atoi(Temp.sCharge)==0)continue;
		
		mvitem_spacctitem2spuserstat(&Temp,&s);

		if(InsertBin(ppRoot,(void *)&s,
			data_search_bintree_spstatzb_e,
			assign_insert_bintree_spstatzb_e)<0){
			WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
			return -1;
		}


		if(++iCnt%30000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("���ر�%s��¼�����,�ܼ�¼��%d",TempIn.sTableName,iCnt);
	return iCnt;	
}

void mvitem_spacctitem2spuserstat(struct SpAcctItemStruct *pi,
	struct SpUserStatStruct *po)
{

	bzero((void*)po,sizeof(struct SpUserStatStruct));

	strcpy(po->sMsisdn,pi->sMsisdn);
	strncpy(po->sSpCode,pi->sSpCode,5);
	strcpy(po->sSpServiceCode,pi->sSpServiceCode);
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);

/*	po->iTicketTypeID=pi->iTicketTypeID;*/

	po->iSjInfoFee=atoi(pi->sCharge);

}


void mvitem_spuserstatsj(struct SpUserStatStruct *pi,
	struct SpUserStatStruct *po)
{
	bzero((void*)po,sizeof(struct SpUserStatStruct));

	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sSpCode,pi->sSpCode);
	strcpy(po->sSpServiceCode,pi->sSpServiceCode);
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);

/*	po->iTicketTypeID=pi->iTicketTypeID;*/
	
	po->iSjInfoFee=pi->iSjInfoFee;

}

void FmtSmspNbrStat(struct RSmspNbrStatStruct *pData)
{
	if(strcmp(pData->sSpCode,"-1")==0)strcpy(pData->sSpCode,"");
	if(strcmp(pData->sSpServiceCode,"-1")==0)strcpy(pData->sSpServiceCode,"");
	if(strcmp(pData->sSpAccNbr,"-1")==0)strcpy(pData->sSpAccNbr,"");

}

int MountSmspNbrStat2Bin(char sTableName[],char sBillingCycleID[])
{
	int iCnt=0,iFee=0;
	
	struct RSmspNbrStatStruct Temp;
	struct RSmspNbrStatStructIn TempIn;
	
	struct SpUserStatStruct spuserstat,*pHead=NULL,s;
	
	strcpy(TempIn.sTableName,sTableName);

	sprintf(TempIn.sCondition,"\n\
		WHERE BILLING_CYCLE_ID='%s' ",sBillingCycleID);
	
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSmspNbrStatToStruct(&Temp,&TempIn)){
		
		if(ChkSpCode(Temp.sSpCode,Temp.sSpAccNbr,"")<0)continue;
		FmtSmspNbrStat(&Temp);
	
/*SP�û�����ϸ*/
		mvitem_smspnbrstat2spuserstat(&Temp,&spuserstat);

/*����SP��SP_CONTACT_RELATION�Ҳ���sp_code��sp_service_code�Ĳ�����ͳ��*/
		if(strcmp(STYPE,"BD")==0&&
			spuserstat.iContactID==0)continue;

		if(strcmp(STYPE,"ZB")==0){
			if(InsertBin(&pRootys,(void *)&spuserstat,
				data_search_bintree_spstatzb_e,
				assign_insert_bintree_spstatzb_e)<0){
				WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
				return -1;
			}
		}
		else{
		/*�ѱ���ʵ�պ�����Ӧ����ϸ��*/
			if(strcmp(STYPE,"BD")==0&&
				spuserstat.iSjInfoFee==0){
	
				mvitem_spuserstatsj(&spuserstat,&s);
				
				if(strlen(s.sSpServiceCode)>8)s.sSpServiceCode[8]=0;
				/*���Ҽ�¼�Ƿ���ʵ����*/
				if((SearchBin(pRootsj,(void*)&s,
					data_search_bintree_spstatzb_e,
					(void**)&pHead))==FOUND){

					if(pHead->iSjInfoFee!=0){

						if((iFee=pHead->iSjInfoFee-spuserstat.iYsInfoFee)>0){
							spuserstat.iSjInfoFee=spuserstat.iYsInfoFee;
							pHead->iSjInfoFee=iFee;
						}
						else{
							spuserstat.iSjInfoFee=pHead->iSjInfoFee;
							pHead->iSjInfoFee=0;
						}
						
						iSjCnt++;
					}
				}
			}
	
		/*�ѱ����Żݺ�����Ӧ����ϸ��*/
			if(strcmp(STYPE,"BD")==0&&
				spuserstat.iDisctAmnt==0){
	
				mvitem_spuserstatsj(&spuserstat,&s);
				if(strlen(s.sSpServiceCode)>8)s.sSpServiceCode[8]=0;
				/*���Ҽ�¼�Ƿ���ʵ����*/
				if((SearchBin(pRootdisct,(void*)&s,
					data_search_bintree_spstatzb_e,
					(void**)&pHead))==FOUND){
					if(pHead->iSjInfoFee!=0){

						if((iFee=pHead->iSjInfoFee-spuserstat.iYsInfoFee)>0){
							spuserstat.iDisctAmnt=spuserstat.iYsInfoFee;
							pHead->iSjInfoFee=iFee;
						}
						else{
							spuserstat.iDisctAmnt=pHead->iSjInfoFee;
							pHead->iSjInfoFee=0;
						}
						iDisctCnt++;
					}
				}		
			}
		
		
			if(InsertBin(&pRootys,&spuserstat,
				data_search_bintree_spstatbd_e,
				assign_insert_bintree_spstatbd_e)<0){
				WriteAlertMsg("����%s���ڴ���ʧ��",TempIn.sTableName);
				return -1;
			}
		}
		
		if(++iCnt%30000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("���ر�%s��¼����ϣ��ܼ�¼��%d",TempIn.sTableName,iCnt);
	return iCnt;	
}

void mvitem_smspnbrstat2spuserstat(struct RSmspNbrStatStruct *pi,
	struct SpUserStatStruct *po)
{
	struct SpContactRelationStruct *pS=NULL;

	bzero((void*)po,sizeof(struct SpUserStatStruct));

	strcpy(po->sMsisdn,pi->sMsisdn);
	
	SetHomeAreaCode(pi->sHomeAreaCode,po->sHomeAreaCode);
	
	strcpy(po->sUserType,pi->sUserType);
	strcpy(po->sSpCode,pi->sSpCode);
	strcpy(po->sSpAccNbr,pi->sSpAccNbr);
	
	po->iTicketTypeID=pi->iTicketTypeID;
	
	po->iContactID=0;
	
	if(strcmp(STYPE,"ZB")==0){
		strcpy(po->sSpServiceCode,"");
	/*ȡ��sp����*/
		strcpy(po->sSpServiceType,pi->sHomeAreaCode+3);
		if(strlen(po->sSpServiceType)!=2){
	
			if(SearchSpContactRelation(pi->sSpCode,"",
				pi->sSpAccNbr,pi->sMaxStartTime,&pS)==NOTFOUND)
				strcpy(po->sSpServiceType,"90");
			else	strcpy(po->sSpServiceType,pS->sServiceType);
		}
	}
	else{
		strcpy(po->sSpServiceCode,pi->sSpServiceCode);

		po->iContactID=GetContactId(pi->sSpCode,
			pi->sSpServiceCode,pi->sMaxStartTime);

		GetBinStr("SP_CONTACT_RELATION",po->iContactID,"",
			pi->sMaxStartTime,po->sSpServiceType);
	}
	po->iYsCommFee	=0;
	po->iYsInfoFee	=pi->iTotalInfoFee+pi->iTotalRentFee;
	po->iSjInfoFee	=0;
	po->iDisctAmnt	=0;
	po->iTpFee	=0;
	po->iRenegeFee	=0;
	po->iAdjustFee	=0;
	po->iUpCommFee	=pi->iTotalCommFee;
	po->iUpCnt	=pi->iMoCnt;
	po->iDownCnt	=pi->iMtCnt;
	
	po->iDiffCommFee	=0;
	po->iQfAmnt		=0;
	po->iSjBadRate		=0;
	po->iOutFee		=0;

	strcpy(po->sBillingCycleID,pi->sBillingCycleID);
	
}
int ModifyTicketTypeID(int iTicketTypeID,char sSpServiceType[])
{
	int i=0;
/*��ͳ�ƹ�ʽͬ�����޸�ticket_type_id*/
	i=0;
	if(strcmp(sSpServiceType,"01")==0)i=9127;
	else if(strcmp(sSpServiceType,"02")==0)i=9141;
	else if(strcmp(sSpServiceType,"03")==0)i=9131;
	else if(strcmp(sSpServiceType,"09")==0)i=9161;
	else if(strcmp(sSpServiceType,"")!=0)i=9100;
	
	if(i==0)i=iTicketTypeID;     
	
	return i;    

}
int GetContactId(char sSpCode[],char sSpServiceCode[],
	char sStartTime[])
{
	int  iContactID=0;
	char sTemp[20];

	iContactID=0;
	
	strcpy(sTemp,sSpCode);
	strcat(sTemp,sSpServiceCode);

	/*sp_code=23156,sp_service_code����*/		
	if(strcmp(sSpCode,"23156")==0&&
		strncmp(sSpServiceCode,"5",1)==0){

		strcpy(sTemp,sSpCode);
		strcpy(sSpServiceCode,sSpServiceCode);
		sSpServiceCode[3]=0;	
		strcat(sTemp,sSpServiceCode);
	}
	if(strcmp(sSpCode,"23156")==0&&
		strncmp(sSpServiceCode,"6135",4)==0){

		strcpy(sTemp,sSpCode);
		strcpy(sSpServiceCode,sSpServiceCode);
		sSpServiceCode[6]=0;	
		strcat(sTemp,sSpServiceCode);
	}

	GetBinInt("SP_CONTACT_RELATION",1,sTemp,
		sStartTime,&iContactID);
	if(iContactID==0)
		GetBinInt("SP_CONTACT_RELATION",1,
			sSpCode,sStartTime,&iContactID);
				
	return iContactID;
}

void mvitem_spuserstat(struct SpUserStatStruct *pi,struct SpUserStatStruct *po)
{/*�����ƶ�����*/

	bzero((void*)po,sizeof(struct SpUserStatStruct));

		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sUserType,		pi->sUserType,1);

		po->iContactID=			pi->iContactID;

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,20);

		po->iTicketTypeID=		pi->iTicketTypeID;

		strncpy(po->sSpServiceType,	pi->sSpServiceType,2);

		po->iYsCommFee=			pi->iYsCommFee;
		po->iYsInfoFee=			pi->iYsInfoFee;
		po->iSjInfoFee=			pi->iSjInfoFee;
		po->iDisctAmnt=			pi->iDisctAmnt;
		po->iTpFee=			pi->iTpFee;
		po->iRenegeFee=			pi->iRenegeFee;
		po->iAdjustFee=			pi->iAdjustFee;
		po->iUpCommFee=			pi->iUpCommFee;
		po->iUpCnt=			pi->iUpCnt;
		po->iDownCnt=			pi->iDownCnt;
		po->iDiffCommFee=		pi->iDiffCommFee;
		po->iQfAmnt=			pi->iQfAmnt;
		po->iSjBadRate=			pi->iSjBadRate;
		po->iOutFee=			pi->iOutFee;

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
}


int InsertSpUserStat(struct SpUserStatStruct *p,int iInsertFlag)
{
        static int iFirstFlag=TRUE;
        static struct SpUserStatStructOut TempOut;
        if(iFirstFlag==TRUE){
                iFirstFlag=FALSE;
                bzero((void*)&TempOut,sizeof(struct SpUserStatStructOut));
                strcpy(TempOut.sTableName,SOUTPUTTABLE);
        }
        return EInsertStructToSpUserStat(p,iInsertFlag,&TempOut);
}

int DealOutDb(void **ppData)
{
	int iRate=0;
	double	dRate;
	
	struct SpUserStatStruct *ptHead,*pTemp;
	struct SpUserStatStruct	pout;

	ptHead=(struct SpUserStatStruct*)*ppData;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_spuserstat(pTemp,&pout);
		
		if(pout.iYsInfoFee==0)pout.iSjBadRate=0;
		else if(pout.iYsInfoFee>0&&
			pout.iSjInfoFee==0)pout.iSjBadRate=1000;
		else{
		
			iRate=pout.iYsInfoFee-pout.iSjInfoFee;
			
			if(iRate==0)pout.iSjBadRate=0;
			else if(iRate<0)pout.iSjBadRate=-999;
			else{
				dRate=iRate*1.0/pout.iYsInfoFee;
				pout.iSjBadRate=dRate*1000;
			}
		
		}
		
		pout.iYsCommFee=pout.iUpCommFee+pout.iDiffCommFee;
		pout.iQfAmnt=pout.iYsInfoFee-pout.iSjInfoFee;
		
		iTotalCnt++;
		if(InsertSpUserStat(&pout,FALSE)<0){
			WriteAlertMsg("д���ݿ��%sʱ����",SOUTPUTTABLE);
			printf("д���ݿ��%sʱ����.\n",SOUTPUTTABLE);
			return -1;
		}
	       if(iTotalCnt%30000==0){
	                if(InsertSpUserStat(NULL,TRUE)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",SOUTPUTTABLE);
				printf("д���ݿ��%sʱ����.\n",SOUTPUTTABLE);
				return -1;
			}
	                WriteProcMsg("��ǰ������¼��%d,�������%s",iTotalCnt,SOUTPUTTABLE);
	        }		
	}
	
	return 0;
}

int StallSpSettOut(char sTableName[],char sBillingCycleID[])
{
	int iCnt=0,iTotalCharge=0,iAddUpCharge=0,iCharge=0;
	int iTicketTypeID=0,iFee=0,iAddTotalFee=0;
	double 	dRatio;
	
	struct SpUserStatStruct *ptCur,*ptPre,s;
	struct SpUserStatStruct *pTemp=NULL;

	struct SpAcctItemStruct Temp;
	struct SpAcctItemStructIn TempIn;
	
	strcpy(TempIn.sTableName,sTableName);

	sprintf(TempIn.sCondition,"\n\
		WHERE BILLING_CYCLE_ID='%s'",sBillingCycleID);
	
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSpAcctItemToStruct(&Temp,&TempIn)){
		
		bzero((void*)&s,sizeof(struct SpUserStatStruct));

		s.iContactID=atoi(Temp.sSpCode);

		/*����ָ�����ڵļ�¼�Ƿ���Ӧ����*/
		if((SearchBin(pRootys,(void*)&s,
			data_search_bintree_spstatbd_e,
			(void**)&pTemp))==NOTFOUND){
		/*δ�ҵ�Ӧ�ռ�¼*/
			continue;
		}


		/*����ܷ��ã��ܷ���Ϊ0�򲻷�̯*/
		iTotalCharge=0;
		
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;		
			
			ptPre->iTicketTypeID=ModifyTicketTypeID(ptPre->iTicketTypeID,ptPre->sSpServiceType);

			iTicketTypeID=ptPre->iTicketTypeID/10*10;
			if((iTicketTypeID-Temp.iTicketTypeID)!=0)continue;
			if(iTicketTypeID==9130)
				iTotalCharge+=ptPre->iYsInfoFee;
			else	iTotalCharge+=ptPre->iSjInfoFee;
			
			if(atoi(Temp.sCharge)<0)
				iTotalCharge+=ptPre->iUpCnt+ptPre->iDownCnt;
		}
		/*if(iTotalCharge<atoi(Temp.sCharge)){
		�������ô���Ӧ����ѽ��=Ӧ��
			sprintf(Temp.sCharge,"%d",iTotalCharge);
		}*/
		if(iTotalCharge<=0) printf("ContactID=%s.\n",Temp.sSpCode);
		/*��һ��ѭ�������÷�̯��*/
		iAddUpCharge=0;
		iAddTotalFee=0;
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			iTicketTypeID=ptPre->iTicketTypeID/10*10;
			if((iTicketTypeID-Temp.iTicketTypeID)!=0)continue;
			
			if(iTicketTypeID==9130)
				iFee=ptPre->iYsInfoFee;
			else	iFee=ptPre->iSjInfoFee;
			
			if(atoi(Temp.sCharge)<0)
				iFee=ptPre->iUpCnt+ptPre->iDownCnt;
			
		/*�������*/
			if(iTotalCharge!=0)
				dRatio=iFee*1.0/iTotalCharge;
			else
				dRatio=0;
			
			iAddTotalFee+=iFee;
			
			if(ptCur!=NULL){
				
				if((iTotalCharge-iAddTotalFee)>iFee){
					if(dRatio!=0){
						iCharge=(atoi(Temp.sCharge)*dRatio);
						iAddUpCharge+=iCharge;
					}
					else 
						iCharge=0;
				}
				else{
					iCharge=atoi(Temp.sCharge)-iAddUpCharge;
					iAddUpCharge+=iCharge;
				}
			}
			else{
				if(iFee!=0)
					iCharge=atoi(Temp.sCharge)-iAddUpCharge;
				else 
					iCharge=0;
			}
			
			ptPre->iOutFee=iCharge;
			
			if((atoi(Temp.sCharge)-iAddUpCharge)==0)continue;
		}
		if(++iCnt%30000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
		
	}
	
	WriteProcMsg("���ر�%s��¼����ϣ��ܼ�¼��%d",TempIn.sTableName,iCnt);
	return iCnt;	
			
}

int StallDiffCommFee(char sTableName[],char sBillingCycleID[])
{
	int iCnt=0,iTotalCharge=0,iAddUpCharge=0,iCharge=0;
	int iTicketTypeID=0,iMoMtCnt=0,iAddTotalFee=0;
	double 	dRatio;
	
	struct SpUserStatStruct *ptCur,*ptPre,s;
	struct SpUserStatStruct *pTemp=NULL;

	struct SpAcctItemStruct Temp;
	struct SpAcctItemStructIn TempIn;
	
	strcpy(TempIn.sTableName,sTableName);

	sprintf(TempIn.sCondition,"\n\
		WHERE BILLING_CYCLE_ID='%s'",sBillingCycleID);
	
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSpAcctItemToStruct(&Temp,&TempIn)){
		
		bzero((void*)&s,sizeof(struct SpUserStatStruct));

		s.iContactID=atoi(Temp.sSpCode);

		/*����ָ�����ڵļ�¼�Ƿ���Ӧ����*/
		if((SearchBin(pRootys,(void*)&s,
			data_search_bintree_spstatbd_e,
			(void**)&pTemp))==NOTFOUND){
		/*δ�ҵ�Ӧ�ռ�¼*/
			continue;
		}


		/*����ܷ��ã��ܷ���Ϊ0�򲻷�̯*/
		iTotalCharge=0;
		
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;		
			
			ptPre->iTicketTypeID=ModifyTicketTypeID(ptPre->iTicketTypeID,ptPre->sSpServiceType);
			
			iTicketTypeID=ptPre->iTicketTypeID/10*10;
			if((iTicketTypeID-Temp.iTicketTypeID)!=0)continue;
			
			if(strcmp(ptPre->sSpServiceType,"04")==0)
				iTotalCharge+=(ptPre->iYsInfoFee+500)/1000*97;
			else{
				iMoMtCnt=ptPre->iDownCnt-ptPre->iUpCnt;
				if(iMoMtCnt>=0)iTotalCharge+=iMoMtCnt;
			}	
		}
		/*if(iTotalCharge<atoi(Temp.sCharge)){
		�������ô���Ӧ����ѽ��=Ӧ��
			sprintf(Temp.sCharge,"%d",iTotalCharge);
		}*/
		/*if(iTotalCharge<=0) printf("ContactID=%s.\n",Temp.sSpCode);*/
		/*��һ��ѭ�������÷�̯��*/
		iAddUpCharge=0;
		iAddTotalFee=0;
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			iTicketTypeID=ptPre->iTicketTypeID/10*10;
			if((iTicketTypeID-Temp.iTicketTypeID)!=0)continue;
			
			iMoMtCnt=0;
			if(strcmp(ptPre->sSpServiceType,"04")==0)
				iMoMtCnt=(ptPre->iYsInfoFee+500)/1000*97;
			else{
				iMoMtCnt=ptPre->iDownCnt-ptPre->iUpCnt;
				if(iMoMtCnt<0)iMoMtCnt=0;
			}

			
		/*�������*/
			if(iTotalCharge!=0)
				dRatio=iMoMtCnt*1.0/iTotalCharge;
			else
				dRatio=0;
				
			iAddTotalFee+=iMoMtCnt;
			
			if(ptCur!=NULL){
				if((iTotalCharge-iAddTotalFee)>iMoMtCnt){
					if(dRatio!=0){
						iCharge=(atoi(Temp.sCharge)*dRatio);
						iAddUpCharge+=iCharge;
					}
					else 
						iCharge=0;
				}
				else{
					iCharge=atoi(Temp.sCharge)-iAddUpCharge;
					iAddUpCharge+=iCharge;
				}
			}
			else{
				if(iMoMtCnt!=0)
					iCharge=atoi(Temp.sCharge)-iAddUpCharge;
				else 
					iCharge=0;
				
			}
			ptPre->iDiffCommFee=iCharge;
			
			if((atoi(Temp.sCharge)-iAddUpCharge)==0)continue;
		}
		if(++iCnt%30000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
		
	}
	
	WriteProcMsg("���ر�%s��¼����ϣ��ܼ�¼��%d",TempIn.sTableName,iCnt);
	return iCnt;	
			
}


int main(int argc,char *argv[])
{
	char sSpSjTable[31],sSpYsTable[31],sSpDisctTable[31],sBillingCycleID[7];
	
       if(RLike(argv[0],"sp_user_stat_zb")==true){
                InitAppRes("sp_user_stat_zb");
                strcpy(STYPE,"ZB");
		if(argc!=5){
		        printf("Usage %s out_tablename BillingCycleID \
sj_tablename ys_stat_tablename.\n",argv[0]);
		        return -1;
		}       	
       }
        else if(RLike(argv[0],"sp_user_stat_bd")==true){
                InitAppRes("sp_user_stat_bd");
                strcpy(STYPE,"BD");
		if(argc!=6){
		        printf("Usage %s out_tablename BillingCycleID \
sj_tablename ys_stat_tablename sp_disct_detail_XX .\n",argv[0]);
		        return -1;
		}       	

		strcpy(sSpDisctTable,argv[5]);
		Upper(sSpDisctTable);
      
       }
        else{
                printf("����������Ϊ%s,%s .\n",
                        "sp_user_stat_zb","sp_user_stat_bd");
                return -1;
        }
	strcpy(SOUTPUTTABLE,argv[1]);Upper(SOUTPUTTABLE);  
	strcpy(sBillingCycleID,argv[2]);sBillingCycleID[6]=0;     
	strcpy(sSpSjTable,argv[3]);Upper(sSpSjTable);
	strcpy(sSpYsTable,argv[4]);Upper(sSpYsTable);

	if(ConnectDataDB()<0) return -1;

	if(strcmp(STYPE,"BD")==0){	
	/*���ر���ʵ�����ݲ������ѯ��*/
		if(MountSpAcctItem2Bin(sSpSjTable,&pRootsj)<0) return -1;
	/*���ر����Ż����ݲ������ѯ��*/
		if(MountSpAcctItem2Bin(sSpDisctTable,&pRootdisct)<0) return -1;
	}


/*����Ӧ��ͳ�����ݵ�BINTREE*/
	if(MountSmspNbrStat2Bin(sSpYsTable,sBillingCycleID)<0) return -1;

	if(strcmp(STYPE,"ZB")==0){	
	/*�����ܲ�ʵ�����ݺϲ���Ӧ����ϸ��*/
		if(MountSpTicketSj2Bin(sSpSjTable)<0) return -1;
	}

	             
/*���ر��ؽ�����á�����������ͨ�ŷѰ�iContactID������̯����ϸ����*/
	if(strcmp(STYPE,"BD")==0){
	
		if(StallSpSettOut("SP_LOCAL_SETT_OUT",sBillingCycleID)<0)
			 return -1;
		if(StallDiffCommFee("SP_LOCAL_DIFF_COMM_FEE",sBillingCycleID)<0)
			 return -1;
	}

/*������ݵ�ͳ�Ʊ�*/
	TravelBin(pRootys,DealOutDb);

        if(InsertSpUserStat(NULL,TRUE)<0){
        	WriteAlertMsg("д���ݿ��%sʱ����",SOUTPUTTABLE);
		printf("д���ݿ��%sʱ����.\n",SOUTPUTTABLE);
		return -1;
	}
	if(strcmp(STYPE,"BD")==0){
	        WriteProcMsg("����ʵ�ռ�¼��%d,�����Żݼ�¼��%d���ϲ���Ӧ����ϸ",iSjCnt,iDisctCnt);
	        printf("����ʵ�ռ�¼��%d,�����Żݼ�¼��%d���ϲ���Ӧ����ϸ .\n",iSjCnt,iDisctCnt);
	}
	
	
        WriteProcMsg("������ϣ���������¼��%d,�������%s",iTotalCnt,SOUTPUTTABLE);
        printf("������ϣ���������¼��%d,�������%s .\n",iTotalCnt,SOUTPUTTABLE);
        CommitWork();
 
	DisconnectDatabase();
	return 0;	
}