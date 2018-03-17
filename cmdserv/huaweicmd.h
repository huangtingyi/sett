#ifndef HUAWEI_MSC_H
#define HUAWEI_MSC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmdparse.h"

int AddCmdHeadTail(char sCmd[]);
int ProcCmd(int(*Proc)(int iBusi,struct ResultStruct **pptHead),
	struct InfoItemStruct *ptInfoItem,char sCmdType[],struct ResultStruct **pptResult);

/*�������û�����*/
int ProcCRUSER(int iBusi,struct ResultStruct **pptHead);

/*ҵ���������*/
int ProcCHGSRV(int iBusi,struct ResultStruct **pptHead);

/*ɾ���û�����*/
int ProcDLUSER(int iBusi,struct ResultStruct **pptHead);

/*�޸��û�IMSI����*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead);

/*�޸��û�DN����*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead);

/*�޸��û�ESN����*/
int ProcCHGESN(int iBusi,struct ResultStruct **pptHead);

/*�޸��û�PIC����*/
int ProcCHGPIC(int iBusi,struct ResultStruct **pptHead);

/*�û���Ϣ��ѯ����*/
int ProcQUINFO(int iBusi,struct ResultStruct **pptHead);

/*�û���Ϣ��ѯ����*/
int ProcUSIRSP(int iBusi,struct ResultStruct **pptHead);

/*�������Ӧ��*/
int ProcRSPACK(int iBusi,struct ResultStruct **pptHead);

/*�յ�����Ӧ��*/
int ProcREQACK(int iBusi,struct ResultStruct **pptHead);

/*��������Ϣ*/
int ProcFEBRSP(int iBusi,struct ResultStruct **pptHead);

/*�������ݲ�ѯ����*/
int ProcQWINFO(int iBusi,struct ResultStruct **pptHead);

/*����״̬��ѯ����*/
int ProcQWSTAT(int iBusi,struct ResultStruct **pptHead);

/*�������ݲ�ѯ�����Ϣ*/
int ProcWDTRSP(int iBusi,struct ResultStruct **pptHead);

/*��ѯ���������Ϣ*/
int ProcWITRSP(int iBusi,struct ResultStruct **pptHead);

#endif
