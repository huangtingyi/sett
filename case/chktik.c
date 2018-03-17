/*---------����ʵ�ִ��� unicom_ticket.pc----------*/

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

/*���ݱȽϲ���*/
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
/*�������ݽṹ����������ݶ���������*/
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
		
/*ΪSAME����������ֶ�*/
		strcpy(Temp.sType,"0");
		strcpy(Temp.sSerialNbr,"");
		
		RegularNbr(Temp.sMsisdn,sAreaCode,Temp.sStartTime);
		
		if((pTemp=malloc(sizeof(struct ChkSttTicketStruct)))==NULL) return -1;
                memcpy(pTemp,(void *)&Temp,sizeof(struct ChkSttTicketStruct));
	
                if(InsertBin(&ptHead,pTemp,
                	data_search_bintree_chk_stt_ticket_e,
                        assign_insert_bintree_chk_stt_ticket_e)<0){
                        printf("�����ڴ浽BINTREEʧ��.\n");
                        return -1;
		}
		if(++iCount%10000==0) 
			printf("���ػ�����%s %d ��.\n",sTableName,iCount);

        }

        *pptHead=ptHead;
	printf("���ػ�����%s %d ��.\n",sTableName,iCount);
        
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

/*ͨ��ʱ�䲻��ʱ�䷶Χ�ڵĻ�������������˳�*/
		tTempTime=tGetTime(pTemp->sStartTime);
		
		iCurDiff=tTempTime-tStartTime;
			
		if(iCurDiff>=iTimeDiff) break;
		if(iCurDiff<=-iTimeDiff) continue;

/*ͨ��ʱ����ʱ�䷶Χ��,����ʱ����ƥ������*/
		d1=p->iDuration;
		d2=pTemp->iDuration;
		
		if(d1>=d2+iDuraDiff||d1<=d2-iDuraDiff)continue;

/*��������µĸ��ӽ�ͨ��Ŀ��ʱ��Ļ�������µĻ���*/
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
/*�������ݽṹ����������ݶ���������*/
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
		printf("�÷�:%s mytab opptab restab timediff duradiff areacode\n",argv[0]);
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
		printf("�������ݿ����.\n");
		return -1;
	}
	
        if(MountChkSttTicketToBin(&pMyRoot,sMyTab,sAreaCode)<0){
        	printf("�������ݴ���.\n");
        	return -1;
        }
        
/*��ʼ��UP���OUT��*/        
        bzero((void*)&TempMyUp,sizeof(struct ChkSttTicketStructUp));
        bzero((void*)&TempOppUp,sizeof(struct ChkSttTicketStructUp));
	bzero((void*)&TempOut,sizeof(struct ChkSttTicketStructOut));
	TempMyUp.iCurPos=TempOppUp.iCurPos=TempOut.iCurPos=0;
	
	strcpy(TempMyUp.sTableName,sMyTab);
	strcpy(TempOppUp.sTableName,sOppTab);
	strcpy(TempOut.sTableName,sResTab);
/*��ʼ�����뻺��*/
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
				WriteAlertPrint("����%s�����",sOppTab);
				return -1;
			}
			if(EUpdateStructToChkSttTicket(pTemp,false,&TempMyUp)<0){
				WriteAlertPrint("����%s�����.",sMyTab);
				return -1;
			}

		}
		else{
			iCnt2++;

			strcpy(Temp.sType,"1");
			if(EInsertStructToChkSttTicket(&Temp,false,&TempOut)<0){
				WriteAlertPrint("д��%s�����",sResTab);
				return -1;
			}
		}
		
		if(iCnt%10000==0){
			
			if(EUpdateStructToChkSttTicket(NULL,true,&TempOppUp)<0){
				WriteAlertPrint("����%s�����",sOppTab);
				return -1;
			}
			if(EUpdateStructToChkSttTicket(NULL,true,&TempMyUp)<0){
				WriteAlertPrint("����%s�����.",sMyTab);
				return -1;
			}
			if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
				WriteAlertPrint("д��%s�����",sResTab);
				return -1;
			}
			
			WriteProcPrint("��ǰ��������%d,������%d,����%d",
				iCnt,iCnt1,iCnt2);
			CommitWork();
		}
        }


	if(EUpdateStructToChkSttTicket(NULL,true,&TempOppUp)<0){
		WriteAlertPrint("����%s�����",sOppTab);
		return -1;
	}
	if(EUpdateStructToChkSttTicket(NULL,true,&TempMyUp)<0){
		WriteAlertPrint("����%s�����.",sMyTab);
		return -1;
	}
	if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
		WriteAlertPrint("д��%s�����",sResTab);
		return -1;
	}

/*	WriteProcPrint("��ǰ��������%d,������%d,����%d",iCnt,iCnt1,iCnt2);*/
	CommitWork();
        
        TravelBin(pMyRoot,node_output_chk_stt_ticket_e);
        DestroyBin(pMyRoot);

        ptHead=pOppDiffList;
        
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		
		if(EInsertStructToChkSttTicket(pTemp,false,&TempOut)<0){
			WriteAlertPrint("д��%s�����",sResTab);
			return -1;
		}
		
		free(pTemp);
		
		iCnt2++;
		
		if(iCnt2%10000==0){
			
			if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
				WriteAlertPrint("д��%s�����",sResTab);
				return -1;
			}
			CommitWork();
			WriteProcPrint("��ǰ���������%d",iCnt);
		}
	}
	
	if(EInsertStructToChkSttTicket(NULL,true,&TempOut)<0){
		WriteAlertPrint("д��%s�����",sResTab);
		return -1;
	}
	CommitWork();

	WriteProcPrint("���,��ǰ��������%d,������%d,����%d",iCnt,iCnt1,iCnt2);
	
        DisconnectDatabase();

	return 0;
}

