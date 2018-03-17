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

int GenTableName(char sModule[],char sStatMonth[],char sOppCarrier[],
	char sAreaCode[],char sTableName[])
{
	char sMonth[3];
	
	strncpy(sMonth,sStatMonth+4,2);sMonth[2]=0;
	strcpy(sTableName,"BIINTF_");

	if(strcmp(sModule,"STT")==0){
		strcat(sTableName,sModule);
		strcat(sTableName,"_");
		if(strcmp(sOppCarrier,"CT")!=0){
			strcat(sTableName,sOppCarrier);
			strcat(sTableName,"_");
		}
		if(strcmp(sOppCarrier,"CT")==0 || strcmp(sOppCarrier,"CM")==0){
			strcat(sTableName,sAreaCode);
			strcat(sTableName,"_");
		}
		strcat(sTableName,sMonth);	
	}
	else if(strcmp(sModule,"STP")==0){
		strcat(sTableName,sModule);
		strcat(sTableName,"_");
		strcat(sTableName,sOppCarrier);
		strcat(sTableName,"_");
		if(strcmp(sOppCarrier,"CT")==0 || strcmp(sOppCarrier,"CM")==0){
			strcat(sTableName,sAreaCode);
			strcat(sTableName,"_");
		}
		strcat(sTableName,sMonth);
	}
	else{
		strcat(sTableName,sModule);
		strcat(sTableName,"_");
		strcat(sTableName,sMonth);		
	}
	return 0;	
}

int GenFileName(char sOutputDir[],char sModule[],char sStatPeriod[],
	char sOppCarrier[],char sAreaCode[],char sOutputFile[])
{	
	char sFileNamePrefix[30];
	char sFileNameSuffix[30];
	char sBaseFileName[30];
 	
	if(strncmp(sModule,"STT",3)==0){
		strcpy(sFileNamePrefix,"C0010JS1M");
		if(strcmp(sOppCarrier,"CT")==0){ 
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000002101.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000002102.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000002103.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000002104.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000002105.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000002106.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000002107.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000002108.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000002109.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}
		}
		else if(strcmp(sOppCarrier,"CM")==0){ 
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000002110.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000002111.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000002112.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000002113.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000002114.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000002115.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000002116.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000002117.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000002118.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}			
		}
		else if(strcmp(sOppCarrier,"CNC")==0) 
			strcpy(sFileNameSuffix,"0000002119.Txt");
		else if(strcmp(sOppCarrier,"CRC")==0)
				strcpy(sFileNameSuffix,"0000002120.Txt");
		else if(strcmp(sOppCarrier,"CS")==0)
				strcpy(sFileNameSuffix,"0000002121.Txt");
		else if(strcmp(sOppCarrier,"CTC")==0)
				strcpy(sFileNameSuffix,"0000002122.Txt");
		else{
			printf("生成文件名错误!");
			return -1;
		}
		strcpy(sBaseFileName,sFileNamePrefix);
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,sFileNameSuffix);	
	}
	else if(strncmp(sModule,"TLL",3)==0){
		strcpy(sBaseFileName,"C0010JS2M");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"0000000101.Txt");
	}
	else if(strncmp(sModule,"SRT",3)==0){
		strcpy(sBaseFileName,"C0010JS3M");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"0000000101.Txt");
	}
	else if(strncmp(sModule,"VIT",3)==0){
		strcpy(sBaseFileName,"C0010JS4D");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"00000101.Txt");
	}
	/*固网送经营分析文件名定义*/
	else if(strncmp(sModule,"STP",3)==0){
		strcpy(sFileNamePrefix,"C0010JS1M");
		if(strcmp(sOppCarrier,"CT")==0){ 
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000001101.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000001102.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000001103.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000001104.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000001105.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000001106.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000001107.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000001108.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000001109.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}
		}
		else if(strcmp(sOppCarrier,"CM")==0){ 
			if(strcmp(sAreaCode,"591")==0)
				strcpy(sFileNameSuffix,"0000001110.Txt");
			else if(strcmp(sAreaCode,"592")==0)
				strcpy(sFileNameSuffix,"0000001111.Txt");
			else if(strcmp(sAreaCode,"593")==0)
				strcpy(sFileNameSuffix,"0000001112.Txt");
			else if(strcmp(sAreaCode,"594")==0)
				strcpy(sFileNameSuffix,"0000001113.Txt");
			else if(strcmp(sAreaCode,"595")==0)
				strcpy(sFileNameSuffix,"0000001114.Txt");
			else if(strcmp(sAreaCode,"596")==0)
				strcpy(sFileNameSuffix,"0000001115.Txt");
			else if(strcmp(sAreaCode,"597")==0)
				strcpy(sFileNameSuffix,"0000001116.Txt");
			else if(strcmp(sAreaCode,"598")==0)
				strcpy(sFileNameSuffix,"0000001117.Txt");
			else if(strcmp(sAreaCode,"599")==0)
				strcpy(sFileNameSuffix,"0000001118.Txt");
			else{
				printf("生成文件名错误!");
				return -1;
			}
		}
		else if(strcmp(sOppCarrier,"CRC")==0)
				strcpy(sFileNameSuffix,"0000001120.Txt");
		else{
			printf("生成文件名错误!");
			return -1;
		}
		strcpy(sBaseFileName,sFileNamePrefix);
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,sFileNameSuffix);
	}
	else if(strncmp(sModule,"TLP",3)==0){
		strcpy(sBaseFileName,"C0010JS2M");
		strcat(sBaseFileName,sStatPeriod);
		strcat(sBaseFileName,"0000001101.Txt");
	}
	else{
		printf("生成文件名失败！\n");
		return -1;
	}
	
	RegularDir(sOutputDir);
	strcpy(sOutputFile,sOutputDir);
	strcat(sOutputFile,sBaseFileName);
	
	return 0;
}

int GenSttFile4fj(char sTableName[],FILE *fp,char sStatMonth[])
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

        while(EGetBiintfSttToStruct4fj(&Temp,&TempIn)){
        	if(iCount%10000==0&&iCount!=0){
			printf("表%s导出数据%d条.\n",TempIn.sTableName,iCount);
			WriteProcMsg("表%s导出数据%d条.",TempIn.sTableName,iCount);
		}

		l=0;
		bzero(sRecord,200);
		
		l+=sprintf(sRecord+l,"|%s|"	,sStatMonth	);              
		l+=sprintf(sRecord+l,"%s|"	,Temp.sVisitAreaCode	);      
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallingNbr	);      
		l+=sprintf(sRecord+l,"%s|"	,Temp.sDistanceType	);	
		l+=sprintf(sRecord+l,"%s|"	,Temp.sRoamType		);      
		l+=sprintf(sRecord+l,"%d|"	,Temp.iCalledCarrierID	);      
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallDirection	);      
		l+=sprintf(sRecord+l,"%d|"	,Temp.iTicketTypeID	);      
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeIn		);      
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeOut		);	
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeDuration	);      
		l+=sprintf(sRecord+l,"%d|\r\n"	,Temp.iDuration		);      
		
		WriteFile(fp,sRecord,l);
		iCount++;

        }
        return 0;
}

int GenTllFile4fj(char sTableName[],FILE *fp,char sStatMonth[])
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

        while(EGetBiintfTllToStruct4fj(&Temp,&TempIn)){
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
		l+=sprintf(sRecord+l,"%d|"	,Temp.iOppCarrierID	);
		l+=sprintf(sRecord+l,"%s|"	,Temp.sCallDirection	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iTicketTypeID	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeIn		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeOut		);	
		l+=sprintf(sRecord+l,"%d|"	,Temp.iFeeDuration	);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iDuration		);
		l+=sprintf(sRecord+l,"%d|"	,Temp.iRoamFee		);
		l+=sprintf(sRecord+l,"%d|\r\n"	,Temp.iTollFee		);
      
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
		l+=sprintf(sRecord+l,"%d|\r\n"	,Temp.iTollFee		);
		
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
		l+=sprintf(sRecord+l,"%d|\r\n"	,Temp.iTollDuration	);

		WriteFile(fp,sRecord,l);
		iCount++;

        }
        return 0;
}

int main(int argc,char *argv[])
{
	char	sTableName[32],sStatMonth[7],sStatDate[9],sOutputDir[128],
		sOutputFile[128],sModule[4],sOppCarrier[4],sAreaCode[4];
		
	if(argc!=4 && argc!=5 && argc!=6){
		printf("Usage %s Module OutputDir StatPeriod [OppCarrier] [AreaCode]\n",argv[0]);
		printf("sample:\n");
		printf("%s stt /home/bill/test 200506 ct 591\n"	,argv[0]);
		printf("%s stp /home/bill/test 200506 ct 591\n"	,argv[0]);
		printf("%s stt /home/bill/test 200506 cnc \n"	,argv[0]);
		printf("%s tll /home/bill/test 200506 \n"	,argv[0]);
		printf("%s srt /home/bill/test 200506 \n"	,argv[0]);
		printf("%s vit /home/bill/test 20050620 \n"	,argv[0]);
		return -1;
	}
	                
	strcpy(sModule,argv[1]);
	Upper(sModule);
	strcpy(sOutputDir,argv[2]);

	if(strcmp(sModule,"STT")!=0 && 
		strcmp(sModule,"TLL")!=0 &&
		strcmp(sModule,"SRT")!=0 &&
		strcmp(sModule,"VIT")!=0 &&
		strcmp(sModule,"STP")!=0 &&
		strcmp(sModule,"TLP")!=0){
		printf("业务模块错误，请重新输入！\n");
		return -1;
	}
	
	if(strcmp(sModule,"STT")==0 || strcmp(sModule,"STP")==0){
		strcpy(sStatMonth,argv[3]);
		strcpy(sOppCarrier,argv[4]);
		Upper(sOppCarrier);
		strcpy(sAreaCode,argv[5]);
	}
	
	if(strcmp(sModule,"TLL")==0 || strcmp(sModule,"SRT")==0 
		|| strcmp(sModule,"TLP")==0)
		strcpy(sStatMonth,argv[3]);
	
	if(strcmp(sModule,"VIT")==0){
		strcpy(sStatDate,argv[3]);
		strncpy(sStatMonth,sStatDate,6);
		sStatMonth[6]=0;
	}
		
	/*生成表名*/
	GenTableName(sModule,sStatMonth,sOppCarrier,sAreaCode,sTableName);
	printf("sTableName=%s\n",sTableName);
	
	/*生成文件名*/

	if(strncmp(sModule,"VIT",3)==0)
		GenFileName(sOutputDir,sModule,sStatDate,sOppCarrier,
			sAreaCode,sOutputFile);
	else
		GenFileName(sOutputDir,sModule,sStatMonth,sOppCarrier,
			sAreaCode,sOutputFile);
					
	printf("sOutputFile=%s\n",sOutputFile);
	
	if((fp=fopen(sOutputFile,"w"))==NULL) return -1;

	if(IniConnect("dataconnstr")<0){ 
	        printf("connerror\n");
		return -1;	
	}
	
	/*生成文件*/
	if(strncmp(sModule,"STT",3)==0 || strncmp(sModule,"STP",3)==0)
		GenSttFile4fj(sTableName,fp,sStatMonth);
	else if(strncmp(sModule,"TLL",3)==0 || strncmp(sModule,"TLP",3)==0)
		GenTllFile4fj(sTableName,fp,sStatMonth);
	else if(strncmp(sModule,"SRT",3)==0)
		GenSrtFile(sTableName,fp,sStatMonth);
	else if(strncmp(sModule,"VIT",3)==0)
		GenVitFile(sTableName,fp,sStatDate);

	printf("从表%s统计数据，生成%s文件完毕\n",
		sTableName,sOutputFile);
	WriteProcMsg("从表%s统计数据，生成%s文件完毕\n",
		sTableName,sOutputFile);
		
	fclose(fp);
	DisconnectDatabase();
			
	return 0;
}

