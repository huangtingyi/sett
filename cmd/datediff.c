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
	char sDate1[15],sDate2[15];
	time_t t1,t2;
	if(argc!=3) return -1;
	
	strcpy(sDate1,argv[1]);
	strcpy(sDate1+8,"000000");
	strcpy(sDate2,argv[2]);
	strcpy(sDate2+8,"000000");

	if((t1=tGetTime(sDate1))<0) return -1;
	if((t2=tGetTime(sDate2))<0) return -1;

	printf("%d\n",(int)(t1-t2)/86400);
		
	return 0;
}

