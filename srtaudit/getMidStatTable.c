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
 
#include "sett_supp.h"
#include "ticket_field.h"

char gsCarrID[4],gsNetWork[4],gsCompCode[32],gsType[10];

struct SettMTicketUeStruct *gMidSttList=NULL;

int data_search_mid_stt(void *pValue,void *pData)
{
	int iResult=0;
	
	struct SettMTicketUeStruct *pSource=(struct SettMTicketUeStruct*)pValue;
	struct SettMTicketUeStruct *pTarget=(struct SettMTicketUeStruct*)pData;

	if((iResult=strcmp(pSource->sProdID,		pTarget->sProdID))!=0) return iResult;
	if((iResult=strcmp(pSource->sCallingNumber,	pTarget->sCallingNumber))!=0) return iResult;
	if((iResult=strcmp(pSource->sCalledNumber,	pTarget->sCalledNumber))!=0) return iResult;
	if((iResult=strcmp(pSource->sCallType,		pTarget->sCallType))!=0) return iResult;

	return iResult;
}

int SearchMidStatItem(BINTREE *ptRoot,struct SettMTicketUeStruct *p,
	struct SettMTicketUeStruct **pptCur)
{
	int iResult=NULL;
	struct SettMTicketUeStruct *ptHead=NULL,*pTemp;
	
	*pptCur=NULL;
	if(SearchBin(ptRoot,p,data_search_mid_stt,(void**)&ptHead)==FOUND){
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			
			if((iResult=pTemp->iReportItemID - 		p->iReportItemID)!=0) continue;
			if((iResult=strcmp(pTemp->sCityID,		p->sCityID))!=0) continue;

			if((iResult=strcmp(pTemp->sCallingCityID,	p->sCallingCityID))!=0) continue;
			if((iResult=strcmp(pTemp->sCallingType,		p->sCallingType))!=0) continue;
			if((iResult=strcmp(pTemp->sCallingCompCode,	p->sCallingCompCode))!=0) continue;
			if((iResult=strcmp(pTemp->sCallingAreaCode,	p->sCallingAreaCode))!=0) continue;
				
			if((iResult=strcmp(pTemp->sCalledCityID,	p->sCalledCityID))!=0) continue;
			if((iResult=strcmp(pTemp->sCalledNumberType,	p->sCalledNumberType))!=0) continue;
			if((iResult=strcmp(pTemp->sCalledCompCode,	p->sCalledCompCode))!=0) continue;
			if((iResult=strcmp(pTemp->sCalledAreaCode,	p->sCalledAreaCode))!=0) continue;

			if((iResult=strcmp(pTemp->sSettDate,		p->sSettDate))!=0) continue;
				
			if((iResult=strcmp(pTemp->sGroupID,		p->sGroupID))!=0) continue;
			if((iResult=strcmp(pTemp->sOtherGroupID,	p->sOtherGroupID))!=0) continue;
				
			if((iResult=strcmp(pTemp->sCallingNbrType,	p->sCallingNbrType))!=0) continue;
			if((iResult=strcmp(pTemp->sCalledNbrType,	p->sCalledNbrType))!=0) continue;
			if((iResult=strcmp(pTemp->sSettDirection,	p->sSettDirection))!=0) continue;
			if((iResult=strcmp(pTemp->sSettCarrID,		p->sSettCarrID))!=0) continue;
			
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
	struct SettMTicketUeStruct *pTemp=(struct SettMTicketUeStruct*)(*ppData);

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
		printf("	语音NetWork说明: 	移动:YD、固网:GW\n");
		printf("	语音CarrID说明: 	电信:CT、电信CDMA:CTC、铁通：CRC、移动：CM\n");
		printf("	注意：短信及彩信后两个参数不使用\n");
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
int SearchRepMidRelStructItem(char sProdID[],char sCode[],struct RptMidRelStruct **pptCur)
{
	static int iFirstFlag=true;
	static struct RptMidRelStruct *ptHead=NULL;
	struct RptMidRelStruct *pTemp,*ptLkHead;

	if(iFirstFlag==true){
		if(InitRptMidRel(&ptHead)<0) return -1;
		
		iFirstFlag=false;
	}

	ptLkHead=ptHead;
	while(ptLkHead!=NULL){
		pTemp=ptLkHead;
		ptLkHead=ptLkHead->pNext;

		if(strcmp(sProdID,pTemp->sIndexID)==0&&
			(strcmp(sCode,pTemp->sRptCode)==0||strcmp(sCode,"-1")==0)){
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


int SearchBiProductDescStructItem(char sProdID[],struct BiProductDescStruct **pptCur)
{
	static int iFirstFlag=true;
	static struct BiProductDescStruct *ptHead=NULL;
	struct BiProductDescStruct *pTemp,*ptLkHead;
	if(iFirstFlag==true){
		if(InitBiProductDesc(&ptHead)<0) return -1;
		
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
void DecodeMidNumberType(char sNumberType[],char sType[])
{
	strcpy(sType,"1");
	
	if(strcmp(sNumberType,"00")==0||strcmp(sNumberType,"01")==0||
		strcmp(sNumberType,"10")==0) strcpy(sType,"1");
	else if(strcmp(sNumberType,"03")==0||strcmp(sNumberType,"04")==0||
		strcmp(sNumberType,"12")==0||strcmp(sNumberType,"13")==0||
		strcmp(sNumberType,"20")==0) strcpy(sType,"2");
	else	strcpy(sType,"3");
	
}
void DecodeMidUeSettComp(char sCompCode[],char sValue[])
{
	if(strcmp(sCompCode,"CM")==0)		strcpy(sValue,"2");
	else if(strcmp(sCompCode,"CRC")==0)	strcpy(sValue,"5");
	else if(strcmp(sCompCode,"CT")==0)	strcpy(sValue,"1");
	else if(strcmp(sCompCode,"CTC")==0)	strcpy(sValue,"6");
	else strcpy(sValue,"-1");
	
}
void DecodeOthMidSettComp(char sInCompCode[],char sInNetType[],char sOutNetType[],char sValue[],char sOutCode[])
{
	char sTemp[3],sCompCode[20];
	
	if(strcmp(sOutNetType,"1")==0){
		strcpy(sTemp,"Y");
		strcpy(sCompCode,"fj_ltyd");
	}
	else{
		strcpy(sTemp,"G");
		strcpy(sCompCode,"fj_ltgw");
	}

	if(strcmp(sInNetType,"0")==0){
		if(strcmp(sInCompCode,"U")==0){
			strcat(sTemp,"4");
			strcat(sCompCode,"_ltgw");
		}
		else if(strcmp(sInCompCode,"M")==0){
			strcat(sTemp,"5");
			strcat(sCompCode,"_ydgw");
		}
		else{
			strcat(sTemp,"1");
			strcat(sCompCode,"_dxgw");
		}
	}
	else{
		if(strcmp(sInCompCode,"U")==0){
			strcat(sTemp,"3");
			strcat(sCompCode,"_ltyd");
		}
		else if(strcmp(sInCompCode,"M")==0){
			strcat(sTemp,"2");
			strcat(sCompCode,"_ydyd");
		}
		else{
			strcat(sTemp,"6");
			strcat(sCompCode,"_dxyd");
		}
	}
	strcpy(sValue,sTemp);
	strcpy(sOutCode,sCompCode);
}
int mvSttDetailtoMidtable(char sPart[],struct SettTicketUeStruct *pi,
	struct SettMTicketUeStruct *po)
{
	int iSettDuration=0,i;
	char	sOtherGroupID[3],sAreaCode[9],sTemp[10],sCompCode[10],sOutCode[20];
	struct RptMidRelStruct *pRptMidRel=NULL;
	struct BiProductDescStruct *ptCur=NULL;
	
	memset((void*)po,0,sizeof(struct SettMTicketUeStruct));

	i=strlen(pi->sCityID);
	if(pi->sCityID[i-1]=='0'){
		strncpy(po->sCityID,pi->sCityID,i-1);
		po->sCityID[i-1]=0;
	}
	else{
		strcpy(po->sCityID,pi->sCityID);
	}
	
	strcpy(po->sCallingNumber,		pi->sCallingNumber);
	strcpy(po->sCallingCityID,		pi->sCallingCityID);
	strcpy(po->sCallingType,		pi->sCallingType);
	strcpy(po->sCallingCompCode,		pi->sInCompanyCode);
	
	if(pi->sCallingAreaCode[0]=='0')
		strcpy(po->sCallingAreaCode,pi->sCallingAreaCode+1);
	else	strcpy(po->sCallingAreaCode,pi->sCallingAreaCode);
	
	
	strcpy(po->sCalledNumber,		pi->sCalledNumber);
	strcpy(po->sCalledCityID,		pi->sCalledCityID);
	strcpy(po->sCalledNumberType,		pi->sCalledNumberType);
	strcpy(po->sCalledCompCode,		pi->sOutCompanyCode);
	
	if(pi->sCalledAreaCode[0]=='0')
		strcpy(po->sCalledAreaCode,pi->sCalledAreaCode+1);
	else	strcpy(po->sCalledAreaCode,pi->sCalledAreaCode);

	if(strcmp(pi->sCallType,"09")==0||strcmp(pi->sCallType,"01")==0||strcmp(pi->sCallType,"1")==0)
		strcpy(po->sCallType,"1");
	else	strcpy(po->sCallType,"2");
	
	strcpy(po->sProdID,			pi->sProdID);
	strncpy(po->sSettDate,			pi->sStartTime,8);po->sSettDate[8]=0;
	
	po->dDuration=atof(pi->sDuration);
	po->dStlDuration=atof(pi->sStlDuration);
	po->dStlAmount=atof(pi->sStlAmount)/100.0;
	po->iSettCnt=1;
	
	strcpy(sOutCode,gsCompCode);
	
	if(strcmp(gsCarrID,"OTH")!=0)
		DecodeMidUeSettComp(gsCarrID,po->sSettCarrID);
	else	DecodeOthMidSettComp(pi->sInCompanyCode,pi->sInTrunkNetType,
			pi->sOutTrunkNetType,po->sSettCarrID,sOutCode);
	
	if(SearchBiProductDescStructItem(po->sProdID,&ptCur)==NOTFOUND){
		strcpy(po->sSettDirection,"-1");
	}
	else{
		strcpy(po->sSettDirection,ptCur->sSettDirection);
	}
	
	if(SearchRepMidRelStructItem(po->sProdID,sOutCode,&pRptMidRel)==FOUND)
		po->iReportItemID=pRptMidRel->iIndexGroupID;
	else{
		po->iReportItemID=-1;
		
		if((strcmp(gsNetWork,"GW")==0&&strcmp(gsCarrID,"CT")==0)||
			(strcmp(gsNetWork,"GW")==0&&strcmp(gsCarrID,"CTC")==0)){
			
			if(strcmp(gsCarrID,"CT")==0) strcpy(sCompCode,"fj_ltgw_dxyd");
			else if(strcmp(gsCarrID,"CTC")==0) strcpy(sCompCode,"fj_ltgw_dxgw");
			
			if(SearchRepMidRelStructItem(po->sProdID,
				sCompCode,&pRptMidRel)==FOUND)
				po->iReportItemID=pRptMidRel->iIndexGroupID;
		}
	}

	strcpy(po->sGroupID,		pi->sGroupID);
	if(strcmp(po->sCallType,"1")==0){
		i=strlen(pi->sCalledNumber);
		if(i<=2) strcpy(po->sOtherGroupID,po->sCalledNumber);
		else{
			strncpy(po->sOtherGroupID,	pi->sCalledNumber+i-2,2);
			po->sOtherGroupID[2]=0;
		}
	}
	else{
		i=strlen(pi->sCallingNumber);
		if(i<=2) strcpy(po->sOtherGroupID,po->sCallingNumber);
		else{
			strncpy(po->sOtherGroupID,	pi->sCallingNumber+i-2,2);
			po->sOtherGroupID[2]=0;
		}
	}
	
	DecodeMidNumberType(po->sCallingType,po->sCallingNbrType);
	DecodeMidNumberType(po->sCalledNumberType,po->sCalledNbrType);
	

	if(((strcmp(gsNetWork,"GW")==0&&strcmp(gsCarrID,"CT")==0)||
		(strcmp(gsNetWork,"GW")==0&&strcmp(gsCarrID,"CTC")==0))&&pRptMidRel!=NULL){
		
		if(strcmp(pRptMidRel->sOppCode,"dxgw")==0) strcpy(po->sSettCarrID,"1");
		else if(strcmp(pRptMidRel->sOppCode,"dxyd")==0) strcpy(po->sSettCarrID,"6");
	}

	return true;
}
int LoadSttTabletoBintree(int iGroupID,char sPart[],char sTableNameIn[],BINTREE **pptRoot)
{
	unsigned long ulRecCnt=0,ulold=0,ulnew=0;
	struct SettTicketUeStructIn TempIn;
	struct SettTicketUeStruct Temp;
	
	struct SettMTicketUeStruct TempMid;
	struct SettMTicketUeStruct *pTemp=NULL;
	struct SettMTicketUeStruct *ptFound=NULL;
	
	memset((void*)&TempIn,0,sizeof(struct SettTicketUeStructIn));
	memset((void*)&Temp,0,sizeof(struct SettTicketUeStruct));
	
	/*strcpy(TempIn.sTableName,sTableNameIn);
	strcpy(TempIn.sCondition,"");*/
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s)",sTableNameIn,sPart);
	sprintf(TempIn.sCondition,"WHERE GROUP_ID='%02d'",iGroupID);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetSettTicketUeToStruct(&Temp,&TempIn)) {
		
		/*转换结构体格式*/
		if(mvSttDetailtoMidtable(sPart,&Temp,&TempMid)==false) continue;
		
/*		if(SearchBin(*pptRoot,&TempMid,data_search_mid_stt,(void**)&ptFound)==FOUND){*/
		if(SearchMidStatItem(*pptRoot,&TempMid,&ptFound)==FOUND){
			ptFound->iSettCnt += TempMid.iSettCnt;
			ptFound->dDuration += TempMid.dDuration;
			ptFound->dStlDuration += TempMid.dStlDuration;
			ptFound->dStlAmount += TempMid.dStlAmount;
			ulold++;
		}
		else{
			if((pTemp=(struct SettMTicketUeStruct*)
				malloc(sizeof(struct SettMTicketUeStruct)))==NULL){
				WriteProcMsg("malloc struct SettMTicketUeStruct 失败!!!");
				return -1;
			}
			memset((void*)pTemp,0,sizeof(struct SettMTicketUeStruct));
			memcpy((void*)pTemp,(void*)&TempMid,sizeof(struct SettMTicketUeStruct));

			if(InsertBin(pptRoot,pTemp,data_search_mid_stt,
				assign_insert_bintree_mid_stt)<0){
				WriteProcMsg("生成二叉树 SettMTicketUeStruct 失败.");
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
int EInsertList2TableStt(char sTableName[],struct SettMTicketUeStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct SettMTicketUeStructOut TempOut;
	struct SettMTicketUeStruct *ptCur=NULL;
	struct SettMTicketUeStruct *ptLoadCur=NULL;

	memset(&TempOut,0,sizeof(struct SettMTicketUeStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			sprintf(ptCur->sDuration,"%lf",ptCur->dDuration);
			sprintf(ptCur->sStlDuration,"%lf",ptCur->dStlDuration);
			sprintf(ptCur->sStlAmount,"%lf",ptCur->dStlAmount);
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToSettMTicketUe(NULL,true,&TempOut)<0){
					WriteProcMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前输出数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToSettMTicketUe(ptCur,false,&TempOut)<0){
				WriteProcMsg("写表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			free(ptCur);
		}
	}
	if(EInsertStructToSettMTicketUe(NULL,true,&TempOut)<0){
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
		if(LoadSttTabletoBintree(iGroupID,sPart,sTableNameIn,&pRoot)<0) return -1;
		
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
/**********短彩信***************/

int mvMsgDetailtoMidtable(char sPart[],struct SettTicketSmStruct *pi,
	struct SettMTicketUeStruct *po)
{
	int iSettDuration=0,i;
	char	sOtherGroupID[3],sAreaCode[9],sTemp[10],sCityID[8];
	struct RptMidRelStruct *pTicketTypeMap=NULL;
	struct BiProductDescStruct *ptCur=NULL;
	
	memset((void*)po,0,sizeof(struct SettMTicketUeStruct));

	sprintf(sCityID,"%d",pi->iCityID);
	i=strlen(sCityID);
	if(sCityID[i-1]=='0'){
		strncpy(po->sCityID,sCityID,i-1);
		po->sCityID[i-1]=0;
	}
	else{
		strcpy(po->sCityID,sCityID);
	}
/*20160701,新增，由于短彩信处理方式一致，规整到短信处理接口中，新增彩信特殊判断方式*/	
	if(strcmp(gsType,"MMS")==0)
		strcpy(po->sCallingCityID,		pi->sCallingAreaCode);
	else	strcpy(po->sCallingCityID,		pi->sCallingCityID);
		
	strcpy(po->sCallingType,		pi->sCallingNumberType);
	strcpy(po->sCallingCompCode,		pi->sCallingCompanyID);
	
	if(pi->sCallingAreaCode[0]=='0')
		strcpy(po->sCallingAreaCode,pi->sCallingAreaCode+1);
	else	strcpy(po->sCallingAreaCode,pi->sCallingAreaCode);
	
	strcpy(po->sCallingNumber,		pi->sCallingNumber);
	
	/*20160701,新增，由于短彩信处理方式一致，规整到短信处理接口中，新增彩信特殊判断方式*/	
	if(strcmp(gsType,"MMS")==0)
		strcpy(po->sCalledCityID,		pi->sCalledAreaCode);
	else	strcpy(po->sCalledCityID,		pi->sCalledCityID);
		
	strcpy(po->sCalledNumberType,		pi->sCalledNumberType);
	strcpy(po->sCalledCompCode,		pi->sCalledCompanyID);
	
	if(pi->sCalledAreaCode[0]=='0')
		strcpy(po->sCalledAreaCode,pi->sCalledAreaCode+1);
	else	strcpy(po->sCalledAreaCode,pi->sCalledAreaCode);

	strcpy(po->sCalledNumber,		pi->sCalledNumber);
	
	if(strcmp(pi->sCallType,"07")==0||strcmp(pi->sCallType,"01")==0||strcmp(pi->sCallType,"1")==0)
		strcpy(po->sCallType,"1");
	else	strcpy(po->sCallType,"2");
	
	strcpy(po->sProdID,			pi->sProdID);
	strncpy(po->sSettDate,			pi->sStartTime,8);po->sSettDate[8]=0;
	
	po->dDuration=1;
	po->dStlDuration=1;
	po->dStlAmount=atof(pi->sStlAmount)/100.0;
	po->iSettCnt=1;
	
	if(SearchRepMidRelStructItem(po->sProdID,gsCompCode,&pTicketTypeMap)==FOUND)
		po->iReportItemID=pTicketTypeMap->iIndexGroupID;
	else	po->iReportItemID=-1;

	strcpy(po->sGroupID,		pi->sGroupID);
	
	DecodeMidNumberType(po->sCallingType,po->sCallingNbrType);
	DecodeMidNumberType(po->sCalledNumberType,po->sCalledNbrType);
	
	if(SearchBiProductDescStructItem(po->sProdID,&ptCur)==NOTFOUND){
		strcpy(po->sSettDirection,"-1");
	}
	else{
		strcpy(po->sSettDirection,ptCur->sSettDirection);
	}
	
	if(strcmp(po->sCallType,"1")==0){
		i=strlen(pi->sCalledNumber);
		if(i<=2) strcpy(po->sOtherGroupID,po->sCalledNumber);
		else{
			strncpy(po->sOtherGroupID,	pi->sCalledNumber+i-2,2);
			po->sOtherGroupID[2]=0;
		}
		
		if(strcmp(po->sCallingNbrType,"1")==0)
			strcpy(po->sSettCarrID,"Y");
		else	strcpy(po->sSettCarrID,"G");
		
		if(strcmp(pi->sDownCompanyID,"M")==0){
			if(strcmp(po->sCalledNbrType,"1")==0)
				strcat(po->sSettCarrID,"2");
			else	strcat(po->sSettCarrID,"5");
		}
		else{
			if(strcmp(po->sCalledNbrType,"1")==0)
				strcat(po->sSettCarrID,"6");
			else	strcat(po->sSettCarrID,"1");
		}
	}
	else{
		i=strlen(pi->sCallingNumber);
		if(i<=2) strcpy(po->sOtherGroupID,po->sCallingNumber);
		else{
			strncpy(po->sOtherGroupID,	pi->sCallingNumber+i-2,2);
			po->sOtherGroupID[2]=0;
		}
		
		if(strcmp(po->sCalledNbrType,"1")==0)
			strcpy(po->sSettCarrID,"Y");
		else	strcpy(po->sSettCarrID,"G");
		
		if(strcmp(pi->sUpCompanyID,"M")==0){
			if(strcmp(po->sCallingNbrType,"1")==0)
				strcat(po->sSettCarrID,"2");
			else	strcat(po->sSettCarrID,"5");
		}
		else{
			if(strcmp(po->sCallingNbrType,"1")==0)
				strcat(po->sSettCarrID,"6");
			else	strcat(po->sSettCarrID,"1");
		}
	}
	
/*	
	DecodeOthMidSettComp(pi->sInCompanyCode,pi->sInTrunkNetType,
		pi->sOutTrunkNetType,po->sSettCarrID);
*/
	return true;
}

void DecodeCallCompanyID(char sCallingCompanyID[],char sValue[],char sNumberType[])
{
	if(strcmp(sCallingCompanyID,"9001")==0){
		strcpy(sValue,"U");
		strcpy(sNumberType,"03");
	}
	else if(strcmp(sCallingCompanyID,"9002")==0){
		strcpy(sValue,"M");
		strcpy(sNumberType,"00");
	}
	else if(strcmp(sCallingCompanyID,"9003")==0){
		strcpy(sValue,"U");
		strcpy(sNumberType,"00");
	}
	else if(strcmp(sCallingCompanyID,"9004")==0){
		strcpy(sValue,"M");
		strcpy(sNumberType,"03");
	}
	else if(strcmp(sCallingCompanyID,"9005")==0){
		strcpy(sValue,"T");
		strcpy(sNumberType,"03");
	}
	else if(strcmp(sCallingCompanyID,"9007")==0){
		strcpy(sValue,"T");
		strcpy(sNumberType,"00");
	}
	else{
		strcpy(sValue,"U");
		strcpy(sNumberType,"00");
	}
	
	
}


void DecodeCallCompanyID_new(char sCallingCompanyID[],char sValue[],char sNumberType[])
{
	if(strcmp(sCallingCompanyID,"U")==0){
		strcpy(sValue,"U");
		strcpy(sNumberType,"00");
	}
	else if(strcmp(sCallingCompanyID,"M")==0){
		strcpy(sValue,"M");
		strcpy(sNumberType,"00");
	}
	else if(strcmp(sCallingCompanyID,"T")==0){
		strcpy(sValue,"T");
		strcpy(sNumberType,"00");
	}
	else{
		strcpy(sValue,"U");
		strcpy(sNumberType,"00");
	}
}

int mvMmsDetailtoMidtable(char sPart[],struct SettTicketMmsStruct *pi,
	struct SettMTicketUeStruct *po)
{
	int iSettDuration=0,i;
	char	sOtherGroupID[3],sAreaCode[9],sTemp[10],sCityID[8];
	struct RptMidRelStruct *pTicketTypeMap=NULL;
	struct BiProductDescStruct *ptCur=NULL;
	
	memset((void*)po,0,sizeof(struct SettMTicketUeStruct));

	sprintf(sCityID,"%d",pi->iCityID);
	i=strlen(sCityID);
	if(sCityID[i-1]=='0'){
		strncpy(po->sCityID,sCityID,i-1);
		po->sCityID[i-1]=0;
	}
	else{
		strcpy(po->sCityID,sCityID);
	}
	
	strcpy(po->sCallingCityID,		pi->sCallingAreaCode);
	
	DecodeCallCompanyID_new(pi->sCallingCompanyID,po->sCallingCompCode,po->sCallingType);
/*	
	strcpy(po->sCallingType,		pi->sCallingNumberType);
	strcpy(po->sCallingCompCode,		pi->sCallingCompanyID);*/
	
	if(pi->sCallingAreaCode[0]=='0')
		strcpy(po->sCallingAreaCode,pi->sCallingAreaCode+1);
	else	strcpy(po->sCallingAreaCode,pi->sCallingAreaCode);
	
	strcpy(po->sCallingNumber,		pi->sCallingNumber);
	
	strcpy(po->sCalledCityID,		pi->sCalledAreaCode);
	
	DecodeCallCompanyID_new(pi->sCalledCompanyID,po->sCalledCompCode,po->sCalledNumberType);

/*	
	strcpy(po->sCalledNumberType,		pi->sCalledNumberType);
	strcpy(po->sCalledCompCode,		pi->sCalledCompanyID);
*/	
	if(pi->sCalledAreaCode[0]=='0')
		strcpy(po->sCalledAreaCode,pi->sCalledAreaCode+1);
	else	strcpy(po->sCalledAreaCode,pi->sCalledAreaCode);

	strcpy(po->sCalledNumber,		pi->sCalledNumber);
	
	if(strcmp(pi->sCallType,"07")==0||strcmp(pi->sCallType,"01")==0||strcmp(pi->sCallType,"1")==0)
		strcpy(po->sCallType,"1");
	else	strcpy(po->sCallType,"2");
	
	strcpy(po->sProdID,			pi->sProdID);
	strncpy(po->sSettDate,			pi->sStartTime,8);po->sSettDate[8]=0;
	
	po->dDuration=1;
	po->dStlDuration=1;
	po->dStlAmount=atof(pi->sStlAmount)/100.0;
	po->iSettCnt=1;
	
	if(SearchRepMidRelStructItem(po->sProdID,gsCompCode,&pTicketTypeMap)==FOUND)
		po->iReportItemID=pTicketTypeMap->iIndexGroupID;
	else	po->iReportItemID=-1;

	strcpy(po->sGroupID,		pi->sGroupID);
	
	DecodeMidNumberType(po->sCallingType,po->sCallingNbrType);
	DecodeMidNumberType(po->sCalledNumberType,po->sCalledNbrType);
	
	if(SearchBiProductDescStructItem(po->sProdID,&ptCur)==NOTFOUND){
		strcpy(po->sSettDirection,"-1");
	}
	else{
		strcpy(po->sSettDirection,ptCur->sSettDirection);
	}
	
	if(strcmp(po->sCallType,"1")==0){
		i=strlen(pi->sCalledNumber);
		if(i<=2) strcpy(po->sOtherGroupID,po->sCalledNumber);
		else{
			strncpy(po->sOtherGroupID,	pi->sCalledNumber+i-2,2);
			po->sOtherGroupID[2]=0;
		}
		
		if(strcmp(po->sCallingNbrType,"1")==0)
			strcpy(po->sSettCarrID,"Y");
		else	strcpy(po->sSettCarrID,"G");
		
		if(strcmp(po->sCallingCompCode,"M")==0){
			if(strcmp(po->sCalledNbrType,"1")==0)
				strcat(po->sSettCarrID,"2");
			else	strcat(po->sSettCarrID,"5");
		}
		else{
			if(strcmp(po->sCalledNbrType,"1")==0)
				strcat(po->sSettCarrID,"6");
			else	strcat(po->sSettCarrID,"1");
		}
	}
	else{
		i=strlen(pi->sCallingNumber);
		if(i<=2) strcpy(po->sOtherGroupID,po->sCallingNumber);
		else{
			strncpy(po->sOtherGroupID,	pi->sCallingNumber+i-2,2);
			po->sOtherGroupID[2]=0;
		}

		if(strcmp(po->sCalledNbrType,"1")==0)
			strcpy(po->sSettCarrID,"Y");
		else	strcpy(po->sSettCarrID,"G");
		
		if(strcmp(po->sCalledCompCode,"M")==0){
			if(strcmp(po->sCallingNbrType,"1")==0)
				strcat(po->sSettCarrID,"2");
			else	strcat(po->sSettCarrID,"5");
		}
		else{
			if(strcmp(po->sCallingNbrType,"1")==0)
				strcat(po->sSettCarrID,"6");
			else	strcat(po->sSettCarrID,"1");
		}
	}
	
/*	
	DecodeOthMidSettComp(pi->sInCompanyCode,pi->sInTrunkNetType,
		pi->sOutTrunkNetType,po->sSettCarrID);
*/
	return true;
}

int LoadSmsTabletoBintree(int iGroupID,char sPart[],char sTableNameIn[],BINTREE **pptRoot)
{
	unsigned long ulRecCnt=0,ulold=0,ulnew=0;
	struct SettTicketSmStructIn TempIn;
	struct SettTicketSmStruct Temp;
	
	struct SettMTicketUeStruct TempMid;
	struct SettMTicketUeStruct *pTemp=NULL;
	struct SettMTicketUeStruct *ptFound=NULL;
	
	memset((void*)&TempIn,0,sizeof(struct SettTicketSmStructIn));
	memset((void*)&Temp,0,sizeof(struct SettTicketSmStruct));
	
	/*strcpy(TempIn.sTableName,sTableNameIn);
	strcpy(TempIn.sCondition,"");*/
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s)",sTableNameIn,sPart);
	sprintf(TempIn.sCondition,"WHERE GROUP_ID='%02d' AND IS_FREE='0'",iGroupID);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetSettTicketSmToStruct(&Temp,&TempIn)) {
		
		/*转换结构体格式*/
		if(mvMsgDetailtoMidtable(sPart,&Temp,&TempMid)==false) continue;
		
/*		if(SearchBin(*pptRoot,&TempMid,data_search_mid_stt,(void**)&ptFound)==FOUND){*/
		if(SearchMidStatItem(*pptRoot,&TempMid,&ptFound)==FOUND){
			ptFound->iSettCnt += TempMid.iSettCnt;
			ptFound->dDuration += TempMid.dDuration;
			ptFound->dStlDuration += TempMid.dStlDuration;
			ptFound->dStlAmount += TempMid.dStlAmount;
			ulold++;
		}
		else{
			if((pTemp=(struct SettMTicketUeStruct*)
				malloc(sizeof(struct SettMTicketUeStruct)))==NULL){
				WriteProcMsg("malloc struct SettMTicketUeStruct 失败!!!");
				return -1;
			}
			memset((void*)pTemp,0,sizeof(struct SettMTicketUeStruct));
			memcpy((void*)pTemp,(void*)&TempMid,sizeof(struct SettMTicketUeStruct));

			if(InsertBin(pptRoot,pTemp,data_search_mid_stt,
				assign_insert_bintree_mid_stt)<0){
				WriteProcMsg("生成二叉树 SettMTicketUeStruct 失败.");
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
int LoadMmsTabletoBintree(int iGroupID,char sPart[],char sTableNameIn[],BINTREE **pptRoot)
{
	unsigned long ulRecCnt=0,ulold=0,ulnew=0;
	struct SettTicketMmsStructIn TempIn;
	struct SettTicketMmsStruct Temp;
	
	struct SettMTicketUeStruct TempMid;
	struct SettMTicketUeStruct *pTemp=NULL;
	struct SettMTicketUeStruct *ptFound=NULL;
	
	memset((void*)&TempIn,0,sizeof(struct SettTicketMmsStructIn));
	memset((void*)&Temp,0,sizeof(struct SettTicketMmsStruct));
	
	/*strcpy(TempIn.sTableName,sTableNameIn);
	strcpy(TempIn.sCondition,"");*/
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s) ",sTableNameIn,sPart);
	sprintf(TempIn.sCondition,"WHERE GROUP_ID='%02d' AND IS_FREE ='0' ",iGroupID);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetSettTicketMmsToStruct(&Temp,&TempIn)) {
		
		/*转换结构体格式*/
		if(mvMmsDetailtoMidtable(sPart,&Temp,&TempMid)==false) continue;
		
/*		if(SearchBin(*pptRoot,&TempMid,data_search_mid_stt,(void**)&ptFound)==FOUND){*/
		if(SearchMidStatItem(*pptRoot,&TempMid,&ptFound)==FOUND){
			ptFound->iSettCnt += TempMid.iSettCnt;
			ptFound->dDuration += TempMid.dDuration;
			ptFound->dStlDuration += TempMid.dStlDuration;
			ptFound->dStlAmount += TempMid.dStlAmount;
			ulold++;
		}
		else{
			if((pTemp=(struct SettMTicketUeStruct*)
				malloc(sizeof(struct SettMTicketUeStruct)))==NULL){
				WriteProcMsg("malloc struct SettMTicketUeStruct 失败!!!");
				return -1;
			}
			memset((void*)pTemp,0,sizeof(struct SettMTicketUeStruct));
			memcpy((void*)pTemp,(void*)&TempMid,sizeof(struct SettMTicketUeStruct));

			if(InsertBin(pptRoot,pTemp,data_search_mid_stt,
				assign_insert_bintree_mid_stt)<0){
				WriteProcMsg("生成二叉树 SettMTicketUeStruct 失败.");
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
int DealMsProcMain(char sPart[],char sType[],char sTableNameIn[],char sTableNameOut[])
{
	int iGroupID=0;
	BINTREE *pRoot=NULL;
	while(iGroupID<100){
		/*从详单表中加载数据*/
		/*20160701,由于彩信格式变化修改成与短信一致及处理方式一致，故直接使用短信方式处理即可，无需新增相关处理代码*/
		if(strcmp(sType,"SMS")==0||strcmp(sType,"MMS")==0){
			if(LoadSmsTabletoBintree(iGroupID,sPart,sTableNameIn,&pRoot)<0) return -1;
		}
		/*20160701，由于被前面全部处理，本else不会再进行相关业务处理，无需关注*/
		else{
			if(LoadMmsTabletoBintree(iGroupID,sPart,sTableNameIn,&pRoot)<0) return -1;
		}
		
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

void DecodeProdCode(char sNetWork[],char sCompCode[],char sValue[])
{
	char sTemp[128];
	
	if(strcmp(sNetWork,"YD")==0)
		sprintf(sTemp,"fj_ltyd_");
	else	sprintf(sTemp,"fj_ltgw_");
	
	if(strcmp(sCompCode,"CM")==0)		strcat(sTemp,"ydyd");
	else if(strcmp(sCompCode,"CRC")==0)	strcat(sTemp,"ydgw");
	else if(strcmp(sCompCode,"CT")==0)	strcat(sTemp,"dxgw");
	else if(strcmp(sCompCode,"CTC")==0)	strcat(sTemp,"dxyd");
	else if(strcmp(sCompCode,"CNC")==0)	strcat(sTemp,"ltyd");
	else strcpy(sTemp,"");
	
	strcpy(sValue,sTemp);
}

int main(int argc,char **argv)
{
	
	char sNetWork[4],sCarrID[4],sType[10];
	char sMonth[3],sPart[9];
	char sTableNameIn[31],sTableNameOut[31];

	/*检查参数*/	
	if(CheckParam(argc,argv)<0) return -1;
	
	strcpy(sPart,argv[1]);
	strncpy(sMonth,sPart+4,2);sMonth[2]=0;
	strcpy(sType,argv[2]);
	
	InitAppRes(argv[0]);
/* 新增全局变量type，为方便内部使用*/	
	strcpy(gsType,sType);
	
	if(ConnectDataDB()<0) return -1;
		
	WriteProcMsg("中间统计程序开始执行...");
	if(argc==3){
		/*短信、彩信 表待定*/
		if(strcmp(sType,"SMS")==0){
			sprintf(sTableNameIn,"ST_SMS_TICKET_%s",sMonth);
			sprintf(sTableNameOut,"ST_SMS_M_TICKET_%s",sMonth);
			strcpy(gsCompCode,"-1");
		}
		else{
			sprintf(sTableNameIn,"ST_MMS_TICKET_%s",sMonth);
			sprintf(sTableNameOut,"ST_MMS_M_TICKET_%s",sMonth);
			strcpy(gsCompCode,"-1");
		}
		
		if(DealMsProcMain(sPart,sType,sTableNameIn,sTableNameOut)<0) return -1;
		
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
		
		DecodeProdCode(gsNetWork,gsCarrID,gsCompCode);
		
		if(DealSTTProcMain(sPart,sTableNameIn,sTableNameOut)<0) return -1;;
	}
	
	WriteProcMsg("从详单表 %s 统计到中间表 %s 完成.",sTableNameIn,sTableNameOut);

	DisconnectDatabase();	
	WriteProcMsg("中间统计程序执行完成.");
	return 0;
}
