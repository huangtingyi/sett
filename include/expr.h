#ifndef __EXPR_H__
#define __EXPR_H__

#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwcoding.h>
#include <bintree.h>


/*#define DEBUG_EXPR*/
#define TYPE_LOG1		1
#define TYPE_LOG2		2
#define TYPE_MATH		3
#define TYPE_CONTROL		4
#define TYPE_CONST		5
#define TYPE_SYSVAR		6
#define TYPE_TEMPVAR		7
#define TYPE_SEPARATOR		8
#define TYPE_ASSIGN		9
#define TYPE_MATH1		10
#define TYPE_CONST_STR		11
#define TYPE_CONST_HEX		12
#define TYPE_CONST_DEC		13
#define TYPE_CONST_BIN		14
#define TYPE_SFUN		15
#define TYPE_DFUN		16
#define TYPE_CONST_DOUBLE	17
#define TYPE_CONST_LONG_STR	18/*���ַ���*/
#define TYPE_MODALITY_PARA	19/*��ʽ����*/
#define TYPE_PRECOMP_CONTROL 20/*#ifdef#ifndef#if#else#endif#define#include*/
#define TYPE_DECLARE		21/*int,string,point,double,struct*/
#define TYPE_MICRO		22
#define TYPE_FUN		23


#define MOVE			'm'
#define JMP			'j'
#define JMPF			'J'
#define RET  			'r'
#define ADD			'+'
#define SUB			'-'
#define MULTI			'*'
#define DIV			'/'
#define SQR			'^'
#define MOD			'%'
#define GT			'1'
#define LT			'2'
#define GE			'3'
#define LE			'4'
#define EQ			'5'
#define NE			'6'
#define MOR			'7'
#define MAND			'8'
#define OR			'|'
#define AND			'&'
#define NOT			'!'
#define ASSIGN			'='
#define DFUN			'f'
#define SFUN			'F'
#define OPSP			'p'
#define FUN			'c'

#define SYSVAR_COUNT	600
#define MAXVAR_COUNT	6000
#define MAXSTACKLEN	600	/*�����ջ����*/

#define SYMBOL_LENGTH	255
#define CODE_BUFLEN	3000
#define SYMBOL_BUFLEN	6000
#define WHILE_STACK	256
#define EXPRLEN		32768

/*�������ɵ���Ԫ��ṹ*/
struct CodeStruct{
	int (*Oper)(int d1,int r);
	char op;
	int  data1;
	int  data2;
	int  result;
	int  iSymPos;
};

/*����ʷ��������ɵķ�����*/
struct SymbolStruct{
	char sValue[SYMBOL_LENGTH+1];
	int  iType;
	int  iOriPos;
};


/*����ϵͳ�ı����ּ������ֵ�����*/
struct ReserveKeywordStruct{
	char sSymbol[SYMBOL_LENGTH+1];
	int  iType;
};

/*���幫ʽ���뼰����洢�ṹ*/

  /*����ṹ*/
struct OutputExprStruct{
	char sSymbol[SYMBOL_LENGTH+1];
	int  iOffset;
	char cType;/*'1':����,'2':�ַ���,'0':δ֪����,'3':ָ��,'4'�ṹ*/
	union{
		int	iValue;
		char	sValue[4096];
		char	*pValue;
		double	dValue;
	} u;
			/*��������Ĳ���*/
	int  iParam;
	void (*SaveVariant)(int,void *pi);
};
struct SymVarStruct
{
	char sSymbol[SYMBOL_LENGTH+1];
	char cModified; /*0 :clean, 1:loaded,  2:modified*/
/*��������,����ʱ������ַ����������Ĳ�������ʱ����û�ã�*/
	int  iParam;
/*���ر�������---���빫ʽʱ���صĺ�������ʱ����û�ã�*/
	void (*LoadVariant)(int,void *pi);
/*�Ƿ���ر�ʶ*/
	void (*SaveVariant)(int,void *pi);
	int	iIndex;		/*���ű��Ӧ�����ڱ�����������*/
};
  /*��������ṹ*/
struct VariantStruct{
	char cType;/*'1':����,'2':�ַ���,'0':δ֪����,'3':ָ��,'4'�ṹ,'5'����*/
	union{
		int	iValue;
		char	*sValue;
		char	*pValue;
		double	dValue;
	} u;
	int	iParam;	/*ϵͳ��������,�����ֶ�*/
	int	iIndex;	/*�����ڷ��ű��е�λ������*/
};
  
/*��ʽ�ṹ*/
struct ExprBufStruct{
	struct CodeStruct *CodeBuf;        /* ִ�д��뻺���� */
	int iCodeCnt;                                  /* �������� */
	struct VariantStruct *VarBuf;
	struct SymVarStruct  SysBuf[SYSVAR_COUNT*2]; 
/* ��������洢��,ǰһ����(0->SYSVAR_COUNT-1)Ϊϵͳ��������
            ��һ����Ϊ��ʱ������*/
	int iSysVarCnt;				/*ϵͳ��������*/
	int iTmpVarCnt;				/*��ʱ��������*/
	int iSysTmpCnt;				/*׼ϵͳ��������*/
	int STACK_BP;				/*��ջ����ַ*/
	int BP;
	int SP;
	struct VariantStruct r;			/*���巵��ֵ*/
	struct OutputExprStruct *OutputBuf;     /*�����*/
	int	iOutputLen;                     /*�������*/
	int	iPos;
	char	sErrorMsg[8192];
	BINTREE *pRoot;
};

/*����ԭ��*/
int GetSymType(char sSymbol[]);
void InitReserveSymbol();
int Lexicalize(char sInput[]);
int GenerateCode();
int ProcStatementBlock();
int ProcComplexStatement();
int ProcStatement();
int ProcAssignStatement();
int ProcConditionStatement();
int ProcControlStatement();
int ProcWhileStatement();
int ProcFunctionStatement(int iResultAddr);
int ProcExpr(int iResultAddr);
int Gen(char cOp,int iData1,int iData2,int iResultAddr,
	int (*Oper)(int d1,int r));
int GetVarOffset(char * sVar);
int GetSymPri(char cSym);
void ModifyResultAddr(int iPos,int iResultAddr);
void SetJmpAddr(int iJmpCodeAddr,int iJmpTargetAddr);

int GetIntVariant(struct VariantStruct *pDataSeg,int iOffset);
char *GetAddrVariant(struct VariantStruct *pDataSeg,int iOffset);
char *GetStrVariant(struct VariantStruct *pDataSeg,int iOffset);
char *GetPointVariant(struct VariantStruct *pDataSeg,int iOffset);
double GetDoubleVariant(struct VariantStruct *pDataSeg,int iOffset);


/****************�ⲿ���ýӿ�API**********************/
int ExecCode(struct ExprBufStruct *pText);
int CompileExpr(char sInput[],struct OutputExprStruct asVarOutput[],
	int * piOutputLen);


extern int igSymCnt;   /*����������*/
extern int igSymPos;   /*��������ǰָ��*/
extern int igReserveCount;  /*�����ָ���*/
extern struct SymbolStruct     SymbolFlow[SYMBOL_BUFLEN];

extern int igCodePos;       /*�������ĵ�ǰλ��ָ��*/
extern int WhileLevel,ContinueStack[WHILE_STACK],BreakStack[WHILE_STACK];
extern struct ExprBufStruct ExprBuf;
extern struct ExprBufStruct *pExprBuf;

/*ִ�й�ʽʱ������������,Ч��Ҫ���*/	
extern void (*LoadVariant)(int,void *pi);
extern void (*SaveVariant)(int,void *pi);
/*���빫ʽʱ�������ֲ��ҵĳ���ֵ������������Ч��*/
extern void (*LoadConst)(char sVar[],char *pcType,void *pi);
/*���˹�ʽʱ��λϵͳ������������MeLoadVariant��ֵ�ĺ�����
	ͬʱ���ز����������ɾ����MeLoadVariant����	*/
extern int (*CheckSysVar)(char sVar[],char *pcType);

#define C_TYPEP		SymbolFlow[igSymPos-1].iType
#define C_TYPEN		SymbolFlow[igSymPos+1].iType
#define C_CVALUEP 	SymbolFlow[igSymPos-1].sValue[0]
#define C_CVALUEN 	SymbolFlow[igSymPos+1].sValue[0]
#define C_TYPE   	SymbolFlow[igSymPos].iType
#define C_SVALUE 	SymbolFlow[igSymPos].sValue
#define C_CVALUE 	SymbolFlow[igSymPos].sValue[0]
#define C_ORIPOS	SymbolFlow[igSymPos].iOriPos
#define CURR_EXPR 	(*pExprBuf)
#define CODE_FLOW 	pExprBuf->CodeBuf
#define CODE_OUTBUF 	pExprBuf->OutputBuf
#define CODE_VARBUF 	pExprBuf->VarBuf
#define CODE_SYSBUF	pExprBuf->SysBuf
#define CURORIPOS	SymbolFlow[CODE_FLOW[igCodePos].iSymPos].iOriPos
#define CURRORIPOS	SymbolFlow[CODE_FLOW[igCodePos-1].iSymPos+1].iOriPos

#define MY_BP		(pExprBuf->BP)
#define MY_SP		(pExprBuf->SP)
#define MY_AD(x)	((x)<MAXVAR_COUNT?(x):(x-MAXVAR_COUNT)+MY_BP)
#define MY_STACK_BP	CURR_EXPR.STACK_BP
#define IS_SYSVAR(i)  ((i)>=0&&(i)<SYSVAR_COUNT?true:false)
#define IS_TMPVAR(i)  ((i)>=SYSVAR_COUNT&&(i)<MY_STACK_BP?true:false)
#define IS_PARAVAR(i) ((i)>=MY_STACK_BP&&(i)<MY_STACK_BP+MAXSTACKLEN?true:false)
#define IS_ADDR(i)    ((i)>=0&&(i)<CURR_EXPR.STACK_BP+MAXSTACKLEN?true:false)

#define IS_TMPSYSVAR(i) (IS_TMPVAR(i)?((CODE_VARBUF[i].iIndex!=-1)?true:false):false)
#define IS_TMPTMPVAR(i) (IS_TMPVAR(i)?((CODE_VARBUF[i].iIndex==-1)?true:false):false)

#define CHECK_AD(x)	\
	if((x)>=(MY_STACK_BP+MAXSTACKLEN)){\
		ReportExprError(CURORIPOS,"ϵͳ����->��ջ���");\
		return -1;\
	}
#define MY_PUSH_REG(x) {\
	CODE_VARBUF[CURR_EXPR.SP].cType=VARTYPE_INT;\
	CODE_VARBUF[CURR_EXPR.SP].u.iValue=(x);\
	CURR_EXPR.SP++;\
	}
#define MY_PUSH_ADDR(x) {\
	int sp=CURR_EXPR.SP;\
	CODE_VARBUF[sp].cType=CODE_VARBUF[x].cType;\
	if(CODE_VARBUF[x].cType==VARTYPE_INT)\
		CODE_VARBUF[sp].u.iValue=CODE_VARBUF[x].u.iValue;\
	else if(CODE_VARBUF[x].cType==VARTYPE_STR)\
		AssignV2VStrchar(&(CODE_VARBUF[sp].u.sValue),\
					CODE_VARBUF[x].u.sValue);\
	else if(CODE_VARBUF[x].cType==VARTYPE_DOUBLE)\
		CODE_VARBUF[sp].u.dValue=CODE_VARBUF[x].u.dValue;\
	else 	CODE_VARBUF[sp].u.pValue=CODE_VARBUF[x].u.pValue;\
	CURR_EXPR.SP++;\
	}
#define MY_POP_REG(x)  {\
	CURR_EXPR.SP--;\
	x=CODE_VARBUF[CURR_EXPR.SP].u.iValue;\
	}
#define MY_POP_ADDR(x) {\
	int sp=(--(CURR_EXPR.SP));\
	if(x>=0){	\
		if(CODE_VARBUF[x].cType==VARTYPE_INT)\
			CODE_VARBUF[x].u.iValue=CODE_VARBUF[sp].u.iValue;\
		else if(CODE_VARBUF[x].cType==VARTYPE_STR){\
			AssignV2VStrchar(&(CODE_VARBUF[x].u.sValue),\
					CODE_VARBUF[sp].u.sValue);\
			free(CODE_VARBUF[sp].u.sValue);\
			CODE_VARBUF[sp].u.sValue=NULL;\
		}\
		else if(CODE_VARBUF[x].cType==VARTYPE_DOUBLE)\
			CODE_VARBUF[x].u.dValue=CODE_VARBUF[sp].u.dValue;\
		else 	CODE_VARBUF[x].u.pValue=CODE_VARBUF[sp].u.pValue;\
	}\
	else{\
		int i=0;\
		while(1){\
			if(CODE_VARBUF[sp].cType==VARTYPE_STR){\
				free(CODE_VARBUF[sp].u.sValue);\
				CODE_VARBUF[sp].u.sValue=NULL;\
			}\
			if(x>=(--i)) break;\
			sp=(--(CURR_EXPR.SP));\
		}\
	}\
	}
#define REGISTER_IP	1
#define REGISTER_BP	2
#define REGISTER_SP	3
#define P_OP_PUSH	1
#define P_OP_POP	2
#define P_OP_CALL	3
#define ADDR_VARIANT	0
#define ADDR_REGISTER	1

/*********������������*/
int OutputCompileError(char sInput[]);
/*��ȡ��ʽ������ӿڱ���*/
int GetSysVar(struct ExprBufStruct *pText,int iResetFlag);

#define LABEL_STACK	100
struct LabelStruct
{
	char 	sLabel[SYMBOL_LENGTH+1];
	int	iTargetCodeAddr;
	int	iJmpCodeAddr;
};
void DisplaySysVar();
void DisplayCode();
void DisplaySymbolFlow();
int CheckCurCode();
int CheckCode();
struct ExprBufStruct *GetCompileResult();
int InitConstVar(char type,int i,char sSymbolVal[]);
int ProcDFunStatement(int iResultAddr);
int ProcSFunStatement(int iResultAddr);

struct	ExprBinStruct
{
	struct	ExprBinStruct *pNext;
	char sName[128];
	int iVarInd;
	int iSymInd;
};
int SearchExprBin(struct ExprBufStruct *p,char sName[],struct ExprBinStruct **pptCur);
void get_int_value(char sName[],struct ExprBufStruct *p,int *piValue);
void get_str_value(char sName[],struct ExprBufStruct *p,char sValue[]);
void set_int_value(char sName[],struct ExprBufStruct *p,int iValue);
void set_str_value(char sName[],struct ExprBufStruct *p,char sValue[]);
void set_point_value(char sName[],struct ExprBufStruct *p,void *pValue);
void set_double_value(char sName[],struct ExprBufStruct *p,double dValue);


void ReportExprError(int iPos,char *fmt,...);
void GetLinePosInfo(char sInput[],int iOff,int *piLine,int *piPos);
void FormatExprErrorMsg(char sInput[]);

void PushFileStack(char sFileName[]);
void EmptyFileStack();
int EncodingOriPos(int iOriPos);
void DecodingOriPos(int iOriPos,int *piIndex,int *piOriPos);
int ProcFunDefStatement();
int ProcFunStatement(int iResultAddr);
void DestroyExprBuf(struct ExprBufStruct *pExpr);

#endif
