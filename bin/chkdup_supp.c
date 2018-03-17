#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwsem.h>
#include <wwshm.h>
#include <list.h>
#include <bintree.h>
#include <trie.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <expr_supp.h>
#include <wwdb.h>

#include "dupsupp.h"
#include "tariff_disct.h"
#include "param_intf.h"
#include "stt_ticket.h"


struct BinItemStruct{
	POINTER ioffNext;
	char	sModule[4];
	char 	sDataDate[15];
	time_t 	tMinAcrossBeginTime;
	time_t 	tMaxAcrossEndTime;
	
	int 	iRecordCnt;
	int 	iNodeCnt;
	int 	iReadTimes;
	int 	iWriteTimes;
	int 	iRebuildTimes;
	char	sState[2];	/*'0' ���ݿ�,'1' ���ڴ���,'2' ����*/

	int 	iCommitCnt;	/*��commitcnt,recordcnt��һ�µ�ʱ�����������*/
	time_t	tLastAccessTime;

/*��ʷ�Ķ���*/
	int 	iPreRecordCnt;
	int 	iPreNodeCnt;
	int 	iPreReadTimes;
	int 	iPreWriteTimes;
	int 	iPreRebuildTimes;
	int 	iPreCommitCnt;
	time_t	tPreLastAccessTime;

	time_t	tDataDate;
	
	POINTER ioffUseTimeNxt;/*LRU������*/

	POINTER ioffNxt;	/*Сʱ˳���������*/
	POINTER ioffPre;	/*Сʱ˳������ǰ��*/
	
	int	iUpdated;	/*true,һ��,false��һ��*/
	POINTER ioffUpdateNxt;	/*�䶯�鵵����*/
	POINTER ioffNew;	/*�»�������δ����Ļ�������*/
	
	POINTER ioffTrie;	/*����ƽ���������ͷ�ڵ�*/
	POINTER ioffList;	/*������ʱ�������ڵ�����*/
};
#define STATE_INDB	'0'
#define STATE_INMEM	'1'
#define STATE_MEMNOIND	'2'

struct AdjCtrlStruct
{
	int iMax;
	int iCur;
	int iMin;
};
struct ShmDupHead 
{
	char	sModule[4];	/*��ϵͳ*/
	int	iShmKey;
	int	iSemKey;
	POINTER	iBlockLen;
	POINTER	iTotalLen;
	int	iMaxChkDays;

	int	iDiffSec;		/*ʱ���࣬������durationʱ�����ص�*/
	int	iDiffStart;		/*������,start_time���ص�*/
	int	iChkOpp;		/*���other_party�ֶ�ѡ��,0�����,1���*/

	struct	ShmCtrlStruct	ItemNode;
	struct	ShmCtrlStruct	ItemData; /*Сʱ�ڵ����*/
	struct	ShmCtrlStruct	TrieNode; /*�����ڵ����*/
	struct	ShmCtrlStruct	TrieData; /*�������ݸ���*/

	struct AdjCtrlStruct CHourNode;
	struct AdjCtrlStruct CTrieNode;
	struct AdjCtrlStruct CTrieData;

	char	sTablespaceName[31];/*��ռ���*/
	char	sExprName[256];

	POINTER	ioffHead;		/*ָ��ʱ����С���ֵ�ָ��ڵ�*/
	POINTER	ioffTail;		/*ָ��ʱ����С���ֵ�ָ��ڵ�*/
	POINTER	ioffUseTimeHead;	/*ָ����������¼�ڵ���ָ��*/
	POINTER ioffUpdateHead;		/*��һ������*/
	POINTER	ioffRoot;		/*Сʱ�ڵ�ƽ�������*/
	POINTER ioffTmp;		/*��ʱ��Žض�������TRIEҶ��*/
};
struct TTicketStruct{

	POINTER		ioffNext;/*freelist��bintreelist*/
	POINTER		ioffNew;/*newlist*/
	char		sCallType[3];	
	char 		sMsisdn[13];
	char		sOtherParty[21];	
	time_t		tStartTime;
	int		iDuration;
};
struct HourStatStruct
{
	struct HourStatStruct *pNext;
	int	iCnt;
	time_t	tDataDate;
	char	sDataDate[15];
	struct DupTicketStruct *pHead;
};

struct FMemStruct DUPMEM;
struct ShmDupHead *PSHMDUP;
POINTER igoffTmpList=-1; /*�����ʱ��TRIEж�»�����¼����,DestroyLeaveTrie��*/

void ItemNeedShmRes(struct BinItemStruct *ptCur,int *piNodeCnt,int *piDataCnt);
void InsertUseTimeLeave(POINTER ioffValue);
int DeleteUseTimeLeave(POINTER ioffValue);
void DestroyLeaveTrie(struct BinItemStruct *ptHead);
void DestroyLeaveData(struct BinItemStruct *ptHead);
POINTER WhatLeave(time_t tDataDate,char cIgnoreState);
void InsertBinUpdatedList(POINTER ioffCur);
/*
dupflagȡֵ : 
dupflag=0	��Ҫ���أ����غ����ص�
dupflag=1	0->1,���غ��ȷ���ص�
dupflag=2	����Ҫ���أ�д���������ļ��Ҳ����
*/
#define OPDUP(x) OPFLIST(&DUPMEM,x)

#define CHOURNODE PSHMDUP->CHourNode 
#define CTRIENODE PSHMDUP->CTrieNode 
#define CTRIEDATA PSHMDUP->CTrieData 

#define MallocItemData() MallocFItem((void*)&DUPMEM,&PSHMDUP->ItemData)
#define MallocTrieData() MallocFItem((void*)&DUPMEM,&PSHMDUP->TrieData)
#define MallocItemNode() MallocFItem((void*)&DUPMEM,&PSHMDUP->ItemNode)
#define MallocTrieNode() MallocFItem((void*)&DUPMEM,&PSHMDUP->TrieNode)
#define FreeItemData(o)	FreeFItem((void*)&DUPMEM,&PSHMDUP->ItemData,o)
#define FreeTrieData(o)	FreeFItem((void*)&DUPMEM,&PSHMDUP->TrieData,o)
#define FreeItemNode(o)	FreeFItem((void*)&DUPMEM,&PSHMDUP->ItemNode,o)
#define FreeTrieNode(o)	FreeFItem((void*)&DUPMEM,&PSHMDUP->TrieNode,o)

int CheckUseTimeList()
{
	int iCnt=0,iFlag=false;
	struct BinItemStruct *pTemp;
	POINTER ioffHead,ioffTemp=-1;
	
	ioffHead=PSHMDUP->ioffUseTimeHead;
	
	while(ioffHead!=-1){
		
		ioffTemp=ioffHead;
		pTemp=(struct BinItemStruct *)OPDUP(ioffTemp);
		ioffHead=pTemp->ioffUseTimeNxt;

		if(ioffTemp==238644) iFlag=true;
		iCnt++;
		if(iCnt>10000) return -1;
	}
	if(iFlag==true) printf("in usetime %d.\n",iCnt);
	else		printf("not in usetime %d.\n",iCnt);
	return 0;
}
int InitShmDupHead(char sModule[4],struct ShmDupHead *p)
{
	int l,i;
	FILE *fp;
	char sTemp[128],sPath[128],sItem[20],sBillHome[256],sInput[16*1024];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];

	bzero((void*)p,sizeof(struct ShmDupHead));

	strncpy(p->sModule,sModule,3);

	p->ioffHead		=-1;
	p->ioffTail		=-1;
	p->ioffUseTimeHead	=-1;
	p->ioffUpdateHead	=-1;
	p->ioffRoot		=-1;
	p->ioffTmp		=-1;

	GetIniName(sPath);

	strcpy(sItem,"shmkey");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->iShmKey=Str2Int(sTemp);

	strcpy(sItem,"semkey");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->iSemKey=Str2Int(sTemp);

/****������ѡ��Ŀ��ʼ*/
	strcpy(sItem,"diff_sec");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	p->iDiffSec=Str2Int(sTemp);
	if(p->iDiffSec>3)p->iDiffSec=3;

	strcpy(sItem,"diff_start");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	p->iDiffSec=Str2Int(sTemp);
	if(p->iDiffStart>60)p->iDiffStart=60;

	strcpy(sItem,"chk_opp");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	p->iChkOpp=Str2Int(sTemp);
/**��ѡ����������**/

	strcpy(sItem,"hournode_max");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->CHourNode.iMax=Str2Int(sTemp);

	strcpy(sItem,"hournode_min");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->CHourNode.iMin=Str2Int(sTemp);


	strcpy(sItem,"trienode_max");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->CTrieNode.iMax=Str2Int(sTemp);

	strcpy(sItem,"trienode_min");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->CTrieNode.iMin=Str2Int(sTemp);


	strcpy(sItem,"triedata_max");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->CTrieData.iMax=Str2Int(sTemp);

	strcpy(sItem,"triedata_min");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->CTrieData.iMin=Str2Int(sTemp);

	strcpy(sItem,"tablespace_name");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	if(i<0||strlen(sTemp)==0) strcpy(p->sTablespaceName,"CHKDATA");
	else	strcpy(p->sTablespaceName,sTemp);
	
	strcpy(sItem,"expr_name");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	GetBillHome(sBillHome);
	sprintf(p->sExprName,"%sexpr/%s",sBillHome,sTemp);

	ERROR_RETURNA(!IsFile(p->sExprName),"�ļ�%s������",p->sExprName);
	l=FileSize(p->sExprName);
	ERROR_RETURNA((l>=1024*16)||(l<=0),"�ļ�%s��С����0-16K��Χ��",
		p->sExprName);
	ERROR_RETURNA((fp=fopen(p->sExprName,"r"))==NULL,"���ļ�%sʧ��",
		p->sExprName);
	ERROR_RETURNA(fread(sInput,l,1,fp)!=1,"��ȡ�ļ�%sʧ��",
		p->sExprName);
	sInput[l]=0;fclose(fp);
	RegPrepVar();
	CheckSysVar=CheckPrepVar;

	ERROR_RETURNB((i=CompileExpr(sInput,asVarOutput,&l))<0,
		"���빫ʽ%s����::\n%s",p->sExprName,pExprBuf->sErrorMsg);

	strcpy(sItem,"max_blk_len");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"��ȡbill.ini�ļ�ʧ��");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s�޶�Ӧ����",
                sModule,sItem);
	p->iBlockLen=Str2Int(sTemp);

/*	p->iBlockLen=(POINTER)2047*1024*1024;*/
	p->iMaxChkDays=10*366;
	p->iTotalLen=((POINTER)sizeof(struct FShmStruct)+
			(POINTER)sizeof(struct ShmDupHead)+
			(POINTER)p->CTrieData.iMax*sizeof(struct TTicketStruct)+
			(POINTER)p->CTrieNode.iMax*sizeof(ETRIE)+
			(POINTER)p->iMaxChkDays*24*(sizeof(EBINTREE)+
			sizeof(struct BinItemStruct)))/1024/1024+2;

	p->iTotalLen=p->iTotalLen*1024*1024;

	return 0;
}
void GetDupSourceID(char sSourceID[],char sBaseName[],char sDupSourceID[])
{
	int off=0;
	char *pc,sTmpTime[15],sTarget[128];

	strcpy(sTarget,sSourceID);

	strncpy(sTmpTime,sBaseName,8);
	strcpy(sTmpTime+8,"000000");

	if(tGetTime(sTmpTime)!=-1) off=8;

	if((pc=strstr(sBaseName,".tmp"))!=NULL){
		strncat(sTarget,sBaseName+off,pc-sBaseName-off);
		sTarget[strlen(sSourceID)+pc-sBaseName-off]=0;
	}
	else	strcat(sTarget,sBaseName+off);

	strncpy(sDupSourceID,sTarget,30);sDupSourceID[30]=0;

}
int mvitem_record2ticket(struct FileControlStruct *pi,char sSourceID[],
	char sBaseName[31],struct DupTicketStruct *po)
{
	int iDupFlag=0;
	char sTemp[256];
	
	set_point_value("chk_ori",pExprBuf,(void*)(pi->pData));
	
	if(ExecCode(pExprBuf)<0){
		printf("ִ�й�ʽ%sʧ��,�����˳�.\n",PSHMDUP->sExprName);
		return -1;
	}
	
	get_int_value("dupflag",pExprBuf,&iDupFlag);
	if(iDupFlag==-1) iDupFlag=0;

	po->pNext=NULL;
	po->pLoadNext=NULL;

	get_str_value("call_type",	pExprBuf,sTemp);
	strncpy(po->sCallType,sTemp,2);
	po->sCallType[2]=0;AllTrim(po->sCallType);

	get_str_value("msisdn",		pExprBuf,sTemp);
	strncpy(po->sMsisdn,sTemp,12);
	po->sMsisdn[12]=0;AllTrim(po->sMsisdn);

	get_str_value("other_party",	pExprBuf,sTemp);
	strncpy(po->sOtherParty,sTemp,20);
	po->sOtherParty[20]=0;AllTrim(po->sOtherParty);

	get_str_value("start_time",	pExprBuf,sTemp);
	strncpy(po->sStartTime,sTemp,14);
	po->sStartTime[14]=0;AllTrim(po->sStartTime);

	get_str_value("duration",	pExprBuf,sTemp);
	strncpy(po->sDuration,sTemp,6);
	po->sDuration[6]=0;AllTrim(po->sDuration);

	strncpy(po->sHour,po->sStartTime+8,2);	po->sHour[2]=0;
	strncpy(po->sMiss,po->sStartTime+10,4); po->sMiss[4]=0;

	GetDupSourceID(sSourceID,sBaseName,po->sSourceID);
	
/*	strncpy(po->sSourceID,sSourceID,19);	po->sSourceID[19]=0;*/
	
	po->tStartTime=	tGetTime(po->sStartTime);
	po->iDuration=	atoi(po->sDuration);
	po->iDupFlag=	iDupFlag;
	po->pOri=	(void*)pi;
	
	return 0;
}
void mvitem_dupticket2ticket(struct DupTicketStruct *pi,
	struct TTicketStruct *po)
{
	po->ioffNext=-1;
	po->ioffNew=-1;

	strcpy(po->sCallType,	pi->sCallType);
	strcpy(po->sMsisdn,	pi->sMsisdn);
	strcpy(po->sOtherParty,	pi->sOtherParty);

	po->tStartTime=		tGetTime(pi->sStartTime);
	po->iDuration=		atoi(pi->sDuration);

}
int SearchHourStat(struct HourStatStruct *ptHead,char sStartTime[15],
	struct HourStatStruct **pptCur)
{
	while(ptHead!=NULL){
		if(strncmp(sStartTime,ptHead->sDataDate,10)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
struct HourStatStruct *CreateHourStat(struct DupTicketStruct *ptHead)
{
	struct DupTicketStruct *ptPre,*ptCur=ptHead;
	struct HourStatStruct *pStat=NULL,*pTemp;

	while(ptCur!=NULL){

		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(SearchHourStat(pStat,ptPre->sStartTime,&pTemp)==NOTFOUND){

			if((pTemp=(struct HourStatStruct*)malloc(
				sizeof(struct HourStatStruct)))==NULL){
				DestroyList((LIST*)pStat);
				return NULL;
			}
			bzero((void*)pTemp,sizeof(struct HourStatStruct));

			strncpy(pTemp->sDataDate,ptPre->sStartTime,10);
			strcpy(pTemp->sDataDate+10,"0000");
			pTemp->tDataDate=tGetTime(pTemp->sDataDate);

			InsertList((LIST**)&pStat,(LIST*)pTemp);
		}

		InsertList((LIST**)&(pTemp->pHead),(LIST*)ptPre);
		pTemp->iCnt++;
	}
	return pStat;
}
struct DupTicketStruct *CreateDupTicketList(char sSourceID[],char sFileName[])
{
	char	sBaseName[128];
	struct DupTicketStruct *pList=NULL,*pTemp;
	struct FileControlStruct *ptHead=NULL,*pControl;

	GetBaseName(sFileName,sBaseName);

/*���ļ����ݵ��ú������ص��ڴ�*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("�����ļ�%s���ڴ�ʧ��.\n",sFileName);
		return NULL;
	}
/*ȷ���������ݺ��ļ�һ��*/
	ReverseList((LIST**)&ptHead);
	
	pControl=ptHead;
	while(ptHead!=NULL){

		if((pTemp=(struct DupTicketStruct *)malloc(
			sizeof(struct DupTicketStruct)))==NULL){
			listfree(&pControl);
			DestroyList((LIST*)pList);
			printf("����DupTicket�ڴ�ʧ��.\n");
			return NULL;

		}
		if(mvitem_record2ticket(ptHead,sSourceID,sBaseName,pTemp)<0)
			return NULL;

		InsertList((LIST**)&pList,(LIST*)pTemp);

		ptHead=ptHead->pNext;
	}

	return pList;
}
void UpdateDupHeadInfo(struct ShmDupHead* pi,struct ShmDupHead* po)
{
	po->iMaxChkDays=	pi->iMaxChkDays;
	po->iSemKey=		pi->iSemKey;

	po->iDiffSec=		pi->iDiffSec;
	po->iDiffStart=		pi->iDiffStart;
	po->iChkOpp=		pi->iChkOpp;

	po->CHourNode.iMax=pi->CHourNode.iMax;
	po->CTrieNode.iMax=pi->CTrieNode.iMax;
	po->CTrieData.iMax=pi->CTrieData.iMax;

	po->CHourNode.iMin=pi->CHourNode.iMin;
	po->CTrieNode.iMin=pi->CTrieNode.iMin;
	po->CTrieData.iMin=pi->CTrieData.iMin;
	
	strcpy(po->sTablespaceName,pi->sTablespaceName);
}
void InitDupHeadInfo(struct ShmDupHead* pi,struct ShmDupHead* po)
{
	int iMaxHour;
	POINTER ioffset=0;

	ioffset=sizeof(struct FShmStruct)+sizeof(struct ShmDupHead);

	memcpy((void*)po,(void*)pi,sizeof(struct ShmDupHead));

	iMaxHour=pi->iMaxChkDays*24;
	ioffset+=InitFShmCtrl(sizeof(EBINTREE),iMaxHour,
		(void*)&DUPMEM,ioffset,&(po->ItemNode));
	
	ioffset+=InitFShmCtrl(sizeof(struct BinItemStruct),iMaxHour,
		(void*)&DUPMEM,ioffset,&(po->ItemData));

	ioffset+=InitFShmCtrl(sizeof(ETRIE),po->CTrieNode.iMax,
		(void*)&DUPMEM,ioffset,&(po->TrieNode));

	ioffset+=InitFShmCtrl(sizeof(struct TTicketStruct),po->CTrieData.iMax,
		(void*)&DUPMEM,ioffset,&(po->TrieData));
}
int comp_insert_datadate_list(POINTER ioffSource,POINTER ioffTarget)
{
	struct BinItemStruct *pSource;
	struct BinItemStruct *pTarget;

	pSource=(struct BinItemStruct *)OPDUP(ioffSource);
	pTarget=(struct BinItemStruct *)OPDUP(ioffTarget);

	return pSource->tDataDate-pTarget->tDataDate;
}
void assign_insert_datadate_list(POINTER *pioffHead,POINTER ioffTarget)
{
	*pioffHead=ioffTarget;
}
int comp_search_datadate_list(void *pValue,POINTER ioffTarget)
{
	struct BinItemStruct *pTarget;
	time_t	tDataDate=*((time_t*)pValue);

	pTarget=(struct BinItemStruct *)OPDUP(ioffTarget);

	return tDataDate-pTarget->tDataDate;
}
int comp_search_starttime_list(void *pValue,POINTER ioffTarget)
{
	struct BinItemStruct *pTarget;
	time_t	tStartTime=*((time_t*)pValue);

	pTarget=(struct BinItemStruct *)OPDUP(ioffTarget);

	if(tStartTime<pTarget->tDataDate) return -1;
	if(tStartTime>=pTarget->tDataDate+3600) return 1;
	return 0;
}
void mvitem_item2hournode(struct BinItemStruct *pi,struct HourNodeStruct *po)
{
	bzero((void*)po,sizeof(struct HourNodeStruct));

	strcpy(po->sModule,	pi->sModule);
	strcpy(po->sDataDate,	pi->sDataDate);

	po->iMinAcrossBeginTime=(int)pi->tMinAcrossBeginTime;
	po->iMaxAcrossEndTime=	(int)pi->tMaxAcrossEndTime;

	po->iRecordCnt=		pi->iRecordCnt;
	po->iNodeCnt=		pi->iNodeCnt;
	po->iReadTimes=		pi->iReadTimes;
	po->iWriteTimes=	pi->iWriteTimes;
	po->iRebuildTimes=	pi->iRebuildTimes;
	strcpy(po->sState,	pi->sState);
}
void mvitem_hournode2item(struct HourNodeStruct *pi,struct BinItemStruct *po)
{
	bzero((void*)po,sizeof(struct BinItemStruct));

	po->ioffNext=-1;
	strcpy(po->sModule,	pi->sModule);
	strcpy(po->sDataDate,	pi->sDataDate);

	po->tMinAcrossBeginTime=(time_t)pi->iMinAcrossBeginTime;
	po->tMaxAcrossEndTime=	(time_t)pi->iMaxAcrossEndTime;

	po->iRecordCnt=		pi->iRecordCnt;
	po->iNodeCnt=		pi->iNodeCnt;
	po->iReadTimes=		pi->iReadTimes;
	po->iWriteTimes=	pi->iWriteTimes;
	po->iRebuildTimes=	pi->iRebuildTimes;
	strcpy(po->sState,	pi->sState);

	po->iCommitCnt=		pi->iRecordCnt;
	po->tDataDate=		tGetTime(pi->sDataDate);
	po->tLastAccessTime=	-1;

	po->ioffUseTimeNxt=-1;
	po->ioffNxt=-1;
	po->ioffPre=-1;
	
	po->iUpdated=true;
	po->ioffUpdateNxt=-1;
	po->ioffNew=-1;
	
	po->ioffTrie=-1;
	po->ioffList=-1;
}
int mv_ticket_list_duphead_tmp(POINTER *pioffData)
{
	int iCnt=0;
	struct TTicketStruct *pTemp;
	POINTER ioffHead=*pioffData,ioffTemp;
	
	while(ioffHead!=-1){

		ioffTemp=ioffHead;
		pTemp=(struct TTicketStruct *)OPDUP(ioffTemp);
		ioffHead=pTemp->ioffNext;
		
		InsertFList((void*)&DUPMEM,&igoffTmpList,ioffTemp);
		iCnt++;
	}
	
	*pioffData=-1;
	return iCnt;
}
int comp_hour_node_list(void *pValue,void*pHead)
{
	struct HourNodeStruct *pSource=(struct HourNodeStruct *)pValue;
	struct HourNodeStruct *pTarget=(struct HourNodeStruct *)pHead;

	return strcmp(pSource->sDataDate,pTarget->sDataDate);
}
void assign_hour_node_list(void **ppData,void *pData)
{
	InsertList((LIST**)(ppData),(LIST*)pData);
}
int free_hournode_data(void **ppData)
{
	free(*ppData);
	*ppData=NULL;
	return 0;
}
int AdjustItemBinTree(char sDataDate[],POINTER *pioffRoot)
{
	time_t	tTempDate;
	POINTER ioffTmp,ioffCur,ioffHead,ioffTail;
	BINTREE *pRoot=NULL;
	struct BinItemStruct *pTemp;
	char sTempDate[15],sBeginDate[15],sEndDate[15],sCurDate[15];
	struct HourNodeStruct *ptPre,*ptCur,**pptHead;
	struct HourNodeStruct TempNode,*ptHeadO=NULL,*ptHeadN=NULL;

	struct HourNodeStructOut TempOut;

	bzero((void*)&TempOut,sizeof(struct HourNodeStructOut));
	strcpy(TempOut.sTableName,"HOUR_NODE");

	bzero((void*)&TempNode,sizeof(struct HourNodeStruct));

	strcpy(sTempDate,sDataDate); strcpy(sTempDate+8,"000000");
	
	strcpy(sBeginDate,sTempDate);
	strcpy(sEndDate,sTempDate);
	AddYears(sBeginDate,-5);
	AddYears(sEndDate,5);

	GetHostTime(sTempDate);
	if(!(strcmp(sTempDate,sBeginDate)>=0&&strcmp(sTempDate,sEndDate)<0)){
		WriteAlertMsg("ʱ��Ƿ�,����ʱ�������ϵͳʱ���ǰ��10��");
		return -1;
	}
/*�����ܵ����ݿ��еļ�¼���ص��ڴ�*/
	if(InitHourNode(PSHMDUP->sModule,sBeginDate,sEndDate,&ptCur)<0)
		return -1;
/*������״�ṹ���ں�������*/
	while(ptCur!=NULL){
		ptPre=ptCur;ptCur=ptCur->pNext;
		if(InsertBin(&pRoot,(void*)ptPre,comp_hour_node_list,
			assign_hour_node_list)<0) return -1;
	}
/*����һ�µ��������ڴ��е�Ҷ�ӣ������ڼ�������ڵ�Ҷ��ȥ��*/
	DestroyFBin((void*)&DUPMEM,*pioffRoot,&(PSHMDUP->ItemNode));
	*pioffRoot=-1;
	ioffHead=PSHMDUP->ioffHead;
	while(ioffHead!=-1){

		ioffTmp=ioffHead;
		ioffHead=((struct BinItemStruct *)OPDUP(ioffHead))->ioffNxt;

		pTemp=(struct BinItemStruct *)OPDUP(ioffTmp);

/*��BinNode�Żؿ��ƽṹ��*/
		if(strcmp(pTemp->sDataDate,sBeginDate)>=0&&
			strcmp(pTemp->sDataDate,sEndDate)<0){

			if(InsertFBin((void*)&DUPMEM,pioffRoot,&(PSHMDUP->ItemNode),
				ioffTmp,comp_insert_datadate_list,
				assign_insert_datadate_list)<0) return -1;
		}
		else{
/*�����µĹ����ڴ��trie��data�Żص���ջ��*/
			FreeItemData(ioffTmp);
			DestroyLeaveTrie(pTemp);
			DestroyLeaveData(pTemp);

			if(pTemp->iUpdated==true)/*���ڵ���벻һ��������*/
				InsertBinUpdatedList(ioffTmp);
		}

	}
/*��������*/
/*
ptHeadO�������ڴ��ز����ڣ��������ݿ����е�Ҷ��
ptHeadN: �����ڴ治���ڣ��������ݿ�Ҳû�еļ�¼*/
	ptCur=NULL;
	for(strcpy(sCurDate,sBeginDate);strcmp(sCurDate,sEndDate)<0;
		AddHours(sCurDate,1)){

		tTempDate=tGetTime(sCurDate);
		if(SearchFBin((void*)&DUPMEM,*pioffRoot,(void*)&tTempDate,
			comp_search_datadate_list,&ioffCur)==FOUND)continue;

		strcpy(TempNode.sDataDate,sCurDate);
		if(SearchBin(pRoot,(void*)&TempNode,
			comp_hour_node_list,(void**)&ptCur)==NOTFOUND){

			pptHead=&ptHeadN;
			if((ptCur=(struct HourNodeStruct*)malloc(
				sizeof(struct HourNodeStruct)))==NULL)
				return -1;
			bzero((void*)ptCur,sizeof(struct HourNodeStruct));

			strcpy(ptCur->sModule,PSHMDUP->sModule);
			strcpy(ptCur->sDataDate,sCurDate);
			ptCur->iMinAcrossBeginTime=-1;
			ptCur->iMaxAcrossEndTime=-1;
			ptCur->sState[0]=STATE_INDB;
		}
		else
			pptHead=&ptHeadO;

		InsertList((LIST**)pptHead,(LIST*)ptCur);
	}
/*���Ѿ������ݿ��еļ�¼д�������ڴ�*/
	ptCur=ptHeadO;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		/*����һ��Ҫ��Ϊ������DB��*/
		ptPre->sState[0]=STATE_INDB;

		if((ioffTmp=MallocItemData())==-1) return -1;
		pTemp=(struct BinItemStruct *)OPDUP(ioffTmp);
		mvitem_hournode2item(ptPre,pTemp);

		if(InsertFBin((void*)&DUPMEM,pioffRoot,&(PSHMDUP->ItemNode),
			ioffTmp,comp_insert_datadate_list,
			assign_insert_datadate_list)<0) return -1;
	}
/*���������ݿ��еļ�¼д�������ڴ�����ݿ�*/
	ptCur=ptHeadN;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if((ioffTmp=MallocItemData())==-1) return -1;
		pTemp=(struct BinItemStruct *)OPDUP(ioffTmp);
		mvitem_hournode2item(ptPre,pTemp);

		if(InsertFBin((void*)&DUPMEM,pioffRoot,&(PSHMDUP->ItemNode),
			ioffTmp,comp_insert_datadate_list,
			assign_insert_datadate_list)<0) return -1;

/*����д�����ݿ�*/
		if(EInsertStructToHourNode(ptPre,false,&TempOut)<0) return -1;
	}

	if(EInsertStructToHourNode(NULL,true,&TempOut)<0) return -1;

	CommitWork();

/*�ͷ�һϵ�е���ʱռ�õ��ڴ�*/
	TravelBin(pRoot,free_hournode_data);/*ptHeadO�������ͷ���*/
	DestroyBin(pRoot);
	DestroyList((LIST*)ptHeadN);

/*��������,����������LIST*/
	PSHMDUP->ioffUseTimeHead=ioffHead=ioffTail=-1;
	CHOURNODE.iCur=0;
	for(strcpy(sCurDate,sBeginDate);strcmp(sCurDate,sEndDate)<0;
		AddHours(sCurDate,1)){

		tTempDate=tGetTime(sCurDate);/*����Ҳ������߼�����*/
		if(SearchFBin((void*)&DUPMEM,*pioffRoot,(void*)&tTempDate,
			comp_search_datadate_list,&ioffCur)==NOTFOUND)
			return -1;
		pTemp=(struct BinItemStruct *)OPDUP(ioffCur);

		if(pTemp->sState[0]!=STATE_INDB)
			InsertUseTimeLeave(ioffCur);

		pTemp->ioffPre=	ioffTail;
		ioffTail=	ioffCur;
	}
/*��ioffTailת��������ioffHead*/
	ioffCur=ioffTail;
	while(ioffCur!=-1){
		ioffTmp=ioffCur;
		pTemp=(struct BinItemStruct *)OPDUP(ioffCur);
		ioffCur=pTemp->ioffPre;

		pTemp->ioffNxt=ioffHead;
		ioffHead=	ioffTmp;
	}

	PSHMDUP->ioffHead=	ioffHead;
	PSHMDUP->ioffTail=	ioffTail;

	return 0;
}
int comp_sort_dup_ticket_list(POINTER ioffSource,POINTER ioffTarget)
{
	struct TTicketStruct *pSource;
	struct TTicketStruct *pTarget;

	pSource=(struct TTicketStruct *)OPDUP(ioffSource);
	pTarget=(struct TTicketStruct *)OPDUP(ioffTarget);

	return pSource->tStartTime-pTarget->tStartTime;
}
void assign_insert_dup_ticket_trie(POINTER *pioffHead,POINTER ioffValue)
{
	InsertFListSort((void*)&DUPMEM,pioffHead,ioffValue,
		comp_sort_dup_ticket_list);
}
void InsertBinUpdatedList(POINTER ioffCur)
{
	char	sAccessTime[15];
	struct BinItemStruct *ptCur;

	ptCur=(struct BinItemStruct *)OPDUP(ioffCur);
	
	GetHostTime(sAccessTime);
	
	ptCur->tLastAccessTime=	tGetTime(sAccessTime);
	ptCur->ioffUpdateNxt=	PSHMDUP->ioffUpdateHead;
	PSHMDUP->ioffUpdateHead=ioffCur;
	ptCur->iUpdated=	false;
}
void InsertNewList(POINTER *pioffHead,POINTER ioffValue)
{
	struct TTicketStruct *pTemp;
	
	pTemp=(struct TTicketStruct *)OPDUP(ioffValue);
	pTemp->ioffNew= *pioffHead;
	*pioffHead=	ioffValue;
}
int Ticket2Shm(struct DupTicketStruct *ptHead)
{
	int iNodeCnt;
	POINTER ioffTmp,ioffCur;
	struct TTicketStruct *pTemp;
	struct BinItemStruct *ptCur;

	if((ioffTmp=MallocTrieData())<0){
		WriteProcMsg("����01t=%s,h=%d,n=%d,d=%d",ptHead->sStartTime,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
		return -1;
	}

	pTemp=(struct TTicketStruct*)OPDUP(ioffTmp);

	mvitem_dupticket2ticket(ptHead,pTemp);

	if(SearchFBin((void*)&DUPMEM,PSHMDUP->ioffRoot,
		(void*)&(ptHead->tStartTime),
		comp_search_starttime_list,&ioffCur)==NOTFOUND){
		WriteProcMsg("����02t=%s,h=%d,n=%d,d=%d",ptHead->sStartTime,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
		return -1;
	}
	ptCur=(struct BinItemStruct *)OPDUP(ioffCur);
	
	if(ptCur->iUpdated==true)/*���ڵ���벻һ��������*/
		InsertBinUpdatedList(ioffCur);

	ptCur->iRecordCnt++;
	ptCur->iCommitCnt++;
	
	if(ptCur->sState[0]==STATE_MEMNOIND){
		pTemp->ioffNext=ptCur->ioffList;
		ptCur->ioffList=ioffTmp;
		
		InsertNewList(&ptCur->ioffNew,ioffTmp);
	}
	else if(ptCur->sState[0]==STATE_INMEM){
		if((iNodeCnt=InsertFTrie((void*)&DUPMEM,&(ptCur->ioffTrie),
			pTemp->sMsisdn,&(PSHMDUP->TrieNode),ioffTmp,
			assign_insert_dup_ticket_trie))<0){
			WriteProcMsg("����03t=%s,h=%d,n=%d,d=%d",ptHead->sStartTime,
				CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
			return -1;
		}
		ptCur->iNodeCnt+=iNodeCnt;
		
		InsertNewList(&ptCur->ioffNew,ioffTmp);
	}
	else/*����Ѿ��������ݿ����˼�¼����ֱ�Ӳ��빲���ڴ�*/
		FreeTrieData(ioffTmp);

	return 0;
}
int CheckDUPSHM(char sDataDate[])
{
	POINTER ioffCur;
	time_t	tDataDate=tGetTime(sDataDate);
	
	if(SearchFBin((void*)&DUPMEM,PSHMDUP->ioffRoot,(void*)&tDataDate,
		comp_search_datadate_list,&ioffCur)==NOTFOUND){
		
		/*����Сʱ�ڵ㲻��������е���*/

		if(AdjustItemBinTree(sDataDate,&PSHMDUP->ioffRoot)<0){
			WriteAlertMsg("����FBINTREE����,%s",sDataDate);
			return -1;
		}

		if(SearchFBin((void*)&DUPMEM,PSHMDUP->ioffRoot,
			(void*)&tDataDate,
			comp_search_datadate_list,&ioffCur)==NOTFOUND){
			WriteAlertMsg("Ӧ�ó����߼�����");
			return -1;
		}
	}
	return 0;
}
void ItemNeedShmRes(struct BinItemStruct *ptCur,int *piNodeCnt,int *piDataCnt)
{
	if(ptCur->sState[0]==STATE_INDB){
		*piNodeCnt=ptCur->iNodeCnt;
		*piDataCnt=ptCur->iRecordCnt;
	}
	else if(ptCur->sState[0]==STATE_MEMNOIND){
		*piNodeCnt=ptCur->iNodeCnt;
		*piDataCnt=0;
	}
	else
		*piNodeCnt=*piDataCnt=0;
}
void InsertUseTimeLeave(POINTER ioffValue)
{
	struct BinItemStruct *pTemp;
	
	if(ioffValue==-1) return;

	CHOURNODE.iCur++;
	
	pTemp=(struct BinItemStruct *)OPDUP(ioffValue);
	pTemp->ioffUseTimeNxt=		PSHMDUP->ioffUseTimeHead;
	PSHMDUP->ioffUseTimeHead=	ioffValue;

}
int DeleteUseTimeLeave(POINTER ioffValue)
{
	POINTER ioffPre,ioffCur;
	struct BinItemStruct *pTemp,*ptPre,*ptCur;
	
	if(ioffValue==-1) return false;
	
	CHOURNODE.iCur--;

	pTemp=(struct BinItemStruct *)OPDUP(ioffValue);
	
	if(ioffValue==PSHMDUP->ioffUseTimeHead){
		PSHMDUP->ioffUseTimeHead=	pTemp->ioffUseTimeNxt;
		return true;
	}
	
	ioffPre=PSHMDUP->ioffUseTimeHead;	
	ptPre=(struct BinItemStruct *)OPDUP(ioffPre);

	ioffCur=ptPre->ioffUseTimeNxt;
	ptCur=(struct BinItemStruct *)OPDUP(ioffCur);
	
	while(ioffCur!=-1){
		if(ioffCur==ioffValue){
			ptPre->ioffUseTimeNxt=ptCur->ioffUseTimeNxt;
			return true;
		}
		ioffPre=ioffCur;
		ioffCur=ptCur->ioffUseTimeNxt;
		
		ptPre=ptCur;
		ptCur=(struct BinItemStruct *)OPDUP(ioffCur);
	}
	
	return false;
	
}
POINTER WhatLeave(time_t tDataDate,char cIgnoreState)
{
	struct BinItemStruct *pTemp;
	POINTER ioffHead,ioffTemp=-1,ioffCur=-1;
	time_t tLastAccessTime=tGetTime("20200101000000");;
	
	ioffHead=PSHMDUP->ioffUseTimeHead;
	
	while(ioffHead!=-1){
		
		ioffTemp=ioffHead;
		pTemp=(struct BinItemStruct *)OPDUP(ioffTemp);
		ioffHead=pTemp->ioffUseTimeNxt;
		
		if(pTemp->sState[0]==cIgnoreState) continue;
		
		if(tDataDate>=pTemp->tDataDate&&
			tDataDate<pTemp->tDataDate+3599) continue;

		if(pTemp->tLastAccessTime<tLastAccessTime){
			ioffCur=ioffTemp;
			tLastAccessTime=pTemp->tLastAccessTime;
		}
	}
	if(ioffCur<0){
		WriteAlertMsg("�Ҳ�������ɾ���Ľڵ�h=%d,tn=%d,td=%d",
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
	}
			
	return ioffCur;
	
}
void DestroyLeaveTrie(struct BinItemStruct *ptHead)
{
	int iDataCnt,iNodeCnt;

	/*���ڲ����ڴ��е��������˳�*/
	if(ptHead->sState[0]!=STATE_INMEM) return;

	igoffTmpList=-1;

/*�����еĻ�������igoffTmpList��*/
	iDataCnt=TravelFTrie((void*)&DUPMEM,ptHead->ioffTrie,
		mv_ticket_list_duphead_tmp);
/*�������ڴ��е�TRIE�ڵ�ɾ��*/
	iNodeCnt=DestroyFTrie((void*)&DUPMEM,
		ptHead->ioffTrie,&(PSHMDUP->TrieNode));

/*��igoffTmpList�е����ݷŵ�->ioffList������*/
/*	AppendFListTail((void*)&DUPMEM,&(ptHead->ioffList),igoffTmpList);

	WriteProcMsg("reccnt=%d nodecnt=%d rc=%d nc=%d r=%d r1=%d\n",
		ptHead->iRecordCnt,ptHead->iNodeCnt,iDataCnt,iNodeCnt,
		CountFList((void*)&DUPMEM,ptHead->ioffList),
		CountFList((void*)&DUPMEM,igoffTmpList));
*/
/*	ptHead->ioffList=igoffTmpList; ����д����ȫ,��һ��д����ȫ*/
	
	AppendFListTail((void*)&DUPMEM,&(ptHead->ioffList),igoffTmpList);
/*����ʱ�������*/
	igoffTmpList=-1;
	ptHead->ioffTrie=-1;
	ptHead->sState[0]=STATE_MEMNOIND;
	
	CTRIENODE.iCur=PSHMDUP->TrieNode.iUsedCnt;
}
void DestroyLeaveData(struct BinItemStruct *ptHead)
{
	POINTER ioffHead,ioffTemp;
	struct TTicketStruct *pTemp;
	
	ioffHead=ptHead->ioffList;

	while(ioffHead!=-1){

		ioffTemp=ioffHead;
		pTemp=(struct TTicketStruct *)OPDUP(ioffTemp);
		ioffHead=pTemp->ioffNext;
		
		FreeTrieData(ioffTemp);
	}
	ptHead->ioffList=-1;
	ptHead->ioffNew=-1;
	ptHead->sState[0]=STATE_INDB;
	CTRIEDATA.iCur=PSHMDUP->TrieData.iUsedCnt;
}
int CreateLeaveData(struct BinItemStruct *ptHead)
{
	int iDataCnt=0;
	POINTER ioffTemp;
	struct TTicketStruct *pTemp;
	struct DupTicketStruct *ptPre=NULL,*ptCur=NULL;

	ptHead->ioffList=-1;
		
	if((iDataCnt=InitDupTicket(ptHead->sDataDate,PSHMDUP->sModule,
		PSHMDUP->sTablespaceName,&ptCur))<0) return -1;
	
	while(ptCur!=NULL){
		
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		if((ioffTemp=MallocTrieData())<0){
			
			WriteAlertMsg("CreateLeaveData�߼�����h=%d,n=%d,d=%d",
				CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
			DestroyLeaveData(ptHead);
			return -1;
		}
		pTemp=(struct TTicketStruct *)OPDUP(ioffTemp);
		
		mvitem_dupticket2ticket(ptPre,pTemp);
		
		InsertFList((void*)&DUPMEM,&(ptHead->ioffList),ioffTemp);
	}
	if(iDataCnt!=ptHead->iRecordCnt){
		WriteProcMsg("hour=%s reccnt=%d been updated by %d",
			ptHead->sDataDate,ptHead->iRecordCnt,iDataCnt);
		ptHead->iRecordCnt=iDataCnt;
	}
	ptHead->sState[0]=STATE_MEMNOIND;
	CTRIEDATA.iCur=PSHMDUP->TrieData.iUsedCnt;
		
	return 0;
}
int CreateLeaveTrie(struct BinItemStruct *ptHead)
{
	int iNodeCnt=0,iCurCnt;
	POINTER ioffHead,ioffTemp;
	struct TTicketStruct *pTemp;
	
	ptHead->ioffTrie=-1;
	ioffHead=ptHead->ioffList;

	while(ioffHead!=-1){

		ioffTemp=ioffHead;
		pTemp=(struct TTicketStruct *)OPDUP(ioffTemp);
		ioffHead=pTemp->ioffNext;

		if((iCurCnt=InsertFTrie((void*)&DUPMEM,&(ptHead->ioffTrie),
			pTemp->sMsisdn,&(PSHMDUP->TrieNode),ioffTemp,
			assign_insert_dup_ticket_trie))<0){

			WriteAlertMsg("CreateLeaveTrie�߼�����h=%d,n=%d,d=%d",
				CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
			DestroyLeaveTrie(ptHead);
			return -1;			
		}
		iNodeCnt+=iCurCnt;
	}
	if(iNodeCnt!=ptHead->iNodeCnt){
		WriteProcMsg("hour=%s nodecnt=%d been updated by %d",
			ptHead->sDataDate,ptHead->iNodeCnt,iNodeCnt);
		ptHead->iNodeCnt=iNodeCnt;
	}
	ptHead->ioffList=-1;
	ptHead->sState[0]=STATE_INMEM;
	CTRIENODE.iCur=PSHMDUP->TrieNode.iUsedCnt;
	
	return 0;
}
int AdjustHourNode(time_t tDataDate)
{
	POINTER ioffCur;
	struct BinItemStruct *pTemp;
	
	while(CHOURNODE.iCur>CHOURNODE.iMin){
		
		if((ioffCur=WhatLeave(tDataDate,STATE_INDB))==-1) return -1;

		pTemp=(struct BinItemStruct *)OPDUP(ioffCur);
		
		WriteProcMsg("hr=%s pageout h=%d,n=%d,d=%d",pTemp->sDataDate,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);

		DestroyLeaveTrie(pTemp);
		DestroyLeaveData(pTemp);
		
		DeleteUseTimeLeave(ioffCur);
		pTemp->sState[0]=STATE_INDB;
		
		if(pTemp->iUpdated==true)/*���ڵ���벻һ��������*/
			InsertBinUpdatedList(ioffCur);
	}
	return 0;
}
int AdjustTrieNode(time_t tDataDate,int iNodeCnt)
{
	POINTER ioffCur;
	struct BinItemStruct *pTemp;

	while(CTRIENODE.iCur>(CTRIENODE.iMin-(POINTER)iNodeCnt)){
		
		if((ioffCur=WhatLeave(tDataDate,STATE_MEMNOIND))==-1) return -1;
		
		pTemp=(struct BinItemStruct *)OPDUP(ioffCur);
		
		DestroyLeaveTrie(pTemp);
		pTemp->sState[0]=STATE_MEMNOIND;

		WriteProcMsg("hr=%s drpind h=%d,n=%d,d=%d",pTemp->sDataDate,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);

		if(pTemp->iUpdated==true)/*���ڵ���벻һ��������*/
			InsertBinUpdatedList(ioffCur);
	}
	return 0;
}
int AdjustTrieData(time_t tDataDate,int iDataCnt)
{
	
	POINTER ioffCur;
	struct BinItemStruct *pTemp;
	
	while(CTRIEDATA.iCur>(CTRIEDATA.iMin-(POINTER)iDataCnt)){
		
		if((ioffCur=WhatLeave(tDataDate,STATE_INDB))==-1) return -1;

		pTemp=(struct BinItemStruct *)OPDUP(ioffCur);
		
		DestroyLeaveTrie(pTemp);
		DestroyLeaveData(pTemp);

		DeleteUseTimeLeave(ioffCur);
		pTemp->sState[0]=STATE_INDB;
		
		WriteProcMsg("hr=%s pageout h=%d,n=%d,d=%d",pTemp->sDataDate,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);

		if(pTemp->iUpdated==true)/*���ڵ���벻һ��������*/
			InsertBinUpdatedList(ioffCur);
	}
	return 0;
}
void GetHourList(char sHour[])
{
	char sPin[7];
	struct BinItemStruct *pTemp;
	POINTER ioffHead,ioffTemp=-1;
	
	strcpy(sHour,"");
	
	ioffHead=PSHMDUP->ioffUseTimeHead;
	
	while(ioffHead!=-1){
		
		ioffTemp=ioffHead;
		pTemp=(struct BinItemStruct *)OPDUP(ioffTemp);
		ioffHead=pTemp->ioffUseTimeNxt;
		
		strncpy(sPin,pTemp->sDataDate+4,6);sPin[6]=0;

		if(ioffHead!=-1) strcat(sPin,",");
		
		strcat(sHour,sPin);
	}
}
int CompTicket(char sAOpp[],char sBOpp[],time_t tAStartTime,
	time_t tBStartTime,int iADuration,int iBDuration)
{
	int res=0;

	if(PSHMDUP->iChkOpp){
		if((res=strcmp(sAOpp,sBOpp))!=0) return res;
	}
	res =tAStartTime-tBStartTime;
	if(res<-(PSHMDUP->iDiffStart)||res>PSHMDUP->iDiffStart) return res;
	
	res=iADuration-iBDuration;
	if(res<-(PSHMDUP->iDiffSec)||res>PSHMDUP->iDiffSec) return res;

	return 0;
}
int AdjustCheckDup(struct DupTicketStruct *p,struct BinItemStruct *ptCur,
	int iNodeCnt,int iDataCnt)
{
	if(CTRIENODE.iCur>=(CTRIENODE.iMax-(POINTER)iNodeCnt)||
		CTRIEDATA.iCur>=(CTRIEDATA.iMax-(POINTER)iDataCnt)||
		CHOURNODE.iCur>=CHOURNODE.iMax){

		char sHour[1024];

		GetHourList(sHour);

		WriteProcMsg("�л���ʼt=%s,h=%d,n=%d,d=%d nn=%d nd=%d\n%s",
			p->sStartTime,CHOURNODE.iCur,CTRIENODE.iCur,
			CTRIEDATA.iCur,iNodeCnt,iDataCnt,sHour);

/*���������Ƶĵ���*/
		if(AdjustHourNode(ptCur->tDataDate)<0) 	return -1;
			
		if(AdjustTrieNode(ptCur->tDataDate,iNodeCnt)<0)	return -1;

		if(AdjustTrieData(ptCur->tDataDate,iDataCnt)<0)	return -1;
		
		GetHourList(sHour);
		WriteProcMsg("�л�����t=%s,h=%d,n=%d,d=%d \n%s",p->sStartTime,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur,sHour);
	}
	return 0;
}
int CheckDupTicket(struct DupTicketStruct *p,int iCnt)
{
	int	iNodeCnt=0,iDataCnt=0;
	POINTER ioffCur,ioffTmp,ioffHead;
	struct	TTicketStruct *pTmp;
	struct BinItemStruct *ptCur;
	
	if(SearchFBin((void*)&DUPMEM,PSHMDUP->ioffRoot,(void*)&(p->tStartTime),
		comp_search_starttime_list,&ioffCur)==NOTFOUND) return -1;
		
	ptCur=(struct BinItemStruct *)OPDUP(ioffCur);
	
/*�����Ҫ�ڴ���Դ�������������Ҫ���򴥷�����*/
	ItemNeedShmRes(ptCur,&iNodeCnt,&iDataCnt);

	if(iNodeCnt<0||iDataCnt<0){
		WriteAlertMsg("����00t=%s,h=%d,n=%d,d=%d nc=%d dc=%d",
			p->sStartTime,CHOURNODE.iCur,CTRIENODE.iCur,
			CTRIEDATA.iCur,iNodeCnt,iDataCnt);
		return -1;
	}
	iCnt+=20000;iNodeCnt+=(iCnt*2);iDataCnt+=iCnt;

	/*�����ڴ�ǰ��һ�ε���*/
	if(AdjustCheckDup(p,ptCur,iNodeCnt,iDataCnt)<0) return -1;

	if(ptCur->sState[0]!=STATE_INMEM){
	
		if(ptCur->sState[0]==STATE_INDB){

			if(CreateLeaveData(ptCur)<0) return -1;

			InsertUseTimeLeave(ioffCur);
			
			WriteProcMsg("hr=%s pagein h=%d,n=%d,d=%d",
				ptCur->sDataDate,CHOURNODE.iCur,
				CTRIENODE.iCur,CTRIEDATA.iCur);

		}

		if(CreateLeaveTrie(ptCur)<0) return -1;

		WriteProcMsg("hr=%s crtind h=%d,n=%d,d=%d",ptCur->sDataDate,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);

		/*�ϴε���������ε���*/
		if(AdjustCheckDup(p,ptCur,iCnt,iCnt)<0) return -1;

	}
	
	if(SearchFTrie((void*)&DUPMEM,ptCur->ioffTrie,p->sMsisdn,
		&ioffTmp)==NOTFOUND) return false;

	ioffHead=ioffTmp;
	while(ioffHead!=-1){

		ioffTmp=ioffHead;
		pTmp=(struct	TTicketStruct *)OPDUP(ioffTmp);
		ioffHead=pTmp->ioffNext;
		
		if(strcmp(p->sCallType,pTmp->sCallType)==0&&
			strcmp(p->sMsisdn,pTmp->sMsisdn)==0){

			if(CompTicket(p->sOtherParty,pTmp->sOtherParty,
				p->tStartTime,pTmp->tStartTime,
				p->iDuration,pTmp->iDuration)==0) return true;
		}	
	}
	
	return false;
}
int CheckDupMain(struct HourStatStruct *ptHead,int *piNormalCnt,int *piDupCnt)
{
	int i,iNormalCnt=0,iDupCnt=0;
	struct HourStatStruct *pTemp;
	struct DupTicketStruct *ptPre,*ptCur;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		ptCur=pTemp->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;

			if(ptPre->iDupFlag==0){
			/*��������ص��Ƚ�����д�빲���ڴ棬��������ʱ������*/
				if((i=CheckDupTicket(ptPre,pTemp->iCnt))<0)
					return -1;

				if(i==true){
					iDupCnt++;
					ptPre->iDupFlag=1;
				}
				else	iNormalCnt++;
			}
			else if(ptPre->iDupFlag==2) iNormalCnt++;
			else iDupCnt++;
		}
	}
	*piNormalCnt=	iNormalCnt;
	*piDupCnt=	iDupCnt;
	return 0;
}
int SearchDupTicketOut(struct FileControlStruct *ptHead,char sTableName[],
	struct DupTicketStructOut **pptCur)
{
	struct DupTicketStructOut *pTmp=NULL;


	while(ptHead!=NULL){
		pTmp=(struct DupTicketStructOut *)ptHead->pData;
		if(strcmp(sTableName,pTmp->sTableName)==0){
			*pptCur=pTmp;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
/*���������������*/
int InsertTicket2Dup(struct HourStatStruct *ptHead)
{
	char	sDataDate[9],sPreName[31],sTableName[31];
	struct HourStatStruct *pTemp;
	struct DupTicketStruct *ptPre,*ptCur;
	struct FileControlStruct *pTempOut=NULL;
	struct DupTicketStructOut *pTarget=NULL,Temp;

	strcpy(sPreName,"");
	strcpy(sTableName,"");

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sDataDate,pTemp->sDataDate,8);
		sDataDate[8]=0;
		
		strcpy(sPreName,sTableName);
		sprintf(sTableName,"DUP_TICKET_%s_%s",
				PSHMDUP->sModule,sDataDate);

		if(SearchDupTicketOut(pTempOut,sTableName,&pTarget)==NOTFOUND){

			bzero((void*)&Temp,sizeof(struct DupTicketStructOut));

			strcpy(Temp.sTableName,sTableName);

			if(item2list(&pTempOut,(void*)&Temp,
				sizeof(struct DupTicketStructOut))<0)
				return -1;
			/*��һ�����*/
			if(SearchDupTicketOut(pTempOut,sTableName,
				&pTarget)==NOTFOUND) return -1;
		}

		ptCur=pTemp->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
		/*ϵͳ��д�룬��Ҫ������ȷ�ϲ����ص��ļ�¼������*/
			if(ptPre->iDupFlag!=0) continue;

			if(EInsertStructToDupTicket(ptPre,false,pTarget)<0)
				return -1;
		}

		/*��������л��ˣ�����Ҫ��buffer���*/
/*		if(strcmp(sPreName,"")!=0&&strcmp(sTableName,sPreName)!=0){

			if(EInsertStructToDupTicket(NULL,true,pTarget)<0)
				return -1;
		}
*/
	}
	while(pTempOut!=NULL){

		pTarget=(struct DupTicketStructOut *)pTempOut->pData;

		if(EInsertStructToDupTicket(NULL,true,pTarget)<0) return -1;

		pTempOut=pTempOut->pNext;
	}

	return 0;
}
void GetDupName(char sSourceName[],char sTargetDir[],char sDupName[])
{
	char *pc;
	char sBaseName[128];
	
	GetBaseName(sSourceName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;
	
	sprintf(sDupName,"%s%s.DUP",sTargetDir,sBaseName);
}
int WriteDup2File(struct HourStatStruct *ptHead,int iNormalCnt,
	int iDupCnt,char sSourceName[],char sTargetDir[])
{
	struct HourStatStruct *pTemp;
	struct DupTicketStruct *ptPre,*ptCur;

	char	sNormalName[128],sDupName[128],sCommand[256];
	struct	FileControlStruct *pNormal=NULL,*pDup=NULL;

	sprintf(sNormalName,"%s",sSourceName);
	GetDupName(sSourceName,sTargetDir,sDupName);

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		ptCur=pTemp->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
		/*�����غ�ȷʵ����Ҫ�����Һ˲�����ص��ļ�¼д���ص��ļ�*/
			if(ptPre->iDupFlag==1)
				InsertList((LIST**)&pDup,(LIST*)ptPre->pOri);
			else	InsertList((LIST**)&pNormal,(LIST*)ptPre->pOri);
		}
	}
	/*ֻ�����ص�������²���д�ļ�*/
	if(iNormalCnt==0){
		sprintf(sCommand,"mv %s %s ",sNormalName,sDupName);
		system(sCommand);
		listfree(&pNormal);
		listfree(&pDup);
	}
	else if(iDupCnt!=0){
		if(list2fileln(&pNormal,sNormalName)<0) return -1;
		if(list2fileln(&pDup,sDupName)<0) return -1;
	}
	else{
		listfree(&pNormal);
		listfree(&pDup);
	}

	return 0;
}
void ArchDupShm()
{
	struct BinItemStruct *pTemp;
	POINTER ioffHead=0,ioffTemp;

	ioffHead=PSHMDUP->ioffUpdateHead;
	
	while(ioffHead!=-1){
		
		ioffTemp=ioffHead;

		pTemp=(struct BinItemStruct *)OPDUP(ioffHead);
		ioffHead=pTemp->ioffUpdateNxt;
		
		pTemp->iPreRecordCnt	=pTemp->iRecordCnt;     
		pTemp->iPreNodeCnt      =pTemp->iNodeCnt;     
		pTemp->iPreReadTimes    =pTemp->iReadTimes;   
		pTemp->iPreWriteTimes   =pTemp->iWriteTimes;  
		pTemp->iPreRebuildTimes =pTemp->iRebuildTimes;
		pTemp->iPreCommitCnt    =pTemp->iCommitCnt;
		pTemp->tPreLastAccessTime=pTemp->tLastAccessTime;

		pTemp->ioffNew=-1;/*�鵵�ϴ��Ѿ�OK�Ķ���*/
		pTemp->iUpdated=true;
	}
	PSHMDUP->ioffUpdateHead=-1;
}
void ResetItemShm(struct BinItemStruct *ptHead)
{
	struct TTicketStruct *pTemp;
	POINTER ioffHead=ptHead->ioffNew,ioffTemp,*pioffTmp;
	
	
	while(ioffHead!=-1){

		ioffTemp=ioffHead;
		pTemp=(struct TTicketStruct *)OPDUP(ioffHead);
		ioffHead=pTemp->ioffNew;
		
		pioffTmp=GetFTrieLk((void*)&DUPMEM, ptHead->ioffTrie,
			pTemp->sMsisdn);
		if(pioffTmp==NULL) continue;	/*��ȫ�������һ���ж�*/
		if(*pioffTmp==-1)continue;
/*��������Ӽ�����ɾ��*/
		DeleteFList((void*)&DUPMEM,pioffTmp,ioffTemp);
/*��ɾ�������Ķ����Ż��ڴ����������*/
		FreeTrieData(ioffTemp);
	}
	ptHead->ioffNew=-1;
}
void ResetDupShm()
{
	struct BinItemStruct *pTemp;
	POINTER ioffHead,ioffTemp;
	ioffHead=PSHMDUP->ioffUpdateHead;
	
	while(ioffHead!=-1){
		
		ioffTemp=ioffHead;
		pTemp=(struct BinItemStruct *)OPDUP(ioffHead);
		ioffHead=pTemp->ioffUpdateNxt;
		
		pTemp->iRecordCnt    =pTemp->iPreRecordCnt;     
		pTemp->iNodeCnt      =pTemp->iPreNodeCnt;     
		pTemp->iReadTimes    =pTemp->iPreReadTimes;   
		pTemp->iWriteTimes   =pTemp->iPreWriteTimes;  
		pTemp->iRebuildTimes =pTemp->iPreRebuildTimes;
		pTemp->iCommitCnt    =pTemp->iPreCommitCnt;
		pTemp->tLastAccessTime=pTemp->tPreLastAccessTime;
		
		pTemp->iUpdated=true;
		ResetItemShm(pTemp);
	}
	PSHMDUP->ioffUpdateHead=-1;
}
int TicketFile2Shm(struct HourStatStruct *ptHead)
{
	struct HourStatStruct *pTemp;
	struct DupTicketStruct *ptPre,*ptCur;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		ptCur=pTemp->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;

			if(ptPre->iDupFlag==0){
				if(Ticket2Shm(ptPre)<0) return -1;
			}
		}
	}
	
	CTRIENODE.iCur=PSHMDUP->TrieNode.iUsedCnt;
	CTRIEDATA.iCur=PSHMDUP->TrieData.iUsedCnt;
	
	return 0;
}
int SynHourNodeInfo()
{
	static int iFirstFlag=true;
	static struct HourNodeStruct Temp;
	static struct HourNodeStructUp TempUp;
	
	struct BinItemStruct *pTemp;
	POINTER ioffHead,ioffTemp;
	ioffHead=PSHMDUP->ioffUpdateHead;
	
	if(iFirstFlag==true){
		iFirstFlag=false;
		strcpy(TempUp.sTableName,"HOUR_NODE");
	}
	
	while(ioffHead!=-1){
		
		ioffTemp=ioffHead;
		pTemp=(struct BinItemStruct *)OPDUP(ioffHead);
		ioffHead=pTemp->ioffUpdateNxt;
		
		mvitem_item2hournode(pTemp,&Temp);
		if(EUpdateStructToHourNode(&Temp,false,&TempUp)<0) return -1;
	}
	
	if(EUpdateStructToHourNode(NULL,true,&TempUp)<0) return -1;
	
	return 0;
}
void RollbackOutputFile(char sTargetDir[],char sFileName[],
	int iNormalCnt,int iDupCnt)
{
	char sCommand[256],sBaseName[256],sTargetName[256];
	
	GetBaseName(sFileName,sBaseName);
	
	if(iNormalCnt!=0){
		sprintf(sTargetName,"%s%s.NOR",sTargetDir,sBaseName);
		sprintf(sCommand,"test -f %s && rm -f %s",
			sTargetName,sTargetName);
		system(sCommand);
	}
	if(iDupCnt!=0){
		sprintf(sTargetName,"%s%s.DUP",sTargetDir,sBaseName);
		sprintf(sCommand,"test -f %s && rm -f %s",
			sTargetName,sTargetName);
		system(sCommand);
	}
}
int data_search_bintree_dup_ticket_e(void *pValue,void *pData)
{
	struct DupTicketStruct *pSource=(struct DupTicketStruct *)pValue;
	struct DupTicketStruct *pTarget=(struct DupTicketStruct *)pData;
	
	int res=0;
	
	if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;

	return CompTicket(pSource->sOtherParty,pTarget->sOtherParty,
		tGetTime(pSource->sStartTime),tGetTime(pTarget->sStartTime),
		pSource->iDuration,pTarget->iDuration);
/*
	if((res=strcmp(pSource->sOtherParty,pTarget->sOtherParty))!=0) return res;

	res =tGetTime(pSource->sStartTime)-tGetTime(pTarget->sStartTime);
	if(res<-1||res>1) return res;
	
	res=pSource->iDuration-pTarget->iDuration;
	if(res<-1||res>1) return res;

	return 0;
*/
}
void assign_insert_bintree_dup_ticket_only(void **ppData,void *pData)
{
	*ppData=pData;
}
/*�����BINTREE��һ�������BINTREE���䲻�޸�pNext*/
int CheckInternalDup(struct DupTicketStruct *ptHead)
{
	int iCnt=0;
	BINTREE *pRoot=NULL;
	struct DupTicketStruct *pNoUse,*pTemp;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(pTemp->iDupFlag!=0) continue;

		/*����ļ����ص��ҵ����޸�*/
		if(SearchBin(pRoot,(void*)pTemp,
			data_search_bintree_dup_ticket_e,
			(void*)&pNoUse)==FOUND){
			pTemp->iDupFlag=1;
			continue;
		}
		/*�����ݼ���ƽ���������,���޸�pNext*/
		if(InsertBin(&pRoot,(void*)pTemp,
			data_search_bintree_dup_ticket_e,
			assign_insert_bintree_dup_ticket_only)<0) return -1;
		iCnt++;
	}
	
	DestroyBin(pRoot);

	return iCnt;
}
int igLayer=0;

int TravelFFBin(void *pNodeSeg,POINTER ioffsetHead,
	int ( *pOperation)(POINTER *,int),int iLayer)
{
	int j=0;
	EBINTREE *ptHead;
	
	if(ioffsetHead==-1) return 0;
	
	ptHead=OPFBINTREE(pNodeSeg,ioffsetHead);
	
	if(ptHead->ioffLeft!=-1)
		j+=TravelFFBin(pNodeSeg,ptHead->ioffLeft,pOperation,iLayer+1);
	if(ptHead->ioffRight!=-1)
		j+=TravelFFBin(pNodeSeg,ptHead->ioffRight,pOperation,iLayer+1);
	j+=(*pOperation)(&(ptHead->ioffData),iLayer);
	return j;
}
int print_fbin_tree(POINTER *pioffHead,int iLayer)
{
	struct BinItemStruct *pTemp;

	pTemp=(struct BinItemStruct *)OPDUP(*pioffHead);
	
	PrintLog("aa.txt","l=%d,%s\n",iLayer,pTemp->sDataDate);

	return 0;
}
int WantBillExpr(char sModule[])
{
	char sTemp[128],sPath[128];

	GetIniName(sPath);
	if(ReadString(sPath,"bss","prep","billexpr",sTemp)<0) return false;
	
	if(strstr(sTemp,sModule)==NULL) return false;
	return true;
}
int ChkDupMain(char sModule[],char sSourceID[],char sSourceName[],
	char sTargetDir[],char msg[])
{
	void *pShm;
	int iCreateFlag=false,iNormalCnt=0,iDupCnt=0,iSemID=0;
	char sBaseName[128];
	struct ShmDupHead Temp;
	struct DupTicketStruct *pTicketList=NULL;
	struct HourStatStruct *ptHead=NULL;

	if(WantBillExpr(sModule)){
		MoveAllShmToMem();
		InitTollTariffList(comp_toll_tariff_ticket);
		RegRateExprFun();
	}

	if(InitShmDupHead(sModule,&Temp)<0){
		WriteAlertPrint("�ص�����ȡ%s���ص�������ʧ��",sModule);
		WriteErrStackAlert();
		return -1;
	}
	if((pShm=AttachMultiShm(Temp.iShmKey,&DUPMEM))==NULL){
		if((pShm=CreateMultiShm(Temp.iShmKey,(POINTER)Temp.iTotalLen,
			(POINTER)Temp.iBlockLen,&DUPMEM))==NULL){
			WriteAlertPrint("�ص���鴴��%d key�Ĺ����ڴ�ʧ��",
				Temp.iShmKey);
			RollbackWorkRelease();
			return -1;
		}
		WriteProcMsg("m=%s,tl=%d,h0=%d,h1=%d,tdl=%d,tnl=%d,bdl=%d,bnl=%d\n",
			Temp.sModule,Temp.iTotalLen,
			sizeof(struct FShmStruct),sizeof(struct ShmDupHead),
			sizeof(struct TTicketStruct),sizeof(ETRIE),
			sizeof(struct BinItemStruct),sizeof(EBINTREE));
		iCreateFlag=true;
	}
	if((iSemID=AttachSem(Temp.iSemKey))<0){
		if((iSemID=CreateSem(Temp.iSemKey,1))<0){
			WriteAlertPrint("�ص���鴴�� %d key�Ĺ����ڴ�ʧ��",
				Temp.iSemKey);
			RollbackWorkRelease();
			return -1;
		}
	}
	
	PSHMDUP=(struct ShmDupHead *)OPELIST(pShm,sizeof(struct FShmStruct));
	LockSem(iSemID);
	if(iCreateFlag==false)/*��������Ϣʵʱ���µ������ڴ�*/
		UpdateDupHeadInfo(&Temp,PSHMDUP);
	else	InitDupHeadInfo(&Temp,PSHMDUP);
	UnlockSem(iSemID);
/** ������
	TravelFFBin(&DUPMEM,PSHMDUP->ioffRoot,print_fbin_tree,0); exit(1);
*/
/*�����ﹲ���ڴ��ӳ���Ѿ�����*/

/*�������Ļ������뻰������*/
	if((pTicketList=CreateDupTicketList(sSourceID,sSourceName))==NULL){
		strcpy(msg,"�������뻰���������");
		goto err_next;
	}
/*����ļ����ص�*/
	if(CheckInternalDup(pTicketList)<0){
		strcpy(msg,"�ļ��ں��ص�����-->InsertBin");
		goto err_next;
	}

/*�������Ļ�������Сʱͳ��������*/
	if((ptHead=CreateHourStat(pTicketList))==NULL){
		strcpy(msg,"����Сʱͳ���������");
		goto err_next;
	}
	LockSem(iSemID);
/*��鹲���ڴ��е�BINITEM����ȷ��*/
	if(CheckDUPSHM(ptHead->sDataDate)<0){
		strcpy(msg,"��鹲���ڴ��е�BINITEM����");
		UnlockSem(iSemID);
		goto err_next;
	}
/*�����ص����ѭ��*/
	if(CheckDupMain(ptHead,&iNormalCnt,&iDupCnt)<0){
		strcpy(msg,"�����ص����ѭ������");
		UnlockSem(iSemID);
		goto err_next;
	}
	UnlockSem(iSemID);
/*���������ص�����*/
	if(InsertTicket2Dup(ptHead)<0){
		strcpy(msg,"���������ص��������");
		goto err_next;
	}
/*������д�����Ŀ¼*/
	if(WriteDup2File(ptHead,iNormalCnt,iDupCnt,sSourceName,sTargetDir)<0){
		strcpy(msg,"������д�����Ŀ¼����");
		goto err_next;
	}
	LockSem(iSemID);
/*�������ļ�д�빲���ڴ�*/
	if(TicketFile2Shm(ptHead)<0){
		strcpy(msg,"�������ļ�д�빲���ڴ����");
		UnlockSem(iSemID);
		goto err_next;
	}
	UnlockSem(iSemID);
/*ͬ��Сʱ�ڵ�������Ϣ*/
	if(SynHourNodeInfo()<0){
		strcpy(msg,"ͬ��Сʱ�ڵ�������Ϣ����");
		goto err_next;
	}
/*��û������,�򱣴�ս�����޸Ĺ����ڴ��iPre��ioffNew��ioffUpdateHead����Ϣ*/
	LockSem(iSemID);
	ArchDupShm();
	UnlockSem(iSemID);
	
	GetBaseName(sSourceName,sBaseName);

	sprintf(msg,"%d\t%d\t%d\t%d\t%d\t%s",
		iNormalCnt,iDupCnt,CHOURNODE.iCur,
		CTRIENODE.iCur,CTRIEDATA.iCur,sBaseName);

	CommitWork();
	DetachMultiShm(&DUPMEM);
	return 0;
err_next:
	ResetDupShm();
	WriteErrStackAlert();
	RollbackWork();
	RollbackOutputFile(sTargetDir,sSourceName,iNormalCnt,iDupCnt);
	DetachMultiShm(&DUPMEM);
	return -1;
}
