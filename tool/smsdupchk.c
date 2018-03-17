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

/*重单处理*/
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

/*保存文件用的全局变量，使TravelBin的hook函数能保存文件*/
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
		/*WriteAlertMsg("打开键值文件:%s读失败!",sFileName);*/
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
	
	/*不存在的时候新建立，并要设置sKey成员,新建时要加载文件到内存*/	
	pTemp=NULL;
	if((pTemp=malloc(sizeof(struct DupKeyBinStruct)))==NULL){
		WriteAlertMsg("分配DupKeyBin内存失败。\n");
		exit(-1);
	}	
	bzero(pTemp,sizeof(struct DupKeyBinStruct));
	
	strncpy(pTemp->sKey,sDateTime,6);
	pTemp->sKey[6]=0;
	InsertList((LIST **)&pDupKeyBin,(LIST *)pTemp);
	
	/*加载数据到内存*/
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
	struct KeyStruct *p;/*重单过滤*/
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
		WriteAlertMsg("加载文件%s失败",sFileName);
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
		                        WriteAlertMsg("插入重单链表失败.\n");
		                        return -1;
		                }				
				/*将记录的月租费用设置为0*/
				strncpy(((struct FSmsTicketStruct *)(pTemp->pData))->sRentFee,"0000000000",8);
				strncpy(((struct FSmsTicketStruct *)(pTemp->pData))->sBaseFee,"0000000000",8);
				continue;
			}			
			AddKeyToFile(p,ppRoot);			
		}
	}
		
	/*输出重单*/
	if ( pDupTicket != NULL ){
		sprintf(sTemp,"%s%s.dup",sKeyPath,sBaseName);
		if ( list2fileln( (struct FileControlStruct **)&pDupTicket,
			 sTemp) < 0 ){
			 WriteAlertMsg("输出重单文件%s错误",sTemp);
			return -1;
		}
	}	
	
	/*todo:循环执行输出所有记录......
	struct DupKeyBinStruct *pDupKeyBin=NULL;*/
	while(pDupKeyBin!=NULL){
		SaveKeytoFile( &(pDupKeyBin->pRoot),pDupKeyBin->sFileName );
		pDupKeyBin=pDupKeyBin->pNext;
	}
	/*todo:输出正常文件*/
	sprintf(sTemp,"%s%s",sOutputPath,sBaseName);
	if ( list2fileln( (struct FileControlStruct **)&ptLkHead,sTemp) < 0 ){
		 WriteAlertMsg("输出重单文件%s错误",sTemp);
		return -1;
	}
		
	return 0;
}

