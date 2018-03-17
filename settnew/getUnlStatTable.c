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

struct AnStatUnunsalTicketStruct *gUnlListGe=NULL;
struct AnStatUnunsalTicketStruct *gUnlListCntDur=NULL;

int data_search_abnormal(void *pValue,void *pData)
{
	int iResult=0;
	
	struct AnStatUnunsalTicketStruct *pSource=(struct AnStatUnunsalTicketStruct*)pValue;
	struct AnStatUnunsalTicketStruct *pTarget=(struct AnStatUnunsalTicketStruct*)pData;
	
	if((iResult=strcmp(pSource->sHomeAreaCode,	pTarget->sHomeAreaCode))!=0) return iResult;
	if((iResult=strcmp(pSource->sMsisdn,		pTarget->sMsisdn))!=0) return iResult;
	if((iResult=strcmp(pSource->sSettDate,		pTarget->sSettDate))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyNbrType,		pTarget->sMyNbrType))!=0) return iResult;
	if((iResult=strcmp(pSource->sMy3gFlag,		pTarget->sMy3gFlag))!=0) return iResult;
	if((iResult=strcmp(pSource->sMyCarrID,		pTarget->sMyCarrID))!=0) return iResult;
	if((iResult=strcmp(pSource->sServFlag,		pTarget->sServFlag))!=0) return iResult;
			
	return iResult;
}
void assign_insert_bintree_abnormal(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int append_bintree_to_list_ge(void **ppData)
{
	struct AnStatUnunsalTicketStruct *pTemp=(struct AnStatUnunsalTicketStruct*)(*ppData);

	pTemp->pLoadNext=gUnlListGe;
	gUnlListGe=pTemp;

	return 0;
}
int append_bintree_to_list_cnt_dur(void **ppData)
{
	struct AnStatUnunsalTicketStruct *pTemp=(struct AnStatUnunsalTicketStruct*)(*ppData);

	pTemp->pLoadNext=gUnlListCntDur;
	gUnlListCntDur=pTemp;

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
int CheckParam(int argc,char **argv)
{	
	char sBillDate[9],sType[4],sNetWork[3];
		
	strcpy(sBillDate,argv[1]);
	strcpy(sType,argv[2]);
	
	if(ChkDate(sBillDate)<0) goto err_step;
	
	if(argc==3){
		if((strcmp(sType,"SMS")!=0) 
			&& (strcmp(sType,"MMS")!=0)) goto err_step;
	}
	else if(argc==4){
		strcpy(sNetWork,argv[3]);
		
		if((strcmp(sType,"STT")!=0)) goto err_step;
		
		if((strcmp(sNetWork,"YD")!=0) 
			&& (strcmp(sNetWork,"GW")!=0)) goto err_step;
	}
	else{
err_step:	printf("��������!\n");
		printf("	Usage: %s Billdate(YYYYMMDD) Type [NetWork] \n",argv[0]);
		printf("	Billdate˵��:���ڣ�YYYYMMDD��\n");
		printf("	Type˵��: 	STT Ϊ����,SMS Ϊ����,MMS Ϊ����\n");
		printf("	NetWork˵��: 	�ƶ�:YD������:GW\n");
		return -1;
	}
	
	return 0;
}
void GetInFeeOrOutFeeFlag(char sProdID[],char sFlag[],
	struct TicketTypeMapStruct *pTicketType)
{
	struct TicketTypeMapStruct *pFound=NULL;
	struct TicketTypeMapStruct Temp;

	bzero((void*)&Temp,sizeof(struct TicketTypeMapStruct));
	
	strcpy(Temp.sProdID,sProdID);
	strcpy(sFlag,"");

	if(SearchList((LIST *)pTicketType,(void *)&Temp,(LIST **)&pFound,
		comp_list_ticket_type_map)==FOUND){
			
		sprintf(sFlag,"%s",pFound->sFeeType);
	}
	
}
void GetInFeeOrOutCntDurFlag(char sProdID[],char sFlag[],
	struct TicketTypeMapStruct *pTicketType)
{
	struct TicketTypeMapStruct *pFound=NULL;
	struct TicketTypeMapStruct Temp;

	bzero((void*)&Temp,sizeof(struct TicketTypeMapStruct));
	
	strcpy(Temp.sProdID,sProdID);
	strcpy(sFlag,"");

	if(SearchList((LIST *)pTicketType,(void *)&Temp,(LIST **)&pFound,
		comp_list_ticket_type_map)==FOUND){
			
		sprintf(sFlag,"%s",pFound->sCallType);
	}
	
}
void mvMidSttTickettoAbnormaltable(struct TemplateMidSttTicketStruct *pi,
	struct AnStatUnunsalTicketStruct *po)
{
	char sFeeType[2];
	bzero((void*)po,sizeof(struct AnStatUnunsalTicketStruct));

	strcpy(po->sHomeAreaCode,	pi->sHomeAreaCode);
	strcpy(po->sMsisdn,		pi->sMsisdn);
	strcpy(po->sSettDate,		pi->sSettDate);
	
	/*֧��*/
	po->iInFee=0;
	po->iOutFee=pi->iSettFee;
	po->iCnt=pi->iCnt;
	po->iDuration=pi->iDuration;
	po->iSettDuration=pi->iSettDuration;

	strcpy(po->sMyNbrType,		pi->sMyNbrType);
	strcpy(po->sMy3gFlag,		pi->sMy3gFlag);
	strcpy(po->sMyCarrID,		pi->sMyCarrID);
	strcpy(po->sServFlag,		pi->sServFlag);

	AllTrim(po->sHomeAreaCode);
	AllTrim(po->sMsisdn);
	AllTrim(po->sSettDate);
	AllTrim(po->sMyNbrType);
	AllTrim(po->sMy3gFlag);
	AllTrim(po->sMyCarrID);
	AllTrim(po->sServFlag);
}
int GenBinTreeGe(struct TemplateMidSttTicketStruct *pMidTemp,
	struct TicketTypeMapStruct *pTicketType,BINTREE **pptRoot)
{
	char sFeeType[2];
	struct AnStatUnunsalTicketStruct TempUnl;
	struct AnStatUnunsalTicketStruct *ptFound=NULL;
	struct AnStatUnunsalTicketStruct *pTemp=NULL;
	
	strcpy(sFeeType,"");
	/*���� pi->sProdID�ж����뻹��֧��������֧�������߶��쳣ͳ��*/
	GetInFeeOrOutFeeFlag(pMidTemp->sProdID,sFeeType,pTicketType);
	if(strcmp(sFeeType,"0")!=0) return 0;
		
	mvMidSttTickettoAbnormaltable(pMidTemp,&TempUnl);
	
	if(SearchBin(*pptRoot,&TempUnl,data_search_abnormal,(void**)&ptFound)==FOUND){
		
		ptFound->iCnt += TempUnl.iCnt;
		ptFound->iDuration += TempUnl.iDuration;
		ptFound->iSettDuration += TempUnl.iSettDuration;
		ptFound->iInFee += TempUnl.iInFee;
		ptFound->iOutFee += TempUnl.iOutFee;
	}
	else{
		if((pTemp=(struct AnStatUnunsalTicketStruct*)
			malloc(sizeof(struct AnStatUnunsalTicketStruct)))==NULL){
			WriteProcMsg("malloc struct AnStatUnunsalTicketStruct ʧ��!!!");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct AnStatUnunsalTicketStruct));
		memcpy((void*)pTemp,(void*)&TempUnl,sizeof(struct AnStatUnunsalTicketStruct));

		if(InsertBin(pptRoot,pTemp,data_search_abnormal,
				assign_insert_bintree_abnormal)<0){
			WriteProcMsg("���ɶ����� AnStatUnunsalTicketStruct ʧ��.");
		 	return -1;
		}
	}
	
	return 0;
}
int GenBinTreeCntDur(struct TemplateMidSttTicketStruct *pMidTemp,
	struct TicketTypeMapStruct *pTicketType,BINTREE **pptRoot)
{
	char sCallType[2];
	struct AnStatUnunsalTicketStruct TempUnl;
	struct AnStatUnunsalTicketStruct *ptFound=NULL;
	struct AnStatUnunsalTicketStruct *pTemp=NULL;
	
	strcpy(sCallType,"");
	/*���� pi->sProdID�ж����л��Ǳ��У��������в�����Ƶ�����쳣ͳ��*/
	GetInFeeOrOutCntDurFlag(pMidTemp->sProdID,sCallType,pTicketType);
	if(strcmp(sCallType,"1")!=0) return 0;
		
	mvMidSttTickettoAbnormaltable(pMidTemp,&TempUnl);
	
	if(SearchBin(*pptRoot,&TempUnl,data_search_abnormal,(void**)&ptFound)==FOUND){
		
		ptFound->iCnt += TempUnl.iCnt;
		ptFound->iDuration += TempUnl.iDuration;
		ptFound->iSettDuration += TempUnl.iSettDuration;
		ptFound->iInFee += TempUnl.iInFee;
		ptFound->iOutFee += TempUnl.iOutFee;
	}
	else{
		if((pTemp=(struct AnStatUnunsalTicketStruct*)
			malloc(sizeof(struct AnStatUnunsalTicketStruct)))==NULL){
			WriteProcMsg("malloc struct AnStatUnunsalTicketStruct ʧ��!!!");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct AnStatUnunsalTicketStruct));
		memcpy((void*)pTemp,(void*)&TempUnl,sizeof(struct AnStatUnunsalTicketStruct));

		if(InsertBin(pptRoot,pTemp,data_search_abnormal,
				assign_insert_bintree_abnormal)<0){
			WriteProcMsg("���ɶ����� AnStatUnunsalTicketStruct ʧ��.");
		 	return -1;
		}
	}

	return 0;
}
int LoadMidSttToBintree(int iGroupID,char sBillDate[],char sTableNameIn[],
	struct TicketTypeMapStruct *pTicketType,BINTREE **pptRootGe,BINTREE **pptRootCntDur)
{
	unsigned long ulRecCnt=0;
	
	struct TemplateMidSttTicketStructIn TempIn;
	struct TemplateMidSttTicketStruct Temp;

	bzero((void*)&TempIn,sizeof(struct TemplateMidSttTicketStructIn));
	bzero((void*)&Temp,sizeof(struct TemplateMidSttTicketStruct));
	
	sprintf(TempIn.sTableName,"%s PARTITION(PART%s)",sTableNameIn,sBillDate);
	sprintf(TempIn.sCondition,"WHERE GROUP_ID='%02d'",iGroupID);
	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetTemplateMidSttTicketToStruct(&Temp,&TempIn)) {
		/*�߶�*/
		if(GenBinTreeGe(&Temp,pTicketType,pptRootGe)<0) return -1;
		/*��Ƶ������*/
		if(GenBinTreeCntDur(&Temp,pTicketType,pptRootCntDur)<0) return -1;
		
		ulRecCnt++;
	}
	WriteProcMsg("��ţ�%02d,�ӱ��� %s ��ȡ���� %d ��.",iGroupID,sTableNameIn,ulRecCnt);
	return 0;	
}

int InsertData2TableFee(int iInsertFalg,char sTableName[],struct AnStatUnunsalTicketStruct *pTemp)
{
	static int iCntfee=0;
	static int iFirstFlagFee=true;
	static struct AnStatUnunsalTicketStructOut TempOutFee;
	
	if(iFirstFlagFee==true){
		bzero(&TempOutFee,sizeof(struct AnStatUnunsalTicketStructOut));
		strcpy(TempOutFee.sTableName,sTableName);
		iFirstFlagFee=false;
	}
	if(iInsertFalg==true){
		if(EInsertStructToAnStatUnunsalTicket(NULL,true,&TempOutFee)<0){
			WriteProcMsg("д��%s����.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		CommitWork();
		WriteProcMsg("��ǰ������ݵ� %s ���¼�� %d ��.",
			sTableName,iCntfee);
	}
	else{
		if(++iCntfee%10000==0){
			if(EInsertStructToAnStatUnunsalTicket(NULL,true,&TempOutFee)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
			WriteProcMsg("��ǰ������ݵ� %s ���¼�� %d ��.",
				sTableName,iCntfee);
		}
		if(EInsertStructToAnStatUnunsalTicket(pTemp,false,&TempOutFee)<0){
			WriteProcMsg("д��%s����.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		
	}
	
	return 0;	
}
int InsertData2TableCnt(int iInsertFalg,char sTableName[],struct AnStatUnunsalTicketStruct *pTemp)
{
	static int iCntCnt=0;
	static int iFirstFlagCnt=true;
	static struct AnStatUnunsalTicketStructOut TempOutCnt;
	
	if(iFirstFlagCnt==true){
		bzero(&TempOutCnt,sizeof(struct AnStatUnunsalTicketStructOut));
		strcpy(TempOutCnt.sTableName,sTableName);
		iFirstFlagCnt=false;
	}
	if(iInsertFalg==true){
		if(EInsertStructToAnStatUnunsalTicket(NULL,true,&TempOutCnt)<0){
			WriteProcMsg("д��%s����.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		CommitWork();
		WriteProcMsg("��ǰ������ݵ� %s ���¼�� %d ��.",
			sTableName,iCntCnt);
	}
	else{
		if(++iCntCnt%10000==0){
			if(EInsertStructToAnStatUnunsalTicket(NULL,true,&TempOutCnt)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
			WriteProcMsg("��ǰ������ݵ� %s ���¼�� %d ��.",
				sTableName,iCntCnt);
		}
		if(EInsertStructToAnStatUnunsalTicket(pTemp,false,&TempOutCnt)<0){
			WriteProcMsg("д��%s����.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		
	}
	
	return 0;	
}
int InsertData2TableDur(int iInsertFalg,char sTableName[],struct AnStatUnunsalTicketStruct *pTemp)
{
	static int iCntDur=0;
	static int iFirstFlagDur=true;
	static struct AnStatUnunsalTicketStructOut TempOutDur;
	
	if(iFirstFlagDur==true){
		bzero(&TempOutDur,sizeof(struct AnStatUnunsalTicketStructOut));
		strcpy(TempOutDur.sTableName,sTableName);
		iFirstFlagDur=false;
	}
	if(iInsertFalg==true){
		if(EInsertStructToAnStatUnunsalTicket(NULL,true,&TempOutDur)<0){
			WriteProcMsg("д��%s����.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		CommitWork();
		WriteProcMsg("��ǰ������ݵ� %s ���¼�� %d ��.",
			sTableName,iCntDur);
	}
	else{
		if(++iCntDur%10000==0){
			if(EInsertStructToAnStatUnunsalTicket(NULL,true,&TempOutDur)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
			WriteProcMsg("��ǰ������ݵ� %s ���¼�� %d ��.",
				sTableName,iCntDur);
		}
		if(EInsertStructToAnStatUnunsalTicket(pTemp,false,&TempOutDur)<0){
			WriteProcMsg("д��%s����.",sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		
	}
	
	return 0;	
}

int EInsertListToAbnormalGE(int iLastflag,char sNetWork[],char sMonth[],
	struct AnStatUnunsalTicketStruct *ptHead)
{
	static int iFlag=true;
	static char sTableNameOutFee[31];
	
	struct AnStatUnunsalTicketStruct *ptCur=NULL;
	struct AnStatUnunsalTicketStruct *ptLoadCur=NULL;
	
	if(iFlag==true){	
		sprintf(sTableNameOutFee,"AN_STAT_UNL_TICKET_%s_GE_%s",sNetWork,sMonth);/*�߶�*/
  		iFlag=false;
  	}
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if(ptCur->iOutFee >= 300000){
				/*�߶�*/
				if(InsertData2TableFee(false,sTableNameOutFee,ptCur)<0) return -1;
			}
			free(ptCur);	
		}
	}
	if(iLastflag==true){
		if(InsertData2TableFee(true,sTableNameOutFee,NULL)<0) return -1;
	}
	return 0;
}
int EInsertListToAbnormalCntDur(int iLastflag,char sNetWork[],char sMonth[],
	struct AnStatUnunsalTicketStruct *ptHead)
{
	static int iFlag=true;
	static char sTableNameOutCnt[31];
	static char sTableNameOutDur[31];
	
	struct AnStatUnunsalTicketStruct *ptCur=NULL;
	struct AnStatUnunsalTicketStruct *ptLoadCur=NULL;
	
	if(iFlag==true){	
  		sprintf(sTableNameOutCnt,"AN_STAT_UNL_TICKET_%s_CP_%s",sNetWork,sMonth);/*��Ƶ*/
  		sprintf(sTableNameOutDur,"AN_STAT_UNL_TICKET_%s_CC_%s",sNetWork,sMonth);/*����*/
  		
  		iFlag=false;
  	}
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if(ptCur->iCnt >= 30){
				/*��Ƶ*/
				if(InsertData2TableCnt(false,sTableNameOutCnt,ptCur)<0) return -1;	
			}
			if(ptCur->iDuration >= 7200){
				/*����*/
				if(InsertData2TableDur(false,sTableNameOutDur,ptCur)<0) return -1;
			}
			free(ptCur);	
		}
	}
	if(iLastflag==true){
		if(InsertData2TableCnt(true,sTableNameOutCnt,NULL)<0) return -1;
		if(InsertData2TableDur(true,sTableNameOutDur,NULL)<0) return -1;
	}
	
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
int DealSttProcMain(char sNetWork[],char sMonth[],char sBillDate[])
{
	int i=0,iGroupID=0,iLastflag=false;
	char sTableNameIn[4][31];
	
	struct TicketTypeMapStruct *pTicketType=NULL;
	BINTREE *pRootGe=NULL;
	BINTREE *pRootCntDur=NULL;

  	sprintf(sTableNameIn[0],"ST_%s_M_TICKET_CM_%s_TEST",sNetWork,sMonth);
	sprintf(sTableNameIn[1],"ST_%s_M_TICKET_CT_%s_TEST",sNetWork,sMonth);
	sprintf(sTableNameIn[2],"ST_%s_M_TICKET_CTC_%s_TEST",sNetWork,sMonth);
	sprintf(sTableNameIn[3],"ST_%s_M_TICKET_CRC_%s_TEST",sNetWork,sMonth);
	
/*����ticket_type_map���ñ�*/
	if(GenTicketTypeMapList(&pTicketType)<0) return -1;	
  		
	/*��MSISDN����λ�������*/
	while(iGroupID<100){
		
		for(i=0;i<4;i++){		
			if(LoadMidSttToBintree(iGroupID,sBillDate,sTableNameIn[i],
				pTicketType,&pRootGe,&pRootCntDur)<0) return -1;
		}
		TravelBin(pRootGe,append_bintree_to_list_ge);
		TravelBin(pRootCntDur,append_bintree_to_list_cnt_dur);
		
		if(iGroupID==99) iLastflag=true;
		/*�߶�*/	
		if(EInsertListToAbnormalGE(iLastflag,sNetWork,sMonth,
			gUnlListGe)<0) return -1;
		/*��������Ƶ*/	
		if(EInsertListToAbnormalCntDur(iLastflag,sNetWork,sMonth,
			gUnlListCntDur)<0) return -1;
		
		DestroyBin(pRootGe);
		DestroyBin(pRootCntDur);
		pRootGe=NULL;
		pRootCntDur=NULL;
		gUnlListGe=NULL;
		gUnlListCntDur=NULL;
		iGroupID++;
	 }
	return 0;
}
int DealMsgProcMain(char sType[],char sMonth[],char sBillDate[])
{
	char sTableNameIn[31],sTableNameOut[31];

	return 0;
}

int main(int argc,char *argv[])
{
	char sMonth[3],sBillDate[9],sType[4],sNetWork[3];
	
	/*������*/	
	if(CheckParam(argc,argv)<0) return -1;

	strcpy(sBillDate,argv[1]);
	strcpy(sType,argv[2]);
	strncpy(sMonth,sBillDate+4,2);sMonth[2]=0;
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
	WriteProcMsg("�쳣����ͳ�Ƴ���ʼִ��...");
	if(argc == 3){
		/*���š�����*/
		if(DealMsgProcMain(sType,sMonth,sBillDate)<0) return -1;
	}
	else{
		/*����*/
		strcpy(sNetWork,argv[3]);
		if(DealSttProcMain(sNetWork,sMonth,sBillDate)<0) return -1;
		
	}
	WriteProcMsg("�쳣����ͳ�Ƴ���ִ�����.");
	DisconnectDatabase();	
	
	return 0;
}

