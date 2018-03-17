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
	char sKeyStr[60];
	int iKeyInt;
};

struct CompressRecordStruct
{
	char cLen;
	char sStartTime[6];
	char sDuration[2];
	char sLocation[2];
	char sCallInfo[40];
};


BINTREE *pLocationBin=NULL;
int iLocationID=0;
FILE *fpParam=NULL;

int print_param_node(void **ppData)
{
	struct CommKeyStruct *pTemp;
	
	pTemp=(struct CommKeyStruct *)(*ppData);

	fprintf(fpParam,"%s\t%d\n",pTemp->sKeyStr,pTemp->iKeyInt);
	
	return 0;
}
int PrintLocation(char sLocationName[])
{
	
	if((fpParam=fopen(sLocationName,"w"))==NULL) return -1;
	TravelBin(pLocationBin,print_param_node);
	DestroyBin(pLocationBin);
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
int InitCommKeyTree(BINTREE **pptHead,char sFileName[])
{

	int iMaxID=0;
	char	sTemp[1024],sID[256],sKeyStr[256];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL,*ptLkHead=NULL;
	struct CommKeyStruct *p;

	*pptHead=NULL;

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;

	ptLkHead=ptHead;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		TrimAll(sTemp);

		GetSepStr(sTemp,'\t',0,sKeyStr);AllTrim(sKeyStr);
		GetSepStr(sTemp,'\t',1,sID);AllTrim(sID);

		if((p=malloc(sizeof(struct CommKeyStruct)))==NULL) return -1;
		p->pNext=NULL;
		strncpy(p->sKeyStr,sKeyStr,59);
		p->sKeyStr[59]=0;AllTrim(p->sKeyStr);
		p->iKeyInt=	atoi(sID);

/*获取最大的keyint*/
		if(p->iKeyInt>iMaxID)	iMaxID=p->iKeyInt;

		if(InsertBin(pptHead,(void*)p,
			data_search_bintree_comm_key_e,
			assign_insert_bintree)<0) return -1;
	}
	
/*释放FileControl结构*/
	listfree(&ptLkHead);
	return iMaxID;
}
int mvdmp2compressrecord(struct DmpTicketStruct *pi,struct CompressRecordStruct *po)
{
	int k;
	char sTemp[100];
	
	strcpy(sTemp,pi->sStartTime+2);
	asc_dec2hbcd(sTemp,(unsigned char*)po->sStartTime);
	
	k=atoi(pi->sDuration);
	if(k>65535) k=0;
	((unsigned char*)po->sDuration)[0]=k/0x100;
	((unsigned char*)po->sDuration)[1]=k%0x100;
	
	k=AddCommKey(pi->sLocation,&pLocationBin,&iLocationID);
	if(k>65535) k=0;
	((unsigned char*)po->sLocation)[0]=k/0x100;
	((unsigned char*)po->sLocation)[1]=k%0x100;


	memset((void*)(po->sCallInfo),0xff,40);
	
	sTemp[0]=atoi(pi->sCallType)+'0';
	sTemp[1]=0;
	strcat(sTemp,pi->sMsisdn);
	strcat(sTemp,"F");
	strcat(sTemp,pi->sOtherParty);

	k=asc_hex2hbcd(sTemp,(unsigned char*)po->sCallInfo);
	
	po->cLen=sizeof(struct CompressRecordStruct)-40+k;

	return (int)(po->cLen);
}

int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char sPath[256],sFileName[256],sLocationName[256],sCommand[256],sPreName[256];
	static int iCount=0,k,iSeq=0;
        
        struct CompressRecordStruct Rec;
        struct DmpTicketStruct Temp;
        struct DmpTicketStructIn TempIn;

	if(argc!=4){
		printf("用法：%s path tablename location.txt .\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);
        ConnectDataDB();
        
        bzero((void*)&TempIn,sizeof(struct DmpTicketStructIn));
	strcpy(TempIn.sCondition,"");
	
        strcpy(sPath,argv[1]);
        strcpy(TempIn.sTableName,argv[2]);
	RegularDir(sPath);
	Upper(TempIn.sTableName);
	strcpy(sLocationName,argv[3]);
	
	iLocationID=InitCommKeyTree(&pLocationBin,sLocationName);
	if(iLocationID<0) iLocationID=0;
	
	strcpy(sPreName,"");
	strcpy(sFileName,"");
	
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;
        	
        while(EGetDmpTicketToStruct(&Temp,&TempIn)){
        
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
				/*只有在gzip不成功的情况下用compress*/
				sprintf(sCommand, "gzip %s",sPreName);
				if(system(sCommand)!=0){
					sprintf(sCommand,"compress %s",sPreName);
					system(sCommand);
				}
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
		
		if((k=mvdmp2compressrecord(&Temp,&Rec))<0){
			printf("话单结构不满足要求.\n");
			return -1;
		}
		fwrite((void*)&Rec,1,k,fp);
        }
	if(fp!=NULL)fclose(fp);
	if(strcmp(sFileName,"")!=0){
		/*只有在gzip不成功的情况下用compress*/
		sprintf(sCommand, "gzip %s",sFileName);
		if(system(sCommand)!=0){
			sprintf(sCommand,"compress %s",sFileName);
			system(sCommand);
		}
		printf("文件 %s 生成完毕.\n",sFileName);
		WriteProcMsg("文件 %s 生成完毕.",sFileName);
	}
        
	printf("输出联通完毕，话单总数%d.\n",iCount);
	WriteProcMsg("表%s生成文件完毕,话单总数%d.",TempIn.sTableName,iCount);

	if(PrintLocation(sLocationName)<0)	printf("输出参数表失败.\n");
	else 	printf("输出参数表成功.\n");

        DisconnectDatabase();

	return 0;
}

