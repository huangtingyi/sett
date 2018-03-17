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

	/*被叫区域代码*/
	strncpy(sDistanceType,pSource->sDistanceType,1);
	switch(sDistanceType[0])
	{
		case '1':/*本地*/
		case '2':/*2	省内*/
			break;/*缺省不变,上传为省内*/
		case '3':/*3	省际*/
			sDistanceType[0] ='2';/*上传省际是2*/
			break;
		case '4':/*4	港澳台*/
			sDistanceType[0] ='3';/*上传港澳台是3*/
			break;
		case '5':/*5	国际*/
			sDistanceType[0] ='4';/*上传国际是4*/
			break;
		default:/*其他来访话单或者错误*/
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
	/*接入运营商类型*/
	char sCallingCarrierID[5];
	int  iCallingCarrierID;

	memset(sCallingCarrierID,0,5);
	iCallingCarrierID = pSource->iCallingCarrierID;
	switch(iCallingCarrierID)
	{
		case 1:/*中国电信*/
			sprintf(sCallingCarrierID,"0%d",4);/*上传时候的中国电信*/
			break;
		case 2:/*中国移动*/
			sprintf(sCallingCarrierID,"0%d",5);/*上传时候的中国移动**/
			break;
		case 3:/*中国联通*/
			sprintf(sCallingCarrierID,"0%d",1);/*上传时候的中国联通*/
			break;
		case 4:/*中国网通*/
			sprintf(sCallingCarrierID,"0%d",2);/*上传时候的中国网通*/
			break;
		case 5:/*中国铁通*/
			sprintf(sCallingCarrierID,"0%d",3);/*上传时候的中国铁通*/
			break;
		default:/*其他*/
			sprintf(sCallingCarrierID,"%d",99);/*上传时候的其他电信*/
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

	/*接入用户群类型*/
	memset(sUserGroupType,0,sizeof(sUserGroupType));
	if(iCallingCarrierID==1 || iCallingCarrierID==4 || iCallingCarrierID==5)
	/*PSTN用户*/
		strncpy(sUserGroupType,"01",2);
	else if(strncmp(pSource->sMsisdn,"133",3)==0)
	/*联通C网用户*/
		strncpy(sUserGroupType,"02",2);
	else if(strncmp(pSource->sMsisdn,"130",3)==0||
		strncmp(pSource->sMsisdn,"131",3)==0||
		strncmp(pSource->sMsisdn,"132",3)==0)
	/*联通G网用户*/
		strncpy(sUserGroupType,"03",2);
	else
	/*其他用户*/
		strncpy(sUserGroupType,"99",2);
}

void GetT193OperationType(struct SttTicketStruct *pSource,
	char sOperationType[])
{
	/*承载业务类型*/
	memset(sOperationType,0,sizeof(sOperationType));
	if(strncmp(pSource->sUserType,"1",1)==0)
	/*193业务*/
		strncpy(sOperationType,"2",1);
	else if(strncmp(pSource->sUserType,"I",1)==0)
	/*VoIP业务*/
		strncpy(sOperationType,"1",1);
	else
	/*其他业务*/
		strncpy(sOperationType,"9",1);

}

void GetT193NetRouteType(struct SttTicketStruct *pSource,
	char sNetRouteType[])
{
	/*网络路由类型*/
	memset(sNetRouteType,0,sizeof(sNetRouteType));
	if(strncmp(pSource->sUserType,"1",1)==0)
	/*193业务*/
		strncpy(sNetRouteType,"2",1);
	else if(strncmp(pSource->sUserType,"I",1)==0)
	/*VoIP业务*/
		strncpy(sNetRouteType,"1",1);
	else
	/*其他业务*/
		strncpy(sNetRouteType,"9",1);
}

void GetT193CalledType(struct SttTicketStruct *pSource,
	char sCalledType[])
{
	int  iCallingCarrierID;
	iCallingCarrierID = pSource->iCallingCarrierID;

	/*被叫类型*/
	memset(sCalledType,0,sizeof(sCalledType));
	if(iCallingCarrierID==1 ||iCallingCarrierID==4 || iCallingCarrierID==5)
	/*PSTN用户*/
		strncpy(sCalledType,"0001",4);
	else if(pSource->iCalledTypeID==3001)
	/*联通C网用户*/
		strncpy(sCalledType,"0102",4);
	else if(pSource->iCalledTypeID==3002)
	/*联通G网用户*/
		strncpy(sCalledType,"0103",4);
	else if(pSource->iCalledTypeID==2001)
	/*移动G网用户*/
		strncpy(sCalledType,"0503",4);
	else if(strncmp(pSource->sDistanceType,"5",1)==0)
	/*国际用户*/
		strncpy(sCalledType,"9090",4);
	else
	/*其他用户*/
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

/*累加记录*/
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

/*参数：外部要插入的结构，当前结点的数据区*/
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

	/*当第一次调用该函数（即创建结点的过程中），*ppData还没加载数据*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct T193StatStruct));
		ERROR_EXIT(pTemp==NULL,"分配T193StatStruct结构错误");
		bzero((void*)pTemp,sizeof(struct T193StatStruct));

		/*如果不存在该sVisitAreaCode与sOppAreaCode，定义结点的数据区*/
		/*做数据关联,生成结点的键值*/
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

		/*将定义好的结点数据区挂回结点上*/
		*ppData=(void*)pTemp;

		return;
	}
	/*如果找到相同的键值的结点,根据对应ticket_type_id累加记费数,时长,费用*/
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

	/*取日期*/
	strcpy(sTableName,argv[6]);
	if(argc==8){
		strncpy(sProcDate,argv[7],8);
	}
	else{
		GetHostTime(sProcDate);
		AddDays(sProcDate,-1);
	}
	sProcDate[8]='\0';


	/*检查参数合法性*/
	if(strcmp(sServiceType,"193")!=0 && strcmp(sServiceType,"17911")!=0){
		printf("输出业务类别%s无效.\n",sServiceType);
		WriteAlertMsg(">:输出业务类别%s无效.\n",sServiceType);
		return -1;
	}
	if(IsDir(sOutputDir)==FALSE){
		printf("输出正常目录%s无效.\n",sOutputDir);
		WriteAlertMsg(">:输出正常目录%s无效.\n",sOutputDir);
		return -1;
	}

	if(sFileOpMode[0]!='I' &&  sFileOpMode[0]!='C' &&
		sFileOpMode[0]!='U' && sFileOpMode[0]!='D'){
		printf("输出入库标志%s无效.\n",sFileOpMode);
		WriteAlertMsg(">:输出入库标志%s无效.\n",sFileOpMode);
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

	/*该处定义select条件*/
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"WHERE substr(START_TIME,1,8)='%s' \n\
		AND ROAM_TYPE IN('1','2')",sProcDate);

        Upper(TempIn.sTableName);

	pFileHead=(struct T193FileHeadStruct *)
		malloc(sizeof(struct T193FileHeadStruct));
	ERROR_EXIT(pFileHead==NULL,"分配T193FileHeadStruct结构错误");

	TempIn.iBufEmpty=TRUE;
        TempIn.iFirstFlag=TRUE;

        /*取出表中记录加载二叉树，构造文件体记录结构*/
        if(strcmp(sServiceType,"193")==0){
	        while(EGetSttTicketToStruct(&Temp,&TempIn)){
			iCount++;
	                if(InsertBin(&pRoot,(void *)&Temp,
				data_search_bintree_T193record,
				assign_insert_bintree_T193record)<0){
				WriteAlertMsg("生成BINTREE失败T193RECORD");
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
				WriteAlertMsg("生成BINTREE失败T193RECORD");
				return -1;
			}
	        }
	}

/*	TravelBin(pRoot,PrintT193Stat);*/
        TravelBin(pRoot,StatAll);

	if((fp=fopen(sOutputFileName,"w"))==NULL) return -1;

	/*输出文件*/
	GenT193FileHead(&FileStat,pFileHead);
	OutputT193FileHead(pFileHead,sFileOpMode);
	TravelBin(pRoot,OutputT193FileBody);

	printf("文件 %s 生成完毕.\n",sBaseFileName);
	WriteProcMsg("文件 %s 生成完毕.",sBaseFileName);

	fclose(fp);
	DisconnectDatabase();
	return 0;
}
