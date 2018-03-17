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
	
	/*如果没有按key拆文件*/
	if(pTiny==NULL){
		for(i=0;i<strlen(sSplitStr);i++){

			/*只检查正常输出的话单*/
			if(GetLogFileType(sSplitStr[i])!='C') continue;
			
			sprintf(sTempName,"%s.%c.tmp",sOutName,sSplitStr[i]);
			
			if(ChkDupMain(ptHead->sChkMod,ptHead->sSourceID,
				sTempName,ptHead->sErrPath,msg)<0) return -1;
			if(GetSepCnt(msg,'\t')!=6){
				printALERT("ChkDupMain错误,输应为6个参数实际为 %s",msg);
				return -1;
			}
			GetSepStr(msg,'\t',1,sTemp);
			iDupCnt+=atoi(sTemp);
		}
		*piDupCnt=iDupCnt;
		return 0;
	}
	
	/*按KEY拆文件，直接读取控制文件*/
	ptCur=pTiny;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		/*只检查正常输出的话单*/
		if(GetLogFileType(sSplitStr[i])!='C') continue;
		
		sprintf(sTempName,"%s.%c.%s.tmp",
			sOutName,sSplitStr[i],ptPre->sKey);

		if(ChkDupMain(ptHead->sChkMod,ptHead->sSourceID,
			sTempName,ptHead->sErrPath,msg)<0) return -1;
		if(GetSepCnt(msg,'\t')!=6){
			printALERT("ChkDupMain错误,输应为6个参数实际为 %s",msg);
			return -1;
		}
		GetSepStr(msg,'\t',1,sTemp);
		iDupCnt+=atoi(sTemp);
		
	}
	*piDupCnt=iDupCnt;

	return 0;
}
/*得到一个PrepLogList列表，填写:file_name,cnt,file_type字段,
	并将输出文件修改为临时文件名字*/
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

		/*如果是异常单或错误话单*/
		if(sSplitStr[i]=='a'||sSplitStr[i]=='e'){
			sprintf(p->sFileName,"%s.%s.%c",
				sPrefix,p->sModule,sSplitStr[i]);
			
			if(sSplitStr[i]=='a')p->iCnt=iAbnoCnt;
			else		p->iCnt=iErrCnt;
			
			p->sFileType[0]=GetLogFileType(sSplitStr[i]);

			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("分配内存PrepLogStruct错误");
				return -1;
			}
			
			GetPathName(sOutName,sSourcePath);
			GetBaseName(sOutName,sErrName);

			if(sSplitStr[i]=='a')
				sprintf(sTempName,"%s%s.abn",sSourcePath,sErrName+8);
			else	sprintf(sTempName,"%s%s.err",sSourcePath,sErrName+8);

			sprintf(sTargetName,"%s%s.tmp",sErrPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("将%s改名为%s失败",sTempName,sTargetName);
				return -1;
			}
			continue;
		}
		
		sprintf(oriPrefix,"%s.%c",sOutName,sSplitStr[i]);
		sprintf(stdPrefix,"%s.%s.%c",sPrefix,p->sModule,sSplitStr[i]);
		
		/*错误话单或者忽略话单，以及未按KEY拆分的话单*/
		p->sFileType[0]=GetLogFileType(sSplitStr[i]);

		if(SearchTinySplit(pTinySplit,sSplitStr[i])==NOTFOUND){

			sprintf(sTempName,"%s.tmp",oriPrefix);

			p->iCnt=0;
			if(IsFile(sTempName))	p->iCnt=FileLines(sTempName);

			sprintf(p->sFileName,"%s",stdPrefix);

			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("分配内存PrepLogStruct错误");
				return -1;
			}
			sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("将%s改名为%s失败",sTempName,sTargetName);
				return -1;
			}
			/*写重单文件日志*/
			sprintf(sTempName,"%s.DUP",oriPrefix);
			if(!IsFile(sTempName))continue;
			
			strcpy(p->sFileType,"D");
			p->iCnt=FileLines(sTempName);

			sprintf(p->sFileName,"%s.DUP",stdPrefix);
			
			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("分配内存PrepLogStruct错误");
				return -1;
			}
			sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("将%s改名为%s失败",sTempName,sTargetName);
				return -1;
			}
			continue;
		}
		
		/*按key拆分的话单*/
		ptCur=pTinySplit;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			if(sSplitStr[i]!=ptPre->sSplitType[0]) continue;
			
			p->sFileType[0]=GetLogFileType(sSplitStr[i]);
			
			/*如果有对应的重单文件则写重单日志*/
			iDupCnt=0;
			sprintf(sTempName,"%s.%s.DUP",oriPrefix,ptPre->sKey);
			if(IsFile(sTempName)){
				sprintf(p->sFileName,"%s.%s.DUP",stdPrefix,
					ptPre->sKey);
				strcpy(p->sFileType,"D");
				p->iCnt=iDupCnt=FileLines(sTempName);

				if(item2List((LIST**)pptHead,(LIST*)p,
					sizeof(struct PrepLogStruct))<0){
					printALERT("分配内存PrepLogStruct错误");
					return -1;
				}
				sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
				if(Rename(sTempName,sTargetName)<0){
					printALERT("将%s改名为%s失败",sTempName,sTargetName);
					return -1;
				}
			}
			
			p->iCnt=ptPre->iCnt-iDupCnt;

			sprintf(p->sFileName,"%s.%s",stdPrefix,ptPre->sKey);

			if(item2List((LIST**)pptHead,(LIST*)p,
				sizeof(struct PrepLogStruct))<0){
				printALERT("分配内存PrepLogStruct错误");
				return -1;
			}
			sprintf(sTempName,"%s.%s.tmp",oriPrefix,ptPre->sKey);
			sprintf(sTargetName,"%s%s.tmp",sPath,p->sFileName);
			if(Rename(sTempName,sTargetName)<0){
				printALERT("将%s改名为%s失败",sTempName,sTargetName);
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
			printALERT("将%s改名为%s失败",sTempName,sTargetName);
			return -1;
		}
		WriteProcPrint("成功生成%s文件",ptHead->sFileName);
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

/*将被处理的文件修改一个临时文件名*/
	if(Rename(sFileName,sTempName)!=0){
		sprintf(msg,"改名 %s 到 %s 失败",sFileName,sTempName);
		return -1;
	}
	
/*如果调用预处理的程序失败则调用日志,写错误日志*/
	sprintf(sCommand,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d",PREP,
		sExprFile,sTempName,p->sNormalPath,p->sErrPath,
		p->sMsc,p->sAreaCode,p->sModule,p->sUserType,
		p->sSourceID,p->sInType,p->sSplit,p->iStartPos,p->iKeyLen);
	if(exec2str(sCommand,sLine)!=0){
		sprintf(msg,"预处理失败,执行 %s",sCommand);
		return -1;
	}
/*做一个输出参数的校验*/
	if(GetSepCnt(sLine,'\t')!=7){
		sprintf(msg,"预处理输出信息错误,应为7个参数实际为 %s",sLine);
		return -1;
	}
/*获取预处理命令输出的参数*/
	GetSepStr(sLine,'\t',0,sOutName);
	GetSepStr(sLine,'\t',1,sTemp);	iByte=atoi(sTemp);
	GetSepStr(sLine,'\t',2,sTemp);	iNormalCnt=atoi(sTemp);
	GetSepStr(sLine,'\t',3,sTemp);	iErrCnt=atoi(sTemp);
	GetSepStr(sLine,'\t',4,sTemp);	iAbnoCnt=atoi(sTemp);
	GetSepStr(sLine,'\t',5,sTemp);	iCnt=atoi(sTemp);
	GetSepStrX(sLine,'\t',6,20,sSplitStr);

	iDupCnt=0;

/*做一个话单平衡数校验，总记录和错误+异常平衡*/
	if(iCnt!=(iNormalCnt+iErrCnt+iAbnoCnt)){
		sprintf(msg,"输出话单不平衡%d!=%d+%d+%d",
			iCnt,iNormalCnt,iErrCnt,iAbnoCnt);
		return -1;
	}
	GetBaseName(sOutName,sTemp);
	strncpy(Temp.sDataDate,sTemp,8);
	strcpy(Temp.sDataDate+8,"000000");
	
	strncpy(sTempDate,Temp.sDataDate,8);sTempDate[8]=0;

/*读取控制文件*/
	if(InitTinySplitList(p->sSourceID,sOutName,&pTinySplit)<0)
		return -1;

	if(iChkDupFlag==true&&iNormalCnt!=0){
		if(ChkPrepDup(p,sOutName,sSplitStr,pTinySplit,&iDupCnt)<0)
			return -1;
	}

	GetHostTime(Temp.sDealEndDate);

/*这里锁定特定SOURCE_ID和特定DATA_DATE,对于锁冲突直接退出*/
	GetLogLock("PREP",Temp.sSourceID,Temp.sDataDate,sLockName);
	iRet=LockLog(sLockName,msg);
	if(iRet!=0){
		WriteAlertMsg("信息:%s，进程退出",msg);
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
	
/*检查各种类型话单的完整性，输入和输出日志平衡*/
	if(GetFileTypeCnt(pLogList,'E')!=iErrCnt){
		sprintf(msg,"预处理输入和输出错单不平衡,in=%d,out=%d",
			iErrCnt,GetFileTypeCnt(pLogList,'E'));
		return -1;
	}
	if(GetFileTypeCnt(pLogList,'D')!=iDupCnt){
		sprintf(msg,"预处理重单不平衡,out0=%d,out1=%d",
			iDupCnt,GetFileTypeCnt(pLogList,'D'));
		return -1;
	}
	if(GetFileTypeCnt(pLogList,'A')!=iAbnoCnt){
		sprintf(msg,"预处理输入和输出异常单不平衡,in=%d,out=%d",
			iAbnoCnt,GetFileTypeCnt(pLogList,'A'));
		return -1;
	}
	if(GetFileTypeCnt(pLogList,'C')!=(iNormalCnt-iDupCnt)){
		sprintf(msg,"预处理输入和输出正常单不平衡,in=%d,out=%d",
			iNormalCnt,GetFileTypeCnt(pLogList,'C'));
		return -1;
	}

/*将处理完成获取的参数调用PREPLOG记录日志*/
	if(WriteList2PrepLog(pLogList,&Temp,sBaseName,iByte,iCnt,
		p->sInType)<0){
		sprintf(msg,"写PREP_LOG失败");
		return -1;
	}
/*将处理后的文件移到备份目录*/
	sprintf(sTargetName,"%s%s",p->sBackPath,sBaseName);

	if(Rename(sTempName,sTargetName)!=0){
		sprintf(msg,"执行备份文件%s到%s失败",
			sTempName,p->sBackPath);
		return -1;
	}

/*将输出文件名改为正式输出文件名*/
	if(RenameOutputFile(pLogList,p->sNormalPath,p->sErrPath)<0) return -1;

	DestroyList((LIST*)pTinySplit);
	RemoveFileSplit(p->sSourceID,sOutName);

	/*日志解锁*/
	UnlockLog(sLockName);

/*得到输出的文件名字列表*/
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
		printALERT("输入文件%s无效",sExprFile);
		return -1;
	}
/*检查目录是否有效，无效则建立起来*/
	CheckDir(pParam->sSourcePath);
	CheckDir(pParam->sBackPath);
	CheckDir(pParam->sNormalPath);
	CheckDir(pParam->sErrPath);

	iChkDupFlag=WantChkDup(pParam->sChkMod);

/*生成一个文件列表*/
	if(dir2list(pParam->sSourcePath,pParam->sFilter,&ptHead)<0){
		printALERT("生成文件列表失败 %s %s",
			pParam->sSourcePath,pParam->sFilter);
		return -1;
	}
/*先将链表备份了*/
	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(WantQuit()==true){
			WriteProcMsg("接收到退出信号，程序退出");
			break;
		}
		
		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);

	/*如果文件刚被修改则不处理*/
		sprintf(sTempName,"%s%s",pParam->sSourcePath,sFileName);
		if(FileModifyDiff(sTempName)<1) continue;

		
	/*检查文件是否被处理，如果处理了则不处理了*/
		if(PrepLogCheck(pParam->sSourceID,sFileName,pParam->sModule)==1){
			printNORMAL("文件%s已处理",sFileName);
			continue;
		}
	/*如果文件字节数为0则备份*/
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
				sprintf(msg,"写PREP_PROC_LOG表失败,文件%s",sFileName);
				return -1;
			}
			sprintf(sTargetName,"%s%s",pParam->sBackPath,sFileName);
			if(Rename(sTempName,sTargetName)!=0){
				sprintf(msg,"执行备份0字节文件%s到%s失败",
					sTempName,pParam->sBackPath);
				return -1;
			}
			printNORMAL("成功备份0字节文件 %s 到 %s",sTempName,pParam->sBackPath);
	
			CommitWork();

			continue;
		}
		if(ProcessFile(sFileName,sExprFile,pParam,iChkDupFlag,
			sTargetName,msg)<0){
			
			listfree(&ptLkHead);
			printALERT("预处理文件 %s失败,信息%s.",
				sFileName,msg);
			return -1;
		}
		CommitWork();
		printNORMAL("成功预处理了文件 %s 生成 %s",sFileName,sTargetName);
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

/*初始化PREP应用位置和公式路径到全局变量*/
	if(InitPrepCtl()<0) return -1;

/*将需要处理的参数获取到 链表中*/
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

/*释放内存*/
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
		printf("输入文件%s无效.\n",PREP);
		return -1;
	}
	if(IsDir(EXPRPATH)==FALSE){
		printf("输出正常目录%s无效.\n",EXPRPATH);
		return -1;
	}
	return 0;
}
