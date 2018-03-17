
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "sett_nbr_supp.pc"
};


static unsigned int sqlctx = 5234171;


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
   unsigned char  *sqhstv[23];
   unsigned long  sqhstl[23];
            int   sqhsts[23];
            short *sqindv[23];
            int   sqinds[23];
   unsigned long  sqharm[23];
   unsigned long  *sqharc[23];
   unsigned short  sqadto[23];
   unsigned short  sqtdso[23];
} sqlstm = {12,23};

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
5,0,0,1,0,0,17,52,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,58,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,75,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,83,0,0,23,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
161,0,0,1,0,0,15,119,0,0,0,0,0,1,0,
176,0,0,2,0,0,17,289,0,0,1,1,0,1,0,1,97,0,0,
195,0,0,2,0,0,21,292,0,0,23,23,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,
302,0,0,3,70,0,4,464,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <param_intf.h>
#include <datatype.h>
#include <bintree.h>
#include <sett_nbr_supp.h>

/*批量数据动态从SETT_NBR_STAT中用结构缓冲方式取数据*/
int EGetSettNbrStatToStruct(struct SettNbrStatStruct *p,
	struct SettNbrStatStructIn *pSource)
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
				nvl(PROV_CODE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(NET_TYPE,' '),\n\
				nvl(TICKET_TYPE_ID,0),\n\
				nvl(CNT,0),\n\
				nvl(DURATION,0),\n\
				nvl(SETT_MIN,0),\n\
				to_char(nvl(IN_FEE,0)),\n\
				to_char(nvl(OUT_FEE,0)),\n\
				nvl(SERVICE_TYPE,' '),\n\
				nvl(NBR_TYPE,' '),\n\
				nvl(OPP_NBR_TYPE,' '),\n\
				nvl(OPP_CARR_ID,0),\n\
				nvl(OPP_AREA,' '),\n\
				nvl(OPP_PROV,' '),\n\
				nvl(BILLING_TYPE_ID,' '),\n\
				nvl(RESERVE1,' '),\n\
				nvl(RESERVE2,' '),\n\
				nvl(RESERVE3,' '),\n\
				nvl(SETT_ITEM_DATE,' '),\n\
				nvl(BILLING_CYCLE_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_NBR_STATSCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE SETT_NBR_STATSCR SETT_NBR_STATCR");

		/* EXEC SQL DECLARE SETT_NBR_STATCR CURSOR FOR SETT_NBR_STATSCR; */ 

		CheckSqlError("Declare SETT_NBR_STATCR");

		/* EXEC SQL OPEN SETT_NBR_STATCR; */ 

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


		CheckSqlError("Open SETT_NBR_STATCR;");


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

		/* EXEC SQL CLOSE SETT_NBR_STATCR; */ 

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
		/* EXEC SQL FETCH SETT_NBR_STATCR INTO
			:pSource->asAccNbr,
			:pSource->asHomeAreaCode,
			:pSource->asProvCode,
			:pSource->asVisitAreaCode,
			:pSource->asNetType,
			:pSource->aiTicketTypeID,
			:pSource->aiCnt,
			:pSource->aiDuration,
			:pSource->aiSettMin,
			:pSource->asInFee,
			:pSource->asOutFee,
			:pSource->asServiceType,
			:pSource->asNbrType,
			:pSource->asOppNbrType,
			:pSource->aiOppCarrID,
			:pSource->asOppArea,
			:pSource->asOppProv,
			:pSource->asBillingTypeID,
			:pSource->asReserve1,
			:pSource->asReserve2,
			:pSource->asReserve3,
			:pSource->asSettItemDate,
			:pSource->asBillingCycleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 23;
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asProvCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asNetType);
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )5;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiTicketTypeID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiSettMin);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asInFee);
  sqlstm.sqhstl[9] = (unsigned long )13;
  sqlstm.sqhsts[9] = (         int  )13;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asOutFee);
  sqlstm.sqhstl[10] = (unsigned long )13;
  sqlstm.sqhsts[10] = (         int  )13;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asServiceType);
  sqlstm.sqhstl[11] = (unsigned long )4;
  sqlstm.sqhsts[11] = (         int  )4;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asNbrType);
  sqlstm.sqhstl[12] = (unsigned long )5;
  sqlstm.sqhsts[12] = (         int  )5;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asOppNbrType);
  sqlstm.sqhstl[13] = (unsigned long )5;
  sqlstm.sqhsts[13] = (         int  )5;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiOppCarrID);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asOppArea);
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )6;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asOppProv);
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )6;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asBillingTypeID);
  sqlstm.sqhstl[17] = (unsigned long )21;
  sqlstm.sqhsts[17] = (         int  )21;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asReserve1);
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )11;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asReserve2);
  sqlstm.sqhstl[19] = (unsigned long )11;
  sqlstm.sqhsts[19] = (         int  )11;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asReserve3);
  sqlstm.sqhstl[20] = (unsigned long )11;
  sqlstm.sqhsts[20] = (         int  )11;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asSettItemDate);
  sqlstm.sqhstl[21] = (unsigned long )9;
  sqlstm.sqhsts[21] = (         int  )9;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asBillingCycleID);
  sqlstm.sqhstl[22] = (unsigned long )7;
  sqlstm.sqhsts[22] = (         int  )7;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
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


		CheckSqlError("Fetch SETT_NBR_STATCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_NBR_STATCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 23;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )161;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_NBR_STAT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAccNbr,		pSource->asAccNbr[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sProvCode,		pSource->asProvCode[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sNetType,		pSource->asNetType[iCurPos]);

		p->iTicketTypeID=		pSource->aiTicketTypeID[iCurPos];
		p->iCnt=			pSource->aiCnt[iCurPos];
		p->iDuration=			pSource->aiDuration[iCurPos];
		p->iSettMin=			pSource->aiSettMin[iCurPos];

		strcpy(p->sInFee,		pSource->asInFee[iCurPos]);
		strcpy(p->sOutFee,		pSource->asOutFee[iCurPos]);
		strcpy(p->sServiceType,		pSource->asServiceType[iCurPos]);
		strcpy(p->sNbrType,		pSource->asNbrType[iCurPos]);
		strcpy(p->sOppNbrType,		pSource->asOppNbrType[iCurPos]);

		p->iOppCarrID=			pSource->aiOppCarrID[iCurPos];

		strcpy(p->sOppArea,		pSource->asOppArea[iCurPos]);
		strcpy(p->sOppProv,		pSource->asOppProv[iCurPos]);
		strcpy(p->sBillingTypeID,	pSource->asBillingTypeID[iCurPos]);
		strcpy(p->sReserve1,		pSource->asReserve1[iCurPos]);
		strcpy(p->sReserve2,		pSource->asReserve2[iCurPos]);
		strcpy(p->sReserve3,		pSource->asReserve3[iCurPos]);
		strcpy(p->sSettItemDate,	pSource->asSettItemDate[iCurPos]);
		strcpy(p->sBillingCycleID,	pSource->asBillingCycleID[iCurPos]);

		AllTrim(p->sAccNbr);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sProvCode);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sNetType);
		AllTrim(p->sInFee);
		AllTrim(p->sOutFee);
		AllTrim(p->sServiceType);
		AllTrim(p->sNbrType);
		AllTrim(p->sOppNbrType);
		AllTrim(p->sOppArea);
		AllTrim(p->sOppProv);
		AllTrim(p->sBillingTypeID);
		AllTrim(p->sReserve1);
		AllTrim(p->sReserve2);
		AllTrim(p->sReserve3);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sBillingCycleID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入SETT_NBR_STAT*/
int EInsertStructToSettNbrStat(struct SettNbrStatStruct *p,
	int iInsertFlag,struct SettNbrStatStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAccNbr[iCurPos],		p->sAccNbr);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asProvCode[iCurPos],		p->sProvCode);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asNetType[iCurPos],		p->sNetType);

		pTarget->aiTicketTypeID[iCurPos]=		p->iTicketTypeID;
		pTarget->aiCnt[iCurPos]=			p->iCnt;
		pTarget->aiDuration[iCurPos]=			p->iDuration;
		pTarget->aiSettMin[iCurPos]=			p->iSettMin;

		strcpy(pTarget->asInFee[iCurPos],		p->sInFee);
		strcpy(pTarget->asOutFee[iCurPos],		p->sOutFee);
		strcpy(pTarget->asServiceType[iCurPos],		p->sServiceType);
		strcpy(pTarget->asNbrType[iCurPos],		p->sNbrType);
		strcpy(pTarget->asOppNbrType[iCurPos],		p->sOppNbrType);

		pTarget->aiOppCarrID[iCurPos]=			p->iOppCarrID;

		strcpy(pTarget->asOppArea[iCurPos],		p->sOppArea);
		strcpy(pTarget->asOppProv[iCurPos],		p->sOppProv);
		strcpy(pTarget->asBillingTypeID[iCurPos],	p->sBillingTypeID);
		strcpy(pTarget->asReserve1[iCurPos],		p->sReserve1);
		strcpy(pTarget->asReserve2[iCurPos],		p->sReserve2);
		strcpy(pTarget->asReserve3[iCurPos],		p->sReserve3);
		strcpy(pTarget->asSettItemDate[iCurPos],	p->sSettItemDate);
		strcpy(pTarget->asBillingCycleID[iCurPos],	p->sBillingCycleID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_NBR_STAT_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				ACC_NBR,\n\
				HOME_AREA_CODE,\n\
				PROV_CODE,\n\
				VISIT_AREA_CODE,\n\
				NET_TYPE,\n\
				TICKET_TYPE_ID,\n\
				CNT,\n\
				DURATION,\n\
				SETT_MIN,\n\
				IN_FEE,\n\
				OUT_FEE,\n\
				SERVICE_TYPE,\n\
				NBR_TYPE,\n\
				OPP_NBR_TYPE,\n\
				OPP_CARR_ID,\n\
				OPP_AREA,\n\
				OPP_PROV,\n\
				BILLING_TYPE_ID,\n\
				RESERVE1,\n\
				RESERVE2,\n\
				RESERVE3,\n\
				SETT_ITEM_DATE,\n\
				BILLING_CYCLE_ID)\n\
			VALUES (\n\
				:asAccNbr,\n\
				:asHomeAreaCode,\n\
				:asProvCode,\n\
				:asVisitAreaCode,\n\
				:asNetType,\n\
				:aiTicketTypeID,\n\
				:aiCnt,\n\
				:aiDuration,\n\
				:aiSettMin,\n\
				to_number(:asInFee),\n\
				to_number(:asOutFee),\n\
				:asServiceType,\n\
				:asNbrType,\n\
				:asOppNbrType,\n\
				:aiOppCarrID,\n\
				:asOppArea,\n\
				:asOppProv,\n\
				:asBillingTypeID,\n\
				:asReserve1,\n\
				:asReserve2,\n\
				:asReserve3,\n\
				:asSettItemDate,\n\
				:asBillingCycleID\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_NBR_STATTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 23;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )176;
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


		if(CheckSqlResult("Prepare insert statement SETT_NBR_STAT")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_NBR_STATTRG USING
				:pTarget->asAccNbr,
				:pTarget->asHomeAreaCode,
				:pTarget->asProvCode,
				:pTarget->asVisitAreaCode,
				:pTarget->asNetType,
				:pTarget->aiTicketTypeID,
				:pTarget->aiCnt,
				:pTarget->aiDuration,
				:pTarget->aiSettMin,
				:pTarget->asInFee,
				:pTarget->asOutFee,
				:pTarget->asServiceType,
				:pTarget->asNbrType,
				:pTarget->asOppNbrType,
				:pTarget->aiOppCarrID,
				:pTarget->asOppArea,
				:pTarget->asOppProv,
				:pTarget->asBillingTypeID,
				:pTarget->asReserve1,
				:pTarget->asReserve2,
				:pTarget->asReserve3,
				:pTarget->asSettItemDate,
				:pTarget->asBillingCycleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 23;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )195;
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asProvCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asNetType);
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )5;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiTicketTypeID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiCnt);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->aiSettMin);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asInFee);
  sqlstm.sqhstl[9] = (unsigned long )13;
  sqlstm.sqhsts[9] = (         int  )13;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asOutFee);
  sqlstm.sqhstl[10] = (unsigned long )13;
  sqlstm.sqhsts[10] = (         int  )13;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asServiceType);
  sqlstm.sqhstl[11] = (unsigned long )4;
  sqlstm.sqhsts[11] = (         int  )4;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asNbrType);
  sqlstm.sqhstl[12] = (unsigned long )5;
  sqlstm.sqhsts[12] = (         int  )5;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asOppNbrType);
  sqlstm.sqhstl[13] = (unsigned long )5;
  sqlstm.sqhsts[13] = (         int  )5;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiOppCarrID);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asOppArea);
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )6;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asOppProv);
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )6;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asBillingTypeID);
  sqlstm.sqhstl[17] = (unsigned long )21;
  sqlstm.sqhsts[17] = (         int  )21;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asReserve1);
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )11;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asReserve2);
  sqlstm.sqhstl[19] = (unsigned long )11;
  sqlstm.sqhsts[19] = (         int  )11;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asReserve3);
  sqlstm.sqhstl[20] = (unsigned long )11;
  sqlstm.sqhsts[20] = (         int  )11;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asSettItemDate);
  sqlstm.sqhstl[21] = (unsigned long )9;
  sqlstm.sqhsts[21] = (         int  )9;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asBillingCycleID);
  sqlstm.sqhstl[22] = (unsigned long )7;
  sqlstm.sqhsts[22] = (         int  )7;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into SETT_NBR_STAT")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



void mvitem_settnbrstat(struct SettNbrStatStruct *pi,struct SettNbrStatStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct SettNbrStatStruct));

		strncpy(po->sAccNbr,		pi->sAccNbr,20);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sProvCode,		pi->sProvCode,5);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sNetType,		pi->sNetType,4);

		po->iTicketTypeID=		pi->iTicketTypeID;
		po->iCnt=			pi->iCnt;
		po->iDuration=			pi->iDuration;
		po->iSettMin=			pi->iSettMin;

		strncpy(po->sInFee,		pi->sInFee,12);
		strncpy(po->sOutFee,		pi->sOutFee,12);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sNbrType,		pi->sNbrType,4);
		strncpy(po->sOppNbrType,	pi->sOppNbrType,4);

		po->iOppCarrID=			pi->iOppCarrID;

		strncpy(po->sOppArea,		pi->sOppArea,5);
		strncpy(po->sOppProv,		pi->sOppProv,5);
		strncpy(po->sBillingTypeID,	pi->sBillingTypeID,20);
		strncpy(po->sReserve1,		pi->sReserve1,10);
		strncpy(po->sReserve2,		pi->sReserve2,10);
		strncpy(po->sReserve3,		pi->sReserve3,10);
		strncpy(po->sSettItemDate,	pi->sSettItemDate,8);
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);
}

void mvitem_mfsettnbrstat(struct SettNbrStatStruct *pi,struct FSettNbrStatStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettNbrStatStruct));

		strncpy(po->sAccNbr,pi->sAccNbr,strlen(pi->sAccNbr));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sProvCode,pi->sProvCode,strlen(pi->sProvCode));
		strncpy(po->sVisitAreaCode,pi->sVisitAreaCode,strlen(pi->sVisitAreaCode));
		strncpy(po->sNetType,pi->sNetType,strlen(pi->sNetType));

		sprintf(sTemp,"%04d",pi->iTicketTypeID);
		strncpy(po->sTicketTypeID,sTemp,4);
		sprintf(sTemp,"%09d",pi->iCnt);
		strncpy(po->sCnt,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDuration);
		strncpy(po->sDuration,sTemp,9);
		sprintf(sTemp,"%09d",pi->iSettMin);
		strncpy(po->sSettMin,sTemp,9);

		strncpy(po->sInFee,pi->sInFee,strlen(pi->sInFee));
		strncpy(po->sOutFee,pi->sOutFee,strlen(pi->sOutFee));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sNbrType,pi->sNbrType,strlen(pi->sNbrType));
		strncpy(po->sOppNbrType,pi->sOppNbrType,strlen(pi->sOppNbrType));

		sprintf(sTemp,"%04d",pi->iOppCarrID);
		strncpy(po->sOppCarrID,sTemp,4);

		strncpy(po->sOppArea,pi->sOppArea,strlen(pi->sOppArea));
		strncpy(po->sOppProv,pi->sOppProv,strlen(pi->sOppProv));
		strncpy(po->sBillingTypeID,pi->sBillingTypeID,strlen(pi->sBillingTypeID));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));
		strncpy(po->sReserve3,pi->sReserve3,strlen(pi->sReserve3));
		strncpy(po->sSettItemDate,pi->sSettItemDate,strlen(pi->sSettItemDate));
		strncpy(po->sBillingCycleID,pi->sBillingCycleID,strlen(pi->sBillingCycleID));

}
void mvitem_fmsettnbrstat(struct FSettNbrStatStruct *pi,struct SettNbrStatStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SettNbrStatStruct));

		strncpy(po->sAccNbr,		pi->sAccNbr,20);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sProvCode,		pi->sProvCode,5);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sNetType,		pi->sNetType,4);

		strncpy(sTemp,	pi->sTicketTypeID,4);sTemp[4]=0;
		po->iTicketTypeID=atoi(sTemp);
		strncpy(sTemp,		pi->sCnt,9);sTemp[9]=0;
		po->iCnt=atoi(sTemp);
		strncpy(sTemp,		pi->sDuration,9);sTemp[9]=0;
		po->iDuration=atoi(sTemp);		
		strncpy(sTemp,		pi->sSettMin,9);sTemp[9]=0;
		po->iSettMin=atoi(sTemp);

		strncpy(po->sInFee,		pi->sInFee,12);
		strncpy(po->sOutFee,		pi->sOutFee,12);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sNbrType,		pi->sNbrType,4);
		strncpy(po->sOppNbrType,	pi->sOppNbrType,4);

		strncpy(sTemp,		pi->sOppCarrID,4);sTemp[4]=0;
		po->iOppCarrID=atoi(sTemp);

		strncpy(po->sOppArea,		pi->sOppArea,5);
		strncpy(po->sOppProv,		pi->sOppProv,5);
		strncpy(po->sBillingTypeID,	pi->sBillingTypeID,20);
		strncpy(po->sReserve1,		pi->sReserve1,10);
		strncpy(po->sReserve2,		pi->sReserve2,10);
		strncpy(po->sReserve3,		pi->sReserve3,10);
		strncpy(po->sSettItemDate,	pi->sSettItemDate,8);
		strncpy(po->sBillingCycleID,	pi->sBillingCycleID,6);

		AllTrim(po->sAccNbr);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sProvCode);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sNetType);
		AllTrim(po->sInFee);
		AllTrim(po->sOutFee);
		AllTrim(po->sServiceType);
		AllTrim(po->sNbrType);
		AllTrim(po->sOppNbrType);
		AllTrim(po->sOppArea);
		AllTrim(po->sOppProv);
		AllTrim(po->sBillingTypeID);
		AllTrim(po->sReserve1);
		AllTrim(po->sReserve2);
		AllTrim(po->sReserve3);
		AllTrim(po->sSettItemDate);
		AllTrim(po->sBillingCycleID);
}
/**********************2016.01.29*******************/
int IsInNBR(char sMsisdn[])
{
			int iStaffID=0;
	
	  /* EXEC SQL SELECT COUNT(*) INTO :iStaffID 
		FROM zhjs.ALL_APP_INFO_NBR 
		WHERE MSISDN=:sMsisdn; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 23;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select count(*)  into :b0  from zhjs.ALL_APP_INFO_NBR whe\
re MSISDN=:b1";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )302;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&iStaffID;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)sMsisdn;
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



/*	EXEC SQL SELECT STAFF_ID INTO :iStaffID FROM STAFF WHERE ROWNUM<2;*/
	if(CheckSqlResult("CHECK ALL_APP_INFO_NBR")<0) return -1;

	return iStaffID;
}

