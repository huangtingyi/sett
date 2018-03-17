
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "toll_voip193_supp.pc"
};


static unsigned int sqlctx = 85438715;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
5,0,0,1,0,0,17,46,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,52,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,69,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,77,0,0,11,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
113,0,0,1,0,0,15,101,0,0,0,0,0,1,0,
128,0,0,2,0,0,17,176,0,0,1,1,0,1,0,1,97,0,0,
147,0,0,2,0,0,45,182,0,0,0,0,0,1,0,
162,0,0,2,0,0,15,199,0,0,0,0,0,1,0,
177,0,0,2,0,0,13,207,0,0,9,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
228,0,0,2,0,0,15,229,0,0,0,0,0,1,0,
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
#include <stt_ticket.h>
#include "toll_voip193_supp.h"

/*批量数据动态从DATA_CALLING_STAT中用结构缓冲方式取数据*/
int EGetDataCallingStatToStruct(struct DataCallingStatStruct *p,
	struct DataCallingStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				nvl(CALLING_TYPE,' '),\n\
				nvl(CALLED_TYPE,' '),\n\
				nvl(CALLING_NET_TYPE,' '),\n\
				nvl(SERVICE_TYPE,' '),\n\
				to_char(nvl(TOLL_FEE,0)),\n\
				to_char(nvl(TOLL_SEC,0)),\n\
				nvl(CNT,0),\n\
				nvl(SETT_MONTH,' '),\n\
				to_char(nvl(DEAL_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE DATA_CALLING_STATSCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE DATA_CALLING_STATSCR DATA_CALLING_STATCR");

		/* EXEC SQL DECLARE DATA_CALLING_STATCR CURSOR FOR DATA_CALLING_STATSCR; */ 

		CheckSqlError("Declare DATA_CALLING_STATCR");

		/* EXEC SQL OPEN DATA_CALLING_STATCR; */ 

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
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open DATA_CALLING_STATCR;");


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

		/* EXEC SQL CLOSE DATA_CALLING_STATCR; */ 

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
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		return FALSE;
	}

	if(pSource->iBufEmpty||!pSource->iFetchRecNum){

/* FETCH */
		/* EXEC SQL FETCH DATA_CALLING_STATCR INTO
			:pSource->asCallingAreaCode,
			:pSource->asCalledAreaCode,
			:pSource->asCallingType,
			:pSource->asCalledType,
			:pSource->asCallingNetType,
			:pSource->asServiceType,
			:pSource->asTollFee,
			:pSource->asTollSec,
			:pSource->aiCnt,
			:pSource->asSettMonth,
			:pSource->asDealDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )54;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )10;
  sqlstm.sqhsts[0] = (         int  )10;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asCallingType);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )2;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCalledType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCallingNetType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asServiceType);
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )5;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asTollFee);
  sqlstm.sqhstl[6] = (unsigned long )13;
  sqlstm.sqhsts[6] = (         int  )13;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asTollSec);
  sqlstm.sqhstl[7] = (unsigned long )13;
  sqlstm.sqhsts[7] = (         int  )13;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asSettMonth);
  sqlstm.sqhstl[9] = (unsigned long )7;
  sqlstm.sqhsts[9] = (         int  )7;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asDealDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
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


		CheckSqlError("Fetch DATA_CALLING_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE DATA_CALLING_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 11;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )113;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=DATA_CALLING_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sCallingAreaCode,	pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCalledAreaCode,	pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sCallingType,		pSource->asCallingType[iCurPos]);
		strcpy(p->sCalledType,		pSource->asCalledType[iCurPos]);
		strcpy(p->sCallingNetType,	pSource->asCallingNetType[iCurPos]);
		strcpy(p->sServiceType,		pSource->asServiceType[iCurPos]);
		strcpy(p->sTollFee,		pSource->asTollFee[iCurPos]);
		strcpy(p->sTollSec,		pSource->asTollSec[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];

		strcpy(p->sSettMonth,		pSource->asSettMonth[iCurPos]);
		strcpy(p->sDealDate,		pSource->asDealDate[iCurPos]);

		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sCallingType);
		AllTrim(p->sCalledType);
		AllTrim(p->sCallingNetType);
		AllTrim(p->sServiceType);
		AllTrim(p->sTollFee);
		AllTrim(p->sTollSec);
		AllTrim(p->sSettMonth);
		AllTrim(p->sDealDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据动态从MOB_CALLED_STAT中用结构缓冲方式取数据*/
int EGetMobCalledStatToStruct(struct MobCalledStatStruct *p,
	struct MobCalledStatStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				nvl(CALLING_TYPE,' '),\n\
				nvl(CALLED_TYPE,' '),\n\
				to_char(nvl(TOLL_FEE,0)),\n\
				to_char(nvl(TOLL_SEC,0)),\n\
				nvl(CNT,0),\n\
				nvl(SETT_MONTH,' '),\n\
				to_char(nvl(DEAL_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE MOB_CALLED_STATSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )128;
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


		CheckSqlError(" PREPARE MOB_CALLED_STATSCR MOB_CALLED_STATCR");

		/* EXEC SQL DECLARE MOB_CALLED_STATCR CURSOR FOR MOB_CALLED_STATSCR; */ 

		CheckSqlError("Declare MOB_CALLED_STATCR");

		/* EXEC SQL OPEN MOB_CALLED_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )147;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open MOB_CALLED_STATCR;");


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

		/* EXEC SQL CLOSE MOB_CALLED_STATCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )162;
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
		/* EXEC SQL FETCH MOB_CALLED_STATCR INTO
			:pSource->asCallingAreaCode,
			:pSource->asCalledAreaCode,
			:pSource->asCallingType,
			:pSource->asCalledType,
			:pSource->asTollFee,
			:pSource->asTollSec,
			:pSource->aiCnt,
			:pSource->asSettMonth,
			:pSource->asDealDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )177;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[0] = (unsigned long )10;
  sqlstm.sqhsts[0] = (         int  )10;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asCallingType);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )2;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCalledType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asTollFee);
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )13;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asTollSec);
  sqlstm.sqhstl[5] = (unsigned long )13;
  sqlstm.sqhsts[5] = (         int  )13;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSettMonth);
  sqlstm.sqhstl[7] = (unsigned long )7;
  sqlstm.sqhsts[7] = (         int  )7;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asDealDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
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


		CheckSqlError("Fetch MOB_CALLED_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE MOB_CALLED_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 11;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )228;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=MOB_CALLED_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sCallingAreaCode,	pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCalledAreaCode,	pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sCallingType,		pSource->asCallingType[iCurPos]);
		strcpy(p->sCalledType,		pSource->asCalledType[iCurPos]);
		strcpy(p->sTollFee,		pSource->asTollFee[iCurPos]);
		strcpy(p->sTollSec,		pSource->asTollSec[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];

		strcpy(p->sSettMonth,		pSource->asSettMonth[iCurPos]);
		strcpy(p->sDealDate,		pSource->asDealDate[iCurPos]);

		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sCallingType);
		AllTrim(p->sCalledType);
		AllTrim(p->sTollFee);
		AllTrim(p->sTollSec);
		AllTrim(p->sSettMonth);
		AllTrim(p->sDealDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

void mvitem_voip193recordstruct(struct DataCallingStatStruct *pi,
	struct Voip193RecordStruct *po)
{/*数据移动部分*/

	char sCityCode[9];
	bzero((void*)po,sizeof(struct Voip193RecordStruct));

	GenCityCode(pi->sCallingAreaCode,sCityCode);
	strncpy(po->sInCityCode,	sCityCode,3);
	po->sInCityCode[3]=0;
	GenCityCode(pi->sCalledAreaCode,sCityCode);
	strncpy(po->sOutCityCode,	sCityCode,3);
	po->sOutCityCode[3]=0;
	if(strncmp(pi->sServiceType,"CARD",4)==0){
		if(strcmp(pi->sCalledType,"G")==0){
			po->iTollFee1	=atoi(pi->sTollFee);
			po->iDuration1	=atoi(pi->sTollSec)*6;
			po->iCnt1	=pi->iCnt;
		}
		else if(strcmp(pi->sCalledType,"C")==0){
			po->iTollFee2	=atoi(pi->sTollFee);
        	        po->iDuration2	=atoi(pi->sTollSec)*6;
		        po->iCnt2	=pi->iCnt;
		}
		else if(strcmp(pi->sCalledType,"X")==0){
		        po->iTollFee3	=atoi(pi->sTollFee);
			po->iDuration3	=atoi(pi->sTollSec)*6;
			po->iCnt3	=pi->iCnt;
		}
	}
	else if(strncmp(pi->sServiceType,"LINE",4)==0){
		if(strcmp(pi->sCalledType,"G")==0){
			po->iTollFee4	=atoi(pi->sTollFee);
			po->iDuration4	=atoi(pi->sTollSec)*6;
			po->iCnt4	=pi->iCnt;
		}
		else if(strcmp(pi->sCalledType,"C")==0){
			po->iTollFee5	=atoi(pi->sTollFee);
        	        po->iDuration5	=atoi(pi->sTollSec)*6;
		        po->iCnt5	=pi->iCnt;
		}
		else if(strcmp(pi->sCalledType,"X")==0){
		        po->iTollFee6	=atoi(pi->sTollFee);
			po->iDuration6	=atoi(pi->sTollSec)*6;
			po->iCnt6	=pi->iCnt;
		}
	}
}
void mvitem_tollrecordstruct(struct MobCalledStatStruct *pi,
	struct TollRecordStruct *po)
{/*数据移动部分*/

	char sCityCode[9];
	bzero((void*)po,sizeof(struct TollRecordStruct));

	GenCityCode(pi->sCallingAreaCode,sCityCode);
	strncpy(po->sInCityCode,	sCityCode,3);
	po->sInCityCode[3]=0;
	GenCityCode(pi->sCalledAreaCode,sCityCode);
	strncpy(po->sOutCityCode,	sCityCode,3);
	po->sOutCityCode[3]=0;

	if(strcmp(pi->sCalledType,"G")==0){
		po->iTollFee1	=atoi(pi->sTollFee);
		po->iDuration1	=atoi(pi->sTollSec)*6;
		po->iCnt1	=pi->iCnt;
	}
	else if(strcmp(pi->sCalledType,"C")==0){
		po->iTollFee2	=atoi(pi->sTollFee);
                po->iDuration2	=atoi(pi->sTollSec)*6;
	        po->iCnt2	=pi->iCnt;
	}
	else if(strcmp(pi->sCalledType,"X")==0){
	        po->iTollFee3	=atoi(pi->sTollFee);
		po->iDuration3	=atoi(pi->sTollSec)*6;
		po->iCnt3	=pi->iCnt;
	}
}
