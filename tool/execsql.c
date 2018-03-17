#include <hnixs.h>
#include <list.h>
#include <wwlog.h>
#include <wwcoding.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwdb.h>

int GenSqlList(struct FileControlStruct *ptHead,
	struct FileControlStruct **pptSqlList)
{
	int	iRet;	
	char	sLine[512],sCommand[1024*8];
	struct FileControlStruct *pSqlList=NULL,*pTemp;

	sCommand[0]=0;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		memcpy(sLine,(char*)(pTemp->pData),pTemp->iLen);
		sLine[pTemp->iLen]=0;
		if(sLine[pTemp->iLen-1]!=';'){
			sprintf(sCommand,"%s\n\
				%s",sCommand,sLine);
		}
		else{
			sprintf(sCommand,"%s\n\
				%s",sCommand,sLine);
			sCommand[strlen(sCommand)-1]=0;
			Upper(sCommand);
			iRet=item2list(&pSqlList,(void *)sCommand,
				strlen(sCommand));
			if(iRet<0){
				printf("生成SQL脚本 %s 链表失败",sCommand);
				return -1;
			}
			sCommand[0]=0;
		}
	}
	
	ReverseList((LIST**)&pSqlList);
	*pptSqlList=pSqlList;
	
	return 0;
}

int ExecSqlList(struct	FileControlStruct *pSqlList)
{
	int	iRet;
	char	sCommand[1024*8];
	struct	FileControlStruct *pTemp;
	
	while(pSqlList!=NULL){
		pTemp=pSqlList;
		pSqlList=pSqlList->pNext;
		memcpy(sCommand,(char*)(pTemp->pData),pTemp->iLen);
		sCommand[pTemp->iLen]=0;

		iRet=ExecSql(sCommand);
		if(iRet<0){
			/*WriteProcPrint("SQL:%s执行错误\n",sCommand);*/
			WriteProcPrint("SQL 执行错误\n");
			return -1;
		}
		/*WriteProcPrint("SQL:%s\n已正确执行\n",sCommand);		*/
		WriteProcPrint("SQL: 已正确执行\n");
	}
	return 0;
}

int main(int argc, char **argv)
{
	char	sFileName[128];
	struct	FileControlStruct *ptHead=NULL,*pSqlList=NULL;

	if(argc!=3){
		printf("Usage %s userid sqlfile.\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	strcpy(sFileName,argv[2]);

	FastConnect(argv[1]);

	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件 %s 链表失败.\n",sFileName);
		return -1;
	}
		
	if(GenSqlList(ptHead,&pSqlList)<0) return -1;
		
	if(ExecSqlList(pSqlList)<0) return -1;
	
	DisconnectDatabase();
	return 0;
}

