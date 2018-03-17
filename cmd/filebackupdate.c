#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <wwtiny.h>
#include <wwsupp.h>

int main(int argc,char *argv[])
{	
	char sFileName[128],sDateRule[128],sBackupDate[15];

	if(argc!=3) return -1;

	strcpy(sDateRule,argv[1]);
	strcpy(sFileName,argv[2]);
	
	if(FileBackupDate(sFileName,sDateRule,sBackupDate)<0) return -1;
	
	sBackupDate[8]=0;

        printf("%s\n",sBackupDate);

        return 0;
}
	
