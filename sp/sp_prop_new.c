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

struct SmspStatPropStruct
{
	struct SmspStatPropStruct *pNext;	
	char	sBillingCycleID[7];
	char	sMsisdn[16];
	char	sHomeAreaCode[10];
	int	iTicketTypeID;
	char	sSpCode[6];
	char	sSpServiceType[11];
	char	sSpAccNbr[13];
	int	iCharge;
	int	iRecCnt;
	double	dRatio;
	struct SmspStatPropStruct *pLoadNext;
};

void GenSmspStatPropNode(struct RSmspNbrStatStruct *pSource,
	struct SmspStatPropStruct *pTarget)
{
	char sSStartTime[15];
	struct SpContactRelationStruct *pS=NULL;
	
	strcpy(pTarget->sBillingCycleID,pSource->sBillingCycleID);
	strcpy(pTarget->sMsisdn,pSource->sMsisdn);
	
	SetHomeAreaCode(pSource->sHomeAreaCode,pTarget->sHomeAreaCode);
	
	pTarget->iTicketTypeID=pSource->iTicketTypeID;

	strcpy(pTarget->sSpCode,pSource->sSpCode);

/*取得sp类型*/
	strcpy(pTarget->sSpServiceType,pSource->sHomeAreaCode+3);
	
	if(strlen(pTarget->sSpServiceType)!=2){
		
		strcpy(sSStartTime,pSource->sBillingCycleID);
		strcpy(sSStartTime+6,"02000000");sSStartTime[14]=0;
		if(SearchSpContactRelation(pSource->sSpCode,"",
			pSource->sSpAccNbr,sSStartTime,&pS)==NOTFOUND)
			strcpy(pTarget->sSpServiceType,"90");
		else	strcpy(pTarget->sSpServiceType,pS->sServiceType);
	}
	strcpy(pTarget->sSpAccNbr,pSource->sSpAccNbr);

	pTarget->iCharge=pSource->iTotalInfoFee+pSource->iTotalRentFee;
	
	if(pTarget->iCharge>0)pTarget->iRecCnt=pSource->iTotalCnt;
	
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
	if((res=strcmp(pSource->sSpServiceType,pTarget->sSpServiceType))!=0)
		return res;
	if((res=strcmp(pSource->sSpAccNbr,pTarget->sSpAccNbr))!=0)
		return res;
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) 
		return res;

	return res;
}
int comp_list_smsp_stat_prop_e(LIST *pValue,LIST *pHead)
{
	struct SmspStatPropStruct *pSource=(struct SmspStatPropStruct *)pValue;
	struct SmspStatPropStruct *pTarget=(struct SmspStatPropStruct *)pHead;
	int res=0;
	
	if((res=pSource->iCharge-pTarget->iCharge)!=0) return res;
	if((res=pSource->iRecCnt-pTarget->iRecCnt)!=0) return res;
	
	return res;
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
		pTemp->iRecCnt+=ptHead->iRecCnt;
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
void FmtSpInfo(struct RSmspNbrStatStruct *pData)
{
	if(strcmp(pData->sSpCode,"-1")==0)strcpy(pData->sSpCode,"");
	if(strcmp(pData->sSpServiceCode,"-1")==0)strcpy(pData->sSpServiceCode,"");
	if(strcmp(pData->sSpAccNbr,"-1")==0)strcpy(pData->sSpAccNbr,"");

}
int MountSmspNbrStat2Bin(char sCycleBeginDate[],char sCycleEndDate[],
	BINTREE **ppRoot)
{
	int iCnt=0,iContactId=0;
	
	struct RSmspNbrStatStruct Temp;
	struct RSmspNbrStatStructIn TempIn;
	
	struct SmspStatPropStruct s;
	
	strcpy(TempIn.sTableName,"SMSP_NBR_STAT_ZB");

	sprintf(TempIn.sCondition,"\n\
		WHERE BILLING_CYCLE_ID BETWEEN '%s' AND '%s'",
		sCycleBeginDate,sCycleEndDate);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetSmspNbrStatToStruct(&Temp,&TempIn)){
		
		Fmt86A13(Temp.sMsisdn);
		FmtSpInfo(&Temp);
		
		GetBinInt("SP_CONTACT_RELATION_ZB",1,Temp.sSpCode,Temp.sMaxStartTime,&iContactId);
		
		/*在SP_CONTACT_RELATION_ZB找不到sp_code或sp_service_code的不进行摊分*/
/*		if(iContactId==0)	continue;
*/	
		GenSmspStatPropNode(&Temp,&s);

		if(InsertBin(ppRoot,(void *)&s,
			data_search_bintree_smsp_stat_prop_e,
			assign_insert_bintree_smsp_stat_prop_e)<0){
			WriteAlertMsg("加载SMSP_NBR_STAT_ZB到内存树失败");
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
	struct SpAcctItemNewStruct *pSource=(struct SpAcctItemNewStruct *)pValue;
	struct SmspStatPropStruct *pTarget=(struct SmspStatPropStruct *)pData;

/*数据比较部分*/
	int res=0;

	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;

	return res;
}
void mvitem_spacctitemnew(struct SmspStatPropStruct *ps,
	struct SpAcctItemNewStruct *pi,struct SpAcctItemNewStruct *po)
{
	bzero((void*)po,sizeof(struct SpAcctItemNewStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sHomeAreaCode,pi->sHomeAreaCode);
	strcpy(po->sBillingCycleID,pi->sBillingCycleID);
	strcpy(po->sPayCycleID,	pi->sPayCycleID);
	strcpy(po->sCharge,pi->sCharge);
	strcpy(po->sPayTime,    pi->sPayTime);
	
	if(ps!=NULL){
		po->iTicketTypeID=	ps->iTicketTypeID;	
		strcpy(po->sSpCode,	ps->sSpCode);
		strcpy(po->sSpServiceType,ps->sSpServiceType);
		strcpy(po->sSpAccNbr,ps->sSpAccNbr);
		/*strcpy(po->sServiceCode,ps->sSpServiceCode); */
		po->iRecCnt=ps->iRecCnt;
	}
	
	
}
void mvitem_spacctitemnew2stat(struct SpAcctItemNewStruct *pi,
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
	
	struct SpAcctItemNewStruct Temp,AcctItem,TempErr;
	struct SpAcctItemNewStructIn TempIn;
	
	struct SpAcctItemNewStructOut TempOut;
	struct SpAcctItemNewStructOut TempOutErr;

	struct SmspStatPropStruct *pTemp,*ptCur,*ptPre,s;

	if(argc!=3){
		printf("Usage %s sp_acct_item_zb_xx sp_acct_item_detailzb_xx.\n",argv[0]);
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
	bzero((void*)&TempIn,sizeof(struct SpAcctItemNewStructIn));
	strcpy(TempIn.sTableName,sInputTable);
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	
	bzero((void*)&TempOut,sizeof(struct SpAcctItemNewStructOut));
	strcpy(TempOut.sTableName,sOutputTable);

	bzero((void*)&TempOutErr,sizeof(struct SpAcctItemNewStructOut));
	strcpy(TempOutErr.sTableName,"SP_ACCT_ITEM_ZB_ERR");

	/*获取数据循环，将实收数据取出来,一个一个地分摊*/
	while(EGetSpAcctItemNewToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;
		Fmt86A13(Temp.sMsisdn);
		
		mvitem_spacctitemnew2stat(&Temp,&s);

		/*查找指定帐期的记录是否在应收中*/
		if((SearchBin(pRoot,(void*)&s,
			data_search_bintree_smsp_stat_prop_e,
			(void**)&pTemp))==NOTFOUND){
		/*未找到应收记录*/
			if(strcmp(Temp.sBillingCycleID,sCycleBeginDate)<0)
				strcpy(sErrCode,"X9999");/*帐期前数据*/
			else
				strcpy(sErrCode,"X9998");/*缺应收话单*/
				
			mvitem_spacctitemnew(NULL,&Temp,&AcctItem);
			
			/*设置默认的话单类别及SP代码和业务代码*/
			AcctItem.iTicketTypeID=0;
			strcpy(AcctItem.sSpCode,"X9999");
			strcpy(AcctItem.sSpAccNbr,sErrCode);
			iTotalCnt++;
			if(EInsertStructToSpAcctItemNew(&AcctItem,FALSE,&TempOut)<0){
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
			memcpy((void*)&TempErr,(void*)&Temp,
				sizeof(struct SpAcctItemNewStruct));
			sprintf(TempErr.sSpAccNbr,"%d",iTotalCharge);
			if(EInsertStructToSpAcctItemNew(&TempErr,FALSE,
				&TempOutErr)<0){
				WriteAlertMsg("写数据库表%s时出错",
					TempOutErr.sTableName);
				return -1;
			}
				
		/*如相同号码营帐传过来的实收费用大于应收则把实收=应收*/
			sprintf(Temp.sCharge,"%d",iTotalCharge);
		}

		/*做一个循环将费用分摊了*/
		iAddUpCharge=0;
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			mvitem_spacctitemnew(ptPre,&Temp,&AcctItem);
			
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
			if(EInsertStructToSpAcctItemNew(&AcctItem,FALSE,&TempOut)<0){
				WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
				return -1;
			}
		}
		if(++iCnt%10000==0){
			if(EInsertStructToSpAcctItemNew(NULL,true,&TempOut)<0){
				WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
				return -1;
			}
			WriteProcMsg("处理记录数%d,输出记录数%d",iCnt,iTotalCnt);
			CommitWork();
		}
		
	}

	if(EInsertStructToSpAcctItemNew(NULL,FALSE,&TempOutErr)<0){
		WriteAlertMsg("写数据库表%s时出错",TempOutErr.sTableName);
		return -1;
	}
	if(EInsertStructToSpAcctItemNew(NULL,true,&TempOut)<0){
		printf("写数据库表%s时出错.\n",TempOut.sTableName);
		return -1;
	}
	WriteProcMsg("处理完毕，共处理记录数%d,输出记录数%d",iCnt,iTotalCnt);
	printf("处理完毕，共处理记录数%d,输出记录数%d.\n",iCnt,iTotalCnt);
	CommitWork();

	DisconnectDatabase();
	return 0;	
}
