#ifndef	__EXPR_SUPP_H__
#define __EXPR_SUPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>

struct ExprVarStruct
{
	struct ExprVarStruct *pNext;
	
	void (*LoadVariant)(int,void *pi);
	void (*SaveVariant)(int,void *pi);
	char sName[64];
	char cType;		/*变量类型，整数、数值等等*/
	char cUseType;		/*'f':话单字段域,'T':话单域*/
};


/****************对外公布公式接口变量****************/

int RegVarItem(void (*LoadVariant)(int,void *pi),
	void (*SaveVariant)(int,void *pi),char cType,char cUseType,char sSymbol[]);
int SearchRegVarLink(char sSymbol[],struct ExprVarStruct **pptCur);
void DestroyRegVarLink();			/*清除注册变量链表*/

struct ExprFunStruct
{
	struct	ExprFunStruct *pNext;
	char 	sName[64];
/*参数1为函数参数首地，d2函数参数个数，r函数返回值地址*/
	int	(*FUNCTION)(int d1,int r);
	char	sParamConstraint[20];/*最大支持19个参数*/
/*返回值类型:'1':整数,'2':字符串,'0':未知道类型,'3':指针类型*/
	char cType;
/*函数类型,'f'一般函数,'F'常量参数函数*/
	char cFunctionType;
};
int RegFunItem(char sName[64],int (*FUNCTION)(int d1,int r),
	char sParamConstraint[20],char cType,char cFunctionType);
int SearchRegFunLink(char sSymbol[],struct ExprFunStruct **pptCur);
int SearchRegFunLinkByAddr(int (*FUNCTION)(int d1,int r),char sName[]);
void DestroyRegFunLink();

extern int	(*RegExprSupp)();

#endif
