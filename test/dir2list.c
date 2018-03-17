#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wwdir.h"

int main()
{
	char sFileName[256];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	
	dir2list(".","*.c",&ptHead);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sFileName,(char*)pTemp->pData,pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		
		printf("%s\n",sFileName);
	}
	
	return 0;
}
