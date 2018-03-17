#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
	InitAppRes(argv[0]);
	
	if(CreateUserDataShmBinTree()<0){
		printf("刷新用户资料失败.\n");
		return -1;
	}
	
	printf("刷新用户资料成功.\n");
	
	return 0;
}
