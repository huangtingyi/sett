#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include <wwcoding.h>
#include <wwtiny.h>
#include <wwnet.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>
#include "stt_ticket.h"

struct PickCheckLogStruct *ptOut=NULL;

int ProcessFile(char sBaseName[],char sFileName[],char sFileDate[],
	char sSourceID[],char sModule[]);
int data_search_bintree_pick_check_log_e(void *pValue,void*pData);
int PrepProcLog2Bin(BINTREE *pRoot,char sFileDate[],
	char sSourceID[],char sModule[]);
int link_pick_check_log_out(void **ppData);
int OutputList2Table(struct PickCheckLogStruct *ptOut,char sTableName[]);

int link_pick_check_log_out(void **ppData)
{
	struct PickCheckLogStruct *pTemp=(struct PickCheckLogStruct *)(*ppData);
	
	
	if(strcmp(pTemp->sFileType,"00000")==0){

	        if(PickLogCheck(pTemp->sSourceID,pTemp->sChkFileName,-1)==1){
			strcpy(pTemp->sFileType,"00001");
	        }
	}
	
	InsertList((LIST**)&ptOut,(LIST*)pTemp);

	return 0;
}
int OutputList2Table(struct PickCheckLogStruct *ptOut,char sTableName[])
{
	int iInsCnt=0;
	struct PickCheckLogStructOut TempOut;
	struct	PickCheckLogStruct *ptCur,*ptPre;

/**������ݵ����ʱ�**/
        bzero((void*)&TempOut,sizeof(struct PickCheckLogStructOut));

        strcpy(TempOut.sTableName,sTableName);

  	ptCur=ptOut;
	iInsCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToPickCheckLog(ptPre,false,&TempOut)<0){
			printf("�����Ŀ����pick_check_log.\n");
			WriteErrStackAlert();
			return -1;
		}
		iInsCnt++;

	}
	if(EInsertStructToPickCheckLog(NULL,true,&TempOut)<0){
		printf("�����Ŀ����pick_check_log.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("���±�%s��¼��%d.",sTableName,iInsCnt);
	
	return 0;

}

int PrepProcLog2Bin(BINTREE *pRoot,char sFileDate[],
	char sSourceID[],char sModule[])
{
	static int iFirstFlag=true;
        static struct PrepProcLogStruct Temp;
        static struct PrepProcLogStructIn TempIn;

	static struct PickCheckLogStruct *pHead=NULL;
	static struct PickCheckLogStruct s;
	
	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,"PREP_PROC_LOG");
	sprintf(TempIn.sCondition,"\n\
	WHERE  SOURCE_ID='%s' AND\n\
		FILE_NAME IN (\n\
			SELECT ORI_FILE_NAME FROM PREP_LOG\n\
			WHERE SOURCE_ID='%s' AND\n\
			DATA_DATE>=(TO_DATE('%s','yyyymmddhh24miss')-1) AND\n\
			DATA_DATE<=TO_DATE('%s','yyyymmddhh24miss')) AND\n\
		MODULE='%s'",sSourceID,sSourceID,sFileDate,sFileDate,sModule);


        /*ȡ�����м�¼���ض�����*/
        while(EGetPrepProcLogToStruct(&Temp,&TempIn)){
		
		strcpy(s.sSourceID,Temp.sSourceID);
		strcpy(s.sModule,Temp.sModule);
		strcpy(s.sChkFileName,Temp.sFileName);
		
		if(SearchBin(pRoot,&s,data_search_bintree_pick_check_log_e,
			(void **)&pHead)==FOUND){

			/*������������쳣���¹ؼ����ж�����¼����ֻ�ۼ�һ��*/
			if(pHead->iPreCnt>0) continue;

			pHead->iPreCnt=	Temp.iCnt;
			if((pHead->iChkCnt-pHead->iPreCnt)!=0)
				strcpy(pHead->sFileType,"00011");
			else
				strcpy(pHead->sFileType,"00111");
		}
        }
	return 0;
}

int data_search_bintree_pick_check_log_e(void *pValue,void*pData)
{
	struct PickCheckLogStruct *pSource=(struct PickCheckLogStruct *)pValue;
	struct PickCheckLogStruct *pTarget=(struct PickCheckLogStruct *)pData;
	int res;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	if((res=strcmp(pSource->sModule,pTarget->sModule))!=0) return res;
	if((res=strcmp(pSource->sChkFileName,pTarget->sChkFileName))!=0) return res;
	
	return 0;

}

int ProcessFile(char sBaseName[],char sFileName[],char sFileDate[],
	char sSourceID[],char sModule[])
{
	int iCnt=0,iChkCnt=0;
	char sHostTime[15],sChkFileName[128],sOri[128],sTemp[128];
	char sTableName[80];
	struct PickCheckLogStruct  Temp;
	struct FileControlStruct *ptHead=NULL,*pTemp,*pList=NULL;
	
	BINTREE *pRoot=NULL; 
	
	
	bzero((void*)&Temp,sizeof(struct PickCheckLogStruct));
	
/*���ļ����ݵ��ú������ص��ڴ�*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("�����ļ�%s���ڴ�ʧ��.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}

	GetHostTime(sHostTime);

	pList=ptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sOri,(char*)(pTemp->pData),pTemp->iLen);
		sOri[pTemp->iLen]=0;
		AllTrim(sOri);
		strncpy(sChkFileName,sOri,50);
		sChkFileName[50]=0;TrimAll(sChkFileName);
		strncpy(sTemp,sOri+50,10);
		sTemp[10]=0;iChkCnt=atoi(sTemp);
		
		strcpy(Temp.sSourceID,sSourceID);
		strcpy(Temp.sModule,sModule);
		strcpy(Temp.sFileName,sBaseName);
		strcpy(Temp.sFileDate,sFileDate);
		strcpy(Temp.sChkFileName,sChkFileName);
		Temp.iChkCnt=iChkCnt;
		Temp.iPreCnt=0;/*Ĭ�ϴ����¼Ϊ0*/
		strcpy(Temp.sFileType,"00000");/*Ĭ������Ϊû�ɼ�*/
		strcpy(Temp.sDealDate,sHostTime);

		if(InsertBin(&pRoot,(void *)&Temp,
			data_search_bintree_pick_check_log_e,
			assign_insert_bintree)<0){
			WriteAlertMsg("����BINTREEʧ��pick_check_log");
			return -1;
		}

		iCnt++;
	}	
/*����Ԥ������־��,�����ص����ݸ��µ�ƽ�������*/
	if(PrepProcLog2Bin(pRoot,sFileDate,sSourceID,sModule)<0){
		WriteAlertMsg("����BINTREEʧ��");
		return -1;
	}

/*����sFileType="00000"��pick����һ�飬���ӵ�ptOut����*/
	TravelBin(pRoot,link_pick_check_log_out);

/**������ݵ�ͳ�Ʊ�**/
	strcpy(sTableName,"PICK_CHECK_LOG");
	if(OutputList2Table(ptOut,sTableName)<0){
		WriteAlertMsg("������ݵ�ͳ�Ʊ����.\n");
		return -1;
	}

      	listfree(&pList);
     	
	return iCnt;


}
int main(int argc,char *argv[])
{
	int iCnt;
	char sFileName[128],sDateRule[13],sFileDate[15],*pc;
	char sSourceID[20],sModule[20],sBaseName[128],sCondition[256];
	
	static struct PickCheckLogStruct Temp;
	
	if(argc!=5){
		printf("Usage %s filename daterule sourceid module .\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	
	strcpy(sFileName,argv[1]);	TrimAll(sFileName);
	strcpy(sDateRule,argv[2]);	sDateRule[12]=0;TrimAll(sDateRule);
	strcpy(sSourceID,argv[3]);	sSourceID[6]=0;	TrimAll(sSourceID);
	strcpy(sModule,argv[4]);	sModule[3]=0;	TrimAll(sModule);
	
	GetBaseName(sFileName,sBaseName);
	
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;
	
	if(IniConnect("dataconnstr")<0) return -1;

/*��ȡDATA_DATE�ֶ�*/
	FileBackupDate(sFileName,sDateRule,sFileDate);
	if(strcmp(sFileDate,"")==0){
		WriteAlertMsg("�ļ�%s���ɷ���",sFileName);
		return -1;
	}
	
/*����Ѿ���������*/
	sprintf(sCondition,"WHERE SOURCE_ID='%s' AND \n\
			FILE_NAME='%s' AND	\n\
			MODULE='%s' ",sSourceID,sBaseName,sModule);
	if(SDGetPickCheckLogToStruct(&Temp,"PICK_CHECK_LOG",sCondition)==true)
		return 0;

	CommitWork();



	if((iCnt=ProcessFile(sBaseName,sFileName,sFileDate,sSourceID,sModule))<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	WriteProcMsg("��Դ%s�ɹ������ļ�%s,��¼%d",sSourceID,sBaseName,iCnt);
	printf("��Դ%s�ɹ������ļ�%s,��¼%d.\n",sSourceID,sBaseName,iCnt);
	
	CommitWorkRelease();
	
	return 0;
}








