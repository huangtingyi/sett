#ifndef __ACCTDB_SUPP_H__
#define __ACCTDB_SUPP_H__

#include <sett_item.h>

int data_search_bintree_acct_item_e(void *pValue,void*pData);
void assign_insert_bintree_acct_item_e(void **ppData,void *pData);
int OutputList2Table(struct SettItemStruct *ptOut,
	struct SettItemStruct *ptUp,char sTableName[]);
int CheckAcctDbCtrl(int iLatnId,char sModule[]);
int SetAcctDbCtrl(int iLatnId,char sModule[],char sState[]);
int CompileStatExpr(char sExprName[]);
int AcctLogCheck(char sFileName[],char sSourceID[],char sModule[]);

int AcctItem2Bin(BINTREE *pRoot,char sTableName[]);

int SearchLatnByAreaCode(char sAreaCode[],struct LatnStruct **pptCur);

int AcctDBMain(char sSourceID[],char sSourcePath[],char sFileType[],
	char sFilter[],char sBackPath[],char sModule[],char sAreaCode[],
	char sItemTableName[],char sDateRule[],char sOperType[],
	char sAppID[],int iTacheID);
#endif

