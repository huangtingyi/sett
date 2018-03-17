#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwtiny.h>
#include <bintree.h>
#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <ticket_field.h>
#include <tariff_disct.h>

int CompileExprFile(char sExprName[])
{
	int l;
	static char sPreExpr[256];
	char sInput[EXPRLEN],sMessage[1024];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];

/*公式文件名相同则不编译*/
	if(strcmp(sExprName,sPreExpr)==0) return 0;

	if(pExprBuf!=NULL){
		DestroyExprBuf(pExprBuf);
		pExprBuf=NULL;
	}
	strcpy(sPreExpr,sExprName);
	
/*将公式文件读到内存*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,sMessage)!=0){
		WriteAlertPrint("读文件%s失败:%s",sExprName,sMessage);
		return -1;
	}
/*加载编译公式函数及参数*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*编译公式*/
	if(CompileExpr(sInput,asVarOutput,&l)<0){
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	return 0;
}

int ProcessVerifyFile(char sFileName[],char sNormalDir[],
	char sAbnormalDir[],char sResult[])
{
	int l,iRet,iTicketValid=0,iErrCode=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0;
	char sRecord[1024],sHostTime[15];
	char sNormalName[128],sAbnormalName[128],sBaseName[128];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pAbnormal=NULL,*pNormal=NULL;

/*将文件数据调用函数加载到内存*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		sprintf(sResult,"加载文件%s到内存失败.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}
	GetBaseName(sFileName,sBaseName);
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		iCnt++;
		
		/**复位话单结构的当前输出链表{unlink pCur链表}*/
		ResetTicket();
		/**加载原始话单到指定的原始话单结构字段，设置原始话单长度*/
		TICKET.iOriLen=	pTemp->iLen;
		TICKET.sOri[pTemp->iLen]=0;
		memcpy((void*)(TICKET.sOri),pTemp->pData,pTemp->iLen);
			
		set_str_value("$FILENAME",pExprBuf,sBaseName);
		GetHostTime(sHostTime);	
		set_str_value("$NOW",pExprBuf,sHostTime);
		
		/*执行公式{这里可以获得pCur链表，link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			printf("执行公式错误,%d.\n",iRet);
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_int_value("errcode",pExprBuf,&iErrCode);
			
	/*话单处理*/

		if(iErrCode<0){
			iAbnormalCnt++;
			l=sprintf(sRecord,"%s%04d\n",TICKET.sOri,-iErrCode);
			if(item2list(&pAbnormal,sRecord,l)<0){
				printf("生成错误话单链表错误.\n");
				return -1;
			}
		}
		else{
		
			if(iTicketValid<0){
				iNormalCnt++;
				l=sprintf(sRecord,"%s\n",TICKET.sOri);
				if(item2list(&pNormal,sRecord,l)<0){
					printf("生成正常话单链表错误.\n");
					return -1;
				}	
			}
			else{
				iNormalCnt++;
				GenStdTicket();
				if(item2list(&pNormal,TICKET.sStd,TICKET.iStdLen)<0){
					printf("生成正常话单链表错误.\n");
					return -1;
				}	
			}
		}
			

		/*释放内存*/
		free(pTemp);
	}
	
	
	DestroyBin(pExprBuf->pRoot);
	strcpy(sNormalName,"NULL");
	strcpy(sAbnormalName,"NULL");
/**写资料异常话单********/
	if(pAbnormal!=NULL){
	/*将输出的话单正序一下*/
		ReverseList((LIST**)&pAbnormal);
		sprintf(sAbnormalName,"%s.abn",sBaseName);
		strcat(sAbnormalDir,sAbnormalName);
		if(list2file(&pAbnormal,sAbnormalDir)<0){
			sprintf(sResult,"写异常话单文件%s失败.\n",sAbnormalDir);
			return -1;
		}
	}

/**写资料正常话单********/
	if(pNormal!=NULL){
	/*将输出的话单正序一下*/
		ReverseList((LIST**)&pNormal);
		sprintf(sNormalName,"%s.nor",sBaseName);
		strcat(sNormalDir,sNormalName);
		if(list2file(&pNormal,sNormalDir)<0){
			sprintf(sResult,"写正常话单文件%s失败.\n",sNormalDir);
			return -1;
		}
	}
	printf("%s\t%s\t%d\t%d\n",sNormalName,sAbnormalName,iNormalCnt,iAbnormalCnt);
	return 0;
}

int main(int argc,char *argv[])
{
	int i;
	char sExprName[128],sFileName[128];
	char sNormalDir[128],sAbnormalDir[128];
	char sResult[1024];
	
	if(argc!=5){
		printf("Usage %s input expr normaldir abnormaldir.\n",argv[0]);
		return -1;
	}
/*初始化参数部分*/
	InitAppRes(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sExprName,argv[2]);
	strcpy(sNormalDir,argv[3]);
	strcpy(sAbnormalDir,argv[4]);

/**检查参数合法性*******/
	if(IsFile(sFileName)==FALSE){
		printf("输入文件%s无效.\n",sFileName);
		return -1;
	}
	if(IsDir(sNormalDir)==FALSE){
		printf("输出正常目录%s无效.\n",sNormalDir);
		return -1;
	}
	if(IsDir(sAbnormalDir)==FALSE){
		printf("输出异常目录%s无效.\n",sAbnormalDir);
		return -1;
	}
	RegularDir(sNormalDir);
	RegularDir(sAbnormalDir);
	
/*编译公式*/
	if(CompileExprFile(sExprName)<0) return -1;
		
/*调用主函数处理文件*/
	i=ProcessVerifyFile(sFileName,sNormalDir,sAbnormalDir,sResult);
/*打印输出结果*/
	printf(sResult);

	return i;
}
