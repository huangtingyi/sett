#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <bintree.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

int igSeq=-1;
char sgDate[15];
char sNorRes[2048],sErrRes[2048];

int InitPickLog2List(char sBeginDate[],char sEndDate[],char sSourceID[],
	int *piMaxSeq,int *piMinSeq,char sMaxDate[15],char sMinDate[15],
	struct PickLogStruct **pptHead)
{
	int iCnt=0;
	char sFileType[3];
	struct PickLogStruct Temp,*pTemp;
	struct PickLogStructIn TempIn;
	
	*piMaxSeq=-1;
	*piMinSeq=999999999;
	strcpy(sMinDate,"20300101000000");
	strcpy(sMaxDate,"19900101000000");
	
	*pptHead=NULL;
	bzero((void*)&TempIn,sizeof(struct PickLogStructIn));
	sprintf(TempIn.sTableName,"PICK_LOG");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
	
	if(strlen(sSourceID)==9){
		strncpy(sFileType,sSourceID+7,2);sFileType[2]=0;
		sSourceID[6]=0;
		sprintf(TempIn.sCondition,"WHERE \n\
			DEAL_END_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
			DEAL_END_DATE<to_date('%s','yyyymmddhh24miss') AND\n\
			SOURCE_ID='%s'AND SUBSTR(FILE_NAME,6,2)='%s'\n\
			",sBeginDate,sEndDate,sSourceID,sFileType);
	}
	else{
		sprintf(TempIn.sCondition,"WHERE \n\
			DEAL_END_DATE>=to_date('%s','yyyymmddhh24miss') AND\n\
			DEAL_END_DATE<to_date('%s','yyyymmddhh24miss') AND\n\
			SOURCE_ID='%s'",sBeginDate,sEndDate,sSourceID);
	}
	
	while(EGetPickLogToStruct(&Temp,&TempIn)){
		
		if(strcmp(Temp.sDealEndDate,sMinDate)<0){
			strcpy(sMinDate,Temp.sDealEndDate);
			*piMinSeq=Temp.iSeq;
		}
		if(strcmp(Temp.sDealEndDate,sMaxDate)>0){
			strcpy(sMaxDate,Temp.sDealEndDate);
			*piMaxSeq=Temp.iSeq;
		}
		
		iCnt++;
		if((pTemp=malloc(sizeof(struct PickLogStruct)))==NULL){
			printf("�����ڴ�PickLogStruct����\n");
			return -1;
		}
		memcpy((void*)pTemp,(void*)&Temp,sizeof(struct PickLogStruct));
		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	return iCnt;
}
/*�������ⲿҪ����Ľṹ����ǰ����������*/
int data_search_bintree_pick_log_e(void *pValue,void*pData)
{               
	struct PickLogStruct *pSource=(struct PickLogStruct *)pValue;
	struct PickLogStruct *pTarget=(struct PickLogStruct *)pData;

	return pSource->iSeq-pTarget->iSeq;
}
int key_comp_pick_log_e(LIST *pValue,LIST *pData)
{
        struct PickLogStruct *pSource=(struct PickLogStruct *)pValue;
        struct PickLogStruct *pTarget=(struct PickLogStruct *)pData;
        
        return strcmp(pSource->sDealEndDate,pTarget->sDealEndDate);
        
}
void assign_insert_bintree_pick_log_e(void **pptHead,void *pData)
{
        InsertListSort((LIST**)pptHead,(LIST*)pData,key_comp_pick_log_e);
}
int node_print_pick_log_e(void **ppHead)
{
	
	struct PickLogStruct *ptHead=(*ppHead),*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		printf("%s,%d,%s.\n",
			pTemp->sDealEndDate,pTemp->iSeq,pTemp->sFileName);
		
	}
	return 0;
}
int GetMyNextSeq(int i,int iMinSeq,int iMaxSeq)
{
	if(i==iMaxSeq) i=iMinSeq;
	else i++;
	return i;
}
int GetMyPreSeq(int i,int iMinSeq,int iMaxSeq)
{
	if(i==iMinSeq) i=iMaxSeq;
	else i--;
	return i;
}
int SearchPickSeq(BINTREE *pRoot,int iSeq,char sCurDate[],time_t diff,
	struct PickLogStruct **pptCur)
{
	time_t tCur,tPre,tCurDate;
	struct PickLogStruct Temp,*ptHead,*pTemp,*ptCur;
	
	bzero((void*)&Temp,sizeof(struct PickLogStruct));
	
	Temp.iSeq=iSeq;

	if(SearchBin(pRoot,(void*)&Temp,data_search_bintree_pick_log_e,
		(void**)&ptHead)==NOTFOUND) return NOTFOUND;
	
	ptCur=NULL;
	/*�ҵ�һ��ʱ����ӽ�sCurDate�ļ�¼,��Ϊ���־�ļ�¼*/
	tCurDate=tGetTime(sCurDate);
	tPre=86400000;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*����Ѿ���ʶ���˾Ͳ���Ҫ��*/
		if(strcmp(pTemp->sState,"O")==0) continue;
		
		tCur=tGetTime(pTemp->sDealEndDate)-tCurDate;
		if(tCur<0) tCur=-tCur;
		
		if(tCur<tPre){
			tPre=tCur;
			ptCur=pTemp;
		}
	}			

	if(ptCur==NULL) return NOTFOUND;
	
	if(diff!=-1&&tPre>diff) return NOTFOUND;

	*pptCur=ptCur;

	return FOUND;
}
void OutputSeqStr(int iBgn,int iEnd,char sRes[])
{
	char pin[2],sTemp[40];

	if(sRes[0]==0)	strcpy(pin,"");
	else		strcpy(pin,",");

	
	if(iBgn==iEnd)	sprintf(sTemp,"%s%d",pin,iBgn);
	else		sprintf(sTemp,"%s%d-%d",pin,iBgn,iEnd);
				
	strcat(sRes,sTemp);
}
int node_no_match_print_e(void **ppHead)
{
	struct PickLogStruct *ptHead=(*ppHead),*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(strcmp(pTemp->sState,"O")==0) continue;
		
		OutputSeqStr(pTemp->iSeq,pTemp->iSeq,sErrRes);
	}
	return 0;
}

int node_no_match_cnt_e(void **ppHead)
{
	int iCnt=0;
	struct PickLogStruct *ptHead=(*ppHead),*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(strcmp(pTemp->sState,"O")==0) continue;
		
		igSeq=pTemp->iSeq;
		strcpy(sgDate,pTemp->sDealEndDate);

		iCnt++;
	}
	return iCnt;
}

/*������С������SEQ*/
void AdjustMinMaxSeq(BINTREE *pRoot,int iMinSeq,int iMaxSeq,
	int *piMaxSeq1,int *piMinSeq1,char sMaxDate[15],char sMinDate[15])
{
	int i;
	struct PickLogStruct *pTemp;
	
	i=*piMinSeq1;
	while(1){
		i=GetMyPreSeq(i,iMinSeq,iMaxSeq);
		if(SearchPickSeq(pRoot,i,sMinDate,(time_t)3600,&pTemp)
			==NOTFOUND) break;
		strcpy(sMinDate,pTemp->sDealEndDate);
		*piMinSeq1=i;
	}
	i=*piMaxSeq1;
	while(1){
		i=GetMyNextSeq(i,iMinSeq,iMaxSeq);
		if(SearchPickSeq(pRoot,i,sMaxDate,(time_t)3600,&pTemp)
			==NOTFOUND) break;
		strcpy(sMaxDate,pTemp->sDealEndDate);
		*piMaxSeq1=i;
	}
}
/*����Ŀ���ļ�*/
int main(int argc,char *argv[])
{
	BINTREE *pRoot=NULL;
	int iMaxSeq=0,iMinSeq=0,iMaxSeq1=0,iMinSeq1=0,iCnt=0,i,iErrCnt=0;
	int iNormalBgn,iNormalEnd,iErrBgn,iErrEnd;
	struct PickLogStruct *ptLkHead=NULL,*ptHead,*pTemp;
	char sSourceID[20],sCurDate[15],sTemp[128];
	char sBeginDate[15],sEndDate[15],sMinDate[15],sMaxDate[15];
					
	if(argc !=5 ){
		printf("Usage %s sourceid date minseq maxseq.\n",argv[0]);
		printf("date����˵��:\n");
		printf("	Ddate1date2 Ҫ���date1��date2,yyyymmdd��ʽ\n");
		printf("	-n 	����date����,�õ�ǰϵͳʱ����\n");
		printf("	date 	Ҫ�������,yyyymmdd��ʽ\n");
		return -1;		
	}
	
/*��ʼ����������*/
	strcpy(sSourceID,argv[1]);	
	strcpy(sTemp,argv[2]);

/*�������ڲ���*/
	if(strstr(sTemp,"-n")!=NULL){
		GetHostTime(sBeginDate);sBeginDate[8]=0;
		strcpy(sEndDate,sBeginDate);
	}
	else if(strncmp(sTemp,"D",1)==0){
		strncpy(sBeginDate,sTemp+1,8);sBeginDate[8]=0;
		strncpy(sEndDate,sTemp+9,8);sEndDate[8]=0;
	}
	else{
		strncpy(sBeginDate,sTemp,8);sBeginDate[8]=0;
		strcpy(sEndDate,sBeginDate);
	}
	strcat(sBeginDate,"000000");
	strcat(sEndDate,"000000");AddDates(sEndDate,1);

	iMinSeq=atoi(argv[3]);
	iMaxSeq=atoi(argv[4]);
	
/**�������Ϸ���*******/
	if(strcmp(sEndDate,sBeginDate)<=0){
		printf("�������ڱ��������ʼ����.\n");
		return -1;
	}
	if(iMaxSeq<=iMinSeq)	{
		printf("������кŲ������������С���кŲ���.\n");
		return -1;
	}
	
	if(ConnectDataDB()<0){
		printf("�޷��������ݿ�.\n");
		return -1;
	}
/*���ش�������ݵ��ڴ�*/
	if((iCnt=InitPickLog2List(sBeginDate,sEndDate,sSourceID,
		&iMaxSeq1,&iMinSeq1,sMaxDate,sMinDate,&ptLkHead))<0)return -1;
	
	DisconnectDatabase();
	
	if(iCnt==0){
		printf("��ʱ���������.\n");
		return -1;
	}

	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(InsertBin(&pRoot,(void*)pTemp,
			data_search_bintree_pick_log_e,
			assign_insert_bintree_pick_log_e)<0){
			printf("����ƽ�������ʧ��.\n");
			return -1;
		}
	}

/*����һ����С������SEQ��һСʱ�ڵķ�ת���*/
	AdjustMinMaxSeq(pRoot,iMinSeq,iMaxSeq,&iMaxSeq1,&iMinSeq1,
		sMaxDate,sMinDate);

/*��һ��ѭ�������еĶ�����ӡ����*/
/*	TravelBin(pRoot,node_print_pick_log_e);*/

/*ȡ�ÿ�ʼ�ͽ�����SEQ*/
	iErrCnt=0;
	strcpy(sNorRes,"");strcpy(sErrRes,"");
	iNormalBgn=iNormalEnd=iErrBgn=iErrEnd=-1;
next_abc:
	i=iMinSeq1;
	strcpy(sCurDate,sMinDate);

	while(1){
	/*����ҵ���һ��SEQ*/
		if(SearchPickSeq(pRoot,i,sCurDate,(time_t)-1,&pTemp)==FOUND){

			strcpy(pTemp->sState,"O");/*��һ����־*/
			strcpy(sCurDate,pTemp->sDealEndDate);
			
			if(iNormalBgn==-1) iNormalBgn=i;
			iNormalEnd=i;

			if(iErrBgn!=-1){/*����д��������������*/
				OutputSeqStr(iErrBgn,iErrEnd,sErrRes);
				iErrBgn=iErrEnd=-1;
				iErrCnt++;
			}
			
		}
		else{/*����Ҳ���*/
			if(iErrCnt>10){
				printf("��SOURCE_ID=%s��SEQ�����쳣.\n",sSourceID);
				return -1;
			}
			if(iErrBgn==-1)	iErrBgn=i;
			iErrEnd=i;

			if(iNormalBgn!=-1){/*����д��������������*/
				OutputSeqStr(iNormalBgn,iNormalEnd,sNorRes);
				iNormalBgn=iNormalEnd=-1;
			}
		}
		/*����Ѿ������һ�������OK*/
		if(i==iMaxSeq1&&strcmp(sCurDate,sMaxDate)==0){
			
			if(iNormalBgn!=-1){/*����д��������������*/
				OutputSeqStr(iNormalBgn,iNormalEnd,sNorRes);
				iNormalBgn=iNormalEnd=-1;
			}
			break;
		}
		i=GetMyNextSeq(i,iMinSeq,iMaxSeq);
	}
	
	iCnt=TravelBin(pRoot,node_no_match_cnt_e);
	if(iCnt>100){
		iMinSeq1=iMaxSeq1=igSeq;
		strcpy(sMaxDate,sgDate);strcpy(sMinDate,sgDate);

		AdjustMinMaxSeq(pRoot,iMinSeq,iMaxSeq,
			&iMaxSeq1,&iMinSeq1,sMaxDate,sMinDate);
		goto next_abc;
	}

/*��һ��ѭ����δƥ��Ķ���ƴ��sErrRes��*/
	TravelBin(pRoot,node_no_match_print_e);
	
	printf("%s\t%s\t%s\tУ����\n",sSourceID,sNorRes,sErrRes);

	return 0;
}

