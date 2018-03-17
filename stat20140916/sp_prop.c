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
	
	/*找不到则分配内存，找到则加入*/
	if(SearchList((LIST*)ptHead,(void*)pData,(LIST**)&pTemp,
		comp_search_list_smsp_stat_prop_e)==NOTFOUND){
		
		if((pTemp=malloc(sizeof(struct SmspStatPropStruct)))==NULL){
			WriteAlertPrint("分配内存 SmspStatPropStruct 错误");
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

/*计算总费用，设置结束标志*/
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

		/*sp_code=23156,sp_service_code处理*/		
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
		
		/*在SP_CONTACT_RELATION找不到sp_code或sp_service_code的不进行摊分*/
		if(iContactId==0)	continue;
		
		GenSmspStatPropNode(&Temp,&s);

		if(InsertBin(ppRoot,(void *)&s,
			data_search_bintree_smsp_stat_prop_e,
			assign_insert_bintree_smsp_stat_prop_e)<0){
			WriteAlertMsg("加载SMSP_NBR_STAT到内存树失败");
			return -1;
		}
		if(++iCnt%10000==0)
			WriteProcMsg("加载表%s记录数%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("加载表%s记录数完毕，总记录数%d",TempIn.sTableName,iCnt);
	return 0;	
}
int data_search_bintree_sp_acc_recv_e(void *pValue,void *pData)
{
	struct SpAcctItemStruct *pSource=(struct SpAcctItemStruct *)pValue;
	struct SmspStatPropStruct *pTarget=(struct SmspStatPropStruct *)pData;

/*数据比较部分*/
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
	
	/*获取起始帐期和终止帐期*/
	GetPropCycle(sInputTable,sCycleBeginDate,sCycleEndDate);
	
	/*加载应收统计数据到BINTREE*/
	if(MountSmspNbrStat2Bin(sCycleBeginDate,sCycleEndDate,&pRoot)<0) return -1;
	
	/*计算树状结构的比例*/
	CalcRatio(pRoot);

	/*将实收总帐取出*/
	bzero((void*)&TempIn,sizeof(struct SpAcctItemStructIn));
	strcpy(TempIn.sTableName,sInputTable);
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	
	bzero((void*)&TempOut,sizeof(struct SpAcctItemStructOut));
	strcpy(TempOut.sTableName,sOutputTable);

	/*获取数据循环，将实收数据取出来,一个一个地分摊*/
	while(EGetSpAcctItemToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;
		Fmt86A13(Temp.sMsisdn);
		
		mvitem_spacctitem2stat(&Temp,&s);

		/*查找指定帐期的记录是否在应收中*/
		if((SearchBin(pRoot,(void*)&s,
			data_search_bintree_smsp_stat_prop_e,
			(void**)&pTemp))==NOTFOUND){
		/*未找到应收记录*/
			if(strcmp(Temp.sBillingCycleID,sCycleBeginDate)<0)
				strcpy(sErrCode,"99999");/*帐期前数据*/
			else
				strcpy(sErrCode,"99998");/*缺应收话单*/
				
			mvitem_spacctitem(NULL,&Temp,&AcctItem);
			
			/*设置默认的话单类别及SP代码和业务代码*/
			AcctItem.iTicketTypeID=0;
			strcpy(AcctItem.sSpCode,"99999");
			strcpy(AcctItem.sSpServiceCode,sErrCode);
			iTotalCnt++;
			if(EInsertStructToSpAcctItem(&AcctItem,FALSE,&TempOut)<0){
				WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
				return -1;
			}
			continue;
		}
		
		/*算出总费用，总费用为0则不分摊*/
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
		/*如相同号码营帐传过来的实收费用大于应收则把实收=应收*/
			sprintf(Temp.sCharge,"%d",iTotalCharge);
		}

		/*做一个循环将费用分摊了*/
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
				WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
				return -1;
			}
		}
		if(++iCnt%10000==0){
			if(EInsertStructToSpAcctItem(NULL,true,&TempOut)<0){
				WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
				return -1;
			}
			WriteProcMsg("处理记录数%d,输出记录数%d",iCnt,iTotalCnt);
			CommitWork();
		}
		
	}

	if(EInsertStructToSpAcctItem(NULL,true,&TempOut)<0){
		printf("写数据库表%s时出错.\n",TempOut.sTableName);
		return -1;
	}
	WriteProcMsg("处理完毕，共处理记录数%d,输出记录数%d",iCnt,iTotalCnt);
	CommitWork();

	DisconnectDatabase();
	return 0;	
}
