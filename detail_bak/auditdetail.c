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
/*�ڵ�ؼ���Ϊ���������͡����˺��롢�Զ˺��롢�û�����*/
	
	if((iResult=strcmp(pSource->sMsisdn,	pTarget->sMsisdn))!=0) return iResult;
	if((iResult=strcmp(pSource->sOtherParty,pTarget->sOtherParty))!=0) return iResult;
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
        struct DupKeyStruct *pSource=(struct DupKeyStruct *)pValue;
        struct DupKeyStruct *pTarget=(struct DupKeyStruct *)pHead;

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
int SplitLongDurationPrepTicket(struct StPrepTicketStruct *p,int iFlag,BINTREE **pptRoot)
{
	struct StPrepTicketStruct *pTemp;
	struct StPrepTicketCtlStruct *ptPre;
	int iCnt,i,iDuration;
	
	iCnt=(p->iDuration+1799)/1800;
	iDuration=p->iDuration%1800;

	for(i=0;i<iCnt;i++){
		
		if(i==iCnt-1){
			if(p->iDuration>1800)
				iDuration=p->iDuration%1800;
			else	iDuration=p->iDuration;
		}
		else	iDuration=1800;
		
		if((pTemp=(struct StPrepTicketStruct *)malloc(
			sizeof(struct StPrepTicketStruct)))==NULL){
			WriteAlertMsg("������ռ�struct StPrepTicketStructʧ��.");
			return 0;
		}
		memcpy((void*)pTemp,(void*)p,sizeof(struct StPrepTicketStruct));
		pTemp->pLoadNext=NULL;
		pTemp->pNext=NULL;
		pTemp->iDuration=iDuration;

		AddTimes(pTemp->sStartTime,i*1800);
		strcpy(pTemp->sEndTime,pTemp->sStartTime);
		AddTimes(pTemp->sEndTime,iDuration);

		if(iCnt==1&&iFlag==false)
			strcpy(pTemp->sSplitFlag,"E");
		else	strcpy(pTemp->sSplitFlag,"X");
		
		if(InsertBin(pptRoot,pTemp,data_search_st_prep_ticket_e,
			assign_insert_bintree_st_prep_ticket_e)<0){
			WriteProcMsg("���ɶ����� StPrepTicketStruct ʧ��.");
			return -1;
		}
		
		if(iCnt>1||iFlag==true){
		
			if((ptPre=(struct StPrepTicketCtlStruct *)malloc(
				sizeof(struct StPrepTicketCtlStruct)))==NULL){
				WriteAlertMsg("������ռ�struct StPrepTicketCtlStruct ʧ��.");
				return 0;
			}
			strcpy(ptPre->sRowID,p->sRowID);
			strcpy(ptPre->sAuditType,"0");
			ptPre->pTicket=pTemp;
			
			if(InsertBin(&pTicketCtlRoot,ptPre,data_search_st_prep_ticket_ctl_e,
				assign_insert_bintree)<0){
				WriteProcMsg("���ɶ����� StPrepTicketCtlStruct ʧ��.");
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
		WriteAlertMsg("������ռ�struct StPrepTicketCtlStruct ʧ��.");
		return 0;
	}
	strcpy(pTemp->sRowID,p->sRowID);
	strcpy(pTemp->sAuditType,"0");
	pTemp->pTicket=p;
	
	if(InsertBin(&pTicketCtlRoot,pTemp,data_search_st_prep_ticket_ctl_e,
		assign_insert_bintree)<0){
		WriteProcMsg("���ɶ����� StPrepTicketCtlStruct ʧ��.");
		return -1;
	}
	
	return 0;
}
int SplitCallTypePrepTicket(struct StPrepTicketStruct *p,struct StPrepTicketStruct *ptCur,
	struct StPrepTicketStruct *ptPre)
{
	
	memcpy((void*)ptCur,(void*)p,sizeof(struct StPrepTicketStruct));
/*�Ǻ�ת�����������´���*/
	if(strcmp(p->sCallType,"24")!=0) return false;

	memcpy((void*)ptPre,(void*)p,sizeof(struct StPrepTicketStruct));
/*����������ͨ�ƶ�*/	
	if(IS_UNICOM_GSM(p->sThirdParty)||IS_UNICOM_WCDMA(p->sThirdParty)){
	/*�Զ�Ϊ��ͨ�ƶ�*/
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
		/*�Զ�Ϊ��ͨ�ƶ�*/
		if(IS_UNICOM_GSM(p->sOtherParty)||IS_UNICOM_WCDMA(p->sOtherParty)){
			strcpy(ptCur->sCallType,"02");
			strcpy(ptCur->sOtherParty,ptPre->sThirdParty);
			strcpy(ptCur->sSplitFlag,"X");
			return false;
		}
		else{
			/*��ת�������2��*/	
			strcpy(ptCur->sCallType,"01");
			strcpy(ptCur->sSplitFlag,"X");
			
			strcpy(ptPre->sCallType,"02");
			strcpy(ptPre->sOtherParty,ptPre->sThirdParty);
			strcpy(ptPre->sSplitFlag,"X");
			
			return true;
		}
	}

}
int InitPrepTicketBintree(char sTableName[],char sCondition[],BINTREE **pptRoot)
{
	struct StPrepTicketStruct Temp,*pTemp,CurTemp,PreTemp;
	struct StPrepTicketStructIn TempIn;
	int iTotalCnt=0,iSplitFlag=false;
	
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
	
	*pptRoot=NULL;
	
	while(EGetStPrepTicketToStruct(&Temp,&TempIn)){
/*
		
		if(strcmp(Temp.sCallType,"24")==0)
			printf("-------���Զϵ�-------\n");
*/		
	/*iSplitFlagΪTRUEʱ��û����б��𵥣�������ֻ��ƷѲ�ĺ�ת������CALL_TYPE=��24��,
		CurTemp,PreTempΪ�𵥺�Ľ���洢���ݣ����δ����ֱ�Ӵ洢��CruTemp�ϣ�
		PreTemp���洢����*/
		if((iSplitFlag=SplitCallTypePrepTicket(&Temp,&CurTemp,&PreTemp))==true){
			strcpy(PreTemp.sAuditType,"0");
			strcpy(PreTemp.sSplitFlag,"E");
			if(SplitLongDurationPrepTicket(&PreTemp,iSplitFlag,pptRoot)<0) return -1;
		}
		
		strcpy(CurTemp.sAuditType,"0");
		strcpy(CurTemp.sSplitFlag,"E");
		if(SplitLongDurationPrepTicket(&CurTemp,iSplitFlag,pptRoot)<0) return -1;

		if((++iTotalCnt)%10000==0){
			WriteProcMsg("��ǰ���ر� %s ���ݼ�¼�� %d ��.",sTableName,iTotalCnt);
		}
	}
	
	WriteProcMsg("���ر� %s �����ݼ�¼�� %d ��.",sTableName,iTotalCnt);
	
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
int SetAuditDetailNotFound(struct StPrepTicketStruct *ptHead)
{
	struct StPrepTicketStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strcpy(pTemp->sAuditType,"0");
	}
	
	return 0;
}

int AuditKeyFoundDetail(char sServiceType[],struct StPrepTicketStruct *p,struct StPrepTicketStruct *ptHead,
	struct StPrepTicketStruct **pptCur)
{
	struct StPrepTicketStruct *pTemp,*ptCur;
	int iRes=0,iDuration=0;
	double dRes;
	
	*pptCur=NULL;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->sAuditType,"1")==0) continue;
		
		iRes=tGetTime(pTemp->sStartTime)-tGetTime(p->sStartTime);
		iDuration=pTemp->iDuration-p->iDuration;
		
		if(strcmp(sServiceType,"STT")==0){
			if(abs(iRes)<120&&abs(iDuration)<4){
				*pptCur=pTemp;
				return FOUND;
			}
		}
		else if(strcmp(sServiceType,"SMS")==0){
			if(abs(iRes)<5){
				*pptCur=pTemp;
				return FOUND;
			}
		}
		else if(strcmp(sServiceType,"MMS")==0){
			if(abs(iRes)<5){
				*pptCur=pTemp;
				return FOUND;
			}
		}
	}
	
	return NOTFOUND;
}

int AuditDeatilProcess(char sServiceType[])
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
				
				if(AuditKeyFoundDetail(sServiceType,pTemp,ptLkHead,&ptCur)==FOUND){
					strcpy(ptCur->sAuditType,"1");
					strcpy(pTemp->sAuditType,"1");
				}
				else{
					strcpy(pTemp->sAuditType,"0");
				}
			}
			else{
			/*�ڵ�û���ŵģ����ʾ�ýڵ������������ڶԷ������ﶼ���޷����ҵ��ģ�
				�ʸýڵ����������ݾͲ����ظ����ң�ֱ�����ó��޷��ҵ�����*/
				
				SetAuditDetailNotFound(pTemp);
				
				break;
			}
			
		}
		
	}
	
	return 0;
}

/*��������*/
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
			
			if(strcmp(pTemp->sSplitFlag,"X")==0) continue;
			
			if(EUpdateStructToStPrepTicket(pTemp,false,&TempUp)<0){
				WriteProcMsg("���±� %s ����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			if((++iTotalCnt)%10000==0){
				if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
					WriteProcMsg("���±� %s ����.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("��ǰ�������ݵ� %s ���¼�� %d ��.",
					sTableName,iTotalCnt);
			}
		}
	}
	
	if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
		WriteProcMsg("���±� %s ����.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	WriteProcMsg("��ǰ�������ݵ� %s ���ܼ�¼�� %d ��.",sTableName,iTotalCnt);

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
/*���²�����*/
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
		
		CheckStPrepTicketListState(ptHead,Temp.sAuditType);
		strcpy(Temp.sRowID,ptHead->sRowID);
		
		if(EUpdateStructToStPrepTicket(&Temp,false,&TempUp)<0){
			WriteProcMsg("���±� %s ����.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		if((++iTotalCnt)%10000==0){
			if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
				WriteProcMsg("���±� %s ����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
			WriteProcMsg("��ǰ���²����ݵ� %s ���¼�� %d ��.",
				sTableName,iTotalCnt);
		}
	}
	
	if(EUpdateStructToStPrepTicket(NULL,true,&TempUp)<0){
		WriteProcMsg("���±� %s ����.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	WriteProcMsg("��ǰ���²����ݵ� %s ���ܼ�¼�� %d ��.",sTableName,iTotalCnt);

	return 0;
}

int main(int argc, char **argv)
{
	char sServiceType[5],sDetailDate[9],sPart[31],sCondition[256],sCondition1[256];
	char sAccTableName[128],sOdsTableName[128],sMonth[3];
	char sStartTime[15],sEndTime[15];
	int iGroupID=0;

	if(argc!=3){
		printf("Useage:%s detaildate[20141010,YYYYMMDD] service[STT,SMS,MMS]\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
	
	strcpy(sDetailDate,argv[1]);Upper(sDetailDate);
	strcpy(sServiceType,argv[2]);Upper(sServiceType);
	
	if(ChkDate(sDetailDate)<0){
		WriteAlertPrint("����ʱ�䡾%s�������쳣,YYYYMMDD.",sDetailDate);
		return -1;
	}
	
	if(strcmp(sServiceType,"STT")!=0&&strcmp(sServiceType,"SMS")!=0&&
		strcmp(sServiceType,"MMS")!=0){
		WriteAlertPrint("�����ҵ�����͡�%s���쳣.",sServiceType);
		return -1;
	}

/*��������*/
	strncpy(sMonth,sDetailDate+4,2);sMonth[2]=0;
	GetHostTime(sStartTime);
	while(iGroupID<100){

		sprintf(sAccTableName," ST_ACC_PREP_%s_%s ",sServiceType,sMonth);
		sprintf(sOdsTableName," ST_ODS_PREP_%s_%s ",sServiceType,sMonth);

		sprintf(sCondition," PARTITION(PART%s) WHERE GROUP_ID='%02d' ",sDetailDate,iGroupID);
		sprintf(sCondition1," PARTITION(PART%s) WHERE GROUP_ID='%02d' ",sDetailDate,iGroupID);
	/*���ؽ��㷽����*/
		if(InitPrepTicketBintree(sAccTableName,sCondition1,&pAccRoot)<0){
			WriteAlertMsg("���ؽ��㷽������ʧ��,[%s%s].",sAccTableName,sCondition);
			return -1;
		}
	/*���ؼƷѷ�����*/	
		if(InitPrepTicketBintree(sOdsTableName,sCondition,&pOdsRoot)<0){
			WriteAlertMsg("���ؼƷѷ�������ʧ��,[%s%s].",sOdsTableName,sCondition);
			return -1;
		}
	/*���ݱȶ�*/	
		if(AuditDeatilProcess(sServiceType)<0){
			WriteAlertMsg("�ȶ�����ʧ��.");
			return -1;
		}
	/*���ݸ���*/
		
		if(UpdateStPrepTicket(sAccTableName,pAccRoot)<0){
			WriteAlertMsg("���½����� %s ����ʧ��.",sAccTableName);
			return -1;
		}
		if(UpdateStPrepTicket(sOdsTableName,pOdsRoot)<0){
			WriteAlertMsg("���¼ƷѲ�� %s ����ʧ��.",sOdsTableName);
			return -1;
		}
		if(UpdateStPrepSplitTicket(sOdsTableName,pTicketCtlRoot)<0){
			WriteAlertMsg("���¼ƷѲ�� %s ������ʧ��.",sOdsTableName);
			return -1;
		}
		
		DestroyPrepTicketCtl(pTicketCtlRoot);
		pTicketCtlRoot=NULL;
		DestroyPrepTicket(pAccRoot);
		pAccRoot=NULL;
		DestroyPrepTicket(pOdsRoot);
		pOdsRoot=NULL;
		
		WriteProcMsg("������� PART%s �ĵ� %02d �����������.",sDetailDate,iGroupID);
		iGroupID++;
	}
	GetHostTime(sEndTime);
	WriteProcMsg("������� PART%s �������,��ʼʱ��:%s,����ʱ��:%s.",sDetailDate,sStartTime,sEndTime);

	return 0;
}
