#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>
#include <bintree.h>

#include "updata_ticket.h"

#define MAX_PROC_CNT 300000
#define MAX_PROC_CNT_A 300000
#define	MAX_PROC_CNT_B 3

struct UpdataCtlStruct
{
	int iHeadLen;
	int iTailLen;

	/* Member Function List */
	int  iChkDupFlag;
	/* Data Member List */
	char sFileType[6];
	char sSourcePath[256];
	char sBackPath[256];
	char sWorkPath[256];
	char sTargetPath[256];
	char sFilter[128];
	char sBelongCode[128];
	char sAppHome[128];
	char sCityCode[128];
	char sDataCityCode[8];
	char sTargetName[256];
	char sDataDate[15];
	int  iDelay;
	int  iUpdataID;
	char sPreHead[512];
	char sPreTail[512];
	struct UpdataLogStruct PreLog;
	char sHead[512];
	char sTail[512];
	char sAppID[11];
	char sAppFile[128];
	int  iTacheID;
	char sDealDate[15];
	struct FileControlStruct *pFileAll;
	struct UpdataLogStruct CurLog;
};

struct UpdataCtlStruct UPDCTL;

BINTREE *pRoot=NULL;/*重单过滤*/

/*文件列表处理*/
int (*XChkOriFileName)(char sOriFileName[]);
/*补空文件*/
int (*XGenNullFile)(int iMaxSeq);
/*将记录统计信息加入FILEHEAD和FILETAIL*/
int (*XSumRecInfo)(char sRecord[]);
/*初始化日志结构*/
int (*XInitUpdataLog)(char sStartTime[],struct UpdataLogStruct *pLog);
/*将FILEHEAD,FILEHEAD加入文件体，并写输出文件*/
int (*XWriteTargetFile)();
/*生成文件名*/
void (*XAssignFileName)(char sNextSeq[],char sTargetName[]);
/*生成文件头记录和文件尾记录*/
void (*XInitFileHeadTail)(int iUpdataID,struct UpdataLogStruct *p);
/*结束一次循环处理*/
int (*XComplateDealFile)();


/***************************************************************************/
/**函数头文件定义区*/
/***************************************************************************/

int ProcessFile(char sFileName[]);
void InitVisualFunc(char sFileType[]);
int CompDateSeq(char sCurDate[15],int iCurSeq,char sEndDate[15],int iEndSeq);
void NextDataSeq(int iMaxSeq,char sCurDate[15],int *piCurSeq);
void InitDataSeq(int iMaxSeq,char sEndDate[15],int *piCurSeq);
int GenNullFile(int iMaxSeq);
int CdmaAnd1XComplateDealFile();

void GetPosStr(char sStr[],int iStrLen,int iBgnPos,int iLen,char sResult[]);

int IsCdmaRI(char sFileType[]);
int IsCdmaII(char sFileType[]);
int IsGsmRI(char sFileType[]);
int IsGsmII(char sFileType[]);
int IsGCUpdata(char sFileType[]);

int IsCdma1xUp(char sFileType[]);
int IsCdma1x(char sFileType[]);
int IsRhjf(char sFileType[]);
int IsCdmaBill(char sFileType[]);
int IsGsmBill(char sFileType[]);
int IsSmsBill(char sFileType[]);

int IsNxRhjf(char sFileType[]);
int IsHbSmgDIntf(char sFileType[]);
int IsHbCardIntf(char sFileType[]);
int IsHbCardSn(char sFileType[]);
int IsHbCardGj(char sFileType[]);
int IsHbCard52(char sFileType[]);

int IsHbInfoIntf(char sFileType[]);
int IsHbInfoSn(char sFileType[]);
int IsHbInfoZb(char sFileType[]);

int IsBillTicket(char sFileType[]);
int IsSttIntf(char sFileType[]);
int IsNsmsIntf(char sFileType[]);

int IsNewGsmup( char sFileType[] );

int CheckType(char sType[]);

void ParseArg(int argc,char **argv);
int GetBelongCodeAndCityCode(char sBelongCode[5],char sCityCode[5],char sAppHome[128]);
int FileProc(char sFileName[]);
int FileFilter(int iDelay,char sFileName[]);
int InsertUpdataProcLog(char sOriFileName[],char sCurFileName[]);
int BackupFileList(struct FileControlStruct *ptHead,
	struct FileControlStruct *pEnd,char sSourcePath[],char sBackPath[]);

void cvhead_tail_ticket_cri(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen);
void cvhead_tail_ticket_cii(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen);
void cvhead_tail_ticket_jri(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen);
void cvhead_tail_ticket_jii(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen);

void InitUpdataLogBegin(int iSeq,char sFileType[],char sDataDate[],
	char sBelongCode[],struct UpdataLogStruct *p);
void InitUpdataLogEnd(struct UpdataLogStruct *p);

void AssignDateTime(char sFirstCallDate[],char sFirstCallTime[],
	char sEndCallDate[],char sEndCallTime[],const char sDateTime[]);

/*漫游上传下发处理函数集*/
int GCCRI_SumRecInfo(char sRecord[]);
int GCCII_SumRecInfo(char sRecord[]);
int GCJRI_SumRecInfo(char sRecord[]);
int GCJII_SumRecInfo(char sRecord[]);
int GCTRS_SumRecInfo(char sRecord[]);
int GCUpdata_SumRecInfo(char sRecord[]);
int GCUpdata_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int GCUpdata_WriteTargetFile();
void GCUpdata_AssignFileName(char sNextSeq[],char sTargetName[]);
void GCUpdata_InitFileHeadTail(int iUpdataID,struct UpdataLogStruct *p);

/*CDMA1X处理函数集*/
int Cdma1x_SumRecInfo(char sRecord[]);
int Cdma1x_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int Cdma1x_WriteTargetFile();
void Cdma1x_AssignFileName(char sNextSeq[],char sTargetName[]);
void Cdma1x_InitFileHead(int iUpdataID,struct UpdataLogStruct *p);

void Cdma1x_AssignFileName(char sNextSeq[],char sTargetName[]);
void C1X_CNG_AssignFileName(char sNextSeq[],char sTargetName[]);
void C1X_XRB_AssignFileName(char sNextSeq[],char sTargetName[]);
void C1X_XLO_AssignFileName(char sNextSeq[],char sTargetName[]);
void C1X_XIO_AssignFileName(char sNextSeq[],char sTargetName[]);
void C1X_XRO_AssignFileName(char sNextSeq[],char sTargetName[]);
void C1X_XRI_AssignFileName(char sNextSeq[],char sTargetName[]);
void GetCdma1xBillFileName(char sRoamType[],char sNextSeq[],
	char sSuffix[],char sFileName[]);
void Cdma1x_InitFileHead(int iUpdataID,struct UpdataLogStruct *p);

int Cdma_SumRecInfo(char sRecord[]);
int Cdma_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int Cdma_WriteTargetFile();


int Gsm_SumRecInfo(char sRecord[]);
int Gsm_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int Gsm_WriteTargetFile();
void Gsm_AssignFileName(char sNextSeq[],char sTargetName[]);
void Gsm_InitFileHead(int iUpdataID,struct UpdataLogStruct *p);

int Rhjf_SumRecInfo(char sRecord[]);
int Rhjf_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int Rhjf_WriteTargetFile();
void Rhjf_AssignFileName(char sNextSeq[],char sTargetName[]);
void Rhjf_InitFileHead(int iUpdataID,struct UpdataLogStruct *p);

int  Sms_SumRecInfo(char sRecord[]);
int  Sms_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int  Sms_WriteTargetFile();
void Sms_AssignFileName(char sNextSeq[],char sTargetName[]);
void Sms_InitFileHead(int iUpdataID,struct UpdataLogStruct *p);

int NxRhjf_SumRecInfo(char sRecord[]);
int NxRhjf_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int NxRhjf_WriteTargetFile();
void NxRhjf_AssignFileName(char sNextSeq[],char sTargetName[]);
void NxRhjf_InitFileHead(int iUpdataID,struct UpdataLogStruct *p);

int HbSmgD_SumRecInfo(char sRecord[]);
int HbSmgD_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int HbSmgD_WriteTargetFile();
void HbSmgD_AssignFileName(char sNextSeq[],char sTargetName[]);

int IsMonthTag(char sTempDate[],char sMonthTag[]);
int IsZnwSnLatnTag(char sLatnTag[]);
int HbCardSn_SumRecInfo(char sRecord[]);
int HbCardGj_SumRecInfo(char sRecord[]);
int HbCard52_SumRecInfo(char sRecord[]);
int HbCard_SumRecInfo(char sRecord[]);
int HbCard_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int HbCard_WriteTargetFile();
void HbCard_AssignFileName(char sNextSeq[],char sTargetName[]);

int HbInfo_SumRecInfo(char sRecord[]);
int HbInfoSn_SumRecInfo(char sRecord[]);
int HbInfoZb_SumRecInfo(char sRecord[]);
int HbInfo_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int HbInfo_WriteTargetFile();
void HbInfo_AssignFileName(char sNextSeq[],char sTargetName[]);

int Bill_ChkOriFileName(char sOriFileName[]);
int Bill_SumRecInfo(char sRecord[]);
int Stt_SumRecInfo(char sRecord[]);
int Nsms_SumRecInfo(char sRecord[]);
int Bill_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int Bill_WriteTargetFile();

void newcvhead_tail_ticket_cri(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen);
void newcvhead_tail_ticket_cii(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen);
int NewGCRI_SumRecInfo(char sRecord[]);
int NewGCII_SumRecInfo(char sRecord[]);
int NewGTRS_SumRecInfo(char sRecord[]);
int NewGUpdata_SumRecInfo(char sRecord[]);
int NewGUpdata_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int NewGUpdata_WriteTargetFile();
void NewGUpdata_AssignFileName(char sNextSeq[],char sTargetName[]);
void NewGUpdata_InitFileHeadTail(int iUpdataID,struct UpdataLogStruct *p);

int IsGprsjf(char sFileType[]);
int Gprsjf_SumRecInfo(char sRecord[]);
int Gprsjf_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog);
int Gprsjf_WriteTargetFile();
void Gprsjf_AssignFileName(char sNextSeq[],char sTargetName[]);
void Gprsjf_InitFileHead(int iUpdataID,struct UpdataLogStruct *p);


/**==============================**/
/*	中国电信C网改造		 **/
/**==============================**/
int IsNewCdmaBill(char sFileType[]);
int IsNewCdma1xBill(char sFileType[]);
int IsNewSmsBill(char sFileType[]);
int IsNewSmspBill(char sFileType[]);
void NewCdma1x_AssignFileName(char sNextSeq[],char sTargetName[]);
void NewSms_AssignFileName(char sNextSeq[],char sTargetName[]);

void InitVisualFunc(char sFileType[])
{
	if(IsGCUpdata(sFileType)){
		UPDCTL.iHeadLen=	512;
		UPDCTL.iTailLen=	512;
		XGenNullFile=		GenNullFile;
		XSumRecInfo=		GCUpdata_SumRecInfo;
		XInitUpdataLog=		GCUpdata_InitUpdataLog;
		XWriteTargetFile=	GCUpdata_WriteTargetFile;
		XAssignFileName=	GCUpdata_AssignFileName;
		XInitFileHeadTail=	GCUpdata_InitFileHeadTail;
	}
	else if(IsCdma1x(sFileType)){

		UPDCTL.iHeadLen=	sizeof(struct Cdma1xheadStruct);
		UPDCTL.iTailLen=	0;

	/*除了CDMA1x与总部上传1X要补空文件*/
		if(IsCdma1xUp(sFileType))XGenNullFile=GenNullFile;

		XSumRecInfo=		Cdma1x_SumRecInfo;
		XWriteTargetFile=	Cdma1x_WriteTargetFile;
		XAssignFileName=	Cdma1x_AssignFileName;
		XInitFileHeadTail=	Cdma1x_InitFileHead;
		XInitUpdataLog=		Cdma1x_InitUpdataLog;
		XComplateDealFile=	CdmaAnd1XComplateDealFile;
			
		UPDCTL.iChkDupFlag=1;
	}
	else if(IsCdmaBill(sFileType)){
		
		UPDCTL.iHeadLen=	sizeof(struct CdmaheadStruct);
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		Cdma_SumRecInfo;
		XWriteTargetFile=	Cdma_WriteTargetFile;
		XAssignFileName=	NULL;
		XInitFileHeadTail=	NULL;
		XInitUpdataLog=		Cdma_InitUpdataLog;
		XComplateDealFile=	CdmaAnd1XComplateDealFile;
	}
	else if(IsGsmBill(sFileType)){
		
		UPDCTL.iHeadLen=	sizeof(struct GsmHeadStruct);
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		Gsm_SumRecInfo;
		XWriteTargetFile=	Gsm_WriteTargetFile;
		XAssignFileName=	Gsm_AssignFileName;
		XInitFileHeadTail=	Gsm_InitFileHead;
		XInitUpdataLog=		Gsm_InitUpdataLog;
	}
	else if(IsRhjf(sFileType)){
		
		UPDCTL.iHeadLen=	sizeof(struct RhjfHeadStruct);
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		Rhjf_SumRecInfo;
		XWriteTargetFile=	Rhjf_WriteTargetFile;
		XAssignFileName=	Rhjf_AssignFileName;
		XInitFileHeadTail=	Rhjf_InitFileHead;
		XInitUpdataLog=		Rhjf_InitUpdataLog;		
	}
	else if(IsNxRhjf(sFileType)){
		
		UPDCTL.iHeadLen=	sizeof(struct NxRhjfHeadStruct);
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		NxRhjf_SumRecInfo;
		XWriteTargetFile=	NxRhjf_WriteTargetFile;
		XAssignFileName=	NxRhjf_AssignFileName;
		XInitFileHeadTail=	NxRhjf_InitFileHead;
		XInitUpdataLog=		NxRhjf_InitUpdataLog;		
	}
	else if(IsSmsBill(sFileType)){

		UPDCTL.iHeadLen=	sizeof(struct SmsHeadStruct);
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		Sms_SumRecInfo;
		XWriteTargetFile=	Sms_WriteTargetFile;
		XAssignFileName=	Sms_AssignFileName;
		XInitFileHeadTail=	Sms_InitFileHead;
		XInitUpdataLog=		Sms_InitUpdataLog;
	}
	else if(IsHbSmgDIntf(sFileType)){

		UPDCTL.iHeadLen=	0;
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		HbSmgD_SumRecInfo;
		XWriteTargetFile=	HbSmgD_WriteTargetFile;
		XAssignFileName=	HbSmgD_AssignFileName;
		XInitFileHeadTail=	NULL;
		XInitUpdataLog=		HbSmgD_InitUpdataLog;
	}
	else if(IsHbCardIntf(sFileType)){

		UPDCTL.iHeadLen=	512;
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		HbCard_SumRecInfo;
		XWriteTargetFile=	HbCard_WriteTargetFile;
		XAssignFileName=	HbCard_AssignFileName;
		XInitFileHeadTail=	NULL;
		XInitUpdataLog=		HbCard_InitUpdataLog;
	}
	else if(IsHbInfoIntf(sFileType)){

		UPDCTL.iHeadLen=	512;
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		HbInfo_SumRecInfo;
		XWriteTargetFile=	HbInfo_WriteTargetFile;
		XAssignFileName=	HbInfo_AssignFileName;
		XInitFileHeadTail=	NULL;
		XInitUpdataLog=		HbInfo_InitUpdataLog;
	}
	else if(IsBillTicket(sFileType)){

		UPDCTL.iHeadLen=	0;
		UPDCTL.iTailLen=	0;
		XChkOriFileName=	Bill_ChkOriFileName;
		XSumRecInfo=		Bill_SumRecInfo;
		XWriteTargetFile=	Bill_WriteTargetFile;
		XAssignFileName=	NULL;
		XInitFileHeadTail=	NULL;
		XInitUpdataLog=		Bill_InitUpdataLog;
	}
	else if(IsNewGsmup(sFileType)){
		UPDCTL.iHeadLen=	512;
		UPDCTL.iTailLen=	512;
		XGenNullFile=		GenNullFile;
		XSumRecInfo=		NewGUpdata_SumRecInfo;
		XInitUpdataLog=		NewGUpdata_InitUpdataLog;
		XWriteTargetFile=	NewGUpdata_WriteTargetFile;
		XAssignFileName=	NewGUpdata_AssignFileName;
		XInitFileHeadTail=	NewGUpdata_InitFileHeadTail;
	}
	else if(IsGprsjf(sFileType)){
		
		UPDCTL.iHeadLen=	sizeof(struct GprsHeadStruct);
		UPDCTL.iTailLen=	0;
		XGenNullFile=		GenNullFile;
		XSumRecInfo=		Gprsjf_SumRecInfo;
		XWriteTargetFile=	Gprsjf_WriteTargetFile;
		XAssignFileName=	Gprsjf_AssignFileName;
		XInitFileHeadTail=	Gprsjf_InitFileHead;
		XInitUpdataLog=		Gprsjf_InitUpdataLog;		
	}
	else if(IsNewCdmaBill(sFileType)){
		
		UPDCTL.iHeadLen=	sizeof(struct CdmaheadStruct);
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		Cdma_SumRecInfo;
		XWriteTargetFile=	Cdma_WriteTargetFile;
		XAssignFileName=	NULL;
		XInitFileHeadTail=	NULL;
		XInitUpdataLog=		Cdma_InitUpdataLog;
	}
	else if(IsNewCdma1xBill(sFileType)){
		UPDCTL.iHeadLen=	sizeof(struct Cdma1xheadStruct);
		UPDCTL.iTailLen=	0;

		XSumRecInfo=		Cdma1x_SumRecInfo;
		XWriteTargetFile=	Cdma1x_WriteTargetFile;
		XAssignFileName=	NewCdma1x_AssignFileName;
		XInitFileHeadTail=	Cdma1x_InitFileHead;
		XInitUpdataLog=		Cdma1x_InitUpdataLog;
			
		UPDCTL.iChkDupFlag=0;
	}
	else if(IsNewSmsBill(sFileType)||IsNewSmspBill(sFileType)){

		UPDCTL.iHeadLen=	sizeof(struct SmsHeadStruct);
		UPDCTL.iTailLen=	0;
		XSumRecInfo=		Sms_SumRecInfo;
		XWriteTargetFile=	Sms_WriteTargetFile;
		XAssignFileName=	NewSms_AssignFileName;
		XInitFileHeadTail=	Sms_InitFileHead;
		XInitUpdataLog=		Sms_InitUpdataLog;
	}
	else {
		CheckType(sFileType);
		exit(-1);
	}
}
void ResetHeadTail()
{
	memcpy((void*)UPDCTL.sHead,(void*)UPDCTL.sPreHead,512);
	memcpy((void*)UPDCTL.sTail,(void*)UPDCTL.sPreTail,512);
	memcpy((void*)&UPDCTL.CurLog,(void*)&UPDCTL.PreLog,
		sizeof(struct UpdataLogStruct));
}
void ArchHeadTail()
{
	memcpy((void*)UPDCTL.sPreHead,(void*)UPDCTL.sHead,512);
	memcpy((void*)UPDCTL.sPreTail,(void*)UPDCTL.sTail,512);
	memcpy((void*)&UPDCTL.PreLog,(void*)&UPDCTL.CurLog,
		sizeof(struct UpdataLogStruct));
}
void BackupFile(char sFileName[])
{
	execcmd("mv %s %s.err",sFileName,sFileName);
}
int main(int argc,char **argv)
{
	int iRet,iCnt=0;
	char msg[256];
	char sStartTime[15],sBaseName[128],sFileName[256],sLockName[256];
	struct FileControlStruct *ptHead=NULL,*pTemp=NULL,*ptLkHead=NULL;
	struct UpdataLogStruct TempLog;

	char sDupKeyFile[256];/*重单键值文件*/

	InitAppRes(argv[0]);

	ParseArg(argc,argv);

	/*获取城市代码等相关参数*/
	if(GetBelongCodeAndCityCode(UPDCTL.sBelongCode,
		UPDCTL.sCityCode,UPDCTL.sAppHome)<0){
		WriteAlertMsg("获取归属及城市代码失败");
		return -1;
	}

	/*初始化函数指针*/
	InitVisualFunc(UPDCTL.sFileType);

	if(ConnectDataDB()<0) return -1;

	GetHostTime(UPDCTL.sDealDate);

	/*补空文件,不需要的写空的函数*/
	if(XGenNullFile!=NULL){
		if((iRet=XGenNullFile(96))!=0){
			DisconnectDatabase();
			if(iRet<0){
				WriteAlertMsg("对文件类型为%s补空文件失败",
					UPDCTL.sFileType);
				return -1;
			}
			WriteProcMsg("文件类型为%s当前文件已经生成",
				UPDCTL.sFileType);
			return 0;
		}
	}

	/*生成要处理的文件列表*/
	if(dir2list(UPDCTL.sSourcePath,UPDCTL.sFilter,&ptHead)<0){
		WriteAlertMsg("获取要处理的文件列表失败，进程退出");
		return -1;
	}

	/*载入键值文件*/
	if(UPDCTL.iChkDupFlag){
		sprintf(sDupKeyFile,"%s%s.dup.key",UPDCTL.sSourcePath,UPDCTL.sFileType);
		LoadKeyFromFile(&pRoot,sDupKeyFile,delete_overtime_ticket);
	}

	/*锁定特定FILE_TYPE的UPDATA_INTF，以免冲突*/
	GetLogLock("INTF",UPDCTL.sFileType,"",sLockName);
	iRet=LockLog(sLockName,msg);
	
	if(iRet!=0){
		WriteAlertMsg("信息:%s，进程退出",msg);
		return iRet;
	}
	
	GetHostTime(sStartTime);
	/*保存ptLkHead记录，链表头用，以备份数据*/
	ptLkHead=ptHead;

	while(ptHead !=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sBaseName,pTemp->pData,pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		sprintf(sFileName,"%s%s",UPDCTL.sSourcePath,sBaseName);

		/*文件列表处理*/
		if(XChkOriFileName!=NULL){
			if(XChkOriFileName(sBaseName)<0){
				/*清除该文件*/
				strcpy((char*)pTemp->pData,"");
				continue;
			}
		}

		if((iRet=FileFilter(UPDCTL.iDelay,sFileName))!=0){
			/*间隔太小不备份，已经处理过备份*/
			strcpy((char*)(pTemp->pData),"");
			continue;
		}
		
		ResetHeadTail();
		
		/*处理当前文件*/
		if((iRet=ProcessFile(sFileName))<0){
			RollbackWork();
			DisconnectDatabase();	
			return iRet;
		}
		
		if(iRet==1){/*如果某个文件格式问题统计失败，则清除该文件*/
			strcpy((char*)pTemp->pData,"");
			BackupFile(sFileName);
			continue;
		}
		
		ArchHeadTail();
	
		/*达到处理最大数*/
		if(iRet==9) break;
	}

	/*保存键值文件*/
	if(UPDCTL.iChkDupFlag) SaveKeytoFile(&pRoot,sDupKeyFile);

	if(UPDCTL.pFileAll!=NULL){
		
		/*写操作日志*/
		if(XInitUpdataLog(sStartTime,&TempLog)<0){
			WriteAlertMsg("初始化操作日志失败");
			return -1;
		}
		strcpy(TempLog.sAppID,UPDCTL.sAppID);
		TempLog.iTacheID=	UPDCTL.iTacheID;

		if(SDInsertStructToUpdataLog(&TempLog,"UPDATA_LOG")<0){
			WriteAlertMsg("写UPDATA_LOG日志失败");
			WriteErrStackAlert();
			RollbackWork();
			DisconnectDatabase();
			return -1;
		}		

		/*输出结果,写文件或其它操作*/
		if((iCnt=XWriteTargetFile())<0){
			WriteAlertMsg("写输出文件%s失败",UPDCTL.sTargetName);
			WriteErrStackAlert();
			RollbackWork();
			DisconnectDatabase();
			return -1;
		}
		WriteProcMsg("生成文件%s成功",UPDCTL.sTargetName);
	}

	/*
	备份文件，从文件列表开头开始处理，直到已经处理的最后一个文件，
	即：因为达到最大处理数据量而break或文件列表结束
	*/
	if(BackupFileList(ptLkHead,ptHead,
		UPDCTL.sSourcePath,UPDCTL.sBackPath)<0) return -1;

	if(XComplateDealFile!=NULL){
		if(XComplateDealFile()<0){
			WriteAlertMsg("结束处理%s类型文件失败",UPDCTL.sFileType);
			return -1;
		}
	}
	if(iCnt>0)	printf("%s %d\n",UPDCTL.sTargetName,iCnt);
	else		printf("%s %d\n","NULL",iCnt);

	/*日志解锁*/
	UnlockLog(sLockName);

    	DisconnectDatabase();

	return 0;
}
int ProcessFile(char sFileName[])
{
	static int iCnt=0;
	char sDateTime[15],sDupName[128],sKey[489],sTargetName[128];
	struct FileControlStruct *ptHead=NULL,*pTemp=NULL,*pDupTicket=NULL;

	struct KeyStruct *p;/*重单过滤*/

	/*加载文件到内存链表*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		WriteAlertMsg("加载文件%s到内存失败",sFileName);
		WriteErrStackAlert();
		return -1;
	}

	GetHostTime(sDateTime);

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*此处理为方便起见改为系统时间，一般应使用话单开始时间，
		因为rate过滤24小时话单是以话单开始时间算的。使用系统时间
		会增加键值文件大小，不过1X上下传数据量不大，影响不大*/
		/*cdma1x的前13位为ID号和类别可能不一样，后面的如果全部一样则为重单*/
		if(UPDCTL.iChkDupFlag){
			
			if(IsCdma1x(UPDCTL.sFileType)){
				strncpy(sKey,(char*)(pTemp->pData)+12,439);
				sKey[439]=0;
			}
			else{
				WriteAlertMsg("请设置重单过滤条件");
				return -1;
			}
			p=MakeDupKey(sDateTime,"%s",sKey);
			if(IsDupTicket(pRoot,p)==FOUND){
				InsertList((LIST **)&pDupTicket,(LIST *)pTemp);
				continue;
			}
			AddKeyToFile(p,&pRoot);
		}

		/*统计文件，由各种不同的文件处理函数进行操行，写FileHead记录。*/
		if(XSumRecInfo((char*)pTemp->pData)<0){
			WriteAlertMsg("文件%s的统计失败,系统忽略",sFileName);
			return 1;
		}

		/*保存结果数据，以供输出*/
		InsertList((LIST **)&UPDCTL.pFileAll,(LIST *)pTemp);

		++iCnt;
	}

	/*输出重单*/
	if(pDupTicket !=NULL){
		sprintf(sDupName,"%s.dup",sFileName);
		if(list2fileln((struct FileControlStruct **)&pDupTicket,
			 sDupName)<0){
			 WriteAlertMsg("输出重单文件%s错误",sDupName);
			return -1;
		}
	}

	/*写处理操作日志*/
	if(iCnt>0)strcpy(sTargetName,UPDCTL.sTargetName);
	else	strcpy(sTargetName,"NULL");
	
	if(InsertUpdataProcLog(sFileName,sTargetName)<0) return -1;

	/*充许处理的最大值*/
	if(IsHbCardIntf(UPDCTL.sFileType)==1){
		if(MAX_PROC_CNT_B!=-1&&iCnt>=MAX_PROC_CNT_B) return 9;
		
	}
	else if(IsBillTicket(UPDCTL.sFileType)==1){
		if(MAX_PROC_CNT_A!=-1&&iCnt>=MAX_PROC_CNT_A) return 9;
	}
	else{
		if(MAX_PROC_CNT!=-1&&iCnt>=MAX_PROC_CNT) return 9;
	}

	return 0;
}
int SeqReverse(int aiSeq[4],int iTotalType)
{
#define SEQ_REVERSE_MAX	500

	int i,j,iFloorFlag=false,iCeilFlag=false;

	for(i=0;i<iTotalType;i++){
		j=aiSeq[i];

		if(j>=(9999-SEQ_REVERSE_MAX))iCeilFlag=true;
		if(j<SEQ_REVERSE_MAX)	iFloorFlag=true;
	}

	if(iCeilFlag==true&&iFloorFlag==true) return true;
	return false;	
}
int CdmaAnd1XComplateDealFile()
{
	int i,j,iTotalType,aiCurSeq[20],iMaxSeq;
	char sCurDate[15],asFileType[20][6];
	struct UpdataLogStruct Temp;

	if(strcmp(UPDCTL.sFileType,"CDT")!=0 &&
		strcmp(UPDCTL.sFileType,"XLO")!=0) return 0;

	if(strcmp(UPDCTL.sFileType,"XLO")==0){
		strcpy(asFileType[0],"XIO");
		strcpy(asFileType[1],"XRO");
		strcpy(asFileType[2],"XRB");
		strcpy(asFileType[3],"XLO");
		iTotalType=4;
	}

	if(strcmp(UPDCTL.sFileType,"CDT")==0){
		strcpy(asFileType[0],"CDC");
		strcpy(asFileType[1],"CDR");
		strcpy(asFileType[2],"CDS");
		strcpy(asFileType[3],"CDT");
		iTotalType=4;
	}
/*将UPDATA_LOG中，四种类型的最大序列号存在aiCurSeq[]数组中*/
	for (i=0;i<iTotalType;i++){
		if(GetLastSeqComm(asFileType[i],&aiCurSeq[i])<0)
			return -1;
	}

/*找到补空文件的终止序列号*/
	iMaxSeq=1;

	if(SeqReverse(aiCurSeq,iTotalType)==true){
		for(i=0;i<iTotalType;i++){
			j=aiCurSeq[i];
			if(j<(9999/2)){
				if(j>iMaxSeq)iMaxSeq=j;
			}
		}
	}
	else{
		for(i=0;i<iTotalType;i++){
			j=aiCurSeq[i];
			if(j>iMaxSeq)iMaxSeq=j;
		}
	}

/*获取补空文件的DATA_DATE*/
	GetHostTime(sCurDate);
	strcpy(sCurDate+8,"000000");

/*对每个TYPE的文件从当前序列号+1,补到最大序列号,并考虑翻转*/
	for (i=0;i<iTotalType;i++){

		j=aiCurSeq[i];
		while(1){
			
			if(j==iMaxSeq) break;
	
			j++;
			if(j>9999) j=1;

			InitUpdataLogBegin(j,asFileType[i],sCurDate,
				UPDCTL.sBelongCode,&Temp);
			InitUpdataLogEnd(&Temp);
			strcpy(Temp.sFileName,"NULL");
			
			if(SDInsertStructToUpdataLog(&Temp,"UPDATA_LOG")<0){
				RollbackWork();
				return -1;
			}
		}
	}

	return 0;
}
int CompDateSeq(char sCurDate[15],int iCurSeq,char sEndDate[15],int iEndSeq)
{
	int res=0;

	if((res=strcmp(sCurDate,sEndDate))!=0) return res;

	return (iCurSeq-iEndSeq);
}
void NextDataSeq(int iMaxSeq,char sCurDate[15],int *piCurSeq)
{
	(*piCurSeq)++;

	if((*piCurSeq)>iMaxSeq){
		AddDates(sCurDate,1);
		*piCurSeq=1;
	}
}
void InitDataSeq(int iMaxSeq,char sEndDate[15],int *piCurSeq)
{
	char sHostDate[15];

	strcpy(sHostDate,UPDCTL.sDealDate);

	strncpy(sEndDate,sHostDate,8);
	strcpy(sEndDate+8,"000000");

	/*取到当前的序列号*/
	*piCurSeq=(tGetTime(sHostDate)-tGetTime(sEndDate))*iMaxSeq/86400;
	if(*piCurSeq==0){
		AddDates(sEndDate,-1);
		*piCurSeq=	iMaxSeq;
	}
}
int GenNullFile(int iMaxSeq)
{
	int iBeginSeq,iEndSeq,iCurSeq;
	char sFileType[6],sBelongCode[6],sCityCode[6],sNextSeq[5];
	char sCurDate[15],sBeginDate[15],sEndDate[15],sTargetPath[128];

	struct UpdataLogStruct Temp;
	
	strcpy(sFileType,	UPDCTL.sFileType);
	strcpy(sBelongCode,	UPDCTL.sBelongCode);
	strcpy(sCityCode,	UPDCTL.sCityCode);
	strcpy(sTargetPath,	UPDCTL.sTargetPath);
	
	if(GetLastDateSeq(sFileType,sBeginDate,&iBeginSeq)<0) return -1;

	iCurSeq	=iBeginSeq;
	strcpy(sCurDate,sBeginDate);
	InitDataSeq(iMaxSeq,sEndDate,&iEndSeq);
	/*当前文件已经生成*/
	/*WriteProcMsg("文件系列号:%s,%s,%d,%s,%d",UPDCTL.sFileType,sBeginDate,iBeginSeq,sEndDate,iEndSeq);*/
	if(CompDateSeq(sBeginDate,iBeginSeq,sEndDate,iEndSeq)==0) return 1;
	
	while(1){

		NextDataSeq(iMaxSeq,sCurDate,&iCurSeq);

		/*注意，补空文件时必须使用sCurDate为sDataDate,此处必须设置....*/
		strcpy(UPDCTL.sDataDate,sCurDate);

		sprintf(sNextSeq,"%04d",iCurSeq);

		if(CompDateSeq(sCurDate,iCurSeq,sEndDate,iEndSeq)>=0)break;

		/*这里需要填充空文件*/
		InitUpdataLogBegin(iCurSeq,sFileType,sCurDate,sBelongCode,&Temp);
		InitUpdataLogEnd(&Temp);

		/*初始化文件头*/
		XAssignFileName(sNextSeq,Temp.sFileName);
		XInitFileHeadTail(atoi(sNextSeq),&Temp); 

		/*部份实现根据UPLog来实现文件头的生成所以在这里进行操作。
			使用各部分定义的实现。*/
		memcpy(&(UPDCTL.CurLog),&Temp,sizeof(struct UpdataLogStruct));

		if(XWriteTargetFile()<0)return -1;

		if(SDInsertStructToUpdataLog(&Temp,"UPDATA_LOG")<0) return -1;

		CommitWork();
	}

	return 0;
}

void GetPosStr(char sStr[],int iStrLen,int iBgnPos,int iLen,char sResult[])
{
	strcpy(sResult,"");

	if(iBgnPos<iStrLen&&iLen>0&&(iBgnPos+iLen)<=iStrLen){
		strncpy(sResult,sStr+iBgnPos,iLen);
		sResult[iLen]=0;
	}
}
int IsCdmaRI(char sFileType[])
{
	if(strcmp(sFileType,"CBI")==0||
		strcmp(sFileType,"QRI")==0||
		strcmp(sFileType,"MVI")==0||
		strcmp(sFileType,"TVI")==0||
		strcmp(sFileType,"J04")==0||
		strcmp(sFileType,"J08")==0||
		strcmp(sFileType,"J10")==0||
		strcmp(sFileType,"JRI")==0) return true;
	return false;
}
int IsCdmaII(char sFileType[])
{
	if(strcmp(sFileType,"QII")==0||
		strcmp(sFileType,"JII")==0) return true;
	return false;
}
int IsGsmRI(char sFileType[])
{
	if(strcmp(sFileType,"CRI")==0||
		strcmp(sFileType,"TRI")==0||
		strcmp(sFileType,"C04")==0||
		strcmp(sFileType,"C08")==0||
		strcmp(sFileType,"C10")==0||
		strcmp(sFileType,"GBI")==0) return true;
	return false;
}
int IsGsmII(char sFileType[])
{
	if(strcmp(sFileType,"CII")==0||
		strcmp(sFileType,"TII")==0) return true;
	return false;
}
int IsGCUpdata(char sFileType[])
{
	if(IsCdmaRI(sFileType)==true) return true;
	if(IsCdmaII(sFileType)==true) return true;
	if(IsGsmRI(sFileType)==true) return true;
	if(IsGsmII(sFileType)==true) return true;

	return false;
}
int IsRhjf(char sFileType[])
{
	if(strcmp(sFileType,"RHO")==0||
		strcmp(sFileType,"RHT")==0||
		strcmp(sFileType,"IPO")==0||
		strcmp(sFileType,"IPT")==0) return true;
	return false;
}
int IsNxRhjf(char sFileType[])
{
	if(strcmp(sFileType,"R04")==0||		/*193详单*/
		strcmp(sFileType,"R06")==0||
		strcmp(sFileType,"R07")==0||	/*17911详单*/
		strcmp(sFileType,"R11")==0)return true;
	return false;
}
int IsCdma1xUp(char sFileType[])
{
	if(strcmp(sFileType,"XRI")==0||
		strcmp(sFileType,"XNG")==0) return true;
	return false;
}
int IsCdma1x(char sFileType[])
{
	/*具体含义参见，updata_impl.c开头部分关于cdma1x的说明*/
	if(strcmp(sFileType,"XRI")==0||
		strcmp(sFileType,"XNG")==0||
		strcmp(sFileType,"XRO")==0||
		strcmp(sFileType,"XIO")==0||
		strcmp(sFileType,"XRB")==0||
		strcmp(sFileType,"XLO")==0) return true;
	return false;
}
int IsGsmBill(char sFileType[])
{
	if(strcmp(sFileType,"GSC")==0||
		strcmp(sFileType,"GSR")==0||
		strcmp(sFileType,"GSS")==0||
		strcmp(sFileType,"GSD")==0||
		strcmp(sFileType,"GSI")==0||
		strcmp(sFileType,"GSN")==0||		
		strcmp(sFileType,"GST")==0) return true;

	return false;
}
int IsCdmaBill(char sFileType[])
{
	if(strcmp(sFileType,"CDC")==0||
		strcmp(sFileType,"CDR")==0||
		strcmp(sFileType,"CDS")==0||
		strcmp(sFileType,"CDT")==0||
		strcmp(sFileType,"CDD")==0||
		strcmp(sFileType,"CDI")==0||
		strcmp(sFileType,"CDN")==0) return true;
	return false;
}
int IsSmsBill(char sFileType[])
{
	if(strcmp(sFileType,"SMG")==0||
		strcmp(sFileType,"SMC")==0||
		strcmp(sFileType,"SPC")==0||
		strcmp(sFileType,"SPG")==0) return true;
	return false;
}
int IsHbSmgDIntf(char sFileType[])
{
	if(strcmp(sFileType,"SIF")==0) return true;
	return false;
}
int IsHbCardIntf(char sFileType[])
{

	if(IsHbCardSn(UPDCTL.sFileType)==true) return true; 
	if(IsHbCardGj(UPDCTL.sFileType)==true) return true;  
	if(IsHbCard52(UPDCTL.sFileType)==true) return true;  

	return false;
}
int IsHbCardSn(char sFileType[])
{
	if(strcmp(sFileType,"ZIC")==0||
		strcmp(sFileType,"ZIN")==0||
		strcmp(sFileType,"ZQQ")==0) return true;
	return false;
}
int IsHbCardGj(char sFileType[])
{
	char sBillHome[128];
	
	GetBillHome(sBillHome);
	sprintf(UPDCTL.sAppFile,"%sbin/hbacctfile",sBillHome);

	if(IsFile(UPDCTL.sAppFile)==FALSE){
		WriteAlertMsg("应用程序%s不存在",UPDCTL.sAppFile);
		return false;
	}	
	
	
	if(strcmp(sFileType,"S80")==0||
		strcmp(sFileType,"S40")==0||
		strcmp(sFileType,"S60")==0||
		strcmp(sFileType,"S10")==0||
		strcmp(sFileType,"S11")==0||
		strcmp(sFileType,"S93")==0||
		strcmp(sFileType,"S76")==0) return true;
	return false;
}
int IsHbCard52(char sFileType[])
{
	if(strcmp(sFileType,"S52")==0) return true;
	return false;
}

int IsHbInfoIntf(char sFileType[])
{
	char sBillHome[128];
	
	GetBillHome(sBillHome);
	sprintf(UPDCTL.sAppFile,"%sbin/hbacctfile",sBillHome);

	if(IsFile(UPDCTL.sAppFile)==FALSE){
		WriteAlertMsg("应用程序%s不存在",UPDCTL.sAppFile);
		return false;
	}	

	if(IsHbInfoSn(UPDCTL.sFileType)==true) return true; 
	if(IsHbInfoZb(UPDCTL.sFileType)==true) return true;  

	return false;
}
int IsHbInfoSn(char sFileType[])
{
	if(strcmp(sFileType,"I69")==0) return true;
	return false;
}
int IsHbInfoZb(char sFileType[])
{
	if(strcmp(sFileType,"I16")==0) return true;
	return false;
}

int IsBillTicket(char sFileType[])
{
	if(strcmp(sFileType,"STT")==0||
		strcmp(sFileType,"NSM")==0) return true;
	return false;
}
int IsSttIntf(char sFileType[])
{
	if(strcmp(sFileType,"STT")==0) return true;
	return false;
}
int IsNsmsIntf(char sFileType[])
{
	if(strcmp(sFileType,"NSM")==0) return true;
	return false;
}

int CheckType(char sType[])
{
	if(IsRhjf(sType)==1) return 0;
	if(IsCdma1x(sType)==1) return 0;
	if(IsCdmaBill(sType)==1) return 0;
	if(IsGsmBill(sType)==1) return 0;
	if(IsSmsBill(sType)==1) return 0;
	if(IsGCUpdata(sType)==1) return 0;
	if(IsNxRhjf(sType)==1) return 0;
	if(IsHbSmgDIntf(sType)==1) return 0;
	if(IsHbCardIntf(sType)==1) return 0;
	if(IsHbInfoIntf(sType)==1) return 0;
	if(IsBillTicket(sType)==1) return 0;
	if(IsNewGsmup(sType)==1) return 0;
	if(IsGprsjf(sType)==1) return 0;
	if(IsNewCdmaBill(sType)==1) return 0;
	if(IsNewCdma1xBill(sType)==1) return 0;
	if(IsNewSmsBill(sType)==1) return 0;
	if(IsNewSmspBill(sType)==1) return 0;
	WriteAlertMsg("类别仅限：\n\tXRI(省际漫入),XRO(省际漫出),XIO(国际漫出),XLO(本地)--CDMA1X\n\t\
			CD1(本地),CD2(省内),CD3(国内),CD4(国际)--C网计费\n\t\
			CRI,CII,JRI,JII,TRI,TII,QRI,QII--G,C总部上下传\n\t\
			RHO(193O)-RHT(193T)-IPO(17911O)-IPT(17911T)--融合计费,193,17911,油田通\n\t\
			GSC(本地),GSR(省内),GSS(国内),GST(国际)--G网计费\n\t\
			C04(长庆通G-->陕西),C08(长庆通G-->宁夏)\n\t\
			J04(长庆通C-->陕西),J08(长庆通C-->宁夏)\n\t\
			C10(青海通G-->青海),J10(青海通C-->青海)\n\t\
			MVI(4330正式文件),TVI(4330测试文件)\n\t\
			SMG(G网p2p),SMC(C网p2p）,SPG(G网在信),SPC(C网在信)--短信计费\n\t\
			R04,R06,R07,R11 宁夏融合计费\n\t\
			SIF(短信网关帐单接口),ZIC(ic卡),ZQQ(省内亲情),ZIN(省内除亲情)\n\t\
			S80->800,S40->4006,S60->600,S10->116800,S11->11681(国家骨干)\n\t\
			S93->196300,S76->17960IP,S52(央视幸运52互动4006665252)\n\t\
			I16->总部116916,I69->省内116169 河北网通结算\n\t\
			STT(标准批价格式),NSM(N短信格式)");
	return -1;
}
void ParseArg(int argc,char **argv)
{
	
	if(argc!=11){
		printf("Usage %s type sourcepath backpath workpath "
			"targetpath filter delay citycode appid tacheid.\n",
			argv[0]);
		exit(-1);
	}

	bzero((void*)&UPDCTL,sizeof(struct UpdataCtlStruct));

	strncpy(UPDCTL.sFileType,argv[1],5);
	UPDCTL.sFileType[5]=0;
	if(CheckType(UPDCTL.sFileType)<0){
		printf("非法类别 %s .\n",UPDCTL.sFileType);
		exit(-1);
	}
	
	strcpy(UPDCTL.sSourcePath,argv[2]);
	strcpy(UPDCTL.sBackPath,argv[3]);
	strcpy(UPDCTL.sWorkPath,argv[4]);
	strcpy(UPDCTL.sTargetPath,argv[5]);
	RegularDir(UPDCTL.sSourcePath);
	RegularDir(UPDCTL.sBackPath);
	RegularDir(UPDCTL.sWorkPath);
	RegularDir(UPDCTL.sTargetPath);

	strcpy(UPDCTL.sFilter,argv[6]);
	UPDCTL.iDelay=atoi(argv[7]);
	
	/*C网计费，配置中需要指出这个点的城市场代码*/
	strncpy(UPDCTL.sDataCityCode,argv[8],4);
	UPDCTL.sDataCityCode[4]=0;
	AllTrim(UPDCTL.sDataCityCode);

	strcpy(UPDCTL.sAppID,argv[9]);
	UPDCTL.iTacheID= atoi(argv[10]);
	
}
int GetBelongCodeAndCityCode(char sBelongCode[5],char sCityCode[5],
	char sAppHome[128])
{
	int iRet;
	char sTemp[128],sPath[128];

	strcpy(sBelongCode,"");
	strcpy(sCityCode,"");
	strcpy(sAppHome,"");

	GetIniName(sPath);

	iRet=ReadString(sPath,"bss","updata","belong_code",sTemp);
	ERROR_RETURNZ(iRet<0,"读取bill.ini文件失败");
	ERROR_RETURNA((strlen(sTemp)==0),"bill.ini->bss->updata-%s无对应配置",
		"belong_code");
	strncpy(sBelongCode,sTemp,4);sBelongCode[4]=0;AllTrim(sBelongCode);

	iRet=ReadString(sPath,"bss","updata","city_code",sTemp);
	ERROR_RETURNZ(iRet<0,"读取bill.ini文件失败");
	ERROR_RETURNA((strlen(sTemp)==0),"bill.ini->bss->updata-%s无对应配置",
		"city_code");
	strncpy(sCityCode,sTemp,4);sCityCode[4]=0;AllTrim(sCityCode);

	GetAppHome(sAppHome);

	return 0;
}
int FileProc(char sFileName[])
{
	int iRet;
	char	sCondition[128];
	struct UpdataProcLogStruct Temp;

	sprintf(sCondition," WHERE ORI_FILE_NAME='%s'",sFileName);
	iRet=SDGetUpdataProcLogToStruct(&Temp,"UPDATA_PROC_LOG",sCondition);

	return iRet;
}
int FileFilter(int iDelay,char sFileName[])
{

	char sBaseName[128];

	GetBaseName(sFileName,sBaseName);

	/**如果文件处理过则不处理**/
	if(FileProc(sBaseName)==true) return 1;

	/*如果文件时间与系统时间太近则不处理*/
	if((tGetHostTime()-FileModifyTime(sFileName))<iDelay) return -1;

	return 0;
}

int InsertUpdataProcLog(char sOriFileName[],char sCurFileName[])
{
	char sTemp[256];
	struct UpdataProcLogStruct ProcLog;

	GetBaseName(sOriFileName,sTemp);

	strcpy(ProcLog.sOriFileName,sTemp);
	strcpy(ProcLog.sCurFileName,sCurFileName);
	ProcLog.iByte=FileSize(sOriFileName);
	ProcLog.iRecCnt=FileLine(sOriFileName);
	
	FileModifyDate(sOriFileName,ProcLog.sFileDate);
	
	strcpy(ProcLog.sAppID,UPDCTL.sAppID);
	ProcLog.iTacheID=UPDCTL.iTacheID;

	if(SDInsertStructToUpdataProcLog(&ProcLog,"UPDATA_PROC_LOG")<0){
		WriteAlertMsg("Ori:%s,Cur:%s 写入日志表UPDATA_PROC_LOG失败",
			sOriFileName,sCurFileName);
		WriteErrStackAlert();
		return -1;
	}
	return 0;
}
int BackupFileList(struct FileControlStruct *ptHead,
	struct FileControlStruct *pEnd,char sSourcePath[],char sBackPath[])
{
	char	sCommand[256],*pc;
	char	sTemp[128],sFileName[128],sBackName[128],sBaseName[128];
	struct FileControlStruct *pTemp;

	if(ptHead==NULL) return 0;

	while(ptHead!=pEnd){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sTemp,(char*)(pTemp->pData),pTemp->iLen);
		sTemp[pTemp->iLen]=0;

		/*时间不满足条件的文件不要处理*/
		if(strlen(sTemp)==0) continue;

		if((pc=strchr(sTemp,'\n'))!=NULL) *pc=0;
		GetBaseName(sTemp,sBaseName);
		sprintf(sFileName,"%s%s",sSourcePath,sBaseName);
		sprintf(sBackName,"%s%s",sBackPath,sBaseName);

		if(strcmp(sBackPath,sSourcePath)!=0){
			sprintf(sCommand,"mv %s %s",sFileName,sBackName);
			/*备份文件失败不退出继续处理*/
			if(system(sCommand)!=0)
				WriteAlertMsg("备份%s文件失败",sFileName);
		}
	}
	return 0;
}

void cvhead_tail_ticket_cri(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen)
{
	char sDealDate[15],sFileIdentify[4];

	strcpy(sDealDate,UPDCTL.sDataDate);
	sDealDate[8]=0;
	
	strcpy(sFileIdentify,p->sFileType);

	*piHeadLen=sprintf(sHead,"10%s%s%05d03%s%s%s%06d%015d%92s",
		sBelongCode,sFileIdentify,p->iUpdataID,sDealDate,
		p->sBeginTime,p->sEndTime,p->iRecCnt,p->iTotalCharge," ");
	/*长庆通，油田通特殊处理*/
	if(strcmp(p->sFileType,"C04")==0||strcmp(p->sFileType,"C08")==0||
		strcmp(p->sFileType,"C10")==0){
		*piHeadLen=sprintf(sHead,"10%s%s%05d03%s%s%s%06d%015d%92s",
			sBelongCode,"CRI",p->iUpdataID,sDealDate,
		    p->sBeginTime,p->sEndTime,p->iRecCnt,p->iTotalCharge," ");
	}

	strcpy(sTail,"");
	*piTailLen=0;
}
void cvhead_tail_ticket_cii(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen)
{
	char sDealDate[15],sFileIdentify[4];

	strcpy(sDealDate,UPDCTL.sDataDate);
	sDealDate[8]=0;
	strcpy(sFileIdentify,p->sFileType);

	*piHeadLen=sprintf(sHead,"10%s%s%05d02%s%s%s%06d%015d%77s",
		sBelongCode,sBelongCode,p->iUpdataID,sDealDate,
		p->sBeginTime,p->sEndTime,p->iRecCnt,p->iTotalCharge," ");
	strcpy(sTail,"");
	*piTailLen=0;
}

void cvhead_tail_ticket_jri(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen)
{
	char sTempDate[15],sDealDate[9],sFileIdentify[4];

	strcpy(sTempDate,UPDCTL.sDataDate);
	strncpy(sDealDate,sTempDate+2,6);sDealDate[6]=0;
	strcpy(sFileIdentify,p->sFileType);
	*piHeadLen=sprintf(sHead,"01%s%03d%s%s021001",
		sDealDate,p->iUpdataID,sBelongCode,sFileIdentify);
	*piTailLen=sprintf(sTail,"98%s%03d%s%s%05d%012d%05d%012d",
		sDealDate,p->iUpdataID,sBelongCode,sFileIdentify,
		p->iRecCnt,p->iTotalCharge,p->iRecCnt,p->iTotalCharge);

	/*长庆通，油田通特殊处理*/
	if(strcmp(p->sFileType,"J04")==0||strcmp(p->sFileType,"J08")==0){
		*piHeadLen=sprintf(sHead,"01%s%03d%s%s021001",
			sDealDate,p->iUpdataID,sBelongCode,"CQT");
		*piTailLen=sprintf(sTail,"98%s%03d%s%s%05d%012d%05d%012d",
			sDealDate,p->iUpdataID,sBelongCode,"CQT",
			p->iRecCnt,p->iTotalCharge,p->iRecCnt,p->iTotalCharge);
	}
	if(strcmp(p->sFileType,"J10")==0){
		*piHeadLen=sprintf(sHead,"01%s%03d%s%s021001",
			sDealDate,p->iUpdataID,sBelongCode,"JRI");
		*piTailLen=sprintf(sTail,"98%s%03d%s%s%05d%012d%05d%012d",
			sDealDate,p->iUpdataID,sBelongCode,"JRI",
			p->iRecCnt,p->iTotalCharge,p->iRecCnt,p->iTotalCharge);
	}

}
void cvhead_tail_ticket_jii(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen)
{
	char sTempDate[15],sDealDate[9],sFileIdentify[4];

	strcpy(sTempDate,UPDCTL.sDataDate);
	strncpy(sDealDate,sTempDate+2,6);sDealDate[6]=0;

	strcpy(sFileIdentify,p->sFileType);
	*piHeadLen=sprintf(sHead,"01%s%03d%s%s021001",
		sDealDate,p->iUpdataID,sBelongCode,sFileIdentify);

	*piTailLen=sprintf(sTail,"98%s%03d%s%s%04d%012d%04d%012d",
		sDealDate,p->iUpdataID,sBelongCode,sFileIdentify,
		p->iRecCnt,p->iTotalCharge,p->iRecCnt,p->iTotalCharge);
}
void InitUpdataLogBegin(int iSeq,char sFileType[],char sDataDate[],
	char sBelongCode[],struct UpdataLogStruct *p)
{
	char	sTempDate[7];

	strncpy(sTempDate,sDataDate+2,6);sTempDate[6]=0;

	bzero((void*)p,sizeof(struct UpdataLogStruct));

	p->iUpdataID=	iSeq;
	strncpy(p->sFileType,sFileType,5);
	sprintf(p->sFileName,"%s%s%03d.%s",
		p->sFileType,sTempDate,iSeq,sBelongCode);

	if(XAssignFileName!=NULL){

		char sSeq[10];
		
		sprintf(sSeq,"%d",iSeq);
		XAssignFileName(sSeq,p->sFileName);
	}

	strcpy(p->sBeginTime,"20300101000000");
	strcpy(p->sEndTime,"19900101000000");
	strcpy(p->sDataDate,sDataDate);

	GetHostTime(p->sDealBeginDate);
	
	strcpy(p->sAppID,UPDCTL.sAppID);
	p->iTacheID=	UPDCTL.iTacheID;
}
void InitUpdataLogEnd(struct UpdataLogStruct *p)
{
	if(p->iRecCnt==0){
		strcpy(p->sBeginTime,p->sDealBeginDate);
		strcpy(p->sEndTime,p->sDealBeginDate);
	}
	GetHostTime(p->sDealEndDate);
}
void AssignDateTime(char sFirstCallDate[],char sFirstCallTime[],
	char sEndCallDate[],char sEndCallTime[],const char sDateTime[])
{
	char sTmpDateTime[15];
	const char *p;

	strcpy(sTmpDateTime,sFirstCallDate);
	strcat(sTmpDateTime,sFirstCallTime);
	if(strcmp(sDateTime,sTmpDateTime)<0){

		p=sDateTime+8;
		strncpy(sFirstCallDate,sDateTime,8);
		sFirstCallDate[8]=0;
		strcpy(sFirstCallTime,p);
	}

	strcpy(sTmpDateTime,sEndCallDate);
	strcat(sTmpDateTime,sEndCallTime);
	if(strcmp(sDateTime,sTmpDateTime)>0){

		p=sDateTime+8;
		strncpy(sEndCallDate,sDateTime,8);
		sEndCallDate[8]=0;
		strcpy(sEndCallTime,p);
	}
}

int GCCRI_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct CriTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	/*呼转*/
	if(strncmp((char *)sRecord,"41",2)==0)
		return GCTRS_SumRecInfo(sRecord);

	mvitem_fmcriticket((struct FCriTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;
	pLog->iTotalCharge +=atoi(Temp.sRoamFee)+
		atoi(Temp.sTollFee)+atoi(Temp.sOtherFee);

	sprintf(sStartTime,"%s%s",Temp.sStartDate,Temp.sStartTime);

	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}
int GCCII_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct CiiTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	mvitem_fmciiticket((struct FCiiTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;
	pLog->iTotalCharge +=atoi(Temp.sFee);

	sprintf(sStartTime,"%s%s",Temp.sStartDate,Temp.sStartTime);
	sStartTime[14]=0;
	
	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}
int GCJRI_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct JriTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	mvitem_fmjriticket((struct FJriTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;
	pLog->iTotalCharge +=atoi(Temp.sRoamFee) +
		atoi(Temp.sTollFee)+atoi(Temp.sOtherFee);

	sprintf(sStartTime,"20%s%s",
		Temp.sStartDate,Temp.sRoamStartTime);
	
	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}
int GCJII_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct JiiTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	mvitem_fmjiiticket((struct FJiiTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;
	pLog->iTotalCharge +=atoi(Temp.sRoamFee) +
		atoi(Temp.sTollFee)+atoi(Temp.sOtherFee);


	sprintf(sStartTime,"20%s%s",
		Temp.sStartDate,Temp.sRoamStartTime);

	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}

/*呼转*/
int GCTRS_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct TrsTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	mvitem_fmtrsticket((struct FTrsTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;

	sprintf(sStartTime,"%s%s",Temp.sStartDate,Temp.sStartTime);
	sStartTime[14]=0;

	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}
int GCUpdata_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;

	if(iFirstFlag==1){
		int iSeq;
		char sTempSeq[6];

		iFirstFlag=0;

		InitDataSeq(96,UPDCTL.sDataDate,&iSeq);
		UPDCTL.iUpdataID=iSeq;
		sprintf(sTempSeq,"%04d",iSeq);
		GCUpdata_AssignFileName(sTempSeq,UPDCTL.sTargetName);
		InitUpdataLogBegin(iSeq,UPDCTL.sFileType,UPDCTL.sDataDate,
			UPDCTL.sBelongCode,&(UPDCTL.CurLog));
	}

	if(IsGsmRI(UPDCTL.sFileType))	return GCCRI_SumRecInfo(sRecord);
	if(IsGsmII(UPDCTL.sFileType))	return GCCII_SumRecInfo(sRecord);
	if(IsCdmaRI(UPDCTL.sFileType))	return GCJRI_SumRecInfo(sRecord);
	if(IsCdmaII(UPDCTL.sFileType))	return GCJII_SumRecInfo(sRecord);

	return -1;
}

int GCUpdata_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	memcpy(pLog,&(UPDCTL.CurLog),sizeof(struct UpdataLogStruct));

	InitUpdataLogEnd(pLog);

	strcpy(pLog->sDealBeginDate,sStartTime);

	return 0;
}
int GCUpdata_WriteTargetFile()
{
	char sTargetName[256];

	GCUpdata_InitFileHeadTail(UPDCTL.iUpdataID,&(UPDCTL.CurLog));

	if(UPDCTL.iHeadLen>0){
		if(item2list(&UPDCTL.pFileAll,(void *)UPDCTL.sHead,
			UPDCTL.iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				UPDCTL.sFileType);
			return -1;
		}
	}
	if(UPDCTL.iTailLen>0){
		if(item2listtail(&UPDCTL.pFileAll,UPDCTL.sTail,
			UPDCTL.iTailLen)<0){
			WriteAlertMsg("添加%s类型文件的文件尾错误",
				UPDCTL.sFileType);
			return -1;
		}
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2filelrn(&UPDCTL.pFileAll,sTargetName);
}
void GCUpdata_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[7];

	strncpy(sTempDate,UPDCTL.sDataDate+2,6);sTempDate[6]=0;

	sprintf(sTargetName,"%s%s%03d.%s",UPDCTL.sFileType,
		sTempDate,atoi(sNextSeq),UPDCTL.sBelongCode);

	/*长庆通，油田通特殊处理*/
	if(strcmp(UPDCTL.sFileType,"C04")==0||strcmp(UPDCTL.sFileType,"J04")==0)
		sprintf(sTargetName,"CQT%s%03d084.%s",
			sTempDate,atoi(sNextSeq),UPDCTL.sBelongCode);
	else if(strcmp(UPDCTL.sFileType,"C08")==0||strcmp(UPDCTL.sFileType,"J08")==0)
		sprintf(sTargetName,"CQT%s%03d088.%s",
			sTempDate,atoi(sNextSeq),UPDCTL.sBelongCode);
	else if(strcmp(UPDCTL.sFileType,"C10")==0)
		sprintf(sTargetName,"CRIT%s%03d.087",sTempDate,atoi(sNextSeq));
	else if(strcmp(UPDCTL.sFileType,"J10")==0)
		sprintf(sTargetName,"JRIT%s%03d.087",sTempDate,atoi(sNextSeq));

	strcpy(UPDCTL.sTargetName,sTargetName);
}

void GCUpdata_InitFileHeadTail(int iUpdataID,struct UpdataLogStruct *p)
{
	if(IsGsmRI(UPDCTL.sFileType))
		cvhead_tail_ticket_cri(p,UPDCTL.sBelongCode,UPDCTL.sHead,
			UPDCTL.sTail,&(UPDCTL.iHeadLen),&(UPDCTL.iTailLen));
	else if(IsGsmII(UPDCTL.sFileType))
		cvhead_tail_ticket_cii(p,UPDCTL.sBelongCode,UPDCTL.sHead,
			UPDCTL.sTail,&(UPDCTL.iHeadLen),&(UPDCTL.iTailLen));
	else if(IsCdmaRI(UPDCTL.sFileType))
		cvhead_tail_ticket_jri(p,UPDCTL.sBelongCode,UPDCTL.sHead,
			UPDCTL.sTail,&(UPDCTL.iHeadLen),&(UPDCTL.iTailLen));
	else if(IsCdmaII(UPDCTL.sFileType))
		cvhead_tail_ticket_jii(p,UPDCTL.sBelongCode,UPDCTL.sHead,
			UPDCTL.sTail,&(UPDCTL.iHeadLen),&(UPDCTL.iTailLen));
}
int Cdma1x_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char sBCharge[9],sFCharge[9],sOCharge[9],sBeginTime[15];
	struct Cdma1xheadStruct *pFileHead=NULL;
	struct CDMA1X_RECD *pCdmaRec=NULL;

	pFileHead=(struct Cdma1xheadStruct *)UPDCTL.sHead;

	pCdmaRec=(struct CDMA1X_RECD *)sRecord;

	/*文件第一条记录时执行*/
	if(iFirstFlag==1){
		char sNextSeq[5];
		int iEndSeq;

		iFirstFlag=0;

		/*TODO:修改序列号获取方式
			只有漫入的需要限制每天个数及时间以及补空文件。
		*/
		if(IsCdma1xUp(UPDCTL.sFileType)==1){
			InitDataSeq(96,UPDCTL.sDataDate,&iEndSeq);
		}
		else{
			if(GetLastSeqComm(UPDCTL.sFileType,&iEndSeq)<0){
				WriteAlertMsg("取序列号错误");
				exit(-1);
			}
			++iEndSeq;
			if(iEndSeq>9999){
				iEndSeq=1;
			}
			GetHostTime(UPDCTL.sDataDate);
			strcpy(UPDCTL.sDataDate+8,"000000");
		}

		UPDCTL.iUpdataID=iEndSeq;
		sprintf(sNextSeq,"%04d",iEndSeq);
		XInitFileHeadTail(atoi(sNextSeq),NULL);
		XAssignFileName(sNextSeq,UPDCTL.sTargetName);
	}

	strncpy(sBCharge,pCdmaRec->BaseCharge,8);
	sBCharge[8]=0;
	strncpy(sFCharge,pCdmaRec->FluxCharge,8);
	sFCharge[8]=0;
	strncpy(sOCharge,pCdmaRec->OtherCharge,8);
	sOCharge[8]=0;

	sprintf(pFileHead->sAllRecords,"%010d",1+atoi(pFileHead->sAllRecords));

	sprintf(pFileHead->sAllDurations,"%010d",
		atoi(pFileHead->sAllDurations) +
		atoi(sBCharge)+atoi(sFCharge)+atoi(sOCharge));

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	strncpy(sBeginTime,pCdmaRec->StartTime,14);sBeginTime[14]=0;
	
	if(tGetTime(sBeginTime)<0) return -1;

	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,sBeginTime);

	return 0;
}
int Cdma1x_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{
	char sBeginDate[15],sEndDate[15];
	struct Cdma1xheadStruct *pFileHead=(struct Cdma1xheadStruct *)UPDCTL.sHead;

	/*以下五行为区别*/
	sprintf(sBeginDate,"%s%s",
		pFileHead->sFirstCallDate,pFileHead->sFirstCallTime);
	sprintf(sEndDate,"%s%s",
		pFileHead->sEndCallDate,pFileHead->sEndCallTime);

	pLog->iRecCnt=		atoi(pFileHead->sAllRecords);
	pLog->iTotalCharge=	atoi(pFileHead->sAllDurations);
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);
	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}

int Cdma1x_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256];
	struct FCdma1xheadStruct FileHead;

	bzero((void*)&FileHead,sizeof(struct FCdma1xheadStruct));
	mvitem_mfcdma1xhead((struct Cdma1xheadStruct*)UPDCTL.sHead,&FileHead);

	if(IsCdma1xUp(UPDCTL.sFileType)!=true){
		if(strcmp(UPDCTL.sBelongCode,"038")==0)	iHeadLen=460;
		else					iHeadLen=488;
	}
	else  iHeadLen=488;

	if(item2list(&UPDCTL.pFileAll,(void *)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型文件的文件头错误",UPDCTL.sFileType);
		return -1;
	}
	
	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2fileln(&UPDCTL.pFileAll,sTargetName);
}
void Cdma1x_InitFileHead(int iUpdataID,struct UpdataLogStruct *p)
{
	char sDateTime[15];
	struct Cdma1xheadStruct *po=(struct Cdma1xheadStruct *)UPDCTL.sHead;

	/*初始化文件头*/
	UPDCTL.iHeadLen=sizeof(struct Cdma1xheadStruct);
	bzero((void*)po,UPDCTL.iHeadLen);

	strcpy(po->sRecordType,"01");
	sprintf(po->sFileSeq,"%04d",iUpdataID);
	strcpy(po->sFileVer,"00");
	strcpy(po->sAaaSyscode,"   ");
	strcpy(po->sCityCode,UPDCTL.sBelongCode);

	GetHostTime(sDateTime);
	strncpy(po->sCreatedDate,sDateTime,8);
	po->sCreatedDate[8]=0;

	strcpy(po->sFirstCallDate,"20300101");
	strcpy(po->sFirstCallTime,"000000");
	strcpy(po->sEndCallDate,"19900101");
	strcpy(po->sEndCallTime,"000000");
	sprintf(po->sAllRecords,"%010d",0);
	sprintf(po->sAllDurations,"%010d",0);
	LeftPad(po->sNoused,418,' ');
}


void C1X_CNG_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char sHostDate[15],sTempTime[5],sTempDate[7];

	GetHostTime(sHostDate);
	strncpy(sTempTime,sHostDate+8,4);	sTempTime[4]=0;
	strncpy(sTempDate,UPDCTL.sDataDate+2,6);sTempDate[6]=0;
	if(atoi(sNextSeq)==96) strcpy(sTempTime,"2359");

	sprintf(sTargetName,"TCDMA1XR%s%s%s%s.AVL",
		UPDCTL.sBelongCode,sTempDate,sTempTime,sNextSeq);
	strcpy(UPDCTL.sTargetName,sTargetName);
}
void C1X_XRI_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char sHostDate[15],sTempTime[5],sTempDate[7];

	GetHostTime(sHostDate);
	strncpy(sTempTime,sHostDate+8,4);	sTempTime[4]=0;
	strncpy(sTempDate,UPDCTL.sDataDate+2,6);sTempDate[6]=0;
	if(atoi(sNextSeq)==96) strcpy(sTempTime,"2359");

	sprintf(sTargetName,"CDMA1XR%s%s%s%s.AVL",
		UPDCTL.sBelongCode,sTempDate,sTempTime,sNextSeq);
	strcpy(UPDCTL.sTargetName,sTargetName);
}

void GetCdma1xBillFileName(char sRoamType[],char sNextSeq[],
	char sSuffix[],char sFileName[])
{

	char sHostDate[15];

	GetHostTime(sHostDate);	sHostDate[12]=0;

	sprintf(sFileName,"%s%s%s.%s",sRoamType,sHostDate,sNextSeq,sSuffix);
}

void C1X_XRO_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char sFileName[128];

	GetCdma1xBillFileName("2000",sNextSeq,"req",sFileName);

	strcpy(UPDCTL.sTargetName,sFileName);
	strcpy(sTargetName,sFileName);
}

void C1X_XIO_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char sFileName[128];
/*GS的XIO文件和福建的XIO文件扩展名不同*/
	if(strcmp(UPDCTL.sBelongCode,"087")==0)
		GetCdma1xBillFileName("4000",sNextSeq,"AVL",sFileName);
	else	GetCdma1xBillFileName("4000",sNextSeq,"req",sFileName);

	strcpy(UPDCTL.sTargetName,sFileName);
	strcpy(sTargetName,sFileName);
}

void C1X_XLO_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char sFileName[128];

	GetCdma1xBillFileName("0000",sNextSeq,"req",sFileName);

	strcpy(UPDCTL.sTargetName,sFileName);
	strcpy(sTargetName,sFileName);
}

void C1X_XRB_AssignFileName(char sNextSeq[],char sTargetName[])
{
        char sFileName[128],sHostDate[15];

        GetHostTime(sHostDate);sHostDate[12]=0;

        sprintf(sFileName,"1000%s%s.in",sHostDate,sNextSeq);

        strcpy(UPDCTL.sTargetName,sFileName);
        strcpy(sTargetName,sFileName);
}
void Cdma1x_AssignFileName(char sNextSeq[],char sTargetName[])
{
        if(strcmp(UPDCTL.sFileType,"XNG")==0)		/*双模上下传*/
		C1X_CNG_AssignFileName(sNextSeq,sTargetName);
	else if(strcmp(UPDCTL.sFileType,"XLO")==0) 	/*非漫游，本地*/
		C1X_XLO_AssignFileName(sNextSeq,sTargetName);
	else if(strcmp(UPDCTL.sFileType,"XRO")==0) 	/*国内漫出*/
		C1X_XRO_AssignFileName(sNextSeq,sTargetName);
	else if(strcmp(UPDCTL.sFileType,"XIO")==0) 	/*国际漫出*/
		C1X_XIO_AssignFileName(sNextSeq,sTargetName);
	else if(strcmp(UPDCTL.sFileType,"XRB")==0) 	/*国内漫入计费用*/
		C1X_XRB_AssignFileName(sNextSeq,sTargetName);
	else 	C1X_XRI_AssignFileName(sNextSeq,sTargetName);
}

int Cdma_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;

	char sDay[9];
	int iRoamType;
	struct CdmaheadStruct *pFileHead=NULL;
	struct CdmaTicketStruct Temp;


	pFileHead=(struct CdmaheadStruct *)UPDCTL.sHead;

	mvitem_fmcdmaticket((struct FCdmaTicketStruct *)sRecord,&Temp);

	/*0非漫游,1省内漫游,2省际来访，3国际来访,4港澳台来访*/
	if((iRoamType=atoi(Temp.sRoamType))>4) iRoamType=4;

	/*第一次处理这种类型文件的文件头是进行操作，以后记录不需要再进行以下操作*/
	if(iFirstFlag==1){

		int iSeq,iTmpRoamType;
		char sDateTime[15];
		
		iFirstFlag=0;

		/*
		  总部要求的文件类型：本地话单01、省内漫游02，国内漫游03，国际漫游04
		    现在系统中的类型：0非漫游,1省内漫游,2省际来访，3国际来访,4港澳台来访
		    所以进行以下一句转换
		*/
		if(iRoamType<=3) iTmpRoamType=iRoamType+1;
		sprintf(pFileHead->sRecordType,"%02d",iTmpRoamType);

		strcpy(pFileHead->sCityCode,UPDCTL.sDataCityCode);

		strcpy(pFileHead->sFileTag,"CDMA");

		if(GetLastSeqComm(UPDCTL.sFileType,&iSeq)<0){
			printf("调用GetLastSeqComm取序列号错误！,1\n");
			exit(-1);
		}

		++iSeq;
		if(iSeq>9999)iSeq=1;

		UPDCTL.iUpdataID=iSeq;


		GetHostTime(sDateTime);
		strcpy(sDateTime+8,"000000");

		strcpy(UPDCTL.sDataDate,sDateTime);
		sprintf(pFileHead->sFileSeq,"%04d",iSeq);
		strcpy(pFileHead->sFileVer,"00");

		/*获取设置日期、时间,文件名中日期只需要yymmdd*/
		strncpy(sDay,sDateTime+2,6);sDay[6]=0;

		strncpy(pFileHead->sCreatedDate,sDateTime,8);
		pFileHead->sCreatedDate[8]=0;
		
		sprintf(UPDCTL.sTargetName,"CDMAD%s%c%04d%s.AVL",
			pFileHead->sCityCode,
			UPDCTL.sFileType[strlen(UPDCTL.sFileType)-1],iSeq,sDay);

		strcpy(pFileHead->sFirstCallDate,"20300101");
		strcpy(pFileHead->sFirstCallTime,"000000");
		strcpy(pFileHead->sEndCallDate,"19900101");
		strcpy(pFileHead->sEndCallTime,"000000");

	}

	/*以下为文件信息的统计，每条记录都需要统计*/
	pFileHead->iAllRecords++;
	sprintf(pFileHead->sAllDurations,"%015d",
		atoi(pFileHead->sAllDurations)+
		(atoi(Temp.sTollFee)+atoi(Temp.sRoamFee)+
		atoi(Temp.sInfoFee)+atoi(Temp.sOtherFee))*10);

	if(tGetTime(Temp.sStartTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,
		Temp.sStartTime);

 	return 0;
}
int Cdma_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{
	char sEndDate[15],sBeginDate[15];
	struct CdmaheadStruct *pFileHead=(struct CdmaheadStruct *)UPDCTL.sHead;


	sprintf(sBeginDate,"%s%s",
		pFileHead->sFirstCallDate,pFileHead->sFirstCallTime);
	sprintf(sEndDate,"%s%s",
		pFileHead->sEndCallDate,pFileHead->sEndCallTime);

	pLog->iRecCnt=		pFileHead->iAllRecords;
	pLog->iTotalCharge=	atoi(pFileHead->sAllDurations);
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);

	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
int Cdma_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256];
	struct FCdmaheadStruct FileHead;

	bzero((void*)&FileHead,sizeof(struct FCdmaheadStruct));
	mvitem_mfcdmahead((struct CdmaheadStruct*)UPDCTL.sHead,&FileHead);


	iHeadLen=sizeof(struct FCdmaheadStruct);
	/*福建的文件头多一个字节*/
	if(strcmp(UPDCTL.sBelongCode,"038")!=0)	--iHeadLen;

	if(item2list(&UPDCTL.pFileAll,(void *)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型文件的文件头错误",UPDCTL.sFileType);
		return -1;
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2fileln(&UPDCTL.pFileAll,sTargetName);
}

int Gsm_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	struct GsmHeadStruct *pFileHead=NULL;


	pFileHead=(struct GsmHeadStruct *)UPDCTL.sHead;

	/*文件第一条记录时执行*/
	if(iFirstFlag==1){
		char sNextSeq[9];
		int iEndSeq;

		iFirstFlag=0;

		if(GetLastSeqComm(UPDCTL.sFileType,&iEndSeq)<0){
			WriteAlertMsg("取序列号错误");
			exit(-1);
		}
		++iEndSeq;
		if(iEndSeq>9999) iEndSeq=1;

		GetHostTime(UPDCTL.sDataDate);
		strcpy(UPDCTL.sDataDate+8,"000000");

		UPDCTL.iUpdataID=iEndSeq;
		sprintf(sNextSeq,"%08d",iEndSeq);
		Gsm_InitFileHead(atoi(sNextSeq),NULL);
		Gsm_AssignFileName(sNextSeq,UPDCTL.sTargetName);
	}

	pFileHead->iRecordCnt++;

	return 0;
}
int Gsm_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{
	struct GsmHeadStruct *pFileHead=(struct GsmHeadStruct *)UPDCTL.sHead;

	pLog->iRecCnt=pFileHead->iRecordCnt;
	pLog->iTotalCharge=0;
	pLog->iUpdataID=UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);

	strcpy(pLog->sBeginTime,sStartTime);
	strcpy(pLog->sEndTime,sStartTime);

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
int Gsm_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256];
	struct FGsmHeadStruct FileHead;

	memset(&FileHead,0,sizeof(struct FGsmHeadStruct));
	mvitem_mfgsmhead((struct GsmHeadStruct*)UPDCTL.sHead,&FileHead);


	iHeadLen=sizeof(struct FGsmHeadStruct);

	if(item2list(&UPDCTL.pFileAll,(void *)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型文件的文件头错误",UPDCTL.sFileType);
		return -1;
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2fileln(&UPDCTL.pFileAll,sTargetName);
}
void Gsm_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[7];
/*
城市代码	文件来源	文件流水号	文件日期	.	后缀
110B0000010920030306.AVL
*/
	strncpy(sTempDate,UPDCTL.sDataDate+2,6);sTempDate[6]=0;
	sprintf(sTargetName,"%s%c%08d%s.AVL",UPDCTL.sDataCityCode,
		(UPDCTL.sFileType)[2],atoi(sNextSeq),sTempDate);

	strcpy(UPDCTL.sTargetName,sTargetName);
}
void Gsm_InitFileHead(int iUpdataID,struct UpdataLogStruct *p)
{
	char sDateTime[15];
	struct GsmHeadStruct *po=(struct GsmHeadStruct *)UPDCTL.sHead;

	/*初始化文件头*/
	UPDCTL.iHeadLen=sizeof(struct GsmHeadStruct);
	memset(po,0,UPDCTL.iHeadLen);

	strcpy(po->sRecordType,"01");
	strcpy(po->sCityCode,UPDCTL.sDataCityCode);
	strcpy(po->sFileVer,"00");
	po->iFileSeq=iUpdataID;

	GetHostTime(sDateTime);
	strncpy(po->sCreateDate,sDateTime,8); po->sCreateDate[8]=0;

	po->iRecordCnt=0;
}
int Rhjf_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char sBCharge[9],sFCharge[9],sOCharge[9],sBeginTime[15];
	struct RhjfHeadStruct *pFileHead=NULL;
	struct FRhjfBodyStruct *pRhjfRec=NULL;

	pFileHead=(struct RhjfHeadStruct *)UPDCTL.sHead;

	pRhjfRec=(struct FRhjfBodyStruct *)sRecord;

	/*文件第一条记录时执行*/
	if(iFirstFlag==1){
		char sNextSeq[5];
		int iEndSeq;

		iFirstFlag=0;

		if(GetLastSeqComm(UPDCTL.sFileType,&iEndSeq)<0){
			WriteAlertMsg("取序列号错误");
			exit(-1);
		}
		++iEndSeq;
		if(iEndSeq>9999) iEndSeq=1;

		GetHostTime(UPDCTL.sDataDate);
		strcpy(UPDCTL.sDataDate+8,"000000");

		UPDCTL.iUpdataID=iEndSeq;
		sprintf(sNextSeq,"%04d",iEndSeq);
		Rhjf_InitFileHead(atoi(sNextSeq),NULL);
		Rhjf_AssignFileName(sNextSeq,UPDCTL.sTargetName);
	}

	strncpy(sBCharge,pRhjfRec->sBaseFee,8);
	sBCharge[8]=0;
	strncpy(sFCharge,pRhjfRec->sLongFee,8);
	sFCharge[8]=0;
	strncpy(sOCharge,pRhjfRec->sOtherFee,8);
	sOCharge[8]=0;

	sprintf(pFileHead->sCallSumNbr,"%06d",1+atoi(pFileHead->sCallSumNbr));

	sprintf(pFileHead->sCallSumFee,"%015d",atoi(pFileHead->sCallSumFee)+
		atoi(sBCharge)+atoi(sFCharge)+atoi(sOCharge));

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	strncpy(sBeginTime,pRhjfRec->sStartTime,14);
	sBeginTime[14]=0;
	
	if(tGetTime(sBeginTime)<0) return -1;

	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sLastCallDate,pFileHead->sLastCallTime,sBeginTime);

	return 0;
}
int Rhjf_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	char sEndDate[15],sBeginDate[15];
	struct RhjfHeadStruct *pFileHead=(struct RhjfHeadStruct *)UPDCTL.sHead;

	/*以下五行为区别*/
	sprintf(sBeginDate,"%s%s",pFileHead->sFirstCallDate,pFileHead->sFirstCallTime);
	sprintf(sEndDate,"%s%s",pFileHead->sLastCallDate,pFileHead->sLastCallTime);
	pLog->iRecCnt=		atoi(pFileHead->sCallSumNbr);
	pLog->iTotalCharge=	atoi(pFileHead->sCallSumFee);
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);
	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
int Rhjf_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256];
	struct FRhjfHeadStruct FileHead;

	memset(&FileHead,0,sizeof(struct FRhjfHeadStruct));
	mvitem_mfrhjfhead((struct RhjfHeadStruct *)UPDCTL.sHead,&FileHead);


	iHeadLen=sizeof(struct FRhjfHeadStruct);

	if(item2list(&UPDCTL.pFileAll,(void *)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型文件的文件头错误",UPDCTL.sFileType);
		return -1;
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2fileln(&UPDCTL.pFileAll,sTargetName);
}
void Rhjf_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[15];
/*
BILL1932005070117565581410941.AVL
BILL193YYYYMMDDhhmissNNNNZZZZ.AVL	===>193O
CALLED193YYYYMMDDNNNNZZZZ.AVL	===>193T
*/

	GetHostTime(sTempDate);
	if(strcmp(UPDCTL.sFileType,"RHO")==0)
		sprintf(sTargetName,"BILL193%s%04d0%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);
	else if(strcmp(UPDCTL.sFileType,"RHT")==0)
		sprintf(sTargetName,"CALLED193%s%04d0%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);
	else if(strcmp(UPDCTL.sFileType,"IPO")==0)
		sprintf(sTargetName,"BILL17911%s%04d0%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);
	else if(strcmp(UPDCTL.sFileType,"IPT")==0)
		sprintf(sTargetName,"CALLED17911%s%04d0%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);			

	strcpy(UPDCTL.sTargetName,sTargetName);
}
void Rhjf_InitFileHead(int iUpdataID,struct UpdataLogStruct *p)
{
	char sDateTime[15];
	struct RhjfHeadStruct *po=(struct RhjfHeadStruct *)UPDCTL.sHead;

	/*初始化文件头*/
	UPDCTL.iHeadLen=sizeof(struct RhjfHeadStruct);
	memset(po,0,UPDCTL.iHeadLen);

	strcpy(po->sRecordType,"00");
	sprintf(po->sCityCode,"0%s",UPDCTL.sDataCityCode);
	if(strcmp(UPDCTL.sFileType,"RHO")==0||strcmp(UPDCTL.sFileType,"RHT")==0)
		strcpy(po->sFileFlag,"RHJF");
	if(strcmp(UPDCTL.sFileType,"IPO")==0||strcmp(UPDCTL.sFileType,"IPT")==0)
		strcpy(po->sFileFlag,"IPJF");		
	sprintf(po->sFileSeq,"%04d",iUpdataID);
	strcpy(po->sFileVersion,"00");

	GetHostTime(sDateTime);
	strncpy(po->sFileCreatDate,sDateTime,8);
	po->sFileCreatDate[8]=0;

	strcpy(po->sFirstCallDate,"20300101");
	strcpy(po->sFirstCallTime,"000000");
	strcpy(po->sLastCallDate,"19900101");
	strcpy(po->sLastCallTime,"000000");
	sprintf(po->sCallSumNbr,"%06d",0);
	sprintf(po->sCallSumFee,"%015d",0);
	LeftPad(po->sNouse,60,' ');
}
int Sms_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char sRCharge[7],sICharge[7],sStartTime[15];
	struct SmsHeadStruct *pFileHead=NULL;

	pFileHead=(struct SmsHeadStruct *)UPDCTL.sHead;

	/*文件第一条记录时执行*/
	if(iFirstFlag==1){
		char sNextSeq[9];
		int iEndSeq;

		iFirstFlag=0;

		if(GetLastSeqComm(UPDCTL.sFileType,&iEndSeq)<0){
			WriteAlertMsg("取序列号错误");
			exit(-1);
		}
		++iEndSeq;
		if(iEndSeq>9999) iEndSeq=1;

		GetHostTime(UPDCTL.sDataDate);
		strcpy(UPDCTL.sDataDate+8,"000000");

		UPDCTL.iUpdataID=iEndSeq;
		sprintf(sNextSeq,"%04d",iEndSeq);
		XInitFileHeadTail(atoi(sNextSeq),NULL);
		XAssignFileName(sNextSeq,UPDCTL.sTargetName);
	}

	GetPosStr(sRecord,256,66,14,sStartTime);
	if(tGetTime(sStartTime)<0){
		WriteAlertMsg("取记录开始时间%s错误.",sStartTime);
		return -1;
	}
		
	GetPosStr(sRecord,256,80,6,sRCharge);
	GetPosStr(sRecord,256,86,6,sICharge);

	/*费用*/
	sprintf(pFileHead->sRoamFee,"%010d",
		atoi(pFileHead->sRoamFee)+atoi(sRCharge));
	sprintf(pFileHead->sInfoFee,"%010d",
		atoi(pFileHead->sInfoFee)+atoi(sICharge));

	if(tGetTime(sStartTime)<0) return -1;

	/*时间*/
	if(strcmp(pFileHead->sFirstCallDate,sStartTime)>0)
		strcpy(pFileHead->sFirstCallDate,sStartTime);
	if(strcmp(pFileHead->sLastCallDate,sStartTime)<0)
		strcpy(pFileHead->sLastCallDate,sStartTime);

	sprintf(pFileHead->sRecordCnt,"%010d",atoi(pFileHead->sRecordCnt)+1);

	return 0;
}
int Sms_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{
	struct SmsHeadStruct *pFileHead=(struct SmsHeadStruct *)UPDCTL.sHead;

	pLog->iRecCnt=atoi(pFileHead->sRecordCnt);
	pLog->iTotalCharge	=atoi(pFileHead->sRoamFee)+atoi(pFileHead->sInfoFee);
	pLog->iUpdataID=UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);
	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,pFileHead->sFirstCallDate);
		strcpy(pLog->sEndTime,pFileHead->sLastCallDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
int Sms_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256];
	struct FSmsHeadStruct FileHead;

	memset(&FileHead,0,sizeof(struct FSmsHeadStruct));
	mvitem_mfsmshead((struct SmsHeadStruct*)UPDCTL.sHead,&FileHead);


	iHeadLen=sizeof(struct FSmsHeadStruct);

	if(item2list(&UPDCTL.pFileAll,(void *)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型文件的文件头错误",UPDCTL.sFileType);
		return -1;
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2filelrn(&UPDCTL.pFileAll,sTargetName);
}


void Sms_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[9];
/*
联通在信:
SMGXD[G/C]YYYYMMDD[seq%04d].ProvCode
SMGXDC200506010229.087  CDMA
SMGXDG200506010287.087  GSM

点对点短信：
XD[G/C]YYYYMMDD[seq%04d].ProvCode
XDG200507220404.087 GSM
XDC200507220518.087 CDMA
*/
	strncpy(sTempDate,UPDCTL.sDataDate,8);sTempDate[8]=0;

	/*UPDCTL.sFileType in enum(SPG,SPC) so sFileType[3] in enum(G,C)*/
	if(strncmp(UPDCTL.sFileType,"SP",2)==0){
		sprintf(sTargetName,"SMGXD%c%s%04d.087",UPDCTL.sFileType[2],
			sTempDate,atoi(sNextSeq));
	}
	else if(strncmp(UPDCTL.sFileType,"SM",2)==0){
		sprintf(sTargetName,"XD%c%s%04d.087",UPDCTL.sFileType[2],
			sTempDate,atoi(sNextSeq));
	}

	strcpy(UPDCTL.sTargetName,sTargetName);
}

void Sms_InitFileHead(int iUpdataID,struct UpdataLogStruct *p)
{
	char sDateTime[15];
	struct SmsHeadStruct *po=(struct SmsHeadStruct *)UPDCTL.sHead;

	/*初始化文件头*/
	UPDCTL.iHeadLen=sizeof(struct SmsHeadStruct);
	memset(po,0,UPDCTL.iHeadLen);

	strcpy(po->sHeadTag,"HD");
	sprintf(po->sFileSeq,"%04d",iUpdataID);
	strcpy(po->sFileVer,"01");

	GetHostTime(sDateTime);
	strncpy(po->sCreateDate,sDateTime,8);
	po->sCreateDate[8]=0;

	strcpy(po->sFirstCallDate,"20300101000000");
	strcpy(po->sLastCallDate,"19900101000000");
	sprintf(po->sRecordCnt,"%010d",0);
	sprintf(po->sRoamFee,"%010d",0);
	sprintf(po->sInfoFee,"%010d",0);
	LeftPad(po->sReserve,56,' ');
}

int NxRhjf_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char sTemp[13],sBeginTime[15];
	struct NxRhjfHeadStruct *pFileHead=NULL;
	struct FNxRhjfTicketStruct *pNxRhjfRec=NULL;

	pFileHead=(struct NxRhjfHeadStruct *)UPDCTL.sHead;

	pNxRhjfRec=(struct FNxRhjfTicketStruct *)sRecord;

	/*文件第一条记录时执行*/
	if(iFirstFlag==1){
		char sNextSeq[5];
		int iEndSeq;

		iFirstFlag=0;

		if(GetLastSeqComm(UPDCTL.sFileType,&iEndSeq)<0){
			WriteAlertMsg("取序列号错误");
			exit(-1);
		}
		++iEndSeq;
		if(iEndSeq>9999) iEndSeq=1;

		GetHostTime(UPDCTL.sDataDate);
		strcpy(UPDCTL.sDataDate+8,"000000");

		UPDCTL.iUpdataID=iEndSeq;
		sprintf(sNextSeq,"%04d",iEndSeq);
		NxRhjf_InitFileHead(atoi(sNextSeq),NULL);
		NxRhjf_AssignFileName(sNextSeq,UPDCTL.sTargetName);
	}

	strncpy(sTemp,pNxRhjfRec->sTotalFee,12);sTemp[12]=0;

	pFileHead->iTotalCnt++;
	sprintf(pFileHead->sTotalFee,"%012d",
		atoi(sTemp)+atoi(pFileHead->sTotalFee));

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	strncpy(sBeginTime,pNxRhjfRec->sStartTime,14);
	sBeginTime[14]=0;
	
	if(tGetTime(sBeginTime)<0) return -1;

	if(strcmp(sBeginTime,pFileHead->sBeginTime)<0)
		strcpy(pFileHead->sBeginTime,sBeginTime);
	if(strcmp(sBeginTime,pFileHead->sEndTime)>0)
		strcpy(pFileHead->sEndTime,sBeginTime);

	return 0;
}
int NxRhjf_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	char sEndDate[15],sBeginDate[15];
	struct NxRhjfHeadStruct *pFileHead=(struct NxRhjfHeadStruct *)UPDCTL.sHead;

	/*以下五行为区别*/
	strcpy(sBeginDate,pFileHead->sBeginTime);
	strcpy(sEndDate,pFileHead->sEndTime);

	pLog->iRecCnt=		pFileHead->iTotalCnt;
	pLog->iTotalCharge=	atoi(pFileHead->sTotalFee);
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);
	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
int NxRhjf_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256];
	struct FNxRhjfHeadStruct FileHead;

	memset(&FileHead,0,sizeof(struct FNxRhjfHeadStruct));
	mvitem_mfnxrhjfhead((struct NxRhjfHeadStruct *)UPDCTL.sHead,&FileHead);


	iHeadLen=sizeof(struct FNxRhjfHeadStruct);

	if(item2list(&UPDCTL.pFileAll,(void *)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型文件的文件头错误",UPDCTL.sFileType);
		return -1;
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2filelrn(&UPDCTL.pFileAll,sTargetName);
}
void NxRhjf_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[15];
/*
04200609056187.880.AVL	193文件
06200609056187.880.AVL	
07200609056187.880.AVL	17911文件
11200609056187.880.AVL  
*/
	GetHostTime(sTempDate);sTempDate[8]=0;
	if(strcmp(UPDCTL.sFileType,"R04")==0)
		sprintf(sTargetName,"04%s%04d.%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);
	else if(strcmp(UPDCTL.sFileType,"R06")==0)
		sprintf(sTargetName,"06%s%04d.%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);
	else if(strcmp(UPDCTL.sFileType,"R07")==0)
		sprintf(sTargetName,"07%s%04d.%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);
	else if(strcmp(UPDCTL.sFileType,"R11")==0)
		sprintf(sTargetName,"11%s%04d.%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);
	else
		sprintf(sTargetName,"04%s%04d.%s.AVL",sTempDate,
			atoi(sNextSeq),UPDCTL.sDataCityCode);

	strcpy(UPDCTL.sTargetName,sTargetName);
}
void NxRhjf_InitFileHead(int iUpdataID,struct UpdataLogStruct *p)
{
	char sDateTime[15];
	struct NxRhjfHeadStruct *po=(struct NxRhjfHeadStruct *)UPDCTL.sHead;

	/*初始化文件头*/
	UPDCTL.iHeadLen=sizeof(struct NxRhjfHeadStruct);
	bzero((void*)po,UPDCTL.iHeadLen);

	strcpy(po->sRecordType,"10");	/*固定为10*/
	strcpy(po->sPickID,"");
	strcpy(po->sOriFileName,"");
	po->iSeqNbr=	iUpdataID;
	strcpy(po->sVersion,"2");

	GetHostTime(sDateTime);
	strncpy(po->sCreatedDate,sDateTime,8);po->sCreatedDate[8]=0;

	strcpy(po->sBeginTime,"20300101000000");
	strcpy(po->sEndTime,"19900101000000");

	po->iTotalCnt=0;
	sprintf(po->sTotalFee,"%12d",0);
	LeftPad(po->sReserve,116,' ');
}
/****************************************************************/
/*                                                              */
/*                                                              */
/*		以下是网通部分程序                               */
/*                                                              */
/*                                                              */
/****************************************************************/
/*短信网关下发地市接口文件*/
int HbSmgD_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char    sDateTime[15];

	struct HbjsFileHeadStruct *pFileHead=NULL;
	struct SmgDTicketStruct Temp;

	pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	mvitem_fmsmgdticket((struct FSmgDTicketStruct *)sRecord,&Temp);

	/*第一次处理这种类型文件的取Seq，以后记录不需要再进行以下操作*/
	if(iFirstFlag==1){

		int iSeq;
		iFirstFlag=0;

		if(GetLastSeqComm(UPDCTL.sFileType,&iSeq)<0){
			printf("调用GetLastSeqComm取序列号错误！,2\n");
			exit(-1);
		}

		++iSeq;
		if(iSeq>999)iSeq=1;

		UPDCTL.iUpdataID=iSeq;
		
		strcpy(pFileHead->sFirstCallDate,"20300101");
		strcpy(pFileHead->sFirstCallTime,"000000");
		strcpy(pFileHead->sEndCallDate,"19900101");
		strcpy(pFileHead->sEndCallTime,"000000");
		
		GetHostTime(pFileHead->sCreatedDate);		

		strcpy(UPDCTL.sDataDate,pFileHead->sCreatedDate);
		UPDCTL.sDataDate[14]=0;
		
		sprintf(UPDCTL.sTargetName,"%d,%s",UPDCTL.iUpdataID,UPDCTL.sFileType);
		
	}

	/*以下为文件信息的统计，每条记录都需要统计*/
	pFileHead->iTotalCnt++;
	
	strncpy(sDateTime,Temp.sRecvDateTime,14);
	
	sDateTime[14]=0;
	
	if(tGetTime(sDateTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,sDateTime);

	strcpy(UPDCTL.sDataDate,pFileHead->sEndCallDate);
	strcat(UPDCTL.sDataDate,pFileHead->sEndCallTime);
	UPDCTL.sDataDate[14]=0;

 	return 0;
}
int HbSmgD_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{
	char sEndDate[15],sBeginDate[15],sTempSeq[4];
	struct HbjsFileHeadStruct *pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;

	sprintf(sTempSeq,"%03d",UPDCTL.iUpdataID);sTempSeq[3]=0;
	HbSmgD_AssignFileName(sTempSeq,UPDCTL.sTargetName);
	
	strcpy(pFileHead->sFileName,UPDCTL.sTargetName);

	strcpy(sBeginDate,sStartTime);
	strcpy(sEndDate,sStartTime);
	
	pLog->iRecCnt=		pFileHead->iTotalCnt;
	pLog->iTotalCharge=	0;
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);

	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
void HbSmgD_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[15],sDataDate[15];
/*
hd.20060808.xxx.smg.yyyymmdd 
sjz.20060808.xxx.smg.yyyymmdd
bd.20060808.xxx.smg.yyyymmdd 
zjk.20060808.xxx.smg.yyyymmdd
cd.20060808.xxx.smg.yyyymmdd 
ts.20060808.xxx.smg.yyyymmdd 
lf.20060808.xxx.smg.yyyymmdd 
cz.20060808.xxx.smg.yyyymmdd 
hs.20060808.xxx.smg.yyyymmdd 
xt.20060808.xxx.smg.yyyymmdd 
qhd.20060808.xxx.smg.yyyymmdd

310-->     hd  
311-->     sjz 
312-->     bd  
313-->     zjk 
314-->     cd  
315-->     ts  
316-->     lf  
317-->     cz  
318-->     hs  
319-->     xt  
335-->     qhd


*/
	GetHostTime(sTempDate);sTempDate[8]=0;
	strcpy(sDataDate,UPDCTL.sDataDate);sDataDate[8]=0;
	
	if(strcmp(UPDCTL.sDataCityCode,"310")==0)
		sprintf(sTargetName,"hd.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"311")==0)
		sprintf(sTargetName,"sjz.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"312")==0)
		sprintf(sTargetName,"bd.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"313")==0)
		sprintf(sTargetName,"zjk.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"314")==0)
		sprintf(sTargetName,"cd.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"315")==0)
		sprintf(sTargetName,"ts.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"316")==0)
		sprintf(sTargetName,"lf.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"317")==0)
		sprintf(sTargetName,"cz.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"318")==0)
		sprintf(sTargetName,"hs.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"319")==0)
		sprintf(sTargetName,"xt.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);
	else if(strcmp(UPDCTL.sDataCityCode,"335")==0)
		sprintf(sTargetName,"qhd.%s.%03d.smg.%s",
			sTempDate,atoi(sNextSeq),sDataDate);

	strcpy(UPDCTL.sTargetName,sTargetName);
}

int HbSmgD_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256],sChkTargetName[256];
	struct FHbjsFileHeadStruct FileHead;
	struct FileControlStruct *pRec=NULL; 
	
	bzero((void*)&FileHead,sizeof(struct FHbjsFileHeadStruct));
	mvitem_mfsmgdhead((struct HbjsFileHeadStruct*)UPDCTL.sHead,&FileHead);

	iHeadLen=sizeof(struct FHbjsFileHeadStruct);

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);
	sprintf(sChkTargetName,"%s%s.verf",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	if(item2listtail(&pRec,(void*)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型的校验文件错误",UPDCTL.sFileType);
		return -1;
	}
	if(list2filelrn(&pRec,sChkTargetName)<0){
		WriteAlertMsg("写%s类型校验文件%s错误",UPDCTL.sFileType,sChkTargetName);
		return -1;
	}
	
	return list2filelrn(&UPDCTL.pFileAll,sTargetName);
}


int HbCard_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;

	if(iFirstFlag==1){
		int iSeq;
		char sHostTime[15];

		iFirstFlag=0;

		GetHostTime(sHostTime);
		strcpy(UPDCTL.sDataDate,sHostTime);
		if(GetLastSeqComm(UPDCTL.sFileType,&iSeq)<0){
			printf("调用GetLastSeqComm取序列号错误！,3\n");
			exit(-1);
		}

		++iSeq;
		if(iSeq>999)iSeq=1;

		UPDCTL.iUpdataID=iSeq;
		sprintf(UPDCTL.sTargetName,"%d,%s",UPDCTL.iUpdataID,UPDCTL.sFileType);
	}

	if(IsHbCardSn(UPDCTL.sFileType))	return HbCardSn_SumRecInfo(sRecord);
	if(IsHbCardGj(UPDCTL.sFileType))	return HbCardGj_SumRecInfo(sRecord);
	if(IsHbCard52(UPDCTL.sFileType))	return HbCard52_SumRecInfo(sRecord);

	return -1;
}

int HbCard_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	char sEndDate[15],sBeginDate[15];
	struct HbjsFileHeadStruct *pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	HbCard_AssignFileName("",UPDCTL.sTargetName);
	
	strcpy(pFileHead->sFileName,UPDCTL.sTargetName);

	strcpy(sBeginDate,sStartTime);
	strcpy(sEndDate,sStartTime);
	
	pLog->iRecCnt=		pFileHead->iTotalCnt;
	pLog->iTotalCharge=	0;
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);

	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);


	return 0;
}
int HbCard_WriteTargetFile()
{
	int iHeadLen,iCnt=0;
	char sTargetName[256],sChkTargetName[256];
	struct FHbjsFileHeadStruct FileHead;
	struct FHbZnwGjFileHeadStruct FileGjHead;
	struct FileControlStruct *pRec=NULL; 


	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);
	
	if(IsHbCardGj(UPDCTL.sFileType)){
		
		UPDCTL.iHeadLen=sizeof(struct FHbZnwGjFileHeadStruct);

		bzero((void*)&FileGjHead,sizeof(struct FHbZnwGjFileHeadStruct));
		mvitem_mfznwgjhead(
			(struct HbZnwGjFileHeadStruct*)UPDCTL.sTail,&FileGjHead);

		if(item2list(&UPDCTL.pFileAll,&FileGjHead,UPDCTL.iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				UPDCTL.sFileType);
			return -1;
		}
		if((iCnt=list2fileln(&UPDCTL.pFileAll,sTargetName))<0) return -1;
		
	/*外置程序对文件做帐单汇总处理*/	
		if(execcmd("%s %s GJGG %s",UPDCTL.sAppFile,sTargetName,
			UPDCTL.sTargetPath)!=0){
			WriteAlertMsg("调用 %s %s %s失败",UPDCTL.sAppFile,
			sTargetName,UPDCTL.sTargetPath);
			execcmd("rm -f %s ",sTargetName);
			return -1;
		}
		
		return iCnt-1;
	}
	if(IsHbCardSn(UPDCTL.sFileType)==true||
		IsHbCard52(UPDCTL.sFileType)==true){
		
		UPDCTL.iHeadLen=0;
		bzero((void*)&FileHead,sizeof(struct FHbjsFileHeadStruct));
		mvitem_mfsmgdhead((struct HbjsFileHeadStruct*)UPDCTL.sHead,&FileHead);
	
		iHeadLen=sizeof(struct FHbjsFileHeadStruct);
	
		sprintf(sChkTargetName,"%s%s.verf",UPDCTL.sTargetPath,UPDCTL.sTargetName);
	
		if(item2listtail(&pRec,(void*)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型的校验文件错误",UPDCTL.sFileType);
			return -1;
		}
		if(list2filelrn(&pRec,sChkTargetName)<0){
			WriteAlertMsg("写%s类型校验文件%s错误",UPDCTL.sFileType,sChkTargetName);
			return -1;
		}
		if(IsHbCard52(UPDCTL.sFileType))
			return list2fileln(&UPDCTL.pFileAll,sTargetName);
		else 
			return list2filelrn(&UPDCTL.pFileAll,sTargetName);
	}

	return -1;

	
}
int IsMonthTag(char sTempDate[],char sMonthTag[])
{
	char sMonth[3],sDay[3],sDateTime[15];

	strcpy(sDateTime,sTempDate);
	if(tGetTime(sDateTime)<0) return -1;
	
	strncpy(sMonth,sDateTime+4,2);sMonth[2]=0;
	strncpy(sDay,sDateTime+6,2);sDay[2]=0;

	if(strcmp(sMonth,"01")==0)strcpy(sMonthTag,"Jan");
	else if(strcmp(sMonth,"02")==0)strcpy(sMonthTag,"Feb");
	else if(strcmp(sMonth,"03")==0)strcpy(sMonthTag,"Mar");
	else if(strcmp(sMonth,"04")==0)strcpy(sMonthTag,"Apr");
	else if(strcmp(sMonth,"05")==0)strcpy(sMonthTag,"May");
	else if(strcmp(sMonth,"06")==0)strcpy(sMonthTag,"Jun");
	else if(strcmp(sMonth,"07")==0)strcpy(sMonthTag,"Jul");
	else if(strcmp(sMonth,"08")==0)strcpy(sMonthTag,"Aug");
	else if(strcmp(sMonth,"09")==0)strcpy(sMonthTag,"Sep");
	else if(strcmp(sMonth,"10")==0)strcpy(sMonthTag,"Oct");
	else if(strcmp(sMonth,"11")==0)strcpy(sMonthTag,"Nov");
	else if(strcmp(sMonth,"12")==0)strcpy(sMonthTag,"Dec");

	strcat(sMonthTag,sDay);
	
	return 0;
}
int IsZnwSnLatnTag(char sLatnTag[])
{
	
	strcpy(sLatnTag,"");

	if(strcmp(UPDCTL.sDataCityCode,"310")==0)strcpy(sLatnTag,"21");
	else if(strcmp(UPDCTL.sDataCityCode,"311")==0)strcpy(sLatnTag,"01");
	else if(strcmp(UPDCTL.sDataCityCode,"312")==0)strcpy(sLatnTag,"05");
	else if(strcmp(UPDCTL.sDataCityCode,"313")==0)strcpy(sLatnTag,"07");
	else if(strcmp(UPDCTL.sDataCityCode,"314")==0)strcpy(sLatnTag,"27");
	else if(strcmp(UPDCTL.sDataCityCode,"315")==0)strcpy(sLatnTag,"25");
	else if(strcmp(UPDCTL.sDataCityCode,"316")==0)strcpy(sLatnTag,"13");
	else if(strcmp(UPDCTL.sDataCityCode,"317")==0)strcpy(sLatnTag,"15");
	else if(strcmp(UPDCTL.sDataCityCode,"318")==0)strcpy(sLatnTag,"17");
	else if(strcmp(UPDCTL.sDataCityCode,"319")==0)strcpy(sLatnTag,"19");
	else if(strcmp(UPDCTL.sDataCityCode,"335")==0)strcpy(sLatnTag,"23");

	return 0;
}
void HbCard_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sHostTime[15],sMonthDayTag[6],sLatnTag[3];
	char 	sDataDate[9],sCrateDate[9],sCrateTime[7];

	GetHostTime(sHostTime);
	
	
	IsMonthTag(sHostTime,sMonthDayTag);
	IsZnwSnLatnTag(sLatnTag);

	strncpy(sCrateDate,sHostTime,8);sCrateDate[8]=0;
	strncpy(sCrateTime,sHostTime+8,6);sCrateTime[6]=0;

	
	strncpy(sDataDate,UPDCTL.sDataDate,8);sDataDate[8]=0;
	
	if(strcmp(UPDCTL.sFileType,"ZIC")==0){
		sprintf(sTargetName,"%s_%s_IN_%s.QD.IC",
			sMonthDayTag,sLatnTag,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"ZIN")==0){
		sprintf(sTargetName,"%s_%s_IN_%s.QD",
			sMonthDayTag,sLatnTag,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"ZQQ")==0){
		sprintf(sTargetName,"%s_%s_QQ_%s.QD",
			sMonthDayTag,sLatnTag,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S80")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.800",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S40")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.4006",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S60")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.600",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S10")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.116800",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S11")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.11681",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S93")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.196300",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S76")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.17960",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"S52")==0){
		sDataDate[6]=0;
		sprintf(sTargetName,
			"央视幸运52互动4006665252计费详单.0%s.%s",
			UPDCTL.sDataCityCode,sDataDate);
	}
	strcpy(UPDCTL.sTargetName,sTargetName); 
}


int HbCardSn_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char    sDateTime[15];

	struct HbjsFileHeadStruct *pFileHead=NULL;
	struct ZnwSnIntfStruct Temp;

	pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	mvitem_fmznwsnintf((struct FZnwSnIntfStruct *)sRecord,&Temp);

	/*第一次处理这种类型文件的取Seq，以后记录不需要再进行以下操作*/
	if(iFirstFlag==1){

		iFirstFlag=0;
		
		strcpy(pFileHead->sFirstCallDate,"20300101");
		strcpy(pFileHead->sFirstCallTime,"000000");
		strcpy(pFileHead->sEndCallDate,"19900101");
		strcpy(pFileHead->sEndCallTime,"000000");
		GetHostTime(pFileHead->sCreatedDate);
	}

	/*以下为文件信息的统计，每条记录都需要统计*/
	pFileHead->iTotalCnt++;
	
	strncpy(sDateTime,Temp.sStartTime,14);
	
	sDateTime[14]=0;
	
	if(tGetTime(sDateTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,sDateTime);

	strcpy(UPDCTL.sDataDate,pFileHead->sEndCallDate);
	strcat(UPDCTL.sDataDate,pFileHead->sEndCallTime);
	UPDCTL.sDataDate[14]=0;

	return 0;
}

int HbCardGj_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char    sDateTime[15];

	struct HbjsFileHeadStruct *pFileHead=NULL;
	struct HbZnwGjFileHeadStruct *pTail=NULL;
	struct ZnwGjIntfStruct Temp;

	pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	pTail=(struct HbZnwGjFileHeadStruct *)UPDCTL.sTail;
	
	mvitem_fmznwgjintf((struct FZnwGjIntfStruct *)sRecord,&Temp);

	/*第一次处理这种类型文件的取Seq，以后记录不需要再进行以下操作*/
	if(iFirstFlag==1){

		iFirstFlag=0;
		
		strcpy(pFileHead->sFirstCallDate,"20300101");
		strcpy(pFileHead->sFirstCallTime,"000000");
		strcpy(pFileHead->sEndCallDate,"19900101");
		strcpy(pFileHead->sEndCallTime,"000000");
		GetHostTime(pFileHead->sCreatedDate);
	}

	/*以下为文件信息的统计，每条记录都需要统计*/
	pFileHead->iTotalCnt++;

	sprintf(pTail->sTotalCnt,"%011d",1+atoi(pTail->sTotalCnt));

	sprintf(pTail->sTotalDuration,"%011d",
		atoi(pTail->sTotalDuration)+atoi(Temp.sDuration));

	sprintf(pTail->sTotalFee,"%011d",
		atoi(pTail->sTotalFee)+atoi(Temp.sTotalFee));

	strncpy(sDateTime,Temp.sStartTime,14);
	
	sDateTime[14]=0;
	
	if(tGetTime(sDateTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,sDateTime);

	strcpy(UPDCTL.sDataDate,pFileHead->sEndCallDate);
	strcat(UPDCTL.sDataDate,pFileHead->sEndCallTime);
	UPDCTL.sDataDate[14]=0;

	return 0;
}

int HbCard52_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char    sDateTime[15];

	struct HbjsFileHeadStruct *pFileHead=NULL;
	struct Znw52IntfStruct Temp;

	pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	mvitem_fmznw52intf((struct FZnw52IntfStruct *)sRecord,&Temp);

	/*第一次处理这种类型文件的取Seq，以后记录不需要再进行以下操作*/
	if(iFirstFlag==1){

		iFirstFlag=0;
		
		strcpy(pFileHead->sFirstCallDate,"20300101");
		strcpy(pFileHead->sFirstCallTime,"000000");
		strcpy(pFileHead->sEndCallDate,"19900101");
		strcpy(pFileHead->sEndCallTime,"000000");
		GetHostTime(pFileHead->sCreatedDate);
	}

	/*以下为文件信息的统计，每条记录都需要统计*/
	pFileHead->iTotalCnt++;

	strncpy(sDateTime,Temp.sStartTime,14);	sDateTime[14]=0;
	
	if(tGetTime(sDateTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,sDateTime);

	strcpy(UPDCTL.sDataDate,pFileHead->sEndCallDate);
	strcat(UPDCTL.sDataDate,pFileHead->sEndCallTime);
	UPDCTL.sDataDate[14]=0;

	return 0;
}
/*检查扣除序列号的文件名的一致性*/
int Bill_ChkOriFileName(char sOriFileName[])
{
	static char sTempNoSeqName[40],sNoSeqName[40];

	/*取得一个没有序列号的文件名*/
	strncpy(sTempNoSeqName,sOriFileName,14);sTempNoSeqName[14]=0;
	strcat(sTempNoSeqName,sOriFileName+19);

	if(strcmp(sNoSeqName,"")==0){
		strcpy(sNoSeqName,sTempNoSeqName);
		
		/*将ORI_FILE_NAME保存，给SumRecInfo使用*/
		strcpy(UPDCTL.sTargetName,sOriFileName);
		return 0;
	}
	
	if(strcmp(sTempNoSeqName,sNoSeqName)!=0) return -1;
	
	return 0;
}

int Bill_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;

	if(iFirstFlag==1){
		
		int iSeq;
		char sOriFileName[256],sHostTime[15],sTempDate[15];
		char sSourceIDDate[15],sModule[4],sTail[2];

		iFirstFlag=0;
	/*从结构中取回文件名*/
		strcpy(sOriFileName,UPDCTL.sTargetName);
	
	/*取SEQ*/	
		if(GetLastSeqComm(UPDCTL.sFileType,&iSeq)<0){
			printf("调用GetLastSeqComm取序列号错误！,4\n");
			exit(-1);
		}

		++iSeq;
		if(iSeq>9999)iSeq=1;

		UPDCTL.iUpdataID=iSeq;

	/*取三个关键字段用于命名**/
		strncpy(sSourceIDDate,sOriFileName,14);sSourceIDDate[14]=0;
		strncpy(sModule,sOriFileName+20,3);sModule[3]=0;
		strncpy(sTail,sOriFileName+28,1);sTail[1]=0;

		sprintf(UPDCTL.sTargetName,"%s%05d.%s.UPI.%s",
			sSourceIDDate,iSeq,sModule,sTail);
	/*取DATADATE*/
		GetHostTime(sHostTime);
		strcpy(UPDCTL.sDataDate,sHostTime);
		
		/*从文件名中取时间,默认为系统时间*/
		strncpy(sTempDate,sOriFileName+6,8);
		strcpy(sTempDate+8,"000000");
		if(tGetTime(sTempDate)!=-1)strcpy(UPDCTL.sDataDate,sTempDate);

	}

	if(IsSttIntf(UPDCTL.sFileType))		return Stt_SumRecInfo(sRecord);
	if(IsNsmsIntf(UPDCTL.sFileType))	return Nsms_SumRecInfo(sRecord);

	return -1;
}
int Stt_SumRecInfo(char sRecord[])
{
	/*以下为文件信息的统计，每条记录都需要统计*/
	UPDCTL.iHeadLen++;

	return 0;
}
int Nsms_SumRecInfo(char sRecord[])
{
	/*以下为文件信息的统计，每条记录都需要统计*/
	UPDCTL.iHeadLen++;

	return 0;
}
int Bill_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	char sEndDate[15],sBeginDate[15];
	
	strcpy(sBeginDate,sStartTime);
	strcpy(sEndDate,sStartTime);
	
	pLog->iRecCnt=		UPDCTL.iHeadLen;
	pLog->iTotalCharge=	0;
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);

	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
int Bill_WriteTargetFile()
{
	char sTargetName[256];

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);
	
	UPDCTL.iHeadLen=0;

	return list2fileln(&UPDCTL.pFileAll,sTargetName);

}

int HbInfo_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;

	if(iFirstFlag==1){
		int iSeq;
		char sHostTime[15];

		iFirstFlag=0;

		GetHostTime(sHostTime);
		strcpy(UPDCTL.sDataDate,sHostTime);
		if(GetLastSeqComm(UPDCTL.sFileType,&iSeq)<0){
			printf("调用GetLastSeqComm取序列号错误！,5\n");
			exit(-1);
		}

		++iSeq;
		if(iSeq>999)iSeq=1;

		UPDCTL.iUpdataID=iSeq;
		sprintf(UPDCTL.sTargetName,"%d,%s",
			UPDCTL.iUpdataID,UPDCTL.sFileType);
	}

	if(IsHbInfoSn(UPDCTL.sFileType))return HbInfoSn_SumRecInfo(sRecord);
	if(IsHbInfoZb(UPDCTL.sFileType))return HbInfoZb_SumRecInfo(sRecord);

	return -1;
}

int HbInfo_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	char sEndDate[15],sBeginDate[15];
	struct HbjsFileHeadStruct *pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	HbInfo_AssignFileName("",UPDCTL.sTargetName);
	
	strcpy(pFileHead->sFileName,UPDCTL.sTargetName);

	strcpy(sBeginDate,sStartTime);
	strcpy(sEndDate,sStartTime);
	
	pLog->iRecCnt=		pFileHead->iTotalCnt;
	pLog->iTotalCharge=	0;
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);

	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);


	return 0;
}
int HbInfo_WriteTargetFile()
{
	int iHeadLen,iCnt=0;
	char sTargetName[256],sChkTargetName[256],sType[10];
	struct FHbjsFileHeadStruct FileHead;
	struct FHbZnwGjFileHeadStruct FileGjHead;
	struct FileControlStruct *pRec=NULL; 


	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);
	
	if(IsHbInfoIntf(UPDCTL.sFileType)){
	/*写校验文件*/
		UPDCTL.iHeadLen=0;
		bzero((void*)&FileHead,sizeof(struct FHbjsFileHeadStruct));
		mvitem_mfsmgdhead((struct HbjsFileHeadStruct*)UPDCTL.sHead,&FileHead);
	
		iHeadLen=sizeof(struct FHbjsFileHeadStruct);
	
		sprintf(sChkTargetName,"%s%s.verf",UPDCTL.sTargetPath,UPDCTL.sTargetName);
	
		if(item2listtail(&pRec,(void*)&FileHead,iHeadLen)<0){
			WriteAlertMsg("添加%s类型的校验文件错误",UPDCTL.sFileType);
			return -1;
		}
		if(list2filelrn(&pRec,sChkTargetName)<0){
			WriteAlertMsg("写%s类型校验文件%s错误",UPDCTL.sFileType,sChkTargetName);
			return -1;
		}
		
	/*添加文件头*/	
		UPDCTL.iHeadLen=sizeof(struct FHbZnwGjFileHeadStruct);

		bzero((void*)&FileGjHead,sizeof(struct FHbZnwGjFileHeadStruct));
		mvitem_mfznwgjhead(
			(struct HbZnwGjFileHeadStruct*)UPDCTL.sTail,&FileGjHead);

		if(item2list(&UPDCTL.pFileAll,&FileGjHead,UPDCTL.iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				UPDCTL.sFileType);
			return -1;
		}
		if((iCnt=list2fileln(&UPDCTL.pFileAll,sTargetName))<0)return -1;
		
	/*外置程序对文件做帐单汇总处理*/
		if(IsHbInfoSn(UPDCTL.sFileType)==true)strcpy(sType,"IFSN");
		else if(IsHbInfoZb(UPDCTL.sFileType)==true)
			strcpy(sType,"IFZB");             
		else strcpy(sType,"X"); 
		
		if(execcmd("%s %s %s %s",UPDCTL.sAppFile,sTargetName,sType,
			UPDCTL.sTargetPath)!=0){
			WriteAlertMsg("调用 %s %s %s %s失败",
			UPDCTL.sAppFile,sTargetName,sType,UPDCTL.sTargetPath);
			execcmd("rm -f %s ",sTargetName);
			return -1;
		}
		return iCnt-1;
	}

	return -1;

	
}
void HbInfo_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sHostTime[15];
	char 	sDataDate[9],sCrateDate[9],sCrateTime[7];

	GetHostTime(sHostTime);
	
	strncpy(sCrateDate,sHostTime,8);sCrateDate[8]=0;
	strncpy(sCrateTime,sHostTime+8,6);sCrateTime[6]=0;

	
	strncpy(sDataDate,UPDCTL.sDataDate,6);sDataDate[6]=0;
	
	if(strcmp(UPDCTL.sFileType,"I69")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.P.116169",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else if(strcmp(UPDCTL.sFileType,"I16")==0){
		sprintf(sTargetName,"SDR.0%s.%s.%s.%s.116916",
			UPDCTL.sDataCityCode,sCrateDate,
			sCrateTime,sDataDate);
	}
	else strcpy(sTargetName,"NULL");
	
	strcpy(UPDCTL.sTargetName,sTargetName); 
}

int HbInfoSn_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char    sDateTime[15];

	struct HbjsFileHeadStruct *pFileHead=NULL;
	struct HbZnwGjFileHeadStruct *pTail=NULL;
	struct SpCdrSnIntfStruct Temp;

	pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	pTail=(struct HbZnwGjFileHeadStruct *)UPDCTL.sTail;
	
	mvitem_fmspcdrsnintf((struct FSpCdrSnIntfStruct *)sRecord,&Temp);

	/*第一次处理这种类型文件的取Seq，以后记录不需要再进行以下操作*/
	if(iFirstFlag==1){

		iFirstFlag=0;
		
		strcpy(pFileHead->sFirstCallDate,"20300101");
		strcpy(pFileHead->sFirstCallTime,"000000");
		strcpy(pFileHead->sEndCallDate,"19900101");
		strcpy(pFileHead->sEndCallTime,"000000");
		GetHostTime(pFileHead->sCreatedDate);
	}

	/*以下为文件信息的统计，每条记录都需要统计*/
	pFileHead->iTotalCnt++;

	sprintf(pTail->sTotalCnt,"%011d",1+atoi(pTail->sTotalCnt));

	sprintf(pTail->sTotalDuration,"%011d",
		atoi(pTail->sTotalDuration)+atoi(Temp.sDuration));

	sprintf(pTail->sTotalFee,"%011d",
		atoi(pTail->sTotalFee)+atoi(Temp.sFee));

	strncpy(sDateTime,Temp.sStartTime,14);
	
	sDateTime[14]=0;
	
	if(tGetTime(sDateTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,sDateTime);

	strcpy(UPDCTL.sDataDate,pFileHead->sEndCallDate);
	strcat(UPDCTL.sDataDate,pFileHead->sEndCallTime);
	UPDCTL.sDataDate[14]=0;

	return 0;
}

int HbInfoZb_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char    sDateTime[15];

	struct HbjsFileHeadStruct *pFileHead=NULL;
	struct HbZnwGjFileHeadStruct *pTail=NULL;
	struct SpCdrZbIntfStruct Temp;

	pFileHead=(struct HbjsFileHeadStruct *)UPDCTL.sHead;
	
	pTail=(struct HbZnwGjFileHeadStruct *)UPDCTL.sTail;
	
	mvitem_fmspcdrzbintf((struct FSpCdrZbIntfStruct *)sRecord,&Temp);

	/*第一次处理这种类型文件的取Seq，以后记录不需要再进行以下操作*/
	if(iFirstFlag==1){

		iFirstFlag=0;
		
		strcpy(pFileHead->sFirstCallDate,"20300101");
		strcpy(pFileHead->sFirstCallTime,"000000");
		strcpy(pFileHead->sEndCallDate,"19900101");
		strcpy(pFileHead->sEndCallTime,"000000");
		GetHostTime(pFileHead->sCreatedDate);
	}

	/*以下为文件信息的统计，每条记录都需要统计*/
	pFileHead->iTotalCnt++;

	sprintf(pTail->sTotalCnt,"%011d",1+atoi(pTail->sTotalCnt));

	sprintf(pTail->sTotalDuration,"%011d",
		atoi(pTail->sTotalDuration)+atoi(Temp.sDuration));

	sprintf(pTail->sTotalFee,"%011d",
		atoi(pTail->sTotalFee)+atoi(Temp.sFee));

	strncpy(sDateTime,Temp.sStartTime,14);
	
	sDateTime[14]=0;
	
	if(tGetTime(sDateTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sEndCallDate,pFileHead->sEndCallTime,sDateTime);

	strcpy(UPDCTL.sDataDate,pFileHead->sEndCallDate);
	strcat(UPDCTL.sDataDate,pFileHead->sEndCallTime);
	UPDCTL.sDataDate[14]=0;

	return 0;
}

void newcvhead_tail_ticket_cri(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen)
{
	char sDealDate[15],sFileIdentify[4];

	strcpy(sDealDate,UPDCTL.sDataDate);
	sDealDate[8]=0;
	
	strcpy(sFileIdentify,p->sFileType);
	
	if(strcmp(p->sFileType,"NRI")==0)strcpy(sFileIdentify,"CRI");
	if(strcmp(p->sFileType,"NBI")==0)strcpy(sFileIdentify,"GBI");

	*piHeadLen=sprintf(sHead,"10%s%s%05d03%s%s%s%06d%015d%170s",
		sBelongCode,sFileIdentify,p->iUpdataID,sDealDate,
		p->sBeginTime,p->sEndTime,p->iRecCnt,p->iTotalCharge," ");
	/*长庆通，油田通特殊处理*/
	if(strcmp(p->sFileType,"C04")==0||strcmp(p->sFileType,"C08")==0||
		strcmp(p->sFileType,"C10")==0){
		*piHeadLen=sprintf(sHead,"10%s%s%05d03%s%s%s%06d%015d%170s",
			sBelongCode,"CRI",p->iUpdataID,sDealDate,
		    p->sBeginTime,p->sEndTime,p->iRecCnt,p->iTotalCharge," ");
	}

	strcpy(sTail,"");
	*piTailLen=0;
}
void newcvhead_tail_ticket_cii(struct UpdataLogStruct *p,char sBelongCode[],
	char sHead[],char sTail[],int *piHeadLen,int *piTailLen)
{
	char sDealDate[15],sFileIdentify[4];

	strcpy(sDealDate,UPDCTL.sDataDate);
	sDealDate[8]=0;
	strcpy(sFileIdentify,p->sFileType);
	
	*piHeadLen=sprintf(sHead,"10%s%s%05d02%s%s%s%06d%015d%127s",
		sBelongCode,sBelongCode,p->iUpdataID,sDealDate,
		p->sBeginTime,p->sEndTime,p->iRecCnt,p->iTotalCharge," ");
	strcpy(sTail,"");
	*piTailLen=0;
}

int IsNewGsmRI( char sFileType[] )
{
	if(strcmp(sFileType,"NRI")==0||
		strcmp(sFileType,"TRI")==0||
		strcmp(sFileType,"NBI")==0) return true;
	return false;
}
int IsNewGsmII( char sFileType[] )
{
	if(strcmp(sFileType,"NII")==0||
		strcmp(sFileType,"TII")==0) return true;
	return false;
}
int IsNewGsmup( char sFileType[] )
{
	if(IsNewGsmRI(sFileType)) return true;
	if(IsNewGsmII(sFileType)) return true;
	
	return false;
}

int NewGCRI_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct NewCriTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	/*呼转*/
	if(strncmp((char *)sRecord,"41",2)==0)
		return NewGTRS_SumRecInfo(sRecord);

	Newmvitem_fmcriticket((struct FNewCriTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;
	pLog->iTotalCharge +=atoi(Temp.sRoamFee)+
		atoi(Temp.sTollFee)+atoi(Temp.sOtherFee);

	sprintf(sStartTime,"%s%s",Temp.sStartDate,Temp.sStartTime);

	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}
int NewGCII_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct NewCiiTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	Newmvitem_fmciiticket((struct FNewCiiTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;
	pLog->iTotalCharge +=atoi(Temp.sFee);

	sprintf(sStartTime,"%s%s",Temp.sStartDate,Temp.sStartTime);
	sStartTime[14]=0;
	
	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}

/*呼转*/
int NewGTRS_SumRecInfo(char sRecord[])
{
	char sStartTime[15];
	struct NewTrsTicketStruct Temp;
	struct UpdataLogStruct *pLog=&UPDCTL.CurLog;

	Newmvitem_fmtrsticket((struct FNewTrsTicketStruct *)sRecord,&Temp);

	pLog->iRecCnt++;

	sprintf(sStartTime,"%s%s",Temp.sStartDate,Temp.sStartTime);
	sStartTime[14]=0;

	if(tGetTime(sStartTime)<0) return -1;

	if(strcmp(sStartTime,pLog->sBeginTime)<0)
		strcpy(pLog->sBeginTime,sStartTime);
	if(strcmp(sStartTime,pLog->sEndTime)>0)
		strcpy(pLog->sEndTime,sStartTime);

	return 0;
}

int NewGUpdata_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;

	if(iFirstFlag==1){
		int iSeq;
		char sTempSeq[6];

		iFirstFlag=0;

		InitDataSeq(96,UPDCTL.sDataDate,&iSeq);
		UPDCTL.iUpdataID=iSeq;
		sprintf(sTempSeq,"%04d",iSeq);
		NewGUpdata_AssignFileName(sTempSeq,UPDCTL.sTargetName);
		InitUpdataLogBegin(iSeq,UPDCTL.sFileType,UPDCTL.sDataDate,
			UPDCTL.sBelongCode,&(UPDCTL.CurLog));
	}

	if(IsNewGsmRI(UPDCTL.sFileType))	return NewGCRI_SumRecInfo(sRecord);
	if(IsNewGsmII(UPDCTL.sFileType))	return NewGCII_SumRecInfo(sRecord);

	return -1;
}

int NewGUpdata_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	memcpy(pLog,&(UPDCTL.CurLog),sizeof(struct UpdataLogStruct));

	InitUpdataLogEnd(pLog);

	strcpy(pLog->sDealBeginDate,sStartTime);

	return 0;
}
int NewGUpdata_WriteTargetFile()
{
	char sTargetName[256];

	NewGUpdata_InitFileHeadTail(UPDCTL.iUpdataID,&(UPDCTL.CurLog));

	if(UPDCTL.iHeadLen>0){
		if(item2list(&UPDCTL.pFileAll,(void *)UPDCTL.sHead,
			UPDCTL.iHeadLen)<0){
			WriteAlertMsg("添加%s类型文件的文件头错误",
				UPDCTL.sFileType);
			return -1;
		}
	}
	if(UPDCTL.iTailLen>0){
		if(item2listtail(&UPDCTL.pFileAll,UPDCTL.sTail,
			UPDCTL.iTailLen)<0){
			WriteAlertMsg("添加%s类型文件的文件尾错误",
				UPDCTL.sFileType);
			return -1;
		}
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2filelrn(&UPDCTL.pFileAll,sTargetName);
}
void NewGUpdata_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[7],sTempType[4];

	strncpy(sTempDate,UPDCTL.sDataDate+2,6);sTempDate[6]=0;

	strcpy(sTempType,UPDCTL.sFileType);
	if(strcmp(UPDCTL.sFileType,"NRI")==0)strcpy(sTempType,"CRI");
	if(strcmp(UPDCTL.sFileType,"NII")==0)strcpy(sTempType,"CII");
	if(strcmp(UPDCTL.sFileType,"NBI")==0)strcpy(sTempType,"GBI");

	sprintf(sTargetName,"%s%s%03d.%s",sTempType,
		sTempDate,atoi(sNextSeq),UPDCTL.sBelongCode);		

	strcpy(UPDCTL.sTargetName,sTargetName);
}

void NewGUpdata_InitFileHeadTail(int iUpdataID,struct UpdataLogStruct *p)
{
	if(IsNewGsmRI(UPDCTL.sFileType))
		newcvhead_tail_ticket_cri(p,UPDCTL.sBelongCode,UPDCTL.sHead,
			UPDCTL.sTail,&(UPDCTL.iHeadLen),&(UPDCTL.iTailLen));
	else if(IsNewGsmII(UPDCTL.sFileType))
		newcvhead_tail_ticket_cii(p,UPDCTL.sBelongCode,UPDCTL.sHead,
			UPDCTL.sTail,&(UPDCTL.iHeadLen),&(UPDCTL.iTailLen));

}
int IsGprsjf(char sFileType[])
{
	if(strcmp(sFileType,"GRI")==0||		/*国内来访*/
		strcmp(sFileType,"GII")==0||	/*国际来访*/
		strcmp(sFileType,"GRO")==0||	/*国内出访*/
		strcmp(sFileType,"GIO")==0||	/*国际出访*/
		strcmp(sFileType,"GPO")==0)return true;   /*省内业务*/
	return false;
}
int Gprsjf_SumRecInfo(char sRecord[])
{
	static int iFirstFlag=1;
	char sTemp[11],sBeginTime[15];
	struct GprsHeadStruct *pFileHead=NULL;
	struct FGprsTicketIntfStruct *pGprsRec=NULL;

	pFileHead=(struct GprsHeadStruct *)UPDCTL.sHead;

	pGprsRec=(struct FGprsTicketIntfStruct *)sRecord;

	/*文件第一条记录时执行*/
	if(iFirstFlag==1){
		char sNextSeq[5];
		int iEndSeq;

		iFirstFlag=0;

		if(GetLastSeqComm(UPDCTL.sFileType,&iEndSeq)<0){
			WriteAlertMsg("取序列号错误");
			exit(-1);
		}
		++iEndSeq;
		if(iEndSeq>9999) iEndSeq=1;

		GetHostTime(UPDCTL.sDataDate);
		strcpy(UPDCTL.sDataDate+8,"000000");

		UPDCTL.iUpdataID=iEndSeq;
		sprintf(sNextSeq,"%04d",iEndSeq);
		Gprsjf_InitFileHead(atoi(sNextSeq),NULL);
		Gprsjf_AssignFileName(sNextSeq,UPDCTL.sTargetName);
	}

	sprintf(pFileHead->sTotalCnt,"%010d",atoi(pFileHead->sTotalCnt)+1);
	strncpy(sTemp,pGprsRec->sTotalFee,10);sTemp[10]=0;
	sprintf(pFileHead->sTotalFee,"%015d",
		atoi(sTemp)+atoi(pFileHead->sTotalFee));

	strncpy(sBeginTime,pGprsRec->sStartTime,14);
	sBeginTime[14]=0;
	
	if(tGetTime(sBeginTime)<0) return -1;

	/*设置文件中最大(迟)和最小(早)的的通话开始时间*/
	AssignDateTime(pFileHead->sFirstCallDate,pFileHead->sFirstCallTime,
		pFileHead->sLastCallDate,pFileHead->sLastCallTime,sBeginTime);

	return 0;
}
int Gprsjf_InitUpdataLog(char sStartTime[],struct UpdataLogStruct *pLog)
{

	char sEndDate[15],sBeginDate[15];
	struct GprsHeadStruct *pFileHead=(struct GprsHeadStruct *)UPDCTL.sHead;

	/*以下五行为区别*/
	strncpy(sBeginDate,pFileHead->sFirstCallDate,8);sBeginDate[8]=0;
	strncpy(sBeginDate+8,pFileHead->sFirstCallTime,6);sBeginDate[14]=0;

	strncpy(sEndDate,pFileHead->sLastCallDate,8);sEndDate[8]=0;
	strncpy(sEndDate+8,pFileHead->sLastCallTime,6);sEndDate[14]=0;


	pLog->iRecCnt=		atoi(pFileHead->sTotalCnt);
	pLog->iTotalCharge=	atoi(pFileHead->sTotalFee);
	pLog->iUpdataID=	UPDCTL.iUpdataID;

	strcpy(pLog->sFileType,UPDCTL.sFileType);
	strcpy(pLog->sFileName,UPDCTL.sTargetName);
	if(pLog->iRecCnt>0){
		strcpy(pLog->sBeginTime,sBeginDate);
		strcpy(pLog->sEndTime,sEndDate);
	}
	else{
		strcpy(pLog->sBeginTime,sStartTime);
		strcpy(pLog->sEndTime,sStartTime);
	}

	strcpy(pLog->sDealBeginDate,sStartTime);
	GetHostTime(pLog->sDealEndDate);
	strcpy(pLog->sDataDate ,UPDCTL.sDataDate);

	return 0;
}
int Gprsjf_WriteTargetFile()
{
	int iHeadLen;
	char sTargetName[256];
	struct FGprsHeadStruct FileHead;

	memset(&FileHead,0,sizeof(struct FGprsHeadStruct));
	if(CountList((LIST*)UPDCTL.pFileAll)==0){
		char sHostDate[15];
		struct GprsHeadStruct *pFileHead=(struct GprsHeadStruct *)UPDCTL.sHead;
		
		GetHostTime(sHostDate);
		
		strncpy(pFileHead->sFirstCallDate,sHostDate,8);pFileHead->sFirstCallDate[8]=0;
		strncpy(pFileHead->sFirstCallTime,sHostDate+8,6);pFileHead->sFirstCallTime[6]=0;
		strncpy(pFileHead->sLastCallDate,sHostDate,8);pFileHead->sLastCallDate[8]=0;
		strncpy(pFileHead->sLastCallTime,sHostDate+8,6);pFileHead->sLastCallTime[6]=0;	
	}
	
	mvitem_mfgprshead((struct GprsHeadStruct *)UPDCTL.sHead,&FileHead);


	iHeadLen=sizeof(struct FGprsHeadStruct);

	if(item2list(&UPDCTL.pFileAll,(void *)&FileHead,iHeadLen)<0){
		WriteAlertMsg("添加%s类型文件的文件头错误",UPDCTL.sFileType);
		return -1;
	}

	sprintf(sTargetName,"%s%s",UPDCTL.sTargetPath,UPDCTL.sTargetName);

	return list2filelrn(&UPDCTL.pFileAll,sTargetName);
}
void Gprsjf_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char	sTempDate[15];
/*
ABCDHZZZYYYYMMDDNNNN.XXX
ABCD：业务代码，在本接口取值GPRS
H：业务标识码，"I"表示国际漫游，"R"表示国内漫游,"P"表示省内业务；
ZZZ：省分代码；
YYYYMMDD：表示文件生成时间；
NNNN：表示文件序列号，每日从0001开始记数。四位，不足四位，左取零。
XXX：表示话单类型。 取值为"AVU"为上传文件；取值为"AVD"为下发文件, 取值为"AVL"为本地文件
如:
GPRSR087200612290001.AVU
*/

	GetHostTime(sTempDate);sTempDate[8]=0;
	if(strcmp(UPDCTL.sFileType,"GRI")==0)
		sprintf(sTargetName,"GPRSR%s%s%04d.AVU",
			UPDCTL.sBelongCode,sTempDate,atoi(sNextSeq));
	else if(strcmp(UPDCTL.sFileType,"GII")==0)
		sprintf(sTargetName,"GPRSI%s%s%04d.AVU",
			UPDCTL.sBelongCode,sTempDate,atoi(sNextSeq));
	else
		sprintf(sTargetName,"GPRSP%s%s%04d.AVL",
			UPDCTL.sBelongCode,sTempDate,atoi(sNextSeq));

	strcpy(UPDCTL.sTargetName,sTargetName);
}
void Gprsjf_InitFileHead(int iUpdataID,struct UpdataLogStruct *p)
{
	char sDateTime[15];
	struct GprsHeadStruct *po=(struct GprsHeadStruct *)UPDCTL.sHead;

	/*初始化文件头*/
	UPDCTL.iHeadLen=sizeof(struct GprsHeadStruct);
	bzero((void*)po,UPDCTL.iHeadLen);

	strcpy(po->sRecordType,"50");	/*固定为10*/
	strncpy(po->sProvCode,UPDCTL.sBelongCode,3);po->sProvCode[3]=0;
	strcpy(po->sFileFlag,"GPRS");
	sprintf(po->sFileSeq,"%04d",iUpdataID);
	strcpy(po->sFileVersion,"01");

	GetHostTime(sDateTime);
	strncpy(po->sFileCreatDate,sDateTime,8);po->sFileCreatDate[8]=0;

	strcpy(po->sFirstCallDate,"20300101");
	strcpy(po->sFirstCallTime,"000000");
	strcpy(po->sLastCallDate,"19900101");
	strcpy(po->sLastCallTime,"000000");

	sprintf(po->sTotalCnt,"%010d",0);
	sprintf(po->sTotalFee,"%015d",0);
	LeftPad(po->sNouse,342,' ');

}

/**==============================**/
/*	中国电信C网改造		 **/
/**==============================**/
int IsNewCdmaBill(char sFileType[])
{
	if(strcmp(sFileType,"CDMAC")==0||
		strcmp(sFileType,"CDMAR")==0||
		strcmp(sFileType,"CDMAS")==0||
		strcmp(sFileType,"CDMAT")==0||
		strcmp(sFileType,"CDMAD")==0||
		strcmp(sFileType,"CDMAI")==0) return true;
	return false;
}
int IsNewCdma1xBill(char sFileType[])
{
	if(strcmp(sFileType,"C1XC")==0||
		strcmp(sFileType,"C1XR")==0||
		strcmp(sFileType,"C1XS")==0||
		strcmp(sFileType,"C1XT")==0||
		strcmp(sFileType,"C1XD")==0||
		strcmp(sFileType,"C1XI")==0) return true;
	return false;
}

int IsNewSmsBill(char sFileType[])
{
	if(strcmp(sFileType,"SMS")==0) return true;
	return false;
}
int IsNewSmspBill(char sFileType[])
{
	if(strcmp(sFileType,"SMSP")==0) return true;
	return false;
}
void NewCdma1x_AssignFileName(char sNextSeq[],char sTargetName[])
{
	char sDay[7];

	strncpy(sDay,UPDCTL.sDealDate+2,6);sDay[6]=0;

	sprintf(sTargetName,"CDMA1XD%s%c%04d%s.AVL",
		UPDCTL.sDataCityCode,UPDCTL.sFileType[strlen(UPDCTL.sFileType)-1],
		atoi(sNextSeq),sDay);
}
void NewSms_AssignFileName(char sNextSeq[],char sTargetName[])
{
	int iSeq=atoi(sNextSeq);
	char sDay[7];

	strncpy(sDay,UPDCTL.sDealDate+2,6);sDay[6]=0;

	if(strcmp(UPDCTL.sFileType,"SMS")==0)
		sprintf(sTargetName,"SMS%sC%04d%s.AVL",
			UPDCTL.sDataCityCode,iSeq,sDay);
	else if(strcmp(UPDCTL.sFileType,"SMSP")==0)
		sprintf(sTargetName,"SMSP%sC%04d%s.AVL",
			UPDCTL.sDataCityCode,iSeq,sDay);
	else	sprintf(sTargetName,"%s%sC%04d%s.AVL",
			UPDCTL.sFileType,UPDCTL.sDataCityCode,iSeq,sDay);
}

