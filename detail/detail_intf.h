#ifndef __DETAIL_INTF_H__
#define __DETAIL_INTF_H__

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <bintree.h>
#include <wwfile.h>
#include <ticket.h>
#include <detail_supp.h>


int AccSttTicket2Str(char sTableName[], char sTemp[], char sPrepTime[]);
void mvitem_mfaccsttticket(struct AccSttTicketStruct *pi,struct FAccSttTicketStruct *po);

int AccSmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[]);
void mvitem_mfaccsmsticket(struct AccSmsTicketStruct *pi,struct FAccSmsTicketStruct *po);

int AccMmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[]);
void mvitem_mfaccmmsticket(struct AccMmsTicketStruct *pi,struct FAccMmsTicketStruct *po);

int OdsSttTicket2Str(char sTableName[], char sTemp[], char sPrepTime[]);
void mvitem_mfodssttticket(struct OdsSttTicketStruct *pi,struct FOdsSttTicketStruct *po);

int OdsSmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[]);
void mvitem_mfodssmsticket(struct OdsSmsTicketStruct *pi,struct FOdsSmsTicketStruct *po);

int OdsMmsTicket2Str(char sTableName[], char sTemp[], char sPrepTime[]);
void mvitem_mfodsmmsticket(struct OdsMmsTicketStruct *pi,struct FOdsMmsTicketStruct *po);

int LocSttTicket2Str(char sTableName[], char sTemp[], char sPrepTime[]);
void mvitem_mflocsttticket(struct LocSttTicketStruct *pi,struct FLocSttTicketStruct *po);

struct StPrepTicketCtlStruct{
	struct StPrepTicketCtlStruct *pNext;
	
	char	sRowID[19];
	char	sAuditType[2];
	char	cPreFlag;
	struct StPrepTicketStruct *pTicket;
	
	struct StPrepTicketCtlStruct *pLoadNext;
};


int SearchStAreaMscTimeOffsetItem(char sAreaCode[],struct StAreaMscTimeOffsetStruct **pptCur);

#endif

