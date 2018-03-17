#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <bintree.h>
#include <wwcoding.h>

#include <stt_ticket.h>

struct CommKeyStruct 
{
	struct CommKeyStruct  *pNext;
	char sKeyStr[30];
	int iKeyInt;
};

struct CompressRecordStruct
{
	char cStartHour;
	char sMiss[2];
	char sDuration[2];
	char cMsc;
	char sTrunkIn[2];
	char sTrunkOut[2];
	char sLac[2];
	char sCellID[2];
	char cCallType;
	char sMsisdn[8];
	char sOtherParty[12];
};
BINTREE *pMscBin=NULL;
BINTREE *pTrunkBin=NULL;
BINTREE *pLacBin=NULL;
BINTREE *pCellIDBin=NULL;
BINTREE *pStartHourBin=NULL;
int iMscID=0,iTrunkID=0,iLacID=0,iCellID=0,iStartHourID=0;
FILE *fpParam=NULL;

int print_param_node(void **ppData)
{
	struct CommKeyStruct *pTemp;
	
	pTemp=(struct CommKeyStruct *)(*ppData);

	fprintf(fpParam,"%s\t%d\n",pTemp->sKeyStr,pTemp->iKeyInt);
	
	return 0;
}
int PrintParamAll(char sPath[])
{
	char sFileName[256];
	
	sprintf(sFileName,"%sMSC.txt",sPath);
	if((fpParam=fopen(sFileName,"w"))==NULL) return -1;
	TravelBin(pMscBin,print_param_node);
	DestroyBin(pMscBin);
	fclose(fpParam);
	

	sprintf(sFileName,"%sTRUNK.txt",sPath);
	if((fpParam=fopen(sFileName,"w"))==NULL) return -1;
	TravelBin(pTrunkBin,print_param_node);
	DestroyBin(pTrunkBin);
	fclose(fpParam);


	sprintf(sFileName,"%sLAC.txt",sPath);
	if((fpParam=fopen(sFileName,"w"))==NULL) return -1;
	TravelBin(pLacBin,print_param_node);
	DestroyBin(pLacBin);
	fclose(fpParam);


	sprintf(sFileName,"%sCELL_ID.txt",sPath);
	if((fpParam=fopen(sFileName,"w"))==NULL) return -1;
	TravelBin(pCellIDBin,print_param_node);
	DestroyBin(pCellIDBin);
	fclose(fpParam);

	sprintf(sFileName,"%sSTARTHOUR.txt",sPath);
	if((fpParam=fopen(sFileName,"w"))==NULL) return -1;
	TravelBin(pStartHourBin,print_param_node);
	DestroyBin(pStartHourBin);
	fclose(fpParam);
	
	return 0;
}
int data_search_bintree_comm_key_e(void *pValue,void*pData)
{
	struct CommKeyStruct *pSource=(struct CommKeyStruct *)pValue;
	struct CommKeyStruct *pTarget=(struct CommKeyStruct *)pData;

	return strcmp(pSource->sKeyStr,pTarget->sKeyStr);
}
int AddCommKey(char sKeyStr[],BINTREE **pptHead,int *piID)
{
	struct CommKeyStruct Temp,*p;
	
	strcpy(Temp.sKeyStr,sKeyStr);

	if(SearchBin(*pptHead,(void*)&Temp,
		data_search_bintree_comm_key_e,(void*)&p)==FOUND)
		return p->iKeyInt;
	
	if((p=malloc(sizeof(struct CommKeyStruct)))==NULL) return -1;
	
	p->pNext=NULL;
	strcpy(p->sKeyStr,sKeyStr);
	p->iKeyInt=*piID;
	(*piID)++;
	if(InsertBin(pptHead,(void*)p,data_search_bintree_comm_key_e,
		assign_insert_bintree)<0) return -1;
	return p->iKeyInt;
}
int mvprep2compressrecord(struct PrepTicketStruct *pi,struct CompressRecordStruct *po)
{
	int k;
	char sStartHour[11];

	po->cCallType=atoi(pi->sCallType);
	
	memset((void*)(po->sMsisdn),0xff,8);
	memset((void*)(po->sOtherParty),0xff,12);
	k=asc_dec2hbcd(pi->sMsisdn,(unsigned char*)po->sMsisdn);
	k=asc_dec2hbcd(pi->sOtherParty,(unsigned char*)po->sOtherParty);
	
	strncpy(sStartHour,pi->sStartTime,10);sStartHour[10]=0;
	
	k=AddCommKey(sStartHour,&pStartHourBin,&iStartHourID);
	if(k<0||k>255) return -1;
	*((unsigned char*)&(po->cStartHour))=	k;
	
	k=asc_dec2hbcd(pi->sStartTime+10,(unsigned char*)po->sMiss);
	
	k=atoi(pi->sDuration);
	if(k>65535) k=0;
	*((unsigned short*)(po->sDuration))=	k;
	
	k=AddCommKey(pi->sMsc,&pMscBin,&iMscID);
	if(k<0||k>255) return -1;
	*((unsigned char*)&(po->cMsc))=	k;
	
	k=AddCommKey(pi->sTrunkIn,&pTrunkBin,&iTrunkID);
	if(k<0||k>65535) return -1;
	*((unsigned short*)(po->sTrunkIn))=	k;
	
	k=AddCommKey(pi->sTrunkOut,&pTrunkBin,&iTrunkID);
	if(k<0||k>65535) return -1;
	*((unsigned short*)(po->sTrunkOut))=	k;


	k=AddCommKey(pi->sLac,&pLacBin,&iLacID);
	if(k<0||k>65535) return -1;
	*((unsigned short*)(po->sLac))=	k;

	k=AddCommKey(pi->sCellID,&pCellIDBin,&iCellID);
	if(k<0||k>65535) return -1;
	*((unsigned short*)(po->sCellID))=	k;

	return 0;
}
int TransRecord(struct PrepTicketStruct *pi,struct CompressRecordStruct *p)
{
	int k;
	char sTemp[50],*pc;
	
	pc=&(p->cCallType);

	sTemp[0]=p->cCallType+'0'; sTemp[1]=0;
	strcat(sTemp,pi->sMsisdn);strcat(sTemp,"F");
	strcat(sTemp,pi->sOtherParty);strcat(sTemp,"F");

	k=asc_hex2hbcd(sTemp,(unsigned char*)pc);
	pc[k]=0xff;
	
	return 20-k;
}
int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char sPath[256],sFileName[256],sCommand[256],sPreName[256];
	static int iCount=0,k,iSeq=0;
        
        struct CompressRecordStruct Rec;
        struct PrepTicketStruct Temp;
        struct PrepTicketStructIn TempIn;

	if(argc!=3){
		printf("用法：%s path tablename.\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);
        IniConnect("dataconnstr");
        
        bzero((void*)&TempIn,sizeof(struct PrepTicketStructIn));
	strcpy(TempIn.sCondition,"");
	
        strcpy(sPath,argv[1]);
        strcpy(TempIn.sTableName,argv[2]);
	RegularDir(sPath);
	Upper(TempIn.sTableName);
	
	strcpy(sPreName,"");
	strcpy(sFileName,"");
	
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;
        	
        while(EGetPrepTicketToStruct(&Temp,&TempIn)){
        
        	if(strcmp(Temp.sCallType,"01")!=0&&
        		strcmp(Temp.sCallType,"02")!=0&&
        		strcmp(Temp.sCallType,"03")!=0&&
        		strcmp(Temp.sCallType,"07")!=0&&
        		strcmp(Temp.sCallType,"08")!=0)	continue;
        	
		if(iCount%10000==0&&iCount!=0){
			printf("表%s导出话单话单数%d.\n",TempIn.sTableName,iCount);
			WriteProcMsg("表%s导出话单话单数%d.",TempIn.sTableName,iCount);
		}
		if(iCount%20000000==0){
			if(fp!=NULL)fclose(fp);
			if(strcmp(sPreName,"")!=0){
				sprintf(sCommand,"compress %s",sPreName);
				system(sCommand);
				printf("文件 %s 生成完毕.\n",sPreName);
				WriteProcMsg("文件 %s 生成完毕.",sPreName);
			}
			sprintf(sFileName,"%s%s.%03d",
				sPath,TempIn.sTableName,iSeq);
			strcpy(sPreName,sFileName);
			if((fp=fopen(sFileName,"w"))==NULL){
				printf("打开文件%s失败.\n",sFileName);
				exit(1);
			}
			iSeq++;
		}
		iCount++;
		
		if(mvprep2compressrecord(&Temp,&Rec)<0){
			printf("话单结构不满足要求.\n");
			return -1;
		}
		k=TransRecord(&Temp,&Rec);
		
		fwrite((void*)&Rec,1,sizeof(struct CompressRecordStruct)-k,fp);
        }
	if(fp!=NULL)fclose(fp);
	if(strcmp(sFileName,"")!=0){
		sprintf(sCommand,"compress %s",sFileName);
		system(sCommand);
		printf("文件 %s 生成完毕.\n",sFileName);
		WriteProcMsg("文件 %s 生成完毕.",sFileName);
	}
        
	printf("输出联通完毕，话单总数%d.\n",iCount);
	WriteProcMsg("表%s生成文件完毕,话单总数%d.",TempIn.sTableName,iCount);

       if(PrintParamAll(sPath)<0)	printf("输出参数表失败.\n");
	else 	printf("输出参数表成功.\n");

        DisconnectDatabase();

	return 0;
}

