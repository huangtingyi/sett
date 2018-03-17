#ifndef __IMSIESN_H__
#define __IMSIESN_H__

/* ����ṹ��������*/
struct MsisdnImsiEsnStructIn{

#ifndef MSISDN_IMSI_ESN_BUFLEN_IN
#define MSISDN_IMSI_ESN_BUFLEN_IN		300
#endif

	struct MsisdnImsiEsnStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asMsisdn[MSISDN_IMSI_ESN_BUFLEN_IN][16];
	char    asImsi[MSISDN_IMSI_ESN_BUFLEN_IN][16];
	char    asEsn[MSISDN_IMSI_ESN_BUFLEN_IN][16];
	char	asYear[MSISDN_IMSI_ESN_BUFLEN_IN][5];
	char    asYMap[MSISDN_IMSI_ESN_BUFLEN_IN][73];
	char	asRowID[MSISDN_IMSI_ESN_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct MsisdnImsiEsnStruct{

	struct MsisdnImsiEsnStruct *pNext;
	char    sMsisdn[16];
	char    sImsi[16];
	char    sEsn[16];
	char    sYear[5];
	char    sYMap[73];
	char	sRowID[19];
	char	cFlag;	/*0 һ��,1��һ��*/
};
/*�����ṹ����*/
struct UMsisdnImsiEsnStruct{

	char    sYMap[73];
	char	sRowID[19];
};

struct UMsisdnImsiEsnStructUp
{
#ifndef MSISDN_IMSI_ESN_BUFLEN_UP
#define MSISDN_IMSI_ESN_BUFLEN_UP 	1000
#endif
	int	iCurPos;
	char	sTableName[31];
		/* ״̬ */
	char    asYMap[MSISDN_IMSI_ESN_BUFLEN_UP][73];
		/* ����ʱ�� */
	char	asRowID[MSISDN_IMSI_ESN_BUFLEN_UP][19];
};

int EGetMsisdnImsiEsnToStruct(struct MsisdnImsiEsnStruct *p,
	struct MsisdnImsiEsnStructIn *pSource);
int EUpdateStructToMsisdnImsiEsn(struct UMsisdnImsiEsnStruct *p,
        int iUpdateFlag,struct UMsisdnImsiEsnStructUp *pTarget);
int GetMsisdnImsiEsnRowID(struct MsisdnImsiEsnStruct *p,char sRowID[]);

#endif
