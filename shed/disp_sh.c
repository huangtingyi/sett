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

#include <appsupp.h>

int ProcessMain( struct DispParamStruct *pParam)
{
	int l=0;
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

		/*如果文件刚被修改则不处理*/
		sprintf(sTempName,"%s%s",pParam->sSourcePath,sFileName);

		if(FileModifyDiff(sTempName)<1) continue;

		/*为了安全起见，清空命令行*/
		sCommand[0]=sRCommand[0]=0;
		
		/*拷贝命令,及成功后删除源文件*/
		l=0;
		if(strlen(pParam->sDestPath1)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath1);
		}
		if(strlen(pParam->sDestPath2)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath2);

		}
		if(strlen(pParam->sDestPath3)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath3);

		}
		if(strlen(pParam->sDestPath4)!=0){
			l+=sprintf(sCommand+l,"cp %s %s &&",
				sTempName,pParam->sDestPath4);
		}
	/*去掉最后的&&*/
		if(RLike(sCommand,"&&"))
			sCommand[strlen(sCommand)-2]=0;
		
		/*失败恢复命令*/
		l=0;
		if(strlen(pParam->sDestPath1)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath1,sFileName);
		if(strlen(pParam->sDestPath2)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath2,sFileName);
		if(strlen(pParam->sDestPath3)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath3,sFileName);
		if(strlen(pParam->sDestPath4)!=0)
			l+=sprintf(sRCommand+l,"rm -f %s%s &&",
				pParam->sDestPath4,sFileName);

	/*去掉最后的&&*/
		if(RLike(sRCommand,"&&"))
			sRCommand[strlen(sRCommand)-2]=0;

		/*全部成功后删除文件,如果某个失败，删除已经分发的文件。*/
		if(system(sCommand)!=0){

			printALERT("执行%s失败",sCommand);
			system(sRCommand);
			listfree(&ptLkHead);
			return -1;
		}
		sprintf(sCommand,"rm -f %s",sTempName);
		system(sCommand);

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
	char sFileName[256];
	struct DispParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;

	if(argc!=3){
		printf("Usage %s disp.ini GroupID.\n",argv[0]);
		return -1;
	}

	InitAppRes("disp.sh");

	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);

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

		iRet=ProcessMain(pTemp);

		if(iRet<0){
			printALERT("分发文件失败!");
			return -1;
		}
		if(iRet>0) break;
	}

	DestroyList((LIST*)ptLkHead);

	return 0;
}

