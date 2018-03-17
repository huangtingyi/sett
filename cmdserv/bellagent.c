#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>
#include <wwfile.h>
#include <wwnet.h>

#include <cmdsupp.h>
#include <intfcmd.h>
#include <wwtelnet.h>

/*****************BELL交换机回执信息**************/
#define bLoginFailSign1     "INVALID PASSWORD"		/*无效密码*/
#define bLoginFailSign2     "WRONG USERID"		/*无效用户*/
#define bLoginFailSign3     "LOCKED USER"		/*用户锁定*/
#define bLoginFailSign4     "ALREADY LOGGED ON"		/*用户已登录*/
#define bLoginSuccSign      "<"				/*登录成功提示*/
#define bEnterUserSign      "USERID <"			/*输入用户名提示*/
#define bEnterPwdSign       "PASSWORD <"		/*输入密码提示*/
#define bHLRCancelSign      "CANCELLED !"		/*连接取消*/
#define bHLRTerminatedSign  "DIALOG TERMINATED !"	/*连接中断*/
#define bReLoginSign        "SEMANTIC ERROR CODE = 0020"/*重复登录了*/
/*以下是业务部分*/
#define bFailureSign        "NOT SUCCESSFUL"		/*命令不成功*/
#define bCmdErrorSign       "COMMAND ERROR !"		/*命令错误*/
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
#define bCmdEndSign         "LAST REPORT"		/*回执结束*/
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
		/*清空缓冲区*/
		ResetRecvBufAndResult();
		return;
	}	
/*CANCEL,TERMINAL就将缓冲复位，将telnet断开从新连接*/
	if(strstr(sData,bHLRCancelSign)!=NULL||
		strstr(sData,bHLRTerminatedSign)!=NULL){
		/*清空缓冲区*/
		ResetRecvBufAndResult();
		Serv->iLogined=false;
		return;
	}	
/*如果数据没有结束,则将数据加到CmdResult.sRecvBuf缓冲中*/
	if(strlen(CmdResult.sRecvBuf)+strlen(sData)>8192){
		strcpy(Intf.sState,COMMAND_STATE_ERR);
		ProcFailureCmd("接收缓冲满");
		return;
	}
/*判断是否回执结束，如果没有结束则将数据加入缓冲*/
	if((pc=strchr(sData,0x03))==NULL){
		strcat(CmdResult.sRecvBuf,sData);
		return;	
	
	}

	if((strstr(CmdResult.sRecvBuf,"SUCCESSFUL")!=NULL||
		strstr(CmdResult.sRecvBuf,bNotFindDNSign)!=NULL)&&
		strcmp(Intf.sState,COMMAND_STATE_WAIT)!=0){
		/*清空缓冲区*/
		ResetRecvBufAndResult();
		return;
	}
	/*如果是查询则清空*/
	if(strstr(CmdResult.sRecvBuf,"DISPLAY-MS-DATA")!=NULL){
		/*清空缓冲区*/
		ResetRecvBufAndResult();
		return;
	}
	if(strstr(CmdResult.sRecvBuf,bCmdErrorSign)!=NULL){
/*如果是创建用户*/
		if(strcmp(Intf.sCmdType,"CRUSER")==0&&
			strstr(sData,bDelUserSign)!=NULL){
	
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
			strcpy(CmdResult.asCmdMsg[CmdResult.iCurCmd],"CRUSER删除命令失败");
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_SUC;
			
		}
		else{
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_ERR;
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务命令失败",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_CREATE_ERR;
		}
	}
	else if(strstr(CmdResult.sRecvBuf,bFailureSign)!=NULL){

		CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_OTHER_ERR;
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_ERR;
		if(strstr(CmdResult.sRecvBuf,bUserExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务用户已存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_MDN_EXIST;
			
		}
		else if(strstr(CmdResult.sRecvBuf,bIMSIExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务IMSI已存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_IMSI_EXIST;
		}
		else if(strstr(CmdResult.sRecvBuf,bPICExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务PIC已存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_PIC_EXIST;
		}
		else if(strstr(CmdResult.sRecvBuf,bESNExistSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务ESN已存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_ESN_EXIST;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindDNSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务用户不存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_MDN_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindIMSISign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务IMSI不存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_IMSI_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindESNSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务ESN不存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_ESN_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bNotFindPICSign)!=NULL){
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务PIC不存在",
				Intf.sCmdType);
			CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_PIC_NOTFOUND;
		}
		else if(strstr(CmdResult.sRecvBuf,bDuplicatedSign)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务重复选项",
				Intf.sCmdType);
		else if(strstr(CmdResult.sRecvBuf,bNoOptionSign1)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务删除不存在的业务",
				Intf.sCmdType);
		else if(strstr(CmdResult.sRecvBuf,bNoOptionSign2)!=NULL||
			strstr(CmdResult.sRecvBuf,bNoOptionSign3)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务辅业务不存在",
				Intf.sCmdType);
		else if(strstr(CmdResult.sRecvBuf,bCosNotExist)!=NULL)
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务COS业务不存在",
				Intf.sCmdType);
		else{
			sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务操作失败",
				Intf.sCmdType);
		}
	}
	else{
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		CmdResult.aiCmdRetCode[CmdResult.iCurCmd]=RT_SUC;
		sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务操作成功",
				Intf.sCmdType);
	}
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
/*用获得的参数初始化Telnet控制结构*/
	TelnetInitial(&Serv,pAgent->sIp,pAgent->iPort,
		pAgent->sUserName,pAgent->sPassword,
		"login","assword","Welcome");
/*设置处理的外置函数*/	
	Serv.OnLogined=	OnLogin;
	Serv.OnTimeOut=	OnTimeOut;
	Serv.OnError=		OnError;
	Serv.ProcCmd=	OnProcCmd;
	Serv.OnDataRecv= 	OnDataRecv;
	Serv.OnDisconnect= 	OnDisconnect;

	TelnetProcMain(&Serv);
	
	return 0;
}
