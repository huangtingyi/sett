/*---------ͷ�ļ����� up_highcharge.h----------*/
#ifndef __UP_HIGHCHARGE_H__
#define __UP_HIGHCHARGE_H__

/*�����ļ�*/
#include <stdio.h>
#include <sqlca.h>
#include <datatype.h>
#include <bintree.h>
#include <trie.h>
#include <list.h>
#include <wwdb.h>
/*����һ��64λ������*/
/*typedef long LONGINT;*/


/*�����ṹ����*/
struct UpHighchargeStruct{

	struct UpHighchargeStruct *pNext;
	char    sImsi[16];
	int     iTotalCharge;
	char    sFirstCallTime[15];
	char    sLastCallTime[15];
	char	sProvCode[4];
};



/*����ṹ��������*/
struct UpHighchargeStructOut{

#ifndef UP_HIGHCHARGE_BUFLEN_OUT
#define UP_HIGHCHARGE_BUFLEN_OUT		1000
#endif

	struct UpHighchargeStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asImsi[UP_HIGHCHARGE_BUFLEN_OUT][16];
	int     aiTotalCharge[UP_HIGHCHARGE_BUFLEN_OUT];
	char    asFirstCallTime[UP_HIGHCHARGE_BUFLEN_OUT][15];
	char    asLastCallTime[UP_HIGHCHARGE_BUFLEN_OUT][15];
	char	asProvCode[UP_HIGHCHARGE_BUFLEN_OUT][4];
};



/* ����ṹ��������*/
struct UpHighchargeStructIn{

#ifndef UP_HIGHCHARGE_BUFLEN_IN
#define UP_HIGHCHARGE_BUFLEN_IN		1000
#endif

	struct UpHighchargeStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[256];
	char    asImsi[UP_HIGHCHARGE_BUFLEN_IN][16];
	int     aiTotalCharge[UP_HIGHCHARGE_BUFLEN_IN];
	char    asFirstCallTime[UP_HIGHCHARGE_BUFLEN_IN][15];
	char    asLastCallTime[UP_HIGHCHARGE_BUFLEN_IN][15];
	char	asProvCode[UP_HIGHCHARGE_BUFLEN_IN][4];
};

#endif
