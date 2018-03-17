#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <list.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <bintree.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE 
#define FALSE 0
#endif

struct LabelStruct
{
	struct LabelStruct *pNext;
	char	cFlag;	/*0不修改，1要修改,2可能被修改*/
	char	sLabel[32];
};
struct LabelAntiStruct
{
	struct LabelAntiStruct *pNext;
	char	sOriLabel[32];
	char	sTrsLabel[32];
};
struct FileProtStruct
{
	struct FileProtStruct *pNext;
	char	sSourceName[128];
	char	sTargetName[128];
	struct 	LabelStruct *pHead;
};
struct DirectoryItemStruct
{
	struct DirectoryItemStruct *pNext;
	char	sRelaDir[120];
	char	sName[120];
	int	iExistFlag;
};

int iCodeFlag=true;
int WantToModify(char cFlag,char sLabel[]);

void ConvertDirLast(char sDir[])
{
	if(sDir[0]==0) return;
	
	if(sDir[strlen(sDir)-1]=='/'||
		sDir[strlen(sDir)-1]=='\\') sDir[strlen(sDir)]=0;
}
int IsDirectory(char sName[])
{
	DIR *P;
	
	if((P=opendir(sName))==NULL) return FALSE;
	closedir(P);
	
	return TRUE;
}
int CreateDirList(DIR *DP,char sRelaDir[120],struct DirectoryItemStruct **pptHead)
{
	char sTempName[1024];
	struct dirent *dp;
	struct DirectoryItemStruct *pTemp=NULL;

	while((dp = readdir(DP))!=NULL){
	
		/*是目录本身或上级目录则继续**/
		if(strcmp(dp->d_name,".")==0||
			strcmp(dp->d_name,"..")==0)
			continue;

		/*拼凑文件名*/
		strcpy(sTempName,sRelaDir);
		strcat(sTempName,"/");
		strcat(sTempName,dp->d_name);
	
		if(IsDirectory(sTempName)){

			DIR	*TP;
			struct DirectoryItemStruct *ptHead=NULL;

			/*这个目录下没东西*/
			if((TP=opendir(sTempName))==NULL)
				continue;
			
			if(CreateDirList(TP,sTempName,&ptHead)<0)
				return -1;
			/*将临时链表合并到输出链表中*/	
			while(ptHead!=NULL){
				pTemp=ptHead;
				ptHead=ptHead->pNext;
				InsertList((LIST**)pptHead,(LIST*)pTemp);
			}

			continue;
		}

		/*只比较三种文件*/
		if(RLike(sTempName,".pc")==false&&
			RLike(sTempName,".c")==false&&
			RLike(sTempName,".h")==false)  continue;

		if((pTemp=malloc(sizeof(struct DirectoryItemStruct)))==NULL){
			printf("error malloc DirectoryItemStruct.\n");
			return -1;
		}

		bzero((void*)pTemp,sizeof(struct DirectoryItemStruct));
		strcpy(pTemp->sRelaDir,sRelaDir);
		strcpy(pTemp->sName,	dp->d_name);

		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	return 0;
}
static int new_line(char sInput[])
{
	if(strncmp(sInput,"\n",1)==0||
		strncmp(sInput,"\r",1)==0) return true;
	return false;
}
static int comment_c_begin(char sInput[])
{
	if(strncmp(sInput,"/*",2)==0) return true;
	return false;
}
static int comment_c_end(char sInput[])
{
	if(strncmp(sInput,"*/",2)==0) return true;
	return false;
}
static int comment_cpp_begin(char sInput[])
{
	if(strncmp(sInput,"//",2)==0) return true;
	return false;
}
static int comment_cpp_end(char sInput[])
{
	return new_line(sInput);
}
static int string_c_begin(char sInput[])
{
	if(strncmp(sInput,"\"",1)==0) return true;
	return false;
}
static int string_c_next(char sInput[])
{
	if(strncmp(sInput,"\\\\",2)==0) return 2;
	if(strncmp(sInput,"\\\"",2)==0) return 2;
	if(strncmp(sInput,"\"",1)==0) return 0;
	else return 1;
}
static int char_c_begin(char sInput[])
{
	if(strncmp(sInput,"\'",1)==0) return true;
	return false;
}
static int char_c_next(char sInput[])
{
	if(strncmp(sInput,"\\\\",2)==0) return 2;
	if(strncmp(sInput,"\\\'",2)==0) return 2;
	if(strncmp(sInput,"\'",1)==0) return 0;
	else return 1;
}
static int input_end(char sInput[])
{
	if(sInput[0]==0) return true;
	return false;
}
static int identify_begin(char sInput[])
{
	if((sInput[0]>='a'&&sInput[0]<='z')||
                (sInput[0]>='A'&& sInput[0]<='Z')||
                sInput[0]=='_') return true;
	return false;
}
static int identify_next(char sInput[])
{
	if((sInput[0]>='a'&&sInput[0]<='z')||
                (sInput[0]>='A'&& sInput[0]<='Z')||
                (sInput[0]>='0'&&sInput[0]<='9')||
                sInput[0]=='_') return true;
	return false;
}
static int const_hex_num_begin (char sInput[])
{
	char c1=sInput[0],c2=sInput[1];

        if(c1=='0'&&(c2=='X'||c2=='x')) return true;
        return false;
}

int const_hex_num_next(char sInput[])
{
	char c=sInput[0];

        if((c>='0'&&c<='9')||
                (c>='a'&&c<='f')||
                (c>='A'&&c<='F')) return 1;
        return 0;
}
int const_dec_num_begin(char sInput[])
{
	char c=sInput[0];

        if(c>='0'&&c<='9') return true;
        return false;
}
int const_dec_num_next(char sInput[])
{
	char c=sInput[0];

        if(c>='0'&&c<='9') return 1;
        return 0;

}
static int const_bin_num_begin (char sInput[])
{
	char c1=sInput[0],c2=sInput[1];

        if(c1=='0'&&(c2=='B'||c2=='b')) return true;
        return false;
}
int const_bin_num_next(char sInput[])
{
	char c=sInput[0];

        if(c>='0'&&c<='1') return 1;
        return 0;
}
int seperator_begin(char sInput[])
{
	if(strchr(" \t\n\r(){}<>=+-*/%|$&!,;.:[]\\#?^#@~",sInput[0])!=NULL)
		return true;
	return false;
}
static int ReadWord(char sInput[],char sOutput[])
{
	int l;
	char *pc=sInput;

	strcpy(sOutput,"");

	if(input_end(pc)) return 0;

	if(comment_c_begin(pc)){
		pc+=2;
		if(input_end(pc)) goto read_tail;
		while(!comment_c_end(pc)){
			pc++;
			if(input_end(pc)) goto read_tail;
		}
		pc+=2;
		goto read_tail;
	}
	if(comment_cpp_begin(pc)){
		pc+=2;
		if(input_end(pc)) goto read_tail;
		while(!comment_cpp_end(pc)){
			pc++;
			if(input_end(pc)) goto read_tail;
		}
		while(comment_cpp_end(pc)) pc++;
		goto read_tail;
	}

	if(string_c_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=string_c_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		pc++;
		goto read_tail;
	}
	if(char_c_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=char_c_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		pc++;
		goto read_tail;
	}
	if(const_hex_num_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=const_hex_num_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		goto read_tail;
	}
	if(const_dec_num_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=const_dec_num_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		goto read_tail;
	}
	if(const_bin_num_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=const_bin_num_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		goto read_tail;
	}
	if(identify_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=identify_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		goto read_tail;
	}
	if(seperator_begin(pc)){
		pc++;
		goto read_tail;
	}
read_tail:
	if(pc!=sInput){
		strncpy(sOutput,sInput,pc-sInput);
		sOutput[pc-sInput]=0;
		return pc-sInput;
	}
	return 0;
}
int LowerGtUpper(char sLabel[])
{
	int l,u,i,len=strlen(sLabel);
	
	for(i=0,l=0;i<len;i++)if(sLabel[i]>='a'&&sLabel[i]<='z')l++;
	for(i=0,u=0;i<len;i++)if(sLabel[i]>='A'&&sLabel[i]<='Z')u++;
	
	if(l>u) return true;
	return false;
}
int LikeTrsLabel(char sLabel[])
{
	if(strncmp(sLabel,"h",1)==0) return true;
	return false;
}
int GetLabelList(char sInput[],struct LabelStruct **pptHead)
{
	int i,iCnt,l=0;
	char sWord[2048*10],*sTemp=sInput,*pc;
	struct LabelStruct *pTemp,*ptHead=NULL;

	while((l=ReadWord(sTemp,sWord))>0){

		sTemp+=l;

		if(iCodeFlag==true||strlen(sWord)>31){

			iCnt=(strlen(sWord)+29)/30;

			for(i=0;i<iCnt;i++){
				pc=sWord+i*30;

				pTemp=malloc(sizeof(struct LabelStruct));
				if (pTemp==NULL){
					printf("分配LabelStruct内存失败!\n");
					exit(-1);
				}
				bzero((void*)pTemp,sizeof(struct LabelStruct));

				strncpy(pTemp->sLabel,pc,30);
				pTemp->cFlag=0;
				InsertList((LIST **)&ptHead,(LIST *)pTemp);
			}
			if(iCnt==1) pTemp->cFlag=1;
		}
		else{
		
			pTemp=malloc(sizeof(struct LabelStruct));
			if (pTemp==NULL){
				printf("分配LabelStruct内存失败!\n");
				exit(-1);
			}
			bzero((void*)pTemp,sizeof(struct LabelStruct));
			strcpy(pTemp->sLabel,sWord);
			InsertList((LIST **)&ptHead,(LIST *)pTemp);
			pTemp->cFlag=0;
			
			if(strlen(sWord)==31&&WantToModify(1,sWord)){
				if(LikeTrsLabel(sWord))	pTemp->cFlag=1;
			}
			else
				pTemp->cFlag=1;
		}
	}

	ReverseList((LIST **)&ptHead);

	*pptHead=ptHead;

	return 0;
}
int CreateFileProtList(struct DirectoryItemStruct *pSource,
	char sSourceDir[],char sTargetDir[],struct FileProtStruct **pptHead)
{
	char sRelaDir[128];
	struct FileProtStruct *pTemp;
	
	*pptHead=NULL;
	
	while(pSource!=NULL){
		if((pTemp=(struct FileProtStruct*)
			malloc(sizeof(struct FileProtStruct)))==NULL) 
			return -1;

		strcpy(sRelaDir,pSource->sRelaDir+strlen(sSourceDir)+1);
		
		bzero((void*)pTemp,sizeof(struct FileProtStruct));
		
		if(strlen(sRelaDir)!=0){
			sprintf(pTemp->sSourceName,"%s/%s/%s",sSourceDir,
				sRelaDir,pSource->sName);
			sprintf(pTemp->sTargetName,"%s/%s/%s",sTargetDir,
				sRelaDir,pSource->sName);
		}
		else{
			sprintf(pTemp->sSourceName,"%s/%s",sSourceDir,
				pSource->sName);
			sprintf(pTemp->sTargetName,"%s/%s",sTargetDir,
				pSource->sName);
		}
		pTemp->pHead=NULL;
		
		InsertList((LIST**)pptHead,(LIST*)pTemp);
		
		pSource=pSource->pNext;
	}
	
	return 0;
}
int comp_insert_label_anti(void *p1,void *p2)
{
	struct LabelAntiStruct *pSource=(struct LabelAntiStruct *)p1;
	struct LabelAntiStruct *pTarget=(struct LabelAntiStruct *)p2;
	
	return strcmp(pSource->sOriLabel,pTarget->sOriLabel);
}
void ReverseString(char sInput[])
{
	int i,l;
	char sTemp[8196];
	
	strcpy(sTemp,sInput);
	l=strlen(sTemp);
	
	for(i=0;i<l;i++)
		sInput[i]=sTemp[l-i-1];
}
int ModifyLabel(void **ppData)
{
	char c,t;
	int i,l;
	static char asLowerAnti[26]="abcdefghijklmnopqrstuvwxyz";
	static char asUpperAnti[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	struct LabelAntiStruct *pHead=(struct LabelAntiStruct *)*ppData;

	strcpy(pHead->sTrsLabel,pHead->sOriLabel);
	if(iCodeFlag==false){
		if(LikeTrsLabel(pHead->sOriLabel)||
			strlen(pHead->sOriLabel)<31)
			strcpy(pHead->sTrsLabel,pHead->sOriLabel+1);
	}
	
	l=strlen(pHead->sTrsLabel);
	for(i=0;i<l;i++){
		c=pHead->sTrsLabel[i];
		if(c>='a'&&c<='z')	t=asLowerAnti[25-(c-'a')];
		else if(c>='A'&&c<='Z')	t=asUpperAnti[25-(c-'A')];
		else t=c;
		pHead->sTrsLabel[i]=t;
	}
	if(iCodeFlag==true)
		strcat(pHead->sTrsLabel,"h");
	
	ReverseString(pHead->sTrsLabel);
	
	return 0;
}
void PrintLabelList(struct LabelStruct *ptHead)
{
	int i=0;

	while(ptHead!=NULL){
		printf("%d.%d.---->%s|||\n",
			i++,(int)(ptHead->cFlag),ptHead->sLabel);
/*		printf("%s",ptHead->sLabel);*/
		ptHead=ptHead->pNext;
	}
	exit(1);
}
void LoadFileToLabeLList(char sSourceDir[],struct FileProtStruct *ptHead)
{ 
#define MYMAXFILELEN	1024*1024
	int l;
	FILE *fp;
	char sFileName[128],sInput[MYMAXFILELEN];
	
	while(ptHead!=NULL){
/*		printf("loading file  %s.\n",ptHead->sSourceName);*/

		strcpy(sFileName,ptHead->sSourceName);

/*将文件的内容加载到 sInput 变量*/
		l=FileSize(sFileName);
		if(l==0)continue;
		if(l<0||l>MYMAXFILELEN){
			printf("获取文件 %s 字节数失败.\n",sFileName);
			exit(1);
		}
		if((fp=fopen(sFileName,"r"))==NULL){
			printf("打开文件 %s 读失败.\n",sFileName);
			exit(2);
		}
		fread((void*)sInput,l,1,fp);sInput[l]=0;
		fclose(fp);
/*将变量生成链表在整个 FileProtStruct 中*/
		GetLabelList(sInput,&(ptHead->pHead));
		
		if(strstr(sSourceDir,"new")!=NULL)
			PrintLabelList(ptHead->pHead);
		
		ptHead=ptHead->pNext;
	}
}
int WantToModify(char cFlag,char sLabel[])
{
	char sUpperStr[32],sLowerStr[32];

	if(cFlag==0||strlen(sLabel)<=3) return false;
	if(strncmp(sLabel,"xml",3)==0) return false;
	
	strcpy(sUpperStr,sLabel);
	strcpy(sLowerStr,sLabel);
	Upper(sUpperStr);
	Lower(sLowerStr);
			
	if(strcmp(sLabel,sLowerStr)==0||
		strcmp(sLabel,sUpperStr)==0) return false;

	if(!identify_begin(sLabel)) return false;

	return true;
}
void CreateLabelAntiTree(struct FileProtStruct *ptHead,BINTREE **pptHead)
{
	struct LabelStruct *pTemp;
	struct LabelAntiStruct *pAnti,Anti,*pNoUse=NULL;
	BINTREE *pRoot=NULL;
	
	while(ptHead!=NULL){
		pTemp=ptHead->pHead;
		while(pTemp!=NULL){

			if(WantToModify(pTemp->cFlag,pTemp->sLabel)==false){
				pTemp=pTemp->pNext;
				continue;
			}

			pTemp->cFlag=2;/*修改为可能被修改*/
			bzero((void*)&Anti,sizeof(struct LabelAntiStruct));
			strcpy(Anti.sOriLabel,pTemp->sLabel);
			if(SearchBin(pRoot,(void*)&Anti,
				comp_insert_label_anti,(void**)&pNoUse)==NOTFOUND){
				
				if((pAnti=(struct LabelAntiStruct *)
					malloc(sizeof(struct LabelAntiStruct)))==NULL){
					printf("分配内存 LabelAntiStruct 失败.\n");
					exit (4);
				}
				memcpy((void*)pAnti,(void*)&Anti,sizeof(struct LabelAntiStruct));
				if(InsertBin(&pRoot,(void*)pAnti,
					comp_insert_label_anti,
					assign_insert_bintree)<0){
					printf("生成对照树错误.\n");
					exit(5);
				}
			}
			pTemp=pTemp->pNext;
		}
		ptHead=ptHead->pNext;
	}
	*pptHead=pRoot;
}
void CreateNewLabel(BINTREE *pRoot)
{	
	TravelBin(pRoot,ModifyLabel);
}
void ModifyLabelInProtList(BINTREE *pRoot,struct FileProtStruct *ptHead)
{
	struct LabelStruct *pTemp;
	struct LabelAntiStruct *pNoUse=NULL,Anti;

	while(ptHead!=NULL){
		pTemp=ptHead->pHead;
		while(pTemp!=NULL){
			if(pTemp->cFlag!=2){
				pTemp=pTemp->pNext;
				continue;
			}
			strcpy(Anti.sOriLabel,pTemp->sLabel);
			if(SearchBin(pRoot,(void*)&Anti,
				comp_insert_label_anti,(void**)&pNoUse)==NOTFOUND){
				printf("程序逻辑错误.\n");
				exit(6);
			}
			strcpy(pTemp->sLabel,pNoUse->sTrsLabel);
			pTemp=pTemp->pNext;
		}
		ptHead=ptHead->pNext;
	}
}
void WriteProtListToTargetDir(struct FileProtStruct *ptHead)
{
	FILE *fp;
	char sFileName[128];
	struct LabelStruct *pTemp;

	while(ptHead!=NULL){
		strcpy(sFileName,ptHead->sTargetName);
		if((fp=fopen(sFileName,"w"))==NULL){
			printf("打开文件 %s 写失败.\n",sFileName);
			exit(3);
		}
		pTemp=ptHead->pHead;
		while(pTemp!=NULL){
			fprintf(fp,"%s",pTemp->sLabel);
			pTemp=pTemp->pNext;
		}
		fclose(fp);
		ptHead=ptHead->pNext;
	}
}
void CreateDirectoryItem(char sSourceDir[],struct DirectoryItemStruct **pp)
{
	DIR *DP;
	struct DirectoryItemStruct *ptHead=NULL;
	
	if((DP=opendir(sSourceDir))==NULL){
		printf("打开目录%s错误.\n",sSourceDir);
		exit(1);
	}
	if(CreateDirList(DP,sSourceDir,&ptHead)<0){
		printf("生成目录%s列表错误.\n",sSourceDir);
		exit(1);
	}
	closedir(DP);
	*pp=ptHead;
}
int main(int argc,char *argv[])
{
	char sSourceDir[120],sTargetDir[120];

	BINTREE *pRoot=NULL;
	struct FileProtStruct *pProtect=NULL;
	struct DirectoryItemStruct *pDirectoryItem=NULL;	

	if(argc!=2&&argc!=3){
		printf("用法:程序名 版本路径 [c|d].\n");
		printf("例如: %s src\n",argv[0]);
		exit(1);
	}
	if(IsDirectory(argv[1])==false){
		printf("给定路径不正确.\n");
		exit(1);
	}
	iCodeFlag=true;
	if(argc==3){
		if(strcmp(argv[2],"c")!=0) iCodeFlag=false;
	}
		
	strcpy(sSourceDir,argv[1]);
	ConvertDirLast(sSourceDir);
	
	strcpy(sTargetDir,sSourceDir);
	
	CreateDirectoryItem(sSourceDir,&pDirectoryItem);
/*生成Prot链表*/
	CreateFileProtList(pDirectoryItem,sSourceDir,sTargetDir,&pProtect);
	printf("开始加载文件.\n");
/*加载文件到pLabelList中*/
	LoadFileToLabeLList(sSourceDir,pProtect);
	printf("加载文件完毕,生成对照表.\n");
/*建立Label对照表*/	
	CreateLabelAntiTree(pProtect,&pRoot);
	
	printf("生成对照表完毕,分配新LABEL.\n");
/*分配新的Label*/
	CreateNewLabel(pRoot);

	printf("分配新LABEL完毕,修改LABEL.\n");
/*修改目标代码*/
	ModifyLabelInProtList(pRoot,pProtect);

	printf("修改LABEL完毕,输出结果到目标目录.\n");
/*将结果写到目标目录中*/
	WriteProtListToTargetDir(pProtect);

	printf("应用程序转换成功.\n");
	
	return 0;
}

