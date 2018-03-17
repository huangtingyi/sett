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


#include "high_supp.h"


struct DetailStatReportStruct *gReportList=NULL;
struct PstnDetailTicketStruct *gUpdateList=NULL;

int data_search_report(void *pValue,void *pData)
{
	int iResult=0;
	struct DetailStatReportStruct *pSource=(struct DetailStatReportStruct*)pValue;
	struct DetailStatReportStruct *pTarget=(struct DetailStatReportStruct*)pData;

	if((iResult=strcmp(pSource->sImsi,pTarget->sImsi))!=0) return iResult;	
	if((iResult=strcmp(pSource->sCallingNbr,pTarget->sCallingNbr))!=0) return iResult;	
	
	return 0;

}
void assign_insert_bintree_report(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int append_bintree_to_list_report(void **ppData)
{
	struct DetailStatReportStruct *pTemp=(struct DetailStatReportStruct*)(*ppData);

	pTemp->pLoadNext=gReportList;
	gReportList=pTemp;

	return 0;
}
int data_search_update(void *pValue,void *pData)
{
	int iResult=0;
	struct PstnDetailTicketStruct *pSource=(struct PstnDetailTicketStruct*)pValue;
	struct PstnDetailTicketStruct *pTarget=(struct PstnDetailTicketStruct*)pData;

	if((iResult=strcmp(pSource->sImsi,pTarget->sImsi))!=0) return iResult;	
	if((iResult=strcmp(pSource->sServiceNbr,pTarget->sServiceNbr))!=0) return iResult;	
	if((iResult=strcmp(pSource->sCallingNbr,pTarget->sCallingNbr))!=0) return iResult;	
	if((iResult=strcmp(pSource->sCallTime,pTarget->sCallTime))!=0) return iResult;	
	return 0;

}

void assign_insert_bintree_update(void **ppData,void *pData)
{
	InsertList((LIST **)ppData,(LIST *)pData);
}

int append_bintree_to_list_update(void **ppData)
{
	struct PstnDetailTicketStruct *pTemp=(struct PstnDetailTicketStruct*)(*ppData);

	pTemp->pLoadNext=gUpdateList;
	gUpdateList=pTemp;

	return 0;
}
void DealTicketToReport(struct PstnDetailTicketStruct *pSource,struct DetailStatReportStruct *pTarget)
{
	strcpy(pTarget->sRecordType,	pSource->sRecordType);
	strcpy(pTarget->sCompany,	pSource->sCompany);
	strcpy(pTarget->sImsi,		pSource->sImsi);
	strcpy(pTarget->sCallingNbr,	pSource->sCallingNbr);
	strcpy(pTarget->sNumberType,	pSource->sNumberType);
	strcpy(pTarget->sCalledNbr,	pSource->sCalledNbr);
	strcpy(pTarget->sServiceType,	pSource->sServiceType);
	strcpy(pTarget->sServiceNbr,	pSource->sServiceNbr);
	strcpy(pTarget->sDualType,	pSource->sDualType);
	strcpy(pTarget->sDualNbr,	pSource->sDualNbr);
	strcpy(pTarget->sMsc,		pSource->sMsc);
	strcpy(pTarget->sLac,		pSource->sLac);	
	strcpy(pTarget->sMobileCode,	pSource->sMobileCode);
	strcpy(pTarget->sCallTime,	pSource->sCallTime);
	strcpy(pTarget->sPayUnits,	pSource->sPayUnits);
	strcpy(pTarget->sAmountData,	pSource->sAmountData);
	strcpy(pTarget->sTollProjects,	pSource->sTollProjects);
	strcpy(pTarget->sRate1,		pSource->sRate1);
	strcpy(pTarget->sRate2,		pSource->sRate2);
	
	strcpy(pTarget->sCnt,"0");
	strcpy(pTarget->sTollFee,"0");
	strcpy(pTarget->sSdr,"0");

	
}
int ProResultToReport(char sTableName[],struct PstnDetailTicketStruct *pTemp,BINTREE **pptRoot)
{
	int iCnt=0,iTollFee=0;
	double iSdr=0;
	char sTime[15],sNowTime[15];
	
	struct DetailStatReportStruct *pReportTemp=NULL;
	struct PstnDetailTicketStructIn TempIn;
	struct PstnDetailTicketStruct Temp;
	
	bzero((void*)&TempIn,sizeof(struct PstnDetailTicketStructIn));
	bzero((void*)&Temp,sizeof(struct PstnDetailTicketStruct));

	strcpy(TempIn.sTableName,sTableName);
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	strcpy(sTime,pTemp->sCallTime);
	strcpy(sNowTime,sTime);
	AddDays(sTime,-1);

	sprintf(TempIn.sCondition,
		"WHERE Calling_nbr='%s' AND Call_Time>='%s' AND Call_Time<='%s'",
		pTemp->sCallingNbr,sTime,sNowTime);
		
	while(EGetPstnDetailTicketToStructByDate(&Temp,&TempIn)){
		iCnt++;
		iTollFee+=Temp.iTollFee;
		iSdr+=atof(Temp.sSdr);
	}
	
	if(iSdr<=50) return 0;
	
	if((pReportTemp=(struct DetailStatReportStruct*)malloc(sizeof(struct DetailStatReportStruct)))==NULL){
		WriteProcMsg("malloc struct DetailStatReportStruct 失败!!!");
		return -1;
	}
	bzero((void*)pReportTemp,sizeof(struct DetailStatReportStruct));
		
	DealTicketToReport(pTemp,pReportTemp);
	sprintf(pReportTemp->sCnt,"%d",iCnt);
	sprintf(pReportTemp->sTollFee,"%d",iTollFee);
	sprintf(pReportTemp->sSdr,"%.3f",iSdr);
		
	if(InsertBin(pptRoot,pReportTemp,data_search_report,
		assign_insert_bintree_report)<0){
		WriteProcMsg("生成二叉树 DetailStatReportStruct 失败.");
		return -1;
	}
	
	return 0;
}

int LoadTableToBintree(char sTableName[],BINTREE **pptRootUpdate,BINTREE **pptRoot)
{
	unsigned long iTotalCnt=0;
	
	struct PstnDetailTicketStructIn TempIn;
	struct PstnDetailTicketStruct Temp;
	struct PstnDetailTicketStruct *ptUpdate;
	
	bzero((void*)&TempIn,sizeof(struct PstnDetailTicketStructIn));
	bzero((void*)&Temp,sizeof(struct PstnDetailTicketStruct));
	
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,"WHERE STATE='0'");
	TempIn.iFirstFlag = true;
	TempIn.iBufEmpty=true;
	Temp.pNext = NULL;
	Temp.pLoadNext = NULL;
	
	*pptRoot=NULL;
	*pptRootUpdate=NULL;
	
	while (EGetPstnDetailTicketToStruct(&Temp,&TempIn)) {
		
		if(strcmp(Temp.sCallingNbr,"00000000000")==0) continue;
				
		if(ProResultToReport(sTableName,&Temp,pptRoot)<0) return -1;
		
		if((ptUpdate=(struct PstnDetailTicketStruct*)malloc(sizeof(struct PstnDetailTicketStruct)))==NULL){
			WriteProcMsg("malloc struct PstnDetailTicketStruct 失败!!!");
			return -1;
		}
		bzero((void*)ptUpdate,sizeof(struct PstnDetailTicketStruct));
		memcpy((void*)ptUpdate,(void*)&Temp,sizeof(struct PstnDetailTicketStruct));
		strcpy(ptUpdate->sState,"1");
		
		if(InsertBin(pptRootUpdate,ptUpdate,data_search_update,
			assign_insert_bintree_update)<0){
			WriteProcMsg("生成Update二叉树 PstnDetailTicketStruct 失败.");
			return -1;
		}
		if((++iTotalCnt)%1000==0){
			WriteProcMsg("加载统计 %s 数据记录 %d 条.",sTableName,iTotalCnt);
		}
	}
	WriteProcMsg("加载并统计 %s 数据总记录 %d 条.",sTableName,iTotalCnt);
	return 0;
}
int FreeMemList(struct DetailStatReportStruct *ptHead)
{
	int iCnt=0;
	struct DetailStatReportStruct *pTemp=NULL;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		hfree(pTemp,sizeof(struct DetailStatReportStruct));
			
		iCnt++;
	}
	
	ptHead=NULL;
	
	return iCnt;
}
int InsertListToTable(char sTableName[],struct DetailStatReportStruct *ptHead)
{
	unsigned long ulRecCnt=0;
	struct DetailStatReportStructOut TempOut;
	struct DetailStatReportStruct *ptCur=NULL;
	struct DetailStatReportStruct *ptLoadCur=NULL;

	bzero(&TempOut,sizeof(struct DetailStatReportStructOut));

	strcpy(TempOut.sTableName,sTableName);
	
	while(ptHead!=NULL){
		ptLoadCur=ptHead;
		ptHead=ptHead->pLoadNext;
		
		while(ptLoadCur!= NULL){
			ptCur = ptLoadCur;
			ptLoadCur = ptLoadCur->pNext;
			if((++ulRecCnt)%10000==0){
				if(EInsertStructToDetailStatReport(NULL,true,&TempOut)<0){
					WriteProcMsg("写表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前输出数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EInsertStructToDetailStatReport(ptCur,false,&TempOut)<0){
				WriteProcMsg("写表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
		}
	}
	if(EInsertStructToDetailStatReport(NULL,true,&TempOut)<0){
		WriteProcMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcMsg("输出数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);
	
	return 0;
}
int UpdateListToTable(char sTableName[],struct PstnDetailTicketStruct *ptHead)
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
			if((++ulRecCnt)%10000==0){
				if(EUpdateStructToPstnDetailTicket(NULL,true,&TempOut)<0){
					WriteProcMsg("更新表%s错误.",sTableName);
					WriteErrStackAlert();
					RollbackWorkRelease();
					return -1;
				}
				CommitWork();
				WriteProcMsg("当前更新数据到 %s 表记录数 %lu 条.",
					sTableName,ulRecCnt);
			}
			if(EUpdateStructToPstnDetailTicket(ptCur,false,&TempOut)<0){
				WriteProcMsg("更新表%s错误.",sTableName);
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
		}
	}
	if(EUpdateStructToPstnDetailTicket(NULL,true,&TempOut)<0){
		WriteProcMsg("写表%s错误.",sTableName);
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	WriteProcMsg("更新数据到 %s 表总记录数 %lu 条.",sTableName,ulRecCnt);
	
	return 0;
}
int main(int argc,char *argv[])
{
	char sTableNameIn[31];
	char sTableNameOut[31];
	BINTREE *ptRoot=NULL;
	BINTREE *ptRootUpdate=NULL;
	
	if(argc != 3){
		WriteProcPrint("Usage: ./highreport TableNameIn TableNameOut !!!");
		return -1;
	}

	strcpy(sTableNameIn,argv[1]);
	strcpy(sTableNameOut,argv[2]);
	
	InitAppRes(argv[0]);
	
	if(ConnectDataDB()<0) return -1;
	
	WriteProcMsg("数据统计开始");
	if(LoadTableToBintree(sTableNameIn,&ptRootUpdate,&ptRoot)<0){
		DestroyBin(ptRoot);
		DestroyBin(ptRootUpdate);
		DisconnectDatabase();	
		return -1;
	}
	TravelBin(ptRoot,append_bintree_to_list_report);
	
	WriteProcMsg("数据统计完成，开始入库");
	if(InsertListToTable(sTableNameOut,gReportList)<0){
		DestroyBin(ptRoot);
		DestroyBin(ptRootUpdate);	
		DisconnectDatabase();	
		return -1;
	} 
	TravelBin(ptRootUpdate,append_bintree_to_list_update);
	
	WriteProcMsg("数据统计完成，开始更新数据源");
	if(UpdateListToTable(sTableNameIn,gUpdateList)<0){
		DestroyBin(ptRoot);
		DestroyBin(ptRootUpdate);	
		DisconnectDatabase();	
		return -1;
	}
	FreeMemList(gReportList);	
	DestroyBin(ptRoot);		
	DisconnectDatabase();	
	WriteProcMsg("数据统计完成");
	return 0;
}




