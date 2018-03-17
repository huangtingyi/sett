#include <stdio.h>
#include <dbsupp.h>
#include <string.h>
#include <wwdb.h>
#include <isselect.h>

int main()
{		
	int iCount=0;
	char *msisdn="13001000068";
	char *table="ALL_APP_INFO_NBR";
	if(IniConnect("dataconnstr")<0){
    	printf("error\n");
        return -1;
    }
    printf("success\n");
		iCount=IsInNBR(msisdn,table);
		printf("%d\n",iCount);return 0;

}
