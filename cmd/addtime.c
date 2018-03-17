#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <wwtiny.h>

int main(int argc,char *argv[])
{
	int t;
	char sDate1[128];
	
	if(argc!=3) return -1;
	
	strcpy(sDate1,argv[1]);
	t=	atoi(argv[2]);
	if(strlen(sDate1)==8) strcpy(sDate1+8,"000000");
	else	sDate1[15]=0;
	AddTimes(sDate1,t);
	printf("%s",sDate1);
	return 0;
}
