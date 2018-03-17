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
/*
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
*/
#ifdef ZZZZZZZZZZ
void FDisplayCode(FILE *fp)
{
	int i;
	char op,sName[64],sItem[256];
	int	d1,d2,r;
	
	for(i=0;i<CURR_EXPR.iCodeCnt;i++){
		
		op=CODE_FLOW[i].op;
		d1=CODE_FLOW[i].data1;
		d2=CODE_FLOW[i].data2;
		r= CODE_FLOW[i].result;
		
		sprintf(sItem,"%03d: %c %5d %5d %5d --",i,op,d1,d2,r);

		switch (op){
		case JMP:
			fprintf(fp,"%s jmp   ==>    %5d\n",sItem,r);
		break;
		case JMPF:
			fprintf(fp,"%s jmpf  ==>    %5d\n",sItem,r);
		break;
		case RET:
			fprintf(fp,"%s return==>    %5d\n",sItem,r);
	    	break;
	    	case ASSIGN:
	    		if(r==800){
	    			printf("hello.\n");
	    		}
			fprintf(fp,"%s %s = %s\n",
	    			sItem,GetSysSymbol(r),GetSysSymbol(d1));
		break;
		case SFUN:
		case DFUN:
			strcpy(sName,"");
			SearchRegFunLinkByAddr(CODE_FLOW[i].Oper,sName);
			fprintf(fp,"%s %s = %ccall %s(%d,%d)\n",
	    			sItem,GetSysSymbol(r),op,sName,d1,d2);
	    	break;
	    	case FUN:
	    		strcpy(sName,"");
	    		SearchDefFunByAddr(CODE_FLOW[i].result,sName);
			fprintf(fp,"%s %s = %ccall %s(%d,%d)\n",
	    			sItem,GetSysSymbol(r),op,sName,d1,d2);
	    	break;
	    	case OPSP:
	    		if(d1==P_OP_PUSH||d1==P_OP_POP){
	    			
	    			char pin[5];
	    			
	    			if(d1==P_OP_PUSH)strcpy(pin,"PUSH");
	    			else		strcpy(pin,"POP");

	    			if(d2==ADDR_REGISTER){
	    				switch (r){
	    				case REGISTER_IP:
	    				fprintf(fp,"%s %s IP",sItem,pin);
					break;
	    				case REGISTER_BP:
	    				fprintf(fp,"%s %s BP",sItem,pin);
	    				break;
	    				case REGISTER_SP:
	    				fprintf(fp,"%s %s SP",sItem,pin);
	    				break;
	    				default:
	    				fprintf(fp,"%s %s BP",sItem,pin);
	    				break;
	    				}
	    			}
	    			else{
	    				fprintf(fp,"%s %s %s",
						sItem,pin,GetSysSymbol(r));
	    			}
			}
			else if(CODE_FLOW[i].data1==P_OP_CALL){
				if(CODE_FLOW[i].Oper==mv_sp2bp)
					fprintf(fp,"%s BP=SP",sItem);
				else if(CODE_FLOW[i].Oper==mv_bp2sp)
					fprintf(fp,"%s SP=BP",sItem);
				else if(CODE_FLOW[i].Oper==clear_variant)
					fprintf(fp,"%s CLS %s",
						sItem,GetSysSymbol(r));
			}
			else
				fprintf(fp,"%s %s = %s %c %s\n",
	    	 			sItem,GetSysSymbol(r),
	    	 			GetSysSymbol(d1),op,GetSysSymbol(d2));
	    	 	
		break;
		default:
		{
			char sOp[5];
			sOp[0]=op;sOp[1]=0;
			switch(op){
			case '1':/*GT  */strcpy(sOp,">");break;
			case '2':/*LT  */strcpy(sOp,"<");break;
			case '3':/*GE  */strcpy(sOp,">=");break;
			case '4':/*LE  */strcpy(sOp,"<=");break;
			case '5':/*EQ  */strcpy(sOp,"==");break;
			case '6':/*NE  */strcpy(sOp,"!=");break;
			case '7':/*MOR */strcpy(sOp,"|");break;
			case '8':/*MAND*/strcpy(sOp,"&");break;
			case '|':/*OR  */strcpy(sOp,"||");break;
			case '&':/*AND */strcpy(sOp,"&&");break;
			default:break;
			}		
			fprintf(fp,"%s %s = %s %s %s\n",
    	 			sItem,GetSysSymbol(r),
    	 			GetSysSymbol(d1),sOp,GetSysSymbol(d2));
    	 	}
		break;
		}
	}	
}
#endif
/*
void GetConstValuePin(int iIndex,char pin[])
{
	strcpy(pin,"");

	if(CODE_VARBUF[iIndex].cType==VARTYPE_STR){
		int i,j=0;
		char *p;

		if((p=GetVarcharData(CODE_VARBUF[iIndex].u.sValue))!=NULL){
		
			pin[j++]='=';pin[j++]='\"';
			for(i=0;i<strlen(p);i++){
				pin[j++]=p[i];
				if(i>20){
					pin[j++]='.';pin[j++]='.';
					pin[j++]='.';break;
				}
			}
			pin[j++]='\"';pin[j]=0;
		
		}
		else sprintf(pin,"=\"%s\"","");
	}
	else if(CODE_VARBUF[iIndex].cType==VARTYPE_INT)
		sprintf(pin,"=%d",CODE_VARBUF[iIndex].u.iValue);
	else if(CODE_VARBUF[iIndex].cType==VARTYPE_DOUBLE)
		sprintf(pin,"=%f",CODE_VARBUF[iIndex].u.dValue);
	else if(CODE_VARBUF[iIndex].cType==VARTYPE_POINTER)
		sprintf(pin,"=pt%x",CODE_VARBUF[iIndex].u.pValue);
	else
		sprintf(pin,"=st%x",CODE_VARBUF[iIndex].u.pValue);
}
void GetConstValuePin(int iIndex,char pin[])
{
	strcpy(pin,"");

	if(CODE_VARBUF[iIndex].cType==VARTYPE_STR){
		int i,j=0;
		char *p;

		if((p=GetVarcharData(CODE_VARBUF[iIndex].u.sValue))!=NULL){
		
			pin[j++]='\"';
			for(i=0;i<strlen(p);i++){
				pin[j++]=p[i];
				if(i>20){
					pin[j++]='.';pin[j++]='.';
					pin[j++]='.';break;
				}
			}
			pin[j++]='\"';pin[j]=0;
		
		}
		else sprintf(pin,"\"%s\"","");
	}
	else if(CODE_VARBUF[iIndex].cType==VARTYPE_INT)
		sprintf(pin,"%d",CODE_VARBUF[iIndex].u.iValue);
	else if(CODE_VARBUF[iIndex].cType==VARTYPE_DOUBLE)
		sprintf(pin,"%f",CODE_VARBUF[iIndex].u.dValue);
	else if(CODE_VARBUF[iIndex].cType==VARTYPE_POINTER)
		sprintf(pin,"pt%x",CODE_VARBUF[iIndex].u.pValue);
	else
		sprintf(pin,"st%x",CODE_VARBUF[iIndex].u.pValue);
}

void GetSysSymbol1(int i,char sTemp[],int iFlag)
{
	
	if(i<0)	strcpy(sTemp,"");
	else if(i<SYSVAR_COUNT)	strcpy(sTemp,CODE_SYSBUF[i].sSymbol);
	else if(i>=MAXVAR_COUNT)sprintf(sTemp,"p%d",i-MAXVAR_COUNT);
	else if(CODE_VARBUF[i].iIndex!=-1)
		strcpy(sTemp,CODE_SYSBUF[CODE_VARBUF[i].iIndex].sSymbol);
	else{
		if(iFlag==true){
			char pin[256];
			GetConstValuePin(i,pin);
			sprintf(sTemp,"[%d](%s)",i,pin);
		}
		else
			sprintf(sTemp,"[%d]",i);		
	}
}
*/
void FDisplayCode(FILE *fp)
{
	int i;
	char op,sName[64],sItem[256],pin[256];
	char	MY_D1[256],MY_D2[256],MY_R[256];
	int	d1,d2,r;
	
	for(i=0;i<CURR_EXPR.iCodeCnt;i++){
		
		op=CODE_FLOW[i].op;
		d1=CODE_FLOW[i].data1;
		d2=CODE_FLOW[i].data2;
		r= CODE_FLOW[i].result;

		GetSysSymbol(d1,MY_D1,true);
		GetSysSymbol(d2,MY_D2,true);
		GetSysSymbol(r, MY_R,false);

		sprintf(sItem,"%03d: %c %5d %5d %5d --",i,op,d1,d2,r);

		switch (op){
		case JMP:
			fprintf(fp,"%s jmp   ==>    %5d\n",sItem,r);
		break;
		case JMPF:
			fprintf(fp,"%s jmpf  ==>    %5d\n",sItem,r);
		break;
		case RET:
			fprintf(fp,"%s return==>    %5d\n",sItem,r);
	    	break;
	    	case ASSIGN:
			fprintf(fp,"%s %s = %s\n",sItem,MY_R,MY_D1);
		break;
		case SFUN:
		case DFUN:
			GetConstValuePin(d2,pin);
			strcpy(sName,"");
			SearchRegFunLinkByAddr(CODE_FLOW[i].Oper,sName);
			if(MY_D1[0]=='[') sprintf(MY_D1,"[%d]",d1);
			fprintf(fp,"%s %s = %ccall %s(%s,%s)\n",
	    			sItem,MY_R,op,sName,MY_D1,pin);
	    	break;
	    	case FUN:
			GetConstValuePin(d2,pin);
	    		strcpy(sName,"");
	    		SearchDefFunByAddr(CODE_VARBUF[r].iParam,sName);
	    		if(MY_D1[0]=='[') sprintf(MY_D1,"[%d]",d1);
			fprintf(fp,"%s %s = %ccall %s(%s,%s)\n",
	    			sItem,MY_R,op,sName,MY_D1,pin);
	    	break;
	    	case OPSP:
	    		if(d1==P_OP_PUSH||d1==P_OP_POP){
	    			
	    			if(d1==P_OP_PUSH)strcpy(pin,"PUSH");
	    			else		strcpy(pin,"POP");

	    			if(d2==ADDR_REGISTER){
	    				switch (r){
	    				case REGISTER_IP:
	    				fprintf(fp,"%s %s IP\n",sItem,pin);
					break;
	    				case REGISTER_BP:
	    				fprintf(fp,"%s %s BP\n",sItem,pin);
	    				break;
	    				case REGISTER_SP:
	    				fprintf(fp,"%s %s SP\n",sItem,pin);
	    				break;
	    				default:
	    				fprintf(fp,"%s %s BP\n",sItem,pin);
	    				break;
	    				}
	    			}
	    			else{
	    				if(r>0)fprintf(fp,"%s %s %s\n",sItem,pin,MY_R);
	    				else fprintf(fp,"%s %s p1-p%d->null\n",sItem,pin,-r);
	    			}
			}
			else if(CODE_FLOW[i].data1==P_OP_CALL){
				if(CODE_FLOW[i].Oper==mv_sp2bp)
					fprintf(fp,"%s BP=SP\n",sItem);
				else if(CODE_FLOW[i].Oper==mv_bp2sp)
					fprintf(fp,"%s SP=BP\n",sItem);
				else if(CODE_FLOW[i].Oper==clear_variant)
					fprintf(fp,"%s CLS %s\n",sItem,MY_R);
			}
			else
				fprintf(fp,"%s %s = %s %c %s\n",
	    	 			sItem,MY_R,MY_D1,op,MY_D2);
	    	 	
		break;
		default:
		{
			char sOp[5];
			sOp[0]=op;sOp[1]=0;
			switch(op){
			case '1':/*GT  */strcpy(sOp,">");break;
			case '2':/*LT  */strcpy(sOp,"<");break;
			case '3':/*GE  */strcpy(sOp,">=");break;
			case '4':/*LE  */strcpy(sOp,"<=");break;
			case '5':/*EQ  */strcpy(sOp,"==");break;
			case '6':/*NE  */strcpy(sOp,"!=");break;
			case '7':/*MOR */strcpy(sOp,"|");break;
			case '8':/*MAND*/strcpy(sOp,"&");break;
			case '|':/*OR  */strcpy(sOp,"||");break;
			case '&':/*AND */strcpy(sOp,"&&");break;
			default:break;
			}		
			fprintf(fp,"%s %s = %s %s %s\n",
    	 			sItem,MY_R,MY_D1,sOp,MY_D2);
    	 	}
		break;
		}
	}
}
int main(int argc, char *argv[])
{
	int l,i;
	FILE *fp;
	char sExprName[128],sTargetName[128],sInput[EXPRLEN],sMessage[2048];
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
		sInput,sMessage)!=0){
		WriteAlertPrint("读文件%s失败:%s",sExprName,sMessage);
		return -1;
	}
/*加载编译公式函数及参数*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0)
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
	else
		printf("编译公式%s成功.\n",sExprName);
	
	if(i>=0){
		ExecCode(pExprBuf);
	}
	if((fp=fopen(sTargetName,"w"))==NULL){
		printf("打开文件%s写失败.\n",sTargetName);
		return -1;
	}
	
	fprintf(fp,"\n=====================以下是符号表==========================\n");
	FDisplaySymbolFlow(fp);
	fprintf(fp,"\n=====================以下是系统变量=========================\n");
	FDisplaySysVar(fp);
	fprintf(fp,"\n=====================以下是目标代码=========================\n");
	FDisplayCode(fp);
	
	fclose(fp);
	
	return 0;
}
