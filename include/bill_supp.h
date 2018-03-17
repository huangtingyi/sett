#ifndef __BILL_SUPP_H__
#define __BILL_SUPP_H__

#include <stt_ticket.h>

int ProcessRateTicket(struct FileControlListStruct *ptHead,char sAreaCode[],
	char sBaseName[],char sModule[],struct FileControlStruct *pRec,
	char sSplitNew[],int *piErrCode,int *piErrInfo);
int ProcessRateFile(char sFileName[],char sVisitAreaCode[],char sModule[],
	char sNormalDir[],char sErrDir[],char sSource[],int iWantCtl,
	char sSplit[],int iStartPos,int iKeyLen,
	struct FileControlListStruct *pControlList,char sResult[]);
void InitParamMem();
void DestroyParamMem();
int CompileExprFile(char sExprName[]);


void mvitem_prep2mobticket(struct FileControlStruct *p,
	char sVisitAreaCode[],struct MobTicketStruct *po);
void mvitem_prep2mobticket_x(char sData[],int iLen,
	char sVisitAreaCode[],struct MobTicketStruct *po);

int ProcessTicket(struct FileControlListStruct *pList,char sTemplateRule[],
	int f,char sModule[],struct MobTicketStruct *p,char sSplitNew[]);
void InitSttMsisdnOtherParty(struct MobTicketStruct *p);
void InitBilMsisdnOtherParty(struct MobTicketStruct *p);
void mvitem_stt2dup(struct FPrepTicketStruct *pi,struct DupKeyStruct *po);
void mvitem_bil2dup(struct FPrepTicketStruct *pi,struct DupKeyStruct *po);
int comp_insert_list_dup_key_bil(LIST *pValue,LIST*pHead);
int comp_insert_list_dup_key_stt(LIST *pValue,LIST*pHead);
void DeleteDupTicket(struct FileControlStruct **pptHead);

extern struct	MobTicketStruct Ticket;
extern struct FileControlStruct *pDup;
extern void (*InitMsisdnOtherParty)(struct MobTicketStruct *p);
extern int (*comp_insert_list_dup_key_e)(LIST *pValue,LIST*pHead);
extern void (*mvitem_ticket2dup)(struct FPrepTicketStruct *pi,struct DupKeyStruct *po);

int GetBillingFlag(char sSplitStr[]);
int ProcessBillFile(char sFileName[],char sVisitAreaCode[],char sModule[],
	char sNormalDir[],char sErrDir[],char sTemplateRule[],
	char sUserType[],int iBillFlag,char sSource[],
	int iWantCtl,char sSplit[],int iStartPos,int iKeyLen,
	struct	FileControlListStruct *pControlList,char sResult[]);
int GetFullFlag(char sSplitStr[]);

int WantWriteErrTicket(struct MobTicketStruct *p,int iFlag);
int mvitem2preperr(struct FileControlStruct *pTemp,
	int iErrCode,char sRecord[512]);


#endif

