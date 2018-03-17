#ifndef __SETTBID_SUPP_H__
#define __SETTBID_SUPP_H__


/*单个结构申明*/
struct SpContactRuleStruct{

	struct SpContactRuleStruct *pNext;
	int     iRuleID;		/* 规则标识 */
	int	iContactID;
	int     iSeq;			/* 序列号 */
	char    sFeeType[2];		/* '0' ：信息费＋通信费，'1'：信息费 */
	char    sType[2];		/* 结算类型 */
	int     iMinTotalFee;		/* 最小总费用（Z通信费＋信息费） */
	int     iMaxTotalFee;		/* 最大总费用（Z通信费＋信息费） */
	int     iBalCommRate;		/* 不均衡通信费率（Y 分） */
	int     iInfoDisctRatio;	/* 信息损失比率（a　百分比） */
	int     iInfoSettRatio;		/* 信息费结算比率（b 百分比） */
	int     iValue;			/* 绝对值(c 分) */
	int     iP1;			/* 扩展参数1 */
	int     iP2;			/* 扩展参数2 */
	char    sEffDate[15];		/* 生效时间 */
	char    sExpDate[15];		/* 失效时间 */
	char    sState[4];		/* 状态 */
	char    sStateDate[15];		/* 状态日期 */
	int     iStaffID;		/* 员工工号 */
	struct SpContactRuleStruct *pLoadNext;
};

/* 输入结构缓冲申明*/
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
		/* 规则标识 */
	int     aiRuleID[SP_CONTACT_RULE_BUFLEN_IN];
	int	aiContactID[SP_CONTACT_RULE_BUFLEN_IN];
		/* 序列号 */
	int     aiSeq[SP_CONTACT_RULE_BUFLEN_IN];
		/* '0' ：信息费＋通信费，'1'：信息费 */
	char    asFeeType[SP_CONTACT_RULE_BUFLEN_IN][2];
		/* 结算类型 */
	char    asType[SP_CONTACT_RULE_BUFLEN_IN][2];
		/* 最小总费用（Z通信费＋信息费） */
	int     aiMinTotalFee[SP_CONTACT_RULE_BUFLEN_IN];
		/* 最大总费用（Z通信费＋信息费） */
	int     aiMaxTotalFee[SP_CONTACT_RULE_BUFLEN_IN];
		/* 不均衡通信费率（Y 分） */
	int     aiBalCommRate[SP_CONTACT_RULE_BUFLEN_IN];
		/* 信息损失比率（a　百分比） */
	int     aiInfoDisctRatio[SP_CONTACT_RULE_BUFLEN_IN];
		/* 信息费结算比率（b 百分比） */
	int     aiInfoSettRatio[SP_CONTACT_RULE_BUFLEN_IN];
		/* 绝对值(c 分) */
	int     aiValue[SP_CONTACT_RULE_BUFLEN_IN];
		/* 扩展参数1 */
	int     aiP1[SP_CONTACT_RULE_BUFLEN_IN];
		/* 扩展参数2 */
	int     aiP2[SP_CONTACT_RULE_BUFLEN_IN];
		/* 生效时间 */
	char    asEffDate[SP_CONTACT_RULE_BUFLEN_IN][15];
		/* 失效时间 */
	char    asExpDate[SP_CONTACT_RULE_BUFLEN_IN][15];
		/* 状态 */
	char    asState[SP_CONTACT_RULE_BUFLEN_IN][4];
		/* 状态日期 */
	char    asStateDate[SP_CONTACT_RULE_BUFLEN_IN][15];
		/* 员工工号 */
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

