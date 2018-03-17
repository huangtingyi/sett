#ifndef HUAWEI_MSC_H
#define HUAWEI_MSC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmdparse.h"

int AddCmdHeadTail(char sCmd[]);
int ProcCmd(int(*Proc)(int iBusi,struct ResultStruct **pptHead),
	struct InfoItemStruct *ptInfoItem,char sCmdType[],struct ResultStruct **pptResult);

/*创建新用户请求*/
int ProcCRUSER(int iBusi,struct ResultStruct **pptHead);

/*业务控制请求*/
int ProcCHGSRV(int iBusi,struct ResultStruct **pptHead);

/*删除用户请求*/
int ProcDLUSER(int iBusi,struct ResultStruct **pptHead);

/*修改用户IMSI请求*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead);

/*修改用户DN请求*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead);

/*修改用户ESN请求*/
int ProcCHGESN(int iBusi,struct ResultStruct **pptHead);

/*修改用户PIC请求*/
int ProcCHGPIC(int iBusi,struct ResultStruct **pptHead);

/*用户信息查询请求*/
int ProcQUINFO(int iBusi,struct ResultStruct **pptHead);

/*用户信息查询反馈*/
int ProcUSIRSP(int iBusi,struct ResultStruct **pptHead);

/*反馈结果应答*/
int ProcRSPACK(int iBusi,struct ResultStruct **pptHead);

/*收到请求应答*/
int ProcREQACK(int iBusi,struct ResultStruct **pptHead);

/*请求结果消息*/
int ProcFEBRSP(int iBusi,struct ResultStruct **pptHead);

/*工单内容查询请求*/
int ProcQWINFO(int iBusi,struct ResultStruct **pptHead);

/*工单状态查询请求*/
int ProcQWSTAT(int iBusi,struct ResultStruct **pptHead);

/*工单内容查询结果消息*/
int ProcWDTRSP(int iBusi,struct ResultStruct **pptHead);

/*查询工单结果消息*/
int ProcWITRSP(int iBusi,struct ResultStruct **pptHead);

#endif
