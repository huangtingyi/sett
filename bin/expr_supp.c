
/****************************************************************
*               ���ر������������Ϸ��Ժ���                    *
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
                /*����ϵͳ�����ĳ��ȱ������������һ��*/
                if(strlen(sSymbol)==strlen(pTemp->sName)){

                        if((p=strchr(pTemp->sName,'*'))==NULL){
                                /*��ȫƥ�����,�����ע��ı�����Ȳ�ƥ��*/
                                if(strcmp(sSymbol,pTemp->sName)==0){
                                        *pptCur=pTemp;
                                        return FOUND;
                                }
                        }
                        else{/*ǰ��λƥ�䣬����ǰ��λ��ȫ��Ȳ�ƥ��*/
                                if(strncmp(sSymbol,pTemp->sName,
                                        (p-pTemp->sName))==0){
                                        *pptCur=pTemp;
                                        return FOUND;
                                }
                        }
                }

		/*****���Ϊ#ͨ��������Ƴ���*******/
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
/*����ֵ��-1�����ڴ����0������1δ����������ظ�*/
int RegVarItem(void (*LoadVariant)(int,void *pi),
	void (*SaveVariant)(int,void *pi),char cType,char cUseType,char sSymbol[])
{
        struct  ExprVarStruct *p;
	if(SearchRegVarLink(sSymbol,&p)==FOUND) return 0;
	
        if((p=(struct   ExprVarStruct *)malloc(
                sizeof(struct   ExprVarStruct)))==NULL){
                WriteAlertMsg("�����ڴ����ExprVarStruct.");
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
                WriteAlertMsg("�����ڴ����ExprFunStruct.");
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
