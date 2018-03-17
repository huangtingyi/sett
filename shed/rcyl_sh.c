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

char RCYL[256];
int InitRcylCtl();
int InitRollCtl();
int GetLockLogSeq(char sLockName[],int iSeq,char msg[]);
void UnlockLogSeq(char sLockName[],int iSeq);

int InitRcylCtl()
{	
	if(IsFile(RCYL)==FALSE){
		printf("输入文件%s无效.\n",RCYL);
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
	int iSeq=0,iTaskSeqNbr,iFlag=0,i,l,iUpdateFlag=0,iRet;
	char sMessage[2048],sSourceID[7],sTargetName[256],sTableName[256];
	char sFileName[256],sCommand[1024],sLine[1024],sMonth[3];
	char sHostTime[15],sHostDate[9],sTargetTemp[256],sPath[256];
	char sDealBeginDate[15],sDealEndDate[15],sDataDate[15],sTempName[256];
	char sDeginTime[15],sEndTime[15],sCondition[1024],sSplitNew[21];
	char sLockName[256],sAppCode[9],msg[2048],sMsc[11],sUserType[2];
	char sAddCond[256],sFieldName[31];
	struct RcylParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	if(argc!=6&&argc!=8){
		printf("Usage %s shm|billrcyl.ini|ratercyl.ini|flowxxxx "
			"sSourceID taskseq month update[0,1] [begintime endtime].\n",argv[0]);
		return -1;
	}	
	
	GetBillHome(sPath);
	
        if(RLike(argv[0],"billrcyl_sh")==true){
                InitAppRes("billrcyl.sh");
                sprintf(RCYL,"%sbin/billrcyl",sPath);
                strcpy(sAppCode,"BILLRCYL");
        }
        else if(RLike(argv[0],"ratercyl_sh")==true){
                InitAppRes("ratercyl.sh");
                sprintf(RCYL,"%sbin/ratercyl",sPath);
                strcpy(sAppCode,"RATERCYL");
        }
        else if(RLike(argv[0],"preprcyl_sh")==true){
                InitAppRes("preprcyl.sh");
                sprintf(RCYL,"%sbin/preprcyl",sPath);
                strcpy(sAppCode,"PREPRCYL");
        }
        else{
                printALERT("程序名必须为%s,%s,%s",
                	"billrcyl_sh","ratercyl_sh","preprcyl_sh");
                return -1;
        }


	strcpy(sFileName,argv[1]);
	strcpy(sSourceID,argv[2]);sSourceID[6]=0;
	iTaskSeqNbr=atoi(argv[3]);
	strcpy(sMonth,argv[4]);sMonth[2]=0;
	iUpdateFlag=atoi(argv[5]);

	strcpy(sDeginTime,"");	
	strcpy(sEndTime,"");	
	
	if(argc==8){
		iFlag=1;
		strcpy(sDeginTime,argv[6]);sDeginTime[14]=0;
		strcpy(sEndTime,argv[7]);sEndTime[14]=0;
		if(tGetTime(sDeginTime)<0||tGetTime(sEndTime)<0) return -1;
	}
	
	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*初始化RESYSLE应用位置*/
	if(InitRcylCtl()<0) return -1;

/*将需要处理的参数获取到 链表中*/
	if(GetRcylParamList(sFileName,sSourceID,iTaskSeqNbr,&ptHead)<0)
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
		/*当调用程序有传入endtime时，则生成文件名的时间按endtime生成*/
		GetHostTime(sHostTime);
		strcpy(sDealBeginDate,sHostTime);
		/*当调用程序有传入endtime时，则生成文件名的时间按endtime生成*/
		if(tGetTime(sEndTime)>0)strcpy(sHostTime,sEndTime);

		strncpy(sHostDate,sHostTime,8);sHostDate[8]=0;

		strcpy(sDataDate,sHostDate);strcat(sDataDate,"000000");
		iSeq=GetRcylNextSeq(pTemp->sSourceID,sDataDate,pTemp->sModule);

/*这里锁定特定SOURCE_ID和特定DATA_DATE,对于锁冲突则读取锁文件处理*/
		GetLogLock(sAppCode,pTemp->sSourceID,sDataDate,sLockName);
		iRet=GetLockLogSeq(sLockName,iSeq,msg);
		
		if(iRet!=0)iSeq++;

		sprintf(sTargetName,"%s%s%05d.RCL",
			pTemp->sSourceID,sHostDate,iSeq);
		
		/*将表名替换为实际的表名*/
		strcpy(sTableName,pTemp->sTableName);
		ReplaceStr(sTableName,"$MM$",sMonth);
		
		strcpy(sCondition,pTemp->sCondition);
		ReplaceStr(sCondition,"\"","");
		
		if(iFlag==1){

			AllTrim(sCondition);
			l=strlen(sCondition);
			
			strcpy(sFieldName,"START_TIME");
			if(strncmp(sTableName,"SMS_TICKET_SMG",14)==0)
				strcpy(sFieldName,"RECV_DATE_TIME");
			
			/*考虑到这里输出的文件名命名是按endtime命名，所以
			条件为>= and <=，避免输出文件名的时间是第二天的文件*/
			sprintf(sAddCond," %s >='%s' AND %s <='%s' \n\
				",sFieldName,sDeginTime,sFieldName,sEndTime);

			if(l==0)sprintf(sCondition,"WHERE %s",sAddCond);
			else	sprintf(sCondition+l," AND %s",sAddCond);			
		}

		sprintf(sTargetTemp,"%s%s",pTemp->sNormalPath,sTargetName);
		
	       	if(RLike(RCYL,"billrcyl")==true){
			sprintf(sCommand,"%s %s \"%s\" %s %s %s %s %s %s %s %d",
				RCYL,sTableName,sCondition,"P",
				pTemp->sExprFile,pTemp->sTemplateID,pTemp->sSplitStr,
				pTemp->sVisitCode,pTemp->sModule,sTargetTemp,iUpdateFlag);
	        }
	        else if(RLike(RCYL,"ratercyl")==true){
			sprintf(sCommand,"%s %s \"%s\" %s %s %s %s %s %s %s %d",
				RCYL,sTableName,sCondition,pTemp->sFileType,
				pTemp->sExprFile,pTemp->sTemplateID,pTemp->sSplitStr,
				pTemp->sVisitCode,pTemp->sModule,sTargetTemp,iUpdateFlag);
	        }
	        else if(RLike(RCYL,"preprcyl")==true){
	        	strcpy(sMsc,pTemp->sTemplateID);
	        	strncpy(sUserType,pTemp->sSplitStr,1);sUserType[1]=0;
	        	
			sprintf(sCommand,"%s %s \"%s\" %s %s %s %s %s %s %s %s %s %d",
				RCYL,sTableName,sCondition,"E",pTemp->sExprFile,
				sMsc,sUserType,pTemp->sVisitCode,pTemp->sModule,sSourceID,
				pTemp->sFileType,sTargetTemp,iUpdateFlag);
	        }
		
			
		if(exec2str(sCommand,sLine)!=0){
	
			sprintf(sMessage,"回收失败,执行 %s",sCommand);
			return -1;
		}
		
		GetSepStrX(sLine,'\t',4,20,sSplitNew);
		
		/*如果没输出文件则不写日志*/
		if(strlen(sSplitNew)==0) continue;		

		GetHostTime(sDealEndDate);
		
		if(InsertRcylLog(pTemp->sSourceID,pTemp->sModule,sTargetName,
			iSeq,sDataDate,sDealBeginDate,sDealEndDate,
			pTemp->sNormalPath,pTemp->sFileType,sAppCode,
			pTemp->iTacheID,pTemp->sAppID)!=0){
			sprintf(sMessage,"写日志出错, %s",sCommand);
			return -1;	
		}

		/*将输出的文件移到正式文件名*/
		sprintf(sTargetTemp,"%s%s",pTemp->sNormalPath,sTargetName);
		
		for(l=0,i=0;i<strlen(sSplitNew);i++){
			sprintf(sCommand,"mv %s.%c.tmp %s.%c",
				sTargetTemp,sSplitNew[i],sTargetTemp,sSplitNew[i]);
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

