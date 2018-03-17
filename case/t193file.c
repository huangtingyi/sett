#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>
#include <wwfile.h>
#include <wwdir.h>
#include <stt_ticket.h>
#include "param_intf.h"
#include "wwshm.h"
#include "t193file.h"

struct T193StatAllStruct FileStat;
BINTREE *pRoot=NULL;
BINTREE *pFileRoot=NULL;
FILE *fp=NULL;
char sProcDate[15];

void GetT193CallingAreaCode(struct SttTicketStruct *pSource,
	char sCallingAreaCode[])
{

	strncpy(sCallingAreaCode,"0",1);
	strncat(sCallingAreaCode,pSource->sHomeAreaCode,5);
	AllTrim(sCallingAreaCode);

	if(strncmp(sCallingAreaCode,"0935c",5)==0)
		sCallingAreaCode[4]=0;
	else if(strncmp(sCallingAreaCode,"0935w",5)==0)
		sCallingAreaCode[4]=0;
	else if(strncmp(sCallingAreaCode,"0937q",5)==0)
		sCallingAreaCode[4]=0;
	else if(strncmp(sCallingAreaCode,"0937y",5)==0)
		sCallingAreaCode[4]=0;
}

void GetT193CalledAreaCode(struct SttTicketStruct *pSource,
	char sCalledAreaCode[])
{
	char sDistanceType[2];
	char sCallNbr[11];

	memset(sDistanceType,0,2);
	memset(sCallNbr,0,11);

	/*�����������*/
	strncpy(sDistanceType,pSource->sDistanceType,1);
	switch(sDistanceType[0])
	{
		case '1':/*����*/
		case '2':/*2	ʡ��*/
			break;/*ȱʡ����,�ϴ�Ϊʡ��*/
		case '3':/*3	ʡ��*/
			sDistanceType[0] ='2';/*�ϴ�ʡ����2*/
			break;
		case '4':/*4	�۰�̨*/
			sDistanceType[0] ='3';/*�ϴ��۰�̨��3*/
			break;
		case '5':/*5	����*/
			sDistanceType[0] ='4';/*�ϴ�������4*/
			break;
		default:/*�������û������ߴ���*/
			break;
	}
	strncpy(sCalledAreaCode,sDistanceType,1);
	strncat(sCalledAreaCode,"0",1);
	strcat(sCallNbr,pSource->sCalledCode);
	AllTrim(sCallNbr);

	if(strncmp(sCallNbr,"935c",4)==0)	sCallNbr[3]=0;
	else if(strncmp(sCallNbr,"935w",4)==0)	sCallNbr[3]=0;
	else if(strncmp(sCallNbr,"937q",4)==0)	sCallNbr[3]=0;
	else if(strncmp(sCallNbr,"937y",4)==0)	sCallNbr[3]=0;

        /*by cdp 20050902*/
        if(!isdigit(sCallNbr[3])) sCallNbr[3]=0;

	strcat(sCalledAreaCode,sCallNbr);
}

void GetT193BusinessType(struct SttTicketStruct *pSource,
	char sBusinessType[])
{
	/*������Ӫ������*/
	char sCallingCarrierID[5];
	int  iCallingCarrierID;

	memset(sCallingCarrierID,0,5);
	iCallingCarrierID = pSource->iCallingCarrierID;
	switch(iCallingCarrierID)
	{
		case 1:/*�й�����*/
			sprintf(sCallingCarrierID,"0%d",4);/*�ϴ�ʱ����й�����*/
			break;
		case 2:/*�й��ƶ�*/
			sprintf(sCallingCarrierID,"0%d",5);/*�ϴ�ʱ����й��ƶ�**/
			break;
		case 3:/*�й���ͨ*/
			sprintf(sCallingCarrierID,"0%d",1);/*�ϴ�ʱ����й���ͨ*/
			break;
		case 4:/*�й���ͨ*/
			sprintf(sCallingCarrierID,"0%d",2);/*�ϴ�ʱ����й���ͨ*/
			break;
		case 5:/*�й���ͨ*/
			sprintf(sCallingCarrierID,"0%d",3);/*�ϴ�ʱ����й���ͨ*/
			break;
		default:/*����*/
			sprintf(sCallingCarrierID,"%d",99);/*�ϴ�ʱ�����������*/
			break;
	}
	memset(sBusinessType,0,sizeof(sBusinessType));
	strncpy(sBusinessType,sCallingCarrierID,2);
}

void GetT193UserGroupType(struct SttTicketStruct *pSource,
	char sUserGroupType[])
{
	int  iCallingCarrierID;
	iCallingCarrierID = pSource->iCallingCarrierID;

	/*�����û�Ⱥ����*/
	memset(sUserGroupType,0,sizeof(sUserGroupType));
	if(iCallingCarrierID==1 || iCallingCarrierID==4 || iCallingCarrierID==5)
	/*PSTN�û�*/
		strncpy(sUserGroupType,"01",2);
	else if(strncmp(pSource->sMsisdn,"133",3)==0)
	/*��ͨC���û�*/
		strncpy(sUserGroupType,"02",2);
	else if(strncmp(pSource->sMsisdn,"130",3)==0||
		strncmp(pSource->sMsisdn,"131",3)==0||
		strncmp(pSource->sMsisdn,"132",3)==0)
	/*��ͨG���û�*/
		strncpy(sUserGroupType,"03",2);
	else
	/*�����û�*/
		strncpy(sUserGroupType,"99",2);
}

void GetT193OperationType(struct SttTicketStruct *pSource,
	char sOperationType[])
{
	/*����ҵ������*/
	memset(sOperationType,0,sizeof(sOperationType));
	if(strncmp(pSource->sUserType,"1",1)==0)
	/*193ҵ��*/
		strncpy(sOperationType,"2",1);
	else if(strncmp(pSource->sUserType,"I",1)==0)
	/*VoIPҵ��*/
		strncpy(sOperationType,"1",1);
	else
	/*����ҵ��*/
		strncpy(sOperationType,"9",1);

}

void GetT193NetRouteType(struct SttTicketStruct *pSource,
	char sNetRouteType[])
{
	/*����·������*/
	memset(sNetRouteType,0,sizeof(sNetRouteType));
	if(strncmp(pSource->sUserType,"1",1)==0)
	/*193ҵ��*/
		strncpy(sNetRouteType,"2",1);
	else if(strncmp(pSource->sUserType,"I",1)==0)
	/*VoIPҵ��*/
		strncpy(sNetRouteType,"1",1);
	else
	/*����ҵ��*/
		strncpy(sNetRouteType,"9",1);
}

void GetT193CalledType(struct SttTicketStruct *pSource,
	char sCalledType[])
{
	int  iCallingCarrierID;
	iCallingCarrierID = pSource->iCallingCarrierID;

	/*��������*/
	memset(sCalledType,0,sizeof(sCalledType));
	if(iCallingCarrierID==1 ||iCallingCarrierID==4 || iCallingCarrierID==5)
	/*PSTN�û�*/
		strncpy(sCalledType,"0001",4);
	else if(pSource->iCalledTypeID==3001)
	/*��ͨC���û�*/
		strncpy(sCalledType,"0102",4);
	else if(pSource->iCalledTypeID==3002)
	/*��ͨG���û�*/
		strncpy(sCalledType,"0103",4);
	else if(pSource->iCalledTypeID==2001)
	/*�ƶ�G���û�*/
		strncpy(sCalledType,"0503",4);
	else if(strncmp(pSource->sDistanceType,"5",1)==0)
	/*�����û�*/
		strncpy(sCalledType,"9090",4);
	else
	/*�����û�*/
		strncpy(sCalledType,"9999",4);
}



void GenT193FileHead(struct T193StatAllStruct *FileStat,
	struct T193FileHeadStruct *pFileHead)
{
	sprintf(pFileHead->sSumAllFileRecord,	"%012d",FileStat->iSumAllFileRecord);
	sprintf(pFileHead->sSumAllCallDuration,	"%015d",FileStat->iSumAllCallDuration);
	sprintf(pFileHead->sSumAllUnits,	"%015d",FileStat->iSumAllUnits);
	sprintf(pFileHead->sSumAllCall,		"%015d",FileStat->iSumAllCall);
	sprintf(pFileHead->sSumAllCallFee,	"%015d",FileStat->iSumAllCallFee);
}

int StatAll(void **ppRoot)
{
	struct T193StatStruct *pTemp=(*ppRoot);

	if(pTemp!=NULL){
		FileStat.iSumAllFileRecord 	+=1;
		FileStat.iSumAllCallDuration	+=pTemp->iSumCallDuration;
		FileStat.iSumAllUnits 		+=pTemp->iSumUnits;
		FileStat.iSumAllCall		+=pTemp->iSumCall;
		FileStat.iSumAllCallFee		+=pTemp->iSumCallFee;
	}
	return 0;
}

/*�ۼӼ�¼*/
void SumValue(struct T193StatStruct *pTemp,
	struct SttTicketStruct *pRecordData)
{
	pTemp->iSumCallDuration	+=pRecordData->iDuration;
	pTemp->iSumUnits	+=(pRecordData->iDuration+5)/6;
	pTemp->iSumCall		++;
	pTemp->iSumCallFee	=pTemp->iSumCallFee+
				pRecordData->iRoamFee+
				pRecordData->iTollFee+
				pRecordData->iAddFee;
}

/*�������ⲿҪ����Ľṹ����ǰ����������*/
int data_search_bintree_T193record(void *pValue,void*pData)
{

	char sCallingAreaCode[11],sCalledAreaCode[11],sBusinessType[3],
		sUserGroupType[3],sOperationType[2],sNetRouteType[2],sCalledType[5];
	struct SttTicketStruct *pSource=(struct SttTicketStruct *)pValue;
	struct T193StatStruct *pTarget=(struct T193StatStruct *)pData;
	int res;

	memset(sCallingAreaCode,0,11);
	memset(sCalledAreaCode,0,11);
	memset(sBusinessType,0,3);
	memset(sUserGroupType,0,3);
	memset(sOperationType,0,2);
	memset(sNetRouteType,0,2);
	memset(sCalledType,0,5);

	GetT193CallingAreaCode(pSource,sCallingAreaCode);
	GetT193CalledAreaCode(pSource,sCalledAreaCode);
	GetT193BusinessType(pSource,sBusinessType);
	GetT193UserGroupType(pSource,sUserGroupType);
	GetT193OperationType(pSource,sOperationType);
	GetT193NetRouteType(pSource,sNetRouteType);
	GetT193CalledType(pSource,sCalledType);

	res=0;

	if((res=strcmp(sCallingAreaCode,pTarget->sCallingAreaCode))!=0)
		return res;
	if((res=strcmp(sCalledAreaCode,pTarget->sCalledAreaCode))!=0)
		return res;
	if((res=strcmp(sBusinessType,pTarget->sBusinessType))!=0)
		return res;
	if((res=strcmp(sUserGroupType,pTarget->sUserGroupType))!=0)
		return res;
	if((res=strcmp(sOperationType,pTarget->sOperationType))!=0)
		return res;
	if((res=strcmp(sNetRouteType,pTarget->sNetRouteType))!=0)
		return res;
	if((res=strcmp(sCalledType,pTarget->sCalledType))!=0)
		return res;

	return res;
}

void assign_insert_bintree_T193record(void **ppData,void *pData)
{
	struct T193StatStruct *pTemp;
	struct SttTicketStruct *pRecordData=(struct SttTicketStruct*)pData;

	/*����һ�ε��øú��������������Ĺ����У���*ppData��û��������*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct T193StatStruct));
		ERROR_EXIT(pTemp==NULL,"����T193StatStruct�ṹ����");
		bzero((void*)pTemp,sizeof(struct T193StatStruct));

		/*��������ڸ�sVisitAreaCode��sOppAreaCode���������������*/
		/*�����ݹ���,���ɽ��ļ�ֵ*/
		GetT193CallingAreaCode((struct SttTicketStruct*)pData,
			pTemp->sCallingAreaCode);
		GetT193CalledAreaCode((struct SttTicketStruct*)pData,
			pTemp->sCalledAreaCode);
		GetT193BusinessType((struct SttTicketStruct*)pData,
			pTemp->sBusinessType);
		GetT193UserGroupType((struct SttTicketStruct*)pData,
			pTemp->sUserGroupType);
		GetT193OperationType((struct SttTicketStruct*)pData,
			pTemp->sOperationType);
		GetT193NetRouteType((struct SttTicketStruct*)pData,
			pTemp->sNetRouteType);
		GetT193CalledType((struct SttTicketStruct*)pData,
			pTemp->sCalledType);

		SumValue(pTemp,pRecordData);

		/*������õĽ���������һؽ����*/
		*ppData=(void*)pTemp;

		return;
	}
	/*����ҵ���ͬ�ļ�ֵ�Ľ��,���ݶ�Ӧticket_type_id�ۼӼǷ���,ʱ��,����*/
	pTemp=(*ppData);

	SumValue(pTemp,pRecordData);
}

int PrintT193Stat(void **ppRoot)
{
	struct T193StatStruct *pTemp=(*ppRoot);
	if(pTemp!=NULL){
		printf("%s\t",pTemp->sCallingAreaCode);
		printf("%s\t",pTemp->sCalledAreaCode);
		printf("%s\t",pTemp->sBusinessType);
		printf("%s\t",pTemp->sUserGroupType);
		printf("%s\t",pTemp->sOperationType);
		printf("%s\t",pTemp->sNetRouteType);
		printf("%s\t",pTemp->sCalledType);
		printf("%d\t",pTemp->iSumCallDuration);
		printf("%d\t",pTemp->iSumUnits);
		printf("%d\t",pTemp->iSumCall);
		printf("%d\n",pTemp->iSumCallFee);
	}
	return 0;
}

void OutputT193FileHead(struct T193FileHeadStruct *pFileHead,char sFileOpMode[])
{
	int l=0;
	char *pc,sRecord[200];

	pc=(char*)pFileHead;
	
	l+=sprintf(sRecord+l,"%s%1s\r\n",pc,sFileOpMode);
	WriteFile(fp,sRecord,l);
}

int OutputT193FileBody(void **ppRoot)
{
	struct T193StatStruct *pTemp=(*ppRoot);
	char sRecord[200],sTempDate[9];
	int l=0;

	if(pTemp!=NULL){

		pTemp->sCallingAreaCode[5]=0;
		pTemp->sCalledAreaCode[10]=0;
		pTemp->sBusinessType[2]=0;
		pTemp->sUserGroupType[2]=0;
		pTemp->sOperationType[1]=0;
		pTemp->sNetRouteType[1]=0;
		pTemp->sCalledType[4]=0;
		strncpy(sTempDate,sProcDate,8);sTempDate[8]=0;
		
		l=0;

		LeftPad(pTemp->sBusinessType,2,'0');
		LeftPad(pTemp->sUserGroupType,2,'0');
		LeftPad(pTemp->sOperationType,1,'0');
		LeftPad(pTemp->sNetRouteType,1,'0');
		LeftPad(pTemp->sCalledType,4,'0');

		l+=sprintf(sRecord+l,"%-5s%-10s%2s%2s%1s%1s%4s",
			pTemp->sCallingAreaCode,pTemp->sCalledAreaCode,
			pTemp->sBusinessType,pTemp->sUserGroupType,
			pTemp->sOperationType,pTemp->sNetRouteType,
			pTemp->sCalledType);
		
		l+=sprintf(sRecord+l,"%010d%010d%010d%010d%-8s\r\n",
			pTemp->iSumCallDuration,pTemp->iSumUnits,
			pTemp->iSumCall,pTemp->iSumCallFee,sTempDate);

		WriteFile(fp,sRecord,l);
	}
	return 0;
}

int main(int argc,char *argv[])
{
	int iCount=0;
	char sProvCode[4],sFileSeq[3],sFileOpMode[2],sTableName[31];
	char sServiceType[6],sOutputDir[80],sOutputFileName[256],sBaseFileName[20];

        struct SttTicketStruct Temp;
        struct SttTicketStructIn TempIn;
        struct T193FileHeadStruct *pFileHead;

	if(argc!=7&&argc!=8){
		printf("Usage %s ServiceType OutputDir ProvinceCode FileSeq FileOpMode tablename [procdate].\n",argv[0]);
		return -1;
	}

	strcpy(sServiceType,argv[1]);
	strcpy(sOutputDir,argv[2]);
	strcpy(sProvCode,argv[3]);
	strcpy(sFileSeq,argv[4]);
	strcpy(sFileOpMode,argv[5]);

	/*ȡ����*/
	strcpy(sTableName,argv[6]);
	if(argc==8){
		strncpy(sProcDate,argv[7],8);
	}
	else{
		GetHostTime(sProcDate);
		AddDays(sProcDate,-1);
	}
	sProcDate[8]='\0';


	/*�������Ϸ���*/
	if(strcmp(sServiceType,"193")!=0 && strcmp(sServiceType,"17911")!=0){
		printf("���ҵ�����%s��Ч.\n",sServiceType);
		WriteAlertMsg(">:���ҵ�����%s��Ч.\n",sServiceType);
		return -1;
	}
	if(IsDir(sOutputDir)==FALSE){
		printf("�������Ŀ¼%s��Ч.\n",sOutputDir);
		WriteAlertMsg(">:�������Ŀ¼%s��Ч.\n",sOutputDir);
		return -1;
	}

	if(sFileOpMode[0]!='I' &&  sFileOpMode[0]!='C' &&
		sFileOpMode[0]!='U' && sFileOpMode[0]!='D'){
		printf("�������־%s��Ч.\n",sFileOpMode);
		WriteAlertMsg(">:�������־%s��Ч.\n",sFileOpMode);
		return -1;
	}

	if(strcmp(sServiceType,"193")==0)strcpy(sBaseFileName,"SU");
	else strcpy(sBaseFileName,"JU");
	strncat(sBaseFileName,sProcDate,8);
	strncat(sBaseFileName,sFileSeq,2);
	strncat(sBaseFileName,".",1);
	strncat(sBaseFileName,sProvCode,3);

	strcat(sOutputDir,"/");
	strcpy(sOutputFileName,sOutputDir);
	strcat(sOutputFileName,sBaseFileName);

	InitAppRes(argv[0]);
	IniConnect("dataconnstr");

	bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));

	/*�ô�����select����*/
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"WHERE substr(START_TIME,1,8)='%s' \n\
		AND ROAM_TYPE IN('1','2')",sProcDate);

        Upper(TempIn.sTableName);

	pFileHead=(struct T193FileHeadStruct *)
		malloc(sizeof(struct T193FileHeadStruct));
	ERROR_EXIT(pFileHead==NULL,"����T193FileHeadStruct�ṹ����");

	TempIn.iBufEmpty=TRUE;
        TempIn.iFirstFlag=TRUE;

        /*ȡ�����м�¼���ض������������ļ����¼�ṹ*/
        if(strcmp(sServiceType,"193")==0){
	        while(EGetSttTicketToStruct(&Temp,&TempIn)){
			iCount++;
	                if(InsertBin(&pRoot,(void *)&Temp,
				data_search_bintree_T193record,
				assign_insert_bintree_T193record)<0){
				WriteAlertMsg("����BINTREEʧ��T193RECORD");
				return -1;
			}
	        }
	}
	else{
	        while(EGetSttTicketToStruct(&Temp,&TempIn)){
			iCount++;
	                if(InsertBin(&pRoot,(void *)&Temp,
				data_search_bintree_T193record,
				assign_insert_bintree_T193record)<0){
				WriteAlertMsg("����BINTREEʧ��T193RECORD");
				return -1;
			}
	        }
	}

/*	TravelBin(pRoot,PrintT193Stat);*/
        TravelBin(pRoot,StatAll);

	if((fp=fopen(sOutputFileName,"w"))==NULL) return -1;

	/*����ļ�*/
	GenT193FileHead(&FileStat,pFileHead);
	OutputT193FileHead(pFileHead,sFileOpMode);
	TravelBin(pRoot,OutputT193FileBody);

	printf("�ļ� %s �������.\n",sBaseFileName);
	WriteProcMsg("�ļ� %s �������.",sBaseFileName);

	fclose(fp);
	DisconnectDatabase();
	return 0;
}
