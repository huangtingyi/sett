#ifndef __FTAM_H__
#define __FTAM_H__

struct FTtscofStruct
{
	unsigned char cStatus;
	unsigned char cSec;
	unsigned char cMin;
	unsigned char cHour;
	unsigned char cDay;
	unsigned char cMon;
	unsigned char cYearLow;
	unsigned char cYearHigh;
	unsigned char cReserve;
};
struct FTttcofStruct
{
	unsigned char cSec;
	unsigned char cMin;
	unsigned char cHour;
	unsigned char cDay;
	unsigned char cMon;
	unsigned char cYearLow;
	unsigned char cYearHigh;
};

struct TtcofStruct
{
	int	iSeq;
	char	sStatus[2];
	char	sDate[15];
};

#define MAX_FILE_SEQ	1000

void mvitem_tts2tt(struct FTtscofStruct *pi,int iSeq,struct TtcofStruct *po);
void mvitem_tt2ttt(struct TtcofStruct *pi,struct FTttcofStruct *po);


#endif

