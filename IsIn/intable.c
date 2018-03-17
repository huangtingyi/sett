#include <stdio.h>
#include <dbsupp.h>
#include <string.h>
#include <wwdb.h>
#include <isselect.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <bintree.h>
#include <stt_ticket.h>
#include <ticket.h>
#include <sett_nbr_supp.h>
int main(int argc,char *argv[])
{		
	int iCount=0;
	char *msisdn="777777235";
	char *table="ALL_APP_INFO_NBR";
	InitAppRes(argv[0]);
	if(IniConnect("dataconnstr")<0){
    	printf("error\n");
        return -1;
    }
    printf("success\n");
		iCount=IsInNBR(msisdn,table);
		printf("%d\n",iCount);return 0;

}
