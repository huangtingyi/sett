#include <stdio.h>
#include <stdlib.h>
#include <bintree.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <wwfile.h>

#include "sett_supp.h"

int arry[]={18,10,14,14,14,8,30,30,30,30,8,8,20,20,4,18,4,20,8,10,10,
		30,30,10,10,18,8,8,18,18,8,18,60,18,3,8,18,8,30,30,30,
		8,1,8,5,12,8,18,4,1,9,9,30,18,18,18,20,18,18,15,15,18,18,
		15,15,18,18,18,18,1,30,50,10,20,8,30,30,4,30,10,30,10,20,
		20,4,10,18,20,20,4,10,18,20,20,20,20,20,20,20,20,20,30,10};
		
void AddTrime(char sStr[],int i,char sTemp[])
{
	int iLen=0;
	int iCnt=0;
	int m=0;
	
	iLen=strlen(sStr);
	iCnt=arry[i]-iLen;
	if(iCnt<=0)
		iCnt=0;
	while(m<iCnt){
		strncat(sStr," ",iCnt);
		m++;
	}
	strcpy(sTemp,sStr);
	
}
int GenSettleStr(char sStr[],char sResult[],int i)
{
	int iLen=0; 
	char sTemp[128];
	
	AddTrime(sStr,i,sTemp);
	iLen=sprintf(sResult,"%s",sTemp);

	return iLen;
}
int SettleMentYD(char str[],char sTemp[])
{
	
	int i=0;
	int iOffset=0;
	int iLen=0;
	char *p;
	char Temp[4096];
	char delims=44;
	
	p=str;
	while(*p!='\0'){
		if(*p==','){
			iLen++;
		}
		p++;
	}
	while(i<iLen){
		GetSepStr(str,',',i,Temp);
		iOffset+=GenSettleStr(Temp,sTemp+iOffset,i);
		i++;
	}
	
	return 0;
}	
int main(int argc, char **argv)
{
	int 	iRet,iLen;
	char	sRecord[4096],sTemp[4096];
	char 	sInNetWork[3],sOutNetWork[3];
	char 	sInOperators[3],sOutOperators[3];
	char	sFileName[256],sBaseName[256],*pc;
	char	sGnDir[256];
	char 	sGCTName[256],sGCMName[256],sGCRCName[256],sGCTCName[256],sOTHName[256];
	char 	sNCTName[256],sNCMName[256],sNCRCName[256],sNCTCName[256],sNCNCName[256];
	struct	FileControlStruct *ptHead=NULL,*pTemp;
	struct	FileControlStruct *pGCT=NULL,*pGCM=NULL,*pGCRC=NULL,*pGCTC=NULL,*pOTH=NULL;
	struct	FileControlStruct *pNCT=NULL,*pNCM=NULL,*pNCRC=NULL,*pNCTC=NULL,*pNCNC=NULL;

	if(argc!=3){
		printf("Usage %s input gdir .\n",argv[0]);
		return -1;
	}
	strcpy(sFileName,argv[1]);
	strcpy(sGnDir,	argv[2]);RegularDir(sGnDir);
	
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
		sRecord[pTemp->iLen]=0;
		SettleMentYD(sRecord,sTemp);
		
		iLen=strlen(sTemp);
		pc=sTemp;
		
		strncpy(sInNetWork,sTemp+933,1);
		sInNetWork[1]=0;
		strncpy(sInOperators,sTemp+935,1);
		sInOperators[1]=0;
		strncpy(sOutNetWork,sTemp+948,1);
		sOutNetWork[1]=0;
		strncpy(sOutOperators,sTemp+950,1);
		sOutOperators[1]=0;
		/*
		if(strncmp(pc,"4600",4)==0||strncmp(pc,"4601",4)==0||pc[0]==' ')
			iRet=item2list(&pGn,sTemp,iLen+1);
		else
			iRet=item2list(&pGj,sRecord,pTemp->iLen+1);
		*/
		if(strcmp(sInNetWork,"0")==0 && strcmp(sOutNetWork,"0")==0){
			/*GW_CT*/
			if((strcmp(sInOperators,"5")==0 
				&& strcmp(sOutOperators,"1")==0)
				|| (strcmp(sInOperators,"1")==0 
					&& strcmp(sOutOperators,"5")==0) ){
				 if(strncmp(sTemp+983,"C007",4)==0 
					|| strncmp(sTemp+983,"C207",4)==0
					|| strncmp(sTemp+998,"C007",4)==0
					|| strncmp(sTemp+998,"C207",4)==0){
					iRet=item2list(&pGCTC,sTemp,iLen+1);
				}else{
					iRet=item2list(&pGCT,sTemp,iLen+1);
				}
			}else if((strcmp(sInOperators,"2")==0 /*GW_CM*/
				&& strcmp(sOutOperators,"1")==0)
				|| (strcmp(sInOperators,"1")==0 
					&& strcmp(sOutOperators,"2")==0) ){
					iRet=item2list(&pGCM,sTemp,iLen+1);
			}else if((strcmp(sInOperators,"4")==0 /*GW_CRC*/
				&& strcmp(sOutOperators,"1")==0)
				|| (strcmp(sInOperators,"1")==0 
					&& strcmp(sOutOperators,"4")==0) ){
					iRet=item2list(&pGCRC,sTemp,iLen+1);
			}else{/*GW_OTH*/
				iRet=item2list(&pOTH,sTemp,iLen+1);
			}
		}else if(strcmp(sInNetWork,"1")==0 && strcmp(sOutNetWork,"1")==0){
			 if(strncmp(sTemp+932,"S127",4)==0
				|| strncmp(sTemp+947,"S127",4)==0){
				iRet=item2list(&pNCTC,sTemp,iLen+1);
				}else if(strncmp(sTemp+983,"C007",4)==0 
					|| strncmp(sTemp+983,"C207",4)==0
					|| strncmp(sTemp+998,"C007",4)==0
					|| strncmp(sTemp+998,"C207",4)==0){
					iRet=item2list(&pNCTC,sTemp,iLen+1);
				}else if((strcmp(sInOperators,"5")==0 
				&& strcmp(sOutOperators,"3")==0)
				|| (strcmp(sInOperators,"3")==0 
					&& strcmp(sOutOperators,"5")==0) ){
					iRet=item2list(&pNCT,sTemp,iLen+1);
			}else if((strcmp(sInOperators,"2")==0 /*YD_CM*/
				&& strcmp(sOutOperators,"3")==0)
				|| (strcmp(sInOperators,"3")==0 
					&& strcmp(sOutOperators,"2")==0) ){
				iRet=item2list(&pNCM,sTemp,iLen+1);
			}else if((strcmp(sInOperators,"4")==0 /*YD_CRC*/
				&& strcmp(sOutOperators,"3")==0)
				|| (strcmp(sInOperators,"3")==0 
					&& strcmp(sOutOperators,"4")==0) ){
				iRet=item2list(&pNCRC,sTemp,iLen+1);
			}else if((strcmp(sInOperators,"1")==0 /*YD_CNC*/
				&& strcmp(sOutOperators,"3")==0)
				|| (strcmp(sInOperators,"3")==0 
					&& strcmp(sOutOperators,"1")==0) ){
					iRet=item2list(&pNCNC,sTemp,iLen+1);
			}else{/*YD_OTH*/
				iRet=item2list(&pOTH,sTemp,iLen+1);
			}
		}else if(strcmp(sInNetWork,"1")==0 && strcmp(sOutNetWork,"0")==0
			 || strcmp(sInNetWork,"0")==0 && strcmp(sOutNetWork,"1")==0){
			if(strcmp(sInOperators,"1")==0 && strcmp(sOutOperators,"2")==0
				|| strcmp(sInOperators,"2")==0 && strcmp(sOutOperators,"1")==0){
				iRet=item2list(&pGCM,sTemp,iLen+1);
			}else if(strcmp(sInOperators,"1")==0 && strcmp(sOutOperators,"5")==0
				|| strcmp(sInOperators,"5")==0 && strcmp(sOutOperators,"1")==0){
				 if(strncmp(sTemp+983,"C007",4)==0 
					|| strncmp(sTemp+983,"C207",4)==0
					|| strncmp(sTemp+998,"C007",4)==0
					|| strncmp(sTemp+998,"C207",4)==0){
					iRet=item2list(&pGCTC,sTemp,iLen+1);
				}else{
					iRet=item2list(&pGCT,sTemp,iLen+1);
				}
			}else if(strcmp(sInOperators,"1")==0 && strcmp(sOutOperators,"4")==0
				|| strcmp(sInOperators,"4")==0 && strcmp(sOutOperators,"1")==0){
				iRet=item2list(&pGCRC,sTemp,iLen+1);	
			}else{
				iRet=item2list(&pOTH,sTemp,iLen+1);
			}
		}else if(strcmp(sInNetWork,"1")==0 && strcmp(sOutNetWork,"0")==0
			 || strcmp(sInNetWork,"0")==0 && strcmp(sOutNetWork,"1")==0){
			 if(strncmp(sTemp+932,"S127",4)==0
				|| strncmp(sTemp+947,"S127",4)==0){
				iRet=item2list(&pNCTC,sTemp,iLen+1);
				}else if(strncmp(sTemp+983,"C007",4)==0 
					|| strncmp(sTemp+983,"C207",4)==0
					|| strncmp(sTemp+998,"C007",4)==0
					|| strncmp(sTemp+998,"C207",4)==0){
					iRet=item2list(&pNCTC,sTemp,iLen+1);
				}else if((strcmp(sInOperators,"5")==0 
					&& strcmp(sOutOperators,"3")==0)
					|| (strcmp(sInOperators,"3")==0 
						&& strcmp(sOutOperators,"5")==0) ){
					iRet=item2list(&pNCT,sTemp,iLen+1);	
				}else if((strcmp(sInOperators,"2")==0 /*YD_CM*/
					&& strcmp(sOutOperators,"3")==0)
					|| (strcmp(sInOperators,"3")==0 
						&& strcmp(sOutOperators,"2")==0) ){
					iRet=item2list(&pNCM,sTemp,iLen+1);
				}else if((strcmp(sInOperators,"4")==0 /*YD_CRC*/
					&& strcmp(sOutOperators,"3")==0)
					|| (strcmp(sInOperators,"3")==0 
						&& strcmp(sOutOperators,"4")==0) ){
					iRet=item2list(&pNCRC,sTemp,iLen+1);
				}else if((strcmp(sInOperators,"1")==0 /*YD_CNC*/
					&& strcmp(sOutOperators,"3")==0)
					|| (strcmp(sInOperators,"3")==0 
						&& strcmp(sOutOperators,"1")==0) ){
					iRet=item2list(&pNCNC,sTemp,iLen+1);
				}else{/*YD_OTH*/
					iRet=item2list(&pOTH,sTemp,iLen+1);
				}
			
			}else{
				/*OTH*/
				iRet=item2list(&pOTH,sTemp,iLen+1);
			}
		if(iRet<0){
			printf("生成文件 %s 链表失败.\n",sFileName);
			return -1;
		}
	}
	/*
	sprintf(sGCTName,"%s%s.GCT",sGnDir,sBaseName);
	sprintf(sGCMName,"%s%s.GCM",sGnDir,sBaseName);
	sprintf(sGCRCName,"%s%s.GCRC",sGnDir,sBaseName);
	sprintf(sGCTCName,"%s%s.GCTC",sGnDir,sBaseName);
	sprintf(sOTHName,"%s%s.OTH",sGnDir,sBaseName);
	sprintf(sNCTName,"%s%s.NCT",sGnDir,sBaseName);
	sprintf(sNCMName,"%s%s.NCM",sGnDir,sBaseName);
	sprintf(sNCRCName,"%s%s.NCRC",sGnDir,sBaseName);
	sprintf(sNCTCName,"%s%s.NCTC",sGnDir,sBaseName);
	sprintf(sNCNCName,"%s%s.NCNC",sGnDir,sBaseName);
	*/
	sprintf(sGCTName,"%s%s.0",sGnDir,sBaseName);
	sprintf(sGCMName,"%s%s.1",sGnDir,sBaseName);
	sprintf(sGCRCName,"%s%s.2",sGnDir,sBaseName);
	sprintf(sGCTCName,"%s%s.3",sGnDir,sBaseName);
	sprintf(sOTHName,"%s%s.4",sGnDir,sBaseName);
	sprintf(sNCTName,"%s%s.5",sGnDir,sBaseName);
	sprintf(sNCMName,"%s%s.6",sGnDir,sBaseName);
	sprintf(sNCRCName,"%s%s.7",sGnDir,sBaseName);
	sprintf(sNCTCName,"%s%s.8",sGnDir,sBaseName);
	sprintf(sNCNCName,"%s%s.9",sGnDir,sBaseName);
	
	if(list2file(&pGCT,sGCTName)<0){
		printf("输出文件%s错误.\n",sGCTName);
		return -1;
	}
	if(list2file(&pGCM,sGCMName)<0){
		printf("输出文件%s错误.\n",sGCMName);
		return -1;
	}
	if(list2file(&pGCRC,sGCRCName)<0){
		printf("输出文件%s错误.\n",sGCRCName);
		return -1;
	}
	if(list2file(&pGCTC,sGCTCName)<0){
		printf("输出文件%s错误.\n",sGCTCName);
		return -1;
	}
	if(list2file(&pOTH,sOTHName)<0){
		printf("输出文件%s错误.\n",sOTHName);
		return -1;
	}
	if(list2file(&pNCT,sNCTName)<0){
		printf("输出文件%s错误.\n",sNCTName);
		return -1;
	}
	if(list2file(&pNCM,sNCMName)<0){
		printf("输出文件%s错误.\n",sNCMName);
		return -1;
	}
	if(list2file(&pNCRC,sNCRCName)<0){
		printf("输出文件%s错误.\n",sNCRCName);
		return -1;
	}
	if(list2file(&pNCTC,sNCTCName)<0){
		printf("输出文件%s错误.\n",sGCTCName);
		return -1;
	}
	if(list2file(&pNCNC,sNCNCName)<0){
		printf("输出文件%s错误.\n",sNCNCName);
		return -1;
	}
	
	printf("拆分文件%s成功.\n",sFileName);
	
	return 0;
}
