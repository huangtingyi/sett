
/****************************************************************
*               加载变量及检查变量合法性函数                    *
*                                                               *
****************************************************************/
#include <stdio.h>
#include <hnixs.h>
#include <wwlog.h>
#include <list.h>
#include <expr.h>
#include <expr_supp.h>

struct ExprVarStruct *pRegVar=NULL;
struct ExprFunStruct *pRegFun=NULL;
int	DefaultRegExprSupp();

int	(*RegExprSupp)()=DefaultRegExprSupp;
int	DefaultRegExprSupp()
{
	return 0;
}
int SearchRegVarLink(char sSymbol[],struct ExprVarStruct **pptCur)
{
        char *p;
        struct ExprVarStruct *pTemp;

        pTemp=pRegVar;

        while(pTemp!=NULL){
                /*首先系统变量的长度必须和外来变量一致*/
                if(strlen(sSymbol)==strlen(pTemp->sName)){

                        if((p=strchr(pTemp->sName,'*'))==NULL){
                                /*完全匹配变量,必须和注册的变量相等才匹配*/
                                if(strcmp(sSymbol,pTemp->sName)==0){
                                        *pptCur=pTemp;
                                        return FOUND;
                                }
                        }
                        else{/*前几位匹配，必须前几位完全相等才匹配*/
                                if(strncmp(sSymbol,pTemp->sName,
                                        (p-pTemp->sName))==0){
                                        *pptCur=pTemp;
                                        return FOUND;
                                }
                        }
                }

		/*****如果为#通配符则不限制长度*******/
		if((p=strchr(pTemp->sName,'#'))!=NULL){
                        if(strncmp(sSymbol,pTemp->sName,
                                (p-pTemp->sName))==0){
                                *pptCur=pTemp;
                                return FOUND;
                        }
		}

                pTemp=pTemp->pNext;
        }
        return NOTFOUND;
}
void DestroyRegVarLink()
{
        struct ExprVarStruct *ptPre,*ptCur;
        ptCur=pRegVar;

        while(ptCur!=NULL){
                ptPre=ptCur;
                ptCur=ptCur->pNext;
                free(ptPre);
        }
        pRegVar=NULL;
}
/*返回值：-1分配内存错误，0正常，1未插入变量名重复*/
int RegVarItem(void (*LoadVariant)(int,void *pi),
	void (*SaveVariant)(int,void *pi),char cType,char cUseType,char sSymbol[])
{
        struct  ExprVarStruct *p;
	if(SearchRegVarLink(sSymbol,&p)==FOUND) return 0;
	
        if((p=(struct   ExprVarStruct *)malloc(
                sizeof(struct   ExprVarStruct)))==NULL){
                WriteAlertMsg("分配内存错误ExprVarStruct.");
                return -1;
        }

	p->LoadVariant= LoadVariant;
	p->SaveVariant  = SaveVariant;
	p->cType        = cType;
	p->cUseType	= cUseType;
	strcpy(p->sName,sSymbol);

	InsertList((LIST**)&pRegVar,(LIST*)p);

        return 0;
}

void DestroyRegFunLink()
{
        struct ExprFunStruct *ptPre,*ptCur;
        ptCur=pRegFun;

        while(ptCur!=NULL){
                ptPre=ptCur;
                ptCur=ptCur->pNext;
                free(ptPre);
        }
        pRegFun=NULL;
}

int SearchRegFunLink(char sSymbol[],struct ExprFunStruct **pptCur)
{
        struct ExprFunStruct *pTemp;

        pTemp=pRegFun;

        while(pTemp!=NULL){
		if(strcmp(sSymbol,pTemp->sName)==0){
			*pptCur=pTemp;
			return FOUND;
		}
                pTemp=pTemp->pNext;
        }
        return NOTFOUND;
}
int SearchRegFunLinkByAddr(int (*FUNCTION)(int d1,int r),char sName[])
{
        struct ExprFunStruct *pTemp;

        pTemp=pRegFun;

        while(pTemp!=NULL){
        	if(FUNCTION==pTemp->FUNCTION){
			strcpy(sName,pTemp->sName);
			return FOUND;
		}
                pTemp=pTemp->pNext;
        }
        return NOTFOUND;
}
int RegFunItem(char sName[64],int (*FUNCTION)(int d1,int r),
	char sParamConstraint[20],char cType,char cFunctionType)
{
        struct  ExprFunStruct *p;

	if(SearchRegFunLink(sName,&p)==FOUND) return 0;
	
        if((p=(struct   ExprFunStruct *)malloc(
                sizeof(struct   ExprFunStruct)))==NULL){
                WriteAlertMsg("分配内存错误ExprFunStruct.");
                return -1;
        }
	memset((void*)p,0,sizeof(struct ExprFunStruct));
	strcpy(p->sName,sName);
	p->FUNCTION=FUNCTION;
	strcpy(p->sParamConstraint,sParamConstraint);
	p->cType=	cType;
	p->cFunctionType=cFunctionType;
	InsertList((LIST**)&pRegFun,(LIST*)p);
	
        return 0;
}
