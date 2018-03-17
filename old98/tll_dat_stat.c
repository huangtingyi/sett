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
#include <stt_ticket.h>

#include "param_intf.h"
#include "dbsupp.h"
#include "tll_dat_stat_supp.h"

int K=0;
char SCAPITALAREACODE[9];

BINTREE *pRootSttWj=NULL;
BINTREE *pRootSttWn=NULL;
BINTREE *pRootBilWn=NULL;

struct MobCalledStatStruct *pStatOut=NULL;
struct MobCalledStatStruct *pStatErr=NULL;


void DestroyBinX();
void GenAreaCode(char sAreaCodeIn[],char sAreaCodeOut[]);
void GetMobCalledStat(struct SttSjStruct *pi,struct MobCalledStatStruct *po);
int SttSj2MobCalledStat(BINTREE **ppRoot,char sTableName[]);
int data_search_bintree_mobcalled_e(void *pValue,void*pData);
void assign_insert_bintree_mobcalled_e(void **ppData,void *pData);
void mvitem_mobcalledstat(struct MobCalledStatStruct *pi,struct MobCalledStatStruct *po);
void diff_wn_stat(struct MobCalledStatStruct *pHead,
	 struct MobCalledStatStruct *pTemp);

void DestroyMobCalledStat(struct MobCalledStatStruct *ptHead);

void DestroyBinX()
{
	DestroyBin(pRootSttWj);
	DestroyBin(pRootSttWn);
	DestroyBin(pRootBilWn);
	
}

void ChkAreaCode(char sIn[])
{
	int l=0;
	char sTemp[10];
	
	l=strlen(sIn)-1;
	
	if(strncmp(sIn+l,"A",1)==0||
		strncmp(sIn+l,"B",1)==0||
		strncmp(sIn+l,"C",1)==0||
		strncmp(sIn+l,"w",1)==0||
		strncmp(sIn+l,"c",1)==0||
		strncmp(sIn+l,"y",1)==0||
		strncmp(sIn+l,"q",1)==0){

		strncpy(sTemp,sIn,l);sTemp[l]=0;
		strcpy(sIn,sTemp);
	}

}

void GenAreaCode(char sAreaCodeIn[],char sAreaCodeOut[])
{

	
	
	if(strcmp(sAreaCodeIn,"99900")==0||
		strcmp(sAreaCodeIn,"9999")==0){
	aa:;
		if(K<0||K>30)K=0;
		sprintf(sAreaCodeOut,"%d",aiCapitalAreaCode[K]);
		K++;
		
		if(strcmp(sAreaCodeOut,SCAPITALAREACODE)==0)goto aa;
		
	}		
	else	strncpy(sAreaCodeOut,sAreaCodeIn,5);
	
	ChkAreaCode(sAreaCodeOut);
	
}

int GenCityCode(char sAreaCode[],char sCityCode[])
{
	struct AreaCodeDescStruct *pTemp=NULL;

	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==NOTFOUND){
		printf("����%sû���ҵ����д���\n",sAreaCode);
		return -1;
	}
	strcpy(sCityCode,pTemp->sCityCode);
	if ( strcmp(sCityCode,"-1") == 0 ){
               strcpy(sCityCode,"841");
	}

	return 0;
}

void GetMobCalledStat(struct SttSjStruct *pi,struct MobCalledStatStruct *po)
{/*�����ƶ�����*/
	int iTollSec=0;
	
	bzero((void*)po,sizeof(struct MobCalledStatStruct));

/*��Ҫ���쳣�������ر���*/
		
		GenAreaCode(pi->sCallingAreaCode,po->sCallingAreaCode);
		GenAreaCode(pi->sVisitAreaCode,po->sCalledAreaCode);
		
		
		strncpy(po->sCallingType,	pi->sCallingUserType,1);
		strncpy(po->sCalledType,	pi->sCalledUserType,1);
		
		sprintf(po->sTollFee,		"%d",pi->iTollFee);
		
		iTollSec=(pi->iDuration+5)/6;
		sprintf(po->sTollSec,		"%d",iTollSec);


		po->iCnt=			1;

		strncpy(po->sSettMonth,		pi->sStartTime,6);
}
void mvitem_mobcalledstat(struct MobCalledStatStruct *pi,struct MobCalledStatStruct *po)
{/*�����ƶ�����*/
		char sCityCode[9];
		bzero((void*)po,sizeof(struct MobCalledStatStruct));

		GenCityCode(pi->sCallingAreaCode, sCityCode);
		strncpy(po->sCallingAreaCode, sCityCode,3);
		po->sCallingAreaCode[3]=0;
		GenCityCode(po->sCalledAreaCode, sCityCode);
		strncpy(po->sCalledAreaCode, sCityCode,3);
		po->sCalledAreaCode[3]=0;
		
		strncpy(po->sCallingType,	pi->sCallingType,1);
		strncpy(po->sCalledType,	pi->sCalledType,1);
		strncpy(po->sTollFee,		pi->sTollFee,12);
		strncpy(po->sTollSec,		pi->sTollSec,12);

		po->iCnt=			pi->iCnt;

		strncpy(po->sSettMonth,		pi->sSettMonth,6);
}
int data_search_bintree_mobcalled_e(void *pValue,void*pData)
{
	struct MobCalledStatStruct *pSource=(struct MobCalledStatStruct *)pValue;
	struct MobCalledStatStruct *pTarget=(struct MobCalledStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sCallingAreaCode,pTarget->sCallingAreaCode))!=0) return res;
	if((res=strcmp(pSource->sCalledAreaCode,pTarget->sCalledAreaCode))!=0) return res;
	if((res=strcmp(pSource->sCallingType,pTarget->sCallingType))!=0) return res;
	if((res=strcmp(pSource->sCalledType,pTarget->sCalledType))!=0) return res;
	if((res=strcmp(pSource->sSettMonth,pTarget->sSettMonth))!=0) return res;

	return 0;
}

void assign_insert_bintree_mobcalled_e(void **ppData,void *pData)
{
	int iTollFee=0,iTollSec=0;

	struct MobCalledStatStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct MobCalledStatStruct));
		ERROR_EXIT(pTemp==NULL,"����MobCalledStatStruct�ṹ����");
		memcpy((void*)pTemp,pData,sizeof(struct MobCalledStatStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	
	iTollFee=atoi(pTemp->sTollFee)+
		atoi(((struct MobCalledStatStruct*)pData)->sTollFee);
	iTollSec=atoi(pTemp->sTollSec)+
		atoi(((struct MobCalledStatStruct*)pData)->sTollSec);
	pTemp->iCnt=pTemp->iCnt+((struct MobCalledStatStruct*)pData)->iCnt;

	sprintf(pTemp->sTollFee,		"%d",iTollFee);
	sprintf(pTemp->sTollSec,		"%d",iTollSec);


}

int SttSj2MobCalledStat(BINTREE **ppRoot,char sTableName[])
{
	int iDCnt=0,iFirstFlag=0;

        static struct SttSjStruct Temp;
        static struct SttSjStructIn TempIn;
        
	struct MobCalledStatStruct TempB;
	
	TempIn.iBufEmpty=TRUE;
       	TempIn.iFirstFlag=TRUE;

       	strcpy(TempIn.sTableName,sTableName);
       	strcpy(TempIn.sCondition,"");


        /*ȡ�����м�¼���ض�����*/
        while(EGetSttSjToStruct(&Temp,&TempIn)){
        	
        	if(iFirstFlag==0){
        		iFirstFlag=1;
        		GetCapitalCode(Temp.sVisitAreaCode,SCAPITALAREACODE);
        	}
		
		GetMobCalledStat(&Temp,&TempB);

       	
                if(InsertBin(ppRoot,&TempB,
			data_search_bintree_mobcalled_e,
			assign_insert_bintree_mobcalled_e)<0){
			WriteAlertMsg("����BINTREEʧ��");
			return -1;
		}
		if((++iDCnt%30000)==0)
			WriteProcMsg("��%s��ǰ������Ϊ%d",sTableName,iDCnt);

        }
        WriteProcMsg("�ɹ����ر�%s ��¼��%d��",TempIn.sTableName,iDCnt);
	return 0;
}

int link_wn_diff(void **ppHead)
{

	struct MobCalledStatStruct *ptHead=(*ppHead),*pTemp,Temp;
	static struct MobCalledStatStruct *pHead=NULL;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_mobcalledstat(pTemp,&Temp);
		
		if(SearchBin(pRootSttWn,&Temp,data_search_bintree_mobcalled_e,
			(void **)&pHead)==FOUND){

			diff_wn_stat(pTemp,pHead);
		}
	}

	return 0;
}


void diff_wn_stat(struct MobCalledStatStruct *pHead,
	 struct MobCalledStatStruct *pTemp)
{
	int iTollFee=0,iTollSec=0;
	
	iTollFee=atoi(pHead->sTollFee)-atoi(pTemp->sTollFee);
	iTollSec=atoi(pHead->sTollSec)-atoi(pTemp->sTollSec);
	pHead->iCnt=pHead->iCnt-pTemp->iCnt;

	sprintf(pHead->sTollFee,		"%d",iTollFee);
	sprintf(pHead->sTollSec,		"%d",iTollSec);

}

/**�Ա�MobCalledStatStruct�������ͷź���**/
void DestroyMobCalledStat(struct MobCalledStatStruct *ptHead)
{
	struct MobCalledStatStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}


int link_mobcalledstat_split(void **ppData)
{
	int iTollFee=0,iTollSec=0;
	
	struct MobCalledStatStruct *pTemp=(struct MobCalledStatStruct *)(*ppData);

	iTollFee=atoi(pTemp->sTollFee);
	iTollSec=atoi(pTemp->sTollSec);
	
	if(iTollFee==0&&iTollSec==0&&pTemp->iCnt==0)return 0;
	
	if(iTollFee<0||iTollSec<=0||pTemp->iCnt<=0)
		InsertList((LIST**)&pStatErr,(LIST*)pTemp);
	else	InsertList((LIST**)&pStatOut,(LIST*)pTemp);

	return 0;
}

int MobCalledStatList2Table(struct MobCalledStatStruct *ptOut,
	struct MobCalledStatStruct *ptErr,char sTableName[])
{
	struct MobCalledStatStructOut TempOut;
	struct MobCalledStatStructOut TempErr;
	struct	MobCalledStatStruct *ptCur,*ptPre;
	int	iCnt=0,iErrCnt=0;
	char sDateTime[15];
	
/**������ݵ�ͳ�Ʊ�**/
        bzero((void*)&TempOut,sizeof(struct MobCalledStatStructOut));
        bzero((void*)&TempErr,sizeof(struct MobCalledStatStructOut));

        strcpy(TempOut.sTableName,sTableName);
	sprintf(TempErr.sTableName,"%s_ERR",sTableName);
	
	GetHostTime(sDateTime);

  	ptCur=ptOut;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		strcpy(ptPre->sDealDate,sDateTime);
		
		if(EInsertStructToMobCalledStat(ptPre,false,&TempOut)<0){
			WriteAlertMsg("������ݴ��� DATA_CALLED_STAT");
			WriteErrStackAlert();
			return -1;
		}
		if((++iCnt)%1000==0)
			WriteProcMsg("�Ա�%s�����¼��%d��",TempOut.sTableName,iCnt);

	}
	if(EInsertStructToMobCalledStat(NULL,true,&TempOut)<0){
		WriteAlertMsg("������ݴ��� DATA_CALLED_STAT");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("�Ա�%s������,���Ƽ�¼��%d��",TempOut.sTableName,iCnt);

/**�������ݵ����ʱ�**/
	ptCur=ptErr;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		strcpy(ptPre->sDealDate,sDateTime);
		
		if(EInsertStructToMobCalledStat(ptPre,false,&TempErr)<0){
			WriteAlertMsg("������ݴ��� DATA_CALLED_STAT_err");
			WriteErrStackAlert();
			return -1;
		}
		if((++iErrCnt)%1000==0)
			WriteProcMsg("�Ա�%s�����¼��%d��",TempErr.sTableName,iErrCnt);
	}
	if(EInsertStructToMobCalledStat(NULL,true,&TempErr)<0){
		WriteAlertMsg("������ݴ��� DATA_CALLED_STAT_err");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("�Ա�%s������,���Ƽ�¼��%d��",TempErr.sTableName,iErrCnt);

	return 0;

}

int DealStatData(BINTREE *pRoot)
{
	int iCnt=0;


/*����ֵ�ӵ�pStatOut��������ֵ�ӵ�pStatErr����*/
	DestroyMobCalledStat(pStatOut);
	DestroyMobCalledStat(pStatErr);
	pStatOut=NULL;
	pStatErr=NULL;

	TravelBin(pRoot,link_mobcalledstat_split);

/**������ݵ�ͳ�Ʊ�**/
	
	if(MobCalledStatList2Table(pStatOut,pStatErr,"DATA_CALLED_STAT")<0){
		return -1;
	}
	
}

int main(int argc, char **argv)
{
	int  iTotalCnt=0,iCnt=0;
	char sSttWjTableName[31],sSttWnTableName[31],sBilWnTableName[31];
	char sBillingCycleID[7],sMonth[3],*pPre,*pCur;


	if(argc!=2){
		printf("Usage %s bilingcycleid.\n",argv[0]);
		return -1;
	}

	InitAppRes(argv[0]);
	strcpy(sBillingCycleID,argv[1]);sBillingCycleID[6]=0;
	strncpy(sMonth,sBillingCycleID+4,2);  sMonth[2]=0;
	
	if(atoi(sMonth)<1&&atoi(sMonth)>12){
		printf("��������Ϊ%s ����ȷ.\n",sBillingCycleID);
		WriteProcMsg("��������Ϊ%s ����ȷ.",sBillingCycleID);
		return -1;
	}

	IniConnect("dataconnstr");

/*1.ʡ��������������*/
	sprintf(sSttWjTableName,"STT_SJ_WJ_%s",sMonth);
	
	if(SttSj2MobCalledStat(&pRootSttWj,sSttWjTableName)<0){
		WriteAlertMsg("�� %s ����BINTREEʧ��",sSttWjTableName);
		return -1;		
	}

/*2ʡ�������������������� */
	sprintf(sSttWnTableName,"STT_SJ_WN_%s",sMonth);
	
	if(SttSj2MobCalledStat(&pRootSttWn,sSttWnTableName)<0){
		WriteAlertMsg("�� %s ����BINTREEʧ��",sSttWnTableName);
		return -1;		
	}

/*3 ʡ������������ڱ� */
	sprintf(sBilWnTableName,"BIL_SJ_WN_%s",sMonth);

	if(SttSj2MobCalledStat(&pRootBilWn,sBilWnTableName)<0){
		WriteAlertMsg("�� %s ����BINTREEʧ��",sBilWnTableName);
		return -1;		
	}

/*ʡ�������������ͳ�ƺ�Ҫ�޳�ʡ������������������*/

	TravelBin(pRootBilWn,link_wn_diff);

/*pRootSttWjͳ�����������ͳ�Ʊ�*/
	if(DealStatData(pRootSttWj)<0){
		RollbackWork();
		return -1;
	}

/*pRootBilWnͳ�����������ͳ�Ʊ�*/
	if(DealStatData(pRootBilWn)<0){
		RollbackWork();
		return -1;
	}


	WriteProcMsg("�Ա�%s,%s,%s ͳ������%s��ͳ�ƽ���",
		sSttWjTableName,sSttWjTableName,sSttWjTableName,sBillingCycleID);
	printf("�Ա�%s,%s,%s ͳ������%s��ͳ�ƽ���.\n",
		sSttWjTableName,sSttWjTableName,sSttWjTableName,sBillingCycleID);
	
	CommitWork();
	DestroyBinX();
	DisconnectDatabase();

	return 0;
}

