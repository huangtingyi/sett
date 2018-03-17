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
		printALERT("文件%s无效.",GETTABLE);
		return -1;
	}
	return 0;	
}
int InsertLogCheck(char sSourceID[], char sFileName[],char sModule[])
{
	char sCondition[256];
        struct AcctLogStruct Temp;
/*检查入库日时志。*/
	sprintf(sCondition,"WHERE SOURCE_ID='%s' AND \n\
		FILE_NAME='%s' AND      \n\
		MODULE='%s' AND \n\
		STATE='A'",sSourceID,sFileName,sModule);
	return SDGetAcctLogToStruct(&Temp,"INSERT_LOG",sCondition);
}
/*不判断备份文件异常*/
void BackupInstFile(char sFileName[],char sBackPath[])
{
	char sCommand[1024],sTargetName[256];

/*去掉.tmp文件扩展名*/
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
	
/*生成一个文件列表*/
	if(dir2list(pParam->sSourcePath,pParam->sFilter,&ptHead)<0){
		printALERT("获取目录%s的%s模式的文件列表失败",
			pParam->sSourcePath,pParam->sFilter);
		return -1;
	}
	
	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		
		pTemp = ptHead;
		ptHead = ptHead->pNext;
		
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
		
		if(InsertLogCheck(pParam->sSourceID,sFileName,pParam->sModule)==true){
			printNORMAL("文件%s已入库，被备份到%s目录",
				sFileName,pParam->sBackPath);
			BackupInstFile(sTempName,pParam->sBackPath);
			continue;
		}
	/*调用通用入库函数入库*/
		if(ProcessFile(pParam,sTempName)<0){
			RollbackWork();
			return -1;
		}		
	        CommitWork();
	}
/*释放文件列表*/
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

/*获取DATA_DATE字段*/
	FileBackupDate(sFileName,ptHead->sDateRule,sDataDate);
	if(strcmp(sDataDate,"")==0){
		if(FileModifyDate(sFileName,sDataDate)!=0){
			printALERT("文件%s不可访问",sFileName);
			return -1;
		}
	}
		
/*写入库日志*/
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

/*获取改入库的表名*/
	if(GetTableName(ptHead->sModule,sBaseName,ptHead->sBelongCode,
		GETTABLE,sTableName)!=0){
			
		printALERT("模块%s,区号%s,文件%s获取表失败",
			ptHead->sModule,ptHead->sBelongCode,sBaseName);
		return -1;	
	}
	strcpy(Temp.sOperType,  ptHead->sOperType);
	strcpy(Temp.sFileType,  ptHead->sFileType);
	strcpy(Temp.sTableName,  sTableName);	
/*将待入库的文件名改为临时文件*/
	if(execcmd("mv %s %s",sFileName,sTempName)!=0){
		printALERT("将文件%s移动到%s文件失败",sFileName,sTempName);
		return -1;
	}
	
/*调用主入库函数入库*/
	if((iCnt=InsertTicket(sTempName,sTableName,sType))<0){
		printALERT("对表%s 入库文件%s失败",sTableName,sFileName);
		return -1;
	}
	Temp.iCnt=iCnt;
	GetHostTime(Temp.sDealEndDate);
	if(SDInsertStructToAcctLog(&Temp,"INSERT_LOG")<0){
		printALERT("写INSERT_LOG日志错误");
	        WriteErrStackAlert();
	        return -1;
	}
/*进行文件备份和改名*/
	BackupInstFile(sTempName,ptHead->sBackPath);
	
	printNORMAL("文件 %s 插入表 %s 成功,记录数 %d",
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

/*初始化INS2DB应用位置和公式路径到全局变量*/
	if(InitInstCtl()<0) return -1;

/*将需要处理的参数获取到 链表中*/
	if(GetInstParamList(sFileName,iGroupID,&ptHead)<0) return -1;

	if(ConnectDataDB()<0){
		printALERT("连结数据库失败");
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(IsDir(pTemp->sSourcePath)==false){
		        printALERT("输入路径%s无效",pTemp->sSourcePath);
		        return -1;
		}
	/*如果备份目录为空，作为不备份处理*/
		if(IsDir(pTemp->sBackPath)==false&&
			strcmp(pTemp->sBackPath,"")!=0){
		        printALERT("备份路径%s无效",pTemp->sBackPath);
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

