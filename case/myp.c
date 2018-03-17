/*---------函数实现代码 unicom_ticket.pc----------*/

#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>

#include <param_intf.h>
#include <stt_ticket.h>
#include <ticket_field.h>

static int iTCount=0,iTSameCnt=0,iTDiffCnt=0;

#define STATE_FOUND		'1'
#define STATE_NOTFOUND		'0'

struct TimeOffsetStruct
{
	struct TimeOffsetStruct *pNext;
	char	sMsc[15];
	int	iOffsetTotal;
	int	iCnt;
	int 	iOffset;
};
int data_search_bintree_prep_ticket_e(void *pValue,void *pData)
{
        struct PrepTicketStruct *pSource=(struct PrepTicketStruct *)pValue;
        struct PrepTicketStruct *pTarget=(struct PrepTicketStruct *)pData;

/*数据比较部分*/
	return strcmp(pSource->sMsisdn,pTarget->sMsisdn);
}
int key_comp_prep_ticket_e(LIST *pValue,LIST *pData)
{
        struct PrepTicketStruct *pSource=(struct PrepTicketStruct *)pValue;
        struct PrepTicketStruct *pTarget=(struct PrepTicketStruct *)pData;
        
	int res=0;
        if((res=strcmp(pSource->sStartTime,pTarget->sStartTime))!=0) return res;
        
        return atoi(pSource->sDuration)-atoi(pTarget->sDuration);
        
        
}
void assign_insert_bintree_prep_ticket_e(void **pptHead,void *pData)
{
        InsertListSort((LIST**)pptHead,(LIST*)pData,
        	key_comp_prep_ticket_e);
}
int UnicomCallOtherCarrierLocal(struct PrepTicketStruct *p)
{
	int iRet;
	char sCalledCode[10],sVisitAreaCode[10];
	struct HeadCarrStruct	*pHeadCarr=NULL;
	
	
	strcpy(sVisitAreaCode,"592");
	
	if(SearchHeadCarr(p->sMsisdn,
		"*",p->sStartTime,&pHeadCarr)==NOTFOUND) return false;

	if(pHeadCarr->iSettCarrierID!=3) return false;

	if(SearchHeadCarr(p->sOtherParty,
		"*",p->sStartTime,&pHeadCarr)==NOTFOUND) return false;

	if(pHeadCarr->iSettCarrierID==3) return false;
	
	
	if(GetCalledAreaCode(p->sCallType,p->sOtherParty,sVisitAreaCode,
		p->sStartTime,&iRet,sCalledCode)==NOTFOUND) return false;

	if(strcmp(sVisitAreaCode,sCalledCode)!=0) return false;
	
	return true;
}
int OtherCarrierCallUnicom(struct PrepTicketStruct *p)
{
	struct HeadCarrStruct	*pHeadCarr=NULL;
	
	if(SearchHeadCarr(p->sOtherParty,
		"*",p->sStartTime,&pHeadCarr)==NOTFOUND) return false;

	if(pHeadCarr->iSettCarrierID!=3) return false;

	if(SearchHeadCarr(p->sMsisdn,
		"*",p->sStartTime,&pHeadCarr)==NOTFOUND) return false;

	if(pHeadCarr->iSettCarrierID==3) return false;
	
	return true;

}
void ExchangeAccNbr(struct PrepTicketStruct *p)
{
	char sTemp[32];
	
	struct HeadCarrStruct	*pHeadCarr=NULL;
	
	strcpy(p->sOtherLac,"0");
	
	if(SearchHeadCarr(p->sOtherParty,
		"*",p->sStartTime,&pHeadCarr)==NOTFOUND) return;

	if(pHeadCarr->iSettCarrierID!=3) return;
	
	strcpy(sTemp,p->sOtherParty);
	strcpy(p->sOtherParty,p->sMsisdn);
	strncpy(p->sMsisdn, sTemp,15);
	p->sMsisdn[15]=0;
	
	strcpy(p->sOtherLac,"1");
}
/*批量数据结构缓冲加载数据二叉树查找*/
int MountPrepTicketToBin(BINTREE **pptHead,char sTableName[])
{
	int iCount=0;
       	BINTREE *ptHead=NULL; 
       
        struct PrepTicketStruct *pTemp;
        struct PrepTicketStruct Temp;
        struct PrepTicketStructIn TempIn;

        bzero((void*)&TempIn,sizeof(struct PrepTicketStructIn));

	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,"");
	
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetPrepTicketToStruct(&Temp,&TempIn)){
        	
		/*设置初始状态*/
		strcpy(Temp.sServiceType,"000");
		
		
/*为SAME表制造关联字段*/
		strcpy(Temp.sMsrn,"");
		
		if((pTemp=malloc(sizeof(struct PrepTicketStruct)))==NULL) return -1;
                memcpy(pTemp,(void *)&Temp,sizeof(struct PrepTicketStruct));
	
                InsertBin(&ptHead,pTemp,data_search_bintree_prep_ticket_e,
                        assign_insert_bintree_prep_ticket_e);
		if(++iCount%10000==0) 
			printf("加载话单表TELECOM_TICKET %d 条.\n",iCount);

        }

        *pptHead=ptHead;
	printf("完毕，共加载话单表TELECOM_TICKET %d 条.\n",iCount);
        
        return 0;
}

int SearchTimeOffset(struct TimeOffsetStruct *ptHead,char sMsc[],
	struct TimeOffsetStruct **pptCur)
{
	while(ptHead!=NULL){
		if(strcmp(sMsc,ptHead->sMsc)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
struct TimeOffsetStruct *GetTimeOffset(struct PrepTicketStruct *p)
{
	struct TimeOffsetStruct *pTemp=NULL;
	static struct TimeOffsetStruct *ptHead=NULL;
	
	if(SearchTimeOffset(ptHead,p->sMsc,&pTemp)==NOTFOUND){

		if((pTemp=(struct TimeOffsetStruct *)malloc(
			sizeof(struct TimeOffsetStruct)))==NULL){
			printf("malloc TimeOffsetStruct error.\n");
			exit(1);
		}
		bzero((void*)pTemp,sizeof(struct TimeOffsetStruct));
		strcpy(pTemp->sMsc,p->sMsc);

		InsertList((LIST**)&ptHead,(LIST*)pTemp);		
	}
	return pTemp;
}
int SearchPrepTicketBin(BINTREE *pRoot,struct PrepTicketStruct *p,
	char sStartTime[],int iDiffTime,int iDiffDuration,
	struct PrepTicketStruct **ppCur)
{
	int	iLastDiff=iDiffTime,iCurDiff,d1,d2;
	time_t	tStartTime=tGetTime(sStartTime),tTempTime;
	struct PrepTicketStruct *ptHead=NULL,*pTemp;
	static struct PrepTicketStruct Temp;

	*ppCur=NULL;


	strcpy(Temp.sMsisdn,p->sMsisdn);

	if(SearchBin(pRoot,&Temp,
		data_search_bintree_prep_ticket_e,
		(void **)&ptHead)==NOTFOUND) return NOTFOUND;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

/*通话时间不在时间范围内的话单则继续或者退出*/
		tTempTime=tGetTime(pTemp->sStartTime);
		
		iCurDiff=tTempTime-tStartTime;
			
		if(iCurDiff>=iDiffTime) break;
		if(iCurDiff<=-iDiffTime) continue;

/*通话时间在时间范围内,但是时长不匹配则不是*/
		d1=atoi(p->sDuration);
		d2=atoi(pTemp->sDuration);
		
		if(d1>=d2+iDiffDuration||d1<=d2-iDiffDuration)continue;

/*如果发现新的更接近通话目标时间的话单则从新的话单*/
		if(iCurDiff<0) iCurDiff=-iCurDiff;
		
		if(iCurDiff<iLastDiff){
			iLastDiff=iCurDiff;
			*ppCur=pTemp;
		}
	}
	if(*ppCur!=NULL) return FOUND;
	return NOTFOUND;	
}
void ModifyPrepTicket(struct PrepTicketStruct *p)
{
	strcpy(p->sServiceType,"001");
}
int InsertPrepTicketGWSame(struct PrepTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct PrepTicketStructOut TempOut;
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct PrepTicketStructOut));
		strcpy(TempOut.sTableName,"PREP_TICKET_GW_SAME");
	}
	return EInsertStructToPrepTicket(p,iInsertFlag,&TempOut);
	
}
int InsertPrepTicketGWDiff(struct PrepTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct PrepTicketStructOut TempOut;
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct PrepTicketStructOut));
		strcpy(TempOut.sTableName,"PREP_TICKET_GW_DIFF");
	}
	return EInsertStructToPrepTicket(p,iInsertFlag,&TempOut);
}

int InsertPrepTicketDJSame(struct PrepTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct PrepTicketStructOut TempOut;
	
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct PrepTicketStructOut));
		strcpy(TempOut.sTableName,"PREP_TICKET_DJ_SAME");
	}
	return EInsertStructToPrepTicket(p,iInsertFlag,&TempOut);
}
int InsertPrepTicketDJDiff(struct PrepTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct PrepTicketStructOut TempOut;
	
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct PrepTicketStructOut));
		strcpy(TempOut.sTableName,"PREP_TICKET_DJ_DIFF");
	}
	return EInsertStructToPrepTicket(p,iInsertFlag,&TempOut);
}

int node_output_prep_ticket_e(void **ppHead)
{
	
	struct PrepTicketStruct *ptHead=(*ppHead),*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iTCount++;
		
		if(strcmp(pTemp->sServiceType,"001")==0){
			if(InsertPrepTicketGWSame(pTemp,FALSE)<0)
				return -1;
			iTSameCnt++;
		}
		else{
			if(InsertPrepTicketGWDiff(pTemp,FALSE)<0)
				return -1;
			iTDiffCnt++;
		}
	}
	if(iTCount%10000==0){
		if(InsertPrepTicketGWSame(NULL,TRUE)<0)
			return -1;
		if(InsertPrepTicketGWDiff(NULL,TRUE)<0)
			return -1;
		printf("当前输出关口局话单数目%d,%d,%d.\n",
			iTCount,iTSameCnt,iTDiffCnt);
		WriteProcMsg("当前输出关口局话单数目%d,%d,%d",
			iTCount,iTSameCnt,iTDiffCnt);
		CommitWork();
	}
	return 0;
}

/*批量数据结构缓冲加载数据二叉树查找*/
int main(int argc,char *argv[])
{
	int iRet,iOffset;
	char sStartTime[15],sKeyStr[10];
	static int iCount=0,iSameCnt=0,iDiffCnt=0,iDiffTime=0;
        
        struct TimeOffsetStruct *pTime;
        BINTREE *pGateWayBin=NULL;
        struct PrepTicketStruct Temp;
        struct PrepTicketStructIn TempIn;
        struct PrepTicketStruct *pTemp;

	if(argc!=3&&argc!=2){
		printf("用法:%s difftime [user/pass]\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);
	
	if(argc==3)
		FastConnect(argv[2]);
	else
		IniConnect("dataconnstr");

	iDiffTime=atoi(argv[1]);
	if(iDiffTime<60)iDiffTime=60;

        if(MountPrepTicketToBin(&pGateWayBin,"PREP_TICKET_GW")<0) exit(1);
        
        
        bzero((void*)&TempIn,sizeof(struct PrepTicketStructIn));
        strcpy(TempIn.sTableName,"PREP_TICKET_DJ");
        strcpy(TempIn.sCondition,"");
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetPrepTicketToStruct(&Temp,&TempIn)){
        


		iCount++;

		pTime=GetTimeOffset(&Temp);
		strcpy(sStartTime,Temp.sStartTime);
		AddTimes(sStartTime,pTime->iOffset);

/*UNICOM_TICKET.MSRN=TELECOM_TICKET.OCALLED_NBR关联*/
/*为SAME表制造关联字段*/
		strcpy(Temp.sMsrn,"");
		
		iRet=SearchPrepTicketBin(pGateWayBin,&Temp,
			sStartTime,iDiffTime,60,&pTemp);
		
		if(iRet==FOUND){
			
			iOffset=tGetTime(pTemp->sStartTime)-tGetTime(Temp.sStartTime);
			pTime->iOffsetTotal+=iOffset;
			pTime->iCnt++;
			pTime->iOffset=pTime->iOffsetTotal/pTime->iCnt;
			
			iSameCnt++;
			ModifyPrepTicket(pTemp);
/*为SAME表制造关联字段*/
			sprintf(sKeyStr,"%09d",iSameCnt);
			strcpy(pTemp->sMsrn,sKeyStr);
			strcpy(Temp.sMsrn,sKeyStr);

			if(InsertPrepTicketDJSame(&Temp,FALSE)<0){
				WriteAlertMsg("insert same error.\n");
				return -1;
			}
		}
		else{
			iDiffCnt++;

			if(InsertPrepTicketDJDiff(&Temp,FALSE)<0){
				WriteAlertMsg("insert diff error.\n");
				return -1;
			}
		}
		
/*			printf("当前输出端局话单数目%d.\n",iCount);*/
		if(iCount%10000==0){
			if(InsertPrepTicketDJSame(NULL,TRUE)<0){
				WriteAlertMsg("insert same error.\n");
				return -1;
			}
			if(InsertPrepTicketDJDiff(NULL,TRUE)<0){
				WriteAlertMsg("insert diff error.\n");
				return -1;
			}
			printf("当前输出端局话单数%d,%d,%d.\n",
				iCount,iSameCnt,iDiffCnt);
			WriteProcMsg("当前输出端局话单数%d,%d,%d",
				iCount,iSameCnt,iDiffCnt);
			CommitWork();
		}
        }
        
		if(InsertPrepTicketDJSame(NULL,TRUE)<0){
			WriteAlertMsg("insert same error.\n");
			return -1;
		}
		if(InsertPrepTicketDJDiff(NULL,TRUE)<0){
			WriteAlertMsg("insert diff error.\n");
			return -1;
		}
	printf("当前输出端局话单数%d,%d,%d.\n",
		iCount,iSameCnt,iDiffCnt);
		
	WriteProcMsg("当前输出端局话单数%d,%d,%d",
		iCount,iSameCnt,iDiffCnt);
		CommitWork();
        TravelBin(pGateWayBin,node_output_prep_ticket_e);
        
		if(InsertPrepTicketGWSame(NULL,TRUE)<0){
			WriteAlertMsg("insert same error.\n");
			return -1;
		}
		if(InsertPrepTicketGWDiff(NULL,TRUE)<0){
			WriteAlertMsg("insert diff error.\n");
			return -1;
		}
		printf("当前输出关口局话单数目%d,%d,%d.\n",
			iTCount,iTSameCnt,iTDiffCnt);
		WriteProcMsg("当前输出关口局话单数目%d,%d,%d.\n",
			iTCount,iTSameCnt,iTDiffCnt);
			CommitWork();

        DisconnectDatabase();

	return 0;
}

