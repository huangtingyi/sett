#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdb.h>
#include <bintree.h>


#include "ausett_supp.h"
#include "ausett_intf.h"

struct StatCtrlStruct g_StatCtrl;
struct AuSettNbrStatStruct *g_ptListIn=NULL;
struct AuSettNbrStatStruct *g_ptListOut=NULL;


int data_search_bintree_sett_nbr_stat(void *pValue,void *pData)
{
	int iRes;
	
	struct AuSettNbrStatStruct *pSource=(struct AuSettNbrStatStruct *)pValue;
	struct AuSettNbrStatStruct *pTarget=(struct AuSettNbrStatStruct *)pData;
	
	if((iRes=pSource->iReportItemID-pTarget->iReportItemID)!=0) return iRes;
	if((iRes=strcmp(pSource->sAccNbr,pTarget->sAccNbr))!=0) return iRes;
	if((iRes=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return iRes;
	if((iRes=strcmp(pSource->sSettType,pTarget->sSettType))!=0) return iRes;
	if((iRes=strcmp(pSource->sSettNbrType,pTarget->sSettNbrType))!=0) return iRes;
	if((iRes=strcmp(pSource->sSettCarrID,pTarget->sSettCarrID))!=0) return iRes;
	if((iRes=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return iRes;
	if((iRes=strcmp(pSource->sTrunkIn,pTarget->sTrunkIn))!=0) return iRes;
	if((iRes=strcmp(pSource->sTrunkOut,pTarget->sTrunkOut))!=0) return iRes;
	if((iRes=strcmp(pSource->sTrunkCarrierID,pTarget->sTrunkCarrierID))!=0) return iRes;
	if((iRes=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return iRes;
		
	return 0;
}
void assign_insert_bintree_sett_nbr_stat(void **ppData,void *pData)
{
	*ppData=pData;
}
int append_bintree_au_sett_nbr_stat_t(void **ppData)
{
	struct AuSettNbrStatStruct *pTemp=(struct AuSettNbrStatStruct *)*ppData;
	
	if(pTemp->iInFlag==1)
		InsertList((LIST**)&g_ptListIn,(LIST*)pTemp);
	else
		InsertList((LIST**)&g_ptListOut,(LIST*)pTemp);
}
int comp_list_accnbr(void *pValue,LIST *pData)
{
	struct AccNbrStruct *pSource=(struct AccNbrStruct *)pValue;
	struct AccNbrStruct *pTarget=(struct AccNbrStruct *)pData;
	
	return strcmp(pSource->sAccNbr,pTarget->sAccNbr);
}
void GenTableNameIn(struct StatCtrlStruct *pCtrl)
{
	char sTablePrefix[30];
	
	strcpy(sTablePrefix,"");
	if(strcmp(pCtrl->sDealType,"STT")==0){
		if(pCtrl->sNetType[0]=='P'){
			strcpy(sTablePrefix,"PSTN_");
		}
		
		sprintf(pCtrl->sTableNameIn,"%sSTT_TICKET_%s_%s",sTablePrefix,
			pCtrl->sCarrType,pCtrl->sMonth);
	}
	else{
		if(pCtrl->sNetType[0]=='G'){
			strcpy(sTablePrefix,"T_YD_UE_38_");
		}
		else if(pCtrl->sNetType[0]=='P'){
			strcpy(sTablePrefix,"T_GW_UE_38_");
		}
		sprintf(pCtrl->sTableNameIn,"%s%s",sTablePrefix,pCtrl->sBillingDate);
	}

}
void GenTableNameOut(struct StatCtrlStruct *pCtrl)
{
	if(strcmp(pCtrl->sDealType,"STT")==0){
		sprintf(pCtrl->sTableNameOut0,"AU_SETT_NBR_OUT_STAT_%s",pCtrl->sMonth);
		sprintf(pCtrl->sTableNameOut1,"AU_SETT_NBR_IN_STAT_%s",pCtrl->sMonth);
		sprintf(pCtrl->sTableNameOther,"AU_SETT_OTH_STAT_%s",pCtrl->sMonth);
	}
	else{
		sprintf(pCtrl->sTableNameOut0,"AU_OPP_SETT_NBR_OUT_STAT_%s",pCtrl->sMonth);
		sprintf(pCtrl->sTableNameOut1,"AU_OPP_SETT_NBR_IN_STAT_%s",pCtrl->sMonth);
	}
}
void GenSettTypeStt(char sSettType[])
{
	sSettType[0]=0;
	if(strcmp(g_StatCtrl.sNetType,"G")==0){
		if(strcmp(g_StatCtrl.sCarrType,"CT")==0)
			strcpy(sSettType,"10");
		else if(strcmp(g_StatCtrl.sCarrType,"CTC")==0)
			strcpy(sSettType,"11");
		else if(strcmp(g_StatCtrl.sCarrType,"CM")==0)
			strcpy(sSettType,"12");
		else if(strcmp(g_StatCtrl.sCarrType,"CRC")==0)
			strcpy(sSettType,"13");
	}
	else{
		if(strcmp(g_StatCtrl.sCarrType,"CT")==0)
			strcpy(sSettType,"20");
		else if(strcmp(g_StatCtrl.sCarrType,"CTC")==0)
			strcpy(sSettType,"21");
		else if(strcmp(g_StatCtrl.sCarrType,"CM")==0)
			strcpy(sSettType,"22");
		else if(strcmp(g_StatCtrl.sCarrType,"CRC")==0)
			strcpy(sSettType,"23");
	}
}
int GetReportItemIDStt(struct ReportItemConfigExtStruct *ptHead,
	struct SttTicketStruct *pValue,struct AuSettNbrStatStruct *po)
{
	static char sBuf[2];
	static struct ReportItemConfigExtStruct *ptFound;
	
	if(SearchReportItemConfig(ptHead,pValue,&ptFound)==NOTFOUND){
		po->iReportItemID=9000000+pValue->iTicketTypeID;
		po->iInFlag=3;
		strcpy(po->sSettType,g_StatCtrl.sSettType);
		WriteAlertMsg("无匹配的报表项:ticket_type_id=%d,msisdn=%s",pValue->iTicketTypeID,
			pValue->sMsisdn);
		return 0;
	}
	
	po->iReportItemID=ptFound->iReportItemID;
	strcpy(po->sSettType,ptFound->sSettType);
	sBuf[0]=ptFound->sFeeType[0];
	sBuf[1]=0;
	po->iInFlag=atoi(sBuf);
	
	if(po->iInFlag==0 || po->iInFlag==2){
		if(ptFound->sFeeType[1]=='C'){
			strcpy(po->sAccNbr,pValue->sOtherParty);
			strcpy(po->sHomeAreaCode,pValue->sCalledCode);
			strcpy(po->sCalledCode,pValue->sHomeAreaCode);
		}
		else{
			strcpy(po->sAccNbr,pValue->sMsisdn);
			strcpy(po->sHomeAreaCode,pValue->sHomeAreaCode);
			strcpy(po->sCalledCode,pValue->sCalledCode);
		}
	}
	else if(po->iInFlag==1){
		if(ptFound->sFeeType[1]=='C'){
			strcpy(po->sAccNbr,pValue->sMsisdn);
			strcpy(po->sHomeAreaCode,pValue->sHomeAreaCode);
			strcpy(po->sCalledCode,pValue->sCalledCode);
		}
		else{
			strcpy(po->sAccNbr,pValue->sOtherParty);
			strcpy(po->sHomeAreaCode,pValue->sCalledCode);
			strcpy(po->sCalledCode,pValue->sHomeAreaCode);
		}
	}
		
	return 0;
}
void GetSettNbrTypeStt(struct AuSettNbrStatStruct *po)
{
	char sCarrType[6];
	
	strcpy(sCarrType,g_StatCtrl.sCarrType);
	
	if(strcmp(sCarrType,"CM")==0){
		if(po->sNetType[0]=='G'){
			strcpy(po->sSettNbrType,"CMM");
		}
		else{
			strcpy(po->sSettNbrType,"CRC");
		}
		
		strcpy(po->sSettCarrID,"2");
	}
	else if(strcmp(sCarrType,"CT")==0){
		strcpy(po->sSettNbrType,"CT");
		strcpy(po->sSettCarrID,"1");
		
	}
	else if(strcmp(sCarrType,"CTC")==0){
		strcpy(po->sSettNbrType,"CTC");
		strcpy(po->sSettCarrID,"1");
		
	}
	else if(strcmp(sCarrType,"CRC")==0){
		strcpy(po->sSettNbrType,"CRC");
		strcpy(po->sSettCarrID,"2");
	}
	else if(strcmp(sCarrType,"CNC")==0){
		strcpy(po->sSettCarrID,"4");
		strcpy(po->sSettNbrType,"CNC");
	}
	
}
int DealSttRecord(struct SttTicketStruct *pi,struct AuSettNbrStatStruct *po)
{
	strcpy(po->sVisitAreaCode,pi->sVisitAreaCode);
	strcpy(po->sNetType,g_StatCtrl.sNetType);
	strcpy(po->sMsc,pi->sMsc);
	strcpy(po->sTrunkIn,pi->sTrunkIn);
	strcpy(po->sTrunkOut,pi->sTrunkOut);
	strncpy(po->sBillingCycleID,g_StatCtrl.sBillingDate,6);
	po->sBillingCycleID[6]=0;
	GetSettNbrTypeStt(po);
	
	po->iSettMin=(pi->iDuration+59)/60;
	po->iCnt=1;
	po->dDuration=pi->iDuration;
	
	if(po->iInFlag==1){/*收入*/
		po->dFee = pi->iAddFee-pi->iTollFee;
		sprintf(po->sTrunkCarrierID,"%1d",pi->iTrunkInCarrierID);
	}
	else{		/*支出*/
		po->dFee = pi->iTollFee-pi->iAddFee;
		sprintf(po->sTrunkCarrierID,"%1d",pi->iTrunkOutCarrierID);
	}
	if(po->dFee<0.0) po->dFee=0.0;
		
	return 0;
}

int GenSqlCondition(struct AuSettNbrStatStruct *ptHead,struct AuSettNbrStatStruct **pptNewHead,
	char sCondi[])
{
	int iCnt=0;
	int iOff=0;
	struct AccNbrStruct temp,*pTemp,*ptFound,*ptNbrHead=NULL;
	
	*pptNewHead=NULL;
	if(ptHead==NULL){
		strcpy(sCondi," ");
		return 0;
	}
	
	while(ptHead!=NULL){
		
		strcpy(temp.sAccNbr,ptHead->sAccNbr);
		if(SearchList((LIST*)ptNbrHead,&temp,(LIST**)&ptFound,
			comp_list_accnbr)==NOTFOUND){
			if((pTemp=malloc(sizeof(struct AccNbrStruct)))==NULL){
				WriteAlertMsg("malloc AccNbrStruct failed.");
				return -1;
			}
			strcpy(pTemp->sAccNbr,ptHead->sAccNbr);
			InsertList((LIST**)&ptNbrHead,(LIST*)pTemp);
			++iCnt;
		}
		if(iCnt==50){
			*pptNewHead=ptHead->pNext;
			ptHead->pNext=NULL;
			break;
		}
			
		ptHead=ptHead->pNext;
	}
	
	
	iOff+=sprintf(sCondi,"WHERE acc_nbr IN (");
	while(ptNbrHead!=NULL){
		pTemp=ptNbrHead;
		ptNbrHead=ptNbrHead->pNext;
		
		iOff+=sprintf(sCondi+iOff,"'%s',",pTemp->sAccNbr);
		
		free(pTemp);	
	}
	sCondi[iOff-1]=')';
	
	return 0;
}

int OutputNbrStatData2Table_t(struct AuSettNbrStatStruct *ptHead,char sTemplateName[],
	char sTableName[])
{
	char sCondi[1024];
	struct AuSettNbrStatStruct *ptHeadNew;
	
	if(GenSqlCondition(ptHead,&ptHeadNew,sCondi)<0) return -1;
	
	return 0;
}

/* 按天加载我方的详单表 */
int DealSttTicketTable2Bin(struct ReportItemConfigExtStruct *ptHead,BINTREE **pptRoot)
{
	int iRecCnt=0,iNodeCnt=0;
	long long llSize=0;
	char sPartitionInfo[64];
	BINTREE *ptRootStat=NULL;
	struct AuSettNbrStatStruct *pTemp,*ptFound,snsTemp;
	
	struct SttTicketStruct Temp;
	struct SttTicketStructIn TempIn;
	
	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));
	sprintf(TempIn.sTableName,"%s partition(part%s)",g_StatCtrl.sTableNameIn,g_StatCtrl.sBillingDate);
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSttTicketToStruct_t(&Temp,&TempIn)){
		if(++iRecCnt%100000==0){
			WriteProcMsg("正在加载表 %s,记录数 %d",g_StatCtrl.sTableNameIn,iRecCnt);
		}
		
		if(GetReportItemIDStt(ptHead,&Temp,&snsTemp)<0) return -1;
		DealSttRecord(&Temp,&snsTemp);
		
		if(SearchBin(ptRootStat,&snsTemp,data_search_bintree_sett_nbr_stat,
			(void**)&ptFound)==FOUND){
			ptFound->iCnt+=snsTemp.iCnt;
			ptFound->iSettMin+=snsTemp.iSettMin;
			ptFound->dFee+=snsTemp.dFee;
			ptFound->dDuration+=snsTemp.dDuration;
		}
		else{
			++iNodeCnt;
			llSize+=sizeof(struct AuSettNbrStatStruct);
			
			if((pTemp=malloc(sizeof(struct AuSettNbrStatStruct)))==NULL){
				WriteAlertMsg("malloc AuSettNbrStatStruct failed.");
				return -1;
			}
			memcpy(pTemp,&snsTemp,sizeof(struct AuSettNbrStatStruct));
			pTemp->pNext=NULL;
			
			if(InsertBin(&ptRootStat,pTemp,data_search_bintree_sett_nbr_stat,
				assign_insert_bintree_sett_nbr_stat)<0){
				WriteAlertMsg("建树 AuSettNbrStatStruct 失败.");
				return -1;
			}
		}
		
		if(iNodeCnt%1000000==0){
			WriteAlertMsg("iNodeCnt=%d,llSize=%lldMB",iNodeCnt,llSize/(1024*1024));
		}
	}
	WriteProcMsg("加载表 %s 完成,记录数 %d,Node=%d",g_StatCtrl.sTableNameIn,iRecCnt,iNodeCnt);
	WriteAlertMsg("iNodeCnt=%d,llSize=%lldMB",iNodeCnt,llSize/(1024*1024));
	return 0;
}
int LoadReportItemConfig2List(struct ReportItemConfigExtStruct **pptHead)
{
	char sCondi[512];
	
	GenSettTypeStt(g_StatCtrl.sSettType);
	if(g_StatCtrl.sSettType[0]==0)
		strcpy(sCondi," ");
	else
		sprintf(sCondi,"WHERE sett_type='%s' ",g_StatCtrl.sSettType);
	if(LoadTableReportItemConfig("param.report_item_config",sCondi,pptHead)<0){
		WriteState2LogTable(&g_StatCtrl,"P0F");
		return -1;
	}
	
	return 0;
}
void PrintHelpMsg(char sProgram[])
{
	printf("%s CarrType(cm|ct|ctc|cnc|crc) NetType(g|p) BillingCycleID(yyyymmdd) DealType(stt|opp)\n\n",sProgram);
}
int main(int argc,char *argv[])
{
	BINTREE *ptRoot=NULL;
	struct ReportItemConfigExtStruct *ptListRepParam=NULL;
	
	if(argc!=5){
		PrintHelpMsg(argv[0]);
		return -1;
	}
	
	strcpy(g_StatCtrl.sCarrType,argv[1]);
	strcpy(g_StatCtrl.sNetType,argv[2]);
	strcpy(g_StatCtrl.sBillingDate,argv[3]);
	strcpy(g_StatCtrl.sDealType,argv[4]);
	strncpy(g_StatCtrl.sMonth,g_StatCtrl.sBillingDate+4,2);
	g_StatCtrl.sMonth[2]=0;
	Upper(g_StatCtrl.sCarrType);
	Upper(g_StatCtrl.sNetType);
	Upper(g_StatCtrl.sDealType);
	
	GenTableNameIn(&g_StatCtrl);
	GenTableNameOut(&g_StatCtrl);
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
		
	if(ChkDate(g_StatCtrl.sBillingDate)<0){
		WriteAlertMsg("参数StatDate=%s 无效",g_StatCtrl.sBillingDate);
		WriteState2LogTable(&g_StatCtrl,"P0F");
		return -1;
	}
	if(LoadReportItemConfig2List(&ptListRepParam)<0) return -1;
		
	
	if(strcmp(g_StatCtrl.sDealType,"STT")==0){
		if(DealSttTicketTable2Bin(ptListRepParam,&ptRoot)<0) return -1;
	}
	else if(strcmp(g_StatCtrl.sDealType,"OPP")==0){
	}
	else{
		WriteAlertMsg("DealType=%s 无效.",g_StatCtrl.sDealType);
		return -1;
	}

/* 将统计树转成 收入,支出两条链表 */	
	TravelBin(ptRoot,append_bintree_au_sett_nbr_stat_t);
	
/* 统计数据写到收入表 */
	if(OutputNbrStatData2Table_t(g_ptListIn,"TMP_SETT_NBR_IN_STAT",g_StatCtrl.sTableNameOut1)<0){
		WriteState2LogTable(&g_StatCtrl,"P0F");
		DisconnectDatabase();
		return -1;
	}
/* 统计数据写到支出表 */
	if(OutputNbrStatData2Table_t(g_ptListOut,"TMP_SETT_NBR_OUT_STAT",g_StatCtrl.sTableNameOut0)<0){
		WriteState2LogTable(&g_StatCtrl,"P0F");
		DisconnectDatabase();
		return -1;
	}
	
	DisconnectDatabase();
	WriteProcMsg("settnbrstat 程序运行成功.");
	
	return 0;
}


