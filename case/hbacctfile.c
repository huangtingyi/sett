#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>

#include "dbsupp.h"
#include "updata_ticket.h"
#include "ticket_field.h"

char FILEHEADSTR[45];
int  IFILECNT;
struct ZnwGjAcctStruct *ptZnwAcct=NULL;
struct SpAcctSnIntfStruct *ptInfoSnAcct=NULL;
struct SpAcctZbIntfStruct *ptInfoZbAcct=NULL;
void assign_insert_bintree_znwgj_acct_e(void **ppData,void *pData);
int data_search_bintree_znwgj_acct_e(void *pValue,void*pData);
void assign_insert_bintree_infosn_acct_e(void **ppData,void *pData);
int data_search_bintree_infosn_acct_e(void *pValue,void*pData);
void assign_insert_bintree_infozb_acct_e(void **ppData,void *pData);
int data_search_bintree_infozb_acct_e(void *pValue,void*pData);

void GetOutName(char sFileType[],char sFileName[],char sOutFileName[]);
void mvitem_mfznwgjacct(struct ZnwGjAcctStruct *pi,struct FZnwGjAcctStruct *po);

int GetInfoSnAcct(char sRecord[],struct SpAcctSnIntfStruct *p);
int GetInfoZbAcct(char sRecord[],struct SpAcctZbIntfStruct *p);
int InfoSnAcct2File(struct SpAcctSnIntfStruct *pSource,char sTargetName[]);
int InfoZbAcct2File(struct SpAcctZbIntfStruct *pSource,char sTargetName[]);

void GetOutName(char sFileType[],char sFileName[],char sOutFileName[])
{

	if(strcmp(sFileType,"GJGG")==0||
		strcmp(sFileType,"IFSN")==0||
		strcmp(sFileType,"IFZB")==0){
		strcpy(sOutFileName,"TOL");
		sprintf(sOutFileName,"%s%s",sOutFileName,sFileName+3);
	}

}
int GetZnwGjAcct(char sRecord[],struct ZnwGjAcctStruct *p)
{
	char sDistanceType[2];
	struct ZnwGjIntfStruct Temp;

	bzero((void*)p,sizeof(struct ZnwGjAcctStruct));

	mvitem_fmznwgjintf((struct FZnwGjIntfStruct *)sRecord,&Temp);

	if(strncmp(Temp.sCalledNbr,"4006",4)==0||
		strncmp(Temp.sCalledNbr,"8008",4)==0){
		
		if(strcmp(Temp.sBillingFlag,"2")!=0)return -1;
		
		strncpy(p->sCallingNbr,Temp.sCalledNbr,20);
		p->sCallingNbr[20]=0;
		
		strcpy(p->sServiceKey,Temp.sServiceKey);
		strncpy(p->sCalledNbr,Temp.sCalledNbr,4);p->sCalledNbr[4]=0;
	}
	else if(strncmp(Temp.sCalledNbr,"116800",6)==0){
		strncpy(p->sCallingNbr,Temp.sBillingNbr,20);
		p->sCallingNbr[20]=0;
		
		strcpy(p->sServiceKey,Temp.sServiceKey);
		strncpy(p->sCalledNbr,Temp.sCalledNbr,10);p->sCalledNbr[10]=0;
	
	}
	  

	strcpy(p->sBaseFee,Temp.sBaseFee);
	strcpy(p->sAddFee,Temp.sAddFee);

	if(strcmp(Temp.sHomeAreaCode,Temp.sCalledCode)==0)
		strcpy(sDistanceType,"1");
	else if(GetAreaType(Temp.sHomeAreaCode+1,sDistanceType)==NOTFOUND)
                strcpy(sDistanceType,"1");

	if(strcmp(sDistanceType,"2")==0){/* 省内长途 */
		strcpy(p->sNcnt,"1");
		strcpy(p->sNduration,Temp.sDuration);
		strcpy(p->sNfee,Temp.sTotalFee);
	}
	else if(strcmp(sDistanceType,"3")==0){/* 省际长途 */
		strcpy(p->sScnt,"1");
		strcpy(p->sSduration,Temp.sDuration);
		strcpy(p->sSfee,Temp.sTotalFee);
	}
	else if(strcmp(sDistanceType,"4")==0||
		strcmp(sDistanceType,"5")==0){/* 国际长途 */
		strcpy(p->sGcnt,"1");
		strcpy(p->sGduration,Temp.sDuration);
		strcpy(p->sGfee,Temp.sTotalFee);
	}
	else{/* 本地 */
		strcpy(p->sLcnt,"1");
		strcpy(p->sLduration,Temp.sDuration);
		strcpy(p->sLfee,Temp.sTotalFee);
	}

	strcpy(p->sCnt,"1");
	strcpy(p->sDuration,Temp.sDuration);
	strcpy(p->sFee,Temp.sTotalFee);


	return 0;

}
int link_znw_acct(void **ppData)
{
	InsertList((LIST**)&ptZnwAcct,(LIST*)(*ppData));
	IFILECNT++;
	return 0;
}
int link_infosn_acct(void **ppData)
{
	InsertList((LIST**)&ptInfoSnAcct,(LIST*)(*ppData));
	IFILECNT++;
	return 0;
}
int link_infozb_acct(void **ppData)
{
	InsertList((LIST**)&ptInfoZbAcct,(LIST*)(*ppData));
	IFILECNT++;
	return 0;
}
int ZnwAcct2File(struct ZnwGjAcctStruct *pSource,char sTargetName[])
{
	int iFileRecordLen,iCnt=0;
	char FileHead[45];
	struct FileControlStruct *pRec=NULL;
	struct ZnwGjAcctStruct	*ptHead=NULL,*pTemp;
	struct FZnwGjAcctStruct FTemp;
	
	ptHead=pSource;
	
	if(ptHead==NULL)return 0;
	
	iFileRecordLen=sizeof(struct FZnwGjAcctStruct);

	sprintf(FileHead,"%011d",IFILECNT);
	strcat(FileHead,FILEHEADSTR+11);
	FileHead[44]=0;

	if(item2list(&pRec,(void*)&FileHead,44)<0){
		WriteAlertMsg("添加文件头失败");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		mvitem_mfznwgjacct(pTemp,&FTemp);
		
		if(item2listtail(&pRec,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2fileln(&pRec,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}

	listfree(&pRec);
	
	return iCnt;
}


int ZnwGjFileAcct(char sFileName[],char sNormalDir[],char sOutFileName[])
{
	static int iFirstFlag=1;
	int iCnt=0;
	char sTemp[128],sTargetName[128],sRecord[1024];

	BINTREE *pRoot=NULL;

	struct ZnwGjAcctStruct	Temp;
	struct FileControlStruct *ptHead=NULL,*pTemp,*pList=NULL;

	sprintf(sTargetName,"%s%s",sNormalDir,sOutFileName);

/*将文件数据调用函数加载到内存*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件%s到内存失败.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}

	pList=ptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*保存文件头*/
		if(iFirstFlag==1){
			iFirstFlag=0;
			strcpy(FILEHEADSTR,"00000000000");
			strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
			sTemp[pTemp->iLen]=0;
			sprintf(FILEHEADSTR+11,"%-33s",sTemp);
			continue;
		}

		strncpy(sRecord,pTemp->pData,pTemp->iLen);
		sRecord[pTemp->iLen]=0;

		if(GetZnwGjAcct(sRecord,&Temp)!=0)continue;
		
		if(strcmp(Temp.sCallingNbr,"")==0)continue;
		
		if(InsertBin(&pRoot,(void *)&Temp,
			data_search_bintree_znwgj_acct_e,
			assign_insert_bintree_znwgj_acct_e)<0){
			WriteAlertMsg("生成BINTREE失败znwgj_acct");
			return -1;
		}
	}
/*挂到ptZnwAcct中*/
	TravelBin(pRoot,link_znw_acct);
	

/*输出到文件*/
	if((iCnt=ZnwAcct2File(ptZnwAcct,sTargetName))<0){
		RollbackWorkRelease();
		return -1;
	}
	
	WriteProcMsg(" %d 条记录输出到文件 %s 成功.",iCnt,sOutFileName);

	DestroyBin(pRoot);
      	listfree(&pList);

	return	0;
}
int data_search_bintree_znwgj_acct_e(void *pValue,void*pData)
{
	struct ZnwGjAcctStruct *pSource=(struct ZnwGjAcctStruct *)pValue;
	struct ZnwGjAcctStruct *pTarget=(struct ZnwGjAcctStruct *)pData;
	int res;

	if((res=strcmp(pSource->sCallingNbr,pTarget->sCallingNbr))!=0) return res;
	if((res=strcmp(pSource->sServiceKey,pTarget->sServiceKey))!=0) return res;
	if((res=strcmp(pSource->sCalledNbr,pTarget->sCalledNbr))!=0) return res;

	return 0;
}
void assign_insert_bintree_znwgj_acct_e(void **ppData,void *pData)
{
	int iBaseFee,iAddFee,iLcnt,iLduration,iLfee,iNcnt,iNduration;
	int iNfee,iScnt,iSduration,iSfee,iGcnt,iGduration,iGfee,iCnt;
	int iDuration,iFee;

	struct ZnwGjAcctStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct ZnwGjAcctStruct));
		ERROR_EXIT(pTemp==NULL,"分配MsisdnStat结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct ZnwGjAcctStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}

	iBaseFee   =atoi(((struct ZnwGjAcctStruct*)pData)->sBaseFee  );
	iAddFee    =atoi(((struct ZnwGjAcctStruct*)pData)->sAddFee   );
	iLcnt      =atoi(((struct ZnwGjAcctStruct*)pData)->sLcnt     );
	iLduration =atoi(((struct ZnwGjAcctStruct*)pData)->sLduration);
	iLfee      =atoi(((struct ZnwGjAcctStruct*)pData)->sLfee     );
	iNcnt      =atoi(((struct ZnwGjAcctStruct*)pData)->sNcnt     );
	iNduration =atoi(((struct ZnwGjAcctStruct*)pData)->sNduration);
	iNfee      =atoi(((struct ZnwGjAcctStruct*)pData)->sNfee     );
	iScnt      =atoi(((struct ZnwGjAcctStruct*)pData)->sScnt     );
	iSduration =atoi(((struct ZnwGjAcctStruct*)pData)->sSduration);
	iSfee      =atoi(((struct ZnwGjAcctStruct*)pData)->sSfee     );
	iGcnt      =atoi(((struct ZnwGjAcctStruct*)pData)->sGcnt     );
	iGduration =atoi(((struct ZnwGjAcctStruct*)pData)->sGduration);
	iGfee      =atoi(((struct ZnwGjAcctStruct*)pData)->sGfee     );
	iCnt       =atoi(((struct ZnwGjAcctStruct*)pData)->sCnt      );
	iDuration  =atoi(((struct ZnwGjAcctStruct*)pData)->sDuration );
	iFee       =atoi(((struct ZnwGjAcctStruct*)pData)->sFee      );
	
	iBaseFee   +=atoi(pTemp->sBaseFee  );
	iAddFee    +=atoi(pTemp->sAddFee   );
	iLcnt      +=atoi(pTemp->sLcnt     );
	iLduration +=atoi(pTemp->sLduration);
	iLfee      +=atoi(pTemp->sLfee     );
	iNcnt      +=atoi(pTemp->sNcnt     );
	iNduration +=atoi(pTemp->sNduration);
	iNfee      +=atoi(pTemp->sNfee     );
	iScnt      +=atoi(pTemp->sScnt     );
	iSduration +=atoi(pTemp->sSduration);
	iSfee      +=atoi(pTemp->sSfee     );
	iGcnt      +=atoi(pTemp->sGcnt     );
	iGduration +=atoi(pTemp->sGduration);
	iGfee      +=atoi(pTemp->sGfee     );
	iCnt       +=atoi(pTemp->sCnt      );
	iDuration  +=atoi(pTemp->sDuration );
	iFee       +=atoi(pTemp->sFee      );

	sprintf(pTemp->sBaseFee  ,	"%010d",iBaseFee  );
	sprintf(pTemp->sAddFee   ,	"%010d",iAddFee   );
	sprintf(pTemp->sLcnt     ,	"%011d",iLcnt     );
	sprintf(pTemp->sLduration,	"%011d",iLduration);
	sprintf(pTemp->sLfee     ,	"%011d",iLfee     );
	sprintf(pTemp->sNcnt     ,	"%011d",iNcnt     );
	sprintf(pTemp->sNduration,	"%011d",iNduration);
	sprintf(pTemp->sNfee     ,	"%011d",iNfee     );
	sprintf(pTemp->sScnt     ,	"%011d",iScnt     );
	sprintf(pTemp->sSduration,	"%011d",iSduration);
	sprintf(pTemp->sSfee     ,	"%011d",iSfee     );
	sprintf(pTemp->sGcnt     ,	"%011d",iGcnt     );
	sprintf(pTemp->sGduration,	"%011d",iGduration);
	sprintf(pTemp->sGfee     ,	"%011d",iGfee     );
	sprintf(pTemp->sCnt      ,	"%011d",iCnt      );
	sprintf(pTemp->sDuration ,	"%011d",iDuration );
	sprintf(pTemp->sFee      ,	"%011d",iFee      );
}


int InfoSnFileAcct(char sFileName[],char sNormalDir[],char sOutFileName[])
{
	static int iFirstFlag=1;
	int iCnt=0;
	char sTemp[128],sTargetName[128],sRecord[1024];

	BINTREE *pRoot=NULL;

	struct SpAcctSnIntfStruct	Temp;
	struct FileControlStruct *ptHead=NULL,*pTemp,*pList=NULL;

	sprintf(sTargetName,"%s%s",sNormalDir,sOutFileName);

/*将文件数据调用函数加载到内存*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件%s到内存失败.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}

	pList=ptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*保存文件头*/
		if(iFirstFlag==1){
			iFirstFlag=0;
			strcpy(FILEHEADSTR,"00000000000");
			strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
			sTemp[pTemp->iLen]=0;
			sprintf(FILEHEADSTR+11,"%-33s",sTemp);
			continue;
		}

		strncpy(sRecord,pTemp->pData,pTemp->iLen);
		sRecord[pTemp->iLen]=0;

		if(GetInfoSnAcct(sRecord,&Temp)!=0)continue;
		
		if(strcmp(Temp.sCallingNbr,"")==0)continue;
		
		if(InsertBin(&pRoot,(void *)&Temp,
			data_search_bintree_infosn_acct_e,
			assign_insert_bintree_infosn_acct_e)<0){
			WriteAlertMsg("生成BINTREE失败znwgj_acct");
			return -1;
		}
	}
/*挂到ptInfoSnAcct中*/
	TravelBin(pRoot,link_infosn_acct);
	

/*输出到文件*/
	if((iCnt=InfoSnAcct2File(ptInfoSnAcct,sTargetName))<0){
		RollbackWorkRelease();
		return -1;
	}
	
	WriteProcMsg(" %d 条记录输出到文件 %s 成功.",iCnt,sOutFileName);

	DestroyBin(pRoot);
      	listfree(&pList);

	return	0;
}

int GetInfoSnAcct(char sRecord[],struct SpAcctSnIntfStruct *p)
{
	int iCnt=0;
	struct SpCdrSnIntfStruct Temp;

	bzero((void*)p,sizeof(struct SpAcctSnIntfStruct));

	mvitem_fmspcdrsnintf((struct FSpCdrSnIntfStruct *)sRecord,&Temp);

	strcpy(p->sProvinceName,"HEB");
	strncpy(p->sAreaCode,Temp.sCallingNbr,4);p->sAreaCode[4]=0;
	strcpy(p->sSpNbr,Temp.sSpNbr);
	
	strcpy(p->sCallingNbr,	Temp.sCallingNbr);
	strcpy(p->sCalledNbr,	Temp.sCalledNbr);
	iCnt=1;
	sprintf(p->sCnt,"%011d",iCnt);
	
	strcpy(p->sDuration,	Temp.sDuration);
	strcpy(p->sFee,		Temp.sFee); 
	strcpy(p->sRate,	Temp.sRate); 
	strcpy(p->sNotes,	Temp.sNotes); 

	return 0;

}
int data_search_bintree_infosn_acct_e(void *pValue,void*pData)
{
	struct SpAcctSnIntfStruct *pSource=(struct SpAcctSnIntfStruct *)pValue;
	struct SpAcctSnIntfStruct *pTarget=(struct SpAcctSnIntfStruct *)pData;
	int res;

	if((res=strcmp(pSource->sProvinceName,pTarget->sProvinceName))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;
	if((res=strcmp(pSource->sSpNbr,pTarget->sSpNbr))!=0) return res;
	if((res=strcmp(pSource->sCallingNbr,pTarget->sCallingNbr))!=0) return res;
	if((res=strcmp(pSource->sCalledNbr,pTarget->sCalledNbr))!=0) return res;
	if((res=strcmp(pSource->sRate,pTarget->sRate))!=0) return res;
	if((res=strcmp(pSource->sNotes,pTarget->sNotes))!=0) return res;

	return 0;
}
void assign_insert_bintree_infosn_acct_e(void **ppData,void *pData)
{
	int iCnt,iDuration,iFee;

	struct SpAcctSnIntfStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SpAcctSnIntfStruct));
		ERROR_EXIT(pTemp==NULL,"分配MsisdnStat结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SpAcctSnIntfStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}

	iCnt   		=atoi(((struct SpAcctSnIntfStruct*)pData)->sCnt   	);
	iDuration    	=atoi(((struct SpAcctSnIntfStruct*)pData)->sDuration    );
	iFee      	=atoi(((struct SpAcctSnIntfStruct*)pData)->sFee      	);
	
	iCnt  		+=atoi(pTemp->sCnt  	);
	iDuration       +=atoi(pTemp->sDuration );
	iFee      	+=atoi(pTemp->sFee      );

	sprintf(pTemp->sCnt  	,	"%011d",iCnt  	);
	sprintf(pTemp->sDuration,	"%011d",iDuration );
	sprintf(pTemp->sFee     ,	"%011d",iFee      );
}

int InfoSnAcct2File(struct SpAcctSnIntfStruct *pSource,char sTargetName[])
{
	int iFileRecordLen,iCnt=0;
	char FileHead[45];
	struct FileControlStruct *pRec=NULL;
	struct SpAcctSnIntfStruct	*ptHead=NULL,*pTemp;
	struct FSpAcctSnIntfStruct FTemp;
	
	ptHead=pSource;
	
	if(ptHead==NULL)return 0;
	
	iFileRecordLen=sizeof(struct FSpAcctSnIntfStruct);

	sprintf(FileHead,"%011d",IFILECNT);
	strcat(FileHead,FILEHEADSTR+11);
	FileHead[44]=0;

	if(item2list(&pRec,(void*)&FileHead,44)<0){
		WriteAlertMsg("添加文件头失败");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		mvitem_mfspacctsnintf(pTemp,&FTemp);
		
		if(item2listtail(&pRec,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2fileln(&pRec,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}

	listfree(&pRec);
	
	return iCnt;
}

int InfoZbFileAcct(char sFileName[],char sNormalDir[],char sOutFileName[])
{
	static int iFirstFlag=1;
	int iCnt=0;
	char sTemp[128],sTargetName[128],sRecord[1024];

	BINTREE *pRoot=NULL;

	struct SpAcctZbIntfStruct	Temp;
	struct FileControlStruct *ptHead=NULL,*pTemp,*pList=NULL;

	sprintf(sTargetName,"%s%s",sNormalDir,sOutFileName);

/*将文件数据调用函数加载到内存*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件%s到内存失败.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}

	pList=ptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*保存文件头*/
		if(iFirstFlag==1){
			iFirstFlag=0;
			strcpy(FILEHEADSTR,"00000000000");
			strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
			sTemp[pTemp->iLen]=0;
			sprintf(FILEHEADSTR+11,"%-33s",sTemp);
			continue;
		}

		strncpy(sRecord,pTemp->pData,pTemp->iLen);
		sRecord[pTemp->iLen]=0;

		if(GetInfoZbAcct(sRecord,&Temp)!=0)continue;
		
		if(strcmp(Temp.sCallingNbr,"")==0)continue;
		
		if(InsertBin(&pRoot,(void *)&Temp,
			data_search_bintree_infozb_acct_e,
			assign_insert_bintree_infozb_acct_e)<0){
			WriteAlertMsg("生成BINTREE失败infozb_acct");
			return -1;
		}
	}
/*挂到ptInfoZbAcct中*/
	TravelBin(pRoot,link_infozb_acct);
	

/*输出到文件*/
	if((iCnt=InfoZbAcct2File(ptInfoZbAcct,sTargetName))<0){
		RollbackWorkRelease();
		return -1;
	}
	
	WriteProcMsg(" %d 条记录输出到文件 %s 成功.",iCnt,sOutFileName);

	DestroyBin(pRoot);
      	listfree(&pList);

	return	0;
}

int GetInfoZbAcct(char sRecord[],struct SpAcctZbIntfStruct *p)
{
	int iCnt=0;
	struct SpCdrZbIntfStruct Temp;

	bzero((void*)p,sizeof(struct SpAcctZbIntfStruct));

	mvitem_fmspcdrzbintf((struct FSpCdrZbIntfStruct *)sRecord,&Temp);

	strcpy(p->sCallingNbr,	Temp.sCallingNbr);
	strncpy(p->sCalledNbr,Temp.sCalledNbr,6);p->sCalledNbr[6]=0;
	iCnt=1;
	sprintf(p->sCnt,"%011d",iCnt);
	
	strcpy(p->sDuration,	Temp.sDuration);
	strcpy(p->sFee,		Temp.sFee); 

	return 0;

}
int data_search_bintree_infozb_acct_e(void *pValue,void*pData)
{
	struct SpAcctZbIntfStruct *pSource=(struct SpAcctZbIntfStruct *)pValue;
	struct SpAcctZbIntfStruct *pTarget=(struct SpAcctZbIntfStruct *)pData;
	int res;

	if((res=strcmp(pSource->sCallingNbr,pTarget->sCallingNbr))!=0) return res;
	if((res=strcmp(pSource->sCalledNbr,pTarget->sCalledNbr))!=0) return res;

	return 0;
}
void assign_insert_bintree_infozb_acct_e(void **ppData,void *pData)
{
	int iCnt,iDuration,iFee;

	struct SpAcctZbIntfStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SpAcctZbIntfStruct));
		ERROR_EXIT(pTemp==NULL,"分配MsisdnStat结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SpAcctZbIntfStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}

	iCnt   		=atoi(((struct SpAcctZbIntfStruct*)pData)->sCnt   	);
	iDuration    	=atoi(((struct SpAcctZbIntfStruct*)pData)->sDuration    );
	iFee      	=atoi(((struct SpAcctZbIntfStruct*)pData)->sFee      	);
	
	iCnt  		+=atoi(pTemp->sCnt  	);
	iDuration       +=atoi(pTemp->sDuration );
	iFee      	+=atoi(pTemp->sFee      );

	sprintf(pTemp->sCnt  	,	"%011d",iCnt  	);
	sprintf(pTemp->sDuration,	"%011d",iDuration );
	sprintf(pTemp->sFee     ,	"%011d",iFee      );
}

int InfoZbAcct2File(struct SpAcctZbIntfStruct *pSource,char sTargetName[])
{
	int iFileRecordLen,iCnt=0;
	char FileHead[45];
	struct FileControlStruct *pRec=NULL;
	struct SpAcctZbIntfStruct	*ptHead=NULL,*pTemp;
	struct FSpAcctZbIntfStruct FTemp;
	
	ptHead=pSource;
	
	if(ptHead==NULL)return 0;
	
	iFileRecordLen=sizeof(struct FSpAcctZbIntfStruct);

	sprintf(FileHead,"%011d",IFILECNT);
	strcat(FileHead,FILEHEADSTR+11);
	FileHead[44]=0;

	if(item2list(&pRec,(void*)&FileHead,44)<0){
		WriteAlertMsg("添加文件头失败");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		mvitem_mfspacctzbintf(pTemp,&FTemp);
		
		if(item2listtail(&pRec,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2fileln(&pRec,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}

	listfree(&pRec);
	
	return iCnt;
}


int main(int argc, char **argv)
{
	char	sNormalDir[256],sOutFileName[128];
	char	sBaseName[128],sFileName[128],sFileType[10];

	if(argc!=4){
		printf("Usage %s filename filetype normaldir.\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sFileType,argv[2]);
	strcpy(sNormalDir,argv[3]);
	
	RegularDir(sNormalDir);

	GetBaseName(sFileName,sBaseName);
	GetOutName(sFileType,sBaseName,sOutFileName);

/**汇总文件**/
	if(strcmp(sFileType,"GJGG")==0){
		if(ZnwGjFileAcct(sFileName,sNormalDir,sOutFileName)<0){
			printf("汇总文件%s失败.\n",sFileName);
			return -1;
		}
	}
	else if(strcmp(sFileType,"IFSN")==0){
		if(InfoSnFileAcct(sFileName,sNormalDir,sOutFileName)<0){
			printf("汇总文件%s失败.\n",sFileName);
			return -1;
		}
	}
	else if(strcmp(sFileType,"IFZB")==0){
		if(InfoZbFileAcct(sFileName,sNormalDir,sOutFileName)<0){
			printf("汇总文件%s失败.\n",sFileName);
			return -1;
		}
	}		
	else{
		WriteProcMsg("类型不匹配 %s.",sFileType);
		printf("类型不匹配 %s .\n",sFileType);
		return -1;
	}


	printf("帐单文件汇总成功. ");

	return 0;
}
