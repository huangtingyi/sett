#include <stdio.h>
#include <stdlib.h>

#include <wwcoding.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <param_intf.h>
#include <dbsupp.h>

#include <appsupp.h>

char PREP[256],EXPRPATH[256],CHKDUP[256];

int ChkDupMain(char sModule[],char sSourceID[],char sSourceName[],
	char sTargetDir[],char msg[]);

int InitPrepCtl();


int WantChkDup(char sModule[])
{
	char sTemp[128],sPath[128],sTempModule[128];

	GetIniName(sPath);
	if(ReadString(sPath,"bss","prep","chkdup",sTemp)<0) return false;
	
	strcpy(sTempModule,sModule);Upper(sTempModule);

	if(strstr(sTemp,sTempModule)!=NULL) return true;
	return false;
}
int ChkPrepDup(struct PrepParamStruct *ptHead,char sOutName[],char sSplitStr[],
	struct TinySplitStruct *pTiny,int *piDupCnt)
{
	int i,iDupCnt=0;
	char sTempName[256],msg[1024],sTemp[20];
	struct TinySplitStruct *ptPre,*ptCur;
	
	/*���û�а�key���ļ�*/
	if(pTiny==NULL){
		for(i=0;i<strlen(sSplitStr);i++){

			/*ֻ�����������Ļ���*/
			if(GetLogFileType(sSplitStr[i])!='C') continue;
			
			sprintf(sTempName,"%s.%c.tmp",sOutName,sSplitStr[i]);
			
			if(ChkDupMain(ptHead->sChkMod,ptHead->sSourceID,
				sTempName,ptHead->sErrPath,msg)<0) return -1;
			if(GetSepCnt(msg,'\t')!=6){
				printALERT("ChkDupMain����,��ӦΪ6������ʵ��Ϊ %s",msg);
				return -1;
			}
			GetSepStr(msg,'\t',1,sTemp);
			iDupCnt+=atoi(sTemp);
		}
		*piDupCnt=iDupCnt;
		return 0;
	}
	
	/*��KEY���ļ���ֱ�Ӷ�ȡ�����ļ�*/
	ptCur=pTiny;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		/*ֻ�����������Ļ���*/
		if(GetLogFileType(sSplitStr[i])!='C') continue;
		
		sprintf(sTempName,"%s.%c.%s.tmp",
			sOutName,sSplitStr[i],ptPre->sKey);

		if(ChkDupMain(ptHead->sChkMod,ptHead->sSourceID,
			sTempName,ptHead->sErrPath,msg)<0) return -1;
		if(GetSepCnt(msg,'\t')!=6){
			printALERT("ChkDupMain����,��ӦΪ6������ʵ��Ϊ %s",msg);
			return -1;
		}
		GetSepStr(msg,'\t',1,sTemp);
		iDupCnt+=atoi(sTemp);
		
	}
	*piDupCnt=iDupCnt;

	return 0;
}
/*�õ�һ��PrepLogList�б���д:file_name,cnt,file_type�ֶ�,
	��������ļ��޸�Ϊ��ʱ�ļ�����*/
int GetPrepLogList(struct TinySplitStruct *pTinySplit,char sSplitStr[],
	int iAbnoCnt,int iErrCnt,char sOutName[],char sPrefix[],
	char sPath[],char sErrPath[],struct PrepLogStruct *p,
	struct PrepLogStruct **pptHead)
{
	int i=0,iDupCnt=0;
	char	sTempDate[9],oriPrefix[256],stdPrefix[256];
	char	sTempName[256],sTargetName[256];
	char	sSourcePath[256],sErrName[256];
	struct TinySplitStruct *ptPre,*ptCur;

	*pptHead=NULL;

	strncpy(sTempDate,p->sDataDate,8);sTempDate[8]=0;

	for(i=0;i<strlen(sSplitStr);i++){

		/*������쳣������󻰵�*/
		if(sSplitStr[i]=='a'||sSplitStr[i]=='e'){
			sprintf(p->sFileName,"%s.%s.%c",
				sPrefix,p->sModule,sSplitStr[i]);
			
			if(sSplitStr[i]=='a')p->iCnt=iAbnoCnt;
			else		p->iCnt=iErrCnt;
			
			p->sFileType[0]=GetLogFileType(sSplitStr[i]);

			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("�����ڴ�PrepLogStruct����");
				return -1;
			}
			
			GetPathName(sOutName,sSourcePath);
			GetBaseName(sOutName,sErrName);

			if(sSplitStr[i]=='a')
				sprintf(sTempName,"%s%s.abn",sSourcePath,sErrName+8);
			else	sprintf(sTempName,"%s%s.err",sSourcePath,sErrName+8);

			sprintf(sTargetName,"%s%s.tmp",sErrPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("��%s����Ϊ%sʧ��",sTempName,sTargetName);
				return -1;
			}
			continue;
		}
		
		sprintf(oriPrefix,"%s.%c",sOutName,sSplitStr[i]);
		sprintf(stdPrefix,"%s.%s.%c",sPrefix,p->sModule,sSplitStr[i]);
		
		/*���󻰵����ߺ��Ի������Լ�δ��KEY��ֵĻ���*/
		p->sFileType[0]=GetLogFileType(sSplitStr[i]);

		if(SearchTinySplit(pTinySplit,sSplitStr[i])==NOTFOUND){

			sprintf(sTempName,"%s.tmp",oriPrefix);

			p->iCnt=0;
			if(IsFile(sTempName))	p->iCnt=FileLines(sTempName);

			sprintf(p->sFileName,"%s",stdPrefix);

			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("�����ڴ�PrepLogStruct����");
				return -1;
			}
			sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("��%s����Ϊ%sʧ��",sTempName,sTargetName);
				return -1;
			}
			/*д�ص��ļ���־*/
			sprintf(sTempName,"%s.DUP",oriPrefix);
			if(!IsFile(sTempName))continue;
			
			strcpy(p->sFileType,"D");
			p->iCnt=FileLines(sTempName);

			sprintf(p->sFileName,"%s.DUP",stdPrefix);
			
			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("�����ڴ�PrepLogStruct����");
				return -1;
			}
			sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("��%s����Ϊ%sʧ��",sTempName,sTargetName);
				return -1;
			}
			continue;
		}
		
		/*��key��ֵĻ���*/
		ptCur=pTinySplit;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			if(sSplitStr[i]!=ptPre->sSplitType[0]) continue;
			
			p->sFileType[0]=GetLogFileType(sSplitStr[i]);
			
			/*����ж�Ӧ���ص��ļ���д�ص���־*/
			iDupCnt=0;
			sprintf(sTempName,"%s.%s.DUP",oriPrefix,ptPre->sKey);
			if(IsFile(sTempName)){
				sprintf(p->sFileName,"%s.%s.DUP",stdPrefix,
					ptPre->sKey);
				strcpy(p->sFileType,"D");
				p->iCnt=iDupCnt=FileLines(sTempName);

				if(item2List((LIST**)pptHead,(LIST*)p,
					sizeof(struct PrepLogStruct))<0){
					printALERT("�����ڴ�PrepLogStruct����");
					return -1;
				}
				sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
				if(Rename(sTempName,sTargetName)<0){
					printALERT("��%s����Ϊ%sʧ��",sTempName,sTargetName);
					return -1;
				}
			}
			
			p->iCnt=ptPre->iCnt-iDupCnt;

			sprintf(p->sFileName,"%s.%s",stdPrefix,ptPre->sKey);

			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("�����ڴ�PrepLogStruct����");
				return -1;
			}
			sprintf(sTempName,"%s.%s.tmp",oriPrefix,ptPre->sKey);
			sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("��%s����Ϊ%sʧ��",sTempName,sTargetName);
				return -1;
			}
		}
	}	
	return 0;
}
static int GetFileTypeCnt(struct PrepLogStruct *ptHead,char cFileType)
{
	int iCnt=0;
	
	while(ptHead!=NULL){
		if(cFileType==ptHead->sFileType[0]) iCnt+=ptHead->iCnt;
		ptHead=ptHead->pNext;
	}
	return iCnt;
}
static int RenameOutputFile(struct PrepLogStruct *ptHead,
	char sNormalPath[],char sErrPath[])
{
	char sTempName[256],sTargetName[256],sPath[256];

	while(ptHead!=NULL){
		if(strcmp(ptHead->sFileType,"A")==0||
			strcmp(ptHead->sFileType,"E")==0)
			strcpy(sPath,sErrPath);
		else	strcpy(sPath,sNormalPath);

		sprintf(sTempName,"%s%s.tmp",sPath,ptHead->sFileName);
		sprintf(sTargetName,"%s%s",sPath,ptHead->sFileName);
		if(Rename(sTempName,sTargetName)<0){
			printALERT("��%s����Ϊ%sʧ��",sTempName,sTargetName);
			return -1;
		}
		WriteProcPrint("�ɹ�����%s�ļ�",ptHead->sFileName);
		ptHead=ptHead->pNext;
	}
	return 0;
}
static int WriteList2PrepLog(struct PrepLogStruct *pList,
	struct PrepLogStruct *pLog,char sBaseName[],
	int iByte,int iCnt,char sInType[])
{
	struct PrepLogStruct *pTemp;
	struct PrepProcLogStruct Temp;
	
	bzero((void*)&Temp,sizeof(struct PrepProcLogStruct));
	
	Temp.iInputID=pLog->iInputID;
	strcpy(Temp.sSourceID,pLog->sSourceID);
	strcpy(Temp.sModule,pLog->sModule);
	
	strcpy(Temp.sDealBeginDate,pLog->sDealBeginDate);
	strcpy(Temp.sDealEndDate,pLog->sDealEndDate);
	
	strcpy(Temp.sFileName,sBaseName);
	Temp.iByte= iByte;
	Temp.iCnt= iCnt;
	
	Temp.iNormalCnt=GetFileTypeCnt(pList,'C');
	Temp.iErrCnt=GetFileTypeCnt(pList,'E');
	Temp.iDupCnt=GetFileTypeCnt(pList,'D');
	Temp.iAbnoCnt=GetFileTypeCnt(pList,'A');
	Temp.iNewCnt=GetFileTypeCnt(pList,'N');

	strcpy(Temp.sFileType,sInType);
	
	strcpy(Temp.sAppID,pLog->sAppID);
	Temp.iTacheID=	pLog->iTacheID;
	
	if(SDInsertStructToPrepProcLog(&Temp,"PREP_PROC_LOG")<0) return -1;
	
	pTemp=pList;
	while(pTemp!=NULL){
		
		if(SDInsertStructToPrepLog(pTemp,"PREP_LOG")<0)
			return -1;
		pTemp=pTemp->pNext;
	}
	return 0;
}
static void GetMyTargetName(char sPrefix[],char sModule[],char sSplitStr[],
	char sTargetName[])
{
	int i=0,k;

	k=sprintf(sTargetName,"%s.%s.%c",sPrefix,sModule,sSplitStr[0]);

	for(i=1;i<strlen(sSplitStr);i++)
		k+=sprintf(sTargetName+k,",~.%c",sSplitStr[i]);
}
int ProcessFile(char sBaseName[],char sExprFile[],struct PrepParamStruct *p,
	int iChkDupFlag,char sNewName[],char msg[])
{
	int iCnt,iNormalCnt,iErrCnt,iAbnoCnt,iDupCnt,iByte,pid=0,iRet;
	char sFileName[256],sTempName[256],sTargetName[256],sOutName[256];
	char sTemp[256],sPrefix[40],sCommand[1024],sLine[2048],sSplitStr[20];
	char sTempDate[15],sTempSource[7],sTempBaseName[60],sLockName[256];
	struct PrepLogStruct Temp,*pLogList=NULL;
	struct TinySplitStruct *pTinySplit=NULL;

	strcpy(msg,"");
	strcpy(sNewName,"");
	
	bzero((void*)&Temp,sizeof(struct PrepLogStruct));
	
	Temp.iInputID=		GetInputID();
	strcpy(Temp.sSourceID,p->sSourceID);
	strcpy(Temp.sModule,p->sModule);
	strcpy(Temp.sState,"A");
	
	strcpy(Temp.sOriFileName,sBaseName);
	strcpy(Temp.sAppID,p->sAppID);
	Temp.iTacheID=	p->iTacheID;
	
	strncpy(sTempSource,Temp.sSourceID,6);sTempSource[6]=0;
	RightPad(sTempSource,6,'0');
	
	pid=getpid();

	sprintf(sFileName,"%s%s",p->sSourcePath,sBaseName);
	sprintf(sTempBaseName,"%s_%d",sBaseName,pid);
	sprintf(sTempName,"%s%s.tmp",p->sSourcePath,sTempBaseName);

	GetHostTime(Temp.sDealBeginDate);

/*����������ļ��޸�һ����ʱ�ļ���*/
	if(Rename(sFileName,sTempName)!=0){
		sprintf(msg,"���� %s �� %s ʧ��",sFileName,sTempName);
		return -1;
	}
	
/*�������Ԥ����ĳ���ʧ���������־,д������־*/
	sprintf(sCommand,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d",PREP,
		sExprFile,sTempName,p->sNormalPath,p->sErrPath,
		p->sMsc,p->sAreaCode,p->sModule,p->sUserType,
		p->sSourceID,p->sInType,p->sSplit,p->iStartPos,p->iKeyLen);
	if(exec2str(sCommand,sLine)!=0){
		sprintf(msg,"Ԥ����ʧ��,ִ�� %s",sCommand);
		return -1;
	}
/*��һ�����������У��*/
	if(GetSepCnt(sLine,'\t')!=7){
		sprintf(msg,"Ԥ���������Ϣ����,ӦΪ7������ʵ��Ϊ %s",sLine);
		return -1;
	}
/*��ȡԤ������������Ĳ���*/
	GetSepStr(sLine,'\t',0,sOutName);
	GetSepStr(sLine,'\t',1,sTemp);	iByte=atoi(sTemp);
	GetSepStr(sLine,'\t',2,sTemp);	iNormalCnt=atoi(sTemp);
	GetSepStr(sLine,'\t',3,sTemp);	iErrCnt=atoi(sTemp);
	GetSepStr(sLine,'\t',4,sTemp);	iAbnoCnt=atoi(sTemp);
	GetSepStr(sLine,'\t',5,sTemp);	iCnt=atoi(sTemp);
	GetSepStrX(sLine,'\t',6,20,sSplitStr);

	iDupCnt=0;

/*��һ������ƽ����У�飬�ܼ�¼�ʹ���+�쳣ƽ��*/
	if(iCnt!=(iNormalCnt+iErrCnt+iAbnoCnt)){
		sprintf(msg,"���������ƽ��%d!=%d+%d+%d",
			iCnt,iNormalCnt,iErrCnt,iAbnoCnt);
		return -1;
	}
	GetBaseName(sOutName,sTemp);
	strncpy(Temp.sDataDate,sTemp,8);
	strcpy(Temp.sDataDate+8,"000000");
	
	strncpy(sTempDate,Temp.sDataDate,8);sTempDate[8]=0;

/*��ȡ�����ļ�*/
	if(InitTinySplitList(p->sSourceID,sOutName,&pTinySplit)<0)
		return -1;

	if(iChkDupFlag==true&&iNormalCnt!=0){
		if(ChkPrepDup(p,sOutName,sSplitStr,pTinySplit,&iDupCnt)<0)
			return -1;
	}

	GetHostTime(Temp.sDealEndDate);

/*���������ض�SOURCE_ID���ض�DATA_DATE,��������ͻֱ���˳�*/
	GetLogLock("PREP",Temp.sSourceID,Temp.sDataDate,sLockName);
	iRet=LockLog(sLockName,msg);
	if(iRet!=0){
		WriteAlertMsg("��Ϣ:%s�������˳�",msg);
		return -1;
	}

	strcpy(sPrefix,"");
	if(iCnt!=0){
		if((Temp.iSeq=GetPrepNextSeq(sTempSource,
			Temp.sDataDate,Temp.sModule))<0)return -1;
		sprintf(sPrefix,"%s%s%05d",sTempSource,sTempDate,Temp.iSeq);
	}
	
	if(GetPrepLogList(pTinySplit,sSplitStr,iAbnoCnt,iErrCnt,sOutName,
		sPrefix,p->sNormalPath,p->sErrPath,&Temp,&pLogList)<0) return -1;
	
/*���������ͻ����������ԣ�����������־ƽ��*/
	if(GetFileTypeCnt(pLogList,'E')!=iErrCnt){
		sprintf(msg,"Ԥ����������������ƽ��,in=%d,out=%d",
			iErrCnt,GetFileTypeCnt(pLogList,'E'));
		return -1;
	}
	if(GetFileTypeCnt(pLogList,'D')!=iDupCnt){
		sprintf(msg,"Ԥ�����ص���ƽ��,out0=%d,out1=%d",
			iDupCnt,GetFileTypeCnt(pLogList,'D'));
		return -1;
	}
	if(GetFileTypeCnt(pLogList,'A')!=iAbnoCnt){
		sprintf(msg,"Ԥ�������������쳣����ƽ��,in=%d,out=%d",
			iAbnoCnt,GetFileTypeCnt(pLogList,'A'));
		return -1;
	}
	if(GetFileTypeCnt(pLogList,'C')!=(iNormalCnt-iDupCnt)){
		sprintf(msg,"Ԥ��������������������ƽ��,in=%d,out=%d",
			iNormalCnt,GetFileTypeCnt(pLogList,'C'));
		return -1;
	}

/*��������ɻ�ȡ�Ĳ�������PREPLOG��¼��־*/
	if(WriteList2PrepLog(pLogList,&Temp,sBaseName,iByte,iCnt,
		p->sInType)<0){
		sprintf(msg,"дPREP_LOGʧ��");
		return -1;
	}
/*���������ļ��Ƶ�����Ŀ¼*/
	sprintf(sTargetName,"%s%s",p->sBackPath,sBaseName);

	if(Rename(sTempName,sTargetName)!=0){
		sprintf(msg,"ִ�б����ļ�%s��%sʧ��",
			sTempName,p->sBackPath);
		return -1;
	}

/*������ļ�����Ϊ��ʽ����ļ���*/
	if(RenameOutputFile(pLogList,p->sNormalPath,p->sErrPath)<0) return -1;

	DestroyList((LIST*)pTinySplit);
	RemoveFileSplit(p->sSourceID,sOutName);

	/*��־����*/
	UnlockLog(sLockName);

/*�õ�������ļ������б�*/
	GetMyTargetName(sPrefix,p->sModule,sSplitStr,sNewName);

	return 0;
}
int ProcessMain(struct PrepParamStruct *pParam)
{
	int iChkDupFlag;
	char msg[2048];
	char sExprFile[256],sFileName[256],sTempName[256],sTargetName[2048];
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;

	sprintf(sExprFile,"%s%s",EXPRPATH,pParam->sExprFile);
	if(IsFile(sExprFile)==FALSE){
		printALERT("�����ļ�%s��Ч",sExprFile);
		return -1;
	}
/*���Ŀ¼�Ƿ���Ч����Ч��������*/
	CheckDir(pParam->sSourcePath);
	CheckDir(pParam->sBackPath);
	CheckDir(pParam->sNormalPath);
	CheckDir(pParam->sErrPath);

	iChkDupFlag=WantChkDup(pParam->sChkMod);

/*����һ���ļ��б�*/
	if(dir2list(pParam->sSourcePath,pParam->sFilter,&ptHead)<0){
		printALERT("�����ļ��б�ʧ�� %s %s",
			pParam->sSourcePath,pParam->sFilter);
		return -1;
	}
/*�Ƚ���������*/
	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

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

		
	/*����ļ��Ƿ񱻴�������������򲻴�����*/
		if(PrepLogCheck(pParam->sSourceID,sFileName,pParam->sModule)==1){
			printNORMAL("�ļ�%s�Ѵ���",sFileName);
			continue;
		}
	/*����ļ��ֽ���Ϊ0�򱸷�*/
		if(FileSize(sTempName)<=2){
			struct PrepProcLogStruct Temp;

			bzero((void*)&Temp,sizeof(struct PrepProcLogStruct));

			strcpy(Temp.sSourceID,pParam->sSourceID);
			strcpy(Temp.sModule,  pParam->sModule);
			strcpy(Temp.sFileName,sFileName);
			GetHostTime(Temp.sDealBeginDate);
			GetHostTime(Temp.sDealEndDate);
			strcpy(Temp.sFileType,pParam->sInType);	
			strcpy(Temp.sAppID,pParam->sAppID);
			Temp.iTacheID=	pParam->iTacheID;

			if(SDInsertStructToPrepProcLog(&Temp,"PREP_PROC_LOG")<0){
				sprintf(msg,"дPREP_PROC_LOG��ʧ��,�ļ�%s",sFileName);
				return -1;
			}
			sprintf(sTargetName,"%s%s",pParam->sBackPath,sFileName);
			if(Rename(sTempName,sTargetName)!=0){
				sprintf(msg,"ִ�б���0�ֽ��ļ�%s��%sʧ��",
					sTempName,pParam->sBackPath);
				return -1;
			}
			printNORMAL("�ɹ�����0�ֽ��ļ� %s �� %s",sTempName,pParam->sBackPath);
	
			CommitWork();

			continue;
		}
		if(ProcessFile(sFileName,sExprFile,pParam,iChkDupFlag,
			sTargetName,msg)<0){
			
			listfree(&ptLkHead);
			printALERT("Ԥ�����ļ� %sʧ��,��Ϣ%s.",
				sFileName,msg);
			return -1;
		}
		CommitWork();
		printNORMAL("�ɹ�Ԥ�������ļ� %s ���� %s",sFileName,sTargetName);
	}
	
	listfree(&ptLkHead);	
	return 0;
}

int main(int argc,char *argv[])
{
	int iGroupID,iRet;
	char sFileName[256];
	struct PrepParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc!=3){
		printf("Usage %s shm|prep.ini|flowxxxx groupid .\n",argv[0]);
		return 0;
	}
	
	InitAppRes("prep.sh");

	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	
	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*��ʼ��PREPӦ��λ�ú͹�ʽ·����ȫ�ֱ���*/
	if(InitPrepCtl()<0) return -1;

/*����Ҫ����Ĳ�����ȡ�� ������*/
	if(GetPrepParamList(sFileName,iGroupID,&ptHead)<0) return -1;
	
	if(ConnectDataDB()<0){
		WriteErrStackAlert();
		return -1;
	}

	ptLkHead=ptHead;
	
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if((iRet=ProcessMain(pTemp))<0){
			
			RollbackWork();
			DisconnectDatabase();
			return -1;
		}
		if(iRet>0) break;
		
		CommitWork();
		if(WantQuit()==true)break;
	}

/*�ͷ��ڴ�*/
	DestroyList((LIST*)ptLkHead);
	
	DisconnectDatabase();

	return 0;
}

int InitPrepCtl()
{
	char sPath[256];

	GetBillHome(sPath);
	
	sprintf(PREP,"%sbin/prep",sPath);
	sprintf(EXPRPATH,"%sexpr/",sPath);
	sprintf(CHKDUP,"%sbin/chkdup",sPath);
	
	if(IsFile(PREP)==FALSE){
		printf("�����ļ�%s��Ч.\n",PREP);
		return -1;
	}
	if(IsDir(EXPRPATH)==FALSE){
		printf("�������Ŀ¼%s��Ч.\n",EXPRPATH);
		return -1;
	}
	return 0;
}
