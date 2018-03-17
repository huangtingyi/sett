#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <wwfile.h>
#include <wwdir.h>
#include <dbsupp.h>
#include "kpistat_supp.h"

void GetPrepErrScale(char sBusinessModule[],double *iErrScale)
{
	if(strcmp(sBusinessModule,"CDMA")==0)		*iErrScale=0.00005;
	else if(strcmp(sBusinessModule,"1X")==0) 	*iErrScale=0.00005;
	else *iErrScale=0; 
}

void GetTableName(char sProcModule[],char sTableName[])
{
	if(strcmp(sProcModule,"PREP")==0) strcpy(sTableName,"PREP_LOG");
	else strcpy(sTableName,"BILLING_LOG");
}

int GetCondition(char sHost[],char sBusinessModule[],
	char sDataDate[],char sCondition[])
{
	if(strcmp(sHost,"CDMAJF")==0){
		if(strcmp(sBusinessModule,"CDMA")==0)
			sprintf(sCondition,"\n\
				WHERE SUBSTR(SOURCE_ID,4,1)='C'\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);

		else if(strcmp(sBusinessModule,"1X")==0)
			sprintf(sCondition,"\n\
				WHERE SOURCE_ID IN ('CDMA1X')\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);

		else{
			WriteAlertMsg("生成SELECT CONDITION错误,系统类别%s,业务模块%s.\n",
				sHost,sBusinessModule);
			return -1;
		}
	}

	if(strcmp(sHost,"ZHJS")==0){
		if(strcmp(sBusinessModule,"WJ")==0)
			sprintf(sCondition,"\n\
				WHERE (SUBSTR(SOURCE_ID,3,2) IN ('DC','DG','GG','GC','G1','G0','GI','II','TG','TC')\n\
				OR SOURCE_ID='CDMA1X')\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);
				
		else{
			WriteAlertMsg("生成SELECT CONDITION错误,系统类别%s,业务模块%s.\n",
				sHost,sBusinessModule);
			return -1;
		}
	}
	
	sCondition[strlen(sCondition)]=0;
	return 0;
}

int GetPrepLogData(char sHost[],char sProcModule[],
	char sBusinessModule[],FILE *fp)
{
	double iErrScale;
	char sHostTime[15],sTimeStamp[15],sDataDate[15];
	struct PrepLogStruct Temp;
	struct PrepLogStructIn TempIn;
	
	GetHostTime(sHostTime);
	strcpy(sTimeStamp,sHostTime+4);sTimeStamp[10]=0;
	GetHostTime(sDataDate);AddDates(sDataDate,-1);sDataDate[8]=0;
	GetPrepErrScale(sBusinessModule,&iErrScale);
	
	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PrepLogStructIn));
	GetTableName(sProcModule,TempIn.sTableName);
	if (GetCondition(sHost,sBusinessModule,sDataDate,TempIn.sCondition)<0)
		return -1;

	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	/*提取**/
	while(EGetPrepLogToStruct(&Temp,&TempIn)){
		fprintf(fp,"%s%s%s%20s%50s%010d%010d%010d%04d%04d%010d\n",
			sTimeStamp,		/*预处理时间戳*/
			Temp.sDealBeginDate,	/*预处理起始时间*/
			Temp.sDealEndDate,	/*预处理结束时间*/
			Temp.sSourceID,		/*文件所属端局名称*/
			Temp.sOriFileName,	/*文件名称*/
			Temp.iCnt,		/*文件中话单总数*/
			0,			/*文件中不计费话单数*/
			(int)(Temp.iCnt*iErrScale),	/*文件中错单数*/
			0,			/*剔除循环计数*/
			0,			/*剔除原因编码*/
			0			/*剔除话单数*/
		);
	}
	return 0;
}

int GetBillingLogData(char sHost[],char sProcModule[],
	char sBusinessModule[],FILE *fp)
{
	double iErrScale;
	char sHostTime[15],sTimeStamp[15],sDataDate[15],sCondition[8*1024];

	GetHostTime(sHostTime);
	strcpy(sTimeStamp,sHostTime+4);sTimeStamp[10]=0;
	GetHostTime(sDataDate);AddDates(sDataDate,-1);sDataDate[8]=0;
	GetPrepErrScale(sBusinessModule,&iErrScale);
	
	if (GetCondition(sHost,sBusinessModule,sDataDate,sCondition)<0)
		return -1;
		
	PrintBillingData(sTimeStamp,sCondition,fp);
	
	return 0;
}

int GenIntfFile(char sHost[],char sProcModule[],
	char sBusinessModule[],FILE *fp)
{

	if(IniConnect("dataconnstr")<0){
	        printf("连接数据库失败\n");
		return -1;
	}
/*
	if(FastConnect("110")<0){
	        printf("fastconnec连接数据库失败\n");
		return -1;
	}
*/

	if(strcmp(sProcModule,"PREP")==0) 
		return GetPrepLogData(sHost,sProcModule,sBusinessModule,fp);

	else if(strcmp(sProcModule,"BILL")==0) 
		return GetBillingLogData(sHost,sProcModule,sBusinessModule,fp);

	DisconnectDatabase();
	return 0;

}


int main(int argc,char *argv[])
{
	char sFileName[256],sFileDate[15],sOutputPath[256];
	char sHost[20],sProcModule[20],sProcID[3],sBusinessModule[20];

	FILE *fp=NULL;

	if(argc!=5){
		printf("Usage:	%s sHost sProcModule sBusinessModule sOutputPath.\n",argv[0]);
		printf("Caller:	kpinmsintf_4fj CDMAJF PREP CDMA .\n" );
		printf("Caller:	kpinmsintf_4fj CDMAJF PREP 1X   .\n" );
		printf("Caller:	kpinmsintf_4fj CDMAJF BILL CDMA .\n" );
		printf("Caller:	kpinmsintf_4fj CDMAJF BILL 1X   .\n" );
		printf("Caller:	kpinmsintf_4fj ZHJS   BILL WJ   .\n" );

		return -1;
	}
	
	InitAppRes(argv[0]);

	strcpy(sHost,argv[1]);Upper(sHost);
	strcpy(sProcModule,argv[2]);Upper(sProcModule);
	strcpy(sBusinessModule,argv[3]);Upper(sBusinessModule);
	strcpy(sOutputPath,argv[4]);RegularDir(sOutputPath);

	if(strcmp(sHost,"ZHJS")!=0&&strcmp(sHost,"CDMAJF")!=0){
		printf("系统模块不正确，请重新输入.\n");
		printf("目前包括系统模块：ZHJS/CDMAJF.\n");
		return -1;
	}

	if(strcmp(sProcModule,"PREP")==0) strcpy(sProcID,"02");
	else if(strcmp(sProcModule,"BILL")==0) strcpy(sProcID,"03");
	else{
		printf("流程模块不正确，请重新输入.\n");
		printf("目前包括流程模块：PREP/BILL.\n");
		return -1;
	}

	if(strcmp(sHost,"ZHJS")==0){
		if(strcmp(sBusinessModule,"WJ")!=0){
			printf("业务模块不正确，请重新输入.\n");
			printf("目前包括业务模块：WJ.\n");
			return -1;
		}
	}

	if(strcmp(sHost,"CDMAJF")==0){
		if(strcmp(sBusinessModule,"CDMA")!=0&&
			strcmp(sBusinessModule,"1X")!=0){
			printf("业务模块不正确，请重新输入.\n");
			printf("目前包括业务模块：CDMA/1X.\n");
			return -1;
		}
	}


	GetHostTime(sFileDate);sFileDate[8]=0;

	sprintf(sFileName,"%s%s_%s_%s",sOutputPath,sBusinessModule,sFileDate,sProcID);

	if((fp=fopen(sFileName,"w"))==NULL){
		printf("打开文件%s失败.\n",sFileName);
		return -1;
	}

	if(GenIntfFile(sHost,sProcModule,sBusinessModule,fp)<0){
		WriteAlertPrint("生成KPI网管接口文件%s错误,sFileName.\n",
			sHost,sBusinessModule);
		return -1;
	}

	fclose(fp);

	WriteProcPrint("生成KPI网管接口文件 %s.\n",sFileName);

	return 0;
}

