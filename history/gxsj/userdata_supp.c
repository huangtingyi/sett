#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
	InitAppRes(argv[0]);
	
	if(CreateUserDataShmBinTree()<0){
		printf("ˢ���û�����ʧ��.\n");
		return -1;
	}
	
	printf("ˢ���û����ϳɹ�.\n");
	
	return 0;
}
