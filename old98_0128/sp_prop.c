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

struct SmspStatPropStruct
{
	struct SmspStatPropStruct *pNext;	
	char sBillingCycleID[7];
	char sMsisdn[16];
	int iTicketTypeID;
	char sSpCode[6];
	char sSpServiceCode[11];
	int iCharge;
	double dRatio;
	struct SmspStatPropStruct *pLoadNext;
};

void GenSmspStatPropNode(struct RSmspNbrStatStruct *pSource,
	struct SmspStatPropStruct *pTarget)
{
	strcpy(pTarget->sBillingCycleID,pSource->sBillingCycleID);
	strcpy(pTarget->sMsisdn,pSource->sMsisdn);

	pTarget->iTicketTypeID=pSource->iTicketTypeID;

	strcpy(pTarget->sSpCode,pSource->sSpCode);
	strncpy(pTarget->sSpServiceCode,pSource->sSpServiceCode,8);
	pTarget->sSpServiceCode[8]=0;

	pTarget->iCharge=pSource->iTotalInfoFee+pSource->iTotalRentFee;
}

int data_search_bintree_smsp_stat_prop_e(void *pValue,void*pData)
{               	
	struct SmspStatPropStruct *pSource=(struct SmspStatPropStruct *)pValue;
	struct SmspStatPropStruct *pTarget=(struct SmspStatPropStruct *)pData;
	int res=0;
	
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) 
		return res;	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) 
		return res;

	return res;
}
int comp_search_list_smsp_stat_prop_e(void *pValue,LIST*pHead)
{
	struct SmspStatPropStruct *pSource=(struct SmspStatPropStruct *)pValue;
	struct SmspStatPropStruct *pTarget=(struct SmspStatPropStruct *)pHead;
	int res=0;
	
	if((res=strcmp(pSource->sSpCode,pTarget->sSpCode))!=0)
		return res;
	if((res=strcmp(pSource->sSpServiceCode,pTarget->sSpServiceCode))!=0)
		return res;
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) 
		return res;

	return res;
}
int comp_list_smsp_stat_prop_e(LIST *pValue,LIST *pHead)
{
	struct SmspStatPropStruct *pSource=(struct SmspStatPropStruct *)pValue;
	struct SmspStatPropStruct *pTarget=(struct SmspStatPropStruct *)pHead;
	
	return pSource->iCharge-pTarget->iCharge;	
}
void assign_insert_bintree_smsp_stat_prop_e(void **ppHead,void *pData)
{
	struct SmspStatPropStruct *ptHead,*pTemp;
	
	ptHead=(struct SmspStatPropStruct *)(*ppHead);
	
	/*�Ҳ���������ڴ棬�ҵ������*/
	if(SearchList((LIST*)ptHead,(void*)pData,(LIST**)&pTemp,
		comp_search_list_smsp_stat_prop_e)==NOTFOUND){
		
		if((pTemp=malloc(sizeof(struct SmspStatPropStruct)))==NULL){
			WriteAlertPrint("�����ڴ� SmspStatPropStruct ����");
			exit (1);
		}
		memcpy((void*)pTemp,pData,sizeof(struct SmspStatPropStruct));
		InsertListSort((LIST**)ppHead,(LIST*)pTemp,
			comp_list_smsp_stat_prop_e);
	}
	else{
		ptHead=(struct SmspStatPropStruct *)pData;
		pTemp->iCharge+=ptHead->iCharge;
	}
		
}
void GetPropCycle(char sInputTable[],char sCycleBeginDate[],char sCycleEndDate[])
{
	char sHostTime[15],sMonth[3],sYear[5],sCycleDate[15];
	
	GetHostTime(sHostTime);
	
	strncpy(sMonth,sInputTable+strlen(sInputTable)-2,2);sMonth[2]=0;
	
	strncpy(sYear,sHostTime,4);sYear[4]=0;
	
	sprintf(sCycleDate,"%s%s01000000",sYear,sMonth);

	if(tGetTime(sCycleDate)>tGetTime(sHostTime)) AddYears(sCycleDate,-1);
	
	strcpy(sCycleEndDate,sCycleDate);
	strcpy(sCycleBeginDate,sCycleDate);
	AddMonths(sCycleBeginDate,-2);
	sCycleEndDate[6]=0;
	sCycleBeginDate[6]=0;
}
int calc_ratio(void **ppData)
{
	int iTotalCharge=0,iCnt=0;
	struct SmspStatPropStruct *ptHead,*pTemp;
	
	ptHead=(struct SmspStatPropStruct*)*ppData;

/*�����ܷ��ã����ý�����־*/
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		iTotalCharge+=pTemp->iCharge;
		iCnt++;
	}

	ptHead=(struct SmspStatPropStruct*)*ppData;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		if(iTotalCharge!=0)
			pTemp->dRatio=pTemp->iCharge*1.0/iTotalCharge;
		else
			pTemp->dRatio=0;
	}
	return 0;
}
void CalcRatio(BINTREE *pRoot)
{
	TravelBin(pRoot,calc_ratio);
}

int MountSmspNbrStat2Bin(char sCycleBeginDate[],char sCycleEndDate[],
	BINTREE **ppRoot)
{
	int iCnt=0,iContactId=0;
	char sTemp[20],sSpServiceCode[20];
	
	struct RSmspNbrStatStruct Temp;
	struct RSmspNbrStatStructIn TempIn;
	
	struct SmspStatPropStruct s;
	
	strcpy(TempIn.sTableName,"SMSP_NBR_STAT");

	sprintf(TempIn.sCondition,"\n\
		WHERE BILLING_CYCLE_ID BETWEEN '%s' AND '%s'",
		sCycleBeginDate,sCycleEndDate);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSmspNbrStatToStruct(&Temp,&TempIn)){
		
		Fmt86A13(Temp.sMsisdn);
		
		strcpy(sTemp,Temp.sSpCode);
		strcat(sTemp,Temp.sSpServiceCode);

		/*sp_code=23156,sp_service_code����*/		
		if(strcmp(Temp.sSpCode,"23156")==0&&
			strncmp(Temp.sSpServiceCode,"5",1)==0){

			strcpy(sTemp,Temp.sSpCode);
			strcpy(sSpServiceCode,Temp.sSpServiceCode);
			sSpServiceCode[3]=0;	
			strcat(sTemp,sSpServiceCode);
		}
		if(strcmp(Temp.sSpCode,"23156")==0&&
			strncmp(Temp.sSpServiceCode,"6135",4)==0){

			strcpy(sTemp,Temp.sSpCode);
			strcpy(sSpServiceCode,Temp.sSpServiceCode);
			sSpServiceCode[6]=0;	
			strcat(sTemp,sSpServiceCode);
		}
		
		GetBinInt("SP_CONTACT_RELATION",1,sTemp,
			Temp.sMaxStartTime,&iContactId);
		if(iContactId==0)
			GetBinInt("SP_CONTACT_RELATION",1,
				Temp.sSpCode,Temp.sMaxStartTime,&iContactId);
		
		/*��SP_CONTACT_RELATION�Ҳ���sp_code��sp_service_code�Ĳ�����̯��*/
		if(iContactId==0)	continue;
		
		GenSmspStatPropNode(&Temp,&s);

		if(InsertBin(ppRoot,(void *)&s,
			data_search_bintree_smsp_stat_prop_e,
			assign_insert_bintree_smsp_stat_prop_e)<0){
			WriteAlertMsg("����SMSP_NBR_STAT���ڴ���ʧ��");
			return -1;
		}
		if(++iCnt%10000==0)
			WriteProcMsg("���ر�%s��¼��%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("���ر�%s��¼����ϣ��ܼ�¼��%d",TempIn.sTableName,iCnt);
	return 0;	
}
int data_search_bintree_sp_acc_recv_e(void *pValue,void *pData)
{
	struct SpAcctItemStruct *pSource=(struct SpAcctItemStruct *)pValue;
	struct SmspStatPropStruct *pTarget=(struct SmspStatPropStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;

	return res;
}
void mvitem_spacctitem(struct SmspStatPropStruct *ps,
	struct SpAcctItemStruct *pi,struct SpAcctItemStruct *po)
{
	bzero((void*)po,sizeof(struct SpAcctItemStruct));

	strcpy(po->sBillingCycleID,pi->sBillingCycleID);
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sPayCycleID,	pi->sPayCycleID);
	strcpy(po->sServiceCode,pi->sServiceCode);
	strcpy(po->sCharge,pi->sCharge);
	strcpy(po->sPayTime,    pi->sPayTime);
	
	if(ps!=NULL){
		po->iTicketTypeID=	ps->iTicketTypeID;	
		strcpy(po->sSpCode,	ps->sSpCode);
		strcpy(po->sSpServiceCode,ps->sSpServiceCode);
	}
}
void mvitem_spacctitem2stat(struct SpAcctItemStruct *pi,
	struct SmspStatPropStruct *po)
{
	bzero((void*)po,sizeof(struct SmspStatPropStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);
}
int main(int argc,char *argv[])
{
	int iCnt=0,iTotalCnt=0,iTotalCharge=0,iAddUpCharge=0,iCharge=0;
	char sInputTable[31],sOutputTable[31];
	char sCycleBeginDate[15],sCycleEndDate[15],sErrCode[6];
	BINTREE *pRoot=NULL;
	
	struct SpAcctItemStruct Temp,AcctItem;
	struct SpAcctItemStructIn TempIn;
	
	struct SpAcctItemStructOut TempOut;

	struct SmspStatPropStruct *pTemp,*ptCur,*ptPre,s;

	if(argc!=3){
		printf("Usage %s sp_acct_item_all_xx sp_acct_item_detail_xx.\n",argv[0]);
		return -1;
	}

	InitAppRes(argv[0]);
	strcpy(sInputTable,argv[1]);Upper(sInputTable);
	strcpy(sOutputTable,argv[2]);Upper(sOutputTable);
	
	if(ConnectDataDB()<0) return -1;
	
	/*��ȡ��ʼ���ں���ֹ����*/
	GetPropCycle(sInputTable,sCycleBeginDate,sCycleEndDate);
	
	/*����Ӧ��ͳ�����ݵ�BINTREE*/
	if(MountSmspNbrStat2Bin(sCycleBeginDate,sCycleEndDate,&pRoot)<0) return -1;
	
	/*������״�ṹ�ı���*/
	CalcRatio(pRoot);

	/*��ʵ������ȡ��*/
	bzero((void*)&TempIn,sizeof(struct SpAcctItemStructIn));
	strcpy(TempIn.sTableName,sInputTable);
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	
	bzero((void*)&TempOut,sizeof(struct SpAcctItemStructOut));
	strcpy(TempOut.sTableName,sOutputTable);

	/*��ȡ����ѭ������ʵ������ȡ����,һ��һ���ط�̯*/
	while(EGetSpAcctItemToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;
		Fmt86A13(Temp.sMsisdn);
		
		mvitem_spacctitem2stat(&Temp,&s);

		/*����ָ�����ڵļ�¼�Ƿ���Ӧ����*/
		if((SearchBin(pRoot,(void*)&s,
			data_search_bintree_smsp_stat_prop_e,
			(void**)&pTemp))==NOTFOUND){
		/*δ�ҵ�Ӧ�ռ�¼*/
			if(strcmp(Temp.sBillingCycleID,sCycleBeginDate)<0)
				strcpy(sErrCode,"99999");/*����ǰ����*/
			else
				strcpy(sErrCode,"99998");/*ȱӦ�ջ���*/
				
			mvitem_spacctitem(NULL,&Temp,&AcctItem);
			
			/*����Ĭ�ϵĻ������SP�����ҵ�����*/
			AcctItem.iTicketTypeID=0;
			strcpy(AcctItem.sSpCode,"99999");
			strcpy(AcctItem.sSpServiceCode,sErrCode);
			iTotalCnt++;
			if(EInsertStructToSpAcctItem(&AcctItem,FALSE,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				return -1;
			}
			continue;
		}
		
		/*����ܷ��ã��ܷ���Ϊ0�򲻷�̯*/
		iTotalCharge=0;
		
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			iTotalCharge+=ptPre->iCharge;
		}
		if(iTotalCharge<atoi(Temp.sCharge)){
			PrintLog("/ticket/app/ctl/err.txt","%s\t%s\t%d\n",
				Temp.sMsisdn,Temp.sCharge,iTotalCharge);
		/*����ͬ����Ӫ�ʴ�������ʵ�շ��ô���Ӧ�����ʵ��=Ӧ��*/
			sprintf(Temp.sCharge,"%d",iTotalCharge);
		}

		/*��һ��ѭ�������÷�̯��*/
		iAddUpCharge=0;
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			mvitem_spacctitem(ptPre,&Temp,&AcctItem);
			
			if(ptCur!=NULL){
				if(ptPre->dRatio!=0){
					iCharge=(atoi(Temp.sCharge)*ptPre->dRatio+0.5);
					iAddUpCharge+=iCharge;
				}
				else 
					iCharge=0;
			}
			else{
				if(ptPre->iCharge!=0)
					iCharge=atoi(Temp.sCharge)-iAddUpCharge;
				else 
					iCharge=0;
				
			}
			sprintf(AcctItem.sCharge,"%d",iCharge);
			
			iTotalCnt++;
			if(EInsertStructToSpAcctItem(&AcctItem,FALSE,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				return -1;
			}
		}
		if(++iCnt%10000==0){
			if(EInsertStructToSpAcctItem(NULL,true,&TempOut)<0){
				WriteAlertMsg("д���ݿ��%sʱ����",TempOut.sTableName);
				return -1;
			}
			WriteProcMsg("�����¼��%d,�����¼��%d",iCnt,iTotalCnt);
			CommitWork();
		}
		
	}

	if(EInsertStructToSpAcctItem(NULL,true,&TempOut)<0){
		printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
		return -1;
	}
	WriteProcMsg("������ϣ��������¼��%d,�����¼��%d",iCnt,iTotalCnt);
	CommitWork();

	DisconnectDatabase();
	return 0;	
}
