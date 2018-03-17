/******************************************************************

    <��ʽ>     ::= <����>
    <����>   ::= <���>|<�������>
    <���>     ::= <��ֵ���>|<�������>|<�����>
    <�������> ::= '{' {<����>} '}'
    <��ֵ���> ::= <����>=<���ʽ>;
    <�������> ::= if(<���ʽ>)<����>|if(<���ʽ>)<����>else<����>
    <�����>   ::= ';'

    <���ʽ> ��<��ֵ���>������ ';' Ϊ��β,��<�������>�� ')' �� '(' ��ƥ��Ϊ��β;

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

int igSymCnt;   /*����������*/
int igSymPos;   /*��������ǰָ��*/
struct SymbolStruct	SymbolFlow[SYMBOL_BUFLEN];

int igReserveCount=0;  /*�����ָ���*/
/*����ϵͳ�ı����ּ������ֵ�����*/
struct ReserveKeywordStruct ReserveSymbol[100];

int igCodePos;     /*�������ĵ�ǰλ��ָ��*/

/*��ǰ�ѱ��빫ʽ��������ʽ�ṹ*/
struct VariantStruct VarBuf[MAXVAR_COUNT+MAXSTACKLEN];
struct CodeStruct CodeBuf[CODE_BUFLEN];
struct OutputExprStruct OutputBuf[SYSVAR_COUNT]; /*�����*/
struct ExprBufStruct ExprBuf;	/*��ʽ�ṹ����*/
struct ExprBufStruct *pExprBuf=&ExprBuf;

/*while�ṹ��μ�continue��ջ��break��ջ*/
int WhileLevel=0,ContinueStack[WHILE_STACK],BreakStack[WHILE_STACK];
int iLabelSp=0;
struct LabelStruct LabelStack[LABEL_STACK];

int	igFilePos=0;		/*include�����ļ��б�����*/
char	FileStack[128][256];	/*include�����ļ����б�*/

void (*LoadVariant)(int,void *pi)=NULL;
void (*SaveVariant)(int,void *pi)=NULL;

void (*LoadConst)(char sVar[],char *pcType,void *pi)=NULL;
int  (*CheckSysVar)(char sVar[],char *pcType)=NULL;

#define GEN(a,b,c,d,e)  { if(Gen(a,b,c,d,e)<0) return -1;}
#define ADDSYMBOLFLOW(a,b,c,d) {if(AddSymbolFlow(a,b,c,d)<0) return -1;}


#define CHECKVAROFFSET(x) if((x)<0){\
			ReportExprError(CURORIPOS,"ϵͳ����->����̫��");\
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
	/*�޸�BP��SP��ָ��*/
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
	/*����Ǳ��ر������ͷ��ڴ�2008.12.31,hlm����*/
	if(pExpr!=&ExprBuf) free(pExpr);
}
void DefSaveVariant(int i,void *pi)
{
	/*Ĭ��ʲô������*/
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

/*�����ַ������������ز�����ȫ�ֱ���ָ��,TempLoadVariant*/
int DefCheckSysVar(char sVar[],char *pcType)
{
	*pcType=VARTYPE_UNK;
	LoadVariant=DefLoadVariant;
	SaveVariant=DefSaveVariant;
	return 0;
}

/*�������Ĺ�ʽ����*/
int GetSysVar(struct ExprBufStruct *pText,int iResetFlag)
{
	int i,iSysVarCnt;
	struct VariantStruct    *pDataSeg;
	struct SymVarStruct	*pSysSeg;

	pDataSeg=	pText->VarBuf;
	pSysSeg=	pText->SysBuf;
	
	iSysVarCnt=pText->iSysVarCnt;

/*		�޸�Ϊֱ�����		*/
	for(i=0;i<iSysVarCnt;i++){
		
		if(pSysSeg[i].cModified == 2){
			if(pSysSeg[i].SaveVariant==NULL){
				printf("����%sû�ж����������-�Ƿ����.\n",
					pSysSeg[i].sSymbol);
				WriteAlertMsg("����%sû�ж����������-�Ƿ����",
					pSysSeg[i].sSymbol);
				return -1;
			}
			/*ֱ�ӵ����������������Ӧ������*/
			pSysSeg[i].SaveVariant(pSysSeg[i].iParam,
				(void*)&(pDataSeg[i].u));
		}
		/*��λϵͳ����*/
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
/*������ʵ��ַ������Ҫת��*/
#define CUROP		CODE_FLOW[igCodePos].op
#define ADDRD1		CODE_FLOW[igCodePos].data1
#define ADDRD2		CODE_FLOW[igCodePos].data2
#define ADDRR		CODE_FLOW[igCodePos].result

/*������ʽ���������*/
	if(ADDRD1>=MAXVAR_COUNT||ADDRD2>=MAXVAR_COUNT||ADDRR>=MAXVAR_COUNT)
		return 0;

	switch(CUROP){
	case JMP:
	case JMPF:
		/*��ЧĿ�ĵ�ַ,��������Ҫ�޸ĵĵ�ַ*/
		if(ADDRR<0){
			ReportExprError(CURORIPOS,"�������->��ת��Ч��ַ");
			return -1;
		}
		/*����������*/
		if(CUROP==JMPF&&CODE_VARBUF[ADDRD1].cType!=VARTYPE_INT&&
			CODE_VARBUF[ADDRD1].cType!=VARTYPE_UNK){
			ReportExprError(CURORIPOS,"�������->��ת��Ч��ַ");
			return -1;
		}
		break;
	case RET:
	break;
	case ADD:
		/*�Ƿ���ַ*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"�������->�ӷ���ַ��Ч");
			return -1;
		}
		/*������������ͬ��*/
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_STR||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE)){

				/*����ֶκͲ����ֶ���ͬ*/
			if(CODE_VARBUF[ADDRR].cType==
				CODE_VARBUF[ADDRD1].cType) break;
				/*����ֶ�����ʱ����������δ֪����*/
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
				/*���Ӱ�ȫ�����������޸�add1.type*/
				CODE_VARBUF[ADDRD1].cType=CODE_VARBUF[ADDRD2].cType;
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD2].cType;
				break;
			}
		}
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_POINTER&&
			CODE_VARBUF[ADDRD2].cType==VARTYPE_INT){
				/*����ֶκͲ����ֶ���ͬ*/
			if(CODE_VARBUF[ADDRR].cType==
				CODE_VARBUF[ADDRD1].cType) break;
				/*����ֶ�����ʱ����������δ֪����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD1].cType;
				break;
			}
		}
		ReportExprError(CURORIPOS,"�������->�ӷ����Ͳ�һ��");
		return -1;
	case SUB:
	case MULTI:
	case DIV:
		/*�Ƿ���ַ*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"�������->����%c��ַ��Ч",CUROP);
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT)){
			
				/*����ֶκͲ����ֶ���ͬ*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*����ֶ�����ʱ����������δ֪����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE)){
			
				/*����ֶκͲ����ֶ���ͬ*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_DOUBLE)
				break;
				/*����ֶ�����ʱ����������δ֪����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_DOUBLE;
				break;
			}
		}
		ReportExprError(CURORIPOS,"�������->����%c���Ͳ�ƥ��",CUROP);
		return -1;
	case SQR:
	case MOD:
	case OR:
	case AND:
	case MOR:
	case MAND:
		/*�Ƿ���ַ*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"�������->����%c��ַ��Ч",CUROP);
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT)){
			
				/*����ֶκͲ����ֶ���ͬ*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*����ֶ�����ʱ����������δ֪����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		ReportExprError(CURORIPOS,"�������->����%c���Ͳ�ƥ��",CUROP);
		return -1;
	case GT:
	case LT:
	case GE:
	case LE:
	case EQ:
	case NE:
		/*�Ƿ���ַ*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"�������->����%c��ַ��Ч",CUROP);
			return -1;
		}
		/*������������ͬ���������ַ���*/
		if(CODE_VARBUF[ADDRD1].cType==CODE_VARBUF[ADDRD2].cType&&
			(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_STR||
				CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE)){

				/*����ֶ�Ϊ����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*����ֶ�����ʱ����������δ֪����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		ReportExprError(CURORIPOS,"�������->����%c���Ͳ�ƥ��",CUROP);
		return -1;
	case NOT:
		/*�Ƿ���ַ*/
		if(ADDRD1<0||ADDRR<0){
			ReportExprError(CURORIPOS,"�������->�ǲ�����ַ��Ч");
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT){
			
				/*����ֶκͲ����ֶ���ͬ*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_INT)
				break;
				/*����ֶ�����ʱ����������δ֪����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||
				ADDRR>=SYSVAR_COUNT){
				CODE_VARBUF[ADDRR].cType=VARTYPE_INT;
				break;
			}
		}
		ReportExprError(CURORIPOS,"�������->�ǲ������Ͳ�ƥ��");
		return -1;
		
	case ASSIGN:
		/*�Ƿ���ַ*/
		if(ADDRD1<0||ADDRR<0){
			ReportExprError(CURORIPOS,"�������->��ֵ��ַ��Ч");
			return -1;
		}	
		
		/*�����δ��ʼ���ı������Ҳ����м����*/
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_UNK&&
			(i=CODE_VARBUF[ADDRD1].iIndex)>=0){
			/*ֻ��$��ͷ�ı�����������������ʽ�ⲿ�ĳ����ʼ��*/
			if(CODE_SYSBUF[i].sSymbol[0]=='$') break;
        	
			ReportExprError(CURORIPOS,"�������->����%sδ��ʼ����ʹ��",
				CODE_SYSBUF[i].sSymbol);
			return -1;
		}
		if(CODE_VARBUF[ADDRD1].cType==VARTYPE_INT||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_STR||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_POINTER||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_STRUCT||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_DOUBLE||
			CODE_VARBUF[ADDRD1].cType==VARTYPE_UNK){
			
				/*����ֶκͲ����ֶ���ͬ*/
			if(CODE_VARBUF[ADDRR].cType==CODE_VARBUF[ADDRD1].cType)
				break;
				/*����ֶ�����ʱ����������δ֪����*/
			if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK){
				CODE_VARBUF[ADDRR].cType=CODE_VARBUF[ADDRD1].cType;
				break;
			}
			if(CODE_VARBUF[ADDRD1].cType==VARTYPE_UNK)
				break;
		}
		ReportExprError(CURORIPOS,"�������->��ֵ���Ͳ�ƥ��");
		return -1;
	case SFUN :/*��̬���������*/
	break;
	case DFUN:
	case FUN:
		/*�Ƿ���ַ*/
		if(ADDRD1<0||ADDRD2<0||ADDRR<0){
			ReportExprError(CURORIPOS,"�������->�������õ�ַ��Ч");
			return -1;
		}
		
		if(CODE_VARBUF[ADDRD2].cType!=VARTYPE_STR){
			ReportExprError(CURORIPOS,"�������->�����������");
			return -1;
		}
		sFunType=GetVarcharData(CODE_VARBUF[ADDRD2].u.sValue);
		if(CODE_VARBUF[ADDRR].cType==VARTYPE_UNK||ADDRR>=SYSVAR_COUNT)
			CODE_VARBUF[ADDRR].cType=sFunType[0];

		if(CODE_VARBUF[ADDRR].cType!=sFunType[0]){
			ReportExprError(CURORIPOS,"�������->��������ֵ���ʹ���");
			return -1;
		}
		for(i=0,j=1;j<strlen(sFunType);i++,j++){

			/*����ǿɱ����ֱ�Ӳ��������*/
			if(sFunType[j]=='#') break;
			
			if(CODE_VARBUF[ADDRD1+i].cType==VARTYPE_UNK&&
				ADDRD1+i>SYSVAR_COUNT)
				CODE_VARBUF[ADDRD1+i].cType=sFunType[j];

			if(sFunType[j]!=CODE_VARBUF[ADDRD1+i].cType&&
				sFunType[j]!=VARTYPE_UNK){
				ReportExprError(CURORIPOS,"�������->������%d�������Ͳ�ƥ��",j);
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
	ReportExprError(CURORIPOS,"�������->�Ƿ�ָ��");
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
	/*Ϊ�����Ч�ʸ�Ϊ����*/
		C_D1=MY_AD(pCode->data1);
		C_D2=MY_AD(pCode->data2);
		C_RES=MY_AD(pCode->result);
	/*����Ƿ��ж�ջ���*/
		CHECK_AD(C_D1);
		CHECK_AD(C_D2);
		CHECK_AD(C_RES);
	/*��ַ��Ч��ֱ�ӻ�ȡ������ȡĬ����������*/
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
			if(C_D1!=-1){/*ֱ�Ӹ��Ƶ���ʽ������*/
				if(C_D1_TYPE==VARTYPE_INT){
					d1 = GetIntVariant(pDataSeg,C_D1);
					CURR_EXPR.r.u.iValue = d1;
				}
				else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
					GetStrVariant(pDataSeg,C_D1);/*��Ҫ��*/
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
				else{/*�ṹ��ֵ*/
					GetPointVariant(pDataSeg,C_D1);/*��Ҫ��*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
				AddV2VStrchar(&(asVarInput[C_RES].u.sValue),
					asVarInput[C_D1].u.sValue,
					asVarInput[C_D2].u.sValue);
			}
			else if(C_D1_TYPE==VARTYPE_DOUBLE){
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				asVarInput[C_RES].u.dValue=f1+f2;
			}
			else{/*ָ��ӷ�*/
				s1 = GetPointVariant(pDataSeg,C_D1);
				d2 = GetIntVariant(pDataSeg,C_D2);
				pDataSeg[C_RES].u.pValue=s1+d2;
			}
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
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
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
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
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
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
					WriteAlertMsg("��ʽ�ĳ���Ϊ0");
					return -1;
				}
				asVarInput[C_RES].u.iValue = d1 / d2;
			}
			else{
				f1=GetDoubleVariant(pDataSeg,C_D1);
				f2=GetDoubleVariant(pDataSeg,C_D2);
				if(f2 == 0 ){
					WriteAlertMsg("��ʽ�ĳ���Ϊ0");
					return -1;
				}				
				asVarInput[C_RES].u.dValue=f1/f2;
			}
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			break;
		case MOD:
			d1 = GetIntVariant(pDataSeg,C_D1);
			d2 = GetIntVariant(pDataSeg,C_D2);
			asVarInput[C_RES].u.iValue=d1%d2;
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
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
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
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
			else if(C_D1_TYPE==VARTYPE_STR){/*�ַ�������*/
				GetStrVariant(pDataSeg,C_D1);/*��Ҫ��*/
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
			else{/*�ṹ��ֵ*/
				GetPointVariant(pDataSeg,C_D1);/*��Ҫ��*/
				AssignV2VMemchar(&(asVarInput[C_RES].u.sValue),
					asVarInput[C_D1].u.sValue);
			}
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			if(IS_TMPTMPVAR(C_RES))/*����ǳ��ؼ���������������*/
				asVarInput[C_RES].iParam=asVarInput[C_D1].iParam;
			
			break;
		case SFUN:/*��̬������������*/
			igCodePos++;
			continue;
		case DFUN:/*���ö�̬����*/
			r=C_OPER(C_D1,C_RES);
			if(r<0) return -1;
			igCodePos++;
			/*�����ϵͳ�������޸ĸ�ֵ��ʶ*/
			if((iIndex=asVarInput[C_RES].iIndex)!=-1)
				asSysInput[iIndex].cModified = 2;
			/*�������������ʽ�����������ͱ�����Ҫ�޸�����*/
			if(IS_PARAVAR(C_RES)||
				(IS_TMPTMPVAR(C_RES)&&
				CODE_VARBUF[C_RES].cType==VARTYPE_UNK))
				asVarInput[C_RES].cType=C_D1_TYPE;
			continue;
		case FUN:
			/*IP��ջ*/
			MY_PUSH_REG(igCodePos+1);/*ֱ����ת��ָ����ַ*/
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
					continue;/*�޸ķ��ص�ַ���˳�*/
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
				/*����͵���һ�º�������*/
				if(C_OPER(C_D1,C_RES)<0) return -1;
			}
			/*��������Ķ���������*/
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
	
	if(iOffset>=SYSVAR_COUNT) return pData->u.iValue;	/* ��ʱ���� */

	if(CODE_SYSBUF[iOffset].cModified > 0) return pData->u.iValue;
	

	/*ע����������ڼ��ر���ǰ����Ϊ�������غ����ڲ������޸���*/
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
	
	/* ��ʱ���� */
	if(iOffset>=SYSVAR_COUNT) return GetVarcharData(pData->u.sValue);

	if(CODE_SYSBUF[iOffset].cModified>0) 
		return GetVarcharData(pData->u.sValue);
	

	/*ע����������ڼ��ر���ǰ����Ϊ�������غ����ڲ������޸���*/
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
	
	if(iOffset>=SYSVAR_COUNT) return pData->u.pValue;	/* ��ʱ���� */

	if(CODE_SYSBUF[iOffset].cModified > 0) return pData->u.pValue;
	

	/*ע����������ڼ��ر���ǰ����Ϊ�������غ����ڲ������޸���*/
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
	
	if(iOffset>=SYSVAR_COUNT) return pData->u.dValue;	/* ��ʱ���� */

	if(CODE_SYSBUF[iOffset].cModified > 0) return pData->u.dValue;
	
	/*ע����������ڼ��ر���ǰ����Ϊ�������غ����ڲ������޸���*/
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
	/*��ʽ����ɹ���������������ķ���*/
	(*piOutputLen) = CURR_EXPR.iOutputLen;
	memcpy(asVarOutput,CURR_EXPR.OutputBuf,
		(*piOutputLen)*sizeof(struct OutputExprStruct));
}
int CheckCompileResult(int iOutputLen,struct OutputExprStruct asVarOutput[])
{
	int i;

	/**2002-01-16���CheckSysVar�ĺϷ���***/
	for(i=0;i<iOutputLen;i++){

		if(asVarOutput[i].iParam<0){
			ReportExprError(0,"����������->�����Ƿ�����%s",
				asVarOutput[i].sSymbol);
			return -1;
		}
	}
	if(CURR_EXPR.iSysVarCnt>=SYSVAR_COUNT){
		
		ReportExprError(0,"ϵͳ����->ϵͳ������%d���������%d",
			CURR_EXPR.iSysVarCnt,SYSVAR_COUNT);
		return -1;
	}
	if(CURR_EXPR.iTmpVarCnt>=(MAXVAR_COUNT-SYSVAR_COUNT)){
		ReportExprError(0,"ϵͳ����->��ʱ������%d���������%d",
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

	/*������λ�ý���*/
	DecodingOriPos(pExprBuf->iPos,&iIndex,&iOffset);

	if(iIndex>0){
		/*����ļ����������ֱ�ӽ��ļ����ֺ�ƫ�ƴ�������ο�*/
		if(ReadFileToBuf(FileStack[iIndex],EXPRLEN,sInput,sMsg)<0){
			sprintf(pExprBuf->sErrorMsg,"�ļ�%s�������%s,ƫ��%d",
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
	sprintf(pExprBuf->sErrorMsg,"�ļ�%s\n%s\n%s\nλ��:%d��%d��,%s",
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
	igSymCnt=0;   /*����������*/
	igSymPos=0;   /*��������ǰָ*/

	WhileLevel=0; /*�������*/
	igCodePos=0;  /*�������*/
		
/*�����ʽ�����������������׶ε����Ϊ��ʽ��ߵ�ϵͳ�����������ܲ����������*/
	CURR_EXPR.iOutputLen = 0;

/*��λ���ر��� ���� ����������*/

	if(LoadConst==NULL)
		LoadConst=DefLoadConst;	/*���س�������*/

	/*��λ���ر�������,�������ַ���Ϊ����*/
	if(CheckSysVar==NULL)
		CheckSysVar= DefCheckSysVar;

	InitReserveSymbol();
	
	/*���дʷ�����,���ɵ�������*/
	if( (iRet = PropLexicalize(sInput,sMsg)) <0){
		FormatExprErrorMsg(sInput);
		return -2;
	}

#ifdef DEBUG_EXPR
	DisplaySymbolFlow();
#endif
	/*�﷨���������,������Ԫ������*/
	if((iRet=GenerateCode())<0){

		FormatExprErrorMsg(sInput);
		
		return -3;
	}
#ifdef DEBUG_EXPR
	DisplayCode();
#endif
	/*����Ƿ�ȫ�����ɹ�����*/
	if(igSymPos<igSymCnt){
		
		ReportExprError(C_ORIPOS,"��ʽ������,{ �� } ��ƥ��");
		
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
/*���ɴ���*/
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

/*���� <����>*/
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

/*���� <�������>*/
/* ��ջ����{}����������� */
int ProcComplexStatement()
{
	igSymPos++;        /*����'{'*/
	while(!(C_TYPE==TYPE_SEPARATOR&&C_CVALUE=='}') && igSymPos<igSymCnt){

		if( C_TYPE==TYPE_SEPARATOR &&  C_CVALUE=='{' ){
			if(ProcComplexStatement()<0)
				return -igSymPos;
		}
		else{
			if(ProcStatement()<0)
				return -igSymPos;
		}
	}; /*����ֱ��ƥ�䵽 '}'*/

	if((igSymPos>=igSymCnt)||(C_TYPE!=TYPE_SEPARATOR)||(C_CVALUE!='}')){
		ReportExprError(C_ORIPOS,"�������->{�޷�ƥ�䵽}");
		return -igSymPos;
	}

	igSymPos++; /*���� '{'*/
	return 0;

}
int ProcGotoTarget(int iTargetCodeAddr)
{
	int i,iJmpCodeAddr;

	for(i=0;i<iLabelSp;i++){
		if(strcmp(C_SVALUE,LabelStack[i].sLabel)==0){
			if(LabelStack[i].iTargetCodeAddr!=-1){
				ReportExprError(CURRORIPOS,"�������->�����������%s",
					LabelStack[i].sLabel);
				return -1;
			}
			LabelStack[i].iTargetCodeAddr=iTargetCodeAddr;
			iJmpCodeAddr=LabelStack[i].iJmpCodeAddr;
			SetJmpAddr(iJmpCodeAddr,iTargetCodeAddr);
		}
	}
	/*û�з���goto��䵽�ñ�ʶ*/
	if(i==iLabelSp){
		if(iLabelSp>=LABEL_STACK-1){
			ReportExprError(CURRORIPOS,"ϵͳ����->���ջ���");
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
	/*û�з���goto����Ŀ�ı�ʶ*/
	if(i==iLabelSp){
		if(iLabelSp>=LABEL_STACK-1){
			ReportExprError(CURRORIPOS,"ϵͳ����->���ջ���");
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
				"�﷨����->goto��ʶ%s,Ŀ�ĵ�ַû�ж���",
				LabelStack[i].sLabel);
			return -1;
		}
	}
	return 0;
}
/*���� <�������>*/
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

	igSymPos++;/*���������ַ�*/

	while(1){
		if(C_TYPE!=TYPE_TEMPVAR&&C_TYPE!=TYPE_SYSVAR){

			ReportExprError(C_ORIPOS,
			"�������->��������%s,����ϵͳ����ʱ����",C_SVALUE);

			return -igSymPos;
		}
		iTmpAddr=GetVarOffset(C_SVALUE);

		CHECKVAROFFSET(iTmpAddr);

		/*�������û����������֮*/		
		if(CODE_VARBUF[iTmpAddr].cType==VARTYPE_UNK)
			CODE_VARBUF[iTmpAddr].cType=cType;

		if(CODE_VARBUF[iTmpAddr].cType!=cType){

			ReportExprError(C_ORIPOS,
				"�������->����%s,���ͳ�ͻ,ԭ����%c,������%c",
				C_SVALUE,CODE_VARBUF[iTmpAddr].cType,cType);

			return -igSymPos;
		}
		
		igSymPos++;/*����һ������*/
		
		/*�������������OK*/
		if(C_TYPE==TYPE_SEPARATOR && C_CVALUE==';') break;
		
		if(!(C_TYPE==TYPE_SEPARATOR && C_CVALUE==',')){
			
			ReportExprError(C_ORIPOS,
			"�������->�������,������Ϊ',',����Ϊ%s",	C_SVALUE);

			return -igSymPos;			
		}
		
		igSymPos++;/*���������ļ����*/
	}

	igSymPos++; /*���������*/

	return 0;
}
/*���� <���>*/
int ProcStatement()
{

	/*�����'if'��ͷ��,�����������,�����Ǹ�ֵ���*/
	if(( C_TYPE ==TYPE_CONTROL)&&( strcmp(C_SVALUE,"if")==0))
		return (ProcConditionStatement()<0)?-igSymPos:0;

	if(( C_TYPE ==TYPE_CONTROL)&&( strcmp(C_SVALUE,"while")==0))
		return (ProcWhileStatement()<0)?-igSymPos:0;

	if((C_TYPE ==TYPE_CONTROL)&& 
		( strcmp(C_SVALUE,"return")==0||
		  strcmp(C_SVALUE,"break")==0||
		  strcmp(C_SVALUE,"continue")==0))
		return (ProcControlStatement()<0)?-igSymPos:0;
/*����gotoĿ�ı�ʶ��*/
	if((C_TYPE==TYPE_TEMPVAR)&&(
		C_TYPEN==TYPE_SEPARATOR&&C_CVALUEN==':')){
		
		int iTargetCodeAddr=igCodePos;
		
		if(ProcGotoTarget(iTargetCodeAddr)<0) return -igSymPos;
		igSymPos+=2;
		return 0;
	}
/*����goto���*/
	if((C_TYPE ==TYPE_CONTROL)&&strcmp(C_SVALUE,"goto")==0){
		
		int iJmpCodeAddr;
		
		igSymPos++;
		if(C_TYPE!=TYPE_TEMPVAR){
			ReportExprError(C_ORIPOS,"�������->ӦΪ���,��������%s",C_SVALUE);
			return -igSymPos;
		}
		
		GEN(JMP,-1,-1,-1,NULL);
		iJmpCodeAddr = igCodePos-1;/*��ס��ǰJMP�Ĵ����ַ*/
		
		if(ProcGotoJmp(iJmpCodeAddr)<0) return -igSymPos;
		igSymPos++;
		if((C_TYPE==TYPE_SEPARATOR)&&( C_CVALUE == ';')){
			igSymPos++;
			return 0;
		}
		ReportExprError(C_ORIPOS,"�������->ӦΪ';',��������%s",C_SVALUE);
		return -igSymPos;
	}
/*����ֵ���*/
	if(C_TYPE==TYPE_SYSVAR||C_TYPE==TYPE_TEMPVAR||
		C_TYPE==TYPE_MODALITY_PARA)
		return (ProcAssignStatement()<0)?-igSymPos:0;
/*����̬����*/
	if(C_TYPE==TYPE_DFUN){
		if(ProcDFunStatement(-1)<0) return -igSymPos;
	}
/*����̬����*/
	if(C_TYPE==TYPE_SFUN){
		if(ProcSFunStatement(-1)<0) return -igSymPos;
	}
/*�����Զ��庯��*/
	if(C_TYPE==TYPE_FUN&&C_CVALUEN=='('){
		if(ProcFunStatement(-1)<0) return -igSymPos;
	}
/*�������������*/
	if(C_TYPE==TYPE_FUN){
		return (ProcFunDefStatement()<0)?-igSymPos:0;
	}
	if(C_TYPE==TYPE_SEPARATOR&&(C_CVALUE==';'||NewLine(C_CVALUE))){
		igSymPos++;     /*�����,���� ';','\r','\n'*/
 		return 0;
	}
/*�����������*/
	if(C_TYPE==TYPE_DECLARE){
		return (ProcDeclareStatement()<0)?-igSymPos:0;
	}

	ReportExprError(C_ORIPOS,"�������->ӦΪ';',��������%s",C_SVALUE);
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
/*���� <�������>,ע�ⲻ֧���޷���ֵ����*/
int ProcDFunStatement(int iResultAddr)
{	
	char sFunType[256];
	int i,iParamCnt,iParamAddr=-1,j,iAddr2;
	struct ExprFunStruct *pTemp;
	
	if(C_TYPE!=TYPE_DFUN) return -igSymPos;
	
/*����һ�㺯��*/
	if(SearchRegFunLink(C_SVALUE,&pTemp)==NOTFOUND){
		ReportExprError(C_ORIPOS,"�������->����%sδע��",C_SVALUE);
		return -igSymPos;
	}

	igSymPos++;/*������������*/
		
	iParamCnt=strlen(pTemp->sParamConstraint);
	/*����ǿɱ��������ӷ��ű��л�ȡ��������ʱʵ�ʵĲ�������*/
	if(strcmp(pTemp->sParamConstraint,"#")==0)
		iParamCnt=GetSymParamCnt(igSymPos,igSymCnt);

	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"�������->����%s��ӦΪ(,��������%s",C_SVALUE);
		return igSymPos;
	}
		
	igSymPos++;/*����'('��*/

/*��������Լ��*/
	iAddr2=		GetVarOffset(NULL);
	CHECKVAROFFSET(iAddr2);
	CODE_VARBUF[iAddr2].cType=VARTYPE_STR;

	sFunType[0]=pTemp->cType;
	strcpy(sFunType+1,pTemp->sParamConstraint);
	AssignStrchar2Varchar(&(CODE_VARBUF[iAddr2].u.sValue),sFunType);
	
	if(iResultAddr==-1){
	/*������ֵ�����ַ*/
		iResultAddr = GetVarOffset(NULL); 
		CHECKVAROFFSET(iResultAddr);
	}

	/*������ʱ��ʵ�ʲ�������������d2.iParam��*/
	CODE_VARBUF[iAddr2].iParam=iParamCnt;
	
	/*������������ַ�����,Ϊ�˱�֤������
		���ȷ��������ɸ��������Ĵ���*/
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
			WriteAlertMsg("����%s�ĵ�%d���������Ͳ�ƥ��%c->%c",
				CODE_VARBUF[j].cType,
				pTemp->sParamConstraint[i]);
			return -igSymPos;
		}
*/	
		i++;
		if(i==iParamCnt) break;
			
		if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=','){
			ReportExprError(C_ORIPOS,
				"�������->����%s������ӦΪ',',��������%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		}
		igSymPos++;/*����','��*/
	}
	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"�������->����%s��������ӦΪ')',��������%s",
				pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*����')'��*/
	
	/*д������ֵ������*/
	CODE_VARBUF[iResultAddr].cType=pTemp->cType;
	
	iParamAddr=iParamAddr-iParamCnt+1;
	
	GEN(DFUN,iParamAddr,iAddr2,iResultAddr,pTemp->FUNCTION);

	return iResultAddr;
}
/*���� <��̬�������>,ע�ⲻ֧���޷���ֵ����*/
int ProcSFunStatement(int iResultAddr)
{
	char sFunType[256];
	int i,iParamCnt,iParamAddr=-1,j,k,iAddr2;

	struct ExprFunStruct *pTemp;

	if(C_TYPE!=TYPE_SFUN) return -igSymPos;

	if(SearchRegFunLink(C_SVALUE,&pTemp)==NOTFOUND){
		ReportExprError(C_ORIPOS,"�������->����%sδע��",C_SVALUE);
		return -igSymPos;
	}
		
	igSymPos++;/*������������*/

	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"�������->����%s��ӦΪ(,��������%s",C_SVALUE);
		return igSymPos;
	}
		
	igSymPos++;/*����'('��*/

	iParamCnt=strlen(pTemp->sParamConstraint);

/*��������Լ��*/
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
	/*������ֵ�����ַ*/
		iResultAddr = GetVarOffset(NULL); 
		CHECKVAROFFSET(iResultAddr);
	}
	
	/*������������ַ�����,Ϊ�˱�֤������
		���ȷ��������ɸ��������Ĵ���*/
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
			igSymPos++;/*������ֶ����ñ���������������*/
		break;
		case TYPE_SFUN:
			if(ProcSFunStatement(j)<0) return -igSymPos;
		break;
		case TYPE_SYSVAR:
			/*��ϵͳ�����Ĳ���������*/
			k=GetVarOffset(C_SVALUE);
			CHECKVAROFFSET(k);
			CODE_VARBUF[j].iParam=CODE_VARBUF[k].iParam;
			igSymPos++;/*������ֶ����ñ���������������*/
		break;
		default:
		ReportExprError(C_ORIPOS,
		"�������->��������%s,������Ϊϵͳ��������������������Ϊ%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		break;
		}
		
		i++;
		if(i==iParamCnt) break;
			
		if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=','){
			ReportExprError(C_ORIPOS,
			"�������->��������%s������ӦΪ',',��������%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		}
		igSymPos++;/*����','��*/
	}

	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"�������->����%s��������ӦΪ')',��������%s",
				pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*����')'��*/

	iParamAddr=iParamAddr-iParamCnt+1;

	/*ֱ�ӵ��þ�̬���������������������ַ��*/
	if(pTemp->FUNCTION(iParamAddr,iResultAddr)<0){
			
		ReportExprError(C_ORIPOS,
			"�������->���þ�̬����%sʧ��",pTemp->sName);
		return -igSymPos;
	}
	/*����һ�����������ղ����룬����DisplayCode*/
	GEN(SFUN,iParamAddr,iAddr2,iResultAddr,pTemp->FUNCTION);

	return iResultAddr;
}
/*���� <��ֵ���>*/
int ProcAssignStatement()
{
	int iResultAddr;

	if(C_TYPE!=TYPE_MODALITY_PARA){
		iResultAddr=GetVarOffset(C_SVALUE); /*ȡ�ñ���ֵ������ƫ�Ƶ�ַ*/
		CHECKVAROFFSET(iResultAddr);
	}
	else
		iResultAddr=atoi(C_SVALUE)+MAXVAR_COUNT;

	igSymPos++;/*���뱻��ֵ����*/
	if(C_TYPE!=TYPE_ASSIGN){

		ReportExprError(C_ORIPOS,
			"�������->��ֵӦΪ=��������%s,",C_SVALUE);

		return -igSymPos;
	}
	igSymPos++; /*���븳ֵ��*/

	if(ProcExpr(iResultAddr)<0) return -igSymPos;

	if(C_TYPE==TYPE_SEPARATOR && C_CVALUE==';')
		igSymPos++;            /*���� ;*/
	else{
		ReportExprError(C_ORIPOS,
			"�������->��ֵ������ӦΪ';',��������%s,",C_SVALUE);
		return -igSymPos;
	}
	return 0;	

}

/*���� <�������>*/
/*	��¼if����һ��������ַ
	true	����¼��ַƫ��
	false	��¼��ַƫ��
	��ǿ������һ��Ϊ�ٵ���ת��Ԫʽ(��ת��ַ����)��������ifΪtrue�������󣬽���ת��ַ����
*/
int ProcConditionStatement()
{
	int iCondResultAddr;
	int iCodeAddr1,iCodeAddr2;

	igSymPos++;     /*���� if���� '('*/
	iCondResultAddr = GetVarOffset(NULL);
	CHECKVAROFFSET(iCondResultAddr);

	if( ( C_TYPE ==TYPE_MATH) && (C_CVALUE=='(') )
	     igSymPos++;     /*���� '('*/
	else{
		ReportExprError(C_ORIPOS,
			"�������->������俪ʼӦΪ'(',��������%s,",C_SVALUE);
		return -igSymPos;
	}	     

	/* �����������ʽ ������ƫ�Ʒ��� iCondResultAddr*/
	if(ProcExpr(iCondResultAddr)<0)
		return -igSymPos;
	if(C_TYPE==TYPE_MATH && C_CVALUE==')')
		igSymPos++;      /*���� ')')*/
	else{
		ReportExprError(C_ORIPOS,
			"�������->����������ӦΪ')',��������%s,",C_SVALUE);
		return -igSymPos;
	}
	/*���� '���iCondResultAddr,��Ӧ�����ݶ���ֵ������ת' ���,
		Ŀ�ĵ�ַΪ������һ�������Ĵ�����ָ��*/
	GEN(JMPF,iCondResultAddr,-1,-1,NULL);
	iCodeAddr1 = igCodePos-1;/*��ס��ǰJMPF�Ĵ����ַ*/
	/*   */

	if(ProcStatementBlock()<0)
		return -igSymPos;

	if( C_TYPE==TYPE_CONTROL &&  strcmp( C_SVALUE, "else")==0 ){

		/* ���� '��������ת' ���, Ŀ�ĵ�ַΪ������һ������(else��)��Ĵ�����ָ��*/
		GEN(JMP,-1,-1,-1,NULL);
		iCodeAddr2 = igCodePos-1;/*��ס��ǰJMP�Ĵ����ַ*/
		/* */

		/*��д ǰ'���iCondResultAddr������ת' ��Ŀ�ĵ�ַ*/
		SetJmpAddr(iCodeAddr1,igCodePos);/*�����iCodeAddr1ָ����if��������һ���߼����ʾ�����ַ*/
		/* igCodePosָ����else�������Ĵ����ַ*/
		igSymPos++;/*���� 'else'*/
		if(ProcStatementBlock()<0)
			return -igSymPos;
		/*��д ǰ'��������ת' ����Ŀ�ĵ�ַ*/
		SetJmpAddr(iCodeAddr2,igCodePos);
	}
	else{
		/*��д ǰ'���iCondResultAddr������ת' ��Ŀ�ĵ�ַ*/
		SetJmpAddr(iCodeAddr1,igCodePos);
	}
	return 0;
}

/*���� <����ѭ�����>*/
int ProcWhileStatement()
{
	int iVarOffset;
	int iCodeAddr1,iCodeAddr2,iCodeAddrContinue,iCodeAddrBreak;

	igSymPos++; /*���� "while"*/

	/*������ʱ�м����*/
        iVarOffset=GetVarOffset(NULL);
	CHECKVAROFFSET(iVarOffset);

	if(C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"�������->while��俪ʼӦΪ'(',��������%s,",C_SVALUE);
		return -igSymPos;
	}

	igSymPos++;     /*���� '('*/     

	iCodeAddrContinue = igCodePos;/*��ס��ǰCONTINUE�Ĵ����ַ*/


	if(ProcExpr(iVarOffset)<0)	return -igSymPos;

	if(C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"�������->while������ӦΪ')',��������%s,",C_SVALUE);
		return -igSymPos;
	}
	
	igSymPos++;      /*���� ')')*/

	/*���� '���iVarOffset������ת' ���,Ŀ�ĵ�ַΪWHILE������
		Ŀǰ���ĵ�ַ��ʱ��-1*/
	GEN(JMPF,iVarOffset,-1,-1,NULL);
	iCodeAddr1 = igCodePos-1;/*��ס��ǰJMPF�Ĵ����ַ,��WHILEʧ����*/

	/*���� '���iVarOffset������ת' ���,Ŀ�ĵ�ַΪWHILEѭ����
		Ŀǰ���ĵ�ַ��ʱ��-1*/
	GEN(JMP,-1,-1,-1,NULL);
	iCodeAddr2 = igCodePos-1;/*��ס��ǰ��ת��ѭ����ĵ�ַ*/

	/*���� '���iVarOffset������ת' ���,Ŀ�ĵ�ַΪWHILE������
		Ŀǰ���ĵ�ַ��ʱ��-1*/
	GEN(JMP,-1,-1,-1,NULL);
	iCodeAddrBreak = igCodePos-1;/*��ס��ǰ��ת��ѭ��������ľ�����ת�����BREAK��*/

	/*��д ǰ'���iVarOffset������ת' ��Ŀ�ĵ�ַ*/
	SetJmpAddr(iCodeAddr2,igCodePos);

/*��WHILE��CONTINUE��BREAK���ݸ�ȫ�ֱ����������������*/
	ContinueStack[WhileLevel]=iCodeAddrContinue;
	BreakStack[WhileLevel]=iCodeAddrBreak;
/*WHILE����*/
	WhileLevel ++;

	if(ProcStatementBlock()<0){
		return -igSymPos;
	}
	GEN(JMP,-1,-1,iCodeAddrContinue,NULL); /*����CONTINUE����*/

/*�޸�while�ļ���ת��break������ת��Ŀ�ĵ�ַΪ��ѭ�������*/
	SetJmpAddr(iCodeAddr1,igCodePos);
	SetJmpAddr(iCodeAddrBreak,igCodePos);
/*WHILE����*/
	WhileLevel--;

	return 0;
}


int ProcControlStatement()
{

	if(C_TYPE!=TYPE_CONTROL){
		ReportExprError(C_ORIPOS,
			"�������->������俪ʼ���ʹ���");
		return -igSymPos;
	}

	if(strcmp(C_SVALUE,"return")==0){

		int iVarOffset=-1;

		/*����return 		*/
		igSymPos ++;

		if(C_CVALUE!=';'){	
		        iVarOffset=GetVarOffset(NULL);
			CHECKVAROFFSET(iVarOffset);

			if(ProcExpr(iVarOffset)<0)	return -igSymPos;
		}

		if(C_CVALUE!=';'){
			ReportExprError(C_ORIPOS,
			"�������->return������ӦΪ';',��������%s,",C_SVALUE);
			return -igSymPos;
		}
		
		if(CURR_FUNP!=NULL){ /*��ĳ�������е�return*/
			
			if(iVarOffset!=-1){/*����з���ֵ������һ����ֵ���*/
				GEN('=',iVarOffset,-1,CURR_FUNP->iParamCnt+
					MAXVAR_COUNT,NULL);
			}
			/*����һ��POPָ��,POP��IPȥ���γ���ת*/
			GEN(OPSP,P_OP_POP,ADDR_REGISTER,REGISTER_IP,NULL);
			return 0;
		}
		/*ֱ�����ɽ�������	*/
		GEN(RET,iVarOffset,-1,-1,NULL);

		return 0;
	}

	if(strcmp(C_SVALUE,"continue")!=0 && strcmp(C_SVALUE,"break")!=0 ){

		ReportExprError(C_ORIPOS,
			"�������->�Ƿ��������%s,",C_SVALUE);
		return -igSymPos;
	}

	if(WhileLevel<=0){
		ReportExprError(C_ORIPOS,
			"�������->%s���;������whileѭ����,",C_SVALUE);
		return -igSymPos;
	}

	if(strcmp(C_SVALUE,"continue")==0 ){
		GEN(JMP,-1,-1,ContinueStack[WhileLevel-1],NULL);
	}
	else
		GEN(JMP,-1,-1,BreakStack[WhileLevel-1],NULL);

	/*����������*/
	igSymPos ++;
	
	if(C_CVALUE!=';'){
		ReportExprError(C_ORIPOS,
			"�������->����������ӦΪ';',��������%s,",C_SVALUE);
		return -igSymPos;
	}		
	/*����ֺ�*/	
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

	/*��ȡ��һ������*/
	td=VarAddrStack[(*pvp)--];

	switch(SymStack[*psp].iType){
	case TYPE_LOG1: /*�߼��ǵ��߼���Ŀ����,
		 !x ���ߡ�~x,��ֱ�ӽ�ջ����Ϊd1*/
		d1=td;
		d2=-1;
	break;
	case TYPE_MATH1:/*������Ŀ����, 
		-5 ���ߡ�+10��,����һ��d1,����ջ����Ϊd2*/
		d1= GetVarOffset(NULL);
		CHECKVAROFFSET(d1);
		/*���ݲ�����������һ������0�򸡵�0*/
		if(CODE_VARBUF[td].cType==VARTYPE_INT){
			CODE_VARBUF[d1].cType=VARTYPE_INT;
			CODE_VARBUF[d1].u.iValue=0;
		}
		else if(CODE_VARBUF[td].cType==VARTYPE_DOUBLE){
			CODE_VARBUF[d1].cType=VARTYPE_DOUBLE;
			CODE_VARBUF[d1].u.dValue=0;
		}
		else{/*�����﷨������ֱ������*/
			CODE_VARBUF[d1].cType=VARTYPE_UNK;
			CODE_VARBUF[d1].u.sValue=NULL;
		}
		d2=td;
	break;
	default:/*����˫Ŀ��������,
		4-9,��ջ����d2,����ȡһ��ջ����Ϊd1*/
		d2=td;
		if((*pvp)<=0) return -igSymPos;	
		/*��ȡ����һ������*/
		d1=VarAddrStack[(*pvp)--];
	break;
	}
	
	r = GetVarOffset(NULL);
	CHECKVAROFFSET(r);
	GEN(SymStack[(*psp)--].sValue[0],d1,d2,r,NULL);

	/*�������ַ��ջ*/
	VarAddrStack[++(*pvp)] = r;	
	return 0;
}
int InitConstVar(char type,int i,char sSymbolVal[])
{
	char	sTemp[256];
	switch(type){
	case TYPE_CONST:
		/*������Բ���iParam��LoadViant����*/
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
		ReportExprError(C_ORIPOS,"�������->%s�����ǳ���",C_SVALUE);
		return -igSymPos;
	}
	return 0;
}
/*���� <���ʽ> */
int ProcExpr(int iResultAddr)
{
	int    i,iEndFlag,iSymPos1,iConstFunFlag=false;
/*�����ջ������ջ��ջ��ָ��,ջ��ʱΪ��,��һ���ջ��ջ���һ*/
	int vp,sp;
	int VarAddrStack[1000];
	struct SymbolStruct SymStack[200];

	vp=sp=0;
	iEndFlag=0;
	
	if(C_TYPE==TYPE_SFUN) iConstFunFlag=true;

	iSymPos1=igSymPos;

/*	ϵͳ��������ʱ���������� �����CodeFlow�е�sValue
	���������CodeFlow�е�cValue�������ָ��ַ��������ַ����������ʽ�ַ�
*/

	while(!iEndFlag){
		switch(C_TYPE){
		case TYPE_SYSVAR:
		case TYPE_TEMPVAR:
			i = GetVarOffset(C_SVALUE);
			CHECKVAROFFSET(i);
			VarAddrStack[++vp] = i;
		break;
		case TYPE_MODALITY_PARA:/*���βθ�ֵ��ͨ����������ϢҲ����*/
			/*�β�����ͨ����ProcFunStatement�м�⣬���������*/
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
			/*�ڸú������ڲ��Ѿ������˷�����ֵ����*/
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
/*�������ﺯ���ڲ��Ѿ�ָ����һ������������Ҫ��continue*/
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
			case ')':/*����)����ݵ�(,�����м�Ĺ����������ɴ���*/
				while(sp>0&&SymStack[sp].sValue[0]!='(')
					if(ProcExprStack(&vp,VarAddrStack,
					&sp,SymStack)<0) return -igSymPos;
				
				/*���� '('�˳�,'(' ��ƥ��,��ջ*/
				if(sp>0) sp--;
				else	iEndFlag=1;  /* ')' �� '('ƥ��,����*/
			break;
			default:
				while(sp>0&&GetSymPri(
			SymStack[sp].sValue[0])>=GetSymPri(C_CVALUE))
					if(ProcExprStack(&vp,VarAddrStack,
					&sp,SymStack)<0) return -igSymPos;
				/*���Ž�����ջ*/
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
					"�﷨����->�����Ƿ��ַ�%s,�Ƿ���',',';',')'",
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

		/*��ȡ��һ������*/
		igSymPos++;
	}/*end while(!iEndFlag*/

	/*�����һ��ָ��������ַ��ΪiResultAddr*/
	if( (vp!=1) || (sp !=0) ){
		ReportExprError(C_ORIPOS,"�﷨����->���ʽ����");
		return -igSymPos;
	}
	/*������ʽ����һ�����N������ɵĳ���������
			�����һ������������;
		�����ɸ�ֵ���뽫������ֵ�������ֵ��ַ,
	�����򽫱��ʽ�����һ���м����������ֱַ���޸�Ϊ�����ַ*/

	if((igSymPos-iSymPos1)==1||iConstFunFlag==true||
		strchr("+-*/^%12345678|&!=",CODE_FLOW[igCodePos-1].op)==NULL){
		GEN('=',VarAddrStack[vp--],-1,iResultAddr,NULL);
	}
	else	ModifyResultAddr(igCodePos-1,iResultAddr);

/*	ֱ���޸ĵ�ַ����ȫ�����ɸ�ֵ�������Ժ�
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
/*	��Ԫ�� 
	���ɴ��룬�����������Ϊ����������������1��������2��Ŀ�Ĳ�������������Ϊ-1��ʾ�ò�����������*/
int Gen(char cOp,int iData1,int iData2,int iResultAddr,
	int (*Oper)(int d1,int r))
{
	
	CODE_FLOW[igCodePos].Oper=Oper;
	CODE_FLOW[igCodePos].op = cOp;
	CODE_FLOW[igCodePos].data1 = iData1;
	CODE_FLOW[igCodePos].data2 = iData2;
	CODE_FLOW[igCodePos].result = iResultAddr;
	CODE_FLOW[igCodePos].iSymPos = igSymPos;
    /*���Ŀ�ĵ�ַΪϵͳ����,����ϵͳ�����*/
	
	if(ReportSysVarModify(cOp,iResultAddr)<0){
		ReportExprError(C_ORIPOS,"�﷨����->ϵͳ����̫�࣬����%d",
			SYSVAR_COUNT);
		return -1;
	}

	igCodePos++;
	if(igCodePos>=CODE_BUFLEN){
		ReportExprError(C_ORIPOS,"�﷨����->���볤�ȳ���%d",
			CODE_BUFLEN);
		return -1;
	}
	return 0;
}

/* �޸�iPos��Ԫʽ�Ľ����ַƫ�� */
void ModifyResultAddr(int iPos,int iResultAddr)
{
	CODE_FLOW[iPos].result = iResultAddr;	
	ReportSysVarModify(CODE_FLOW[iPos].op,iResultAddr);
}
void SetJmpAddr(int iJmpCodeAddr,int iJmpTargetAddr)
{
	CODE_FLOW[iJmpCodeAddr].result = iJmpTargetAddr;
}
/* ȡ�ò�������Ӧ�����ȼ� */
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
/*���빫ʽʱʹ�ã�������Ч��
	sVar = NULL ����һ����ʱϵͳ��������������VarBuf�е�ƫ�� 
	sVar != NULL ���ҹ�ʽ���ݿ����Ƿ����sVar
		������������ 
		���ھͷ����������е�ƫ��(��λ��)*/
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
			ReportExprError(C_ORIPOS,"�﷨����->ϵͳ����̫�࣬����%d",
				SYSVAR_COUNT);
		else if(iSysTmpCnt>=SYSVAR_COUNT*2)
			ReportExprError(C_ORIPOS,"�﷨����->׼ϵͳ����̫�࣬����%d",
				SYSVAR_COUNT*2);
		else
			ReportExprError(C_ORIPOS,"�﷨����->��ʱ����̫�࣬����%d",
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
			/*��ò��������ر�������*/
		pSysSeg[i].iParam=CheckSysVar(sVar,&(pDataSeg[i].cType));
		pDataSeg[i].iParam=pSysSeg[i].iParam;
		if(pDataSeg[i].iParam<0){
			
			ReportExprError(C_ORIPOS,"�﷨����->����%s,У��δͨ��",sVar);
			return -1;
		}
		if(pDataSeg[i].cType==VARTYPE_STR){
			if((p=(char*)MallocVarchar(DEF_STR_LEN+1))==NULL){
               			ReportExprError(C_ORIPOS,
               				"Ϊϵͳ����%s���������ڴ�ʧ��",sVar);
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

	/**����ֻ����ʱ������**/	
	for(i=SYSVAR_COUNT;i<iSysTmpCnt;i++)
		if(strcmp(pSysSeg[i].sSymbol,sVar)==0)
			return pSysSeg[i].iIndex;
	
	strcpy(pSysSeg[i].sSymbol,sVar);
	pSysSeg[i].iParam=0;
	pSysSeg[i].LoadVariant = DefLoadVariant;
	pSysSeg[i].SaveVariant = DefSaveVariant;
	
	pSysSeg[i].iIndex=	iTmpVarCnt;

	if((pTemp=malloc(sizeof(struct ExprBinStruct)))==NULL){
                WriteAlertMsg("�����ڴ��EXPR_TREEʧ��");
		return -1;
	}
	pTemp->pNext=NULL;
	strcpy(pTemp->sName,sVar);
	pTemp->iVarInd=	iTmpVarCnt;
	pTemp->iSymInd= iSysTmpCnt;

	if(InsertBin(&(pText->pRoot),(void *)pTemp,
		data_search_expr_bin_e,
		assign_insert_bintree)<0){
                WriteAlertMsg("����BINTREEʧ��EXPR_TREE");
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
			ReportExprError(i,"�ʷ�����->Cע��->δƥ��'*/'��ʽ����");
			return -1;
		}
		while(!CommentCEnd(sInput[i],sInput[i+1])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->Cע��->δƥ��'*/'��ʽ����");
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
			ReportExprError(i,"�ʷ�����->Cppע��->��ʽ����");
			return -1;
		}
		while(!NewLine(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->Cppע��->��ʽ����");
				return -1;
			}
		}
		i++; /*�����س�*/
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
			ReportExprError(i,"�ʷ�����->#ע��->��ʽ����");
			return -1;
		}
		while(!NewLine(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->#ע��->��ʽ����");
				return -1;
			}
		}
		i++; /*�����س�*/
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
			/*unix�º�dos�µ��ַ������ڵ�����֧��*/
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
			"ϵͳ����->���ű�������%d��",SYMBOL_BUFLEN);
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
			ReportExprError(i,"�ʷ�����->������->��ʽ����");
			return -1;
		}
		while(!ConstStringEnd(sInput[i],pin[1])){

			/*����ָ��ת���ַ�*/
			if(strncmp(sInput+i,pin,2)==0)i+=2;
			else i++;

			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->������->��ʽ����");
				return -1;
			}
		}
		i++; /*����"��*/
		
		/*������ű�*/
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
			ReportExprError(i,"�ʷ�����->������->��ʽ����");
			return -1;
		}
		while(ConstDecNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->������->��ʽ����");
				return -1;
			}
		}
		
		if(sInput[i]!='.'){
			/*������ű�*/
			ADDSYMBOLFLOW(sInput,*piPos,i-(*piPos),TYPE_CONST_DEC);
		
			*piPos=i;
			return true;
		}
		/*����С����*/
		i++;
		while(ConstDecNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->������->��ʽ����");
				return -1;
			}
		}

		/*������ű�*/
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
			ReportExprError(i,"�ʷ�����->��HEX����->��ʽ����");
			return -1;
		}
		while(ConstHexNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->��HEX����->��ʽ����");
				return -1;
			}			
		}

		/*������ű�*/
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
			ReportExprError(i,"�ʷ�����->��BIN����->��ʽ����");
			return -1;
		}
		while(ConstBinNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->��BIN����->��ʽ����");
				return -1;
			}			
		}

		/*������ű�*/
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
	/*����Ǻ��־Ͳ������һ���ַ�*/
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
			ReportExprError(i,"�ʷ�����->��ʶ��->��ʽ����");
			return -1;
		}
		while(IdentifyNext(sInput[i-1],sInput[i])){
			
			/*���־�����һ���ַ�*/
/*			if(sInput[i-1]&0x80){
				i++;
				if(ExprEnd(sInput[i])){
					ReportExprError(i,"�ʷ�����->��ʶ��->��ʽ����");
					return -1;
				}
			}
*/
			i++;
			
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"�ʷ�����->��ʶ��->��ʽ����");
				return -1;
			}		
		}

		strncpy(sTemp,sInput+(*piPos),i-(*piPos));
		sTemp[i-(*piPos)]=0;
		
		/*������ű�*/
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

	/*����һ��*/
	iSymPos--;
	
	/*ȥ��ǰ���Ļ���*/
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
			/*�ж��ǵ�Ŀ�������������������˫Ŀ��������ӣ�����
		          ˫Ŀ���������������������ģ�
		          ��������һ�����������������������ı��ʽ��
		          ����ж���˫Ŀ�����ֻ�ж�ǰ���Ƿ������������
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
		/*������Ҫ�޸�ori_pos*/
		SymbolFlow[igSymPos-1].iOriPos= i-1;
		
		return true;
	}
	return false;
}
/*�ʷ�����,���ɾ��ж�������ķ����� SymbolFlow*/
int Lexicalize(char sInput[])
{
	int i=0,iRet,iInputLen;
	
	iInputLen=strlen(sInput);
	
	igSymPos=0;
	while(i<iInputLen){
		
		while(JmpSeperator(sInput[i])&&!ExprEnd(sInput[i])) i++;

		if(ExprEnd(sInput[i])) break;
	
/*���д���һ�������ں궨��*/
		if(strncmp(sInput+i,"\\\n",2)==0){i+=2;continue;}
		if(strncmp(sInput+i,"\\\r\n",3)==0){i+=3;continue;}
/*����C����ע��*/
		if((iRet=LexCComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*����C++ע��*/
		if((iRet=LexCppComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;

/*����Shע��	if((iRet=LexShComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;
*/
/*�������ַ���*/
		if((iRet=LexConstString(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*������ʮ��������*/
		if((iRet=LexConstHexNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*��������������*/
		if((iRet=LexConstBinNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*������ʮ������*/
		if((iRet=LexConstDecNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*�����ʶ��*/
		if((iRet=LexIdentify(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*����ָ��*/
		if((iRet=LexSeperator(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*����"+,-,*,/"��������*/
		if((iRet=LexMath(sInput,&i))<0) return -1;
		if(iRet==true) continue;
		
/*����">,<,=,!,|,&"�߼�����*/
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

/*	ȡ��sSymbol������ 
	ϵͳ����	TYPE_SYSVAR
	��ʱ����	TYPE_TEMPVAR
	����		TYPE_CONST
	���Ʒ���	TYPE_CONTROL
*/
int GetSymType(char sSymbol[])
{
	int i;
	struct ExprVarStruct *pTemp;
	struct ExprFunStruct *pFun;
	
	for(i=0;i<igReserveCount;i++)
		if(strcmp(ReserveSymbol[i].sSymbol,sSymbol)==0)
			return ReserveSymbol[i].iType;
/*���ϵͳ����ע������*/
	if(SearchRegVarLink(sSymbol,&pTemp)==FOUND)  return TYPE_SYSVAR;
/*������ú���ע������*/
	if(SearchRegFunLink(sSymbol,&pFun)==FOUND){
		if(pFun->cFunctionType==DFUN)return TYPE_DFUN;
		return TYPE_SFUN;
	}
/*�Զ����ֶα���*/
/*	if(strncmp(sSymbol,"it_",3)==0||
		strncmp(sSymbol,"pt_",3)==0||
		strncmp(sSymbol,"st_",3)==0) return  TYPE_SYSVAR;
*/
/*����涨����Բ��Ϊ����*/
	if(sSymbol[0]=='$') return TYPE_TEMPVAR;
	
/*���⴦�������������Ϊ����*/
	if(sSymbol[0]&0x80) return TYPE_CONST;
	
	return TYPE_TEMPVAR;
}



int OutputCompileError(char sInput[])
{
	int i,iPos,iErrPos,iLastNewLine;
					
	printf("��ʽ����ʧ��!\n");
	
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
	
/*����һ�㺯��*/
	if(SearchDefFun(C_SVALUE,&CURR_FUNP)==NOTFOUND){
		ReportExprError(C_ORIPOS,"�������->����%sδ����",C_SVALUE);
		/*���⺯������������*/
		if(igSymPos==0) igSymPos++;
		return -igSymPos;
	}

	igSymPos++;/*��������������*/

/*����һ��ǿ����ת���*/
	GEN(JMP,-1,-1,-1,NULL);
	iJmpCodeAddr=igCodePos-1;
	
	/*��¼�������õĵ�ַ*/
	CURR_FUNP->iCodeAddr= igCodePos;
	/*����һ����������*/
	if(ProcStatementBlock()<0) return -igSymPos;
	
/*����Ҫ������û��return��䣬
	�����÷���ֵΪĬ����ֵ��������
	��Ҫ���һ��,����һ��POPIP��ָ��
*/
	if(CODE_FLOW[igCodePos-1].op!=OPSP){
		GEN(OPSP,P_OP_CALL,ADDR_VARIANT,CURR_FUNP->iParamCnt+
			MAXVAR_COUNT,clear_variant);
		GEN(OPSP,P_OP_POP,ADDR_REGISTER,REGISTER_IP,NULL);
	}
	
	/*������ת�����ַ*/
	SetJmpAddr(iJmpCodeAddr,igCodePos);
	
	CURR_FUNP=NULL;

	return 0;
}
/***
����:
BP=6096;
SP=6100;
����ԭ�ͣ�
int FUN1(int ,string );
���������: FUN1(1,"abc");
���ɴ�������:

���ɲ���1�Ĵ���; 
���ɲ���2�Ĵ���;
PUSH BP;SP=6101,BP=6096
BP=SP;	BP=6101;
PUSH P1 SP=6102
PUSH P2 SP=6103
PUSH RET ����ǿյ�; SP=6104
CALL FUN1 {
		PUSH IP SP=6105
		JMP ADDR OF FUN1;
	  }
	  SP=6105
//===>SP=SP-N-2 ==> SP=6101
	ע���ڲ���return ����һ�� pop����.
POP iResultAddr; SP=6103
SP=BP;		 SP=6101
POP BP	  ==> SP=6100,BP=6096;

	d1	d2		r	Oper
p	1 push	0 addr		��ַ	NULL
	2 pop	1 register	��ַ	NULL
	3 ������� -1		-1��	���ú���;;
c	CALL
	d1  ����,d2��Լ��, r ����ֵ��ַ,����iCodePos�ڷ���ֵ��.iParam��;;
======================�������õĶ�ջ�����=======================
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
	
/*����һ�㺯��*/
	if(SearchDefFun(C_SVALUE,&pTemp)==NOTFOUND){
		ReportExprError(C_ORIPOS,"�������->����%sδ����",C_SVALUE);
		return -igSymPos;
	}

	igSymPos++;/*����������*/
	
	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!='('){
		ReportExprError(C_ORIPOS,
			"�������->����%s��ӦΪ(,��������%s",
			pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*����'('��*/

/*��������Լ��*/
	iAddr2=		GetVarOffset(NULL);
	CHECKVAROFFSET(iAddr2);
	CODE_VARBUF[iAddr2].cType=VARTYPE_STR;

	iParamCnt=pTemp->iParamCnt;

	sFunType[0]=pTemp->cType;
	strcpy(sFunType+1,pTemp->sType);
	AssignStrchar2Varchar(&(CODE_VARBUF[iAddr2].u.sValue),sFunType);

	if(iResultAddr==-1){
	/*������ֵ�����ַ*/
		iResultAddr = GetVarOffset(NULL); 
		CHECKVAROFFSET(iResultAddr);
	}

	/*���ú����ķ���ֵ*/
	CODE_VARBUF[iResultAddr].cType= pTemp->cType;
	CODE_VARBUF[iResultAddr].iParam=pTemp->iCodeAddr;

	
	/*������ʱ��ʵ�ʲ�������������d2.iParam��*/
	CODE_VARBUF[iAddr2].iParam=iParamCnt;

	/*������������ַ�����,Ϊ�˱�֤������
		���ȷ��������ɸ��������Ĵ���*/
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
			WriteAlertMsg("����%s�ĵ�%d���������Ͳ�ƥ��%c->%c",
				CODE_VARBUF[j].cType,
				pTemp->sParamConstraint[i]);
			return -igSymPos;
		}
*/	
		i++;
		if(i==iParamCnt) break;
			
		if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=','){
			ReportExprError(C_ORIPOS,
				"�������->����%s������ӦΪ',',��������%s",
					pTemp->sName,C_SVALUE);
			return -igSymPos;
		}
		igSymPos++;/*����','��*/
	}
	if(C_TYPE!=TYPE_SEPARATOR&&C_CVALUE!=')'){
		ReportExprError(C_ORIPOS,
			"�������->����%s��������ӦΪ')',��������%s",
				pTemp->sName,C_SVALUE);
		return -igSymPos;
	}
	igSymPos++;/*����')'��*/
/*������,�������õĲ���ͨ����ֵ���뱻����iParamAddr-iParamCnt+1->iParamCnt��*/
/*
P	1 push	0 addr		��ַ
	2 pop	1 register	��ַ(1=IP;2=BP,3=SP)
*/
	GEN(OPSP,P_OP_PUSH,ADDR_REGISTER,REGISTER_BP,NULL);
	GEN(OPSP,P_OP_CALL,-1,-1,mv_sp2bp);
	/*��N��������ջ*/
	i=0;
	while(i<iParamCnt){
		j=iParamAddr-iParamCnt+i+1;
		GEN(OPSP,P_OP_PUSH,ADDR_VARIANT,j,NULL);
		i++;
	}
	GEN(OPSP,P_OP_PUSH,ADDR_VARIANT,iResultAddr,NULL);
	
	/*����ָ���ĺ������ô������*/
	GEN(FUN,iParamAddr-iParamCnt+1,iAddr2,iResultAddr,NULL);
	
	/*����POP iResultAddr�Ĵ���*/
	GEN(OPSP,P_OP_POP,ADDR_VARIANT,iResultAddr,NULL);

	/*����POP��N�������Ĵ���*/
	GEN(OPSP,P_OP_POP,ADDR_VARIANT,-iParamCnt,NULL);
	
	/*����POP��BP�Ĵ���*/
	GEN(OPSP,P_OP_POP,ADDR_REGISTER,REGISTER_BP,NULL);
	
	return 0;
}
