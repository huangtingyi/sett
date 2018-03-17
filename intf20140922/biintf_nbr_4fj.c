#include <stdio.h>	
#include <stdlib.h>     
#include <wwdb.h>       
#include <wwlog.h>      
#include <wwtiny.h>
#include <wwsupp.h>
#include <wwdir.h>     
#include <bintree.h>    
#include <list.h>   
#include <wwfile.h>     
#include <stt_ticket.h>
#include "param_intf.h"
#include "wwshm.h"
#include "ticket_field.h"
#include "sett_nbr_supp.h"
#include "biintf_nbr_supp.h"


BINTREE *pRoot=NULL;
BINTREE *pRootchk=NULL;

FILE *fp=NULL;

double iTotalCnt,iTotalDuration,iTotalFeeDuration,iTotalInFee,iTotalOutFee;
int iOutTotalCnt;
char sChkTableName[64];

int IsInSTT(char sInType[]);
int IsInSTP(char sInType[]);
int IsInVIT(char sInType[]);
int IsInTLL(char sInType[]);
int IsInTLP(char sInType[]);
int IsInSMS(char sInType[]);
int IsInSCX(char sInType[]);

int InitVisualFunc(char sFileType[]);

int DealSettNbrStat(char sTableName[],char sCondition[],char sModule[],
	char sRoamDirection[],char msg[]);
	
int XDealSettNbr2Bin(struct SettNbrIntfFjbiStruct *p,char msg[]);

int (*XDealSettNbr)(char sSouTableName[],char sCondition[],char sModule[],
char sRoamDirection[],char msg[]);
int (*XDealRecord2intf)(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[]);

int GenTableName(char sModule[],char sStatMonth[],char sTableName[]);
int GenFileName(char sOutputDir[],char sModule[],char sStatPeriod[],
	char sOppCarrier[],char sAreaCode[],char sRoamDirection[],char sOutputFile[]);
int GenSQLCondition(char sModule[],char sOppCarrier[],char sAreaCode[],
	char sRoamDirection[],char sCondition[]);
	
	
int GenOutAccNbr(char sAccNbr[],char sHomeAreaCode[],char sReserve1[],
	char sReserve2[],char sOutAccNbr[]);

int STT_DealRecord2intf(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[])
{
	int iFEEDuration,iDuration,iHomeCarrID;
	char sNbrRelation[2];
	char sCallDirection[2],sOutAccNbr[25],sHostTime[15];
	
	/*获取结算号码*/
	GenOutAccNbr(pi->sAccNbr,pi->sHomeAreaCode,pi->sReserve1,
		pi->sReserve2,sOutAccNbr);

	/*获取呼叫方向*/
	strncpy(sCallDirection,pi->sReserve2,1);sCallDirection[1]=0;

	
	/*获取通话时长、结算时长*/
	if(IsInSCX(sModule) || IsInSMS(sModule)){
		iDuration=0;
		iFEEDuration=0;
	}
	else{
		iDuration=pi->iDuration;
		iFEEDuration=pi->iSettMin;
	}

	strcpy(po->sBillingCycleID,	pi->sBillingCycleID);
	sprintf(po->sVisitAreaCode,"0%s",pi->sVisitAreaCode);
	strcpy(po->sAccNbr,		sOutAccNbr);
	strcpy(po->sRoamAreaCode,	"");
	
	GetHostTime(sHostTime);
	
	GetHeadCarr(sOutAccNbr,pi->sAccNbr,pi->sHomeAreaCode,sHostTime,&iHomeCarrID);

	if(pi->iTicketTypeID==3711||
		pi->iTicketTypeID==3718||
		pi->iTicketTypeID==3713||
		pi->iTicketTypeID==3717){
	
		if(pi->iOppCarrID==3&&
			iHomeCarrID==3)pi->iTicketTypeID=3711;
		else if(pi->iOppCarrID!=3&&
			iHomeCarrID!=3)pi->iTicketTypeID=3718;
		else if(pi->iOppCarrID!=3&&
			iHomeCarrID==3)pi->iTicketTypeID=3713;
		else if(pi->iOppCarrID==3&&
			iHomeCarrID!=3)pi->iTicketTypeID=3717;
	}
	/*重置外省号码:区号+1位运营商+00000*/
	if(strncmp(pi->sHomeAreaCode,"59",2)!=0)
		sprintf(po->sAccNbr,"0%s%d00000",pi->sHomeAreaCode,iHomeCarrID);
		
	
	if(atoi(sCallDirection)==1){
		sprintf(po->sHomeAreaCode,"0%s",pi->sHomeAreaCode);
		sprintf(po->sOppAreaCode,"0%s",pi->sOppArea);		
		po->iHomeCarrID   =		iHomeCarrID;
		po->iOppCarrID   =		pi->iOppCarrID;
	}
	else{
		sprintf(po->sHomeAreaCode,"0%s",pi->sOppArea);
		sprintf(po->sOppAreaCode,"0%s",pi->sHomeAreaCode);		
		po->iHomeCarrID   =		pi->iOppCarrID;
		po->iOppCarrID   =		iHomeCarrID;	
	}
	
	po->iCallDirection=		atoi(sCallDirection);
	po->iTicketTypeID=		pi->iTicketTypeID;
	po->iCnt	 =		pi->iCnt;
	po->iDuration	 =		iDuration;
	po->iFeeDuration =		iFEEDuration;
	
	po->iInFee=atoi(pi->sInFee);
	po->iOutFee=atoi(pi->sOutFee);
	
	strcpy(po->sServiceType,	pi->sServiceType);
	
	if(strcmp(pi->sNbrType,"CUW")==0)strcpy(po->sNbrType,"3G");
	else if(strcmp(pi->sNbrType,"PSTN")==0)strcpy(po->sNbrType,"PSTN");
	else strcpy(po->sNbrType,"2G");

	if(strcmp(pi->sOppNbrType,"CMT")==0)strcpy(po->sOppNbrType,"TD");
	else if(strcmp(pi->sOppNbrType,"CTC")==0)strcpy(po->sOppNbrType,"CDMA");
	else if(strcmp(pi->sOppNbrType,"CMM")==0)strcpy(po->sOppNbrType,"2G");
	else if(strcmp(pi->sOppNbrType,"CUG")==0)strcpy(po->sOppNbrType,"2G");
	else strcpy(po->sOppNbrType,"PSTN");


	if(po->iInFee==0&&po->iOutFee>0)po->iSettFlag=2;
	else if(po->iInFee>0&&po->iOutFee==0)po->iSettFlag=1;
	else po->iSettFlag=0;	
	
	if(po->iTicketTypeID==3713)po->iSettFlag=1;
	if(po->iTicketTypeID==881||
		po->iTicketTypeID==882)po->iSettFlag=2;

	if(po->iSettFlag==0){
		po->iInFee=0;po->iOutFee=0;
	}
	
	strcpy(po->sReserve1,		"");
	strcpy(po->sReserve2,		"");
	
	/*对网间结算区分出港澳台和国际*/
	if(IsInSTT(sModule) || IsInSTP(sModule)){
		int iTollType=0;
		char sStateX[1];
		GetBinInt("FJBI_TICKET_TYPE",po->iTicketTypeID,sModule,sHostTime,&iTollType);
		GetBinStr("FJBI_TICKET_TYPE",po->iTicketTypeID,sModule,sHostTime,sStateX);
		
		if(iTollType==3){
			if(strcmp(sStateX,"H")==0){
				if(strcmp(po->sHomeAreaCode,"00886")==0||
					strcmp(po->sHomeAreaCode,"00853")==0||
					strcmp(po->sHomeAreaCode,"00852")==0||
					strncmp(po->sHomeAreaCode,"00",2)==0)
					po->iTicketTypeID=po->iTicketTypeID+60;
			}
			else if(strcmp(sStateX,"O")==0){
				if(strcmp(po->sOppAreaCode,"00886")==0||
					strcmp(po->sOppAreaCode,"00853")==0||
					strcmp(po->sOppAreaCode,"00852")==0||
					strncmp(po->sOppAreaCode,"00",2)==0)
					po->iTicketTypeID=po->iTicketTypeID+60;				
			}
			
		}
		
	}
	
	return 0;
}
int VIT_DealRecord2intf(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[])
{
	int iFEEDuration,iDuration,iHomeCarrID;
	char sNbrRelation[2];
	char sCallDirection[2],sOutAccNbr[25],sHostTime[15];

	/*获取呼叫方向*/
	strncpy(sCallDirection,pi->sReserve2,1);sCallDirection[1]=0;
	
	iDuration=pi->iDuration;
	iFEEDuration=pi->iSettMin;

	strcpy(po->sBillingCycleID,	pi->sBillingCycleID);
	
	strcpy(po->sAccNbr,		pi->sAccNbr);

	if(pi->iTicketTypeID==9312||
		pi->iTicketTypeID==9322||
		pi->iTicketTypeID==9332){
		sprintf(po->sVisitAreaCode,"0%s",pi->sHomeAreaCode);
	}
	else{
		sprintf(po->sVisitAreaCode,"0%s",pi->sVisitAreaCode);
	}
	
	sprintf(po->sRoamAreaCode,"0%s",pi->sVisitAreaCode);

	GetHostTime(sHostTime);
	
	GetHeadCarr(pi->sAccNbr,pi->sAccNbr,pi->sHomeAreaCode,sHostTime,&iHomeCarrID);

	/*重置外省号码:区号+1位运营商+00000*/
	if(strncmp(pi->sHomeAreaCode,"59",2)!=0)
		sprintf(po->sAccNbr,"0%s%d00000",pi->sHomeAreaCode,iHomeCarrID);


	sprintf(po->sHomeAreaCode,"0%s",pi->sHomeAreaCode);
	sprintf(po->sOppAreaCode,"0%s",pi->sOppArea);		
	po->iHomeCarrID   =		iHomeCarrID;
	po->iOppCarrID   =		pi->iOppCarrID;
	

	po->iCallDirection=		atoi(sCallDirection);
	po->iTicketTypeID=		pi->iTicketTypeID;
	po->iCnt	 =		pi->iCnt;
	po->iDuration	 =		iDuration;
	po->iFeeDuration =		iFEEDuration;
	
	po->iInFee=atoi(pi->sInFee);
	po->iOutFee=atoi(pi->sOutFee);
		
	strcpy(po->sServiceType,	pi->sServiceType);

	if(strcmp(pi->sNbrType,"CUW")==0)strcpy(po->sNbrType,"3G");
	else if(strcmp(pi->sNbrType,"PSTN")==0)strcpy(po->sNbrType,"PSTN");
	else strcpy(po->sNbrType,"2G");

	if(strcmp(pi->sOppNbrType,"CMT")==0)strcpy(po->sOppNbrType,"TD");
	else if(strcmp(pi->sOppNbrType,"CTC")==0)strcpy(po->sOppNbrType,"CDMA");
	else if(strcmp(pi->sOppNbrType,"CMM")==0)strcpy(po->sOppNbrType,"2G");
	else if(strcmp(pi->sOppNbrType,"CUG")==0)strcpy(po->sOppNbrType,"2G");
	else strcpy(po->sOppNbrType,"PSTN");


	if(po->iInFee==0&&po->iOutFee>0)po->iSettFlag=2;
	else if(po->iInFee>0&&po->iOutFee==0)po->iSettFlag=1;
	else po->iSettFlag=0;
	
	if(pi->iTicketTypeID==9312)
		strcpy(po->sReserve1,		"6");
	else if(pi->iTicketTypeID==9312)
		strcpy(po->sReserve1,		"3");
	else if(pi->iTicketTypeID==9321)
		strcpy(po->sReserve1,		"8");
	else if(pi->iTicketTypeID==9322)
		strcpy(po->sReserve1,		"5");
	else 	strcpy(po->sReserve1,		"3");
	
	strcpy(po->sReserve2,		"");
	
	return 0;
}
int TLL_DealRecord2intf(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[])
{
	STT_DealRecord2intf(sModule,pi,po,msg);
	
	strcpy(po->sServiceType,"TLL");
	
	return 0;
}
int STP_DealRecord2intf(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[])
{
	STT_DealRecord2intf(sModule,pi,po,msg);
	strcpy(po->sServiceType,"STP");
	
	return 0;
}
int TLP_DealRecord2intf(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[])
{
	STT_DealRecord2intf(sModule,pi,po,msg);
	strcpy(po->sServiceType,"TLP");
	return 0;
}

int SCX_DealRecord2intf(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[])
{
	int iFEEDuration,iDuration,iHomeCarrID;
	char sNbrRelation[2];
	char sCallDirection[2],sOutAccNbr[25],sHostTime[15];


	/*获取呼叫方向*/
	if(strncmp(pi->sReserve2,"7",1)==0)
		strcpy(sCallDirection,"1");
	else 	strcpy(sCallDirection,"2");
	
	iDuration=0;
	iFEEDuration=0;

	strcpy(po->sBillingCycleID,	pi->sBillingCycleID);

	strcpy(po->sAccNbr,		pi->sAccNbr);
	
	sprintf(po->sVisitAreaCode,"0%s",pi->sVisitAreaCode);
	strcpy(po->sRoamAreaCode,	"");
	
	GetHostTime(sHostTime);
	
	GetHeadCarr(pi->sAccNbr,pi->sAccNbr,pi->sHomeAreaCode,sHostTime,&iHomeCarrID);

	/*重置外省号码:区号+1位运营商+00000*/
	if(strncmp(pi->sHomeAreaCode,"59",2)!=0)
		sprintf(po->sAccNbr,"0%s%d00000",pi->sHomeAreaCode,iHomeCarrID);

	if(atoi(sCallDirection)==1){
		sprintf(po->sHomeAreaCode,"0%s",pi->sHomeAreaCode);
		sprintf(po->sOppAreaCode,"0%s",pi->sOppArea);		
		po->iHomeCarrID   =		iHomeCarrID;
		po->iOppCarrID   =		pi->iOppCarrID;
	}
	else{
		sprintf(po->sHomeAreaCode,"0%s",pi->sOppArea);
		sprintf(po->sOppAreaCode,"0%s",pi->sHomeAreaCode);		
		po->iHomeCarrID   =		pi->iOppCarrID;
		po->iOppCarrID   =		iHomeCarrID;	
	}	
	
	po->iCallDirection=		atoi(sCallDirection);
	po->iTicketTypeID=		pi->iTicketTypeID;
	po->iCnt	 =		pi->iCnt;
	po->iDuration	 =		iDuration;
	po->iFeeDuration =		iFEEDuration;
	
	po->iInFee=atoi(pi->sInFee);
	po->iOutFee=atoi(pi->sOutFee);
	
	strcpy(po->sServiceType,	pi->sServiceType);

	if(strcmp(pi->sNbrType,"CUW")==0)strcpy(po->sNbrType,"3G");
	else if(strcmp(pi->sNbrType,"PSTN")==0)strcpy(po->sNbrType,"PSTN");
	else strcpy(po->sNbrType,"2G");

	if(strcmp(pi->sOppNbrType,"CMT")==0)strcpy(po->sOppNbrType,"TD");
	else if(strcmp(pi->sOppNbrType,"CTC")==0)strcpy(po->sOppNbrType,"CDMA");
	else if(strcmp(pi->sOppNbrType,"CMM")==0)strcpy(po->sOppNbrType,"2G");
	else if(strcmp(pi->sOppNbrType,"CUG")==0)strcpy(po->sOppNbrType,"2G");
	else strcpy(po->sOppNbrType,"PSTN");

	
	if(po->iInFee==0&&po->iOutFee>0)po->iSettFlag=2;
	else if(po->iInFee>0&&po->iOutFee==0)po->iSettFlag=1;
	else po->iSettFlag=0;
	
	strcpy(po->sReserve1,		"");
	strcpy(po->sReserve2,		"");
	
	return 0;
}
int SMS_DealRecord2intf(char sModule[],struct SettNbrStatStruct *pi,
	struct SettNbrIntfFjbiStruct *po,char msg[])
{
	SCX_DealRecord2intf(sModule,pi,po,msg);
	strcpy(po->sServiceType,	"SMS");
	
	return 0;
}
int data_search_bintree_f_sett_nbr_e(void *pValue,void*pData)
{
	struct SettNbrIntfFjbiStruct *pSource=(struct SettNbrIntfFjbiStruct *)pValue;
	struct SettNbrIntfFjbiStruct *pTarget=(struct SettNbrIntfFjbiStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sBillingCycleID,	pTarget->sBillingCycleID))!=0) return res;
	if((res=strcmp(pSource->sVisitAreaCode,		pTarget->sVisitAreaCode))!=0) return res;
	if((res=strcmp(pSource->sAccNbr,		pTarget->sAccNbr))!=0) return res;
	if((res=strcmp(pSource->sHomeAreaCode,		pTarget->sHomeAreaCode))!=0) return res;
	if((res=strcmp(pSource->sOppAreaCode,		pTarget->sOppAreaCode))!=0) return res;
	if((res=strcmp(pSource->sRoamAreaCode,		pTarget->sRoamAreaCode))!=0) return res;
	
	if((res=pSource->iHomeCarrID	-	pTarget->iHomeCarrID)!=0) return res;
	if((res=pSource->iOppCarrID	-	pTarget->iOppCarrID)!=0) return res;
	if((res=pSource->iCallDirection	-	pTarget->iCallDirection)!=0) return res;
	if((res=pSource->iTicketTypeID	-	pTarget->iTicketTypeID)!=0) return res;
		
		
	if((res=strcmp(pSource->sServiceType,		pTarget->sServiceType))!=0) return res;
	if((res=strcmp(pSource->sNbrType,		pTarget->sNbrType))!=0) return res;
	if((res=strcmp(pSource->sOppNbrType,		pTarget->sOppNbrType))!=0) return res;
	
	if((res=pSource->iSettFlag	-	pTarget->iSettFlag)!=0) return res;
	
	if((res=strcmp(pSource->sReserve1,		pTarget->sReserve1))!=0) return res;
	if((res=strcmp(pSource->sReserve2,		pTarget->sReserve2))!=0) return res;
	if((res=strcmp(pSource->sDealDate,		pTarget->sDealDate))!=0) return res;
		
	return 0;
}
void insert_bintree_f_sett_nbr_e(void **ppData,void *pData)
{
       int iInFee=0,iOutFee=0;

        struct SettNbrIntfFjbiStruct *pTemp;
        if((pTemp=(*ppData))==NULL){
                pTemp=malloc(sizeof(struct SettNbrIntfFjbiStruct));
                ERROR_EXIT(pTemp==NULL,"分配SettNbrIntfFjbiStruct结构错误");
                memcpy((void*)pTemp,pData,sizeof(struct SettNbrIntfFjbiStruct));
                pTemp->pNext=NULL;
                *ppData=(void*)pTemp;
                return;
        }
	pTemp->iCnt+=((struct SettNbrIntfFjbiStruct*)pData)->iCnt;
	pTemp->iDuration+=((struct SettNbrIntfFjbiStruct*)pData)->iDuration;
	pTemp->iFeeDuration+=((struct SettNbrIntfFjbiStruct*)pData)->iFeeDuration;
	pTemp->iInFee+=((struct SettNbrIntfFjbiStruct*)pData)->iInFee;
	pTemp->iOutFee+=((struct SettNbrIntfFjbiStruct*)pData)->iOutFee;
	
}

int XDealSettNbr2Bin(struct SettNbrIntfFjbiStruct *p,char msg[])
{

	struct 	SettNbrIntfFjbiStruct	Temp;
	
	mvitem_settnbrintffjbi(p,&Temp);
	
	if(InsertBin(&pRoot,(void *)&Temp,
		data_search_bintree_f_sett_nbr_e,
		insert_bintree_f_sett_nbr_e)<0){
		WriteAlertMsg("加载数据到内存树失败");
		return -1;
	}
			
	return 0;
		
}
int XDealSettNbrBin2File(void **ppTemp)
{
	int l=0;
	char sRecord[1024];
	struct SettNbrIntfFjbiStruct *p=(struct SettNbrIntfFjbiStruct *)*ppTemp;
	struct SettNbrIntfFjbiStruct	Temp;
	
	while(p!=NULL){
		l=0;
		memset(sRecord,0,sizeof(sRecord));	
		bzero((void*)&Temp,sizeof(struct SettNbrIntfFjbiStruct));
		
		iTotalCnt+=p->iCnt*1.0/10000.0;
		iTotalDuration+=p->iDuration*1.0/10000.0;
		iTotalFeeDuration+=p->iFeeDuration*1.0/10000.0;
		iTotalInFee+=p->iInFee*1.0/10000.0;
		iTotalOutFee+=p->iOutFee*1.0/10000.0;
		
		if(strcmp(p->sServiceType,"VIT")==0&&
			strcmp(p->sRoamAreaCode,"")==0)
			strcpy(p->sRoamAreaCode,p->sVisitAreaCode);

/*增加去掉号码后的统计数据，插到 pRootchk 树中*/
		mvitem_settnbrintffjbi(p,&Temp);
		strcpy(Temp.sAccNbr,"ALL");

		if(InsertBin(&pRootchk,(void *)&Temp,
			data_search_bintree_f_sett_nbr_e,
			insert_bintree_f_sett_nbr_e)<0){
			WriteAlertMsg("加载数据到内存树失败");
			return -1;
		}		
		
		l+=sprintf(sRecord+l,"|%s|"	,p->sBillingCycleID);
		l+=sprintf(sRecord+l,"%s|"	,p->sVisitAreaCode);
		l+=sprintf(sRecord+l,"%s|"	,p->sAccNbr);
		l+=sprintf(sRecord+l,"%s|"	,p->sHomeAreaCode);
		l+=sprintf(sRecord+l,"%s|"	,p->sOppAreaCode);
		l+=sprintf(sRecord+l,"%s|"	,p->sRoamAreaCode);
		l+=sprintf(sRecord+l,"%d|"	,p->iHomeCarrID);
		l+=sprintf(sRecord+l,"%d|"	,p->iOppCarrID);
		l+=sprintf(sRecord+l,"%d|"	,p->iCallDirection);
		l+=sprintf(sRecord+l,"%d|"	,p->iTicketTypeID);		
		l+=sprintf(sRecord+l,"%d|"	,p->iInFee);
		l+=sprintf(sRecord+l,"%d|"	,p->iOutFee);
		l+=sprintf(sRecord+l,"%d|"	,p->iFeeDuration);
		l+=sprintf(sRecord+l,"%d|"	,p->iDuration);
		l+=sprintf(sRecord+l,"%d|"	,p->iCnt);
		l+=sprintf(sRecord+l,"%s|"	,p->sServiceType);
		l+=sprintf(sRecord+l,"%s|"	,p->sNbrType);
		l+=sprintf(sRecord+l,"%s|"	,p->sOppNbrType);
		l+=sprintf(sRecord+l,"%d|"	,p->iSettFlag);
		l+=sprintf(sRecord+l,"%s|"	,p->sReserve1);
		l+=sprintf(sRecord+l,"%s|\r\n"	,p->sReserve2);
		
		WriteFile(fp,sRecord,l);
		p=p->pNext;
	}
	return 0;	
}


int InsertSettNbrIntfFjbi(struct SettNbrIntfFjbiStruct *p,int iInsertFlag)
{
        static int iFirstFlag=TRUE;
        static struct SettNbrIntfFjbiStructOut TempOut;
        if(iFirstFlag==TRUE){
                iFirstFlag=FALSE;
                bzero((void*)&TempOut,sizeof(struct SettNbrIntfFjbiStructOut));
                strcpy(TempOut.sTableName,sChkTableName);
        }
        return EInsertStructToSettNbrIntfFjbi(p,iInsertFlag,&TempOut);
}
int ChkSett2Table(void **ppData)
{
	
	struct SettNbrIntfFjbiStruct *ptHead,*pTemp;
	struct SettNbrIntfFjbiStruct	pout;

	ptHead=(struct SettNbrIntfFjbiStruct*)*ppData;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_settnbrintffjbi(pTemp,&pout);
		
		GetHostTime(pout.sDealDate);

		iOutTotalCnt++;
		if(InsertSettNbrIntfFjbi(&pout,FALSE)<0)return -1;

		if(iOutTotalCnt%30000==0){
			if(InsertSettNbrIntfFjbi(NULL,TRUE)<0){
				return -1;
			}
	                WriteProcMsg("当前处理记录数%d,输出到表%s",
	                	iTotalCnt,sChkTableName);
		}		
	}
	
	return 0;
}
int DeleteTable(char sTableName[],char sCondition[])
{
	int iRet,l=0;
	char sCommand[1024];
	
	sprintf(sCommand,"DELETE %s %s ",sTableName,sCondition);

	Upper(sCommand);
	ExecSql(sCommand);
		
	return 0;
}

int XChkSett2Table(char sStatMonth[],char sModule[])
{
/*清理稽核表相应的数据*/
	char sCondition[256];
	
	sprintf(sCondition,
		"WHERE BILLING_CYCLE_ID='%s' AND SERVICE_TYPE='%s' ",
		sStatMonth,sModule);
	
	if(TableExist(sChkTableName)==true){
                if(DeleteTable(sChkTableName,sCondition)<0)return -1;
        }
        	
	
/*输出数据到稽核表*/
	TravelBin(pRoot,ChkSett2Table);
		
        if(InsertSettNbrIntfFjbi(NULL,TRUE)<0)return -1;

	WriteProcMsg("当前处理记录数%d,输出到表%s",
		iOutTotalCnt,sChkTableName);
	
	return 0;
}
int IsInSTT(char sInType[])
{
	if(strcmp(sInType,"STT")==0) return true;
	return false;
}
int IsInSTP(char sInType[])
{
	if(strcmp(sInType,"STP")==0) return true;
	return false;
}
int IsInVIT(char sInType[])
{
	if(strcmp(sInType,"VIT")==0) return true;
	return false;
}
int IsInTLL(char sInType[])
{
	if(strcmp(sInType,"TLL")==0) return true;
	return false;
}
int IsInTLP(char sInType[])
{
	if(strcmp(sInType,"TLP")==0) return true;
	return false;
}
int IsInSMS(char sInType[])
{
	if(strcmp(sInType,"SMS")==0) return true;
	return false;
}
int IsInSCX(char sInType[])
{
	if(strcmp(sInType,"SCX")==0) return true;
	return false;
}
int InitVisualFunc(char sFileType[])
{
	if(IsInSTT(sFileType)){
		XDealSettNbr=DealSettNbrStat;
		XDealRecord2intf=STT_DealRecord2intf;
	}
	else if(IsInVIT(sFileType)){
		XDealSettNbr=DealSettNbrStat;
		XDealRecord2intf=VIT_DealRecord2intf;		
	}
	else if(IsInTLL(sFileType)){
		XDealSettNbr=DealSettNbrStat;
		XDealRecord2intf=TLL_DealRecord2intf;
		
	}
	else if(IsInSTP(sFileType)){
		XDealSettNbr=DealSettNbrStat;
		XDealRecord2intf=STP_DealRecord2intf;
		
	}
	else if(IsInTLP(sFileType)){
		XDealSettNbr=DealSettNbrStat;
		XDealRecord2intf=TLP_DealRecord2intf;
		
	}
	else if(IsInSCX(sFileType)){
		XDealSettNbr=DealSettNbrStat;
		XDealRecord2intf=SCX_DealRecord2intf;
		
	}
	else{
		printf("为找到 %s 的业务类型.",sFileType);
		return -1;	
	}
	return 0;
}

        
void DealAreaCode(char sAreaCode[])
{
	int l=0;
	char sStr[2];
	l=strlen(sAreaCode)-1;
	strncpy(sStr,sAreaCode+l,1);sStr[1]=0;
        if(strcmp(sStr,"c")==0||
        	strcmp(sStr,"w")==0||
        	strcmp(sStr,"q")==0||
        	strcmp(sStr,"y")==0||
        	strcmp(sStr,"A")==0||
        	strcmp(sStr,"B")==0||
        	strcmp(sStr,"C")==0)sAreaCode[l]=0;

}

        
int DealSettNbrStat(char sTableName[],char sCondition[],char sModule[],char sRoamDirection[],char msg[])
{
	int iCnt=0;
	struct SettNbrStatStruct Temp;
        struct SettNbrStatStructIn TempIn;
        struct SettNbrIntfFjbiStruct TempOut;
        
        bzero((void*)&TempIn,sizeof(struct SettNbrStatStructIn));
        strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;
        
	while(EGetSettNbrStatToStruct(&Temp,&TempIn)){
		
		bzero((void*)&TempOut,sizeof(struct SettNbrIntfFjbiStruct));
		
		DealAreaCode(Temp.sHomeAreaCode);
		DealAreaCode(Temp.sOppArea);
		DealAreaCode(Temp.sVisitAreaCode);

		if(XDealRecord2intf(sModule,&Temp,&TempOut,msg)<0) return -1;
				
		if(XDealSettNbr2Bin(&TempOut,msg)<0)return -1;

			if((++iCnt%30000)==0)
			WriteProcMsg("表%s当前统计记录数为%d",sTableName,iCnt);		
	}
	
	WriteProcMsg("表%s当前统计记录数为%d",sTableName,iCnt);
	
	return 0;	
}
int GenTableName(char sModule[],char sStatMonth[],char sTableName[])
{
	char sMonth[3],sYear[5];
	
	strncpy(sMonth,sStatMonth+4,2);sMonth[2]=0;

	sprintf(sTableName,"SETT_NBR_STAT_%s_%s",sModule,sMonth);
	
	strncpy(sYear,sStatMonth,4);sYear[4]=0;
	
	sprintf(sChkTableName,"SETT_NBR_INTF_FJBI_%s",sYear);

	return 0;
}

int GenFileName(char sOutputDir[],char sModule[],char sStatPeriod[],
	char sOppCarrier[],char sAreaCode[],char sRoamDirection[],char sOutputFile[])
{	
	char sFileNamePrefix[30];
	char sFileNameSuffix[30];
	char sBaseFileName[30];
 	
	if(IsInSTT(sModule)){
		strcpy(sFileNamePrefix,"C0010JS1M");
		if(strcmp(sOppCarrier,"CT")==0){
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000002101.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000002102.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000002103.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000002104.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000002105.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000002106.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000002107.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000002108.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000002109.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}
		}
		else if(strcmp(sOppCarrier,"CM")==0){ 
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000002110.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000002111.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000002112.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000002113.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000002114.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000002115.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000002116.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000002117.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000002118.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}			
		}
		else if(strcmp(sOppCarrier,"CRC")==0)
				strcpy(sFileNameSuffix,"0000002120.Txt");
		else if(strcmp(sOppCarrier,"CS")==0)
				strcpy(sFileNameSuffix,"0000002121.Txt");
		else if(strcmp(sOppCarrier,"CTC")==0)
				strcpy(sFileNameSuffix,"0000002122.Txt");
		else{
			printf("生成文件名错误!");
			return -1;
		}
		strcpy(sBaseFileName,sFileNamePrefix);
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,sFileNameSuffix);
	}
	else if(IsInSTP(sModule)){
		strcpy(sFileNamePrefix,"C0010JS1M");
		if(strcmp(sOppCarrier,"CT")==0){ 
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000001101.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000001102.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000001103.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000001104.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000001105.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000001106.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000001107.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000001108.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000001109.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}
		}
		else if(strcmp(sOppCarrier,"CM")==0){
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000001110.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000001111.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000001112.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000001113.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000001114.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000001115.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000001116.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000001117.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000001118.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}
		}
		else if(strcmp(sOppCarrier,"CRC")==0)
				strcpy(sFileNameSuffix,"0000001120.Txt");
		else{
			printf("生成文件名错误!");
			return -1;
		}
		strcpy(sBaseFileName,sFileNamePrefix);
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,sFileNameSuffix);
	}
	else if(IsInTLL(sModule)){
		strcpy(sBaseFileName,"C0010JS2M");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"0000000101.Txt");
	}
	else if(IsInVIT(sModule)){
		strcpy(sFileNamePrefix,"C0010JS4D");
		if(strcmp(sRoamDirection,"IN")==0)
			strcpy(sFileNameSuffix,"00000101.Txt");
		else if(strcmp(sRoamDirection,"OUT")==0)
			strcpy(sFileNameSuffix,"00000102.Txt");
		else{
			printf("生成文件名错误!");
			return -1;
		}
		strcpy(sBaseFileName,sFileNamePrefix);
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,sFileNameSuffix);
	}
	else if(IsInSMS(sModule)){
		strcpy(sBaseFileName,"C0010JS3M");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"00000101.Txt");
	}
	else if(IsInSCX(sModule)){
		strcpy(sBaseFileName,"C0010JS3M");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"00000102.Txt");
	}
	else if(IsInTLP(sModule)){
		strcpy(sBaseFileName,"C0010JS2M");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"0000001101.Txt");
	}
	else{
		printf("生成文件名失败！\n");
		return -1;
	}
	
	RegularDir(sOutputDir);
	strcpy(sOutputFile,sOutputDir);
	strcat(sOutputFile,sBaseFileName);
	
	return 0;
}

/*
1.GSM网间语音
	与电信固网，分地市给文件
	与电信CDMA，不分地市
	与移动，分地市给文件
	与铁通，不分地市
	与卫通，不分地市
2.固网网间语音
	与电信（包含CDMA），分地市给文件
	与移动，分地市给文件
	与铁通，不分地市
3.短信彩信，按日给文件
4.漫游上下传，分漫入漫出，按日给文件
5.GSM长途、固网长途，整个表出一个文件
*/
int GenSQLCondition(char sModule[],char sOppCarrier[],char sAreaCode[],
	char sRoamDirection[],char sCondition[])
{
	char sTicketTypeId[20];
	
	if(IsInSTT(sModule) || IsInSTP(sModule)){
        	if(IsInSTT(sModule) && strcmp(sOppCarrier,"CT")==0){
        		strcpy(sCondition," WHERE TICKET_TYPE_ID LIKE '1%' AND TICKET_TYPE_ID NOT LIKE '1_3_'");
        		strcat(sCondition," AND VISIT_AREA_CODE='");
        		strcat(sCondition,sAreaCode);
        		strcat(sCondition,"'");
        	}
        	else if(IsInSTT(sModule) && strcmp(sOppCarrier,"CTC")==0)
        		strcpy(sCondition," WHERE TICKET_TYPE_ID LIKE '1_3_'");
        	else if(IsInSTP(sModule) && strcmp(sOppCarrier,"CT")==0){
        		strcpy(sCondition," WHERE TICKET_TYPE_ID LIKE '1%'");
        		strcat(sCondition," AND VISIT_AREA_CODE='");
        		strcat(sCondition,sAreaCode);
        		strcat(sCondition,"'");
        	}
        	else if(strcmp(sOppCarrier,"CM")==0){
        		strcpy(sCondition," WHERE TICKET_TYPE_ID LIKE '2%'");
        		strcat(sCondition," AND VISIT_AREA_CODE='");
        		strcat(sCondition,sAreaCode);
        		strcat(sCondition,"'");
        	}
        	else if(strcmp(sOppCarrier,"CRC")==0)
        		strcpy(sCondition," WHERE TICKET_TYPE_ID LIKE '5%'");
        	else if(strcmp(sOppCarrier,"CS")==0)
        		strcpy(sCondition," WHERE TICKET_TYPE_ID LIKE '6%'");
        	else{
			printf("获取数据查询条件失败.\n");
			return -1;
		}
	}
	else if(IsInSCX(sModule) || IsInSMS(sModule)){
		strcpy(sCondition,"WHERE SUBSTR(RESERVE2,4,1)='0'");
        }
        else if(IsInVIT(sModule)){
		
        	if(strcmp(sRoamDirection,"IN")==0)
        		strcpy(sTicketTypeId,"9311,9321");
        	else if(strcmp(sRoamDirection,"OUT")==0)
        		strcpy(sTicketTypeId,"9312,9322,9332");
        	else{
        		printf("获取查询条件话单类别ID失败.\n");
			return -1;
        	}
        	strcat(sCondition," WHERE TICKET_TYPE_ID IN (");
        	strcat(sCondition,sTicketTypeId);
        	strcat(sCondition,")");
        }
        else if(IsInTLL(sModule) || IsInTLP(sModule))
        	strcpy(sCondition,"");
        else{
		printf("获取数据查询条件失败.\n");
		return -1;
	}
	
	return 0;
}
/*
11.号码为非本省的移动电话号码，直接取，不加区号
12.号码为本省的移动电话号码，直接取，不加区号
13.号码为省际固定号码（区号＋7-8位），加区号
14.号码为本省的固定号码（区号＋7+8位），加区号
15.港澳台、国际号码，加区号
16.号码为1或9开头的短号，不加区号
17.区号+短号

18.对于17911等接入号，则直接填写HEAD_CARR表查到的TYPE=’R’的接入号字段，而截断后面的号码;
	18 接入号+号码
	19 接入号+区号+号码
	20 本类其它
21.区号+其它号码
99.对于其他超长号码，则直接截断10位号码，作为RESERVE1填写
	98 有去区号
*/


int GenOutAccNbr(char sAccNbr[],char sHomeAreaCode[],char sReserve1[],
	char sReserve2[],char sOutAccNbr[])
{
	char sType[2];
	
	GetAreaType(sHomeAreaCode,sType);

	if(strncmp(sReserve2+1,"11",2)==0){
		strcpy(sOutAccNbr,sAccNbr);
		return 11;
	}
	else if (strncmp(sReserve2+1,"12",2)==0){
		strcpy(sOutAccNbr,sAccNbr);
		return 12;
	}
	else if (strncmp(sReserve2+1,"13",2)==0){
		sprintf(sOutAccNbr,"0%s%s",sHomeAreaCode,sAccNbr);
		return 13;
	}
	else if (strncmp(sReserve2+1,"14",2)==0){
		sprintf(sOutAccNbr,"0%s%s",sHomeAreaCode,sAccNbr);
		return 14;
	}
	else if (strncmp(sReserve2+1,"15",2)==0){
		sprintf(sOutAccNbr,"0%s%s",sHomeAreaCode,sAccNbr);
		return 15;
	}
	else if (strncmp(sReserve2+1,"16",2)==0){
		strcpy(sOutAccNbr,sAccNbr);
		return 16;
	}
	else if (strncmp(sReserve2+1,"17",2)==0){
		sprintf(sOutAccNbr,"0%s%s",sHomeAreaCode,sAccNbr);
		return 17;
	}
	else if (strncmp(sReserve2+1,"18",2)==0){
		sprintf(sOutAccNbr,"%s%s",sReserve1,sAccNbr);
		return 18;
	}
	else if (strncmp(sReserve2+1,"19",2)==0||
		strncmp(sReserve2+1,"20",2)==0){
		sprintf(sOutAccNbr,"%s0%s%s",sReserve1,sHomeAreaCode,sAccNbr);
		return 19;
	}					
	else if (strncmp(sReserve2+1,"21",2)==0){
		sprintf(sOutAccNbr,"0%s%s",sHomeAreaCode,sAccNbr);
		return 21;
	}
	else{
		strcpy(sOutAccNbr,sAccNbr);
		return 99;
	}
	
	return 0;
}

int main(int argc,char *argv[])
{
	char	sTableName[32],sStatMonth[7],sOutputDir[128];
	char	sOutputFile[128],sModule[4],sOppCarrier[4],sAreaCode[4],sRoamDirection[4];
	char 	msg[1024],sCondition[1024];
	if(argc!=4 && argc!=5 && argc!=6){
		printf("Usage %s Module OutputDir StatPeriod [OppCarrier] [AreaCode] [RoamDirection]\n",argv[0]);
		printf("sample:\n");
		printf("%s stt /home/bill/test 200506 ct,cm,ctc,crc 591~599\n"	,argv[0]);
		printf("%s stp /home/bill/test 200506 ct,cm,crc 591~599\n"	,argv[0]);
		printf("%s tll /home/bill/test 200506 \n"	,argv[0]);
		printf("%s tlp /home/bill/test 200506 \n"	,argv[0]);
		printf("%s scx /home/bill/test 200506 \n"	,argv[0]);
		printf("%s vit /home/bill/test 200506 in,out \n"	,argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	
	strcpy(sModule,argv[1]);
	Upper(sModule);
	strcpy(sOutputDir,argv[2]);

	if(!IsInSTT(sModule) && 
		!IsInTLL(sModule) &&
		!IsInVIT(sModule) &&
		!IsInSCX(sModule) &&
		!IsInSMS(sModule) &&
		!IsInSTP(sModule) &&
		!IsInTLP(sModule)){
		printf("业务模块错误，请重新输入！\n");
		return -1;
	}
	
	if(IsInSTT(sModule) || IsInSTP(sModule)){
		strcpy(sStatMonth,argv[3]);
		strcpy(sOppCarrier,argv[4]);
		Upper(sOppCarrier);
		strcpy(sAreaCode,argv[5]);
	}
	
	strcpy(sStatMonth,argv[3]);
	
	if(IsInVIT(sModule)){
		strcpy(sRoamDirection,argv[4]);
		Upper(sRoamDirection);
	}
	if(InitVisualFunc(sModule)<0) return -1;
		
	/*生成表名*/
	GenTableName(sModule,sStatMonth,sTableName);
	printf("sTableName=%s\n",sTableName);
	
	/*生成文件名*/
	if(IsInVIT(sModule))
		GenFileName(sOutputDir,sModule,sStatMonth,sOppCarrier,
			sAreaCode,sRoamDirection,sOutputFile);
	else if(IsInSCX(sModule) || IsInSMS(sModule))
		GenFileName(sOutputDir,sModule,sStatMonth,sOppCarrier,
			sAreaCode,"",sOutputFile);
	else
		GenFileName(sOutputDir,sModule,sStatMonth,sOppCarrier,
			sAreaCode,"",sOutputFile);
					
	printf("sOutputFile=%s\n",sOutputFile);
	
	if((fp=fopen(sOutputFile,"w"))==NULL) return -1;

	if(IniConnect("dataconnstr")<0){ 
	        printf("connerror\n");
		return -1;	
	}
	/*获取输出数据的SQL条件*/
        if(IsInSTT(sModule) || IsInSTP(sModule))
        	GenSQLCondition(sModule,sOppCarrier,sAreaCode,"",sCondition);
	else if(IsInSCX(sModule) || IsInSMS(sModule))
        	GenSQLCondition(sModule,"","","",sCondition);
	else if(IsInVIT(sModule))
        	GenSQLCondition(sModule,"","",sRoamDirection,sCondition);
	else if(IsInTLL(sModule) || IsInTLP(sModule))
        	GenSQLCondition(sModule,"","","",sCondition);
        else{
        	printf("获取不到SQL条件.\n");
        	return -1;
        }
        
        if(XDealSettNbr(sTableName,sCondition,sModule,sRoamDirection,msg)<0){
        	printf("%s",msg);
        	WriteAlertMsg(msg);
        	return -1;
	}
	/*写入到文件中*/
	TravelBin((BINTREE*)pRoot,XDealSettNbrBin2File);

	/*把pRootchk输出到稽核表中 SETT_NBR_INTF_FJBI_yyyy*/

	if(XChkSett2Table(sStatMonth,sModule)<0){
		WriteAlertPrint("输出到稽核表%s失败",sChkTableName);
		RollbackWork();
		return -1;
	}
				
	printf("从表%s统计数据，生成%s文件完毕\n",sTableName,sOutputFile);
	WriteProcMsg("从表%s统计数据，生成%s文件完毕\n",sTableName,sOutputFile);
	
	printf("合计话单数%f,通话时长%f,结算时长%f,结算收入%f,结算支出%f.\n",
	iTotalCnt,iTotalDuration,iTotalFeeDuration,iTotalInFee,iTotalOutFee);

	WriteProcMsg("合计话单数%f,通话时长%f,结算时长%f,结算收入%f,结算支出%f.",
	iTotalCnt,iTotalDuration,iTotalFeeDuration,iTotalInFee,iTotalOutFee);

	
	fclose(fp);
	CommitWork();
	DisconnectDatabase();
	
	return 0;	
}     

