
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
           char  filnam[10];
};
static struct sqlcxp sqlfpn =
{
    9,
    "dbsupp.pc"
};


static unsigned int sqlctx = 36219;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
5,0,0,1,0,0,17,45,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,51,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,68,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,76,0,0,14,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
125,0,0,1,0,0,15,103,0,0,0,0,0,1,0,
140,0,0,2,0,0,17,187,0,0,1,1,0,1,0,1,97,0,0,
159,0,0,2,0,0,45,193,0,0,0,0,0,1,0,
174,0,0,2,0,0,13,199,0,0,14,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,
245,0,0,2,0,0,15,217,0,0,0,0,0,1,0,
260,0,0,2,0,0,15,220,0,0,0,0,0,1,0,
275,0,0,3,0,0,17,284,0,0,1,1,0,1,0,1,97,0,0,
294,0,0,3,0,0,21,287,0,0,14,14,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,
365,0,0,4,0,0,17,330,0,0,1,1,0,1,0,1,97,0,0,
384,0,0,4,0,0,45,336,0,0,0,0,0,1,0,
399,0,0,4,0,0,13,342,0,0,11,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
458,0,0,4,0,0,15,357,0,0,0,0,0,1,0,
473,0,0,4,0,0,15,360,0,0,0,0,0,1,0,
488,0,0,5,0,0,17,414,0,0,1,1,0,1,0,1,97,0,0,
507,0,0,5,0,0,21,417,0,0,11,11,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
566,0,0,6,0,0,17,460,0,0,1,1,0,1,0,1,97,0,0,
585,0,0,6,0,0,45,466,0,0,0,0,0,1,0,
600,0,0,6,0,0,13,472,0,0,14,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
671,0,0,6,0,0,15,490,0,0,0,0,0,1,0,
686,0,0,6,0,0,15,493,0,0,0,0,0,1,0,
701,0,0,7,0,0,17,555,0,0,1,1,0,1,0,1,97,0,0,
720,0,0,7,0,0,21,558,0,0,14,14,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,
791,0,0,8,0,0,17,606,0,0,1,1,0,1,0,1,97,0,0,
810,0,0,8,0,0,45,612,0,0,0,0,0,1,0,
825,0,0,8,0,0,13,618,0,0,16,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,
904,0,0,8,0,0,15,638,0,0,0,0,0,1,0,
919,0,0,8,0,0,15,641,0,0,0,0,0,1,0,
934,0,0,9,0,0,17,704,0,0,1,1,0,1,0,1,97,0,0,
953,0,0,9,0,0,21,707,0,0,16,16,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,
1032,0,0,1,0,0,17,756,0,0,1,1,0,1,0,1,97,0,0,
1051,0,0,1,0,0,45,762,0,0,0,0,0,1,0,
1066,0,0,1,0,0,13,768,0,0,14,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,
1137,0,0,1,0,0,15,786,0,0,0,0,0,1,0,
1152,0,0,1,0,0,15,789,0,0,0,0,0,1,0,
1167,0,0,10,0,0,17,854,0,0,1,1,0,1,0,1,97,0,0,
1186,0,0,10,0,0,21,857,0,0,15,15,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,
1261,0,0,11,0,0,17,919,0,0,1,1,0,1,0,1,97,0,0,
1280,0,0,11,0,0,21,922,0,0,13,13,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1347,0,0,12,0,0,17,984,0,0,1,1,0,1,0,1,97,0,0,
1366,0,0,12,0,0,21,987,0,0,14,14,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,
1437,0,0,13,0,0,17,1032,0,0,1,1,0,1,0,1,97,0,0,
1456,0,0,13,0,0,45,1038,0,0,0,0,0,1,0,
1471,0,0,13,0,0,13,1044,0,0,12,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
1534,0,0,13,0,0,15,1060,0,0,0,0,0,1,0,
1549,0,0,13,0,0,15,1063,0,0,0,0,0,1,0,
1564,0,0,14,0,0,17,1120,0,0,1,1,0,1,0,1,97,0,0,
1583,0,0,14,0,0,21,1123,0,0,12,12,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1646,0,0,15,0,0,17,1161,0,0,1,1,0,1,0,1,97,0,0,
1665,0,0,15,0,0,45,1167,0,0,0,0,0,1,0,
1680,0,0,15,0,0,13,1173,0,0,7,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,
1723,0,0,15,0,0,15,1184,0,0,0,0,0,1,0,
1738,0,0,15,0,0,15,1187,0,0,0,0,0,1,0,
1753,0,0,16,0,0,17,1230,0,0,1,1,0,1,0,1,97,0,0,
1772,0,0,16,0,0,21,1233,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,
1815,0,0,17,139,0,4,1255,0,0,2,1,0,1,0,2,97,0,0,1,97,0,0,
1838,0,0,18,104,0,4,1264,0,0,2,1,0,1,0,2,97,0,0,1,97,0,0,
1861,0,0,19,122,0,4,1276,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,
1888,0,0,20,147,0,4,1297,0,0,2,1,0,1,0,2,97,0,0,1,97,0,0,
1911,0,0,21,108,0,4,1306,0,0,2,1,0,1,0,2,97,0,0,1,97,0,0,
1934,0,0,22,126,0,4,1318,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,
1961,0,0,23,122,0,4,1338,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,
1988,0,0,24,109,0,4,1357,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
2011,0,0,25,49,0,4,1375,0,0,1,0,0,1,0,2,3,0,0,
2030,0,0,26,105,0,4,1394,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2061,0,0,27,135,0,4,1414,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2092,0,0,28,130,0,4,1435,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
2123,0,0,29,96,0,4,1443,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,
2150,0,0,30,138,0,4,1465,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2181,0,0,31,138,0,4,1483,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2212,0,0,32,138,0,4,1501,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2243,0,0,33,141,0,4,1520,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2274,0,0,34,426,0,4,1536,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
2297,0,0,35,0,0,17,1578,0,0,1,1,0,1,0,1,97,0,0,
2316,0,0,35,0,0,45,1582,0,0,0,0,0,1,0,
2331,0,0,35,0,0,13,1586,0,0,4,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2362,0,0,35,0,0,15,1596,0,0,0,0,0,1,0,
2377,0,0,36,0,0,17,1627,0,0,1,1,0,1,0,1,97,0,0,
2396,0,0,36,0,0,45,1631,0,0,0,0,0,1,0,
2411,0,0,36,0,0,13,1635,0,0,4,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2442,0,0,36,0,0,15,1645,0,0,0,0,0,1,0,
2457,0,0,37,0,0,17,1690,0,0,1,1,0,1,0,1,97,0,0,
2476,0,0,37,0,0,45,1694,0,0,0,0,0,1,0,
2491,0,0,37,0,0,13,1699,0,0,4,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,
2522,0,0,37,0,0,15,1713,0,0,0,0,0,1,0,
2537,0,0,38,0,0,17,1739,0,0,1,1,0,1,0,1,97,0,0,
2556,0,0,38,0,0,45,1743,0,0,0,0,0,1,0,
2571,0,0,38,0,0,13,1749,0,0,2,0,0,1,0,2,3,0,0,2,97,0,0,
2594,0,0,38,0,0,15,1759,0,0,0,0,0,1,0,
2609,0,0,39,156,0,4,1769,0,0,3,1,0,1,0,2,97,0,0,2,3,0,0,1,97,0,0,
2636,0,0,40,0,0,17,1806,0,0,1,1,0,1,0,1,97,0,0,
2655,0,0,40,0,0,45,1812,0,0,0,0,0,1,0,
2670,0,0,40,0,0,15,1829,0,0,0,0,0,1,0,
2685,0,0,40,0,0,13,1837,0,0,8,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,
2732,0,0,40,0,0,15,1858,0,0,0,0,0,1,0,
2747,0,0,41,0,0,17,1989,0,0,1,1,0,1,0,1,97,0,0,
2766,0,0,41,0,0,45,1995,0,0,0,0,0,1,0,
2781,0,0,41,0,0,13,2001,0,0,11,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2840,0,0,41,0,0,15,2016,0,0,0,0,0,1,0,
2855,0,0,41,0,0,15,2019,0,0,0,0,0,1,0,
2870,0,0,42,0,0,17,2073,0,0,1,1,0,1,0,1,97,0,0,
2889,0,0,42,0,0,21,2076,0,0,11,11,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2948,0,0,43,184,0,3,2101,0,0,7,7,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,
2991,0,0,44,76,0,4,2150,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
3014,0,0,45,50,0,5,2162,0,0,1,1,0,1,0,1,3,0,0,
3033,0,0,46,81,0,5,2175,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
3060,0,0,47,0,0,17,2556,0,0,1,1,0,1,0,1,97,0,0,
3079,0,0,47,0,0,21,2559,0,0,17,17,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,
3162,0,0,48,129,0,4,2744,0,0,4,3,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
3193,0,0,49,95,0,4,2752,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,
3220,0,0,6,0,0,17,2836,0,0,1,1,0,1,0,1,97,0,0,
3239,0,0,6,0,0,45,2842,0,0,0,0,0,1,0,
3254,0,0,6,0,0,15,2859,0,0,0,0,0,1,0,
3269,0,0,6,0,0,13,2867,0,0,14,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,
3340,0,0,6,0,0,15,2894,0,0,0,0,0,1,0,
3355,0,0,8,0,0,17,2983,0,0,1,1,0,1,0,1,97,0,0,
3374,0,0,8,0,0,45,2989,0,0,0,0,0,1,0,
3389,0,0,8,0,0,15,3006,0,0,0,0,0,1,0,
3404,0,0,8,0,0,13,3014,0,0,16,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,
3483,0,0,8,0,0,15,3043,0,0,0,0,0,1,0,
3498,0,0,50,0,0,17,3153,0,0,1,1,0,1,0,1,97,0,0,
3517,0,0,50,0,0,21,3156,0,0,9,9,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
3568,0,0,51,0,0,17,3197,0,0,1,1,0,1,0,1,97,0,0,
3587,0,0,51,0,0,45,3203,0,0,0,0,0,1,0,
3602,0,0,51,0,0,13,3210,0,0,9,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
3653,0,0,51,0,0,15,3223,0,0,0,0,0,1,0,
3668,0,0,51,0,0,15,3226,0,0,0,0,0,1,0,
3683,0,0,52,0,0,17,3249,0,0,1,1,0,1,0,1,97,0,0,
3702,0,0,52,0,0,45,3255,0,0,0,0,0,1,0,
3717,0,0,52,0,0,13,3258,0,0,1,0,0,1,0,2,3,0,0,
3736,0,0,52,0,0,15,3263,0,0,0,0,0,1,0,
3751,0,0,52,0,0,15,3267,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>


/*批量数据动态从BILLING_LOG中用结构缓冲方式取数据*/
int EGetBillingLogToStruct(struct BillingLogStruct *p,
	struct BillingLogStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				CNT,\n\
				FILE_NAME,\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				to_char(DATA_DATE,'yyyymmddhh24miss'),\n\
				SEQ,\n\
				ORI_FILE_NAME,\n\
				nvl(FILE_TYPE,'-1'),\n\
				nvl(TACHE_ID,-1),\n\
				nvl(APP_ID,'-1')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE BILLING_LOGSCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE BILLING_LOGSCR BILLING_LOGCR");

		/* EXEC SQL DECLARE BILLING_LOGCR CURSOR FOR BILLING_LOGSCR; */ 

		CheckSqlError("Declare BILLING_LOGCR");

		/* EXEC SQL OPEN BILLING_LOGCR; */ 

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


		CheckSqlError("Open BILLING_LOGCR;");


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

		/* EXEC SQL CLOSE BILLING_LOGCR; */ 

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
		/* EXEC SQL FETCH BILLING_LOGCR INTO
			:pSource->aiInputID,
			:pSource->asSourceID,
			:pSource->asModule,
			:pSource->asState,
			:pSource->aiCnt,
			:pSource->asFileName,
			:pSource->asDealBeginDate,
			:pSource->asDealEndDate,
			:pSource->asDataDate,
			:pSource->aiSeq,
			:pSource->asOriFileName,
			:pSource->asFileType,
			:pSource->aiTacheID,
			:pSource->asAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )54;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )4;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )41;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )15;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asDataDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiSeq);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asOriFileName);
  sqlstm.sqhstl[10] = (unsigned long )81;
  sqlstm.sqhsts[10] = (         int  )81;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )6;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[13] = (unsigned long )11;
  sqlstm.sqhsts[13] = (         int  )11;
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


		CheckSqlError("Fetch BILLING_LOGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE BILLING_LOGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )125;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=BILLING_LOG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iInputID=			pSource->aiInputID[iCurPos];

		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);
		strcpy(p->sModule,		pSource->asModule[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];

		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sDealBeginDate,	pSource->asDealBeginDate[iCurPos]);
		strcpy(p->sDealEndDate,		pSource->asDealEndDate[iCurPos]);
		strcpy(p->sDataDate,		pSource->asDataDate[iCurPos]);

		p->iSeq=			pSource->aiSeq[iCurPos];

		strcpy(p->sOriFileName,		pSource->asOriFileName[iCurPos]);
		strcpy(p->sFileType,		pSource->asFileType[iCurPos]);

		p->iTacheID=			pSource->aiTacheID[iCurPos];

		strcpy(p->sAppID,		pSource->asAppID[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sState);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sDataDate);
		AllTrim(p->sOriFileName);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}


/*单条数据从用动态SQL从ACCT_LOG取数据*/
int SDGetAcctLogToStruct(struct AcctLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				BYTE,\n\
				CNT,\n\
				FILE_NAME,\n\
				TABLE_NAME,\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				to_char(DATA_DATE,'yyyymmddhh24miss'),\n\
				nvl(OPER_TYPE,' '),\n\
				nvl(FILE_TYPE,' '),\n\
				nvl(TACHE_ID,-1),\n\
				nvl(APP_ID,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ACCT_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )140;
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


		CheckSqlError(" PREPARE ACCT_LOGSCR ACCT_LOGCR");

		/* EXEC SQL DECLARE ACCT_LOGCR CURSOR FOR ACCT_LOGSCR; */ 

		CheckSqlError("Declare ACCT_LOGCR");

		/* EXEC SQL OPEN ACCT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )159;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ACCT_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH ACCT_LOGCR INTO
			:p->sSourceID,
			:p->sModule,
			:p->sState,
			:p->iByte,
			:p->iCnt,
			:p->sFileName,
			:p->sTableName,
			:p->sDealBeginDate,
			:p->sDealEndDate,
			:p->sDataDate,
			:p->sOperType,
			:p->sFileType,
			:p->iTacheID,
			:p->sAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )174;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sTableName);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sOperType);
  sqlstm.sqhstl[10] = (unsigned long )4;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[13] = (unsigned long )11;
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


		CheckSqlError("Fetch ACCT_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE ACCT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )245;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE ACCT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )260;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sState);
		AllTrim(p->sFileName);
		AllTrim(p->sTableName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sDataDate);
		AllTrim(p->sOperType);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	return TRUE;
}

/*单条数据动态SQL向ACCT_LOG写数据*/
int SDInsertStructToAcctLog(struct AcctLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				BYTE,\n\
				CNT,\n\
				FILE_NAME,\n\
				TABLE_NAME,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				DATA_DATE,\n\
				OPER_TYPE,\n\
				FILE_TYPE,\n\
				TACHE_ID,\n\
				APP_ID)\n\
			VALUES (\n\
				:sSourceID,\n\
				:sModule,\n\
				:sState,\n\
				:iByte,\n\
				:iCnt,\n\
				:sFileName,\n\
				:sTableName,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				to_date(:sDataDate,'yyyymmddhh24miss'),\n\
				:sOperType,\n\
				:sFileType,\n\
				:iTacheID,\n\
				:sAppID\n\
			)",sTableName);

		/* EXEC SQL PREPARE ACCT_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )275;
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


		if(CheckSqlResult("Prepare insert statement ACCT_LOG")<0) return -1;

		/* EXEC SQL EXECUTE ACCT_LOGTRG USING
				:p->sSourceID,
				:p->sModule,
				:p->sState,
				:p->iByte,
				:p->iCnt,
				:p->sFileName,
				:p->sTableName,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sDataDate,
				:p->sOperType,
				:p->sFileType,
				:p->iTacheID,
				:p->sAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )294;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sTableName);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sOperType);
  sqlstm.sqhstl[10] = (unsigned long )4;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[13] = (unsigned long )11;
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


		if(CheckSqlResult("Dyn insert into ACCT_LOG")<0) return -1;

	return 0;
}
/*单条数据从用动态SQL从PICK_LOG取数据*/
int SDGetPickLogToStruct(struct PickLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				BYTE,\n\
				FILE_NAME,\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				SEQ,\n\
				STATE,\n\
				nvl(FILE_TYPE,'-1'),\n\
				nvl(TACHE_ID,-1),\n\
				nvl(APP_ID,'-1')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PICK_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )365;
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


		CheckSqlError(" PREPARE PICK_LOGSCR PICK_LOGCR");

		/* EXEC SQL DECLARE PICK_LOGCR CURSOR FOR PICK_LOGSCR; */ 

		CheckSqlError("Declare PICK_LOGCR");

		/* EXEC SQL OPEN PICK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )384;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PICK_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH PICK_LOGCR INTO
			:p->iInputID,
			:p->sSourceID,
			:p->iByte,
			:p->sFileName,
			:p->sDealBeginDate,
			:p->sDealEndDate,
			:p->iSeq,
			:p->sState,
			:p->sFileType,
			:p->iTacheID,
			:p->sAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )399;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[5] = (unsigned long )15;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iSeq);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
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


		CheckSqlError("Fetch PICK_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE PICK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )458;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE PICK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )473;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sSourceID);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sState);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	return TRUE;
}

/*单条数据动态SQL向PICK_LOG写数据*/
int SDInsertStructToPickLog(struct PickLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				BYTE,\n\
				FILE_NAME,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				SEQ,\n\
				STATE,\n\
				FILE_TYPE,\n\
				TACHE_ID,\n\
				APP_ID)\n\
			VALUES (\n\
				:iInputID,\n\
				:sSourceID,\n\
				:iByte,\n\
				:sFileName,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				:iSeq,\n\
				:sState,\n\
				:sFileType,\n\
				:iTacheID,\n\
				:sAppID\n\
			)",sTableName);

		/* EXEC SQL PREPARE PICK_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )488;
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


		if(CheckSqlResult("Prepare insert statement PICK_LOG")<0) return -1;

		/* EXEC SQL EXECUTE PICK_LOGTRG USING
				:p->iInputID,
				:p->sSourceID,
				:p->iByte,
				:p->sFileName,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->iSeq,
				:p->sState,
				:p->sFileType,
				:p->iTacheID,
				:p->sAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )507;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[5] = (unsigned long )15;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iSeq);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
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


		if(CheckSqlResult("Dyn insert into PICK_LOG")<0) return -1;

	return 0;
}
/*单条数据从用动态SQL从PREP_LOG取数据*/
int SDGetPrepLogToStruct(struct PrepLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				CNT,\n\
				FILE_NAME,\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				to_char(DATA_DATE,'yyyymmddhh24miss'),\n\
				SEQ,\n\
				ORI_FILE_NAME,\n\
				nvl(FILE_TYPE,' '),\n\
				nvl(APP_ID,' '),\n\
				nvl(TACHE_ID,0)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PREP_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )566;
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


		CheckSqlError(" PREPARE PREP_LOGSCR PREP_LOGCR");

		/* EXEC SQL DECLARE PREP_LOGCR CURSOR FOR PREP_LOGSCR; */ 

		CheckSqlError("Declare PREP_LOGCR");

		/* EXEC SQL OPEN PREP_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )585;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PREP_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH PREP_LOGCR INTO
			:p->iInputID,
			:p->sSourceID,
			:p->sModule,
			:p->sState,
			:p->iCnt,
			:p->sFileName,
			:p->sDealBeginDate,
			:p->sDealEndDate,
			:p->sDataDate,
			:p->iSeq,
			:p->sOriFileName,
			:p->sFileType,
			:p->sAppID,
			:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )600;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iSeq);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sOriFileName);
  sqlstm.sqhstl[10] = (unsigned long )81;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[12] = (unsigned long )11;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
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


		CheckSqlError("Fetch PREP_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE PREP_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )671;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE PREP_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )686;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sState);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sDataDate);
		AllTrim(p->sOriFileName);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	return TRUE;
}
/*单条数据动态SQL向PREP_LOG写数据*/
int SDInsertStructToPrepLog(struct PrepLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				CNT,\n\
				FILE_NAME,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				DATA_DATE,\n\
				SEQ,\n\
				ORI_FILE_NAME,\n\
				FILE_TYPE,\n\
				APP_ID,\n\
				TACHE_ID)\n\
			VALUES (\n\
				:iInputID,\n\
				:sSourceID,\n\
				:sModule,\n\
				:sState,\n\
				:iCnt,\n\
				:sFileName,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				to_date(:sDataDate,'yyyymmddhh24miss'),\n\
				:iSeq,\n\
				:sOriFileName,\n\
				:sFileType,\n\
				:sAppID,\n\
				:iTacheID\n\
			)",sTableName);

		/* EXEC SQL PREPARE PREP_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )701;
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


		if(CheckSqlResult("Prepare insert statement PREP_LOG")<0) return -1;

		/* EXEC SQL EXECUTE PREP_LOGTRG USING
				:p->iInputID,
				:p->sSourceID,
				:p->sModule,
				:p->sState,
				:p->iCnt,
				:p->sFileName,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sDataDate,
				:p->iSeq,
				:p->sOriFileName,
				:p->sFileType,
				:p->sAppID,
				:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )720;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iSeq);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sOriFileName);
  sqlstm.sqhstl[10] = (unsigned long )81;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[12] = (unsigned long )11;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
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


		if(CheckSqlResult("Dyn insert into PREP_LOG")<0) return -1;

	return 0;
}
/*单条数据从用动态SQL从PREP_PROC_LOG取数据*/
int SDGetPrepProcLogToStruct(struct PrepProcLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				BYTE,\n\
				CNT,\n\
				FILE_NAME,\n\
				to_char(nvl(DEAL_BEGIN_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(DEAL_END_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(NORMAL_CNT,0),\n\
				nvl(ERR_CNT,0),\n\
				nvl(DUP_CNT,0),\n\
				nvl(ABNO_CNT,0),\n\
				nvl(NEW_CNT,0),\n\
				nvl(FILE_TYPE,' '),\n\
				nvl(APP_ID,' '),\n\
				nvl(TACHE_ID,0)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PREP_PROC_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )791;
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


		CheckSqlError(" PREPARE PREP_PROC_LOGSCR PREP_PROC_LOGCR");

		/* EXEC SQL DECLARE PREP_PROC_LOGCR CURSOR FOR PREP_PROC_LOGSCR; */ 

		CheckSqlError("Declare PREP_PROC_LOGCR");

		/* EXEC SQL OPEN PREP_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )810;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PREP_PROC_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH PREP_PROC_LOGCR INTO
			:p->iInputID,
			:p->sSourceID,
			:p->sModule,
			:p->iByte,
			:p->iCnt,
			:p->sFileName,
			:p->sDealBeginDate,
			:p->sDealEndDate,
			:p->iNormalCnt,
			:p->iErrCnt,
			:p->iDupCnt,
			:p->iAbnoCnt,
			:p->iNewCnt,
			:p->sFileType,
			:p->sAppID,
			:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )825;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&(p->iNormalCnt);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iErrCnt);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&(p->iDupCnt);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&(p->iAbnoCnt);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&(p->iNewCnt);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
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


		CheckSqlError("Fetch PREP_PROC_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE PREP_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )904;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE PREP_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )919;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	return TRUE;
}
/*单条数据动态SQL向PREP_PROC_LOG写数据*/
int SDInsertStructToPrepProcLog(struct PrepProcLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				BYTE,\n\
				CNT,\n\
				FILE_NAME,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				NORMAL_CNT,\n\
				ERR_CNT,\n\
				DUP_CNT,\n\
				ABNO_CNT,\n\
				NEW_CNT,\n\
				FILE_TYPE,\n\
				APP_ID,\n\
				TACHE_ID)\n\
			VALUES (\n\
				:iInputID,\n\
				:sSourceID,\n\
				:sModule,\n\
				:iByte,\n\
				:iCnt,\n\
				:sFileName,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				:iNormalCnt,\n\
				:iErrCnt,\n\
				:iDupCnt,\n\
				:iAbnoCnt,\n\
				:iNewCnt,\n\
				:sFileType,\n\
				:sAppID,\n\
				:iTacheID\n\
			)",sTableName);

		/* EXEC SQL PREPARE PREP_PROC_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )934;
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


		if(CheckSqlResult("Prepare insert statement PREP_PROC_LOG")<0) return -1;

		/* EXEC SQL EXECUTE PREP_PROC_LOGTRG USING
				:p->iInputID,
				:p->sSourceID,
				:p->sModule,
				:p->iByte,
				:p->iCnt,
				:p->sFileName,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->iNormalCnt,
				:p->iErrCnt,
				:p->iDupCnt,
				:p->iAbnoCnt,
				:p->iNewCnt,
				:p->sFileType,
				:p->sAppID,
				:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )953;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&(p->iNormalCnt);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iErrCnt);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&(p->iDupCnt);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&(p->iAbnoCnt);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&(p->iNewCnt);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
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


		if(CheckSqlResult("Dyn insert into PREP_PROC_LOG")<0) return -1;

	return 0;
}

/*单条数据从用动态SQL从BILLING_LOG取数据*/
int SDGetBillingLogToStruct(struct BillingLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				CNT,\n\
				FILE_NAME,\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				to_char(DATA_DATE,'yyyymmddhh24miss'),\n\
				SEQ,\n\
				ORI_FILE_NAME,\n\
				nvl(FILE_TYPE,'-1'),\n\
				nvl(TACHE_ID,-1),\n\
				nvl(APP_ID,'-1')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE BILLING_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1032;
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


		CheckSqlError(" PREPARE BILLING_LOGSCR BILLING_LOGCR");

		/* EXEC SQL DECLARE BILLING_LOGCR CURSOR FOR BILLING_LOGSCR; */ 

		CheckSqlError("Declare BILLING_LOGCR");

		/* EXEC SQL OPEN BILLING_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1051;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open BILLING_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH BILLING_LOGCR INTO
			:p->iInputID,
			:p->sSourceID,
			:p->sModule,
			:p->sState,
			:p->iCnt,
			:p->sFileName,
			:p->sDealBeginDate,
			:p->sDealEndDate,
			:p->sDataDate,
			:p->iSeq,
			:p->sOriFileName,
			:p->sFileType,
			:p->iTacheID,
			:p->sAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1066;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iSeq);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sOriFileName);
  sqlstm.sqhstl[10] = (unsigned long )81;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[13] = (unsigned long )11;
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


		CheckSqlError("Fetch BILLING_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE BILLING_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1137;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE BILLING_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1152;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sState);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sDataDate);
		AllTrim(p->sOriFileName);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	return TRUE;
}

/*单条数据动态SQL向BILLING_LOG写数据*/
int SDInsertStructToBillingLog(struct BillingLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				CNT,\n\
				FILE_NAME,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				DATA_DATE,\n\
				SEQ,\n\
				ORI_FILE_NAME,\n\
				FILE_TYPE,\n\
				APP_CODE,\n\
				TACHE_ID,\n\
				APP_ID)\n\
			VALUES (\n\
				:iInputID,\n\
				:sSourceID,\n\
				:sModule,\n\
				:sState,\n\
				:iCnt,\n\
				:sFileName,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				to_date(:sDataDate,'yyyymmddhh24miss'),\n\
				:iSeq,\n\
				:sOriFileName,\n\
				:sFileType,\n\
				:sAppCode,\n\
				:iTacheID,\n\
				:sAppID\n\
			)",sTableName);

		/* EXEC SQL PREPARE BILLING_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1167;
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


		if(CheckSqlResult("Prepare insert statement BILLING_LOG")<0) return -1;

		/* EXEC SQL EXECUTE BILLING_LOGTRG USING
				:p->iInputID,
				:p->sSourceID,
				:p->sModule,
				:p->sState,
				:p->iCnt,
				:p->sFileName,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sDataDate,
				:p->iSeq,
				:p->sOriFileName,
				:p->sFileType,
				:p->sAppCode,
				:p->iTacheID,
				:p->sAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1186;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iSeq);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sOriFileName);
  sqlstm.sqhstl[10] = (unsigned long )81;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(p->sAppCode);
  sqlstm.sqhstl[12] = (unsigned long )9;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
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


		if(CheckSqlResult("Dyn insert into BILLING_LOG")<0) return -1;

	return 0;
}
/*单条数据动态SQL向ROLL_PROC_LOG写数据*/
int SDInsertStructToRollProcLog(struct RollProcLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				CNT,\n\
				FILE_NAME,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				ORI_FILE_NAME,\n\
				FILE_TYPE,\n\
				APP_CODE,\n\
				APP_ID,\n\
				TACHE_ID)\n\
			VALUES (\n\
				:iInputID,\n\
				:sSourceID,\n\
				:sModule,\n\
				:sState,\n\
				:iCnt,\n\
				:sFileName,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				:sOriFileName,\n\
				:sFileType,\n\
				:sAppCode,\n\
				:sAppID,\n\
				:iTacheID\n\
			)",sTableName);

		/* EXEC SQL PREPARE ROLL_PROC_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1261;
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


		if(CheckSqlResult("Prepare insert statement ROLL_PROC_LOG")<0) return -1;

		/* EXEC SQL EXECUTE ROLL_PROC_LOGTRG USING
				:p->iInputID,
				:p->sSourceID,
				:p->sModule,
				:p->sState,
				:p->iCnt,
				:p->sFileName,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sOriFileName,
				:p->sFileType,
				:p->sAppCode,
				:p->sAppID,
				:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1280;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sOriFileName);
  sqlstm.sqhstl[8] = (unsigned long )81;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[9] = (unsigned long )6;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sAppCode);
  sqlstm.sqhstl[10] = (unsigned long )9;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
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


		if(CheckSqlResult("Dyn insert into ROLL_PROC_LOG")<0) return -1;

	return 0;
}
/*单条数据动态SQL向ROLL_LOG写数据*/
int SDInsertStructToRollLog(struct RollLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				FILE_NAME,\n\
				CNT,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				DATA_DATE,\n\
				SEQ,\n\
				FILE_TYPE,\n\
				APP_CODE,\n\
				APP_ID,\n\
				TACHE_ID)\n\
			VALUES (\n\
				:iInputID,\n\
				:sSourceID,\n\
				:sModule,\n\
				:sState,\n\
				:sFileName,\n\
				:iCnt,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				to_date(:sDataDate,'yyyymmddhh24miss'),\n\
				:iSeq,\n\
				:sFileType,\n\
				:sAppCode,\n\
				:sAppID,\n\
				:iTacheID\n\
			)",sTableName);

		/* EXEC SQL PREPARE ROLL_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1347;
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


		if(CheckSqlResult("Prepare insert statement ROLL_LOG")<0) return -1;

		/* EXEC SQL EXECUTE ROLL_LOGTRG USING
				:p->iInputID,
				:p->sSourceID,
				:p->sModule,
				:p->sState,
				:p->sFileName,
				:p->iCnt,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sDataDate,
				:p->iSeq,
				:p->sFileType,
				:p->sAppCode,
				:p->sAppID,
				:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1366;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(p->iSeq);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[10] = (unsigned long )6;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(p->sAppCode);
  sqlstm.sqhstl[11] = (unsigned long )9;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[12] = (unsigned long )11;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
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


		if(CheckSqlResult("Dyn insert into ROLL_LOG")<0) return -1;

	return 0;
}

/*单条数据从用动态SQL从UPDATA_LOG取数据*/
int SDGetUpdataLogToStruct(struct UpdataLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				UPDATA_ID,\n\
				FILE_TYPE,\n\
				FILE_NAME,\n\
				to_char(BEGIN_TIME,'yyyymmddhh24miss'),\n\
				to_char(END_TIME,'yyyymmddhh24miss'),\n\
				REC_CNT,\n\
				TOTAL_CHARGE,\n\
				to_char(DATA_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				nvl(APP_ID,'INTF01'),\n\
				nvl(TACHE_ID,0)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE UPDATA_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1437;
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


		CheckSqlError(" PREPARE UPDATA_LOGSCR UPDATA_LOGCR");

		/* EXEC SQL DECLARE UPDATA_LOGCR CURSOR FOR UPDATA_LOGSCR; */ 

		CheckSqlError("Declare UPDATA_LOGCR");

		/* EXEC SQL OPEN UPDATA_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1456;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open UPDATA_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH UPDATA_LOGCR INTO
			:p->iUpdataID,
			:p->sFileType,
			:p->sFileName,
			:p->sBeginTime,
			:p->sEndTime,
			:p->iRecCnt,
			:p->iTotalCharge,
			:p->sDataDate,
			:p->sDealBeginDate,
			:p->sDealEndDate,
			:p->sAppID,
			:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1471;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iUpdataID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[2] = (unsigned long )81;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sBeginTime);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sEndTime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&(p->iRecCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iTotalCharge);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&(p->iTacheID);
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


		CheckSqlError("Fetch UPDATA_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE UPDATA_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1534;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE UPDATA_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1549;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sFileType);
		AllTrim(p->sFileName);
		AllTrim(p->sBeginTime);
		AllTrim(p->sEndTime);
		AllTrim(p->sDataDate);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sAppID);

	return TRUE;
}

/*单条数据动态SQL向UPDATA_LOG写数据*/
int SDInsertStructToUpdataLog(struct UpdataLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				UPDATA_ID,\n\
				FILE_TYPE,\n\
				FILE_NAME,\n\
				BEGIN_TIME,\n\
				END_TIME,\n\
				REC_CNT,\n\
				TOTAL_CHARGE,\n\
				DATA_DATE,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				APP_ID,\n\
				TACHE_ID)\n\
			VALUES (\n\
				:iUpdataID,\n\
				:sFileType,\n\
				:sFileName,\n\
				to_date(:sBeginTime,'yyyymmddhh24miss'),\n\
				to_date(:sEndTime,'yyyymmddhh24miss'),\n\
				:iRecCnt,\n\
				:iTotalCharge,\n\
				to_date(:sDataDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				:sAppID,\n\
				:iTacheID\n\
			)",sTableName);

		/* EXEC SQL PREPARE UPDATA_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1564;
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


		if(CheckSqlResult("Prepare insert statement UPDATA_LOG")<0) return -1;

		/* EXEC SQL EXECUTE UPDATA_LOGTRG USING
				:p->iUpdataID,
				:p->sFileType,
				:p->sFileName,
				:p->sBeginTime,
				:p->sEndTime,
				:p->iRecCnt,
				:p->iTotalCharge,
				:p->sDataDate,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sAppID,
				:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1583;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iUpdataID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[2] = (unsigned long )81;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sBeginTime);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sEndTime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&(p->iRecCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iTotalCharge);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDataDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&(p->iTacheID);
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


		if(CheckSqlResult("Dyn insert into UPDATA_LOG")<0) return -1;

	return 0;
}

/*单条数据从用动态SQL从UPDATA_PROC_LOG取数据*/
int SDGetUpdataProcLogToStruct(struct UpdataProcLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				ORI_FILE_NAME,\n\
				CUR_FILE_NAME,\n\
				BYTE,\n\
				REC_CNT,\n\
				to_char(FILE_DATE,'yyyymmddhh24miss'),\n\
				nvl(APP_ID,'INTF01'),\n\
				nvl(TACHE_ID,0)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE UPDATA_PROC_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1646;
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


		CheckSqlError(" PREPARE UPDATA_PROC_LOGSCR UPDATA_PROC_LOGCR");

		/* EXEC SQL DECLARE UPDATA_PROC_LOGCR CURSOR FOR UPDATA_PROC_LOGSCR; */ 

		CheckSqlError("Declare UPDATA_PROC_LOGCR");

		/* EXEC SQL OPEN UPDATA_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1665;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open UPDATA_PROC_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH UPDATA_PROC_LOGCR INTO
			:p->sOriFileName,
			:p->sCurFileName,
			:p->iByte,
			:p->iRecCnt,
			:p->sFileDate,
			:p->sAppID,
			:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1680;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(p->sOriFileName);
  sqlstm.sqhstl[0] = (unsigned long )81;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sCurFileName);
  sqlstm.sqhstl[1] = (unsigned long )81;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iRecCnt);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sFileDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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


		CheckSqlError("Fetch UPDATA_PROC_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE UPDATA_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1723;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE UPDATA_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1738;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sOriFileName);
		AllTrim(p->sCurFileName);
		AllTrim(p->sFileDate);
		AllTrim(p->sAppID);

	return TRUE;
}

/*单条数据动态SQL向UPDATA_PROC_LOG写数据*/
int SDInsertStructToUpdataProcLog(struct UpdataProcLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				ORI_FILE_NAME,\n\
				CUR_FILE_NAME,\n\
				BYTE,\n\
				REC_CNT,\n\
				FILE_DATE,\n\
				APP_ID,\n\
				TACHE_ID)\n\
			VALUES (\n\
				:sOriFileName,\n\
				:sCurFileName,\n\
				:iByte,\n\
				:iRecCnt,\n\
				to_date(:sFileDate,'yyyymmddhh24miss'),\n\
				:sAppID,\n\
				:iTacheID\n\
			)",sTableName);

		/* EXEC SQL PREPARE UPDATA_PROC_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1753;
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


		if(CheckSqlResult("Prepare insert statement UPDATA_PROC_LOG")<0) return -1;

		/* EXEC SQL EXECUTE UPDATA_PROC_LOGTRG USING
				:p->sOriFileName,
				:p->sCurFileName,
				:p->iByte,
				:p->iRecCnt,
				:p->sFileDate,
				:p->sAppID,
				:p->iTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1772;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(p->sOriFileName);
  sqlstm.sqhstl[0] = (unsigned long )81;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sCurFileName);
  sqlstm.sqhstl[1] = (unsigned long )81;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iRecCnt);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sFileDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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


		if(CheckSqlResult("Dyn insert into UPDATA_PROC_LOG")<0) return -1;

	return 0;
}

int GetLastDateSeq(char sFileType[],char sDataDate[],int *piSeq)
{
	int iSeq=0;
	char	sTempDate[15],sTempType[6];
	

	strcpy(sTempType,sFileType);

/*先带索引的方式获取最大的DATA_DATE 在DATA>SYSDATE-1的情况下*/
	/* EXEC SQL SELECT nvl(to_char(max(DATA_DATE),'yyyymmddhh24miss'),'0')
		INTO :sTempDate
		FROM UPDATA_LOG
		WHERE DATA_DATE>TRUNC(SYSDATE)-1 AND
			FILE_TYPE=:sTempType; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select nvl(to_char(max(DATA_DATE),'yyyymmddhh24miss'),'0') \
into :b0  from UPDATA_LOG where (DATA_DATE>(TRUNC(SYSDATE)-1) and FILE_TYPE=:\
b1)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1815;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sTempDate;
 sqlstm.sqhstl[0] = (unsigned long )15;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempType;
 sqlstm.sqhstl[1] = (unsigned long )6;
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


	if(CheckSqlResult("GET MAX DATADATE UPDATA_LOG")<0) return -1;

/*如果获取不到则通过不用索引的方式获取*/
	if(strncmp(sTempDate,"0",1)==0){
		/* EXEC SQL SELECT nvl(to_char(max(DATA_DATE),'yyyymmddhh24miss'),'0')
			INTO :sTempDate
			FROM UPDATA_LOG
			WHERE FILE_TYPE=:sTempType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select nvl(to_char(max(DATA_DATE),'yyyymmddhh24miss'),'0')\
 into :b0  from UPDATA_LOG where FILE_TYPE=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1838;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)sTempDate;
  sqlstm.sqhstl[0] = (unsigned long )15;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sTempType;
  sqlstm.sqhstl[1] = (unsigned long )6;
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


		if(CheckSqlResult("GET MAX DATADATE UPDATA_LOG")<0) return -1;

		/*如果还是获取不到则取系统时间*/
		if(strncmp(sTempDate,"0",1)==0) GetHostTime(sTempDate);

	}
	strcpy(sTempDate+8,"000000");
	
	/* EXEC SQL SELECT nvl(max(UPDATA_ID),0) 
		INTO :iSeq
		FROM UPDATA_LOG 
		WHERE DATA_DATE=to_date(:sTempDate,'yyyymmddhh24miss') AND
			FILE_TYPE=:sTempType; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select nvl(max(UPDATA_ID),0) into :b0  from UPDATA_LOG wher\
e (DATA_DATE=to_date(:b1,'yyyymmddhh24miss') and FILE_TYPE=:b2)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1861;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempDate;
 sqlstm.sqhstl[1] = (unsigned long )15;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempType;
 sqlstm.sqhstl[2] = (unsigned long )6;
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


	if(CheckSqlResult("GET MAX SEQ BY DATADATE UPDATA_LOG")<0) return -1;
	
	strcpy(sDataDate,sTempDate);
	*piSeq=	iSeq;
	
	return 0;
}
int GetLastSeqComm(char sFileType[],int *piSeq)
{
	int iSeq=0;
	char	sTempDate[15],sTempType[6];
	

	strcpy(sTempType,sFileType);
	
/*先带索引的方式获取最大的DEAL_DATE 在DEAL>SYSDATE-1的情况下*/
	/* EXEC SQL SELECT nvl(to_char(max(DEAL_END_DATE),'yyyymmddhh24miss'),'0')
		INTO :sTempDate
		FROM UPDATA_LOG
		WHERE DEAL_END_DATE>TRUNC(SYSDATE)-1 AND
			FILE_TYPE=:sTempType; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select nvl(to_char(max(DEAL_END_DATE),'yyyymmddhh24miss'),'\
0') into :b0  from UPDATA_LOG where (DEAL_END_DATE>(TRUNC(SYSDATE)-1) and FIL\
E_TYPE=:b1)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1888;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sTempDate;
 sqlstm.sqhstl[0] = (unsigned long )15;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempType;
 sqlstm.sqhstl[1] = (unsigned long )6;
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


	if(CheckSqlResult("GET MAX DEALDATE UPDATA_LOG")<0) return -1;
	
/*如果获取不到则通过不用索引的方式获取*/
	if(strncmp(sTempDate,"0",1)==0){
		/* EXEC SQL SELECT nvl(to_char(max(DEAL_END_DATE),'yyyymmddhh24miss'),'0')
			INTO :sTempDate
			FROM UPDATA_LOG
			WHERE FILE_TYPE=:sTempType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select nvl(to_char(max(DEAL_END_DATE),'yyyymmddhh24miss'),\
'0') into :b0  from UPDATA_LOG where FILE_TYPE=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1911;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)sTempDate;
  sqlstm.sqhstl[0] = (unsigned long )15;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sTempType;
  sqlstm.sqhstl[1] = (unsigned long )6;
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


		if(CheckSqlResult("GET MAX DEALDATE UPDATA_LOG")<0) return -1;
	}

	if(strncmp(sTempDate,"0",1)==0){
		*piSeq=0;
		return 0;
	}
	
	/* EXEC SQL SELECT nvl(max(UPDATA_ID) ,0)
		INTO :iSeq
		FROM UPDATA_LOG 
		WHERE DEAL_END_DATE=to_date(:sTempDate,'yyyymmddhh24miss') AND
			FILE_TYPE=:sTempType; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select nvl(max(UPDATA_ID),0) into :b0  from UPDATA_LOG wher\
e (DEAL_END_DATE=to_date(:b1,'yyyymmddhh24miss') and FILE_TYPE=:b2)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1934;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempDate;
 sqlstm.sqhstl[1] = (unsigned long )15;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempType;
 sqlstm.sqhstl[2] = (unsigned long )6;
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


	if(CheckSqlResult("GET MAX SEQ UPDATA_LOG")<0) return -1;

	*piSeq=	iSeq;
	
	return 0;
}
int GetLastSeq(char sFileType[],char sDataDate[],int *piSeq)
{
	int iSeq=0;
	char	sTempDate[15],sTempType[6];
	

	strcpy(sTempType,sFileType);
	strcpy(sTempDate,sDataDate);
	
	/* EXEC SQL SELECT nvl(max(UPDATA_ID),0) 
		INTO :iSeq
		FROM UPDATA_LOG 
		WHERE DATA_DATE=to_date(:sTempDate,'yyyymmddhh24miss') AND
			FILE_TYPE=:sTempType; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select nvl(max(UPDATA_ID),0) into :b0  from UPDATA_LOG wher\
e (DATA_DATE=to_date(:b1,'yyyymmddhh24miss') and FILE_TYPE=:b2)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1961;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempDate;
 sqlstm.sqhstl[1] = (unsigned long )15;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempType;
 sqlstm.sqhstl[2] = (unsigned long )6;
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


	if(CheckSqlResult("GET MAX SEQ UPDATA_LOG")<0) return -1;
	
	*piSeq=	iSeq;
	
	return 0;
}
/*这个函数用在tsmsfile中*/
int GetNextSeq( char sFileType[] )
{	
	int iNextSeq =0;
	char sTempType[6];

	strcpy(sTempType,sFileType);

	/* EXEC SQL SELECT nvl(max(UPDATA_ID),0) INTO :iNextSeq
		FROM UPDATA_LOG
		WHERE DEAL_END_DATE>trunc(SYSDATE) AND
			FILE_TYPE=:sTempType; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select nvl(max(UPDATA_ID),0) into :b0  from UPDATA_LOG wher\
e (DEAL_END_DATE>trunc(SYSDATE) and FILE_TYPE=:b1)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1988;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iNextSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempType;
 sqlstm.sqhstl[1] = (unsigned long )6;
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



	if(CheckSqlResult("GET CURDATE MAX SEQ UPDATA_LOG")<0) return -1;

	iNextSeq ++;
	 
	if ( iNextSeq > 9999 )
		iNextSeq = 1;
	return iNextSeq;
}

int GetInputID()
{
	int iInputID;
	
	/* EXEC SQL SELECT INPUT_ID_SEQ.NEXTVAL INTO :iInputID FROM DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select INPUT_ID_SEQ.nextval  into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2011;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iInputID;
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


	if(CheckSqlResult("GET INPUT_ID_SEQ")<0) return -1;
	return iInputID;
}
int BillingLogCheck(char sSourceID[20],char sFileName[80],
	char sModule[10],char sTargetName[])
{
	int iCnt;
	char sTempSourceID[20],sTempFileName[80];
	char sTempModule[10],sTempTarget[80];
	
	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempFileName,	sFileName);
	strcpy(sTempModule,	sModule);
	strcpy(sTempTarget,	sTargetName);

/*对于目标文件如果是彻底失败的直接不检查*/
	if(RLike(sTempTarget,"0")==true) return 0;

	/* EXEC SQL SELECT COUNT(*) INTO :iCnt
		FROM BILLING_PROC_LOG
		WHERE SOURCE_ID=:sTempSourceID AND
			FILE_NAME=:sTempFileName AND
			MODULE=:sTempModule; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(*)  into :b0  from BILLING_PROC_LOG where ((SO\
URCE_ID=:b1 and FILE_NAME=:b2) and MODULE=:b3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2030;
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
 sqlstm.sqhstv[1] = (unsigned char  *)sTempSourceID;
 sqlstm.sqhstl[1] = (unsigned long )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempFileName;
 sqlstm.sqhstl[2] = (unsigned long )80;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)sTempModule;
 sqlstm.sqhstl[3] = (unsigned long )10;
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


	if(CheckSqlResult("COUNT BILLING_PROC_LOG")<0) return -1;

	if(iCnt==0) return 0;
	return 1;	
}

int PrepLogCheck(char sSourceID[20],char sFileName[80],char sModule[10])
{
	int iCnt;
	char sTempSourceID[20],sTempFileName[80],sTempModule[10];
	
	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempFileName,	sFileName);
	strcpy(sTempModule,	sModule);

	/* EXEC SQL SELECT COUNT(*) INTO :iCnt
		FROM PREP_PROC_LOG
		WHERE SOURCE_ID=:sTempSourceID AND
			FILE_NAME=:sTempFileName AND
			MODULE=:sTempModule AND
			DEAL_END_DATE>SYSDATE-90; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(*)  into :b0  from PREP_PROC_LOG where (((SOUR\
CE_ID=:b1 and FILE_NAME=:b2) and MODULE=:b3) and DEAL_END_DATE>(SYSDATE-90))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2061;
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
 sqlstm.sqhstv[1] = (unsigned char  *)sTempSourceID;
 sqlstm.sqhstl[1] = (unsigned long )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempFileName;
 sqlstm.sqhstl[2] = (unsigned long )80;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)sTempModule;
 sqlstm.sqhstl[3] = (unsigned long )10;
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


	if(CheckSqlResult("COUNT PREP_PROC_LOG")<0) return -1;

	if(iCnt==0) return 0;
	return 1;	
}

int PickLogCheck(char sSourceID[20],char sFileName[80],int iChkDays)
{
	int iCnt;
	char sTempSourceID[20],sTempFileName[80];
	
	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempFileName,	sFileName);
	
	if(iChkDays>0){
		/* EXEC SQL SELECT COUNT(*) INTO :iCnt
			FROM PICK_LOG
			WHERE SOURCE_ID=:sSourceID AND
				FILE_NAME=:sFileName AND
				STATE='A' AND
				DEAL_END_DATE>SYSDATE-:iChkDays; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(*)  into :b0  from PICK_LOG where (((SOURCE_I\
D=:b1 and FILE_NAME=:b2) and STATE='A') and DEAL_END_DATE>(SYSDATE-:b3))";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2092;
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
  sqlstm.sqhstv[1] = (unsigned char  *)sSourceID;
  sqlstm.sqhstl[1] = (unsigned long )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)sFileName;
  sqlstm.sqhstl[2] = (unsigned long )80;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&iChkDays;
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


	}
	else{
		/* EXEC SQL SELECT COUNT(*) INTO :iCnt
			FROM PICK_LOG
			WHERE SOURCE_ID=:sSourceID AND
				FILE_NAME=:sFileName AND
				STATE='A' ; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(*)  into :b0  from PICK_LOG where ((SOURCE_ID\
=:b1 and FILE_NAME=:b2) and STATE='A')";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2123;
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
  sqlstm.sqhstv[1] = (unsigned char  *)sSourceID;
  sqlstm.sqhstl[1] = (unsigned long )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)sFileName;
  sqlstm.sqhstl[2] = (unsigned long )80;
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


	}

	if(CheckSqlResult("COUNT PICK_LOG")<0) return -1;
	
	if(iCnt==0) return 0;
	return 1;	
}
int GetPrepNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10])
{
	int iSeq;
	char sTempSourceID[10],sTempDataDate[15], sTempModule[10];

	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempDataDate,	sDataDate);
	strcpy(sTempModule,	sModule);
	
	
	/* EXEC SQL SELECT nvl(MAX(SEQ),-1)+1 INTO :iSeq
		FROM PREP_LOG
		WHERE SOURCE_ID=:sTempSourceID AND
			DATA_DATE=to_date(:sTempDataDate,'yyyymmddhh24miss') AND
			MODULE=:sTempModule; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select (nvl(max(SEQ),(-1))+1) into :b0  from PREP_LOG where\
 ((SOURCE_ID=:b1 and DATA_DATE=to_date(:b2,'yyyymmddhh24miss')) and MODULE=:b\
3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2150;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempSourceID;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempDataDate;
 sqlstm.sqhstl[2] = (unsigned long )15;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)sTempModule;
 sqlstm.sqhstl[3] = (unsigned long )10;
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



	if(CheckSqlResult("GET PREP_LOG SEQ")<0) return -1;
	return iSeq;
}
int GetRcylNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10])
{
	int iSeq;
	char sTempSourceID[10],sTempDataDate[15],sTempModule[10],sNextDate[15];

	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempDataDate,	sDataDate);
	strcpy(sTempModule,	sModule);
	
	/* EXEC SQL SELECT nvl(MAX(SEQ),-1)+1 INTO :iSeq
		FROM RCYL_LOG
		WHERE DATA_DATE=to_date(:sTempDataDate,'yyyymmddhh24miss') AND
			SOURCE_ID=:sTempSourceID AND
			MODULE=:sTempModule; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select (nvl(max(SEQ),(-1))+1) into :b0  from RCYL_LOG where\
 ((DATA_DATE=to_date(:b1,'yyyymmddhh24miss') and SOURCE_ID=:b2) and MODULE=:b\
3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2181;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempDataDate;
 sqlstm.sqhstl[1] = (unsigned long )15;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempSourceID;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)sTempModule;
 sqlstm.sqhstl[3] = (unsigned long )10;
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



	if(CheckSqlResult("GET RCYL_LOG SEQ")<0) return -1;
	return iSeq;
}
int GetRollNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10])
{
	int iSeq;
	char sTempSourceID[10],sTempDataDate[15],sTempModule[10],sNextDate[15];

	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempDataDate,	sDataDate);
	strcpy(sTempModule,	sModule);
	
	/* EXEC SQL SELECT nvl(MAX(SEQ),-1)+1 INTO :iSeq
		FROM ROLL_LOG
		WHERE DATA_DATE=to_date(:sTempDataDate,'yyyymmddhh24miss') AND
			SOURCE_ID=:sTempSourceID AND
			MODULE=:sTempModule; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select (nvl(max(SEQ),(-1))+1) into :b0  from ROLL_LOG where\
 ((DATA_DATE=to_date(:b1,'yyyymmddhh24miss') and SOURCE_ID=:b2) and MODULE=:b\
3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2212;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempDataDate;
 sqlstm.sqhstl[1] = (unsigned long )15;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempSourceID;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)sTempModule;
 sqlstm.sqhstl[3] = (unsigned long )10;
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



	if(CheckSqlResult("GET ROLL_LOG SEQ")<0) return -1;
	return iSeq;
}
int GetBillNextSeq(char sSourceID[10],char sDataDate[15],char sModule[10])
{
	int iSeq;
	char sTempSourceID[10],sTempDataDate[15], sTempModule[10];

	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempDataDate,	sDataDate);
	strcpy(sTempModule,	sModule);
	
	
	/* EXEC SQL SELECT nvl(MAX(SEQ),-1)+1 INTO :iSeq
		FROM BILLING_LOG
		WHERE SOURCE_ID=:sTempSourceID AND
			DATA_DATE=to_date(:sTempDataDate,'yyyymmddhh24miss') AND
			MODULE=:sTempModule; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select (nvl(max(SEQ),(-1))+1) into :b0  from BILLING_LOG wh\
ere ((SOURCE_ID=:b1 and DATA_DATE=to_date(:b2,'yyyymmddhh24miss')) and MODULE\
=:b3)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2243;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSeq;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempSourceID;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempDataDate;
 sqlstm.sqhstl[2] = (unsigned long )15;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)sTempModule;
 sqlstm.sqhstl[3] = (unsigned long )10;
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



	if(CheckSqlResult("GET BILLING_LOG SEQ")<0) return -1;
	return iSeq;
}
/***系统监控部分**************************/
int GetTablespaceUsedPercent(char sTableSpaceName[31])
{	
	int iUsedPercent=0;
	char sTempTableSpaceName[31];
	strcpy(sTempTableSpaceName,sTableSpaceName);
	
	/* EXEC SQL SELECT 
		round((B.TOTAL_MB-A.TOTAL_MB)/B.TOTAL_MB*100,2) INTO :iUsedPercent
	FROM (
		SELECT	TABLESPACE_NAME,
			round(sum(BYTES)/(1024*1024),2) TOTAL_MB,
			round(max(BYTES)/(1024*1024),2) MAX_MB
		FROM DBA_FREE_SPACE
		GROUP BY TABLESPACE_NAME
	) A,
	(
		SELECT TABLESPACE_NAME,
			round(sum(BYTES)/(1024*1024),2) TOTAL_MB
		FROM   DBA_DATA_FILES
	    GROUP BY TABLESPACE_NAME
	) B
	WHERE A.TABLESPACE_NAME = B.TABLESPACE_NAME
	AND B.TABLESPACE_NAME=:sTempTableSpaceName; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select round((((B.TOTAL_MB-A.TOTAL_MB)/B.TOTAL_MB)* 100),2)\
 into :b0  from (select TABLESPACE_NAME ,round((sum(BYTES)/(1024* 1024)),2) T\
OTAL_MB ,round((max(BYTES)/(1024* 1024)),2) MAX_MB  from DBA_FREE_SPACE  grou\
p by TABLESPACE_NAME) A ,(select TABLESPACE_NAME ,round((sum(BYTES)/(1024* 10\
24)),2) TOTAL_MB  from DBA_DATA_FILES  group by TABLESPACE_NAME) B where (A.T\
ABLESPACE_NAME=B.TABLESPACE_NAME and B.TABLESPACE_NAME=:b1)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2274;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iUsedPercent;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempTableSpaceName;
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



	if(CheckSqlResult("GET TABLESPACE")<0) return -1;
	return iUsedPercent;
	
}
void PrintErrTicket(char sTableName[],int iMaxCnt)
{
	int iCnt;
	char sTrunk[10],sMsc[11],sDirection[20];
	
	char statement[8192];
	
	sprintf(statement,"\n\
		SELECT COUNT(*) CNT,		\n\
			MSC,			\n\
			'其它' TRUNKNAME,	\n\
			'其它' TRUNK_TYPE     \n\
		FROM %s 			\n\
		WHERE TICKET_TYPE_ID=0 AND 	\n\
		TRUNK_OUT_TYPE_ID<>0 AND	\n\
		TRUNK_IN_TYPE_ID<>0		\n\
		GROUP BY MSC			\n\
		HAVING COUNT(*) >= %d		\n\
	",sTableName,iMaxCnt);
	
	/* EXEC SQL PREPARE CHKTICKET_SCR FROM :statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2297;
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


	/* EXEC SQL DECLARE CHKTICKET_CR CURSOR FOR CHKTICKET_SCR; */ 

	CheckSqlError("Declare CHKTICKET_CR");

	/* EXEC SQL OPEN CHKTICKET_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2316;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	CheckSqlError("Open CHKTICKET_CR");	
	
	while(1){			
		/* EXEC SQL FETCH CHKTICKET_CR INTO :iCnt,:sMsc,:sTrunk,:sDirection; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2331;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sMsc;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)sTrunk;
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)sDirection;
  sqlstm.sqhstl[3] = (unsigned long )20;
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

	
		CheckSqlError("Fetch CHKTICKET_CR");
		if(NoDataFetched) break;
		
		AllTrim(sMsc);
		AllTrim(sTrunk);
		AllTrim(sDirection);			
		printf("%d\t%s\t%s\t%s\tErr\n",iCnt,sMsc,sTrunk,sDirection);
	}
	
	/* EXEC SQL CLOSE CHKTICKET_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2362;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

void PrintMissTrunk(char sTableName[],int iMaxCnt)
{
	int iCnt;
	char sTrunk[10],sMsc[11],sDirection[20];
	
	char statement[8192];
	
	sprintf(statement,"\n\
		SELECT COUNT(*) CNT,		\n\
			MSC,			\n\
			nvl(TRUNK_IN,'空') TRUNKNAME,	\n\
			'入中继' TRUNK_TYPE   	\n\
		FROM %s 			\n\
		WHERE TICKET_TYPE_ID=0 AND 	\n\
			TRUNK_IN_TYPE_ID=0  	\n\
		GROUP BY MSC,TRUNK_IN 		\n\
		HAVING COUNT(*) >= %d 		\n\
		UNION 				\n\
		SELECT COUNT(*) CNT,		\n\
			MSC,			\n\
			nvl(TRUNK_OUT,'空') TRUNKNAME,	\n\
			'出中继' TRUNK_TYPE     \n\
		FROM %s 			\n\
		WHERE TICKET_TYPE_ID=0 AND 	\n\
		TRUNK_OUT_TYPE_ID=0		\n\
		GROUP BY MSC,TRUNK_OUT		\n\
		HAVING COUNT(*) >= %d		\n\
	",sTableName,iMaxCnt,sTableName,iMaxCnt);
	/* EXEC SQL PREPARE CHKTRUNK_SCR FROM :statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2377;
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


	/* EXEC SQL DECLARE CHKTRUNK_CR CURSOR FOR CHKTRUNK_SCR; */ 

	CheckSqlError("Declare CHKTRUNK_CR");

	/* EXEC SQL OPEN CHKTRUNK_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2396;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	CheckSqlError("Open CHKTRUNK_CR");	
	
	while(1){			
		/* EXEC SQL FETCH CHKTRUNK_CR INTO :iCnt,:sMsc,:sTrunk,:sDirection; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2411;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sMsc;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)sTrunk;
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)sDirection;
  sqlstm.sqhstl[3] = (unsigned long )20;
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

	
		CheckSqlError("Fetch CHKTRUNK_CR");
		if(NoDataFetched) break;
		
		AllTrim(sMsc);
		AllTrim(sTrunk);
		AllTrim(sDirection);			
		printf("%d\t%s\t%s\t%s\tMissed\n",iCnt,sMsc,sTrunk,sDirection);
	}
	
	/* EXEC SQL CLOSE CHKTRUNK_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2442;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}
void PrintInsertLogCnt(char sSourceID[10],int iDay)
{
	int iPercent,iCurCnt,iAvgCnt;
	char	sModule[10];
	char	statement[8192];
	
	sprintf(statement,"\n\
	SELECT round((B.CNT -A.CNT)/B.CNT*100) PERCENT, \n\
		A.MODULE,	\n\
		A.CNT,		\n\
		B.CNT		\n\
	FROM	\n\
	(	\n\
		SELECT SUM(CNT) CNT,\n\
			MODULE  \n\
		FROM INSERT_LOG	\n\
		WHERE TRUNC(DATA_DATE)=TRUNC(SYSDATE) AND \n\
			SOURCE_ID='%s' \n\
		GROUP BY MODULE \n\
	)A,	\n\
	(	\n\
	SELECT ROUND(AVG(CNT)) CNT,	\n\
		MODULE	\n\
	FROM \n\
		( \n\
			SELECT SUM(CNT) CNT,	\n\
				MODULE		\n\
			FROM	\n\
			(	\n\
				SELECT CNT,	\n\
					DATA_DATE,\n\
					MODULE	\n\
				FROM INSERT_LOG	\n\
				WHERE DATA_DATE>=SYSDATE-%d AND \n\
	to_char(DEAL_END_DATE,'hh24miss')<TO_CHAR(SYSDATE,'hh24miss') AND\n\
					SOURCE_ID='%s'	\n\
			)\n\
			GROUP BY DATA_DATE,MODULE \n\
		)		\n\
		GROUP BY MODULE \n\
	)B \n\
	WHERE A.MODULE = B.MODULE",sSourceID,iDay,sSourceID);
			
	/* EXEC SQL PREPARE CHKINSERTLOG_SCR FROM :statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2457;
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


	/* EXEC SQL DECLARE CHKINSERTLOG_CR CURSOR FOR CHKINSERTLOG_SCR; */ 

	CheckSqlError("Declare CHKINSERTLOG_CR");

	/* EXEC SQL OPEN CHKINSERTLOG_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2476;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	CheckSqlError("Open CHKINSERTLOG_CR");	
	
	while(1){			
	
		/* EXEC SQL FETCH CHKINSERTLOG_CR INTO 
			:iPercent,:sModule,:iCurCnt,:iAvgCnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2491;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&iPercent;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sModule;
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&iCurCnt;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&iAvgCnt;
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


		CheckSqlError("Fetch CHECK_CNT");
		
		if(NoDataFetched) break;
		
		AllTrim(sModule);
		
		/*错误话单的处理刚好相反*/
		if (strcmp(sModule,"ERR")==0) 	iPercent =-iPercent;
			
		printf("%d\t%s\t%d\t%d\n",iPercent,sModule,iCurCnt,iAvgCnt);
	}																	
	
	/* EXEC SQL CLOSE CHKINSERTLOG_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2522;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}
int PrintDataDelay(char sType[],char sTableName[31])
{
	int iDelay;
	char sVisitAreaCode[10];
	char	statement[8192];
	
	if(strcmp(sType,"visit")!=0&&strcmp(sType,"vit")!=0) return -1;
	
	if ( strcmp(sType,"visit") == 0 )
	{
		sprintf(statement,"\n\
			SELECT nvl(round((SYSDATE-max(START_TIME))*60*24),0),\n\
		  		nvl(VISIT_AREA_CODE,'000') \n\
		  	FROM %s 	\n\
		  	GROUP BY VISIT_AREA_CODE",sTableName);
	}
	else{
		sprintf(statement,"\n\
			SELECT nvl(round((SYSDATE-to_date(max(START_TIME),'yyyymmddhh24miss'))*60*24),0),\n\
		  		nvl(VISIT_AREA_CODE,'000') \n\
		  	FROM %s 	\n\
		  	GROUP BY VISIT_AREA_CODE",sTableName);
	}

	/* EXEC SQL PREPARE DATADELAY_SCR FROM :statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2537;
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


	/* EXEC SQL DECLARE DATADELAY_CR CURSOR FOR DATADELAY_SCR; */ 

	CheckSqlError("Declare DATADELAY_CR");

	/* EXEC SQL OPEN DATADELAY_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2556;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	CheckSqlError("Open DATADELAY_CR");	
	
					
	while(1){			
	
		/* EXEC SQL FETCH DATADELAY_CR INTO :iDelay,:sVisitAreaCode; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2571;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&iDelay;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)sVisitAreaCode;
  sqlstm.sqhstl[1] = (unsigned long )10;
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

	
		CheckSqlError("Fetch DATADELAY_CR");
		
		if(NoDataFetched) break;
		
		AllTrim(sVisitAreaCode);	
			
		printf("%d\t%s\n",iDelay,sVisitAreaCode);
	}																							
	
	/* EXEC SQL CLOSE DATADELAY_CR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2594;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return 0;
}
void GetPickLogDelay(char sSourceID[7],char sDealEndDate[15],int *piDelay)
{
	int	iDelay;
	char	sTempSourceID[7],sTempDate[15];
	
	strcpy(sTempSourceID,sSourceID);
	
	/* EXEC SQL SELECT 
		nvl(to_char(max(DEAL_END_DATE),'yyyymmddhh24miss'),'0'),
		nvl(SYSDATE-max(DEAL_END_DATE),0)*86400
		INTO	:sTempDate,:iDelay
		FROM PICK_LOG
		WHERE SOURCE_ID=:sTempSourceID; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select nvl(to_char(max(DEAL_END_DATE),'yyyymmddhh24miss'),'\
0') ,(nvl((SYSDATE-max(DEAL_END_DATE)),0)* 86400) into :b0,:b1  from PICK_LOG\
 where SOURCE_ID=:b2";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2609;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sTempDate;
 sqlstm.sqhstl[0] = (unsigned long )15;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&iDelay;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)sTempSourceID;
 sqlstm.sqhstl[2] = (unsigned long )7;
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


	CheckSqlError(" SELECT PICK_LOG");
	
	strcpy(sDealEndDate,sTempDate);
	*piDelay=	iDelay;	
}
/*批量数据动态从PICK_LOG中用结构缓冲方式取数据*/
int EGetPickLogToStruct(struct PickLogStruct *p,
	struct PickLogStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				BYTE,\n\
				FILE_NAME,\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				SEQ,\n\
				STATE\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE EPICK_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2636;
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


		CheckSqlError(" PREPARE EPICK_LOGSCR EPICK_LOGCR");

		/* EXEC SQL DECLARE EPICK_LOGCR CURSOR FOR EPICK_LOGSCR; */ 

		CheckSqlError("Declare EPICK_LOGCR");

		/* EXEC SQL OPEN EPICK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2655;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open EPICK_LOGCR;");


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

		/* EXEC SQL CLOSE EPICK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2670;
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
		/* EXEC SQL FETCH EPICK_LOGCR INTO
			:pSource->aiInputID,
			:pSource->asSourceID,
			:pSource->aiByte,
			:pSource->asFileName,
			:pSource->asDealBeginDate,
			:pSource->asDealEndDate,
			:pSource->aiSeq,
			:pSource->asState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1000;
  sqlstm.offset = (unsigned int  )2685;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiByte);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )81;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asDealBeginDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asDealEndDate);
  sqlstm.sqhstl[5] = (unsigned long )15;
  sqlstm.sqhsts[5] = (         int  )15;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiSeq);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asState);
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


		CheckSqlError("Fetch EPICK_LOGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE EPICK_LOGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 16;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2732;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PICK_LOG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iInputID=			pSource->aiInputID[iCurPos];

		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);

		p->iByte=			pSource->aiByte[iCurPos];

		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sDealBeginDate,	pSource->asDealBeginDate[iCurPos]);
		strcpy(p->sDealEndDate,		pSource->asDealEndDate[iCurPos]);

		p->iSeq=			pSource->aiSeq[iCurPos];

		strcpy(p->sState,		pSource->asState[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sState);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表PICK_LOG的链表释放函数**/
void DestroyPickLog(struct PickLogStruct *ptHead)
{
	struct PickLogStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitPickLog(char sSourceID[],char sTableName[],
	struct PickLogStruct **pptHead)
{
	int iCnt=0;
	static struct PickLogStruct *pTemp,*ptHead=NULL;
	struct PickLogStruct Temp;
	struct PickLogStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyPickLog(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PickLogStructIn));
	sprintf(TempIn.sTableName,sTableName);
	/*MODIFYHERE*/
	sprintf(TempIn.sCondition,"\n\
		WHERE SOURCE_ID='%s' AND \n\
			DEAL_END_DATE>trunc(SYSDATE)-300",
				sSourceID);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetPickLogToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct PickLogStruct*)
			malloc(sizeof(struct PickLogStruct)))==NULL){

			DestroyPickLog(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct PickLogStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
/*		if((++iCnt%10000)==0)
			WriteProcMsg("加载表PICK_LOG记录数%d",iCnt);*/
	}

/*	WriteProcMsg("加载表PICK_LOG完毕总记录数%d",iCnt);*/

	return iCnt;
}

/*单条数据从用动态SQL从SETT_LOG取数据*/
int SDGetSettLogToStruct(struct SettLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				MODULE,\n\
				SETT_CARRIER_ID,\n\
				LATN_ID,\n\
				nvl(SETT_CYCLE_ID,-1),\n\
				to_char(SETT_ITEM_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				nvl(STEP,'-1'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2747;
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


		CheckSqlError(" PREPARE SETT_LOGSCR SETT_LOGCR");

		/* EXEC SQL DECLARE SETT_LOGCR CURSOR FOR SETT_LOGSCR; */ 

		CheckSqlError("Declare SETT_LOGCR");

		/* EXEC SQL OPEN SETT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2766;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_LOGCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH SETT_LOGCR INTO
			:p->iInputID,
			:p->sModule,
			:p->iSettCarrierID,
			:p->iLatnID,
			:p->iSettCycleID,
			:p->sSettItemDate,
			:p->sDealBeginDate,
			:p->sDealEndDate,
			:p->sStep,
			:p->sState,
			:p->sStateDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2781;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&(p->iSettCarrierID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iLatnID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iSettCycleID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sSettItemDate);
  sqlstm.sqhstl[5] = (unsigned long )15;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sStep);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sStateDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
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


		CheckSqlError("Fetch SETT_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE SETT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2840;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE SETT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2855;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sModule);
		AllTrim(p->sSettItemDate);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sStep);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);

	return TRUE;
}

/*单条数据动态SQL向SETT_LOG写数据*/
int SDInsertStructToSettLog(struct SettLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				MODULE,\n\
				SETT_CARRIER_ID,\n\
				LATN_ID,\n\
				SETT_CYCLE_ID,\n\
				SETT_ITEM_DATE,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				STEP,\n\
				STATE,\n\
				STATE_DATE)\n\
			VALUES (\n\
				:iInputID,\n\
				:sModule,\n\
				:iSettCarrierID,\n\
				:iLatnID,\n\
				:iSettCycleID,\n\
				to_date(:sSettItemDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				:sStep,\n\
				:sState,\n\
				to_date(:sStateDate,'yyyymmddhh24miss')\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2870;
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


		if(CheckSqlResult("Prepare insert statement SETT_LOG")<0) return -1;

		/* EXEC SQL EXECUTE SETT_LOGTRG USING
				:p->iInputID,
				:p->sModule,
				:p->iSettCarrierID,
				:p->iLatnID,
				:p->iSettCycleID,
				:p->sSettItemDate,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sStep,
				:p->sState,
				:p->sStateDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2889;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&(p->iSettCarrierID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&(p->iLatnID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(p->iSettCycleID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sSettItemDate);
  sqlstm.sqhstl[5] = (unsigned long )15;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sStep);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sState);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(p->sStateDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
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


		if(CheckSqlResult("Dyn insert into SETT_LOG")<0) return -1;

	return 0;
}
/*单条数据静态SQL向PROC_CTRL写数据*/
int SSInsertStructToProcCtrl(struct ProcCtrlStruct *p)
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		/* EXEC SQL INSERT INTO PROC_CTRL (
				INPUT_ID,
				FILE_NAME,
				CREATED_DATE,
				DEAL_DATE,
				STATE,
				CREATE_CMD,
				PROC_CMD)
			VALUES (
				:p->iInputID,
				:p->sFileName,
				to_date(:p->sCreatedDate,'yyyymmddhh24miss'),
				to_date(:p->sDealDate,'yyyymmddhh24miss'),
				:p->sState,
				:p->sCreateCmd,
				:p->sProcCmd
			); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into PROC_CTRL (INPUT_ID,FILE_NAME,CREATED_DATE,DEA\
L_DATE,STATE,CREATE_CMD,PROC_CMD) values (:b0,:b1,to_date(:b2,'yyyymmddhh24mi\
ss'),to_date(:b3,'yyyymmddhh24miss'),:b4,:b5,:b6)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2948;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[1] = (unsigned long )256;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sCreatedDate);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sDealDate);
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
  sqlstm.sqhstv[5] = (unsigned char  *)(p->sCreateCmd);
  sqlstm.sqhstl[5] = (unsigned long )256;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(p->sProcCmd);
  sqlstm.sqhstl[6] = (unsigned long )256;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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


		if(CheckSqlResult("insert into PROC_CTRL")<0) return -1;

	return 0;
}

int NewProcCtrl(char sFileName[],char sCreateCmd[])
{
	struct ProcCtrlStruct Temp;
	
	bzero((void*)&Temp,sizeof(struct ProcCtrlStruct));
	
	if((Temp.iInputID=GetInputID())<0) return -1;

	strncpy(Temp.sFileName,	sFileName,255);
	strcpy(Temp.sState,"0");
	GetHostTime(Temp.sCreatedDate);
	GetHostTime(Temp.sDealDate);
	strncpy(Temp.sCreateCmd,sCreateCmd,255);
	strcpy(Temp.sProcCmd,"null");

	if(SSInsertStructToProcCtrl(&Temp)<0) return -1;
	
	return Temp.iInputID;
}
int CheckProcCtrl(char sFileName[])
{
	int iInputID=0;
	char sTempFileName[256];
	
	strncpy(sTempFileName,sFileName,255); sTempFileName[255]=0;
	AllTrim(sTempFileName);
	
	/* EXEC SQL SELECT INPUT_ID INTO :iInputID FROM PROC_CTRL
		WHERE FILE_NAME=:sTempFileName AND 
			STATE='0'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select INPUT_ID into :b0  from PROC_CTRL where (FILE_NAME=:\
b1 and STATE='0')";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2991;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iInputID;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempFileName;
 sqlstm.sqhstl[1] = (unsigned long )256;
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


	if(CheckSqlResult("GET INPUT_ID FROM PROC_CTRL")<0) return -1;
	
	if(NoDataFetched) return 0;
	
	return iInputID;
	
}
int BeginProcCtrl(int iInputID)
{
	/* EXEC SQL UPDATE PROC_CTRL 
		SET STATE='1'
		WHERE INPUT_ID=:iInputID; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update PROC_CTRL  set STATE='1' where INPUT_ID=:b0";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3014;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iInputID;
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


	
	return CheckSqlResult("UPDATE PROC_CTRL STATE BEGIN");
}
int EndProcCtrl(int iInputID,char sState[],char sProcCmd[])
{
	char sTempState[2],sTempProcCmd[256];
	
	strncpy(sTempState,sState,1); sTempState[1]=0;
	strncpy(sTempProcCmd,sProcCmd,255); sTempProcCmd[255]=0;
	
	/* EXEC SQL UPDATE PROC_CTRL
		SET STATE=:sTempState,
			DEAL_DATE=SYSDATE,
			PROC_CMD=:sTempProcCmd
		WHERE INPUT_ID=:iInputID; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update PROC_CTRL  set STATE=:b0,DEAL_DATE=SYSDATE,PROC_CMD=\
:b1 where INPUT_ID=:b2";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3033;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sTempState;
 sqlstm.sqhstl[0] = (unsigned long )2;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)sTempProcCmd;
 sqlstm.sqhstl[1] = (unsigned long )256;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&iInputID;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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


	return CheckSqlResult("UPDATE PROC_CTRL STATE END");
}

int InsertPickLog(char sSourceID[],int iSize,char sFileName[],
	char sDealBeginDate[], char sDealEndDate[],int iSeq,
	char sFileType[],int iTacheID,char sAppID[])
{
/*** $source $size1 $filename $dealbegindate $dealenddate $seq*/
	
	char sBaseName[256];
	struct PickLogStruct Temp;
/*	
	if(NewProcCtrl(sFileName,"pick")<0) return -1;
*/	
	bzero((void*)&Temp,sizeof(struct PickLogStruct));
	
	GetBaseName(sFileName,sBaseName);
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iByte=iSize;
	strcpy(Temp.sFileName,sBaseName);
	strcpy(Temp.sDealBeginDate,sDealBeginDate);
	strcpy(Temp.sDealEndDate,sDealEndDate);
	Temp.iSeq=iSeq;
	
	strcpy(Temp.sState,"A");
	strcpy(Temp.sFileType,sFileType);
	Temp.iTacheID=iTacheID;
	strcpy(Temp.sAppID,sAppID);
	
	TrimAll(Temp.sSourceID);
	
	Temp.iInputID=GetInputID();
	
	if(SDInsertStructToPickLog(&Temp,"PICK_LOG")<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
		
	return 0;
}
char GetLogFileType(char cSplitType)
{
	char cFileType='C';
	
	cFileType='C';

	if(cSplitType>='N'&&cSplitType<='Z')cFileType='N';
	else if(cSplitType=='a')cFileType='A';
	else if(cSplitType=='e')cFileType='E';
	
	return cFileType;
}
int WritePrepLog(struct PrepLogStruct *p,int iErrCnt,int iAbnoCnt,
	char sPrefix[],char sSplitStr[],char sOutName[])
{
	int i=0,iDupCnt=0;
	char	sTempName[256],sTempDate[9];
	char	oriPrefix[256],stdPrefix[256];
	struct TinySplitStruct *pTinySplit=NULL,*ptPre,*ptCur;

	strncpy(sTempDate,p->sDataDate,8);sTempDate[8]=0;
	sprintf(sOutName,"%s%s",sTempDate,p->sOriFileName);

	if(InitTinySplitList(p->sSourceID,sOutName,&pTinySplit)<0)
		return -1;

	for(i=0;i<strlen(sSplitStr);i++){

		/*如果是异常单或错误话单*/
		if(sSplitStr[i]=='a'||sSplitStr[i]=='e'){
			sprintf(p->sFileName,"%s.%s.%c",
				sPrefix,p->sModule,sSplitStr[i]);
			
			if(sSplitStr[i]=='a')p->iCnt=iAbnoCnt;
			else		p->iCnt=iErrCnt;
			p->sFileType[0]=GetLogFileType(sSplitStr[i]);
	
			if(SDInsertStructToPrepLog(p,"PREP_LOG")<0)return -1;
			continue;
		}
		
		sprintf(oriPrefix,"%s.%c",sOutName,sSplitStr[i]);
		sprintf(stdPrefix,"%s.%s.%c",sPrefix,p->sModule,sSplitStr[i]);
		
		/*错误话单或者忽略话单，以及未按KEY拆分的话单*/
		
		p->sFileType[0]=GetLogFileType(sSplitStr[i]);

		if(SearchTinySplit(pTinySplit,sSplitStr[i])==NOTFOUND){

			sprintf(sTempName,"%s.tmp",oriPrefix);
			p->iCnt=FileLines(sTempName);

			sprintf(p->sFileName,"%s",stdPrefix);

			if(SDInsertStructToPrepLog(p,"PREP_LOG")<0)return -1;

			/*写重单文件日志*/
			sprintf(sTempName,"%s.DUP",oriPrefix);
			if(!IsFile(sTempName))continue;
			
			strcpy(p->sFileType,"D");
			p->iCnt=FileLines(sTempName);

			sprintf(p->sFileName,"%s.DUP",stdPrefix);
			
			if(SDInsertStructToPrepLog(p,"PREP_LOG")<0)return -1;
			continue;
		}
		
		/*按key拆分的话单*/
		ptCur=pTinySplit;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			if(sSplitStr[i]!=ptPre->sSplitType[0]) continue;
			
			p->sFileType[0]=GetLogFileType(sSplitStr[i]);
			/*如果有对应的重单文件则写重单日志*/
			iDupCnt=0;
			sprintf(sTempName,"%s.%s.DUP",oriPrefix,ptPre->sKey);
			if(IsFile(sTempName)){
				sprintf(p->sFileName,"%s.%s.DUP",stdPrefix,
					ptPre->sKey);
				strcpy(p->sFileType,"D");
				p->iCnt=iDupCnt=FileLines(sTempName);
				if(SDInsertStructToPrepLog(p,"PREP_LOG")<0)return -1;
			}
			
			p->iCnt=ptPre->iCnt-iDupCnt;

			sprintf(p->sFileName,"%s.%s",stdPrefix,ptPre->sKey);
	
			if(SDInsertStructToPrepLog(p,"PREP_LOG")<0) return -1;
		}
	}
	DestroyList((LIST*)pTinySplit);
	
	return 0;
}
int InsertPrepLog(char sSourceID[],char sModule[],char sOriFileName[],
	char sDataDate[],int iByte,int iNormalCnt,int iErrCnt,int iAbnoCnt,
	char sDealBeginDate[],char sDealEndDate[],char sSplitStr[],
	char sState[],char sOutName[],
	char sInFileType[],int iTacheID,char sAppID[],char sPrefix[])
{
	char sTempSource[7],sTempDate[9];
	struct PrepLogStruct Temp;
	struct PrepProcLogStruct ProcLog;

	strcpy(Temp.sDataDate,sDataDate);
	
	strncpy(sTempDate,sDataDate,8);sTempDate[8]=0;
	
	strcpy(Temp.sSourceID,	sSourceID);
	strcpy(Temp.sModule,	sModule);
	
	TrimAll(Temp.sSourceID);
	TrimAll(Temp.sModule);
	
	strcpy(Temp.sOriFileName,sOriFileName);
		
	strcpy(Temp.sDealBeginDate,sDealBeginDate);
	strcpy(Temp.sDealEndDate,sDealEndDate);

	strncpy(sTempSource,Temp.sSourceID,6);sTempSource[6]=0;
	RightPad(sTempSource,6,'0');
	
	strcpy(Temp.sState,sState);
	Temp.iTacheID=iTacheID;
	strcpy(Temp.sAppID,sAppID);

	Temp.iInputID=GetInputID();

	ProcLog.iInputID=Temp.iInputID;
	strcpy(ProcLog.sSourceID,Temp.sSourceID);
	strcpy(ProcLog.sModule,Temp.sModule);

	ProcLog.iByte=	iByte;

	ProcLog.iCnt=	iNormalCnt+iErrCnt+iAbnoCnt;
	
	strcpy(ProcLog.sFileName,sOriFileName);
	strcpy(ProcLog.sDealBeginDate,sDealBeginDate);
	strcpy(ProcLog.sDealEndDate,sDealEndDate);
	strcpy(ProcLog.sFileType,sInFileType);

	ProcLog.iTacheID=iTacheID;
	strcpy(ProcLog.sAppID,sAppID);
	
	if(SDInsertStructToPrepProcLog(&ProcLog,"PREP_PROC_LOG")<0)return -1;
		
	if((Temp.iSeq=GetPrepNextSeq(sTempSource,Temp.sDataDate,sModule))<0)
		return -1;
	
	sprintf(sPrefix,"%s%s%05d",sTempSource,sTempDate,Temp.iSeq);
	
	if(WritePrepLog(&Temp,iErrCnt,iAbnoCnt,sPrefix,sSplitStr,sOutName)<0)
		return -1;

	return 0;
}
int WriteBillingLog(struct BillingLogStruct *p,char sPrefix[],char sSplitStr[],
	char sNormalPath[],char sErrPath[])
{
	int i=0;
	char	sPath[256],sTempName[256];
	struct TinySplitStruct *pTinySplit=NULL,*ptPre,*ptCur;
	
	if(InitTinySplitList(p->sSourceID,p->sOriFileName,&pTinySplit)<0)
		return -1;
	
	for(i=0;i<strlen(sSplitStr);i++){

		if(sSplitStr[i]=='a')	strcpy(sPath,sErrPath);
		else			strcpy(sPath,sNormalPath);
		
		if(SearchTinySplit(pTinySplit,sSplitStr[i])==NOTFOUND){

			sprintf(sTempName,"%s%s.%c.tmp",
				sPath,p->sOriFileName,sSplitStr[i]);
			p->iCnt=FileLines(sTempName);

			sprintf(p->sFileName,"%s.%s.BIL.%c",
				sPrefix,p->sModule,sSplitStr[i]);

			if(SDInsertStructToBillingLog(p,"BILLING_LOG")<0)
				return -1;
			continue;
		}
		
		ptCur=pTinySplit;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			if(sSplitStr[i]!=ptPre->sSplitType[0]) continue;
			
			p->iCnt=ptPre->iCnt;
			sprintf(p->sFileName,"%s.%s.BIL.%c.%s",sPrefix,
				p->sModule,sSplitStr[i],ptPre->sKey);
				
			if(SDInsertStructToBillingLog(p,"BILLING_LOG")<0)
				return -1;
		}
	}
	DestroyList((LIST*)pTinySplit);

	return 0;
}
int InsertBillingLog(char sSourceID[],char sModule[],char sOriFileName[],
	int iByte,int iCnt,char sDataDate[],char sDealBeginDate[],
	char sDealEndDate[],char sState[],char sSplitStr[],char sNormalPath[],
	char sErrPath[],char sInType[],char sOutType[],
	char sAppCode[],int iTacheID,char sAppID[],char sPrefix[])
{
	char sTemp[40],sTempSource[7];
	struct BillingLogStruct Temp;
	struct BillingProcLogStruct ProcLog;

	strcpy(sPrefix,"");
	bzero((void*)&Temp,sizeof(struct BillingLogStruct));

	strcpy(Temp.sSourceID,	sSourceID);
	strcpy(Temp.sModule,	sModule);
	GetBaseName(sOriFileName,Temp.sOriFileName);
	Temp.iCnt=		iCnt;

	TrimAll(Temp.sSourceID);
	TrimAll(Temp.sModule);
	
	strncpy(sTempSource,Temp.sSourceID,6);sTempSource[6]=0;
	RightPad(sTempSource,6,'0');

	strcpy(Temp.sDataDate,	sDataDate);
	strcpy(Temp.sDataDate+8,"000000");

	strcpy(Temp.sDealBeginDate,	sDealBeginDate);
	strcpy(Temp.sDealEndDate,	sDealEndDate);

	strcpy(Temp.sState,sState);
	strcpy(Temp.sFileType,	sOutType);	
	strcpy(Temp.sAppCode,	sAppCode);
	Temp.iTacheID=iTacheID;
	strcpy(Temp.sAppID,	sAppID);	
	
	bzero((void*)&ProcLog,sizeof(struct BillingProcLogStruct));
	ProcLog.iInputID=GetInputID();
	strcpy(ProcLog.sSourceID,Temp.sSourceID);
	strcpy(ProcLog.sModule, Temp.sModule);
	strcpy(ProcLog.sFileName,Temp.sOriFileName);
	strcpy(ProcLog.sSplitStr,sSplitStr);
	ProcLog.iByte=iByte;
	ProcLog.iCnt=iCnt;
	strcpy(ProcLog.sDealBeginDate,	sDealBeginDate);
	strcpy(ProcLog.sDealEndDate,	sDealEndDate);
	strcpy(ProcLog.sFileType,	sInType);
	strcpy(ProcLog.sAppCode,		sAppCode);
	ProcLog.iTacheID=iTacheID;
	strcpy(ProcLog.sAppID,	sAppID);	
	
	if(SDInsertStructToBillingProcLog(&ProcLog,"BILLING_PROC_LOG")<0)
		return -1;

	Temp.iInputID=ProcLog.iInputID;
	
	/*当SOURCE_ID一致的时候，则不改，不一致的时候重新分配*/
	/*如果是内部的文件名，则不改名，$SOURCEYYYYMMDDNNNNN.开头的文件*/
	if(IsInternalName(Temp.sOriFileName)){
		strncpy(sTemp,Temp.sOriFileName+14,5);sTemp[5]=0;
		Temp.iSeq=atoi(sTemp);
		strncpy(sPrefix,Temp.sOriFileName,19);sPrefix[19]=0;
	}
	else{
		if((Temp.iSeq=GetBillNextSeq(sTempSource,Temp.sDataDate,
			sModule))<0) return -1;
		strncpy(sTemp,Temp.sDataDate,8);sTemp[8]=0;
		sprintf(sPrefix,"%s%s%05d",sTempSource,sTemp,Temp.iSeq);
	}

	if(WriteBillingLog(&Temp,sPrefix,sSplitStr,sNormalPath,sErrPath)<0)
		return -1;

	return 0;
}
/*单条数据动态SQL向BILLING_PROC_LOG写数据*/
int SDInsertStructToBillingProcLog(struct BillingProcLogStruct *p,char sTableName[])
{


/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				FILE_NAME,\n\
				SPLIT_STR,\n\
				BYTE,\n\
				CNT,\n\
				DEAL_BEGIN_DATE,\n\
				DEAL_END_DATE,\n\
				CUR_FILE_NAME,\n\
				NORMAL_CNT,\n\
				ABNO_CNT,\n\
				NEW_CNT,\n\
				FILE_TYPE,\n\
				APP_CODE,\n\
				TACHE_ID,\n\
				APP_ID)\n\
			VALUES (\n\
				:iInputID,\n\
				:sSourceID,\n\
				:sModule,\n\
				:sFileName,\n\
				:sSplitStr,\n\
				:iByte,\n\
				:iCnt,\n\
				to_date(:sDealBeginDate,'yyyymmddhh24miss'),\n\
				to_date(:sDealEndDate,'yyyymmddhh24miss'),\n\
				:sCurFileName,\n\
				:iNormalCnt,\n\
				:iAbnoCnt,\n\
				:iNewCnt,\n\
				:sFileType,\n\
				:sAppCode,\n\
				:iTacheID,\n\
				:sAppID\n\
			)",sTableName);

		/* EXEC SQL PREPARE BILLING_PROC_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3060;
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


		if(CheckSqlResult("Prepare insert statement BILLING_PROC_LOG")<0) return -1;

		/* EXEC SQL EXECUTE BILLING_PROC_LOGTRG USING
				:p->iInputID,
				:p->sSourceID,
				:p->sModule,
				:p->sFileName,
				:p->sSplitStr,
				:p->iByte,
				:p->iCnt,
				:p->sDealBeginDate,
				:p->sDealEndDate,
				:p->sCurFileName,
				:p->iNormalCnt,
				:p->iAbnoCnt,
				:p->iNewCnt,
				:p->sFileType,
				:p->sAppCode,
				:p->iTacheID,
				:p->sAppID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3079;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sSplitStr);
  sqlstm.sqhstl[4] = (unsigned long )21;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&(p->iByte);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iCnt);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sDealBeginDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDealEndDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(p->sCurFileName);
  sqlstm.sqhstl[9] = (unsigned long )81;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&(p->iNormalCnt);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&(p->iAbnoCnt);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&(p->iNewCnt);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(p->sAppCode);
  sqlstm.sqhstl[14] = (unsigned long )9;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&(p->iTacheID);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(p->sAppID);
  sqlstm.sqhstl[16] = (unsigned long )11;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
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


		if(CheckSqlResult("Dyn insert into BILLING_PROC_LOG")<0) return -1;

	return 0;
}
int InsertRollLog(char sSourceID[],char sModule[],char sFileName[],
	int iSeq,char sDataDate[],char sDealBeginDate[],char sDealEndDate[],
	char sNormalPath[],char sFileType[],char sAppCode[],
	int iTacheID,char sAppID[])
{
	char sTargetTemp[256],sTargetList[1024];
	struct RollLogStruct Temp;
	struct RollProcLogStruct Log;
	struct TinyRollLogStruct *pTemp,*ptHead=NULL;

	bzero((void*)&Temp,sizeof(struct RollLogStruct));
	bzero((void*)&Log,sizeof(struct RollProcLogStruct));

	strcpy(sTargetList,"");
/*初始化TEMP变量*/
	Temp.iInputID=	GetInputID();
	strcpy(Temp.sSourceID,	sSourceID);
	strcpy(Temp.sModule,	sModule);
	Temp.iCnt=	0;

	strcpy(Temp.sDataDate,	sDataDate);
	strcpy(Temp.sDataDate+8,"000000");
	
	strcpy(Temp.sDealBeginDate,	sDealBeginDate);
	strcpy(Temp.sDealEndDate,	sDealEndDate);
	Temp.iSeq=	iSeq;
	
	strcpy(Temp.sState,"A");
	strcpy(Temp.sFileType,	sFileType);
	strcpy(Temp.sAppCode,	sAppCode);
	Temp.iTacheID=		iTacheID;
	strcpy(Temp.sAppID,	sAppID);
	
/*初始化LOG变量*/
	Log.iInputID=	Temp.iInputID;
	strcpy(Log.sSourceID,Temp.sSourceID);
	strcpy(Log.sModule,  Temp.sModule);
	strcpy(Log.sState,   Temp.sState);
	strcpy(Log.sDealBeginDate,Temp.sDealBeginDate);
	strcpy(Log.sDealEndDate,Temp.sDealEndDate);
	strcpy(Log.sFileType,Temp.sFileType);
	strcpy(Log.sAppCode,Temp.sAppCode);
	strcpy(Log.sAppID,Temp.sAppID);
	Log.iTacheID=	Temp.iTacheID;
	
	if(InitRollLogCtl(sFileName,&ptHead)<0) return -1;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		Log.iCnt= pTemp->iCnt;
		strcpy(Log.sOriFileName,pTemp->sOriFileName);
		
		Log.iCnt= pTemp->iCnt;
		strcpy(Log.sOriFileName,pTemp->sOriFileName);
		strcpy(Log.sFileName,pTemp->sFileName);
		strcpy(Temp.sFileName,pTemp->sFileName);

		if(strstr(sTargetList,pTemp->sFileName)==NULL){

			strcat(sTargetList,pTemp->sFileName);
			strcat(sTargetList,",");
			sprintf(sTargetTemp,"%s%s.tmp",
				sNormalPath,pTemp->sFileName);
			Temp.iCnt=FileLines(sTargetTemp);

			if(SDInsertStructToRollLog(&Temp,"ROLL_LOG")<0)
				return -1;
		}

		free(pTemp);

		if(SDInsertStructToRollProcLog(&Log,"ROLL_PROC_LOG")<0)
			return -1;

	}
	return 0;
}
int InsertRcylLog(char sSourceID[],char sModule[],char sFileName[],
	int iSeq,char sDataDate[],char sDealBeginDate[],char sDealEndDate[],
	char sNormalPath[],char sFileType[],char sAppCode[],
	int iTacheID,char sAppID[])
{
	char sTargetTemp[256],sTargetList[1024];
	struct RollLogStruct Temp;
	struct RollProcLogStruct Log;
	struct TinyRollLogStruct *pTemp,*ptHead=NULL;

	bzero((void*)&Temp,sizeof(struct RollLogStruct));
	bzero((void*)&Log,sizeof(struct RollProcLogStruct));

	strcpy(sTargetList,"");
/*初始化TEMP变量*/
	Temp.iInputID=	GetInputID();
	strcpy(Temp.sSourceID,	sSourceID);
	strcpy(Temp.sModule,	sModule);
	Temp.iCnt=	0;

	strcpy(Temp.sDataDate,	sDataDate);
	strcpy(Temp.sDataDate+8,"000000");
	
	strcpy(Temp.sDealBeginDate,	sDealBeginDate);
	strcpy(Temp.sDealEndDate,	sDealEndDate);
	Temp.iSeq=	iSeq;
	
	strcpy(Temp.sState,"A");
	strcpy(Temp.sFileType,	sFileType);
	strcpy(Temp.sAppCode,	sAppCode);
	Temp.iTacheID=		iTacheID;
	strcpy(Temp.sAppID,	sAppID);
/*初始化LOG变量*/
	Log.iInputID=	Temp.iInputID;
	strcpy(Log.sSourceID,Temp.sSourceID);
	strcpy(Log.sModule,  Temp.sModule);
	strcpy(Log.sState,   Temp.sState);
	strcpy(Log.sDealBeginDate,Temp.sDealBeginDate);
	strcpy(Log.sDealEndDate,Temp.sDealEndDate);
	strcpy(Log.sFileType,Temp.sFileType);
	strcpy(Log.sAppCode,Temp.sAppCode);
	strcpy(Log.sAppID,Temp.sAppID);
	Log.iTacheID=	Temp.iTacheID;

	if(InitRollLogCtl(sFileName,&ptHead)<0) return -1;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		Log.iCnt= pTemp->iCnt;
		strcpy(Log.sOriFileName,pTemp->sOriFileName);
		strcpy(Log.sFileName,pTemp->sFileName);
		strcpy(Temp.sFileName,pTemp->sFileName);

		if(strstr(sTargetList,pTemp->sFileName)==NULL){

			strcat(sTargetList,pTemp->sFileName);
			strcat(sTargetList,",");
			sprintf(sTargetTemp,"%s%s.tmp",
				sNormalPath,pTemp->sFileName);
			Temp.iCnt=FileLines(sTargetTemp);

			if(SDInsertStructToRollLog(&Temp,"RCYL_LOG")<0)
				return -1;
		}
		
		free(pTemp);

		if(SDInsertStructToRollProcLog(&Log,"RCYL_PROC_LOG")<0)
			return -1;

	}
	return 0;
}	
int PutLogCheck(char sSourceID[20],char sFileName[80],int iChkDays)
{
	int iCnt;
	char sTempSourceID[20],sTempFileName[80];
	
	strcpy(sTempSourceID,	sSourceID);
	strcpy(sTempFileName,	sFileName);
	
	if(iChkDays>0){
		/* EXEC SQL SELECT COUNT(*) INTO :iCnt
			FROM PUT_LOG
			WHERE SOURCE_ID=:sSourceID AND
				FILE_NAME=:sFileName AND
				STATE='A' AND
				DEAL_END_DATE>SYSDATE-:iChkDays; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(*)  into :b0  from PUT_LOG where (((SOURCE_ID\
=:b1 and FILE_NAME=:b2) and STATE='A') and DEAL_END_DATE>(SYSDATE-:b3))";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3162;
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
  sqlstm.sqhstv[1] = (unsigned char  *)sSourceID;
  sqlstm.sqhstl[1] = (unsigned long )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)sFileName;
  sqlstm.sqhstl[2] = (unsigned long )80;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&iChkDays;
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


	}
	else{
		/* EXEC SQL SELECT COUNT(*) INTO :iCnt
			FROM PUT_LOG
			WHERE SOURCE_ID=:sSourceID AND
				FILE_NAME=:sFileName AND
				STATE='A' ; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select count(*)  into :b0  from PUT_LOG where ((SOURCE_ID=\
:b1 and FILE_NAME=:b2) and STATE='A')";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3193;
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
  sqlstm.sqhstv[1] = (unsigned char  *)sSourceID;
  sqlstm.sqhstl[1] = (unsigned long )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)sFileName;
  sqlstm.sqhstl[2] = (unsigned long )80;
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


	}

	if(CheckSqlResult("COUNT PUT_LOG")<0) return -1;
	
	if(iCnt==0) return 0;
	return 1;	
}


int InsertPutLog(char sSourceID[],int iSize,char sFileName[],
	char sDealBeginDate[], char sDealEndDate[],int iSeq,
	char sFileType[],int iTacheID,char sAppID[])
{
/*** $source $size1 $filename $dealbegindate $dealenddate $seq*/
	
	char sBaseName[256];
	struct PickLogStruct Temp;
	
	bzero((void*)&Temp,sizeof(struct PickLogStruct));
	
	GetBaseName(sFileName,sBaseName);
	
	strcpy(Temp.sSourceID,sSourceID);
	Temp.iByte=iSize;
	strcpy(Temp.sFileName,sBaseName);
	strcpy(Temp.sDealBeginDate,sDealBeginDate);
	strcpy(Temp.sDealEndDate,sDealEndDate);
	Temp.iSeq=iSeq;
	
	strcpy(Temp.sState,"A");
	strcpy(Temp.sFileType,sFileType);
	Temp.iTacheID=iTacheID;
	strcpy(Temp.sAppID,sAppID);
	
	TrimAll(Temp.sSourceID);
	
	Temp.iInputID=GetInputID();
	
	if(SDInsertStructToPickLog(&Temp,"PUT_LOG")<0){
		WriteErrStackAlert();
		RollbackWorkRelease();
		return -1;
	}
		
	return 0;
}

/*批量数据动态从PREP_LOG中用结构缓冲方式取数据*/
int EGetPrepLogToStruct(struct PrepLogStruct *p,
	struct PrepLogStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				STATE,\n\
				CNT,\n\
				FILE_NAME,\n\
				to_char(DEAL_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(DEAL_END_DATE,'yyyymmddhh24miss'),\n\
				to_char(DATA_DATE,'yyyymmddhh24miss'),\n\
				SEQ,\n\
				ORI_FILE_NAME,\n\
				nvl(FILE_TYPE,' '),\n\
				nvl(APP_ID,' '),\n\
				nvl(TACHE_ID,0)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PREP_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3220;
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


		CheckSqlError(" PREPARE PREP_LOGSCR PREP_LOGCR");

		/* EXEC SQL DECLARE PREP_LOGCR CURSOR FOR PREP_LOGSCR; */ 

		CheckSqlError("Declare PREP_LOGCR");

		/* EXEC SQL OPEN PREP_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3239;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PREP_LOGCR;");


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

		/* EXEC SQL CLOSE PREP_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3254;
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
		/* EXEC SQL FETCH PREP_LOGCR INTO
			:pSource->aiInputID,
			:pSource->asSourceID,
			:pSource->asModule,
			:pSource->asState,
			:pSource->aiCnt,
			:pSource->asFileName,
			:pSource->asDealBeginDate,
			:pSource->asDealEndDate,
			:pSource->asDataDate,
			:pSource->aiSeq,
			:pSource->asOriFileName,
			:pSource->asFileType,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3269;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )4;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )41;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )15;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asDataDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiSeq);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asOriFileName);
  sqlstm.sqhstl[10] = (unsigned long )81;
  sqlstm.sqhsts[10] = (         int  )81;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )6;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[12] = (unsigned long )11;
  sqlstm.sqhsts[12] = (         int  )11;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch PREP_LOGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PREP_LOGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3340;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PREP_LOG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iInputID=			pSource->aiInputID[iCurPos];

		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);
		strcpy(p->sModule,		pSource->asModule[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);

		p->iCnt=			pSource->aiCnt[iCurPos];

		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sDealBeginDate,	pSource->asDealBeginDate[iCurPos]);
		strcpy(p->sDealEndDate,		pSource->asDealEndDate[iCurPos]);
		strcpy(p->sDataDate,		pSource->asDataDate[iCurPos]);

		p->iSeq=			pSource->aiSeq[iCurPos];

		strcpy(p->sOriFileName,		pSource->asOriFileName[iCurPos]);
		strcpy(p->sFileType,		pSource->asFileType[iCurPos]);
		strcpy(p->sAppID,		pSource->asAppID[iCurPos]);

		p->iTacheID=			pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sState);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sDataDate);
		AllTrim(p->sOriFileName);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据动态从PREP_PROC_LOG中用结构缓冲方式取数据*/
int EGetPrepProcLogToStruct(struct PrepProcLogStruct *p,
	struct PrepProcLogStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				INPUT_ID,\n\
				SOURCE_ID,\n\
				MODULE,\n\
				BYTE,\n\
				CNT,\n\
				FILE_NAME,\n\
				to_char(nvl(DEAL_BEGIN_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(DEAL_END_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(NORMAL_CNT,0),\n\
				nvl(ERR_CNT,0),\n\
				nvl(DUP_CNT,0),\n\
				nvl(ABNO_CNT,0),\n\
				nvl(NEW_CNT,0),\n\
				nvl(FILE_TYPE,' '),\n\
				nvl(APP_ID,' '),\n\
				nvl(TACHE_ID,0)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PREP_PROC_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3355;
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


		CheckSqlError(" PREPARE PREP_PROC_LOGSCR PREP_PROC_LOGCR");

		/* EXEC SQL DECLARE PREP_PROC_LOGCR CURSOR FOR PREP_PROC_LOGSCR; */ 

		CheckSqlError("Declare PREP_PROC_LOGCR");

		/* EXEC SQL OPEN PREP_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3374;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PREP_PROC_LOGCR;");


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

		/* EXEC SQL CLOSE PREP_PROC_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3389;
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
		/* EXEC SQL FETCH PREP_PROC_LOGCR INTO
			:pSource->aiInputID,
			:pSource->asSourceID,
			:pSource->asModule,
			:pSource->aiByte,
			:pSource->aiCnt,
			:pSource->asFileName,
			:pSource->asDealBeginDate,
			:pSource->asDealEndDate,
			:pSource->aiNormalCnt,
			:pSource->aiErrCnt,
			:pSource->aiDupCnt,
			:pSource->aiAbnoCnt,
			:pSource->aiNewCnt,
			:pSource->asFileType,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3404;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiInputID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )4;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiByte);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiCnt);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asDealBeginDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )15;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asDealEndDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiNormalCnt);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiErrCnt);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiDupCnt);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiAbnoCnt);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiNewCnt);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )6;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )11;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch PREP_PROC_LOGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PREP_PROC_LOGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3483;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PREP_PROC_LOG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iInputID=			pSource->aiInputID[iCurPos];

		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);
		strcpy(p->sModule,		pSource->asModule[iCurPos]);

		p->iByte=			pSource->aiByte[iCurPos];
		p->iCnt=			pSource->aiCnt[iCurPos];

		strcpy(p->sFileName,		pSource->asFileName[iCurPos]);
		strcpy(p->sDealBeginDate,	pSource->asDealBeginDate[iCurPos]);
		strcpy(p->sDealEndDate,		pSource->asDealEndDate[iCurPos]);
		
		p->iNormalCnt=			pSource->aiNormalCnt[iCurPos];
		p->iErrCnt=			pSource->aiErrCnt[iCurPos];
		p->iDupCnt=			pSource->aiDupCnt[iCurPos];
		p->iAbnoCnt=			pSource->aiAbnoCnt[iCurPos];
		p->iNewCnt=			pSource->aiNewCnt[iCurPos];

		strcpy(p->sFileType,		pSource->asFileType[iCurPos]);
		strcpy(p->sAppID,		pSource->asAppID[iCurPos]);

		p->iTacheID=			pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sFileName);
		AllTrim(p->sDealBeginDate);
		AllTrim(p->sDealEndDate);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/*批量数据结构缓冲写入PICK_CHECK_LOG*/
int EInsertStructToPickCheckLog(struct PickCheckLogStruct *p,
	int iInsertFlag,struct PickCheckLogStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSourceID[iCurPos],	p->sSourceID);
		strcpy(pTarget->asModule[iCurPos],	p->sModule);
		strcpy(pTarget->asFileName[iCurPos],	p->sFileName);
		strcpy(pTarget->asFileDate[iCurPos],	p->sFileDate);
		strcpy(pTarget->asChkFileName[iCurPos],	p->sChkFileName);

		pTarget->aiChkCnt[iCurPos]=		p->iChkCnt;
		pTarget->aiPreCnt[iCurPos]=		p->iPreCnt;

		strcpy(pTarget->asFileType[iCurPos],	p->sFileType);
		strcpy(pTarget->asDealDate[iCurPos],	p->sDealDate);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==PICK_CHECK_LOG_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SOURCE_ID,\n\
				MODULE,\n\
				FILE_NAME,\n\
				FILE_DATE,\n\
				CHK_FILE_NAME,\n\
				CHK_CNT,\n\
				PRE_CNT,\n\
				FILE_TYPE,\n\
				DEAL_DATE)\n\
			VALUES (\n\
				:asSourceID,\n\
				:asModule,\n\
				:asFileName,\n\
				to_date(:asFileDate,'yyyymmddhh24miss'),\n\
				:asChkFileName,\n\
				:aiChkCnt,\n\
				:aiPreCnt,\n\
				:asFileType,\n\
				to_date(:asDealDate,'yyyymmddhh24miss')\n\
			)",sTableName);

		/* EXEC SQL PREPARE PICK_CHECK_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3498;
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


		if(CheckSqlResult("Prepare insert statement PICK_CHECK_LOG")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE PICK_CHECK_LOGTRG USING
				:pTarget->asSourceID,
				:pTarget->asModule,
				:pTarget->asFileName,
				:pTarget->asFileDate,
				:pTarget->asChkFileName,
				:pTarget->aiChkCnt,
				:pTarget->aiPreCnt,
				:pTarget->asFileType,
				:pTarget->asDealDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )3517;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asModule);
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )4;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[2] = (unsigned long )81;
  sqlstm.sqhsts[2] = (         int  )81;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asFileDate);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )15;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asChkFileName);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->aiChkCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiPreCnt);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asFileType);
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )6;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asDealDate);
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


		if(CheckSqlResult("Dyn insert into PICK_CHECK_LOG")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*单条数据从用动态SQL从PICK_CHECK_LOG取数据*/
int SDGetPickCheckLogToStruct(struct PickCheckLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SOURCE_ID,' '),\n\
				nvl(MODULE,' '),\n\
				nvl(FILE_NAME,' '),\n\
				to_char(FILE_DATE,'yyyymmddhh24miss'),\n\
				nvl(CHK_FILE_NAME,' '),\n\
				nvl(CHK_CNT,0),\n\
				nvl(PRE_CNT,0),\n\
				nvl(FILE_TYPE,' '),\n\
				to_char(DEAL_DATE,'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PICK_CHECK_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3568;
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


		CheckSqlError(" PREPARE PICK_CHECK_LOGSCR PICK_CHECK_LOGCR");

		/* EXEC SQL DECLARE PICK_CHECK_LOGCR CURSOR FOR PICK_CHECK_LOGSCR; */ 

		CheckSqlError("Declare PICK_CHECK_LOGCR");

		/* EXEC SQL OPEN PICK_CHECK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3587;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PICK_CHECK_LOGCR;");


	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH PICK_CHECK_LOGCR INTO
			:p->sSourceID,
			:p->sModule,
			:p->sFileName,
			:p->sFileDate,
			:p->sChkFileName,
			:p->iChkCnt,
			:p->iPreCnt,
			:p->sFileType,
			:p->sDealDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3602;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(p->sSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sModule);
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[2] = (unsigned long )81;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(p->sFileDate);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(p->sChkFileName);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&(p->iChkCnt);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iPreCnt);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(p->sFileType);
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(p->sDealDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
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


		CheckSqlError("Fetch PICK_CHECK_LOGCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE PICK_CHECK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3653;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE PICK_CHECK_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3668;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



/* 从缓冲区取数据*/
/*------该部分不需要取数据,只要格式转换-----*/

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sFileName);
		AllTrim(p->sFileDate);
		AllTrim(p->sChkFileName);		
		AllTrim(p->sFileType);
		AllTrim(p->sDealDate);


	return TRUE;
}
int SDGetTabCnt(char sTableName[])
{
	int iCnt=0;
	char statement[4096];

	sprintf(statement,"SELECT count(*) FROM %s",sTableName);

	/* EXEC SQL PREPARE TAB_CNTSCR FROM :statement; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3683;
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


	if(CheckSqlResult(" PREPARE TAB_CNTSCR TAB_CNTCR")<0) return -1;

	/* EXEC SQL DECLARE TAB_CNTCR CURSOR FOR TAB_CNTSCR; */ 

	if(CheckSqlResult("Declare TAB_CNTCR")<0) return -1;

	/* EXEC SQL OPEN TAB_CNTCR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3702;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	if(CheckSqlResult("Open TAB_CNTCR")<0) return -1;

	/* EXEC SQL FETCH TAB_CNTCR INTO
		:iCnt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3717;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&iCnt;
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


	if(CheckSqlResult("Fetch TAB_CNTCR")<0) return -1;

	if(NoDataFetched){
		/* EXEC SQL CLOSE TAB_CNTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3736;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return 0;
	}

	/* EXEC SQL CLOSE TAB_CNTCR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3751;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return iCnt;
}
