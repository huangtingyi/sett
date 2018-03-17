#ifndef __APPSUPP_H__
#define __APPSUPP_H__

#include <param_intf.h>

void printsourceNORMAL(char sSourceID[],char *fmt,...);
void printNORMAL(char *fmt,...);
void printALERT(char *fmt,...);

int FInitPickList(char sFileName[],int iGroupID,
	struct PickParamStruct **pptHead);
int GetPickParamList(char sFileName[],int iGroupID,
	struct PickParamStruct **pptHead);

int FInitPrepList(char sFileName[],int iGroupID,
	struct PrepParamStruct **pptHead);
int GetPrepParamList(char sFileName[],int iGroupID,
	struct PrepParamStruct **pptHead);

int FInitDispList(char sFileName[],int iGroupID,
	struct DispParamStruct **pptHead);
int GetDispParamList(char sFileName[],int iGroupID,
	struct DispParamStruct **pptHead);

int FInitBillList(char sFileName[],char sAppCode[],int iGroupID,
	struct BillParamStruct **pptHead);
int GetBillParamList(char sFileName[],char sAppCode[],int iGroupID,
	struct BillParamStruct **pptHead);

int FInitInstList(char sFileName[],int iGroupID,
	struct InstParamStruct **pptHead);
int GetInstParamList(char sFileName[],int iGroupID,
	struct InstParamStruct **pptHead);

void GetTaskPath(char sSourcePath[],char sSourceID[],char sTargetPath[]);
int ShmIniName(char sFileName[]);
int FlowIniName(char sFileName[],int *piFlowID);
int GetTacheID(int iParamID,int iFlowID);

void mvitem_task2pick(struct PickTaskParamStruct *pi,int iTacheID,
	struct SourceDescStruct *ps,struct TaskParamStruct *ptp,
	struct PickParamStruct *po);
int GetFlowPickParamList(int iFlowID,int iGroupID,
	struct PickParamStruct **pptHead);

void mvitem_task2prep(struct PrepTaskParamStruct *pi,int iTacheID,
	struct SourceDescStruct *ps,struct TaskParamStruct *ptp,
	struct PrepParamStruct *po);
int GetFlowPrepParamList(int iFlowID,int iGroupID,
	struct PrepParamStruct **pptHead);

int mvitem_task2billlist(struct BillTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct BillParamStruct **pptHead);
int GetFlowBillParamList(int iFlowID,char sAppCode[],int iGroupID,
	struct BillParamStruct **pptHead);
int mvitem_task2instlist(struct InstTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct InstParamStruct **pptHead);
int GetFlowInstParamList(int iFlowID,int iGroupID,
	struct InstParamStruct **pptHead);

int mvitem_task2acctlist(struct AcctTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct AcctParamStruct **pptHead);
int GetFlowAcctParamList(int iFlowID,int iGroupID,
	struct AcctParamStruct **pptHead);

int GetPutParamList(char sFileName[],int iGroupID,
	struct PutParamStruct **pptHead);
int GetFlowPutParamList(int iFlowID,int iGroupID,
	struct PutParamStruct **pptHead);
int FInitPutList(char sFileName[],int iGroupID,
	struct PutParamStruct **pptHead);
void mvitem_task2put(struct PutTaskParamStruct *pi,int iTacheID,
	struct SourceDescStruct *ps,struct TaskParamStruct *ptp,
	struct PutParamStruct *po);
void mvitem_str2put(char sLine[],struct PutParamStruct *p);


void mvitem_str2Intf(char sLine[],struct IntfParamStruct *p);
int FInitIntfList(char sFileName[],int iGroupID,
	struct IntfParamStruct **pptHead);
int mvitem_task2intflist(struct IntfTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct IntfParamStruct **pptHead);
int GetFlowIntfParamList(int iFlowID,int iGroupID,
	struct IntfParamStruct **pptHead);
int GetIntfParamList(char sFileName[],int iGroupID,
	struct IntfParamStruct **pptHead);
int InsertPutLog(char sSourceID[],int iSize,char sFileName[],
	char sDealBeginDate[], char sDealEndDate[],int iSeq,
	char sFileType[],int iTacheID,char sAppID[]);
int PutLogCheck(char sSourceID[20],char sFileName[80],int iChkDays); 
		
void mvitem_str2recy(char sLine[],struct RcylParamStruct *p);
int FInitRcylList(char sFileName[],char sSourceID[],
	struct RcylParamStruct **pptHead);
int mvitem_task2recylist(struct RcylTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct RcylParamStruct **pptHead);
int GetFlowRcylParamList(int iFlowID,char sSourceID[],int iTaskSeqNbr,
	struct RcylParamStruct **pptHead);
int GetRcylParamList(char sFileName[],char sSourceID[],int iTaskSeqNbr,
	struct RcylParamStruct **pptHead);

void mvitem_str2roll(char sLine[],struct RollParamStruct *p);
int FInitRollList(char sFileName[],char sSourceID[],
	struct RollParamStruct **pptHead);
int mvitem_task2rolllist(struct RollTaskParamStruct *pi,int iTacheID,
	struct TaskParamStruct *ptp,struct RollParamStruct **pptHead);
int GetFlowRollParamList(int iFlowID,char sSourceID[],int iTaskSeqNbr,
	struct RollParamStruct **pptHead);
int GetRollParamList(char sFileName[],char sSourceID[],int iTaskSeqNbr,
	struct RollParamStruct **pptHead);
int GetAcctParamList(char sFileName[],int iGroupID,
	struct AcctParamStruct **pptHead);

#endif

