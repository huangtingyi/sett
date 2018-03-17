#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "bintree.h"
#include "wwlog.h"
#include "list.h"
#include "wwtiny.h"

#include "md5.h"

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

/*
�����������ݵ�md5���룬sOutput����md5�Ľ��
�̰߳�ȫ
���� 0��ʾ�ɹ�.
*/
int MD5(char sOutput[],char *pcFmt,...)
{
	#define MAXLEN 8192
	int iBuffLen=0;
	char sText[MAXLEN+1];
	va_list argptr;

	md5_state_t state;
	md5_byte_t digest[16];
	char hex_output[16*2 + 1];
	int di;	
	
	/*��ȡ������ֵ���շ���*/
	memset(sText,0,MAXLEN);
	va_start(argptr, pcFmt);
	vsprintf( sText, pcFmt, argptr);
	va_end(argptr);
	sText[MAXLEN] = 0;
	
	iBuffLen = strlen(sText);	
	if (iBuffLen==0){
		sOutput[0]='\0';
		return 0;
	}

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)sText, iBuffLen);
	md5_finish(&state, digest);
	for (di = 0; di < 16; ++di)
	    sprintf(hex_output + di * 2, "%02x", digest[di]);

	strcpy(sOutput,hex_output);
	return 0;
}

/*�����ļ��õ�ȫ�ֱ�����ʹTravelBin��hook�����ܱ����ļ�*/
FILE *SaveKeyFP;

int hook_save_file( void **ppData)
{
	fwrite(*ppData,sizeof(struct KeyStruct),1,SaveKeyFP);
	return;
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
		WriteAlertMsg("�򿪼�ֵ�ļ�:%s��ʧ��!",sFileName);
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

int main(int argc, char *argv[])
{
    BINTREE *pRoot=NULL;
    
   struct KeyStruct *p;
   int i;
   
    LoadKeyFromFile(&pRoot,"./a.key",delete_overtime_ticket);
    
    for (i=100000;i<110000;i++){
    	p=MakeDupKey("20041130000050","%d",i);   
	if (IsDupTicket(pRoot,p)==FOUND)
		continue;    
    	AddKeyToFile(p,&pRoot);
    }
   /* 
    //p=MakeDupKey("20041128000015","12345");
    //AddKeyToFile(p,&pRoot);
    //
    //p=MakeDupKey("20041129000005","HELLO1234");
    //if (IsDupTicket(pRoot,p)==FOUND)
    //   puts("dupppp");    
    //AddKeyToFile(p,&pRoot);
    */  

    SaveKeytoFile( &pRoot,"./b.key");
    return 0;
}
/*
//loadfile
//	
//	
//	
//	p=MakeKey("%s%s%s",s->sMsisdn,);	
//	if (isDupTicket(pRoot,p)){
//		continue;		
//	}
//	else{
//		AddToKeyFile(&pRoot,p);
//	}
//
//	
//savefile
*/
