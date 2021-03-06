#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <datatype.h>
#include <wwsupp.h>

#include "spzb_supp.h"
#include "stt_ticket.h"
#include "ticket_field.h"

#define IS_UNICOMCDMA(x)      IsDpAccNbr("unicomcdma",x)

struct IntfCtlStruct
{
	int iHeadLen;

	char sFirstTabName[31];
	char sCondition[128];
	char sRefTabName[31];
	char sFileType[3];
	char sTargetPath[256];
	char sProvCode[4];
	char sFileSeq[5];
	char sBillingCycleID[7];
	char sFileDate[9];
	char sHeadG[512];
	char sHeadC[512];
	int iRate;
	struct FileControlStruct *pFileAllG;
	struct FileControlStruct *pFileAllC;
};

struct IntfCtlStruct INFCTL;

void ParseArg(int argc,char **argv);

BINTREE *pRoot=NULL;
BINTREE *pRootOut=NULL;

/*输出文件*/
int (*XWriteTargetFile)();
/*生成文件头记录记录*/
void (*XInitFileHead)();
/*处理话单到输出结构*/
int (*XDealTicket2Outlist)();

/***************************************************************************/
/**函数头文件定义区*/
/***************************************************************************/

int IsSpzbYS(char sFileType[]);
int IsSpzbRX(char sFileType[]);
int IsSpzbSJ(char sFileType[]);
int IsSpzbMX(char sFileType[]);
int IsSpzbTP(char sFileType[]);

int CheckType(char sType[]);
void AssignFileName(char sNetTpye[],char sTargetName[]);
void InitVisualFunc(char sFileType[]);

int YsSmsTicket2Outlist(char sTableName[],char sCondition[]);
int SmsBtoYsTicketUp(void **ppHead);
void GetSmsTicketB(struct SmsTicketStruct *pi,struct SmsTicketBStruct *po);
void Ys_InitFileHead();
int Ys_WriteTargetFile();
int GetYsFiletag(struct OutYsTicketUpStruct *pi);
int GetYsTicketUp(struct SmsTicketBStruct *pi,struct OutYsTicketUpStruct *po);
int GetYsTicketUpFile(void **ppHead);


int RxSmsTicket2Outlist(char sTableName[],char sCondition[]);
void Rx_InitFileHead();
int Rx_WriteTargetFile();
int CxDown2Bintree(BINTREE **ppRoot,char sTableName[]);
int GetRxTicketUp(struct SmsTicketStruct *pi,struct RxTicketUpStruct *po);
int GetRxFiletag(struct RxTicketUpStruct *pi);


void Sj_InitFileHead();
int Sj_WriteTargetFile();
int SjSpTicketSj2Outlist(char sTableName[],char sCondition[]);
int GetSjTicketUp(struct SpTicketSjStruct *pi,struct SjTicketUpStruct *po);
int GetSjTicketUpFile(void **ppHead);
int GetSjFiletag(struct SjTicketUpStruct *pi);


int YssjChk2Bintree(BINTREE **ppRoot,char sTableName[]);

void Mx_InitFileHead();
int Mx_WriteTargetFile();
int MxTicketUp2Outlist(char sTableName[],char sCondition[]);
int GetMxFiletag(struct MxTicketUpStruct *pi);

void Tp_InitFileHead();
int Tp_WriteTargetFile();
int TpTicketUp2Outlist(char sTableName[],char sCondition[]);
int GetTpFiletag(struct TpTicketUpStruct *pi);

/*-------------------------------------*/
int IsSpzbYS(char sFileType[])
{
	if(strcmp(sFileType,"YS")==0) return true;
	return false;
}


int YsSmsTicket2Outlist(char sTableName[],char sCondition[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct SmsTicketStruct Temp;
        static struct SmsTicketStructIn TempIn;

	struct SmsTicketBStruct TempB;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
        	strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetSmsTicketToStruct(&Temp,&TempIn)){

		if(ChkSpCode(Temp.sSpCode,Temp.sSpAccNbr,"")<0)continue;
        /*把sp_acc_nbr和sp_service_code对换*/
        	SetSpAccNbr(&Temp);
		
		GetSmsTicketB(&Temp,&TempB);

                if(InsertBin(&pRoot,&TempB,
			data_search_bintree_smsb_e,
			assign_insert_bintree_smsb_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
		if((++iCnt%30000)==0)
			WriteProcMsg("表%s当前话单数为%d",sTableName,iCnt);

        }

        WriteProcMsg("成功加载表%s 话单数%d条",sTableName,iCnt);

/**取得上传总部结构**/
        TravelBin(pRoot,SmsBtoYsTicketUp);

/**取得输出文件**/
	TravelBin(pRootOut,GetYsTicketUpFile);

	return 0;
}

int SmsBtoYsTicketUp(void **ppHead)
{

	struct SmsTicketBStruct *ptHead=(*ppHead),*pTemp;
	struct OutYsTicketUpStruct Temp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(GetYsTicketUp(pTemp,&Temp)<0) return -1;

                if(InsertBin(&pRootOut,&Temp,
			data_search_bintree_ysup_e,
			assign_insert_bintree_ysup_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}


	}

	return 0;
}

void Ys_InitFileHead()
{
	int iFileSeq;
	char sDateTime[15];
	struct YsTicketUpHeadStruct *po=(struct YsTicketUpHeadStruct *)INFCTL.sHeadG;

	/*初始化文件头*/
	INFCTL.iHeadLen=sizeof(struct YsTicketUpHeadStruct);
	bzero((void*)po,INFCTL.iHeadLen);

	GetHostTime(sDateTime);

	strncpy(INFCTL.sFileDate,sDateTime,8);INFCTL.sFileDate[8]=0;

	iFileSeq=atoi(INFCTL.sFileSeq);
	sprintf(po->sFileSeq,"%04d",iFileSeq);
	strcpy(po->sFileVersion,"01");
	strcpy(po->sFileCreatDate,INFCTL.sFileDate);
	strcpy(po->sProvCode,INFCTL.sProvCode);
	strcpy(po->sBillingCycleID,INFCTL.sBillingCycleID);

	sprintf(po->sTotalCnt,		"%010d",0);
	sprintf(po->sTotalHdCnt,	"%010d",0);
	sprintf(po->sTotalFee,		"%015d",0);
	sprintf(po->sTotalMoCnt,	"%010d",0);
	sprintf(po->sTotalMtCnt,	"%010d",0);
	sprintf(po->sTotalH20Cnt,	"%010d",0);
	sprintf(po->sTotalH20Fee,	"%010d",0);
	LeftPad(po->sReserv2,18,' ');

	memcpy((void*)INFCTL.sHeadC,(void*)INFCTL.sHeadG,512);


}
int GetYsFiletag(struct OutYsTicketUpStruct *pi)
{/*数据移动部分*/

	int iTotalCntG=0,iTotalCntC=0,iHeadLen=0;
	int iTotalHdCnt,iTotalFee,iTotalMoCnt,iTotalMtCnt;
	int iTotalH20Fee,iTotalH20Cnt;

	struct YsTicketUpHeadStruct *pFileHeadG=NULL,*pFileHeadC=NULL;
	struct FYsTicketUpStruct YsFile;

	pFileHeadG=(struct YsTicketUpHeadStruct *)INFCTL.sHeadG;
	pFileHeadC=(struct YsTicketUpHeadStruct *)INFCTL.sHeadC;

	mvitem_mfysticketup(pi,&YsFile);
	iHeadLen=sizeof(struct FYsTicketUpStruct);

	/*支持扩位前的程序*/
/*	{
	int i;
	char *pc=(char*)&YsFile;

	for(i=17;i<iHeadLen;i++)pc[i-3]=pc[i];
	iHeadLen=iHeadLen-3;
	}	
*/
		if(strncmp(pi->sOutFileName+2,"C",1)==0){

			iTotalCntC    	=atoi(pFileHeadC->sTotalCnt)  +1;
			iTotalHdCnt    	=atoi(pFileHeadC->sTotalHdCnt)  +atoi(pi->sYsHdCnt);
			iTotalFee       =atoi(pFileHeadC->sTotalFee)    +atoi(pi->sYsFee);
			iTotalMoCnt     =atoi(pFileHeadC->sTotalMoCnt)  +atoi(pi->sMoCnt);
			iTotalMtCnt	=atoi(pFileHeadC->sTotalMtCnt)  +atoi(pi->sMtCnt);
			iTotalH20Cnt    =atoi(pFileHeadC->sTotalH20Cnt) +atoi(pi->sH20Cnt);
			iTotalH20Fee	=atoi(pFileHeadC->sTotalH20Fee) +atoi(pi->sH20Fee);

			sprintf(pFileHeadC->sTotalCnt,		"%010d",iTotalCntC);
			sprintf(pFileHeadC->sTotalHdCnt,	"%010d",iTotalHdCnt);
			sprintf(pFileHeadC->sTotalFee,		"%015d",iTotalFee);
			sprintf(pFileHeadC->sTotalMoCnt,	"%010d",iTotalMoCnt);
			sprintf(pFileHeadC->sTotalMtCnt,	"%010d",iTotalMtCnt);
			sprintf(pFileHeadC->sTotalH20Cnt,	"%010d",iTotalH20Cnt);
			sprintf(pFileHeadC->sTotalH20Fee,	"%010d",iTotalH20Fee);

			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllC,(void *)&YsFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}

		}
		else{
			iTotalCntG    	=atoi(pFileHeadG->sTotalCnt)  +1;
			iTotalHdCnt    	=atoi(pFileHeadG->sTotalHdCnt)  +atoi(pi->sYsHdCnt);
			iTotalFee       =atoi(pFileHeadG->sTotalFee)    +atoi(pi->sYsFee);
			iTotalMoCnt     =atoi(pFileHeadG->sTotalMoCnt)  +atoi(pi->sMoCnt);
			iTotalMtCnt	=atoi(pFileHeadG->sTotalMtCnt)  +atoi(pi->sMtCnt);
			iTotalH20Cnt    =atoi(pFileHeadG->sTotalH20Cnt) +atoi(pi->sH20Cnt);
			iTotalH20Fee	=atoi(pFileHeadG->sTotalH20Fee) +atoi(pi->sH20Fee);

			sprintf(pFileHeadG->sTotalCnt,		"%010d",iTotalCntG);
			sprintf(pFileHeadG->sTotalHdCnt,	"%010d",iTotalHdCnt);
			sprintf(pFileHeadG->sTotalFee,		"%015d",iTotalFee);
			sprintf(pFileHeadG->sTotalMoCnt,	"%010d",iTotalMoCnt);
			sprintf(pFileHeadG->sTotalMtCnt,	"%010d",iTotalMtCnt);
			sprintf(pFileHeadG->sTotalH20Cnt,	"%010d",iTotalH20Cnt);
			sprintf(pFileHeadG->sTotalH20Fee,	"%010d",iTotalH20Fee);

			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllG,(void *)&YsFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}
		}

	return 0;

}
int GetYsTicketUp(struct SmsTicketBStruct *pi,struct OutYsTicketUpStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct OutYsTicketUpStruct));

		strcpy(po->sSpCode,		pi->sSpCode);
		strcpy(po->sSpAccNbr,		pi->sSpAccNbr);
		strcpy(po->sSpServiceType,	pi->sSpServiceType);
		strcpy(po->sCityCode,		pi->sCityCode);

		AssignFileName(pi->sNetTpye,po->sOutFileName);

		strcpy(po->sYsHdCnt,		pi->sYsHdCnt);
		strcpy(po->sYsFee,		pi->sYsFee);
		strcpy(po->sMoCnt,		pi->sMoCnt);
		strcpy(po->sMtCnt,		pi->sMtCnt);

		if(atoi(pi->sYsHdCnt)>20){
			sprintf(po->sH20Cnt,"%010d",atoi(pi->sYsHdCnt));
			sprintf(po->sH20Fee,"%010d",atoi(pi->sYsFee));
		}
		else{
			sprintf(po->sH20Cnt,		        "%010d",0);
			sprintf(po->sH20Fee,		        "%010d",0);
		}
	return 0;

}
int GetYsTicketUpFile(void **ppHead)
{

	struct OutYsTicketUpStruct *ptHead=(*ppHead),*pTemp;

/*取得文件体等*/
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(GetYsFiletag(pTemp)<0) return -1;
	}

	return 0;
}
void GetSmsTicketB(struct SmsTicketStruct *pi,struct SmsTicketBStruct *po)
{/*数据移动部分*/

	int iYsHdCnt=0,iYsFee=0,iMoCnt=0,iMtCnt=0;
	char sHomeAreaCode[5];

	struct SpContactRelationStruct *pS=NULL;
	
	bzero((void*)po,sizeof(struct SmsTicketBStruct));
		
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sSpCode,		pi->sSpCode,5);
		strncpy(po->sSpAccNbr,		pi->sSpAccNbr,12);
		
		if(strlen(pi->sSpProvCode)>0){
			strncpy(po->sSpServiceType,pi->sSpProvCode,2);
		}
		else{
			if(SearchSpContactRelation(pi->sSpCode,
				"",pi->sSpAccNbr,pi->sStartTime,&pS)==NOTFOUND)
				strcpy(po->sSpServiceType,"90");
			else	strcpy(po->sSpServiceType,pS->sServiceType);
		}
/* 		
		if(strcmp(pi->sSpCode,"90022")==0){
			if(SearchSpContactRelation(pi->sSpCode,
				pi->sSpServiceCode,"",
				pi->sStartTime,&pS)==NOTFOUND)
				strcpy(po->sSpServiceType,"90");
			else	strcpy(po->sSpServiceType,pS->sServiceType);
		}
*/
		SetHomeAreaCode(pi->sHomeAreaCode,sHomeAreaCode);

		if(GetCityCode(sHomeAreaCode,po->sCityCode)==NOTFOUND)
			strcpy(po->sCityCode,"380");

		if(IS_UNICOMCDMA(pi->sMsisdn))
			strcpy(po->sNetTpye,"C");
		else
			strcpy(po->sNetTpye,"G");

		if(pi->iInfoFee>0||pi->iRentFee>0){
			iYsHdCnt=1;
			iYsFee=pi->iInfoFee+pi->iRentFee;
		}

		if(strncmp(po->sSpServiceType,"90",2)==0){
			if(strcmp(pi->sCallType,"07")==0)iMoCnt=1;
			else	iMtCnt=1;
		}

		sprintf(po->sYsHdCnt,			"%010d",iYsHdCnt);
		sprintf(po->sYsFee,		        "%015d",iYsFee);
		sprintf(po->sMoCnt,		        "%010d",iMoCnt);
		sprintf(po->sMtCnt,		        "%010d",iMtCnt);

		strncpy(po->sChkDate,		pi->sStartTime,10);
		po->sChkDate[10]=0;

}

int Ys_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256],OutFileName[256];

	struct FYsTicketUpHeadStruct FileHead;

	iHeadLen=sizeof(struct FYsTicketUpHeadStruct);
	
	if(iHeadLen>0){
		
		memset(&FileHead,0,sizeof(struct FYsTicketUpHeadStruct));
		mvitem_mfysticketuphead(
			(struct YsTicketUpHeadStruct *)INFCTL.sHeadG,&FileHead);
	
		
		if(item2list(&INFCTL.pFileAllG,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
		memset(&FileHead,0,sizeof(struct FYsTicketUpHeadStruct));
		mvitem_mfysticketuphead(
			(struct YsTicketUpHeadStruct *)INFCTL.sHeadC,&FileHead);

		if(item2list(&INFCTL.pFileAllC,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
	}

	AssignFileName("G",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	if(list2filelrn(&INFCTL.pFileAllG,sTargetName)<0)return -1;

	AssignFileName("C",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	return list2filelrn(&INFCTL.pFileAllC,sTargetName);
}

int IsSpzbRX(char sFileType[])
{
	if(strcmp(sFileType,"RX")==0) return true;
	return false;
}

void Rx_InitFileHead()
{
	int iFileSeq;
	char sDateTime[15];
	struct RxTicketUpHeadStruct *po=(struct RxTicketUpHeadStruct *)INFCTL.sHeadG;

	/*初始化文件头*/
	INFCTL.iHeadLen=sizeof(struct RxTicketUpHeadStruct);
	bzero((void*)po,INFCTL.iHeadLen);

	GetHostTime(sDateTime);

	strncpy(INFCTL.sFileDate,sDateTime,8);INFCTL.sFileDate[8]=0;

	iFileSeq=atoi(INFCTL.sFileSeq);
	sprintf(po->sFileSeq,"%04d",iFileSeq);
	strcpy(po->sFileVersion,"01");
	strcpy(po->sFileCreatDate,INFCTL.sFileDate);
	strcpy(po->sProvCode,INFCTL.sProvCode);
	strcpy(po->sBillingCycleID,INFCTL.sBillingCycleID);

	sprintf(po->sTotalRxCnt,	"%010d",0);
	sprintf(po->sTotalRxFee,	"%015d",0);
	LeftPad(po->sReserv,79,' ');

	memcpy((void*)INFCTL.sHeadC,(void*)INFCTL.sHeadG,512);

}

int RxSmsTicket2Outlist(char sTableName[],char sCondition[])
{
	int iCnt=0,iTotalCnt=0;
	static int iFirstFlag=true;
        static struct SmsTicketStruct Temp;
        static struct SmsTicketStructIn TempIn;

/*	struct CxTicketDownStruct S,*pTemp;*/

	struct RxTicketUpStruct TempRx;

/*	BINTREE *pRootCX=NULL;*/
/*加载总部下发触发剔除话单接口表*/

/*	if(CxDown2Bintree(&pRootCX,INFCTL.sRefTabName)<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}
*/
	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
        	strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetSmsTicketToStruct(&Temp,&TempIn)){
		iTotalCnt++;
		
		if(ChkSpCode(Temp.sSpCode,Temp.sSpAccNbr,"")<0)continue;
        /*把sp_acc_nbr和sp_service_code对换*/
        	SetSpAccNbr(&Temp);
		
/*		GetCxDown(&Temp,&S);*/
		
/*未找到记录则丢弃*/
/*		if((SearchBin(pRootCX,(void*)&S,
			data_search_bintree_cx_down_e,
			(void**)&pTemp))==NOTFOUND)continue;*/
/*找到记录则输出*/
		if(GetRxTicketUp(&Temp,&TempRx)<0)continue;

		if(GetRxFiletag(&TempRx)<0)continue;

		if((++iCnt%10000)==0)
			WriteProcMsg("表%s当前话单数为%d,有效话单为%d",sTableName,iTotalCnt,iCnt);

        }

        if(INFCTL.pFileAllC!=NULL)ReverseList((LIST**)&INFCTL.pFileAllC);    
	if(INFCTL.pFileAllG!=NULL)ReverseList((LIST**)&INFCTL.pFileAllG);
	
        WriteProcMsg("表%s当前话单数为%d,有效话单为%d",sTableName,iTotalCnt,iCnt);
	return 0;
}

int GetRxTicketUp(struct SmsTicketStruct *pi,struct RxTicketUpStruct *po)
{/*数据移动部分*/
	char sHomeAreaCode[5];
	
	struct SpContactRelationStruct *pS=NULL;
	
	bzero((void*)po,sizeof(struct RxTicketUpStruct));

		strcpy(po->sSpCode,		pi->sSpCode);
		strcpy(po->sSpServiceCode,	pi->sSpServiceCode);
		strcpy(po->sSpAccNbr,		pi->sSpAccNbr);


		if(strlen(pi->sSpProvCode)>0){
			strncpy(po->sServiceType,pi->sSpProvCode,2);
		}
		else{
			if(SearchSpContactRelation(pi->sSpCode,
				"",pi->sSpAccNbr,pi->sStartTime,&pS)==NOTFOUND)
				strcpy(po->sServiceType,"90");
			else	strcpy(po->sServiceType,pS->sServiceType);
		}

		if(strcmp(pi->sCallType,"07")==0)strcpy(po->sTicketType,"00");
		else	strcpy(po->sTicketType,"01");

		strcpy(po->sMsisdn,		pi->sMsisdn);
		Fmt86A13(po->sMsisdn);

		if(IS_UNICOMCDMA(po->sMsisdn))
			strcpy(po->sUserType,"C");
		else
			strcpy(po->sUserType,"G");

		SetHomeAreaCode(pi->sHomeAreaCode,sHomeAreaCode);
		
		if(GetCityCode(sHomeAreaCode,po->sVisitCityCode)==NOTFOUND){
			strcpy(po->sVisitCityCode,"380");
		}

		sprintf(po->sInfoFee,"%06d",pi->iInfoFee+pi->iRentFee);

		strcpy(po->sRecvTime,pi->sStartTime);
		AddTimes(po->sRecvTime,-10);

		strcpy(po->sDoneTime,pi->sStartTime);

		if(strcmp(pi->sHomeProvCode,"998")==0)
			strcpy(po->sRxReason,"999");
		else
			strcpy(po->sRxReason,pi->sHomeProvCode);


	return 0;

}

int GetRxFiletag(struct RxTicketUpStruct *pi)
{/*数据移动部分*/

	int iTotalRxCnt,iTotalRxFee,iHeadLen=0;

	struct RxTicketUpHeadStruct *pFileHeadG=NULL,*pFileHeadC=NULL;
	struct FRxTicketUpStruct RxFile;

	pFileHeadG=(struct RxTicketUpHeadStruct *)INFCTL.sHeadG;
	pFileHeadC=(struct RxTicketUpHeadStruct *)INFCTL.sHeadC;

	iHeadLen=sizeof(struct FRxTicketUpStruct);

		if(strncmp(pi->sUserType,"C",1)==0){
			
			
			strcpy(pi->sUserType,"0");
			iTotalRxCnt    	=atoi(pFileHeadC->sTotalRxCnt)  +1;
			iTotalRxFee    	=atoi(pFileHeadC->sTotalRxFee)  +atoi(pi->sInfoFee);

			sprintf(pFileHeadC->sTotalRxCnt,	"%010d",iTotalRxCnt);
			sprintf(pFileHeadC->sTotalRxFee,	"%015d",iTotalRxFee);

			sprintf(pi->sTicketSeq,"%d",iTotalRxCnt);
			mvitem_mfrxticketup(pi,&RxFile);
			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllC,(void *)&RxFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}
		}
		else{
			strcpy(pi->sUserType,"0");
			iTotalRxCnt    	=atoi(pFileHeadG->sTotalRxCnt)  +1;
			iTotalRxFee    	=atoi(pFileHeadG->sTotalRxFee)  +atoi(pi->sInfoFee);

			sprintf(pFileHeadG->sTotalRxCnt,	"%010d",iTotalRxCnt);
			sprintf(pFileHeadG->sTotalRxFee,	"%015d",iTotalRxFee);

			sprintf(pi->sTicketSeq,"%d",iTotalRxCnt);
			mvitem_mfrxticketup(pi,&RxFile);
			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllG,(void *)&RxFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}
		}

	return 0;

}

int CxDown2Bintree(BINTREE **ppRoot,char sTableName[])
{
	int iCnt=0;

	static int iFirstFlag=true;
        static struct CxTicketDownStruct Temp;
        static struct CxTicketDownStructIn TempIn;
	struct CxTicketDownStruct *pTemp=NULL;
	
	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;

        	strcpy(TempIn.sTableName,sTableName);
        	sprintf(TempIn.sCondition,
        		"WHERE BILLING_CYCLE_ID='%s'",INFCTL.sBillingCycleID);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetCxTicketDownToStruct(&Temp,&TempIn)){

	        if((pTemp=malloc(sizeof(struct CxTicketDownStruct)))==NULL){
	                printf("分配内存失败CxTicketDownStruct.\n");
	                return -1;
	        }
		memcpy((void*)pTemp,(void*)&Temp,sizeof(struct CxTicketDownStruct));
        	
		/*插入CxTicketDownStruct*/
                if(InsertBin(ppRoot,(void*)pTemp,
			data_search_bintree_cx_down_e,
			assign_insert_bintree)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
		iCnt++;
        }
        WriteProcMsg("成功加载表%s 记录数%d条",TempIn.sTableName,iCnt);
	return 0;
}


int Rx_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256],OutFileName[256];

	struct FRxTicketUpHeadStruct FileHead;

	iHeadLen=sizeof(struct FRxTicketUpHeadStruct);
	
	if(iHeadLen>0){
		
		memset(&FileHead,0,sizeof(struct FRxTicketUpHeadStruct));
		mvitem_mfrxticketuphead(
			(struct RxTicketUpHeadStruct *)INFCTL.sHeadG,&FileHead);
	
		
		if(item2list(&INFCTL.pFileAllG,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
		memset(&FileHead,0,sizeof(struct FRxTicketUpHeadStruct));
		mvitem_mfrxticketuphead(
			(struct RxTicketUpHeadStruct *)INFCTL.sHeadC,&FileHead);

		if(item2list(&INFCTL.pFileAllC,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
	}

	AssignFileName("G",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	if(list2filelrn(&INFCTL.pFileAllG,sTargetName)<0)return -1;

	AssignFileName("C",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	return list2filelrn(&INFCTL.pFileAllC,sTargetName);
}


int IsSpzbSJ(char sFileType[])
{
	if(strcmp(sFileType,"SJ")==0) return true;
	return false;
}

void Sj_InitFileHead()
{
	int iFileSeq;
	char sDateTime[15];
	struct SjTicketUpHeadStruct *po=(struct SjTicketUpHeadStruct *)INFCTL.sHeadG;

	/*初始化文件头*/
	INFCTL.iHeadLen=sizeof(struct SjTicketUpHeadStruct);
	bzero((void*)po,INFCTL.iHeadLen);

	GetHostTime(sDateTime);

	strncpy(INFCTL.sFileDate,sDateTime,8);INFCTL.sFileDate[8]=0;

	iFileSeq=atoi(INFCTL.sFileSeq);
	sprintf(po->sFileSeq,"%04d",iFileSeq);
	strcpy(po->sFileVersion,"01");
	strcpy(po->sFileCreatDate,INFCTL.sFileDate);
	strcpy(po->sProvCode,INFCTL.sProvCode);
	strcpy(po->sBillingCycleID,INFCTL.sBillingCycleID);

	sprintf(po->sTotalCnt,		"%010d",0);
	sprintf(po->sTotalHdCnt,	"%010d",0);
	sprintf(po->sTotalFee,		"%015d",0);
	sprintf(po->sTotalTpFee,	"%010d",0);
	sprintf(po->sTotalRenegeFee,	"%010d",0);
	sprintf(po->sTotalAdjustFee,	"%010d",0);

	LeftPad(po->sReserv3,10,' ');
	LeftPad(po->sReserv4,18,' ');

	memcpy((void*)INFCTL.sHeadC,(void*)INFCTL.sHeadG,512);

}

int SjSpTicketSj2Outlist(char sTableName[],char sCondition[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct SpTicketSjStruct Temp;
        static struct SpTicketSjStructIn TempIn;

	struct SjTicketUpStruct TempSJ;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
        	strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetSpTicketSjToStruct(&Temp,&TempIn)){

		if(ChkSpCode(Temp.sSpCode,Temp.sSpAccNbr,"")<0)continue;
		
		if(GetSjTicketUp(&Temp,&TempSJ)<0)continue;

                if(InsertBin(&pRoot,&TempSJ,
			data_search_bintree_spsj_e,
			assign_insert_bintree_spsj_e)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
		if((++iCnt%30000)==0)
			WriteProcMsg("表%s当前话单数为%d",sTableName,iCnt);

        }

        WriteProcMsg("成功加载表%s 话单数%d条",sTableName,iCnt);

/**取得输出文件**/
	TravelBin(pRoot,GetSjTicketUpFile);

	return 0;
}

int GetSjTicketUp(struct SpTicketSjStruct *pi,struct SjTicketUpStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct SjTicketUpStruct));

		strncpy(po->sSpCode,pi->sSpCode,5);po->sSpCode[5]=0;
		strncpy(po->sSpAccNbr,pi->sSpAccNbr,12);po->sSpAccNbr[12]=0;
		strcpy(po->sSpServiceType,	pi->sSpServiceType);

		if(GetCityCode(pi->sHomeAreaCode,po->sCityCode)==NOTFOUND){
			strcpy(po->sCityCode,"380");
		}

		sprintf(po->sSjHdCnt,"%010d",pi->iSjHdCnt);
		sprintf(po->sSjFee,"%015d",pi->iSjFee);
		sprintf(po->sTpFee,"%010d",pi->iTpFee);
		sprintf(po->sRenegeFee,"%010d",pi->iRenegeFee);
		sprintf(po->sAdjustFee,"%010d",pi->iAdjustFee);

/*sReserv6,用于区分G&C的统计记录,输出的时候要清空*/
		if(IS_UNICOMCDMA(pi->sMsisdn))
			strcpy(po->sReserv6,"C");
		else
			strcpy(po->sReserv6,"G");

	return 0;

}
int GetSjTicketUpFile(void **ppHead)
{

	struct SjTicketUpStruct *ptHead=(*ppHead),*pTemp;

/*取得文件体等*/
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(GetSjFiletag(pTemp)<0) return -1;
	}

	return 0;
}

int GetSjFiletag(struct SjTicketUpStruct *pi)
{/*数据移动部分*/

	int iTotalCntG=0,iTotalCntC=0,iHeadLen=0;
	int iTotalHdCnt,iTotalFee,iTotalTpFee,iTotalRenegeFee,iTotalAdjustFee;

	struct SjTicketUpHeadStruct *pFileHeadG=NULL,*pFileHeadC=NULL;
	struct FSjTicketUpStruct SjFile;

	pFileHeadG=(struct SjTicketUpHeadStruct *)INFCTL.sHeadG;
	pFileHeadC=(struct SjTicketUpHeadStruct *)INFCTL.sHeadC;

	iHeadLen=sizeof(struct FSjTicketUpStruct);

		if(strncmp(pi->sReserv6,"C",1)==0){

			iTotalCntC    	=atoi(pFileHeadC->sTotalCnt)  +1;
			iTotalHdCnt    	=atoi(pFileHeadC->sTotalHdCnt)  +atoi(pi->sSjHdCnt);
			iTotalFee       =atoi(pFileHeadC->sTotalFee)    +atoi(pi->sSjFee);
			iTotalTpFee     =atoi(pFileHeadC->sTotalTpFee)  +atoi(pi->sTpFee);
			iTotalRenegeFee =atoi(pFileHeadC->sTotalRenegeFee)  +atoi(pi->sRenegeFee);
			iTotalAdjustFee =atoi(pFileHeadC->sTotalAdjustFee)  +atoi(pi->sAdjustFee);

			sprintf(pFileHeadC->sTotalCnt,		"%010d",iTotalCntC);
			sprintf(pFileHeadC->sTotalHdCnt,	"%010d",iTotalHdCnt);
			sprintf(pFileHeadC->sTotalFee,		"%015d",iTotalFee);
			sprintf(pFileHeadC->sTotalTpFee,	"%010d",iTotalTpFee);
			sprintf(pFileHeadC->sTotalRenegeFee,	"%010d",iTotalRenegeFee);
			sprintf(pFileHeadC->sTotalAdjustFee,	"%010d",iTotalAdjustFee);

			/*sReserv6,用于区分G&C的统计记录,输出的时候要清空*/
			strcpy(pi->sReserv6,"");
			mvitem_mfsjticketup(pi,&SjFile);
			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllC,(void *)&SjFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}

		}
		else{
			iTotalCntG    	=atoi(pFileHeadG->sTotalCnt)  +1;
			iTotalHdCnt    	=atoi(pFileHeadG->sTotalHdCnt)  +atoi(pi->sSjHdCnt);
			iTotalFee       =atoi(pFileHeadG->sTotalFee)    +atoi(pi->sSjFee);
			iTotalTpFee     =atoi(pFileHeadG->sTotalTpFee)  +atoi(pi->sTpFee);
			iTotalRenegeFee =atoi(pFileHeadG->sTotalRenegeFee)  +atoi(pi->sRenegeFee);
			iTotalAdjustFee =atoi(pFileHeadG->sTotalAdjustFee)  +atoi(pi->sAdjustFee);

			sprintf(pFileHeadG->sTotalCnt,		"%010d",iTotalCntG);
			sprintf(pFileHeadG->sTotalHdCnt,	"%010d",iTotalHdCnt);
			sprintf(pFileHeadG->sTotalFee,		"%015d",iTotalFee);
			sprintf(pFileHeadG->sTotalTpFee,	"%010d",iTotalTpFee);
			sprintf(pFileHeadG->sTotalRenegeFee,	"%010d",iTotalRenegeFee);
			sprintf(pFileHeadG->sTotalAdjustFee,	"%010d",iTotalAdjustFee);

			/*sReserv6,用于区分G&C的统计记录,输出的时候要清空*/
			strcpy(pi->sReserv6,"");
			mvitem_mfsjticketup(pi,&SjFile);
			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllG,(void *)&SjFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}
		}

	return 0;

}

int Sj_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256],OutFileName[256];

	struct FSjTicketUpHeadStruct FileHead;

	iHeadLen=sizeof(struct FSjTicketUpHeadStruct);
	
	if(iHeadLen>0){
		
		memset(&FileHead,0,sizeof(struct FSjTicketUpHeadStruct));
		mvitem_mfsjticketuphead(
			(struct SjTicketUpHeadStruct *)INFCTL.sHeadG,&FileHead);
	
		
		if(item2list(&INFCTL.pFileAllG,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
		memset(&FileHead,0,sizeof(struct FSjTicketUpHeadStruct));
		mvitem_mfsjticketuphead(
			(struct SjTicketUpHeadStruct *)INFCTL.sHeadC,&FileHead);

		if(item2list(&INFCTL.pFileAllC,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
	}

	AssignFileName("G",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	if(list2filelrn(&INFCTL.pFileAllG,sTargetName)<0)return -1;

	AssignFileName("C",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	return list2filelrn(&INFCTL.pFileAllC,sTargetName);
}

int IsSpzbMX(char sFileType[])
{
	if(strcmp(sFileType,"MX")==0) return true;
	return false;
}
void Mx_InitFileHead()
{
	int iFileSeq;
	char sDateTime[15];
	struct MxTicketUpHeadStruct *po=(struct MxTicketUpHeadStruct *)INFCTL.sHeadG;

	/*初始化文件头*/
	INFCTL.iHeadLen=sizeof(struct MxTicketUpHeadStruct);
	bzero((void*)po,INFCTL.iHeadLen);

	GetHostTime(sDateTime);

	strncpy(INFCTL.sFileDate,sDateTime,8);INFCTL.sFileDate[8]=0;

	iFileSeq=atoi(INFCTL.sFileSeq);
	sprintf(po->sFileSeq,"%04d",iFileSeq);
	strcpy(po->sFileVersion,"01");
	strcpy(po->sFileCreatDate,INFCTL.sFileDate);
	strcpy(po->sProvCode,INFCTL.sProvCode);
	strcpy(po->sBillingCycleID,INFCTL.sBillingCycleID);

	sprintf(po->sTotalCnt,		"%010d",0);
	sprintf(po->sMxFee,		"%010d",0);

	LeftPad(po->sReserv1,10,' ');
	LeftPad(po->sReserv2,15,' ');

	memcpy((void*)INFCTL.sHeadC,(void*)INFCTL.sHeadG,512);

}

int YssjChk2Bintree(BINTREE **ppRoot,char sTableName[])
{
	int iCnt=0;

	static int iFirstFlag=true;
        static struct YssjChkStruct Temp;
        static struct YssjChkStructIn TempIn;
        struct YssjChkStruct	*pTemp=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;

        	strcpy(TempIn.sTableName,sTableName);
        	sprintf(TempIn.sCondition,
        		"WHERE RATE>%d ",INFCTL.iRate);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetYssjChkToStruct(&Temp,&TempIn)){
	        if((pTemp=malloc(sizeof(struct YssjChkStruct)))==NULL){
	                printf("分配内存失败YssjChkStruct.\n");
	                return -1;
	        }
		memcpy((void*)pTemp,(void*)&Temp,sizeof(struct YssjChkStruct));
        	
		/*插入YssjChkStruct*/
                if(InsertBin(ppRoot,(void*)pTemp,
			data_search_bintree_yssjchk_e,
			assign_insert_bintree)<0){
			WriteAlertMsg("生成BINTREE失败");
			return -1;
		}
		iCnt++;
        }
        WriteProcMsg("成功加载表%s 记录数%d条",TempIn.sTableName,iCnt);
	return 0;
}

int MxTicketUp2Outlist(char sTableName[],char sCondition[])
{
	int iCnt=0,iTotalCnt=0;
	static int iFirstFlag=true;
        static struct MxTicketUpStruct Temp;
        static struct MxTicketUpStructIn TempIn;

	struct YssjChkStruct *pTemp,S;

	BINTREE *pRootChk=NULL;
/*加载SP应收实收对账表*/

	if(YssjChk2Bintree(&pRootChk,INFCTL.sRefTabName)<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
        	strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetMxTicketUpToStruct(&Temp,&TempIn)){

	
		iTotalCnt++;
		if(ChkSpCode(Temp.sSpCode,"","")<0)continue;
/*欠费异常*/		
		if(strcmp(Temp.sMxType,"002")==0)continue;
		GetMxYssjChk(&Temp,&S);
/*未找到记录则丢弃*/
		if((SearchBin(pRootChk,(void*)&S,
			data_search_bintree_yssjchk_s_e,
			(void**)&pTemp))==NOTFOUND)continue;


		if(GetMxFiletag(&Temp)<0)continue;

		if((++iCnt%10000)==0)
			WriteProcMsg("表%s当前话单数为%d,有效话单为%d",sTableName,iTotalCnt,iCnt);

        }

        WriteProcMsg("表%s当前话单数为%d,有效话单为%d",sTableName,iTotalCnt,iCnt);
	return 0;
}

int GetMxFiletag(struct MxTicketUpStruct *pi)
{/*数据移动部分*/

	int iTotalCnt,iMxFee,iHeadLen=0;
	char sTemp[5];
		
	struct MxTicketUpHeadStruct *pFileHeadG=NULL,*pFileHeadC=NULL;
	struct FMxTicketUpStruct MxFile;

	pFileHeadG=(struct MxTicketUpHeadStruct *)INFCTL.sHeadG;
	pFileHeadC=(struct MxTicketUpHeadStruct *)INFCTL.sHeadC;

	if(strncmp(pi->sVisitCityCode,"59",2)==0){
		strncpy(sTemp,pi->sVisitCityCode,3);sTemp[3]=0;
	
		if(GetCityCode(sTemp,
			pi->sVisitCityCode)==NOTFOUND){
			strcpy(pi->sVisitCityCode,"380");
		}
	}
	
	mvitem_mfmxticketup(pi,&MxFile);
	
	iHeadLen=sizeof(struct FMxTicketUpStruct);

		if(IS_UNICOMCDMA(pi->sMsisdn)){

			iTotalCnt    	=atoi(pFileHeadC->sTotalCnt)  +1;
			iMxFee    	=atoi(pFileHeadC->sMxFee)  +atoi(pi->sMxFee);

			sprintf(pFileHeadC->sTotalCnt,	"%010d",iTotalCnt);
			sprintf(pFileHeadC->sMxFee,	"%010d",iMxFee);

			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllC,(void *)&MxFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}

		}
		else{
			iTotalCnt    	=atoi(pFileHeadG->sTotalCnt)  +1;
			iMxFee    	=atoi(pFileHeadG->sMxFee)  +atoi(pi->sMxFee);

			sprintf(pFileHeadG->sTotalCnt,	"%010d",iTotalCnt);
			sprintf(pFileHeadG->sMxFee,	"%010d",iMxFee);

			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllG,(void *)&MxFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}
		}

	return 0;

}

int Mx_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256],OutFileName[256];

	struct FMxTicketUpHeadStruct FileHead;

	iHeadLen=sizeof(struct FMxTicketUpHeadStruct);
	
	if(iHeadLen>0){
		
		memset(&FileHead,0,sizeof(struct FMxTicketUpHeadStruct));
		mvitem_mfmxticketuphead(
			(struct MxTicketUpHeadStruct *)INFCTL.sHeadG,&FileHead);
	
		
		if(item2list(&INFCTL.pFileAllG,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
		memset(&FileHead,0,sizeof(struct FMxTicketUpHeadStruct));
		mvitem_mfmxticketuphead(
			(struct MxTicketUpHeadStruct *)INFCTL.sHeadC,&FileHead);

		if(item2list(&INFCTL.pFileAllC,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
	}

	AssignFileName("G",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	if(list2filelrn(&INFCTL.pFileAllG,sTargetName)<0)return -1;

	AssignFileName("C",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	return list2filelrn(&INFCTL.pFileAllC,sTargetName);
}

int IsSpzbTP(char sFileType[])
{
	if(strcmp(sFileType,"TP")==0) return true;
	return false;
}
void Tp_InitFileHead()
{
	int iFileSeq;
	char sDateTime[15];
	struct TpTicketUpHeadStruct *po=(struct TpTicketUpHeadStruct *)INFCTL.sHeadG;

	/*初始化文件头*/
	INFCTL.iHeadLen=sizeof(struct TpTicketUpHeadStruct);
	bzero((void*)po,INFCTL.iHeadLen);

	GetHostTime(sDateTime);

	strncpy(INFCTL.sFileDate,sDateTime,8);INFCTL.sFileDate[8]=0;

	iFileSeq=atoi(INFCTL.sFileSeq);
	sprintf(po->sFileSeq,"%04d",iFileSeq);
	strcpy(po->sFileVersion,"01");
	strcpy(po->sFileCreatDate,INFCTL.sFileDate);
	strcpy(po->sProvCode,INFCTL.sProvCode);
	strcpy(po->sBillingCycleID,INFCTL.sBillingCycleID);

	sprintf(po->sTotalCnt,		"%010d",0);
	sprintf(po->sTotalFee,		"%010d",0);

	LeftPad(po->sReserv1,25,' ');

	memcpy((void*)INFCTL.sHeadC,(void*)INFCTL.sHeadG,512);

}
int TpTicketUp2Outlist(char sTableName[],char sCondition[])
{
	int iCnt=0,iTotalCnt=0;
	static int iFirstFlag=true;
        static struct TpTicketUpStruct Temp;
        static struct TpTicketUpStructIn TempIn;

	struct YssjChkStruct *pTemp,S;

	BINTREE *pRootChk=NULL;
/*加载SP应收实收对账表*/

	if(YssjChk2Bintree(&pRootChk,INFCTL.sRefTabName)<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
        	strcpy(TempIn.sTableName,sTableName);
        	strcpy(TempIn.sCondition,sCondition);
		iFirstFlag=false;
	}

        /*取出表中记录加载二叉树*/
        while(EGetTpTicketUpToStruct(&Temp,&TempIn)){

		iTotalCnt++;
		if(ChkSpCode(Temp.sSpCode,"","")<0)continue;
		
		GetTpYssjChk(&Temp,&S);
/*未找到记录则丢弃*/
		if((SearchBin(pRootChk,(void*)&S,
			data_search_bintree_yssjchk_s_e,
			(void**)&pTemp))==NOTFOUND)continue;

		if(GetTpFiletag(&Temp)<0)continue;

		if((++iCnt%10000)==0)
			WriteProcMsg("表%s当前话单数为%d,有效话单为%d",sTableName,iTotalCnt,iCnt);

        }

        WriteProcMsg("表%s当前话单数为%d,有效话单为%d",sTableName,iTotalCnt,iCnt);
	return 0;
}

int GetTpFiletag(struct TpTicketUpStruct *pi)
{/*数据移动部分*/

	int iTotalCnt,iTotalFee,iHeadLen=0;
	char sTemp[5];
	
	struct TpTicketUpHeadStruct *pFileHeadG=NULL,*pFileHeadC=NULL;
	struct FTpTicketUpStruct TpFile;

	pFileHeadG=(struct TpTicketUpHeadStruct *)INFCTL.sHeadG;
	pFileHeadC=(struct TpTicketUpHeadStruct *)INFCTL.sHeadC;

	if(strncmp(pi->sVisitCityCode,"59",2)==0){
		strncpy(sTemp,pi->sVisitCityCode,3);sTemp[3]=0;
	
		if(GetCityCode(sTemp,
			pi->sVisitCityCode)==NOTFOUND){
			strcpy(pi->sVisitCityCode,"380");
		}
	}

	mvitem_mftpticketup(pi,&TpFile);
	iHeadLen=sizeof(struct FTpTicketUpStruct);

		if(IS_UNICOMCDMA(pi->sMsisdn)){

			iTotalCnt    	=atoi(pFileHeadC->sTotalCnt)  +1;
			iTotalFee    	=atoi(pFileHeadC->sTotalFee)  +atoi(pi->sTpFee);

			sprintf(pFileHeadC->sTotalCnt,	"%010d",iTotalCnt);
			sprintf(pFileHeadC->sTotalFee,	"%010d",iTotalFee);

			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllC,(void *)&TpFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}

		}
		else{
			iTotalCnt    	=atoi(pFileHeadG->sTotalCnt)  +1;
			iTotalFee    	=atoi(pFileHeadG->sTotalFee)  +atoi(pi->sTpFee);

			sprintf(pFileHeadG->sTotalCnt,	"%010d",iTotalCnt);
			sprintf(pFileHeadG->sTotalFee,	"%010d",iTotalFee);

			/*保存结果数据，以供输出*/
			if(item2list(&INFCTL.pFileAllG,(void *)&TpFile,iHeadLen)<0){
				WriteAlertMsg("添加%s类型文件的文件错误",INFCTL.sFileType);
				return -1;
			}
		}

	return 0;

}

int Tp_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256],OutFileName[256];

	struct FTpTicketUpHeadStruct FileHead;

	iHeadLen=sizeof(struct FTpTicketUpHeadStruct);
	
	if(iHeadLen>0){
		
		memset(&FileHead,0,sizeof(struct FTpTicketUpHeadStruct));
		mvitem_mftpticketuphead(
			(struct TpTicketUpHeadStruct *)INFCTL.sHeadG,&FileHead);
	
		
		if(item2list(&INFCTL.pFileAllG,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
		memset(&FileHead,0,sizeof(struct FTpTicketUpHeadStruct));
		mvitem_mftpticketuphead(
			(struct TpTicketUpHeadStruct *)INFCTL.sHeadC,&FileHead);

		if(item2list(&INFCTL.pFileAllC,(void *)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				INFCTL.sFileType);
			return -1;
		}
	}

	AssignFileName("G",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	if(list2filelrn(&INFCTL.pFileAllG,sTargetName)<0)return -1;

	AssignFileName("C",OutFileName);
	sprintf(sTargetName,"%s%s",INFCTL.sTargetPath,OutFileName);

	return list2filelrn(&INFCTL.pFileAllC,sTargetName);
}


void AssignFileName(char sNetTpye[],char sTargetName[])
{

	sprintf(sTargetName,"%s%s%s%s%s.req",INFCTL.sFileType,sNetTpye,
		INFCTL.sProvCode,INFCTL.sFileDate,INFCTL.sFileSeq);

}
int CheckType(char sType[])
{
	if(IsSpzbYS(sType)==1) return 0;
	if(IsSpzbRX(sType)==1) return 0;
	if(IsSpzbSJ(sType)==1) return 0;
	if(IsSpzbMX(sType)==1) return 0;
	if(IsSpzbTP(sType)==1) return 0;
	WriteAlertMsg("类别仅限：\n\tYS(应收接口)");
	return -1;
}

void InitVisualFunc(char sFileType[])
{
	if(IsSpzbYS(sFileType)){
		INFCTL.iHeadLen=	512;
		
		XInitFileHead=		Ys_InitFileHead;
		XDealTicket2Outlist=	YsSmsTicket2Outlist;
		XWriteTargetFile=	Ys_WriteTargetFile;
	}
	else if(IsSpzbRX(sFileType)){
		INFCTL.iHeadLen=	512;
		
		XInitFileHead=		Rx_InitFileHead;
		XDealTicket2Outlist=	RxSmsTicket2Outlist;
		XWriteTargetFile=	Rx_WriteTargetFile;
	}
	else if(IsSpzbSJ(sFileType)){
		INFCTL.iHeadLen=	512;
		
		XInitFileHead=		Sj_InitFileHead;
		XDealTicket2Outlist=	SjSpTicketSj2Outlist;
		XWriteTargetFile=	Sj_WriteTargetFile;
	}
	else if(IsSpzbMX(sFileType)){
		INFCTL.iHeadLen=	512;
		
		XInitFileHead=		Mx_InitFileHead;
		XDealTicket2Outlist=	MxTicketUp2Outlist;
		XWriteTargetFile=	Mx_WriteTargetFile;
	}
	else if(IsSpzbTP(sFileType)){
		INFCTL.iHeadLen=	512;
		
		XInitFileHead=		Tp_InitFileHead;
		XDealTicket2Outlist=	TpTicketUp2Outlist;
		XWriteTargetFile=	Tp_WriteTargetFile;
	}
	else {
		CheckType(sFileType);
		exit(-1);
	}
}

void ParseArg(int argc,char **argv)
{

	char sAppID[256],sTemp[256];

	if(argc!=8&&argc!=9&&argc!=10){
		printf("Usage %s type targetpath ProvCode "
			"FileSeq BillingCycleID sFirstTabName wherecause [sRefTabName] [dRate].\n",
			argv[0]);
		exit(-1);
	}

	bzero((void*)&INFCTL,sizeof(struct IntfCtlStruct));

	strncpy(INFCTL.sFileType,argv[1],2);
	INFCTL.sFileType[2]=0;

	if(CheckType(INFCTL.sFileType)<0){
		printf("非法类别 %s .\n",INFCTL.sFileType);
		exit(-1);
	}
	sprintf(sAppID,"%s_%s",argv[0],INFCTL.sFileType);
	InitAppRes(sAppID);

	strcpy(INFCTL.sTargetPath,argv[2]);
	RegularDir(INFCTL.sTargetPath);

	strcpy(INFCTL.sProvCode,argv[3]);
	INFCTL.sProvCode[3]=0;


	strcpy(INFCTL.sFileSeq,argv[4]);
	INFCTL.sFileSeq[4]=0;
	strcpy(INFCTL.sBillingCycleID,argv[5]);
	INFCTL.sBillingCycleID[6]=0;

	strcpy(INFCTL.sFirstTabName,argv[6]);
	Upper(INFCTL.sFirstTabName);

	strcpy(INFCTL.sCondition,argv[7]);Upper(INFCTL.sCondition);

	if(argc==9||argc==10){
		strcpy(INFCTL.sRefTabName,argv[8]);
		Upper(INFCTL.sRefTabName);
	}
	if(argc==10){
		strcpy(sTemp,argv[9]);
		INFCTL.iRate=atoi(sTemp)*10;
	}
	
}

int main(int argc, char **argv)
{



	ParseArg(argc,argv);

	/*初始化函数指针*/
	InitVisualFunc(INFCTL.sFileType);

/**连接数据库***/
	if(ConnectDataDB()<0) return -1;
/*初始化文件头*/  
	XInitFileHead(); 

/**加载处理月话单表**/
	if(XDealTicket2Outlist(INFCTL.sFirstTabName,
		INFCTL.sCondition)<0){
		WriteAlertMsg("生成BINTREE失败");
		return -1;
	}
	
/*输出结果,写文件*/
	if(XWriteTargetFile()<0){
		WriteAlertMsg("写输出文件失败");
		DisconnectDatabase();
		return -1;
	}

	
	WriteProcMsg("输出文件成功到%s",INFCTL.sTargetPath);
	printf("输出文件成功到%s.\n",INFCTL.sTargetPath);

	DestroyBin(pRoot);
	DestroyBin(pRootOut);
	DisconnectDatabase();

	return 0;
}
