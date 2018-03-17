#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "list.h"
#include "wwlog.h"
#include "wwcoding.h"
#include "wwfile.h"
#include "wwnet.h"

#include "expr.h"

struct UserStruct
{
	char	sMsisdn[16];
	char	sImsi[16];
	char	sEsn[16];
	char	sMsg[256];
};

struct UserStruct gUsr;

struct CmdParamStruct
{
	struct CmdParamStruct *pNext;
	char	sName[128];
	char	sValue[128];
};
struct CmdProcStruct
{
	struct CmdProcStruct *pNext;
	char	sName[256];
	int	iParamCnt;
	struct CmdParamStruct *pHead;
	int	(*ProcCmd)(struct CmdParamStruct *pHead,char sResult[256]);
};
struct TcpClientStruct *pClient=NULL;

struct CmdParamStruct *GetCmdParam(char sInput[1024]);
void GetTabStr(char sInput[1024],int iPos,char sOutput[]);
struct CmdProcStruct *GetCmdProc(char sInput[1024]);
int SearchCmd(struct CmdProcStruct *ptHead,char sName[],
	struct CmdProcStruct **pptCur);
int RegRespond(struct CmdProcStruct **pptHead,char sCmdStr[1024],
	int(*ProcCmd)(struct CmdParamStruct *pHead,char sResult[256]));

void GetTabStr(char sInput[1024],int iPos,char sOutput[])
{
	struct ParamStruct Param;
	struct PositionStruct Position;

	Param.d1=	iPos;
	Param.d2=	0;

	strcpy(sOutput,"");

	if(GET_TAB_POS(sInput,(char *)&Param,&Position)==-1) return;
	
	strncpy(sOutput,sInput+Position.iOffset,Position.iLen);
	sOutput[Position.iLen]=0;
}
struct CmdProcStruct *GetCmdProc(char sInput[1024])
{
	char	sOutput[256];
	struct CmdProcStruct *pTemp;

	GetTabStr(sInput,0,sOutput);
	if(strlen(sOutput)==0) return NULL;

	if((pTemp=(struct CmdProcStruct *)malloc(sizeof(
		struct CmdProcStruct)))==NULL) return NULL;

	bzero((void*)pTemp,sizeof(struct CmdProcStruct));
	strcpy(pTemp->sName,sOutput);

	pTemp->pHead=GetCmdParam(sInput);
	pTemp->iParamCnt=CountList((LIST*)(pTemp->pHead));
	
	return pTemp;	
}
struct CmdParamStruct *GetCmdParam(char sInput[1024])
{
	int j=1;
	char	sOutput[256];
	struct CmdParamStruct *ptHead=NULL,*pTemp;

	while(1){
		GetTabStr(sInput,j,sOutput);
		if(strlen(sOutput)==0) break;

		if((pTemp=(struct CmdParamStruct *)malloc(sizeof(
			struct CmdParamStruct)))==NULL){
			DestroyList((LIST*)ptHead);
			return NULL;
		}
		bzero((void*)pTemp,sizeof(struct CmdParamStruct));
		strcpy(pTemp->sName,sOutput);
		InsertListTail((LIST**)&ptHead,(LIST*)pTemp);
		j++;
	}
	return ptHead;
}
int RegRespond(struct CmdProcStruct **pptHead,char sCmdStr[1024],
	int(*ProcCmd)(struct CmdParamStruct *pHead,char sResult[256]))
{
	struct CmdProcStruct *ptHead;

	ptHead=GetCmdProc(sCmdStr);
	ptHead->ProcCmd=	ProcCmd;

	InsertList((LIST**)pptHead,(LIST*)ptHead);
	return 0;
}
int comp_search_cmd(void *pi,LIST *po)
{
	char	*sName=(char*)pi;
	struct CmdProcStruct *pTarget=(struct CmdProcStruct *)po;
	
	return strcmp(sName,pTarget->sName);
}
int SearchCmd(struct CmdProcStruct *ptHead,char sName[],
	struct CmdProcStruct **pptCur)
{
	return SearchList((LIST*)ptHead,sName,
		(LIST**)pptCur,comp_search_cmd);
}
void PrintUsage(struct CmdProcStruct *ptHead,char sUsage[256])
{
	int l=0;
	struct CmdParamStruct *pTemp=ptHead->pHead;

	l+=sprintf(sUsage,"用法:%s",ptHead->sName);
	
	while(pTemp!=NULL){
		l+=sprintf(sUsage+l," %s",pTemp->sName);
		pTemp=pTemp->pNext;
	}	
}
int CheckParamValid(char sParamName[],char sValue[])
{
	return 0;
}
int CheckCmdStr(struct CmdProcStruct *pCmd,char sInput[1024],char sMsg[256])
{
	int l=0;
	char	sOutput[256];
	struct CmdProcStruct *ptHead=NULL;
	struct CmdParamStruct *pStd,*pCur;

	strcpy(sMsg,"");

	GetTabStr(sInput,0,sOutput);
	if(strlen(sOutput)==0){
		sprintf(sMsg,"在请求%s中无命令",sInput);
		return -1;
	}

	if(SearchCmd(pCmd,sOutput,&ptHead)==NOTFOUND){
		sprintf(sMsg,"命令%s在系统中未注册",sOutput);
		return -1;
	}
	pStd=ptHead->pHead;
	pCur=GetCmdParam(sInput);

	if(CountList((LIST*)pCur)!=CountList((LIST*)pStd)){
		l+=sprintf(sMsg,"参数个数错误.\n");
		PrintUsage(ptHead,sMsg+l);
		DestroyList((LIST*)pCur);
		return -1;
	}
	
	while(pStd!=NULL){
		if(CheckParamValid(pStd->sName,pCur->sName)<0){
			sprintf(sMsg,"参数%s的数值%s无效",
				pStd->sName,pCur->sName);
			DestroyList((LIST*)pCur);
			return -1;
		}
		strcpy(pStd->sValue,pCur->sName);
		pStd=pStd->pNext;
		pCur=pCur->pNext;
	}
	DestroyList((LIST*)pCur);
	return 0;
}

int GetCmdLine()
{
	return 0;
}
int CheckCmdLine()
{
	return 0;
}
int ProcCmdLine()
{
	return 0;
}
int ReturnCmdLine()
{
	return 0;
}

int i_createuser(int d1,int r)
{
	int l;
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);

	bzero((void*)&gUsr,sizeof(struct UserStruct));
		
	strcpy(gUsr.sMsisdn,p1);
	strcpy(gUsr.sImsi,p2);
	strcpy(gUsr.sEsn,p3);
	
	l=sprintf(gUsr.sMsg,"对");
	
	if(strlen(gUsr.sMsisdn)!=0)
		l+=sprintf(gUsr.sMsg+l,"号码为%s ",gUsr.sMsisdn);
	if(strlen(gUsr.sImsi)!=0)
		l+=sprintf(gUsr.sMsg+l,"IMSI为%s ",gUsr.sImsi);
	if(strlen(gUsr.sEsn)!=0) 
		l+=sprintf(gUsr.sMsg+l,"ESN为%s ",gUsr.sEsn);
	
	sprintf(gUsr.sMsg+l,"用户 开户成功.");
	
	
	return 0;
}
void RegCmdExprFun()
{
RegFunItem("开户",	i_createuser,	"222",'1','f');
RegFunItem("createuser",i_createuser,	"222",'1','f');
}
void Hehehe()
{
#ifdef AAAAA
	GetCmdLine();	/*获取命令*/
	CheckCmdLine();	/*检查命令*/
	ProcCmdLine();	/*处理命令*/
	ReturnCmdLine();	/*结果返回*/
#endif
}
int on_client_write(struct TcpClientStruct *ptHead)
{
	char sInput[1024];
	static int iFirstFlag=true,n,l,i,iRet;
	struct OutputBufStruct asVarOutput[SYSVAR_COUNT];
		
	printf("client write event arrive.\n");
	
	if(iFirstFlag==true){
		RegCmdExprFun();
		iFirstFlag=false;
	}

	n=wwfdgets(sInput,1024,ptHead->iSockFd);
	if(n<=0) return 0;
	
	printf("receive msg=%s,%d.\n",sInput,n);
	
	if((i=CompileExpr(sInput,asVarOutput,&l))>=0){
		
		if((iRet=ExecCode(pExprBuf))<0)
			sprintf(gUsr.sMsg,"执行公式错误\n");
	}
	else{
		sprintf(gUsr.sMsg,"编译公式错误::\n%s\n",
			pExprBuf->sErrorMsg);
	}
	DisplaySymbolFlow();
	DisplayCode();
	printf("the bak msg=%s,i=%d.\n",gUsr.sMsg,i);
	
	if(n>0){
		write(ptHead->iSockFd,gUsr.sMsg,strlen(gUsr.sMsg));
	}

	return n;
}
int my_child_start()
{
	return IniConnect("dataconnstr");
}
int my_child_end()
{
	DisconnectDatabase();
	return 0;
}
void my_initial_client(struct TcpClientStruct *ptHead)
{
	ptHead->OnTimeOut	=NULL;
	ptHead->OnConnectAuth	=NULL;
	ptHead->OnDataRecv	=on_client_write;
	ptHead->OnDataSend	=NULL;
	ptHead->OnConnect	=my_child_start;
	ptHead->OnDisconnect	=my_child_end;
}


int main()
{
	struct TcpServerStruct *pServer=NULL;
	
	pServer=CreateTcpServer(7788,false,5,3,	NULL,my_initial_client);
	
	TcpServerRun(pServer);
	
	return 0;
}
