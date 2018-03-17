#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <wwfile.h>
#include <wwdir.h>
#include <dbsupp.h>

int main(int argc,char *argv[])
{

	int iByte,iCnt,iErrCnt,iAbnoCnt,iTacheID;
	char sSourceID[20],sModule[10],sOriFileName[128],sDataDate[15];
	char sDealBeginDate[15],sDealEndDate[15],sInFileType[10];
	char sState[2],sTempSource[7],sAppID[20];
	char sOutName[256],sSplitStr[40],sPrefix[40];
	
	if(argc!=15){
		printf("Usage %s source module filename datedate byte "
			"cnt errcnt abnocnt dealbegindate dealenddate "
			"splitstr outname,infiletype tacheid appid.\n",argv[0]);
		return -1;
	}
	
	if(ConnectDataDB()<0) return -1;
		
	strcpy(sSourceID,argv[1]);
	strcpy(sModule,	argv[2]);
	
	TrimAll(sSourceID);
	TrimAll(sModule);
	
	strcpy(sOriFileName,argv[3]);
	strcpy(sDataDate,	argv[4]);
	strcpy(sDataDate+8,	"000000");
	iByte=		atoi(argv[5]);
	iCnt=		atoi(argv[6]);
	iErrCnt=	atoi(argv[7]);
	iAbnoCnt=	atoi(argv[8]);
		
	strcpy(sDealBeginDate,	argv[9]);
	strcpy(sDealEndDate,	argv[10]);

	strcpy(sSplitStr,	argv[11]);
	strcpy(sOutName,	argv[12]);
	strcpy(sInFileType,	argv[13]);
	iTacheID=atoi(argv[14]);
	strcpy(sAppID,		argv[15]);

	strcpy(sState,"A");

	strncpy(sTempSource,sSourceID,6);sTempSource[6]=0;
	RightPad(sTempSource,6,'0');
	
	
	if(InsertPrepLog(sTempSource,sModule,sOriFileName,
		sDataDate,iByte,iCnt,iErrCnt,iAbnoCnt,sDealBeginDate,
		sDealEndDate,sSplitStr,sState,sOutName,
		sInFileType,iTacheID,sAppID,sPrefix)<0){

		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}

	CommitWork();
	
	DisconnectDatabase();
	
	printf("%s\n",sPrefix);

	return 0;
}
