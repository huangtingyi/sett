#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <bintree.h>

#include "imei_supp.h"

struct Imei2DbCtlStruct
{	
	struct ImeiUpStruct asImeiUp[201];
	struct ImeiUpStruct *ptHead;
	int	iTotalCnt;
};

struct Imei2DbCtlStruct asImei2DbCtl[10];

struct ImeiUpStruct asImeiUp[2000];
int	igCnt=0;

void InitImei2DbCtl()
{
	asImei2DbCtl[0].iTotalCnt=0;asImei2DbCtl[0].ptHead=NULL;
	asImei2DbCtl[1].iTotalCnt=0;asImei2DbCtl[1].ptHead=NULL;
	asImei2DbCtl[2].iTotalCnt=0;asImei2DbCtl[2].ptHead=NULL;
	asImei2DbCtl[3].iTotalCnt=0;asImei2DbCtl[3].ptHead=NULL;
	asImei2DbCtl[4].iTotalCnt=0;asImei2DbCtl[4].ptHead=NULL;
	asImei2DbCtl[5].iTotalCnt=0;asImei2DbCtl[5].ptHead=NULL;
	asImei2DbCtl[6].iTotalCnt=0;asImei2DbCtl[6].ptHead=NULL;
	asImei2DbCtl[7].iTotalCnt=0;asImei2DbCtl[7].ptHead=NULL;
	asImei2DbCtl[8].iTotalCnt=0;asImei2DbCtl[8].ptHead=NULL;
	asImei2DbCtl[9].iTotalCnt=0;asImei2DbCtl[9].ptHead=NULL;
	asImei2DbCtl[10].iTotalCnt=0;asImei2DbCtl[10].ptHead=NULL;
}

void Append2Imei2DbCtl(struct ImeiUpStruct *p)
{
	int i=p->iGroupID;
	struct ImeiUpStruct *pTemp;
	
	memcpy((void*)&(asImei2DbCtl[i].asImeiUp[asImei2DbCtl[i].iTotalCnt]),(void*)p,sizeof(struct ImeiUpStruct));
	
	pTemp=&(asImei2DbCtl[i].asImeiUp[asImei2DbCtl[i].iTotalCnt]);
	pTemp->pNext=NULL;pTemp->pLoadNext=NULL;
	InsertList((LIST**)&(asImei2DbCtl[i].ptHead),(LIST*)pTemp);
	
	asImei2DbCtl[i].iTotalCnt++;
}

int data_search_bintree_imei_up_e(void *pValue,void*pData)
{
	int res=0;
	
	struct ImeiUpStructX *pSource=(struct ImeiUpStructX *)pValue;
	struct ImeiUpStructX *pTarget=(struct ImeiUpStructX *)pData;
	
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	
	return 0;
}

int SearchImeiUpItem(struct ImeiUpStructX *p,BINTREE *ptRoot)
{
	struct ImeiUpStructX *ptHead,*pTemp;
	
	
	if(SearchBin(ptRoot,(void*)p,data_search_bintree_imei_up_e,
		(void**)&ptHead)==NOTFOUND) return NOTFOUND;
	
	while(ptHead!=NULL){
		if(strcmp(ptHead->sImei,p->sImei)==0&&
			strcmp(ptHead->sImsi,p->sImsi)==0)
			return FOUND;
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}

void GenConditonStr(struct ImeiUpStruct *ptHead,int iGroupID,char sCondition[])
{
	char sTemp[4096];
	int i=0;
	strcpy(sCondition,"");
	i+=sprintf(sTemp," WHERE GROUP_ID=%d AND MSISDN IN ( ",iGroupID);
	while(ptHead!=NULL){
		
		i+=sprintf(sTemp+i,"'%s',",ptHead->sMsisdn);
		ptHead=ptHead->pNext;
	}
	sTemp[i-1]=0;
	strcat(sTemp,")");
	strcpy(sCondition,sTemp);
}

void SetImeiUpNewFlag(struct ImeiUpStructX *p,struct ImeiUpStruct *ptHead)
{
	while(ptHead!=NULL){
		if(strcmp(ptHead->sMsisdn,p->sMsisdn)==0&&
			strcmp(ptHead->sImei,p->sImei)==0&&
			strcmp(ptHead->sImsi,p->sImsi)==0){
			strcpy(ptHead->sFlag,"1");
			return ;
		}
		ptHead=ptHead->pNext;
	}
}

int GenImeiUpBintree(struct ImeiUpStruct *ptHead,int iGroupID,BINTREE **pptRoot)
{
	char  sCondition[4096];
	struct ImeiUpStructX Temp,*pTemp;
	struct ImeiUpStructXIn TempIn;
	BINTREE *ptRoot=NULL;
	
	bzero((void*)&Temp,sizeof(struct ImeiUpStructX));
	bzero((void*)&TempIn,sizeof(struct ImeiUpStructXIn));
	
	GenConditonStr(ptHead,iGroupID,sCondition);
	strcpy(TempIn.sTableName,"IMEI_UP");
	strcpy(TempIn.sCondition,sCondition);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	while(EGetImeiUpToStructX(&Temp,&TempIn)){
		
/*		SetImeiUpNewFlag(&Temp,ptHead);*/
		
		if(SearchImeiUpItem(&Temp,*pptRoot)==FOUND) continue;
		
		if((pTemp=(struct ImeiUpStructX*)malloc(
			sizeof(struct ImeiUpStructX)))==NULL) return -1;

		strcpy(pTemp->sMsisdn,Temp.sMsisdn);
		strcpy(pTemp->sImei,Temp.sImei);
		strcpy(pTemp->sImsi,Temp.sImsi);
		
		pTemp->pNext=NULL;
		pTemp->pLoadNext=NULL;
		
		SetImeiUpNewFlag(pTemp,ptHead);
		
		if(InsertBin(pptRoot,(void*)pTemp,data_search_bintree_imei_up_e,
			assign_insert_bintree)<0) return -1;
/*		if(InsertBin(&ptRoot,(void*)pTemp,data_search_bintree_imei_up_e,
			assign_insert_bintree)<0) return -1;*/
	}
/*	while(ptHead!=NULL){
		
		if(SearchImeiUpItem(ptHead,ptRoot)==FOUND) strcpy(ptHead->sFlag,"1");
		
		ptHead=ptHead->pNext;
	}
	DestroyBin(ptRoot);*/

	return 0;
}

int InsertImeiUpItem2Table(struct ImeiUpStruct *ptHead,int iInsertFlag)
{
	static struct ImeiUpStructOut TempOut;
	static struct ImeiUpStruct *pTemp;
	static int iFirstFlag=true,iTotalCnt=0;
	
/*	if(iInsertFlag==true&&iFirstFlag==true) return 0;*/
	
	if(iFirstFlag==true){
		bzero((void*)&TempOut,sizeof(struct ImeiUpStructOut));
       		strcpy(TempOut.sTableName,"IMEI_UP");
       		iFirstFlag=false;
       	}
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->sFlag,"1")==0) continue;
		
		GetRsSeq(pTemp->sRsSeq);
		GetHostTime(pTemp->sCreatetime);
		
		if((++iTotalCnt)%10000==0){
			if(EInsertStructToImeiUp(NULL,true,&TempOut)<0){
				WriteAlertMsg("写表%s失败",TempOut.sTableName);
				RollbackWorkRelease();
				return -1;
			}
			CommitWork();
			WriteProcPrint("对表 %s 写入 %d 条.",TempOut.sTableName,iTotalCnt);
		}
		if(EInsertStructToImeiUp(pTemp,false,&TempOut)<0){
			WriteAlertMsg("写表%s失败",TempOut.sTableName);
			RollbackWorkRelease();
			return -1;
		}
	}
	
	if(iInsertFlag==true){
		if(EInsertStructToImeiUp(NULL,true,&TempOut)<0){
			WriteAlertMsg("写表%s失败",TempOut.sTableName);
			RollbackWorkRelease();
			return -1;
		}
		CommitWork();
/*		WriteProcPrint("对表 %s 写入 %d 条.",TempOut.sTableName,iTotalCnt);*/
	
	}
	
	return 0;
}

void mvitem_str2imeiben(char sLine[],struct ImeiUpStruct *p)
{
	char sTemp[256];

	bzero((void*)p,sizeof(struct ImeiUpStruct));
	
	memcpy(sTemp,sLine,16);sTemp[16]=0;AllTrim(sTemp);
	strcpy(p->sMsisdn,sTemp);
	memcpy(sTemp,sLine+16,16);sTemp[16]=0;AllTrim(sTemp);
	strcpy(p->sImei,sTemp);
	memcpy(sTemp,sLine+32,16);sTemp[16]=0;AllTrim(sTemp);
	strcpy(p->sImsi,sTemp);
	memcpy(sTemp,sLine+48,15);sTemp[15]=0;AllTrim(sTemp);
	strcpy(p->sCallstarttime,sTemp);
	memcpy(sTemp,sLine+63,2);sTemp[2]=0;AllTrim(sTemp);
	strcpy(p->sAreaID,sTemp);
	memcpy(sTemp,sLine+65,2);sTemp[2]=0;AllTrim(sTemp);
	strcpy(p->sMatchitem,sTemp);
	memcpy(sTemp,sLine+67,2);sTemp[2]=0;AllTrim(sTemp);
	strcpy(p->sType,sTemp);
	strncpy(sTemp,p->sMsisdn+strlen(p->sMsisdn)-1,1);sTemp[1]=0;AllTrim(sTemp);
	p->iGroupID=atoi(sTemp);

}
int AppendImeiUp2Db(int iInsertFlag,BINTREE **pptRoot)
{
	int i=0;
	for(i=0;i<10;i++){
		if(iInsertFlag==false){
			if(asImei2DbCtl[i].iTotalCnt<200) continue;
			if(GenImeiUpBintree(asImei2DbCtl[i].ptHead,i,pptRoot)<0) return -1;
			if(InsertImeiUpItem2Table(asImei2DbCtl[i].ptHead,iInsertFlag)<0) return -1;
		}
		else{
			if(asImei2DbCtl[i].ptHead==NULL) continue;
			if(GenImeiUpBintree(asImei2DbCtl[i].ptHead,i,pptRoot)<0) return -1;
			if(InsertImeiUpItem2Table(asImei2DbCtl[i].ptHead,iInsertFlag)<0) return -1;
		}
		asImei2DbCtl[i].ptHead=NULL;
		asImei2DbCtl[i].iTotalCnt=0;
	}
	return 0;	
}
/*批量加载文件数据*/
int FTxtFile2Bintree(char sPathFileName[],BINTREE **pptRoot)
{
	char	sTemp[1024],sCondition[2000];
	struct ImeiUpStructX TempX;
	struct ImeiUpStruct Temp,*pImeiUp,*pImeiList=NULL;
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	
	if(TxtFileToList(sPathFileName,&ptHead)<0) return -1;
	
	igCnt=0;
	
/*备份链表*/
	ptLkHead=ptHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*忽略太长的行*/
		if(pTemp->iLen>=1024) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);
/*忽略太短的行*/
		if(strlen(sTemp)<20) continue;
/*忽略注释行*/
		if(sTemp[0]=='#') continue;
		mvitem_str2imeiben(sTemp,&Temp);
		
		if(strlen(Temp.sMsisdn)==0||strlen(Temp.sImei)==0||strlen(Temp.sImsi)==0) continue;
		
		strcpy(TempX.sMsisdn,Temp.sMsisdn);
		strcpy(TempX.sImei,Temp.sImei);
		strcpy(TempX.sImsi,Temp.sImsi);
	
		if(SearchImeiUpItem(&TempX,*pptRoot)==FOUND) continue;
		
		strcpy(Temp.sFlag,"0");
	
		Append2Imei2DbCtl(&Temp);
		
		if(AppendImeiUp2Db(false,pptRoot)<0) return -1;

	}
	
	if(AppendImeiUp2Db(true,pptRoot)<0) return -1;
	listfree(&ptLkHead);
}

int main(int argc,char **argv)
{
	char sSourcePath[128],sFileName[128],sPathFileName[128];
	
	struct FileControlStruct *ptHead=NULL,*pTemp=NULL,*ptLkHead=NULL;
	BINTREE *ptRoot=NULL;
	int i=0,iFileCnt=0;
	
	InitAppRes(argv[0]);
	if(ConnectDataDB()<0) return -1;
while(1){	
	strcpy(sSourcePath,"/ticket/work/Imei_prep/");
	/*生成要处理的文件列表*/
	sleep(10);
	if(i==10) break;
		
	ptHead=NULL;
	if(dir2list(sSourcePath,"*.P",&ptHead)<0){
		WriteAlertMsg("获取要处理的文件列表失败，进程退出");
		return -1;
	}
	if(ptHead==NULL) continue;
	ptLkHead=ptHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);
		
		sprintf(sPathFileName,"%s%s",sSourcePath,sFileName);
		if(IsFile(sPathFileName)==0) continue;
		
		if(FTxtFile2Bintree(sPathFileName,&ptRoot)<0) return -1;
		WriteProcMsg("文件 %s 处理完成.",sFileName);
		execcmd("rm -f %s",sPathFileName);
		iFileCnt++;
		if(iFileCnt==200) return 0;
	}
	if(InsertImeiUpItem2Table(NULL,true)<0) return -1;
	listfree(&ptLkHead);
	i++;
}
	return 0;	
}