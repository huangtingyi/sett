#include <stdio.h>
#include <stdlib.h>

#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwfile.h>
#include <wwdb.h>
#include <list.h>
#include <wwcoding.h>

/*单个结构申明*/
struct PrepTicketStruct{

	struct PrepTicketStruct *pNext;
	char    sCallType[3];		/* 呼叫类型 */
	char    sImsi[16];		/* IMSI */
	char    sMsisdn[16];		/* 用户号码 */
	char    sOtherParty[25];		/* 对端号码 */
	char    sStartTime[15];		/* 应答时间 */
	char    sDuration[7];		/* 时长 */
	char    sMsc[11];		/* MSC */
	char    sTrunkIn[9];		/* 入中继 */
	char    sTrunkOut[9];		/* 出中继 */
	char    sLac[5];		/* LAC */
	char    sCellID[5];		/* CELL_ID */
	char    sOtherLac[5];		/* 对端LAC */
	char    sOtherCellID[5];		/* 对端CELL_ID */
	char    sServiceType[4];		/* 业务类型 */
	char    sServiceCode[5];		/* 业务代码 */
	char    sThirdParty[16];		/* 第三方号码 */
	char    sMsrn[16];		/* MSRN */
	char    sEsn[16];		/* 电子串号 */
	char    sReserve[11];		/* 保留 */
	char    sDealDate[15];		/* 处理日期 */
	char    sSourceID[31];		/* 文件来源 */
	struct PrepTicketStruct *pLoadNext;
};
/*单个文件结构申明*/
struct FPrepTicketStruct{

	char    sCallType[2];
	char    sImsi[15];
	char    sMsisdn[15];
	char    sOtherParty[24];
	char    sStartTime[14];
	char    sDuration[6];
	char    sMsc[10];
	char    sTrunkIn[8];
	char    sTrunkOut[8];
	char    sLac[4];
	char    sCellID[4];
	char    sOtherLac[4];
	char    sOtherCellID[4];
	char    sServiceType[3];
	char    sServiceCode[4];
	char    sThirdParty[15];
	char    sMsrn[15];
	char    sEsn[15];
	char	sReserve[10];
};
void mvitem_fmprepticket(struct FPrepTicketStruct *pi,struct PrepTicketStruct *po)
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
		strncpy(po->sMsrn,		pi->sMsrn,15);
		strncpy(po->sEsn,		pi->sEsn,15);
		strncpy(po->sReserve,		pi->sReserve,10);
/*		strncpy(po->sDealDate,		pi->sDealDate,14);
		strncpy(po->sSourceID,		pi->sSourceID,30);MODIFYHERE*/

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
		AllTrim(po->sEsn);
		AllTrim(po->sReserve);
/*		AllTrim(po->sDealDate);
		AllTrim(po->sSourceID);	MODIFYHERE*/
}
int SearchDup(struct FileControlStruct *pDup,struct FileControlStruct *pValue)
{
	struct FileControlStruct *ptHead=pDup,*pTemp;
	struct PrepTicketStruct TempTarget,TempSource;
	
	mvitem_fmprepticket(
		(struct FPrepTicketStruct*)(pValue->pData),&TempSource);
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		mvitem_fmprepticket(
			(struct FPrepTicketStruct*)(pTemp->pData),&TempTarget);
		if(strcmp(TempSource.sCallType,TempTarget.sCallType)==0&&
			strcmp(TempSource.sMsisdn,TempTarget.sMsisdn)==0&&
			strcmp(TempSource.sOtherParty,TempTarget.sOtherParty)==0&&
			strcmp(TempSource.sStartTime,TempTarget.sStartTime)==0)
			return FOUND;
	}
	return NOTFOUND;
}
int exec2list11(char sCommand[256],struct FileControlStruct **pptHead)
{
	FILE *fp;
	int iRet,l;
	char sRecord[1024];
	
	*pptHead=NULL;
	
	fp=popen(sCommand,"r");
	
	while(!feof(fp)){
		if((l=wwfgets(sRecord,1024,fp))==0) continue;
		if(item2listtail(pptHead,(void*)sRecord,l)<0) return -1;
	}
	
	return pclose(fp);
}
int TestHp()
{
	struct PositionStruct Temp,*p;

	Temp.pData=NULL;
	Temp.iOffset=0;
	Temp.iLen=2;
	p=(struct PositionStruct*)(char*)malloc(sizeof(struct PositionStruct))+1;
	
	p->iOffset=Temp.iOffset;
	return 0;

}
int main()
{
	int iRet;
	char sCommand[256],sInput[1024];
	struct FileControlStruct *ptHead=NULL;
	
	TestHp(); return 0;
	
	iRet=exec2str("ls -rt ",sInput);
	sprintf(sCommand,"ls -rt /data1/ucjs/ticket/online/prep/FZGG01 | sed /%s/p ","FZGG01*.PRE");
	iRet=exec2list11(sCommand,&ptHead);
	
	return 0;
}
int main1(int argc,char *argv[])
{
	char sFileIn[256],sFileDup[256],sFileOut[256];
	struct FileControlStruct *pIn=NULL,*pDup=NULL,*pOut=NULL;
	struct FileControlStruct *ptHead=NULL,*pTemp;

	
	if(argc!=4){
		printf("Usage %s filein filedup fileout.\n",argv[0]);
		return 0;
	}
	strcpy(sFileIn,argv[1]);
	strcpy(sFileDup,argv[2]);
	strcpy(sFileOut,argv[3]);
	
	if(TxtFileToList(sFileIn,&pIn)<0){
		printf("加载文件%s到内存失败.\n",sFileIn);
		return -1;
	}
	if(TxtFileToList(sFileDup,&pDup)<0){
		printf("加载文件%s到内存失败.\n",sFileDup);
		return -1;
	}
	ptHead=pIn;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(SearchDup(pDup,pTemp)==FOUND) continue;
		
		InsertList((LIST**)&pOut,(LIST*)pTemp);
	}
	if(list2fileln(&pOut,sFileOut)<0){
		printf("写入文件%s失败.\n",sFileOut);
		return -1;
	}
	listfree(&pIn);listfree(&pDup);
	
	return 0;
}
