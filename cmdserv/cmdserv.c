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

/*ת������*/
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

/*��������ת��������*/
	sprintf(sCmd,"%s %s %s \"%s\" %s",
		sExecName,p->sCmdType,ptHead->sAreaCode,
		p->sStdInfoLine,sCmdOut);
	if((iRet=system(sCmd))!=0){
		sprintf(sMsg,"ִ��ʧ��:����:%d",iRet);
		return -1;
	}
/*���������*/
	if(IsFile(sCmdOut)||(l=FileSize(sCmdOut))<=0){
		sprintf(sMsg,"�ű����������");
		return -1;
	}
	if(l>256){
		sprintf(sMsg,"�ű�����������ļ�̫��%d>256",l);
		return -1;
	}
/*��������ļ�����sInput��*/
	if((fp=fopen(sCmdOut,"r"))==NULL){
		sprintf(sMsg,"���ļ�%sʧ��",sCmdOut);
		return -1;
	}
	if(fread(sInput,l,1,fp)!=1){
		sprintf(sMsg,"���ļ�%sʧ��",sCmdOut);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);

/*���ĵ����ת����p->sCmdLine��*/
	strcpy(p->sCmdLine,sInput);
	
	return 0;
}
/*���ָ��ĺϷ��ԣ�����дSwitchID,�����ɽ�����ָ��*/
int CheckCmd(struct IntfCmdStruct *p)
{
	char sMsg[128];
	struct NbrHeadStruct *pNbrHead=NULL;
	struct SwitchStruct *ptHead=NULL;
	struct CmdTemplateStruct *pCmdTemplate=NULL;
	
	if(strlen(p->sMsisdn)==0&&strlen(p->sImsi)==0){
		strcpy(p->sBackLine,"ָ���MSISDN��IMSI��Ϊ��");
		return -1;
	}
	if(strlen(p->sMsisdn)!=0){
		if(SearchNbrHead(p->sServiceType,"ACCNBR",p->sMsisdn,
			&pNbrHead)==NOTFOUND){
			sprintf(p->sBackLine,
				"ָ��ҵ��%s,����%s�ںŶα��в�����",
				p->sServiceType,p->sMsisdn);
			return -1;
		}
	}
	else{
		if(SearchNbrHead(p->sServiceType,"IMSI",p->sImsi,
			&pNbrHead)==NOTFOUND){
			sprintf(p->sBackLine,
				"ָ��ҵ��%s,IMSI %s�ںŶα��в�����",
				p->sServiceType,p->sImsi);
			return -1;
		}
	}
	p->iSwitchID=pNbrHead->iSwitchID;

/*���ָ�������Ѿ�ת�����˾Ͳ�Ҫת����*/
	if(strlen(p->sCmdLine)!=0){
		p->iModify=false;
		return 0;
	}
/*������仯,��ʾ����������µ����ݿ�*/
	p->iModify=true;

/*�ҵ���Ӧ�Ľ�����*/
	SearchSwitch(&ptHead);
	
	while(ptHead!=NULL){
		if(p->iSwitchID==ptHead->iSwitchID) break;
		ptHead=ptHead->pNext;
	}
	if(ptHead==NULL){
		sprintf(p->sBackLine,
			"ָ��ҵ��%s,����%s,������%d��ʶ�ڽ��������в�����",
			p->sServiceType,p->sMsisdn,p->iSwitchID);
		return -1;
	}
/*�ҹ�������*/
	if(SearchCmdTemplate(ptHead->iTypeID,p->sCmdType,
		&pCmdTemplate)==NOTFOUND){
		sprintf(p->sBackLine,
			"����������%d,ҵ������%s������ģ��û������",
			ptHead->iTypeID,p->sCmdType);
		return -1;
	}
/*���ú���������ת��*/
	if(TranslateCmd(pCmdTemplate,p,ptHead,sMsg)<0){
		sprintf(p->sBackLine,"�ýű�%sת��%s����ʧ��,����%s ��Ϣ:%s",
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
/*�����ݿ��е�������ӵ�pSwichStatList��,��û���жϹ����ų��ϵ*/
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
		
/*���ָ��ĺϷ��ԣ�����дSwichID*/
		if(CheckCmd(ptPre)<0){
			strcpy(ptPre->sState,COMMAND_STATE_FAIL);
			if(EUpdateStructToUIntfCmd(ptPre,false,&TempUp)<0){
				WriteAlertMsg("�������ݿ�INTF_CMD����");
				return -1;
			}
/*��ָ�������������ɾ�����ͷ��ڴ�*/
			/**DeleteList((LIST**)&pList,(LIST*)ptPre);**/
			free(ptPre);
			continue;
		}
/*��������ӵ�SwitchStatList��*/
		if(AddCmdToSwitchStatList(ptPre,&ptHead)<0){
			WriteAlertMsg("����������ͳ������ʧ��");
			return -1;
		}
	}
	
	if(EUpdateStructToUIntfCmd(NULL,true,&TempUp)<0){
		WriteAlertMsg("�������ݿ�INTF_CMD����");
		return -1;
	}
/*�ύ����*/
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
/*����iFreeCmdCnt,��ptHead��ȡ�¸Ľ�������N�������ŵ�������*/
struct IntfCmdStruct *GetCmdOrdList(int iFreeCmdCnt,
	int iSwitchID,struct SwitchStatStruct *ptHead)
{
	int	iTempCnt=iFreeCmdCnt;
	struct IntfCmdStruct *ptLkHead=NULL,*pPre,*pCur;
/*���ҽ�����*/
	while(ptHead!=NULL){
		if(iSwitchID==ptHead->iSwitchID) break;
		ptHead=ptHead->pNext;
	}
/*���û��ָ�����������޹���*/
	if(ptHead==NULL) return NULL;
	if(ptHead->pHead==NULL) return NULL;/*KKK*/
/*�����ָ���������������ҹ����Ȼ�����С��ֱ�ӷ���*/
	if(iFreeCmdCnt>=ptHead->iFreeCmdCnt){
		ptLkHead=ptHead->pHead;
		ptHead->pHead=NULL;
		return ptLkHead;
	}
/*�����Ȼ�������һ����ٻ�����������*/
/*��ȡǰN����������*/
	pCur=ptHead->pHead;
	while(pCur!=NULL){
		/*һ����ִ�е������Ϊ��KKK��һ�����*/
		pPre=pCur;
		pCur=pCur->pNext;
		iTempCnt-=CountIntfCmdLoad(pPre);
		if(iTempCnt<0) break;
	}
/*��ʣ��Ĺ�������ԭ������*/
	pCur=ptHead->pHead;
	ptHead->pHead=pPre;

/*�������ͷ�س�������ʣ�ಿ�ֽض�*/
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
/*�ӹ����ڴ�Ŀ���������ȡ��һ���ڵ�*/
			ioffNew=PSHMCMD->IntfCmd.ioffFree;
			if(ioffNew==-1){WriteAlertMsg("�����߼�����");exit(1);}
			PSHMCMD->IntfCmd.ioffFree=OONXTSHMCMD(ioffNew);
			PSHMCMD->IntfCmd.iUsedCnt++;
			pAgent->iCmdCnt++;
/*��ʼ������ڵ㣬����ֵ*/
			mvitem_intf2i(ptPre,(struct IIntfCmdStruct *)
				OPSHMCMD(ioffNew));
/*������ڵ�ӵ���������ĩβ*/
			INSERT_SHMCMD_LIST_TAIL(&(pAgent->ioffCmd),ioffNew);
/*���ù���״̬Ϊ�Ѽ��빲���ڴ�*/
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
			&pAgent)!=FOUND) continue;/*һ�㲻�����е���*/
		
		AddIntfCmd2Shm(pTemp->pHead,pAgent);
	}
}
/*���һ���û��Ĺ����ų�*/
void MutexCmd(struct IntfCmdStruct **pptHead)
{
	/*��ʱû������ų��ϵ*/
}
/*��һ���������Ĺ����ų�*/
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
/*������״̬���µ����ݿ�*/
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
/*�жϹ����ڴ湤���Ƿ�����*/
int  ShmCmdBufIsFull()
{
	POINTER ioffHead=PSHMCMD->ioffAgent;
	struct IAgentStruct *pAgent=NULL;
	
	while(ioffHead!=-1){

		pAgent=(struct IAgentStruct *)OPSHMCMD(ioffHead);
/*ֻҪ��һ���������Ļ����������Ͳ���*/
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
		WriteProcMsg("�����ڴ湤������");
		return;
	}
	if(InitIntfCmd(&ptHead,"WHERE STATE='I0N'")<0){
		WriteAlertMsg("�����ݿ���ȡ��������ʧ��");
		exit(1);
	}
/*���û�й������ݾͲ�������*/
	if(ptHead==NULL) return;
	
/*�����ݿ���ع���������ʧ��*/
	if(CreateSwitchStatList(ptHead,&pCmdStat)<0){
		WriteAlertMsg("�����ݿ���ع���������ʧ��");
		exit(1);
	}
/*�Թ����ڴ����*/
	LockCmdShm();
/*�����ع����ӵ������ڴ�*/

	/*ȡ�����ڴ���й�������,pFree*/
	if((pFreeStat=GetSwitchStatList())==NULL){
		WriteAlertMsg("����pFree����ʧ��");
		UnlockCmdShm();
		exit(1);
	}
/*��ÿ��������ȡ��ʱ�������N���û��Ĺ�����FreeCmdCnt������*/
	MoveCmd2FreeStat(pCmdStat,pFreeStat);
/*���β鿴ÿ������Ĺ������ж��ų��ϵ,���ù���״̬*/
	MutexCmdInMem(pFreeStat);

/*����Щ�����Ƶ������ڴ���*/
	MoveFreeStat2Shm(pFreeStat);
	
/*�������ڴ����*/
	UnlockCmdShm();

/*���Ѿ�ת��������Ϣ���µ����ݿ⣬��һ��ȡ�Ͳ���Ҫת����*/
	if(UpdateIntfCmdState(pCmdStat)<0){
		DestroySwitchStat(pFreeStat);
		WriteAlertMsg("������״̬���µ����ݿ�");
		exit(1);
	}
/*�ͷŵ�pCmdStat�е��ڴ�*/
	DestroySwitchStat(pCmdStat);

/*���Ѿ����빲���ڴ桢���ų�ȵĹ������»����ݿ�*/
	if(UpdateIntfCmdState(pFreeStat)<0){
		DestroySwitchStat(pFreeStat);
		WriteAlertMsg("������״̬���µ����ݿ�");
		exit(1);
	}
	DestroySwitchStat(pFreeStat);
}
int ProcCmdMain()
{
	int iAdaptEvent;
	
/*����������¼�ȡ��*/
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

	if(iFlag==true) return;/*�򵥵ķ�ʽ����������*/
	iFlag=true;
	
/*�����Ӧ�¼���1��һ��*/
	if(tGetTime(sCurTime)-tGetTime(sLastTime)==0) return;
	
	iFlag=true;

/*����������˻��������¼��ͼ�������*/	
	while(1){
		if(ProcCmdMain()==false) break;
		
		/*ȷ�������Ӧʱ�䲻Ӧ����3��*/
		GetHostTime(sCurTime);
		if(tGetTime(sCurTime)-tGetTime(sLastTime)>2) break;
	}

	GetHostTime(sLastTime);
	
	iFlag=false;
}
/*��pAgent->icurCmd���������Ƶ�������������pAgent������뵽ifreeCmd��*/
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

			WriteAlertMsg("����IntfCmd�ڴ�ʧ��");
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
			WriteAlertMsg("IntfCmdBackShm2List���ô���");
			exit(1);
		}
		ptCur=ptPre;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			if(EUpdateStructToUIntfCmd(ptPre,false,&TempUp)<0){
				WriteAlertMsg("����INTF_CMD�����");
				exit(1);
			}
			free(ptPre);/*�ͷ��ڴ�*/
		}
		
		ioffHead=OONXTSHMCMD(ioffHead);
	}
	if(EUpdateStructToUIntfCmd(NULL,true,&TempUp)<0){
		WriteAlertMsg("����INTF_CMD�����");
		exit(1);
	}
	CommitWork();
	
}
int main(int argc,char *argv[])
{
	int iFullFlag=false;
	
/*����Ƿ���Ҫǿ�Ƹ��£�����ֱ�ӽ������ڴ�ɾ��*/
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
			printf("��ȡ�����ڴ�KEYʧ��.\n");
			return -1;
		}
		DestroyShm(iShmKey);
	}
/*���������ڴ���߸���*/
	if(ConnectCmdShmAndInitMem()<0){
		if(BuildCmdShmInit()<0){
			printf("��ȫ��������������ڴ�ʧ��.\n");
			return -1;
		}
	}
	else{
		if(IsCmdServRun()==true){
			printf("CmdServer���򻹼���������.\n");
			return -1;
		}
		
		if(IncreaseCmdShmInit()<0){
			DetachShm((void*)PSHMCMD);
			if(BuildCmdShmInit()<0){
				printf("��ȫ��������������ڴ�ʧ��.\n");
				return -1;
			}
		}
	}
/*�����ﹲ���ڴ涼������,Mem�ǹ��ڹ����ڴ�ı��ؽṹpShmָ�����ڴ�*/
	InitAppRes(argv[0]);
	if(IniConnect("dataconnstr")<0) return -1;
		 
/*������ѭ������*/

	while(1){
		usleep(100);
		/*����ִ��������µ����ݿ�*/
		ProcBackCmd();
		/*������ת��Ϊָ����ʽ����Agent*/
		ProcSendCmd();

		HeartBeatServer();
	}
	
	CommitWorkRelease();

	return 0;
}
