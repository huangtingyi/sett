#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <wwtiny.h>

int main(int argc,char *argv[])
{
	time_t t1;
	char sDate1[15],sTime[15];
	struct tm *tm;

	if(argc!=2) return -1;
	
	strcpy(sDate1,argv[1]);

	if((t1=tGetTime(sDate1))<0) return -1;

	t1+=3600*8;

	if((tm = (struct tm*)localtime(&t1)) == (void*)0)
		return -1;
	if(tm->tm_isdst == 1){
                t1 -= 3600;
                if((tm = (struct tm *)localtime(&t1)) == NULL)
                        return -1;
        }

	if(strftime(sTime,15,"%Y%m%d%H%M%S",tm) == (size_t)0)
		return -1;
	
	printf("%s\n",sTime);
		
	return 0;
}

