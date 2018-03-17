#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

int main(int argc,char *argv[])
{

	int iFlag,iMaxDelayTime;
	
	char sTableName[32],sType[6];
	
	if(argc!=4){
		printf("Usage %s TableName MaxDelayTime vit/visit.\n",argv[0]);
		return -1;
	}
	
	strcpy(sTableName,argv[1]);
	iMaxDelayTime = atoi(argv[2]);
	strcpy(sType,argv[3]);
	sType[5] = 0;
		
	
	if(IniConnect("dataconnstr")<0){ 
	        printf("connerror\n");
		return -1;	
	}
	iFlag=PrintDataDelay(sType,sTableName);

	DisconnectDatabase();
			
	return iFlag;
}
