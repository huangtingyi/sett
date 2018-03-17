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

/*单个结构申明*/
struct TpUpStruct{

	struct TpUpStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sVisitCityCode[4];	/* 用户归属地市代码 */
	char    sSpCode[6];		/* SP代码 */
	char    sSpAccNbr[13];		/* SP接入码 */
	char    sSpServiceType[3];	/* SP业务类型 */
	int     iTpFee;			/* 退赔信息费 */
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
			WriteAlertMsg("加载%s到内存树失败",TempIn.sTableName);
			return -1;
		}
		if(++iCnt%10000==0)
			WriteProcMsg("加载表%s记录数%d",TempIn.sTableName,iCnt);
			
	}
	WriteProcMsg("加载表%s记录数完毕，总记录数%d",TempIn.sTableName,iCnt);
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
		ERROR_EXIT(pTemp==NULL,"分配TpUpStruct结构错误");
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

/*取得sp类型*/
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
	
	/*加载退赔数据到BINTREE*/
	if(MountTpTicketUp2Bin(&pRoot,sTpTable)<0) return -1;


	/*将实收取出*/
	bzero((void*)&TempIn,sizeof(struct SpAcctItemNewStructIn));
	strcpy(TempIn.sTableName,sInputTable);
	sprintf(TempIn.sCondition,sCondition);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	
	bzero((void*)&TempOut,sizeof(struct SpTicketSjStructOut));
	strcpy(TempOut.sTableName,sOutputTable);

	/*获取数据循环，将实收数据取出来,到输出*/
	while(EGetSpAcctItemNewToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;
		
		mvitem_spacctitemnew2tp(&Temp,&s);

/*这里可以处理违约扣款金额和调帐金额，功能类似退赔处理*/

		/*查找记录是否在退赔中*/
		if((SearchBin(pRoot,(void*)&s,
			data_search_bintree_tp_up_e,
			(void**)&pTemp))==NOTFOUND){
		/*未找到退赔记录*/
			mvitem_spacctitemnew2spsj(NULL,&Temp,&spticketsj);
			
			spticketsj.iTpFee=0;
			iTotalCnt++;
			if(EInsertStructToSpTicketSj(&spticketsj,FALSE,&TempOut)<0){
				WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
				return -1;
			}
			continue;
		}
		
		mvitem_spacctitemnew2spsj(pTemp,&Temp,&spticketsj);
			
		iTotalCnt++;
		if(EInsertStructToSpTicketSj(&spticketsj,FALSE,&TempOut)<0){
			WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
			return -1;
		}
		if(++iCnt%10000==0){
			if(EInsertStructToSpTicketSj(NULL,true,&TempOut)<0){
				WriteAlertMsg("写数据库表%s时出错",TempOut.sTableName);
				return -1;
			}
			WriteProcMsg("处理记录数%d,输出记录数%d",iCnt,iTotalCnt);
			CommitWork();
		}
		
	}

	if(EInsertStructToSpTicketSj(NULL,true,&TempOut)<0){
		printf("写数据库表%s时出错.\n",TempOut.sTableName);
		return -1;
	}
	WriteProcMsg("处理完毕，共处理记录数%d,输出记录数%d",iCnt,iTotalCnt);
	printf("处理完毕，共处理记录数%d,输出记录数%d.\n",iCnt,iTotalCnt);
	CommitWork();

	DisconnectDatabase();
	return 0;	
}
