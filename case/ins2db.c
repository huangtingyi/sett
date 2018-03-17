#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <stt_ticket.h>

int main(int argc,char *argv[])
{
	int iCnt,iTacheID;
	char sFileName[128],sTableName[31],sType[10],*pc;
	char sDataDate[20],sSourceID[20],sModule[20];
	char sBaseName[128],sCondition[256],sAppID[11],sOperType[10];
	struct AcctLogStruct Temp;
	
	if(argc!=10){
		printf("Usage %s filename tablename type datadate source opertype module appid tacheid.\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	
	strcpy(sFileName,argv[1]);	TrimAll(sFileName);
	strcpy(sTableName,argv[2]);	TrimAll(sTableName);
	strcpy(sType,	argv[3]);	sType[4]=0;	TrimAll(sType);
	strcpy(sDataDate,argv[4]);	sDataDate[8]=0;	TrimAll(sDataDate);
	strcpy(sSourceID,argv[5]);	sSourceID[6]=0;	TrimAll(sSourceID);
	strcpy(sOperType,argv[6]);	sOperType[3]=0;	TrimAll(sOperType);
	strcpy(sModule,argv[7]);	sModule[3]=0;	TrimAll(sModule);
	strcpy(sAppID,argv[8]);		sAppID[10]=0;	TrimAll(sAppID);
	iTacheID=atoi(argv[9]);
	
	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;
	
	if(IniConnect("dataconnstr")<0) return -1;
	
/*如果已经入库就算了*/
	sprintf(sCondition,"WHERE SOURCE_ID='%s' AND \n\
			FILE_NAME='%s' AND	\n\
			MODULE='%s' AND	\n\
			STATE='A'",sSourceID,sBaseName,sModule);
	if(SDGetAcctLogToStruct(&Temp,"INSERT_LOG",sCondition)==true) return 0;
	
	CommitWork();
	
	bzero((void*)&Temp,sizeof(struct AcctLogStruct));
	strcpy(Temp.sSourceID,	sSourceID);
	strcpy(Temp.sModule,	sModule);
	strcpy(Temp.sState,	"A");
	Temp.iByte=	FileSize(sFileName);
	strcpy(Temp.sFileName,	sBaseName);
	strcpy(Temp.sTableName,	sTableName);
	GetHostTime(Temp.sDealBeginDate);
	strcpy(Temp.sDataDate,sDataDate);
	strcpy(Temp.sDataDate+8,"000000");
	strcpy(Temp.sOperType,	sOperType);
	strcpy(Temp.sFileType,	sType);
	Temp.iTacheID=iTacheID;
	strcpy(Temp.sAppID,	sAppID);
	
	if((iCnt=InsertTicket(sFileName,sTableName,sType))<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	Temp.iCnt=iCnt;
	GetHostTime(Temp.sDealEndDate);
	
	if(SDInsertStructToAcctLog(&Temp,"INSERT_LOG")<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	CommitWork();
	
	return 0;
}

