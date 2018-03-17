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

struct SettItemControlDayStruct *gStatList=NULL;
char gsFeeType[3],gsStat[3];

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
int GetHeadCarredCode(struct DwSusVoiticketDsStruct *pi,int iFlag)
{
	int iCarrID=0;
	char sStartTime[16];
	struct HeadCarrStruct *ptFound=NULL;
	
	GetHostTime(sStartTime);
	
	if(iFlag==1){
		if(SearchHeadCarr(pi->sAccNbr,"*",sStartTime,
			&ptFound)==FOUND){
			iCarrID=ptFound->iSettCarrierID;
		}else{
			iCarrID=0;
		}
	}else{
		if(SearchHeadCarr(pi->sOtherParty,"*",sStartTime,
			&ptFound)==FOUND){
			iCarrID=ptFound->iSettCarrierID;
		}else{
			iCarrID=0;
		}
	}
	
	return iCarrID;
}
int GetFMQAreaCode(char sAcctNbr[],char sAreaCode[])
{
	struct AreaCodeDescStruct *ptFound=NULL;
	
	if(SearchCityCodeDesc(sAcctNbr,&ptFound)==FOUND){
		strncpy(sAreaCode,ptFound->sAreaCode,8);
		sAreaCode[8]=0;
	}else{
		strcpy(sAreaCode,"");
	}
	
	return 0;
}
int DealRecordStt(struct DwSusVoiticketDsStruct *pi,char sYearMonthDay[],
			struct SettItemControlDayStruct *po)
{
	static int iSettDur=0,iInFee=0,iOutFee=0;
	char sHead[16],sUser[6],sHomeAreaCode[9],sCnt[13];
	char sMsisdn[25],sVisitAreaCode[9];
	int iSettCarrID=0;
	
	strcpy(po->sStatDate,sYearMonthDay);
	
	strcpy(sHomeAreaCode,"");
	strcpy(sVisitAreaCode,"");
	strcpy(po->sCallType,"01");
	if(strcmp(pi->sRoamType,"11")==0){
		strcpy(po->sRomeType,"1");
	}else if(strcmp(pi->sRoamType,"21")==0){
		strcpy(po->sRomeType,"2");
	}else if(strcmp(pi->sRoamType,"23")==0){
		strcpy(po->sRomeType,"3");
	}else if(strcmp(pi->sRoamType,"24")==0){
		strcpy(po->sRomeType,"5");
	}else if(strcmp(pi->sRoamType,"25")==0){
		strcpy(po->sRomeType,"4");
	}else if(strcmp(pi->sRoamType,"26")==0){
		strcpy(po->sRomeType,"6");
	}else if(strcmp(pi->sRoamType,"27")==0){
		strcpy(po->sRomeType,"7");
	}else if(strcmp(pi->sRoamType,"28")==0){
		strcpy(po->sRomeType,"8");
	}else{
		return -1;
	}
	if(strcmp(pi->sDistanceType,"01")==0
		|| strcmp(pi->sDistanceType,"02")==0){
		strcpy(po->sDistanceType,"1");
	}else if(strcmp(pi->sDistanceType,"21")==0){
		strcpy(po->sDistanceType,"2");
	}else if(strcmp(pi->sDistanceType,"22")==0){
		strcpy(po->sDistanceType,"3");
	}else if(strcmp(pi->sDistanceType,"31")==0
		|| strcmp(pi->sDistanceType,"51")==0
		|| strcmp(pi->sDistanceType,"52")==0
		|| strcmp(pi->sDistanceType,"59")==0){
		strcpy(po->sDistanceType,"5");
	}else if(strcmp(pi->sDistanceType,"40")==0
		|| strcmp(pi->sDistanceType,"41")==0
		|| strcmp(pi->sDistanceType,"42")==0
		|| strcmp(pi->sDistanceType,"43")==0){
		strcpy(po->sDistanceType,"4");
	}else{
		return -1;
	}
	
	if(strncmp(pi->sCalledHomeCode,"00",2)==0){
		strncpy(po->sCalledCode,pi->sCalledHomeCode+2,4);
		po->sCalledCode[4]=0;
	}else if(strncmp(pi->sCalledHomeCode,"0",1)==0){
		strncpy(po->sCalledCode,pi->sCalledHomeCode+1,4);
		po->sCalledCode[4]=0;
	}else{
		strncpy(po->sCalledCode,pi->sCalledHomeCode,4);
		po->sCalledCode[4]=0;
	}
	
	GetFMQAreaCode(pi->sVisitAreaCode,sVisitAreaCode);
	AllTrim(sVisitAreaCode);
	if(strncmp(sVisitAreaCode,"000",3)==0){
		strncpy(po->sVisitAreaCode,sVisitAreaCode+3,4);
		po->sVisitAreaCode[4]=0;
	}else if(strncmp(sVisitAreaCode,"00",2)==0){
		strncpy(po->sVisitAreaCode,sVisitAreaCode+2,4);
		po->sVisitAreaCode[4]=0;
	}else if(strncmp(sVisitAreaCode,"0",1)==0){
		strncpy(po->sVisitAreaCode,sVisitAreaCode+1,4);
		po->sVisitAreaCode[4]=0;
	}else{
		strncpy(po->sVisitAreaCode,sVisitAreaCode,4);
		po->sVisitAreaCode[4]=0;
	}
	
	
	GetFMQAreaCode(pi->sAreaID,sHomeAreaCode);
	AllTrim(sHomeAreaCode);
	if(strncmp(sHomeAreaCode,"00",2)==0){
		strncpy(po->sHomeAreaCode,sHomeAreaCode+2,4);
		po->sHomeAreaCode[4]=0;
	}else if(strncmp(sHomeAreaCode,"0",1)==0){
		strncpy(po->sHomeAreaCode,sHomeAreaCode+1,4);
		po->sHomeAreaCode[4]=0;
	}else{
		strncpy(po->sHomeAreaCode,sHomeAreaCode,4);
		po->sHomeAreaCode[4]=0;
	}
	
	po->iCallingCarrierID=GetHeadCarredCode(pi,1);
	po->iCalledCarrierID=GetHeadCarredCode(pi,2);
	
	po->iCnt=1;
	strncpy(po->sDuration,pi->sSumDura,12);
	po->sDuration[12]=0;
	
	iSettDur=(atoi(pi->sSumDura)+59)/60*60;
	sprintf(po->sSettDuration,"%d",iSettDur);
	
	strcpy(sHead,"");
	iSettCarrID=0;
	if(strncmp(sHomeAreaCode,"0",1)==0){
		strcpy(po->sUserType,"0");
	}else{
		iSettCarrID=GetMyHeadCarr(pi->sAccNbr,"*",iSettCarrID,sHead);
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
	if(strcmp(gsStat,"N")==0){
		strcpy(po->sSettType,"5");
	}else if(strcmp(gsStat,"G")==0){
		strcpy(po->sSettType,"4");
	}
	
	strcpy(sHead,"");
	iSettCarrID=0;
	if(strncmp(pi->sCalledHomeCode,"0",1)==0 ){
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
	strcpy(po->sInFee,"0");
	strncpy(po->sOutFee,pi->sSumTollCharge,12);
	po->sOutFee[12]=0;
	
	return 0;
}
int LoadSttTicket2Bin(char sTableName[],char sYearMonthDay[],BINTREE **pptRoot)
{
	static unsigned long ulTotalCnt=0;
	int  iNodeCnt=0;
	long long llSize=0;
	float iSettDur=0,iInFee=0,iOutFee=0,iDur=0;
	char sOutFee[20];
	struct DwSusVoiticketDsStruct Temp;
	struct DwSusVoiticketDsStructIn TempIn;
	struct SettItemControlDayStruct *pTemp,*ptFound,snsTemp,*ptCur;
	
	bzero(&TempIn,sizeof(struct DwSusVoiticketDsStructIn));
	
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"where CALL_DATE='%s' and SVCID='%s'",sYearMonthDay,gsStat);

   	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	*pptRoot=NULL;

	while(EGetDwSusVoiticketDsToStruct(&Temp,&TempIn)){
		if(strcmp(Temp.sAccNbr,"")==0
			|| strncmp(Temp.sAccNbr,"0000",4)==0){
			continue;
		}
		if (++ulTotalCnt%10000==0){
			WriteProcMsg("正在加载表 %s 记录数 %lu 条",
				sTableName,ulTotalCnt);
		}
		bzero(&snsTemp,sizeof(struct SettItemControlDayStruct));
		
		if(DealRecordStt(&Temp,sYearMonthDay,&snsTemp)<0) continue;
		
		if(SearchBin(*pptRoot,&snsTemp,data_search_bintree_sett_nbr_stat,
			(void**)&ptFound)==FOUND){
			
			ptFound->iCnt+=snsTemp.iCnt;
			
			iSettDur=atof(ptFound->sSettDuration);
			iInFee=atof(ptFound->sInFee);
			iOutFee=atof(ptFound->sOutFee);
			iDur=atof(ptFound->sDuration);
			
			iSettDur+=atof(snsTemp.sSettDuration);
			iOutFee+=atof(snsTemp.sOutFee);
			iDur+=atof(snsTemp.sDuration);
			
			sprintf(ptFound->sSettDuration,"%0.0lf",floor(iSettDur));
			ptFound->sSettDuration[12]=0;
			strcpy(ptFound->sInFee,"0");
			ptFound->sInFee[12]=0;
			sprintf(sOutFee,"%0.0lf",floor(iOutFee));
			strncpy(ptFound->sOutFee,sOutFee,12);
			ptFound->sOutFee[12]=0;
			sprintf(ptFound->sDuration,"%0.0lf",floor(iDur));
			ptFound->sDuration[12]=0;
			
			iSettDur=0;
			iInFee=0;
			iOutFee=0;
			iDur=0;
				
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
				
				if(strncmp(ptCur->sHomeAreaCode,"0",1)==0){
					strcpy(ptCur->sHomeAreaCode,ptCur->sHomeAreaCode+1);
				}
				if(strncmp(ptCur->sVisitAreaCode,"0",1)==0){
					strcpy(ptCur->sVisitAreaCode,ptCur->sVisitAreaCode+1);
				}
				if(strncmp(ptCur->sCalledCode,"0",1)==0){
					strcpy(ptCur->sCalledCode,ptCur->sCalledCode+1);
				}
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
int DeleteFun(char sTableName[],char sYesMonth[])
{
	char sSqlStmt[1024];

	sprintf(sSqlStmt,"DELETE FROM %s WHERE stat_date='%s' and call_type='01'",sTableName,sYesMonth);

	if(ExecSql(sSqlStmt)<0){
		WriteAlertMsg("执行 %s 失败.",sSqlStmt);
		exit(-1);
	}

	CommitWork();	

}
int main(int argc,char *argv[])
{
	char sTableNameIn[64],sTableNameOut[64];
	char sYearMonthDay[9],sMonth[3],sYearMonth[8];
	BINTREE *ptRoot=NULL,*ptRootUpdate=NULL;
	
	if(argc!=4){
		printf("%s YearMonthDay(20120815) FeeType(FQ) Stat(G|N)\n",argv[0]);
		return -1;
	}
	strcpy(sYearMonthDay,argv[1]);
	strncpy(sMonth,sYearMonthDay+4,2);
	sMonth[2]=0;
	strncpy(sYearMonth,sYearMonthDay,6);
	sYearMonth[6]=0;
	strcpy(gsFeeType,argv[2]);
	strcpy(gsStat,argv[3]);

	sprintf(sTableNameIn,"DW_SUS_VOITICKET_DS_%s",sYearMonth);
	
	if(strcmp(gsStat,"N")==0){
		strcpy(sTableNameOut,"sett_item_control_day_fix");
	}else if(strcmp(gsStat,"G")==0){
		strcpy(sTableNameOut,"sett_item_control_day_mob");
	}
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
	
	if(LoadSttTicket2Bin(sTableNameIn,sYearMonthDay,&ptRoot)<0) return -1;
	
	gStatList=NULL;
	
	TravelBin(ptRoot,append_bintree_au_sett_stat_t);
	
/*	if(DeleteFun(sTableNameOut,sYearMonth)<0) return -1;*/
		
	if(OutputList2Table(gStatList,sTableNameOut)<0) return-1;
	
	DestroyBin(ptRoot);	
	
	DisconnectDatabase();
	
	return 0;
}

