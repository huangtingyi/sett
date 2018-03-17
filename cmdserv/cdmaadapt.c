#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwcoding.h>
#include <list.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwnet.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <cmdsupp.h>
#include <intfcmd.h>

#include <expr.h>

#define CONNECT_TIME_OVER 120
char sgLastRespondTime[15];
int  igConnectFlag=false;


int TranslateCmd(int iSockFd,char sServiceType[],char sInput[],
	struct IntfCmdStruct *p)
{
	int iBodyLen,iWapLen;
	char	sErrMsg[256],sInfoLine[257],sTemp[10];
	struct InfoItemStruct *pInfo=NULL;
	struct	CdmaCmdHeadStruct *pHead;
	
	iWapLen=sizeof(struct CdmaCmdHeadStruct)+
		sizeof(struct CdmaCmdTailStruct);
	
	if((iBodyLen=CheckPack(sInput,strlen(sInput),sErrMsg))<0){

		AnswerCdmaMsg(iSockFd,sInput,"REQACK",sErrMsg,false);
		
		printf("%s",sErrMsg);
		return -1;
	}
	
	strncpy(sInfoLine,sInput+sizeof(struct CdmaCmdHeadStruct),iBodyLen);
	sInfoLine[iBodyLen]=0;
	
	if((pInfo=GenInfoItemList(sInfoLine,'\'','+'))==NULL){
		
		AnswerCdmaMsg(iSockFd,sInput,"REQACK",
			"������Ϣ�б����",false);
		printf("������Ϣ�б����.\n");
		return -1;
	}
	pHead=(struct	CdmaCmdHeadStruct *)sInput;
	
	bzero((void*)p,sizeof(struct IntfCmdStruct));
	
	strncpy(p->sSerialNbr,pHead->sSerialNbr,16);p->sSerialNbr[16]=0;
	p->iStaffID=0;
	
	GetInfoItemValue(pInfo,"IMSI",p->sImsi);
	GetInfoItemValue(pInfo,"DN",p->sMsisdn);
	GetInfoItemValue(pInfo,"ESN",p->sEsn);
	
	strcpy(p->sServiceType,sServiceType);
	strncpy(p->sCmdType,	pHead->sCmdType,6);p->sCmdType[6]=0;

	strncpy(sTemp,pHead->sPriority,2);sTemp[2]=0;
	p->iPriority=atoi(sTemp);
	
	strcpy(p->sOrderLine,sInput);


	GenInfoLine(pInfo,'=',',',p->sStdInfoLine);
	
	GetHostTime(p->sDealBeginTime);
	GetHostTime(p->sDealEndTime);
/*���ù���״̬Ϊ�¹���*/
	strcpy(p->sState,COMMAND_STATE_NEW);
	
	DestroyList((LIST*)pInfo);
	
	return 0;
}
/*������е�ʱ��̫������Ͽ����ݿ�*/
void on_client_time_out(struct TcpClientStruct *ptHead)
{
}
int ReceiveSockBuf(int iSockFd,char sInput[])
{
	int n=0,l,i;

	i=l=GetSockBufLen(iSockFd);

/*	printf("the l=%d.\n",l);*/

	while(l>0){	
		n=read(iSockFd,sInput+n,1024);
		l-=n;
		usleep(200);
	}
	sInput[i]=0;
	if(n<=0) return 0;
	return i;
}
int SendSockBuf(int iSockFd,char sInput[],int n)
{
	return write(iSockFd,sInput,n);
}
int GetCmdBody(char sSerialNbr[],char sCmd[])
{
	struct IntfCmdStruct Temp;
	struct IntfCmdStructIn TempIn;
	
	strcpy(sCmd,"");
	
	bzero((void*)&TempIn,sizeof(struct IntfCmdStructIn));
	
	strcpy(TempIn.sTableName,"INTF_CMD");
	sprintf(TempIn.sCondition,"WHERE SERIAL_NBR='%s'",sSerialNbr);
	
	if(EGetIntfCmdToStruct(&Temp,&TempIn)!=true) return false;
	
	strcpy(sCmd,Temp.sOrderLine);
	return true;
}
int CheckCdmaQWINFOService(struct IntfCmdStruct *p,
	char sCmd[257],char sErrMsg[257])
{
	char sTemp[257];
	struct InfoItemStruct *pInfo=NULL;
	
	if((pInfo=GenInfoItemList(p->sStdInfoLine,'=',','))==NULL){
		
		strcpy(sErrMsg,"������Ϣ�б����");
		return -1;
	}
	GetInfoItemValue(pInfo,"SNO",sTemp);
	if(strlen(sTemp)==0)
		sprintf(sErrMsg,"%sҵ��,û��SNO+��Ϣ��Ԫ",p->sCmdType);
	if(GetCmdBody(sTemp,sCmd)!=true)
		sprintf(sErrMsg,"%sҵ��,���ݿ���û������",p->sCmdType);
	
	DestroyList((LIST*)pInfo);
	
	return 0;
}
int ProcQWINFO(int iSockFd,struct IntfCmdStruct *p)
{
	
	char sCmd[257],sErrMsg[257];
	
	if(CheckCdmaQWINFOService(p,sCmd,sErrMsg)<0){
		AnswerCdmaIntf(iSockFd,p->sOrderLine,
			"WDTRSP","SNO+\'DN+\'IMSI+\'");
		WriteAlertMsg("%s",sErrMsg);
	}
	else
		AnswerCdmaIntf(iSockFd,p->sOrderLine,"WDTRSP",sCmd);
	
	return 0;
}
int GetQWSTATCondition(struct IntfCmdStruct *p,char sCondition[256])
{
	int i=0,k=0;
	char 	asConds[7][128],sCond[128],sTemp[256];
	
	struct InfoItemStruct *pInfo=NULL;
	
	if((pInfo=GenInfoItemList(p->sStdInfoLine,'=',','))==NULL) return -1;

	for(i=0;i<7;i++) strcpy(asConds[i],"");
	
	
	/*�����������*/
	GetInfoItemValue(pInfo,"LASTSNO",sTemp);
	if(strlen(sTemp)!=0){
		strcpy(sCond,"");
		if(strlen(sCond)!=0){strcpy(asConds[k],sCond);k++;}
	}
	
	/*ȡSNO����*/
	GetInfoItemValue(pInfo,"SNO",sTemp);
	if(strlen(sTemp)!=0){
		sprintf(sCond," SERIAL_NBR=\'%s\'",sTemp);
		if(strlen(sCond)!=0){strcpy(asConds[k],sCond);k++;}
	}
	
	/*ȡSTATUS����	0������ɹ���1��δ����2�����ڴ���3������ʧ��*/
	GetInfoItemValue(pInfo,"STATUS",sTemp);
	if(strlen(sTemp)!=0){
		switch(atoi(sTemp)){
		case 0:
			strcpy(sCond,"STATE=\'I0S\'");
		break;
		case 1:
			strcpy(sCond,"STATE=\'I0N\'");
		break;
		case 2:
			strcpy(sCond,"STATE=\'I0W\'");
		break;
		case 3:
			strcpy(sCond,"(STATE=\'I0E\' OR STATE=\'I0F\')");
		break;
		default:
			strcpy(sCond,"STATE=\'I0S\'");
		}
		if(strlen(sCond)!=0){strcpy(asConds[k],sCond);k++;}
	}
	GetInfoItemValue(pInfo,"WBGINTIME",sTemp);
	if(strlen(sTemp)!=0){
		sprintf(sCond,"to_char(DEAL_END_TIME,'yyyymmddhh24miss')>='%s'",sTemp);
		if(strlen(sCond)!=0){strcpy(asConds[k],sCond);k++;}
	}

	GetInfoItemValue(pInfo,"WENDTIME",sTemp);
	if(strlen(sTemp)!=0){
		sprintf(sCond,"to_char(DEAL_END_TIME,'yyyymmddhh24miss')<'%s'",sTemp);
		if(strlen(sCond)!=0){strcpy(asConds[k],sCond);k++;}
	}

	GetInfoItemValue(pInfo,"IMSI",sTemp);
	if(strlen(sTemp)!=0){
		sprintf(sCond,"IMSI='%s'",sTemp);
		if(strlen(sCond)!=0){strcpy(asConds[k],sCond);k++;}
	}

	GetInfoItemValue(pInfo,"ESN",sTemp);
	if(strlen(sTemp)!=0){
		sprintf(sCond,"ESN='%s'",sTemp);
		if(strlen(sCond)!=0){strcpy(asConds[k],sCond);k++;}
	}
	
	strcpy(sCondition,"");
	for(i=0;i<k;i++){
		if(i==0){
			strcat(sCondition," WHERE ");
			strcat(sCondition,asConds[i]);
		}
		else{
			strcat(sCondition," AND ");
			strcat(sCondition,asConds[i]);
		}
	}
	return 0;
}
int ProcQWSTAT(int iSockFd,struct IntfCmdStruct *p)
{
	int l=0,iCount=0,iStatus=0;
	char sCondition[256];
	static char sSendBuf[CDMA_BACK_BUF];/*���ͻ���*/
	
	struct IntfCmdStruct *ptHead=NULL;
	
	if(GetQWSTATCondition(p,sCondition)<0){
		AnswerCdmaIntf(iSockFd,p->sOrderLine,
			"WITRSP","RETNUM+000000|");
		WriteAlertMsg("��ȡ��ѯ��������");
		return -1;
	}
	
	if(InitIntfCmd(&ptHead,sCondition)<0){
		AnswerCdmaIntf(iSockFd,p->sOrderLine,
			"WITRSP","RETNUM+000000|");
		WriteAlertMsg("�����ݿ��ȡ���ݴ���");
		return -1;
	}
	if(iCount==0){
		AnswerCdmaIntf(iSockFd,p->sOrderLine,
			"WITRSP","RETNUM+000000|");
		return 0;
	}

	iCount=CountList((LIST*)ptHead);
	l+=sprintf(sSendBuf+l,"RETNUM+%06d|",iCount);

	while(ptHead!=NULL){

		if(strcmp(ptHead->sState,"I0S")==0) 	iStatus=0;
		else if(strcmp(ptHead->sState,"I0N")==0)iStatus=1;
		else if(strcmp(ptHead->sState,"I0W")==0)iStatus=2;
		else 					iStatus=3;
		
		
		l+=sprintf(sSendBuf+l,"IMSI+%s'DN+%s'STATUS+%d|",
			ptHead->sImsi,ptHead->sMsisdn,iStatus);
		
		if(l>=CDMA_BACK_BUF){
			AnswerCdmaIntf(iSockFd,p->sOrderLine,
				"WITRSP","RETNUM+000000|");
			WriteAlertMsg("��ȡ��ѯ����Խ��");
			return -1;
		}
		ptHead=ptHead->pNext;
	}
	AnswerCdmaIntf(iSockFd,p->sOrderLine,"WITRSP",sSendBuf);
	return 0;
}
int CheckCdmaREQService(struct IntfCmdStruct *p,char sErrMsg[256])
{
	char sCmdType[7],sTemp[257];
	struct InfoItemStruct *pInfo=NULL;
	
	strcpy(sErrMsg,"");
	strcpy(sCmdType,p->sCmdType);
	
	if((pInfo=GenInfoItemList(p->sStdInfoLine,'=',','))==NULL){
		
		strcpy(sErrMsg,"������Ϣ�б����");
		return -1;
	}
	
	if(strcmp(sCmdType,"CRUSER")==0||
		strcmp(sCmdType,"CHGSRV")==0||
		strcmp(sCmdType,"DLUSER")==0||
		strcmp(sCmdType,"CHIMSI")==0||
		strcmp(sCmdType,"CHGMDN")==0||
		strcmp(sCmdType,"CHGESN")==0||
		strcmp(sCmdType,"CHGPIC")==0){

		if(strlen(p->sImsi)==0)
			sprintf(sErrMsg,"%sҵ��,û��IMSI+��Ϣ��Ԫ",sCmdType);
		else if(strlen(p->sMsisdn)==0)
			sprintf(sErrMsg,"%sҵ��,û��DN+��Ϣ��Ԫ",sCmdType);
		else if(strlen(p->sEsn)==0)
			sprintf(sErrMsg,"%sҵ��,û��ESN+��Ϣ��Ԫ",sCmdType);
		
		GetInfoItemValue(pInfo,"PIC",sTemp);
		if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��PIC+��Ϣ��Ԫ",sCmdType);
		if(strcmp(sCmdType,"CHGMDN")==0){
			GetInfoItemValue(pInfo,"NEWDN",sTemp);
			if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��NEWDN+��Ϣ��Ԫ",sCmdType);
		}
		if(strcmp(sCmdType,"CHGIMSI")==0){
			GetInfoItemValue(pInfo,"NEWIMSI",sTemp);
			if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��NEWIMSI+��Ϣ��Ԫ",sCmdType);
		}
		if(strcmp(sCmdType,"CHGESN")==0){
			GetInfoItemValue(pInfo,"NEWESN",sTemp);
			if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��NEWESN+��Ϣ��Ԫ",sCmdType);
		
			GetInfoItemValue(pInfo,"AKEY",sTemp);
			if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��AKEY+��Ϣ��Ԫ",sCmdType);
		
			GetInfoItemValue(pInfo,"CHECKSUM",sTemp);
			if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��CHECKSUM+��Ϣ��Ԫ",sCmdType);
			
			GetInfoItemValue(pInfo,"KEYID",sTemp);
			if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��KEYID+��Ϣ��Ԫ",sCmdType);
		}
		if(strcmp(sCmdType,"CHGPIC")==0){
			GetInfoItemValue(pInfo,"NEWPIC",sTemp);
			if(strlen(sTemp)==0)
			sprintf(sErrMsg,"%sҵ��,û��NEWPIC+��Ϣ��Ԫ",sCmdType);
		}
		
	}
	else if(strcmp(sCmdType,"QUINFO")==0){
		if(strlen(p->sImsi)==0)
			sprintf(sErrMsg,"%sҵ��,û��IMSI+��Ϣ��Ԫ",sCmdType);
		else if(strlen(p->sMsisdn)==0)
			sprintf(sErrMsg,"%sҵ��,û��DN+��Ϣ��Ԫ",sCmdType);
	}
	else		sprintf(sErrMsg,"%s,��Ϣ���ʹ���",sCmdType);
	
	DestroyList((LIST*)pInfo);
	
	if(strlen(sErrMsg)!=0) return -1;
	
	return 0;
}
int ProcREQ(int iSockFd,struct IntfCmdStruct *p)
{
	int iRetryTimes=0;
	char	sErrMsg[257];
		
/*��鹤��ҵ������Ϸ���*/
	if(CheckCdmaREQService(p,sErrMsg)<0){
		AnswerCdmaMsg(iSockFd,p->sOrderLine,"REQACK",
			sErrMsg,false);
		WriteAlertMsg("����ָ��ҵ�����ָ��%s,������Ϣ%s",
			p->sOrderLine,sErrMsg);
		return -1;
	}
/*���������*/
retry_point:		
	if(SDInsertStructToIntfCmd(p,"INTF_CMD")<0){
		if(iRetryTimes>=1){

			AnswerCdmaMsg(iSockFd,p->sOrderLine,"REQACK",
				"�Ա�INTF_CMD������",false);
			
			WriteAlertMsg("������ָ��%s",p->sOrderLine);
			printf("�Ա�INTF_CMD������.\n");
			return -1;
		}
		iRetryTimes=iRetryTimes+1;
		
		DisconnectDatabase();
		if(IniConnect("dataconnstr")<0){
			printf("�������ݿ����.\n");
			return -1;
		}
		igConnectFlag=true;
		goto retry_point;
	}
	CommitWork();

/*֪ͨCMDSERVER��Ϣ�Ѿ�����,��������ݿ��ȡ����,
	�Ѿ�û���¼���Ҫ��Ӧ������Ϣ*/
	if(GetAdaptNotify()!=ADAPT_DATA_REACH)
		AdaptNotifyCmdServer(ADAPT_DATA_REACH);

	AnswerCdmaMsg(iSockFd,p->sOrderLine,"REQACK","��Ϣ������ȷ",true);
	
	return 0;
}
int on_client_write(struct TcpClientStruct *ptHead)
{
	int n;
	char	sServiceType[6],sInput[1024];
	struct IntfCmdStruct Temp;
	
/*������ݿ�Ͽ�������*/
	if(igConnectFlag==false){
		if(IniConnect("dataconnstr")<0){
			printf("�������ݿ����.\n");
			return -1;
		}
		igConnectFlag=true;
	}

	strcpy(sServiceType,"MSC");
	if((n=ReceiveSockBuf(ptHead->iSockFd,sInput))==0) return 0;
/*����ReceiveSockBuf��յĽ�����*/
	strcat(sInput,"\n");
	

/*���ת������д��־�����Ը�����*/
	if(TranslateCmd(ptHead->iSockFd,sServiceType,sInput,&Temp)<0){
		AnswerCdmaMsg(ptHead->iSockFd,sInput,"REQACK",
			"���յ��Ƿ�����",false);
		WriteAlertMsg("���յ��Ƿ�����\n%s",sInput);
		return n;
	}

	/*RSPACK��Ϣ��Result����ģ�����ֱ�Ӻ���*/
	if(strcmp(Temp.sCmdType,"RSPACK")==0) return n;
	
	if(strcmp(Temp.sCmdType,"QWINFO")==0)
		ProcQWINFO(ptHead->iSockFd,&Temp);
	else if(strcmp(Temp.sCmdType,"QWSTAT")==0)
		ProcQWSTAT(ptHead->iSockFd,&Temp);
	else 
		ProcREQ(ptHead->iSockFd,&Temp);
		
	return n;
}
int my_child_start()
{
	return 0;
}
int my_child_end()
{
	DisconnectDatabase();
	return 0;
}
void my_initial_client(struct TcpClientStruct *ptHead)
{
	ptHead->OnTimeOut	=on_client_time_out;
	ptHead->OnConnectAuth	=NULL;
	ptHead->OnDataRecv	=on_client_write;
	ptHead->OnConnect	=my_child_start;
	ptHead->OnDisconnect	=my_child_end;
}



int main()
{
	struct TcpServerStruct *pServer=NULL;
	
	pServer=CreateTcpServer(7788,false,5,3,NULL,my_initial_client);
	
	TcpServerRun(pServer);
	
	return 0;
}


