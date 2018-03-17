
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "high_supp.pc"
};


static unsigned int sqlctx = 299515;


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
   unsigned char  *sqhstv[44];
   unsigned long  sqhstl[44];
            int   sqhsts[44];
            short *sqindv[44];
            int   sqinds[44];
   unsigned long  sqharm[44];
   unsigned long  *sqharc[44];
   unsigned short  sqadto[44];
   unsigned short  sqtdso[44];
} sqlstm = {12,44};

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
5,0,0,1,0,0,17,46,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,52,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,69,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,77,0,0,8,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,
101,0,0,1,0,0,15,98,0,0,0,0,0,1,0,
116,0,0,2,0,0,17,201,0,0,1,1,0,1,0,1,97,0,0,
135,0,0,2,0,0,45,207,0,0,0,0,0,1,0,
150,0,0,2,0,0,15,224,0,0,0,0,0,1,0,
165,0,0,2,0,0,13,232,0,0,44,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
356,0,0,2,0,0,15,289,0,0,0,0,0,1,0,
371,0,0,3,0,0,17,423,0,0,1,1,0,1,0,1,97,0,0,
390,0,0,3,0,0,45,429,0,0,0,0,0,1,0,
405,0,0,3,0,0,15,446,0,0,0,0,0,1,0,
420,0,0,3,0,0,13,454,0,0,2,0,0,1,0,2,3,0,0,2,3,0,0,
443,0,0,3,0,0,15,469,0,0,0,0,0,1,0,
458,0,0,4,0,0,17,751,0,0,1,1,0,1,0,1,97,0,0,
477,0,0,4,0,0,21,754,0,0,43,43,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,
664,0,0,5,0,0,17,836,0,0,1,1,0,1,0,1,97,0,0,
683,0,0,5,0,0,21,839,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
706,0,0,6,0,0,17,893,0,0,1,1,0,1,0,1,97,0,0,
725,0,0,6,0,0,45,899,0,0,0,0,0,1,0,
740,0,0,6,0,0,15,916,0,0,0,0,0,1,0,
755,0,0,6,0,0,13,924,0,0,22,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
858,0,0,6,0,0,15,959,0,0,0,0,0,1,0,
873,0,0,7,0,0,17,1121,0,0,1,1,0,1,0,1,97,0,0,
892,0,0,7,0,0,21,1124,0,0,22,22,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
995,0,0,8,0,0,17,1174,0,0,1,1,0,1,0,1,97,0,0,
1014,0,0,8,0,0,45,1180,0,0,0,0,0,1,0,
1029,0,0,8,0,0,13,1186,0,0,5,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,
1064,0,0,8,0,0,15,1195,0,0,0,0,0,1,0,
1079,0,0,8,0,0,15,1198,0,0,0,0,0,1,0,
1094,0,0,9,52,0,4,1215,0,0,1,0,0,1,0,2,3,0,0,
1113,0,0,10,0,0,17,1249,0,0,1,1,0,1,0,1,97,0,0,
1132,0,0,10,0,0,21,1252,0,0,5,5,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,
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

#include "../include/extend_intf.h"
#include "../include/stt_ticket.h"
#include "high_supp.h"


/*批量数据动态从IMEI_UP中用结构缓冲方式取数据*/
int EGetImeiUpToStruct(struct ImeiUpStruct *p,
	struct ImeiUpStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(RS_SEQ,' '),\n\
				MSISDN,\n\
				IMEI,\n\
				IMSI,\n\
				nvl(CALLSTARTTIME,' '),\n\
				nvl(MATCHITEM,' '),\n\
				nvl(TYPE,' '),\n\
				nvl(CREATETIME,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE IMEI_UPSCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE IMEI_UPSCR IMEI_UPCR");

		/* EXEC SQL DECLARE IMEI_UPCR CURSOR FOR IMEI_UPSCR; */ 

		CheckSqlError("Declare IMEI_UPCR");

		/* EXEC SQL OPEN IMEI_UPCR; */ 

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


		CheckSqlError("Open IMEI_UPCR;");


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

		/* EXEC SQL CLOSE IMEI_UPCR; */ 

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
		/* EXEC SQL FETCH IMEI_UPCR INTO
			:pSource->asRsSeq,
			:pSource->asMsisdn,
			:pSource->asImei,
			:pSource->asImsi,
			:pSource->asCallstarttime,
			:pSource->asMatchitem,
			:pSource->asType,
			:pSource->asCreatetime; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
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
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asRsSeq);
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )19;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[1] = (unsigned long )21;
  sqlstm.sqhsts[1] = (         int  )21;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asImei);
  sqlstm.sqhstl[2] = (unsigned long )31;
  sqlstm.sqhsts[2] = (         int  )31;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asImsi);
  sqlstm.sqhstl[3] = (unsigned long )21;
  sqlstm.sqhsts[3] = (         int  )21;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCallstarttime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asMatchitem);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asType);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCreatetime);
  sqlstm.sqhstl[7] = (unsigned long )21;
  sqlstm.sqhsts[7] = (         int  )21;
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


		CheckSqlError("Fetch IMEI_UPCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE IMEI_UPCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 8;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )101;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=IMEI_UP_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sRsSeq,		pSource->asRsSeq[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sImei,		pSource->asImei[iCurPos]);
		strcpy(p->sImsi,		pSource->asImsi[iCurPos]);
		strcpy(p->sCallstarttime,	pSource->asCallstarttime[iCurPos]);
		strcpy(p->sMatchitem,		pSource->asMatchitem[iCurPos]);
		strcpy(p->sType,		pSource->asType[iCurPos]);
		strcpy(p->sCreatetime,		pSource->asCreatetime[iCurPos]);

		AllTrim(p->sRsSeq);
		AllTrim(p->sMsisdn);
		AllTrim(p->sImei);
		AllTrim(p->sImsi);
		AllTrim(p->sCallstarttime);
		AllTrim(p->sMatchitem);
		AllTrim(p->sType);
		AllTrim(p->sCreatetime);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据动态从PSTN_DETAIL_TICKET中用结构缓冲方式取数据*/
int EGetPstnDetailTicketToStruct(struct PstnDetailTicketStruct *p,
	struct PstnDetailTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(RECORD_TYPE,' '),\n\
				nvl(COMPANY,' '),\n\
				nvl(REFERENCE,' '),\n\
				nvl(NONE,' '),\n\
				nvl(IMSI,' '),\n\
				nvl(CALLING_NBR,' '),\n\
				nvl(MODIFY_INS,' '),\n\
				nvl(NUMBER_TYPE,' '),\n\
				nvl(PICK_PROGRAM,' '),\n\
				nvl(CALLED_NBR,' '),\n\
				nvl(SERVICE_TYPE,' '),\n\
				nvl(SERVICE_NBR,' '),\n\
				nvl(DUAL_TYPE,' '),\n\
				nvl(DUAL_NBR,' '),\n\
				nvl(REQ_CHANNEL,' '),\n\
				nvl(USE_CHANNEL,' '),\n\
				nvl(SERVICE_TRAN,' '),\n\
				nvl(ACTIVITY_CODE1,' '),\n\
				nvl(ADD_ACTIVITY_CODE1,' '),\n\
				nvl(ACTIVITY_CODE2,' '),\n\
				nvl(ADD_ACTIVITY_CODE2,' '),\n\
				nvl(ACTIVITY_CODE3,' '),\n\
				nvl(ADD_ACTIVITY_CODE3,' '),\n\
				nvl(ACTIVITY_CODE4,' '),\n\
				nvl(ADD_ACTIVITY_CODE4,' '),\n\
				nvl(ACTIVITY_CODE5,' '),\n\
				nvl(ADD_ACTIVITY_CODE5,' '),\n\
				nvl(MSC,' '),\n\
				nvl(LAC,' '),\n\
				nvl(CELLULAR_SIGNS,' '),\n\
				nvl(MOBILE_CODE,' '),\n\
				nvl(CALL_TIME,' '),\n\
				nvl(PAY_UNITS,' '),\n\
				nvl(AMOUNT_DATA,' '),\n\
				nvl(TOLL_FEE,0),\n\
				nvl(TOLL_PROJECTS,' '),\n\
				nvl(TAX_RATE,' '),\n\
				nvl(RATE_1,' '),\n\
				nvl(RETENTION,' '),\n\
				nvl(RATE_2,' '),\n\
				nvl(SDR,0),\n\
				nvl(STATE,' '),\n\
				nvl(FILE_NAME,' '),\n\
				rowidtochar(ROWID) \n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PSTN_DETAIL_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )116;
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


		CheckSqlError(" PREPARE PSTN_DETAIL_TICKETSCR PSTN_DETAIL_TICKETCR");

		/* EXEC SQL DECLARE PSTN_DETAIL_TICKETCR CURSOR FOR PSTN_DETAIL_TICKETSCR; */ 

		CheckSqlError("Declare PSTN_DETAIL_TICKETCR");

		/* EXEC SQL OPEN PSTN_DETAIL_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )135;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PSTN_DETAIL_TICKETCR;");


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

		/* EXEC SQL CLOSE PSTN_DETAIL_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )150;
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
		/* EXEC SQL FETCH PSTN_DETAIL_TICKETCR INTO
			:pSource->asRecordType,
			:pSource->asCompany,
			:pSource->asReference,
			:pSource->asNone,
			:pSource->asImsi,
			:pSource->asCallingNbr,
			:pSource->asModifyIns,
			:pSource->asNumberType,
			:pSource->asPickProgram,
			:pSource->asCalledNbr,
			:pSource->asServiceType,
			:pSource->asServiceNbr,
			:pSource->asDualType,
			:pSource->asDualNbr,
			:pSource->asReqChannel,
			:pSource->asUseChannel,
			:pSource->asServiceTran,
			:pSource->asActivityCode1,
			:pSource->asAddActivityCode1,
			:pSource->asActivityCode2,
			:pSource->asAddActivityCode2,
			:pSource->asActivityCode3,
			:pSource->asAddActivityCode3,
			:pSource->asActivityCode4,
			:pSource->asAddActivityCode4,
			:pSource->asActivityCode5,
			:pSource->asAddActivityCode5,
			:pSource->asMsc,
			:pSource->asLac,
			:pSource->asCellularSigns,
			:pSource->asMobileCode,
			:pSource->asCallTime,
			:pSource->asPayUnits,
			:pSource->asAmountData,
			:pSource->aiTollFee,
			:pSource->asTollProjects,
			:pSource->asTaxRate,
			:pSource->asRate1,
			:pSource->asRetention,
			:pSource->asRate2,
			:pSource->aiSdr,
			:pSource->asState,
			:pSource->asFileName,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )165;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asRecordType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCompany);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asReference);
  sqlstm.sqhstl[2] = (unsigned long )7;
  sqlstm.sqhsts[2] = (         int  )7;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asNone);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asImsi);
  sqlstm.sqhstl[4] = (unsigned long )16;
  sqlstm.sqhsts[4] = (         int  )16;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCallingNbr);
  sqlstm.sqhstl[5] = (unsigned long )26;
  sqlstm.sqhsts[5] = (         int  )26;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asModifyIns);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asNumberType);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asPickProgram);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asCalledNbr);
  sqlstm.sqhstl[9] = (unsigned long )26;
  sqlstm.sqhsts[9] = (         int  )26;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asServiceType);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asServiceNbr);
  sqlstm.sqhstl[11] = (unsigned long )9;
  sqlstm.sqhsts[11] = (         int  )9;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asDualType);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asDualNbr);
  sqlstm.sqhstl[13] = (unsigned long )3;
  sqlstm.sqhsts[13] = (         int  )3;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asReqChannel);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asUseChannel);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asServiceTran);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asActivityCode1);
  sqlstm.sqhstl[17] = (unsigned long )2;
  sqlstm.sqhsts[17] = (         int  )2;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asAddActivityCode1);
  sqlstm.sqhstl[18] = (unsigned long )3;
  sqlstm.sqhsts[18] = (         int  )3;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asActivityCode2);
  sqlstm.sqhstl[19] = (unsigned long )2;
  sqlstm.sqhsts[19] = (         int  )2;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asAddActivityCode2);
  sqlstm.sqhstl[20] = (unsigned long )3;
  sqlstm.sqhsts[20] = (         int  )3;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asActivityCode3);
  sqlstm.sqhstl[21] = (unsigned long )2;
  sqlstm.sqhsts[21] = (         int  )2;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asAddActivityCode3);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asActivityCode4);
  sqlstm.sqhstl[23] = (unsigned long )2;
  sqlstm.sqhsts[23] = (         int  )2;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asAddActivityCode4);
  sqlstm.sqhstl[24] = (unsigned long )3;
  sqlstm.sqhsts[24] = (         int  )3;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asActivityCode5);
  sqlstm.sqhstl[25] = (unsigned long )2;
  sqlstm.sqhsts[25] = (         int  )2;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->asAddActivityCode5);
  sqlstm.sqhstl[26] = (unsigned long )3;
  sqlstm.sqhsts[26] = (         int  )3;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[27] = (unsigned long )16;
  sqlstm.sqhsts[27] = (         int  )16;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->asLac);
  sqlstm.sqhstl[28] = (unsigned long )6;
  sqlstm.sqhsts[28] = (         int  )6;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pSource->asCellularSigns);
  sqlstm.sqhstl[29] = (unsigned long )6;
  sqlstm.sqhsts[29] = (         int  )6;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pSource->asMobileCode);
  sqlstm.sqhstl[30] = (unsigned long )2;
  sqlstm.sqhsts[30] = (         int  )2;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pSource->asCallTime);
  sqlstm.sqhstl[31] = (unsigned long )15;
  sqlstm.sqhsts[31] = (         int  )15;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pSource->asPayUnits);
  sqlstm.sqhstl[32] = (unsigned long )7;
  sqlstm.sqhsts[32] = (         int  )7;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pSource->asAmountData);
  sqlstm.sqhstl[33] = (unsigned long )7;
  sqlstm.sqhsts[33] = (         int  )7;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pSource->aiTollFee);
  sqlstm.sqhstl[34] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[34] = (         int  )sizeof(int);
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pSource->asTollProjects);
  sqlstm.sqhstl[35] = (unsigned long )2;
  sqlstm.sqhsts[35] = (         int  )2;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pSource->asTaxRate);
  sqlstm.sqhstl[36] = (unsigned long )11;
  sqlstm.sqhsts[36] = (         int  )11;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pSource->asRate1);
  sqlstm.sqhstl[37] = (unsigned long )11;
  sqlstm.sqhsts[37] = (         int  )11;
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pSource->asRetention);
  sqlstm.sqhstl[38] = (unsigned long )18;
  sqlstm.sqhsts[38] = (         int  )18;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pSource->asRate2);
  sqlstm.sqhstl[39] = (unsigned long )11;
  sqlstm.sqhsts[39] = (         int  )11;
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pSource->aiSdr);
  sqlstm.sqhstl[40] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[40] = (         int  )sizeof(int);
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[41] = (unsigned long )3;
  sqlstm.sqhsts[41] = (         int  )3;
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[42] = (unsigned long )33;
  sqlstm.sqhsts[42] = (         int  )33;
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqharc[42] = (unsigned long  *)0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[43] = (unsigned long )19;
  sqlstm.sqhsts[43] = (         int  )19;
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqharc[43] = (unsigned long  *)0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
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


		CheckSqlError("Fetch PSTN_DETAIL_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PSTN_DETAIL_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )356;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PSTN_DETAIL_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sRecordType,		pSource->asRecordType[iCurPos]);
		strcpy(p->sCompany,		pSource->asCompany[iCurPos]);
		strcpy(p->sReference,		pSource->asReference[iCurPos]);
		strcpy(p->sNone,		pSource->asNone[iCurPos]);
		strcpy(p->sImsi,		pSource->asImsi[iCurPos]);
		strcpy(p->sCallingNbr,		pSource->asCallingNbr[iCurPos]);
		strcpy(p->sModifyIns,		pSource->asModifyIns[iCurPos]);
		strcpy(p->sNumberType,		pSource->asNumberType[iCurPos]);
		strcpy(p->sPickProgram,		pSource->asPickProgram[iCurPos]);
		strcpy(p->sCalledNbr,		pSource->asCalledNbr[iCurPos]);
		strcpy(p->sServiceType,		pSource->asServiceType[iCurPos]);
		strcpy(p->sServiceNbr,		pSource->asServiceNbr[iCurPos]);
		strcpy(p->sDualType,		pSource->asDualType[iCurPos]);
		strcpy(p->sDualNbr,		pSource->asDualNbr[iCurPos]);
		strcpy(p->sReqChannel,		pSource->asReqChannel[iCurPos]);
		strcpy(p->sUseChannel,		pSource->asUseChannel[iCurPos]);
		strcpy(p->sServiceTran,		pSource->asServiceTran[iCurPos]);
		strcpy(p->sActivityCode1,	pSource->asActivityCode1[iCurPos]);
		strcpy(p->sAddActivityCode1,	pSource->asAddActivityCode1[iCurPos]);
		strcpy(p->sActivityCode2,	pSource->asActivityCode2[iCurPos]);
		strcpy(p->sAddActivityCode2,	pSource->asAddActivityCode2[iCurPos]);
		strcpy(p->sActivityCode3,	pSource->asActivityCode3[iCurPos]);
		strcpy(p->sAddActivityCode3,	pSource->asAddActivityCode3[iCurPos]);
		strcpy(p->sActivityCode4,	pSource->asActivityCode4[iCurPos]);
		strcpy(p->sAddActivityCode4,	pSource->asAddActivityCode4[iCurPos]);
		strcpy(p->sActivityCode5,	pSource->asActivityCode5[iCurPos]);
		strcpy(p->sAddActivityCode5,	pSource->asAddActivityCode5[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sLac,			pSource->asLac[iCurPos]);
		strcpy(p->sCellularSigns,	pSource->asCellularSigns[iCurPos]);
		strcpy(p->sMobileCode,		pSource->asMobileCode[iCurPos]);
		strcpy(p->sCallTime,		pSource->asCallTime[iCurPos]);
		strcpy(p->sPayUnits,		pSource->asPayUnits[iCurPos]);
		strcpy(p->sAmountData,		pSource->asAmountData[iCurPos]);

		p->iTollFee=			pSource->aiTollFee[iCurPos];

		strcpy(p->sTollProjects,	pSource->asTollProjects[iCurPos]);
		strcpy(p->sTaxRate,		pSource->asTaxRate[iCurPos]);
		strcpy(p->sRate1,		pSource->asRate1[iCurPos]);
		strcpy(p->sRetention,		pSource->asRetention[iCurPos]);
		strcpy(p->sRate2,		pSource->asRate2[iCurPos]);

		p->iSdr=			pSource->aiSdr[iCurPos];

		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sRowID,		pSource->asRowID[iCurPos]);
		
		AllTrim(p->sRecordType);
		AllTrim(p->sCompany);
		AllTrim(p->sReference);
		AllTrim(p->sNone);
		AllTrim(p->sImsi);
		AllTrim(p->sCallingNbr);
		AllTrim(p->sModifyIns);
		AllTrim(p->sNumberType);
		AllTrim(p->sPickProgram);
		AllTrim(p->sCalledNbr);
		AllTrim(p->sServiceType);
		AllTrim(p->sServiceNbr);
		AllTrim(p->sDualType);
		AllTrim(p->sDualNbr);
		AllTrim(p->sReqChannel);
		AllTrim(p->sUseChannel);
		AllTrim(p->sServiceTran);
		AllTrim(p->sActivityCode1);
		AllTrim(p->sAddActivityCode1);
		AllTrim(p->sActivityCode2);
		AllTrim(p->sAddActivityCode2);
		AllTrim(p->sActivityCode3);
		AllTrim(p->sAddActivityCode3);
		AllTrim(p->sActivityCode4);
		AllTrim(p->sAddActivityCode4);
		AllTrim(p->sActivityCode5);
		AllTrim(p->sAddActivityCode5);
		AllTrim(p->sMsc);
		AllTrim(p->sLac);
		AllTrim(p->sCellularSigns);
		AllTrim(p->sMobileCode);
		AllTrim(p->sCallTime);
		AllTrim(p->sPayUnits);
		AllTrim(p->sAmountData);
		AllTrim(p->sTollProjects);
		AllTrim(p->sTaxRate);
		AllTrim(p->sRate1);
		AllTrim(p->sRetention);
		AllTrim(p->sRate2);
		AllTrim(p->sState);
		AllTrim(p->sFileName);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*时间条件*/
int EGetPstnDetailTicketToStructByDate(struct PstnDetailTicketStruct *p,
	struct PstnDetailTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(TOLL_FEE,0),\n\
				nvl(SDR,0) \n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PSTN_DETAIL_TICKETSCR2 FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )371;
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


		CheckSqlError(" PREPARE PSTN_DETAIL_TICKETSCR2 PSTN_DETAIL_TICKETCR2");

		/* EXEC SQL DECLARE PSTN_DETAIL_TICKETCR2 CURSOR FOR PSTN_DETAIL_TICKETSCR2; */ 

		CheckSqlError("Declare PSTN_DETAIL_TICKETCR2");

		/* EXEC SQL OPEN PSTN_DETAIL_TICKETCR2; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )390;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PSTN_DETAIL_TICKETCR2;");


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

		/* EXEC SQL CLOSE PSTN_DETAIL_TICKETCR2; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )405;
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
		/* EXEC SQL FETCH PSTN_DETAIL_TICKETCR2 INTO
			:pSource->aiTollFee,
			:pSource->aiSdr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )420;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTollFee);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSdr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
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


		CheckSqlError("Fetch PSTN_DETAIL_TICKETCR2");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PSTN_DETAIL_TICKETCR2; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )443;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PSTN_DETAIL_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/

		p->iTollFee=			pSource->aiTollFee[iCurPos];
		p->iSdr=			pSource->aiSdr[iCurPos];

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_fmpstndetailticket(struct FPstnDetailTicketStruct *pi,struct PstnDetailTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct PstnDetailTicketStruct));

		strncpy(po->sRecordType,	pi->sRecordType,2);
		strncpy(po->sCompany,		pi->sCompany,5);
		strncpy(po->sReference,		pi->sReference,6);
		strncpy(po->sNone,		pi->sNone,1);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sCallingNbr,	pi->sCallingNbr,25);
		strncpy(po->sModifyIns,		pi->sModifyIns,1);
		strncpy(po->sNumberType,	pi->sNumberType,1);
		strncpy(po->sPickProgram,	pi->sPickProgram,1);
		strncpy(po->sCalledNbr,		pi->sCalledNbr,25);
		strncpy(po->sServiceType,	pi->sServiceType,1);
		strncpy(po->sServiceNbr,	pi->sServiceNbr,8);
		strncpy(po->sDualType,		pi->sDualType,1);
		strncpy(po->sDualNbr,		pi->sDualNbr,2);
		strncpy(po->sReqChannel,	pi->sReqChannel,1);
		strncpy(po->sUseChannel,	pi->sUseChannel,1);
		strncpy(po->sServiceTran,	pi->sServiceTran,1);
		strncpy(po->sActivityCode1,	pi->sActivityCode1,1);
		strncpy(po->sAddActivityCode1,	pi->sAddActivityCode1,2);
		strncpy(po->sActivityCode2,	pi->sActivityCode2,1);
		strncpy(po->sAddActivityCode2,	pi->sAddActivityCode2,2);
		strncpy(po->sActivityCode3,	pi->sActivityCode3,1);
		strncpy(po->sAddActivityCode3,	pi->sAddActivityCode3,2);
		strncpy(po->sActivityCode4,	pi->sActivityCode4,1);
		strncpy(po->sAddActivityCode4,	pi->sAddActivityCode4,2);
		strncpy(po->sActivityCode5,	pi->sActivityCode5,1);
		strncpy(po->sAddActivityCode5,	pi->sAddActivityCode5,2);
		strncpy(po->sMsc,		pi->sMsc,15);
		strncpy(po->sLac,		pi->sLac,5);
		strncpy(po->sCellularSigns,	pi->sCellularSigns,5);
		strncpy(po->sMobileCode,	pi->sMobileCode,1);
		strncpy(po->sCallTime,		pi->sCallTime,14);
		strncpy(po->sPayUnits,		pi->sPayUnits,6);
		strncpy(po->sAmountData,	pi->sAmountData,6);

		strncpy(sTemp,		pi->sTollFee,9);sTemp[9]=0;
		po->iTollFee=atoi(sTemp);

		strncpy(po->sTollProjects,	pi->sTollProjects,1);
		strncpy(po->sTaxRate,		pi->sTaxRate,10);
		strncpy(po->sRate1,		pi->sRate1,10);
		strncpy(po->sRetention,		pi->sRetention,17);
		strncpy(po->sRate2,		pi->sRate2,10);

		strncpy(sTemp,		pi->sSdr,9);sTemp[9]=0;
		po->iSdr=atoi(sTemp);


		AllTrim(po->sRecordType);
		AllTrim(po->sCompany);
		AllTrim(po->sReference);
		AllTrim(po->sNone);
		AllTrim(po->sImsi);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sModifyIns);
		AllTrim(po->sNumberType);
		AllTrim(po->sPickProgram);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceNbr);
		AllTrim(po->sDualType);
		AllTrim(po->sDualNbr);
		AllTrim(po->sReqChannel);
		AllTrim(po->sUseChannel);
		AllTrim(po->sServiceTran);
		AllTrim(po->sActivityCode1);
		AllTrim(po->sAddActivityCode1);
		AllTrim(po->sActivityCode2);
		AllTrim(po->sAddActivityCode2);
		AllTrim(po->sActivityCode3);
		AllTrim(po->sAddActivityCode3);
		AllTrim(po->sActivityCode4);
		AllTrim(po->sAddActivityCode4);
		AllTrim(po->sActivityCode5);
		AllTrim(po->sAddActivityCode5);
		AllTrim(po->sMsc);
		AllTrim(po->sLac);
		AllTrim(po->sCellularSigns);
		AllTrim(po->sMobileCode);
		AllTrim(po->sCallTime);
		AllTrim(po->sPayUnits);
		AllTrim(po->sAmountData);
		AllTrim(po->sTollProjects);
		AllTrim(po->sTaxRate);
		AllTrim(po->sRate1);
		AllTrim(po->sRetention);
		AllTrim(po->sRate2);
		
}

/*批量数据结构缓冲写入PSTN_DETAIL_TICKET*/
int EInsertStructToPstnDetailTicket(struct PstnDetailTicketStruct *p,
	int iInsertFlag,struct PstnDetailTicketStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asRecordType[iCurPos],		p->sRecordType);
		strcpy(pTarget->asCompany[iCurPos],		p->sCompany);
		strcpy(pTarget->asReference[iCurPos],		p->sReference);
		strcpy(pTarget->asNone[iCurPos],		p->sNone);
		strcpy(pTarget->asImsi[iCurPos],		p->sImsi);
		strcpy(pTarget->asCallingNbr[iCurPos],		p->sCallingNbr);
		strcpy(pTarget->asModifyIns[iCurPos],		p->sModifyIns);
		strcpy(pTarget->asNumberType[iCurPos],		p->sNumberType);
		strcpy(pTarget->asPickProgram[iCurPos],		p->sPickProgram);
		strcpy(pTarget->asCalledNbr[iCurPos],		p->sCalledNbr);
		strcpy(pTarget->asServiceType[iCurPos],		p->sServiceType);
		strcpy(pTarget->asServiceNbr[iCurPos],		p->sServiceNbr);
		strcpy(pTarget->asDualType[iCurPos],		p->sDualType);
		strcpy(pTarget->asDualNbr[iCurPos],		p->sDualNbr);
		strcpy(pTarget->asReqChannel[iCurPos],		p->sReqChannel);
		strcpy(pTarget->asUseChannel[iCurPos],		p->sUseChannel);
		strcpy(pTarget->asServiceTran[iCurPos],		p->sServiceTran);
		strcpy(pTarget->asActivityCode1[iCurPos],	p->sActivityCode1);
		strcpy(pTarget->asAddActivityCode1[iCurPos],	p->sAddActivityCode1);
		strcpy(pTarget->asActivityCode2[iCurPos],	p->sActivityCode2);
		strcpy(pTarget->asAddActivityCode2[iCurPos],	p->sAddActivityCode2);
		strcpy(pTarget->asActivityCode3[iCurPos],	p->sActivityCode3);
		strcpy(pTarget->asAddActivityCode3[iCurPos],	p->sAddActivityCode3);
		strcpy(pTarget->asActivityCode4[iCurPos],	p->sActivityCode4);
		strcpy(pTarget->asAddActivityCode4[iCurPos],	p->sAddActivityCode4);
		strcpy(pTarget->asActivityCode5[iCurPos],	p->sActivityCode5);
		strcpy(pTarget->asAddActivityCode5[iCurPos],	p->sAddActivityCode5);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asLac[iCurPos],			p->sLac);
		strcpy(pTarget->asCellularSigns[iCurPos],	p->sCellularSigns);
		strcpy(pTarget->asMobileCode[iCurPos],		p->sMobileCode);
		strcpy(pTarget->asCallTime[iCurPos],		p->sCallTime);
		strcpy(pTarget->asPayUnits[iCurPos],		p->sPayUnits);
		strcpy(pTarget->asAmountData[iCurPos],		p->sAmountData);

		pTarget->aiTollFee[iCurPos]=			p->iTollFee;

		strcpy(pTarget->asTollProjects[iCurPos],	p->sTollProjects);
		strcpy(pTarget->asTaxRate[iCurPos],		p->sTaxRate);
		strcpy(pTarget->asRate1[iCurPos],		p->sRate1);
		strcpy(pTarget->asRetention[iCurPos],		p->sRetention);
		strcpy(pTarget->asRate2[iCurPos],		p->sRate2);

		pTarget->aiSdr[iCurPos]=			p->iSdr;

		strcpy(pTarget->asState[iCurPos],		p->sState);
		strcpy(pTarget->asFileName[iCurPos],		p->sFileName);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==PSTN_DETAIL_TICKET_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				RECORD_TYPE,\n\
				COMPANY,\n\
				REFERENCE,\n\
				NONE,\n\
				IMSI,\n\
				CALLING_NBR,\n\
				MODIFY_INS,\n\
				NUMBER_TYPE,\n\
				PICK_PROGRAM,\n\
				CALLED_NBR,\n\
				SERVICE_TYPE,\n\
				SERVICE_NBR,\n\
				DUAL_TYPE,\n\
				DUAL_NBR,\n\
				REQ_CHANNEL,\n\
				USE_CHANNEL,\n\
				SERVICE_TRAN,\n\
				ACTIVITY_CODE1,\n\
				ADD_ACTIVITY_CODE1,\n\
				ACTIVITY_CODE2,\n\
				ADD_ACTIVITY_CODE2,\n\
				ACTIVITY_CODE3,\n\
				ADD_ACTIVITY_CODE3,\n\
				ACTIVITY_CODE4,\n\
				ADD_ACTIVITY_CODE4,\n\
				ACTIVITY_CODE5,\n\
				ADD_ACTIVITY_CODE5,\n\
				MSC,\n\
				LAC,\n\
				CELLULAR_SIGNS,\n\
				MOBILE_CODE,\n\
				CALL_TIME,\n\
				PAY_UNITS,\n\
				AMOUNT_DATA,\n\
				TOLL_FEE,\n\
				TOLL_PROJECTS,\n\
				TAX_RATE,\n\
				RATE_1,\n\
				RETENTION,\n\
				RATE_2,\n\
				SDR,\n\
				STATE,\n\
				FILE_NAME)\n\
			VALUES (\n\
				:asRecordType,\n\
				:asCompany,\n\
				:asReference,\n\
				:asNone,\n\
				:asImsi,\n\
				:asCallingNbr,\n\
				:asModifyIns,\n\
				:asNumberType,\n\
				:asPickProgram,\n\
				:asCalledNbr,\n\
				:asServiceType,\n\
				:asServiceNbr,\n\
				:asDualType,\n\
				:asDualNbr,\n\
				:asReqChannel,\n\
				:asUseChannel,\n\
				:asServiceTran,\n\
				:asActivityCode1,\n\
				:asAddActivityCode1,\n\
				:asActivityCode2,\n\
				:asAddActivityCode2,\n\
				:asActivityCode3,\n\
				:asAddActivityCode3,\n\
				:asActivityCode4,\n\
				:asAddActivityCode4,\n\
				:asActivityCode5,\n\
				:asAddActivityCode5,\n\
				:asMsc,\n\
				:asLac,\n\
				:asCellularSigns,\n\
				:asMobileCode,\n\
				:asCallTime,\n\
				:asPayUnits,\n\
				:asAmountData,\n\
				:aiTollFee,\n\
				:asTollProjects,\n\
				:asTaxRate,\n\
				:asRate1,\n\
				:asRetention,\n\
				:asRate2,\n\
				:aiSdr,\n\
				:asState,\n\
				:asFileName\n\
			)",sTableName);

		/* EXEC SQL PREPARE PSTN_DETAIL_TICKETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )458;
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


		if(CheckSqlResult("Prepare insert statement PSTN_DETAIL_TICKET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE PSTN_DETAIL_TICKETTRG USING
				:pTarget->asRecordType,
				:pTarget->asCompany,
				:pTarget->asReference,
				:pTarget->asNone,
				:pTarget->asImsi,
				:pTarget->asCallingNbr,
				:pTarget->asModifyIns,
				:pTarget->asNumberType,
				:pTarget->asPickProgram,
				:pTarget->asCalledNbr,
				:pTarget->asServiceType,
				:pTarget->asServiceNbr,
				:pTarget->asDualType,
				:pTarget->asDualNbr,
				:pTarget->asReqChannel,
				:pTarget->asUseChannel,
				:pTarget->asServiceTran,
				:pTarget->asActivityCode1,
				:pTarget->asAddActivityCode1,
				:pTarget->asActivityCode2,
				:pTarget->asAddActivityCode2,
				:pTarget->asActivityCode3,
				:pTarget->asAddActivityCode3,
				:pTarget->asActivityCode4,
				:pTarget->asAddActivityCode4,
				:pTarget->asActivityCode5,
				:pTarget->asAddActivityCode5,
				:pTarget->asMsc,
				:pTarget->asLac,
				:pTarget->asCellularSigns,
				:pTarget->asMobileCode,
				:pTarget->asCallTime,
				:pTarget->asPayUnits,
				:pTarget->asAmountData,
				:pTarget->aiTollFee,
				:pTarget->asTollProjects,
				:pTarget->asTaxRate,
				:pTarget->asRate1,
				:pTarget->asRetention,
				:pTarget->asRate2,
				:pTarget->aiSdr,
				:pTarget->asState,
				:pTarget->asFileName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )477;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asRecordType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asCompany);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asReference);
  sqlstm.sqhstl[2] = (unsigned long )7;
  sqlstm.sqhsts[2] = (         int  )7;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asNone);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asImsi);
  sqlstm.sqhstl[4] = (unsigned long )16;
  sqlstm.sqhsts[4] = (         int  )16;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asCallingNbr);
  sqlstm.sqhstl[5] = (unsigned long )26;
  sqlstm.sqhsts[5] = (         int  )26;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asModifyIns);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asNumberType);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asPickProgram);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asCalledNbr);
  sqlstm.sqhstl[9] = (unsigned long )26;
  sqlstm.sqhsts[9] = (         int  )26;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asServiceType);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asServiceNbr);
  sqlstm.sqhstl[11] = (unsigned long )9;
  sqlstm.sqhsts[11] = (         int  )9;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asDualType);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asDualNbr);
  sqlstm.sqhstl[13] = (unsigned long )3;
  sqlstm.sqhsts[13] = (         int  )3;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asReqChannel);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asUseChannel);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asServiceTran);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asActivityCode1);
  sqlstm.sqhstl[17] = (unsigned long )2;
  sqlstm.sqhsts[17] = (         int  )2;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asAddActivityCode1);
  sqlstm.sqhstl[18] = (unsigned long )3;
  sqlstm.sqhsts[18] = (         int  )3;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asActivityCode2);
  sqlstm.sqhstl[19] = (unsigned long )2;
  sqlstm.sqhsts[19] = (         int  )2;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asAddActivityCode2);
  sqlstm.sqhstl[20] = (unsigned long )3;
  sqlstm.sqhsts[20] = (         int  )3;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asActivityCode3);
  sqlstm.sqhstl[21] = (unsigned long )2;
  sqlstm.sqhsts[21] = (         int  )2;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asAddActivityCode3);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asActivityCode4);
  sqlstm.sqhstl[23] = (unsigned long )2;
  sqlstm.sqhsts[23] = (         int  )2;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asAddActivityCode4);
  sqlstm.sqhstl[24] = (unsigned long )3;
  sqlstm.sqhsts[24] = (         int  )3;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pTarget->asActivityCode5);
  sqlstm.sqhstl[25] = (unsigned long )2;
  sqlstm.sqhsts[25] = (         int  )2;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pTarget->asAddActivityCode5);
  sqlstm.sqhstl[26] = (unsigned long )3;
  sqlstm.sqhsts[26] = (         int  )3;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[27] = (unsigned long )16;
  sqlstm.sqhsts[27] = (         int  )16;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pTarget->asLac);
  sqlstm.sqhstl[28] = (unsigned long )6;
  sqlstm.sqhsts[28] = (         int  )6;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pTarget->asCellularSigns);
  sqlstm.sqhstl[29] = (unsigned long )6;
  sqlstm.sqhsts[29] = (         int  )6;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pTarget->asMobileCode);
  sqlstm.sqhstl[30] = (unsigned long )2;
  sqlstm.sqhsts[30] = (         int  )2;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pTarget->asCallTime);
  sqlstm.sqhstl[31] = (unsigned long )15;
  sqlstm.sqhsts[31] = (         int  )15;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pTarget->asPayUnits);
  sqlstm.sqhstl[32] = (unsigned long )7;
  sqlstm.sqhsts[32] = (         int  )7;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pTarget->asAmountData);
  sqlstm.sqhstl[33] = (unsigned long )7;
  sqlstm.sqhsts[33] = (         int  )7;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pTarget->aiTollFee);
  sqlstm.sqhstl[34] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[34] = (         int  )sizeof(int);
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pTarget->asTollProjects);
  sqlstm.sqhstl[35] = (unsigned long )2;
  sqlstm.sqhsts[35] = (         int  )2;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pTarget->asTaxRate);
  sqlstm.sqhstl[36] = (unsigned long )11;
  sqlstm.sqhsts[36] = (         int  )11;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pTarget->asRate1);
  sqlstm.sqhstl[37] = (unsigned long )11;
  sqlstm.sqhsts[37] = (         int  )11;
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pTarget->asRetention);
  sqlstm.sqhstl[38] = (unsigned long )18;
  sqlstm.sqhsts[38] = (         int  )18;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pTarget->asRate2);
  sqlstm.sqhstl[39] = (unsigned long )11;
  sqlstm.sqhsts[39] = (         int  )11;
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pTarget->aiSdr);
  sqlstm.sqhstl[40] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[40] = (         int  )sizeof(int);
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pTarget->asState);
  sqlstm.sqhstl[41] = (unsigned long )3;
  sqlstm.sqhsts[41] = (         int  )3;
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[42] = (unsigned long )33;
  sqlstm.sqhsts[42] = (         int  )33;
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqharc[42] = (unsigned long  *)0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into PSTN_DETAIL_TICKET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}
/*更新STATE，1表示已统计*/
int EUpdateStructToPstnDetailTicket(struct PstnDetailTicketStruct *p,
	int iInsertFlag,struct PstnDetailTicketStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/

		strcpy(pTarget->asState[iCurPos],	p->sState);
		strcpy(pTarget->asRowID[iCurPos],	p->sRowID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==PSTN_DETAIL_TICKET_BUFLEN_OUT){

/* UPDATE */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s SET \n\
				STATE=:asState\n\
			WHERE ROWID = chartorowid(:asRowID)",sTableName);

		/* EXEC SQL PREPARE PSTN_DETAIL_TICKETTRGUP FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )664;
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


		if(CheckSqlResult("Prepare Update statement PSTN_DETAIL_TICKET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE PSTN_DETAIL_TICKETTRGUP USING
				:pTarget->asState,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )683;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asState);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )19;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
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


		if(CheckSqlResult("Dyn insert into PSTN_DETAIL_TICKET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*批量数据动态从DETAIL_STAT_REPORT中用结构缓冲方式取数据*/
int EGetDetailStatReportToStruct(struct DetailStatReportStruct *p,
	struct DetailStatReportStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(RECORD_TYPE,' '),\n\
				nvl(COMPANY,' '),\n\
				nvl(IMSI,' '),\n\
				nvl(CALLING_NBR,' '),\n\
				nvl(NUMBER_TYPE,' '),\n\
				nvl(CALLED_NBR,' '),\n\
				nvl(SERVICE_TYPE,' '),\n\
				nvl(SERVICE_NBR,' '),\n\
				nvl(DUAL_TYPE,' '),\n\
				nvl(DUAL_NBR,' '),\n\
				nvl(MSC,' '),\n\
				nvl(LAC,' '),\n\
				nvl(MOBILE_CODE,' '),\n\
				nvl(CALL_TIME,' '),\n\
				nvl(PAY_UNITS,' '),\n\
				nvl(AMOUNT_DATA,' '),\n\
				nvl(TOLL_PROJECTS,' '),\n\
				nvl(RATE_1,' '),\n\
				nvl(RATE_2,' '),\n\
				to_char(nvl(CNT,0)),\n\
				to_char(nvl(TOLL_FEE,0)),\n\
				to_char(nvl(SDR,0))\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE DETAIL_STAT_REPORTSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )706;
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


		CheckSqlError(" PREPARE DETAIL_STAT_REPORTSCR DETAIL_STAT_REPORTCR");

		/* EXEC SQL DECLARE DETAIL_STAT_REPORTCR CURSOR FOR DETAIL_STAT_REPORTSCR; */ 

		CheckSqlError("Declare DETAIL_STAT_REPORTCR");

		/* EXEC SQL OPEN DETAIL_STAT_REPORTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )725;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open DETAIL_STAT_REPORTCR;");


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

		/* EXEC SQL CLOSE DETAIL_STAT_REPORTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )740;
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
		/* EXEC SQL FETCH DETAIL_STAT_REPORTCR INTO
			:pSource->asRecordType,
			:pSource->asCompany,
			:pSource->asImsi,
			:pSource->asCallingNbr,
			:pSource->asNumberType,
			:pSource->asCalledNbr,
			:pSource->asServiceType,
			:pSource->asServiceNbr,
			:pSource->asDualType,
			:pSource->asDualNbr,
			:pSource->asMsc,
			:pSource->asLac,
			:pSource->asMobileCode,
			:pSource->asCallTime,
			:pSource->asPayUnits,
			:pSource->asAmountData,
			:pSource->asTollProjects,
			:pSource->asRate1,
			:pSource->asRate2,
			:pSource->asCnt,
			:pSource->asTollFee,
			:pSource->asSdr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )755;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asRecordType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCompany);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asImsi);
  sqlstm.sqhstl[2] = (unsigned long )16;
  sqlstm.sqhsts[2] = (         int  )16;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallingNbr);
  sqlstm.sqhstl[3] = (unsigned long )26;
  sqlstm.sqhsts[3] = (         int  )26;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asNumberType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCalledNbr);
  sqlstm.sqhstl[5] = (unsigned long )26;
  sqlstm.sqhsts[5] = (         int  )26;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asServiceType);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asServiceNbr);
  sqlstm.sqhstl[7] = (unsigned long )9;
  sqlstm.sqhsts[7] = (         int  )9;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asDualType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asDualNbr);
  sqlstm.sqhstl[9] = (unsigned long )3;
  sqlstm.sqhsts[9] = (         int  )3;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[10] = (unsigned long )16;
  sqlstm.sqhsts[10] = (         int  )16;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asLac);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )6;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asMobileCode);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asCallTime);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )15;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asPayUnits);
  sqlstm.sqhstl[14] = (unsigned long )7;
  sqlstm.sqhsts[14] = (         int  )7;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asAmountData);
  sqlstm.sqhstl[15] = (unsigned long )7;
  sqlstm.sqhsts[15] = (         int  )7;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asTollProjects);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asRate1);
  sqlstm.sqhstl[17] = (unsigned long )11;
  sqlstm.sqhsts[17] = (         int  )11;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asRate2);
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )11;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asCnt);
  sqlstm.sqhstl[19] = (unsigned long )13;
  sqlstm.sqhsts[19] = (         int  )13;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asTollFee);
  sqlstm.sqhstl[20] = (unsigned long )13;
  sqlstm.sqhsts[20] = (         int  )13;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asSdr);
  sqlstm.sqhstl[21] = (unsigned long )13;
  sqlstm.sqhsts[21] = (         int  )13;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
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


		CheckSqlError("Fetch DETAIL_STAT_REPORTCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE DETAIL_STAT_REPORTCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 44;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )858;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=DETAIL_STAT_REPORT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sRecordType,		pSource->asRecordType[iCurPos]);
		strcpy(p->sCompany,		pSource->asCompany[iCurPos]);
		strcpy(p->sImsi,		pSource->asImsi[iCurPos]);
		strcpy(p->sCallingNbr,		pSource->asCallingNbr[iCurPos]);
		strcpy(p->sNumberType,		pSource->asNumberType[iCurPos]);
		strcpy(p->sCalledNbr,		pSource->asCalledNbr[iCurPos]);
		strcpy(p->sServiceType,		pSource->asServiceType[iCurPos]);
		strcpy(p->sServiceNbr,		pSource->asServiceNbr[iCurPos]);
		strcpy(p->sDualType,		pSource->asDualType[iCurPos]);
		strcpy(p->sDualNbr,		pSource->asDualNbr[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sLac,			pSource->asLac[iCurPos]);
		strcpy(p->sMobileCode,		pSource->asMobileCode[iCurPos]);
		strcpy(p->sCallTime,		pSource->asCallTime[iCurPos]);
		strcpy(p->sPayUnits,		pSource->asPayUnits[iCurPos]);
		strcpy(p->sAmountData,		pSource->asAmountData[iCurPos]);
		strcpy(p->sTollProjects,	pSource->asTollProjects[iCurPos]);
		strcpy(p->sRate1,		pSource->asRate1[iCurPos]);
		strcpy(p->sRate2,		pSource->asRate2[iCurPos]);
		strcpy(p->sCnt,			pSource->asCnt[iCurPos]);
		strcpy(p->sTollFee,		pSource->asTollFee[iCurPos]);
		strcpy(p->sSdr,			pSource->asSdr[iCurPos]);

		AllTrim(p->sRecordType);
		AllTrim(p->sCompany);
		AllTrim(p->sImsi);
		AllTrim(p->sCallingNbr);
		AllTrim(p->sNumberType);
		AllTrim(p->sCalledNbr);
		AllTrim(p->sServiceType);
		AllTrim(p->sServiceNbr);
		AllTrim(p->sDualType);
		AllTrim(p->sDualNbr);
		AllTrim(p->sMsc);
		AllTrim(p->sLac);
		AllTrim(p->sMobileCode);
		AllTrim(p->sCallTime);
		AllTrim(p->sPayUnits);
		AllTrim(p->sAmountData);
		AllTrim(p->sTollProjects);
		AllTrim(p->sRate1);
		AllTrim(p->sRate2);
		AllTrim(p->sCnt);
		AllTrim(p->sTollFee);
		AllTrim(p->sSdr);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入DETAIL_STAT_REPORT*/
int EInsertStructToDetailStatReport(struct DetailStatReportStruct *p,
	int iInsertFlag,struct DetailStatReportStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asRecordType[iCurPos],		p->sRecordType);
		strcpy(pTarget->asCompany[iCurPos],		p->sCompany);
		strcpy(pTarget->asImsi[iCurPos],		p->sImsi);
		strcpy(pTarget->asCallingNbr[iCurPos],		p->sCallingNbr);
		strcpy(pTarget->asNumberType[iCurPos],		p->sNumberType);
		strcpy(pTarget->asCalledNbr[iCurPos],		p->sCalledNbr);
		strcpy(pTarget->asServiceType[iCurPos],		p->sServiceType);
		strcpy(pTarget->asServiceNbr[iCurPos],		p->sServiceNbr);
		strcpy(pTarget->asDualType[iCurPos],		p->sDualType);
		strcpy(pTarget->asDualNbr[iCurPos],		p->sDualNbr);
		strcpy(pTarget->asMsc[iCurPos],			p->sMsc);
		strcpy(pTarget->asLac[iCurPos],			p->sLac);
		strcpy(pTarget->asMobileCode[iCurPos],		p->sMobileCode);
		strcpy(pTarget->asCallTime[iCurPos],		p->sCallTime);
		strcpy(pTarget->asPayUnits[iCurPos],		p->sPayUnits);
		strcpy(pTarget->asAmountData[iCurPos],		p->sAmountData);
		strcpy(pTarget->asTollProjects[iCurPos],	p->sTollProjects);
		strcpy(pTarget->asRate1[iCurPos],		p->sRate1);
		strcpy(pTarget->asRate2[iCurPos],		p->sRate2);
		strcpy(pTarget->asCnt[iCurPos],			p->sCnt);
		strcpy(pTarget->asTollFee[iCurPos],		p->sTollFee);
		strcpy(pTarget->asSdr[iCurPos],			p->sSdr);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==DETAIL_STAT_REPORT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				RECORD_TYPE,\n\
				COMPANY,\n\
				IMSI,\n\
				CALLING_NBR,\n\
				NUMBER_TYPE,\n\
				CALLED_NBR,\n\
				SERVICE_TYPE,\n\
				SERVICE_NBR,\n\
				DUAL_TYPE,\n\
				DUAL_NBR,\n\
				MSC,\n\
				LAC,\n\
				MOBILE_CODE,\n\
				CALL_TIME,\n\
				PAY_UNITS,\n\
				AMOUNT_DATA,\n\
				TOLL_PROJECTS,\n\
				RATE_1,\n\
				RATE_2,\n\
				CNT,\n\
				TOLL_FEE,\n\
				SDR)\n\
			VALUES (\n\
				:asRecordType,\n\
				:asCompany,\n\
				:asImsi,\n\
				:asCallingNbr,\n\
				:asNumberType,\n\
				:asCalledNbr,\n\
				:asServiceType,\n\
				:asServiceNbr,\n\
				:asDualType,\n\
				:asDualNbr,\n\
				:asMsc,\n\
				:asLac,\n\
				:asMobileCode,\n\
				:asCallTime,\n\
				:asPayUnits,\n\
				:asAmountData,\n\
				:asTollProjects,\n\
				:asRate1,\n\
				:asRate2,\n\
				to_number(:asCnt),\n\
				to_number(:asTollFee),\n\
				to_number(:asSdr)\n\
			)",sTableName);

		/* EXEC SQL PREPARE DETAIL_STAT_REPORTTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )873;
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


		if(CheckSqlResult("Prepare insert statement DETAIL_STAT_REPORT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE DETAIL_STAT_REPORTTRG USING
				:pTarget->asRecordType,
				:pTarget->asCompany,
				:pTarget->asImsi,
				:pTarget->asCallingNbr,
				:pTarget->asNumberType,
				:pTarget->asCalledNbr,
				:pTarget->asServiceType,
				:pTarget->asServiceNbr,
				:pTarget->asDualType,
				:pTarget->asDualNbr,
				:pTarget->asMsc,
				:pTarget->asLac,
				:pTarget->asMobileCode,
				:pTarget->asCallTime,
				:pTarget->asPayUnits,
				:pTarget->asAmountData,
				:pTarget->asTollProjects,
				:pTarget->asRate1,
				:pTarget->asRate2,
				:pTarget->asCnt,
				:pTarget->asTollFee,
				:pTarget->asSdr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )892;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asRecordType);
  sqlstm.sqhstl[0] = (unsigned long )3;
  sqlstm.sqhsts[0] = (         int  )3;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asCompany);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asImsi);
  sqlstm.sqhstl[2] = (unsigned long )16;
  sqlstm.sqhsts[2] = (         int  )16;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallingNbr);
  sqlstm.sqhstl[3] = (unsigned long )26;
  sqlstm.sqhsts[3] = (         int  )26;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asNumberType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asCalledNbr);
  sqlstm.sqhstl[5] = (unsigned long )26;
  sqlstm.sqhsts[5] = (         int  )26;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asServiceType);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asServiceNbr);
  sqlstm.sqhstl[7] = (unsigned long )9;
  sqlstm.sqhsts[7] = (         int  )9;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asDualType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asDualNbr);
  sqlstm.sqhstl[9] = (unsigned long )3;
  sqlstm.sqhsts[9] = (         int  )3;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[10] = (unsigned long )16;
  sqlstm.sqhsts[10] = (         int  )16;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asLac);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )6;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asMobileCode);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asCallTime);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )15;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asPayUnits);
  sqlstm.sqhstl[14] = (unsigned long )7;
  sqlstm.sqhsts[14] = (         int  )7;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asAmountData);
  sqlstm.sqhstl[15] = (unsigned long )7;
  sqlstm.sqhsts[15] = (         int  )7;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asTollProjects);
  sqlstm.sqhstl[16] = (unsigned long )2;
  sqlstm.sqhsts[16] = (         int  )2;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asRate1);
  sqlstm.sqhstl[17] = (unsigned long )11;
  sqlstm.sqhsts[17] = (         int  )11;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asRate2);
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )11;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asCnt);
  sqlstm.sqhstl[19] = (unsigned long )13;
  sqlstm.sqhsts[19] = (         int  )13;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asTollFee);
  sqlstm.sqhstl[20] = (unsigned long )13;
  sqlstm.sqhsts[20] = (         int  )13;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asSdr);
  sqlstm.sqhstl[21] = (unsigned long )13;
  sqlstm.sqhsts[21] = (         int  )13;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into DETAIL_STAT_REPORT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*单条数据从用动态SQL从HIGH_TICKET_LOG取数据*/
int SDGetHighTicketLogToStruct(struct HighTicketLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(HIGH_TICKET_SEQ,0),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(FILE_DATE,' '),\n\
				to_char(nvl(DEAL_TIME,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE HIGH_TICKET_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )995;
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


		CheckSqlError(" PREPARE HIGH_TICKET_LOGSCR HIGH_TICKET_LOGCR");

		/* EXEC SQL DECLARE HIGH_TICKET_LOGCR CURSOR FOR HIGH_TICKET_LOGSCR; */ 

		CheckSqlError("Declare HIGH_TICKET_LOGCR");

		/* EXEC SQL OPEN HIGH_TICKET_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1014;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open HIGH_TICKET_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH HIGH_TICKET_LOGCR INTO
			:p->iHighTicketSeq,
			:p->sFileName,
			:p->sFileDate,
			:p->sDealTime,
			:p->sState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1029;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iHighTicketSeq);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[1] = (unsigned long )33;
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


		CheckSqlError("Fetch HIGH_TICKET_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE HIGH_TICKET_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1064;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE HIGH_TICKET_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1079;
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

int GetHighTicketSeq()
{
	int iHighTicketSeq=0;
	
	/* EXEC SQL SELECT HIGH_TICKET_SEQ.nextval INTO :iHighTicketSeq FROM DUAL ; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select HIGH_TICKET_SEQ.nextval  into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1094;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iHighTicketSeq;
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


	CheckSqlError("Get iHighTicketSeq ERROR");
	
	return iHighTicketSeq;
	
}
/*单条数据动态SQL向HIGH_TICKET_LOG写数据*/
int SDInsertStructToHighTicketLog(struct HighTicketLogStruct *p,char sTableName[])
{

/*获取seq值*/
		p->iHighTicketSeq=GetHighTicketSeq();

/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				HIGH_TICKET_SEQ,\n\
				FILE_NAME,\n\
				FILE_DATE,\n\
				DEAL_TIME,\n\
				STATE)\n\
			VALUES (\n\
				:iHighTicketSeq,\n\
				:sFileName,\n\
				:sFileDate,\n\
				to_date(:sDealTime,'yyyymmddhh24miss'),\n\
				:sState\n\
			)",sTableName);

		/* EXEC SQL PREPARE HIGH_TICKET_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1113;
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


		if(CheckSqlResult("Prepare insert statement HIGH_TICKET_LOG")<0) return -1;

		/* EXEC SQL EXECUTE HIGH_TICKET_LOGTRG USING
				:p->iHighTicketSeq,
				:p->sFileName,
				:p->sFileDate,
				:p->sDealTime,
				:p->sState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1132;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iHighTicketSeq);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[1] = (unsigned long )33;
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


		if(CheckSqlResult("Dyn insert into HIGH_TICKET_LOG")<0) return -1;

	return 0;
}





