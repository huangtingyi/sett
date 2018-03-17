
#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <wwshm.h>

#include "gen_supp.h"
#include "param_intf.h"

int main(int argc,char *argv[])
{
	
	InitAppRes(argv[0]);
	
	MoveAllShmToMem();
	
	printf("访问所有共享内存表成功.\n");

	return 0;
}
