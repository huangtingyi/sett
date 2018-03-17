#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <list.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <param_intf.h>

#include <cmdsupp.h>
#include <intfcmd.h>

/*转换命令*/
int TranslateCmd(struct CmdTemplateStruct *pTemplate,
	struct IntfCmdStruct *p,struct SwitchStruct *ptHead,char sMsg[])
{
	FILE *fp;
	int iRet,l;
	char *env,sInput[257];
	char sPath[128],sCmdOut[256],sExecName[256],sCmd[1024];
	
	strcpy(sMsg,"");
	
        if((env=getenv("BILLHOME"))==NULL)
                strcpy(sPath,"/home/bill/");
        else
                strcpy(sPath,env);
        
	RegularDir(sPath);
	
	sprintf(sCmdOut,"%swork/cmdout%d.txt",sPath,getpid());
	sprintf(sExecName,"%sbin/%s",sPath,pTemplate->sCmdText);

/*调用命令转换结果输出*/
	sprintf(sCmd,"%s %s %s \"%s\" %s",
		sExecName,p->sCmdType,ptHead->sAreaCode,
		p->sStdInfoLine,sCmdOut);
	if((iRet=system(sCmd))!=0){
		sprintf(sMsg,"执行失败:代码:%d",iRet);
		return -1;
	}
/*检查输出结果*/
	if(IsFile(sCmdOut)||(l=FileSize(sCmdOut))<=0){
		sprintf(sMsg,"脚本命令无输出");
		return -1;
	}
	if(l>256){
		sprintf(sMsg,"脚本命令无输出文件太大%d>256",l);
		return -1;
	}
/*将输出的文件读到sInput中*/
	if((fp=fopen(sCmdOut,"r"))==NULL){
		sprintf(sMsg,"打开文件%s失败",sCmdOut);
		return -1;
	}
	if(fread(sInput,l,1,fp)!=1){
		sprintf(sMsg,"读文件%s失败",sCmdOut);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);

/*将文的输出转换到p->sCmdLine中*/
	strcpy(p->sCmdLine,sInput);
	
	return 0;
}
/*检查指令的合法性，并填写SwitchID,并生成交换机指令*/
int CheckCmd(struct IntfCmdStruct *p)
{
	char sMsg[128];
	struct NbrHeadStruct *pNbrHead=NULL;
	struct SwitchStruct *ptHead=NULL;
	struct CmdTemplateStruct *pCmdTemplate=NULL;
	
	if(strlen(p->sMsisdn)==0&&strlen(p->sImsi)==0){
		strcpy(p->sBackLine,"指令的MSISDN和IMSI都为空");
		return -1;
	}
	if(strlen(p->sMsisdn)!=0){
		if(SearchNbrHead(p->sServiceType,"ACCNBR",p->sMsisdn,
			&pNbrHead)==NOTFOUND){
			sprintf(p->sBackLine,
				"指令业务%s,号码%s在号段表中不存在",
				p->sServiceType,p->sMsisdn);
			return -1;
		}
	}
	else{
		if(SearchNbrHead(p->sServiceType,"IMSI",p->sImsi,
			&pNbrHead)==NOTFOUND){
			sprintf(p->sBackLine,
				"指令业务%s,IMSI %s在号段表中不存在",
				p->sServiceType,p->sImsi);
			return -1;
		}
	}
	p->iSwitchID=pNbrHead->iSwitchID;

/*如果指定命令已经转换过了就不要转换了*/
	if(strlen(p->sCmdLine)!=0){
		p->iModify=false;
		return 0;
	}
/*命令发生变化,提示将命令体更新到数据库*/
	p->iModify=true;

/*找到对应的交换机*/
	SearchSwitch(&ptHead);
	
	while(ptHead!=NULL){
		if(p->iSwitchID==ptHead->iSwitchID) break;
		ptHead=ptHead->pNext;
	}
	if(ptHead==NULL){
		sprintf(p->sBackLine,
			"指令业务%s,号码%s,交换机%d标识在交换机表中不存在",
			p->sServiceType,p->sMsisdn,p->iSwitchID);
		return -1;
	}
/*找工单命令*/
	if(SearchCmdTemplate(ptHead->iTypeID,p->sCmdType,
		&pCmdTemplate)==NOTFOUND){
		sprintf(p->sBackLine,
			"交换机类型%d,业务类型%s的命令模版没有配置",
			ptHead->iTypeID,p->sCmdType);
		return -1;
	}
/*调用函数将命令转换*/
	if(TranslateCmd(pCmdTemplate,p,ptHead,sMsg)<0){
		sprintf(p->sBackLine,"用脚本%s转换%s命令失败,参数%s 消息:%s",
			pCmdTemplate->sCmdText,
			p->sCmdType,p->sStdInfoLine,sMsg);
		return -1;
	}
	return 0;
}
int SearchStatSwitch(struct SwitchStatStruct *ptHead,int iSwitchID,
	struct SwitchStatStruct **pptCur)
{
	*pptCur=NULL;
	
	while(ptHead!=NULL){
		if(iSwitchID==ptHead->iSwitchID){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
int comp_command_msisdn_imsi(LIST *pData,LIST *ptHead)
{
	int res;
	
	struct IntfCmdStruct *pSource=(struct IntfCmdStruct *)pData;
	struct IntfCmdStruct *pTarget=(struct IntfCmdStruct *)ptHead;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	return strcmp(pSource->sImsi,pTarget->sImsi);
}
void summ_command_msisdn_list(LIST *ptHead,LIST *pData)
{
	struct IntfCmdStruct *pSource=(struct IntfCmdStruct *)pData;
	struct IntfCmdStruct *pTarget=(struct IntfCmdStruct *)ptHead;
	
	pSource->pLoadNext=pTarget->pLoadNext;
	pTarget->pLoadNext=pSource;
}
int AddCmdToSwitchStatList(struct IntfCmdStruct *p,
	struct SwitchStatStruct **pptHead)
{
	struct SwitchStatStruct *pTemp=NULL;
	
	if(SearchStatSwitch(*pptHead,p->iSwitchID,&pTemp)==NOTFOUND){
		if((pTemp=(struct SwitchStatStruct*)
			malloc(sizeof(struct SwitchStatStruct)))==NULL)
			return -1;
		bzero((void*)pTemp,sizeof(struct SwitchStatStruct));
	}
	p->pNext=NULL;
	p->pLoadNext=NULL;
	InsertListSumm((LIST**)&(pTemp->pHead),(LIST*)p,
		comp_command_msisdn_imsi,
		summ_command_msisdn_list);
	return 0;
}
/*将数据库中的命令添加到pSwichStatList中,还没有判断工单排斥关系*/
int CreateSwitchStatList(struct IntfCmdStruct *pList,
	struct SwitchStatStruct **pptHead)
{
	struct SwitchStatStruct *ptHead=NULL;
	struct IntfCmdStruct *ptPre,*ptCur;
	static struct IntfCmdStructUp TempUp;
	
	strcpy(TempUp.sTableName,"INTF_CMD");
	
	*pptHead=NULL;
	
	ptCur=pList;
	while(ptCur!=NULL){
		
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
/*检查指令的合法性，并填写SwichID*/
		if(CheckCmd(ptPre)<0){
			strcpy(ptPre->sState,COMMAND_STATE_FAIL);
			if(EUpdateStructToUIntfCmd(ptPre,false,&TempUp)<0){
				WriteAlertMsg("更新数据库INTF_CMD错误");
				return -1;
			}
/*将指定命令从链表中删除并释放内存*/
			/**DeleteList((LIST**)&pList,(LIST*)ptPre);**/
			free(ptPre);
			continue;
		}
/*将命令添加到SwitchStatList中*/
		if(AddCmdToSwitchStatList(ptPre,&ptHead)<0){
			WriteAlertMsg("将工单加入统计链表失败");
			return -1;
		}
	}
	
	if(EUpdateStructToUIntfCmd(NULL,true,&TempUp)<0){
		WriteAlertMsg("更新数据库INTF_CMD错误");
		return -1;
	}
/*提交任务*/
	CommitWork();
	
	*pptHead=ptHead;
	
	return 0;
}
void DestroySwitchStat(struct SwitchStatStruct *ptHead)
{
	struct SwitchStatStruct *pTemp;
	struct IntfCmdStruct *pPre,*pCur;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		pCur=pTemp->pHead;
		while(pCur!=NULL){
			pPre=pCur;
			pCur=pCur->pNext;
			free(pCur);			
		}
		free(pTemp);
	}
}
int CountIntfCmdLoad(struct IntfCmdStruct *ptHead)
{
	int iCnt=0;
	while(ptHead!=NULL){
		iCnt++;
		ptHead=ptHead->pLoadNext;
	}
	return iCnt;
}
/*根据iFreeCmdCnt,到ptHead中取下改交换机的N个工单放到链表中*/
struct IntfCmdStruct *GetCmdOrdList(int iFreeCmdCnt,
	int iSwitchID,struct SwitchStatStruct *ptHead)
{
	int	iTempCnt=iFreeCmdCnt;
	struct IntfCmdStruct *ptLkHead=NULL,*pPre,*pCur;
/*查找交换机*/
	while(ptHead!=NULL){
		if(iSwitchID==ptHead->iSwitchID) break;
		ptHead=ptHead->pNext;
	}
/*如果没有指定交换机则无工单*/
	if(ptHead==NULL) return NULL;
	if(ptHead->pHead==NULL) return NULL;/*KKK*/
/*如果有指定交换机工单，且工单比缓冲区小则直接返回*/
	if(iFreeCmdCnt>=ptHead->iFreeCmdCnt){
		ptLkHead=ptHead->pHead;
		ptHead->pHead=NULL;
		return ptLkHead;
	}
/*工单比缓冲区大，一般很少会出现这种情况*/
/*截取前N个工单链表*/
	pCur=ptHead->pHead;
	while(pCur!=NULL){
		/*一定会执行到这里，因为有KKK这一条语句*/
		pPre=pCur;
		pCur=pCur->pNext;
		iTempCnt-=CountIntfCmdLoad(pPre);
		if(iTempCnt<0) break;
	}
/*将剩余的工单留在原链表中*/
	pCur=ptHead->pHead;
	ptHead->pHead=pPre;

/*将链表表头截出，并将剩余部分截断*/
	ptLkHead=pCur;
	while(pCur->pNext!=NULL){
		if(pCur->pNext==pPre){
			pCur->pNext=NULL;
			break;
		}
		pCur=pCur->pNext;
	}
	
	return ptLkHead;
}
void MoveCmd2FreeStat(struct SwitchStatStruct *pSource,
	struct SwitchStatStruct *pTarget)
{
	struct SwitchStatStruct *ptHead,*pTemp;
	
	ptHead=pTarget;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		pTemp->pHead=GetCmdOrdList(
			pTemp->iFreeCmdCnt,pTemp->iSwitchID,pSource);
	}
}
int SearchIAgent(int iSwitchID,POINTER ioffHead,struct IAgentStruct **pptCur)
{
	struct IAgentStruct *pTemp;
	
	if(ioffHead!=-1){
		pTemp=(struct IAgentStruct *)OPSHMCMD(ioffHead);
		if(iSwitchID==pTemp->iSwitchID){
			*pptCur=pTemp;
			return FOUND;
		}
		ioffHead=OONXTSHMCMD(ioffHead);
	}
	return NOTFOUND;
}
void AddIntfCmd2Shm(struct IntfCmdStruct *ptHead,
	struct IAgentStruct *pAgent)
{
	POINTER ioffNew;
	struct IntfCmdStruct	*pTemp,*ptPre,*ptCur;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		ptCur=pTemp;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pLoadNext;
			
			if(strcmp(ptPre->sState,COMMAND_STATE_NEW)!=0)
				continue;
/*从共享内存的空闲链表中取出一个节点*/
			ioffNew=PSHMCMD->IntfCmd.ioffFree;
			if(ioffNew==-1){WriteAlertMsg("程序逻辑错误");exit(1);}
			PSHMCMD->IntfCmd.ioffFree=OONXTSHMCMD(ioffNew);
			PSHMCMD->IntfCmd.iUsedCnt++;
			pAgent->iCmdCnt++;
/*初始化这个节点，并赋值*/
			mvitem_intf2i(ptPre,(struct IIntfCmdStruct *)
				OPSHMCMD(ioffNew));
/*将这个节点加到缓冲链表末尾*/
			INSERT_SHMCMD_LIST_TAIL(&(pAgent->ioffCmd),ioffNew);
/*设置工单状态为已加入共享内存*/
			strcpy(ptPre->sState,COMMAND_STATE_IN);
		}
	}
}       
void MoveFreeStat2Shm(struct SwitchStatStruct *pFreeStat)
{       
	struct IAgentStruct *pAgent;
	struct SwitchStatStruct *ptHead,*pTemp;
        
	
	ptHead=pFreeStat;
	
	while(ptHead!=NULL){
        
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(SearchIAgent(pTemp->iSwitchID,PSHMCMD->ioffAgent,
			&pAgent)!=FOUND) continue;/*一般不会运行到这*/
		
		AddIntfCmd2Shm(pTemp->pHead,pAgent);
	}
}
/*针对一个用户的工单排斥*/
void MutexCmd(struct IntfCmdStruct **pptHead)
{
	/*暂时没有添加排斥关系*/
}
/*对一个交换机的工单排斥*/
void MutexCmdInMem(struct SwitchStatStruct *ptHead)
{
	struct SwitchStatStruct *pTemp;
	
	struct IntfCmdStruct *ptPre,*ptCur;

	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		ptCur=pTemp->pHead;
		pTemp->pHead=NULL;
		
		while(ptCur!=NULL){
		
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			MutexCmd(&ptPre);
			
			InsertList((LIST**)&(pTemp->pHead),(LIST*)ptPre);
		}
	}
}
/*将工单状态更新到数据库*/
int UpdateIntfCmdState(struct SwitchStatStruct *ptHead)
{
	static struct IntfCmdStructUp TempUp;
	
	struct SwitchStatStruct *pTemp;
	struct IntfCmdStruct *ptPre,*ptCur;
	
	strcpy(TempUp.sTableName,"INTF_CMD");
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		ptCur=pTemp->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			while(ptPre!=NULL){
				if(strcmp(ptPre->sState,COMMAND_STATE_NEW)==0&&
					ptPre->iModify==false){
					ptPre=ptPre->pLoadNext;
					continue;
				}
				if(EUpdateStructToUIntfCmd(ptPre,false,&TempUp)<0)
					return -1;
				
				ptPre=ptPre->pLoadNext;
			}
		}
	}
	if(EUpdateStructToUIntfCmd(NULL,true,&TempUp)<0)
		return -1;
	CommitWork();
	
	return 0;
}
/*判断共享内存工单是否满了*/
int  ShmCmdBufIsFull()
{
	POINTER ioffHead=PSHMCMD->ioffAgent;
	struct IAgentStruct *pAgent=NULL;
	
	while(ioffHead!=-1){

		pAgent=(struct IAgentStruct *)OPSHMCMD(ioffHead);
/*只要有一个交换机的缓冲区不满就不满*/
		if(pAgent->iCmdBufLen>pAgent->iCmdCnt) return false;
		
		ioffHead=OONXTSHMCMD(ioffHead);
	}
	return true;
}
void ProcCmd()
{
	struct SwitchStatStruct *pFreeStat=NULL,*pCmdStat=NULL;
	struct IntfCmdStruct *ptHead=NULL;
	
	if(ShmCmdBufIsFull()){
		WriteProcMsg("共享内存工单满了");
		return;
	}
	if(InitIntfCmd(&ptHead,"WHERE STATE='I0N'")<0){
		WriteAlertMsg("从数据库总取工单数据失败");
		exit(1);
	}
/*如果没有工单数据就不处理了*/
	if(ptHead==NULL) return;
	
/*从数据库加载工单到本地失败*/
	if(CreateSwitchStatList(ptHead,&pCmdStat)<0){
		WriteAlertMsg("从数据库加载工单到本地失败");
		exit(1);
	}
/*对共享内存加锁*/
	LockCmdShm();
/*将本地工单加到共享内存*/

	/*取共享内存空闲工单链表,pFree*/
	if((pFreeStat=GetSwitchStatList())==NULL){
		WriteAlertMsg("生成pFree链表失败");
		UnlockCmdShm();
		exit(1);
	}
/*对每个交换机取出时间最早的N个用户的工单，FreeCmdCnt工单数*/
	MoveCmd2FreeStat(pCmdStat,pFreeStat);
/*依次查看每个号码的工单，判断排斥关系,设置工单状态*/
	MutexCmdInMem(pFreeStat);

/*将这些工单移到共享内存中*/
	MoveFreeStat2Shm(pFreeStat);
	
/*将共享内存解锁*/
	UnlockCmdShm();

/*将已经转换工单信息更新到数据库，下一次取就不需要转换了*/
	if(UpdateIntfCmdState(pCmdStat)<0){
		DestroySwitchStat(pFreeStat);
		WriteAlertMsg("将工单状态更新到数据库");
		exit(1);
	}
/*释放调pCmdStat中的内存*/
	DestroySwitchStat(pCmdStat);

/*将已经加入共享内存、被排斥等的工单更新回数据库*/
	if(UpdateIntfCmdState(pFreeStat)<0){
		DestroySwitchStat(pFreeStat);
		WriteAlertMsg("将工单状态更新到数据库");
		exit(1);
	}
	DestroySwitchStat(pFreeStat);
}
int ProcCmdMain()
{
	int iAdaptEvent;
	
/*将待处理的事件取出*/
	iAdaptEvent=PSHMCMD->iCmdAdaptEvent;
	PSHMCMD->iCmdAdaptEvent=0;
	
	if((iAdaptEvent|ADAPT_DATA_REACH)!=0)	ProcCmd();
		
	if(PSHMCMD->iCmdAdaptEvent!=0) return true;

	return false;
}
void ProcSendCmd()
{
	static int iFlag=false;
	static char sLastTime[15],sCurTime[15];

	if(iFlag==true) return;/*简单的方式不允许重入*/
	iFlag=true;
	
/*最大响应事件是1秒一次*/
	if(tGetTime(sCurTime)-tGetTime(sLastTime)==0) return;
	
	iFlag=true;

/*如果处理完了还继续有事件就继续处理*/	
	while(1){
		if(ProcCmdMain()==false) break;
		
		/*确保最大响应时间不应超过3秒*/
		GetHostTime(sCurTime);
		if(tGetTime(sCurTime)-tGetTime(sLastTime)>2) break;
	}

	GetHostTime(sLastTime);
	
	iFlag=false;
}
/*将pAgent->icurCmd链表数据移到本地链表，并将pAgent链表插入到ifreeCmd中*/
int IntfCmdBackShm2List(struct IAgentStruct *pAgent,
	struct IntfCmdStruct **pptHead)
{	
	POINTER ioffTmp;
	struct IntfCmdStruct *ptHead=NULL,*pTemp;
	
	*pptHead=NULL;

	LockAgent(pAgent);
	
	ioffTmp=pAgent->icurCmd;
	while(ioffTmp!=-1){
		
		if((pTemp=(struct IntfCmdStruct*)malloc(
			sizeof(struct IntfCmdStruct)))==NULL){

			WriteAlertMsg("分配IntfCmd内存失败");
			UnlockAgent(pAgent);
			return -1;
		}
		mvitem_intf2m((struct IIntfCmdStruct *)
			OPSHMCMD(ioffTmp),pTemp);
		InsertList((LIST**)&ptHead,(LIST*)pTemp);
		
		INSERT_SHMCMD_LIST(&(PSHMCMD->IntfCmd.ioffFree),ioffTmp);
		PSHMCMD->IntfCmd.iUsedCnt--;
		DELETE_SHMCMD_LIST(&(pAgent->icurCmd),ioffTmp);
		pAgent->iCmdCnt--;
		
		ioffTmp=pAgent->icurCmd;
	}
	
	UnlockAgent(pAgent);
	
	*pptHead=ptHead;
	return 0;
}
void ProcBackCmd()
{
	POINTER ioffHead=PSHMCMD->ioffAgent;
	struct IAgentStruct *pTemp;
	struct IntfCmdStruct *ptPre=NULL,*ptCur=NULL;
	
	static struct IntfCmdStructUp TempUp;
	
	strcpy(TempUp.sTableName,"INTF_CMD");

	while(ioffHead!=-1){

		pTemp=(struct IAgentStruct *)OPSHMCMD(ioffHead);

		if(IntfCmdBackShm2List(pTemp,&ptPre)<0){
			WriteAlertMsg("IntfCmdBackShm2List调用错误");
			exit(1);
		}
		ptCur=ptPre;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			if(EUpdateStructToUIntfCmd(ptPre,false,&TempUp)<0){
				WriteAlertMsg("更新INTF_CMD表错误");
				exit(1);
			}
			free(ptPre);/*释放内存*/
		}
		
		ioffHead=OONXTSHMCMD(ioffHead);
	}
	if(EUpdateStructToUIntfCmd(NULL,true,&TempUp)<0){
		WriteAlertMsg("更新INTF_CMD表错误");
		exit(1);
	}
	CommitWork();
	
}
int main(int argc,char *argv[])
{
	int iFullFlag=false;
	
/*检查是否需要强制更新，有则直接将共享内存删除*/
	if(argc!=1&&argc!=2){
		printf("Usage :%s [-f].\n",argv[0]);
		return -1;
	}
	
	if(argc==2){
		if(strcmp(argv[1],"-f")==0) iFullFlag=true;
	}
	if(iFullFlag==true){
		
		int iShmKey;
		
		if((iShmKey= GetCmdShmKey())<0){
			printf("获取共享内存KEY失败.\n");
			return -1;
		}
		DestroyShm(iShmKey);
	}
/*建立共享内存或者更新*/
	if(ConnectCmdShmAndInitMem()<0){
		if(BuildCmdShmInit()<0){
			printf("完全更新命令服务共享内存失败.\n");
			return -1;
		}
	}
	else{
		if(IsCmdServRun()==true){
			printf("CmdServer程序还继续在运行.\n");
			return -1;
		}
		
		if(IncreaseCmdShmInit()<0){
			DetachShm((void*)PSHMCMD);
			if(BuildCmdShmInit()<0){
				printf("完全更新命令服务共享内存失败.\n");
				return -1;
			}
		}
	}
/*到这里共享内存都建立了,Mem是挂在共享内存的本地结构pShm指向共享内存*/
	InitAppRes(argv[0]);
	if(IniConnect("dataconnstr")<0) return -1;
		 
/*进行主循环心跳*/

	while(1){
		usleep(100);
		/*将回执的命令更新到数据库*/
		ProcBackCmd();
		/*将命令转换为指定格式发给Agent*/
		ProcSendCmd();

		HeartBeatServer();
	}
	
	CommitWorkRelease();

	return 0;
}
