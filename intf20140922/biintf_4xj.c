#include <stdio.h>	
#include <stdlib.h>     
#include <wwdb.h>       
#include <wwlog.h>      
#include <wwtiny.h>
#include <wwdir.h>     
#include <bintree.h>    
#include <list.h>   
#include <wwfile.h>     
#include <stt_ticket.h>
#include "param_intf.h"
#include "wwshm.h"
#include "biintf_supp.h"

FILE *fp=NULL;
char sProvCode[5];

int GetProvCode(char sProvCode[5])
{	
	int iRet;
	char sTemp[128],sPath[128];

	GetIniName(sPath);
	
	iRet=ReadString(sPath,"bss","updata","belong_code",sTemp);
	ERROR_RETURNZ(iRet<0,"读取bill.ini文件失败");
	ERROR_RETURNA((strlen(sTemp)==0),"bill.ini->bss->updata-%s无对应配置",
		"belong_code");
/*
	if(iRet<0) printf("读取bill.ini文件失败\n");
	if(strlen(sTemp)==0) 
		printf("bill.ini->bss->updata-belong_code无对应配置\n");
*/
	strncpy(sProvCode,sTemp,4);
	sProvCode[4]=0;
	AllTrim(sProvCode);

	return 0;
}

int GenSttFile(char sTableName[],FILE *fp,char sStatMonth[])
{
	int l,iCount=0;
	char sRecord[200];
	
	struct BiintfSttStruct Temp;
        struct BiintfSttStructIn TempIn;
        
        bzero((void*)&TempIn,sizeof(struct BiintfSttStructIn));
        strcpy(TempIn.sTableName,sTableName);
        strcpy(TempIn.sCondition,"");
        
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetBiintfSttToStruct(&Temp,&TempIn)){
        	if(iCount%10000==0&&iCount!=0){
			printf("表%s导出数据%d条.\n",TempIn.sTableName,iCount);
			WriteProcMsg("表%s导出数据%d条.",TempIn.sTableName,iCount);
		}

		l=0;
		bzero(sRecord,200);
		
		l+=sprintf(sRecord+l,"|%s|"	,sStatMonth	);              
		l+=sprintf(sRecord+l,"%s|"	,Temp.sNbrAreaCode	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallingNbr	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sVisitAreaCode	);      		      
		l+=sprintf(sRecord+l,"%s|"	,Temp.sDistanceType	);	
		l+=sprintf(sRecord+l,"%s|"	,Temp.sRoamType		);      
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallDirection	);      
		l+=sprintf(sRecord+l,"%d|"	,Temp.iTicketTypeID	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iCalledCarrierID	);      		     
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeOut		);	
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeIn		);      
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeDuration	);      
		l+=sprintf(sRecord+l,"%d\r\n"	,Temp.iDuration		);      
		
		WriteFile(fp,sRecord,l);
		iCount++;

        }
        return 0;
}

int GenTllFile(char sTableName[],FILE *fp,char sStatMonth[])
{
	int l,iCount=0;
	char sRecord[200];
	
	struct BiintfTllStruct Temp;
        struct BiintfTllStructIn TempIn;
        
        bzero((void*)&TempIn,sizeof(struct BiintfTllStructIn));
        strcpy(TempIn.sTableName,sTableName);
        strcpy(TempIn.sCondition,"");
        
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetBiintfTllToStruct(&Temp,&TempIn)){
        	if(iCount%10000==0&&iCount!=0){
			printf("表%s导出数据%d条.\n",TempIn.sTableName,iCount);
			WriteProcMsg("表%s导出数据%d条.",TempIn.sTableName,iCount);
		}

		l=0;
		bzero(sRecord,200);

		l+=sprintf(sRecord+l,"|%s|"	,sStatMonth		);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sNbrAreaCode	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallingNbr	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sVisitAreaCode	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sDistanceType	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sRoamType		);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallDirection	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iTicketTypeID	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iOppCarrierID	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeIn		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeOut		);	
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeDuration	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iDuration		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iRoamFee		);
		l+=sprintf(sRecord+l,"%d\r\n"	,Temp.iTollFee		);
      
		WriteFile(fp,sRecord,l);
		iCount++;

        }
        return 0;
}

int GenSrtFile(char sTableName[],FILE *fp,char sStatMonth[])
{
	int l,iCount=0;
	char sRecord[200];
	
	struct BiintfSrtStruct Temp;
        struct BiintfSrtStructIn TempIn;
        
        bzero((void*)&TempIn,sizeof(struct BiintfSrtStructIn));
        strcpy(TempIn.sTableName,sTableName);
        strcpy(TempIn.sCondition,"");
        
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetBiintfSrtToStruct(&Temp,&TempIn)){
        	if(iCount%10000==0&&iCount!=0){
			printf("表%s导出数据%d条.\n",TempIn.sTableName,iCount);
			WriteProcMsg("表%s导出数据%d条.",TempIn.sTableName,iCount);
		}

		l=0;
		bzero(sRecord,200);

		l+=sprintf(sRecord+l,"|%s|"	,sStatMonth		);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sVisitAreaCode	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallingNbr	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sDistanceType	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sRoamType		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iSettCarrierID	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallDirection	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iTicketTypeID	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeIn		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeOut		);	
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeDuration	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iDuration		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iRoamFee		);
		l+=sprintf(sRecord+l,"%d\r\n"	,Temp.iTollFee		);
		
		WriteFile(fp,sRecord,l);
		iCount++;

        }
        return 0;
}

int GenVitFile(char sTableName[],FILE *fp,char sStatDate[])
{
	int l,iCount=0;
	char sRecord[200];
	
	struct BiintfVitStruct Temp;
        struct BiintfVitStructIn TempIn;
        
        bzero((void*)&TempIn,sizeof(struct BiintfVitStructIn));
        strcpy(TempIn.sTableName,sTableName);
        strcpy(TempIn.sCondition,"WHERE START_DATE='");
        strcat(TempIn.sCondition,sStatDate);
        strcat(TempIn.sCondition,"'");
        
        /*printf("TempIn.sCondition=%s\n",TempIn.sCondition);*/
        
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetBiintfVitToStruct(&Temp,&TempIn)){
        	if(iCount%10000==0&&iCount!=0){
			printf("表%s导出数据%d条.\n",TempIn.sTableName,iCount);
			WriteProcMsg("表%s导出数据%d条.",TempIn.sTableName,iCount);
		}

		l=0;
		bzero(sRecord,200);
		
		l+=sprintf(sRecord+l,"|%s|"	,sStatDate		);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sVisitAreaCode	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCellID		);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallType		);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sDistanceType	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sRoamType		);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sTimePeriod	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iOppCarrierID	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iCounts		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iCallTimes	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iDuration		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iRoamDuration	);
		l+=sprintf(sRecord+l,"%d\r\n"	,Temp.iTollDuration	);

		WriteFile(fp,sRecord,l);
		iCount++;

        }
        return 0;
}

int main(int argc,char *argv[])
{
	char	sFileName[32],sTableName[32],sStatPeriod[9],sOutputDir[128],
		sOutputFile[128],sModule[4];

	GetProvCode(sProvCode);
	printf("Now generate sProvCode=%s\n",sProvCode);
	if(strcmp(sProvCode,"089")==0){
		printf("You wanna generate BI interface for [Xinjiang] Province?\n");
		printf("Please read through intruction following:"); 
		printf("file_name			table_name			remark				\n");
		printf("C1104627MYYYYMMDD1101.Txt	jyfx_stt_cm_gsm_991_yyyymm      GSM结算分析详单（移动）		\n");
		printf("C1104627MYYYYMMDD1102.Txt	jyfx_stt_cm_gsm_other_yyyymm    GSM结算分析详单（移动）		\n");
		printf("C1104628MYYYYMMDD1101.Txt	jyfx_stt_ct_gsm_991_yyyymm      GSM结算分析详单（电信）		\n");
		printf("C1104628MYYYYMMDD1102.Txt	jyfx_stt_ct_gsm_other_yyyymm    GSM结算分析详单（电信）		\n");
		printf("C1104629MYYYYMMDD1101.Txt	jyfx_stt_cnc_crc_gsm_yyyymm     GSM结算分析详单（其它）		\n");
		printf("C1104630MYYYYMMDD1101.Txt	jyfx_tll_prv_gsm_yyyymm         GSM结算分析详单（联通省内）	\n");
		printf("C1104631MYYYYMMDD1101.Txt	jyfx_tll_vit_gsm_yyyymm         GSM结算分析详单（联通省际）	\n");
		printf("                                                                                                \n");
		printf("C2104627MYYYYMMDD1101.Txt	jyfx_stt_cm_cdma_991_yyyymm      CDMA结算分析详单（移动）	\n");
		printf("C2104627MYYYYMMDD1102.Txt	jyfx_stt_cm_cdma_other_yyyymm    CDMA结算分析详单（移动          \n");
		printf("C2104628MYYYYMMDD1101.Txt	jyfx_stt_ct_cdma_991_yyyymm      CDMA结算分析详单（电信）        \n");
		printf("C2104628MYYYYMMDD1102.Txt	jyfx_stt_ct_cdma_other_yyyymm    CDMA结算分析详单（电信）        \n");
		printf("C2104629MYYYYMMDD1101.Txt	jyfx_stt_cnc_crc_cdma_yyyymm     CDMA结算分析详单（其它）        \n");
		printf("C2104630MYYYYMMDD1101.Txt	jyfx_tll_prv_cdma_yyyymm         CDMA结算分析详单（联通省内）    \n");
		printf("C2104631MYYYYMMDD1101.Txt	jyfx_tll_vit_cdma_yyyymm         CDMA结算分析详单（联通省际）    \n");
	}
	else{
		printf("The program does not run under [Xinjiang] Province.Please check\n");
		return -1;
	}
	
	if(argc!=5){
		printf("Usage %s FileName TableName OutputDir StatPeriod\n",argv[0]);
		return -1;
	}
	
	strcpy(sFileName,argv[1]);
	strcpy(sTableName,argv[2]);Upper(sTableName);
	strcpy(sOutputDir,argv[3]);
	RegularDir(sOutputDir);
	printf("sOutputDir=%s\n",sOutputDir);
	strcpy(sOutputFile,sOutputDir);
	strcat(sOutputFile,sFileName);
	strcpy(sStatPeriod,argv[4]);
						
	printf("sOutputFile=%s\n",sOutputFile);
	
	if((fp=fopen(sOutputFile,"w"))==NULL) return -1;

	if(IniConnect("dataconnstr")<0){ 
	        printf("connerror\n");
		return -1;	
	}
	
	/*生成文件*/
	strncpy(sModule,sTableName+5,3);
	
	printf("sModule=%s\n",sModule);
	if(strncmp(sModule,"STT",3)==0)
		GenSttFile(sTableName,fp,sStatPeriod);
	else if(strncmp(sModule,"TLL",3)==0)
		GenTllFile(sTableName,fp,sStatPeriod);
/*
	else if(strncmp(sModule,"SRT",3)==0)                   
		GenSrtFile(sTableName,fp,sStatPeriod);
	else if(strncmp(sModule,"VIT",3)==0)
		GenVitFile(sTableName,fp,sStatPeriod);
*/
	else{
		printf("业务模块不正确，请重新输入.\n");
		return -1;
	}

	printf("从表%s统计数据，生成%s文件完毕\n",
		sTableName,sOutputFile);
	WriteProcMsg("从表%s统计数据，生成%s文件完毕\n",
		sTableName,sOutputFile);
		
	fclose(fp);
	DisconnectDatabase();
			
	return 0;	
}

