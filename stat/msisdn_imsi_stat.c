#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

#include "dbsupp.h"
#include "msisdn_imsi.h"
#include "stt_ticket.h"
#include "ticket_field.h"
#include "param_intf.h"

int iCuUpdate=0,iCuInsert=0,iCnt=0;
BINTREE *pRootStat=NULL;
struct MsisdnImsiStatStructOut MsisdnUp;
struct MsisdnImsiStatStructOut MsisdnOut;


int CheckScpFlag(char *sScpFlag)
{
	if(strcmp(sScpFlag,"1")==0||
		strcmp(sScpFlag,"3") == 0)return 0;
	
	return -1;	
}
int data_search_bintree_msisdn_imsi_e(void *pValue,void*pData)
{
	struct MsisdnImsiStatStruct *pSource=(struct MsisdnImsiStatStruct *)pValue;
	struct MsisdnImsiStatStruct *pTarget=(struct MsisdnImsiStatStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
		
	return 0;
}
void insert_bintree_msisdn_imsi_e(void **ppData,void *pData)
{

	struct MsisdnImsiStatStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct MsisdnImsiStatStruct));
		ERROR_EXIT(pTemp==NULL,"����MsisdnImsiStatStruct�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct MsisdnImsiStatStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	strcpy(pTemp->sMsisdn,((struct MsisdnImsiStatStruct*)pData)->sMsisdn);
	strcpy(pTemp->sImsi,((struct MsisdnImsiStatStruct*)pData)->sImsi);
	strcpy(pTemp->sScpFlag,((struct MsisdnImsiStatStruct*)pData)->sScpFlag);
	strcpy(pTemp->sRowID,((struct MsisdnImsiStatStruct*)pData)->sRowID);
	
}
int data_search_bintree_msisdn_imsihh_e(void *pValue,void*pData)
{
	struct MsisdnImsiStatHHStruct *pSource=(struct MsisdnImsiStatHHStruct *)pValue;
	struct MsisdnImsiStatHHStruct *pTarget=(struct MsisdnImsiStatHHStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
		
	return 0;
}

int comp_insert_list_hh_e(LIST *pValue,LIST*pHead)
{
	struct MsisdnImsiStatHHStruct *pSource=(struct MsisdnImsiStatHHStruct *)pValue;
	struct MsisdnImsiStatHHStruct *pTarget=(struct MsisdnImsiStatHHStruct *)pHead;
/*��СʱHH��������**/
	return strcmp(pTarget->sHh,pSource->sHh);
}
void insert_bintree_msisdn_imsihh_e(void **ppHead,void *pData)
{

	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_hh_e);
	
}

int mvitem_hh2msisdnimsi(struct MsisdnImsiStatHHStruct *pi, struct MsisdnImsiStatStruct *po)
{
	bzero((void*)po,sizeof(struct MsisdnImsiStatStruct));

	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sImsi,pi->sImsi);
	strcpy(po->sScpFlag,pi->sScpFlag);
	strcpy(po->sRowID,pi->sRowID);
	
	return 0;
}


int mvitem_prep2msisdnimsiHH(struct PrepTicketStruct *pi, struct MsisdnImsiStatHHStruct *po)
{
	bzero((void*)po,sizeof(struct MsisdnImsiStatHHStruct));
	
	strcpy(po->sMsisdn,pi->sMsisdn);
	strcpy(po->sImsi,pi->sImsi);
	if(strcmp(pi->sScpFlag,"1")==0)
		strcpy(po->sScpFlag,"1");
	else if(strcmp(pi->sScpFlag,"3")==0)
		strcpy(po->sScpFlag,"3");
	else 	strcpy(po->sScpFlag,"0");
	
	strncpy(po->sHh,pi->sStartTime+8,2);

	strcpy(po->sRowID,pi->sRowID);
	return 0;
}

int GetMsisdnImsi2Root(BINTREE **pRoot,char *sTableName,char *sCondition)
{
	struct MsisdnImsiStatStruct Temp;
	struct MsisdnImsiStatStructIn TempIn;

/*��ʼ�����*/
	TempIn.iFirstFlag=true;
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,sCondition);
	
/*  �Ƚ�PREP_TICKET_TEMP���е�����ȡ����BITREE��  */
	while(EGetMsisdnImsiStatToStruct(&Temp,&TempIn)){
/*��ȡ�������ݲ��뵽BINTREE��*/
		if(InsertBin(pRoot,(void *)&Temp,
			data_search_bintree_msisdn_imsi_e,
			insert_bintree_msisdn_imsi_e)<0){
				WriteAlertMsg("����BINTREEʧ��prep_ticket_temp");
				return -1;
		}	
	}
	return 0;	
}

int msisdn_List2Db(void **ppData)
{
	struct MsisdnImsiStatStruct Temp,*pCur;
	struct MsisdnImsiStatHHStruct *pTemp;
	struct MsisdnImsiStatHHStruct *ptHead=(struct MsisdnImsiStatHHStruct *)*ppData;
/*ֻȡͷ�ڵ�*/

	mvitem_hh2msisdnimsi(ptHead,&Temp);
	
	
	if((SearchBin(pRootStat,(void *)&Temp,
		data_search_bintree_msisdn_imsi_e,(void *)&pCur) == FOUND)){
		
		if(strcmp(pCur->sImsi,"X")==0 ||
			strcmp(pCur->sScpFlag,"X")==0)
			return 0;
		if(strcmp(Temp.sImsi,pCur->sImsi)!=0&&
			strcmp(Temp.sScpFlag,pCur->sScpFlag)!=0){
					
			strcpy(pCur->sScpFlag,Temp.sScpFlag);
			strcpy(pCur->sImsi,Temp.sImsi);
			/*�������ݵ�����*/
			if(UpdateDateToMsisdnImsiStat(pCur,false,
				&MsisdnUp)!=0){
				WriteAlertMsg("���±�%s����.",MsisdnUp.sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
	
			strcpy(pCur->sScpFlag,"X");
			strcpy(pCur->sImsi,"X");
			iCuUpdate++;							
			return 0;
		}
		/*scp_flag�ĸ���*/
		if(strcmp(Temp.sScpFlag,pCur->sScpFlag)!=0){
			
			strcpy(pCur->sScpFlag,Temp.sScpFlag);
			/*�������ݵ�����*/
			if(UpdateDateToMsisdnImsiStat(pCur,false,
				&MsisdnUp)!=0){
				WriteAlertMsg("���±�%s����.",MsisdnUp.sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			strcpy(pCur->sScpFlag,"X");
			iCuUpdate++;
			return 0;			
		}						
		/*imsi�ĸ���*/
		if(strcmp(Temp.sImsi,pCur->sImsi)!=0){
			
			strcpy(pCur->sImsi,Temp.sImsi);
			/*�������ݵ�����*/
			if(UpdateDateToMsisdnImsiStat(pCur,false,
				&MsisdnUp)!=0){
				WriteAlertMsg("���±�%s����.",MsisdnUp.sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			strcpy(pCur->sImsi,"X");
			iCuUpdate++;
			return 0;		
		}
		
		strcpy(pCur->sScpFlag,"X");
		strcpy(pCur->sImsi,"X");
		if((iCuUpdate)%30000==0){
		
			/*�ύδ���µ�����*/
			if(UpdateDateToMsisdnImsiStat(NULL,true,&MsisdnUp)!=0){
				WriteAlertMsg("���±�%s����.",MsisdnUp.sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
	
			CommitWork();
			WriteProcMsg("�Ա�%s���¼�¼��%d",MsisdnUp.sTableName,iCuUpdate);
		}		
		return 0;		
	}
		
	/*�ύ���ݵ�����*/
	if(EInsertStructToMsisdnImsiStat(&Temp,
		false,&MsisdnOut)<0){
		WriteAlertMsg("д��%s����.",MsisdnOut.sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}

	if((++iCuInsert)%30000==0){
	
		/*�ύδ���������*/
		if(EInsertStructToMsisdnImsiStat(NULL,true,&MsisdnOut)<0){
			WriteAlertMsg("д��%s����.",MsisdnOut.sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
	
		CommitWork();
		WriteProcMsg("�Ա�%s�����¼��%d",MsisdnOut.sTableName,iCuInsert);
	}	
	
	return 0;
}
int main(int argc, char **argv)
{
	int  t1=0;
	char sInTableName[31],sOutTableName[31],sCondition[1024];
	char sStatDate[15],sChkDate[15],sDateTemp[15];
	char sTempCondition[1024];

	BINTREE *pRoot=NULL;
	
	struct MsisdnImsiStatHHStruct *p;
	
	struct MsisdnImsiStatStruct *pCur=NULL;
	
	struct PrepTicketStruct Temp;
	struct PrepTicketStructIn TempIn;
	
	if(argc != 4 && argc != 5){
		printf("Usage:%s intablename outtablename statdate [wherecase].\n",argv[0]);
		return -1;	
	}
	InitAppRes(argv[0]);
	
	strcpy(sTempCondition,"");
	
	strcpy(sInTableName,argv[1]);
	strcpy(sDateTemp,argv[3]);
	strcpy(sOutTableName,argv[2]);
	
	strcpy(sStatDate,sDateTemp);
        strcat(sStatDate,"000000");
        strcpy(sChkDate,sStatDate);
/*        strcat(sChkDate,"235959");*/
        
        if((t1=tGetTime(sStatDate))<0) return -1;
        if(AddTimes(sStatDate,86400)<0) return -1;
	
	if(argc == 5){
		sprintf(sCondition,
			"%s AND START_TIME>='%s' AND START_TIME<'%s' ",
			argv[4],sChkDate,sStatDate);	
	}
	else{
		sprintf(sCondition,
			"WHERE START_TIME>='%s' AND START_TIME<'%s' ",
			sChkDate,sStatDate);
	}
	
	if(ConnectDataDB()<0) return -1;
/*��ʼ�����*/	
	TempIn.iFirstFlag=true;
	strcpy(TempIn.sTableName,sInTableName);
	strcpy(TempIn.sCondition,sCondition);
/*��ʼ�������ݽṹ*/	
	bzero((void*)&MsisdnUp,sizeof(struct MsisdnImsiStatStructOut));
	strcpy(MsisdnUp.sTableName,sOutTableName);
/*��ʼ�������ݽṹ*/
	bzero((void*)&MsisdnOut,sizeof(struct MsisdnImsiStatStructOut));
	strcpy(MsisdnOut.sTableName,sOutTableName);
	
/*   ��MSISDN_IMSI_STAT����ȡ�����ݵ����ṹpRootStat��   */

	if(GetMsisdnImsi2Root(&pRootStat,sOutTableName,sTempCondition)!=0)return -1;
	
/*  ��PREP_TICKET������Ӧ����ȡ����BITREE�� */

	while(EGetPrepTicketToStruct(&Temp,&TempIn)){
		iCnt++;
		
		if(strcmp(Temp.sCallType,"01")!=0)continue;
		if(Temp.sMsisdn[0]!='1')continue;
			
		if((p=(struct MsisdnImsiStatHHStruct*)malloc(
			sizeof(struct MsisdnImsiStatHHStruct )))==NULL){
			WriteAlertMsg("����MsisdnImsiStatHHStructʧ��");
			exit(1);
		}		
		mvitem_prep2msisdnimsiHH(&Temp,p);
		
		if(InsertBin(&pRoot,(void *)p,
			data_search_bintree_msisdn_imsihh_e,
			insert_bintree_msisdn_imsihh_e)<0){
			WriteAlertMsg("����BINTREEʧ��prep_ticket");
			return -1;
		}

		
		if((iCnt%30000)==0)
			WriteProcMsg("���ر� %s ��¼��%d",sInTableName,iCnt);
			
	}

	TravelBin(pRoot,msisdn_List2Db);

/*�ύδ���µ�����*/
	if(UpdateDateToMsisdnImsiStat(NULL,true,&MsisdnUp)!=0){
		WriteAlertMsg("���±�%s����.",MsisdnUp.sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}

	/*�ύδ���������*/
	if(EInsertStructToMsisdnImsiStat(NULL,true,&MsisdnOut)<0){
		WriteAlertMsg("д��%s����.",MsisdnOut.sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}	
/*  �ͷ���Դ  */
	CommitWork();
	WriteProcPrint("������¼ %d,�����¼��Ϊ %d,���¼�¼��Ϊ %d",
		iCnt,iCuInsert,iCuUpdate);
	DestroyBin(pRoot);
	DestroyBin(pRootStat);
	DisconnectDatabase();
	
	return 0;
}
