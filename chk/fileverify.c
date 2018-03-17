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

int ProcessFVerifyFile(char sFileName[],char sResult[])
{
	int iRet,iErrCode=0;
	char sHostTime[15],sBaseName[256];

	GetBaseName(sFileName,sBaseName);
	
	set_str_value("$FILENAME",pExprBuf,sBaseName);
	GetHostTime(sHostTime);	
	set_str_value("$NOW",pExprBuf,sHostTime);
		
	/*执行公式{这里可以获得pCur链表，link}*/
	if((iRet=ExecCode(pExprBuf))<0){
		printf("执行公式错误,%d.\n",iRet);
		return -1;
	}
	get_int_value("errcode",pExprBuf,&iErrCode);
			
	printf("%d\n",iErrCode);
	return 0;
}

int main(int argc,char *argv[])
{
	int i;
	char sExprName[128],sFileName[128];
	char sResult[1024];
	
	if(argc!=3){
		printf("Usage %s input expr.\n",argv[0]);
		return -1;
	}
/*初始化参数部分*/
	InitAppRes(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sExprName,argv[2]);

/**检查参数合法性*******/
	if(IsFile(sFileName)==FALSE){
		printf("输入文件%s无效.\n",sFileName);
		return -1;
	}
/*编译公式*/
	if(CompileExprFile(sExprName)<0) return -1;
		
/*调用主函数处理文件*/
	i=ProcessFVerifyFile(sFileName,sResult);
/*打印输出结果*/
	printf(sResult);

	return i;
}
