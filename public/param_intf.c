#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <trie.h>
#include <wwdir.h>
#include <bintree.h>
#include <wwsem.h>
#include <wwshm.h>

#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <expr_supp.h>
#include "base_supp.h"
#include "param_intf.h"

struct TollTariffStruct *apTollTariff[MAXTARIFFID];
struct DisctRuleStruct  *apDisctRule[MAXDISCTRULEID];
struct ExprDefStruct    *apExprDef[MAXEXPRID];

int  aiAcctItemTypeAnti[MAXACCTITEMTYPE];
char asAcctItemTypeKind[MAXACCTITEMTYPE];

int SHM_PCB_KEY=0;
int SEM_PCB_ID=0;
void *PSHM=NULL;
int GetPcbKey()
{
	int iRet;
	char sTemp[128],sPath[128];

	GetIniName(sPath);

	iRet=ReadString(sPath,"bss","param","pcb_key",sTemp);	

	ERROR_RETURNZ(iRet<0,"读取bill.ini文件失败");
	
	ERROR_RETURNA((strlen(sTemp)==0),"bill.ini->bss->param-%s无对应配置",
		"pcb_key");
/*
	if((pc=strstr(sTemp,"0x"))!=NULL||
		(pc=strstr(sTemp,"0X"))!=NULL)
		iKey=HexStrToInt(pc+2);
	else
		iKey=atoi(sTemp);
*/	
	return Str2Int(sTemp);
}
/*参数从Shm到MemTable*/
int MoveTableShmToList(char sTableName[31],struct FileControlStruct **pptHead)
{
	POINTER ioffsetCur;
	struct ShmTableStruct 	*pShmTab;
	struct ShmPcbStruct 	*pPcb;
	int iRecCnt=0,i=0;

	*pptHead=NULL;
	
	CheckPcbShmValid();
	
	pPcb=(struct ShmPcbStruct *)PSHM;
	
	for(i=0;i<pPcb->iTabCnt;i++){
		if(strcmp(sTableName,pPcb->ShmTab[i].sTableName)==0)
			break;
	}
	pShmTab=&(pPcb->ShmTab[i]);
	if(i==pPcb->iTabCnt){/*共享内存没有指定的参数数据*/
		WriteAlertMsg("共享内存内没有%s表",sTableName);
		DetachShm(PSHM);
		PSHM=NULL;
		return -1;
	}

	ioffsetCur=	pShmTab->ioffset;
	
	while(iRecCnt<pShmTab->iRecCnt){

		iRecCnt++;
		if(item2list(pptHead,(void*)PPCBDATA(PSHM,ioffsetCur),
			pShmTab->iRecLen)<0){
			WriteAlertMsg("加载共享内存表%s到本地链表失败",
				pShmTab->sTableName);
			DetachShm(PSHM);
			PSHM=NULL;
			return -1;
		}
		ioffsetCur+=pShmTab->iRecLen;
	}
	return 0;
}
int MoveShmToMem(int (*MInit)())
{
	int i=0;
	while(i<3){
		if(MInit()>=0) return 0;
		sleep(10);
		i++;
	}
	return -1;
}
/********号段表支持***********/
int comp_insert_list_t130_area_code_e(LIST *pValue,LIST*pHead)
{
	struct T130AreaCodeStruct *pSource=(struct T130AreaCodeStruct *)pValue;
	struct T130AreaCodeStruct *pTarget=(struct T130AreaCodeStruct *)pHead;

	int res=0;
	if((res=strcmp(pSource->sHead,pTarget->sHead))!=0) return res;
	/*ID和SEQ是导序的*/
	if((res=pTarget->iHeadID-pSource->iHeadID)!=0) return res;
	if((res=pTarget->iSeqNbr-pSource->iSeqNbr)!=0) return res;
	return res;

}
void assign_insert_trie_t130_area_code_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_t130_area_code_e);
}
int SearchT130AreaCode(char sAccNbr[13],char sStartTime[],
	struct T130AreaCodeStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	TRIE *ptHead=NULL;
	static struct FileControlStruct *pControl=NULL;
	struct T130AreaCodeStruct *p=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyTrie(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==TRUE){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("T130_AREA_CODE",&pList)<0){
			WriteAlertMsg("访问共享内存表T130_AREA_CODE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct T130AreaCodeStruct *)(pTemp->pData);
			
			if(InsertTrie(&ptHead,p->sHead, (void *)p,
				assign_insert_trie_t130_area_code_e)<0){
				WriteAlertMsg("生成TRIE失败T130_AREA_CODE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	if(SearchTrie(ptHead, sAccNbr,(void**)&p)==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;

	while(p!=NULL){

		if(strncmp(sAccNbr,p->sHead,strlen(p->sHead))==0){
			MY_MATCH_ARCH(sStartTime,p,pptCur);
		}
		p=p->pNext;
	}
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
}
int MInitT130AreaCode()
{
	struct T130AreaCodeStruct *pNoUse=NULL;
	
	return SearchT130AreaCode("","",&pNoUse);
}
/**区号查找支持函数**/
int SearchAreaCodeDesc(char sAreaCode[],struct AreaCodeDescStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	TRIE *ptHead=NULL;
	static struct FileControlStruct *pControl=NULL;
	struct AreaCodeDescStruct *p=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyTrie(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==TRUE){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("AREA_CODE_DESC",&pList)<0){
			WriteAlertMsg("访问共享内存表AREA_CODE_DESC失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct AreaCodeDescStruct *)(pTemp->pData);
			
			if(InsertTrie(&ptHead,p->sAreaCode, (void *)p,
				assign_insert_trie)<0){
				WriteAlertMsg("生成TRIE失败AREA_CODE_DESC");
				return -1;
			}
		}
		ReHookTrie(ptHead,ptHead);
		iFirstFlag=false;
	}
	
	if((SearchTrie(ptHead,sAreaCode,(void**)&p))==NOTFOUND) 
		return NOTFOUND;
	
	while(p!=NULL){
		if(strncmp(sAreaCode,p->sAreaCode,strlen(p->sAreaCode))==0){
			*pptCur=p;
			return FOUND;
		}
		p=p->pNext;
	}	
	return NOTFOUND;
}
int MInitAreaCodeDesc()
{
	struct AreaCodeDescStruct *pNoUse=NULL;
	return SearchAreaCodeDesc("",&pNoUse);
}
int SearchCityCodeDesc(char sCityCode[],struct AreaCodeDescStruct **pptCur)
{

	static int	iFirstFlag=true;
	static	TRIE *ptHead=NULL;
	static struct FileControlStruct *pControl=NULL;
	struct AreaCodeDescStruct *p=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyTrie(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==TRUE){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("AREA_CODE_DESC",&pList)<0){
			WriteAlertMsg("访问共享内存表AREA_CODE_DESC失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct AreaCodeDescStruct *)(pTemp->pData);
			
			if(InsertTrie(&ptHead,p->sCityCode, (void *)p,
				assign_insert_trie)<0){
				WriteAlertMsg("生成TRIE失败AREA_CODE_DESC");
				return -1;
			}
		}
		ReHookTrie(ptHead,ptHead);
		iFirstFlag=false;
	}
	
	if((SearchTrie(ptHead,sCityCode,(void**)&p))==NOTFOUND) 
		return NOTFOUND;
	
	while(p!=NULL){
		if(strcmp(sCityCode,p->sCityCode)==0){
			*pptCur=p;
			return FOUND;
		}
		p=p->pNext;
	}	
	return NOTFOUND;
}
int MInitCityCodeDesc()
{
	struct AreaCodeDescStruct *pNoUse=NULL;
	return SearchCityCodeDesc("",&pNoUse);
}

/***国际电信运营对照表**********/
int comp_insert_list_telecom_carrier_e(LIST *pValue,LIST*pHead)
{
	struct TelecomCarrierStruct *pSource=(struct TelecomCarrierStruct *)pValue;
	struct TelecomCarrierStruct *pTarget=(struct TelecomCarrierStruct *)pHead;

	int res=0;
	if((res=strcmp(pSource->sImsiHead,pTarget->sImsiHead))!=0) return res;
	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	/*ID和SEQ是导序的*/
	if((res=pTarget->iHeadID-pSource->iHeadID)!=0) return res;
	if((res=pTarget->iSeqNbr-pSource->iSeqNbr)!=0) return res;
	return res;

}
void assign_insert_trie_telecom_carrier_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_telecom_carrier_e);
}
int SearchTelecomCarrier(char sImsi[],char sMsc[],char sStartTime[],
	struct TelecomCarrierStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	TRIE *ptHead=NULL;
	struct TelecomCarrierStruct *p=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyTrie(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==TRUE){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TELECOM_CARRIER",&pList)<0){
			WriteAlertMsg("访问共享内存表TELECOM_CARRIER失败");
			return -1;
		}

		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TelecomCarrierStruct *)(pTemp->pData);
			
			if(InsertTrie(&ptHead,p->sImsiHead, (void *)p,
				assign_insert_trie_telecom_carrier_e)<0){
				WriteAlertMsg("生成TRIE失败TELECOM_CARRIER");
				return -1;
			}
		}
		ReHookTrie(ptHead,ptHead);
		iFirstFlag=false;
	}
	
	if((SearchTrie(ptHead,sImsi,(void**)&p))==NOTFOUND) 
		return NOTFOUND;
	
	*pptCur=NULL;

	while(p!=NULL){

		if(strncmp(sImsi,p->sImsiHead,strlen(p->sImsiHead))==0&&
			strcmp(sMsc,p->sMsc)==0){
			MY_MATCH_ARCH(sStartTime,p,pptCur);
		}
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
}
int MInitTelecomCarrier()
{
	struct TelecomCarrierStruct *pNoUse=NULL;
	return SearchTelecomCarrier("","","",&pNoUse);
}


/*MSC查找*/
int SearchMsc(char sMsc[],struct MscStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	TRIE *ptHead=NULL;
	struct MscStruct *p=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyTrie(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("MSC",&pList)<0){
			WriteAlertMsg("访问共享内存表MSC失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct MscStruct *)(pTemp->pData);
			
			if(InsertTrie(&ptHead,p->sMsc, (void *)p,
				assign_insert_trie)<0){
				WriteAlertMsg("生成TRIE失败MSC");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	if((SearchTrie(ptHead,sMsc,(void**)&p))==NOTFOUND) 
		return NOTFOUND;
	
	while(p!=NULL){
		if(strcmp(sMsc,p->sMsc)==0){
			*pptCur=p;
			return FOUND;
		}
		p=p->pNext;
	}	
	return NOTFOUND;
}
int MInitMsc()
{
	struct MscStruct *pNoUse=NULL;
	return SearchMsc("",&pNoUse);
}
/*交叉漫游表*/
int data_search_bintree_across_cell_code_e(void *pValue,void*pData)
{
	struct AcrossCellCodeStruct *pSource=(struct AcrossCellCodeStruct *)pValue;
	struct AcrossCellCodeStruct *pTarget=(struct AcrossCellCodeStruct *)pData;

/*数据比较部分*/
	int res=0;

	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	if((res=strcmp(pSource->sLac,pTarget->sLac))!=0) return res;
	if((res=strcmp(pSource->sCellID,pTarget->sCellID))!=0) return res;
	if((res=strcmp(pSource->sAcrossAreaCode,pTarget->sAcrossAreaCode))!=0) return res;

	return res;
}
int comp_insert_list_across_cell_code_e(LIST *pValue,LIST*pHead)
{
	struct AcrossCellCodeStruct *pSource=(struct AcrossCellCodeStruct *)pValue;
	struct AcrossCellCodeStruct *pTarget=(struct AcrossCellCodeStruct *)pHead;

	int res=0;
	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	if((res=strcmp(pSource->sLac,pTarget->sLac))!=0) return res;
	if((res=strcmp(pSource->sCellID,pTarget->sCellID))!=0) return res;
	if((res=strcmp(pSource->sAcrossAreaCode,pTarget->sAcrossAreaCode))!=0) return res;
	
	if((res=pTarget->iAcrossCodeID-pSource->iAcrossCodeID)!=0) return res;
	if((res=pTarget->iSeqNbr-pSource->iSeqNbr)!=0) return res;
	return res;

}
void assign_insert_bintree_across_cell_code_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_across_cell_code_e);
}
int SearchAcrossCellCode(char sMsc[],char sLac[],char sCellID[],char sAreaCode[],
	char sStartTime[],struct AcrossCellCodeStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct AcrossCellCodeStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("ACROSS_CELL_CODE",&pList)<0){
			WriteAlertMsg("访问共享内存表ACROSS_CELL_CODE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct AcrossCellCodeStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_across_cell_code_e,
				assign_insert_bintree_across_cell_code_e)<0){
				WriteAlertMsg("生成BINTREE失败ACROSS_CELL_CODE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sMsc,sMsc);
	strcpy(Temp.sLac,sLac);
	strcpy(Temp.sCellID,sCellID);
	strcpy(Temp.sAcrossAreaCode,sAreaCode);
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_across_cell_code_e,
		(void**)&p))==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;
	
	while(p!=NULL){
		MY_MATCH_ARCH(sStartTime,p,pptCur);
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;
	
	return NOTFOUND;
}
int MInitAcrossCellCode()
{
	struct AcrossCellCodeStruct *pNoUse=NULL;
	return SearchAcrossCellCode("","","","","",&pNoUse);
}


/*中继表*/
int data_search_bintree_trunk_e(void *pValue,void*pData)
{
	struct TrunkStruct *pSource=(struct TrunkStruct *)pValue;
	struct TrunkStruct *pTarget=(struct TrunkStruct *)pData;

/*数据比较部分*/
	int res=0;

	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	if((res=strcmp(pSource->sTrunk,pTarget->sTrunk))!=0) return res;

	return res;

}
int comp_insert_list_trunk_e(LIST *pValue,LIST*pHead)
{
	struct TrunkStruct *pSource=(struct TrunkStruct *)pValue;
	struct TrunkStruct *pTarget=(struct TrunkStruct *)pHead;

	int res=0;
	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	if((res=strcmp(pSource->sTrunk,pTarget->sTrunk))!=0) return res;

	if((res=pTarget->iTrunkID-pSource->iTrunkID)!=0) return res;
	if((res=pTarget->iSeqNbr-pSource->iSeqNbr)!=0) return res;
	return res;

}
void assign_insert_bintree_trunk_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_trunk_e);
}

int SearchTrunk(char sMsc[],char sTrunk[],char sDirection[],
	char sStartTime[],struct TrunkStruct **pptCur)
{
	char	sTemp[4];
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TrunkStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TRUNK",&pList)<0){
			WriteAlertMsg("访问共享内存表TRUNK失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TrunkStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_trunk_e,
				assign_insert_bintree_trunk_e)<0){
				WriteAlertMsg("生成BINTREE失败TRUNK");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sMsc,sMsc);
	strcpy(Temp.sTrunk,sTrunk);
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_trunk_e,
		(void**)&p))==NOTFOUND) 
		return NOTFOUND;
	
	if(sDirection[0]=='I')		strcpy(sTemp,"IBD");
	else if(sDirection[0]=='O')	strcpy(sTemp,"OBD");
	else	strcpy(sTemp,"IOBD");
	
	*pptCur=NULL;
	
	while(p!=NULL){
		
		if(strchr(sTemp,p->sDirection[0])!=NULL){
			MY_MATCH_ARCH(sStartTime,p,pptCur);
		}
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
}
int MInitTrunk()
{
	struct TrunkStruct *pNoUse=NULL;
	
	return SearchTrunk("","","","",&pNoUse);
}

/*基站表*/
int data_search_bintree_cell_code_e(void *pValue,void*pData)
{
	struct CellCodeStruct *pSource=(struct CellCodeStruct *)pValue;
	struct CellCodeStruct *pTarget=(struct CellCodeStruct *)pData;

	int res=0;
	
	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	if((res=strcmp(pSource->sLac,pTarget->sLac))!=0) return res;
	if((res=strcmp(pSource->sCellID,pTarget->sCellID))!=0) return res;

	return res;
}
int comp_insert_list_cell_code_e(LIST *pValue,LIST*pHead)
{
	struct CellCodeStruct *pSource=(struct CellCodeStruct *)pValue;
	struct CellCodeStruct *pTarget=(struct CellCodeStruct *)pHead;

	int res=0;
	if((res=strcmp(pSource->sMsc,pTarget->sMsc))!=0) return res;
	if((res=strcmp(pSource->sLac,pTarget->sLac))!=0) return res;
	if((res=strcmp(pSource->sCellID,pTarget->sCellID))!=0) return res;

	if((res=pTarget->iCellCodeID-pSource->iCellCodeID)!=0) return res;
	if((res=pTarget->iSeqNbr-pSource->iSeqNbr)!=0) return res;
	return res;

}
void assign_insert_bintree_cell_code_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_cell_code_e);
}
int SearchCellCode(char sMsc[],char sLac[],char sCellID[],
	char sStartTime[],struct CellCodeStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct CellCodeStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("CELL_CODE",&pList)<0){
			WriteAlertMsg("访问共享内存表CELL_CODE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct CellCodeStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_cell_code_e,
				assign_insert_bintree_cell_code_e)<0){
				WriteAlertMsg("生成BINTREE失败CELL_CODE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sMsc,sMsc);
	strcpy(Temp.sLac,sLac);
	strcpy(Temp.sCellID,sCellID);
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_cell_code_e,
		(void**)&p))==NOTFOUND){
		strcpy(Temp.sLac,"*");
		if((SearchBin(ptHead,&Temp,data_search_bintree_cell_code_e,
			(void**)&p))==NOTFOUND) {
		
			strcpy(Temp.sLac,sLac);
			strcpy(Temp.sCellID,"*");
			if((SearchBin(ptHead,&Temp,data_search_bintree_cell_code_e,
				(void**)&p))==NOTFOUND) return NOTFOUND;
		}
	}

	*pptCur=NULL;
	
	while(p!=NULL){
		
		MY_MATCH_ARCH(sStartTime,p,pptCur);

		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
}
int MInitCellCode()
{
	struct CellCodeStruct *pNoUse=NULL;
	
	return SearchCellCode("","","","",&pNoUse);
}
int comp_insert_list_head_carr_e(LIST *pValue,LIST*pHead)
{
	struct HeadCarrStruct *pSource=(struct HeadCarrStruct *)pValue;
	struct HeadCarrStruct *pTarget=(struct HeadCarrStruct *)pHead;

	int res=0;
	if((res=strcmp(pSource->sHead,pTarget->sHead))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	
	if((res=pTarget->iHeadID-pSource->iHeadID)!=0) return res;
	if((res=pTarget->iSeqNbr-pSource->iSeqNbr)!=0) return res;

	return res;

}
void assign_insert_trie_head_carr_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_head_carr_e);
}
/*号段运营商表*/
int SearchHeadCarr(char sHead[],char sAreaCode[],char sStartTime[],
	struct HeadCarrStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	TRIE *ptHead=NULL;
	struct HeadCarrStruct *p=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyTrie(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("HEAD_CARR",&pList)<0){
			WriteAlertMsg("访问共享内存表HEAD_CARR失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct HeadCarrStruct *)(pTemp->pData);
			
			if(InsertTrie(&ptHead,p->sHead, (void *)p,
				assign_insert_trie_head_carr_e)<0){
				WriteAlertMsg("生成TRIE失败HEAD_CARR");
				return -1;
			}
		}
		ReHookTrie(ptHead,ptHead);
		iFirstFlag=false;
	}
/*号码升8位的特殊处理*/
	if(sHead[0]>='2'&&sHead[0]<='8'&&strlen(sHead)==8&&
		SearchTrie(ptHead,sHead,(void**)&p)==FOUND){
		
		*pptCur=NULL;
		
		while(p!=NULL){
			
			if(strncmp(sHead,p->sHead,strlen(p->sHead))==0&&
				strcmp(sAreaCode,p->sAreaCode)==0&&p->iLen==8){
				MY_MATCH_ARCH(sStartTime,p,pptCur);
			}
			p=p->pNext;
		}
		if((*pptCur)!=NULL) return FOUND;
	}
	if((SearchTrie(ptHead,sHead,(void**)&p))==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;

	while(p!=NULL){
		struct ICommSearchStruct *pTemp;
		char sCarrierID[5];
		
/*		if(SearchCommTrie("NP_TC_CARRID",0,sHead,sStartTime,&pTemp)
			==FOUND){
			GetStrValFromCS(pTemp,sCarrierID);
			p->iSettCarrierID=atoi(sCarrierID);
		}
*/
		if(strcmp(sAreaCode,p->sAreaCode)==0&&
			(((p->iLen==0&&strcmp(sHead,p->sHead)==0)||
			    (p->iLen!=0&&p->iLen!=8&&
			     strncmp(sHead,p->sHead,strlen(p->sHead))==0)))){
			MY_MATCH_ARCH(sStartTime,p,pptCur);
		}
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
}
int MInitHeadCarr()
{
	struct HeadCarrStruct *pNoUse=NULL;
	
	return SearchHeadCarr("","","",&pNoUse);
}

int data_search_bintree_ticket_field_e(void *pValue,void*pData)
{
	struct TicketFieldStruct *pSource=(struct TicketFieldStruct *)pValue;
	struct TicketFieldStruct *pTarget=(struct TicketFieldStruct *)pData;

	return pSource->iFieldID-pTarget->iFieldID;
}
int SetPointToExprValue(struct TicketFieldStruct *p)
{
	int iIndex;
	
	if(p->sUseType[0]!=NEW_FIELD_USE) return 0;
	
	if(p->sDataType[0]==VARTYPE_INT){
		/*注册变量*/
		RegVarItem(get_t_integer,put_t_integer,
			VARTYPE_INT,'f',p->sGetValueFun);
		iIndex=AddTicketField(p->sGetValueFun,VARTYPE_INT);
	}
	else{
		RegVarItem(get_t_string,put_t_string,
			VARTYPE_STR,'f',p->sGetValueFun);
		iIndex=AddTicketField(p->sGetValueFun,VARTYPE_STR);
	}
	if(iIndex<0) return -1;
	p->pValue=TFIELD[iIndex].u.sValue;
	return 0;
}
int SearchTicketField(int iTicketFieldID,struct TicketFieldStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TicketFieldStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TICKET_FIELD",&pList)<0){
			WriteAlertMsg("访问共享内存表TICKET_FIELD失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TicketFieldStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_ticket_field_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败TICKET_FIELD");
				return -1;
			}
			if(SetPointToExprValue(p)<0){
				WriteAlertMsg("设置 POINT 到公式变量失败");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iFieldID=iTicketFieldID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_ticket_field_e,(void**)pptCur);
}
int MInitTicketField()
{
	struct TicketFieldStruct *pNoUse=NULL;
	
	return SearchTicketField(0,&pNoUse);
}

int data_search_bintree_ticket_field_rule_e(void *pValue,void*pData)
{
	struct TicketFieldRuleStruct *pSource=(struct TicketFieldRuleStruct *)pValue;
	struct TicketFieldRuleStruct *pTarget=(struct TicketFieldRuleStruct *)pData;

/*数据比较部分*/
	int res=0;

	if((res=(pSource->iID-pTarget->iID))!=0) return res;

	if((res=strcmp(pSource->sUseType,pTarget->sUseType))!=0) return res;

	return res;

}
int comp_insert_list_ticket_field_rule_e(LIST *pValue,LIST*pHead)
{
	struct TicketFieldRuleStruct *pSource=(struct TicketFieldRuleStruct *)pValue;
	struct TicketFieldRuleStruct *pTarget=(struct TicketFieldRuleStruct *)pHead;

	return pSource->iPriority-pTarget->iPriority;
}
void assign_insert_bintree_ticket_field_rule_e(void **ppHead,void *pData)
{
	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_ticket_field_rule_e);
}
int SearchTicketFieldRule(int iID,char sUseType[],
	struct TicketFieldRuleStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TicketFieldRuleStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TICKET_FIELD_RULE",&pList)<0){
			WriteAlertMsg("访问共享内存表TICKET_FIELD_RULE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TicketFieldRuleStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_ticket_field_rule_e,
				assign_insert_bintree_ticket_field_rule_e)<0){
				WriteAlertMsg("生成BINTREE失败TICKET_FIELD_RULE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iID=iID;
	strcpy(Temp.sUseType,sUseType);
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_ticket_field_rule_e,(void**)pptCur);
}
int MInitTicketFieldRule()
{
	struct TicketFieldRuleStruct *pNoUse=NULL;
	return SearchTicketFieldRule(0,"",&pNoUse);
}

int data_search_bintree_ticket_field_value_e(void *pValue,void*pData)
{
	struct TicketFieldValueStruct *pSource=(struct TicketFieldValueStruct *)pValue;
	struct TicketFieldValueStruct *pTarget=(struct TicketFieldValueStruct *)pData;

	return pSource->iRuleID-pTarget->iRuleID;
}

int SearchTicketFieldValue(int iRuleID,struct TicketFieldValueStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TicketFieldValueStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TICKET_FIELD_VALUE",&pList)<0){
			WriteAlertMsg("访问共享内存表TICKET_FIELD_VALUE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TicketFieldValueStruct *)(pTemp->pData);
			p->iValue=atoi(p->sValue);
			p->iValueLen=strlen(p->sValue);
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_ticket_field_value_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败TICKET_FIELD_VALUE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iRuleID=iRuleID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_ticket_field_value_e,(void**)pptCur);
}
int MInitTicketFieldValue()
{
	struct TicketFieldValueStruct *pNoUse=NULL;
	
	return SearchTicketFieldValue(0,&pNoUse);
}
int data_search_bintree_split_rule_e(void *pValue,void*pData)
{
	struct SplitRuleStruct *pSource=(struct SplitRuleStruct *)pValue;
	struct SplitRuleStruct *pTarget=(struct SplitRuleStruct *)pData;


	int res=0;

	if((res=(pSource->iTemplateRuleID-pTarget->iTemplateRuleID))!=0) return res;
	if((res=strcmp(pSource->sSplitType,pTarget->sSplitType))!=0) return res;

	return res;

}
int comp_insert_list_split_rule_e(LIST *pValue,LIST*pHead)
{
	
	struct SplitRuleStruct *pSource=(struct SplitRuleStruct *)pValue;
	struct SplitRuleStruct *pTarget=(struct SplitRuleStruct *)pHead;

	return pSource->iPriority-pTarget->iPriority;
}

void assign_insert_bintree_split_rule_e(void **ppHead,void *pData)
{
/*	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_split_rule_e);
*/
	struct SplitRuleStruct *p=(struct SplitRuleStruct *)pData;
	p->pChild=NULL;
	InsertList((LIST**)ppHead,(LIST*)pData);
}
struct SplitRuleStruct *GetSplitRuleByParent(
	struct SplitRuleStruct **pptHead,int iParentID)
{
	struct SplitRuleStruct *pNew=NULL,*pOld=NULL,*pTemp,*ptHead=*pptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(iParentID==pTemp->iParentID)
			InsertListSort((LIST**)&pNew,(LIST*)pTemp,
				comp_insert_list_split_rule_e);
		else
			InsertList((LIST**)&pOld,(LIST*)pTemp);
	}
	*pptHead=pOld;
	return pNew;
}
int	AppendChildSplitRule(struct SplitRuleStruct *ptHead,
	struct SplitRuleStruct **ppTail)
{
	struct SplitRuleStruct *pTemp;
	
	if((*ppTail)==NULL) return false;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		pTemp->pChild=GetSplitRuleByParent(ppTail,pTemp->iSplitRuleID);
		
		/*不是叶子节点，且直接丢弃话单设为入库*/
/*		if(pTemp->pChild!=NULL&&pTemp->iTicketTypeID<0)
			pTemp->iTicketTypeID=0;
*/
		if(AppendChildSplitRule(pTemp->pChild,ppTail)==false)
			return false;
	}
	return true;
}
int regular_split_rule_list(void **ppData)
{
	struct SplitRuleStruct *pOld,*pNew;
	
	pOld=(struct SplitRuleStruct *)(*ppData);

	pNew=GetSplitRuleByParent(&pOld,-1);
	AppendChildSplitRule(pNew,&pOld);
	*ppData=(void*)pNew;
	return 0;
}
int SearchSplitRule(int iTemplateRuleID,char sSplitType[],
	struct SplitRuleStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct SplitRuleStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("SPLIT_RULE",&pList)<0){
			WriteAlertMsg("访问共享内存表SPLIT_RULE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct SplitRuleStruct *)(pTemp->pData);

			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_split_rule_e,
				assign_insert_bintree_split_rule_e)<0){
				WriteAlertMsg("生成BINTREE失败SPLIT_RULE");
				return -1;
			}
		}
		iFirstFlag=false;
		TravelBin(ptHead,regular_split_rule_list);
	}
	
	Temp.iTemplateRuleID=iTemplateRuleID;
	strcpy(Temp.sSplitType,sSplitType);
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_split_rule_e,(void**)pptCur);
}
int SearchTemplateRuleArray(int iTemplateRuleID,int aiTemplateRule[])
{
	int i=0;
	
	while(aiTemplateRule[i]!=-1){
		if(iTemplateRuleID==aiTemplateRule[i]) return FOUND;
		i++;
	}
	return NOTFOUND;
}
int GetTemplateSplitStr(char sTemplateRule[],char sSplitStr[])
{
	int iCnt,i,aiTemplateRule[30];
	struct SplitRuleStruct *p;
	struct FileControlStruct *pControl,*pList=NULL,*pTemp;

	strcpy(sSplitStr,"");

        iCnt=ParseArgv(sTemplateRule,(int)(':'));
        for(i=0;i<iCnt;i++)
                aiTemplateRule[i]=atoi(ParseToken[i]);

	aiTemplateRule[i]=-1;

	if(MoveTableShmToList("SPLIT_RULE",&pList)<0){
		WriteAlertMsg("访问共享内存表SPLIT_RULE失败");
		return -1;
	}

	pControl=pList;
	while(pList!=NULL){
		pTemp=pList;
		pList=pList->pNext;
		
		p=(struct SplitRuleStruct *)(pTemp->pData);

		if(SearchTemplateRuleArray(p->iTemplateRuleID,
			aiTemplateRule)==FOUND){			
			if(strstr(sSplitStr,p->sSplitType)==NULL)
				strcat(sSplitStr,p->sSplitType);
		}
	}

	listfree(&pControl);

	return 0;
}
int MInitSplitRule()
{
	struct SplitRuleStruct *pNoUse=NULL;
	
	return SearchSplitRule(0,"",&pNoUse);
}
int data_search_bintree_ticket_type_e(void *pValue,void*pData)
{
	struct TicketTypeStruct *pSource=(struct TicketTypeStruct *)pValue;
	struct TicketTypeStruct *pTarget=(struct TicketTypeStruct *)pData;

	return strcmp(pSource->sSplitType,pTarget->sSplitType);
}


int SearchTicketType(char sSplitType[],struct TicketTypeStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TicketTypeStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TICKET_TYPE",&pList)<0){
			WriteAlertMsg("访问共享内存表TICKET_TYPE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TicketTypeStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_ticket_type_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败TICKET_TYPE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sSplitType,sSplitType);
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_ticket_type_e,(void**)pptCur);
}
int MInitTicketType()
{
	struct TicketTypeStruct *pNoUse=NULL;
	
	return SearchTicketType("",&pNoUse);
}

int data_search_bintree_ticket_type_tariff_e(void *pValue,void*pData)
{
	struct TicketTypeTariffStruct *pSource=(struct TicketTypeTariffStruct *)pValue;
	struct TicketTypeTariffStruct *pTarget=(struct TicketTypeTariffStruct *)pData;


	return pSource->iTicketTypeID-pTarget->iTicketTypeID;
}


int SearchTicketTypeTariff(int iTicketTypeID,struct TicketTypeTariffStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TicketTypeTariffStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TICKET_TYPE_TARIFF",&pList)<0){
			WriteAlertMsg("访问共享内存表TICKET_TYPE_TARIFF失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TicketTypeTariffStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_ticket_type_tariff_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败TICKET_TYPE_TARIFF");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iTicketTypeID=iTicketTypeID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_ticket_type_tariff_e,(void**)pptCur);
}
int MInitTicketTypeTariff()
{
	struct TicketTypeTariffStruct *pNoUse=NULL;
	
	return SearchTicketTypeTariff(0,&pNoUse);
}
int data_search_bintree_ticket_based_disct_e(void *pValue,void*pData)
{
	struct TicketBasedDisctStruct *pSource=(struct TicketBasedDisctStruct *)pValue;
	struct TicketBasedDisctStruct *pTarget=(struct TicketBasedDisctStruct *)pData;


	return pSource->iDisctRuleID-pTarget->iDisctRuleID;
}


int SearchTicketBasedDisct(int iDisctRuleID,struct TicketBasedDisctStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TicketBasedDisctStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TICKET_BASED_DISCT",&pList)<0){
			WriteAlertMsg("访问共享内存表TICKET_BASED_DISCT失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TicketBasedDisctStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_ticket_based_disct_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败TICKET_BASED_DISCT");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iDisctRuleID=iDisctRuleID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_ticket_based_disct_e,(void**)pptCur);
}
int MInitTicketBasedDisct()
{
	struct TicketBasedDisctStruct *pNoUse=NULL;
	
	return SearchTicketBasedDisct(0,&pNoUse);
}

int comp_insert_list_time_span_disct_e(LIST *pValue,LIST*pHead)
{
	struct TimeSpanDisctStruct *pSource=(struct TimeSpanDisctStruct *)pValue;
	struct TimeSpanDisctStruct *pTarget=(struct TimeSpanDisctStruct *)pHead;

	return pSource->iPriority-pTarget->iPriority;
}

void assign_insert_bintree_time_span_disct_e(void **ppHead,void *pData)
{
	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_time_span_disct_e);
}
int data_search_bintree_time_span_disct_e(void *pValue,void*pData)
{
	struct TimeSpanDisctStruct *pSource=(struct TimeSpanDisctStruct *)pValue;
	struct TimeSpanDisctStruct *pTarget=(struct TimeSpanDisctStruct *)pData;


	return pSource->iDisctRuleID-pTarget->iDisctRuleID;
}
int SearchTimeSpanDisct(int iDisctRuleID,struct TimeSpanDisctStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TimeSpanDisctStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TIME_SPAN_DISCT",&pList)<0){
			WriteAlertMsg("访问共享内存表TIME_SPAN_DISCT失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TimeSpanDisctStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_time_span_disct_e,
				assign_insert_bintree_time_span_disct_e)<0){
				WriteAlertMsg("生成BINTREE失败TIME_SPAN_DISCT");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iDisctRuleID=iDisctRuleID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_time_span_disct_e,(void**)pptCur);
}
int MInitTimeSpanDisct()
{
	struct TimeSpanDisctStruct *pNoUse=NULL;
	
	return SearchTimeSpanDisct(0,&pNoUse);
}
int comp_insert_list_expr_disct_e(LIST *pValue,LIST*pHead)
{
	struct ExprDisctStruct *pSource=(struct ExprDisctStruct *)pValue;
	struct ExprDisctStruct *pTarget=(struct ExprDisctStruct *)pHead;

	return pSource->iPriority-pTarget->iPriority;
}

void assign_insert_bintree_expr_disct_e(void **ppHead,void *pData)
{
	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_expr_disct_e);
}
int data_search_bintree_expr_disct_e(void *pValue,void*pData)
{
	struct ExprDisctStruct *pSource=(struct ExprDisctStruct *)pValue;
	struct ExprDisctStruct *pTarget=(struct ExprDisctStruct *)pData;


	return pSource->iDisctRuleID-pTarget->iDisctRuleID;
}


int SearchExprDisct(int iDisctRuleID,struct ExprDisctStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct ExprDisctStruct *p=NULL,Temp;

	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("EXPR_DISCT",&pList)<0){
			WriteAlertMsg("访问共享内存表EXPR_DISCT失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct ExprDisctStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_expr_disct_e,
				assign_insert_bintree_expr_disct_e)<0){
				WriteAlertMsg("生成BINTREE失败EXPR_DISCT");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iDisctRuleID=iDisctRuleID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_expr_disct_e,(void**)pptCur);
}
int MInitExprDisct()
{
	struct ExprDisctStruct *pNoUse=NULL;
	
	return SearchExprDisct(0,&pNoUse);
}
int data_search_bintree_disct_rule_mutex_e(void *pValue,void*pData)
{
	struct DisctRuleMutexStruct *pSource=(struct DisctRuleMutexStruct *)pValue;
	struct DisctRuleMutexStruct *pTarget=(struct DisctRuleMutexStruct *)pData;


	return pSource->iDisctRuleID-pTarget->iDisctRuleID;
}
int SearchDisctRuleMutex(int iDisctRuleID,struct DisctRuleMutexStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct DisctRuleMutexStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("DISCT_RULE_MUTEX",&pList)<0){
			WriteAlertMsg("访问共享内存表DISCT_RULE_MUTEX失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct DisctRuleMutexStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_disct_rule_mutex_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败DISCT_RULE_MUTEX");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iDisctRuleID=iDisctRuleID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_disct_rule_mutex_e,(void**)pptCur);
}
int MInitDisctRuleMutex()
{
	struct DisctRuleMutexStruct *pNoUse=NULL;
	
	return SearchDisctRuleMutex(0,&pNoUse);
}
int SearchTollTariff(struct TollTariffStruct **pptCur)
{
	static int	iFirstFlag=true;
	struct TollTariffStruct *p=NULL,*pTemp;
	static struct TollTariffStruct *ptHead=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TOLL_TARIFF",&pList)<0){
			WriteAlertMsg("访问共享内存表TOLL_TARIFF失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TollTariffStruct *)(pTemp->pData);
			
			if(p->iTariffID<0||p->iTariffID>=MAXTARIFFID)
				continue;
			p->pLoadNext=ptHead;
			ptHead=p;
		}
		iFirstFlag=false;
	}
	pTemp=ptHead;
	while(pTemp!=NULL){
		InsertList((LIST**)pptCur,(LIST*)pTemp);
		pTemp=pTemp->pLoadNext;
	}
	if(*pptCur==NULL) return NOTFOUND;
	return FOUND;
}
int MInitTollTariff()
{
	struct TollTariffStruct *pNoUse=NULL;
	
	return SearchTollTariff(&pNoUse);
}
int SearchDisctRule(int (*comp_fun)(LIST*),struct DisctRuleStruct **pptCur)
{
	static int	iFirstFlag=true;
	struct DisctRuleStruct *p=NULL;
	static struct DisctRuleStruct *ptHead=NULL,*pTemp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	*pptCur=NULL;
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("DISCT_RULE",&pList)<0){
			WriteAlertMsg("访问共享内存表DISCT_RULE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct DisctRuleStruct *)(pTemp->pData);
			
			if(p->iDisctRuleID<0||p->iDisctRuleID>=MAXDISCTRULEID)
				continue;
			p->pLoadNext=ptHead;
			ptHead=p;
		}
		iFirstFlag=false;
	}
	pTemp=ptHead;
	while(pTemp!=NULL){
		if(comp_fun!=NULL){
			if(comp_fun((LIST*)pTemp)==0)
				InsertList((LIST**)pptCur,(LIST*)pTemp);
		}
		pTemp=pTemp->pLoadNext;
	}
	if(*pptCur==NULL) return NOTFOUND;
	return FOUND;
}
int MInitDisctRule()
{
	struct DisctRuleStruct *pNoUse=NULL;
	
	return SearchDisctRule(NULL,&pNoUse);
}
int data_search_bintree_expr_def_e(void *pValue,void*pData)
{
	struct ExprDefStruct *pSource=(struct ExprDefStruct *)pValue;
	struct ExprDefStruct *pTarget=(struct ExprDefStruct *)pData;

	return strcmp(pSource->sExprType,pTarget->sExprType);
}

int SearchExprDef(char sExprType[],struct ExprDefStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct ExprDefStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("EXPR_DEF",&pList)<0){
			WriteAlertMsg("访问共享内存表EXPR_DEF失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct ExprDefStruct *)(pTemp->pData);
			/*合法性检查*/
			if(p->iExprID<0||p->iExprID>=MAXEXPRID) continue;
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_expr_def_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败EXPR_DEF");
				return -1;
			}
			PEXPRDEF(p->iExprID)=p;
			p->iCompileFlag=0;
			p->iPriority=0;
			strcpy(p->sParam,"");
			p->pExprBuf=NULL;
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sExprType,sExprType);
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_expr_def_e,(void**)pptCur);
}
int MInitExprDef()
{
	struct ExprDefStruct *pNoUse=NULL;
	return SearchExprDef("",&pNoUse);
}

/*
int data_search_bintree_comm_search_e(void *pValue,void*pData)
{
	int res;
	struct CommSearchStruct *pSource=(struct CommSearchStruct *)pValue;
	struct CommSearchStruct *pTarget=(struct CommSearchStruct *)pData;

	if((res=pSource->iIntKey-pTarget->iIntKey)!=0) return res;
	if((res=strcmp(pSource->sTableName,pTarget->sTableName))!=0) return res;

	return strcmp(pSource->sStrKey,pTarget->sStrKey);
}
int comp_insert_list_comm_search_e(LIST *pValue,LIST*pHead)
{
	struct CommSearchStruct *pSource=(struct CommSearchStruct *)pValue;
	struct CommSearchStruct *pTarget=(struct CommSearchStruct *)pHead;

	int res=0;
	
	if((res=pSource->iIntKey-pTarget->iIntKey)!=0) return res;
	if((res=strcmp(pSource->sTableName,pTarget->sTableName))!=0) return res;
	if((res=strcmp(pSource->sStrKey,pTarget->sStrKey))!=0) return res;

	if((res=strcmp(pTarget->sCreatedDate,pSource->sCreatedDate))!=0) return res;
	if((res=strcmp(pTarget->sStateDate,pSource->sStateDate))!=0) return res;

	return res;

}
void assign_insert_comm_search_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_comm_search_e);
}
*/
int data_search_bintree_comm_search_my(void *p,POINTER ioffData)
{
	int res;

	struct ICommSearchStruct *pSource;
	struct ICommSearchStruct *pTarget;

	pSource=(struct ICommSearchStruct *)p;
	pTarget=(struct ICommSearchStruct *)OPELIST(PSHM,ioffData);

	if((res=pSource->iIntKey-pTarget->iIntKey)!=0) return res;
	if((res=strcmp(pSource->sTableName,pTarget->sTableName))!=0) return res;

	return strcmp(pSource->sKey,pTarget->sKey);
}
void GetStrValFromCS(struct ICommSearchStruct *pi,char sStrVal[])
{
	if(pi->cType=='S'){
		struct SKeyValStruct *p=(struct SKeyValStruct *)&(pi->sKey);
		strcpy(sStrVal,	p->sVal);
	}
	else if(pi->cType=='M'){
		struct MKeyValStruct *p=(struct MKeyValStruct *)&(pi->sKey);
		strcpy(sStrVal,	p->sVal);
	}
	else /*if(cType=='L')*/{
		struct LKeyValStruct *p=(struct LKeyValStruct *)&(pi->sKey);
		strcpy(sStrVal,	p->sVal);
	}
}
void GetStrValFromCSX(struct ICommSearchStruct *pi,int iMaxLen,char sStrVal[])
{
	char sTemp[MY_MAXL_LEN+1];
	
	GetStrValFromCS(pi,sTemp);
	
	strncpy(sStrVal,sTemp,iMaxLen);sStrVal[iMaxLen]=0;

	AllTrim(sStrVal);
}
/*在调用这两个函数之前，需要调用:AttachAllShm或MoveAllShmToMem
连接上共享内存*/
int SearchCommBin(char sTableName[],int iIntKey,char sStrKey[],
	char sStartTime[],struct ICommSearchStruct **pptCur)
{
	POINTER ioffCur;
	struct ShmCscStruct *pc;
	struct ICommSearchStruct Temp,*p;
	
	Temp.iIntKey=	iIntKey;
	strcpy(Temp.sKey,	sStrKey);
	strcpy(Temp.sTableName,	sTableName);

	CheckPcbShmValid();
	
	pc=(struct ShmCscStruct*)OPELIST(PSHM,sizeof(struct ShmPcbStruct));
	
	if(SearchEBin(PSHM,pc->ioffbRoot,&Temp,
		data_search_bintree_comm_search_my,&ioffCur)==NOTFOUND)
		return NOTFOUND;

	*pptCur=NULL;

	while(ioffCur!=-1){
		
		p=(struct ICommSearchStruct*)OPELIST(PSHM,ioffCur);

		MY_MATCH_ARCH(sStartTime,p,pptCur);
		
		ioffCur=p->ioffNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
	
}

int SearchCommTrie(char sTableName[],int iIntKey,char sStrKey[],
	char sStartTime[],struct ICommSearchStruct **pptCur)
{
	POINTER ioffCur;
	struct ShmCscStruct *pc;
	struct ICommSearchStruct Temp,*p;
	
	Temp.iIntKey=	iIntKey;
	strcpy(Temp.sKey,	sStrKey);
	strcpy(Temp.sTableName,	sTableName);
	
	CheckPcbShmValid();

	pc=(struct ShmCscStruct*)OPELIST(PSHM,sizeof(struct ShmPcbStruct));

	if(SearchETrie(PSHM,pc->iofftRoot,sStrKey,&ioffCur)==NOTFOUND)
		return NOTFOUND;

	*pptCur=NULL;
	
	while(ioffCur!=-1){
		
		p=(struct ICommSearchStruct*)OPELIST(PSHM,ioffCur);

		if(iIntKey==p->iIntKey&&
			strncmp(sStrKey,p->sKey,strlen(p->sKey))==0&&
			strcmp(sTableName,p->sTableName)==0){

			MY_MATCH_ARCH(sStartTime,p,pptCur);
		}
		
		ioffCur=p->ioffNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
	
}


/*按照table_name,k1,k2,bgn_key排序*/
int data_insert_bintree_comm_range_e(void *pValue,void*pData)
{
	int res;
	struct CommRangeStruct *pSource=(struct CommRangeStruct *)pValue;
	struct CommRangeStruct *pTarget=(struct CommRangeStruct *)pData;
	
	if((res=strcmp(pSource->sTableName,pTarget->sTableName))!=0) return res;

	return strcmp(pSource->sBgnKey,pTarget->sBgnKey);
}
/*按照table_name,k1,k2,end_key降序*/
int comp_insert_list_comm_range_e(LIST *pValue,LIST*pHead)
{
	struct CommRangeStruct *pSource=(struct CommRangeStruct *)pValue;
	struct CommRangeStruct *pTarget=(struct CommRangeStruct *)pHead;
/*数据比较部分*/
	int res=0;

	if((res=strcmp(pTarget->sTableName,pSource->sTableName))!=0) return res;
	if((res=strcmp(pTarget->sEndKey,pSource->sEndKey))!=0) return res;
	
	if((res=strcmp(pTarget->sCreatedDate,pSource->sCreatedDate))!=0) return res;
	if((res=strcmp(pTarget->sStateDate,pSource->sStateDate))!=0) return res;

	return res;

}
void assign_insert_bintree_comm_range_e(void **ppData,void *pData)
{
	InsertListSort((LIST**)(ppData), (LIST*)pData,
		comp_insert_list_comm_range_e);
}

int data_search_bintree_comm_range_e(void *pValue,void*pData)
{
	int res;
	struct CommRangeStruct *pSource=(struct CommRangeStruct *)pValue;
	struct CommRangeStruct *pTarget=(struct CommRangeStruct *)pData;

	if((res=strcmp(pSource->sTableName,	pTarget->sTableName))!=0) return res;
	
	if(strcmp(pSource->sBgnKey,		pTarget->sBgnKey)<0) return -1;
	if(strcmp(pSource->sBgnKey,		pTarget->sEndKey)>0) return 1;

	return 0;
}

int SearchCommRange(char sTableName[],char sKey[],
	char sStartTime[],struct CommRangeStruct **pptCur)
{
	int i=0;
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct CommRangeStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("COMM_RANGE",&pList)<0){
			WriteAlertMsg("访问共享内存表COMM_RANGE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct CommRangeStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_insert_bintree_comm_range_e,
				assign_insert_bintree_comm_range_e)<0){
				WriteAlertMsg("生成BINTREE失败COMM_RANGE");
				return -1;
			}

		}
		HandShakeBin(ptHead);

		iFirstFlag=false;
	}

	strcpy(Temp.sTableName,sTableName);
	strcpy(Temp.sBgnKey,sKey);
	
	if(SearchBin(ptHead,&Temp,
		data_search_bintree_comm_range_e,(void**)&p)==NOTFOUND)
		return NOTFOUND;

	*pptCur=NULL;

	while(p!=NULL){
		
		i=data_search_bintree_comm_range_e((void*)&Temp,(void*)p);
	
		if(i==0){
			MY_MATCH_ARCH(sStartTime,p,pptCur);
		}
		if(i<0) break;

		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
	
}
int MInitCommRange()
{
	struct CommRangeStruct *pNoUse=NULL;
	return SearchCommRange("","","",&pNoUse);
}

int data_search_bintree_pick_param_e(void *pValue,void*pData)
{
	struct PickParamStruct *pSource=(struct PickParamStruct *)pValue;
	struct PickParamStruct *pTarget=(struct PickParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchPickParam(int iGroupID,struct PickParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct PickParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("PICK_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表PICK_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct PickParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_pick_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败PICK_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_pick_param_e,(void**)pptCur);
}
int MInitPickParam()
{
	struct PickParamStruct *pNoUse=NULL;
	return SearchPickParam(0,&pNoUse);
}
int data_search_bintree_prep_param_e(void *pValue,void*pData)
{
	struct PrepParamStruct *pSource=(struct PrepParamStruct *)pValue;
	struct PrepParamStruct *pTarget=(struct PrepParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchPrepParam(int iGroupID,struct PrepParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct PrepParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("PREP_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表PREP_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct PrepParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_prep_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败PREP_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_prep_param_e,(void**)pptCur);
}
int MInitPrepParam()
{
	struct PrepParamStruct *pNoUse=NULL;
	return SearchPrepParam(0,&pNoUse);
}
int data_search_bintree_bill_param_e(void *pValue,void*pData)
{
	int res=0;
	struct BillParamStruct *pSource=(struct BillParamStruct *)pValue;
	struct BillParamStruct *pTarget=(struct BillParamStruct *)pData;

	if((res=strcmp(pSource->sAppCode,pTarget->sAppCode))!=0) return res;
	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchBillParam(char sAppCode[],int iGroupID,
	struct BillParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct BillParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("BILL_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表BILL_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct BillParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_bill_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败BILL_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	strcmp(Temp.sAppCode,sAppCode);
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_bill_param_e,(void**)pptCur);
}
int MInitBillParam()
{
	struct BillParamStruct *pNoUse=NULL;
	return SearchBillParam("",0,&pNoUse);
}
int data_search_bintree_insert_param_e(void *pValue,void*pData)
{
	struct InstParamStruct *pSource=(struct InstParamStruct *)pValue;
	struct InstParamStruct *pTarget=(struct InstParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchInstParam(int iGroupID,struct InstParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct InstParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("INST_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表INST_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct InstParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_insert_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败INST_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_insert_param_e,(void**)pptCur);
}
int MInitInstParam()
{
	struct InstParamStruct *pNoUse=NULL;
	return SearchInstParam(0,&pNoUse);
}
int data_search_bintree_disp_param_e(void *pValue,void*pData)
{
	struct DispParamStruct *pSource=(struct DispParamStruct *)pValue;
	struct DispParamStruct *pTarget=(struct DispParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}
int SearchDispParam(int iGroupID,struct DispParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct DispParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("DISP_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表DISP_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct DispParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_insert_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败DISP_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_disp_param_e,(void**)pptCur);
}
int MInitDispParam()
{
	struct DispParamStruct *pNoUse=NULL;
	return SearchDispParam(0,&pNoUse);
}
int SearchSwitch(struct SwitchStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	struct SwitchStruct *ptHead=NULL;
	struct SwitchStruct *p=NULL,*pTemp,*ptLkHead=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("SWITCH",&pList)<0){
			WriteAlertMsg("访问共享内存表SWITCH失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct SwitchStruct *)(pTemp->pData);
			
			p->pLoadNext=ptHead;
			ptHead=p;
		}
		iFirstFlag=false;
	}
	p=ptHead;
	while(p!=NULL){
		pTemp=p;
		p=p->pLoadNext;
		
		InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	*pptCur=ptLkHead;
	if(ptLkHead!=NULL) return FOUND;
	return NOTFOUND;
}
int MInitSwitch()
{
	struct SwitchStruct *pNoUse=NULL;
	return SearchSwitch(&pNoUse);
}
int data_search_bintree_cmd_template_e(void *pValue,void*pData)
{
	struct CmdTemplateStruct *pSource=(struct CmdTemplateStruct *)pValue;
	struct CmdTemplateStruct *pTarget=(struct CmdTemplateStruct *)pData;
	int res;
	
	if((res=pSource->iSwitchTypeID-pTarget->iSwitchTypeID)!=0) return res;
	return strcmp(pSource->sStandardCode,pTarget->sStandardCode);
}

int SearchCmdTemplate(int iSwitchTypeID,char sStandardCode[],
	struct CmdTemplateStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct CmdTemplateStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("CMD_TEMPLATE",&pList)<0){
			WriteAlertMsg("访问共享内存表CMD_TEMPLATE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct CmdTemplateStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_cmd_template_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败CMD_TEMPLATE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iSwitchTypeID=iSwitchTypeID;
	strcpy(Temp.sStandardCode,sStandardCode);
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_cmd_template_e,(void**)pptCur);
}
int MInitCmdTemplate()
{
	struct CmdTemplateStruct *pNoUse=NULL;
	return SearchCmdTemplate(0,"",&pNoUse);
}
int SearchNbrHead(char sServiceType[],char sFieldType[],
	char sAccNbr[],struct NbrHeadStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	TRIE *ptHead=NULL;
	struct NbrHeadStruct *p=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyTrie(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("NBR_HEAD",&pList)<0){
			WriteAlertMsg("访问共享内存表NBR_HEAD失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct NbrHeadStruct *)(pTemp->pData);
			
			if(InsertTrie(&ptHead,p->sHead,(void *)p,
				assign_insert_trie)<0){
				WriteAlertMsg("生成trie失败NBR_HEAD");
				return -1;
			}
		}
		ReHookTrie(ptHead,ptHead);
		iFirstFlag=false;
	}
	
	if(SearchTrie(ptHead,sAccNbr,(void**)&p)==NOTFOUND)
		return NOTFOUND;
	while(p!=NULL){
		if(strncmp(sAccNbr,p->sHead,strlen(p->sHead))==0&&
			strcmp(sServiceType,p->sServiceType)==0&&
			strcmp(sFieldType,p->sFieldType)==0){
			*pptCur=p;
			return FOUND;
		}
		p=p->pNext;
	}
	return NOTFOUND;
	
}
int MInitNbrHead()
{
	struct NbrHeadStruct *pNoUse=NULL;
	return SearchNbrHead("","","",&pNoUse);
}
int SearchAcctItemType(struct AcctItemTypeStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	struct AcctItemTypeStruct *ptHead=NULL;
	struct AcctItemTypeStruct *p=NULL,*pTemp,*ptLkHead=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("ACCT_ITEM_TYPE",&pList)<0){
			WriteAlertMsg("访问共享内存表ACCT_ITEM_TYPE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct AcctItemTypeStruct *)(pTemp->pData);
			
			p->pLoadNext=ptHead;
			ptHead=p;
		}
		iFirstFlag=false;
	}
	p=ptHead;
	while(p!=NULL){
		pTemp=p;
		p=p->pLoadNext;
		
		InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	*pptCur=ptLkHead;
	if(ptLkHead!=NULL) return FOUND;
	return NOTFOUND;
}
int MInitAcctItemType()
{
	struct AcctItemTypeStruct *pNoUse=NULL;
	return SearchAcctItemType(&pNoUse);
}

int data_search_bintree_sett_rule_e(void *pValue,void*pData)
{
	struct SettRuleStruct *pSource=(struct SettRuleStruct *)pValue;
	struct SettRuleStruct *pTarget=(struct SettRuleStruct *)pData;

	int res=0;
	
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
	
	if((res=strcmp(pSource->sTariffType,pTarget->sTariffType))!=0) return res;
	return res;
}
int comp_insert_list_sett_rule_e(LIST *pValue,LIST*pHead)
{
	struct SettRuleStruct *pSource=(struct SettRuleStruct *)pValue;
	struct SettRuleStruct *pTarget=(struct SettRuleStruct *)pHead;

	int res=0;
	
	if((res=pSource->iTicketTypeID-pTarget->iTicketTypeID)!=0) return res;
	
	if((res=strcmp(pSource->sTariffType,pTarget->sTariffType))!=0) return res;
	
	if((res=pSource->iSettRuleID-pTarget->iSettRuleID)!=0) return res;
	if((res=pSource->iSeqNbr-pTarget->iSeqNbr)!=0) return res;

	return res;

}
void assign_insert_bintree_sett_rule_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_sett_rule_e);
}

int SearchSettRule(int iTicketTypeID,char sTariffType[],char sStartTime[],
	struct SettRuleStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct SettRuleStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("SETT_RULE",&pList)<0){
			WriteAlertMsg("访问共享内存表SETT_RULE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct SettRuleStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_sett_rule_e,
				assign_insert_bintree_sett_rule_e)<0){
				WriteAlertMsg("生成BINTREE失败SETT_RULE");
				return -1;
			}

		}
		iFirstFlag=false;
	}
	Temp.iTicketTypeID=	iTicketTypeID;
	
	if(SearchBin(ptHead,&Temp,
		data_search_bintree_sett_rule_e,(void**)&p)==NOTFOUND)
		return NOTFOUND;
	
	*pptCur=NULL;

	while(p!=NULL){
		MY_MATCH_ARCH(sStartTime,p,pptCur);
		p=p->pNext;
	}
	if((*pptCur)!=NULL) return FOUND;

	return NOTFOUND;
	
}
int MInitSettRule()
{
	struct SettRuleStruct *pNoUse=NULL;
	return SearchSettRule(0,"","",&pNoUse);
}

int data_search_bintree_sett_cycle_e(void *pValue,void*pData)
{
	int res;
	struct SettCycleStruct *pSource=(struct SettCycleStruct *)pValue;
	struct SettCycleStruct *pTarget=(struct SettCycleStruct *)pData;

	if((res=strcmp(pSource->sModule,pTarget->sModule))!=0) return res;
	return pSource->iSettCarrierID-pTarget->iSettCarrierID;
}

int SearchSettCycle(char sModule[],int iSettCarrierID,
	struct SettCycleStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct SettCycleStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("SETT_CYCLE",&pList)<0){
			WriteAlertMsg("访问共享内存表SETT_CYCLE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct SettCycleStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_sett_cycle_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败SETT_CYCLE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	strcpy(Temp.sModule,sModule);
	Temp.iSettCarrierID=	iSettCarrierID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_sett_cycle_e,(void**)pptCur);
}
int MInitSettCycle()
{
	struct SettCycleStruct *pNoUse=NULL;
	
	return SearchSettCycle("",0,&pNoUse);
}

int data_search_bintree_sett_cycle_id_e(void *pValue,void*pData)
{
	struct SettCycleStruct *pSource=(struct SettCycleStruct *)pValue;
	struct SettCycleStruct *pTarget=(struct SettCycleStruct *)pData;

	return pSource->iSettCycleID-pTarget->iSettCycleID;
}

int SearchSettCycleID(int iSettCycleID,struct SettCycleStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct SettCycleStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("SETT_CYCLE",&pList)<0){
			WriteAlertMsg("访问共享内存表SETT_CYCLE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct SettCycleStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_sett_cycle_id_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败SETT_CYCLE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	Temp.iSettCycleID=		iSettCycleID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_sett_cycle_id_e,(void**)pptCur);
}
int MInitSettCycleID()
{
	struct SettCycleStruct *pNoUse=NULL;
	
	return SearchSettCycleID(0,&pNoUse);
}

int SearchLatn(int iLatnID,struct LatnStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	struct LatnStruct *ptHead=NULL;
	struct LatnStruct *p=NULL,*pTemp,*ptLkHead=NULL;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("LATN",&pList)<0){
			WriteAlertMsg("访问共享内存表LATN失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct LatnStruct *)(pTemp->pData);
			
			p->pLoadNext=ptHead;
			ptHead=p;
		}
		iFirstFlag=false;
	}
	p=ptHead;
	while(p!=NULL){
		pTemp=p;
		p=p->pLoadNext;
		
		if(iLatnID==-1||iLatnID==pTemp->iLatnID)
			InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	*pptCur=ptLkHead;
	if(ptLkHead!=NULL) return FOUND;
	return NOTFOUND;
}
int MInitLatn()
{
	struct LatnStruct *pNoUse=NULL;
	return SearchLatn(0,&pNoUse);
}
int data_search_bintree_sett_area_e(void *pValue,void*pData)
{
	struct SettAreaStruct *pSource=(struct SettAreaStruct *)pValue;
	struct SettAreaStruct *pTarget=(struct SettAreaStruct *)pData;

	return pSource->iSettAreaID-pTarget->iSettAreaID;
}
int SearchSettArea(int iSettAreaID,struct SettAreaStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct SettAreaStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("SETT_AREA",&pList)<0){
			WriteAlertMsg("访问共享内存表SETT_AREA失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct SettAreaStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_sett_area_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败SETT_AREA");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iSettAreaID=iSettAreaID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_sett_area_e,(void**)pptCur);
}
int MInitSettArea()
{
	struct SettAreaStruct *pNoUse=NULL;
	return SearchSettArea(0,&pNoUse);
}

int data_search_bintree_put_param_e(void *pValue,void*pData)
{
	struct PutParamStruct *pSource=(struct PutParamStruct *)pValue;
	struct PutParamStruct *pTarget=(struct PutParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchPutParam(int iGroupID,struct PutParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct PutParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("PUT_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表PUT_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct PutParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_put_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败PUT_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_put_param_e,(void**)pptCur);
}
int MInitPutParam()
{
	struct PutParamStruct *pNoUse=NULL;
	return SearchPutParam(0,&pNoUse);
}
int data_search_bintree_comm_param_e(void *pValue,void*pData)
{
	struct CommParamStruct *pSource=(struct CommParamStruct *)pValue;
	struct CommParamStruct *pTarget=(struct CommParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchCommParam(int iGroupID,struct CommParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct CommParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("COMM_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表COMM_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct CommParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_comm_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败COMM_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_comm_param_e,(void**)pptCur);
}
int MInitCommParam()
{
	struct CommParamStruct *pNoUse=NULL;
	return SearchCommParam(0,&pNoUse);
}
int data_search_bintree_acct_param_e(void *pValue,void*pData)
{
	struct AcctParamStruct *pSource=(struct AcctParamStruct *)pValue;
	struct AcctParamStruct *pTarget=(struct AcctParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}
int SearchAcctParam(int iGroupID,struct AcctParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct AcctParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("ACCT_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表ACCT_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct AcctParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_acct_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败ACCT_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_acct_param_e,(void**)pptCur);
}
int MInitAcctParam()
{
	struct AcctParamStruct *pNoUse=NULL;
	return SearchAcctParam(0,&pNoUse);
}

int data_search_bintree_intf_param_e(void *pValue,void*pData)
{
	struct IntfParamStruct *pSource=(struct IntfParamStruct *)pValue;
	struct IntfParamStruct *pTarget=(struct IntfParamStruct *)pData;

	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchIntfParam(int iGroupID,struct IntfParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct IntfParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("INTF_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表INTF_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct IntfParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_intf_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败INTF_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iGroupID=iGroupID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_intf_param_e,(void**)pptCur);
}
int MInitIntfParam()
{
	struct IntfParamStruct *pNoUse=NULL;
	return SearchIntfParam(0,&pNoUse);
}

int data_search_bintree_recycle_param_e(void *pValue,void*pData)
{
	int res;
	struct RcylParamStruct *pSource=(struct RcylParamStruct *)pValue;
	struct RcylParamStruct *pTarget=(struct RcylParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iTaskSeqNbr-pTarget->iTaskSeqNbr;
}

int SearchRcylParam(char sSourceID[],int iTaskSeqNbr,
	struct RcylParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct RcylParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("RCYL_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表RCYL_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct RcylParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_recycle_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败RCYL_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iTaskSeqNbr=iTaskSeqNbr;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_recycle_param_e,(void**)pptCur);
}
int MInitRcylParam()
{
	struct RcylParamStruct *pNoUse=NULL;
	return SearchRcylParam("",0,&pNoUse);
}

int data_search_bintree_roll_param_e(void *pValue,void*pData)
{
	int res;
	struct RollParamStruct *pSource=(struct RollParamStruct *)pValue;
	struct RollParamStruct *pTarget=(struct RollParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iTaskSeqNbr-pTarget->iTaskSeqNbr;
}

int SearchRollParam(char sSourceID[],int iTaskSeqNbr,
	struct RollParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct RollParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("ROLL_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表ROLL_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct RollParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_roll_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败ROLL_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iTaskSeqNbr= iTaskSeqNbr;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_roll_param_e,(void**)pptCur);
}
int MInitRollParam()
{
	struct RollParamStruct *pNoUse=NULL;
	return SearchRollParam("",0,&pNoUse);
}

int data_search_bintree_tariff_relation_e(void *pValue,void*pData)
{
	struct TollTariffStruct *pSource=(struct TollTariffStruct *)pValue;
	struct TollTariffStruct *pTarget=(struct TollTariffStruct *)pData;


	return strcmp(pSource->sTariffRef,pTarget->sTariffRef);
}
int comp_insert_list_toll_tariff_e(LIST *pValue,LIST*pHead)
{
	struct TollTariffStruct *pSource=(struct TollTariffStruct *)pValue;
	struct TollTariffStruct *pTarget=(struct TollTariffStruct *)pHead;

	int res=0;
	/*ID和SEQ是导序的*/
	if((res=pTarget->iTariffID-pSource->iTariffID)!=0) return res;
	if((res=pTarget->iSeqNbr-pSource->iSeqNbr)!=0) return res;
	return res;

}
void assign_insert_bintree_toll_tariff_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_toll_tariff_e);
}
int SearchTollTariffRef(char sTariffRef[],struct TollTariffStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TollTariffStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TOLL_TARIFF",&pList)<0){
			WriteAlertMsg("访问共享内存表TOLL_TARIFF失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TollTariffStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_tariff_relation_e,
				assign_insert_bintree_toll_tariff_e)<0){
				WriteAlertMsg("生成BINTREE失败TOLL_TARIFF");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sTariffRef,sTariffRef);
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_tariff_relation_e,(void**)&pptCur);
}
int MInitTollTariffRef()
{
	struct TollTariffStruct *pNoUse=NULL;
	
	return SearchTollTariffRef("",&pNoUse);
}

int data_search_bintree_pick_task_param_e(void *pValue,void*pData)
{
	int res=0;
	struct PickTaskParamStruct *pSource=(struct PickTaskParamStruct *)pValue;
	struct PickTaskParamStruct *pTarget=(struct PickTaskParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchPickTaskParam(char sSourceID[],int iGroupID,
	struct PickTaskParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct PickTaskParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("PICK_TASK_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表PICK_TASK_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct PickTaskParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_pick_task_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败PICK_TASK_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iGroupID=iGroupID;
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_pick_task_param_e,
		(void**)&p))==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;
	
	while(p!=NULL){
		MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;
	
	return NOTFOUND;
}
int MInitPickTaskParam()
{
	struct PickTaskParamStruct *pNoUse=NULL;
	return SearchPickTaskParam("",0,&pNoUse);
}

int data_search_bintree_prep_task_param_e(void *pValue,void*pData)
{
	int res=0;
	struct PrepTaskParamStruct *pSource=(struct PrepTaskParamStruct *)pValue;
	struct PrepTaskParamStruct *pTarget=(struct PrepTaskParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchPrepTaskParam(char sSourceID[],int iGroupID,
	struct PrepTaskParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct PrepTaskParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("PREP_TASK_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表PREP_TASK_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct PrepTaskParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_prep_task_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败PREP_TASK_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iGroupID=iGroupID;
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_prep_task_param_e,
		(void**)&p))==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;
	
	while(p!=NULL){
		MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;
	
	return NOTFOUND;

}
int MInitPrepTaskParam()
{
	struct PrepTaskParamStruct *pNoUse=NULL;
	return SearchPrepTaskParam("",0,&pNoUse);
}
int data_search_bintree_bill_task_param_e(void *pValue,void*pData)
{
	int res=0;
	struct BillTaskParamStruct *pSource=(struct BillTaskParamStruct *)pValue;
	struct BillTaskParamStruct *pTarget=(struct BillTaskParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	if((res=strcmp(pSource->sAppCode,pTarget->sAppCode))!=0) return res;
	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchBillTaskParam(char sSourceID[],char sAppCode[],int iGroupID,
	struct BillTaskParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct BillTaskParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("BILL_TASK_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表BILL_TASK_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct BillTaskParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_bill_task_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败BILL_TASK_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}

	strcpy(Temp.sSourceID,sSourceID);
	strcpy(Temp.sAppCode,sAppCode);
	Temp.iGroupID=iGroupID;
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_bill_task_param_e,
		(void**)&p))==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;
	
	while(p!=NULL){
		MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;
	
	return NOTFOUND;
}
int MInitBillTaskParam()
{
	struct BillTaskParamStruct *pNoUse=NULL;
	return SearchBillTaskParam("","",0,&pNoUse);
}

int data_search_bintree_acct_task_param_e(void *pValue,void*pData)
{
	int res=0;
	struct AcctTaskParamStruct *pSource=(struct AcctTaskParamStruct *)pValue;
	struct AcctTaskParamStruct *pTarget=(struct AcctTaskParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchAcctTaskParam(char sSourceID[],int iGroupID,
	struct AcctTaskParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct AcctTaskParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("ACCT_TASK_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表ACCT_TASK_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct AcctTaskParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_acct_task_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败ACCT_TASK_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iGroupID=iGroupID;
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_acct_task_param_e,
		(void**)&p))==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;
	
	while(p!=NULL){
		MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;
	
	return NOTFOUND;
}
int MInitAcctTaskParam()
{
	struct AcctTaskParamStruct *pNoUse=NULL;
	return SearchAcctTaskParam("",0,&pNoUse);
}
int data_search_bintree_inst_task_param_e(void *pValue,void*pData)
{
	int res=0;
	struct InstTaskParamStruct *pSource=(struct InstTaskParamStruct *)pValue;
	struct InstTaskParamStruct *pTarget=(struct InstTaskParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iGroupID-pTarget->iGroupID;
}

int SearchInstTaskParam(char sSourceID[],int iGroupID,
	struct InstTaskParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct InstTaskParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("INST_TASK_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表INST_TASK_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct InstTaskParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_inst_task_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败INST_TASK_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iGroupID=iGroupID;
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_inst_task_param_e,
		(void**)&p))==NOTFOUND) return NOTFOUND;
	
	*pptCur=NULL;
	
	while(p!=NULL){
		MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
		p=p->pNext;
	}
	
	if((*pptCur)!=NULL) return FOUND;
	
	return NOTFOUND;

}
int MInitInstTaskParam()
{
	struct InstTaskParamStruct *pNoUse=NULL;
	return SearchInstTaskParam("",0,&pNoUse);
}
int data_search_bintree_flow_tache_e(void *pValue,void*pData)
{
	int res=0;
	struct FlowTacheStruct *pSource=(struct FlowTacheStruct *)pValue;
	struct FlowTacheStruct *pTarget=(struct FlowTacheStruct *)pData;

	if((res=pSource->iTaskID-pTarget->iTaskID)!=0) return res;
	return pSource->iFlowID-pTarget->iFlowID;
}

int SearchFlowTache(int iTaskID,int iFlowID,
	struct FlowTacheStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct FlowTacheStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("FLOW_TACHE",&pList)<0){
			WriteAlertMsg("访问共享内存表FLOW_TACHE失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct FlowTacheStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_flow_tache_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败FLOW_TACHE");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iFlowID=iFlowID;
	Temp.iTaskID=iTaskID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_flow_tache_e,(void**)pptCur);
}
int MInitFlowTache()
{
	struct FlowTacheStruct *pNoUse=NULL;
	return SearchFlowTache(0,0,&pNoUse);
}
int data_search_bintree_flow_task_e(void *pValue,void*pData)
{
	struct FlowTaskStruct *pSource=(struct FlowTaskStruct *)pValue;
	struct FlowTaskStruct *pTarget=(struct FlowTaskStruct *)pData;

	return pSource->iParamID-pTarget->iParamID;
}

int SearchFlowTask(int iParamID,struct FlowTaskStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct FlowTaskStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("FLOW_TASK",&pList)<0){
			WriteAlertMsg("访问共享内存表FLOW_TASK失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct FlowTaskStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_flow_task_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败FLOW_TASK");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iParamID=iParamID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_flow_task_e,(void**)pptCur);
}
int MInitFlowTask()
{
	struct FlowTaskStruct *pNoUse=NULL;
	return SearchFlowTask(0,&pNoUse);
}
int data_search_bintree_task_param_e(void *pValue,void*pData)
{
	struct TaskParamStruct *pSource=(struct TaskParamStruct *)pValue;
	struct TaskParamStruct *pTarget=(struct TaskParamStruct *)pData;

	return pSource->iParamID-pTarget->iParamID;
}

int SearchTaskParam(int iParamID,struct TaskParamStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct TaskParamStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("TASK_PARAM",&pList)<0){
			WriteAlertMsg("访问共享内存表TASK_PARAM失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct TaskParamStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_task_param_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败TASK_PARAM");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iParamID=iParamID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_task_param_e,(void**)pptCur);
}
int MInitTaskParam()
{
	struct TaskParamStruct *pNoUse=NULL;
	return SearchTaskParam(0,&pNoUse);
}
int data_search_bintree_source_desc_e(void *pValue,void*pData)
{
	struct SourceDescStruct *pSource=(struct SourceDescStruct *)pValue;
	struct SourceDescStruct *pTarget=(struct SourceDescStruct *)pData;

	return pSource->iFlowID-pTarget->iFlowID;
}
int comp_insert_list_source_desc_e(LIST *pValue,LIST*pHead)
{
	struct SourceDescStruct *pSource=(struct SourceDescStruct *)pValue;
	struct SourceDescStruct *pTarget=(struct SourceDescStruct *)pHead;

	return strcmp(pSource->sSourceID,pTarget->sSourceID);
}
void assign_insert_bintree_source_desc_e(void **ppData,void *pData)
{

	InsertListSort((LIST**)(ppData),(LIST*)pData,
		comp_insert_list_source_desc_e);
}

int SearchSourceDesc(int iFlowID,struct SourceDescStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct SourceDescStruct *p=NULL,Temp;
	
	static struct FileControlStruct *pControl=NULL;
	
	if(pptCur==NULL){
		listfree(&pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct FileControlStruct *pList=NULL,*pTemp;
		
		if(MoveTableShmToList("SOURCE_DESC",&pList)<0){
			WriteAlertMsg("访问共享内存表SOURCE_DESC失败");
			return -1;
		}
		pControl=pList;
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=(struct SourceDescStruct *)(pTemp->pData);
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_source_desc_e,
				assign_insert_bintree_source_desc_e)<0){
				WriteAlertMsg("生成BINTREE失败SOURCE_DESC");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	
	Temp.iFlowID=iFlowID;
	
	return SearchBin(ptHead,&Temp,
		data_search_bintree_source_desc_e,(void**)pptCur);
}
int MInitSourceDesc()
{
	struct SourceDescStruct *pNoUse=NULL;
	return SearchSourceDesc(0,&pNoUse);
}
void CheckPcbShmValid()
{
	static time_t tLastTime=-1,tThisTime;

	LockSafe(SEM_PCB_ID,0);
	UnlockSafe(SEM_PCB_ID,0);

	/*在客户端连接共享内存前检察就先锁定共享内存，并马上解锁。*/
	/**
	      ------无锁区----|------锁定,刷新----|---无锁区 **/
	/*执行到这里，说明,程序目前在无锁区内******************/
	
	tThisTime=tGetHostTime();

	if(tThisTime-tLastTime>20){
		/* tLastTime==-1,以上条件包含这个条件 */
		int iErrCode=0;

		if(tLastTime==-1){
			SHM_PCB_KEY=GetPcbKey();
			SEM_PCB_ID=AttachSem(SHM_PCB_KEY);
			ERROR_EXIT(SEM_PCB_ID<0,"连接共享内存锁失败.");
		}
		tLastTime=tThisTime;

		/*加入PCB块*/
		if(PSHM!=NULL)DetachShm(PSHM);
		PSHM=AttachShm(SHM_PCB_KEY,&iErrCode,NULL);
		ERROR_EXIT(iErrCode,"连接共享内存失败");
	}
}
void MoveAllShmToMem()
{	
	SHM_PCB_KEY=GetPcbKey();
	SEM_PCB_ID=AttachSem(SHM_PCB_KEY);
	ERROR_EXIT(SEM_PCB_ID<0,"连接共享内存锁失败.");

	CheckPcbShmValid();

	ERROR_EXIT(MoveShmToMem(MInitT130AreaCode)<0,"获取T130_AREA_CODE错误");
	ERROR_EXIT(MoveShmToMem(MInitAreaCodeDesc)<0,"获取AREA_CODE_DESC错误");
	ERROR_EXIT(MoveShmToMem(MInitCityCodeDesc)<0,"获取AREA_CODE_DESC错误");
	ERROR_EXIT(MoveShmToMem(MInitTelecomCarrier)<0,"获取TELECOM_CARRIER错误");
	ERROR_EXIT(MoveShmToMem(MInitMsc)<0,"获取MSC错误");
	ERROR_EXIT(MoveShmToMem(MInitAcrossCellCode)<0,"获取ACROSS_CELL_CODE错误");
	ERROR_EXIT(MoveShmToMem(MInitTrunk)<0,"获取TRUNK错误");
	ERROR_EXIT(MoveShmToMem(MInitCellCode)<0,"获取CELL_CODE错误");
	ERROR_EXIT(MoveShmToMem(MInitHeadCarr)<0,"获取HEAD_CARR错误");
	ERROR_EXIT(MoveShmToMem(MInitTicketField)<0,"获取TICKET_FIELD错误");
	ERROR_EXIT(MoveShmToMem(MInitTicketFieldRule)<0,"获取TICKET_FIELD_RULE错误");
	ERROR_EXIT(MoveShmToMem(MInitTicketFieldValue)<0,"获取TICKET_FIELD_VALUE错误");
	ERROR_EXIT(MoveShmToMem(MInitSplitRule)<0,"获取SPLIT_RULE错误");
	ERROR_EXIT(MoveShmToMem(MInitTicketType)<0,"获取TICKET_TYPE错误");
	ERROR_EXIT(MoveShmToMem(MInitTicketTypeTariff)<0,"获取TICKET_TYPE_TARIFF错误");
	ERROR_EXIT(MoveShmToMem(MInitTicketBasedDisct)<0,"获取TICKET_BASED_DISCT错误");
	ERROR_EXIT(MoveShmToMem(MInitTimeSpanDisct)<0,"获取TIME_SPAN_DISCT错误");
	ERROR_EXIT(MoveShmToMem(MInitExprDisct)<0,"获取EXPR_DISCT错误");
	ERROR_EXIT(MoveShmToMem(MInitDisctRuleMutex)<0,"获取DISCT_RULE_MUTEX错误");
	ERROR_EXIT(MoveShmToMem(MInitTollTariff)<0,"获取TOLL_TARIFF错误");
	ERROR_EXIT(MoveShmToMem(MInitDisctRule)<0,"获取DISCT_RULE错误");
	ERROR_EXIT(MoveShmToMem(MInitExprDef)<0,"获取EXPR_DEF错误");

	ERROR_EXIT(MoveShmToMem(MInitPickParam)<0,"获取PICK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitPrepParam)<0,"获取PREP_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitBillParam)<0,"获取BILL_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitInstParam)<0,"获取INST_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitDispParam)<0,"获取DISP_PARAM错误");

	ERROR_EXIT(MoveShmToMem(MInitCommRange)<0,"获取COMM_RANGE错误");

	ERROR_EXIT(MoveShmToMem(MInitSwitch)<0,"获取SWITCH错误");
	ERROR_EXIT(MoveShmToMem(MInitCmdTemplate)<0,"获取CMD_TEMPLATE错误");
	ERROR_EXIT(MoveShmToMem(MInitNbrHead)<0,"获取NBR_HEAD错误");
	ERROR_EXIT(MoveShmToMem(MInitAcctItemType)<0,"获取ACCT_ITEM_TYPE错误");
	ERROR_EXIT(MoveShmToMem(MInitSettRule)<0,"获取SETT_RULE错误");

	ERROR_EXIT(MoveShmToMem(MInitSettCycle)<0,"获取SETT_CYCLE错误");
	ERROR_EXIT(MoveShmToMem(MInitSettCycleID)<0,"获取SETT_CYCLE错误");
	ERROR_EXIT(MoveShmToMem(MInitLatn)<0,"获取LATN错误");
	ERROR_EXIT(MoveShmToMem(MInitSettArea)<0,"获取SETT_AREA错误");

	ERROR_EXIT(MoveShmToMem(MInitPutParam)<0,"获取PUT_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitCommParam)<0,"获取COMM_PARAM错误");

	ERROR_EXIT(MoveShmToMem(MInitAcctParam)<0,"获取ACCT_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitIntfParam)<0,"获取INTF_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitRcylParam)<0,"获取RCYL_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitRollParam)<0,"获取ROLL_PARAM错误");

	ERROR_EXIT(MoveShmToMem(MInitTollTariffRef)<0,"获取TOLL_TARIFF错误");
	
	ERROR_EXIT(MoveShmToMem(MInitPickTaskParam)<0,"获取PICK_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitPrepTaskParam)<0,"获取PREP_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitBillTaskParam)<0,"获取BILL_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitAcctTaskParam)<0,"获取ACCT_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitInstTaskParam)<0,"获取INST_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitRollTaskParam)<0,"获取ROLL_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitFlowTache)<0,"获取FLOW_TACHE错误");
	ERROR_EXIT(MoveShmToMem(MInitFlowTask)<0,"获取FLOW_TASK错误");
	ERROR_EXIT(MoveShmToMem(MInitTaskParam)<0,"获取TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MInitSourceDesc)<0,"获取SOURCE_DESC错误");
	
}

int MDestroyT130AreaCode()
{
	return SearchT130AreaCode("","",NULL);
}
int MDestroyAreaCodeDesc()
{
	return SearchAreaCodeDesc("",NULL);
}
int MDestroyCityCodeDesc()
{
	return SearchCityCodeDesc("",NULL);
}
int MDestroyTelecomCarrier()
{
	return SearchTelecomCarrier("","","",NULL);
}
int MDestroyMsc()
{
	return SearchMsc("",NULL);
}
int MDestroyAcrossCellCode()
{
	return SearchAcrossCellCode("","","","","",NULL);
}
int MDestroyTrunk()
{	
	return SearchTrunk("","","","",NULL);
}
int MDestroyCellCode()
{
	return SearchCellCode("","","","",NULL);
}
int MDestroyHeadCarr()
{	
	return SearchHeadCarr("","","",NULL);
}
int MDestroyTicketField()
{	
	return SearchTicketField(0,NULL);
}
int MDestroyTicketFieldRule()
{
	return SearchTicketFieldRule(0,"",NULL);
}
int MDestroyTicketFieldValue()
{
	
	return SearchTicketFieldValue(0,NULL);
}
int MDestroySplitRule()
{	
	return SearchSplitRule(0,"",NULL);
}
int MDestroyTicketType()
{	
	return SearchTicketType("",NULL);
}
int MDestroyTicketTypeTariff()
{	
	return SearchTicketTypeTariff(0,NULL);
}
int MDestroyTicketBasedDisct()
{	
	return SearchTicketBasedDisct(0,NULL);
}
int MDestroyTimeSpanDisct()
{	
	return SearchTimeSpanDisct(0,NULL);
}
int MDestroyExprDisct()
{	
	return SearchExprDisct(0,NULL);
}
int MDestroyDisctRuleMutex()
{	
	return SearchDisctRuleMutex(0,NULL);
}
int MDestroyTollTariff()
{	
	return SearchTollTariff(NULL);
}
int MDestroyDisctRule()
{	
	return SearchDisctRule(NULL,NULL);
}
int MDestroyExprDef()
{
	return SearchExprDef("",NULL);
}
int MDestroyPickParam()
{
	return SearchPickParam(0,NULL);
}
int MDestroyPrepParam()
{
	return SearchPrepParam(0,NULL);
}
int MDestroyBillParam()
{
	return SearchBillParam("",0,NULL);
}
int MDestroyInstParam()
{
	return SearchInstParam(0,NULL);
}
int MDestroyDispParam()
{
	return SearchDispParam(0,NULL);
}
int MDestroyCommRange()
{
	return SearchCommRange("","","",NULL);
}

int MDestroySwitch()
{
	return SearchSwitch(NULL);
}
int MDestroyCmdTemplate()
{
	return SearchCmdTemplate(0,"",NULL);
}
int MDestroyNbrHead()
{
	return SearchNbrHead("","","",NULL);
}
int MDestroyAcctItemType()
{
	return SearchAcctItemType(NULL);
}

int MDestroySettRule()
{
	return SearchSettRule(0,"","",NULL);
}
int MDestroySettCycle()
{
	return SearchSettCycle("",0,NULL);

}
int MDestroySettCycleID()
{
	return SearchSettCycleID(0,NULL);
}
int MDestroyLatn()
{
	return SearchLatn(0,NULL);
}
int MDestroySettArea()
{
	return SearchSettArea(0,NULL);
}
int MDestroyPutParam()
{
	return SearchPutParam(0,NULL);
}
int MDestroyCommParam()
{	
	return SearchCommParam(0,NULL);
}
int MDestroyAcctParam()
{	
	return SearchAcctParam(0,NULL);
}
int MDestroyIntfParam()
{	
	return SearchIntfParam(0,NULL);
}
int MDestroyRcylParam()
{	
	return SearchRcylParam("",0,NULL);
}
int MDestroyRollParam()
{	
	return SearchRollParam("",0,NULL);
}
int MDestroyTollTariffRef()
{	
	return SearchTollTariffRef("",NULL);
}
int MDestroyPickTaskParam()
{	
	return SearchPickTaskParam("",0,NULL);
}
int MDestroyPrepTaskParam()
{	
	return SearchPrepTaskParam("",0,NULL);
}
int MDestroyBillTaskParam()
{	
	return SearchBillTaskParam("","",0,NULL);
}
int MDestroyAcctTaskParam()
{	
	return SearchAcctTaskParam("",0,NULL);
}
int MDestroyInstTaskParam()
{	
	return SearchInstTaskParam("",0,NULL);
}
int MDestroyFlowTache()
{	
	return SearchFlowTache(0,0,NULL);
}
int MDestroyFlowTask()
{	
	return SearchFlowTask(0,NULL);
}
int MDestroyTaskParam()
{	
	return SearchTaskParam(0,NULL);
}
int MDestroySourceDesc()
{	
	return SearchSourceDesc(0,NULL);
}
int MDestroyPutTaskParam()
{
	return SearchPutTaskParam("",0,NULL);
}
int MDestroyRcylTaskParam()
{
	return SearchRcylTaskParam("",0,NULL);
}
int MDestroyIntfTaskParam()
{
	return SearchIntfTaskParam("",0,NULL);
}
int MDestroyRollTaskParam()
{
	return SearchRollTaskParam("",0,NULL);
}

void DistroyAllMem()
{
	ERROR_EXIT(MoveShmToMem(MDestroyT130AreaCode)<0,"释放T130_AREA_CODE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyAreaCodeDesc)<0,"释放AREA_CODE_DESC错误");
	ERROR_EXIT(MoveShmToMem(MDestroyCityCodeDesc)<0,"释放AREA_CODE_DESC错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTelecomCarrier)<0,"释放TELECOM_CARRIER错误");
	ERROR_EXIT(MoveShmToMem(MDestroyMsc)<0,"释放MSC错误");
	ERROR_EXIT(MoveShmToMem(MDestroyAcrossCellCode)<0,"释放ACROSS_CELL_CODE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTrunk)<0,"释放TRUNK错误");
	ERROR_EXIT(MoveShmToMem(MDestroyCellCode)<0,"释放CELL_CODE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyHeadCarr)<0,"释放HEAD_CARR错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTicketField)<0,"释放TICKET_FIELD错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTicketFieldRule)<0,"释放TICKET_FIELD_RULE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTicketFieldValue)<0,"释放TICKET_FIELD_VALUE错误");
	ERROR_EXIT(MoveShmToMem(MDestroySplitRule)<0,"释放SPLIT_RULE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTicketType)<0,"释放TICKET_TYPE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTicketTypeTariff)<0,"释放TICKET_TYPE_TARIFF错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTicketBasedDisct)<0,"释放TICKET_BASED_DISCT错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTimeSpanDisct)<0,"释放TIME_SPAN_DISCT错误");
	ERROR_EXIT(MoveShmToMem(MDestroyExprDisct)<0,"释放EXPR_DISCT错误");
	ERROR_EXIT(MoveShmToMem(MDestroyDisctRuleMutex)<0,"释放DISCT_RULE_MUTEX错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTollTariff)<0,"释放TOLL_TARIFF错误");
	ERROR_EXIT(MoveShmToMem(MDestroyDisctRule)<0,"释放DISCT_RULE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyExprDef)<0,"释放EXPR_DEF错误");

	ERROR_EXIT(MoveShmToMem(MDestroyPickParam)<0,"释放PICK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyPrepParam)<0,"释放PREP_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyBillParam)<0,"释放BILL_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyInstParam)<0,"释放INST_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyDispParam)<0,"释放DISP_PARAM错误");
	
	ERROR_EXIT(MoveShmToMem(MDestroyCommRange)<0,"释放COMM_RANGE错误");
	
	ERROR_EXIT(MoveShmToMem(MDestroySwitch)<0,"释放SWITCH错误");
	ERROR_EXIT(MoveShmToMem(MDestroyCmdTemplate)<0,"释放CMD_TEMPLATE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyNbrHead)<0,"释放NBR_HEAD错误");
	
	ERROR_EXIT(MoveShmToMem(MDestroyAcctItemType)<0,"释放ACCT_ITEM_TYPE错误");
	ERROR_EXIT(MoveShmToMem(MDestroySettRule)<0,"释放SETT_RULE错误");
	
	ERROR_EXIT(MoveShmToMem(MDestroySettCycle)<0,"释放SETT_CYCLE错误");
	ERROR_EXIT(MoveShmToMem(MDestroySettCycleID)<0,"释放SETT_CYCLE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyLatn)<0,"释放LATN错误");
	ERROR_EXIT(MoveShmToMem(MDestroySettArea)<0,"释放SETT_AREA错误");
	
	ERROR_EXIT(MoveShmToMem(MDestroyPutParam)<0,"释放PUT_PARAM错误");	
	ERROR_EXIT(MoveShmToMem(MDestroyCommParam)<0,"释放COMM_PARAM错误");

	ERROR_EXIT(MoveShmToMem(MDestroyAcctParam)<0,"释放ACCT_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyIntfParam)<0,"释放INTF_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyRcylParam)<0,"释放RCYL_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyRollParam)<0,"释放ROLL_PARAM错误");

	ERROR_EXIT(MoveShmToMem(MDestroyTollTariffRef)<0,"释放TOLL_TARIFF错误");
	
	ERROR_EXIT(MoveShmToMem(MDestroyPickTaskParam)<0,"释放PICK_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyPrepTaskParam)<0,"释放PREP_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyBillTaskParam)<0,"释放BILL_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyAcctTaskParam)<0,"释放ACCT_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyInstTaskParam)<0,"释放INST_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyRollTaskParam)<0,"释放ROLL_TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroyFlowTache)<0,"释放FLOW_TACHE错误");
	ERROR_EXIT(MoveShmToMem(MDestroyFlowTask)<0,"释放FLOW_TASK错误");
	ERROR_EXIT(MoveShmToMem(MDestroyTaskParam)<0,"释放TASK_PARAM错误");
	ERROR_EXIT(MoveShmToMem(MDestroySourceDesc)<0,"释放SOURCE_DESC错误");
}

int data_search_bintree_put_task_param_e(void *pValue,void*pData)
{
        int res=0;
        struct PutTaskParamStruct *pSource=(struct PutTaskParamStruct *)pValue;
        struct PutTaskParamStruct *pTarget=(struct PutTaskParamStruct *)pData;

        if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
        return pSource->iGroupID-pTarget->iGroupID;
}

int SearchPutTaskParam(char sSourceID[],int iGroupID,
        struct PutTaskParamStruct **pptCur)
{
        static int      iFirstFlag=true;
        static  BINTREE *ptHead=NULL;
        struct PutTaskParamStruct *p=NULL,Temp;

        static struct FileControlStruct *pControl=NULL;

        if(pptCur==NULL){
                listfree(&pControl);
                DestroyBin(ptHead);
                ptHead=NULL;
                pControl=NULL;
                iFirstFlag=true;
                return FOUND;
        }

        if(iFirstFlag==true){

                struct FileControlStruct *pList=NULL,*pTemp;

                if(MoveTableShmToList("PUT_TASK_PARAM",&pList)<0){
                        WriteAlertMsg("访问共享内存表失败 PUT_TASK_PARAM");
                        return -1;
                }
                pControl=pList;
                while(pList!=NULL){
                        pTemp=pList;
                        pList=pList->pNext;

                        p=(struct PutTaskParamStruct *)(pTemp->pData);

                        if(InsertBin(&ptHead,(void *)p,
                                data_search_bintree_put_task_param_e,
                                assign_insert_bintree)<0){
                                WriteAlertMsg("生成BINTREE失败PUT_TASK_PARAM");
                                return -1;
                        }
                }
                iFirstFlag=false;
        }

        strcpy(Temp.sSourceID,sSourceID);
        Temp.iGroupID=iGroupID;

        if((SearchBin(ptHead,&Temp,data_search_bintree_put_task_param_e,
                (void**)&p))==NOTFOUND) return NOTFOUND;

        *pptCur=NULL;

        while(p!=NULL){
                MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
                p=p->pNext;
        }

        if((*pptCur)!=NULL) return FOUND;

        return NOTFOUND;
}

int MInitPutTaskParam()
{
	struct PutTaskParamStruct *pNoUse=NULL;
	return SearchPutTaskParam("",0,&pNoUse);
}

int data_search_bintree_recycle_task_param_e(void *pValue,void*pData)
{
        int res=0;
        struct RcylTaskParamStruct *pSource=(struct RcylTaskParamStruct *)pValue;
        struct RcylTaskParamStruct *pTarget=(struct RcylTaskParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iTaskSeqNbr-pTarget->iTaskSeqNbr;
}

int SearchRcylTaskParam(char sSourceID[],int iTaskSeqNbr,
	struct RcylTaskParamStruct **pptCur)
{
        static int      iFirstFlag=true;
        static  BINTREE *ptHead=NULL;
        struct RcylTaskParamStruct *p=NULL,Temp;

        static struct FileControlStruct *pControl=NULL;

        if(pptCur==NULL){
                listfree(&pControl);
                DestroyBin(ptHead);
                ptHead=NULL;
                pControl=NULL;
                iFirstFlag=true;
                return FOUND;
        }

        if(iFirstFlag==true){

                struct FileControlStruct *pList=NULL,*pTemp;

                if(MoveTableShmToList("RCYL_TASK_PARAM",&pList)<0){
                        WriteAlertMsg("访问共享内存表失败");
                        return -1;
                }
                pControl=pList;
                while(pList!=NULL){
                        pTemp=pList;
                        pList=pList->pNext;

                        p=(struct RcylTaskParamStruct *)(pTemp->pData);

                        if(InsertBin(&ptHead,(void *)p,
                                data_search_bintree_recycle_task_param_e,
                                assign_insert_bintree)<0){
                                WriteAlertMsg("生成BINTREE失败RCYL_TASK_PARAM");
                                return -1;
                        }
                }
                iFirstFlag=false;
        }

        strcpy(Temp.sSourceID,sSourceID);
        Temp.iTaskSeqNbr=	iTaskSeqNbr;
        
        if((SearchBin(ptHead,&Temp,data_search_bintree_recycle_task_param_e,
                (void**)&p))==NOTFOUND) return NOTFOUND;

        *pptCur=NULL;

        while(p!=NULL){
                MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
                p=p->pNext;
        }

        if((*pptCur)!=NULL) return FOUND;

        return NOTFOUND;
}

int MInitRcylTaskParam()
{
	struct RcylTaskParamStruct *pNoUse=NULL;
	return SearchRcylTaskParam("",0,&pNoUse);
}

int data_search_bintree_intf_task_param_e(void *pValue,void*pData)
{
        int res=0;
        struct IntfTaskParamStruct *pSource=(struct IntfTaskParamStruct *)pValue;
        struct IntfTaskParamStruct *pTarget=(struct IntfTaskParamStruct *)pData;

        if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
        return pSource->iGroupID-pTarget->iGroupID;
}

int SearchIntfTaskParam(char sSourceID[],int iGroupID,
        struct IntfTaskParamStruct **pptCur)
{
        static int      iFirstFlag=true;
        static  BINTREE *ptHead=NULL;
        struct IntfTaskParamStruct *p=NULL,Temp;

        static struct FileControlStruct *pControl=NULL;

        if(pptCur==NULL){
                listfree(&pControl);
                DestroyBin(ptHead);
                ptHead=NULL;
                pControl=NULL;
                iFirstFlag=true;
                return FOUND;
        }

        if(iFirstFlag==true){

                struct FileControlStruct *pList=NULL,*pTemp;

                if(MoveTableShmToList("INTF_TASK_PARAM",&pList)<0){
                        WriteAlertMsg("访问共享内存表失败");
                        return -1;
                }
                pControl=pList;
                while(pList!=NULL){
                        pTemp=pList;
                        pList=pList->pNext;

                        p=(struct IntfTaskParamStruct *)(pTemp->pData);

                        if(InsertBin(&ptHead,(void *)p,
                                data_search_bintree_intf_task_param_e,
                                assign_insert_bintree)<0){
                                WriteAlertMsg("生成BINTREE失败INTF_TASK");
                                return -1;
                        }
                }
                iFirstFlag=false;
        }

        strcpy(Temp.sSourceID,sSourceID);
        Temp.iGroupID=iGroupID;

        if((SearchBin(ptHead,&Temp,data_search_bintree_intf_task_param_e,
                (void**)&p))==NOTFOUND) return NOTFOUND;

        *pptCur=NULL;

        while(p!=NULL){
                MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
                p=p->pNext;
        }

        if((*pptCur)!=NULL) return FOUND;

        return NOTFOUND;
}
int MInitIntfTaskParam()
{
	struct IntfTaskParamStruct *pNoUse=NULL;
	return SearchIntfTaskParam("",0,&pNoUse);
}

int data_search_bintree_roll_task_param_e(void *pValue,void*pData)
{
        int res=0;
        struct RollTaskParamStruct *pSource=(struct RollTaskParamStruct *)pValue;
        struct RollTaskParamStruct *pTarget=(struct RollTaskParamStruct *)pData;

	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	return pSource->iTaskSeqNbr-pTarget->iTaskSeqNbr;
}

int SearchRollTaskParam(char sSourceID[],int iTaskSeqNbr,
        struct RollTaskParamStruct **pptCur)
{
        static int      iFirstFlag=true;
        static  BINTREE *ptHead=NULL;
        struct RollTaskParamStruct *p=NULL,Temp;

        static struct FileControlStruct *pControl=NULL;

        if(pptCur==NULL){
                listfree(&pControl);
                DestroyBin(ptHead);
                ptHead=NULL;
                pControl=NULL;
                iFirstFlag=true;
                return FOUND;
        }

        if(iFirstFlag==true){

                struct FileControlStruct *pList=NULL,*pTemp;

                if(MoveTableShmToList("ROLL_TASK_PARAM",&pList)<0){
                        WriteAlertMsg("访问共享内存表失败");
                        return -1;
                }
                pControl=pList;
                while(pList!=NULL){
                        pTemp=pList;
                        pList=pList->pNext;

                        p=(struct RollTaskParamStruct *)(pTemp->pData);

                        if(InsertBin(&ptHead,(void *)p,
                                data_search_bintree_roll_task_param_e,
                                assign_insert_bintree)<0){
                                WriteAlertMsg("生成BINTREE失败ROLL_TASK");
                                return -1;
                        }
                }
                iFirstFlag=false;
        }

        strcpy(Temp.sSourceID,sSourceID);
        Temp.iTaskSeqNbr=	iTaskSeqNbr;
        
        if((SearchBin(ptHead,&Temp,data_search_bintree_roll_task_param_e,
                (void**)&p))==NOTFOUND) return NOTFOUND;

        *pptCur=NULL;

        while(p!=NULL){
                MY_MATCH_ARCH(APPHOSTTIME,p,pptCur);
                p=p->pNext;
        }

        if((*pptCur)!=NULL) return FOUND;

        return NOTFOUND;
}
int MInitRollTaskParam()
{
	struct RollTaskParamStruct *pNoUse=NULL;
	return SearchRollTaskParam("",0,&pNoUse);
}

