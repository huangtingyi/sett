#ifndef __WWDB_H__
#define __WWDB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqlcpr.h>

#ifndef NoDataFetched
#define NoDataFetched (sqlca.sqlcode==1403||sqlca.sqlcode==100)
#endif
#ifndef FetchColNum
#define FetchColNum   (sqlca.sqlerrd[2])
#endif

#define PASSWD_KEY    "!{~$%?<*/-+.,;:|"

int GetDbConnStr(int iUserID,char sConnStr[]);
int ConnectDatabase(char sUserName[],char sPassword[],char sStr[]);
void DisconnectDatabase();
void WriteMsgAndCommit(char cStatusChar,char *fmt, ...);
void WriteMsgAndRollback(char *fmt, ...);
void CommitWorkRelease();
void RollbackWorkRelease();
void CommitWork();
void RollbackWork();
void CheckSqlError(char *fmt, ...);
int iDataNotFound();
int TableExist(char sTableName[31]);
int SynonymExist(char sSynonymName[31]);
int IndexExist(char sIndexName[31]);
int TableIndexExist(char sTableName[31]);
int ExecSql(char statement[]);
int DupTable(char *sTemplate, char *sTableName);
int DupTableExt(char *sTemplate, char *sTableName, char *sTableSpaceName);
int DupTableIndex(char * sTemplateTable, char * sTableName, char * sIndExt);
int DupTableIndexExt(char * sTemplateTable, char * sTableName,
	char * sIndExt, char *sTableSpaceName);

int SqlResult(char sFileName[],int iLine,char sMessage[]);
#define SQLRESULT(x)		SqlResult(__FILE__,__LINE__,x)
#define CheckSqlResult(x)	SqlResult(__FILE__,__LINE__,x)
#define CheckSqlError(x)	{\
		if (SqlResult(__FILE__,__LINE__,x)<0){\
			RollbackWorkRelease(); \
			WriteErrStackAlert();\
			exit(1);\
		}\
				}
int FastConnect(char sTemp[]);
int IniConnect(char sConnDp[]);
int TwiceConnect(int iUserID);
int GetIniConnStr(char sConnDp[],char sConnStr[]);

#define ConnectDataDB()	IniConnect("dataconnstr")
#define ConnectParamDB() IniConnect("paramconnstr")
#define ConnectArchDB()	IniConnect("archconnstr")

#define TYPE_OF_CHAR		1
#define TYPE_OF_NUMBER1		-32766
#define TYPE_OF_NUMBER		2
#define TYPE_OF_LONG		8
#define TYPE_OF_ROWID		11
#define TYPE_OF_UNIVERSAL_ROWID	104
#define TYPE_OF_DATETIME	12
#define TYPE_OF_DATETYPE1	-32756
#define TYPE_OF_RAW		23
#define TYPE_OF_LONGRAW		24
#define MAX_ITEMS		64
#define MAX_VNAME_LEN		30
#define MAX_INAME_LEN		30
#define MAX_LEN			4096
#define MAX_REC_LEN		256*1024

#define VALUE_TYPE_STR		'2'
#define VALUE_TYPE_INT		'1'
#define VALUE_TYPE_FLOAT	'3'
#define VALUE_TYPE_DATE		'4'

struct RowStruct
{
	struct RowStruct *pNext;
	int iLen;
	int iFreeLen;
	int iColNum;
	char **apIndex;	/*指向字段值的指针数组，数组大小为iColNum*/
	char *pValue;	/*指向记录内容的区域，所有字段都存在这个区域中*/
};
struct	DataSetStruct
{
	int iRowNum;				/*结果集包含的行数*/
	int iColNum;				/*结果集每行的字段数*/
	char acFieldType[MAX_ITEMS];		/*字段类型指针*/
	char asFieldName[MAX_ITEMS][MAX_VNAME_LEN+1];/*字段名指针*/
	struct RowStruct *pCur;			/*当前行记录结构*/
	struct RowStruct *pRow;			/*行记录结构*/
};

struct RowStruct *MallocRow(int iColNum,int iValueLen);
void DestroyDataSetRow(struct DataSetStruct *pDs);
int InitColNumAndFieldNames(SQLDA *sdp, struct DataSetStruct *pDs,
	char sMessage[]);
int InitStmtDs(char statement[],struct DataSetStruct *pDs,
	int iMaxRow,char sMessage[]);
int GetStmtDs(char statement[],struct DataSetStruct *pDs,char sMessage[]);
void PrintDs(struct DataSetStruct *pDs);
int GetColPos(struct DataSetStruct *pDs,char sColName[]);
int EofDs(struct DataSetStruct *pDs);
void NextDs(struct DataSetStruct *pDs);
char *GetCurRowFieldValue(struct DataSetStruct *pDs,char sFieldName[]);
char *GetIndRowFieldValue(struct DataSetStruct *pDs,int iIndex,
	char sFieldName[]);
void ShrinkRow(struct RowStruct **ppRow);
void SetRowFieldValue(struct DataSetStruct *pDs,struct RowStruct **ppCur,
	char sFieldName[],char sValue[]);
void SetCurRowFieldValue(struct DataSetStruct *pDs,char sFieldName[],
	char sValue[]);
void SetIndRowFieldValue(struct DataSetStruct *pDs,int iIndex,
	char sFieldName[],char sValue[]);

void SetQuit(int iSigNo);
int WantQuit();
int GetConnStr(char sUserId[]);

#define INIT_COMM_STRUCT_IN(t,c,x) {bzero((void*)&(x),sizeof(x));x.iFirstFlag=TRUE;x.iBufEmpty=TRUE;strcpy(x.sTableName,t);strcpy(x.sCondition,c);}
#define INIT_COMM_STRUCT_OUT(t,x) {bzero((void*)&(x),sizeof(x));strcpy(x.sTableName,t);}
#define INIT_COMM_STRUCT_UP(t,x) {bzero((void*)&(x),sizeof(x));strcpy(x.sTableName,t);}


#endif
