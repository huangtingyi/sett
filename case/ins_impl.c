#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <wwcoding.h>
#include <ticket_field.h>
#include <param_intf.h>
#include <up_back.h>
#include <stt_ticket.h>
#include <wwsupp.h>


int InsertNewGsmTicket(char sFileName[],char sTableName[]);

void RegularDealDate(char sBaseName[],char sDealDate[])
{
	char sTemp[15];

	strncpy(sTemp,sBaseName+6,8);sTemp[8]=0;
	strcpy(sTemp+8,"000000");
	if(ChkTime(sTemp)==0)	strcpy(sDealDate,sTemp);
}
int InsertTicket(char sFileName[],char sTableName[],char sType[])
{
	int iCnt;

	switch(sType[0]){
		case 'P':
			iCnt=InsertPrepTicket(sFileName,sTableName);
		break;
		case 'S':
			iCnt=InsertSttTicket(sFileName,sTableName);
		break;
		case 'M':
			iCnt=InsertSmscTicket(sFileName,sTableName);
		break;
		case 'N':
			iCnt=InsertSmspTicket(sFileName,sTableName);
		break;
		case 'R':
			/*RTD	gprs漫游上传格式*/
			/*RTE	gprs中兴格式*/
			if(strcmp(sType,"RTD")==0)
				iCnt=InsertGprsStdIntf(sFileName,sTableName);
			else if(strcmp(sType,"RTE")==0)
				iCnt=InsertGprsZteIntf(sFileName,sTableName);
			else if(strcmp(sType,"RTX")==0)
				iCnt=InsertGprsTicketNew(sFileName,sTableName);
			else	iCnt=InsertGprsTicket(sFileName,sTableName);
		break;
		case 'X':
			iCnt=InsertCdma1xTicket(sFileName,sTableName);
		break;
		case 'T':
			iCnt=InsertSmsTicket(sFileName,sTableName);
		break;
		case 't':
			iCnt=InsertNsmsTicket(sFileName,sTableName);
		break;
		case 'G':
			if(sType[1]=='N')
				iCnt=InsertNewGsmTicket(sFileName,sTableName);
			else if(sType[1]='X')
				iCnt=InsertGXGsmTicket(sFileName,sTableName);
			else
				iCnt=InsertGsmTicket(sFileName,sTableName);
		break;
		case 'C':
			iCnt=InsertCdmaTicket(sFileName,sTableName);
		break;
		case '1':
			iCnt=Insert193Ticket(sFileName,sTableName);
		break;
		case '2':
			iCnt=InsertRhjfBillTicket(sFileName,sTableName);
		break;
		case 'c':
			iCnt=InsertCdmaBillTicket(sFileName,sTableName);
		break;
		case 'g':
			iCnt=InsertGsmBillTicket(sFileName,sTableName);
		break;
		case 's':
			iCnt=InsertSmsBillTicket(sFileName,sTableName);
		break;
		case 'u':
			iCnt=InsertSmsupBillTicket(sFileName,sTableName);
		break;
		case 'U':
			iCnt=InsertSmsupIntfTicket(sFileName,sTableName);
		break;
		case 'a':
			iCnt=InsertSmgTicket(sFileName,sTableName);
		break;
		case 'Z':
			iCnt=InsertZnwTicket(sFileName,sTableName);
		break;
		case 'I':
			iCnt=InsertIccTicket(sFileName,sTableName);
		break;
		case 'F':
			iCnt=InsertInfoAcct(sFileName,sTableName);
		break;
		case 'f':
			iCnt=InsertInfoNbrAcct(sFileName,sTableName);
		break;
		case 'n':
			iCnt=InsertNxRhjfTicket(sFileName,sTableName);
		break;
		case 'E':
			iCnt=InsertErrTicket(sFileName,sTableName);
		break;
		default:
			iCnt=-1;
			WriteAlertMsg("文件%s,表名%s,入库失败,类型%s不存在.",sFileName,sTableName,sType);
		break;
	}
	return iCnt;
}
void mvitem_fmprepticket(struct FPrepTicketStruct *pi,int len,
	struct PrepTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct PrepTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sLac,		pi->sLac,4);
		strncpy(po->sCellID,		pi->sCellID,4);
		strncpy(po->sOtherLac,		pi->sOtherLac,4);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,4);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sMsrn,		pi->sMsrn,12);
		
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sReserve1,		pi->sReserve1,2);

		strncpy(po->sEsn,		pi->sEsn,15);

		strncpy(po->sScpFlag,		pi->sScpFlag,1);
		strncpy(po->sDeformFlag,	pi->sDeformFlag,1);
		strncpy(po->sReserve,		pi->sReserve,8);

		if(len==sizeof(struct FPrepTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);

			AllTrim(po->sErrCode);
			AllTrim(po->sFileName);
			AllTrim(po->sModule);
			AllTrim(po->sAreaCode);
		}

		AllTrim(po->sCallType);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sUserType);
		AllTrim(po->sReserve1);
		AllTrim(po->sEsn);
		AllTrim(po->sReserve);
}
/*标识PREP重单的DEFORM_FLAG字段开始....*/
static struct FileControlStruct *pDup=NULL;
static int mark_deform_flag_hook_pdup_list(void **ppData)
{
	char sPreCallType[3],sCallType[3],cDeformFlag;
	struct FPrepTicketStruct *p;
	struct DupKeyStruct *pTemp,*ptHead=(struct DupKeyStruct *)(*ppData);

	if(CountList((LIST*)ptHead)==1) goto next_mark_over;

/*对重单打DEFORM_FLAG标记*/
	strcpy(sPreCallType,"");
	cDeformFlag='A';

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*p=(struct FPrepTicketStruct *)pTemp->pData;*/
		p=(struct FPrepTicketStruct *)((struct FileControlStruct *)pTemp->pData)->pData;

		strncpy(sCallType,p->sCallType,2);sCallType[2]=0;

		if(strcmp(sCallType,sPreCallType)!=0){
			strcpy(sPreCallType,sCallType);
			p->sDeformFlag[0]=cDeformFlag;
			cDeformFlag++;
			/*超过ABCD的，就直接去掉*/
			if(p->sDeformFlag[0]>='E') p->sDeformFlag[0]='X';
		}
		else/*如果是一样的则第二张话单标为X*/
			p->sDeformFlag[0]='X';

	}
/*将打好标记的话单挂回到pDup中*/
next_mark_over:
	ptHead=(struct DupKeyStruct *)(*ppData);

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		InsertList((LIST**)&pDup,(LIST*)(pTemp->pData));
	}
/*释放DupKey结构链表*/
	DestroyList((LIST*)(*ppData));
	return 0;
}
static void mvitem_ticket2dup(struct FPrepTicketStruct *pi,struct DupKeyStruct *po)
{
	int l;
	char	sTemp[32];

	bzero((void*)po,sizeof(struct DupKeyStruct));

	strncpy(po->sCallType,	pi->sCallType,2);

	strncpy(po->sMsisdn,	pi->sMsisdn,15);
	strncpy(sTemp,	pi->sOtherParty,24);sTemp[24]=0;


	AllTrim(po->sMsisdn);
	AllTrim(sTemp);

	l=0;
	if(sTemp[0]=='0'){
		struct AreaCodeDescStruct *pTemp;
		if(SearchAreaCodeDesc(sTemp+1,&pTemp)==FOUND)
			l=strlen(pTemp->sAreaCode)+1;
	}
	
	strcpy(po->sOtherParty,sTemp+l);
	

	po->sOtherParty[12]=0;	
	strncpy(sTemp,  pi->sTrunkIn,6);sTemp[6]=0;
	AllTrim(sTemp);
	strcat(po->sOtherParty,sTemp);

	strncpy(sTemp,  pi->sTrunkOut,6);sTemp[6]=0;
	AllTrim(sTemp);
	strcat(po->sOtherParty,sTemp);

	strncpy(sTemp,	pi->sDuration,6);sTemp[6]=0;
	po->iDuration=	atoi(sTemp);

	strncpy(po->sStartTime,	pi->sStartTime,14);
}
static int data_search_bintree_dup_key_e(void *pValue,void*pData)
{
	struct DupKeyStruct *pSource=(struct DupKeyStruct *)pValue;
	struct DupKeyStruct *pTarget=(struct DupKeyStruct *)pData;

/*数据比较部分*/
	int res=0;

	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sOtherParty,pTarget->sOtherParty))!=0) return res;
	
	res =tGetTime(pSource->sStartTime)-tGetTime(pTarget->sStartTime);
	if(res<0||res>0) return res;
	
	res=pSource->iDuration-pTarget->iDuration;
	if(res<0||res>0) return res;

	return 0;

}
static int comp_insert_list_dup_key_e(LIST *pValue,LIST*pHead)
{
	struct DupKeyStruct *pSource=(struct DupKeyStruct *)pValue;
	struct DupKeyStruct *pTarget=(struct DupKeyStruct *)pHead;
/*CALL_TYPE按照降序排列**/
	return strcmp(pTarget->sCallType,pSource->sCallType);
}
static void assign_insert_bintree_dup_key_e(void **ppHead,void *pData)
{
	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_dup_key_e);
}
static void MarkDupTicket(struct FileControlStruct **pptHead)
{
	BINTREE	*pRoot=NULL;
	struct DupKeyStruct *p;
	struct FileControlStruct *pTemp,*ptHead=(*pptHead);
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((p=(struct DupKeyStruct*)malloc(
			sizeof(struct DupKeyStruct )))==NULL){
			WriteAlertMsg("生成DUPKEY失败dup_key");
			exit(1);
		}
		/**将记录的参数导入MobTicket中**/
		mvitem_ticket2dup((struct FPrepTicketStruct *)pTemp->pData,
			(struct DupKeyStruct *)p);
		
		p->pData=(void*)pTemp;

		if(InsertBin(&pRoot,(void *)p,
			data_search_bintree_dup_key_e,
			assign_insert_bintree_dup_key_e)<0){
			WriteAlertMsg("生成BINTREE失败dup_key");
			exit(1);
		}
	}
	pDup=NULL;
	TravelBin(pRoot,mark_deform_flag_hook_pdup_list);
	*pptHead=pDup;
	DestroyBin(pRoot);
}
/*标识PREP重单的DEFORM_FLAG字段结束....*/
int InsertPrepTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct PrepTicketStruct Temp;
	struct PrepTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct PrepTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	
	MarkDupTicket(&ptHead);

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmprepticket((struct FPrepTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToPrepTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToPrepTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmsttticket(struct FSttTicketStruct *pi,int len,
	struct SttTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SttTicketStruct));

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);

		strncpy(sTemp,		pi->sRoamFee,5);sTemp[5]=0;
		po->iRoamFee=atoi(sTemp);
		strncpy(sTemp,		pi->sTollFee,7);sTemp[7]=0;
		po->iTollFee=atoi(sTemp);
		strncpy(sTemp,		pi->sAddFee,5);sTemp[5]=0;
		po->iAddFee=atoi(sTemp);
		strncpy(sTemp,		pi->sDuration,6);sTemp[6]=0;
		po->iDuration=atoi(sTemp);

		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sDistanceType,	pi->sDistanceType,1);
		strncpy(po->sOppType,		pi->sOppType,1);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sSplitRuleID,	pi->sSplitRuleID,4);
		strncpy(po->sOppRoamType,	pi->sOppRoamType,1);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sOtherLac,		pi->sOtherLac,5);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,7);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,7);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sMsrn,		pi->sMsrn,12);

		strncpy(sTemp,	pi->sTrunkInTypeID,4);sTemp[4]=0;
		po->iTrunkInTypeID=atoi(sTemp);
		strncpy(sTemp,	pi->sTrunkOutTypeID,4);sTemp[4]=0;
		po->iTrunkOutTypeID=atoi(sTemp);
		strncpy(sTemp,	pi->sTrunkInCarrierID,4);sTemp[4]=0;
		po->iTrunkInCarrierID=atoi(sTemp);
		strncpy(sTemp,	pi->sTrunkOutCarrierID,4);sTemp[4]=0;
		po->iTrunkOutCarrierID=atoi(sTemp);

		strncpy(po->sTrunkInType,	pi->sTrunkInType,1);
		strncpy(po->sTrunkOutType,	pi->sTrunkOutType,1);

		strncpy(sTemp,	pi->sCallingCarrierID,4);sTemp[4]=0;
		po->iCallingCarrierID=atoi(sTemp);
		strncpy(sTemp,	pi->sCalledCarrierID,4);sTemp[4]=0;
		po->iCalledCarrierID=atoi(sTemp);
		strncpy(sTemp,	pi->sCallingTypeID,4);sTemp[4]=0;
		po->iCallingTypeID=atoi(sTemp);
		strncpy(sTemp,	pi->sCalledTypeID,4);sTemp[4]=0;
		po->iCalledTypeID=atoi(sTemp);

		strncpy(sTemp,	pi->sCallingAreaID,4);sTemp[4]=0;
		po->iCallingAreaID=atoi(sTemp);
		strncpy(sTemp,	pi->sCalledAreaID,4);sTemp[4]=0;
		po->iCalledAreaID=atoi(sTemp);

		strncpy(po->sSplitType,		pi->sSplitType,1);
		strncpy(po->sCal,		pi->sCal,1);
		strncpy(po->sEsn,		pi->sEsn,15);

		strncpy(po->sScpFlag,		pi->sScpFlag,1);
		strncpy(po->sDeformFlag,	pi->sDeformFlag,1);
		strncpy(po->sReserve,		pi->sReserve,8);
		strncpy(po->sBillMode,		pi->sBillMode,3);
		
		strncpy(po->sReserve1,		pi->sReserve1,2);
		strncpy(po->sRoamTariffType,	pi->sRoamTariffType,3);
		strncpy(po->sTollTariffType,	pi->sTollTariffType,3);
		strncpy(po->sAddTariffType,	pi->sAddTariffType,3);

		if(len==sizeof(struct FSttTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
		}

		AllTrim(po->sCallType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sCalledCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sStartTime);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sRoamType);
		AllTrim(po->sDistanceType);
		AllTrim(po->sOppType);
		AllTrim(po->sUserType);
		AllTrim(po->sSplitRuleID);
		AllTrim(po->sOppRoamType);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sImsi);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sTrunkInType);
		AllTrim(po->sTrunkOutType);

		AllTrim(po->sCal);
		AllTrim(po->sEsn);

		AllTrim(po->sScpFlag);
		AllTrim(po->sDeformFlag);
		AllTrim(po->sReserve);
		AllTrim(po->sBillMode);
		
		AllTrim(po->sReserve1);
		AllTrim(po->sRoamTariffType);
		AllTrim(po->sTollTariffType);
		AllTrim(po->sAddTariffType);

		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);

}
int InsertSttTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct SttTicketStruct Temp;
	struct SttTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct SttTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToSttTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSttTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}
	listfree(&ptLkHead);

	return iCnt;
}
void mvitem_cri2vitticket(up_cri_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));

	if(strncmp(pi->RecType,"20",2)==0){
		strcpy(po->sCallType,"01");
		strncpy(po->sMsisdn,pi->CallingNum,15);
		strncpy(po->sOtherParty,pi->CalledNum,15);
		strncpy(po->sCalledCode,pi->OutCityCode,3);
		strncpy(po->sVisitAreaCode,pi->InCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
	else{
		strcpy(po->sCallType,"02");
		strncpy(po->sMsisdn,pi->CalledNum,15);
		strncpy(po->sOtherParty,pi->CallingNum,15);
		strncpy(po->sCalledCode,pi->InCityCode,3);
		strncpy(po->sVisitAreaCode,pi->OutCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
		strncpy(sTemp,pi->RoamCharge,9);sTemp[9]=0;
		po->iRoamFee=			atoi(sTemp);
		strncpy(sTemp,pi->LandCharge,6);sTemp[6]=0;
		po->iTollFee=			atoi(sTemp);
		strncpy(sTemp,pi->OtherCharge,6);sTemp[6]=0;
		po->iAddFee=			atoi(sTemp);

		strncpy(sTemp,pi->Duration,6);
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,	pi->CallDate,8);
		strncpy(po->sStartTime+8,	pi->CallStartTime,6);

		strncpy(po->sRoamType,		"2",	1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}

		strncpy(po->sUserType,		"1",1);

		strncpy(po->sImsi,		pi->IMSI,15);
		AllTrim(po->sImsi);

		strcpy(po->sMsrn,"");

		strncpy(po->sMsc,		pi->MSC,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		pi->LAC,5);
		AllTrim(po->sLac);
		strncpy(po->sCellID,		pi->CellOri_A,5);
		AllTrim(po->sCellID);

		strcpy(po->sServiceType,"000");
		strcpy(po->sServiceCode,"0011");

		strncpy(po->sSupplementCode,	pi->FunctionCode1,15);
}
void mvitem_cri2vitticket_trans(up_cri_hz_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));



		strcpy(po->sCallType,"03");
		strncpy(po->sThirdParty,pi->CallingNum,12);
		strncpy(po->sMsisdn,	pi->NumB,15);
		strncpy(po->sOtherParty,pi->CalledNum,15);

		strncpy(po->sCalledCode,pi->OutCityCode,3);
		strncpy(po->sVisitAreaCode,pi->InCityCode,3);

		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sThirdParty);


		po->iRoamFee=			0;
		po->iTollFee=			0;
		po->iAddFee=			0;

		strncpy(sTemp,pi->Duration,6);
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,	pi->CallDate,8);
		strncpy(po->sStartTime+8,	pi->CallStartTime,6);

		strncpy(po->sRoamType,		"2",	1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}

		strncpy(po->sUserType,		"1",1);

		strncpy(po->sImsi,		pi->IMSI,15);
		AllTrim(po->sImsi);

		strcpy(po->sMsrn,"");

		strncpy(po->sMsc,		pi->MSC,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		pi->LAC,5);
		AllTrim(po->sLac);
		strncpy(po->sCellID,		pi->CellOri_A,5);
		AllTrim(po->sCellID);

		strcpy(po->sServiceType,"002");
		strncpy(po->sServiceCode,"00",2);
		if(strncmp(pi->AppendCode,"  ",2)!=0)
			strncpy(po->sServiceCode,pi->AppendCode,2);
		else
			strncpy(po->sServiceCode,"00",2);

		strcpy(po->sSupplementCode,	"");
}
void mvitem_cii2vitticket(up_cii_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));



	if(strncmp(pi->RecType,"20",2)==0){
		strcpy(po->sCallType,"01");
		strncpy(po->sMsisdn,pi->CallingNum,15);
		strncpy(po->sOtherParty,pi->CalledNum,15);
		strncpy(po->sCalledCode,pi->OutCityCode,3);
		strncpy(po->sVisitAreaCode,pi->InCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
	else{
		strcpy(po->sCallType,"02");
		strncpy(po->sMsisdn,pi->CalledNum,15);
		strncpy(po->sOtherParty,pi->CallingNum,15);
		strncpy(po->sCalledCode,pi->InCityCode,3);
		strncpy(po->sVisitAreaCode,pi->OutCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
		strncpy(sTemp,pi->Charges,9);sTemp[9]=0;
		po->iRoamFee=			atoi(sTemp);


		strncpy(sTemp,pi->Duration,6);sTemp[6]=0;
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,	pi->CallDate,8);
		strncpy(po->sStartTime+8,	pi->CallStartTime,6);

		strncpy(po->sRoamType,		"3",	1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}

		strncpy(po->sUserType,		"1",1);

		strncpy(po->sImsi,		pi->IMSI,15);
		AllTrim(po->sImsi);

		strcpy(po->sMsrn,"");

		strncpy(po->sMsc,		pi->MSC,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		pi->LAC,5);
		AllTrim(po->sLac);
		strncpy(po->sCellID,		pi->CellOri_A,5);
		AllTrim(po->sCellID);

		strcpy(po->sServiceType,"000");
		strcpy(po->sServiceCode,"0011");

		strncpy(po->sSupplementCode,	pi->FunctionCode1,15);
}
int InsertGsmTicket(char sFileName[],char sTableName[])
{
	int iCnt=0;
	char sBaseName[60],sDealDate[15];
	struct UpTicketGStructOut TempOut;
	struct UpTicketGStruct Temp;
	FILE *fp;
	char sTicket[TICKETBUFSIZE];

	GetBaseName(sFileName,sBaseName);

	bzero((void*)&TempOut,sizeof(struct UpTicketGStructOut));
	TempOut.iCurPos=0;

	strcpy(TempOut.sTableName,sTableName);

	if((fp=fopen(sFileName,"r"))==NULL){
		printf("File %s Open Error!\n",sFileName);
		return -1;
	}
	if(strncmp(sBaseName,"CRI",3)!=0&&
		strncmp(sBaseName,"CII",3)!=0&&
		strncmp(sBaseName,"GBI",3)!=0&&
                strncmp(sBaseName,"QHT",3)!=0&&
                strncmp(sBaseName,"CQT",3)!=0&&
		strncmp(sBaseName,"TRI",3)!=0&&
		strncmp(sBaseName,"TII",3)!=0) return 0;

	if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
		sBaseName[strlen(sBaseName)-4]=0;

	strncpy(sDealDate,"20",2);
	strncpy(sDealDate+2,sBaseName+3,6);
	if(strncmp("CRIT",sBaseName,4)==0)
		strncpy(sDealDate+2,sBaseName+4,6);
	strcpy(sDealDate+8,"000000");

	while(1){
		fgets(sTicket,TICKETBUFSIZE,fp);
		if(feof(fp)) break;

		if(strncmp(sTicket,"10",2)==0) continue;

		if(strncmp(sBaseName,"CRI",3)==0||
			strncmp(sBaseName,"GBI",3)==0||
			strncmp(sBaseName,"TRI",3)==0){

			if(strncmp(sTicket,"41",2)==0)
				mvitem_cri2vitticket_trans((up_cri_hz_buf*)&sTicket,&Temp);
			else
				mvitem_cri2vitticket((up_cri_buf*)&sTicket,&Temp);
		}
		else
			mvitem_cii2vitticket((up_cii_buf*)&sTicket,&Temp);

		strcpy(Temp.sDealDate,sDealDate);
		strcpy(Temp.sSourceID,sBaseName);

		GetImsiArea(Temp.sImsi,"G",Temp.sStartTime,Temp.sHomeAreaCode);
		if(strcmp(Temp.sHomeAreaCode,"086")==0||
			strlen(Temp.sHomeAreaCode)==0)
			GetBelongCode(Temp.sMsisdn,Temp.sStartTime,Temp.sHomeAreaCode);

		if(EInsertStructToUpTicketG(&Temp,FALSE,&TempOut)<0) return -1;

		iCnt++;
/*	if(EInsertStructToUpTicketG(NULL,TRUE,&TempOut)<0)
		return -1;
**/
	}
	if(EInsertStructToUpTicketG(NULL,TRUE,&TempOut)<0) return -1;


	printf("成功将文件%s入库到表%s",sBaseName,sTableName);

	return iCnt;

}
void mvitem_cri_gx2vitticket(struct FVisitGsmupCriStruct* pi,struct VisitGsmupCriStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct VisitGsmupCriStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sScpFlagID,		pi->sLinkRef,1);
		strncpy(po->sLinkRef,		pi->sLinkRef+1,5);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,25);
		strncpy(po->sModifyTag,		pi->sModifyTag,1);
		strncpy(po->sNbrType,		pi->sNbrType,1);
		strncpy(po->sNbrPlan,		pi->sNbrPlan,1);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sDupServiceType,	pi->sDupServiceType,1);
		strncpy(po->sDupServiceCode,	pi->sDupServiceCode,2);
		strncpy(po->sAckChannel,	pi->sAckChannel,1);
		strncpy(po->sUseChannel,	pi->sUseChannel,1);
		strncpy(po->sTransparentFlag,	pi->sTransparentFlag,1);
		strncpy(po->sAct1,		pi->sAct1,1);
		strncpy(po->sCode1,		pi->sCode1,2);
		strncpy(po->sAct2,		pi->sAct2,1);
		strncpy(po->sCode2,		pi->sCode2,2);
		strncpy(po->sAct3,		pi->sAct3,1);
		strncpy(po->sCode3,		pi->sCode3,2);
		strncpy(po->sAct4,		pi->sAct4,1);
		strncpy(po->sCode4,		pi->sCode4,2);
		strncpy(po->sAct5,		pi->sAct5,1);
		strncpy(po->sCode5,		pi->sCode5,2);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sFlowRef,		pi->sFlowRef,6);
		strncpy(po->sTollCode,		pi->sTollCode,1);
		strncpy(po->sOtherCode,		pi->sOtherCode,2);
		strncpy(po->sRoamFee,		pi->sRoamFee,9);
		strncpy(po->sTollFee,		pi->sTollFee,6);
		strncpy(po->sOtherFee,		pi->sOtherFee,6);
		strncpy(po->sPayItem,		pi->sPayItem,1);
		strncpy(po->sSystemType,	pi->sSystemType,1);
		strncpy(po->sRateIndication,	pi->sRateIndication,1);
		strncpy(po->sHotBillingTag,	pi->sHotBillingTag,1);
		strncpy(po->sImei,		pi->sImei,25);
		strncpy(po->sReserve2,		pi->sReserve2,30);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sScpFlagID);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sModifyTag);
		AllTrim(po->sNbrType);
		AllTrim(po->sNbrPlan);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sDupServiceType);
		AllTrim(po->sDupServiceCode);
		AllTrim(po->sAckChannel);
		AllTrim(po->sUseChannel);
		AllTrim(po->sTransparentFlag);
		AllTrim(po->sAct1);
		AllTrim(po->sCode1);
		AllTrim(po->sAct2);
		AllTrim(po->sCode2);
		AllTrim(po->sAct3);
		AllTrim(po->sCode3);
		AllTrim(po->sAct4);
		AllTrim(po->sCode4);
		AllTrim(po->sAct5);
		AllTrim(po->sCode5);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sFlowRef);
		AllTrim(po->sTollCode);
		AllTrim(po->sOtherCode);
		AllTrim(po->sRoamFee);
		AllTrim(po->sTollFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sPayItem);
		AllTrim(po->sSystemType);
		AllTrim(po->sRateIndication);
		AllTrim(po->sHotBillingTag);
		AllTrim(po->sImei);
		AllTrim(po->sReserve2);

}
void mvitem_cri_gx2vitticket_trans(struct FVisitGsmupCricfStruct* pi,struct VisitGsmupCricfStruct* po)
{
	char sTemp[20];
	
	memset(po,0,sizeof(struct VisitGsmupCricfStruct));
	
		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sScpFlagID,		pi->sLinkRef,1);
		strncpy(po->sLinkRef,		pi->sLinkRef+1,5);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sThirdParty,	pi->sThirdParty,25);
		strncpy(po->sMsisdn,		pi->sMsisdn,25);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sReserve2,		pi->sReserve2,9);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sSystemType,	pi->sSystemType,1);
		strncpy(po->sRateIndication,	pi->sRateIndication,1);
		strncpy(po->sHotBillingTag,	pi->sHotBillingTag,1);
		strncpy(po->sImei,		pi->sImei,25);
		strncpy(po->sReserve3,		pi->sReserve3,51);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sScpFlagID);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sReserve2);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sSystemType);
		AllTrim(po->sRateIndication);
		AllTrim(po->sHotBillingTag);
		AllTrim(po->sImei);
		AllTrim(po->sReserve3);
}
void mvitem_cii_gx2vitticket(struct FVisitGsmupCiiStruct* pi,struct VisitGsmupCiiStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct VisitGsmupCiiStruct));
	
		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sInCityCode,	pi->sInCityCode,3);
		strncpy(po->sOutCityCode,	pi->sOutCityCode,3);
		strncpy(po->sLinkRef,		pi->sLinkRef,6);
		strncpy(po->sReserve1,		pi->sReserve1,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,25);
		strncpy(po->sModifyTag,		pi->sModifyTag,1);
		strncpy(po->sNbrType,		pi->sNbrType,1);
		strncpy(po->sNbrPlan,		pi->sNbrPlan,1);
		strncpy(po->sOtherParty,	pi->sOtherParty,25);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);
		strncpy(po->sDupServiceType,	pi->sDupServiceType,1);
		strncpy(po->sDupServiceCode,	pi->sDupServiceCode,2);
		strncpy(po->sAckChannel,	pi->sAckChannel,1);
		strncpy(po->sUseChannel,	pi->sUseChannel,1);
		strncpy(po->sTransparentFlag,	pi->sTransparentFlag,1);
		strncpy(po->sAct1,		pi->sAct1,1);
		strncpy(po->sCode1,		pi->sCode1,2);
		strncpy(po->sAct2,		pi->sAct2,1);
		strncpy(po->sCode2,		pi->sCode2,2);
		strncpy(po->sAct3,		pi->sAct3,1);
		strncpy(po->sCode3,		pi->sCode3,2);
		strncpy(po->sAct4,		pi->sAct4,1);
		strncpy(po->sCode4,		pi->sCode4,2);
		strncpy(po->sAct5,		pi->sAct5,1);
		strncpy(po->sCode5,		pi->sCode5,2);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sServType,		pi->sServType,1);
		strncpy(po->sStartDate,		pi->sStartDate,8);
		strncpy(po->sStartTime,		pi->sStartTime,6);
		strncpy(po->sPayUnit,		pi->sPayUnit,6);
		strncpy(po->sFlowRef,		pi->sFlowRef,6);
		strncpy(po->sFee,		pi->sFee,9);
		strncpy(po->sPayItem,		pi->sPayItem,1);
		strncpy(po->sSystemType,	pi->sSystemType,1);
		strncpy(po->sRateIndication,	pi->sRateIndication,1);
		strncpy(po->sHotBillingTag,	pi->sHotBillingTag,1);
		strncpy(po->sVhe,		pi->sVhe,1);
		strncpy(po->sInterScpFlag,	pi->sInterScpFlag,10);
		strncpy(po->sReserve2,		pi->sReserve2,16);

		AllTrim(po->sRecordType);
		AllTrim(po->sInCityCode);
		AllTrim(po->sOutCityCode);
		AllTrim(po->sLinkRef);
		AllTrim(po->sReserve1);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sModifyTag);
		AllTrim(po->sNbrType);
		AllTrim(po->sNbrPlan);
		AllTrim(po->sOtherParty);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sDupServiceType);
		AllTrim(po->sDupServiceCode);
		AllTrim(po->sAckChannel);
		AllTrim(po->sUseChannel);
		AllTrim(po->sTransparentFlag);
		AllTrim(po->sAct1);
		AllTrim(po->sCode1);
		AllTrim(po->sAct2);
		AllTrim(po->sCode2);
		AllTrim(po->sAct3);
		AllTrim(po->sCode3);
		AllTrim(po->sAct4);
		AllTrim(po->sCode4);
		AllTrim(po->sAct5);
		AllTrim(po->sCode5);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sServType);
		AllTrim(po->sStartDate);
		AllTrim(po->sStartTime);
		AllTrim(po->sPayUnit);
		AllTrim(po->sFlowRef);
		AllTrim(po->sFee);
		AllTrim(po->sPayItem);
		AllTrim(po->sSystemType);
		AllTrim(po->sRateIndication);
		AllTrim(po->sHotBillingTag);
		AllTrim(po->sVhe);
		AllTrim(po->sInterScpFlag);
		AllTrim(po->sReserve2);

}
int InsertGXGsmCri2Table(int iInsertFlag,char sTableName[],struct VisitGsmupCriStruct *pTemp)
{
	static int iFirstFlag=true;
	static struct VisitGsmupCriStructOut TempOut;
	static struct VisitGsmupCriStruct Temp;
	
	if(iFirstFlag==true){
		bzero((void*)&TempOut,sizeof(struct VisitGsmupCriStructOut));
		strcpy(TempOut.sTableName,sTableName);
		iFirstFlag=false;
	}
	
	if(iInsertFlag==true){
		if(EInsertStructToVisitGsmupCri(NULL,iInsertFlag,&TempOut)<0) return -1;
		CommitWork();
	}
	else{
		if(EInsertStructToVisitGsmupCri(pTemp,iInsertFlag,&TempOut)<0) return -1;
	}
	
	return 0;
}
int InsertGXGsmCriHz2Table(int iInsertFlag,char sTableName[],struct VisitGsmupCricfStruct *pTemp)
{
	static int iFirstFlag=true;
	static struct VisitGsmupCricfStructOut TempOut;
	static struct VisitGsmupCricfStruct Temp;
	
	if(iFirstFlag==true){
		bzero((void*)&TempOut,sizeof(struct VisitGsmupCricfStructOut));
		strcpy(TempOut.sTableName,sTableName);
		iFirstFlag=false;
	}
	
	if(iInsertFlag==true){
		if(EInsertStructToVisitGsmupCricf(NULL,iInsertFlag,&TempOut)<0) return -1;
		CommitWork();
	}
	else{
		if(EInsertStructToVisitGsmupCricf(pTemp,iInsertFlag,&TempOut)<0) return -1;
	}
	return 0;
}
int InsertGXGsmCii2Table(int iInsertFlag,char sTableName[],struct VisitGsmupCiiStruct *pTemp)
{
	static int iFirstFlag=true;
	static struct VisitGsmupCiiStructOut TempOut;
	static struct VisitGsmupCiiStruct Temp;
	
	if(iFirstFlag==true){
		bzero((void*)&TempOut,sizeof(struct VisitGsmupCiiStructOut));
		strcpy(TempOut.sTableName,sTableName);
		iFirstFlag=false;
	}
	
	if(iInsertFlag==true){
		if(EInsertStructToVisitGsmupCii(NULL,iInsertFlag,&TempOut)<0) return -1;
		CommitWork();
	}
	else{
		if(EInsertStructToVisitGsmupCii(pTemp,iInsertFlag,&TempOut)<0) return -1;
	}
	return 0;
}
int InsertGXGsm2TicketTable(char cFlag,int iInsertFlag,char sTableName[],void** pVoid)
{
	
	switch(cFlag){
		
		case 'A':
			if(InsertGXGsmCri2Table(iInsertFlag,sTableName,
				(struct VisitGsmupCriStruct *)(*pVoid))<0) return -1;
			break;
		case 'B':
			if(InsertGXGsmCriHz2Table(iInsertFlag,sTableName,
				(struct VisitGsmupCricfStruct *)(*pVoid))<0) return -1;
			break;
		case 'C':
			if(InsertGXGsmCii2Table(iInsertFlag,sTableName,
				(struct VisitGsmupCiiStruct *)(*pVoid))<0) return -1;
			break;
		default:
			break;
	}
	
}
int InsertGXGsmTicket(char sFileName[],char sTableName[])
{
	int iCnt=0;
	char sBaseName[60],sDealDate[15],sType[2],sMonth[3];
	struct UpTicketGStructOut TempOut;
	struct UpTicketGStruct Temp;
	void *pVoid;
	
	struct VisitGsmupCiiStruct CiiTmp;
	struct VisitGsmupCriStruct CriTmp;
	struct VisitGsmupCricfStruct CricfTmp;
	
	FILE *fp;
	char sTicket[TICKETBUFSIZE];

	GetBaseName(sFileName,sBaseName);

	bzero((void*)&TempOut,sizeof(struct UpTicketGStructOut));
	TempOut.iCurPos=0;

	strcpy(TempOut.sTableName,sTableName);

	if((fp=fopen(sFileName,"r"))==NULL){
		printf("File %s Open Error!\n",sFileName);
		return -1;
	}
	if(strncmp(sBaseName,"CRI",3)!=0&&
		strncmp(sBaseName,"CCF",3)!=0&&
		strncmp(sBaseName,"CII",3)!=0&&
		strncmp(sBaseName,"GBI",3)!=0&&
                strncmp(sBaseName,"QHT",3)!=0&&
                strncmp(sBaseName,"CQT",3)!=0&&
		strncmp(sBaseName,"TRI",3)!=0&&
		strncmp(sBaseName,"TII",3)!=0) return 0;

	if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
		sBaseName[strlen(sBaseName)-4]=0;

	strncpy(sDealDate,"20",2);
	strncpy(sDealDate+2,sBaseName+3,6);
	if(strncmp("CRIT",sBaseName,4)==0)
		strncpy(sDealDate+2,sBaseName+4,6);
	strcpy(sDealDate+8,"000000");
	
	strncpy(sMonth,sTableName,2);sMonth[2]=0;
	
	while(1){
		fgets(sTicket,TICKETBUFSIZE,fp);
		if(feof(fp)) break;

		if(strncmp(sTicket,"10",2)==0) continue;

		if(strncmp(sBaseName,"CRI",3)==0||
			strncmp(sBaseName,"GBI",3)==0||
			strncmp(sBaseName,"TRI",3)==0){
			strcpy(sType,"A");
			if(strncmp(sTicket,"41",2)==0){
				mvitem_cri_gx2vitticket_trans((struct FVisitGsmupCricfStruct*)&sTicket,&CricfTmp);
				strcpy(sType,"B");
				pVoid=&CricfTmp;
			}
			else{
				mvitem_cri_gx2vitticket((struct FVisitGsmupCriStruct*)&sTicket,&CriTmp);
				pVoid=&CricfTmp;
			}
		}
		else if(strncmp(sBaseName,"CCF",3)==0){
			mvitem_cri_gx2vitticket_trans((struct FVisitGsmupCricfStruct*)&sTicket,&CricfTmp);
			strcpy(sType,"B");
			pVoid=&CricfTmp;
		}
		else{
			mvitem_cii_gx2vitticket((struct FVisitGsmupCiiStruct*)&sTicket,&CiiTmp);
			strcpy(sType,"C");
			pVoid=&CiiTmp;
		}
		switch(sType[0]){
		
			case 'A':
				strcpy(CriTmp.sSourceID,sBaseName);
				if(InsertGXGsmCri2Table(false,sTableName,&CriTmp)<0) return -1;
				break;
			case 'B':
				strcpy(CricfTmp.sSourceID,sBaseName);
				if(InsertGXGsmCriHz2Table(false,sTableName,&CricfTmp)<0) return -1;
				break;
			case 'C':
				strcpy(CiiTmp.sSourceID,sBaseName);
				if(InsertGXGsmCii2Table(false,sTableName,&CiiTmp)<0) return -1;
				break;
			default:
				break;
		}

		iCnt++;

	}
		switch(sType[0]){
		
			case 'A':
				if(InsertGXGsmCri2Table(true,sTableName,NULL)<0) return -1;
				break;
			case 'B':
				if(InsertGXGsmCriHz2Table(true,sTableName,NULL)<0) return -1;
				break;
			case 'C':
				if(InsertGXGsmCii2Table(true,sTableName,NULL)<0) return -1;
				break;
			default:
				break;
		}
	printf("成功将文件%s入库到表%s",sBaseName,sTableName);

	return iCnt;

}
void mvitem_jri2vitticket(up_jri_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));



	if(pi->CallDirect=='1')/*主叫和呼转*/
		strcpy(po->sCallType,"01");
	else
		strcpy(po->sCallType,"02");

	strncpy(sTemp,pi->SpecService,5);sTemp[5]=0;
	if(strchr(sTemp,'1')!=0||
		strchr(sTemp,'V')!=0||
		strchr(sTemp,'W')!=0||
		strchr(sTemp,'X')!=0||
		strchr(sTemp,'Y')!=0||
		strchr(sTemp,'Z')!=0){

		strcpy(po->sCallType,"03");
		strncpy(po->sThirdParty,pi->Reserved7,12);
	}

	strncpy(sTemp,pi->MSSISDN_MDNLen,2);sTemp[2]=0;
	strncpy(po->sMsisdn,pi->MSSISDN_MDN,atoi(sTemp));
	po->sMsisdn[15]=0;
	AllTrim(po->sMsisdn);

		strncpy(po->sCalledCode,	pi->OppCity,3);
		AllTrim(po->sCalledCode);
		strncpy(po->sOtherParty,	pi->OppNum,24);
		AllTrim(po->sOtherParty);

		strncpy(po->sVisitAreaCode,	pi->CityCode,3);
		AllTrim(po->sVisitAreaCode);

		strncpy(sTemp,pi->RoamCharge,10);sTemp[10]=0;
		po->iRoamFee=			atoi(sTemp);
		strncpy(sTemp,pi->LandCharge,10);sTemp[10]=0;
		po->iTollFee=			atoi(sTemp);
		strncpy(sTemp,pi->OtherCharge,10);sTemp[10]=0;
		po->iAddFee=			atoi(sTemp);
		strncpy(sTemp,pi->RoamCallTime,6);sTemp[6]=0;
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,		"20",2);
		strncpy(po->sStartTime+2,	pi->CallDate,6);
		strncpy(po->sStartTime+8,	pi->RoamLinkTime,6);

		strncpy(po->sRoamType,		"2",1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}
		strncpy(po->sUserType,		"2",1);

		strncpy(po->sImsi,		pi->MSID,15);
		strncpy(po->sMsrn,		pi->TempNum,15);
		AllTrim(po->sMsrn);
		strncpy(po->sMsc,		pi->MAD,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		" ",5);
		strncpy(po->sCellID,		pi->CellOri_A,5);

	if(strcmp(po->sCallType,"01")==0||
		strcmp(po->sCallType,"02")==0){

		strcpy(po->sServiceType,"000");
		strcpy(po->sServiceCode,"0011");
	}
	else{
		strcpy(po->sServiceType,"002");

		strncpy(sTemp,pi->SpecService,5);sTemp[5]=0;

		if(strchr(sTemp,'X')!=NULL)
			strcpy(po->sServiceCode,"0029");
		else if(strchr(sTemp,'1')!=NULL)
			strcpy(po->sServiceCode,"0020");
		else if(strchr(sTemp,'V')!=NULL)
			strcpy(po->sServiceCode,"0021");
		else if(strchr(sTemp,'W')!=NULL)
			strcpy(po->sServiceCode,"0028");
		else if(strchr(sTemp,'Y')!=NULL)
			strcpy(po->sServiceCode,"002A");
		else if(strchr(sTemp,'Z')!=NULL)
			strcpy(po->sServiceCode,"002B");
		else
			strcpy(po->sServiceCode,"0021");

	}
		strcpy(po->sSupplementCode,	"");
}
void mvitem_jii2vitticket(up_jii_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));

	if(pi->CallDirect=='1')/*主叫和呼转*/
		strcpy(po->sCallType,"01");
	else
		strcpy(po->sCallType,"02");

	strncpy(sTemp,pi->MSSISDN_MDNLen,2);sTemp[2]=0;
	strncpy(po->sMsisdn,pi->MSSISDN_MDN,atoi(sTemp));
	po->sMsisdn[15]=0;
	AllTrim(po->sMsisdn);

		strncpy(po->sCalledCode,	pi->OppCity,3);
		AllTrim(po->sCalledCode);
		strncpy(po->sOtherParty,	pi->OppNum,24);
		AllTrim(po->sOtherParty);

		strncpy(po->sHomeAreaCode,	pi->SID_BID,3);
		AllTrim(po->sHomeAreaCode);

		strncpy(po->sVisitAreaCode,	pi->SID_BID,5);
		AllTrim(po->sVisitAreaCode);
		TrimLeftX(po->sVisitAreaCode,'0');

		strncpy(sTemp,pi->RoamCharge,10);sTemp[10]=0;
		po->iRoamFee=			atoi(sTemp);
		strncpy(sTemp,pi->LandCharge,10);sTemp[10]=0;
		po->iTollFee=			atoi(sTemp);
		strncpy(sTemp,pi->OtherCharge,10);sTemp[10]=0;
		po->iAddFee=			atoi(sTemp);
		strncpy(sTemp,pi->RoamCallTime,6);sTemp[6]=0;
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,		"20",2);
		strncpy(po->sStartTime+2,	pi->CallDate,6);
		strncpy(po->sStartTime+8,	pi->RoamLinkTime,6);


		strncpy(po->sRoamType,		"3",1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}
		strncpy(po->sUserType,		"2",1);

		strncpy(po->sImsi,		pi->MSID,15);
		strncpy(po->sMsrn,		pi->TempNum,15);
		AllTrim(po->sMsrn);
		strncpy(po->sMsc,		pi->MAD,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		" ",5);
		strncpy(po->sCellID,		pi->CellOri_A,5);

		strcpy(po->sServiceType,"000");
		strcpy(po->sServiceCode,"0011");
		strcpy(po->sSupplementCode,	"");
}
int InsertCdmaTicket(char sFileName[],char sTableName[])
{
	int iCnt=0;
	char sBaseName[60],sDealDate[15];
	struct UpTicketGStructOut TempOut;
	struct UpTicketGStruct Temp;
	FILE *fp;
	char sTicket[TICKETBUFSIZE];

	GetBaseName(sFileName,sBaseName);

	bzero((void*)&TempOut,sizeof(struct UpTicketGStructOut));
	TempOut.iCurPos=0;

	strcpy(TempOut.sTableName,sTableName);

	if((fp=fopen(sFileName,"r"))==NULL){
		printf("File %s Open Error!\n",sFileName);
		return -1;
	}
	if(strncmp(sBaseName,"JRI",3)!=0&&
		strncmp(sBaseName,"JII",3)!=0&&
		strncmp(sBaseName,"CBI",3)!=0&&
                strncmp(sBaseName,"QHT",3)!=0&&
                strncmp(sBaseName,"CQT",3)!=0&&
		strncmp(sBaseName,"QRI",3)!=0&&
		strncmp(sBaseName,"QII",3)!=0) return 0;

	if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
		sBaseName[strlen(sBaseName)-4]=0;

	strncpy(sDealDate,"20",2);
	strncpy(sDealDate+2,sBaseName+3,6);
	if(strncmp("JRIT",sBaseName,4)==0)
		strncpy(sDealDate+2,sBaseName+4,6);
	strcpy(sDealDate+8,"000000");

	while(1){
		fgets(sTicket,TICKETBUFSIZE,fp);
		if(feof(fp)) break;
		if(strncmp(sTicket,"22",2)!=0) continue;

		if(strncmp(sBaseName,"JRI",3)==0||
			strncmp(sBaseName,"CBI",3)==0||
			strncmp(sBaseName,"CQT",3)==0||
			strncmp(sBaseName,"QHT",3)==0||
			strncmp(sBaseName,"QRI",3)==0)
			mvitem_jri2vitticket((up_jri_buf*)&sTicket,&Temp);
		else
			mvitem_jii2vitticket((up_jii_buf*)&sTicket,&Temp);

		strcpy(Temp.sDealDate,sDealDate);
		strcpy(Temp.sSourceID,sBaseName);

		GetImsiArea(Temp.sImsi,"C",Temp.sStartTime,Temp.sHomeAreaCode);
		if(strcmp(Temp.sHomeAreaCode,"086")==0||
			strlen(Temp.sHomeAreaCode)==0)
			GetBelongCode(Temp.sMsisdn,Temp.sStartTime,Temp.sHomeAreaCode);

		if(EInsertStructToUpTicketG(&Temp,FALSE,&TempOut)<0)return -1;

		iCnt++;
	}
	if(EInsertStructToUpTicketG(NULL,TRUE,&TempOut)<0) return -1;


	printf("成功将文件%s入库到表%s",sBaseName,sTableName);

	return iCnt;
}
void mvitem_fmt193ticket(struct FT193TicketStruct *pi,struct T193TicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct T193TicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,20);
		strncpy(po->sOtherParty,	pi->sOtherParty,20);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,5);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,5);

		AllTrim(po->sCallType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCalledAreaCode);
}
int Insert193Ticket(char sFileName[],char sTableName[])
{
	int iCnt=0,l;
	char	sBaseName[128],sHostDate[15];
	struct T193TicketStruct	Temp;
	struct T193TicketStructOut TempOut;
	struct FileControlStruct *ptHead,*pTemp,*ptLkHead;
	struct T130AreaCodeStruct *pT130=NULL;

	GetHostTime(sHostDate);
	GetBaseName(sFileName,sBaseName);
	if(strlen(sBaseName)>4){
		if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
			sBaseName[strlen(sBaseName)-4]=0;
	}

	bzero((void*)&TempOut,sizeof(struct T193TicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmt193ticket((struct FT193TicketStruct *)(pTemp->pData),&Temp);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);
		if(IS_MOB_NBR(Temp.sMsisdn)){
			 if(SearchT130AreaCode(Temp.sMsisdn,
				Temp.sDealDate,&pT130)==FOUND)
			 	strcpy(Temp.sHomeAreaCode,pT130->sAreaCode);
			 else	strcpy(Temp.sHomeAreaCode,Temp.sCallingAreaCode);
		}
		if(EInsertStructToT193Ticket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToT193Ticket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmsmscticket(struct FSmscTicketStruct *pi,int len,
	struct SmscTicketStruct *po)
{
	char sTemp[128];
	bzero((void*)po,sizeof(struct SmscTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sCityCode,		pi->sCityCode,5);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sSmsp,		pi->sSmsp,15);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sFee,		pi->sFee,6);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);

		strncpy(sTemp,pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=		atoi(sTemp);

		if(len==sizeof(struct FSmscTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
		}

		AllTrim(po->sCityCode);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sMsc);
		AllTrim(po->sSmsp);
		AllTrim(po->sUserType);
		AllTrim(po->sServiceCode);

		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);

}
int InsertSmscTicket(char sFileName[],char sTableName[])
{
	int iCnt=0,l;
	char	sBaseName[128],sHostDate[15];
	struct SmscTicketStruct	Temp;
	struct SmscTicketStructOut TempOut;
	struct FileControlStruct *ptHead,*pTemp,*ptLkHead;
	struct T130AreaCodeStruct *pT130=NULL;

	GetHostTime(sHostDate);
	GetBaseName(sFileName,sBaseName);
	if(strlen(sBaseName)>4){
		if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
			sBaseName[strlen(sBaseName)-4]=0;
	}
	bzero((void*)&TempOut,sizeof(struct SmscTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmsmscticket((struct FSmscTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		/*if(IS_MOB_NBR(Temp.sMsisdn)){
			 if(SearchT130AreaCode(Temp.sMsisdn,
				Temp.sDealDate,&pT130)==FOUND)
			 	strcpy(Temp.sCityCode,pT130->sAreaCode);
		}*/

		if(EInsertStructToSmscTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSmscTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}
	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmsmspticket(struct FSmspTicketStruct *pi,int len,
	struct SmspTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SmspTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sCityCode,		pi->sCityCode,5);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sSmsp,		pi->sSmsp,15);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,10);
		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sFee1,		pi->sFee1,6);
		strncpy(po->sFee2,		pi->sFee2,6);
		strncpy(po->sFee3,		pi->sFee3,6);
		strncpy(po->sFee4,		pi->sFee4,6);
		strncpy(po->sFee5,		pi->sFee5,8);
		strncpy(po->sFee6,		pi->sFee6,8);

		strncpy(sTemp,			pi->sTicketTypeID,4); sTemp[4]=0;
		po->iTicketTypeID=		atoi(sTemp);

		if(len==sizeof(struct FSmspTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
		}

		AllTrim(po->sCallType);
		AllTrim(po->sCityCode);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sSmsp);
		AllTrim(po->sUserType);
		AllTrim(po->sSpAccNbr);
		AllTrim(po->sSpServiceCode);
		AllTrim(po->sSpCode);
		AllTrim(po->sFee1);
		AllTrim(po->sFee2);
		AllTrim(po->sFee3);
		AllTrim(po->sFee4);
		AllTrim(po->sFee5);
		AllTrim(po->sFee6);

		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);
}
int InsertSmspTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct SmspTicketStruct Temp;
	struct SmspTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct SmspTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmsmspticket((struct FSmspTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToSmspTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSmspTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}
	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmgprsticket(struct FGprsTicketStruct *pi,int len,
	struct GprsTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct GprsTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sNiPdp,		pi->sNiPdp,1);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sSgsn,		pi->sSgsn,8);
		strncpy(po->sMsnc,		pi->sMsnc,1);
		strncpy(po->sLac,		pi->sLac,4);
		strncpy(po->sRouteArea,		pi->sRouteArea,4);
		strncpy(po->sCellID,		pi->sCellID,4);
		strncpy(po->sChargingID,	pi->sChargingID,8);
		strncpy(po->sGgsn,		pi->sGgsn,8);
		strncpy(po->sApnNi,		pi->sApnNi,63);
		strncpy(po->sApnOi,		pi->sApnOi,37);
		strncpy(po->sPdpType,		pi->sPdpType,1);
		strncpy(po->sServedPdpAddress,	pi->sServedPdpAddress,16);
		strncpy(po->sSgsnChange,	pi->sSgsnChange,1);
		strncpy(po->sCloseCause,	pi->sCloseCause,1);
		strncpy(po->sResult,		pi->sResult,1);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,9);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,9);
		strncpy(po->sUserType,		pi->sUserType,2);
		strncpy(po->sFeeType,		pi->sFeeType,2);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sCallDuration,	pi->sCallDuration,6);
		strncpy(po->sTariff1,		pi->sTariff1,1);
		strncpy(po->sDataFlowup1,	pi->sDataFlowup1,10);
		strncpy(po->sDataFlowdn1,	pi->sDataFlowdn1,10);
		strncpy(po->sDuration1,		pi->sDuration1,6);
		strncpy(po->sTariff2,		pi->sTariff2,1);
		strncpy(po->sDataFlowup2,	pi->sDataFlowup2,10);
		strncpy(po->sDataFlowdn2,	pi->sDataFlowdn2,10);
		strncpy(po->sDuration2,		pi->sDuration2,6);
		strncpy(po->sTariff3,		pi->sTariff3,1);
		strncpy(po->sDataFlowup3,	pi->sDataFlowup3,10);
		strncpy(po->sDataFlowdn3,	pi->sDataFlowdn3,10);
		strncpy(po->sDuration3,		pi->sDuration3,6);
		strncpy(po->sTariff4,		pi->sTariff4,1);
		strncpy(po->sDataFlowup4,	pi->sDataFlowup4,10);
		strncpy(po->sDataFlowdn4,	pi->sDataFlowdn4,10);
		strncpy(po->sDuration4,		pi->sDuration4,6);
		strncpy(po->sTariff5,		pi->sTariff5,1);
		strncpy(po->sDataFlowup5,	pi->sDataFlowup5,10);
		strncpy(po->sDataFlowdn5,	pi->sDataFlowdn5,10);
		strncpy(po->sDuration5,		pi->sDuration5,6);
		strncpy(po->sTariff6,		pi->sTariff6,1);
		strncpy(po->sDataFlowup6,	pi->sDataFlowup6,10);
		strncpy(po->sDataFlowdn6,	pi->sDataFlowdn6,10);
		strncpy(po->sDuration6,		pi->sDuration6,6);
		strncpy(po->sCfee,		pi->sCfee,8);
		strncpy(po->sFee1,		pi->sFee1,8);
		strncpy(po->sFee2,		pi->sFee2,8);
		strncpy(po->sFee3,		pi->sFee3,8);
		strncpy(po->sTotalFee,		pi->sTotalFee,9);

		strncpy(sTemp,		pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=	atoi(sTemp);

		if(len==sizeof(struct FGprsTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
		}

		AllTrim(po->sRecordType);
		AllTrim(po->sNiPdp);
		AllTrim(po->sMsisdn);
		AllTrim(po->sImsi);
		AllTrim(po->sSgsn);
		AllTrim(po->sMsnc);
		AllTrim(po->sLac);
		AllTrim(po->sRouteArea);
		AllTrim(po->sCellID);
		AllTrim(po->sChargingID);
		AllTrim(po->sGgsn);
		AllTrim(po->sApnNi);
		AllTrim(po->sApnOi);
		AllTrim(po->sPdpType);
		AllTrim(po->sServedPdpAddress);
		AllTrim(po->sSgsnChange);
		AllTrim(po->sCloseCause);
		AllTrim(po->sResult);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sUserType);
		AllTrim(po->sFeeType);
		AllTrim(po->sRoamType);
		AllTrim(po->sServiceType);
		AllTrim(po->sStartTime);
		AllTrim(po->sCallDuration);
		AllTrim(po->sTariff1);
		AllTrim(po->sDataFlowup1);
		AllTrim(po->sDataFlowdn1);
		AllTrim(po->sDuration1);
		AllTrim(po->sTariff2);
		AllTrim(po->sDataFlowup2);
		AllTrim(po->sDataFlowdn2);
		AllTrim(po->sDuration2);
		AllTrim(po->sTariff3);
		AllTrim(po->sDataFlowup3);
		AllTrim(po->sDataFlowdn3);
		AllTrim(po->sDuration3);
		AllTrim(po->sTariff4);
		AllTrim(po->sDataFlowup4);
		AllTrim(po->sDataFlowdn4);
		AllTrim(po->sDuration4);
		AllTrim(po->sTariff5);
		AllTrim(po->sDataFlowup5);
		AllTrim(po->sDataFlowdn5);
		AllTrim(po->sDuration5);
		AllTrim(po->sTariff6);
		AllTrim(po->sDataFlowup6);
		AllTrim(po->sDataFlowdn6);
		AllTrim(po->sDuration6);
		AllTrim(po->sCfee);
		AllTrim(po->sFee1);
		AllTrim(po->sFee2);
		AllTrim(po->sFee3);
		AllTrim(po->sTotalFee);

		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);
}
int InsertGprsTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct GprsTicketStruct Temp;
	struct GprsTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct GprsTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmgprsticket((struct FGprsTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToGprsTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToGprsTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
/*added by ccq 20140509*/
void mvitem_fmgprsticketnew(struct FGprsTicketNewStruct *pi,struct GprsTicketNewStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct GprsTicketNewStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sRoamType,		pi->sRoamType,2);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sSgsn,		pi->sSgsn,16);
		strncpy(po->sSgsnChange,	pi->sSgsnChange,1);
		strncpy(po->sGgsn,		pi->sGgsn,16);
		strncpy(po->sServedPdpAddress,	pi->sServedPdpAddress,16);
		strncpy(po->sApnNi,		pi->sApnNi,63);
		strncpy(po->sApnOi,		pi->sApnOi,37);
		strncpy(po->sReserv1,		pi->sReserv1,14);

		strncpy(sTemp,	pi->sCallDuration,6);sTemp[6]=0;
		po->iCallDuration=atoi(sTemp);

		strncpy(po->sPartialType,	pi->sPartialType,1);
		strncpy(po->sCloseCause,	pi->sCloseCause,2);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sNiPdp,		pi->sNiPdp,1);
		strncpy(po->sChargingID,	pi->sChargingID,10);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
		strncpy(po->sReserv2,		pi->sReserv2,10);
		strncpy(po->sRoamRemark,	pi->sRoamRemark,10);
		strncpy(po->sImei,		pi->sImei,19);
		strncpy(po->sDataFlowdn,	pi->sDataFlowdn,20);
		strncpy(po->sDataFlowup,	pi->sDataFlowup,20);
		strncpy(po->sChargeItem,	pi->sChargeItem,1);
		strncpy(po->sChargeUnit,	pi->sChargeUnit,20);
		strncpy(po->sChargeOperation,	pi->sChargeOperation,2);

		strncpy(sTemp,		pi->sTotalFee,9);sTemp[9]=0;
		po->iTotalFee=atoi(sTemp);

		strncpy(po->sReserv3,		pi->sReserv3,63);

		AllTrim(po->sRecordType);
		AllTrim(po->sRoamType);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sSgsn);
		AllTrim(po->sSgsnChange);
		AllTrim(po->sGgsn);
		AllTrim(po->sServedPdpAddress);
		AllTrim(po->sApnNi);
		AllTrim(po->sApnOi);
		AllTrim(po->sPartialType);
		AllTrim(po->sCloseCause);
		AllTrim(po->sStartTime);
		AllTrim(po->sNiPdp);
		AllTrim(po->sChargingID);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sReserv2);
		AllTrim(po->sRoamRemark);
		AllTrim(po->sImei);
		AllTrim(po->sDataFlowdn);
		AllTrim(po->sDataFlowup);
		AllTrim(po->sChargeItem);
		AllTrim(po->sChargeUnit);
		AllTrim(po->sChargeOperation);
		AllTrim(po->sReserv3);
}
int InsertGprsTicketNew(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iRet=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct GprsTicketNewStruct Temp;
	struct GprsTicketNewStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc,sCode[15];


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct GprsTicketNewStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmgprsticketnew((struct FGprsTicketNewStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);
		strcpy(Temp.sState,'\0');
		/*获取区号*/		
		if(GetHomeAreaCode(Temp.sMsisdn,Temp.sImsi,Temp.sVisitCityCode,
			1,Temp.sStartTime,&iRet,sCode)==NOTFOUND)			
			return iRet;
		strcpy(Temp.sReserv1,sCode);
		
		if(EInsertStructToGprsTicketNew(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToGprsTicketNew(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
/*added end 20140509*/
void mvitem_fmcdmaticketfj(struct FCdmaTicketFjStruct *pi,struct CdmaTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct CdmaTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,11);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sEsn,		pi->sEsn,11);
		strncpy(po->sOtherParty,	pi->sOtherParty,21);
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sThirdParty,	pi->sThirdParty,21);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sOtherLac,		pi->sOtherLac,5);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,5);
		strncpy(po->sAppendServiceCode,	pi->sAppendServiceCode,2);
		strncpy(po->sEndReason,		pi->sEndReason,1);
		strncpy(po->sDeformityFlag,	pi->sDeformityFlag,1);
		strncpy(po->sRoamFee,		pi->sRoamFee,8);
		strncpy(po->sRoamDuration,	pi->sRoamDuration,6);
		strncpy(po->sRoamRateType,	pi->sRoamRateType,1);
		strncpy(po->sTollFee,		pi->sTollFee,8);
		strncpy(po->sTollDuration,	pi->sTollDuration,6);
		strncpy(po->sTollFeeType,	pi->sTollFeeType,1);
		strncpy(po->sInfoFee,		pi->sInfoFee,8);
		strncpy(po->sOtherFee,		pi->sOtherFee,8);
		strncpy(po->sOppCityCode,	pi->sOppCityCode,3);
		strncpy(po->sOppProvCode,	pi->sOppProvCode,3);
		strncpy(po->sOppCountryCode,	pi->sOppCountryCode,3);
		strncpy(po->sTollType,		pi->sTollType,1);
		strncpy(po->sTollNetType,	pi->sTollNetType,1);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sActCode,		pi->sActCode,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);

		AllTrim(po->sRecordType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sImsi);
		AllTrim(po->sEsn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sThirdParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sAppendServiceCode);
		AllTrim(po->sEndReason);
		AllTrim(po->sDeformityFlag);
		AllTrim(po->sRoamFee);
		AllTrim(po->sRoamDuration);
		AllTrim(po->sRoamRateType);
		AllTrim(po->sTollFee);
		AllTrim(po->sTollDuration);
		AllTrim(po->sTollFeeType);
		AllTrim(po->sInfoFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sOppCityCode);
		AllTrim(po->sOppProvCode);
		AllTrim(po->sOppCountryCode);
		AllTrim(po->sTollType);
		AllTrim(po->sTollNetType);
		AllTrim(po->sRoamType);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sUserType);
		AllTrim(po->sActCode);
		AllTrim(po->sServiceCode);
}
void mvitem_fmcdmaticketxj(struct FCdmaTicketXjStruct *pi,struct CdmaTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct CdmaTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,11);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sEsn,		pi->sEsn,11);
		strncpy(po->sOtherParty,	pi->sOtherParty,21);
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sThirdParty,	pi->sThirdParty,21);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sOtherLac,		pi->sOtherLac,5);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,5);
		strncpy(po->sAppendServiceCode,	pi->sAppendServiceCode,2);
		strncpy(po->sEndReason,		pi->sEndReason,1);
		strncpy(po->sDeformityFlag,	pi->sDeformityFlag,1);
		strncpy(po->sRoamFee,		pi->sRoamFee,8);
		strncpy(po->sRoamDuration,	pi->sRoamDuration,6);
		strncpy(po->sRoamRateType,	pi->sRoamRateType,1);
		strncpy(po->sTollFee,		pi->sTollFee,8);
		strncpy(po->sTollDuration,	pi->sTollDuration,6);
		strncpy(po->sTollFeeType,	pi->sTollFeeType,1);
		strncpy(po->sInfoFee,		pi->sInfoFee,8);
		strncpy(po->sOtherFee,		pi->sOtherFee,8);
		strncpy(po->sOppCityCode,	pi->sOppCityCode,3);
		strncpy(po->sOppProvCode,	pi->sOppProvCode,3);
		strncpy(po->sOppCountryCode,	pi->sOppCountryCode,3);
		strncpy(po->sTollType,		pi->sTollType,1);
		strncpy(po->sTollNetType,	pi->sTollNetType,1);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sActCode,		pi->sActCode,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);

		AllTrim(po->sRecordType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sImsi);
		AllTrim(po->sEsn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sThirdParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sAppendServiceCode);
		AllTrim(po->sEndReason);
		AllTrim(po->sDeformityFlag);
		AllTrim(po->sRoamFee);
		AllTrim(po->sRoamDuration);
		AllTrim(po->sRoamRateType);
		AllTrim(po->sTollFee);
		AllTrim(po->sTollDuration);
		AllTrim(po->sTollFeeType);
		AllTrim(po->sInfoFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sOppCityCode);
		AllTrim(po->sOppProvCode);
		AllTrim(po->sOppCountryCode);
		AllTrim(po->sTollType);
		AllTrim(po->sTollNetType);
		AllTrim(po->sRoamType);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sUserType);
		AllTrim(po->sActCode);
		AllTrim(po->sServiceCode);
}
void mvitem_fmcdmaticket(struct FCdmaTicketStruct *pi,struct CdmaTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct CdmaTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sEsn,		pi->sEsn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,21);
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sThirdParty,	pi->sThirdParty,21);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sOtherLac,		pi->sOtherLac,5);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,5);
		strncpy(po->sAppendServiceCode,	pi->sAppendServiceCode,2);
		strncpy(po->sEndReason,		pi->sEndReason,1);
		strncpy(po->sDeformityFlag,	pi->sDeformityFlag,1);
		strncpy(po->sRoamFee,		pi->sRoamFee,8);
		strncpy(po->sRoamDuration,	pi->sRoamDuration,6);
		strncpy(po->sRoamRateType,	pi->sRoamRateType,1);
		strncpy(po->sTollFee,		pi->sTollFee,8);
		strncpy(po->sTollDuration,	pi->sTollDuration,6);
		strncpy(po->sTollFeeType,	pi->sTollFeeType,1);
		strncpy(po->sInfoFee,		pi->sInfoFee,8);
		strncpy(po->sOtherFee,		pi->sOtherFee,8);
		strncpy(po->sOppCityCode,	pi->sOppCityCode,3);
		strncpy(po->sOppProvCode,	pi->sOppProvCode,3);
		strncpy(po->sOppCountryCode,	pi->sOppCountryCode,3);
		strncpy(po->sTollType,		pi->sTollType,1);
		strncpy(po->sTollNetType,	pi->sTollNetType,1);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sActCode,		pi->sActCode,1);
		strncpy(po->sServiceCode,	pi->sServiceCode,2);

		strncpy(po->sCalledType,	pi->sCalledType,3);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,10);
		strncpy(po->sUserType1,		pi->sUserType1,2);
		strncpy(po->sReserve,		pi->sReserve,18);

		AllTrim(po->sRecordType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sImsi);
		AllTrim(po->sEsn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sThirdParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sAppendServiceCode);
		AllTrim(po->sEndReason);
		AllTrim(po->sDeformityFlag);
		AllTrim(po->sRoamFee);
		AllTrim(po->sRoamDuration);
		AllTrim(po->sRoamRateType);
		AllTrim(po->sTollFee);
		AllTrim(po->sTollDuration);
		AllTrim(po->sTollFeeType);
		AllTrim(po->sInfoFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sOppCityCode);
		AllTrim(po->sOppProvCode);
		AllTrim(po->sOppCountryCode);
		AllTrim(po->sTollType);
		AllTrim(po->sTollNetType);
		AllTrim(po->sRoamType);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sUserType);
		AllTrim(po->sActCode);
		AllTrim(po->sServiceCode);

		AllTrim(po->sCalledType);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sUserType1);
		AllTrim(po->sReserve);
}
int InsertCdmaBillTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct CdmaTicketStruct Temp;
	struct CdmaTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct CdmaTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if(strncmp((char *)(pTemp->pData),"02",2)==0)continue;
		}

		if(pTemp->iLen==sizeof(struct FCdmaTicketStruct))
			mvitem_fmcdmaticket((struct FCdmaTicketStruct *)(pTemp->pData),&Temp);
		else if(pTemp->iLen==sizeof(struct FCdmaTicketFjStruct))
			mvitem_fmcdmaticketfj((struct FCdmaTicketFjStruct *)(pTemp->pData),&Temp);
		else
			mvitem_fmcdmaticketxj((struct FCdmaTicketXjStruct *)(pTemp->pData),&Temp);

		if(strlen(Temp.sHomeAreaCode)==0){
			int i=0;
			char sVisitAreaCode[10];

			strcpy(sVisitAreaCode,"");
			GetAreaCode(Temp.sVisitCityCode,sVisitAreaCode);

			GetHomeAreaCode(Temp.sMsisdn,Temp.sImsi,sVisitAreaCode,1,
				Temp.sStartTime,&i,Temp.sHomeAreaCode);
		}

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToCdmaTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToCdmaTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmcdma1xticket(struct FCdma1xTicketStruct *pi,int len,
	struct Cdma1xTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct Cdma1xTicketStruct));

		strncpy(po->sRecordType,		pi->sRecordType,2);
		strncpy(po->sSeqNumber,			pi->sSeqNumber,10);
		strncpy(po->sMdn,			pi->sMdn,20);
		strncpy(po->sMsisdn,			pi->sMsisdn,15);
		strncpy(po->sEsn,			pi->sEsn,19);
		strncpy(po->sIp,			pi->sIp,15);
		strncpy(po->sNai,			pi->sNai,64);
		strncpy(po->sUserType,			pi->sUserType,1);
		strncpy(po->sNaiAreaCode,		pi->sNaiAreaCode,3);
		strncpy(po->sRoamType,			pi->sRoamType,1);
		strncpy(po->sIpTechType,		pi->sIpTechType,1);
		strncpy(po->sAccountSessionID,		pi->sAccountSessionID,8);
		strncpy(po->sCorrelationID,		pi->sCorrelationID,8);
		strncpy(po->sHaip,			pi->sHaip,15);
		strncpy(po->sPdsnip,			pi->sPdsnip,15);
		strncpy(po->sPcfip,			pi->sPcfip,15);
		strncpy(po->sBsid,			pi->sBsid,12);
		strncpy(po->sUzid,			pi->sUzid,10);
		strncpy(po->sServiceOption,		pi->sServiceOption,2);
		strncpy(po->sCompulsoryTunnel,		pi->sCompulsoryTunnel,1);
		strncpy(po->sEndRelease,		pi->sEndRelease,1);
		strncpy(po->sDataCountTermination,	pi->sDataCountTermination,10);
		strncpy(po->sDataCountOrigination,	pi->sDataCountOrigination,10);
		strncpy(po->sBadFrameCount,		pi->sBadFrameCount,10);
		strncpy(po->sStartTime,			pi->sStartTime,14);
		strncpy(po->sStopTime,			pi->sStopTime,14);
		strncpy(po->sActiveTime,		pi->sActiveTime,10);
		strncpy(po->sActionCount,		pi->sActionCount,10);
		strncpy(po->sSdbCountTermination,	pi->sSdbCountTermination,10);
		strncpy(po->sSdbCountOrigination,	pi->sSdbCountOrigination,10);
		strncpy(po->sSdbTerminationnum,		pi->sSdbTerminationnum,10);
		strncpy(po->sSdbOriginationnum,		pi->sSdbOriginationnum,10);
		strncpy(po->sPdsnReceiveNum,		pi->sPdsnReceiveNum,10);
		strncpy(po->sMipReceiveNum,		pi->sMipReceiveNum,10);
		strncpy(po->sMipSendNum,		pi->sMipSendNum,10);
		strncpy(po->sIpqos,			pi->sIpqos,10);
		strncpy(po->sAirlinkqos,		pi->sAirlinkqos,10);

		strncpy(sTemp,		pi->sBaseCharge,8);sTemp[8]=0;
		po->iBaseCharge=atoi(sTemp);
		strncpy(sTemp,		pi->sFluxCharge,8);sTemp[8]=0;
		po->iFluxCharge=atoi(sTemp);
		strncpy(sTemp,		pi->sOtherCharge,8);sTemp[8]=0;
		po->iOtherCharge=atoi(sTemp);

		strncpy(po->sHomeCountryCode,		pi->sHomeCountryCode,5);
		strncpy(po->sHomeOperatorCode,		pi->sHomeOperatorCode,5);
		strncpy(po->sVisitCountryCode,		pi->sVisitCountryCode,5);
		strncpy(po->sVisitOperatoCode,		pi->sVisitOperatoCode,5);
		strncpy(po->sRatingRuleID,		pi->sRatingRuleID,8);

		if(len>460){
		strncpy(po->sNoused1,			pi->sNoused1,10);
		strncpy(po->sNoused2,			pi->sNoused2,10);
		strncpy(po->sNoused3,			pi->sNoused3,10);
		}
		if(len>488){
		strncpy(sTemp,		pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);
		strncpy(po->sHomeAreaCode,		pi->sHomeAreaCode,5);
		}
		if(len==sizeof(struct FCdma1xTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
		}



		AllTrim(po->sRecordType);
		AllTrim(po->sSeqNumber);
		AllTrim(po->sMdn);
		AllTrim(po->sMsisdn);
		AllTrim(po->sEsn);
		AllTrim(po->sIp);
		AllTrim(po->sNai);
		AllTrim(po->sUserType);
		AllTrim(po->sNaiAreaCode);
		AllTrim(po->sRoamType);
		AllTrim(po->sIpTechType);
		AllTrim(po->sAccountSessionID);
		AllTrim(po->sCorrelationID);
		AllTrim(po->sHaip);
		AllTrim(po->sPdsnip);
		AllTrim(po->sPcfip);
		AllTrim(po->sBsid);
		AllTrim(po->sUzid);
		AllTrim(po->sServiceOption);
		AllTrim(po->sCompulsoryTunnel);
		AllTrim(po->sEndRelease);
		AllTrim(po->sDataCountTermination);
		AllTrim(po->sDataCountOrigination);
		AllTrim(po->sBadFrameCount);
		AllTrim(po->sStartTime);
		AllTrim(po->sStopTime);
		AllTrim(po->sActiveTime);
		AllTrim(po->sActionCount);
		AllTrim(po->sSdbCountTermination);
		AllTrim(po->sSdbCountOrigination);
		AllTrim(po->sSdbTerminationnum);
		AllTrim(po->sSdbOriginationnum);
		AllTrim(po->sPdsnReceiveNum);
		AllTrim(po->sMipReceiveNum);
		AllTrim(po->sMipSendNum);
		AllTrim(po->sIpqos);
		AllTrim(po->sAirlinkqos);

		AllTrim(po->sHomeCountryCode);
		AllTrim(po->sHomeOperatorCode);
		AllTrim(po->sVisitCountryCode);
		AllTrim(po->sVisitOperatoCode);
		AllTrim(po->sRatingRuleID);
		AllTrim(po->sNoused1);
		AllTrim(po->sNoused2);
		AllTrim(po->sNoused3);

		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);

}
int InsertCdma1xTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct Cdma1xTicketStruct Temp;
	struct Cdma1xTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct Cdma1xTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if(strncmp((char *)(pTemp->pData),"01",2)==0)continue;
		}

		mvitem_fmcdma1xticket((struct FCdma1xTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToCdma1xTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToCdma1xTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmgsmrateticket(struct FGsmRateTicketStruct *pi,struct GsmRateTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct GsmRateTicketStruct));

		strncpy(po->sTicketID,			pi->sTicketID,10);
		strncpy(po->sMsisdn,			pi->sMsisdn,15);
		strncpy(po->sImsi,			pi->sImsi,15);
		strncpy(po->sCityCode,			pi->sCityCode,4);
		strncpy(po->sMonth,			pi->sMonth,2);
		strncpy(po->sBillMonth,			pi->sBillMonth,6);
		strncpy(po->sCallType,			pi->sCallType,2);
		strncpy(po->sStartTime,			pi->sStartTime,14);
		strncpy(po->sEndReason,			pi->sEndReason,1);
		strncpy(po->sDeformFlag,		pi->sDeformFlag,1);
		strncpy(po->sOtherParty,		pi->sOtherParty,21);
		strncpy(po->sCalledCode,		pi->sCalledCode,4);

		strncpy(sTemp,			pi->sDuration,6);sTemp[6]=0;
		po->iDuration=atoi(sTemp);

		strncpy(po->sMsc,			pi->sMsc,10);
		strncpy(po->sCellID,			pi->sCellID,5);
		strncpy(po->sOtherCellID,		pi->sOtherCellID,5);
		strncpy(po->sTrunkIn,			pi->sTrunkIn,7);
		strncpy(po->sTrunkOut,			pi->sTrunkOut,7);
		strncpy(po->sTollType,			pi->sTollType,1);
		strncpy(po->sRoamType,			pi->sRoamType,1);
		strncpy(po->sTollNetType,		pi->sTollNetType,1);
		strncpy(po->sValueAddBusi,		pi->sValueAddBusi,2);
		strncpy(po->sGroupID,			pi->sGroupID,5);
		strncpy(po->sSameGroupFlag,		pi->sSameGroupFlag,1);
		strncpy(po->sHomeProvCode,		pi->sHomeProvCode,3);
		strncpy(po->sVisitCityCode,		pi->sVisitCityCode,3);
		strncpy(po->sThirdParty,		pi->sThirdParty,15);
		strncpy(po->sBusiType,			pi->sBusiType,1);
		strncpy(po->sBusiCode,			pi->sBusiCode,2);
		strncpy(po->sBaseFee,			pi->sBaseFee,10);
		strncpy(po->sTollFee,			pi->sTollFee,10);
		strncpy(po->sTollAddFee,		pi->sTollAddFee,10);
		strncpy(po->sOtherFee,			pi->sOtherFee,10);
		strncpy(po->sRoamFee,			pi->sRoamFee,10);
		strncpy(po->sAddFee,			pi->sAddFee,10);
		strncpy(po->sDisctBaseFee,		pi->sDisctBaseFee,10);
		strncpy(po->sDisctTollFee,		pi->sDisctTollFee,10);
		strncpy(po->sDisctTollAddFee,		pi->sDisctTollAddFee,10);
		strncpy(po->sDisctOtherFee,		pi->sDisctOtherFee,10);
		strncpy(po->sSupplementActiveCode,	pi->sSupplementActiveCode,1);
		strncpy(po->sSupplementCode,		pi->sSupplementCode,2);
		strncpy(po->sFileSeq,			pi->sFileSeq,8);
		strncpy(po->sCalledType,		pi->sCalledType,3);
		strncpy(po->sHomeAreaCode,		pi->sHomeAreaCode,10);
		strncpy(po->sLac,			pi->sLac,5);
		strncpy(po->sUserType,			pi->sUserType,2);
		strncpy(po->sReserve,			pi->sReserve,18);

		AllTrim(po->sTicketID);
		AllTrim(po->sMsisdn);
		AllTrim(po->sImsi);
		AllTrim(po->sCityCode);
		AllTrim(po->sMonth);
		AllTrim(po->sBillMonth);
		AllTrim(po->sCallType);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndReason);
		AllTrim(po->sDeformFlag);
		AllTrim(po->sOtherParty);
		AllTrim(po->sCalledCode);
		AllTrim(po->sMsc);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sTollType);
		AllTrim(po->sRoamType);
		AllTrim(po->sTollNetType);
		AllTrim(po->sValueAddBusi);
		AllTrim(po->sGroupID);
		AllTrim(po->sSameGroupFlag);
		AllTrim(po->sHomeProvCode);
		AllTrim(po->sVisitCityCode);
		AllTrim(po->sThirdParty);
		AllTrim(po->sBusiType);
		AllTrim(po->sBusiCode);
		AllTrim(po->sBaseFee);
		AllTrim(po->sTollFee);
		AllTrim(po->sTollAddFee);
		AllTrim(po->sOtherFee);
		AllTrim(po->sRoamFee);
		AllTrim(po->sAddFee);
		AllTrim(po->sDisctBaseFee);
		AllTrim(po->sDisctTollFee);
		AllTrim(po->sDisctTollAddFee);
		AllTrim(po->sDisctOtherFee);
		AllTrim(po->sSupplementActiveCode);
		AllTrim(po->sSupplementCode);
		AllTrim(po->sFileSeq);
		AllTrim(po->sCalledType);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sLac);
		AllTrim(po->sUserType);
		AllTrim(po->sReserve);
}
int InsertGsmBillTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct GsmRateTicketStruct Temp;
	struct GsmRateTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct GsmRateTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if(strncmp((char *)(pTemp->pData),"01",2)==0)continue;
		}

		mvitem_fmgsmrateticket((struct FGsmRateTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToGsmRateTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToGsmRateTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmsmsrateticket(struct FSmsRateTicketStruct *pi,struct SmsRateTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SmsRateTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sCallType,		pi->sCallType,1);
		strncpy(po->sMsisdn,		pi->sMsisdn,13);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,4);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,13);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,13);
		strncpy(po->sBusiCode,		pi->sBusiCode,10);
		strncpy(po->sFeeType,		pi->sFeeType,1);

		strncpy(sTemp,		pi->sMsgLen,4);sTemp[4]=0;
		po->iMsgLen=atoi(sTemp);
		strncpy(sTemp,		pi->sMsgCnt,4);sTemp[4]=0;
		po->iMsgCnt=atoi(sTemp);

		strncpy(po->sStartTime,		pi->sStartTime,14);

		strncpy(sTemp,		pi->sBaseFee,6);sTemp[6]=0;
		po->iBaseFee=atoi(sTemp);
		strncpy(sTemp,		pi->sInfoFee,6);sTemp[6]=0;
		po->iInfoFee=atoi(sTemp);
		strncpy(sTemp,	pi->sInfoFeeType,2);sTemp[2]=0;
		po->iInfoFeeType=atoi(sTemp);

		strncpy(po->sOriFileName,	pi->sOriFileName,20);
		strncpy(po->sReserve,		pi->sReserve,20);

		AllTrim(po->sRecordType);
		AllTrim(po->sCallType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sUserType);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sBusiCode);
		AllTrim(po->sFeeType);
		AllTrim(po->sStartTime);
		AllTrim(po->sOriFileName);
		AllTrim(po->sReserve);
}
int InsertSmsBillTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct SmsRateTicketStruct Temp;
	struct SmsRateTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct SmsRateTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if(strncmp((char *)(pTemp->pData),"HD",2)==0)continue;
		}

		mvitem_fmsmsrateticket((struct FSmsRateTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToSmsRateTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSmsRateTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmsmsupticket(struct FSmsupTicketStruct *pi,struct SmsupTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SmsupTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sMsgType,		pi->sMsgType,3);
		strncpy(po->sSpProvCode,	pi->sSpProvCode,3);

		strncpy(sTemp,		pi->sSmg,5);sTemp[5]=0;
		po->iSmg=atoi(sTemp);
		strncpy(sTemp,		pi->sSpCode,5);sTemp[5]=0;
		po->iSpCode=atoi(sTemp);
		strncpy(sTemp,		pi->sFwSmg,5);sTemp[5]=0;
		po->iFwSmg=atoi(sTemp);

		strncpy(po->sFwSmgProv,		pi->sFwSmgProv,3);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sMsgCnt,		pi->sMsgCnt,10);
		strncpy(po->sBaseFee,		pi->sBaseFee,12);
		strncpy(po->sInfoFee,		pi->sInfoFee,12);
		strncpy(po->sHomeProvCode,	pi->sHomeProvCode,3);
		strncpy(po->sFileType,		pi->sFileType,3);
		strncpy(po->sReserve1,		pi->sReserve1,30);

		AllTrim(po->sRecordType);
		AllTrim(po->sMsgType);
		AllTrim(po->sSpProvCode);
		AllTrim(po->sFwSmgProv);
		AllTrim(po->sStartTime);
		AllTrim(po->sMsgCnt);
		AllTrim(po->sBaseFee);
		AllTrim(po->sInfoFee);
		AllTrim(po->sHomeProvCode);
		AllTrim(po->sFileType);
		AllTrim(po->sReserve1);
}
int InsertSmsupBillTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct SmsupTicketStruct Temp;
	struct SmsupTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct SmsupTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if (strncmp((char *)(pTemp->pData),"HD",2)==0)continue;
		}

		mvitem_fmsmsupticket((struct FSmsupTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToSmsupTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSmsupTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
/*批量数据结构缓冲写入SMSUP_INTF_TICKET*/
void mvitem_fmsmsupintfticket(struct FSmsupIntfTicketStruct *pi,struct SmsupIntfTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SmsupIntfTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sMsgType,		pi->sMsgType,3);

		strncpy(sTemp,	pi->sSpProvCode,3);sTemp[3]=0;
		po->iSpProvCode=atoi(sTemp);
		strncpy(sTemp,		pi->sSmg,5);sTemp[5]=0;
		po->iSmg=atoi(sTemp);
		strncpy(sTemp,		pi->sSpCode,5);sTemp[5]=0;
		po->iSpCode=atoi(sTemp);
		strncpy(sTemp,		pi->sFwSmg,5);sTemp[5]=0;
		po->iFwSmg=atoi(sTemp);
		strncpy(sTemp,	pi->sFwSmgProv,3);sTemp[3]=0;
		po->iFwSmgProv=atoi(sTemp);

		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);
		strncpy(po->sMoCnt1,		pi->sMoCnt1,10);
		strncpy(po->sMoCnt2,		pi->sMoCnt2,10);
		strncpy(po->sMfCnt1,		pi->sMfCnt1,10);
		strncpy(po->sMfCnt2,		pi->sMfCnt2,10);
		strncpy(po->sFee1,		pi->sFee1,12);
		strncpy(po->sFee2,		pi->sFee2,12);

		strncpy(sTemp,	pi->sHomeProvCode,3);sTemp[3]=0;
		po->iHomeProvCode=atoi(sTemp);

		strncpy(po->sRoamFee1,		pi->sRoamFee1,10);
		strncpy(po->sRoamFee2,		pi->sRoamFee2,10);
		strncpy(po->sInfoFee1,		pi->sInfoFee1,10);
		strncpy(po->sInfoFee2,		pi->sInfoFee2,10);
		strncpy(po->sRoamNfee1,		pi->sRoamNfee1,10);
		strncpy(po->sRoamNfee2,		pi->sRoamNfee2,10);
		strncpy(po->sReserve1,		pi->sReserve1,20);

		AllTrim(po->sRecordType);
		AllTrim(po->sMsgType);
		AllTrim(po->sMinStartTime);
		AllTrim(po->sMaxStartTime);
		AllTrim(po->sMoCnt1);
		AllTrim(po->sMoCnt2);
		AllTrim(po->sMfCnt1);
		AllTrim(po->sMfCnt2);
		AllTrim(po->sFee1);
		AllTrim(po->sFee2);
		AllTrim(po->sRoamFee1);
		AllTrim(po->sRoamFee2);
		AllTrim(po->sInfoFee1);
		AllTrim(po->sInfoFee2);
		AllTrim(po->sRoamNfee1);
		AllTrim(po->sRoamNfee2);
		AllTrim(po->sReserve1);
}
int InsertSmsupIntfTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct SmsupIntfTicketStruct Temp;
	struct SmsupIntfTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct SmsupIntfTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if (strncmp((char *)(pTemp->pData),"01",2)==0)continue;
		}

		mvitem_fmsmsupintfticket((struct FSmsupIntfTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToSmsupIntfTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSmsupIntfTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
int InsertSmgTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct SmgTicketStruct Temp;
	struct SmgTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct SmgTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmsmgticket((struct FSmgTicketStruct *)(pTemp->pData),
				pTemp->iLen,&Temp);

		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToSmgTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSmgTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
int InsertZnwTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct ZnwTicketStruct Temp;
	struct ZnwTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct ZnwTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmznwticket((struct FZnwTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToZnwTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToZnwTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
int InsertIccTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct IccTicketStruct Temp;
	struct IccTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct IccTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmiccticket((struct FIccTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToIccTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToIccTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
int InsertInfoAcct(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct InfoAcctStruct Temp;
	struct InfoAcctStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct InfoAcctStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fminfoacct((struct FInfoAcctStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToInfoAcct(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToInfoAcct(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
int InsertInfoNbrAcct(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct InfoNbrAcctStruct Temp;
	struct InfoNbrAcctStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct InfoNbrAcctStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fminfonbracct((struct FInfoNbrAcctStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToInfoNbrAcct(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToInfoNbrAcct(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fminfonbracct(struct FInfoNbrAcctStruct *pi,
	struct InfoNbrAcctStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct InfoNbrAcctStruct));

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,20);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,20);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,20);

		strncpy(sTemp,		pi->sCnt,9);sTemp[9]=0;
		po->iCnt=atoi(sTemp);
		strncpy(sTemp,		pi->sDuration,9);sTemp[9]=0;
		po->iDuration=atoi(sTemp);
		strncpy(sTemp,		pi->sFee,9);sTemp[9]=0;
		po->iFee=atoi(sTemp);

		strncpy(po->sStartTime,		pi->sStartTime,14);

		strncpy(sTemp,	pi->sCallingTypeID,4);sTemp[4]=0;
		po->iCallingTypeID=atoi(sTemp);

		strncpy(po->sNetType,		pi->sNetType,1);
		strncpy(po->sNotes,		pi->sNotes,60);

		AllTrim(po->sRecordType);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sSpAccNbr);
		AllTrim(po->sSpServiceCode);
		AllTrim(po->sStartTime);
		AllTrim(po->sNetType);
		AllTrim(po->sNotes);
}
void mvitem_fminfoacct(struct FInfoAcctStruct *pi,struct InfoAcctStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct InfoAcctStruct));

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sProvinceID,	pi->sProvinceID,5);
		strncpy(po->sAreaCode,		pi->sAreaCode,5);

		strncpy(sTemp,		pi->sTotalCnt,9);sTemp[9]=0;
		po->iTotalCnt=atoi(sTemp);
		strncpy(sTemp,		pi->sTotalFee,9);sTemp[9]=0;
		po->iTotalFee=atoi(sTemp);
		strncpy(sTemp,		pi->sValidCnt,9);sTemp[9]=0;
		po->iValidCnt=atoi(sTemp);
		strncpy(sTemp,		pi->sValidFee,9);sTemp[9]=0;
		po->iValidFee=atoi(sTemp);
		strncpy(sTemp,	pi->sInvalidCnt,9);sTemp[9]=0;
		po->iInvalidCnt=atoi(sTemp);

		strncpy(po->sInvalidFee,	pi->sInvalidFee,9);
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sSpCode,		pi->sSpCode,20);

		strncpy(sTemp,		pi->sFee,9);sTemp[9]=0;
		po->iFee=atoi(sTemp);
		strncpy(sTemp,		pi->sOweFee,9);sTemp[9]=0;
		po->iOweFee=atoi(sTemp);


		AllTrim(po->sProvinceID);
		AllTrim(po->sAreaCode);
		AllTrim(po->sInvalidFee);
		AllTrim(po->sBillingCycleID);
		AllTrim(po->sSpCode);
}

void mvitem_fmiccticket(struct FIccTicketStruct *pi,struct IccTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct IccTicketStruct));

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sProvinceCode,	pi->sProvinceCode,5);
		strncpy(po->sCallAreaCode,	pi->sCallAreaCode,5);
		strncpy(po->sCardID,		pi->sCardID,30);
		strncpy(po->sCardProvinceCode,	pi->sCardProvinceCode,5);
		strncpy(po->sCardAreaCode,	pi->sCardAreaCode,5);
		strncpy(po->sCardAreaID,	pi->sCardAreaID,5);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,24);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,24);
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sStartTime,		pi->sStartTime,14);

		strncpy(sTemp,		pi->sDuration,9);sTemp[9]=0;
		po->iDuration=atoi(sTemp);
		strncpy(sTemp,		pi->sTotalFee,9);sTemp[9]=0;
		po->iTotalFee=atoi(sTemp);

		strncpy(po->sServiceType,	pi->sServiceType,2);
		strncpy(po->sDistanceType,	pi->sDistanceType,1);

		AllTrim(po->sRecordType);
		AllTrim(po->sProvinceCode);
		AllTrim(po->sCallAreaCode);
		AllTrim(po->sCardID);
		AllTrim(po->sCardProvinceCode);
		AllTrim(po->sCardAreaCode);
		AllTrim(po->sCardAreaID);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sBillingCycleID);
		AllTrim(po->sStartTime);
		AllTrim(po->sServiceType);
		AllTrim(po->sDistanceType);
}
void mvitem_fmznwticket(struct FZnwTicketStruct *pi,struct ZnwTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct ZnwTicketStruct));

		strncpy(sTemp,		pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sRecordType,		pi->sRecordType,2);
		strncpy(po->sStreamNumber,		pi->sStreamNumber,10);
		strncpy(po->sServiceKey,		pi->sServiceKey,10);
		strncpy(po->sBillingMode,		pi->sBillingMode,1);
		strncpy(po->sChargeRecordID,		pi->sChargeRecordID,8);
		strncpy(po->sCallingNbr,		pi->sCallingNbr,24);
		strncpy(po->sCalledNbr,			pi->sCalledNbr,24);
		strncpy(po->sTranslatedNbr,		pi->sTranslatedNbr,24);
		strncpy(po->sLocationNbr,		pi->sLocationNbr,10);
		strncpy(po->sBillingFlag,		pi->sBillingFlag,4);
		strncpy(po->sBillingNbr,		pi->sBillingNbr,24);
		strncpy(po->sStartTime,			pi->sStartTime,14);
		strncpy(po->sStopTime,			pi->sStopTime,14);

		strncpy(sTemp,			pi->sDuration,9);sTemp[9]=0;
		po->iDuration=atoi(sTemp);
		strncpy(sTemp,			pi->sTotalFee,9);sTemp[9]=0;
		po->iTotalFee=atoi(sTemp);

		strncpy(po->sBearCapability,		pi->sBearCapability,2);
		strncpy(po->sTariffClass,		pi->sTariffClass,2);
		strncpy(po->sBillType,			pi->sBillType,4);
		strncpy(po->sUserID,			pi->sUserID,10);
		strncpy(po->sServiceNbr,		pi->sServiceNbr,28);

		strncpy(sTemp,			pi->sCount,8);sTemp[8]=0;
		po->iCount=atoi(sTemp);
		strncpy(sTemp,			pi->sBaseFee,9);sTemp[9]=0;
		po->iBaseFee=atoi(sTemp);
		strncpy(sTemp,			pi->sBountyFee,9);sTemp[9]=0;
		po->iBountyFee=atoi(sTemp);
		strncpy(sTemp,			pi->sAddFee,9);sTemp[9]=0;
		po->iAddFee=atoi(sTemp);

		strncpy(po->sTransParam,		pi->sTransParam,30);
		strncpy(po->sCallparttobecharger,	pi->sCallparttobecharger,32);
		strncpy(po->sScpID,			pi->sScpID,10);
		strncpy(po->sCauseOfCallend,		pi->sCauseOfCallend,4);
		strncpy(po->sServiceModulator,		pi->sServiceModulator,4);
		strncpy(po->sServiceType,		pi->sServiceType,2);
		strncpy(po->sCardID,			pi->sCardID,30);
		strncpy(po->sHomeAreaCode,		pi->sHomeAreaCode,5);
		strncpy(po->sCalledCode,		pi->sCalledCode,5);
		strncpy(po->sBillingAreaCode,		pi->sBillingAreaCode,5);
		strncpy(po->sCardAreaCode,		pi->sCardAreaCode,5);
		strncpy(po->sDistanceType,		pi->sDistanceType,1);
		strncpy(po->sOriFileName,		pi->sOriFileName,40);

		AllTrim(po->sRecordType);
		AllTrim(po->sStreamNumber);
		AllTrim(po->sServiceKey);
		AllTrim(po->sBillingMode);
		AllTrim(po->sChargeRecordID);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sTranslatedNbr);
		AllTrim(po->sLocationNbr);
		AllTrim(po->sBillingFlag);
		AllTrim(po->sBillingNbr);
		AllTrim(po->sStartTime);
		AllTrim(po->sStopTime);
		AllTrim(po->sBearCapability);
		AllTrim(po->sTariffClass);
		AllTrim(po->sBillType);
		AllTrim(po->sUserID);
		AllTrim(po->sServiceNbr);
		AllTrim(po->sTransParam);
		AllTrim(po->sCallparttobecharger);
		AllTrim(po->sScpID);
		AllTrim(po->sCauseOfCallend);
		AllTrim(po->sServiceModulator);
		AllTrim(po->sServiceType);
		AllTrim(po->sCardID);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sCalledCode);
		AllTrim(po->sBillingAreaCode);
		AllTrim(po->sCardAreaCode);
		AllTrim(po->sDistanceType);
		AllTrim(po->sOriFileName);
}
void mvitem_fmsmgticket(struct FSmgTicketStruct *pi,int len,
	struct SmgTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SmgTicketStruct));

		strncpy(po->sMessageID,		pi->sMessageID,20);
		strncpy(po->sSmsType,		pi->sSmsType,1);
		strncpy(po->sSubType,		pi->sSubType,1);
		strncpy(po->sMsisdn,		pi->sMsisdn,21);
		strncpy(po->sSpCode,		pi->sSpCode,10);
		strncpy(po->sOtherParty,	pi->sOtherParty,21);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,10);
		strncpy(po->sBillType,		pi->sBillType,2);
		strncpy(po->sInfoFee,		pi->sInfoFee,6);
		strncpy(po->sPriority,		pi->sPriority,1);
		strncpy(po->sMsgLen,		pi->sMsgLen,3);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,4);
		strncpy(po->sSmg,		pi->sSmg,6);
		strncpy(po->sTsmg,		pi->sTsmg,6);
		strncpy(po->sSmc,		pi->sSmc,6);
		strncpy(po->sRecvDateTime,	pi->sRecvDateTime,14);
		strncpy(po->sDoneDateTime,	pi->sDoneDateTime,14);
		strncpy(po->sMsgID,		pi->sMsgID,20);
		strncpy(po->sOppMsgID,		pi->sOppMsgID,20);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,21);

		if(len==sizeof(struct FSmgTicketStruct)){
			strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
			po->iTicketTypeID=atoi(sTemp);
		}

		AllTrim(po->sMessageID);
		AllTrim(po->sSmsType);
		AllTrim(po->sSubType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sSpCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sSpServiceCode);
		AllTrim(po->sBillType);
		AllTrim(po->sInfoFee);
		AllTrim(po->sPriority);
		AllTrim(po->sMsgLen);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sSmg);
		AllTrim(po->sTsmg);
		AllTrim(po->sSmc);
		AllTrim(po->sRecvDateTime);
		AllTrim(po->sDoneDateTime);
		AllTrim(po->sMsgID);
		AllTrim(po->sOppMsgID);
		AllTrim(po->sCallingNbr);
}
void mvitem_fmrhjfticket(struct FRhjfTicketStruct *pi,struct RhjfTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct RhjfTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sTicketType,	pi->sTicketType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,30);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,7);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,7);
		strncpy(po->sBaseCharge,	pi->sBaseCharge,8);
		strncpy(po->sLandCharge,	pi->sLandCharge,8);
		strncpy(po->sOtherCharge,	pi->sOtherCharge,8);
		strncpy(po->sLandType,		pi->sLandType,1);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,5);

		AllTrim(po->sCallType);
		AllTrim(po->sTicketType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sBaseCharge);
		AllTrim(po->sLandCharge);
		AllTrim(po->sOtherCharge);
		AllTrim(po->sLandType);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sCalledAreaCode);
}
int InsertRhjfBillTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct RhjfTicketStruct Temp;
	struct RhjfTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct RhjfTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if(strstr((char *)(pTemp->pData),"RHJF")!=NULL) continue;
		}

		mvitem_fmrhjfticket((struct FRhjfTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToRhjfTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToRhjfTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmsmsticket(struct FSmsTicketStruct *pi,
	int len,struct SmsTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SmsTicketStruct));

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);

		strncpy(sTemp,		pi->sMsgLen,4);sTemp[4]=0;
		po->iMsgLen=atoi(sTemp);

		strncpy(po->sMsgID,		pi->sMsgID,30);
		strncpy(po->sSmsc,		pi->sSmsc,15);
		strncpy(po->sSmg,		pi->sSmg,15);
		strncpy(po->sTsmg,		pi->sTsmg,15);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sCalledType,	pi->sCalledType,2);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,10);
		strncpy(po->sSpCode,		pi->sSpCode,5);

		strncpy(sTemp,		pi->sBaseFee,8);sTemp[8]=0;
		po->iBaseFee=atoi(sTemp);
		strncpy(sTemp,		pi->sInfoFee,8);sTemp[8]=0;
		po->iInfoFee=atoi(sTemp);
		strncpy(sTemp,		pi->sRentFee,8);sTemp[8]=0;
		po->iRentFee=atoi(sTemp);
		strncpy(sTemp,		pi->sOtherFee,8);sTemp[8]=0;
		po->iOtherFee=atoi(sTemp);
		strncpy(sTemp,		pi->sInFee,8);sTemp[8]=0;
		po->iInFee=atoi(sTemp);
		strncpy(sTemp,		pi->sOutFee,8);sTemp[8]=0;
		po->iOutFee=atoi(sTemp);

		strncpy(po->sOriCallType,	pi->sOriCallType,2);
		strncpy(po->sReserve,		pi->sReserve,10);

		strncpy(po->sSpProvCode,	pi->sSpProvCode,3);
		strncpy(po->sHomeProvCode,	pi->sHomeProvCode,3);
		strncpy(po->sScpFlag,		pi->sScpFlag,1);
		strncpy(sTemp,	pi->sCallingTypeID,4);sTemp[4]=0;
		po->iCallingTypeID=atoi(sTemp);
		strncpy(po->sBillType,		pi->sBillType,1);

		if(len==sizeof(struct FSmsTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
		}

		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sMsisdn);
		AllTrim(po->sCalledCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sMsgID);
		AllTrim(po->sSmsc);
		AllTrim(po->sSmg);
		AllTrim(po->sTsmg);
		AllTrim(po->sUserType);
		AllTrim(po->sCalledType);
		AllTrim(po->sSpAccNbr);
		AllTrim(po->sSpServiceCode);
		AllTrim(po->sSpCode);
		AllTrim(po->sOriCallType);
		AllTrim(po->sReserve);

		AllTrim(po->sSpProvCode);
		AllTrim(po->sHomeProvCode);
		AllTrim(po->sScpFlag);
		AllTrim(po->sBillType);

		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);
}
int InsertSmsTicket(char sFileName[],char sTableName[])
{
	int iCnt=0,l;
	char	sBaseName[128],sHostDate[15];
	struct SmsTicketStruct	Temp;
	struct SmsTicketStructOut TempOut;
	struct FileControlStruct *ptHead,*pTemp,*ptLkHead;

	GetHostTime(sHostDate);
	GetBaseName(sFileName,sBaseName);
	if(strlen(sBaseName)>4){
		if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
			sBaseName[strlen(sBaseName)-4]=0;
	}
	bzero((void*)&TempOut,sizeof(struct SmsTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmsmsticket((struct FSmsTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToSmsTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToSmsTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}
	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmnsmsticket(struct FNsmsTicketStruct *pi,
	int len,struct NsmsTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct NsmsTicketStruct));

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);

		strncpy(sTemp,		pi->sMsgLen,4);sTemp[4]=0;
		po->iMsgLen=atoi(sTemp);

		strncpy(po->sMsgID,		pi->sMsgID,30);
		strncpy(po->sOppMsgID,		pi->sOppMsgID,30);
		strncpy(po->sSubType,		pi->sSubType,1);
		strncpy(po->sSmsc,		pi->sSmsc,15);
		strncpy(po->sSmg,		pi->sSmg,15);
		strncpy(po->sTsmg,		pi->sTsmg,15);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sCalledType,	pi->sCalledType,2);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,10);
		strncpy(po->sSpCode,		pi->sSpCode,10);

		strncpy(sTemp,		pi->sBaseFee,8);sTemp[8]=0;
		po->iBaseFee=atoi(sTemp);
		strncpy(sTemp,		pi->sInfoFee,8);sTemp[8]=0;
		po->iInfoFee=atoi(sTemp);
		strncpy(sTemp,		pi->sRentFee,8);sTemp[8]=0;
		po->iRentFee=atoi(sTemp);
		strncpy(sTemp,		pi->sOtherFee,8);sTemp[8]=0;
		po->iOtherFee=atoi(sTemp);
		strncpy(sTemp,		pi->sInFee,8);sTemp[8]=0;
		po->iInFee=atoi(sTemp);
		strncpy(sTemp,		pi->sOutFee,8);sTemp[8]=0;
		po->iOutFee=atoi(sTemp);

		strncpy(po->sOriCallType,	pi->sOriCallType,2);
		strncpy(po->sReserve,		pi->sReserve,10);
		strncpy(po->sSpProvCode,	pi->sSpProvCode,3);
		strncpy(po->sHomeProvCode,	pi->sHomeProvCode,3);
		strncpy(po->sScpFlag,		pi->sScpFlag,1);

		strncpy(sTemp,	pi->sCallingTypeID,4);sTemp[4]=0;
		po->iCallingTypeID=atoi(sTemp);

		strncpy(po->sBillType,		pi->sBillType,1);

		if(len==sizeof(struct FNsmsTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
		}

		AllTrim(po->sCallType);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sMsisdn);
		AllTrim(po->sCalledCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sMsgID);
		AllTrim(po->sOppMsgID);
		AllTrim(po->sSubType);
		AllTrim(po->sSmsc);
		AllTrim(po->sSmg);
		AllTrim(po->sTsmg);
		AllTrim(po->sUserType);
		AllTrim(po->sCalledType);
		AllTrim(po->sSpAccNbr);
		AllTrim(po->sSpServiceCode);
		AllTrim(po->sSpCode);
		AllTrim(po->sOriCallType);
		AllTrim(po->sReserve);
		AllTrim(po->sSpProvCode);
		AllTrim(po->sHomeProvCode);
		AllTrim(po->sScpFlag);
		AllTrim(po->sBillType);
		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);
}
int InsertNsmsTicket(char sFileName[],char sTableName[])
{
	int iCnt=0,l;
	char	sBaseName[128],sHostDate[15];
	struct NsmsTicketStruct	Temp;
	struct NsmsTicketStructOut TempOut;
	struct FileControlStruct *ptHead,*pTemp,*ptLkHead;

	GetHostTime(sHostDate);
	GetBaseName(sFileName,sBaseName);
	if(strlen(sBaseName)>4){
		if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
			sBaseName[strlen(sBaseName)-4]=0;
	}
	bzero((void*)&TempOut,sizeof(struct NsmsTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmnsmsticket((struct FNsmsTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToNsmsTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToNsmsTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}
	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_rsmsnbrstat(struct SmsNbrStatStruct *pi,struct RSmsNbrStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct RSmsNbrStatStruct));

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sTicketType,	pi->sTicketType,2);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);

		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;

		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);

}
void mvitem_usmsnbrstat(struct RSmsNbrStatStruct *pi,struct USmsNbrStatStruct *po)
{/*数据移动部分*/
	bzero((void*)po,sizeof(struct USmsNbrStatStruct));
		strcpy(po->sBillingCycleID,	pi->sBillingCycleID);
		strcpy(po->sTicketType,		pi->sTicketType);
		strcpy(po->sUserType,		pi->sUserType);
		strcpy(po->sMsisdn,		pi->sMsisdn);

		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;

		strcpy(po->sMinStartTime,	pi->sMinStartTime);
		strcpy(po->sMaxStartTime,	pi->sMaxStartTime);
		strcpy(po->sHomeAreaCode,	pi->sHomeAreaCode);
		strcpy(po->sCreatedDate,	pi->sCreatedDate);
		strcpy(po->sUpdatedDate,	pi->sUpdatedDate);
		strcpy(po->sRowID,		pi->sRowID);
}
void mvitem_smsnbrstat(struct RSmsNbrStatStruct *pi,struct SmsNbrStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct SmsNbrStatStruct));
		strcpy(po->sBillingCycleID,	pi->sBillingCycleID);
		strcpy(po->sTicketType,		pi->sTicketType);
		strcpy(po->sUserType,		pi->sUserType);
		strcpy(po->sMsisdn,		pi->sMsisdn);

		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;

		strcpy(po->sMinStartTime,	pi->sMinStartTime);
		strcpy(po->sMaxStartTime,	pi->sMaxStartTime);
		strcpy(po->sHomeAreaCode,	pi->sHomeAreaCode);
		strcpy(po->sCreatedDate,	pi->sCreatedDate);
		strcpy(po->sUpdatedDate,	pi->sUpdatedDate);

}
void mvitem_rsmspspstat(struct SmspSpStatStruct *pi,struct RSmspSpStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct RSmspSpStatStruct));

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);

		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;
		po->iTotalCnt=			pi->iTotalCnt;
		po->iTotalFee=			pi->iTotalFee;
		po->iTotalInfoFee=		pi->iTotalInfoFee;
		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iTotalRentFee=		pi->iTotalRentFee;

		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,14);
		strncpy(po->sUpdatedDate,	pi->sUpdatedDate,14);
}
void mvitem_usmspspstat(struct RSmspSpStatStruct *pi,struct USmspSpStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct USmspSpStatStruct));

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);

		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;
		po->iTotalCnt=			pi->iTotalCnt;
		po->iTotalFee=			pi->iTotalFee;
		po->iTotalInfoFee=		pi->iTotalInfoFee;
		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iTotalRentFee=		pi->iTotalRentFee;

		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,14);
		strncpy(po->sUpdatedDate,	pi->sUpdatedDate,14);
		strncpy(po->sRowID,	pi->sRowID,19);
}
void mvitem_smspspstat(struct RSmspSpStatStruct *pi,struct SmspSpStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct SmspSpStatStruct));

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);

		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;
		po->iTotalCnt=			pi->iTotalCnt;
		po->iTotalFee=			pi->iTotalFee;
		po->iTotalInfoFee=		pi->iTotalInfoFee;
		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iTotalRentFee=		pi->iTotalRentFee;

		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,14);
		strncpy(po->sUpdatedDate,	pi->sUpdatedDate,14);

}
void mvitem_rsmspnbrstat(struct SmspNbrStatStruct *pi,struct RSmspNbrStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct RSmspNbrStatStruct));

		po->iTicketTypeID=		pi->iTicketTypeID;
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);

		po->iTotalFee=			pi->iTotalFee;
		po->iTotalInfoFee=		pi->iTotalInfoFee;
		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iTotalRentFee=		pi->iTotalRentFee;

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,8);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);

		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;
		po->iTotalCnt=			pi->iTotalCnt;

		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,14);
		strncpy(po->sUpdatedDate,	pi->sUpdatedDate,14);
}
void mvitem_usmspnbrstat(struct RSmspNbrStatStruct *pi,struct USmspNbrStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct USmspNbrStatStruct));

		po->iTicketTypeID=		pi->iTicketTypeID;
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);

		po->iTotalFee=			pi->iTotalFee;
		po->iTotalInfoFee=		pi->iTotalInfoFee;
		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iTotalRentFee=		pi->iTotalRentFee;

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,8);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);

		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;
		po->iTotalCnt=			pi->iTotalCnt;

		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,14);
		strncpy(po->sUpdatedDate,	pi->sUpdatedDate,14);
		strncpy(po->sRowID,	pi->sRowID,19);
}
void mvitem_smspnbrstat(struct RSmspNbrStatStruct *pi,struct SmspNbrStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct SmspNbrStatStruct));

		po->iTicketTypeID=		pi->iTicketTypeID;
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);

		po->iTotalFee=			pi->iTotalFee;
		po->iTotalInfoFee=		pi->iTotalInfoFee;
		po->iTotalCommFee=		pi->iTotalCommFee;
		po->iTotalRentFee=		pi->iTotalRentFee;

		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpServiceCode,	pi->sSpServiceCode,8);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);

		po->iMoCnt=			pi->iMoCnt;
		po->iMtCnt=			pi->iMtCnt;
		po->iTotalCnt=			pi->iTotalCnt;

		strncpy(po->sMinStartTime,	pi->sMinStartTime,14);
		strncpy(po->sMaxStartTime,	pi->sMaxStartTime,14);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCreatedDate,	pi->sCreatedDate,14);
		strncpy(po->sUpdatedDate,	pi->sUpdatedDate,14);
}
void mvitem_fmnxrhjfticket(struct FNxRhjfTicketStruct *pi,struct NxRhjfTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct NxRhjfTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sCallingRef,	pi->sCallingRef,5);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,10);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,20);
		strncpy(po->sCalledRef,		pi->sCalledRef,5);
		strncpy(po->sCalledCode,	pi->sCalledCode,10);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,20);
		strncpy(po->sUserType,		pi->sUserType,2);
		strncpy(po->sCallingCarrType,	pi->sCallingCarrType,2);
		strncpy(po->sCalledCarrType,	pi->sCalledCarrType,2);
		strncpy(po->sCalledAreaID,	pi->sCalledAreaID,10);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sRouteType,		pi->sRouteType,1);
		strncpy(po->sCardNbr,		pi->sCardNbr,30);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,10);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,10);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sEndTime,		pi->sEndTime,14);
		strncpy(po->sDuration,		pi->sDuration,8);
		strncpy(po->sChargeDuration,	pi->sChargeDuration,8);
		strncpy(po->sBaseFee,		pi->sBaseFee,12);
		strncpy(po->sDisctFee,		pi->sDisctFee,12);
		strncpy(po->sTotalFee,		pi->sTotalFee,12);

		AllTrim(po->sRecordType);
		AllTrim(po->sCallingRef);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledRef);
		AllTrim(po->sCalledCode);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sUserType);
		AllTrim(po->sCallingCarrType);
		AllTrim(po->sCalledCarrType);
		AllTrim(po->sCalledAreaID);
		AllTrim(po->sServiceType);
		AllTrim(po->sRouteType);
		AllTrim(po->sCardNbr);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sDuration);
		AllTrim(po->sChargeDuration);
		AllTrim(po->sBaseFee);
		AllTrim(po->sDisctFee);
		AllTrim(po->sTotalFee);
}
int InsertNxRhjfTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0,iHead=true;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct NxRhjfTicketStruct Temp;
	struct NxRhjfTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct NxRhjfTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iHead==true){
			iHead=false;
			if(strncmp((char *)(pTemp->pData),"10",2)==0)continue;
		}

		mvitem_fmnxrhjfticket((struct FNxRhjfTicketStruct *)(pTemp->pData),&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		RegularDealDate(sBaseName,Temp.sDealDate);
		strncpy(Temp.sSourceID,sBaseName,40);

		if(EInsertStructToNxRhjfTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToNxRhjfTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmservcard(struct FServCardStruct *pi,struct ServCardStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct ServCardStruct));

		strncpy(po->sAccNbr,		pi->sAccNbr,15);
		strncpy(po->sAreaCode,		pi->sAreaCode,5);
		strncpy(po->sAreaCodeName,	pi->sAreaCodeName,20);
		strncpy(po->sAreaName,		pi->sAreaName,20);
		strncpy(po->sCustNane,		pi->sCustNane,30);

		strncpy(sTemp,		pi->sTypeID,4);sTemp[4]=0;
		po->iTypeID=atoi(sTemp);

		AllTrim(po->sAccNbr);
		AllTrim(po->sAreaCode);
		AllTrim(po->sAreaCodeName);
		AllTrim(po->sAreaName);
		AllTrim(po->sCustNane);
}
void mvitem_msisdnstat(struct MsisdnStatStruct *pi,struct MsisdnStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct MsisdnStatStruct));

		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sAreaCode,		pi->sAreaCode,9);

		po->iAreaID=			pi->iAreaID;

		strncpy(po->sNetType,		pi->sNetType,3);
		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sServiceType,	pi->sServiceType,10);

		po->iTotalDuration=		pi->iTotalDuration;
		po->iTotalMin=			pi->iTotalMin;
		po->iTotalCnt=			pi->iTotalCnt;
		po->iTotalFee1=			pi->iTotalFee1;
		po->iTotalFee2=			pi->iTotalFee2;
		po->iTotalFee3=			pi->iTotalFee3;

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sRowID,		pi->sRowID,19);
}


/*G网国内漫游上传数据的首记录结构*/
typedef struct _buf_up_newcri_head_{
	char RecType[2];	/*记录类型*/
	char FilialeCode[3];	/*省分公司代码*/
	char FileSymbol[3];	/*文件标志*/
	char FileSerial[5];	/*文件序列号*/
	char FileVersion[2];	/*文件版本号*/
	char FileDate[8];	/*文件产生日期*/
	char FirstCallDate[8];	/*首次通话日期*/
	char FirstCallTime[6];	/*首次通话时间*/
	char LastCallDate[8];	/*末次通话日期*/
	char LastCallTime[6];	/*末次通话时间*/
	char RecCount[6];	/*通话总记录数*/
	char TotalFee[15];	/*总话费*/
	char Reserved[145];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_newcri_head_buf;

/*G网国际漫游上传数据的首记录结构*/
typedef struct _buf_up_newcii_head_{
	char RecType[2];	/*记录类型*/
	char FilialeCode[3];	/*省分公司代码*/
	char FileSymbol[3];	/*文件标志*/
	char FileSerial[5];	/*文件序列号*/
	char FileVersion[2];	/*文件版本号*/
	char FileDate[8];	/*文件产生日期*/
	char FirstCallDate[8];	/*首次通话日期*/
	char FirstCallTime[6];	/*首次通话时间*/
	char LastCallDate[8];	/*末次通话日期*/
	char LastCallTime[6];	/*末次通话时间*/
	char RecCount[6];	/*通话总记录数*/
	char TotalFee[15];	/*总话费*/
	char Reserved[127];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_newcii_head_buf;

/*G网国内漫游上传数据的主/被叫记录结构*/
typedef struct _buf_up_newcri_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[25];	/*主叫号码*/
	char ChangeFlag[1];	/*修改指示*/
	char NumType[1];	/*号码类型*/
	char NumPick[1];	/*选号方案*/
	char CalledNum[25];	/*被叫号码*/
	char ServiceType[1];	/*业务类型*/
	char ServiceCode[2];	/*业务码*/
	char ServiceType2[1];	/*双重业务类型*/
	char ServiceCode2[2];	/*双重业务码*/
	char ChannelReq[1];	/*要求的收音通道*/
	char ChannelUsed[1];	/*使用的收音通道*/
	char ServiceTrans[1];	/*业务透明性*/
				/*附加业务事件*/
	char FunctionCode1[1];	/*活动码1*/
	char AppendCode1[2];	/*附加业务码1*/
	char FunctionCode2[1];	/*活动码2*/
	char AppendCode2[2];	/*附加业务码2*/
	char FunctionCode3[1];	/*活动码3*/
	char AppendCode3[2];	/*附加业务码3*/
	char FunctionCode4[1];	/*活动码4*/
	char AppendCode4[2];	/*附加业务码4*/
	char FunctionCode5[1];	/*活动码5*/
	char AppendCode5[2];	/*附加业务码5*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char DataAmountRef[6];	/*数据量参考*/
	char LandChargeCode[1];	/*长途费代码*/
	char OtherChargeCode[2];/*其他话费代码*/
	char RoamCharge[9];	/*漫游话费*/
	char LandCharge[6];	/*长途话费*/
	char OtherCharge[6];	/*其他话费*/
	char ChargeItem[1];	/*收费的项目*/
	char Reserved2[33];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_newcri_buf;

/*G网国内漫游上传数据的呼转记录结构*/
typedef struct _buf_up_newcri_hz_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[25];	/*主叫号码*/
	char NumB[25];		/*B号码*/
	char CalledNum[25];	/*被叫号码*/
	char FunctionCode[1];	/*活动码1*/
	char AppendCode[2];	/*附加业务码1*/
	char Reserved2[9];	/*未用*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char Reserved3[54];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_newcri_hz_buf;

/*G网国际漫游上传记录结构*/
typedef struct _buf_up_newcii_{
	char RecType[2];	/*记录类型*/
	char InCityCode[3];	/*入联通网城市代码*/
	char OutCityCode[3];	/*出联通网城市代码*/
	char Links[6];		/*链参考*/
	char Reserved[1];	/*未用*/
	char IMSI[15];		/*IMSI号码*/
	char CallingNum[25];	/*主叫号码*/
	char ChangeFlag[1];	/*修改指示*/
	char NumType[1];	/*号码类型*/
	char NumPick[1];	/*选号方案*/
	char CalledNum[25];	/*被叫号码*/
	char ServiceType[1];	/*业务类型*/
	char ServiceCode[2];	/*业务码*/
	char ServiceType2[1];	/*双重业务类型*/
	char ServiceCode2[2];	/*双重业务码*/
	char ChannelReq[1];	/*要求的收音通道*/
	char ChannelUsed[1];	/*使用的收音通道*/
	char ServiceTrans[1];	/*业务透明性*/
				/*附加业务事件*/
	char FunctionCode1[1];	/*活动码1*/
	char AppendCode1[2];	/*附加业务码1*/
	char FunctionCode2[1];	/*活动码2*/
	char AppendCode2[2];	/*附加业务码2*/
	char FunctionCode3[1];	/*活动码3*/
	char AppendCode3[2];	/*附加业务码3*/
	char FunctionCode4[1];	/*活动码4*/
	char AppendCode4[2];	/*附加业务码4*/
	char FunctionCode5[1];	/*活动码5*/
	char AppendCode5[2];	/*附加业务码5*/
	char MSC[15];		/*MSC 标识*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*蜂窝标志*/
	char MobileCode[1];	/*移动设备类别码*/
	char CallDate[8];	/*通话日期*/
	char CallStartTime[6];	/*通话起始时间*/
	char Duration[6];	/*付费单位*/
	char DataAmountRef[6];	/*数据量参考*/
	char Charges[9];	/*话费*/
	char ChargeItem[1];	/*收费的项目*/
	char Reserved2[30];	/*未用*/
	char BackLine[1];	/*回车*/
	char NewLine[1];	/*换行*/
}up_newcii_buf;

void mvitem_newcri2vitticket(up_newcri_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));

	if(strncmp(pi->RecType,"20",2)==0){
		strcpy(po->sCallType,"01");
		strncpy(po->sMsisdn,pi->CallingNum,24);
		strncpy(po->sOtherParty,pi->CalledNum,24);
		strncpy(po->sCalledCode,pi->OutCityCode,3);
		strncpy(po->sVisitAreaCode,pi->InCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
	else{
		strcpy(po->sCallType,"02");
		strncpy(po->sMsisdn,pi->CalledNum,24);
		strncpy(po->sOtherParty,pi->CallingNum,24);
		strncpy(po->sCalledCode,pi->InCityCode,3);
		strncpy(po->sVisitAreaCode,pi->OutCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
		strncpy(sTemp,pi->RoamCharge,9);sTemp[9]=0;
		po->iRoamFee=			atoi(sTemp);
		strncpy(sTemp,pi->LandCharge,6);sTemp[6]=0;
		po->iTollFee=			atoi(sTemp);
		strncpy(sTemp,pi->OtherCharge,6);sTemp[6]=0;
		po->iAddFee=			atoi(sTemp);

		strncpy(sTemp,pi->Duration,6);
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,	pi->CallDate,8);
		strncpy(po->sStartTime+8,	pi->CallStartTime,6);

		strncpy(po->sRoamType,		"2",	1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}

		strncpy(po->sUserType,		"1",1);

		strncpy(po->sImsi,		pi->IMSI,15);
		AllTrim(po->sImsi);

		strcpy(po->sMsrn,"");

		strncpy(po->sMsc,		pi->MSC,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		pi->LAC,5);
		AllTrim(po->sLac);
		strncpy(po->sCellID,		pi->CellOri_A,5);
		AllTrim(po->sCellID);

		strcpy(po->sServiceType,"000");
		strcpy(po->sServiceCode,"0011");

		strncpy(po->sSupplementCode,	pi->FunctionCode1,15);
}
void mvitem_newcri2vitticket_trans(up_newcri_hz_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));



		strcpy(po->sCallType,"03");
		strncpy(po->sThirdParty,pi->CallingNum,24);
		strncpy(po->sMsisdn,	pi->NumB,15);
		strncpy(po->sOtherParty,pi->CalledNum,24);

		strncpy(po->sCalledCode,pi->OutCityCode,3);
		strncpy(po->sVisitAreaCode,pi->InCityCode,3);

		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sThirdParty);


		po->iRoamFee=			0;
		po->iTollFee=			0;
		po->iAddFee=			0;

		strncpy(sTemp,pi->Duration,6);
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,	pi->CallDate,8);
		strncpy(po->sStartTime+8,	pi->CallStartTime,6);

		strncpy(po->sRoamType,		"2",	1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}

		strncpy(po->sUserType,		"1",1);

		strncpy(po->sImsi,		pi->IMSI,15);
		AllTrim(po->sImsi);

		strcpy(po->sMsrn,"");

		strncpy(po->sMsc,		pi->MSC,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		pi->LAC,5);
		AllTrim(po->sLac);
		strncpy(po->sCellID,		pi->CellOri_A,5);
		AllTrim(po->sCellID);

		strcpy(po->sServiceType,"002");
		strncpy(po->sServiceCode,"00",2);
		if(strncmp(pi->AppendCode,"  ",2)!=0)
			strncpy(po->sServiceCode,pi->AppendCode,2);
		else
			strncpy(po->sServiceCode,"00",2);

		strcpy(po->sSupplementCode,	"");
}
void mvitem_newcii2vitticket(up_newcii_buf* pi,struct UpTicketGStruct* po)
{
	char sTemp[20];

	memset(po,0,sizeof(struct UpTicketGStruct));



	if(strncmp(pi->RecType,"20",2)==0){
		strcpy(po->sCallType,"01");
		strncpy(po->sMsisdn,pi->CallingNum,24);
		strncpy(po->sOtherParty,pi->CalledNum,24);
		strncpy(po->sCalledCode,pi->OutCityCode,3);
		strncpy(po->sVisitAreaCode,pi->InCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
	else{
		strcpy(po->sCallType,"02");
		strncpy(po->sMsisdn,pi->CalledNum,24);
		strncpy(po->sOtherParty,pi->CallingNum,24);
		strncpy(po->sCalledCode,pi->InCityCode,3);
		strncpy(po->sVisitAreaCode,pi->OutCityCode,3);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
	}
		strncpy(sTemp,pi->Charges,9);sTemp[9]=0;
		po->iRoamFee=			atoi(sTemp);


		strncpy(sTemp,pi->Duration,6);sTemp[6]=0;
		po->iDuration=			atoi(sTemp);

		strncpy(po->sStartTime,	pi->CallDate,8);
		strncpy(po->sStartTime+8,	pi->CallStartTime,6);

		strncpy(po->sRoamType,		"3",	1);
		if(po->iTollFee==0)
			strncpy(po->sDistanceType,	"1",1);
		else{
			if(strcmp(po->sCalledCode,"0852")==0||
				strcmp(po->sCalledCode,"0853")==0||
				strcmp(po->sCalledCode,"0886")==0)
				strncpy(po->sDistanceType,	"4",1);
			else if(strncmp(po->sCalledCode,"0",1)==0)
				strncpy(po->sDistanceType,	"5",1);
			else
				strncpy(po->sDistanceType,	"3",1);
		}

		strncpy(po->sUserType,		"1",1);

		strncpy(po->sImsi,		pi->IMSI,15);
		AllTrim(po->sImsi);

		strcpy(po->sMsrn,"");

		strncpy(po->sMsc,		pi->MSC,15);
		AllTrim(po->sMsc);

		strncpy(po->sLac,		pi->LAC,5);
		AllTrim(po->sLac);
		strncpy(po->sCellID,		pi->CellOri_A,5);
		AllTrim(po->sCellID);

		strcpy(po->sServiceType,"000");
		strcpy(po->sServiceCode,"0011");

		strncpy(po->sSupplementCode,	pi->FunctionCode1,15);
}
int InsertNewGsmTicket(char sFileName[],char sTableName[])
{
	int iCnt=0;
	char sBaseName[60],sDealDate[15];
	struct UpTicketGStructOut TempOut;
	struct UpTicketGStruct Temp;
	FILE *fp;
	char sTicket[TICKETBUFSIZE];

	GetBaseName(sFileName,sBaseName);

	bzero((void*)&TempOut,sizeof(struct UpTicketGStructOut));
	TempOut.iCurPos=0;

	strcpy(TempOut.sTableName,sTableName);

	if((fp=fopen(sFileName,"r"))==NULL){
		printf("File %s Open Error!\n",sFileName);
		return -1;
	}
	if(strncmp(sBaseName,"CRI",3)!=0&&
		strncmp(sBaseName,"CII",3)!=0&&
		strncmp(sBaseName,"GBI",3)!=0&&
                strncmp(sBaseName,"QHT",3)!=0&&
                strncmp(sBaseName,"CQT",3)!=0&&
		strncmp(sBaseName,"TRI",3)!=0&&
		strncmp(sBaseName,"TII",3)!=0) return 0;

	if(strcmp(sBaseName+strlen(sBaseName)-4,".tmp")==0)
		sBaseName[strlen(sBaseName)-4]=0;

	strncpy(sDealDate,"20",2);
	strncpy(sDealDate+2,sBaseName+3,6);
	if(strncmp("CRIT",sBaseName,4)==0)
		strncpy(sDealDate+2,sBaseName+4,6);
	strcpy(sDealDate+8,"000000");

	while(1){
		fgets(sTicket,TICKETBUFSIZE,fp);
		if(feof(fp)) break;

		if(strncmp(sTicket,"10",2)==0) continue;

		if(strncmp(sBaseName,"CRI",3)==0||
			strncmp(sBaseName,"GBI",3)==0||
			strncmp(sBaseName,"TRI",3)==0){

			if(strncmp(sTicket,"41",2)==0)
				mvitem_newcri2vitticket_trans((up_newcri_hz_buf*)&sTicket,&Temp);
			else
				mvitem_newcri2vitticket((up_newcri_buf*)&sTicket,&Temp);
		}
		else
			mvitem_newcii2vitticket((up_newcii_buf*)&sTicket,&Temp);

		strcpy(Temp.sDealDate,sDealDate);
		strcpy(Temp.sSourceID,sBaseName);

		GetImsiArea(Temp.sImsi,"G",Temp.sStartTime,Temp.sHomeAreaCode);
		if(strcmp(Temp.sHomeAreaCode,"086")==0||
			strlen(Temp.sHomeAreaCode)==0)
			GetBelongCode(Temp.sMsisdn,Temp.sStartTime,Temp.sHomeAreaCode);
			
		if(strncmp(sBaseName,"CII",3)==0){
			Temp.iTollFee=Temp.iRoamFee;
			Temp.iRoamFee=0;
		}
		if(EInsertStructToUpTicketG(&Temp,FALSE,&TempOut)<0) return -1;

		iCnt++;
/*	if(EInsertStructToUpTicketG(NULL,TRUE,&TempOut)<0)
		return -1;
**/
	}
	if(EInsertStructToUpTicketG(NULL,TRUE,&TempOut)<0) return -1;


	printf("成功将文件%s入库到表%s",sBaseName,sTableName);

	return iCnt;

}

void mvitem_fmolderrticket(struct FileControlStruct *pTemp,struct ErrTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	struct FOldErrTicketStruct *pi=(struct FOldErrTicketStruct *)pTemp->pData;
	int iLen=pTemp->iLen-(pi->sErrRec-(char*)pi);

	if(iLen>2048) iLen=2048;
	bzero((void*)po,sizeof(struct ErrTicketStruct));

	strncpy(po->sRecordType,pi->sRecordType,1);
	strncpy(po->sCallType,	pi->sCallType,2);
	strncpy(po->sMsisdn,	pi->sMsisdn,15);
	strncpy(po->sOtherParty,pi->sOtherParty,24);
	strncpy(po->sStartTime,	pi->sStartTime,14);
	strncpy(po->sDuration,	pi->sDuration,6);
	strncpy(po->sImsi,	pi->sImsi,15);
	strncpy(po->sMsc,	pi->sMsc,15);
	strncpy(po->sReserve1,	pi->sReserve1,20);
	strncpy(po->sReserve2,	pi->sReserve2,20);
	strncpy(po->sReserve3,	pi->sReserve3,30);
	strncpy(po->sReserve4,	pi->sReserve4,30);
	strncpy(po->sSourceID,	pi->sSourceID,6);
	/*strncpy(po->sFileName,	pi->sFileName,40);*/
	strncpy(po->sOriFileName,	pi->sFileName,40);
	strncpy(po->sErrCode,	pi->sErrCode,4);

	strncpy(sTemp,	pi->sLine,8);sTemp[8]=0;
	po->iLine=atoi(sTemp);

	strncpy(po->sModule,	pi->sModule,3);
	strncpy(po->sState,	pi->sState,1);
	strncpy(po->sUpdateDate,pi->sUpdateDate,14);
	strncpy(po->sDealDate,	pi->sDealDate,14);

	strncpy(po->sErrRec,		pi->sErrRec,iLen);

	AllTrim(po->sRecordType);
	AllTrim(po->sCallType);
	AllTrim(po->sMsisdn);
	AllTrim(po->sOtherParty);
	AllTrim(po->sStartTime);
	AllTrim(po->sDuration);
	AllTrim(po->sImsi);
	AllTrim(po->sMsc);
	AllTrim(po->sReserve1);
	AllTrim(po->sReserve2);
	AllTrim(po->sReserve3);
	AllTrim(po->sReserve4);
	AllTrim(po->sSourceID);
/*	AllTrim(po->sFileName);*/
	AllTrim(po->sOriFileName);
	AllTrim(po->sErrCode);
	AllTrim(po->sModule);
	AllTrim(po->sState);
	AllTrim(po->sUpdateDate);
	AllTrim(po->sDealDate);
	AllTrim(po->sErrRec);
}
void mvitem_fmerrticket(struct FileControlStruct *pTemp,struct ErrTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];
	
	struct FErrTicketStruct *pi=(struct FErrTicketStruct *)pTemp->pData;
	int iLen=pTemp->iLen-(pi->sErrRec-(char*)pi);

	if(iLen>2048) iLen=2048;

	bzero((void*)po,sizeof(struct ErrTicketStruct));

	strncpy(po->sRecordType,	pi->sRecordType,1);
	strncpy(po->sCallType,		pi->sCallType,2);
	strncpy(po->sMsisdn,		pi->sMsisdn,15);
	strncpy(po->sOtherParty,	pi->sOtherParty,24);
	strncpy(po->sStartTime,		pi->sStartTime,14);
	strncpy(po->sDuration,		pi->sDuration,6);
	strncpy(po->sImsi,		pi->sImsi,15);
	strncpy(po->sMsc,		pi->sMsc,15);
	strncpy(po->sReserve1,		pi->sReserve1,20);
	strncpy(po->sReserve2,		pi->sReserve2,20);
	strncpy(po->sReserve3,		pi->sReserve3,30);
	strncpy(po->sReserve4,		pi->sReserve4,30);
	strncpy(po->sOriSourceID,	pi->sOriSourceID,6);
	strncpy(po->sOriFileName,	pi->sOriFileName,40);

	strncpy(sTemp,		pi->sLine,8);sTemp[8]=0;
	po->iLine=atoi(sTemp);

	strncpy(po->sErrCode,		pi->sErrCode,4);
	strncpy(po->sFileName,		pi->sFileName,19);
	strncpy(po->sModule,		pi->sModule,3);
	strncpy(po->sAreaCode,		pi->sAreaCode,5);
	strncpy(po->sState,		pi->sState,1);
/*	strncpy(po->sUpdateDate,	pi->sUpdateDate,14);
	strncpy(po->sDealDate,		pi->sDealDate,14);
	strncpy(po->sSourceID,		pi->sSourceID,30);
*/
	strncpy(po->sErrRec,		pi->sErrRec,iLen);

	AllTrim(po->sRecordType);
	AllTrim(po->sCallType);
	AllTrim(po->sMsisdn);
	AllTrim(po->sOtherParty);
	AllTrim(po->sStartTime);
	AllTrim(po->sDuration);
	AllTrim(po->sImsi);
	AllTrim(po->sMsc);
	AllTrim(po->sReserve1);
	AllTrim(po->sReserve2);
	AllTrim(po->sReserve3);
	AllTrim(po->sReserve4);
	AllTrim(po->sOriSourceID);
	AllTrim(po->sOriFileName);
	AllTrim(po->sErrCode);
	AllTrim(po->sFileName);
	AllTrim(po->sModule);
	AllTrim(po->sAreaCode);
	AllTrim(po->sState);
/*	AllTrim(po->sUpdateDate);
	AllTrim(po->sDealDate);
	AllTrim(po->sSourceID);
*/
	AllTrim(po->sErrRec);
}
int InsertErrTicket(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct ErrTicketStruct Temp;
	struct ErrTicketStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;
	struct FErrTicketStruct *p;


	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct ErrTicketStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		p=(struct FErrTicketStruct *)pTemp->pData;
		
		if(strncmp(p->sFileName,"NORECYLE",8)==0)
			mvitem_fmerrticket(pTemp,&Temp);
		else	mvitem_fmolderrticket(pTemp,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		strncpy(Temp.sSourceID,sBaseName,30);

		if(EInsertStructToErrTicket(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToErrTicket(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
void mvitem_fmgprszteintf(struct FGprsZteIntfStruct *pi,struct GprsZteIntfStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct GprsZteIntfStruct));

	strncpy(po->sRecordType,	pi->sRecordType,2);
	strncpy(po->sNiPdp,		pi->sNiPdp,1);
	strncpy(po->sImsi,		pi->sImsi,15);
	strncpy(po->sEsn,		pi->sEsn,20);
	strncpy(po->sMsisdn,		pi->sMsisdn,15);
	strncpy(po->sStartTime,		pi->sStartTime,14);

	strncpy(sTemp,	pi->sCallDuration,6);sTemp[6]=0;
		po->iCallDuration=atoi(sTemp);

	strncpy(po->sSgsnAddr,		pi->sSgsnAddr,16);

	strncpy(sTemp,		pi->sCellID,5);sTemp[5]=0;
		po->iCellID=atoi(sTemp);
	strncpy(sTemp,		pi->sLac,5);sTemp[5]=0;
		po->iLac=atoi(sTemp);

	strncpy(po->sChargingID,	pi->sChargingID,10);
	strncpy(po->sGgsnAddr,		pi->sGgsnAddr,16);
	strncpy(po->sApnNi,		pi->sApnNi,63);
	strncpy(po->sApnOi,		pi->sApnOi,37);
	strncpy(po->sPdpType,		pi->sPdpType,1);
	strncpy(po->sServedPdpAddress,	pi->sServedPdpAddress,16);

	strncpy(sTemp,	pi->sSgsnChange,1);sTemp[1]=0;
		po->iSgsnChange=atoi(sTemp);
	strncpy(sTemp,	pi->sCloseCause,2);sTemp[2]=0;
		po->iCloseCause=atoi(sTemp);

	strncpy(po->sIntegrityFlag,	pi->sIntegrityFlag,2);
	strncpy(po->sServiceType,	pi->sServiceType,3);
	strncpy(po->sUserType,		pi->sUserType,1);
	strncpy(po->sDataFlowup1,	pi->sDataFlowup1,10);
	strncpy(po->sDataFlowdn1,	pi->sDataFlowdn1,10);
	strncpy(po->sBillItem,		pi->sBillItem,1);
	strncpy(po->sBillService,	pi->sBillService,2);
	strncpy(po->sRoamType,		pi->sRoamType,1);
	strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,4);
	strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,4);
	strncpy(po->sDurationCnt,	pi->sDurationCnt,10);
	strncpy(po->sFlowCnt,		pi->sFlowCnt,10);
	strncpy(po->sDurationUnit,	pi->sDurationUnit,10);
	strncpy(po->sBillUnit,		pi->sBillUnit,10);
	strncpy(po->sCfee,		pi->sCfee,10);
	strncpy(po->sFee1,		pi->sFee1,10);
	strncpy(po->sFileName,		pi->sFileName,20);
	strncpy(po->sHomeCityCode,	pi->sHomeCityCode,5);
	strncpy(po->sMsnc,		pi->sMsnc,8);
	strncpy(po->sCloseCause1,	pi->sCloseCause1,4);
	strncpy(po->sGgsn,		pi->sGgsn,10);
	strncpy(po->sApnMode,		pi->sApnMode,1);
	strncpy(po->sBillFlag,		pi->sBillFlag,1);
	strncpy(po->sGsnIp,		pi->sGsnIp,16);
	strncpy(po->sBillSeq,		pi->sBillSeq,8);
	strncpy(po->sSgsnPlmnID,	pi->sSgsnPlmnID,7);
	strncpy(po->sFee2,		pi->sFee2,10);
	strncpy(po->sRouteArea,		pi->sRouteArea,4);
	strncpy(po->sErrCode,		pi->sErrCode,15);

	AllTrim(po->sRecordType);
	AllTrim(po->sNiPdp);
	AllTrim(po->sImsi);
	AllTrim(po->sEsn);
	AllTrim(po->sMsisdn);
	AllTrim(po->sStartTime);
	AllTrim(po->sSgsnAddr);
	AllTrim(po->sChargingID);
	AllTrim(po->sGgsnAddr);
	AllTrim(po->sApnNi);
	AllTrim(po->sApnOi);
	AllTrim(po->sPdpType);
	AllTrim(po->sServedPdpAddress);
	AllTrim(po->sIntegrityFlag);
	AllTrim(po->sServiceType);
	AllTrim(po->sUserType);
	AllTrim(po->sDataFlowup1);
	AllTrim(po->sDataFlowdn1);
	AllTrim(po->sBillItem);
	AllTrim(po->sBillService);
	AllTrim(po->sRoamType);
	AllTrim(po->sHomeAreaCode);
	AllTrim(po->sVisitAreaCode);
	AllTrim(po->sDurationCnt);
	AllTrim(po->sFlowCnt);
	AllTrim(po->sDurationUnit);
	AllTrim(po->sBillUnit);
	AllTrim(po->sCfee);
	AllTrim(po->sFee1);
	AllTrim(po->sFileName);
	AllTrim(po->sHomeCityCode);
	AllTrim(po->sMsnc);
	AllTrim(po->sCloseCause1);
	AllTrim(po->sGgsn);
	AllTrim(po->sApnMode);
	AllTrim(po->sBillFlag);
	AllTrim(po->sGsnIp);
	AllTrim(po->sBillSeq);
	AllTrim(po->sSgsnPlmnID);
	AllTrim(po->sFee2);
	AllTrim(po->sRouteArea);
	AllTrim(po->sErrCode);
}
int InsertGprsZteIntf(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct GprsZteIntfStruct Temp;
	struct GprsZteIntfStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;

	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct GprsZteIntfStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmgprszteintf((struct FGprsZteIntfStruct *)(pTemp->pData)
			,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		strncpy(Temp.sSourceID,sBaseName,30);

		if(EInsertStructToGprsZteIntf(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToGprsZteIntf(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}

void mvitem_fmgprsstdintf(struct FGprsStdIntfStruct *pi,struct GprsStdIntfStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct GprsStdIntfStruct));

	strncpy(po->sRecordType,	pi->sRecordType,2);
	strncpy(po->sRoamType,		pi->sRoamType,2);
	strncpy(po->sImsi,		pi->sImsi,15);
	strncpy(po->sMsisdn,		pi->sMsisdn,15);
	strncpy(po->sSgsn,		pi->sSgsn,16);
	strncpy(po->sSgsnChange,	pi->sSgsnChange,1);
	strncpy(po->sGgsn,		pi->sGgsn,16);
	strncpy(po->sServedPdpAddress,	pi->sServedPdpAddress,16);
	strncpy(po->sApnNi,		pi->sApnNi,63);
	strncpy(po->sApnOi,		pi->sApnOi,37);
	strncpy(po->sReserv1,		pi->sReserv1,14);

	strncpy(sTemp,	pi->sCallDuration,6);sTemp[6]=0;
		po->iCallDuration=atoi(sTemp);

	strncpy(po->sPartialType,	pi->sPartialType,1);
	strncpy(po->sCloseCause,	pi->sCloseCause,2);
	strncpy(po->sStartTime,		pi->sStartTime,14);
	strncpy(po->sNiPdp,		pi->sNiPdp,1);
	strncpy(po->sChargingID,	pi->sChargingID,10);
	strncpy(po->sLac,		pi->sLac,5);
	strncpy(po->sCellID,		pi->sCellID,5);
	strncpy(po->sVisitCityCode,	pi->sVisitCityCode,3);
	strncpy(po->sReserv2,		pi->sReserv2,10);
	strncpy(po->sRoamRemark,	pi->sRoamRemark,10);
	strncpy(po->sImei,		pi->sImei,19);
	strncpy(po->sDataFlowdn,	pi->sDataFlowdn,10);
	strncpy(po->sDataFlowup,	pi->sDataFlowup,10);
	strncpy(po->sChargeItem,	pi->sChargeItem,1);
	strncpy(po->sChargeUnit,	pi->sChargeUnit,10);
	strncpy(po->sChargeOperation,	pi->sChargeOperation,2);

	strncpy(sTemp,		pi->sTotalFee,9);sTemp[9]=0;
		po->iTotalFee=atoi(sTemp);

	strncpy(po->sReserv3,		pi->sReserv3,93);

	AllTrim(po->sRecordType);
	AllTrim(po->sRoamType);
	AllTrim(po->sImsi);
	AllTrim(po->sMsisdn);
	AllTrim(po->sSgsn);
	AllTrim(po->sSgsnChange);
	AllTrim(po->sGgsn);
	AllTrim(po->sServedPdpAddress);
	AllTrim(po->sApnNi);
	AllTrim(po->sApnOi);
	AllTrim(po->sReserv1);
	AllTrim(po->sPartialType);
	AllTrim(po->sCloseCause);
	AllTrim(po->sStartTime);
	AllTrim(po->sNiPdp);
	AllTrim(po->sChargingID);
	AllTrim(po->sLac);
	AllTrim(po->sCellID);
	AllTrim(po->sVisitCityCode);
	AllTrim(po->sReserv2);
	AllTrim(po->sRoamRemark);
	AllTrim(po->sImei);
	AllTrim(po->sDataFlowdn);
	AllTrim(po->sDataFlowup);
	AllTrim(po->sChargeItem);
	AllTrim(po->sChargeUnit);
	AllTrim(po->sChargeOperation);
	AllTrim(po->sReserv3);
}
int InsertGprsStdIntf(char sFileName[],char sTableName[])
{
	int l,iCnt=0;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	struct GprsStdIntfStruct Temp;
	struct GprsStdIntfStructOut TempOut;
	char	sBaseName[80],sHostDate[15],*pc;

	GetHostTime(sHostDate);

	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;

	bzero((void*)&TempOut,sizeof(struct GprsStdIntfStructOut));
	strcpy(TempOut.sTableName,sTableName);

	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("加载文件%s失败",sFileName);
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmgprsstdintf((struct FGprsStdIntfStruct *)(pTemp->pData)
			,&Temp);

		strcpy(Temp.sUpdateDate,sHostDate);
		strcpy(Temp.sDealDate,sHostDate);
		strncpy(Temp.sSourceID,sBaseName,30);

		if(EInsertStructToGprsStdIntf(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			listfree(&ptLkHead);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToGprsStdIntf(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		listfree(&ptLkHead);
		return -1;
	}

	listfree(&ptLkHead);
	return iCnt;
}
