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
#include "ticket_field.h"
#include "param_intf.h"

BINTREE *pRoot=NULL;

struct SettSumDayStruct *pSettSumDay=NULL;

int link_sett_sum_day(void **ppData)
{
	InsertList((LIST**)&pSettSumDay,(LIST*)(*ppData));
	return 0;
}
int Struct2Table(struct SettSumDayStruct *ptOut,char sTableName[])
{
	struct SettSumDayStructOut TempOut;
	struct	SettSumDayStruct *ptCur,*ptPre;
	int	iCnt=0;
	char sHostDate[15];
	
/**输出数据到统计表**/	
        bzero((void*)&TempOut,sizeof(struct SettSumDayStructOut));

        strcpy(TempOut.sTableName,sTableName);
	
	GetHostTime(sHostDate);
	
  	ptCur=ptOut;
	iCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		strcpy(ptPre->sDealDate,sHostDate);
		
		if(EInsertStructToSettSumDay(ptPre,false,&TempOut)<0){
			printf("输出数据错误SETT_SUM_DAY.\n");
			WriteErrStackAlert();
			return -1;
		}
		iCnt++;
		
	}
	if(EInsertStructToSettSumDay(NULL,true,&TempOut)<0){
		printf("输出数据错误SETT_SUM_DAY.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("汇总正确输出记录数%d",iCnt);

	return 0;

}
	
	
int data_search_bintree_sett_sum_day_e(void *pValue,void*pData)
{
	struct SettSumDayStruct *pSource=(struct SettSumDayStruct *)pValue;
	struct SettSumDayStruct *pTarget=(struct SettSumDayStruct *)pData;
	int res;
	
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;

	if((res=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return res;
	if((res=strcmp(pSource->sStatMonth,pTarget->sStatMonth))!=0) return res;
	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
	if((res=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return res;
	if((res=strcmp(pSource->sStartDate,pTarget->sStartDate))!=0) return res;
	
	if((res=pSource->iCallingCarrierID-pTarget->iCallingCarrierID)!=0) return res;
	if((res=pSource->iCalledCarrierID-pTarget->iCalledCarrierID)!=0) return res;
	if((res=pSource->iThirdCarrierID-pTarget->iThirdCarrierID)!=0) return res;

	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	if((res=strcmp(pSource->sIpAccNbr,pTarget->sIpAccNbr))!=0) return res;

	return 0;
}
void assign_insert_bintree_sett_sum_day_e(void **ppData,void *pData)
{

	struct SettSumDayStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SettSumDayStruct));
		ERROR_EXIT(pTemp==NULL,"分配SettSumDayStruct结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SettSumDayStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	pTemp->iDurationCnt+=((struct SettSumDayStruct*)pData)->iDurationCnt;
	pTemp->iDuration+=((struct SettSumDayStruct*)pData)->iDuration;
	pTemp->iSettCnt+=((struct SettSumDayStruct*)pData)->iSettCnt;
	pTemp->iTotalFee+=((struct SettSumDayStruct*)pData)->iTotalFee;
	pTemp->iCount+=((struct SettSumDayStruct*)pData)->iCount;
}
int GetIpAccNbr(char sAccNbr[],char sIpAccNbr[])
{
	
	if(strncmp(sAccNbr,"068",3)==0){strcpy(sIpAccNbr,"068");}
	else if(strncmp(sAccNbr,"190",3)==0){strcpy(sIpAccNbr,"190");}
	else if(strncmp(sAccNbr,"193",3)==0){strcpy(sIpAccNbr,"193");}
	else if(strncmp(sAccNbr,"194",3)==0){strcpy(sIpAccNbr,"194");}
	else if(strncmp(sAccNbr,"195",3)==0){strcpy(sIpAccNbr,"195");}
	else if(strncmp(sAccNbr,"196300",6)==0){strcpy(sIpAccNbr,"196300");}
	else if(strncmp(sAccNbr,"196",3)==0){strcpy(sIpAccNbr,"196");}
	else if(strncmp(sAccNbr,"197",3)==0){strcpy(sIpAccNbr,"197");}
	else if(strncmp(sAccNbr,"200",3)==0){strcpy(sIpAccNbr,"200");}
	else if(strncmp(sAccNbr,"201",3)==0){strcpy(sIpAccNbr,"201");}
	else if(strncmp(sAccNbr,"300",3)==0){strcpy(sIpAccNbr,"300");}
	else if(strncmp(sAccNbr,"179",3)==0){
		strncpy(sIpAccNbr,sAccNbr,5);
		sIpAccNbr[5]=0;
	}
	else if(strncmp(sAccNbr,"000196",6)==0){strcpy(sIpAccNbr,"196");}
	else if(strncmp(sAccNbr,"000190",6)==0){strcpy(sIpAccNbr,"190");}
	else if(strncmp(sAccNbr,"000179",6)==0){
		strncpy(sIpAccNbr+3,sAccNbr,5);
		sIpAccNbr[5]=0;
	}
	else if(strncmp(sAccNbr,"0196",4)==0){strcpy(sIpAccNbr,"196");}
	else if(strncmp(sAccNbr,"00196",5)==0){strcpy(sIpAccNbr,"196");}
	else strcpy(sIpAccNbr,"");

	return 0;
}

int mvitem_stt2settsumday(struct SttTicketStruct *pi,
	struct SettSumDayStruct *po)
{
	int i=0;
	int iCarrierID=0;
	char sRawNbr[16],sSecPerCnt[6];
	
	bzero((void*)po,sizeof(struct SettSumDayStruct));
		
		po->iTicketTypeID=		pi->iTicketTypeID;

		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sStatMonth,		pi->sStartTime,6);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sStartDate,		pi->sStartTime,8);
		
		po->iCallingCarrierID=		pi->iCallingCarrierID;
		po->iCalledCarrierID=		pi->iCalledCarrierID;
		
		GetRawNbr(pi->sThirdParty,
			pi->sCalledCode,pi->sStartTime,sRawNbr);
		GetHeadCarr(pi->sThirdParty,sRawNbr,
			pi->sCalledCode,pi->sStartTime,&iCarrierID);
		
		po->iThirdCarrierID=	iCarrierID;
		
		strncpy(po->sUserType,		pi->sUserType,1);


		GetIpAccNbr(pi->sOtherParty,po->sIpAccNbr);
		

		po->iDurationCnt=		1;
		po->iDuration=			pi->iDuration;

		GetBinStr("TICKET_TARIFF",pi->iTicketTypeID,"",pi->sStartTime,sSecPerCnt);
		i=atoi(sSecPerCnt);
		if(i<=0)i=60;
		po->iSettCnt=(pi->iDuration+i-1)/i;

		po->iTotalFee=0;
		
		if(pi->iTollFee!=0&&
			pi->iTollFee>(pi->iAddFee+pi->iRoamFee))
			po->iTotalFee=0-(pi->iTollFee-pi->iRoamFee-pi->iAddFee);
		else if(pi->iAddFee!=0&&
			(pi->iAddFee+pi->iRoamFee)>pi->iTollFee)
			po->iTotalFee=(pi->iAddFee+pi->iRoamFee-pi->iTollFee);

		po->iCount=			1;
		
		po->sStatMonth[6]=0;
		po->sHomeAreaCode[5]=0;
		po->sCalledCode[5]=0;
		po->sStartDate[8]=0;
	return 0;
		
}

int main(int argc, char **argv)
{
	int	iCnt=0,t1=0;
	char sStatTableName[30],sTableName[31],sCondition[128];
	char sStatDate[15],sChkDate[15],sDateTemp[15];
	
	static int iFirstFlag=true;
	static struct SttTicketStruct Temp;
	static struct SttTicketStructIn TempIn;
	
	struct SettSumDayStruct TempOut;
	
	if(argc!=4&&argc!=5){
		printf("Usage %s tablename statdate stattablename [wherecause].\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sTableName,argv[1]);
	Upper(sTableName);
	strcpy(sDateTemp,argv[2]);
	Upper(sDateTemp);
	sDateTemp[8]=0;
				
	strcpy(sStatTableName,argv[3]);
        Upper(sStatTableName);
        
        strcpy(sCondition,"");
        if(argc==5){
        	strcpy(sCondition,argv[4]);
        	Upper(sCondition);
        }

/*取前一天日期*/
        strcpy(sStatDate,sDateTemp);
        strcat(sStatDate,"000000");
        strcpy(sChkDate,sStatDate);
        if((t1=tGetTime(sStatDate))<0) return -1;
        if(AddTimes(sStatDate,-86400)<0) return -1;
        /* strncpy(sStatDate,sChkDate,8);
        sStatDate[8]=0;*/
/*初始化批价参数*/
	MoveAllShmToMem();
        
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;
	
	if(strlen(sCondition)==0)
		sprintf(sCondition,
			" WHERE TICKET_TYPE_ID>0 AND START_TIME>='%s' and START_TIME<'%s' ",sStatDate,sChkDate);

	
/*		sprintf(sCondition,
			" WHERE SUBSTR(START_TIME,1,8)='%s' ",sStatDate);
*/
	
	if(iFirstFlag==true){
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,sTableName);
		strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}
	while(EGetSttTicketToStruct(&Temp,&TempIn)){

		mvitem_stt2settsumday(&Temp,&TempOut);

		if(InsertBin(&pRoot,(void *)&TempOut,
			data_search_bintree_sett_sum_day_e,
			assign_insert_bintree_sett_sum_day_e)<0){
			WriteAlertMsg("生成BINTREE失败sett_sum_day");
			return -1;
		}
		if((++iCnt%30000)==0)
			WriteProcMsg("表%s当前统计记录数为%d",sTableName,iCnt);
	}
	WriteProcMsg("表%s统计完毕,记录数为%d",sTableName,iCnt);

/*将帐目挂到pSettSumDay中*/
	TravelBin(pRoot,link_sett_sum_day);
	
/**输出数据到统计表**/
	if(Struct2Table(pSettSumDay,sStatTableName)<0){
		WriteAlertMsg("输出数据到统计表出错.\n");
		return -1;
	};

/*释放批价参数*/
	DistroyAllMem();
	
	CommitWork();
	DestroyBin(pRoot);
	DisconnectDatabase();
	
	return 0;
}
