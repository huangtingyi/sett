#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <expr_fun.h>


void InitBaseField(char sInput[],char sRoamType[2],char sTrunkInTypeID[5],
	char sTrunkOutTypeID[5],char sMsisdn[16],char sOtherParty[25])
{
	sRoamType[0]=	sInput[97];sRoamType[1]=0;
	
	strncpy(sTrunkInTypeID,	sInput+204,4);sTrunkInTypeID[24]=0;
	AllTrim(sTrunkInTypeID);
	
	strncpy(sTrunkOutTypeID,sInput+208,4);sTrunkOutTypeID[24]=0;
	AllTrim(sTrunkOutTypeID);
	
	strncpy(sMsisdn,	sInput+6,15);sMsisdn[15]=0;
	AllTrim(sMsisdn);
	
	strncpy(sOtherParty,	sInput+26,24);sOtherParty[24]=0;
	AllTrim(sOtherParty);
}
int main(int argc, char **argv)
{
	int iRet;

	char	sRecord[512];
	char	sRoamType[2],sTrunkInTypeID[5],sTrunkOutTypeID[5];
	char	sMsisdn[16],sOtherParty[25],*pc;
	
	char	sFileName[128],sBaseName[128],sOutDir[128];
	char	s193OName[128],s193TName[128],s17911OName[128],s17911TName[128];
	
	struct	FileControlStruct *ptHead=NULL,*pTemp;
	struct	FileControlStruct *p17911O=NULL,*p17911T=NULL;
	struct	FileControlStruct *p193O=NULL,*p193T=NULL;
	
	if(argc!=3){
		printf("Usage %s input outdir.\n",argv[0]);
		return -1;
	}
	strcpy(sFileName,argv[1]);
	strcpy(sOutDir,	argv[2]);RegularDir(sOutDir);
	
	if(TxtFileToList(sFileName,&ptHead)<0){
		printf("加载文件 %s 链表失败.\n",sFileName);
		return -1;
	}
	GetBaseName(sFileName,sBaseName);
	if((pc=strstr(sBaseName,".tmp"))!=NULL) *pc=0;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		memcpy(sRecord,(char*)(pTemp->pData),pTemp->iLen);
		sRecord[pTemp->iLen]='\n';
		
		InitBaseField((char*)sRecord,sRoamType,sTrunkInTypeID,
			sTrunkOutTypeID,sMsisdn,sOtherParty);
		
		if(strcmp(sRoamType,"1")==0||strcmp(sRoamType,"2")==0){
			
			if(strcmp(sTrunkOutTypeID,"3003")==0||
				strncmp(sOtherParty,"17911",5)==0)
				iRet=item2list(&p17911O,sRecord,pTemp->iLen);
			else if(strcmp(sTrunkOutTypeID,"3005")==0||
				strncmp(sOtherParty,"193",3)==0)
				iRet=item2list(&p193O,sRecord,pTemp->iLen);
		}
		else{
			if(strcmp(sTrunkInTypeID,"3003")==0||
				strncmp(sOtherParty,"17911",5)==0)
				iRet=item2list(&p17911T,sRecord,pTemp->iLen);
			else if(strcmp(sTrunkInTypeID,"3005")==0||
				strncmp(sOtherParty,"193",3)==0)
				iRet=item2list(&p193T,sRecord,pTemp->iLen);
		}
		if(iRet<0){
			printf("生成文件 %s 链表失败.\n",sFileName);
			return -1;
		}
	}
	sprintf(s193OName,"%s%s.193O",sOutDir,sBaseName);
	sprintf(s193TName,"%s%s.193T",sOutDir,sBaseName);
	
	sprintf(s17911OName,"%s%s.17911O",sOutDir,sBaseName);
	sprintf(s17911TName,"%s%s.17911T",sOutDir,sBaseName);
	
	if(list2file(&p17911O,s17911OName)<0){
		printf("输出文件%s错误.\n",s17911OName);
		return -1;
	}
	if(list2file(&p17911T,s17911TName)<0){
		printf("输出文件%s错误.\n",s17911TName);
		return -1;
	}
	if(list2file(&p193O,s193OName)<0){
		printf("输出文件%s错误.\n",s193OName);
		return -1;
	}
	if(list2file(&p193T,s193TName)<0){
		printf("输出文件%s错误.\n",s193TName);
		return -1;
	}
	printf("拆分文件%s成功.\n",sFileName);
	
	return 0;
}
