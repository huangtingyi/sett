#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
#include "ticket_field.h"

char gsCarrID[4],gsNetWork[4];

struct TemplateMidSttTicketStruct *gMidSttList=NULL;

int data_search_mid_stt(void *pValue,void *pData)
{
	int iResult=0;
	
	struct TemplateMidSttTicketStruct *pSource=(struct TemplateMidSttTicketStruct*)pValue;
	struct TemplateMidSttTicketStruct *pTarget=(struct TemplateMidSttTicketStruct*)pData;

	if((iResult=strcmp(pSource->sProdID,		pTarget->sProdID))!=0) return iResult;
	if((iResult=strcmp(pSource->sMsisdn,		pTarget->sMsisdn))!=0) return iResult;
	if((iResult=strcmp(pSource->sOtherParty,	pTarget->sOtherParty))!=0) return iResult;
/*
	if((iResult=strcmp(pSource->sSettLatnID,	pTarget->sSettLatnID))!=0) return iResult;
	if((iResult=pSource->iReportItemID - pTarget->iReportItemID)!=0) return iResult;
	if((iResult=strcmp(pSource->sCallType,		pTarget->sCallType))!=0) return iResult;
	if((iResult=strcmp(pSource->sHomeAreaCode,	pTarget->sHomeAreaCode))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppAreaCode,	pTarget->sOppAreaCode))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyDistanceType,	pTarget->sMyDistanceType))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppDistanceType,	pTarget->sOppDistanceType))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyNbrType,		pTarget->sMyNbrType))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppNbrType,	pTarget->sOppNbrType))!=0) return iResult;
	if((iResult=strcmp(pSource->sMy3gFlag,		pTarget->sMy3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sOpp3gFlag,		pTarget->sOpp3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyCarrID,		pTarget->sMyCarrID))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppCarrID,		pTarget->sOppCarrID))!=0) return iResult;
	if((iResult=strcmp(pSource->sServFlag,		pTarget->sServFlag))!=0) return iResult;
*/
	return iResult;
}

int SearchMidStatItem(BINTREE *ptRoot,struct TemplateMidSttTicketStruct *p,
	struct TemplateMidSttTicketStruct **pptCur)
{
	int iResult=NULL;
	struct TemplateMidSttTicketStruct *ptHead=NULL,*pTemp;
	
	*pptCur=NULL;
	if(SearchBin(ptRoot,p,data_search_mid_stt,(void**)&ptHead)==FOUND){
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			
			if((iResult=strcmp(pTemp->sSettLatnID,		p->sSettLatnID))!=0) continue;
			if((iResult=pTemp->iReportItemID - 		p->iReportItemID)!=0) continue;
			if((iResult=strcmp(pTemp->sCallType,		p->sCallType))!=0) continue;
			if((iResult=strcmp(pTemp->sHomeAreaCode,	p->sHomeAreaCode))!=0) continue;
			if((iResult=strcmp(pTemp->sOppAreaCode,		p->sOppAreaCode))!=0) continue;
			if((iResult=strcmp(pTemp->sMyDistanceType,	p->sMyDistanceType))!=0) continue;
			if((iResult=strcmp(pTemp->sOppDistanceType,	p->sOppDistanceType))!=0) continue;
			if((iResult=strcmp(pTemp->sMyNbrType,		p->sMyNbrType))!=0) continue;
			if((iResult=strcmp(pTemp->sOppNbrType,		p->sOppNbrType))!=0) continue;
			if((iResult=strcmp(pTemp->sMy3gFlag,		p->sMy3gFlag))!=0) continue;
			if((iResult=strcmp(pTemp->sOpp3gFlag,		p->sOpp3gFlag))!=0) continue;
			if((iResult=strcmp(pTemp->sMyCarrID,		p->sMyCarrID))!=0) continue;
			if((iResult=strcmp(pTemp->sOppCarrID,		p->sOppCarrID))!=0) continue;
			if((iResult=strcmp(pTemp->sServFlag,		p->sServFlag))!=0) continue;
			
			*pptCur=pTemp;
			return FOUND;
		}
	}
	
	return NOTFOUND;
}
void assign_insert_bintree_mid_stt(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int append_bintree_to_list_mid_stt(void **ppData)
{
	struct TemplateMidSttTicketStruct *pTemp=(struct TemplateMidSttTicketStruct*)(*ppData);

	pTemp->pLoadNext=gMidSttList;
	gMidSttList=pTemp;

	return 0;
}
int CheckParam(int argc,char **argv)
{	
	char sType[4],sBillDate[9];
	
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

int IsNumber(char sTemp[])
{
	int i,iLen;
	
	iLen=strlen(sTemp);
	for(i=0;i<iLen;i++){
		if((sTemp[i]>='a'&&sTemp[i]<='z')||
			(sTemp[i]>='A'&&sTemp[i]<='Z')) return false;
	}
	return true;
}

int SetSettNbrType(char sMsisdn[],char sAreaCode[],char sStartTime[],
		char sNbrType[],char sNetType[])
{
	char sRawNbr[25];
	int iRet;
	struct HeadCarrStruct *pHeadCarr;
	
/*去掉引示号,区号等*/
	AllTrim(sMsisdn);
	AllTrim(sAreaCode);
	NewGetRawNbr(sMsisdn,sAreaCode,sStartTime,sRawNbr);
	if((iRet=SearchHeadCarr(sRawNbr,"*",sStartTime,&pHeadCarr))==FOUND){
		/*特服号码*/
		if(strcmp(pHeadCarr->sType,"S")==0||
			strcmp(pHeadCarr->sType,"F")==0||
			strcmp(pHeadCarr->sType,"X")==0){
			strcpy(sNbrType,pHeadCarr->sType);
			strcpy(sNetType,"2");
			return FOUND;
		}
	}

	if(IS_MOB_NBR(sRawNbr)){/*移动网号码*/
		if(IS_MOBILE_TD(sRawNbr)){
			strcpy(sNbrType,"U");
			strcpy(sNetType,"1");
			return FOUND;
		}
		if(IS_MOBILE_GSM(sRawNbr)){
			strcpy(sNbrType,"G");
			strcpy(sNetType,"0");
			return FOUND;
		}
		if(IS_UNICOM_CDMA(sRawNbr)){
			strcpy(sNbrType,"G");
			strcpy(sNetType,"0");
			return FOUND;
		}
		if(IS_UNICOM_WCDMA(sRawNbr)){
			strcpy(sNbrType,"U");
			strcpy(sNetType,"1");
			return FOUND;
		}
		if(IS_UNICOM_GSM(sRawNbr)){
			strcpy(sNbrType,"G");
			strcpy(sNetType,"0");
			return FOUND;
		}
	}
	else{/*固网号码*/	
		if(iRet==FOUND){		
			/*常规号码*/
			if(strcmp(pHeadCarr->sType,"C")==0){
				if(pHeadCarr->iSettCarrierID==1){
					strcpy(sNbrType,"C");
					strcpy(sNetType,"2");
					return FOUND;
				}
				if(pHeadCarr->iSettCarrierID==4){
					strcpy(sNbrType,"C");
					strcpy(sNetType,"2");
					return FOUND;
				}
				if(pHeadCarr->iSettCarrierID==5){
					strcpy(sNbrType,"C");
					strcpy(sNetType,"2");
					return FOUND;
				}
			}
		}
	}
/*不规则号码*/
	strcpy(sNbrType,"E");
	strcpy(sNetType,"2");
	return FOUND;
}
int SearchTicketTypeMapStructItem(char sProdID[],struct TicketTypeMapStruct **pptCur)
{
	static int iFirstFlag=true;
	static struct TicketTypeMapStruct *ptHead=NULL;
	struct TicketTypeMapStruct *pTemp,*ptLkHead;
	if(iFirstFlag==true){
		if(InitTicketTypeMap(&ptHead)<0) return -1;
		
		iFirstFlag=false;
	}
	
	ptLkHead=ptHead;
	while(ptLkHead!=NULL){
		pTemp=ptLkHead;
		ptLkHead=ptLkHead->pNext;
		
		if(strcmp(sProdID,pTemp->sProdID)==0){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	return NOTFOUND;
}
void AnalyzeCarrID(char sTrunkGroup[],char sCarrID[])
{
/*	strcpy(sCarrID,"0");
	if(strcmp(sTrunkGroup,"9001")==0) strcpy(sCarrID,"4");
	else if(strcmp(sTrunkGroup,"9002")==0) strcpy(sCarrID,"2");
	else if(strcmp(sTrunkGroup,"9003")==0) strcpy(sCarrID,"3");
	else if(strcmp(sTrunkGroup,"9004")==0) strcpy(sCarrID,"5");
	else if(strcmp(sTrunkGroup,"9005")==0) strcpy(sCarrID,"1");
	else if(strcmp(sTrunkGroup,"9007")==0) strcpy(sCarrID,"6");
*/	
	strcpy(sCarrID,"0");
	if(strcmp(sTrunkGroup,"1")==0) strcpy(sCarrID,"4");
	else if(strcmp(sTrunkGroup,"2")==0) strcpy(sCarrID,"2");
	else if(strcmp(sTrunkGroup,"3")==0) strcpy(sCarrID,"3");
	else if(strcmp(sTrunkGroup,"4")==0) strcpy(sCarrID,"5");
	else if(strcmp(sTrunkGroup,"5")==0){
		if(strcmp(gsCarrID,"CTC")==0&&strcmp(gsNetWork,"GW")==0)
			strcpy(sCarrID,"6");
		else 	strcpy(sCarrID,"1");
	}
	else if(strcmp(sTrunkGroup,"7")==0) strcpy(sCarrID,"6");
}
int mvDetailtoMidtable(char sPart[],struct TTemplateYdGwUeStruct *pi,
	struct TemplateMidSttTicketStruct *po)
{
	int iSettDuration=0,i;
	char	sOtherGroupID[3],sAreaCode[9],sTemp[10];
	struct TicketTypeMapStruct *pTicketTypeMap=NULL;
	
	bzero((void*)po,sizeof(struct TemplateMidSttTicketStruct));
	
	sprintf(sTemp,"%d",pi->iCityID);
	strncpy(sAreaCode,	sTemp,3);sAreaCode[3]=0;
	AllTrim(sAreaCode);
	strcpy(po->sProdID,pi->sProdID);
	
	if(strncmp(sTemp,"591",3)==0)		strcpy(po->sSettLatnID,"A");
	else if(strncmp(sTemp,"592",3)==0)	strcpy(po->sSettLatnID,"B");
	else if(strncmp(sTemp,"593",3)==0)	strcpy(po->sSettLatnID,"E");
	else if(strncmp(sTemp,"594",3)==0)	strcpy(po->sSettLatnID,"F");
	else if(strncmp(sTemp,"595",3)==0)	strcpy(po->sSettLatnID,"C");
	else if(strncmp(sTemp,"596",3)==0)	strcpy(po->sSettLatnID,"D");
	else if(strncmp(sTemp,"597",3)==0)	strcpy(po->sSettLatnID,"I");
	else if(strncmp(sTemp,"598",3)==0)	strcpy(po->sSettLatnID,"H");
	else if(strncmp(sTemp,"599",3)==0)	strcpy(po->sSettLatnID,"G");
	
	if(SearchTicketTypeMapStructItem(po->sProdID,&pTicketTypeMap)==NOTFOUND) return false;
	strcpy(po->sCallType,		pTicketTypeMap->sCallType);
	po->iReportItemID=pTicketTypeMap->iReportItemID;
	
	if(strcmp(pTicketTypeMap->sCallType,"1")==0){
		strncpy(po->sHomeAreaCode,pi->sCallingAreaCode,5);
			po->sHomeAreaCode[5]=0;AllTrim(po->sHomeAreaCode);
		strncpy(po->sMsisdn,pi->sCallingNumber,15);
			po->sMsisdn[15]=0;AllTrim(po->sMsisdn);
		strncpy(po->sOppAreaCode,pi->sCalledAreaCode,5);
			po->sOppAreaCode[5]=0;AllTrim(po->sOppAreaCode);
		strncpy(po->sOtherParty,pi->sCalledNumber,15);
			po->sOtherParty[15]=0;AllTrim(po->sOtherParty);
		strncpy(sTemp,pi->sInTrunkGroup+3,1);sTemp[1]=0;AllTrim(sTemp);
		AnalyzeCarrID(sTemp,po->sMyCarrID);
		strncpy(sTemp,pi->sOutTrunkGroup+3,1);sTemp[1]=0;AllTrim(sTemp);
		AnalyzeCarrID(sTemp,po->sOppCarrID);
		/*
		strncpy(po->sMyCarrID,pi->sInTrunkGroup+3,1);po->sMyCarrID[1]=0;
		strncpy(po->sOppCarrID,pi->sOutTrunkGroup+3,1);po->sOppCarrID[1]=0;*/
	}
	else{
		strncpy(po->sHomeAreaCode,pi->sCalledAreaCode,5);
			po->sHomeAreaCode[5]=0;AllTrim(po->sHomeAreaCode);
		strncpy(po->sMsisdn,pi->sCalledNumber,15);
			po->sMsisdn[15]=0;AllTrim(po->sMsisdn);
		strncpy(po->sOppAreaCode,pi->sCallingAreaCode,5);
			po->sOppAreaCode[5]=0;AllTrim(po->sOppAreaCode);
		strncpy(po->sOtherParty,pi->sCallingNumber,15);
			po->sOtherParty[15]=0;AllTrim(po->sOtherParty);
		
		strncpy(sTemp,pi->sOutTrunkGroup+3,1);sTemp[1]=0;AllTrim(sTemp);
		AnalyzeCarrID(sTemp,po->sMyCarrID);
		strncpy(sTemp,pi->sInTrunkGroup+3,1);sTemp[1]=0;AllTrim(sTemp);
		AnalyzeCarrID(sTemp,po->sOppCarrID);
/*		
		strncpy(po->sMyCarrID,pi->sOutTrunkGroup+3,1);po->sMyCarrID[1]=0;
		strncpy(po->sOppCarrID,pi->sInTrunkGroup+3,1);po->sOppCarrID[1]=0;*/
	}
	
	strncpy(po->sSettDate,sPart,8);

	po->iCnt=1;
	po->iDuration=atoi(pi->sDuration);
	
	if(pi->iRateUnitType==2)
		po->iSettDuration=pi->iRateUnits*60;
	else if(pi->iRateUnitType==6)
		po->iSettDuration=pi->iRateUnits*6;
	else	po->iSettDuration=0;
/*	
	iSettDuration=(po->iDuration+59)/60;
	po->iSettDuration=iSettDuration*60;
*/	
	po->iSettFee=atoi(pi->sTotalDueAmount)/100;

	if(strcmp(po->sCallType,"1")==0){
		if(strcmp(sAreaCode,po->sHomeAreaCode)==0) strcpy(po->sMyDistanceType,"0");
		else if(strcmp(po->sHomeAreaCode,"591")==0||strcmp(po->sHomeAreaCode,"592")==0||
			strcmp(po->sHomeAreaCode,"593")==0||strcmp(po->sHomeAreaCode,"594")==0||
			strcmp(po->sHomeAreaCode,"595")==0||strcmp(po->sHomeAreaCode,"596")==0||
			strcmp(po->sHomeAreaCode,"597")==0||strcmp(po->sHomeAreaCode,"598")==0||
			strcmp(po->sHomeAreaCode,"599")==0) strcpy(po->sMyDistanceType,"1");
		else	strcpy(po->sMyDistanceType,"2");

		if(strcmp(sAreaCode,po->sOppAreaCode)==0) strcpy(po->sOppDistanceType,"0");
		else if(strcmp(po->sOppAreaCode,"591")==0||strcmp(po->sOppAreaCode,"592")==0||
			strcmp(po->sOppAreaCode,"593")==0||strcmp(po->sOppAreaCode,"594")==0||
			strcmp(po->sOppAreaCode,"595")==0||strcmp(po->sOppAreaCode,"596")==0||
			strcmp(po->sOppAreaCode,"597")==0||strcmp(po->sOppAreaCode,"598")==0||
			strcmp(po->sOppAreaCode,"599")==0) strcpy(po->sOppDistanceType,"1");
		else	strcpy(po->sOppDistanceType,"2");
		
	}
	else{
		if(strcmp(sAreaCode,po->sOppAreaCode)==0) strcpy(po->sMyDistanceType,"0");
		else if(strcmp(po->sOppAreaCode,"591")==0||strcmp(po->sOppAreaCode,"592")==0||
			strcmp(po->sOppAreaCode,"593")==0||strcmp(po->sOppAreaCode,"594")==0||
			strcmp(po->sOppAreaCode,"595")==0||strcmp(po->sOppAreaCode,"596")==0||
			strcmp(po->sOppAreaCode,"597")==0||strcmp(po->sOppAreaCode,"598")==0||
			strcmp(po->sOppAreaCode,"599")==0) strcpy(po->sMyDistanceType,"1");
		else	strcpy(po->sMyDistanceType,"2");
			
		if(strcmp(sAreaCode,po->sHomeAreaCode)==0) strcpy(po->sOppDistanceType,"0");
		else if(strcmp(po->sHomeAreaCode,"591")==0||strcmp(po->sHomeAreaCode,"592")==0||
			strcmp(po->sHomeAreaCode,"593")==0||strcmp(po->sHomeAreaCode,"594")==0||
			strcmp(po->sHomeAreaCode,"595")==0||strcmp(po->sHomeAreaCode,"596")==0||
			strcmp(po->sHomeAreaCode,"597")==0||strcmp(po->sHomeAreaCode,"598")==0||
			strcmp(po->sHomeAreaCode,"599")==0) strcpy(po->sOppDistanceType,"1");
		else	strcpy(po->sOppDistanceType,"2");
		
	}
	
	SetSettNbrType(po->sMsisdn,po->sHomeAreaCode,
			pi->sStartTime,po->sMyNbrType,po->sMy3gFlag);
	SetSettNbrType(po->sOtherParty,po->sOppAreaCode,
		pi->sStartTime,po->sOppNbrType,po->sOpp3gFlag);

	strcpy(po->sServFlag,"1");
	strcpy(po->sGroupID,		pi->sGroupID);
	
	AllTrim(po->sOtherParty);
	
	i=strlen(po->sOtherParty);
	if(i<=2) strcpy(sOtherGroupID,po->sOtherParty);
	else{
		strncpy(sOtherGroupID,po->sOtherParty+i-2,2);
		sOtherGroupID[2]=0;
	}
	
	if(IsNumber(sOtherGroupID)==false) 
		strcpy(po->sOtherGroupID,"00");
	else	strcpy(po->sOtherGroupID,sOtherGroupID);
	
	AllTrim(po->sSettLatnID);
	AllTrim(po->sProdID);
	AllTrim(po->sCallType);
	AllTrim(po->sHomeAreaCode);
	AllTrim(po->sMsisdn);
	AllTrim(po->sOppAreaCode);
	AllTrim(po->sOtherParty);
	AllTrim(po->sSettDate);
	AllTrim(po->sMyDistanceType);
	AllTrim(po->sOppDistanceType);
	AllTrim(po->sMyNbrType);
	AllTrim(po->sOppNbrType);
	AllTrim(po->sMy3gFlag);
	AllTrim(po->sOpp3gFlag);
	AllTrim(po->sMyCarrID);
	AllTrim(po->sOppCarrID);
	AllTrim(po->sServFlag);
	AllTrim(po->sGroupID);
	AllTrim(po->sOtherGroupID);
	
	return true;
}
int LoadTabletoBintree(int iGroupID,char sPart[],char sTableNameIn[],BINTREE **pptRoot)
{
	unsigned long ulRecCnt=0,ulold=0,ulnew=0;
	struct TTemplateYdGwUeStructIn TempIn;
	struct TTemplateYdGwUeStruct Temp;
	
	struct TemplateMidSttTicketStruct TempMid;
	struct TemplateMidSttTicketStruct *pTemp=NULL;
	struct TemplateMidSttTicketStruct *ptFound=NULL;
	
	bzero((void*)&TempIn,sizeof(struct TemplateSttTicketStructIn));
	bzero((void*)&Temp,sizeof(struct TemplateSttTicketStruct));
	
	/*strcpy(TempIn.sTableName,sTableNameIn);
	strcpy(TempIn.sCondition,"");*/
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s)",sTableNameIn,sPart);
	sprintf(TempIn.sCondition,"WHERE GROUP_ID='%02d'",iGroupID);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetTTemplateYdGwUeToStruct(&Temp,&TempIn)) {
		
		/*转换结构体格式*/
		if(mvDetailtoMidtable(sPart,&Temp,&TempMid)==false) continue;
		
/*		if(SearchBin(*pptRoot,&TempMid,data_search_mid_stt,(void**)&ptFound)==FOUND){*/
		if(SearchMidStatItem(*pptRoot,&TempMid,&ptFound)==FOUND){
			ptFound->iCnt += 1;
			ptFound->iDuration += TempMid.iDuration;
			ptFound->iSettDuration += TempMid.iSettDuration;
			ptFound->iSettFee += TempMid.iSettFee;
			ulold++;
		}
		else{
			if((pTemp=(struct TemplateMidSttTicketStruct*)
				malloc(sizeof(struct TemplateMidSttTicketStruct)))==NULL){
				WriteProcMsg("malloc struct TemplateMidSttTicketStruct 失败!!!");
				return -1;
			}
			bzero((void*)pTemp,sizeof(struct TemplateMidSttTicketStruct));
			memcpy((void*)pTemp,(void*)&TempMid,sizeof(struct TemplateMidSttTicketStruct));

			if(InsertBin(pptRoot,pTemp,data_search_mid_stt,
				assign_insert_bintree_mid_stt)<0){
				WriteProcMsg("生成二叉树 TemplateMidSttTicketStruct 失败.");
				return -1;
			}
			ulnew++;
		}
		ulRecCnt++;
		if((++ulRecCnt)%50000==0){
			WriteProcMsg("从表中 %s 读取数据 %d 条. ",sTableNameIn,ulRecCnt);
		}
		
	}
	
	WriteProcMsg("组号：%02d ,从表中 %s 读取数据 %d 条. 新增 %d 条,累加 %d 条",iGroupID,sTableNameIn,ulRecCnt,ulnew,ulold);
	
	return 0;
}
int EInsertList2TableStt(char sTableName[],struct TemplateMidSttTicketStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct TemplateMidSttTicketStructOut TempOut;
	struct TemplateMidSttTicketStruct *ptCur=NULL;
	struct TemplateMidSttTicketStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct TemplateMidSttTicketStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToTemplateMidSttTicket(NULL,true,&TempOut)<0){
					WriteProcMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前输出数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToTemplateMidSttTicket(ptCur,false,&TempOut)<0){
				WriteProcMsg("写表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			free(ptCur);
		}
	}
	if(EInsertStructToTemplateMidSttTicket(NULL,true,&TempOut)<0){
		WriteProcMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcMsg("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);
	
	return 0;
}
int DealSTTProcMain(char sPart[],char sTableNameIn[],char sTableNameOut[])
{
	int iGroupID=0;
	BINTREE *pRoot=NULL;
	while(iGroupID<100){
		/*从详单表中加载数据*/	
		if(LoadTabletoBintree(iGroupID,sPart,sTableNameIn,&pRoot)<0) return -1;
		
		TravelBin(pRoot,append_bintree_to_list_mid_stt);
		/*数据入库到中间统计表*/			
		if(EInsertList2TableStt(sTableNameOut,gMidSttList)<0) return -1;
		
		DestroyBin(pRoot);
		pRoot=NULL;
		gMidSttList=NULL;
		iGroupID++;
	}
	return 0;
}
int DealMsgProcMain(char sTableNameIn[],char sTableNameOut[])
{
	
	return 0;
}
int main(int argc,char **argv)
{
	
	char sNetWork[4],sCarrID[4];
	char sMonth[3],sPart[9];
	char sTableNameIn[31],sTableNameOut[31];

	/*检查参数*/	
	if(CheckParam(argc,argv)<0) return -1;
	
	strcpy(sPart,argv[1]);
	strncpy(sMonth,sPart+4,2);sMonth[2]=0;
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
		
	WriteProcMsg("中间统计程序开始执行...");
	if(argc==3){
		/*短信、彩信 表待定*/
		DealMsgProcMain(sTableNameIn,sTableNameOut);
	}
	else{
		strcpy(sNetWork,argv[3]);
		strcpy(sCarrID,argv[4]);
		
		sprintf(sTableNameIn,"T_%s_UE_%s_%s",sNetWork,sCarrID,sMonth);
		sprintf(sTableNameOut,"ST_%s_M_TICKET_%s_%s",sNetWork,sCarrID,sMonth);
		strcpy(gsCarrID,sCarrID);
		strcpy(gsNetWork,sNetWork);
		Upper(gsCarrID);
		Upper(gsNetWork);
		DealSTTProcMain(sPart,sTableNameIn,sTableNameOut);
		WriteProcMsg("从详单表 %s 统计到中间表 %s 完成.",sTableNameIn,sTableNameOut);
	}
	

	DisconnectDatabase();	
	WriteProcMsg("中间统计程序执行完成.");
	return 0;
}
