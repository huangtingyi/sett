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

#include <c1xadapt.h>

#define CONNECT_TIME_OVER 120
char sgLastRespondTime[15];
int  igConnectFlag=false;


int  AnswerCdma1XIntf(int iSockFd,char sCmd[],char sCmdType[],
	char sReturn[])
{
	static char	sTemp[CDMA_BACK_BUF];
	struct Cdma1XCmdHeadStruct *p;

	p=(struct Cdma1XCmdHeadStruct*)sTemp;
	
	memcpy(sTemp,sCmd,sizeof(struct Cdma1XCmdHeadStruct));
	
	sTemp[sizeof(struct CdmaCmdHeadStruct)]=0;
	
	strcat(sTemp,sReturn);
	strcat(sTemp,"MNF\n");
	
	strncpy(p->sCmdType,sCmdType,strlen(sCmdType));
	
	return SockSendData(iSockFd,sTemp,strlen(sTemp));
}

int  AnswerCdma1XMsg(int iSockFd,char sCmd[],char sCmdType[],
        char sMsg[],int iFlag)
{
        char    sTemp[8192];

	/*�Է�������������ͽ��м��,ֻ����ָ����������*/
        if(strcmp(sCmdType,"FEBRSP")!=0) return -1;

        strcpy(sTemp,"");
        strcat(sTemp,"RTCODE+300");
        strcat(sTemp,"'RTDESC+");
        strcat(sTemp,sMsg);

        return AnswerCdma1XIntf(iSockFd,sCmd,sCmdType,sTemp);
}


int Check1XPack(char sInput[],int l,char sErrMsg[])
{
	int 	iBodyLen,iWapLen;
	char	sTemp[20];
	struct	Cdma1XCmdHeadStruct *pHead;
	
	strcpy(sErrMsg,"");
	pHead=(struct Cdma1XCmdHeadStruct *)sInput;
	strncpy(sTemp,pHead->sBodyLen,4);sTemp[4]=0;
	iBodyLen=atoi(sTemp);
	
	iWapLen=sizeof(struct Cdma1XCmdHeadStruct);
	
	if(iBodyLen+iWapLen!=l){
		sprintf(sErrMsg,"�����Ƿ�:����ӦΪ%d,ʵ�ʰ�����Ϊ%d.\n",
			iBodyLen+iWapLen,l);
		return -1;
	}

	if(strncmp(pHead->sHeadIdentify,"MHF",3)!=0){
		sprintf(sErrMsg,"��ͷ�Ƿ�.\n");
		return -1;
	}
	
	return iBodyLen;
	
}

int TranslateCmd(int iSockFd,char sServiceType[],char sInput[],
	struct IntfCmdStruct *p)
{
	int iBodyLen,iWapLen;
	char	sErrMsg[256],sInfoLine[257],sTemp[10];
	struct InfoItemStruct *pInfo=NULL;
	struct	Cdma1XCmdHeadStruct *pHead;
	
	iWapLen=sizeof(struct Cdma1XCmdHeadStruct);
	
	if((iBodyLen=Check1XPack(sInput,strlen(sInput),sErrMsg))<0){

		AnswerCdma1XMsg(iSockFd,sInput,"FEBRSP",sErrMsg,false);
		
		printf("%s",sErrMsg);
		return -1;
	}
	
	strncpy(sInfoLine,sInput+sizeof(struct Cdma1XCmdHeadStruct),iBodyLen);
	sInfoLine[iBodyLen]=0;
	
	if((pInfo=GenInfoItemList(sInfoLine,'\'','+'))==NULL){
		
		AnswerCdma1XMsg(iSockFd,sInput,"FEBRSP",
			"������Ϣ�б����",false);
		printf("������Ϣ�б����.\n");
		return -1;
	}
	pHead=(struct	Cdma1XCmdHeadStruct *)sInput;
	
	bzero((void*)p,sizeof(struct IntfCmdStruct));
	
	strncpy(p->sSerialNbr,pHead->sSerialNbr,16);p->sSerialNbr[16]=0;
	p->iStaffID=0;
	
	/*
	GetInfoItemValue(pInfo,"IMSI",p->sImsi);
	GetInfoItemValue(pInfo,"DN",p->sMsisdn);
	GetInfoItemValue(pInfo,"ESN",p->sEsn);
	*/
	
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

void AddField(char sServType[],char sName[],char sDesc[],
	char cType,int iLen,struct CmdFieldStruct *p)
{
	strcpy(p->sServType,sServType);
	strcpy(p->sName,sName);
	strcpy(p->sDesc,sDesc);
	if(cType=='n'||cType=='N')
		p->cType='N';
	else
		p->cType='C';
	p->iLen=iLen ;
}                                       

int CheckCdma1XREQService(struct IntfCmdStruct *p,char sErrMsg[256])
{
	char sCmdType[7],sTemp[257];
	struct InfoItemStruct *pInfo=NULL;
	struct CmdFieldStruct fields[100];
	int i,iPos= 0;
	
	strcpy(sErrMsg,"");
	strcpy(sCmdType,p->sCmdType);
	memset(fields,0,sizeof(struct CmdFieldStruct)*100);
		
	if((pInfo=GenInfoItemList(p->sStdInfoLine,'=',','))==NULL){
		
		strcpy(sErrMsg,"������Ϣ�б����");
		return -1;
	}

	if(strcmp(sCmdType,"SLOGIN")==0){	
		AddField("SLOGIN","ADMIN","�û���",'C',64,&fields[iPos++]);
		AddField("SLOGIN","PASSWD","����",'C',64,&fields[iPos++]);
	}
		
	if(strcmp(sCmdType,"CRTNAI")==0){
		AddField("CRTNAI","NAIUSERNAME","NAI�û���",'C',32,&fields[iPos++]);
		AddField("CRTNAI","PASSWORD","����",'C',10,&fields[iPos++]);
		AddField("CRTNAI","NAIGROUPID","NAIҵ�����ʶ",'N',10,&fields[iPos++]);
		AddField("CRTNAI","SERVICETYPE","�����ʶ",'N',5,&fields[iPos++]);
		AddField("CRTNAI","NAIBUREAUID","NAI�����ر�ʶ",'N',3,&fields[iPos++]);
		AddField("CRTNAI","SERVICESTATUS","NAI�û�������״̬",'N',2,&fields[iPos++]);
		AddField("CRTNAI","IMSIJUDGEID","IMSI��Ȩ��ʶ",'C',1,&fields[iPos++]);
		AddField("CRTNAI","NAITYPE","NAI���",'C',1,&fields[iPos++]);
		AddField("CRTNAI","IMSI","IMSI",'C',15,&fields[iPos++]);
		AddField("CRTNAI","MDN","MDN",'C',20,&fields[iPos++]);
	}
	
	if(strcmp(sCmdType,"QUINFO")==0
		||strcmp(sCmdType,"CHGNAI")==0
		||strcmp(sCmdType,"DLTNAI")==0){		
		AddField("QUINFO","NAIUSERNAME","NAI�û���",'C',32,&fields[iPos++]);
	}
	
	if(strcmp(sCmdType,"CHGPWD")==0){
		AddField("CHGPWD","NAIUSERNAME","NAI�û���",'C',32,&fields[iPos++]);
		AddField("CHGPWD","PASSWORD","����",'C',10,&fields[iPos++]);
		AddField("CHGPWD","NEWPASSWORD","�û��¿���",'C',10,&fields[iPos++]);
	}
	
	if(strcmp(sCmdType,"ADDSRV")==0){
		AddField("ADDSRV","NAIUSERNAME","NAI�û���",'C',32,&fields[iPos++]);
		AddField("ADDSRV","SERVICETYPE","�����ӵķ����ʶ",'N',5,&fields[iPos++]);
	}	
	
	if(strcmp(sCmdType,"DLTSRV")==0){
		AddField("DLTSRV","NAIUSERNAME","NAI�û���",'C',32,&fields[iPos++]);
		AddField("DLTSRV","SERVICETYPE","�����ķ����ʶ",'N',5,&fields[iPos++]);
	}

	if(strcmp(sCmdType,"CRIMSI")==0){
		AddField("CRIMSI","IMSI","IMSI",'C',15,&fields[iPos++]);
		AddField("CRIMSI","MDN","MDN",'C',20,&fields[iPos++]);
		AddField("CRIMSI","STATUS","״̬",'C',1,&fields[iPos++]);
		AddField("CRIMSI","USERTYPE","�û�����",'C',2,&fields[iPos++]);

	}
	
	if(strcmp(sCmdType,"CHIMSI")==0){
		AddField("CHIMSI","MDN","MDN",'C',20,&fields[iPos++]);
		AddField("CHIMSI","STATUS","״̬",'C',1,&fields[iPos++]);
		AddField("CHIMSI","USERTYPE","�û�����",'C',2,&fields[iPos++]);
	}									

	if(strcmp(sCmdType,"CHGTNL")==0){
		AddField("CHGTNL","NEWIMSI","IMSI",'C',15,&fields[iPos++]);
		AddField("CHGTNL","MDN","MDN",'C',20,&fields[iPos++]);
		AddField("CHGTNL","STATUS","״̬",'C',1,&fields[iPos++]);
	}	
	
	if(strcmp(sCmdType,"CHGMDN")==0){
		AddField("CHGMDN","IMSI","IMSI",'C',15,&fields[iPos++]);
		AddField("CHGMDN","NEWMDN","MDN",'C',20,&fields[iPos++]);
		AddField("CHGMDN","STATUS","״̬",'C',1,&fields[iPos++]);
	}	
	
	if(strcmp(sCmdType,"PREQUT")==0){
		AddField("PREQUT","MDN","MDN",'C',20,&fields[iPos++]);
		AddField("PREQUT","STATUS","״̬",'C',1,&fields[iPos++]);
	}
		
	if(strcmp(sCmdType,"FRMQUT")==0){
		AddField("FRMQUT","MDN","MDN",'C',20,&fields[iPos++]);
	}
	
	if(strcmp(sCmdType,"CHGDMN")==0){
		AddField("CHGDMN","STATUS","״̬",'C',1,&fields[iPos++]);
	}
	
	if(strcmp(sCmdType,"QUIMSI")==0||strcmp(sCmdType,"DLIMSI")==0){
		char sTmpVal[64];
		/*����������һ*/
		GetInfoItemValue(pInfo,"IMSI",sTemp); 
		GetInfoItemValue(pInfo,"MDN",sTmpVal);                
		if(strlen(sTemp)==0&&strlen(sTmpVal)==0)                                  
			sprintf(sErrMsg,"%sҵ��,û��IMSI��MDN��Ϣ��Ԫ",sCmdType);
	}
	
	/*todo:����ȱ���ֶ�,�ֶ���𣬳���*/
	for(i=0; i<iPos; i++){
		
		char *pName;
		if(strcmp(fields[i].sServType,sCmdType)!=0){
			continue;
		}
		
		pName=fields[i].sName;
		GetInfoItemValue(pInfo,pName,sTemp);
		
		/*���ڷ��ؽ������60λ���Ƿ���ȱ�ٶ���ֶΣ�*/
		if(strlen(sTemp)==0){
			sprintf(sErrMsg,"%sҵ��,û��%s��Ϣ��Ԫ",sCmdType,pName);
			break;
		}
		
		if(strlen(sTemp)==0){
			sprintf(sErrMsg,"%sҵ��,%s��Ϣ��Ԫ���ȴ���!",sCmdType,pName);
			break;
		}
	}
	
	
	DestroyList((LIST*)pInfo);
	
	if(strlen(sErrMsg)!=0) return -1;
	
	return 0;
}
int ProcREQ(int iSockFd,struct IntfCmdStruct *p)
{
	int iRetryTimes=0;
	char	sErrMsg[257];
	
	
	GetHostTime(sgLastRespondTime);
	
/*������ݿ�Ͽ�������*/
	if(igConnectFlag==false){
		if(IniConnect("dataconnstr")<0){
			printf("�������ݿ����.\n");
			return -1;
		}
		igConnectFlag=true;
	}
/*��鹤��ҵ������Ϸ���*/
	if(CheckCdma1XREQService(p,sErrMsg)<0){
		AnswerCdma1XMsg(iSockFd,p->sOrderLine,"FEBRSP",
			sErrMsg,false);
		WriteAlertMsg("����ָ��ҵ�����ָ��%s,������Ϣ%s",
			p->sOrderLine,sErrMsg);
		return -1;
	}
/*���������*/
retry_point:		
	if(SDInsertStructToIntfCmd(p,"INTF_CMD")<0){
		if(iRetryTimes>=1){

			AnswerCdma1XMsg(iSockFd,p->sOrderLine,"FEBRSP",
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

	AnswerCdma1XMsg(iSockFd,p->sOrderLine,"FEBRSP","��Ϣ������ȷ",true);
	
	return 0;
}

int on_client_write(struct TcpClientStruct *ptHead)
{
	int n;
	char	sServiceType[6],sInput[1024];
	struct IntfCmdStruct Temp;
	
	
	strcpy(sServiceType,"MSC");
	if((n=ReceiveSockBuf(ptHead->iSockFd,sInput))==0) return 0;
/*����ReceiveSockBuf��յĽ�����*/
	strcat(sInput,"\n");
	

/*���ת������д��־�����Ը�����*/
	if(TranslateCmd(ptHead->iSockFd,sServiceType,sInput,&Temp)<0){
		AnswerCdma1XMsg(ptHead->iSockFd,sInput,"FEBRSP",
			"���յ��Ƿ�����",false);
		WriteAlertMsg("���յ��Ƿ�����\n%s",sInput);
		return n;
	}

	/*��������*/
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


