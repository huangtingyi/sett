#ifndef __EXPR_FMP_H__
#define __EXPR_FMP_H__

struct LSymbolStruct
{
	struct LSymbolStruct *pNext;
	struct SymbolStruct s;	
};
struct ParamDefStruct
{
	struct ParamDefStruct *pNext;
	struct LSymbolStruct  *pSymBgn;	/*>= 这个*/
	struct LSymbolStruct  *pSymEnd;	/*< 这个*/
};
struct BlockDefStruct
{
	struct  BlockDefStruct *pNext;
	char	sName[128];	/*用于注册*/
	char	cType;		/*函数返回值类型*/
	int	iCodeAddr;	/*函数目标代码地址*/
	int	iParamCnt;
	char	sType[32];	/*参数类型,是宏的时候均为未定义*/
	struct	ParamDefStruct pa[32];/*参数列表*/
	struct  LSymbolStruct *pHead; /*宏定义的头*/
	struct 	LSymbolStruct *pBody; /*宏体，形参替换为type=para,value="%d"*/
};

int AssignLSymHead(struct LSymbolStruct **pptHead,struct LSymbolStruct *p);
int AssignLSymTail(struct LSymbolStruct **pptHead,struct LSymbolStruct *p);
void PrintLSymList(struct LSymbolStruct *ptHead);

/*查找一个宏定义*/
int SearchBlockDef(struct BlockDefStruct *ptHead,char sName[],
	struct BlockDefStruct **pptCur);
void DestroyBlockDef(struct BlockDefStruct *ptHead);
/*检查预编译条件*/
int ChkPropCond(char sSymbol[],struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pDef);

/*支持预编译功能的所有语句处理*/
int PropStatement(struct LSymbolStruct *pTemp,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,
	int iFlag,char sMsg[]);
int PropNormalLines(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,
	char sMsg[]);
/*处理#ifdef 或 #ifndef 语句*/
int PropIfStatement(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,char sMsg[]);

int PropIncludeStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[]);

/*获取一个宏定义或引用支持*/
int GetHeadListComm(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[]);
/*检查形式参数的形态，必须为一个标识符的形式，否则报错误*/
int CheckModalityParam(char sName[],int iCnt,struct ParamDefStruct pa[],
	char sMsg[]);
/*获取宏定义的头*/
int GetMicroHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[]);
/*或取宏定义的引用*/
int GetMicroRef(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[]);

/*支持获取宏定义体,获取词法链表的一行*/
int GetSymLine(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[]);
/**获取一个宏定义体*/
int GetMicroBody(struct LSymbolStruct *ptHead,int iCnt,struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[]);
/*宏展开调用*/
int DeployMicroStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pItem,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[]);
/*对一个列表进行宏展开，并将展开结果追加到指定列表*/
int DeployMicroList(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,char sMsg[]);
/*处理宏定义语句*/
int PropDefineStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,int iFlag,char sMsg[]);

/*将全局符号表导到链表中*/
int MoveSymbolFlowToLSymbolList(struct LSymbolStruct **pptHead);
/*将链表移到全局符号表，并释放链表*/
int MoveLSymListToSymbolFlow(struct LSymbolStruct *ptHead);

/*不支持预编译功能的文件词法解析*/
int FileLexicalize(char sFileName[],char sMsg[]);
/*带预编译功能的对一个串的词法分析*/
int PropLexicalize(char sInput[],char sMsg[]);
/*带预编译功能的对一个文件的词法分析*/
int FilePropLexicalize(char sFileName[],char sMsg[]);


extern struct BlockDefStruct *pDefFun,*pCurFun;
#define CURR_FUNP pCurFun

/*获取一个语句块*/
int GetSymBlock(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[]);
int SearchBlockDefByAddr(struct BlockDefStruct *ptHead,int iCodeAddr,
	struct BlockDefStruct **pptCur);
int SearchDefFunByAddr(int iCodeAddr,char sName[]);

void DeleteLSymListLrn(struct LSymbolStruct **pptHead);
/*判断一个语句是否为函数定义语句,不需要考虑回车换行的问题*/
int IsFunDefStatement(struct LSymbolStruct *ptHead,char sName[]);
int GetFunParamType(struct LSymbolStruct *pTemp,char sName[],
	int i,char *pcType,char sMsg[]);
/*获取一个函数文件头定义*/
int GetFunDefHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sName[],char *pcType,char asType[],
	struct ParamDefStruct pa[],char sMsg[]);
/*获取一个函数体定义*/
int GetFunDefBody(struct LSymbolStruct *ptHead,char sName[],
	int iCnt,char asType[],struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[]);
/*增加一个函数定义句句*/
int PropFunDefStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppTail,
	char sMsg[]);
int BlockParamMatch(struct BlockDefStruct *p1,struct BlockDefStruct *p2,
	char sMsg[]);
int SearchDefFun(char sSymbol[],struct BlockDefStruct **pptCur);
int PropFunDefList(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,char sMsg[]);


#endif

