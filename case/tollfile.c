/*---------函数实现代码 unicom_ticket.pc----------*/                                          
#include <stdio.h>	
#include <stdlib.h>     
#include <wwdb.h>       
#include <wwlog.h>      
#include <wwtiny.h>     
#include <bintree.h>    
#include <list.h>   
#include <wwfile.h>     
#include <stt_ticket.h>
#include "param_intf.h"
#include "wwshm.h"
#include "tollfile.h"

struct StatAllStruct FileStat;
BINTREE *pRoot=NULL;
BINTREE *pFileRoot=NULL;
FILE *fp=NULL;
char sProvCode[5],sNetType[2];

int GetProvCode(char sProvCode[5])
{	
	int iRet;
	char sTemp[128],sPath[128];

	GetIniName(sPath);
	
	iRet=ReadString(sPath,"bss","updata","belong_code",sTemp);
	ERROR_RETURNZ(iRet<0,"读取bill.ini文件失败");
	ERROR_RETURNA((strlen(sTemp)==0),"bill.ini->bss->updata-%s无对应配置",
		"belong_code");

	strncpy(sProvCode,sTemp,4);
	sProvCode[4]=0;
	AllTrim(sProvCode);

	return 0;
}

/*取VisitAreaCode*/
void GetTollVisitAreaCode(struct SttTicketStruct *pSource,
	char sVisitAreaCode[])
{		
	struct TrunkStruct *pTrunk=NULL;
		
	if(SearchTrunk(pSource->sMsc,pSource->sTrunkIn,"I",
		pSource->sStartTime,&pTrunk)==FOUND)
		strcpy(sVisitAreaCode,pTrunk->sOppAreaCode);
	else
		strcpy(sVisitAreaCode,pSource->sVisitAreaCode);
/*甘肃的长途VISIT_AREA_CODE要设为归属*/
	if(strncmp(pSource->sVisitAreaCode,"93",2)==0||
		strncmp(pSource->sVisitAreaCode,"94",2)==0)
		strcpy(sVisitAreaCode,pSource->sHomeAreaCode);
}

/*取OppAreaCode*/
void GetTollOppAreaCode(struct SttTicketStruct *pSource,
	char sOppAreaCode[])
{
	struct TrunkStruct *pTrunk=NULL;
	
	if((strcmp(pSource->sVisitAreaCode,pSource->sCalledCode)==0)||
		(pSource->sCalledCode[0]=='0')){
		if(SearchTrunk(pSource->sMsc,pSource->sTrunkOut,"O",
			pSource->sStartTime,&pTrunk)==FOUND)
			strcpy(sOppAreaCode,pTrunk->sOppAreaCode);
	}
	else strcpy(sOppAreaCode,pSource->sCalledCode);

/*甘肃的长途OPP_AREA_CODE要设为CALLED_CODE*/
	if(strncmp(pSource->sVisitAreaCode,"93",2)==0||
		strncmp(pSource->sVisitAreaCode,"94",2)==0)
		strcpy(sOppAreaCode,pSource->sCalledCode);

}

/*累加记录*/
void InsertTollRecord(struct TollFileStatStruct *pTemp,
	struct SttTicketStruct *pRecordData)
{
	int iTollMin,iTollSec,iTollFee;
	
	iTollMin=(pRecordData->iDuration+59)/60;
	iTollSec=(pRecordData->iDuration+5)/6*6;
	/*对于福建来说长途费为每分钟8分钱*/	
	if(strncmp(pRecordData->sVisitAreaCode,"59",2)==0)
		iTollFee=iTollMin*8;
	else
		iTollFee=pRecordData->iTollFee;

	if (pRecordData->iTicketTypeID==301){
		pTemp->i301TotalCallNum	+=iTollMin;
		pTemp->i301TotalDuration+=iTollSec;
		pTemp->i301TotalTollFee	+=iTollFee;
	}
	
	if (pRecordData->iTicketTypeID==302){
		pTemp->i302TotalCallNum	+=iTollMin;
		pTemp->i302TotalDuration+=iTollSec;
		pTemp->i302TotalTollFee	+=iTollFee;
	}
	
	if (pRecordData->iTicketTypeID==303){
		pTemp->i303TotalCallNum	+=iTollMin;
		pTemp->i303TotalDuration+=iTollSec;
		pTemp->i303TotalTollFee	+=iTollFee;
	}
	
	if (pRecordData->iTicketTypeID==304){
		pTemp->i304TotalCallNum	+=iTollMin;
		pTemp->i304TotalDuration+=iTollSec;        
		pTemp->i304TotalTollFee	+=iTollFee; 
		/*注意这里累计的是分钟数*/
		pTemp->i304TotalRoamFee	+=iTollMin;
	}
	
	if (pRecordData->iTicketTypeID==305){
		pTemp->i305TotalCallNum	+=iTollMin;
		pTemp->i305TotalDuration+=iTollSec;
		pTemp->i305TotalTollFee	+=iTollFee;
	}    
	/*
	pTemp->iTotalFee	=pTemp->i301TotalTollFee+
				 pTemp->i302TotalTollFee+
				 pTemp->i303TotalTollFee+ 
				 pTemp->i304TotalTollFee+   
				 pTemp->i304TotalRoamFee+ 
				 pTemp->i305TotalTollFee;
	*/
}
                  
/*参数：外部要插入的结构，当前结点的数据区*/
int data_search_bintree_tollrecord(void *pValue,void*pData)
{               
	char sOppAreaCode[10],sVisitAreaCode[10];
	
	struct SttTicketStruct *pSource=(struct SttTicketStruct *)pValue;
	struct TollFileStatStruct *pTarget=(struct TollFileStatStruct *)pData;
	int res;
	        
	GetTollVisitAreaCode(pSource,sVisitAreaCode);
	GetTollOppAreaCode(pSource,sOppAreaCode);
	        
	res=0;	
	if((res=strcmp(sVisitAreaCode,pTarget->sVisitAreaCode))!=0)
		return res;
	if((res=strcmp(sOppAreaCode,pTarget->sOppAreaCode))!=0)
		return res;
	return res;
}               
                
void assign_insert_bintree_tollrecord(void **ppData,void *pData)
{               
	struct TollFileStatStruct *pTemp;
	struct SttTicketStruct *pRecordData=(struct SttTicketStruct*)pData;
	
	/*当第一次调用该函数（即创建结点的过程中），*ppData还没加载数据*/
	if((pTemp=(*ppData))==NULL){	
		pTemp=malloc(sizeof(struct TollFileStatStruct));
		ERROR_EXIT(pTemp==NULL,"分配TollFileStatStruct结构错误");
		bzero((void*)pTemp,sizeof(struct TollFileStatStruct));

		/*如果不存在该sVisitAreaCode与sOppAreaCode，定义结点的数据区*/
		/*做数据关联,生成结点的键值*/
		GetTollVisitAreaCode((struct SttTicketStruct*)pData,
			pTemp->sVisitAreaCode);
		GetTollOppAreaCode((struct SttTicketStruct*)pData,
			pTemp->sOppAreaCode);
		
		pTemp->iTotalRecCnt=1;
		InsertTollRecord(pTemp,pRecordData);
		
		strcpy(pTemp->sMinStartTime,pRecordData->sStartTime);
		strcpy(pTemp->sMaxStartTime,pRecordData->sStartTime);
		
		/*将定义好的结点数据区挂回结点上*/
		*ppData=(void*)pTemp;
                
		return;
	}       
	/*如果找到相同的键值的结点,根据对应ticket_type_id累加记费数,时长,费用*/
	pTemp=(*ppData);
	pTemp->iTotalRecCnt++;
	InsertTollRecord(pTemp,pRecordData);
			
	/*比较时间*/
	if(strcmp(pTemp->sMinStartTime,pRecordData->sStartTime)>0) 
		strcpy(pTemp->sMinStartTime,pRecordData->sStartTime);
	if(strcmp(pTemp->sMaxStartTime,pRecordData->sStartTime)<0) 
		strcpy(pTemp->sMaxStartTime,pRecordData->sStartTime);
}   

/*调整二叉树结点*/
int AdjustTollNode(void **ppRoot)
{
	double dRatio;
	struct TollFileStatStruct *pTemp=(*ppRoot);
	
	if(pTemp==NULL) return 0;

	if(strncmp(sProvCode,"038",3)==0){
		dRatio=1.0/10;
		pTemp->i301TotalCallNum=pTemp->i301TotalCallNum*dRatio;
		pTemp->i302TotalCallNum=pTemp->i302TotalCallNum*dRatio;
		pTemp->i303TotalCallNum=pTemp->i303TotalCallNum*dRatio;
		pTemp->i304TotalCallNum=pTemp->i304TotalCallNum*dRatio;
		pTemp->i305TotalCallNum=pTemp->i305TotalCallNum*dRatio;
			
		pTemp->i301TotalTollFee=pTemp->i301TotalTollFee*dRatio;
		pTemp->i302TotalTollFee=pTemp->i302TotalTollFee*dRatio;
		pTemp->i303TotalTollFee=pTemp->i303TotalTollFee*dRatio;
		pTemp->i304TotalTollFee=pTemp->i304TotalTollFee*dRatio;
		pTemp->i305TotalTollFee=pTemp->i305TotalTollFee*dRatio;
		/*注意这里i304TotalRoamFee是分钟数*/	
		pTemp->i304TotalRoamFee=pTemp->i304TotalRoamFee/3*10*dRatio;
	}
	else if(strncmp(sProvCode,"087",3)==0){
		/*甘肃的指标只有301的话单类型，其它全为0，
			甘肃的TOLL_DURATION也做了比率调整*/
		/*甘肃G网特殊处理,比率为6/10*/
		if(strcmp(sNetType,"G")==0){
			pTemp->i301TotalTollFee=pTemp->i301TotalTollFee*6/10;
			pTemp->i301TotalCallNum=pTemp->i301TotalCallNum*6/10;
			pTemp->i301TotalDuration=pTemp->i301TotalDuration*6/10/6*6;

			if(pTemp->i301TotalTollFee!=0&&pTemp->i301TotalCallNum==0)
				pTemp->i301TotalCallNum=1;
			if(pTemp->i301TotalTollFee!=0&&pTemp->i301TotalDuration==0)
				pTemp->i301TotalDuration=6;
		}
		else{/*甘肃C网特殊处理,比率为1/4*/
			pTemp->i301TotalTollFee=pTemp->i301TotalTollFee/4;
			pTemp->i301TotalCallNum=pTemp->i301TotalCallNum/4;
			pTemp->i301TotalDuration=pTemp->i301TotalDuration/4/6*6;
			if(pTemp->i301TotalTollFee!=0&&pTemp->i301TotalCallNum==0)
				pTemp->i301TotalCallNum=1;
			if(pTemp->i301TotalTollFee!=0&&pTemp->i301TotalDuration==0)
				pTemp->i301TotalDuration=6;
		}
	}
	else/*其它地区只要调整一下304指标即可,这里i304TotalRoamFee是分钟数*/	
		pTemp->i304TotalRoamFee=pTemp->i304TotalRoamFee/3*10;

	return 0;       
}                       

/*时长,计费次数,费用统计*/
int StatAll(void **ppRoot)
{
	struct TollFileStatStruct *pTemp=(*ppRoot);
	
	if(pTemp!=NULL){
		FileStat.i301StatAllCallNum	+=pTemp->i301TotalCallNum;
		FileStat.i301StatAllDuration	+=pTemp->i301TotalDuration;	
		FileStat.i301StatAllTollFee	+=pTemp->i301TotalTollFee; 
		
		FileStat.i302StatAllCallNum	+=pTemp->i302TotalCallNum; 
		FileStat.i302StatAllDuration	+=pTemp->i302TotalDuration;
		FileStat.i302StatAllTollFee	+=pTemp->i302TotalTollFee;
		
		FileStat.i303StatAllCallNum	+=pTemp->i303TotalCallNum;
		FileStat.i303StatAllDuration	+=pTemp->i303TotalDuration;
		FileStat.i303StatAllTollFee	+=pTemp->i303TotalTollFee;
		
		FileStat.i304StatAllCallNum	+=pTemp->i304TotalCallNum; 
		FileStat.i304StatAllDuration	+=pTemp->i304TotalDuration;
		FileStat.i304StatAllTollFee	+=pTemp->i304TotalTollFee;    
		FileStat.i304StatAllRoamFee	+=pTemp->i304TotalRoamFee; 

		FileStat.i305StatAllCallNum	+=pTemp->i305TotalCallNum; 
		FileStat.i305StatAllDuration	+=pTemp->i305TotalDuration;
		FileStat.i305StatAllTollFee	+=pTemp->i305TotalTollFee; 
		FileStat.iStalAllRecCnt	++; 		
		/*FileStat.iStalAllRecCnt	+=pTemp->iTotalRecCnt;*/ 
		/*FileStat.iStatAllFee		+=pTemp->iTotalFee;*/
		
		FileStat.iStatAllFee		=FileStat.iStatAllFee+
						pTemp->i301TotalTollFee+
						pTemp->i302TotalTollFee+
						pTemp->i303TotalTollFee+
						pTemp->i304TotalTollFee+
						pTemp->i304TotalRoamFee+
						pTemp->i305TotalTollFee;
		/*比较时间*/
		if(strcmp(FileStat.sFirstStartTime,pTemp->sMinStartTime)>0)   
			strcpy(FileStat.sFirstStartTime,pTemp->sMinStartTime);
		if(strcmp(FileStat.sLastStartTime,pTemp->sMaxStartTime)<0)   
			strcpy(FileStat.sLastStartTime,pTemp->sMaxStartTime);
	}
	return 0;						
}   

void GenTollFileHead(char sCompanyCode[],char sFileFlag[],char sFileSeq[],
	char sMinTime[],char sMaxTime[],struct TollFileHeadStruct *pFileHead) 
{
	char sBeginDate[9],sBeginTime[7];
	char sEndDate[9],sEndTime[7];
	char sNowTime[15],sNowDate[9];
	
	GetHostTime(sNowTime);
	strncpy(sNowDate,sNowTime,8);sNowDate[8]=0;
	
	strncpy(sBeginDate,sMinTime,8);sBeginDate[8]=0;
	strncpy(sBeginTime,sMinTime+8,6);sBeginTime[6]=0;
	strncpy(sEndDate,sMaxTime,8);sEndDate[8]=0;
	strncpy(sEndTime,sMaxTime+8,6);sEndTime[6]=0;
	
   	strcpy (pFileHead->sFileType	,"00");
	strcpy (pFileHead->sCompanyCode	,sCompanyCode);
	strcpy (pFileHead->sFileFlag	,sFileFlag);
	strcpy (pFileHead->sFileSeq	,sFileSeq );
	strcpy (pFileHead->sFileVersion	,"02");
	strcpy (pFileHead->sFileCreateDate,sNowDate);
	strcpy (pFileHead->sBeginDate	,sBeginDate);
	strcpy (pFileHead->sBeginTime	,sBeginTime);
	strcpy (pFileHead->sEndDate	,sEndDate);
	strcpy (pFileHead->sEndTime	,sEndTime);
	sprintf(pFileHead->sTotalRecord ,"%d",FileStat.iStalAllRecCnt);    
	sprintf(pFileHead->sTotalFee	,"%d",FileStat.iStatAllFee);        	
	strcpy (pFileHead->sUnUsedSpace	,"0"); 		
}
    
void GenTollFileTail(struct TollFileTailStruct *pFileTail)
{
	sprintf(pFileTail->sTotalTollFee1,"%d",FileStat.i301StatAllTollFee);
	sprintf(pFileTail->sTotalCallNum1,"%d",FileStat.i301StatAllCallNum);
	sprintf(pFileTail->sTotalDuration1,"%d",FileStat.i301StatAllDuration);
	sprintf(pFileTail->sTotalTollFee2,"%d",FileStat.i302StatAllTollFee);
	sprintf(pFileTail->sTotalCallNum2,"%d",FileStat.i302StatAllCallNum);
	sprintf(pFileTail->sTotalDuration2,"%d",FileStat.i302StatAllDuration);
	sprintf(pFileTail->sTotalTollFee3,"%d",FileStat.i303StatAllTollFee);
	sprintf(pFileTail->sTotalCallNum3,"%d",FileStat.i303StatAllCallNum);
	sprintf(pFileTail->sTotalDuration3,"%d",FileStat.i303StatAllDuration);
	sprintf(pFileTail->sTotalTollFee4,"%d",FileStat.i304StatAllTollFee);
	sprintf(pFileTail->sTotalLocalFee4,"%d",FileStat.i304StatAllRoamFee);
	sprintf(pFileTail->sTotalCallNum4,"%d",FileStat.i304StatAllCallNum);
	sprintf(pFileTail->sTotalDuration4,"%d",FileStat.i304StatAllDuration);
	sprintf(pFileTail->sTotalTollFee5,"%d",FileStat.i305StatAllTollFee);
	sprintf(pFileTail->sTotalCallNum5,"%d",FileStat.i305StatAllCallNum);
	sprintf(pFileTail->sTotalDuration5,"%d",FileStat.i305StatAllDuration);
}

/*转换城市编码*/
int ToCityCode(char sAreaCode[],char sCityCode[])
{
	struct AreaCodeDescStruct *pTemp=NULL;
	
	if(strncmp(sProvCode,"088",3)==0&&strlen(sAreaCode)==0){
		strcpy(sCityCode,"880");
		return 0;
	}
	
	if(sAreaCode[0]=='0'){
		strcpy(sCityCode,sAreaCode);
		return 0;
	}
	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==NOTFOUND)
		return -1;
	strcpy(sCityCode,pTemp->sCityCode);
	if ( strcmp(sCityCode,"-1") == 0 ){
               strcpy(sCityCode,"841");
	}

	return 0;

}

void OutputTollFileHead(struct TollFileHeadStruct *pFileHead)
{
	char sRecord[200];
	int l=0;

	LeftPad(pFileHead->sFileFlag,3,'0');
	
	l+=sprintf(sRecord+l,"%-2s%-3s%3s%-5s",
		pFileHead->sFileType,pFileHead->sCompanyCode,
		pFileHead->sFileFlag ,pFileHead->sFileSeq);
	l+=sprintf(sRecord+l,"%-2s%-8s%-8s%-6s",
		pFileHead->sFileVersion,pFileHead->sFileCreateDate,
		pFileHead->sBeginDate,pFileHead->sBeginTime);
	l+=sprintf(sRecord+l,"%-8s%-6s%06d%015d",
		pFileHead->sEndDate,pFileHead->sEndTime,
		atoi(pFileHead->sTotalRecord),atoi(pFileHead->sTotalFee));
	l+=sprintf(sRecord+l,"%94s\r\n","");
	WriteFile(fp,sRecord,l);
}

void InsertTollFile(struct TollFileStatStruct *pTemp,
	struct TollFileStatStruct *pTollRecord)
{
	pTemp->i301TotalCallNum	+=pTollRecord->i301TotalCallNum	;
	pTemp->i301TotalDuration+=pTollRecord->i301TotalDuration;
	pTemp->i301TotalTollFee	+=pTollRecord->i301TotalTollFee	;
	pTemp->i302TotalCallNum	+=pTollRecord->i302TotalCallNum	;
	pTemp->i302TotalDuration+=pTollRecord->i302TotalDuration;
	pTemp->i302TotalTollFee	+=pTollRecord->i302TotalTollFee	;
	pTemp->i303TotalCallNum	+=pTollRecord->i303TotalCallNum	;
	pTemp->i303TotalDuration+=pTollRecord->i303TotalDuration;
	pTemp->i303TotalTollFee	+=pTollRecord->i303TotalTollFee	;
	pTemp->i304TotalCallNum	+=pTollRecord->i304TotalCallNum	;
	pTemp->i304TotalDuration+=pTollRecord->i304TotalDuration;
	pTemp->i304TotalTollFee	+=pTollRecord->i304TotalTollFee	;
	pTemp->i304TotalRoamFee	+=pTollRecord->i304TotalRoamFee	;
	pTemp->i305TotalCallNum	+=pTollRecord->i305TotalCallNum	;
	pTemp->i305TotalDuration+=pTollRecord->i305TotalDuration;
	pTemp->i305TotalTollFee	+=pTollRecord->i305TotalTollFee	;
}           

/*参数：外部要插入的结构，当前结点的数据区*/
int data_search_bintree_tollfile(void *pValue,void*pData)
{               
	struct TollFileStatStruct *pSource=(struct TollFileStatStruct *)pValue;
	struct TollFileStatStruct *pTarget=(struct TollFileStatStruct *)pData,
		Temp;
	int res;

	ToCityCode(pSource->sVisitAreaCode,Temp.sVisitAreaCode);
	ToCityCode(pSource->sOppAreaCode,  Temp.sOppAreaCode);
	
	res=0;	
	if((res=strcmp(Temp.sVisitAreaCode,pTarget->sVisitAreaCode))!=0)
		return res;
	if((res=strcmp(Temp.sOppAreaCode,pTarget->sOppAreaCode))!=0)
		return res;
	return res;
}               
                
void assign_insert_bintree_tollfile(void **ppData,void *pData)
{               
	struct TollFileStatStruct *pTemp;
	struct TollFileStatStruct *pTollRecord=(struct TollFileStatStruct*)pData;
	
	/*当第一次调用该函数（即创建结点的过程中），*ppData还没加载数据*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct TollFileStatStruct));
		ERROR_EXIT(pTemp==NULL,"分配TollFileStatStruct结构错误");
		bzero((void*)pTemp,sizeof(struct TollFileStatStruct));

		/*如果不存在该sVisitAreaCode与sOppAreaCode，定义结点的数据区*/
		/*做数据关联,生成结点的键值*/			
		ToCityCode(pTollRecord->sVisitAreaCode,pTemp->sVisitAreaCode);
		ToCityCode(pTollRecord->sOppAreaCode,pTemp->sOppAreaCode);
				
		pTemp->iTotalRecCnt=1;

		InsertTollFile(pTemp,pTollRecord);
		strcpy(pTemp->sMinStartTime,pTollRecord->sMinStartTime);
                strcpy(pTemp->sMaxStartTime,pTollRecord->sMaxStartTime);
                
		/*将定义好的结点数据区挂回结点上*/
		*ppData=(void*)pTemp;
                
		return;
	}       
	/*如果找到相同的键值的结点,根据对应visit_area_code,opp_area_code
	累加记费数,时长,费用*/
	pTemp=(*ppData);
	pTemp->iTotalRecCnt++;
	InsertTollFile(pTemp,pTollRecord);
			
	/*比较时间*/
	if(strcmp(pTemp->sMinStartTime,pTollRecord->sMinStartTime)>0) 
		strcpy(pTemp->sMinStartTime,pTollRecord->sMinStartTime);
	if(strcmp(pTemp->sMaxStartTime,pTollRecord->sMaxStartTime)<0) 
		strcpy(pTemp->sMaxStartTime,pTollRecord->sMaxStartTime);
}

int Unite(void **ppRoot)
{
	struct TollFileStatStruct *pTemp=(*ppRoot);
	if(pTemp!=NULL){
		if(InsertBin(&pFileRoot,(void *)pTemp,
			data_search_bintree_tollfile,
			assign_insert_bintree_tollfile)<0){
			WriteAlertMsg("生成BINTREE失败TOLLFILE");
			return -1;
		}
	}
	return 0;	
}

int OutputTollFileBody(void **ppRoot)
{
	struct TollFileStatStruct *pTemp=(*ppRoot);
	struct TollFileBodyStruct *pBody;
	char sRecord[200];
	int l;
	
	pBody=(struct TollFileBodyStruct *)
		malloc(sizeof(struct TollFileBodyStruct));
	ERROR_EXIT(pBody==NULL,"分配TollFileBodyStruct结构错误");
	

	if(pTemp!=NULL){
		/*
		ToCityCode(pTemp->sVisitAreaCode,pTemp->sVisitAreaCode);
		ToCityCode(pTemp->sOppAreaCode,pTemp->sOppAreaCode);
		*/
		strcpy(pBody->sVisitCityCode 	,pTemp->sVisitAreaCode);
		strcpy(pBody->sOutCityCode	,pTemp->sOppAreaCode);
		sprintf(pBody->sTollFee1	,"%d",pTemp->i301TotalTollFee);
		sprintf(pBody->sCallNum1	,"%d",pTemp->i301TotalCallNum);
		sprintf(pBody->sDuration1	,"%d",pTemp->i301TotalDuration);
		sprintf(pBody->sTollFee2	,"%d",pTemp->i302TotalTollFee);
		sprintf(pBody->sCallNum2	,"%d",pTemp->i302TotalCallNum);
		sprintf(pBody->sDuration2	,"%d",pTemp->i302TotalDuration);
		sprintf(pBody->sTollFee3	,"%d",pTemp->i303TotalTollFee);
		sprintf(pBody->sCallNum3	,"%d",pTemp->i303TotalCallNum);
		sprintf(pBody->sDuration3	,"%d",pTemp->i303TotalDuration);
		sprintf(pBody->sTollFee4	,"%d",pTemp->i304TotalTollFee);
		sprintf(pBody->sLocalFee4	,"%d",pTemp->i304TotalRoamFee);
		sprintf(pBody->sCallNum4	,"%d",pTemp->i304TotalCallNum);
		sprintf(pBody->sDuration4	,"%d",pTemp->i304TotalDuration);
		sprintf(pBody->sTollFee5	,"%d",pTemp->i305TotalTollFee);
		sprintf(pBody->sCallNum5	,"%d",pTemp->i305TotalCallNum);
		sprintf(pBody->sDuration5	,"%d",pTemp->i305TotalDuration);
		
		l=0;
		LeftPad(pBody->sVisitCityCode,3,'0');
		LeftPad(pBody->sOutCityCode,3,'0');
		l+=sprintf(sRecord+l,"%3s%3s",
			pBody->sVisitCityCode,pBody->sOutCityCode);
		l+=sprintf(sRecord+l,"%010d%010d%010d",
			atoi(pBody->sTollFee1),
			atoi(pBody->sCallNum1),atoi(pBody->sDuration1));
		l+=sprintf(sRecord+l,"%010d%010d%010d",
			atoi(pBody->sTollFee2),
			atoi(pBody->sCallNum2),atoi(pBody->sDuration2));
		l+=sprintf(sRecord+l,"%010d%010d%010d", 
			atoi(pBody->sTollFee3),
			atoi(pBody->sCallNum3),atoi(pBody->sDuration3));
		l+=sprintf(sRecord+l,"%010d%010d%010d%010d",    
			atoi(pBody->sTollFee4),atoi(pBody->sLocalFee4),
			atoi(pBody->sCallNum4),atoi(pBody->sDuration4));
		l+=sprintf(sRecord+l,"%010d%010d%010d\r\n",                     
			atoi(pBody->sTollFee5),
			atoi(pBody->sCallNum5),atoi(pBody->sDuration5));
			
		WriteFile(fp,sRecord,l);
	}
	return 0;   
}

void OutputTollFileTail(struct TollFileTailStruct *pFileTail)
{
	char sRecord[200];
	int l=0;
		
	l+=sprintf(sRecord+l,"%6s","");
	l+=sprintf(sRecord+l,"%010d%010d%010d",
		atoi(pFileTail->sTotalTollFee1),atoi(pFileTail->sTotalCallNum1),
		atoi(pFileTail->sTotalDuration1));
	l+=sprintf(sRecord+l,"%010d%010d%010d",
		atoi(pFileTail->sTotalTollFee2),atoi(pFileTail->sTotalCallNum2),
		atoi(pFileTail->sTotalDuration2));
	l+=sprintf(sRecord+l,"%010d%010d%010d",
		atoi(pFileTail->sTotalTollFee3),atoi(pFileTail->sTotalCallNum3),
		atoi(pFileTail->sTotalDuration3));
	l+=sprintf(sRecord+l,"%010d%010d%010d%010d",
		atoi(pFileTail->sTotalTollFee4),atoi(pFileTail->sTotalLocalFee4),
		atoi(pFileTail->sTotalCallNum4),atoi(pFileTail->sTotalDuration4));
	l+=sprintf(sRecord+l,"%010d%010d%010d\r\n",
		atoi(pFileTail->sTotalTollFee5),atoi(pFileTail->sTotalCallNum5),
		atoi(pFileTail->sTotalDuration5));
	WriteFile(fp,sRecord,l);
}       

int main(int argc,char *argv[])
{          
	int iCount=0;
	char sBaseName[128],sFileName[256],sFileType[4],
		sFileSeq[6],sPreName[256],sUserType[2];
	        
        struct SttTicketStruct Temp;
        struct SttTicketStructIn TempIn;
        struct TollFileHeadStruct *pFileHead;
	struct TollFileTailStruct *pFileTail;
	
	if(argc!=3){
		printf("用法：%s tablename filename.\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);
	IniConnect("dataconnstr");
	
	bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));   
	
	strcpy(sBaseName,argv[2]);
	/*校验文件名*/
	strncpy(sFileType,sBaseName,3);
	sFileType[3]=0;
	strcpy(sFileSeq,"00");
	strncpy(sFileSeq+2,sBaseName+9,3);
	sFileSeq[5]=0;
		
	if(strncmp(sFileType,"CTI",3)==0||strncmp(sFileType,"TTI",3)==0)
		strcpy(sUserType,"G");
	else if(strncmp(sFileType,"JTI",3)==0||strncmp(sFileType,"QTI",3)==0)
		strcpy(sUserType,"C");
	else{
		printf("please input a correct filetype\n");
		return -1;
	}
	strcpy(sNetType,sUserType);

	/*该处定义select条件*/                         
	sprintf(TempIn.sCondition,"\n\
		WHERE TICKET_TYPE_ID IN (301,302,303,304,305) \n\
			AND (substr(MSISDN,1,2)!='13' OR \n\
			(substr(MSISDN,1,2)='13' AND ROAM_TYPE IN ('1','2'))) \n\
			AND USER_TYPE='%s'",sUserType);
			
	strcpy(TempIn.sTableName,argv[1]);
        Upper(TempIn.sTableName);  
	GetProvCode(sProvCode);
	
	pFileHead=(struct TollFileHeadStruct *)
		malloc(sizeof(struct TollFileHeadStruct));
	ERROR_EXIT(pFileHead==NULL,"分配TollFileHeadStruct结构错误");
	
	pFileTail=(struct TollFileTailStruct *)
		malloc(sizeof(struct TollFileTailStruct)); 
	ERROR_EXIT(pFileTail==NULL,"分配TollFileTailStruct结构错误");
	
	strcpy(sPreName,"");
	strcpy(sFileName,"");
	
	TempIn.iBufEmpty=TRUE;
        TempIn.iFirstFlag=TRUE;
        
        /*取出表中记录加载二叉树，构造长途文件体记录结构*/
        while(EGetSttTicketToStruct(&Temp,&TempIn)){
		iCount++;
                if(InsertBin(&pRoot,(void *)&Temp,
			data_search_bintree_tollrecord,
			assign_insert_bintree_tollrecord)<0){
			WriteAlertMsg("生成BINTREE失败TOLLRECORD");
			return -1;
		}
        }
	              
        /*对各结点数据做调整*/
        TravelBin(pRoot,AdjustTollNode);
        
        /*把重复记录合并*/
        TravelBin(pRoot,Unite);
        
        /*遍历树，汇总*/
        bzero((void*)&FileStat,sizeof(struct StatAllStruct));
        strcpy(FileStat.sFirstStartTime	,"999999999999");
	strcpy(FileStat.sLastStartTime 	,"000000000000"); 
        TravelBin(pFileRoot,StatAll);
        
	GenTollFileHead(sProvCode,sFileType,sFileSeq,
		FileStat.sFirstStartTime,FileStat.sLastStartTime,pFileHead);
	GenTollFileTail(pFileTail);    
	
	if((fp=fopen(sBaseName,"w"))==NULL) return -1;
	
	OutputTollFileHead(pFileHead);	
	TravelBin(pFileRoot,OutputTollFileBody);
	OutputTollFileTail(pFileTail);
	
	printf("文件 %s 生成完毕.\n",sBaseName);
	WriteProcMsg("文件 %s 生成完毕.",sBaseName);
	
	fclose(fp);
	DisconnectDatabase();
	return 0;
}
