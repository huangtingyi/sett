
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
650,0,0,4,0,0,17,724,0,0,1,1,0,1,0,1,97,0,0,
669,0,0,4,0,0,45,730,0,0,0,0,0,1,0,
684,0,0,4,0,0,15,747,0,0,0,0,0,1,0,
699,0,0,4,0,0,13,755,0,0,17,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,
782,0,0,4,0,0,15,785,0,0,0,0,0,1,0,
797,0,0,5,0,0,17,880,0,0,1,1,0,1,0,1,97,0,0,
816,0,0,5,0,0,45,886,0,0,0,0,0,1,0,
831,0,0,5,0,0,15,903,0,0,0,0,0,1,0,
846,0,0,5,0,0,13,911,0,0,16,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
925,0,0,5,0,0,15,940,0,0,0,0,0,1,0,
940,0,0,6,0,0,17,1066,0,0,1,1,0,1,0,1,97,0,0,
959,0,0,6,0,0,45,1072,0,0,0,0,0,1,0,
974,0,0,6,0,0,15,1089,0,0,0,0,0,1,0,
989,0,0,6,0,0,13,1097,0,0,51,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1208,0,0,6,0,0,15,1161,0,0,0,0,0,1,0,
1223,0,0,7,0,0,17,1356,0,0,1,1,0,1,0,1,97,0,0,
1242,0,0,7,0,0,21,1359,0,0,18,18,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1329,0,0,8,0,0,17,1422,0,0,1,1,0,1,0,1,97,0,0,
1348,0,0,8,0,0,21,1426,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
1375,0,0,7,0,0,17,1506,0,0,1,1,0,1,0,1,97,0,0,
1394,0,0,7,0,0,17,1507,0,0,1,1,0,1,0,1,97,0,0,
1413,0,0,9,0,0,17,1533,0,0,1,1,0,1,0,1,97,0,0,
1432,0,0,9,0,0,45,1539,0,0,0,0,0,1,0,
1447,0,0,9,0,0,15,1556,0,0,0,0,0,1,0,
1462,0,0,9,0,0,13,1564,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
1493,0,0,9,0,0,15,1581,0,0,0,0,0,1,0,
1508,0,0,10,0,0,17,1747,0,0,1,1,0,1,0,1,97,0,0,
1527,0,0,10,0,0,21,1750,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
1554,0,0,11,0,0,17,1832,0,0,1,1,0,1,0,1,97,0,0,
1573,0,0,11,0,0,45,1838,0,0,0,0,0,1,0,
1588,0,0,11,0,0,15,1855,0,0,0,0,0,1,0,
1603,0,0,11,0,0,13,1863,0,0,51,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1822,0,0,11,0,0,15,1927,0,0,0,0,0,1,0,
1837,0,0,12,0,0,17,2122,0,0,1,1,0,1,0,1,97,0,0,
1856,0,0,12,0,0,45,2128,0,0,0,0,0,1,0,
1871,0,0,12,0,0,15,2145,0,0,0,0,0,1,0,
1886,0,0,12,0,0,13,2153,0,0,63,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2153,0,0,12,0,0,15,2229,0,0,0,0,0,1,0,
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
				nvl(USAGE_SEQ,' '),\n\
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
			:pSource->asUsageSeq,
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
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asUsageSeq);
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
		strcpy(p->sUsageSeq,		pSource->asUsageSeq[iCurPos]);
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

		AllTrim(p->sUsageSeq);
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
				to_char(nvl(USAGE_SEQ,0)),\n\
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
			:pSource->asUsageSeq,
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
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->asUsageSeq);
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
		strcpy(p->sUsageSeq,	pSource->asUsageSeq[iCurPos]);
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
		AllTrim(p->sUsageSeq);
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
				nvl(THIRD_PARTY,' '),\n\
				nvl(DATAFILE_DAY,' '),\n\
				nvl(TRUNK_GROUPOUT,' '),\n\
				nvl(ORIGINAL_FILE,' ')\n\
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
			:pSource->asThirdParty,
			:pSource->asDataFileDay,
			:pSource->asTrunkGroupout,
			:pSource->asOriginalFile; */ 

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
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asDataFileDay);
  sqlstm.sqhstl[14] = (unsigned long )9;
  sqlstm.sqhsts[14] = (         int  )9;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asTrunkGroupout);
  sqlstm.sqhstl[15] = (unsigned long )25;
  sqlstm.sqhsts[15] = (         int  )25;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asOriginalFile);
  sqlstm.sqhstl[16] = (unsigned long )81;
  sqlstm.sqhsts[16] = (         int  )81;
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
   sqlstm.offset = (unsigned int  )782;
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
		strcpy(p->sDataFileDay,		pSource->asDataFileDay[iCurPos]);
		strcpy(p->sTrunkGroupout,		pSource->asTrunkGroupout[iCurPos]);
		strcpy(p->sOriginalFile,		pSource->asOriginalFile[iCurPos]);
		
		AllTrim(p->sUsageEventID);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sServiceNum1);
		AllTrim(p->sServiceNumr);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sOtherParty);
		AllTrim(p->sOppAreaCode);
		AllTrim(p->sStartTime);
		AllTrim(p->sThirdParty);
		AllTrim(p->sDataFileDay);
		AllTrim(p->sTrunkGroupout);
		AllTrim(p->sOriginalFile);
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
				nvl(DATAFILE_DAY,' '),\n\
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
  sqlstm.offset = (unsigned int  )797;
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
  sqlstm.offset = (unsigned int  )816;
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
  sqlstm.offset = (unsigned int  )831;
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
			:pSource->asDataFileDay,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )846;
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
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asDataFileDay);
  sqlstm.sqhstl[14] = (unsigned long )9;
  sqlstm.sqhsts[14] = (         int  )9;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[15] = (unsigned long )19;
  sqlstm.sqhsts[15] = (         int  )19;
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
   sqlstm.offset = (unsigned int  )925;
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
		strcpy(p->sDataFileDay,		pSource->asDataFileDay[iCurPos]);
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
		AllTrim(p->sDataFileDay);
	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据动态从ST_ODS_SM_G_201410中用结构缓冲方式取数据*/
int EGetOdsSmsTicketToStruct(struct OdsSmsTicketStruct *p,
	struct OdsSmsTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SERVICE_ID,0),\n\
				nvl(BILL_NUMBER,' '),\n\
				nvl(CALL_TYPE,0),\n\
				nvl(HOME_AREA,' '),\n\
				to_char(nvl(START_TIME,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(OPP_NUMBER,' '),\n\
				nvl(SP_CODE,' '),\n\
				nvl(SP_SMG,' '),\n\
				nvl(ACCESS_CODE,' '),\n\
				nvl(SERVICE_CODE,' '),\n\
				nvl(LANG_TYPE,' '),\n\
				nvl(SV_TYPE,0),\n\
				nvl(SVC_EX,' '),\n\
				to_char(nvl(SM_TYPE,0)),\n\
				nvl(MSG_LENGTH,0),\n\
				nvl(END_REASON,0),\n\
				nvl(NICE,0),\n\
				nvl(SMG_CODE,' '),\n\
				nvl(USER_TYPE,0),\n\
				nvl(CFEE1,0),\n\
				nvl(AFEE1,0),\n\
				nvl(SERVICE_NUMR,' '),\n\
				nvl(PART_ID,0),\n\
				nvl(ACCOUNT_ID,0),\n\
				nvl(SUBSCRIPTION_ID,0),\n\
				nvl(SVC_TYPE,0),\n\
				nvl(REGION_ID,' '),\n\
				nvl(USAGE_TYPE,0),\n\
				nvl(USAGE_CASE,0),\n\
				nvl(USAGE_CLASS,0),\n\
				nvl(CLASS_OF_SERVICE_CODE,0),\n\
				nvl(CFEE,0),\n\
				nvl(LFEE,0),\n\
				nvl(IFEE,0),\n\
				nvl(DIS_CFEE,0),\n\
				nvl(DIS_LFEE,0),\n\
				nvl(DIS_IFEE,0),\n\
				nvl(CFEE_TIMES,0),\n\
				nvl(LFEE_TIMES,0),\n\
				nvl(IFEE_TIMES,0),\n\
				nvl(PACKAGE_ID,0),\n\
				nvl(PRODUCT_CLASS,0),\n\
				nvl(ORIGINAL_FILE,' '),\n\
				nvl(LATE_LINK,0),\n\
				to_char(nvl(CAL_TIME,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(AUDI_STR,' '),\n\
				nvl(VARIAN_STR,' '),\n\
				to_char(nvl(TIMESTAMP,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(DATAFILE_DAY,' '),\n\
				nvl(INSTORAGE_DAY,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ODS_SMS_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )940;
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


		CheckSqlError(" PREPARE ODS_SMS_TICKETSCR ODS_SMS_TICKETCR");

		/* EXEC SQL DECLARE ODS_SMS_TICKETCR CURSOR FOR ODS_SMS_TICKETSCR; */ 

		CheckSqlError("Declare ODS_SMS_TICKETCR");

		/* EXEC SQL OPEN ODS_SMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )959;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ODS_SMS_TICKETCR;");


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

		/* EXEC SQL CLOSE ODS_SMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )974;
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
		/* EXEC SQL FETCH ODS_SMS_TICKETCR INTO
			:pSource->aiServiceID,
			:pSource->asBillNumber,
			:pSource->aiCallType,
			:pSource->asHomeArea,
			:pSource->asStartTime,
			:pSource->asOtherParty,
			:pSource->asOppNumber,
			:pSource->asSpCode,
			:pSource->asSpSmg,
			:pSource->asAccessCode,
			:pSource->asServiceCode,
			:pSource->asLangType,
			:pSource->aiSvType,
			:pSource->asSvcEx,
			:pSource->asSmType,
			:pSource->aiMsgLength,
			:pSource->aiEndReason,
			:pSource->aiNice,
			:pSource->asSmgCode,
			:pSource->aiUserType,
			:pSource->aiCfee1,
			:pSource->aiAfee1,
			:pSource->asServiceNumr,
			:pSource->aiPartID,
			:pSource->aiAccountID,
			:pSource->aiSubscriptionID,
			:pSource->aiSvcType,
			:pSource->asRegionID,
			:pSource->aiUsageType,
			:pSource->aiUsageCase,
			:pSource->aiUsageClass,
			:pSource->aiClassOfServiceCode,
			:pSource->aiCfee,
			:pSource->aiLfee,
			:pSource->aiIfee,
			:pSource->aiDisCfee,
			:pSource->aiDisLfee,
			:pSource->aiDisIfee,
			:pSource->aiCfeeTimes,
			:pSource->aiLfeeTimes,
			:pSource->aiIfeeTimes,
			:pSource->aiPackageID,
			:pSource->aiProductClass,
			:pSource->asOriginalFile,
			:pSource->aiLateLink,
			:pSource->asCalTime,
			:pSource->asAudiStr,
			:pSource->asVarianStr,
			:pSource->asTimestamp,
			:pSource->asDatafileDay,
			:pSource->asInstorageDay; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )989;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiServiceID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asBillNumber);
  sqlstm.sqhstl[1] = (unsigned long )41;
  sqlstm.sqhsts[1] = (         int  )41;
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
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asHomeArea);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )41;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asOppNumber);
  sqlstm.sqhstl[6] = (unsigned long )41;
  sqlstm.sqhsts[6] = (         int  )41;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSpCode);
  sqlstm.sqhstl[7] = (unsigned long )7;
  sqlstm.sqhsts[7] = (         int  )7;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSpSmg);
  sqlstm.sqhstl[8] = (unsigned long )7;
  sqlstm.sqhsts[8] = (         int  )7;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asAccessCode);
  sqlstm.sqhstl[9] = (unsigned long )21;
  sqlstm.sqhsts[9] = (         int  )21;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asServiceCode);
  sqlstm.sqhstl[10] = (unsigned long )31;
  sqlstm.sqhsts[10] = (         int  )31;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asLangType);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiSvType);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asSvcEx);
  sqlstm.sqhstl[13] = (unsigned long )7;
  sqlstm.sqhsts[13] = (         int  )7;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asSmType);
  sqlstm.sqhstl[14] = (unsigned long )16;
  sqlstm.sqhsts[14] = (         int  )16;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->aiMsgLength);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->aiEndReason);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )sizeof(int);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->aiNice);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )sizeof(int);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asSmgCode);
  sqlstm.sqhstl[18] = (unsigned long )9;
  sqlstm.sqhsts[18] = (         int  )9;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->aiUserType);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(int);
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->aiCfee1);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->aiAfee1);
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )sizeof(int);
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asServiceNumr);
  sqlstm.sqhstl[22] = (unsigned long )41;
  sqlstm.sqhsts[22] = (         int  )41;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->aiPartID);
  sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[23] = (         int  )sizeof(int);
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->aiAccountID);
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )sizeof(int);
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->aiSubscriptionID);
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )sizeof(int);
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->aiSvcType);
  sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[26] = (         int  )sizeof(int);
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asRegionID);
  sqlstm.sqhstl[27] = (unsigned long )2;
  sqlstm.sqhsts[27] = (         int  )2;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->aiUsageType);
  sqlstm.sqhstl[28] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[28] = (         int  )sizeof(int);
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pSource->aiUsageCase);
  sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[29] = (         int  )sizeof(int);
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pSource->aiUsageClass);
  sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[30] = (         int  )sizeof(int);
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pSource->aiClassOfServiceCode);
  sqlstm.sqhstl[31] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[31] = (         int  )sizeof(int);
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pSource->aiCfee);
  sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[32] = (         int  )sizeof(int);
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pSource->aiLfee);
  sqlstm.sqhstl[33] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[33] = (         int  )sizeof(int);
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pSource->aiIfee);
  sqlstm.sqhstl[34] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[34] = (         int  )sizeof(int);
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pSource->aiDisCfee);
  sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[35] = (         int  )sizeof(int);
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pSource->aiDisLfee);
  sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[36] = (         int  )sizeof(int);
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pSource->aiDisIfee);
  sqlstm.sqhstl[37] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[37] = (         int  )sizeof(int);
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pSource->aiCfeeTimes);
  sqlstm.sqhstl[38] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[38] = (         int  )sizeof(int);
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pSource->aiLfeeTimes);
  sqlstm.sqhstl[39] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[39] = (         int  )sizeof(int);
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pSource->aiIfeeTimes);
  sqlstm.sqhstl[40] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[40] = (         int  )sizeof(int);
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pSource->aiPackageID);
  sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[41] = (         int  )sizeof(int);
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pSource->aiProductClass);
  sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[42] = (         int  )sizeof(int);
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqharc[42] = (unsigned long  *)0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)(pSource->asOriginalFile);
  sqlstm.sqhstl[43] = (unsigned long )81;
  sqlstm.sqhsts[43] = (         int  )81;
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqharc[43] = (unsigned long  *)0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
  sqlstm.sqhstv[44] = (unsigned char  *)(pSource->aiLateLink);
  sqlstm.sqhstl[44] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[44] = (         int  )sizeof(int);
  sqlstm.sqindv[44] = (         short *)0;
  sqlstm.sqinds[44] = (         int  )0;
  sqlstm.sqharm[44] = (unsigned long )0;
  sqlstm.sqharc[44] = (unsigned long  *)0;
  sqlstm.sqadto[44] = (unsigned short )0;
  sqlstm.sqtdso[44] = (unsigned short )0;
  sqlstm.sqhstv[45] = (unsigned char  *)(pSource->asCalTime);
  sqlstm.sqhstl[45] = (unsigned long )15;
  sqlstm.sqhsts[45] = (         int  )15;
  sqlstm.sqindv[45] = (         short *)0;
  sqlstm.sqinds[45] = (         int  )0;
  sqlstm.sqharm[45] = (unsigned long )0;
  sqlstm.sqharc[45] = (unsigned long  *)0;
  sqlstm.sqadto[45] = (unsigned short )0;
  sqlstm.sqtdso[45] = (unsigned short )0;
  sqlstm.sqhstv[46] = (unsigned char  *)(pSource->asAudiStr);
  sqlstm.sqhstl[46] = (unsigned long )2049;
  sqlstm.sqhsts[46] = (         int  )2049;
  sqlstm.sqindv[46] = (         short *)0;
  sqlstm.sqinds[46] = (         int  )0;
  sqlstm.sqharm[46] = (unsigned long )0;
  sqlstm.sqharc[46] = (unsigned long  *)0;
  sqlstm.sqadto[46] = (unsigned short )0;
  sqlstm.sqtdso[46] = (unsigned short )0;
  sqlstm.sqhstv[47] = (unsigned char  *)(pSource->asVarianStr);
  sqlstm.sqhstl[47] = (unsigned long )256;
  sqlstm.sqhsts[47] = (         int  )256;
  sqlstm.sqindv[47] = (         short *)0;
  sqlstm.sqinds[47] = (         int  )0;
  sqlstm.sqharm[47] = (unsigned long )0;
  sqlstm.sqharc[47] = (unsigned long  *)0;
  sqlstm.sqadto[47] = (unsigned short )0;
  sqlstm.sqtdso[47] = (unsigned short )0;
  sqlstm.sqhstv[48] = (unsigned char  *)(pSource->asTimestamp);
  sqlstm.sqhstl[48] = (unsigned long )15;
  sqlstm.sqhsts[48] = (         int  )15;
  sqlstm.sqindv[48] = (         short *)0;
  sqlstm.sqinds[48] = (         int  )0;
  sqlstm.sqharm[48] = (unsigned long )0;
  sqlstm.sqharc[48] = (unsigned long  *)0;
  sqlstm.sqadto[48] = (unsigned short )0;
  sqlstm.sqtdso[48] = (unsigned short )0;
  sqlstm.sqhstv[49] = (unsigned char  *)(pSource->asDatafileDay);
  sqlstm.sqhstl[49] = (unsigned long )9;
  sqlstm.sqhsts[49] = (         int  )9;
  sqlstm.sqindv[49] = (         short *)0;
  sqlstm.sqinds[49] = (         int  )0;
  sqlstm.sqharm[49] = (unsigned long )0;
  sqlstm.sqharc[49] = (unsigned long  *)0;
  sqlstm.sqadto[49] = (unsigned short )0;
  sqlstm.sqtdso[49] = (unsigned short )0;
  sqlstm.sqhstv[50] = (unsigned char  *)(pSource->asInstorageDay);
  sqlstm.sqhstl[50] = (unsigned long )9;
  sqlstm.sqhsts[50] = (         int  )9;
  sqlstm.sqindv[50] = (         short *)0;
  sqlstm.sqinds[50] = (         int  )0;
  sqlstm.sqharm[50] = (unsigned long )0;
  sqlstm.sqharc[50] = (unsigned long  *)0;
  sqlstm.sqadto[50] = (unsigned short )0;
  sqlstm.sqtdso[50] = (unsigned short )0;
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


		CheckSqlError("Fetch ODS_SMS_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ODS_SMS_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 51;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1208;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ODS_SMS_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iServiceID=			pSource->aiServiceID[iCurPos];

		strcpy(p->sBillNumber,		pSource->asBillNumber[iCurPos]);

		p->iCallType=			pSource->aiCallType[iCurPos];

		strcpy(p->sHomeArea,		pSource->asHomeArea[iCurPos]);
		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sOppNumber,		pSource->asOppNumber[iCurPos]);
		strcpy(p->sSpCode,		pSource->asSpCode[iCurPos]);
		strcpy(p->sSpSmg,		pSource->asSpSmg[iCurPos]);
		strcpy(p->sAccessCode,		pSource->asAccessCode[iCurPos]);
		strcpy(p->sServiceCode,		pSource->asServiceCode[iCurPos]);
		strcpy(p->sLangType,		pSource->asLangType[iCurPos]);

		p->iSvType=			pSource->aiSvType[iCurPos];

		strcpy(p->sSvcEx,		pSource->asSvcEx[iCurPos]);
		strcpy(p->sSmType,		pSource->asSmType[iCurPos]);

		p->iMsgLength=			pSource->aiMsgLength[iCurPos];
		p->iEndReason=			pSource->aiEndReason[iCurPos];
		p->iNice=			pSource->aiNice[iCurPos];

		strcpy(p->sSmgCode,		pSource->asSmgCode[iCurPos]);

		p->iUserType=			pSource->aiUserType[iCurPos];
		p->iCfee1=			pSource->aiCfee1[iCurPos];
		p->iAfee1=			pSource->aiAfee1[iCurPos];

		strcpy(p->sServiceNumr,		pSource->asServiceNumr[iCurPos]);

		p->iPartID=			pSource->aiPartID[iCurPos];
		p->iAccountID=			pSource->aiAccountID[iCurPos];
		p->iSubscriptionID=		pSource->aiSubscriptionID[iCurPos];
		p->iSvcType=			pSource->aiSvcType[iCurPos];

		strcpy(p->sRegionID,		pSource->asRegionID[iCurPos]);

		p->iUsageType=			pSource->aiUsageType[iCurPos];
		p->iUsageCase=			pSource->aiUsageCase[iCurPos];
		p->iUsageClass=			pSource->aiUsageClass[iCurPos];
		p->iClassOfServiceCode=		pSource->aiClassOfServiceCode[iCurPos];
		p->iCfee=			pSource->aiCfee[iCurPos];
		p->iLfee=			pSource->aiLfee[iCurPos];
		p->iIfee=			pSource->aiIfee[iCurPos];
		p->iDisCfee=			pSource->aiDisCfee[iCurPos];
		p->iDisLfee=			pSource->aiDisLfee[iCurPos];
		p->iDisIfee=			pSource->aiDisIfee[iCurPos];
		p->iCfeeTimes=			pSource->aiCfeeTimes[iCurPos];
		p->iLfeeTimes=			pSource->aiLfeeTimes[iCurPos];
		p->iIfeeTimes=			pSource->aiIfeeTimes[iCurPos];
		p->iPackageID=			pSource->aiPackageID[iCurPos];
		p->iProductClass=		pSource->aiProductClass[iCurPos];

		strcpy(p->sOriginalFile,	pSource->asOriginalFile[iCurPos]);

		p->iLateLink=			pSource->aiLateLink[iCurPos];

		strcpy(p->sCalTime,		pSource->asCalTime[iCurPos]);
		strcpy(p->sAudiStr,		pSource->asAudiStr[iCurPos]);
		strcpy(p->sVarianStr,		pSource->asVarianStr[iCurPos]);
		strcpy(p->sTimestamp,		pSource->asTimestamp[iCurPos]);
		strcpy(p->sDatafileDay,		pSource->asDatafileDay[iCurPos]);
		strcpy(p->sInstorageDay,	pSource->asInstorageDay[iCurPos]);

		AllTrim(p->sBillNumber);
		AllTrim(p->sHomeArea);
		AllTrim(p->sStartTime);
		AllTrim(p->sOtherParty);
		AllTrim(p->sOppNumber);
		AllTrim(p->sSpCode);
		AllTrim(p->sSpSmg);
		AllTrim(p->sAccessCode);
		AllTrim(p->sServiceCode);
		AllTrim(p->sLangType);
		AllTrim(p->sSvcEx);
		AllTrim(p->sSmType);
		AllTrim(p->sSmgCode);
		AllTrim(p->sServiceNumr);
		AllTrim(p->sRegionID);
		AllTrim(p->sOriginalFile);
		AllTrim(p->sCalTime);
		AllTrim(p->sAudiStr);
		AllTrim(p->sVarianStr);
		AllTrim(p->sTimestamp);
		AllTrim(p->sDatafileDay);
		AllTrim(p->sInstorageDay);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/*批量数据结构缓冲写入ST_PREP_TICKET*/
int EInsertStructToStPrepTicket(struct StPrepTicketStruct *p,
	int iInsertFlag,struct StPrepTicketStructOut *pTarget,char *sSourceID)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asUsageEventID[iCurPos],	p->sUsageEventID);
		strcpy(pTarget->asSourceID[iCurPos],		sSourceID);
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
		strcpy(pTarget->asOppUsageEventID[iCurPos],	p->sOppUsageEventID);
		strcpy(pTarget->asDataFileDay[iCurPos],		p->sDataFileDay);
		strcpy(pTarget->asCalledMsisdn[iCurPos],		p->sCalledMsisdn);
		strcpy(pTarget->asFileName[iCurPos],		p->sFileName);

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
				THIRD_PARTY,\n\
				OPP_USAGE_EVENT_ID,\n\
				DATAFILE_DAY,\n\
				CALLED_MSISDN,\n\
				FILE_NAME)\n\
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
				:asThirdParty,\n\
				:asOppUsageEventID,\n\
				:asDataFileDay,\n\
				:asCalled_Msisdn,\n\
				:asFile_Name\n\
			)",sTableName);

		/* EXEC SQL PREPARE ST_STT_PREP_TICKETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1223;
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
				:pTarget->asThirdParty,
				:pTarget->asOppUsageEventID,
				:pTarget->asDataFileDay,
				:pTarget->asCalledMsisdn,
		        :pTarget->asFileName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1242;
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
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asOppUsageEventID);
  sqlstm.sqhstl[14] = (unsigned long )19;
  sqlstm.sqhsts[14] = (         int  )19;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asDataFileDay);
  sqlstm.sqhstl[15] = (unsigned long )9;
  sqlstm.sqhsts[15] = (         int  )9;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asCalledMsisdn);
  sqlstm.sqhstl[16] = (unsigned long )31;
  sqlstm.sqhsts[16] = (         int  )31;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[17] = (unsigned long )81;
  sqlstm.sqhsts[17] = (         int  )81;
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
		strcpy(pTarget->asOppUsageEventID[iCurPos],	p->sOppUsageEventID);
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
				AUDIT_TYPE=		:asAuditType,\n\
				OPP_USAGE_EVENT_ID=	:asOppUsageEventID\n\
			WHERE \n\
				ROWID = chartorowid(:asRowID)\n\
			",sTableName);

		/* EXEC SQL PREPARE ST_TICKET_PREP_UPUCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1329;
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
				:pTarget->asOppUsageEventID,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1348;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asOppUsageEventID);
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )19;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asRowID);
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )19;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
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
	memset((void*)po,0,sizeof(struct StPrepTicketStruct));

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
		strncpy(po->sDataFileDay,		pi->sDataFileDay,8);
		strncpy(po->sCalledMsisdn,		pi->sCalledMsisdn,30);
		strncpy(po->sFileName,		pi->sFileName,80);

		AllTrim(po->sUsageEventID);
		AllTrim(po->sSourceID);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sSettCity);
		AllTrim(po->sOppAreaCode);
		AllTrim(po->sOtherParty);
		AllTrim(po->sCallType);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sAuditType);
		AllTrim(po->sThirdParty);
		AllTrim(po->sDataFileDay);
		AllTrim(po->sCalledMsisdn);		
		AllTrim(po->sFileName);	
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
 sqlstm.arrsiz = 51;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1375;
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
 sqlstm.arrsiz = 51;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1394;
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


/*批量数据动态从ST_AREA_MSC_TIME_OFFSET中用结构缓冲方式取数据*/
int EGetStAreaMscTimeOffsetToStruct(struct StAreaMscTimeOffsetStruct *p,
	struct StAreaMscTimeOffsetStructIn *pSource)
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
				nvl(MSC,' '),\n\
				nvl(OFFSET,0),\n\
				nvl(HOME_AREA_CODE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ST_AREA_MSC_TIME_OFFSETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1413;
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


		CheckSqlError(" PREPARE ST_AREA_MSC_TIME_OFFSETSCR ST_AREA_MSC_TIME_OFFSETCR");

		/* EXEC SQL DECLARE ST_AREA_MSC_TIME_OFFSETCR CURSOR FOR ST_AREA_MSC_TIME_OFFSETSCR; */ 

		CheckSqlError("Declare ST_AREA_MSC_TIME_OFFSETCR");

		/* EXEC SQL OPEN ST_AREA_MSC_TIME_OFFSETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1432;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ST_AREA_MSC_TIME_OFFSETCR;");


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

		/* EXEC SQL CLOSE ST_AREA_MSC_TIME_OFFSETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1447;
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
		/* EXEC SQL FETCH ST_AREA_MSC_TIME_OFFSETCR INTO
			:pSource->asAreaCode,
			:pSource->asMsc,
			:pSource->aiOffset,
			:pSource->asHomeAreaCode; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1462;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[1] = (unsigned long )15;
  sqlstm.sqhsts[1] = (         int  )15;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiOffset);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asHomeAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )10;
  sqlstm.sqhsts[3] = (         int  )10;
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


		CheckSqlError("Fetch ST_AREA_MSC_TIME_OFFSETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ST_AREA_MSC_TIME_OFFSETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 51;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1493;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ST_AREA_MSC_TIME_OFFSET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAreaCode,		pSource->asAreaCode[iCurPos]);
		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);

		p->iOffset=			pSource->aiOffset[iCurPos];
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		
		AllTrim(p->sAreaCode);
		AllTrim(p->sMsc);
		AllTrim(p->sHomeAreaCode);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_stareamsctimeoffset(struct StAreaMscTimeOffsetStruct *pi,struct StAreaMscTimeOffsetStruct *po)
{/*数据移动部分*/

	memset((void*)po,0,sizeof(struct StAreaMscTimeOffsetStruct));

		strncpy(po->sAreaCode,	pi->sAreaCode,9);
		strncpy(po->sMsc,	pi->sMsc,14);

		po->iOffset=		pi->iOffset;
}
void mvitem_fmstareamsctimeoffset(struct FStAreaMscTimeOffsetStruct *pi,struct StAreaMscTimeOffsetStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	memset((void*)po,0,sizeof(struct StAreaMscTimeOffsetStruct));

		strncpy(po->sAreaCode,	pi->sAreaCode,9);
		strncpy(po->sMsc,	pi->sMsc,14);

		strncpy(sTemp,	pi->sOffset,8);sTemp[8]=0;
		po->iOffset=atoi(sTemp);

		AllTrim(po->sAreaCode);
		AllTrim(po->sMsc);
}
void mvitem_mfstareamsctimeoffset(struct StAreaMscTimeOffsetStruct *pi,struct FStAreaMscTimeOffsetStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FStAreaMscTimeOffsetStruct));

		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));

		sprintf(sTemp,"%08d",pi->iOffset);
		strncpy(po->sOffset,sTemp,8);

}
/**对表ST_AREA_MSC_TIME_OFFSET的链表释放函数**/
void DestroyStAreaMscTimeOffset(struct StAreaMscTimeOffsetStruct *ptHead)
{
	struct StAreaMscTimeOffsetStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitStAreaMscTimeOffset(struct StAreaMscTimeOffsetStruct **pptHead)
{
	int iCnt=0;
	static struct StAreaMscTimeOffsetStruct *pTemp,*ptHead=NULL;
	struct StAreaMscTimeOffsetStruct Temp;
	struct StAreaMscTimeOffsetStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyStAreaMscTimeOffset(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct StAreaMscTimeOffsetStructIn));
	sprintf(TempIn.sTableName,"ST_AREA_MSC_TIME_OFFSET");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetStAreaMscTimeOffsetToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct StAreaMscTimeOffsetStruct*)
			malloc(sizeof(struct StAreaMscTimeOffsetStruct)))==NULL){

			DestroyStAreaMscTimeOffset(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct StAreaMscTimeOffsetStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表ST_AREA_MSC_TIME_OFFSET记录数%d",iCnt);
	}

	WriteProcMsg("加载表ST_AREA_MSC_TIME_OFFSET完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据结构缓冲写入ST_AREA_MSC_TIME_OFFSET*/
int EInsertStructToStAreaMscTimeOffset(struct StAreaMscTimeOffsetStruct *p,
	int iInsertFlag,struct StAreaMscTimeOffsetStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asAreaCode[iCurPos],	p->sAreaCode);
		strcpy(pTarget->asMsc[iCurPos],		p->sMsc);

		pTarget->aiOffset[iCurPos]=		p->iOffset;

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==ST_AREA_MSC_TIME_OFFSET_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				AREA_CODE,\n\
				MSC,\n\
				OFFSET)\n\
			VALUES (\n\
				:asAreaCode,\n\
				:asMsc,\n\
				:aiOffset\n\
			)",sTableName);

		/* EXEC SQL PREPARE ST_AREA_MSC_TIME_OFFSETTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1508;
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


		if(CheckSqlResult("Prepare insert statement ST_AREA_MSC_TIME_OFFSET")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE ST_AREA_MSC_TIME_OFFSETTRG USING
				:pTarget->asAreaCode,
				:pTarget->asMsc,
				:pTarget->aiOffset; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1527;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asMsc);
  sqlstm.sqhstl[1] = (unsigned long )15;
  sqlstm.sqhsts[1] = (         int  )15;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->aiOffset);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
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


		if(CheckSqlResult("Dyn insert into ST_AREA_MSC_TIME_OFFSET")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据动态从ODS_MMS_TICKET中用结构缓冲方式取数据*/
int EGetOdsMmsTicketToStruct(struct OdsMmsTicketStruct *p,
	struct OdsMmsTicketStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SERVICE_ID,0),\n\
				nvl(BILL_NUMBER,' '),\n\
				nvl(CALL_TYPE,0),\n\
				nvl(HOME_AREA,' '),\n\
				to_char(nvl(START_TIME,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(OTHER_PARTY,' '),\n\
				nvl(OPP_NUMBER,' '),\n\
				nvl(SP_CODE,' '),\n\
				nvl(SP_SMG,' '),\n\
				nvl(ACCESS_CODE,' '),\n\
				nvl(SERVICE_CODE,' '),\n\
				nvl(LANG_TYPE,' '),\n\
				nvl(SV_TYPE,0),\n\
				nvl(SVC_EX,' '),\n\
				to_char(nvl(SM_TYPE,0)),\n\
				to_char(nvl(MSG_LENGTH,0)),\n\
				nvl(END_REASON,0),\n\
				nvl(NICE,0),\n\
				nvl(SMG_CODE,' '),\n\
				nvl(USER_TYPE,0),\n\
				nvl(CFEE1,0),\n\
				nvl(AFEE1,0),\n\
				nvl(SERVICE_NUMR,' '),\n\
				nvl(PART_ID,0),\n\
				nvl(ACCOUNT_ID,0),\n\
				nvl(SUBSCRIPTION_ID,0),\n\
				nvl(SVC_TYPE,0),\n\
				nvl(REGION_ID,' '),\n\
				nvl(USAGE_TYPE,0),\n\
				nvl(USAGE_CASE,0),\n\
				nvl(USAGE_CLASS,0),\n\
				nvl(CLASS_OF_SERVICE_CODE,0),\n\
				nvl(CFEE,0),\n\
				nvl(LFEE,0),\n\
				nvl(IFEE,0),\n\
				nvl(DIS_CFEE,0),\n\
				nvl(DIS_LFEE,0),\n\
				nvl(DIS_IFEE,0),\n\
				nvl(CFEE_TIMES,0),\n\
				nvl(LFEE_TIMES,0),\n\
				nvl(IFEE_TIMES,0),\n\
				nvl(PACKAGE_ID,0),\n\
				nvl(PRODUCT_CLASS,0),\n\
				nvl(ORIGINAL_FILE,' '),\n\
				nvl(LATE_LINK,0),\n\
				to_char(nvl(CAL_TIME,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(AUDI_STR,' '),\n\
				nvl(VARIAN_STR,' '),\n\
				nvl(DATAFILE_DAY,' '),\n\
				nvl(INSTORAGE_DAY,' '),\n\
				nvl(USAGE_SEQ,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ODS_MMS_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1554;
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


		CheckSqlError(" PREPARE ODS_MMS_TICKETSCR ODS_MMS_TICKETCR");

		/* EXEC SQL DECLARE ODS_MMS_TICKETCR CURSOR FOR ODS_MMS_TICKETSCR; */ 

		CheckSqlError("Declare ODS_MMS_TICKETCR");

		/* EXEC SQL OPEN ODS_MMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1573;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ODS_MMS_TICKETCR;");


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

		/* EXEC SQL CLOSE ODS_MMS_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1588;
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
		/* EXEC SQL FETCH ODS_MMS_TICKETCR INTO
			:pSource->aiServiceID,
			:pSource->asBillNumber,
			:pSource->aiCallType,
			:pSource->asHomeArea,
			:pSource->asStartTime,
			:pSource->asOtherParty,
			:pSource->asOppNumber,
			:pSource->asSpCode,
			:pSource->asSpSmg,
			:pSource->asAccessCode,
			:pSource->asServiceCode,
			:pSource->asLangType,
			:pSource->aiSvType,
			:pSource->asSvcEx,
			:pSource->asSmType,
			:pSource->asMsgLength,
			:pSource->aiEndReason,
			:pSource->aiNice,
			:pSource->asSmgCode,
			:pSource->aiUserType,
			:pSource->aiCfee1,
			:pSource->aiAfee1,
			:pSource->asServiceNumr,
			:pSource->aiPartID,
			:pSource->aiAccountID,
			:pSource->aiSubscriptionID,
			:pSource->aiSvcType,
			:pSource->asRegionID,
			:pSource->aiUsageType,
			:pSource->aiUsageCase,
			:pSource->aiUsageClass,
			:pSource->aiClassOfServiceCode,
			:pSource->aiCfee,
			:pSource->aiLfee,
			:pSource->aiIfee,
			:pSource->aiDisCfee,
			:pSource->aiDisLfee,
			:pSource->aiDisIfee,
			:pSource->aiCfeeTimes,
			:pSource->aiLfeeTimes,
			:pSource->aiIfeeTimes,
			:pSource->aiPackageID,
			:pSource->aiProductClass,
			:pSource->asOriginalFile,
			:pSource->aiLateLink,
			:pSource->asCalTime,
			:pSource->asAudiStr,
			:pSource->asVarianStr,
			:pSource->asDatafileDay,
			:pSource->asInstorageDay,
			:pSource->asUsageSeq; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1603;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiServiceID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asBillNumber);
  sqlstm.sqhstl[1] = (unsigned long )41;
  sqlstm.sqhsts[1] = (         int  )41;
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
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asHomeArea);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asOtherParty);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )41;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asOppNumber);
  sqlstm.sqhstl[6] = (unsigned long )41;
  sqlstm.sqhsts[6] = (         int  )41;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSpCode);
  sqlstm.sqhstl[7] = (unsigned long )10;
  sqlstm.sqhsts[7] = (         int  )10;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSpSmg);
  sqlstm.sqhstl[8] = (unsigned long )7;
  sqlstm.sqhsts[8] = (         int  )7;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asAccessCode);
  sqlstm.sqhstl[9] = (unsigned long )11;
  sqlstm.sqhsts[9] = (         int  )11;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asServiceCode);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )11;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asLangType);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiSvType);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asSvcEx);
  sqlstm.sqhstl[13] = (unsigned long )4;
  sqlstm.sqhsts[13] = (         int  )4;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asSmType);
  sqlstm.sqhstl[14] = (unsigned long )16;
  sqlstm.sqhsts[14] = (         int  )16;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asMsgLength);
  sqlstm.sqhstl[15] = (unsigned long )17;
  sqlstm.sqhsts[15] = (         int  )17;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->aiEndReason);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )sizeof(int);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->aiNice);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )sizeof(int);
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asSmgCode);
  sqlstm.sqhstl[18] = (unsigned long )5;
  sqlstm.sqhsts[18] = (         int  )5;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->aiUserType);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(int);
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->aiCfee1);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->aiAfee1);
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )sizeof(int);
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asServiceNumr);
  sqlstm.sqhstl[22] = (unsigned long )41;
  sqlstm.sqhsts[22] = (         int  )41;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->aiPartID);
  sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[23] = (         int  )sizeof(int);
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->aiAccountID);
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )sizeof(int);
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->aiSubscriptionID);
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )sizeof(int);
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->aiSvcType);
  sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[26] = (         int  )sizeof(int);
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->asRegionID);
  sqlstm.sqhstl[27] = (unsigned long )2;
  sqlstm.sqhsts[27] = (         int  )2;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->aiUsageType);
  sqlstm.sqhstl[28] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[28] = (         int  )sizeof(int);
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pSource->aiUsageCase);
  sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[29] = (         int  )sizeof(int);
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pSource->aiUsageClass);
  sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[30] = (         int  )sizeof(int);
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pSource->aiClassOfServiceCode);
  sqlstm.sqhstl[31] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[31] = (         int  )sizeof(int);
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pSource->aiCfee);
  sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[32] = (         int  )sizeof(int);
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pSource->aiLfee);
  sqlstm.sqhstl[33] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[33] = (         int  )sizeof(int);
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pSource->aiIfee);
  sqlstm.sqhstl[34] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[34] = (         int  )sizeof(int);
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pSource->aiDisCfee);
  sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[35] = (         int  )sizeof(int);
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pSource->aiDisLfee);
  sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[36] = (         int  )sizeof(int);
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pSource->aiDisIfee);
  sqlstm.sqhstl[37] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[37] = (         int  )sizeof(int);
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pSource->aiCfeeTimes);
  sqlstm.sqhstl[38] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[38] = (         int  )sizeof(int);
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pSource->aiLfeeTimes);
  sqlstm.sqhstl[39] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[39] = (         int  )sizeof(int);
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pSource->aiIfeeTimes);
  sqlstm.sqhstl[40] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[40] = (         int  )sizeof(int);
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pSource->aiPackageID);
  sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[41] = (         int  )sizeof(int);
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pSource->aiProductClass);
  sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[42] = (         int  )sizeof(int);
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqharc[42] = (unsigned long  *)0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)(pSource->asOriginalFile);
  sqlstm.sqhstl[43] = (unsigned long )81;
  sqlstm.sqhsts[43] = (         int  )81;
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqharc[43] = (unsigned long  *)0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
  sqlstm.sqhstv[44] = (unsigned char  *)(pSource->aiLateLink);
  sqlstm.sqhstl[44] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[44] = (         int  )sizeof(int);
  sqlstm.sqindv[44] = (         short *)0;
  sqlstm.sqinds[44] = (         int  )0;
  sqlstm.sqharm[44] = (unsigned long )0;
  sqlstm.sqharc[44] = (unsigned long  *)0;
  sqlstm.sqadto[44] = (unsigned short )0;
  sqlstm.sqtdso[44] = (unsigned short )0;
  sqlstm.sqhstv[45] = (unsigned char  *)(pSource->asCalTime);
  sqlstm.sqhstl[45] = (unsigned long )15;
  sqlstm.sqhsts[45] = (         int  )15;
  sqlstm.sqindv[45] = (         short *)0;
  sqlstm.sqinds[45] = (         int  )0;
  sqlstm.sqharm[45] = (unsigned long )0;
  sqlstm.sqharc[45] = (unsigned long  *)0;
  sqlstm.sqadto[45] = (unsigned short )0;
  sqlstm.sqtdso[45] = (unsigned short )0;
  sqlstm.sqhstv[46] = (unsigned char  *)(pSource->asAudiStr);
  sqlstm.sqhstl[46] = (unsigned long )2049;
  sqlstm.sqhsts[46] = (         int  )2049;
  sqlstm.sqindv[46] = (         short *)0;
  sqlstm.sqinds[46] = (         int  )0;
  sqlstm.sqharm[46] = (unsigned long )0;
  sqlstm.sqharc[46] = (unsigned long  *)0;
  sqlstm.sqadto[46] = (unsigned short )0;
  sqlstm.sqtdso[46] = (unsigned short )0;
  sqlstm.sqhstv[47] = (unsigned char  *)(pSource->asVarianStr);
  sqlstm.sqhstl[47] = (unsigned long )81;
  sqlstm.sqhsts[47] = (         int  )81;
  sqlstm.sqindv[47] = (         short *)0;
  sqlstm.sqinds[47] = (         int  )0;
  sqlstm.sqharm[47] = (unsigned long )0;
  sqlstm.sqharc[47] = (unsigned long  *)0;
  sqlstm.sqadto[47] = (unsigned short )0;
  sqlstm.sqtdso[47] = (unsigned short )0;
  sqlstm.sqhstv[48] = (unsigned char  *)(pSource->asDatafileDay);
  sqlstm.sqhstl[48] = (unsigned long )9;
  sqlstm.sqhsts[48] = (         int  )9;
  sqlstm.sqindv[48] = (         short *)0;
  sqlstm.sqinds[48] = (         int  )0;
  sqlstm.sqharm[48] = (unsigned long )0;
  sqlstm.sqharc[48] = (unsigned long  *)0;
  sqlstm.sqadto[48] = (unsigned short )0;
  sqlstm.sqtdso[48] = (unsigned short )0;
  sqlstm.sqhstv[49] = (unsigned char  *)(pSource->asInstorageDay);
  sqlstm.sqhstl[49] = (unsigned long )9;
  sqlstm.sqhsts[49] = (         int  )9;
  sqlstm.sqindv[49] = (         short *)0;
  sqlstm.sqinds[49] = (         int  )0;
  sqlstm.sqharm[49] = (unsigned long )0;
  sqlstm.sqharc[49] = (unsigned long  *)0;
  sqlstm.sqadto[49] = (unsigned short )0;
  sqlstm.sqtdso[49] = (unsigned short )0;
  sqlstm.sqhstv[50] = (unsigned char  *)(pSource->asUsageSeq);
  sqlstm.sqhstl[50] = (unsigned long )19;
  sqlstm.sqhsts[50] = (         int  )19;
  sqlstm.sqindv[50] = (         short *)0;
  sqlstm.sqinds[50] = (         int  )0;
  sqlstm.sqharm[50] = (unsigned long )0;
  sqlstm.sqharc[50] = (unsigned long  *)0;
  sqlstm.sqadto[50] = (unsigned short )0;
  sqlstm.sqtdso[50] = (unsigned short )0;
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


		CheckSqlError("Fetch ODS_MMS_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ODS_MMS_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 51;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1822;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ODS_MMS_TICKET_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iServiceID=			pSource->aiServiceID[iCurPos];

		strcpy(p->sBillNumber,		pSource->asBillNumber[iCurPos]);

		p->iCallType=			pSource->aiCallType[iCurPos];

		strcpy(p->sHomeArea,		pSource->asHomeArea[iCurPos]);
		strcpy(p->sStartTime,		pSource->asStartTime[iCurPos]);
		strcpy(p->sOtherParty,		pSource->asOtherParty[iCurPos]);
		strcpy(p->sOppNumber,		pSource->asOppNumber[iCurPos]);
		strcpy(p->sSpCode,		pSource->asSpCode[iCurPos]);
		strcpy(p->sSpSmg,		pSource->asSpSmg[iCurPos]);
		strcpy(p->sAccessCode,		pSource->asAccessCode[iCurPos]);
		strcpy(p->sServiceCode,		pSource->asServiceCode[iCurPos]);
		strcpy(p->sLangType,		pSource->asLangType[iCurPos]);

		p->iSvType=			pSource->aiSvType[iCurPos];

		strcpy(p->sSvcEx,		pSource->asSvcEx[iCurPos]);
		strcpy(p->sSmType,		pSource->asSmType[iCurPos]);
		strcpy(p->sMsgLength,		pSource->asMsgLength[iCurPos]);

		p->iEndReason=			pSource->aiEndReason[iCurPos];
		p->iNice=			pSource->aiNice[iCurPos];

		strcpy(p->sSmgCode,		pSource->asSmgCode[iCurPos]);

		p->iUserType=			pSource->aiUserType[iCurPos];
		p->iCfee1=			pSource->aiCfee1[iCurPos];
		p->iAfee1=			pSource->aiAfee1[iCurPos];

		strcpy(p->sServiceNumr,		pSource->asServiceNumr[iCurPos]);

		p->iPartID=			pSource->aiPartID[iCurPos];
		p->iAccountID=			pSource->aiAccountID[iCurPos];
		p->iSubscriptionID=		pSource->aiSubscriptionID[iCurPos];
		p->iSvcType=			pSource->aiSvcType[iCurPos];

		strcpy(p->sRegionID,		pSource->asRegionID[iCurPos]);

		p->iUsageType=			pSource->aiUsageType[iCurPos];
		p->iUsageCase=			pSource->aiUsageCase[iCurPos];
		p->iUsageClass=			pSource->aiUsageClass[iCurPos];
		p->iClassOfServiceCode=		pSource->aiClassOfServiceCode[iCurPos];
		p->iCfee=			pSource->aiCfee[iCurPos];
		p->iLfee=			pSource->aiLfee[iCurPos];
		p->iIfee=			pSource->aiIfee[iCurPos];
		p->iDisCfee=			pSource->aiDisCfee[iCurPos];
		p->iDisLfee=			pSource->aiDisLfee[iCurPos];
		p->iDisIfee=			pSource->aiDisIfee[iCurPos];
		p->iCfeeTimes=			pSource->aiCfeeTimes[iCurPos];
		p->iLfeeTimes=			pSource->aiLfeeTimes[iCurPos];
		p->iIfeeTimes=			pSource->aiIfeeTimes[iCurPos];
		p->iPackageID=			pSource->aiPackageID[iCurPos];
		p->iProductClass=		pSource->aiProductClass[iCurPos];

		strcpy(p->sOriginalFile,	pSource->asOriginalFile[iCurPos]);

		p->iLateLink=			pSource->aiLateLink[iCurPos];

		strcpy(p->sCalTime,		pSource->asCalTime[iCurPos]);
		strcpy(p->sAudiStr,		pSource->asAudiStr[iCurPos]);
		strcpy(p->sVarianStr,		pSource->asVarianStr[iCurPos]);
		strcpy(p->sDatafileDay,		pSource->asDatafileDay[iCurPos]);
		strcpy(p->sInstorageDay,	pSource->asInstorageDay[iCurPos]);
		strcpy(p->sUsageSeq,	pSource->asUsageSeq[iCurPos]);

		AllTrim(p->sBillNumber);
		AllTrim(p->sHomeArea);
		AllTrim(p->sStartTime);
		AllTrim(p->sOtherParty);
		AllTrim(p->sOppNumber);
		AllTrim(p->sSpCode);
		AllTrim(p->sSpSmg);
		AllTrim(p->sAccessCode);
		AllTrim(p->sServiceCode);
		AllTrim(p->sLangType);
		AllTrim(p->sSvcEx);
		AllTrim(p->sSmType);
		AllTrim(p->sMsgLength);
		AllTrim(p->sSmgCode);
		AllTrim(p->sServiceNumr);
		AllTrim(p->sRegionID);
		AllTrim(p->sOriginalFile);
		AllTrim(p->sCalTime);
		AllTrim(p->sAudiStr);
		AllTrim(p->sVarianStr);
		AllTrim(p->sDatafileDay);
		AllTrim(p->sInstorageDay);
		AllTrim(p->sUsageSeq);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据动态从LOC_STT_TICKET中用结构缓冲方式取数据*/
int EGetLocSttTicketToStruct(struct LocSttTicketStruct *p,
	struct LocSttTicketStructIn *pSource)
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
				to_char(nvl(UPDATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(DEAL_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(SOURCE_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE LOC_STT_TICKETSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1837;
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


		CheckSqlError(" PREPARE LOC_STT_TICKETSCR LOC_STT_TICKETCR");

		/* EXEC SQL DECLARE LOC_STT_TICKETCR CURSOR FOR LOC_STT_TICKETSCR; */ 

		CheckSqlError("Declare LOC_STT_TICKETCR");

		/* EXEC SQL OPEN LOC_STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1856;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open LOC_STT_TICKETCR;");


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

		/* EXEC SQL CLOSE LOC_STT_TICKETCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 51;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1871;
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
		/* EXEC SQL FETCH LOC_STT_TICKETCR INTO
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
  sqlstm.offset = (unsigned int  )1886;
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


		CheckSqlError("Fetch LOC_STT_TICKETCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE LOC_STT_TICKETCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 63;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2153;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=LOC_STT_TICKET_BUFLEN_IN)
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
