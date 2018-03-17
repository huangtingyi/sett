#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <cmdsupp.h>
#include <intfcmd.h>

#include <wwnet.h>

int OnConnect(struct ClientSockStruct *Socket)
{
	puts("OnConnect");
	return 0;
}
int OnDisconnect(struct ClientSockStruct *Socket)
{
	puts("OnDisconnect");
	return 0;
}
int OnDataRecv(struct ClientSockStruct *Socket,char sData[],int iLen)
{
	puts("onDataAvalible");
	return 0;
}
int OnError(struct ClientSockStruct *Socket)
{
	puts("OnError");
	return 0;
}
int OnTimeOut(struct ClientSockStruct *Socket)
{
	puts("OnTimeOut");
	return 0;
}
int ProcCmd(struct ClientSockStruct *Socket)
{
	puts("ProcCmd");
	return 0;
}
int CdmaSendResult(int iSockFd,struct IntfCmdStruct *ptHead)
{
	char sBackType[7],sComBody[256];
	int iBodyLen;
	
	if(strcmp(ptHead->sCmdType,"QUINFO")==0)
		strcpy(sBackType,"USIRSP");
	else
		strcpy(sBackType,"FEBRSP");
	
	
	sprintf(sComBody,"RTCODE+%d'RTDESC+%s",
		ptHead->iRetCode,ptHead->sBackLine);
	iBodyLen=strlen(sComBody);
	
	sprintf(ptHead->sBackLine,"%s%06d%sMNF\n",
		sBackType,iBodyLen,sComBody);
	
      	SockSendData(iSockFd,ptHead->sBackLine,-1);
      	
      	
	return 0;
}
int ResultClientSockMain(struct ClientSockStruct *Socket)
{
	
	fd_set iFdSet,iPreFdSet;
	char	sCondition[256];
	struct IntfCmdStruct *ptHead=NULL,*ptPre,*ptCur;
	
	static struct IntfCmdStructUp TempUp;
	
	strcpy(TempUp.sTableName,"INTF_CMD");
	
	strcpy(sCondition,"WHERE STATE IN('I0E','I0F','I0S')");
	
	InitMySet(&iFdSet);
	Item2MySet(&iFdSet,Socket->iSockFd);
	
	while(Socket->iTerminate==0){
		
		iPreFdSet=iFdSet;
		
		if(Socket->iConnected==0){
			ClientSockConnect(Socket);
			Socket->iConnected= true;
			return 0;
		}
		/*从数据库中取出n条待返回工单*/
		if(InitIntfCmd(&ptHead,sCondition)<0){
			WriteAlertMsg("从数据库获取数据错误");
			return -1;
		}
		/*如果没有工单则sleep5*/
		if(ptHead==NULL){
			WaitSec(5);
			continue;
		}
		/*将每一张工单组织成指定格式发给营帐*/
		ptCur=ptHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			/*组织工单发给营帐*/
			if(CdmaSendResult(Socket->iSockFd,ptPre)<0) continue;
		
			/*成功发给营帐的工单更新状态*/
			strcpy(ptPre->sState,"I0H");
			if(EUpdateStructToUIntfCmd(ptPre,false,&TempUp)<0)
				return -1;
		}
		/*更新数据库将数据库指定工单的状态改未历史*/
		
/*将内存的数据释放*/
		DestroyList((LIST*)ptHead);
		ptHead=NULL;
		
		if(EUpdateStructToUIntfCmd(NULL,true,&TempUp)<0)
			return -1;
		CommitWork();
	}

	return 0;
}
int main(int argc,char **argv)
{
	int iPort;
	char sIp[16];
	
	struct ClientSockStruct Socket;
	
	if(argc!=3){
		printf("Usage :%s ip port.\n",argv[0]);
		return -1;
	}
	
	strcpy(sIp,argv[1]);
	iPort=atoi(argv[2]);
	
	InitClientSocket(&Socket,sIp,iPort,20);

	
	Socket.OnConnect	= OnConnect;
	Socket.OnDisconnect	= OnDisconnect;
	Socket.OnDataRecv	= OnDataRecv;
	Socket.OnError		= OnError;
	Socket.OnTimeOut	= OnTimeOut;
	Socket.ProcCmd	= ProcCmd;
	Socket.ClientSockProcMain=ResultClientSockMain;
	
		
	ClientSockConnect(&Socket);
	
	ClientSockProcMain(&Socket);
	
	return 0;
}

