#ifndef __SETT_ITEM_H__
#define __SETT_ITEM_H__

/*����ṹ��������*/
struct SettItemStructOut{

#ifndef SETT_ITEM_BUFLEN_OUT
#define SETT_ITEM_BUFLEN_OUT		300
#endif

	struct SettItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������Ŀ��ʶ */
	int     aiSettItemID[SETT_ITEM_BUFLEN_OUT];
		/* ��������ʾ */
	int     aiLatnID[SETT_ITEM_BUFLEN_OUT];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[SETT_ITEM_BUFLEN_OUT];
		/* ������ʾ�ƶ����롢������ʾ�ƶ����� */
	int     aiCharge[SETT_ITEM_BUFLEN_OUT];
		/* �ϸ�ȡ����ʱ��,��ȷ���� */
	char    asSettItemDate[SETT_ITEM_BUFLEN_OUT][15];
		/* �������� */
	char    asCreatedDate[SETT_ITEM_BUFLEN_OUT][15];
		/* S0A���ã�S0X���� */
	char    asState[SETT_ITEM_BUFLEN_OUT][4];
	
	int	aiOppCarrierID[SETT_ITEM_BUFLEN_OUT];
	int	aiSettCycleID[SETT_ITEM_BUFLEN_OUT];
	char    asUserType[SETT_ITEM_BUFLEN_OUT][11];
	char    asSourceID[SETT_ITEM_BUFLEN_OUT][31];
	
};


/* ����ṹ��������*/
struct SettItemStructIn{

#ifndef SETT_ITEM_BUFLEN_IN
#define SETT_ITEM_BUFLEN_IN		300
#endif

	struct SettItemStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ������Ŀ��ʶ */
	int     aiSettItemID[SETT_ITEM_BUFLEN_IN];
		/* ��������ʾ */
	int     aiLatnID[SETT_ITEM_BUFLEN_IN];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[SETT_ITEM_BUFLEN_IN];
		/* ������ʾ�ƶ����롢������ʾ�ƶ����� */
	int     aiCharge[SETT_ITEM_BUFLEN_IN];
		/* �ϸ�ȡ����ʱ��,��ȷ���� */
	char    asSettItemDate[SETT_ITEM_BUFLEN_IN][15];
		/* �������� */
	char    asCreatedDate[SETT_ITEM_BUFLEN_IN][15];
		/* S0A���ã�S0X���� */
	char    asState[SETT_ITEM_BUFLEN_IN][4];
	
	int	aiOppCarrierID[SETT_ITEM_BUFLEN_IN];
	int	aiSettCycleID[SETT_ITEM_BUFLEN_IN];
	char    asUserType[SETT_ITEM_BUFLEN_IN][11];
	char    asSourceID[SETT_ITEM_BUFLEN_IN][31];
	char	asRowID[SETT_ITEM_BUFLEN_IN][19];
};


/*�����ṹ����*/
struct SettItemStruct{

	struct SettItemStruct *pNext;
	int     iSettItemID;		/* ������Ŀ��ʶ */
	int     iLatnID;		/* ��������ʾ */
	int     iAcctItemTypeID;		/* ��Ŀ���ͱ�ʶ */
	int     iCharge;		/* ������ʾ�ƶ����롢������ʾ�ƶ����� */
	char    sSettItemDate[15];		/* �ϸ�ȡ����ʱ��,��ȷ���� */
	char    sCreatedDate[15];		/* �������� */
	char    sState[4];		/* S0A���ã�S0X���� */
	int	iOppCarrierID;
	int	iSettCycleID;
	char	sUserType[11];
	char	sSourceID[31];
	char	sRowID[19];
	struct SettItemStruct *pLoadNext;
};

/*����ṹ��������*/
struct SettItemStructUp{

#ifndef SETT_ITEM_BUFLEN_UP
#define SETT_ITEM_BUFLEN_UP		300
#endif

	struct SettItemStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* ������Ŀ��ʶ */
	int     aiSettItemID[SETT_ITEM_BUFLEN_UP];
		/* ��������ʾ */
	int     aiLatnID[SETT_ITEM_BUFLEN_UP];
		/* ��Ŀ���ͱ�ʶ */
	int     aiAcctItemTypeID[SETT_ITEM_BUFLEN_UP];
		/* ������ʾ�ƶ����롢������ʾ�ƶ����� */
	int     aiCharge[SETT_ITEM_BUFLEN_UP];
		/* �ϸ�ȡ����ʱ��,��ȷ���� */
	char    asSettItemDate[SETT_ITEM_BUFLEN_UP][15];
		/* �������� */
	char    asCreatedDate[SETT_ITEM_BUFLEN_UP][15];
		/* S0A���ã�S0X���� */
	char    asState[SETT_ITEM_BUFLEN_UP][4];
	
	int	aiOppCarrierID[SETT_ITEM_BUFLEN_UP];
	int	aiSettCycleID[SETT_ITEM_BUFLEN_UP];
	char    asUserType[SETT_ITEM_BUFLEN_UP][11];
	char    asSourceID[SETT_ITEM_BUFLEN_UP][31];
	char	asRowID[SETT_ITEM_BUFLEN_UP][19];
	
};


/*�������ݶ�̬��SETT_ITEM���ýṹ���巽ʽȡ����*/
int EGetSettItemToStruct(struct SettItemStruct *p,
	struct SettItemStructIn *pSource);
/**�Ա�SETT_ITEM�������ͷź���**/
void DestroySettItem(struct SettItemStruct *ptHead);
int InitSettItem(struct SettItemStruct **pptHead);
int EInsertStructToSettItem(struct SettItemStruct *p,
	int iInsertFlag,struct SettItemStructOut *pTarget);
int EUpdateStructToSettItem(struct SettItemStruct *p,
	int iUpdateFlag,struct SettItemStructUp *pTarget);

int iGetAcctItemID();
void mvitem_settitem(struct SettItemStruct *pi,struct SettItemStruct *po);

int CheckAcctDbCtrl(int iLatnId,char sModule[]);
int SetAcctDbCtrl(int iLatnId,char sModule[],char sState[]);

#endif
