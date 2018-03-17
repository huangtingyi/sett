#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwtiny.h>
#include <bintree.h>
#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <ticket_field.h>
#include <tariff_disct.h>

#include <ticket.h>
#include <stt_ticket.h>
#include "cdma1xprep.h"

struct Cdma1xPrepStruct *pOutputFile=NULL;
struct Cdma1xPrepStruct *pOutputBuf=NULL;


void mvitem_str2cdma1xprep(char sTemp[],struct Cdma1xPrepStruct *p)
{
	bzero((void*)p,sizeof(struct Cdma1xPrepStruct));
	
	GetSepStrX(sTemp,'\t',0	 ,10,	p->sSequencenum		);
	GetSepStrX(sTemp,'\t',1	 ,4,	p->sAccountingStatusType	);
	GetSepStrX(sTemp,'\t',2	 ,15,	p->sMsid               	);
	GetSepStrX(sTemp,'\t',3	 ,15,	p->sIp                 	);
	GetSepStrX(sTemp,'\t',4	 ,64,	p->sNai                 );
        GetSepStrX(sTemp,'\t',5  ,8,	p->sAccountSessionID    );
        GetSepStrX(sTemp,'\t',6  ,8,	p->sCorrelationID       );
        GetSepStrX(sTemp,'\t',7  ,4,	p->sSessionContinue      );
        GetSepStrX(sTemp,'\t',8  ,15,	p->sMipHomeAgent        );
        GetSepStrX(sTemp,'\t',9  ,15,	p->sPdsn                );
        GetSepStrX(sTemp,'\t',10 ,15,	p->sServingPcf          );
        GetSepStrX(sTemp,'\t',11 ,12,	p->sBsid                );
        GetSepStrX(sTemp,'\t',12 ,10,	p->sUserZone            );
        GetSepStrX(sTemp,'\t',13 ,4,	p->sForwardTarfficType  );
        GetSepStrX(sTemp,'\t',14 ,4,	p->sReverseMuxOption    );
        GetSepStrX(sTemp,'\t',15 ,4,	p->sServiceOption       );
        GetSepStrX(sTemp,'\t',16 ,4,	p->sForwardTrafficType  );
        GetSepStrX(sTemp,'\t',17 ,4,	p->sReverseTrafficType  );
        GetSepStrX(sTemp,'\t',18 ,4,	p->sFundamentaFrameSice );
        GetSepStrX(sTemp,'\t',19 ,4,	p->sForwardFundamenta   );
        GetSepStrX(sTemp,'\t',20 ,4,	p->sReverseFundamenta   );
        GetSepStrX(sTemp,'\t',21 ,4,	p->sIpTechnology        );
        GetSepStrX(sTemp,'\t',22 ,4,	p->sCompulsoryTunnel    );
        GetSepStrX(sTemp,'\t',23 ,4,	p->sReleaseIndicator    );
        GetSepStrX(sTemp,'\t',24 ,4,	p->sDcch                );
        GetSepStrX(sTemp,'\t',25 ,10,	p->sDataOctetCountUp    );
        GetSepStrX(sTemp,'\t',26 ,10,	p->sDataOctetCountDown  );
        GetSepStrX(sTemp,'\t',27 ,10,	p->sBadPpp              );
        GetSepStrX(sTemp,'\t',28 ,10,	p->sEventTime           );
        GetSepStrX(sTemp,'\t',29 ,10,	p->sActiveTime          );
        GetSepStrX(sTemp,'\t',30 ,10,	p->sNumberActive        );
        GetSepStrX(sTemp,'\t',31 ,10,	p->sSdbOctetCountDonw   );
        GetSepStrX(sTemp,'\t',32 ,10,	p->sSdbOctetCountUp     );
        GetSepStrX(sTemp,'\t',33 ,10,	p->sNumberSdbsDown      );
        GetSepStrX(sTemp,'\t',34 ,10,	p->sNumberSdbsUp        );
        GetSepStrX(sTemp,'\t',35 ,10,	p->sNumberHdlc          );
        GetSepStrX(sTemp,'\t',36 ,10,	p->sBoundMobile         );
        GetSepStrX(sTemp,'\t',37 ,10,	p->sOutBoundMobile      );
        GetSepStrX(sTemp,'\t',38 ,10,	p->sIpQualityService    );
        GetSepStrX(sTemp,'\t',39 ,10,	p->sAirlikeQuality      );
        GetSepStrX(sTemp,'\t',40 ,10,	p->sAirlikeRecoredType  );
        GetSepStrX(sTemp,'\t',41 ,10,	p->sRpSessionID         );
        GetSepStrX(sTemp,'\t',42 ,10,	p->sAirlikeSequenceNumber);
        GetSepStrX(sTemp,'\t',43 ,10,	p->sMobileTerminated	);
        GetSepStrX(sTemp,'\t',44 ,20,	p->sMdn                 );
        GetSepStrX(sTemp,'\t',45 ,10,	p->sUserType            );
        GetSepStrX(sTemp,'\t',46 ,10,	p->sNaiBureald          );
        GetSepStrX(sTemp,'\t',47 ,10,	p->sRoamingID           );
/*        GetSepStrX(sTemp,'\t',48 ,19,	p->sEsn                 );*/

	p->pNext=NULL;	
}

int ReadCdma1xPrep2List(char sFileName[],struct Cdma1xPrepStruct **pptHead)
{
	char	sTemp[8192];
	struct	FileControlStruct *pTemp=NULL,*ptHead=NULL;
	struct	Cdma1xPrepStruct *p=NULL;
	
	*pptHead=NULL;

	if(TxtFileToList(sFileName,&ptHead)<0) return -1;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
	/*忽略太长的行*/
		if(pTemp->iLen>=8192) continue;

		strncpy(sTemp,(char*)pTemp->pData,pTemp->iLen);
		sTemp[pTemp->iLen]=0;
		/*TrimAll(sTemp);*/
	/*忽略太短的行*/
		if(strlen(sTemp)<100) continue;
		
		if((p=(struct Cdma1xPrepStruct*)malloc(
			sizeof(struct Cdma1xPrepStruct)))==NULL){
			WriteAlertPrint("分配内存Cdma1xPrepStruct失败,退出!");
			return -1;
		}

	/*将行记录转换结构格式*/
		mvitem_str2cdma1xprep(sTemp,p);

		InsertList((LIST**)pptHead,(LIST*)p);

	}

	return 0;
}

void PrintList(struct Cdma1xPrepStruct **ppHead)
{
	struct Cdma1xPrepStruct *pTemp=*ppHead;
	while(pTemp!=NULL){
		printf("%s\t%s\n",pTemp->sAccountSessionID,pTemp->sEventTime);
		pTemp=pTemp->pNext;
	}
}


int WriteCdma1xPrep2List(struct FileControlStruct **ppHead,
	struct Cdma1xPrepStruct *pData)
{
	int l=0;
	char sTemp[8196];

	l+=sprintf(sTemp+l,"%s\t",pData->sSequencenum		);			
	l+=sprintf(sTemp+l,"%s\t",pData->sAccountingStatusType  	);
	l+=sprintf(sTemp+l,"%s\t",pData->sMsid                 	);
	l+=sprintf(sTemp+l,"%s\t",pData->sIp                   	);
	l+=sprintf(sTemp+l,"%s\t",pData->sNai                     );
	l+=sprintf(sTemp+l,"%s\t",pData->sAccountSessionID        );
	l+=sprintf(sTemp+l,"%s\t",pData->sCorrelationID           );
	l+=sprintf(sTemp+l,"%s\t",pData->sSessionContinue          );
	l+=sprintf(sTemp+l,"%s\t",pData->sMipHomeAgent            );
	l+=sprintf(sTemp+l,"%s\t",pData->sPdsn                    );
	l+=sprintf(sTemp+l,"%s\t",pData->sServingPcf              );
	l+=sprintf(sTemp+l,"%s\t",pData->sBsid                    );
	l+=sprintf(sTemp+l,"%s\t",pData->sUserZone                );
	l+=sprintf(sTemp+l,"%s\t",pData->sForwardTarfficType      );
	l+=sprintf(sTemp+l,"%s\t",pData->sReverseMuxOption        );
	l+=sprintf(sTemp+l,"%s\t",pData->sServiceOption           );
	l+=sprintf(sTemp+l,"%s\t",pData->sForwardTrafficType      );
	l+=sprintf(sTemp+l,"%s\t",pData->sReverseTrafficType      );
	l+=sprintf(sTemp+l,"%s\t",pData->sFundamentaFrameSice     );
	l+=sprintf(sTemp+l,"%s\t",pData->sForwardFundamenta       );
	l+=sprintf(sTemp+l,"%s\t",pData->sReverseFundamenta       );
	l+=sprintf(sTemp+l,"%s\t",pData->sIpTechnology            );
	l+=sprintf(sTemp+l,"%s\t",pData->sCompulsoryTunnel        );
	l+=sprintf(sTemp+l,"%s\t",pData->sReleaseIndicator        );
	l+=sprintf(sTemp+l,"%s\t",pData->sDcch                    );
	l+=sprintf(sTemp+l,"%s\t",pData->sDataOctetCountUp        );
	l+=sprintf(sTemp+l,"%s\t",pData->sDataOctetCountDown      );
	l+=sprintf(sTemp+l,"%s\t",pData->sBadPpp                  );
	l+=sprintf(sTemp+l,"%s\t",pData->sEventTime               );
	l+=sprintf(sTemp+l,"%s\t",pData->sActiveTime              );
	l+=sprintf(sTemp+l,"%s\t",pData->sNumberActive            );
	l+=sprintf(sTemp+l,"%s\t",pData->sSdbOctetCountDonw       );
	l+=sprintf(sTemp+l,"%s\t",pData->sSdbOctetCountUp         );
	l+=sprintf(sTemp+l,"%s\t",pData->sNumberSdbsDown          );
	l+=sprintf(sTemp+l,"%s\t",pData->sNumberSdbsUp            );
	l+=sprintf(sTemp+l,"%s\t",pData->sNumberHdlc              );
	l+=sprintf(sTemp+l,"%s\t",pData->sBoundMobile             );
	l+=sprintf(sTemp+l,"%s\t",pData->sOutBoundMobile          );
	l+=sprintf(sTemp+l,"%s\t",pData->sIpQualityService        );
	l+=sprintf(sTemp+l,"%s\t",pData->sAirlikeQuality          );
	l+=sprintf(sTemp+l,"%s\t",pData->sAirlikeRecoredType      );
	l+=sprintf(sTemp+l,"%s\t",pData->sRpSessionID             );
	l+=sprintf(sTemp+l,"%s\t",pData->sAirlikeSequenceNumber   );
	l+=sprintf(sTemp+l,"%s\t",pData->sMobileTerminated        );
	l+=sprintf(sTemp+l,"%s\t",pData->sMdn                     );
	l+=sprintf(sTemp+l,"%s\t",pData->sUserType                );
	l+=sprintf(sTemp+l,"%s\t",pData->sNaiBureald              );
	l+=sprintf(sTemp+l,"%s\t\r\n",pData->sRoamingID               );
/*	l+=sprintf(sTemp+l,"%s\r\n",pData->sEsn                     );*/

	return item2list(ppHead,(void*)sTemp,l);
}

int data_search_bintree_cdma1xbuffile(void *pValue,void*pData)
{               	
	struct Cdma1xPrepStruct *pSource=(struct Cdma1xPrepStruct *)pValue;
	struct Cdma1xPrepStruct *pTarget=(struct Cdma1xPrepStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sMsid,pTarget->sMsid))!=0) return res;
	if((res=strcmp(pSource->sIp,pTarget->sIp))!=0) return res;
	if((res=strcmp(pSource->sNai,pTarget->sNai))!=0) return res;
	if((res=strcmp(pSource->sAccountSessionID,pTarget->sAccountSessionID))!=0) return res;
	if((res=strcmp(pSource->sRpSessionID,pTarget->sRpSessionID))!=0) return res;

	return res;
}
void ConvertAccountingStatusType(char sOriType[],char sType[])
{
	if(strcmp(sOriType,"1")==0)	strcpy(sType,"1");
	else if(strcmp(sOriType,"2")==0)strcpy(sType,"3");
	else if(strcmp(sOriType,"3")==0)strcpy(sType,"2");
	else	strcpy(sType,"0");
}
int key_comp_cdma1xbuffile_e(LIST *pValue,LIST *pData)
{
        struct Cdma1xPrepStruct *pSource=(struct Cdma1xPrepStruct *)pValue;
        struct Cdma1xPrepStruct *pTarget=(struct Cdma1xPrepStruct *)pData;
        char	sSourceType[2],sTargetType[2];
        int res;
        
	if((res=strcmp(pSource->sEventTime,pTarget->sEventTime))!=0) return res;
	ConvertAccountingStatusType(pSource->sAccountingStatusType,sSourceType);
	ConvertAccountingStatusType(pTarget->sAccountingStatusType,sTargetType);
	return strcmp(sSourceType,sTargetType);
}

void assign_insert_bintree_cdma1xbuffile(void **ppData,void *pData)
{       	
	InsertListSort((LIST**)ppData,(LIST*)pData,
        	key_comp_cdma1xbuffile_e);
}

int GenCdma1xBin(BINTREE **ppRoot,char sTicketFile[],char sBufFile[])
{
	struct	Cdma1xPrepStruct *ptHead=NULL,*pTemp;

	if(ReadCdma1xPrep2List(sTicketFile,&ptHead)<0){
		WriteAlertPrint("读取CDMA1X AAA 预处理缓冲文件%s失败", sTicketFile);
		return -1;
	}
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
				
	        if(InsertBin(ppRoot,(void *)pTemp,
			data_search_bintree_cdma1xbuffile,
			assign_insert_bintree_cdma1xbuffile)<0){
			WriteAlertMsg("生成BINTREE失败CDMA1XBUFFILE");
			return -1;
		}
	}
	
	if(IsFile(sBufFile)==FALSE){
		printf("缓冲文件文件%s不存在.\n",sBufFile);
		return 0;
	}
	
	if(ReadCdma1xPrep2List(sBufFile,&ptHead)<0){
		WriteAlertPrint("读取CDMA1X AAA 预处理缓冲文件%s失败",sBufFile);
		return -1;
	}
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
				
	        if(InsertBin(ppRoot,(void *)pTemp,
			data_search_bintree_cdma1xbuffile,
			assign_insert_bintree_cdma1xbuffile)<0){
			WriteAlertMsg("生成BINTREE失败CDMA1XBUFFILE");
			return -1;
		}
	}

	return 0;
	
}
/*终止话单到来，则返回真*/
int SessionStopTicketCome(struct Cdma1xPrepStruct *ptHead)
{
	while(ptHead!=NULL){
		if(strcmp(ptHead->sAccountingStatusType,"2")==0) return true;
		ptHead=ptHead->pNext;
	}
	return false;
}
/*该SESSION是否超时*/
int SessionTicketOverTime(struct Cdma1xPrepStruct *ptHead)
{
	struct Cdma1xPrepStruct *pTemp=NULL;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
	}
	if(pTemp==NULL) return false;
	
	if((tGetHostTime()-atoi(pTemp->sEventTime))>86400) return true;
	return false;
}
/*获取一个完整Session的话单*/
struct Cdma1xPrepStruct *GetSessionTicket(struct Cdma1xPrepStruct *ptHead,
	struct Cdma1xPrepStruct **ppTail)
{
	struct Cdma1xPrepStruct *ptPre=NULL,*ptCur;
	
	ptCur=ptHead;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(strcmp(ptPre->sAccountingStatusType,"2")==0){

			*ppTail=ptPre->pNext;
			ptPre->pNext=NULL;
			return ptHead;
		}
	}
	*ppTail=NULL;
	return NULL;
}
/*调整链表中结束话单的ActiveTime*/
void AdjustStopTicketActiveTime(struct Cdma1xPrepStruct *ptHead)
{
	struct Cdma1xPrepStruct *pStart=NULL,*pStop=NULL,*pFirstMid=NULL;
	
	while(ptHead!=NULL){

		if(strcmp(ptHead->sAccountingStatusType,"1")==0) pStart=ptHead;
		else if(strcmp(ptHead->sAccountingStatusType,"2")==0) pStop=ptHead;
		else if(strcmp(ptHead->sAccountingStatusType,"3")==0&&
			pFirstMid==NULL)pFirstMid=ptHead;

		ptHead=ptHead->pNext;
	}
	if(pStart==NULL) pStart=pFirstMid;
	
	if(pStop!=NULL){

		if(atoi(pStop->sActiveTime)==0&&pStart!=NULL){
			sprintf(pStop->sActiveTime,"%d",
			atoi(pStop->sEventTime)-atoi(pStart->sEventTime));
		}
	}
}
/*遍历单个节点的主函数，将话单分别插入输出链表和Buf链表中*/
int ProcessBinTreeNode(void **ppData)
{
	struct Cdma1xPrepStruct *ptHead=(*ppData),*pTail=NULL;

	while(SessionStopTicketCome(ptHead)){

		ptHead=GetSessionTicket(ptHead,&pTail);
		/*检查是否是单张结束话单，如果是则检查是否超时(默认一个小时)*/
		if(CountList((LIST*)ptHead)==1){
			if(tGetHostTime()-atoi(ptHead->sEventTime)>3600)
				InsertList((LIST**)&pOutputFile,(LIST*)ptHead);
			else	InsertList((LIST**)&pOutputBuf,(LIST*)ptHead);

			ptHead=pTail;
			continue;
		}
		/*变换ptHead链表，达到时间合并;*/
		AdjustStopTicketActiveTime(ptHead);

		/*将ptHead的链表加入pOutputFile中*/
		if(ptHead!=NULL){
			AppendListTail((LIST**)&ptHead,(LIST*)pOutputFile);
			pOutputFile=ptHead;
		}
		
		ptHead=pTail;
	}
	if(SessionTicketOverTime(ptHead)==true){

		/*将ptHead链表加入pOutputFile中*/
		if(ptHead!=NULL){
			AppendListTail((LIST**)&ptHead,(LIST*)pOutputFile);
			pOutputFile=ptHead;
		}
	}
	else{
		/*将链表加入到pOutputBuf中*/
		if(ptHead!=NULL){
			AppendListTail((LIST**)&ptHead,(LIST*)pOutputBuf);
			pOutputBuf=ptHead;
		}
	}
	*ppData=NULL;

	return 0;
}
int WriteCdma1xPrep2File(struct Cdma1xPrepStruct *pList,char sFileName[])
{
	struct FileControlStruct *pHead=NULL;
	struct Cdma1xPrepStruct *ptLkHead=pList;
	while(pList!=NULL){
		if(WriteCdma1xPrep2List(&pHead,pList)<0){
			printf("生成CDMA1X AAA 输出话单链表错误.\n");
			return -1;
		}
		pList=pList->pNext;
	}
	
	DestroyList((LIST*)ptLkHead);
	
	if(list2file(&pHead,sFileName)<0){                	
		printf("写CDMA1X AAA 文件%s失败.\n",sFileName);	
		return -1;
	}
	return 0;
}

int main(int argc,char *argv[])
{       
	char 	sFileName[256],sBaseName[256],sOutputPath[256],sOutputFile[256],
		sBufFilePath[256],sBufFile[256];
	BINTREE *pRoot=NULL;
	
	if(argc!=3){
		printf("Usage %s filename outputpath.\n",argv[0]);
		return -1;
	}
        
	InitAppRes(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sOutputPath,argv[2]);
	
	if(IsFile(sFileName)==FALSE){
		printf("话单文件%s无效.\n",sFileName);
		return -1;
	}
	GetBaseName(sFileName,sBaseName);
	
	RegularDir(sOutputPath);
	GetAppHome(sBufFilePath);	
	RegularDir(sBufFilePath);
	
	/*加载缓冲文件到内存*/
	sprintf(sBufFile,"%sctl/CDMA1X.buf",sBufFilePath);
	if(GenCdma1xBin(&pRoot,sFileName,sBufFile)<0){
		WriteAlertPrint("加载CDMA1X AAA 缓冲文件%s失败", sBufFile);
		return -1;
	}
	
	TravelBin(pRoot,ProcessBinTreeNode);
	DestroyBin(pRoot);
	
	sprintf(sOutputFile,"%s%s",sOutputPath,sBaseName);
	WriteCdma1xPrep2File(pOutputFile,sOutputFile);
	printf("CDMA1X AAA预处理话单%s输出成功\n",sOutputFile);
	WriteCdma1xPrep2File(pOutputBuf,sBufFile);

	return 0;
}
