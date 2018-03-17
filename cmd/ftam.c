#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwcoding.h>
#include "ftam.h"

void mvitem_tts2tt(struct FTtscofStruct *pi,int iSeq,struct TtcofStruct *po)
{
	bzero((void*)po,sizeof(struct TtcofStruct));
	
	if(pi->cStatus==0x00) strcpy(po->sStatus,"0");
	else if(pi->cStatus==0x01) strcpy(po->sStatus,"1");
	else strcpy(po->sStatus,"2");
	
	po->iSeq=	iSeq;
	
	sprintf(po->sDate,"%02x%02x%02x%02x%02x%02x%02x",
		pi->cYearHigh,pi->cYearLow,pi->cMon,pi->cDay,
		pi->cHour,pi->cMin,pi->cSec);	
}
void mvitem_tt2ttt(struct TtcofStruct *pi,struct FTttcofStruct *po)
{
	char sTempYh[3],sTempYl[3],sTempMon[3],sTempMDay[3],sTempHour[3],
	     sTempMin[3],sTempSec[3],*sAnswerTime;

	sAnswerTime=pi->sDate;
	
	sTempYh[0]=sAnswerTime[0];
	sTempYh[1]=sAnswerTime[1]; sTempYh[2]=0;

	sTempYl[0]=sAnswerTime[2];
	sTempYl[1]=sAnswerTime[3]; sTempYl[2]=0;

	sTempMon[0]=sAnswerTime[4];
	sTempMon[1]=sAnswerTime[5]; sTempMon[2]=0;


	sTempMon[0]=sAnswerTime[4];
	sTempMon[1]=sAnswerTime[5]; sTempMon[2]=0;

	sTempMDay[0]=sAnswerTime[6];
	sTempMDay[1]=sAnswerTime[7]; sTempMDay[2]=0;

	sTempHour[0]=sAnswerTime[8];
	sTempHour[1]=sAnswerTime[9]; sTempHour[2]=0;

	sTempMin[0]=sAnswerTime[10];
	sTempMin[1]=sAnswerTime[11]; sTempMin[2]=0;

	sTempSec[0]=sAnswerTime[12];
	sTempSec[1]=sAnswerTime[13]; sTempSec[2]=0;

	bzero((void*)po,sizeof(struct FTttcofStruct));
	
	po->cYearHigh=	HexStrToInt(sTempYh);
	po->cYearLow=	HexStrToInt(sTempYl);
	po->cMon=	HexStrToInt(sTempMon);
	po->cDay=	HexStrToInt(sTempMDay);
	po->cHour=	HexStrToInt(sTempHour);
	po->cMin=	HexStrToInt(sTempMin);
	po->cSec=	HexStrToInt(sTempSec);
}


