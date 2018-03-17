#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>
#include <wwfile.h>
#include <wwnet.h>

#include <cmdsupp.h>
#include <intfcmd.h>
#include <wwtelnet.h>

/*****************BELL��������ִ��Ϣ**************/
#define bLoginFailSign1     "INVALID PASSWORD"		/*��Ч����*/
#define bLoginFailSign2     "WRONG USERID"		/*��Ч�û�*/
#define bLoginFailSign3     "LOCKED USER"		/*�û�����*/
#define bLoginFailSign4     "ALREADY LOGGED ON"		/*�û��ѵ�¼*/
#define bLoginSuccSign      "<"				/*��¼�ɹ���ʾ*/
#define bEnterUserSign      "USERID <"			/*�����û�����ʾ*/
#define bEnterPwdSign       "PASSWORD <"		/*����������ʾ*/
#define bHLRCancelSign      "CANCELLED !"		/*����ȡ��*/
#define bHLRTerminatedSign  "DIALOG TERMINATED !"	/*�����ж�*/
#define bReLoginSign        "SEMANTIC ERROR CODE = 0020"/*�ظ���¼��*/
/*������ҵ�񲿷�*/
#define bFailureSign        "NOT SUCCESSFUL"		/*����ɹ�*/
#define bCmdErrorSign       "COMMAND ERROR !"		/*�������*/
#define bUserExistSign      "Tuple found."	
#define bIMSIExistSign      "MIN ALREADY EXISTS"
#define bPICExistSign       "The PIC is already datafilled"
#define bESNExistSign       "The ESN is already datafilled"
#define bNotFindDNSign      "MSIN DOES NOT EXIST IN SUBSCRIBER DATABASE"
#define bNotFindIMSISign    "MSIN DOES NOT EXIST"
#define bNotFindESNSign     "ESN not found."
#define bNotFindPICSign     "PIC not found."
#define bDuplicatedSign     "Option Duplicated."
#define bNoOptionSign1      "SERVICE NOT PRIVATELY PROVIDED, DELETE NOT ALLOWED"
#define bNoOptionSign2      "OLD SN-BSV INCONSISTENT"
#define bNoOptionSign3      "SUPPLEMENTARY SERVICES INCONSISTENT"
#define bDelUserSign        "DELETE-MS"
#define bCosNotExist	    "ASSIGNED COS DOES NOT EXIST"
#define bCmdEndSign         "LAST REPORT"		/*��ִ����*/
/*********************************************************/

void OnLogin(struct TelnetStruct *Serv,char sData[])
{
	puts("OnLogin");
}
void OnTimeOut(struct TelnetStruct *Serv)
{
	puts("OnTimeOut");
}
void OnError(struct TelnetStruct *Serv,char sMsg[],int iErrNo)
{
	puts("OnError");
	puts(sMsg);
}
void OnDisconnect(struct TelnetStruct *Serv)
{
	puts("OnDisconnect");
}
void BellDataAvailble(struct TelnetStruct *Serv,char sData[])
{	
	char *pc,sTemp[257];

	if(Serv->iLogined==false){
		if(strstr(sData,"\"SEND IP\" COMMAND.")!=NULL){
			SockSendBuf(Serv->iSockFd,"\0x03",-1);
		}
		/*��ջ�����*/
		ResetRecvBufAndResult();
		return;
	}	
/*CANCEL,TERMINAL�ͽ����帴λ����telnet�Ͽ���������*/
	if(strstr(sData,bHLRCancelSign)!=NULL||
		strstr(sData,bHLRTerminatedSign)!=NULL){
		/*��ջ�����*/
		ResetRecvBufAndResult();
		Serv->iLogined=false;
		return;
	}	
/*�������û�н���,�����ݼӵ�CmdResult.sRecvBuf������*/
	if(strlen(CmdResult.sRecvBuf)+strlen(sData)>8192){
		strcpy(Intf.sState,COMMAND_STATE_ERR);
		ProcFailureCmd("���ջ�����");
		return;
	}
/*�ж��Ƿ��ִ���������û�н��������ݼ��뻺��*/
	if((pc=strchr(sData,0x03))==NULL){
		strcat(CmdResult.sRecvBuf,sData);
		return;	
	
	}

	if((strstr(CmdResult.sRecvBuf,"SUCCESSFUL")!=NULL||
		strstr(CmdResult.sRecvBuf,bNotFindDNSign)!=NULL)&&
		strcmp(Intf.sState,COMMAND_STATE_WAIT)!=0){
		/*��ջ�����*/
		ResetRecvBufAndResult();
		return;
	}
	/*����ǲ�ѯ�����*/
	if(strstr(CmdResult.sRecvBuf,"DISPLAY-MS-DATA")!=NULL){
		/*��ջ�����*/
		ResetRecvBufAndResult();
		return;
	}
	if(strstr(CmdResult.sRecvBuf,bCmdErrorSign)!=NULL){
/*����Ǵ����û�*/
		if(strcmp(Intf.sCmdType,"CRUSER")==0&&
			strstr(sData,bDelUserSign)!=NULL){
	
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
			strcpy(CmdResult.asCmdMsg[CmdResult.iCurCmd],"CRUSERɾ������ʧ��");
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_SUC;
			
		}
		else{
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_ERR;
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ������ʧ��",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_CREATE_ERR;
		}
	}
	else if(strstr(CmdResult.sRecvBuf,bFailureSign)!=NULL){

		CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_OTHER_ERR;
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_ERR;
		if(strstr(CmdResult.sRecvBuf,bUserExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ���û��Ѵ���",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_MDN_EXIST;
			
		}
		else if(strstr(CmdResult.sRecvBuf,bIMSIExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��IMSI�Ѵ���",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_IMSI_EXIST;
		}
		else if(strstr(CmdResult.sRecvBuf,bPICExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��PIC�Ѵ���",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_PIC_EXIST;
		}
		else if(strstr(CmdResult.sRecvBuf,bESNExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��ESN�Ѵ���",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_ESN_EXIST;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindDNSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ���û�������",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_MDN_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindIMSISign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��IMSI������",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_IMSI_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindESNSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��ESN������",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_ESN_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindPICSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��PIC������",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_PIC_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bDuplicatedSign)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ���ظ�ѡ��",
				Intf.sCmdType);
		else if(strstr(CmdResult.sRecvBuf,bNoOptionSign1)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��ɾ�������ڵ�ҵ��",
				Intf.sCmdType);
		else if(strstr(CmdResult.sRecvBuf,bNoOptionSign2)!=NULL||
			strstr(CmdResult.sRecvBuf,bNoOptionSign3)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��ҵ�񲻴���",
				Intf.sCmdType);
		else if(strstr(CmdResult.sRecvBuf,bCosNotExist)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ��COSҵ�񲻴���",
				Intf.sCmdType);
		else{
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ�����ʧ��",
				Intf.sCmdType);
		}
	}
	else{
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_SUC;
		sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ������ɹ�",
				Intf.sCmdType);
	}
/*������ָ���Ƶ���һ������*/
	CmdResult.iCurCmd++;
/*�������û�н����ͽ���һ�������ȥ*/
	if(CmdResult.iCurCmd<CmdResult.iCmdCnt){
		GetCmd(&Intf,CmdResult.iCurCmd,sTemp);
		SockSendBuf(Serv->iSockFd,sTemp,strlen(sTemp));
		return;
	}
/*��������������Ѿ�������ˣ�
1.�ж������ִ�н����
2.���ȴ������е������͵�ִ���������
3.�����ջ����ϵͳ���Ʊ�����λ
*/
	AnalizeCmdResult();
	ProcCmdEnd();
	ResetRecvBufAndResult();
}
void OnDataRecv(struct TelnetStruct *Serv,char sData[])
{
	BellDataAvailble(Serv,sData);
	puts(sData);
}

void OnProcCmd(struct TelnetStruct *Serv)
{
	puts("onProcCmd");	
	GetShmCmdSend(Serv->iSockFd);
}
int main(int argc,char *argv[])
{ 
	int iSwitchID;
	struct TelnetStruct Serv;
	struct IAgentStruct *pAgent=NULL;
	
	if(argc!=2){
		printf("Usage %s switchid.\n",argv[0]);
		return -1;
	}
	Intf.iSwitchID=iSwitchID=atoi(argv[1]);
/*���ӹ����ڴ�*/
	if(ConnectCmdShmAndInitMem()<0){
		printf("���ӹ����ڴ�ʧ��.\n");
		return -1;
	}
/*������SwitchID�ĺϷ���*/	
	if((pAgent=GetShmAgent(iSwitchID))==NULL){
		printf("SwitchID=%d�ڹ����ڴ��в�����.\n",iSwitchID);
		return -1;
	}
/*�û�õĲ�����ʼ��Telnet���ƽṹ*/
	TelnetInitial(&Serv,pAgent->sIp,pAgent->iPort,
		pAgent->sUserName,pAgent->sPassword,
		"login","assword","Welcome");
/*���ô�������ú���*/	
	Serv.OnLogined=	OnLogin;
	Serv.OnTimeOut=	OnTimeOut;
	Serv.OnError=		OnError;
	Serv.ProcCmd=	OnProcCmd;
	Serv.OnDataRecv= 	OnDataRecv;
	Serv.OnDisconnect= 	OnDisconnect;

	TelnetProcMain(&Serv);
	
	return 0;
}
