#ifndef __SETTBID_SUPP_H__
#define __SETTBID_SUPP_H__


/*�����ṹ����*/
struct SpContactRuleStruct{

	struct SpContactRuleStruct *pNext;
	int     iRuleID;		/* �����ʶ */
	int	iContactID;
	int     iSeq;			/* ���к� */
	char    sFeeType[2];		/* '0' ����Ϣ�ѣ�ͨ�ŷѣ�'1'����Ϣ�� */
	char    sType[2];		/* �������� */
	int     iMinTotalFee;		/* ��С�ܷ��ã�Zͨ�ŷѣ���Ϣ�ѣ� */
	int     iMaxTotalFee;		/* ����ܷ��ã�Zͨ�ŷѣ���Ϣ�ѣ� */
	int     iBalCommRate;		/* ������ͨ�ŷ��ʣ�Y �֣� */
	int     iInfoDisctRatio;	/* ��Ϣ��ʧ���ʣ�a���ٷֱȣ� */
	int     iInfoSettRatio;		/* ��Ϣ�ѽ�����ʣ�b �ٷֱȣ� */
	int     iValue;			/* ����ֵ(c ��) */
	int     iP1;			/* ��չ����1 */
	int     iP2;			/* ��չ����2 */
	char    sEffDate[15];		/* ��Чʱ�� */
	char    sExpDate[15];		/* ʧЧʱ�� */
	char    sState[4];		/* ״̬ */
	char    sStateDate[15];		/* ״̬���� */
	int     iStaffID;		/* Ա������ */
	struct SpContactRuleStruct *pLoadNext;
};

/* ����ṹ��������*/
struct SpContactRuleStructIn{

#ifndef SP_CONTACT_RULE_BUFLEN_IN
#define SP_CONTACT_RULE_BUFLEN_IN		300
#endif

	struct SpContactRuleStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* �����ʶ */
	int     aiRuleID[SP_CONTACT_RULE_BUFLEN_IN];
	int	aiContactID[SP_CONTACT_RULE_BUFLEN_IN];
		/* ���к� */
	int     aiSeq[SP_CONTACT_RULE_BUFLEN_IN];
		/* '0' ����Ϣ�ѣ�ͨ�ŷѣ�'1'����Ϣ�� */
	char    asFeeType[SP_CONTACT_RULE_BUFLEN_IN][2];
		/* �������� */
	char    asType[SP_CONTACT_RULE_BUFLEN_IN][2];
		/* ��С�ܷ��ã�Zͨ�ŷѣ���Ϣ�ѣ� */
	int     aiMinTotalFee[SP_CONTACT_RULE_BUFLEN_IN];
		/* ����ܷ��ã�Zͨ�ŷѣ���Ϣ�ѣ� */
	int     aiMaxTotalFee[SP_CONTACT_RULE_BUFLEN_IN];
		/* ������ͨ�ŷ��ʣ�Y �֣� */
	int     aiBalCommRate[SP_CONTACT_RULE_BUFLEN_IN];
		/* ��Ϣ��ʧ���ʣ�a���ٷֱȣ� */
	int     aiInfoDisctRatio[SP_CONTACT_RULE_BUFLEN_IN];
		/* ��Ϣ�ѽ�����ʣ�b �ٷֱȣ� */
	int     aiInfoSettRatio[SP_CONTACT_RULE_BUFLEN_IN];
		/* ����ֵ(c ��) */
	int     aiValue[SP_CONTACT_RULE_BUFLEN_IN];
		/* ��չ����1 */
	int     aiP1[SP_CONTACT_RULE_BUFLEN_IN];
		/* ��չ����2 */
	int     aiP2[SP_CONTACT_RULE_BUFLEN_IN];
		/* ��Чʱ�� */
	char    asEffDate[SP_CONTACT_RULE_BUFLEN_IN][15];
		/* ʧЧʱ�� */
	char    asExpDate[SP_CONTACT_RULE_BUFLEN_IN][15];
		/* ״̬ */
	char    asState[SP_CONTACT_RULE_BUFLEN_IN][4];
		/* ״̬���� */
	char    asStateDate[SP_CONTACT_RULE_BUFLEN_IN][15];
		/* Ա������ */
	int     aiStaffID[SP_CONTACT_RULE_BUFLEN_IN];
};



int EGetSpContactRuleToStruct(struct SpContactRuleStruct *p,
	struct SpContactRuleStructIn *pSource);

int CalcSpSettFee(int t,int x,int br,int xs,int mo,int mt,int iContactID,char sStartTime[]);
int GetBalCommRate(int t,int x,int iContactID,char sStartTime[]);
int data_search_bintree_sp_contact_rule_e(void *pValue,void*pData);
int SearchSpContactRule(int iContactID,int t,int x,
	char sStartTime[],struct SpContactRuleStruct **pptCur);
int data_search_bintree_sp_contact_rule_e(void *pValue,void*pData);
void RegSpSettExprFun();

#endif

