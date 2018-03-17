#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bintree.h>
#include <wwfile.h>

#include "user_ticket.h"

struct UserAcct{
	struct UserAcct *pNext;
	char sCallingNbr[30];
	int iTicketTypeID;
	LONGINT	iRoamFee;
	LONGINT	iTollFee;
	LONGINT	iAddFee;
};

struct FUserAcct{
	char sCallingNbr[29];
	char sTicketTypeID[4];
	char sRoamFee[16];
	char sTollFee[16];
	char sAddFee[16];
};

struct	FileControlStruct *pOutPutList=NULL;

void mvitem_mfuseracct(struct UserAcct *pi,struct FUserAcct *po)
{
	char sTemp[128];
	memset((void*)po,' ',sizeof(struct FUserAcct));
	
	strncpy(po->sCallingNbr,pi->sCallingNbr,strlen(pi->sCallingNbr));
		
	sprintf(sTemp,"%04d",pi->iTicketTypeID);
	strncpy(po->sTicketTypeID,sTemp,4);
	
	sprintf(sTemp,"%016d",pi->iRoamFee);
	strncpy(po->sRoamFee,sTemp,16);
	
	sprintf(sTemp,"%016d",pi->iTollFee);
	strncpy(po->sTollFee,sTemp,16);
	
	sprintf(sTemp,"%016d",pi->iAddFee);
	strncpy(po->sAddFee,sTemp,16);
}

int node_output_ticket_e(void **ppHead)
{
	struct	FileControlListStruct *p=NULL;
	struct UserAcct *ptHead=(*ppHead),*pTemp;
	char sTemp[sizeof(struct FUserAcct)];
	
	mvitem_mfuseracct(ptHead,(struct FUserAcct *)sTemp);
	item2list(&pOutPutList,(void *)sTemp,sizeof(struct FUserAcct));
	/*
	printf("%s,%d,%d,%d,%d\n%s\n",ptHead->sCallingNbr,
	                          ptHead->iTicketTypeID,
	                          ptHead->iRoamFee,ptHead->iTollFee,ptHead->iAddFee,
	                          sTemp);
	*/
	return 0;	
}

int data_search_bintree_data_ticket_e(void *pValue,void *pData)
{
	
        struct UserAcct *pSource=pValue;
        struct UserAcct *pTarget=pData;
	int res=0;
	
/*���ݱȽϲ���*/
	if ((res=pTarget->iTicketTypeID-pSource->iTicketTypeID)!=0)return res;
/*	if ((res=pData->iRoamFee-pValue->iRoamFee)!=0)return res;
	if ((res=pData->iTollFee-pValue->iTollFee)!=0)return res;
	if ((res=pData->iAddFee-pValue->iAddFee)!=0)return res;	
*/	
	return strcmp(pTarget->sCallingNbr,pSource->sCallingNbr);
}

void assign_insert_bintree_data_ticket_e(void **pptHead,void *pData)
{
        struct UserAcct *pTarget=(struct UserAcct *)(*pptHead);
        struct UserAcct *pSource=(struct UserAcct *)pData;
	if (*pptHead==NULL)
        	InsertList((LIST**)pptHead,(LIST*)pData);
	else{
		pTarget->iRoamFee+=pSource->iRoamFee;
		pTarget->iTollFee+=pSource->iTollFee;
		pTarget->iAddFee +=pSource->iAddFee ;	
	}        	
}

/*׼������*/	
int GetFileList(char sSourcePath[],char sFilter[],
	struct FileControlStruct **pptHead)
{
	char sPath[256],sCtlPath[256],sCommand[256];

	*pptHead=NULL;

	if(IsDir(sSourcePath)==false){
		printf("·��%s��Ч.\n",sSourcePath);
		return -1;
	}
	RegularDir(sSourcePath);

	sprintf(sCommand,"ls -rt %s | sed -n /%s/p",sSourcePath,sFilter);
	
	if(exec2list(sCommand,pptHead)!=0){
		printf("ִ��%s����ʧ��.\n",sCommand);
		return -1;
	}
	
	return 0;
}

int main( int argc, char **argv )
{
	int l,iCnt=0;
	char sFileName[256],sNow[15],sOutputFn[256],outputPath[256],inputPath[256],sFilter[32];
	struct FileControlStruct *InputFileList=NULL,*ptPre,*ptCur;
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct DataTicketBStruct Temp;
	struct FDataTicketBStruct *pFTicket;
	struct UserAcct *pUserAcct=NULL;
	
       	BINTREE *pBinTree=NULL;
       	
	if(argc!=4){
		printf("Usage %s inputPath outputPath Filter.\n",argv[0]);
		return -1;
	}    	
	
	strcpy(inputPath,argv[1]);
	strcpy(outputPath,argv[2]);
	strcpy(sFilter,argv[3]);
	
	if(IsDir(outputPath)==FALSE){
		printf("����쳣Ŀ¼%s��Ч.\n",outputPath);
		return -1;
	}
	RegularDir(outputPath);		
	
	if(IsDir(inputPath)==FALSE){
		printf("����Ŀ¼%s��Ч.\n",inputPath);
		return -1;
	}
	RegularDir(inputPath);
	
	if(GetFileList(inputPath,sFilter,&InputFileList)<0){
		printf("�����ļ��б�ʧ��.\n");
		return -1;
	}
	
	ptCur=InputFileList;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		strncpy(sFileName,(char*)(ptPre->pData),ptPre->iLen);
		sFileName[ptPre->iLen]=0;
		TrimAll(sFileName);		
		if(strlen(sFileName)<=1) continue;

		/*���ļ����ݵ��ú������ص��ڴ�*/
		if((l=TxtFileToList(sFileName,&ptHead))<0){
			printf("�����ļ�%s���ڴ�ʧ��.\n",sFileName);
			WriteErrStackAlert();
			return -1;
		}
		while( ptHead != NULL ){
			
			pTemp = ptHead;
			ptHead = ptHead->pNext;
			
			/*ת��Ϊ�ṹ*/
			mvitem_fmdataticketb(pTemp->pData,&Temp);
			
	                if((pUserAcct=(struct UserAcct *)
	                	malloc(sizeof(struct UserAcct)))==NULL){
	                        printf("error Malloc UserAcct.\n");
	                        return -1;
	                }
	                
	                strcpy(pUserAcct->sCallingNbr,Temp.sCallingNbr);
	                pUserAcct->iTicketTypeID = Temp.iTicketTypeID;
	                pUserAcct->iRoamFee = Temp.iRoamFee;       
	                pUserAcct->iTollFee = Temp.iTollFee;       
	                pUserAcct->iAddFee  = Temp.iAddFee ;	
	                
	                
			/*�����û����룬ticket_type_id����bintree*/
			InsertBin(&pBinTree,pUserAcct,data_search_bintree_data_ticket_e,
				assign_insert_bintree_data_ticket_e);		
		}
	}
	
	/*����bintree,ת����ʽ,���bintree*/	
	TravelBin(pBinTree,node_output_ticket_e);
	
	
	GetHostTime(sNow);
	sprintf(sOutputFn,"MA%s.DAT",sNow);	
	if( list2fileln(&pOutPutList,sOutputFn)<0 ){
		printf("д����ļ�ʧ��.\n");
		return -1;
	}
	
	printf("�����ļ����ɳɹ���\n");

	return 0;
}
