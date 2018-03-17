#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwsupp.h>

int main(int argc,char *argv[])
{
	int iSize;
	char sFileSize[256],sCommand[256],sSize[1024];
	
	if(argc!=2) return -1;
	
	strcpy(sFileSize,argv[1]);
	
	sprintf(sCommand,"cat %s | head -1",sFileSize);
	if(exec2str(sCommand,sSize)!=0) return -1;

	iSize=GetFtpDirSize(sSize);
	
	printf("%d",iSize);
	return 0;
}
