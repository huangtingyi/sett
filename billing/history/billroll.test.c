#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <bintree.h>
#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <ticket_field.h>
#include <tariff_disct.h>
#include <ticket.h>
#include "stt_ticket.h"
#include <bill_supp.h>

void mvitem_rsttticket2mob_bill(struct RSttTicketStruct *pi,
	struct MobTicketStruct *po);
void mvitem_rsttticket2ticketanalyze(struct RSttTicketStruct *pi,
	struct TicketAnalyzeStruct *po);
void mvitem_rsttticket2mob_prep(struct RSttTicketStruct *pi,
	struct MobTicketStruct *po);
int cmitem_mobbill(struct MobTicketStruct *pSource,
	struct MobTicketStruct *pTarget);
int cmitem_ticketanalyze(struct TicketAnalyzeStruct *pSource,
	struct TicketAnalyzeStruct *pTarget);
void mvitem_upsttticket(struct MobTicketStruct *pm,
	struct TicketAnalyzeStruct *pa,char sRowID[19],
	struct USttTicketStruct *po);

struct	MobTicketStruct Ticket;
struct FileControlOutStruct *pOutput=NULL;
struct TinyRollLogStruct *pSumLog=NULL;

int GenOutputList(struct MobTicketStruct *pn,char sFileName[],
	struct RSttTicketStruct *po)
{
	int i,l;
	char sRecord[1024],sSplitNew[21],msg[1024],sTargetName[256],sTmp[21];
	
	strcpy(sSplitNew,"");

	l=PrintTicket(pn,po->sSplitType,sRecord);
	
	if(Item2OutList(&pOutput,po->sSplitType,sRecord,l,sSplitNew,msg)<0){
		WriteAlertMsg("����ԭ�����������");
		return -1;
	}
	l=PrintTicketOriNeg(po,sRecord);
	
	/*������ǰ���ļ�����ԭ�е��ļ�����ʽ���
	���ǵ���λ��˵��������������ticket_type_id in(1000..9999)
	�����������Ĭ��splitType��Ϊ ticket_type_id��λ*/
	strcpy(sSuffixStr,"");
	strcpy(sTmp,po->sSplitType);
	
	if(po->iTicketTypeID>=1000&&po->iTicketTypeID<9999){
		sTmp[0]=po->iTicketTypeID/1000+'0';
		sTmp[1]=0;
	}
	else{
		i=strlen(po->sSourceID);
		if(i>0&&po->sSourceID[i-1]=='.')
			strcpy(sTmp,po->sSourceID+i-1);
	}

	if(Item2OutList(&pOutput,sTmp,sRecord,l,sSplitNew,msg)<0){
		WriteAlertMsg("�����»����������");
		return -1;
	}

	for(i=0;i<strlen(sSplitNew);i++){

		sprintf(sTargetName,"%s.%c",sFileName,sSplitNew[i]);

		if(SumTinyRollLog(&pSumLog,po->sSourceID,sTargetName,2)<0){
			WriteAlertMsg("������־�ļ��б����");
			return -1;
		}
	}
	
	return 0;	
}

int WantOutput(char sFileName[])
{
	if(strcmp(sFileName,"null")==0||
		strcmp(sFileName,"NULL")==0) return false;
	return true;
}

int EUpdateStructToUSttTicket1(struct USttTicketStruct *p,
	int iUpdateFlag,struct USttTicketStructUp *pTarget);

int main(int argc,char *argv[])
{

	int iRet,iCnt=0,iMissCnt=0,iRightCnt=0,iBillingFlag,iWantOutput=false;
	char sVisitAreaCode[10],sSplitNew[30];
	char  sTemplateRule[128],sModule[4],sNormalDir[256],sBaseName[256];
	char sSplitStr[64],sTableName[31],sCondition[256],sFileName[256];

	struct	FileControlListStruct *pList;
	struct SplitRuleStruct *pSplitRule=NULL;
	struct MobTicketStruct *p=&Ticket;
	
	struct MobTicketStruct MobTemp;
	struct TicketAnalyzeStruct AnalyzeTemp;
	
	struct RSttTicketStruct	Temp;
	struct RSttTicketStructIn	TempIn;
	
	struct USttTicketStruct TempUStt;
	struct USttTicketStructUp TempUp;	
	
	if(argc!=5&&argc!=6){
		printf("Usage %s templateid tablename wherecause filename [module].\n",
			argv[0]);
		return -1;
	}
/*��ʼ����������*/
	InitAppRes(argv[0]);
	strcpy(sTemplateRule,argv[1]);
	strcpy(sTableName,argv[2]);
	strcpy(sCondition,argv[3]);
	strcpy(sFileName,argv[4]);
	if(argc==6){strncpy(sModule,argv[5],3);sModule[3]=0;}
	else	strcpy(sModule,"BLR");

	iWantOutput=WantOutput(sFileName);
	pSumLog=NULL;
	
/*��ʼ�����۲���*/
	InitParamMem();
/*�������ڴ�ȥ��TEMPLATE_ID��Ӧ��SPLIT_TYPE����ȡ����08.06.03*/
	if(GetTemplateSplitStr(sTemplateRule,sSplitStr)<0) return -1;
/*���������б�*/
	InitFileControlList(sTemplateRule,sSplitStr,&pFileControlList);
	
/*�����ʷ�����*/
	InitTollTariffList(comp_toll_tariff_ticket);

/*�����뻰��ָ��ָ��ָ������*/
	pTicketField=p;

/*��ʼ��select��update�ṹ����*/
	bzero((void*)&TempIn,sizeof(struct RSttTicketStructIn));
	TempIn.iFirstFlag=true;
	TempIn.iBufEmpty =true;
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	bzero((void*)&TempUp,sizeof(struct USttTicketStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
/**�������ݿ�***/
	if(ConnectDataDB()<0) return -1;
	
	while(EGetRSttTicketToStruct(&Temp,&TempIn)==true){
		
		iCnt++;
		if(strcmp(Temp.sImsi,"-1")==0) strcpy(Temp.sImsi,"");
/***�����ݿ⵼���ķ�TicketAnalyze����ָ��mobticket�ṹ��*/	
/**ͬʱ���ݿ⵼��TicketAnalyze����ָ��TicketAnalyze�ṹ**/
		mvitem_rsttticket2mob_bill(&Temp,&MobTemp);
		mvitem_rsttticket2ticketanalyze(&Temp,&AnalyzeTemp);
		
/*�������۵��ֶ��Ƶ�mobticket�ṹ��*/
		bzero((void*)p,sizeof(struct MobTicketStruct));
		mvitem_rsttticket2mob_prep(&Temp,p);
/*����billingflag*/
		if(Temp.sSplitType[0]>='0'&&
			Temp.sSplitType[0]<='9')iBillingFlag=false;
		else	iBillingFlag=true;
			
/*����Ĭ�����ţ����ó������������VISIT_AREA_CODE*/
		/*��;���㲻�����м�*/
		if(strcmp(sTemplateRule,"1")==0&&
			Temp.sSplitType[0]=='2'){
			strcpy(sVisitAreaCode,Temp.sVisitAreaCode);
		}
		else{
			strcpy(sVisitAreaCode,":");
			strcat(sVisitAreaCode,Temp.sVisitAreaCode);
		}

		if((iRet=AnalyzeTicketBase(p,sVisitAreaCode,iBillingFlag))<0)
			continue;
/*������Ҫ�Ļ����ֶ�*/
		AnalyzeUserType("U",p);
		PreModifyTicket(p,iBillingFlag);
		AnalyzeTicketExtent(sTemplateRule,iBillingFlag,
			sModule,Temp.sSplitType,p);

/*����ָ���Ļ�������ģ����벢����*/
		pList=GetFileControlList(pFileControlList,Temp.sSplitType);
		
		if((pSplitRule=GetMultiSplitRule(pList))==NULL){
			WriteAlertMsg("����ģ��%s��������%s��ƥ��.",
				sTemplateRule,Temp.sSplitType);
			return -1;
		}
		p->iSplitRuleID =	pSplitRule->iSplitRuleID;
		p->iTicketTypeID=	pSplitRule->iTicketTypeID;
		strcpy(p->sSplitType,	pSplitRule->sSplitType);
		
		if((iRet=CalMainTicketD(p))<0){
			WriteAlertMsg("���ʧ��");
			return -1;
		}
		
		ModifyTicketFee(p);

/*�Ƚ�����ǰ��Ļ�������,��������,�Թ�*/
		if(cmitem_mobbill(p,&MobTemp)==0&&
			cmitem_ticketanalyze(&TicketAnalyze,&AnalyzeTemp)==0){
			iMissCnt++;
			continue;
		}
		
/*�����¾ɼ�¼�������*/
		if(iWantOutput){
			if(GenOutputList(p,sFileName,&Temp)<0){
				WriteAlertMsg("�����������ʧ��");
				return -1;
			}
		}	
		
/*����������,��������浽ָ��update�ṹ*/
		mvitem_upsttticket(p,&TicketAnalyze,Temp.sRowID,&TempUStt);
/*����¼���µ����ݿ���*/
		if(EUpdateStructToUSttTicket1(&TempUStt,false,&TempUp)<0){
			WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
			return -1;
		}
		if((++iRightCnt)%10000==0){
			if(EUpdateStructToUSttTicket1(NULL,true,&TempUp)<0){
				WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
				return -1;
			}
			CommitWork();
			WriteProcMsg("�Ա�%s����������Ŀ%d,���в��������۵Ļ�����%d,��������������%d",
				TempUp.sTableName,iCnt,iMissCnt,iRightCnt);
		}
		
	}
	
	if(EUpdateStructToUSttTicket1(NULL,true,&TempUp)<0){
		WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
		return -1;
	}
	CommitWork();
	WriteProcMsg("�Ա�%s����������Ŀ%d,���в��������۵Ļ�����%d,��������������%d",
		TempUp.sTableName,iCnt,iMissCnt,iRightCnt);

	DisconnectDatabase();

	DistroyAllMem();

/*�������*/
	strcpy(sSplitNew,"");
	if(iWantOutput){
		if(WriteRollLogCtl(pSumLog,sFileName)<0){
			WriteAlertMsg("д��־�����ļ�ʧ��");
			return -1;
		}

		GetPathName(sFileName,sNormalDir);
		GetBaseName(sFileName,sBaseName);

		if(OutList2File(pOutput,sNormalDir,sBaseName,sSplitNew)<0){
			WriteAlertMsg("д���������ļ�%sʧ��",sFileName);
			return -1;
		}
	}

	printf("%s\t%d\t%d\t%d\t%s\n",
		TempUp.sTableName,iCnt,iMissCnt,iRightCnt,sSplitNew);

	return 0;
}
void mvitem_rsttticket2mob_bill(struct RSttTicketStruct *pi,
	struct MobTicketStruct *po)
{
	bzero((void*)po,sizeof(struct MobTicketStruct));

		po->iTicketTypeID=		pi->iTicketTypeID;
		po->iRoamFee=			pi->iRoamFee;
		po->iTollFee=			pi->iTollFee;
		po->iAddFee=			pi->iAddFee;

		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sDistanceType,	pi->sDistanceType,1);
/*splitrule_id���⴦��*/
/*		strncpy(po->sSplitRuleID,	pi->sSplitRuleID,4);*/
		po->iSplitRuleID=	atoi(pi->sSplitRuleID);
		strcpy(po->sBillMode,		pi->sBillMode);
		
}
void mvitem_rsttticket2ticketanalyze(struct RSttTicketStruct *pi,
	struct TicketAnalyzeStruct *po)
{
	bzero((void*)po,sizeof(struct TicketAnalyzeStruct));
	
		po->iTrunkInTypeID=		pi->iTrunkInTypeID;
		po->iTrunkOutTypeID=		pi->iTrunkOutTypeID;
		po->iTrunkInCarrierID=		pi->iTrunkInCarrierID;
		po->iTrunkOutCarrierID=		pi->iTrunkOutCarrierID;
		po->iCallingTypeID=		pi->iCallingTypeID;
		po->iCalledTypeID=		pi->iCalledTypeID;
		po->iCallingCarrierID=		pi->iCallingCarrierID;
		po->iCalledCarrierID=		pi->iCalledCarrierID;
		po->iCallingAreaID=		pi->iCallingAreaID;
		po->iCalledAreaID=		pi->iCalledAreaID;
}
void mvitem_rsttticket2mob_prep(struct RSttTicketStruct *pi,
	struct MobTicketStruct *po)
{
	bzero((void*)po,sizeof(struct MobTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);
/*duration���⴦��*/
/*		strncpy(po->sDuration,		pi->sDuration,6);*/
		po->iDuration=			atoi(pi->sDuration);
		
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sLac,		pi->sLac,4);
		strncpy(po->sCellID,		pi->sCellID,4);
		strncpy(po->sOtherLac,		pi->sOtherLac,4);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,4);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sEsn,		pi->sEsn,15);
		
		AllTrim(po->sCallType);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sMsrn);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sThirdParty);
		AllTrim(po->sEsn);
}
int cmitem_mobbill(struct MobTicketStruct *pSource,
	struct MobTicketStruct *pTarget)
{
	int res=0;
	
	if((res=(pSource->iTicketTypeID-pTarget->iTicketTypeID))!=0) return res;
	if((res=(pSource->iRoamFee-pTarget->iRoamFee))!=0) return res;
	if((res=(pSource->iTollFee-pTarget->iTollFee))!=0) return res;
	if((res=(pSource->iAddFee-pTarget->iAddFee))!=0) return res;

	if((res=strcmp(pSource->sHomeAreaCode,pTarget->sHomeAreaCode))!=0) return res;
	if((res=strcmp(pSource->sVisitAreaCode,pTarget->sVisitAreaCode))!=0) return res;
	if((res=strcmp(pSource->sCalledCode,pTarget->sCalledCode))!=0) return res;
	if((res=strcmp(pSource->sRoamType,pTarget->sRoamType))!=0) return res;
	if((res=strcmp(pSource->sDistanceType,pTarget->sDistanceType))!=0) return res;
/*splitrule_id���⴦��*/
/*	if((res=(pSource->iSplitRuleID-pTarget->iSplitRuleID))!=0) return res;
���ǲ�ͬ�ķ���ģ��,����SPLIT_RULE_ID���ж�
*/
	if((res=strcmp(pSource->sBillMode,pTarget->sBillMode))!=0) return res;

	return res;

}
int cmitem_ticketanalyze(struct TicketAnalyzeStruct *pSource,
	struct TicketAnalyzeStruct *pTarget)
{
	int res=0;
	
	if((res=(pSource->iTrunkInTypeID-pTarget->iTrunkInTypeID))!=0) return res;
	if((res=(pSource->iTrunkOutTypeID-pTarget->iTrunkOutTypeID))!=0) return res;
	if((res=(pSource->iTrunkInCarrierID-pTarget->iTrunkInCarrierID))!=0) return res;
	if((res=(pSource->iTrunkOutCarrierID-pTarget->iTrunkOutCarrierID))!=0) return res;
	if((res=(pSource->iCallingTypeID-pTarget->iCallingTypeID))!=0) return res;
	if((res=(pSource->iCalledTypeID-pTarget->iCalledTypeID))!=0) return res;
	if((res=(pSource->iCallingCarrierID-pTarget->iCallingCarrierID))!=0) return res;
	if((res=(pSource->iCalledCarrierID-pTarget->iCalledCarrierID))!=0) return res;
	if((res=(pSource->iCallingAreaID-pTarget->iCallingAreaID))!=0) return res;
	if((res=(pSource->iCalledAreaID-pTarget->iCalledAreaID))!=0) return res;
	
	return res;
}
void mvitem_upsttticket(struct MobTicketStruct *pm,
	struct TicketAnalyzeStruct *pa,char sRowID[19],
	struct USttTicketStruct *po)
{
	bzero((void*)po,sizeof(struct USttTicketStruct));
	
/*����mobticket������*/
		po->iTicketTypeID=		pm->iTicketTypeID;
		po->iRoamFee=			pm->iRoamFee;
		po->iTollFee=			pm->iTollFee;
		po->iAddFee=			pm->iAddFee;

		if(po->iRoamFee>=99999)		po->iRoamFee=0;
		if(po->iTollFee>=9999999)	po->iTollFee=0;
		if(po->iAddFee>=99999)		po->iAddFee=0;
	
		strncpy(po->sHomeAreaCode,	pm->sHomeAreaCode,5);
		strncpy(po->sVisitAreaCode,	pm->sVisitAreaCode,5);
		strncpy(po->sCalledCode,	pm->sCalledCode,5);
		strncpy(po->sRoamType,		pm->sRoamType,1);
		strncpy(po->sDistanceType,	pm->sDistanceType,1);
/*splitrule_id���⴦��*/
		sprintf(po->sSplitRuleID,	"%04d",pm->iSplitRuleID);
/*����ticketanalyze������*/
		po->iTrunkInTypeID=		pa->iTrunkInTypeID;
		po->iTrunkOutTypeID=		pa->iTrunkOutTypeID;
		po->iTrunkInCarrierID=		pa->iTrunkInCarrierID;
		po->iTrunkOutCarrierID=		pa->iTrunkOutCarrierID;
		po->iCallingTypeID=		pa->iCallingTypeID;
		po->iCalledTypeID=		pa->iCalledTypeID;
		po->iCallingCarrierID=		pa->iCallingCarrierID;
		po->iCalledCarrierID=		pa->iCalledCarrierID;
		po->iCallingAreaID=		pa->iCallingAreaID;
		po->iCalledAreaID=		pa->iCalledAreaID;
		
		strncpy(po->sTrunkIn,		pm->sTrunkIn,7);
		strncpy(po->sTrunkOut,		pm->sTrunkOut,7);
/*ָ����״̬*/
		strcpy(po->sState,		STATE_BILLED);
/*ָ��rowid*/
		strncpy(po->sRowID,		sRowID,18);
/*�����ؼ���*/
		strcpy(po->sMsisdn,		pm->sMsisdn);
		strcpy(po->sStartTime,		pm->sStartTime);
		po->iDuration=			pm->iDuration;

		strcpy(po->sBillMode,		pm->sBillMode);
}
