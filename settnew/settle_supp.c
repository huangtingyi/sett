
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
    "settle_supp.pc"
};


static unsigned int sqlctx = 1299707;


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
   unsigned char  *sqhstv[29];
   unsigned long  sqhstl[29];
            int   sqhsts[29];
            short *sqindv[29];
            int   sqinds[29];
   unsigned long  sqharm[29];
   unsigned long  *sqharc[29];
   unsigned short  sqadto[29];
   unsigned short  sqtdso[29];
} sqlstm = {12,29};

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
5,0,0,1,0,0,17,53,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,59,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,76,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,84,0,0,17,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,
137,0,0,1,0,0,15,114,0,0,0,0,0,1,0,
152,0,0,2,0,0,17,312,0,0,1,1,0,1,0,1,97,0,0,
171,0,0,2,0,0,21,315,0,0,17,17,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,
254,0,0,3,0,0,17,390,0,0,1,1,0,1,0,1,97,0,0,
273,0,0,3,0,0,45,396,0,0,0,0,0,1,0,
288,0,0,3,0,0,15,413,0,0,0,0,0,1,0,
303,0,0,3,0,0,13,421,0,0,29,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
434,0,0,3,0,0,15,463,0,0,0,0,0,1,0,
449,0,0,4,0,0,17,667,0,0,1,1,0,1,0,1,97,0,0,
468,0,0,4,0,0,21,670,0,0,29,29,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
599,0,0,5,55,0,4,716,0,0,1,0,0,1,0,2,3,0,0,
618,0,0,6,0,0,17,740,0,0,1,1,0,1,0,1,97,0,0,
637,0,0,6,0,0,45,746,0,0,0,0,0,1,0,
652,0,0,6,0,0,13,752,0,0,5,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
687,0,0,6,0,0,15,761,0,0,0,0,0,1,0,
702,0,0,6,0,0,15,764,0,0,0,0,0,1,0,
717,0,0,7,0,0,17,803,0,0,1,1,0,1,0,1,97,0,0,
736,0,0,7,0,0,21,806,0,0,5,5,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
771,0,0,8,0,0,17,860,0,0,1,1,0,1,0,1,97,0,0,
790,0,0,8,0,0,45,866,0,0,0,0,0,1,0,
805,0,0,8,0,0,15,883,0,0,0,0,0,1,0,
820,0,0,8,0,0,13,891,0,0,24,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,
931,0,0,8,0,0,15,928,0,0,0,0,0,1,0,
946,0,0,9,0,0,17,1102,0,0,1,1,0,1,0,1,97,0,0,
965,0,0,9,0,0,21,1105,0,0,24,24,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
1076,0,0,10,0,0,17,1169,0,0,1,1,0,1,0,1,97,0,0,
1095,0,0,10,0,0,45,1175,0,0,0,0,0,1,0,
1110,0,0,10,0,0,15,1192,0,0,0,0,0,1,0,
1125,0,0,10,0,0,13,1200,0,0,12,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1188,0,0,10,0,0,15,1225,0,0,0,0,0,1,0,
1203,0,0,11,0,0,17,1335,0,0,1,1,0,1,0,1,97,0,0,
1222,0,0,11,0,0,21,1338,0,0,12,12,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1285,0,0,12,0,0,17,1392,0,0,1,1,0,1,0,1,97,0,0,
1304,0,0,12,0,0,45,1398,0,0,0,0,0,1,0,
1319,0,0,12,0,0,15,1415,0,0,0,0,0,1,0,
1334,0,0,12,0,0,13,1423,0,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1401,0,0,12,0,0,15,1449,0,0,0,0,0,1,0,
1416,0,0,13,0,0,17,1571,0,0,1,1,0,1,0,1,97,0,0,
1435,0,0,13,0,0,21,1574,0,0,13,13,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1502,0,0,14,0,0,17,1631,0,0,1,1,0,1,0,1,97,0,0,
1521,0,0,14,0,0,45,1637,0,0,0,0,0,1,0,
1536,0,0,14,0,0,15,1654,0,0,0,0,0,1,0,
1551,0,0,14,0,0,13,1662,0,0,14,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,
1622,0,0,14,0,0,15,1689,0,0,0,0,0,1,0,
1637,0,0,15,0,0,17,1811,0,0,1,1,0,1,0,1,97,0,0,
1656,0,0,15,0,0,21,1814,0,0,14,14,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
1727,0,0,16,0,0,17,1869,0,0,1,1,0,1,0,1,97,0,0,
1746,0,0,16,0,0,45,1875,0,0,0,0,0,1,0,
1761,0,0,16,0,0,15,1892,0,0,0,0,0,1,0,
1776,0,0,16,0,0,13,1900,0,0,13,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1843,0,0,16,0,0,15,1926,0,0,0,0,0,1,0,
1858,0,0,17,0,0,17,2042,0,0,1,1,0,1,0,1,97,0,0,
1877,0,0,17,0,0,21,2045,0,0,13,13,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1944,0,0,18,0,0,17,2099,0,0,1,1,0,1,0,1,97,0,0,
1963,0,0,18,0,0,45,2105,0,0,0,0,0,1,0,
1978,0,0,18,0,0,15,2122,0,0,0,0,0,1,0,
1993,0,0,18,0,0,13,2130,0,0,11,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2052,0,0,18,0,0,15,2154,0,0,0,0,0,1,0,
2067,0,0,19,0,0,17,2284,0,0,1,1,0,1,0,1,97,0,0,
2086,0,0,19,0,0,45,2290,0,0,0,0,0,1,0,
2101,0,0,19,0,0,15,2307,0,0,0,0,0,1,0,
2116,0,0,19,0,0,13,2315,0,0,8,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2163,0,0,19,0,0,15,2336,0,0,0,0,0,1,0,
2178,0,0,20,0,0,17,2458,0,0,1,1,0,1,0,1,97,0,0,
2197,0,0,20,0,0,45,2464,0,0,0,0,0,1,0,
2212,0,0,20,0,0,15,2481,0,0,0,0,0,1,0,
2227,0,0,20,0,0,13,2489,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2258,0,0,20,0,0,15,2506,0,0,0,0,0,1,0,
2273,0,0,21,0,0,17,2884,0,0,1,1,0,1,0,1,97,0,0,
2292,0,0,21,0,0,45,2890,0,0,0,0,0,1,0,
2307,0,0,21,0,0,15,2907,0,0,0,0,0,1,0,
2322,0,0,21,0,0,13,2915,0,0,28,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2449,0,0,21,0,0,15,2956,0,0,0,0,0,1,0,
};


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdb.h>
#include <bintree.h>
#include <dbsupp.h>

#include "settle_supp.h"


/*批量数据动态从TEMPLATE_SMS_MMS_TICKET中用结构缓冲方式取数据*/
int EGetTemplateSmsMmsTicketToStruct(struct TemplateSmsMmsTicketStruct *p,
	struct TemplateSmsMmsTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_LATN_ID,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(PROD_ID,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(MSISDN,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(SETT_FEE,0),\n\
				nvl(MY_3G_FLAG,' '),\n\
				nvl(OPP_3G_FLAG,' '),\n\
				nvl(MY_CARR_ID,' '),\n\
				nvl(OPP_CARR_ID,' '),\n\
				nvl(SERV_FLAG,' '),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(GROUP_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TEMPLATE_SMS_MMS_TICKETSCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE TEMPLATE_SMS_MMS_TICKETSCR TEMPLATE_SMS_MMS_TICKETCR");

		/* EXEC SQL DECLARE TEMPLATE_SMS_MMS_TICKETCR CURSOR FOR TEMPLATE_SMS_MMS_TICKETSCR; */ 

		CheckSqlError("Declare TEMPLATE_SMS_MMS_TICKETCR");

		/* EXEC SQL OPEN TEMPLATE_SMS_MMS_TICKETCR; */ 

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


		CheckSqlError("Open TEMPLATE_SMS_MMS_TICKETCR;");


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

		/* EXEC SQL CLOSE TEMPLATE_SMS_MMS_TICKETCR; */ 

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
		/* EXEC SQL FETCH TEMPLATE_SMS_MMS_TICKETCR INTO
			:pSource->asSettLatnID,
			:pSource->aiReportItemID,
			:pSource->asProdID,
			:pSource->asCallType,
			:pSource->asHomeAreaCode,
			:pSource->asMsisdn,
			:pSource->asOppAreaCode,
			:pSource->asOtherParty,
			:pSource->asStartTime,
			:pSource->aiSettFee,
			:pSource->asMy3gFlag,
			:pSource->asOpp3gFlag,
			:pSource->asMyCarrID,
			:pSource->asOppCarrID,
			:pSource->asServFlag,
			:pSource->asFileName,
			:pSource->asGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
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
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[5] = (unsigned long )16;
  sqlstm.sqhsts[5] = (         int  )16;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[7] = (unsigned long )16;
  sqlstm.sqhsts[7] = (         int  )16;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiSettFee);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asMy3gFlag);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asOpp3gFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asMyCarrID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asOppCarrID);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asServFlag);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[15] = (unsigned long )61;
  sqlstm.sqhsts[15] = (         int  )61;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[16] = (unsigned long )3;
  sqlstm.sqhsts[16] = (         int  )3;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
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


		CheckSqlError("Fetch TEMPLATE_SMS_MMS_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TEMPLATE_SMS_MMS_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )137;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TEMPLATE_SMS_MMS_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSettLatnID,		pSource->asSettLatnID[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);

		p->iSettFee=			pSource->aiSettFee[iCurPos];

		strcpy(p->sMy3gFlag,		pSource->asMy3gFlag[iCurPos]);
		strcpy(p->sOpp3gFlag,		pSource->asOpp3gFlag[iCurPos]);
		strcpy(p->sMyCarrID,		pSource->asMyCarrID[iCurPos]);
		strcpy(p->sOppCarrID,		pSource->asOppCarrID[iCurPos]);
		strcpy(p->sServFlag,		pSource->asServFlag[iCurPos]);
		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sGroupID,		pSource->asGroupID[iCurPos]);

		AllTrim(p->sSettLatnID);
		AllTrim(p->sProdID);
		AllTrim(p->sCallType);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sMsisdn);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sStartTime);
		AllTrim(p->sMy3gFlag);
		AllTrim(p->sOpp3gFlag);
		AllTrim(p->sMyCarrID);
		AllTrim(p->sOppCarrID);
		AllTrim(p->sServFlag);
		AllTrim(p->sFileName);
		AllTrim(p->sGroupID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_fmtemplatesmsmmsticket(struct FTemplateSmsMmsTicketStruct *pi,struct TemplateSmsMmsTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct TemplateSmsMmsTicketStruct));

		strncpy(po->sSettLatnID,	pi->sSettLatnID,1);

		strncpy(sTemp,	pi->sReportItemID,8);sTemp[8]=0;
		po->iReportItemID=atoi(sTemp);

		strncpy(po->sProdID,		pi->sProdID,10);
		strncpy(po->sCallType,		pi->sCallType,1);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOppAreaCode,	pi->sOppAreaCode,5);
		strncpy(po->sOtherParty,	pi->sOtherParty,15);
		strncpy(po->sStartTime,		pi->sStartTime,14);

		strncpy(sTemp,		pi->sSettFee,9);sTemp[9]=0;
		po->iSettFee=atoi(sTemp);

		strncpy(po->sMy3gFlag,		pi->sMy3gFlag,1);
		strncpy(po->sOpp3gFlag,		pi->sOpp3gFlag,1);
		strncpy(po->sMyCarrID,		pi->sMyCarrID,1);
		strncpy(po->sOppCarrID,		pi->sOppCarrID,1);
		strncpy(po->sServFlag,		pi->sServFlag,1);
		strncpy(po->sFileName,		pi->sFileName,60);
		strncpy(po->sGroupID,		pi->sGroupID,2);

		AllTrim(po->sSettLatnID);
		AllTrim(po->sProdID);
		AllTrim(po->sCallType);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOppAreaCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sMy3gFlag);
		AllTrim(po->sOpp3gFlag);
		AllTrim(po->sMyCarrID);
		AllTrim(po->sOppCarrID);
		AllTrim(po->sServFlag);
		AllTrim(po->sFileName);
		AllTrim(po->sGroupID);
}
/**对表TEMPLATE_SMS_MMS_TICKET的链表释放函数**/
void DestroyTemplateSmsMmsTicket(struct TemplateSmsMmsTicketStruct *ptHead)
{
	struct TemplateSmsMmsTicketStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
/*批量数据结构缓冲写入TEMPLATE_SMS_MMS_TICKET*/
int EInsertStructToTemplateSmsMmsTicket(struct TemplateSmsMmsTicketStruct *p,
	int iInsertFlag,struct TemplateSmsMmsTicketStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSettLatnID[iCurPos],		p->sSettLatnID);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asProdID[iCurPos],		p->sProdID);
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asMsisdn[iCurPos],		p->sMsisdn);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);
		strcpy(pTarget->asOtherParty[iCurPos],		p->sOtherParty);
		strcpy(pTarget->asStartTime[iCurPos],		p->sStartTime);

		pTarget->aiSettFee[iCurPos]=			p->iSettFee;

		strcpy(pTarget->asMy3gFlag[iCurPos],		p->sMy3gFlag);
		strcpy(pTarget->asOpp3gFlag[iCurPos],		p->sOpp3gFlag);
		strcpy(pTarget->asMyCarrID[iCurPos],		p->sMyCarrID);
		strcpy(pTarget->asOppCarrID[iCurPos],		p->sOppCarrID);
		strcpy(pTarget->asServFlag[iCurPos],		p->sServFlag);
		strcpy(pTarget->asFileName[iCurPos],		p->sFileName);
		strcpy(pTarget->asGroupID[iCurPos],		p->sGroupID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==TEMPLATE_SMS_MMS_TICKET_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_LATN_ID,\n\
				REPORT_ITEM_ID,\n\
				PROD_ID,\n\
				CALL_TYPE,\n\
				HOME_AREA_CODE,\n\
				CALLING_NUMBER,\n\
				OPP_AREA_CODE,\n\
				CALLED_NUMBER,\n\
				START_TIME,\n\
				SETT_FEE,\n\
				MY_3G_FLAG,\n\
				OPP_3G_FLAG,\n\
				MY_CARR_ID,\n\
				OPP_CARR_ID,\n\
				SERV_FLAG,\n\
				FILE_NAME,\n\
				GROUP_ID)\n\
			VALUES (\n\
				:asSettLatnID,\n\
				:aiReportItemID,\n\
				:asProdID,\n\
				:asCallType,\n\
				:asHomeAreaCode,\n\
				:asMsisdn,\n\
				:asOppAreaCode,\n\
				:asOtherParty,\n\
				:asStartTime,\n\
				:aiSettFee,\n\
				:asMy3gFlag,\n\
				:asOpp3gFlag,\n\
				:asMyCarrID,\n\
				:asOppCarrID,\n\
				:asServFlag,\n\
				:asFileName,\n\
				:asGroupID\n\
			)",sTableName);

		/* EXEC SQL PREPARE TEMPLATE_SMS_MMS_TICKETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )152;
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


		if(CheckSqlResult("Prepare insert statement TEMPLATE_SMS_MMS_TICKET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE TEMPLATE_SMS_MMS_TICKETTRG USING
				:pTarget->asSettLatnID,
				:pTarget->aiReportItemID,
				:pTarget->asProdID,
				:pTarget->asCallType,
				:pTarget->asHomeAreaCode,
				:pTarget->asMsisdn,
				:pTarget->asOppAreaCode,
				:pTarget->asOtherParty,
				:pTarget->asStartTime,
				:pTarget->aiSettFee,
				:pTarget->asMy3gFlag,
				:pTarget->asOpp3gFlag,
				:pTarget->asMyCarrID,
				:pTarget->asOppCarrID,
				:pTarget->asServFlag,
				:pTarget->asFileName,
				:pTarget->asGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )171;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asMsisdn);
  sqlstm.sqhstl[5] = (unsigned long )16;
  sqlstm.sqhsts[5] = (         int  )16;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asOtherParty);
  sqlstm.sqhstl[7] = (unsigned long )16;
  sqlstm.sqhsts[7] = (         int  )16;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asStartTime);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->aiSettFee);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asMy3gFlag);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asOpp3gFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asMyCarrID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asOppCarrID);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asServFlag);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[15] = (unsigned long )61;
  sqlstm.sqhsts[15] = (         int  )61;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[16] = (unsigned long )3;
  sqlstm.sqhsts[16] = (         int  )3;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into TEMPLATE_SMS_MMS_TICKET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*批量数据动态从TEMPLATE_STT_TICKET中用结构缓冲方式取数据*/
int EGetTemplateSttTicketToStruct(struct TemplateSttTicketStruct *p,
	struct TemplateSttTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_LATN_ID,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(PROD_ID,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(MSISDN,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(DURATION,0),\n\
				nvl(SETT_FEE,0),\n\
				nvl(MY_DISTANCE_TYPE,' '),\n\
				nvl(OPP_DISTANCE_TYPE,' '),\n\
				nvl(MY_NBR_TYPE,' '),\n\
				nvl(OPP_NBR_TYPE,' '),\n\
				nvl(MY_3G_FLAG,' '),\n\
				nvl(OPP_3G_FLAG,' '),\n\
				nvl(MSC,' '),\n\
				nvl(TRUNK_IN,' '),\n\
				nvl(TRUNK_OUT,' '),\n\
				nvl(TRUNK_IN_CARR_ID,' '),\n\
				nvl(TRUNK_OUT_CARR_ID,' '),\n\
				nvl(MY_CARR_ID,' '),\n\
				nvl(OPP_CARR_ID,' '),\n\
				nvl(MY_AREA_ID,0),\n\
				nvl(OPP_AREA_ID,0),\n\
				nvl(SERV_FLAG,' '),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(GROUP_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TEMPLATE_STT_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )254;
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


		CheckSqlError(" PREPARE TEMPLATE_STT_TICKETSCR TEMPLATE_STT_TICKETCR");

		/* EXEC SQL DECLARE TEMPLATE_STT_TICKETCR CURSOR FOR TEMPLATE_STT_TICKETSCR; */ 

		CheckSqlError("Declare TEMPLATE_STT_TICKETCR");

		/* EXEC SQL OPEN TEMPLATE_STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )273;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TEMPLATE_STT_TICKETCR;");


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

		/* EXEC SQL CLOSE TEMPLATE_STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )288;
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
		/* EXEC SQL FETCH TEMPLATE_STT_TICKETCR INTO
			:pSource->asSettLatnID,
			:pSource->aiReportItemID,
			:pSource->asProdID,
			:pSource->asCallType,
			:pSource->asHomeAreaCode,
			:pSource->asMsisdn,
			:pSource->asOppAreaCode,
			:pSource->asOtherParty,
			:pSource->asStartTime,
			:pSource->aiDuration,
			:pSource->aiSettFee,
			:pSource->asMyDistanceType,
			:pSource->asOppDistanceType,
			:pSource->asMyNbrType,
			:pSource->asOppNbrType,
			:pSource->asMy3gFlag,
			:pSource->asOpp3gFlag,
			:pSource->asMsc,
			:pSource->asTrunkIn,
			:pSource->asTrunkOut,
			:pSource->asTrunkInCarrID,
			:pSource->asTrunkOutCarrID,
			:pSource->asMyCarrID,
			:pSource->asOppCarrID,
			:pSource->aiMyAreaID,
			:pSource->aiOppAreaID,
			:pSource->asServFlag,
			:pSource->asFileName,
			:pSource->asGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )303;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[5] = (unsigned long )16;
  sqlstm.sqhsts[5] = (         int  )16;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[7] = (unsigned long )16;
  sqlstm.sqhsts[7] = (         int  )16;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
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
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiSettFee);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asMyDistanceType);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asOppDistanceType);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asMyNbrType);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asOppNbrType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asMy3gFlag);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asOpp3gFlag);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[17] = (unsigned long )11;
  sqlstm.sqhsts[17] = (         int  )11;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asTrunkIn);
  sqlstm.sqhstl[18] = (unsigned long )8;
  sqlstm.sqhsts[18] = (         int  )8;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asTrunkOut);
  sqlstm.sqhstl[19] = (unsigned long )8;
  sqlstm.sqhsts[19] = (         int  )8;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asTrunkInCarrID);
  sqlstm.sqhstl[20] = (unsigned long )2;
  sqlstm.sqhsts[20] = (         int  )2;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asTrunkOutCarrID);
  sqlstm.sqhstl[21] = (unsigned long )2;
  sqlstm.sqhsts[21] = (         int  )2;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asMyCarrID);
  sqlstm.sqhstl[22] = (unsigned long )2;
  sqlstm.sqhsts[22] = (         int  )2;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asOppCarrID);
  sqlstm.sqhstl[23] = (unsigned long )2;
  sqlstm.sqhsts[23] = (         int  )2;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->aiMyAreaID);
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )sizeof(int);
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->aiOppAreaID);
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )sizeof(int);
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->asServFlag);
  sqlstm.sqhstl[26] = (unsigned long )2;
  sqlstm.sqhsts[26] = (         int  )2;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[27] = (unsigned long )61;
  sqlstm.sqhsts[27] = (         int  )61;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[28] = (unsigned long )3;
  sqlstm.sqhsts[28] = (         int  )3;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
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


		CheckSqlError("Fetch TEMPLATE_STT_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TEMPLATE_STT_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )434;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TEMPLATE_STT_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSettLatnID,		pSource->asSettLatnID[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);

		p->iDuration=			pSource->aiDuration[iCurPos];
		p->iSettFee=			pSource->aiSettFee[iCurPos];

		strcpy(p->sMyDistanceType,	pSource->asMyDistanceType[iCurPos]);
		strcpy(p->sOppDistanceType,	pSource->asOppDistanceType[iCurPos]);
		strcpy(p->sMyNbrType,		pSource->asMyNbrType[iCurPos]);
		strcpy(p->sOppNbrType,		pSource->asOppNbrType[iCurPos]);
		strcpy(p->sMy3gFlag,		pSource->asMy3gFlag[iCurPos]);
		strcpy(p->sOpp3gFlag,		pSource->asOpp3gFlag[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sTrunkIn,		pSource->asTrunkIn[iCurPos]);
		strcpy(p->sTrunkOut,		pSource->asTrunkOut[iCurPos]);
		strcpy(p->sTrunkInCarrID,	pSource->asTrunkInCarrID[iCurPos]);
		strcpy(p->sTrunkOutCarrID,	pSource->asTrunkOutCarrID[iCurPos]);
		strcpy(p->sMyCarrID,		pSource->asMyCarrID[iCurPos]);
		strcpy(p->sOppCarrID,		pSource->asOppCarrID[iCurPos]);

		p->iMyAreaID=			pSource->aiMyAreaID[iCurPos];
		p->iOppAreaID=			pSource->aiOppAreaID[iCurPos];

		strcpy(p->sServFlag,		pSource->asServFlag[iCurPos]);
		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sGroupID,		pSource->asGroupID[iCurPos]);

		AllTrim(p->sSettLatnID);
		AllTrim(p->sProdID);
		AllTrim(p->sCallType);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sMsisdn);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sStartTime);
		AllTrim(p->sMyDistanceType);
		AllTrim(p->sOppDistanceType);
		AllTrim(p->sMyNbrType);
		AllTrim(p->sOppNbrType);
		AllTrim(p->sMy3gFlag);
		AllTrim(p->sOpp3gFlag);
		AllTrim(p->sMsc);
		AllTrim(p->sTrunkIn);
		AllTrim(p->sTrunkOut);
		AllTrim(p->sTrunkInCarrID);
		AllTrim(p->sTrunkOutCarrID);
		AllTrim(p->sMyCarrID);
		AllTrim(p->sOppCarrID);
		AllTrim(p->sServFlag);
		AllTrim(p->sFileName);
		AllTrim(p->sGroupID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入TEMPLATE_STT_TICKET*/
int EInsertStructToTemplateSttTicket(struct TemplateSttTicketStruct *p,
	int iInsertFlag,struct TemplateSttTicketStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSettLatnID[iCurPos],		p->sSettLatnID);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asProdID[iCurPos],		p->sProdID);
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asMsisdn[iCurPos],		p->sMsisdn);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);
		strcpy(pTarget->asOtherParty[iCurPos],		p->sOtherParty);
		strcpy(pTarget->asStartTime[iCurPos],		p->sStartTime);

		pTarget->aiDuration[iCurPos]=			p->iDuration;
		pTarget->aiSettFee[iCurPos]=			p->iSettFee;

		strcpy(pTarget->asMyDistanceType[iCurPos],	p->sMyDistanceType);
		strcpy(pTarget->asOppDistanceType[iCurPos],	p->sOppDistanceType);
		strcpy(pTarget->asMyNbrType[iCurPos],		p->sMyNbrType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);
		strcpy(pTarget->asMy3gFlag[iCurPos],		p->sMy3gFlag);
		strcpy(pTarget->asOpp3gFlag[iCurPos],		p->sOpp3gFlag);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asTrunkIn[iCurPos],		p->sTrunkIn);
		strcpy(pTarget->asTrunkOut[iCurPos],		p->sTrunkOut);
		strcpy(pTarget->asTrunkInCarrID[iCurPos],	p->sTrunkInCarrID);
		strcpy(pTarget->asTrunkOutCarrID[iCurPos],	p->sTrunkOutCarrID);
		strcpy(pTarget->asMyCarrID[iCurPos],		p->sMyCarrID);
		strcpy(pTarget->asOppCarrID[iCurPos],		p->sOppCarrID);

		pTarget->aiMyAreaID[iCurPos]=			p->iMyAreaID;
		pTarget->aiOppAreaID[iCurPos]=			p->iOppAreaID;

		strcpy(pTarget->asServFlag[iCurPos],		p->sServFlag);
		strcpy(pTarget->asFileName[iCurPos],		p->sFileName);
		strcpy(pTarget->asGroupID[iCurPos],		p->sGroupID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==TEMPLATE_STT_TICKET_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_LATN_ID,\n\
				REPORT_ITEM_ID,\n\
				PROD_ID,\n\
				CALL_TYPE,\n\
				HOME_AREA_CODE,\n\
				MSISDN,\n\
				OPP_AREA_CODE,\n\
				OTHER_PARTY,\n\
				START_TIME,\n\
				DURATION,\n\
				SETT_FEE,\n\
				MY_DISTANCE_TYPE,\n\
				OPP_DISTANCE_TYPE,\n\
				MY_NBR_TYPE,\n\
				OPP_NBR_TYPE,\n\
				MY_3G_FLAG,\n\
				OPP_3G_FLAG,\n\
				MSC,\n\
				TRUNK_IN,\n\
				TRUNK_OUT,\n\
				TRUNK_IN_CARR_ID,\n\
				TRUNK_OUT_CARR_ID,\n\
				MY_CARR_ID,\n\
				OPP_CARR_ID,\n\
				MY_AREA_ID,\n\
				OPP_AREA_ID,\n\
				SERV_FLAG,\n\
				FILE_NAME,\n\
				GROUP_ID)\n\
			VALUES (\n\
				:asSettLatnID,\n\
				:aiReportItemID,\n\
				:asProdID,\n\
				:asCallType,\n\
				:asHomeAreaCode,\n\
				:asMsisdn,\n\
				:asOppAreaCode,\n\
				:asOtherParty,\n\
				:asStartTime,\n\
				:aiDuration,\n\
				:aiSettFee,\n\
				:asMyDistanceType,\n\
				:asOppDistanceType,\n\
				:asMyNbrType,\n\
				:asOppNbrType,\n\
				:asMy3gFlag,\n\
				:asOpp3gFlag,\n\
				:asMsc,\n\
				:asTrunkIn,\n\
				:asTrunkOut,\n\
				:asTrunkInCarrID,\n\
				:asTrunkOutCarrID,\n\
				:asMyCarrID,\n\
				:asOppCarrID,\n\
				:aiMyAreaID,\n\
				:aiOppAreaID,\n\
				:asServFlag,\n\
				:asFileName,\n\
				:asGroupID\n\
			)",sTableName);

		/* EXEC SQL PREPARE TEMPLATE_STT_TICKETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )449;
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


		if(CheckSqlResult("Prepare insert statement TEMPLATE_STT_TICKET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE TEMPLATE_STT_TICKETTRG USING
				:pTarget->asSettLatnID,
				:pTarget->aiReportItemID,
				:pTarget->asProdID,
				:pTarget->asCallType,
				:pTarget->asHomeAreaCode,
				:pTarget->asMsisdn,
				:pTarget->asOppAreaCode,
				:pTarget->asOtherParty,
				:pTarget->asStartTime,
				:pTarget->aiDuration,
				:pTarget->aiSettFee,
				:pTarget->asMyDistanceType,
				:pTarget->asOppDistanceType,
				:pTarget->asMyNbrType,
				:pTarget->asOppNbrType,
				:pTarget->asMy3gFlag,
				:pTarget->asOpp3gFlag,
				:pTarget->asMsc,
				:pTarget->asTrunkIn,
				:pTarget->asTrunkOut,
				:pTarget->asTrunkInCarrID,
				:pTarget->asTrunkOutCarrID,
				:pTarget->asMyCarrID,
				:pTarget->asOppCarrID,
				:pTarget->aiMyAreaID,
				:pTarget->aiOppAreaID,
				:pTarget->asServFlag,
				:pTarget->asFileName,
				:pTarget->asGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )468;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asMsisdn);
  sqlstm.sqhstl[5] = (unsigned long )16;
  sqlstm.sqhsts[5] = (         int  )16;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asOtherParty);
  sqlstm.sqhstl[7] = (unsigned long )16;
  sqlstm.sqhsts[7] = (         int  )16;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asStartTime);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiSettFee);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asMyDistanceType);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asOppDistanceType);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asMyNbrType);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asOppNbrType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asMy3gFlag);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asOpp3gFlag);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[17] = (unsigned long )11;
  sqlstm.sqhsts[17] = (         int  )11;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asTrunkIn);
  sqlstm.sqhstl[18] = (unsigned long )8;
  sqlstm.sqhsts[18] = (         int  )8;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asTrunkOut);
  sqlstm.sqhstl[19] = (unsigned long )8;
  sqlstm.sqhsts[19] = (         int  )8;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asTrunkInCarrID);
  sqlstm.sqhstl[20] = (unsigned long )2;
  sqlstm.sqhsts[20] = (         int  )2;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asTrunkOutCarrID);
  sqlstm.sqhstl[21] = (unsigned long )2;
  sqlstm.sqhsts[21] = (         int  )2;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asMyCarrID);
  sqlstm.sqhstl[22] = (unsigned long )2;
  sqlstm.sqhsts[22] = (         int  )2;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asOppCarrID);
  sqlstm.sqhstl[23] = (unsigned long )2;
  sqlstm.sqhsts[23] = (         int  )2;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->aiMyAreaID);
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )sizeof(int);
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pTarget->aiOppAreaID);
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )sizeof(int);
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pTarget->asServFlag);
  sqlstm.sqhstl[26] = (unsigned long )2;
  sqlstm.sqhsts[26] = (         int  )2;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[27] = (unsigned long )61;
  sqlstm.sqhsts[27] = (         int  )61;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[28] = (unsigned long )3;
  sqlstm.sqhsts[28] = (         int  )3;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into TEMPLATE_STT_TICKET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}




int GetSettBillStorSeq()
{
	int iSettBillStorSeq=0;
	
	/* EXEC SQL SELECT SETT_BILL_STOR_SEQ.nextval INTO :iSettBillStorSeq FROM DUAL ; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select SETT_BILL_STOR_SEQ.nextval  into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )599;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSettBillStorSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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


	CheckSqlError("Get iSettBillStorSeq ERROR");
	
	return iSettBillStorSeq;
	
}

int SDGetSettBillStorLogToStruct(struct SettBillStorLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_BILL_STOR_SEQ,0),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(FILE_DATE,' '),\n\
				to_char(nvl(DEAL_TIME,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_BILL_STORSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )618;
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


		CheckSqlError(" PREPARE SETT_BILL_STORSCR SETT_BILL_STORCR");

		/* EXEC SQL DECLARE SETT_BILL_STORCR CURSOR FOR SETT_BILL_STORSCR; */ 

		CheckSqlError("Declare SETT_BILL_STORCR");

		/* EXEC SQL OPEN SETT_BILL_STORCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )637;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_BILL_STORCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH SETT_BILL_STORCR INTO
			:p->iSettBillStorSeq,
			:p->sFileName,
			:p->sFileDate,
			:p->sDealTime,
			:p->sState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )652;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iSettBillStorSeq);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[1] = (unsigned long )65;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sFileDate);
  sqlstm.sqhstl[2] = (unsigned long )9;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sDealTime);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
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


		CheckSqlError("Fetch SETT_BILL_STORCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE SETT_BILL_STORCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )687;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE SETT_BILL_STORCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )702;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sFileName);
		AllTrim(p->sFileDate);
		AllTrim(p->sDealTime);
		AllTrim(p->sState);

	return TRUE;
}
int SDInsertStructToSettBillStorLog(struct SettBillStorLogStruct *p,char sTableName[])
{

/*获取seq值*/
		p->iSettBillStorSeq=GetSettBillStorSeq();

/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_BILL_STOR_SEQ,\n\
				FILE_NAME,\n\
				FILE_DATE,\n\
				DEAL_TIME,\n\
				STATE)\n\
			VALUES (\n\
				:iSettBillStorSeq,\n\
				:sFileName,\n\
				:sFileDate,\n\
				to_date(:sDealTime,'yyyymmddhh24miss'),\n\
				:sState\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_BILL_STORTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )717;
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


		if(CheckSqlResult("Prepare insert statement SETT_BILL_STOR")<0) return -1;

		/* EXEC SQL EXECUTE SETT_BILL_STORTRG USING
				:p->iSettBillStorSeq,
				:p->sFileName,
				:p->sFileDate,
				:p->sDealTime,
				:p->sState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )736;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iSettBillStorSeq);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[1] = (unsigned long )65;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sFileDate);
  sqlstm.sqhstl[2] = (unsigned long )9;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sDealTime);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
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


		if(CheckSqlResult("Dyn insert into SETT_BILL_STOR")<0) return -1;

	return 0;
}


/*批量数据动态从TEMPLATE_MID_STT_TICKET中用结构缓冲方式取数据*/
int EGetTemplateMidSttTicketToStruct(struct TemplateMidSttTicketStruct *p,
	struct TemplateMidSttTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_LATN_ID,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(PROD_ID,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(MSISDN,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(SETT_DATE,' '),\n\
				nvl(CNT,0),\n\
				nvl(DURATION,0),\n\
				nvl(SETT_DURATION,0),\n\
				nvl(SETT_FEE,0),\n\
				nvl(MY_DISTANCE_TYPE,' '),\n\
				nvl(OPP_DISTANCE_TYPE,' '),\n\
				nvl(MY_NBR_TYPE,' '),\n\
				nvl(OPP_NBR_TYPE,' '),\n\
				nvl(MY_3G_FLAG,' '),\n\
				nvl(OPP_3G_FLAG,' '),\n\
				nvl(MY_CARR_ID,' '),\n\
				nvl(OPP_CARR_ID,' '),\n\
				nvl(SERV_FLAG,' '),\n\
				nvl(GROUP_ID,' '),\n\
				nvl(OTHER_GROUP_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TEMPLATE_MID_STT_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )771;
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


		CheckSqlError(" PREPARE TEMPLATE_MID_STT_TICKETSCR TEMPLATE_MID_STT_TICKETCR");

		/* EXEC SQL DECLARE TEMPLATE_MID_STT_TICKETCR CURSOR FOR TEMPLATE_MID_STT_TICKETSCR; */ 

		CheckSqlError("Declare TEMPLATE_MID_STT_TICKETCR");

		/* EXEC SQL OPEN TEMPLATE_MID_STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )790;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TEMPLATE_MID_STT_TICKETCR;");


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

		/* EXEC SQL CLOSE TEMPLATE_MID_STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )805;
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
		/* EXEC SQL FETCH TEMPLATE_MID_STT_TICKETCR INTO
			:pSource->asSettLatnID,
			:pSource->aiReportItemID,
			:pSource->asProdID,
			:pSource->asCallType,
			:pSource->asHomeAreaCode,
			:pSource->asMsisdn,
			:pSource->asOppAreaCode,
			:pSource->asOtherParty,
			:pSource->asSettDate,
			:pSource->aiCnt,
			:pSource->aiDuration,
			:pSource->aiSettDuration,
			:pSource->aiSettFee,
			:pSource->asMyDistanceType,
			:pSource->asOppDistanceType,
			:pSource->asMyNbrType,
			:pSource->asOppNbrType,
			:pSource->asMy3gFlag,
			:pSource->asOpp3gFlag,
			:pSource->asMyCarrID,
			:pSource->asOppCarrID,
			:pSource->asServFlag,
			:pSource->asGroupID,
			:pSource->asOtherGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )820;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[5] = (unsigned long )16;
  sqlstm.sqhsts[5] = (         int  )16;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[7] = (unsigned long )16;
  sqlstm.sqhsts[7] = (         int  )16;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSettDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiSettDuration);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiSettFee);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asMyDistanceType);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asOppDistanceType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asMyNbrType);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asOppNbrType);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asMy3gFlag);
  sqlstm.sqhstl[17] = (unsigned long )2;
  sqlstm.sqhsts[17] = (         int  )2;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asOpp3gFlag);
  sqlstm.sqhstl[18] = (unsigned long )2;
  sqlstm.sqhsts[18] = (         int  )2;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asMyCarrID);
  sqlstm.sqhstl[19] = (unsigned long )2;
  sqlstm.sqhsts[19] = (         int  )2;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asOppCarrID);
  sqlstm.sqhstl[20] = (unsigned long )2;
  sqlstm.sqhsts[20] = (         int  )2;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asServFlag);
  sqlstm.sqhstl[21] = (unsigned long )2;
  sqlstm.sqhsts[21] = (         int  )2;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asOtherGroupID);
  sqlstm.sqhstl[23] = (unsigned long )3;
  sqlstm.sqhsts[23] = (         int  )3;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
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


		CheckSqlError("Fetch TEMPLATE_MID_STT_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TEMPLATE_MID_STT_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )931;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TEMPLATE_MID_STT_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSettLatnID,		pSource->asSettLatnID[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sSettDate,		pSource->asSettDate[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iDuration=			pSource->aiDuration[iCurPos];
		p->iSettDuration=		pSource->aiSettDuration[iCurPos];
		p->iSettFee=			pSource->aiSettFee[iCurPos];

		strcpy(p->sMyDistanceType,	pSource->asMyDistanceType[iCurPos]);
		strcpy(p->sOppDistanceType,	pSource->asOppDistanceType[iCurPos]);
		strcpy(p->sMyNbrType,		pSource->asMyNbrType[iCurPos]);
		strcpy(p->sOppNbrType,		pSource->asOppNbrType[iCurPos]);
		strcpy(p->sMy3gFlag,		pSource->asMy3gFlag[iCurPos]);
		strcpy(p->sOpp3gFlag,		pSource->asOpp3gFlag[iCurPos]);
		strcpy(p->sMyCarrID,		pSource->asMyCarrID[iCurPos]);
		strcpy(p->sOppCarrID,		pSource->asOppCarrID[iCurPos]);
		strcpy(p->sServFlag,		pSource->asServFlag[iCurPos]);
		strcpy(p->sGroupID,		pSource->asGroupID[iCurPos]);
		strcpy(p->sOtherGroupID,	pSource->asOtherGroupID[iCurPos]);

		AllTrim(p->sSettLatnID);
		AllTrim(p->sProdID);
		AllTrim(p->sCallType);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sMsisdn);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sSettDate);
		AllTrim(p->sMyDistanceType);
		AllTrim(p->sOppDistanceType);
		AllTrim(p->sMyNbrType);
		AllTrim(p->sOppNbrType);
		AllTrim(p->sMy3gFlag);
		AllTrim(p->sOpp3gFlag);
		AllTrim(p->sMyCarrID);
		AllTrim(p->sOppCarrID);
		AllTrim(p->sServFlag);
		AllTrim(p->sGroupID);
		AllTrim(p->sOtherGroupID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*批量数据结构缓冲写入TEMPLATE_MID_STT_TICKET*/
int EInsertStructToTemplateMidSttTicket(struct TemplateMidSttTicketStruct *p,
	int iInsertFlag,struct TemplateMidSttTicketStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSettLatnID[iCurPos],		p->sSettLatnID);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asProdID[iCurPos],		p->sProdID);
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asMsisdn[iCurPos],		p->sMsisdn);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);
		strcpy(pTarget->asOtherParty[iCurPos],		p->sOtherParty);
		strcpy(pTarget->asSettDate[iCurPos],		p->sSettDate);

		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiDuration[iCurPos]=			p->iDuration;
		pTarget->aiSettDuration[iCurPos]=		p->iSettDuration;
		pTarget->aiSettFee[iCurPos]=			p->iSettFee;

		strcpy(pTarget->asMyDistanceType[iCurPos],	p->sMyDistanceType);
		strcpy(pTarget->asOppDistanceType[iCurPos],	p->sOppDistanceType);
		strcpy(pTarget->asMyNbrType[iCurPos],		p->sMyNbrType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);
		strcpy(pTarget->asMy3gFlag[iCurPos],		p->sMy3gFlag);
		strcpy(pTarget->asOpp3gFlag[iCurPos],		p->sOpp3gFlag);
		strcpy(pTarget->asMyCarrID[iCurPos],		p->sMyCarrID);
		strcpy(pTarget->asOppCarrID[iCurPos],		p->sOppCarrID);
		strcpy(pTarget->asServFlag[iCurPos],		p->sServFlag);
		strcpy(pTarget->asGroupID[iCurPos],		p->sGroupID);
		strcpy(pTarget->asOtherGroupID[iCurPos],	p->sOtherGroupID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==TEMPLATE_MID_STT_TICKET_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_LATN_ID,\n\
				REPORT_ITEM_ID,\n\
				PROD_ID,\n\
				CALL_TYPE,\n\
				HOME_AREA_CODE,\n\
				MSISDN,\n\
				OPP_AREA_CODE,\n\
				OTHER_PARTY,\n\
				SETT_DATE,\n\
				CNT,\n\
				DURATION,\n\
				SETT_DURATION,\n\
				SETT_FEE,\n\
				MY_DISTANCE_TYPE,\n\
				OPP_DISTANCE_TYPE,\n\
				MY_NBR_TYPE,\n\
				OPP_NBR_TYPE,\n\
				MY_3G_FLAG,\n\
				OPP_3G_FLAG,\n\
				MY_CARR_ID,\n\
				OPP_CARR_ID,\n\
				SERV_FLAG,\n\
				GROUP_ID,\n\
				OTHER_GROUP_ID)\n\
			VALUES (\n\
				:asSettLatnID,\n\
				:aiReportItemID,\n\
				:asProdID,\n\
				:asCallType,\n\
				:asHomeAreaCode,\n\
				:asMsisdn,\n\
				:asOppAreaCode,\n\
				:asOtherParty,\n\
				:asSettDate,\n\
				:aiCnt,\n\
				:aiDuration,\n\
				:aiSettDuration,\n\
				:aiSettFee,\n\
				:asMyDistanceType,\n\
				:asOppDistanceType,\n\
				:asMyNbrType,\n\
				:asOppNbrType,\n\
				:asMy3gFlag,\n\
				:asOpp3gFlag,\n\
				:asMyCarrID,\n\
				:asOppCarrID,\n\
				:asServFlag,\n\
				:asGroupID,\n\
				:asOtherGroupID\n\
			)",sTableName);

		/* EXEC SQL PREPARE TEMPLATE_MID_STT_TICKETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )946;
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


		if(CheckSqlResult("Prepare insert statement TEMPLATE_MID_STT_TICKET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE TEMPLATE_MID_STT_TICKETTRG USING
				:pTarget->asSettLatnID,
				:pTarget->aiReportItemID,
				:pTarget->asProdID,
				:pTarget->asCallType,
				:pTarget->asHomeAreaCode,
				:pTarget->asMsisdn,
				:pTarget->asOppAreaCode,
				:pTarget->asOtherParty,
				:pTarget->asSettDate,
				:pTarget->aiCnt,
				:pTarget->aiDuration,
				:pTarget->aiSettDuration,
				:pTarget->aiSettFee,
				:pTarget->asMyDistanceType,
				:pTarget->asOppDistanceType,
				:pTarget->asMyNbrType,
				:pTarget->asOppNbrType,
				:pTarget->asMy3gFlag,
				:pTarget->asOpp3gFlag,
				:pTarget->asMyCarrID,
				:pTarget->asOppCarrID,
				:pTarget->asServFlag,
				:pTarget->asGroupID,
				:pTarget->asOtherGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )965;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asMsisdn);
  sqlstm.sqhstl[5] = (unsigned long )16;
  sqlstm.sqhsts[5] = (         int  )16;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asOtherParty);
  sqlstm.sqhstl[7] = (unsigned long )16;
  sqlstm.sqhsts[7] = (         int  )16;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asSettDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->aiSettDuration);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->aiSettFee);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asMyDistanceType);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asOppDistanceType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asMyNbrType);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asOppNbrType);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asMy3gFlag);
  sqlstm.sqhstl[17] = (unsigned long )2;
  sqlstm.sqhsts[17] = (         int  )2;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asOpp3gFlag);
  sqlstm.sqhstl[18] = (unsigned long )2;
  sqlstm.sqhsts[18] = (         int  )2;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asMyCarrID);
  sqlstm.sqhstl[19] = (unsigned long )2;
  sqlstm.sqhsts[19] = (         int  )2;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asOppCarrID);
  sqlstm.sqhstl[20] = (unsigned long )2;
  sqlstm.sqhsts[20] = (         int  )2;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asServFlag);
  sqlstm.sqhstl[21] = (unsigned long )2;
  sqlstm.sqhsts[21] = (         int  )2;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asOtherGroupID);
  sqlstm.sqhstl[23] = (unsigned long )3;
  sqlstm.sqhsts[23] = (         int  )3;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into TEMPLATE_MID_STT_TICKET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据动态从AN_STAT_UNUNSAL_TICKET中用结构缓冲方式取数据*/
int EGetAnStatUnunsalTicketToStruct(struct AnStatUnunsalTicketStruct *p,
	struct AnStatUnunsalTicketStructIn *pSource)
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
				nvl(MSISDN,' '),\n\
				nvl(SETT_DATE,' '),\n\
				nvl(CNT,0),\n\
				nvl(DURATION,0),\n\
				nvl(SETT_DURATION,0),\n\
				nvl(IN_FEE,0),\n\
				nvl(OUT_FEE,0),\n\
				nvl(MY_NBR_TYPE,' '),\n\
				nvl(MY_3G_FLAG,' '),\n\
				nvl(MY_CARR_ID,' '),\n\
				nvl(SERV_FLAG,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AN_STAT_UNUNSAL_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1076;
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


		CheckSqlError(" PREPARE AN_STAT_UNUNSAL_TICKETSCR AN_STAT_UNUNSAL_TICKETCR");

		/* EXEC SQL DECLARE AN_STAT_UNUNSAL_TICKETCR CURSOR FOR AN_STAT_UNUNSAL_TICKETSCR; */ 

		CheckSqlError("Declare AN_STAT_UNUNSAL_TICKETCR");

		/* EXEC SQL OPEN AN_STAT_UNUNSAL_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1095;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AN_STAT_UNUNSAL_TICKETCR;");


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

		/* EXEC SQL CLOSE AN_STAT_UNUNSAL_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1110;
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
		/* EXEC SQL FETCH AN_STAT_UNUNSAL_TICKETCR INTO
			:pSource->asHomeAreaCode,
			:pSource->asMsisdn,
			:pSource->asSettDate,
			:pSource->aiCnt,
			:pSource->aiDuration,
			:pSource->aiSettDuration,
			:pSource->aiInFee,
			:pSource->aiOutFee,
			:pSource->asMyNbrType,
			:pSource->asMy3gFlag,
			:pSource->asMyCarrID,
			:pSource->asServFlag; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1125;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[1] = (unsigned long )16;
  sqlstm.sqhsts[1] = (         int  )16;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asSettDate);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiSettDuration);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiInFee);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiOutFee);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asMyNbrType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asMy3gFlag);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asMyCarrID);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asServFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
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


		CheckSqlError("Fetch AN_STAT_UNUNSAL_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AN_STAT_UNUNSAL_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1188;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AN_STAT_UNUNSAL_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sSettDate,		pSource->asSettDate[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iDuration=			pSource->aiDuration[iCurPos];
		p->iSettDuration=		pSource->aiSettDuration[iCurPos];
		p->iInFee=			pSource->aiInFee[iCurPos];
		p->iOutFee=			pSource->aiOutFee[iCurPos];

		strcpy(p->sMyNbrType,		pSource->asMyNbrType[iCurPos]);
		strcpy(p->sMy3gFlag,		pSource->asMy3gFlag[iCurPos]);
		strcpy(p->sMyCarrID,		pSource->asMyCarrID[iCurPos]);
		strcpy(p->sServFlag,		pSource->asServFlag[iCurPos]);

		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sMsisdn);
		AllTrim(p->sSettDate);
		AllTrim(p->sMyNbrType);
		AllTrim(p->sMy3gFlag);
		AllTrim(p->sMyCarrID);
		AllTrim(p->sServFlag);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*批量数据结构缓冲写入AN_STAT_UNUNSAL_TICKET*/
int EInsertStructToAnStatUnunsalTicket(struct AnStatUnunsalTicketStruct *p,
	int iInsertFlag,struct AnStatUnunsalTicketStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asMsisdn[iCurPos],		p->sMsisdn);
		strcpy(pTarget->asSettDate[iCurPos],		p->sSettDate);

		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiDuration[iCurPos]=			p->iDuration;
		pTarget->aiSettDuration[iCurPos]=		p->iSettDuration;
		pTarget->aiInFee[iCurPos]=			p->iInFee;
		pTarget->aiOutFee[iCurPos]=			p->iOutFee;

		strcpy(pTarget->asMyNbrType[iCurPos],		p->sMyNbrType);
		strcpy(pTarget->asMy3gFlag[iCurPos],		p->sMy3gFlag);
		strcpy(pTarget->asMyCarrID[iCurPos],		p->sMyCarrID);
		strcpy(pTarget->asServFlag[iCurPos],		p->sServFlag);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AN_STAT_UNUNSAL_TICKET_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				HOME_AREA_CODE,\n\
				MSISDN,\n\
				SETT_DATE,\n\
				CNT,\n\
				DURATION,\n\
				SETT_DURATION,\n\
				IN_FEE,\n\
				OUT_FEE,\n\
				MY_NBR_TYPE,\n\
				MY_3G_FLAG,\n\
				MY_CARR_ID,\n\
				SERV_FLAG)\n\
			VALUES (\n\
				:asHomeAreaCode,\n\
				:asMsisdn,\n\
				:asSettDate,\n\
				:aiCnt,\n\
				:aiDuration,\n\
				:aiSettDuration,\n\
				:aiInFee,\n\
				:aiOutFee,\n\
				:asMyNbrType,\n\
				:asMy3gFlag,\n\
				:asMyCarrID,\n\
				:asServFlag\n\
			)",sTableName);

		/* EXEC SQL PREPARE AN_STAT_UNUNSAL_TICKETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1203;
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


		if(CheckSqlResult("Prepare insert statement AN_STAT_UNUNSAL_TICKET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AN_STAT_UNUNSAL_TICKETTRG USING
				:pTarget->asHomeAreaCode,
				:pTarget->asMsisdn,
				:pTarget->asSettDate,
				:pTarget->aiCnt,
				:pTarget->aiDuration,
				:pTarget->aiSettDuration,
				:pTarget->aiInFee,
				:pTarget->aiOutFee,
				:pTarget->asMyNbrType,
				:pTarget->asMy3gFlag,
				:pTarget->asMyCarrID,
				:pTarget->asServFlag; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1222;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asMsisdn);
  sqlstm.sqhstl[1] = (unsigned long )16;
  sqlstm.sqhsts[1] = (         int  )16;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asSettDate);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiSettDuration);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiInFee);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiOutFee);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asMyNbrType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asMy3gFlag);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asMyCarrID);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asServFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into AN_STAT_UNUNSAL_TICKET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*批量数据动态从TEMPLATE_STT_TREND中用结构缓冲方式取数据*/
int EGetTemplateSttTrendToStruct(struct TemplateSttTrendStruct *p,
	struct TemplateSttTrendStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_LATN_ID,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(SETT_DATE,' '),\n\
				nvl(CNT,0),\n\
				to_char(nvl(DURATION,0)),\n\
				to_char(nvl(SETT_DURATION,0)),\n\
				to_char(nvl(IN_FEE,0)),\n\
				to_char(nvl(OUT_FEE,0)),\n\
				nvl(MY_NBR_TYPE,' '),\n\
				nvl(MY_3G_FLAG,' '),\n\
				nvl(OPP_CARR_ID,' '),\n\
				nvl(OPP_3G_FLAG,' '),\n\
				nvl(SERV_FLAG,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TEMPLATE_STT_TRENDSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1285;
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


		CheckSqlError(" PREPARE TEMPLATE_STT_TRENDSCR TEMPLATE_STT_TRENDCR");

		/* EXEC SQL DECLARE TEMPLATE_STT_TRENDCR CURSOR FOR TEMPLATE_STT_TRENDSCR; */ 

		CheckSqlError("Declare TEMPLATE_STT_TRENDCR");

		/* EXEC SQL OPEN TEMPLATE_STT_TRENDCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1304;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TEMPLATE_STT_TRENDCR;");


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

		/* EXEC SQL CLOSE TEMPLATE_STT_TRENDCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1319;
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
		/* EXEC SQL FETCH TEMPLATE_STT_TRENDCR INTO
			:pSource->asSettLatnID,
			:pSource->aiReportItemID,
			:pSource->asSettDate,
			:pSource->aiCnt,
			:pSource->asDuration,
			:pSource->asSettDuration,
			:pSource->asInFee,
			:pSource->asOutFee,
			:pSource->asMyNbrType,
			:pSource->asMy3gFlag,
			:pSource->asOppCarrID,
			:pSource->asOpp3gFlag,
			:pSource->asServFlag; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1334;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asSettDate);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asDuration);
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )13;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asSettDuration);
  sqlstm.sqhstl[5] = (unsigned long )13;
  sqlstm.sqhsts[5] = (         int  )13;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asInFee);
  sqlstm.sqhstl[6] = (unsigned long )13;
  sqlstm.sqhsts[6] = (         int  )13;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asOutFee);
  sqlstm.sqhstl[7] = (unsigned long )13;
  sqlstm.sqhsts[7] = (         int  )13;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asMyNbrType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asMy3gFlag);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asOppCarrID);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asOpp3gFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asServFlag);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
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


		CheckSqlError("Fetch TEMPLATE_STT_TRENDCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TEMPLATE_STT_TRENDCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1401;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TEMPLATE_STT_TREND_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSettLatnID,		pSource->asSettLatnID[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sSettDate,		pSource->asSettDate[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];

		strcpy(p->sDuration,		pSource->asDuration[iCurPos]);
		strcpy(p->sSettDuration,	pSource->asSettDuration[iCurPos]);
		strcpy(p->sInFee,		pSource->asInFee[iCurPos]);
		strcpy(p->sOutFee,		pSource->asOutFee[iCurPos]);
		strcpy(p->sMyNbrType,		pSource->asMyNbrType[iCurPos]);
		strcpy(p->sMy3gFlag,		pSource->asMy3gFlag[iCurPos]);
		strcpy(p->sOppCarrID,		pSource->asOppCarrID[iCurPos]);
		strcpy(p->sOpp3gFlag,		pSource->asOpp3gFlag[iCurPos]);
		strcpy(p->sServFlag,		pSource->asServFlag[iCurPos]);

		AllTrim(p->sSettLatnID);
		AllTrim(p->sSettDate);
		AllTrim(p->sDuration);
		AllTrim(p->sSettDuration);
		AllTrim(p->sInFee);
		AllTrim(p->sOutFee);
		AllTrim(p->sMyNbrType);
		AllTrim(p->sMy3gFlag);
		AllTrim(p->sOppCarrID);
		AllTrim(p->sOpp3gFlag);
		AllTrim(p->sServFlag);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*批量数据结构缓冲写入TEMPLATE_STT_TREND*/
int EInsertStructToTemplateSttTrend(struct TemplateSttTrendStruct *p,
	int iInsertFlag,struct TemplateSttTrendStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSettLatnID[iCurPos],		p->sSettLatnID);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;

		strcpy(pTarget->asSettDate[iCurPos],		p->sSettDate);

		pTarget->aiCnt[iCurPos]=			p->iCnt;

		strcpy(pTarget->asDuration[iCurPos],		p->sDuration);
		strcpy(pTarget->asSettDuration[iCurPos],	p->sSettDuration);
		strcpy(pTarget->asInFee[iCurPos],		p->sInFee);
		strcpy(pTarget->asOutFee[iCurPos],		p->sOutFee);
		strcpy(pTarget->asMyNbrType[iCurPos],		p->sMyNbrType);
		strcpy(pTarget->asMy3gFlag[iCurPos],		p->sMy3gFlag);
		strcpy(pTarget->asOppCarrID[iCurPos],		p->sOppCarrID);
		strcpy(pTarget->asOpp3gFlag[iCurPos],		p->sOpp3gFlag);
		strcpy(pTarget->asServFlag[iCurPos],		p->sServFlag);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==TEMPLATE_STT_TREND_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_LATN_ID,\n\
				REPORT_ITEM_ID,\n\
				SETT_DATE,\n\
				CNT,\n\
				DURATION,\n\
				SETT_DURATION,\n\
				IN_FEE,\n\
				OUT_FEE,\n\
				MY_NBR_TYPE,\n\
				MY_3G_FLAG,\n\
				OPP_CARR_ID,\n\
				OPP_3G_FLAG,\n\
				SERV_FLAG)\n\
			VALUES (\n\
				:asSettLatnID,\n\
				:aiReportItemID,\n\
				:asSettDate,\n\
				:aiCnt,\n\
				to_number(:asDuration),\n\
				to_number(:asSettDuration),\n\
				to_number(:asInFee),\n\
				to_number(:asOutFee),\n\
				:asMyNbrType,\n\
				:asMy3gFlag,\n\
				:asOppCarrID,\n\
				:asOpp3gFlag,\n\
				:asServFlag\n\
			)",sTableName);

		/* EXEC SQL PREPARE TEMPLATE_STT_TRENDTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1416;
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


		if(CheckSqlResult("Prepare insert statement TEMPLATE_STT_TREND")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE TEMPLATE_STT_TRENDTRG USING
				:pTarget->asSettLatnID,
				:pTarget->aiReportItemID,
				:pTarget->asSettDate,
				:pTarget->aiCnt,
				:pTarget->asDuration,
				:pTarget->asSettDuration,
				:pTarget->asInFee,
				:pTarget->asOutFee,
				:pTarget->asMyNbrType,
				:pTarget->asMy3gFlag,
				:pTarget->asOppCarrID,
				:pTarget->asOpp3gFlag,
				:pTarget->asServFlag; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1435;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asSettDate);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asDuration);
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )13;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asSettDuration);
  sqlstm.sqhstl[5] = (unsigned long )13;
  sqlstm.sqhsts[5] = (         int  )13;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asInFee);
  sqlstm.sqhstl[6] = (unsigned long )13;
  sqlstm.sqhsts[6] = (         int  )13;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asOutFee);
  sqlstm.sqhstl[7] = (unsigned long )13;
  sqlstm.sqhsts[7] = (         int  )13;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asMyNbrType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asMy3gFlag);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asOppCarrID);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asOpp3gFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asServFlag);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into TEMPLATE_STT_TREND")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*批量数据动态从AN_SETT_TOP_500_TW中用结构缓冲方式取数据*/
int EGetAnSettTop500TwToStruct(struct AnSettTop500TwStruct *p,
	struct AnSettTop500TwStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_LATN_ID,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(SETT_DATE,' '),\n\
				nvl(CNT,0),\n\
				nvl(DURATION,0),\n\
				nvl(SETT_DURATION,0),\n\
				nvl(SETT_FEE,0),\n\
				nvl(OPP_NBR_TYPE,' '),\n\
				nvl(MY_3G_FLAG,' '),\n\
				nvl(OPP_3G_FLAG,' '),\n\
				nvl(MY_CARR_ID,' '),\n\
				nvl(OPP_CARR_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AN_SETT_TOP_500_TWSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1502;
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


		CheckSqlError(" PREPARE AN_SETT_TOP_500_TWSCR AN_SETT_TOP_500_TWCR");

		/* EXEC SQL DECLARE AN_SETT_TOP_500_TWCR CURSOR FOR AN_SETT_TOP_500_TWSCR; */ 

		CheckSqlError("Declare AN_SETT_TOP_500_TWCR");

		/* EXEC SQL OPEN AN_SETT_TOP_500_TWCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1521;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AN_SETT_TOP_500_TWCR;");


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

		/* EXEC SQL CLOSE AN_SETT_TOP_500_TWCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1536;
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
		/* EXEC SQL FETCH AN_SETT_TOP_500_TWCR INTO
			:pSource->asSettLatnID,
			:pSource->asCallType,
			:pSource->asOppAreaCode,
			:pSource->asOtherParty,
			:pSource->asSettDate,
			:pSource->aiCnt,
			:pSource->aiDuration,
			:pSource->aiSettDuration,
			:pSource->aiSettFee,
			:pSource->asOppNbrType,
			:pSource->asMy3gFlag,
			:pSource->asOpp3gFlag,
			:pSource->asMyCarrID,
			:pSource->asOppCarrID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1551;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[3] = (unsigned long )16;
  sqlstm.sqhsts[3] = (         int  )16;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asSettDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiSettDuration);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiSettFee);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asOppNbrType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asMy3gFlag);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asOpp3gFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asMyCarrID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asOppCarrID);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
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


		CheckSqlError("Fetch AN_SETT_TOP_500_TWCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AN_SETT_TOP_500_TWCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1622;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AN_SETT_TOP_500_TW_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSettLatnID,	pSource->asSettLatnID[iCurPos]);
		strcpy(p->sCallType,	pSource->asCallType[iCurPos]);
		strcpy(p->sOppAreaCode,	pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sOtherParty,	pSource->asOtherParty[iCurPos]);
		strcpy(p->sSettDate,	pSource->asSettDate[iCurPos]);

		p->iCnt=		pSource->aiCnt[iCurPos];
		p->iDuration=		pSource->aiDuration[iCurPos];
		p->iSettDuration=	pSource->aiSettDuration[iCurPos];
		p->iSettFee=		pSource->aiSettFee[iCurPos];

		strcpy(p->sOppNbrType,	pSource->asOppNbrType[iCurPos]);
		strcpy(p->sMy3gFlag,	pSource->asMy3gFlag[iCurPos]);
		strcpy(p->sOpp3gFlag,	pSource->asOpp3gFlag[iCurPos]);
		strcpy(p->sMyCarrID,	pSource->asMyCarrID[iCurPos]);
		strcpy(p->sOppCarrID,	pSource->asOppCarrID[iCurPos]);

		AllTrim(p->sSettLatnID);
		AllTrim(p->sCallType);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sSettDate);
		AllTrim(p->sOppNbrType);
		AllTrim(p->sMy3gFlag);
		AllTrim(p->sOpp3gFlag);
		AllTrim(p->sMyCarrID);
		AllTrim(p->sOppCarrID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入AN_SETT_TOP_500_TW*/
int EInsertStructToAnSettTop500Tw(struct AnSettTop500TwStruct *p,
	int iInsertFlag,struct AnSettTop500TwStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSettLatnID[iCurPos],	p->sSettLatnID);
		strcpy(pTarget->asCallType[iCurPos],	p->sCallType);
		strcpy(pTarget->asOppAreaCode[iCurPos],	p->sOppAreaCode);
		strcpy(pTarget->asOtherParty[iCurPos],	p->sOtherParty);
		strcpy(pTarget->asSettDate[iCurPos],	p->sSettDate);

		pTarget->aiCnt[iCurPos]=		p->iCnt;
		pTarget->aiDuration[iCurPos]=		p->iDuration;
		pTarget->aiSettDuration[iCurPos]=	p->iSettDuration;
		pTarget->aiSettFee[iCurPos]=		p->iSettFee;

		strcpy(pTarget->asOppNbrType[iCurPos],	p->sOppNbrType);
		strcpy(pTarget->asMy3gFlag[iCurPos],	p->sMy3gFlag);
		strcpy(pTarget->asOpp3gFlag[iCurPos],	p->sOpp3gFlag);
		strcpy(pTarget->asMyCarrID[iCurPos],	p->sMyCarrID);
		strcpy(pTarget->asOppCarrID[iCurPos],	p->sOppCarrID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AN_SETT_TOP_500_TW_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_LATN_ID,\n\
				CALL_TYPE,\n\
				OPP_AREA_CODE,\n\
				OTHER_PARTY,\n\
				SETT_DATE,\n\
				CNT,\n\
				DURATION,\n\
				SETT_DURATION,\n\
				SETT_FEE,\n\
				OPP_NBR_TYPE,\n\
				MY_3G_FLAG,\n\
				OPP_3G_FLAG,\n\
				MY_CARR_ID,\n\
				OPP_CARR_ID)\n\
			VALUES (\n\
				:asSettLatnID,\n\
				:asCallType,\n\
				:asOppAreaCode,\n\
				:asOtherParty,\n\
				:asSettDate,\n\
				:aiCnt,\n\
				:aiDuration,\n\
				:aiSettDuration,\n\
				:aiSettFee,\n\
				:asOppNbrType,\n\
				:asMy3gFlag,\n\
				:asOpp3gFlag,\n\
				:asMyCarrID,\n\
				:asOppCarrID\n\
			)",sTableName);

		/* EXEC SQL PREPARE AN_SETT_TOP_500_TWTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1637;
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


		if(CheckSqlResult("Prepare insert statement AN_SETT_TOP_500_TW")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AN_SETT_TOP_500_TWTRG USING
				:pTarget->asSettLatnID,
				:pTarget->asCallType,
				:pTarget->asOppAreaCode,
				:pTarget->asOtherParty,
				:pTarget->asSettDate,
				:pTarget->aiCnt,
				:pTarget->aiDuration,
				:pTarget->aiSettDuration,
				:pTarget->aiSettFee,
				:pTarget->asOppNbrType,
				:pTarget->asMy3gFlag,
				:pTarget->asOpp3gFlag,
				:pTarget->asMyCarrID,
				:pTarget->asOppCarrID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1656;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asOtherParty);
  sqlstm.sqhstl[3] = (unsigned long )16;
  sqlstm.sqhsts[3] = (         int  )16;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asSettDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiSettDuration);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->aiSettFee);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asOppNbrType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asMy3gFlag);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asOpp3gFlag);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asMyCarrID);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asOppCarrID);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into AN_SETT_TOP_500_TW")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据动态从AN_SETT_TOP_500_LT中用结构缓冲方式取数据*/
int EGetAnSettTop500LtToStruct(struct AnSettTop500LtStruct *p,
	struct AnSettTop500LtStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_LATN_ID,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(MSISDN,' '),\n\
				nvl(SETT_DATE,' '),\n\
				nvl(CNT,0),\n\
				nvl(DURATION,0),\n\
				nvl(SETT_DURATION,0),\n\
				nvl(SETT_FEE,0),\n\
				nvl(MY_NBR_TYPE,' '),\n\
				nvl(MY_3G_FLAG,' '),\n\
				nvl(MY_CARR_ID,' '),\n\
				nvl(SERV_FLAG,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AN_SETT_TOP_500_LTSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1727;
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


		CheckSqlError(" PREPARE AN_SETT_TOP_500_LTSCR AN_SETT_TOP_500_LTCR");

		/* EXEC SQL DECLARE AN_SETT_TOP_500_LTCR CURSOR FOR AN_SETT_TOP_500_LTSCR; */ 

		CheckSqlError("Declare AN_SETT_TOP_500_LTCR");

		/* EXEC SQL OPEN AN_SETT_TOP_500_LTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1746;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AN_SETT_TOP_500_LTCR;");


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

		/* EXEC SQL CLOSE AN_SETT_TOP_500_LTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1761;
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
		/* EXEC SQL FETCH AN_SETT_TOP_500_LTCR INTO
			:pSource->asSettLatnID,
			:pSource->asCallType,
			:pSource->asHomeAreaCode,
			:pSource->asMsisdn,
			:pSource->asSettDate,
			:pSource->aiCnt,
			:pSource->aiDuration,
			:pSource->aiSettDuration,
			:pSource->aiSettFee,
			:pSource->asMyNbrType,
			:pSource->asMy3gFlag,
			:pSource->asMyCarrID,
			:pSource->asServFlag; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1776;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[3] = (unsigned long )16;
  sqlstm.sqhsts[3] = (         int  )16;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asSettDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiSettDuration);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiSettFee);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asMyNbrType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asMy3gFlag);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asMyCarrID);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asServFlag);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
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


		CheckSqlError("Fetch AN_SETT_TOP_500_LTCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AN_SETT_TOP_500_LTCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1843;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AN_SETT_TOP_500_LT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSettLatnID,		pSource->asSettLatnID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sSettDate,		pSource->asSettDate[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iDuration=			pSource->aiDuration[iCurPos];
		p->iSettDuration=		pSource->aiSettDuration[iCurPos];
		p->iSettFee=			pSource->aiSettFee[iCurPos];

		strcpy(p->sMyNbrType,		pSource->asMyNbrType[iCurPos]);
		strcpy(p->sMy3gFlag,		pSource->asMy3gFlag[iCurPos]);
		strcpy(p->sMyCarrID,		pSource->asMyCarrID[iCurPos]);
		strcpy(p->sServFlag,		pSource->asServFlag[iCurPos]);

		AllTrim(p->sSettLatnID);
		AllTrim(p->sCallType);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sMsisdn);
		AllTrim(p->sSettDate);
		AllTrim(p->sMyNbrType);
		AllTrim(p->sMy3gFlag);
		AllTrim(p->sMyCarrID);
		AllTrim(p->sServFlag);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*批量数据结构缓冲写入AN_SETT_TOP_500_LT*/
int EInsertStructToAnSettTop500Lt(struct AnSettTop500LtStruct *p,
	int iInsertFlag,struct AnSettTop500LtStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSettLatnID[iCurPos],		p->sSettLatnID);
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asMsisdn[iCurPos],		p->sMsisdn);
		strcpy(pTarget->asSettDate[iCurPos],		p->sSettDate);

		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiDuration[iCurPos]=			p->iDuration;
		pTarget->aiSettDuration[iCurPos]=		p->iSettDuration;
		pTarget->aiSettFee[iCurPos]=			p->iSettFee;

		strcpy(pTarget->asMyNbrType[iCurPos],		p->sMyNbrType);
		strcpy(pTarget->asMy3gFlag[iCurPos],		p->sMy3gFlag);
		strcpy(pTarget->asMyCarrID[iCurPos],		p->sMyCarrID);
		strcpy(pTarget->asServFlag[iCurPos],		p->sServFlag);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==AN_SETT_TOP_500_LT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_LATN_ID,\n\
				CALL_TYPE,\n\
				HOME_AREA_CODE,\n\
				MSISDN,\n\
				SETT_DATE,\n\
				CNT,\n\
				DURATION,\n\
				SETT_DURATION,\n\
				SETT_FEE,\n\
				MY_NBR_TYPE,\n\
				MY_3G_FLAG,\n\
				MY_CARR_ID,\n\
				SERV_FLAG)\n\
			VALUES (\n\
				:asSettLatnID,\n\
				:asCallType,\n\
				:asHomeAreaCode,\n\
				:asMsisdn,\n\
				:asSettDate,\n\
				:aiCnt,\n\
				:aiDuration,\n\
				:aiSettDuration,\n\
				:aiSettFee,\n\
				:asMyNbrType,\n\
				:asMy3gFlag,\n\
				:asMyCarrID,\n\
				:asServFlag\n\
			)",sTableName);

		/* EXEC SQL PREPARE AN_SETT_TOP_500_LTTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1858;
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


		if(CheckSqlResult("Prepare insert statement AN_SETT_TOP_500_LT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE AN_SETT_TOP_500_LTTRG USING
				:pTarget->asSettLatnID,
				:pTarget->asCallType,
				:pTarget->asHomeAreaCode,
				:pTarget->asMsisdn,
				:pTarget->asSettDate,
				:pTarget->aiCnt,
				:pTarget->aiDuration,
				:pTarget->aiSettDuration,
				:pTarget->aiSettFee,
				:pTarget->asMyNbrType,
				:pTarget->asMy3gFlag,
				:pTarget->asMyCarrID,
				:pTarget->asServFlag; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1877;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSettLatnID);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asMsisdn);
  sqlstm.sqhstl[3] = (unsigned long )16;
  sqlstm.sqhsts[3] = (         int  )16;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asSettDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiSettDuration);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->aiSettFee);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asMyNbrType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asMy3gFlag);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asMyCarrID);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asServFlag);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into AN_SETT_TOP_500_LT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*参数部分*/

/*批量数据动态从T_ST_REPORT_GROUP_MEMBER中用结构缓冲方式取数据*/
int EGetTStReportGroupMemberToStruct(struct TStReportGroupMemberStruct *p,
	struct TStReportGroupMemberStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(PROVINCE_ID,0),\n\
				nvl(GROUP_ID,0),\n\
				nvl(MEMBER_TYPE,' '),\n\
				nvl(MEMBER_VALUE,' '),\n\
				nvl(MEMBER_ORDER,0),\n\
				nvl(REPORT_SEQ,0),\n\
				nvl(RATE_DESC,' '),\n\
				nvl(SETTLE_DESC,' '),\n\
				nvl(MEMBER_NAME,' '),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(OPP_CARRIER_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE T_ST_REPORT_GROUP_MEMBERSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1944;
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


		CheckSqlError(" PREPARE T_ST_REPORT_GROUP_MEMBERSCR T_ST_REPORT_GROUP_MEMBERCR");

		/* EXEC SQL DECLARE T_ST_REPORT_GROUP_MEMBERCR CURSOR FOR T_ST_REPORT_GROUP_MEMBERSCR; */ 

		CheckSqlError("Declare T_ST_REPORT_GROUP_MEMBERCR");

		/* EXEC SQL OPEN T_ST_REPORT_GROUP_MEMBERCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1963;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open T_ST_REPORT_GROUP_MEMBERCR;");


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

		/* EXEC SQL CLOSE T_ST_REPORT_GROUP_MEMBERCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1978;
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
		/* EXEC SQL FETCH T_ST_REPORT_GROUP_MEMBERCR INTO
			:pSource->aiProvinceID,
			:pSource->aiGroupID,
			:pSource->asMemberType,
			:pSource->asMemberValue,
			:pSource->aiMemberOrder,
			:pSource->aiReportSeq,
			:pSource->asRateDesc,
			:pSource->asSettleDesc,
			:pSource->asMemberName,
			:pSource->asNetType,
			:pSource->asOppCarrierID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1993;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiProvinceID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asMemberType);
  sqlstm.sqhstl[2] = (unsigned long )21;
  sqlstm.sqhsts[2] = (         int  )21;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asMemberValue);
  sqlstm.sqhstl[3] = (unsigned long )21;
  sqlstm.sqhsts[3] = (         int  )21;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiMemberOrder);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiReportSeq);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asRateDesc);
  sqlstm.sqhstl[6] = (unsigned long )257;
  sqlstm.sqhsts[6] = (         int  )257;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSettleDesc);
  sqlstm.sqhstl[7] = (unsigned long )257;
  sqlstm.sqhsts[7] = (         int  )257;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asMemberName);
  sqlstm.sqhstl[8] = (unsigned long )201;
  sqlstm.sqhsts[8] = (         int  )201;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[9] = (unsigned long )3;
  sqlstm.sqhsts[9] = (         int  )3;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asOppCarrierID);
  sqlstm.sqhstl[10] = (unsigned long )5;
  sqlstm.sqhsts[10] = (         int  )5;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
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


		CheckSqlError("Fetch T_ST_REPORT_GROUP_MEMBERCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE T_ST_REPORT_GROUP_MEMBERCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2052;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=T_ST_REPORT_GROUP_MEMBER_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iProvinceID=			pSource->aiProvinceID[iCurPos];
		p->iGroupID=			pSource->aiGroupID[iCurPos];

		strcpy(p->sMemberType,		pSource->asMemberType[iCurPos]);
		strcpy(p->sMemberValue,		pSource->asMemberValue[iCurPos]);

		p->iMemberOrder=		pSource->aiMemberOrder[iCurPos];
		p->iReportSeq=			pSource->aiReportSeq[iCurPos];

		strcpy(p->sRateDesc,		pSource->asRateDesc[iCurPos]);
		strcpy(p->sSettleDesc,		pSource->asSettleDesc[iCurPos]);
		strcpy(p->sMemberName,		pSource->asMemberName[iCurPos]);
		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);
		strcpy(p->sOppCarrierID,	pSource->asOppCarrierID[iCurPos]);

		AllTrim(p->sMemberType);
		AllTrim(p->sMemberValue);
		AllTrim(p->sRateDesc);
		AllTrim(p->sSettleDesc);
		AllTrim(p->sMemberName);
		AllTrim(p->sNetType);
		AllTrim(p->sOppCarrierID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表T_ST_REPORT_GROUP_MEMBER的链表释放函数**/
void DestroyTStReportGroupMember(struct TStReportGroupMemberStruct *ptHead)
{
	struct TStReportGroupMemberStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTStReportGroupMember(struct TStReportGroupMemberStruct **pptHead)
{
	int iCnt=0;
	static struct TStReportGroupMemberStruct *pTemp,*ptHead=NULL;
	struct TStReportGroupMemberStruct Temp;
	struct TStReportGroupMemberStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTStReportGroupMember(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TStReportGroupMemberStructIn));
	sprintf(TempIn.sTableName,"param.T_ST_REPORT_GROUP_MEMBER");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTStReportGroupMemberToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TStReportGroupMemberStruct*)
			malloc(sizeof(struct TStReportGroupMemberStruct)))==NULL){

			DestroyTStReportGroupMember(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TStReportGroupMemberStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表T_ST_REPORT_GROUP_MEMBER记录数%d",iCnt);
	}

	WriteProcMsg("加载表T_ST_REPORT_GROUP_MEMBER完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TICKET_TYPE_MAP中用结构缓冲方式取数据*/
int EGetTicketTypeMapToStruct(struct TicketTypeMapStruct *p,
	struct TicketTypeMapStructIn *pSource)
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
				nvl(PROD_ID,' '),\n\
				nvl(IN_TRUNK_CARR_ID,' '),\n\
				nvl(OUT_TRUNK_CARR_ID,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(FLAG,' '),\n\
				nvl(FEE_TYPE,' '),\n\
				nvl(PROD_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_TYPE_MAPSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2067;
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


		CheckSqlError(" PREPARE TICKET_TYPE_MAPSCR TICKET_TYPE_MAPCR");

		/* EXEC SQL DECLARE TICKET_TYPE_MAPCR CURSOR FOR TICKET_TYPE_MAPSCR; */ 

		CheckSqlError("Declare TICKET_TYPE_MAPCR");

		/* EXEC SQL OPEN TICKET_TYPE_MAPCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2086;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_TYPE_MAPCR;");


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

		/* EXEC SQL CLOSE TICKET_TYPE_MAPCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2101;
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
		/* EXEC SQL FETCH TICKET_TYPE_MAPCR INTO
			:pSource->aiReportItemID,
			:pSource->asProdID,
			:pSource->asInTrunkCarrID,
			:pSource->asOutTrunkCarrID,
			:pSource->asCallType,
			:pSource->asFlag,
			:pSource->asFeeType,
			:pSource->asProdType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2116;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asInTrunkCarrID);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )2;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asOutTrunkCarrID);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFlag);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asFeeType);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asProdType);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
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


		CheckSqlError("Fetch TICKET_TYPE_MAPCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_TYPE_MAPCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2163;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_TYPE_MAP_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sInTrunkCarrID,	pSource->asInTrunkCarrID[iCurPos]);
		strcpy(p->sOutTrunkCarrID,	pSource->asOutTrunkCarrID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sFlag,		pSource->asFlag[iCurPos]);
		strcpy(p->sFeeType,		pSource->asFeeType[iCurPos]);
		strcpy(p->sProdType,		pSource->asProdType[iCurPos]);

		AllTrim(p->sProdID);
		AllTrim(p->sInTrunkCarrID);
		AllTrim(p->sOutTrunkCarrID);
		AllTrim(p->sCallType);
		AllTrim(p->sFlag);
		AllTrim(p->sFeeType);
		AllTrim(p->sProdType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TICKET_TYPE_MAP的链表释放函数**/
void DestroyTicketTypeMap(struct TicketTypeMapStruct *ptHead)
{
	struct TicketTypeMapStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketTypeMap(struct TicketTypeMapStruct **pptHead)
{
	int iCnt=0;
	static struct TicketTypeMapStruct *pTemp,*ptHead=NULL;
	struct TicketTypeMapStruct Temp;
	struct TicketTypeMapStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketTypeMap(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TicketTypeMapStructIn));
	sprintf(TempIn.sTableName,"param.TICKET_TYPE_MAP");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketTypeMapToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketTypeMapStruct*)
			malloc(sizeof(struct TicketTypeMapStruct)))==NULL){

			DestroyTicketTypeMap(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketTypeMapStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_TYPE_MAP记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_TYPE_MAP完毕总记录数%d",iCnt);

	return iCnt;
}


/*批量数据动态从NBR_TYPE_FILTER_CFG中用结构缓冲方式取数据*/
int EGetNbrTypeFilterCfgToStruct(struct NbrTypeFilterCfgStruct *p,
	struct NbrTypeFilterCfgStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(NBR_TYPE,' '),\n\
				nvl(TYPE_NAME,' '),\n\
				nvl(REMARK,' '),\n\
				nvl(CARRIER_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE NBR_TYPE_FILTER_CFGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2178;
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


		CheckSqlError(" PREPARE NBR_TYPE_FILTER_CFGSCR NBR_TYPE_FILTER_CFGCR");

		/* EXEC SQL DECLARE NBR_TYPE_FILTER_CFGCR CURSOR FOR NBR_TYPE_FILTER_CFGSCR; */ 

		CheckSqlError("Declare NBR_TYPE_FILTER_CFGCR");

		/* EXEC SQL OPEN NBR_TYPE_FILTER_CFGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2197;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open NBR_TYPE_FILTER_CFGCR;");


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

		/* EXEC SQL CLOSE NBR_TYPE_FILTER_CFGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2212;
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
		/* EXEC SQL FETCH NBR_TYPE_FILTER_CFGCR INTO
			:pSource->asNbrType,
			:pSource->asTypeName,
			:pSource->asRemark,
			:pSource->asCarrierID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2227;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asNbrType);
  sqlstm.sqhstl[0] = (unsigned long )2;
  sqlstm.sqhsts[0] = (         int  )2;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asTypeName);
  sqlstm.sqhstl[1] = (unsigned long )51;
  sqlstm.sqhsts[1] = (         int  )51;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[2] = (unsigned long )401;
  sqlstm.sqhsts[2] = (         int  )401;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCarrierID);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
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


		CheckSqlError("Fetch NBR_TYPE_FILTER_CFGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE NBR_TYPE_FILTER_CFGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2258;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=NBR_TYPE_FILTER_CFG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sNbrType,	pSource->asNbrType[iCurPos]);
		strcpy(p->sTypeName,	pSource->asTypeName[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);
		strcpy(p->sCarrierID,	pSource->asCarrierID[iCurPos]);

		AllTrim(p->sNbrType);
		AllTrim(p->sTypeName);
		AllTrim(p->sRemark);
		AllTrim(p->sCarrierID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表NBR_TYPE_FILTER_CFG的链表释放函数**/
void DestroyNbrTypeFilterCfg(struct NbrTypeFilterCfgStruct *ptHead)
{
	struct NbrTypeFilterCfgStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}

int InitNbrTypeFilterCfg(struct NbrTypeFilterCfgStruct **pptHead)
{
	int iCnt=0;
	static struct NbrTypeFilterCfgStruct *pTemp,*ptHead=NULL;
	struct NbrTypeFilterCfgStruct Temp;
	struct NbrTypeFilterCfgStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyNbrTypeFilterCfg(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct NbrTypeFilterCfgStructIn));
	sprintf(TempIn.sTableName,"param.NBR_TYPE_FILTER_CFG");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetNbrTypeFilterCfgToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct NbrTypeFilterCfgStruct*)
			malloc(sizeof(struct NbrTypeFilterCfgStruct)))==NULL){

			DestroyNbrTypeFilterCfg(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct NbrTypeFilterCfgStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表NBR_TYPE_FILTER_CFG记录数%d",iCnt);
	}

	WriteProcMsg("加载表NBR_TYPE_FILTER_CFG完毕总记录数%d",iCnt);

	return iCnt;
}
void mvitem_fmttemplateydgwue(struct FTTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct TTemplateYdGwUeStruct));

		strncpy(po->sUsageEventID,		pi->sUsageEventID,18);
		strncpy(po->sProdID,			pi->sProdID,10);
		strncpy(po->sStartTime,			pi->sStartTime,14);
		strncpy(po->sEndTime,			pi->sEndTime,14);
		strncpy(po->sRateTime,			pi->sRateTime,14);
		strncpy(po->sOperationTypeID,		pi->sOperationTypeID,8);
		strncpy(po->sCallingNumber,		pi->sCallingNumber,30);
		strncpy(po->sCalledNumber,		pi->sCalledNumber,30);
		strncpy(po->sBilledNumber,		pi->sBilledNumber,30);
		strncpy(po->sThirdNumber,		pi->sThirdNumber,30);

		strncpy(sTemp,		pi->sCallingAreaID,8);sTemp[8]=0;
		po->iCallingAreaID=atoi(sTemp);
		strncpy(sTemp,		pi->sCalledAreaID,8);sTemp[8]=0;
		po->iCalledAreaID=atoi(sTemp);

		strncpy(po->sInTrunkNumber,		pi->sInTrunkNumber,20);
		strncpy(po->sOutTrunkNumber,		pi->sOutTrunkNumber,20);

		strncpy(sTemp,		pi->sRawUnitType,4);sTemp[4]=0;
		po->iRawUnitType=atoi(sTemp);

		strncpy(po->sRawUnits,			pi->sRawUnits,18);

		strncpy(sTemp,		pi->sRateUnitType,4);sTemp[4]=0;
		po->iRateUnitType=atoi(sTemp);

		strncpy(po->sIsFree,			pi->sIsFree,20);

		strncpy(sTemp,			pi->sRateUnits,8);sTemp[8]=0;
		po->iRateUnits=atoi(sTemp);

		strncpy(po->sCallingAreaCode,		pi->sCallingAreaCode,10);
		strncpy(po->sCalledAreaCode,		pi->sCalledAreaCode,10);
		strncpy(po->sCallingRoamNumber,		pi->sCallingRoamNumber,30);
		strncpy(po->sCalledRoamNumber,		pi->sCalledRoamNumber,30);
		strncpy(po->sCallingRoamAreaCode,	pi->sCallingRoamAreaCode,10);
		strncpy(po->sCalledRoamAreaCode,	pi->sCalledRoamAreaCode,10);
		strncpy(po->sTotalDueAmount,		pi->sTotalDueAmount,18);

		strncpy(sTemp,		pi->sProdInstID,8);sTemp[8]=0;
		po->iProdInstID=atoi(sTemp);
		strncpy(sTemp,			pi->sRateID,8);sTemp[8]=0;
		po->iRateID=atoi(sTemp);

		strncpy(po->sUpFlux,			pi->sUpFlux,18);
		strncpy(po->sDuration,			pi->sDuration,18);

		strncpy(sTemp,			pi->sCityID,8);sTemp[8]=0;
		po->iCityID=atoi(sTemp);

		strncpy(po->sDownFlux,			pi->sDownFlux,18);
		strncpy(po->sFileName,			pi->sFileName,60);
		strncpy(po->sTotalFlux,			pi->sTotalFlux,18);
		strncpy(po->sStatus,			pi->sStatus,3);

		strncpy(sTemp,		pi->sBillCycleSeq,8);sTemp[8]=0;
		po->iBillCycleSeq=atoi(sTemp);

		strncpy(po->sCurrBalance,		pi->sCurrBalance,18);

		strncpy(sTemp,		pi->sCreateCycleSeq,8);sTemp[8]=0;
		po->iCreateCycleSeq=atoi(sTemp);

		strncpy(po->sRateKey1,			pi->sRateKey1,30);
		strncpy(po->sRateKey2,			pi->sRateKey2,30);
		strncpy(po->sRateKey3,			pi->sRateKey3,30);

		strncpy(sTemp,		pi->sPureCycleSeq,8);sTemp[8]=0;
		po->iPureCycleSeq=atoi(sTemp);
		strncpy(sTemp,			pi->sDirection,1);sTemp[1]=0;
		po->iDirection=atoi(sTemp);
		strncpy(sTemp,		pi->sFileClassID,8);sTemp[8]=0;
		po->iFileClassID=atoi(sTemp);

		strncpy(po->sExceptionType,		pi->sExceptionType,5);
		strncpy(po->sOrigUsageTypeID,		pi->sOrigUsageTypeID,12);

		strncpy(sTemp,		pi->sTotalDueUnits,8);sTemp[8]=0;
		po->iTotalDueUnits=atoi(sTemp);

		strncpy(po->sStlAmount,			pi->sStlAmount,18);
		strncpy(po->sPostFlag,			pi->sPostFlag,4);

		strncpy(sTemp,			pi->sIsPrepay,1);sTemp[1]=0;
		po->iIsPrepay=atoi(sTemp);
		strncpy(sTemp,			pi->sFileID,9);sTemp[9]=0;
		po->iFileID=atoi(sTemp);
		strncpy(sTemp,		pi->sParentFileID,9);sTemp[9]=0;
		po->iParentFileID=atoi(sTemp);

		strncpy(po->sTableName,			pi->sTableName,30);
		strncpy(po->sCallingCompanyID,		pi->sCallingCompanyID,18);
		strncpy(po->sCalledCompanyID,		pi->sCalledCompanyID,18);
		strncpy(po->sSwitchCompanyID,		pi->sSwitchCompanyID,18);
		strncpy(po->sProvinceID,		pi->sProvinceID,20);
		strncpy(po->sDurationMinnum,		pi->sDurationMinnum,18);
		strncpy(po->sDurationSec6,		pi->sDurationSec6,18);
		strncpy(po->sInTrunkGroup,		pi->sInTrunkGroup,15);
		strncpy(po->sOutTrunkGroup,		pi->sOutTrunkGroup,15);
		strncpy(po->sCallingNumberCompanyID,	pi->sCallingNumberCompanyID,18);
		strncpy(po->sCalledNumberCompanyID,	pi->sCalledNumberCompanyID,18);
		strncpy(po->sCallingGroupID,		pi->sCallingGroupID,15);
		strncpy(po->sCalledGroupID,		pi->sCalledGroupID,15);
		strncpy(po->sStlObject,			pi->sStlObject,18);
		strncpy(po->sProdPropID,		pi->sProdPropID,18);
		strncpy(po->sCallingSubType,		pi->sCallingSubType,18);
		strncpy(po->sCalledSubType,		pi->sCalledSubType,18);

		strncpy(sTemp,		pi->sStlDirection,1);sTemp[1]=0;
		po->iStlDirection=atoi(sTemp);

		strncpy(po->sPreCallType,		pi->sPreCallType,30);
		strncpy(po->sTurnCode,			pi->sTurnCode,50);
		strncpy(po->sTurnCodeCompanyID,		pi->sTurnCodeCompanyID,10);
		strncpy(po->sTurnCodeProvinceID,	pi->sTurnCodeProvinceID,20);

		strncpy(sTemp,		pi->sTurnCodeCityID,8);sTemp[8]=0;
		po->iTurnCodeCityID=atoi(sTemp);

		strncpy(po->sTurnCodeOperationTypeGrade,pi->sTurnCodeOperationTypeGrade,30);
		strncpy(po->sTurnType,			pi->sTurnType,30);
		strncpy(po->sTurnCdrID,			pi->sTurnCdrID,4);
		strncpy(po->sSecondCallingNumber,	pi->sSecondCallingNumber,30);
		strncpy(po->sSecondCallingAreaCode,	pi->sSecondCallingAreaCode,10);
		strncpy(po->sSecondCallingGroupID,	pi->sSecondCallingGroupID,30);
		strncpy(po->sSecondCallingCompanyID,	pi->sSecondCallingCompanyID,10);
		strncpy(po->sPreCallParentCdrID,	pi->sPreCallParentCdrID,20);
		strncpy(po->sPreCallSubCdrID,		pi->sPreCallSubCdrID,20);
		strncpy(po->sPreCallSubCdrNum,		pi->sPreCallSubCdrNum,4);
		strncpy(po->sPreCallSubCdrSeq,		pi->sPreCallSubCdrSeq,10);
		strncpy(po->sPreCallUsageEventID,	pi->sPreCallUsageEventID,18);
		strncpy(po->sTurnParentCdrID,		pi->sTurnParentCdrID,20);
		strncpy(po->sTurnSubCdrID,		pi->sTurnSubCdrID,20);
		strncpy(po->sTurnSubCdrNum,		pi->sTurnSubCdrNum,4);
		strncpy(po->sTurnSubCdrSeq,		pi->sTurnSubCdrSeq,10);
		strncpy(po->sTurnUsageEventID,		pi->sTurnUsageEventID,18);
		strncpy(po->sInTrunkGenre,		pi->sInTrunkGenre,20);
		strncpy(po->sOutTrunkGenre,		pi->sOutTrunkGenre,20);
		strncpy(po->sInTrunkNetType,		pi->sInTrunkNetType,20);
		strncpy(po->sOutTrunkNetType,		pi->sOutTrunkNetType,20);
		strncpy(po->sCallingNumberType,		pi->sCallingNumberType,20);
		strncpy(po->sCalledNumberType,		pi->sCalledNumberType,20);
		strncpy(po->sCallingDomainID,		pi->sCallingDomainID,20);
		strncpy(po->sCalledDomainID,		pi->sCalledDomainID,20);
		strncpy(po->sSecondSubType,		pi->sSecondSubType,20);
		strncpy(po->sSecondCallingRoamnumber,	pi->sSecondCallingRoamnumber,30);
		strncpy(po->sViewCall,			pi->sViewCall,10);

		AllTrim(po->sUsageEventID);
		AllTrim(po->sProdID);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sRateTime);
		AllTrim(po->sOperationTypeID);
		AllTrim(po->sCallingNumber);
		AllTrim(po->sCalledNumber);
		AllTrim(po->sBilledNumber);
		AllTrim(po->sThirdNumber);
		AllTrim(po->sInTrunkNumber);
		AllTrim(po->sOutTrunkNumber);
		AllTrim(po->sRawUnits);
		AllTrim(po->sIsFree);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCalledAreaCode);
		AllTrim(po->sCallingRoamNumber);
		AllTrim(po->sCalledRoamNumber);
		AllTrim(po->sCallingRoamAreaCode);
		AllTrim(po->sCalledRoamAreaCode);
		AllTrim(po->sTotalDueAmount);
		AllTrim(po->sUpFlux);
		AllTrim(po->sDuration);
		AllTrim(po->sDownFlux);
		AllTrim(po->sFileName);
		AllTrim(po->sTotalFlux);
		AllTrim(po->sStatus);
		AllTrim(po->sCurrBalance);
		AllTrim(po->sRateKey1);
		AllTrim(po->sRateKey2);
		AllTrim(po->sRateKey3);
		AllTrim(po->sExceptionType);
		AllTrim(po->sOrigUsageTypeID);
		AllTrim(po->sStlAmount);
		AllTrim(po->sPostFlag);
		AllTrim(po->sTableName);
		AllTrim(po->sCallingCompanyID);
		AllTrim(po->sCalledCompanyID);
		AllTrim(po->sSwitchCompanyID);
		AllTrim(po->sProvinceID);
		AllTrim(po->sDurationMinnum);
		AllTrim(po->sDurationSec6);
		AllTrim(po->sInTrunkGroup);
		AllTrim(po->sOutTrunkGroup);
		AllTrim(po->sCallingNumberCompanyID);
		AllTrim(po->sCalledNumberCompanyID);
		AllTrim(po->sCallingGroupID);
		AllTrim(po->sCalledGroupID);
		AllTrim(po->sStlObject);
		AllTrim(po->sProdPropID);
		AllTrim(po->sCallingSubType);
		AllTrim(po->sCalledSubType);
		AllTrim(po->sPreCallType);
		AllTrim(po->sTurnCode);
		AllTrim(po->sTurnCodeCompanyID);
		AllTrim(po->sTurnCodeProvinceID);
		AllTrim(po->sTurnCodeOperationTypeGrade);
		AllTrim(po->sTurnType);
		AllTrim(po->sTurnCdrID);
		AllTrim(po->sSecondCallingNumber);
		AllTrim(po->sSecondCallingAreaCode);
		AllTrim(po->sSecondCallingGroupID);
		AllTrim(po->sSecondCallingCompanyID);
		AllTrim(po->sPreCallParentCdrID);
		AllTrim(po->sPreCallSubCdrID);
		AllTrim(po->sPreCallSubCdrNum);
		AllTrim(po->sPreCallSubCdrSeq);
		AllTrim(po->sPreCallUsageEventID);
		AllTrim(po->sTurnParentCdrID);
		AllTrim(po->sTurnSubCdrID);
		AllTrim(po->sTurnSubCdrNum);
		AllTrim(po->sTurnSubCdrSeq);
		AllTrim(po->sTurnUsageEventID);
		AllTrim(po->sInTrunkGenre);
		AllTrim(po->sOutTrunkGenre);
		AllTrim(po->sInTrunkNetType);
		AllTrim(po->sOutTrunkNetType);
		AllTrim(po->sCallingNumberType);
		AllTrim(po->sCalledNumberType);
		AllTrim(po->sCallingDomainID);
		AllTrim(po->sCalledDomainID);
		AllTrim(po->sSecondSubType);
		AllTrim(po->sSecondCallingRoamnumber);
		AllTrim(po->sViewCall);
}

/*批量数据动态从T_TEMPLATE_YD_GW_UE中用结构缓冲方式取数据*/
int EGetTTemplateYdGwUeToStruct(struct TTemplateYdGwUeStruct *p,
	struct TTemplateYdGwUeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(USAGE_EVENT_ID,' '),\n\
				nvl(PROD_ID,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(END_TIME,' '),\n\
				nvl(RATE_TIME,' '),\n\
				nvl(CALLING_NUMBER,' '),\n\
				nvl(CALLED_NUMBER,' '),\n\
				nvl(BILLED_NUMBER,' '),\n\
				nvl(IN_TRUNK_NUMBER,' '),\n\
				nvl(OUT_TRUNK_NUMBER,' '),\n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				to_char(nvl(TOTAL_DUE_AMOUNT,0)),\n\
				to_char(nvl(DURATION,0)),\n\
				nvl(CITY_ID,0),\n\
				nvl(IN_TRUNK_GROUP,' '),\n\
				nvl(OUT_TRUNK_GROUP,' '),\n\
				nvl(CALLING_GROUP_ID,' '),\n\
				nvl(CALLED_GROUP_ID,' '),\n\
				nvl(IN_TRUNK_GENRE,' '),\n\
				nvl(OUT_TRUNK_GENRE,' '),\n\
				nvl(IN_TRUNK_NET_TYPE,' '),\n\
				nvl(OUT_TRUNK_NET_TYPE,' '),\n\
				nvl(CALLING_NUMBER_TYPE,' '),\n\
				nvl(CALLED_NUMBER_TYPE,' '),\n\
				nvl(RATE_UNIT_TYPE,0),\n\
				nvl(RATE_UNITS,0),\n\
				nvl(GROUP_ID,'0')\n\
			FROM %s %s",sTableName,sCondition);
			
		/* EXEC SQL PREPARE T_TEMPLATE_YD_GW_UESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2273;
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


		CheckSqlError(" PREPARE T_TEMPLATE_YD_GW_UESCR T_TEMPLATE_YD_GW_UECR");

		/* EXEC SQL DECLARE T_TEMPLATE_YD_GW_UECR CURSOR FOR T_TEMPLATE_YD_GW_UESCR; */ 

		CheckSqlError("Declare T_TEMPLATE_YD_GW_UECR");

		/* EXEC SQL OPEN T_TEMPLATE_YD_GW_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2292;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open T_TEMPLATE_YD_GW_UECR;");


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

		/* EXEC SQL CLOSE T_TEMPLATE_YD_GW_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2307;
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
		/* EXEC SQL FETCH T_TEMPLATE_YD_GW_UECR INTO
			:pSource->asUsageEventID,
			:pSource->asProdID,
			:pSource->asStartTime,
			:pSource->asEndTime,
			:pSource->asRateTime,
			:pSource->asCallingNumber,
			:pSource->asCalledNumber,
			:pSource->asBilledNumber,
			:pSource->asInTrunkNumber,
			:pSource->asOutTrunkNumber,
			:pSource->asCallingAreaCode,
			:pSource->asCalledAreaCode,
			:pSource->asTotalDueAmount,
			:pSource->asDuration,
			:pSource->aiCityID,
			:pSource->asInTrunkGroup,
			:pSource->asOutTrunkGroup,
			:pSource->asCallingGroupID,
			:pSource->asCalledGroupID,
			:pSource->asInTrunkGenre,
			:pSource->asOutTrunkGenre,
			:pSource->asInTrunkNetType,
			:pSource->asOutTrunkNetType,
			:pSource->asCallingNumberType,
			:pSource->asCalledNumberType,
			:pSource->aiRateUnitType,
			:pSource->aiRateUnits,
			:pSource->asGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2322;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asUsageEventID);
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )19;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asEndTime);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )15;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asRateTime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCallingNumber);
  sqlstm.sqhstl[5] = (unsigned long )31;
  sqlstm.sqhsts[5] = (         int  )31;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asCalledNumber);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )31;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asBilledNumber);
  sqlstm.sqhstl[7] = (unsigned long )31;
  sqlstm.sqhsts[7] = (         int  )31;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asInTrunkNumber);
  sqlstm.sqhstl[8] = (unsigned long )21;
  sqlstm.sqhsts[8] = (         int  )21;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asOutTrunkNumber);
  sqlstm.sqhstl[9] = (unsigned long )21;
  sqlstm.sqhsts[9] = (         int  )21;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )11;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )11;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asTotalDueAmount);
  sqlstm.sqhstl[12] = (unsigned long )19;
  sqlstm.sqhsts[12] = (         int  )19;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asDuration);
  sqlstm.sqhstl[13] = (unsigned long )19;
  sqlstm.sqhsts[13] = (         int  )19;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiCityID);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asInTrunkGroup);
  sqlstm.sqhstl[15] = (unsigned long )16;
  sqlstm.sqhsts[15] = (         int  )16;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asOutTrunkGroup);
  sqlstm.sqhstl[16] = (unsigned long )16;
  sqlstm.sqhsts[16] = (         int  )16;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asCallingGroupID);
  sqlstm.sqhstl[17] = (unsigned long )16;
  sqlstm.sqhsts[17] = (         int  )16;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asCalledGroupID);
  sqlstm.sqhstl[18] = (unsigned long )16;
  sqlstm.sqhsts[18] = (         int  )16;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asInTrunkGenre);
  sqlstm.sqhstl[19] = (unsigned long )21;
  sqlstm.sqhsts[19] = (         int  )21;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asOutTrunkGenre);
  sqlstm.sqhstl[20] = (unsigned long )21;
  sqlstm.sqhsts[20] = (         int  )21;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asInTrunkNetType);
  sqlstm.sqhstl[21] = (unsigned long )21;
  sqlstm.sqhsts[21] = (         int  )21;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asOutTrunkNetType);
  sqlstm.sqhstl[22] = (unsigned long )21;
  sqlstm.sqhsts[22] = (         int  )21;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asCallingNumberType);
  sqlstm.sqhstl[23] = (unsigned long )21;
  sqlstm.sqhsts[23] = (         int  )21;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asCalledNumberType);
  sqlstm.sqhstl[24] = (unsigned long )21;
  sqlstm.sqhsts[24] = (         int  )21;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->aiRateUnitType);
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )sizeof(int);
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->aiRateUnits);
  sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[26] = (         int  )sizeof(int);
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[27] = (unsigned long )3;
  sqlstm.sqhsts[27] = (         int  )3;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
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


		CheckSqlError("Fetch T_TEMPLATE_YD_GW_UECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE T_TEMPLATE_YD_GW_UECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2449;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=T_TEMPLATE_YD_GW_UE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sUsageEventID,		pSource->asUsageEventID[iCurPos]);
		strcpy(p->sProdID,			pSource->asProdID[iCurPos]);
		strcpy(p->sStartTime,			pSource->asStartTime[iCurPos]);
		strcpy(p->sEndTime,			pSource->asEndTime[iCurPos]);
		strcpy(p->sRateTime,			pSource->asRateTime[iCurPos]);
		strcpy(p->sCallingNumber,		pSource->asCallingNumber[iCurPos]);
		strcpy(p->sCalledNumber,		pSource->asCalledNumber[iCurPos]);
		strcpy(p->sBilledNumber,		pSource->asBilledNumber[iCurPos]);
		
		p->iCallingAreaID=			pSource->aiCallingAreaID[iCurPos];
		p->iCalledAreaID=			pSource->aiCalledAreaID[iCurPos];

		strcpy(p->sInTrunkNumber,		pSource->asInTrunkNumber[iCurPos]);
		strcpy(p->sOutTrunkNumber,		pSource->asOutTrunkNumber[iCurPos]);

		strcpy(p->sCallingAreaCode,		pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCalledAreaCode,		pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sCallingRoamNumber,		pSource->asCallingRoamNumber[iCurPos]);
		strcpy(p->sCalledRoamNumber,		pSource->asCalledRoamNumber[iCurPos]);
		strcpy(p->sCallingRoamAreaCode,		pSource->asCallingRoamAreaCode[iCurPos]);
		strcpy(p->sCalledRoamAreaCode,		pSource->asCalledRoamAreaCode[iCurPos]);
		strcpy(p->sTotalDueAmount,		pSource->asTotalDueAmount[iCurPos]);

		strcpy(p->sDuration,			pSource->asDuration[iCurPos]);

		p->iCityID=				pSource->aiCityID[iCurPos];

		strcpy(p->sInTrunkGroup,		pSource->asInTrunkGroup[iCurPos]);
		strcpy(p->sOutTrunkGroup,		pSource->asOutTrunkGroup[iCurPos]);
		strcpy(p->sCallingGroupID,		pSource->asCallingGroupID[iCurPos]);
		strcpy(p->sCalledGroupID,		pSource->asCalledGroupID[iCurPos]);
		strcpy(p->sInTrunkGenre,		pSource->asInTrunkGenre[iCurPos]);
		strcpy(p->sOutTrunkGenre,		pSource->asOutTrunkGenre[iCurPos]);
		strcpy(p->sInTrunkNetType,		pSource->asInTrunkNetType[iCurPos]);
		strcpy(p->sOutTrunkNetType,		pSource->asOutTrunkNetType[iCurPos]);
		strcpy(p->sCallingNumberType,		pSource->asCallingNumberType[iCurPos]);
		strcpy(p->sCalledNumberType,		pSource->asCalledNumberType[iCurPos]);
		p->iRateUnitType=			pSource->aiRateUnitType[iCurPos];
		p->iRateUnits=				pSource->aiRateUnits[iCurPos];
		strcpy(p->sGroupID,			pSource->asGroupID[iCurPos]);

		AllTrim(p->sUsageEventID);
		AllTrim(p->sProdID);
		AllTrim(p->sStartTime);
		AllTrim(p->sEndTime);
		AllTrim(p->sRateTime);
		AllTrim(p->sOperationTypeID);
		AllTrim(p->sCallingNumber);
		AllTrim(p->sCalledNumber);
		AllTrim(p->sBilledNumber);
		AllTrim(p->sThirdNumber);
		AllTrim(p->sInTrunkNumber);
		AllTrim(p->sOutTrunkNumber);
		AllTrim(p->sRawUnits);
		AllTrim(p->sIsFree);
		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sCallingRoamNumber);
		AllTrim(p->sCalledRoamNumber);
		AllTrim(p->sCallingRoamAreaCode);
		AllTrim(p->sCalledRoamAreaCode);
		AllTrim(p->sTotalDueAmount);
		AllTrim(p->sUpFlux);
		AllTrim(p->sDuration);
		AllTrim(p->sDownFlux);
		AllTrim(p->sFileName);
		AllTrim(p->sTotalFlux);
		AllTrim(p->sStatus);
		AllTrim(p->sCurrBalance);
		AllTrim(p->sRateKey1);
		AllTrim(p->sRateKey2);
		AllTrim(p->sRateKey3);
		AllTrim(p->sExceptionType);
		AllTrim(p->sOrigUsageTypeID);
		AllTrim(p->sStlAmount);
		AllTrim(p->sPostFlag);
		AllTrim(p->sTableName);
		AllTrim(p->sCallingCompanyID);
		AllTrim(p->sCalledCompanyID);
		AllTrim(p->sSwitchCompanyID);
		AllTrim(p->sProvinceID);
		AllTrim(p->sDurationMinnum);
		AllTrim(p->sDurationSec6);
		AllTrim(p->sInTrunkGroup);
		AllTrim(p->sOutTrunkGroup);
		AllTrim(p->sCallingNumberCompanyID);
		AllTrim(p->sCalledNumberCompanyID);
		AllTrim(p->sCallingGroupID);
		AllTrim(p->sCalledGroupID);
		AllTrim(p->sStlObject);
		AllTrim(p->sProdPropID);
		AllTrim(p->sCallingSubType);
		AllTrim(p->sCalledSubType);
		AllTrim(p->sPreCallType);
		AllTrim(p->sTurnCode);
		AllTrim(p->sTurnCodeCompanyID);
		AllTrim(p->sTurnCodeProvinceID);
		AllTrim(p->sTurnCodeOperationTypeGrade);
		AllTrim(p->sTurnType);
		AllTrim(p->sTurnCdrID);
		AllTrim(p->sSecondCallingNumber);
		AllTrim(p->sSecondCallingAreaCode);
		AllTrim(p->sSecondCallingGroupID);
		AllTrim(p->sSecondCallingCompanyID);
		AllTrim(p->sPreCallParentCdrID);
		AllTrim(p->sPreCallSubCdrID);
		AllTrim(p->sPreCallSubCdrNum);
		AllTrim(p->sPreCallSubCdrSeq);
		AllTrim(p->sPreCallUsageEventID);
		AllTrim(p->sTurnParentCdrID);
		AllTrim(p->sTurnSubCdrID);
		AllTrim(p->sTurnSubCdrNum);
		AllTrim(p->sTurnSubCdrSeq);
		AllTrim(p->sTurnUsageEventID);
		AllTrim(p->sInTrunkGenre);
		AllTrim(p->sOutTrunkGenre);
		AllTrim(p->sInTrunkNetType);
		AllTrim(p->sOutTrunkNetType);
		AllTrim(p->sCallingNumberType);
		AllTrim(p->sCalledNumberType);
		AllTrim(p->sCallingDomainID);
		AllTrim(p->sCalledDomainID);
		AllTrim(p->sSecondSubType);
		AllTrim(p->sSecondCallingRoamnumber);
		AllTrim(p->sViewCall);
		AllTrim(p->sGroupID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

