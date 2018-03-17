#include <stdio.h>
#include <stdlib.h>
#include "wwfile.h"
#include "wwdb.h"

int main(int argc,char *argv[])
{
	char sUserId[64];

	if(argc!=2){
		printf("Usage %s sUserId .\n",argv[0]);
		return -1;
	}

	/*获取参数*/
	strcpy(sUserId,argv[1]);
	
	GetConnStr(sUserId);
			
	return 0;
}

