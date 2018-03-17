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

char ROLL[256];
int InitRollCtl();
int GetLockLogSeq(char sLockName[],int iSeq,char msg[]);
void UnlockLogSeq(char sLockName[],int iSeq);

int InitRollCtl()
{
	
	if(IsFile(ROLL)==FALSE){
		printf("输入文件%s无效.\n",ROLL);
		return -1;
	}
	return 0;
}

int GetLockLogSeq(char sLockName[],int iSeq,char msg[])
{
	char sCommand[256],sResult[256],sTemp[6];

	strcpy(msg,"");

	/*文件不存在则*/
	if(!IsFile(sLockName)){
		sprintf(sCommand,"echo start %05d %d > %s ",iSeq,getpid(),sLockName);
	
		if(exec2str(sCommand,sResult)!=0){
			sprintf(msg,"执行%s失败",sCommand);
			return -1;
		}
		sprintf(msg,"%05d",iSeq);
		return 0;
	}
	/*文件存在则是否是start,则把seq+1*/
	while(1){

		if(!IsFile(sLockName)) break;

		if(ReadFileToBuf(sLockName,256,sResult,msg)<0)
			return -1;

		if(strncmp(sResult,"start",5)!=0) break;
		
		strncpy(sTemp,sResult+6,5);sTemp[5]=0;
		
		sprintf(msg,"%05d",atoi(sTemp)+1);
		
		sprintf(sCommand,"echo start %s %d > %s ",msg,getpid(),sLockName);
		system(sCommand);
		
		return 0;
	}
	/*如果已经解锁则自己进入*/
	sprintf(sCommand,"echo start %05d %d > %s ",iSeq+1,getpid(),sLockName);
	system(sCommand);
	
	sprintf(msg,"%05d",iSeq);
	return 0;
}
void UnlockLogSeq(char sLockName[],int iSeq)
{
	char sCommand[256],sResult[256],sTemp[6],sTemp1[6];


	ReadFileToBuf(sLockName,256,sResult,sTemp1);

	strncpy(sTemp,sResult+6,5);sTemp[5]=0;
	sprintf(sTemp1,"%05d",iSeq);
	
	if(strcmp(sTemp1,sTemp)==0){
		sprintf(sCommand,"rm -rf %s",sLockName);
		system(sCommand);
	}
}
int main( int argc, char **argv )
{
	int iSeq=0,iTaskSeqNbr,iFlag=0,i,l,iRet;
	char sMessage[2048],sSourceID[7],sTargetName[256],sTableName[256];
	char sParamName[256],sCommand[1024],sLine[1024],sModule[4];
	char sHostTime[15],sHostDate[9],sFileName[256],sMonth[3];
	char sDealBeginDate[15],sDealEndDate[15],sDataDate[15],sTempName[256];
	char sDeginTime[15],sEndTime[15],sCondition[1024],sSplitNew[10];
	char sLockName[256],sAppCode[9],msg[2048],sPath[256],sAddCond[256];
	struct RollParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc!=5&&argc!=7){
		printf("Usage %s shm|billroll.ini|rateroll.ini|flowxxxx "
			"sSourceID taskseq month [begintime endtime].\n",argv[0]);
		return -1;
	}	


	GetBillHome(sPath);

        if(RLike(argv[0],"billroll_sh")==true){
                InitAppRes("billroll.sh");
		sprintf(ROLL,"%sbin/billroll",sPath);
                strcpy(sAppCode,"BILLROLL");
        }
        else if(RLike(argv[0],"rateroll_sh")==true){
                InitAppRes("rateroll.sh");
                sprintf(ROLL,"%sbin/rateroll",sPath);
                strcpy(sAppCode,"RATEROLL");
	}
        else{
                printALERT("程序名必须为%s,%s","billroll_sh","rateroll_sh");
                return -1;
        }


	strcpy(sParamName,argv[1]);
	strcpy(sSourceID,argv[2]);sSourceID[6]=0;
	iTaskSeqNbr=atoi(argv[3]);
	strcpy(sMonth,argv[4]);sMonth[2]=0;

	strcpy(sDeginTime,"");	
	strcpy(sEndTime,"");	

	if(argc==7){
		iFlag=1;
		strcpy(sDeginTime,argv[5]);sDeginTime[14]=0;
		strcpy(sEndTime,argv[6]);sEndTime[14]=0;
		if(tGetTime(sDeginTime)<0||tGetTime(sEndTime)<0) return -1;
	}
	
	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*初始化RESYSLE应用位置*/
	if(InitRollCtl()<0) return -1;

/*将需要处理的参数获取到 链表中*/
	if(GetRollParamList(sParamName,sSourceID,iTaskSeqNbr,&ptHead)<0)
		return -1;
	
	if(ConnectDataDB()<0){
		printALERT("连结数据库失败");
		return -1;
	}


	ptLkHead=ptHead;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(iTaskSeqNbr!=pTemp->iTaskSeqNbr)continue;
		
		if(IsDir(pTemp->sNormalPath)==false){
		        printALERT("输出路径%s无效",pTemp->sNormalPath);
		        return -1;
		}
		
	/*调用billr程序*/
		GetHostTime(sHostTime);
		strcpy(sDealBeginDate,sHostTime);
		/*当调用程序有传入endtime时，则生成文件名的时间按endtime生成*/
		if(tGetTime(sEndTime)>0)strcpy(sHostTime,sEndTime);
		
		strncpy(sHostDate,sHostTime,8);sHostDate[8]=0;
		
		strcpy(sModule,"RLL");
		
		strcpy(sDataDate,sHostDate);strcat(sDataDate,"000000");
		iSeq=GetRollNextSeq(pTemp->sSourceID,sDataDate,sModule);
		
/*这里锁定特定SOURCE_ID和特定DATA_DATE,对于锁冲突则读取锁文件处理*/
		GetLogLock(sAppCode,pTemp->sSourceID,sDataDate,sLockName);
		iRet=GetLockLogSeq(sLockName,iSeq,msg);
		
		if(iRet!=0)iSeq++;

		sprintf(sTargetName,"%s%s%05d.RLL",pTemp->sSourceID,sHostDate,iSeq);
		sprintf(sFileName,"%s%s",pTemp->sNormalPath,sTargetName);
		
		/*将表名替换为实际的表名*/
		strcpy(sTableName,pTemp->sTableName);
		ReplaceStr(sTableName,"$MM$",sMonth);

		strcpy(sCondition,pTemp->sCondition);
		ReplaceStr(sCondition,"\"","");

		if(iFlag==1){
			AllTrim(sCondition);
			l=strlen(sCondition);

			/*考虑到这里输出的文件名命名是按endtime命名，所以
			条件为>= and <=，避免输出文件名的时间是第二天的文件*/
			sprintf(sAddCond," START_TIME >='%s' AND \n\
			 	START_TIME <='%s' \n\
				",sDeginTime,sEndTime);

			if(l==0)sprintf(sCondition,"WHERE %s",sAddCond);
			else	sprintf(sCondition+l," AND %s",sAddCond);
		}
		
		/*billroll和rateroll命令都一样*/
		sprintf(sCommand,"%s %s \"%s\" %s %s %s %s %s %s",
			ROLL,sTableName,sCondition,pTemp->sUserType,
			pTemp->sTemplateID,pTemp->sSplitType,
			pTemp->sVisitCode,pTemp->sModule,sFileName);

		if(exec2str(sCommand,sLine)!=0){
			sprintf(sMessage,"回收失败,执行 %s",sCommand);
			return -1;
		}

		GetSepStrX(sLine,'\t',4,9,sSplitNew);
		
		/*如果没输出文件则不写日志*/
		if(strlen(sSplitNew)==0) continue;
		
		GetHostTime(sDealEndDate);
		
		if(InsertRollLog(pTemp->sSourceID,sModule,sTargetName,
			iSeq,sDataDate,sDealBeginDate,sDealEndDate,
			pTemp->sNormalPath,pTemp->sFileType,sAppCode,
			pTemp->iTacheID,pTemp->sAppID)!=0){
			sprintf(sMessage,"写日志出错, %s",sCommand);
			return -1;	
		}

		/*将输出的文件移到正式文件名*/
		for(l=0,i=0;i<strlen(sSplitNew);i++){
			sprintf(sCommand,"mv %s.%c.tmp %s.%c",
				sFileName,sSplitNew[i],sFileName,sSplitNew[i]);
			system(sCommand);
			l+=sprintf(sTempName+l," %s.%c",sTargetName,sSplitNew[i]);
		}

		RemoveRollLogCtl(sTargetName);
		/*日志解锁*/
		UnlockLogSeq(sLockName,iSeq);

		CommitWork();
		printNORMAL("成功生成文件%s",sTempName);
		
		if(WantQuit()==true){
			WriteProcMsg("接收到退出信号，程序退出");
			break;
		}
		
	}
	
	DestroyList((LIST*)ptLkHead);

	DisconnectDatabase();	
	return 0;
}

