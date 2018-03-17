#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include<math.h>
#include <wwdb.h>
#include <bintree.h>
#include <dbsupp.h>

#include "../include/extend_intf.h"
#include "../include/stt_ticket.h"

#include "srt_info.h"

struct SettItemControlAllStruct *gStatList=NULL;

int  iNumdays=0;
char sYesMonth[9],sYesterday[9];
char sConMonth[9],sConLMonth[9];
char sConLYMonth[9],sConFMonth[9],sConLDMonth[9];
char sCondition1[512],sCondition2[512],sCondition3[512];

int data_search_bintree_stat(void *pValue,void *pData)
{
	int iRes=0;

	struct SettItemControlAllStruct *pSource=(struct SettItemControlAllStruct*)pValue;
	struct SettItemControlAllStruct *pTarget=(struct SettItemControlAllStruct*)pData;

	if((iRes=strcmp(pSource->sSettType,pTarget->sSettType))!=0) return iRes;
	if((iRes=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return iRes;
	if((iRes=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return iRes;
	if((iRes=strcmp(pSource->sRoamType,pTarget->sRoamType))!=0) return iRes;
	if((iRes=strcmp(pSource->sDistanceType,pTarget->sDistanceType))!=0) return iRes;
	if((iRes=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sCalledUserType,pTarget->sCalledUserType))!=0) return iRes;
	

	return 0;

}
void assign_insert_bintree_day_stat(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int append_bintree_to_list_day_stat(void **ppData)
{
	struct SettItemControlAllStruct *pTemp=(struct SettItemControlAllStruct*)(*ppData);

	pTemp->pLoadNext=gStatList;
	gStatList=pTemp;

	return 0;
}
int GetConditionTime(char sYearMonthDay[],char sCondition1[],
				char sCondition2[],char sCondition3[])
{
	int iLen1=0,iLen2=0,iLen3=0;
	char sMonth[3],sFirstDay[16],sTemp[9];
	char sLastYear[16],sTime[16],sLastTime[16];
	char sYearMonth[7],sLastMonthDay[16],sLastDay[16];
	
	strncpy(sYearMonth,sYearMonthDay,6);
	sYearMonth[6]=0;
	sprintf(sFirstDay,"%s01000000",sYearMonth);
	
	strcpy(sTime,sYearMonthDay);
	strcat(sTime,"000000");
	
	strcpy(sLastYear,sYearMonthDay);
	strcat(sLastYear,"000000");
	
	strcpy(sLastMonthDay,sFirstDay);
	strcpy(sLastDay,sFirstDay);
	
	AddMonths(sLastMonthDay,-1);
	AddMonths(sTime,-1);
	
	AddYears(sLastYear,-1);
	AddYears(sLastDay,-1);
	
	strcpy(sLastTime,sYearMonthDay);
	strcat(sLastTime,"000000");
	AddDays(sLastTime,-1);
	
	strncpy(sTemp,sLastTime,8);
	sTemp[8]=0;
	strcpy(sYesterday,sTemp);
	
	strncpy(sConLMonth,sLastMonthDay,8);
	sConLMonth[8]=0;
	strncpy(sConMonth,sFirstDay,8);
	sConMonth[8]=0;
	strncpy(sConLDMonth,sTime,8);
	sConLDMonth[8]=0;
	strcpy(sYesMonth,sConLDMonth);
	
	strncpy(sConFMonth,sLastYear,8);
	sConFMonth[8]=0;
	strncpy(sConLYMonth,sLastDay,8);
	sConLYMonth[8]=0;
	
	iLen1=sprintf(sCondition1,
		"WHERE STAT_DATE BETWEEN '%s' AND '%s' ",
		sConLMonth,sConLDMonth);
	sCondition1[iLen1]=0;
	
	iLen2=sprintf(sCondition2,
		"WHERE STAT_DATE BETWEEN '%s' AND '%s' ",
		sConMonth,sYearMonthDay);
	sCondition2[iLen2]=0;
	
	iLen3=sprintf(sCondition3,
		"WHERE STAT_DATE BETWEEN '%s' AND '%s' ",
		sConLYMonth,sConFMonth);
	sCondition1[iLen3]=0;
	
	return 0;
}
int GenSttStatistics2Bin(BINTREE **pptRoot,
	struct SettItemControlDayStruct *pTemp)
{
	struct SettItemControlAllStruct *po;
	
	if((po=malloc(sizeof(struct SettItemControlAllStruct)))==NULL){
		WriteProcMsg("malloc SettItemControlAllStruct failed.");
		return -1;
	}
			
	bzero((void*)po,sizeof(struct SettItemControlAllStruct));
	
	strcpy(po->sStatDate,pTemp->sStatDate);
	strcpy(po->sSettType,pTemp->sSettType);
	strcpy(po->sCallType,pTemp->sCallType);
	strcpy(po->sUserType,pTemp->sUserType);
	strcpy(po->sRoamType,pTemp->sRomeType);
	strcpy(po->sDistanceType,pTemp->sDistanceType);
	strcpy(po->sCalledCode,pTemp->sCalledCode);
	strcpy(po->sVisitAreaCode,pTemp->sVisitAreaCode);
	strcpy(po->sHomeAreaCode,pTemp->sHomeAreaCode);
	po->iCallingCarrierID=pTemp->iCallingCarrierID;
	po->iCalledCarrierID=pTemp->iCalledCarrierID;
	strcpy(po->sCalledUserType,pTemp->sCalledUserType);
	po->iCnt=pTemp->iCnt;
	strcpy(po->sDuration,pTemp->sDuration);
	strcpy(po->sSettDuration,pTemp->sSettDuration);
	strcpy(po->sInFee,pTemp->sInFee);
	strcpy(po->sOutFee,pTemp->sOutFee);
	po->iCnt1=0;
	strcpy(po->sDuration1,"0");
	strcpy(po->sSettDuration1,"0");
	strcpy(po->sInFee1,"0");
	strcpy(po->sOutFee1,"0");
	po->iCnt2=0;
	strcpy(po->sDuration2,"0");
	strcpy(po->sSettDuration2,"0");
	strcpy(po->sInFee2,"0");
	strcpy(po->sOutFee2,"0");
	po->iCnt3=0;
	strcpy(po->sDuration3,"0");
	strcpy(po->sSettDuration3,"0");
	strcpy(po->sInFee3,"0");
	strcpy(po->sOutFee3,"0");
	po->iCnt4=0;
	strcpy(po->sDuration4,"0");
	strcpy(po->sSettDuration4,"0");
	strcpy(po->sInFee4,"0");
	strcpy(po->sOutFee4,"0");
	po->iCnt5=0;
	strcpy(po->sDuration5,"0");
	strcpy(po->sSettDuration5,"0");
	strcpy(po->sInFee5,"0");
	strcpy(po->sOutFee5,"0");
	po->iCnt6=0;
	strcpy(po->sDuration6,"0");
	strcpy(po->sSettDuration6,"0");
	strcpy(po->sInFee6,"0");
	strcpy(po->sOutFee6,"0");
	po->iCnt7=0;
	strcpy(po->sDuration7,"0");
	strcpy(po->sSettDuration7,"0");
	strcpy(po->sInFee7,"0");
	strcpy(po->sOutFee7,"0");
	
	if(InsertBin(pptRoot,po,data_search_bintree_stat,
			assign_insert_bintree_day_stat)<0){
		WriteAlertMsg("生成二叉树 struct PrepTicketSttOutStruct 失败.");
		return -1;
	}
	
	return 0;
}
int UpdateSttStatistics2Bin(BINTREE **pptRoot,int iFlag,
			struct SettItemControlDayStruct *pTemp)
{
	struct SettItemControlAllStruct *po,*ptFound;
	
	if((po=malloc(sizeof(struct SettItemControlAllStruct)))==NULL){
		WriteProcMsg("malloc SettItemControlAllStruct failed.");
		return -1;
	}
			
	bzero((void*)po,sizeof(struct SettItemControlAllStruct));
	
	strcpy(po->sSettType,pTemp->sSettType);
	strcpy(po->sCallType,pTemp->sCallType);
	strcpy(po->sUserType,pTemp->sUserType);
	strcpy(po->sRoamType,pTemp->sRomeType);
	strcpy(po->sDistanceType,pTemp->sDistanceType);
	strcpy(po->sCalledCode,pTemp->sCalledCode);
	strcpy(po->sVisitAreaCode,pTemp->sVisitAreaCode);
	strcpy(po->sHomeAreaCode,pTemp->sHomeAreaCode);
	po->iCallingCarrierID=pTemp->iCallingCarrierID;
	po->iCalledCarrierID=pTemp->iCalledCarrierID;
	strcpy(po->sCalledUserType,pTemp->sCalledUserType);
	
	if(SearchBin(*pptRoot,po,data_search_bintree_stat,
		(void**)&ptFound)==FOUND){
		if(iFlag==1){	
			ptFound->iCnt1=pTemp->iCnt;
			strcpy(ptFound->sDuration1,pTemp->sDuration);
			strcpy(ptFound->sSettDuration1,pTemp->sSettDuration);
			strcpy(ptFound->sInFee1,pTemp->sInFee);
			strcpy(ptFound->sOutFee1,pTemp->sOutFee);
		
		}
		if(iFlag==2){	
			ptFound->iCnt2=pTemp->iCnt;
			strcpy(ptFound->sDuration2,pTemp->sDuration);
			strcpy(ptFound->sSettDuration2,pTemp->sSettDuration);
			strcpy(ptFound->sInFee2,pTemp->sInFee);
			strcpy(ptFound->sOutFee2,pTemp->sOutFee);
		}
	}
	
	
	return 0;
}
int EListCntSttStatistics2Bin(BINTREE **pptRootUpdate,
			struct SettItemControlDayStruct *pTemp)
{
	struct SettItemControlAllStruct *po,*ptFound,*ptCur; 
	float iSettDur=0,iInFee=0,iOutFee=0,iDur=0;
	
	if((po=malloc(sizeof(struct SettItemControlAllStruct)))==NULL){
		WriteProcMsg("malloc SettItemControlAllStruct failed.");
		return -1;
	}
			
	bzero((void*)po,sizeof(struct SettItemControlAllStruct));
	
	strcpy(po->sSettType,pTemp->sSettType);
	strcpy(po->sCallType,pTemp->sCallType);
	strcpy(po->sUserType,pTemp->sUserType);
	strcpy(po->sRoamType,pTemp->sRomeType);
	strcpy(po->sDistanceType,pTemp->sDistanceType);
	strcpy(po->sCalledCode,pTemp->sCalledCode);
	strcpy(po->sVisitAreaCode,pTemp->sVisitAreaCode);
	strcpy(po->sHomeAreaCode,pTemp->sHomeAreaCode);
	po->iCallingCarrierID=pTemp->iCallingCarrierID;
	po->iCalledCarrierID=pTemp->iCalledCarrierID;
	strcpy(po->sCalledUserType,pTemp->sCalledUserType);
	
	if(SearchBin(*pptRootUpdate,po,data_search_bintree_stat,
		(void**)&ptFound)==FOUND){
		ptFound->iCnt+=pTemp->iCnt;
		iSettDur+=atof(pTemp->sSettDuration);
		iInFee+=atof(pTemp->sInFee);
		iOutFee+=atof(pTemp->sOutFee);
		iDur+=atof(pTemp->sDuration);
		
		
		sprintf(ptFound->sSettDuration,"%lf",floor(iSettDur));
		ptFound->sSettDuration[12]=0;
		
		sprintf(ptFound->sInFee,"%lf",floor(iInFee));
		ptFound->sInFee[12]=0;
		sprintf(ptFound->sOutFee,"%lf",floor(iOutFee));
		ptFound->sOutFee[12]=0;
		sprintf(ptFound->sDuration,"%lf",floor(iDur));
		ptFound->sDuration[12]=0;
		
	}else{
		if(InsertBin(pptRootUpdate,po,data_search_bintree_stat,
			assign_insert_bintree_day_stat)<0){
			WriteAlertMsg("生成二叉树 struct PrepTicketSttOutStruct 失败.");
			return -1;
		}
	}
	
	return 0;
}
int UpdataCntSttStatistics2Bin(BINTREE **pptRoot,int iFlag, 
			struct SettItemControlAllStruct *ptHead)
{
	struct SettItemControlAllStruct *ptCur=NULL;
	struct SettItemControlAllStruct *ptLoadCur=NULL;
	struct SettItemControlAllStruct *ptFound=NULL;
	static float iSettDur=0,iInFee=0,iOutFee=0,iDur=0;
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
			while(ptLoadCur!= NULL){
				ptCur = ptLoadCur;
				ptLoadCur = ptLoadCur->pNext;
				if(SearchBin(*pptRoot,ptCur,data_search_bintree_stat,
					(void**)&ptFound)==FOUND){
					if(iFlag==3){	
						ptFound->iCnt6=ptCur->iCnt;
						strcpy(ptFound->sDuration6,ptCur->sDuration);
						strcpy(ptFound->sSettDuration6,ptCur->sSettDuration);
						strcpy(ptFound->sInFee6,ptCur->sInFee);
						strcpy(ptFound->sOutFee6,ptCur->sOutFee);
						
						iSettDur=floor(atof(ptCur->sSettDuration)/iNumdays);
						iInFee=floor(atof(ptCur->sInFee)/iNumdays);
						iOutFee=floor(atof(ptCur->sOutFee)/iNumdays);
						iDur=floor(atof(ptCur->sDuration)/iNumdays);	
						
						ptFound->iCnt3=ptCur->iCnt/iNumdays;
						sprintf(ptFound->sSettDuration3,"%lf",floor(iSettDur));
						ptFound->sSettDuration3[12]=0;
						sprintf(ptFound->sInFee3,"%lf",floor(iInFee));
						ptFound->sInFee3[12]=0;
						sprintf(ptFound->sOutFee3,"%lf",floor(iOutFee));
						ptFound->sOutFee3[12]=0;
						sprintf(ptFound->sDuration3,"%lf",floor(iDur));
						ptFound->sDuration3[12]=0;
					}
					if(iFlag==4){	
						ptFound->iCnt5=ptCur->iCnt;
						strcpy(ptFound->sDuration5,ptCur->sDuration);
						strcpy(ptFound->sSettDuration5,ptCur->sSettDuration);
						strcpy(ptFound->sInFee5,ptCur->sInFee);
						strcpy(ptFound->sOutFee5,ptCur->sOutFee);
						
						iSettDur=floor(atof(ptCur->sSettDuration)/iNumdays);
						iInFee=floor(atof(ptCur->sInFee)/iNumdays);
						iOutFee=floor(atof(ptCur->sOutFee)/iNumdays);
						iDur=floor(atof(ptCur->sDuration)/iNumdays);	
						
						ptFound->iCnt4=ptCur->iCnt/iNumdays;
						sprintf(ptFound->sSettDuration4,"%lf",floor(iSettDur));
						ptFound->sSettDuration4[12]=0;
						sprintf(ptFound->sInFee4,"%lf",floor(iInFee));
						ptFound->sInFee4[12]=0;
						sprintf(ptFound->sOutFee4,"%lf",floor(iOutFee));
						ptFound->sOutFee4[12]=0;
						sprintf(ptFound->sDuration4,"%lf",floor(iDur));
						ptFound->sDuration4[12]=0;
						
					}
					if(iFlag==5){	
						ptFound->iCnt7=ptCur->iCnt;
						strcpy(ptFound->sDuration7,ptCur->sDuration);
						strcpy(ptFound->sSettDuration7,ptCur->sSettDuration);
						strcpy(ptFound->sInFee7,ptCur->sInFee);
						strcpy(ptFound->sOutFee7,ptCur->sOutFee);
					}
				}
			}
	}
	return 0;
}
int LoadSttControlDay2Bin(char sTableName[],char sYearMonth[],
		BINTREE **pptRoot,int iFlag,BINTREE **pptRootUpdate)
{
	int iStat=0;
	unsigned long ulTotalCnt=0; 
	
	struct SettItemControlDayStructIn TempIn;
	struct SettItemControlDayStruct   Temp;
	
	bzero(&TempIn,sizeof(struct SettItemControlDayStructIn));
	
	strcpy(TempIn.sTableName,sTableName);
	if(iFlag==0 ||iFlag==1 || iFlag==2){
		sprintf(TempIn.sCondition,"where STAT_DATE='%s'",sYearMonth);
	}else if(iFlag==3){
		strcpy(TempIn.sCondition,sCondition1);
	}else if(iFlag==4){
		strcpy(TempIn.sCondition,sCondition2);
	}else if(iFlag==5){
		strcpy(TempIn.sCondition,sCondition3);
	}
 	
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	if(iFlag==0){
		if(iStat==0){
			*pptRoot=NULL;
			 iStat=1;
		}
	}
	while(EGetSettItemControlDayToStruct(&Temp,&TempIn)){
		if (++ulTotalCnt%10000==0){
			WriteProcMsg("正在加载表 %s 记录数 %lu 条!",
				sTableName,ulTotalCnt);
		}
		if(iFlag==0){
			if(GenSttStatistics2Bin(pptRoot,&Temp)<0) return -1;
		}else if(iFlag==1){
			if(UpdateSttStatistics2Bin(pptRoot,1,&Temp)<0) return -1;
		}else if(iFlag==2){
			if(UpdateSttStatistics2Bin(pptRoot,2,&Temp)<0) return -1;
		}else{
			if(EListCntSttStatistics2Bin(pptRootUpdate,&Temp)<0) return -1;
		}
	}
	gStatList=NULL;
	TravelBin(*pptRootUpdate,append_bintree_to_list_day_stat);
	if(iFlag==3){
		if(UpdataCntSttStatistics2Bin(pptRoot,3,gStatList)<0) return -1;
	}else if(iFlag==5){
		if(UpdataCntSttStatistics2Bin(pptRoot,4,gStatList)<0) return -1;
	}
	else if(iFlag==6){
		if(UpdataCntSttStatistics2Bin(pptRoot,5,gStatList)<0) return -1;
	}
	
	WriteProcMsg("加载表 %s 完毕,总记录数 %lu 条.",sTableName,ulTotalCnt);
	
	return 0;
}
int EInsertList2Table(struct SettItemControlAllStruct *ptHead,char sTableName[])
{
	unsigned long ulRecCnt=0;

	struct SettItemControlAllStructOut TempOut;
	struct SettItemControlAllStruct *ptCur=NULL;
	struct SettItemControlAllStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct SettItemControlAllStructOut));

	strcpy(TempOut.sTableName,sTableName);

	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
			while(ptLoadCur!= NULL){
				ptCur = ptLoadCur;
				ptLoadCur = ptLoadCur->pNext;
				if((++ulRecCnt)%10000==0){
					if(EInsertStructToSettItemControlAll(NULL,true,&TempOut)<0){
						WriteAlertMsg("写表%s错误.",sTableName);
						WriteErrStackAlert();
						return -1;
					}
					CommitWork();
					WriteProcMsg("当前输出数据到Busi表 %s 记录数 %lu 条.",
						sTableName,ulRecCnt);
				}
				if(EInsertStructToSettItemControlAll(ptCur,false,&TempOut)<0){
					WriteAlertMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					return -1;
				}
				free(ptCur);
			}
	}
	if(EInsertStructToSettItemControlAll(NULL,true,&TempOut)<0){
		WriteAlertMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		return -1;
	}
	CommitWork();
	WriteProcPrint("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);

	return 0;
}
int main(int argc,char *argv[])
{
	char sYearMonthDay[9],sDays[3];
	char sTableNameIn[64],sTableNameOut[64];
	BINTREE *ptRoot=NULL,*ptRootUpdate=NULL;
	
	if(argc!=2){
		printf("%s YearMonthDay(20120815)\n",argv[0]);
		return -1;
	}
	strcpy(sYearMonthDay,argv[1]);
	strncpy(sDays,sYearMonthDay+6,2);
	sDays[2]=0;
	iNumdays=atof(sDays);
	
	sprintf(sTableNameIn,"sett_item_control_all_v2");
	strcpy(sTableNameOut,"sett_item_control_all_temp");
	
	GetConditionTime(sYearMonthDay,sCondition1,
				sCondition2,sCondition3);
				
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
	
	if(LoadSttControlDay2Bin(sTableNameIn,sYearMonthDay,&ptRoot,0,NULL)<0) return -1;
		
	if(LoadSttControlDay2Bin(sTableNameIn,sYesMonth,&ptRoot,1,NULL)<0) return -1;

	if(LoadSttControlDay2Bin(sTableNameIn,sYesterday,&ptRoot,2,NULL)<0) return -1;
	
	if(LoadSttControlDay2Bin(sTableNameIn,"",&ptRoot,3,&ptRootUpdate)<0) return -1;
		
	if(LoadSttControlDay2Bin(sTableNameIn,"",&ptRoot,4,&ptRootUpdate)<0) return -1;
			
	if(LoadSttControlDay2Bin(sTableNameIn,"",&ptRoot,5,&ptRootUpdate)<0) return -1;
	
	gStatList=NULL;

	TravelBin(ptRoot,append_bintree_to_list_day_stat);
	
	if(EInsertList2Table(gStatList,sTableNameOut)<0) return -1;

	DestroyBin(ptRoot);	
	
	DisconnectDatabase();

	return 0;
}
