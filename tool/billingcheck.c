#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

int main(int argc,char *argv[])
{
	int iFlag;
	char sSourceID[20],sFileName[80],sModule[10];
	
	if(argc!=4){
		printf("Usage %s $source $filename $module.\n",argv[0]);
		return -1;
	}
	strcpy(sSourceID,argv[1]);
	strcpy(sFileName,argv[2]);
	strcpy(sModule,argv[3]);
	
	TrimAll(sSourceID);
	TrimAll(sModule);
	
	if(ConnectDataDB()<0) return -1;	
	
	iFlag=BillingLogCheck(sSourceID,sFileName,sModule,"");
		
	DisconnectDatabase();
	
	return iFlag;
}
