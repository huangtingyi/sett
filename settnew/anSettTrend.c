#include <stdio.h>
#include <stdlib.h>
#include <bintree.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <wwfile.h>

#include "settle_supp.h"

struct TemplateSttTrendStruct *gTrendList=NULL;

int data_search_setttrend(void *pValue,void *pData)
{
	int iResult=0;
	
	struct TemplateSttTrendStruct *pSource=(struct TemplateSttTrendStruct*)pValue;
	struct TemplateSttTrendStruct *pTarget=(struct TemplateSttTrendStruct*)pData;
	
	if((iResult=strcmp(pSource->sSettLatnID,	pTarget->sSettLatnID))!=0) return iResult;
	if((iResult=pSource->iReportItemID-pTarget->iReportItemID)!=0) return iResult;
	if((iResult=strcmp(pSource->sSettDate,		pTarget->sSettDate))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyNbrType,		pTarget->sMyNbrType))!=0) return iResult;	
	if((iResult=strcmp(pSource->sMy3gFlag,		pTarget->sMy3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppCarrID,		pTarget->sOppCarrID))!=0) return iResult;
	if((iResult=strcmp(pSource->sOpp3gFlag,		pTarget->sOpp3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sServFlag,		pTarget->sServFlag))!=0) return iResult;
			
	return iResult;
}
void assign_insert_bintree_setttrend(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}
int append_bintree_to_list_trend(void **ppData)
{
	struct TemplateSttTrendStruct *pTemp=(struct TemplateSttTrendStruct*)(*ppData);

	pTemp->pLoadNext=gTrendList;
	gTrendList=pTemp;

	return 0;
}

int CheckParam(int argc,char **argv)
{	
	char sBillDate[9],sType[4];

	strcpy(sBillDate,argv[1]);
	strcpy(sType,argv[2]);
	
	if(ChkDate(sBillDate)<0) goto err_step;

	if(argc==3){
		if((strcmp(sType,"SMS")!=0) && (strcmp(sType,"MMS")!=0)){
			printf("Usage: %s BillDate SMS/MMS",argv[0]);
			return -1;
		}
	}
	else if(argc==5){
		if((strcmp(sType,"STT")!=0)){
			printf("Usage: %s BillDate STT NetWork CarrID",argv[0]);
			return -1;
		}
	}
	else{
err_step:	
		printf("参数错误!\n");
		printf("	Usage: %s BillDate Type [NetWork] [CarrID].\n",argv[0]);
		printf("	BillDate说明: 	时间（YYYYMMDD）\n");
		printf("	Type说明: 	STT 为语音,SMS 为短信,MMS 为彩信\n");
		printf("	NetWork说明: 	移动:YD、固网:GW\n");
		printf("	CarrID说明: 	电信:CT、电信CDMA:CTC、铁通：CRC、移动：CM\n");
		return -1;
	}
	
	return 0;

}
int comp_list_ticket_type_map(void *pi,LIST *ptHead)
{
	int iResult=0;
	
	struct TicketTypeMapStruct *pSource=(struct TicketTypeMapStruct*)pi;
	struct TicketTypeMapStruct *pTarget=(struct TicketTypeMapStruct*)ptHead;
	
	if((iResult=strcmp(pSource->sProdID,	pTarget->sProdID))!=0) return iResult;
		
	return iResult;
}
void GetInFeeOrOutFeeFlag(char sProdID[],char sFeeType[],
	struct TicketTypeMapStruct *pTicketType)
{
	struct TicketTypeMapStruct *pFound=NULL;
	struct TicketTypeMapStruct Temp;

	bzero((void*)&Temp,sizeof(struct TicketTypeMapStruct));
	
	strcpy(Temp.sProdID,sProdID);
	strcpy(sFeeType,"");

	if(SearchList((LIST *)pTicketType,(void *)&Temp,(LIST **)&pFound,
		comp_list_ticket_type_map)==FOUND){
			
		sprintf(sFeeType,"%s",pFound->sFeeType);
	}
	
}
void mvSttMidToSettTrend(struct TicketTypeMapStruct *pTicketType,
	struct TemplateMidSttTicketStruct *pi,struct TemplateSttTrendStruct *po)
{
	char sFeeType[2];
	
	bzero((void*)po,sizeof(struct TemplateSttTrendStruct));
	
	strcpy(po->sSettLatnID,pi->sSettLatnID);
	po->iReportItemID=pi->iReportItemID;
	strcpy(po->sSettDate,pi->sSettDate);
	po->iCnt=pi->iCnt;
	
	sprintf(po->sDuration,"%d",pi->iDuration);
	sprintf(po->sSettDuration,"%d",pi->iSettDuration);
	
	GetInFeeOrOutFeeFlag(pi->sProdID,sFeeType,pTicketType);
	if(strcmp(sFeeType,"0")==0){
		/*支出*/
		strcpy(po->sInFee,"0");
		sprintf(po->sOutFee,"%d",pi->iSettFee);
	}
	else if(strcmp(sFeeType,"1")==0){
		/*收入*/
		sprintf(po->sInFee,"%d",pi->iSettFee);
		strcpy(po->sOutFee,"0");
		
	}
	else{
		printf("sFeeType=[%s],ProdID=[%s]未找到匹配的FEE_TYPE\n",
			sFeeType,pi->sProdID);
	}

	strcpy(po->sMyNbrType,pi->sMyNbrType);
	strcpy(po->sMy3gFlag,pi->sMy3gFlag);
	strcpy(po->sOppCarrID,pi->sOppCarrID);
	strcpy(po->sOpp3gFlag,pi->sOpp3gFlag);
	strcpy(po->sServFlag,pi->sServFlag);
	
	AllTrim(po->sSettLatnID);
	AllTrim(po->sSettDate);
	AllTrim(po->sDuration);
	AllTrim(po->sSettDuration);
	AllTrim(po->sMyNbrType);
	AllTrim(po->sMy3gFlag);
	AllTrim(po->sOppCarrID);
	AllTrim(po->sOpp3gFlag);
	AllTrim(po->sServFlag);
		
	
}
int LoadSttDateToBintree(char sBilldate[],char sTableName[],
	struct TicketTypeMapStruct *pTicketType,BINTREE **pptRoot)
{
	long lDuration=0,lSettDuration=0,lInFee=0,lOutFee=0;
	unsigned long ulRecCnt=0;
	struct TemplateMidSttTicketStructIn TempIn;
	struct TemplateMidSttTicketStruct Temp;
	struct TemplateSttTrendStruct TrendTemp;
	struct TemplateSttTrendStruct *pTemp=NULL;
	struct TemplateSttTrendStruct *ptFound=NULL;
	
	bzero((void*)&TempIn,sizeof(struct TemplateMidSttTicketStructIn));
	bzero((void*)&Temp,sizeof(struct TemplateMidSttTicketStruct));
	bzero((void*)&TrendTemp,sizeof(struct TemplateSttTrendStruct));
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s)",sTableName,sBilldate);
	strcpy(TempIn.sCondition,"");
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetTemplateMidSttTicketToStruct(&Temp,&TempIn)){
		
		mvSttMidToSettTrend(pTicketType,&Temp,&TrendTemp);
		if(SearchBin(*pptRoot,&TrendTemp,data_search_setttrend,(void**)&ptFound)==FOUND){
					
			ptFound->iCnt += TrendTemp.iCnt;
			
			lDuration=atol(ptFound->sDuration)+atol(TrendTemp.sDuration);
			lSettDuration=atol(ptFound->sSettDuration)+atol(TrendTemp.sSettDuration);
			
			sprintf(ptFound->sDuration,"%ld",lDuration);
			sprintf(ptFound->sSettDuration,"%ld",lSettDuration);
			
			lInFee=atol(ptFound->sInFee)+atol(TrendTemp.sInFee);
			lOutFee=atol(ptFound->sOutFee)+atol(TrendTemp.sOutFee);
			
			sprintf(ptFound->sInFee,"%ld",lInFee);
			sprintf(ptFound->sOutFee,"%ld",lOutFee);			

		}
		else{
			if((pTemp=(struct TemplateSttTrendStruct*)
				malloc(sizeof(struct TemplateSttTrendStruct)))==NULL){
				WriteProcMsg("mallo struct TemplateSttTrendStruct 失败！！！");
				return -1;
			}
			bzero((void*)pTemp,sizeof(struct TemplateSttTrendStruct));
			memcpy((void*)pTemp,(void*)&TrendTemp,sizeof(struct TemplateSttTrendStruct));
			
			if(InsertBin(pptRoot,pTemp,data_search_setttrend,
					assign_insert_bintree_setttrend)<0){
				WriteProcMsg("生成二叉树 TemplateSttTrendStruct 失败.");
			 	return -1;
			}
		}
		ulRecCnt++;
	}
	WriteProcMsg("从表中 %s 读取数据 %d 条.",sTableName,ulRecCnt);
	
	return 0;
}
int EInsertList2TableSettTrend(char sTableName[],struct TemplateSttTrendStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct TemplateSttTrendStructOut TempOut;
	struct TemplateSttTrendStruct *ptCur=NULL;
	struct TemplateSttTrendStruct *ptLoadCur=NULL;
	
	bzero(&TempOut,sizeof(struct TemplateSttTrendStructOut));
	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
						
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToTemplateSttTrend(NULL,true,&TempOut)<0){
					WriteProcMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前输出数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToTemplateSttTrend(ptCur,false,&TempOut)<0){
				WriteProcMsg("写表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}

			free(ptCur);
		}
	}
	if(EInsertStructToTemplateSttTrend(NULL,true,&TempOut)<0){
		WriteProcMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcPrint("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);
	
	return 0;
}
int GenTicketTypeMapList(struct TicketTypeMapStruct **ppHead)
{
	int iCnt=0;
	
	struct TicketTypeMapStructIn TempIn;
	struct TicketTypeMapStruct Temp;
	struct TicketTypeMapStruct *pTemp=NULL;
	
	bzero((void*)&TempIn,sizeof(struct TicketTypeMapStructIn));
	bzero((void*)&Temp,sizeof(struct TicketTypeMapStruct));
	
	strcpy(TempIn.sTableName,"param.TICKET_TYPE_MAP");
	strcpy(TempIn.sCondition,"");
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetTicketTypeMapToStruct(&Temp,&TempIn)) {
		
		if((pTemp=(struct TicketTypeMapStruct*)
			malloc(sizeof(struct TicketTypeMapStruct)))==NULL){
			WriteProcMsg("malloc struct TicketTypeMapStruct 失败!!!");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct TicketTypeMapStruct));
		memcpy((void*)pTemp,(void*)&Temp,sizeof(struct TicketTypeMapStruct));
		
		InsertList((LIST **)ppHead,(LIST *)pTemp);
		iCnt++;
	}
	WriteProcMsg("从表%s中加载 %d 条数据到链表.",TempIn.sTableName,iCnt);
	
	return 0;
}
int DealProMainStt(char sBilldate[],char sNetWork[],char sCarrID[])
{
	char sTableNameIn[31],sTableNameOut[31],sMonth[3];
	
	struct TicketTypeMapStruct *pTicketType=NULL;
	BINTREE *pRoot=NULL;
	
	strncpy(sMonth,sBilldate+4,2);sMonth[2]=0;
	sprintf(sTableNameIn,"ST_%s_M_TICKET_%s_%s",sNetWork,sCarrID,sMonth);
	sprintf(sTableNameOut,"AN_%s_TREND_%s_%s",sNetWork,sCarrID,sMonth);
/*加载ticket_type_map配置表*/
	if(GenTicketTypeMapList(&pTicketType)<0) return -1;
/*加载统计中间表数据*/	
	if(LoadSttDateToBintree(sBilldate,sTableNameIn,pTicketType,&pRoot)<0) return-1;

	TravelBin(pRoot,append_bintree_to_list_trend);

	if(EInsertList2TableSettTrend(sTableNameOut,gTrendList)<0) return -1;
	
	DestroyBin(pRoot);
	pRoot=NULL;
	gTrendList=NULL;
	
	return 0;
}
int DealProMainMsg(char sBilldate[])
{
	return 0;
}
int main(int argc,char *argv[])
{
	char sNetWork[4],sCarrID[4],sBilldate[9];
	

	/*检查参数*/
	if(CheckParam(argc,argv)<0) return -1;
		
	strcpy(sBilldate,argv[1]);
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0)	return -1;
	
	if(argc==3){
		/*处理短信、彩信*/
		DealProMainMsg(sBilldate);
	}
	else{
		strcpy(sNetWork,argv[3]);
		strcpy(sCarrID,argv[4]);
		/*处理语音*/
		DealProMainStt(sBilldate,sNetWork,sCarrID);
	}
	DisconnectDatabase();
		
	
	return 0;
}


