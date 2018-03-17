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

static int iTCount=0,iTSameCnt=0,iTDiffCnt=0;
BINTREE *pBillBin=NULL,*pErrBin=NULL;
struct PrepTicketStruct *pErrList=NULL;

#define STATE_FOUND		'1'
#define STATE_NOTFOUND		'0'

/**
001	MSISDN找不到
002	OTHER_PARTY找不到
003	THIRD_PARTY找不到
004	OTHER_PARTY+MSISDN都找不到
005	OTHER_PARTY+THIRD_PARTY找不到
**/

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
int key_comp_prep_ticket_ee(LIST *pValue,LIST *pData)
{
        struct PrepTicketStruct *pSource=(struct PrepTicketStruct *)pValue;
        struct PrepTicketStruct *pTarget=(struct PrepTicketStruct *)pData;
        
	int res=0;
        if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
        if((res=strcmp(pSource->sStartTime,pTarget->sStartTime))!=0) return res;
        
        return atoi(pSource->sDuration)-atoi(pTarget->sDuration);
        
        
}
void assign_insert_bintree_prep_ticket_ee(void **pptHead,void *pData)
{
        InsertListSort((LIST**)pptHead,(LIST*)pData,
        	key_comp_prep_ticket_ee);
}

int ProvinceLocalUser(char sMsisdn[],char sStartTime[])
{
	struct T130AreaCodeStruct *pTemp=NULL;
	struct AreaCodeDescStruct *ptCur=NULL;
	struct HeadCarrStruct	*pHeadCarr=NULL;

	if(SearchHeadCarr(sMsisdn,
		"*",sStartTime,&pHeadCarr)==NOTFOUND) return false;

	if(pHeadCarr->iSettCarrierID!=3) return false;
	
	if(SearchT130AreaCode(sMsisdn,sStartTime,&pTemp)==NOTFOUND)
		return false;
	if(SearchAreaCodeDesc(pTemp->sAreaCode,&ptCur)==NOTFOUND)
		return false;
		
	if(ptCur->sType[0]=='2'||ptCur->sType[0]=='1') return true;

	return false;
	
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

        	/*只需要主被叫呼转话单*/
		if(strcmp(Temp.sCallType,"01")!=0&&
			strcmp(Temp.sCallType,"02")!=0&&
			strcmp(Temp.sCallType,"03")!=0) continue;
		
		/*非省内的用户就不检查了*/
		if(ProvinceLocalUser(Temp.sMsisdn,Temp.sStartTime)==false)
			continue;

		
		if((pTemp=malloc(sizeof(struct PrepTicketStruct)))==NULL) return -1;
                memcpy(pTemp,(void *)&Temp,sizeof(struct PrepTicketStruct));
	
                InsertBin(&ptHead,pTemp,data_search_bintree_prep_ticket_e,
                        assign_insert_bintree_prep_ticket_e);
		if(++iCount%10000==0) 
			printf("加载话单表PREP_TICKET %d 条.\n",iCount);

        }

        *pptHead=ptHead;
	printf("完毕，共加载话单表PREP_TICKET %d 条.\n",iCount);
        
        return 0;
}


int SearchPrepTicketBin(BINTREE *pRoot,struct PrepTicketStruct *p,
	char sMsisdn[],int iDiffTime,int iDiffDuration)
{
	struct PrepTicketStruct *ptCur=NULL;
	int	iLastDiff=iDiffTime,iCurDiff,d1,d2;
	time_t	tStartTime=tGetTime(p->sStartTime),tTempTime;
	struct PrepTicketStruct *ptHead=NULL,*pTemp;

	static struct PrepTicketStruct Temp;


	strcpy(Temp.sMsisdn,sMsisdn);

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
			ptCur=pTemp;
		}
	}
	if(ptCur!=NULL) return FOUND;
	return NOTFOUND;	
}
int InsertPrepTicketErr(struct PrepTicketStruct *p,int iInsertFlag)
{
	static int iFirstFlag=TRUE;
	static struct PrepTicketStructOut TempOut;
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct PrepTicketStructOut));
		strcpy(TempOut.sTableName,"PREP_TICKET_ERR");
	}
	return EInsertStructToPrepTicket(p,iInsertFlag,&TempOut);
}
int node_errlist_prep_ticket_e(void **ppHead)
{
	struct PrepTicketStruct *ptPre,*ptCur;
	ptCur=(*ppHead);
	
	while(ptCur!=NULL){

		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		InsertList((LIST**)&pErrList,(LIST*)ptPre);
	}
	return 0;
}
int node_combin_prep_ticket_e(void **ppHead)
{
	struct PrepTicketStruct *ptPre,*ptCur,*pTemp;
	
	ptCur=(*ppHead);
	
	while(ptCur!=NULL){

		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		while(ptCur!=NULL){
			
			/*呼叫类型不一致的不合并*/
			if(strcmp(ptPre->sCallType,ptCur->sCallType)!=0)
				break;
			/*通话时间＋时长不连续的不合并*/
			if(tGetTime(ptPre->sStartTime)+atoi(ptPre->sDuration)
				<tGetTime(ptCur->sStartTime))	break;
			
			sprintf(ptPre->sDuration,"%06d",
				atoi(ptPre->sDuration)+atoi(ptCur->sDuration));
		
			pTemp=ptCur;
			ptCur=ptCur->pNext;
			ptPre->pNext=ptCur;
			free(pTemp);
		}
	}
	return 0;
}
int node_output_prep_ticket_e(void **ppHead)
{
	
	struct PrepTicketStruct *ptHead=(*ppHead),*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iTCount++;
	
		if(InsertPrepTicketErr(pTemp,FALSE)<0)	return -1;

	}
	if(iTCount%10000==0){
		if(InsertPrepTicketErr(NULL,TRUE)<0)
			return -1;
		printf("当前输出关口局话单数目%d,%d,%d.\n",
			iTCount,iTSameCnt,iTDiffCnt);
		WriteProcMsg("当前输出关口局话单数目%d,%d,%d",
			iTCount,iTSameCnt,iTDiffCnt);
		CommitWork();
	}
	return 0;
}
int CorrectPrepTicketBill(struct PrepTicketStruct *p,int iDiffTime)
{
	strcpy(p->sServiceType,"000");
	
	if(strcmp(p->sCallType,"01")==0||
		strcmp(p->sCallType,"02")==0){
		
		if(ProvinceLocalUser(p->sOtherParty,p->sStartTime)==true){
		
			if(SearchPrepTicketBin(pBillBin,p,p->sOtherParty,
				iDiffTime,3)==NOTFOUND)
				strcpy(p->sServiceType,"002");
		}
	}
	else if(strcmp(p->sCallType,"03")==0){
		if(ProvinceLocalUser(p->sOtherParty,p->sStartTime)==true){
		
			if(SearchPrepTicketBin(pBillBin,p,
				p->sOtherParty,iDiffTime,3)==NOTFOUND)
				strcpy(p->sServiceType,"002");
		}
		if(ProvinceLocalUser(p->sThirdParty,p->sStartTime)==true){
		
			if(SearchPrepTicketBin(pBillBin,p,
				p->sThirdParty,iDiffTime,3)==NOTFOUND){
				if(strcmp(p->sServiceType,"000")==0)
					strcpy(p->sServiceType,"003");
				else
					strcpy(p->sServiceType,"005");
			}
		}
	}
	else{
		if(ProvinceLocalUser(p->sOtherParty,p->sStartTime)==true){
		
			if(SearchPrepTicketBin(pBillBin,p,
				p->sOtherParty,iDiffTime,3)==NOTFOUND)
				strcpy(p->sServiceType,"001");
		}
		if(ProvinceLocalUser(p->sMsisdn,p->sStartTime)==true){
		
			if(SearchPrepTicketBin(pBillBin,p,
				p->sMsisdn,iDiffTime,3)==NOTFOUND){
				if(strcmp(p->sServiceType,"000")==0)
					strcpy(p->sServiceType,"003");
				else
					strcpy(p->sServiceType,"004");
			}
		}
	}
	if(strcmp(p->sServiceType,"000")==0) return true;
	return false;
}

/*批量数据结构缓冲加载数据二叉树查找*/
int main(int argc,char *argv[])
{
	static int iCount=0,iSameCnt=0,iDiffCnt=0,iDiffTime=0;
        struct PrepTicketStruct Temp;
        struct PrepTicketStructIn TempIn;
        struct PrepTicketStruct *pTemp,*ptHead;

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

/*将话单加载到平衡二叉树中*/
        if(MountPrepTicketToBin(&pBillBin,"PREP_TICKET_BILL")<0) exit(1);
/*对待比对的话单进行时长的合并*/
        TravelBin(pBillBin,node_combin_prep_ticket_e);
        
        bzero((void*)&TempIn,sizeof(struct PrepTicketStructIn));
        strcpy(TempIn.sTableName,"PREP_TICKET_ALL");
        strcpy(TempIn.sCondition,"");
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;


        while(EGetPrepTicketToStruct(&Temp,&TempIn)){
        
		iCount++;
		
		if(CorrectPrepTicketBill(&Temp,iDiffTime)==true){
			iSameCnt++;			
			continue;
		}
		
		iDiffCnt++;
		
		if((pTemp=malloc(sizeof(struct PrepTicketStruct)))==NULL)
			return -1;
                memcpy(pTemp,(void *)&Temp,sizeof(struct PrepTicketStruct));
	
                InsertBin(&pErrBin,pTemp,data_search_bintree_prep_ticket_e,
                        assign_insert_bintree_prep_ticket_ee);
                        
		if(iCount%10000==0)
			printf("比对话单数%d, 相同%d, 不相同%d.\n",
				iCount,iSameCnt,iDiffCnt);
        }
        
	printf("一次比对结束，比对话单数%d, 相同%d, 不相同%d.\n",
		iCount,iSameCnt,iDiffCnt);

/*对待比对的话单进行时长的合并*/
        TravelBin(pErrBin,node_combin_prep_ticket_e);
        
/*将话单放到pErrList链表中*/
	pErrList=NULL;
        TravelBin(pErrBin,node_errlist_prep_ticket_e);
/*将平衡二叉树释放*/
        DestroyBin(pErrBin);

        iCount=iSameCnt=iDiffCnt=0;
        
        ptHead=pErrList;
        
        while(ptHead!=NULL){
        
        	pTemp=ptHead;
        	ptHead=ptHead->pNext;
        	
        	iCount++;

		if(CorrectPrepTicketBill(pTemp,iDiffTime)==true){
			iSameCnt++;			
			continue;
		}
		iDiffCnt++;
		
		if(InsertPrepTicketErr(pTemp,FALSE)<0){
			WriteAlertMsg("insert diff error.\n");
			return -1;
		}
		if(iCount%10000==0){
			if(InsertPrepTicketErr(NULL,TRUE)<0){
				WriteAlertMsg("insert same error.\n");
				return -1;
			}
			CommitWork();
			printf("比对话单数%d, 相同%d, 不相同%d.\n",
				iCount,iSameCnt,iDiffCnt);
		}
        }
	if(InsertPrepTicketErr(NULL,TRUE)<0){
		WriteAlertMsg("insert same error.\n");
		return -1;
	}
	printf("二次比对结束，比对话单数%d, 相同%d, 不相同%d.\n",
		iCount,iSameCnt,iDiffCnt);

	CommitWork();
        
/*将给释放的内存释放了*/
        DestroyList((LIST*)pErrList);
	pErrList=NULL;
        TravelBin(pBillBin,node_errlist_prep_ticket_e);
        DestroyBin(pBillBin);
        DestroyList((LIST*)pErrList);
	pErrList=NULL;
        
        DisconnectDatabase();

	return 0;
}

