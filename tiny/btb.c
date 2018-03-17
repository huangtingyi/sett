/*---------函数实现代码 unicom_ticket.pc----------*/
#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>

#include <stt_ticket.h>

int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char sPath[256],sFileName[256],sCommand[256],sPreName[256];
	static int iCount=0,iSeq=0;
        
        struct SttTicketStruct Temp;
        struct SttTicketStructIn TempIn;

	if(argc!=3){
		printf("用法：%s path tablename.\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);
        IniConnect("dataconnstr");
        
        bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));
	strcpy(TempIn.sCondition,"");
	
        strcpy(sPath,argv[1]);
        strcpy(TempIn.sTableName,argv[2]);
	RegularDir(sPath);
	Upper(TempIn.sTableName);
	
	strcpy(sPreName,"");
	strcpy(sFileName,"");
	
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;
        	
        while(EGetSttTicketToStruct(&Temp,&TempIn)){
        
		if(iCount%10000==0&&iCount!=0){
			printf("表%s导出话单话单数%d.\n",TempIn.sTableName,iCount);
			WriteProcMsg("表%s导出话单话单数%d.",TempIn.sTableName,iCount);
		}
		if(iCount%20000000==0){
			if(fp!=NULL)fclose(fp);
			if(strcmp(sPreName,"")!=0){
				sprintf(sCommand,"compress %s",sPreName);
				system(sCommand);
				printf("文件 %s 生成完毕.\n",sPreName);
				WriteProcMsg("文件 %s 生成完毕.",sPreName);
			}
			sprintf(sFileName,"%s%s.%03d",
				sPath,TempIn.sTableName,iSeq);
			strcpy(sPreName,sFileName);
			if((fp=fopen(sFileName,"w"))==NULL){
				printf("打开文件%s失败.\n",sFileName);
				exit(1);
			}
			iSeq++;
		}
		iCount++;
			
		fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\n",
			Temp.sCallType,Temp.sMsisdn,Temp.sOtherParty,
			Temp.sStartTime,Temp.iDuration,Temp.iTicketTypeID,
			Temp.sThirdParty,Temp.sMsc,Temp.sTrunkIn,Temp.sTrunkOut,
			Temp.iRoamFee,Temp.iTollFee,Temp.iAddFee,
			Temp.sSplitType,Temp.sUserType,Temp.sSourceID);

        }
	if(fp!=NULL)fclose(fp);
	if(strcmp(sFileName,"")!=0){
		sprintf(sCommand,"compress %s",sFileName);
		system(sCommand);
		printf("文件 %s 生成完毕.\n",sFileName);
		WriteProcMsg("文件 %s 生成完毕.",sFileName);
	}
        
	printf("输出联通完毕，话单总数%d.\n",iCount);
	WriteProcMsg("表%s生成文件完毕,话单总数%d.",TempIn.sTableName,iCount);

        DisconnectDatabase();

	return 0;
}

