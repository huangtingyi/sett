#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <hnixs.h>
#include <wwcoding.h>
#include <wwtiny.h>
#include <wwfile.h>

int main(int argc,char *argv[])
{
	int lPre=0,lCur=0,iRecCnt=0,iCnt=0;
	char sSourceName[256],sTargetName[256],sInput[4096],sOutput[1024];
	struct FileControlStruct *ptHead=NULL,*ptLkHead=NULL,*pTemp,*pList=NULL;
	
        if(argc!=3){
                printf("Usage: %s sourcename targetname.\n",argv[0]);
                return -1;
        }

	strcpy(sSourceName,argv[1]);
	strcpy(sTargetName,argv[2]);
	
	if(TxtFileToList(sSourceName,&ptLkHead)<0){
		printf("文件%s加载到内存错误.\n",sSourceName);
		return -1;
	}

	ptHead=ptLkHead;
	while(ptHead!=NULL){

		iRecCnt++;
		iCnt++;

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(pTemp->iLen>sizeof(sInput)){
			printf("第%d条记录超长，大于%d字节,为%d.\n",
				iRecCnt,sizeof(sInput),pTemp->iLen);
			return -1;
		}
		
		strncpy(sInput,(char*)pTemp->pData,pTemp->iLen);
		sInput[pTemp->iLen]=0;
		AllTrim(sInput);
		
		free(pTemp);

		if(!IsAllHex(sInput)){
			printf("第%d条记录不合法，文本信息应为16进制数，实际为\n%s\n",
				iRecCnt,sInput);
			return -1;
		}

		lCur=asc_hex2hbcd(sInput,(unsigned char*)sOutput);
		if(lPre==0)lPre=lCur;
		
		if(lCur!=lPre){
			printf("第%d条记录长度不合法，应该为%d长,实际为%d长，实际为\n%s\n",
				iRecCnt,lPre,lCur,sInput);
			return -1;
		}
		
		if(item2list(&pList,(void*)sOutput,lCur)<0){
			printf("加入FileControl列表错误.\n");
			return -1;
		}
	}
	
	ReverseList((LIST**)&pList);
	
	if(list2file(&pList,sTargetName)<0){
		printf("写文件%s失败.\n",sTargetName);
		return -1;
	}
	printf("成功将%s文件转换为%s文件",sSourceName,sTargetName);

	return 0;
}

