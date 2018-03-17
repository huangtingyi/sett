/*---------函数实现代码 unicom_ticket.pc----------*/

#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>
#include <hnixs.h>
#include <stt_ticket.h>

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
int data_search_bintree_telecom_ticket_e(void *pValue,void *pData)
{
        struct TelecomTicketStruct *pSource=(struct TelecomTicketStruct *)pValue;
        struct TelecomTicketStruct *pTarget=(struct TelecomTicketStruct *)pData;

/*数据比较部分*/
	return strcmp(pSource->sOCallingNbr,pTarget->sOCallingNbr);
}
int key_comp_telecom_ticket_e(LIST *pValue,LIST *pData)
{
        struct TelecomTicketStruct *pSource=(struct TelecomTicketStruct *)pValue;
        struct TelecomTicketStruct *pTarget=(struct TelecomTicketStruct *)pData;
        
	int res=0;
        if((res=strcmp(pSource->sStartTime,pTarget->sStartTime))!=0) return res;
        if((res=(pSource->iDuration-pTarget->iDuration))!=0) return res;

        return res;
        
}
void assign_insert_bintree_telecom_ticket_e(void **pptHead,void *pData)
{
        InsertListSort((LIST**)pptHead,(LIST*)pData,
        	key_comp_telecom_ticket_e);
}

/*批量数据结构缓冲加载数据二叉树查找*/
int MountTelecomTicketToBin(BINTREE **pptHead,char sTableName[])
{
	int iCount=0;
       	BINTREE *ptHead=NULL; 
       
        struct TelecomTicketStruct *pTemp;
        struct TelecomTicketStruct Temp;
        struct TelecomTicketStructIn TempIn;

        bzero((void*)&TempIn,sizeof(struct TelecomTicketStructIn));
        if(strlen(sTableName)!=0){
                strcpy(TempIn.sTableName,sTableName);
                strcpy(TempIn.sCondition,"");
        }
        else{
                strcpy(TempIn.sTableName,"TELECOM_TICKET");
                strcpy(TempIn.sCondition,"");
        }
        
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetTelecomTicketToStruct(&Temp,&TempIn)){
        	
		/*设置初始状态*/
		Temp.sState[0]=STATE_NOTFOUND;
/*为SAME表制造关联字段*/
		Temp.tStartTime=tGetTime(Temp.sStartTime);
		strcpy(Temp.sOCalledNbr,"");
		
		if(strcmp(Temp.sCallingNbr,Temp.sOCallingNbr)==0){
			if(strncmp(Temp.sCallingNbr,"179",3)!=0&&
				strncmp(Temp.sCallingNbr,"200",3)!=0&&
				strncmp(Temp.sCallingNbr,"800",3)!=0&&
				strlen(Temp.sCallingNbr)<8){
		strcpy(Temp.sOCallingNbr,Temp.sCallingAreaCode);
		strcat(Temp.sOCallingNbr,Temp.sCallingNbr);
			}
		}
                if((pTemp=(struct TelecomTicketStruct *)
                	malloc(sizeof(struct TelecomTicketStruct)))==NULL){
                        printf("error Malloc TelecomTicketStruct.\n");
                        return -1;
                }

                memcpy(pTemp,(void *)&Temp,sizeof(struct TelecomTicketStruct));
	
                InsertBin(&ptHead,pTemp,data_search_bintree_telecom_ticket_e,
                        assign_insert_bintree_telecom_ticket_e);
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
struct TimeOffsetStruct *GetTimeOffset(struct SttTicketStruct *p)
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
/*		pTemp->iOffsetTotal=1800;
		pTemp->iCnt=1;
		pTemp->iOffset=1800;
*/
		InsertList((LIST**)&ptHead,(LIST*)pTemp);		
	}
	return pTemp;
}
int SearchTelecomBin(BINTREE *pRoot,struct SttTicketStruct *p,
	char sStartTime[],int iDiffTime,int iDiffDuration,
	struct TelecomTicketStruct **ppCur)
{
	int	iLastDiff=iDiffTime,iCurDiff;
	time_t	tStartTime=tGetTime(sStartTime);
	struct TelecomTicketStruct *ptHead=NULL,*pTemp;
	static struct TelecomTicketStruct Temp;

	*ppCur=NULL;


	strcpy(Temp.sOCallingNbr,p->sMsisdn);

	if(SearchBin(pRoot,&Temp,
		data_search_bintree_telecom_ticket_e,
		(void **)&ptHead)==NOTFOUND) return NOTFOUND;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

/*通话时间不在时间范围内的话单则继续或者退出*/
		iCurDiff=pTemp->tStartTime-tStartTime;
			
		if(iCurDiff>=iDiffTime) break;
		if(iCurDiff<=-iDiffTime) continue;
/*通话时间在时间范围内,但是时长不匹配则不是*/
		if(p->iDuration>=pTemp->iDuration+iDiffDuration||
			p->iDuration<=pTemp->iDuration-iDiffDuration)continue;
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
void ModifyTelecomTicket(struct TelecomTicketStruct *p)
{
	p->sState[0]=STATE_FOUND;
}
int InsertTelecomTicketSame(struct TelecomTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct TelecomTicketStructOut TempOut;
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct TelecomTicketStructOut));
		strcpy(TempOut.sTableName,"TELECOM_TICKET_SAME");
	}
	return EInsertStructToTelecomTicket(p,iInsertFlag,&TempOut);
	
}
int InsertTelecomTicketDiff(struct TelecomTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct TelecomTicketStructOut TempOut;
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct TelecomTicketStructOut));
		strcpy(TempOut.sTableName,"TELECOM_TICKET_DIFF");
	}
	return EInsertStructToTelecomTicket(p,iInsertFlag,&TempOut);
}

int InsertSttTicketSame(struct SttTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct SttTicketStructOut TempOut;
	
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct SttTicketStructOut));
		strcpy(TempOut.sTableName,"UNICOM_TICKET_SAME");
	}
	return EInsertStructToSttTicket(p,iInsertFlag,&TempOut);
}
int InsertSttTicketDiff(struct SttTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct SttTicketStructOut TempOut;
	
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct SttTicketStructOut));
		strcpy(TempOut.sTableName,"UNICOM_TICKET_DIFF");
	}
	return EInsertStructToSttTicket(p,iInsertFlag,&TempOut);
}

int node_output_telecom_ticket_e(void **ppHead)
{
	
	struct TelecomTicketStruct *ptHead=(*ppHead),*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iTCount++;
		
		if(pTemp->sState[0]==STATE_FOUND){
			if(InsertTelecomTicketSame(pTemp,FALSE)<0)
				return -1;
			iTSameCnt++;
		}
		else{
			if(InsertTelecomTicketDiff(pTemp,FALSE)<0)
				return -1;
			iTDiffCnt++;
		}
	}
	if(iTCount%10000==0){
		if(InsertTelecomTicketSame(NULL,TRUE)<0)
			return -1;
		if(InsertTelecomTicketDiff(NULL,TRUE)<0)
			return -1;
		printf("当前输出电信话单数目%d,%d,%d.\n",
			iTCount,iTSameCnt,iTDiffCnt);
		WriteProcMsg("当前输出电信话单数目%d,%d,%d",
			iTCount,iTSameCnt,iTDiffCnt);
		CommitWork();
	}
	return 0;
}

/*批量数据结构缓冲加载数据二叉树查找*/
int main(int argc,char *argv[])
{
	int iRet,iOffset;
	char sTemp[25],sStartTime[15],sKeyStr[10];
	static int iCount=0,iSameCnt=0,iDiffCnt=0,iDiffTime=0;
        
        struct TimeOffsetStruct *pTime;
        BINTREE *pTeleBin=NULL;
        struct SttTicketStruct Temp;
        struct SttTicketStructIn TempIn;
        struct TelecomTicketStruct *pTemp;
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

        if(MountTelecomTicketToBin(&pTeleBin,"")<0)     exit(1);
        
        bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));
        strcpy(TempIn.sTableName,"UNICOM_TICKET");
        strcpy(TempIn.sCondition,"");
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

        while(EGetSttTicketToStruct(&Temp,&TempIn)){
        
		iCount++;
/*			printf("ii当前输出联通话单数目%d.\n",iCount);*/

		strcpy(sTemp,Temp.sMsisdn);	

		if(strlen(Temp.sMsisdn)==7&&Temp.sMsisdn[0]!='1'){
			strcpy(Temp.sMsisdn,Temp.sHomeAreaCode);
			strcat(Temp.sMsisdn,sTemp);
		}
		if(strncmp(Temp.sMsisdn,"0",1)==0)
			strcpy(Temp.sMsisdn,Temp.sMsisdn+1);

		pTime=GetTimeOffset(&Temp);
		strcpy(sStartTime,Temp.sStartTime);
		AddTimes(sStartTime,pTime->iOffset);

/*UNICOM_TICKET.MSRN=TELECOM_TICKET.OCALLED_NBR关联*/
/*为SAME表制造关联字段*/
		strcpy(Temp.sMsrn,"");
		
		iRet=SearchTelecomBin(pTeleBin,&Temp,
			sStartTime,iDiffTime,3,&pTemp);
		
		if(iRet==FOUND){
			
			iOffset=tGetTime(pTemp->sStartTime)-tGetTime(Temp.sStartTime);
			pTime->iOffsetTotal+=iOffset;
			pTime->iCnt++;
			pTime->iOffset=pTime->iOffsetTotal/pTime->iCnt;
			
			iSameCnt++;
			ModifyTelecomTicket(pTemp);
/*为SAME表制造关联字段*/
			sprintf(sKeyStr,"%09d",iSameCnt);
			strcpy(pTemp->sOCalledNbr,sKeyStr);
			strcpy(Temp.sMsrn,sKeyStr);

			strcpy(Temp.sMsisdn,sTemp);
			if(InsertSttTicketSame(&Temp,FALSE)<0){
				WriteAlertMsg("insert same error.\n");
				return -1;
			}
		}
		else{
			iDiffCnt++;

			strcpy(Temp.sMsisdn,sTemp);
			if(InsertSttTicketDiff(&Temp,FALSE)<0){
				WriteAlertMsg("insert diff error.\n");
				return -1;
			}
		}
		
/*			printf("当前输出联通话单数目%d.\n",iCount);*/
		if(iCount%10000==0){
			if(InsertSttTicketSame(NULL,TRUE)<0){
				WriteAlertMsg("insert same error.\n");
				return -1;
			}
			if(InsertSttTicketDiff(NULL,TRUE)<0){
				WriteAlertMsg("insert diff error.\n");
				return -1;
			}
			printf("当前输出联通话单数%d,%d,%d.\n",
				iCount,iSameCnt,iDiffCnt);
			WriteProcMsg("当前输出联通话单数%d,%d,%d",
				iCount,iSameCnt,iDiffCnt);
			CommitWork();
		}
        }
        
		if(InsertSttTicketSame(NULL,TRUE)<0){
			WriteAlertMsg("insert same error.\n");
			return -1;
		}
		if(InsertSttTicketDiff(NULL,TRUE)<0){
			WriteAlertMsg("insert diff error.\n");
			return -1;
		}
	printf("当前输出联通话单数%d,%d,%d.\n",
		iCount,iSameCnt,iDiffCnt);
		
	WriteProcMsg("当前输出联通话单数%d,%d,%d",
		iCount,iSameCnt,iDiffCnt);
		CommitWork();
        TravelBin(pTeleBin,node_output_telecom_ticket_e);
        
		if(InsertTelecomTicketSame(NULL,TRUE)<0){
			WriteAlertMsg("insert same error.\n");
			return -1;
		}
		if(InsertTelecomTicketDiff(NULL,TRUE)<0){
			WriteAlertMsg("insert diff error.\n");
			return -1;
		}
		printf("当前输出电信话单数目%d,%d,%d.\n",
			iTCount,iTSameCnt,iTDiffCnt);
		WriteProcMsg("当前输出电信话单数目%d,%d,%d.\n",
			iTCount,iTSameCnt,iTDiffCnt);
			CommitWork();

        DisconnectDatabase();

	return 0;
}

