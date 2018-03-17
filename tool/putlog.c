#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

int main(int argc,char *argv[])
{
/*** $source $size1 $filename $dealbegindate $dealenddate $seq $filetype*/
	struct PickLogStruct Temp;

	if(argc!=10){
		printf("Usage %s $source $size1 $filename $dealbegindate $dealenddate \
		 $seq $filetype $tacheid $appid.\n",
			argv[0]);
		return -1;
	}
	
	if(ConnectDataDB()<0) return -1;
	
	bzero((void*)&Temp,sizeof(struct PickLogStruct));
	
	strcpy(Temp.sSourceID,		argv[1]);
	Temp.iByte=			atoi(argv[2]);
	strcpy(Temp.sFileName,		argv[3]);
	strcpy(Temp.sDealBeginDate,	argv[4]);
	strcpy(Temp.sDealEndDate,	argv[5]);
	Temp.iSeq=			atoi(argv[6]);
	strcpy(Temp.sFileType,		argv[7]);
	Temp.iTacheID=			atoi(argv[8]);
	strcpy(Temp.sAppID,		argv[9]);
	
	TrimAll(Temp.sSourceID);

	if(InsertPutLog(Temp.sSourceID,Temp.iByte,Temp.sFileName,
		Temp.sDealBeginDate,Temp.sDealEndDate,Temp.iSeq,
		Temp.sFileType,Temp.iTacheID,Temp.sAppID)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	DisconnectDatabase();
	
	return 0;
}
