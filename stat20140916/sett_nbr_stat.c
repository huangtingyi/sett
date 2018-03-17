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
#include <stt_ticket.h>
#include <ticket.h>
#include <sett_nbr_supp.h>
#include "../serv/simple_serv.h"
#include "../serv/serv_intf.h"
#include "ticket_field.h"

struct SettNbrStatCtlStruct
{
	char InType[4];
	char sOutTableName[128];
};

struct SettNbrStatCtlStruct STATCTL;

BINTREE *pRoot=NULL;/*ͳ�ƽ��*/
static int iTotalCnt=0;

int (*XDealTicket)(char sSouTableName[],
	char sCondition[],char sBillingCycleID[]);
int (*XDealRecord)(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int ChkParamStr(char sSouTableName[],
	char sOutTableName[],char sBillingCycleID[]);
int XStatData2Bin(struct SettNbrStatStruct *ptOut);
int XStatData2Table();
int StatData2Table(void **ppData);
int InsertSettNbrStat(struct SettNbrStatStruct *p,int iInsertFlag);
int DealSttTicket(char sSouTableName[],
	char sCondition[],char sBillingCycleID[]);
int DealSmscTicket(char sSouTableName[],
	char sCondition[],char sBillingCycleID[]);
int DealSmspTicket(char sSouTableName[],
	char sCondition[],char sBillingCycleID[]);

void InitVisualFunc(char sFileType[]);	
int CreateTable(char sSouTableName[],char sCondition[]);
int DropTable(char sSouTableName[]);

int IsInSTT(char sInType[]);
int IsInSTP(char sInType[]);
int IsInVIT(char sInType[]);
int IsInTLR(char sInType[]);
int IsInTLL(char sInType[]);
int IsInTLP(char sInType[]);
int IsInSMS(char sInType[]);
int IsInSCX(char sInType[]);
/*******���뱨�����ӵĺ�������******/
int SCX_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int SMS_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int TLP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int STP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int TLL_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int TLR_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int VIT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);
int STT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po);


int ChkParamStr(char sSouTableName[],
	char sOutTableName[],char sBillingCycleID[])
{
	int l=0;
	char sChkTime[15],sStr1[3],sStr2[3];

	
	strncpy(sChkTime,sBillingCycleID,6); 
	strcpy(sChkTime+6,"01000000");
       
	if(ChkTime(sChkTime)!=0){
		WriteAlertMsg("��������BillingCycleID=%s",sBillingCycleID);
		return -1;
	}
	
	strncpy(sStr1,sBillingCycleID+4,2);sStr1[2]=0;

	l=strlen(sSouTableName)-2;
	strncpy(sStr2,sSouTableName+l,2);sStr2[2]=0;
	if(strcmp(sStr1,sStr2)!=0){
		WriteAlertMsg("sSouTableName�����λ��BillingCycleID��һ��");
		return -1;
	}

	l=strlen(sOutTableName)-2;
	strncpy(sStr2,sOutTableName+l,2);sStr2[2]=0;
	if(strcmp(sStr1,sStr2)!=0){
		WriteAlertMsg("sOutTableName�����λ��BillingCycleID��һ��");
		return -1;
	}

	return 0;
}

int XStatData2Bin(struct SettNbrStatStruct *ptOut)
{

	struct 	SettNbrStatStruct	Temp;
	
	mvitem_settnbrstat(ptOut,&Temp);
	
	if(InsertBin(&pRoot,(void *)&Temp,
		data_search_bintree_settnbrstat_e,
		assign_insert_bintree_settnbrstat_e)<0){
		WriteAlertMsg("�������ݵ��ڴ���ʧ��");
		return -1;
	}
			
	return 0;
}
int XStatData2Table()
{

/*������ݵ�ͳ�Ʊ�*/
	TravelBin(pRoot,StatData2Table);
		
        if(InsertSettNbrStat(NULL,TRUE)<0)return -1;

	WriteProcMsg("��ǰ�����¼��%d,�������%s",
		iTotalCnt,STATCTL.sOutTableName);
	
	return 0;
}

int StatData2Table(void **ppData)
{
	
	struct SettNbrStatStruct *ptHead,*pTemp;
	struct SettNbrStatStruct	pout;

	ptHead=(struct SettNbrStatStruct*)*ppData;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_settnbrstat(pTemp,&pout);

		iTotalCnt++;
		if(InsertSettNbrStat(&pout,FALSE)<0)return -1;

		if(iTotalCnt%30000==0){
			if(InsertSettNbrStat(NULL,TRUE)<0){
				return -1;
			}
	                WriteProcMsg("��ǰ�����¼��%d,�������%s",
	                	iTotalCnt,STATCTL.sOutTableName);
		}		
	}
	
	return 0;
}

int InsertSettNbrStat(struct SettNbrStatStruct *p,int iInsertFlag)
{
        static int iFirstFlag=TRUE;
        static struct SettNbrStatStructOut TempOut;
        if(iFirstFlag==TRUE){
                iFirstFlag=FALSE;
                bzero((void*)&TempOut,sizeof(struct SettNbrStatStructOut));
                strcpy(TempOut.sTableName,STATCTL.sOutTableName);
        }
        return EInsertStructToSettNbrStat(p,iInsertFlag,&TempOut);
}

int DealSttTicket(char sSouTableName[],
	char sCondition[],char sBillingCycleID[])
{
	int iCnt=0,l=0;
	char sOri[1024];
	struct SttTicketStruct Temp;
	struct SttTicketStructIn TempIn;
	struct SettNbrStatStruct s;
	
	strcpy(TempIn.sTableName,sSouTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;

	while(EGetSttTicketToStruct(&Temp,&TempIn)){

		mvitem_mfsttticket(&Temp,(struct FSttTicketStruct*)sOri);
		sOri[sizeof(struct FSttTicketStruct)]=0;		

		if((l=XDealRecord(sOri,sBillingCycleID,&s))<0){
			WriteAlertMsg("�Ա�%s��������ʧ��",sSouTableName);
			return -1;
		}		
		
		if(l>1) continue;	/*����Դ��ͳ��*/
		
		if(XStatData2Bin(&s)<0)return -1;

		if((++iCnt%30000)==0)
			WriteProcMsg("��%s��ǰͳ�Ƽ�¼��Ϊ%d",sSouTableName,iCnt);
	}


	WriteProcMsg("��%sͳ�����,�굥��¼��Ϊ%d",sSouTableName,iCnt);
		
	return 0;
}
int DealSmscTicket(char sSouTableName[],
	char sCondition[],char sBillingCycleID[])
{
	int iCnt=0,l=0;
	char sOri[1024];
	struct SmscTicketStruct Temp;
	struct SmscTicketStructIn TempIn;
	struct SettNbrStatStruct s;
	
	strcpy(TempIn.sTableName,sSouTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;

	while(EGetSmscTicketToStruct(&Temp,&TempIn)){

		mvitem_mfsmscticket(&Temp,(struct FSmscTicketStruct*)sOri);
		sOri[sizeof(struct FSmscTicketStruct)]=0;		

		if((l=XDealRecord(sOri,sBillingCycleID,&s))<0){
			WriteAlertMsg("�Ա�%s��������ʧ��",sSouTableName);
			return -1;
		}		
		
		if(l>1) continue;	/*����Դ��ͳ��*/

		if(XStatData2Bin(&s)<0)return -1;

		if((++iCnt%30000)==0)
			WriteProcMsg("��%s��ǰͳ�Ƽ�¼��Ϊ%d",sSouTableName,iCnt);
	}


	WriteProcMsg("��%sͳ�����,�굥��¼��Ϊ%d",sSouTableName,iCnt);
		
	return 0;
}
int DealSmspTicket(char sSouTableName[],
	char sCondition[],char sBillingCycleID[])
{
	int iCnt=0,l=0;
	char sOri[1024];
	struct SmspTicketStruct Temp;
	struct SmspTicketStructIn TempIn;
	struct SettNbrStatStruct s;
	
	strcpy(TempIn.sTableName,sSouTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;

	while(EGetSmspTicketToStruct(&Temp,&TempIn)){

		mvitem_mfsmspticket(&Temp,(struct FSmspTicketStruct*)sOri);
		sOri[sizeof(struct FSmspTicketStruct)]=0;		

		if((l=XDealRecord(sOri,sBillingCycleID,&s))<0){
			WriteAlertMsg("�Ա�%s��������ʧ��",sSouTableName);
			return -1;
		}		
		
		if(l>1) continue;	/*����Դ��ͳ��*/

		if(XStatData2Bin(&s)<0)return -1;

		if((++iCnt%30000)==0)
			WriteProcMsg("��%s��ǰͳ�Ƽ�¼��Ϊ%d",sSouTableName,iCnt);
	}


	WriteProcMsg("��%sͳ�����,�굥��¼��Ϊ%d",sSouTableName,iCnt);
			
	return 0;
}

void InitVisualFunc(char sFileType[])
{
	if(IsInSTT(sFileType)){
		XDealTicket=DealSttTicket;
		XDealRecord=STT_DealRecord;
	}
	else if(IsInVIT(sFileType)){
		XDealTicket=DealSttTicket;
		XDealRecord=VIT_DealRecord;		
	}
	else if(IsInTLR(sFileType)){
		XDealTicket=DealSttTicket;
		XDealRecord=TLR_DealRecord;
		
	}	
	else if(IsInTLL(sFileType)){
		XDealTicket=DealSttTicket;
		XDealRecord=TLL_DealRecord;
		
	}
	else if(IsInSTP(sFileType)){
		XDealTicket=DealSttTicket;
		XDealRecord=STP_DealRecord;
		
	}
	else if(IsInTLP(sFileType)){
		XDealTicket=DealSttTicket;
		XDealRecord=TLP_DealRecord;
		
	}
	else if(IsInSMS(sFileType)){
		XDealTicket=DealSmscTicket;
		XDealRecord=SMS_DealRecord;
		
	}
	else if(IsInSCX(sFileType)){
		XDealTicket=DealSmspTicket;
		XDealRecord=SCX_DealRecord;
		
	}
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
int IsInTLR(char sInType[])
{
	if(strcmp(sInType,"TLR")==0) return true;
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
int DropTable(char sSouTableName[])
{
	char sCommand[1024];
	
/*
ɾ����ʱ��TLL_TICKET_LS_XX
*/
	sprintf(sCommand,"DROP TABLE %s ",sSouTableName);

	Upper(sCommand);
	ExecSql(sCommand);
	
	return 0;
}
int CreateTable(char sSouTableName[],char sCondition[])
{
	int iRet,l=0;
	char sCommand[1024],sStr[3],sOutTableName[128];
	
/*
GSMʡ�ʳ�;�������⴦��:
����ͼTLL_TICKET_XX д����ʱ����TLL_TICKET_LS_XX
��������ɾ����ʱ��TLL_TICKET_LS_XX
*/
	l=strlen(sSouTableName)-2;
	strncpy(sStr,sSouTableName+l,2);sStr[2]=0;
	
	sprintf(sOutTableName,"STAT_LS_TICKET_%s",sStr);

	if(TableExist(sOutTableName)==true){
                if(DropTable(sOutTableName)<0)return -1;
        }
	
	sprintf(sCommand,
	"CREATE TABLE %s AS SELECT * FROM %s %s ",
	sOutTableName,sSouTableName,sCondition);

	Upper(sCommand);
	iRet=ExecSql(sCommand);
	if(iRet<0){
	        WriteAlertPrint("ִ��SQL %s ����",sCommand);
	        return -1;
	}
	
	strcpy(sSouTableName,sOutTableName);
	
	return 0;
}


int data_search_bintree_settnbrstat_e(void *pValue,void*pData)
{
	struct SettNbrStatStruct *pSource=(struct SettNbrStatStruct *)pValue;
	struct SettNbrStatStruct *pTarget=(struct SettNbrStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sAccNbr,pTarget->sAccNbr))!=0) return res;
	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
	if((res=strcmp(pSource->sProvCode,pTarget->sProvCode))!=0) return res;
	if((res=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return res;	
	if((res=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return res;	

	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;

	if((res=strcmp(pSource->sServiceType,pTarget->sServiceType))!=0) return res;
	if((res=strcmp(pSource->sNbrType,pTarget->sNbrType))!=0) return res;
	if((res=strcmp(pSource->sOppNbrType,pTarget->sOppNbrType))!=0) return res;

	if((res=pSource->iOppCarrID-pTarget->iOppCarrID)!=0) return res;

	if((res=strcmp(pSource->sOppArea,pTarget->sOppArea))!=0) return res;
	if((res=strcmp(pSource->sOppProv,pTarget->sOppProv))!=0) return res;
	if((res=strcmp(pSource->sBillingTypeID,pTarget->sBillingTypeID))!=0) return res;
	if((res=strcmp(pSource->sReserve1,pTarget->sReserve1))!=0) return res;	
	if((res=strcmp(pSource->sReserve2,pTarget->sReserve2))!=0) return res;	
	if((res=strcmp(pSource->sReserve3,pTarget->sReserve3))!=0) return res;	
	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;	
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}

void assign_insert_bintree_settnbrstat_e(void **ppData,void *pData)
{
        int iInFee=0,iOutFee=0;

        struct SettNbrStatStruct *pTemp;
        if((pTemp=(*ppData))==NULL){
                pTemp=malloc(sizeof(struct SettNbrStatStruct));
                ERROR_EXIT(pTemp==NULL,"����SettNbrStatStruct�ṹ����");
                memcpy((void*)pTemp,pData,sizeof(struct SettNbrStatStruct));
                pTemp->pNext=NULL;
                *ppData=(void*)pTemp;
                return;
        }
	pTemp->iCnt+=((struct SettNbrStatStruct*)pData)->iCnt;
	pTemp->iDuration+=((struct SettNbrStatStruct*)pData)->iDuration;
	pTemp->iSettMin+=((struct SettNbrStatStruct*)pData)->iSettMin;


        iInFee=atoi(pTemp->sInFee)+
                atoi(((struct SettNbrStatStruct*)pData)->sInFee);
        iOutFee=atoi(pTemp->sOutFee)+
                atoi(((struct SettNbrStatStruct*)pData)->sOutFee);

        sprintf(pTemp->sInFee,                  "%12d",iInFee);
        sprintf(pTemp->sOutFee,                  "%12d",iOutFee);

}

void GetNbrType(char sAccNbr[],
	int iCarrierID,char sAreaCode[],char sOutNbrType[])
{
	int i=0;
	char sNbrType[5],sType[2];

	strcpy(sType,"");
	strcpy(sNbrType,"X");
	
	GetAreaType(sAreaCode,sType);
	
	if(IS_UNICOM_WCDMA(sAccNbr))	strcpy(sNbrType,"CUW");
	else if(IS_MOBILE_TD(sAccNbr))	strcpy(sNbrType,"CMT");
	else if(IS_UNICOM_CDMA(sAccNbr))strcpy(sNbrType,"CTC");
	else if(IS_UNICOM_GSM(sAccNbr))	strcpy(sNbrType,"CUG");
	else if(IS_MOBILE_GSM(sAccNbr))	strcpy(sNbrType,"CMM");
	else if(strcmp(sType,"2")==0){
	
		if(iCarrierID==1)strcpy(sNbrType,"CT");
		else if(iCarrierID==2)strcpy(sNbrType,"CMM");
		else if(iCarrierID==3)strcpy(sNbrType,"CUG");
		else if(iCarrierID==4)strcpy(sNbrType,"CUN");
		else if(iCarrierID==5)strcpy(sNbrType,"CRC");
		else if(iCarrierID==6)strcpy(sNbrType,"CS");
	}
	
	strcpy(sOutNbrType,sNbrType);
}

void GetProvCode(char sAreaCode[],char sVisitAreaCode[],char sOutsProvCode[])
{
	char sProvCode[5];

	strcpy(sProvCode,"");

	GetCapitalCode(sAreaCode,sProvCode);
	
	if(strcmp(sProvCode,"")==0)
		GetCapitalCode(sVisitAreaCode,sProvCode);
	
	if(strncmp(sProvCode,"0",1)==0||
		strcmp(sProvCode,"-1")==0)strcpy(sProvCode,"");

	strcpy(sOutsProvCode,sProvCode);

}

/*
11.���ں���Ϊ�Ǳ�ʡ���ƶ��绰���룬��RESERVE1��д�Ŷ�;
12.���ں���Ϊ��ʡ���ƶ��绰���룬��RESERVE1��д�Ŷ�;
13.���ں���Ϊ�Ǳ�ʡ�Ĺ̶����루���ţ�7-8λ������RESERVE1��д�̶������ǰ3λ;
14.���ں���Ϊ��ʡ�Ĺ̶����루���ţ�7+8λ������RESERVE1��дHEAD_CARR���е�AREA_ID;

15.���ʺ��루�������ţ�nλ��,

16.���ں���Ϊ1��9��ͷ�Ķ̺ţ���RESERVE1��дȥ�����ŵĶ̺š������볤�Ȳ�����6λ,400,800��;
17.����+�̺�

18.����17911�Ƚ���ţ���ֱ����дHEAD_CARR��鵽��TYPE=��R���Ľ�����ֶΣ����ضϺ���ĺ���;
	18 �����+����
	19 �����+����+����
	20 ��������
21.����+��������
99.���������������룬��ֱ�ӽض�10λ���룬��ΪRESERVE1��д
	98 ��ȥ����
*/
int GetSttRes(char sAccNbr[],char sRawNbr[],
	char sAreaCode[],char sStartTime[],char sRes[])
{
	int off=0,len,l;
	char *sOtherParty=sAccNbr;
	char sTempAreaCode[9],sLongAreaCode[9],sType[2];
	struct HeadCarrStruct	*pHeadCarr=NULL;


	strcpy(sRes,"");

	if(strcmp(sRawNbr,"NOTFOUND")==0)return 0;
/*15.���ʺ��루�������ţ�nλ��*/
	if(sAreaCode[0]=='0'){
		if(strncmp(sAccNbr+1,
			sAreaCode,strlen(sAreaCode))==0){
			strncpy(sRes,sAccNbr,10);
			return 15;
		}
	}
/*14.���ں���Ϊ��ʡ�Ĺ̶����루���ţ�7+8λ����
��RESERVE1��дHEAD_CARR���е�AREA_ID;*/
	if(SearchHeadCarr(sOtherParty,sAreaCode,sStartTime,&pHeadCarr)==FOUND){

		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_CORR)==0){
			if((strlen(sOtherParty)==8&&
				strcmp(sOtherParty,sRawNbr)==0)
				||strlen(sOtherParty)==7){
				sprintf(sRes,"%4d",pHeadCarr->iAreaID);
				return 14;
			}
		}
	}
/*16.���볤�Ȳ�����6λ�̺�,400,800*/	
	if(SpecialNbr(sOtherParty,sStartTime)==true&&
		(strlen(sOtherParty)<=6||
		strncmp(sOtherParty,"400",3)==0||
		strncmp(sOtherParty,"800",3)==0)){
		strcpy(sRes,sOtherParty);
		return 16;
	}

/*18.�ж�HEAD_CARR��鵽��TYPE=��R���Ľ�����ֶ�*/	
	if(SearchHeadCarr(sOtherParty,"*",sStartTime,&pHeadCarr)==FOUND){
		if(strcmp(pHeadCarr->sType,HEAD_CARR_TYPE_REF)==0&&
			strncmp(pHeadCarr->sHead,"00",2)!=0){
			strcpy(sRes,pHeadCarr->sHead);
			l=strlen(pHeadCarr->sHead);
			if(strncmp(sOtherParty+l,sRawNbr,strlen(sRawNbr))==0)
				return 18;
			if(sOtherParty[l]=='0') l++;
			l=l+strlen(sAreaCode);
			
			if(strncmp(sOtherParty+l,sRawNbr,strlen(sRawNbr))==0)
				return 19;
			
			
			return 20;
		}
	}

/*11.�Ǳ�ʡ���ƶ��绰����*/
	strcpy(sType,"");
	GetAreaType(sAreaCode,sType);

	if(sOtherParty[0]=='0'){ off++;sOtherParty++;}
	if(IS_MOB_NBR(sOtherParty)&&
		sOtherParty[0]=='1'&&
		strlen(sOtherParty)==11){
		if(strcmp(sType,"2")!=0){
			strncpy(sRes,sOtherParty,7);
			return 11;
		}
		strncpy(sRes,sOtherParty,7);
		return 12;
	}

	strcpy(sTempAreaCode,sAreaCode);
	RegularAreaCode(sTempAreaCode);

	l=strlen(sTempAreaCode);
	len=strlen(sOtherParty);
	if(strncmp(sOtherParty,sTempAreaCode,l)==0){
/*+���ŵĶ̺�*/
		if(SpecialNbr(sOtherParty+l,sStartTime)==true){
			strcpy(sRes,sOtherParty+l);
			return 17;
		}
/*+���ŵĹ̶�����*/		
		if((len-l==7||len-l==8||len-l==11)&&
			sOtherParty[l]!='0'&&sTempAreaCode[0]!='0'){

			if(SearchHeadCarr(sOtherParty+l,
				sAreaCode,sStartTime,&pHeadCarr)==FOUND){
				if(strcmp(pHeadCarr->sType,
					HEAD_CARR_TYPE_CORR)==0&&
					((strlen(sOtherParty)-l)==8||
					(strlen(sOtherParty)-l)==7)){
					sprintf(sRes,"%4d",pHeadCarr->iAreaID);
					return 14;
				}					
			}
			if(IS_MOB_NBR(sOtherParty+l)&&
				sOtherParty[l]=='1'&&
				(strlen(sOtherParty)-l)==11){
				if(strcmp(sType,"2")!=0){
					strncpy(sRes,sOtherParty+l,7);
					return 11;
				}
				strncpy(sRes,sOtherParty+l,7);
				return 12;
			}		
			
			if(((strlen(sOtherParty)-l)==8||
				(strlen(sOtherParty)-l)==7)&&
				sOtherParty[l]!='1'){
				strncpy(sRes,sOtherParty+l,3);
				return 13;
			}
			strncpy(sRes,sOtherParty+l,10);
			return 21;
		}
		else{
			strncpy(sRes,sOtherParty+l,10);
			return 21;
		}
	}

	strncpy(sRes,sAccNbr,10);
	if(strncmp(sRes,sRawNbr,10)==0)return 99;
	
	return 98;
}

void ModifySttTicket(struct SttTicketStruct *pi)
{
/*
1.ȡ�����Ǳ���Ӫ�̵ĺ��룬����MSISDN����OTHER_PARTY,
������ƶ�������ȥ��0,����ǹ̶�������ȥ�����ţ������������ֱ��ȥ�����ţ�
����������.
2.ACC_NBR����ֶ��ڻ�������ʱ��ֱ������MSRN�ֶ�;
3.�ڻ������У���MSRN����MSISDNʱ��CAL='1',��MSRN����OTHER_PARTYʱ��CAL='2' 
������CAL='3'
4.ֻ���������������
*/
	char sAccNbr[25],sCal[2],sRawMsisdn[25],sRawOtherParty[25];
	
	
	NewGetRawNbr(pi->sMsisdn,pi->sHomeAreaCode,pi->sStartTime,sRawMsisdn);
	NewGetRawNbr(pi->sOtherParty,pi->sCalledCode,pi->sStartTime,sRawOtherParty);
	

	if(pi->iTicketTypeID>0&&
		strcmp(pi->sUserType,"P")==0){

		if(pi->iTrunkInCarrierID==4)
			strcpy(sAccNbr,sRawMsisdn);
		else if(pi->iTrunkOutCarrierID==4)
			strcpy(sAccNbr,sRawOtherParty);
		else{
			if(pi->iAddFee>pi->iTollFee)
				strcpy(sAccNbr,sRawOtherParty);
			if(pi->iAddFee<pi->iTollFee)
				strcpy(sAccNbr,sRawMsisdn);
			else if((pi->iCallingCarrierID==3||
				pi->iCallingCarrierID==4)&&
				pi->iCallingTypeID!=3001)
				strcpy(sAccNbr,sRawMsisdn);
			else if((pi->iCalledCarrierID==3||
				pi->iCalledCarrierID==4)&&
				pi->iCalledTypeID!=3001)
				strcpy(sAccNbr,sRawOtherParty);
			else
				strcpy(sAccNbr,"NOTFOUND");
		}
	}		
	else if(pi->iTicketTypeID>0){
	/*GSM�������*/				
		if(pi->iTrunkInCarrierID==3)
			strcpy(sAccNbr,sRawMsisdn);
		else if(pi->iTrunkOutCarrierID==3)
			strcpy(sAccNbr,sRawOtherParty);
		else{
			if(pi->iAddFee>pi->iTollFee)
				strcpy(sAccNbr,sRawOtherParty);
			if(pi->iAddFee<pi->iTollFee)
				strcpy(sAccNbr,sRawMsisdn);
			else if(pi->iCallingCarrierID==3&&
				pi->iCallingTypeID!=3001)
				strcpy(sAccNbr,sRawMsisdn);
			else if(pi->iCalledCarrierID==3&&
				pi->iCalledTypeID!=3001)
				strcpy(sAccNbr,sRawOtherParty);
			else
				strcpy(sAccNbr,"NOTFOUND");
		}
	}

	
	if(strcmp(sAccNbr,sRawMsisdn)==0)
		strcpy(sCal,"1");
	else if(strcmp(sAccNbr,sRawOtherParty)==0)
		strcpy(sCal,"2");
	else	strcpy(sCal,"3");

	strncpy(pi->sMsrn,sCal,1);
	strncpy(pi->sMsrn+1,sAccNbr,11);
	pi->sMsrn[12]=0;	
}
int STT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{
	int iCnt=1,iInFee=0,iOutFee=0,i=0;
	char sSecPerCnt[6],sType[2],sOriAccNbr[25],sCal[2];
	struct SttTicketStruct Temp;
	
	bzero((void*)po,sizeof(struct SettNbrStatStruct));
	
	mvitem_fmsttticket((struct FSttTicketStruct *)sOri,
		sizeof(struct FSttTicketStruct),&Temp);
	
	ModifySttTicket(&Temp);
	
	if(Temp.iTicketTypeID<=0)	return 2;
	po->iTicketTypeID=		Temp.iTicketTypeID;
	
	if(strcmp(Temp.sMsrn,"")==0)
		strcpy(po->sAccNbr,"NULL");
	else 	strncpy(po->sAccNbr,Temp.sMsrn+1,11);
	
	strncpy(po->sVisitAreaCode,	Temp.sVisitAreaCode,5);
	strcpy(po->sNetType,		"GSM");

	po->iCnt=			iCnt;
	po->iDuration=			Temp.iDuration;
/*ȡ�ʷѲ���*/
	GetBinStr("TICKET_TARIFF",
		Temp.iTicketTypeID,"",Temp.sStartTime,sSecPerCnt);
	i=atoi(sSecPerCnt);if(i<=0)i=60;
	po->iSettMin=(Temp.iDuration+i-1)/i*i;

       	iInFee=Temp.iAddFee-Temp.iTollFee;
        iOutFee=Temp.iTollFee-Temp.iAddFee;
        
        if(iInFee<0)iInFee=0;
        if(iOutFee<0)iOutFee=0;
        
        sprintf(po->sInFee,                  "%12d",iInFee);
        sprintf(po->sOutFee,                 "%12d",iOutFee);
        
	strcpy(po->sServiceType,	"STT");
	strncpy(sCal,Temp.sMsrn,1);sCal[1]=0;
	
	if(strcmp(sCal,"1")==0){
		strncpy(po->sHomeAreaCode,	Temp.sHomeAreaCode,5);
		GetNbrType(po->sAccNbr,Temp.iCallingCarrierID,
			Temp.sHomeAreaCode,po->sNbrType);	
		GetNbrType(Temp.sOtherParty,Temp.iCalledCarrierID,
			Temp.sCalledCode,po->sOppNbrType);
		po->iOppCarrID=		Temp.iCalledCarrierID;
		strncpy(po->sOppArea,	Temp.sCalledCode,5);
		strcpy(sOriAccNbr,		Temp.sMsisdn);
	}
	else{
		strncpy(po->sHomeAreaCode,	Temp.sCalledCode,5);

		GetNbrType(po->sAccNbr,Temp.iCalledCarrierID,
			Temp.sCalledCode,po->sNbrType);	
		GetNbrType(Temp.sMsisdn,Temp.iCallingCarrierID,
			Temp.sHomeAreaCode,po->sOppNbrType);	
		po->iOppCarrID=		Temp.iCallingCarrierID;
		strncpy(po->sOppArea,	Temp.sHomeAreaCode,5);
		
		strcpy(sOriAccNbr,		Temp.sOtherParty);
	}

	GetProvCode(po->sHomeAreaCode,po->sVisitAreaCode,po->sProvCode);

	GetProvCode(po->sOppArea,po->sVisitAreaCode,po->sOppProv);

	GetAreaType(po->sHomeAreaCode,sType);

	if(strcmp(sType,"2")==0)
		GetBillingTypeID(po->sAccNbr,po->sBillingTypeID);

	i=GetSttRes(sOriAccNbr,po->sAccNbr,
		po->sHomeAreaCode,Temp.sStartTime,po->sReserve1);
	sprintf(po->sReserve2,"%1s%02d",	sCal,i);
		
	if(strcmp(Temp.sUserType,"W")==0)strcpy(po->sNbrType,"CUW");
	if(strcmp(Temp.sCal,"2")==0&&
		po->iTicketTypeID/1000==2)strcpy(po->sOppNbrType,"CMT");
	
	if(strcmp(Temp.sUserType,"W")!=0&&
		strcmp(Temp.sUserType,"P")!=0&&
		strcmp(po->sNbrType,"CUW")==0)strcpy(po->sNbrType,"CUG");
	if(strcmp(Temp.sCal,"2")!=0&&
		po->iTicketTypeID/1000==2&&
		strcmp(po->sOppNbrType,"CMT")==0)strcpy(po->sOppNbrType,"CMM");

	if(po->iTicketTypeID/1000==1){
		if(((po->iTicketTypeID/10)%10)==2||
			((po->iTicketTypeID/10)%10)==3)strcpy(po->sOppNbrType,"CTC");
		else strcpy(po->sOppNbrType,"CT");
	}
	
	strcpy(po->sReserve3,		"");
	strncpy(po->sSettItemDate,	Temp.sStartTime,8);
	strcpy(po->sBillingCycleID,	sBillingCycleID);
	
	return 0;
}
int VIT_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{

	int iCnt=1,iInFee=0,iOutFee=0,i,iSettFlag=0,iRate=0,iCount=0;
	char sType[2],sTempAreaCode[9],sRawMsisdn[16],sCal[2],sTemp[10];
	struct SttTicketStruct Temp;
	
	bzero((void*)po,sizeof(struct SettNbrStatStruct));
	
	mvitem_fmsttticket((struct FSttTicketStruct *)sOri,
		sizeof(struct FSttTicketStruct),&Temp);
	
	
	if(Temp.iTicketTypeID==9312&&
		strcmp(Temp.sCallType,"03")==0&&
		strcmp(Temp.sStartTime,"20100501000000")<0){
		char sRMsisdn[25];
		strcpy(sRMsisdn,Temp.sMsisdn);
		strcpy(Temp.sMsisdn,Temp.sOtherParty);
		strcpy(Temp.sOtherParty,sRMsisdn);
		strcpy(Temp.sHomeAreaCode,Temp.sCalledCode);
		Temp.iCallingCarrierID=Temp.iCalledCarrierID;
		/*��ȡTemp.iCalledCarrierID��Temp.sCalledCode*/
		
		GetCalledAreaCode(Temp.sCallType,Temp.sOtherParty,Temp.sVisitAreaCode,
			Temp.sStartTime,&iSettFlag,Temp.sCalledCode);
		GetRawNbr(Temp.sOtherParty,Temp.sCalledCode,Temp.sStartTime,sRMsisdn);
		GetHeadCarr(Temp.sOtherParty,sRMsisdn,"",Temp.sStartTime,&Temp.iCalledCarrierID);
		
	}
	
	if(Temp.iTicketTypeID!=9321&&
		Temp.iTicketTypeID!=9322&&
		Temp.iTicketTypeID!=9311&&
		Temp.iTicketTypeID!=9312&&
		Temp.iTicketTypeID!=9332)return 2;

	iSettFlag=Temp.iTicketTypeID%10-1;

	strcpy(po->sAccNbr,Temp.sMsisdn);
	strcpy(sRawMsisdn,"");
	if(Temp.iTicketTypeID==9321||
		Temp.iTicketTypeID==9322){
		strcpy(po->sAccNbr,Temp.sImsi);
		NewGetRawNbr(po->sAccNbr,
			po->sHomeAreaCode,Temp.sStartTime,sRawMsisdn);
	}
	strncpy(po->sHomeAreaCode,	Temp.sHomeAreaCode,5);
	GetProvCode(po->sHomeAreaCode,Temp.sVisitAreaCode,po->sProvCode);

	strcpy(sTempAreaCode,Temp.sVisitAreaCode);
	RegularAreaCode(sTempAreaCode);
	strncpy(po->sVisitAreaCode,	sTempAreaCode,5);
	strcpy(po->sNetType,		"GSM");

	po->iTicketTypeID=		Temp.iTicketTypeID;
	po->iCnt=			iCnt;
	po->iDuration=			Temp.iDuration;
	i=60;
/*
1.�漰3G���û��Ľ�������޸�
20090901��a.��������޸Ķ���ֻ��186�û���3G�û���
b.��������:�����ؽ�����ε�0.02Ԫ/���ӣ����α��У���������

2.���ÿ����ν��� 0.12Ԫ/����
3.�������� 0.2Ԫ/����

//////////���Ϲ����Ѿ�����Ӧ�����ڵĴ������������Ϊ׼2016.01.29//////////

1.sCallType='01'�����б�������ҵӦ�ñ�ģ�iRate=20  ��������ҵӦ�ñ�ģ�iRate=50 
2.sCallType='02'��iRate=0 ��
*/	
	iCount=IsInNBR(Temp.sMsisdn);
	if(strcmp(Temp.sCallType,"02")==0) iRate=0;

	else if(strcmp(Temp.sCallType,"01")==0){
		
		if(iCount>0) iRate=20;
		else iRate=50;
	}
	else {
		/*Ԥ��*/
	}
	po->iSettMin=(Temp.iDuration+i-1)/i*i;
		
 	if(iSettFlag==0){/*����*/
 		iInFee=(po->iSettMin/i)*iRate;
 		iOutFee=0;
 	}
 	else{
  		iInFee=0;
 		iOutFee=(po->iSettMin/i)*iRate;
 	}
        
        sprintf(po->sInFee,                  "%12d",iInFee);
        sprintf(po->sOutFee,                 "%12d",iOutFee);
        
	strcpy(po->sServiceType,	"VIT");

	GetNbrType(po->sAccNbr,Temp.iCallingCarrierID,
		Temp.sHomeAreaCode,po->sNbrType);	
	GetNbrType(Temp.sOtherParty,Temp.iCalledCarrierID,
		Temp.sCalledCode,po->sOppNbrType);
	po->iOppCarrID=		Temp.iCalledCarrierID;
	strncpy(po->sOppArea,	Temp.sCalledCode,5);

	GetProvCode(po->sOppArea,po->sVisitAreaCode,po->sOppProv);

	GetAreaType(po->sHomeAreaCode,sType);

	if(strcmp(sType,"2")==0)
		GetBillingTypeID(po->sAccNbr,po->sBillingTypeID);

	if(strcmp(Temp.sCallType,"02")==0)strcpy(sCal,"2");
	else strcpy(sCal,"1");

	strncpy(sTemp,Temp.sStartTime+8,2);sTemp[2]=0;
	/*sprintf(po->sReserve1,"%5s%2s",	Temp.sCellID,sTemp);*/
	strcpy(po->sReserve1,	"");
	sprintf(po->sReserve2,"%1s%02d",	sCal,0);
	strncpy(po->sReserve3,		sRawMsisdn,10);
	strncpy(po->sSettItemDate,	Temp.sStartTime,8);
	strcpy(po->sBillingCycleID,	sBillingCycleID);
	
	return 0;

}
int TLR_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{

	int iCnt=1,iInFee=0,iOutFee=0,i,iRate=0;
	char sType[2],sTempAreaCode[9],sRawMsisdn[16],sCal[2];
	struct SttTicketStruct Temp;
	
	bzero((void*)po,sizeof(struct SettNbrStatStruct));
	
	mvitem_fmsttticket((struct FSttTicketStruct *)sOri,
		sizeof(struct FSttTicketStruct),&Temp);
	
	if(Temp.iTicketTypeID/10!=370)return 2;


	strcpy(po->sAccNbr,Temp.sMsisdn);
	strncpy(po->sHomeAreaCode,	Temp.sHomeAreaCode,5);
	GetProvCode(po->sHomeAreaCode,Temp.sVisitAreaCode,po->sProvCode);

	strcpy(sTempAreaCode,Temp.sVisitAreaCode);
	RegularAreaCode(sTempAreaCode);
	strncpy(po->sVisitAreaCode,	sTempAreaCode,5);
	strcpy(po->sNetType,		"GSM");

	po->iTicketTypeID=		Temp.iTicketTypeID;
	po->iCnt=			iCnt;
	po->iDuration=			Temp.iDuration;
/*
����  0.06/����
*/	i=60;
	iRate=60;
	po->iSettMin=(Temp.iDuration+i-1)/i*i;
		
	iInFee=0;
	iOutFee=(po->iSettMin/i)*iRate;	

        
        sprintf(po->sInFee,                  "%12d",iInFee);
        sprintf(po->sOutFee,                 "%12d",iOutFee);
        
	strcpy(po->sServiceType,	"TLR");

	GetNbrType(po->sAccNbr,Temp.iCallingCarrierID,
		Temp.sHomeAreaCode,po->sNbrType);	
	GetNbrType(Temp.sOtherParty,Temp.iCalledCarrierID,
		Temp.sCalledCode,po->sOppNbrType);
	po->iOppCarrID=		Temp.iCalledCarrierID;
	strncpy(po->sOppArea,	Temp.sCalledCode,5);

	GetProvCode(po->sOppArea,po->sVisitAreaCode,po->sOppProv);

	GetAreaType(po->sHomeAreaCode,sType);

	if(strcmp(sType,"2")==0)
		GetBillingTypeID(po->sAccNbr,po->sBillingTypeID);

	if(strcmp(Temp.sCallType,"02")==0)strcpy(sCal,"2");
	else strcpy(sCal,"1");

	i=GetSttRes(po->sAccNbr,po->sAccNbr,
		po->sHomeAreaCode,Temp.sStartTime,po->sReserve1);
	sprintf(po->sReserve2,"%1s%02d",	sCal,i);
	strcpy(po->sReserve3,		"");
	strncpy(po->sSettItemDate,	Temp.sStartTime,8);
	strcpy(po->sBillingCycleID,	sBillingCycleID);
	
	return 0;

}
int TLL_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{
	int iCnt=1,iInFee=0,iOutFee=0,i,iSettFlag=0,iRate=0,iSttFlag=1;
	int iCallingCarrierID=0,iCalledCarrierID=0;
	char sType[2],sTempAreaCode[9],sRawMsisdn[16],sRawOtherParty[25];
	char sCal[2],sOriAccNbr[25];
	struct SttTicketStruct Temp;
	
	bzero((void*)po,sizeof(struct SettNbrStatStruct));

/*
ע�⣬gsm��;����Ŀǰֻ��ʡ����ز��֣�
�굥��ʽ����ͼ��ʽת��TEMPLATE_STT_TICKET,TICKET_TYPE_ID����ͼ��д��

TLL_INTF_WJ_08		3717 ʡ��GSMרҵ�û���������䳤;����
TLL_INTF_WN_08		3711 ʡ��GSMרҵ�û������GSM��;����
VOIP193_INTF_08		3781 GSMʹ��VOIP��193����ר�ߺ�������ƽ̨ҵ���𻰵�
STT_SJ_WJ_08		3718 ʡ������������仰��	
STT_SJ_WN_08		3713 ʡ������������ڻ���(������) ��Ҫ��Ϊ���ۼ��˾�
BIL_SJ_WN_08		3713 ʡ������������ڻ���(�ƷѶ˾�)

����  0.06/����

�����ʵ�ʵĻ�����������ticket_type_id����������
�Ա��� ticket_type_id�ͺ�����Ӫ�ߵ�һ���ԡ�

*/
	
	mvitem_fmsttticket((struct FSttTicketStruct *)sOri,
		sizeof(struct FSttTicketStruct),&Temp);
	
	if(Temp.iTicketTypeID<=0)return 2;

	if(Temp.iTicketTypeID==3713&&
		strcmp(Temp.sReserve,"STT")==0){
		iSttFlag=-1;
	}
	else{
		iSttFlag=1;
	}
	
	NewGetRawNbr(Temp.sMsisdn,Temp.sHomeAreaCode,Temp.sStartTime,sRawMsisdn);
	NewGetRawNbr(Temp.sOtherParty,Temp.sCalledCode,Temp.sStartTime,sRawOtherParty);

	GetHeadCarr(Temp.sMsisdn,Temp.sMsisdn,
		"",Temp.sStartTime,&iCallingCarrierID);

	GetHeadCarr(Temp.sOtherParty,Temp.sOtherParty,
		"",Temp.sStartTime,&iCalledCarrierID);

	if(iCallingCarrierID==0)iCallingCarrierID=1;
	if(iCalledCarrierID==0)iCalledCarrierID=1;
	
	if(Temp.iTicketTypeID==3711||
		Temp.iTicketTypeID==3718||
		Temp.iTicketTypeID==3713||
		Temp.iTicketTypeID==3717){
	
		if(iCallingCarrierID==3&&
			iCalledCarrierID==3)Temp.iTicketTypeID=3711;
		else if(iCallingCarrierID!=3&&
			iCalledCarrierID!=3)Temp.iTicketTypeID=3718;
		else if(iCallingCarrierID!=3&&
			iCalledCarrierID==3)Temp.iTicketTypeID=3713;
		else if(iCallingCarrierID==3&&
			iCalledCarrierID!=3)Temp.iTicketTypeID=3717;
	}
	
	iSettFlag=(Temp.iTicketTypeID/10)%10;

	if(Temp.iTicketTypeID==3781)strcpy(sCal,"1");
	else strcpy(sCal,"2");
	
	
	if(strcmp(sRawMsisdn,"")==0)strcpy(sRawMsisdn,Temp.sMsisdn);
	if(strcmp(sRawOtherParty,"")==0)strcpy(sRawOtherParty,Temp.sOtherParty);
	
	if(strcmp(sCal,"1")==0){
		strcpy(po->sAccNbr,sRawMsisdn);
		strncpy(po->sHomeAreaCode,	Temp.sHomeAreaCode,5);
		GetProvCode(po->sHomeAreaCode,Temp.sVisitAreaCode,po->sProvCode);
		GetNbrType(sRawMsisdn,iCallingCarrierID,
			Temp.sHomeAreaCode,po->sNbrType);	
		GetNbrType(sRawOtherParty,iCalledCarrierID,
			Temp.sCalledCode,po->sOppNbrType);
		po->iOppCarrID=		iCalledCarrierID;
		strncpy(po->sOppArea,	Temp.sCalledCode,5);
		
		strcpy(sOriAccNbr,		Temp.sMsisdn);
	}
	else{
		strcpy(po->sAccNbr,sRawOtherParty);
		strncpy(po->sHomeAreaCode,	Temp.sCalledCode,5);
		GetProvCode(po->sHomeAreaCode,Temp.sVisitAreaCode,po->sProvCode);
		GetNbrType(sRawOtherParty,iCalledCarrierID,
			Temp.sCalledCode,po->sNbrType);	
		GetNbrType(sRawMsisdn,iCallingCarrierID,
			Temp.sHomeAreaCode,po->sOppNbrType);
		po->iOppCarrID=		iCallingCarrierID;
		strncpy(po->sOppArea,	Temp.sHomeAreaCode,5);
		strcpy(sOriAccNbr,		Temp.sOtherParty);
	}
	strcpy(sTempAreaCode,Temp.sVisitAreaCode);
	RegularAreaCode(sTempAreaCode);
	strncpy(po->sVisitAreaCode,	sTempAreaCode,5);
	strcpy(po->sNetType,		"GSM");

	po->iTicketTypeID=		Temp.iTicketTypeID;
	
	
	iCnt=1;
	iRate=60;
	i=60;
	
	po->iCnt=			iCnt*iSttFlag;
	po->iDuration=			Temp.iDuration*iSttFlag;
	po->iSettMin=(Temp.iDuration+i-1)/i*i*iSttFlag;
	
 	if(iSettFlag!=8){/*����*/
 		iInFee=(po->iSettMin/i)*iRate;
 		iOutFee=0;
 	}
 	else{
  		iInFee=0;
 		iOutFee=(po->iSettMin/i)*iRate;
 	}	
        
        sprintf(po->sInFee,                  "%12d",iInFee);
        sprintf(po->sOutFee,                 "%12d",iOutFee);
        
	strcpy(po->sServiceType,	"TLL");

	GetProvCode(po->sOppArea,po->sVisitAreaCode,po->sOppProv);
	
	GetAreaType(po->sHomeAreaCode,sType);

	if(strcmp(sType,"2")==0)
		GetBillingTypeID(po->sAccNbr,po->sBillingTypeID);

	i=GetSttRes(sOriAccNbr,po->sAccNbr,
		po->sHomeAreaCode,Temp.sStartTime,po->sReserve1);
	sprintf(po->sReserve2,"%1s%02d",	sCal,i);
	/*if(Temp.iTicketTypeID==3781)*/	
		strcpy(po->sReserve3,		Temp.sReserve);
	strncpy(po->sSettItemDate,	Temp.sStartTime,8);
	strcpy(po->sBillingCycleID,	sBillingCycleID);
	
	return 0;
}
int STP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{

	if(STT_DealRecord(sOri,sBillingCycleID,po)==2)return 2;
	strcpy(po->sNetType,"PSTN");
		
	return 0;
}
int TLP_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{

	int iCnt=1,iInFee=0,iOutFee=0,i,iSettFlag=0,iRate=0;
	char sType[2],sTempAreaCode[9],sRawMsisdn[16],sRawOtherParty[25];
	char sCal[2],sOriAccNbr[25];
	struct SttTicketStruct Temp;
	
	bzero((void*)po,sizeof(struct SettNbrStatStruct));

/*
ע�⣬������;����Ŀǰֻ��ʡ�ʡ����ʳ�;

1.���ڽӽ�  0.006/6��
2.���ڲ��й���  0.006/6��
3.���ڲ��й��� �������ʱ�international_sett_tariff

*/
	
	mvitem_fmsttticket((struct FSttTicketStruct *)sOri,
		sizeof(struct FSttTicketStruct),&Temp);
	
	if(Temp.iTicketTypeID<=0)return 2;

	iSettFlag=(Temp.iTicketTypeID/10)%10;

	NewGetRawNbr(Temp.sMsisdn,Temp.sHomeAreaCode,Temp.sStartTime,sRawMsisdn);
	NewGetRawNbr(Temp.sOtherParty,Temp.sCalledCode,Temp.sStartTime,sRawOtherParty);
	
	if(strcmp(sRawMsisdn,"")==0)strcpy(sRawMsisdn,Temp.sMsisdn);
	if(strcmp(sRawOtherParty,"")==0)strcpy(sRawOtherParty,Temp.sOtherParty);

	if(Temp.iCallingCarrierID==0)Temp.iCallingCarrierID=1;
	if(Temp.iCalledCarrierID==0)Temp.iCalledCarrierID=1;
		
	if(iSettFlag==0||iSettFlag==8){
		strcpy(po->sAccNbr,sRawMsisdn);
		strncpy(po->sHomeAreaCode,	Temp.sHomeAreaCode,5);
		GetProvCode(po->sHomeAreaCode,Temp.sVisitAreaCode,po->sProvCode);
		GetNbrType(sRawMsisdn,Temp.iCallingCarrierID,
			Temp.sHomeAreaCode,po->sNbrType);	
		GetNbrType(sRawOtherParty,Temp.iCalledCarrierID,
			Temp.sCalledCode,po->sOppNbrType);
		po->iOppCarrID=		Temp.iCalledCarrierID;
		strncpy(po->sOppArea,	Temp.sCalledCode,5);
		strcpy(sOriAccNbr,		Temp.sMsisdn);
		strcpy(sCal,"1");
	}
	else{
		strcpy(po->sAccNbr,sRawOtherParty);
		strncpy(po->sHomeAreaCode,	Temp.sCalledCode,5);
		GetProvCode(po->sHomeAreaCode,Temp.sVisitAreaCode,po->sProvCode);
		GetNbrType(sRawOtherParty,Temp.iCalledCarrierID,
			Temp.sCalledCode,po->sNbrType);	
		GetNbrType(sRawMsisdn,Temp.iCallingCarrierID,
			Temp.sHomeAreaCode,po->sOppNbrType);
		po->iOppCarrID=		Temp.iCallingCarrierID;
		strncpy(po->sOppArea,	Temp.sHomeAreaCode,5);
		strcpy(sOriAccNbr,		Temp.sOtherParty);	
		strcpy(sCal,"2");
	}
	strcpy(sTempAreaCode,Temp.sVisitAreaCode);
	RegularAreaCode(sTempAreaCode);
	strncpy(po->sVisitAreaCode,	sTempAreaCode,5);
	strcpy(po->sNetType,		"PSTN");

	po->iTicketTypeID=		Temp.iTicketTypeID;
	po->iCnt=			iCnt;
	po->iDuration=			Temp.iDuration;
	i=6;
	
	po->iSettMin=(Temp.iDuration+i-1)/i;
	
       	iInFee=Temp.iAddFee;
        iOutFee=Temp.iTollFee;
        
        if(po->iTicketTypeID==881||
		po->iTicketTypeID==882)iInFee=0;
        if(iInFee<0)iInFee=0;
        if(iOutFee<0)iOutFee=0;

        
        sprintf(po->sInFee,                  "%12d",iInFee);
        sprintf(po->sOutFee,                 "%12d",iOutFee);
        
	strcpy(po->sServiceType,	"TLP");

	GetProvCode(po->sOppArea,po->sVisitAreaCode,po->sOppProv);
	
	GetAreaType(po->sHomeAreaCode,sType);

	if(strcmp(sType,"2")==0)
		GetBillingTypeID(po->sAccNbr,po->sBillingTypeID);

	i=GetSttRes(sOriAccNbr,po->sAccNbr,
		po->sHomeAreaCode,Temp.sStartTime,po->sReserve1);
	sprintf(po->sReserve2,"%1s%02d",	sCal,i);
	strcpy(po->sReserve3,		"");
	strncpy(po->sSettItemDate,	Temp.sStartTime,8);
	strcpy(po->sBillingCycleID,	sBillingCycleID);
	
	return 0;
}
int SMS_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{
	printf("���������ڽ�����.....\n");
	return -1;
}
int SCX_DealRecord(char sOri[],
	char sBillingCycleID[],struct SettNbrStatStruct *po)
{
	int iCnt=1,iFlag=true,iRet,iOppCarrID=0;
	char sType[2],sTempAreaCode[9],sCalledCode[9];
	struct SmspTicketStruct Temp;
	
	bzero((void*)po,sizeof(struct SettNbrStatStruct));
	
	mvitem_fmsmspticket((struct FSmspTicketStruct *)sOri,
		sizeof(struct FSmspTicketStruct),&Temp);
	
	if(Temp.iTicketTypeID<=0)return 2;

	strcpy(po->sAccNbr,Temp.sMsisdn);

	if(GetHomeAreaCode(po->sAccNbr,"",Temp.sCityCode,
		iFlag,Temp.sStartTime,&iRet,po->sHomeAreaCode)==NOTFOUND)
		strcpy(po->sHomeAreaCode,	Temp.sCityCode);	
	
	GetProvCode(po->sHomeAreaCode,Temp.sCityCode,po->sProvCode);

	strcpy(sTempAreaCode,Temp.sCityCode);
	RegularAreaCode(sTempAreaCode);
	strncpy(po->sVisitAreaCode,	sTempAreaCode,5);
	strcpy(po->sNetType,		"GSM");

	po->iTicketTypeID=		Temp.iTicketTypeID;
	po->iCnt=			iCnt;
	po->iDuration=0;
	po->iSettMin=0;
		       
        sprintf(po->sInFee,                  "%s",Temp.sFee2);
        sprintf(po->sOutFee,                 "%s",Temp.sFee1);
        
	strcpy(po->sServiceType,	"SCX");

	GetNbrType(po->sAccNbr,0,po->sHomeAreaCode,po->sNbrType);
	
	if(GetCalledAreaCode(Temp.sCallType,Temp.sOtherParty,Temp.sCityCode,
		Temp.sStartTime,&iRet,sCalledCode)==NOTFOUND)
		strcpy(sCalledCode,	Temp.sCityCode);
			
	GetNbrType(Temp.sOtherParty,0,sCalledCode,po->sOppNbrType);
	
			
	GetHeadCarr(Temp.sOtherParty,Temp.sOtherParty,
		"",Temp.sStartTime,&iOppCarrID);
			
	po->iOppCarrID=		iOppCarrID;
	strncpy(po->sOppArea,	sCalledCode,5);

	GetProvCode(po->sOppArea,Temp.sCityCode,po->sOppProv);

	GetAreaType(po->sHomeAreaCode,sType);

	if(strcmp(sType,"2")==0)
		GetBillingTypeID(po->sAccNbr,po->sBillingTypeID);

	strcpy(po->sReserve1,		"");
/*
ȡ���ͱ�ʶ
  st_state	=trimcut(t_ori,97,1);
	
	opp_carrier_id=1;
	
	if(atoi(st_state)==0||
		atoi(st_state)==3||
		atoi(st_state)==5||
		atoi(st_state)==7)
		opp_carrier_id=0;
*/	
	if(strncmp(Temp.sSpAccNbr,"0",1)==0||
		strncmp(Temp.sSpAccNbr,"3",1)==0||
		strncmp(Temp.sSpAccNbr,"5",1)==0||
		strncmp(Temp.sSpAccNbr,"7",1)==0)	
		strcpy(sType,"0");
	else	strcpy(sType,"1");
	
	sprintf(po->sReserve2,"%1s%02d%1s",Temp.sCallType+1,0,sType);	
	strcpy(po->sReserve3,		"");
	strncpy(po->sSettItemDate,	Temp.sStartTime,8);
	strcpy(po->sBillingCycleID,	sBillingCycleID);
	
	return 0;
}

int main(int argc,char **argv)
{

	char sSouTableName[128],sCondition[256],sBillingCycleID[7];


	if(argc != 5&&argc != 6){
		printf("Usage %s tablename stattable wherecase billingcycleid intype[SMS|SCX|VIT|TLL(def=STT)]\n",argv[0]);
		exit(1);
	}

	InitAppRes(argv[0]);

	strcpy(sSouTableName,argv[1]);
	strcpy(STATCTL.sOutTableName,argv[2]);
	strcpy(sCondition,argv[3]);
	strcpy(sBillingCycleID,argv[4]);
	if(argc == 6){
		strcpy(STATCTL.InType,argv[5]);
		STATCTL.InType[3]=0;
	}
	else	strcpy(STATCTL.InType,"STT");
	
	if(ChkParamStr(sSouTableName,
		STATCTL.sOutTableName,sBillingCycleID)!=0)return -1;

	
	/*��ʼ������ָ��*/
	InitVisualFunc(STATCTL.InType);

	if(IniConnect("dataconnstr")<0){
		WriteAlertPrint("�������ݿ�ʧ��");
		return -1;
	}

	if(IsInTLL(STATCTL.InType)){
		if(CreateTable(sSouTableName,sCondition)<0)return -1;
	}
	
	if(XDealTicket(sSouTableName,sCondition,sBillingCycleID)<0){
		WriteAlertPrint("�Ա�%sͳ������%s��ͳ��ʧ��",
			sSouTableName,sCondition);
		return -1;
	}
	
/*��ͳ�����������ͳ�Ʊ�*/
	if(XStatData2Table()<0){
		WriteAlertPrint("�����ͳ�Ʊ�%sʧ��",STATCTL.sOutTableName);
		RollbackWork();
		return -1;
	}

	if(IsInTLL(STATCTL.InType)){
		if(TableExist(sSouTableName)==true){
                	if(DropTable(sSouTableName)<0)return -1;
        	}
	}

	
	WriteProcMsg("�Ա�%sͳ������%s��ͳ�ƽ���",sSouTableName,sCondition);
	printf("�Ա�%sͳ������%s��ͳ�ƽ���.\n",sSouTableName,sCondition);
	
	CommitWork();
	DestroyBin(pRoot);
	DisconnectDatabase();

	return 0;
}
