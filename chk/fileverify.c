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

/*��ʽ�ļ�����ͬ�򲻱���*/
	if(strcmp(sExprName,sPreExpr)==0) return 0;

	if(pExprBuf!=NULL){
		DestroyExprBuf(pExprBuf);
		pExprBuf=NULL;
	}
	strcpy(sPreExpr,sExprName);
	
/*����ʽ�ļ������ڴ�*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,sMessage)!=0){
		WriteAlertPrint("���ļ�%sʧ��:%s",sExprName,sMessage);
		return -1;
	}
/*���ر��빫ʽ����������*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*���빫ʽ*/
	if(CompileExpr(sInput,asVarOutput,&l)<0){
		printf("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("���빫ʽ%s����::\n%s\n",
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
		
	/*ִ�й�ʽ{������Ի��pCur����link}*/
	if((iRet=ExecCode(pExprBuf))<0){
		printf("ִ�й�ʽ����,%d.\n",iRet);
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
/*��ʼ����������*/
	InitAppRes(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sExprName,argv[2]);

/**�������Ϸ���*******/
	if(IsFile(sFileName)==FALSE){
		printf("�����ļ�%s��Ч.\n",sFileName);
		return -1;
	}
/*���빫ʽ*/
	if(CompileExprFile(sExprName)<0) return -1;
		
/*���������������ļ�*/
	i=ProcessFVerifyFile(sFileName,sResult);
/*��ӡ������*/
	printf(sResult);

	return i;
}
