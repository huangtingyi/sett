#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

int main(int argc,char *argv[])
{
	int iMaxCnt;
	char sTableName[31];
	
	if(argc!=3){
		printf("Usage %s tabname maxcnt\n",argv[0]);
		return -1;
	}	
	
	strcpy(sTableName,argv[1]);
	iMaxCnt=atoi(argv[2]);
	
	if(IniConnect("dataconnstr")<0){ 
	        printf("connerror\n");
		return -1;	
	}

	PrintMissTrunk(sTableName,iMaxCnt);
	PrintErrTicket(sTableName,iMaxCnt);

	DisconnectDatabase();
			
	return 0;
}
