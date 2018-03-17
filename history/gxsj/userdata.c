#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwsem.h>
#include <wwshm.h>
#include <list.h>
#include <bintree.h>
#include <trie.h>
#include <wwlog.h>
#include <wwdb.h>
#include <assert.h>
#include "user_ticket.h"
#include "shmbintree.h"

#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <expr_supp.h>

extern  struct FMemStruct FMem;

int comp_e_list_pay(POINTER ioffSource,POINTER ioffTarget)
{
	struct PayRelationStruct *pSource;
	struct PayRelationStruct *pTarget;
	char sTemp1[21],sTemp2[21];
	
	pSource=(struct PayRelationStruct *)OPFLIST(&FMem,ioffSource);
	pTarget=(struct PayRelationStruct *)OPFLIST(&FMem,ioffTarget);
	
	sprintf(sTemp1,"%ld%ld",pSource->lCustomerNo,pSource->lUserNo);
	sprintf(sTemp2,"%ld%ld",pTarget->lCustomerNo,pTarget->lUserNo);
	
	return strcmp(sTemp1,sTemp2);
}

int comp_e_list_atom(POINTER ioffSource,POINTER ioffTarget)
{
	struct AtomBillIntfStruct *pSource;
	struct AtomBillIntfStruct *pTarget;
	char sTemp1[21],sTemp2[21];
	
	pSource=(struct AtomBillIntfStruct *)OPFLIST(&FMem,ioffSource);
	pTarget=(struct AtomBillIntfStruct *)OPFLIST(&FMem,ioffTarget);
	
	sprintf(sTemp1,"%s%d",pSource->sBillAtom,pSource->iTicketTypeID);
	sprintf(sTemp2,"%s%d",pTarget->sBillAtom,pTarget->iTicketTypeID);
	
	return strcmp(sTemp1,sTemp2);
}

int comp_e_list_info(POINTER ioffSource,POINTER ioffTarget)
{
	struct InfoLineStruct *pSource;
	struct InfoLineStruct *pTarget;
	
	pSource=(struct InfoLineStruct *)OPFLIST(&FMem,ioffSource);
	pTarget=(struct InfoLineStruct *)OPFLIST(&FMem,ioffTarget);
	
	return strcmp(pSource->sDeviceNumber,pTarget->sDeviceNumber);
}

int comp_search_e_list_info(void *pValue,POINTER ioffTarget)
{
	struct InfoLineStruct *pTarget;	
	char *sValue=(char*)pValue;
	
	pTarget=(struct InfoLineStruct *)OPFLIST(&FMem,ioffTarget);
	
	return strcmp(sValue,pTarget->sDeviceNumber);
}

int comp_search_e_list_pay(void *pValue,POINTER ioffTarget)
{
	struct PayRelationStruct *pTarget;	
	char *sValue=(char*)pValue,sTemp[21];
	
	pTarget=(struct PayRelationStruct *)OPFLIST(&FMem,ioffTarget);
	
	sprintf(sTemp,"%ld%ld",pTarget->lCustomerNo,pTarget->lUserNo);
	
	return strcmp(sValue,sTemp);
}

int comp_search_e_list_atom(void *pValue,POINTER ioffTarget)
{
	struct AtomBillIntfStruct *pTarget;	
	char *sValue=(char*)pValue,sTemp[10];
	
	pTarget=(struct AtomBillIntfStruct *)OPFLIST(&FMem,ioffTarget);
	
	sprintf(sTemp,"%s%d",pTarget->sBillAtom,pTarget->iTicketTypeID);
	
	return strcmp(sValue,sTemp);
}

char *GetPayRelationRowStr(struct PayRelationStruct *pi,char sPo[])
{
	sprintf(sPo,"%ld,%ld,%s,%s,%s,%ld,%s",
		pi->lCustomerNo,pi->lUserNo,pi->sChargeCode,pi->sValidDate,
		pi->sInvalidDate,pi->lPayNo,pi->sLocalNet);

	return sPo;
}
char *GetAtomBillIntfRowStr(struct AtomBillIntfStruct *pi,char sPo[])
{
	sprintf(sPo,"%s,%s,%s,%d,%s,%ld,%d,%d,%d,%s",
		pi->sTeleType,pi->sLocalNet,pi->sBillAtom,pi->iTicketTypeID,	
		pi->sType,pi->lRate,pi->iParam1,pi->iParam2,pi->iParam3,pi->sRemarks);
		
	return sPo;
}
char *GetInfoLineRowStr(struct InfoLineStruct *pi,char sPo[])
{
	sprintf(sPo,"%s,%ld,%ld,%ld,%s,%s,%s,%s,%s,%s,%s,"
		"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",
		pi->sDeviceNumber,pi->lCustomerNo,pi->lUserNo,pi->lAssureNo,
		pi->sUserPwd,pi->sKindCode,pi->sStatusCode,pi->sUserDinner,
		pi->sSpecDinner,pi->sCreditDinner,pi->sCallLevel,pi->sGroupCode,
		pi->sInNetType,pi->sInNetDate,pi->sStopDate,pi->sDeptNo,
		pi->sLocalNet,pi->sLongNumber,pi->sMemo,pi->sOperNo,
		pi->sOperDeptNo,pi->sOperLocalNet,pi->sOperDate,pi->sFlag,
		pi->sFixType,pi->sFixAddress,pi->sHomeBur,pi->sContractNo);
		
	return sPo;
}

int CreateUserDataShmBinTree()
{
	int iCnt;
	struct FBinTreeShmStruct *ptBin=NULL;
	struct PayRelationStruct *pPayRelation=NULL;
	struct AtomBillIntfStruct *pAtomBillIntf=NULL;
	struct InfoLineStruct *pInfoLine=NULL;	
	struct ShmBinTreeHead *pPayTree=NULL,*pAtomTree=NULL,*pInfoTree=NULL;
		
	/**连接数据库***/
	if(IniConnect("dataconnstr")<0) return -1;
	if ((iCnt = InitPayRelation(&pPayRelation))<0){
		printf("加载表PAY_RELATION失败.%d\n",iCnt);
		return -1;
	}
	
	FMem.iBlockCnt=3;
	DestroyMultiShm(MULTI_SHM_ID,&FMem);	
	InitBinTreeShm(&ptBin,MULTI_SHM_ID);
	
	
	pPayTree=AddShmBinTree(ptBin,"PAY_RELATION",
		sizeof(struct PayRelationStruct),iCnt);
	if (pPayTree==NULL){
		printf("添加树失败.\n");
		return -1;
	}
	/*新建立时设置值.*/
	MvList2ShmBinTree(pPayTree,(LIST *)pPayRelation,
		sizeof(struct PayRelationStruct),comp_e_list_pay);        
	printf("成功加载表PAY_RELATION %d 条记录.\n",iCnt);
	DestroyPayRelation(pPayRelation);
	
	
	if ((iCnt = InitAtomBillIntf(&pAtomBillIntf))<0){
		printf("加载表ATOM_BILL_INTF失败.%d\n",iCnt);
		return -1;
	}	
	pAtomTree=AddShmBinTree(ptBin,"ATOM_BILL_INTF",
		sizeof(struct AtomBillIntfStruct),iCnt);
	if (pPayTree==NULL){
		printf("添加树失败.\n");
		return -1;
	}
	/*新建立时设置值.*/
	MvList2ShmBinTree(pAtomTree,(LIST *)pAtomBillIntf,
		sizeof(struct AtomBillIntfStruct),comp_e_list_atom);
	printf("成功加载表ATOM_BILL_INTF %d 条记录.\n",iCnt);
	DestroyAtomBillIntf(pAtomBillIntf);
	
	if ((iCnt = InitInfoLine(&pInfoLine))<0){
		printf("加载表INFO_LINE失败.%d\n",iCnt);
		return -1;
	}	
	pInfoTree=AddShmBinTree(ptBin,"INFO_LINE",
		sizeof(struct InfoLineStruct),iCnt);
	if (pPayTree==NULL){
		printf("添加树失败.\n");
		return -1;
	}
	/*新建立时设置值.*/
	MvList2ShmBinTree(pInfoTree,(LIST *)pInfoLine,
		sizeof(struct InfoLineStruct),comp_e_list_info);
	printf("成功加载表INFO_LINE %d 条记录.\n",iCnt);
	DestroyInfoLine(pInfoLine);
	
	DisconnectDatabase();	
	
	return 0;	
}

int SearchInfoLine( char sDeviceNumber[],struct InfoLineStruct  **pptHead )
{
        static int iFirstFlag=true;
        static struct ShmBinTreeHead *pTree=NULL;
        struct InfoLineStruct *p=NULL;
        
        if( iFirstFlag==true ){
		pTree = AttachShmBinTree("INFO_LINE");
        	iFirstFlag=false;
        }
        
        if (pTree==NULL) return NOTFOUND;
        
	if (SearchShmBinTree(pTree,sDeviceNumber,
		comp_search_e_list_info,(void **)&p)==FOUND){

		*pptHead = p;
		return FOUND;
	}

	return NOTFOUND;
}

int SearchPayRelation( LONGINT lCustomerNo,LONGINT lUserNo,
	struct PayRelationStruct  **pptHead)
{
        static int iFirstFlag=true;
        static struct ShmBinTreeHead *pTree=NULL;
        struct PayRelationStruct *p=NULL;
        char sValue[21];
        	
        if( iFirstFlag==true ){
		pTree = AttachShmBinTree("PAY_RELATION");
        	iFirstFlag=false;
        }
        
        if (pTree==NULL) return NOTFOUND;
        
        sprintf(sValue,"%ld%ld",lCustomerNo,lUserNo);
	if (SearchShmBinTree(pTree,sValue,
		comp_search_e_list_pay,(void **)&p)==FOUND){
		*pptHead = p;
		return FOUND;
	}

	return NOTFOUND;
} 

int SearchAtomBillIntf( char sBillAtom[], int iTicketTypeID,
	struct AtomBillIntfStruct **pptHead )
{
        static int iFirstFlag=true;
        static struct ShmBinTreeHead *pTree=NULL;
        struct AtomBillIntfStruct *p=NULL;
        char sValue[10];
        	
        if( iFirstFlag==true ){
		pTree = AttachShmBinTree("ATOM_BILL_INTF");
        	iFirstFlag=false;
        }
        
        if (pTree==NULL) return NOTFOUND;
        
        sprintf(sValue,"%s%d",sBillAtom,iTicketTypeID);
	if (SearchShmBinTree(pTree,sValue,
		comp_search_e_list_atom,(void **)&p)==FOUND){

		*pptHead = p;
		return FOUND;
	}

	return NOTFOUND;
}

int GetInfoLine(char sDeviceNumber[],char sResult[])
{        
	struct InfoLineStruct *pHead=NULL;
	
	strcpy(sResult,"");
	
	if (SearchInfoLine(sDeviceNumber,&pHead)==FOUND){
		GetInfoLineRowStr(pHead,sResult);
		return FOUND;
	}
	
        return NOTFOUND;
}

int GetPayRelation( LONGINT lCustomerNo,LONGINT lUserNo,char sResult[])
{        
	struct PayRelationStruct *pHead=NULL;
	
	strcpy(sResult,"");
	
	if (SearchPayRelation(lCustomerNo,lUserNo,&pHead)==FOUND){
		GetPayRelationRowStr(pHead,sResult);
		return FOUND;
	}
	
        return NOTFOUND;
}

int GetAtomBillIntf(char sBillAtom[], int iTicketTypeID,char sResult[])
{        
	struct AtomBillIntfStruct *pHead=NULL;
	
	strcpy(sResult,"");
	
	if (SearchAtomBillIntf(sBillAtom,iTicketTypeID,&pHead)==FOUND){
		GetAtomBillIntfRowStr(pHead,sResult);
		return FOUND;
	}
	
        return NOTFOUND;
}

int i_getinfoline(int d1,int r)
{
        char sTemp[sizeof(struct InfoLineStruct)+1];
        char *p1=GetStrVariant(CODE_VARBUF,d1);

        CODE_VARBUF[r].cType=VARTYPE_STR;
        GetInfoLine(p1,sTemp);

        return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_getpayrelation(int d1,int r)
{
        char sTemp[sizeof(struct PayRelationStruct)+1];
        LONGINT i1=GetIntVariant(CODE_VARBUF,d1);
        LONGINT i2=GetIntVariant(CODE_VARBUF,d1+1);

        CODE_VARBUF[r].cType=VARTYPE_STR;
        GetPayRelation(i1,i2,sTemp);

        return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_getatombillintf(int d1,int r)
{
        char sTemp[sizeof(struct AtomBillIntfStruct)+1];
        char *p1=GetStrVariant(CODE_VARBUF,d1);
        LONGINT i2=GetIntVariant(CODE_VARBUF,d1+1);

        CODE_VARBUF[r].cType=VARTYPE_STR;
        GetAtomBillIntf(p1,i2,sTemp);

        return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_getsepposvar(int d1, int r)
{
	char sTmp[2048];
	struct PositionStruct tmp;
	
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_STRUCT; /*结构体*/
	GET_SEP_POS(p1,p11,&tmp);

	sTmp[0]='\0';
	if( tmp.iLen>0 ){
		strncpy(sTmp,p1+tmp.iOffset,tmp.iLen);
		sTmp[tmp.iLen]='\0';
	}
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTmp);
}



void RegShmUserDataExprFun()
{
RegFunItem("getinfoline",	i_getinfoline,		"2",'2','f');
RegFunItem("getpayrelation",	i_getpayrelation,	"11",'2','f');
RegFunItem("getatombillintf",	i_getatombillintf,	"21",'2','f');
RegFunItem("getsepposvar",	i_getsepposvar,		"23",'2','f');
}
