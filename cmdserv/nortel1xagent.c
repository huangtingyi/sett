/*todo:
	OnTimeOut时是否需要判断命令超时。
	判断指令成功失败后是否需要清空缓冲？
	
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
现在的成功消息只有四种，分别如下：
S0000:CDMA HLR SERVER CONTACTED
S0001:Operate Success
S0002:Login Success
S0003:Exited
*/
#define SCONNECT "S0000"
#define SLOGINED "S0002"
#define SOPERATESUCC "S0001"
#define SEXITED  "S0003"

/*是否已经登陆*/
int iLogined= 0;
static struct IAgentStruct *pAgent=NULL;

int OnConnect(struct ClientSockStruct *Socket)
{
	puts("OnConnect");
	
	/*登陆*/
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
	
	/*RTCODE=0XXX 取其中XXX三位 错误代码*/
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
    		
	/*RTDESC=XXXXX，取不定长串XXXXX 错误描述*/
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

	/*接收缓冲满*/
	if(strlen(CmdResult.sRecvBuf)+strlen(sData)>8192){
		strcpy(Intf.sState,COMMAND_STATE_ERR);
		ProcFailureCmd("接收缓冲满");
		return;
	}	
	
	strcat(CmdResult.sRecvBuf,sData);
	/*命令是否完整*/
        if((strstr(CmdResult.sRecvBuf,"RTCODE=")!=NULL)
        	&&(strstr(CmdResult.sRecvBuf,"USIRSP")!=NULL)
        	&&(strstr(CmdResult.sRecvBuf,"IMSRSP")!=NULL))
		return;
	
	/*登陆*/
	if(iLogined==false){		
		if(strstr(CmdResult.sRecvBuf,"RTCODE=0000")!=NULL){			
			iLogined= true;
			ResetRecvBufAndResult();
			return;
		}
		else if(strstr(CmdResult.sRecvBuf,"RTCODE=0106")!=NULL){
			puts("非法的系统用户.");
			return;
		}
		else if(strstr(CmdResult.sRecvBuf,"RTCODE=0107")!=NULL){
			puts("系统用户口令错.");
			return;
		}		
	}
	
	/*已经登陆的.....*/
	
        if(strstr(CmdResult.sRecvBuf,"RTCODE=0103")!=0){
        	iLogined= false;
        	puts("尚未登录.");
        }	
	
	
	/*解析结果*/
	ParseResult(CmdResult.sRecvBuf,&iRetCode,sErrorDesc);
	CmdResult.sCmdState[CmdResult.iCurCmd]=iRetCode;
	strcpy(CmdResult.asCmdMsg[CmdResult.iCurCmd],sErrorDesc);	
	
	
	ResetRecvBufAndResult();
	
	/*将命令指针移到下一个命令*/
	CmdResult.iCurCmd++;
	/*如果命令没有结束就将下一个命令发过去*/
	if(CmdResult.iCurCmd<CmdResult.iCmdCnt){
		
		GetCmd(&Intf,CmdResult.iCurCmd,sTemp);
		SockSendBuf(Serv->iSockFd,sTemp,strlen(sTemp));
		return;
	}
	
	/*如果到这里命令已经都完毕了，
	1.判定命令的执行结果；
	2.将等待链表中的命令送到执行完毕链表；
	3.将接收缓冲等系统控制变量复位
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
/*连接共享内存*/
	if(ConnectCmdShmAndInitMem()<0){
		printf("连接共享内存失败.\n");
		return -1;
	}
/*检查参数SwitchID的合法性*/	
	if((pAgent=GetShmAgent(iSwitchID))==NULL){
		printf("SwitchID=%d在共享内存中不存在.\n",iSwitchID);
		return -1;
	}
/*用获得的参数初始化InitClientSocket控制结构*/
	InitClientSocket(&Serv,pAgent->sIp,pAgent->iPort,30);
/*设置处理的外置函数*/	
	Serv.OnConnect=	OnConnect;
	Serv.OnTimeOut=	OnTimeOut;
	Serv.OnError=		OnError;
	Serv.ProcCmd=	OnProcCmd;
	Serv.OnDataRecv= 	OnDataRecv;
	Serv.OnDisconnect= 	OnDisconnect;

	ClientSockProcMain(&Serv);
	
	return 0;
}
