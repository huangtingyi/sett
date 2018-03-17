
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <wwtiny.h>
#include <wwsupp.h>

int main(int argc,char *argv[])
{

	char sModifyTime[15];

	if(argc!=2) return -1;

	if(FileModifyDate(argv[1],sModifyTime)<0) return -1;
	
	sModifyTime[8]=0;

	printf("%s\n",sModifyTime);
		
	return 0;
}

