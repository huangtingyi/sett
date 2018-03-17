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
	char	sState[2];	/*'0' 数据库,'1' 在内存中,'2' 无树*/

	int 	iCommitCnt;	/*当commitcnt,recordcnt不一致的时候表明有数据*/
	time_t	tLastAccessTime;

/*历史的东西*/
	int 	iPreRecordCnt;
	int 	iPreNodeCnt;
	int 	iPreReadTimes;
	int 	iPreWriteTimes;
	int 	iPreRebuildTimes;
	int 	iPreCommitCnt;
	time_t	tPreLastAccessTime;

	time_t	tDataDate;
	
	POINTER ioffUseTimeNxt;/*LRU链表后继*/

	POINTER ioffNxt;	/*小时顺序线索后继*/
	POINTER ioffPre;	/*小时顺序线索前趋*/
	
	int	iUpdated;	/*true,一致,false不一致*/
	POINTER ioffUpdateNxt;	/*变动归档链表*/
	POINTER ioffNew;	/*新话单链表，未进库的话单链表*/
	
	POINTER ioffTrie;	/*话单平衡二叉树的头节点*/
	POINTER ioffList;	/*无索引时话单所在的链表*/
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
	char	sModule[4];	/*子系统*/
	int	iShmKey;
	int	iSemKey;
	POINTER	iBlockLen;
	POINTER	iTotalLen;
	int	iMaxChkDays;

	int	iDiffSec;		/*时间差距，差距多少duration时间算重单*/
	int	iDiffStart;		/*差距多少,start_time算重单*/
	int	iChkOpp;		/*检查other_party字段选项,0不检查,1检查*/

	struct	ShmCtrlStruct	ItemNode;
	struct	ShmCtrlStruct	ItemData; /*小时节点个数*/
	struct	ShmCtrlStruct	TrieNode; /*索引节点个数*/
	struct	ShmCtrlStruct	TrieData; /*索引数据个数*/

	struct AdjCtrlStruct CHourNode;
	struct AdjCtrlStruct CTrieNode;
	struct AdjCtrlStruct CTrieData;

	char	sTablespaceName[31];/*表空间名*/
	char	sExprName[256];

	POINTER	ioffHead;		/*指向时间最小部分的指针节点*/
	POINTER	ioffTail;		/*指向时间最小部分的指针节点*/
	POINTER	ioffUseTimeHead;	/*指向有新增记录节点首指针*/
	POINTER ioffUpdateHead;		/*不一致链表*/
	POINTER	ioffRoot;		/*小时节点平衡二叉树*/
	POINTER ioffTmp;		/*临时存放截断下来的TRIE叶子*/
};
struct TTicketStruct{

	POINTER		ioffNext;/*freelist，bintreelist*/
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
POINTER igoffTmpList=-1; /*存放临时从TRIE卸下话单记录链表,DestroyLeaveTrie用*/

void ItemNeedShmRes(struct BinItemStruct *ptCur,int *piNodeCnt,int *piDataCnt);
void InsertUseTimeLeave(POINTER ioffValue);
int DeleteUseTimeLeave(POINTER ioffValue);
void DestroyLeaveTrie(struct BinItemStruct *ptHead);
void DestroyLeaveData(struct BinItemStruct *ptHead);
POINTER WhatLeave(time_t tDataDate,char cIgnoreState);
void InsertBinUpdatedList(POINTER ioffCur);
/*
dupflag取值 : 
dupflag=0	需要查重，查重后不是重单
dupflag=1	0->1,查重后的确是重单
dupflag=2	不需要查重，写正常话单文件且不入库
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
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->iShmKey=Str2Int(sTemp);

	strcpy(sItem,"semkey");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->iSemKey=Str2Int(sTemp);

/****新增三选项目开始*/
	strcpy(sItem,"diff_sec");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	p->iDiffSec=Str2Int(sTemp);
	if(p->iDiffSec>3)p->iDiffSec=3;

	strcpy(sItem,"diff_start");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	p->iDiffSec=Str2Int(sTemp);
	if(p->iDiffStart>60)p->iDiffStart=60;

	strcpy(sItem,"chk_opp");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	p->iChkOpp=Str2Int(sTemp);
/**三选项新增结束**/

	strcpy(sItem,"hournode_max");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->CHourNode.iMax=Str2Int(sTemp);

	strcpy(sItem,"hournode_min");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->CHourNode.iMin=Str2Int(sTemp);


	strcpy(sItem,"trienode_max");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->CTrieNode.iMax=Str2Int(sTemp);

	strcpy(sItem,"trienode_min");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->CTrieNode.iMin=Str2Int(sTemp);


	strcpy(sItem,"triedata_max");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->CTrieData.iMax=Str2Int(sTemp);

	strcpy(sItem,"triedata_min");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	p->CTrieData.iMin=Str2Int(sTemp);

	strcpy(sItem,"tablespace_name");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	if(i<0||strlen(sTemp)==0) strcpy(p->sTablespaceName,"CHKDATA");
	else	strcpy(p->sTablespaceName,sTemp);
	
	strcpy(sItem,"expr_name");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
                sModule,sItem);
	GetBillHome(sBillHome);
	sprintf(p->sExprName,"%sexpr/%s",sBillHome,sTemp);

	ERROR_RETURNA(!IsFile(p->sExprName),"文件%s不存在",p->sExprName);
	l=FileSize(p->sExprName);
	ERROR_RETURNA((l>=1024*16)||(l<=0),"文件%s大小不在0-16K范围内",
		p->sExprName);
	ERROR_RETURNA((fp=fopen(p->sExprName,"r"))==NULL,"打开文件%s失败",
		p->sExprName);
	ERROR_RETURNA(fread(sInput,l,1,fp)!=1,"读取文件%s失败",
		p->sExprName);
	sInput[l]=0;fclose(fp);
	RegPrepVar();
	CheckSysVar=CheckPrepVar;

	ERROR_RETURNB((i=CompileExpr(sInput,asVarOutput,&l))<0,
		"编译公式%s错误::\n%s",p->sExprName,pExprBuf->sErrorMsg);

	strcpy(sItem,"max_blk_len");
	i=ReadString(sPath,"chkdup",sModule,sItem,sTemp);
	ERROR_RETURNZ(i<0,"读取bill.ini文件失败");
	ERROR_RETURNB((strlen(sTemp)==0),"bill.ini->chkdup->%s-%s无对应配置",
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
		printf("执行公式%s失败,程序退出.\n",PSHMDUP->sExprName);
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

/*将文件数据调用函数加载到内存*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件%s到内存失败.\n",sFileName);
		return NULL;
	}
/*确保链表数据和文件一致*/
	ReverseList((LIST**)&ptHead);
	
	pControl=ptHead;
	while(ptHead!=NULL){

		if((pTemp=(struct DupTicketStruct *)malloc(
			sizeof(struct DupTicketStruct)))==NULL){
			listfree(&pControl);
			DestroyList((LIST*)pList);
			printf("分配DupTicket内存失败.\n");
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
		WriteAlertMsg("时间非法,数据时间必须在系统时间的前后10年");
		return -1;
	}
/*将可能的数据库中的记录加载到内存*/
	if(InitHourNode(PSHMDUP->sModule,sBeginDate,sEndDate,&ptCur)<0)
		return -1;
/*建立树状结构便于后续查找*/
	while(ptCur!=NULL){
		ptPre=ptCur;ptCur=ptCur->pNext;
		if(InsertBin(&pRoot,(void*)ptPre,comp_hour_node_list,
			assign_hour_node_list)<0) return -1;
	}
/*遍历一下调整共享内存中的叶子，将不在检查区域内的叶子去掉*/
	DestroyFBin((void*)&DUPMEM,*pioffRoot,&(PSHMDUP->ItemNode));
	*pioffRoot=-1;
	ioffHead=PSHMDUP->ioffHead;
	while(ioffHead!=-1){

		ioffTmp=ioffHead;
		ioffHead=((struct BinItemStruct *)OPDUP(ioffHead))->ioffNxt;

		pTemp=(struct BinItemStruct *)OPDUP(ioffTmp);

/*将BinNode放回控制结构中*/
		if(strcmp(pTemp->sDataDate,sBeginDate)>=0&&
			strcmp(pTemp->sDataDate,sEndDate)<0){

			if(InsertFBin((void*)&DUPMEM,pioffRoot,&(PSHMDUP->ItemNode),
				ioffTmp,comp_insert_datadate_list,
				assign_insert_datadate_list)<0) return -1;
		}
		else{
/*将其下的共享内存的trie和data放回到堆栈中*/
			FreeItemData(ioffTmp);
			DestroyLeaveTrie(pTemp);
			DestroyLeaveData(pTemp);

			if(pTemp->iUpdated==true)/*将节点插入不一致链表中*/
				InsertBinUpdatedList(ioffTmp);
		}

	}
/*生成链表*/
/*
ptHeadO：共享内存重不存在，但在数据库中有的叶子
ptHeadN: 共享内存不存在，且在数据库也没有的记录*/
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
/*将已经在数据库中的记录写到共享内存*/
	ptCur=ptHeadO;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		/*这里一定要设为数据在DB中*/
		ptPre->sState[0]=STATE_INDB;

		if((ioffTmp=MallocItemData())==-1) return -1;
		pTemp=(struct BinItemStruct *)OPDUP(ioffTmp);
		mvitem_hournode2item(ptPre,pTemp);

		if(InsertFBin((void*)&DUPMEM,pioffRoot,&(PSHMDUP->ItemNode),
			ioffTmp,comp_insert_datadate_list,
			assign_insert_datadate_list)<0) return -1;
	}
/*将不在数据库中的记录写到共享内存和数据库*/
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

/*额外写入数据库*/
		if(EInsertStructToHourNode(ptPre,false,&TempOut)<0) return -1;
	}

	if(EInsertStructToHourNode(NULL,true,&TempOut)<0) return -1;

	CommitWork();

/*释放一系列的临时占用的内存*/
	TravelBin(pRoot,free_hournode_data);/*ptHeadO在这里释放了*/
	DestroyBin(pRoot);
	DestroyList((LIST*)ptHeadN);

/*建立线索,并建立在用LIST*/
	PSHMDUP->ioffUseTimeHead=ioffHead=ioffTail=-1;
	CHOURNODE.iCur=0;
	for(strcpy(sCurDate,sBeginDate);strcmp(sCurDate,sEndDate)<0;
		AddHours(sCurDate,1)){

		tTempDate=tGetTime(sCurDate);/*如果找不到则逻辑错误*/
		if(SearchFBin((void*)&DUPMEM,*pioffRoot,(void*)&tTempDate,
			comp_search_datadate_list,&ioffCur)==NOTFOUND)
			return -1;
		pTemp=(struct BinItemStruct *)OPDUP(ioffCur);

		if(pTemp->sState[0]!=STATE_INDB)
			InsertUseTimeLeave(ioffCur);

		pTemp->ioffPre=	ioffTail;
		ioffTail=	ioffCur;
	}
/*将ioffTail转过来就是ioffHead*/
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
		WriteProcMsg("错误01t=%s,h=%d,n=%d,d=%d",ptHead->sStartTime,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
		return -1;
	}

	pTemp=(struct TTicketStruct*)OPDUP(ioffTmp);

	mvitem_dupticket2ticket(ptHead,pTemp);

	if(SearchFBin((void*)&DUPMEM,PSHMDUP->ioffRoot,
		(void*)&(ptHead->tStartTime),
		comp_search_starttime_list,&ioffCur)==NOTFOUND){
		WriteProcMsg("错误02t=%s,h=%d,n=%d,d=%d",ptHead->sStartTime,
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
		return -1;
	}
	ptCur=(struct BinItemStruct *)OPDUP(ioffCur);
	
	if(ptCur->iUpdated==true)/*将节点插入不一致链表中*/
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
			WriteProcMsg("错误03t=%s,h=%d,n=%d,d=%d",ptHead->sStartTime,
				CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
			return -1;
		}
		ptCur->iNodeCnt+=iNodeCnt;
		
		InsertNewList(&ptCur->ioffNew,ioffTmp);
	}
	else/*如果已经到了数据库中了记录，则直接不入共享内存*/
		FreeTrieData(ioffTmp);

	return 0;
}
int CheckDUPSHM(char sDataDate[])
{
	POINTER ioffCur;
	time_t	tDataDate=tGetTime(sDataDate);
	
	if(SearchFBin((void*)&DUPMEM,PSHMDUP->ioffRoot,(void*)&tDataDate,
		comp_search_datadate_list,&ioffCur)==NOTFOUND){
		
		/*发现小时节点不存在则进行调整*/

		if(AdjustItemBinTree(sDataDate,&PSHMDUP->ioffRoot)<0){
			WriteAlertMsg("调整FBINTREE错误,%s",sDataDate);
			return -1;
		}

		if(SearchFBin((void*)&DUPMEM,PSHMDUP->ioffRoot,
			(void*)&tDataDate,
			comp_search_datadate_list,&ioffCur)==NOTFOUND){
			WriteAlertMsg("应用程序逻辑错误");
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
		WriteAlertMsg("找不到可以删除的节点h=%d,tn=%d,td=%d",
			CHOURNODE.iCur,CTRIENODE.iCur,CTRIEDATA.iCur);
	}
			
	return ioffCur;
	
}
void DestroyLeaveTrie(struct BinItemStruct *ptHead)
{
	int iDataCnt,iNodeCnt;

	/*对于不在内存中的数据则退出*/
	if(ptHead->sState[0]!=STATE_INMEM) return;

	igoffTmpList=-1;

/*将数中的话单放在igoffTmpList中*/
	iDataCnt=TravelFTrie((void*)&DUPMEM,ptHead->ioffTrie,
		mv_ticket_list_duphead_tmp);
/*将共享内存中的TRIE节点删除*/
	iNodeCnt=DestroyFTrie((void*)&DUPMEM,
		ptHead->ioffTrie,&(PSHMDUP->TrieNode));

/*将igoffTmpList中的数据放到->ioffList链表中*/
/*	AppendFListTail((void*)&DUPMEM,&(ptHead->ioffList),igoffTmpList);

	WriteProcMsg("reccnt=%d nodecnt=%d rc=%d nc=%d r=%d r1=%d\n",
		ptHead->iRecordCnt,ptHead->iNodeCnt,iDataCnt,iNodeCnt,
		CountFList((void*)&DUPMEM,ptHead->ioffList),
		CountFList((void*)&DUPMEM,igoffTmpList));
*/
/*	ptHead->ioffList=igoffTmpList; 这样写不安全,后一种写法安全*/
	
	AppendFListTail((void*)&DUPMEM,&(ptHead->ioffList),igoffTmpList);
/*将临时链表清空*/
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
			
			WriteAlertMsg("CreateLeaveData逻辑错误h=%d,n=%d,d=%d",
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

			WriteAlertMsg("CreateLeaveTrie逻辑错误h=%d,n=%d,d=%d",
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
		
		if(pTemp->iUpdated==true)/*将节点插入不一致链表中*/
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

		if(pTemp->iUpdated==true)/*将节点插入不一致链表中*/
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

		if(pTemp->iUpdated==true)/*将节点插入不一致链表中*/
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

		WriteProcMsg("切换开始t=%s,h=%d,n=%d,d=%d nn=%d nd=%d\n%s",
			p->sStartTime,CHOURNODE.iCur,CTRIENODE.iCur,
			CTRIEDATA.iCur,iNodeCnt,iDataCnt,sHour);

/*做三个控制的调整*/
		if(AdjustHourNode(ptCur->tDataDate)<0) 	return -1;
			
		if(AdjustTrieNode(ptCur->tDataDate,iNodeCnt)<0)	return -1;

		if(AdjustTrieData(ptCur->tDataDate,iDataCnt)<0)	return -1;
		
		GetHourList(sHour);
		WriteProcMsg("切换结束t=%s,h=%d,n=%d,d=%d \n%s",p->sStartTime,
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
	
/*检查需要内存资源数，如果不满足要求则触发调整*/
	ItemNeedShmRes(ptCur,&iNodeCnt,&iDataCnt);

	if(iNodeCnt<0||iDataCnt<0){
		WriteAlertMsg("错误00t=%s,h=%d,n=%d,d=%d nc=%d dc=%d",
			p->sStartTime,CHOURNODE.iCur,CTRIENODE.iCur,
			CTRIEDATA.iCur,iNodeCnt,iDataCnt);
		return -1;
	}
	iCnt+=20000;iNodeCnt+=(iCnt*2);iDataCnt+=iCnt;

	/*加载内存前做一次调整*/
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

		/*上次调整不到这次调整*/
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
			/*如果不是重单先将数据写入共享内存，并存在临时链表中*/
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
/*将话单该入库的入库*/
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
			/*做一个检测*/
			if(SearchDupTicketOut(pTempOut,sTableName,
				&pTarget)==NOTFOUND) return -1;
		}

		ptCur=pTemp->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
		/*系统仅写入，需要查重且确认不是重单的记录到表中*/
			if(ptPre->iDupFlag!=0) continue;

			if(EInsertStructToDupTicket(ptPre,false,pTarget)<0)
				return -1;
		}

		/*如果表做切换了，则需要将buffer清空*/
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
		/*将核重后确实是需要核重且核查出是重单的记录写入重单文件*/
			if(ptPre->iDupFlag==1)
				InsertList((LIST**)&pDup,(LIST*)ptPre->pOri);
			else	InsertList((LIST**)&pNormal,(LIST*)ptPre->pOri);
		}
	}
	/*只有有重单的情况下才重写文件*/
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

		pTemp->ioffNew=-1;/*归档上次已经OK的东西*/
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
		if(pioffTmp==NULL) continue;	/*安全起见做的一个判断*/
		if(*pioffTmp==-1)continue;
/*将数据项从键树中删除*/
		DeleteFList((void*)&DUPMEM,pioffTmp,ioffTemp);
/*将删除下来的东西放回内存管理链表中*/
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
/*这里的BINTREE是一种特殊的BINTREE，其不修改pNext*/
int CheckInternalDup(struct DupTicketStruct *ptHead)
{
	int iCnt=0;
	BINTREE *pRoot=NULL;
	struct DupTicketStruct *pNoUse,*pTemp;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(pTemp->iDupFlag!=0) continue;

		/*如果文件内重单找到则修改*/
		if(SearchBin(pRoot,(void*)pTemp,
			data_search_bintree_dup_ticket_e,
			(void*)&pNoUse)==FOUND){
			pTemp->iDupFlag=1;
			continue;
		}
		/*将数据加入平衡二叉树中,不修改pNext*/
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
		WriteAlertPrint("重单检查获取%s的重单检查参数失败",sModule);
		WriteErrStackAlert();
		return -1;
	}
	if((pShm=AttachMultiShm(Temp.iShmKey,&DUPMEM))==NULL){
		if((pShm=CreateMultiShm(Temp.iShmKey,(POINTER)Temp.iTotalLen,
			(POINTER)Temp.iBlockLen,&DUPMEM))==NULL){
			WriteAlertPrint("重单检查创建%d key的共享内存失败",
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
			WriteAlertPrint("重单检查创建 %d key的共享内存失败",
				Temp.iSemKey);
			RollbackWorkRelease();
			return -1;
		}
	}
	
	PSHMDUP=(struct ShmDupHead *)OPELIST(pShm,sizeof(struct FShmStruct));
	LockSem(iSemID);
	if(iCreateFlag==false)/*将备份信息实时更新到共享内存*/
		UpdateDupHeadInfo(&Temp,PSHMDUP);
	else	InitDupHeadInfo(&Temp,PSHMDUP);
	UnlockSem(iSemID);
/** 测试用
	TravelFFBin(&DUPMEM,PSHMDUP->ioffRoot,print_fbin_tree,0); exit(1);
*/
/*到这里共享内存的映像已经建立*/

/*将待检查的话单加入话单链表*/
	if((pTicketList=CreateDupTicketList(sSourceID,sSourceName))==NULL){
		strcpy(msg,"话单加入话单链表错误");
		goto err_next;
	}
/*检查文件内重单*/
	if(CheckInternalDup(pTicketList)<0){
		strcpy(msg,"文件内核重单错误-->InsertBin");
		goto err_next;
	}

/*将待检查的话单加入小时统计链表中*/
	if((ptHead=CreateHourStat(pTicketList))==NULL){
		strcpy(msg,"加入小时统计链表错误");
		goto err_next;
	}
	LockSem(iSemID);
/*检查共享内存中的BINITEM的正确性*/
	if(CheckDUPSHM(ptHead->sDataDate)<0){
		strcpy(msg,"检查共享内存中的BINITEM错误");
		UnlockSem(iSemID);
		goto err_next;
	}
/*进行重单检查循环*/
	if(CheckDupMain(ptHead,&iNormalCnt,&iDupCnt)<0){
		strcpy(msg,"进行重单检查循环错误");
		UnlockSem(iSemID);
		goto err_next;
	}
	UnlockSem(iSemID);
/*将话单入重单检查库*/
	if(InsertTicket2Dup(ptHead)<0){
		strcpy(msg,"将话单入重单检查库错误");
		goto err_next;
	}
/*将话单写入输出目录*/
	if(WriteDup2File(ptHead,iNormalCnt,iDupCnt,sSourceName,sTargetDir)<0){
		strcpy(msg,"将话单写入输出目录错误");
		goto err_next;
	}
	LockSem(iSemID);
/*将话单文件写入共享内存*/
	if(TicketFile2Shm(ptHead)<0){
		strcpy(msg,"将话单文件写入共享内存错误");
		UnlockSem(iSemID);
		goto err_next;
	}
	UnlockSem(iSemID);
/*同步小时节点日子信息*/
	if(SynHourNodeInfo()<0){
		strcpy(msg,"同步小时节点日子信息错误");
		goto err_next;
	}
/*都没问题了,则保存战果，修改共享内存的iPre和ioffNew和ioffUpdateHead等信息*/
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
