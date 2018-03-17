#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

int main(int argc,char *argv[])
{
	int iFlag,iChkDays;
	char sSourceID[20],sFileName[80];
	
	if(argc!=3&&argc!=4){
		printf("Usage %s source filename [chkdays].\n",argv[0]);
		return -1;
	}
	strcpy(sSourceID,argv[1]);
	strcpy(sFileName,argv[2]);

	if(argc==4) iChkDays=atoi(argv[3]);
	else	iChkDays=-1;
		
	if(ConnectDataDB()<0) return -1;
	
	iFlag=PutLogCheck(sSourceID,sFileName,iChkDays);
	
	DisconnectDatabase();
	
	return iFlag;
}
