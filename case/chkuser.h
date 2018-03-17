#ifndef __CHKUSER_H__
#define __CHKUSER_H__


/*�����ṹ����*/
struct YzMsisdnStruct{

	struct YzMsisdnStruct *pNext;
	char    sMsisdn[81];
	char    sState[5];
};



/*����ṹ��������*/
struct YzMsisdnStructOut{

#ifndef YZ_MSISDN_BUFLEN_OUT
#define YZ_MSISDN_BUFLEN_OUT		1000
#endif

	struct YzMsisdnStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asMsisdn[YZ_MSISDN_BUFLEN_OUT][81];
	char    asState[YZ_MSISDN_BUFLEN_OUT][5];
};



/* ����ṹ��������*/
struct YzMsisdnStructIn{

#ifndef YZ_MSISDN_BUFLEN_IN
#define YZ_MSISDN_BUFLEN_IN		1000
#endif

	struct YzMsisdnStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[256];
	char    asMsisdn[YZ_MSISDN_BUFLEN_IN][81];
	char    asState[YZ_MSISDN_BUFLEN_IN][5];
};




int EGetYzMsisdnToStruct(struct YzMsisdnStruct *p,
	struct YzMsisdnStructIn *pSource);
#endif


















































































































