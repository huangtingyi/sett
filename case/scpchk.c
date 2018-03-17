/*---------函数实现代码 unicom_ticket.pc----------*/
#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>
#include <wwfile.h>
#include <wwdir.h>
#include "wwshm.h"
#include "scpchk.h"

/*批量数据结构缓冲更新*/
int EUpdateStructToSttTicketState(struct SttTicketStruct *p,
	int iUpdateFlag,struct USttTicketStructUp *pTarget);

int cmitem_ticket_spot(void *pi,void *po)
{
	struct SttTicketStruct	*pSource =pi;
	struct SttTicketStruct *pTarget=(struct SttTicketStruct *)po;

/*数据比较部分*/
	int res=0;

 	if(strcmp(pSource->sCallType,pTarget->sCallType)==0&&
 		strcmp(pSource->sMsisdn,pTarget->sMsisdn)==0&&
		strcmp(pSource->sOtherParty,pTarget->sOtherParty)==0) return res;

	return -1;
}
int AnalyzeTicket(struct SttTicketStruct *pSource,char sTableName[],
	struct SttTicketStruct **pTarget,struct SttTicketStruct **ptUp)
{
	static struct SttTicketStruct *ptHead=NULL,*pTemp=NULL;
	static struct SttTicketStruct *pTempI,*pTempOut,*pTempUp,*p;
	time_t	tStartTime,tNextStartTime;
	int iCnt=0;
	char sHostDate[15];
	
	ptHead=pSource;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;		
		p=ptHead;
		iCnt++;
		
		/*插入输出链表*/
		if((pTempI=(struct SttTicketStruct *)malloc(
		 sizeof(struct SttTicketStruct)))==NULL){
			 printf("分配内存失败.\n");
			 return -1;
		
		}
		mvitem_SttTicketStruct(pTemp,pTempI);
		
		InsertList((LIST**)&pTempOut,(LIST*)pTempI);

		
		/*取到一组最后一条话单*/
		tStartTime=tGetTime(pTemp->sStartTime);
		tNextStartTime=tGetTime(p->sStartTime);
		if((tStartTime+pTemp->iDuration)<tNextStartTime){
			/*最后一条话单*/
			if(strcmp(pTemp->sScpFlag,"0")==0){/*SCP_FLAG未打上标志*/
				/*插入输出链表UPDATE链表*/
				strcpy(pTempI->sState,"X");
				InsertList((LIST**)&pTempUp,(LIST*)pTempI);
				iCnt=0;
			}
			else{/*SCP_FLAG打上标志*/
				if(iCnt==1){
					GetHostTime(sHostDate);
					if((tStartTime+7200)>tGetTime(sHostDate)){
						continue;
						DeleteList((LIST**)&pTempOut,(LIST*)pTemp);
					}
				}

				/*插入输出链表UPDATE链表*/
				strcpy(pTempI->sState,"X");
				InsertList((LIST**)&pTempUp,(LIST*)pTempI);
				/*置ScpFlag*/
				ModifyTicketScpFlag(pTempOut,pTemp->sScpFlag);
				iCnt=0;
			}
			
		}
		else{/*非最后一条话单*/
			GetHostTime(sHostDate);
			if((tStartTime+21600)>tGetTime(sHostDate)){
				continue;
				DeleteList((LIST**)&pTempOut,(LIST*)pTemp);
			}
			/*插入输出链表UPDATE链表*/
			strcpy(pTempI->sState,"X");
			InsertList((LIST**)&pTempUp,(LIST*)pTempI);
			iCnt=0;			
		}
	}

	*pTarget=(void*)pTempOut;
	*ptUp=(void*)pTempUp;
	
	return 0;
	
}

int ModifyTicketScpFlag(struct SttTicketStruct *p,char sScpFlag[])
{
	static struct SttTicketStruct	*pTemp,*ptHead=NULL;
	
	ptHead=p;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		strncpy(p->sScpFlag,sScpFlag,1);
	}	
	return 0;
}
int UpdateSttState(struct SttTicketStruct *pSourcet,char sTableName[],
	int iUpdateFlag)
{
	static struct USttTicketStructUp TempUp;
	static int iFirstFlag=TRUE;

	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempUp,sizeof(struct USttTicketStructUp));
		strcpy(TempUp.sTableName,sTableName);
	}

	return EUpdateStructToSttTicketState(pSourcet,iUpdateFlag,&TempUp);
}
int UpdateStt(struct SttTicketStruct *pSourcet,char sTableName[])
{
	int iCnt=0;
	static struct SttTicketStruct *pTemp,*ptHead;
	
	ptHead=pSourcet;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(UpdateSttState(pTemp,sTableName,FALSE)<0){
			WriteErrStackAlert();
			RollbackWorkRelease();
			return -1;
		}
		if(++iCnt%10000==0){ 
			if(UpdateSttState(NULL,sTableName,TRUE)<0){
				WriteErrStackAlert();
				RollbackWorkRelease();
				return -1;
			}
			printf("更新记录数%d.\n",iCnt);
			WriteProcMsg("更新记录数%d.",iCnt);
		}
	}
	if(UpdateSttState(NULL,sTableName,TRUE)<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
	
	return iCnt;
}

int ProcessFile(struct SttTicketStruct *pSource,char sTargetName[])
{
	int iFileRecordLen,iCnt=0;
	struct FileControlStruct *pOutput=NULL;
	struct SttTicketStruct	*ptHead,*pTemp;
	struct FSttTicketStruct FTemp;

	ptHead=pSource;
	iFileRecordLen=sizeof(struct FSttTicketStruct)-31;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		mvitem_mfsttticket(pTemp,&FTemp);
		
		if(item2listtail(&pOutput,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2fileln(&pOutput,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.\n",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}

	listfree(&pOutput);
	return iCnt;
}


int main(int argc,char *argv[])
{
	int iCnt=0,iUpdateCnt=0;
	char sTableName[60],sCondition[256];
	char sTargetName[256],sTargetPath[256],sOutFileName[256];
	
	static struct SttTicketStruct	Temp,*pTemp,*pTemps,*ptHead=NULL;
	static struct SttTicketStruct	*ptLkHead=NULL,*pSameHead=NULL,*ptSttOut,*ptSttUp;
	struct SttTicketStructIn	TempIn;
	
	if(argc!=4){
		printf("用法：%s TableName TargetPath sOutFileName.\n",argv[0]);
		exit(1);
	}
	
	InitAppRes(argv[0]);
	strcpy(sTableName,argv[1]);
        Upper(sTableName);
	strcpy(sTargetPath,argv[2]);
	strcpy(sOutFileName,argv[3]);

	if(IsDir(sTargetPath)==FALSE){
		printf("输出目录%s无效.\n",sTargetPath);
		return -1;
	}

	RegularDir(sTargetPath);
	
	sprintf(sTargetName,"%s%s",sTargetPath,sOutFileName);

	IniConnect("dataconnstr");


/*初始化select和update结构缓冲*/
	bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));
	TempIn.iFirstFlag=true;
	TempIn.iBufEmpty =true;
	strcpy(TempIn.sTableName,sTableName);
	sprintf(sCondition,"\n\
		WHERE STATE='0' \n\
		ORDER BY CALL_TYPE,MSISDN,OTHER_PARTY,START_TIME,DURATION ");
	strcpy(TempIn.sCondition,sCondition);
	
	/*加载话单表到ptLkHead*/
	while(EGetSttTicketToStruct(&Temp,&TempIn)==true){
		if((pTemp=(struct SttTicketStruct *)malloc(
		 sizeof(struct SttTicketStruct)))==NULL){
			 printf("分配内存失败.\n");
			 return -1;
		
                }
		mvitem_SttTicketStruct(&Temp,pTemp);
		
		InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
		
		if((++iCnt)%10000==0){
			WriteAlertMsg("加载话单表 %s 记录 %d 条",sTableName,iCnt);
			printf("加载话单表 %s 记录 %d 条.\n",sTableName,iCnt);
			
		}
	}
	
	/*从ptLkHead中取出第一个CALL_TYPE,MSISDN,OTHER_PARTY相同的话单出来;*/
	ptHead=ptLkHead;
	iCnt=0;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if((pTemps=(struct SttTicketStruct *)malloc(
		 sizeof(struct SttTicketStruct)))==NULL){
			 printf("分配内存失败.\n");
			 return -1;
		
	        }
		mvitem_SttTicketStruct(pTemp,pTemps);
		
		InsertList((LIST**)&pSameHead,(LIST*)pTemps);
		
		/*判断每组话单的结点*/
		if(cmitem_ticket_spot(ptHead,pTemp)!=0){
			/*处理单组话单*/
			AnalyzeTicket(pSameHead,sTableName,&ptSttOut,&ptSttUp);
			pSameHead=NULL;
		}
		
	}

	if((iUpdateCnt=UpdateStt(ptSttUp,sTableName))<0){
		printf("修改 %s 表state失败.\n",sTableName);
		return -1;
	}
	WriteAlertMsg("修改 %s 表state记录 %d 条.\n",sTableName,iUpdateCnt);
	printf("修改 %s 表state记录 %d 条.\n",sTableName,iUpdateCnt);
	
	if((iCnt=ProcessFile(ptSttOut,sTargetName))<0){
		printf("写文件失败！.\n");
		RollbackWorkRelease();
		return -1;
	}
	
	WriteAlertMsg(" %d 条记录输出到话单文件 %s 成功.\n",iCnt,sOutFileName);
	printf(" %d 条记录输出到话单文件 %s 成功.\n",iCnt,sOutFileName);

	CommitWorkRelease();	
	DisconnectDatabase();

	return 0;
}
