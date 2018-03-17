
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
           char  filnam[8];
};
static struct sqlcxp sqlfpn =
{
    7,
    "imsi.pc"
};


static unsigned int sqlctx = 9459;


static struct sqlexd {
   unsigned int   sqlvsn;
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
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
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
            void  *sqhstv[3];
   unsigned int   sqhstl[3];
            int   sqhsts[3];
            void  *sqindv[3];
            int   sqinds[3];
   unsigned int   sqharm[3];
   unsigned int   *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
{12,4130,1,0,0,
5,0,0,1,0,0,17,49,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,2,0,0,21,53,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
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
#include "imsiesn.h"

int EUpdateStructToMsisdnImsiEsn(struct UMsisdnImsiEsnStruct *p,
        int iUpdateFlag,struct UMsisdnImsiEsnStructUp *pTarget)
{

        int  iCurPos=pTarget->iCurPos;
        char *sTableName=pTarget->sTableName;


        if(iUpdateFlag!=TRUE){


                strcpy(pTarget->asYMap[iCurPos],		p->sYMap);
                strcpy(pTarget->asRowID[iCurPos],               p->sRowID);

                iCurPos++;
        }

        if(iUpdateFlag==TRUE||iCurPos==MSISDN_IMSI_ESN_BUFLEN_UP){

/* INSERT */
                char statement[4096];

                if(iCurPos==0) return 0;

                sprintf(statement,"\n\
                        UPDATE %s\n\
                        SET \n\
                                Y_MAP=                  :asYMap\n\
                        WHERE \n\
                                ROWID = chartorowid(:asRowID)\n\
                        ",sTableName);

                /* EXEC SQL PREPARE RU_IMSIESN_TICKETUCRxx FROM :statement; */ 

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
                sqlstm.sqhstv[0] = (         void  *)statement;
                sqlstm.sqhstl[0] = (unsigned int  )4096;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         void  *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned int  )0;
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


                if(CheckSqlResult("Prepare update statement U_MSISDN_IMSI_ESN")<0)
                        return -1;

                /* EXEC SQL FOR :iCurPos EXECUTE RU_IMSIESN_TICKETUCR_1xx USING
                                :pTarget->asYMap,
                                :pTarget->asRowID,
                                :pTarget->asYMap; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )iCurPos;
                sqlstm.offset = (unsigned int  )24;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (         void  *)(pTarget->asYMap);
                sqlstm.sqhstl[0] = (unsigned int  )73;
                sqlstm.sqhsts[0] = (         int  )73;
                sqlstm.sqindv[0] = (         void  *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned int  )0;
                sqlstm.sqharc[0] = (unsigned int   *)0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (         void  *)(pTarget->asRowID);
                sqlstm.sqhstl[1] = (unsigned int  )19;
                sqlstm.sqhsts[1] = (         int  )19;
                sqlstm.sqindv[1] = (         void  *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned int  )0;
                sqlstm.sqharc[1] = (unsigned int   *)0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (         void  *)(pTarget->asYMap);
                sqlstm.sqhstl[2] = (unsigned int  )73;
                sqlstm.sqhsts[2] = (         int  )73;
                sqlstm.sqindv[2] = (         void  *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned int  )0;
                sqlstm.sqharc[2] = (unsigned int   *)0;
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


                if(CheckSqlResult("Dyn update U_MSISDN_IMSI_ESN")<0) return -1;

                iCurPos=0;
        }

        pTarget->iCurPos=iCurPos;
        return 0;
}

