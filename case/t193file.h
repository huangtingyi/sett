#ifndef __T193FILE_H__
#define __T193FILE_H__

struct T193StatStruct
{
	int iSumCallDuration;
	int iSumUnits;
	int iSumCall;
	int iSumCallFee;
	char sCallDate[9];
	/*Ö÷¼ü*/
	char sCallingAreaCode[11];
	char sCalledAreaCode[11];
	char sBusinessType[3];
	char sUserGroupType[3];
	char sOperationType[2];
	char sNetRouteType[2];
	char sCalledType[5];
	
	struct T193StatStruct *next;
};

struct T193StatAllStruct
{
	int	iSumAllFileRecord;
	int	iSumAllCallDuration;
	int	iSumAllUnits;
	int	iSumAllCall;
	int	iSumAllCallFee;
};

struct T193FileHeadStruct
{
	char	sSumAllFileRecord[12];
	char	sSumAllCallDuration[15];
	char	sSumAllUnits[15];
	char	sSumAllCall[15];
	char	sSumAllCallFee[15];
	char	sFileOpMode[1];
	char	sReturn[1];
	char	sNewLine[1];

	/*
	char sfiles_sum[12];
	char sduration_sum[15];
	char sunits_sum[15];
	char scall_sum[15];
	char scharge_sum[15];
	char sopt_file_flag[1];
	char sReturn[1];
	char sNewLine[1];
	*/	
};

struct T193FileBodyStruct
{
	char sCallingAreaCode[11];
	char sCalledAreaCode[11];
	char sBusinessType[3];
	char sUserGroupType[3];
	char sOperationType[2];
	char sNetRouteType[2];
	char sCalledType[5];
	char sCallDate[9];

	char sSumCallDuration[10];
	char sSumUnits[10];
	char sSumCall[10];
	char sSumCallFee[10];	
};

#endif
