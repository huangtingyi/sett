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
	struct LSymbolStruct  *pSymBgn;	/*>= ���*/
	struct LSymbolStruct  *pSymEnd;	/*< ���*/
};
struct BlockDefStruct
{
	struct  BlockDefStruct *pNext;
	char	sName[128];	/*����ע��*/
	char	cType;		/*��������ֵ����*/
	int	iCodeAddr;	/*����Ŀ������ַ*/
	int	iParamCnt;
	char	sType[32];	/*��������,�Ǻ��ʱ���Ϊδ����*/
	struct	ParamDefStruct pa[32];/*�����б�*/
	struct  LSymbolStruct *pHead; /*�궨���ͷ*/
	struct 	LSymbolStruct *pBody; /*���壬�β��滻Ϊtype=para,value="%d"*/
};

int AssignLSymHead(struct LSymbolStruct **pptHead,struct LSymbolStruct *p);
int AssignLSymTail(struct LSymbolStruct **pptHead,struct LSymbolStruct *p);
void PrintLSymList(struct LSymbolStruct *ptHead);

/*����һ���궨��*/
int SearchBlockDef(struct BlockDefStruct *ptHead,char sName[],
	struct BlockDefStruct **pptCur);
void DestroyBlockDef(struct BlockDefStruct *ptHead);
/*���Ԥ��������*/
int ChkPropCond(char sSymbol[],struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pDef);

/*֧��Ԥ���빦�ܵ�������䴦��*/
int PropStatement(struct LSymbolStruct *pTemp,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,
	int iFlag,char sMsg[]);
int PropNormalLines(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,
	char sMsg[]);
/*����#ifdef �� #ifndef ���*/
int PropIfStatement(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,char sMsg[]);

int PropIncludeStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[]);

/*��ȡһ���궨�������֧��*/
int GetHeadListComm(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[]);
/*�����ʽ��������̬������Ϊһ����ʶ������ʽ�����򱨴���*/
int CheckModalityParam(char sName[],int iCnt,struct ParamDefStruct pa[],
	char sMsg[]);
/*��ȡ�궨���ͷ*/
int GetMicroHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[]);
/*��ȡ�궨�������*/
int GetMicroRef(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[]);

/*֧�ֻ�ȡ�궨����,��ȡ�ʷ������һ��*/
int GetSymLine(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[]);
/**��ȡһ���궨����*/
int GetMicroBody(struct LSymbolStruct *ptHead,int iCnt,struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[]);
/*��չ������*/
int DeployMicroStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pItem,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[]);
/*��һ���б���к�չ��������չ�����׷�ӵ�ָ���б�*/
int DeployMicroList(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,char sMsg[]);
/*����궨�����*/
int PropDefineStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,int iFlag,char sMsg[]);

/*��ȫ�ַ��ű���������*/
int MoveSymbolFlowToLSymbolList(struct LSymbolStruct **pptHead);
/*�������Ƶ�ȫ�ַ��ű����ͷ�����*/
int MoveLSymListToSymbolFlow(struct LSymbolStruct *ptHead);

/*��֧��Ԥ���빦�ܵ��ļ��ʷ�����*/
int FileLexicalize(char sFileName[],char sMsg[]);
/*��Ԥ���빦�ܵĶ�һ�����Ĵʷ�����*/
int PropLexicalize(char sInput[],char sMsg[]);
/*��Ԥ���빦�ܵĶ�һ���ļ��Ĵʷ�����*/
int FilePropLexicalize(char sFileName[],char sMsg[]);


extern struct BlockDefStruct *pDefFun,*pCurFun;
#define CURR_FUNP pCurFun

/*��ȡһ������*/
int GetSymBlock(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[]);
int SearchBlockDefByAddr(struct BlockDefStruct *ptHead,int iCodeAddr,
	struct BlockDefStruct **pptCur);
int SearchDefFunByAddr(int iCodeAddr,char sName[]);

void DeleteLSymListLrn(struct LSymbolStruct **pptHead);
/*�ж�һ������Ƿ�Ϊ�����������,����Ҫ���ǻس����е�����*/
int IsFunDefStatement(struct LSymbolStruct *ptHead,char sName[]);
int GetFunParamType(struct LSymbolStruct *pTemp,char sName[],
	int i,char *pcType,char sMsg[]);
/*��ȡһ�������ļ�ͷ����*/
int GetFunDefHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sName[],char *pcType,char asType[],
	struct ParamDefStruct pa[],char sMsg[]);
/*��ȡһ�������嶨��*/
int GetFunDefBody(struct LSymbolStruct *ptHead,char sName[],
	int iCnt,char asType[],struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[]);
/*����һ������������*/
int PropFunDefStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppTail,
	char sMsg[]);
int BlockParamMatch(struct BlockDefStruct *p1,struct BlockDefStruct *p2,
	char sMsg[]);
int SearchDefFun(char sSymbol[],struct BlockDefStruct **pptCur);
int PropFunDefList(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,char sMsg[]);


#endif

