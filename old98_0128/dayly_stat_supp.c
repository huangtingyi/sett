
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "dayly_stat_supp.pc"
};


static unsigned int sqlctx = 18785787;


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
   unsigned char  *sqhstv[27];
   unsigned long  sqhstl[27];
            int   sqhsts[27];
            short *sqindv[27];
            int   sqinds[27];
   unsigned long  sqharm[27];
   unsigned long  *sqharc[27];
   unsigned short  sqadto[27];
   unsigned short  sqtdso[27];
} sqlstm = {12,27};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ char *, int * _*/);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,852,0,0,
5,0,0,1,114,0,4,17,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,
32,0,0,2,123,0,3,25,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
55,0,0,3,110,0,4,44,0,0,3,2,0,1,0,2,97,0,0,1,97,0,0,1,97,0,0,
82,0,0,4,142,0,4,51,0,0,3,2,0,1,0,2,97,0,0,1,97,0,0,1,97,0,0,
109,0,0,5,104,0,5,91,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
136,0,0,6,0,0,17,140,0,0,1,1,0,1,0,1,97,0,0,
155,0,0,6,0,0,45,146,0,0,0,0,0,1,0,
170,0,0,6,0,0,15,163,0,0,0,0,0,1,0,
185,0,0,6,0,0,13,171,0,0,17,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,
268,0,0,6,0,0,15,201,0,0,0,0,0,1,0,
283,0,0,7,0,0,17,340,0,0,1,1,0,1,0,1,97,0,0,
302,0,0,7,0,0,21,343,0,0,16,16,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,
381,0,0,7,0,0,17,427,0,0,1,1,0,1,0,1,97,0,0,
400,0,0,7,0,0,21,430,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
435,0,0,8,0,0,17,491,0,0,1,1,0,1,0,1,97,0,0,
454,0,0,8,0,0,45,497,0,0,0,0,0,1,0,
469,0,0,8,0,0,15,514,0,0,0,0,0,1,0,
484,0,0,8,0,0,13,522,0,0,26,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,
603,0,0,8,0,0,15,561,0,0,0,0,0,1,0,
618,0,0,9,0,0,17,748,0,0,1,1,0,1,0,1,97,0,0,
637,0,0,9,0,0,21,751,0,0,25,25,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,97,0,0,1,97,0,0,
752,0,0,9,0,0,17,853,0,0,1,1,0,1,0,1,97,0,0,
771,0,0,9,0,0,21,856,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
802,0,0,10,0,0,17,916,0,0,1,1,0,1,0,1,97,0,0,
821,0,0,10,0,0,45,922,0,0,0,0,0,1,0,
836,0,0,10,0,0,15,939,0,0,0,0,0,1,0,
851,0,0,10,0,0,13,947,0,0,27,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
974,0,0,10,0,0,15,987,0,0,0,0,0,1,0,
989,0,0,11,0,0,17,1178,0,0,1,1,0,1,0,1,97,0,0,
1008,0,0,11,0,0,21,1181,0,0,26,26,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1127,0,0,11,0,0,17,1287,0,0,1,1,0,1,0,1,97,0,0,
1146,0,0,11,0,0,21,1290,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,97,0,0,
1185,0,0,12,0,0,17,1336,0,0,1,1,0,1,0,1,97,0,0,
1204,0,0,12,0,0,45,1342,0,0,0,0,0,1,0,
1219,0,0,12,0,0,15,1359,0,0,0,0,0,1,0,
1234,0,0,12,0,0,13,1367,0,0,13,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
1301,0,0,12,0,0,15,1393,0,0,0,0,0,1,0,
1316,0,0,13,0,0,17,1510,0,0,1,1,0,1,0,1,97,0,0,
1335,0,0,13,0,0,21,1513,0,0,12,12,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
1398,0,0,13,0,0,17,1584,0,0,1,1,0,1,0,1,97,0,0,
1417,0,0,13,0,0,21,1587,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
1448,0,0,14,0,0,17,1632,0,0,1,1,0,1,0,1,97,0,0,
1467,0,0,14,0,0,45,1638,0,0,0,0,0,1,0,
1482,0,0,14,0,0,15,1655,0,0,0,0,0,1,0,
1497,0,0,14,0,0,13,1663,0,0,13,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1564,0,0,14,0,0,15,1689,0,0,0,0,0,1,0,
1579,0,0,15,0,0,17,1806,0,0,1,1,0,1,0,1,97,0,0,
1598,0,0,15,0,0,21,1809,0,0,12,12,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1661,0,0,15,0,0,17,1881,0,0,1,1,0,1,0,1,97,0,0,
1680,0,0,15,0,0,21,1884,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <param_intf.h>
#include <dayly_stat_supp.h>


int CheckDaylyStatLog(char sServiceType[],char sDataDate[])
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	int iCnt;
	char sState[4],sDealDate[15];
	/* EXEC SQL END DECLARE SECTION; */ 

/*1、存在记录？*/
	/* EXEC SQL SELECT COUNT(*) INTO :iCnt FROM DAYLY_STAT_LOG
		WHERE SERVICE_TYPE=:sServiceType AND
		SETT_ITEM_DATE	=to_date(:sDataDate,'YYYYMMDD'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(*)  into :b0  from DAYLY_STAT_LOG where (SERVI\
CE_TYPE=:b1 and SETT_ITEM_DATE=to_date(:b2,'YYYYMMDD'))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sServiceType;
 sqlstm.sqhstl[1] = (unsigned long )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sDataDate;
 sqlstm.sqhstl[2] = (unsigned long )0;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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



	if(CheckSqlResult("COUNT DAYLY_STAT_LOG")<0) return -1;

	if(iCnt==0){/*不存在记录插入一条记录*/

		/* EXEC SQL INSERT INTO DAYLY_STAT_LOG(
				SERVICE_TYPE,
				SETT_ITEM_DATE,
				DEAL_DATE,
				STATE
			)
			VALUES (
				:sServiceType,
				to_date(:sDataDate,'YYYYMMDD'),
				SYSDATE,
				'A0X'
			); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into DAYLY_STAT_LOG (SERVICE_TYPE,SETT_ITEM_DATE,DE\
AL_DATE,STATE) values (:b0,to_date(:b1,'YYYYMMDD'),SYSDATE,'A0X')";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )32;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)sServiceType;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sDataDate;
  sqlstm.sqhstl[1] = (unsigned long )0;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
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



		if(CheckSqlResult("insert into DAYLY_STAT_LOG")<0) return -1;

		return 0;
	}

/*2、存在记录*/
	/* EXEC SQL SELECT STATE INTO :sState
		FROM DAYLY_STAT_LOG
		WHERE SERVICE_TYPE=:sServiceType AND
		SETT_ITEM_DATE	=to_date(:sDataDate,'YYYYMMDD'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select STATE into :b0  from DAYLY_STAT_LOG where (SERVICE_T\
YPE=:b1 and SETT_ITEM_DATE=to_date(:b2,'YYYYMMDD'))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sState;
 sqlstm.sqhstl[0] = (unsigned long )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sServiceType;
 sqlstm.sqhstl[1] = (unsigned long )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sDataDate;
 sqlstm.sqhstl[2] = (unsigned long )0;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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



	if(CheckSqlResult("SELECT DAYLY_STAT_LOG")<0) return -1;

	/* EXEC SQL SELECT to_char(DEAL_DATE,'yyyymmddhh24miss') INTO :sDealDate
		FROM DAYLY_STAT_LOG
		WHERE SERVICE_TYPE=:sServiceType AND
		SETT_ITEM_DATE	=to_date(:sDataDate,'YYYYMMDD'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char(DEAL_DATE,'yyyymmddhh24miss') into :b0  from\
 DAYLY_STAT_LOG where (SERVICE_TYPE=:b1 and SETT_ITEM_DATE=to_date(:b2,'YYYYM\
MDD'))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )82;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sDealDate;
 sqlstm.sqhstl[0] = (unsigned long )15;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sServiceType;
 sqlstm.sqhstl[1] = (unsigned long )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sDataDate;
 sqlstm.sqhstl[2] = (unsigned long )0;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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



	if(CheckSqlResult("SELECT DAYLY_STAT_LOG")<0) return -1;

	if(strcmp(sState,"A0A")==0){
	/*找到记录判断STATE='A0A'则，update STATE='A0X',继续处理*/
		if(SetDaylyStatLog(sServiceType,sDataDate,"A0X")<0)return -1;
		return 0;
	}
	else if(strcmp(sState,"A0X")==0){
	/*找到记录判断STATE='A0H'则输出提示，已经统计过*/
		printf("业务类型%s 统计日期%s 目前正在统计,请核实!\n",
			sServiceType,sDealDate);
		WriteAlertMsg("业务类型%s 统计日期%s 目前正在统计,请核实!",
			sServiceType,sDealDate);
		return -1;
	}
	else if(strcmp(sState,"A0H")==0){
	/*找到记录判断STATE='A0H'则输出提示，已经统计过*/
		printf("业务类型%s 统计日期%s 已经统计过,请核实!\n",
			sServiceType,sDealDate);
		WriteAlertMsg("业务类型%s 统计日期%s 已经统计过,请核实!",
			sServiceType,sDealDate);
		return -1;
	}

	printf("业务类型%s 统计日期%s 业务类型不对,状态%s 请核实!\n",
		sServiceType,sDealDate,sState);
	WriteAlertMsg("业务类型%s 统计日期%s 业务类型不对,状态%s 请核实!",
		sServiceType,sDealDate,sState);

	return -1;
}

int SetDaylyStatLog(char sServiceType[],char sDataDate[],char sState[])
{

	/* EXEC SQL UPDATE DAYLY_STAT_LOG
		SET STATE=:sState
		WHERE SERVICE_TYPE=:sServiceType AND
		SETT_ITEM_DATE	=to_date(:sDataDate,'YYYYMMDD'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update DAYLY_STAT_LOG  set STATE=:b0 where (SERVICE_TYPE=:b\
1 and SETT_ITEM_DATE=to_date(:b2,'YYYYMMDD'))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )109;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sState;
 sqlstm.sqhstl[0] = (unsigned long )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sServiceType;
 sqlstm.sqhstl[1] = (unsigned long )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sDataDate;
 sqlstm.sqhstl[2] = (unsigned long )0;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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



	if(CheckSqlResult("UPDATE DAYLY_STAT_LOG")<0){
		WriteAlertPrint("更新DAYLY_STAT_LOG表 %s 记录失败");
		return -1;
	}
	return 0;
}



/*批量数据动态从DAYLY_STT_HOUR_STAT中用结构缓冲方式取数据*/
int EGetDaylySttHourStatToStruct(struct DaylySttHourStatStruct *p,
	struct DaylySttHourStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(CALL_TYPE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(MSC,' '),\n\
				nvl(TRUNK_IN,' '),\n\
				nvl(TRUNK_IN_TYPE_ID,0),\n\
				nvl(TRUNK_IN_CARR_ID,0),\n\
				nvl(TRUNK_OUT,' '),\n\
				nvl(TRUNK_OUT_TYPE_ID,0),\n\
				nvl(TRUNK_OUT_CARR_ID,0),\n\
				nvl(START_HOUR,' '),\n\
				nvl(TOTAL_SEC,0),\n\
				nvl(INCOME,0),\n\
				nvl(OUTCOME,0),\n\
				nvl(TOTAL_MIN,0),\n\
				to_char(nvl(SETT_ITEM_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE DAYLY_STT_HOUR_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )136;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		CheckSqlError(" PREPARE DAYLY_STT_HOUR_STATSCR DAYLY_STT_HOUR_STATCR");

		/* EXEC SQL DECLARE DAYLY_STT_HOUR_STATCR CURSOR FOR DAYLY_STT_HOUR_STATSCR; */ 

		CheckSqlError("Declare DAYLY_STT_HOUR_STATCR");

		/* EXEC SQL OPEN DAYLY_STT_HOUR_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )155;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open DAYLY_STT_HOUR_STATCR;");


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

		/* EXEC SQL CLOSE DAYLY_STT_HOUR_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )170;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH DAYLY_STT_HOUR_STATCR INTO
			:pSource->asCallType,
			:pSource->asVisitAreaCode,
			:pSource->asMsc,
			:pSource->asTrunkIn,
			:pSource->aiTrunkInTypeID,
			:pSource->aiTrunkInCarrID,
			:pSource->asTrunkOut,
			:pSource->aiTrunkOutTypeID,
			:pSource->aiTrunkOutCarrID,
			:pSource->asStartHour,
			:pSource->aiTotalSec,
			:pSource->aiIncome,
			:pSource->aiOutcome,
			:pSource->aiTotalMin,
			:pSource->asSettItemDate,
			:pSource->asBillingCycleID,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )185;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )10;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asTrunkIn);
  sqlstm.sqhstl[3] = (unsigned long )10;
  sqlstm.sqhsts[3] = (         int  )10;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiTrunkInTypeID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiTrunkInCarrID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asTrunkOut);
  sqlstm.sqhstl[6] = (unsigned long )10;
  sqlstm.sqhsts[6] = (         int  )10;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiTrunkOutTypeID);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiTrunkOutCarrID);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asStartHour);
  sqlstm.sqhstl[9] = (unsigned long )11;
  sqlstm.sqhsts[9] = (         int  )11;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiTotalSec);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiIncome);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiOutcome);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->aiTotalMin);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asSettItemDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[15] = (unsigned long )7;
  sqlstm.sqhsts[15] = (         int  )7;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[16] = (unsigned long )19;
  sqlstm.sqhsts[16] = (         int  )19;
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


		CheckSqlError("Fetch DAYLY_STT_HOUR_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE DAYLY_STT_HOUR_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )268;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=DAYLY_STT_HOUR_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sTrunkIn,		pSource->asTrunkIn[iCurPos]);

		p->iTrunkInTypeID=		pSource->aiTrunkInTypeID[iCurPos];
		p->iTrunkInCarrID=		pSource->aiTrunkInCarrID[iCurPos];

		strcpy(p->sTrunkOut,		pSource->asTrunkOut[iCurPos]);

		p->iTrunkOutTypeID=		pSource->aiTrunkOutTypeID[iCurPos];
		p->iTrunkOutCarrID=		pSource->aiTrunkOutCarrID[iCurPos];

		strcpy(p->sStartHour,		pSource->asStartHour[iCurPos]);

		p->iTotalSec=			pSource->aiTotalSec[iCurPos];
		p->iIncome=			pSource->aiIncome[iCurPos];
		p->iOutcome=			pSource->aiOutcome[iCurPos];
		p->iTotalMin=			pSource->aiTotalMin[iCurPos];

		strcpy(p->sSettItemDate,	pSource->asSettItemDate[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);
		strcpy(p->sRowID,               pSource->asRowID[iCurPos]);

		AllTrim(p->sCallType);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sMsc);
		AllTrim(p->sTrunkIn);
		AllTrim(p->sTrunkOut);
		AllTrim(p->sStartHour);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}


/*批量数据结构缓冲写入DAYLY_STT_HOUR_STAT*/
int EInsertStructToDaylySttHourStat(struct DaylySttHourStatStruct *p,
	int iInsertFlag,struct DaylySttHourStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asTrunkIn[iCurPos],		p->sTrunkIn);

		pTarget->aiTrunkInTypeID[iCurPos]=		p->iTrunkInTypeID;
		pTarget->aiTrunkInCarrID[iCurPos]=		p->iTrunkInCarrID;

		strcpy(pTarget->asTrunkOut[iCurPos],		p->sTrunkOut);

		pTarget->aiTrunkOutTypeID[iCurPos]=		p->iTrunkOutTypeID;
		pTarget->aiTrunkOutCarrID[iCurPos]=		p->iTrunkOutCarrID;

		strcpy(pTarget->asStartHour[iCurPos],		p->sStartHour);

		pTarget->aiTotalSec[iCurPos]=			p->iTotalSec;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiTotalMin[iCurPos]=			p->iTotalMin;

		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==DAYLY_STT_HOUR_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				CALL_TYPE,\n\
				VISIT_AREA_CODE,\n\
				MSC,\n\
				TRUNK_IN,\n\
				TRUNK_IN_TYPE_ID,\n\
				TRUNK_IN_CARR_ID,\n\
				TRUNK_OUT,\n\
				TRUNK_OUT_TYPE_ID,\n\
				TRUNK_OUT_CARR_ID,\n\
				START_HOUR,\n\
				TOTAL_SEC,\n\
				INCOME,\n\
				OUTCOME,\n\
				TOTAL_MIN,\n\
				SETT_ITEM_DATE,\n\
				BILLING_CYCLE_ID)\n\
			VALUES (\n\
				:asCallType,\n\
				:asVisitAreaCode,\n\
				:asMsc,\n\
				:asTrunkIn,\n\
				:aiTrunkInTypeID,\n\
				:aiTrunkInCarrID,\n\
				:asTrunkOut,\n\
				:aiTrunkOutTypeID,\n\
				:aiTrunkOutCarrID,\n\
				:asStartHour,\n\
				:aiTotalSec,\n\
				:aiIncome,\n\
				:aiOutcome,\n\
				:aiTotalMin,\n\
				to_date(:asSettItemDate,'yyyymmddhh24miss'),\n\
				:asBillingCycleID\n\
			)",sTableName);

		/* EXEC SQL PREPARE DAYLY_STT_HOUR_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )283;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare insert statement DAYLY_STT_HOUR_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE DAYLY_STT_HOUR_STATTRG USING
				:pTarget->asCallType,
				:pTarget->asVisitAreaCode,
				:pTarget->asMsc,
				:pTarget->asTrunkIn,
				:pTarget->aiTrunkInTypeID,
				:pTarget->aiTrunkInCarrID,
				:pTarget->asTrunkOut,
				:pTarget->aiTrunkOutTypeID,
				:pTarget->aiTrunkOutCarrID,
				:pTarget->asStartHour,
				:pTarget->aiTotalSec,
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiTotalMin,
				:pTarget->asSettItemDate,
				:pTarget->asBillingCycleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )302;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )10;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asTrunkIn);
  sqlstm.sqhstl[3] = (unsigned long )10;
  sqlstm.sqhsts[3] = (         int  )10;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->aiTrunkInTypeID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiTrunkInCarrID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asTrunkOut);
  sqlstm.sqhstl[6] = (unsigned long )10;
  sqlstm.sqhsts[6] = (         int  )10;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiTrunkOutTypeID);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->aiTrunkOutCarrID);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asStartHour);
  sqlstm.sqhstl[9] = (unsigned long )11;
  sqlstm.sqhsts[9] = (         int  )11;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiTotalSec);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->aiTotalMin);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asSettItemDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[15] = (unsigned long )7;
  sqlstm.sqhsts[15] = (         int  )7;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into DAYLY_STT_HOUR_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*批量数据结构缓冲更新DAYLY_STT_HOUR_STAT*/
int EUpdateStructToDaylySttHourStat(struct DaylySttHourStatStruct *p,
	int iUpdateFlag,struct DaylySttHourStatStructUp *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asTrunkIn[iCurPos],		p->sTrunkIn);

		pTarget->aiTrunkInTypeID[iCurPos]=		p->iTrunkInTypeID;
		pTarget->aiTrunkInCarrID[iCurPos]=		p->iTrunkInCarrID;

		strcpy(pTarget->asTrunkOut[iCurPos],		p->sTrunkOut);

		pTarget->aiTrunkOutTypeID[iCurPos]=		p->iTrunkOutTypeID;
		pTarget->aiTrunkOutCarrID[iCurPos]=		p->iTrunkOutCarrID;

		strcpy(pTarget->asStartHour[iCurPos],		p->sStartHour);

		pTarget->aiTotalSec[iCurPos]=			p->iTotalSec;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiTotalMin[iCurPos]=			p->iTotalMin;

		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);
		strcpy(pTarget->asRowID[iCurPos],               p->sRowID);

		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==DAYLY_STT_HOUR_STAT_BUFLEN_UP){

/* UPDATE */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s \n\
			SET \n\
				TOTAL_SEC	=:aiTotalSec,\n\
				INCOME		=:aiIncome,\n\
				OUTCOME		=:aiOutcome,\n\
				TOTAL_MIN	=:aiTotalMin\n\
			WHERE \n\
                                ROWID = chartorowid(:asRowID)\n\
                        ",sTableName);

		/* EXEC SQL PREPARE DAYLY_STT_HOUR_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )381;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare update statement DAYLY_STT_HOUR_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE DAYLY_STT_HOUR_STATTRG USING
				:pTarget->aiTotalSec,
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiTotalMin,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )400;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiTotalSec);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiTotalMin);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
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


		if(CheckSqlResult("Dyn update  DAYLY_STT_HOUR_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*批量数据动态从DAYLY_STT_STAT中用结构缓冲方式取数据*/
int EGetDaylySttStatToStruct(struct DaylySttStatStruct *p,
	struct DaylySttStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(CALL_TYPE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(HOME_CAPITAL_CODE,' '),\n\
				nvl(CALLED_CODE,' '),\n\
				nvl(CALLED_CAPITAL_CODE,' '),\n\
				nvl(TICKET_TYPE_ID,0),\n\
				nvl(OPP_CARR_ID,0),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(MSISDN_USER_TYPE,' '),\n\
				nvl(MSISDN_NBR_TYPE,' '),\n\
				nvl(MSISDN_HEAD,' '),\n\
				nvl(MSISDN_AREA_ID,0),\n\
				nvl(MSISDN_BILLING_TYPE_ID,' '),\n\
				nvl(MSISDN_CARRIER_ID,0),\n\
				nvl(OPP_USER_TYPE,' '),\n\
				nvl(OPP_NBR_TYPE,' '),\n\
				nvl(OPP_HEAD,' '),\n\
				nvl(OPP_AREA_ID,0),\n\
				nvl(OPP_CARRIER_ID,0),\n\
				nvl(INCOME,0),\n\
				nvl(OUTCOME,0),\n\
				nvl(TOTAL_MIN,0),\n\
				to_char(nvl(SETT_ITEM_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE DAYLY_STT_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )435;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		CheckSqlError(" PREPARE DAYLY_STT_STATSCR DAYLY_STT_STATCR");

		/* EXEC SQL DECLARE DAYLY_STT_STATCR CURSOR FOR DAYLY_STT_STATSCR; */ 

		CheckSqlError("Declare DAYLY_STT_STATCR");

		/* EXEC SQL OPEN DAYLY_STT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )454;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open DAYLY_STT_STATCR;");


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

		/* EXEC SQL CLOSE DAYLY_STT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )469;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH DAYLY_STT_STATCR INTO
			:pSource->asCallType,
			:pSource->asVisitAreaCode,
			:pSource->asHomeAreaCode,
			:pSource->asHomeCapitalCode,
			:pSource->asCalledCode,
			:pSource->asCalledCapitalCode,
			:pSource->aiTicketTypeID,
			:pSource->aiOppCarrID,
			:pSource->asNetType,
			:pSource->asMsisdnUserType,
			:pSource->asMsisdnNbrType,
			:pSource->asMsisdnHead,
			:pSource->aiMsisdnAreaID,
			:pSource->asMsisdnBillingTypeID,
			:pSource->aiMsisdnCarrierID,
			:pSource->asOppUserType,
			:pSource->asOppNbrType,
			:pSource->asOppHead,
			:pSource->aiOppAreaID,
			:pSource->aiOppCarrierID,
			:pSource->aiIncome,
			:pSource->aiOutcome,
			:pSource->aiTotalMin,
			:pSource->asSettItemDate,
			:pSource->asBillingCycleID,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )484;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )10;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asHomeCapitalCode);
  sqlstm.sqhstl[3] = (unsigned long )10;
  sqlstm.sqhsts[3] = (         int  )10;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCalledCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCalledCapitalCode);
  sqlstm.sqhstl[5] = (unsigned long )10;
  sqlstm.sqhsts[5] = (         int  )10;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiTicketTypeID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiOppCarrID);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asMsisdnUserType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asMsisdnNbrType);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asMsisdnHead);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiMsisdnAreaID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asMsisdnBillingTypeID);
  sqlstm.sqhstl[13] = (unsigned long )11;
  sqlstm.sqhsts[13] = (         int  )11;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiMsisdnCarrierID);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asOppUserType);
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
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asOppHead);
  sqlstm.sqhstl[17] = (unsigned long )8;
  sqlstm.sqhsts[17] = (         int  )8;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->aiOppAreaID);
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )sizeof(int);
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->aiOppCarrierID);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(int);
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->aiIncome);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->aiOutcome);
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )sizeof(int);
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->aiTotalMin);
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )sizeof(int);
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asSettItemDate);
  sqlstm.sqhstl[23] = (unsigned long )15;
  sqlstm.sqhsts[23] = (         int  )15;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[24] = (unsigned long )7;
  sqlstm.sqhsts[24] = (         int  )7;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[25] = (unsigned long )19;
  sqlstm.sqhsts[25] = (         int  )19;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
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


		CheckSqlError("Fetch DAYLY_STT_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE DAYLY_STT_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 26;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )603;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=DAYLY_STT_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sHomeCapitalCode,	pSource->asHomeCapitalCode[iCurPos]);
		strcpy(p->sCalledCode,		pSource->asCalledCode[iCurPos]);
		strcpy(p->sCalledCapitalCode,	pSource->asCalledCapitalCode[iCurPos]);

		p->iTicketTypeID=		pSource->aiTicketTypeID[iCurPos];
		p->iOppCarrID=			pSource->aiOppCarrID[iCurPos];

		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);
		strcpy(p->sMsisdnUserType,	pSource->asMsisdnUserType[iCurPos]);
		strcpy(p->sMsisdnNbrType,	pSource->asMsisdnNbrType[iCurPos]);
		strcpy(p->sMsisdnHead,		pSource->asMsisdnHead[iCurPos]);

		p->iMsisdnAreaID=		pSource->aiMsisdnAreaID[iCurPos];

		strcpy(p->sMsisdnBillingTypeID,	pSource->asMsisdnBillingTypeID[iCurPos]);

		p->iMsisdnCarrierID=		pSource->aiMsisdnCarrierID[iCurPos];

		strcpy(p->sOppUserType,		pSource->asOppUserType[iCurPos]);
		strcpy(p->sOppNbrType,		pSource->asOppNbrType[iCurPos]);
		strcpy(p->sOppHead,		pSource->asOppHead[iCurPos]);

		p->iOppAreaID=			pSource->aiOppAreaID[iCurPos];
		p->iOppCarrierID=		pSource->aiOppCarrierID[iCurPos];
		p->iIncome=			pSource->aiIncome[iCurPos];
		p->iOutcome=			pSource->aiOutcome[iCurPos];
		p->iTotalMin=			pSource->aiTotalMin[iCurPos];

		strcpy(p->sSettItemDate,	pSource->asSettItemDate[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);
		strcpy(p->sRowID,               pSource->asRowID[iCurPos]);

		AllTrim(p->sCallType);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sHomeCapitalCode);
		AllTrim(p->sCalledCode);
		AllTrim(p->sCalledCapitalCode);
		AllTrim(p->sNetType);
		AllTrim(p->sMsisdnUserType);
		AllTrim(p->sMsisdnNbrType);
		AllTrim(p->sMsisdnHead);
		AllTrim(p->sMsisdnBillingTypeID);
		AllTrim(p->sOppUserType);
		AllTrim(p->sOppNbrType);
		AllTrim(p->sOppHead);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}


/*批量数据结构缓冲写入DAYLY_STT_STAT*/
int EInsertStructToDaylySttStat(struct DaylySttStatStruct *p,
	int iInsertFlag,struct DaylySttStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asHomeCapitalCode[iCurPos],	p->sHomeCapitalCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asCalledCapitalCode[iCurPos],	p->sCalledCapitalCode);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;
		pTarget->aiOppCarrID[iCurPos]=			p->iOppCarrID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnUserType[iCurPos],	p->sMsisdnUserType);
		strcpy(pTarget->asMsisdnNbrType[iCurPos],	p->sMsisdnNbrType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);

		pTarget->aiMsisdnAreaID[iCurPos]=		p->iMsisdnAreaID;

		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);

		pTarget->aiMsisdnCarrierID[iCurPos]=		p->iMsisdnCarrierID;

		strcpy(pTarget->asOppUserType[iCurPos],		p->sOppUserType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);
		strcpy(pTarget->asOppHead[iCurPos],		p->sOppHead);

		pTarget->aiOppAreaID[iCurPos]=			p->iOppAreaID;
		pTarget->aiOppCarrierID[iCurPos]=		p->iOppCarrierID;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiTotalMin[iCurPos]=			p->iTotalMin;

		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==DAYLY_STT_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				CALL_TYPE,\n\
				VISIT_AREA_CODE,\n\
				HOME_AREA_CODE,\n\
				HOME_CAPITAL_CODE,\n\
				CALLED_CODE,\n\
				CALLED_CAPITAL_CODE,\n\
				TICKET_TYPE_ID,\n\
				OPP_CARR_ID,\n\
				NET_TYPE,\n\
				MSISDN_USER_TYPE,\n\
				MSISDN_NBR_TYPE,\n\
				MSISDN_HEAD,\n\
				MSISDN_AREA_ID,\n\
				MSISDN_BILLING_TYPE_ID,\n\
				MSISDN_CARRIER_ID,\n\
				OPP_USER_TYPE,\n\
				OPP_NBR_TYPE,\n\
				OPP_HEAD,\n\
				OPP_AREA_ID,\n\
				OPP_CARRIER_ID,\n\
				INCOME,\n\
				OUTCOME,\n\
				TOTAL_MIN,\n\
				SETT_ITEM_DATE,\n\
				BILLING_CYCLE_ID)\n\
			VALUES (\n\
				:asCallType,\n\
				:asVisitAreaCode,\n\
				:asHomeAreaCode,\n\
				:asHomeCapitalCode,\n\
				:asCalledCode,\n\
				:asCalledCapitalCode,\n\
				:aiTicketTypeID,\n\
				:aiOppCarrID,\n\
				:asNetType,\n\
				:asMsisdnUserType,\n\
				:asMsisdnNbrType,\n\
				:asMsisdnHead,\n\
				:aiMsisdnAreaID,\n\
				:asMsisdnBillingTypeID,\n\
				:aiMsisdnCarrierID,\n\
				:asOppUserType,\n\
				:asOppNbrType,\n\
				:asOppHead,\n\
				:aiOppAreaID,\n\
				:aiOppCarrierID,\n\
				:aiIncome,\n\
				:aiOutcome,\n\
				:aiTotalMin,\n\
				to_date(:asSettItemDate,'yyyymmddhh24miss'),\n\
				:asBillingCycleID\n\
			)",sTableName);

		/* EXEC SQL PREPARE DAYLY_STT_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )618;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare insert statement DAYLY_STT_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE DAYLY_STT_STATTRG USING
				:pTarget->asCallType,
				:pTarget->asVisitAreaCode,
				:pTarget->asHomeAreaCode,
				:pTarget->asHomeCapitalCode,
				:pTarget->asCalledCode,
				:pTarget->asCalledCapitalCode,
				:pTarget->aiTicketTypeID,
				:pTarget->aiOppCarrID,
				:pTarget->asNetType,
				:pTarget->asMsisdnUserType,
				:pTarget->asMsisdnNbrType,
				:pTarget->asMsisdnHead,
				:pTarget->aiMsisdnAreaID,
				:pTarget->asMsisdnBillingTypeID,
				:pTarget->aiMsisdnCarrierID,
				:pTarget->asOppUserType,
				:pTarget->asOppNbrType,
				:pTarget->asOppHead,
				:pTarget->aiOppAreaID,
				:pTarget->aiOppCarrierID,
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiTotalMin,
				:pTarget->asSettItemDate,
				:pTarget->asBillingCycleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )637;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )10;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asHomeCapitalCode);
  sqlstm.sqhstl[3] = (unsigned long )10;
  sqlstm.sqhsts[3] = (         int  )10;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asCalledCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asCalledCapitalCode);
  sqlstm.sqhstl[5] = (unsigned long )10;
  sqlstm.sqhsts[5] = (         int  )10;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiTicketTypeID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiOppCarrID);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asMsisdnUserType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asMsisdnNbrType);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asMsisdnHead);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->aiMsisdnAreaID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asMsisdnBillingTypeID);
  sqlstm.sqhstl[13] = (unsigned long )11;
  sqlstm.sqhsts[13] = (         int  )11;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiMsisdnCarrierID);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asOppUserType);
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
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asOppHead);
  sqlstm.sqhstl[17] = (unsigned long )8;
  sqlstm.sqhsts[17] = (         int  )8;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->aiOppAreaID);
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )sizeof(int);
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->aiOppCarrierID);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(int);
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )sizeof(int);
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->aiTotalMin);
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )sizeof(int);
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asSettItemDate);
  sqlstm.sqhstl[23] = (unsigned long )15;
  sqlstm.sqhsts[23] = (         int  )15;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[24] = (unsigned long )7;
  sqlstm.sqhsts[24] = (         int  )7;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into DAYLY_STT_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*批量数据结构缓冲更新DAYLY_STT_STAT*/
int EUpdateStructToDaylySttStat(struct DaylySttStatStruct *p,
	int iUpdateFlag,struct DaylySttStatStructUp *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asHomeCapitalCode[iCurPos],	p->sHomeCapitalCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asCalledCapitalCode[iCurPos],	p->sCalledCapitalCode);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;
		pTarget->aiOppCarrID[iCurPos]=			p->iOppCarrID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnUserType[iCurPos],	p->sMsisdnUserType);
		strcpy(pTarget->asMsisdnNbrType[iCurPos],	p->sMsisdnNbrType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);

		pTarget->aiMsisdnAreaID[iCurPos]=		p->iMsisdnAreaID;

		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);

		pTarget->aiMsisdnCarrierID[iCurPos]=		p->iMsisdnCarrierID;

		strcpy(pTarget->asOppUserType[iCurPos],		p->sOppUserType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);
		strcpy(pTarget->asOppHead[iCurPos],		p->sOppHead);

		pTarget->aiOppAreaID[iCurPos]=			p->iOppAreaID;
		pTarget->aiOppCarrierID[iCurPos]=		p->iOppCarrierID;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiTotalMin[iCurPos]=			p->iTotalMin;

		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);
		strcpy(pTarget->asRowID[iCurPos],               p->sRowID);

		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==DAYLY_STT_STAT_BUFLEN_UP){

/* UPDATE */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s \n\
			SET \n\
				INCOME		=:aiIncome,\n\
				OUTCOME		=:aiOutcome,\n\
				TOTAL_MIN	=:aiTotalMin\n\
			WHERE \n\
                                ROWID = chartorowid(:asRowID)\n\
                        ",sTableName);

		/* EXEC SQL PREPARE DAYLY_STT_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )752;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare update statement DAYLY_STT_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE DAYLY_STT_STATTRG USING
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiTotalMin,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )771;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->aiTotalMin);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[3] = (unsigned long )19;
  sqlstm.sqhsts[3] = (         int  )19;
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


		if(CheckSqlResult("Dyn update DAYLY_STT_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*批量数据动态从SRT_STAT中用结构缓冲方式取数据*/
int EGetSrtStatToStruct(struct SrtStatStruct *p,
	struct SrtStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(CALL_TYPE,' '),\n\
				nvl(AREA_CODE,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(OPP_CAPITAL_CODE,' '),\n\
				nvl(CALLED_CODE,' '),\n\
				nvl(CALLED_CAPITAL_CODE,' '),\n\
				nvl(TICKET_TYPE_ID,0),\n\
				nvl(OPP_CARR_ID,0),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(MSISDN_USER_TYPE,' '),\n\
				nvl(MSISDN_NBR_TYPE,' '),\n\
				nvl(MSISDN_HEAD,' '),\n\
				nvl(MSISDN_AREA_ID,0),\n\
				nvl(MSISDN_BILLING_TYPE_ID,' '),\n\
				nvl(OPP_USER_TYPE,' '),\n\
				nvl(OPP_NBR_TYPE,' '),\n\
				nvl(OPP_HEAD,' '),\n\
				nvl(OPP_AREA_ID,0),\n\
				nvl(OPP_BILLING_TYPE_ID,' '),\n\
				nvl(ROAM_FEE,0),\n\
				nvl(TOLL_FEE,0),\n\
				nvl(INCOME,0),\n\
				nvl(OUTCOME,0),\n\
				nvl(TOTAL_MIN,0),\n\
				to_char(nvl(SETT_ITEM_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SRT_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )802;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		CheckSqlError(" PREPARE SRT_STATSCR SRT_STATCR");

		/* EXEC SQL DECLARE SRT_STATCR CURSOR FOR SRT_STATSCR; */ 

		CheckSqlError("Declare SRT_STATCR");

		/* EXEC SQL OPEN SRT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )821;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SRT_STATCR;");


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

		/* EXEC SQL CLOSE SRT_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )836;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH SRT_STATCR INTO
			:pSource->asCallType,
			:pSource->asAreaCode,
			:pSource->asOppAreaCode,
			:pSource->asOppCapitalCode,
			:pSource->asCalledCode,
			:pSource->asCalledCapitalCode,
			:pSource->aiTicketTypeID,
			:pSource->aiOppCarrID,
			:pSource->asNetType,
			:pSource->asMsisdnUserType,
			:pSource->asMsisdnNbrType,
			:pSource->asMsisdnHead,
			:pSource->aiMsisdnAreaID,
			:pSource->asMsisdnBillingTypeID,
			:pSource->asOppUserType,
			:pSource->asOppNbrType,
			:pSource->asOppHead,
			:pSource->aiOppAreaID,
			:pSource->asOppBillingTypeID,
			:pSource->aiRoamFee,
			:pSource->aiTollFee,
			:pSource->aiIncome,
			:pSource->aiOutcome,
			:pSource->aiTotalMin,
			:pSource->asSettItemDate,
			:pSource->asBillingCycleID,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )851;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )10;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asOppCapitalCode);
  sqlstm.sqhstl[3] = (unsigned long )10;
  sqlstm.sqhsts[3] = (         int  )10;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCalledCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCalledCapitalCode);
  sqlstm.sqhstl[5] = (unsigned long )10;
  sqlstm.sqhsts[5] = (         int  )10;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiTicketTypeID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiOppCarrID);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asMsisdnUserType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asMsisdnNbrType);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asMsisdnHead);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiMsisdnAreaID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asMsisdnBillingTypeID);
  sqlstm.sqhstl[13] = (unsigned long )11;
  sqlstm.sqhsts[13] = (         int  )11;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asOppUserType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asOppNbrType);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asOppHead);
  sqlstm.sqhstl[16] = (unsigned long )8;
  sqlstm.sqhsts[16] = (         int  )8;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->aiOppAreaID);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )sizeof(int);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asOppBillingTypeID);
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )11;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->aiRoamFee);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(int);
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->aiTollFee);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->aiIncome);
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )sizeof(int);
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->aiOutcome);
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )sizeof(int);
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->aiTotalMin);
  sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[23] = (         int  )sizeof(int);
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asSettItemDate);
  sqlstm.sqhstl[24] = (unsigned long )15;
  sqlstm.sqhsts[24] = (         int  )15;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[25] = (unsigned long )7;
  sqlstm.sqhsts[25] = (         int  )7;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[26] = (unsigned long )19;
  sqlstm.sqhsts[26] = (         int  )19;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
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


		CheckSqlError("Fetch SRT_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SRT_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 27;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )974;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SRT_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sAreaCode,		pSource->asAreaCode[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sOppCapitalCode,	pSource->asOppCapitalCode[iCurPos]);
		strcpy(p->sCalledCode,		pSource->asCalledCode[iCurPos]);
		strcpy(p->sCalledCapitalCode,	pSource->asCalledCapitalCode[iCurPos]);

		p->iTicketTypeID=		pSource->aiTicketTypeID[iCurPos];
		p->iOppCarrID=			pSource->aiOppCarrID[iCurPos];

		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);
		strcpy(p->sMsisdnUserType,	pSource->asMsisdnUserType[iCurPos]);
		strcpy(p->sMsisdnNbrType,	pSource->asMsisdnNbrType[iCurPos]);
		strcpy(p->sMsisdnHead,		pSource->asMsisdnHead[iCurPos]);

		p->iMsisdnAreaID=		pSource->aiMsisdnAreaID[iCurPos];

		strcpy(p->sMsisdnBillingTypeID,	pSource->asMsisdnBillingTypeID[iCurPos]);
		strcpy(p->sOppUserType,		pSource->asOppUserType[iCurPos]);
		strcpy(p->sOppNbrType,		pSource->asOppNbrType[iCurPos]);
		strcpy(p->sOppHead,		pSource->asOppHead[iCurPos]);

		p->iOppAreaID=			pSource->aiOppAreaID[iCurPos];

		strcpy(p->sOppBillingTypeID,	pSource->asOppBillingTypeID[iCurPos]);

		p->iRoamFee=			pSource->aiRoamFee[iCurPos];
		p->iTollFee=			pSource->aiTollFee[iCurPos];
		p->iIncome=			pSource->aiIncome[iCurPos];
		p->iOutcome=			pSource->aiOutcome[iCurPos];
		p->iTotalMin=			pSource->aiTotalMin[iCurPos];

		strcpy(p->sSettItemDate,	pSource->asSettItemDate[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);
		strcpy(p->sRowID,               pSource->asRowID[iCurPos]);

		AllTrim(p->sCallType);
		AllTrim(p->sAreaCode);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sOppCapitalCode);
		AllTrim(p->sCalledCode);
		AllTrim(p->sCalledCapitalCode);
		AllTrim(p->sNetType);
		AllTrim(p->sMsisdnUserType);
		AllTrim(p->sMsisdnNbrType);
		AllTrim(p->sMsisdnHead);
		AllTrim(p->sMsisdnBillingTypeID);
		AllTrim(p->sOppUserType);
		AllTrim(p->sOppNbrType);
		AllTrim(p->sOppHead);
		AllTrim(p->sOppBillingTypeID);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入SRT_STAT*/
int EInsertStructToSrtStat(struct SrtStatStruct *p,
	int iInsertFlag,struct SrtStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asAreaCode[iCurPos],		p->sAreaCode);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);
		strcpy(pTarget->asOppCapitalCode[iCurPos],	p->sOppCapitalCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asCalledCapitalCode[iCurPos],	p->sCalledCapitalCode);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;
		pTarget->aiOppCarrID[iCurPos]=			p->iOppCarrID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnUserType[iCurPos],	p->sMsisdnUserType);
		strcpy(pTarget->asMsisdnNbrType[iCurPos],	p->sMsisdnNbrType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);

		pTarget->aiMsisdnAreaID[iCurPos]=		p->iMsisdnAreaID;

		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);
		strcpy(pTarget->asOppUserType[iCurPos],		p->sOppUserType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);
		strcpy(pTarget->asOppHead[iCurPos],		p->sOppHead);

		pTarget->aiOppAreaID[iCurPos]=			p->iOppAreaID;

		strcpy(pTarget->asOppBillingTypeID[iCurPos],	p->sOppBillingTypeID);

		pTarget->aiRoamFee[iCurPos]=			p->iRoamFee;
		pTarget->aiTollFee[iCurPos]=			p->iTollFee;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiTotalMin[iCurPos]=			p->iTotalMin;

		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SRT_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				CALL_TYPE,\n\
				AREA_CODE,\n\
				OPP_AREA_CODE,\n\
				OPP_CAPITAL_CODE,\n\
				CALLED_CODE,\n\
				CALLED_CAPITAL_CODE,\n\
				TICKET_TYPE_ID,\n\
				OPP_CARR_ID,\n\
				NET_TYPE,\n\
				MSISDN_USER_TYPE,\n\
				MSISDN_NBR_TYPE,\n\
				MSISDN_HEAD,\n\
				MSISDN_AREA_ID,\n\
				MSISDN_BILLING_TYPE_ID,\n\
				OPP_USER_TYPE,\n\
				OPP_NBR_TYPE,\n\
				OPP_HEAD,\n\
				OPP_AREA_ID,\n\
				OPP_BILLING_TYPE_ID,\n\
				ROAM_FEE,\n\
				TOLL_FEE,\n\
				INCOME,\n\
				OUTCOME,\n\
				TOTAL_MIN,\n\
				SETT_ITEM_DATE,\n\
				BILLING_CYCLE_ID)\n\
			VALUES (\n\
				:asCallType,\n\
				:asAreaCode,\n\
				:asOppAreaCode,\n\
				:asOppCapitalCode,\n\
				:asCalledCode,\n\
				:asCalledCapitalCode,\n\
				:aiTicketTypeID,\n\
				:aiOppCarrID,\n\
				:asNetType,\n\
				:asMsisdnUserType,\n\
				:asMsisdnNbrType,\n\
				:asMsisdnHead,\n\
				:aiMsisdnAreaID,\n\
				:asMsisdnBillingTypeID,\n\
				:asOppUserType,\n\
				:asOppNbrType,\n\
				:asOppHead,\n\
				:aiOppAreaID,\n\
				:asOppBillingTypeID,\n\
				:aiRoamFee,\n\
				:aiTollFee,\n\
				:aiIncome,\n\
				:aiOutcome,\n\
				:aiTotalMin,\n\
				to_date(:asSettItemDate,'yyyymmddhh24miss'),\n\
				:asBillingCycleID\n\
			)",sTableName);

		/* EXEC SQL PREPARE SRT_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )989;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare insert statement SRT_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SRT_STATTRG USING
				:pTarget->asCallType,
				:pTarget->asAreaCode,
				:pTarget->asOppAreaCode,
				:pTarget->asOppCapitalCode,
				:pTarget->asCalledCode,
				:pTarget->asCalledCapitalCode,
				:pTarget->aiTicketTypeID,
				:pTarget->aiOppCarrID,
				:pTarget->asNetType,
				:pTarget->asMsisdnUserType,
				:pTarget->asMsisdnNbrType,
				:pTarget->asMsisdnHead,
				:pTarget->aiMsisdnAreaID,
				:pTarget->asMsisdnBillingTypeID,
				:pTarget->asOppUserType,
				:pTarget->asOppNbrType,
				:pTarget->asOppHead,
				:pTarget->aiOppAreaID,
				:pTarget->asOppBillingTypeID,
				:pTarget->aiRoamFee,
				:pTarget->aiTollFee,
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiTotalMin,
				:pTarget->asSettItemDate,
				:pTarget->asBillingCycleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1008;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )10;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asOppCapitalCode);
  sqlstm.sqhstl[3] = (unsigned long )10;
  sqlstm.sqhsts[3] = (         int  )10;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asCalledCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asCalledCapitalCode);
  sqlstm.sqhstl[5] = (unsigned long )10;
  sqlstm.sqhsts[5] = (         int  )10;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiTicketTypeID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiOppCarrID);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asMsisdnUserType);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asMsisdnNbrType);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asMsisdnHead);
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )8;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->aiMsisdnAreaID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asMsisdnBillingTypeID);
  sqlstm.sqhstl[13] = (unsigned long )11;
  sqlstm.sqhsts[13] = (         int  )11;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asOppUserType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asOppNbrType);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asOppHead);
  sqlstm.sqhstl[16] = (unsigned long )8;
  sqlstm.sqhsts[16] = (         int  )8;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->aiOppAreaID);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )sizeof(int);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asOppBillingTypeID);
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )11;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->aiRoamFee);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(int);
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->aiTollFee);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )sizeof(int);
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )sizeof(int);
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->aiTotalMin);
  sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[23] = (         int  )sizeof(int);
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asSettItemDate);
  sqlstm.sqhstl[24] = (unsigned long )15;
  sqlstm.sqhsts[24] = (         int  )15;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[25] = (unsigned long )7;
  sqlstm.sqhsts[25] = (         int  )7;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into SRT_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据结构缓冲更新SRT_STAT*/
int EUpdateStructToSrtStat(struct SrtStatStruct *p,
	int iUpdateFlag,struct SrtStatStructUp *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asAreaCode[iCurPos],		p->sAreaCode);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);
		strcpy(pTarget->asOppCapitalCode[iCurPos],	p->sOppCapitalCode);
		strcpy(pTarget->asCalledCode[iCurPos],		p->sCalledCode);
		strcpy(pTarget->asCalledCapitalCode[iCurPos],	p->sCalledCapitalCode);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;
		pTarget->aiOppCarrID[iCurPos]=			p->iOppCarrID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnUserType[iCurPos],	p->sMsisdnUserType);
		strcpy(pTarget->asMsisdnNbrType[iCurPos],	p->sMsisdnNbrType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);

		pTarget->aiMsisdnAreaID[iCurPos]=		p->iMsisdnAreaID;

		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);
		strcpy(pTarget->asOppUserType[iCurPos],		p->sOppUserType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);
		strcpy(pTarget->asOppHead[iCurPos],		p->sOppHead);

		pTarget->aiOppAreaID[iCurPos]=			p->iOppAreaID;

		strcpy(pTarget->asOppBillingTypeID[iCurPos],	p->sOppBillingTypeID);

		pTarget->aiRoamFee[iCurPos]=			p->iRoamFee;
		pTarget->aiTollFee[iCurPos]=			p->iTollFee;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiTotalMin[iCurPos]=			p->iTotalMin;

		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);
		strcpy(pTarget->asRowID[iCurPos],               p->sRowID);

		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==SRT_STAT_BUFLEN_UP){

/* Update */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s \n\
			SET \n\
				ROAM_FEE	=:aiRoamFee,\n\
				TOLL_FEE	=:aiTollFee,\n\
				INCOME		=:aiIncome,\n\
				OUTCOME		=:aiOutcome,\n\
				TOTAL_MIN	=:aiTotalMin\n\
			WHERE \n\
                                ROWID = chartorowid(:asRowID)\n\
                        ",sTableName);


		/* EXEC SQL PREPARE SRT_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1127;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare Update statement SRT_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SRT_STATTRG USING
				:pTarget->aiRoamFee,
				:pTarget->aiTollFee,
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiTotalMin,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1146;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiRoamFee);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiTollFee);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->aiTotalMin);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[5] = (unsigned long )19;
  sqlstm.sqhsts[5] = (         int  )19;
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


		if(CheckSqlResult("Dyn Update SRT_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}
/*批量数据动态从SPCP_STAT中用结构缓冲方式取数据*/
int EGetSpcpStatToStruct(struct SpcpStatStruct *p,
	struct SpcpStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(AREA_CODE,' '),\n\
				nvl(SP_CODE,' '),\n\
				nvl(SP_SERVICE_CODE,' '),\n\
				nvl(SP_ACC_NBR,' '),\n\
				nvl(TICKET_TYPE_ID,0),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(MSISDN_HEAD,' '),\n\
				nvl(MSISDN_BILLING_TYPE_ID,' '),\n\
				nvl(RENT_FEE,0),\n\
				nvl(INFO_FEE,0),\n\
				nvl(OUTCOME,0),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SPCP_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1185;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		CheckSqlError(" PREPARE SPCP_STATSCR SPCP_STATCR");

		/* EXEC SQL DECLARE SPCP_STATCR CURSOR FOR SPCP_STATSCR; */ 

		CheckSqlError("Declare SPCP_STATCR");

		/* EXEC SQL OPEN SPCP_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1204;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SPCP_STATCR;");


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

		/* EXEC SQL CLOSE SPCP_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1219;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH SPCP_STATCR INTO
			:pSource->asAreaCode,
			:pSource->asSpCode,
			:pSource->asSpServiceCode,
			:pSource->asSpAccNbr,
			:pSource->aiTicketTypeID,
			:pSource->asNetType,
			:pSource->asMsisdnHead,
			:pSource->asMsisdnBillingTypeID,
			:pSource->aiRentFee,
			:pSource->aiInfoFee,
			:pSource->aiOutcome,
			:pSource->asBillingCycleID,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1234;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )10;
  sqlstm.sqhsts[0] = (         int  )10;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asSpCode);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asSpServiceCode);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asSpAccNbr);
  sqlstm.sqhstl[3] = (unsigned long )13;
  sqlstm.sqhsts[3] = (         int  )13;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiTicketTypeID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asMsisdnHead);
  sqlstm.sqhstl[6] = (unsigned long )8;
  sqlstm.sqhsts[6] = (         int  )8;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asMsisdnBillingTypeID);
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )11;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiRentFee);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiInfoFee);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiOutcome);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[11] = (unsigned long )7;
  sqlstm.sqhsts[11] = (         int  )7;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[12] = (unsigned long )19;
  sqlstm.sqhsts[12] = (         int  )19;
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


		CheckSqlError("Fetch SPCP_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SPCP_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 27;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1301;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SPCP_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAreaCode,		pSource->asAreaCode[iCurPos]);
		strcpy(p->sSpCode,		pSource->asSpCode[iCurPos]);
		strcpy(p->sSpServiceCode,	pSource->asSpServiceCode[iCurPos]);
		strcpy(p->sSpAccNbr,		pSource->asSpAccNbr[iCurPos]);

		p->iTicketTypeID=		pSource->aiTicketTypeID[iCurPos];

		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);
		strcpy(p->sMsisdnHead,		pSource->asMsisdnHead[iCurPos]);
		strcpy(p->sMsisdnBillingTypeID,	pSource->asMsisdnBillingTypeID[iCurPos]);

		p->iRentFee=			pSource->aiRentFee[iCurPos];
		p->iInfoFee=			pSource->aiInfoFee[iCurPos];
		p->iOutcome=			pSource->aiOutcome[iCurPos];

		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);
		strcpy(p->sRowID,               pSource->asRowID[iCurPos]);

		AllTrim(p->sAreaCode);
		AllTrim(p->sSpCode);
		AllTrim(p->sSpServiceCode);
		AllTrim(p->sSpAccNbr);
		AllTrim(p->sNetType);
		AllTrim(p->sMsisdnHead);
		AllTrim(p->sMsisdnBillingTypeID);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*批量数据结构缓冲写入SPCP_STAT*/
int EInsertStructToSpcpStat(struct SpcpStatStruct *p,
	int iInsertFlag,struct SpcpStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAreaCode[iCurPos],		p->sAreaCode);
		strcpy(pTarget->asSpCode[iCurPos],		p->sSpCode);
		strcpy(pTarget->asSpServiceCode[iCurPos],	p->sSpServiceCode);
		strcpy(pTarget->asSpAccNbr[iCurPos],		p->sSpAccNbr);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);
		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);

		pTarget->aiRentFee[iCurPos]=			p->iRentFee;
		pTarget->aiInfoFee[iCurPos]=			p->iInfoFee;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;

		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SPCP_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				AREA_CODE,\n\
				SP_CODE,\n\
				SP_SERVICE_CODE,\n\
				SP_ACC_NBR,\n\
				TICKET_TYPE_ID,\n\
				NET_TYPE,\n\
				MSISDN_HEAD,\n\
				MSISDN_BILLING_TYPE_ID,\n\
				RENT_FEE,\n\
				INFO_FEE,\n\
				OUTCOME,\n\
				BILLING_CYCLE_ID)\n\
			VALUES (\n\
				:asAreaCode,\n\
				:asSpCode,\n\
				:asSpServiceCode,\n\
				:asSpAccNbr,\n\
				:aiTicketTypeID,\n\
				:asNetType,\n\
				:asMsisdnHead,\n\
				:asMsisdnBillingTypeID,\n\
				:aiRentFee,\n\
				:aiInfoFee,\n\
				:aiOutcome,\n\
				:asBillingCycleID\n\
			)",sTableName);

		/* EXEC SQL PREPARE SPCP_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1316;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare insert statement SPCP_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SPCP_STATTRG USING
				:pTarget->asAreaCode,
				:pTarget->asSpCode,
				:pTarget->asSpServiceCode,
				:pTarget->asSpAccNbr,
				:pTarget->aiTicketTypeID,
				:pTarget->asNetType,
				:pTarget->asMsisdnHead,
				:pTarget->asMsisdnBillingTypeID,
				:pTarget->aiRentFee,
				:pTarget->aiInfoFee,
				:pTarget->aiOutcome,
				:pTarget->asBillingCycleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1335;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )10;
  sqlstm.sqhsts[0] = (         int  )10;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asSpCode);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asSpServiceCode);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asSpAccNbr);
  sqlstm.sqhstl[3] = (unsigned long )13;
  sqlstm.sqhsts[3] = (         int  )13;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->aiTicketTypeID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asMsisdnHead);
  sqlstm.sqhstl[6] = (unsigned long )8;
  sqlstm.sqhsts[6] = (         int  )8;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asMsisdnBillingTypeID);
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )11;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->aiRentFee);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->aiInfoFee);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[11] = (unsigned long )7;
  sqlstm.sqhsts[11] = (         int  )7;
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


		if(CheckSqlResult("Dyn insert into SPCP_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据结构缓冲更新SPCP_STAT*/
int EUpdateStructToSpcpStat(struct SpcpStatStruct *p,
	int iUpdateFlag,struct SpcpStatStructUp *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAreaCode[iCurPos],		p->sAreaCode);
		strcpy(pTarget->asSpCode[iCurPos],		p->sSpCode);
		strcpy(pTarget->asSpServiceCode[iCurPos],	p->sSpServiceCode);
		strcpy(pTarget->asSpAccNbr[iCurPos],		p->sSpAccNbr);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);
		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);

		pTarget->aiRentFee[iCurPos]=			p->iRentFee;
		pTarget->aiInfoFee[iCurPos]=			p->iInfoFee;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;

		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);
		strcpy(pTarget->asRowID[iCurPos],               p->sRowID);

		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==SPCP_STAT_BUFLEN_UP){

/* Update */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s \n\
			SET \n\
				RENT_FEE	=:aiRentFee,\n\
				INFO_FEE	=:aiInfoFee,\n\
				OUTCOME		=:aiOutcome\n\
			WHERE \n\
                                ROWID = chartorowid(:asRowID)\n\
                        ",sTableName);

		/* EXEC SQL PREPARE SPCP_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1398;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare Update statement SPCP_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SPCP_STATTRG USING
				:pTarget->aiRentFee,
				:pTarget->aiInfoFee,
				:pTarget->aiOutcome,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1417;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiRentFee);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiInfoFee);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[3] = (unsigned long )19;
  sqlstm.sqhsts[3] = (         int  )19;
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


		if(CheckSqlResult("Dyn Update SPCP_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据动态从GPRS_1X_STAT中用结构缓冲方式取数据*/
int EGetGprs1xStatToStruct(struct Gprs1xStatStruct *p,
	struct Gprs1xStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(AREA_CODE,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(TICKET_TYPE_ID,0),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(MSISDN_HEAD,' '),\n\
				nvl(MSISDN_BILLING_TYPE_ID,' '),\n\
				nvl(FLOW_FEE,0),\n\
				nvl(INCOME,0),\n\
				nvl(OUTCOME,0),\n\
				nvl(DATA_FLOW,0),\n\
				to_char(nvl(SETT_ITEM_DATE,SYSDATE),'yyyymmddhh24miss'),\n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE GPRS_1X_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1448;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		CheckSqlError(" PREPARE GPRS_1X_STATSCR GPRS_1X_STATCR");

		/* EXEC SQL DECLARE GPRS_1X_STATCR CURSOR FOR GPRS_1X_STATSCR; */ 

		CheckSqlError("Declare GPRS_1X_STATCR");

		/* EXEC SQL OPEN GPRS_1X_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1467;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open GPRS_1X_STATCR;");


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

		/* EXEC SQL CLOSE GPRS_1X_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1482;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH GPRS_1X_STATCR INTO
			:pSource->asAreaCode,
			:pSource->asOppAreaCode,
			:pSource->aiTicketTypeID,
			:pSource->asNetType,
			:pSource->asMsisdnHead,
			:pSource->asMsisdnBillingTypeID,
			:pSource->aiFlowFee,
			:pSource->aiIncome,
			:pSource->aiOutcome,
			:pSource->aiDataFlow,
			:pSource->asSettItemDate,
			:pSource->asBillingCycleID,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1497;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )10;
  sqlstm.sqhsts[0] = (         int  )10;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiTicketTypeID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asMsisdnHead);
  sqlstm.sqhstl[4] = (unsigned long )8;
  sqlstm.sqhsts[4] = (         int  )8;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asMsisdnBillingTypeID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )11;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiFlowFee);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiIncome);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiOutcome);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiDataFlow);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[9] = (         int  )sizeof(long);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asSettItemDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[11] = (unsigned long )7;
  sqlstm.sqhsts[11] = (         int  )7;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[12] = (unsigned long )19;
  sqlstm.sqhsts[12] = (         int  )19;
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


		CheckSqlError("Fetch GPRS_1X_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE GPRS_1X_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 27;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1564;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=GPRS_1X_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAreaCode,		pSource->asAreaCode[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);

		p->iTicketTypeID=		pSource->aiTicketTypeID[iCurPos];

		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);
		strcpy(p->sMsisdnHead,		pSource->asMsisdnHead[iCurPos]);
		strcpy(p->sMsisdnBillingTypeID,	pSource->asMsisdnBillingTypeID[iCurPos]);

		p->iFlowFee=			pSource->aiFlowFee[iCurPos];
		p->iIncome=			pSource->aiIncome[iCurPos];
		p->iOutcome=			pSource->aiOutcome[iCurPos];
		p->iDataFlow=			pSource->aiDataFlow[iCurPos];

		strcpy(p->sSettItemDate,	pSource->asSettItemDate[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);
		strcpy(p->sRowID,               pSource->asRowID[iCurPos]);

		AllTrim(p->sAreaCode);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sNetType);
		AllTrim(p->sMsisdnHead);
		AllTrim(p->sMsisdnBillingTypeID);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sBillingCycleID);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入GPRS_1X_STAT*/
int EInsertStructToGprs1xStat(struct Gprs1xStatStruct *p,
	int iInsertFlag,struct Gprs1xStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAreaCode[iCurPos],		p->sAreaCode);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);
		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);

		pTarget->aiFlowFee[iCurPos]=			p->iFlowFee;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiDataFlow[iCurPos]=			p->iDataFlow;

		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==GPRS_1X_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				AREA_CODE,\n\
				OPP_AREA_CODE,\n\
				TICKET_TYPE_ID,\n\
				NET_TYPE,\n\
				MSISDN_HEAD,\n\
				MSISDN_BILLING_TYPE_ID,\n\
				FLOW_FEE,\n\
				INCOME,\n\
				OUTCOME,\n\
				DATA_FLOW,\n\
				SETT_ITEM_DATE,\n\
				BILLING_CYCLE_ID)\n\
			VALUES (\n\
				:asAreaCode,\n\
				:asOppAreaCode,\n\
				:aiTicketTypeID,\n\
				:asNetType,\n\
				:asMsisdnHead,\n\
				:asMsisdnBillingTypeID,\n\
				:aiFlowFee,\n\
				:aiIncome,\n\
				:aiOutcome,\n\
				:aiDataFlow,\n\
				to_date(:asSettItemDate,'yyyymmddhh24miss'),\n\
				:asBillingCycleID\n\
			)",sTableName);

		/* EXEC SQL PREPARE GPRS_1X_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1579;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare insert statement GPRS_1X_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE GPRS_1X_STATTRG USING
				:pTarget->asAreaCode,
				:pTarget->asOppAreaCode,
				:pTarget->aiTicketTypeID,
				:pTarget->asNetType,
				:pTarget->asMsisdnHead,
				:pTarget->asMsisdnBillingTypeID,
				:pTarget->aiFlowFee,
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiDataFlow,
				:pTarget->asSettItemDate,
				:pTarget->asBillingCycleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1598;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )10;
  sqlstm.sqhsts[0] = (         int  )10;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->aiTicketTypeID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asMsisdnHead);
  sqlstm.sqhstl[4] = (unsigned long )8;
  sqlstm.sqhsts[4] = (         int  )8;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asMsisdnBillingTypeID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )11;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiFlowFee);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->aiDataFlow);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[9] = (         int  )sizeof(long);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asSettItemDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[11] = (unsigned long )7;
  sqlstm.sqhsts[11] = (         int  )7;
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


		if(CheckSqlResult("Dyn insert into GPRS_1X_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据结构缓冲更新GPRS_1X_STAT*/
int EUpdateStructToGprs1xStat(struct Gprs1xStatStruct *p,
	int iUpdateFlag,struct Gprs1xStatStructUp *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAreaCode[iCurPos],		p->sAreaCode);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;

		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);
		strcpy(pTarget->asMsisdnHead[iCurPos],		p->sMsisdnHead);
		strcpy(pTarget->asMsisdnBillingTypeID[iCurPos],	p->sMsisdnBillingTypeID);

		pTarget->aiFlowFee[iCurPos]=			p->iFlowFee;
		pTarget->aiIncome[iCurPos]=			p->iIncome;
		pTarget->aiOutcome[iCurPos]=			p->iOutcome;
		pTarget->aiDataFlow[iCurPos]=			p->iDataFlow;
		
		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);
		strcpy(pTarget->asRowID[iCurPos],               p->sRowID);

		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==GPRS_1X_STAT_BUFLEN_UP){

/* Update */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s \n\
			SET \n\
				FLOW_FEE	=:aiFlowFee,\n\
				INCOME		=:aiIncome,\n\
				OUTCOME		=:aiOutcome,\n\
				DATA_FLOW	=:aiDataFlow\n\
			WHERE \n\
                                ROWID = chartorowid(:asRowID)\n\
                        ",sTableName);

		/* EXEC SQL PREPARE GPRS_1X_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1661;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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


		if(CheckSqlResult("Prepare Update statement GPRS_1X_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE GPRS_1X_STATTRG USING
				:pTarget->aiFlowFee,
				:pTarget->aiIncome,
				:pTarget->aiOutcome,
				:pTarget->aiDataFlow,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1680;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiFlowFee);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiIncome);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->aiOutcome);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiDataFlow);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[3] = (         int  )sizeof(long);
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


		if(CheckSqlResult("Dyn Update GPRS_1X_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

