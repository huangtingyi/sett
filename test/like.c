#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>


int main(int argc,char *argv[])
{
	int ret;
	char sInput[256],sPattern[256];

	if(argc!=2){
		printf("Usage %s sth.\n",argv[0]);
		return -1;
	}
/*Like Test*/
	printf("Please input string:");
	fgets(sInput,sizeof(sInput),fdopen(1,"r"));
	TrimAll(sInput);
	strcpy(sPattern,argv[1]);
	printf("sInput is:%s|\n",sInput);
	printf("sPattern is:%s\n",sPattern);

	ret=Like(sInput,sPattern);
	printf("ret=%d\n",ret);

	return 0;
}

