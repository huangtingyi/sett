#include <stdio.h>
#include <stdlib.h>

#include <wwcoding.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>

#include <param_intf.h>

#include "appsupp.h"
#include "stt_ticket.h"

int ProcessMain(struct InstParamStruct *pParam);
int ProcessFile(struct InstParamStruct *ptHead,char sFileName[]);

char GETTABLE[256];
int GetTableName(char sModule[],char sBaseName[],char sAreaCode[],
	char sGetTable[],char sTableName[])
{
	char sCommand[256],sResult[1024];
	
	strcpy(sTableName,"");

	sprintf(sCommand,"%s %s %s %s",
		sGetTable,sModule,sBaseName,sAreaCode);
	
	if(exec2str(sCommand,sResult)!=0) return -1;
	
	GetSepStrX(sResult,'\t',0,30,sTableName);

	return 0;
}
int InitInstCtl()
{
	char sPath[256];

	GetBillHome(sPath);
	
	sprintf(GETTABLE,"%sshell/gettablename.sh",sPath);
	
	if(IsFile(GETTABLE)==FALSE){
		printALERT("�ļ�%s��Ч.",GETTABLE);
		return -1;
	}
	return 0;	
}
int InsertLogCheck(char sSourceID[], char sFileName[],char sModule[])
{
	char sCondition[256];
        struct AcctLogStruct Temp;
/*��������ʱ־��*/
	sprintf(sCondition,"WHERE SOURCE_ID='%s' AND \n\
		FILE_NAME='%s' AND      \n\
		MODULE='%s' AND \n\
		STATE='A'",sSourceID,sFileName,sModule);
	return SDGetAcctLogToStruct(&Temp,"INSERT_LOG",sCondition);
}
/*���жϱ����ļ��쳣*/
void BackupInstFile(char sFileName[],char sBackPath[])
{
	char sCommand[1024],sTargetName[256];

/*ȥ��.tmp�ļ���չ��*/
	GetBaseName(sFileName,sTargetName);
	if(RLike(sTargetName,".tmp")==true)
		sTargetName[strlen(sTargetName)-4]=0;

	if(strlen(sBackPath)==0)
		sprintf(sCommand,"rm -f %s",sFileName);
	else
		sprintf(sCommand,"mv %s %s%s",sFileName,sBackPath,sTargetName);
	system(sCommand);
}

int ProcessMain(struct InstParamStruct *pParam)
{
	char sFileName[256],sTempName[256];
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;
	
/*����һ���ļ��б�*/
	if(dir2list(pParam->sSourcePath,pParam->sFilter,&ptHead)<0){
		printALERT("��ȡĿ¼%s��%sģʽ���ļ��б�ʧ��",
			pParam->sSourcePath,pParam->sFilter);
		return -1;
	}
	
	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		
		pTemp = ptHead;
		ptHead = ptHead->pNext;
		
		if(WantQuit()==true){
			WriteProcMsg("���յ��˳��źţ������˳�");
			break;
		}

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);

	/*����ļ��ձ��޸��򲻴���*/
		sprintf(sTempName,"%s%s",pParam->sSourcePath,sFileName);
		if(FileModifyDiff(sTempName)<1) continue;
		
		if(InsertLogCheck(pParam->sSourceID,sFileName,pParam->sModule)==true){
			printNORMAL("�ļ�%s����⣬�����ݵ�%sĿ¼",
				sFileName,pParam->sBackPath);
			BackupInstFile(sTempName,pParam->sBackPath);
			continue;
		}
	/*����ͨ����⺯�����*/
		if(ProcessFile(pParam,sTempName)<0){
			RollbackWork();
			return -1;
		}		
	        CommitWork();
	}
/*�ͷ��ļ��б�*/
	listfree(&ptLkHead);

	return 0;
}

int ProcessFile(struct InstParamStruct *ptHead,char sFileName[])
{
	int iCnt=0;
	char sType[5],sBaseName[256],sTempName[256];
	char sTableName[31],sDataDate[15];
	struct AcctLogStruct Temp;
	
	GetBaseName(sFileName,sBaseName);
	sprintf(sTempName,"%s.tmp",sFileName);

/*��ȡDATA_DATE�ֶ�*/
	FileBackupDate(sFileName,ptHead->sDateRule,sDataDate);
	if(strcmp(sDataDate,"")==0){
		if(FileModifyDate(sFileName,sDataDate)!=0){
			printALERT("�ļ�%s���ɷ���",sFileName);
			return -1;
		}
	}
		
/*д�����־*/
	bzero((void*)&Temp,	sizeof(struct AcctLogStruct));
	strcpy(Temp.sSourceID,  ptHead->sSourceID);
	strcpy(Temp.sModule,    ptHead->sModule);
	strcpy(Temp.sState,     "A");
	Temp.iByte=     	FileSize(sFileName);
	strcpy(Temp.sFileName,  sBaseName);
	GetHostTime(Temp.sDealBeginDate);
	strcpy(Temp.sDataDate,  sDataDate);
	strcpy(Temp.sDataDate+8,"000000");		
	strcpy(sType,		ptHead->sFileType);
	
	Temp.iTacheID=		ptHead->iTacheID;
	strcpy(Temp.sAppID,	ptHead->sAppID);

/*��ȡ�����ı���*/
	if(GetTableName(ptHead->sModule,sBaseName,ptHead->sBelongCode,
		GETTABLE,sTableName)!=0){
			
		printALERT("ģ��%s,����%s,�ļ�%s��ȡ��ʧ��",
			ptHead->sModule,ptHead->sBelongCode,sBaseName);
		return -1;	
	}
	strcpy(Temp.sOperType,  ptHead->sOperType);
	strcpy(Temp.sFileType,  ptHead->sFileType);
	strcpy(Temp.sTableName,  sTableName);	
/*���������ļ�����Ϊ��ʱ�ļ�*/
	if(execcmd("mv %s %s",sFileName,sTempName)!=0){
		printALERT("���ļ�%s�ƶ���%s�ļ�ʧ��",sFileName,sTempName);
		return -1;
	}
	
/*��������⺯�����*/
	if((iCnt=InsertTicket(sTempName,sTableName,sType))<0){
		printALERT("�Ա�%s ����ļ�%sʧ��",sTableName,sFileName);
		return -1;
	}
	Temp.iCnt=iCnt;
	GetHostTime(Temp.sDealEndDate);
	if(SDInsertStructToAcctLog(&Temp,"INSERT_LOG")<0){
		printALERT("дINSERT_LOG��־����");
	        WriteErrStackAlert();
	        return -1;
	}
/*�����ļ����ݺ͸���*/
	BackupInstFile(sTempName,ptHead->sBackPath);
	
	printNORMAL("�ļ� %s ����� %s �ɹ�,��¼�� %d",
		sFileName,sTableName,iCnt);
	return 0;
}

int main( int argc, char **argv )
{
	int iGroupID,iRet;
	char sFileName[256];
	struct InstParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc!=3){
		printf("Usage %s shm|ins2db.ini|flowxxxx GroupID.\n",argv[0]);
		return -1;
	}	
	
	InitAppRes("ins2db.sh");

	strcpy(sFileName,argv[1]);
	iGroupID = atoi(argv[2]);
	
	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*��ʼ��INS2DBӦ��λ�ú͹�ʽ·����ȫ�ֱ���*/
	if(InitInstCtl()<0) return -1;

/*����Ҫ����Ĳ�����ȡ�� ������*/
	if(GetInstParamList(sFileName,iGroupID,&ptHead)<0) return -1;

	if(ConnectDataDB()<0){
		printALERT("�������ݿ�ʧ��");
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(IsDir(pTemp->sSourcePath)==false){
		        printALERT("����·��%s��Ч",pTemp->sSourcePath);
		        return -1;
		}
	/*�������Ŀ¼Ϊ�գ���Ϊ�����ݴ���*/
		if(IsDir(pTemp->sBackPath)==false&&
			strcmp(pTemp->sBackPath,"")!=0){
		        printALERT("����·��%s��Ч",pTemp->sBackPath);
		        return -1;
		}

		if((iRet=ProcessMain(pTemp))<0) return -1;
			
		if(iRet>0) break;
		if(WantQuit()==true)break;	
	}
	
	DestroyList((LIST*)ptLkHead);

	DisconnectDatabase();
	
	return 0;
}

