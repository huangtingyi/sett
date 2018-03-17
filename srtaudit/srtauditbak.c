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
#include <wwdb.h>
#include <bintree.h>
#include <dbsupp.h>

#include "../include/extend_intf.h"
#include "../include/stt_ticket.h"

#include "srt_info.h"

unsigned long long lCurUseMem=0ULL;
struct SettItemControlDayStruct *gStatList=NULL;

int data_search_bintree_sett_nbr_stat(void *pValue,void *pData)
{
	int iRes;
	
	struct SettItemControlDayStruct *pSource=(struct SettItemControlDayStruct *)pValue;
	struct SettItemControlDayStruct *pTarget=(struct SettItemControlDayStruct *)pData;
	
	if((iRes=strcmp(pSource->sStatDate,pTarget->sStatDate))!=0) return iRes;
	if((iRes=strcmp(pSource->sSettType,pTarget->sSettType))!=0) return iRes;
	if((iRes=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return iRes;
	if((iRes=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return iRes;
	if((iRes=strcmp(pSource->sRomeType,pTarget->sRomeType))!=0) return iRes;
	if((iRes=strcmp(pSource->sDistanceType,pTarget->sDistanceType))!=0) return iRes;
	if((iRes=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return iRes;
	if((iRes=strcmp(pSource->sCalledUserType,pTarget->sCalledUserType))!=0) return iRes;
	
	return 0;
}
void assign_insert_bintree_sett_nbr_stat(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}
int append_bintree_au_sett_stat_t(void **ppData)
{
	struct SettItemControlDayStruct *pTemp=(struct SettItemControlDayStruct *)*ppData;
	
	InsertList((LIST**)&gStatList,(LIST*)pTemp);
	
	return 0;
}		
int GetMyHeadCarr(char sMsisdn[],char sAreaCode[],
			int iSettCarrID,char sHead[])
{
	static char sRawNbr[25];
	char sStartTime[16];
	struct HeadCarrStruct *pHeadCarr;
	
	GetHostTime(sStartTime);
/*去掉引示号,区号等	
	AllTrim(sMsisdn);
	AllTrim(sAreaCode);
	NewGetRawNbr(sMsisdn,sAreaCode,sStartTime,sRawNbr);
*/	
	if((SearchHeadCarr(sMsisdn,"*",sStartTime,&pHeadCarr))==FOUND){
		strcpy(sHead,pHeadCarr->sHead);
		iSettCarrID=pHeadCarr->iSettCarrierID;
	}
	
	return iSettCarrID;
}
int GetUserType(char sHead[],int iCarr,char sUser[])
{
	static char sRawNbr[25];
	char sStartTime[16];
	struct MobileHeadStruct *ptFound;
	
	if((SearchMobileHeadStruct(sHead,iCarr,&ptFound))==FOUND){
		strcpy(sUser,ptFound->sUserType);
	}
	
	return 0;
}
int DealRecordStt(struct SrtTicketStruct *pi,char sYearMonthDay[],
			struct SettItemControlDayStruct *po)
{
	int iSettDur=0,iInFee=0,iOutFee=0;
	char sHead[16],sUser[6];
	int iSettCarrID=0;
	
	strcpy(po->sStatDate,sYearMonthDay);
	strcpy(po->sSettType,"7");
	strcpy(po->sCallType,pi->sCallType);
	strcpy(po->sDistanceType,pi->sDistanceType);
	strcpy(po->sCalledCode,pi->sCalledCode);
	strcpy(po->sVisitAreaCode,pi->sVisitAreaCode);
	strcpy(po->sHomeAreaCode,pi->sHomeAreaCode);
	
	
	iSettDur=(pi->iDuration+59)/60;
	sprintf(po->sSettDuration,"%d",iSettDur);
	po->sSettDuration[12]=0;
	
	po->iCnt=1;
	sprintf(po->sDuration,"%d",pi->iDuration);
	po->sDuration[12]=0;
	
	/*0:国内漫出，1：国内漫入，2：国际漫出，3：国际漫入*/
	if(strncmp(pi->sSourceID+3,"CRO",3)==0){
		strcpy(po->sRomeType,"0");	
	}else if(strncmp(pi->sSourceID+3,"CRI",3)==0){
		strcpy(po->sRomeType,"1");
	}else if(strncmp(pi->sSourceID+3,"CIO",3)==0){
		strcpy(po->sRomeType,"2");
	}else if(strncmp(pi->sSourceID+3,"CII",3)==0){
		strcpy(po->sRomeType,"3");
	}
/*	
	iSettCarrID=GetMyHeadCarr(pi->sMsisdn,"*",iSettCarrID,sHead);
	GetUserType(sHead,iSettCarrID,sUser);
	strcpy(po->sUserType,sUser);
	
	strcpy(sHead,"");
	iSettCarrID=0;
	
	iSettCarrID=GetMyHeadCarr(pi->sOtherParty,"*",iSettCarrID,sHead);
	GetUserType(sHead,iSettCarrID,sUser);
	strcpy(po->sCalledUserType,sUser);
*/
	if(strncmp(pi->sSourceID+3,"CII",3)==0
		|| strncmp(pi->sSourceID+3,"CRI",3)==0){
		strcpy(po->sStatFee,"1");	
		iInFee=pi->iRoamFee;
		sprintf(po->sInFee,"%d",iInFee);
		po->sInFee[12]=0;
	}else if(strncmp(pi->sSourceID+3,"CIO",3)==0
		|| strncmp(pi->sSourceID+3,"CRO",3)==0){
		strcpy(po->sStatFee,"0");
		iOutFee=pi->iRoamFee;
		sprintf(po->sOutFee,"%d",iOutFee);
		po->sOutFee[12]=0;
	}
	
	return 0;
}
int LoadSttTicket2Bin(char sTableName[],char sYearMonthDay[],BINTREE **pptRoot)
{
	unsigned long ulTotalCnt=0;
	int iRecCnt=0,iNodeCnt=0;
	long long llSize=0;
	int iSettDur=0,iInFee=0,iOutFee=0,iDur=0;
	
	struct SrtTicketStruct Temp;
	struct SrtTicketStructIn TempIn;
	struct SettItemControlDayStruct *pTemp,*ptFound,snsTemp,*ptCur;
	
	bzero(&TempIn,sizeof(struct SrtTicketStructIn));
	
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition," where source_id  like 'BILCRO%' or  source_id  like 'BILCRI%' or  source_id  like 'BILCIO%'  or  source_id  like 'BILCII%'");

   	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	*pptRoot=NULL;

	while(EGetSrtTicketToStruct(&Temp,&TempIn)){
		if (++ulTotalCnt%10000==0){
			WriteProcMsg("正在加载表 %s 记录数 %lu 条",
				sTableName,ulTotalCnt);
		}
		bzero(&snsTemp,sizeof(struct SrtTicketStruct));

		DealRecordStt(&Temp,sYearMonthDay,&snsTemp);
/*		
		if(SearchBin(*pptRoot,&snsTemp,data_search_bintree_sett_nbr_stat,
			(void**)&ptFound)==FOUND){
				while(ptFound!=NULL){
					ptCur=ptFound;
					ptFound=ptFound->pNext;
					
					ptCur->iCnt+=snsTemp.iCnt;
					iSettDur+=atoi(snsTemp.sSettDuration);
					if(strcmp(ptCur->sStatFee,"0")==0){
						iInFee+=atoi(snsTemp.sInFee);
					}else if(strcmp(ptCur->sStatFee,"1")==0){
						iOutFee+=atoi(snsTemp.sOutFee);
					}
					iDur+=atoi(snsTemp.sDuration);
				}	
				sprintf(ptCur->sSettDuration,"%d",iSettDur);
				ptCur->sSettDuration[12]=0;
				sprintf(ptCur->sInFee,"%d",iInFee);
				ptCur->sInFee[12]=0;
				sprintf(ptCur->sOutFee,"%d",iOutFee);
				ptCur->sOutFee[12]=0;
				sprintf(ptCur->sDuration,"%d",iDur);
				ptCur->sDuration[12]=0;
				
		}else{
			if((pTemp=malloc(sizeof(struct SettItemControlDayStruct)))==NULL){
				WriteProcMsg("malloc SettItemControlAllStruct failed.");
				return -1;
			}
			bzero((void*)pTemp,sizeof(struct SettItemControlDayStruct));
			memcpy(pTemp,&snsTemp,sizeof(struct SettItemControlDayStruct));
			pTemp->pNext=NULL;
			
			if(InsertBin(pptRoot,pTemp,data_search_bintree_sett_nbr_stat,
				assign_insert_bintree_sett_nbr_stat)<0){
				WriteProcMsg("建树 SettItemControlAllStruct 失败.");
				return -1;
			}
			++iNodeCnt;
			llSize+=sizeof(struct SettItemControlDayStruct);
		}
*/
	}
	
	WriteProcMsg("加载表 %s 完毕,总记录数 %lu 条.",sTableName,ulTotalCnt);
	printf("加载表 %s 完毕,总记录数 %lu 条.\n",sTableName,ulTotalCnt);
	
	return 0;
}
int OutputList2Table(struct SettItemControlDayStruct *ptHead,char sTableName[])
{
	unsigned long ulRecCnt=0;
	struct SettItemControlDayStructOut TempOut;
	struct SettItemControlDayStruct *ptCur=NULL;
	struct SettItemControlDayStruct *ptLoadCur=NULL;
	
	bzero(&TempOut,sizeof(struct SettItemControlDayStructOut));

	strcpy(TempOut.sTableName,sTableName);

	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
			while(ptLoadCur!= NULL){
				ptCur = ptLoadCur;
				ptLoadCur = ptLoadCur->pNext;
					if((++ulRecCnt)%10000==0){
						if(EInsertStructToSettItemControlDay(NULL,true,&TempOut)<0){
							WriteAlertMsg("写表%s错误.",sTableName);
							WriteErrStackAlert();
							return -1;
						}
						CommitWork();
						WriteProcMsg("当前输出数据到Busi表 %s 记录数 %lu 条.",
							sTableName,ulRecCnt);
					}
				if(EInsertStructToSettItemControlDay(ptCur,false,&TempOut)<0){
					WriteAlertMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					return -1;
				}
				free(ptCur);
				lCurUseMem -= sizeof(struct SettItemControlDayStructOut);
				lCurUseMem -= sizeof(BINTREE);
			}
	}
	if(EInsertStructToSettItemControlDay(NULL,true,&TempOut)<0){
		WriteAlertMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		return -1;
	}
	CommitWork();
	WriteProcPrint("输出数据到Busi表 %s 总记录数 %lu 条.",sTableName,ulRecCnt);

	return 0;
}
int main(int argc,char *argv[])
{
	char sTableNameIn[64],sTableNameOut[64];
	char sYearMonthDay[9],sMonth[3];
	BINTREE *ptRoot=NULL,*ptRootUpdate=NULL;
	
	if(argc!=2){
		printf("%s YearMonthDay(20120815)\n",argv[0]);
		return -1;
	}
	strcpy(sYearMonthDay,argv[1]);
	strncpy(sMonth,sYearMonthDay+4,2);
	sMonth[2]=0;
	
	sprintf(sTableNameIn,"SRT_TICKET_%s partition(part%s)",sMonth,sYearMonthDay);
	strcpy(sTableNameOut,"sett_item_control_all_v2");
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
	
	if(LoadSttTicket2Bin(sTableNameIn,sYearMonthDay,&ptRoot)<0) return -1;
	
	gStatList=NULL;
	
	TravelBin(ptRoot,append_bintree_au_sett_stat_t);
	
	if(OutputList2Table(gStatList,sTableNameOut)<0) return-1;
	
	DestroyBin(ptRoot);	
	
	DisconnectDatabase();
	
	printf("Success\n");
	
	return 0;
}
