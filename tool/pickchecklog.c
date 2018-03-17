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

/**输出数据到累帐表**/
        bzero((void*)&TempOut,sizeof(struct PickCheckLogStructOut));

        strcpy(TempOut.sTableName,sTableName);

  	ptCur=ptOut;
	iInsCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToPickCheckLog(ptPre,false,&TempOut)<0){
			printf("输出帐目错误pick_check_log.\n");
			WriteErrStackAlert();
			return -1;
		}
		iInsCnt++;

	}
	if(EInsertStructToPickCheckLog(NULL,true,&TempOut)<0){
		printf("输出帐目错误pick_check_log.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("更新表%s记录数%d.",sTableName,iInsCnt);
	
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


        /*取出表中记录加载二叉树*/
        while(EGetPrepProcLogToStruct(&Temp,&TempIn)){
		
		strcpy(s.sSourceID,Temp.sSourceID);
		strcpy(s.sModule,Temp.sModule);
		strcpy(s.sChkFileName,Temp.sFileName);
		
		if(SearchBin(pRoot,&s,data_search_bintree_pick_check_log_e,
			(void **)&pHead)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
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
	
/*将文件数据调用函数加载到内存*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件%s到内存失败.\n",sFileName);
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
		Temp.iPreCnt=0;/*默认处理记录为0*/
		strcpy(Temp.sFileType,"00000");/*默认类型为没采集*/
		strcpy(Temp.sDealDate,sHostTime);

		if(InsertBin(&pRoot,(void *)&Temp,
			data_search_bintree_pick_check_log_e,
			assign_insert_bintree)<0){
			WriteAlertMsg("生成BINTREE失败pick_check_log");
			return -1;
		}

		iCnt++;
	}	
/*加载预处理日志表,将加载的数据更新到平衡二叉树*/
	if(PrepProcLog2Bin(pRoot,sFileDate,sSourceID,sModule)<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}

/*将有sFileType="00000"到pick表找一遍，并加到ptOut链表*/
	TravelBin(pRoot,link_pick_check_log_out);

/**输出数据到统计表**/
	strcpy(sTableName,"PICK_CHECK_LOG");
	if(OutputList2Table(ptOut,sTableName)<0){
		WriteAlertMsg("输出数据到统计表出错.\n");
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

/*获取DATA_DATE字段*/
	FileBackupDate(sFileName,sDateRule,sFileDate);
	if(strcmp(sFileDate,"")==0){
		WriteAlertMsg("文件%s不可访问",sFileName);
		return -1;
	}
	
/*如果已经入库就算了*/
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
	
	WriteProcMsg("来源%s成功处理文件%s,记录%d",sSourceID,sBaseName,iCnt);
	printf("来源%s成功处理文件%s,记录%d.\n",sSourceID,sBaseName,iCnt);
	
	CommitWorkRelease();
	
	return 0;
}








