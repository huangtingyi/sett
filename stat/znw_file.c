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
#include "stt_ticket.h"

BINTREE *pRoot=NULL;
BINTREE *pOutRoot=NULL;

struct NbrStatStruct *ptNbrStat=NULL;
struct ServCardStruct *pServCard=NULL;
struct FileControlStruct *pRec=NULL;
int	iFileCnt=1;
char    sBillingCycleID[7],sNormalDir[256];

int Ins2NbrStatStruct(struct NbrStatStruct *pValue)
{
	static struct NbrStatStruct *pTemp;
	
/*���뵽����*/
	
	if((pTemp=(struct NbrStatStruct *)malloc(
	 sizeof(struct NbrStatStruct)))==NULL){
		 printf("�����ڴ�ʧ��.\n");
		 return -1;
	
	}
	
	memcpy((void*)pTemp,pValue,sizeof(struct NbrStatStruct));

	InsertList((LIST**)&ptNbrStat,(LIST*)pTemp);
	
	return 0; 
}
int ChkServiceType(char sServiceType[])
{
        /*��ic����201,200,���ܹ���ҵ���continue*/
        if(strcmp(sServiceType,"200")!=0&&
        	strcmp(sServiceType,"201")!=0&&
        	strcmp(sServiceType,"202")!=0&&
        	strcmp(sServiceType,"205")!=0) return -1;
	return 0; 
	
}
int MsisdnStat2Bintree(BINTREE **ppRoot,char sTableName[],char sFirstCycleID[])
{
	static int iFirstFlag=true;
        static struct MsisdnStatStruct Temp;
        static struct MsisdnStatStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
		sprintf(TempIn.sCondition,
			" WHERE BILLING_CYCLE_ID='%s' ",sFirstCycleID);
		iFirstFlag=false;
	}

        /*ȡ�����м�¼���ض�����*/
        while(EGetMsisdnStatToStruct(&Temp,&TempIn)){
        	
        	if(ChkServiceType(Temp.sServiceType)!=0)continue;
	
	/*����MsisdnStatToStruct*/
                if(InsertBin(ppRoot,&Temp,
			data_search_bintree_msisdn_stat_e,
			assign_insert_bintree_msisdn_stat_e)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
	}
	return 0;
	
	
}
int ServCard2Bintree(BINTREE **ppRoot,char sTableName[])
{
	static int iFirstFlag=true;
        static struct ServCardStruct Temp;
        static struct ServCardStructIn TempIn;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
        	strcpy(TempIn.sCondition,"");
		iFirstFlag=false;
	}

        /*ȡ�����м�¼���ض�����*/
        while(EGetServCardToStruct(&Temp,&TempIn)){
		/*����ServCardToStruct*/
                if(InsertBin(ppRoot,&Temp,
			data_search_bintree_serv_card_e,
			assign_insert_bintree_serv_card_e)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
        }
	return 0;
}

int data_search_bintree_msisdn_stat_e(void *pValue,void*pData)
{
	struct MsisdnStatStruct *pSource=(struct MsisdnStatStruct *)pValue;
	struct MsisdnStatStruct *pTarget=(struct MsisdnStatStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	
	if((res=pSource->iAreaID-pTarget->iAreaID)!=0) return res;

	if((res=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return res;
	if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
	if((res=strcmp(pSource->sServiceType,pTarget->sServiceType))!=0) return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}
void assign_insert_bintree_msisdn_stat_e(void **ppData,void *pData)
{

	struct MsisdnStatStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct MsisdnStatStruct));
		ERROR_EXIT(pTemp==NULL,"����MsisdnStat�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct MsisdnStatStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	pTemp->iTotalDuration+=((struct MsisdnStatStruct*)pData)->iTotalDuration;
	pTemp->iTotalMin+=((struct MsisdnStatStruct*)pData)->iTotalMin;
	pTemp->iTotalCnt+=((struct MsisdnStatStruct*)pData)->iTotalCnt;
	pTemp->iTotalFee1+=((struct MsisdnStatStruct*)pData)->iTotalFee1;
	pTemp->iTotalFee2+=((struct MsisdnStatStruct*)pData)->iTotalFee2;
	pTemp->iTotalFee3+=((struct MsisdnStatStruct*)pData)->iTotalFee3;
}

int data_search_bintree_out_accnbr_e(void *pValue,void*pData)
{
	struct OutAccNbrStruct *pSource=(struct OutAccNbrStruct *)pValue;
	struct OutAccNbrStruct *pTarget=(struct OutAccNbrStruct *)pData;
	int res;

	if((res=strcmp(pSource->sCustNane,pTarget->sCustNane))!=0) return res;
	if((res=strcmp(pSource->sAreaCodeName,pTarget->sAreaCodeName))!=0) return res;
	if((res=strcmp(pSource->sAreaName,pTarget->sAreaName))!=0) return res;
	
	if((res=strcmp(pSource->sAccNbr,pTarget->sAccNbr))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	
	if((res=pSource->iTypeID-pTarget->iTypeID)!=0) return res;

	return 0;
}

void assign_insert_bintree_out_accnbr_e(void **ppData,void *pData)
{

	struct OutAccNbrStruct *pTemp;
	
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct OutAccNbrStruct));
		ERROR_EXIT(pTemp==NULL,"����ServCard�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct OutAccNbrStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	
	pTemp->iUserCnt+=((struct OutAccNbrStruct*)pData)->iUserCnt;
	pTemp->iUserFeeCnt+=((struct OutAccNbrStruct*)pData)->iUserFeeCnt;
	pTemp->iUserLcCnt+=((struct OutAccNbrStruct*)pData)->iUserLcCnt;
	pTemp->iToTalFee+=((struct OutAccNbrStruct*)pData)->iToTalFee;
	pTemp->iUserFee+=((struct OutAccNbrStruct*)pData)->iUserFee;
	
}

int data_search_bintree_serv_card_e(void *pValue,void*pData)
{
	struct ServCardStruct *pSource=(struct ServCardStruct *)pValue;
	struct ServCardStruct *pTarget=(struct ServCardStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sAccNbr,pTarget->sAccNbr))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	
	if((res=pSource->iTypeID-pTarget->iTypeID)!=0) return res;

	return 0;
}

void assign_insert_bintree_serv_card_e(void **ppData,void *pData)
{

	struct ServCardStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct ServCardStruct));
		ERROR_EXIT(pTemp==NULL,"����ServCard�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct ServCardStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
}
int rdata_search_bintree_msisdn_stat_e(void *pValue,void*pData)
{
	struct MsisdnStatStruct *pSource=(struct MsisdnStatStruct *)pValue;
	struct MsisdnStatStruct *pTarget=(struct MsisdnStatStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	
	return 0;

}
void mvitem_msisdnstat2serv(struct MsisdnStatStruct *pi,
	struct ServCardStruct *po)
{
	bzero((void*)po,sizeof(struct ServCardStruct));
	
	strcpy(po->sAccNbr,pi->sMsisdn);
	strcpy(po->sAreaCode,pi->sAreaCode);
	po->iTypeID=atoi(pi->sServiceType);
}
void mvitem_serv2msisdnstat(struct ServCardStruct *pi,
	struct MsisdnStatStruct *po)
{
	bzero((void*)po,sizeof(struct MsisdnStatStruct));
	
	strcpy(po->sMsisdn,pi->sAccNbr);
	strcpy(po->sAreaCode,pi->sAreaCode);
	sprintf(po->sServiceType,"%d",pi->iTypeID);
}                                  
void mvitem_serv2OutAccNbr(struct ServCardStruct *pi,
	struct OutAccNbrStruct *po)
{
	bzero((void*)po,sizeof(struct OutAccNbrStruct));
	
	strcpy(po->sCustNane,pi->sCustNane);
	strcpy(po->sAreaCodeName,pi->sAreaCodeName);
	strcpy(po->sAreaName,pi->sAreaName);
	strcpy(po->sAreaCode,pi->sAreaCode);
	
	po->iTypeID=pi->iTypeID;
		
}
int link_serv_card(void **ppData)
{
	InsertList((LIST**)&pServCard,(LIST*)(*ppData));
	return 0;
}
int search_msisdn_stat(void **ppHead)
{
	
	struct MsisdnStatStruct *ptHead=(*ppHead),*pTemp;
	static struct NbrStatStruct TNbrS;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if((SearchBin(pRoot,pTemp,
			rdata_search_bintree_msisdn_stat_e,
			(void**)&pTemp))==NOTFOUND){
			/*δ�ҵ�Ϊ������������λ�*/
			bzero((void*)&TNbrS,sizeof(struct NbrStatStruct));
			
			strcpy(TNbrS.sRecordType,"07");TNbrS.sRecordType[2]=0;
			strcpy(TNbrS.sServiceType       ,pTemp->sServiceType);   
			strcpy(TNbrS.sAccNbr            ,pTemp->sMsisdn); 
			strcpy(TNbrS.sAreaCode          ,pTemp->sAreaCode);
			TNbrS.iToTalFee		=pTemp->iTotalFee1;
			strcpy(TNbrS.sBillingCycleID    ,sBillingCycleID); 
			strcpy(TNbrS.sOutFileName       ,"NBR_STAT_"); 
			
			Ins2NbrStatStruct(&TNbrS);
		}
	}
	return 0;
}

int search_serv_card(struct ServCardStruct *pValue)
{
	int iUserLcCnt,iUserFeeCnt,iUserCnt,iToTalFee;
	
	struct ServCardStruct *ptCur=NULL,*ptPre=NULL;	
	static struct MsisdnStatStruct Temp,*pTemp;
	static struct OutAccNbrStruct s,Tj;
	static struct NbrStatStruct TNbrS;
	
	ptCur=pValue;
	
	while(ptCur!=NULL){

		ptPre=ptCur;
		ptCur=ptCur->pNext;

		iUserLcCnt=0;
		iUserFeeCnt=1;
		iUserCnt=1;
		
		mvitem_serv2msisdnstat(ptPre,&Temp);
		
		bzero((void*)&Tj,sizeof(struct OutAccNbrStruct));
		bzero((void*)&s,sizeof(struct OutAccNbrStruct));
		
		if((SearchBin(pRoot,(void*)&Temp,
			rdata_search_bintree_msisdn_stat_e,
			(void**)&pTemp))==NOTFOUND){/*δ�ҵ���¼Ϊ��κ���*/
		/*������κ���*/
			strcpy(s.sAreaCode,Temp.sAreaCode);
			strcpy(s.sAccNbr,Temp.sMsisdn);
			strcpy(s.sOutFileName,"LC_");
			s.sOutFileName[3]=0;
			s.iTypeID=atoi(Temp.sServiceType);
		
	                if(InsertBin(&pOutRoot,&s,
				data_search_bintree_out_accnbr_e,
				assign_insert_bintree_out_accnbr_e)<0){
				WriteAlertMsg("����BINTREEʧ��");
				return -1;
			}
		/*���������ͳ����Ϣ*/
			bzero((void*)&TNbrS,sizeof(struct NbrStatStruct));
			strcpy(TNbrS.sRecordType,"01");TNbrS.sRecordType[2]=0;
			strcpy(TNbrS.sAccNbr            ,Temp.sMsisdn);
			strcpy(TNbrS.sServiceType       ,Temp.sServiceType);
			strcpy(TNbrS.sAreaCode          ,Temp.sAreaCode);
			TNbrS.iToTalFee		=0;
			strcpy(TNbrS.sBillingCycleID    ,sBillingCycleID);
			strcpy(TNbrS.sOutFileName       ,"NBR_STAT_");

			Ins2NbrStatStruct(&TNbrS);

			iUserLcCnt=1;
			iUserFeeCnt=0;
			iToTalFee=0;
			
		}
		else{
		/*���������ͳ����Ϣ*/
			bzero((void*)&TNbrS,sizeof(struct NbrStatStruct));
			
			iToTalFee	=pTemp->iTotalFee1;
		
			strcpy(TNbrS.sRecordType,"03");TNbrS.sRecordType[2]=0;
			strcpy(TNbrS.sAccNbr            ,Temp.sMsisdn);
			strcpy(TNbrS.sServiceType       ,Temp.sServiceType);
			strcpy(TNbrS.sAreaCode          ,Temp.sAreaCode);
			TNbrS.iToTalFee		=iToTalFee;
			strcpy(TNbrS.sBillingCycleID    ,sBillingCycleID);
			strcpy(TNbrS.sOutFileName       ,"NBR_STAT_");
			
			Ins2NbrStatStruct(&TNbrS);
		}
	/*���������ͳ����Ϣ*/
		bzero((void*)&TNbrS,sizeof(struct NbrStatStruct));
		strcpy(TNbrS.sRecordType,"04");TNbrS.sRecordType[2]=0;
		strcpy(TNbrS.sAccNbr            ,Temp.sMsisdn);
		strcpy(TNbrS.sServiceType       ,Temp.sServiceType);
		strcpy(TNbrS.sAreaCode          ,Temp.sAreaCode);
		TNbrS.iToTalFee		=iToTalFee;
		strcpy(TNbrS.sBillingCycleID    ,sBillingCycleID);
		strcpy(TNbrS.sOutFileName       ,"NBR_STAT_");
	
		Ins2NbrStatStruct(&TNbrS);
			
		if(ptPre->iTypeID!=201)continue;
			
	/*���뵽У԰��ͳ��*/
		mvitem_serv2OutAccNbr(ptPre,&Tj);
		Tj.iUserCnt=iUserCnt;
		Tj.iUserFeeCnt	=iUserFeeCnt;
		Tj.iUserLcCnt	=iUserLcCnt;
		Tj.iToTalFee	=iToTalFee;
		Tj.iUserFee	=0;
		strcpy(Tj.sOutFileName,"CUSTOM_ACC_");
		Tj.sOutFileName[11]=0;
		
		strcpy(Tj.sAccNbr,"");
		
		if(InsertBin(&pOutRoot,&Tj,
			data_search_bintree_out_accnbr_e,
			assign_insert_bintree_out_accnbr_e)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
	}
	return 0;	
}
struct MyFileOutStruct
{
	struct MyFileOutStruct *pNext;
	char 	sFileNameStr[256];
	FILE *fp;
};
struct MyFileOutStruct *GetFileOut(struct FileControlStruct **pptHead,
	char sFileNameStr[],int l)
{
	struct FileControlStruct *ptHead=*pptHead;
	struct MyFileOutStruct *pTemp,Temp;
	char sFileName[256];
	
	sFileNameStr[l]=0;
	
	while(ptHead!=NULL){
		pTemp=(struct MyFileOutStruct *)ptHead->pData;
		if(strcmp(sFileNameStr,pTemp->sFileNameStr)==0) return pTemp;
		ptHead=ptHead->pNext;
	}
	bzero((void*)&Temp,sizeof(struct MyFileOutStruct));
	
	Temp.pNext=NULL;
	strcpy(Temp.sFileNameStr,sFileNameStr);
	sprintf(sFileName,"%s.txt",sFileNameStr);
	
	if((Temp.fp=fopen(sFileName,"w"))==NULL) return NULL;
	
	if(item2list(pptHead,(void*)&Temp,sizeof(struct MyFileOutStruct))<0)
		return NULL;
	return (struct MyFileOutStruct *)((*pptHead)->pData);
}
void CloseFileOut(struct FileControlStruct *ptHead)
{
	struct MyFileOutStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=(struct MyFileOutStruct *)ptHead->pData;
		fclose(pTemp->fp);

		ptHead=ptHead->pNext;
	}

}

/*�����ļ�֧��*/
int item2fileout(struct FileControlStruct **ppHead,void *pData,int iLen,
	char sTargetName[],char sFileNameStr[])
{
	int l=0;
	char sFileLine[8192],sStr[256];
	struct MyFileOutStruct *pTemp;
	

	strcpy(sStr,sTargetName);
	strcat(sStr,sFileNameStr);
	l=strlen(sStr);
	
	if((pTemp=GetFileOut(ppHead,sStr,l))==NULL) return -1;

	memcpy((void*)sFileLine,pData,iLen);sFileLine[iLen]=0;
	
	if(fprintf(pTemp->fp,"%s",sFileLine)<0) return -1;
	
	return 0;
}

int OutZnwFile(void **ppData)
{
	struct OutAccNbrStruct *ptHead=(*ppData);
	char sRecord[512],sFileNameStr[30],sTargetName[60];
	int l=0,d,y;
	double iToTalFee,iUserFee;
	
	if(ptHead!=NULL){
		l=0;
		iToTalFee=0.0;
		iUserFee=0.0;
		AllTrim(ptHead->sAccNbr);
		strcpy(sFileNameStr,"");
		strcpy(sTargetName,"");
		strcat(sTargetName,sNormalDir);
		strcat(sTargetName,ptHead->sOutFileName);
		
		if(strcmp(ptHead->sOutFileName,"LC_")==0||
			strcmp(ptHead->sOutFileName,"LB_")==0){
			l+=sprintf(sRecord+l,"%s\n",ptHead->sAccNbr);
			
			if(ptHead->iTypeID==201)
				strcpy(sFileNameStr,"206_");
			else if(ptHead->iTypeID==202)
				strcpy(sFileNameStr,"7890_");
			
		}
		else if(strcmp(ptHead->sOutFileName,"CUSTOM_ACC_")==0){
			l+=sprintf(sRecord+l,"%8d%30s%20s",
			iFileCnt,ptHead->sCustNane,ptHead->sAreaCodeName);
			
			l+=sprintf(sRecord+l,"%20s%8d%8d",
			ptHead->sAreaName,ptHead->iUserCnt,ptHead->iUserFeeCnt);

			d=ptHead->iToTalFee;
			y=ptHead->iUserFeeCnt;
			
			if(d!=0)iToTalFee=(d+0.5)/100.0;
			if(d!=0&&y!=0)iUserFee=(d/y+0.5)/100.0;
			
			l+=sprintf(sRecord+l,"%8d%8.2f%8.2f\n",
			ptHead->iUserLcCnt,iToTalFee,iUserFee);
			
			iFileCnt++;
		}
		else{
			printf("�����ļ�����%s.\n",ptHead->sOutFileName);
			WriteProcMsg("�����ļ�����%s",ptHead->sOutFileName);
			return -1;
		}
			
		
		
		strcat(sFileNameStr,sBillingCycleID);
		strcat(sFileNameStr,"_");
		strcat(sFileNameStr,ptHead->sAreaCode);
		
		if(item2fileout(&pRec,sRecord,l,sTargetName,sFileNameStr)<0){
			WriteAlertPrint("���ɻ����������");
			return -1;
		}

	}
	return 0;
}
int OutNbrStatFile(struct NbrStatStruct *ptData)
{
	struct NbrStatStruct *ptHead=NULL,*pTemp=NULL;
	char sRecord[512],sFileNameStr[30],sTargetName[60];
	int l;
	
	ptHead=ptData;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		l=0;
		strcpy(sFileNameStr,"");
		strcpy(sTargetName,"");
		strcat(sTargetName,sNormalDir);
		strcat(sTargetName,pTemp->sOutFileName);
		
		l+=sprintf(sRecord+l,"%2s%15s%10s",
		pTemp->sRecordType,pTemp->sAccNbr,pTemp->sServiceType);
		
		l+=sprintf(sRecord+l,"%5s%9d%6s\n",
		pTemp->sAreaCode,pTemp->iToTalFee,pTemp->sBillingCycleID);
		
		
		strcat(sFileNameStr,sBillingCycleID);
		
		if(item2fileout(&pRec,sRecord,l,sTargetName,sFileNameStr)<0){
			WriteAlertPrint("���ɻ����������");
			return -1;
		}

	}
	return 0;
}

int main(int argc, char **argv)
{
	int  iCnt=0;
	char sNbrTableName[31],sChkTableName[31];
	char sChkDate[15],sFirstCycleID[7];
	
	
	static int iFirstFlag=true;
        static struct MsisdnStatStruct Temp;
        static struct MsisdnStatStructIn TempIn,*pTm;
        
        static struct ServCardStruct *pTemp,s;
	struct OutAccNbrStruct	TempLb;
	struct NbrStatStruct	TNbrS;
	
	BINTREE *pServCardRoot=NULL;
	BINTREE *pMsisdnStatA=NULL;

	if(argc!=5){
		printf("Usage %s nbrtablename chktablename normaldir billingcycleid .\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sNbrTableName,argv[1]);
	Upper(sNbrTableName);
	strcpy(sChkTableName,argv[2]);
	Upper(sChkTableName);
	strcpy(sNormalDir,argv[3]);

	strcpy(sBillingCycleID,argv[4]);
	sBillingCycleID[6]=0;
	
	strcpy(sChkDate,sBillingCycleID);
	strcat(sChkDate,"01000000");
        if(AddTimes(sChkDate,-86400)<0) return -1;
        strncpy(sFirstCycleID,sChkDate,6);
        sFirstCycleID[6]=0;

	RegularDir(sNormalDir);

/**�������ݿ�***/
	if(ConnectDataDB()<0) return -1;
	
/*���ص����ϱ���������*/
	if(ServCard2Bintree(&pServCardRoot,sNbrTableName)<0){
		WriteAlertMsg("����BINTREEʧ��");
		return -1;
	}
/*�����ϸ����ڵ�ͳ������*/
	if(MsisdnStat2Bintree(&pMsisdnStatA,sChkTableName,sFirstCycleID)<0){
		WriteAlertMsg("����BINTREEʧ��");
		return -1;
	}

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sChkTableName);
		sprintf(TempIn.sCondition,
			" WHERE BILLING_CYCLE_ID='%s' ",sBillingCycleID);
		iFirstFlag=false;
	}

        /*ȡ�����м�¼���ض�����*/
        while(EGetMsisdnStatToStruct(&Temp,&TempIn)){
        	
        	/*��ic����201,200,���ܹ���ҵ���continue*/
        	if(ChkServiceType(Temp.sServiceType)!=0)continue;
        	
        	bzero((void*)&TempLb,sizeof(struct OutAccNbrStruct));        	
        	
        	mvitem_msisdnstat2serv(&Temp,&s);
        	
		if((SearchBin(pServCardRoot,(void*)&s,
			data_search_bintree_serv_card_e,
			(void**)&pTemp))==NOTFOUND){/*δ�ҵ���¼Ϊ©������*/

	        	if(strcmp(Temp.sServiceType,"201")==0||
	        		strcmp(Temp.sServiceType,"202")==0){
			/*ic����201��Ҫ���©������*/	
				strcpy(TempLb.sAreaCode,s.sAreaCode);
				strcpy(TempLb.sAccNbr,s.sAccNbr);
				strcpy(TempLb.sOutFileName,"LB_");
				TempLb.sOutFileName[3]=0;
				TempLb.iTypeID=s.iTypeID;
	
						
			/*����©������*/
		                if(InsertBin(&pOutRoot,&TempLb,
					data_search_bintree_out_accnbr_e,
					assign_insert_bintree_out_accnbr_e)<0){
					WriteAlertMsg("����BINTREEʧ��");
					return -1;
				}
			/*���������ͳ����Ϣ*/
				bzero((void*)&TNbrS,sizeof(struct NbrStatStruct));
				strcpy(TNbrS.sRecordType,"02");TNbrS.sRecordType[2]=0;
				strcpy(TNbrS.sServiceType       ,Temp.sServiceType);
				strcpy(TNbrS.sAccNbr            ,Temp.sMsisdn);
				strcpy(TNbrS.sAreaCode          ,Temp.sAreaCode);
				TNbrS.iToTalFee		=Temp.iTotalFee1;
				strcpy(TNbrS.sBillingCycleID    ,sBillingCycleID);
				strcpy(TNbrS.sOutFileName       ,"NBR_STAT_");
			
				Ins2NbrStatStruct(&TNbrS);

			}
		}
		
	/*����MsisdnStatToStruct*/
                if(InsertBin(&pRoot,&Temp,
			data_search_bintree_msisdn_stat_e,
			assign_insert_bintree_msisdn_stat_e)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
	/*�õ����������Ŀͻ�*/
		if((SearchBin(pMsisdnStatA,(void*)&Temp,
			rdata_search_bintree_msisdn_stat_e,
			(void**)&pTm))==NOTFOUND){/*δ�ҵ�Ϊ���������Ŀͻ�*/
			bzero((void*)&TNbrS,sizeof(struct NbrStatStruct));
			
			strcpy(TNbrS.sRecordType,"06");TNbrS.sRecordType[2]=0;
			strcpy(TNbrS.sServiceType       ,Temp.sServiceType);   
			strcpy(TNbrS.sAccNbr            ,Temp.sMsisdn); 
			strcpy(TNbrS.sAreaCode          ,Temp.sAreaCode);
			TNbrS.iToTalFee		=Temp.iTotalFee1;
			strcpy(TNbrS.sBillingCycleID    ,sBillingCycleID); 
			strcpy(TNbrS.sOutFileName       ,"NBR_STAT_"); 
			Ins2NbrStatStruct(&TNbrS);
		}
	
	/*���������ͳ����Ϣ*/
		bzero((void*)&TNbrS,sizeof(struct NbrStatStruct));
		strcpy(TNbrS.sRecordType,"05");TNbrS.sRecordType[2]=0;
		strcpy(TNbrS.sAccNbr            ,Temp.sMsisdn);
		strcpy(TNbrS.sServiceType       ,Temp.sServiceType);
		strcpy(TNbrS.sAreaCode          ,Temp.sAreaCode);
		TNbrS.iToTalFee		=Temp.iTotalFee1;
		strcpy(TNbrS.sBillingCycleID    ,sBillingCycleID);
		strcpy(TNbrS.sOutFileName       ,"NBR_STAT_");

		Ins2NbrStatStruct(&TNbrS);
	
		
 		if((++iCnt%10000)==0)
			WriteProcMsg("��%s��ǰͳ�Ƽ�¼��Ϊ%d",sChkTableName,iCnt);
	}
	WriteProcMsg("��%sͳ�����,��¼��Ϊ%d",sChkTableName,iCnt);

/*�ҵ�pServCard��*/
	TravelBin(pServCardRoot,link_serv_card);


/*���ݽ��з������*/
	search_serv_card(pServCard);
/*�õ�������������λ�*/
	TravelBin(pMsisdnStatA,search_msisdn_stat);
/*����ļ�*/
	TravelBin(pOutRoot,OutZnwFile);
/*����������õ��ļ�*/	
	OutNbrStatFile(ptNbrStat);
	
	CloseFileOut(pRec);


	CommitWork();
	DestroyBin(pRoot);
	DestroyBin(pServCardRoot);
	DestroyBin(pOutRoot);
	DisconnectDatabase();
	
	return 0;
}
