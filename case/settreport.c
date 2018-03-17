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
#include "settreport_supp.h"

struct SettItemStruct *pSettItem=NULL;
struct ReportStatStruct *ptItem=NULL;
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
int link_item(void **ppData)
{	
	InsertList((LIST**)&ptItem,(LIST*)(*ppData));
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
int data_search_bintree_report_stat_e(void *pValue,void*pData)
{
	struct ReportStatStruct *pSource=(struct ReportStatStruct *)pValue;
	struct ReportStatStruct *pTarget=(struct ReportStatStruct *)pData;
	int res;
	
	if((res=pSource->iLatnID-pTarget->iLatnID)!=0) return res;
	if((res=pSource->iItemID-pTarget->iItemID)!=0) return res;
	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;
	if((res=pSource->iSettCycleID-pTarget->iSettCycleID)!=0) return res;
	if((res=pSource->iOppCarrierID-pTarget->iOppCarrierID)!=0) return res;
	if((res=strcmp(pSource->sOppArea,pTarget->sOppArea))!=0) return res;
	if((res=strcmp(pSource->sReserve,pTarget->sReserve))!=0) return res;
	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	if((res=strcmp(pSource->sState,pTarget->sState))!=0) return res;
	
	
	return 0;
}
void assign_insert_bintree_report_stat_e(void **ppData,void *pData)
{

	int iCharge=0;
	struct ReportStatStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct ReportStatStruct));
		ERROR_EXIT(pTemp==NULL,"分配ReportStatStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct ReportStatStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	iCharge=atoi(pTemp->sCharge)+
		atoi(((struct ReportStatStruct*)pData)->sCharge);
	sprintf(pTemp->sCharge,"%12d",iCharge);
}

int main(int argc, char **argv)
{

	int	i,l,iCnt,iRet,iRecFlag=0;
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	char	statement[256];
	char	sDealBeginDate[15],sDealEndDate[15],sInput[EXPRLEN],sExprName[128];
	char	sInTableName[256],sOutTableName[256];
	BINTREE *pRoot=NULL;
	BINTREE *pRootp=NULL;
	BINTREE *pRootOut=NULL;
	
	struct SettItemStruct *p,Temp,*pTemp,*ptHead,*ptPre,*ptCur;
	struct ParamReportStatStruct *ptLKParam,*pa=NULL,*pb,ps;
	struct ReportStatStruct *pTempR,*ptHeadR,*ptRs;
	struct SettItemStructIn TempIn;
	struct ReportStatStructOut TempOut;
	
	int	iCharge,iOutLatnID,iItemID,iSettCycleID,iOppCarrierID;
	char	sDataDate[9],sOppArea[6],sReserve[11],sSourceID[31];
						
	if(argc!=6){
		printf("Usage %s exprfile beginyyyymmdd endyyyymmdd sett_item report_stat.\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sExprName,argv[1]);
	
	GetHostTime(sDealBeginDate);
	strcpy(sDealBeginDate+8,"000000");
	AddDates(sDealBeginDate,-1);
	strcpy(sDealEndDate,sDealBeginDate);
	strncpy(sDealBeginDate,argv[2],8);
	strcpy(sDealBeginDate+8,"000000");
	strncpy(sDealEndDate,argv[3],8);
	strcpy(sDealEndDate+8,"000000");
	
	strcpy(sInTableName,argv[4]);
	strcpy(sOutTableName,argv[5]);
	
	Upper(sInTableName);
	Upper(sOutTableName);
	
	if(strncmp(sOutTableName,"REPORT",6)!=0){
		printf("输出表report_stat= %s 非法.\n",sOutTableName);
		return -1;
	}

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
	RegRateExprFun();
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

	if(TableExist(sInTableName)==FALSE){
		printf(" 帐单表 %s 数据库中不存在.\n",sInTableName);
		exit(-1);
	}
	if(TableExist(sOutTableName)==FALSE){
		printf(" 报表统计表 %s 数据库中不存在.\n",sOutTableName);
		exit(-1);
	}
	strcpy(TempIn.sTableName,sInTableName);

	sprintf(TempIn.sCondition,"\n\
	WHERE SETT_ITEM_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
		SETT_ITEM_DATE<=to_date('%s','yyyymmddhh24miss')\n\
	",sDealBeginDate,sDealEndDate);

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

	/*加载报表项参数*/
	if(InitParamReportStat2Bin(&pRootp)<0)return -1;;
	
	bzero((void*)&ps,sizeof(struct ParamReportStatStruct));
	
	ptHead=pSettItem;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
				
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			ps.iAcctItemTypeID=ptPre->iAcctItemTypeID;

			if(SearchBin(pRootp,(void*)&ps,
				data_search_bintree_paramreportstat_e,
				(void*)&pa)==NOTFOUND) continue;	
			ptLKParam=pa;
			while(ptLKParam!=NULL){
				pb=ptLKParam;
				ptLKParam=ptLKParam->pNext;
 				
				if(ptPre->iCharge==0) continue;
			
				
				set_int_value("$acct_item_type_id",pExprBuf,ptPre->iAcctItemTypeID);
				set_int_value("$charge",pExprBuf,ptPre->iCharge);
				set_int_value("$latn_id",pExprBuf,ptPre->iLatnID);
				set_str_value("$user_type",pExprBuf,ptPre->sUserType);
				set_str_value("$data_date",pExprBuf,ptPre->sSettItemDate);
				set_int_value("$opp_carrier_id",pExprBuf,ptPre->iOppCarrierID);
				set_int_value("$sett_cycle_id",pExprBuf,ptPre->iSettCycleID);
				set_str_value("$source_id",pExprBuf,ptPre->sSourceID);
		
				set_int_value("$item_id",pExprBuf,pb->iItemID);
				set_str_value("$opp_carrier_id_rule",pExprBuf,pb->sOppCarrierID);
				set_str_value("$user_type_rule",pExprBuf,pb->sUserType);

				if((iRet=ExecCode(pExprBuf))<0){
					printf("公式执行失败.\n");
					WriteErrStackAlert();
					return -1;
				}
				get_int_value("out_rec_flag",pExprBuf,&iRecFlag);
				if(iRecFlag<0) continue;
				
				get_int_value("out_item_id",pExprBuf,&iItemID);
				get_int_value("out_charge",pExprBuf,&iCharge);				
				get_int_value("out_latn_id",pExprBuf,&iOutLatnID);
				get_str_value("out_data_date",pExprBuf,sDataDate);
				get_int_value("out_sett_cycle_id",pExprBuf,&iSettCycleID);
				get_int_value("out_opp_carrier_id",pExprBuf,&iOppCarrierID);
				get_str_value("out_opp_area",pExprBuf,sOppArea);
				get_str_value("out_reserve",pExprBuf,sReserve);
				get_str_value("out_source_id",pExprBuf,sSourceID);				
				
				
				if((ptRs=malloc(sizeof(struct ReportStatStruct)))==NULL){
					printf("分配内存失败ReportStatStruct.\n");
					return -1;
				}			
		
				ptRs->iReportStatID=	0;
				ptRs->iLatnID=	iOutLatnID;
				ptRs->iItemID=	iItemID;
				sprintf(ptRs->sCharge,"%12d",iCharge);
				strncpy(ptRs->sSettItemDate,sDataDate,8);
				strcpy(ptRs->sSettItemDate+8,"000000");
				ptRs->iSettCycleID=	iSettCycleID;	
				strcpy(ptRs->sCreatedDate,"");		
				/*GetHostTime(ptRs->sCreatedDate);入库时重填*/
				strcpy(ptRs->sState,"0");
				ptRs->iOppCarrierID=	iOppCarrierID;
				strcpy(ptRs->sOppArea,sOppArea);
				strcpy(ptRs->sReserve,sReserve);
				strcpy(ptRs->sSourceID,sSourceID);
							
				if(InsertBin(&pRootOut,(void*)ptRs,
					data_search_bintree_report_stat_e,
					assign_insert_bintree_report_stat_e)<0) return -1;				
			}
		}
	}
	
	/*将报表项挂到ptItem中*/
	ptItem=NULL;
	TravelBin(pRootOut,link_item);
	DestroyBin(pRootOut);
	
	
	/**删除过去统计结果**/

	sprintf(statement,"DELETE FROM %s \n\
		WHERE SETT_ITEM_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
			SETT_ITEM_DATE<=to_date('%s','yyyymmddhh24miss') \n\
		",sOutTableName,sDealBeginDate,sDealEndDate);

	
	iRet=ExecSql(statement);
	if(iRet<0){
		 printf("删除%s记录错误.\n",sOutTableName);
		 WriteErrStackAlert();
		 return -1;
	}
	/**输出数据到月帐表**/
        bzero((void*)&TempOut,sizeof(struct ReportStatStructOut));
        strcpy(TempOut.sTableName,sOutTableName);

	ptHeadR=ptItem;
	iCnt=0;
	while(ptHeadR!=NULL){
		pTempR=ptHeadR;
		ptHeadR=ptHeadR->pNext;
		
		pTempR->iReportStatID=	iReportStatID();
		GetHostTime(pTempR->sCreatedDate);
		if(EInsertStructToReportStat(pTempR,false,&TempOut)<0){
			printf("输出报表项错误%s.\n",sOutTableName);
			WriteErrStackAlert();
			return -1;
		}
		iCnt++;
		
	}
	if(EInsertStructToReportStat(NULL,true,&TempOut)<0){
		printf("输出报表项错误%s.\n",sOutTableName);
		WriteErrStackAlert();
		return -1;
	}
	WriteProcMsg("统计正确输出帐目数%d",iCnt);
	printf("报表项月结程序成功,统计正确输出帐目数%d 到表%s.\n",iCnt,sOutTableName);
	
	DisconnectDatabase();
	return 0;
}
