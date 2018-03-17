#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <param_intf.h>

int ProcessMain( struct DispParamStruct *pParam,char sType[])
{
	int l=0;
	int iCnt=0;
	char sFileName[256],sTempName[256];
	char sCommand[10240],sRCommand[10240];
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;

/*生成一个文件列表*/
	if(dir2list(pParam->sSourcePath,pParam->sFilter,&ptHead)<0){
		printALERT("生成文件列表失败 %s %s",
			pParam->sSourcePath,pParam->sFilter);
		return -1;
	}

	ptLkHead=ptHead;

	/*移动文件*/
	while( ptHead != NULL ){

		pTemp = ptHead;
		ptHead = ptHead->pNext;

		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		
		
		/*sprintf(sTempName,"%s.tmp",sFileName);
		if((iCnt=InsertTicket(sTempName,sTableName,sType))<0){
			printALERT("对表%s 入库文件%s失败",sTableName,sFileName);
			return -1;
		}*/
		iCnt++;
		printNORMAL("对文件%s分发成功",sTempName);
	}
	listfree(&ptLkHead);
	return 0;
}
int MyChkDir(char sPath[])
{
	if(strcmp(sPath,"/nil/")==0) return -1;
	return CheckDir(sPath);
}
int main( int argc, char **argv )
{
	int iRet,iGroupID;
	char sFileName[256],sType[3];
	struct DispParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;

	if(argc!=4){
		printf("Usage %s disp.ini GroupID Type.\n",argv[0]);
		return -1;
	}

	InitAppRes("lindb.sh");

	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	strcpy(sType,argv[3]);
	
/*将需要处理的参数获取到 链表中*/
	if(GetDispParamList(sFileName,iGroupID,&ptHead)<0) return -1;

	ptLkHead= ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*检查参数合法性。*/

		if(IsDir(pTemp->sSourcePath)==FALSE){
			printALERT("输入目录%s无效.",pTemp->sSourcePath);
			continue;
		}

		/*目标目录不存在则建立,考虑/nil目录*/
		if(MyChkDir(pTemp->sDestPath1)<0)strcpy(pTemp->sDestPath1,"");
		if(MyChkDir(pTemp->sDestPath2)<0)strcpy(pTemp->sDestPath2,"");
		if(MyChkDir(pTemp->sDestPath3)<0)strcpy(pTemp->sDestPath3,"");
		if(MyChkDir(pTemp->sDestPath4)<0)strcpy(pTemp->sDestPath4,"");

		iRet=ProcessMain(pTemp,sType);

		if(iRet<0){
			printALERT("分发文件失败!");
			return -1;
		}
		if(iRet>0) break;
	}

	DestroyList((LIST*)ptLkHead);

	return 0;
}

