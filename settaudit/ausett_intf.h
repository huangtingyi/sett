#ifndef _AUSETT_INTF_H_
#define _AUSETT_INTF_H_


struct StatCtrlStruct
{
	char sNetType[4];
	char sSettType[4];
	char sCarrType[4];
	char sDealType[4];
	char sMonth[4];
	char sBillingDate[10];
	char sTableNameIn[64];
	char sTableNameOut0[64];	/*支出输出表名*/
	char sTableNameOut1[64];	/*收入输出表名*/
	char sTableNameOther[64];	/*其他 报表项ID 输出表名*/
};

struct AccNbrStruct
{
	struct AccNbrStruct *pNext;
	char sAccNbr[21];
};

struct ReportItemIDStruct
{
	struct ReportItemIDStruct *pNext;
	int iReportItemID;
};

struct ConditionValStruct
{
	struct ConditionValStruct *pNext;
	int iValue;
};

struct ConditionColStruct
{
	struct ConditionColStruct *pNext;
	int	iColumnCtrl;
	char	sColumnName[31];
	char	sColumnValue[61];
};

/*将report_item_param表记录转成此结构体方便查找*/
struct ReportItemConfigExtStruct
{
	struct ReportItemConfigExtStruct *pNext;
	int	iReportItemID;
	char	sFeeType[4];
	char	sSettType[6];
	char	sTicketTypeID[31];
	struct ConditionValStruct	*ptLkTtid;	/*存放sTicketTypeID转换过来的iTicketTypeID*/
	struct ConditionColStruct	*ptLkCondi;
};


int TruncateTableData(char sTableName[]);
int DeleteTableDataByDate(char sTableName[],char sDate[]);
int OutputProcessInfo2LogTable(struct AuSettLogStruct *ptHead,char sTableOut[]);
int WriteState2LogTable(struct StatCtrlStruct *pCtrl,char sDealState[]);
int LoadTableReportItemConfig(char sTableName[],char sSettType[],struct ReportItemConfigExtStruct **pptHead);
int SearchReportItemConfig(struct ReportItemConfigExtStruct *ptHead,struct SttTicketStruct *pValue,
	struct ReportItemConfigExtStruct **pptCur);
	

#endif

