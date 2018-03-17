#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "md5.h"

int main(int argc, char *argv[])
{
	char inFile[1024],sOutput[33];
	
	if(argc!=2){
		printf("Usage:%s inFile\n",argv[0]);
		exit(1);
	}
	strcpy(inFile,argv[1]);
	GetFileMD5(inFile,sOutput);
	printf("%s",sOutput);
	
	return 0;
}
