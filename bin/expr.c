/******************************************************************

    <公式>     ::= <语句块>
    <语句块>   ::= <语句>|<复合语句>
    <语句>     ::= <赋值语句>|<条件语句>|<空语句>
    <复合语句> ::= '{' {<语句块>} '}'
    <赋值语句> ::= <变量>=<表达式>;
    <条件语句> ::= if(<表达式>)<语句块>|if(<表达式>)<语句块>else<语句块>
    <空语句>   ::= ';'

    <表达式> 在<赋值语句>中遇到 ';' 为结尾,在<条件语句>中 ')' 无 '(' 可匹配为结尾;

**********************************************************************/

#include <hnixs.h>
#include <wwlog.h>
#include <wwcoding.h>
#include <wwfile.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <expr_supp.h>
#include <expr_fmp.h>

int igSymCnt;   /*符号流长度*/
int igSymPos;   /*符号流当前指针*/
struct SymbolStruct	SymbolFlow[SYMBOL_BUFLEN];

int igReserveCount=0;  /*保留字个数*/
/*定义系统的保留字及保留字的类型*/
struct ReserveKeywordStruct ReserveSymbol[100];

int igCodePos;     /*代码流的当前位置指针*/

/*当前已编译公式数量，公式结构*/
struct VariantStruct VarBuf[MAXVAR_COUNT+MAXSTACKLEN];
struct CodeStruct CodeBuf[CODE_BUFLEN];
struct OutputExprStruct OutputBuf[SYSVAR_COUNT]; /*输出区*/
struct ExprBufStruct ExprBuf;	/*公式结构缓冲*/
struct ExprBufStruct *pExprBuf=&ExprBuf;

/*while结构层次及continue堆栈、break堆栈*/
int WhileLevel=0,ContinueStack[WHILE_STACK],BreakStack[WHILE_STACK];
int iLabelSp=0;
struct LabelStruct LabelStack[LABEL_STACK];

int	igFilePos=0;		/*include到的文件列表索引*/
char	FileStack[128][256];	/*include到的文件名列表*/

void (*LoadVariant)(int,void *pi)=NULL;
void (*SaveVariant)(int,void *pi)=NULL;

void (*LoadConst)(char sVar[],char *pcType,void *pi)=NULL;
int  (*CheckSysVar)(char sVar[],char *pcType)=NULL;

#define GEN(a,b,c,d,e)  { if(Gen(a,b,c,d,e)<0) return -1;}
#define ADDSYMBOLFLOW(a,b,c,d) {if(AddSymbolFlow(a,b,c,d)<0) return -1;}


#define CHECKVAROFFSET(x) if((x)<0){\
			ReportExprError(CURORIPOS,"系统错误->变量太多");\
			return -igSymPos;\
		}

int NewLine(char c);

void InitExprBuf()
{
	ExprBuf.CodeBuf=	CodeBuf;
	ExprBuf.iCodeCnt=	0;
	ExprBuf.VarBuf=		VarBuf;
	ExprBuf.iSysVarCnt=	0;
	ExprBuf.iTmpVarCnt=	SYSVAR_COUNT;
	ExprBuf.iSysTmpCnt=	SYSVAR_COUNT;
	ExprBuf.OutputBuf=	OutputBuf;
	ExprBuf.iOutputLen=	0;
	
	ExprBuf.iPos=0;
	bzero((void*)&(ExprBuf.r),sizeof(struct VariantStruct));
	ExprBuf.r.cType=	VARTYPE_INT;
	strcpy(ExprBuf.sErrorMsg,"");
	ExprBuf.pRoot=		NULL;
	pExprBuf=		&ExprBuf;
}
struct ExprBufStruct *GetCompileResult()
{
	char	*pTemp;
	struct ExprBufStruct 	*pBuf;
	
	if(ExprBuf.iCodeCnt==0) return NULL;
	
	if((pTemp=(char *)malloc(sizeof(struct ExprBufStruct)+
		sizeof(struct CodeStruct)*ExprBuf.iCodeCnt+
		sizeof(struct VariantStruct)*(SYSVAR_COUNT+
			ExprBuf.iTmpVarCnt+MAXSTACKLEN)
		))==NULL) return NULL;
	
	pBuf=(struct ExprBufStruct *)pTemp;	
	memcpy((void*)pTemp,(void*)&ExprBuf,sizeof(struct ExprBufStruct));
	pTemp+=sizeof(struct ExprBufStruct);

	pBuf->CodeBuf=	(struct CodeStruct*)pTemp;
	memcpy((void*)pTemp,(void*)&(ExprBuf.CodeBuf[0]),
		sizeof(struct CodeStruct)*ExprBuf.iCodeCnt);
	pTemp+=sizeof(struct CodeStruct)*ExprBuf.iCodeCnt;
	
	pBuf->VarBuf=	(struct VariantStruct*)pTemp;
	
	memcpy((void*)pTemp,(void*)&(ExprBuf.VarBuf[0]),
		sizeof(struct VariantStruct)*(SYSVAR_COUNT+ExprBuf.iTmpVarCnt));
	/*修改BP和SP的指针*/
	pBuf->BP=pBuf->SP=pBuf->STACK_BP=ExprBuf.iTmpVarCnt;
	pBuf->OutputBuf=NULL;
	pBuf->iOutputLen=0;
	
	return pBuf;	
}
void DestroyExprBuf(struct ExprBufStruct *pExpr)
{
	int i;
	
	for(i=0;i<pExpr->iSysVarCnt;i++){
		if(pExpr->VarBuf[i].cType==VARTYPE_STR||
			pExpr->VarBuf[i].cType==VARTYPE_STRUCT){
			if(pExpr->VarBuf[i].u.sValue!=NULL)
				free(pExpr->VarBuf[i].u.sValue);
		}
	}
	for(i=SYSVAR_COUNT;i<pExpr->iTmpVarCnt;i++){
		if(pExpr->VarBuf[i].cType==VARTYPE_STR||
			pExpr->VarBuf[i].cType==VARTYPE_STRUCT){
			if(pExpr->VarBuf[i].u.sValue!=NULL)
				free(pExpr->VarBuf[i].u.sValue);
		}
	}
	/*如果是本地变量则不释放内存2008.12.31,hlm发现*/
	if(pExpr!=&ExprBuf) free(pExpr);
}
void DefSaveVariant(int i,void *pi)
{
	/*默认什么都不做*/
}

void DefLoadVariant(int i,void *pi)
{
	*(int*)pi=0;
}

void DefLoadConst(char sVar[],char *pcType,void *pi)
{
	if(strcmp(sVar,"null")==0){
		*pcType=VARTYPE_POINTER;
		*(void **)pi=NULL;
		return;
	}
	*pcType=VARTYPE_UNK;
	*(int*)pi=0;
}

/*解释字符串变量，返回参数及全局变量指针,TempLoadVariant*/
int DefCheckSysVar(char sVar[],char *pcType)
{
	*pcType=VARTYPE_UNK;
	LoadVariant=DefLoadVariant;
	SaveVariant=DefSaveVariant;
	return 0;
}

/*保存变更的公式变量*/
int GetSysVar(struct ExprBufStruct *pText,int iResetFlag)
{
	int i,iSysVarCnt;
	struct VariantStruct    *pDataSeg;
	struct SymVarStruct	*pSysSeg;

	pDataSeg=	pText->VarBuf;
	pSysSeg=	pText->SysBuf;
	
	iSysVarCnt=pText->iSysVarCnt;

/*		修改为直接输出		*/
	for(i=0;i<iSysVarCnt;i++){
		
		if(pSysSeg[i].cModified == 2){
			if(pSysSeg[i].SaveVariant==NULL){
				printf("变量%s没有定义输出函数-非法输出.\n",
					pSysSeg[i].sSymbol);
				WriteAlertMsg("变量%s没有定义输出函数-非法输出",
					pSysSeg[i].sSymbol);
				return -1;
			}
			/*直接调用输出函数，到相应变量中*/
			pSysSeg[i].SaveVariant(pSysSeg[i].iParam,
				(void*)&(pDataSeg[i].u));
		}
		/*复位系统变量*/
		if(iResetFlag==true) pSysSeg[i].cModified = 0;
	}

	return 0;
}

int CheckCode()
{
	int i;
	
	for(i=0;i<CURR_EXPR.iCodeCnt;i++){
		igCodePos=i;
		if(CheckCurCode()<0) return -i-1;
	}
	return 0;
}
int CheckCurCode()
{       
	char *sFunType;
	int i,j;
/*这里是实地址，不需要转换*/
#define CUROP		CODE_FLOW[igCodePos].op
#define ADDRD1		CODE_FLOW[igCodePos].data1
#define ADDRD2		CODE_FLOW[igCodePos].data2
#define ADDRR		CODE_FLOW[igCodePos].result

/*对于形式参数不检测*/
	if(ADDRD1>=MAXVAR_COUNT||ADDRD2>=MAXVAR_COUNT||ADDRR>=MAXVAR_COUNT)
		return 0;

	switch(CUROP){
	case JMP:
	case JMPF:
		/*无效目的地址,可能是需要修改的地址*/
		if(ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->跳转无效地址");
			return -1;
		}
		/*条件非整数*/
		if(CUROP==JMPF&&CODE_VARBUF[ADDRD1].cType!=VARTYPE_INT&&
			CODE_VARBUF[ADDRD1].cType!=VARTYPE_UNK){
			ReportExprError(CURORIPOS,"语义错误->跳转无效地址");
			return -1;
		}
		break;
	case RET:
	break;
	case ADD:
		/*非法地址*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->加法地址无效");
			return -1;
		}
		/*必须是类型相同的*/
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_STR||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE)){

				/*结果字段和操作字段相同*/
			if(CODE_VARBUF[ADDRR].cType==
				CODE_VARBUF[ADDRD1].cType) break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD1].cType;
				break;
			}
		}
		if((CODE_VARBUF[ADDRD1].cType==VARTYPE_INT||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_STR||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE)&&
				CODE_VARBUF[ADDRD2].cType==VARTYPE_UNK){
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD1].cType;
				break;
			}
		}
		if((CODE_VARBUF[ADDRD2].cType==VARTYPE_INT||
			CODE_VARBUF[ADDRD2].cType==VARTYPE_STR||
			CODE_VARBUF[ADDRD2].cType==VARTYPE_DOUBLE)&&
				CODE_VARBUF[ADDRD1].cType==VARTYPE_UNK){
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				/*增加安全性这里做了修改add1.type*/
				CODE_VARBUF[ADDRD1].cType=CODE_VARBUF[ADDRD2].cType;
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD2].cType;
				break;
			}
		}
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_POINTER&&
			CODE_VARBUF[ADDRD2].cType==VARTYPE_INT){
				/*结果字段和操作字段相同*/
			if(CODE_VARBUF[ADDRR].cType==
				CODE_VARBUF[ADDRD1].cType) break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD1].cType;
				break;
			}
		}
		ReportExprError(CURORIPOS,"语义错误->加法类型不一致");
		return -1;
	case SUB:
	case MULTI:
	case DIV:
		/*非法地址*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->操作%c地址无效",CUROP);
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT)){
			
				/*结果字段和操作字段相同*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE)){
			
				/*结果字段和操作字段相同*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_DOUBLE)
				break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_DOUBLE;
				break;
			}
		}
		ReportExprError(CURORIPOS,"语义错误->操作%c类型不匹配",CUROP);
		return -1;
	case SQR:
	case MOD:
	case OR:
	case AND:
	case MOR:
	case MAND:
		/*非法地址*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->操作%c地址无效",CUROP);
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT)){
			
				/*结果字段和操作字段相同*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		ReportExprError(CURORIPOS,"语义错误->操作%c类型不匹配",CUROP);
		return -1;
	case GT:
	case LT:
	case GE:
	case LE:
	case EQ:
	case NE:
		/*非法地址*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->操作%c地址无效",CUROP);
			return -1;
		}
		/*必须是类型相同的整数或字符串*/
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_STR||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE)){

				/*结果字段为整数*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		ReportExprError(CURORIPOS,"语义错误->操作%c类型不匹配",CUROP);
		return -1;
	case NOT:
		/*非法地址*/
		if(ADDRD1<0||ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->非操作地址无效");
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT){
			
				/*结果字段和操作字段相同*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		ReportExprError(CURORIPOS,"语义错误->非操作类型不匹配");
		return -1;
		
	case ASSIGN:
		/*非法地址*/
		if(ADDRD1<0||ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->赋值地址无效");
			return -1;
		}	
		
		/*如果是未初始化的变量，且不是中间变量*/
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_UNK&&
			(i=CODE_VARBUF[ADDRD1].iIndex)>=0){
			/*只有$开头的变量，保留用来给公式外部的程序初始化*/
			if(CODE_SYSBUF[i].sSymbol[0]=='$') break;
        	
			ReportExprError(CURORIPOS,"语义错误->变量%s未初始化就使用",
				CODE_SYSBUF[i].sSymbol);
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_STR||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_POINTER||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_STRUCT||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_UNK){
			
				/*结果字段和操作字段相同*/
			if(CODE_VARBUF[ADDRR].cType==CODE_VARBUF[ADDRD1].cType)
				break;
				/*结果字段是临时变量或者是未知变量*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK){
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD1].cType;
				break;
			}
			if(CODE_VARBUF[ADDRD1].cType==VARTYPE_UNK)
				break;
		}
		ReportExprError(CURORIPOS,"语义错误->赋值类型不匹配");
		return -1;
	case SFUN :/*静态函数不检查*/
	break;
	case DFUN:
	case FUN:
		/*非法地址*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"语义错误->函数调用地址无效");
			return -1;
		}
		
		if(CODE_VARBUF[ADDRD2].cType!=VARTYPE_STR){
			ReportExprError(CURORIPOS,"语义错误->函数编译错误");
			return -1;
		}
		sFunType=GetVarcharData(CODE_VARBUF[ADDRD2].u.sValue);
		if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||ADDRR>=SYSVAR_COUNT)
			CODE_VARBUF[ADDRR].cType=sFunType[0];

		if(CODE_VARBUF[ADDRR].cType!=sFunType[0]){
			ReportExprError(CURORIPOS,"语义错误->函数返回值类型错误");
			return -1;
		}
		for(i=0,j=1;j<strlen(sFunType);i++,j++){

			/*如果是可变参则直接不检查类型*/
			if(sFunType[j]=='#') break;
			
			if(CODE_VARBUF[ADDRD1+i].cType==VARTYPE_UNK&&
				ADDRD1+i>SYSVAR_COUNT)
				CODE_VARBUF[ADDRD1+i].cType=sFunType[j];

			if(sFunType[j]!=CODE_VARBUF[ADDRD1+i].cType&&
				sFunType[j]!=VARTYPE_UNK){
				ReportExprError(CURORIPOS,"语义错误->函数第%d参数类型不匹配",j);
				return -1;
			}
		}
	break;
	case OPSP:
		switch(ADDRD1){
		case P_OP_PUSH:
		case P_OP_POP:
			if(ADDRD2==ADDR_REGISTER){
				if(ADDRR==REGISTER_IP||ADDRR==REGISTER_BP||
					ADDRR==REGISTER_SP) return 0;
			}
			else if(ADDRD2==ADDR_VARIANT){
				if(ADDRD1==P_OP_PUSH){
					if(ADDRR>=0&&ADDRR<
					(MAXVAR_COUNT+MAXSTACKLEN)) return 0;
				}
				else{
					if(ADDRR>=-30&&ADDRR<
					(MAXVAR_COUNT+MAXSTACKLEN)) return 0;
				}
			}
		break;
		case P_OP_CALL:
			if(ADDRD2==-1&&ADDRR==-2&&
				CODE_FLOW[igCodePos].Oper!=NULL) return 0;
		break;
		default:break;
		}
	break;
	default:
	ReportExprError(CURORIPOS,"语义错误->非法指令");
	return -1;
	}
	return 0;
}
int ExecCode(struct ExprBufStruct *pText)
{
	double f1,f2;
	int d1,d2,i,r,iIndex,C_D1,C_D2,C_RES;
	char *s1,*s2,C_D1_TYPE;

	struct CodeStruct       *pCode,*pCodeSeg;
	struct VariantStruct    *pDataSeg;
	struct SymVarStruct	*pSysSeg;

	pExprBuf	=pText;
	
#define C_OPER		pCode->Oper
#define C_OP 		pCode->op
#define asVarInput	pDataSeg
#define asSysInput	pSysSeg

	pCodeSeg=	pText->CodeBuf;
	pDataSeg=	pText->VarBuf;
	pSysSeg=	pText->SysBuf;
	
	igCodePos = 0;

	while(igCodePos<pText->iCodeCnt){

		pCode = pCodeSeg+igCodePos;
	/*为了提高效率改为变量*/
		C_D1=MY_AD(pCode->data1);
		C_D2=MY_AD(pCode->data2);
		C_RES=MY_AD(pCode->result);
	/*检查是否有堆栈溢出*/
		CHECK_AD(C_D1);
		CHECK_AD(C_D2);
		CHECK_AD(C_RES);
	/*地址有效则直接获取，否则取默认整数类型*/
		if(IS_ADDR(C_D1)==true)C_D1_TYPE=pDataSeg[C_D1].cType;
		else	C_D1_TYPE=VARTYPE_INT;

		switch( C_OP ){
		case JMP:
			igCodePos = 	pCode->result;
			continue;
		case JMPF:
			d1 = GetIntVariant(pDataSeg,C_D1);
			if( d1 == 0)	igCodePos=pCode->result;
			else		igCodePos++;
			continue;
		case RET:
			if(C_D1!=-1){/*直接复制到公式返回区*/
				if(C_D1_TYPE==VARTYPE_INT){
					d1 = GetIntVariant(pDataSeg,C_D1);
					CURR_EXPR.r.u.iValue = d1;
				}
				else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
					GetStrVariant(pDataSeg,C_D1);/*必要的*/
					AssignV2VStrchar(&(CURR_EXPR.r.u.sValue),
						asVarInput[C_D1].u.sValue);
				}
				else if(C_D1_TYPE==VARTYPE_DOUBLE){
					f1 = GetDoubleVariant(pDataSeg,C_D1);
					CURR_EXPR.r.u.dValue = f1;
				}
				else if(C_D1_TYPE==VARTYPE_POINTER){
					s1 = GetPointVariant(pDataSeg,C_D1);
					CURR_EXPR.r.u.pValue=s1;
				}
				else{/*结构赋值*/
					GetPointVariant(pDataSeg,C_D1);/*必要的*/
					AssignV2VMemchar(&(asVarInput[C_RES].u.sValue),
						CURR_EXPR.r.u.sValue);
				}
				CURR_EXPR.r.cType=C_D1_TYPE;
			}
			igCodePos = pText->iCodeCnt;
			continue;
		case ADD:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				asVarInput[C_RES].u.iValue = d1 + d2;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				AddV2VStrchar(&(asVarInput[C_RES].u.sValue),
					asVarInput[C_D1].u.sValue,
					asVarInput[C_D2].u.sValue);
			}
			else if(C_D1_TYPE==VARTYPE_DOUBLE){
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				asVarInput[C_RES].u.dValue=f1+f2;
			}
			else{/*指针加法*/
				s1 = GetPointVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				pDataSeg[C_RES].u.pValue=s1+d2;
			}
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			break;
		case SUB:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				asVarInput[C_RES].u.iValue = d1 - d2;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				asVarInput[C_RES].u.dValue=f1-f2;
			}
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			break;
		case MULTI:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				asVarInput[C_RES].u.iValue = d1 * d2;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				asVarInput[C_RES].u.dValue=f1*f2;
			}
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			break;
		case DIV:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				if(d2 == 0 ){
					WriteAlertMsg("公式的除数为0");
					return -1;
				}
				asVarInput[C_RES].u.iValue = d1 / d2;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				if(f2 == 0 ){
					WriteAlertMsg("公式的除数为0");
					return -1;
				}				
				asVarInput[C_RES].u.dValue=f1/f2;
			}
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			break;
		case MOD:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			asVarInput[C_RES].u.iValue=d1%d2;
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			break;
		case SQR:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			r = 1;
			for(i=0;i<d2;i++) r *= d1;
			asVarInput[C_RES].u.iValue *= r;
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			break;
		case GT:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				r  = d1>d2?1:0;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				s1 = GetStrVariant(pDataSeg,C_D1);
				s2 = GetStrVariant(pDataSeg,C_D2);
				r  = strcmp(s1,s2)>0?1:0;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				r  = f1>f2?1:0;
			}
			asVarInput[C_RES].u.iValue = r;
			break;
		case LT:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				r  = d1<d2?1:0;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				s1 = GetStrVariant(pDataSeg,C_D1);
				s2 = GetStrVariant(pDataSeg,C_D2);
				r  = strcmp(s1,s2)<0?1:0;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				r  = f1<f2?1:0;
			}
			asVarInput[C_RES].u.iValue = r;
			break;
		case GE:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				r  = d1>=d2?1:0;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				s1 = GetStrVariant(pDataSeg,C_D1);
				s2 = GetStrVariant(pDataSeg,C_D2);
				r  = strcmp(s1,s2)>=0?1:0;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				r  = f1>=f2?1:0;
			}
			asVarInput[C_RES].u.iValue = r;
			break;
		case LE:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				r  = d1<=d2?1:0;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				s1 = GetStrVariant(pDataSeg,C_D1);
				s2 = GetStrVariant(pDataSeg,C_D2);
				r  = strcmp(s1,s2)<=0?1:0;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				r  = f1<=f2?1:0;
			}
			asVarInput[C_RES].u.iValue = r;
			break;
		case EQ:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				r  = d1==d2?1:0;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				s1 = GetStrVariant(pDataSeg,C_D1);
				s2 = GetStrVariant(pDataSeg,C_D2);
				r  = strcmp(s1,s2)==0?1:0;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				r  = f1==f2?1:0;
			}
			asVarInput[C_RES].u.iValue = r;
			break;
		case NE:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				r  = d1!=d2?1:0;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				s1 = GetStrVariant(pDataSeg,C_D1);
				s2 = GetStrVariant(pDataSeg,C_D2);
				r  = strcmp(s1,s2)!=0?1:0;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				r  = f1!=f2?1:0;
			}
			asVarInput[C_RES].u.iValue = r;
			break;
		case OR:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			asVarInput[C_RES].u.iValue = ( d1 || d2);
			break;
		case AND:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			asVarInput[C_RES].u.iValue = ( d1 && d2);
			break;
		case MOR:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			asVarInput[C_RES].u.iValue =  d1 | d2;
			break;
		case MAND:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			asVarInput[C_RES].u.iValue =  d1 & d2;
			break;
		case NOT:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			asVarInput[C_RES].u.iValue = !(d1);
			break;
		case ASSIGN:
			if(C_D1_TYPE==VARTYPE_INT){
				d1 = GetIntVariant(pDataSeg,C_D1);
				asVarInput[C_RES].u.iValue = d1;
			}
			else if(C_D1_TYPE==VARTYPE_STR){/*字符串处理*/
				GetStrVariant(pDataSeg,C_D1);/*必要的*/
				AssignV2VStrchar(&(asVarInput[C_RES].u.sValue),
					asVarInput[C_D1].u.sValue);
			}
			else if(C_D1_TYPE==VARTYPE_DOUBLE){
				f1 = GetDoubleVariant(pDataSeg,C_D1);
				asVarInput[C_RES].u.dValue = f1;
			}
			else if(C_D1_TYPE==VARTYPE_POINTER){
				s1 = GetPointVariant(pDataSeg,C_D1);
				asVarInput[C_RES].u.pValue=s1;
			}
			else{/*结构赋值*/
				GetPointVariant(pDataSeg,C_D1);/*必要的*/
				AssignV2VMemchar(&(asVarInput[C_RES].u.sValue),
					asVarInput[C_D1].u.sValue);
			}
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			if(IS_TMPTMPVAR(C_RES))/*这里非常关键将变量参数带入*/
				asVarInput[C_RES].iParam=asVarInput[C_D1].iParam;
			
			break;
		case SFUN:/*静态函数不做事情*/
			igCodePos++;
			continue;
		case DFUN:/*调用动态函数*/
			r=C_OPER(C_D1,C_RES);
			if(r<0) return -1;
			igCodePos++;
			/*如果是系统变量则修改赋值标识*/
			if((iIndex=asVarInput[C_RES].iIndex)!=-1)
				asSysInput[iIndex].cModified = 2;
			/*结果操作数是形式参数或无类型变量则要修改类型*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			continue;
		case FUN:
			/*IP入栈*/
			MY_PUSH_REG(igCodePos+1);/*直接跳转到指定地址*/
			igCodePos=asVarInput[C_RES].iParam;
			continue;
		case OPSP:
			if(pCode->data1==P_OP_PUSH){
				if(pCode->data2==ADDR_REGISTER){
					switch(pCode->result){
					case REGISTER_IP:
						MY_PUSH_REG(igCodePos);
					break;
					case REGISTER_BP:
						MY_PUSH_REG(CURR_EXPR.BP);
					break;
					case REGISTER_SP:
						MY_PUSH_REG(CURR_EXPR.SP);
					break;
					default:
						MY_PUSH_REG(CURR_EXPR.BP);
					break;
					}
				}
				else{
					MY_PUSH_ADDR(C_RES);
				}
			}
			else if(pCode->data1==P_OP_POP){
				if(pCode->data2==ADDR_REGISTER){
					switch(pCode->result){
					case REGISTER_IP:
						MY_POP_REG(igCodePos);
					continue;/*修改返回地址，退出*/
					case REGISTER_BP:
						MY_POP_REG(CURR_EXPR.BP);
					break;
					case REGISTER_SP:
						MY_POP_REG(CURR_EXPR.SP);
					break;
					default:
						MY_POP_REG(CURR_EXPR.BP);
					break;
					}
				}
				else{
					MY_POP_ADDR(C_RES);
				}				
			}
			else if(pCode->data1==P_OP_CALL){
				/*这里就调用一下函数操作*/
				if(C_OPER(C_D1,C_RES)<0) return -1;
			}
			/*其他情况的东西不处理*/
			igCodePos++;
			continue;
		default:
			break;
		} /*end switch*/
		if((iIndex=asVarInput[C_RES].iIndex)!=-1)
			asSysInput[iIndex].cModified = 2;
		igCodePos++;

	}/*end while*/
	
	if(GetSysVar(pText,true)<0) return -1;
	
	return 0;
}

int GetIntVariant(struct VariantStruct *pDataSeg,int iOffset)
{
	struct VariantStruct *pData;

	if(iOffset==-1)	return 0;

	pData=CODE_VARBUF+iOffset;
	
	if(iOffset>=SYSVAR_COUNT) return pData->u.iValue;	/* 临时变量 */

	if(CODE_SYSBUF[iOffset].cModified > 0) return pData->u.iValue;
	

	/*注意这里必须在加载变量前，因为变量加载函数内部可能修改它*/
	CODE_SYSBUF[iOffset].cModified = 1;	
	CODE_SYSBUF[iOffset].LoadVariant(CODE_SYSBUF[iOffset].iParam,
		(void*)&(pData->u));

	return pData->u.iValue;	
	 
}
char *GetAddrVariant(struct VariantStruct *pDataSeg,int iOffset)
{
	return (char*)&(pDataSeg[iOffset].u);
}	
char *GetStrVariant(struct VariantStruct *pDataSeg,int iOffset)
{
	struct VariantStruct *pData;

	if(iOffset==-1)	return NULL;

	pData=CODE_VARBUF+iOffset;
	
	/* 临时变量 */
	if(iOffset>=SYSVAR_COUNT) return GetVarcharData(pData->u.sValue);

	if(CODE_SYSBUF[iOffset].cModified>0) 
		return GetVarcharData(pData->u.sValue);
	

	/*注意这里必须在加载变量前，因为变量加载函数内部可能修改它*/
	CODE_SYSBUF[iOffset].cModified = 1;	
	CODE_SYSBUF[iOffset].LoadVariant(CODE_SYSBUF[iOffset].iParam,
		(void*)&(pData->u));

	return GetVarcharData(pData->u.sValue);	
}
char *GetPointVariant(struct VariantStruct *pDataSeg,int iOffset)
{
	struct VariantStruct *pData;

	if(iOffset==-1)	return NULL;

	pData=CODE_VARBUF+iOffset;
	
	if(iOffset>=SYSVAR_COUNT) return pData->u.pValue;	/* 临时变量 */

	if(CODE_SYSBUF[iOffset].cModified > 0) return pData->u.pValue;
	

	/*注意这里必须在加载变量前，因为变量加载函数内部可能修改它*/
	CODE_SYSBUF[iOffset].cModified = 1;	
	CODE_SYSBUF[iOffset].LoadVariant(CODE_SYSBUF[iOffset].iParam,
		(void*)&(pData->u));

	return pData->u.pValue;	
	 
}
double GetDoubleVariant(struct VariantStruct *pDataSeg,int iOffset)
{
	struct VariantStruct *pData;

	if(iOffset==-1)	return 0;

	pData=CODE_VARBUF+iOffset;
	
	if(iOffset>=SYSVAR_COUNT) return pData->u.dValue;	/* 临时变量 */

	if(CODE_SYSBUF[iOffset].cModified > 0) return pData->u.dValue;
	
	/*注意这里必须在加载变量前，因为变量加载函数内部可能修改它*/
	CODE_SYSBUF[iOffset].cModified = 1;	
	CODE_SYSBUF[iOffset].LoadVariant(CODE_SYSBUF[iOffset].iParam,
		(void*)&(pData->u));

	return pData->u.dValue;	
}

void DisplaySymbolFlow()
{
	int iType,i;
	char asType[23][12]={"LOG1","LOG2","MATH","CONTROL","CONST",
		"SYSVAR","TEMPVAR","SEPARATOR","ASSIGN","MATH1","CONSTSTR",
		"CONSTHEX","CONSTDEC","CONSTBIN","SFUN","DFUN","DOUBLE",
		"LCONSTSTR","MODALITY","PRECOMP","DECLARE","MICRO","FUN"};
       for(i=0;i<igSymCnt;i++){
       		iType=SymbolFlow[i].iType-1;
		if(strchr(SymbolFlow[i].sValue,'%')==NULL)
       			WriteProcMsg("%03d: %10s  %s\n",
				i,asType[iType],SymbolFlow[i].sValue);
		else if(strcmp(SymbolFlow[i].sValue,"\n")==0)
       			WriteProcMsg("%03d: %10s  \\n\n",i,asType[iType]);
		else
       			WriteProcMsg("%03d: %10s \n",i,asType[iType]);

       		if(strcmp(SymbolFlow[i].sValue,"\n")==0)
       			printf("%03d: %10s  \\n\n",i,asType[iType]);
       		else  	printf("%03d: %10s  %s\n",i,asType[iType],SymbolFlow[i].sValue);
       }
}
void OutputCompileResult(int *piOutputLen,struct OutputExprStruct asVarOutput[])
{
	/*公式编译成功，输出可能输出项的符号*/
	(*piOutputLen) = CURR_EXPR.iOutputLen;
	memcpy(asVarOutput,CURR_EXPR.OutputBuf,
		(*piOutputLen)*sizeof(struct OutputExprStruct));
}
int CheckCompileResult(int iOutputLen,struct OutputExprStruct asVarOutput[])
{
	int i;

	/**2002-01-16检查CheckSysVar的合法性***/
	for(i=0;i<iOutputLen;i++){

		if(asVarOutput[i].iParam<0){
			ReportExprError(0,"变量检测错误->遇到非法变量%s",
				asVarOutput[i].sSymbol);
			return -1;
		}
	}
	if(CURR_EXPR.iSysVarCnt>=SYSVAR_COUNT){
		
		ReportExprError(0,"系统错误->系统变量数%d超过最大数%d",
			CURR_EXPR.iSysVarCnt,SYSVAR_COUNT);
		return -1;
	}
	if(CURR_EXPR.iTmpVarCnt>=(MAXVAR_COUNT-SYSVAR_COUNT)){
		ReportExprError(0,"系统错误->临时变量数%d超过最大数%d",
			CURR_EXPR.iTmpVarCnt,
			MAXVAR_COUNT-SYSVAR_COUNT);
		return -1;
	}
	return 0;
}
void GetLinePosInfo(char sInput[],int iOff,int *piLine,int *piPos)
{
	int i,iLine=1,iPos=0,j;

	for(i=0;i<iOff;i++){
		if(sInput[i]=='\n'){
			iLine++;
			iPos=i+1;
		}
	}
	i=iPos;j=0;
	while(i<iOff){
		if(sInput[i]!='\t') j++;
		else	j=(j+8)/8*8;
		i++;
	}
	iPos=j;
	*piLine=iLine;
	*piPos=iPos;	
}
void ReportExprError(int iPos,char *fmt,...)
{
	int l;
	va_list	argptr;

	pExprBuf->iPos=	iPos;
	
	strcat(pExprBuf->sErrorMsg,"\n");
	l=strlen(pExprBuf->sErrorMsg);
	
	va_start(argptr, fmt);
	vsprintf(pExprBuf->sErrorMsg+l,fmt,argptr);
	va_end(argptr);
}
void FormatExprErrorMsg(char s[])
{
	int iLine=0,iPos=0,i=0,j,l,iIndex,iOffset;
	char sLine[512],sLineBegin[512],sLineEnd[512],sPin[512];
	char sMsg[256],sTemp[512],sInput[EXPRLEN];

	/*将错误位置解码*/
	DecodingOriPos(pExprBuf->iPos,&iIndex,&iOffset);

	if(iIndex>0){
		/*如果文件读入错误，则直接将文件名字和偏移打出，供参考*/
		if(ReadFileToBuf(FileStack[iIndex],EXPRLEN,sInput,sMsg)<0){
			sprintf(pExprBuf->sErrorMsg,"文件%s读入错误%s,偏移%d",
				FileStack[iIndex],sMsg,iOffset);
			return;
		}
	}
	else strcpy(sInput,s);
	
	GetLinePosInfo(sInput,iOffset,&iLine,&iPos);

	i=iOffset;j=0;
	while(sInput[i]!='\n'&&sInput[i]!=0)
		sLineEnd[j++]=sInput[i++];

	sLineEnd[j]=0;
		
	i=iOffset-1;j=0;
	while(sInput[i]!='\n'&&i>0)
		sLineBegin[j++]=sInput[i--];
	sLineBegin[j]=0;
	
	l=strlen(sLineBegin);
	for(i=0,j=0;i<l;i++)
		sLine[j++]=sLineBegin[l-i-1];
	sLine[j]=0;
	strcat(sLine,sLineEnd);
	
	strcpy(sTemp,pExprBuf->sErrorMsg);
	for(i=0;i<iPos;i++) sPin[i]=' '; sPin[i++]='^';sPin[i]=0;
	sprintf(pExprBuf->sErrorMsg,"文件%s\n%s\n%s\n位置:%d行%d列,%s",
		FileStack[iIndex],sLine,sPin,iLine,iPos+1,sTemp);
}
void ResetTmpSysVar()
{
	char *pc=NULL;
	int i,j,iSysTmpCnt;

	struct ExprBufStruct	*pText;
	struct VariantStruct	*pDataSeg;
	struct SymVarStruct	*pSysSeg;

	pText=		&(CURR_EXPR);
	pDataSeg=	pText->VarBuf;
	pSysSeg=	pText->SysBuf;

	iSysTmpCnt=	pText->iSysTmpCnt;

	for(i=SYSVAR_COUNT;i<iSysTmpCnt;i++){

		if(pSysSeg[i].sSymbol[0]=='$') continue;

		j=pSysSeg[i].iIndex;

		switch(pDataSeg[j].cType){
		case VARTYPE_INT:
			pDataSeg[j].u.iValue=0;
		break;
		case VARTYPE_STR:
			pc=GetStrVariant(pDataSeg,j);
			if(pc!=NULL) strcpy(pc,"");
		break;
		case VARTYPE_POINTER:
			pDataSeg[j].u.sValue=NULL;
		break;
		case VARTYPE_DOUBLE:
			pDataSeg[j].u.dValue=0.0;
		break;
		}
	}
}
int CompileExpr(char sInput[],struct OutputExprStruct asVarOutput[],
	int * piOutputLen)
{
	int iRet;
	char sMsg[256];
	static int iFirstFlag=true;

	if(iFirstFlag==true){
		iFirstFlag=false;
		RegExprFun();
	}
	
	InitExprBuf();
	InitExprIntfVar();

	iLabelSp=0;
	igSymCnt=0;   /*符号流长度*/
	igSymPos=0;   /*符号流当前指*/

	WhileLevel=0; /*清除变量*/
	igCodePos=0;  /*清除变量*/
		
/*清除公式的输出缓冲区（编译阶段的输出为等式左边的系统变量，即可能产生的输出）*/
	CURR_EXPR.iOutputLen = 0;

/*复位加载变量 常量 检查变量函数*/

	if(LoadConst==NULL)
		LoadConst=DefLoadConst;	/*加载常量函数*/

	/*定位加载变量函数,并解析字符串为参数*/
	if(CheckSysVar==NULL)
		CheckSysVar= DefCheckSysVar;

	InitReserveSymbol();
	
	/*进行词法分析,生成单词序列*/
	if( (iRet = PropLexicalize(sInput,sMsg)) <0){
		FormatExprErrorMsg(sInput);
		return -2;
	}

#ifdef DEBUG_EXPR
	DisplaySymbolFlow();
#endif
	/*语法及语义分析,生成四元组序列*/
	if((iRet=GenerateCode())<0){

		FormatExprErrorMsg(sInput);
		
		return -3;
	}
#ifdef DEBUG_EXPR
	DisplayCode();
#endif
	/*检查是否全部被成功编译*/
	if(igSymPos<igSymCnt){
		
		ReportExprError(C_ORIPOS,"公式不完整,{ 和 } 不匹配");
		
		FormatExprErrorMsg(sInput);
		
		return -igSymPos;
	}

	if((iRet=CheckCode())<0){

		FormatExprErrorMsg(sInput);
		return -4;
	}
	OutputCompileResult(piOutputLen,asVarOutput);
	
	if(CheckCompileResult(*piOutputLen,asVarOutput)<0)return -5;

	return 0;
}
void DisplaySysVar()
{
	int i;
	for(i=0;i<CURR_EXPR.iSysVarCnt;i++){
		if(CODE_VARBUF[i].cType==VARTYPE_INT){
			WriteProcPrint("%d\t%c\t%s=%d.\n",i,
				CODE_VARBUF[i].cType,CODE_SYSBUF[i].sSymbol,
				CODE_VARBUF[i].u.iValue);
		}
		else if(CODE_VARBUF[i].cType==VARTYPE_STR){
			WriteProcPrint("%d\t%c\t%s=%s.\n",i,
				CODE_VARBUF[i].cType,CODE_SYSBUF[i].sSymbol,
				GetVarcharData(CODE_VARBUF[i].u.sValue));
		}
		else{
			WriteProcPrint("%d\t%c\t%s\n",i,
				CODE_VARBUF[i].cType,CODE_SYSBUF[i].sSymbol);
		}
	}
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
		sprintf(pin,"pt%ld",(unsigned long)CODE_VARBUF[iIndex].u.pValue);
	else
		sprintf(pin,"st%ld",(unsigned long)CODE_VARBUF[iIndex].u.pValue);
}

void GetSysSymbol(int i,char sTemp[],int iFlag)
{
	
	if(i<0)	strcpy(sTemp,"");
	else if(i<SYSVAR_COUNT)	strcpy(sTemp,CODE_SYSBUF[i].sSymbol);
	else if(i>=MAXVAR_COUNT)sprintf(sTemp,"BP[%d]",i-MAXVAR_COUNT);
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
void DisplayCode()
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
			WriteProcPrint("%s jmp   ==>    %5d",sItem,r);
		break;
		case JMPF:
			WriteProcPrint("%s jmpf  ==>    %5d",sItem,r);
		break;
		case RET:
			WriteProcPrint("%s return==>    %5d",sItem,r);
	    	break;
	    	case ASSIGN:
			WriteProcPrint("%s %s = %s",sItem,MY_R,MY_D1);
		break;
		case SFUN:
		case DFUN:
			GetConstValuePin(d2,pin);
			strcpy(sName,"");
			SearchRegFunLinkByAddr(CODE_FLOW[i].Oper,sName);
			if(MY_D1[0]=='[') sprintf(MY_D1,"[%d]",d1);
			WriteProcPrint("%s %s = %ccall %s(%s,%s)",
	    			sItem,MY_R,op,sName,MY_D1,pin);
	    	break;
	    	case FUN:
			GetConstValuePin(d2,pin);
	    		strcpy(sName,"");
	    		SearchDefFunByAddr(CODE_VARBUF[r].iParam,sName);
	    		if(MY_D1[0]=='[') sprintf(MY_D1,"[%d]",d1);
			WriteProcPrint("%s %s = %ccall %s(%s,%s)",
	    			sItem,MY_R,op,sName,MY_D1,pin);
	    	break;
	    	case OPSP:
	    		if(d1==P_OP_PUSH||d1==P_OP_POP){
	    			
	    			if(d1==P_OP_PUSH)strcpy(pin,"PUSH");
	    			else		strcpy(pin,"POP");

	    			if(d2==ADDR_REGISTER){
	    				switch (r){
	    				case REGISTER_IP:
	    				WriteProcPrint("%s %s IP",sItem,pin);
					break;
	    				case REGISTER_BP:
	    				WriteProcPrint("%s %s BP",sItem,pin);
	    				break;
	    				case REGISTER_SP:
	    				WriteProcPrint("%s %s SP",sItem,pin);
	    				break;
	    				default:
	    				WriteProcPrint("%s %s BP",sItem,pin);
	    				break;
	    				}
	    			}
	    			else{
	    				if(r>0)WriteProcPrint("%s %s %s",sItem,pin,MY_R);
	    				else WriteProcPrint("%s %s p1-p%d->null",sItem,pin,-r);
	    			}
			}
			else if(CODE_FLOW[i].data1==P_OP_CALL){
				if(CODE_FLOW[i].Oper==mv_sp2bp)
					WriteProcPrint("%s BP=SP",sItem);
				else if(CODE_FLOW[i].Oper==mv_bp2sp)
					WriteProcPrint("%s SP=BP",sItem);
				else if(CODE_FLOW[i].Oper==clear_variant)
					WriteProcPrint("%s CLS %s",sItem,MY_R);
			}
			else
				WriteProcPrint("%s %s = %s %c %s",
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
			WriteProcPrint("%s %s = %s %s %s",
    	 			sItem,MY_R,MY_D1,sOp,MY_D2);
    	 	}
		break;
		}
	}
}
/*生成代码*/
int GenerateCode()
{
	igSymPos = 0;
	igCodePos = 0;
	
	while(igSymPos<igSymCnt){
		
		if(ProcStatementBlock()<0) return -igSymPos;
	}
	CURR_EXPR.STACK_BP=CURR_EXPR.BP=CURR_EXPR.SP=MAXVAR_COUNT;
	CURR_EXPR.iCodeCnt=igCodePos;
	
	return 0;
}

/*处理 <语句块>*/
int ProcStatementBlock()
{
	if(C_TYPE==TYPE_SEPARATOR&&C_CVALUE=='{'){
		if(ProcComplexStatement()<0)
			return -igSymPos;
	}
	else{
		if(ProcStatement()<0)
			return -igSymPos;
	}
	return 0;
}

/*处理 <复合语句>*/
/* 堆栈处理{}所包含的语句 */
int ProcComplexStatement()
{
	igSymPos++;        /*读入'{'*/
	while(!(C_TYPE==TYPE_SEPARATOR&&C_CVALUE=='}') && igSymPos<igSymCnt){

		if( C_TYPE==TYPE_SEPARATOR &&  C_CVALUE=='{' ){
			if(ProcComplexStatement()<0)
				return -igSymPos;
		}
		else{
			if(ProcStatement()<0)
				return -igSymPos;
		}
	}; /*处理直到匹配到 '}'*/

	if((igSymPos>=igSymCnt)||(C_TYPE!=TYPE_SEPARATOR)||(C_CVALUE!='}')){
		ReportExprError(C_ORIPOS,"语义错误->{无法匹配到}");
		return -igSymPos;
	}

	igSymPos++; /*读入 '{'*/
	return 0;

}
int ProcGotoTarget(int iTargetCodeAddr)
{
	int i,iJmpCodeAddr;

	for(i=0;i<iLabelSp;i++){
		if(strcmp(C_SVALUE,LabelStack[i].sLabel)==0){
			if(LabelStack[i].iTargetCodeAddr!=-1){
				ReportExprError(CURRORIPOS,"语义错误->发现重名卷标%s",
					LabelStack[i].sLabel);
				return -1;
			}
			LabelStack[i].iTargetCodeAddr=iTargetCodeAddr;
			iJmpCodeAddr=LabelStack[i].iJmpCodeAddr;
			SetJmpAddr(iJmpCodeAddr,iTargetCodeAddr);
		}
	}
	/*没有发现goto语句到该标识*/
	if(i==iLabelSp){
		if(iLabelSp>=LABEL_STACK-1){
			ReportExprError(CURRORIPOS,"系统错误->卷标栈溢出");
			return -1;
		}
		strcpy(LabelStack[i].sLabel,C_SVALUE);
		LabelStack[i].iTargetCodeAddr=	iTargetCodeAddr;
		LabelStack[i].iJmpCodeAddr=	-1;
		iLabelSp++;
		
	}
	return 0;
}
int ProcGotoJmp(int iJmpCodeAddr)
{
	int i,iTargetCodeAddr;

	for(i=0;i<iLabelSp;i++){
		if(strcmp(C_SVALUE,LabelStack[i].sLabel)==0){
			if(LabelStack[i].iTargetCodeAddr!=-1){
				iTargetCodeAddr=LabelStack[i].iTargetCodeAddr;
				SetJmpAddr(iJmpCodeAddr,iTargetCodeAddr);
				break;
			}
		}
	}
	/*没有发现goto语句的目的标识*/
	if(i==iLabelSp){
		if(iLabelSp>=LABEL_STACK-1){
			ReportExprError(CURRORIPOS,"系统错误->卷标栈溢出");
			return -1;
		}
		strcpy(LabelStack[i].sLabel,C_SVALUE);
		LabelStack[i].iTargetCodeAddr=	-1;
		LabelStack[i].iJmpCodeAddr=	iJmpCodeAddr;
		iLabelSp++;
		
	}
	return 0;
}
int ProcGotoCheck()
{
	int i;
	
	for(i=0;i<iLabelSp;i++){
		if(LabelStack[i].iTargetCodeAddr==-1){
			ReportExprError(CURORIPOS,
				"语法错误->goto标识%s,目的地址没有定义",
				LabelStack[i].sLabel);
			return -1;
		}
	}
	return 0;
}
/*处理 <申明语句>*/
int ProcDeclareStatement()
{
	char cType;
	int iTmpAddr=0;

	if(C_TYPE!=TYPE_DECLARE) return -igSymPos;
	
	if(strcmp(C_SVALUE,"int")==0)		cType='1';
	else if(strcmp(C_SVALUE,"string")==0)	cType='2';
	else if(strcmp(C_SVALUE,"double")==0)	cType='5';
	else if(strcmp(C_SVALUE,"struct")==0)	cType='4';
	else if(strcmp(C_SVALUE,"pointer")==0)	cType='3';
	else{
		return -igSymPos;
	}

	igSymPos++;/*读入类型字符*/

	while(1){
		if(C_TYPE!=TYPE_TEMPVAR&&C_TYPE!=TYPE_SYSVAR){

			ReportExprError(C_ORIPOS,
			"语义错误->申明遇到%s,不是系统或临时变量",C_SVALUE);

			return -igSymPos;
		}
		iTmpAddr=GetVarOffset(C_SVALUE);

		CHECKVAROFFSET(iTmpAddr);

		/*如果变量没设置则设置之*/		
		if(CODE_VARBUF[iTmpAddr].cType==VARTYPE_UNK)
			CODE_VARBUF[iTmpAddr].cType=cType;

		if(CODE_VARBUF[iTmpAddr].cType!=cType){

			ReportExprError(C_ORIPOS,
				"语义错误->申明%s,类型冲突,原类型%c,现类型%c",
				C_SVALUE,CODE_VARBUF[iTmpAddr].cType,cType);

			return -igSymPos;
		}
		
		igSymPos++;/*读入一个变量*/
		
		/*如果申明结束就OK*/
		if(C_TYPE==TYPE_SEPARATOR && C_CVALUE==';') break;
		
		if(!(C_TYPE==TYPE_SEPARATOR && C_CVALUE==',')){
			
			ReportExprError(C_ORIPOS,
			"语义错误->申明语句,变量间为',',而不为%s",	C_SVALUE);

			return -igSymPos;			
		}
		
		igSymPos++;/*读入变量间的间隔符*/
	}

	igSymPos++; /*读入结束符*/

	return 0;
}
/*处理 <语句>*/
int ProcStatement()
{

	/*如果是'if'打头的,处理条件语句,否则是赋值语句*/
	if(( C_TYPE ==TYPE_CONTROL)&&( strcmp(C_SVALUE,"if")==0))
		return (ProcConditionStatement()<0)?-igSymPos:0;

	if(( C_TYPE ==TYPE_CONTROL)&&( strcmp(C_SVALUE,"while")==0))
		return (ProcWhileStatement()<0)?-igSymPos:0;

	if((C_TYPE ==TYPE_CONTROL)&& 
		( strcmp(C_SVALUE,"return")==0||
		  strcmp(C_SVALUE,"break")==0||
		  strcmp(C_SVALUE,"continue")==0))
		return (ProcControlStatement()<0)?-igSymPos:0;
/*处理goto目的标识符*/
	if((C_TYPE==TYPE_TEMPVAR)&&(
		C_TYPEN==TYPE_SEPARATOR&&C_CVALUEN==':')){
		
		int iTargetCodeAddr=igCodePos;
		
		if(ProcGotoTarget(iTargetCodeAddr)<0) return -igSymPos;
		igSymPos+=2;
		return 0;
	}
/*处理goto语句*/
	if((C_TYPE ==TYPE_CONTROL)&&strcmp(C_SVALUE,"goto")==0){
		
		int iJmpCodeAddr;
		
		igSymPos++;
		if(C_TYPE!=TYPE_TEMPVAR){
			ReportExprError(C_ORIPOS,"语义错误->应为卷标,但遇到了%s",C_SVALUE);
			return -igSymPos;
		}
		
		GEN(JMP,-1,-1,-1,NULL);
		iJmpCodeAddr = igCodePos-1;/*记住当前JMP的代码地址*/
		
		if(ProcGotoJmp(iJmpCodeAddr)<0) return -igSymPos;
		igSymPos++;
		if((C_TYPE==TYPE_SEPARATOR)&&( C_CVALUE == ';')){
			igSymPos++;
			return 0;
		}
		ReportExprError(C_ORIPOS,"语义错误->应为';',但遇到了%s",C_SVALUE);
		return -igSymPos;
	}
/*处理赋值语句*/
	if(C_TYPE==TYPE_SYSVAR||C_TYPE==TYPE_TEMPVAR||
		C_TYPE==TYPE_MODALITY_PARA)
		return (ProcAssignStatement()<0)?-igSymPos:0;
/*处理动态函数*/
	if(C_TYPE==TYPE_DFUN){
		if(ProcDFunStatement(-1)<0) return -igSymPos;
	}
/*处理静态函数*/
	if(C_TYPE==TYPE_SFUN){
		if(ProcSFunStatement(-1)<0) return -igSymPos;
	}
/*处理自定义函数*/
	if(C_TYPE==TYPE_FUN&&C_CVALUEN=='('){
		if(ProcFunStatement(-1)<0) return -igSymPos;
	}
/*处理函数定义语句*/
	if(C_TYPE==TYPE_FUN){
		return (ProcFunDefStatement()<0)?-igSymPos:0;
	}
	if(C_TYPE==TYPE_SEPARATOR&&(C_CVALUE==';'||NewLine(C_CVALUE))){
		igSymPos++;     /*空语句,读入 ';','\r','\n'*/
 		return 0;
	}
/*处理申明语句*/
	if(C_TYPE==TYPE_DECLARE){
		return (ProcDeclareStatement()<0)?-igSymPos:0;
	}

	ReportExprError(C_ORIPOS,"语义错误->应为';',但遇到了%s",C_SVALUE);
	return -igSymPos;
}
int GetSymParamCnt(int iSymbolPos,int iSymbolCnt)
{
	int iCnt=0,i,j=0;

	for(i=iSymbolPos;i<iSymbolCnt;i++){
		if(strcmp(SymbolFlow[i].sValue,"(")==0) j++;
		if(strcmp(SymbolFlow[i].sValue,")")==0) j--;
		if(j==0) break;
		if(j==1&&strcmp(SymbolFlow[i].sValue,",")==0) iCnt++;
	}
	if(j!=0) return -1;
	return iCnt+1;
}
/*处理 <函数语句>,注意不支持无返回值函数*/
int ProcDFunStatement(int iResultAddr)
{	
	char sFunType[256];
	int i,iParamCnt,iParamAddr=-1,j,iAddr2;
	struct ExprFunStruct *pTemp;
	
	if(C_TYPE!=TYPE_DFUN) return -igSymPos;
	
/*处理一般函数*/
	if(SearchRegFunLink(C_SVALUE,&pTemp)==NOTFOUND){
		ReportExprError(C_ORIPOS,"语义错误->函数%s未注册",C_SVALUE);
		return -igSymPos;
	}

	igSymPos++;/*跳过函数本身*/
		
	iParamCnt=strlen(pTemp->sParamConstraint);
	/*如果是可变参数，则从符号表中获取函数调用时实际的参数个数*/
	if(strcmp(pTemp->sParamConstraint,"#")==0)
		iParamCnt=GetSymParamCnt(igSymPos,igSymCnt);

	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"语义错误->函数%s后应为(,但遇到了%s",C_SVALUE);
		return igSymPos;
	}
		
	igSymPos++;/*跳过'('号*/

/*参数类型约束*/
	iAddr2=		GetVarOffset(NULL);
	CHECKVAROFFSET(iAddr2);
	CODE_VARBUF[iAddr2].cType=VARTYPE_STR;

	sFunType[0]=pTemp->cType;
	strcpy(sFunType+1,pTemp->sParamConstraint);
	AssignStrchar2Varchar(&(CODE_VARBUF[iAddr2].u.sValue),sFunType);
	
	if(iResultAddr==-1){
	/*给返回值分配地址*/
		iResultAddr = GetVarOffset(NULL); 
		CHECKVAROFFSET(iResultAddr);
	}

	/*将调用时的实际参数个数保存在d2.iParam中*/
	CODE_VARBUF[iAddr2].iParam=iParamCnt;
	
	/*逐个分配参数地址并检查,为了保证连续性
		则先分配再生成各个参数的代码*/
	for(i=0;i<iParamCnt;i++){
		iParamAddr=GetVarOffset(NULL);
		CHECKVAROFFSET(iParamAddr);
	}
	i=0;
	while(i<iParamCnt){
		j=iParamAddr-iParamCnt+i+1;
		if(ProcExpr(j)<0){
			return -igSymPos;
		}
/*
		if(CODE_VARBUF[j].cType!=pTemp->sParamConstraint[i]){
			WriteAlertMsg("函数%s的第%d个参数类型不匹配%c->%c",
				CODE_VARBUF[j].cType,
				pTemp->sParamConstraint[i]);
			return -igSymPos;
		}
*/	
		i++;
		if(i==iParamCnt) break;
			
		if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=','){
			ReportExprError(C_ORIPOS,
				"语义错误->函数%s参数间应为',',但遇到了%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		}
		igSymPos++;/*跳过','号*/
	}
	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"语义错误->函数%s参数结束应为')',但遇到了%s",
				pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*跳过')'号*/
	
	/*写出返回值的类型*/
	CODE_VARBUF[iResultAddr].cType=pTemp->cType;
	
	iParamAddr=iParamAddr-iParamCnt+1;
	
	GEN(DFUN,iParamAddr,iAddr2,iResultAddr,pTemp->FUNCTION);

	return iResultAddr;
}
/*处理 <静态函数语句>,注意不支持无返回值函数*/
int ProcSFunStatement(int iResultAddr)
{
	char sFunType[256];
	int i,iParamCnt,iParamAddr=-1,j,k,iAddr2;

	struct ExprFunStruct *pTemp;

	if(C_TYPE!=TYPE_SFUN) return -igSymPos;

	if(SearchRegFunLink(C_SVALUE,&pTemp)==NOTFOUND){
		ReportExprError(C_ORIPOS,"语义错误->函数%s未注册",C_SVALUE);
		return -igSymPos;
	}
		
	igSymPos++;/*跳过函数本身*/

	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"语义错误->函数%s后应为(,但遇到了%s",C_SVALUE);
		return igSymPos;
	}
		
	igSymPos++;/*跳过'('号*/

	iParamCnt=strlen(pTemp->sParamConstraint);

/*参数类型约束*/
	iAddr2=		GetVarOffset(NULL);
	CHECKVAROFFSET(iAddr2);
	CODE_VARBUF[iAddr2].cType=VARTYPE_STR;
	
/*	CODE_VARBUF[iAddr2].u.sValue[0]=pTemp->cType;
	strcpy(CODE_VARBUF[iAddr2].u.sValue+1,pTemp->sParamConstraint);
*/
	sFunType[0]=pTemp->cType;
	strcpy(sFunType+1,pTemp->sParamConstraint);
	AssignStrchar2Varchar(&(CODE_VARBUF[iAddr2].u.sValue),sFunType);


	if(iResultAddr==-1){
	/*给返回值分配地址*/
		iResultAddr = GetVarOffset(NULL); 
		CHECKVAROFFSET(iResultAddr);
	}
	
	/*逐个分配参数地址并检查,为了保证连续性
		则先分配再生成各个参数的代码*/
	for(i=0;i<iParamCnt;i++){
		iParamAddr=GetVarOffset(NULL);
		CHECKVAROFFSET(iParamAddr);
	}
	i=0;

	while(i<iParamCnt){
		j=iParamAddr-iParamCnt+i+1;

		switch(C_TYPE){
		case TYPE_CONST:
		case TYPE_CONST_HEX:
		case TYPE_CONST_BIN:
		case TYPE_CONST_DEC:
		case TYPE_CONST_STR:
		case TYPE_CONST_DOUBLE:
			if(InitConstVar(C_TYPE,j,C_SVALUE)<0)
				return -igSymPos;
			igSymPos++;/*如果是手动设置变量，则跳过变量*/
		break;
		case TYPE_SFUN:
			if(ProcSFunStatement(j)<0) return -igSymPos;
		break;
		case TYPE_SYSVAR:
			/*将系统变量的参数导过来*/
			k=GetVarOffset(C_SVALUE);
			CHECKVAROFFSET(k);
			CODE_VARBUF[j].iParam=CODE_VARBUF[k].iParam;
			igSymPos++;/*如果是手动设置变量，则跳过变量*/
		break;
		default:
		ReportExprError(C_ORIPOS,
		"语义错误->常量函数%s,参数须为系统变量、常数或常量函数但为%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		break;
		}
		
		i++;
		if(i==iParamCnt) break;
			
		if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=','){
			ReportExprError(C_ORIPOS,
			"语义错误->常量函数%s参数间应为',',但遇到了%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		}
		igSymPos++;/*跳过','号*/
	}

	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"语义错误->函数%s参数结束应为')',但遇到了%s",
				pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*跳过')'号*/

	iParamAddr=iParamAddr-iParamCnt+1;

	/*直接调用静态函数，将数据整到结果地址中*/
	if(pTemp->FUNCTION(iParamAddr,iResultAddr)<0){
			
		ReportExprError(C_ORIPOS,
			"语义错误->调用静态函数%s失败",pTemp->sName);
		return -igSymPos;
	}
	/*生成一个常量函数空操作码，便于DisplayCode*/
	GEN(SFUN,iParamAddr,iAddr2,iResultAddr,pTemp->FUNCTION);

	return iResultAddr;
}
/*处理 <赋值语句>*/
int ProcAssignStatement()
{
	int iResultAddr;

	if(C_TYPE!=TYPE_MODALITY_PARA){
		iResultAddr=GetVarOffset(C_SVALUE); /*取得被赋值变量的偏移地址*/
		CHECKVAROFFSET(iResultAddr);
	}
	else
		iResultAddr=atoi(C_SVALUE)+MAXVAR_COUNT;

	igSymPos++;/*读入被赋值变量*/
	if(C_TYPE!=TYPE_ASSIGN){

		ReportExprError(C_ORIPOS,
			"语义错误->赋值应为=但遇到了%s,",C_SVALUE);

		return -igSymPos;
	}
	igSymPos++; /*读入赋值号*/

	if(ProcExpr(iResultAddr)<0) return -igSymPos;

	if(C_TYPE==TYPE_SEPARATOR && C_CVALUE==';')
		igSymPos++;            /*读入 ;*/
	else{
		ReportExprError(C_ORIPOS,
			"语义错误->赋值语句结束应为';',但遇到了%s,",C_SVALUE);
		return -igSymPos;
	}
	return 0;	

}

/*处理 <条件语句>*/
/*	记录if语句的一个基本地址
	true	不记录地址偏移
	false	记录地址偏移
	先强制生成一个为假的跳转四元式(跳转地址不明)，处理完if为true后的语句块后，将跳转地址更改
*/
int ProcConditionStatement()
{
	int iCondResultAddr;
	int iCodeAddr1,iCodeAddr2;

	igSymPos++;     /*跳过 if读入 '('*/
	iCondResultAddr = GetVarOffset(NULL);
	CHECKVAROFFSET(iCondResultAddr);

	if( ( C_TYPE ==TYPE_MATH) && (C_CVALUE=='(') )
	     igSymPos++;     /*读入 '('*/
	else{
		ReportExprError(C_ORIPOS,
			"语义错误->条件语句开始应为'(',但遇到了%s,",C_SVALUE);
		return -igSymPos;
	}	     

	/* 处理条件表达式 处理结果偏移放入 iCondResultAddr*/
	if(ProcExpr(iCondResultAddr)<0)
		return -igSymPos;
	if(C_TYPE==TYPE_MATH && C_CVALUE==')')
		igSymPos++;      /*读入 ')')*/
	else{
		ReportExprError(C_ORIPOS,
			"语义错误->条件语句结束应为')',但遇到了%s,",C_SVALUE);
		return -igSymPos;
	}
	/*生成 '如果iCondResultAddr,对应的数据段数值假则跳转' 语句,
		目的地址为生成下一个语句块后的代码流指针*/
	GEN(JMPF,iCondResultAddr,-1,-1,NULL);
	iCodeAddr1 = igCodePos-1;/*记住当前JMPF的代码地址*/
	/*   */

	if(ProcStatementBlock()<0)
		return -igSymPos;

	if( C_TYPE==TYPE_CONTROL &&  strcmp( C_SVALUE, "else")==0 ){

		/* 生成 '无条件跳转' 语句, 目的地址为生成下一个语句块(else块)后的代码流指针*/
		GEN(JMP,-1,-1,-1,NULL);
		iCodeAddr2 = igCodePos-1;/*记住当前JMP的代码地址*/
		/* */

		/*填写 前'如果iCondResultAddr假则跳转' 的目的地址*/
		SetJmpAddr(iCodeAddr1,igCodePos);/*这里的iCodeAddr1指的是if后面的最后一条逻辑表达示代码地址*/
		/* igCodePos指的是else代码后面的代码地址*/
		igSymPos++;/*读入 'else'*/
		if(ProcStatementBlock()<0)
			return -igSymPos;
		/*填写 前'无条件跳转' 语句的目的地址*/
		SetJmpAddr(iCodeAddr2,igCodePos);
	}
	else{
		/*填写 前'如果iCondResultAddr假则跳转' 的目的地址*/
		SetJmpAddr(iCodeAddr1,igCodePos);
	}
	return 0;
}

/*处理 <当型循环语句>*/
int ProcWhileStatement()
{
	int iVarOffset;
	int iCodeAddr1,iCodeAddr2,iCodeAddrContinue,iCodeAddrBreak;

	igSymPos++; /*读入 "while"*/

	/*分配临时中间变量*/
        iVarOffset=GetVarOffset(NULL);
	CHECKVAROFFSET(iVarOffset);

	if(C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"语义错误->while语句开始应为'(',但遇到了%s,",C_SVALUE);
		return -igSymPos;
	}

	igSymPos++;     /*读入 '('*/     

	iCodeAddrContinue = igCodePos;/*记住当前CONTINUE的代码地址*/


	if(ProcExpr(iVarOffset)<0)	return -igSymPos;

	if(C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"语义错误->while语句结束应为')',但遇到了%s,",C_SVALUE);
		return -igSymPos;
	}
	
	igSymPos++;      /*读入 ')')*/

	/*生成 '如果iVarOffset假则跳转' 语句,目的地址为WHILE语句结束
		目前它的地址暂时填-1*/
	GEN(JMPF,iVarOffset,-1,-1,NULL);
	iCodeAddr1 = igCodePos-1;/*记住当前JMPF的代码地址,给WHILE失败用*/

	/*生成 '如果iVarOffset真则跳转' 语句,目的地址为WHILE循环体
		目前它的地址暂时填-1*/
	GEN(JMP,-1,-1,-1,NULL);
	iCodeAddr2 = igCodePos-1;/*记住当前跳转到循环体的地址*/

	/*生成 '如果iVarOffset真则跳转' 语句,目的地址为WHILE语句结束
		目前它的地址暂时填-1*/
	GEN(JMP,-1,-1,-1,NULL);
	iCodeAddrBreak = igCodePos-1;/*记住当前跳转到循环体结束的绝对跳转代码给BREAK用*/

	/*填写 前'如果iVarOffset真则跳转' 的目的地址*/
	SetJmpAddr(iCodeAddr2,igCodePos);

/*将WHILE的CONTINUE及BREAK传递给全局变量，给控制语句用*/
	ContinueStack[WhileLevel]=iCodeAddrContinue;
	BreakStack[WhileLevel]=iCodeAddrBreak;
/*WHILE升级*/
	WhileLevel ++;

	if(ProcStatementBlock()<0){
		return -igSymPos;
	}
	GEN(JMP,-1,-1,iCodeAddrContinue,NULL); /*生成CONTINUE代码*/

/*修改while的假跳转及break绝对跳转的目的地址为，循环体结束*/
	SetJmpAddr(iCodeAddr1,igCodePos);
	SetJmpAddr(iCodeAddrBreak,igCodePos);
/*WHILE降级*/
	WhileLevel--;

	return 0;
}


int ProcControlStatement()
{

	if(C_TYPE!=TYPE_CONTROL){
		ReportExprError(C_ORIPOS,
			"语义错误->控制语句开始类型错误");
		return -igSymPos;
	}

	if(strcmp(C_SVALUE,"return")==0){

		int iVarOffset=-1;

		/*读如return 		*/
		igSymPos ++;

		if(C_CVALUE!=';'){	
		        iVarOffset=GetVarOffset(NULL);
			CHECKVAROFFSET(iVarOffset);

			if(ProcExpr(iVarOffset)<0)	return -igSymPos;
		}

		if(C_CVALUE!=';'){
			ReportExprError(C_ORIPOS,
			"语义错误->return语句结束应为';',但遇到了%s,",C_SVALUE);
			return -igSymPos;
		}
		
		if(CURR_FUNP!=NULL){ /*在某个函数中的return*/
			
			if(iVarOffset!=-1){/*如果有返回值则生成一个赋值语句*/
				GEN('=',iVarOffset,-1,CURR_FUNP->iParamCnt+
					MAXVAR_COUNT,NULL);
			}
			/*生成一个POP指令,POP到IP去，形成跳转*/
			GEN(OPSP,P_OP_POP,ADDR_REGISTER,REGISTER_IP,NULL);
			return 0;
		}
		/*直接生成结束代码	*/
		GEN(RET,iVarOffset,-1,-1,NULL);

		return 0;
	}

	if(strcmp(C_SVALUE,"continue")!=0 && strcmp(C_SVALUE,"break")!=0 ){

		ReportExprError(C_ORIPOS,
			"语义错误->非法控制语句%s,",C_SVALUE);
		return -igSymPos;
	}

	if(WhileLevel<=0){
		ReportExprError(C_ORIPOS,
			"语义错误->%s语句;必须在while循环内,",C_SVALUE);
		return -igSymPos;
	}

	if(strcmp(C_SVALUE,"continue")==0 ){
		GEN(JMP,-1,-1,ContinueStack[WhileLevel-1],NULL);
	}
	else
		GEN(JMP,-1,-1,BreakStack[WhileLevel-1],NULL);

	/*读如控制语句*/
	igSymPos ++;
	
	if(C_CVALUE!=';'){
		ReportExprError(C_ORIPOS,
			"语义错误->控制语句结束应为';',但遇到了%s,",C_SVALUE);
		return -igSymPos;
	}		
	/*读入分号*/	
	igSymPos ++;

	return 0;

}
void SetVarValue(int d,int iValue)
{
	CODE_VARBUF[d].cType=VARTYPE_INT;
	CODE_VARBUF[d].u.iValue=iValue;
}
int ProcExprStack(int *pvp,int VarAddrStack[],
	int *psp,struct SymbolStruct SymStack[])
{
	int d1,d2,r,td;
	
	if((*pvp)<=0) return -igSymPos;
	if((*psp)<=0) return -igSymPos;

	/*先取出一个变量*/
	td=VarAddrStack[(*pvp)--];

	switch(SymStack[*psp].iType){
	case TYPE_LOG1: /*逻辑非等逻辑单目运算,
		 !x 或者　~x,则直接将栈顶变为d1*/
		d1=td;
		d2=-1;
	break;
	case TYPE_MATH1:/*算术单目运算, 
		-5 或者　+10等,则构造一个d1,并将栈顶变为d2*/
		d1= GetVarOffset(NULL);
		CHECKVAROFFSET(d1);
		/*根据操作数，构造一个整数0或浮点0*/
		if(CODE_VARBUF[td].cType==VARTYPE_INT){
			CODE_VARBUF[d1].cType=VARTYPE_INT;
			CODE_VARBUF[d1].u.iValue=0;
		}
		else if(CODE_VARBUF[td].cType==VARTYPE_DOUBLE){
			CODE_VARBUF[d1].cType=VARTYPE_DOUBLE;
			CODE_VARBUF[d1].u.dValue=0;
		}
		else{/*这里语法检测会出现编译错误*/
			CODE_VARBUF[d1].cType=VARTYPE_UNK;
			CODE_VARBUF[d1].u.sValue=NULL;
		}
		d2=td;
	break;
	default:/*其他双目运算运算,
		4-9,则栈顶是d2,并再取一个栈顶作为d1*/
		d2=td;
		if((*pvp)<=0) return -igSymPos;	
		/*再取出第一个变量*/
		d1=VarAddrStack[(*pvp)--];
	break;
	}
	
	r = GetVarOffset(NULL);
	CHECKVAROFFSET(r);
	GEN(SymStack[(*psp)--].sValue[0],d1,d2,r,NULL);

	/*将结果地址入栈*/
	VarAddrStack[++(*pvp)] = r;	
	return 0;
}
int InitConstVar(char type,int i,char sSymbolVal[])
{
	char	sTemp[256];
	switch(type){
	case TYPE_CONST:
		/*这里可以不加iParam和LoadViant变量*/
		(*LoadConst)(sSymbolVal,&(CODE_VARBUF[i].cType),
			 	(void*)&(CODE_VARBUF[i].u));
	break;
	case TYPE_CONST_HEX:
		CODE_VARBUF[i].cType=VARTYPE_INT;
		CODE_VARBUF[i].u.iValue=HexStrToInt(sSymbolVal+2);
	break;
	case TYPE_CONST_BIN:
		CODE_VARBUF[i].cType=VARTYPE_INT;
		CODE_VARBUF[i].u.iValue=BinStrToInt(sSymbolVal+2);
	break;
	case TYPE_CONST_DEC:
		CODE_VARBUF[i].cType=VARTYPE_INT;
		CODE_VARBUF[i].u.iValue=atoi(sSymbolVal);
	break;
	case TYPE_CONST_STR:
		CODE_VARBUF[i].cType=VARTYPE_STR;
		if(strlen(sSymbolVal)-2<0) return -igSymPos;
		
		strncpy(sTemp,sSymbolVal+1,strlen(sSymbolVal)-2);
		sTemp[strlen(sSymbolVal)-2]=0;
		AssignStrchar2Varchar(&(CODE_VARBUF[i].u.sValue),sTemp);
	break;
	case TYPE_CONST_DOUBLE:
		CODE_VARBUF[i].cType=VARTYPE_DOUBLE;
		CODE_VARBUF[i].u.dValue=atof(sSymbolVal);
	break;
	default:
		ReportExprError(C_ORIPOS,"语义错误->%s必须是常量",C_SVALUE);
		return -igSymPos;
	}
	return 0;
}
/*处理 <表达式> */
int ProcExpr(int iResultAddr)
{
	int    i,iEndFlag,iSymPos1,iConstFunFlag=false;
/*运算符栈和数据栈的栈顶指针,栈空时为零,加一后进栈出栈后减一*/
	int vp,sp;
	int VarAddrStack[1000];
	struct SymbolStruct SymStack[200];

	vp=sp=0;
	iEndFlag=0;
	
	if(C_TYPE==TYPE_SFUN) iConstFunFlag=true;

	iSymPos1=igSymPos;

/*	系统变量，临时变量，常量 存放在CodeFlow中的sValue
	其它存放在CodeFlow中的cValue，包括分隔字符，控制字符和条件表达式字符
*/

	while(!iEndFlag){
		switch(C_TYPE){
		case TYPE_SYSVAR:
		case TYPE_TEMPVAR:
			i = GetVarOffset(C_SVALUE);
			CHECKVAROFFSET(i);
			VarAddrStack[++vp] = i;
		break;
		case TYPE_MODALITY_PARA:/*对形参赋值，通常将类型信息也加入*/
			/*形参类型通常在ProcFunStatement中检测，其他不检测*/
			i=atoi(C_SVALUE)+MAXVAR_COUNT;
			VarAddrStack[++vp] = i;
		break;
		case TYPE_CONST:
		case TYPE_CONST_HEX:
		case TYPE_CONST_BIN:
		case TYPE_CONST_DEC:
		case TYPE_CONST_STR:
		case TYPE_CONST_DOUBLE:
			i = GetVarOffset(NULL);
			CHECKVAROFFSET(i);
			if(InitConstVar(C_TYPE,i,C_SVALUE)<0)return -igSymPos;
        	
			VarAddrStack[++vp] = i;
		break;
		case TYPE_SFUN:
		case TYPE_DFUN:
		case TYPE_FUN:
			i = GetVarOffset(NULL);
			CHECKVAROFFSET(i);
			/*在该函数的内部已经给出了返回数值类型*/
			if(C_TYPE==TYPE_SFUN){
				if(ProcSFunStatement(i)<0) return -igSymPos;
			}
			else if(C_TYPE==TYPE_DFUN){
				if(ProcDFunStatement(i)<0) return -igSymPos;
			}
			else{
				if(ProcFunStatement(i)<0) return -igSymPos;
			}
			VarAddrStack[++vp] = i;
/*由于这里函数内部已经指向下一个符号所以需要用continue*/
		continue;
		case TYPE_LOG2:
		case TYPE_LOG1:
		case TYPE_MATH1:
		case TYPE_MATH:
			switch(C_CVALUE){
			case '(':
				SymStack[++sp].iType=C_TYPE;
				strcpy(SymStack[sp].sValue,C_SVALUE);
				break;
			case ')':/*遇到)则回溯到(,并将中间的过程意义生成代码*/
				while(sp>0&&SymStack[sp].sValue[0]!='(')
					if(ProcExprStack(&vp,VarAddrStack,
					&sp,SymStack)<0) return -igSymPos;
				
				/*遇到 '('退出,'(' 已匹配,出栈*/
				if(sp>0) sp--;
				else	iEndFlag=1;  /* ')' 无 '('匹配,结束*/
			break;
			default:
				while(sp>0&&GetSymPri(
			SymStack[sp].sValue[0])>=GetSymPri(C_CVALUE))
					if(ProcExprStack(&vp,VarAddrStack,
					&sp,SymStack)<0) return -igSymPos;
				/*符号进符号栈*/
				SymStack[++sp].iType=C_TYPE;
				strcpy(SymStack[sp].sValue,C_SVALUE);
				break;
			}/*end switch(C_CVALUE*/
		break;
		default:
			if(C_TYPE==TYPE_SEPARATOR&&(C_CVALUE==';'||C_CVALUE==','))
				iEndFlag=1;
			else{
				ReportExprError(C_ORIPOS,
					"语法错误->遇到非法字符%s,是否是',',';',')'",
					C_SVALUE);
				return -igSymPos;
			}
		}/*end switch(C_TYPE*/
        	
		if(iEndFlag){
			while(sp>0&&SymStack[sp].sValue[0]!='(')
				if(ProcExprStack(&vp,VarAddrStack,
					&sp,SymStack)<0) return -igSymPos;
			break;
		}
		if(igSymPos>=igSymCnt) return -igSymPos;

		/*获取下一个符号*/
		igSymPos++;
	}/*end while(!iEndFlag*/

	/*将最后一条指令的输出地址改为iResultAddr*/
	if( (vp!=1) || (sp !=0) ){
		ReportExprError(C_ORIPOS,"语法错误->表达式错误");
		return -igSymPos;
	}
	/*如果表达式　就一个项或N个项组成的常量函数，
			或最后一个非算术操作;
		则生成赋值代码将这个项的值赋给结果值地址,
	否则，则将表达式的最后一个中间结果的输出地址直接修改为结果地址*/

	if((igSymPos-iSymPos1)==1||iConstFunFlag==true||
		strchr("+-*/^%12345678|&!=",CODE_FLOW[igCodePos-1].op)==NULL){
		GEN('=',VarAddrStack[vp--],-1,iResultAddr,NULL);
	}
	else	ModifyResultAddr(igCodePos-1,iResultAddr);

/*	直接修改地址不安全，生成赋值语句兼容性好
	GEN('=',VarAddrStack[vp--],-1,iResultAddr,NULL);*/

	return 0;
}

int ReportSysVarModify(char cOp,int iResultAddr)
{
	int i,j,k=iResultAddr,iOutputLen;
	
	if((cOp!=JMP)&&(cOp!=JMPF)&&(k< SYSVAR_COUNT)&&(k>=0)){
		
		iOutputLen = CURR_EXPR.iOutputLen;
		for(i=0;i<iOutputLen;i++){
			if( CURR_EXPR.OutputBuf[i].iOffset==k )
				break;
		}
		
		if(i >=SYSVAR_COUNT ) return -1;
		
		if(i >= iOutputLen){
			
			j=CURR_EXPR.iOutputLen;
			
			strcpy(CODE_OUTBUF[j].sSymbol,CODE_SYSBUF[k].sSymbol);
			CODE_OUTBUF[j].iOffset = k ;
			CODE_OUTBUF[j].cType=	CODE_VARBUF[k].cType;
			CODE_OUTBUF[j].u.iValue=0;
			CODE_OUTBUF[j].iParam =CODE_VARBUF[k].iParam;
			CODE_OUTBUF[j].SaveVariant=CODE_SYSBUF[k].SaveVariant;
			
			CURR_EXPR.iOutputLen++;			
		}
	}
	return 0;
}
/*	四元组 
	生成代码，输入参数依次为：操作符、操作数1、操作数2、目的操作数；操作数为-1表示该操作数无作用*/
int Gen(char cOp,int iData1,int iData2,int iResultAddr,
	int (*Oper)(int d1,int r))
{
	
	CODE_FLOW[igCodePos].Oper=Oper;
	CODE_FLOW[igCodePos].op = cOp;
	CODE_FLOW[igCodePos].data1 = iData1;
	CODE_FLOW[igCodePos].data2 = iData2;
	CODE_FLOW[igCodePos].result = iResultAddr;
	CODE_FLOW[igCodePos].iSymPos = igSymPos;
    /*如果目的地址为系统变量,增加系统输出项*/
	
	if(ReportSysVarModify(cOp,iResultAddr)<0){
		ReportExprError(C_ORIPOS,"语法错误->系统变量太多，超过%d",
			SYSVAR_COUNT);
		return -1;
	}

	igCodePos++;
	if(igCodePos>=CODE_BUFLEN){
		ReportExprError(C_ORIPOS,"语法错误->代码长度超过%d",
			CODE_BUFLEN);
		return -1;
	}
	return 0;
}

/* 修改iPos四元式的结果地址偏移 */
void ModifyResultAddr(int iPos,int iResultAddr)
{
	CODE_FLOW[iPos].result = iResultAddr;	
	ReportSysVarModify(CODE_FLOW[iPos].op,iResultAddr);
}
void SetJmpAddr(int iJmpCodeAddr,int iJmpTargetAddr)
{
	CODE_FLOW[iJmpCodeAddr].result = iJmpTargetAddr;
}
/* 取得操作符对应的优先级 */
int GetSymPri(char cOp)
{
	int i;
	struct {
		char op;
		int  pri;
	}asOpPri[19]={	{'(',0},{'|',1},{'&',2},
			{'1',3},{'2',3},{'3',3},{'4',3},{'5',3},{'6',3},
			{'=',4},{'!',5},{'+',6},{'-',6},{'7',6},{'8',6},
			{'*',7},{'/',7},{'%',7},{'^',8}   };
	for(i=0;i<19;i++)
		if(asOpPri[i].op == cOp)
			return asOpPri[i].pri;
	return 0;
}

int data_search_expr_bin_e(void *pValue,void*pData)
{
	struct ExprBinStruct *pSource=(struct ExprBinStruct *)pValue;
 	struct ExprBinStruct *pTarget=(struct ExprBinStruct *)pData;

	return strcmp(pSource->sName,pTarget->sName);
}
/*编译公式时使用，不考虑效率
	sVar = NULL 新增一个临时系统变量，返回其在VarBuf中的偏移 
	sVar != NULL 查找公式数据块中是否存在sVar
		不存在则新增 
		存在就返回在数组中的偏移(即位置)*/
int GetVarOffset(char * sVar)
{
	char *p;
	int i,iType,iTmpVarCnt,iSysVarCnt,iSysTmpCnt;
	struct ExprBufStruct	*pText;
	struct VariantStruct	*pDataSeg;
	struct SymVarStruct	*pSysSeg;
	struct ExprBinStruct *pTemp;

	pText=		&(CURR_EXPR);
	pDataSeg=	pText->VarBuf;
	pSysSeg=	pText->SysBuf;
	iTmpVarCnt=	pText->iTmpVarCnt;
	iSysVarCnt=	pText->iSysVarCnt;
	iSysTmpCnt=	pText->iSysTmpCnt;

	if(iTmpVarCnt>=(MAXVAR_COUNT-SYSVAR_COUNT)||
		iSysVarCnt>=SYSVAR_COUNT||
		iSysTmpCnt>=SYSVAR_COUNT*2){
		if(iSysVarCnt>=SYSVAR_COUNT)
			ReportExprError(C_ORIPOS,"语法错误->系统变量太多，超过%d",
				SYSVAR_COUNT);
		else if(iSysTmpCnt>=SYSVAR_COUNT*2)
			ReportExprError(C_ORIPOS,"语法错误->准系统变量太多，超过%d",
				SYSVAR_COUNT*2);
		else
			ReportExprError(C_ORIPOS,"语法错误->临时变量太多，超过%d",
				(MAXVAR_COUNT-SYSVAR_COUNT));
		return -1;
	}

	if(sVar==NULL){

		pDataSeg[iTmpVarCnt].cType=VARTYPE_UNK;	
		pDataSeg[iTmpVarCnt].iParam=0;
		pDataSeg[iTmpVarCnt].iIndex=-1;
		pDataSeg[iTmpVarCnt].u.sValue=NULL;
		pText->iTmpVarCnt++;
	
		return iTmpVarCnt;
	}
	
	iType = GetSymType(sVar);
	if(iType == TYPE_SYSVAR){
		for(i=0;i<iSysVarCnt;i++)
			if(strcmp(pSysSeg[i].sSymbol,sVar)==0) return i;

		strcpy(pSysSeg[i].sSymbol,sVar);

		LoadVariant=DefLoadVariant;
		SaveVariant=DefSaveVariant;
			/*获得参数及加载变量函数*/
		pSysSeg[i].iParam=CheckSysVar(sVar,&(pDataSeg[i].cType));
		pDataSeg[i].iParam=pSysSeg[i].iParam;
		if(pDataSeg[i].iParam<0){
			
			ReportExprError(C_ORIPOS,"语法错误->变量%s,校验未通过",sVar);
			return -1;
		}
		if(pDataSeg[i].cType==VARTYPE_STR){
			if((p=(char*)MallocVarchar(DEF_STR_LEN+1))==NULL){
               			ReportExprError(C_ORIPOS,
               				"为系统变量%s分配运行内存失败",sVar);
				return -1;
			}
			pDataSeg[i].u.sValue=p;
		}
		pSysSeg[i].iIndex=	i;
		pSysSeg[i].LoadVariant=LoadVariant;
		pSysSeg[i].SaveVariant=SaveVariant;
		
		pDataSeg[i].iIndex=	i;

		pText->iSysVarCnt++;
		
		return iSysVarCnt;
	}

	/**这里只有临时变量了**/	
	for(i=SYSVAR_COUNT;i<iSysTmpCnt;i++)
		if(strcmp(pSysSeg[i].sSymbol,sVar)==0)
			return pSysSeg[i].iIndex;
	
	strcpy(pSysSeg[i].sSymbol,sVar);
	pSysSeg[i].iParam=0;
	pSysSeg[i].LoadVariant = DefLoadVariant;
	pSysSeg[i].SaveVariant = DefSaveVariant;
	
	pSysSeg[i].iIndex=	iTmpVarCnt;

	if((pTemp=malloc(sizeof(struct ExprBinStruct)))==NULL){
                WriteAlertMsg("分配内存给EXPR_TREE失败");
		return -1;
	}
	pTemp->pNext=NULL;
	strcpy(pTemp->sName,sVar);
	pTemp->iVarInd=	iTmpVarCnt;
	pTemp->iSymInd= iSysTmpCnt;

	if(InsertBin(&(pText->pRoot),(void *)pTemp,
		data_search_expr_bin_e,
		assign_insert_bintree)<0){
                WriteAlertMsg("生成BINTREE失败EXPR_TREE");
                return -1;
        }

	pDataSeg[iTmpVarCnt].iParam=0;
	pDataSeg[iTmpVarCnt].cType=VARTYPE_UNK;
	pDataSeg[iTmpVarCnt].u.sValue=NULL;
	pDataSeg[iTmpVarCnt].iIndex=iSysTmpCnt;
	
	pText->iTmpVarCnt++;	
	pText->iSysTmpCnt++;

	return iTmpVarCnt;
}

int NewLine(char c)
{
	if(c=='\n'||c=='\r') return true;
	return false;
}
int JmpSeperator(char c)
{
	if(c==' '||c=='\t') return true;
	return false;
}
int StatementEnd(char c)
{
	if(c==';') return true;
	return false;
}
int WordEnd(char c)
{
	if(c==',') return true;
	return false;
}
int ExprEnd(char c)
{
	if(c==0) return true;
	return false;
}
int CommentCBegin(char c1,char c2)
{
	if(c1=='/'&&c2=='*') return true;
	return false;
}
int CommentCEnd(char c1,char c2)
{
	if(c1=='*'&&c2=='/') return true;
	return false;
}
int LexCComment(char sInput[],int *piPos)
{	
	int i=*piPos;
	
	if(CommentCBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->C注释->未匹配'*/'公式结束");
			return -1;
		}
		while(!CommentCEnd(sInput[i],sInput[i+1])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->C注释->未匹配'*/'公式结束");
				return -1;
			}
		}
		i+=2;
		*piPos=i;
		return true;
	}
	return false;
}
int CommentCppBegin(char c1,char c2)
{
	if(c1=='/'&&c2=='/') return true;
	return false;
}
int LexCppComment(char sInput[],int *piPos)
{
	int i=*piPos;
	
	if(CommentCppBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->Cpp注释->公式结束");
			return -1;
		}
		while(!NewLine(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->Cpp注释->公式结束");
				return -1;
			}
		}
		i++; /*跳过回车*/
		*piPos=i;
		return true;
	}
	return false;
}
int CommentShBegin(char c)
{
	if(c=='#') return true;
	return false;
}
int LexShComment(char sInput[],int *piPos)
{	
	int i=*piPos;
	if(CommentShBegin(sInput[i])){
		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->#注释->公式结束");
			return -1;
		}
		while(!NewLine(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->#注释->公式结束");
				return -1;
			}
		}
		i++; /*跳过回车*/
		*piPos=i;
		return true;
	}
	return false;

}
void RegularConstStr(char sInput[])
{
	int i=0,j=0;
	char sTemp[256];
	
	while(i<strlen(sInput)){

		if(strncmp(sInput+i,"\\\\",2)==0){
			sTemp[j++]= '\\';i+=2;
		}
		else if(strncmp(sInput+i,"\\a",2)==0){
			sTemp[j++]= '\a';i+=2;
		}
		else if(strncmp(sInput+i,"\\b",2)==0){
			sTemp[j++]= '\b';i+=2;
		}
		else if(strncmp(sInput+i,"\\f",2)==0){
			sTemp[j++]= '\f';i+=2;
		}
		else if(strncmp(sInput+i,"\\n",2)==0){
			sTemp[j++]= '\n';i+=2;
		}
		else if(strncmp(sInput+i,"\\r",2)==0){
			sTemp[j++]= '\r';i+=2;
		}
		else if(strncmp(sInput+i,"\\t",2)==0){
			sTemp[j++]= '\t';i+=2;
		}
		else if(strncmp(sInput+i,"\\v",2)==0){
			sTemp[j++]= '\v';i+=2;
		}
		else if(strncmp(sInput+i,"\\\"",2)==0){
			sTemp[j++]= '\"';i+=2;
		}
		else
			sTemp[j++]= sInput[i++];
	}
	sTemp[j]=0;
	strcpy(sInput,sTemp);
}
int ConstStringBegin(char c)
{
	if(c=='"'||c=='\'') return true;
	return false;
}
int ConstStringEnd(char c,char x)
{
	if(c==x) return true;
	return false;
}
int AddSymbolFlow(char sInput[],int iOffset,int iLen,int iType)
{
	int i,j=0;
	char	sTemp[8192];
	
	if(iType==TYPE_CONST_STR){
		for(i=iOffset;i<iOffset+iLen;i++){
			/*unix下和dos下的字符常量内的序行支持*/
			if(strncmp(sInput+i,"\\\n",2)==0){i+=2;continue;}
			if(strncmp(sInput+i,"\\\r\n",3)==0){i+=3;continue;}
			sTemp[j++]=sInput[i];
		}
		sTemp[j]=0;
		if(sInput[iOffset]=='"') RegularConstStr(sTemp);
			
	}
	else{
		strncpy(sTemp,sInput+iOffset,iLen);
		sTemp[iLen]=0;
	}

	strcpy(C_SVALUE,sTemp);
	
	if(iType!=-1)	C_TYPE	=iType;
	else		C_TYPE	=GetSymType(sTemp);

	C_ORIPOS=	EncodingOriPos(iOffset+iLen-1);
	igSymPos++;
	if(igSymPos>=SYMBOL_BUFLEN){
		ReportExprError(iOffset,
			"系统错误->符号变量超过%d个",SYMBOL_BUFLEN);
		return -1;
	}
	return 0;
}
int LexConstString(char sInput[],int *piPos)
{
	int i=*piPos;
	char pin[3];

	if(ConstStringBegin(sInput[i])){

		pin[0]='\\';pin[1]=sInput[i];pin[2]=0;

		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->串常量->公式结束");
			return -1;
		}
		while(!ConstStringEnd(sInput[i],pin[1])){

			/*跳过指定转义字符*/
			if(strncmp(sInput+i,pin,2)==0)i+=2;
			else i++;

			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->串常量->公式结束");
				return -1;
			}
		}
		i++; /*跳过"号*/
		
		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,*piPos,i-(*piPos),TYPE_CONST_STR);
		
		*piPos=i;
		return true;
	}
	return false;
}
int ConstDecNumBegin(char c)
{
	if((c>='0'&&c<='9')||c=='.') return true;
	return false;
}
int ConstDecNumNext(char c)
{
	if(c>='0'&&c<='9') return true;
	return false;
}
int LexConstDecNum(char sInput[],int *piPos)
{
	int i=*piPos;
	
	if(ConstDecNumBegin(sInput[i])){
		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->常整数->公式结束");
			return -1;
		}
		while(ConstDecNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常整数->公式结束");
				return -1;
			}
		}
		
		if(sInput[i]!='.'){
			/*加入符号表*/
			ADDSYMBOLFLOW(sInput,*piPos,i-(*piPos),TYPE_CONST_DEC);
		
			*piPos=i;
			return true;
		}
		/*跳过小数点*/
		i++;
		while(ConstDecNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常整数->公式结束");
				return -1;
			}
		}

		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,*piPos,i-(*piPos),TYPE_CONST_DOUBLE);
		*piPos=i;
		return true;		
	}
	return false;
}

int ConstHexNumBegin(char c1,char c2)
{
	if(c1=='0'&&(c2=='X'||c2=='x')) return true;
	return false;
}
int ConstHexNumNext(char c)
{
	if((c>='0'&&c<='9')||
		(c>='a'&&c<='f')||
		(c>='A'&&c<='F')) return true;
	return false;
}
int LexConstHexNum(char sInput[],int *piPos)
{
	int i=*piPos;
	
	if(ConstHexNumBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->常HEX整数->公式结束");
			return -1;
		}
		while(ConstHexNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常HEX整数->公式结束");
				return -1;
			}			
		}

		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,(*piPos),i-(*piPos),TYPE_CONST_HEX);
		
		*piPos=i;
		return true;
	}
	return false;
}
int ConstBinNumBegin(char c1,char c2)
{
	if(c1=='0'&&(c2=='B'||c2=='b')) return true;
	return false;
}
int ConstBinNumNext(char c)
{
	if(c>='0'&&c<='1') return true;
	return false;
}
int LexConstBinNum(char sInput[],int *piPos)
{
	int i=*piPos;
	
	if(ConstBinNumBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->常BIN整数->公式结束");
			return -1;
		}
		while(ConstBinNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常BIN整数->公式结束");
				return -1;
			}			
		}

		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,(*piPos),i-(*piPos),TYPE_CONST_BIN);
		
		*piPos=i;
		return true;
	}
	return false;
}
int IdentifyBegin(char c)
{
	if(c=='$'||(c>='a' && c<='z')||
		(c>='A' && c<='Z')||(c&0x80)||c=='#') return true;
	return false;
}
int IdentifyNext(char c1,char c2)
{
	/*如果是汉字就不检测下一个字符*/
	if((c1&0x80)&&(c2&0x80)) return true;
	
	if( c2=='_'||c2=='.'||(c2>='a' && c2<='z') || 
		(c2>='A' && c2<='Z') || 
		(c2>='0' && c2<='9') || (c2&0x80) ) return true;
	return false;
}
int LexIdentify(char sInput[],int *piPos)
{
	int i=*piPos;
	char sTemp[256];

	if(IdentifyBegin(sInput[i])){
		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->标识符->公式结束");
			return -1;
		}
		while(IdentifyNext(sInput[i-1],sInput[i])){
			
			/*汉字就跳过一个字符*/
/*			if(sInput[i-1]&0x80){
				i++;
				if(ExprEnd(sInput[i])){
					ReportExprError(i,"词法错误->标识符->公式结束");
					return -1;
				}
			}
*/
			i++;
			
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->标识符->公式结束");
				return -1;
			}		
		}

		strncpy(sTemp,sInput+(*piPos),i-(*piPos));
		sTemp[i-(*piPos)]=0;
		
		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,(*piPos),i-(*piPos),GetSymType(sTemp));
		
		*piPos=i;
		return true;
	}
	return false;
}
int SeperatorBegin(char c)
{
	if(c=='{'||c=='}'||c==':'||
		c==','||c==';'||NewLine(c)) return true;
	return false;
}
int LexSeperator(char sInput[],int *piPos)
{
	int i=*piPos;
	
	if(SeperatorBegin(sInput[i])){
		i++;
		ADDSYMBOLFLOW(sInput,(*piPos),1,TYPE_SEPARATOR);
		*piPos=i;
		return true;
	}
	return false;
}
int MathBegin(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||
		c=='%'||c=='^'||
		c=='('||c==')') return true;
	return false;
}
int GetTypeMath(int iSymPos)
{
	int iType;

	/*回退一格*/
	iSymPos--;
	
	/*去掉前导的换行*/
	while(iSymPos>0){
		if(NewLine(SymbolFlow[iSymPos].sValue[0])==false) break;
		iSymPos--;
	}

	if(iSymPos<=0) return TYPE_MATH1;
		
	iType=SymbolFlow[iSymPos].iType;
	if((iType==TYPE_CONST_HEX) ||
		(iType==TYPE_CONST_BIN) ||
		(iType==TYPE_CONST_DEC) ||
		(iType==TYPE_CONST_STR) ||
		(iType==TYPE_CONST_DOUBLE) ||
		(iType==TYPE_SYSVAR) ||
		(iType==TYPE_TEMPVAR)||(iType==TYPE_MATH&&
			SymbolFlow[iSymPos].sValue[0]==')')) return TYPE_MATH;
	return TYPE_MATH1;
}
int LexMath(char sInput[],int *piPos)
{
	int i=*piPos,iType=0;
	
	if(MathBegin(sInput[i])){
		switch(sInput[i]){
		case '+':
		case '-':
			/*判断是单目运算符（正，负）还是双目运算符（加，减）
		          双目运算符是连结两个运算项的，
		          运算项是一个变量或是由括号括起来的表达式，
		          因此判断是双目运算符只判断前面是否变量或右括号
		         */
			if(igSymPos!=0&&
			    ( (C_TYPEP==TYPE_CONST_HEX) ||
			      (C_TYPEP==TYPE_CONST_BIN) ||
			      (C_TYPEP==TYPE_CONST_DEC) ||
			      (C_TYPEP==TYPE_CONST_STR) ||
			      (C_TYPEP==TYPE_CONST_DOUBLE) ||
			      (C_TYPEP==TYPE_SYSVAR) ||
			      (C_TYPEP==TYPE_TEMPVAR)||
			      (C_TYPEP==TYPE_MATH&&C_CVALUEP==')') 
			    )
			)
				iType=TYPE_MATH;
			else
				iType=GetTypeMath(igSymPos);
		break;
		case '*':
		case '/':
		case '%':
		case '^':
		case '(':
		case ')':
			iType=TYPE_MATH;
		break;
		default:
			return -1;
		}
		i++;
		ADDSYMBOLFLOW(sInput,(*piPos),1,iType);
		*piPos=i;
		return true;
	}
	return false;
}
int LogicalBegin(char c)
{
	if(c=='>'||c=='<'||c=='='||
		c=='!'||c=='|'||c=='&') return true;
	return false;
}
int LexLogical(char sInput[],int *piPos)
{
	int i=*piPos,iType=0;
	char sTemp[2];
	
	if(LogicalBegin(sInput[i])){
		if(strncmp(sInput+i,">=",2)==0){
			strcpy(sTemp,"3");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"<=",2)==0){
			strcpy(sTemp,"4");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"==",2)==0){
			strcpy(sTemp,"5");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"!=",2)==0||
			strncmp(sInput,"<>",2)==0){
			strcpy(sTemp,"6");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,">",1)==0){
			strcpy(sTemp,"1");
			iType=TYPE_LOG2;
			i++;
		}
		else if(strncmp(sInput+i,"<",1)==0){
			strcpy(sTemp,"2");
			iType=TYPE_LOG2;
			i++;
		}
		else if(strncmp(sInput+i,"=",1)==0){
			strcpy(sTemp,"=");
			iType=TYPE_ASSIGN;
			i++;
		}
		else if(strncmp(sInput+i,"!",1)==0){
			strcpy(sTemp,"!");
			iType=TYPE_LOG1;
			i++;
		}
		else if(strncmp(sInput+i,"||",2)==0){
			strcpy(sTemp,"|");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"&&",2)==0){
			strcpy(sTemp,"&");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"|",1)==0){
			strcpy(sTemp,"7");
			iType=TYPE_MATH;
			i++;
		}
		else if(strncmp(sInput+i,"&",1)==0){
			strcpy(sTemp,"8");
			iType=TYPE_MATH;
			i++;
		}
		else
			return false;
		
		ADDSYMBOLFLOW(sTemp,0,1,iType);
		*piPos=i;
		/*由于需要修改ori_pos*/
		SymbolFlow[igSymPos-1].iOriPos= i-1;
		
		return true;
	}
	return false;
}
/*词法分析,生成具有独立含义的符号流 SymbolFlow*/
int Lexicalize(char sInput[])
{
	int i=0,iRet,iInputLen;
	
	iInputLen=strlen(sInput);
	
	igSymPos=0;
	while(i<iInputLen){
		
		while(JmpSeperator(sInput[i])&&!ExprEnd(sInput[i])) i++;

		if(ExprEnd(sInput[i])) break;
	
/*续行处理，一般是用于宏定义*/
		if(strncmp(sInput+i,"\\\n",2)==0){i+=2;continue;}
		if(strncmp(sInput+i,"\\\r\n",3)==0){i+=3;continue;}
/*处理C语言注释*/
		if((iRet=LexCComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理C++注释*/
		if((iRet=LexCppComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;

/*处理Sh注释	if((iRet=LexShComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;
*/
/*处理常量字符串*/
		if((iRet=LexConstString(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理常量十六进制数*/
		if((iRet=LexConstHexNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理常量二进制数*/
		if((iRet=LexConstBinNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理常量十进制数*/
		if((iRet=LexConstDecNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理标识符*/
		if((iRet=LexIdentify(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理分割符*/
		if((iRet=LexSeperator(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理"+,-,*,/"算术符号*/
		if((iRet=LexMath(sInput,&i))<0) return -1;
		if(iRet==true) continue;
		
/*处理">,<,=,!,|,&"逻辑符号*/
		if((iRet=LexLogical(sInput,&i))<0) return -1;
		if(iRet==true) continue;
		return -i-1;
	} /*end while(i*/
	igSymCnt=igSymPos;
	return 0;
}
void AddReserveSymbol(char sSymbol[],int iType)
{
	strcpy(ReserveSymbol[igReserveCount].sSymbol,sSymbol);
	ReserveSymbol[igReserveCount++].iType = iType;
}
void InitReserveSymbol()
{
	igReserveCount = 0;
	
	CURR_EXPR.iSysVarCnt = 0;
	CURR_EXPR.iTmpVarCnt = SYSVAR_COUNT;

	AddReserveSymbol("if",		TYPE_CONTROL);
	AddReserveSymbol("else",	TYPE_CONTROL);
	AddReserveSymbol("while",	TYPE_CONTROL);
	AddReserveSymbol("continue",	TYPE_CONTROL);
	AddReserveSymbol("break",	TYPE_CONTROL);
	AddReserveSymbol("return",	TYPE_CONTROL);
	AddReserveSymbol("goto",	TYPE_CONTROL);

	AddReserveSymbol("null",	TYPE_CONST);

	AddReserveSymbol("int",		TYPE_DECLARE);
	AddReserveSymbol("string",	TYPE_DECLARE);
	AddReserveSymbol("double",	TYPE_DECLARE);
	AddReserveSymbol("pointer",	TYPE_DECLARE);
	AddReserveSymbol("struct",	TYPE_DECLARE);
	
	AddReserveSymbol("#ifdef",	TYPE_PRECOMP_CONTROL);
	AddReserveSymbol("#ifndef",	TYPE_PRECOMP_CONTROL);
	AddReserveSymbol("#define",	TYPE_PRECOMP_CONTROL);
	AddReserveSymbol("#include",	TYPE_PRECOMP_CONTROL);
	AddReserveSymbol("#else",	TYPE_PRECOMP_CONTROL);
	AddReserveSymbol("#endif",	TYPE_PRECOMP_CONTROL);
}

/*	取得sSymbol的类型 
	系统变量	TYPE_SYSVAR
	临时变量	TYPE_TEMPVAR
	常量		TYPE_CONST
	控制符号	TYPE_CONTROL
*/
int GetSymType(char sSymbol[])
{
	int i;
	struct ExprVarStruct *pTemp;
	struct ExprFunStruct *pFun;
	
	for(i=0;i<igReserveCount;i++)
		if(strcmp(ReserveSymbol[i].sSymbol,sSymbol)==0)
			return ReserveSymbol[i].iType;
/*检查系统变量注册链表*/
	if(SearchRegVarLink(sSymbol,&pTemp)==FOUND)  return TYPE_SYSVAR;
/*检查内置函数注册链表*/
	if(SearchRegFunLink(sSymbol,&pFun)==FOUND){
		if(pFun->cFunctionType==DFUN)return TYPE_DFUN;
		return TYPE_SFUN;
	}
/*自定义字段变量*/
/*	if(strncmp(sSymbol,"it_",3)==0||
		strncmp(sSymbol,"pt_",3)==0||
		strncmp(sSymbol,"st_",3)==0) return  TYPE_SYSVAR;
*/
/*特殊规定：美圆则为变量*/
	if(sSymbol[0]=='$') return TYPE_TEMPVAR;
	
/*特殊处理：如果汉字则处理为常量*/
	if(sSymbol[0]&0x80) return TYPE_CONST;
	
	return TYPE_TEMPVAR;
}



int OutputCompileError(char sInput[])
{
	int i,iPos,iErrPos,iLastNewLine;
					
	printf("公式编译失败!\n");
	
	if(igSymPos>=igSymCnt)
		iErrPos = SymbolFlow[igSymCnt-1].iOriPos+1;
	else
		iErrPos = SymbolFlow[igSymPos].iOriPos;
			
	for(i=0;i<=iErrPos;i++){
		printf("%c",sInput[i]);
		if(sInput[i] =='\n') iLastNewLine = i;
	}
	printf("\n");

	for(iPos=0;iPos<i-iLastNewLine-2 ;iPos++)
		printf("%c",' ');
	printf("%c\n",'*');
	return 0;
}

int SearchExprBin(struct ExprBufStruct *p,char sName[],struct ExprBinStruct **pptCur)
{
	struct ExprBinStruct Temp;

	strcpy(Temp.sName,sName);

	return SearchBin(p->pRoot,(void*)&Temp,
		data_search_expr_bin_e,(void*)pptCur);
		
}
void get_int_value(char sName[],struct ExprBufStruct *p,int *piValue)
{
	struct	ExprBinStruct *pTemp=NULL;
	struct	VariantStruct *pVar;
	struct	SymVarStruct *pSys;

	*piValue=-1;

	if(SearchExprBin(p,sName,&pTemp)==NOTFOUND) return;
	pVar=	&(p->VarBuf[pTemp->iVarInd]);
	pSys=	&(p->SysBuf[pTemp->iSymInd]);
	
	if(pSys->cModified!=2) return;
	*piValue=	pVar->u.iValue;
}
void get_str_value(char sName[],struct ExprBufStruct *p,char sValue[])
{
	struct	ExprBinStruct *pTemp=NULL;
	struct	VariantStruct *pVar;
	struct	SymVarStruct *pSys;

	strcpy(sValue,"");
	if(SearchExprBin(p,sName,&pTemp)==NOTFOUND) return;
	pVar=	&(p->VarBuf[pTemp->iVarInd]);
	pSys=	&(p->SysBuf[pTemp->iSymInd]);
	if(pSys->cModified!=2) return;
	strcpy(sValue,GetVarcharData(pVar->u.sValue));
}
void set_int_value(char sName[],struct ExprBufStruct *p,int iValue)
{
	struct	ExprBinStruct *pTemp=NULL;
	struct	VariantStruct *pVar;

	if(SearchExprBin(p,sName,&pTemp)==NOTFOUND) return;
	pVar=	&(p->VarBuf[pTemp->iVarInd]);
	pVar->cType=	VARTYPE_INT;
	pVar->u.iValue=	iValue;
}
void set_str_value(char sName[],struct ExprBufStruct *p,char sValue[])
{
	struct	ExprBinStruct *pTemp=NULL;
	struct	VariantStruct *pVar;

	if(SearchExprBin(p,sName,&pTemp)==NOTFOUND) return;
	pVar=	&(p->VarBuf[pTemp->iVarInd]);
	pVar->cType=	VARTYPE_STR;
	
	AssignStrchar2Varchar(&(pVar->u.sValue),sValue);
/*
	strcpy(pVar->u.sValue,sValue);
*/
}
void set_point_value(char sName[],struct ExprBufStruct *p,void *pValue)
{
	struct	ExprBinStruct *pTemp=NULL;
	struct	VariantStruct *pVar;

	if(SearchExprBin(p,sName,&pTemp)==NOTFOUND) return;
	pVar=	&(p->VarBuf[pTemp->iVarInd]);
	pVar->cType=	VARTYPE_POINTER;
	pVar->u.pValue=	pValue;
}
void set_double_value(char sName[],struct ExprBufStruct *p,double dValue)
{
	struct	ExprBinStruct *pTemp=NULL;
	struct	VariantStruct *pVar;

	if(SearchExprBin(p,sName,&pTemp)==NOTFOUND) return;
	pVar=	&(p->VarBuf[pTemp->iVarInd]);
	pVar->cType=	VARTYPE_DOUBLE;
	pVar->u.dValue=	dValue;
}

void PushFileStack(char sFileName[])
{
	strcpy(FileStack[igFilePos++],sFileName);
}
void EmptyFileStack()
{
	igFilePos=0;
}
int EncodingOriPos(int iOriPos)
{
	return (igFilePos-1)*256*256+iOriPos;
}
void DecodingOriPos(int iOriPos,int *piIndex,int *piOriPos)
{
	*piIndex=iOriPos/(256*256);
	*piOriPos=iOriPos%(256*256);
}

int ProcFunDefStatement()
{	
	int iJmpCodeAddr;

	if(C_TYPE!=TYPE_FUN) return -igSymPos;
	
/*处理一般函数*/
	if(SearchDefFun(C_SVALUE,&CURR_FUNP)==NOTFOUND){
		ReportExprError(C_ORIPOS,"语义错误->函数%s未定义",C_SVALUE);
		/*避免函数声明语句错误*/
		if(igSymPos==0) igSymPos++;
		return -igSymPos;
	}

	igSymPos++;/*跳过函数名本身*/

/*生成一条强制跳转语句*/
	GEN(JMP,-1,-1,-1,NULL);
	iJmpCodeAddr=igCodePos-1;
	
	/*记录函数调用的地址*/
	CURR_FUNP->iCodeAddr= igCodePos;
	/*处理一个函数代码*/
	if(ProcStatementBlock()<0) return -igSymPos;
	
/*这里要检查如果没有return语句，
	则设置返回值为默认数值，并返回
	需要添加一下,生成一个POPIP的指令
*/
	if(CODE_FLOW[igCodePos-1].op!=OPSP){
		GEN(OPSP,P_OP_CALL,ADDR_VARIANT,CURR_FUNP->iParamCnt+
			MAXVAR_COUNT,clear_variant);
		GEN(OPSP,P_OP_POP,ADDR_REGISTER,REGISTER_IP,NULL);
	}
	
	/*设置跳转结果地址*/
	SetJmpAddr(iJmpCodeAddr,igCodePos);
	
	CURR_FUNP=NULL;

	return 0;
}
/***
例子:
BP=6096;
SP=6100;
函数原型：
int FUN1(int ,string );
待处理代码: FUN1(1,"abc");
生成代码如下:

生成参数1的代码; 
生成参数2的代码;
PUSH BP;SP=6101,BP=6096
BP=SP;	BP=6101;
PUSH P1 SP=6102
PUSH P2 SP=6103
PUSH RET 这个是空的; SP=6104
CALL FUN1 {
		PUSH IP SP=6105
		JMP ADDR OF FUN1;
	  }
	  SP=6105
//===>SP=SP-N-2 ==> SP=6101
	注意内部的return 触发一次 pop操作.
POP iResultAddr; SP=6103
SP=BP;		 SP=6101
POP BP	  ==> SP=6100,BP=6096;

	d1	d2		r	Oper
p	1 push	0 addr		地址	NULL
	2 pop	1 register	地址	NULL
	3 特殊操作 -1		-1　	调用函数;;
c	CALL
	d1  参数,d2　约束, r 返回值地址,函数iCodePos在返回值的.iParam中;;
======================函数调用的堆栈情况表=======================
	BP[-1]====>$(ORI_BP)
	BP[0]====>  $(P1)
	...
	BP[N-1]==>  $(PN)
	BP[N]====>  $(RET)
	BP[N+1]==>  $(IP)
*/
int ProcFunStatement(int iResultAddr)
{
	
	char sFunType[256];
	int i,iParamCnt,iParamAddr=-1,j,iAddr2;
	struct BlockDefStruct *pTemp=NULL;
	
	if(C_TYPE!=TYPE_FUN) return -igSymPos;
	
/*处理一般函数*/
	if(SearchDefFun(C_SVALUE,&pTemp)==NOTFOUND){
		ReportExprError(C_ORIPOS,"语义错误->函数%s未定义",C_SVALUE);
		return -igSymPos;
	}

	igSymPos++;/*跳过函数名*/
	
	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"语义错误->函数%s后应为(,但遇到了%s",
			pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*跳过'('号*/

/*参数类型约束*/
	iAddr2=		GetVarOffset(NULL);
	CHECKVAROFFSET(iAddr2);
	CODE_VARBUF[iAddr2].cType=VARTYPE_STR;

	iParamCnt=pTemp->iParamCnt;

	sFunType[0]=pTemp->cType;
	strcpy(sFunType+1,pTemp->sType);
	AssignStrchar2Varchar(&(CODE_VARBUF[iAddr2].u.sValue),sFunType);

	if(iResultAddr==-1){
	/*给返回值分配地址*/
		iResultAddr = GetVarOffset(NULL); 
		CHECKVAROFFSET(iResultAddr);
	}

	/*设置函数的返回值*/
	CODE_VARBUF[iResultAddr].cType= pTemp->cType;
	CODE_VARBUF[iResultAddr].iParam=pTemp->iCodeAddr;

	
	/*将调用时的实际参数个数保存在d2.iParam中*/
	CODE_VARBUF[iAddr2].iParam=iParamCnt;

	/*逐个分配参数地址并检查,为了保证连续性
		则先分配再生成各个参数的代码*/
	for(i=0;i<iParamCnt;i++){
		iParamAddr=GetVarOffset(NULL);
		CHECKVAROFFSET(iParamAddr);
	}
	i=0;
	while(i<iParamCnt){
		j=iParamAddr-iParamCnt+i+1;
		if(ProcExpr(j)<0){
			return -igSymPos;
		}
/*
		if(CODE_VARBUF[j].cType!=pTemp->sParamConstraint[i]){
			WriteAlertMsg("函数%s的第%d个参数类型不匹配%c->%c",
				CODE_VARBUF[j].cType,
				pTemp->sParamConstraint[i]);
			return -igSymPos;
		}
*/	
		i++;
		if(i==iParamCnt) break;
			
		if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=','){
			ReportExprError(C_ORIPOS,
				"语义错误->函数%s参数间应为',',但遇到了%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		}
		igSymPos++;/*跳过','号*/
	}
	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"语义错误->函数%s参数结束应为')',但遇到了%s",
				pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*跳过')'号*/
/*到这里,函数调用的参数通过赋值代码被导到iParamAddr-iParamCnt+1->iParamCnt中*/
/*
P	1 push	0 addr		地址
	2 pop	1 register	地址(1=IP;2=BP,3=SP)
*/
	GEN(OPSP,P_OP_PUSH,ADDR_REGISTER,REGISTER_BP,NULL);
	GEN(OPSP,P_OP_CALL,-1,-1,mv_sp2bp);
	/*将N个参数如栈*/
	i=0;
	while(i<iParamCnt){
		j=iParamAddr-iParamCnt+i+1;
		GEN(OPSP,P_OP_PUSH,ADDR_VARIANT,j,NULL);
		i++;
	}
	GEN(OPSP,P_OP_PUSH,ADDR_VARIANT,iResultAddr,NULL);
	
	/*生成指定的函数盗用代码代码*/
	GEN(FUN,iParamAddr-iParamCnt+1,iAddr2,iResultAddr,NULL);
	
	/*生成POP iResultAddr的代码*/
	GEN(OPSP,P_OP_POP,ADDR_VARIANT,iResultAddr,NULL);

	/*生成POP出N个参数的代码*/
	GEN(OPSP,P_OP_POP,ADDR_VARIANT,-iParamCnt,NULL);
	
	/*生成POP　BP的代码*/
	GEN(OPSP,P_OP_POP,ADDR_REGISTER,REGISTER_BP,NULL);
	
	return 0;
}
