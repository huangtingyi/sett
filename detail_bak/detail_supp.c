
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
    "detail_supp.pc"
};


static unsigned int sqlctx = 1157627;


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
   unsigned char  *sqhstv[41];
   unsigned long  sqhstl[41];
            int   sqhsts[41];
            short *sqindv[41];
            int   sqinds[41];
   unsigned long  sqharm[41];
   unsigned long  *sqharc[41];
   unsigned short  sqadto[41];
   unsigned short  sqtdso[41];
} sqlstm = {12,41};

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
5,0,0,1,0,0,17,71,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,77,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,94,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,102,0,0,41,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,
233,0,0,1,0,0,15,156,0,0,0,0,0,1,0,
248,0,0,2,0,0,17,309,0,0,1,1,0,1,0,1,97,0,0,
267,0,0,2,0,0,45,315,0,0,0,0,0,1,0,
282,0,0,2,0,0,15,332,0,0,0,0,0,1,0,
297,0,0,2,0,0,13,340,0,0,27,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
420,0,0,2,0,0,15,380,0,0,0,0,0,1,0,
435,0,0,3,0,0,17,516,0,0,1,1,0,1,0,1,97,0,0,
454,0,0,3,0,0,45,522,0,0,0,0,0,1,0,
469,0,0,3,0,0,15,539,0,0,0,0,0,1,0,
484,0,0,3,0,0,13,547,0,0,34,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,
635,0,0,3,0,0,15,594,0,0,0,0,0,1,0,
650,0,0,4,0,0,17,721,0,0,1,1,0,1,0,1,97,0,0,
669,0,0,4,0,0,45,727,0,0,0,0,0,1,0,
684,0,0,4,0,0,15,744,0,0,0,0,0,1,0,
699,0,0,4,0,0,13,752,0,0,14,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
770,0,0,4,0,0,15,779,0,0,0,0,0,1,0,
785,0,0,5,0,0,17,867,0,0,1,1,0,1,0,1,97,0,0,
804,0,0,5,0,0,45,873,0,0,0,0,0,1,0,
819,0,0,5,0,0,15,890,0,0,0,0,0,1,0,
834,0,0,5,0,0,13,898,0,0,15,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,
909,0,0,5,0,0,15,926,0,0,0,0,0,1,0,
924,0,0,6,0,0,17,1052,0,0,1,1,0,1,0,1,97,0,0,
943,0,0,6,0,0,21,1055,0,0,14,14,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
1014,0,0,7,0,0,17,1112,0,0,1,1,0,1,0,1,97,0,0,
1033,0,0,7,0,0,21,1116,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1056,0,0,6,0,0,17,1191,0,0,1,1,0,1,0,1,97,0,0,
1075,0,0,6,0,0,17,1192,0,0,1,1,0,1,0,1,97,0,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <wwdir.h>

#include <detail_supp.h>

/*批量数据动态从T_YD_UE_CM中用结构缓冲方式取数据*/
int EGetAccSttTicketToStruct(struct AccSttTicketStruct *p,
	struct AccSttTicketStructIn *pSource)
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
				nvl(CITY_ID,' '),\n\
				nvl(CDR_TYPE,' '),\n\
				nvl(CALLING_CITY_ID,' '),\n\
				nvl(CALLING_EXCEPTION,' '),\n\
				nvl(CALLING_TYPE,' '),\n\
				nvl(CALLING_COMP_CODE,' '),\n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLING_NUMBER,' '),\n\
				nvl(CALLED_CITY_ID,' '),\n\
				nvl(CALLED_EXCEPTION,' '),\n\
				nvl(CALLED_NUMBER_TYPE,' '),\n\
				nvl(CALLED_COMP_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				nvl(CALLED_NUMBER,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(END_TIME,' '),\n\
				to_char(nvl(DURATION,0)),\n\
				nvl(IN_TRUNK_NUMBER,' '),\n\
				nvl(IN_COMPANY_CODE,' '),\n\
				nvl(IN_TRUNK_NET_TYPE,' '),\n\
				nvl(OUT_TRUNK_NUMBER,' '),\n\
				nvl(OUT_COMPANY_CODE,' '),\n\
				nvl(OUT_TRUNK_NET_TYPE,' '),\n\
				nvl(IS_FREE,' '),\n\
				nvl(CALLING_LOCATION,' '),\n\
				nvl(SECOND_CALLING_LOCATION,' '),\n\
				nvl(ORIG_CALLING_NUMBER,' '),\n\
				nvl(ORIG_CALLED_NUMBER,' '),\n\
				nvl(ORIG_SECOND_CALLING_NUMBER,' '),\n\
				nvl(EXCEPTION_TYPE,' '),\n\
				nvl(PRE_CALL_TYPE,' '),\n\
				nvl(TURN_TYPE,' '),\n\
				nvl(PROD_ID,' '),\n\
				nvl(RATE_UNIT_TYPE,' '),\n\
				to_char(nvl(STL_DURATION,0)),\n\
				nvl(RATE_ID,' '),\n\
				to_char(nvl(STL_AMOUNT,0)),\n\
				nvl(GROUP_ID,' '),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(CALL_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE T_YD_UE_CMSCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE T_YD_UE_CMSCR T_YD_UE_CMCR");

		/* EXEC SQL DECLARE T_YD_UE_CMCR CURSOR FOR T_YD_UE_CMSCR; */ 

		CheckSqlError("Declare T_YD_UE_CMCR");

		/* EXEC SQL OPEN T_YD_UE_CMCR; */ 

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


		CheckSqlError("Open T_YD_UE_CMCR;");


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

		/* EXEC SQL CLOSE T_YD_UE_CMCR; */ 

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
		/* EXEC SQL FETCH T_YD_UE_CMCR INTO
			:pSource->asUsageEventID,
			:pSource->asCityID,
			:pSource->asCdrType,
			:pSource->asCallingCityID,
			:pSource->asCallingException,
			:pSource->asCallingType,
			:pSource->asCallingCompCode,
			:pSource->asCallingAreaCode,
			:pSource->asCallingNumber,
			:pSource->asCalledCityID,
			:pSource->asCalledException,
			:pSource->asCalledNumberType,
			:pSource->asCalledCompCode,
			:pSource->asCalledAreaCode,
			:pSource->asCalledNumber,
			:pSource->asStartTime,
			:pSource->asEndTime,
			:pSource->asDuration,
			:pSource->asInTrunkNumber,
			:pSource->asInCompanyCode,
			:pSource->asInTrunkNetType,
			:pSource->asOutTrunkNumber,
			:pSource->asOutCompanyCode,
			:pSource->asOutTrunkNetType,
			:pSource->asIsFree,
			:pSource->asCallingLocation,
			:pSource->asSecondCallingLocation,
			:pSource->asOrigCallingNumber,
			:pSource->asOrigCalledNumber,
			:pSource->asOrigSecondCallingNumber,
			:pSource->asExceptionType,
			:pSource->asPreCallType,
			:pSource->asTurnType,
			:pSource->asProdID,
			:pSource->asRateUnitType,
			:pSource->asStlDuration,
			:pSource->asRateID,
			:pSource->asStlAmount,
			:pSource->asGroupID,
			:pSource->asFileName,
			:pSource->asCallType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
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
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asUsageEventID);
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )19;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCityID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )7;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asCdrType);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallingCityID);
  sqlstm.sqhstl[3] = (unsigned long )9;
  sqlstm.sqhsts[3] = (         int  )9;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCallingException);
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )5;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCallingType);
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )5;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asCallingCompCode);
  sqlstm.sqhstl[6] = (unsigned long )3;
  sqlstm.sqhsts[6] = (         int  )3;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[7] = (unsigned long )9;
  sqlstm.sqhsts[7] = (         int  )9;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asCallingNumber);
  sqlstm.sqhstl[8] = (unsigned long )31;
  sqlstm.sqhsts[8] = (         int  )31;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asCalledCityID);
  sqlstm.sqhstl[9] = (unsigned long )9;
  sqlstm.sqhsts[9] = (         int  )9;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asCalledException);
  sqlstm.sqhstl[10] = (unsigned long )5;
  sqlstm.sqhsts[10] = (         int  )5;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asCalledNumberType);
  sqlstm.sqhstl[11] = (unsigned long )5;
  sqlstm.sqhsts[11] = (         int  )5;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asCalledCompCode);
  sqlstm.sqhstl[12] = (unsigned long )3;
  sqlstm.sqhsts[12] = (         int  )3;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[13] = (unsigned long )9;
  sqlstm.sqhsts[13] = (         int  )9;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asCalledNumber);
  sqlstm.sqhstl[14] = (unsigned long )31;
  sqlstm.sqhsts[14] = (         int  )31;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[15] = (unsigned long )17;
  sqlstm.sqhsts[15] = (         int  )17;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asEndTime);
  sqlstm.sqhstl[16] = (unsigned long )17;
  sqlstm.sqhsts[16] = (         int  )17;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asDuration);
  sqlstm.sqhstl[17] = (unsigned long )19;
  sqlstm.sqhsts[17] = (         int  )19;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asInTrunkNumber);
  sqlstm.sqhstl[18] = (unsigned long )12;
  sqlstm.sqhsts[18] = (         int  )12;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asInCompanyCode);
  sqlstm.sqhstl[19] = (unsigned long )5;
  sqlstm.sqhsts[19] = (         int  )5;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asInTrunkNetType);
  sqlstm.sqhstl[20] = (unsigned long )5;
  sqlstm.sqhsts[20] = (         int  )5;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asOutTrunkNumber);
  sqlstm.sqhstl[21] = (unsigned long )12;
  sqlstm.sqhsts[21] = (         int  )12;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asOutCompanyCode);
  sqlstm.sqhstl[22] = (unsigned long )5;
  sqlstm.sqhsts[22] = (         int  )5;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asOutTrunkNetType);
  sqlstm.sqhstl[23] = (unsigned long )5;
  sqlstm.sqhsts[23] = (         int  )5;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asIsFree);
  sqlstm.sqhstl[24] = (unsigned long )5;
  sqlstm.sqhsts[24] = (         int  )5;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asCallingLocation);
  sqlstm.sqhstl[25] = (unsigned long )5;
  sqlstm.sqhsts[25] = (         int  )5;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->asSecondCallingLocation);
  sqlstm.sqhstl[26] = (unsigned long )5;
  sqlstm.sqhsts[26] = (         int  )5;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asOrigCallingNumber);
  sqlstm.sqhstl[27] = (unsigned long )37;
  sqlstm.sqhsts[27] = (         int  )37;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->asOrigCalledNumber);
  sqlstm.sqhstl[28] = (unsigned long )37;
  sqlstm.sqhsts[28] = (         int  )37;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pSource->asOrigSecondCallingNumber);
  sqlstm.sqhstl[29] = (unsigned long )37;
  sqlstm.sqhsts[29] = (         int  )37;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pSource->asExceptionType);
  sqlstm.sqhstl[30] = (unsigned long )11;
  sqlstm.sqhsts[30] = (         int  )11;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pSource->asPreCallType);
  sqlstm.sqhstl[31] = (unsigned long )5;
  sqlstm.sqhsts[31] = (         int  )5;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pSource->asTurnType);
  sqlstm.sqhstl[32] = (unsigned long )5;
  sqlstm.sqhsts[32] = (         int  )5;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[33] = (unsigned long )16;
  sqlstm.sqhsts[33] = (         int  )16;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pSource->asRateUnitType);
  sqlstm.sqhstl[34] = (unsigned long )5;
  sqlstm.sqhsts[34] = (         int  )5;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pSource->asStlDuration);
  sqlstm.sqhstl[35] = (unsigned long )19;
  sqlstm.sqhsts[35] = (         int  )19;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pSource->asRateID);
  sqlstm.sqhstl[36] = (unsigned long )11;
  sqlstm.sqhsts[36] = (         int  )11;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pSource->asStlAmount);
  sqlstm.sqhstl[37] = (unsigned long )19;
  sqlstm.sqhsts[37] = (         int  )19;
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[38] = (unsigned long )3;
  sqlstm.sqhsts[38] = (         int  )3;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[39] = (unsigned long )65;
  sqlstm.sqhsts[39] = (         int  )65;
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[40] = (unsigned long )3;
  sqlstm.sqhsts[40] = (         int  )3;
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
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


		CheckSqlError("Fetch T_YD_UE_CMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE T_YD_UE_CMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 41;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )233;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ACC_STT_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sUsageEventID,		pSource->asUsageEventID[iCurPos]);
		strcpy(p->sCityID,			pSource->asCityID[iCurPos]);
		strcpy(p->sCdrType,			pSource->asCdrType[iCurPos]);
		strcpy(p->sCallingCityID,		pSource->asCallingCityID[iCurPos]);
		strcpy(p->sCallingException,		pSource->asCallingException[iCurPos]);
		strcpy(p->sCallingType,			pSource->asCallingType[iCurPos]);
		strcpy(p->sCallingCompCode,		pSource->asCallingCompCode[iCurPos]);
		strcpy(p->sCallingAreaCode,		pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCallingNumber,		pSource->asCallingNumber[iCurPos]);
		strcpy(p->sCalledCityID,		pSource->asCalledCityID[iCurPos]);
		strcpy(p->sCalledException,		pSource->asCalledException[iCurPos]);
		strcpy(p->sCalledNumberType,		pSource->asCalledNumberType[iCurPos]);
		strcpy(p->sCalledCompCode,		pSource->asCalledCompCode[iCurPos]);
		strcpy(p->sCalledAreaCode,		pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sCalledNumber,		pSource->asCalledNumber[iCurPos]);
		strcpy(p->sStartTime,			pSource->asStartTime[iCurPos]);
		strcpy(p->sEndTime,			pSource->asEndTime[iCurPos]);
		strcpy(p->sDuration,			pSource->asDuration[iCurPos]);
		strcpy(p->sInTrunkNumber,		pSource->asInTrunkNumber[iCurPos]);
		strcpy(p->sInCompanyCode,		pSource->asInCompanyCode[iCurPos]);
		strcpy(p->sInTrunkNetType,		pSource->asInTrunkNetType[iCurPos]);
		strcpy(p->sOutTrunkNumber,		pSource->asOutTrunkNumber[iCurPos]);
		strcpy(p->sOutCompanyCode,		pSource->asOutCompanyCode[iCurPos]);
		strcpy(p->sOutTrunkNetType,		pSource->asOutTrunkNetType[iCurPos]);
		strcpy(p->sIsFree,			pSource->asIsFree[iCurPos]);
		strcpy(p->sCallingLocation,		pSource->asCallingLocation[iCurPos]);
		strcpy(p->sSecondCallingLocation,	pSource->asSecondCallingLocation[iCurPos]);
		strcpy(p->sOrigCallingNumber,		pSource->asOrigCallingNumber[iCurPos]);
		strcpy(p->sOrigCalledNumber,		pSource->asOrigCalledNumber[iCurPos]);
		strcpy(p->sOrigSecondCallingNumber,	pSource->asOrigSecondCallingNumber[iCurPos]);
		strcpy(p->sExceptionType,		pSource->asExceptionType[iCurPos]);
		strcpy(p->sPreCallType,			pSource->asPreCallType[iCurPos]);
		strcpy(p->sTurnType,			pSource->asTurnType[iCurPos]);
		strcpy(p->sProdID,			pSource->asProdID[iCurPos]);
		strcpy(p->sRateUnitType,		pSource->asRateUnitType[iCurPos]);
		strcpy(p->sStlDuration,			pSource->asStlDuration[iCurPos]);
		strcpy(p->sRateID,			pSource->asRateID[iCurPos]);
		strcpy(p->sStlAmount,			pSource->asStlAmount[iCurPos]);
		strcpy(p->sGroupID,			pSource->asGroupID[iCurPos]);
		strcpy(p->sFileName,			pSource->asFileName[iCurPos]);
		strcpy(p->sCallType,			pSource->asCallType[iCurPos]);

		AllTrim(p->sUsageEventID);
		AllTrim(p->sCityID);
		AllTrim(p->sCdrType);
		AllTrim(p->sCallingCityID);
		AllTrim(p->sCallingException);
		AllTrim(p->sCallingType);
		AllTrim(p->sCallingCompCode);
		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCallingNumber);
		AllTrim(p->sCalledCityID);
		AllTrim(p->sCalledException);
		AllTrim(p->sCalledNumberType);
		AllTrim(p->sCalledCompCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sCalledNumber);
		AllTrim(p->sStartTime);
		AllTrim(p->sEndTime);
		AllTrim(p->sDuration);
		AllTrim(p->sInTrunkNumber);
		AllTrim(p->sInCompanyCode);
		AllTrim(p->sInTrunkNetType);
		AllTrim(p->sOutTrunkNumber);
		AllTrim(p->sOutCompanyCode);
		AllTrim(p->sOutTrunkNetType);
		AllTrim(p->sIsFree);
		AllTrim(p->sCallingLocation);
		AllTrim(p->sSecondCallingLocation);
		AllTrim(p->sOrigCallingNumber);
		AllTrim(p->sOrigCalledNumber);
		AllTrim(p->sOrigSecondCallingNumber);
		AllTrim(p->sExceptionType);
		AllTrim(p->sPreCallType);
		AllTrim(p->sTurnType);
		AllTrim(p->sProdID);
		AllTrim(p->sRateUnitType);
		AllTrim(p->sStlDuration);
		AllTrim(p->sRateID);
		AllTrim(p->sStlAmount);
		AllTrim(p->sGroupID);
		AllTrim(p->sFileName);
		AllTrim(p->sCallType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}


/*批量数据动态从ST_SMS_TICKET中用结构缓冲方式取数据*/
int EGetAccSmsTicketToStruct(struct AccSmsTicketStruct *p,
	struct AccSmsTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(PROD_ID,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(END_TIME,' '),\n\
				nvl(CALLING_NUMBER,' '),\n\
				nvl(CALLING_CITY_ID,' '),\n\
				nvl(CALLING_COMPANY_ID,' '),\n\
				nvl(CALLING_NUMBER_TYPE,' '),\n\
				nvl(CALLED_NUMBER,' '),\n\
				nvl(CALLED_CITY_ID,' '),\n\
				nvl(CALLED_COMPANY_ID,' '),\n\
				nvl(CALLED_NUMBER_TYPE,' '),\n\
				nvl(CITY_ID,0),\n\
				nvl(IS_FREE,' '),\n\
				nvl(BILL_CYCLE_SEQ,0),\n\
				nvl(EXCEPTION_TYPE,' '),\n\
				to_char(nvl(STL_AMOUNT,0)),\n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				nvl(STL_DIRECTION,' '),\n\
				nvl(UP_GW,' '),\n\
				nvl(DOWN_GW,' '),\n\
				nvl(UP_COMPANY_ID,' '),\n\
				nvl(DOWN_COMPANY_ID,' '),\n\
				to_char(nvl(USAGE_EVENT_ID,0)),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(GROUP_ID,' '),\n\
				nvl(CALL_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ST_SMS_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )248;
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


		CheckSqlError(" PREPARE ST_SMS_TICKETSCR ST_SMS_TICKETCR");

		/* EXEC SQL DECLARE ST_SMS_TICKETCR CURSOR FOR ST_SMS_TICKETSCR; */ 

		CheckSqlError("Declare ST_SMS_TICKETCR");

		/* EXEC SQL OPEN ST_SMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )267;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ST_SMS_TICKETCR;");


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

		/* EXEC SQL CLOSE ST_SMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )282;
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
		/* EXEC SQL FETCH ST_SMS_TICKETCR INTO
			:pSource->asProdID,
			:pSource->asStartTime,
			:pSource->asEndTime,
			:pSource->asCallingNumber,
			:pSource->asCallingCityID,
			:pSource->asCallingCompanyID,
			:pSource->asCallingNumberType,
			:pSource->asCalledNumber,
			:pSource->asCalledCityID,
			:pSource->asCalledCompanyID,
			:pSource->asCalledNumberType,
			:pSource->aiCityID,
			:pSource->asIsFree,
			:pSource->aiBillCycleSeq,
			:pSource->asExceptionType,
			:pSource->asStlAmount,
			:pSource->asCallingAreaCode,
			:pSource->asCalledAreaCode,
			:pSource->asStlDirection,
			:pSource->asUpGw,
			:pSource->asDownGw,
			:pSource->asUpCompanyID,
			:pSource->asDownCompanyID,
			:pSource->asUsageEventID,
			:pSource->asFileName,
			:pSource->asGroupID,
			:pSource->asCallType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )297;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )31;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )19;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asEndTime);
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )19;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallingNumber);
  sqlstm.sqhstl[3] = (unsigned long )33;
  sqlstm.sqhsts[3] = (         int  )33;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCallingCityID);
  sqlstm.sqhstl[4] = (unsigned long )7;
  sqlstm.sqhsts[4] = (         int  )7;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCallingCompanyID);
  sqlstm.sqhstl[5] = (unsigned long )3;
  sqlstm.sqhsts[5] = (         int  )3;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asCallingNumberType);
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )5;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCalledNumber);
  sqlstm.sqhstl[7] = (unsigned long )33;
  sqlstm.sqhsts[7] = (         int  )33;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asCalledCityID);
  sqlstm.sqhstl[8] = (unsigned long )7;
  sqlstm.sqhsts[8] = (         int  )7;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asCalledCompanyID);
  sqlstm.sqhstl[9] = (unsigned long )3;
  sqlstm.sqhsts[9] = (         int  )3;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asCalledNumberType);
  sqlstm.sqhstl[10] = (unsigned long )5;
  sqlstm.sqhsts[10] = (         int  )5;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiCityID);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asIsFree);
  sqlstm.sqhstl[12] = (unsigned long )5;
  sqlstm.sqhsts[12] = (         int  )5;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->aiBillCycleSeq);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asExceptionType);
  sqlstm.sqhstl[14] = (unsigned long )9;
  sqlstm.sqhsts[14] = (         int  )9;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asStlAmount);
  sqlstm.sqhstl[15] = (unsigned long )19;
  sqlstm.sqhsts[15] = (         int  )19;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[16] = (unsigned long )33;
  sqlstm.sqhsts[16] = (         int  )33;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[17] = (unsigned long )33;
  sqlstm.sqhsts[17] = (         int  )33;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asStlDirection);
  sqlstm.sqhstl[18] = (unsigned long )5;
  sqlstm.sqhsts[18] = (         int  )5;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asUpGw);
  sqlstm.sqhstl[19] = (unsigned long )33;
  sqlstm.sqhsts[19] = (         int  )33;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asDownGw);
  sqlstm.sqhstl[20] = (unsigned long )33;
  sqlstm.sqhsts[20] = (         int  )33;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asUpCompanyID);
  sqlstm.sqhstl[21] = (unsigned long )3;
  sqlstm.sqhsts[21] = (         int  )3;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asDownCompanyID);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asUsageEventID);
  sqlstm.sqhstl[23] = (unsigned long )19;
  sqlstm.sqhsts[23] = (         int  )19;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[24] = (unsigned long )65;
  sqlstm.sqhsts[24] = (         int  )65;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[25] = (unsigned long )3;
  sqlstm.sqhsts[25] = (         int  )3;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[26] = (unsigned long )3;
  sqlstm.sqhsts[26] = (         int  )3;
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


		CheckSqlError("Fetch ST_SMS_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ST_SMS_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 41;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )420;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ACC_SMS_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);
		strcpy(p->sEndTime,		pSource->asEndTime[iCurPos]);
		strcpy(p->sCallingNumber,	pSource->asCallingNumber[iCurPos]);
		strcpy(p->sCallingCityID,	pSource->asCallingCityID[iCurPos]);
		strcpy(p->sCallingCompanyID,	pSource->asCallingCompanyID[iCurPos]);
		strcpy(p->sCallingNumberType,	pSource->asCallingNumberType[iCurPos]);
		strcpy(p->sCalledNumber,	pSource->asCalledNumber[iCurPos]);
		strcpy(p->sCalledCityID,	pSource->asCalledCityID[iCurPos]);
		strcpy(p->sCalledCompanyID,	pSource->asCalledCompanyID[iCurPos]);
		strcpy(p->sCalledNumberType,	pSource->asCalledNumberType[iCurPos]);

		p->iCityID=			pSource->aiCityID[iCurPos];

		strcpy(p->sIsFree,		pSource->asIsFree[iCurPos]);

		p->iBillCycleSeq=		pSource->aiBillCycleSeq[iCurPos];

		strcpy(p->sExceptionType,	pSource->asExceptionType[iCurPos]);
		strcpy(p->sStlAmount,		pSource->asStlAmount[iCurPos]);
		strcpy(p->sCallingAreaCode,	pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCalledAreaCode,	pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sStlDirection,	pSource->asStlDirection[iCurPos]);
		strcpy(p->sUpGw,		pSource->asUpGw[iCurPos]);
		strcpy(p->sDownGw,		pSource->asDownGw[iCurPos]);
		strcpy(p->sUpCompanyID,		pSource->asUpCompanyID[iCurPos]);
		strcpy(p->sDownCompanyID,	pSource->asDownCompanyID[iCurPos]);
		strcpy(p->sUsageEventID,	pSource->asUsageEventID[iCurPos]);
		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sGroupID,		pSource->asGroupID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);

		AllTrim(p->sProdID);
		AllTrim(p->sStartTime);
		AllTrim(p->sEndTime);
		AllTrim(p->sCallingNumber);
		AllTrim(p->sCallingCityID);
		AllTrim(p->sCallingCompanyID);
		AllTrim(p->sCallingNumberType);
		AllTrim(p->sCalledNumber);
		AllTrim(p->sCalledCityID);
		AllTrim(p->sCalledCompanyID);
		AllTrim(p->sCalledNumberType);
		AllTrim(p->sIsFree);
		AllTrim(p->sExceptionType);
		AllTrim(p->sStlAmount);
		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sStlDirection);
		AllTrim(p->sUpGw);
		AllTrim(p->sDownGw);
		AllTrim(p->sUpCompanyID);
		AllTrim(p->sDownCompanyID);
		AllTrim(p->sUsageEventID);
		AllTrim(p->sFileName);
		AllTrim(p->sGroupID);
		AllTrim(p->sCallType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}




/*批量数据动态从ST_MMS_TICKET中用结构缓冲方式取数据*/
int EGetAccMmsTicketToStruct(struct AccMmsTicketStruct *p,
	struct AccMmsTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(PROD_ID,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(END_TIME,' '),\n\
				nvl(CALLING_NUMBER,' '),\n\
				nvl(CALLED_NUMBER,' '),\n\
				nvl(OPERATION_TYPE_ID,' '),\n\
				nvl(CITY_ID,0),\n\
				nvl(IS_FREE,' '),\n\
				nvl(RATE_UNIT_TYPE,' '),\n\
				to_char(nvl(RATE_UNITS,0)),\n\
				nvl(BILL_CYCLE_SEQ,0),\n\
				nvl(EXCEPTION_TYPE,' '),\n\
				nvl(PROVINCE_ID,' '),\n\
				nvl(CALLING_GROUP_ID,' '),\n\
				nvl(CALLED_GROUP_ID,' '),\n\
				nvl(CALLING_COMPANY_ID,' '),\n\
				nvl(CALLED_COMPANY_ID,' '),\n\
				nvl(STL_OBJECT,' '),\n\
				to_char(nvl(STL_AMOUNT,0)),\n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				nvl(STL_DIRECTION,' '),\n\
				nvl(UP_GW,' '),\n\
				nvl(DOWN_GW,' '),\n\
				nvl(UPGW_GROUP_ID,' '),\n\
				nvl(DOWN_GW_GROUP_ID,' '),\n\
				nvl(UP_COMPANY_ID,' '),\n\
				nvl(DOWN_COMPANY_ID,' '),\n\
				to_char(nvl(USAGE_EVENT_ID,0)),\n\
				nvl(CALLING_CITY_CODE,' '),\n\
				nvl(CALLED_CITY_CODE,' '),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(GROUP_ID,' '),\n\
				nvl(CALL_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ST_MMS_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )435;
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


		CheckSqlError(" PREPARE ST_MMS_TICKETSCR ST_MMS_TICKETCR");

		/* EXEC SQL DECLARE ST_MMS_TICKETCR CURSOR FOR ST_MMS_TICKETSCR; */ 

		CheckSqlError("Declare ST_MMS_TICKETCR");

		/* EXEC SQL OPEN ST_MMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )454;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ST_MMS_TICKETCR;");


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

		/* EXEC SQL CLOSE ST_MMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )469;
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
		/* EXEC SQL FETCH ST_MMS_TICKETCR INTO
			:pSource->asProdID,
			:pSource->asStartTime,
			:pSource->asEndTime,
			:pSource->asCallingNumber,
			:pSource->asCalledNumber,
			:pSource->asOperationTypeID,
			:pSource->aiCityID,
			:pSource->asIsFree,
			:pSource->asRateUnitType,
			:pSource->asRateUnits,
			:pSource->aiBillCycleSeq,
			:pSource->asExceptionType,
			:pSource->asProvinceID,
			:pSource->asCallingGroupID,
			:pSource->asCalledGroupID,
			:pSource->asCallingCompanyID,
			:pSource->asCalledCompanyID,
			:pSource->asStlObject,
			:pSource->asStlAmount,
			:pSource->asCallingAreaCode,
			:pSource->asCalledAreaCode,
			:pSource->asStlDirection,
			:pSource->asUpGw,
			:pSource->asDownGw,
			:pSource->asUpgwGroupID,
			:pSource->asDownGwGroupID,
			:pSource->asUpCompanyID,
			:pSource->asDownCompanyID,
			:pSource->asUsageEventID,
			:pSource->asCallingCityCode,
			:pSource->asCalledCityCode,
			:pSource->asFileName,
			:pSource->asGroupID,
			:pSource->asCallType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )484;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )31;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )19;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asEndTime);
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )19;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallingNumber);
  sqlstm.sqhstl[3] = (unsigned long )33;
  sqlstm.sqhsts[3] = (         int  )33;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCalledNumber);
  sqlstm.sqhstl[4] = (unsigned long )33;
  sqlstm.sqhsts[4] = (         int  )33;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asOperationTypeID);
  sqlstm.sqhstl[5] = (unsigned long )9;
  sqlstm.sqhsts[5] = (         int  )9;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiCityID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asIsFree);
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )5;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asRateUnitType);
  sqlstm.sqhstl[8] = (unsigned long )5;
  sqlstm.sqhsts[8] = (         int  )5;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asRateUnits);
  sqlstm.sqhstl[9] = (unsigned long )13;
  sqlstm.sqhsts[9] = (         int  )13;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiBillCycleSeq);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asExceptionType);
  sqlstm.sqhstl[11] = (unsigned long )9;
  sqlstm.sqhsts[11] = (         int  )9;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asProvinceID);
  sqlstm.sqhstl[12] = (unsigned long )5;
  sqlstm.sqhsts[12] = (         int  )5;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asCallingGroupID);
  sqlstm.sqhstl[13] = (unsigned long )33;
  sqlstm.sqhsts[13] = (         int  )33;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asCalledGroupID);
  sqlstm.sqhstl[14] = (unsigned long )33;
  sqlstm.sqhsts[14] = (         int  )33;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asCallingCompanyID);
  sqlstm.sqhstl[15] = (unsigned long )9;
  sqlstm.sqhsts[15] = (         int  )9;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asCalledCompanyID);
  sqlstm.sqhstl[16] = (unsigned long )9;
  sqlstm.sqhsts[16] = (         int  )9;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asStlObject);
  sqlstm.sqhstl[17] = (unsigned long )9;
  sqlstm.sqhsts[17] = (         int  )9;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asStlAmount);
  sqlstm.sqhstl[18] = (unsigned long )19;
  sqlstm.sqhsts[18] = (         int  )19;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[19] = (unsigned long )33;
  sqlstm.sqhsts[19] = (         int  )33;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[20] = (unsigned long )33;
  sqlstm.sqhsts[20] = (         int  )33;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asStlDirection);
  sqlstm.sqhstl[21] = (unsigned long )5;
  sqlstm.sqhsts[21] = (         int  )5;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asUpGw);
  sqlstm.sqhstl[22] = (unsigned long )33;
  sqlstm.sqhsts[22] = (         int  )33;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asDownGw);
  sqlstm.sqhstl[23] = (unsigned long )33;
  sqlstm.sqhsts[23] = (         int  )33;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asUpgwGroupID);
  sqlstm.sqhstl[24] = (unsigned long )33;
  sqlstm.sqhsts[24] = (         int  )33;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asDownGwGroupID);
  sqlstm.sqhstl[25] = (unsigned long )33;
  sqlstm.sqhsts[25] = (         int  )33;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->asUpCompanyID);
  sqlstm.sqhstl[26] = (unsigned long )33;
  sqlstm.sqhsts[26] = (         int  )33;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asDownCompanyID);
  sqlstm.sqhstl[27] = (unsigned long )33;
  sqlstm.sqhsts[27] = (         int  )33;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->asUsageEventID);
  sqlstm.sqhstl[28] = (unsigned long )19;
  sqlstm.sqhsts[28] = (         int  )19;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pSource->asCallingCityCode);
  sqlstm.sqhstl[29] = (unsigned long )33;
  sqlstm.sqhsts[29] = (         int  )33;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pSource->asCalledCityCode);
  sqlstm.sqhstl[30] = (unsigned long )33;
  sqlstm.sqhsts[30] = (         int  )33;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[31] = (unsigned long )65;
  sqlstm.sqhsts[31] = (         int  )65;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[32] = (unsigned long )3;
  sqlstm.sqhsts[32] = (         int  )3;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[33] = (unsigned long )3;
  sqlstm.sqhsts[33] = (         int  )3;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
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


		CheckSqlError("Fetch ST_MMS_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ST_MMS_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 41;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )635;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ACC_MMS_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);
		strcpy(p->sEndTime,		pSource->asEndTime[iCurPos]);
		strcpy(p->sCallingNumber,	pSource->asCallingNumber[iCurPos]);
		strcpy(p->sCalledNumber,	pSource->asCalledNumber[iCurPos]);
		strcpy(p->sOperationTypeID,	pSource->asOperationTypeID[iCurPos]);

		p->iCityID=			pSource->aiCityID[iCurPos];

		strcpy(p->sIsFree,		pSource->asIsFree[iCurPos]);
		strcpy(p->sRateUnitType,	pSource->asRateUnitType[iCurPos]);
		strcpy(p->sRateUnits,		pSource->asRateUnits[iCurPos]);

		p->iBillCycleSeq=		pSource->aiBillCycleSeq[iCurPos];

		strcpy(p->sExceptionType,	pSource->asExceptionType[iCurPos]);
		strcpy(p->sProvinceID,		pSource->asProvinceID[iCurPos]);
		strcpy(p->sCallingGroupID,	pSource->asCallingGroupID[iCurPos]);
		strcpy(p->sCalledGroupID,	pSource->asCalledGroupID[iCurPos]);
		strcpy(p->sCallingCompanyID,	pSource->asCallingCompanyID[iCurPos]);
		strcpy(p->sCalledCompanyID,	pSource->asCalledCompanyID[iCurPos]);
		strcpy(p->sStlObject,		pSource->asStlObject[iCurPos]);
		strcpy(p->sStlAmount,		pSource->asStlAmount[iCurPos]);
		strcpy(p->sCallingAreaCode,	pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCalledAreaCode,	pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sStlDirection,	pSource->asStlDirection[iCurPos]);
		strcpy(p->sUpGw,		pSource->asUpGw[iCurPos]);
		strcpy(p->sDownGw,		pSource->asDownGw[iCurPos]);
		strcpy(p->sUpgwGroupID,		pSource->asUpgwGroupID[iCurPos]);
		strcpy(p->sDownGwGroupID,	pSource->asDownGwGroupID[iCurPos]);
		strcpy(p->sUpCompanyID,		pSource->asUpCompanyID[iCurPos]);
		strcpy(p->sDownCompanyID,	pSource->asDownCompanyID[iCurPos]);
		strcpy(p->sUsageEventID,	pSource->asUsageEventID[iCurPos]);
		strcpy(p->sCallingCityCode,	pSource->asCallingCityCode[iCurPos]);
		strcpy(p->sCalledCityCode,	pSource->asCalledCityCode[iCurPos]);
		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sGroupID,		pSource->asGroupID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);

		AllTrim(p->sProdID);
		AllTrim(p->sStartTime);
		AllTrim(p->sEndTime);
		AllTrim(p->sCallingNumber);
		AllTrim(p->sCalledNumber);
		AllTrim(p->sOperationTypeID);
		AllTrim(p->sIsFree);
		AllTrim(p->sRateUnitType);
		AllTrim(p->sRateUnits);
		AllTrim(p->sExceptionType);
		AllTrim(p->sProvinceID);
		AllTrim(p->sCallingGroupID);
		AllTrim(p->sCalledGroupID);
		AllTrim(p->sCallingCompanyID);
		AllTrim(p->sCalledCompanyID);
		AllTrim(p->sStlObject);
		AllTrim(p->sStlAmount);
		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sStlDirection);
		AllTrim(p->sUpGw);
		AllTrim(p->sDownGw);
		AllTrim(p->sUpgwGroupID);
		AllTrim(p->sDownGwGroupID);
		AllTrim(p->sUpCompanyID);
		AllTrim(p->sDownCompanyID);
		AllTrim(p->sUsageEventID);
		AllTrim(p->sCallingCityCode);
		AllTrim(p->sCalledCityCode);
		AllTrim(p->sFileName);
		AllTrim(p->sGroupID);
		AllTrim(p->sCallType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据动态从ST_ODS_DR_G中用结构缓冲方式取数据*/
int EGetOdsSttTicketToStruct(struct OdsSttTicketStruct *p,
	struct OdsSttTicketStructIn *pSource)
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
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(CALL_TYPE,0),\n\
				nvl(SERVICE_NUM1,' '),\n\
				nvl(SERVICE_NUMR,' '),\n\
				nvl(SUBSCRIPTION_ID,0),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(OPP_NET_TYPE,0),\n\
				nvl(OPP_NUM_TYPE,0),\n\
				nvl(START_TIME,' '),\n\
				nvl(CALL_DURATION,0),\n\
				nvl(THIRD_PARTY,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ST_ODS_DR_GSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )650;
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


		CheckSqlError(" PREPARE ST_ODS_DR_GSCR ST_ODS_DR_GCR");

		/* EXEC SQL DECLARE ST_ODS_DR_GCR CURSOR FOR ST_ODS_DR_GSCR; */ 

		CheckSqlError("Declare ST_ODS_DR_GCR");

		/* EXEC SQL OPEN ST_ODS_DR_GCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )669;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ST_ODS_DR_GCR;");


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

		/* EXEC SQL CLOSE ST_ODS_DR_GCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )684;
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
		/* EXEC SQL FETCH ST_ODS_DR_GCR INTO
			:pSource->asUsageEventID,
			:pSource->asVisitAreaCode,
			:pSource->aiCallType,
			:pSource->asServiceNum1,
			:pSource->asServiceNumr,
			:pSource->aiSubscriptionID,
			:pSource->asHomeAreaCode,
			:pSource->asOtherParty,
			:pSource->asOppAreaCode,
			:pSource->aiOppNetType,
			:pSource->aiOppNumType,
			:pSource->asStartTime,
			:pSource->aiCallDuration,
			:pSource->asThirdParty; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )699;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asVisitAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiCallType);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asServiceNum1);
  sqlstm.sqhstl[3] = (unsigned long )41;
  sqlstm.sqhsts[3] = (         int  )41;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asServiceNumr);
  sqlstm.sqhstl[4] = (unsigned long )41;
  sqlstm.sqhsts[4] = (         int  )41;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiSubscriptionID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[6] = (unsigned long )11;
  sqlstm.sqhsts[6] = (         int  )11;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[7] = (unsigned long )41;
  sqlstm.sqhsts[7] = (         int  )41;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[8] = (unsigned long )11;
  sqlstm.sqhsts[8] = (         int  )11;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiOppNetType);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiOppNumType);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiCallDuration);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asThirdParty);
  sqlstm.sqhstl[13] = (unsigned long )41;
  sqlstm.sqhsts[13] = (         int  )41;
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


		CheckSqlError("Fetch ST_ODS_DR_GCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ST_ODS_DR_GCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 41;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )770;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ODS_STT_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sUsageEventID,	pSource->asUsageEventID[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);

		p->iCallType=			pSource->aiCallType[iCurPos];

		strcpy(p->sServiceNum1,		pSource->asServiceNum1[iCurPos]);
		strcpy(p->sServiceNumr,		pSource->asServiceNumr[iCurPos]);

		p->iSubscriptionID=		pSource->aiSubscriptionID[iCurPos];

		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);

		p->iOppNetType=			pSource->aiOppNetType[iCurPos];
		p->iOppNumType=			pSource->aiOppNumType[iCurPos];

		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);

		p->iCallDuration=		pSource->aiCallDuration[iCurPos];
		
		strcpy(p->sThirdParty,		pSource->asThirdParty[iCurPos]);
		
		AllTrim(p->sUsageEventID);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sServiceNum1);
		AllTrim(p->sServiceNumr);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sStartTime);
		AllTrim(p->sThirdParty);
	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据动态从ST_PREP_TICKET中用结构缓冲方式取数据*/
int EGetStPrepTicketToStruct(struct StPrepTicketStruct *p,
	struct StPrepTicketStructIn *pSource)
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
				nvl(SOURCE_ID,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(MSISDN,' '),\n\
				nvl(SETT_CITY,' '),\n\
				nvl(OPP_AREA_CODE,' '),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(END_TIME,' '),\n\
				nvl(DURATION,0),\n\
				nvl(AUDIT_TYPE,' '),\n\
				nvl(GROUP_ID,' '),\n\
				nvl(THIRD_PARTY,' '),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ST_PREP_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )785;
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


		CheckSqlError(" PREPARE ST_PREP_TICKETSCR ST_PREP_TICKETCR");

		/* EXEC SQL DECLARE ST_PREP_TICKETCR CURSOR FOR ST_PREP_TICKETSCR; */ 

		CheckSqlError("Declare ST_PREP_TICKETCR");

		/* EXEC SQL OPEN ST_PREP_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )804;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ST_PREP_TICKETCR;");


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

		/* EXEC SQL CLOSE ST_PREP_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )819;
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
		/* EXEC SQL FETCH ST_PREP_TICKETCR INTO
			:pSource->asUsageEventID,
			:pSource->asSourceID,
			:pSource->asHomeAreaCode,
			:pSource->asMsisdn,
			:pSource->asSettCity,
			:pSource->asOppAreaCode,
			:pSource->asOtherParty,
			:pSource->asCallType,
			:pSource->asStartTime,
			:pSource->asEndTime,
			:pSource->aiDuration,
			:pSource->asAuditType,
			:pSource->asGroupId,
			:pSource->asThirdParty,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )834;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )7;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )7;
  sqlstm.sqhsts[2] = (         int  )7;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asMsisdn);
  sqlstm.sqhstl[3] = (unsigned long )31;
  sqlstm.sqhsts[3] = (         int  )31;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asSettCity);
  sqlstm.sqhstl[4] = (unsigned long )7;
  sqlstm.sqhsts[4] = (         int  )7;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )7;
  sqlstm.sqhsts[5] = (         int  )7;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )31;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[7] = (unsigned long )3;
  sqlstm.sqhsts[7] = (         int  )3;
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
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asEndTime);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
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
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asAuditType);
  sqlstm.sqhstl[11] = (unsigned long )3;
  sqlstm.sqhsts[11] = (         int  )3;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asGroupId);
  sqlstm.sqhstl[12] = (unsigned long )3;
  sqlstm.sqhsts[12] = (         int  )3;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asThirdParty);
  sqlstm.sqhstl[13] = (unsigned long )31;
  sqlstm.sqhsts[13] = (         int  )31;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[14] = (unsigned long )19;
  sqlstm.sqhsts[14] = (         int  )19;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
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


		CheckSqlError("Fetch ST_STT_PREP_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ST_PREP_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 41;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )909;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ST_PREP_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sUsageEventID,	pSource->asUsageEventID[iCurPos]);
		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sMsisdn,		pSource->asMsisdn[iCurPos]);
		strcpy(p->sSettCity,		pSource->asSettCity[iCurPos]);
		strcpy(p->sOppAreaCode,		pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);
		strcpy(p->sEndTime,		pSource->asEndTime[iCurPos]);

		p->iDuration=			pSource->aiDuration[iCurPos];

		strcpy(p->sAuditType,		pSource->asAuditType[iCurPos]);
		strcpy(p->sGroupId,		pSource->asGroupId[iCurPos]);
		strcpy(p->sThirdParty,		pSource->asThirdParty[iCurPos]);
		strcpy(p->sRowID,		pSource->asRowID[iCurPos]);

		AllTrim(p->sUsageEventID);
		AllTrim(p->sSourceID);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sMsisdn);
		AllTrim(p->sSettCity);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sCallType);
		AllTrim(p->sStartTime);
		AllTrim(p->sEndTime);
		AllTrim(p->sAuditType);
		AllTrim(p->sGroupId);
		AllTrim(p->sRowID);
		AllTrim(p->sThirdParty);
	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入ST_PREP_TICKET*/
int EInsertStructToStPrepTicket(struct StPrepTicketStruct *p,
	int iInsertFlag,struct StPrepTicketStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asUsageEventID[iCurPos],	p->sUsageEventID);
		strcpy(pTarget->asSourceID[iCurPos],		p->sSourceID);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asMsisdn[iCurPos],		p->sMsisdn);
		strcpy(pTarget->asSettCity[iCurPos],		p->sSettCity);
		strcpy(pTarget->asOppAreaCode[iCurPos],		p->sOppAreaCode);
		strcpy(pTarget->asOtherParty[iCurPos],		p->sOtherParty);
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asStartTime[iCurPos],		p->sStartTime);
		strcpy(pTarget->asEndTime[iCurPos],		p->sEndTime);

		pTarget->aiDuration[iCurPos]=			p->iDuration;

		strcpy(pTarget->asAuditType[iCurPos],		p->sAuditType);
		strcpy(pTarget->asGroupId[iCurPos],		p->sGroupId);
		strcpy(pTarget->asThirdParty[iCurPos],		p->sThirdParty);
		
		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==ST_PREP_TICKET_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				USAGE_EVENT_ID,\n\
				SOURCE_ID,\n\
				HOME_AREA_CODE,\n\
				MSISDN,\n\
				SETT_CITY,\n\
				OPP_AREA_CODE,\n\
				OTHER_PARTY,\n\
				CALL_TYPE,\n\
				START_TIME,\n\
				END_TIME,\n\
				DURATION,\n\
				AUDIT_TYPE,\n\
				GROUP_ID,\n\
				THIRD_PARTY)\n\
			VALUES (\n\
				:asUsageEventID,\n\
				:asSourceID,\n\
				:asHomeAreaCode,\n\
				:asMsisdn,\n\
				:asSettCity,\n\
				:asOppAreaCode,\n\
				:asOtherParty,\n\
				:asCallType,\n\
				:asStartTime,\n\
				:asEndTime,\n\
				:aiDuration,\n\
				:asAuditType,\n\
				:asGroupId,\n\
				:asThirdParty\n\
			)",sTableName);

		/* EXEC SQL PREPARE ST_STT_PREP_TICKETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )924;
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


		if(CheckSqlResult("Prepare insert statement ST_STT_PREP_TICKET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE ST_STT_PREP_TICKETTRG USING
				:pTarget->asUsageEventID,
				:pTarget->asSourceID,
				:pTarget->asHomeAreaCode,
				:pTarget->asMsisdn,
				:pTarget->asSettCity,
				:pTarget->asOppAreaCode,
				:pTarget->asOtherParty,
				:pTarget->asCallType,
				:pTarget->asStartTime,
				:pTarget->asEndTime,
				:pTarget->aiDuration,
				:pTarget->asAuditType,
				:pTarget->asGroupId,
				:pTarget->asThirdParty; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )943;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asUsageEventID);
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )19;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )7;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asHomeAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )7;
  sqlstm.sqhsts[2] = (         int  )7;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asMsisdn);
  sqlstm.sqhstl[3] = (unsigned long )31;
  sqlstm.sqhsts[3] = (         int  )31;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asSettCity);
  sqlstm.sqhstl[4] = (unsigned long )7;
  sqlstm.sqhsts[4] = (         int  )7;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asOppAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )7;
  sqlstm.sqhsts[5] = (         int  )7;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asOtherParty);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )31;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[7] = (unsigned long )3;
  sqlstm.sqhsts[7] = (         int  )3;
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
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asEndTime);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
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
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asAuditType);
  sqlstm.sqhstl[11] = (unsigned long )3;
  sqlstm.sqhsts[11] = (         int  )3;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asGroupId);
  sqlstm.sqhstl[12] = (unsigned long )3;
  sqlstm.sqhsts[12] = (         int  )3;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asThirdParty);
  sqlstm.sqhstl[13] = (unsigned long )31;
  sqlstm.sqhsts[13] = (         int  )31;
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


		if(CheckSqlResult("Dyn insert into ST_STT_PREP_TICKET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

int EUpdateStructToStPrepTicket(struct StPrepTicketStruct *p,
	int iUpdateFlag,struct StPrepTicketStructUp *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;


	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		
		strcpy(pTarget->asAuditType[iCurPos],		p->sAuditType);
		strcpy(pTarget->asRowID[iCurPos],		p->sRowID);

		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==ST_PREP_TICKET_UP){

/* INSERT */
		char statement[4096];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s\n\
			SET \n\
				AUDIT_TYPE=		:asAuditType\n\
			WHERE \n\
				ROWID = chartorowid(:asRowID)\n\
			",sTableName);

		/* EXEC SQL PREPARE ST_TICKET_PREP_UPUCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1014;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)statement;
  sqlstm.sqhstl[0] = (unsigned long )4096;
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


		if(CheckSqlResult("Prepare update statement ST_TICKET_PREP_UP")<0)
			return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE ST_TICKET_PREP_UPUCR USING
				:pTarget->asAuditType,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1033;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asAuditType);
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


		if(CheckSqlResult("Dyn update ST_TICKET_PREP_UP")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

void mvitem_fmstprepticket(struct FStPrepTicketStruct *pi,struct StPrepTicketStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];
	char sStartTime[14];
	int iLen;
	bzero((void*)po,sizeof(struct StPrepTicketStruct));

		strncpy(po->sUsageEventID,	pi->sUsageEventID,18);
		strncpy(po->sSourceID,		pi->sSourceID,6);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,6);
		strncpy(po->sMsisdn,		pi->sMsisdn,30);
		strncpy(po->sSettCity,		pi->sSettCity,6);
		strncpy(po->sOppAreaCode,	pi->sOppAreaCode,6);
		strncpy(po->sOtherParty,	pi->sOtherParty,30);
		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sEndTime,		pi->sEndTime,14);

		strncpy(sTemp,		pi->sDuration,8);sTemp[8]=0;
		po->iDuration=atoi(sTemp);

		strncpy(po->sAuditType,		pi->sAuditType,2);
		AllTrim(po->sMsisdn);
		iLen = strlen(po->sMsisdn);
		if(po->sMsisdn[iLen-2] >= '0' && po->sMsisdn[iLen-2] <= '9' &&
			po->sMsisdn[iLen-1] >= '0' && po->sMsisdn[iLen-1] <= '9'){
			po->sGroupId[0] = po->sMsisdn[iLen-2];
			po->sGroupId[1] = po->sMsisdn[iLen-1];
		}
		else
			strcpy(po->sGroupId, "00");
		
		strncpy(po->sThirdParty,	pi->sThirdParty,30);
		
		strncpy(sStartTime, pi->sStartTime,14);
		AllTrim(po->sEndTime);
		if(strcmp(po->sEndTime, "") == 0){
			AddTimes(sStartTime, po->iDuration);
			strncpy(po->sEndTime, sStartTime,14);
		}
		AllTrim(po->sUsageEventID);
		AllTrim(po->sSourceID);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sMsisdn);
		AllTrim(po->sSettCity);
		AllTrim(po->sOppAreaCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sCallType);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sAuditType);
		AllTrim(po->sGroupId);
		AllTrim(po->sThirdParty);
}


void CreateTable(char tablename[])
{
	char dropment[8192];
	char createment[8192];

	sprintf(dropment, "DROP TABLE %s",tablename);
	sprintf(createment, "CREATE TABLE %s AS SELECT * FROM ST_PREP_TICKET",tablename);
	/* EXEC SQL PREPARE ST_STT_PREP_TICKETTRG FROM :dropment; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1056;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)dropment;
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


	/* EXEC SQL PREPARE ST_STT_PREP_TICKETTRG FROM :createment; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1075;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)createment;
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


}

