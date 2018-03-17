#include <hnixs.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwcoding.h>
#include <list.h>
#include <wwsupp.h>

struct TaskStruct
{
	struct TaskStruct *pNext;
	char sSourceID[32];
	char sStr1[64];
	char sStr2[64];
	char sTask[256];
	int  iForceFlag;
	int  iNewFlag;
};

int mvitem_str2task(char sTemp[],struct TaskStruct *p,char sMessage[1024])
{
	char	*pc;
	int	l,iNewFlag,iForceFlag;
	char	sTask[256],sSourceID[256],sStr1[256],sStr2[256],sStr3[512];

	strcpy(sMessage,"");
	bzero((void*)p,sizeof(struct TaskStruct));
	
	GetSepStr(sTemp,',',0,sSourceID);AllTrim(sSourceID);
	GetSepStr(sTemp,',',1,sStr1);	AllTrim(sStr1);
	GetSepStr(sTemp,',',2,sStr2);	AllTrim(sStr2);
	GetSepStr(sTemp,',',3,sStr3);	AllTrim(sStr3);

/*������ַǷ�����������,�м�¼������澯������*/
	if((pc=strchr(sTemp,':'))==NULL){
		sprintf(sMessage,"�������������,%s,����",sTemp);
		return -1;
	}

	strcpy(sTask,pc+1);

	iForceFlag=atoi(sStr3);

	if(strchr(sStr1,'x')!=NULL) iNewFlag=true;
	else iNewFlag=false;

	if(strlen(sSourceID)>=32||
		strlen(sStr1)>=64||strlen(sStr2)>=64){

		l=sprintf(sMessage,"����%s�����쳣����\n",sTemp);
		sprintf(sMessage+l,"source_id=%s,s1=%s,s2=%s",
			sSourceID,sStr1,sStr2);
		return -1;
	}
	
	p->pNext=NULL;
	strcpy(p->sSourceID,sSourceID);
	strcpy(p->sStr1,	sStr1);
	strcpy(p->sStr2,	sStr2);

	p->iForceFlag=	iForceFlag;
	strcpy(p->sTask,	sTask);
	p->iNewFlag=	iNewFlag;
	
	return 0;
	
}
int FInitTaskList(char sFileName[],struct TaskStruct **pptHead)
{
	char	sTemp[1024],sMessage[1024];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct	TaskStruct *ptPre=NULL,*ptCur=NULL,Temp;

/*�����ȶ��ļ�*/
	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

/*�ͷ��ϴ�ѭ��������ڴ�*/
	if((*pptHead)!=NULL){
		DestroyList((LIST*)(*pptHead));
		*pptHead=NULL;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*����̫������*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*����̫�̵���*/
		if(strlen(sTemp)<20) continue;
/*����ע����*/
		if(strchr(sTemp,'#')!=NULL) continue;
/*���м�¼ת���ṹ��ʽ*/
		if(mvitem_str2task(sTemp,&Temp,sMessage)!=0){
			WriteAlertPrint(sMessage);
			continue;
		}
		
		if((ptCur=(struct TaskStruct*)malloc(
			sizeof(struct TaskStruct)))==NULL){
			WriteAlertPrint("�����ڴ�TaskStructʧ��,�˳�!");
			return -1;
		}
		memcpy((void*)ptCur,(void*)&Temp,sizeof(struct TaskStruct));

		InsertListTail((LIST**)&ptPre,(LIST*)ptCur);

	}
/*�ͷ�FileControl�ṹ*/
	listfree(&ptLkHead);

	*pptHead=ptPre;

	return 0;
}

int IntervalTime(char sDateStr[],char sTimeStr[])
{
	char sHostTime[15],sTemp[64];
	char sYear[5],sMonth[3],sDay[3],sHour[3],sMin[3],sSec[3];
	int  iYear,iMonth,iDay,iHour,iMin,iSec;

	GetHostTime(sHostTime);

	strncpy(sTemp,sHostTime,4);	sTemp[4]=0;	iYear=atoi(sTemp);
	strncpy(sTemp,sHostTime+4,2);	sTemp[2]=0;	iMonth=atoi(sTemp);
	strncpy(sTemp,sHostTime+6,2);	sTemp[2]=0;	iDay=atoi(sTemp);
	strncpy(sTemp,sHostTime+8,2);	sTemp[2]=0;	iHour=atoi(sTemp);
	strncpy(sTemp,sHostTime+10,2);	sTemp[2]=0;	iMin=atoi(sTemp);
	strncpy(sTemp,sHostTime+12,2);	sTemp[2]=0;	iSec=atoi(sTemp);

	GetSepStr(sDateStr,'.',0,sTemp); AllTrim(sTemp);
	strncpy(sYear,sTemp,4); sYear[4]=0;

	GetSepStr(sDateStr,'.',1,sTemp);AllTrim(sTemp);
	strncpy(sMonth,sTemp,2);sMonth[2]=0;

	GetSepStr(sDateStr,'.',2,sTemp); AllTrim(sTemp);
	strncpy(sDay,sTemp,2);	sDay[2]=0;


	GetSepStr(sTimeStr,'.',0,sTemp); AllTrim(sTemp);
	strncpy(sHour,sTemp,2);	sHour[2]=0;

	GetSepStr(sTimeStr,'.',1,sTemp); AllTrim(sTemp);
	strncpy(sMin,sTemp,2);	sMin[2]=0;

	GetSepStr(sTimeStr,'.',2,sTemp); AllTrim(sTemp);
	strncpy(sSec,sTemp,2);	sSec[2]=0;

	printf("Want Startup newmode host=%s,datestr=%s,timestr=%s.\n",
		sHostTime,sDateStr,sTimeStr);

	if((strcmp(sYear,"x")==0||atoi(sYear)==iYear)&&
		(strcmp(sMonth,"x")==0||atoi(sMonth)==iMonth)&&
		(strcmp(sDay,"x")==0||atoi(sDay)==iDay)&&
		(strcmp(sHour,"x")==0||atoi(sHour)==iHour)&&
		(strcmp(sMin,"x")==0||atoi(sMin)==iMin)&&
		(strcmp(sSec,"x")==0||(atoi(sSec)==0&&iSec<30)||
		(atoi(sSec)!=0&&iSec>=30))) return true;
	return false;
}
int WantStartup(int iPre,int iCur,struct TaskStruct *pTemp)
{
	int iPreOff,iCurOff,iOff,iInterval;

/*��ģʽ�ĵ��ȷ�ʽ*/
	if(pTemp->iNewFlag==false){

		iInterval=atoi(pTemp->sStr1);
		iOff=	  atoi(pTemp->sStr2);

		iPreOff=iPre-iPre/iInterval*iInterval;
		iCurOff=iCur-iCur/iInterval*iInterval;

	printf("Want Startup oldmode iPreOff=%d,iCurOff=%d,iOff=%d.\n",
		iPreOff,iCurOff,iOff);

	/*���off==interval-1�����,�������iCurOffΪ0ʱ��Ҫ����,2008.11.25*/
		if(iOff>=iPreOff&&
			(iOff<iCurOff||(iOff==(iInterval-1)&&iCurOff==0))
			) return true;
		return false;
	}
/*��ģʽ�ĵ��ȷ�ʽ*/
	return 	IntervalTime(pTemp->sStr1,pTemp->sStr2);
}
void GetTaskTime(int iTaskPid,char sTaskTime[64])
{
	char sCommand[256],sTemp[1024],sPid[128];
	struct FileControlStruct *ptLkHead,*ptHead,*pTemp;


	strcpy(sTaskTime,"");

	sprintf(sCommand,"ps -ef | grep -v grep | grep %d",iTaskPid);

	if(exec2list(sCommand,&ptLkHead)<0) return;

	ptHead=ptLkHead;
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sTemp,pTemp->pData,1023);sTemp[1023]=0;
		AllTrim(sTemp);

		GetTabStr(sTemp,1,sPid);

		if(iTaskPid==atoi(sPid)){
			GetTabStr(sTemp,4,sTaskTime);
			break;
		}
	}
	listfree(&ptLkHead);
}
void WriteShedTaskInfo(char sCtlName[],char sSourceID[],char sTaskPid[],
	char sTaskTime[])
{
	char sCommand[1024];

	sprintf(sCommand,"echo %s %s %s > %s",
		sSourceID,sTaskPid,sTaskTime,sCtlName);
	system(sCommand);
}
void ReadShedTaskInfo(char sCtlName[],char sSourceID[],int *ppid,char sTaskTime[])
{
	char sCommand[1024],sResult[1024],sTemp[256];

	strcpy(sSourceID,"");
	*ppid=0;
	strcpy(sTaskTime,"");

	sprintf(sCommand,"cat %s | head -1",sCtlName);

	if(exec2str(sCommand,sResult)!=0) return;

	GetTabStr(sResult,0,sTemp);
	strncpy(sSourceID,sTemp,31);sSourceID[31]=0;AllTrim(sSourceID);

	GetTabStr(sResult,1,sTemp); *ppid=atoi(sTemp);

	GetTabStr(sResult,2,sTemp);
	strncpy(sTaskTime,sTemp,63);sTaskTime[63]=0;AllTrim(sTaskTime);
}
int StartupTask(char sCtlName[],char sSourceID[],char sTaskCmd[])
{
	int iTaskPid;
	char sCommand[256],sResult[1024],sTaskTime[64],sTaskPid[16];

	sprintf(sCommand,"nohup %s >/dev/null & \n echo $!",sTaskCmd);

	if(exec2str(sCommand,sResult)!=0) return -1;

	TrimAll(sResult);

	if((iTaskPid=atoi(sResult))==0) return -1;

	GetTaskTime(iTaskPid,sTaskTime);

	if(strlen(sTaskTime)!=0)
		WriteProcPrint("���� %s %s �ɹ�",sSourceID,sTaskCmd);
	else
		WriteProcPrint("���� %s %s ʧ��",sSourceID,sTaskCmd);

	sprintf(sTaskPid,"%d",iTaskPid);

	WriteShedTaskInfo(sCtlName,sSourceID,sTaskPid,sTaskTime);
	return 0;
}
void ShedtskMain(struct TaskStruct *ptHead,int iPre,int iCur,char sCtlPath[])
{
	int iTaskPid;

	char sCtlName[256],sReadStr[128],sTaskTime[64],sLastTime[64];
	struct	TaskStruct *pTemp;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

/*������������������ȡ��һ������*/
		if(WantStartup(iPre,iCur,pTemp)==false) continue;

printf("startup here %s.\n",pTemp->sSourceID);

		sprintf(sCtlName,"%s%s.txt",sCtlPath,pTemp->sSourceID);
/*��������ļ�������������֮*/
		if(!IsFile(sCtlName)){
			StartupTask(sCtlName,pTemp->sSourceID,pTemp->sTask);
			continue;
		}

		ReadShedTaskInfo(sCtlName,sReadStr,&iTaskPid,sLastTime);
/*���ǰ̨����Ѿ�ֹͣ��Ӧ�ã���������*/
		if(strcmp(sReadStr,"stopped")==0)	continue;

/*���ǰ̨��ط�����ֹͣӦ�ã�д��������*/
		if(strcmp(sReadStr,"stop")==0){
			WriteShedTaskInfo(sCtlName,"stopped","stopped","stopped");
			continue;
		}
/*���ǰ̨��ط���������������֮*/
		if(strcmp(sReadStr,"start")==0){
			StartupTask(sCtlName,pTemp->sSourceID,pTemp->sTask);
			continue;
		}
/*��ȡϵͳĳ��PID������ʱ��*/
		GetTaskTime(iTaskPid,sTaskTime);
/*���ϵͳû�иý���,����һ������ʱ���ϵͳ���̵�����ʱ�䲻ͬ��������һ��*/
		if(strlen(sTaskTime)==0||strcmp(sTaskTime,sLastTime)!=0){
			StartupTask(sCtlName,pTemp->sSourceID,pTemp->sTask);
			continue;
		}
/*����˵�����ý��̻�������,�����Ҫǿ��������,д��־��������*/
		if(pTemp->iForceFlag==0){
			WriteProcPrint("����pid=%d %s���г�ʱ,�޷�����",
				iTaskPid,pTemp->sTask);
			continue;
		}
/*Ҫǿ��������,ɱ���̲�����*/
		WriteProcPrint("����pid=%d %s���г�ʱ,�����",
			iTaskPid,pTemp->sTask);
		kill(iTaskPid,9);
		StartupTask(sCtlName,pTemp->sSourceID,pTemp->sTask);
	}
}
void SleepTime(int iDelay)
{
	static time_t tCurTime=0,tPreTime=0;

	if(tPreTime==0){
		tPreTime=tGetHostTime();
		sleep(iDelay);
		return;
	}
	while(1){

		tCurTime=tGetHostTime();
{
		char sPreTime[15],sCurTime[15];

		sFormatTime(tCurTime,sCurTime);
		sFormatTime(tPreTime,sPreTime);

		printf("sleeping pretime=%s,curtime=%s,delaysec=%ld.\n",
			sPreTime,sCurTime,(tCurTime-tPreTime));
}

		if((tCurTime-tPreTime)>=iDelay){
			tPreTime=tCurTime;
			break;
		}
		sleep(1);
	}
}
int main(int argc,char *argv[])
{
	time_t tBaseTime;
	int iPre=0,iCur=0,pid;
	char sAppHome[256],sBillHome[256],sCtlPath[256],sCtlName[256];
	char sTaskName[256],sBaseTask[256],sHostTime[15];
	char sTaskTime[64],sSourceID[256],sTaskID[32];
	struct	TaskStruct *pTaskList=NULL;

	if (argc!=2){
		printf("Usage %s taskfile.\n", argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);

	GetBaseName(argv[0],sSourceID);
	strcpy(sTaskName, argv[1]);
	
	GetBaseName(sTaskName, sTaskID);

	if(!IsFile(sTaskName)){
		GetBaseName(sTaskName,sBaseTask);
		if(strcmp(sTaskName,sBaseTask)!=0){
			WriteAlertPrint("�����ļ�%s������",sTaskName);
			return -1;
		}
		GetBillHome(sBillHome);
		sprintf(sTaskName,"%sshell/%s",sBillHome,sBaseTask);
		if(!IsFile(sTaskName)){
			WriteAlertPrint("�����ļ�%s������",sTaskName);
			return -1;
		}
	}

	GetAppHome(sAppHome);
	sprintf(sCtlPath,"%sctl/",sAppHome);

	if(!IsDir(sCtlPath)){
		WriteAlertPrint("Ӧ����ͣ����·��%s������",sCtlPath);
		return -1;
	}

	WriteProcPrint("�������ȳɹ�");

	GetHostTime(sHostTime);
	strcpy(sHostTime+8,"000000");
	tBaseTime=tGetTime(sHostTime);
	iPre=iCur=(tGetHostTime()-tBaseTime)/10;


	pid=getpid();
	GetTaskTime(pid,sTaskTime);
	sprintf(sCtlName,"%s%s.txt",sCtlPath,sTaskID);
	
	if(IsFile(sCtlName)&&FileModifyDiff(sCtlName)<600){
		printf("�����Ѿ�����.\n");
		return -1;
	}

	WriteShedTaskInfo(sCtlName,sSourceID,sTaskID,sTaskTime);

	while(1){

		if(FInitTaskList(sTaskName, &pTaskList)<0)
			WriteAlertPrint("��ȡ�ļ�%sʧ��", sTaskName);

		ShedtskMain(pTaskList,iPre,iCur,sCtlPath);

		SleepTime(10);

		iPre=iCur;
		iCur=(tGetHostTime()-tBaseTime)/10;

		ReadShedTaskInfo(sCtlName,sSourceID,&pid,sTaskTime);

		if(strcmp(sSourceID,"stop")==0){
			WriteProcPrint("�ӵ��˳��ź�,�����˳�");
			unlink(sCtlName);
			break;
		}
		
		/*ÿ5����д֪ͨϵͳ������*/
		if(iCur%60==0){
			GetTaskTime(pid,sTaskTime);
			WriteShedTaskInfo(sCtlName,sSourceID,sTaskID,sTaskTime);
		}
	}
	return 0;
}
