#include <hnixs.h>
#include <list.h>
#include <bintree.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwsupp.h>
#include <stt_ticket.h>
#include <ticket_field.h>


int DomesticImsi(char sImsi[]);

struct PrepTicketStruct *pImeiList=NULL;

static void mymvitem_fmprepticket(struct FPrepTicketStruct *pi,
	int len,struct PrepTicketStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct PrepTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sLac,		pi->sLac,4);
		strncpy(po->sCellID,		pi->sCellID,4);
		strncpy(po->sOtherLac,		pi->sOtherLac,4);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,4);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sMsrn,		pi->sMsrn,12);
/*	
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sReserve1,		pi->sReserve1,2);
*/
		strncpy(po->sEsn,		pi->sEsn,15);

		strncpy(po->sScpFlag,		pi->sScpFlag,1);
		strncpy(po->sDeformFlag,	pi->sDeformFlag,1);
		strncpy(po->sReserve,		pi->sReserve,8);

		if(len==sizeof(struct FPrepTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);

			AllTrim(po->sErrCode);
			AllTrim(po->sFileName);
			AllTrim(po->sModule);
			AllTrim(po->sAreaCode);
		}

		AllTrim(po->sCallType);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsrn);
/*		AllTrim(po->sUserType);
		AllTrim(po->sReserve1);
*/
		AllTrim(po->sEsn);
		AllTrim(po->sReserve);
}
int data_search_bintree_mdn_imsi_imei_e(void *pValue,void*pData)
{
	struct PrepTicketStruct *pSource=(struct PrepTicketStruct *)pValue;
	struct PrepTicketStruct *pTarget=(struct PrepTicketStruct *)pData;

/*数据比较部分*/
	int res=0;

	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sImsi,pTarget->sImsi))!=0) return res;
	if((res=strcmp(pSource->sEsn,pTarget->sEsn))!=0) return res;
	
	return 0;

}
void assign_insert_bintree_mdn_imsi_imei_e(void **ppData,void *pData)
{

	struct PrepTicketStruct *pTemp,*pValue;

	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct PrepTicketStruct));
		ERROR_EXIT(pTemp==NULL,"分配PrepTicket结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct PrepTicketStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}

	pValue=(struct PrepTicketStruct*)pData;

	if(strcmp(pValue->sStartTime,pTemp->sStartTime)>=0)
		strcpy(pTemp->sStartTime,pValue->sStartTime);
}

int AddPrepFileToBin(BINTREE **ppRoot,char sFileName[])
{
	struct PrepTicketStruct Temp;
	struct FileControlStruct *ptHead=NULL,*pTemp;

	if(TxtFileToList(sFileName,&ptHead)<0){
		WriteAlertPrint("加载文件%s到内存失败",sFileName);
		return -1;
	}
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		mymvitem_fmprepticket((struct FPrepTicketStruct *)pTemp->pData,
			pTemp->iLen,&Temp);

		/*只有国内移动号码才做这个*/
		if(IS_MOB_NBR(Temp.sMsisdn)&&strlen(Temp.sImsi)>0&&
			DomesticImsi(Temp.sImsi)&&
			(strcmp(Temp.sCallType,"01")==0||
				strcmp(Temp.sCallType,"02")==0)&&
			IS_UNICOM_CDMA(Temp.sMsisdn)==false){
			if(InsertBin(ppRoot,(void *)&Temp,
				data_search_bintree_mdn_imsi_imei_e,
				assign_insert_bintree_mdn_imsi_imei_e)<0){
				WriteAlertPrint("生成BINTREE失败MDN,IMSI,IMEI");
				return -1;
			}
		}
		free(pTemp);
	}
	return 0;
}
int hook_imei_list(void **ppData)
{
	struct PrepTicketStruct *pTemp,*ptHead=(struct PrepTicketStruct *)(*ppData);

	ptHead=(struct PrepTicketStruct *)(*ppData);

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		InsertList((LIST**)&pImeiList,(LIST*)pTemp);
	}
	return 0;
}
int OutputList2ImeiFile(struct PrepTicketStruct *ptHead,char sTargetName[],int iSeq)
{
	FILE *fp;
	char sHostTime[15],sAreaCode[10],sCityCode[10];
	
	GetHostTime(sHostTime);
	
	if((fp=fopen(sTargetName,"w"))==NULL){
		WriteAlertPrint("打开%s文件写失败.",sTargetName);
		return -1;
	}
	
	if(fprintf(fp,"%04d%-3s%-14s%3s%010d%-40s\n",
		iSeq,"1.0",sHostTime,"BSS",CountList((LIST*)ptHead)," ")<0){

		WriteAlertPrint("写文件%s失败.",sTargetName);
		return -1;
	}
	
	while(ptHead!=NULL){
		
		strcpy(sCityCode,"");

		if(GetBelongCode(ptHead->sMsisdn,ptHead->sStartTime,sAreaCode)==FOUND)
			GetCityCode(sAreaCode,sCityCode);

/*		if(fprintf(fp,"%s\t%s\t%s\t%s\t%s\n",
			ptHead->sMsisdn,ptHead->sEsn,ptHead->sImsi,
			ptHead->sStartTime,sCityCode)<0){

			WriteAlertPrint("写文件%s失败.",sTargetName);
			return -1;
		}
*/
		if(fprintf(fp,"%s\t%s\t%s\t%s\n",
			ptHead->sMsisdn,ptHead->sEsn,
			ptHead->sImsi,ptHead->sStartTime)<0){

			WriteAlertPrint("写文件%s失败.",sTargetName);
			return -1;
		}
		ptHead=ptHead->pNext;
	}	
	fclose(fp);

	return 0;
}
void GetAppSeqName(char sAppSeqName[])
{
	char sAppHome[256];
	
	GetAppHome(sAppHome);
	
	sprintf(sAppSeqName,"%s%s/genimei.seq",sAppHome,"ctl");
}
int main(int argc,char *argv[])
{
	BINTREE *pRoot=NULL;
	int iSeq=0;
	struct FileControlStruct *ptLkHead=NULL,*ptHead,*pTemp;
	char sCmd[1024],sResult[1024];
	char sSourcePath[120],sFilter[20],sTargetPath[120],sAppSeqName[256];
	char sFileName[256],sTargetName[256],sHostDate[15],sTempName[256];
	
	if(argc!=4){
		printf("Usage: %s sourcedir filter targetpath\n",argv[0]);
		exit(1);
	}

	strcpy(sSourcePath,argv[1]);
	strcpy(sFilter,argv[2]);
	strcpy(sTargetPath,argv[3]);
	
	RegularDir(sSourcePath);
	RegularDir(sTargetPath);
	
	GetAppSeqName(sAppSeqName);
	
	if(IsFile(sAppSeqName)){
		sprintf(sCmd,"head -1 %s",sAppSeqName);
		if(exec2str(sCmd,sResult)<0){
			WriteAlertPrint("执行 %s 失败",sCmd);
			return -1;
		}
		iSeq=atoi(sResult);
	}
	iSeq=iSeq+1;
	
	if(iSeq>9999)iSeq=1;

	GetHostTime(sHostDate);sHostDate[12]=0;
	sprintf(sTargetName,"%sUII%s%s%04d.req",
		sTargetPath,sHostDate,"038",iSeq);

	if(dir2list(sSourcePath,sFilter,&ptLkHead)<0){
		WriteAlertPrint("生成文件列表失败 %s %s",sSourcePath,sFilter);
		return -1;
	}
	
	WriteProcPrint("加载%d个文件",CountList((LIST*)ptLkHead));

	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);
		sprintf(sTempName,"%s%s",sSourcePath,sFileName);

		if(AddPrepFileToBin(&pRoot,sTempName)<0) return -1;

	}

	TravelBin(pRoot,hook_imei_list);
	
	
	if(OutputList2ImeiFile(pImeiList,sTargetName,iSeq)<0) return -1;

	WriteProcPrint("生成%s文件成功",sTargetName);

	sprintf(sCmd,"echo %d > %s",iSeq,sAppSeqName);
	if(execcmd(sCmd)<0){
		WriteAlertPrint("执行 %s 失败",sCmd);
		return -1;
	}

	/*做一个循环删除调输入文件*/
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);
		sprintf(sTempName,"%s%s",sSourcePath,sFileName);
		
		unlink(sTempName);
	}
	
	return 0;
}

