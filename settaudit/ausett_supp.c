
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "ausett_supp.pc"
};


static unsigned int sqlctx = 1208315;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[63];
   unsigned long  sqhstl[63];
            int   sqhsts[63];
            short *sqindv[63];
            int   sqinds[63];
   unsigned long  sqharm[63];
   unsigned long  *sqharc[63];
   unsigned short  sqadto[63];
   unsigned short  sqtdso[63];
} sqlstm = {12,63};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,852,0,0,
5,0,0,1,0,0,17,33,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,39,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,56,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,64,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,
97,0,0,1,0,0,15,84,0,0,0,0,0,1,0,
112,0,0,2,0,0,17,290,0,0,1,1,0,1,0,1,97,0,0,
131,0,0,2,0,0,45,296,0,0,0,0,0,1,0,
146,0,0,2,0,0,15,313,0,0,0,0,0,1,0,
161,0,0,2,0,0,13,321,0,0,63,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
428,0,0,2,0,0,15,397,0,0,0,0,0,1,0,
443,0,0,3,0,0,17,762,0,0,1,1,0,1,0,1,97,0,0,
462,0,0,3,0,0,45,768,0,0,0,0,0,1,0,
477,0,0,3,0,0,15,785,0,0,0,0,0,1,0,
492,0,0,3,0,0,13,793,0,0,6,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,
531,0,0,3,0,0,15,812,0,0,0,0,0,1,0,
546,0,0,4,0,0,17,913,0,0,1,1,0,1,0,1,97,0,0,
565,0,0,4,0,0,21,916,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,
604,0,0,5,0,0,17,971,0,0,1,1,0,1,0,1,97,0,0,
623,0,0,5,0,0,45,977,0,0,0,0,0,1,0,
638,0,0,5,0,0,15,994,0,0,0,0,0,1,0,
653,0,0,5,0,0,13,1002,0,0,19,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
744,0,0,5,0,0,15,1034,0,0,0,0,0,1,0,
759,0,0,6,0,0,17,1235,0,0,1,1,0,1,0,1,97,0,0,
778,0,0,6,0,0,21,1238,0,0,18,18,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,
865,0,0,7,0,0,17,1305,0,0,1,1,0,1,0,1,97,0,0,
884,0,0,7,0,0,45,1311,0,0,0,0,0,1,0,
899,0,0,7,0,0,15,1328,0,0,0,0,0,1,0,
914,0,0,7,0,0,13,1336,0,0,19,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
1005,0,0,7,0,0,15,1368,0,0,0,0,0,1,0,
1020,0,0,8,0,0,17,1519,0,0,1,1,0,1,0,1,97,0,0,
1039,0,0,8,0,0,21,1522,0,0,18,18,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,
1126,0,0,9,0,0,17,1588,0,0,1,1,0,1,0,1,97,0,0,
1145,0,0,9,0,0,45,1594,0,0,0,0,0,1,0,
1160,0,0,9,0,0,15,1611,0,0,0,0,0,1,0,
1175,0,0,9,0,0,13,1619,0,0,19,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
1266,0,0,9,0,0,15,1651,0,0,0,0,0,1,0,
1281,0,0,9,0,0,17,1750,0,0,1,1,0,1,0,1,97,0,0,
1300,0,0,9,0,0,45,1756,0,0,0,0,0,1,0,
1315,0,0,9,0,0,15,1773,0,0,0,0,0,1,0,
1330,0,0,9,0,0,13,1781,0,0,19,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
1421,0,0,9,0,0,15,1813,0,0,0,0,0,1,0,
1436,0,0,10,0,0,17,2010,0,0,1,1,0,1,0,1,97,0,0,
1455,0,0,10,0,0,21,2013,0,0,18,18,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,
1542,0,0,11,0,0,17,2125,0,0,1,1,0,1,0,1,97,0,0,
1561,0,0,11,0,0,21,2128,0,0,18,18,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,
1648,0,0,12,0,0,17,2194,0,0,1,1,0,1,0,1,97,0,0,
1667,0,0,12,0,0,21,2197,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,97,0,0,
1702,0,0,13,0,0,17,2250,0,0,1,1,0,1,0,1,97,0,0,
1721,0,0,13,0,0,21,2253,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,97,0,0,
1756,0,0,14,0,0,17,2306,0,0,1,1,0,1,0,1,97,0,0,
1775,0,0,14,0,0,21,2309,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,97,0,0,
1810,0,0,15,0,0,17,2362,0,0,1,1,0,1,0,1,97,0,0,
1829,0,0,15,0,0,21,2365,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,97,0,0,
};


#include<list.h>
#include<wwdb.h>

#include "ausett_supp.h"
#include "ausett_intf.h"


/*批量数据动态从REPORT_ITEM_CONFIG中用结构缓冲方式取数据*/
int EGetReportItemConfigToStruct(struct ReportItemConfigStruct *p,
	struct ReportItemConfigStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(FEE_TYPE,' '),\n\
				nvl(TICKET_TYPE_ID,' '),\n\
				nvl(COLUMN_NAME,' '),\n\
				nvl(COLUMN_VALUE,' '),\n\
				nvl(COLUMN_CTRL,-1),\n\
				nvl(SETT_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE REPORT_ITEM_CONFIGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError(" PREPARE REPORT_ITEM_CONFIGSCR REPORT_ITEM_CONFIGCR");

		/* EXEC SQL DECLARE REPORT_ITEM_CONFIGCR CURSOR FOR REPORT_ITEM_CONFIGSCR; */ 

		CheckSqlError("Declare REPORT_ITEM_CONFIGCR");

		/* EXEC SQL OPEN REPORT_ITEM_CONFIGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open REPORT_ITEM_CONFIGCR;");


		pSource->iFirstFlag = pSource->iEndFlag = FALSE;
		pSource->iFetchRecNum = pSource->iCurPos = 0;
		pSource->iBufEmpty = TRUE;
	}

	if(pSource->iEndFlag==TRUE&&iCurPos==pSource->iRecCnt){

		pSource->iBufEmpty=TRUE;
		pSource->iCurPos=0;
		pSource->iFetchRecNum=0;
		pSource->iEndFlag=FALSE;
		pSource->iFirstFlag=TRUE;

		/* EXEC SQL CLOSE REPORT_ITEM_CONFIGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )39;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH REPORT_ITEM_CONFIGCR INTO
			:pSource->aiReportItemID,
			:pSource->asFeeType,
			:pSource->asTicketTypeID,
			:pSource->asColumnName,
			:pSource->asColumnValue,
			:pSource->aiColumnCtrl,
			:pSource->asSettType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )54;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asFeeType);
  sqlstm.sqhstl[1] = (unsigned long )3;
  sqlstm.sqhsts[1] = (         int  )3;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asTicketTypeID);
  sqlstm.sqhstl[2] = (unsigned long )31;
  sqlstm.sqhsts[2] = (         int  )31;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asColumnName);
  sqlstm.sqhstl[3] = (unsigned long )31;
  sqlstm.sqhsts[3] = (         int  )31;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asColumnValue);
  sqlstm.sqhstl[4] = (unsigned long )61;
  sqlstm.sqhsts[4] = (         int  )61;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiColumnCtrl);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asSettType);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch REPORT_ITEM_CONFIGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE REPORT_ITEM_CONFIGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 7;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )97;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=REPORT_ITEM_CONFIG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sFeeType,		pSource->asFeeType[iCurPos]);
		strcpy(p->sTicketTypeID,	pSource->asTicketTypeID[iCurPos]);
		strcpy(p->sColumnName,		pSource->asColumnName[iCurPos]);
		strcpy(p->sColumnValue,		pSource->asColumnValue[iCurPos]);

		p->iColumnCtrl=			pSource->aiColumnCtrl[iCurPos];

		strcpy(p->sSettType,		pSource->asSettType[iCurPos]);

		AllTrim(p->sFeeType);
		AllTrim(p->sTicketTypeID);
		AllTrim(p->sColumnName);
		AllTrim(p->sColumnValue);
		AllTrim(p->sSettType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_fmreportitemconfig(struct FReportItemConfigStruct *pi,struct ReportItemConfigStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct ReportItemConfigStruct));

		strncpy(sTemp,	pi->sReportItemID,8);sTemp[8]=0;
		po->iReportItemID=atoi(sTemp);

		strncpy(po->sFeeType,		pi->sFeeType,2);
		strncpy(po->sTicketTypeID,	pi->sTicketTypeID,30);
		strncpy(po->sColumnName,	pi->sColumnName,30);
		strncpy(po->sColumnValue,	pi->sColumnValue,60);

		strncpy(sTemp,	pi->sColumnCtrl,3);sTemp[3]=0;
		po->iColumnCtrl=atoi(sTemp);

		strncpy(po->sSettType,		pi->sSettType,5);

		AllTrim(po->sFeeType);
		AllTrim(po->sTicketTypeID);
		AllTrim(po->sColumnName);
		AllTrim(po->sColumnValue);
		AllTrim(po->sSettType);
}
/**对表REPORT_ITEM_CONFIG的链表释放函数**/
void DestroyReportItemConfig(struct ReportItemConfigStruct *ptHead)
{
	struct ReportItemConfigStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitReportItemConfig(struct ReportItemConfigStruct **pptHead)
{
	int iCnt=0;
	static struct ReportItemConfigStruct *pTemp,*ptHead=NULL;
	struct ReportItemConfigStruct Temp;
	struct ReportItemConfigStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyReportItemConfig(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct ReportItemConfigStructIn));
	sprintf(TempIn.sTableName,"REPORT_ITEM_CONFIG");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetReportItemConfigToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct ReportItemConfigStruct*)
			malloc(sizeof(struct ReportItemConfigStruct)))==NULL){

			DestroyReportItemConfig(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct ReportItemConfigStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表REPORT_ITEM_CONFIG记录数%d",iCnt);
	}

	WriteProcMsg("加载表REPORT_ITEM_CONFIG完毕总记录数%d",iCnt);

	return iCnt;
}



/*批量数据动态从STT_TICKET中用结构缓冲方式取数据*/
int EGetSttTicketToStruct_t(struct SttTicketStruct *p,
	struct SttTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(TICKET_TYPE_ID,0),\n\
				CALL_TYPE,\n\
				nvl(MSISDN,' '),\n\
				nvl(CALLED_CODE,' '),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(ROAM_FEE,0),\n\
				nvl(TOLL_FEE,0),\n\
				nvl(ADD_FEE,0),\n\
				nvl(DURATION,0),\n\
				START_TIME,\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(ROAM_TYPE,' '),\n\
				nvl(DISTANCE_TYPE,' '),\n\
				nvl(OPP_TYPE,' '),\n\
				nvl(USER_TYPE,' '),\n\
				nvl(SPLIT_RULE_ID,' '),\n\
				nvl(OPP_ROAM_TYPE,' '),\n\
				nvl(SERVICE_TYPE,' '),\n\
				nvl(SERVICE_CODE,' '),\n\
				nvl(IMSI,' '),\n\
				nvl(MSC,' '),\n\
				nvl(LAC,' '),\n\
				nvl(CELL_ID,' '),\n\
				nvl(OTHER_LAC,' '),\n\
				nvl(OTHER_CELL_ID,' '),\n\
				nvl(TRUNK_IN,' '),\n\
				nvl(TRUNK_OUT,' '),\n\
				nvl(THIRD_PARTY,' '),\n\
				nvl(MSRN,' '),\n\
				nvl(TRUNK_IN_TYPE_ID,0),\n\
				nvl(TRUNK_OUT_TYPE_ID,0),\n\
				nvl(TRUNK_IN_CARRIER_ID,0),\n\
				nvl(TRUNK_OUT_CARRIER_ID,0),\n\
				nvl(TRUNK_IN_TYPE,' '),\n\
				nvl(TRUNK_OUT_TYPE,' '),\n\
				nvl(CALLING_CARRIER_ID,0),\n\
				nvl(CALLED_CARRIER_ID,0),\n\
				nvl(CALLING_TYPE_ID,0),\n\
				nvl(CALLED_TYPE_ID,0),\n\
				nvl(CALLING_AREA_ID,0),\n\
				nvl(CALLED_AREA_ID,0),\n\
				nvl(A_SETT_AREA_ID,0),\n\
				nvl(B_SETT_AREA_ID,0),\n\
				nvl(SPLIT_TYPE,' '),\n\
				nvl(CAL,' '),\n\
				nvl(ESN,' '),\n\
				nvl(SCP_FLAG,' '),\n\
				nvl(DEFORM_FLAG,' '),\n\
				nvl(RESERVE,' '),\n\
				nvl(BILL_MODE,' '),\n\
				nvl(RESERVE1,' '),\n\
				nvl(ROAM_TARIFF_TYPE,' '),\n\
				nvl(TOLL_TARIFF_TYPE,' '),\n\
				nvl(ADD_TARIFF_TYPE,' '),\n\
				nvl(ERR_CODE,' '),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(MODULE,' '),\n\
				nvl(AREA_CODE,' '),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(UPDATE_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				to_char(nvl(DEAL_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				nvl(SOURCE_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE STT_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )112;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError(" PREPARE STT_TICKETSCR STT_TICKETCR");

		/* EXEC SQL DECLARE STT_TICKETCR CURSOR FOR STT_TICKETSCR; */ 

		CheckSqlError("Declare STT_TICKETCR");

		/* EXEC SQL OPEN STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )131;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open STT_TICKETCR;");


		pSource->iFirstFlag = pSource->iEndFlag = FALSE;
		pSource->iFetchRecNum = pSource->iCurPos = 0;
		pSource->iBufEmpty = TRUE;
	}

	if(pSource->iEndFlag==TRUE&&iCurPos==pSource->iRecCnt){

		pSource->iBufEmpty=TRUE;
		pSource->iCurPos=0;
		pSource->iFetchRecNum=0;
		pSource->iEndFlag=FALSE;
		pSource->iFirstFlag=TRUE;

		/* EXEC SQL CLOSE STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )146;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH STT_TICKETCR INTO
			:pSource->aiTicketTypeID,
			:pSource->asCallType,
			:pSource->asMsisdn,
			:pSource->asCalledCode,
			:pSource->asOtherParty,
			:pSource->asVisitAreaCode,
			:pSource->aiRoamFee,
			:pSource->aiTollFee,
			:pSource->aiAddFee,
			:pSource->aiDuration,
			:pSource->asStartTime,
			:pSource->asHomeAreaCode,
			:pSource->asRoamType,
			:pSource->asDistanceType,
			:pSource->asOppType,
			:pSource->asUserType,
			:pSource->asSplitRuleID,
			:pSource->asOppRoamType,
			:pSource->asServiceType,
			:pSource->asServiceCode,
			:pSource->asImsi,
			:pSource->asMsc,
			:pSource->asLac,
			:pSource->asCellID,
			:pSource->asOtherLac,
			:pSource->asOtherCellID,
			:pSource->asTrunkIn,
			:pSource->asTrunkOut,
			:pSource->asThirdParty,
			:pSource->asMsrn,
			:pSource->aiTrunkInTypeID,
			:pSource->aiTrunkOutTypeID,
			:pSource->aiTrunkInCarrierID,
			:pSource->aiTrunkOutCarrierID,
			:pSource->asTrunkInType,
			:pSource->asTrunkOutType,
			:pSource->aiCallingCarrierID,
			:pSource->aiCalledCarrierID,
			:pSource->aiCallingTypeID,
			:pSource->aiCalledTypeID,
			:pSource->aiCallingAreaID,
			:pSource->aiCalledAreaID,
			:pSource->aiASettAreaID,
			:pSource->aiBSettAreaID,
			:pSource->asSplitType,
			:pSource->asCal,
			:pSource->asEsn,
			:pSource->asScpFlag,
			:pSource->asDeformFlag,
			:pSource->asReserve,
			:pSource->asBillMode,
			:pSource->asReserve1,
			:pSource->asRoamTariffType,
			:pSource->asTollTariffType,
			:pSource->asAddTariffType,
			:pSource->asErrCode,
			:pSource->asFileName,
			:pSource->asModule,
			:pSource->asAreaCode,
			:pSource->asState,
			:pSource->asUpdateDate,
			:pSource->asDealDate,
			:pSource->asSourceID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )161;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTicketTypeID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[1] = (unsigned long )3;
  sqlstm.sqhsts[1] = (         int  )3;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[2] = (unsigned long )16;
  sqlstm.sqhsts[2] = (         int  )16;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCalledCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[4] = (unsigned long )25;
  sqlstm.sqhsts[4] = (         int  )25;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )6;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiRoamFee);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiTollFee);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiAddFee);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )6;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asRoamType);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asDistanceType);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asOppType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asUserType);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asSplitRuleID);
  sqlstm.sqhstl[16] = (unsigned long )5;
  sqlstm.sqhsts[16] = (         int  )5;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asOppRoamType);
  sqlstm.sqhstl[17] = (unsigned long )2;
  sqlstm.sqhsts[17] = (         int  )2;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asServiceType);
  sqlstm.sqhstl[18] = (unsigned long )4;
  sqlstm.sqhsts[18] = (         int  )4;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asServiceCode);
  sqlstm.sqhstl[19] = (unsigned long )5;
  sqlstm.sqhsts[19] = (         int  )5;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asImsi);
  sqlstm.sqhstl[20] = (unsigned long )16;
  sqlstm.sqhsts[20] = (         int  )16;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[21] = (unsigned long )16;
  sqlstm.sqhsts[21] = (         int  )16;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asLac);
  sqlstm.sqhstl[22] = (unsigned long )6;
  sqlstm.sqhsts[22] = (         int  )6;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asCellID);
  sqlstm.sqhstl[23] = (unsigned long )6;
  sqlstm.sqhsts[23] = (         int  )6;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asOtherLac);
  sqlstm.sqhstl[24] = (unsigned long )6;
  sqlstm.sqhsts[24] = (         int  )6;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asOtherCellID);
  sqlstm.sqhstl[25] = (unsigned long )6;
  sqlstm.sqhsts[25] = (         int  )6;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->asTrunkIn);
  sqlstm.sqhstl[26] = (unsigned long )8;
  sqlstm.sqhsts[26] = (         int  )8;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asTrunkOut);
  sqlstm.sqhstl[27] = (unsigned long )8;
  sqlstm.sqhsts[27] = (         int  )8;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->asThirdParty);
  sqlstm.sqhstl[28] = (unsigned long )16;
  sqlstm.sqhsts[28] = (         int  )16;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pSource->asMsrn);
  sqlstm.sqhstl[29] = (unsigned long )13;
  sqlstm.sqhsts[29] = (         int  )13;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pSource->aiTrunkInTypeID);
  sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[30] = (         int  )sizeof(int);
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pSource->aiTrunkOutTypeID);
  sqlstm.sqhstl[31] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[31] = (         int  )sizeof(int);
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pSource->aiTrunkInCarrierID);
  sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[32] = (         int  )sizeof(int);
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pSource->aiTrunkOutCarrierID);
  sqlstm.sqhstl[33] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[33] = (         int  )sizeof(int);
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pSource->asTrunkInType);
  sqlstm.sqhstl[34] = (unsigned long )2;
  sqlstm.sqhsts[34] = (         int  )2;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pSource->asTrunkOutType);
  sqlstm.sqhstl[35] = (unsigned long )2;
  sqlstm.sqhsts[35] = (         int  )2;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pSource->aiCallingCarrierID);
  sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[36] = (         int  )sizeof(int);
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pSource->aiCalledCarrierID);
  sqlstm.sqhstl[37] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[37] = (         int  )sizeof(int);
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pSource->aiCallingTypeID);
  sqlstm.sqhstl[38] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[38] = (         int  )sizeof(int);
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pSource->aiCalledTypeID);
  sqlstm.sqhstl[39] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[39] = (         int  )sizeof(int);
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pSource->aiCallingAreaID);
  sqlstm.sqhstl[40] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[40] = (         int  )sizeof(int);
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pSource->aiCalledAreaID);
  sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[41] = (         int  )sizeof(int);
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pSource->aiASettAreaID);
  sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[42] = (         int  )sizeof(int);
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqharc[42] = (unsigned long  *)0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)(pSource->aiBSettAreaID);
  sqlstm.sqhstl[43] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[43] = (         int  )sizeof(int);
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqharc[43] = (unsigned long  *)0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
  sqlstm.sqhstv[44] = (unsigned char  *)(pSource->asSplitType);
  sqlstm.sqhstl[44] = (unsigned long )2;
  sqlstm.sqhsts[44] = (         int  )2;
  sqlstm.sqindv[44] = (         short *)0;
  sqlstm.sqinds[44] = (         int  )0;
  sqlstm.sqharm[44] = (unsigned long )0;
  sqlstm.sqharc[44] = (unsigned long  *)0;
  sqlstm.sqadto[44] = (unsigned short )0;
  sqlstm.sqtdso[44] = (unsigned short )0;
  sqlstm.sqhstv[45] = (unsigned char  *)(pSource->asCal);
  sqlstm.sqhstl[45] = (unsigned long )2;
  sqlstm.sqhsts[45] = (         int  )2;
  sqlstm.sqindv[45] = (         short *)0;
  sqlstm.sqinds[45] = (         int  )0;
  sqlstm.sqharm[45] = (unsigned long )0;
  sqlstm.sqharc[45] = (unsigned long  *)0;
  sqlstm.sqadto[45] = (unsigned short )0;
  sqlstm.sqtdso[45] = (unsigned short )0;
  sqlstm.sqhstv[46] = (unsigned char  *)(pSource->asEsn);
  sqlstm.sqhstl[46] = (unsigned long )16;
  sqlstm.sqhsts[46] = (         int  )16;
  sqlstm.sqindv[46] = (         short *)0;
  sqlstm.sqinds[46] = (         int  )0;
  sqlstm.sqharm[46] = (unsigned long )0;
  sqlstm.sqharc[46] = (unsigned long  *)0;
  sqlstm.sqadto[46] = (unsigned short )0;
  sqlstm.sqtdso[46] = (unsigned short )0;
  sqlstm.sqhstv[47] = (unsigned char  *)(pSource->asScpFlag);
  sqlstm.sqhstl[47] = (unsigned long )2;
  sqlstm.sqhsts[47] = (         int  )2;
  sqlstm.sqindv[47] = (         short *)0;
  sqlstm.sqinds[47] = (         int  )0;
  sqlstm.sqharm[47] = (unsigned long )0;
  sqlstm.sqharc[47] = (unsigned long  *)0;
  sqlstm.sqadto[47] = (unsigned short )0;
  sqlstm.sqtdso[47] = (unsigned short )0;
  sqlstm.sqhstv[48] = (unsigned char  *)(pSource->asDeformFlag);
  sqlstm.sqhstl[48] = (unsigned long )2;
  sqlstm.sqhsts[48] = (         int  )2;
  sqlstm.sqindv[48] = (         short *)0;
  sqlstm.sqinds[48] = (         int  )0;
  sqlstm.sqharm[48] = (unsigned long )0;
  sqlstm.sqharc[48] = (unsigned long  *)0;
  sqlstm.sqadto[48] = (unsigned short )0;
  sqlstm.sqtdso[48] = (unsigned short )0;
  sqlstm.sqhstv[49] = (unsigned char  *)(pSource->asReserve);
  sqlstm.sqhstl[49] = (unsigned long )9;
  sqlstm.sqhsts[49] = (         int  )9;
  sqlstm.sqindv[49] = (         short *)0;
  sqlstm.sqinds[49] = (         int  )0;
  sqlstm.sqharm[49] = (unsigned long )0;
  sqlstm.sqharc[49] = (unsigned long  *)0;
  sqlstm.sqadto[49] = (unsigned short )0;
  sqlstm.sqtdso[49] = (unsigned short )0;
  sqlstm.sqhstv[50] = (unsigned char  *)(pSource->asBillMode);
  sqlstm.sqhstl[50] = (unsigned long )4;
  sqlstm.sqhsts[50] = (         int  )4;
  sqlstm.sqindv[50] = (         short *)0;
  sqlstm.sqinds[50] = (         int  )0;
  sqlstm.sqharm[50] = (unsigned long )0;
  sqlstm.sqharc[50] = (unsigned long  *)0;
  sqlstm.sqadto[50] = (unsigned short )0;
  sqlstm.sqtdso[50] = (unsigned short )0;
  sqlstm.sqhstv[51] = (unsigned char  *)(pSource->asReserve1);
  sqlstm.sqhstl[51] = (unsigned long )3;
  sqlstm.sqhsts[51] = (         int  )3;
  sqlstm.sqindv[51] = (         short *)0;
  sqlstm.sqinds[51] = (         int  )0;
  sqlstm.sqharm[51] = (unsigned long )0;
  sqlstm.sqharc[51] = (unsigned long  *)0;
  sqlstm.sqadto[51] = (unsigned short )0;
  sqlstm.sqtdso[51] = (unsigned short )0;
  sqlstm.sqhstv[52] = (unsigned char  *)(pSource->asRoamTariffType);
  sqlstm.sqhstl[52] = (unsigned long )4;
  sqlstm.sqhsts[52] = (         int  )4;
  sqlstm.sqindv[52] = (         short *)0;
  sqlstm.sqinds[52] = (         int  )0;
  sqlstm.sqharm[52] = (unsigned long )0;
  sqlstm.sqharc[52] = (unsigned long  *)0;
  sqlstm.sqadto[52] = (unsigned short )0;
  sqlstm.sqtdso[52] = (unsigned short )0;
  sqlstm.sqhstv[53] = (unsigned char  *)(pSource->asTollTariffType);
  sqlstm.sqhstl[53] = (unsigned long )4;
  sqlstm.sqhsts[53] = (         int  )4;
  sqlstm.sqindv[53] = (         short *)0;
  sqlstm.sqinds[53] = (         int  )0;
  sqlstm.sqharm[53] = (unsigned long )0;
  sqlstm.sqharc[53] = (unsigned long  *)0;
  sqlstm.sqadto[53] = (unsigned short )0;
  sqlstm.sqtdso[53] = (unsigned short )0;
  sqlstm.sqhstv[54] = (unsigned char  *)(pSource->asAddTariffType);
  sqlstm.sqhstl[54] = (unsigned long )4;
  sqlstm.sqhsts[54] = (         int  )4;
  sqlstm.sqindv[54] = (         short *)0;
  sqlstm.sqinds[54] = (         int  )0;
  sqlstm.sqharm[54] = (unsigned long )0;
  sqlstm.sqharc[54] = (unsigned long  *)0;
  sqlstm.sqadto[54] = (unsigned short )0;
  sqlstm.sqtdso[54] = (unsigned short )0;
  sqlstm.sqhstv[55] = (unsigned char  *)(pSource->asErrCode);
  sqlstm.sqhstl[55] = (unsigned long )5;
  sqlstm.sqhsts[55] = (         int  )5;
  sqlstm.sqindv[55] = (         short *)0;
  sqlstm.sqinds[55] = (         int  )0;
  sqlstm.sqharm[55] = (unsigned long )0;
  sqlstm.sqharc[55] = (unsigned long  *)0;
  sqlstm.sqadto[55] = (unsigned short )0;
  sqlstm.sqtdso[55] = (unsigned short )0;
  sqlstm.sqhstv[56] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[56] = (unsigned long )20;
  sqlstm.sqhsts[56] = (         int  )20;
  sqlstm.sqindv[56] = (         short *)0;
  sqlstm.sqinds[56] = (         int  )0;
  sqlstm.sqharm[56] = (unsigned long )0;
  sqlstm.sqharc[56] = (unsigned long  *)0;
  sqlstm.sqadto[56] = (unsigned short )0;
  sqlstm.sqtdso[56] = (unsigned short )0;
  sqlstm.sqhstv[57] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[57] = (unsigned long )4;
  sqlstm.sqhsts[57] = (         int  )4;
  sqlstm.sqindv[57] = (         short *)0;
  sqlstm.sqinds[57] = (         int  )0;
  sqlstm.sqharm[57] = (unsigned long )0;
  sqlstm.sqharc[57] = (unsigned long  *)0;
  sqlstm.sqadto[57] = (unsigned short )0;
  sqlstm.sqtdso[57] = (unsigned short )0;
  sqlstm.sqhstv[58] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[58] = (unsigned long )6;
  sqlstm.sqhsts[58] = (         int  )6;
  sqlstm.sqindv[58] = (         short *)0;
  sqlstm.sqinds[58] = (         int  )0;
  sqlstm.sqharm[58] = (unsigned long )0;
  sqlstm.sqharc[58] = (unsigned long  *)0;
  sqlstm.sqadto[58] = (unsigned short )0;
  sqlstm.sqtdso[58] = (unsigned short )0;
  sqlstm.sqhstv[59] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[59] = (unsigned long )2;
  sqlstm.sqhsts[59] = (         int  )2;
  sqlstm.sqindv[59] = (         short *)0;
  sqlstm.sqinds[59] = (         int  )0;
  sqlstm.sqharm[59] = (unsigned long )0;
  sqlstm.sqharc[59] = (unsigned long  *)0;
  sqlstm.sqadto[59] = (unsigned short )0;
  sqlstm.sqtdso[59] = (unsigned short )0;
  sqlstm.sqhstv[60] = (unsigned char  *)(pSource->asUpdateDate);
  sqlstm.sqhstl[60] = (unsigned long )15;
  sqlstm.sqhsts[60] = (         int  )15;
  sqlstm.sqindv[60] = (         short *)0;
  sqlstm.sqinds[60] = (         int  )0;
  sqlstm.sqharm[60] = (unsigned long )0;
  sqlstm.sqharc[60] = (unsigned long  *)0;
  sqlstm.sqadto[60] = (unsigned short )0;
  sqlstm.sqtdso[60] = (unsigned short )0;
  sqlstm.sqhstv[61] = (unsigned char  *)(pSource->asDealDate);
  sqlstm.sqhstl[61] = (unsigned long )15;
  sqlstm.sqhsts[61] = (         int  )15;
  sqlstm.sqindv[61] = (         short *)0;
  sqlstm.sqinds[61] = (         int  )0;
  sqlstm.sqharm[61] = (unsigned long )0;
  sqlstm.sqharc[61] = (unsigned long  *)0;
  sqlstm.sqadto[61] = (unsigned short )0;
  sqlstm.sqtdso[61] = (unsigned short )0;
  sqlstm.sqhstv[62] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[62] = (unsigned long )41;
  sqlstm.sqhsts[62] = (         int  )41;
  sqlstm.sqindv[62] = (         short *)0;
  sqlstm.sqinds[62] = (         int  )0;
  sqlstm.sqharm[62] = (unsigned long )0;
  sqlstm.sqharc[62] = (unsigned long  *)0;
  sqlstm.sqadto[62] = (unsigned short )0;
  sqlstm.sqtdso[62] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch STT_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE STT_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 63;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )428;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=STT_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTicketTypeID=		pSource->aiTicketTypeID[iCurPos];

		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sCalledCode,		pSource->asCalledCode[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);

		p->iRoamFee=			pSource->aiRoamFee[iCurPos];
		p->iTollFee=			pSource->aiTollFee[iCurPos];
		p->iAddFee=			pSource->aiAddFee[iCurPos];
		p->iDuration=			pSource->aiDuration[iCurPos];

		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sRoamType,		pSource->asRoamType[iCurPos]);
		strcpy(p->sDistanceType,	pSource->asDistanceType[iCurPos]);
		strcpy(p->sOppType,		pSource->asOppType[iCurPos]);
		strcpy(p->sUserType,		pSource->asUserType[iCurPos]);
		strcpy(p->sSplitRuleID,		pSource->asSplitRuleID[iCurPos]);
		strcpy(p->sOppRoamType,		pSource->asOppRoamType[iCurPos]);
		strcpy(p->sServiceType,		pSource->asServiceType[iCurPos]);
		strcpy(p->sServiceCode,		pSource->asServiceCode[iCurPos]);
		strcpy(p->sImsi,		pSource->asImsi[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sLac,			pSource->asLac[iCurPos]);
		strcpy(p->sCellID,		pSource->asCellID[iCurPos]);
		strcpy(p->sOtherLac,		pSource->asOtherLac[iCurPos]);
		strcpy(p->sOtherCellID,		pSource->asOtherCellID[iCurPos]);
		strcpy(p->sTrunkIn,		pSource->asTrunkIn[iCurPos]);
		strcpy(p->sTrunkOut,		pSource->asTrunkOut[iCurPos]);
		strcpy(p->sThirdParty,		pSource->asThirdParty[iCurPos]);
		strcpy(p->sMsrn,		pSource->asMsrn[iCurPos]);

		p->iTrunkInTypeID=		pSource->aiTrunkInTypeID[iCurPos];
		p->iTrunkOutTypeID=		pSource->aiTrunkOutTypeID[iCurPos];
		p->iTrunkInCarrierID=		pSource->aiTrunkInCarrierID[iCurPos];
		p->iTrunkOutCarrierID=		pSource->aiTrunkOutCarrierID[iCurPos];

		strcpy(p->sTrunkInType,		pSource->asTrunkInType[iCurPos]);
		strcpy(p->sTrunkOutType,	pSource->asTrunkOutType[iCurPos]);

		p->iCallingCarrierID=		pSource->aiCallingCarrierID[iCurPos];
		p->iCalledCarrierID=		pSource->aiCalledCarrierID[iCurPos];
		p->iCallingTypeID=		pSource->aiCallingTypeID[iCurPos];
		p->iCalledTypeID=		pSource->aiCalledTypeID[iCurPos];
		p->iCallingAreaID=		pSource->aiCallingAreaID[iCurPos];
		p->iCalledAreaID=		pSource->aiCalledAreaID[iCurPos];
		p->iASettAreaID=		pSource->aiASettAreaID[iCurPos];
		p->iBSettAreaID=		pSource->aiBSettAreaID[iCurPos];

		strcpy(p->sSplitType,		pSource->asSplitType[iCurPos]);
		strcpy(p->sCal,			pSource->asCal[iCurPos]);
		strcpy(p->sEsn,			pSource->asEsn[iCurPos]);
		strcpy(p->sScpFlag,		pSource->asScpFlag[iCurPos]);
		strcpy(p->sDeformFlag,		pSource->asDeformFlag[iCurPos]);
		strcpy(p->sReserve,		pSource->asReserve[iCurPos]);
		strcpy(p->sBillMode,		pSource->asBillMode[iCurPos]);
		strcpy(p->sReserve1,		pSource->asReserve1[iCurPos]);
		strcpy(p->sRoamTariffType,	pSource->asRoamTariffType[iCurPos]);
		strcpy(p->sTollTariffType,	pSource->asTollTariffType[iCurPos]);
		strcpy(p->sAddTariffType,	pSource->asAddTariffType[iCurPos]);
		strcpy(p->sErrCode,		pSource->asErrCode[iCurPos]);
		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sModule,		pSource->asModule[iCurPos]);
		strcpy(p->sAreaCode,		pSource->asAreaCode[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sUpdateDate,		pSource->asUpdateDate[iCurPos]);
		strcpy(p->sDealDate,		pSource->asDealDate[iCurPos]);
		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);

		AllTrim(p->sCallType);
		AllTrim(p->sMsisdn);
		AllTrim(p->sCalledCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sStartTime);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sRoamType);
		AllTrim(p->sDistanceType);
		AllTrim(p->sOppType);
		AllTrim(p->sUserType);
		AllTrim(p->sSplitRuleID);
		AllTrim(p->sOppRoamType);
		AllTrim(p->sServiceType);
		AllTrim(p->sServiceCode);
		AllTrim(p->sImsi);
		AllTrim(p->sMsc);
		AllTrim(p->sLac);
		AllTrim(p->sCellID);
		AllTrim(p->sOtherLac);
		AllTrim(p->sOtherCellID);
		AllTrim(p->sTrunkIn);
		AllTrim(p->sTrunkOut);
		AllTrim(p->sThirdParty);
		AllTrim(p->sMsrn);
		AllTrim(p->sTrunkInType);
		AllTrim(p->sTrunkOutType);
		AllTrim(p->sSplitType);
		AllTrim(p->sCal);
		AllTrim(p->sEsn);
		AllTrim(p->sScpFlag);
		AllTrim(p->sDeformFlag);
		AllTrim(p->sReserve);
		AllTrim(p->sBillMode);
		AllTrim(p->sReserve1);
		AllTrim(p->sRoamTariffType);
		AllTrim(p->sTollTariffType);
		AllTrim(p->sAddTariffType);
		AllTrim(p->sErrCode);
		AllTrim(p->sFileName);
		AllTrim(p->sModule);
		AllTrim(p->sAreaCode);
		AllTrim(p->sState);
		AllTrim(p->sUpdateDate);
		AllTrim(p->sDealDate);
		AllTrim(p->sSourceID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_fmsttticket(struct FSttTicketStruct *pi,struct SttTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SttTicketStruct));

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);

		strncpy(sTemp,		pi->sRoamFee,5);sTemp[5]=0;
		po->iRoamFee=atoi(sTemp);
		strncpy(sTemp,		pi->sTollFee,7);sTemp[7]=0;
		po->iTollFee=atoi(sTemp);
		strncpy(sTemp,		pi->sAddFee,5);sTemp[5]=0;
		po->iAddFee=atoi(sTemp);
		strncpy(sTemp,		pi->sDuration,6);sTemp[6]=0;
		po->iDuration=atoi(sTemp);

		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sRoamType,		pi->sRoamType,1);
		strncpy(po->sDistanceType,	pi->sDistanceType,1);
		strncpy(po->sOppType,		pi->sOppType,1);
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sSplitRuleID,	pi->sSplitRuleID,4);
		strncpy(po->sOppRoamType,	pi->sOppRoamType,1);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellID,		pi->sCellID,5);
		strncpy(po->sOtherLac,		pi->sOtherLac,5);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,5);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,7);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,7);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sMsrn,		pi->sMsrn,12);

		strncpy(sTemp,	pi->sTrunkInTypeID,4);sTemp[4]=0;
		po->iTrunkInTypeID=atoi(sTemp);
		strncpy(sTemp,	pi->sTrunkOutTypeID,4);sTemp[4]=0;
		po->iTrunkOutTypeID=atoi(sTemp);
		strncpy(sTemp,	pi->sTrunkInCarrierID,4);sTemp[4]=0;
		po->iTrunkInCarrierID=atoi(sTemp);
		strncpy(sTemp,	pi->sTrunkOutCarrierID,4);sTemp[4]=0;
		po->iTrunkOutCarrierID=atoi(sTemp);

		strncpy(po->sTrunkInType,	pi->sTrunkInType,1);
		strncpy(po->sTrunkOutType,	pi->sTrunkOutType,1);

		strncpy(sTemp,	pi->sCallingCarrierID,4);sTemp[4]=0;
		po->iCallingCarrierID=atoi(sTemp);
		strncpy(sTemp,	pi->sCalledCarrierID,4);sTemp[4]=0;
		po->iCalledCarrierID=atoi(sTemp);
		strncpy(sTemp,	pi->sCallingTypeID,4);sTemp[4]=0;
		po->iCallingTypeID=atoi(sTemp);
		strncpy(sTemp,	pi->sCalledTypeID,4);sTemp[4]=0;
		po->iCalledTypeID=atoi(sTemp);
		strncpy(sTemp,	pi->sCallingAreaID,4);sTemp[4]=0;
		po->iCallingAreaID=atoi(sTemp);
		strncpy(sTemp,	pi->sCalledAreaID,4);sTemp[4]=0;
		po->iCalledAreaID=atoi(sTemp);
		strncpy(sTemp,	pi->sASettAreaID,4);sTemp[4]=0;
		po->iASettAreaID=atoi(sTemp);
		strncpy(sTemp,	pi->sBSettAreaID,4);sTemp[4]=0;
		po->iBSettAreaID=atoi(sTemp);

		strncpy(po->sSplitType,		pi->sSplitType,1);
		strncpy(po->sCal,		pi->sCal,1);
		strncpy(po->sEsn,		pi->sEsn,15);
		strncpy(po->sScpFlag,		pi->sScpFlag,1);
		strncpy(po->sDeformFlag,	pi->sDeformFlag,1);
		strncpy(po->sReserve,		pi->sReserve,8);
		strncpy(po->sBillMode,		pi->sBillMode,3);
		strncpy(po->sReserve1,		pi->sReserve1,2);
		strncpy(po->sRoamTariffType,	pi->sRoamTariffType,3);
		strncpy(po->sTollTariffType,	pi->sTollTariffType,3);
		strncpy(po->sAddTariffType,	pi->sAddTariffType,3);
		strncpy(po->sErrCode,		pi->sErrCode,4);
		strncpy(po->sFileName,		pi->sFileName,19);
		strncpy(po->sModule,		pi->sModule,3);
		strncpy(po->sAreaCode,		pi->sAreaCode,5);
		strncpy(po->sState,		pi->sState,1);
		strncpy(po->sUpdateDate,	pi->sUpdateDate,14);
		strncpy(po->sDealDate,		pi->sDealDate,14);
		strncpy(po->sSourceID,		pi->sSourceID,40);

		AllTrim(po->sCallType);
		AllTrim(po->sMsisdn);
		AllTrim(po->sCalledCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sStartTime);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sRoamType);
		AllTrim(po->sDistanceType);
		AllTrim(po->sOppType);
		AllTrim(po->sUserType);
		AllTrim(po->sSplitRuleID);
		AllTrim(po->sOppRoamType);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sImsi);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sTrunkInType);
		AllTrim(po->sTrunkOutType);
		AllTrim(po->sSplitType);
		AllTrim(po->sCal);
		AllTrim(po->sEsn);
		AllTrim(po->sScpFlag);
		AllTrim(po->sDeformFlag);
		AllTrim(po->sReserve);
		AllTrim(po->sBillMode);
		AllTrim(po->sReserve1);
		AllTrim(po->sRoamTariffType);
		AllTrim(po->sTollTariffType);
		AllTrim(po->sAddTariffType);
		AllTrim(po->sErrCode);
		AllTrim(po->sFileName);
		AllTrim(po->sModule);
		AllTrim(po->sAreaCode);
		AllTrim(po->sState);
		AllTrim(po->sUpdateDate);
		AllTrim(po->sDealDate);
		AllTrim(po->sSourceID);
}
/**对表STT_TICKET的链表释放函数**/
void DestroySttTicket(struct SttTicketStruct *ptHead)
{
	struct SttTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSttTicket(struct SttTicketStruct **pptHead)
{
	int iCnt=0;
	static struct SttTicketStruct *pTemp,*ptHead=NULL;
	struct SttTicketStruct Temp;
	struct SttTicketStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySttTicket(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));
	sprintf(TempIn.sTableName,"STT_TICKET");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSttTicketToStruct_t(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SttTicketStruct*)
			malloc(sizeof(struct SttTicketStruct)))==NULL){

			DestroySttTicket(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SttTicketStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表STT_TICKET记录数%d",iCnt);
	}

	WriteProcMsg("加载表STT_TICKET完毕总记录数%d",iCnt);

	return iCnt;
}


/*批量数据动态从AU_SETT_LOG中用结构缓冲方式取数据*/
int EGetAuSettLogToStruct(struct AuSettLogStruct *p,
	struct AuSettLogStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(DEAL_TABLE,' '),\n\
				nvl(OUT_TABLE_IN,' '),\n\
				nvl(OUT_TABLE_OUT,' '),\n\
				to_char(nvl(DATA_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				to_char(nvl(DEAL_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				nvl(DEAL_STATE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AU_SETT_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )443;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError(" PREPARE AU_SETT_LOGSCR AU_SETT_LOGCR");

		/* EXEC SQL DECLARE AU_SETT_LOGCR CURSOR FOR AU_SETT_LOGSCR; */ 

		CheckSqlError("Declare AU_SETT_LOGCR");

		/* EXEC SQL OPEN AU_SETT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )462;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AU_SETT_LOGCR;");


		pSource->iFirstFlag = pSource->iEndFlag = FALSE;
		pSource->iFetchRecNum = pSource->iCurPos = 0;
		pSource->iBufEmpty = TRUE;
	}

	if(pSource->iEndFlag==TRUE&&iCurPos==pSource->iRecCnt){

		pSource->iBufEmpty=TRUE;
		pSource->iCurPos=0;
		pSource->iFetchRecNum=0;
		pSource->iEndFlag=FALSE;
		pSource->iFirstFlag=TRUE;

		/* EXEC SQL CLOSE AU_SETT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )477;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH AU_SETT_LOGCR INTO
			:pSource->asDealTable,
			:pSource->asOutTableIn,
			:pSource->asOutTableOut,
			:pSource->asDataDate,
			:pSource->asDealDate,
			:pSource->asDealState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )492;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asDealTable);
  sqlstm.sqhstl[0] = (unsigned long )41;
  sqlstm.sqhsts[0] = (         int  )41;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asOutTableIn);
  sqlstm.sqhstl[1] = (unsigned long )41;
  sqlstm.sqhsts[1] = (         int  )41;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asOutTableOut);
  sqlstm.sqhstl[2] = (unsigned long )41;
  sqlstm.sqhsts[2] = (         int  )41;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asDataDate);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )15;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asDealDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asDealState);
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )4;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch AU_SETT_LOGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AU_SETT_LOGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 63;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )531;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AU_SETT_LOG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sDealTable,	pSource->asDealTable[iCurPos]);
		strcpy(p->sOutTableIn,	pSource->asOutTableIn[iCurPos]);
		strcpy(p->sOutTableOut,	pSource->asOutTableOut[iCurPos]);
		strcpy(p->sDataDate,	pSource->asDataDate[iCurPos]);
		strcpy(p->sDealDate,	pSource->asDealDate[iCurPos]);
		strcpy(p->sDealState,	pSource->asDealState[iCurPos]);

		AllTrim(p->sDealTable);
		AllTrim(p->sOutTableIn);
		AllTrim(p->sOutTableOut);
		AllTrim(p->sDataDate);
		AllTrim(p->sDealDate);
		AllTrim(p->sDealState);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_fmausettlog(struct FAuSettLogStruct *pi,struct AuSettLogStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct AuSettLogStruct));

		strncpy(po->sDealTable,		pi->sDealTable,40);
		strncpy(po->sOutTableIn,	pi->sOutTableIn,40);
		strncpy(po->sOutTableOut,	pi->sOutTableOut,40);
		strncpy(po->sDataDate,		pi->sDataDate,14);
		strncpy(po->sDealDate,		pi->sDealDate,14);
		strncpy(po->sDealState,		pi->sDealState,3);

		AllTrim(po->sDealTable);
		AllTrim(po->sOutTableIn);
		AllTrim(po->sOutTableOut);
		AllTrim(po->sDataDate);
		AllTrim(po->sDealDate);
		AllTrim(po->sDealState);
}
/*批量数据结构缓冲写入AU_SETT_LOG*/
int EInsertStructToAuSettLog(struct AuSettLogStruct *p,
	int iInsertFlag,struct AuSettLogStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asDealTable[iCurPos],	p->sDealTable);
		strcpy(pTarget->asOutTableIn[iCurPos],	p->sOutTableIn);
		strcpy(pTarget->asOutTableOut[iCurPos],	p->sOutTableOut);
		strcpy(pTarget->asDataDate[iCurPos],	p->sDataDate);
		strcpy(pTarget->asDealDate[iCurPos],	p->sDealDate);
		strcpy(pTarget->asDealState[iCurPos],	p->sDealState);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AU_SETT_LOG_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				DEAL_TABLE,\n\
				OUT_TABLE_IN,\n\
				OUT_TABLE_OUT,\n\
				DATA_DATE,\n\
				DEAL_DATE,\n\
				DEAL_STATE)\n\
			VALUES (\n\
				:asDealTable,\n\
				:asOutTableIn,\n\
				:asOutTableOut,\n\
				to_date(:asDataDate,'yyyymmddhh24miss'),\n\
				to_date(:asDealDate,'yyyymmddhh24miss'),\n\
				:asDealState\n\
			)",sTableName);

		/* EXEC SQL PREPARE AU_SETT_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )546;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare insert statement AU_SETT_LOG")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AU_SETT_LOGTRG USING
				:pTarget->asDealTable,
				:pTarget->asOutTableIn,
				:pTarget->asOutTableOut,
				:pTarget->asDataDate,
				:pTarget->asDealDate,
				:pTarget->asDealState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )565;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asDealTable);
  sqlstm.sqhstl[0] = (unsigned long )41;
  sqlstm.sqhsts[0] = (         int  )41;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asOutTableIn);
  sqlstm.sqhstl[1] = (unsigned long )41;
  sqlstm.sqhsts[1] = (         int  )41;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asOutTableOut);
  sqlstm.sqhstl[2] = (unsigned long )41;
  sqlstm.sqhsts[2] = (         int  )41;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asDataDate);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )15;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asDealDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asDealState);
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )4;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn insert into AU_SETT_LOG")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*批量数据动态从AU_SETT_NBR_IN_STAT中用结构缓冲方式取数据*/
int EGetAuSettNbrInStatToStruct(struct AuSettNbrStatStruct *p,
	struct AuSettNbrStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(ACC_NBR,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(CALLED_CODE,' '),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(SETT_TYPE,' '),\n\
				nvl(SETT_NBR_TYPE,' '),\n\
				nvl(SETT_CARR_ID,' '),\n\
				nvl(MSC,' '),\n\
				nvl(TRUNK_IN,' '),\n\
				nvl(TRUNK_OUT,' '),\n\
				nvl(TRUNK_IN_CARRIER_ID,' '),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				nvl(CNT,0),\n\
				nvl(SETT_MIN,0),\n\
				nvl(IN_FEE,0),\n\
				nvl(DURATION,0),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AU_SETT_NBR_IN_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )604;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError(" PREPARE AU_SETT_NBR_IN_STATSCR AU_SETT_NBR_IN_STATCR");

		/* EXEC SQL DECLARE AU_SETT_NBR_IN_STATCR CURSOR FOR AU_SETT_NBR_IN_STATSCR; */ 

		CheckSqlError("Declare AU_SETT_NBR_IN_STATCR");

		/* EXEC SQL OPEN AU_SETT_NBR_IN_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )623;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AU_SETT_NBR_IN_STATCR;");


		pSource->iFirstFlag = pSource->iEndFlag = FALSE;
		pSource->iFetchRecNum = pSource->iCurPos = 0;
		pSource->iBufEmpty = TRUE;
	}

	if(pSource->iEndFlag==TRUE&&iCurPos==pSource->iRecCnt){

		pSource->iBufEmpty=TRUE;
		pSource->iCurPos=0;
		pSource->iFetchRecNum=0;
		pSource->iEndFlag=FALSE;
		pSource->iFirstFlag=TRUE;

		/* EXEC SQL CLOSE AU_SETT_NBR_IN_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )638;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH AU_SETT_NBR_IN_STATCR INTO
			:pSource->asAccNbr,
			:pSource->asHomeAreaCode,
			:pSource->asVisitAreaCode,
			:pSource->asCalledCode,
			:pSource->asNetType,
			:pSource->aiReportItemID,
			:pSource->asSettType,
			:pSource->asSettNbrType,
			:pSource->asSettCarrID,
			:pSource->asMsc,
			:pSource->asTrunkIn,
			:pSource->asTrunkOut,
			:pSource->asTrunkCarrierID,
			:pSource->asBillingCycleID,
			:pSource->aiCnt,
			:pSource->aiSettMin,
			:pSource->adFee,
			:pSource->adDuration,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )653;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asAccNbr);
  sqlstm.sqhstl[0] = (unsigned long )21;
  sqlstm.sqhsts[0] = (         int  )21;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCalledCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asSettType);
  sqlstm.sqhstl[6] = (unsigned long )3;
  sqlstm.sqhsts[6] = (         int  )3;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSettNbrType);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSettCarrID);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[9] = (unsigned long )16;
  sqlstm.sqhsts[9] = (         int  )16;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asTrunkIn);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asTrunkOut);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asTrunkCarrierID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[18] = (unsigned long )19;
  sqlstm.sqhsts[18] = (         int  )19;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch AU_SETT_NBR_IN_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AU_SETT_NBR_IN_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 63;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )744;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AU_SETT_NBR_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAccNbr,		pSource->asAccNbr[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sCalledCode,		pSource->asCalledCode[iCurPos]);
		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sSettType,		pSource->asSettType[iCurPos]);
		strcpy(p->sSettNbrType,		pSource->asSettNbrType[iCurPos]);
		strcpy(p->sSettCarrID,		pSource->asSettCarrID[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sTrunkIn,		pSource->asTrunkIn[iCurPos]);
		strcpy(p->sTrunkOut,		pSource->asTrunkOut[iCurPos]);
		strcpy(p->sTrunkCarrierID,	pSource->asTrunkCarrierID[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iSettMin=			pSource->aiSettMin[iCurPos];

		p->dFee=		pSource->adFee[iCurPos];
		p->dDuration=		pSource->adDuration[iCurPos];
		strcpy(p->sRowID,		pSource->asRowID[iCurPos]);

		AllTrim(p->sAccNbr);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sCalledCode);
		AllTrim(p->sNetType);
		AllTrim(p->sSettType);
		AllTrim(p->sSettNbrType);
		AllTrim(p->sSettCarrID);
		AllTrim(p->sMsc);
		AllTrim(p->sTrunkIn);
		AllTrim(p->sTrunkOut);
		AllTrim(p->sTrunkCarrierID);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_fmausettnbrstat(struct FAuSettNbrStatStruct *pi,struct AuSettNbrStatStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct AuSettNbrStatStruct));

		strncpy(po->sAccNbr,		pi->sAccNbr,20);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sNetType,		pi->sNetType,1);

		strncpy(sTemp,	pi->sReportItemID,4);sTemp[4]=0;
		po->iReportItemID=atoi(sTemp);

		strncpy(po->sSettType,		pi->sSettType,2);
		strncpy(po->sSettNbrType,	pi->sSettNbrType,3);
		strncpy(po->sSettCarrID,	pi->sSettCarrID,1);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,7);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,7);
		strncpy(po->sTrunkCarrierID,	pi->sTrunkCarrierID,1);
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);

		strncpy(sTemp,		pi->sCnt,9);sTemp[9]=0;
		po->iCnt=atoi(sTemp);
		strncpy(sTemp,		pi->sSettMin,9);sTemp[9]=0;
		po->iSettMin=atoi(sTemp);

		strncpy(sTemp,		pi->sFee,12); sTemp[12]=0;
		po->dFee=atof(sTemp);
		strncpy(sTemp,		pi->sDuration,12); sTemp[12]=0;
		po->dDuration=atof(sTemp);
		
		AllTrim(po->sAccNbr);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sCalledCode);
		AllTrim(po->sNetType);
		AllTrim(po->sSettType);
		AllTrim(po->sSettNbrType);
		AllTrim(po->sSettCarrID);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sTrunkCarrierID);
		AllTrim(po->sBillingCycleID);
}






/*---------------写输出表函数--------------------------------*/
/*批量数据结构缓冲写入AU_SETT_NBR_IN_STAT*/
int EInsertStructToAuSettNbrInStat(struct AuSettNbrStatStruct *p,
	int iInsertFlag,struct AuSettNbrStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAccNbr[iCurPos],		p->sAccNbr);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asSettType[iCurPos],		p->sSettType);
		strcpy(pTarget->asSettNbrType[iCurPos],		p->sSettNbrType);
		strcpy(pTarget->asSettCarrID[iCurPos],		p->sSettCarrID);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asTrunkIn[iCurPos],		p->sTrunkIn);
		strcpy(pTarget->asTrunkOut[iCurPos],		p->sTrunkOut);
		strcpy(pTarget->asTrunkCarrierID[iCurPos],	p->sTrunkCarrierID);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiSettMin[iCurPos]=			p->iSettMin;

		pTarget->adFee[iCurPos]=			p->dFee;
		pTarget->adDuration[iCurPos]=			p->dDuration;

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AU_SETT_NBR_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				ACC_NBR,\n\
				HOME_AREA_CODE,\n\
				VISIT_AREA_CODE,\n\
				CALLED_CODE,\n\
				NET_TYPE,\n\
				REPORT_ITEM_ID,\n\
				SETT_TYPE,\n\
				SETT_NBR_TYPE,\n\
				SETT_CARR_ID,\n\
				MSC,\n\
				TRUNK_IN,\n\
				TRUNK_OUT,\n\
				TRUNK_IN_CARRIER_ID,\n\
				BILLING_CYCLE_ID,\n\
				CNT,\n\
				SETT_MIN,\n\
				IN_FEE,\n\
				DURATION)\n\
			VALUES (\n\
				:asAccNbr,\n\
				:asHomeAreaCode,\n\
				:asVisitAreaCode,\n\
				:asCalledCode,\n\
				:asNetType,\n\
				:aiReportItemID,\n\
				:asSettType,\n\
				:asSettNbrType,\n\
				:asSettCarrID,\n\
				:asMsc,\n\
				:asTrunkIn,\n\
				:asTrunkOut,\n\
				:asTrunkCarrierID,\n\
				:asBillingCycleID,\n\
				:aiCnt,\n\
				:aiSettMin,\n\
				:adFee,\n\
				:adDuration\n\
			)",sTableName);

		/* EXEC SQL PREPARE AU_SETT_NBR_IN_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )759;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare insert statement AU_SETT_NBR_IN_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AU_SETT_NBR_IN_STATTRG USING
				:pTarget->asAccNbr,
				:pTarget->asHomeAreaCode,
				:pTarget->asVisitAreaCode,
				:pTarget->asCalledCode,
				:pTarget->asNetType,
				:pTarget->aiReportItemID,
				:pTarget->asSettType,
				:pTarget->asSettNbrType,
				:pTarget->asSettCarrID,
				:pTarget->asMsc,
				:pTarget->asTrunkIn,
				:pTarget->asTrunkOut,
				:pTarget->asTrunkCarrierID,
				:pTarget->asBillingCycleID,
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )778;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asAccNbr);
  sqlstm.sqhstl[0] = (unsigned long )21;
  sqlstm.sqhsts[0] = (         int  )21;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCalledCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asSettType);
  sqlstm.sqhstl[6] = (unsigned long )3;
  sqlstm.sqhsts[6] = (         int  )3;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asSettNbrType);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asSettCarrID);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[9] = (unsigned long )16;
  sqlstm.sqhsts[9] = (         int  )16;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asTrunkIn);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asTrunkOut);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asTrunkCarrierID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn insert into AU_SETT_NBR_IN_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*批量数据动态从AU_SETT_NBR_OUT_STAT中用结构缓冲方式取数据*/
int EGetAuSettNbrOutStatToStruct(struct AuSettNbrStatStruct *p,
	struct AuSettNbrStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(ACC_NBR,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(CALLED_CODE,' '),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(SETT_TYPE,' '),\n\
				nvl(SETT_NBR_TYPE,' '),\n\
				nvl(SETT_CARR_ID,' '),\n\
				nvl(MSC,' '),\n\
				nvl(TRUNK_IN,' '),\n\
				nvl(TRUNK_OUT,' '),\n\
				nvl(TRUNK_OUT_CARRIER_ID,' '),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				nvl(CNT,0),\n\
				nvl(SETT_MIN,0),\n\
				nvl(OUT_FEE,0),\n\
				nvl(DURATION,0),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AU_SETT_NBR_OUT_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )865;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError(" PREPARE AU_SETT_NBR_OUT_STATSCR AU_SETT_NBR_OUT_STATCR");

		/* EXEC SQL DECLARE AU_SETT_NBR_OUT_STATCR CURSOR FOR AU_SETT_NBR_OUT_STATSCR; */ 

		CheckSqlError("Declare AU_SETT_NBR_OUT_STATCR");

		/* EXEC SQL OPEN AU_SETT_NBR_OUT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )884;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AU_SETT_NBR_OUT_STATCR;");


		pSource->iFirstFlag = pSource->iEndFlag = FALSE;
		pSource->iFetchRecNum = pSource->iCurPos = 0;
		pSource->iBufEmpty = TRUE;
	}

	if(pSource->iEndFlag==TRUE&&iCurPos==pSource->iRecCnt){

		pSource->iBufEmpty=TRUE;
		pSource->iCurPos=0;
		pSource->iFetchRecNum=0;
		pSource->iEndFlag=FALSE;
		pSource->iFirstFlag=TRUE;

		/* EXEC SQL CLOSE AU_SETT_NBR_OUT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )899;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH AU_SETT_NBR_OUT_STATCR INTO
			:pSource->asAccNbr,
			:pSource->asHomeAreaCode,
			:pSource->asVisitAreaCode,
			:pSource->asCalledCode,
			:pSource->asNetType,
			:pSource->aiReportItemID,
			:pSource->asSettType,
			:pSource->asSettNbrType,
			:pSource->asSettCarrID,
			:pSource->asMsc,
			:pSource->asTrunkIn,
			:pSource->asTrunkOut,
			:pSource->asTrunkCarrierID,
			:pSource->asBillingCycleID,
			:pSource->aiCnt,
			:pSource->aiSettMin,
			:pSource->adFee,
			:pSource->adDuration,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )914;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asAccNbr);
  sqlstm.sqhstl[0] = (unsigned long )21;
  sqlstm.sqhsts[0] = (         int  )21;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCalledCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asSettType);
  sqlstm.sqhstl[6] = (unsigned long )3;
  sqlstm.sqhsts[6] = (         int  )3;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSettNbrType);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSettCarrID);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[9] = (unsigned long )16;
  sqlstm.sqhsts[9] = (         int  )16;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asTrunkIn);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asTrunkOut);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asTrunkCarrierID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[18] = (unsigned long )19;
  sqlstm.sqhsts[18] = (         int  )19;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch AU_SETT_NBR_OUT_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AU_SETT_NBR_OUT_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 63;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1005;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AU_SETT_NBR_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAccNbr,		pSource->asAccNbr[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sCalledCode,		pSource->asCalledCode[iCurPos]);
		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sSettType,		pSource->asSettType[iCurPos]);
		strcpy(p->sSettNbrType,		pSource->asSettNbrType[iCurPos]);
		strcpy(p->sSettCarrID,		pSource->asSettCarrID[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sTrunkIn,		pSource->asTrunkIn[iCurPos]);
		strcpy(p->sTrunkOut,		pSource->asTrunkOut[iCurPos]);
		strcpy(p->sTrunkCarrierID,	pSource->asTrunkCarrierID[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iSettMin=			pSource->aiSettMin[iCurPos];

		p->dFee=		pSource->adFee[iCurPos];
		p->dDuration=		pSource->adDuration[iCurPos];
		strcpy(p->sRowID,		pSource->asRowID[iCurPos]);


		AllTrim(p->sAccNbr);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sCalledCode);
		AllTrim(p->sNetType);
		AllTrim(p->sSettType);
		AllTrim(p->sSettNbrType);
		AllTrim(p->sSettCarrID);
		AllTrim(p->sMsc);
		AllTrim(p->sTrunkIn);
		AllTrim(p->sTrunkOut);
		AllTrim(p->sTrunkCarrierID);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->dFee);
		AllTrim(p->dDuration);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}


/*批量数据结构缓冲写入AU_SETT_NBR_OUT_STAT*/
int EInsertStructToAuSettNbrOutStat(struct AuSettNbrStatStruct *p,
	int iInsertFlag,struct AuSettNbrStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAccNbr[iCurPos],		p->sAccNbr);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asSettType[iCurPos],		p->sSettType);
		strcpy(pTarget->asSettNbrType[iCurPos],		p->sSettNbrType);
		strcpy(pTarget->asSettCarrID[iCurPos],		p->sSettCarrID);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asTrunkIn[iCurPos],		p->sTrunkIn);
		strcpy(pTarget->asTrunkOut[iCurPos],		p->sTrunkOut);
		strcpy(pTarget->asTrunkCarrierID[iCurPos],	p->sTrunkCarrierID);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiSettMin[iCurPos]=			p->iSettMin;

		pTarget->adFee[iCurPos]=			p->dFee;
		pTarget->adDuration[iCurPos]=			p->dDuration;

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AU_SETT_NBR_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				ACC_NBR,\n\
				HOME_AREA_CODE,\n\
				VISIT_AREA_CODE,\n\
				CALLED_CODE,\n\
				NET_TYPE,\n\
				REPORT_ITEM_ID,\n\
				SETT_TYPE,\n\
				SETT_NBR_TYPE,\n\
				SETT_CARR_ID,\n\
				MSC,\n\
				TRUNK_IN,\n\
				TRUNK_OUT,\n\
				TRUNK_OUT_CARRIER_ID,\n\
				BILLING_CYCLE_ID,\n\
				CNT,\n\
				SETT_MIN,\n\
				OUT_FEE,\n\
				DURATION)\n\
			VALUES (\n\
				:asAccNbr,\n\
				:asHomeAreaCode,\n\
				:asVisitAreaCode,\n\
				:asCalledCode,\n\
				:asNetType,\n\
				:aiReportItemID,\n\
				:asSettType,\n\
				:asSettNbrType,\n\
				:asSettCarrID,\n\
				:asMsc,\n\
				:asTrunkIn,\n\
				:asTrunkOut,\n\
				:asTrunkCarrierID,\n\
				:asBillingCycleID,\n\
				:aiCnt,\n\
				:aiSettMin,\n\
				:adFee,\n\
				:adDuration\n\
			)",sTableName);

		/* EXEC SQL PREPARE AU_SETT_NBR_OUT_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1020;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare insert statement AU_SETT_NBR_OUT_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AU_SETT_NBR_OUT_STATTRG USING
				:pTarget->asAccNbr,
				:pTarget->asHomeAreaCode,
				:pTarget->asVisitAreaCode,
				:pTarget->asCalledCode,
				:pTarget->asNetType,
				:pTarget->aiReportItemID,
				:pTarget->asSettType,
				:pTarget->asSettNbrType,
				:pTarget->asSettCarrID,
				:pTarget->asMsc,
				:pTarget->asTrunkIn,
				:pTarget->asTrunkOut,
				:pTarget->asTrunkCarrierID,
				:pTarget->asBillingCycleID,
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1039;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asAccNbr);
  sqlstm.sqhstl[0] = (unsigned long )21;
  sqlstm.sqhsts[0] = (         int  )21;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCalledCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asSettType);
  sqlstm.sqhstl[6] = (unsigned long )3;
  sqlstm.sqhsts[6] = (         int  )3;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asSettNbrType);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asSettCarrID);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[9] = (unsigned long )16;
  sqlstm.sqhsts[9] = (         int  )16;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asTrunkIn);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asTrunkOut);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asTrunkCarrierID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn insert into AU_SETT_NBR_OUT_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*批量数据动态从AU_SETT_IN_STAT中用结构缓冲方式取数据*/
int EGetAuSettInStatToStruct(struct AuSettStatStruct *p,
	struct AuSettStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(CALLED_CODE,' '),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(SETT_TYPE,' '),\n\
				nvl(SETT_NBR_TYPE,' '),\n\
				nvl(SETT_CARR_ID,' '),\n\
				nvl(MSC,' '),\n\
				nvl(TRUNK_IN,' '),\n\
				nvl(TRUNK_OUT,' '),\n\
				nvl(TRUNK_IN_CARRIER_ID,' '),\n\
				nvl(SETT_ITEM_DATE,' '),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				nvl(CNT,0),\n\
				nvl(SETT_MIN,0),\n\
				nvl(IN_FEE,0),\n\
				nvl(DURATION,0),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AU_SETT_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1126;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError(" PREPARE AU_SETT_STATSCR AU_SETT_STATCR");

		/* EXEC SQL DECLARE AU_SETT_STATCR CURSOR FOR AU_SETT_STATSCR; */ 

		CheckSqlError("Declare AU_SETT_STATCR");

		/* EXEC SQL OPEN AU_SETT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1145;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AU_SETT_STATCR;");


		pSource->iFirstFlag = pSource->iEndFlag = FALSE;
		pSource->iFetchRecNum = pSource->iCurPos = 0;
		pSource->iBufEmpty = TRUE;
	}

	if(pSource->iEndFlag==TRUE&&iCurPos==pSource->iRecCnt){

		pSource->iBufEmpty=TRUE;
		pSource->iCurPos=0;
		pSource->iFetchRecNum=0;
		pSource->iEndFlag=FALSE;
		pSource->iFirstFlag=TRUE;

		/* EXEC SQL CLOSE AU_SETT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1160;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH AU_SETT_STATCR INTO
			:pSource->asHomeAreaCode,
			:pSource->asVisitAreaCode,
			:pSource->asCalledCode,
			:pSource->asNetType,
			:pSource->aiReportItemID,
			:pSource->asSettType,
			:pSource->asSettNbrType,
			:pSource->asSettCarrID,
			:pSource->asMsc,
			:pSource->asTrunkIn,
			:pSource->asTrunkOut,
			:pSource->asTrunkCarrierID,
			:pSource->asSettItemDate,
			:pSource->asBillingCycleID,
			:pSource->aiCnt,
			:pSource->aiSettMin,
			:pSource->adFee,
			:pSource->adDuration,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1175;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )6;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asCalledCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asSettType);
  sqlstm.sqhstl[5] = (unsigned long )3;
  sqlstm.sqhsts[5] = (         int  )3;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asSettNbrType);
  sqlstm.sqhstl[6] = (unsigned long )4;
  sqlstm.sqhsts[6] = (         int  )4;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSettCarrID);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[8] = (unsigned long )16;
  sqlstm.sqhsts[8] = (         int  )16;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asTrunkIn);
  sqlstm.sqhstl[9] = (unsigned long )8;
  sqlstm.sqhsts[9] = (         int  )8;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asTrunkOut);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asTrunkCarrierID);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asSettItemDate);
  sqlstm.sqhstl[12] = (unsigned long )9;
  sqlstm.sqhsts[12] = (         int  )9;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[18] = (unsigned long )19;
  sqlstm.sqhsts[18] = (         int  )19;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch AU_SETT_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AU_SETT_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 63;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1266;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AU_SETT_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sCalledCode,		pSource->asCalledCode[iCurPos]);
		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sSettType,		pSource->asSettType[iCurPos]);
		strcpy(p->sSettNbrType,		pSource->asSettNbrType[iCurPos]);
		strcpy(p->sSettCarrID,		pSource->asSettCarrID[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sTrunkIn,		pSource->asTrunkIn[iCurPos]);
		strcpy(p->sTrunkOut,		pSource->asTrunkOut[iCurPos]);
		strcpy(p->sTrunkCarrierID,	pSource->asTrunkCarrierID[iCurPos]);
		strcpy(p->sSettItemDate,	pSource->asSettItemDate[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iSettMin=			pSource->aiSettMin[iCurPos];

		p->dFee=		pSource->adFee[iCurPos];
		p->dDuration=		pSource->adDuration[iCurPos];
		strcpy(p->sRowID,		pSource->asRowID[iCurPos]);

		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sCalledCode);
		AllTrim(p->sNetType);
		AllTrim(p->sSettType);
		AllTrim(p->sSettNbrType);
		AllTrim(p->sSettCarrID);
		AllTrim(p->sMsc);
		AllTrim(p->sTrunkIn);
		AllTrim(p->sTrunkOut);
		AllTrim(p->sTrunkCarrierID);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);


	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*批量数据动态从AU_SETT_OUT_STAT中用结构缓冲方式取数据*/
int EGetAuSettOutStatToStruct(struct AuSettStatStruct *p,
	struct AuSettStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(CALLED_CODE,' '),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(SETT_TYPE,' '),\n\
				nvl(SETT_NBR_TYPE,' '),\n\
				nvl(SETT_CARR_ID,' '),\n\
				nvl(MSC,' '),\n\
				nvl(TRUNK_IN,' '),\n\
				nvl(TRUNK_OUT,' '),\n\
				nvl(TRUNK_OUT_CARRIER_ID,' '),\n\
				nvl(SETT_ITEM_DATE,' '),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				nvl(CNT,0),\n\
				nvl(SETT_MIN,0),\n\
				nvl(OUT_FEE,0),\n\
				nvl(DURATION,0),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AU_SETT_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1281;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError(" PREPARE AU_SETT_STATSCR AU_SETT_STATCR");

		/* EXEC SQL DECLARE AU_SETT_STATCR CURSOR FOR AU_SETT_STATSCR; */ 

		CheckSqlError("Declare AU_SETT_STATCR");

		/* EXEC SQL OPEN AU_SETT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1300;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AU_SETT_STATCR;");


		pSource->iFirstFlag = pSource->iEndFlag = FALSE;
		pSource->iFetchRecNum = pSource->iCurPos = 0;
		pSource->iBufEmpty = TRUE;
	}

	if(pSource->iEndFlag==TRUE&&iCurPos==pSource->iRecCnt){

		pSource->iBufEmpty=TRUE;
		pSource->iCurPos=0;
		pSource->iFetchRecNum=0;
		pSource->iEndFlag=FALSE;
		pSource->iFirstFlag=TRUE;

		/* EXEC SQL CLOSE AU_SETT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1315;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH AU_SETT_STATCR INTO
			:pSource->asHomeAreaCode,
			:pSource->asVisitAreaCode,
			:pSource->asCalledCode,
			:pSource->asNetType,
			:pSource->aiReportItemID,
			:pSource->asSettType,
			:pSource->asSettNbrType,
			:pSource->asSettCarrID,
			:pSource->asMsc,
			:pSource->asTrunkIn,
			:pSource->asTrunkOut,
			:pSource->asTrunkCarrierID,
			:pSource->asSettItemDate,
			:pSource->asBillingCycleID,
			:pSource->aiCnt,
			:pSource->aiSettMin,
			:pSource->adFee,
			:pSource->adDuration,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1330;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )6;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asCalledCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asSettType);
  sqlstm.sqhstl[5] = (unsigned long )3;
  sqlstm.sqhsts[5] = (         int  )3;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asSettNbrType);
  sqlstm.sqhstl[6] = (unsigned long )4;
  sqlstm.sqhsts[6] = (         int  )4;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSettCarrID);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[8] = (unsigned long )16;
  sqlstm.sqhsts[8] = (         int  )16;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asTrunkIn);
  sqlstm.sqhstl[9] = (unsigned long )8;
  sqlstm.sqhsts[9] = (         int  )8;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asTrunkOut);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asTrunkCarrierID);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asSettItemDate);
  sqlstm.sqhstl[12] = (unsigned long )9;
  sqlstm.sqhsts[12] = (         int  )9;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[18] = (unsigned long )19;
  sqlstm.sqhsts[18] = (         int  )19;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch AU_SETT_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AU_SETT_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 63;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1421;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AU_SETT_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sCalledCode,		pSource->asCalledCode[iCurPos]);
		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sSettType,		pSource->asSettType[iCurPos]);
		strcpy(p->sSettNbrType,		pSource->asSettNbrType[iCurPos]);
		strcpy(p->sSettCarrID,		pSource->asSettCarrID[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sTrunkIn,		pSource->asTrunkIn[iCurPos]);
		strcpy(p->sTrunkOut,		pSource->asTrunkOut[iCurPos]);
		strcpy(p->sTrunkCarrierID,	pSource->asTrunkCarrierID[iCurPos]);
		strcpy(p->sSettItemDate,	pSource->asSettItemDate[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iSettMin=			pSource->aiSettMin[iCurPos];

		p->dFee=		pSource->adFee[iCurPos];
		p->dDuration=		pSource->adDuration[iCurPos];
		strcpy(p->sRowID,		pSource->asRowID[iCurPos]);

		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sCalledCode);
		AllTrim(p->sNetType);
		AllTrim(p->sSettType);
		AllTrim(p->sSettNbrType);
		AllTrim(p->sSettCarrID);
		AllTrim(p->sMsc);
		AllTrim(p->sTrunkIn);
		AllTrim(p->sTrunkOut);
		AllTrim(p->sTrunkCarrierID);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);


	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

void mvitem_fmausettstat(struct FAuSettStatStruct *pi,struct AuSettStatStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct AuSettStatStruct));

		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sCalledCode,	pi->sCalledCode,5);
		strncpy(po->sNetType,		pi->sNetType,1);

		strncpy(sTemp,	pi->sReportItemID,4);sTemp[4]=0;
		po->iReportItemID=atoi(sTemp);

		strncpy(po->sSettType,		pi->sSettType,2);
		strncpy(po->sSettNbrType,	pi->sSettNbrType,3);
		strncpy(po->sSettCarrID,	pi->sSettCarrID,1);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,7);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,7);
		strncpy(po->sTrunkCarrierID,	pi->sTrunkCarrierID,1);
		strncpy(po->sSettItemDate,	pi->sSettItemDate,8);
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);

		strncpy(sTemp,		pi->sCnt,9);sTemp[9]=0;
		po->iCnt=atoi(sTemp);
		strncpy(sTemp,		pi->sSettMin,9);sTemp[9]=0;
		po->iSettMin=atoi(sTemp);

		strncpy(sTemp,		pi->sFee,12);sTemp[12]=0;
		po->dFee=atof(sTemp);
		strncpy(sTemp,		pi->sDuration,12);sTemp[12]=0;
		po->dDuration=atof(sTemp);

		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sCalledCode);
		AllTrim(po->sNetType);
		AllTrim(po->sSettType);
		AllTrim(po->sSettNbrType);
		AllTrim(po->sSettCarrID);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sTrunkCarrierID);
		AllTrim(po->sSettItemDate);
		AllTrim(po->sBillingCycleID);

}
/*批量数据结构缓冲写入AU_SETT_IN_STAT*/
int EInsertStructToAuSettInStat(struct AuSettStatStruct *p,
	int iInsertFlag,struct AuSettStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asSettType[iCurPos],		p->sSettType);
		strcpy(pTarget->asSettNbrType[iCurPos],		p->sSettNbrType);
		strcpy(pTarget->asSettCarrID[iCurPos],		p->sSettCarrID);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asTrunkIn[iCurPos],		p->sTrunkIn);
		strcpy(pTarget->asTrunkOut[iCurPos],		p->sTrunkOut);
		strcpy(pTarget->asTrunkCarrierID[iCurPos],	p->sTrunkCarrierID);
		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiSettMin[iCurPos]=			p->iSettMin;

		pTarget->adFee[iCurPos]=		p->dFee;
		pTarget->adDuration[iCurPos]=		p->dDuration;

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AU_SETT_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				HOME_AREA_CODE,\n\
				VISIT_AREA_CODE,\n\
				CALLED_CODE,\n\
				NET_TYPE,\n\
				REPORT_ITEM_ID,\n\
				SETT_TYPE,\n\
				SETT_NBR_TYPE,\n\
				SETT_CARR_ID,\n\
				MSC,\n\
				TRUNK_IN,\n\
				TRUNK_OUT,\n\
				TRUNK_IN_CARRIER_ID,\n\
				SETT_ITEM_DATE,\n\
				BILLING_CYCLE_ID,\n\
				CNT,\n\
				SETT_MIN,\n\
				IN_FEE,\n\
				DURATION)\n\
			VALUES (\n\
				:asHomeAreaCode,\n\
				:asVisitAreaCode,\n\
				:asCalledCode,\n\
				:asNetType,\n\
				:aiReportItemID,\n\
				:asSettType,\n\
				:asSettNbrType,\n\
				:asSettCarrID,\n\
				:asMsc,\n\
				:asTrunkIn,\n\
				:asTrunkOut,\n\
				:asTrunkCarrierID,\n\
				:asSettItemDate,\n\
				:asBillingCycleID,\n\
				:aiCnt,\n\
				:aiSettMin,\n\
				:adFee,\n\
				:adDuration\n\
			)",sTableName);

		/* EXEC SQL PREPARE AU_SETT_IN_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1436;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare insert statement AU_SETT_IN_STATTRG")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AU_SETT_IN_STATTRG USING
				:pTarget->asHomeAreaCode,
				:pTarget->asVisitAreaCode,
				:pTarget->asCalledCode,
				:pTarget->asNetType,
				:pTarget->aiReportItemID,
				:pTarget->asSettType,
				:pTarget->asSettNbrType,
				:pTarget->asSettCarrID,
				:pTarget->asMsc,
				:pTarget->asTrunkIn,
				:pTarget->asTrunkOut,
				:pTarget->asTrunkCarrierID,
				:pTarget->asSettItemDate,
				:pTarget->asBillingCycleID,
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1455;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )6;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asCalledCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asSettType);
  sqlstm.sqhstl[5] = (unsigned long )3;
  sqlstm.sqhsts[5] = (         int  )3;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asSettNbrType);
  sqlstm.sqhstl[6] = (unsigned long )4;
  sqlstm.sqhsts[6] = (         int  )4;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asSettCarrID);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[8] = (unsigned long )16;
  sqlstm.sqhsts[8] = (         int  )16;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asTrunkIn);
  sqlstm.sqhstl[9] = (unsigned long )8;
  sqlstm.sqhsts[9] = (         int  )8;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asTrunkOut);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asTrunkCarrierID);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asSettItemDate);
  sqlstm.sqhstl[12] = (unsigned long )9;
  sqlstm.sqhsts[12] = (         int  )9;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn insert into AU_SETT_IN_STATTRG")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}
/*批量数据结构缓冲写入AU_SETT_OUT_STAT*/
int EInsertStructToAuSettOutStat(struct AuSettStatStruct *p,
	int iInsertFlag,struct AuSettStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asSettType[iCurPos],		p->sSettType);
		strcpy(pTarget->asSettNbrType[iCurPos],		p->sSettNbrType);
		strcpy(pTarget->asSettCarrID[iCurPos],		p->sSettCarrID);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asTrunkIn[iCurPos],		p->sTrunkIn);
		strcpy(pTarget->asTrunkOut[iCurPos],		p->sTrunkOut);
		strcpy(pTarget->asTrunkCarrierID[iCurPos],	p->sTrunkCarrierID);
		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiSettMin[iCurPos]=			p->iSettMin;

		pTarget->adFee[iCurPos]=		p->dFee;
		pTarget->adDuration[iCurPos]=		p->dDuration;

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AU_SETT_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				HOME_AREA_CODE,\n\
				VISIT_AREA_CODE,\n\
				CALLED_CODE,\n\
				NET_TYPE,\n\
				REPORT_ITEM_ID,\n\
				SETT_TYPE,\n\
				SETT_NBR_TYPE,\n\
				SETT_CARR_ID,\n\
				MSC,\n\
				TRUNK_IN,\n\
				TRUNK_OUT,\n\
				TRUNK_OUT_CARRIER_ID,\n\
				SETT_ITEM_DATE,\n\
				BILLING_CYCLE_ID,\n\
				CNT,\n\
				SETT_MIN,\n\
				OUT_FEE,\n\
				DURATION)\n\
			VALUES (\n\
				:asHomeAreaCode,\n\
				:asVisitAreaCode,\n\
				:asCalledCode,\n\
				:asNetType,\n\
				:aiReportItemID,\n\
				:asSettType,\n\
				:asSettNbrType,\n\
				:asSettCarrID,\n\
				:asMsc,\n\
				:asTrunkIn,\n\
				:asTrunkOut,\n\
				:asTrunkCarrierID,\n\
				:asSettItemDate,\n\
				:asBillingCycleID,\n\
				:aiCnt,\n\
				:aiSettMin,\n\
				:adFee,\n\
				:adDuration\n\
			)",sTableName);

		/* EXEC SQL PREPARE AU_SETT_OUT_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1542;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare insert statement AU_SETT_OUT_STATTRG")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AU_SETT_OUT_STATTRG USING
				:pTarget->asHomeAreaCode,
				:pTarget->asVisitAreaCode,
				:pTarget->asCalledCode,
				:pTarget->asNetType,
				:pTarget->aiReportItemID,
				:pTarget->asSettType,
				:pTarget->asSettNbrType,
				:pTarget->asSettCarrID,
				:pTarget->asMsc,
				:pTarget->asTrunkIn,
				:pTarget->asTrunkOut,
				:pTarget->asTrunkCarrierID,
				:pTarget->asSettItemDate,
				:pTarget->asBillingCycleID,
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1561;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )6;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asCalledCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asSettType);
  sqlstm.sqhstl[5] = (unsigned long )3;
  sqlstm.sqhsts[5] = (         int  )3;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asSettNbrType);
  sqlstm.sqhstl[6] = (unsigned long )4;
  sqlstm.sqhsts[6] = (         int  )4;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asSettCarrID);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[8] = (unsigned long )16;
  sqlstm.sqhsts[8] = (         int  )16;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asTrunkIn);
  sqlstm.sqhstl[9] = (unsigned long )8;
  sqlstm.sqhsts[9] = (         int  )8;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asTrunkOut);
  sqlstm.sqhstl[10] = (unsigned long )8;
  sqlstm.sqhsts[10] = (         int  )8;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asTrunkCarrierID);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asSettItemDate);
  sqlstm.sqhstl[12] = (unsigned long )9;
  sqlstm.sqhsts[12] = (         int  )9;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )sizeof(double);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )sizeof(double);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn insert into AU_SETT_OUT_STATTRG")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*------------------以下更新函数------------------------------------------------*/
/*批量数据结构缓冲更新AU_SETT_NBR_OUT_STAT*/
int EUpDateStructToAuSettNbrOutStat(struct AuSettNbrStatStruct *p,
	int iUpdateFlag,struct AuSettNbrStatStructUpdOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		
		pTarget->aiCnt[iCurPos]=		p->iCnt;
		pTarget->aiSettMin[iCurPos]=		p->iSettMin;
		pTarget->adFee[iCurPos]=		p->dFee;
		pTarget->adDuration[iCurPos]=		p->dDuration;
		strcpy(pTarget->asRowID[iCurPos],	p->sRowID);
		
		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==AU_SETT_NBR_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;
		sprintf(statement,"\n\
			UPDATE %s\n\
			SET \n\
				CNT=		:aiCnt,\n\
				SETT_MIN=	:aiSettMin,\n\
				OUT_FEE	=	:adFee,\n\
				DURATION=	:adDuration,\n\
			WHERE \n\
				ROWID = chartorowid(:asRowID)",sTableName);

		/* EXEC SQL PREPARE SETT_NBR_OUT_STAT_UP FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1648;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare update statement SETT_NBR_OUT_STAT_UP")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_NBR_OUT_STAT_UP USING
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1667;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )sizeof(double);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )sizeof(double);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[4] = (unsigned long )19;
  sqlstm.sqhsts[4] = (         int  )19;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn update into SETT_NBR_OUT_STAT_UP")<0) return -1;


		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据结构缓冲更新AU_SETT_NBR_IN_STAT*/
int EUpDateStructToAuSettNbrInStat(struct AuSettNbrStatStruct *p,
	int iUpdateFlag,struct AuSettNbrStatStructUpdOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		
		pTarget->aiCnt[iCurPos]=		p->iCnt;
		pTarget->aiSettMin[iCurPos]=		p->iSettMin;
		pTarget->adFee[iCurPos]=		p->dFee;
		pTarget->adDuration[iCurPos]=		p->dDuration;
		strcpy(pTarget->asRowID[iCurPos],	p->sRowID);
		
		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==AU_SETT_NBR_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;
		sprintf(statement,"\n\
			UPDATE %s\n\
			SET \n\
				CNT=		:aiCnt,\n\
				SETT_MIN=	:aiSettMin,\n\
				IN_FEE	=	:adFee,\n\
				DURATION=	:adDuration,\n\
			WHERE \n\
				ROWID = chartorowid(:asRowID)",sTableName);

		/* EXEC SQL PREPARE SETT_NBR_IN_STAT_UP FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1702;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare update statement SETT_NBR_IN_STAT_UP")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_NBR_IN_STAT_UP USING
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1721;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )sizeof(double);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )sizeof(double);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[4] = (unsigned long )19;
  sqlstm.sqhsts[4] = (         int  )19;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn update into SETT_NBR_IN_STAT_UP")<0) return -1;


		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据结构缓冲更新AU_SETT_IN_STAT*/
int EUpDateStructToAuSettInStat(struct AuSettStatStruct *p,
	int iUpdateFlag,struct AuSettStatStructUpdOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		
		pTarget->aiCnt[iCurPos]=		p->iCnt;
		pTarget->aiSettMin[iCurPos]=		p->iSettMin;
		pTarget->adFee[iCurPos]=		p->dFee;
		pTarget->adDuration[iCurPos]=		p->dDuration;
		strcpy(pTarget->asRowID[iCurPos],	p->sRowID);
		
		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==AU_SETT_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;
		sprintf(statement,"\n\
			UPDATE %s\n\
			SET \n\
				CNT=		:aiCnt,\n\
				SETT_MIN=	:aiSettMin,\n\
				IN_FEE	=	:adFee,\n\
				DURATION=	:adDuration,\n\
			WHERE \n\
				ROWID = chartorowid(:asRowID)",sTableName);

		/* EXEC SQL PREPARE SETT_IN_STAT_UP FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1756;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare update statement SETT_IN_STAT_UP")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_IN_STAT_UP USING
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1775;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )sizeof(double);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )sizeof(double);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[4] = (unsigned long )19;
  sqlstm.sqhsts[4] = (         int  )19;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn update into SETT_IN_STAT_UP")<0) return -1;


		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据结构缓冲更新AU_SETT_OUT_STAT*/
int EUpDateStructToAuSettOutStat(struct AuSettStatStruct *p,
	int iUpdateFlag,struct AuSettStatStructUpdOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		
		pTarget->aiCnt[iCurPos]=		p->iCnt;
		pTarget->aiSettMin[iCurPos]=		p->iSettMin;
		pTarget->adFee[iCurPos]=		p->dFee;
		pTarget->adDuration[iCurPos]=		p->dDuration;
		strcpy(pTarget->asRowID[iCurPos],	p->sRowID);
		
		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==AU_SETT_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;
		sprintf(statement,"\n\
			UPDATE %s\n\
			SET \n\
				CNT=		:aiCnt,\n\
				SETT_MIN=	:aiSettMin,\n\
				OUT_FEE	=	:adFee,\n\
				DURATION=	:adDuration,\n\
			WHERE \n\
				ROWID = chartorowid(:asRowID)",sTableName);

		/* EXEC SQL PREPARE SETT_OUT_STAT_UP FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1810;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )8192;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Prepare update statement SETT_OUT_STAT_UP")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_OUT_STAT_UP USING
				:pTarget->aiCnt,
				:pTarget->aiSettMin,
				:pTarget->adFee,
				:pTarget->adDuration,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 63;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1829;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->adFee);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )sizeof(double);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->adDuration);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )sizeof(double);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[4] = (unsigned long )19;
  sqlstm.sqhsts[4] = (         int  )19;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn update into SETT_OUT_STAT_UP")<0) return -1;


		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

