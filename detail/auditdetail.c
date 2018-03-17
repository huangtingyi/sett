#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

#include <ticket_field.h>
#include <tariff_disct.h>
#include <ticket.h>
#include <detail_intf.h>
#include <detail_supp.h>

BINTREE *pAccRoot=NULL,*pOdsRoot=NULL,*pTicketCtlRoot=NULL;
struct StPrepTicketStruct *gpTicketList=NULL,*pOdsTicketList=NULL;
struct StPrepTicketCtlStruct *gpTicketCtlList=NULL;

int data_search_st_prep_ticket_e(void *pValue,void *pData)
{
	int iResult=0;
	
	struct StPrepTicketStruct *pSource=(struct StPrepTicketStruct*)pValue;
	struct StPrepTicketStruct *pTarget=(struct StPrepTicketStruct*)pData;
/*节点关键字为：呼叫类型、本端号码、对端号码、用户分组*/
	
	if((iResult=strcmp(pSource->sMsisdn,	pTarget->sMsisdn))!=0) return iResult;
/*	if((iResult=strcmp(pSource->sOtherParty,pTarget->sOtherParty))!=0) return iResult;*/
	if((iResult=strcmp(pSource->sCallType,	pTarget->sCallType))!=0) return iResult;

	return iResult;
}

int data_search_st_prep_ticket_ctl_e(void *pValue,void *pData)
{
	int iResult=0;
	
	struct StPrepTicketCtlStruct *pSource=(struct StPrepTicketCtlStruct*)pValue;
	struct StPrepTicketCtlStruct *pTarget=(struct StPrepTicketCtlStruct*)pData;
	
	if((iResult=strcmp(pSource->sRowID,	pTarget->sRowID))!=0) return iResult;

	return iResult;
}

int comp_insert_list_st_prep_ticket_e(LIST *pValue,LIST*pHead)
{
        struct StPrepTicketStruct *pSource=(struct StPrepTicketStruct *)pValue;
        struct StPrepTicketStruct *pTarget=(struct StPrepTicketStruct *)pHead;

        return strcmp(pTarget->sStartTime,pSource->sStartTime);
}
void assign_insert_bintree_st_prep_ticket_e(void **ppData,void *pData)
{
	InsertListSort((LIST**)ppData,(LIST*)pData,
                comp_insert_list_st_prep_ticket_e);
}
int append_bintree_to_list_st_prep_ticket_e(void **ppData)
{
	struct StPrepTicketStruct *pTemp=(struct StPrepTicketStruct*)(*ppData);

	pTemp->pLoadNext=gpTicketList;
	gpTicketList=pTemp;

	return 0;
}
int append_bintree_to_list_st_prep_ticket_ctl_e(void **ppData)
{
	struct StPrepTicketCtlStruct *pTemp=(struct StPrepTicketCtlStruct*)(*ppData);

	pTemp->pLoadNext=gpTicketCtlList;
	gpTicketCtlList=pTemp;

	return 0;
}
int SplitLongDurationPrepTicket(int iTimeFlag,struct StPrepTicketStruct *p,int iFlag,BINTREE **pptRoot)
{
	struct StPrepTicketStruct *pTemp;
	struct StPrepTicketCtlStruct *ptPre;
	struct StAreaMscTimeOffsetStruct *ptCur;
	int iCnt,i,iDuration;
	
	iCnt=(p->iDuration+1799)/1800;
	iDuration=p->iDuration%1800;
/*结算侧话单不做拆单处理*/	
	if(iTimeFlag==false){
		if((pTemp=(struct StPrepTicketStruct *)malloc(
			sizeof(struct StPrepTicketStruct)))==NULL){
			WriteAlertMsg("拆单申请空间struct StPrepTicketStruct失败.");
			return 0;
		}
		memcpy((void*)pTemp,(void*)p,sizeof(struct StPrepTicketStruct));
		pTemp->pLoadNext=NULL;
		pTemp->pNext=NULL;
		if(InsertBin(pptRoot,pTemp,data_search_st_prep_ticket_e,
			assign_insert_bintree_st_prep_ticket_e)<0){
			WriteProcMsg("生成二叉树 StPrepTicketStruct 失败.");
			return -1;
		}
		return 0;
	}

	for(i=0;i<iCnt;i++){
		
		if(i==iCnt-1){
			if(p->iDuration>1800)
				iDuration=p->iDuration%1800;
			else	iDuration=p->iDuration;
		}
		else	iDuration=1800;
		
		if((pTemp=(struct StPrepTicketStruct *)malloc(
			sizeof(struct StPrepTicketStruct)))==NULL){
			WriteAlertMsg("拆单申请空间struct StPrepTicketStruct失败.");
			return 0;
		}
		memcpy((void*)pTemp,(void*)p,sizeof(struct StPrepTicketStruct));
		pTemp->pLoadNext=NULL;
		pTemp->pNext=NULL;
		pTemp->iDuration=iDuration;

		AddTimes(pTemp->sStartTime,i*1800);
		strcpy(pTemp->sEndTime,pTemp->sStartTime);
		AddTimes(pTemp->sEndTime,iDuration);

		pTemp->iOffset=0;
		if(SearchStAreaMscTimeOffsetItem(pTemp->sSettCity,&ptCur)==FOUND)
			pTemp->iOffset=ptCur->iOffset;

		if(iCnt==1&&iFlag==false)
			strcpy(pTemp->sSplitFlag,"E");
		else	strcpy(pTemp->sSplitFlag,"X");
		
		if(InsertBin(pptRoot,pTemp,data_search_st_prep_ticket_e,
			assign_insert_bintree_st_prep_ticket_e)<0){
			WriteProcMsg("生成二叉树 StPrepTicketStruct 失败.");
			return -1;
		}
		
		if(iCnt>1||iFlag==true){
		
			if((ptPre=(struct StPrepTicketCtlStruct *)malloc(
				sizeof(struct StPrepTicketCtlStruct)))==NULL){
				WriteAlertMsg("拆单申请空间struct StPrepTicketCtlStruct 失败.");
				return 0;
			}
			memset((void*)ptPre,0,sizeof(struct StPrepTicketCtlStruct));
			strcpy(ptPre->sRowID,p->sRowID);
			strcpy(ptPre->sAuditType,"0");
			ptPre->cPreFlag=p->cPreFlag;
			ptPre->pTicket=pTemp;
			
			if(InsertBin(&pTicketCtlRoot,ptPre,data_search_st_prep_ticket_ctl_e,
				assign_insert_bintree)<0){
				WriteProcMsg("生成二叉树 StPrepTicketCtlStruct 失败.");
				return -1;
			}
		}
	}
	
	return 0;
}
int InitPrepTicketCtl(struct StPrepTicketStruct *p)
{
	struct StPrepTicketCtlStruct *pTemp;
	
	if((pTemp=(struct StPrepTicketCtlStruct *)malloc(
		sizeof(struct StPrepTicketCtlStruct)))==NULL){
		WriteAlertMsg("拆单申请空间struct StPrepTicketCtlStruct 失败.");
		return 0;
	}
	strcpy(pTemp->sRowID,p->sRowID);
	strcpy(pTemp->sAuditType,"0");
	pTemp->pTicket=p;
	
	if(InsertBin(&pTicketCtlRoot,pTemp,data_search_st_prep_ticket_ctl_e,
		assign_insert_bintree)<0){
		WriteProcMsg("生成二叉树 StPrepTicketCtlStruct 失败.");
		return -1;
	}
	
	return 0;
}
int SplitCallTypePrepTicket(struct StPrepTicketStruct *p,struct StPrepTicketStruct *ptCur,
	struct StPrepTicketStruct *ptPre)
{
	
	memcpy((void*)ptCur,(void*)p,sizeof(struct StPrepTicketStruct));
/*非呼转话单不做以下处理*/
	if(strcmp(p->sCallType,"24")!=0&&strcmp(p->sCallType,"22")!=0) return false;

	memcpy((void*)ptPre,(void*)p,sizeof(struct StPrepTicketStruct));
/*第三方是联通移动*/	
	if(IS_UNICOM_GSM(p->sThirdParty)||IS_UNICOM_WCDMA(p->sThirdParty)){
	/*对端为联通移动*/
		if(IS_UNICOM_GSM(p->sOtherParty)||IS_UNICOM_WCDMA(p->sOtherParty)){
			return false;
		}
		else{
			strcpy(ptCur->sCallType,"01");
			strcpy(ptCur->sSplitFlag,"X");

			return false;
		}
	}
	else{
		/*对端为联通移动*/
		if(IS_UNICOM_GSM(p->sOtherParty)||IS_UNICOM_WCDMA(p->sOtherParty)){
			strcpy(ptCur->sCallType,"02");
			strcpy(ptCur->sOtherParty,ptPre->sThirdParty);
			strcpy(ptCur->sSplitFlag,"X");
			return false;
		}
		else{
			/*呼转话单拆成2条*/	
			strcpy(ptCur->sCallType,"01");
			strcpy(ptCur->sSplitFlag,"X");
			
			strcpy(ptPre->sCallType,"02");
			strcpy(ptPre->sOtherParty,ptPre->sThirdParty);
			strcpy(ptPre->sSplitFlag,"X");
			
			return true;
		}
	}

}
int InitPrepTicketBintree(int iFlag,char cFlag,char sTableName[],char sCondition[],int iTimeFlag,char sDetailDate[],BINTREE **pptRoot)
{
	struct StPrepTicketStruct Temp,*pTemp,CurTemp,PreTemp;
	struct StPrepTicketStructIn TempIn;
	int iTotalCnt=0,iSplitFlag=false,iCnt=0;
	
	memset((void*)&TempIn,0,sizeof(struct StPrepTicketStructIn));
	memset((void*)&Temp,0,sizeof(struct StPrepTicketStruct));
	memset((void*)&CurTemp,0,sizeof(struct StPrepTicketStruct));
	memset((void*)&PreTemp,0,sizeof(struct StPrepTicketStruct));
	
	sprintf(TempIn.sTableName,"%s",sTableName);
	sprintf(TempIn.sCondition,"%s",sCondition);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetStPrepTicketToStruct(&Temp,&TempIn)){
		
	/*iSplitFlag为TRUE时候该话单有备拆单，这里暂只拆计费侧的呼转话单即CALL_TYPE=‘24’,
		CurTemp,PreTemp为拆单后的结果存储数据，如果未拆单则直接存储到CruTemp上，
		PreTemp不存储数据*/
	/*	
		if(strncmp(Temp.sStartTime,sDetailDate,8)==0)
			Temp.cPreFlag='N';
		else	Temp.cPreFlag='Y';
	*/
		Temp.cPreFlag=cFlag;
	
		if((iSplitFlag=SplitCallTypePrepTicket(&Temp,&CurTemp,&PreTemp))==true){
			strcpy(PreTemp.sAuditType,"3");
			strcpy(PreTemp.sSplitFlag,"E");
			PreTemp.sFirstFlag='F';
			if(SplitLongDurationPrepTicket(iFlag,&PreTemp,iSplitFlag,pptRoot)<0) return -1;
		}
		
		strcpy(CurTemp.sAuditType,"3");
		strcpy(CurTemp.sSplitFlag,"E");
		CurTemp.sFirstFlag='F';
		if(SplitLongDurationPrepTicket(iFlag,&CurTemp,iSplitFlag,pptRoot)<0) return -1;

		if((++iTotalCnt)%10000==0){
			WriteProcMsg("当前加载表 %s 数据记录数 %d 条.",sTableName,iTotalCnt);
		}
	}
	
	WriteProcMsg("加载表 %s 总数据记录数 %d 条.",sTableName,iTotalCnt);
	
	return 0;
}

int DestroyPrepTicket(BINTREE *ptRoot)
{
	struct StPrepTicketStruct *ptLkHead,*pTemp;
	
	gpTicketList=NULL;
	
	TravelBin(ptRoot,append_bintree_to_list_st_prep_ticket_e);
	
	while(gpTicketList!=NULL){
		
		ptLkHead=gpTicketList;
		gpTicketList=gpTicketList->pLoadNext;
		
		while(ptLkHead!=NULL){
			pTemp=ptLkHead;
			ptLkHead=ptLkHead->pNext;
			
			free(pTemp);
			pTemp=NULL;
		}
	}
	DestroyBin(ptRoot);
	return 0;
}
int DestroyPrepTicketCtl(BINTREE *ptRoot)
{
	struct StPrepTicketCtlStruct *ptLkHead,*pTemp;
	
	gpTicketList=NULL;
	
	TravelBin(ptRoot,append_bintree_to_list_st_prep_ticket_ctl_e);
	
	while(gpTicketCtlList!=NULL){
		
		ptLkHead=gpTicketCtlList;
		gpTicketCtlList=gpTicketCtlList->pLoadNext;
		
		while(ptLkHead!=NULL){
			pTemp=ptLkHead;
			ptLkHead=ptLkHead->pNext;
			pTemp->pTicket=NULL;
			free(pTemp);
			pTemp=NULL;
		}
	}
	DestroyBin(ptRoot);
	return 0;
}
int SetAuditDetailNotFound(struct StPrepTicketStruct *ptHead,char sFlag[])
{
	struct StPrepTicketStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strcpy(pTemp->sAuditType,sFlag);
	}
	
	return 0;
}

int CheckAllTimeAndDuration(char sServiceType[],int iSubTime,int iSubDuration)
{
	
	if(strcmp(sServiceType,"STT")==0){
		if(abs(iSubTime)<120&&abs(iSubDuration)<4){
			return true;
		}
	}
	else if(strcmp(sServiceType,"SMS")==0){
		if(abs(iSubTime)<600){
			return true;
		}
	}
	else if(strcmp(sServiceType,"MMS")==0){
		if(abs(iSubTime)<5){
			return true;
		}
	}
	
	return false;
}
int CheckTimeAndDuration(char sServiceType[],int iSubTime,int iSubDuration)
{
	
	if(strcmp(sServiceType,"STT")==0){
	/*	if(iSubTime>iSubDuration) return false;*/
		
		if(abs(iSubTime)<60&&abs(iSubDuration)<4){
			return true;
		}
	}
	else if(strcmp(sServiceType,"SMS")==0){
		if(abs(iSubTime)<5){
			return true;
		}
	}
	else if(strcmp(sServiceType,"MMS")==0){
		if(abs(iSubTime)<5){
			return true;
		}
	}
	
	return false;
}
/*比对全*/
int AuditKeyDetail(char sServiceType[],struct StPrepTicketStruct *p,
	struct StPrepTicketStruct *ptHead,struct StPrepTicketStruct **pptCur)
{
	struct StPrepTicketStruct *pTemp,*ptCur;
	int iRes=0,iDuration=0;
	double dRes;
	
	*pptCur=NULL;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->sOtherParty,p->sOtherParty)==0) continue;
		if(strcmp(pTemp->sAuditType,"1")==0) continue;
		
		iRes=tGetTime(pTemp->sStartTime)-tGetTime(p->sStartTime);
		iDuration=pTemp->iDuration-p->iDuration;
		
		if(CheckTimeAndDuration(sServiceType,iRes,iDuration)==true){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	
	return 0;
}

int AuditAllKeyFoundDetail(char sServiceType[],struct StPrepTicketStruct *p,
	struct StPrepTicketStruct *ptHead,struct StPrepTicketStruct **pptCur)
{
	struct StPrepTicketStruct *pTemp,*ptCur;
	int iRes=0,iDuration=0;
	double dRes;
	
	*pptCur=NULL;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->sOtherParty,p->sOtherParty)!=0) continue;
		if(strcmp(pTemp->sAuditType,"1")==0) continue;
	/*先直接匹配，不涉及到偏移量*/	
		iRes=tGetTime(pTemp->sStartTime)-tGetTime(p->sStartTime);
		iDuration=pTemp->iDuration-p->iDuration;
		
		if(CheckAllTimeAndDuration(sServiceType,iRes,iDuration)==true){
			*pptCur=pTemp;
			return FOUND;
		}
	/*再前面无法匹配上时候再增加偏移量，进行匹配*/	
		if(pTemp->iOffset==0) continue;
		iRes=iRes+pTemp->iOffset;
		if(CheckAllTimeAndDuration(sServiceType,iRes,iDuration)==true){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	
	return NOTFOUND;
}

int AuditDetailProcess(char sServiceType[])
{
	struct StPrepTicketStruct *ptHead=NULL,*ptLkHead=NULL,*pTemp=NULL,*ptCur=NULL;
	
	gpTicketList=NULL;
	TravelBin(pAccRoot,append_bintree_to_list_st_prep_ticket_e);
	
	while(gpTicketList!=NULL){
		ptHead=gpTicketList;
		gpTicketList=gpTicketList->pLoadNext;
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			
			if(SearchBin(pOdsRoot,pTemp,data_search_st_prep_ticket_e,
				(void**)&ptLkHead)==FOUND){
				
				if(ptLkHead->sFirstFlag=='F'){
					SetAuditDetailNotFound(ptLkHead,"0");
					ptLkHead->sFirstFlag='X';
				}
				
				if(AuditAllKeyFoundDetail(sServiceType,pTemp,ptLkHead,&ptCur)==FOUND){
					strcpy(ptCur->sAuditType,"1");
					strcpy(pTemp->sAuditType,"1");
					strcpy(pTemp->sOppUsageEventID,ptCur->sUsageEventID);
					strcpy(ptCur->sOppUsageEventID,pTemp->sUsageEventID);
				}
				else{
					if(AuditKeyDetail(sServiceType,pTemp,ptLkHead,&ptCur)==FOUND){
						strcpy(ptCur->sAuditType,"2");
						strcpy(pTemp->sAuditType,"2");
						strcpy(pTemp->sOppUsageEventID,ptCur->sUsageEventID);
						strcpy(ptCur->sOppUsageEventID,pTemp->sUsageEventID);
					}
					else	strcpy(pTemp->sAuditType,"0");
				}
			}
			else{
			/*节点没找着的，则表示该节点下所有数据在对方数据里都是无法查找到的，
				故该节点下所有数据就不在重复查找，直接设置成无法找到即可,节点为CALL_TYPE,MSISDN*/
				
				SetAuditDetailNotFound(pTemp,"3");
				
				break;
			}
			
		}
		
	}
	
	return 0;
}

/*更新数据*/
int UpdateStPrepTicket(char sTableName[],BINTREE *ptRoot)
{
	struct StPrepTicketStruct *ptHead=NULL,*ptLkHead=NULL,*pTemp=NULL,*ptCur=NULL;
	struct StPrepTicketStructUp TempUp;
	int iTotalCnt=0;
	
	memset((void*)&TempUp,0,sizeof(struct StPrepTicketStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
	
	gpTicketList=NULL;
	TravelBin(ptRoot,append_bintree_to_list_st_prep_ticket_e);
	
	while(gpTicketList!=NULL){
		ptHead=gpTicketList;
		gpTicketList=gpTicketList->pLoadNext;
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			
			if(strcmp(pTemp->sSplitFlag,"X")==0||pTemp->cPreFlag=='Y') continue;
			
			if(EUpdateStructToStPrepTicket(pTemp,false,&TempUp)<0){
				WriteProcMsg("更新表 %s 错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			if((++iTotalCnt)%10000==0){
				if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
					WriteProcMsg("更新表 %s 错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前更新数据到 %s 表记录数 %d 条.",
					sTableName,iTotalCnt);
			}
		}
	}
	
	if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
		WriteProcMsg("更新表 %s 错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	WriteProcMsg("当前更新数据到 %s 表总记录数 %d 条.",sTableName,iTotalCnt);

	return 0;
}

void CheckStPrepTicketListState(struct StPrepTicketCtlStruct *ptHead,char sAuditType[])
{
	struct StPrepTicketCtlStruct *pTemp;
	struct StPrepTicketStruct *p;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		p=pTemp->pTicket;
		
		if(strcmp(p->sAuditType,"0")==0){
			strcpy(sAuditType,"0");
			return ;
		}
	}
	strcpy(sAuditType,"1");
}
/*更新拆单数据*/
int UpdateStPrepSplitTicket(char sTableName[],BINTREE *ptRoot)
{
	struct StPrepTicketCtlStruct *ptHead=NULL;
	struct StPrepTicketStruct Temp;
	struct StPrepTicketStructUp TempUp;
	int iTotalCnt=0;
	
	memset((void*)&TempUp,0,sizeof(struct StPrepTicketStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
	gpTicketCtlList=NULL;
	TravelBin(ptRoot,append_bintree_to_list_st_prep_ticket_ctl_e);
	
	while(gpTicketCtlList!=NULL){
		ptHead=gpTicketCtlList;
		gpTicketCtlList=gpTicketCtlList->pLoadNext;
		
		if(ptHead->cPreFlag=='Y') continue;
		
		CheckStPrepTicketListState(ptHead,Temp.sAuditType);
		strcpy(Temp.sRowID,ptHead->sRowID);
		strcpy(Temp.sOppUsageEventID,ptHead->pTicket->sOppUsageEventID);
		
		if(EUpdateStructToStPrepTicket(&Temp,false,&TempUp)<0){
			WriteProcMsg("更新表1 %s 错误.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		if((++iTotalCnt)%10000==0){
			if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
				WriteProcMsg("更新表2 %s 错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
			WriteProcMsg("当前更新拆单数据到 %s 表记录数 %d 条.",
				sTableName,iTotalCnt);
		}
	}
	
	if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
		WriteProcMsg("更新表3 %s 错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	WriteProcMsg("当前更新拆单数据到 %s 表总记录数 %d 条.",sTableName,iTotalCnt);

	return 0;
}

int main(int argc, char **argv)
{
	char sServiceType[5],sDetailDate[9],sPart[31],sCurCondition[256];
	char sAccTableName[128],sOdsTableName[128],sMonth[3],sPreMonth[3];
	char sPreAccTable[128],sPreOdsTable[128],sPreCondition[256];
	char sStartTime[15],sEndTime[15],sCurTime[15],sPreTime[15],sPreDate[9];
	char sNextMonth[3],sNextAccTable[128],sNextOdsTable[128],sNextCondition[256];
	char sNextTime[15],sNextDate[9],sPlat[5],sCurDay[3],sPreDay[3],sNextDay[3];
	int iGroupID=0;

	if(argc!=4){
		printf("Useage:%s detaildate[20141010,YYYYMMDD] service[STT,SMS,MMS] plat[ACC,LOC]\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
	
	strcpy(sDetailDate,argv[1]);Upper(sDetailDate);
	strcpy(sServiceType,argv[2]);Upper(sServiceType);
	strcpy(sPlat,argv[3]);Upper(sPlat);
	
	if(ChkDate(sDetailDate)<0){
		WriteAlertPrint("输入时间【%s】参数异常,YYYYMMDD.",sDetailDate);
		return -1;
	}
	
	if(strcmp(sServiceType,"STT")!=0&&strcmp(sServiceType,"SMS")!=0&&
		strcmp(sServiceType,"MMS")!=0){
		WriteAlertPrint("输入的业务类型【%s】异常.",sServiceType);
		return -1;
	}

/*加载数据*/
	strncpy(sMonth,sDetailDate+4,2);sMonth[2]=0;
	strncpy(sCurDay,sDetailDate+6,2);sCurDay[2]=0;
	
	GetHostTime(sStartTime);
	sprintf(sCurTime,"%s220000",sDetailDate);
	strcpy(sPreTime,sCurTime);
	sprintf(sCurTime,"%s020000",sDetailDate);
	strcpy(sNextTime,sCurTime);
	
	AddTimes(sPreTime,-86400);
	AddTimes(sNextTime,86400);

	strncpy(sPreMonth,sPreTime+4,2);sPreMonth[2]=0;
	strncpy(sPreDay,sPreTime+6,2);sPreDay[2]=0;
	strncpy(sPreDate,sPreTime,8);sPreDate[8]=0;
	
	strncpy(sNextMonth,sNextTime+4,2);sNextMonth[2]=0;
	strncpy(sNextDay,sNextTime+6,2);sNextDay[2]=0;
	strncpy(sNextDate,sNextTime,8);sNextDate[8]=0;
	
	while(iGroupID<=100){

		sprintf(sAccTableName," ST_%s_PREP_%s_%s%s ",sPlat,sServiceType,sMonth,sCurDay);
		sprintf(sOdsTableName," ST_ODS_PREP_%s_%s%s ",sServiceType,sMonth,sCurDay);
		
		sprintf(sPreAccTable," ST_%s_PREP_%s_%s%s ",sPlat,sServiceType,sPreMonth,sPreDay);
		sprintf(sPreOdsTable," ST_ODS_PREP_%s_%s%s ",sServiceType,sPreMonth,sPreDay);
		
		sprintf(sNextAccTable," ST_%s_PREP_%s_%s%s ",sPlat,sServiceType,sNextMonth,sNextDay);
		sprintf(sNextOdsTable," ST_ODS_PREP_%s_%s%s ",sServiceType,sNextMonth,sNextDay);
		
		sprintf(sCurCondition," PARTITION(PART%02d) ",iGroupID);
		sprintf(sPreCondition," PARTITION(PART%02d) WHERE START_TIME>='%s'",iGroupID,sPreTime);
		sprintf(sNextCondition," PARTITION(PART%02d) WHERE START_TIME<='%s'",iGroupID,sNextTime);
	/*加载结算方数据*/
		if(InitPrepTicketBintree(false,'N',sAccTableName,sCurCondition,0,sDetailDate,&pAccRoot)<0){
			WriteAlertMsg("加载结算方表数据失败,[%s%s].",sAccTableName,sCurCondition);
			return -1;
		}
		if(InitPrepTicketBintree(false,'Y',sPreAccTable,sPreCondition,0,sDetailDate,&pAccRoot)<0){
			WriteAlertMsg("加载结算方表数据失败,[%s%s].",sPreAccTable,sPreCondition);
			return -1;
		}
		if(InitPrepTicketBintree(false,'Y',sNextAccTable,sNextCondition,0,sDetailDate,&pAccRoot)<0){
			WriteAlertMsg("加载结算方表数据失败,[%s%s].",sNextAccTable,sNextCondition);
			return -1;
		}
		
	/*加载计费方数据*/	
		if(InitPrepTicketBintree(true,'N',sOdsTableName,sCurCondition,0,sDetailDate,&pOdsRoot)<0){
			WriteAlertMsg("加载计费方表数据失败,[%s%s].",sOdsTableName,sCurCondition);
			return -1;
		}
		if(InitPrepTicketBintree(true,'Y',sPreOdsTable,sPreCondition,0,sDetailDate,&pOdsRoot)<0){
			WriteAlertMsg("加载计费方表数据失败,[%s%s].",sPreOdsTable,sPreCondition);
			return -1;
		}
		if(InitPrepTicketBintree(true,'Y',sNextOdsTable,sNextCondition,0,sDetailDate,&pOdsRoot)<0){
			WriteAlertMsg("加载计费方表数据失败,[%s%s].",sNextOdsTable,sNextCondition);
			return -1;
		}
		
	/*数据比对*/	
		if(AuditDetailProcess(sServiceType)<0){
			WriteAlertMsg("比对数据失败.");
			return -1;
		}
		
		if(UpdateStPrepTicket(sAccTableName,pAccRoot)<0){
			WriteAlertMsg("更新结算侧表 %s 数据失败.",sAccTableName);
			return -1;
		}
		if(UpdateStPrepTicket(sOdsTableName,pOdsRoot)<0){
			WriteAlertMsg("更新计费侧表 %s 数据失败.",sOdsTableName);
			return -1;
		}
		if(UpdateStPrepSplitTicket(sOdsTableName,pTicketCtlRoot)<0){
			WriteAlertMsg("更新计费侧表 %s 拆单数据失败.",sOdsTableName);
			return -1;
		}

		DestroyPrepTicketCtl(pTicketCtlRoot);
		pTicketCtlRoot=NULL;
		DestroyPrepTicket(pAccRoot);
		pAccRoot=NULL;
		DestroyPrepTicket(pOdsRoot);
		pOdsRoot=NULL;
		
		WriteProcMsg("处理分区 PART%02d 中的起始时间: %s ,结束时间: %s 数据完成.",iGroupID,sPreTime,sNextTime);
		iGroupID++;
	}
	GetHostTime(sEndTime);
	WriteProcMsg("处理分区 PART%s 数据完成,开始时间:%s,结束时间:%s.",sDetailDate,sStartTime,sEndTime);

	return 0;
}
