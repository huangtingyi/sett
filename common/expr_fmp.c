#include <stdio.h>
#include <hnixs.h>
#include <wwdir.h>
#include <wwlog.h>
#include <list.h>
#include <expr.h>
#include <expr_supp.h>
#include <expr_fun.h>
#include <expr_fmp.h>

struct BlockDefStruct *pDefFun=NULL,*pCurFun=NULL;

/*分配内存，并加入词法分析链表的头部*/
int AssignLSymHead(struct LSymbolStruct **pptHead,struct LSymbolStruct *p)
{
	struct LSymbolStruct *pTemp;

	if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL) return -1;

	memcpy((void*)pTemp,(void*)p,sizeof(struct LSymbolStruct));

	InsertList((LIST**)pptHead,(LIST*)pTemp);

	return 0;
}
/*分配内存，并加入词法分析链表的尾部*/
int AssignLSymTail(struct LSymbolStruct **pptHead,struct LSymbolStruct *p)
{
	struct LSymbolStruct *pTemp;

	if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL) return -1;

	memcpy((void*)pTemp,(void*)p,sizeof(struct LSymbolStruct));

	InsertListTail((LIST**)pptHead,(LIST*)pTemp);

	return 0;
}
void PrintLSymList(struct LSymbolStruct *ptHead)
{
	int i=0,j;
	
	printf("------------------------------------------bgn\n");
	while(ptHead!=NULL){
		for(j=0;j<strlen(ptHead->s.sValue);j++)
			putchar(ptHead->s.sValue[j]);

		/*对于没有空行的句子间加上回车*/
		if((strcmp(ptHead->s.sValue,";")==0||
			strcmp(ptHead->s.sValue,"{")==0||
			strcmp(ptHead->s.sValue,"}")==0)&&
			ptHead->pNext!=NULL){

			if(strcmp(ptHead->pNext->s.sValue,"\n")!=0&&
				strcmp(ptHead->pNext->s.sValue,"\r")!=0)
				putchar('\n');
		}
	
		ptHead=ptHead->pNext;
		if(i++>1000) break;

	}
	printf("\n");
	printf("end------------------------------------------\n");
}
/*查找一个宏定义*/
int SearchBlockDef(struct BlockDefStruct *ptHead,char sName[],
	struct BlockDefStruct **pptCur)
{
	*pptCur=NULL;
	while(ptHead!=NULL){
		if(strcmp(sName,ptHead->sName)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void DestroyBlockDef(struct BlockDefStruct *ptHead)
{
	struct BlockDefStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		DestroyList((LIST*)pTemp->pHead);
		DestroyList((LIST*)pTemp->pBody);
		free(pTemp);
	}
}
/*检查预编译条件*/
int ChkPropCond(char sSymbol[],struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pDef)
{
	char sName[128];
	struct BlockDefStruct *pNoUse=NULL;

	strcpy(sName,ptHead->s.sValue);

	if(strcmp(sSymbol,"#ifdef")==0){
		if(SearchBlockDef(pDef,sName,&pNoUse)==FOUND) return true;
		return false;
	}
	else if(strcmp(sSymbol,"#ifndef")==0){
		if(SearchBlockDef(pDef,sName,&pNoUse)==NOTFOUND) return true;
		return false;
	}
	return false;
}
/*支持预编译功能的所有语句处理*/
int PropStatement(struct LSymbolStruct *pTemp,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,int iFlag,
	char sMsg[])
{
	int i=-1;
	struct LSymbolStruct *pTail;
	
	strcpy(sMsg,"");

	/*如果是预编译语句，则调用相应函数处理*/
	if(pTemp->s.iType==TYPE_PRECOMP_CONTROL){
		/*如果是define语句则修改宏链表*/
		if(strcmp(pTemp->s.sValue,"#define")==0)
			i=PropDefineStatement(pTemp,ppDef,ppHead,&pTail,iFlag,sMsg);
		/*如果是#include语句则直接#include进来了*/
		else if(strcmp(pTemp->s.sValue,"#include")==0)
			i=PropIncludeStatement(pTemp,ppDef,ppHead,&pTail,sMsg);
		/*如果是#ifdef或 #ifndef语句*/
		else if(strcmp(pTemp->s.sValue,"#ifdef")==0||
			strcmp(pTemp->s.sValue,"#ifndef")==0)
			i=PropIfStatement(pTemp,ppDef,ppHead,&pTail,sMsg);
		else
			sprintf(sMsg,"预编译命令 %s不支持",pTemp->s.sValue);
	}
	else
		i=PropNormalLines(pTemp,*ppDef,ppHead,&pTail,sMsg);

	if(i<0) return -1;
	*ppTail=pTail;
	return 0;

}
/*对非预编译行的开头进行处理*/
int PropNormalLines(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	struct LSymbolStruct *pTail,*pTemp,*ptLkHead=NULL;
	
	strcpy(sMsg,"");

	while(ptHead!=NULL){		
		/*如果行开始是预编译控制字符，则退出*/
		if(ptHead->s.iType==TYPE_PRECOMP_CONTROL) break;
		
		/*获取一行*/
		if(GetSymLine(ptHead,&pTail,sMsg)<0) return -1;
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
		}

		ptHead=pTail;
	}

	/*将链表给ptLkHead待转换*/
	ReverseList((LIST**)&ptLkHead);
	ptHead=ptLkHead;
	ptLkHead=NULL;

	/*对一个列表进行宏展开，并将展开结果追加到指定列表*/
	if(DeployMicroList(ptHead,pDef,&ptLkHead,sMsg)<0) return -1;
		
	*ppTail=pTail;
	/*将链表加入主体链表的末尾*/
	AppendListTail((LIST**)ppHead,(LIST*)ptLkHead);
	
	return 0;
}
/*
1.　　处理#ifdef 或 #ifndef 这个东西;
2.
	输入: struct BlockDefStruct **ppDef; 已定义的宏
		struct LSymbolStruct *ptHead; 包含 #ifdef 或 #ifndef 或 #if的东西;
	输出：
		1.不包含 #if #ifndef #define #include 等预编译关键字等的 struct LSymbolStruct **ppHead链表;
		2.ppTail后续的东西拉;
		3.如果有新增宏，则修改ppDef链表;
		4.注意内存的释放==========================,目前没有解决;;
3.流程;
	#ifdef 宏
	1.判断宏是否条件满足;
满足则:
	2.匹配
		#define
		#ifdef #ifndef
		#else
		#endif
	这几个东西;
	3.
		如果
		a)遇到#define 则修改Micro链表;;
		b)遇到#ifdef 或 #ifndef 则重复调用自己获取一块东西;
		c)遇到#endif 则结束;
			如果有遇到 #else 则获取 #原始位置到 #else的东西；
			否则就重原始位置到 #endif的信息;;
		c)#else,则记录#else位置;
			如果直接
			  遇到#define 但是，不修改Micro链表;;
			  遇到#ifxxx则直接获取一块而忽略;;
			  遇到#endif记录#endif位置;;

不满足则:
		#如果
			1.遇到#define，处理但不插链表，不生效;
			2.遇到#ifdef 或 #ifndef 则处理，但丢弃;
			3.直接遇到#endif则表明这个语句结束，获取为空;
			4.遇到#else语句
				如果
			遇到#define，处理，并修改Micro表;
			遇到#ifxxx则直接处理，并拿进来;;
			遇到#endif 则，记录#endif位置，将 #else到#endif中的东西拿出来;;

*/
/*处理#ifdef 或 #ifndef 语句*/
int PropIfStatement(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,char sMsg[])
{
	char sSymbol[30];
	int iTrueFlag,iAfterElse,iFlag;
	
	struct LSymbolStruct *pTail,*pTemp,*pNoUse=NULL,**ppTmp;
	
	strcpy(sMsg,"");

	pTemp=ptHead;
	
	if(pTemp==NULL){
		strcpy(sMsg,"预编译#if语句异常结束");
		return -1;
	}

	if(strcmp(pTemp->s.sValue,"#ifdef")!=0&&
		strcmp(pTemp->s.sValue,"#ifndef")!=0){
		strcpy(sMsg,"预编译#if语句异常必须以　#ifdef或#ifndef开头");
		return -1;
	}
	
	strcpy(sSymbol,pTemp->s.sValue);
	
	/*跳过预编译#if关键字*/
	pTemp=pTemp->pNext;
	
	/*取出一行作为逻辑判断*/
	if(GetSymLine(pTemp,&pTail,sMsg)<0) return -1;
	
	iTrueFlag=ChkPropCond(sSymbol,pTemp,*ppDef);
	iAfterElse=false;

	/*释放 #ifdef 或 #ifndef 这行的东西*/
	DestroyList((LIST*)ptHead);
	
	ptHead=pTail;
	while(ptHead!=NULL){
		
		if((iTrueFlag==true&&iAfterElse==false)||
			(iTrueFlag==false&&iAfterElse==true))
			{ppTmp=ppHead;iFlag=true;}
		else{ppTmp=&pNoUse;iFlag=false;}

		/*遇到else语句则设标志*/
		if(strcmp(ptHead->s.sValue,"#else")==0){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			free(pTemp);
			iAfterElse=true;
			continue;
		}
		/*遇到,结束语句设置返回值,并设置链表为空*/
		if(strcmp(ptHead->s.sValue,"#endif")==0){
			pTemp=ptHead;
			*ppTail=ptHead->pNext;
			free(pTemp);
			/*释放nouse链表*/
			DestroyList((LIST*)pNoUse);
			return 0;
		}
		/*处理，普通,#ifdef,#ifndef #include,#define语句*/
		if(PropStatement(ptHead,ppDef,ppTmp,&pTail,iFlag,sMsg)<0)
			return -1;

		ptHead=pTail;
	}

	strcpy(sMsg,"意外符号表结束 #ifdef 或 #ifndef 未匹配上#endif");
	return -1;
}
/*
处理 #include语句

输入:
	1.struct BlockDefStruct **ppDef; 已定义的宏
	struct LSymbolStruct *ptHead; 包含 #include的东西;
输出:
		1.不包含 #if #ifndef #define #include 等预编译关键字等的 struct LSymbolStruct **ppHead链表;
		2.ppTail后续的东西拉;
		3.如果有新增宏，则修改ppDef链表;
*/
int PropIncludeStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[])
{
	char sInclPath[256],sBaseName[128],l=0,sInclName[256];
	struct LSymbolStruct *pTail,*pTemp;

	strcpy(sMsg,"");

/*先得到公式包含文件路径*/
	GetBillHome(sInclPath);
	strcat(sInclPath,"expr/include/");
	
	if(IsDir(sInclPath)==false){
		sprintf(sMsg,"路径 %s　不存在",sInclPath);
		return -1;
	}
/*检查是否是 #include 开头*/
	if((pTemp=ptHead)==NULL){
		strcpy(sMsg,"预编译#include语句异常结束");
		return -1;
	}
	if(strcmp(pTemp->s.sValue,"#include")!=0){
		strcpy(sMsg,"预编译#include语句异常必须以　#include开头");
		return -1;
	}
	
	/*跳过#include*/
	if((pTemp=pTemp->pNext)==NULL){
		strcpy(sMsg,"预编译#include语句异常结束");
		return -1;
	}
	
	/*这段代码是获取 #include后的文件名,并设置*ppTail变量*/
	if(pTemp->s.iType==TYPE_CONST_STR){
		strncpy(sBaseName,pTemp->s.sValue+1,strlen(pTemp->s.sValue)-2);
		sBaseName[strlen(pTemp->s.sValue)-2]=0;
	}
	else{
		if(strcmp(pTemp->s.sValue,"<")!=0){
			sprintf(sMsg,"#include 之后必须跟 \"或 <,但是遇到%s",
				pTemp->s.sValue);
			return -1;
		}
		/*跳过 <*/
		if((pTemp=pTemp->pNext)==NULL){
			strcpy(sMsg,"预编译#include语句异常结束");
			return -1;
		}
		l=0;
		while(pTemp!=NULL){
			if(strcmp(pTemp->s.sValue,">")==0) break;
			l+=sprintf(sBaseName+l,"%s",pTemp->s.sValue);
			pTemp=pTemp->pNext;
		}
		if(pTemp==NULL){
			strcpy(sMsg,"预编译#include语句异常结束");
			return -1;
		}
	}
	
	/*设置变量的返回数值*/
	*ppTail=pTemp->pNext;
	pTemp->pNext=NULL;
	
	/*将 #include 这行的东西释放*/
	DestroyList((LIST*)ptHead);
	
	/*生成全名文件*/
	sprintf(sInclName,"%s%s",sInclPath,sBaseName);
	
	/*将include文件入include栈，用于错误定位*/
	PushFileStack(sInclName);
	
	if(FileLexicalize(sInclName,sMsg)<0) return -1;
	
	/*将SymbolFlow的词法分析的结果导入ptHead中*/
	if(MoveSymbolFlowToLSymbolList(&ptHead)<0){
		sprintf(sMsg,"分配内存 struct LSymbolStruct　失败");
		return -1;
	}
	/*对各种语句都得处理做一个循环,处理预编译过程*/
	while(ptHead!=NULL){
		
		if(PropStatement(ptHead,ppDef,ppHead,&pTail,true,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	
	return 0;
}

/**
	1.获取一个宏定义的头,或获取一个宏调用的宏;
	2.*ppTail是后续符链表;
	3.ptHead是这个宏定义或宏调用的符号串链表;
	4.pa[]是形参或实参数列表; ===>这个不能存串，而要存链表;;
**/

int GetHeadListComm(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[])
{
	int i=0;
	struct LSymbolStruct *pTemp;

	*ppTail=NULL;
	strcpy(sMsg,"");

	if(ptHead==NULL){
		strcpy(sMsg,"宏异常结束");
		return -1;
	}

	pTemp=ptHead->pNext;
/*直接结束就OK*/
	if(pTemp==NULL) return 0;
/*这里要将链表结束一下*/
	if(strcmp(pTemp->s.sValue,"(")!=0){
		*ppTail=ptHead->pNext;
		ptHead->pNext=NULL;
		return 0;
	}
/*条过(*/
	pTemp=pTemp->pNext;

	while(pTemp!=NULL){
		/*支持0个参数的形式*/
		if(i==0&&strcmp(pTemp->s.sValue,")")==0) break;

		pa[i].pSymBgn=pTemp;

		while(pTemp!=NULL){
			if(strcmp(pTemp->s.sValue,")")==0||
				strcmp(pTemp->s.sValue,",")==0) break;
			pTemp=pTemp->pNext;
		}
		if(pTemp==NULL){
			strcpy(sMsg,"宏异常结束");
			return -1;
		}
		
		pa[i].pSymEnd=pTemp;

		i++;

		if(strcmp(pTemp->s.sValue,")")==0) break;

		if(strcmp(pTemp->s.sValue,",")!=0){
			sprintf("宏的形参之间必须为','间隔",
				pTemp->s.sValue);
			return -1;
		}
		/*跳过,','间隔符*/
		pTemp=pTemp->pNext;
	}
	*ppTail=pTemp->pNext;
	pTemp->pNext=NULL;

	return i;	
}
/*检查形式参数的形态，必须为一个标识符的形式，否则报错误*/
int CheckModalityParam(char sName[],int iCnt,struct ParamDefStruct pa[],
	char sMsg[])
{
	int i;

	strcpy(sMsg,"");
	for(i=0;i<iCnt;i++){
		if(pa[i].pSymBgn->pNext!=pa[i].pSymEnd){
			sprintf(sMsg,"宏%s的第%d个形参超过1个",sName,i);
			return -1;
		}
		if(pa[i].pSymBgn->s.iType!=TYPE_TEMPVAR){
			sprintf(sMsg,"宏%s的第%d个形参必须是一个标识符",
				sName,i);
			return -1;
		}
	}
	return 0;
}
/*获取宏定义的头*/
int GetMicroHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[])
{
	int iCnt;
	
	if((iCnt=GetHeadListComm(ptHead,ppTail,pa,sMsg))<0) return -1;
	
	if(CheckModalityParam(ptHead->s.sValue,iCnt,pa,sMsg)<0) return -1;
	
	
	return iCnt;
}
/*或取宏定义的引用*/
int GetMicroRef(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[])
{
	return GetHeadListComm(ptHead,ppTail,pa,sMsg);
}
/*
	1.获取一行记录;注意包括\n
*/
int GetSymLine(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	struct LSymbolStruct *pTemp;

	strcpy(sMsg,"");

	*ppTail=NULL;

	if(ptHead==NULL){
		strcpy(sMsg,"意外符号表结束");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(strcmp(pTemp->s.sValue,"\n")==0){
			*ppTail=pTemp->pNext;
			pTemp->pNext=NULL;
			return 0;
		}
	}
	return 0;
}
/*获取一个语句块*/
int GetSymBlock(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	int i=0;

	struct LSymbolStruct *pTemp;
	
	strcpy(sMsg,"");

	if(ptHead==NULL){
		strcpy(sMsg,"意外符号表结束");
		return -1;
	}

	if(strcmp(ptHead->s.sValue,"{")!=0){
		strcpy(sMsg,"非法语句块开始");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->s.sValue,"{")==0) i++;
		else if(strcmp(pTemp->s.sValue,"}")==0) i--;
		/*i==0表示匹配上了*/
		if(i==0){
			*ppTail=pTemp->pNext;
			pTemp->pNext=NULL;
			return 0;
		}
	}
	strcpy(sMsg,"意外符号表结束");
	return -1;
}

/*
	从左到右,获取一个宏定义体,找到一个\n的间隔符就ok了
	1.ptHead 是宏定义的开始,处理后就是整个宏体的链表;
		将宏体内的形参都替换为 
		iType=TYPE_MODALITY_PARA
		sValue="%d",n
	2.将宏体后的东西，放在 **ppTail中;
*/
int GetMicroBody(struct LSymbolStruct *ptHead,int iCnt,struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[])
{
	int i;
	struct LSymbolStruct *pTemp;

	if(GetSymLine(ptHead,ppTail,sMsg)<0) return -1;
/*如果没有宏变量则直接OK*/
	if(iCnt==0) return 0;
/*如果有就需要替换了*/
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
	
		for(i=0;i<iCnt;i++){
			/*如果匹配上了宏形参则替换之*/
			if(strcmp(pa[i].pSymBgn->s.sValue,
				pTemp->s.sValue)==0){
				pTemp->s.iType=TYPE_MODALITY_PARA;
				sprintf(pTemp->s.sValue,"%d",i);
				break;
			}
		}
	}
	return 0;
}
/**
宏展开语句功能
	
输入::
	AX(x,y,z)
	struct LSymbolStruct *pHead,其中第一个是一个临时标识符，并且在pDef中找到;;
	struct BlockDefStruct *pItem;
输出::
	(3*(x)+6+(y)-(z)) 这个东西;;

	1.struct LSymbolStruct *pHead,其中第一个是一个临时标识符，并且在pDef中找到;;
	2.pItem宏名字能匹配得上的宏定义项结构;宏定义列表;
	3.ppHead这是宏展开时的列表;
	4.ppTail是宏引用语句结束的位置;;
	5.宏引用列表会释放内存;;
**/
int DeployMicroStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pItem,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[])
{
	int i,iCnt;
	struct ParamDefStruct pa[32];
	struct LSymbolStruct *pBgn,*pEnd,*ptLkHead=NULL,*ptPre,*ptCur;

/*这里的PA中有实参数*/
	if((iCnt=GetHeadListComm(ptHead,ppTail,pa,sMsg))<0) return -1;
/*宏参数要和定义的一致*/
	if(iCnt!=pItem->iParamCnt){
		sprintf(sMsg,"宏%s定义时参数为%d,引用时参数为%d",
			pItem->sName,pItem->iParamCnt,iCnt);
		return -1;
	}

/*包含形参宏体展开列表*/
	ptCur=pItem->pBody;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		/*如果标识符是宏形参数，则实施替换*/
		if(ptPre->s.iType==TYPE_MODALITY_PARA){

			i=atoi(ptPre->s.sValue);

			pBgn=pa[i].pSymBgn;
			pEnd=pa[i].pSymEnd;

			do{
				if(AssignLSymHead(&ptLkHead,pBgn)<0){
					strcpy(sMsg,"分配内存失败");
					return -1;
				}
				pBgn=pBgn->pNext;
			}while(pBgn!=pEnd);		
			
		}
		else{
			if(AssignLSymHead(&ptLkHead,ptPre)<0){
				strcpy(sMsg,"分配内存失败");
				return -1;
			}
		}
	}
	
/*将宏定义体释放掉,只能在这里释放，因为内存在pa中引用*/
	DestroyList((LIST*)ptHead);

	ReverseList((LIST**)&ptLkHead);
	
	AppendListTail((LIST**)ppHead,(LIST*)ptLkHead);
	return 0;
}
/*对一个列表进行宏展开，并将展开结果追加到指定列表*/
int DeployMicroList(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,char sMsg[])
{
	struct BlockDefStruct *pBlockDef=NULL;
	struct LSymbolStruct *pTemp,*ptPre,*ptCur,*ptLkHead=NULL;
/*	int i=0;*/

	pTemp=ptHead;
	
	while(pTemp!=NULL){
		
/*		printf("%d.\n",i++);*/

		/*如果不是标识符，或不是宏则直接将标识符取到ptPre,
		 并pTemp指向下一个标识符，并使ptPre->pNext置空*/
		if(pTemp->s.iType!=TYPE_TEMPVAR||
			SearchBlockDef(pDef,pTemp->s.sValue,&pBlockDef)
			==NOTFOUND){
			ptPre=pTemp;
			pTemp=pTemp->pNext;
			ptPre->pNext=NULL;
		}
		else{
		/*如果是宏则展开之，将展开的结果放在ptPre链表中，并将
		宏引用的pTemp链表释放，同时设pTemp为宏引用之后的字符*/
			ptPre=NULL;
			if(DeployMicroStatement(pTemp,pBlockDef,
				&ptPre,&ptCur,sMsg)<0) return -1;
		/*宏展开时已经将定义的头释放了*/
		/*	DestroyList((LIST*)pTemp);*/
			pTemp=ptCur;
		}
		ptCur=ptPre;
		while(ptCur!=NULL){

			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			InsertList((LIST**)&ptLkHead,(LIST*)ptPre);
		}
	}
	ReverseList((LIST**)&ptLkHead);
/*
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	PrintLSymList(*ppHead);
	printf("yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n");
	PrintLSymList(ptLkHead);
*/
	AppendListTail((LIST**)ppHead,(LIST*)ptLkHead);

	return 0;
}
/*
===
处理宏定义语句;

输入: #define AX(x,y,z) (3*(x)+6+(y)-(z)) 等类似东西;;
输出: struct BlockDefStruct 这个结构项;

::预编译#define语句函数;;
	ptHead #包含 #define　这个关键字的东西;;符号表;
	ptHead宏头和宏体部分被嵌入,pDef中;
	sName  ::当前宏名，避免重复递归展开用,一个宏直接或间接包含自己,
	pDef   ::系统内已申明的宏列表;用于二次展开;
	p      ::系统输出的宏展开结构;;
	ppTail ::宏定义语句结束的链表..

=====*********目前未考虑宏自我包含检测情况，自我包含不能展开直接，也可以用拉;
*/
int PropDefineStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,int iFlag,char sMsg[])
{
	int i;
	struct BlockDefStruct Temp,*pDef;
	struct LSymbolStruct *pTemp=ptHead,*pTail;
	
	if(pTemp==NULL){
		strcpy(sMsg,"宏异常结束");
		return -1;
	}

	/*跳过#define字符*/
	pTemp=pTemp->pNext;
	free(ptHead); /*释放#define 标识符*/

	/*生成宏定义的头并获取参数个数*/
	if((Temp.iParamCnt=GetMicroHead(pTemp,&pTail,Temp.pa,sMsg))<0)
		return -1;

	Temp.cType=VARTYPE_UNK;
	Temp.iCodeAddr=-1;

	/*获取宏名*/
	strcpy(Temp.sName,pTemp->s.sValue);
	Temp.pHead=pTemp;

	/*设置类型为UNK*/
	for(i=0;i<Temp.iParamCnt;i++)Temp.sType[i]=VARTYPE_UNK;
	Temp.sType[i]=0;
	
	/*指针指向宏定义体*/
	pTemp=ptHead=pTail;
	
	/*获取宏定义体*/
	if(GetMicroBody(pTemp,Temp.iParamCnt,Temp.pa,&pTail,sMsg)<0)
		return -1;
	/*这里要做一个循环做一个宏展开,并将结果放到ptHead*/
	ptHead=NULL;
	if(DeployMicroList(pTemp,*ppDef,&ptHead,sMsg)<0) return -1;
	
	*ppTail=pTail;
	Temp.pBody=ptHead;
	
	if(iFlag==true){
		if(SearchBlockDef(*ppDef,Temp.sName,&pDef)==FOUND){
			sprintf(sMsg,"宏%s重复定义",Temp.sName);
			return -1;
		}
	/*　如果这个宏定义生效，则将新增的宏添加到宏链表中*/
		if((pDef=malloc(sizeof(struct BlockDefStruct)))==NULL){
			strcpy(sMsg,"分配内存错误");
			return -1;
		}
		memcpy((void*)pDef,(void*)&Temp,sizeof(struct BlockDefStruct));
		InsertList((LIST**)ppDef,(LIST*)pDef);
	}	
	return 0;
}

/*将全局符号表导到链表中*/
int MoveSymbolFlowToLSymbolList(struct LSymbolStruct **pptHead)
{
	int i;
	struct LSymbolStruct *ptLkHead=NULL,*pTemp;
	
	for(i=0;i<igSymCnt;i++){
		
		if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL) return -1;
		
		memcpy((void*)&(pTemp->s),&SymbolFlow[i],
			sizeof(struct SymbolStruct));
		InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	ReverseList((LIST**)&ptLkHead);
	*pptHead=ptLkHead;
	igSymPos=igSymCnt=0;
	return 0;
}
/*将链表移到全局符号表，并释放链表*/
int MoveLSymListToSymbolFlow(struct LSymbolStruct *ptHead)
{
	int i=0;
	struct LSymbolStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*\r\n这种东西不导回符号表*/
		if(strcmp(pTemp->s.sValue,"\n")==0||
			strcmp(pTemp->s.sValue,"\r")==0) continue;

		memcpy((void*)&SymbolFlow[i],(void*)&(pTemp->s),
			sizeof(struct SymbolStruct));
		if(++i>SYMBOL_BUFLEN) return -1;
	}
	igSymPos=igSymCnt=i;
	return 0;
}
/*不支持预编译功能的文件词法解析*/
int FileLexicalize(char sFileName[],char sMsg[])
{
	char sInput[EXPRLEN];

	if(IsFile(sFileName)==false){
		sprintf(sMsg,"文件 %s 不存在",sFileName);
		return -1;
	}
	if(FileSize(sFileName)>=EXPRLEN){
		sprintf(sMsg,"文件　%s 大小 %d,超过最大值%d",
			sFileName,FileSize(sFileName),EXPRLEN);
		return -1;
	}
	if(ReadFileToBuf(sFileName,EXPRLEN,sInput,sMsg)<0)
		return -1;
	/*对include读入的文件进行词法分析*/
	if(Lexicalize(sInput)<0){
		sprintf(sMsg,"对文件　%s 词法分析错误",sFileName);
		FormatExprErrorMsg(sInput);
		return -1;
	}
	return 0;
}
void AddDefSymToHead(struct LSymbolStruct **pptHead,struct BlockDefStruct *p)
{
	struct LSymbolStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	while(p!=NULL){

		DestroyList((LIST*)p->pHead);
		p->pHead=NULL;
		ptHead=p->pBody;
		p->pBody=NULL;
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
		}
		p=p->pNext;
	}
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	
	/*并将函数引用的类型修改为TYPE_FUN*/
	ptHead=*pptHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		if(pTemp->s.iType==TYPE_TEMPVAR){

			if(SearchDefFun(pTemp->s.sValue,&p)==FOUND)
				pTemp->s.iType=TYPE_FUN;
		}	
	}
}
int PropLexicalize(char sInput[],char sMsg[])
{
	struct BlockDefStruct *pDef=NULL;
	struct LSymbolStruct *ptHead,*pTail,*pTemp;
	
	/*将全局栈清空*/
	EmptyFileStack();
	
	/*如果是字符串，则设置一个特殊的文件名*/
	PushFileStack("[main]");

	/*对include读入的文件进行词法分析*/
	if(Lexicalize(sInput)<0){
		strcpy(sMsg,"词法分析错误");
		FormatExprErrorMsg(sInput);
		return -1;
	}
	
	/*将SymbolFlow的词法分析的结果导入ptHead中*/
	if(MoveSymbolFlowToLSymbolList(&ptHead)<0){
		sprintf(sMsg,"分配内存 struct LSymbolStruct　失败");
		return -1;
	}
	/*对各种语句都得处理做一个循环,处理预编译过程*/

	pTemp=NULL;
	while(ptHead!=NULL){
		if(PropStatement(ptHead,&pDef,&pTemp,&pTail,true,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	ptHead=pTemp;
	pTemp=NULL;
	/*删除回车换行*/
	DeleteLSymListLrn(&ptHead);
	
	pTemp=NULL;
	/*将函数定义的部分放到pDefFun链表中*/	
	if(PropFunDefList(ptHead,&pDefFun,&pTemp,sMsg)<0) return -1;

	ptHead=pTemp;
	pTemp=NULL;
	/*将pDefFun的符号表加到ptHead的头部*/
	ReverseList((LIST**)&pDefFun);
	AddDefSymToHead(&ptHead,pDefFun);
	ReverseList((LIST**)&pDefFun);

	if(MoveLSymListToSymbolFlow(ptHead)<0){
		sprintf(sMsg,"符号表太长,需求长度%d,支持长度%d",
			CountList((LIST*)ptHead),SYMBOL_BUFLEN);
		return -1;
	}

/*	PrintLSymList(ptHead);*/

/*	printf("链表长度=%d.\n",CountList((LIST*)ptHead));
*/	
	DestroyList((LIST*)ptHead);
	DestroyBlockDef(pDef);
	
	return 0;

}
int FilePropLexicalize(char sFileName[],char sMsg[])
{
	struct BlockDefStruct *pDef=NULL;
	struct LSymbolStruct *ptHead,*pTail,*pTemp;
	
	/*将全局栈清空*/
	EmptyFileStack();
	
	/*将词法分析的文件入栈*/
	PushFileStack(sFileName);
	
	/*对include读入的文件进行词法分析*/
	if(FileLexicalize(sFileName,sMsg)<0) return -1;
	
	/*将SymbolFlow的词法分析的结果导入ptHead中*/
	if(MoveSymbolFlowToLSymbolList(&ptHead)<0){
		sprintf(sMsg,"分配内存 struct LSymbolStruct　失败");
		return -1;
	}
	/*对各种语句都得处理做一个循环,处理预编译过程*/

	pTemp=NULL;
	while(ptHead!=NULL){		
		if(PropStatement(ptHead,&pDef,&pTemp,&pTail,true,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	if(MoveLSymListToSymbolFlow(pTemp)<0){
		sprintf(sMsg,"符号表太长,需求长度%d,支持长度%d",
			CountList((LIST*)pTemp),SYMBOL_BUFLEN);
		return -1;
	}
/*
	PrintLSymList(pTemp);
*/
	DestroyList((LIST*)pTemp);
	DestroyBlockDef(pDef);

	return 0;

}

/*查找一个宏定义*/
int SearchBlockDefByAddr(struct BlockDefStruct *ptHead,int iCodeAddr,
	struct BlockDefStruct **pptCur)
{
	*pptCur=NULL;
	while(ptHead!=NULL){
		if(iCodeAddr==ptHead->iCodeAddr){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
/*查找一个自定义行数的名字*/
int SearchDefFunByAddr(int iCodeAddr,char sName[])
{
	struct BlockDefStruct *pTemp=NULL;
	strcpy(sName,"");
	if(SearchBlockDefByAddr(pDefFun,iCodeAddr,&pTemp)==FOUND){
		strcpy(sName,pTemp->sName);
		return FOUND;
	}
	return NOTFOUND;
}


void DeleteLSymListLrn(struct LSymbolStruct **pptHead)
{
	struct LSymbolStruct *ptHead=(*pptHead),*ptLkHead=NULL,*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->s.sValue,"\n")==0||
			strcmp(pTemp->s.sValue,"\r")==0) free(pTemp);
		else InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	ReverseList((LIST**)&ptLkHead);
	*pptHead=ptLkHead;
}
/*判断一个语句是否为函数定义语句,不需要考虑回车换行的问题*/
int IsFunDefStatement(struct LSymbolStruct *ptHead,char sName[])
{
	char sTempName[256];

	strcpy(sName,"");

	if(ptHead==NULL) return false;
	if(ptHead->s.iType!=TYPE_DECLARE) return false;
	if((ptHead=ptHead->pNext)==NULL) return false;

	if(ptHead->s.iType!=TYPE_TEMPVAR) return false;
	strcpy(sTempName,ptHead->s.sValue);
	if((ptHead=ptHead->pNext)==NULL) return false;

	if(strcmp(ptHead->s.sValue,"(")!=0) return false;

	strcpy(sName,sTempName);
	return true;
}
int GetFunParamType(struct LSymbolStruct *pTemp,char sName[],
	int i,char *pcType,char sMsg[])
{
	char sSubItem[100];

	if(i==-1) strcpy(sSubItem,"返回值申明");
	else	  sprintf(sSubItem,"第%d个参数申明",i);

	if(pTemp->s.iType!=TYPE_DECLARE||
		pTemp->pNext->s.iType!=TYPE_TEMPVAR){
		sprintf(sMsg,"函数%s的%s,应为type tmpvar",
			sName,sSubItem);
		return -1;
	}
	if(strcmp(pTemp->s.sValue,"int")==0)		*pcType='1';
	else if(strcmp(pTemp->s.sValue,"string")==0)	*pcType='2';
	else if(strcmp(pTemp->s.sValue,"double")==0)	*pcType='5';
	else if(strcmp(pTemp->s.sValue,"struct")==0)	*pcType='4';
	else if(strcmp(pTemp->s.sValue,"pointer")==0)	*pcType='3';
	else{
		sprintf(sMsg,"函数%s的%s类型%s错误",
			sName,sSubItem,pTemp->s.sValue);
		return -1;
	}
	return 0;
}
/*==============*/
/*获取一个函数文件头定义*/
int GetFunDefHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sName[],char *pcType,char sType[],
	struct ParamDefStruct pa[],char sMsg[])
{
	int iParamCnt,i,j;
	struct LSymbolStruct *pTemp;

	strcpy(sMsg,"");

	if(IsFunDefStatement(ptHead,sName)==false){
		strcpy(sMsg,"不满足函数声明条件");
		return -1;
	}
	if(GetFunParamType(ptHead,sName,-1,pcType,sMsg)<0) return -1;

	if((iParamCnt=GetHeadListComm(ptHead->pNext,ppTail,pa,sMsg))<0) return -1;

	for(i=0;i<iParamCnt;i++){
		j=0;
		pTemp=pa[i].pSymBgn;
		while(pTemp!=NULL){
			if(pTemp==pa[i].pSymEnd||j>100) break;
			j++;
			pTemp=pTemp->pNext;
		}
		if(j!=2){
			sprintf(sMsg,"函数%s的第%d个参数申明间隔错误",
				sName,i);
			return -1;
		}
		/*获取参数的类型*/
		if(GetFunParamType(pa[i].pSymBgn,sName,i,&sType[i],sMsg)<0)
			return -1;
	}
	sType[i]=0;
	return i;
}
/*获取一个函数体定义*/
/*
	从左到右,获取一个函数定义体，如果直接遇到;表示是一个函数头申明;
	1.ptHead 是函数体的开始,处理后就是整个函数体的链表;
		将函数体内的形参都替换为 
		iType=TYPE_MODALITY_PARA
		sValue="%d",n
	2.将函数体后的东西，放在 **ppTail中;
*/
int GetFunDefBody(struct LSymbolStruct *ptHead,char sName[],
	int iCnt,char sType[],struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[])
{
	int i;
	struct LSymbolStruct *pTemp;

	strcpy(sMsg,"");

	if(ptHead==NULL){
		sprintf(sMsg,"函数%s意外结束",sName);
		return -1;
	}
	/*如果就是一个头文件则直接OK*/
	if(strcmp(ptHead->s.sValue,";")==0){
		*ppTail=ptHead->pNext;
		ptHead->pNext=NULL;
		return 0;
	}
	/*获取一个函数定义体*/
	if(GetSymBlock(ptHead,ppTail,sMsg)<0) return -1;
	
/*如果有就需要替换了*/
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
	
		for(i=0;i<iCnt;i++){
			/*如果匹配上了函数形参则替换之*/
			if(strcmp(pa[i].pSymBgn->pNext->s.sValue,
				pTemp->s.sValue)==0){

				pTemp->s.iType=TYPE_MODALITY_PARA;
				/*这个打印的形式是死的*/
				sprintf(pTemp->s.sValue,"%d",i);
				break;
			}
		}
	}

	return 0;
}
/*增加一个函数定义句句*/
int PropFunDefStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	struct BlockDefStruct Temp,*pDef;
	struct LSymbolStruct *pTemp=ptHead,*pTail;
	
	if(pTemp==NULL){
		strcpy(sMsg,"函数异常结束");
		return -1;
	}

	/*生成函数定义的头并获取参数个数*/
	if((Temp.iParamCnt=GetFunDefHead(pTemp,&pTail,Temp.sName,
		&Temp.cType,Temp.sType,Temp.pa,sMsg))<0)
		return -1;
	Temp.pHead=pTemp;
	
	/*指针指向宏定义体*/
	pTemp=ptHead=pTail;
	
	/*获取宏定义体*/
	if(GetFunDefBody(pTemp,Temp.sName,Temp.iParamCnt,Temp.sType,
		Temp.pa,&pTail,sMsg)<0)	return -1;

	/*设置未编译状态*/
	Temp.iCodeAddr=-1;

	*ppTail=pTail;
	/*如果仅是一个函数的头，则将后面的;丢弃*/
	if(pTemp->pNext==NULL){
		Temp.pBody=NULL;
		free(pTemp);
	}
	else{
		/*将函数体之前插入　NAME + TYPE=TYPE_FUN的函数*/
		Temp.pBody=pTemp;
		if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL){
			sprintf(sMsg,"分配内存LSymbolStruct错误");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct LSymbolStruct));
		strcpy(pTemp->s.sValue,Temp.sName);
		pTemp->s.iType=TYPE_FUN;
		pTemp->s.iOriPos=Temp.pHead->s.iOriPos;
		InsertList((LIST**)&Temp.pBody,(LIST*)pTemp);
	}

	/*如果没找到加入*/
	if(SearchBlockDef(*ppDef,Temp.sName,&pDef)==NOTFOUND){
		if((pDef=malloc(sizeof(struct BlockDefStruct)))==NULL){
			strcpy(sMsg,"分配内存错误");
			return -1;
		}
		memcpy((void*)pDef,(void*)&Temp,sizeof(struct BlockDefStruct));
		InsertList((LIST**)ppDef,(LIST*)pDef);
		return 0;
	}
	/*如果参数个数不匹配则返回错误*/
	if(BlockParamMatch(&Temp,pDef,sMsg)<0) return -1;
	
	/*将函数体的词法链表加入指定位置*/
	DestroyList((LIST*)Temp.pHead);
	pDef->pBody=Temp.pBody;
	
	return 0;
}

int BlockParamMatch(struct BlockDefStruct *p1,struct BlockDefStruct *p2,
	char sMsg[])
{
	int i;

	strcpy(sMsg,"");

	if(p1->iParamCnt!=p2->iParamCnt){
		sprintf(sMsg,"函数%s出现两个定义参数个数不匹配%d,%d",
			p1->sName,p1->iParamCnt,p2->iParamCnt);
		return -1;
	}
	if(p1->cType!=p2->cType){
		sprintf(sMsg,"函数%s出现两个定义返回值不匹配%c,%c",
			p1->sName,p1->cType,p2->cType);
		return -1;
	}

	for(i=0;i<p1->iParamCnt;i++){
		if(p1->sType[i]!=p2->sType[i]){
			sprintf(sMsg,"函数%s出现两个定义第%d参数类型不匹配%c,%c",
				p1->sName,i,p1->sType[i],p2->sType[i]);
			return -1;
		}
	}
	if(p2->pBody!=NULL&&p1->pBody!=NULL){
		sprintf(sMsg,"函数%s出现两个定义",p1->sName);
		return -1;
	}

	return 0;
}
int SearchDefFun(char sSymbol[],struct BlockDefStruct **pptCur)
{
	return SearchBlockDef(pDefFun,sSymbol,pptCur);
}

int PropFunDefList(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,char sMsg[])
{
	char sName[128];
	struct LSymbolStruct *pTemp,*ptLkHead=NULL,*pTail=NULL;
	
	strcpy(sMsg,"");

	while(ptHead!=NULL){
		if(IsFunDefStatement(ptHead,sName)==false){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
			continue;
		}
		pTail=NULL;
		if(PropFunDefStatement(ptHead,ppDef,&pTail,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	ReverseList((LIST**)&ptLkHead);

	*ppHead=ptLkHead;
	return 0;
}

