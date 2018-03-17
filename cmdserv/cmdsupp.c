
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwcoding.h>
#include <list.h>
#include <wwnet.h>
#include <wwshm.h>
#include <wwdb.h>
#include <param_intf.h>

#include <cmdsupp.h>
#include <intfcmd.h>


struct IIntfCmdStruct Intf;
struct CmdResultStruct CmdResult;
struct ShmCmdHead 	*PSHMCMD;

int SearchShmCmd(char sSerialNbr[],POINTER ioffHead,POINTER *pioffCur)
{	
	struct IIntfCmdStruct *pTemp;
	
	*pioffCur=-1;
	
	while(ioffHead!=-1){
		
		pTemp=(struct IIntfCmdStruct *)OPSHMCMD(ioffHead);
		
		if(strcmp(sSerialNbr,pTemp->sSerialNbr)==0){
			*pioffCur=ioffHead;
			return FOUND;
		}
		ioffHead=OONXTSHMCMD(ioffHead);
	}
	return NOTFOUND;
	
}

void ResetRecvBufAndResult()
{
	int i;
	
	strcpy(CmdResult.sRecvBuf,"");
	for(i=0;i<20;i++){
		CmdResult.sCmdState[i]=0;
		strcpy(CmdResult.asCmdMsg[i],"");
	}
}
void AnalizeCmdResult()
{
	int i,l=0;

	strcpy(Intf.sState,COMMAND_STATE_SUC);
	Intf.iRetCode=RT_SUC;
	
	for(i=0;i<CmdResult.iCmdCnt;i++){
		if(CmdResult.sCmdState[i]==CMDSTATE_ERR)
			strcpy(Intf.sState,COMMAND_STATE_ERR);
		if(i==0)l+=sprintf(Intf.sBackLine+l,"%s",CmdResult.asCmdMsg[i]);
		else	l+=sprintf(Intf.sBackLine+l,"|%s",CmdResult.asCmdMsg[i]);
		if(CmdResult.aiCmdRetCode[i]!=RT_SUC)
			Intf.iRetCode=CmdResult.aiCmdRetCode[i];
	}
	if(strcmp(Intf.sState,COMMAND_STATE_ERR)==0)
		Intf.iRetCode=RT_OTHER_ERR;
}
/**
1.找到在等待链表中的命令；
2.将全局变量中命令状态及详细信息给指定命令；
3.从等待链表中删除并加入到当前处理链表中;
**/

int  ProcCmdEnd()
{
	POINTER ioffHead,ioffCur;
	struct IAgentStruct *pAgent;
	struct IIntfCmdStruct *pCmd;
	
	if((pAgent=GetShmAgent(Intf.iSwitchID))==NULL) return -1;
	
	ioffHead=pAgent->ioffWaitCmd;
	
	if(SearchShmCmd(Intf.sSerialNbr,ioffHead,&ioffCur)==NOTFOUND)
		return -1;
	pCmd=(struct IIntfCmdStruct*)OPSHMCMD(ioffCur);
	
	strcpy(pCmd->sState,Intf.sState);
	strcpy(pCmd->sBackLine,Intf.sBackLine);
	pCmd->iRetCode=Intf.iRetCode;

	LockAgent(pAgent);
	
	INSERT_SHMCMD_LIST(&(pAgent->ioffWaitCmd),ioffCur);
	INSERT_SHMCMD_LIST(&(pAgent->icurCmd),ioffCur);

	UnlockAgent(pAgent);
	
	return 0;
}
/**
1.将错误状态和错误信息写到全局变量的状态中；
2.调用错误函数将命令写到当前处理结束链表中;
3.从等待链表中删除并加入到当前处理链表中;
**/
int  ProcFailureCmd(char sMsg[])
{

	strncpy(Intf.sBackLine,sMsg,256);Intf.sBackLine[256]=0;
	strcpy(Intf.sState,COMMAND_STATE_ERR);
	
	return ProcCmdEnd();
}
int GetCmdLen(struct IIntfCmdStruct *pCmd,int iCurPos)
{
	char sTemp[3],sCmdPosInfo[11];
	
	struct CmdLineStruct *pCmdLine;
	
	pCmdLine=(struct CmdLineStruct *)(pCmd->sCmdLine);
	strncpy(sCmdPosInfo,pCmdLine->sCmdPosInfo,10);
	sCmdPosInfo[10]=0;AllTrim(sCmdPosInfo);
	
	strncpy(sTemp,sCmdPosInfo+2*iCurPos,2);
	sTemp[2]=0;
	return HexStrToInt(sTemp);
}
int GetCmdCnt(struct IIntfCmdStruct *pCmd)
{
	char sCmdPosInfo[11];
	
	struct CmdLineStruct *pCmdLine;
	
	pCmdLine=(struct CmdLineStruct *)(pCmd->sCmdLine);
	strncpy(sCmdPosInfo,pCmdLine->sCmdPosInfo,10);
	sCmdPosInfo[10]=0;AllTrim(sCmdPosInfo);
	return strlen(sCmdPosInfo)/2;
}
void GetCmdType(struct IIntfCmdStruct *pCmd,
	char sCmdType[])
{
	struct CmdLineStruct *pCmdLine;
	
	pCmdLine=(struct CmdLineStruct *)(pCmd->sCmdLine);
	strncpy(sCmdType,pCmdLine->sCmdType,2);sCmdType[2]=0;
}
void GetCmd(struct IIntfCmdStruct *pCmd,int iCurCnt,
	char sCmd[])
{

	int i,off=0,l;
	
	for(i=0;i<iCurCnt;i++)
		off+=GetCmdLen(pCmd,i);
	l=GetCmdLen(pCmd,iCurCnt);
	
	memcpy(sCmd,pCmd->sCmdLine+
		sizeof(struct CmdLineStruct)+off,l);
	sCmd[l]=0;
}
void GetShmCmdSend(int iSockFd)
{
	int iCount=0;
	POINTER ioffCmd;
	char	sCmdType[3],sTemp[257];
	struct IAgentStruct *pAgent=NULL;
	struct IIntfCmdStruct *pCmd;
	
	
/*如果接口全局变量的状态为等待则不能覆盖*/
	if(strcmp(Intf.sState,COMMAND_STATE_WAIT)==0)return;

	if((pAgent=GetShmAgent(Intf.iSwitchID))==NULL){
		printf("SwitchID=%d在共享内存中不存在.\n",Intf.iSwitchID);
		exit(1);
	}
	
/*如果当前没有工单则等待2分钟，每100ms查询一次*/
	while(pAgent->ioffCmd==-1){usleep(100);iCount++;if(iCount>1200)break;}
	if(pAgent->ioffCmd==-1){/*如果超时,2分钟,没有命令到来则发一个ls过去*/
		SockSendBuf(iSockFd,"ls\n",-1);
		return;
	}
/*查看共享内存锁状况,如果没有锁则锁一下*/
	LockAgent(pAgent);
/*取出待处理工单到全局变量--------*/
	ioffCmd=pAgent->ioffCmd;
	pCmd=(struct IIntfCmdStruct*)OPSHMCMD(ioffCmd);
	
/*获取命令个数、命令及命令类型*/
	CmdResult.iCmdCnt=GetCmdCnt(pCmd);
	GetCmd(pCmd,0,sTemp);
	GetCmdType(pCmd,sCmdType);

	/*从缓冲链表中删除取出的工单*/
	pAgent->ioffCmd=OONXTSHMCMD(ioffCmd);
/*可以直接返回的命令直接写入返回链表，
	需要送给交换机处理的命令写等待链表*/	
	if(strcmp(sCmdType,SYS_REQ_CMD)==0){
		strcpy(pCmd->sBackLine,sTemp);
		strcpy(pCmd->sState,COMMAND_STATE_SUC);
		INSERT_SHMCMD_LIST(&(pAgent->icurCmd),ioffCmd);
	}
	else{
		strcpy(pCmd->sState,COMMAND_STATE_WAIT);
		INSERT_SHMCMD_LIST(&(pAgent->ioffWaitCmd),ioffCmd);
	}
/*拷贝到本地内存*/
	memcpy((void*)&Intf,(void*)pCmd,sizeof(struct IIntfCmdStruct));
/*解锁*/
	UnlockAgent(pAgent);

	if(strcmp(sCmdType,SYS_REQ_CMD)!=0)
		SockSendBuf(iSockFd,sTemp,strlen(sTemp));
}
int SearchShmAgent(int iSwitchID,POINTER ioffHead,POINTER *pioffCur)
{
	struct IAgentStruct *pTemp;
	
	*pioffCur=-1;
	
	while(ioffHead!=-1){
		pTemp=(struct IAgentStruct *)OPSHMCMD(ioffHead);
	
		if(iSwitchID==pTemp->iSwitchID){
			*pioffCur=ioffHead;
			return FOUND;
		}
		ioffHead=OONXTSHMCMD(ioffHead);
	}
	return NOTFOUND;
}
struct IAgentStruct *GetShmAgent(int iSwitchID)
{
	POINTER ioffTmp;
	struct IAgentStruct *pAgent=NULL;
	
	if(SearchShmAgent(iSwitchID,PSHMCMD->ioffAgent,&ioffTmp)==NOTFOUND)
		return NULL;
	pAgent=(struct IAgentStruct *)OPSHMCMD(ioffTmp);
	return pAgent;
}

int CheckPack(char sInput[],int l,char sErrMsg[])
{
	int 	iBodyLen,iWapLen;
	char	sTemp[20];
	struct	CdmaCmdHeadStruct *pHead;
	struct	CdmaCmdTailStruct *pTail;
	
	strcpy(sErrMsg,"");
	pHead=(struct	CdmaCmdHeadStruct *)sInput;
	strncpy(sTemp,pHead->sBodyLen,6);sTemp[6]=0;
	iBodyLen=atoi(sTemp);
	
	iWapLen=sizeof(struct CdmaCmdHeadStruct)+
		sizeof(struct CdmaCmdTailStruct);
	
	if(iBodyLen+iWapLen!=l){
		sprintf(sErrMsg,"包长非法:包长应为%d,实际包长度为%d.\n",
			iBodyLen+iWapLen,l);
		return -1;
	}
	pTail=(struct	CdmaCmdTailStruct *)
		(sInput+iBodyLen+sizeof(struct	CdmaCmdHeadStruct));
	if(strncmp(pHead->sHeadIdentify,"MHF",3)!=0){
		sprintf(sErrMsg,"包头非法.\n");
		return -1;
	}
/*
	if(strncmp(pHead->sVersion,"00001",5)!=0){
		sprintf(sErrMsg,"版本信息无效.\n");
		return -1;
	}
*/
/*	if(strncmp(pHead->sOppSysCode,"        ",8)!=0){
		sprintf(sErrMsg,"营帐系统代码无效.\n");
		return -1;
	}
	if(strncmp(pHead->sMySysCode,"        ",8)!=0){
		sprintf(sErrMsg,"联机指令系统代码无效.\n");
		return -1;
	}
*/
	if(strncmp(pTail->sTailIdentify,"MNF\n",4)!=0){
		sprintf(sErrMsg,"包尾非法.\n");
		return -1;
	}
	return iBodyLen;
	
}
struct InfoItemStruct *GenInfoItemList(char sInfoLine[],
	char cSepItem,char cSepVal)
{
	char	sTemp[128],sName[61],sValue[61],*pc;
	struct ParamStruct	Param;
	struct PositionStruct	Pos;
	struct InfoItemStruct *pTemp,*ptHead=NULL;
	
	Param.d1=0;
	Param.d2=cSepItem;
	
	while(1){

		GET_SEP_POS(sInfoLine,(char *)&Param,&Pos);
		if(Pos.pData==NULL) break;

		strncpy(sTemp,Pos.pData+Pos.iOffset,Pos.iLen);
		sTemp[Pos.iLen]=0;
		
		if(strlen(sTemp)==0) break;

		if((pc=strchr(sTemp,cSepVal))==NULL){
			DestroyList((LIST*)ptHead);
			return NULL;
		}
		
		strncpy(sName,sTemp,pc-sTemp);sName[pc-sTemp]=0;
		strcpy(sValue,++pc);
		
		if((pTemp=(struct InfoItemStruct*)
			malloc(sizeof(struct InfoItemStruct)))==NULL){
			DestroyList((LIST*)ptHead);
			printf("malloc error.\n");
			return NULL;
		}
		strcpy(pTemp->sName,sName);
		strcpy(pTemp->sValue,sValue);
		InsertListTail((LIST**)&ptHead,(LIST*)pTemp);
		
		Param.d1++;
	}
	return ptHead;
}
void GenInfoLine(struct InfoItemStruct *ptHead,char cSepItem,char cSepVal,
	char sInfoLine[256])
{
	int l=0;
	
	while(ptHead!=NULL){
		if(ptHead->pNext==NULL)
			l+=sprintf(sInfoLine+l,"%s%c%s",
				ptHead->sName,cSepItem,ptHead->sValue);
		else
			l+=sprintf(sInfoLine+l,"%s%c%s%c",
				ptHead->sName,cSepItem,ptHead->sValue,cSepVal);
		ptHead=ptHead->pNext;
	}
}
void GetInfoItemValue(struct InfoItemStruct *ptHead,char sName[],
	char sValue[])
{
	strcpy(sValue,"");
	while(ptHead!=NULL){
		if(strcmp(sName,ptHead->sName)==0){
			strcpy(sValue,ptHead->sValue);
			return;
		}
		ptHead=ptHead->pNext;
	}
}

/*******共享内存建立刷新过程**********/
/*全局变量结束*/
int InitCmdTab()
{
	ERROR_EXIT(MoveShmToMem(MInitSwitch)<0,"获取SWITCH错误");
	ERROR_EXIT(MoveShmToMem(MInitCmdTemplate)<0,"获取CMD_TEMPLATE错误");
	ERROR_EXIT(MoveShmToMem(MInitNbrHead)<0,"获取NBR_HEAD错误");
	return 0;
}
int DestroyCmdTab()
{
	ERROR_EXIT(MoveShmToMem(MDestroySwitch)<0,"释放SWITCH错误");
	ERROR_EXIT(MoveShmToMem(MDestroyCmdTemplate)<0,"释放CMD_TEMPLATE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyNbrHead)<0,"释放NBR_HEAD错误");
	return 0;
}
int GetReserveAgentCnt()
{
	int iRet;
	char sPath[128],sTemp[128];
	
	GetIniName(sPath);
	iRet=ReadString(sPath,"bss","cmdserv","RESERVE_AGENT_CNT",sTemp);
	if(iRet<0) return -1;
	return Str2Int(sTemp);
}
int GetAgentCmdBuf()
{
	int iRet;
	char sPath[128],sTemp[128];
	
	GetIniName(sPath);
	iRet=ReadString(sPath,"bss","cmdserv","AGENT_CMD_BUF",sTemp);
	if(iRet<0) return -1;
	return Str2Int(sTemp);
}
int GetMaxAdaptCnt()
{
	int iRet;
	char sPath[128],sTemp[128];
	
	GetIniName(sPath);
	iRet=ReadString(sPath,"bss","cmdserv","MAX_ADAPT_CNT",sTemp);
	if(iRet<0) return -1;
	return Str2Int(sTemp);
}
int GetCmdShmKey()
{
	int iRet;
	char sPath[128],sTemp[128];
	
	GetIniName(sPath);
	iRet=ReadString(sPath,"bss","cmdserv","SHM_KEY",sTemp);
	
	if(iRet<0) return -1;
	if(strlen(sTemp)==0) return -1;
	
	return Str2Int(sTemp);
}
int CalcNeedCmdShm(struct MemCmdStruct *ptHead)
{
	int iTotalLen,iReserveAgentCnt,iAgentCmdBuf,iAgentCnt,iAdaptBufLen;
	
	struct SwitchStruct *ptLkHead=NULL;
	
	bzero((void*)ptHead,sizeof(struct MemCmdStruct));
	
	if(SearchSwitch(&ptLkHead)==NOTFOUND) return -1;
	
	if((iReserveAgentCnt=GetReserveAgentCnt())<0) return -1;

	if((iAgentCmdBuf=GetAgentCmdBuf())<0) return -1;
	
	if((iAdaptBufLen=GetMaxAdaptCnt())<0) return -1;
	
	iAgentCnt=CountList((LIST*)ptLkHead);
	
	iTotalLen=sizeof(struct ShmCmdHead)+
		iAdaptBufLen*(sizeof(struct IAdaptStruct))+
		(iReserveAgentCnt+iAgentCnt)*(sizeof(struct IAgentStruct)+
		iAgentCmdBuf*sizeof(struct IIntfCmdStruct));
	
	ptHead->iTotalLen=	iTotalLen;
	ptHead->iCmdBufLen=	iAgentCmdBuf;
	ptHead->iAgentBufLen=	iReserveAgentCnt+iAgentCnt;
	ptHead->iAdaptBufLen=	iAdaptBufLen;

	return iTotalLen;
	
	
}
/*第一次建立结构，初始化pMem和pShm，用pMem结构成员*/
int InitialCmdMemShm(struct MemCmdStruct *pMem)
{

	POINTER ioffNew;
	int i,iRet=0;
	
	struct SwitchStruct *ptHead=NULL;
	struct IAgentStruct *pAgent=NULL;
	
	if(SearchSwitch(&ptHead)==NOTFOUND) return -1;
	
	bzero((void*)PSHMCMD,sizeof(struct ShmCmdHead));
	
	PSHMCMD->iLock=	1;	/*锁定共享内存*/
	
	PSHMCMD->iTotalLen=	pMem->iTotalLen;
	
	PSHMCMD->Adapt.iRecCnt=pMem->iAdaptBufLen;
	PSHMCMD->Adapt.iRecLen=sizeof(struct IAdaptStruct);
	PSHMCMD->Adapt.iUsedCnt=0;
	PSHMCMD->Adapt.ioffFree=-1;
	
	PSHMCMD->Agent.iRecCnt=pMem->iAgentBufLen;
	PSHMCMD->Agent.iRecLen=sizeof(struct IAgentStruct);
	PSHMCMD->Agent.iUsedCnt=0;
	PSHMCMD->Agent.ioffFree=-1;
	
	PSHMCMD->IntfCmd.iRecCnt=pMem->iCmdBufLen*
				pMem->iAgentBufLen;
	PSHMCMD->IntfCmd.iRecLen=sizeof(struct IIntfCmdStruct);
	PSHMCMD->IntfCmd.iUsedCnt=0;
	PSHMCMD->IntfCmd.ioffFree=-1;
	
	PSHMCMD->ioffAdapt=-1;
	PSHMCMD->ioffAgent=-1;
	
	PSHMCMD->iCmdBufLen=pMem->iCmdBufLen;
	
	PSHMCMD->ioffFree=sizeof(struct ShmCmdHead);
	

/*将所有的pAdapt加入空闲链表*/
	ioffNew=PSHMCMD->ioffFree;
	for(i=0;i<pMem->iAdaptBufLen;i++){
		bzero((void*)OPSHMCMD(ioffNew),sizeof(struct IAdaptStruct));
		INSERT_SHMCMD_LIST(&(PSHMCMD->Adapt.ioffFree),ioffNew);
		ioffNew+=sizeof(struct IAdaptStruct);
	}
/*将所有的pAgent加入空闲链表*/
	for(i=0;i<pMem->iAgentBufLen;i++){
		bzero((void*)OPSHMCMD(ioffNew),sizeof(struct IAgentStruct));
		
		pAgent=(struct IAgentStruct *)OPSHMCMD(ioffNew);
		pAgent->iIndex=		i;/*给将来初始化命令链表用*/
		pAgent->iCmdBufLen=	pMem->iCmdBufLen;
		
		INSERT_SHMCMD_LIST(&(PSHMCMD->Agent.ioffFree),ioffNew);
		ioffNew+=sizeof(struct IAgentStruct);
	}
/*将所有的pIntfCmd加入空闲链表*/
	for(i=0;i<pMem->iAgentBufLen*pMem->iCmdBufLen;i++){
		bzero((void*)OPSHMCMD(ioffNew),
			sizeof(struct IIntfCmdStruct));
		INSERT_SHMCMD_LIST(&(PSHMCMD->IntfCmd.ioffFree),ioffNew);
		ioffNew+=sizeof(struct IIntfCmdStruct);	
	}
	PSHMCMD->ioffFree=ioffNew;

/*将Switch中的结构加入IntfCmd中*/

	while(ptHead!=NULL){

		if(PSHMCMD->Agent.ioffFree==-1){iRet=-1;break;}

		ioffNew=PSHMCMD->Agent.ioffFree;
		
		DELETE_SHMCMD_LIST(&(PSHMCMD->Agent.ioffFree),ioffNew);

		pAgent=(struct IAgentStruct *)OPSHMCMD(ioffNew);

		
		InitialAgentItem(ptHead,pAgent);

		INSERT_SHMCMD_LIST(&(PSHMCMD->ioffAgent),ioffNew);

		ptHead=ptHead->pNext;		
	}
	
	PSHMCMD->iLock=0;
	
	return iRet;
	
}
/*用pSwitch初始化pIAgent,并将pAgent对应的Cmd链表初始化*/
void InitialAgentItem(struct SwitchStruct *ptHead,struct IAgentStruct  *pItem)
{
/*index、cmdbuflen已经在外部初始化了,
  增加量刷新时只更新cmdbuflen*/
	pItem->iSwitchID= ptHead->iSwitchID;
	strcpy(pItem->sIp,ptHead->sIp);
	pItem->iPort=	ptHead->iPort;
	
	strcpy(pItem->sUserName,ptHead->sUserName);
	strcpy(pItem->sPassword,ptHead->sPassword);
	strcpy(pItem->sAreaCode,ptHead->sAreaCode);
	
	pItem->iLock=0;
	pItem->iHeartByte=0;
	pItem->pid=0;
	pItem->iCmdCnt=0;

	pItem->ioffWaitCmd=-1;
	pItem->ioffCmd=-1;
	
	pItem->icurCmd=-1;
}
int ConnectCmdShmAndInitMem()
{
	int iShmKey,iErrCode=0;
	
	if((iShmKey= GetCmdShmKey())<0) return -1;
	
	PSHMCMD=(struct ShmCmdHead*)AttachShm(iShmKey,&iErrCode,NULL);
	
	if(iErrCode) return -1;

	return 0;
}
int BuildCmdShmInit()
{
	void *pData;
	struct MemCmdStruct Mem;
	int	iTotalLen,iErrCode=0,iShmKey;
		
	if((iShmKey= GetCmdShmKey())<0) return -1;
	
	if((iTotalLen=CalcNeedCmdShm(&Mem))<0) return -1;
	
	pData=CreateShm(iShmKey,iTotalLen,&iErrCode);
	
	if(iErrCode) return -1;
	DetachShm(pData);
	
	if(UpdateShmHead(iShmKey,iTotalLen)<0) return -1;
	
	pData=AttachShm(iShmKey,&iErrCode,0);
	if(iErrCode) return -1;
	
	PSHMCMD=(struct ShmCmdHead *)pData;

	return InitialCmdMemShm(&Mem);
}
int SwitchInShm(struct SwitchStruct *p)
{
	POINTER ioffHead;
	struct IAgentStruct *pTemp;
	
	ioffHead=PSHMCMD->ioffAgent;
	
	while(ioffHead!=-1){
		pTemp=(struct IAgentStruct *)OPSHMCMD(ioffHead);
		
		if(strcmp(p->sIp,pTemp->sIp)==0&&
			p->iPort==pTemp->iPort&&
			strcmp(p->sUserName,pTemp->sUserName)==0&&
			strcmp(p->sPassword,pTemp->sPassword)==0) return true;
			
		ioffHead=OONXTSHMCMD(ioffHead);
	}
	
	return false;
}	
int IncreaseCmdShmInit()
{
	int iRet=0;
	POINTER ioffNew;
	struct IAgentStruct *pAgent=NULL;
	struct SwitchStruct *ptHead=NULL;
	
	if(SearchSwitch(&ptHead)==NOTFOUND) return -1;
	
	while(ptHead!=NULL){
		
		if(SwitchInShm(ptHead)==true){
			ptHead=ptHead->pNext;
			continue;
		}
		
		if(PSHMCMD->Agent.ioffFree==-1){iRet=-1;break;}

/*从共享内存中取一个ELIST节点*/
		ioffNew=PSHMCMD->Agent.ioffFree;
		DELETE_SHMCMD_LIST(&(PSHMCMD->Agent.ioffFree),ioffNew);
		
		pAgent=(struct IAgentStruct*)OPSHMCMD(ioffNew);
		pAgent->iCmdBufLen=PSHMCMD->iCmdBufLen;
		
		InitialAgentItem(ptHead,pAgent);

		ptHead=ptHead->pNext;		
	}
	return iRet;
	
}
/*将事件放到共享内存*/
int AdaptNotifyCmdServer(int iMsg)
{	
	if(ConnectCmdShmAndInitMem()<0) return -1;
	
	PSHMCMD->iCmdAdaptEvent|=iMsg;
	
	DetachShm((void*)PSHMCMD);
	
	return 0;
}
/*获取共享内存中的事件消息*/
int GetAdaptNotify()
{
	int iRet;
	
	if(ConnectCmdShmAndInitMem()<0) return 0;
	
	iRet=PSHMCMD->iCmdAdaptEvent;
	PSHMCMD->iCmdAdaptEvent=0;
	
	DetachShm((void*)PSHMCMD);

	return iRet;
}
/*获取共享内存中可以使用的命令缓冲链表*/
struct SwitchStatStruct *GetSwitchStatList()
{
	POINTER ioffHead=PSHMCMD->ioffAgent;
	struct IAgentStruct *pAgent=NULL;
	struct SwitchStatStruct *pTemp,*ptHead=NULL;
	
	while(ioffHead!=-1){
		
		if((pTemp=(struct SwitchStatStruct*)
			malloc(sizeof(struct SwitchStatStruct)))==NULL){
			DestroyList((LIST*)ptHead);
			return NULL;
		}
		bzero((void*)pTemp,sizeof(struct SwitchStatStruct));
		
		pAgent=(struct IAgentStruct *)OPSHMCMD(ioffHead);
		
		pTemp->iSwitchID=pAgent->iSwitchID;
		pTemp->iFreeCmdCnt=pAgent->iCmdBufLen-pAgent->iCmdCnt;
		
		ioffHead=OONXTSHMCMD(ioffHead);
		InsertList((LIST**)&ptHead,(LIST*)pTemp);
	}
	return ptHead;
}

void LockCmdShm()
{
	int i=0;
	
	while(PSHMCMD->iLock==1){
		WaitSec(1);
		i++; 
		if(i>60){
			WriteAlertMsg("CMDSERVER->SERVER共享内存死锁.\n");
			exit(1);
		}
	}
	PSHMCMD->iLock=1;
}
void UnlockCmdShm()
{
	PSHMCMD->iLock=0;
}
void HeartBeatServer()
{
	static int iFirstFlag=true;
	
	if(iFirstFlag==true){
		iFirstFlag=false;
		PSHMCMD->iHeartBeat=0;
	}
	PSHMCMD->iHeartBeat++;
	if(PSHMCMD->iHeartBeat>100000000)
		PSHMCMD->iHeartBeat=0;
}
int IsCmdServRun()
{
	int iPreCnt,iCurCnt;
	
	iPreCnt=PSHMCMD->iHeartBeat;
	
	WaitSec(1);
	
	iCurCnt=PSHMCMD->iHeartBeat;
	
	if(iCurCnt==iPreCnt) return false;
	
	return true;	
}
void LockAgent(struct IAgentStruct *pAgent)
{
	int iCount=0;
	
	while(pAgent->iLock==1){usleep(100);if(iCount++>10) break;}
	if(iCount>50){
		printf("SwitchID=%d在共享内存死锁.\n",pAgent->iSwitchID);
		exit(1);
	}
/*锁定当前共享内存*/
	pAgent->iLock=1;
}
void UnlockAgent(struct IAgentStruct *pAgent)
{
	pAgent->iLock=0;
}

int  AnswerCdmaMsg(int iSockFd,char sCmd[],char sCmdType[],
	char sMsg[],int iFlag)
{
	char	sTemp[8192];

/*对返回命令工单的类型进行检测,只发送指定工单类型*/	
	if(strcmp(sCmdType,"REQACK")!=0&&
		strcmp(sCmdType,"FEBRSP")!=0&&
		strcmp(sCmdType,"USIRSP")!=0&&
		strcmp(sCmdType,"WITRSP")!=0&&
		strcmp(sCmdType,"WDTRSP")!=0) return -1;

	strcpy(sTemp,"");	
	strcat(sTemp,"MSGF+");
	if(iFlag==true)	strcat(sTemp,"0\'");
	else		strcat(sTemp,"1\'");
	strcat(sTemp,"ERRTEXT+");
	strcat(sTemp,sMsg);
	
	return AnswerCdmaIntf(iSockFd,sCmd,sCmdType,sTemp);
}
int  AnswerCdmaIntf(int iSockFd,char sCmd[],char sCmdType[],
	char sReturn[])
{
	static char	sTemp[CDMA_BACK_BUF];
	struct CdmaCmdHeadStruct *p;

	p=(struct CdmaCmdHeadStruct*)sTemp;
	
	memcpy(sTemp,sCmd,sizeof(struct CdmaCmdHeadStruct));
	sTemp[sizeof(struct CdmaCmdHeadStruct)]=0;
	
	strcat(sTemp,sReturn);
	strcat(sTemp,"MNF\n");
	
	strncpy(p->sCmdType,sCmdType,strlen(sCmdType));
	
	return SockSendData(iSockFd,sTemp,strlen(sTemp));
}
