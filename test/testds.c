#include <stdio.h>
#include <stdlib.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <dbsupp.h>

int main(int argc,char *argv[])
{
	int iRet,iSeq=0;
	char sMessage[256],sTemp[1024],sFileType[4],sDataDate[15];

	struct DataSetStruct TempDs;
	
	ConnectDataDB();

	strcpy(sMessage,"");
	RegularDir(sMessage);

	iRet=InitStmtDs("SELECT * FROM TRUNK",
		&TempDs,100,sMessage);

	PrintDs(&TempDs);

	strncpy(sFileType,argv[1],3);sFileType[3]=0;
	
	system("date");
	
	iRet=GetLastSeqComm(sFileType,&iSeq);
	
	printf("getlastseqcdma %d %s %d.\n",iRet,sFileType,iSeq);
	
	system("date");
	iRet=GetLastDateSeq(sFileType,sDataDate,&iSeq);
	
	printf("getlastdateseq %d %s %s %d.\n",iRet,sFileType,sDataDate,iSeq);
	
	system("date");
	
	
	DisconnectDatabase();
	
	sprintf(sTemp,"INSERT INTO \\\nhehe.\n");
	printf(sTemp);
	DelSubStr(sTemp,"\\\n");
	printf(sTemp);
	
	return 0;
}
