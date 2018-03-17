#ifndef __STT_SCP_H__
#define __STT_SCP_H__
#include <bintree.h>
#include <stt_ticket.h>


int UpdateSttState(struct SttTicketStruct *pSourcet,char sTableName[],
	int iUpdateFlag);
int ModifyTicketScpFlag(struct SttTicketStruct *p,char sScpFlag[]);
int AnalyzeTicket(struct SttTicketStruct *pSource,char sTableName[],
	struct SttTicketStruct **pTarget,struct SttTicketStruct **ptUp);
int cmitem_ticket_spot(void *pi,void *po);
int mvitem_SttTicketStruct(struct SttTicketStruct *pi,struct SttTicketStruct *po);
int ProcessFile(struct SttTicketStruct *pSource,char sTargetName[]);
	
#endif



