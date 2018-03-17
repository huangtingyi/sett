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

struct AnSettTop500TwStruct *gListTopTw=NULL;
struct AnSettTop500LtStruct *gListTopLt=NULL;

int data_search_stt_top_lt(void *pValue,void *pData)
{
	int iResult=0;
	
	struct AnSettTop500LtStruct *pSource=(struct AnSettTop500LtStruct*)pValue;
	struct AnSettTop500LtStruct *pTarget=(struct AnSettTop500LtStruct*)pData;
	
	if((iResult=strcmp(pSource->sSettLatnID,	pTarget->sSettLatnID))!=0) return iResult;
	if((iResult=strcmp(pSource->sCallType,		pTarget->sCallType))!=0) return iResult;
	if((iResult=strcmp(pSource->sHomeAreaCode,	pTarget->sHomeAreaCode))!=0) return iResult;
	if((iResult=strcmp(pSource->sMsisdn,		pTarget->sMsisdn))!=0) return iResult;
	if((iResult=strcmp(pSource->sSettDate,		pTarget->sSettDate))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyNbrType,		pTarget->sMyNbrType))!=0) return iResult;	
	if((iResult=strcmp(pSource->sMy3gFlag,		pTarget->sMy3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyCarrID,		pTarget->sMyCarrID))!=0) return iResult;
	if((iResult=strcmp(pSource->sServFlag,		pTarget->sServFlag))!=0) return iResult;
	
	return iResult;
}
int data_search_stt_top_tw(void *pValue,void *pData)
{
	int iResult=0;
	struct AnSettTop500TwStruct *pSource=(struct AnSettTop500TwStruct*)pValue;
	struct AnSettTop500TwStruct *pTarget=(struct AnSettTop500TwStruct*)pData;
	
	if((iResult=strcmp(pSource->sSettLatnID,	pTarget->sSettLatnID))!=0) return iResult;
	if((iResult=strcmp(pSource->sCallType,		pTarget->sCallType))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppAreaCode,	pTarget->sOppAreaCode))!=0) return iResult;
	if((iResult=strcmp(pSource->sOtherParty,	pTarget->sOtherParty))!=0) return iResult;
	if((iResult=strcmp(pSource->sSettDate,		pTarget->sSettDate))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppNbrType,	pTarget->sOppNbrType))!=0) return iResult;	
	if((iResult=strcmp(pSource->sMy3gFlag,		pTarget->sMy3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sOpp3gFlag,		pTarget->sOpp3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyCarrID,		pTarget->sMyCarrID))!=0) return iResult;
	if((iResult=strcmp(pSource->sOppCarrID,		pTarget->sOppCarrID))!=0) return iResult;
		
	return iResult;
}

void assign_insert_bintree_top_lt(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}
void assign_insert_bintree_top_tw(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int append_bintree_to_list_top_lt(void **ppData)
{
	struct AnSettTop500LtStruct *pTemp=(struct AnSettTop500LtStruct*)(*ppData);

	pTemp->pLoadNext=gListTopLt;
	gListTopLt=pTemp;

	return 0;
}
int append_bintree_to_list_top_tw(void **ppData)
{
	struct AnSettTop500TwStruct *pTemp=(struct AnSettTop500TwStruct*)(*ppData);

	pTemp->pLoadNext=gListTopTw;
	gListTopTw=pTemp;

	return 0;
}
int CheckParam(int argc,char **argv)
{	
	char sNetWork[3],sBillDate[9],sCarrID[4];
	
	if(argc==3){
		strcpy(sBillDate,argv[1]);
		strcpy(sNetWork,argv[2]);

		if(ChkDate(sBillDate)<0) goto err_step;
		
		if(strcmp(sNetWork,"YD")!=0 
			&& strcmp(sNetWork,"GW")!=0) goto err_step;
	}
		
	else if(argc==4){
		strcpy(sBillDate,argv[1]);
		strcpy(sNetWork,argv[2]);
		strcpy(sCarrID,argv[3]);
		
		if(ChkDate(sBillDate)<0) goto err_step;
			
		if(strcmp(sNetWork,"YD")!=0 
			&& strcmp(sNetWork,"GW")!=0) goto err_step;
			
		if(strcmp(sCarrID,"CM")!=0 
			&& strcmp(sCarrID,"CT")!=0
			&& strcmp(sCarrID,"CTC")!=0
			&& strcmp(sCarrID,"CRC")!=0) goto err_step;
	}
	else{
err_step:	
		printf("��������!\n");
		printf("	Usage: %s BillDate NetWork [CarrID]\n",argv[0]);
		printf("	BillDate˵��: 	ʱ�䣨YYYYMMDD��\n");
		printf("	NetWork˵��: 	����:YD������:GW\n");
		printf("	CarrID˵��(����ͳ��TOPʹ��): ����:CT������CDMA:CTC����ͨ��CRC���ƶ���CM\n");
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
int IsMidDateToTop500(char sProdID[],struct TicketTypeMapStruct *pTicketType)
{
	struct TicketTypeMapStruct *pFound=NULL;
	struct TicketTypeMapStruct Temp;

	bzero((void*)&Temp,sizeof(struct TicketTypeMapStruct));
	
	strcpy(Temp.sProdID,sProdID);


	if(SearchList((LIST *)pTicketType,(void *)&Temp,(LIST **)&pFound,
		comp_list_ticket_type_map)==FOUND){
			
		if(strcmp(pFound->sProdType,"1")==0) return 0;
	}	
	
	return -1;
}
void mvMidtable2TopLt(struct TemplateMidSttTicketStruct *pi,
	struct AnSettTop500LtStruct *po)
{
	bzero((void*)po,sizeof(struct AnSettTop500LtStruct));
	
	strcpy(po->sSettLatnID,		pi->sSettLatnID);
	strcpy(po->sCallType,		pi->sCallType);
	strcpy(po->sHomeAreaCode,	pi->sHomeAreaCode);
	strcpy(po->sMsisdn,		pi->sMsisdn);
	strcpy(po->sSettDate,		pi->sSettDate);
	
	po->iCnt=pi->iCnt;
	po->iDuration=pi->iDuration;
	po->iSettDuration=pi->iSettDuration;
	po->iSettFee=pi->iSettFee;

	strcpy(po->sMyNbrType,		pi->sMyNbrType);
	strcpy(po->sMy3gFlag,		pi->sMy3gFlag);
	strcpy(po->sMyCarrID,		pi->sMyCarrID);
	strcpy(po->sServFlag,		pi->sServFlag);
	
	AllTrim(po->sSettLatnID);
	AllTrim(po->sCallType);
	AllTrim(po->sHomeAreaCode);
	AllTrim(po->sMsisdn);
	AllTrim(po->sSettDate);
	AllTrim(po->sMyNbrType);
	AllTrim(po->sMy3gFlag);
	AllTrim(po->sMyCarrID);
	AllTrim(po->sServFlag);

}
int LoadMidTable2Top500Lt(int iGroupID,char sBilldate[],char sTableName[],
	struct TicketTypeMapStruct *pTicketType,BINTREE **pptRoot)
{
	unsigned long ulRecCnt=0;
	
	struct TemplateMidSttTicketStructIn TempIn;
	struct TemplateMidSttTicketStruct Temp;
	struct AnSettTop500LtStruct TopLtTemp;
	struct AnSettTop500LtStruct *pTemp=NULL;
	struct AnSettTop500LtStruct *ptFound=NULL;
	
	bzero((void*)&TempIn,sizeof(struct TemplateMidSttTicketStructIn));
	bzero((void*)&Temp,sizeof(struct TemplateMidSttTicketStruct));
	bzero((void*)&TopLtTemp,sizeof(struct AnSettTop500LtStruct));
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s)",sTableName,sBilldate);
	sprintf(TempIn.sCondition,"WHERE GROUP_ID='%02d'",iGroupID);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetTemplateMidSttTicketToStruct(&Temp,&TempIn)){
		
		/*��ȷ���Ƿ����Topͳ��*/
		if(IsMidDateToTop500(Temp.sProdID,pTicketType)<0) continue;
		
		mvMidtable2TopLt(&Temp,&TopLtTemp);	
		if(SearchBin(*pptRoot,&TopLtTemp,data_search_stt_top_lt,
			(void**)&ptFound)==FOUND){
				
			ptFound->iCnt += TopLtTemp.iCnt;
			ptFound->iDuration += TopLtTemp.iDuration;
			ptFound->iSettDuration += TopLtTemp.iSettDuration;
			ptFound->iSettFee += TopLtTemp.iSettFee;
		}
		else{
			if((pTemp=(struct AnSettTop500LtStruct*)
				malloc(sizeof(struct AnSettTop500LtStruct)))==NULL){
				WriteProcMsg("mallo struct AnSettTop500LtStruct ʧ�ܣ�����");
				return -1;
			}
			bzero((void*)pTemp,sizeof(struct AnSettTop500TwStruct));
			memcpy((void*)pTemp,(void*)&TopLtTemp,sizeof(struct AnSettTop500LtStruct));
			
			if(InsertBin(pptRoot,pTemp,data_search_stt_top_lt,
					assign_insert_bintree_top_lt)<0){
				WriteProcMsg("���ɶ����� TemplateSttTendStruct ʧ��.");
			 	return -1;
			}
		}
		ulRecCnt++;
	}

	WriteProcMsg("��ţ�%02d ,�ӱ��� %s ��ȡ���� %d ��.",iGroupID,sTableName,ulRecCnt);

	return 0;
}
int EInsertList2TableTop500Lt(char sTableName[],struct AnSettTop500LtStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct AnSettTop500LtStructOut TempOut;
	struct AnSettTop500LtStruct *ptCur=NULL;
	struct AnSettTop500LtStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct AnSettTop500LtStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToAnSettTop500Lt(NULL,true,&TempOut)<0){
					WriteProcMsg("д��%s����.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("��ǰ������ݵ� %s ���¼�� %lu ��.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToAnSettTop500Lt(ptCur,false,&TempOut)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			free(ptCur);
		}
	}
	if(EInsertStructToAnSettTop500Lt(NULL,true,&TempOut)<0){
		WriteProcMsg("д��%s����.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcMsg("������ݵ� %s ���ܼ�¼�� %lu ��.",sTableName,ulRecCnt);
	
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
			WriteProcMsg("malloc struct TicketTypeMapStruct ʧ��!!!");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct TicketTypeMapStruct));
		memcpy((void*)pTemp,(void*)&Temp,sizeof(struct TicketTypeMapStruct));
		
		InsertList((LIST **)ppHead,(LIST *)pTemp);
		iCnt++;
	}
	WriteProcMsg("�ӱ�%s�м��� %d �����ݵ�����.",TempIn.sTableName,iCnt);
	
	return 0;
}
int DealTop500LtProcMain(char sNetWork[],char sBilldate[])
{
	int iGroupID=0,i=0;
	char sTableNameIn[4][31],sTableNameOut[31],sMonth[3];
	
	struct TicketTypeMapStruct *pTicketType=NULL;
	BINTREE *pRoot=NULL;
	
	strncpy(sMonth,sBilldate+4,2);sMonth[2]=0;
	sprintf(sTableNameIn[0],"ST_%s_M_TICKET_CM_%s",sNetWork,sMonth);
	sprintf(sTableNameIn[1],"ST_%s_M_TICKET_CT_%s",sNetWork,sMonth);
	sprintf(sTableNameIn[2],"ST_%s_M_TICKET_CTC_%s",sNetWork,sMonth);
	sprintf(sTableNameIn[3],"ST_%s_M_TICKET_CRC_%s",sNetWork,sMonth);
	
	sprintf(sTableNameOut,"AN_%s_TOP_LT_%s",sNetWork,sMonth);

/*����ticket_type_map���ñ�*/
	if(GenTicketTypeMapList(&pTicketType)<0) return -1;
	
	while(iGroupID<100){
		for(i=0;i<4;i++){
		
			if(LoadMidTable2Top500Lt(iGroupID,sBilldate,sTableNameIn[i],pTicketType,&pRoot)<0) return -1;
		}

		TravelBin(pRoot,append_bintree_to_list_top_lt);
		
		if(EInsertList2TableTop500Lt(sTableNameOut,gListTopLt)<0) return -1;	
		
		DestroyBin(pRoot);
		pRoot=NULL;
		gListTopLt=NULL;
		iGroupID++;
	}

	
	return 0;
}

void mvMidtable2TopTw(struct TemplateMidSttTicketStruct *pi,
	struct AnSettTop500TwStruct *po)
{
	bzero((void*)po,sizeof(struct AnSettTop500TwStruct));
	
	strcpy(po->sSettLatnID,		pi->sSettLatnID);
	strcpy(po->sCallType,		pi->sCallType);
	strcpy(po->sOppAreaCode,	pi->sOppAreaCode);
	strcpy(po->sOtherParty,		pi->sOtherParty);
	strcpy(po->sSettDate,		pi->sSettDate);
	
	po->iCnt=pi->iCnt;
	po->iDuration=pi->iDuration;
	po->iSettDuration=pi->iSettDuration;
	po->iSettFee=pi->iSettFee;

	strcpy(po->sOppNbrType,		pi->sOppNbrType);
	strcpy(po->sMy3gFlag,		pi->sMy3gFlag);
	strcpy(po->sOpp3gFlag,		pi->sOpp3gFlag);
	strcpy(po->sMyCarrID,		pi->sMyCarrID);
	strcpy(po->sOppCarrID,		pi->sOppCarrID);
	
	AllTrim(po->sSettLatnID);
	AllTrim(po->sCallType);
	AllTrim(po->sOppAreaCode);
	AllTrim(po->sOtherParty);
	AllTrim(po->sSettDate);
	AllTrim(po->sOppNbrType);
	AllTrim(po->sMy3gFlag);
	AllTrim(po->sOpp3gFlag);
	AllTrim(po->sMyCarrID);
	AllTrim(po->sOppCarrID);
}
int LoadMidTable2Top500Tw(int iGroupID,char sBilldate[],char sTableName[],
	struct TicketTypeMapStruct *pTicketType,BINTREE **pptRoot)
{
	unsigned long ulRecCnt=0;
	
	struct TemplateMidSttTicketStructIn TempIn;
	struct TemplateMidSttTicketStruct Temp;
	struct AnSettTop500TwStruct TopTwTemp;
	struct AnSettTop500TwStruct *pTemp=NULL;
	struct AnSettTop500TwStruct *ptFound=NULL;
	
	bzero((void*)&TempIn,sizeof(struct TemplateMidSttTicketStructIn));
	bzero((void*)&Temp,sizeof(struct TemplateMidSttTicketStruct));
	bzero((void*)&TopTwTemp,sizeof(struct AnSettTop500TwStruct));
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s)",sTableName,sBilldate);
	sprintf(TempIn.sCondition,"WHERE OTHER_GROUP_ID='%02d'",iGroupID);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetTemplateMidSttTicketToStruct(&Temp,&TempIn)){
		
		/*��ȷ���Ƿ����Topͳ��*/
		if(IsMidDateToTop500(Temp.sProdID,pTicketType)<0) continue;
		
		mvMidtable2TopTw(&Temp,&TopTwTemp);
		
		if(SearchBin(*pptRoot,&TopTwTemp,data_search_stt_top_tw,
			(void**)&ptFound)==FOUND){
				
			ptFound->iCnt += TopTwTemp.iCnt;
			ptFound->iDuration += TopTwTemp.iDuration;
			ptFound->iSettDuration += TopTwTemp.iSettDuration;
			ptFound->iSettFee += TopTwTemp.iSettFee;	
		}
		else{
			if((pTemp=(struct AnSettTop500TwStruct*)
				malloc(sizeof(struct AnSettTop500TwStruct)))==NULL){
				WriteProcMsg("mallo struct AnSettTop500TwStruct ʧ�ܣ�����");
				return -1;
			}
			bzero((void*)pTemp,sizeof(struct AnSettTop500TwStruct));
			memcpy((void*)pTemp,(void*)&TopTwTemp,sizeof(struct AnSettTop500TwStruct));
			
			if(InsertBin(pptRoot,pTemp,data_search_stt_top_tw,
					assign_insert_bintree_top_tw)<0){
				WriteProcMsg("���ɶ����� TemplateSttTendStruct ʧ��.");
			 	return -1;
			}
		}
		ulRecCnt++;
	}
	
	WriteProcMsg("��ţ�%02d ,�ӱ��� %s ��ȡ���� %d ��.",iGroupID,sTableName,ulRecCnt);
	
	return 0;
}
int EInsertList2TableTop500Tw(char sTableName[],struct AnSettTop500TwStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct AnSettTop500TwStructOut TempOut;
	struct AnSettTop500TwStruct *ptCur=NULL;
	struct AnSettTop500TwStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct AnSettTop500TwStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToAnSettTop500Tw(NULL,true,&TempOut)<0){
					WriteProcMsg("д��%s����.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("��ǰ������ݵ� %s ���¼�� %lu ��.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToAnSettTop500Tw(ptCur,false,&TempOut)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			free(ptCur);
		}
	}
	if(EInsertStructToAnSettTop500Tw(NULL,true,&TempOut)<0){
		WriteProcMsg("д��%s����.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcMsg("������ݵ� %s ���ܼ�¼�� %lu ��.",sTableName,ulRecCnt);
	
	return 0;
}
int DealTop500TwProcMain(char sNetWork[],char sCarrID[],char sBilldate[])
{
	int iGroupID=0;
	char sTableNameIn[31],sTableNameOut[31],sMonth[3];
	
	struct TicketTypeMapStruct *pTicketType=NULL;
	BINTREE *pRoot=NULL;
	
	strncpy(sMonth,sBilldate+4,2);sMonth[2]=0;
	sprintf(sTableNameIn,"ST_%s_M_TICKET_%s_%s",sNetWork,sCarrID,sMonth);
	sprintf(sTableNameOut,"AN_%s_TOP_TW_%s",sNetWork,sMonth);

/*����ticket_type_map���ñ�*/
	if(GenTicketTypeMapList(&pTicketType)<0) return -1;
	
	while(iGroupID<100){
		
		if(LoadMidTable2Top500Tw(iGroupID,sBilldate,sTableNameIn,pTicketType,&pRoot)<0) return -1;
	
		TravelBin(pRoot,append_bintree_to_list_top_tw);
	
		if(EInsertList2TableTop500Tw(sTableNameOut,gListTopTw)<0) return -1;
		
		DestroyBin(pRoot);
		pRoot=NULL;
		gListTopTw=NULL;
		iGroupID++;
	}
	return 0;
}
int main(int argc,char **argv)
{
	
	char sNetWork[3],sBilldate[9],sCarrID[4];

	/*������*/	
	if(CheckParam(argc,argv)<0) return -1;
	
	strcpy(sBilldate,argv[1]);
	strcpy(sNetWork,argv[2]);

	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
		
	if(argc==3){
		WriteProcMsg("���� TOPͳ�Ƴ���ʼִ��...");
		if(DealTop500LtProcMain(sNetWork,sBilldate)<0) return -1;
	}
	else{
		WriteProcMsg("���� TOPͳ�Ƴ���ʼִ��...");
		
		strcpy(sCarrID,argv[3]);
		
		if(DealTop500TwProcMain(sNetWork,sCarrID,sBilldate)<0) return -1;
	}
	DisconnectDatabase();
	
	WriteProcMsg("TOPͳ�Ƴ���ִ�����.");
	return 0;
}
