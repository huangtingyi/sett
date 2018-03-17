#ifndef __C1XADAPT_H__
#define __C1XADAPT_H__

struct	Cdma1XCmdHeadStruct
{
	char	sHeadIdentify[3];	/*�̶�Ϊ"MHF"*/
	char	sVersion[5];		/*�̶�Ϊ"00001"*/
	char	sOppSysCode[8];		/*�̶�Ϊ"        "*/
	char	sMySysCode[8];		/*�̶�Ϊ"        "*/
	char	sRequestTime[14];
	char	sSerialNbr[16];
	char	sPriority[2];
	char	sCmdType[6];		
	char	sBodyLen[4];
};

struct CmdFieldStruct{

	char sServType[15];	
	char sName[24];
	char sDesc[64];
	char cType;
	int  iLen;
};

#endif

