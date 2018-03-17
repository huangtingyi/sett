/*todo:
	OnTimeOutʱ�Ƿ���Ҫ�ж����ʱ��
	�ж�ָ��ɹ�ʧ�ܺ��Ƿ���Ҫ��ջ��壿
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>
#include <wwfile.h>
#include <wwtiny.h>

#include <cmdsupp.h>
#include <intfcmd.h>
#include <wwnet.h>
/*
���ڵĳɹ���Ϣֻ�����֣��ֱ����£�
S0000:CDMA HLR SERVER CONTACTED
S0001:Operate Success
S0002:Login Success
S0003:Exited
*/
#define SCONNECT "S0000"
#define SLOGINED "S0002"
#define SOPERATESUCC "S0001"
#define SEXITED  "S0003"

/*�Ƿ��Ѿ���½*/
int iLogined= 0;
static struct IAgentStruct *pAgent=NULL;

int OnConnect(struct ClientSockStruct *Socket)
{
	puts("OnConnect");
	
	/*��½*/
	if(!iLogined){
		char sDateTime[15];
		char sLoginStr[256];
		char sLengthStr[256];
		
		memset(sLoginStr,0,sizeof(sLoginStr));
		memset(sLengthStr,0,sizeof(sLengthStr));
		
		sprintf(sLoginStr,"ADMIN=%s\tPASSWD=%s",pAgent->sUserName,pAgent->sPassword);
		
		sprintf(sLengthStr,"SLOGIN%04d",strlen(sLoginStr));
		strcat(sLengthStr,sLoginStr);
		strcpy(sLoginStr,"MHF00000000111");
		GetHostTime(sDateTime);
		strcat(sLoginStr,sDateTime);
		strcat(sLoginStr,"000000000000000199");
		strcat(sLoginStr,sLengthStr);
		
		SockSendBuf(Socket->iSockFd,sLoginStr,-1);
	}
	
	return 0;
}
int OnTimeOut(struct ClientSockStruct *Serv)
{
	puts("OnTimeOut");
	return 0;
}
int OnError(struct ClientSockStruct *Serv)
{
	puts("OnError");
	return 0;
}
int OnDisconnect(struct ClientSockStruct *Serv)
{
	puts("OnDisconnect");
	return 0;
}

int ConvertResult(char *p,char sErrorDesc[])
{
      int iLen;
      int iCount= 0;
      int pEof= false;
      char * pSorce;
      char tmpstr1[1024];
      char *tmpstr;
      
      memset(tmpstr1,0,1024);
      strcpy(tmpstr1,p);
      strcat(tmpstr1,"MNF");
      tmpstr= tmpstr1;

      while(strcmp(tmpstr,"MNF")!=0){
        pSorce= strstr(tmpstr,"=");
        if(pSorce!=NULL){
          iLen= pSorce - tmpstr;
          strncat(sErrorDesc,tmpstr,iLen);
          strcat(sErrorDesc,"+");

          tmpstr= tmpstr + iLen+1;
          pSorce= strstr(tmpstr,"\t");
          if(pSorce==NULL){
            pSorce= strstr(tmpstr,"MNF");
            pEof= true;

            iLen= pSorce - tmpstr;
            strncat(sErrorDesc,tmpstr,iLen);
          }
          else{
            iLen= pSorce - tmpstr;
            strncat(sErrorDesc,tmpstr,iLen);
            strcat(sErrorDesc,"\'");
          }

          iCount++;
          if(pEof){
            tmpstr= tmpstr + iLen;
            tmpstr[3]= '\0';
          }
          else{
            tmpstr= tmpstr + iLen + 1;
          }
        }
        else
        {
          iCount= -1;
          break;
        }
      }
      return iCount;
}

int ParseResult(const char sResultStr[],int *iRetCode,char sErrorDesc[])
{
	char *p,*tmpstr,sRetCode[4];
	
	*iRetCode= 300;
	sErrorDesc[0]= '\0';
	
	/*if(strstr(sResultStr,"MHF")==NULL) { *iRetCode= 300; }*/
	
	/*RTCODE=0XXX ȡ����XXX��λ �������*/
	if((p= strstr(sResultStr,"RTCODE="))!= NULL){
		
		p += strlen("RTCODE=0");
		strncpy(sRetCode,p,3); sRetCode[3]='\0';
		*iRetCode=  atoi(sRetCode);
	}
	
	if(strstr(sResultStr,"USIRSP")!=NULL){
		*iRetCode= 000;
		tmpstr= strstr(sResultStr,"USIRSP");
		tmpstr= tmpstr + 10;
		if(ConvertResult(tmpstr,sErrorDesc)<0){
			*iRetCode= 300;
		}
		
		return *iRetCode;
	}
	else if(strstr(sResultStr,"IMSRSP")!=NULL){
		*iRetCode= 000;
		tmpstr= strstr(sResultStr,"IMSRSP");
		tmpstr= tmpstr + 10;
		if(ConvertResult(tmpstr,sErrorDesc)<0){
			*iRetCode= 300;
		}
		
		return *iRetCode;
	}
    		
	/*RTDESC=XXXXX��ȡ��������XXXXX ��������*/
	if((p=strstr(sResultStr,"RTDESC="))!= NULL){
		
		p += strlen("RTDESC=");
		strcpy(sErrorDesc,p);
	}
	
	return *iRetCode;
	
}

void NorTel1XDataAvailble(struct ClientSockStruct *Serv,char sData[])
{
	int iRetCode;
	char sTemp[257],sErrorDesc[1024];

	/*���ջ�����*/
	if(strlen(CmdResult.sRecvBuf)+strlen(sData)>8192){
		strcpy(Intf.sState,COMMAND_STATE_ERR);
		ProcFailureCmd("���ջ�����");
		return;
	}	
	
	strcat(CmdResult.sRecvBuf,sData);
	/*�����Ƿ�����*/
        if((strstr(CmdResult.sRecvBuf,"RTCODE=")!=NULL)
        	&&(strstr(CmdResult.sRecvBuf,"USIRSP")!=NULL)
        	&&(strstr(CmdResult.sRecvBuf,"IMSRSP")!=NULL))
		return;
	
	/*��½*/
	if(iLogined==false){		
		if(strstr(CmdResult.sRecvBuf,"RTCODE=0000")!=NULL){			
			iLogined= true;
			ResetRecvBufAndResult();
			return;
		}
		else if(strstr(CmdResult.sRecvBuf,"RTCODE=0106")!=NULL){
			puts("�Ƿ���ϵͳ�û�.");
			return;
		}
		else if(strstr(CmdResult.sRecvBuf,"RTCODE=0107")!=NULL){
			puts("ϵͳ�û������.");
			return;
		}		
	}
	
	/*�Ѿ���½��.....*/
	
        if(strstr(CmdResult.sRecvBuf,"RTCODE=0103")!=0){
        	iLogined= false;
        	puts("��δ��¼.");
        }	
	
	
	/*�������*/
	ParseResult(CmdResult.sRecvBuf,&iRetCode,sErrorDesc);
	CmdResult.sCmdState[CmdResult.iCurCmd]=iRetCode;
	strcpy(CmdResult.asCmdMsg[CmdResult.iCurCmd],sErrorDesc);	
	
	
	ResetRecvBufAndResult();
	
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
	S*/
	AnalizeCmdResult();
	ProcCmdEnd();
	ResetRecvBufAndResult();
	
	return;

}

int OnDataRecv(struct ClientSockStruct *Serv,char sData[],int iLen)
{
	NorTel1XDataAvailble(Serv,sData);
	puts(sData);
	return 0;
}

int OnProcCmd(struct ClientSockStruct *Serv)
{
	puts("onProcCmd");	
	GetShmCmdSend(Serv->iSockFd);
	return 0;
}

int main(int argc,char *argv[])
{ 
	int iSwitchID;
	struct ClientSockStruct Serv;
	
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
/*�û�õĲ�����ʼ��InitClientSocket���ƽṹ*/
	InitClientSocket(&Serv,pAgent->sIp,pAgent->iPort,30);
/*���ô�������ú���*/	
	Serv.OnConnect=	OnConnect;
	Serv.OnTimeOut=	OnTimeOut;
	Serv.OnError=		OnError;
	Serv.ProcCmd=	OnProcCmd;
	Serv.OnDataRecv= 	OnDataRecv;
	Serv.OnDisconnect= 	OnDisconnect;

	ClientSockProcMain(&Serv);
	
	return 0;
}
