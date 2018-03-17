#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "hnixs.h"

#include "wwtiny.h"
#include "wwsem.h"


int main(int argc,char *argv[])
{
	int iSemID,i;
	long bgn,end;
	struct   timeval tv;
	struct timezone  tz;
	char	sHostDate[15];
	key_t key=0x5100;

	if(argc!=2){
		printf("Usage: %s c\n",argv[0]);
		return -1;
	}

	if((iSemID=CreateSem(key,1))<0){
		if((iSemID=AttachSem(key))<0){
			printf("create semid error.\n");
			return -1;
		}
	}
	
	printf( " semid:%d \n", iSemID );
	usleep(3000000);
	printf( " I will get..., enter return please\n" );
/*	getchar();*/
	

	while(1){
		i=0;
		LockSem(iSemID);
		
		GetHostTime(sHostDate);
		gettimeofday(&tv,&tz);
		bgn=tv.tv_usec;
		printf("time=%s,%s,%s lock it\n",sHostDate,argv[0],argv[1]);

		while(i<6){
			/*printf("%s,i=%d,%d\n",argv[1],i,iSemID);*/
			usleep(5);
			i++;
		}
		GetHostTime(sHostDate);
		gettimeofday(&tv,&tz);
		end=tv.tv_usec;
		printf("time=%s,%s,%s unlock it[%ld--%ld]\n",sHostDate,argv[0],argv[1],bgn,end);
		UnlockSem(iSemID);
		usleep(10);
	}

	return 0;
}

