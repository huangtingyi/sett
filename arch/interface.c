/*---------����ʵ�ִ��� serv.pc----------*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "serv.h"
#include "servacct.h"
#include "servproduct.h"
#include "acct.h"

#include <trie.h>
#include <hnixs.h>
#include <wwdb.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwshm.h>
#include <wwsem.h>

#include <param_intf.h>

#include <interface.h>


struct ShmServHead 	SERV;
struct ShmAcctHead 	ACCT;
struct ShmServAcctHead 	SERVACCT;
struct ShmServProductHead 	SERVPRODUCT;


/*ȫ�ֵĶ���---ȡ��Ŀ*/
#ifndef MAXACCTITEMTYPE
#define MAXACCTITEMTYPE 1000000
#endif
int igAcctItemFirstFlag=TRUE;

int giLockGrpID;

int ShmServHeadValid()
{
	return ShmHeadValid(SERVDATAKEY,(struct ShmHead*)&SERV,
		(struct ShmHead*)(SERV.pHead));
}

int ShmAcctHeadValid()
{
	return ShmHeadValid(ACCTDATAKEY,(struct ShmHead*)&ACCT,
		(struct ShmHead*)(ACCT.pHead));
}

int ShmServAcctHeadValid()
{
	return ShmHeadValid(SERVACCTDATAKEY,(struct ShmHead*)&SERVACCT,
		(struct ShmHead*)(SERVACCT.pHead));
}

int ShmServProductHeadValid()
{
	return ShmHeadValid(SERVPRODUCTDATAKEY,(struct ShmHead*)&SERVPRODUCT,
		(struct ShmHead*)(SERVPRODUCT.pHead));
}

static int ServAccess()
{
	if(ShmServHeadValid()==false){
		if(InitShmServ()!=0) return -1;
	}
	return 0;
}
static int AcctAccess()
{
	if(ShmAcctHeadValid()==false){
		if(InitShmAcct()!=0) return -1;
	}
	return 0;
}
static int ServAcctAccess()
{
	if(ShmServAcctHeadValid()==false){
		if(InitShmServAcct()!=0) return -1;
	}
	return 0;
}
static int ServProductAccess()
{
	if(ShmServProductHeadValid()==false){
		if(InitShmServProduct()!=0) return -1;
	}
	return 0;
}
int GetPayAcctItemType(int iAcctItemTypeID)
{
	int i;
	
	if(igAcctItemFirstFlag){
		InitAcctItemTypeAnti();
		igAcctItemFirstFlag=FALSE;
	}
	i=iAcctItemTypeID;
        
	if(i<0||i>=MAXACCTITEMTYPE) return -1;
        
	do{
		if(asAcctItemTypeKind[i]=='C'||
			asAcctItemTypeKind[i]=='U')
			return i;

		i=aiAcctItemTypeAnti[i];
	}while(i!=-1);
	
	return -1;
}
int GetSaleAcctItemType(int iAcctItemTypeID)
{
	int i;
	
	if(igAcctItemFirstFlag){
		InitAcctItemTypeAnti();
		igAcctItemFirstFlag=FALSE;
        }
        i=iAcctItemTypeID;
        
	if(i<0||i>=MAXACCTITEMTYPE) return -1;
        
        do{
        	if(asAcctItemTypeKind[i]=='A')
        		return i;
        	i=aiAcctItemTypeAnti[i];
	}while(i!=-1);
	return -1;
}

void InitAcctItemTypeAnti()
{		
        int i;
        struct AcctItemTypeStruct *ptHead=NULL,*pTemp;
        
        /*�����޹鲢��Ŀ*/
        
        for(i=0;i<MAXACCTITEMTYPE;i++) {
        	aiAcctItemTypeAnti[i]=0;
        	asAcctItemTypeKind[i]='\0';
        }
       
        SearchAcctItemType(&ptHead);
        
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
        
        	i=pTemp->iAcctItemTypeID;
        
        	if(i<0||i>=MAXACCTITEMTYPE){
                	printf("��Ŀ����%d���ò��Ϸ�ϵͳ����.\n",i);
                	continue;       
        	}
        	if(pTemp->iSummaryItemID!=-1&&
        		(pTemp->iSummaryItemID<0||
        			pTemp->iSummaryItemID>=MAXACCTITEMTYPE)){
        		
                	printf("��Ŀ����%d,%d���ò��Ϸ�ϵͳ����.\n",
                		i,pTemp->iSummaryItemID);
                	continue;       

        	}

        	aiAcctItemTypeAnti[i]=pTemp->iSummaryItemID;
        	asAcctItemTypeKind[i]=pTemp->sAcctItemTypeKind[0];
        }        		
}
/************************************************************
 *            SERV�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/

/*��λ�����ڴ浽�ֲ�������SERV�ṹ��	*/
/*�����������SERV�ṹ�е���Ϣ����ʼ��	*/
/*����ֵ��0���� -1 ������		*/
int InitShmServ()
{
	int iErrCode;
	struct ShmServHead *pHead;
	struct TRIEEXT *pNode;

/*���ý�����������¼���*/

	/*���SERVDATAKEY������*/
	pHead=(struct ShmServHead *)GetShm(SERVDATAKEY,&iErrCode,(void*)0);

	if(iErrCode) return DATA_LOST;
	
	/*���SERVNODEKEY������*/
	pNode=(struct TRIEEXT *)GetShm(SERVNODEKEY,&iErrCode,(void*)0);
	if(iErrCode) return NODE_LOST;

	memcpy((void *)&SERV,(void*)pHead,sizeof(struct ShmServHead));

	SERV.pData=(struct IServStruct*)(pHead+1);
	SERV.pNode=(TRIEEXT*)pNode;
	SERV.pHead=(struct ShmServHead*)pHead;
	
	return 0;
}
/*�뿪SERV��Ĺ����ڴ�*/
int DetachShmServ()
{
	if( shmdt((void*)SERV.pNode)==-1||
		shmdt((void*)SERV.pHead)==-1) return -1;
	return 0;
}

int SearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	struct IServStruct **pptCur)
{
	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp;

	if(SearchTrieE(SERV.ioffsetAccNbr,pNodeSeg,sAccNbr,&ioffsetHead)==
		NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){

		pTemp=SERVTRIEEXT(ioffsetHead);
		if(strcmp(sAccNbr,pTemp->sAccNbr)==0){

			if(strcmp(pTemp->sState, "F0A") == 0){

				*pptCur = pTemp;
				return FOUND;
			}
			if(strcmp(sStartTime,pTemp->sCompletedDate)>0&&
				strcmp(sStartTime,pTemp->sStateDate)<=0){
				*pptCur = pTemp;
				return FOUND;
			}
			if(strcmp(pTemp->sState,"F0P")==0||
				strcmp(pTemp->sState,"F0D")==0||
				strcmp(pTemp->sState,"F0X")==0||
				strcmp(pTemp->sState,"F0Y")==0){
				*pptCur = pTemp;
				return FOUND;
			}
		}
		ioffsetHead=NEXT_SERV__ACCNBR(ioffsetHead);	
	}	
	return NOTFOUND;

}

int SearchImsiInServ(char sImsi[],char sStartTime[15],
	struct IServStruct **pptCur)
{
	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp;

	if(SearchTrieE(SERV.ioffsetImsi,pNodeSeg,sImsi,&ioffsetHead)==
		NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){

		pTemp=SERVTRIEEXT(ioffsetHead);
		if(strcmp(sImsi,pTemp->sImsi)==0){

			if(strcmp(pTemp->sState, "F0A") == 0){

				*pptCur = pTemp;
				return FOUND;
			}
			if(strcmp(sStartTime,pTemp->sCompletedDate)>0&&
				strcmp(sStartTime,pTemp->sStateDate)<=0){
				*pptCur = pTemp;
				return FOUND;
			}
			if(strcmp(pTemp->sState,"F0P")==0||
				strcmp(pTemp->sState,"F0D")==0||
				strcmp(pTemp->sState,"F0Y")==0){
				*pptCur = pTemp;
				return FOUND;
			}
		}
		ioffsetHead=NEXT_SERV__IMSI(ioffsetHead);	
	}	
	return NOTFOUND;

}

int SearchServIDInServ(char sServID[],
	int iServSeqNbr,struct IServStruct **pptCur)
{
	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp;

	if(SearchTrieE(SERV.ioffsetServID,pNodeSeg,sServID,&ioffsetHead)==
		NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){
		pTemp=SERVTRIEEXT(ioffsetHead);
		if(iServSeqNbr==pTemp->iServSeqNbr){
			*pptCur=pTemp;
			return FOUND;
		}
		ioffsetHead=NEXT_SERV__SERVID(ioffsetHead);	
	}
	return NOTFOUND;

}

int SearchServIDInServE(char sServID[],char sStartTime[],
	struct IServStruct **pptCur)
{

	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp=NULL;

	if(SearchTrieE(SERV.ioffsetServID,pNodeSeg,sServID,&ioffsetHead)==
		NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){
		pTemp=SERVTRIEEXT(ioffsetHead);
		
			if(strcmp(pTemp->sState, "F0A") == 0){

				*pptCur = pTemp;
				return FOUND;
			}
			if(strcmp(sStartTime,pTemp->sCompletedDate)>0&&
				strcmp(sStartTime,pTemp->sStateDate)<=0){
				*pptCur = pTemp;
				return FOUND;
			}
			if(strcmp(pTemp->sState,"F0P")==0||
				strcmp(pTemp->sState,"F0D")==0||
				strcmp(pTemp->sState,"F0Y")==0){
				*pptCur = pTemp;
				return FOUND;
			}

		ioffsetHead=NEXT_SERV__SERVID(ioffsetHead);	
	}

	return (*pptCur=pTemp)==NULL?NOTFOUND:FOUND;

}

/************************************************************
 *            SERV�ṩ�ⲿ���õ�API����                     *
 *                                                          *
 ************************************************************/
int IInitShmServ()
{
	return InitShmServ();
}
int IDetachShmServ()
{
	return DetachShmServ();
}
int ISearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	struct IServStruct **pptCur)
{
	return SearchAccNbrInServ(sAccNbr,sStartTime,pptCur);
}

int ISearchServIDInServ(char sServID[],
                int iServSeqNbr,struct IServStruct **pptCur)
{
	return SearchServIDInServ(sServID,iServSeqNbr,pptCur);
}
int CheckShmServAccess()
{

	if(ServAccess()==0) return 0;
	/**THE STATE UNMOUNT HERE,WAIT FOR DETACHED**/
	WaitSec(50);
	return ServAccess();	
}

int USearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res;
	
	struct IServStruct *pTemp;
	
	if(CheckShmServAccess()<0) 
		return SHM_ACCESS_FAIL;
	
	/*������������*/
	if(SearchAccNbrInServ(sAccNbr,sStartTime,&pTemp)==NOTFOUND)
		return NOTFOUND;
	/*ȡ����*/
	res=(*getdata_fun)(p,(void*)pTemp);
	
	if(CheckShmServAccess()<0) 
		return SHM_ACCESS_FAIL;
	
	return res;
}
int USearchAccNbrUsingImsiInServ(char sImsi[15],char sStartTime[15],
	char sAccNbr[16])
{
	struct IServStruct *pTemp;
	
	if(CheckShmServAccess()<0) 
		return SHM_ACCESS_FAIL;
	
	/*������������*/
	if(SearchImsiInServ(sImsi,sStartTime,&pTemp)==NOTFOUND)
		return NOTFOUND;

	strncpy(sAccNbr,pTemp->sAccNbr,15);
	sAccNbr[15]=0;

	if(CheckShmServAccess()<0) 
		return SHM_ACCESS_FAIL;

	return FOUND;
	
}


int USearchServIDInServ(char sServID[],int iServSeqNbr,
	int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res = 0;
	
	struct IServStruct *pTemp;
	
	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;

	
	/*������������*/
	if(SearchServIDInServ(sServID,iServSeqNbr,&pTemp)==NOTFOUND)
		return NOTFOUND;
	/*ȡ����*/
	res=(*getdata_fun)(p,(void*)pTemp);
	
	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;
	
	return res;
	
}

int MESearchAcctIDInServ(char sAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res=0;
	TRIEEXT *pNodeSeg;
	POINTER ioffsetHead;
	struct IServStruct *pTemp=NULL;

	(*getdata_fun)(p,NULL);

	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;

	pNodeSeg=SERV.pNode;

	if(SearchTrieE(SERV.ioffsetAcctID,pNodeSeg,sAcctID,&ioffsetHead)==
		NOTFOUND) return NOTFOUND;
			
	while(ioffsetHead!=-1){
		pTemp=SERVTRIEEXT(ioffsetHead);
		
		if(strcmp(pTemp->sState, "F0H") != 0){
			if((res=(*getdata_fun)(p,pTemp))<0) return res;
		}
		ioffsetHead=NEXT_SERV__SERVID(ioffsetHead);	
	}

	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;
	
	return res;
	
}
/************************************************************
 *            ACCT�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/


/*��λ�����ڴ浽�ֲ�������ACCT�ṹ��	*/
/*�����������ACCT�ṹ�е���Ϣ����ʼ��	*/
/*����ֵ��0���� -1 ������		*/
int InitShmAcct()
{
	int iErrCode;
	struct ShmAcctHead *pHead;
	struct TRIEEXT *pNode;

/*���ý�����������¼���*/

/*	ACCT.iRestoreFlag = TRUE;*/

	/*���ACCTDATAKEY������*/
	pHead=(struct ShmAcctHead *)GetShm(ACCTDATAKEY,&iErrCode,0);

	if(iErrCode) return -1;
	
	/*���ACCTNODEKEY������*/
	pNode=(struct TRIEEXT *)GetShm(ACCTNODEKEY,&iErrCode,0);
	if(iErrCode) return -1;

	memcpy((void *)&ACCT,(void*)pHead,sizeof(struct ShmAcctHead));

	ACCT.pData=(struct IAcctStruct*)(pHead+1);
	ACCT.pNode=(TRIEEXT*)pNode;
	ACCT.pHead=(struct ShmAcctHead*)pHead;
	
	return 0;
}
/*�뿪ACCT��Ĺ����ڴ�*/
int DetachShmAcct()
{
	if( shmdt((void*)ACCT.pNode)==-1||
		shmdt((void*)ACCT.pHead)==-1) return -1;
	return 0;
}

int SearchAcctIDInAcct(char sAcctID[],struct IAcctStruct **pptCur)
{
	TRIEEXT *pNodeSeg=ACCT.pNode;
	POINTER ioffsetHead;
	struct IAcctStruct *pTemp=NULL;

	if(SearchTrieE(ACCT.ioffsetAcctID,pNodeSeg,sAcctID,&ioffsetHead)==
		NOTFOUND)	return NOTFOUND;

	/*�������һ����¼*/			
	while(ioffsetHead!=-1){
		pTemp=ACCTTRIEEXT(ioffsetHead);
		ioffsetHead=NEXT_ACCT__ACCTID(ioffsetHead);	
	}

	if(pTemp==NULL) return NOTFOUND;

	*pptCur=pTemp;

	return FOUND;

}
/************************************************************
 *            ACCT�ṩ�ⲿ���õ�API����                     *
 *                                                          *
 ************************************************************/
int IInitShmAcct()
{
	return InitShmAcct();
}
int IDetachShmAcct()
{
	return DetachShmAcct();
}
int ISearchAcctIDInAcct(char sAcctID[],struct IAcctStruct **pptCur)
{
	return SearchAcctIDInAcct(sAcctID,pptCur);
}

int CheckShmAcctAccess()
{
	if(AcctAccess()==0) return 0;
	/**THE STATE UNMOUNT HERE,WAIT FOR DETACHED**/
	WaitSec(50);
	return AcctAccess();
}
int USearchAcctIDInAcct(char sAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res;
	
	struct IAcctStruct *pTemp;
	
	if(CheckShmAcctAccess()<0) return SHM_ACCESS_FAIL;

	/*������������*/
	if(SearchAcctIDInAcct(sAcctID,&pTemp)==NOTFOUND)
		return NOTFOUND;
	/*ȡ����*/
	res=(*getdata_fun)(p,(void*)pTemp);
	
	if(CheckShmAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	return res;

}
/************************************************************
 *            SERVACCT�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/

/*��λ�����ڴ浽�ֲ�������SERVACCT�ṹ��	*/
/*�����������SERVACCT�ṹ�е���Ϣ����ʼ��	*/
/*����ֵ��0���� -1 ������		*/
int InitShmServAcct()
{
	int iErrCode;
	struct ShmServAcctHead *pHead;
	struct TRIEEXT *pNode;

/*���ý�����������¼���*/

/*	SERVACCT.iRestoreFlag = TRUE;*/

	/*���SERVACCTDATAKEY������*/
	pHead=(struct ShmServAcctHead *)GetShm(SERVACCTDATAKEY,&iErrCode,0);

	if(iErrCode) return -1;
	
	/*���SERVACCTNODEKEY������*/
	pNode=(struct TRIEEXT *)GetShm(SERVACCTNODEKEY,&iErrCode,0);
	if(iErrCode) return -1;

	memcpy((void *)&SERVACCT,(void*)pHead,sizeof(struct ShmServAcctHead));

	SERVACCT.pData=(struct IServAcctStruct*)(pHead+1);
	SERVACCT.pNode=(TRIEEXT*)pNode;
	SERVACCT.pHead=(struct ShmServAcctHead*)pHead;
	
	return 0;
}
/*�뿪SERVACCT��Ĺ����ڴ�*/
int DetachShmServAcct()
{
	if( shmdt((void*)SERVACCT.pNode)==-1||
		shmdt((void*)SERVACCT.pHead)==-1) return -1;
	return 0;
}

int SearchServIDInServAcct(char sServID[],
                int iServSeqNbr,struct IServAcctStruct **pptCur)
{
	TRIEEXT *pNodeSeg=SERVACCT.pNode;
	POINTER ioffsetHead;
	struct IServAcctStruct *pTemp;

	if(SearchTrieE(SERVACCT.ioffsetServID,pNodeSeg,sServID,
		&ioffsetHead)==NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){
		pTemp=SERVACCTTRIEEXT(ioffsetHead);
		if(iServSeqNbr==pTemp->iServSeqNbr){
			*pptCur=pTemp;
			return FOUND;
		}
		ioffsetHead=NEXT_SERVACCT__SERVID(ioffsetHead);	
	}
	return NOTFOUND;

}
/************************************************************
 *            SERVACCT�ṩ�ⲿ���õ�API����                 *
 *                                                          *
 ************************************************************/
int IInitShmServAcct()
{
	return InitShmServAcct();
}
int IDetachShmServAcct()
{
	return DetachShmServAcct();
}
int ISearchServIDInServAcct(char sServID[],
                int iServSeqNbr,struct IServAcctStruct **pptCur)
{
	return SearchServIDInServAcct(sServID,iServSeqNbr,pptCur);
}
int CheckShmServAcctAccess()
{
	if(ServAcctAccess()==0) return 0;
	/**THE STATE UNMOUNT HERE,WAIT FOR DETACHED**/
	WaitSec(50);
	return ServAcctAccess();	
}
int MSearchServIDInServAcct(char sServID[],int iServSeqNbr,
	int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res;
	
	TRIEEXT *pNodeSeg;
	POINTER ioffsetHead;
	struct IServAcctStruct *pDataSeg,*pTemp;

	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	pNodeSeg=SERVACCT.pNode;
	pDataSeg=SERVACCT.pData;
	
	if(SearchTrieE(SERVACCT.ioffsetServID,pNodeSeg,sServID,
		&ioffsetHead)==NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){
		pTemp=SERVACCTTRIEEXT(ioffsetHead);
		if(iServSeqNbr==pTemp->iServSeqNbr){
			if((res=(*getdata_fun)(p,(void*)pTemp))<0){
				/*�������*/
				(*getdata_fun)(NULL,NULL);
				return res;
			}
		}
		ioffsetHead=NEXT_SERVACCT__SERVID(ioffsetHead);	
	}
	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
	return res;
}

/************************************************************
 *            SERVPRODUCT�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/

/*��λ�����ڴ浽�ֲ�������SERVPRODUCT�ṹ��	*/
/*�����������SERVPRODUCT�ṹ�е���Ϣ����ʼ��	*/
/*����ֵ��0���� -1 ������		*/
int InitShmServProduct()
{
	int iErrCode;
	struct ShmServProductHead *pHead;
	struct TRIEEXT *pNode;

/*���ý�����������¼���*/

/*	SERVPRODUCT.iRestoreFlag = TRUE;*/

	/*���SERVPRODUCTDATAKEY������*/
	pHead=(struct ShmServProductHead *)GetShm(SERVPRODUCTDATAKEY,&iErrCode,0);

	if(iErrCode) return -1;
	
	/*���SERVPRODUCTNODEKEY������*/
	pNode=(struct TRIEEXT *)GetShm(SERVPRODUCTNODEKEY,&iErrCode,0);
	if(iErrCode) return -1;

	memcpy((void *)&SERVPRODUCT,(void*)pHead,sizeof(struct ShmServProductHead));

	SERVPRODUCT.pData=(struct IServProductStruct*)(pHead+1);
	SERVPRODUCT.pNode=(TRIEEXT*)pNode;
	SERVPRODUCT.pHead=(struct ShmServProductHead*)pHead;
	
	return 0;
}
/*�뿪SERVPRODUCT��Ĺ����ڴ�*/
int DetachShmServProduct()
{
	if( shmdt((void*)SERVPRODUCT.pNode)==-1||
		shmdt((void*)SERVPRODUCT.pHead)==-1) return -1;
	return 0;
}

int SearchServIDInServProduct(char sServID[],struct IServProductStruct **pptCur)
{
	TRIEEXT *pNodeSeg=SERVPRODUCT.pNode;
	POINTER ioffsetHead;
	struct IServProductStruct *pTemp;

	if(SearchTrieE(SERVPRODUCT.ioffsetServID,pNodeSeg,sServID,
		&ioffsetHead)==NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){
		pTemp=SERVPRODUCTTRIEEXT(ioffsetHead);
/*		if(iServSeqNbr==pTemp->iServSeqNbr){*/
			*pptCur=pTemp;
			return FOUND;
/*		}*/
		ioffsetHead=NEXT_SERVPRODUCT__SERVID(ioffsetHead);	
	}
	return NOTFOUND;

}

/************************************************************
 *            SERVPRODUCT�ṩ�ⲿ���õ�API����                     *
 *                                                          *
 ************************************************************/
int IInitShmServProduct()
{
	return InitShmServProduct();
}
int IDetachShmServProduct()
{
	return DetachShmServProduct();
}
int ISearchServIDInServProduct(char sServID[],struct IServProductStruct **pptCur)
{
	return SearchServIDInServProduct(sServID,pptCur);
}
int CheckShmServProductAccess()
{
	if(ServProductAccess()==0) return 0;
	/**THE STATE UNMOUNT HERE,WAIT FOR DETACHED**/
	WaitSec(50);
	return ServProductAccess();
}
int MSearchServIDInServProduct(char sServID[],char sStartTime[],
	int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res = 0;
	TRIEEXT *pNodeSeg;
	POINTER ioffsetHead;
	struct IServProductStruct *pDataSeg,*pTemp;
	
	if(CheckShmServProductAccess()<0)
		return SHM_ACCESS_FAIL;
		
	pNodeSeg=SERVPRODUCT.pNode;
	pDataSeg=SERVPRODUCT.pData;
	
	if(SearchTrieE(SERVPRODUCT.ioffsetServID,pNodeSeg,sServID,
		&ioffsetHead)==NOTFOUND)	return NOTFOUND;
			
	while(ioffsetHead!=-1){

		pTemp=SERVPRODUCTTRIEEXT(ioffsetHead);

		/***����״̬������Чʱ�����ʱ��***/
		if(strcmp(pTemp->sState,"F0A")==0&&
			strcmp(sStartTime,pTemp->sStateDate)>=0){
			if((res=(*getdata_fun)(p,(void*)pTemp))<0){
				/*�������*/
				(*getdata_fun)(NULL,NULL);
				return res;
			}
		}
		/***��ʷ״̬������Чʱ��С��ʱ��***/
		if(strcmp(pTemp->sState,"F0H")==0){
		/*	strcmp(sStartTime,pTemp->sStateDate)<0){ */
			if((res=(*getdata_fun)(p,(void*)pTemp))<0){
				/*�������*/
				(*getdata_fun)(NULL,NULL);
				return res;
			}
		}
		ioffsetHead=NEXT_SERVPRODUCT__SERVID(ioffsetHead);	
	}	
	
	if(CheckShmServProductAccess()<0)
		return SHM_ACCESS_FAIL;
	
	return res;
}

/***************************************************************
*
*		�ۺϲ��Ҳ���API					*
*	ע�⣺�ò��ֱ����ʼ�����еĹ����ڴ漰ACCTITEMTYPE	*
***************************************************************/

int IInitInterface()
{
	int res=0;
	
	if(IInitShmServ()<0){
		printf("��ʼ��SERV�����.\n");
		res|=NOEXIST_SERV;
	}

	if(IInitShmServAcct()<0){
		printf("��ʼ��SERVACCT����.\n");
		res|=NOEXIST_SERV_ACCT;
	}

	if(IInitShmAcct()<0){
		printf("��ʼ��ACCT����.\n");
		res|=NOEXIST_ACCT;
	}
	if(IInitShmServProduct()<0){
		printf("��ʼ��SERVPRODUCT����.\n");
		res|=NOEXIST_SERV_PRODUCT;
	}

	return res;
}

int IDetachInterface()
{
	
	IDetachShmServ();
	IDetachShmServAcct();
	IDetachShmAcct();
	IDetachShmServProduct();	
	return 0;
}	


int USearchAccNbr(char sAccNbr[],char sStartTime[15],int iAcctItemTypeID,
	int (*getdata_fun)(void *p,void *pHead),void *p,char sAcctID[])
{
	int res,i;
	
	POINTER ioffsetHead;
	
	struct IServStruct *pTemp;
	struct IServAcctStruct *pTempServAcct;
	
	
	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;
	
	/*������������*/
	if(SearchAccNbrInServ(sAccNbr,sStartTime,&pTemp)==NOTFOUND)
		return NOTFOUND;
	/*ȡ����*/
	res=(*getdata_fun)(p,(void*)pTemp);
	
	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;
	
	
/*����SERV-ACCT��*/
	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	if(SearchTrieE(SERVACCT.ioffsetServID,SERVACCT.pNode,pTemp->sServID,
		&ioffsetHead)==NOTFOUND){
			
		if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
		strcpy(sAcctID,pTemp->sDefaultAcctID);
		
		return res;
	}
			
	while(ioffsetHead!=-1){
		
		pTempServAcct=SERVACCTTRIEEXT(ioffsetHead);
		
		if(strcmp(pTempServAcct->sState,"F0A")==0){
			
			/*�Ҳ���Ӫҵ��Ŀ*/
			if((i=GetSaleAcctItemType(iAcctItemTypeID))==-1){
				
				if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
				strcpy(sAcctID,pTemp->sDefaultAcctID);
		
				return res;
			}
			if(i==pTempServAcct->iAcctItemTypeID){
				
				if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
				strcpy(sAcctID,pTempServAcct->sAcctID);
		
				return res;
			}
		}
		
		ioffsetHead=NEXT_SERVACCT__SERVID(ioffsetHead);	
	}
	
	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	strcpy(sAcctID,pTemp->sDefaultAcctID);
				
	return res;
}


int USearchServID(char sServID[],int iServSeqNbr,int iAcctItemTypeID,char sAcctID[])
{
	int res,i;
	
	POINTER ioffsetHead;
	
	struct IServStruct *pTemp;
	struct IServAcctStruct *pTempServAcct;
	
	
	if((res = CheckShmServAccess())<0) 
		return SHM_ACCESS_FAIL;
	
	/*������������*/
	if(SearchServIDInServ(sServID,iServSeqNbr,&pTemp)==NOTFOUND)
		return NOTFOUND;
	
	if((res = CheckShmServAccess())<0) 
		return SHM_ACCESS_FAIL;
	
	
/*����SERV-ACCT��*/
	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	if(SearchTrieE(SERVACCT.ioffsetServID,SERVACCT.pNode,pTemp->sServID,
		&ioffsetHead)==NOTFOUND){
			
		if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
		strcpy(sAcctID,pTemp->sDefaultAcctID);
		
		return MOVE_ITEM_SUCCESS;
	}
			
	while(ioffsetHead!=-1){
		
		pTempServAcct=SERVACCTTRIEEXT(ioffsetHead);
		
		if(strcmp(pTempServAcct->sState,"F0A")==0){
			
			/*�Ҳ���Ӫҵ��Ŀ*/
			if((i=GetSaleAcctItemType(iAcctItemTypeID))==-1){
				
				if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
				strcpy(sAcctID,pTemp->sDefaultAcctID);
		
				return MOVE_ITEM_SUCCESS;
			}
			if(i==pTempServAcct->iAcctItemTypeID){
				
				if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
				strcpy(sAcctID,pTempServAcct->sAcctID);
		
				return MOVE_ITEM_SUCCESS;
			}
		}
		
		ioffsetHead=NEXT_SERVACCT__SERVID(ioffsetHead);	
	}
	
	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	strcpy(sAcctID,pTemp->sDefaultAcctID);
				
	return MOVE_ITEM_SUCCESS;
}

int USearchServIDE(char sServID[],int iServSeqNbr,int iAcctItemTypeID,
	char sAcctID[],char sAccNbr[])
{
	int res,i;
	
	POINTER ioffsetHead;
	
	struct IServStruct *pTemp;
	struct IServAcctStruct *pTempServAcct;
	
	if((res = CheckShmServAccess())<0) 
		return SHM_ACCESS_FAIL;
	
	/*������������*/
	if(SearchServIDInServ(sServID,iServSeqNbr,&pTemp)==NOTFOUND)
		return NOTFOUND;
	
	if((res = CheckShmServAccess())<0) 
		return SHM_ACCESS_FAIL;
	
	strcpy(sAccNbr,pTemp->sAccNbr);	

/*����SERV-ACCT��*/
	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	if(SearchTrieE(SERVACCT.ioffsetServID,SERVACCT.pNode,pTemp->sServID,
		&ioffsetHead)==NOTFOUND){
			
		if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
		strcpy(sAcctID,pTemp->sDefaultAcctID);
		
		return MOVE_ITEM_SUCCESS;
	}
			
	while(ioffsetHead!=-1){
		
		pTempServAcct=SERVACCTTRIEEXT(ioffsetHead);
		
		if(strcmp(pTempServAcct->sState,"F0A")==0){
			
			/*�Ҳ���Ӫҵ��Ŀ*/
			if((i=GetSaleAcctItemType(iAcctItemTypeID))==-1){
				
				if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
				strcpy(sAcctID,pTemp->sDefaultAcctID);
		
				return MOVE_ITEM_SUCCESS;
			}
			if(i==pTempServAcct->iAcctItemTypeID){
				
				if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
		
				strcpy(sAcctID,pTempServAcct->sAcctID);
		
				return MOVE_ITEM_SUCCESS;
			}
		}
		
		ioffsetHead=NEXT_SERVACCT__SERVID(ioffsetHead);	
	}
	
	if(CheckShmServAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	strcpy(sAcctID,pTemp->sDefaultAcctID);
				
	return MOVE_ITEM_SUCCESS;
}
int USearchAcctID(char sAcctID[],int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res;
	struct IAcctStruct *pTemp;
	
	if(CheckShmAcctAccess()<0) return SHM_ACCESS_FAIL;

	if(SearchAcctIDInAcct(sAcctID,&pTemp)==NOTFOUND) return NOTFOUND;

	/*ȡ����*/
	res=(*getdata_fun)(p,(void*)pTemp);
	
	if(CheckShmAcctAccess()<0) return SHM_ACCESS_FAIL;
	
	return res;
}

int get_serv_seq(void *po,void *pi)
{
	int *piServSeqNbr=(int *)po;
	struct IServStruct    *pSource=(struct IServStruct    *)pi;

	*piServSeqNbr=	pSource->iServSeqNbr;
	return MOVE_ITEM_SUCCESS;

}

int get_serv_state(void *po,void *pi)
{
	char  *sState=(char *)po;
	struct IServStruct    *pSource=(struct IServStruct    *)pi;

	strcpy(sState,	pSource->sState);
	
	return MOVE_ITEM_SUCCESS;

}
int USearchServIDInServE(char sServID[],char sStartTime[],
	int (*getdata_fun)(void *p,void *pHead),void *p)
{
	int res = 0;
	
	struct IServStruct *pTemp;
	
	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;

	
	/*������������*/
	if(SearchServIDInServE(sServID,sStartTime,&pTemp)==NOTFOUND)
		return NOTFOUND;
	/*ȡ����*/
	res=(*getdata_fun)(p,(void*)pTemp);
	
	if(CheckShmServAccess()<0) return SHM_ACCESS_FAIL;
	
	return res;
}


int USearchSeqNbrInServ(char sServID[11],char sCycleBeginDate[15],
	char sCycleEndDate[15],int *piServSeqNbr)
{
	int res;
	char sState[4],*sAcctItemDate;
		
	strcpy(sState,"");
	if(USearchServIDInServE(sServID,sCycleEndDate,
		get_serv_state,(void *)sState)<=0) return -1;

	if(strcmp(sState,"F0Y")==0|| strcmp(sState,"F0P")==0)
		sAcctItemDate=sCycleEndDate;
	else
		sAcctItemDate=sCycleBeginDate;
	
	if((res=USearchServIDInServE(sServID,sAcctItemDate,
		get_serv_seq,(void *)piServSeqNbr))<=0) return -1;

	return res;
}
