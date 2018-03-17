#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdb.h>
#include <bintree.h>
#include <dbsupp.h>
#include <stt_ticket.h>
#include <ticket.h>

char STABLETYPE[4];

int (*DealX)(char sSouTableName[],char sOutTableName[],char sCondition[],
	char sFileName[],char sFilter[],char sPath[]);
int (*ProcessRecord)(struct FileControlStruct **ppLkHead,
	struct SttTicketStruct **pptHead);
		
void mvitem_mfsms2sttticket(struct SmsTicketStruct *pi,
	struct FSttTicketStruct *po);
void mvitem_mfsmsp2sttticket(struct SmspTicketStruct *pi,
	struct FSttTicketStruct *po);
	
struct MyFileOutStruct
{
	struct MyFileOutStruct *pNext;
	char 	sSplitType[10];
	FILE *fp;
};

struct AccNbrStruct
{
	struct AccNbrStruct *pNext;
	char sAccNbr[16];
	char sFlag[2];
	char sCallType[3];
	int iCnt;
};

struct MyFileOutStruct *GetFileOut(struct FileControlStruct **pptHead,
	char sTargetName[],char sSplitType[]);

void CloseFileOut(struct FileControlStruct *ptHead)
{
	struct MyFileOutStruct *pTemp;

	while(ptHead!=NULL){
		pTemp=(struct MyFileOutStruct *)ptHead->pData;
		fclose(pTemp->fp);

		ptHead=ptHead->pNext;
	}

}

int item2fileout(struct FileControlStruct **ppHead,void *pData,int iLen,
	char sTargetName[],char sSplitType[])
{
	char sFileLine[8192];
	struct MyFileOutStruct *pTemp;

	if((pTemp=(struct MyFileOutStruct *)(GetFileOut(ppHead,sTargetName,sSplitType)))==NULL) return -1;

	memcpy((void*)sFileLine,pData,iLen);sFileLine[iLen]=0;

	if(fprintf(pTemp->fp,"%s\n",sFileLine)<0) return -1;

	return 0;
}

struct MyFileOutStruct *GetFileOut(struct FileControlStruct **pptHead,
	char sTargetName[],char sSplitType[])
{
	struct FileControlStruct *ptHead=*pptHead;
	struct MyFileOutStruct *pTemp,Temp;
	char sFileName[256];

	while(ptHead!=NULL){
		pTemp=(struct MyFileOutStruct *)ptHead->pData;
		if(strcmp(sSplitType,pTemp->sSplitType)==0) return pTemp;
		ptHead=ptHead->pNext;
	}
	bzero((void*)&Temp,sizeof(struct MyFileOutStruct));

	Temp.pNext=NULL;
	strcpy(Temp.sSplitType,sSplitType);
	sprintf(sFileName,"%s.%s.tmp",sTargetName,sSplitType);

	if((Temp.fp=fopen(sFileName,"w"))==NULL) return NULL;

	if(item2list(pptHead,(void*)&Temp,sizeof(struct MyFileOutStruct))<0)
		return NULL;
	return (struct MyFileOutStruct *)((*pptHead)->pData);
}

static int data_comp_accnbr_e(void *pValue,void *pData)
{

	struct AccNbrStruct *pSource=(struct AccNbrStruct *)pValue;
	struct AccNbrStruct *pTarget=(struct AccNbrStruct *)pData;

	return strcmp(pSource->sAccNbr,pTarget->sAccNbr);
	return strcmp(pSource->sFlag,pTarget->sFlag);
	return strcmp(pSource->sCallType,pTarget->sCallType);
}

static void assign_insert_bintree_accnbr_e(void **ppHead,void *pData)
{
	struct AccNbrStruct *pTemp;
	if((pTemp=(*ppHead))==NULL){
		pTemp=malloc(sizeof(struct AccNbrStruct));
		ERROR_EXIT(pTemp==NULL,"分配MsisdnStat结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct AccNbrStruct));
		pTemp->pNext=NULL;
		*ppHead=(void*)pTemp;
		return;
	}
	pTemp->iCnt+=((struct AccNbrStruct*)pData)->iCnt;
}

void mvitem_fmaccnbrticket(struct FSttTicketStruct *pi,int iFlag,
	struct AccNbrStruct *po){
	bzero((void*)po,sizeof(struct AccNbrStruct));
	if(iFlag==0){
		strncpy(po->sAccNbr,	pi->sMsisdn,15);
		strcpy(po->sFlag,"01");
	}
	else if(iFlag==1){
		strncpy(po->sAccNbr,	pi->sOtherParty,15);
		strcpy(po->sFlag,"02");
	}
	strncpy(po->sCallType,	pi->sCallType,2);
	po->iCnt=1;
	
	AllTrim(po->sAccNbr);
	AllTrim(po->sCallType);
}
   
int ProcessRecordSTT(struct FileControlStruct **ppLkHead,
	struct SttTicketStruct **pptHead){

	int iCnt=0,iMsisdn=0,iOtherParty=1;

	static struct AccNbrStruct Msisdn,OtherParty;
	struct AccNbrStruct *pAccNbr;
	struct SttTicketStruct *pDuration=NULL,*pSttList=NULL,*pFee=NULL;
	struct SttTicketStruct *pMsisdn=NULL,*pOtherParty=NULL,Temp,*pGw=NULL;
	struct FileControlStruct *ptHead,*pTemp,*pHead;
	
	BINTREE *pAccNbrRoot=NULL;

	ptHead=(*ppLkHead);
	pHead=(*ppLkHead);

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		iCnt++;

		mvitem_fmaccnbrticket((struct FSttTicketStruct *)(pTemp->pData),iMsisdn,
			&Msisdn);
		mvitem_fmaccnbrticket((struct FSttTicketStruct *)(pTemp->pData),iOtherParty,
			&OtherParty);

		if(InsertBin(&pAccNbrRoot,&Msisdn,data_comp_accnbr_e,
			assign_insert_bintree_accnbr_e)<0){
			WriteAlertMsg("生成BINTREE失败bintree_accnbr");
			exit(1);
		}
		if(InsertBin(&pAccNbrRoot,&OtherParty,data_comp_accnbr_e,
			assign_insert_bintree_accnbr_e)<0){
			WriteAlertMsg("生成BINTREE失败bintree_accnbr");
			exit(1);
		}
	}

	while(pHead!=NULL){
		pTemp=pHead;
		pHead=pHead->pNext;

		mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);

/*异地固网长途来话从本地群过网清单，增加xiaoqr,20071105
select * from stt_ticket_ct_09 where 
home_area_code!=visit_area_code and 
 trunk_in_carrier_id in(1,4,5,6) and  trunk_out_carrier_id=3 and
 trunk_in_type_id=1201
*/
		if(strcmp(Temp.sHomeAreaCode,Temp.sVisitAreaCode)!=0&&
			(Temp.iTrunkInCarrierID==1||Temp.iTrunkInCarrierID==4||
			Temp.iTrunkInCarrierID==5||Temp.iTrunkInCarrierID==6)&&
			Temp.iTrunkOutCarrierID==3&&Temp.iTrunkInTypeID==1201){
			if((pGw=malloc(sizeof(struct SttTicketStruct)))==NULL){
					printf("error Malloc SttTicketStruct.\n");
					return -1;
			}
			mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
					pTemp->iLen,pGw);
			
			strcpy(pGw->sErrCode,"4001");
			InsertList((LIST**)&pSttList,(LIST*)pGw);
				
				
		}
		

		mvitem_fmaccnbrticket((struct FSttTicketStruct *)(pTemp->pData),iMsisdn,
			&Msisdn);

		if((SearchBin(pAccNbrRoot,&Msisdn,data_comp_accnbr_e,
			(void**)&pAccNbr))==FOUND){
			if(pAccNbr->iCnt >9){
				if((pMsisdn=malloc(sizeof(struct SttTicketStruct)))==NULL){
			        		printf("error Malloc SttTicketStruct.\n");
						return -1;
				}
				mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
						pTemp->iLen,pMsisdn);

				if(strcmp(Temp.sCallType,"09")==0){
					if(Temp.iTrunkInCarrierID==3 && 
						Temp.iTrunkOutCarrierID!=3){
						strcpy(pMsisdn->sErrCode,"3101");
						InsertList((LIST**)&pSttList,(LIST*)pMsisdn);
					}
				}
				else if(strcmp(Temp.sCallType,"05")==0){
					if(Temp.iTrunkInCarrierID!=3 && 
						Temp.iTrunkOutCarrierID==3){
						strcpy(pMsisdn->sErrCode,"3201");
						InsertList((LIST**)&pSttList,(LIST*)pMsisdn);
					}
				}
			}
		}

		mvitem_fmaccnbrticket((struct FSttTicketStruct *)(pTemp->pData),iOtherParty,
			&OtherParty);

		if((SearchBin(pAccNbrRoot,&OtherParty,data_comp_accnbr_e,
			(void**)&pAccNbr))==FOUND){
			if(pAccNbr->iCnt >9){

				if((pOtherParty=malloc(sizeof(struct SttTicketStruct)))==NULL){
				        printf("error Malloc SttTicketStruct.\n");
					return -1;
				}  
				mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
					pTemp->iLen,pOtherParty);
				
				if(strcmp(Temp.sCallType,"09")==0){
					if(Temp.iTrunkInCarrierID==3 && 
						Temp.iTrunkOutCarrierID!=3){
						strcpy(pOtherParty->sErrCode,"3102");
						InsertList((LIST**)&pSttList,(LIST*)pOtherParty);						
					}
				}
				else if(strcmp(Temp.sCallType,"05")==0){
					if(Temp.iTrunkInCarrierID!=3 && 
						Temp.iTrunkOutCarrierID==3){
						strcpy(pOtherParty->sErrCode,"3202");
						InsertList((LIST**)&pSttList,(LIST*)pOtherParty);
					}
				}
			}
		}

		if(Temp.iDuration<3){

			if((pDuration=malloc(sizeof(struct SttTicketStruct)))==NULL){
					printf("error Malloc SttTicketStruct.\n");
					return -1;
				}  
	
			mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
				pTemp->iLen,pDuration);
			
			strcpy(pDuration->sErrCode,"1000");
			InsertList((LIST**)&pSttList,(LIST*)pDuration);
		}
		else if(Temp.iDuration>=1800){
			if((pDuration=malloc(sizeof(struct SttTicketStruct)))==NULL){
					printf("error Malloc SttTicketStruct.\n");
					return -1;
				}  
	
			mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
				pTemp->iLen,pDuration);
			
			strcpy(pDuration->sErrCode,"1001");
			InsertList((LIST**)&pSttList,(LIST*)pDuration);
		}
		if(Temp.iAddFee>2000 || Temp.iTollFee>2000){

			if((pFee=malloc(sizeof(struct SttTicketStruct)))==NULL){
					printf("error Malloc SttTicketStruct.\n");
					return -1;
			}  
	
			mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
				pTemp->iLen,pFee);
			
			strcpy(pFee->sErrCode,"1002");
			InsertList((LIST**)&pSttList,(LIST*)pFee);
		}
	}
	*pptHead=(void*)pSttList;
	DestroyList((LIST*)*ppLkHead);
	DestroyBin(pAccNbrRoot);
	return 0;
}
int ProcessRecordSMS(struct FileControlStruct **ppLkHead,
	struct SttTicketStruct **pptHead){

	int iCnt=0,iMsisdn=0,iOtherParty=1;

	static struct AccNbrStruct Msisdn,OtherParty;
	struct AccNbrStruct *pAccNbr;
	struct SttTicketStruct *pDuration=NULL,*pSttList=NULL,*pFee=NULL;
	struct SttTicketStruct *pMsisdn=NULL,*pOtherParty=NULL,Temp,*pGw=NULL;
	struct FileControlStruct *ptHead,*pTemp,*pHead;
	
	BINTREE *pAccNbrRoot=NULL;

	ptHead=(*ppLkHead);
	pHead=(*ppLkHead);

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		iCnt++;

		mvitem_fmaccnbrticket((struct FSttTicketStruct *)(pTemp->pData),iMsisdn,
			&Msisdn);

		if(InsertBin(&pAccNbrRoot,&Msisdn,data_comp_accnbr_e,
			assign_insert_bintree_accnbr_e)<0){
			WriteAlertMsg("生成BINTREE失败bintree_accnbr");
			exit(1);
		}
	}

	while(pHead!=NULL){
		pTemp=pHead;
		pHead=pHead->pNext;

		mvitem_fmaccnbrticket((struct FSttTicketStruct *)(pTemp->pData),iMsisdn,
			&Msisdn);

		if((SearchBin(pAccNbrRoot,&Msisdn,data_comp_accnbr_e,
			(void**)&pAccNbr))==FOUND){
			if(pAccNbr->iCnt >100){
				if((pMsisdn=malloc(sizeof(struct SttTicketStruct)))==NULL){
			        		printf("error Malloc SttTicketStruct.\n");
						return -1;
				}
				mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
						pTemp->iLen,pMsisdn);

				if(strcmp(STABLETYPE,"SMS")==0){
					strcpy(pMsisdn->sErrCode,"5001");
				}
				else if(strcmp(STABLETYPE,"SMX")==0){
					strcpy(pMsisdn->sErrCode,"6001");
				}
				
				
				InsertList((LIST**)&pSttList,(LIST*)pMsisdn);
			}
		}

	}
	*pptHead=(void*)pSttList;
	DestroyList((LIST*)*ppLkHead);
	DestroyBin(pAccNbrRoot);
	return 0;
}
int ProcessRecordVIT(struct FileControlStruct **ppLkHead,
	struct SttTicketStruct **pptHead){

	int iCnt=0,iMsisdn=0,iOtherParty=1;

	static struct AccNbrStruct Msisdn,OtherParty;
	struct AccNbrStruct *pAccNbr;
	struct SttTicketStruct *pDuration=NULL,*pSttList=NULL,*pFee=NULL;
	struct SttTicketStruct *pMsisdn=NULL,*pOtherParty=NULL,Temp,*pGw=NULL;
	struct FileControlStruct *ptHead,*pTemp,*pHead;
	
	BINTREE *pAccNbrRoot=NULL;

	ptHead=(*ppLkHead);
	pHead=(*ppLkHead);

	while(pHead!=NULL){
		pTemp=pHead;
		pHead=pHead->pNext;

		mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);
	
		if(Temp.iDuration>=1800){
			if((pDuration=malloc(sizeof(struct SttTicketStruct)))==NULL){
					printf("error Malloc SttTicketStruct.\n");
					return -1;
				}  
	
			mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
				pTemp->iLen,pDuration);
			
			strcpy(pDuration->sErrCode,"1001");
			InsertList((LIST**)&pSttList,(LIST*)pDuration);
		}
		if((Temp.iRoamFee+Temp.iTollFee)>5000){

			if((pFee=malloc(sizeof(struct SttTicketStruct)))==NULL){
					printf("error Malloc SttTicketStruct.\n");
					return -1;
			}  
	
			mvitem_fmsttticket((struct FSttTicketStruct *)(pTemp->pData),
				pTemp->iLen,pFee);
			
			strcpy(pFee->sErrCode,"1002");
			InsertList((LIST**)&pSttList,(LIST*)pFee);
		}
	}
	*pptHead=(void*)pSttList;
	DestroyList((LIST*)*ppLkHead);
	DestroyBin(pAccNbrRoot);
	return 0;
}

int ProcessFile(char sPath[],char sFilter[],char sTableName[]){

	int iCnt=0;
	char sFileName[128],sTempName[128];
	char sCommand[128],sDateTime[15];

	static struct SttTicketStruct *pOutList=NULL,*pTempOut=NULL;
	struct SttTicketStructOut TempOut;
	struct FileControlStruct *ptHead=NULL,*pHead=NULL,*pTemp;

	strcpy(TempOut.sTableName,sTableName);

	if((iCnt=dir2list(sPath,sFilter,&ptHead))<0){
		WriteAlertPrint("生成文件列表失败 %s %s",
			sPath,sFilter);
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		memcpy(sFileName,pTemp->pData,pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		sprintf(sTempName,"%s%s",sPath,sFileName);

		if((TxtFileToList(sTempName,&pHead))<0){
			printf("加载文件%s到内存失败.\n",sFileName);
			WriteErrStackAlert();
			return -1;
		}


		if(strcmp(STABLETYPE,"STT")==0){
			ProcessRecord=ProcessRecordSTT;
		}
		else if(strcmp(STABLETYPE,"SMS")==0){
			ProcessRecord=ProcessRecordSMS;
		}
		else if(strcmp(STABLETYPE,"SMX")==0){
			ProcessRecord=ProcessRecordSMS;
		}
		else if(strcmp(STABLETYPE,"VIT")==0){
			ProcessRecord=ProcessRecordVIT;
		}
	

		if(ProcessRecord(&pHead,&pOutList)<0){
			WriteAlertPrint("处理话单记录错误");
			return -1;
		}


		while(pOutList!=NULL){
			pTempOut=pOutList;
			pOutList=pOutList->pNext;

			if(EInsertStructToSttTicket(pTempOut,false,&TempOut)){
				printf("写数据表%s时出错.\n",TempOut.sTableName);
				return -1;
			}
			iCnt++;
			if(iCnt%10000==0){
				if(EInsertStructToSttTicket(NULL,true,&TempOut)){
					printf("写数据表%s时出错.\n",TempOut.sTableName);
					return -1;
				}
				CommitWork();
			}
		}
		if(EInsertStructToSttTicket(NULL,true,&TempOut)){
			printf("写数据表%s时出错.\n",TempOut.sTableName);
			return -1;
		}
		CommitWork();

		printf("文件%s处理完,记录数据为%d.\n",sTempName,iCnt);
		
		sprintf(sCommand,"rm -f %s",sTempName);
		if(system(sCommand)!=0){
			printf("删除文件%s失败\n",sTempName);
			return -1;
		}
		DestroyList((LIST*)pOutList);
		GetHostTime( sDateTime );
		printf("time=%s\n",sDateTime);
	}
	listfree(&ptHead);

	return 0;
}


int DealSTT(char sSouTableName[],char sOutTableName[],char sCondition[],
	char sFileName[],char sFilter[],char sPath[]){
	
	char sTemp[11];
	
	
	struct SttTicketStruct Temp;
	struct SttTicketStructIn TempIn;
	struct FSttTicketStruct FTemp;
	struct FileControlStruct *pTemp=NULL;
	
	strcpy(TempIn.sTableName,sSouTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;


	while(EGetSttTicketToStruct(&Temp,&TempIn)){
		
		if(strcmp(STABLETYPE,"VIT")==0){
			
			if(Temp.iTicketTypeID!=9312&&
				Temp.iTicketTypeID!=9322&&
				Temp.iTicketTypeID!=9412&&
				Temp.iTicketTypeID!=9422)continue;
		}
		
		strncpy(sTemp,Temp.sStartTime,10);sTemp[10]=0;

		mvitem_mfsttticket(&Temp,&FTemp);

		if(item2fileout(&pTemp,(void*)&FTemp,sizeof(struct FSttTicketStruct),sFileName,
			sTemp)<0){
			WriteAlertPrint("生成话单链表错误");
			return -1;
		}
	}

	CloseFileOut(pTemp);
	
	printf("话单文件生成完\n");
	if(ProcessFile(sPath,sFilter,sOutTableName)<0){
		WriteAlertPrint("处理话单文件错误");
		return -1;
	}

}


int DealSMS(char sSouTableName[],char sOutTableName[],char sCondition[],
	char sFileName[],char sFilter[],char sPath[]){
	
	char sTemp[11];
	
	
	struct SmsTicketStruct Temp;
	struct SmsTicketStructIn TempIn;
	struct FSttTicketStruct FTemp;
	struct FileControlStruct *pTemp=NULL;
	
	strcpy(TempIn.sTableName,sSouTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;


	while(EGetSmsTicketToStruct(&Temp,&TempIn)){

		strncpy(sTemp,Temp.sStartTime,10);sTemp[10]=0;

		mvitem_mfsms2sttticket(&Temp,&FTemp);

		if(item2fileout(&pTemp,(void*)&FTemp,sizeof(struct FSttTicketStruct),sFileName,
			sTemp)<0){
			WriteAlertPrint("生成话单链表错误");
			return -1;
		}
	}

	CloseFileOut(pTemp);
	
	printf("话单文件生成完\n");
	if(ProcessFile(sPath,sFilter,sOutTableName)<0){
		WriteAlertPrint("处理话单文件错误");
		return -1;
	}

}
void mvitem_mfsms2sttticket(struct SmsTicketStruct *pi,struct FSttTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSttTicketStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sCalledCode,pi->sCalledCode,strlen(pi->sCalledCode));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		/*填短信计费用户的归属地*/
		strncpy(po->sVisitAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));

		sprintf(sTemp,"%05d",pi->iBaseFee);
		strncpy(po->sRoamFee,sTemp,5);
		sprintf(sTemp,"%07d",pi->iInfoFee);
		strncpy(po->sTollFee,sTemp,7);
		sprintf(sTemp,"%05d",pi->iRentFee);
		strncpy(po->sAddFee,sTemp,5);
		sprintf(sTemp,"%06d",pi->iMsgLen);
		strncpy(po->sDuration,sTemp,6);

		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sImsi,pi->sSmg,strlen(pi->sSmg));
		strncpy(po->sMsc,pi->sTsmg,strlen(pi->sTsmg));
		strncpy(po->sCellID,pi->sBillType,strlen(pi->sBillType));
		strncpy(po->sOtherLac,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sOtherCellID,pi->sCalledType,strlen(pi->sCalledType));
		strncpy(po->sTrunkIn,pi->sSpProvCode,strlen(pi->sSpProvCode));
		strncpy(po->sTrunkOut,pi->sHomeProvCode,strlen(pi->sHomeProvCode));
		strncpy(po->sThirdParty,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sMsrn,pi->sSpServiceCode,strlen(pi->sSpServiceCode));



		sprintf(sTemp,"%04d",pi->iCallingTypeID);
		strncpy(po->sCallingTypeID,sTemp,4);


		strncpy(po->sEsn,pi->sSpAccNbr,strlen(pi->sSpAccNbr));

		strncpy(po->sScpFlag,pi->sScpFlag,strlen(pi->sScpFlag));

		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}

int DealSMX(char sSouTableName[],char sOutTableName[],char sCondition[],
	char sFileName[],char sFilter[],char sPath[]){
	
	char sTemp[11];
	
	
	struct SmspTicketStruct Temp;
	struct SmspTicketStructIn TempIn;
	struct FSttTicketStruct FTemp;
	struct FileControlStruct *pTemp=NULL;
	
	strcpy(TempIn.sTableName,sSouTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;


	while(EGetSmspTicketToStruct(&Temp,&TempIn)){

		strncpy(sTemp,Temp.sStartTime,10);sTemp[10]=0;

		mvitem_mfsmsp2sttticket(&Temp,&FTemp);

		if(item2fileout(&pTemp,(void*)&FTemp,sizeof(struct FSttTicketStruct),sFileName,
			sTemp)<0){
			WriteAlertPrint("生成话单链表错误");
			return -1;
		}
	}

	CloseFileOut(pTemp);
	
	printf("话单文件生成完\n");
	if(ProcessFile(sPath,sFilter,sOutTableName)<0){
		WriteAlertPrint("处理话单文件错误");
		return -1;
	}

}

void mvitem_mfsmsp2sttticket(struct SmspTicketStruct *pi,struct FSttTicketStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSttTicketStruct));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		/*填短信计费用户的归属地*/
		strncpy(po->sVisitAreaCode,pi->sCityCode,strlen(pi->sCityCode));

		sprintf(sTemp,"%05d",atoi(pi->sFee1));
		strncpy(po->sRoamFee,sTemp,5);
		sprintf(sTemp,"%07d",atoi(pi->sFee2));
		strncpy(po->sTollFee,sTemp,7);
		sprintf(sTemp,"%06d",atoi(pi->sDuration));
		strncpy(po->sDuration,sTemp,6);

		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sHomeAreaCode,pi->sSpCode,strlen(pi->sSpCode));
		strncpy(po->sImsi,pi->sSmsp,strlen(pi->sSmsp));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sCellID,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sTrunkOut,pi->sSpAccNbr,strlen(pi->sSpAccNbr));
		strncpy(po->sThirdParty,pi->sSpServiceCode,strlen(pi->sSpServiceCode));

		strncpy(po->sMsrn,pi->sFee4,strlen(pi->sFee4));
		strncpy(po->sEsn,pi->sFee5,strlen(pi->sFee5));


		strncpy(po->sReserve,pi->sFee6,strlen(pi->sFee6));
		
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}

int main(int argc,char **argv){

	char sFileName[256],sAppPath[128];
	char sPath[128],sFilter[48];
	char sSouTableName[128],sOutTableName[128],sCondition[256];


	if(argc != 4&&argc != 5){
		printf("用法：%s tablename errtable wherecase [SMS|SMX|VIT(def=STT)]\n",argv[0]);
		exit(1);
	}

	InitAppRes(argv[0]);
	if(IniConnect("dataconnstr")<0){
		printf("连接数据库失败\n");
		return -1;
	}

	strcpy(sSouTableName,argv[1]);
	strcpy(sOutTableName,argv[2]);
	strcpy(sCondition,argv[3]);
	if(argc == 5){
		strcpy(STABLETYPE,argv[4]);
		STABLETYPE[3]=0;
	}
	else	strcpy(STABLETYPE,"STT");
	
	GetAppHome(sAppPath);
	sprintf(sFileName,"%swork/%s",sAppPath,argv[1]);

	sprintf(sFilter,"%s.20*",argv[1]);
	sprintf(sPath,"%swork/",sAppPath);
	if(strcmp(STABLETYPE,"STT")==0||
		strcmp(STABLETYPE,"VIT")==0){
		DealX=DealSTT;
	}
	else if(strcmp(STABLETYPE,"SMS")==0){
		DealX=DealSMS;
	}
	else if(strcmp(STABLETYPE,"SMX")==0){
		DealX=DealSMX;
	}


	if(DealX(sSouTableName,sOutTableName,sCondition,
		sFileName,sFilter,sPath)<0){
		printf("处理出错。\n");
		return -1;
	}

	printf("处理完。\n");

	return 0;
}
