#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/*int stat(const char *file_name, struct stat *buf);*/

int main(int argc,char *argv[])
{
	struct stat Temp;
	time_t tHostTime;

	if(argc!=2) return -1;

	bzero((void*)&Temp,sizeof(struct stat));

	if(stat(argv[1],&Temp)<0) return -1;

	if(time(&tHostTime)<0) return -1;

	printf("%ld\n",tHostTime-Temp.st_mtime);	
		
	return 0;
}
