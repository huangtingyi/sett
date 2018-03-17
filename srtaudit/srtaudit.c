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
/*去掉引示号,区号等*/	
	AllTrim(sMsisdn);
	AllTrim(sAreaCode);
	NewGetRawNbr(sMsisdn,sAreaCode,sStartTime,sRawNbr);
	
	if((SearchHeadCarr(sRawNbr,"*",sStartTime,&pHeadCarr))==FOUND){
		strcpy(sHead,pHeadCarr->sHead);
		iSettCarrID=pHeadCarr->iSettCarrierID;
	}else{
		strcpy(sHead,"");
		iSettCarrID=0;
	}
	
	return iSettCarrID;
}
int GetUserType(char sHead[],int iCarr,char sUser[])
{
	struct MobileHeadStruct *ptFound;
	
	if((SearchMobileHeadStruct(sHead,iCarr,&ptFound))==FOUND){
		strcpy(sUser,ptFound->sUserType);
	}else{
		strcpy(sUser,"");
	}
	
	return 0;
}
int DealRecordStt(struct SrtTicketStruct *pi,char sYearMonthDay[],
			struct SettItemControlDayStruct *po)
{
	static int iSettDur=0,iInFee=0,iOutFee=0;
	char sHead[16],sUser[6];
	int iSettCarrID=0;
	
	strcpy(po->sStatDate,sYearMonthDay);
	strcpy(po->sSettType,"6");
	strcpy(po->sCallType,pi->sCallType);
	strcpy(po->sDistanceType,pi->sDistanceType);
	strcpy(po->sCalledCode,pi->sCalledCode);
	strcpy(po->sVisitAreaCode,pi->sVisitAreaCode);
	strcpy(po->sHomeAreaCode,pi->sHomeAreaCode);
	po->iCallingCarrierID=pi->iCallingCarrierID;
	po->iCalledCarrierID=pi->iCalledCarrierID;
	iSettDur=(pi->iDuration+59)/60*60;
	sprintf(po->sSettDuration,"%d",iSettDur);
	po->sSettDuration[12]=0;
	
	po->iCnt=1;
	sprintf(po->sDuration,"%d",pi->iDuration);
	po->sDuration[12]=0;
	
	/*3:国内漫出，6：国内漫入，5：国际漫出，8：国际漫入*/
	if(strncmp(pi->sSourceID+3,"CRO",3)==0){
		strcpy(po->sRomeType,"3");	
	}else if(strncmp(pi->sSourceID+3,"CRI",3)==0){
		strcpy(po->sRomeType,"6");
	}else if(strncmp(pi->sSourceID+3,"CIO",3)==0){
		strcpy(po->sRomeType,"5");
	}else if(strncmp(pi->sSourceID+3,"CII",3)==0){
		strcpy(po->sRomeType,"8");
	}
	strcpy(sHead,"");
	iSettCarrID=0;
	if(strncmp(pi->sHomeAreaCode,"0",1)==0){
		strcpy(po->sUserType,"0");
	}else{
		iSettCarrID=GetMyHeadCarr(pi->sMsisdn,"*",iSettCarrID,sHead);
		GetUserType(sHead,iSettCarrID,sUser);
		if(strcmp(sUser,"")!=0){
			strcpy(po->sUserType,sUser);
		}else{
			if(iSettCarrID==1){
				strcpy(po->sUserType,"11");
			}else if(iSettCarrID==3){
				strcpy(po->sUserType,"33");
			}else if(iSettCarrID==5){
				strcpy(po->sUserType,"51");
			}else{
				strcpy(po->sUserType,"0");
			}
		}
	}
	
	strcpy(sHead,"");
	iSettCarrID=0;
	if(strncmp(pi->sCalledCode,"0",1)==0 ){
		strcpy(po->sCalledUserType,"0");
	}else{
		iSettCarrID=GetMyHeadCarr(pi->sOtherParty,"*",iSettCarrID,sHead);
		GetUserType(sHead,iSettCarrID,sUser);
		if(strcmp(sUser,"")!=0){
			strcpy(po->sCalledUserType,sUser);
		}else{
			if(iSettCarrID==1){
				strcpy(po->sCalledUserType,"11");
			}else if(iSettCarrID==3){
				strcpy(po->sCalledUserType,"33");
			}else if(iSettCarrID==5){
				strcpy(po->sCalledUserType,"51");
			}else{
				strcpy(po->sCalledUserType,"0");
			}
		}
	}

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
		po->sInFee[12]=0;
	}
	
	return 0;
}
int LoadSttTicket2Bin(char sTableName[],char sYearMonthDay[],BINTREE **pptRoot)
{
	static unsigned long ulTotalCnt=0;
	int  iNodeCnt=0;
	long long llSize=0;
	float iSettDur=0,iInFee=0,iOutFee=0,iDur=0;
	
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
		if(strcmp(Temp.sMsisdn,"")==0
			|| strncmp(Temp.sMsisdn,"0000",4)==0){
			continue;
		}
		if (++ulTotalCnt%100000==0){
			WriteProcMsg("正在加载表 %s 记录数 %lu 条",
				sTableName,ulTotalCnt);
		}
		if(ulTotalCnt>=10000000){
			WriteProcMsg("表 %s 总记录数 %lu 条退出!",
				sTableName,ulTotalCnt);
			return -1;
		}
		bzero(&snsTemp,sizeof(struct SettItemControlDayStruct));

		DealRecordStt(&Temp,sYearMonthDay,&snsTemp);
		
		if(SearchBin(*pptRoot,&snsTemp,data_search_bintree_sett_nbr_stat,
			(void**)&ptFound)==FOUND){
			
			ptFound->iCnt+=snsTemp.iCnt;
			
			iSettDur=atof(ptFound->sSettDuration);
			iInFee=atof(ptFound->sInFee);
			iOutFee=atof(ptFound->sOutFee);
			iDur=atof(ptFound->sDuration);
			
			iSettDur+=atoi(snsTemp.sSettDuration);
			iInFee+=atoi(snsTemp.sInFee);
			iOutFee+=atoi(snsTemp.sOutFee);
			iDur+=atoi(snsTemp.sDuration);
			
			sprintf(ptFound->sSettDuration,"%d",iSettDur);
			ptFound->sSettDuration[12]=0;
			sprintf(ptFound->sInFee,"%d",iInFee);
			ptFound->sInFee[12]=0;
			sprintf(ptFound->sOutFee,"%d",iOutFee);
			ptFound->sOutFee[12]=0;
			sprintf(ptFound->sDuration,"%d",iDur);
			ptFound->sDuration[12]=0;
				
		}else{
			if((pTemp=malloc(sizeof(struct SettItemControlDayStruct)))==NULL){
				WriteProcMsg("malloc SettItemControlAllStruct failed.");
				return -1;
			}
			bzero((void*)pTemp,sizeof(struct SettItemControlDayStruct));
			memcpy(pTemp,&snsTemp,sizeof(struct SettItemControlDayStruct));
			
			if(InsertBin(pptRoot,pTemp,data_search_bintree_sett_nbr_stat,
				assign_insert_bintree_sett_nbr_stat)<0){
				WriteProcMsg("建树 SettItemControlAllStruct 失败.");
				return -1;
			}
			++iNodeCnt;
			llSize+=sizeof(struct SettItemControlDayStruct);
		}

	}
	
	WriteProcMsg("加载表 %s 完毕,总记录数 %lu 条.",sTableName,ulTotalCnt);
	
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
				if((++ulRecCnt)%100000==0){
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
	WriteProcPrint("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);

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
	strcpy(sTableNameOut,"sett_item_control_day_srt");
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
	
	if(LoadSttTicket2Bin(sTableNameIn,sYearMonthDay,&ptRoot)<0) return -1;
	
	gStatList=NULL;
	
	TravelBin(ptRoot,append_bintree_au_sett_stat_t);
	
	if(OutputList2Table(gStatList,sTableNameOut)<0) return-1;
	
	DestroyBin(ptRoot);	
	
	DisconnectDatabase();
	
	return 0;
}
