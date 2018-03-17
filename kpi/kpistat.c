#include <hnixs.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <wwdbf.h>
#include <wwfile.h>
#include <wwdir.h>
#include "kpistat_supp.h"

int ExecShellCommand(struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[],char sCommand[])
{
	FILE *fp=NULL;
	char sBuffer[1024+1];
	char *pSourceID=NULL,*pValue=NULL,sKpiDate[15],sCreatedDate[15];
	int iDimensionID1;
	struct KpiLibStruct *pTemp;	
	/*
		do:
			system(sCommand);
		result:
			SourceID1|Value1\n
			SourceID2|Value2\n
	*/
	fp=popen(sCommand,"r");
	if(fp==NULL){
		printf("执行命令失败:%s\n",sCommand);
		return -1;
	}
	
	strncpy(sKpiDate,sBeginTime,8);sKpiDate[8]=0;
	
	while(fgets(sBuffer,1024,fp)!=NULL){
		
		/*取得pSourceID和pValue*/
		pSourceID = sBuffer;
		pValue = strchr(pSourceID,'|');
		if( pValue == NULL ){
			printf( "程序结果不正确，应该为 SourceID|Value :%s\n", sBuffer );
			return -1;
		}
		*pValue = '\0';
		pValue++;
		
		/*查找iDimensionID1*/
		iDimensionID1=SearchDimensionID(pptHead,pSourceID);		
		/*形成kpi_lib链表*/
		pTemp=(struct KpiLibStruct *)
			malloc(sizeof(struct KpiLibStruct));
		ERROR_EXIT(pTemp==NULL,"分配KpiLibStruct结构错误");
		
		strcpy(pTemp->sKpiID,sKpiID);
		pTemp->iDimensionID1=iDimensionID1;
		pTemp->iDimensionID2=0;/*保留*/
		pTemp->iValue=atoi(pValue);
		strcpy(pTemp->sKpiDate,sKpiDate);
		strcpy(pTemp->sBeginTime,sBeginTime);
		strcpy(pTemp->sEndTime,sEndTime);
		GetHostTime(sCreatedDate);
		strcpy(pTemp->sCreatedDate,sCreatedDate);
		
		pTemp->pLoadNext=*pptKpiRecord;
		*pptKpiRecord=pTemp;				
	}
	
	return 0;
}

int GetCtlName(char sCtlName[],char sKpiModule[])
{
	char sAppHome[256],sCtlPath[256];
	
	GetAppHome(sAppHome);
	sprintf(sCtlPath,"%sctl/",sAppHome);

	if(!IsDir(sCtlPath)){
		WriteAlertPrint("应用启停控制路径%s不存在",sCtlPath);
		return -1;
	}
	
	sprintf(sCtlName,"%sKPI_%s.txt",sCtlPath,sKpiModule);
	return 0;
	
}

int ReadCtlFile(char sCtlName[],char sLastScanTime[])
{
	char sCommand[1024],sResult[1024];
	
	if(IsFile(sCtlName)==FALSE) return -1;
	
	sprintf(sCommand,"cat %s | head -1",sCtlName);

	if(exec2str(sCommand,sResult)!=0) return -1;
	
	strcpy(sLastScanTime,sResult);
	AllTrim(sLastScanTime);
/*	GetTabStr(sResult,0,sLastScanTime);*/
	return 0;
}

void WriteCtlFile(char sCtlName[],char sCurScanTime[])
{
	char sCommand[1024];

	sprintf(sCommand,"echo %s > %s",
		sCurScanTime,sCtlName);
	system(sCommand);
}

int GetScanTime(char sCtlName[],char sHostTime[],char sBeginTime[],char sEndTime[],
	char sKpiModule[])
{
	char sLastScanTime[15];
	
	/*如果控制文件为空，从当天0点的log开始统计*/
	if(ReadCtlFile(sCtlName,sLastScanTime)<0){
		strcpy(sBeginTime,sHostTime);
		strcpy(sBeginTime+8,"00");
	}else strcpy(sBeginTime,sLastScanTime);
	printf("sLastScanTime=%s\n",sLastScanTime);
	
	strcpy(sEndTime,sHostTime);
	if(strncmp(sBeginTime,sEndTime,10)==0)return -1;
	
	if(strcmp(sKpiModule,"SETTITEMDU")==0||
		strcmp(sKpiModule,"SETTITEMSD")==0||
		strcmp(sKpiModule,"SETTITEMIC")==0||
		strcmp(sKpiModule,"SETTITEMOC")==0||
		strcmp(sKpiModule,"SETTITEMTC")==0)	{
		sBeginTime[8]=0;
		sEndTime[8]=0;
		if(strncmp(sBeginTime,sEndTime,8)==0) return -1;
	}
/*	printf("in func:sBeginTime=%s\t,sEndTime=%s\n",sBeginTime,sEndTime);*/
	return 0;
}

int PrintKpiDimension(struct KpiDimensionStruct *pList)
{
	struct KpiDimensionStruct *pTemp=pList;
	
	while(pTemp!=NULL){

		printf("%d\t%d\t%s\t%s\t%s\n",
			pTemp->iDimensionID,
			pTemp->iParentID,
			pTemp->sDimension,
			pTemp->sDimensionType,
			pTemp->sRemark);
		pTemp=pTemp->pLoadNext;
	}
	return 0;
	
}

int PrintKpiLib(struct KpiLibStruct **pList)
{
	struct KpiLibStruct *pTemp=*pList;
	
	while(pTemp!=NULL){

		printf("%d\t%d\t%d\t%s,%s,%s,%s.\n",
			pTemp->iDimensionID1,
			pTemp->iDimensionID2,
			pTemp->iValue,
			pTemp->sKpiDate,
			pTemp->sBeginTime,
			pTemp->sEndTime,
			pTemp->sCreatedDate);
		pTemp=pTemp->pLoadNext;
	}
	return 0;
	
}

int GenKpiRecord(char sKpiModule[],struct KpiDimensionStruct **pptHead,
	struct KpiLibStruct **pptKpiRecord,char sKpiID[],
	char sBeginTime[],char sEndTime[])
{
	int iCnt;
	int iKpiModuleID;
	
	if(strcmp(sKpiModule,"PREPRECCNT")==0) iKpiModuleID=2020101;
	else if(strcmp(sKpiModule,"PREPERRCNT")==0)	iKpiModuleID=2020102;
	else if(strcmp(sKpiModule,"PREPDUPCNT")==0)	iKpiModuleID=2020103;
	else if(strcmp(sKpiModule,"PREPOVERSTOCK")==0)	iKpiModuleID=2020104;
	else if(strcmp(sKpiModule,"PREPDELAYTIME")==0)	iKpiModuleID=2020105;
	else if(strcmp(sKpiModule,"PREPPROCRATE")==0)	iKpiModuleID=2020106;
	
	else if(strcmp(sKpiModule,"BILLRECCNT")==0)	iKpiModuleID=2020201;
	else if(strcmp(sKpiModule,"BILLERRCNT")==0)	iKpiModuleID=2020202;
	else if(strcmp(sKpiModule,"BILLPROCRATE")==0)	iKpiModuleID=2020203;
	else if(strcmp(sKpiModule,"BILLOVERSTOCK")==0)	iKpiModuleID=2020204;
	
	else if(strcmp(sKpiModule,"INSTPROCRATE")==0)	iKpiModuleID=2020401;
	else if(strcmp(sKpiModule,"INSTFILECNT")==0)	iKpiModuleID=2020402;
	else if(strcmp(sKpiModule,"INSTRECCNT")==0)	iKpiModuleID=2020403;
	else if(strcmp(sKpiModule,"INSTOVERSTOCK")==0)	iKpiModuleID=2020404;
	
	else if(strcmp(sKpiModule,"PICKFILECNT")==0)	iKpiModuleID=2010201;
	else if(strcmp(sKpiModule,"PICKLOCALINTV")==0)	iKpiModuleID=2010202;
	else if(strcmp(sKpiModule,"PICKBYTECNT")==0)	iKpiModuleID=2010203;
	else if(strcmp(sKpiModule,"PICKBRIDGEINTV")==0)	iKpiModuleID=2010204;
	else if(strcmp(sKpiModule,"PICKOVERSTOCK")==0)	iKpiModuleID=2010101;
	else if(strcmp(sKpiModule,"PICKHOSTCHK")==0)	iKpiModuleID=20101011;	
	
	else if(strcmp(sKpiModule,"SETTITEMDU")==0)	iKpiModuleID=9999900;
	else if(strcmp(sKpiModule,"SETTITEMSD")==0)	iKpiModuleID=9999901;
	else if(strcmp(sKpiModule,"SETTITEMIC")==0)	iKpiModuleID=9999902;
	else if(strcmp(sKpiModule,"SETTITEMOC")==0)	iKpiModuleID=9999903;
	else if(strcmp(sKpiModule,"SETTITEMTC")==0)	iKpiModuleID=9999904;
	
	else if(strcmp(sKpiModule,"UPFILECNT")==0)	iKpiModuleID=2030101; 
	else if(strcmp(sKpiModule,"UPRECORDCNT")==0)	iKpiModuleID=2030102;
	else if(strcmp(sKpiModule,"LATEUPFILECNT")==0)	iKpiModuleID=2030103;
	else if(strcmp(sKpiModule,"LATEUPRECCNT")==0)	iKpiModuleID=2030104;
	else if(strcmp(sKpiModule,"DOWNLOSEFCNT")==0)	iKpiModuleID=2030105;
	else if(strcmp(sKpiModule,"DOWNFILECNT")==0)	iKpiModuleID=2030106;
	else if(strcmp(sKpiModule,"ERRFILECNT")==0)	iKpiModuleID=2030107;
	else if(strcmp(sKpiModule,"JRIERRCNT")==0)	iKpiModuleID=2030108;
	else if(strcmp(sKpiModule,"JIIERRCNT")==0)	iKpiModuleID=2030109;
	else if(strcmp(sKpiModule,"CRIERRCNT")==0)	iKpiModuleID=2030110;
	else if(strcmp(sKpiModule,"CIIERRCNT")==0)	iKpiModuleID=2030111;
	
	else{
		iCnt=-1;
		WriteAlertPrint("KPI指标模块号 %s 不正确，请重新输入 \n",sKpiModule);
		return iCnt;
	}
	
	switch(iKpiModuleID){
		case PICKFILECNT:
			iCnt=GenPickFileCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case PICKLOCALINTV:
			iCnt=GenPickLocalIntv(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case PICKBYTECNT:
			iCnt=GenPickByteCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case PICKOVERSTOCK:
			iCnt=ExecShellCommand(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,
				"sh $BILLHOME/shell/chkcntonserver.sh $APPHOME/shell/pick.ini");
		break;
		case PICKHOSTCHK:
			iCnt=ExecShellCommand(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,
				"sh $BILLHOME/shell/kpichkhost.sh $APPHOME/shell/pick.ini");
		break;
		
		case PREPRECCNT:
			iCnt=GenPrepRecCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;		
		case PREPERRCNT:
			iCnt=GenPrepErrCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
/*
		case PREPDUPCNT:
			iCnt=GenPrepDupCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
*/		
		case PREPDELAYTIME:
			iCnt=GenPrepDelayTime(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case PREPPROCRATE:
			iCnt=GenPrepProcRate(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case PREPOVERSTOCK:
			iCnt=ExecShellCommand(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,
				"sh $BILLHOME/shell/kpichkfilecnt.sh $APPHOME/shell/prep.ini 2 7 6");
		break;
		case BILLRECCNT:
			iCnt=GenBillRecCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case BILLERRCNT:
			iCnt=GenBillErrCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case BILLPROCRATE:
			iCnt=GenBillProcRate(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case BILLOVERSTOCK:
			iCnt=ExecShellCommand(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,
				"sh $BILLHOME/shell/kpichkfilecnt.sh $APPHOME/shell/billing.ini 2 4 3");
		break;
		case INSTPROCRATE:
			iCnt=GenInstProcRate(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case INSTFILECNT:
			iCnt=GenInstFileCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case INSTRECCNT:
			iCnt=GenInstRecCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case INSTOVERSTOCK:
			iCnt=ExecShellCommand(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,
				"sh $BILLHOME/shell/kpichkfilecnt.sh $APPHOME/shell/ins2db.ini 2 5 7");
		break;
		case SETTITEMDU:
			iCnt=GenSettItem(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"0");
		break;
		case SETTITEMSD:
			iCnt=GenSettItem(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"1");		
		break;
		case SETTITEMIC:
			iCnt=GenSettItem(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"2");		
		break;
		case SETTITEMOC:
			iCnt=GenSettItem(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"3");		
		break;
		case SETTITEMTC:
			iCnt=GenSettItem(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"4");		
		break;
		case UPFILECNT:
			iCnt=GenUpDownFileCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case UPRECORDCNT:
			iCnt=GenUpDownRecCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime);
		break;
		case JRIERRCNT:
			iCnt=GenUpErrCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"JRIERR");
		break;
		case JIIERRCNT:
			iCnt=GenUpErrCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"JIIERR");
		break;
		case CRIERRCNT:
			iCnt=GenUpErrCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"CRIERR");
		break;
		case CIIERRCNT:
			iCnt=GenUpErrCnt(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,"CIIERR");
		break;
		case DOWNFILECNT:
			iCnt=ExecShellCommand(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,
				"cat $BILLHOME/log/downfile.log");
		break;
		case DOWNLOSEFCNT:
			iCnt=ExecShellCommand(pptHead,pptKpiRecord,sKpiID,
				sBeginTime,sEndTime,
				"cat $BILLHOME/log/lostdownfile.log");
		break;

		default:
			iCnt=-1;
			break;
	}
	return iCnt;
}

int main(int argc,char *argv[])
{
	int iCnt;
	char sKpiModule[30],sKpiID[20],sHostTime[15],
		sBeginTime[15],sEndTime[15],sCtlName[256];
	struct KpiDimensionStruct *pKpiDimension=NULL;
	struct KpiLibStruct *pKpiLib=NULL;

/*
kpistat PICKFILECNT     PM-02-01-02-01
kpistat PICKLOCALINTV   PM-02-01-02-02
kpistat PICKBYTECNT     PM-02-01-02-03
kpistat PICKBRIDGEINTV  PM-02-01-02-04

kpistat PICKOVERSTOCK   PM-02-01-01-01
kpistat PICKHOSTCHK     FM-02-01-01-01 

kpistat PREPRECCNT      PM-02-02-01-01
kpistat PREPERRCNT      PM-02-02-01-02
kpistat PREPOVERSTOCK   PM-02-02-01-04
kpistat PREPDELAYTIME   PM-02-02-01-05 
kpistat PREPPROCRATE    PM-02-02-01-06

kpistat BILLRECCNT      PM-02-02-02-01
kpistat BILLERRCNT      PM-02-02-02-02
kpistat BILLPROCRATE    PM-02-02-02-03
kpistat BILLOVERSTOCK   PM-02-02-02-04

kpistat INSTPROCRATE    PM-02-02-04-01
kpistat INSTFILECNT     PM-02-02-04-02
kpistat INSTRECCNT      PM-02-02-04-03
kpistat INSTOVERSTOCK   PM-02-02-04-04

kpistat SETTITEMDU      PM-99-99-99-00
kpistat SETTITEMSD      PM-99-99-99-01
kpistat SETTITEMIC      PM-99-99-99-02
kpistat SETTITEMOC      PM-99-99-99-03
kpistat SETTITEMTC      PM-99-99-99-04

kpistat UPFILECNT       PM-02-03-01-01  
kpistat UPRECORDCNT     PM-02-03-01-02
kpistat LATEUPFILECNT   PM-02-03-01-03
kpistat LATEUPRECCNT    PM-02-03-01-04
kpistat DOWNLOSEFCNT    PM-02-03-01-05
kpistat DOWNFILECNT     PM-02-03-01-06
kpistat ERRFILECNT      PM-02-03-01-07
kpistat JRIERRCNT       PM-02-03-01-08
kpistat JIIERRCNT       PM-02-03-01-08
kpistat CRIERRCNT       PM-02-03-01-08
kpistat CIIERRCNT       PM-02-03-01-08

*/

	if(argc!=3){
		printf("Usage %s kpi_module kpi_id\n",argv[0]);
		return -1;
	}

	strcpy(sKpiModule,argv[1]);Upper(sKpiModule);
	
	strcpy(sKpiID,argv[2]);
	
/*		
	strcpy(sBeginTime,"20060110030000");
	strcpy(sEndTime,"20060110050000");
*/
	GetHostTime(sHostTime);sHostTime[10]=0;
	/*strcpy(sHostTime+10,"0000");*/

	if(GetCtlName(sCtlName,sKpiModule)<0) return -1; 
	printf("sCtlName=%s\n",sCtlName);

	/*取得本次扫描起始时间*/	
	if(GetScanTime(sCtlName,sHostTime,sBeginTime,sEndTime,sKpiModule)<0) return 0;
	printf("sBeginTime=%s,\tsEndTime=%s\n",sBeginTime,sEndTime);
		
	if(IniConnect("dataconnstr")<0){
	        printf("连接数据库失败\n");
		return -1;
	}
	
	if(InitKpiDimension(&pKpiDimension)<0){
		WriteAlertMsg("加载KPI_DIMENSION失败");
		return -1;
	}
/*	PrintKpiDimension(pKpiDimension);*/
	

	if((iCnt=GenKpiRecord(sKpiModule,&pKpiDimension,&pKpiLib,sKpiID,
		sBeginTime,sEndTime))<0)
		WriteAlertPrint("KPI指标 %s 模块 %s 周期统计失败\n",
			sKpiModule,sBeginTime);
/*		PrintKpiLib(&pKpiLib);*/
	
	if(InsertKpiRecord(&pKpiLib)<0) WriteAlertPrint("插入KPI_LIB表失败\n");

	WriteCtlFile(sCtlName,sEndTime);

	DisconnectDatabase();
	
	return 0;
}
