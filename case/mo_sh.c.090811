#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <wwfile.h>
#include <bintree.h>

#include <alert_info.h>

static int data_comp_alert_info_e(void *pValue,void *pData)
{
	int res;
	struct AlertInfoStruct *pSource=(struct AlertInfoStruct *)pValue;
	struct AlertInfoStruct *pTarget=(struct AlertInfoStruct *)pData;

	if((res=strcmp(pSource->sRemark,pTarget->sRemark))!=0) return res;

	if((res=strcmp(pSource->sDeviceName,pTarget->sDeviceName))!=0) return res;
	if((res=strcmp(pSource->sCategory,pTarget->sCategory))!=0) return res;
	if((res=(pSource->iLevel1-pTarget->iLevel1))!=0) return res;
	if((res=strcmp(pSource->sObjectName,pTarget->sObjectName))!=0) return res;
	if((res=strcmp(pSource->sDeviceIp,pTarget->sDeviceIp))!=0) return res;
	return 0;
}

char *asLogName[]={
	"$APPHOMElog/chkfs_mo.log",
	"$APPHOMElog/chkts_mo.log",
	"$APPHOMElog/chktrunk_mo.log",
	"$APPHOMElog/chkseq_mo_30.log",
	"$APPHOMElog/alert_udret.log",
	"$APPHOMElog/chkdelay_mo.log",
	"$APPHOMElog/chkfilecnt_RII.log",
	"$APPHOMElog/chkfilecnt_RRI.log",
	"$APPHOMElog/chkfilecnt_GBR.log",
	"$APPHOMElog/chkfilecnt_KIO.log",
	"$APPHOMElog/chkfilecnt_KRO.log",
	"$APPHOMElog/chkfilecnt_CBR.log",
	"$APPHOMElog/chkfilecnt_CDMA1XR.log"
};

int main(int argc,char *argv[])
{
	BINTREE *pRoot=NULL;
	int i,iCnt=0;
	char sLogName[256],sBaseName[256],sAppHome[256],sRecord[512],sTemp[512];
	struct AlertInfoStruct Temp,*pTemp,*ptHead=NULL;
	struct AlertInfoStructIn TempIn;
	struct AlertInfoStructOut TempOut;
	
	struct FileControlStruct *pCtlList=NULL,*ptPre=NULL,*ptCur;
	
	
/*	if(argc !=2 ){
		printf("Usage %s mo_sh.ini groupid.\n",argv[0]);
		return -1;		
	}*/
	
	InitAppRes(argv[0]);
	
	strcpy(TempIn.sTableName,"ALERT_INFO");
	TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag =TRUE;
        
        bzero((void*)&TempOut,sizeof(struct AlertInfoStructOut));
	strcpy(TempOut.sTableName,"ALERT_INFO");
	
	/*连接数据库*/
	if(ConnectDataDB()<0){
		WriteErrStackAlert();
		return -1;
	}
	/*加载表ALERT_INFO故障信息,挂到平衡二叉树*/
	while(EGetAlertInfoToStruct(&Temp,&TempIn)){
		
		if((pTemp=malloc(sizeof(struct AlertInfoStruct)))==NULL){
        		printf("error Malloc AlertInfoStruct.\n");
			return -1;
		}
		memcpy((void*)pTemp,(void*)&Temp,
			sizeof(struct AlertInfoStruct));

		if(InsertBin(&pRoot,(void*)pTemp,data_comp_alert_info_e,
			assign_insert_bintree)<0){
			WriteAlertPrint("生成BINTREE失败bintree_sticket");
			return -1;
		}
	}
	
		
	/*扫描日志文件,故障日志信息写到结构缓冲*/
	for(i=0;i<13;i++){
		
		strcpy(sLogName,asLogName[i]);

		GetAppHome(sAppHome);
		
		ReplaceStr(sLogName,"$APPHOME",sAppHome);
		
		if(TxtFileToList(sLogName,&pCtlList)<0){
			printf("加载文件%s失败",sLogName);
			continue;
		}
		ptCur=pCtlList;
		while(ptCur){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			strncpy(sRecord,ptPre->pData,ptPre->iLen);
			sRecord[ptPre->iLen]=0;
			
			if(strstr(sRecord,"正常")!=NULL||
     			strstr(sRecord,"065535")!=NULL||
     			strstr(sRecord,"中继找不到")!=NULL) continue;
     			
     			GetBaseName(sLogName,sBaseName);
     			if(strcmp(sBaseName,"chkdelay_mo.log")==0&&
     				(strstr(sRecord,"D16801")!=NULL||
     				strstr(sRecord,"D16803")!=NULL||
     				strstr(sRecord,"SMSC01")!=NULL)) continue;
     			
     			strcpy(sTemp,sRecord+strlen("01 20080928 15:26:35 3"));

			Temp.iAlertID=iGetAlertInfoID();
			strcpy(Temp.sDeviceName,"结算主机");
			strcpy(Temp.sCategory,"Application");
			Temp.iLevel1=2;
			strcpy(Temp.sObjectName,"结算系统");
			strcpy(Temp.sDeviceIp,"130.38.9.98");
			strcpy(Temp.sRemark,sTemp);
			AllTrim(Temp.sRemark);
			GetHostTime(Temp.sCreatedDate);
			GetHostTime(Temp.sDealDate);
			strcpy(Temp.sAlertSource,"结算系统");
			strcpy(Temp.sMsgID,"");
			strcpy(Temp.sSendState,"0");
			strcpy(Temp.sSendDate,"");
			
			/*比较是否有重复信息,若重复则不写表*/
			if(SearchBin(pRoot,&Temp,data_comp_alert_info_e,(void**)&ptHead)==FOUND){
				printf("有重复信息.\n");
				free(ptPre);
				continue;
			}
			if(EInsertStructToAlertInfo(&Temp,FALSE,&TempOut)<0){
				printf("写数据库表%s时出错.\n",TempOut.sTableName);
	        		WriteErrStackAlert();
	        		return -1;
	       		}
	       		iCnt++;
	       		if(iCnt%1000==0){
				WriteProcMsg("表%s当前入库记录数为%d",TempOut.sTableName,iCnt);
			}
			free(ptPre);
		}	
	}
	
	if(EInsertStructToAlertInfo(NULL,true,&TempOut)<0){
		printf("写数据库表%s时出错.\n",TempOut.sTableName);
	        WriteErrStackAlert();
	        return -1;
	}
	CommitWorkRelease();

	printf("监控故障信息入库成功,记录数为%d.\n",iCnt);

	return 0;

}
