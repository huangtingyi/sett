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

#include "sett_item.h"

struct SettItemStruct *pSettItem=NULL;
void sum_list_sett_item_e(LIST *pHead,LIST*pValue)
{
	struct SettItemStruct *pSource=(struct SettItemStruct *)pValue;
	struct SettItemStruct *pTarget=(struct SettItemStruct *)pHead;
	
	pTarget->iCharge+=pSource->iCharge;
	free(pSource);
}
int comp_insert_list_sett_item_e(LIST *pValue,LIST*pHead)
{
	struct SettItemStruct *pSource=(struct SettItemStruct *)pValue;
	struct SettItemStruct *pTarget=(struct SettItemStruct *)pHead;

	return pSource->iAcctItemTypeID-pTarget->iAcctItemTypeID;
}
void assign_insert_bintree_stat_item_e(void **ppHead,void *pData)
{	/*如果合并上去*/
	InsertListSumm((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_sett_item_e,
		sum_list_sett_item_e);
}
int data_search_bintree_stat_item_e(void *pValue,void*pData)
{
	struct SettItemStruct *pSource=(struct SettItemStruct *)pValue;
	struct SettItemStruct *pTarget=(struct SettItemStruct *)pData;
	int res=0;
	
	if((res=pSource->iLatnID-pTarget->iLatnID)!=0) return res;
	if((res=pSource->iOppCarrierID-pTarget->iOppCarrierID)!=0) return res;
	if((res=pSource->iSettCycleID-pTarget->iSettCycleID)!=0) return res;
	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return strcmp(pSource->sSettItemDate,pTarget->sSettItemDate);
}
int link_sett_item(void **ppData)
{
	struct SettItemStruct *ptHead=(struct SettItemStruct *)(*ppData);
	
	if(ptHead==NULL) return 0;
	
	ptHead->pLoadNext=pSettItem;
	pSettItem=ptHead;
	return 0;
}
int ReadExprToStr(char sExprName[],char sInput[])
{
	int l;
	FILE *fp;
	
	if((l=FileSize(sExprName))>=EXPRLEN){
		printf("参数文件%s大于%d,%d.\n",sExprName,EXPRLEN,l);
		return -1;
	}
	fp=fopen(sExprName,"r");
	if(fread(sInput,l,1,fp)!=1){
		printf("读文件%s失败.\n",sExprName);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);
	return 0;
}
int main(int argc, char **argv)
{

	int	iLatnID,i,l,iCnt,iRet;
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	char	sType[128],statement[256];
	char	sDealBeginDate[15],sDealEndDate[15],sInput[EXPRLEN],sExprName[128];
	BINTREE *pRoot=NULL;
	struct SettItemStruct Temp,*p,*ptLkHead,*pTemp,*ptHead,*ptPre,*ptCur;
	struct SettItemStructIn TempIn;
	struct SettItemStructOut TempOut;
	
	char sState[2];
	int	iAcctItemTypeID,iCharge;
	
	if(argc!=6){
		printf("Usage %s exprfile latnid beginyyyymmdd endyyyymmdd type.\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sExprName,argv[1]);
	iLatnID=-1;
	

	iLatnID=atoi(argv[2]);
	GetHostTime(sDealBeginDate);
	strcpy(sDealBeginDate+8,"000000");
	AddDates(sDealBeginDate,-1);
	strcpy(sDealEndDate,sDealBeginDate);
	strncpy(sDealBeginDate,argv[3],8);
	strcpy(sDealBeginDate+8,"000000");
	strncpy(sDealEndDate,argv[4],8);
	strcpy(sDealEndDate+8,"000000");
	strcpy(sType,argv[5]);
	if(strcmp(sType,"new")!=0)strcpy(sType,"old");

	if(tGetTime(sDealBeginDate)<0||tGetTime(sDealEndDate)<0){
		printf("输入的日期不合法 %s,%s.\n",sDealBeginDate,sDealEndDate);
		return -1;
	}
	if(IsFile(sExprName)==FALSE){
		printf("公式文件%s无效.\n",sExprName);
		return -1;
	}
/*将公式文件读到内存*/
	if(ReadExprToStr(sExprName,sInput)<0){
		printf("加载到公式文件%s到内存失败.\n",sExprName);
		return -1;
	}
/*注册公式函数*/
	RegAcctItemVar();
	CheckSysVar=CheckAcctItemVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}

	if(ConnectDataDB()<0) return -1;
	
	sprintf(TempIn.sTableName,"SETT_ITEM_DAY");
	if(iLatnID==-1){
		sprintf(TempIn.sCondition,"\n\
		WHERE SETT_ITEM_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
			SETT_ITEM_DATE<=to_date('%s','yyyymmddhh24miss')\n\
		",sDealBeginDate,sDealEndDate);
	}
	else{
		sprintf(TempIn.sCondition,"\n\
		WHERE SETT_ITEM_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
		SETT_ITEM_DATE<=to_date('%s','yyyymmddhh24miss') AND \n\
			LATN_ID=%d",sDealBeginDate,sDealEndDate,iLatnID);
	}
	if(strcmp(sType,"old")==0) 
		strcat(TempIn.sCondition," AND ACCT_ITEM_TYPE_ID<900000");
	else
		strcat(TempIn.sCondition," AND ACCT_ITEM_TYPE_ID>=900000");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	while(EGetSettItemToStruct(&Temp,&TempIn)){
		
		if((p=malloc(sizeof(struct SettItemStruct)))==NULL){
			printf("分配内存失败SETT_ITEM.\n");
			return -1;
		}

		memcpy((void*)p,(void*)&Temp,sizeof(struct SettItemStruct));
		if(InsertBin(&pRoot,(void *)p,
			data_search_bintree_stat_item_e,
			assign_insert_bintree_stat_item_e)<0){
			WriteAlertMsg("生成BINTREE失败SETT_ITEM_DAY");
			return -1;
		}
	}
	/*将帐目挂到pSettItem中*/
	TravelBin(pRoot,link_sett_item);
	DestroyBin(pRoot);
	
	ptHead=pSettItem;
	ptLkHead=NULL;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		
		/*将参数加载到公式变量*/
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			SetAcctItemValue(ptPre->iAcctItemTypeID,ptPre->iCharge,"0");
		}
		
		set_int_value("latn_id",pExprBuf,pTemp->iLatnID);
		set_str_value("user_type",pExprBuf,pTemp->sUserType);
		set_str_value("data_date",pExprBuf,pTemp->sSettItemDate);
		set_int_value("opp_carrier_id",pExprBuf,pTemp->iOppCarrierID);
		set_int_value("sett_cycle_id",pExprBuf,pTemp->iSettCycleID);
		set_str_value("source_id",pExprBuf,pTemp->sSourceID);

		if((iRet=ExecCode(pExprBuf))<0){
			printf("公式执行失败.\n");
			WriteErrStackAlert();
			return -1;
		}
		while(GetAcctItemValue(&iAcctItemTypeID,&iCharge,sState)){
			
			if(iCharge==0) continue;
			
			if((p=malloc(sizeof(struct SettItemStruct)))==NULL){
				printf("分配内存失败SETT_ITEM.\n");
				return -1;
			}
			p->iSettItemID=	0;
			p->iLatnID=	pTemp->iLatnID;
			p->iAcctItemTypeID=iAcctItemTypeID;
			p->iCharge=	iCharge;
			strcpy(p->sSettItemDate,pTemp->sSettItemDate);
			GetHostTime(p->sCreatedDate);
			strcpy(p->sState,sState);
			strcpy(p->sUserType,pTemp->sUserType);
			strcpy(p->sSourceID,pTemp->sSourceID);

			p->iOppCarrierID=	pTemp->iOppCarrierID;
			p->iSettCycleID=	pTemp->iSettCycleID;
			
			InsertList((LIST**)&ptLkHead,(LIST*)p);
		}
	}
	/**删除过去统计结果**/
	if(iLatnID==-1){
		sprintf(statement,"DELETE FROM SETT_ITEM \n\
			WHERE SETT_ITEM_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
				SETT_ITEM_DATE<=to_date('%s','yyyymmddhh24miss') \n\
			",sDealBeginDate,sDealEndDate);
	}
	else{
		sprintf(statement,"DELETE FROM SETT_ITEM \n\
			WHERE SETT_ITEM_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
				SETT_ITEM_DATE<=to_date('%s','yyyymmddhh24miss') AND\n\
				LATN_ID=%d",sDealBeginDate,sDealEndDate,iLatnID);
	}
	if(strcmp(sType,"old")==0) 
		strcat(statement," AND ACCT_ITEM_TYPE_ID<900000");
	else
		strcat(statement," AND ACCT_ITEM_TYPE_ID>=900000");
	
	iRet=ExecSql(statement);
	if(iRet<0){
		 printf("删除SETT_ITEM记录错误.\n");
		 WriteErrStackAlert();
		 return -1;
	}
	/**输出数据到月帐表**/
        bzero((void*)&TempOut,sizeof(struct SettItemStructOut));
        strcpy(TempOut.sTableName,"SETT_ITEM");

	ptHead=ptLkHead;
	iCnt=0;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		pTemp->iSettItemID=	iGetAcctItemID();
		if(EInsertStructToSettItem(pTemp,false,&TempOut)<0){
			printf("输出帐目错误SETT_ITEM.\n");
			WriteErrStackAlert();
			return -1;
		}
		iCnt++;
		
	}
	if(EInsertStructToSettItem(NULL,true,&TempOut)<0){
		printf("输出帐目错误SETT_ITEM.\n");
		WriteErrStackAlert();
		return -1;
	}
	WriteProcMsg("统计正确输出帐目数%d",iCnt);
	printf("月结程序成功.");
	
	DisconnectDatabase();
	return 0;
}
