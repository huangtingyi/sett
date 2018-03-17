#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <sv_events.h>


int main(int argc,char *argv[])
{
	int iCnt=0,iTempID;
	struct AlertInfoStructIn TempIn;
	struct SvEventTempStruct SvTemp;
	struct SvEventTempStructOut TempOut;
	static struct UAlertInfoStructUp TempUp;
	struct UAlertInfoStruct Temp;

	/*if(argc !=2 ){
		printf("Usage %s mo_sh.ini groupid.\n",argv[0]);
		return -1;		
	}*/

	InitAppRes(argv[0]);
	
	strcpy(TempIn.sTableName,"ALERT_INFO");
	strcpy(TempIn.sCondition,"WHERE SEND_STATE='0'");
	TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag =TRUE;
        
        bzero((void*)&TempOut,sizeof(struct SvEventTempStructOut));
	strcpy(TempOut.sTableName,"SV_EVENT_TEMP");
	
	bzero((void*)&TempUp,sizeof(struct UAlertInfoStructUp));
	strcpy(TempUp.sTableName,"ALERT_INFO");
	
	/*连接数据库*/
	if(ConnectDataDB()<0){
		WriteErrStackAlert();
		return -1;
	}
	
	/*加载表ALERT_INFO故障信息,即将数据从Temp取到TempIn*/
	while(EGetUAlertInfoToStruct(&Temp,&TempIn)){
		
		iTempID=iGetSvEventTempID();
		sprintf(SvTemp.sTmpID,"%d",iTempID);
		
		strcpy(SvTemp.sTmpDeviceName,Temp.sDeviceName);
		strcpy(SvTemp.sTmpCategory,Temp.sCategory);
		SvTemp.iTmpSeverity=Temp.iLevel1;
		strcpy(SvTemp.sTmpObject,Temp.sObjectName);
		strcpy(SvTemp.sTmpIpAddress,Temp.sDeviceIp);
		strcpy(SvTemp.sTmpContent,Temp.sRemark);
		strcpy(SvTemp.sTmpCreatedTime,Temp.sCreatedDate);
		GetHostTime(SvTemp.sTmpReceivedTime);
		strcpy(SvTemp.sMessageNumber,"");
		strcpy(SvTemp.sEventSource,Temp.sAlertSource);
		
		if(EInsertStructToSvEventTemp(&SvTemp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",TempOut.sTableName);
	        	WriteErrStackAlert();
	        	return -1;
	       	}
	       	iCnt++;
	       	if(iCnt%1000==0){
			WriteProcMsg("表%s当前入库记录数为%d",TempOut.sTableName,iCnt);
		}
	       	
	       	strcpy(Temp.sSendState,"1");
	       	GetHostTime(Temp.sSendDate);
	       	
	       	/*发送后更新Alert_info表*/
	       	if(EUpdateStructToUAlertInfo(&Temp,false,&TempUp)<0){
	       		WriteAlertPrint("更新%s表错误",TempUp.sTableName);
			return -1;
		}
	}
	
	if(EUpdateStructToUAlertInfo(NULL,true,&TempUp)<0){
		WriteAlertPrint("更新%s表时错误",TempUp.sTableName);
		return -1;
	}
	
	WriteProcPrint("成功更新%d条记录到%s",iCnt,TempUp.sTableName);
	
	if(EInsertStructToSvEventTemp(NULL,true,&TempOut)<0){
		printf("写数据库表%s时出错.\n",TempOut.sTableName);
	        WriteErrStackAlert();
	        return -1;
	}
	CommitWorkRelease();

	WriteProcPrint("已发送%d条故障信息到网管三期.",iCnt);

	return 0;
}
