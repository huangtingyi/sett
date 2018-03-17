
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
    "wwdb.pc"
};


static unsigned int sqlctx = 10379;


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
   unsigned char  *sqhstv[14];
   unsigned long  sqhstl[14];
            int   sqhsts[14];
            short *sqindv[14];
            int   sqinds[14];
   unsigned long  sqharm[14];
   unsigned long  *sqharc[14];
   unsigned short  sqadto[14];
   unsigned short  sqtdso[14];
} sqlstm = {12,14};

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

 static char *sq0017 = 
"select TABLESPACE_NAME ,INDEX_NAME ,UNIQUENESS ,INI_TRANS ,MAX_TRANS ,INITI\
AL_EXTENT ,NEXT_EXTENT ,MIN_EXTENTS ,MAX_EXTENTS ,PCT_INCREASE ,FREELISTS ,FR\
EELIST_GROUPS  from USER_INDEXES where TABLE_NAME=:b0           ";

 static char *sq0018 = 
"select COLUMN_NAME  from USER_IND_COLUMNS where INDEX_NAME=:b0 order by COL\
UMN_POSITION            ";

 static char *sq0020 = 
"select TABLESPACE_NAME ,INDEX_NAME ,UNIQUENESS ,INI_TRANS ,MAX_TRANS ,INITI\
AL_EXTENT ,NEXT_EXTENT ,MIN_EXTENTS ,MAX_EXTENTS ,PCT_INCREASE ,FREELISTS ,FR\
EELIST_GROUPS  from USER_INDEXES where TABLE_NAME=:b0           ";

 static char *sq0021 = 
"select COLUMN_NAME  from USER_IND_COLUMNS where INDEX_NAME=:b0 order by COL\
UMN_POSITION            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,852,0,0,
5,0,0,0,0,0,27,62,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,10,0,0,1,10,0,0,
36,0,0,0,0,0,27,65,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,10,0,0,
67,0,0,3,0,0,30,72,0,0,0,0,0,1,0,
82,0,0,4,0,0,30,108,0,0,0,0,0,1,0,
97,0,0,5,0,0,32,112,0,0,0,0,0,1,0,
112,0,0,6,0,0,29,116,0,0,0,0,0,1,0,
127,0,0,7,0,0,31,120,0,0,0,0,0,1,0,
142,0,0,8,64,0,4,146,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
165,0,0,9,68,0,4,160,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
188,0,0,10,65,0,4,175,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
211,0,0,11,65,0,4,190,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
234,0,0,12,0,0,24,203,0,0,1,1,0,1,0,1,97,0,0,
253,0,0,13,286,0,4,214,0,0,14,1,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,97,0,0,
324,0,0,14,0,0,24,270,0,0,1,1,0,1,0,1,97,0,0,
343,0,0,15,286,0,4,292,0,0,14,1,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,97,0,0,
414,0,0,16,0,0,24,351,0,0,1,1,0,1,0,1,97,0,0,
433,0,0,17,216,0,9,408,0,0,1,1,0,1,0,1,97,0,0,
452,0,0,17,0,0,13,413,0,0,12,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
515,0,0,17,0,0,15,417,0,0,0,0,0,1,0,
530,0,0,18,99,0,9,432,0,0,1,1,0,1,0,1,97,0,0,
549,0,0,17,0,0,15,435,0,0,0,0,0,1,0,
564,0,0,18,0,0,13,439,0,0,1,0,0,1,0,2,97,0,0,
583,0,0,17,0,0,15,443,0,0,0,0,0,1,0,
598,0,0,18,0,0,15,444,0,0,0,0,0,1,0,
613,0,0,18,0,0,13,458,0,0,1,0,0,1,0,2,97,0,0,
632,0,0,17,0,0,15,462,0,0,0,0,0,1,0,
647,0,0,18,0,0,15,463,0,0,0,0,0,1,0,
662,0,0,18,0,0,15,468,0,0,0,0,0,1,0,
677,0,0,19,0,0,24,507,0,0,1,1,0,1,0,1,97,0,0,
696,0,0,17,0,0,15,512,0,0,0,0,0,1,0,
711,0,0,18,0,0,15,513,0,0,0,0,0,1,0,
726,0,0,17,0,0,13,526,0,0,12,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
789,0,0,17,0,0,15,530,0,0,0,0,0,1,0,
804,0,0,20,216,0,9,586,0,0,1,1,0,1,0,1,97,0,0,
823,0,0,20,0,0,13,593,0,0,12,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
886,0,0,20,0,0,15,597,0,0,0,0,0,1,0,
901,0,0,21,99,0,9,616,0,0,1,1,0,1,0,1,97,0,0,
920,0,0,20,0,0,15,619,0,0,0,0,0,1,0,
935,0,0,21,0,0,13,623,0,0,1,0,0,1,0,2,97,0,0,
954,0,0,20,0,0,15,627,0,0,0,0,0,1,0,
969,0,0,21,0,0,15,628,0,0,0,0,0,1,0,
984,0,0,21,0,0,13,642,0,0,1,0,0,1,0,2,97,0,0,
1003,0,0,20,0,0,15,646,0,0,0,0,0,1,0,
1018,0,0,21,0,0,15,647,0,0,0,0,0,1,0,
1033,0,0,21,0,0,15,652,0,0,0,0,0,1,0,
1048,0,0,22,0,0,24,693,0,0,1,1,0,1,0,1,97,0,0,
1067,0,0,20,0,0,15,698,0,0,0,0,0,1,0,
1082,0,0,21,0,0,15,699,0,0,0,0,0,1,0,
1097,0,0,20,0,0,13,713,0,0,12,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
1160,0,0,20,0,0,15,717,0,0,0,0,0,1,0,
1175,0,0,23,109,0,4,825,0,0,4,1,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
1206,0,0,24,109,0,4,981,0,0,4,1,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
1237,0,0,25,0,0,17,1172,0,0,1,1,0,1,0,1,97,0,0,
1256,0,0,25,0,0,20,1180,0,0,1,1,0,1,0,3,32,0,0,
1275,0,0,25,0,0,11,1195,0,0,1,1,0,1,0,1,32,0,0,
1294,0,0,25,0,0,14,1200,0,0,1,0,0,1,0,2,32,0,0,
1313,0,0,25,0,0,15,1267,0,0,0,0,0,1,0,
};



#include "hnixs.h"
#include "list.h"
#include "wwcoding.h"
#include "wwtiny.h"
#include "wwlog.h"
#include "wwdecrypt.h"
#include "wwfile.h"
#include "wwdir.h"
#include "wwdb.h"

#ifndef OP_OK
#define OP_OK 0
#endif

#ifndef OP_ERR
#define OP_ERR -1
#endif

/* EXEC SQL INCLUDE sqlca;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */
/* EXEC SQL INCLUDE sqlda;
 */ 
/*
 * $Header: sqlda.h 08-may-2007.05:58:33 ardesai Exp $ sqlda.h 
 */

/***************************************************************
*      The SQLDA descriptor definition                         *
*--------------------------------------------------------------*
*      VAX/3B Version                                          *
*                                                              *
* Copyright (c) 1987, 2007, Oracle. All rights reserved.  *
***************************************************************/


/* NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************
*/

/*  MODIFIED
    ardesai    05/08/07  - Bug[6037057] Undef Y
    apopat     05/08/02  - [2362423] MVS PE to make lines shorter than 79
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for sqlda
    lvbcheng   08/15/97 -  Move sqlda protos to sqlcpr.h
    lvbcheng   06/25/97 -  Move sqlda protos to this file
    jbasu      01/29/95 -  correct typo
    jbasu      01/27/95 -  correct comment - ub2->sb2
    jbasu      12/12/94 - Bug 217878: note this is an SOSD file
    Morse      12/01/87 - undef L and S for v6 include files
    Richey     07/13/87 - change int defs to long 
    Clare      09/13/84 - Port: Ch types to match SQLLIB structs
    Clare      10/02/86 - Add ifndef SQLDA
*/

#ifndef SQLDA_
#define SQLDA_ 1
 
#ifdef T
# undef T
#endif
#ifdef F
# undef F
#endif

#ifdef S
# undef S
#endif
#ifdef L
# undef L
#endif

#ifdef Y
 # undef Y
#endif
 
struct SQLDA {
  /* ub4    */ int        N; /* Descriptor size in number of entries        */
  /* text** */ char     **V; /* Ptr to Arr of addresses of main variables   */
  /* ub4*   */ int       *L; /* Ptr to Arr of lengths of buffers            */
  /* sb2*   */ short     *T; /* Ptr to Arr of types of buffers              */
  /* sb2**  */ short    **I; /* Ptr to Arr of addresses of indicator vars   */
  /* sb4    */ int        F; /* Number of variables found by DESCRIBE       */
  /* text** */ char     **S; /* Ptr to Arr of variable name pointers        */
  /* ub2*   */ short     *M; /* Ptr to Arr of max lengths of var. names     */
  /* ub2*   */ short     *C; /* Ptr to Arr of current lengths of var. names */
  /* text** */ char     **X; /* Ptr to Arr of ind. var. name pointers       */
  /* ub2*   */ short     *Y; /* Ptr to Arr of max lengths of ind. var. names*/
  /* ub2*   */ short     *Z; /* Ptr to Arr of cur lengths of ind. var. names*/
  };
 
typedef struct SQLDA SQLDA;
 
#endif

/* ----------------- */
/* defines for sqlda */
/* ----------------- */

#define SQLSQLDAAlloc(arg1, arg2, arg3, arg4) sqlaldt(arg1, arg2, arg3, arg4) 

#define SQLSQLDAFree(arg1, arg2) sqlclut(arg1, arg2) 



/*  */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */
/*  */ 
/*
 * $Header: sqlda.h 08-may-2007.05:58:33 ardesai Exp $ sqlda.h 
 */

/***************************************************************
*      The SQLDA descriptor definition                         *
*--------------------------------------------------------------*
*      VAX/3B Version                                          *
*                                                              *
* Copyright (c) 1987, 2007, Oracle. All rights reserved.  *
***************************************************************/


/* NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************
*/

/*  MODIFIED
    ardesai    05/08/07  - Bug[6037057] Undef Y
    apopat     05/08/02  - [2362423] MVS PE to make lines shorter than 79
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for sqlda
    lvbcheng   08/15/97 -  Move sqlda protos to sqlcpr.h
    lvbcheng   06/25/97 -  Move sqlda protos to this file
    jbasu      01/29/95 -  correct typo
    jbasu      01/27/95 -  correct comment - ub2->sb2
    jbasu      12/12/94 - Bug 217878: note this is an SOSD file
    Morse      12/01/87 - undef L and S for v6 include files
    Richey     07/13/87 - change int defs to long 
    Clare      09/13/84 - Port: Ch types to match SQLLIB structs
    Clare      10/02/86 - Add ifndef SQLDA
*/

#ifndef SQLDA_
#define SQLDA_ 1
 
#ifdef T
# undef T
#endif
#ifdef F
# undef F
#endif

#ifdef S
# undef S
#endif
#ifdef L
# undef L
#endif

#ifdef Y
 # undef Y
#endif
 
struct SQLDA {
  /* ub4    */ int        N; /* Descriptor size in number of entries        */
  /* text** */ char     **V; /* Ptr to Arr of addresses of main variables   */
  /* ub4*   */ int       *L; /* Ptr to Arr of lengths of buffers            */
  /* sb2*   */ short     *T; /* Ptr to Arr of types of buffers              */
  /* sb2**  */ short    **I; /* Ptr to Arr of addresses of indicator vars   */
  /* sb4    */ int        F; /* Number of variables found by DESCRIBE       */
  /* text** */ char     **S; /* Ptr to Arr of variable name pointers        */
  /* ub2*   */ short     *M; /* Ptr to Arr of max lengths of var. names     */
  /* ub2*   */ short     *C; /* Ptr to Arr of current lengths of var. names */
  /* text** */ char     **X; /* Ptr to Arr of ind. var. name pointers       */
  /* ub2*   */ short     *Y; /* Ptr to Arr of max lengths of ind. var. names*/
  /* ub2*   */ short     *Z; /* Ptr to Arr of cur lengths of ind. var. names*/
  };
 
typedef struct SQLDA SQLDA;
 
#endif

/* ----------------- */
/* defines for sqlda */
/* ----------------- */

#define SQLSQLDAAlloc(arg1, arg2, arg3, arg4) sqlaldt(arg1, arg2, arg3, arg4) 

#define SQLSQLDAFree(arg1, arg2) sqlclut(arg1, arg2) 





typedef struct TableStorageStruct
{
	char	sTableName[31];
	char	sTableSpaceName[31];
	int	iPctFree;
	int	iPctUsed;
	int  	iIniTrans;
	int	iMaxTrans;
	int 	iInitialExtent;
	int	iNextExtent;
	int	iMinExtents;
	int	iMaxExtents;
	int	iPctIncrease;
	int	iFreelists;
	int	iFreelistGroups;
}TABLE_STORAGE;

typedef struct IndexStorage
{
	char sTableSpaceName[31];
	char sIndexName[31];
	char sUniqueness[10];
	int	iIniTrans;
	int	iMaxTrans;
	int	iInitialExtent;
	int	iNextExtent;
	int	iMinExtents;
	int	iMaxExtents;
	int	iPctIncrease;
	int	iFreelists;
	int	iFreelistGroups;
}INDEX_STORAGE;

int ConnectDatabase(char sUserName[], char sPassword[],char sStr[])
{
/*设置默认的环境变量*/
	putenv("NLS_DATE_FORMAT=YYYYMMDDHH24MISS");
	
	if(strlen(sStr)==0){
		/* EXEC SQL CONNECT :sUserName IDENTIFIED BY :sPassword; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )10;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)sUserName;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sPassword;
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
  sqlstm.sqlcmax = (unsigned int )100;
  sqlstm.sqlcmin = (unsigned int )2;
  sqlstm.sqlcincr = (unsigned int )1;
  sqlstm.sqlctimeout = (unsigned int )0;
  sqlstm.sqlcnowait = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
	else {
		/* EXEC SQL CONNECT :sUserName IDENTIFIED BY :sPassword using :sStr; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )10;
  sqlstm.offset = (unsigned int  )36;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)sUserName;
  sqlstm.sqhstl[0] = (unsigned long )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sPassword;
  sqlstm.sqhstl[1] = (unsigned long )0;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)sStr;
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
  sqlstm.sqlcmax = (unsigned int )100;
  sqlstm.sqlcmin = (unsigned int )2;
  sqlstm.sqlcincr = (unsigned int )1;
  sqlstm.sqlctimeout = (unsigned int )0;
  sqlstm.sqlcnowait = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
	return CheckSqlResult("connect DB");
}

void DisconnectDatabase()
{
	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

/*
void WriteMsgAndCommit(char cStatusChar,char *fmt, ...)
{
	va_list argptr;
	static char sTemp[2048];
	
	va_start(argptr, fmt);
	vsprintf(sTemp,fmt, argptr);
	va_end(argptr);

	if(cStatusChar=='E') 	WriteAlertMsg(sTemp); 
	else			WriteProcMsg(sTemp); 

	EXEC SQL COMMIT WORK;
}
void WriteMsgAndRollback(char *fmt, ...)
{

	va_list argptr;
	char sTemp[2048];
	
	
	va_start(argptr, fmt);
	vsprintf(sTemp,fmt, argptr);
	va_end(argptr);

	WriteProcMsg(sTemp);
			
	EXEC SQL ROLLBACK WORK;
}
*/
void CommitWorkRelease()
{
	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )82;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

	
}
void RollbackWorkRelease()
{
	/* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
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


}		
void CommitWork()
{
	/* EXEC SQL COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )112;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

	
}
void RollbackWork()
{
	/* EXEC SQL ROLLBACK WORK; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )127;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}
int SqlResult(char sFileName[],int iLine,char sMessage[])
{
	char sTemp[8192];
	
	if(sqlca.sqlcode<0){
	
		sprintf(sTemp,"位置%s,错误代码%d",sMessage,sqlca.sqlcode);
		__PushErrStack(sFileName,iLine,sTemp);
		
		return -1;
	}
	return 0;
}
int iDataNotFound()
{
    return (sqlca.sqlcode==1403);
}



int TableExist(char sTableName[31])
{
	int iCnt=0;

	/* EXEC SQL SELECT COUNT(*) INTO :iCnt
        	FROM USER_TABLES
	WHERE
	TABLE_NAME = :sTableName; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(*)  into :b0  from USER_TABLES where TABLE_NAM\
E=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )142;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTableName;
 sqlstm.sqhstl[1] = (unsigned long )31;
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


	
	if(CheckSqlResult("COUNT USER_TABLES")<0) return FALSE;
	
 	return iCnt==0?FALSE:TRUE;
}

int SynonymExist(char sSynonymName[31])
{
	int iCnt=0;

	/* EXEC SQL 	
	SELECT COUNT(*) INTO :iCnt
        	FROM USER_SYNONYMS
    	WHERE
        	SYNONYM_NAME = :sSynonymName; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(*)  into :b0  from USER_SYNONYMS where SYNONYM\
_NAME=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )165;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sSynonymName;
 sqlstm.sqhstl[1] = (unsigned long )31;
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


        
	if(CheckSqlResult("COUNT USER_SYNONYMS")<0) return FALSE;
	
 	return iCnt==0?FALSE:TRUE;
}

int IndexExist(char sIndexName[31])
{
	int iCnt=0;

	/* EXEC SQL 	
	SELECT COUNT(*) INTO :iCnt
        	FROM USER_INDEXES
    	WHERE
        	INDEX_NAME = :sIndexName; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(*)  into :b0  from USER_INDEXES where INDEX_NA\
ME=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )188;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sIndexName;
 sqlstm.sqhstl[1] = (unsigned long )31;
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


        	
	if(CheckSqlResult("COUNT USER_INDEXES")<0) return FALSE;
	
 	return iCnt==0?FALSE:TRUE;
}

int TableIndexExist(char sTableName[31])
{
	int iCnt=0;

	/* EXEC SQL 	
	SELECT COUNT(*) INTO :iCnt
        	FROM USER_INDEXES
    	WHERE
        	TABLE_NAME = :sTableName; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(*)  into :b0  from USER_INDEXES where TABLE_NA\
ME=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )211;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTableName;
 sqlstm.sqhstl[1] = (unsigned long )31;
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


        
	if(CheckSqlResult("COUNT USER_INDEXES")<0) return FALSE;
	
 	return iCnt==0?FALSE:TRUE;
}
int ExecSql(char statement[])
{
	
	/* EXEC SQL EXECUTE IMMEDIATE :statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )234;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)statement;
 sqlstm.sqhstl[0] = (unsigned long )0;
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


	
	return CheckSqlResult(statement);
}


int  DupTable(char *sTemplate, char *sTableName)
{
	TABLE_STORAGE tabStorage;
	char  sDynamic[2048];
		
	/* EXEC SQL SELECT
			TABLE_NAME,
			TABLESPACE_NAME,
			PCT_FREE,
			PCT_USED,
			INI_TRANS,
			MAX_TRANS,
			INITIAL_EXTENT,
			NEXT_EXTENT,
			MIN_EXTENTS,
			MAX_EXTENTS,
			PCT_INCREASE,
			FREELISTS,
			FREELIST_GROUPS
		INTO :tabStorage
		FROM USER_TABLES
		WHERE TABLE_NAME = :sTemplate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select TABLE_NAME ,TABLESPACE_NAME ,PCT_FREE ,PCT_USED ,INI\
_TRANS ,MAX_TRANS ,INITIAL_EXTENT ,NEXT_EXTENT ,MIN_EXTENTS ,MAX_EXTENTS ,PCT\
_INCREASE ,FREELISTS ,FREELIST_GROUPS into :s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 \
,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13   from USER_TABLES where TABLE_NAME=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )253;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)tabStorage.sTableName;
 sqlstm.sqhstl[0] = (unsigned long )31;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)tabStorage.sTableSpaceName;
 sqlstm.sqhstl[1] = (unsigned long )31;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&tabStorage.iPctFree;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&tabStorage.iPctUsed;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&tabStorage.iIniTrans;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&tabStorage.iMaxTrans;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&tabStorage.iInitialExtent;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&tabStorage.iNextExtent;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&tabStorage.iMinExtents;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&tabStorage.iMaxExtents;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&tabStorage.iPctIncrease;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&tabStorage.iFreelists;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&tabStorage.iFreelistGroups;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)sTemplate;
 sqlstm.sqhstl[13] = (unsigned long )0;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
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


	
	if(CheckSqlResult("GET TEMPLATE STORAGE")<0)
		return OP_ERR;
	
	
	AllTrim(tabStorage.sTableSpaceName);
	AllTrim(tabStorage.sTableName);
	
	sprintf(sDynamic,
       "CREATE TABLE %s  \
		PCTFREE %d \
		PCTUSED %d \
		INITRANS %d \
		MAXTRANS %d \
		TABLESPACE %s \
		STORAGE (INITIAL %d \
		NEXT %d \
		PCTINCREASE %d \
		MINEXTENTS %d \
		MAXEXTENTS %d \
		FREELIST GROUPS %d \
		FREELISTS %d) \
		as SELECT * FROM %s WHERE rownum < 1",
		sTableName,
		tabStorage.iPctFree,
		tabStorage.iPctUsed,
		tabStorage.iIniTrans,
		tabStorage.iMaxTrans,
		tabStorage.sTableSpaceName,
		tabStorage.iInitialExtent,
		tabStorage.iNextExtent,
		tabStorage.iPctIncrease,
		tabStorage.iMinExtents,
		tabStorage.iMaxExtents,
		tabStorage.iFreelistGroups,
		tabStorage.iFreelists,
		sTemplate);

		printf("create table %s as %s\n", sTableName,sTemplate);
 		/* EXEC SQL EXECUTE IMMEDIATE :sDynamic; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )324;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)sDynamic;
   sqlstm.sqhstl[0] = (unsigned long )2048;
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


 	
 		if (sqlca.sqlcode == -955)
 		{
 			return OP_OK;
 		}

 		if (CheckSqlResult ("CREATE TABLE") == OP_ERR)
 			return OP_ERR;

 		printf("table [%s] reference [%s] created\n",
			sTableName,sTemplate);
 		WriteProcMsg("table [%s] reference [%s] created\n",
			sTableName,sTemplate);
 		return OP_OK;
}

int  DupTableExt(char *sTemplate, char *sTableName, char *sTableSpaceName)
{
	TABLE_STORAGE tabStorage;
	char  sDynamic[2048];
	
	/* EXEC SQL SELECT 
			TABLE_NAME,
			TABLESPACE_NAME,
			PCT_FREE,
			PCT_USED,
			INI_TRANS,
			MAX_TRANS,
			INITIAL_EXTENT,
			NEXT_EXTENT,
			MIN_EXTENTS,
			MAX_EXTENTS,
			PCT_INCREASE,
			FREELISTS,
			FREELIST_GROUPS
		INTO :tabStorage
		FROM USER_TABLES
		WHERE TABLE_NAME = :sTemplate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select TABLE_NAME ,TABLESPACE_NAME ,PCT_FREE ,PCT_USED ,INI\
_TRANS ,MAX_TRANS ,INITIAL_EXTENT ,NEXT_EXTENT ,MIN_EXTENTS ,MAX_EXTENTS ,PCT\
_INCREASE ,FREELISTS ,FREELIST_GROUPS into :s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 \
,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13   from USER_TABLES where TABLE_NAME=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )343;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)tabStorage.sTableName;
 sqlstm.sqhstl[0] = (unsigned long )31;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)tabStorage.sTableSpaceName;
 sqlstm.sqhstl[1] = (unsigned long )31;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&tabStorage.iPctFree;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&tabStorage.iPctUsed;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&tabStorage.iIniTrans;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&tabStorage.iMaxTrans;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&tabStorage.iInitialExtent;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&tabStorage.iNextExtent;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&tabStorage.iMinExtents;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&tabStorage.iMaxExtents;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&tabStorage.iPctIncrease;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&tabStorage.iFreelists;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&tabStorage.iFreelistGroups;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)sTemplate;
 sqlstm.sqhstl[13] = (unsigned long )0;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
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


	
	if(CheckSqlResult("GET TEMPLATE STORAGE")<0)
		return OP_ERR;
	
	AllTrim(tabStorage.sTableSpaceName);
	AllTrim(tabStorage.sTableName);
	
	AllTrim(sTableSpaceName);
	if(strlen(sTableSpaceName) != 0)
		strcpy(tabStorage.sTableSpaceName, sTableSpaceName);

	sprintf(sDynamic,
       "CREATE TABLE %s  \
		PCTFREE %d \
		PCTUSED %d \
		INITRANS %d \
		MAXTRANS %d \
		TABLESPACE %s \
		STORAGE (INITIAL %d \
		NEXT %d \
		PCTINCREASE %d \
		MINEXTENTS %d \
		MAXEXTENTS %d \
		FREELIST GROUPS %d \
		FREELISTS %d) \
		as SELECT * FROM %s WHERE rownum < 1",
		sTableName,
		tabStorage.iPctFree,
		tabStorage.iPctUsed,
		tabStorage.iIniTrans,
		tabStorage.iMaxTrans,
		tabStorage.sTableSpaceName,
		tabStorage.iInitialExtent,
		tabStorage.iNextExtent,
		tabStorage.iPctIncrease,
		tabStorage.iMinExtents,
		tabStorage.iMaxExtents,
		tabStorage.iFreelistGroups,
		tabStorage.iFreelists,
		sTemplate);

		printf("create table %s as %s\n", sTableName, sTemplate);
 		/* EXEC SQL EXECUTE IMMEDIATE :sDynamic; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )414;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)sDynamic;
   sqlstm.sqhstl[0] = (unsigned long )2048;
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


 	
 		if (sqlca.sqlcode == -955)
 		{
 			return OP_OK;
 		}

 		if (CheckSqlResult ("CREATE TABLE") == OP_ERR)
 			return OP_ERR;

 		printf("table [%s] reference [%s] created\n",
			sTableName,sTemplate);
		
 		WriteProcMsg("table [%s] reference [%s] created\n",
			sTableName,sTemplate);
 		return OP_OK;
}

int  DupTableIndex(char * sTemplateTable, char * sTableName, char * sIndExt)
{
	static  int  iFirstCall =1;
	INDEX_STORAGE indStorage;
	
	char sDynamic[2048];
	
	if( iFirstCall){
		/* EXEC SQL DECLARE UI_CURSOR CURSOR FOR
		SELECT  
			TABLESPACE_NAME,
			INDEX_NAME,
			UNIQUENESS,
			INI_TRANS,
			MAX_TRANS,
			INITIAL_EXTENT,
			NEXT_EXTENT,
			MIN_EXTENTS,
			MAX_EXTENTS,
			PCT_INCREASE,
			FREELISTS,
			FREELIST_GROUPS
		FROM 
			USER_INDEXES 
		WHERE 
			TABLE_NAME = :sTemplateTable; */ 

			
		/* EXEC SQL DECLARE IC_CURSOR CURSOR FOR 
		SELECT
			COLUMN_NAME
		FROM 
			USER_IND_COLUMNS 
		WHERE 
			INDEX_NAME=:indStorage.sIndexName
		ORDER BY COLUMN_POSITION; */ 

			
		iFirstCall =0;
	}
	
	/* EXEC SQL OPEN UI_CURSOR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0017;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )433;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sTemplateTable;
 sqlstm.sqhstl[0] = (unsigned long )0;
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


	
	if(CheckSqlResult("OPEN USER_INDEX CURSOR")<0)
		return OP_ERR;
	
	/* EXEC SQL FETCH UI_CURSOR INTO 
			:indStorage; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )452;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)indStorage.sTableSpaceName;
 sqlstm.sqhstl[0] = (unsigned long )31;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)indStorage.sIndexName;
 sqlstm.sqhstl[1] = (unsigned long )31;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)indStorage.sUniqueness;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&indStorage.iIniTrans;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&indStorage.iMaxTrans;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&indStorage.iInitialExtent;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&indStorage.iNextExtent;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&indStorage.iMinExtents;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&indStorage.iMaxExtents;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&indStorage.iPctIncrease;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&indStorage.iFreelists;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&indStorage.iFreelistGroups;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
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


	
	if(CheckSqlResult("Fetch USER_INDEX FIRST")<0){
		/* EXEC SQL CLOSE UI_CURSOR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )515;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return OP_ERR;
	}
	
	while(!(iDataNotFound())){
		
		char  sColumnName[31];
		char  sIndColumns[300];
		
		AllTrim(indStorage.sTableSpaceName);
		AllTrim(indStorage.sIndexName);
		AllTrim(indStorage.sUniqueness);

		printf(" index name :[%s]\n",indStorage.sIndexName);
				
		/* EXEC SQL OPEN IC_CURSOR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0018;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )530;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(indStorage.sIndexName);
  sqlstm.sqhstl[0] = (unsigned long )31;
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


		
		if( CheckSqlResult("OPEN USER_INDEX_COLUMNS CUROSR")<0){
			/* EXEC SQL CLOSE UI_CURSOR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )549;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			return OP_ERR;
		}
		
		/* EXEC SQL FETCH IC_CURSOR INTO 
			:sColumnName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )564;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)sColumnName;
  sqlstm.sqhstl[0] = (unsigned long )31;
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



		if( CheckSqlResult("FETCH USER_INDEX_COLUMNS CUROSR")<0){
			/* EXEC SQL CLOSE UI_CURSOR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )583;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			/* EXEC SQL CLOSE IC_CURSOR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )598;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			return OP_ERR;
		}
		
		sIndColumns[0]= '\0';
		
		while( !(iDataNotFound()) ){
			
			
			AllTrim(sColumnName);
			
			strcat( sIndColumns, sColumnName);
			strcat( sIndColumns, ",");
			
			/* EXEC SQL FETCH IC_CURSOR INTO 
				:sColumnName; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )613;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)sColumnName;
   sqlstm.sqhstl[0] = (unsigned long )31;
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



			if( CheckSqlResult("FETCH USER_INDEX_COLUMNS CUROSR")<0){
				/* EXEC SQL CLOSE UI_CURSOR; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )632;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				/* EXEC SQL CLOSE IC_CURSOR; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )647;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				return OP_ERR;
			}
		}
		
		/* EXEC SQL CLOSE IC_CURSOR ; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )662;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		
		/****create index */
		
		if( strlen(sIndColumns)>0){
			
			if( strncmp(indStorage.sUniqueness,"UNIQUE",6) )
				indStorage.sUniqueness[0] = '\0';
				
			sIndColumns[ strlen(sIndColumns)-1] = '\0';
	 		sprintf (sDynamic, 
			"CREATE %s INDEX %s_%s ON %s (%s) \
			INITRANS %d \
			MAXTRANS %d \
			TABLESPACE %s \
			STORAGE (INITIAL %d \
			NEXT %d \
			PCTINCREASE %d \
			MINEXTENTS %d \
			MAXEXTENTS %d \
			FREELIST GROUPS %d \
			FREELISTS %d)" ,
			indStorage.sUniqueness,
			indStorage.sIndexName,
			sIndExt, 
			sTableName,
			sIndColumns,
			indStorage.iIniTrans,
			indStorage.iMaxTrans,
			indStorage.sTableSpaceName,
			indStorage.iInitialExtent,
			indStorage.iNextExtent,
			indStorage.iPctIncrease,
			indStorage.iMinExtents,
			indStorage.iMaxExtents,
			indStorage.iFreelistGroups,
			indStorage.iFreelists
			);
			
	 		/* EXEC SQL EXECUTE IMMEDIATE :sDynamic; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )677;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)sDynamic;
    sqlstm.sqhstl[0] = (unsigned long )2048;
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

	
	 		
	 		if( sqlca.sqlcode == -955)
	 			printf("INDEX EXISTED\n");
	 		else if(CheckSqlResult("Create Index ")<0){
	 			/* EXEC SQL CLOSE UI_CURSOR; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 14;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )696;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	 			/* EXEC SQL CLOSE IC_CURSOR; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 14;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )711;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	 			return OP_ERR;
	 		}
	 		
	 		printf("index [%s_%s]  on table %s(%s) created\n",
				indStorage.sIndexName,sIndExt,
		 		sTableName,sIndColumns);
	 		WriteProcMsg("index [%s_%s]  on table %s(%s) created\n",
				indStorage.sIndexName,sIndExt,
		 		sTableName,sIndColumns);
		}
		/*end of create index*/
		
		/* EXEC SQL FETCH UI_CURSOR INTO 
				:indStorage; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )726;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)indStorage.sTableSpaceName;
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)indStorage.sIndexName;
  sqlstm.sqhstl[1] = (unsigned long )31;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)indStorage.sUniqueness;
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&indStorage.iIniTrans;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&indStorage.iMaxTrans;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&indStorage.iInitialExtent;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&indStorage.iNextExtent;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&indStorage.iMinExtents;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&indStorage.iMaxExtents;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&indStorage.iPctIncrease;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&indStorage.iFreelists;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&indStorage.iFreelistGroups;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
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


		
	}
	/* EXEC SQL CLOSE UI_CURSOR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )789;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return OP_OK;
}

int  DupTableIndexExt(char * sTemplateTable, char * sTableName,
		char * sIndExt, char *sTableSpaceName)
{
	static  int  iFirstCall =1;
	INDEX_STORAGE indStorage;
	
	char sDynamic[2048];

	memset((char *)&indStorage, 0, sizeof(INDEX_STORAGE));	
	if( iFirstCall){
		
		/* EXEC SQL DECLARE EXT_UI_CURSOR CURSOR FOR
		SELECT  
			TABLESPACE_NAME,
			INDEX_NAME,
			UNIQUENESS,
			INI_TRANS,
			MAX_TRANS,
			INITIAL_EXTENT,
			NEXT_EXTENT,
			MIN_EXTENTS,
			MAX_EXTENTS,
			PCT_INCREASE,
			FREELISTS,
			FREELIST_GROUPS
		FROM 
			USER_INDEXES 
		WHERE 
			TABLE_NAME = :sTemplateTable; */ 

			
		if(CheckSqlResult("OPEN USER_INDEX CURSOR")<0)
			return OP_ERR;
			
		printf("hello0.\n");
			
		/* EXEC SQL DECLARE EXT_IC_CURSOR CURSOR FOR 
		SELECT
			COLUMN_NAME
		FROM 
			USER_IND_COLUMNS 
		WHERE 
			INDEX_NAME=:indStorage.sIndexName
		ORDER BY COLUMN_POSITION; */ 

		
		if(CheckSqlResult("OPEN USER_INDEX CURSOR")<0)
			return OP_ERR;
		
		printf("hello1.\n");
		
		iFirstCall =0;
	}
	
	/* EXEC SQL OPEN EXT_UI_CURSOR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0020;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )804;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sTemplateTable;
 sqlstm.sqhstl[0] = (unsigned long )0;
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


	
	printf("hello2.\n");
		
	if(CheckSqlResult("OPEN USER_INDEX CURSOR")<0)
		return OP_ERR;
	
	/* EXEC SQL FETCH EXT_UI_CURSOR INTO 
			:indStorage; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )823;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)indStorage.sTableSpaceName;
 sqlstm.sqhstl[0] = (unsigned long )31;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)indStorage.sIndexName;
 sqlstm.sqhstl[1] = (unsigned long )31;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)indStorage.sUniqueness;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&indStorage.iIniTrans;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&indStorage.iMaxTrans;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&indStorage.iInitialExtent;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&indStorage.iNextExtent;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&indStorage.iMinExtents;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&indStorage.iMaxExtents;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&indStorage.iPctIncrease;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&indStorage.iFreelists;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&indStorage.iFreelistGroups;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
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


	
	if(CheckSqlResult("Fetch USER_INDEX FIRST")<0){
		/* EXEC SQL CLOSE EXT_UI_CURSOR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )886;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return OP_ERR;
	}
	
	while(!(iDataNotFound())){
		
		char  sColumnName[31];
		char  sIndColumns[300];
		
		AllTrim(indStorage.sTableSpaceName);
		AllTrim(indStorage.sIndexName);
		AllTrim(indStorage.sUniqueness);
		
		AllTrim(sTableSpaceName);
		if(strlen(sTableSpaceName) != 0)
			strcpy(indStorage.sTableSpaceName, sTableSpaceName);
		
		printf(" index name :[%s]\n",indStorage.sIndexName);
				
		/* EXEC SQL OPEN EXT_IC_CURSOR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0021;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )901;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(indStorage.sIndexName);
  sqlstm.sqhstl[0] = (unsigned long )31;
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


		
		if( CheckSqlResult("OPEN USER_INDEX_COLUMNS CUROSR")<0){
			/* EXEC SQL CLOSE EXT_UI_CURSOR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )920;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			return OP_ERR;
		}
		
		/* EXEC SQL FETCH EXT_IC_CURSOR INTO 
			:sColumnName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )935;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)sColumnName;
  sqlstm.sqhstl[0] = (unsigned long )31;
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



		if( CheckSqlResult("FETCH USER_INDEX_COLUMNS CUROSR")<0){
			/* EXEC SQL CLOSE EXT_UI_CURSOR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )954;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			/* EXEC SQL CLOSE EXT_IC_CURSOR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )969;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			return OP_ERR;
		}
		
		sIndColumns[0]= '\0';
		
		while( !(iDataNotFound()) ){
			
			
			AllTrim(sColumnName);
			
			strcat( sIndColumns, sColumnName);
			strcat( sIndColumns, ",");
			
			/* EXEC SQL FETCH EXT_IC_CURSOR INTO 
				:sColumnName; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )984;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)sColumnName;
   sqlstm.sqhstl[0] = (unsigned long )31;
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



			if( CheckSqlResult("FETCH USER_INDEX_COLUMNS CUROSR")<0){
				/* EXEC SQL CLOSE EXT_UI_CURSOR; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1003;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				/* EXEC SQL CLOSE EXT_IC_CURSOR; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1018;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				return OP_ERR;
			}
		}
		
		/* EXEC SQL CLOSE EXT_IC_CURSOR ; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1033;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		
		/****create index */
		
		if( strlen(sIndColumns)>0){
			
			if( strncmp(indStorage.sUniqueness,"UNIQUE",6) )
				indStorage.sUniqueness[0] = '\0';
				
			sIndColumns[ strlen(sIndColumns)-1] = '\0';
	 		sprintf (sDynamic, 
			"CREATE %s INDEX %s_%s ON %s (%s) \
			INITRANS %d \
			MAXTRANS %d \
			TABLESPACE %s \
			STORAGE (INITIAL %d \
			NEXT %d \
			PCTINCREASE %d \
			MINEXTENTS %d \
			MAXEXTENTS %d \
			FREELIST GROUPS %d \
			FREELISTS %d)" ,
			indStorage.sUniqueness,
			indStorage.sIndexName,
			sIndExt, 
			sTableName,
			sIndColumns,
			indStorage.iIniTrans,
			indStorage.iMaxTrans,
			indStorage.sTableSpaceName,
			indStorage.iInitialExtent,
			indStorage.iNextExtent,
			indStorage.iPctIncrease,
			indStorage.iMinExtents,
			indStorage.iMaxExtents,
			indStorage.iFreelistGroups,
			indStorage.iFreelists
			);
/*			
printf(" the index sql is\n%s\n",sDynamic);
*/			
	 		/* EXEC SQL EXECUTE IMMEDIATE :sDynamic; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1048;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)sDynamic;
    sqlstm.sqhstl[0] = (unsigned long )2048;
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

	
	 		
	 		if( sqlca.sqlcode == -955)
	 			printf("INDEX EXISTED\n");
	 		else if(CheckSqlResult("Create Index ")<0){
	 			/* EXEC SQL CLOSE EXT_UI_CURSOR; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 14;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1067;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	 			/* EXEC SQL CLOSE EXT_IC_CURSOR; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 14;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1082;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	 			return OP_ERR;
	 		}
	 		
	 		printf("index [%s_%s]  on table %s(%s) created\n",
				indStorage.sIndexName,sIndExt,
		 		sTableName,sIndColumns);
			
	 		WriteProcMsg("index [%s_%s]  on table %s(%s) created\n",
				indStorage.sIndexName,sIndExt,
		 		sTableName,sIndColumns);
		}
		/*end of create index*/
		
		/* EXEC SQL FETCH EXT_UI_CURSOR INTO 
				:indStorage; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1097;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)indStorage.sTableSpaceName;
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)indStorage.sIndexName;
  sqlstm.sqhstl[1] = (unsigned long )31;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)indStorage.sUniqueness;
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&indStorage.iIniTrans;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&indStorage.iMaxTrans;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&indStorage.iInitialExtent;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&indStorage.iNextExtent;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&indStorage.iMinExtents;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&indStorage.iMaxExtents;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&indStorage.iPctIncrease;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&indStorage.iFreelists;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&indStorage.iFreelistGroups;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
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


		
	}
	/* EXEC SQL CLOSE EXT_UI_CURSOR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
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


	return OP_OK;
}

int GetUserPass(char sTemp[],char sUserName[],char sPassword[])
{
        int iOffset;
        char *pTemp;
        if((pTemp=strchr(sTemp,'/'))==NULL) return FALSE;
        if(pTemp==sTemp) return FALSE;
        iOffset=pTemp-sTemp;
        strncpy(sUserName,sTemp,iOffset);
        sUserName[iOffset]=0;
        strcpy(sPassword,&sTemp[iOffset+1]);
        if(strlen(sPassword)==0) return FALSE;
        return TRUE;
}
static int iGetUserPass(char buf[],char sUserName[],char sPassword[],char sConnStr[])
{
	
	char	*pCur,*pPre,sTemp[128];

	strcpy(sTemp,buf);
	pCur=sTemp;
        if((pPre=strchr(pCur,'/'))==NULL) return FALSE;
        *pPre=0;
        strcpy(sUserName,pCur);
        
	pPre++;
	pCur=pPre;
        if((pPre=strchr(pCur,'@'))!=NULL){
        	*pPre=0;
        	pPre++;
        	strcpy(sPassword,pCur);
        	strcpy(sConnStr,pPre);
        }
        else{
	        strcpy(sPassword,pCur);
	        strcpy(sConnStr,"");
        }
        return TRUE;
}
int UpdateBillPwd(char sUserId[],char sPath[])
{
	int l;
	char sConnStr[64];
	FILE *fp=NULL;

	strcpy(sConnStr,"");
	if(GetDbConnStr(atoi(sUserId),sConnStr)!=0) return -1;
	strcat(sConnStr,"\n");
	l=strlen(sConnStr);
	
	if((fp=fopen(sPath,"w"))==NULL) return -1;
	WriteFile(fp,sConnStr,l);
	fclose(fp);

	return 0;    
}

int ReadBillPwd(char sFileName[],char sResult[])
{
   	FILE * fpINI;
   	char  sLine[256];
   	char *sTemp,*pTemp;

   	strcpy(sResult,"");

   	fpINI = fopen(sFileName ,"r");
   	if(fpINI == NULL)    return -1;

	fgets(sLine,256,fpINI);
   	if(feof(fpINI)){
   		fclose(fpINI);
   		return 0;
   	}
   	sTemp = sLine;
   	while( (*sTemp)==' ' || (*sTemp)=='\t' )
   	  sTemp++;      /*skip space and tabs*/
   	pTemp=strchr(sTemp,'#');
        if(pTemp!=NULL)*pTemp=0;

   	pTemp=strchr(sTemp,'\n');
        if(pTemp!=NULL)*pTemp=0;

        AllTrim(sTemp);
   	  
        strcpy(sResult,sTemp);
   	return 0;
}

int GetDbConnStr(int iUserID,char sConnectStr[])
{
	char sUserName[64],sPassword[64],sConnStr[64],sTemp[128];

	strcpy(sConnectStr,"");

/*用默认用户登陆数据库取加密密码*/

	if(GetIniConnStr("loginconnstr",sTemp)<0) return -1;
	
	ERROR_RETURNA((iGetUserPass(sTemp,sUserName,sPassword,sConnStr)==FALSE),
		"用户名/用户密码格式错误,str=%s",sTemp);

	ERROR_RETURNC((ConnectDatabase(sUserName,sPassword,sConnStr)<0),
		"一次登录数据库用户%s,连接串%s,密码%s错误",
		sUserName,sConnStr,sPassword);
	
	/* EXEC SQL SELECT USERNAME,PASSWORD,CONN_STR
		INTO :sUserName,:sPassword,:sConnStr
		FROM BILL_LOGIN_CONFIG
		WHERE USER_ID=:iUserID AND ROWNUM < 2; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select USERNAME ,PASSWORD ,CONN_STR into :b0,:b1,:b2  from \
BILL_LOGIN_CONFIG where (USER_ID=:b3 and ROWNUM<2)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1175;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sUserName;
 sqlstm.sqhstl[0] = (unsigned long )64;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sPassword;
 sqlstm.sqhstl[1] = (unsigned long )64;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sConnStr;
 sqlstm.sqhstl[2] = (unsigned long )64;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&iUserID;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
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


	
	if(CheckSqlResult("获取用户和加密密码")<0) return -1;
	
	ERROR_RETURNA(NoDataFetched,"没有指定用户ID=%d",iUserID);
	
	DisconnectDatabase();

	AllTrim(sUserName);
	AllTrim(sPassword);
	AllTrim(sConnStr);

	if(strcmp(sConnStr,"")!=0)
		sprintf(sConnectStr,"%s/%s@%s",sUserName,sPassword,sConnStr);
	else
		sprintf(sConnectStr,"%s/%s",sUserName,sPassword);

	return 0;
}
int DecodeBillPwd(char sUserName[],char sInPassword[],char sOutPassword[])
{
	int i=0,j=0,l=0,temp=0,ioutpwd=0,ipwd=0;
	char sKey[8],sPwD[8],sTemp[8],sUName[64];
	char sPassWordKey[64];
	
  	
  	strcpy(sPassWordKey,PASSWD_KEY);
  	sPassWordKey[16]=0;
	l=strlen(sInPassword);

	if(l%2!=0){
		strcpy(sOutPassword,"");
		return 0;
	}
	
	for (i=strlen(sUserName);i<l/2;i++)strcat(sUserName," ");

	i=0;
  	while(i<l){
  		strncpy(sPwD,sInPassword+i,2);
		sPwD[2]=0;             
		ipwd=HexStrToInt(sPwD);
		sprintf(sKey,"%d",sPassWordKey[j]);
		temp=ipwd^atoi(sKey);
		
		sprintf(sUName,"%d",sUserName[j]);
		ioutpwd=atoi(sUName)^temp;
		
		strcpy(sTemp,"");
		sprintf(sTemp,"%c",ioutpwd);
  		strcat(sOutPassword,sTemp);
		j++;
		i=i+2;
	}
	return 0;
}

int FastConnect(char sUserId[])
{
	char sUserName[32],sPassword[32],sConnStr[32];
	char sTemp[64],sRealPassword[32],sPath[256],sUserIni[256];
	
	GetAppHome(sPath);
	sprintf(sUserIni,"shell/.billpwd.%s",sUserId);
	strcat(sPath,sUserIni);

	strcpy(sPassword,"");
	strcpy(sConnStr,"");

	if(strchr(sUserId,'/')==NULL){
		if(IsFile(sPath)==FALSE){
			ERROR_RETURNA((UpdateBillPwd(sUserId,sPath)!=0),
				"写.billpwd.%s 文件失败",sUserId);
		}
		ERROR_RETURNA((ReadBillPwd(sPath,sTemp)!=0),"读取%s文件失败",sPath);
	}
	else{
		strcpy(sTemp,sUserId);
	}
	
	ERROR_RETURNA((iGetUserPass(sTemp,sUserName,sRealPassword,sConnStr)==FALSE),
		"用户名/用户密码格式错误,str=%s",sTemp);

	if(strchr(sUserId,'/')==NULL)	/*解密*/
		DecodeBillPwd(sUserName,sRealPassword,sPassword);
	else	strcpy(sPassword,sRealPassword);

	AllTrim(sUserName);
	AllTrim(sPassword);
	AllTrim(sConnStr);

	if(ConnectDatabase(sUserName,sPassword,sConnStr)!=0){
		
		DisconnectDatabase();
	
		ERROR_RETURNA((UpdateBillPwd(sUserId,sPath)!=0),
			"写.billpwd.%s 文件失败",sUserId);
			
		ERROR_RETURNA((ReadBillPwd(sPath,sTemp)!=0),
			"读取.billpwd.%s 文件失败",sUserId);
		
		ERROR_RETURNA((iGetUserPass(sTemp,sUserName,sRealPassword,sConnStr)==FALSE),
			"用户名/用户密码格式错误,str=%s",sTemp);
	
		/*解密*/
		strcpy(sPassword,"");
		DecodeBillPwd(sUserName,sRealPassword,sPassword);	
		return ConnectDatabase(sUserName,sPassword,sConnStr);
	}

/*	strcpy(sUserName,"ucfj");
	strcpy(sPassword,"cal");
	strcpy(sConnStr,"");	*/
	
	return 0;
}
int GetIniConnStr(char sConnDp[],char sConnStr[])
{
	int iRet;
	char sTemp[128],sPath[128];

	GetIniName(sPath);
	
	iRet=ReadString(sPath,"bss","login",sConnDp,sTemp);	

	ERROR_RETURNZ(iRet<0,"读取bill.ini文件失败");
	
	ERROR_RETURNA((strlen(sTemp)==0),"bill.ini->bss->login-%s无对应配置",
		sConnDp);
	strcpy(sConnStr,sTemp);
	return 0;
}
int IniConnect(char sConnDp[])
{
	char sTemp[128];
	
	if(GetIniConnStr(sConnDp,sTemp)<0) return -1;

	return FastConnect(sTemp);
}
int TwiceConnect(int iUserID)
{
	char sUserName[64],sPassword[64],sConnStr[64],sRealPassword[64];

/*用默认用户登陆数据库取加密密码*/
	strcpy(sUserName,"bill_login");
	strcpy(sPassword,"billingsystem");
	strcpy(sConnStr,"local");
	
	ERROR_RETURNC((ConnectDatabase(sUserName,sPassword,sConnStr)<0),
		"一次登录数据库用户%s,连接串%s,密码%s错误",
		sUserName,sConnStr,sPassword);
	
	/* EXEC SQL SELECT USERNAME,PASSWORD,CONN_STR
		INTO :sUserName,:sPassword,:sConnStr
		FROM BILL_LOGIN_CONFIG
		WHERE USER_ID=:iUserID AND
			ROWNUM < 2; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select USERNAME ,PASSWORD ,CONN_STR into :b0,:b1,:b2  from \
BILL_LOGIN_CONFIG where (USER_ID=:b3 and ROWNUM<2)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1206;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sUserName;
 sqlstm.sqhstl[0] = (unsigned long )64;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sPassword;
 sqlstm.sqhstl[1] = (unsigned long )64;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sConnStr;
 sqlstm.sqhstl[2] = (unsigned long )64;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&iUserID;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
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


	
	if(CheckSqlResult("获取用户和加密密码")<0) return -1;
	
	ERROR_RETURNA(NoDataFetched,"没有指定用户ID=%d",iUserID);
	
	DisconnectDatabase();
	
	AllTrim(sUserName);
	AllTrim(sPassword);
	AllTrim(sConnStr);
	
	decodepass(DB_KEY,sPassword,sRealPassword);
	
	ERROR_RETURNB((ConnectDatabase(sUserName,sPassword,sConnStr)<0),
		"二次登录数据库用户%s,连接串%s错误",
		sUserName,sConnStr);
	
	return 0;
	
}
int GetConnStr(char sUserId[])
{
	char sUserName[32],sPassword[32],sConnStr[32];
	char sTemp[64],sRealPassword[32],sPath[128],sUserIni[64];
	
	GetAppHome(sPath);
	sprintf(sUserIni,"shell/.billpwd.%s",sUserId);
	strcat(sPath,sUserIni);

	strcpy(sPassword,"");
	strcpy(sConnStr,"");

	ERROR_RETURNA((ReadBillPwd(sPath,sTemp)!=0),"读取%s文件失败",sPath);
	
	ERROR_RETURNA((iGetUserPass(sTemp,sUserName,sRealPassword,sConnStr)==FALSE),
		"用户名/用户密码格式错误,str=%s",sTemp);

/*解密*/
	DecodeBillPwd(sUserName,sRealPassword,sPassword);

	AllTrim(sUserName);
	AllTrim(sPassword);
	AllTrim(sConnStr);

	printf("%s/%s@%s",sUserName,sPassword,sConnStr);

	return 0;
}

struct RowStruct *MallocRow(int iColNum,int iValueLen)
{
	int iLen;
	struct RowStruct *p;

	iLen=sizeof(struct RowStruct)+sizeof(char*)*iColNum+iValueLen;

	if((p=(struct RowStruct*)malloc(iLen))==NULL) return NULL;
	
	p->pNext=	NULL;
	p->iColNum=	iColNum;
	p->iLen=	iLen;
	p->iFreeLen=	0;
	p->apIndex=	(char**)(((char*)p)+sizeof(struct RowStruct));
	p->pValue=	(char*)&(p->apIndex[iColNum]);

	return p;
}
void DestroyDataSetRow(struct DataSetStruct *pDs)
{
	if(pDs==NULL)	return;
	
	DestroyList((LIST*)pDs->pRow);

	pDs->iRowNum=0;
	pDs->iColNum=0;
	pDs->pRow=pDs->pCur=NULL;
}
int InitColNumAndFieldNames(SQLDA *sdp, struct DataSetStruct *pDs,
	char sMessage[])
{
	char sTemp[256];
	int i,iPrecision,iScale;

	strcpy(sMessage,"");

	pDs->iColNum=sdp->F;

	for (i=0;i<sdp->F;i++){

		pDs->acFieldType[i]=VALUE_TYPE_STR;
		
		switch(sdp->T[i]){
		case TYPE_OF_CHAR:/*字符串，不需要转换*/
		break;
		case TYPE_OF_NUMBER:/*用sqlprc确定整数的精度和值域*/
		case TYPE_OF_NUMBER1:
			sqlprc ((unsigned int*)&(sdp->L[i]),&iPrecision,&iScale);
			if(iPrecision==0)iPrecision=40;
			
			/*如果是整数或者浮点数，则默认转换为char*/
			sdp->T[i]=TYPE_OF_CHAR;
			sdp->L[i]=iPrecision+1;
			if(iScale>0){
				sdp->L[i]++;/*浮点数多一个小数点字节*/
				pDs->acFieldType[i]=VALUE_TYPE_FLOAT;
			}
			else
				pDs->acFieldType[i]=VALUE_TYPE_INT;

		break;
		case TYPE_OF_LONG:		/*数据库LONG类型*/
			sdp->L[i]=240;
		break;
		case TYPE_OF_ROWID:		/*数据库ROWID类型*/
		case TYPE_OF_UNIVERSAL_ROWID:
			sdp->L[i]=18;
			sdp->T[i]=1;
		break;
		case TYPE_OF_DATETIME:		/*数据库DATETIME类型*/
		case TYPE_OF_DATETYPE1:
			sdp->T[i]=TYPE_OF_DATETIME;
			sdp->L[i]=19;
			pDs->acFieldType[i]=VALUE_TYPE_DATE;
		break;
		case TYPE_OF_RAW:		/*数据库RAW类型等*/
		break;
		case TYPE_OF_LONGRAW:
			sdp->L[i]=240;	
		break;
		default:break;
		}
		sprintf(sTemp,"%.*s",sdp->C[i],sdp->S[i]);
		if(strlen(sTemp)>=MAX_VNAME_LEN){
			sprintf(sMessage,"字段%s最大长度大于%d",
				sTemp,MAX_VNAME_LEN);
			return -1;
		}
		strcpy(pDs->asFieldName[i],sTemp);
/*除了LONG RAW and NUMBER外，所有的数据类型都转换成为字符型*/
		if(sdp->T[i]!=TYPE_OF_LONGRAW&&sdp->T[i]!=TYPE_OF_NUMBER)
			sdp->T[i]=TYPE_OF_CHAR;
	}
	return 0;
}
int GetStmtDs(char statement[],struct DataSetStruct *pDs,char sMessage[])
{
	return InitStmtDs(statement,pDs,1,sMessage);
}
int InitStmtDs(char statement[],struct DataSetStruct *pDs,
	int iMaxRow,char sMessage[])
{
	SQLDA *bdp=NULL,*sdp=NULL;
	int aiIndex[MAX_ITEMS];
	char sTemp[MAX_LEN],sRec[MAX_REC_LEN];
	int i,l,iValueLen=0,iExitCode=0,iRowNum=0;
	short int bdpi[MAX_ITEMS],sdpi[MAX_ITEMS];
	char  bdpv[MAX_ITEMS][MAX_LEN],sdpv[MAX_ITEMS][MAX_LEN];
	char *pCurPos;

	struct RowStruct *pRow;

/*做一些输出变量的初始化*/
	strcpy(sMessage,"");
	pDs->iColNum=0;
	pDs->iRowNum=0;
	pDs->pRow=pDs->pCur=NULL;

/*分配BIND描述符*/
	if((bdp=sqlald(MAX_ITEMS,MAX_VNAME_LEN,MAX_INAME_LEN))==NULL){
		sprintf(sMessage,"错误分配内存BDP");
		goto __err_exit;
	}
/*分配SELECT表述符*/
	if((sdp=sqlald(MAX_ITEMS,MAX_VNAME_LEN,MAX_INAME_LEN))==NULL){
		sprintf(sMessage,"错误分配内存SDP");
		goto __err_exit;
	}
/*初始化BIND和SELECT描述符的I和V数组变量*/
	sdp->N=MAX_ITEMS;
	for(i=0;i<MAX_ITEMS;i++){
		bdp->I[i]=&bdpi[i];
		sdp->I[i]=&sdpi[i];
		bdp->V[i]=(char*)(&bdpv[i]);
		sdp->V[i]=(char*)(&sdpv[i]);
	}
/*调用PREPARE编译动态SQL*/
	/* EXEC SQL PREPARE S FROM :statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1237;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)statement;
 sqlstm.sqhstl[0] = (unsigned long )0;
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


	if(CheckSqlResult("通用SELECT PREPARE失败")<0) goto __err_exit;

/*为PREPARE的S申明光标*/
	/* EXEC SQL DECLARE C CURSOR FOR S; */ 

	if(CheckSqlResult("通用SELECT DECLARE CURSOR失败")<0) goto __err_exit;

/*将SELECT LIST和PREPARE的编译结果绑定,*/
	/* EXEC SQL DESCRIBE SELECT LIST FOR S INTO sdp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1256;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sdp;
 sqlstm.sqhstl[0] = (unsigned long )0;
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


	if(CheckSqlResult("通用SELECT DESCRIBE SELECT LIST命令失败")<0)
		goto __err_exit;
	if(sdp->F<0){
		sprintf(sMessage,"SELECT的列数太多,当前列数%d,最大列数%d",
			-sdp->F,MAX_ITEMS);
		goto __err_exit;
	}
	sdp->N=	sdp->F;

/*初始化DataSet结构中的ColNum和asFieldName成员*/
	if(InitColNumAndFieldNames(sdp,pDs,sMessage)<0) goto __err_exit;

/*打开游标和执行该语句，如果该语句是SELECT，则在OPEN之后处理结果*/
	bdp->N=0;
	/* EXEC SQL OPEN C USING DESCRIPTOR bdp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1275;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)bdp;
 sqlstm.sqhstl[0] = (unsigned long )0;
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


	if(CheckSqlResult("通用SELECT 打开 CURSOR失败")<0) goto __err_exit;

/*做一个FETCH循环获取字段内容*/
	while(1){
		/* EXEC SQL FETCH C USING DESCRIPTOR sdp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1294;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)sdp;
  sqlstm.sqhstl[0] = (unsigned long )0;
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


		if(NoDataFetched) break;

		/*获取填数的区域*/
		pCurPos=&(sRec[0]);
		
		/*将记录填入本地变量中*/
		iValueLen=0;
		for(i=0;i<sdp->F;i++){

			/*如果字段为空则直接设置为空*/
			if(*(sdp->I[i])==-1){
				aiIndex[i]=-1;
				continue;
			}
			aiIndex[i]=iValueLen;
			
			l=sdp->L[i];
			memcpy((void*)sTemp,(void*)(sdp->V[i]),l);
			sTemp[l]=0;
			AllTrim(sTemp);
			
			l=GenAsncharByStrchar(sTemp,pCurPos);
			
			iValueLen+=l;
			pCurPos+=l;
			
			if(iValueLen>=(MAX_REC_LEN-MAX_LEN)){
				sprintf(sMessage,"行记录太长cur=%d,max=%d",
					iValueLen,(MAX_REC_LEN-MAX_LEN));
				goto __err_exit;
			}

		}
		
		/*分配行结构*/
		if((pRow=(struct RowStruct *)MallocRow(sdp->F,iValueLen))==NULL){
			sprintf(sMessage,"分配行记录内存失败");
			goto __err_exit;
		}
		/*将本地变量的结果移动到行中*/
		for(i=0;i<sdp->F;i++){
			if(aiIndex[i]!=-1)
				pRow->apIndex[i]=pRow->pValue+aiIndex[i];
			else
				pRow->apIndex[i]=NULL;
		}
		/*将数据移到行中*/
		memcpy((void*)(pRow->pValue),(void*)sRec,iValueLen);
		
		/*将获取到的行插入到DataSet结构中*/
		InsertList((LIST**)&(pDs->pRow),(LIST*)pRow);
		iRowNum++;

		if(iMaxRow!=-1&&iRowNum>=iMaxRow) break;
	}
	/*将获取到的记录导顺序出去*/
	ReverseList((LIST**)&(pDs->pRow));
	pDs->pCur=pDs->pRow;
	pDs->iRowNum=iRowNum;
	iExitCode=iRowNum;
	goto __corr_exit;
__err_exit:
	iExitCode=-1;
__corr_exit:
	if(bdp!=NULL)	sqlclu(bdp);
	if(sdp!=NULL)	sqlclu(sdp);
	/* EXEC SQL CLOSE C; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1313;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return iExitCode;
}

void PrintDs(struct DataSetStruct *pDs)
{
	int i,l,n,n1;
	char	*p,sTemp[1024];
	struct RowStruct *ptHead,*pTemp;

	l=0;
	for(i=0;i<pDs->iColNum;i++){
		if(i==0)l+=sprintf(sTemp+l,"%s\t",pDs->asFieldName[i]);
		else	l+=sprintf(sTemp+l,",%s\t",pDs->asFieldName[i]);
	}
	strcat(sTemp,"\n");
	printf(sTemp);
	
	for(i=0;i<l;i++) printf("-");
	printf("\n");
	
	ptHead=pDs->pRow;
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		for(i=0;i<pTemp->iColNum;i++){

			p=pTemp->apIndex[i];
			if(p!=NULL){
				n1=DecodeLenItem((unsigned char*)p,&n);
				p+=n1;
				sprintf(sTemp,"%s",p);
			}
			else
				strcpy(sTemp,"");

			printf("%s\t",sTemp);
		}
		printf("\n");
	}
}
int GetColPos(struct DataSetStruct *pDs,char sColName[])
{
	int i=0;
	
	for(i=0;i<pDs->iColNum;i++)
		if(strcmp(sColName,pDs->asFieldName[i])==0)
			return i;
	return -1;
}

int EofDs(struct DataSetStruct *pDs)
{
	if(pDs->pCur!=NULL) return false;
	return true;
}

void NextDs(struct DataSetStruct *pDs)
{
	if(pDs->pCur!=NULL) pDs->pCur=pDs->pCur->pNext;
}

char *GetCurRowFieldValue(struct DataSetStruct *pDs,char sFieldName[])
{
	int i;
	char *p;
	struct RowStruct *pRow;

	if((pRow=pDs->pCur)==NULL)	return NULL;

	if((i=GetColPos(pDs,sFieldName))<0) return NULL;

	p=pRow->apIndex[i];

	return p+DecodeLenItem((unsigned char*)p,&i);
}
char *GetIndRowFieldValue(struct DataSetStruct *pDs,int iIndex,
	char sFieldName[])
{
	int i=0;
	char *p;
	struct RowStruct *pRow;

	pRow=pDs->pRow;
	while(pRow!=NULL){
		if(i>=iIndex) break;
		pRow=pRow->pNext;
	}
	if(pRow==NULL) return NULL;
	if((i=GetColPos(pDs,sFieldName))<0) return NULL;

	p=pRow->apIndex[i];
	
	return p+DecodeLenItem((unsigned char*)p,&i);
}
void InitRowColIndex(struct RowStruct *pRow,int aiIndex[])
{
	char *p;
	int i,l,l1,iLen;
	
	iLen=0;
	for(i=0;i<pRow->iColNum;i++){
		p=pRow->apIndex[i];
		if(p==NULL){
			aiIndex[i]=-1;
			continue;
		}
		/*获取内容的长度和长度的长度*/
		l1=DecodeLenItem((unsigned char*)p,&l);
		iLen+=l+l1;
		aiIndex[i]=iLen;
	}
}
void ResetRowColIndex(struct RowStruct *pRow,int aiIndex[])
{
	int i,iLen=0;
		
	pRow->pValue=(char*)&(pRow->apIndex[pRow->iColNum]);
	
	for(i=0;i<pRow->iColNum;i++){
		if(aiIndex[i]==-1)
			pRow->apIndex[i]=NULL;
		else
			pRow->apIndex[i]=pRow->pValue+aiIndex[i];
		if(aiIndex[i]!=-1) iLen+=aiIndex[i];
	}
	pRow->iLen=iLen;
}
void ShrinkRow(struct RowStruct **ppRow)
{
	struct RowStruct *pRow=*ppRow;
	char sRec[MAX_REC_LEN],*pCurPos;
	int aiIndex[MAX_ITEMS];
	
	if(pRow==NULL) return;

	if(pRow->iFreeLen*100/pRow->iLen<20)	return;
	
	pCurPos=&(sRec[0]);
	
	InitRowColIndex(pRow,aiIndex);
	
	if((pRow=realloc(pRow,pRow->iLen))==NULL) return;
	
	ResetRowColIndex(pRow,aiIndex);
	
	memcpy((void*)(pRow->pValue),(void*)sRec,pRow->iLen);
	*ppRow=pRow;
}
void SetRowFieldValue(struct DataSetStruct *pDs,struct RowStruct **ppCur,
	char sFieldName[],char sValue[])
{
	int l,l1,n,n1,i,aiIndex[MAX_ITEMS];
	char *p,*pEnd,sTemp[3];
	struct RowStruct *pCur=*ppCur;
	
/*没找到这个字段则退出*/
	if(pCur==NULL) return;
	if((i=GetColPos(pDs,sFieldName))<0) return;

/*其中1表示\0,3表示最大的长度编码*/
	l=strlen(sValue)+1;
	l1=GenAsncharLen(l,(unsigned char*)sTemp);
	
	p=pCur->apIndex[i];
	if(p==NULL)	n1=n=0;
	else		n1=DecodeLenItem((unsigned char*)p,&n);
	
	if(l>=(n+n1)){/*新填入的字段比原来的字段大则需要新增加内存*/
	
		InitRowColIndex(pCur,aiIndex);
		
		if((pCur=realloc((void*)pCur,pCur->iLen+l+l1))==NULL) return;
		
		ResetRowColIndex(pCur,aiIndex);

		/*将字段添加到最后*/
		pEnd=((char*)pCur)+pCur->iLen;

		memcpy((void*)pEnd,sTemp,l1);
		memcpy((void*)(pEnd+l1),sValue,l);
		
		pCur->apIndex[i]=pEnd;
		
		pCur->iFreeLen+=n+n1;/*空余的字段增加*/
		pCur->iLen+=l+l1;
		
		if(pCur->iFreeLen*100/pCur->iLen>=20)	ShrinkRow(&pCur);
	}
}
void SetCurRowFieldValue(struct DataSetStruct *pDs,char sFieldName[],
	char sValue[])
{
	struct RowStruct *pCur,*pPre,*pTemp;
	
	pTemp=pDs->pCur;
	
	SetRowFieldValue(pDs,&(pDs->pCur),sFieldName,sValue);
	
	if(pDs->pCur==pTemp) return;/*百分之99.99%就是这种情况*/
	
	pCur=pDs->pRow;/*如果当前记录就是第一行*/
	if(pCur==pTemp){
		pDs->pRow=pDs->pCur;
		return;
	}
	/*如果不是第一行则找到相应行记录更新之*/
	while(pCur!=NULL){
	
		pPre=pCur;
		pCur=pCur->pNext;
		
		if(pCur==pTemp){
			pPre->pNext=pDs->pCur;
			break;
		}
	}
}
void SetIndRowFieldValue(struct DataSetStruct *pDs,int iIndex,
	char sFieldName[],char sValue[])
{
	int i;
	struct RowStruct *pPre,*pCur,*pTemp;
	
	if(iIndex==0){
		pTemp=pDs->pRow;
		SetRowFieldValue(pDs,&(pDs->pRow),sFieldName,sValue);
		if(pDs->pCur==pTemp) pDs->pCur=pDs->pRow;
		
		return;
	}

	i=1;
	pPre=pDs->pRow;
	pCur=pPre->pNext;
	
	while(pCur!=NULL){

		if(i>=iIndex){
			pTemp=pPre->pNext;
			SetRowFieldValue(pDs,&(pPre->pNext),sFieldName,sValue);
			if(pDs->pCur==pTemp) pDs->pCur=pPre->pNext;
			break;
		}
		pPre=pCur;
		pCur=pCur->pNext;
	}
}

