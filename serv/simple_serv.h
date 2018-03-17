#ifndef __SPDB_SPLIT_H__
#define __SPDB_SPLIT_H__

/* 输入结构缓冲申明*/
struct SimpleServStructIn{

#ifndef SIMPLE_SERV_BUFLEN_IN
#define SIMPLE_SERV_BUFLEN_IN		300
#endif

	struct SimpleServStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* 用户号码 */
	char    asMsisdn[SIMPLE_SERV_BUFLEN_IN][16];
	char    asImsi[SIMPLE_SERV_BUFLEN_IN][16];
		/* 出帐状态 */
	char    asState[SIMPLE_SERV_BUFLEN_IN][4];
	char    asBillingTypeID[SIMPLE_SERV_BUFLEN_IN][11];
	char    asReserve[SIMPLE_SERV_BUFLEN_IN][16];
		/* 创建时间 */
	char    asCreatedDate[SIMPLE_SERV_BUFLEN_IN][15];
};


/*单个结构申明*/
struct SimpleServStruct{

	struct SimpleServStruct *pNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sImsi[16];
	char    sState[4];		/* 出帐状态 */
	char    sBillingTypeID[11];
	char    sReserve[16];		/* 系统保留 */
	char    sCreatedDate[15];		/* 创建时间 */
	struct SimpleServStruct *pLoadNext;
};
int EGetSimpleServToStruct(struct SimpleServStruct *p,
	struct SimpleServStructIn *pSource);
int data_search_bintree_simple_serv_e(void *pValue,void*pData);
void assign_insert_bintree_simple_serv_e(void **ppData,void *pData);

#endif

