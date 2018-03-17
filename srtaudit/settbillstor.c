#include <stdio.h>
#include <stdlib.h>
#include <bintree.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <wwfile.h>

#include "gen_supp.h"
#include "sett_supp.h"
#include "../shed/appsupp.h"

#define Maxsize 1024

struct SettTicketUeStruct *gSettStatUeList=NULL;
struct SettTicketSmStruct *gSettStatSmList=NULL;
struct SettTicketMmsStruct *gSettStatMmsList=NULL;
struct SettInsertLogStruct *gSettInsertList=NULL;

unsigned long long lCurUseMem=0;
char gsFileName[65],gsMonth[3],gsMark[10];
int arryUE[]={18,6,4,8,4,4,2,8,30,8,4,4,2,8,30,16,16,18,11,4,4,11,4,4,4,4,4,36,36,36,10,4,4,15,4,18,10,18,2,2,0};
int arrySM[]={30,18,18,32,8,2,4,32,8,2,4,8,4,6,8,18,32,32,4,32,32,2,2,18,0};
int arryMms[]={30,18,18,32,32,8,8,4,4,12,6,8,4,32,32,8,8,8,18,32,32,4,32,32,32,32,32,32,18,32,32,0};

int data_search_day_stat(void *pValue,void *pData)
{
	int iResult=0;
	struct SettTicketUeStruct *pSource=(struct SettTicketUeStruct*)pValue;
	struct SettTicketUeStruct *pTarget=(struct SettTicketUeStruct*)pData;

	if((iResult=strcmp(pSource->sUsageEventID,pTarget->sUsageEventID))!=0) return iResult;		

	return 0;

}
void assign_insert_bintree_day_stat(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int data_search_sm_day_stat(void *pValue,void *pData)
{
	int iResult=0;
	struct SettTicketSmStruct *pSource=(struct SettTicketSmStruct*)pValue;
	struct SettTicketSmStruct *pTarget=(struct SettTicketSmStruct*)pData;

	if((iResult=strcmp(pSource->sUsageEventID,pTarget->sUsageEventID))!=0) return iResult;		

	return 0;

}
int data_search_mms_day_stat(void *pValue,void *pData)
{
	int iResult=0;
	struct SettTicketMmsStruct *pSource=(struct SettTicketMmsStruct*)pValue;
	struct SettTicketMmsStruct *pTarget=(struct SettTicketMmsStruct*)pData;

	if((iResult=strcmp(pSource->sUsageEventID,pTarget->sUsageEventID))!=0) return iResult;		

	return 0;

}
int append_bintree_to_list_sm_day_stat(void **ppData)
{
	struct SettTicketSmStruct *pTemp=(struct SettTicketSmStruct*)(*ppData);

	pTemp->pLoadNext=gSettStatSmList;
	gSettStatSmList=pTemp;

	return 0;
}
int append_bintree_to_list_mms_day_stat(void **ppData)
{
	struct SettTicketMmsStruct *pTemp=(struct SettTicketMmsStruct*)(*ppData);

	pTemp->pLoadNext=gSettStatMmsList;
	gSettStatMmsList=pTemp;

	return 0;
}
int append_bintree_to_list_day_stat(void **ppData)
{
	struct SettTicketUeStruct *pTemp=(struct SettTicketUeStruct*)(*ppData);

	pTemp->pLoadNext=gSettStatUeList;
	gSettStatUeList=pTemp;

	return 0;
}	

int SearchSubsTrunkItem(char sTrunkNumber[],struct SubsTrunkStruct **pptCur)
{
	static int iFirstFlag=true;	
	static struct SubsTrunkStruct *ptHead=NULL;
	struct SubsTrunkStruct *ptLkHead=NULL,*pTemp;

	if(iFirstFlag==true){
		if(InitSubsTrunk(&ptHead)<0) return -1;
		iFirstFlag=false;
	}
	
	*pptCur=NULL;
	ptLkHead=ptHead;
	while(ptLkHead!=NULL){
		pTemp=ptLkHead;
		ptLkHead=ptLkHead->pNext;
		
		if(strcmp(sTrunkNumber,pTemp->sTrunkNumber)==0){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	return NOTFOUND;
}



void AddUeTrime(char sStr[],int i,char sTemp[])
{
	int iLen=0;
	int iCnt=0;
	int m=0;
	
	iLen=strlen(sStr);
	iCnt=arryUE[i]-iLen;
	if(iCnt<=0)
		iCnt=0;
	while(m<iCnt){
		strncat(sStr," ",iCnt);
		m++;
	}
	strcpy(sTemp,sStr);
	
}
void AddSmTrime(char sStr[],int i,char sTemp[])
{
	int iLen=0;
	int iCnt=0;
	int m=0;
	
	iLen=strlen(sStr);
	iCnt=arrySM[i]-iLen;
	if(iCnt<=0)
		iCnt=0;
	while(m<iCnt){
		strncat(sStr," ",iCnt);
		m++;
	}
	strcpy(sTemp,sStr);
	
}
int GenUeSettleStr(char sStr[],char sResult[],int i)
{
	int iLen=0; 
	char sTemp[128];
	
	AddUeTrime(sStr,i,sTemp);
	iLen=sprintf(sResult,"%s",sTemp);

	return iLen;
}
int GenSmSettleStr(char sStr[],char sResult[],int i)
{
	int iLen=0; 
	char sTemp[128];
	
	AddSmTrime(sStr,i,sTemp);
	iLen=sprintf(sResult,"%s",sTemp);

	return iLen;
}
void AddMmsTrime(char sStr[],int i,char sTemp[])
{
	int iLen=0;
	int iCnt=0;
	int m=0;
	
	iLen=strlen(sStr);
	iCnt=arryMms[i]-iLen;
	if(iCnt<=0)
		iCnt=0;
	while(m<iCnt){
		strncat(sStr," ",iCnt);
		m++;
	}
	strcpy(sTemp,sStr);
	
}
int GenMmsSettleStr(char sStr[],char sResult[],int i)
{
	int iLen=0; 
	char sTemp[128];
	
	AddMmsTrime(sStr,i,sTemp);
	iLen=sprintf(sResult,"%s",sTemp);

	return iLen;
}
int EInsertList2SettInsertLogTable(struct SettInsertLogStruct *ptHead)
{
	struct SettInsertLogStruct *pTemp;
	struct SettInsertLogStructOut TempOut;

	memset(&TempOut,0,sizeof(struct SettInsertLogStructOut));
	strcpy(TempOut.sTableName,"SETT_INSERT_LOG");
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(EInsertStructToSettInsertLog(pTemp,false,&TempOut)<0){
			WriteProcMsg("д��%s����.",TempOut.sTableName);
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
	}
	if(EInsertStructToSettInsertLog(NULL,true,&TempOut)<0){
		WriteProcMsg("д��%s����.",TempOut.sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	
	return 0;
}
int EInsertList2Table(char sTableName[],struct SettTicketUeStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct SettTicketUeStructOut TempOut;
	struct SettTicketUeStruct *ptCur=NULL;
	struct SettTicketUeStruct *ptLoadCur=NULL;

	memset(&TempOut,0,sizeof(struct SettTicketUeStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToSettTicketUe(NULL,true,&TempOut)<0){
					WriteProcMsg("д��%s����.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("��ǰ������ݵ� %s ���¼�� %lu ��.",
					sTableName,ulRecCnt);
			}
			
			if(EInsertStructToSettTicketUe(ptCur,false,&TempOut)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			lCurUseMem -= sizeof(struct SettTicketUeStructOut);
			lCurUseMem -= sizeof(BINTREE);
		}
	}
	if(EInsertStructToSettTicketUe(NULL,true,&TempOut)<0){
		WriteProcMsg("д��%s����.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcPrint("������ݵ� %s ���ܼ�¼�� %lu ��.",sTableName,ulRecCnt);
	
	return 0;
}
int EInsertSmList2Table(char sTableName[],struct SettTicketSmStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct SettTicketSmStructOut TempOut;
	struct SettTicketSmStruct *ptCur=NULL;
	struct SettTicketSmStruct *ptLoadCur=NULL;

	memset(&TempOut,0,sizeof(struct SettTicketSmStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToSettTicketSm(NULL,true,&TempOut)<0){
					WriteProcMsg("д��%s����.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("��ǰ������ݵ� %s ���¼�� %lu ��.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToSettTicketSm(ptCur,false,&TempOut)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			lCurUseMem -= sizeof(struct SettTicketSmStructOut);
			lCurUseMem -= sizeof(BINTREE);
		}
	}
	if(EInsertStructToSettTicketSm(NULL,true,&TempOut)<0){
		WriteProcMsg("д��%s����.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcPrint("������ݵ� %s ���ܼ�¼�� %lu ��.",sTableName,ulRecCnt);
	
	return 0;
}


int EInsertMmsList2Table(char sTableName[],struct SettTicketMmsStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct SettTicketMmsStructOut TempOut;
	struct SettTicketMmsStruct *ptCur=NULL;
	struct SettTicketMmsStruct *ptLoadCur=NULL;

	memset(&TempOut,0,sizeof(struct SettTicketMmsStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToSettTicketMms(NULL,true,&TempOut)<0){
					WriteProcMsg("д��%s����.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("��ǰ������ݵ� %s ���¼�� %lu ��.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToSettTicketMms(ptCur,false,&TempOut)<0){
				WriteProcMsg("д��%s����.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			lCurUseMem -= sizeof(struct SettTicketMmsStructOut);
			lCurUseMem -= sizeof(BINTREE);
		}
	}
	if(EInsertStructToSettTicketMms(NULL,true,&TempOut)<0){
		WriteProcMsg("д��%s����.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcPrint("������ݵ� %s ���ܼ�¼�� %lu ��.",sTableName,ulRecCnt);
	
	return 0;
}

/*
0:GW_CT,��ͨ��������Ź���
1:GW_CM,��ͨ�������ƶ��ƶ�
2:GW_CRC,��ͨ�������ƶ���������ͨ��
3:GW_OTH,��ͨ����������
10:GW_CTC,��ͨ����������ƶ�
4:YD_CT,��ͨ�ƶ�����Ź���
5:YD_CM,��ͨ�ƶ����ƶ��ƶ�
6:YD_CRC,��ͨ�ƶ����ƶ���������ͨ��
7:YD_OTH,��ͨ�ƶ�������
8:OTH_OTH,����������
11:YD_CTC,��ͨ�ƶ�������ƶ�
9:YD_CNC��ͨ�ƶ�����ͨ

*/
int GetAsBintreeArrayTable(struct SettleBintreeStruct asBintreeArray[])
{
	strcpy(asBintreeArray[0].sNetWork,"GW");
	strcpy(asBintreeArray[1].sNetWork,"GW");
	strcpy(asBintreeArray[2].sNetWork,"GW");
	strcpy(asBintreeArray[3].sNetWork,"GW");
	
	strcpy(asBintreeArray[4].sNetWork,"YD");
	strcpy(asBintreeArray[5].sNetWork,"YD");
	strcpy(asBintreeArray[6].sNetWork,"YD");
	strcpy(asBintreeArray[7].sNetWork,"YD");
	
	strcpy(asBintreeArray[8].sNetWork,"OTH");
	strcpy(asBintreeArray[9].sNetWork,"YD");
	strcpy(asBintreeArray[10].sNetWork,"GW");
	strcpy(asBintreeArray[11].sNetWork,"YD");
	
	strcpy(asBintreeArray[12].sNetWork,"UN");
	
	strcpy(asBintreeArray[0].sOperators,"CT");
	strcpy(asBintreeArray[1].sOperators,"CM");
	strcpy(asBintreeArray[2].sOperators,"CRC");
	strcpy(asBintreeArray[3].sOperators,"OTH");
	
	strcpy(asBintreeArray[4].sOperators,"CT");
	strcpy(asBintreeArray[5].sOperators,"CM");
	strcpy(asBintreeArray[6].sOperators,"CRC");
	strcpy(asBintreeArray[7].sOperators,"OTH");
	
	strcpy(asBintreeArray[8].sOperators,"OTH");
	strcpy(asBintreeArray[9].sOperators,"CNC");
	strcpy(asBintreeArray[10].sOperators,"CTC");
	strcpy(asBintreeArray[11].sOperators,"CTC");
	
	strcpy(asBintreeArray[12].sOperators,"OTH");
	
	asBintreeArray[0].ptRoot=NULL;
	asBintreeArray[1].ptRoot=NULL;
	asBintreeArray[2].ptRoot=NULL;
	asBintreeArray[3].ptRoot=NULL;
	asBintreeArray[4].ptRoot=NULL;
	asBintreeArray[5].ptRoot=NULL;
	asBintreeArray[6].ptRoot=NULL;
	asBintreeArray[7].ptRoot=NULL;
	asBintreeArray[8].ptRoot=NULL;
	asBintreeArray[9].ptRoot=NULL;
	asBintreeArray[10].ptRoot=NULL;
	asBintreeArray[11].ptRoot=NULL;
	asBintreeArray[12].ptRoot=NULL;
	
	return 0;
}
int SearchTicketTypeMapStructItem(char sProdID[],struct TicketTypeMapStruct **pptCur)
{
	static int iFirstFlag=true;
	static struct TicketTypeMapStruct *ptHead=NULL;
	struct TicketTypeMapStruct *pTemp,*ptLkHead;
	if(iFirstFlag==true){
		if(InitTicketTypeMap(&ptHead)<0) return -1;
		
		iFirstFlag=false;
	}
	
	ptLkHead=ptHead;
	while(ptLkHead!=NULL){
		pTemp=ptLkHead;
		ptLkHead=ptLkHead->pNext;
		
		if(strcmp(sProdID,pTemp->sProdID)==0){
			*pptCur=pTemp;
			return FOUND;
		}
	}
	return NOTFOUND;
}
int IsNumber(char sTemp[])
{
	int i,iLen;
	
	iLen=strlen(sTemp);
	for(i=0;i<iLen;i++){
		if((sTemp[i]>='a'&&sTemp[i]<='z')||
			(sTemp[i]>='A'&&sTemp[i]<='Z')) return false;
	}
	return true;
}

int comp_list_sett_insert_log_e(void *pData,LIST *pValue)
{
	int res=0;
	struct SettInsertLogStruct *pSource=(struct SettInsertLogStruct *)pData;
	struct SettInsertLogStruct *pTarget=(struct SettInsertLogStruct *)pValue;
	
	if((res=strcmp(pSource->sFileName,	pTarget->sFileName))!=0) return res;
	if((res=strcmp(pSource->sTableName,	pTarget->sTableName))!=0) return res;
	if((res=strcmp(pSource->sDataDate,	pTarget->sDataDate))!=0) return res;
		
	return 0;
}

int DealSettInsertFileLog(char sFileName[],char sTableName[],char sDataDate[])
{
	
	struct SettInsertLogStruct Temp,*pTemp=NULL;
	
	strcpy(Temp.sFileName,sFileName);
	strcpy(Temp.sTableName,sTableName);
	strcpy(Temp.sDataDate,sDataDate);
	strcpy(Temp.sState,"0");
	
	if(SearchList((LIST*)gSettInsertList,(void*)&Temp,(LIST**)&pTemp,
		comp_list_sett_insert_log_e)==NOTFOUND){
		
		if((pTemp=(struct SettInsertLogStruct*)malloc(sizeof(struct SettInsertLogStruct)))==NULL){
			WriteAlertMsg("malloc struct SettInsertLogStruct ʧ��.");
			return -1;	
		}
		
		memcpy((void*)pTemp,(void*)&Temp,sizeof(struct SettInsertLogStruct));
		pTemp->pNext=NULL;
		pTemp->pLoadNext=NULL;
		pTemp->iInsertCnt=1;
		
		InsertList((LIST**)&gSettInsertList,(LIST*)pTemp);
		return 0;
	}
	pTemp->iInsertCnt++;

	return 0;
}

int GenerationUeBinTree(char sStr[],struct SettleBintreeStruct asBintreeArray[])
{	
	static int iLen=sizeof(struct SettTicketUeStruct);
	static int iLen_f=sizeof(struct FSettTicketUeStruct);
	struct SettTicketUeStruct *pTemp;
	struct FSettTicketUeStruct *pFp;
	struct TicketTypeMapStruct *ptCur;
	struct SubsTrunkStruct *pSubType=NULL;
	
	char sInNetWork[3],sOutNetWork[3],sTableName[31],sInTrunkNumber[12],sOutTrunkNumber[12];
	char sInCompanyCode[3],sOutCompanyCode[3],sInTrunkSubType[3],sOutTrunkSubType[3];
	char sProdId[4],sGroupID[3],sMsisdn[31],sOppAccNbr[31],sSettDate[9],sHomeNetWork[3],sOppNetWork[3];
	int i=0;
		
	if((pTemp=(struct SettTicketUeStruct*)malloc(iLen))==NULL){
		WriteProcMsg("malloc struct SettTicketUeStruct ʧ��!!!");
		return -1;
	}

	memset((void*)pTemp,0,sizeof(struct SettTicketUeStruct));

	mvitem_fmsettticketue((struct FSettTicketUeStruct*)sStr,pTemp);	
/*���Ĭ��״̬�������Ͳ����ڣ���ʹ���м̲�ѯ���ñ���ȡ�������ͣ�
		���δ���ҵ�������ֱ��ѡ�ø��м��������������*/	
	if(strcmp(pTemp->sInTrunkSubType,"")==0||strcmp(pTemp->sOutTrunkSubType,"")==0){
		if(SearchSubsTrunkItem(pTemp->sInTrunkNumber,&pSubType)==FOUND){
			strcpy(pTemp->sInTrunkSubType,pSubType->sSubType);
		}
		else{
			strcpy(pTemp->sInTrunkSubType,pTemp->sInTrunkNetType);
		}
		if(SearchSubsTrunkItem(pTemp->sOutTrunkNumber,&pSubType)==FOUND){
			strcpy(pTemp->sOutTrunkSubType,pSubType->sSubType);
		}
		else{
			strcpy(pTemp->sOutTrunkSubType,pTemp->sOutTrunkNetType);
		}
	}
	
	
	if(strcmp(pTemp->sInCompanyCode,"U")==0){
		strcpy(sMsisdn,pTemp->sCallingNumber);
		strcpy(sOppAccNbr,pTemp->sCalledNumber);
		
		strcpy(sInNetWork,pTemp->sInTrunkNetType);
		strcpy(sInCompanyCode,pTemp->sInCompanyCode);
		
		strcpy(sOutNetWork,pTemp->sOutTrunkNetType);
		strcpy(sOutCompanyCode,pTemp->sOutCompanyCode);
		
		strcpy(sInTrunkSubType,pTemp->sInTrunkSubType);
		strcpy(sOutTrunkSubType,pTemp->sOutTrunkSubType);
		
		strcpy(sInTrunkNumber,pTemp->sInTrunkNumber);
		strcpy(sOutTrunkNumber,pTemp->sOutTrunkNumber);
		
		strcpy(pTemp->sCallType,"09");
	}
	else{
		strcpy(sMsisdn,pTemp->sCalledNumber);
		strcpy(sOppAccNbr,pTemp->sCallingNumber);
		
		strcpy(sInNetWork,pTemp->sOutTrunkNetType);
		strcpy(sInCompanyCode,pTemp->sOutCompanyCode);
		
		strcpy(sOutNetWork,pTemp->sInTrunkNetType);
		strcpy(sOutCompanyCode,pTemp->sInCompanyCode);
		
		strcpy(sInTrunkSubType,pTemp->sOutTrunkSubType);
		strcpy(sOutTrunkSubType,pTemp->sInTrunkSubType);
		
		strcpy(sInTrunkNumber,pTemp->sOutTrunkNumber);
		strcpy(sOutTrunkNumber,pTemp->sInTrunkNumber);
		
		strcpy(pTemp->sCallType,"05");
	}	
	strcpy(pTemp->sFileName,gsFileName);
	
	i=strlen(sMsisdn);
	if(i<=2) strcpy(sGroupID,sMsisdn);
	else{
		strncpy(sGroupID,sMsisdn+i-2,2);
		sGroupID[2]=0;
	}
	
	if(IsNumber(sGroupID)==false) 
		strcpy(pTemp->sGroupID,"00");
	else	strcpy(pTemp->sGroupID,sGroupID);
	
	if(ChkTime(pTemp->sStartTime)<0
		&& ChkTime(pTemp->sEndTime)<0){
			return -1;
	}

	strcpy(sProdId,pTemp->sProdID);

	/*sInNetWork,sOutNetWork:1.������0.����*/
	/*sInCompanyCode,sOutCompanyCode:U.��ͨ��T.���ţ�M.�ƶ�*/
	
	/*����IN��Ϊ��ͨ����OUT��Ϊ�Զ˷���ͨ���ڴ�֮ǰ�Ѿ�����*/
	/*Ĭ��״̬��ʹ���ļ��Դ�����������,����GW,YD������ʹ�öԶ��м̵�����������*/
	strcpy(sInNetWork,sOutTrunkSubType);	

	if(strcmp(sInNetWork,"0")==0 && strcmp(sOutNetWork,"0")==0&&strcmp(sInCompanyCode,"U")==0){
		/*��ͨ��������Ź���*/
		if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"T")==0)||
			(strcmp(sInCompanyCode,"T")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*0:GW_CT,��ͨ��������Ź���*/
			if(InsertBin(&(asBintreeArray[0].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[0].sNetWork,asBintreeArray[0].sOperators,gsMonth);
			asBintreeArray[0].iCnt++;
		}
		/*��ͨ�������ƶ�����*/
		else if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"M")==0)||
			(strcmp(sInCompanyCode,"M")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*2:GW_CRC,��ͨ�������ƶ���������ͨ��*/
			if(InsertBin(&(asBintreeArray[2].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[2].sNetWork,asBintreeArray[2].sOperators,gsMonth);
			asBintreeArray[2].iCnt++;
		}
		/*��ͨ����������OTH*/
		else{
			/*3:GW_OTH,��ͨ����������*/
			if(InsertBin(&(asBintreeArray[3].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[3].sNetWork,asBintreeArray[3].sOperators,gsMonth);
			asBintreeArray[3].iCnt++;
		}
	}
	else if(strcmp(sInNetWork,"1")==0 && strcmp(sOutNetWork,"1")==0&&strcmp(sInCompanyCode,"U")==0){
		/*��ͨ�ƶ�������ƶ�*/
		if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"T")==0)||
			(strcmp(sInCompanyCode,"T")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*11:YD_CTC,��ͨ�ƶ�������ƶ�*/
			if(InsertBin(&(asBintreeArray[11].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[11].sNetWork,asBintreeArray[11].sOperators,gsMonth);
			asBintreeArray[11].iCnt++;
		}
		/*��ͨ�ƶ����ƶ��ƶ�*/
		else if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"M")==0)||
			(strcmp(sInCompanyCode,"M")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*5:YD_CM,��ͨ�ƶ����ƶ��ƶ�*/
			if(InsertBin(&(asBintreeArray[5].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[5].sNetWork,asBintreeArray[5].sOperators,gsMonth);
			asBintreeArray[5].iCnt++;
		}
		/*��ͨ�ƶ�������OTH*/
		else{
			/*7:YD_OTH,��ͨ�ƶ�������*/
			if(InsertBin(&(asBintreeArray[7].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[7].sNetWork,asBintreeArray[7].sOperators,gsMonth);
			asBintreeArray[7].iCnt++;
		}
	}
	else if(strcmp(sInNetWork,"0")==0 && strcmp(sOutNetWork,"1")==0&&strcmp(sInCompanyCode,"U")==0){
		/*��ͨ����������ƶ�*/
		if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"T")==0)||
			(strcmp(sInCompanyCode,"T")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*10:GW_CTC,��ͨ����������ƶ�*/
			if(InsertBin(&(asBintreeArray[10].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[10].sNetWork,asBintreeArray[10].sOperators,gsMonth);
			asBintreeArray[10].iCnt++;
		}
		/*��ͨ�������ƶ��ƶ�*/
		else if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"M")==0)||
			(strcmp(sInCompanyCode,"M")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*1:GW_CM,��ͨ�������ƶ��ƶ�*/
			if(InsertBin(&(asBintreeArray[1].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[1].sNetWork,asBintreeArray[1].sOperators,gsMonth);
			asBintreeArray[1].iCnt++;
		}
		/*��ͨ��������ͨ�ƶ�*/
		else if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"U")==0)||
			(strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*9:YD_CNC,��ͨ��������ͨ�ƶ�*/
			if(InsertBin(&(asBintreeArray[9].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[9].sNetWork,asBintreeArray[9].sOperators,gsMonth);
			asBintreeArray[9].iCnt++;
		}
		/*��ͨ����������OTH*/
		else{
			/*3:GW_OTH,��ͨ����������*/
			if(InsertBin(&(asBintreeArray[3].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[3].sNetWork,asBintreeArray[3].sOperators,gsMonth);
			asBintreeArray[3].iCnt++;
		}
	}
	else if(strcmp(sInNetWork,"1")==0 && strcmp(sOutNetWork,"0")==0&&strcmp(sInCompanyCode,"U")==0){
		/*��ͨ�ƶ�����Ź���*/
		if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"T")==0)||
			(strcmp(sInCompanyCode,"T")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*4:YD_CT,��ͨ�ƶ�����Ź���*/
			if(InsertBin(&(asBintreeArray[4].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[4].sNetWork,asBintreeArray[4].sOperators,gsMonth);
			asBintreeArray[4].iCnt++;
		}
		/*��ͨ�ƶ����ƶ�����*/
		else if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"M")==0)||
			(strcmp(sInCompanyCode,"M")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*6:YD_CRC,��ͨ�ƶ����ƶ���������ͨ��*/
			if(InsertBin(&(asBintreeArray[6].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[6].sNetWork,asBintreeArray[6].sOperators,gsMonth);
			asBintreeArray[6].iCnt++;
		}
		/*��ͨ�ƶ�����ͨ����*/
		else if((strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"U")==0)||
			(strcmp(sInCompanyCode,"U")==0&&strcmp(sOutCompanyCode,"U")==0)){
			/*9:YD_CNC,��ͨ�ƶ�����ͨ����*/
			if(InsertBin(&(asBintreeArray[9].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[9].sNetWork,asBintreeArray[9].sOperators,gsMonth);
			asBintreeArray[9].iCnt++;
		}
		/*��ͨ�ƶ�������OTH*/
		else{
			/*7:YD_OTH,��ͨ�ƶ�������*/
			if(InsertBin(&(asBintreeArray[7].ptRoot),pTemp,data_search_day_stat,
				assign_insert_bintree_day_stat)<0){
				WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
				return -1;
			}
			sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[7].sNetWork,asBintreeArray[7].sOperators,gsMonth);
			asBintreeArray[7].iCnt++;
		}
	}
	/*OTH_TO_OTH*/
	else{
		/*8:OTH_OTH,����������*/
		if(InsertBin(&(asBintreeArray[8].ptRoot),pTemp,data_search_day_stat,
			assign_insert_bintree_day_stat)<0){
			WriteProcMsg("���ɶ����� struct PrepTicketSttOutStruct ʧ��.");
			return -1;
		}
		sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[8].sNetWork,asBintreeArray[8].sOperators,gsMonth);
		asBintreeArray[8].iCnt++;
		
	}
	strncpy(sSettDate,pTemp->sStartTime,8);sSettDate[8]=0;
	if(DealSettInsertFileLog(pTemp->sFileName,sTableName,sSettDate)<0) return -1;
	
	return 0;
}

int GenerationSmBinTree(char sStr[],struct SettleBintreeStruct asBintreeArray[])
{	
	static int iLen=sizeof(struct SettTicketSmStruct);
	static int iLen_f=sizeof(struct FSettTicketSmStruct);
	struct SettTicketSmStruct *pTemp;
	struct FSettTicketSmStruct *pFp;
	struct TicketTypeMapStruct *ptCur;
	
	char sInNetWork[3],sOutNetWork[3];
	char sInCompanyCode[3],sOutCompanyCode[3],sTableName[31];
	char sProdId[4],sGroupID[3],sMsisdn[31],sOppAccNbr[31],sSettDate[9];
	int i=0;
		
	if((pTemp=(struct SettTicketSmStruct*)malloc(iLen))==NULL){
		WriteProcMsg("malloc struct SettTicketSmStruct ʧ��!!!");
		return -1;
	}

	memset((void*)pTemp,0,sizeof(struct SettTicketSmStruct));

	mvitem_fmsettticketsm((struct FSettTicketSmStruct*)sStr,pTemp);
	
	if(strcmp(gsMark,"SMS")==0){
		
		if(strcmp(pTemp->sDownCompanyID,"U")!=0&&strcmp(pTemp->sUpCompanyID,"U")!=0){
			strcpy(pTemp->sCallType,"-1");
			strcpy(sMsisdn,pTemp->sCallingNumber);
		}
		else if(strcmp(pTemp->sDownCompanyID,"U")==0){
			strcpy(pTemp->sCallType,"07");
			strcpy(sMsisdn,pTemp->sCallingNumber);
		}
		else{
			strcpy(pTemp->sCallType,"08");
			strcpy(sMsisdn,pTemp->sCalledNumber);	
		}
	}
	else{	
		if(strcmp(pTemp->sCallingCompanyID,"U")!=0&&strcmp(pTemp->sCalledCompanyID,"U")!=0){
			strcpy(pTemp->sCallType,"-1");
			strcpy(sMsisdn,pTemp->sCallingNumber);
		}
		else if(strcmp(pTemp->sCallingCompanyID,"U")==0){
			strcpy(pTemp->sCallType,"07");
			strcpy(sMsisdn,pTemp->sCallingNumber);
		}
		else{
			strcpy(pTemp->sCallType,"08");
			strcpy(sMsisdn,pTemp->sCalledNumber);	
		}
	}
	strcpy(pTemp->sFileName,gsFileName);
	
	i=strlen(sMsisdn);
	if(i<=2) strcpy(sGroupID,sMsisdn);
	else{
		strncpy(sGroupID,sMsisdn+i-2,2);
		sGroupID[2]=0;
	}
	
	if(IsNumber(sGroupID)==false) 
		strcpy(pTemp->sGroupID,"00");
	else	strcpy(pTemp->sGroupID,sGroupID);
	
	if(ChkTime(pTemp->sStartTime)<0
		&& ChkTime(pTemp->sEndTime)<0){
			return -1;
	}

	strcpy(sProdId,pTemp->sProdID);
	
	if(InsertBin(&(asBintreeArray[12].ptRoot),pTemp,data_search_sm_day_stat,
		assign_insert_bintree)<0){
		WriteProcMsg("���ɶ����� struct SettTicketSmStruct ʧ��.");
		return -1;
	}
	
	asBintreeArray[12].iCnt++;
	strncpy(sSettDate,pTemp->sStartTime,8);sSettDate[8]=0;
	sprintf(sTableName,"ST_SMS_TICKET_%s",gsMonth);
	if(DealSettInsertFileLog(pTemp->sFileName,sTableName,sSettDate)<0) return -1;
		
	return 0;
}

int GenerationMmsBinTree(char sStr[],struct SettleBintreeStruct asBintreeArray[])
{	
	static int iLen=sizeof(struct SettTicketMmsStruct);
	static int iLen_f=sizeof(struct FSettTicketMmsStruct);
	struct SettTicketMmsStruct *pTemp;
	struct FSettTicketMmsStruct *pFp;
	struct TicketTypeMapStruct *ptCur;
	
	char sInNetWork[3],sOutNetWork[3];
	char sInCompanyCode[3],sOutCompanyCode[3],sTableName[31];
	char sProdId[4],sGroupID[3],sMsisdn[31],sOppAccNbr[31],sSettDate[9];
	int i=0;
		
	if((pTemp=(struct SettTicketMmsStruct*)malloc(iLen))==NULL){
		WriteProcMsg("malloc struct SettTicketMmsStruct ʧ��!!!");
		return -1;
	}

	memset((void*)pTemp,0,sizeof(struct SettTicketMmsStruct));

	mvitem_fmsettticketmms((struct FSettTicketMmsStruct*)sStr,pTemp);
/*	
	if((strcmp(pTemp->sCallingCompanyID,"9001")!=0&&strcmp(pTemp->sCallingCompanyID,"9003")!=0)
		&&(strcmp(pTemp->sCalledCompanyID,"9003")!=0&&strcmp(pTemp->sCalledCompanyID,"9001")!=0)){
		strcpy(pTemp->sCallType,"-1");
		strcpy(sMsisdn,pTemp->sCallingNumber);
	}
	else if(strcmp(pTemp->sCallingCompanyID,"9001")==0||strcmp(pTemp->sCallingCompanyID,"9003")==0){
		strcpy(pTemp->sCallType,"07");
		strcpy(sMsisdn,pTemp->sCallingNumber);
	}
	else{
		strcpy(pTemp->sCallType,"08");
		strcpy(sMsisdn,pTemp->sCalledNumber);	
	}
	*/
	
	if(strcmp(pTemp->sCallingCompanyID,"U")!=0&&strcmp(pTemp->sCalledCompanyID,"U")!=0){
		strcpy(pTemp->sCallType,"-1");
		strcpy(sMsisdn,pTemp->sCallingNumber);
	}
	else if(strcmp(pTemp->sCallingCompanyID,"U")==0){
		strcpy(pTemp->sCallType,"07");
		strcpy(sMsisdn,pTemp->sCallingNumber);
	}
	else{
		strcpy(pTemp->sCallType,"08");
		strcpy(sMsisdn,pTemp->sCalledNumber);	
	}
	
	strcpy(pTemp->sFileName,gsFileName);
	
	i=strlen(sMsisdn);
	if(i<=2) strcpy(sGroupID,sMsisdn);
	else{
		strncpy(sGroupID,sMsisdn+i-2,2);
		sGroupID[2]=0;
	}
	
	if(IsNumber(sGroupID)==false) 
		strcpy(pTemp->sGroupID,"00");
	else	strcpy(pTemp->sGroupID,sGroupID);
	
	if(ChkTime(pTemp->sStartTime)<0
		&& ChkTime(pTemp->sEndTime)<0){
			return -1;
	}

	strcpy(sProdId,pTemp->sProdID);
	
	if(InsertBin(&(asBintreeArray[12].ptRoot),pTemp,data_search_mms_day_stat,
		assign_insert_bintree)<0){
		WriteProcMsg("���ɶ����� struct SettTicketMmsStruct ʧ��.");
		return -1;
	}
	
	asBintreeArray[12].iCnt++;
	strncpy(sSettDate,pTemp->sStartTime,8);sSettDate[8]=0;
	sprintf(sTableName,"ST_SMS_TICKET_%s",gsMonth);
	if(DealSettInsertFileLog(pTemp->sFileName,sTableName,sSettDate)<0) return -1;
	return 0;
}

int SettleMentYD(char str[],struct SettleBintreeStruct asBintreeArray[])
{
	
	int i=0;
	int iOffset=0;
	int iLen=0;
	char *p;
	char Temp[4096],sTemp[4096];
	char delims=44;
	
	memset((void*)Temp,0,sizeof(Temp));
	memset((void*)sTemp,0,sizeof(sTemp));
	
	p=str;
	while(*p!='\0'){
		if(*p==','){
			iLen++;
		}
		p++;
	}
	while(i<=iLen){
		GetSepStr(str,',',i,Temp);
		iOffset+=GenUeSettleStr(Temp,sTemp+iOffset,i);
		i++;
	}
	
	if(GenerationUeBinTree(sTemp,asBintreeArray)<0){
		printf("%s\n",sTemp);
		return -1;
	}
	
	return 0;
}
int SettleMentSM(char str[],struct SettleBintreeStruct asBintreeArray[])
{
	
	int i=0;
	int iOffset=0;
	int iLen=0;
	char *p;
	char Temp[4096],sTemp[4096];
	char delims=44;
	
	p=str;
	while(*p!='\0'){
		if(*p==','){
			iLen++;
		}
		p++;
	}
	while(i<=iLen){
		GetSepStr(str,',',i,Temp);
		iOffset+=GenSmSettleStr(Temp,sTemp+iOffset,i);
		i++;
	}
	
	if(GenerationSmBinTree(sTemp,asBintreeArray)<0){
		printf("%s\n",sTemp);
		return -1;
	}
	
	return 0;
}	
int SettleMentMMS(char str[],struct SettleBintreeStruct asBintreeArray[])
{
	
	int i=0;
	int iOffset=0;
	int iLen=0;
	char *p;
	char Temp[4096],sTemp[4096];
	char delims=44;
	
	p=str;
	while(*p!='\0'){
		if(*p=='\t'){
			iLen++;
		}
		p++;
	}
	while(i<=iLen){
		GetSepStr(str,'\t',i,Temp);
		iOffset+=GenMmsSettleStr(Temp,sTemp+iOffset,i);
		i++;
	}
	
	if(GenerationMmsBinTree(sTemp,asBintreeArray)<0){
		printf("%s\n",sTemp);
		return -1;
	}
	
	return 0;
}	
int TravelFileList(struct FileControlStruct *ptHead,
			char sMark[],struct SettleBintreeStruct asBintreeArray[])
{
	char sStr[2048];
	struct FileControlStruct *pTemp;
	int iLen;
	int iCnt=0,iTotalCnt=0;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		memset((void*)sStr,0,sizeof(sStr));
		memcpy(sStr,pTemp->pData,pTemp->iLen);
		sStr[pTemp->iLen]=0;
		
/*		iCnt+=strlen(sStr);*/
		
		if((strcmp(sMark,"YD"))==0 || (strcmp(sMark,"GW"))==0){
			if(SettleMentYD(sStr,asBintreeArray)<0) return -1;
		}
		else if(strcmp(sMark,"SM")==0){
			if(SettleMentSM(sStr,asBintreeArray)<0) return -1;
		}
		/*20160701,�޸Ĳ��Ŵ���ʽ�����һ�£����벻��Ҫ������ֱ�Ӹ���ʹ�ã������޸���ע��*/
		else if(strcmp(sMark,"MS")==0){
			if(SettleMentSM(sStr,asBintreeArray)<0) return -1;
		}
		/*�ô���ʽΪ20160701ǰ����ʽ�������ţ��Ա�ǰ���else if��ȡ��������ִ�е���*/
		else{
			if(SettleMentMMS(sStr,asBintreeArray)<0) return -1;
		}
		
		strcpy(sStr,"");
		
		iTotalCnt++;
		
	}
	
	return iTotalCnt;
}

int MyChkDir(char sPath[])
{
	if(strcmp(sPath,"/nil/")==0) return -1;
	return CheckDir(sPath);
}
int FreeUeMemList(struct SettTicketUeStruct *ptHead)
{
	int iCnt=0;
	struct SettTicketUeStruct *pTemp=NULL,*ptLkHead;
	
	while(ptHead!=NULL){
		ptLkHead=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLkHead!=NULL){
			pTemp=ptLkHead;
			ptLkHead=ptLkHead->pNext;
			
			free(pTemp);	
			iCnt++;
		}
	}
	ptHead=NULL;
	
	return iCnt;
}
int FreeSmMemList(struct SettTicketSmStruct *ptHead)
{
	int iCnt=0;
	struct SettTicketSmStruct *pTemp=NULL,*ptLkHead;
	
	while(ptHead!=NULL){
		ptLkHead=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLkHead!=NULL){
			pTemp=ptLkHead;
			ptLkHead=ptLkHead->pNext;
			
			free(pTemp);	
			iCnt++;
		}
	}
	ptHead=NULL;
	
	return iCnt;
}
int FreeMmsMemList(struct SettTicketMmsStruct *ptHead)
{
	int iCnt=0;
	struct SettTicketMmsStruct *pTemp=NULL,*ptLkHead;
	
	while(ptHead!=NULL){
		ptLkHead=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLkHead!=NULL){
			pTemp=ptLkHead;
			ptLkHead=ptLkHead->pNext;
			
			free(pTemp);	
			iCnt++;
		}
	}
	ptHead=NULL;
	
	return iCnt;
}
/*ɾ���굥�������*/
void DeleteTableData(char sTableName[],char sFileName[])
{
	char statement[1024];
	
	sprintf(statement,"DELETE FROM %s WHERE FILE_NAME='%s'",sTableName,sFileName);
	if(ExecSql(statement)<0){
		WriteAlertMsg("ִ��%sʧ��",statement);
		exit (-1);
	}
	CommitWork();
}
/*������־�ĳɹ���ʶ*/
void UpdateTableData(char sTableName[],int iFileLines,char sFileName[])
{
	char statement[1024];
	
	sprintf(statement,"UPDATE %s SET STATE='T',FILE_LINES=%d WHERE FILE_NAME='%s'",
		sTableName,iFileLines,sFileName);
	if(ExecSql(statement)<0){
		WriteAlertMsg("ִ��%sʧ��",statement);
		exit (-1);
	}
	CommitWork();	
}

int InitBintreeArray(struct SettleBintreeStruct asBintreeArray[])
{
	int i=0;
	struct SettTicketUeStruct *pStatList=NULL;

	while(i<13){
		gSettStatUeList=NULL;
		TravelBin(asBintreeArray[i].ptRoot,append_bintree_to_list_day_stat);	

		pStatList=gSettStatUeList;
		FreeUeMemList(pStatList);
		DestroyBin(asBintreeArray[i].ptRoot);
		
		i++;
	}
	return 0;
}

int ProcessMain(struct DispParamStruct *pParam,char sMark[],
	char sSourceDir[],char sTargetDir[],struct SettleBintreeStruct asBintreeArray[])
{
	int l=0,iSum=0,i=0;
	int iCnt=0,iM=0,iTotalCnt=0;
	char sMonth[5],sCommondMV[2048],sCondition[1024];
	char sFileName[256],sTempName[256],sHostTime[15];
	char sCommond[2048],sTableName[Maxsize];
	struct FileControlStruct *ptList=NULL;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	struct SettTicketUeStruct *pStatList=NULL;
	struct SettBillStorLogStruct Temp;
/*����һ���ļ��б�*/
	if(dir2list(pParam->sSourcePath,pParam->sFilter,&ptHead)<0){
		WriteAlertPrint("�����ļ��б�ʧ�� %s %s",
			pParam->sSourcePath,pParam->sFilter);
		return -1;
	}
	
	ptLkHead=ptHead;

	/*��������ļ�*/
	while( ptHead != NULL ){

		pTemp = ptHead;
		ptHead = ptHead->pNext;

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		
		strncpy(sMonth,sFileName+18,2);
		sMonth[2]=0;
		strcpy(gsMonth,sMonth);
		
		sprintf(sCondition," WHERE FILE_NAME='%s' ",sFileName);
		if(SDGetSettBillStorLogToStruct(&Temp,"SETT_BILL_STOR_LOG",sCondition)==true){
			if(strcmp(Temp.sState,"T")==0){
				sprintf(sCommond,"rm %s%s",pParam->sSourcePath,sFileName);
				sprintf(sCommondMV,"mv %s%s /ticket/cdr/zjc_bak/%s ",pParam->sSourcePath,sTempName,sTempName);
				system(sCommond);
				continue;
			}
			
		}else{
			strcpy(Temp.sFileName,sFileName);
			strncpy(Temp.sFileDate,sFileName+14,8);Temp.sFileDate[8]=0;
			GetHostTime(sHostTime);
			strcpy(Temp.sDealTime,sHostTime);
			strcpy(Temp.sState,"F");
			sprintf(sTempName,"%s%s",pParam->sSourcePath,sFileName);
			Temp.iFileSize=FileSize(sTempName);
			Temp.iFileLines=0;
			
			if(SDInsertStructToSettBillStorLog(&Temp,"SETT_BILL_STOR_LOG")<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
		}
		
		sprintf(sTempName,"%s%s",pParam->sSourcePath,sFileName);
		strcpy(gsFileName,sFileName);
		while(iM<13){
			strcpy(asBintreeArray[iM].sNetWork,"");
			strcpy(asBintreeArray[iM].sOperators,"");
			iM++;
		}
		
		GetAsBintreeArrayTable(asBintreeArray);
		
		if(TxtFileToList(sTempName,&ptList)<0){
			InitBintreeArray(asBintreeArray);
			continue;
		}
	
		if((iSum=TravelFileList(ptList,sMark,asBintreeArray))<0){
			listfree(&ptList);
			InitBintreeArray(asBintreeArray);
			DestroyList((LIST*)gSettInsertList);
			gSettInsertList=NULL;
			sprintf(sCommond,"mv %s %s.err",sTempName,sTempName);
			system(sCommond);
			continue;
		}
		listfree(&ptList);
		if(strcmp(sMark,"YD")==0||strcmp(sMark,"GW")==0){
			while(i<12){
				gSettStatUeList=NULL;
				
				TravelBin(asBintreeArray[i].ptRoot,append_bintree_to_list_day_stat);	
			
				sprintf(sTableName,"T_%s_UE_%s_%s",asBintreeArray[i].sNetWork,
						asBintreeArray[i].sOperators,sMonth);
				
				pStatList=gSettStatUeList;
				
				if(EInsertList2Table(sTableName,gSettStatUeList)<0) return -1;
			
				FreeUeMemList(pStatList);
				
				DestroyBin(asBintreeArray[i].ptRoot);
				
				i++;
			}
		}
		else if(strcmp(sMark,"SM")==0){
			gSettStatSmList=NULL;
			sprintf(sTableName,"ST_SMS_TICKET_%s",sMonth);

			TravelBin(asBintreeArray[12].ptRoot,append_bintree_to_list_sm_day_stat);
			if(EInsertSmList2Table(sTableName,gSettStatSmList)<0) return -1;

			FreeSmMemList(gSettStatSmList);

			DestroyBin(asBintreeArray[12].ptRoot);
			i++;
		}
		/*20160701,�޸Ĳ�����ⷽʽ�����һ�£����벻��Ҫ������ֱ�Ӹ���ʹ�ã������޸���ע��*/
		
		else if(strcmp(sMark,"MS")==0){
			gSettStatSmList=NULL;
			sprintf(sTableName,"ST_MMS_TICKET_%s",sMonth);

			TravelBin(asBintreeArray[12].ptRoot,append_bintree_to_list_sm_day_stat);
			if(EInsertSmList2Table(sTableName,gSettStatSmList)<0) return -1;

			FreeSmMemList(gSettStatSmList);

			DestroyBin(asBintreeArray[12].ptRoot);
			i++;
		}
		/*�ô���ʽΪ20160701ǰ����ʽ�������ţ��Ա�ǰ���else if��ȡ��������ִ�е���*/
		else{
			gSettStatMmsList=NULL;
			sprintf(sTableName,"ST_MMS_TICKET_%s",sMonth);

			TravelBin(asBintreeArray[12].ptRoot,append_bintree_to_list_mms_day_stat);
			
			if(EInsertMmsList2Table(sTableName,gSettStatMmsList)<0) return -1;

			FreeMmsMemList(gSettStatMmsList);

			DestroyBin(asBintreeArray[12].ptRoot);
			i++;
		
		}
		
		if(EInsertList2SettInsertLogTable(gSettInsertList)<0) return -1;
		DestroyList((LIST*)gSettInsertList);
		gSettInsertList=NULL;
		
		i=0;
		UpdateTableData("SETT_BILL_STOR_LOG",iSum,sFileName);
/*		sprintf(sCommondMV,"rm %s ",sTempName);*/
		sprintf(sCommondMV,"mv %s /ticket/cdr/zjc_bak/%s ",sTempName,sFileName);
		system(sCommondMV);
		
		WriteProcPrint("���ļ�%s�ֽ�ɹ�",sFileName);
		
		if((++iTotalCnt)%400==0) break;
		
	}
	listfree(&ptLkHead);

	return 0;
}

int main(int argc,char *argv[])
{
	int iGroupID,iRet,iNum;
	char sSourceDir[256],sTargetDir[256];
	char sFileName[Maxsize],sTemp[Maxsize];
	char sMark[10];
	char sTablefile[80],sDirFileName[Maxsize],sFile[Maxsize];
	struct SettleBintreeStruct asBintreeArray[15];
	struct DispParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	int iSize=0,j=0,m=0;
	
	if(argc != 3){
		WriteProcPrint("Usage: %s *.ini GroupID!!!",argv[0]);
		return -1;
	}

	
	strcpy(sDirFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	
	InitAppRes(argv[0]);
	
	if(ConnectDataDB()<0) return -1;
		
	if(GetDispParamList(sDirFileName,iGroupID,&ptHead)<0) return -1;
	
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*�������Ϸ���.*/

		if(IsDir(pTemp->sSourcePath)==FALSE){
			WriteAlertMsg("����Ŀ¼%s��Ч.",pTemp->sSourcePath);
			continue;
		}

		/*Ŀ��Ŀ¼����������,����/nilĿ¼
		if(MyChkDir(pTemp->sDestPath1)<0)strcpy(pTemp->sDestPath1,"");
		if(MyChkDir(pTemp->sDestPath2)<0)strcpy(pTemp->sDestPath2,"");
		if(MyChkDir(pTemp->sDestPath3)<0)strcpy(pTemp->sDestPath3,"");
		if(MyChkDir(pTemp->sDestPath4)<0)strcpy(pTemp->sDestPath4,"");
		*/
		strcpy(sSourceDir,pTemp->sDestPath1);
		strcpy(sTargetDir,pTemp->sDestPath2);
		strncpy(sMark,pTemp->sDestPath3,2);
		sMark[2]=0;
		AllTrim(sMark);
		Upper(sMark);
		strcpy(gsMark,sMark);
		iRet=ProcessMain(pTemp,sMark,sSourceDir,sTargetDir,asBintreeArray);

		if(iRet<0){
			WriteAlertMsg("�ַ��ļ�ʧ��!");
			return -1;
		}
		if(iRet>0) break;
	}
	
	DisconnectDatabase();	
	
	return 0;
}
