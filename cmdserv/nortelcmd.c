#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cmdparse.h"

int AddCmdHeadTail(char sCmd[])
{
	return 0;
}


int ProcCmd(int(*Proc)(int iBusi,struct ResultStruct **pptHead),
	struct InfoItemStruct *ptInfoItem,char sCmdType[],struct ResultStruct **pptResult)
{
	int iLen;
	char sValue[256],sCmd[256],sDateTime[15];
	char sTmpCmd[256],sTemp[256],sTempValue[256];
	struct InfoItemStruct *ptHead,*ptTemp;

	GetHostTime(sDateTime);
	
	sprintf(sCmd,"MHF00000000111%s000000000000000030",sDateTime);	
	strcpy(sTmpCmd,sCmd);

	if(strcmp(sCmdType,"CRTNAI")==0){
		
		GetItemValue(ptInfoItem,"NAIUSERNAME",sValue);
		if(strcmp(sValue,"")==0) return -1;
		
		sprintf(sTemp,"NAIUSERNAME=%s",sValue);
		sprintf(sTempValue,"DLTNAI%04d%s",strlen(sTemp),sTemp);
		strcat(sCmd,sTempValue);
		
		AddCmd(sCmd,"",pptResult);
	}
		
	if(strcmp(sCmdType,"CRIMSI")==0){
		
		GetItemValue(ptInfoItem,"MDN",sValue);
		if(strcmp(sValue,"")!= 0){
			
			sprintf(sTemp,"MDN=%s",sValue);
			/*命令长度及命令内容*/
			sprintf(sTempValue,"DLIMSI%04d%s",strlen(sTemp),sTemp);
			strcat(sCmd,sTempValue);
		}
		else{
			GetItemValue(ptInfoItem,"IMSI",sValue);
			if(strcmp(sValue,"")!= 0){
				
				sprintf(sTemp,"IMSI=%s",sValue);				
				/*命令长度及命令内容*/
				sprintf(sTempValue,"DLIMSI%04d%s",strlen(sTemp),sTemp);
				strcat(sCmd,sTempValue);
			}
			else
				return -1;
		}

		AddCmd(sCmd,"",pptResult);
	}
	
	if(strcmp(sCmdType,"CRTRLT")==0){

		GetItemValue(ptInfoItem,"NAIUSERNAME",sValue);
		if(strcmp(sValue,"")==0) return -1;		
		sprintf(sTemp,"NAIUSERNAME=%s",sValue);
		strcat(sTempValue,sTemp);
		
		GetItemValue(ptInfoItem,"MDN",sValue);
		if(strcmp(sValue,"")==0) return -1;		
		sprintf(sTemp,"MDN=%s",sValue);
		strcat(sTempValue,sTemp);
		
		GetItemValue(ptInfoItem,"IMSI",sValue);
		if(strcmp(sValue,"")==0) return -1;		
		sprintf(sTemp,"IMSI=%s",sValue);
		strcat(sTempValue,sTemp);
	
		/*命令类型，长度*/
		sprintf(sValue,"DLTRLT%04d",strlen(sTempValue));		
		strcat(sCmd,sValue);
		
		/*命令内容*/
		strcat(sCmd,sTempValue);
		
		AddCmd(sCmd,"",pptResult);
	}
	
	sprintf(sCmd,"%s%s",sTmpCmd,sCmdType);
	sTempValue[0]= '\0';
	
	/*处理命令选项*/
	ptHead= ptInfoItem;
	while(ptHead!= NULL){

		ptTemp= ptHead;
		ptHead= ptHead->pNext;			
		
		sprintf(sTemp,"%s=%s\t",ptTemp->sName,ptTemp->sValue);		
		strcat(sTempValue,sTemp);
	}
	
	/*处理命令结果*/
	
	/*减去最后一个\t*/
	iLen= strlen(sTempValue) - 1;
	
	if(iLen>0){
		
		/*命令长度*/
		sprintf(sValue,"%04d",iLen);
		strcat(sCmd,sValue);
		
		/*命令内容*/
		strncat(sCmd,sTempValue,iLen);
		
		AddCmd(sCmd,"",pptResult);
	}
	
	return 0;
}

/******************************以下内容对AAA无用，确保接口完整**************************/
/*创建新用户请求*/
int ProcCRUSER(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*业务控制请求*/
int ProcCHGSRV(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*删除用户请求*/
int ProcDLUSER(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*修改用户IMSI请求*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*修改用户DN请求*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*修改用户ESN请求*/
int ProcCHGESN(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*修改用户PIC请求*/
int ProcCHGPIC(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*用户信息查询请求*/
int ProcQUINFO(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*用户信息查询反馈*/
int ProcUSIRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*反馈结果应答*/
int ProcRSPACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*收到请求应答*/
int ProcREQACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*请求结果消息*/
int ProcFEBRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*工单内容查询请求*/
int ProcQWINFO(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*工单状态查询请求*/
int ProcQWSTAT(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*工单内容查询结果消息*/
int ProcWDTRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*查询工单结果消息*/
int ProcWITRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}
