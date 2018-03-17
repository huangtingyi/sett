#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <wwdir.h>
#include <dbsupp.h>

int main(int argc,char *argv[])
{
/*billinglog $source $module $filename $byte \
$handlecnt $cnt $errcnt $abnocnt $datadate $dealbegindate $dealenddate*/

	int  iByte;
	char sNormalPath[256],sErrPath[256],sOriFileName[256];
	char sInType[32],sSplitStr[10],sPrefix[128];
	struct BillingLogStruct Temp;
	
	
	if(argc!=17){
		printf("Usage %s $source $module $filename $byte \
$cnt $datadate $dealbegindate $dealenddate str normalpath errpath \
intype outtype appcode tacheid appid.\n",argv[0]);
		return -1;
	}
	
	if(ConnectDataDB()<0) return -1;
	
	bzero((void*)&Temp,sizeof(struct BillingLogStruct));
	
	strcpy(Temp.sSourceID,argv[1]);
	strcpy(Temp.sModule,	argv[2]);
	strcpy(sOriFileName,	argv[3]);
	iByte=			atoi(argv[4]);
	Temp.iCnt=		atoi(argv[5]);

	TrimAll(Temp.sSourceID);
	TrimAll(Temp.sModule);
	
	strcpy(Temp.sDataDate,	argv[6]);
	strcpy(Temp.sDataDate+8,	"000000");
	
	strcpy(Temp.sDealBeginDate,	argv[7]);
	strcpy(Temp.sDealEndDate,	argv[8]);
	strcpy(sSplitStr,		argv[9]);
	strcpy(sNormalPath,		argv[10]);
	strcpy(sErrPath,		argv[11]);
	strcpy(sInType,			argv[12]);
	strcpy(Temp.sFileType,		argv[13]);
	strcpy(Temp.sAppCode,		argv[14]);
	Temp.iTacheID			=atoi(argv[15]);
	strcpy(Temp.sAppID,		argv[16]);

	RegularDir(sNormalPath);
	RegularDir(sErrPath);
	
	strcpy(Temp.sState,"A");
	if(Temp.iCnt==0) strcpy(Temp.sState,"E");
	
	
	if(InsertBillingLog(Temp.sSourceID,Temp.sModule,sOriFileName,
		iByte,Temp.iCnt,Temp.sDataDate,Temp.sDealBeginDate,
		Temp.sDealEndDate,Temp.sState,sSplitStr,sNormalPath,
		sErrPath,sInType,Temp.sFileType,Temp.sAppCode,
		Temp.iTacheID,Temp.sAppID,sPrefix)<0){
		
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();

	DisconnectDatabase();
	
	printf("%s\n",sPrefix);
	
	return 0;
}
