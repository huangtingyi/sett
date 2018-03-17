#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <trie.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

#include "dbsupp.h"
#include "stt_ticket.h"
#include "simple_serv.h"
#include "serv_intf.h"


struct FMemStruct SERV;
struct ShmServHead *PSHMSERV;

int AttachSimpleServ()
{
	void *pShm;
	POINTER ioffset;
	
	if((pShm=AttachMultiShm(SIMPLE_SERV_KEY,&SERV))==NULL)
		return -1;
	ioffset=sizeof(struct FShmStruct);
	PSHMSERV=(struct ShmServHead *)OPELIST(pShm,ioffset);

	return 0;
}
int SearchSimpleServByMsisdn(char sMsisdn[],struct ISimpleServStruct **pptCur)
{
	POINTER ioffTmp;

	if(PSHMSERV==NULL) return NOTFOUND;
	
	if(SearchFTrie((void*)&SERV,PSHMSERV->ioffTrie,sMsisdn,
		&ioffTmp)==NOTFOUND) return false;

	*pptCur=(struct ISimpleServStruct*)OPSERV(ioffTmp);
	
	return FOUND;
}

int AttachSimpleServI()
{
	void *pShm;
	POINTER ioffset;
	
	if((pShm=AttachMultiShm(SIMPLE_SERV_KEYI,&SERV))==NULL)
		return -1;
	ioffset=sizeof(struct FShmStruct);
	PSHMSERV=(struct ShmServHead *)OPELIST(pShm,ioffset);

	return 0;
}
int SearchSimpleServByImsi(char sImsi[],struct ISimpleServStruct **pptCur)
{
	POINTER ioffTmp;

	if(PSHMSERV==NULL) return NOTFOUND;
	
	if(SearchFTrie((void*)&SERV,PSHMSERV->ioffTrie,sImsi,
		&ioffTmp)==NOTFOUND) return false;

	*pptCur=(struct ISimpleServStruct*)OPSERV(ioffTmp);
	
	return FOUND;
}


int GetBillingTypeID(char sMsisdn[],char sBillingTypeID[])
{
	static int iFirstFlag=1;
	
	struct ISimpleServStruct *pTemp=NULL;

	if(iFirstFlag==1){
		iFirstFlag=0;	

		if(AttachSimpleServ()<0){
			printf("连接共享内存资料失败.\n");
			return NOTFOUND;
		}
	}

	strcpy(sBillingTypeID,"");
	
	if(SearchSimpleServByMsisdn(sMsisdn,&pTemp)!=NULL){
		strcpy(sBillingTypeID,pTemp->sBillingTypeID);
		return FOUND;

	}
	return NOTFOUND;
}

int GetMsisdn(char sImsi[],char sMsisdn[])
{
	static int iFirstFlag=1;
	
	struct ISimpleServStruct *pTemp=NULL;

	if(iFirstFlag==1){
		iFirstFlag=0;	

		if(AttachSimpleServI()<0){
			printf("连接共享内存资料失败.\n");
			return NOTFOUND;
		}
	}

	strcpy(sMsisdn,"");
	
	if(SearchSimpleServByImsi(sImsi,&pTemp)!=NULL){
		strcpy(sMsisdn,pTemp->sMsisdn);
		return FOUND;

	}
	return NOTFOUND;
}


int i_getbillingtypeid(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetBillingTypeID(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_getmsisdn(int d1,int r)
{
	char sTemp[128];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	GetMsisdn(p1,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}


void RegSimpleServExprFun()
{
RegFunItem("getbillingtypeid",	i_getbillingtypeid,	"2",'2','f');
RegFunItem("getmsisdn",		i_getmsisdn,		"2",'2','f');
}
