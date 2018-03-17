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
	
	/*�������ݿ�*/
	if(ConnectDataDB()<0){
		WriteErrStackAlert();
		return -1;
	}
	
	/*���ر�ALERT_INFO������Ϣ,�������ݴ�Tempȡ��TempIn*/
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
			printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
	        	WriteErrStackAlert();
	        	return -1;
	       	}
	       	iCnt++;
	       	if(iCnt%1000==0){
			WriteProcMsg("��%s��ǰ����¼��Ϊ%d",TempOut.sTableName,iCnt);
		}
	       	
	       	strcpy(Temp.sSendState,"1");
	       	GetHostTime(Temp.sSendDate);
	       	
	       	/*���ͺ����Alert_info��*/
	       	if(EUpdateStructToUAlertInfo(&Temp,false,&TempUp)<0){
	       		WriteAlertPrint("����%s�����",TempUp.sTableName);
			return -1;
		}
	}
	
	if(EUpdateStructToUAlertInfo(NULL,true,&TempUp)<0){
		WriteAlertPrint("����%s��ʱ����",TempUp.sTableName);
		return -1;
	}
	
	WriteProcPrint("�ɹ�����%d����¼��%s",iCnt,TempUp.sTableName);
	
	if(EInsertStructToSvEventTemp(NULL,true,&TempOut)<0){
		printf("д���ݿ��%sʱ����.\n",TempOut.sTableName);
	        WriteErrStackAlert();
	        return -1;
	}
	CommitWorkRelease();

	WriteProcPrint("�ѷ���%d��������Ϣ����������.",iCnt);

	return 0;
}
