/*---------函数实现代码 unicom_ticket.pc----------*/

#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>

#include <other_supp.h>
#include <ticket_field.h>

void RegularNbr(char sAccNbr[],char sAreaCode[],char sStartTime[])
{
	char sTempNbr[40];
	
	strcpy(sTempNbr,sAccNbr);
	GetRawNbr(sTempNbr,sAreaCode,sStartTime,sAccNbr);
}
int data_search_bintree_chk_stt_ticket_e(void *pValue,void *pData)
{
        struct ChkSttTicketStruct *pSource=(struct ChkSttTicketStruct *)pValue;
        struct ChkSttTicketStruct *pTarget=(struct ChkSttTicketStruct *)pData;

/*数据比较部分*/
	return strcmp(pSource->sMsisdn,pTarget->sMsisdn);
}
int key_comp_chk_stt_ticket_e(LIST *pValue,LIST *pData)
{
        struct ChkSttTicketStruct *pSource=(struct ChkSttTicketStruct *)pValue;
        struct ChkSttTicketStruct *pTarget=(struct ChkSttTicketStruct *)pData;
        
	int res=0;
        if((res=strcmp(pSource->sStartTime,pTarget->sStartTime))!=0) return res;
        
        return pSource->iDuration-pTarget->iDuration;
        
        
}
void assign_insert_bintree_chk_stt_ticket_e(void **pptHead,void *pData)
{
        InsertListSort((LIST**)pptHead,(LIST*)pData,
        	key_comp_chk_stt_ticket_e);
}
/*批量数据结构缓冲加载数据二叉树查找*/
int MountChkSttTicketToBin(BINTREE **pptHead,char sTableName[],char sAreaCode[])
{
	int iCount=0;
       	BINTREE *ptHead=NULL; 
       
        struct ChkSttTicketStruct *pTemp;
        struct ChkSttTicketStruct Temp;
        struct ChkSttTicketStructIn TempIn;

        bzero((void*)&TempIn,sizeof(struct ChkSttTicketStructIn));

	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,"");
	
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetChkSttTicketToStruct(&Temp,&TempIn)){
		
/*为SAME表制造关联字段*/
		strcpy(Temp.sType,"0");
		strcpy(Temp.sSerialNbr,"");
		
		RegularNbr(Temp.sMsisdn,sAreaCode,Temp.sStartTime);
		
		if((pTemp=malloc(sizeof(struct ChkSttTicketStruct)))==NULL) return -1;
                memcpy(pTemp,(void *)&Temp,sizeof(struct ChkSttTicketStruct));
	
                if(InsertBin(&ptHead,pTemp,
                	data_search_bintree_chk_stt_ticket_e,
                        assign_insert_bintree_chk_stt_ticket_e)<0){
                        printf("分配内存到BINTREE失败.\n");
                        return -1;
		}
		if(++iCount%10000==0) 
			printf("加载话单表%s %d 条.\n",sTableName,iCount);

        }

        *pptHead=ptHead;
	printf("加载话单表%s %d 条.\n",sTableName,iCount);
        
        return 0;
}
int SearchChkSttTicketBin(BINTREE *pRoot,struct ChkSttTicketStruct *p,
	int iTimeDiff,int iDuraDiff,struct ChkSttTicketStruct **ppCur)
{
	int	iLastDiff=iTimeDiff,iCurDiff,d1,d2;
	time_t	tStartTime=tGetTime(p->sStartTime),tTempTime;
	struct ChkSttTicketStruct *ptHead=NULL,*pTemp;
	struct ChkSttTicketStruct Temp;

	*ppCur=NULL;

	strcpy(Temp.sMsisdn,p->sMsisdn);

	if(SearchBin(pRoot,&Temp,
		data_search_bintree_chk_stt_ticket_e,
		(void **)&ptHead)==NOTFOUND) return NOTFOUND;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

/*通话时间不在时间范围内的话单则继续或者退出*/
		tTempTime=tGetTime(pTemp->sStartTime);
		
		iCurDiff=tTempTime-tStartTime;
			
		if(iCurDiff>=iTimeDiff) break;
		if(iCurDiff<=-iTimeDiff) continue;

/*通话时间在时间范围内,但是时长不匹配则不是*/
		d1=p->iDuration;
		d2=pTemp->iDuration;
		
		if(d1>=d2+iDuraDiff||d1<=d2-iDuraDiff)continue;

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

struct ChkSttTicketStruct *pOppDiffList=NULL;

int node_output_chk_stt_ticket_e(void **ppHead)
{
	
	struct ChkSttTicketStruct *ptHead=(*ppHead),*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->sType,"1")==0){
			free(pTemp);
			continue;
		}
		
		InsertList((LIST**)&pOppDiffList,(LIST*)pTemp);
	}
	return 0;
}
/*批量数据结构缓冲加载数据二叉树查找*/
int main(int argc,char *argv[])
{

	BINTREE *pMyRoot=NULL;

	int iTimeDiff,iDuraDiff,iCnt=0,iCnt1=0,iCnt2=0,iRet;
	char sMyTab[31],sOppTab[31],sResTab[31],sAreaCode[10];
        struct ChkSttTicketStructIn TempIn;
        struct ChkSttTicketStructUp TempOppUp,TempMyUp;
        struct ChkSttTicketStructOut TempOut;
        
        struct ChkSttTicketStruct *pTemp,*ptHead,Temp;


	if(argc!=7){
		printf("用法:%s mytab opptab restab timediff duradiff areacode\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	strcpy(sMyTab,	argv[1]);
	strcpy(sOppTab,	argv[2]);
	strcpy(sResTab,	argv[3]);
	iTimeDiff=	atoi(argv[4]);
	iDuraDiff=	atoi(argv[5]);
	
	if(iTimeDiff<60)iTimeDiff=60;
	if(iDuraDiff>3) iDuraDiff=3;
	
	strcpy(sAreaCode,argv[6]);
	
	if(ConnectDataDB()<0){
		printf("连接数据库错误.\n");
		return -1;
	}
	
        if(MountChkSttTicketToBin(&pMyRoot,sMyTab,sAreaCode)<0){
        	printf("加载数据错误.\n");
        	return -1;
        }
        
/*初始化UP表和OUT表*/        
        bzero((void*)&TempMyUp,sizeof(struct ChkSttTicketStructUp));
        bzero((void*)&TempOppUp,sizeof(struct ChkSttTicketStructUp));
	bzero((void*)&TempOut,sizeof(struct ChkSttTicketStructOut));
	TempMyUp.iCurPos=TempOppUp.iCurPos=TempOut.iCurPos=0;
	
	strcpy(TempMyUp.sTableName,sMyTab);
	strcpy(TempOppUp.sTableName,sOppTab);
	strcpy(TempOut.sTableName,sResTab);
/*初始化收入缓冲*/
        bzero((void*)&TempIn,sizeof(struct ChkSttTicketStructIn));
        strcpy(TempIn.sTableName,sOppTab);
        strcpy(TempIn.sCondition,"");
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetChkSttTicketToStruct(&Temp,&TempIn)){
        
		iCnt++;

		strcpy(Temp.sType,"0");
		strcpy(Temp.sSerialNbr,"");
		RegularNbr(Temp.sMsisdn,sAreaCode,Temp.sStartTime);
		
		iRet=SearchChkSttTicketBin(pMyRoot,&Temp,iTimeDiff,iDuraDiff,&pTemp);
		
		if(iRet==FOUND){
		
			iCnt1++;
			strcpy(Temp.sType,"1");
			sprintf(Temp.sSerialNbr,"%09d",iCnt1);
			strcpy(pTemp->sType,"1");
			sprintf(pTemp->sSerialNbr,"%09d",iCnt1);
			
			if(EUpdateStructToChkSttTicket(&Temp,false,&TempOppUp)<0){
				WriteAlertPrint("更新%s表错误",sOppTab);
				return -1;
			}
			if(EUpdateStructToChkSttTicket(pTemp,false,&TempMyUp)<0){
				WriteAlertPrint("更新%s表错误.",sMyTab);
				return -1;
			}

		}
		else{
			iCnt2++;

			strcpy(Temp.sType,"1");
			if(EInsertStructToChkSttTicket(&Temp,false,&TempOut)<0){
				WriteAlertPrint("写入%s表错误",sResTab);
				return -1;
			}
		}
		
		if(iCnt%10000==0){
			
			if(EUpdateStructToChkSttTicket(NULL,true,&TempOppUp)<0){
				WriteAlertPrint("更新%s表错误",sOppTab);
				return -1;
			}
			if(EUpdateStructToChkSttTicket(NULL,true,&TempMyUp)<0){
				WriteAlertPrint("更新%s表错误.",sMyTab);
				return -1;
			}
			if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
				WriteAlertPrint("写入%s表错误",sResTab);
				return -1;
			}
			
			WriteProcPrint("当前处理话单数%d,更新数%d,差异%d",
				iCnt,iCnt1,iCnt2);
			CommitWork();
		}
        }


	if(EUpdateStructToChkSttTicket(NULL,true,&TempOppUp)<0){
		WriteAlertPrint("更新%s表错误",sOppTab);
		return -1;
	}
	if(EUpdateStructToChkSttTicket(NULL,true,&TempMyUp)<0){
		WriteAlertPrint("更新%s表错误.",sMyTab);
		return -1;
	}
	if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
		WriteAlertPrint("写入%s表错误",sResTab);
		return -1;
	}

/*	WriteProcPrint("当前处理话单数%d,更新数%d,差异%d",iCnt,iCnt1,iCnt2);*/
	CommitWork();
        
        TravelBin(pMyRoot,node_output_chk_stt_ticket_e);
        DestroyBin(pMyRoot);

        ptHead=pOppDiffList;
        
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		
		if(EInsertStructToChkSttTicket(pTemp,false,&TempOut)<0){
			WriteAlertPrint("写入%s表错误",sResTab);
			return -1;
		}
		
		free(pTemp);
		
		iCnt2++;
		
		if(iCnt2%10000==0){
			
			if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
				WriteAlertPrint("写入%s表错误",sResTab);
				return -1;
			}
			CommitWork();
			WriteProcPrint("当前输出话单数%d",iCnt);
		}
	}
	
	if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
		WriteAlertPrint("写入%s表错误",sResTab);
		return -1;
	}
	CommitWork();

	WriteProcPrint("完毕,当前处理话单数%d,更新数%d,差异%d",iCnt,iCnt1,iCnt2);
	
        DisconnectDatabase();

	return 0;
}

