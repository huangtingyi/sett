#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <expr_fun.h>


int main(int argc, char **argv)
{
	int iRet;
	char	sRecord[512];
	char	sFileName[128],sBaseName[128],*pc;
	char	sGnName[128],sGjName[128],sGnDir[128],sGjDir[128];
	struct	FileControlStruct *ptHead=NULL,*pTemp;
	struct	FileControlStruct *pGn=NULL,*pGj=NULL;
	
	if(argc!=4){
		printf("Usage %s input gndir gjdir.\n",argv[0]);
		return -1;
	}
	strcpy(sFileName,argv[1]);
	strcpy(sGnDir,	argv[2]);RegularDir(sGnDir);
	strcpy(sGjDir,	argv[3]);RegularDir(sGjDir);
	
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件 %s 链表失败.\n",sFileName);
		return -1;
	}
	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		memcpy(sRecord,(char*)(pTemp->pData),pTemp->iLen);
		sRecord[pTemp->iLen]='\n';
		
		pc=sRecord;pc+=113;
		if(strncmp(pc,"4600",4)==0||strncmp(pc,"4601",4)==0||pc[0]==' ')
			iRet=item2list(&pGn,sRecord,pTemp->iLen+1);
		else
			iRet=item2list(&pGj,sRecord,pTemp->iLen+1);
		if(iRet<0){
			printf("生成文件 %s 链表失败.\n",sFileName);
			return -1;
		}
	}
	sprintf(sGnName,"%s%s.D",sGnDir,sBaseName);
	sprintf(sGjName,"%s%s.I",sGjDir,sBaseName);
	
	if(list2file(&pGn,sGnName)<0){
		printf("输出文件%s错误.\n",sGnName);
		return -1;
	}
	if(list2file(&pGj,sGjName)<0){
		printf("输出文件%s错误.\n",sGjName);
		return -1;
	}
	printf("拆分文件%s成功.\n",sFileName);
	
	return 0;
}
