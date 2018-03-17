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
	char cType;		/*�������ͣ���������ֵ�ȵ�*/
	char cUseType;		/*'f':�����ֶ���,'T':������*/
};


/****************���⹫����ʽ�ӿڱ���****************/

int RegVarItem(void (*LoadVariant)(int,void *pi),
	void (*SaveVariant)(int,void *pi),char cType,char cUseType,char sSymbol[]);
int SearchRegVarLink(char sSymbol[],struct ExprVarStruct **pptCur);
void DestroyRegVarLink();			/*���ע���������*/

struct ExprFunStruct
{
	struct	ExprFunStruct *pNext;
	char 	sName[64];
/*����1Ϊ���������׵أ�d2��������������r��������ֵ��ַ*/
	int	(*FUNCTION)(int d1,int r);
	char	sParamConstraint[20];/*���֧��19������*/
/*����ֵ����:'1':����,'2':�ַ���,'0':δ֪������,'3':ָ������*/
	char cType;
/*��������,'f'һ�㺯��,'F'������������*/
	char cFunctionType;
};
int RegFunItem(char sName[64],int (*FUNCTION)(int d1,int r),
	char sParamConstraint[20],char cType,char cFunctionType);
int SearchRegFunLink(char sSymbol[],struct ExprFunStruct **pptCur);
int SearchRegFunLinkByAddr(int (*FUNCTION)(int d1,int r),char sName[]);
void DestroyRegFunLink();

extern int	(*RegExprSupp)();

#endif
