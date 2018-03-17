#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

int main(int argc,char *argv[])
{
	int iDay;
	char	sSourceID[10];
	
	if(argc!=3){
		printf("Usage %s sourceid days\n",argv[0]);
		return -1;
	}	
	
	strcpy(sSourceID,argv[1]);
	iDay = atoi(argv[2]);
	
	if(IniConnect("dataconnstr")<0){ 
	        printf("connerror\n");
		return -1;	
	}

	PrintInsertLogCnt(sSourceID,iDay);
	
	DisconnectDatabase();
			
	return 0;		
}
