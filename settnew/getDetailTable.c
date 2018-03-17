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

#include "../include/gen_supp.h"
#include "settle_supp.h"
#include "ticket_field.h"

struct TemplateSttTicketStruct *gSettStatList=NULL;

int arrySTT[]={18,10,14,14,14,8,30,30,30,30,8,8,20,20,4,18,4,20,8,10,10,
		30,30,10,10,18,8,8,18,18,8,18,60,18,3,8,18,8,30,30,30,
		8,1,8,5,12,8,18,4,1,9,9,30,18,18,18,20,18,18,15,15,18,18,
		15,15,18,18,18,18,1,30,50,10,20,8,30,30,4,30,10,30,10,20,
		20,4,10,18,20,20,4,10,18,20,20,20,20,20,20,20,20,20,30,10};
int arrySMS[]={18,10,14,14,14,8,30,30,30,30,8,8,20,20,4,18,4,20,8,10,10,
		30,30,10,10,18,8,8,18,18,8,18,60,18,3,8,18,8,30,30,30,
		8,1,8,5,12,8,18,4,1,9,9,30,18,18,18,20,18,18,15,15,18,18,
		15,15,18,18,18,18,1,30,50,10,20,8,30,30,4,30,10,30,10,20,
		20,4,10,18,20,20,4,10,18,20,20,20,20,20,20,20,20,20,30,10};
int arryMMS[]={18,10,14,14,14,8,30,30,30,30,8,8,20,20,4,18,4,20,8,10,10,
		30,30,10,10,18,8,8,18,18,8,18,60,18,3,8,18,8,30,30,30,
		8,1,8,5,12,8,18,4,1,9,9,30,18,18,18,20,18,18,15,15,18,18,
		15,15,18,18,18,18,1,30,50,10,20,8,30,30,4,30,10,30,10,20,
		20,4,10,18,20,20,4,10,18,20,20,20,20,20,20,20,20,20,30,10};

void AnalyzeCarrID(char sTrunkGroup[],char sCarrID[])
{
	strcpy(sCarrID,"0");
	if(strcmp(sTrunkGroup,"9001")==0) strcpy(sCarrID,"4");
	else if(strcmp(sTrunkGroup,"9002")==0) strcpy(sCarrID,"2");
	else if(strcmp(sTrunkGroup,"9003")==0) strcpy(sCarrID,"3");
	else if(strcmp(sTrunkGroup,"9004")==0) strcpy(sCarrID,"5");
	else if(strcmp(sTrunkGroup,"9005")==0) strcpy(sCarrID,"1");
	else if(strcmp(sTrunkGroup,"9007")==0) strcpy(sCarrID,"6");
	
}

int SearchTStReportGroupMemberStructItem(char sProdID[],struct TStReportGroupMemberStruct **pptCur)
{
	static int iFirstFlag=true;
	static struct TStReportGroupMemberStruct *ptHead=NULL;
	struct TStReportGroupMemberStruct *pTemp,*ptLkHead;
	if(iFirstFlag==true){
		if(InitTStReportGroupMember(&ptHead)<0) return -1;
		
		iFirstFlag=false;
	}
	
	ptLkHead=ptHead;
	while(ptLkHead!=NULL){
		pTemp=ptLkHead;
		ptLkHead=ptLkHead->pNext;
		
		if(strcmp(sProdID,pTemp->sMemberValue)==0){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	return NOTFOUND;
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
int SearchNbrTypeFilterCfgStructItem(char sCarrierID[],struct NbrTypeFilterCfgStruct **pptCur)
{
	static int iFirstFlag=true;
	static struct NbrTypeFilterCfgStruct *ptHead=NULL;
	struct NbrTypeFilterCfgStruct *pTemp,*ptLkHead;
	
	if(iFirstFlag==true){
		if(InitNbrTypeFilterCfg(&ptHead)<0) return -1;
		
		iFirstFlag=false;
	}
	
	ptLkHead=ptHead;
	while(ptLkHead!=NULL){
		pTemp=ptLkHead;
		ptLkHead=ptLkHead->pNext;
		
		if(strcmp(sCarrierID,pTemp->sCarrierID)==0){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	return NOTFOUND;
}

void assign_insert_bintree_day_stat(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}
int append_bintree_to_list_day_stat(void **ppData)
{
	struct TemplateSttTicketStruct *pTemp=(struct TemplateSttTicketStruct*)(*ppData);

	pTemp->pLoadNext=gSettStatList;
	gSettStatList=pTemp;

	return 0;
}
struct TemplateSmsMmsTicketStruct *gSettSmsMmsStatList=NULL;
int append_bintree_to_list_day_sms_stat_e(void **ppData)
{
	struct TemplateSmsMmsTicketStruct *pTemp=(struct TemplateSmsMmsTicketStruct*)(*ppData);

	pTemp->pLoadNext=gSettSmsMmsStatList;
	gSettSmsMmsStatList=pTemp;

	return 0;
}	
void AddTrime(char sMark[],char sStr[],int i,char sTemp[])
{
	int iLen=0;
	int iCnt=0;
	int m=0;
	
	iLen=strlen(sStr);
	if(strcmp(sMark,"STT")==0)
		iCnt=arrySTT[i]-iLen;
	else if(strcmp(sMark,"SMS")==0)
		iCnt=arrySMS[i]-iLen;
	else if(strcmp(sMark,"MMS")==0)
		iCnt=arryMMS[i]-iLen;
	else	iCnt=0;
		
	if(iCnt<=0)
		iCnt=0;
	while(m<iCnt){
		strncat(sStr," ",iCnt);
		m++;
	}
	strcpy(sTemp,sStr);
	
}
int GenSettleStr(char sMark[],char sStr[],char sResult[],int i)
{
	int iLen=0; 
	char sTemp[128];
	
	AddTrime(sMark,sStr,i,sTemp);
	iLen=sprintf(sResult,"%s",sTemp);

	return iLen;
}
int EInsertSTTList2Table(char sTableName[],struct TemplateSttTicketStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct TemplateSttTicketStructOut TempOut;
	struct TemplateSttTicketStruct *ptCur=NULL;
	struct TemplateSttTicketStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct TemplateSttTicketStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToTemplateSttTicket(NULL,true,&TempOut)<0){
					WriteProcMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前输出数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToTemplateSttTicket(ptCur,false,&TempOut)<0){
				WriteProcMsg("写表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			free(ptCur);
		}
	}
	if(EInsertStructToTemplateSttTicket(NULL,true,&TempOut)<0){
		WriteProcMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcPrint("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);
	
	return 0;
}

int EInsertSMSMMSList2Table(char sTableName[],struct TemplateSmsMmsTicketStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct TemplateSmsMmsTicketStructOut TempOut;
	struct TemplateSmsMmsTicketStruct *ptCur=NULL;
	struct TemplateSmsMmsTicketStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct TemplateSmsMmsTicketStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToTemplateSmsMmsTicket(NULL,true,&TempOut)<0){
					WriteProcMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前输出数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToTemplateSmsMmsTicket(ptCur,false,&TempOut)<0){
				WriteProcMsg("写表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			free(ptCur);
		}
	}
	if(EInsertStructToTemplateSmsMmsTicket(NULL,true,&TempOut)<0){
		WriteProcMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcPrint("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);
	
	return 0;
}

int GenTicketTypeMapList(char sMark[],struct TicketTypeMapStruct **ppHead)
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
int GetAsBintreeArrayTable(char sMark[],struct TableNameBinTreeStruct asBintreeArray[])
{
/*CT：电信，CTC：电信CDMA，CRC：铁通，CM：移动，OTH：其他*/
	
	int i;
	for(i=0;i<17;i++){
		strcpy(asBintreeArray[i].sTableName,"");
		asBintreeArray[i].ptRoot=NULL;
	}

	if(strcmp(sMark,"STT")==0){
		strcpy(asBintreeArray[0].sTableName,"st_gw_ticket_ct"); 
		strcpy(asBintreeArray[1].sTableName,"st_gw_ticket_cm");
		strcpy(asBintreeArray[2].sTableName,"st_gw_ticket_crc");
		strcpy(asBintreeArray[3].sTableName,"st_gw_ticket_oth");
		strcpy(asBintreeArray[4].sTableName,"st_yd_ticket_ct");
		strcpy(asBintreeArray[5].sTableName,"st_yd_ticket_cm");
		strcpy(asBintreeArray[6].sTableName,"st_yd_ticket_crc");
		strcpy(asBintreeArray[7].sTableName,"st_yd_ticket_oth");
		strcpy(asBintreeArray[8].sTableName,"st_oth_ticket_oth");
		strcpy(asBintreeArray[9].sTableName,"st_yd_ticket_cnc");
		strcpy(asBintreeArray[10].sTableName,"st_gw_ticket_ctc");
		strcpy(asBintreeArray[11].sTableName,"st_yd_ticket_ctc");
		
		/*IP*/
		strcpy(asBintreeArray[12].sTableName,"st_ip_ticket");
		/*短号*/
		strcpy(asBintreeArray[13].sTableName,"st_short_nbr_ticket");
		/*就近、转接*/
		strcpy(asBintreeArray[14].sTableName,"st_near_tran_ticket");
		/*异常 单条超短*/
		strcpy(asBintreeArray[15].sTableName,"st_unnormal_cd_ticket");
		/*异常 单条超长*/
		strcpy(asBintreeArray[16].sTableName,"st_unnormal_dcc_ticket");
	}
	else if(strcmp(sMark,"SMS")==0){
		strcpy(asBintreeArray[0].sTableName,"ST_SMS_TICKET");
	}
	asBintreeArray[0].ptRoot=NULL;
	asBintreeArray[1].ptRoot=NULL;
	asBintreeArray[2].ptRoot=NULL;
	asBintreeArray[3].ptRoot=NULL;
	asBintreeArray[4].ptRoot=NULL;
	asBintreeArray[5].ptRoot=NULL;
	asBintreeArray[6].ptRoot=NULL;
	asBintreeArray[7].ptRoot=NULL;
	asBintreeArray[8].ptRoot=NULL;
	asBintreeArray[9].ptRoot=NULL;
	asBintreeArray[10].ptRoot=NULL;
	asBintreeArray[11].ptRoot=NULL;
	asBintreeArray[12].ptRoot=NULL;
	asBintreeArray[13].ptRoot=NULL;
	asBintreeArray[14].ptRoot=NULL;
	asBintreeArray[15].ptRoot=NULL;
	asBintreeArray[16].ptRoot=NULL;
	
	return 0;
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

int GenSTTTicketStruct(struct FTTemplateYdGwUeStruct *pi,struct TemplateSttTicketStruct *po,
	struct TicketTypeMapStruct *pTicketType)
{
	char sTemp[128],sAreaCode[5];
	struct NbrTypeFilterCfgStruct *pMyNbrTypeCfg=NULL,*pOppNbrTypeCfg=NULL;
	struct TicketTypeMapStruct *pTicketTypeMap=NULL;
	int iLen=0;
	
	bzero((void*)po,sizeof(struct TemplateSttTicketStruct));
/*SETT_LATN_ID*/
		strncpy(sTemp,			pi->sCityID,8);sTemp[8]=0;
		AllTrim(sTemp);
		strcpy(sAreaCode,sTemp);
		strcpy(po->sGroupID,"00");
		if(strncmp(sTemp,"591",3)==0)		strcpy(po->sSettLatnID,"A");
		else if(strncmp(sTemp,"592",3)==0)	strcpy(po->sSettLatnID,"B");
		else if(strncmp(sTemp,"593",3)==0)	strcpy(po->sSettLatnID,"E");
		else if(strncmp(sTemp,"594",3)==0)	strcpy(po->sSettLatnID,"F");
		else if(strncmp(sTemp,"595",3)==0)	strcpy(po->sSettLatnID,"C");
		else if(strncmp(sTemp,"596",3)==0)	strcpy(po->sSettLatnID,"D");
		else if(strncmp(sTemp,"597",3)==0)	strcpy(po->sSettLatnID,"I");
		else if(strncmp(sTemp,"598",3)==0)	strcpy(po->sSettLatnID,"H");
		else if(strncmp(sTemp,"599",3)==0)	strcpy(po->sSettLatnID,"G");
/*PROD_ID*/
		strncpy(po->sProdID,			pi->sProdID,10);		
/*START_TIME*/
		strncpy(po->sStartTime,			pi->sStartTime,14);
		po->sStartTime[14]=0;AllTrim(po->sStartTime);
/*DURATION*/
		strncpy(sTemp,			pi->sDuration,18);sTemp[18]=0;
		AllTrim(sTemp);
		po->iDuration=atoi(sTemp);
		
/*SETT_FEE*/
		strncpy(sTemp,		pi->sTotalDueAmount,18);sTemp[18]=0;
		AllTrim(sTemp);
		po->iSettFee=atoi(sTemp);
/*TRUNK_IN*/
		strncpy(sTemp,			pi->sInTrunkNumber,20);sTemp[20]=0;
		AllTrim(sTemp);
		strncpy(po->sTrunkOut,sTemp+5,6);po->sTrunkOut[6]=0;AllTrim(po->sTrunkOut);
/*TRUNK_OUT*/
		strncpy(sTemp,			pi->sOutTrunkNumber,20);sTemp[20]=0;
		AllTrim(sTemp);
		strncpy(po->sTrunkOut,sTemp+5,6);po->sTrunkOut[6]=0;AllTrim(po->sTrunkOut);
/*FILE_NAME*/	
		strncpy(po->sFileName,			pi->sFileName,60);
		po->sFileName[60]=0;AllTrim(po->sFileName);
		
		if(SearchTicketTypeMapStructItem(po->sProdID,&pTicketTypeMap)==NOTFOUND) return 0;
		
/*REPORT_ITEM_ID*/
		po->iReportItemID=pTicketTypeMap->iReportItemID;
/*CALL_TYPE*/
		strcpy(po->sCallType,pTicketTypeMap->sCallType);
/*HOME_AREA_CODE*/
/*MSISDN*/
/*OPP_AREA_CODE*/
/*OTHER_PARTY*/
/*MY_CARR_ID*/
/*OPP_CARR_ID*/
		if(strcmp(pTicketTypeMap->sCallType,"1")==0){
			strncpy(po->sHomeAreaCode,pi->sCallingAreaCode,5);
				po->sHomeAreaCode[5]=0;AllTrim(po->sHomeAreaCode);
			strncpy(po->sMsisdn,pi->sCallingNumber,15);
				po->sMsisdn[15]=0;AllTrim(po->sMsisdn);
			strncpy(po->sOppAreaCode,pi->sCalledAreaCode,5);
				po->sOppAreaCode[5]=0;AllTrim(po->sOppAreaCode);
			strncpy(po->sOtherParty,pi->sCalledNumber,15);
				po->sOtherParty[15]=0;AllTrim(po->sOtherParty);
			strncpy(po->sMyCarrID,pi->sInTrunkGroup+3,1);po->sMyCarrID[1]=0;
			strncpy(po->sOppCarrID,pi->sOutTrunkGroup+3,1);po->sOppCarrID[1]=0;
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
			strncpy(po->sMyCarrID,pi->sOutTrunkGroup+3,1);po->sMyCarrID[1]=0;
			strncpy(po->sOppCarrID,pi->sInTrunkGroup+3,1);po->sOppCarrID[1]=0;
		}
		
		iLen=strlen(po->sMsisdn);
		
		if(iLen==0) strcpy(po->sGroupID,"00");
		else if(iLen<=2) strcpy(po->sGroupID,po->sMsisdn);
		else	strncpy(po->sGroupID,po->sMsisdn+iLen-2,2);po->sGroupID[2]=0;
		
		if(SearchNbrTypeFilterCfgStructItem(po->sMyCarrID,&pMyNbrTypeCfg)==NOTFOUND) return 0;
		if(SearchNbrTypeFilterCfgStructItem(po->sOppCarrID,&pOppNbrTypeCfg)==NOTFOUND) return 0;
/*MY_DISTANCE_TYPE*/
/*OPP_DISTANCE_TYPE*/		
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
/*MY_NBR_TYPE*/
		strcpy(po->sMyNbrType,pMyNbrTypeCfg->sNbrType);
/*OPP_NBR_TYPE*/
		strcpy(po->sOppNbrType,pOppNbrTypeCfg->sNbrType);
/*MY_3G_FLAG*/
		
/*OPP_3G_FLAG*/
		
		SetSettNbrType(po->sMsisdn,po->sHomeAreaCode,
			po->sStartTime,po->sMyNbrType,po->sMy3gFlag);
		SetSettNbrType(po->sOtherParty,po->sOppAreaCode,
			po->sStartTime,po->sOppNbrType,po->sOpp3gFlag);
		
/*MSC*/		
		strncpy(po->sMsc,pi->sInTrunkNumber,5);po->sMsc[5]=0;
/*TRUNK_IN_CARR_ID*/
		strcpy(po->sTrunkInCarrID,pTicketTypeMap->sInTrunkCarrID);
/*TRUNK_OUT_CARR_ID*/
		strcpy(po->sTrunkOutCarrID,pTicketTypeMap->sOutTrunkCarrID);

/*SERV_FLAG*/
		strcpy(po->sServFlag,"1");
		
		AllTrim(po->sSettLatnID);
		AllTrim(po->sProdID);
		AllTrim(po->sCallType);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOppAreaCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sMyDistanceType);
		AllTrim(po->sOppDistanceType);
		AllTrim(po->sMyNbrType);
		AllTrim(po->sOppNbrType);
		AllTrim(po->sMy3gFlag);
		AllTrim(po->sStartTime);
		AllTrim(po->sOpp3gFlag);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sTrunkInCarrID);
		AllTrim(po->sTrunkOutCarrID);
		AllTrim(po->sMyCarrID);
		AllTrim(po->sOppCarrID);
		AllTrim(po->sServFlag);
		AllTrim(po->sFileName);
		AllTrim(po->sGroupID);
		
		return 0;
}

int GenSMSTicketStruct(char sStr[],struct TemplateSmsMmsTicketStruct *po,
	struct TicketTypeMapStruct *pTicketType)
{
	struct TicketTypeMapStruct *pTicketTypeMap=NULL;
	int iLen=0,iReportItemID=0;
	char sCityID[10],sProID[11],sCallingAreaCode[8],sCalledAreaCode[8];
	char sCallingNumber[25],sCalledNumber[25],sInTrunkGroup[16],sOutTrunkGroup[16];
	char sStartTime[15],sCallingGroupID[16],sCalledGroupID[16],sTotalDueAmount[19];
	char sFileName[128],sCallingCompanyID[10],sCalledCompanyID[10];
	char sCallType[2];
	
	bzero((void*)po,sizeof(struct TemplateSmsMmsTicketStruct));
	
	GetSepStr(sStr,',',21,sCityID);AllTrim(sCityID);
	GetSepStr(sStr,',',1,sProID);AllTrim(sProID);
	GetSepStr(sStr,',',3,sStartTime);AllTrim(sStartTime);
	GetSepStr(sStr,',',5,sCallingNumber);AllTrim(sCallingNumber);
	GetSepStr(sStr,',',6,sCalledNumber);AllTrim(sCalledNumber);
	GetSepStr(sStr,',',10,sCallingAreaCode);AllTrim(sCallingAreaCode);
	GetSepStr(sStr,',',11,sCalledAreaCode);AllTrim(sCalledAreaCode);
	GetSepStr(sStr,',',39,sTotalDueAmount);AllTrim(sTotalDueAmount);
	GetSepStr(sStr,',',48,sFileName);AllTrim(sFileName);
	GetSepStr(sStr,',',55,sCallingGroupID);AllTrim(sCallingGroupID);
	GetSepStr(sStr,',',56,sCalledGroupID);AllTrim(sCalledGroupID);
	GetSepStr(sStr,',',57,sCallingCompanyID);AllTrim(sCallingCompanyID);
	GetSepStr(sStr,',',58,sCalledCompanyID);AllTrim(sCalledCompanyID);
	
	if(strcmp(sCallingCompanyID,"9003")==0)
		strcpy(sCallType,"7");
	else	strcpy(sCallType,"8");
	
/*SETT_LATN_ID*/
	strcpy(po->sGroupID,"00");
	if(strncmp(sCityID,"591",3)==0)		strcpy(po->sSettLatnID,"A");
	else if(strncmp(sCityID,"592",3)==0)	strcpy(po->sSettLatnID,"B");
	else if(strncmp(sCityID,"593",3)==0)	strcpy(po->sSettLatnID,"E");
	else if(strncmp(sCityID,"594",3)==0)	strcpy(po->sSettLatnID,"F");
	else if(strncmp(sCityID,"595",3)==0)	strcpy(po->sSettLatnID,"C");
	else if(strncmp(sCityID,"596",3)==0)	strcpy(po->sSettLatnID,"D");
	else if(strncmp(sCityID,"597",3)==0)	strcpy(po->sSettLatnID,"I");
	else if(strncmp(sCityID,"598",3)==0)	strcpy(po->sSettLatnID,"H");
	else if(strncmp(sCityID,"599",3)==0)	strcpy(po->sSettLatnID,"G");
/*PROD_ID*/
	strcpy(po->sProdID,sProID);	
/*START_TIME*/
	strcpy(po->sStartTime,sStartTime);
/*SETT_FEE*/
	po->iSettFee=atoi(sTotalDueAmount);
/*FILE_NAME*/	
	strcpy(po->sFileName,sFileName);
		
/*REPORT_ITEM_ID*/
	if(strcmp(sCallingCompanyID,"9003")==0){
		if(strcmp(sCalledCompanyID,"9002")==0) iReportItemID=1612206;
		else if(strcmp(sCalledCompanyID,"9003")==0) iReportItemID=0;
		else if(strcmp(sCalledCompanyID,"9005")==0) iReportItemID=1612201;
		else if(strcmp(sCalledCompanyID,"9007")==0) iReportItemID=1612203;
	}
	else{
		if(strcmp(sCallingCompanyID,"9002")==0) iReportItemID=1612205;
		else if(strcmp(sCallingCompanyID,"9003")==0) iReportItemID=0;
		else if(strcmp(sCallingCompanyID,"9005")==0) iReportItemID=1612202;
		else if(strcmp(sCallingCompanyID,"9007")==0) iReportItemID=1612204;
	}
	po->iReportItemID=iReportItemID;
/*CALL_TYPE*/
	strcpy(po->sCallType,sCallType);
/*HOME_AREA_CODE*/
/*MSISDN*/
/*OPP_AREA_CODE*/
/*OTHER_PARTY*/
/*MY_CARR_ID*/
/*OPP_CARR_ID*/
	AnalyzeCarrID(sCallingCompanyID,po->sMyCarrID);
	AnalyzeCarrID(sCalledCompanyID,po->sOppCarrID);
	if(strcmp(sCallType,"7")==0){
		strncpy(po->sHomeAreaCode,sCallingAreaCode,5);
			po->sHomeAreaCode[5]=0;AllTrim(po->sHomeAreaCode);
		strncpy(po->sMsisdn,sCallingNumber,15);
			po->sMsisdn[15]=0;AllTrim(po->sMsisdn);
		strncpy(po->sOppAreaCode,sCalledAreaCode,5);
			po->sOppAreaCode[5]=0;AllTrim(po->sOppAreaCode);
		strncpy(po->sOtherParty,sCalledNumber,15);
			po->sOtherParty[15]=0;AllTrim(po->sOtherParty);
/*			
		strncpy(po->sMyCarrID,pi->sInTrunkGroup+3,1);po->sMyCarrID[1]=0;
		strncpy(po->sOppCarrID,pi->sOutTrunkGroup+3,1);po->sOppCarrID[1]=0;*/
	}
	else{
		strncpy(po->sHomeAreaCode,sCalledAreaCode,5);
			po->sHomeAreaCode[5]=0;AllTrim(po->sHomeAreaCode);
		strncpy(po->sMsisdn,sCalledNumber,15);
			po->sMsisdn[15]=0;AllTrim(po->sMsisdn);
		strncpy(po->sOppAreaCode,sCallingAreaCode,5);
			po->sOppAreaCode[5]=0;AllTrim(po->sOppAreaCode);
		strncpy(po->sOtherParty,sCallingNumber,15);
			po->sOtherParty[15]=0;AllTrim(po->sOtherParty);
/*			
		strncpy(po->sMyCarrID,pi->sOutTrunkGroup+3,1);po->sMyCarrID[1]=0;
		strncpy(po->sOppCarrID,pi->sInTrunkGroup+3,1);po->sOppCarrID[1]=0;*/
	}
		
	iLen=strlen(po->sMsisdn);
	
	if(iLen==0) strcpy(po->sGroupID,"00");
	else if(iLen<=2) strcpy(po->sGroupID,po->sMsisdn);
	else	strncpy(po->sGroupID,po->sMsisdn+iLen-2,2);po->sGroupID[2]=0;
/*		
		if(SearchNbrTypeFilterCfgStructItem(po->sMyCarrID,&pMyNbrTypeCfg)==NOTFOUND) return 0;
		if(SearchNbrTypeFilterCfgStructItem(po->sOppCarrID,&pOppNbrTypeCfg)==NOTFOUND) return 0;*/
/*MY_3G_FLAG*/
/*OPP_3G_FLAG*/
		
	SetSettNbrType(po->sMsisdn,po->sHomeAreaCode,
		po->sStartTime,po->sMyNbrType,po->sMy3gFlag);
	SetSettNbrType(po->sOtherParty,po->sOppAreaCode,
		po->sStartTime,po->sOppNbrType,po->sOpp3gFlag);

/*SERV_FLAG*/
	strcpy(po->sServFlag,"1");
	
	AllTrim(po->sSettLatnID);
	AllTrim(po->sProdID);
	AllTrim(po->sCallType);
	AllTrim(po->sHomeAreaCode);
	AllTrim(po->sMsisdn);
	AllTrim(po->sOppAreaCode);
	AllTrim(po->sOtherParty);
	AllTrim(po->sStartTime);
	AllTrim(po->sMy3gFlag);
	AllTrim(po->sOpp3gFlag);
	AllTrim(po->sMyCarrID);
	AllTrim(po->sOppCarrID);
	AllTrim(po->sServFlag);
	AllTrim(po->sFileName);
	AllTrim(po->sGroupID);
	
	return 0;
}
int data_search_day_stat(void *pValue,void *pData)
{
	int iResult=0;
	struct TemplateSttTicketStruct *pSource=(struct TemplateSttTicketStruct*)pValue;
	struct TemplateSttTicketStruct *pTarget=(struct TemplateSttTicketStruct*)pData;

	if((iResult=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return iResult;		

	return 0;

}
int InsertBinTree(char sStr[],struct TemplateSttTicketStruct *p,
	struct TableNameBinTreeStruct asBintreeArray[])
{	
	struct TTemplateYdGwUeStruct Temp;
	struct FTTemplateYdGwUeStruct *pFp;
	char sInNetWork[3],sOutNetWork[3];
	char sInOperators[3],sOutOperators[3];
	char sProdId[3];
	struct TicketTypeMapStruct *pTicketTypeMap=NULL;
	
	bzero((void*)&Temp,sizeof(struct TTemplateYdGwUeStruct));
	
	mvitem_fmttemplateydgwue((struct FTTemplateYdGwUeStruct*)sStr,&Temp);
	
	if(ChkTime(Temp.sStartTime)<0
		&& ChkTime(Temp.sEndTime)<0
		&& ChkTime(Temp.sRateTime)<0){
			return -1;
	}
	
	strncpy(sInNetWork,Temp.sInTrunkGroup+1,1);
	sInNetWork[1]=0;
	strncpy(sInOperators,Temp.sInTrunkGroup+3,1);
	sInOperators[1]=0;
	strncpy(sOutNetWork,Temp.sOutTrunkGroup+1,1);
	sOutNetWork[1]=0;
	strncpy(sOutOperators,Temp.sOutTrunkGroup+3,1);
	sOutOperators[1]=0;
	strncpy(sProdId,Temp.sProdID,3);
	sProdId[3]=0;	
	
	if(SearchTicketTypeMapStructItem(Temp.sProdID,&pTicketTypeMap)==NOTFOUND){
		
		/*T_OTH_UE_OTH_10 */
		if(InsertBin(&(asBintreeArray[8].ptRoot),p,data_search_day_stat,
			assign_insert_bintree_day_stat)<0){
			WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
			return -1;
		}
		return 0;
	}
	
/*	if((strcmp(sInOperators,"3")==0 && strcmp(sOutOperators,"3")==0)) return 0;	*/

	/*1--移网，0--固网*/
	/*5--电信，1--网通，2--移动，3--联通，4--铁通*/
	if(strcmp(sInNetWork,"0")==0 && strcmp(sOutNetWork,"0")==0){
		if (strcmp(sProdId,"PWJ")==0){
			if((strcmp(sInOperators,"1")==0 && strcmp(sOutOperators,"5")==0)
				|| (strcmp(sInOperators,"5")==0 && strcmp(sOutOperators,"1")==0)){
			
				if(strncmp(Temp.sCallingGroupID,"C007",4)==0
					|| strncmp(Temp.sCallingGroupID,"C207",4)==0
					|| strncmp(Temp.sCalledGroupID,"C007",4)==0
					|| strncmp(Temp.sCalledGroupID,"C207",4)==0){
						
					/*T_GW_UE_CTC_10*/
					if(InsertBin(&(asBintreeArray[10].ptRoot),p,data_search_day_stat,
						assign_insert_bintree_day_stat)<0){
						WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
						return -1;
					}
				}
			
				else{
					/*T_GW_UE_CT_10*/
					if(InsertBin(&(asBintreeArray[0].ptRoot),p,data_search_day_stat,
						assign_insert_bintree_day_stat)<0){
						WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
						return -1;
					}
				}
			}
		
			else if((strcmp(sInOperators,"1")==0 && strcmp(sOutOperators,"2")==0)
				|| (strcmp(sInOperators,"2")==0 && strcmp(sOutOperators,"1")==0)){
					
				/*T_GW_UE_CM_10*/
				if(InsertBin(&(asBintreeArray[1].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
		
			else if((strcmp(sInOperators,"1")==0 && strcmp(sOutOperators,"4")==0)
				|| (strcmp(sInOperators,"4")==0 && strcmp(sOutOperators,"1")==0)){
					
				/*T_GW_UE_CRC_10*/
				if(InsertBin(&(asBintreeArray[2].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
		
			else{
				/*T_GW_UE_OTH_10 */
				if(InsertBin(&(asBintreeArray[3].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
		
		}
		else{
			/*T_GW_UE_OTH_10 */
			if(InsertBin(&(asBintreeArray[3].ptRoot),p,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
				return -1;
			}
		}
	}
	else if(strcmp(sInNetWork,"1")==0 && strcmp(sOutNetWork,"1")==0){
		if (strcmp(sProdId,"PWJ")==0){		
			if((strcmp(sInOperators,"3")==0 && strcmp(sOutOperators,"5")==0)
				|| (strcmp(sInOperators,"5")==0 && strcmp(sOutOperators,"3")==0)){
				/*T_YD_UE_CT_10*/
				if(InsertBin(&(asBintreeArray[4].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
			else if((strcmp(sInOperators,"3")==0 && strcmp(sOutOperators,"7")==0)
				|| (strcmp(sInOperators,"7")==0 && strcmp(sOutOperators,"3")==0)){
					
				/*T_YD_UE_CTC_10*/
				if(InsertBin(&(asBintreeArray[11].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
			else if((strcmp(sInOperators,"3")==0 && strcmp(sOutOperators,"2")==0)
				|| (strcmp(sInOperators,"2")==0 && strcmp(sOutOperators,"3")==0)){
					
				/*T_YD_UE_CM_10*/
				if(InsertBin(&(asBintreeArray[5].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
		
			else if((strcmp(sInOperators,"3")==0 && strcmp(sOutOperators,"4")==0)
				|| (strcmp(sInOperators,"4")==0 && strcmp(sOutOperators,"3")==0)){
					
				/*T_YD_UE_CRC_10*/
				if(InsertBin(&(asBintreeArray[6].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
	
			else{
				/*T_YD_UE_OTH_10*/
				if(InsertBin(&(asBintreeArray[7].ptRoot),p,data_search_day_stat,
					assign_insert_bintree_day_stat)<0){
					WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
					return -1;
				}
			}
		}
		else if(strcmp(sProdId,"PZY")==0){
				
			/*T_YD_UE_CNC_10*/
			if(InsertBin(&(asBintreeArray[9].ptRoot),p,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
				return -1;
			}
		}
		else{
			/*T_YD_UE_OTH_10*/
			if(InsertBin(&(asBintreeArray[7].ptRoot),p,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
				return -1;
			}
		}
	}
	else if(strcmp(sProdId,"PZY")==0){
				
		/*T_YD_UE_CNC_10*/
		if(InsertBin(&(asBintreeArray[9].ptRoot),p,data_search_day_stat,
			assign_insert_bintree_day_stat)<0){
			WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
			return -1;
		}
	}
	else if(strcmp(sInNetWork,sOutNetWork)!=0){
		/*T_OTH_UE_OTH_10 */
		if(InsertBin(&(asBintreeArray[8].ptRoot),p,data_search_day_stat,
			assign_insert_bintree_day_stat)<0){
			WriteProcMsg("生成二叉树 struct TemplateSttTicketStruct 失败.");
			return -1;
		}
	}
	
	return 0;
}

int GenerationBinTreeSTT(char sStr[],struct TicketTypeMapStruct *pTicketType,
	struct TableNameBinTreeStruct asBintreeArray[])
{	
	static int iLen=sizeof(struct TemplateSttTicketStruct);

	struct TemplateSttTicketStruct *pTemp;
	struct FTTemplateYdGwUeStruct *pFp;
	char sInNetWork[3],sOutNetWork[3];
	char sInOperators[3],sOutOperators[3];
	char sProdId[3];
	
	if((pTemp=(struct TemplateSttTicketStruct*)malloc(iLen))==NULL){
		WriteProcMsg("malloc struct TTemplateYdGwUeStruct 失败!!!");
		return -1;
	}
	
	bzero((void*)pTemp,sizeof(struct TemplateSttTicketStruct));
	
	GenSTTTicketStruct((struct FTTemplateYdGwUeStruct*)sStr,pTemp,pTicketType);
	
	if(InsertBinTree(sStr,pTemp,asBintreeArray)<0) return -1;

	return 0;
}

int data_search_day_sms_stat_e(void *pValue,void *pData)
{
	int iResult=0;
	struct TemplateSmsMmsTicketStruct *pSource=(struct TemplateSmsMmsTicketStruct*)pValue;
	struct TemplateSmsMmsTicketStruct *pTarget=(struct TemplateSmsMmsTicketStruct*)pData;

	if((iResult=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return iResult;		

	return 0;

}

int GenerationBinTreeSMS(char sStr[],struct TicketTypeMapStruct *pTicketType,
	BINTREE **pptRoot)
{	
	static int iLen=sizeof(struct TemplateSttTicketStruct);

	struct TemplateSmsMmsTicketStruct *pTemp;
	char sInNetWork[3],sOutNetWork[3];
	char sInOperators[3],sOutOperators[3];
	char sProdId[3];
	
	if((pTemp=(struct TemplateSmsMmsTicketStruct*)malloc(iLen))==NULL){
		WriteProcMsg("malloc struct TemplateSmsMmsTicketStruct 失败!!!");
		return -1;
	}
	
	bzero((void*)pTemp,sizeof(struct TemplateSmsMmsTicketStruct));
	
	GenSMSTicketStruct(sStr,pTemp,pTicketType);
	
	if(InsertBin(pptRoot,pTemp,data_search_day_sms_stat_e,
		assign_insert_bintree)<0){
		WriteAlertMsg("生成树 struct TemplateSmsMmsTicketStruct 失败.");
		return -1;
	}

	return 0;
}
int GenerationBinTreeMMS(char sStr[],struct TicketTypeMapStruct *pTicketType,
	struct TableNameBinTreeStruct asBintreeArray[])
{	
	static int iLen=sizeof(struct TemplateSttTicketStruct);

	struct TemplateSttTicketStruct *pTemp;
	struct FTTemplateYdGwUeStruct *pFp;
	char sInNetWork[3],sOutNetWork[3];
	char sInOperators[3],sOutOperators[3];
	char sProdId[3];
	
	if((pTemp=(struct TemplateSttTicketStruct*)malloc(iLen))==NULL){
		WriteProcMsg("malloc struct TTemplateYdGwUeStruct 失败!!!");
		return -1;
	}
	
	bzero((void*)pTemp,sizeof(struct TemplateSttTicketStruct));
	
	GenSTTTicketStruct((struct FTTemplateYdGwUeStruct*)sStr,pTemp,pTicketType);
	
	if(InsertBinTree(sStr,pTemp,asBintreeArray)<0) return -1;

	return 0;
}
int SettleMentYD(char str[],struct TicketTypeMapStruct *pTicketType,
	struct TableNameBinTreeStruct asBintreeArray[])
{
	
	int i=0;
	int iOffset=0;
	int iLen=0;
	char *p;
	char Temp[4096],sTemp[4096];
	char delims=44;
	
	p=str;
	while(*p!='\0'){
		if(*p==','){
			iLen++;
		}
		p++;
	}
	while(i<iLen){
		GetSepStr(str,',',i,Temp);
		iOffset+=GenSettleStr("STT",Temp,sTemp+iOffset,i);
		i++;
	}
	
	if(GenerationBinTreeSTT(sTemp,pTicketType,asBintreeArray)<0){
		printf("%s\n",sTemp);
		return -1;
	}
	
	return 0;
}
int SettleMentSMS(char sStr[],struct TicketTypeMapStruct *pTicketType,
	BINTREE **pptRoot)
{
	
	if(GenerationBinTreeSMS(sStr,pTicketType,pptRoot)<0){
		return -1;
	}
	
	return 0;
}
int SettleMentMMS(char str[],struct TicketTypeMapStruct *pTicketType,
	struct TableNameBinTreeStruct asBintreeArray[])
{
	
	int i=0;
	int iOffset=0;
	int iLen=0;
	char *p;
	char Temp[4096],sTemp[4096];
	char delims=44;
	
	p=str;
	while(*p!='\0'){
		if(*p==','){
			iLen++;
		}
		p++;
	}
	while(i<iLen){
		GetSepStr(str,',',i,Temp);
		iOffset+=GenSettleStr("MMS",Temp,sTemp+iOffset,i);
		i++;
	}
	
	if(GenerationBinTreeMMS(sTemp,pTicketType,asBintreeArray)<0){
		printf("%s\n",sTemp);
		return -1;
	}
	
	return 0;
}
int TravelFileList(struct FileControlStruct *ptHead,char sMark[],
	struct TicketTypeMapStruct *pTicketType,struct TableNameBinTreeStruct asBintreeArray[])
{
	char sStr[2048];
	struct FileControlStruct *pTemp;
	int iLen;
	int iCnt=0;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		memcpy(sStr,pTemp->pData,pTemp->iLen);
		sStr[pTemp->iLen]=0;
		
		iCnt+=strlen(sStr);
		if(strcmp(sMark,"STT")==0){
			if(SettleMentYD(sStr,pTicketType,asBintreeArray)<0) return -1;
		}
		else if(strcmp(sMark,"SMS")==0){
			if(SettleMentSMS(sStr,pTicketType,&(asBintreeArray[0].ptRoot))<0) return -1;
		}
		else if(strcmp(sMark,"MMS")==0){
			if(SettleMentMMS(sStr,pTicketType,asBintreeArray)<0) return -1;
		}
		
		strcpy(sStr,"");
	}
	
	return iCnt;
}

int MyChkDir(char sPath[])
{
	if(strcmp(sPath,"/nil/")==0) return -1;
	return CheckDir(sPath);
}
int FreeMemList(struct TemplateSttTicketStruct *ptHead)
{
	int iCnt=0;
	struct TemplateSttTicketStruct *pTemp=NULL,*ptLkHead;
	
	while(ptHead!=NULL){
		ptLkHead=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLkHead!=NULL){
			pTemp=ptLkHead;
			ptLkHead=ptLkHead->pNext;
			
			free(pTemp);	
			iCnt++;
		}
	}
	ptHead=NULL;
	
	return iCnt;
}
int FreeSmsMmsMemList(struct TemplateSmsMmsTicketStruct *ptHead)
{
	int iCnt=0;
	struct TemplateSmsMmsTicketStruct *pTemp=NULL,*ptLkHead;
	
	while(ptHead!=NULL){
		ptLkHead=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLkHead!=NULL){
			pTemp=ptLkHead;
			ptLkHead=ptLkHead->pNext;
			
			free(pTemp);	
			iCnt++;
		}
	}
	ptHead=NULL;
	
	return iCnt;
}
/*删除详单表的数据*/
void DeleteTableData(char sTableName[],char sFileName[])
{
	char statement[1024];
	
	sprintf(statement,"DELETE FROM %s WHERE FILE_NAME='%s'",sTableName,sFileName);
	if(ExecSql(statement)<0){
		WriteAlertMsg("执行%s失败",statement);
		exit (-1);
	}
	CommitWork();
}
/*更新日志的成功标识*/
void UpdateTableData(char sTableName[],char sFileName[])
{
	char statement[1024];
	
	sprintf(statement,"UPDATE %s SET STATE='T' WHERE FILE_NAME='%s'",sTableName,sFileName);
	if(ExecSql(statement)<0){
		WriteAlertMsg("执行%s失败",statement);
		exit (-1);
	}
	CommitWork();	
}
/*处理语音*/
int ProcessMainSTT(char sFilter[],char sMark[],char sSourceDir[],char sTargetDir[])
{
	int iSum=0,iM=0,iCnt=0,iTotalCnt=0;
	char sMonth[5],sCondition[1024];
	char sFileName[256],sTempName[256],sHostTime[15];
	char sCommond[2048],sTableName[31];
	
	
	struct TicketTypeMapStruct *pTicketType;
	struct TableNameBinTreeStruct asBintreeArray[17];
	
	struct FileControlStruct *ptList=NULL;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	struct SettBillStorLogStruct Temp;
	bzero((void*)&Temp,sizeof(struct SettBillStorLogStruct));
/*生成一个文件列表*/
	if(dir2list(sSourceDir,sFilter,&ptHead)<0){
		WriteProcMsg("生成文件列表失败 %s %s",sSourceDir,sFilter);
		return -1;
	}
	if(GenTicketTypeMapList(sMark,&pTicketType)<0) return -1;
		
	GetAsBintreeArrayTable(sMark,asBintreeArray);
	
	ptLkHead=ptHead;

	/*编译入库文件*/
	while( ptHead != NULL ){

		pTemp = ptHead;
		ptHead = ptHead->pNext;

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		
		strncpy(sMonth,sFileName+18,2);
		sMonth[2]=0;
		
		sprintf(sCondition," WHERE FILE_NAME='%s' ",sFileName);
		if(SDGetSettBillStorLogToStruct(&Temp,"GET_DETAIL_TABLE_LOG",sCondition)==true){
			if(strcmp(Temp.sState,"T")==0){
				sprintf(sCommond,"mv %s%s %s%s",sSourceDir,sFileName,sTargetDir,sFileName);
				system(sCommond);
				continue;
			}
			
		}else{
			strcpy(Temp.sFileName,sFileName);
			strncpy(Temp.sFileDate,sFileName+14,8);Temp.sFileDate[8]=0;
			GetHostTime(sHostTime);
			strcpy(Temp.sDealTime,sHostTime);
			strcpy(Temp.sState,"F");
			
			if(SDInsertStructToSettBillStorLog(&Temp,"GET_DETAIL_TABLE_LOG")<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
		}
		
		sprintf(sTempName,"%s%s",sSourceDir,sFileName);
		
		if(TxtFileToList(sTempName,&ptList)<0) return -1;
	
		if(iSum=TravelFileList(ptList,sMark,pTicketType,asBintreeArray)<0){
			listfree(&ptList);
			sprintf(sCommond,"mv %s %s.err",sTempName,sTempName);
			system(sCommond);
			return -1;
		}
		listfree(&ptList);
		while(iM<12){
			
			if(strcmp(asBintreeArray[iM].sTableName,"")==0){
				iM++;
				continue;
			}
			
			sprintf(sTableName,"%s_%s",asBintreeArray[iM].sTableName,sMonth);
			
			gSettStatList=NULL;
			gSettSmsMmsStatList=NULL;				
			
			if(strcmp(sMark,"STT")==0){
				TravelBin(asBintreeArray[iM].ptRoot,append_bintree_to_list_day_stat);
				if(EInsertSTTList2Table(sTableName,gSettStatList)<0) return -1;
			}
			else if(strcmp(sMark,"SMS")==0){
				TravelBin(asBintreeArray[iM].ptRoot,append_bintree_to_list_day_sms_stat_e);
				if(EInsertSMSMMSList2Table(sTableName,gSettSmsMmsStatList)<0) return -1;
			}
			else if(strcmp(sMark,"MMS")==0){
				TravelBin(asBintreeArray[iM].ptRoot,append_bintree_to_list_day_sms_stat_e);
				if(EInsertSMSMMSList2Table(sTableName,gSettSmsMmsStatList)<0) return -1;
			}
			
			DestroyBin(asBintreeArray[iM].ptRoot);
			FreeMemList(gSettStatList);
			FreeSmsMmsMemList(gSettSmsMmsStatList);
			asBintreeArray[iM].ptRoot=NULL;
			
			iM++;
		}
		
		iM=0;
		UpdateTableData("GET_DETAIL_TABLE_LOG",sFileName);
		
		sprintf(sCommond,"rm -r %s%s",sSourceDir,sFileName);
		system(sCommond);

		printNORMAL("对文件%s分解成功",sFileName);
		if((++iTotalCnt)%200==0) break;
	}
	listfree(&ptLkHead);
	
	return 0;
}
/*处理短信彩信*/
int ProcessMainSMSMMS(char sFilter[],char sSourceDir[],char sTargetDir[])
{
	
	return 0;
}
int main(int argc,char *argv[])
{
	int iGroupID,iRet;
	char sSourceDir[81],sTargetDir[81],sDirFileName[1024];
	char sFilter[21],sMark[4];
	
	struct DispParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc != 3){
		WriteProcPrint("Usage: %s *.ini GroupID!!!",argv[0]);
		return -1;
	}

	
	strcpy(sDirFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	
	InitAppRes(argv[0]);
	
	if(ConnectDataDB()<0) return -1;
		
	if(GetDispParamList(sDirFileName,iGroupID,&ptHead)<0) return -1;
	
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*检查参数合法性.*/

		if(IsDir(pTemp->sSourcePath)==FALSE){
			printALERT("输入目录%s无效.",pTemp->sSourcePath);
			continue;
		}

		strcpy(sSourceDir,pTemp->sSourcePath);
		strcpy(sTargetDir,pTemp->sDestPath1);
		strcpy(sFilter,pTemp->sFilter);
		strncpy(sMark,pTemp->sDestPath2,3);
		sMark[3]=0;
		/*处理语音*/
		if(strcmp(sMark,"STT")==0||strcmp(sMark,"SMS")==0 || strcmp(sMark,"MMS")==0){
			iRet=ProcessMainSTT(sFilter,sMark,sSourceDir,sTargetDir);
		}
		/*处理短信彩信*/
		else if(strcmp(sMark,"SMS")==0 || strcmp(sMark,"MMS")==0){
			iRet=ProcessMainSMSMMS(sFilter,sSourceDir,sTargetDir);
		}	
		
		if(iRet<0){
			printALERT("分发文件失败!");
			return -1;
		}
		if(iRet>0) break;
	}		

	DisconnectDatabase();	
	
	return 0;
}
