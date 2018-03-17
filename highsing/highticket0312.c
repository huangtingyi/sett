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
#include <math.h>

#include "../shed/appsupp.h"
#include "high_supp.h"

#define Maxsize 1024



struct PstnDetailTicketStruct *gResultList=NULL;
struct PstnDetailTicketStruct *gTempList=NULL;

int comp_list_pstn_detail(void *pValue,LIST *pHead)
{
	int iResult=0;
	struct PstnDetailTicketStruct *pSource=(struct PstnDetailTicketStruct*)pValue;
	struct PstnDetailTicketStruct *pTarget=(struct PstnDetailTicketStruct*)pHead;

	if((iResult=strcmp(pSource->sImsi,pTarget->sImsi))!=0) return iResult;	
	if((iResult=strcmp(pSource->sServiceNbr,pTarget->sServiceNbr))!=0) return iResult;	
	if((iResult=strcmp(pSource->sCallingNbr,pTarget->sCallingNbr))!=0) return iResult;	
	if((iResult=strcmp(pSource->sCallTime,pTarget->sCallTime))!=0) return iResult;	
	
	return iResult;
}
int comp_list_pstn_detail_temp(void *pValue,LIST *pHead)
{
	int iResult=0;
	char sCalledNbrTag[26],sCalledNbrSor[26];
	struct PstnDetailTicketStruct *pSource=(struct PstnDetailTicketStruct*)pValue;
	struct PstnDetailTicketStruct *pTarget=(struct PstnDetailTicketStruct*)pHead;

	strcpy(sCalledNbrTag,pTarget->sCalledNbr);
	Fmt86A13(sCalledNbrTag);
	
	if((iResult=strcmp(pSource->sCallingNbr,pTarget->sCallingNbr))!=0) return iResult;
	if((RLike(pSource->sCalledNbr,sCalledNbrTag))!=true) return -1;
	if((iResult=strcmp(pSource->sCallTime,pTarget->sCallTime))!=0) return iResult;	
	
	return iResult;
}

int data_search_day_stat(void *pValue,void *pData)
{
	int iResult=0;
	char sSourceTime[9],sTargetTime[9];
	struct PstnDetailTicketStruct *pSource=(struct PstnDetailTicketStruct*)pValue;
	struct PstnDetailTicketStruct *pTarget=(struct PstnDetailTicketStruct*)pData;
	
	strncpy(sSourceTime,pSource->sCallTime,8);sSourceTime[8]=0;
	strncpy(sTargetTime,pTarget->sCallTime,8);sTargetTime[8]=0;
	if((iResult=strcmp(sSourceTime,sTargetTime))!=0) return iResult;	
	return 0;

}

void assign_insert_bintree_day_stat(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int append_bintree_to_list_stat(void **ppData)
{
	struct PstnDetailTicketStruct *pTemp=(struct PstnDetailTicketStruct*)(*ppData);

	pTemp->pLoadNext=gResultList;
	gResultList=pTemp;

	return 0;
}
int append_bintree_to_list_temp(void **ppData)
{
	struct PstnDetailTicketStruct *pTemp=(struct PstnDetailTicketStruct*)(*ppData);

	pTemp->pLoadNext=gTempList;
	gTempList=pTemp;

	return 0;
}
int EInsertList2Table(char sTableName[],
	struct PstnDetailTicketStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct PstnDetailTicketStructOut TempOut;
	struct PstnDetailTicketStruct *ptCur=NULL;
	struct PstnDetailTicketStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct PstnDetailTicketStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			if(strcmp(ptCur->sFlag,"F")==0){
				hfree(ptCur,sizeof(struct PstnDetailTicketStruct));
				continue;
			}
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToPstnDetailTicket(NULL,true,&TempOut)<0){
					WriteProcMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前输出数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToPstnDetailTicket(ptCur,false,&TempOut)<0){
				WriteProcMsg("写表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			hfree(ptCur,sizeof(struct PstnDetailTicketStruct));
		}
	}
	if(EInsertStructToPstnDetailTicket(NULL,true,&TempOut)<0){
		WriteProcMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcMsg("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);
	
	return 0;
}
void AddNTrimes(char sStr[],int iSize,int n,char sResult[])
{
	int i=0;
	char sTemp[2048];
	strcpy(sTemp,"");
	strcpy(sResult,"");
	
	strcpy(sTemp,sStr+iSize);
	strncpy(sResult,sStr,iSize);
	sResult[iSize]=0;
	strcat(sResult,"@@@@@@");
	ReplaceStr(sResult,"@"," ");
	strcat(sResult,sTemp);
}
void MvStrTotemplatepstndetailticket(char sStr[],struct PstnDetailTicketStruct *pTemp)
{
	char sTemp[15];
	strncpy(pTemp->sRecordType,	sStr,2);
	strncpy(pTemp->sCompany,	sStr+2,5);
	strncpy(pTemp->sImsi,		sStr+7,15);
	strncpy(pTemp->sCallingNbr,	sStr+22,15);
	strncpy(pTemp->sServiceNbr,	sStr+37,8);
	strncpy(pTemp->sPayUnits,	sStr+45,6);
	strncpy(pTemp->sCallTime,	sStr+51,14);
	strncpy(sTemp,		sStr+65,9);sTemp[9]=0;
	pTemp->iTollFee=atoi(sTemp);
	
	strncpy(pTemp->sTollProjects,	sStr+74,1);
	strncpy(pTemp->sTaxRate,	sStr+75,10);
	strncpy(pTemp->sRate1,		sStr+85,10);

	AllTrim(pTemp->sRecordType);
	AllTrim(pTemp->sCompany);
	AllTrim(pTemp->sImsi);
	AllTrim(pTemp->sCallingNbr);
	AllTrim(pTemp->sServiceNbr);
	AllTrim(pTemp->sPayUnits);
	AllTrim(pTemp->sCallTime);
	AllTrim(pTemp->sTollProjects);
	AllTrim(pTemp->sTaxRate);
	AllTrim(pTemp->sRate1);		
}
void GetCallingNbr(struct PstnDetailTicketStruct *pTemp)
{
	struct ImeiUpStructIn TempIn;
	struct ImeiUpStruct Temp;	
	bzero(&TempIn,sizeof(struct ImeiUpStructIn));
	bzero(&Temp,sizeof(struct ImeiUpStruct));

	strcpy(TempIn.sTableName,"IMEI_UP");
	sprintf(TempIn.sCondition,"WHERE IMSI='%s'",pTemp->sImsi);
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetImeiUpToStruct(&Temp,&TempIn)) 
	{
		strcpy(pTemp->sCallingNbr,Temp.sMsisdn);
		return;
	}
	strcpy(pTemp->sCallingNbr,"00000000000");
}
int LoadStrToBintree(char sFileName[],char sStr[],char sRateSecond[],
	char sRateRes[],BINTREE **pptRoot)
{	
	static int iLen=sizeof(struct PstnDetailTicketStruct);
	static int iLen_f=sizeof(struct FPstnDetailTicketStruct);
	struct PstnDetailTicketStruct *pTemp,*ptFound,*p;
	struct PstnDetailTicketStruct Temp;
	struct FPstnDetailTicketStruct FpTemp;
	double drate;
	
	if((strncmp(sStr,"20",2)==0) || (strncmp(sStr,"30",2)==0)){
		char sRight[2080];
		AddNTrimes(sStr,85,6,sRight);
		mvitem_fmpstndetailticket((struct FPstnDetailTicketStruct *)&sRight,&Temp);
	}
	else if (strncmp(sStr,"60",2)==0) {
		MvStrTotemplatepstndetailticket(sStr,&Temp);
	}
/*获取calling_nbr*/	
	GetCallingNbr(&Temp);
	
	strcpy(Temp.sRate2,sRateSecond);
	drate=(Temp.iTollFee*1.0/100)/atof(sRateRes);
	sprintf(Temp.sSdr,"%.3f",drate);
	/*Temp.iSdr=(int)((drate*10+5)/10);*/
	strcpy(Temp.sState,"0");
	strcpy(Temp.sFileName,sFileName);
	strcpy(Temp.sFlag,"T");
	
	if(SearchBin(*pptRoot,&Temp,data_search_day_stat,(void**)&ptFound)==FOUND){
		if(SearchList((LIST *)ptFound,(void *)&Temp,(LIST **)&p,
			comp_list_pstn_detail)==FOUND) return 0;
	}
	if((pTemp=(struct PstnDetailTicketStruct*)malloc(iLen))==NULL){
		WriteProcMsg("malloc struct TemplatePstnDetailTicketStruct 失败!!!");
		return -1;
	}
	bzero((void*)pTemp,sizeof(struct PstnDetailTicketStruct));
	memcpy((void*)pTemp,(void*)&Temp,sizeof(struct PstnDetailTicketStruct));
	
	if(InsertBin(pptRoot,pTemp,data_search_day_stat,assign_insert_bintree_day_stat)<0){
		WriteProcMsg("生成二叉树 TemplatePstnDetailTicketStruct 失败.");
		return -1;
	}
	return 1;	
}
void GetRate2Result(char sStr[],char sRateSecond[],char sRateRes[])
{
	char sRate[12];
	char *p=NULL;
	strncpy(sRateSecond,sStr+72,10);
	sRateSecond[10]=0;
	AllTrim(sRateSecond);

	strncpy(sRate,sRateSecond,5);
	sRate[5]='.';
	strncpy(sRate+6,sRateSecond+5,5);
	sRate[11]=0;
	p=sRate;
	while ((*p == '0') && (*(p+1) != '.')) {
		p++;
	}
	strcpy(sRateRes,p);
}

int DataIsInStrTicket(char sMonth[],char sPart[],
	char sTemp[],BINTREE **pptRoot)
{
	struct PstnDetailTicketStruct *ptFound=NULL;
	struct PstnDetailTicketStruct *ptCur=NULL;
	struct PstnDetailTicketStruct PstnTemp;
	struct SrtTicket03StructIn TempIn;
	struct SrtTicket03Struct Temp;
	
	bzero(&TempIn,sizeof(struct SrtTicket03StructIn));
	bzero(&Temp,sizeof(struct SrtTicket03Struct));
	bzero(&PstnTemp,sizeof(struct PstnDetailTicketStruct));

	sprintf(TempIn.sTableName,"srt_ticket_%s partition(PART%s)",sMonth,sPart);
	sprintf(TempIn.sCondition,
		"WHERE MSISDN IN (%s) AND TICKET_TYPE_ID in(9312,9322)",sTemp);
		
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	while(EGetSrtTicket03ToStruct(&Temp,&TempIn)){
		
		strcpy(PstnTemp.sCallingNbr,Temp.sMsisdn);
		strcpy(PstnTemp.sCalledNbr,Temp.sOtherParty);
		strcpy(PstnTemp.sCallTime,Temp.sStartTime);
		
		if(SearchBin(*pptRoot,&PstnTemp,data_search_day_stat,
			(void**)&ptFound)==FOUND){
			
			if(SearchList((LIST *)ptFound,(void *)&PstnTemp,
				(LIST **)&ptCur,comp_list_pstn_detail_temp)==FOUND){
				strcpy(ptCur->sFlag,"F");
			}
		}
	}
	return 0;
}

int GenDelDataCondition(struct PstnDetailTicketStruct *ptHead,BINTREE **pptRoot)
{
	int i=0,ulRecCnt=0;
	char sPart[15],sMonth[3];
	char sTemp[2048];
	
	struct PstnDetailTicketStruct *ptCur=NULL;
	struct PstnDetailTicketStruct *ptLoadCur=NULL;
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		strncpy(sPart,ptLoadCur->sCallTime,8);sPart[8]=0;
		strncpy(sMonth,sPart+4,2);sMonth[2]=0;
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;

			if(strstr(sTemp,ptCur->sCallingNbr)!=NULL) continue;
			
			i+=sprintf(sTemp+i,"'%s',",ptCur->sCallingNbr);
			
			if((++ulRecCnt)%100==0){
				sTemp[i-1]='\0';
				/*过滤数据*/			
				DataIsInStrTicket(sMonth,sPart,sTemp,pptRoot);	
				i=0;
			}
		}
		if((ulRecCnt%100==0)) continue;
			
		sTemp[i-1]='\0';
		/*过滤数据*/			
		DataIsInStrTicket(sMonth,sPart,sTemp,pptRoot);	
		i=0;
	}
	
	return 0;
}
int TravelFileList(char sFileName[],struct FileControlStruct *ptHead,
			BINTREE **pptRoot)
{
	char sStr[2048],sRateSecond[11],sRateRes[12];
	struct FileControlStruct *pTemp;
	int iLen=0,iCount=0,i=0;

	pTemp=ptHead;
	ptHead=ptHead->pNext;
	
	memcpy(sStr,pTemp->pData,pTemp->iLen);
	sStr[pTemp->iLen]=0;
	if(strncmp(sStr,"10",2)!=0) return -1;
/*获取Rate2的值  000000964674=>9.64674*/
	GetRate2Result(sStr,sRateSecond,sRateRes);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strcpy(sStr,"");
		memcpy(sStr,pTemp->pData,pTemp->iLen);
		sStr[pTemp->iLen]=0;
		
		if((i=LoadStrToBintree(sFileName,sStr,sRateSecond,sRateRes,pptRoot))<0) return -1;	
		iCount+=i;
	}
	WriteProcMsg("加载数据到二叉树 %d 条.",iCount);
	if(iCount==0) return 0;
	
	gTempList=NULL;
	TravelBin(*pptRoot,append_bintree_to_list_temp);		
/*过滤掉已经在表str_ticket_xx存在的数据 生成过滤条件*/
	GenDelDataCondition(gTempList,pptRoot);	
	
	return iCount;
}
int FreeMemList(struct PstnDetailTicketStruct *ptHead)
{
	int iCnt=0;
	
	struct PstnDetailTicketStruct *ptCur=NULL;
	struct PstnDetailTicketStruct *ptLoadCur=NULL;

	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			
			hfree(ptCur,sizeof(struct PstnDetailTicketStruct));
			
			iCnt++;
		}
	}
	ptHead=NULL;
	
	return iCnt;
}
/*删除详单表的数据*/
void DeleteTableData(char sTableName[],char sFileName[])
{
	char statement[1024];
	
	sprintf(statement,"DELETE FROM %s WHERE FILE_NAME='%s'",sTableName,sFileName);
	if(ExecSql(statement)<0){
		WriteAlertMsg("执行%s失败",statement);
		exit (-1);
	}
	CommitWork();
}
/*更新日志的成功标识*/
void UpdateTableData(char sTableName[],char sFileName[])
{
	char statement[1024];
	
	sprintf(statement,"UPDATE %s SET STATE='T' WHERE FILE_NAME='%s'",sTableName,sFileName);
	if(ExecSql(statement)<0){
		WriteAlertMsg("执行%s失败",statement);
		exit (-1);
	}
	CommitWork();	
}

int ProcessMain(char sFilter[],char sSourceDir[],char sTargetDir[])
{
	int iSum=0;
	char sHTLogTableName[31],sCondition[128],sHostTime[15];
	char sFileName[33],sTempName[256];
	char sCommond[2048],sTableName[31];
	
	struct FileControlStruct *ptList=NULL;
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	struct HighTicketLogStruct Temp;
	BINTREE *ptRoot=NULL;
	
/*生成一个文件列表*/
	if(dir2list(sSourceDir,sFilter,&ptHead)<0){
		WriteProcMsg("生成文件列表失败 %s %s",sSourceDir,sFilter);
		return -1;
	}
	
	ptLkHead=ptHead;
	strcpy(sHTLogTableName,"High_Ticket_Log");
	strcpy(sTableName,"Pstn_Detail_ticket");
	/*编译入库文件*/
	while( ptHead != NULL ){

		pTemp = ptHead;
		ptHead = ptHead->pNext;

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		
		sprintf(sCondition,"WHERE FILE_NAME='%s'",sFileName);
		if(SDGetHighTicketLogToStruct(&Temp,sHTLogTableName,sCondition)==true){
			if(strcmp(Temp.sState,"T")==0){
				sprintf(sCommond,"mv %s%s %s%s",sSourceDir,sFileName,sTargetDir,sFileName);
				system(sCommond);
				continue;
			}
			else{
				DeleteTableData(sTableName,sFileName);
				goto next_step;
			}
		}

		strcpy(Temp.sFileName,sFileName);
		strncpy(Temp.sFileDate,sFileName+4,8);Temp.sFileDate[8]=0;
		GetHostTime(sHostTime);
		strcpy(Temp.sDealTime,sHostTime);
		strcpy(Temp.sState,"F");
		
		if(SDInsertStructToHighTicketLog(&Temp,sHTLogTableName)<0){
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		CommitWork();

next_step:
		sprintf(sTempName,"%s%s",sSourceDir,sFileName);

		if(TxtFileToList(sTempName,&ptList)<0) return -1;
	
		if((iSum=TravelFileList(sFileName,ptList,&ptRoot))<0){
			sprintf(sCommond,"mv %s %s.err",sTempName,sTempName);	
			system(sCommond);	
			continue;
		}
		if(iSum==0) goto next_zero;

		gResultList=NULL;
		TravelBin(ptRoot,append_bintree_to_list_stat);	
	
		if(EInsertList2Table(sTableName,gResultList)<0) return -1;
next_zero:	
		FreeList((LIST *)ptList);
		DestroyBin(ptRoot);
		ptRoot=NULL;		
		ptList=NULL;
	
		UpdateTableData(sHTLogTableName,sFileName);
		
		sprintf(sCommond,"mv %s%s %s%s",sSourceDir,sFileName,sTargetDir,sFileName);
		system(sCommond);
		
		WriteProcMsg("对文件%s分解成功",sFileName);
		
	}
	listfree(&ptLkHead);
	
	return 0;
}

int main(int argc,char *argv[])
{
	int iGroupID,iRet;
	char sSourceDir[81],sTargetDir[81],sFilter[21];
	char sDirFileName[Maxsize];

	struct DispParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc != 3){
		WriteProcPrint("Usage: ./highticket *.ini GroupID!!!");
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

		/*检查参数合法性.*/

		if(IsDir(pTemp->sSourcePath)==FALSE){
			WriteProcMsg("输入目录%s无效.",pTemp->sSourcePath);
			continue;
		}

		strcpy(sSourceDir,pTemp->sSourcePath);
		strcpy(sTargetDir,pTemp->sDestPath1);
		strcpy(sFilter,pTemp->sFilter);

		iRet=ProcessMain(sFilter,sSourceDir,sTargetDir);

		if(iRet<0){
			WriteProcMsg("分发文件失败!");
			return -1;
		}
		if(iRet>0) break;
	}		
	
	DisconnectDatabase();	
	
	return 0;
}



