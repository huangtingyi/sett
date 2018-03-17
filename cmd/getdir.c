#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>

int main(int argc,char *argv[])
{
	
	int i,iDay;
	
	char sHostTime[15],sTempTime[15];
	
	
	if(argc!=2){
		printf("Usage %s day.\n",argv[0]);
		return -1;
	}
		
/*初始化参数部分*/
	if ((iDay = atoi(argv[1])) == 0 ) {
		printf("请输入合法的天数.\n");
		return -1;
	}
	bzero(sHostTime,15);
		
	GetHostTime(sHostTime);
	
	/*取得指定个数的目录名,不含当天*/
	for(i=1;i<=iDay;i++){
		strcpy(sTempTime,sHostTime);
		AddDays(sTempTime ,-i);
		sTempTime[8] = 0;
		printf("%s ",sTempTime);	
	}
	printf("\n");		
	return 0;			
}

