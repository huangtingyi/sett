#include <stdio.h>
#include <stdlib.h>

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

#include <expr_fmp.h>


void FDisplaySymbolFlow(FILE *fp)
{
	int iType,i;
	char asType[23][12]={"LOG1","LOG2","MATH","CONTROL","CONST",
		"SYSVAR","TEMPVAR","SEPARATOR","ASSIGN","MATH1","CONSTSTR",
		"CONSTHEX","CONSTDEC","CONSTBIN","SFUN","DFUN","DOUBLE",
		"LCONSTSTR","MODALITY","PRECOMP","DECLARE","MICRO","FUN"};
       for(i=0;i<igSymCnt;i++){
       		iType=SymbolFlow[i].iType-1;
       		if(strcmp(SymbolFlow[i].sValue,"\n")==0)
       			fprintf(fp,"%03d: %10s  \\n\n",i,asType[iType]);
       		else fprintf(fp,"%03d: %10s  %s\n",
       			i,asType[iType],SymbolFlow[i].sValue);
       }
}
void FDisplaySysVar(FILE *fp)
{
	int i;
	for(i=0;i<CURR_EXPR.iSysVarCnt;i++){
		if(CODE_VARBUF[i].cType==VARTYPE_INT){
			fprintf(fp,"%d\t%c\t%s=%d.\n",i,
				CODE_VARBUF[i].cType,CODE_SYSBUF[i].sSymbol,
				CODE_VARBUF[i].u.iValue);
		}
		else if(CODE_VARBUF[i].cType==VARTYPE_STR){
			fprintf(fp,"%d\t%c\t%s=%s.\n",i,
				CODE_VARBUF[i].cType,CODE_SYSBUF[i].sSymbol,
				GetVarcharData(CODE_VARBUF[i].u.sValue));
		}
		else{
			fprintf(fp,"%d\t%c\t%s\n",i,
				CODE_VARBUF[i].cType,CODE_SYSBUF[i].sSymbol);
		}
	}
}
void FDisplayCode(FILE *fp)
{
	int i;
	char op,sName[64];
	int	d1,d2,r;
	
	for(i=0;i<CURR_EXPR.iCodeCnt;i++){
		
		op=CODE_FLOW[i].op;
		d1=CODE_FLOW[i].data1;
		d2=CODE_FLOW[i].data2;
		r= CODE_FLOW[i].result;
			
		switch (op){
		case JMP:
	    	 	fprintf(fp,"%03d: %c  %5d  %5d  %5d   --- jmp==>    %5d\n",
	    	 		i,op,d1,d2,r,r);
		break;
		case JMPF:
			fprintf(fp,"%03d: %c  %5d  %5d  %5d   --- jmpf==>    %5d\n",
	    	 		i,op,d1,d2,r,r);
		break;
		case RET:
			fprintf(fp,"%03d: %c  %5d  %5d  %5d   --- return==>   %5d\n",
	    	 		i,op,d1,d2,r,r);
	    	break;
		case SFUN:
		case DFUN:
			strcpy(sName,"");
			SearchRegFunLinkByAddr(CODE_FLOW[i].Oper,sName);
			fprintf(fp,"%03d: %c  %5d  %5d  %5d   --- %8s=%c -call %s\n",
	    	 		i,op,d1,d2,r,
	    			GetSysSymbol(r),op,sName);
	    	break;
		default:
			fprintf(fp,"%03d: %c  %5d  %5d  %5d   --- %8s   %c %5s     ==> %8s\n",
	    	 		i,op,d1,d2,r,
	    			GetSysSymbol(d1),op,
	    			GetSysSymbol(d2),
	    			GetSysSymbol(r));
		break;
		}
	}
	
}

int main(int argc, char *argv[])
{
	int l;
	FILE *fp;
	char sExprName[128],sTargetName[128],sInput[EXPRLEN],sMsg[2048];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];


	if(argc!=3){
		printf("Usage %s exprfile objfile.\n",argv[0]);
		return -1;
	}

	InitAppRes(argv[0]);
	strcpy(sExprName,argv[1]);
	strcpy(sTargetName,argv[2]);
	
/**检查参数合法性*******/
	if(IsFile(sExprName)==FALSE){
		printf("输入文件%s无效.\n",sExprName);
		return -1;
	}

/*将公式文件读到内存*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,sMsg)!=0){
		WriteAlertPrint("读文件%s失败:%s",sExprName,sMsg);
		return -1;
	}
/*加载编译公式函数及参数*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
	InitReserveSymbol();
/*编译公式*/
	if(PropLexicalize(sInput,sMsg)<0)
		printf("编译公式错误::\n%s\n",sMsg);
	else
		printf("编译公式%s成功.\n",sExprName);
	
	if((fp=fopen(sTargetName,"w"))==NULL){
		printf("打开文件%s写失败.\n",sTargetName);
		return -1;
	}
	
	fprintf(fp,"\n=====================以下是符号表==========================\n");
	FDisplaySymbolFlow(fp);
	
	fclose(fp);
	
	return 0;
}
