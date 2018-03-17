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
	unsigned char sKey[KEYLEN];/*为节省空间不使用char,而使用unsigned char 保存*/
	time_t tDateTime;/*time_t保存时间，用于判断些数据是否已经过期不需要判重*/	
};

/*
获取数据的md5编码
输入最大长度8192字节
输出16位的md5的unsigned char编码
注意:为方便调用,使用static变量保存结果，故非线程安全.
功能与MD5基本一致为一组内存编码为md5,但为节省空间保存在unsigned char中
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
	
	/*获取将编码值，空返回*/
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
生成输入数据的md5编码，sOutput返回md5的结果
线程安全
返回 0表示成功.
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
	
	/*获取将编码值，空返回*/
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

/*保存文件用的全局变量，使TravelBin的hook函数能保存文件*/
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
		perror("打开文件写失败");
		WriteAlertMsg("打开键值文件:%s写失败!",sFileName);
		return -1;
	}
	
	/*在hook_pdup_list中处理写文件记录操作。。。。*/
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
	
	/*忽略打开失败，可能初次运行*/
	fp=fopen(sFileName,"rb");
	if (fp==NULL){
		perror("打开文件读失败");
		WriteAlertMsg("打开键值文件:%s读失败!",sFileName);
		return 0;
	}

	while( true ){
		
		if((p=(struct KeyStruct*)calloc(
			sizeof(struct KeyStruct ),1))==NULL){
			WriteAlertMsg("生成DUPKEY失败dup_key");
			exit(1);
		}
		
		if (fread(p,1,sizeof(struct KeyStruct),fp)!=
				sizeof(struct KeyStruct)){
			free(p);
			p=NULL;
			break;
		}
				
		/*处理节点*/
		if ( hook_load_file != NULL )
			if (hook_load_file(p)<0){
				free(p);
				p=NULL;
				continue;
			}

		if(InsertBin(pptRoot,(void *)p,
			data_comp_dup_key_e,
			assign_insert_bintree_dup_key_e)<0){
			WriteAlertMsg("生成BINTREE失败dup_key");
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
		WriteAlertMsg("生成DUPKEY失败dup_key");
		exit(1);
	}
	
	memcpy(pNode,pTmpNode,sizeof(struct KeyStruct));
	
	if(InsertBin(pptRoot,(void *)pNode,
		data_comp_dup_key_e,
		assign_insert_bintree_dup_key_e)<0){
		WriteAlertMsg("生成BINTREE失败dup_key");
		exit(1);
	}
	
	return 0;
}
/*载入的hook为节点是处理函数，返回>=0表示加载/保存此节点,可修改参数值。*/
int delete_overtime_ticket(struct KeyStruct *pNode)
{
	time_t tnow;
	
	/*保存30小时内的话单*/
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
