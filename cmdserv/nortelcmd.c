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
			/*����ȼ���������*/
			sprintf(sTempValue,"DLIMSI%04d%s",strlen(sTemp),sTemp);
			strcat(sCmd,sTempValue);
		}
		else{
			GetItemValue(ptInfoItem,"IMSI",sValue);
			if(strcmp(sValue,"")!= 0){
				
				sprintf(sTemp,"IMSI=%s",sValue);				
				/*����ȼ���������*/
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
	
		/*�������ͣ�����*/
		sprintf(sValue,"DLTRLT%04d",strlen(sTempValue));		
		strcat(sCmd,sValue);
		
		/*��������*/
		strcat(sCmd,sTempValue);
		
		AddCmd(sCmd,"",pptResult);
	}
	
	sprintf(sCmd,"%s%s",sTmpCmd,sCmdType);
	sTempValue[0]= '\0';
	
	/*��������ѡ��*/
	ptHead= ptInfoItem;
	while(ptHead!= NULL){

		ptTemp= ptHead;
		ptHead= ptHead->pNext;			
		
		sprintf(sTemp,"%s=%s\t",ptTemp->sName,ptTemp->sValue);		
		strcat(sTempValue,sTemp);
	}
	
	/*����������*/
	
	/*��ȥ���һ��\t*/
	iLen= strlen(sTempValue) - 1;
	
	if(iLen>0){
		
		/*�����*/
		sprintf(sValue,"%04d",iLen);
		strcat(sCmd,sValue);
		
		/*��������*/
		strncat(sCmd,sTempValue,iLen);
		
		AddCmd(sCmd,"",pptResult);
	}
	
	return 0;
}

/******************************�������ݶ�AAA���ã�ȷ���ӿ�����**************************/
/*�������û�����*/
int ProcCRUSER(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*ҵ���������*/
int ProcCHGSRV(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*ɾ���û�����*/
int ProcDLUSER(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�޸��û�IMSI����*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�޸��û�DN����*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�޸��û�ESN����*/
int ProcCHGESN(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�޸��û�PIC����*/
int ProcCHGPIC(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�û���Ϣ��ѯ����*/
int ProcQUINFO(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�û���Ϣ��ѯ����*/
int ProcUSIRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�������Ӧ��*/
int ProcRSPACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�յ�����Ӧ��*/
int ProcREQACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*��������Ϣ*/
int ProcFEBRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�������ݲ�ѯ����*/
int ProcQWINFO(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*����״̬��ѯ����*/
int ProcQWSTAT(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�������ݲ�ѯ�����Ϣ*/
int ProcWDTRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*��ѯ���������Ϣ*/
int ProcWITRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}
