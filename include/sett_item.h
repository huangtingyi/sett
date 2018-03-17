#ifndef __SETT_ITEM_H__
#define __SETT_ITEM_H__

/*输出结构缓冲申明*/
struct SettItemStructOut{

#ifndef SETT_ITEM_BUFLEN_OUT
#define SETT_ITEM_BUFLEN_OUT		300
#endif

	struct SettItemStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算帐目标识 */
	int     aiSettItemID[SETT_ITEM_BUFLEN_OUT];
		/* 本地网表示 */
	int     aiLatnID[SETT_ITEM_BUFLEN_OUT];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[SETT_ITEM_BUFLEN_OUT];
		/* 正数表示移动收入、负数表示移动付出 */
	int     aiCharge[SETT_ITEM_BUFLEN_OUT];
		/* 严格取话单时间,精确到天 */
	char    asSettItemDate[SETT_ITEM_BUFLEN_OUT][15];
		/* 生成日期 */
	char    asCreatedDate[SETT_ITEM_BUFLEN_OUT][15];
		/* S0A在用，S0X不用 */
	char    asState[SETT_ITEM_BUFLEN_OUT][4];
	
	int	aiOppCarrierID[SETT_ITEM_BUFLEN_OUT];
	int	aiSettCycleID[SETT_ITEM_BUFLEN_OUT];
	char    asUserType[SETT_ITEM_BUFLEN_OUT][11];
	char    asSourceID[SETT_ITEM_BUFLEN_OUT][31];
	
};


/* 输入结构缓冲申明*/
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
		/* 结算帐目标识 */
	int     aiSettItemID[SETT_ITEM_BUFLEN_IN];
		/* 本地网表示 */
	int     aiLatnID[SETT_ITEM_BUFLEN_IN];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[SETT_ITEM_BUFLEN_IN];
		/* 正数表示移动收入、负数表示移动付出 */
	int     aiCharge[SETT_ITEM_BUFLEN_IN];
		/* 严格取话单时间,精确到天 */
	char    asSettItemDate[SETT_ITEM_BUFLEN_IN][15];
		/* 生成日期 */
	char    asCreatedDate[SETT_ITEM_BUFLEN_IN][15];
		/* S0A在用，S0X不用 */
	char    asState[SETT_ITEM_BUFLEN_IN][4];
	
	int	aiOppCarrierID[SETT_ITEM_BUFLEN_IN];
	int	aiSettCycleID[SETT_ITEM_BUFLEN_IN];
	char    asUserType[SETT_ITEM_BUFLEN_IN][11];
	char    asSourceID[SETT_ITEM_BUFLEN_IN][31];
	char	asRowID[SETT_ITEM_BUFLEN_IN][19];
};


/*单个结构申明*/
struct SettItemStruct{

	struct SettItemStruct *pNext;
	int     iSettItemID;		/* 结算帐目标识 */
	int     iLatnID;		/* 本地网表示 */
	int     iAcctItemTypeID;		/* 帐目类型标识 */
	int     iCharge;		/* 正数表示移动收入、负数表示移动付出 */
	char    sSettItemDate[15];		/* 严格取话单时间,精确到天 */
	char    sCreatedDate[15];		/* 生成日期 */
	char    sState[4];		/* S0A在用，S0X不用 */
	int	iOppCarrierID;
	int	iSettCycleID;
	char	sUserType[11];
	char	sSourceID[31];
	char	sRowID[19];
	struct SettItemStruct *pLoadNext;
};

/*输出结构缓冲申明*/
struct SettItemStructUp{

#ifndef SETT_ITEM_BUFLEN_UP
#define SETT_ITEM_BUFLEN_UP		300
#endif

	struct SettItemStructUp *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* 结算帐目标识 */
	int     aiSettItemID[SETT_ITEM_BUFLEN_UP];
		/* 本地网表示 */
	int     aiLatnID[SETT_ITEM_BUFLEN_UP];
		/* 帐目类型标识 */
	int     aiAcctItemTypeID[SETT_ITEM_BUFLEN_UP];
		/* 正数表示移动收入、负数表示移动付出 */
	int     aiCharge[SETT_ITEM_BUFLEN_UP];
		/* 严格取话单时间,精确到天 */
	char    asSettItemDate[SETT_ITEM_BUFLEN_UP][15];
		/* 生成日期 */
	char    asCreatedDate[SETT_ITEM_BUFLEN_UP][15];
		/* S0A在用，S0X不用 */
	char    asState[SETT_ITEM_BUFLEN_UP][4];
	
	int	aiOppCarrierID[SETT_ITEM_BUFLEN_UP];
	int	aiSettCycleID[SETT_ITEM_BUFLEN_UP];
	char    asUserType[SETT_ITEM_BUFLEN_UP][11];
	char    asSourceID[SETT_ITEM_BUFLEN_UP][31];
	char	asRowID[SETT_ITEM_BUFLEN_UP][19];
	
};


/*批量数据动态从SETT_ITEM中用结构缓冲方式取数据*/
int EGetSettItemToStruct(struct SettItemStruct *p,
	struct SettItemStructIn *pSource);
/**对表SETT_ITEM的链表释放函数**/
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
