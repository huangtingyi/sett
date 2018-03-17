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
		printf("�����ļ�%s��Ч.\n",RCYL);
		return -1;
	}
	return 0;
}


int GetLockLogSeq(char sLockName[],int iSeq,char msg[])
{
	char sCommand[256],sResult[256],sTemp[6];

	strcpy(msg,"");

	/*�ļ���������*/
	if(!IsFile(sLockName)){
		sprintf(sCommand,"echo start %05d %d > %s ",iSeq,getpid(),sLockName);
	
		if(exec2str(sCommand,sResult)!=0){
			sprintf(msg,"ִ��%sʧ��",sCommand);
			return -1;
		}
		sprintf(msg,"%05d",iSeq);
		return 0;
	}
	/*�ļ��������Ƿ���start,���seq+1*/
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
	/*����Ѿ��������Լ�����*/
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
                printALERT("����������Ϊ%s,%s,%s",
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

/*��ʼ��RESYSLEӦ��λ��*/
	if(InitRcylCtl()<0) return -1;

/*����Ҫ����Ĳ�����ȡ�� ������*/
	if(GetRcylParamList(sFileName,sSourceID,iTaskSeqNbr,&ptHead)<0)
		return -1;
	
	if(ConnectDataDB()<0){
		printALERT("�������ݿ�ʧ��");
		return -1;
	}


	ptLkHead=ptHead;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(iTaskSeqNbr!=pTemp->iTaskSeqNbr)continue;
		
		if(IsDir(pTemp->sNormalPath)==false){
		        printALERT("���·��%s��Ч",pTemp->sNormalPath);
		        return -1;
		}
		/*�����ó����д���endtimeʱ���������ļ�����ʱ�䰴endtime����*/
		GetHostTime(sHostTime);
		strcpy(sDealBeginDate,sHostTime);
		/*�����ó����д���endtimeʱ���������ļ�����ʱ�䰴endtime����*/
		if(tGetTime(sEndTime)>0)strcpy(sHostTime,sEndTime);

		strncpy(sHostDate,sHostTime,8);sHostDate[8]=0;

		strcpy(sDataDate,sHostDate);strcat(sDataDate,"000000");
		iSeq=GetRcylNextSeq(pTemp->sSourceID,sDataDate,pTemp->sModule);

/*���������ض�SOURCE_ID���ض�DATA_DATE,��������ͻ���ȡ���ļ�����*/
		GetLogLock(sAppCode,pTemp->sSourceID,sDataDate,sLockName);
		iRet=GetLockLogSeq(sLockName,iSeq,msg);
		
		if(iRet!=0)iSeq++;

		sprintf(sTargetName,"%s%s%05d.RCL",
			pTemp->sSourceID,sHostDate,iSeq);
		
		/*�������滻Ϊʵ�ʵı���*/
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
			
			/*���ǵ�����������ļ��������ǰ�endtime����������
			����Ϊ>= and <=����������ļ�����ʱ���ǵڶ�����ļ�*/
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
	
			sprintf(sMessage,"����ʧ��,ִ�� %s",sCommand);
			return -1;
		}
		
		GetSepStrX(sLine,'\t',4,20,sSplitNew);
		
		/*���û����ļ���д��־*/
		if(strlen(sSplitNew)==0) continue;		

		GetHostTime(sDealEndDate);
		
		if(InsertRcylLog(pTemp->sSourceID,pTemp->sModule,sTargetName,
			iSeq,sDataDate,sDealBeginDate,sDealEndDate,
			pTemp->sNormalPath,pTemp->sFileType,sAppCode,
			pTemp->iTacheID,pTemp->sAppID)!=0){
			sprintf(sMessage,"д��־����, %s",sCommand);
			return -1;	
		}

		/*��������ļ��Ƶ���ʽ�ļ���*/
		sprintf(sTargetTemp,"%s%s",pTemp->sNormalPath,sTargetName);
		
		for(l=0,i=0;i<strlen(sSplitNew);i++){
			sprintf(sCommand,"mv %s.%c.tmp %s.%c",
				sTargetTemp,sSplitNew[i],sTargetTemp,sSplitNew[i]);
			system(sCommand);
			l+=sprintf(sTempName+l," %s.%c",sTargetName,sSplitNew[i]);
		}

		RemoveRollLogCtl(sTargetName);
		/*��־����*/
		UnlockLogSeq(sLockName,iSeq);

		CommitWork();
		printNORMAL("�ɹ������ļ�%s",sTempName);
		
		if(WantQuit()==true){
			WriteProcMsg("���յ��˳��źţ������˳�");
			break;
		}
		
	}
	
	DestroyList((LIST*)ptLkHead);

	DisconnectDatabase();	
	return 0;
}

