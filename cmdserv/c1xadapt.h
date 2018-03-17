#ifndef __C1XADAPT_H__
#define __C1XADAPT_H__

struct	Cdma1XCmdHeadStruct
{
	char	sHeadIdentify[3];	/*固定为"MHF"*/
	char	sVersion[5];		/*固定为"00001"*/
	char	sOppSysCode[8];		/*固定为"        "*/
	char	sMySysCode[8];		/*固定为"        "*/
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

