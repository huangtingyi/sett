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
#include <dbsupp.h>
#include <wwcoding.h>
#include <stdarg.h>

#include "param_intf.h"
#include "dbsupp.h"
#include "../case/md5.h"

#include <ticket.h>
#include <stt_ticket.h>
#include <bintree.h>

/*�ص�����*/
#define KEYLEN sizeof(unsigned char)*16
struct KeyStruct{
	unsigned char sKey[KEYLEN];/*Ϊ��ʡ�ռ䲻ʹ��char,��ʹ��unsigned char ����*/
	time_t tDateTime;/*time_t����ʱ�䣬�����ж�Щ�����Ƿ��Ѿ����ڲ���Ҫ����*/	
};


/*
��ȡ���ݵ�md5����
������󳤶�8192�ֽ�
���16λ��md5��unsigned char����
ע��:Ϊ�������,ʹ��static�������������ʷ��̰߳�ȫ.
������MD5����һ��Ϊһ���ڴ����Ϊmd5,��Ϊ��ʡ�ռ䱣����unsigned char��
*/
struct KeyStruct *MakeDupKey( char sDateTime[], char *pcFmt,... )
{
	static struct KeyStruct DupKey;

	#define MAXLEN 8192
	int iBuffLen=0;
	char sText[MAXLEN+1];
	va_list argptr;

	md5_state_t state;
	md5_byte_t digest[16];

	/*��ȡ������ֵ���շ���*/
	memset(sText,0,MAXLEN);
	va_start(argptr, pcFmt);
	vsprintf( sText, pcFmt, argptr);
	va_end(argptr);
	sText[MAXLEN] = 0;
	iBuffLen=strlen(sText);

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)sText, iBuffLen);
	md5_finish(&state, digest);

	memcpy(DupKey.sKey,digest,KEYLEN);
	DupKey.tDateTime=tGetTime(sDateTime);

	return &DupKey;
}

/*�����ļ��õ�ȫ�ֱ�����ʹTravelBin��hook�����ܱ����ļ�*/
FILE *SaveKeyFP;

int hook_save_file( void **ppData)
{
	fwrite(*ppData,sizeof(struct KeyStruct),1,SaveKeyFP);
	return 0;
}

int SaveKeytoFile(BINTREE **pptRoot,char sFileName[])
{
	if ( *pptRoot == NULL ) return 0;

	SaveKeyFP = fopen(sFileName,"w");
	if (SaveKeyFP==NULL){
		perror("���ļ�дʧ��");
		WriteAlertMsg("�򿪼�ֵ�ļ�:%sдʧ��!",sFileName);
		return -1;
	}

	/*��hook_pdup_list�д���д�ļ���¼������������*/
	TravelBin(*pptRoot,hook_save_file);
	DestroyBin(*pptRoot);
	*pptRoot=NULL;

	fclose(SaveKeyFP);

	return 0;
}

static int data_comp_dup_key_e(void *pValue,void *pData)
{
	struct KeyStruct *pSource=(struct KeyStruct *)pValue;
	struct KeyStruct *pTarget=(struct KeyStruct *)pData;

	return memcmp(pSource->sKey,pTarget->sKey,KEYLEN);
}

static void assign_insert_bintree_dup_key_e(void **ppHead,void *pData)
{
	*ppHead=pData;
}

int LoadKeyFromFile(BINTREE **pptRoot,const char sFileName[],
	int (*hook_load_file)(struct KeyStruct *pNode)){

	FILE *fp;
	struct KeyStruct *p;

	/*���Դ�ʧ�ܣ����ܳ�������*/
	fp=fopen(sFileName,"rb");
	if (fp==NULL){
		perror("���ļ���ʧ��");
		/*WriteAlertMsg("�򿪼�ֵ�ļ�:%s��ʧ��!",sFileName);*/
		return 0;
	}

	while( true ){

		if((p=(struct KeyStruct*)calloc(
			sizeof(struct KeyStruct ),1))==NULL){
			WriteAlertMsg("����DUPKEYʧ��dup_key");
			exit(1);
		}

		if (fread(p,1,sizeof(struct KeyStruct),fp)!=
				sizeof(struct KeyStruct)){
			free(p);
			p=NULL;
			break;
		}

		/*����ڵ�*/
		if ( hook_load_file != NULL )
			if (hook_load_file(p)<0){
				free(p);
				p=NULL;
				continue;
			}

		if(InsertBin(pptRoot,(void *)p,
			data_comp_dup_key_e,
			assign_insert_bintree_dup_key_e)<0){
			WriteAlertMsg("����BINTREEʧ��dup_key");
			exit(1);
		}
	}

	fclose(fp);
	return 0;
}

int IsDupTicket(BINTREE *pRoot,struct KeyStruct *pNode)
{
	struct KeyStruct *pNoUse;

	if((SearchBin(pRoot,pNode,data_comp_dup_key_e,(void**)&pNoUse))==FOUND)
		return FOUND;

	return NOTFOUND;
}

int AddKeyToFile( struct KeyStruct *pTmpNode, BINTREE **pptRoot )
{
	struct KeyStruct *pNode=NULL;

	if((pNode=(struct KeyStruct*)calloc(
		sizeof(struct KeyStruct ),1))==NULL){
		WriteAlertMsg("����DUPKEYʧ��dup_key");
		exit(1);
	}

	memcpy(pNode,pTmpNode,sizeof(struct KeyStruct));

	if(InsertBin(pptRoot,(void *)pNode,
		data_comp_dup_key_e,
		assign_insert_bintree_dup_key_e)<0){
		WriteAlertMsg("����BINTREEʧ��dup_key");
		exit(1);
	}

	return 0;
}
/*�����hookΪ�ڵ��Ǵ�����������>=0��ʾ����/����˽ڵ�,���޸Ĳ���ֵ��*/
int delete_overtime_ticket(struct KeyStruct *pNode)
{
	time_t tnow;

	/*����30Сʱ�ڵĻ���*/
	if (time(&tnow)-pNode->tDateTime>=108000)
		return -1;
	return 0;
}

struct DupKeyBinStruct{
	struct DupKeyBinStruct *pNext;
	char sKey[7];
	char sFileName[256];
	BINTREE *pRoot;	
};

struct DupKeyBinStruct *pDupKeyBin=NULL;

BINTREE **GetDupKeyBin(char sDateTime[],char sPath[])
{
	char sDupKeyFile[256],sDate[7];
	struct DupKeyBinStruct *ptHead=NULL,*pTemp=NULL;
	
	ptHead=pDupKeyBin;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strncmp(pTemp->sKey,sDateTime,6)==0)
			return &(pTemp->pRoot);
	}
	
	/*�����ڵ�ʱ���½�������Ҫ����sKey��Ա,�½�ʱҪ�����ļ����ڴ�*/	
	pTemp=NULL;
	if((pTemp=malloc(sizeof(struct DupKeyBinStruct)))==NULL){
		WriteAlertMsg("����DupKeyBin�ڴ�ʧ�ܡ�\n");
		exit(-1);
	}	
	bzero(pTemp,sizeof(struct DupKeyBinStruct));
	
	strncpy(pTemp->sKey,sDateTime,6);
	pTemp->sKey[6]=0;
	InsertList((LIST **)&pDupKeyBin,(LIST *)pTemp);
	
	/*�������ݵ��ڴ�*/
	strncpy(sDate,sDateTime,6);
	sDate[6]=0;
	sprintf(sDupKeyFile,"%sSMS%s.dup.key",sPath,sDate);
	LoadKeyFromFile(&(pTemp->pRoot),sDupKeyFile,NULL);	
	strcpy(pTemp->sFileName,sDupKeyFile);
	
	return &(pTemp->pRoot);	
}

int main( int argc,char **argv )
{
	int l=0;
	BINTREE **ppRoot=NULL;
	struct KeyStruct *p;/*�ص�����*/
	struct FileControlStruct *pDupTicket=NULL;
	struct SmsTicketStruct	Temp;
	char sFileName[256],sKeyPath[256],sOutputPath[256],sTemp[1024],sDupKey[256],sDateTime[15],sBaseName[256];
	struct FileControlStruct *ptHead,*pTemp,*ptLkHead;
	
	if(argc!=4){
		printf("usage %s keyFilePath	TicketFile	outputPath.\n",argv[0]);
		return -1;
	}
	
	
	strcpy(sKeyPath,argv[1]);
	strcpy(sFileName,argv[2]);
	strcpy(sOutputPath,argv[3]);
	
	RegularDir(sKeyPath);
	RegularDir(sOutputPath);
	GetBaseName(sFileName,sBaseName);
	
	if((l=TxtFileToList(sFileName,&ptHead))<0){
		WriteAlertMsg("�����ļ�%sʧ��",sFileName);
		return -1;
	}
	
	ptLkHead=ptHead;
	GetHostTime(sDateTime);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mvitem_fmsmsticket((struct FSmsTicketStruct *)(pTemp->pData),
			pTemp->iLen,&Temp);		
		if(Temp.iRentFee!=0){
			ppRoot=GetDupKeyBin(Temp.sStartTime,sKeyPath);
			sprintf(sDupKey,"%s%s%s%d",Temp.sMsisdn,
				Temp.sSpServiceCode,Temp.sSpCode,Temp.iRentFee);
			p=MakeDupKey( sDateTime, "%s",sDupKey);
			if (IsDupTicket(*ppRoot,p)==FOUND){
				/*InsertList((LIST **)&pDupTicket,(LIST *)pTemp);*/
		                if(item2list(&pDupTicket,(void*)(pTemp->pData),
		                        pTemp->iLen)<0){
		                        WriteAlertMsg("�����ص�����ʧ��.\n");
		                        return -1;
		                }				
				/*����¼�������������Ϊ0*/
				strncpy(((struct FSmsTicketStruct *)(pTemp->pData))->sRentFee,"0000000000",8);
				strncpy(((struct FSmsTicketStruct *)(pTemp->pData))->sBaseFee,"0000000000",8);
				continue;
			}			
			AddKeyToFile(p,ppRoot);			
		}
	}
		
	/*����ص�*/
	if ( pDupTicket != NULL ){
		sprintf(sTemp,"%s%s.dup",sKeyPath,sBaseName);
		if ( list2fileln( (struct FileControlStruct **)&pDupTicket,
			 sTemp) < 0 ){
			 WriteAlertMsg("����ص��ļ�%s����",sTemp);
			return -1;
		}
	}	
	
	/*todo:ѭ��ִ��������м�¼......
	struct DupKeyBinStruct *pDupKeyBin=NULL;*/
	while(pDupKeyBin!=NULL){
		SaveKeytoFile( &(pDupKeyBin->pRoot),pDupKeyBin->sFileName );
		pDupKeyBin=pDupKeyBin->pNext;
	}
	/*todo:��������ļ�*/
	sprintf(sTemp,"%s%s",sOutputPath,sBaseName);
	if ( list2fileln( (struct FileControlStruct **)&ptLkHead,sTemp) < 0 ){
		 WriteAlertMsg("����ص��ļ�%s����",sTemp);
		return -1;
	}
		
	return 0;
}

