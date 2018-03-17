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
	if(strcmp(sBusinessModule,"WN")==0)		*iErrScale=0.00005;
	else if(strcmp(sBusinessModule,"WJ")==0) 	*iErrScale=0.00008;
	else if(strcmp(sBusinessModule,"1X")==0) 	*iErrScale=0.00005;
	else if(strcmp(sBusinessModule,"DX")==0) 	*iErrScale=0.00005;
	else if(strcmp(sBusinessModule,"DX_GSM")==0) 	*iErrScale=0.00005;
	else if(strcmp(sBusinessModule,"DX_CDMA")==0) 	*iErrScale=0.00005;
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
	if(strcmp(sHost,"DXJF")==0){
		if(strcmp(sBusinessModule,"DX_CDMA")==0)
			sprintf(sCondition,"WHERE\n\
				SOURCE_ID IN ('NXPC01')\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);

		else if(strcmp(sBusinessModule,"DX_GSM")==0)
			sprintf(sCondition,"WHERE\n\
				SOURCE_ID IN ('NXPG01')\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);

		else{
			WriteAlertMsg("����SELECT CONDITION����,ϵͳ���%s,ҵ��ģ��%s.\n",
				sHost,sBusinessModule);
			return -1;
		}
	}

	if(strcmp(sHost,"ZHJS")==0){
		if(strcmp(sBusinessModule,"WN")==0){
			sprintf(sCondition,"WHERE\n\
				SOURCE_ID LIKE '__DG__'\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);
		}
				
		else if(strcmp(sBusinessModule,"WJ")==0)
			sprintf(sCondition,"WHERE\n\
				SUBSTR(SOURCE_ID,3,2) IN ('GG','GC','GI','G1','II')\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);

		else if(strcmp(sBusinessModule,"1X")==0)
			sprintf(sCondition,"WHERE\n\
				SOURCE_ID = 'C1XAAA'\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);
								
		else if(strcmp(sBusinessModule,"DX")==0)
			sprintf(sCondition,"WHERE\n\
				SOURCE_ID LIKE '__SS__'\n\
				AND to_char(DATA_DATE,'yyyymmdd')='%s'",
				sDataDate
				);
				
		else{
			WriteAlertMsg("����SELECT CONDITION����,ϵͳ���%s,ҵ��ģ��%s.\n",
				sHost,sBusinessModule);
			printf("����SELECT CONDITION����,ϵͳ���%s,ҵ��ģ��%s.\n",
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
	
	/**��ʼ�����뻺���Ա**/
	bzero((void*)&TempIn,sizeof(struct PrepLogStructIn));
	GetTableName(sProcModule,TempIn.sTableName);
	if (GetCondition(sHost,sBusinessModule,sDataDate,TempIn.sCondition)<0)
		return -1;

	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	/*��ȡ**/
	while(EGetPrepLogToStruct(&Temp,&TempIn)){
		fprintf(fp,"%s%s%s%20s%50s%010d%010d%010d%04d%04d%010d\n",
			sTimeStamp,		/*Ԥ����ʱ���*/
			Temp.sDealBeginDate,	/*Ԥ������ʼʱ��*/
			Temp.sDealEndDate,	/*Ԥ��������ʱ��*/
			Temp.sSourceID,		/*�ļ������˾�����*/
			Temp.sOriFileName,	/*�ļ�����*/
			Temp.iCnt,		/*�ļ��л�������*/
			0,			/*�ļ��в��Ʒѻ�����*/
			(int)(Temp.iCnt*iErrScale),	/*�ļ��д�����*/
			0,			/*�޳�ѭ������*/
			0,			/*�޳�ԭ�����*/
			0			/*�޳�������*/
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
	        printf("�������ݿ�ʧ��\n");
		return -1;
	}
/*
	if(FastConnect("110")<0){
	        printf("fastconnec�������ݿ�ʧ��\n");
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
		printf("Caller:	kpi_nmsintf4nx ZHJS PREP WN .\n" );
		printf("Caller:	kpi_nmsintf4nx ZHJS PREP WJ .\n" );
		printf("Caller:	kpi_nmsintf4nx DXJF BILL DX_GSM .\n" );
		printf("Caller:	kpi_nmsintf4nx DXJF BILL DX_CDMA .\n" );
		return -1;
	}

	InitAppRes(argv[0]);

	strcpy(sHost,argv[1]);Upper(sHost);
	strcpy(sProcModule,argv[2]);Upper(sProcModule);
	strcpy(sBusinessModule,argv[3]);Upper(sBusinessModule);
	strcpy(sOutputPath,argv[4]);RegularDir(sOutputPath);

	if(strcmp(sHost,"ZHJS")!=0&&strcmp(sHost,"DXJF")!=0){
		printf("ϵͳģ�鲻��ȷ������������.\n");
		printf("Ŀǰ����ϵͳģ�飺ZHJS/DXJF.\n");
		return -1;
	}

	if(strcmp(sProcModule,"PREP")==0) strcpy(sProcID,"02");
	else if(strcmp(sProcModule,"BILL")==0) strcpy(sProcID,"03");
	else{
		printf("����ģ�鲻��ȷ������������.\n");
		printf("Ŀǰ��������ģ�飺PREP/BILL.\n");
		return -1;
	}

	if(strcmp(sBusinessModule,"WN")!=0&&
		strcmp(sBusinessModule,"WJ")!=0&&
		strcmp(sBusinessModule,"DX")!=0&&
		strcmp(sBusinessModule,"1X")!=0&&
		strcmp(sBusinessModule,"DX_GSM")!=0&&
		strcmp(sBusinessModule,"DX_CDMA")!=0){
		printf("ҵ��ģ�鲻��ȷ������������.\n");
		printf("Ŀǰ����ҵ��ģ�飺WN/WJ/DX/1X.\n");
		return -1;
	}


	GetHostTime(sFileDate);sFileDate[8]=0;

	sprintf(sFileName,"%s%s_%s_%s",sOutputPath,sBusinessModule,sFileDate,sProcID);

	if((fp=fopen(sFileName,"w"))==NULL){
		printf("���ļ�%sʧ��.\n",sFileName);
		return -1;
	}

	if(GenIntfFile(sHost,sProcModule,sBusinessModule,fp)<0){
		WriteProcPrint("����KPI���ܽӿ��ļ�%s����,sFileName.\n",
			sHost,sBusinessModule);
		return -1;
	}

	fclose(fp);

	WriteProcPrint("����KPI���ܽӿ��ļ� %s.\n",sFileName);

	return 0;
}
