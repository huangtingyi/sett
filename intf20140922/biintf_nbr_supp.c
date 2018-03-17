
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
    "biintf_nbr_supp.pc"
};


static unsigned int sqlctx = 18431483;


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
   unsigned char  *sqhstv[22];
   unsigned long  sqhstl[22];
            int   sqhsts[22];
            short *sqindv[22];
            int   sqinds[22];
   unsigned long  sqharm[22];
   unsigned long  *sqharc[22];
   unsigned short  sqadto[22];
   unsigned short  sqtdso[22];
} sqlstm = {12,22};

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
5,0,0,1,0,0,17,54,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,60,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,77,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,85,0,0,22,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
157,0,0,1,0,0,15,120,0,0,0,0,0,1,0,
172,0,0,2,0,0,17,281,0,0,1,1,0,1,0,1,97,0,0,
191,0,0,2,0,0,21,284,0,0,22,22,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <bintree.h>
#include <list.h>
#include <wwfile.h>
#include <stt_ticket.h>
#include "param_intf.h"
#include "biintf_nbr_supp.h"


/*批量数据动态从SETT_NBR_INTF_FJBI中用结构缓冲方式取数据*/
int EGetSettNbrIntfFjbiToStruct(struct SettNbrIntfFjbiStruct *p,
	struct SettNbrIntfFjbiStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(BILLING_CYCLE_ID,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(ACC_NBR,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(ROAM_AREA_CODE,' '),\n\
				nvl(HOME_CARR_ID,0),\n\
				nvl(OPP_CARR_ID,0),\n\
				nvl(CALL_DIRECTION,0),\n\
				nvl(TICKET_TYPE_ID,0),\n\
				nvl(CNT,0),\n\
				nvl(DURATION,0),\n\
				nvl(FEE_DURATION,0),\n\
				nvl(IN_FEE,0),\n\
				nvl(OUT_FEE,0),\n\
				nvl(SERVICE_TYPE,' '),\n\
				nvl(NBR_TYPE,' '),\n\
				nvl(OPP_NBR_TYPE,' '),\n\
				nvl(SETT_FLAG,0),\n\
				nvl(RESERVE1,' '),\n\
				nvl(RESERVE2,' '),\n\
				to_char(nvl(DEAL_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_NBR_INTF_FJBISCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE SETT_NBR_INTF_FJBISCR SETT_NBR_INTF_FJBICR");

		/* EXEC SQL DECLARE SETT_NBR_INTF_FJBICR CURSOR FOR SETT_NBR_INTF_FJBISCR; */ 

		CheckSqlError("Declare SETT_NBR_INTF_FJBICR");

		/* EXEC SQL OPEN SETT_NBR_INTF_FJBICR; */ 

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


		CheckSqlError("Open SETT_NBR_INTF_FJBICR;");


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

		/* EXEC SQL CLOSE SETT_NBR_INTF_FJBICR; */ 

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
		/* EXEC SQL FETCH SETT_NBR_INTF_FJBICR INTO
			:pSource->asBillingCycleID,
			:pSource->asVisitAreaCode,
			:pSource->asAccNbr,
			:pSource->asHomeAreaCode,
			:pSource->asOppAreaCode,
			:pSource->asRoamAreaCode,
			:pSource->aiHomeCarrID,
			:pSource->aiOppCarrID,
			:pSource->aiCallDirection,
			:pSource->aiTicketTypeID,
			:pSource->aiCnt,
			:pSource->aiDuration,
			:pSource->aiFeeDuration,
			:pSource->aiInFee,
			:pSource->aiOutFee,
			:pSource->asServiceType,
			:pSource->asNbrType,
			:pSource->asOppNbrType,
			:pSource->aiSettFlag,
			:pSource->asReserve1,
			:pSource->asReserve2,
			:pSource->asDealDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 22;
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
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asAccNbr);
  sqlstm.sqhstl[2] = (unsigned long )25;
  sqlstm.sqhsts[2] = (         int  )25;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asRoamAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )6;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiHomeCarrID);
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
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiCallDirection);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiTicketTypeID);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiFeeDuration);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->aiInFee);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiOutFee);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asServiceType);
  sqlstm.sqhstl[15] = (unsigned long )4;
  sqlstm.sqhsts[15] = (         int  )4;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asNbrType);
  sqlstm.sqhstl[16] = (unsigned long )5;
  sqlstm.sqhsts[16] = (         int  )5;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asOppNbrType);
  sqlstm.sqhstl[17] = (unsigned long )5;
  sqlstm.sqhsts[17] = (         int  )5;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->aiSettFlag);
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )sizeof(int);
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asReserve1);
  sqlstm.sqhstl[19] = (unsigned long )11;
  sqlstm.sqhsts[19] = (         int  )11;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asReserve2);
  sqlstm.sqhstl[20] = (unsigned long )11;
  sqlstm.sqhsts[20] = (         int  )11;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asDealDate);
  sqlstm.sqhstl[21] = (unsigned long )15;
  sqlstm.sqhsts[21] = (         int  )15;
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


		CheckSqlError("Fetch SETT_NBR_INTF_FJBICR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_NBR_INTF_FJBICR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 22;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )157;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_NBR_INTF_FJBI_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sAccNbr,		pSource->asAccNbr[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sRoamAreaCode,	pSource->asRoamAreaCode[iCurPos]);

		p->iHomeCarrID=			pSource->aiHomeCarrID[iCurPos];
		p->iOppCarrID=			pSource->aiOppCarrID[iCurPos];
		p->iCallDirection=		pSource->aiCallDirection[iCurPos];
		p->iTicketTypeID=		pSource->aiTicketTypeID[iCurPos];
		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iDuration=			pSource->aiDuration[iCurPos];
		p->iFeeDuration=		pSource->aiFeeDuration[iCurPos];
		p->iInFee=			pSource->aiInFee[iCurPos];
		p->iOutFee=			pSource->aiOutFee[iCurPos];

		strcpy(p->sServiceType,		pSource->asServiceType[iCurPos]);
		strcpy(p->sNbrType,		pSource->asNbrType[iCurPos]);
		strcpy(p->sOppNbrType,		pSource->asOppNbrType[iCurPos]);

		p->iSettFlag=			pSource->aiSettFlag[iCurPos];

		strcpy(p->sReserve1,		pSource->asReserve1[iCurPos]);
		strcpy(p->sReserve2,		pSource->asReserve2[iCurPos]);
		strcpy(p->sDealDate,		pSource->asDealDate[iCurPos]);

		AllTrim(p->sBillingCycleID);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sAccNbr);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sRoamAreaCode);
		AllTrim(p->sServiceType);
		AllTrim(p->sNbrType);
		AllTrim(p->sOppNbrType);
		AllTrim(p->sReserve1);
		AllTrim(p->sReserve2);
		AllTrim(p->sDealDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}


/*批量数据结构缓冲写入SETT_NBR_INTF_FJBI*/
int EInsertStructToSettNbrIntfFjbi(struct SettNbrIntfFjbiStruct *p,
	int iInsertFlag,struct SettNbrIntfFjbiStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asAccNbr[iCurPos],		p->sAccNbr);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);
		strcpy(pTarget->asRoamAreaCode[iCurPos],	p->sRoamAreaCode);

		pTarget->aiHomeCarrID[iCurPos]=			p->iHomeCarrID;
		pTarget->aiOppCarrID[iCurPos]=			p->iOppCarrID;
		pTarget->aiCallDirection[iCurPos]=		p->iCallDirection;
		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;
		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiDuration[iCurPos]=			p->iDuration;
		pTarget->aiFeeDuration[iCurPos]=		p->iFeeDuration;
		pTarget->aiInFee[iCurPos]=			p->iInFee;
		pTarget->aiOutFee[iCurPos]=			p->iOutFee;

		strcpy(pTarget->asServiceType[iCurPos],		p->sServiceType);
		strcpy(pTarget->asNbrType[iCurPos],		p->sNbrType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);

		pTarget->aiSettFlag[iCurPos]=			p->iSettFlag;

		strcpy(pTarget->asReserve1[iCurPos],		p->sReserve1);
		strcpy(pTarget->asReserve2[iCurPos],		p->sReserve2);
		strcpy(pTarget->asDealDate[iCurPos],		p->sDealDate);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_NBR_INTF_FJBI_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				BILLING_CYCLE_ID,\n\
				VISIT_AREA_CODE,\n\
				ACC_NBR,\n\
				HOME_AREA_CODE,\n\
				OPP_AREA_CODE,\n\
				ROAM_AREA_CODE,\n\
				HOME_CARR_ID,\n\
				OPP_CARR_ID,\n\
				CALL_DIRECTION,\n\
				TICKET_TYPE_ID,\n\
				CNT,\n\
				DURATION,\n\
				FEE_DURATION,\n\
				IN_FEE,\n\
				OUT_FEE,\n\
				SERVICE_TYPE,\n\
				NBR_TYPE,\n\
				OPP_NBR_TYPE,\n\
				SETT_FLAG,\n\
				RESERVE1,\n\
				RESERVE2,\n\
				DEAL_DATE)\n\
			VALUES (\n\
				:asBillingCycleID,\n\
				:asVisitAreaCode,\n\
				:asAccNbr,\n\
				:asHomeAreaCode,\n\
				:asOppAreaCode,\n\
				:asRoamAreaCode,\n\
				:aiHomeCarrID,\n\
				:aiOppCarrID,\n\
				:aiCallDirection,\n\
				:aiTicketTypeID,\n\
				:aiCnt,\n\
				:aiDuration,\n\
				:aiFeeDuration,\n\
				:aiInFee,\n\
				:aiOutFee,\n\
				:asServiceType,\n\
				:asNbrType,\n\
				:asOppNbrType,\n\
				:aiSettFlag,\n\
				:asReserve1,\n\
				:asReserve2,\n\
				to_date(:asDealDate,'yyyymmddhh24miss')\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_NBR_INTF_FJBITRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 22;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )172;
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


		if(CheckSqlResult("Prepare insert statement SETT_NBR_INTF_FJBI")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_NBR_INTF_FJBITRG USING
				:pTarget->asBillingCycleID,
				:pTarget->asVisitAreaCode,
				:pTarget->asAccNbr,
				:pTarget->asHomeAreaCode,
				:pTarget->asOppAreaCode,
				:pTarget->asRoamAreaCode,
				:pTarget->aiHomeCarrID,
				:pTarget->aiOppCarrID,
				:pTarget->aiCallDirection,
				:pTarget->aiTicketTypeID,
				:pTarget->aiCnt,
				:pTarget->aiDuration,
				:pTarget->aiFeeDuration,
				:pTarget->aiInFee,
				:pTarget->aiOutFee,
				:pTarget->asServiceType,
				:pTarget->asNbrType,
				:pTarget->asOppNbrType,
				:pTarget->aiSettFlag,
				:pTarget->asReserve1,
				:pTarget->asReserve2,
				:pTarget->asDealDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 22;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )191;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asAccNbr);
  sqlstm.sqhstl[2] = (unsigned long )25;
  sqlstm.sqhsts[2] = (         int  )25;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asRoamAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )6;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiHomeCarrID);
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
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->aiCallDirection);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->aiTicketTypeID);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->aiFeeDuration);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->aiInFee);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiOutFee);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asServiceType);
  sqlstm.sqhstl[15] = (unsigned long )4;
  sqlstm.sqhsts[15] = (         int  )4;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asNbrType);
  sqlstm.sqhstl[16] = (unsigned long )5;
  sqlstm.sqhsts[16] = (         int  )5;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asOppNbrType);
  sqlstm.sqhstl[17] = (unsigned long )5;
  sqlstm.sqhsts[17] = (         int  )5;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->aiSettFlag);
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )sizeof(int);
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asReserve1);
  sqlstm.sqhstl[19] = (unsigned long )11;
  sqlstm.sqhsts[19] = (         int  )11;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asReserve2);
  sqlstm.sqhstl[20] = (unsigned long )11;
  sqlstm.sqhsts[20] = (         int  )11;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asDealDate);
  sqlstm.sqhstl[21] = (unsigned long )15;
  sqlstm.sqhsts[21] = (         int  )15;
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


		if(CheckSqlResult("Dyn insert into SETT_NBR_INTF_FJBI")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

void mvitem_settnbrintffjbi(struct SettNbrIntfFjbiStruct *pi,struct SettNbrIntfFjbiStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct SettNbrIntfFjbiStruct));

		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sAccNbr,		pi->sAccNbr,24);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sOppAreaCode,	pi->sOppAreaCode,5);
		strncpy(po->sRoamAreaCode,	pi->sRoamAreaCode,5);

		po->iHomeCarrID=		pi->iHomeCarrID;
		po->iOppCarrID=			pi->iOppCarrID;
		po->iCallDirection=		pi->iCallDirection;
		po->iTicketTypeID=		pi->iTicketTypeID;
		po->iCnt=			pi->iCnt;
		po->iDuration=			pi->iDuration;
		po->iFeeDuration=		pi->iFeeDuration;
		po->iInFee=			pi->iInFee;
		po->iOutFee=			pi->iOutFee;

		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sNbrType,		pi->sNbrType,4);
		strncpy(po->sOppNbrType,	pi->sOppNbrType,4);

		po->iSettFlag=			pi->iSettFlag;

		strncpy(po->sReserve1,		pi->sReserve1,10);
		strncpy(po->sReserve2,		pi->sReserve2,10);
		strncpy(po->sDealDate,		pi->sDealDate,14);
}
