
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "gen_supp.pc"
};


static unsigned int sqlctx = 150523;


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
   unsigned char  *sqhstv[21];
   unsigned long  sqhstl[21];
            int   sqhsts[21];
            short *sqindv[21];
            int   sqinds[21];
   unsigned long  sqharm[21];
   unsigned long  *sqharc[21];
   unsigned short  sqadto[21];
   unsigned short  sqtdso[21];
} sqlstm = {12,21};

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
54,0,0,1,0,0,13,77,0,0,12,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
117,0,0,1,0,0,15,102,0,0,0,0,0,1,0,
132,0,0,2,0,0,17,237,0,0,1,1,0,1,0,1,97,0,0,
151,0,0,2,0,0,45,243,0,0,0,0,0,1,0,
166,0,0,2,0,0,15,260,0,0,0,0,0,1,0,
181,0,0,2,0,0,13,268,0,0,10,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
236,0,0,2,0,0,15,291,0,0,0,0,0,1,0,
251,0,0,3,0,0,17,428,0,0,1,1,0,1,0,1,97,0,0,
270,0,0,3,0,0,45,434,0,0,0,0,0,1,0,
285,0,0,3,0,0,15,451,0,0,0,0,0,1,0,
300,0,0,3,0,0,13,459,0,0,11,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
359,0,0,3,0,0,15,483,0,0,0,0,0,1,0,
374,0,0,4,0,0,17,624,0,0,1,1,0,1,0,1,97,0,0,
393,0,0,4,0,0,45,630,0,0,0,0,0,1,0,
408,0,0,4,0,0,15,647,0,0,0,0,0,1,0,
423,0,0,4,0,0,13,655,0,0,14,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
494,0,0,4,0,0,15,682,0,0,0,0,0,1,0,
509,0,0,5,0,0,17,811,0,0,1,1,0,1,0,1,97,0,0,
528,0,0,5,0,0,45,817,0,0,0,0,0,1,0,
543,0,0,5,0,0,15,834,0,0,0,0,0,1,0,
558,0,0,5,0,0,13,842,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
589,0,0,5,0,0,15,859,0,0,0,0,0,1,0,
604,0,0,6,0,0,17,979,0,0,1,1,0,1,0,1,97,0,0,
623,0,0,6,0,0,45,985,0,0,0,0,0,1,0,
638,0,0,6,0,0,15,1002,0,0,0,0,0,1,0,
653,0,0,6,0,0,13,1010,0,0,11,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
712,0,0,6,0,0,15,1034,0,0,0,0,0,1,0,
727,0,0,7,0,0,17,1163,0,0,1,1,0,1,0,1,97,0,0,
746,0,0,7,0,0,45,1169,0,0,0,0,0,1,0,
761,0,0,7,0,0,15,1186,0,0,0,0,0,1,0,
776,0,0,7,0,0,13,1194,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,
819,0,0,7,0,0,15,1214,0,0,0,0,0,1,0,
834,0,0,8,0,0,17,1333,0,0,1,1,0,1,0,1,97,0,0,
853,0,0,8,0,0,45,1339,0,0,0,0,0,1,0,
868,0,0,8,0,0,15,1356,0,0,0,0,0,1,0,
883,0,0,8,0,0,13,1364,0,0,7,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,
926,0,0,8,0,0,15,1384,0,0,0,0,0,1,0,
941,0,0,9,0,0,17,1499,0,0,1,1,0,1,0,1,97,0,0,
960,0,0,9,0,0,45,1505,0,0,0,0,0,1,0,
975,0,0,9,0,0,15,1522,0,0,0,0,0,1,0,
990,0,0,9,0,0,13,1530,0,0,3,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,
1017,0,0,9,0,0,15,1546,0,0,0,0,0,1,0,
1032,0,0,10,0,0,17,1662,0,0,1,1,0,1,0,1,97,0,0,
1051,0,0,10,0,0,45,1668,0,0,0,0,0,1,0,
1066,0,0,10,0,0,15,1685,0,0,0,0,0,1,0,
1081,0,0,10,0,0,13,1693,0,0,10,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
1136,0,0,10,0,0,15,1716,0,0,0,0,0,1,0,
1151,0,0,11,0,0,17,1850,0,0,1,1,0,1,0,1,97,0,0,
1170,0,0,11,0,0,45,1856,0,0,0,0,0,1,0,
1185,0,0,11,0,0,15,1873,0,0,0,0,0,1,0,
1200,0,0,11,0,0,13,1881,0,0,17,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,
1283,0,0,11,0,0,15,1911,0,0,0,0,0,1,0,
1298,0,0,12,0,0,17,2052,0,0,1,1,0,1,0,1,97,0,0,
1317,0,0,12,0,0,45,2058,0,0,0,0,0,1,0,
1332,0,0,12,0,0,15,2075,0,0,0,0,0,1,0,
1347,0,0,12,0,0,13,2083,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,
1390,0,0,12,0,0,15,2103,0,0,0,0,0,1,0,
1405,0,0,13,0,0,17,2223,0,0,1,1,0,1,0,1,97,0,0,
1424,0,0,13,0,0,45,2229,0,0,0,0,0,1,0,
1439,0,0,13,0,0,15,2246,0,0,0,0,0,1,0,
1454,0,0,13,0,0,13,2254,0,0,6,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,
1493,0,0,13,0,0,15,2273,0,0,0,0,0,1,0,
1508,0,0,14,0,0,17,2398,0,0,1,1,0,1,0,1,97,0,0,
1527,0,0,14,0,0,45,2404,0,0,0,0,0,1,0,
1542,0,0,14,0,0,15,2421,0,0,0,0,0,1,0,
1557,0,0,14,0,0,13,2429,0,0,16,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,
1636,0,0,14,0,0,15,2458,0,0,0,0,0,1,0,
1651,0,0,15,0,0,17,2604,0,0,1,1,0,1,0,1,97,0,0,
1670,0,0,15,0,0,45,2610,0,0,0,0,0,1,0,
1685,0,0,15,0,0,15,2627,0,0,0,0,0,1,0,
1700,0,0,15,0,0,13,2635,0,0,12,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
1763,0,0,15,0,0,15,2660,0,0,0,0,0,1,0,
1778,0,0,16,0,0,17,2794,0,0,1,1,0,1,0,1,97,0,0,
1797,0,0,16,0,0,45,2800,0,0,0,0,0,1,0,
1812,0,0,16,0,0,15,2817,0,0,0,0,0,1,0,
1827,0,0,16,0,0,13,2825,0,0,8,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,
1874,0,0,16,0,0,15,2846,0,0,0,0,0,1,0,
1889,0,0,17,0,0,17,2968,0,0,1,1,0,1,0,1,97,0,0,
1908,0,0,17,0,0,45,2974,0,0,0,0,0,1,0,
1923,0,0,17,0,0,15,2991,0,0,0,0,0,1,0,
1938,0,0,17,0,0,13,2999,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
1969,0,0,17,0,0,15,3016,0,0,0,0,0,1,0,
1984,0,0,18,0,0,17,3135,0,0,1,1,0,1,0,1,97,0,0,
2003,0,0,18,0,0,45,3141,0,0,0,0,0,1,0,
2018,0,0,18,0,0,15,3158,0,0,0,0,0,1,0,
2033,0,0,18,0,0,13,3166,0,0,10,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
2088,0,0,18,0,0,15,3189,0,0,0,0,0,1,0,
2103,0,0,19,0,0,17,3313,0,0,1,1,0,1,0,1,97,0,0,
2122,0,0,19,0,0,45,3319,0,0,0,0,0,1,0,
2137,0,0,19,0,0,15,3336,0,0,0,0,0,1,0,
2152,0,0,19,0,0,13,3344,0,0,10,0,0,1,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2207,0,0,19,0,0,15,3367,0,0,0,0,0,1,0,
2222,0,0,20,0,0,17,3499,0,0,1,1,0,1,0,1,97,0,0,
2241,0,0,20,0,0,45,3505,0,0,0,0,0,1,0,
2256,0,0,20,0,0,15,3522,0,0,0,0,0,1,0,
2271,0,0,20,0,0,13,3530,0,0,12,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2334,0,0,20,0,0,15,3555,0,0,0,0,0,1,0,
2349,0,0,21,0,0,17,3683,0,0,1,1,0,1,0,1,97,0,0,
2368,0,0,21,0,0,45,3689,0,0,0,0,0,1,0,
2383,0,0,21,0,0,15,3706,0,0,0,0,0,1,0,
2398,0,0,21,0,0,13,3714,0,0,2,0,0,1,0,2,3,0,0,2,3,0,0,
2421,0,0,21,0,0,15,3729,0,0,0,0,0,1,0,
2436,0,0,22,0,0,17,3839,0,0,1,1,0,1,0,1,97,0,0,
2455,0,0,22,0,0,45,3845,0,0,0,0,0,1,0,
2470,0,0,22,0,0,15,3862,0,0,0,0,0,1,0,
2485,0,0,22,0,0,13,3870,0,0,8,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2532,0,0,22,0,0,15,3891,0,0,0,0,0,1,0,
2547,0,0,23,0,0,17,4022,0,0,1,1,0,1,0,1,97,0,0,
2566,0,0,23,0,0,45,4028,0,0,0,0,0,1,0,
2581,0,0,23,0,0,15,4045,0,0,0,0,0,1,0,
2596,0,0,23,0,0,13,4053,0,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2663,0,0,23,0,0,15,4079,0,0,0,0,0,1,0,
2678,0,0,24,0,0,17,4226,0,0,1,1,0,1,0,1,97,0,0,
2697,0,0,24,0,0,45,4232,0,0,0,0,0,1,0,
2712,0,0,24,0,0,15,4249,0,0,0,0,0,1,0,
2727,0,0,24,0,0,13,4257,0,0,17,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2810,0,0,24,0,0,15,4287,0,0,0,0,0,1,0,
2825,0,0,25,0,0,17,4447,0,0,1,1,0,1,0,1,97,0,0,
2844,0,0,25,0,0,45,4453,0,0,0,0,0,1,0,
2859,0,0,25,0,0,15,4470,0,0,0,0,0,1,0,
2874,0,0,25,0,0,13,4478,0,0,20,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2969,0,0,25,0,0,15,4511,0,0,0,0,0,1,0,
2984,0,0,26,0,0,17,4679,0,0,1,1,0,1,0,1,97,0,0,
3003,0,0,26,0,0,45,4685,0,0,0,0,0,1,0,
3018,0,0,26,0,0,15,4702,0,0,0,0,0,1,0,
3033,0,0,26,0,0,13,4710,0,0,21,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
3132,0,0,26,0,0,15,4744,0,0,0,0,0,1,0,
3147,0,0,27,0,0,17,4907,0,0,1,1,0,1,0,1,97,0,0,
3166,0,0,27,0,0,45,4913,0,0,0,0,0,1,0,
3181,0,0,27,0,0,15,4930,0,0,0,0,0,1,0,
3196,0,0,27,0,0,13,4938,0,0,11,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3255,0,0,27,0,0,15,4962,0,0,0,0,0,1,0,
3270,0,0,28,0,0,17,5106,0,0,1,1,0,1,0,1,97,0,0,
3289,0,0,28,0,0,45,5112,0,0,0,0,0,1,0,
3304,0,0,28,0,0,15,5129,0,0,0,0,0,1,0,
3319,0,0,28,0,0,13,5137,0,0,10,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3374,0,0,28,0,0,15,5160,0,0,0,0,0,1,0,
3389,0,0,29,0,0,17,5298,0,0,1,1,0,1,0,1,97,0,0,
3408,0,0,29,0,0,45,5304,0,0,0,0,0,1,0,
3423,0,0,29,0,0,15,5321,0,0,0,0,0,1,0,
3438,0,0,29,0,0,13,5329,0,0,9,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3489,0,0,29,0,0,15,5351,0,0,0,0,0,1,0,
3504,0,0,30,0,0,17,5477,0,0,1,1,0,1,0,1,97,0,0,
3523,0,0,30,0,0,45,5483,0,0,0,0,0,1,0,
3538,0,0,30,0,0,15,5500,0,0,0,0,0,1,0,
3553,0,0,30,0,0,13,5508,0,0,6,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,
3592,0,0,30,0,0,15,5527,0,0,0,0,0,1,0,
3607,0,0,31,0,0,17,5644,0,0,1,1,0,1,0,1,97,0,0,
3626,0,0,31,0,0,45,5650,0,0,0,0,0,1,0,
3641,0,0,31,0,0,15,5667,0,0,0,0,0,1,0,
3656,0,0,31,0,0,13,5675,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
3687,0,0,31,0,0,15,5692,0,0,0,0,0,1,0,
3702,0,0,32,0,0,17,5806,0,0,1,1,0,1,0,1,97,0,0,
3721,0,0,32,0,0,45,5812,0,0,0,0,0,1,0,
3736,0,0,32,0,0,15,5829,0,0,0,0,0,1,0,
3751,0,0,32,0,0,13,5837,0,0,5,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,
3786,0,0,32,0,0,15,5855,0,0,0,0,0,1,0,
3801,0,0,33,0,0,17,5980,0,0,1,1,0,1,0,1,97,0,0,
3820,0,0,33,0,0,45,5986,0,0,0,0,0,1,0,
3835,0,0,33,0,0,15,6003,0,0,0,0,0,1,0,
3850,0,0,33,0,0,13,6011,0,0,14,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3921,0,0,33,0,0,15,6038,0,0,0,0,0,1,0,
3936,0,0,34,0,0,17,6173,0,0,1,1,0,1,0,1,97,0,0,
3955,0,0,34,0,0,45,6179,0,0,0,0,0,1,0,
3970,0,0,34,0,0,15,6196,0,0,0,0,0,1,0,
3985,0,0,34,0,0,13,6204,0,0,9,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
4036,0,0,34,0,0,15,6226,0,0,0,0,0,1,0,
4051,0,0,35,0,0,17,6349,0,0,1,1,0,1,0,1,97,0,0,
4070,0,0,35,0,0,45,6355,0,0,0,0,0,1,0,
4085,0,0,35,0,0,15,6372,0,0,0,0,0,1,0,
4100,0,0,35,0,0,13,6380,0,0,4,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
4131,0,0,35,0,0,15,6397,0,0,0,0,0,1,0,
4146,0,0,36,0,0,17,6524,0,0,1,1,0,1,0,1,97,0,0,
4165,0,0,36,0,0,45,6530,0,0,0,0,0,1,0,
4180,0,0,36,0,0,15,6547,0,0,0,0,0,1,0,
4195,0,0,36,0,0,13,6555,0,0,17,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,
4278,0,0,36,0,0,15,6585,0,0,0,0,0,1,0,
4293,0,0,37,0,0,17,6732,0,0,1,1,0,1,0,1,97,0,0,
4312,0,0,37,0,0,45,6738,0,0,0,0,0,1,0,
4327,0,0,37,0,0,15,6755,0,0,0,0,0,1,0,
4342,0,0,37,0,0,13,6763,0,0,11,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
4401,0,0,37,0,0,15,6787,0,0,0,0,0,1,0,
4416,0,0,38,0,0,17,6914,0,0,1,1,0,1,0,1,97,0,0,
4435,0,0,38,0,0,45,6920,0,0,0,0,0,1,0,
4450,0,0,38,0,0,15,6937,0,0,0,0,0,1,0,
4465,0,0,38,0,0,13,6945,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
4496,0,0,38,0,0,15,6962,0,0,0,0,0,1,0,
4511,0,0,39,0,0,17,7074,0,0,1,1,0,1,0,1,97,0,0,
4530,0,0,39,0,0,45,7080,0,0,0,0,0,1,0,
4545,0,0,39,0,0,15,7097,0,0,0,0,0,1,0,
4560,0,0,39,0,0,13,7105,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
4591,0,0,39,0,0,15,7122,0,0,0,0,0,1,0,
4606,0,0,40,0,0,17,7236,0,0,1,1,0,1,0,1,97,0,0,
4625,0,0,40,0,0,45,7242,0,0,0,0,0,1,0,
4640,0,0,40,0,0,15,7259,0,0,0,0,0,1,0,
4655,0,0,40,0,0,13,7267,0,0,6,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,
4694,0,0,40,0,0,15,7286,0,0,0,0,0,1,0,
4709,0,0,41,0,0,17,7406,0,0,1,1,0,1,0,1,97,0,0,
4728,0,0,41,0,0,45,7412,0,0,0,0,0,1,0,
4743,0,0,41,0,0,15,7429,0,0,0,0,0,1,0,
4758,0,0,41,0,0,13,7437,0,0,8,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,
4805,0,0,41,0,0,15,7458,0,0,0,0,0,1,0,
4820,0,0,42,0,0,17,7580,0,0,1,1,0,1,0,1,97,0,0,
4839,0,0,42,0,0,45,7586,0,0,0,0,0,1,0,
4854,0,0,42,0,0,15,7603,0,0,0,0,0,1,0,
4869,0,0,42,0,0,13,7611,0,0,9,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
4920,0,0,42,0,0,15,7633,0,0,0,0,0,1,0,
4935,0,0,43,0,0,17,7765,0,0,1,1,0,1,0,1,97,0,0,
4954,0,0,43,0,0,45,7771,0,0,0,0,0,1,0,
4969,0,0,43,0,0,15,7788,0,0,0,0,0,1,0,
4984,0,0,43,0,0,13,7796,0,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5051,0,0,43,0,0,15,7822,0,0,0,0,0,1,0,
5066,0,0,44,0,0,17,7966,0,0,1,1,0,1,0,1,97,0,0,
5085,0,0,44,0,0,45,7972,0,0,0,0,0,1,0,
5100,0,0,44,0,0,15,7989,0,0,0,0,0,1,0,
5115,0,0,44,0,0,13,7997,0,0,19,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5206,0,0,44,0,0,15,8030,0,0,0,0,0,1,0,
5221,0,0,45,0,0,17,8184,0,0,1,1,0,1,0,1,97,0,0,
5240,0,0,45,0,0,45,8190,0,0,0,0,0,1,0,
5255,0,0,45,0,0,15,15,1,0,0,0,0,1,0,
5270,0,0,45,0,0,13,23,1,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5337,0,0,45,0,0,15,49,1,0,0,0,0,1,0,
5352,0,0,46,0,0,17,187,1,0,1,1,0,1,0,1,97,0,0,
5371,0,0,46,0,0,45,193,1,0,0,0,0,1,0,
5386,0,0,46,0,0,15,210,1,0,0,0,0,1,0,
5401,0,0,46,0,0,13,218,1,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5468,0,0,46,0,0,15,244,1,0,0,0,0,1,0,
5483,0,0,47,0,0,17,390,1,0,1,1,0,1,0,1,97,0,0,
5502,0,0,47,0,0,45,396,1,0,0,0,0,1,0,
5517,0,0,47,0,0,15,413,1,0,0,0,0,1,0,
5532,0,0,47,0,0,13,421,1,0,19,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5623,0,0,47,0,0,15,454,1,0,0,0,0,1,0,
5638,0,0,48,0,0,17,613,1,0,1,1,0,1,0,1,97,0,0,
5657,0,0,48,0,0,45,619,1,0,0,0,0,1,0,
5672,0,0,48,0,0,15,636,1,0,0,0,0,1,0,
5687,0,0,48,0,0,13,644,1,0,18,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5774,0,0,48,0,0,15,675,1,0,0,0,0,1,0,
5789,0,0,49,0,0,17,832,1,0,1,1,0,1,0,1,97,0,0,
5808,0,0,49,0,0,45,838,1,0,0,0,0,1,0,
5823,0,0,49,0,0,15,855,1,0,0,0,0,1,0,
5838,0,0,49,0,0,13,863,1,0,18,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5925,0,0,49,0,0,15,894,1,0,0,0,0,1,0,
5940,0,0,50,0,0,17,1047,1,0,1,1,0,1,0,1,97,0,0,
5959,0,0,50,0,0,45,1053,1,0,0,0,0,1,0,
5974,0,0,50,0,0,15,1070,1,0,0,0,0,1,0,
5989,0,0,50,0,0,13,1078,1,0,16,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
6068,0,0,50,0,0,15,1107,1,0,0,0,0,1,0,
6083,0,0,51,0,0,17,1255,1,0,1,1,0,1,0,1,97,0,0,
6102,0,0,51,0,0,45,1261,1,0,0,0,0,1,0,
6117,0,0,51,0,0,15,1278,1,0,0,0,0,1,0,
6132,0,0,51,0,0,13,1286,1,0,16,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,
6211,0,0,51,0,0,15,1315,1,0,0,0,0,1,0,
6226,0,0,52,0,0,17,1464,1,0,1,1,0,1,0,1,97,0,0,
6245,0,0,52,0,0,45,1470,1,0,0,0,0,1,0,
6260,0,0,52,0,0,15,1487,1,0,0,0,0,1,0,
6275,0,0,52,0,0,13,1495,1,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
6342,0,0,52,0,0,15,1521,1,0,0,0,0,1,0,
6357,0,0,53,0,0,17,1659,1,0,1,1,0,1,0,1,97,0,0,
6376,0,0,53,0,0,45,1665,1,0,0,0,0,1,0,
6391,0,0,53,0,0,15,1682,1,0,0,0,0,1,0,
6406,0,0,53,0,0,13,1690,1,0,12,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
6469,0,0,53,0,0,15,1715,1,0,0,0,0,1,0,
6484,0,0,54,0,0,17,1855,1,0,1,1,0,1,0,1,97,0,0,
6503,0,0,54,0,0,45,1861,1,0,0,0,0,1,0,
6518,0,0,54,0,0,15,1878,1,0,0,0,0,1,0,
6533,0,0,54,0,0,13,1886,1,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
6600,0,0,54,0,0,15,1912,1,0,0,0,0,1,0,
6615,0,0,55,0,0,17,2053,1,0,1,1,0,1,0,1,97,0,0,
6634,0,0,55,0,0,45,2059,1,0,0,0,0,1,0,
6649,0,0,55,0,0,15,2076,1,0,0,0,0,1,0,
6664,0,0,55,0,0,13,2084,1,0,13,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
6731,0,0,55,0,0,15,2110,1,0,0,0,0,1,0,
6746,0,0,56,0,0,17,2250,1,0,1,1,0,1,0,1,97,0,0,
6765,0,0,56,0,0,45,2256,1,0,0,0,0,1,0,
6780,0,0,56,0,0,15,2273,1,0,0,0,0,1,0,
6795,0,0,56,0,0,13,2281,1,0,7,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,
6838,0,0,56,0,0,15,2301,1,0,0,0,0,1,0,
};



#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <list.h>
#include <wwdir.h>

#define PARAM_COND "WHERE nvl(STATE,'A0A') != 'A0X' AND nvl(STATE,'A0A') != 'A0C'"

#include "gen_supp.h"


/*批量数据动态从ACROSS_CELL_CODE中用结构缓冲方式取数据*/
int EGetAcrossCellCodeToStruct(struct AcrossCellCodeStruct *p,
	struct AcrossCellCodeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				ACROSS_CODE_ID,\n\
				SEQ_NBR,\n\
				MSC,\n\
				LAC,\n\
				CELL_ID,\n\
				ACROSS_AREA_CODE,\n\
				REMARK,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ACROSS_CELL_CODESCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE ACROSS_CELL_CODESCR ACROSS_CELL_CODECR");

		/* EXEC SQL DECLARE ACROSS_CELL_CODECR CURSOR FOR ACROSS_CELL_CODESCR; */ 

		CheckSqlError("Declare ACROSS_CELL_CODECR");

		/* EXEC SQL OPEN ACROSS_CELL_CODECR; */ 

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


		CheckSqlError("Open ACROSS_CELL_CODECR;");


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

		/* EXEC SQL CLOSE ACROSS_CELL_CODECR; */ 

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
		/* EXEC SQL FETCH ACROSS_CELL_CODECR INTO
			:pSource->aiAcrossCodeID,
			:pSource->aiSeqNbr,
			:pSource->asMsc,
			:pSource->asLac,
			:pSource->asCellID,
			:pSource->asAcrossAreaCode,
			:pSource->asRemark,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
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
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiAcrossCodeID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asLac);
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )5;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCellID);
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )5;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asAcrossAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )10;
  sqlstm.sqhsts[5] = (         int  )10;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[6] = (unsigned long )61;
  sqlstm.sqhsts[6] = (         int  )61;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
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


		CheckSqlError("Fetch ACROSS_CELL_CODECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ACROSS_CELL_CODECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )117;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ACROSS_CELL_CODE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iAcrossCodeID=		pSource->aiAcrossCodeID[iCurPos];
		p->iSeqNbr=			pSource->aiSeqNbr[iCurPos];

		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sLac,			pSource->asLac[iCurPos]);
		strcpy(p->sCellID,		pSource->asCellID[iCurPos]);
		strcpy(p->sAcrossAreaCode,	pSource->asAcrossAreaCode[iCurPos]);
		strcpy(p->sRemark,		pSource->asRemark[iCurPos]);

		strcpy(p->sEffDate,		pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,		pSource->asExpDate[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sStateDate,		pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,		pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sMsc);
		AllTrim(p->sLac);
		AllTrim(p->sCellID);
		AllTrim(p->sAcrossAreaCode);
		AllTrim(p->sState);
		AllTrim(p->sRemark);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void DestroyAcrossCellCode(struct AcrossCellCodeStruct *ptHead)
{
	struct AcrossCellCodeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitAcrossCellCode(struct AcrossCellCodeStruct **pptHead)
{
	int iCnt=0;
	static struct AcrossCellCodeStruct *pTemp,*ptHead=NULL;
	struct AcrossCellCodeStruct Temp;
	struct AcrossCellCodeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyAcrossCellCode(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct AcrossCellCodeStructIn));
	sprintf(TempIn.sTableName,"ACROSS_CELL_CODE");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetAcrossCellCodeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct AcrossCellCodeStruct*)
			malloc(sizeof(struct AcrossCellCodeStruct)))==NULL){

			DestroyAcrossCellCode(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct AcrossCellCodeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表ACROSS_CELL_CODE记录数%d",iCnt);
	}
	WriteProcMsg("加载表ACROSS_CELL_CODE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从AREA_CODE_DESC中用结构缓冲方式取数据*/
int EGetAreaCodeDescToStruct(struct AreaCodeDescStruct *p,
	struct AreaCodeDescStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				AREA_CODE,\n\
				nvl(CAPITAL_AREA_CODE,'-1'),\n\
				nvl(PROVINCE_NAME,'-1'),\n\
				nvl(REMARK,'-1'),\n\
				nvl(CITY_CODE,'-1'),\n\
				nvl(COUNTRY_CODE,'-1'),\n\
				nvl(TYPE,'3'),\n\
				nvl(IP_TYPE,'0'),\n\
				nvl(TOLL_TYPE1,'0'),\n\
				nvl(TOLL_TYPE2,'0')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE AREA_CODE_DESCSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )132;
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


		CheckSqlError(" PREPARE AREA_CODE_DESCSCR AREA_CODE_DESCCR");

		/* EXEC SQL DECLARE AREA_CODE_DESCCR CURSOR FOR AREA_CODE_DESCSCR; */ 

		CheckSqlError("Declare AREA_CODE_DESCCR");

		/* EXEC SQL OPEN AREA_CODE_DESCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )151;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open AREA_CODE_DESCCR;");


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

		/* EXEC SQL CLOSE AREA_CODE_DESCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )166;
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
		/* EXEC SQL FETCH AREA_CODE_DESCCR INTO
			:pSource->asAreaCode,
			:pSource->asCapitalAreaCode,
			:pSource->asProvinceName,
			:pSource->asRemark,
			:pSource->asCityCode,
			:pSource->asCountryCode,
			:pSource->asType,
			:pSource->asIpType,
			:pSource->asTollType1,
			:pSource->asTollType2; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )181;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCapitalAreaCode);
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )10;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asProvinceName);
  sqlstm.sqhstl[2] = (unsigned long )41;
  sqlstm.sqhsts[2] = (         int  )41;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[3] = (unsigned long )61;
  sqlstm.sqhsts[3] = (         int  )61;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCityCode);
  sqlstm.sqhstl[4] = (unsigned long )4;
  sqlstm.sqhsts[4] = (         int  )4;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCountryCode);
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )4;
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
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asIpType);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asTollType1);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asTollType2);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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


		CheckSqlError("Fetch AREA_CODE_DESCCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE AREA_CODE_DESCCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )236;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=AREA_CODE_DESC_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAreaCode,		pSource->asAreaCode[iCurPos]);
		strcpy(p->sCapitalAreaCode,	pSource->asCapitalAreaCode[iCurPos]);
		strcpy(p->sProvinceName,	pSource->asProvinceName[iCurPos]);
		strcpy(p->sRemark,		pSource->asRemark[iCurPos]);
		strcpy(p->sCityCode,		pSource->asCityCode[iCurPos]);
		strcpy(p->sCountryCode,		pSource->asCountryCode[iCurPos]);
		strcpy(p->sType,		pSource->asType[iCurPos]);

		strcpy(p->sIpType,		pSource->asIpType[iCurPos]);
		strcpy(p->sTollType1,		pSource->asTollType1[iCurPos]);
		strcpy(p->sTollType2,		pSource->asTollType2[iCurPos]);


		AllTrim(p->sAreaCode);
		AllTrim(p->sCapitalAreaCode);
		AllTrim(p->sProvinceName);
		AllTrim(p->sRemark);
		AllTrim(p->sCityCode);
		AllTrim(p->sCountryCode);
		AllTrim(p->sType);

		AllTrim(p->sIpType);
		AllTrim(p->sTollType1);
		AllTrim(p->sTollType2);


	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表AREA_CODE_DESC的链表释放函数**/
void DestroyAreaCodeDesc(struct AreaCodeDescStruct *ptHead)
{
	struct AreaCodeDescStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitAreaCodeDesc(struct AreaCodeDescStruct **pptHead)
{
	int iCnt=0;
	static struct AreaCodeDescStruct *pTemp,*ptHead=NULL;
	struct AreaCodeDescStruct Temp;
	struct AreaCodeDescStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyAreaCodeDesc(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct AreaCodeDescStructIn));
	sprintf(TempIn.sTableName,"AREA_CODE_DESC");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetAreaCodeDescToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct AreaCodeDescStruct*)
			malloc(sizeof(struct AreaCodeDescStruct)))==NULL){

			DestroyAreaCodeDesc(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct AreaCodeDescStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表AREA_CODE_DESC记录数%d",iCnt);
	}

	WriteProcMsg("加载表AREA_CODE_DESC完毕总记录数%d",iCnt);

	return iCnt;
}


/*批量数据动态从T130_AREA_CODE中用结构缓冲方式取数据*/
int EGetT130AreaCodeToStruct(struct T130AreaCodeStruct *p,
	struct T130AreaCodeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				HEAD_ID,\n\
				SEQ_NBR,\n\
				HEAD,\n\
				nvl(LEN,-1),\n\
				nvl(AREA_CODE,'-1'),\n\
				nvl(HEAD_TYPE,'-1'),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE T130_AREA_CODESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )251;
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


		CheckSqlError(" PREPARE T130_AREA_CODESCR T130_AREA_CODECR");

		/* EXEC SQL DECLARE T130_AREA_CODECR CURSOR FOR T130_AREA_CODESCR; */ 

		CheckSqlError("Declare T130_AREA_CODECR");

		/* EXEC SQL OPEN T130_AREA_CODECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )270;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open T130_AREA_CODECR;");


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

		/* EXEC SQL CLOSE T130_AREA_CODECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )285;
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
		/* EXEC SQL FETCH T130_AREA_CODECR INTO
			:pSource->aiHeadID,
			:pSource->aiSeqNbr,
			:pSource->asHead,
			:pSource->aiLen,
			:pSource->asAreaCode,
			:pSource->asHeadType,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )300;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiHeadID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asHead);
  sqlstm.sqhstl[2] = (unsigned long )12;
  sqlstm.sqhsts[2] = (         int  )12;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiLen);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asHeadType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )15;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[8] = (unsigned long )4;
  sqlstm.sqhsts[8] = (         int  )4;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asCreatedDate);
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


		CheckSqlError("Fetch T130_AREA_CODECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE T130_AREA_CODECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )359;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=T130_AREA_CODE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iHeadID=		pSource->aiHeadID[iCurPos];
		p->iSeqNbr=			pSource->aiSeqNbr[iCurPos];

		strcpy(p->sHead,	pSource->asHead[iCurPos]);

		p->iLen=		pSource->aiLen[iCurPos];

		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);
		strcpy(p->sHeadType,	pSource->asHeadType[iCurPos]);

		strcpy(p->sEffDate,		pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,		pSource->asExpDate[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sStateDate,		pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,		pSource->asCreatedDate[iCurPos]);


		AllTrim(p->sHead);
		AllTrim(p->sAreaCode);
		AllTrim(p->sHeadType);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表T130_AREA_CODE的链表释放函数**/
void DestroyT130AreaCode(struct T130AreaCodeStruct *ptHead)
{
	struct T130AreaCodeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitT130AreaCode(struct T130AreaCodeStruct **pptHead)
{
	int iCnt=0;
	static struct T130AreaCodeStruct *pTemp,*ptHead=NULL;
	struct T130AreaCodeStruct Temp;
	struct T130AreaCodeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyT130AreaCode(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct T130AreaCodeStructIn));
	sprintf(TempIn.sTableName,"T130_AREA_CODE");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetT130AreaCodeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct T130AreaCodeStruct*)
			malloc(sizeof(struct T130AreaCodeStruct)))==NULL){

			DestroyT130AreaCode(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct T130AreaCodeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表T130_AREA_CODE记录数%d",iCnt);
	}

	WriteProcMsg("加载表T130_AREA_CODE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TRUNK中用结构缓冲方式取数据*/
int EGetTrunkToStruct(struct TrunkStruct *p,
	struct TrunkStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TRUNK_ID,\n\
				SEQ_NBR,\n\
				TRUNK_TYPE_ID,\n\
				SETT_CARRIER_ID,\n\
				nvl(OPP_AREA_CODE,'-1'),\n\
				DIRECTION,\n\
				MSC,\n\
				TRUNK,\n\
				TRUNK_NAME,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TRUNKSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )374;
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


		CheckSqlError(" PREPARE TRUNKSCR TRUNKCR");

		/* EXEC SQL DECLARE TRUNKCR CURSOR FOR TRUNKSCR; */ 

		CheckSqlError("Declare TRUNKCR");

		/* EXEC SQL OPEN TRUNKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )393;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TRUNKCR;");


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

		/* EXEC SQL CLOSE TRUNKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )408;
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
		/* EXEC SQL FETCH TRUNKCR INTO
			:pSource->aiTrunkID,
			:pSource->aiSeqNbr,
			:pSource->aiTrunkTypeID,
			:pSource->aiSettCarrierID,
			:pSource->asOppAreaCode,
			:pSource->asDirection,
			:pSource->asMsc,
			:pSource->asTrunk,
			:pSource->asTrunkName,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )423;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTrunkID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiTrunkTypeID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiSettCarrierID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOppAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asDirection);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[6] = (unsigned long )11;
  sqlstm.sqhsts[6] = (         int  )11;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asTrunk);
  sqlstm.sqhstl[7] = (unsigned long )8;
  sqlstm.sqhsts[7] = (         int  )8;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asTrunkName);
  sqlstm.sqhstl[8] = (unsigned long )61;
  sqlstm.sqhsts[8] = (         int  )61;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[11] = (unsigned long )4;
  sqlstm.sqhsts[11] = (         int  )4;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )15;
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


		CheckSqlError("Fetch TRUNKCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TRUNKCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )494;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TRUNK_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTrunkID=		pSource->aiTrunkID[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iTrunkTypeID=	pSource->aiTrunkTypeID[iCurPos];
		p->iSettCarrierID=	pSource->aiSettCarrierID[iCurPos];

		strcpy(p->sOppAreaCode,	pSource->asOppAreaCode[iCurPos]);
		strcpy(p->sDirection,	pSource->asDirection[iCurPos]);
		strcpy(p->sMsc,		pSource->asMsc[iCurPos]);
		strcpy(p->sTrunk,	pSource->asTrunk[iCurPos]);
		strcpy(p->sTrunkName,	pSource->asTrunkName[iCurPos]);
		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sOppAreaCode);
		AllTrim(p->sDirection);
		AllTrim(p->sMsc);
		AllTrim(p->sTrunk);
		AllTrim(p->sTrunkName);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);
	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TRUNK的链表释放函数**/
void DestroyTrunk(struct TrunkStruct *ptHead)
{
	struct TrunkStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTrunk(struct TrunkStruct **pptHead)
{
	int iCnt=0;
	static struct TrunkStruct *pTemp,*ptHead=NULL;
	struct TrunkStruct Temp;
	struct TrunkStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTrunk(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TrunkStructIn));
	sprintf(TempIn.sTableName,"TRUNK");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTrunkToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TrunkStruct*)
			malloc(sizeof(struct TrunkStruct)))==NULL){

			DestroyTrunk(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TrunkStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TRUNK记录数%d",iCnt);
	}

	WriteProcMsg("加载表TRUNK完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从MSC中用结构缓冲方式取数据*/
int EGetMscToStruct(struct MscStruct *p,
	struct MscStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				MSC,\n\
				nvl(MSC_TYPE,'0'),\n\
				AREA_CODE,\n\
				REMARK\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE MSCSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )509;
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


		CheckSqlError(" PREPARE MSCSCR MSCCR");

		/* EXEC SQL DECLARE MSCCR CURSOR FOR MSCSCR; */ 

		CheckSqlError("Declare MSCCR");

		/* EXEC SQL OPEN MSCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )528;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open MSCCR;");


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

		/* EXEC SQL CLOSE MSCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )543;
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
		/* EXEC SQL FETCH MSCCR INTO
			:pSource->asMsc,
			:pSource->asMscType,
			:pSource->asAreaCode,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )558;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )11;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asMscType);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )7;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )10;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[3] = (unsigned long )61;
  sqlstm.sqhsts[3] = (         int  )61;
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


		CheckSqlError("Fetch MSCCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE MSCCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )589;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=MSC_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sMsc,		pSource->asMsc[iCurPos]);
		strcpy(p->sMscType,	pSource->asMscType[iCurPos]);
		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		AllTrim(p->sMsc);
		AllTrim(p->sMscType);
		AllTrim(p->sAreaCode);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表MSC的链表释放函数**/
void DestroyMsc(struct MscStruct *ptHead)
{
	struct MscStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitMsc(struct MscStruct **pptHead)
{
	int iCnt=0;
	static struct MscStruct *pTemp,*ptHead=NULL;
	struct MscStruct Temp;
	struct MscStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyMsc(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct MscStructIn));
	sprintf(TempIn.sTableName,"MSC");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetMscToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct MscStruct*)
			malloc(sizeof(struct MscStruct)))==NULL){

			DestroyMsc(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct MscStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表MSC记录数%d",iCnt);
	}

	WriteProcMsg("加载表MSC完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TELECOM_CARRIER中用结构缓冲方式取数据*/
int EGetTelecomCarrierToStruct(struct TelecomCarrierStruct *p,
	struct TelecomCarrierStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				HEAD_ID,\n\
				SEQ_NBR,\n\
				MSC,\n\
				IMSI_HEAD,\n\
				nvl(COUNTRY_AREA_CODE,'-1'),\n\
				nvl(COUNTRY_FLAG,'-1'),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TELECOM_CARRIERSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )604;
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


		CheckSqlError(" PREPARE TELECOM_CARRIERSCR TELECOM_CARRIERCR");

		/* EXEC SQL DECLARE TELECOM_CARRIERCR CURSOR FOR TELECOM_CARRIERSCR; */ 

		CheckSqlError("Declare TELECOM_CARRIERCR");

		/* EXEC SQL OPEN TELECOM_CARRIERCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )623;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TELECOM_CARRIERCR;");


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

		/* EXEC SQL CLOSE TELECOM_CARRIERCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )638;
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
		/* EXEC SQL FETCH TELECOM_CARRIERCR INTO
			:pSource->aiHeadID,
			:pSource->aiSeqNbr,
			:pSource->asMsc,
			:pSource->asImsiHead,
			:pSource->asCountryAreaCode,
			:pSource->asCountryFlag,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )653;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiHeadID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asImsiHead);
  sqlstm.sqhstl[3] = (unsigned long )12;
  sqlstm.sqhsts[3] = (         int  )12;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCountryAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCountryFlag);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )15;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[8] = (unsigned long )4;
  sqlstm.sqhsts[8] = (         int  )4;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asCreatedDate);
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


		CheckSqlError("Fetch TELECOM_CARRIERCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TELECOM_CARRIERCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )712;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TELECOM_CARRIER_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/

		p->iHeadID=			pSource->aiHeadID[iCurPos];
		p->iSeqNbr=			pSource->aiSeqNbr[iCurPos];

		strcpy(p->sMsc,			pSource->asMsc[iCurPos]);
		strcpy(p->sImsiHead,		pSource->asImsiHead[iCurPos]);
		strcpy(p->sCountryAreaCode,	pSource->asCountryAreaCode[iCurPos]);
		strcpy(p->sCountryFlag,		pSource->asCountryFlag[iCurPos]);
		strcpy(p->sEffDate,		pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,		pSource->asExpDate[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sStateDate,		pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,		pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sMsc);
		AllTrim(p->sImsiHead);
		AllTrim(p->sCountryAreaCode);
		AllTrim(p->sCountryFlag);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TELECOM_CARRIER的链表释放函数**/
void DestroyTelecomCarrier(struct TelecomCarrierStruct *ptHead)
{
	struct TelecomCarrierStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTelecomCarrier(struct TelecomCarrierStruct **pptHead)
{
	int iCnt=0;
	static struct TelecomCarrierStruct *pTemp,*ptHead=NULL;
	struct TelecomCarrierStruct Temp;
	struct TelecomCarrierStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTelecomCarrier(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TelecomCarrierStructIn));
	sprintf(TempIn.sTableName,"TELECOM_CARRIER");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTelecomCarrierToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TelecomCarrierStruct*)
			malloc(sizeof(struct TelecomCarrierStruct)))==NULL){

			DestroyTelecomCarrier(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TelecomCarrierStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TELECOM_CARRIER记录数%d",iCnt);
	}

	WriteProcMsg("加载表TELECOM_CARRIER完毕总记录数%d",iCnt);

	return iCnt;
}

int EGetTicketFieldToStruct(struct TicketFieldStruct *p,
	struct TicketFieldStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				FIELD_ID,\n\
				FIELD_TYPE,\n\
				GET_VALUE_FUN,\n\
				nvl(FORMAT_ID,0),\n\
				nvl(DATA_TYPE,'2'),\n\
				nvl(USE_TYPE,'0'),\n\
				REMARK\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_FIELDSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )727;
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


		CheckSqlError(" PREPARE TICKET_FIELDSCR TICKET_FIELDCR");

		/* EXEC SQL DECLARE TICKET_FIELDCR CURSOR FOR TICKET_FIELDSCR; */ 

		CheckSqlError("Declare TICKET_FIELDCR");

		/* EXEC SQL OPEN TICKET_FIELDCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )746;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_FIELDCR;");


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

		/* EXEC SQL CLOSE TICKET_FIELDCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )761;
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
		/* EXEC SQL FETCH TICKET_FIELDCR INTO
			:pSource->aiFieldID,
			:pSource->asFieldType,
			:pSource->asGetValueFun,
			:pSource->aiFormatID,
			:pSource->asDataType,
			:pSource->asUseType,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )776;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiFieldID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asFieldType);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asGetValueFun);
  sqlstm.sqhstl[2] = (unsigned long )61;
  sqlstm.sqhsts[2] = (         int  )61;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiFormatID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asDataType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asUseType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[6] = (unsigned long )41;
  sqlstm.sqhsts[6] = (         int  )41;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
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


		CheckSqlError("Fetch TICKET_FIELDCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_FIELDCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )819;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_FIELD_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iFieldID=		pSource->aiFieldID[iCurPos];

		strcpy(p->sFieldType,	pSource->asFieldType[iCurPos]);
		strcpy(p->sGetValueFun,	pSource->asGetValueFun[iCurPos]);
		p->iFormatID=		pSource->aiFormatID[iCurPos];
		strcpy(p->sDataType,	pSource->asDataType[iCurPos]);
		strcpy(p->sUseType,	pSource->asUseType[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		AllTrim(p->sFieldType);
		AllTrim(p->sGetValueFun);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TICKET_FIELD的链表释放函数**/
void DestroyTicketField(struct TicketFieldStruct *ptHead)
{
	struct TicketFieldStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketField(struct TicketFieldStruct **pptHead)
{
	int iCnt=0;
	static struct TicketFieldStruct *pTemp,*ptHead=NULL;
	struct TicketFieldStruct Temp;
	struct TicketFieldStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketField(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TicketFieldStructIn));
	sprintf(TempIn.sTableName,"TICKET_FIELD");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketFieldToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketFieldStruct*)
			malloc(sizeof(struct TicketFieldStruct)))==NULL){

			DestroyTicketField(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketFieldStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_FIELD记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_FIELD完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TICKET_FIELD_RULE中用结构缓冲方式取数据*/
int EGetTicketFieldRuleToStruct(struct TicketFieldRuleStruct *p,
	struct TicketFieldRuleStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				RULE_ID,\n\
				FIELD_ID,\n\
				PRIORITY,\n\
				ID,\n\
				USE_TYPE,\n\
				METHOD,\n\
				REMARK\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_FIELD_RULESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )834;
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


		CheckSqlError(" PREPARE TICKET_FIELD_RULESCR TICKET_FIELD_RULECR");

		/* EXEC SQL DECLARE TICKET_FIELD_RULECR CURSOR FOR TICKET_FIELD_RULESCR; */ 

		CheckSqlError("Declare TICKET_FIELD_RULECR");

		/* EXEC SQL OPEN TICKET_FIELD_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )853;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_FIELD_RULECR;");


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

		/* EXEC SQL CLOSE TICKET_FIELD_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )868;
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
		/* EXEC SQL FETCH TICKET_FIELD_RULECR INTO
			:pSource->aiRuleID,
			:pSource->aiFieldID,
			:pSource->aiPriority,
			:pSource->aiID,
			:pSource->asUseType,
			:pSource->asMethod,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )883;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiRuleID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiFieldID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiPriority);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asUseType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asMethod);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[6] = (unsigned long )41;
  sqlstm.sqhsts[6] = (         int  )41;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
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


		CheckSqlError("Fetch TICKET_FIELD_RULECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_FIELD_RULECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )926;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_FIELD_RULE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iRuleID=		pSource->aiRuleID[iCurPos];
		p->iFieldID=		pSource->aiFieldID[iCurPos];
		p->iPriority=		pSource->aiPriority[iCurPos];
		p->iID=			pSource->aiID[iCurPos];

		strcpy(p->sUseType,	pSource->asUseType[iCurPos]);
		strcpy(p->sMethod,	pSource->asMethod[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		AllTrim(p->sUseType);
		AllTrim(p->sMethod);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表TICKET_FIELD_RULE的链表释放函数**/
void DestroyTicketFieldRule(struct TicketFieldRuleStruct *ptHead)
{
	struct TicketFieldRuleStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketFieldRule(struct TicketFieldRuleStruct **pptHead)
{
	int iCnt=0;
	static struct TicketFieldRuleStruct *pTemp,*ptHead=NULL;
	struct TicketFieldRuleStruct Temp;
	struct TicketFieldRuleStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketFieldRule(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TicketFieldRuleStructIn));
	sprintf(TempIn.sTableName,"TICKET_FIELD_RULE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketFieldRuleToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketFieldRuleStruct*)
			malloc(sizeof(struct TicketFieldRuleStruct)))==NULL){

			DestroyTicketFieldRule(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketFieldRuleStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_FIELD_RULE记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_FIELD_RULE完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从TICKET_FIELD_VALUE中用结构缓冲方式取数据*/
int EGetTicketFieldValueToStruct(struct TicketFieldValueStruct *p,
	struct TicketFieldValueStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SEQ,\n\
				RULE_ID,\n\
				VALUE\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_FIELD_VALUESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )941;
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


		CheckSqlError(" PREPARE TICKET_FIELD_VALUESCR TICKET_FIELD_VALUECR");

		/* EXEC SQL DECLARE TICKET_FIELD_VALUECR CURSOR FOR TICKET_FIELD_VALUESCR; */ 

		CheckSqlError("Declare TICKET_FIELD_VALUECR");

		/* EXEC SQL OPEN TICKET_FIELD_VALUECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )960;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_FIELD_VALUECR;");


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

		/* EXEC SQL CLOSE TICKET_FIELD_VALUECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )975;
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
		/* EXEC SQL FETCH TICKET_FIELD_VALUECR INTO
			:pSource->aiSeq,
			:pSource->aiRuleID,
			:pSource->asValue; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )990;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiSeq);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiRuleID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asValue);
  sqlstm.sqhstl[2] = (unsigned long )41;
  sqlstm.sqhsts[2] = (         int  )41;
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


		CheckSqlError("Fetch TICKET_FIELD_VALUECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_FIELD_VALUECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1017;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_FIELD_VALUE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iSeq=		pSource->aiSeq[iCurPos];
		p->iRuleID=		pSource->aiRuleID[iCurPos];

		strcpy(p->sValue,	pSource->asValue[iCurPos]);

		AllTrim(p->sValue);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TICKET_FIELD_VALUE的链表释放函数**/
void DestroyTicketFieldValue(struct TicketFieldValueStruct *ptHead)
{
	struct TicketFieldValueStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketFieldValue(struct TicketFieldValueStruct **pptHead)
{
	int iCnt=0;
	static struct TicketFieldValueStruct *pTemp,*ptHead=NULL;
	struct TicketFieldValueStruct Temp;
	struct TicketFieldValueStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketFieldValue(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TicketFieldValueStructIn));
	sprintf(TempIn.sTableName,"TICKET_FIELD_VALUE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketFieldValueToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketFieldValueStruct*)
			malloc(sizeof(struct TicketFieldValueStruct)))==NULL){

			DestroyTicketFieldValue(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketFieldValueStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_FIELD_VALUE记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_FIELD_VALUE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从SPLIT_RULE中用结构缓冲方式取数据*/
int EGetSplitRuleToStruct(struct SplitRuleStruct *p,
	struct SplitRuleStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SPLIT_RULE_ID,\n\
				TEMPLATE_RULE_ID,\n\
				PRIORITY,\n\
				SPLIT_TYPE,\n\
				nvl(TICKET_TYPE_ID,0),\n\
				TARIFF_FLAG,\n\
				nvl(LAY,0),\n\
				nvl(LEAVE_FLAG,'1'),\n\
				nvl(PARENT_ID,-1),\n\
				REMARK\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SPLIT_RULESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1032;
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


		CheckSqlError(" PREPARE SPLIT_RULESCR SPLIT_RULECR");

		/* EXEC SQL DECLARE SPLIT_RULECR CURSOR FOR SPLIT_RULESCR; */ 

		CheckSqlError("Declare SPLIT_RULECR");

		/* EXEC SQL OPEN SPLIT_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1051;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SPLIT_RULECR;");


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

		/* EXEC SQL CLOSE SPLIT_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1066;
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
		/* EXEC SQL FETCH SPLIT_RULECR INTO
			:pSource->aiSplitRuleID,
			:pSource->aiTemplateRuleID,
			:pSource->aiPriority,
			:pSource->asSplitType,
			:pSource->aiTicketTypeID,
			:pSource->aiTariffFlag,
			:pSource->aiLay,
			:pSource->asLeaveFlag,
			:pSource->aiParentID,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1081;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiSplitRuleID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiTemplateRuleID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiPriority);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asSplitType);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
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
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiTariffFlag);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiLay);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asLeaveFlag);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiParentID);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[9] = (unsigned long )41;
  sqlstm.sqhsts[9] = (         int  )41;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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


		CheckSqlError("Fetch SPLIT_RULECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SPLIT_RULECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 14;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1136;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SPLIT_RULE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iSplitRuleID=	pSource->aiSplitRuleID[iCurPos];
		p->iTemplateRuleID=	pSource->aiTemplateRuleID[iCurPos];
		p->iPriority=		pSource->aiPriority[iCurPos];

		strcpy(p->sSplitType,	pSource->asSplitType[iCurPos]);

		p->iTicketTypeID=	pSource->aiTicketTypeID[iCurPos];
		p->iTariffFlag=		pSource->aiTariffFlag[iCurPos];

		p->iLay=		pSource->aiLay[iCurPos];
		strcpy(p->sLeaveFlag,	pSource->asLeaveFlag[iCurPos]);
		p->iParentID=		pSource->aiParentID[iCurPos];

		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		AllTrim(p->sSplitType);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表SPLIT_RULE的链表释放函数**/
void DestroySplitRule(struct SplitRuleStruct *ptHead)
{
	struct SplitRuleStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSplitRule(struct SplitRuleStruct **pptHead)
{
	int iCnt=0;
	static struct SplitRuleStruct *pTemp,*ptHead=NULL;
	struct SplitRuleStruct Temp;
	struct SplitRuleStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySplitRule(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SplitRuleStructIn));
	sprintf(TempIn.sTableName,"SPLIT_RULE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSplitRuleToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SplitRuleStruct*)
			malloc(sizeof(struct SplitRuleStruct)))==NULL){

			DestroySplitRule(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SplitRuleStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SPLIT_RULE记录数%d",iCnt);
	}

	WriteProcMsg("加载表SPLIT_RULE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TOLL_TARIFF中用结构缓冲方式取数据*/
int EGetTollTariffToStruct(struct TollTariffStruct *p,
	struct TollTariffStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TARIFF_ID,\n\
				nvl(SEQ_NBR,1),\n\
				nvl(TARIFF_REF,'000000'),\n\
				TOLL_TYPE,\n\
				TARIFF_TYPE,\n\
				nvl(FIELD_TYPE,'0'),\n\
				nvl(LATN_ID,0),\n\
				nvl(SEC_PER_CNT,-1),\n\
				RATE,\n\
				nvl(RATE_PRECISION,0),\n\
				nvl(CALC_PRECISION,0),\n\
				REMARK,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TOLL_TARIFFSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1151;
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


		CheckSqlError(" PREPARE TOLL_TARIFFSCR TOLL_TARIFFCR");

		/* EXEC SQL DECLARE TOLL_TARIFFCR CURSOR FOR TOLL_TARIFFSCR; */ 

		CheckSqlError("Declare TOLL_TARIFFCR");

		/* EXEC SQL OPEN TOLL_TARIFFCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1170;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TOLL_TARIFFCR;");


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

		/* EXEC SQL CLOSE TOLL_TARIFFCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1185;
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
		/* EXEC SQL FETCH TOLL_TARIFFCR INTO
			:pSource->aiTariffID,
			:pSource->aiSeqNbr,
			:pSource->asTariffRef,
			:pSource->asTollType,
			:pSource->asTariffType,
			:pSource->asFieldType,
			:pSource->aiLatnID,
			:pSource->aiSecPerCnt,
			:pSource->aiRate,
			:pSource->aiRatePrecision,
			:pSource->aiCalcPrecision,
			:pSource->asRemark,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1200;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTariffID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asTariffRef);
  sqlstm.sqhstl[2] = (unsigned long )21;
  sqlstm.sqhsts[2] = (         int  )21;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asTollType);
  sqlstm.sqhstl[3] = (unsigned long )3;
  sqlstm.sqhsts[3] = (         int  )3;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asTariffType);
  sqlstm.sqhstl[4] = (unsigned long )3;
  sqlstm.sqhsts[4] = (         int  )3;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFieldType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiLatnID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiSecPerCnt);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiRate);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiRatePrecision);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiCalcPrecision);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[11] = (unsigned long )61;
  sqlstm.sqhsts[11] = (         int  )61;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )15;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[14] = (unsigned long )4;
  sqlstm.sqhsts[14] = (         int  )4;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[15] = (unsigned long )15;
  sqlstm.sqhsts[15] = (         int  )15;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[16] = (unsigned long )15;
  sqlstm.sqhsts[16] = (         int  )15;
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


		CheckSqlError("Fetch TOLL_TARIFFCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TOLL_TARIFFCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1283;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TOLL_TARIFF_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTariffID=		pSource->aiTariffID[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];

		strcpy(p->sTariffRef,	pSource->asTariffRef[iCurPos]);

		strcpy(p->sTollType,	pSource->asTollType[iCurPos]);
		strcpy(p->sTariffType,	pSource->asTariffType[iCurPos]);
		strcpy(p->sFieldType,	pSource->asFieldType[iCurPos]);

		p->iLatnID=		pSource->aiLatnID[iCurPos];

		p->iSecPerCnt=		pSource->aiSecPerCnt[iCurPos];
		p->iRate=		pSource->aiRate[iCurPos];
		p->iRatePrecision=	pSource->aiRatePrecision[iCurPos];
		p->iCalcPrecision=	pSource->aiCalcPrecision[iCurPos];

		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		strcpy(p->sEffDate,		pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,		pSource->asExpDate[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sStateDate,		pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,		pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sTariffRef);
		AllTrim(p->sTollType);
		AllTrim(p->sTariffType);
		AllTrim(p->sRemark);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TOLL_TARIFF的链表释放函数**/
void DestroyTollTariff(struct TollTariffStruct *ptHead)
{
	struct TollTariffStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTollTariff(struct TollTariffStruct **pptHead)
{
	int iCnt=0;
	static struct TollTariffStruct *pTemp,*ptHead=NULL;
	struct TollTariffStruct Temp;
	struct TollTariffStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTollTariff(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TollTariffStructIn));
	sprintf(TempIn.sTableName,"TOLL_TARIFF");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTollTariffToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TollTariffStruct*)
			malloc(sizeof(struct TollTariffStruct)))==NULL){

			DestroyTollTariff(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TollTariffStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TOLL_TARIFF记录数%d",iCnt);
	}

	WriteProcMsg("加载表TOLL_TARIFF完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从EXPR_DEF中用结构缓冲方式取数据*/
int EGetExprDefToStruct(struct ExprDefStruct *p,
	struct ExprDefStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				EXPR_ID,\n\
				EXPR_TYPE,\n\
				STATE,\n\
				REMARK,\n\
				EXPR,\n\
				nvl(COMMENTS,'-1'),\n\
				nvl(LATN_ID,-1)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE EXPR_DEFSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1298;
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


		CheckSqlError(" PREPARE EXPR_DEFSCR EXPR_DEFCR");

		/* EXEC SQL DECLARE EXPR_DEFCR CURSOR FOR EXPR_DEFSCR; */ 

		CheckSqlError("Declare EXPR_DEFCR");

		/* EXEC SQL OPEN EXPR_DEFCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1317;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open EXPR_DEFCR;");


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

		/* EXEC SQL CLOSE EXPR_DEFCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1332;
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
		/* EXEC SQL FETCH EXPR_DEFCR INTO
			:pSource->aiExprID,
			:pSource->asExprType,
			:pSource->asState,
			:pSource->asRemark,
			:pSource->asExpr,
			:pSource->asComments,
			:pSource->aiLatnID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1347;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiExprID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asExprType);
  sqlstm.sqhstl[1] = (unsigned long )3;
  sqlstm.sqhsts[1] = (         int  )3;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )4;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[3] = (unsigned long )61;
  sqlstm.sqhsts[3] = (         int  )61;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asExpr);
  sqlstm.sqhstl[4] = (unsigned long )4001;
  sqlstm.sqhsts[4] = (         int  )4001;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asComments);
  sqlstm.sqhstl[5] = (unsigned long )101;
  sqlstm.sqhsts[5] = (         int  )101;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiLatnID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
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


		CheckSqlError("Fetch EXPR_DEFCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE EXPR_DEFCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1390;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=EXPR_DEF_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iExprID=		pSource->aiExprID[iCurPos];

		strcpy(p->sExprType,	pSource->asExprType[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);
		strcpy(p->sExpr,	pSource->asExpr[iCurPos]);
		strcpy(p->sComments,	pSource->asComments[iCurPos]);

		p->iLatnID=		pSource->aiLatnID[iCurPos];

		AllTrim(p->sExprType);
		AllTrim(p->sState);
		AllTrim(p->sRemark);
		AllTrim(p->sExpr);
		AllTrim(p->sComments);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表EXPR_DEF的链表释放函数**/
void DestroyExprDef(struct ExprDefStruct *ptHead)
{
	struct ExprDefStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitExprDef(struct ExprDefStruct **pptHead)
{
	int iCnt=0;
	static struct ExprDefStruct *pTemp,*ptHead=NULL;
	struct ExprDefStruct Temp;
	struct ExprDefStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyExprDef(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct ExprDefStructIn));
	sprintf(TempIn.sTableName,"EXPR_DEF");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetExprDefToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct ExprDefStruct*)
			malloc(sizeof(struct ExprDefStruct)))==NULL){

			DestroyExprDef(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct ExprDefStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表EXPR_DEF记录数%d",iCnt);
	}

	WriteProcMsg("加载表EXPR_DEF完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从EXPR_DISCT中用结构缓冲方式取数据*/
int EGetExprDisctToStruct(struct ExprDisctStruct *p,
	struct ExprDisctStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				EXPR_DISCT_ID,\n\
				EXPR_ID,\n\
				nvl(DISCT_RULE_ID,-1),\n\
				PRIORITY,\n\
				nvl(REMARK,'-1'),\n\
				nvl(PARAM,'-1')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE EXPR_DISCTSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1405;
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


		CheckSqlError(" PREPARE EXPR_DISCTSCR EXPR_DISCTCR");

		/* EXEC SQL DECLARE EXPR_DISCTCR CURSOR FOR EXPR_DISCTSCR; */ 

		CheckSqlError("Declare EXPR_DISCTCR");

		/* EXEC SQL OPEN EXPR_DISCTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1424;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open EXPR_DISCTCR;");


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

		/* EXEC SQL CLOSE EXPR_DISCTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1439;
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
		/* EXEC SQL FETCH EXPR_DISCTCR INTO
			:pSource->aiExprDisctID,
			:pSource->aiExprID,
			:pSource->aiDisctRuleID,
			:pSource->aiPriority,
			:pSource->asRemark,
			:pSource->asParam; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1454;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiExprDisctID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiExprID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiDisctRuleID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiPriority);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[4] = (unsigned long )101;
  sqlstm.sqhsts[4] = (         int  )101;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asParam);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )41;
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


		CheckSqlError("Fetch EXPR_DISCTCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE EXPR_DISCTCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1493;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=EXPR_DISCT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iExprDisctID=	pSource->aiExprDisctID[iCurPos];
		p->iExprID=		pSource->aiExprID[iCurPos];
		p->iDisctRuleID=	pSource->aiDisctRuleID[iCurPos];
		p->iPriority=		pSource->aiPriority[iCurPos];

		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);
		strcpy(p->sParam,	pSource->asParam[iCurPos]);

		AllTrim(p->sRemark);
		AllTrim(p->sParam);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表EXPR_DISCT的链表释放函数**/
void DestroyExprDisct(struct ExprDisctStruct *ptHead)
{
	struct ExprDisctStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitExprDisct(struct ExprDisctStruct **pptHead)
{
	int iCnt=0;
	static struct ExprDisctStruct *pTemp,*ptHead=NULL;
	struct ExprDisctStruct Temp;
	struct ExprDisctStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyExprDisct(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct ExprDisctStructIn));
	sprintf(TempIn.sTableName,"EXPR_DISCT");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetExprDisctToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct ExprDisctStruct*)
			malloc(sizeof(struct ExprDisctStruct)))==NULL){

			DestroyExprDisct(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct ExprDisctStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表EXPR_DISCT记录数%d",iCnt);
	}

	WriteProcMsg("加载表EXPR_DISCT完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从HEAD_CARR中用结构缓冲方式取数据*/
int EGetHeadCarrToStruct(struct HeadCarrStruct *p,
	struct HeadCarrStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				HEAD_ID,\n\
				SEQ_NBR,\n\
				HEAD,\n\
				nvl(AREA_CODE,'*'),\n\
				nvl(AREA_ID,-1),\n\
				nvl(SETT_AREA_ID,-1),\n\
				SETT_CARRIER_ID,\n\
				nvl(TYPE_ID,-1),\n\
				nvl(TYPE,'C'),\n\
				LEN,\n\
				REMARK,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE HEAD_CARRSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1508;
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


		CheckSqlError(" PREPARE HEAD_CARRSCR HEAD_CARRCR");

		/* EXEC SQL DECLARE HEAD_CARRCR CURSOR FOR HEAD_CARRSCR; */ 

		CheckSqlError("Declare HEAD_CARRCR");

		/* EXEC SQL OPEN HEAD_CARRCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1527;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open HEAD_CARRCR;");


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

		/* EXEC SQL CLOSE HEAD_CARRCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1542;
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
		/* EXEC SQL FETCH HEAD_CARRCR INTO
			:pSource->aiHeadID,
			:pSource->aiSeqNbr,
			:pSource->asHead,
			:pSource->asAreaCode,
			:pSource->aiAreaID,
			:pSource->aiSettAreaID,
			:pSource->aiSettCarrierID,
			:pSource->aiTypeID,
			:pSource->asType,
			:pSource->aiLen,
			:pSource->asRemark,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1557;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiHeadID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asHead);
  sqlstm.sqhstl[2] = (unsigned long )16;
  sqlstm.sqhsts[2] = (         int  )16;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiAreaID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiSettAreaID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiSettCarrierID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiTypeID);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiLen);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[10] = (unsigned long )61;
  sqlstm.sqhsts[10] = (         int  )61;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[13] = (unsigned long )4;
  sqlstm.sqhsts[13] = (         int  )4;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[15] = (unsigned long )15;
  sqlstm.sqhsts[15] = (         int  )15;
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


		CheckSqlError("Fetch HEAD_CARRCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE HEAD_CARRCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1636;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=HEAD_CARR_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iHeadID=		pSource->aiHeadID[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];

		strcpy(p->sHead,	pSource->asHead[iCurPos]);
		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);

		p->iAreaID=		pSource->aiAreaID[iCurPos];
		p->iSettAreaID=		pSource->aiSettAreaID[iCurPos];
		p->iSettCarrierID=	pSource->aiSettCarrierID[iCurPos];
		p->iTypeID=		pSource->aiTypeID[iCurPos];

		strcpy(p->sType,	pSource->asType[iCurPos]);

		p->iLen=		pSource->aiLen[iCurPos];

		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sHead);
		AllTrim(p->sAreaCode);
		AllTrim(p->sType);
		AllTrim(p->sRemark);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表HEAD_CARR的链表释放函数**/
void DestroyHeadCarr(struct HeadCarrStruct *ptHead)
{
	struct HeadCarrStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitHeadCarr(struct HeadCarrStruct **pptHead)
{
	int iCnt=0;
	static struct HeadCarrStruct *pTemp,*ptHead=NULL;
	struct HeadCarrStruct Temp;
	struct HeadCarrStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyHeadCarr(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct HeadCarrStructIn));
	sprintf(TempIn.sTableName,"HEAD_CARR");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetHeadCarrToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct HeadCarrStruct*)
			malloc(sizeof(struct HeadCarrStruct)))==NULL){

			DestroyHeadCarr(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct HeadCarrStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表HEAD_CARR记录数%d",iCnt);
	}

	WriteProcMsg("加载表HEAD_CARR完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TICKET_BASED_DISCT中用结构缓冲方式取数据*/
int EGetTicketBasedDisctToStruct(struct TicketBasedDisctStruct *p,
	struct TicketBasedDisctStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TICKET_BASED_DISCT_ID,\n\
				nvl(DISCT_RULE_ID,-1),\n\
				UNIT,\n\
				nvl(OFFSET1,-1),\n\
				nvl(DURATION1,-1),\n\
				OFFSET2,\n\
				DURATION2,\n\
				METHOD,\n\
				RATE,\n\
				PRIORITY,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_BASED_DISCTSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1651;
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


		CheckSqlError(" PREPARE TICKET_BASED_DISCTSCR TICKET_BASED_DISCTCR");

		/* EXEC SQL DECLARE TICKET_BASED_DISCTCR CURSOR FOR TICKET_BASED_DISCTSCR; */ 

		CheckSqlError("Declare TICKET_BASED_DISCTCR");

		/* EXEC SQL OPEN TICKET_BASED_DISCTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1670;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_BASED_DISCTCR;");


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

		/* EXEC SQL CLOSE TICKET_BASED_DISCTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1685;
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
		/* EXEC SQL FETCH TICKET_BASED_DISCTCR INTO
			:pSource->aiTicketBasedDisctID,
			:pSource->aiDisctRuleID,
			:pSource->asUnit,
			:pSource->aiOffset1,
			:pSource->aiDuration1,
			:pSource->asOffset2,
			:pSource->aiDuration2,
			:pSource->asMethod,
			:pSource->aiRate,
			:pSource->aiPriority,
			:pSource->asEffDate,
			:pSource->asExpDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1700;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTicketBasedDisctID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiDisctRuleID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asUnit);
  sqlstm.sqhstl[2] = (unsigned long )3;
  sqlstm.sqhsts[2] = (         int  )3;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiOffset1);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiDuration1);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asOffset2);
  sqlstm.sqhstl[5] = (unsigned long )7;
  sqlstm.sqhsts[5] = (         int  )7;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiDuration2);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asMethod);
  sqlstm.sqhstl[7] = (unsigned long )3;
  sqlstm.sqhsts[7] = (         int  )3;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiRate);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiPriority);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
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


		CheckSqlError("Fetch TICKET_BASED_DISCTCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_BASED_DISCTCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1763;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_BASED_DISCT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTicketBasedDisctID=	pSource->aiTicketBasedDisctID[iCurPos];
		p->iDisctRuleID=	pSource->aiDisctRuleID[iCurPos];

		strcpy(p->sUnit,	pSource->asUnit[iCurPos]);

		p->iOffset1=		pSource->aiOffset1[iCurPos];
		p->iDuration1=		pSource->aiDuration1[iCurPos];

		strcpy(p->sOffset2,	pSource->asOffset2[iCurPos]);

		p->iDuration2=		pSource->aiDuration2[iCurPos];

		strcpy(p->sMethod,	pSource->asMethod[iCurPos]);

		p->iRate=		pSource->aiRate[iCurPos];
		p->iPriority=		pSource->aiPriority[iCurPos];

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);

		AllTrim(p->sUnit);
		AllTrim(p->sOffset2);
		AllTrim(p->sMethod);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表TICKET_BASED_DISCT的链表释放函数**/
void DestroyTicketBasedDisct(struct TicketBasedDisctStruct *ptHead)
{
	struct TicketBasedDisctStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketBasedDisct(struct TicketBasedDisctStruct **pptHead)
{
	int iCnt=0;
	static struct TicketBasedDisctStruct *pTemp,*ptHead=NULL;
	struct TicketBasedDisctStruct Temp;
	struct TicketBasedDisctStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketBasedDisct(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TicketBasedDisctStructIn));
	sprintf(TempIn.sTableName,"TICKET_BASED_DISCT");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketBasedDisctToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketBasedDisctStruct*)
			malloc(sizeof(struct TicketBasedDisctStruct)))==NULL){

			DestroyTicketBasedDisct(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketBasedDisctStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_BASED_DISCT记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_BASED_DISCT完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TICKET_TYPE中用结构缓冲方式取数据*/
int EGetTicketTypeToStruct(struct TicketTypeStruct *p,
	struct TicketTypeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TICKET_TYPE_ID,\n\
				nvl(TARIFF_TYPE,'00'),\n\
				nvl(FEE_TYPE,'0000'),\n\
				SETT_CARRIER_ID,\n\
				nvl(SPLIT_TYPE,'-1'),\n\
				nvl(SERV_TYPE,'0000'),\n\
				nvl(FORMAT_ID,1000),\n\
				REMARK\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_TYPESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1778;
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


		CheckSqlError(" PREPARE TICKET_TYPESCR TICKET_TYPECR");

		/* EXEC SQL DECLARE TICKET_TYPECR CURSOR FOR TICKET_TYPESCR; */ 

		CheckSqlError("Declare TICKET_TYPECR");

		/* EXEC SQL OPEN TICKET_TYPECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1797;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_TYPECR;");


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

		/* EXEC SQL CLOSE TICKET_TYPECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1812;
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
		/* EXEC SQL FETCH TICKET_TYPECR INTO
			:pSource->aiTicketTypeID,
			:pSource->asTariffType,
			:pSource->asFeeType,
			:pSource->aiSettCarrierID,
			:pSource->asSplitType,
			:pSource->asServType,
			:pSource->aiFormatID,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1827;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asTariffType);
  sqlstm.sqhstl[1] = (unsigned long )3;
  sqlstm.sqhsts[1] = (         int  )3;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asFeeType);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiSettCarrierID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asSplitType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asServType);
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )5;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiFormatID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[7] = (unsigned long )81;
  sqlstm.sqhsts[7] = (         int  )81;
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


		CheckSqlError("Fetch TICKET_TYPECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_TYPECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1874;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_TYPE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTicketTypeID=	pSource->aiTicketTypeID[iCurPos];

		strcpy(p->sTariffType,	pSource->asTariffType[iCurPos]);
		strcpy(p->sFeeType,	pSource->asFeeType[iCurPos]);

		p->iSettCarrierID=	pSource->aiSettCarrierID[iCurPos];

		strcpy(p->sSplitType,	pSource->asSplitType[iCurPos]);
		strcpy(p->sServType,	pSource->asServType[iCurPos]);

		p->iFormatID=		pSource->aiFormatID[iCurPos];
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		AllTrim(p->sTariffType);
		AllTrim(p->sFeeType);
		AllTrim(p->sSplitType);
		AllTrim(p->sServType);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TICKET_TYPE的链表释放函数**/
void DestroyTicketType(struct TicketTypeStruct *ptHead)
{
	struct TicketTypeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketType(struct TicketTypeStruct **pptHead)
{
	int iCnt=0;
	static struct TicketTypeStruct *pTemp,*ptHead=NULL;
	struct TicketTypeStruct Temp;
	struct TicketTypeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketType(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TicketTypeStructIn));
	sprintf(TempIn.sTableName,"TICKET_TYPE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketTypeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketTypeStruct*)
			malloc(sizeof(struct TicketTypeStruct)))==NULL){

			DestroyTicketType(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketTypeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_TYPE记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_TYPE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TICKET_TYPE_TARIFF中用结构缓冲方式取数据*/
int EGetTicketTypeTariffToStruct(struct TicketTypeTariffStruct *p,
	struct TicketTypeTariffStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TICKET_TYPE_ID,\n\
				TARIFF_ID,\n\
				STATE,\n\
				ACCT_ITEM_TYPE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_TYPE_TARIFFSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1889;
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


		CheckSqlError(" PREPARE TICKET_TYPE_TARIFFSCR TICKET_TYPE_TARIFFCR");

		/* EXEC SQL DECLARE TICKET_TYPE_TARIFFCR CURSOR FOR TICKET_TYPE_TARIFFSCR; */ 

		CheckSqlError("Declare TICKET_TYPE_TARIFFCR");

		/* EXEC SQL OPEN TICKET_TYPE_TARIFFCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1908;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_TYPE_TARIFFCR;");


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

		/* EXEC SQL CLOSE TICKET_TYPE_TARIFFCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1923;
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
		/* EXEC SQL FETCH TICKET_TYPE_TARIFFCR INTO
			:pSource->aiTicketTypeID,
			:pSource->aiTariffID,
			:pSource->asState,
			:pSource->aiAcctItemTypeID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1938;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiTariffID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )4;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiAcctItemTypeID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch TICKET_TYPE_TARIFFCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_TYPE_TARIFFCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1969;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_TYPE_TARIFF_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTicketTypeID=	pSource->aiTicketTypeID[iCurPos];
		p->iTariffID=		pSource->aiTariffID[iCurPos];

		strcpy(p->sState,	pSource->asState[iCurPos]);

		p->iAcctItemTypeID=	pSource->aiAcctItemTypeID[iCurPos];

		AllTrim(p->sState);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表TICKET_TYPE_TARIFF的链表释放函数**/
void DestroyTicketTypeTariff(struct TicketTypeTariffStruct *ptHead)
{
	struct TicketTypeTariffStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketTypeTariff(struct TicketTypeTariffStruct **pptHead)
{
	int iCnt=0;
	static struct TicketTypeTariffStruct *pTemp,*ptHead=NULL;
	struct TicketTypeTariffStruct Temp;
	struct TicketTypeTariffStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketTypeTariff(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TicketTypeTariffStructIn));
	sprintf(TempIn.sTableName,"TICKET_TYPE_TARIFF");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketTypeTariffToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketTypeTariffStruct*)
			malloc(sizeof(struct TicketTypeTariffStruct)))==NULL){

			DestroyTicketTypeTariff(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketTypeTariffStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_TYPE_TARIFF记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_TYPE_TARIFF完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TIME_SPAN_DISCT中用结构缓冲方式取数据*/
int EGetTimeSpanDisctToStruct(struct TimeSpanDisctStruct *p,
	struct TimeSpanDisctStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TIME_SPAN_DISCT_ID,\n\
				nvl(DISCT_RULE_ID,-1),\n\
				PRIORITY,\n\
				OFFSET1,\n\
				DURATION1,\n\
				CYCLE,\n\
				OFFSET2,\n\
				DURATION2,\n\
				METHOD,\n\
				RATE\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TIME_SPAN_DISCTSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1984;
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


		CheckSqlError(" PREPARE TIME_SPAN_DISCTSCR TIME_SPAN_DISCTCR");

		/* EXEC SQL DECLARE TIME_SPAN_DISCTCR CURSOR FOR TIME_SPAN_DISCTSCR; */ 

		CheckSqlError("Declare TIME_SPAN_DISCTCR");

		/* EXEC SQL OPEN TIME_SPAN_DISCTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2003;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TIME_SPAN_DISCTCR;");


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

		/* EXEC SQL CLOSE TIME_SPAN_DISCTCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2018;
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
		/* EXEC SQL FETCH TIME_SPAN_DISCTCR INTO
			:pSource->aiTimeSpanDisctID,
			:pSource->aiDisctRuleID,
			:pSource->aiPriority,
			:pSource->aiOffset1,
			:pSource->aiDuration1,
			:pSource->aiCycle,
			:pSource->aiOffset2,
			:pSource->aiDuration2,
			:pSource->asMethod,
			:pSource->aiRate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2033;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTimeSpanDisctID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiDisctRuleID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiPriority);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiOffset1);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiDuration1);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiCycle);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiOffset2);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiDuration2);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asMethod);
  sqlstm.sqhstl[8] = (unsigned long )3;
  sqlstm.sqhsts[8] = (         int  )3;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiRate);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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


		CheckSqlError("Fetch TIME_SPAN_DISCTCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TIME_SPAN_DISCTCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2088;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TIME_SPAN_DISCT_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTimeSpanDisctID=	pSource->aiTimeSpanDisctID[iCurPos];
		p->iDisctRuleID=	pSource->aiDisctRuleID[iCurPos];
		p->iPriority=		pSource->aiPriority[iCurPos];
		p->iOffset1=		pSource->aiOffset1[iCurPos];
		p->iDuration1=		pSource->aiDuration1[iCurPos];
		p->iCycle=		pSource->aiCycle[iCurPos];
		p->iOffset2=		pSource->aiOffset2[iCurPos];
		p->iDuration2=		pSource->aiDuration2[iCurPos];

		strcpy(p->sMethod,	pSource->asMethod[iCurPos]);

		p->iRate=		pSource->aiRate[iCurPos];

		AllTrim(p->sMethod);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TIME_SPAN_DISCT的链表释放函数**/
void DestroyTimeSpanDisct(struct TimeSpanDisctStruct *ptHead)
{
	struct TimeSpanDisctStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTimeSpanDisct(struct TimeSpanDisctStruct **pptHead)
{
	int iCnt=0;
	static struct TimeSpanDisctStruct *pTemp,*ptHead=NULL;
	struct TimeSpanDisctStruct Temp;
	struct TimeSpanDisctStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTimeSpanDisct(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TimeSpanDisctStructIn));
	sprintf(TempIn.sTableName,"TIME_SPAN_DISCT");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTimeSpanDisctToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TimeSpanDisctStruct*)
			malloc(sizeof(struct TimeSpanDisctStruct)))==NULL){

			DestroyTimeSpanDisct(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TimeSpanDisctStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TIME_SPAN_DISCT记录数%d",iCnt);
	}

	WriteProcMsg("加载表TIME_SPAN_DISCT完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从DISCT_RULE中用结构缓冲方式取数据*/
int EGetDisctRuleToStruct(struct DisctRuleStruct *p,
	struct DisctRuleStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				DISCT_RULE_ID,\n\
				DISCT_TYPE,\n\
				nvl(TARIFF_ID,0),\n\
				nvl(SEQ_NBR,1),\n\
				SOURCE_ID,\n\
				nvl(LATN_ID,-1),\n\
				nvl(PRIORITY,-1),\n\
				to_char(EFF_DATE,'yyyymmddhh24miss'),\n\
				to_char(EXP_DATE,'yyyymmddhh24miss'),\n\
				RULE_NAME\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE DISCT_RULESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2103;
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


		CheckSqlError(" PREPARE DISCT_RULESCR DISCT_RULECR");

		/* EXEC SQL DECLARE DISCT_RULECR CURSOR FOR DISCT_RULESCR; */ 

		CheckSqlError("Declare DISCT_RULECR");

		/* EXEC SQL OPEN DISCT_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2122;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open DISCT_RULECR;");


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

		/* EXEC SQL CLOSE DISCT_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2137;
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
		/* EXEC SQL FETCH DISCT_RULECR INTO
			:pSource->aiDisctRuleID,
			:pSource->asDisctType,
			:pSource->aiTariffID,
			:pSource->aiSeqNbr,
			:pSource->aiSourceID,
			:pSource->aiLatnID,
			:pSource->aiPriority,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asRuleName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2152;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiDisctRuleID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asDisctType);
  sqlstm.sqhstl[1] = (unsigned long )3;
  sqlstm.sqhsts[1] = (         int  )3;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiTariffID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiSourceID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiLatnID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiPriority);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asRuleName);
  sqlstm.sqhstl[9] = (unsigned long )41;
  sqlstm.sqhsts[9] = (         int  )41;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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


		CheckSqlError("Fetch DISCT_RULECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE DISCT_RULECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2207;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=DISCT_RULE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iDisctRuleID=	pSource->aiDisctRuleID[iCurPos];

		strcpy(p->sDisctType,	pSource->asDisctType[iCurPos]);

		p->iTariffID=		pSource->aiTariffID[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];

		p->iSourceID=		pSource->aiSourceID[iCurPos];
		p->iLatnID=		pSource->aiLatnID[iCurPos];
		p->iPriority=		pSource->aiPriority[iCurPos];

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sRuleName,	pSource->asRuleName[iCurPos]);

		AllTrim(p->sDisctType);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sRuleName);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表DISCT_RULE的链表释放函数**/
void DestroyDisctRule(struct DisctRuleStruct *ptHead)
{
	struct DisctRuleStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitDisctRule(struct DisctRuleStruct **pptHead)
{
	int iCnt=0;
	static struct DisctRuleStruct *pTemp,*ptHead=NULL;
	struct DisctRuleStruct Temp;
	struct DisctRuleStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyDisctRule(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct DisctRuleStructIn));
	sprintf(TempIn.sTableName,"DISCT_RULE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetDisctRuleToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct DisctRuleStruct*)
			malloc(sizeof(struct DisctRuleStruct)))==NULL){

			DestroyDisctRule(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct DisctRuleStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表DISCT_RULE记录数%d",iCnt);
	}

	WriteProcMsg("加载表DISCT_RULE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从CELL_CODE中用结构缓冲方式取数据*/
int EGetCellCodeToStruct(struct CellCodeStruct *p,
	struct CellCodeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				CELL_CODE_ID,\n\
				SEQ_NBR,\n\
				MSC,\n\
				LAC,\n\
				CELL_ID,\n\
				AREA_CODE,\n\
				REMARK,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE CELL_CODESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2222;
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


		CheckSqlError(" PREPARE CELL_CODESCR CELL_CODECR");

		/* EXEC SQL DECLARE CELL_CODECR CURSOR FOR CELL_CODESCR; */ 

		CheckSqlError("Declare CELL_CODECR");

		/* EXEC SQL OPEN CELL_CODECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2241;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open CELL_CODECR;");


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

		/* EXEC SQL CLOSE CELL_CODECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2256;
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
		/* EXEC SQL FETCH CELL_CODECR INTO
			:pSource->aiCellCodeID,
			:pSource->aiSeqNbr,
			:pSource->asMsc,
			:pSource->asLac,
			:pSource->asCellID,
			:pSource->asAreaCode,
			:pSource->asRemark,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2271;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiCellCodeID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )11;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asLac);
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )5;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCellID);
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )5;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )6;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[6] = (unsigned long )61;
  sqlstm.sqhsts[6] = (         int  )61;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
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


		CheckSqlError("Fetch CELL_CODECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE CELL_CODECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2334;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=CELL_CODE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iCellCodeID=		pSource->aiCellCodeID[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];

		strcpy(p->sMsc,		pSource->asMsc[iCurPos]);
		strcpy(p->sLac,		pSource->asLac[iCurPos]);
		strcpy(p->sCellID,	pSource->asCellID[iCurPos]);
		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		strcpy(p->sEffDate,		pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,		pSource->asExpDate[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sStateDate,		pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,		pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sMsc);
		AllTrim(p->sLac);
		AllTrim(p->sCellID);
		AllTrim(p->sAreaCode);
		AllTrim(p->sRemark);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表CELL_CODE的链表释放函数**/
void DestroyCellCode(struct CellCodeStruct *ptHead)
{
	struct CellCodeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitCellCode(struct CellCodeStruct **pptHead)
{
	int iCnt=0;
	static struct CellCodeStruct *pTemp,*ptHead=NULL;
	struct CellCodeStruct Temp;
	struct CellCodeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyCellCode(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct CellCodeStructIn));
	sprintf(TempIn.sTableName,"CELL_CODE");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetCellCodeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct CellCodeStruct*)
			malloc(sizeof(struct CellCodeStruct)))==NULL){

			DestroyCellCode(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct CellCodeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表CELL_CODE记录数%d",iCnt);
	}

	WriteProcMsg("加载表CELL_CODE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从DISCT_RULE_MUTEX中用结构缓冲方式取数据*/
int EGetDisctRuleMutexToStruct(struct DisctRuleMutexStruct *p,
	struct DisctRuleMutexStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				DISCT_RULE_ID,\n\
				EXCLUDE_DISCT_RULE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE DISCT_RULE_MUTEXSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2349;
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


		CheckSqlError(" PREPARE DISCT_RULE_MUTEXSCR DISCT_RULE_MUTEXCR");

		/* EXEC SQL DECLARE DISCT_RULE_MUTEXCR CURSOR FOR DISCT_RULE_MUTEXSCR; */ 

		CheckSqlError("Declare DISCT_RULE_MUTEXCR");

		/* EXEC SQL OPEN DISCT_RULE_MUTEXCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2368;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open DISCT_RULE_MUTEXCR;");


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

		/* EXEC SQL CLOSE DISCT_RULE_MUTEXCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2383;
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
		/* EXEC SQL FETCH DISCT_RULE_MUTEXCR INTO
			:pSource->aiDisctRuleID,
			:pSource->aiExcludeDisctRuleID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2398;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiDisctRuleID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiExcludeDisctRuleID);
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


		CheckSqlError("Fetch DISCT_RULE_MUTEXCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE DISCT_RULE_MUTEXCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2421;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=DISCT_RULE_MUTEX_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iDisctRuleID=	pSource->aiDisctRuleID[iCurPos];
		p->iExcludeDisctRuleID=	pSource->aiExcludeDisctRuleID[iCurPos];


	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表DISCT_RULE_MUTEX的链表释放函数**/
void DestroyDisctRuleMutex(struct DisctRuleMutexStruct *ptHead)
{
	struct DisctRuleMutexStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitDisctRuleMutex(struct DisctRuleMutexStruct **pptHead)
{
	int iCnt=0;
	static struct DisctRuleMutexStruct *pTemp,*ptHead=NULL;
	struct DisctRuleMutexStruct Temp;
	struct DisctRuleMutexStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyDisctRuleMutex(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct DisctRuleMutexStructIn));
	sprintf(TempIn.sTableName,"DISCT_RULE_MUTEX");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetDisctRuleMutexToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct DisctRuleMutexStruct*)
			malloc(sizeof(struct DisctRuleMutexStruct)))==NULL){

			DestroyDisctRuleMutex(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct DisctRuleMutexStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表DISCT_RULE_MUTEX记录数%d",iCnt);
	}

	WriteProcMsg("加载表DISCT_RULE_MUTEX完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从DISP_PARAM中用结构缓冲方式取数据*/
int EGetDispParamToStruct(struct DispParamStruct *p,
	struct DispParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				GROUP_ID,\n\
				SOURCE_PATH,\n\
				FILTER,\n\
				DEST_PATH1,\n\
				nvl(DEST_PATH2,'-1'),\n\
				nvl(DEST_PATH3,'-1'),\n\
				nvl(DEST_PATH4,'-1'),\n\
				STATE\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE DISP_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2436;
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


		CheckSqlError(" PREPARE DISP_PARAMSCR DISP_PARAMCR");

		/* EXEC SQL DECLARE DISP_PARAMCR CURSOR FOR DISP_PARAMSCR; */ 

		CheckSqlError("Declare DISP_PARAMCR");

		/* EXEC SQL OPEN DISP_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2455;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open DISP_PARAMCR;");


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

		/* EXEC SQL CLOSE DISP_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2470;
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
		/* EXEC SQL FETCH DISP_PARAMCR INTO
			:pSource->aiGroupID,
			:pSource->asSourcePath,
			:pSource->asFilter,
			:pSource->asDestPath1,
			:pSource->asDestPath2,
			:pSource->asDestPath3,
			:pSource->asDestPath4,
			:pSource->asState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2485;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asSourcePath);
  sqlstm.sqhstl[1] = (unsigned long )81;
  sqlstm.sqhsts[1] = (         int  )81;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[2] = (unsigned long )21;
  sqlstm.sqhsts[2] = (         int  )21;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asDestPath1);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )81;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asDestPath2);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asDestPath3);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asDestPath4);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
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


		CheckSqlError("Fetch DISP_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE DISP_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2532;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=DISP_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sSourcePath,	pSource->asSourcePath[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sDestPath1,	pSource->asDestPath1[iCurPos]);
		strcpy(p->sDestPath2,	pSource->asDestPath2[iCurPos]);
		strcpy(p->sDestPath3,	pSource->asDestPath3[iCurPos]);
		strcpy(p->sDestPath4,	pSource->asDestPath4[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);

		AllTrim(p->sSourcePath);
		AllTrim(p->sFilter);
		AllTrim(p->sDestPath1);
		AllTrim(p->sDestPath2);
		AllTrim(p->sDestPath3);
		AllTrim(p->sDestPath4);
		AllTrim(p->sState);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表DISP_PARAM的链表释放函数**/
void DestroyDispParam(struct DispParamStruct *ptHead)
{
	struct DispParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitDispParam(struct DispParamStruct **pptHead)
{
	int iCnt=0;
	static struct DispParamStruct *pTemp,*ptHead=NULL;
	struct DispParamStruct Temp;
	struct DispParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyDispParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct DispParamStructIn));
	sprintf(TempIn.sTableName,"DISP_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetDispParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct DispParamStruct*)
			malloc(sizeof(struct DispParamStruct)))==NULL){

			DestroyDispParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct DispParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表DISP_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表DISP_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从INST_PARAM中用结构缓冲方式取数据*/
int EGetInstParamToStruct(struct InstParamStruct *p,
	struct InstParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				GROUP_ID,\n\
				FILE_TYPE,\n\
				OPER_TYPE,\n\
				DATE_RULE,\n\
				SOURCE_PATH,\n\
				FILTER,\n\
				BACK_PATH,\n\
				BELONG_CODE,\n\
				MODULE,\n\
				STATE,\n\
				APP_ID,\n\
				TACHE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE INST_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2547;
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


		CheckSqlError(" PREPARE INST_PARAMSCR INST_PARAMCR");

		/* EXEC SQL DECLARE INST_PARAMCR CURSOR FOR INST_PARAMSCR; */ 

		CheckSqlError("Declare INST_PARAMCR");

		/* EXEC SQL OPEN INST_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2566;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open INST_PARAMCR;");


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

		/* EXEC SQL CLOSE INST_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2581;
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
		/* EXEC SQL FETCH INST_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiGroupID,
			:pSource->asFileType,
			:pSource->asOperType,
			:pSource->asDateRule,
			:pSource->asSourcePath,
			:pSource->asFilter,
			:pSource->asBackPath,
			:pSource->asBelongCode,
			:pSource->asModule,
			:pSource->asState,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2596;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asOperType);
  sqlstm.sqhstl[3] = (unsigned long )4;
  sqlstm.sqhsts[3] = (         int  )4;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asDateRule);
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )13;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asSourcePath);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[6] = (unsigned long )21;
  sqlstm.sqhsts[6] = (         int  )21;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asBackPath);
  sqlstm.sqhstl[7] = (unsigned long )81;
  sqlstm.sqhsts[7] = (         int  )81;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asBelongCode);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )6;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )11;
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


		CheckSqlError("Fetch INST_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE INST_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2663;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=INST_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sFileType,	pSource->asFileType[iCurPos]);
		strcpy(p->sOperType,	pSource->asOperType[iCurPos]);
		strcpy(p->sDateRule,	pSource->asDateRule[iCurPos]);
		strcpy(p->sSourcePath,	pSource->asSourcePath[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sBackPath,	pSource->asBackPath[iCurPos]);
		strcpy(p->sBelongCode,	pSource->asBelongCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		p->iTacheID=		pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sFileType);
		AllTrim(p->sOperType);
		AllTrim(p->sDateRule);
		AllTrim(p->sSourcePath);
		AllTrim(p->sFilter);
		AllTrim(p->sBackPath);
		AllTrim(p->sBelongCode);
		AllTrim(p->sModule);
		AllTrim(p->sState);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表INST_PARAM的链表释放函数**/
void DestroyInstParam(struct InstParamStruct *ptHead)
{
	struct InstParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitInstParam(struct InstParamStruct **pptHead)
{
	int iCnt=0;
	static struct InstParamStruct *pTemp,*ptHead=NULL;
	struct InstParamStruct Temp;
	struct InstParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyInstParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct InstParamStructIn));
	sprintf(TempIn.sTableName,"INST_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetInstParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		RegularDir(Temp.sSourcePath);
		RegularDir(Temp.sBackPath);

		if((pTemp=(struct InstParamStruct*)
			malloc(sizeof(struct InstParamStruct)))==NULL){

			DestroyInstParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct InstParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表INST_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表INST_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从PICK_PARAM中用结构缓冲方式取数据*/
int EGetPickParamToStruct(struct PickParamStruct *p,
	struct PickParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				GROUP_ID,\n\
				OPP_PATH,\n\
				OPP_BKUP_PATH,\n\
				LOCAL_PATH,\n\
				IP,\n\
				USER_NAME,\n\
				PASSWD,\n\
				FILTER,\n\
				SEQ_OFF,\n\
				SEQ_LEN,\n\
				DELETE_TYPE,\n\
				CHK_DAYS,\n\
				OUT_TYPE,\n\
				STATE,\n\
				APP_ID,\n\
				TACHE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PICK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2678;
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


		CheckSqlError(" PREPARE PICK_PARAMSCR PICK_PARAMCR");

		/* EXEC SQL DECLARE PICK_PARAMCR CURSOR FOR PICK_PARAMSCR; */ 

		CheckSqlError("Declare PICK_PARAMCR");

		/* EXEC SQL OPEN PICK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2697;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PICK_PARAMCR;");


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

		/* EXEC SQL CLOSE PICK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2712;
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
		/* EXEC SQL FETCH PICK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiGroupID,
			:pSource->asOppPath,
			:pSource->asOppBkupPath,
			:pSource->asLocalPath,
			:pSource->asIp,
			:pSource->asUserName,
			:pSource->asPasswd,
			:pSource->asFilter,
			:pSource->aiSeqOff,
			:pSource->aiSeqLen,
			:pSource->asDeleteType,
			:pSource->aiChkDays,
			:pSource->asOutType,
			:pSource->asState,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2727;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asOppPath);
  sqlstm.sqhstl[2] = (unsigned long )81;
  sqlstm.sqhsts[2] = (         int  )81;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asOppBkupPath);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )81;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asLocalPath);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asIp);
  sqlstm.sqhstl[5] = (unsigned long )17;
  sqlstm.sqhsts[5] = (         int  )17;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asUserName);
  sqlstm.sqhstl[6] = (unsigned long )21;
  sqlstm.sqhsts[6] = (         int  )21;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asPasswd);
  sqlstm.sqhstl[7] = (unsigned long )21;
  sqlstm.sqhsts[7] = (         int  )21;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[8] = (unsigned long )21;
  sqlstm.sqhsts[8] = (         int  )21;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiSeqOff);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiSeqLen);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asDeleteType);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiChkDays);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asOutType);
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )6;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[15] = (unsigned long )11;
  sqlstm.sqhsts[15] = (         int  )11;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch PICK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PICK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2810;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PICK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sOppPath,	pSource->asOppPath[iCurPos]);
		strcpy(p->sOppBkupPath,	pSource->asOppBkupPath[iCurPos]);
		strcpy(p->sLocalPath,	pSource->asLocalPath[iCurPos]);
		strcpy(p->sIp,		pSource->asIp[iCurPos]);
		strcpy(p->sUserName,	pSource->asUserName[iCurPos]);
		strcpy(p->sPasswd,	pSource->asPasswd[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);

		p->iSeqOff=		pSource->aiSeqOff[iCurPos];
		p->iSeqLen=		pSource->aiSeqLen[iCurPos];

		strcpy(p->sDeleteType,	pSource->asDeleteType[iCurPos]);
		
		p->iChkDays=		pSource->aiChkDays[iCurPos];
		
		strcpy(p->sOutType,	pSource->asOutType[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		p->iTacheID=		pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sOppPath);
		AllTrim(p->sOppBkupPath);
		AllTrim(p->sLocalPath);
		AllTrim(p->sIp);
		AllTrim(p->sUserName);
		AllTrim(p->sPasswd);
		AllTrim(p->sFilter);
		AllTrim(p->sDeleteType);
		AllTrim(p->sOutType);
		AllTrim(p->sState);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表PICK_PARAM的链表释放函数**/
void DestroyPickParam(struct PickParamStruct *ptHead)
{
	struct PickParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitPickParam(struct PickParamStruct **pptHead)
{
	int iCnt=0;
	static struct PickParamStruct *pTemp,*ptHead=NULL;
	struct PickParamStruct Temp;
	struct PickParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyPickParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PickParamStructIn));
	sprintf(TempIn.sTableName,"PICK_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetPickParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		RegularDir(Temp.sOppBkupPath);
		RegularDir(Temp.sLocalPath);

		if((pTemp=(struct PickParamStruct*)
			malloc(sizeof(struct PickParamStruct)))==NULL){

			DestroyPickParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct PickParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表PICK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表PICK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}


/*批量数据动态从PREP_PARAM中用结构缓冲方式取数据*/
int EGetPrepParamToStruct(struct PrepParamStruct *p,
	struct PrepParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				GROUP_ID,\n\
				MSC,\n\
				AREA_CODE,\n\
				EXPR_FILE,\n\
				FILTER,\n\
				SOURCE_PATH,\n\
				BACK_PATH,\n\
				NORMAL_PATH,\n\
				MODULE,\n\
				nvl(SPLIT,'C'),\n\
				nvl(START_POS,0),\n\
				nvl(KEY_LEN,0),\n\
				nvl(CHK_MOD,'CHK'),\n\
				nvl(USER_TYPE,'G'),\n\
				IN_TYPE,\n\
				OUT_TYPE,\n\
				STATE,\n\
				APP_ID,\n\
				TACHE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PREP_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2825;
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


		CheckSqlError(" PREPARE PREP_PARAMSCR PREP_PARAMCR");

		/* EXEC SQL DECLARE PREP_PARAMCR CURSOR FOR PREP_PARAMSCR; */ 

		CheckSqlError("Declare PREP_PARAMCR");

		/* EXEC SQL OPEN PREP_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2844;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PREP_PARAMCR;");


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

		/* EXEC SQL CLOSE PREP_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2859;
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
		/* EXEC SQL FETCH PREP_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiGroupID,
			:pSource->asMsc,
			:pSource->asAreaCode,
			:pSource->asExprFile,
			:pSource->asFilter,
			:pSource->asSourcePath,
			:pSource->asBackPath,
			:pSource->asNormalPath,
			:pSource->asModule,
			:pSource->asSplit,
			:pSource->aiStartPos,
			:pSource->aiKeyLen,
			:pSource->asChkMod,
			:pSource->asUserType,
			:pSource->asInType,
			:pSource->asOutType,
			:pSource->asState,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2874;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[2] = (unsigned long )16;
  sqlstm.sqhsts[2] = (         int  )16;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asExprFile);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[5] = (unsigned long )21;
  sqlstm.sqhsts[5] = (         int  )21;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asSourcePath);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asBackPath);
  sqlstm.sqhstl[7] = (unsigned long )81;
  sqlstm.sqhsts[7] = (         int  )81;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asNormalPath);
  sqlstm.sqhstl[8] = (unsigned long )81;
  sqlstm.sqhsts[8] = (         int  )81;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asSplit);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )11;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiStartPos);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiKeyLen);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asChkMod);
  sqlstm.sqhstl[13] = (unsigned long )4;
  sqlstm.sqhsts[13] = (         int  )4;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asUserType);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asInType);
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )6;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asOutType);
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )6;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[17] = (unsigned long )2;
  sqlstm.sqhsts[17] = (         int  )2;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )11;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(int);
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
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


		CheckSqlError("Fetch PREP_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PREP_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 20;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2969;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PREP_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sMsc,		pSource->asMsc[iCurPos]);
		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);
		strcpy(p->sExprFile,	pSource->asExprFile[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sSourcePath,	pSource->asSourcePath[iCurPos]);
		strcpy(p->sBackPath,	pSource->asBackPath[iCurPos]);
		strcpy(p->sNormalPath,	pSource->asNormalPath[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		
		strcpy(p->sSplit,	pSource->asSplit[iCurPos]);
		p->iStartPos=		pSource->aiStartPos[iCurPos];
		p->iKeyLen=		pSource->aiKeyLen[iCurPos];

		strcpy(p->sChkMod,	pSource->asChkMod[iCurPos]);
		strcpy(p->sUserType,	pSource->asUserType[iCurPos]);
	
		strcpy(p->sInType,	pSource->asInType[iCurPos]);
		strcpy(p->sOutType,	pSource->asOutType[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		p->iTacheID=		pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sMsc);
		AllTrim(p->sAreaCode);
		AllTrim(p->sExprFile);
		AllTrim(p->sFilter);
		AllTrim(p->sSourcePath);
		AllTrim(p->sBackPath);
		AllTrim(p->sNormalPath);
		AllTrim(p->sModule);
		AllTrim(p->sSplit);
		AllTrim(p->sChkMod);
		AllTrim(p->sUserType);
		AllTrim(p->sInType);
		AllTrim(p->sOutType);
		AllTrim(p->sState);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表PREP_PARAM的链表释放函数**/
void DestroyPrepParam(struct PrepParamStruct *ptHead)
{
	struct PrepParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitPrepParam(struct PrepParamStruct **pptHead)
{
	int iCnt=0;
	static struct PrepParamStruct *pTemp,*ptHead=NULL;
	struct PrepParamStruct Temp;
	struct PrepParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyPrepParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PrepParamStructIn));
	sprintf(TempIn.sTableName,"PREP_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetPrepParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		RegularDir(Temp.sSourcePath);
		RegularDir(Temp.sBackPath);
		RegularDir(Temp.sNormalPath);
		RegularDir(Temp.sErrPath);

		if((pTemp=(struct PrepParamStruct*)
			malloc(sizeof(struct PrepParamStruct)))==NULL){

			DestroyPrepParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct PrepParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表PREP_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表PREP_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从BILL_PARAM中用结构缓冲方式取数据*/
int EGetBillParamToStruct(struct BillParamStruct *p,
	struct BillParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				APP_CODE,\n\
				GROUP_ID,\n\
				FILTER,\n\
				SOURCE_PATH,\n\
				BACK_PATH,\n\
				NORMAL_PATH,\n\
				USER_TYPE,\n\
				TEMPLATE_ID,\n\
				SPLIT_STR,\n\
				BELONG_CODE,\n\
				MODULE,\n\
				nvl(SPLIT,' '),\n\
				START_POS,\n\
				KEY_LEN,\n\
				nvl(BATCH_FLAG,'0'),\n\
				IN_TYPE,\n\
				OUT_TYPE,\n\
				STATE,\n\
				APP_ID,\n\
				TACHE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE BILL_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2984;
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


		CheckSqlError(" PREPARE BILL_PARAMSCR BILL_PARAMCR");

		/* EXEC SQL DECLARE BILL_PARAMCR CURSOR FOR BILL_PARAMSCR; */ 

		CheckSqlError("Declare BILL_PARAMCR");

		/* EXEC SQL OPEN BILL_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3003;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open BILL_PARAMCR;");


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

		/* EXEC SQL CLOSE BILL_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3018;
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
		/* EXEC SQL FETCH BILL_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->asAppCode,
			:pSource->aiGroupID,
			:pSource->asFilter,
			:pSource->asSourcePath,
			:pSource->asBackPath,
			:pSource->asNormalPath,
			:pSource->asUserType,
			:pSource->asTemplateID,
			:pSource->asSplitStr,
			:pSource->asBelongCode,
			:pSource->asModule,
			:pSource->asSplit,
			:pSource->aiStartPos,
			:pSource->aiKeyLen,
			:pSource->asBatchFlag,
			:pSource->asInType,
			:pSource->asOutType,
			:pSource->asState,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3033;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asAppCode);
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )9;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[3] = (unsigned long )21;
  sqlstm.sqhsts[3] = (         int  )21;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asSourcePath);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asBackPath);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asNormalPath);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asUserType);
  sqlstm.sqhstl[7] = (unsigned long )41;
  sqlstm.sqhsts[7] = (         int  )41;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asTemplateID);
  sqlstm.sqhstl[8] = (unsigned long )81;
  sqlstm.sqhsts[8] = (         int  )81;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asSplitStr);
  sqlstm.sqhstl[9] = (unsigned long )11;
  sqlstm.sqhsts[9] = (         int  )11;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asBelongCode);
  sqlstm.sqhstl[10] = (unsigned long )6;
  sqlstm.sqhsts[10] = (         int  )6;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[11] = (unsigned long )4;
  sqlstm.sqhsts[11] = (         int  )4;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asSplit);
  sqlstm.sqhstl[12] = (unsigned long )10;
  sqlstm.sqhsts[12] = (         int  )10;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->aiStartPos);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiKeyLen);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asBatchFlag);
  sqlstm.sqhstl[15] = (unsigned long )2;
  sqlstm.sqhsts[15] = (         int  )2;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asInType);
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )6;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asOutType);
  sqlstm.sqhstl[17] = (unsigned long )6;
  sqlstm.sqhsts[17] = (         int  )6;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[18] = (unsigned long )2;
  sqlstm.sqhsts[18] = (         int  )2;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[19] = (unsigned long )11;
  sqlstm.sqhsts[19] = (         int  )11;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
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


		CheckSqlError("Fetch BILL_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE BILL_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3132;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=BILL_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);
		strcpy(p->sAppCode,	pSource->asAppCode[iCurPos]);

		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sSourcePath,	pSource->asSourcePath[iCurPos]);
		strcpy(p->sBackPath,	pSource->asBackPath[iCurPos]);
		strcpy(p->sNormalPath,	pSource->asNormalPath[iCurPos]);
		strcpy(p->sUserType,	pSource->asUserType[iCurPos]);

		strcpy(p->sTemplateID,	pSource->asTemplateID[iCurPos]);
		strcpy(p->sSplitStr,	pSource->asSplitStr[iCurPos]);
		strcpy(p->sBelongCode,	pSource->asBelongCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sSplit,	pSource->asSplit[iCurPos]);

		p->iStartPos=		pSource->aiStartPos[iCurPos];
		p->iKeyLen=		pSource->aiKeyLen[iCurPos];

		strcpy(p->sBatchFlag,	pSource->asBatchFlag[iCurPos]);

		strcpy(p->sInType,	pSource->asInType[iCurPos]);
		strcpy(p->sOutType,	pSource->asOutType[iCurPos]);

		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		p->iTacheID=		pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sSourceID);
		AllTrim(p->sFilter);
		AllTrim(p->sSourcePath);
		AllTrim(p->sBackPath);
		AllTrim(p->sNormalPath);
		AllTrim(p->sUserType);
		AllTrim(p->sTemplateID);
		AllTrim(p->sSplitStr);
		AllTrim(p->sBelongCode);
		AllTrim(p->sModule);
		AllTrim(p->sSplit);
		AllTrim(p->sBatchFlag);
		AllTrim(p->sInType);
		AllTrim(p->sOutType);
		AllTrim(p->sState);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表BILL_PARAM的链表释放函数**/
void DestroyBillParam(struct BillParamStruct *ptHead)
{
	struct BillParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitBillParam(struct BillParamStruct **pptHead)
{
	int iCnt=0;
	static struct BillParamStruct *pTemp,*ptHead=NULL;
	struct BillParamStruct Temp;
	struct BillParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyBillParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct BillParamStructIn));
	sprintf(TempIn.sTableName,"BILL_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetBillParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		RegularDir(Temp.sSourcePath);
		RegularDir(Temp.sBackPath);
		RegularDir(Temp.sNormalPath);
		RegularDir(Temp.sErrPath);

		if((pTemp=(struct BillParamStruct*)
			malloc(sizeof(struct BillParamStruct)))==NULL){

			DestroyBillParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct BillParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表BILL_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表BILL_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从COMM_SEARCH中用结构缓冲方式取数据*/
int EGetCommSearchToStruct(struct CommSearchStruct *p,
	struct CommSearchStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TABLE_NAME,\n\
				METHOD,\n\
				INT_KEY,\n\
				STR_KEY,\n\
				nvl(INT_VAL,0),\n\
				nvl(STR_VAL,' '),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE COMM_SEARCHSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3147;
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


		CheckSqlError(" PREPARE COMM_SEARCHSCR COMM_SEARCHCR");

		/* EXEC SQL DECLARE COMM_SEARCHCR CURSOR FOR COMM_SEARCHSCR; */ 

		CheckSqlError("Declare COMM_SEARCHCR");

		/* EXEC SQL OPEN COMM_SEARCHCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3166;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open COMM_SEARCHCR;");


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

		/* EXEC SQL CLOSE COMM_SEARCHCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3181;
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
		/* EXEC SQL FETCH COMM_SEARCHCR INTO
			:pSource->asTableName,
			:pSource->asMethod,
			:pSource->aiIntKey,
			:pSource->asStrKey,
			:pSource->aiIntVal,
			:pSource->asStrVal,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3196;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )31;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asMethod);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiIntKey);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asStrKey);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )81;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiIntVal);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asStrVal);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )15;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[8] = (unsigned long )4;
  sqlstm.sqhsts[8] = (         int  )4;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asCreatedDate);
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


		CheckSqlError("Fetch COMM_SEARCHCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE COMM_SEARCHCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3255;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=COMM_SEARCH_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sTableName,	pSource->asTableName[iCurPos]);
		strcpy(p->sMethod,	pSource->asMethod[iCurPos]);

		p->iIntKey=		pSource->aiIntKey[iCurPos];

		strcpy(p->sStrKey,	pSource->asStrKey[iCurPos]);

		p->iIntVal=		pSource->aiIntVal[iCurPos];

		strcpy(p->sStrVal,	pSource->asStrVal[iCurPos]);

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);

		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sTableName);
		AllTrim(p->sMethod);
		AllTrim(p->sStrKey);
		AllTrim(p->sStrVal);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表COMM_SEARCH的链表释放函数**/
void DestroyCommSearch(struct CommSearchStruct *ptHead)
{
	struct CommSearchStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitCommSearch(struct CommSearchStruct **pptHead,char sMethod[])
{
	int iCnt=0;
	struct CommSearchStruct *pTemp,*ptHead=NULL;
	struct CommSearchStruct Temp;
	struct CommSearchStructIn TempIn;

	*pptHead=NULL;
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct CommSearchStructIn));
	sprintf(TempIn.sTableName,"COMM_SEARCH");
	sprintf(TempIn.sCondition,
		" %s AND METHOD='%s' ",PARAM_COND,sMethod);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetCommSearchToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct CommSearchStruct*)
			malloc(sizeof(struct CommSearchStruct)))==NULL){

			DestroyCommSearch(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct CommSearchStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表COMM_SEARCH_%s记录数%d",sMethod,iCnt);
	}

	WriteProcMsg("加载表COMM_SEARCH_%s完毕总记录数%d",sMethod,iCnt);

	return iCnt;
}
int InitCommSearchBin(struct CommSearchStruct **pptHead)
{
	return InitCommSearch(pptHead,"B");
}
int InitCommSearchTrie(struct CommSearchStruct **pptHead)
{
	return InitCommSearch(pptHead,"T");
}
/*批量数据动态从COMM_RANGE中用结构缓冲方式取数据*/
int EGetCommRangeToStruct(struct CommRangeStruct *p,
	struct CommRangeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TABLE_NAME,\n\
				BGN_KEY,\n\
				END_KEY,\n\
				nvl(INT_VAL,0),\n\
				nvl(STR_VAL,' '),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE COMM_RANGESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3270;
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


		CheckSqlError(" PREPARE COMM_RANGESCR COMM_RANGECR");

		/* EXEC SQL DECLARE COMM_RANGECR CURSOR FOR COMM_RANGESCR; */ 

		CheckSqlError("Declare COMM_RANGECR");

		/* EXEC SQL OPEN COMM_RANGECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3289;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open COMM_RANGECR;");


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

		/* EXEC SQL CLOSE COMM_RANGECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3304;
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
		/* EXEC SQL FETCH COMM_RANGECR INTO
			:pSource->asTableName,
			:pSource->asBgnKey,
			:pSource->asEndKey,
			:pSource->aiIntVal,
			:pSource->asStrVal,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3319;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )31;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asBgnKey);
  sqlstm.sqhstl[1] = (unsigned long )21;
  sqlstm.sqhsts[1] = (         int  )21;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asEndKey);
  sqlstm.sqhstl[2] = (unsigned long )21;
  sqlstm.sqhsts[2] = (         int  )21;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiIntVal);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asStrVal);
  sqlstm.sqhstl[4] = (unsigned long )41;
  sqlstm.sqhsts[4] = (         int  )41;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[5] = (unsigned long )15;
  sqlstm.sqhsts[5] = (         int  )15;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )15;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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


		CheckSqlError("Fetch COMM_RANGECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE COMM_RANGECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3374;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=COMM_RANGE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sTableName,	pSource->asTableName[iCurPos]);
		strcpy(p->sBgnKey,	pSource->asBgnKey[iCurPos]);
		strcpy(p->sEndKey,	pSource->asEndKey[iCurPos]);

		p->iIntVal=		pSource->aiIntVal[iCurPos];

		strcpy(p->sStrVal,	pSource->asStrVal[iCurPos]);

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sTableName);
		AllTrim(p->sBgnKey);
		AllTrim(p->sEndKey);
		AllTrim(p->sStrVal);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表COMM_RANGE的链表释放函数**/
void DestroyCommRange(struct CommRangeStruct *ptHead)
{
	struct CommRangeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitCommRange(struct CommRangeStruct **pptHead)
{
	int iCnt=0;
	static struct CommRangeStruct *pTemp,*ptHead=NULL;
	struct CommRangeStruct Temp;
	struct CommRangeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyCommRange(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct CommRangeStructIn));
	sprintf(TempIn.sTableName,"COMM_RANGE");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetCommRangeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;
/*这里修改，抛弃异常数据*/
		if(strcmp(Temp.sBgnKey,Temp.sEndKey)>0){
WriteAlertMsg("COMM_RANGER异常数据tab=%s,bgn_key=%s,end_key%s未加载,丢弃",
				Temp.sTableName,Temp.sBgnKey,Temp.sEndKey);
			continue;
		}

		if((pTemp=(struct CommRangeStruct*)
			malloc(sizeof(struct CommRangeStruct)))==NULL){

			DestroyCommRange(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct CommRangeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表COMM_RANGE记录数%d",iCnt);
	}

	WriteProcMsg("加载表COMM_RANGE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从SWITCH中用结构缓冲方式取数据*/
int EGetSwitchToStruct(struct SwitchStruct *p,
	struct SwitchStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SWITCH_ID,\n\
				TYPE_ID,\n\
				AREA_CODE,\n\
				METHOD,\n\
				nvl(IP,'-1'),\n\
				nvl(PORT,-1),\n\
				nvl(USER_NAME,'bill'),\n\
				nvl(PASSWORD,'bill'),\n\
				REMARK\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SWITCHSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3389;
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


		CheckSqlError(" PREPARE SWITCHSCR SWITCHCR");

		/* EXEC SQL DECLARE SWITCHCR CURSOR FOR SWITCHSCR; */ 

		CheckSqlError("Declare SWITCHCR");

		/* EXEC SQL OPEN SWITCHCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3408;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SWITCHCR;");


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

		/* EXEC SQL CLOSE SWITCHCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3423;
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
		/* EXEC SQL FETCH SWITCHCR INTO
			:pSource->aiSwitchID,
			:pSource->aiTypeID,
			:pSource->asAreaCode,
			:pSource->asMethod,
			:pSource->asIp,
			:pSource->aiPort,
			:pSource->asUserName,
			:pSource->asPassword,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3438;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiSwitchID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiTypeID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asMethod);
  sqlstm.sqhstl[3] = (unsigned long )7;
  sqlstm.sqhsts[3] = (         int  )7;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asIp);
  sqlstm.sqhstl[4] = (unsigned long )16;
  sqlstm.sqhsts[4] = (         int  )16;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiPort);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asUserName);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )31;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asPassword);
  sqlstm.sqhstl[7] = (unsigned long )31;
  sqlstm.sqhsts[7] = (         int  )31;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[8] = (unsigned long )61;
  sqlstm.sqhsts[8] = (         int  )61;
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


		CheckSqlError("Fetch SWITCHCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SWITCHCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3489;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SWITCH_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iSwitchID=		pSource->aiSwitchID[iCurPos];
		p->iTypeID=		pSource->aiTypeID[iCurPos];

		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);
		strcpy(p->sMethod,	pSource->asMethod[iCurPos]);
		strcpy(p->sIp,		pSource->asIp[iCurPos]);

		p->iPort=		pSource->aiPort[iCurPos];

		strcpy(p->sUserName,	pSource->asUserName[iCurPos]);
		strcpy(p->sPassword,	pSource->asPassword[iCurPos]);

		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		AllTrim(p->sAreaCode);
		AllTrim(p->sMethod);
		AllTrim(p->sIp);
		AllTrim(p->sUserName);
		AllTrim(p->sPassword);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表SWITCH的链表释放函数**/
void DestroySwitch(struct SwitchStruct *ptHead)
{
	struct SwitchStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSwitch(struct SwitchStruct **pptHead)
{
	int iCnt=0;
	static struct SwitchStruct *pTemp,*ptHead=NULL;
	struct SwitchStruct Temp;
	struct SwitchStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySwitch(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SwitchStructIn));
	sprintf(TempIn.sTableName,"SWITCH");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSwitchToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SwitchStruct*)
			malloc(sizeof(struct SwitchStruct)))==NULL){

			DestroySwitch(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SwitchStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SWITCH记录数%d",iCnt);
	}

	WriteProcMsg("加载表SWITCH完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从CMD_TEMPLATE中用结构缓冲方式取数据*/
int EGetCmdTemplateToStruct(struct CmdTemplateStruct *p,
	struct CmdTemplateStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TEMPLATE_ID,\n\
				CMD_TYPE_ID,\n\
				STANDARD_CODE,\n\
				SWITCH_TYPE_ID,\n\
				CMD_TEXT,\n\
				REMARK\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE CMD_TEMPLATESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3504;
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


		CheckSqlError(" PREPARE CMD_TEMPLATESCR CMD_TEMPLATECR");

		/* EXEC SQL DECLARE CMD_TEMPLATECR CURSOR FOR CMD_TEMPLATESCR; */ 

		CheckSqlError("Declare CMD_TEMPLATECR");

		/* EXEC SQL OPEN CMD_TEMPLATECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3523;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open CMD_TEMPLATECR;");


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

		/* EXEC SQL CLOSE CMD_TEMPLATECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3538;
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
		/* EXEC SQL FETCH CMD_TEMPLATECR INTO
			:pSource->aiTemplateID,
			:pSource->aiCmdTypeID,
			:pSource->asStandardCode,
			:pSource->aiSwitchTypeID,
			:pSource->asCmdText,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3553;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTemplateID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiCmdTypeID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asStandardCode);
  sqlstm.sqhstl[2] = (unsigned long )31;
  sqlstm.sqhsts[2] = (         int  )31;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiSwitchTypeID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCmdText);
  sqlstm.sqhstl[4] = (unsigned long )61;
  sqlstm.sqhsts[4] = (         int  )61;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[5] = (unsigned long )61;
  sqlstm.sqhsts[5] = (         int  )61;
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


		CheckSqlError("Fetch CMD_TEMPLATECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE CMD_TEMPLATECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3592;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=CMD_TEMPLATE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTemplateID=			pSource->aiTemplateID[iCurPos];
		p->iCmdTypeID=			pSource->aiCmdTypeID[iCurPos];

		strcpy(p->sStandardCode,	pSource->asStandardCode[iCurPos]);

		p->iSwitchTypeID=		pSource->aiSwitchTypeID[iCurPos];

		strcpy(p->sCmdText,		pSource->asCmdText[iCurPos]);
		strcpy(p->sRemark,		pSource->asRemark[iCurPos]);

		AllTrim(p->sStandardCode);
		AllTrim(p->sCmdText);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表CMD_TEMPLATE的链表释放函数**/
void DestroyCmdTemplate(struct CmdTemplateStruct *ptHead)
{
	struct CmdTemplateStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitCmdTemplate(struct CmdTemplateStruct **pptHead)
{
	int iCnt=0;
	static struct CmdTemplateStruct *pTemp,*ptHead=NULL;
	struct CmdTemplateStruct Temp;
	struct CmdTemplateStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyCmdTemplate(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct CmdTemplateStructIn));
	sprintf(TempIn.sTableName,"CMD_TEMPLATE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetCmdTemplateToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct CmdTemplateStruct*)
			malloc(sizeof(struct CmdTemplateStruct)))==NULL){

			DestroyCmdTemplate(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct CmdTemplateStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表CMD_TEMPLATE记录数%d",iCnt);
	}

	WriteProcMsg("加载表CMD_TEMPLATE完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从NBR_HEAD中用结构缓冲方式取数据*/
int EGetNbrHeadToStruct(struct NbrHeadStruct *p,
	struct NbrHeadStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SERVICE_TYPE,\n\
				HEAD,\n\
				FIELD_TYPE,\n\
				SWITCH_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE NBR_HEADSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3607;
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


		CheckSqlError(" PREPARE NBR_HEADSCR NBR_HEADCR");

		/* EXEC SQL DECLARE NBR_HEADCR CURSOR FOR NBR_HEADSCR; */ 

		CheckSqlError("Declare NBR_HEADCR");

		/* EXEC SQL OPEN NBR_HEADCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3626;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open NBR_HEADCR;");


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

		/* EXEC SQL CLOSE NBR_HEADCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3641;
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
		/* EXEC SQL FETCH NBR_HEADCR INTO
			:pSource->asServiceType,
			:pSource->asHead,
			:pSource->asFieldType,
			:pSource->aiSwitchID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3656;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asServiceType);
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )11;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asHead);
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )13;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asFieldType);
  sqlstm.sqhstl[2] = (unsigned long )7;
  sqlstm.sqhsts[2] = (         int  )7;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiSwitchID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch NBR_HEADCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE NBR_HEADCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3687;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=NBR_HEAD_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sServiceType,	pSource->asServiceType[iCurPos]);
		strcpy(p->sHead,	pSource->asHead[iCurPos]);
		strcpy(p->sFieldType,	pSource->asFieldType[iCurPos]);

		p->iSwitchID=		pSource->aiSwitchID[iCurPos];

		AllTrim(p->sServiceType);
		AllTrim(p->sHead);
		AllTrim(p->sFieldType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表NBR_HEAD的链表释放函数**/
void DestroyNbrHead(struct NbrHeadStruct *ptHead)
{
	struct NbrHeadStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitNbrHead(struct NbrHeadStruct **pptHead)
{
	int iCnt=0;
	static struct NbrHeadStruct *pTemp,*ptHead=NULL;
	struct NbrHeadStruct Temp;
	struct NbrHeadStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyNbrHead(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct NbrHeadStructIn));
	sprintf(TempIn.sTableName,"NBR_HEAD");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetNbrHeadToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct NbrHeadStruct*)
			malloc(sizeof(struct NbrHeadStruct)))==NULL){

			DestroyNbrHead(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct NbrHeadStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表NBR_HEAD记录数%d",iCnt);
	}

	WriteProcMsg("加载表NBR_HEAD完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从ACCT_ITEM_TYPE中用结构缓冲方式取数据*/
int EGetAcctItemTypeToStruct(struct AcctItemTypeStruct *p,
	struct AcctItemTypeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				ACCT_ITEM_TYPE_ID,\n\
				ACCT_ITEM_TYPE_KIND,\n\
				ACCT_ITEM_NAME,\n\
				nvl(STANDARD_CODE,'-1'),\n\
				nvl(SUMMARY_ITEM_ID,-1)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ACCT_ITEM_TYPESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3702;
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


		CheckSqlError(" PREPARE ACCT_ITEM_TYPESCR ACCT_ITEM_TYPECR");

		/* EXEC SQL DECLARE ACCT_ITEM_TYPECR CURSOR FOR ACCT_ITEM_TYPESCR; */ 

		CheckSqlError("Declare ACCT_ITEM_TYPECR");

		/* EXEC SQL OPEN ACCT_ITEM_TYPECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3721;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ACCT_ITEM_TYPECR;");


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

		/* EXEC SQL CLOSE ACCT_ITEM_TYPECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3736;
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
		/* EXEC SQL FETCH ACCT_ITEM_TYPECR INTO
			:pSource->aiAcctItemTypeID,
			:pSource->asAcctItemTypeKind,
			:pSource->asAcctItemName,
			:pSource->asStandardCode,
			:pSource->aiSummaryItemID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3751;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiAcctItemTypeID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asAcctItemTypeKind);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asAcctItemName);
  sqlstm.sqhstl[2] = (unsigned long )61;
  sqlstm.sqhsts[2] = (         int  )61;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asStandardCode);
  sqlstm.sqhstl[3] = (unsigned long )11;
  sqlstm.sqhsts[3] = (         int  )11;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiSummaryItemID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch ACCT_ITEM_TYPECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ACCT_ITEM_TYPECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3786;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ACCT_ITEM_TYPE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iAcctItemTypeID=		pSource->aiAcctItemTypeID[iCurPos];

		strcpy(p->sAcctItemTypeKind,	pSource->asAcctItemTypeKind[iCurPos]);
		strcpy(p->sAcctItemName,	pSource->asAcctItemName[iCurPos]);
		strcpy(p->sStandardCode,	pSource->asStandardCode[iCurPos]);

		p->iSummaryItemID=		pSource->aiSummaryItemID[iCurPos];

		AllTrim(p->sAcctItemTypeKind);
		AllTrim(p->sAcctItemName);
		AllTrim(p->sStandardCode);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表ACCT_ITEM_TYPE的链表释放函数**/
void DestroyAcctItemType(struct AcctItemTypeStruct *ptHead)
{
	struct AcctItemTypeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitAcctItemType(struct AcctItemTypeStruct **pptHead)
{
	int iCnt=0;
	static struct AcctItemTypeStruct *pTemp,*ptHead=NULL;
	struct AcctItemTypeStruct Temp;
	struct AcctItemTypeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyAcctItemType(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct AcctItemTypeStructIn));
	sprintf(TempIn.sTableName,"ACCT_ITEM_TYPE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetAcctItemTypeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct AcctItemTypeStruct*)
			malloc(sizeof(struct AcctItemTypeStruct)))==NULL){

			DestroyAcctItemType(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct AcctItemTypeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表ACCT_ITEM_TYPE记录数%d",iCnt);
	}

	WriteProcMsg("加载表ACCT_ITEM_TYPE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从SETT_RULE中用结构缓冲方式取数据*/
int EGetSettRuleToStruct(struct SettRuleStruct *p,
	struct SettRuleStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SETT_RULE_ID,\n\
				SEQ_NBR,\n\
				TICKET_TYPE_ID,\n\
				TARIFF_TYPE,\n\
				nvl(METHOD,'-1'),\n\
				OPP_CARRIER_ID,\n\
				ACCT_ITEM_TYPE_ID,\n\
				RATE,\n\
				SEC_PER_CNT,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				STATE,\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE-3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_RULESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3801;
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


		CheckSqlError(" PREPARE SETT_RULESCR SETT_RULECR");

		/* EXEC SQL DECLARE SETT_RULECR CURSOR FOR SETT_RULESCR; */ 

		CheckSqlError("Declare SETT_RULECR");

		/* EXEC SQL OPEN SETT_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3820;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_RULECR;");


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

		/* EXEC SQL CLOSE SETT_RULECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3835;
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
		/* EXEC SQL FETCH SETT_RULECR INTO
			:pSource->aiSettRuleID,
			:pSource->aiSeqNbr,
			:pSource->aiTicketTypeID,
			:pSource->asTariffType,
			:pSource->asMethod,
			:pSource->aiOppCarrierID,
			:pSource->aiAcctItemTypeID,
			:pSource->aiRate,
			:pSource->aiSecPerCnt,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3850;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiSettRuleID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asTariffType);
  sqlstm.sqhstl[3] = (unsigned long )3;
  sqlstm.sqhsts[3] = (         int  )3;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asMethod);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->aiOppCarrierID);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiAcctItemTypeID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->aiRate);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(int);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->aiSecPerCnt);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(int);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[11] = (unsigned long )4;
  sqlstm.sqhsts[11] = (         int  )4;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )15;
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


		CheckSqlError("Fetch SETT_RULECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_RULECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3921;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_RULE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iSettRuleID=		pSource->aiSettRuleID[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iTicketTypeID=	pSource->aiTicketTypeID[iCurPos];

		strcpy(p->sTariffType,	pSource->asTariffType[iCurPos]);
		strcpy(p->sMethod,	pSource->asMethod[iCurPos]);

		p->iOppCarrierID=	pSource->aiOppCarrierID[iCurPos];
		p->iAcctItemTypeID=	pSource->aiAcctItemTypeID[iCurPos];
		p->iRate=		pSource->aiRate[iCurPos];
		p->iSecPerCnt=		pSource->aiSecPerCnt[iCurPos];

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sStateDate,		pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,		pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sTariffType);
		AllTrim(p->sMethod);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表SETT_RULE的链表释放函数**/
void DestroySettRule(struct SettRuleStruct *ptHead)
{
	struct SettRuleStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettRule(struct SettRuleStruct **pptHead)
{
	int iCnt=0;
	static struct SettRuleStruct *pTemp,*ptHead=NULL;
	struct SettRuleStruct Temp;
	struct SettRuleStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettRule(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SettRuleStructIn));
	sprintf(TempIn.sTableName,"SETT_RULE");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettRuleToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettRuleStruct*)
			malloc(sizeof(struct SettRuleStruct)))==NULL){

			DestroySettRule(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettRuleStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_RULE记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_RULE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从SETT_CYCLE中用结构缓冲方式取数据*/
int EGetSettCycleToStruct(struct SettCycleStruct *p,
	struct SettCycleStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SETT_CYCLE_ID,\n\
				CYCLE_TYPE_ID,\n\
				MODULE,\n\
				nvl(SETT_CARRIER_ID,-1),\n\
				to_char(CYCLE_BEGIN_DATE,'yyyymmddhh24miss'),\n\
				to_char(CYCLE_END_DATE,'yyyymmddhh24miss'),\n\
				STATE,\n\
				MONTH,\n\
				nvl(REMARK,'-1')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_CYCLESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3936;
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


		CheckSqlError(" PREPARE SETT_CYCLESCR SETT_CYCLECR");

		/* EXEC SQL DECLARE SETT_CYCLECR CURSOR FOR SETT_CYCLESCR; */ 

		CheckSqlError("Declare SETT_CYCLECR");

		/* EXEC SQL OPEN SETT_CYCLECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3955;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_CYCLECR;");


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

		/* EXEC SQL CLOSE SETT_CYCLECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3970;
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
		/* EXEC SQL FETCH SETT_CYCLECR INTO
			:pSource->aiSettCycleID,
			:pSource->aiCycleTypeID,
			:pSource->asModule,
			:pSource->aiSettCarrierID,
			:pSource->asCycleBeginDate,
			:pSource->asCycleEndDate,
			:pSource->asState,
			:pSource->asMonth,
			:pSource->asRemark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3985;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiSettCycleID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiCycleTypeID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiSettCarrierID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCycleBeginDate);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCycleEndDate);
  sqlstm.sqhstl[5] = (unsigned long )15;
  sqlstm.sqhsts[5] = (         int  )15;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[6] = (unsigned long )4;
  sqlstm.sqhsts[6] = (         int  )4;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asMonth);
  sqlstm.sqhstl[7] = (unsigned long )3;
  sqlstm.sqhsts[7] = (         int  )3;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[8] = (unsigned long )61;
  sqlstm.sqhsts[8] = (         int  )61;
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


		CheckSqlError("Fetch SETT_CYCLECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_CYCLECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4036;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_CYCLE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iSettCycleID=		pSource->aiSettCycleID[iCurPos];
		p->iCycleTypeID=		pSource->aiCycleTypeID[iCurPos];

		strcpy(p->sModule,		pSource->asModule[iCurPos]);

		p->iSettCarrierID=		pSource->aiSettCarrierID[iCurPos];

		strcpy(p->sCycleBeginDate,	pSource->asCycleBeginDate[iCurPos]);
		strcpy(p->sCycleEndDate,	pSource->asCycleEndDate[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sMonth,		pSource->asMonth[iCurPos]);
		strcpy(p->sRemark,		pSource->asRemark[iCurPos]);

		AllTrim(p->sModule);
		AllTrim(p->sCycleBeginDate);
		AllTrim(p->sCycleEndDate);
		AllTrim(p->sState);
		AllTrim(p->sMonth);
		AllTrim(p->sRemark);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表SETT_CYCLE的链表释放函数**/
void DestroySettCycle(struct SettCycleStruct *ptHead)
{
	struct SettCycleStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettCycle(struct SettCycleStruct **pptHead)
{
	int iCnt=0;
	static struct SettCycleStruct *pTemp,*ptHead=NULL;
	struct SettCycleStruct Temp;
	struct SettCycleStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettCycle(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SettCycleStructIn));
	sprintf(TempIn.sTableName,"SETT_CYCLE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettCycleToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettCycleStruct*)
			malloc(sizeof(struct SettCycleStruct)))==NULL){

			DestroySettCycle(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettCycleStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_CYCLE记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_CYCLE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从LATN中用结构缓冲方式取数据*/
int EGetLatnToStruct(struct LatnStruct *p,
	struct LatnStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				LATN_ID,\n\
				NAME,\n\
				nvl(STANDARD_CODE,'-1'),\n\
				nvl(AREA_CODE,'-1')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE LATNSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4051;
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


		CheckSqlError(" PREPARE LATNSCR LATNCR");

		/* EXEC SQL DECLARE LATNCR CURSOR FOR LATNSCR; */ 

		CheckSqlError("Declare LATNCR");

		/* EXEC SQL OPEN LATNCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4070;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open LATNCR;");


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

		/* EXEC SQL CLOSE LATNCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4085;
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
		/* EXEC SQL FETCH LATNCR INTO
			:pSource->aiLatnID,
			:pSource->asName,
			:pSource->asStandardCode,
			:pSource->asAreaCode; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4100;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiLatnID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asName);
  sqlstm.sqhstl[1] = (unsigned long )21;
  sqlstm.sqhsts[1] = (         int  )21;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asStandardCode);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )6;
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


		CheckSqlError("Fetch LATNCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE LATNCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4131;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=LATN_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iLatnID=			pSource->aiLatnID[iCurPos];

		strcpy(p->sName,		pSource->asName[iCurPos]);
		strcpy(p->sStandardCode,	pSource->asStandardCode[iCurPos]);
		strcpy(p->sAreaCode,		pSource->asAreaCode[iCurPos]);

		AllTrim(p->sName);
		AllTrim(p->sStandardCode);
		AllTrim(p->sAreaCode);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表LATN的链表释放函数**/
void DestroyLatn(struct LatnStruct *ptHead)
{
	struct LatnStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitLatn(struct LatnStruct **pptHead)
{
	int iCnt=0;
	static struct LatnStruct *pTemp,*ptHead=NULL;
	struct LatnStruct Temp;
	struct LatnStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyLatn(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct LatnStructIn));
	sprintf(TempIn.sTableName,"LATN");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetLatnToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct LatnStruct*)
			malloc(sizeof(struct LatnStruct)))==NULL){

			DestroyLatn(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct LatnStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);

		if((++iCnt%10000)==0)
			WriteProcMsg("加载表LATN记录数%d",iCnt);
	}

	WriteProcMsg("加载表LATN完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从PUT_PARAM中用结构缓冲方式取数据*/
int EGetPutParamToStruct(struct PutParamStruct *p,
	struct PutParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				GROUP_ID,\n\
				OPP_PATH,\n\
				LOCAL_BKUP_PATH,\n\
				LOCAL_PATH,\n\
				IP,\n\
				USER_NAME,\n\
				PASSWD,\n\
				FILTER,\n\
				SEQ_OFF,\n\
				SEQ_LEN,\n\
				DELETE_TYPE,\n\
				nvl(CHK_DAYS,-1),\n\
				FILE_TYPE,\n\
				STATE,\n\
				APP_ID,\n\
				TACHE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PUT_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4146;
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


		CheckSqlError(" PREPARE PUT_PARAMSCR PUT_PARAMCR");

		/* EXEC SQL DECLARE PUT_PARAMCR CURSOR FOR PUT_PARAMSCR; */ 

		CheckSqlError("Declare PUT_PARAMCR");

		/* EXEC SQL OPEN PUT_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4165;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PUT_PARAMCR;");


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

		/* EXEC SQL CLOSE PUT_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4180;
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
		/* EXEC SQL FETCH PUT_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiGroupID,
			:pSource->asOppPath,
			:pSource->asLocalBkupPath,
			:pSource->asLocalPath,
			:pSource->asIp,
			:pSource->asUserName,
			:pSource->asPasswd,
			:pSource->asFilter,
			:pSource->aiSeqOff,
			:pSource->aiSeqLen,
			:pSource->asDeleteType,
			:pSource->aiChkDays,
			:pSource->asFileType,
			:pSource->asState,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4195;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asOppPath);
  sqlstm.sqhstl[2] = (unsigned long )81;
  sqlstm.sqhsts[2] = (         int  )81;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asLocalBkupPath);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )81;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asLocalPath);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asIp);
  sqlstm.sqhstl[5] = (unsigned long )17;
  sqlstm.sqhsts[5] = (         int  )17;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asUserName);
  sqlstm.sqhstl[6] = (unsigned long )21;
  sqlstm.sqhsts[6] = (         int  )21;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asPasswd);
  sqlstm.sqhstl[7] = (unsigned long )21;
  sqlstm.sqhsts[7] = (         int  )21;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[8] = (unsigned long )21;
  sqlstm.sqhsts[8] = (         int  )21;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiSeqOff);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiSeqLen);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asDeleteType);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiChkDays);
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
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[14] = (unsigned long )2;
  sqlstm.sqhsts[14] = (         int  )2;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[15] = (unsigned long )11;
  sqlstm.sqhsts[15] = (         int  )11;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch PUT_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PUT_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4278;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PUT_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);

		p->iGroupID=			pSource->aiGroupID[iCurPos];

		strcpy(p->sOppPath,		pSource->asOppPath[iCurPos]);
		strcpy(p->sLocalBkupPath,	pSource->asLocalBkupPath[iCurPos]);
		strcpy(p->sLocalPath,		pSource->asLocalPath[iCurPos]);
		strcpy(p->sIp,			pSource->asIp[iCurPos]);
		strcpy(p->sUserName,		pSource->asUserName[iCurPos]);
		strcpy(p->sPasswd,		pSource->asPasswd[iCurPos]);
		strcpy(p->sFilter,		pSource->asFilter[iCurPos]);

		p->iSeqOff=			pSource->aiSeqOff[iCurPos];
		p->iSeqOff=			pSource->aiSeqOff[iCurPos];
		
		strcpy(p->sDeleteType,		pSource->asDeleteType[iCurPos]);
		
		p->iChkDays=			pSource->aiChkDays[iCurPos];
	
		strcpy(p->sFileType,		pSource->asFileType[iCurPos]);
		strcpy(p->sState,		pSource->asState[iCurPos]);
		strcpy(p->sAppID,		pSource->asAppID[iCurPos]);
		
		p->iTacheID=			pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sOppPath);
		AllTrim(p->sLocalBkupPath);
		AllTrim(p->sLocalPath);
		AllTrim(p->sIp);
		AllTrim(p->sUserName);
		AllTrim(p->sPasswd);
		AllTrim(p->sFilter);
		AllTrim(p->sDeleteType);
		AllTrim(p->sFileType);
		AllTrim(p->sState);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表PUT_PARAM的链表释放函数**/
void DestroyPutParam(struct PutParamStruct *ptHead)
{
	struct PutParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitPutParam(struct PutParamStruct **pptHead)
{
	int iCnt=0;
	static struct PutParamStruct *pTemp,*ptHead=NULL;
	struct PutParamStruct Temp;
	struct PutParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyPutParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PutParamStructIn));
	sprintf(TempIn.sTableName,"PUT_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetPutParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct PutParamStruct*)
			malloc(sizeof(struct PutParamStruct)))==NULL){

			DestroyPutParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct PutParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表PUT_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表PUT_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从COMM_PARAM中用结构缓冲方式取数据*/
int EGetCommParamToStruct(struct CommParamStruct *p,
	struct CommParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				GROUP_ID,\n\
				MODULE,\n\
				SOURCE_PATH,\n\
				nvl(FILTER,'-1'),\n\
				BACKUP_PATH,\n\
				TARGET_PATH,\n\
				nvl(CMD,'-1'),\n\
				IN_TYPE,\n\
				OUT_TYPE,\n\
				nvl(APPEND_ARG,'-1')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE COMM_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4293;
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


		CheckSqlError(" PREPARE COMM_PARAMSCR COMM_PARAMCR");

		/* EXEC SQL DECLARE COMM_PARAMCR CURSOR FOR COMM_PARAMSCR; */ 

		CheckSqlError("Declare COMM_PARAMCR");

		/* EXEC SQL OPEN COMM_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4312;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open COMM_PARAMCR;");


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

		/* EXEC SQL CLOSE COMM_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4327;
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
		/* EXEC SQL FETCH COMM_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiGroupID,
			:pSource->asModule,
			:pSource->asSourcePath,
			:pSource->asFilter,
			:pSource->asBackupPath,
			:pSource->asTargetPath,
			:pSource->asCmd,
			:pSource->asInType,
			:pSource->asOutType,
			:pSource->asAppendArg; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4342;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
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
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asSourcePath);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )81;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[4] = (unsigned long )21;
  sqlstm.sqhsts[4] = (         int  )21;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asBackupPath);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asTargetPath);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCmd);
  sqlstm.sqhstl[7] = (unsigned long )81;
  sqlstm.sqhsts[7] = (         int  )81;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asInType);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )6;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asOutType);
  sqlstm.sqhstl[9] = (unsigned long )6;
  sqlstm.sqhsts[9] = (         int  )6;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asAppendArg);
  sqlstm.sqhstl[10] = (unsigned long )101;
  sqlstm.sqhsts[10] = (         int  )101;
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


		CheckSqlError("Fetch COMM_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE COMM_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4401;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=COMM_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sSourcePath,	pSource->asSourcePath[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sBackupPath,	pSource->asBackupPath[iCurPos]);
		strcpy(p->sTargetPath,	pSource->asTargetPath[iCurPos]);
		strcpy(p->sCmd,		pSource->asCmd[iCurPos]);
		strcpy(p->sInType,	pSource->asInType[iCurPos]);
		strcpy(p->sOutType,	pSource->asOutType[iCurPos]);
		strcpy(p->sAppendArg,	pSource->asAppendArg[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sModule);
		AllTrim(p->sSourcePath);
		AllTrim(p->sFilter);
		AllTrim(p->sBackupPath);
		AllTrim(p->sTargetPath);
		AllTrim(p->sCmd);
		AllTrim(p->sInType);
		AllTrim(p->sOutType);
		AllTrim(p->sAppendArg);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表COMM_PARAM的链表释放函数**/
void DestroyCommParam(struct CommParamStruct *ptHead)
{
	struct CommParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitCommParam(struct CommParamStruct **pptHead)
{
	int iCnt=0;
	static struct CommParamStruct *pTemp,*ptHead=NULL;
	struct CommParamStruct Temp;
	struct CommParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyCommParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct CommParamStructIn));
	sprintf(TempIn.sTableName,"COMM_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetCommParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct CommParamStruct*)
			malloc(sizeof(struct CommParamStruct)))==NULL){

			DestroyCommParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct CommParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表COMM_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表COMM_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从SETT_AREA中用结构缓冲方式取数据*/
int EGetSettAreaToStruct(struct SettAreaStruct *p,struct SettAreaStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SETT_AREA_ID,\n\
				LATN_ID,\n\
				COUNTY_FLAG,\n\
				NAME\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_AREASCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4416;
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


		CheckSqlError(" PREPARE SETT_AREASCR SETT_AREACR");

		/* EXEC SQL DECLARE SETT_AREACR CURSOR FOR SETT_AREASCR; */ 

		CheckSqlError("Declare SETT_AREACR");

		/* EXEC SQL OPEN SETT_AREACR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4435;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_AREACR;");


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

		/* EXEC SQL CLOSE SETT_AREACR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4450;
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
		/* EXEC SQL FETCH SETT_AREACR INTO
			:pSource->aiSettAreaID,
			:pSource->aiLatnID,
			:pSource->asCountyFlag,
			:pSource->asName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4465;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiSettAreaID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiLatnID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asCountyFlag);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )2;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asName);
  sqlstm.sqhstl[3] = (unsigned long )41;
  sqlstm.sqhsts[3] = (         int  )41;
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


		CheckSqlError("Fetch SETT_AREACR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_AREACR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4496;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_AREA_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iSettAreaID=		pSource->aiSettAreaID[iCurPos];
		p->iLatnID=		pSource->aiLatnID[iCurPos];

		strcpy(p->sCountyFlag,	pSource->asCountyFlag[iCurPos]);
		strcpy(p->sName,	pSource->asName[iCurPos]);

		AllTrim(p->sCountyFlag);
		AllTrim(p->sName);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表AREA的链表释放函数**/
void DestroySettArea(struct SettAreaStruct *ptHead)
{
	struct SettAreaStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettArea(struct SettAreaStruct **pptHead)
{
	int iCnt=0;
	static struct SettAreaStruct *pTemp,*ptHead=NULL;
	struct SettAreaStruct Temp;
	struct SettAreaStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettArea(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SettAreaStructIn));
	sprintf(TempIn.sTableName,"SETT_AREA");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettAreaToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettAreaStruct*)
			malloc(sizeof(struct SettAreaStruct)))==NULL){

			DestroySettArea(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettAreaStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_AREA记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_AREA完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从FLOW_APP中用结构缓冲方式取数据*/
int EGetFlowAppToStruct(struct FlowAppStruct *p,
	struct FlowAppStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				APP_ID,\n\
				APP_CODE,\n\
				APP_TYPE,\n\
				NAME\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE FLOW_APPSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4511;
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


		CheckSqlError(" PREPARE FLOW_APPSCR FLOW_APPCR");

		/* EXEC SQL DECLARE FLOW_APPCR CURSOR FOR FLOW_APPSCR; */ 

		CheckSqlError("Declare FLOW_APPCR");

		/* EXEC SQL OPEN FLOW_APPCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4530;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open FLOW_APPCR;");


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

		/* EXEC SQL CLOSE FLOW_APPCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4545;
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
		/* EXEC SQL FETCH FLOW_APPCR INTO
			:pSource->asAppID,
			:pSource->asAppCode,
			:pSource->asAppType,
			:pSource->asName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4560;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )11;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asAppCode);
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )9;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asAppType);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )2;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asName);
  sqlstm.sqhstl[3] = (unsigned long )21;
  sqlstm.sqhsts[3] = (         int  )21;
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


		CheckSqlError("Fetch FLOW_APPCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE FLOW_APPCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4591;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=FLOW_APP_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		strcpy(p->sAppCode,	pSource->asAppCode[iCurPos]);
		strcpy(p->sAppType,	pSource->asAppType[iCurPos]);
		strcpy(p->sName,	pSource->asName[iCurPos]);

		AllTrim(p->sAppID);
		AllTrim(p->sAppCode);
		AllTrim(p->sAppType);
		AllTrim(p->sName);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表FLOW_APP的链表释放函数**/
void DestroyFlowApp(struct FlowAppStruct *ptHead)
{
	struct FlowAppStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitFlowApp(struct FlowAppStruct **pptHead)
{
	int iCnt=0;
	static struct FlowAppStruct *pTemp,*ptHead=NULL;
	struct FlowAppStruct Temp;
	struct FlowAppStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyFlowApp(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct FlowAppStructIn));
	sprintf(TempIn.sTableName,"FLOW_APP");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetFlowAppToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct FlowAppStruct*)
			malloc(sizeof(struct FlowAppStruct)))==NULL){

			DestroyFlowApp(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct FlowAppStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表FLOW_APP记录数%d",iCnt);
	}

	WriteProcMsg("加载表FLOW_APP完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从FLOW_TASK中用结构缓冲方式取数据*/
int EGetFlowTaskToStruct(struct FlowTaskStruct *p,
	struct FlowTaskStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TASK_ID,\n\
				nvl(GRP_TASK_ID,0),\n\
				GRP_FLAG,\n\
				nvl(APP_ID,' '),\n\
				nvl(PARAM_ID,0),\n\
				NAME\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE FLOW_TASKSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4606;
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


		CheckSqlError(" PREPARE FLOW_TASKSCR FLOW_TASKCR");

		/* EXEC SQL DECLARE FLOW_TASKCR CURSOR FOR FLOW_TASKSCR; */ 

		CheckSqlError("Declare FLOW_TASKCR");

		/* EXEC SQL OPEN FLOW_TASKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4625;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open FLOW_TASKCR;");


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

		/* EXEC SQL CLOSE FLOW_TASKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4640;
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
		/* EXEC SQL FETCH FLOW_TASKCR INTO
			:pSource->aiTaskID,
			:pSource->aiGrpTaskID,
			:pSource->asGrpFlag,
			:pSource->asAppID,
			:pSource->aiParamID,
			:pSource->asName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4655;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTaskID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGrpTaskID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asGrpFlag);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )2;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[3] = (unsigned long )11;
  sqlstm.sqhsts[3] = (         int  )11;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asName);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )41;
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


		CheckSqlError("Fetch FLOW_TASKCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE FLOW_TASKCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4694;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=FLOW_TASK_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTaskID=		pSource->aiTaskID[iCurPos];
		p->iGrpTaskID=		pSource->aiGrpTaskID[iCurPos];

		strcpy(p->sGrpFlag,	pSource->asGrpFlag[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);

		p->iParamID=		pSource->aiParamID[iCurPos];

		strcpy(p->sName,	pSource->asName[iCurPos]);

		AllTrim(p->sGrpFlag);
		AllTrim(p->sAppID);
		AllTrim(p->sName);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表FLOW_TASK的链表释放函数**/
void DestroyFlowTask(struct FlowTaskStruct *ptHead)
{
	struct FlowTaskStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitFlowTask(struct FlowTaskStruct **pptHead)
{
	int iCnt=0;
	static struct FlowTaskStruct *pTemp,*ptHead=NULL;
	struct FlowTaskStruct Temp;
	struct FlowTaskStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyFlowTask(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct FlowTaskStructIn));
	sprintf(TempIn.sTableName,"FLOW_TASK");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetFlowTaskToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct FlowTaskStruct*)
			malloc(sizeof(struct FlowTaskStruct)))==NULL){

			DestroyFlowTask(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct FlowTaskStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表FLOW_TASK记录数%d",iCnt);
	}

	WriteProcMsg("加载表FLOW_TASK完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从FLOW_TACHE中用结构缓冲方式取数据*/
int EGetFlowTacheToStruct(struct FlowTacheStruct *p,
	struct FlowTacheStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				TACHE_ID,\n\
				nvl(PRE_TACHE_ID,0),\n\
				nvl(PRE_SEQ_NBR,0),\n\
				nvl(FLOW_ID,0),\n\
				nvl(TASK_ID,0),\n\
				nvl(APP_ID,' '),\n\
				nvl(PRE_INTF_TYPE,'0'),\n\
				nvl(DATA_DEAL_TYPE,'10')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE FLOW_TACHESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4709;
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


		CheckSqlError(" PREPARE FLOW_TACHESCR FLOW_TACHECR");

		/* EXEC SQL DECLARE FLOW_TACHECR CURSOR FOR FLOW_TACHESCR; */ 

		CheckSqlError("Declare FLOW_TACHECR");

		/* EXEC SQL OPEN FLOW_TACHECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4728;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open FLOW_TACHECR;");


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

		/* EXEC SQL CLOSE FLOW_TACHECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4743;
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
		/* EXEC SQL FETCH FLOW_TACHECR INTO
			:pSource->aiTacheID,
			:pSource->aiPreTacheID,
			:pSource->aiPreSeqNbr,
			:pSource->aiFlowID,
			:pSource->aiTaskID,
			:pSource->asAppID,
			:pSource->asPreIntfType,
			:pSource->asDataDealType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4758;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiPreTacheID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiPreSeqNbr);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiFlowID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiTaskID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )11;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asPreIntfType);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asDataDealType);
  sqlstm.sqhstl[7] = (unsigned long )3;
  sqlstm.sqhsts[7] = (         int  )3;
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


		CheckSqlError("Fetch FLOW_TACHECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE FLOW_TACHECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4805;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=FLOW_TACHE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iTacheID=		pSource->aiTacheID[iCurPos];
		p->iPreTacheID=		pSource->aiPreTacheID[iCurPos];
		p->iPreSeqNbr=		pSource->aiPreSeqNbr[iCurPos];
		p->iFlowID=		pSource->aiFlowID[iCurPos];
		p->iTaskID=		pSource->aiTaskID[iCurPos];

		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		strcpy(p->sPreIntfType,	pSource->asPreIntfType[iCurPos]);
		strcpy(p->sDataDealType,pSource->asDataDealType[iCurPos]);

		AllTrim(p->sAppID);
		AllTrim(p->sPreIntfType);
		AllTrim(p->sDataDealType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表FLOW_TACHE的链表释放函数**/
void DestroyFlowTache(struct FlowTacheStruct *ptHead)
{
	struct FlowTacheStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitFlowTache(struct FlowTacheStruct **pptHead)
{
	int iCnt=0;
	static struct FlowTacheStruct *pTemp,*ptHead=NULL;
	struct FlowTacheStruct Temp;
	struct FlowTacheStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyFlowTache(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct FlowTacheStructIn));
	sprintf(TempIn.sTableName,"FLOW_TACHE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetFlowTacheToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct FlowTacheStruct*)
			malloc(sizeof(struct FlowTacheStruct)))==NULL){

			DestroyFlowTache(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct FlowTacheStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表FLOW_TACHE记录数%d",iCnt);
	}

	WriteProcMsg("加载表FLOW_TACHE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从TASK_PARAM中用结构缓冲方式取数据*/
int EGetTaskParamToStruct(struct TaskParamStruct *p,
	struct TaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				PARAM_ID,\n\
				APP_ID,\n\
				nvl(IN_PATH,' '),\n\
				nvl(BAK_PATH,' '),\n\
				nvl(OUT_PATH,' '),\n\
				nvl(IN_FILTER,' '),\n\
				nvl(OUT_FILTER,' '),\n\
				nvl(IN_TYPE,' '),\n\
				nvl(OUT_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4820;
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


		CheckSqlError(" PREPARE TASK_PARAMSCR TASK_PARAMCR");

		/* EXEC SQL DECLARE TASK_PARAMCR CURSOR FOR TASK_PARAMSCR; */ 

		CheckSqlError("Declare TASK_PARAMCR");

		/* EXEC SQL OPEN TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4839;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4854;
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
		/* EXEC SQL FETCH TASK_PARAMCR INTO
			:pSource->aiParamID,
			:pSource->asAppID,
			:pSource->asInPath,
			:pSource->asBakPath,
			:pSource->asOutPath,
			:pSource->asInFilter,
			:pSource->asOutFilter,
			:pSource->asInType,
			:pSource->asOutType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4869;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asInPath);
  sqlstm.sqhstl[2] = (unsigned long )61;
  sqlstm.sqhsts[2] = (         int  )61;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asBakPath);
  sqlstm.sqhstl[3] = (unsigned long )61;
  sqlstm.sqhsts[3] = (         int  )61;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOutPath);
  sqlstm.sqhstl[4] = (unsigned long )61;
  sqlstm.sqhsts[4] = (         int  )61;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asInFilter);
  sqlstm.sqhstl[5] = (unsigned long )61;
  sqlstm.sqhsts[5] = (         int  )61;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asOutFilter);
  sqlstm.sqhstl[6] = (unsigned long )61;
  sqlstm.sqhsts[6] = (         int  )61;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asInType);
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )6;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asOutType);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )6;
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


		CheckSqlError("Fetch TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4920;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iParamID=		pSource->aiParamID[iCurPos];

		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		strcpy(p->sInPath,	pSource->asInPath[iCurPos]);
		strcpy(p->sBakPath,	pSource->asBakPath[iCurPos]);
		strcpy(p->sOutPath,	pSource->asOutPath[iCurPos]);
		strcpy(p->sInFilter,	pSource->asInFilter[iCurPos]);
		strcpy(p->sOutFilter,	pSource->asOutFilter[iCurPos]);
		strcpy(p->sInType,	pSource->asInType[iCurPos]);
		strcpy(p->sOutType,	pSource->asOutType[iCurPos]);

		AllTrim(p->sAppID);
		AllTrim(p->sInPath);
		AllTrim(p->sBakPath);
		AllTrim(p->sOutPath);
		AllTrim(p->sInFilter);
		AllTrim(p->sOutFilter);
		AllTrim(p->sInType);
		AllTrim(p->sOutType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TASK_PARAM的链表释放函数**/
void DestroyTaskParam(struct TaskParamStruct *ptHead)
{
	struct TaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTaskParam(struct TaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct TaskParamStruct *pTemp,*ptHead=NULL;
	struct TaskParamStruct Temp;
	struct TaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct TaskParamStructIn));
	sprintf(TempIn.sTableName,"TASK_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TaskParamStruct*)
			malloc(sizeof(struct TaskParamStruct)))==NULL){

			DestroyTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从ACCT_TASK_PARAM中用结构缓冲方式取数据*/
int EGetAcctTaskParamToStruct(struct AcctTaskParamStruct *p,
	struct AcctTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				GROUP_ID,\n\
				OPER_TYPE,\n\
				DATE_RULE,\n\
				BELONG_CODE,\n\
				MODULE,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ACCT_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4935;
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


		CheckSqlError(" PREPARE ACCT_TASK_PARAMSCR ACCT_TASK_PARAMCR");

		/* EXEC SQL DECLARE ACCT_TASK_PARAMCR CURSOR FOR ACCT_TASK_PARAMSCR; */ 

		CheckSqlError("Declare ACCT_TASK_PARAMCR");

		/* EXEC SQL OPEN ACCT_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4954;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ACCT_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE ACCT_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4969;
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
		/* EXEC SQL FETCH ACCT_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->aiGroupID,
			:pSource->asOperType,
			:pSource->asDateRule,
			:pSource->asBelongCode,
			:pSource->asModule,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )4984;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOperType);
  sqlstm.sqhstl[4] = (unsigned long )4;
  sqlstm.sqhsts[4] = (         int  )4;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asDateRule);
  sqlstm.sqhstl[5] = (unsigned long )13;
  sqlstm.sqhsts[5] = (         int  )13;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asBelongCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[10] = (unsigned long )4;
  sqlstm.sqhsts[10] = (         int  )4;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
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


		CheckSqlError("Fetch ACCT_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ACCT_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5051;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ACCT_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sOperType,	pSource->asOperType[iCurPos]);
		strcpy(p->sDateRule,	pSource->asDateRule[iCurPos]);
		strcpy(p->sBelongCode,	pSource->asBelongCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sOperType);
		AllTrim(p->sDateRule);
		AllTrim(p->sBelongCode);
		AllTrim(p->sModule);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表ACCT_TASK_PARAM的链表释放函数**/
void DestroyAcctTaskParam(struct AcctTaskParamStruct *ptHead)
{
	struct AcctTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitAcctTaskParam(struct AcctTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct AcctTaskParamStruct *pTemp,*ptHead=NULL;
	struct AcctTaskParamStruct Temp;
	struct AcctTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyAcctTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct AcctTaskParamStructIn));
	sprintf(TempIn.sTableName,"ACCT_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetAcctTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct AcctTaskParamStruct*)
			malloc(sizeof(struct AcctTaskParamStruct)))==NULL){

			DestroyAcctTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct AcctTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表ACCT_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表ACCT_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从BILL_TASK_PARAM中用结构缓冲方式取数据*/
int EGetBillTaskParamToStruct(struct BillTaskParamStruct *p,
	struct BillTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				APP_CODE,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				GROUP_ID,\n\
				USER_TYPE,\n\
				TEMPLATE_ID,\n\
				SPLIT_STR,\n\
				BELONG_CODE,\n\
				MODULE,\n\
				nvl(SPLIT,' '),\n\
				nvl(START_POS,0),\n\
				nvl(KEY_LEN,0),\n\
				nvl(BATCH_FLAG,'0'),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE BILL_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5066;
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


		CheckSqlError(" PREPARE BILL_TASK_PARAMSCR BILL_TASK_PARAMCR");

		/* EXEC SQL DECLARE BILL_TASK_PARAMCR CURSOR FOR BILL_TASK_PARAMSCR; */ 

		CheckSqlError("Declare BILL_TASK_PARAMCR");

		/* EXEC SQL OPEN BILL_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5085;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open BILL_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE BILL_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5100;
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
		/* EXEC SQL FETCH BILL_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->asAppCode,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->aiGroupID,
			:pSource->asUserType,
			:pSource->asTemplateID,
			:pSource->asSplitStr,
			:pSource->asBelongCode,
			:pSource->asModule,
			:pSource->asSplit,
			:pSource->aiStartPos,
			:pSource->aiKeyLen,
			:pSource->asBatchFlag,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )5115;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asAppCode);
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )9;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asUserType);
  sqlstm.sqhstl[5] = (unsigned long )41;
  sqlstm.sqhsts[5] = (         int  )41;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asTemplateID);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSplitStr);
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )11;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asBelongCode);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )6;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asSplit);
  sqlstm.sqhstl[10] = (unsigned long )10;
  sqlstm.sqhsts[10] = (         int  )10;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiStartPos);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiKeyLen);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asBatchFlag);
  sqlstm.sqhstl[13] = (unsigned long )2;
  sqlstm.sqhsts[13] = (         int  )2;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[15] = (unsigned long )15;
  sqlstm.sqhsts[15] = (         int  )15;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[16] = (unsigned long )4;
  sqlstm.sqhsts[16] = (         int  )4;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[17] = (unsigned long )15;
  sqlstm.sqhsts[17] = (         int  )15;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[18] = (unsigned long )15;
  sqlstm.sqhsts[18] = (         int  )15;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
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



		CheckSqlError("Fetch BILL_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE BILL_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5206;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=BILL_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);
		strcpy(p->sAppCode,	pSource->asAppCode[iCurPos]);

		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sUserType,	pSource->asUserType[iCurPos]);
		strcpy(p->sTemplateID,	pSource->asTemplateID[iCurPos]);
		strcpy(p->sSplitStr,	pSource->asSplitStr[iCurPos]);
		strcpy(p->sBelongCode,	pSource->asBelongCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sSplit,	pSource->asSplit[iCurPos]);
		
		p->iStartPos=		pSource->aiStartPos[iCurPos];
		p->iKeyLen=		pSource->aiKeyLen[iCurPos];
		
		strcpy(p->sBatchFlag,	pSource->asBatchFlag[iCurPos]);

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sAppCode);
		AllTrim(p->sUserType);
		AllTrim(p->sTemplateID);
		AllTrim(p->sSplitStr);
		AllTrim(p->sBelongCode);
		AllTrim(p->sModule);
		AllTrim(p->sSplit);
		
		AllTrim(p->sBatchFlag);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表BILL_TASK_PARAM的链表释放函数**/
void DestroyBillTaskParam(struct BillTaskParamStruct *ptHead)
{
	struct BillTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitBillTaskParam(struct BillTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct BillTaskParamStruct *pTemp,*ptHead=NULL;
	struct BillTaskParamStruct Temp;
	struct BillTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyBillTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct BillTaskParamStructIn));
	sprintf(TempIn.sTableName,"BILL_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetBillTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct BillTaskParamStruct*)
			malloc(sizeof(struct BillTaskParamStruct)))==NULL){

			DestroyBillTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct BillTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表BILL_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表BILL_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从INST_TASK_PARAM中用结构缓冲方式取数据*/
int EGetInstTaskParamToStruct(struct InstTaskParamStruct *p,
	struct InstTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				GROUP_ID,\n\
				OPER_TYPE,\n\
				DATE_RULE,\n\
				BELONG_CODE,\n\
				MODULE,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE INST_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5221;
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


		CheckSqlError(" PREPARE INST_TASK_PARAMSCR INST_TASK_PARAMCR");

		/* EXEC SQL DECLARE INST_TASK_PARAMCR CURSOR FOR INST_TASK_PARAMSCR; */ 

		CheckSqlError("Declare INST_TASK_PARAMCR");

		/* EXEC SQL OPEN INST_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5240;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open INST_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE INST_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5255;
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
		/* EXEC SQL FETCH INST_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->aiGroupID,
			:pSource->asOperType,
			:pSource->asDateRule,
			:pSource->asBelongCode,
			:pSource->asModule,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )5270;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOperType);
  sqlstm.sqhstl[4] = (unsigned long )4;
  sqlstm.sqhsts[4] = (         int  )4;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asDateRule);
  sqlstm.sqhstl[5] = (unsigned long )13;
  sqlstm.sqhsts[5] = (         int  )13;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asBelongCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[10] = (unsigned long )4;
  sqlstm.sqhsts[10] = (         int  )4;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
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


		CheckSqlError("Fetch INST_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE INST_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5337;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=INST_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sOperType,	pSource->asOperType[iCurPos]);
		strcpy(p->sDateRule,	pSource->asDateRule[iCurPos]);
		strcpy(p->sBelongCode,	pSource->asBelongCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sOperType);
		AllTrim(p->sDateRule);
		AllTrim(p->sBelongCode);
		AllTrim(p->sModule);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表INST_TASK_PARAM的链表释放函数**/
void DestroyInstTaskParam(struct InstTaskParamStruct *ptHead)
{
	struct InstTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitInstTaskParam(struct InstTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct InstTaskParamStruct *pTemp,*ptHead=NULL;
	struct InstTaskParamStruct Temp;
	struct InstTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyInstTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct InstTaskParamStructIn));
	sprintf(TempIn.sTableName,"INST_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetInstTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct InstTaskParamStruct*)
			malloc(sizeof(struct InstTaskParamStruct)))==NULL){

			DestroyInstTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct InstTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表INST_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表INST_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从INTF_TASK_PARAM中用结构缓冲方式取数据*/
int EGetIntfTaskParamToStruct(struct IntfTaskParamStruct *p,
	struct IntfTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				GROUP_ID,\n\
				DELAY,\n\
				nvl(CITY_CODE,' '),\n\
				FILTER,\n\
				FILE_TYPE,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE INTF_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5352;
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


		CheckSqlError(" PREPARE INTF_TASK_PARAMSCR INTF_TASK_PARAMCR");

		/* EXEC SQL DECLARE INTF_TASK_PARAMCR CURSOR FOR INTF_TASK_PARAMSCR; */ 

		CheckSqlError("Declare INTF_TASK_PARAMCR");

		/* EXEC SQL OPEN INTF_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5371;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open INTF_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE INTF_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5386;
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
		/* EXEC SQL FETCH INTF_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->aiGroupID,
			:pSource->aiDelay,
			:pSource->asCityCode,
			:pSource->asFilter,
			:pSource->asFileType,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )5401;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->aiDelay);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(int);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCityCode);
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )4;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[6] = (unsigned long )61;
  sqlstm.sqhsts[6] = (         int  )61;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )6;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[9] = (unsigned long )15;
  sqlstm.sqhsts[9] = (         int  )15;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[10] = (unsigned long )4;
  sqlstm.sqhsts[10] = (         int  )4;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
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


		CheckSqlError("Fetch INTF_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE INTF_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5468;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=INTF_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		p->iDelay=		pSource->aiDelay[iCurPos];

		strcpy(p->sCityCode,	pSource->asCityCode[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sFileType,	pSource->asFileType[iCurPos]);
		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sCityCode);
		AllTrim(p->sFilter);
		AllTrim(p->sFileType);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表INTF_TASK_PARAM的链表释放函数**/
void DestroyIntfTaskParam(struct IntfTaskParamStruct *ptHead)
{
	struct IntfTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitIntfTaskParam(struct IntfTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct IntfTaskParamStruct *pTemp,*ptHead=NULL;
	struct IntfTaskParamStruct Temp;
	struct IntfTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyIntfTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct IntfTaskParamStructIn));
	sprintf(TempIn.sTableName,"INTF_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetIntfTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct IntfTaskParamStruct*)
			malloc(sizeof(struct IntfTaskParamStruct)))==NULL){

			DestroyIntfTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct IntfTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表INTF_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表INTF_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}


/*批量数据动态从PICK_TASK_PARAM中用结构缓冲方式取数据*/
int EGetPickTaskParamToStruct(struct PickTaskParamStruct *p,
	struct PickTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				GROUP_ID,\n\
				OPP_PATH,\n\
				OPP_BKUP_PATH,\n\
				IP,\n\
				USER_NAME,\n\
				PASSWD,\n\
				FILTER,\n\
				SEQ_OFF,\n\
				SEQ_LEN,\n\
				DELETE_TYPE,\n\
				CHK_DAYS,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PICK_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5483;
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


		CheckSqlError(" PREPARE PICK_TASK_PARAMSCR PICK_TASK_PARAMCR");

		/* EXEC SQL DECLARE PICK_TASK_PARAMCR CURSOR FOR PICK_TASK_PARAMSCR; */ 

		CheckSqlError("Declare PICK_TASK_PARAMCR");

		/* EXEC SQL OPEN PICK_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5502;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PICK_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE PICK_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5517;
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
		/* EXEC SQL FETCH PICK_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->aiGroupID,
			:pSource->asOppPath,
			:pSource->asOppBkupPath,
			:pSource->asIp,
			:pSource->asUserName,
			:pSource->asPasswd,
			:pSource->asFilter,
			:pSource->aiSeqOff,
			:pSource->aiSeqLen,
			:pSource->asDeleteType,
			:pSource->aiChkDays,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )5532;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOppPath);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asOppBkupPath);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asIp);
  sqlstm.sqhstl[6] = (unsigned long )17;
  sqlstm.sqhsts[6] = (         int  )17;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asUserName);
  sqlstm.sqhstl[7] = (unsigned long )21;
  sqlstm.sqhsts[7] = (         int  )21;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asPasswd);
  sqlstm.sqhstl[8] = (unsigned long )21;
  sqlstm.sqhsts[8] = (         int  )21;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[9] = (unsigned long )21;
  sqlstm.sqhsts[9] = (         int  )21;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiSeqOff);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiSeqLen);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asDeleteType);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->aiChkDays);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[15] = (unsigned long )15;
  sqlstm.sqhsts[15] = (         int  )15;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[16] = (unsigned long )4;
  sqlstm.sqhsts[16] = (         int  )4;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[17] = (unsigned long )15;
  sqlstm.sqhsts[17] = (         int  )15;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[18] = (unsigned long )15;
  sqlstm.sqhsts[18] = (         int  )15;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
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


			
		CheckSqlError("Fetch PICK_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PICK_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5623;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PICK_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/

		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sOppPath,	pSource->asOppPath[iCurPos]);
		strcpy(p->sOppBkupPath,	pSource->asOppBkupPath[iCurPos]);
		strcpy(p->sIp,		pSource->asIp[iCurPos]);
		strcpy(p->sUserName,	pSource->asUserName[iCurPos]);
		strcpy(p->sPasswd,	pSource->asPasswd[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);

		p->iSeqOff=		pSource->aiSeqOff[iCurPos];
		p->iSeqLen=		pSource->aiSeqLen[iCurPos];

		strcpy(p->sDeleteType,	pSource->asDeleteType[iCurPos]);
		
		p->iChkDays=		pSource->aiChkDays[iCurPos];

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);


		AllTrim(p->sSourceID);
		AllTrim(p->sOppPath);
		AllTrim(p->sOppBkupPath);
		AllTrim(p->sIp);
		AllTrim(p->sUserName);
		AllTrim(p->sPasswd);
		AllTrim(p->sFilter);
		AllTrim(p->sDeleteType);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表PICK_TASK_PARAM的链表释放函数**/
void DestroyPickTaskParam(struct PickTaskParamStruct *ptHead)
{
	struct PickTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitPickTaskParam(struct PickTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct PickTaskParamStruct *pTemp,*ptHead=NULL;
	struct PickTaskParamStruct Temp;
	struct PickTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyPickTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PickTaskParamStructIn));
	sprintf(TempIn.sTableName,"PICK_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetPickTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct PickTaskParamStruct*)
			malloc(sizeof(struct PickTaskParamStruct)))==NULL){

			DestroyPickTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct PickTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表PICK_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表PICK_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从PREP_TASK_PARAM中用结构缓冲方式取数据*/
int EGetPrepTaskParamToStruct(struct PrepTaskParamStruct *p,
	struct PrepTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				GROUP_ID,\n\
				MSC,\n\
				AREA_CODE,\n\
				EXPR_FILE,\n\
				MODULE,\n\
				nvl(SPLIT,'C'),\n\
				nvl(START_POS,0),\n\
				nvl(KEY_LEN,0),\n\
				nvl(CHK_MOD,'CHK'),\n\
				nvl(USER_TYPE,'G'),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PREP_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5638;
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


		CheckSqlError(" PREPARE PREP_TASK_PARAMSCR PREP_TASK_PARAMCR");

		/* EXEC SQL DECLARE PREP_TASK_PARAMCR CURSOR FOR PREP_TASK_PARAMSCR; */ 

		CheckSqlError("Declare PREP_TASK_PARAMCR");

		/* EXEC SQL OPEN PREP_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5657;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PREP_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE PREP_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5672;
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
		/* EXEC SQL FETCH PREP_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->aiGroupID,
			:pSource->asMsc,
			:pSource->asAreaCode,
			:pSource->asExprFile,
			:pSource->asModule,
			:pSource->asSplit,
			:pSource->aiStartPos,
			:pSource->aiKeyLen,
			:pSource->asChkMod,
			:pSource->asUserType,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )5687;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asMsc);
  sqlstm.sqhstl[4] = (unsigned long )16;
  sqlstm.sqhsts[4] = (         int  )16;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )6;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asExprFile);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSplit);
  sqlstm.sqhstl[8] = (unsigned long )11;
  sqlstm.sqhsts[8] = (         int  )11;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiStartPos);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiKeyLen);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asChkMod);
  sqlstm.sqhstl[11] = (unsigned long )4;
  sqlstm.sqhsts[11] = (         int  )4;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asUserType);
  sqlstm.sqhstl[12] = (unsigned long )2;
  sqlstm.sqhsts[12] = (         int  )2;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )15;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[15] = (unsigned long )4;
  sqlstm.sqhsts[15] = (         int  )4;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[16] = (unsigned long )15;
  sqlstm.sqhsts[16] = (         int  )15;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[17] = (unsigned long )15;
  sqlstm.sqhsts[17] = (         int  )15;
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


		CheckSqlError("Fetch PREP_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PREP_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5774;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PREP_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iParamID=		pSource->aiParamID[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sMsc,		pSource->asMsc[iCurPos]);
		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);
		strcpy(p->sExprFile,	pSource->asExprFile[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		
		strcpy(p->sSplit,	pSource->asSplit[iCurPos]);

		p->iStartPos=		pSource->aiStartPos[iCurPos];
		p->iKeyLen=		pSource->aiKeyLen[iCurPos];
		strcpy(p->sChkMod,	pSource->asChkMod[iCurPos]);
		strcpy(p->sUserType,	pSource->asUserType[iCurPos]);

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sSourceID);

		AllTrim(p->sMsc);
		AllTrim(p->sAreaCode);
		AllTrim(p->sExprFile);
		AllTrim(p->sModule);
		AllTrim(p->sChkMod);
		AllTrim(p->sUserType);
		AllTrim(p->sSplit);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表PREP_TASK_PARAM的链表释放函数**/
void DestroyPrepTaskParam(struct PrepTaskParamStruct *ptHead)
{
	struct PrepTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitPrepTaskParam(struct PrepTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct PrepTaskParamStruct *pTemp,*ptHead=NULL;
	struct PrepTaskParamStruct Temp;
	struct PrepTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyPrepTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PrepTaskParamStructIn));
	sprintf(TempIn.sTableName,"PREP_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetPrepTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct PrepTaskParamStruct*)
			malloc(sizeof(struct PrepTaskParamStruct)))==NULL){

			DestroyPrepTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct PrepTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表PREP_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表PREP_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}


/*批量数据动态从PUT_TASK_PARAM中用结构缓冲方式取数据*/
int EGetPutTaskParamToStruct(struct PutTaskParamStruct *p,
	struct PutTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				GROUP_ID,\n\
				OPP_PATH,\n\
				IP,\n\
				USER_NAME,\n\
				PASSWD,\n\
				FILTER,\n\
				SEQ_OFF,\n\
				SEQ_LEN,\n\
				DELETE_TYPE,\n\
				nvl(CHK_DAYS,-1),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE PUT_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5789;
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


		CheckSqlError(" PREPARE PUT_TASK_PARAMSCR PUT_TASK_PARAMCR");

		/* EXEC SQL DECLARE PUT_TASK_PARAMCR CURSOR FOR PUT_TASK_PARAMSCR; */ 

		CheckSqlError("Declare PUT_TASK_PARAMCR");

		/* EXEC SQL OPEN PUT_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5808;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open PUT_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE PUT_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5823;
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
		/* EXEC SQL FETCH PUT_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->aiGroupID,
			:pSource->asOppPath,
			:pSource->asIp,
			:pSource->asUserName,
			:pSource->asPasswd,
			:pSource->asFilter,
			:pSource->aiSeqOff,
			:pSource->aiSeqLen,
			:pSource->asDeleteType,
			:pSource->aiChkDays,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )5838;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOppPath);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asIp);
  sqlstm.sqhstl[5] = (unsigned long )17;
  sqlstm.sqhsts[5] = (         int  )17;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asUserName);
  sqlstm.sqhstl[6] = (unsigned long )21;
  sqlstm.sqhsts[6] = (         int  )21;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asPasswd);
  sqlstm.sqhstl[7] = (unsigned long )21;
  sqlstm.sqhsts[7] = (         int  )21;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[8] = (unsigned long )21;
  sqlstm.sqhsts[8] = (         int  )21;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->aiSeqOff);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(int);
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiSeqLen);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asDeleteType);
  sqlstm.sqhstl[11] = (unsigned long )2;
  sqlstm.sqhsts[11] = (         int  )2;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiChkDays);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )15;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[15] = (unsigned long )4;
  sqlstm.sqhsts[15] = (         int  )4;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[16] = (unsigned long )15;
  sqlstm.sqhsts[16] = (         int  )15;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[17] = (unsigned long )15;
  sqlstm.sqhsts[17] = (         int  )15;
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


		CheckSqlError("Fetch PUT_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE PUT_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5925;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=PUT_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sOppPath,	pSource->asOppPath[iCurPos]);
		strcpy(p->sIp,		pSource->asIp[iCurPos]);
		strcpy(p->sUserName,	pSource->asUserName[iCurPos]);
		strcpy(p->sPasswd,	pSource->asPasswd[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);

		p->iSeqOff=		pSource->aiSeqOff[iCurPos];
		p->iSeqLen=		pSource->aiSeqLen[iCurPos];
		
		strcpy(p->sDeleteType,	pSource->asDeleteType[iCurPos]);
		
		p->iChkDays=		pSource->aiChkDays[iCurPos];
		
		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sOppPath);
		AllTrim(p->sIp);
		AllTrim(p->sUserName);
		AllTrim(p->sPasswd);
		AllTrim(p->sFilter);
		AllTrim(p->sDeleteType);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表PUT_TASK_PARAM的链表释放函数**/
void DestroyPutTaskParam(struct PutTaskParamStruct *ptHead)
{
	struct PutTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitPutTaskParam(struct PutTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct PutTaskParamStruct *pTemp,*ptHead=NULL;
	struct PutTaskParamStruct Temp;
	struct PutTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyPutTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct PutTaskParamStructIn));
	sprintf(TempIn.sTableName,"PUT_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetPutTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct PutTaskParamStruct*)
			malloc(sizeof(struct PutTaskParamStruct)))==NULL){

			DestroyPutTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct PutTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表PUT_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表PUT_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从RCYL_TASK_PARAM中用结构缓冲方式取数据*/
int EGetRcylTaskParamToStruct(struct RcylTaskParamStruct *p,
	struct RcylTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				TASK_SEQ_NBR,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				TABLE_NAME,\n\
				CONDITION,\n\
				EXPR_FILE,\n\
				TEMPLATE_ID,\n\
				SPLIT_STR,\n\
				VISIT_CODE,\n\
				MODULE,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE RCYL_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5940;
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


		CheckSqlError(" PREPARE RCYL_TASK_PARAMSCR RCYL_TASK_PARAMCR");

		/* EXEC SQL DECLARE RCYL_TASK_PARAMCR CURSOR FOR RCYL_TASK_PARAMSCR; */ 

		CheckSqlError("Declare RCYL_TASK_PARAMCR");

		/* EXEC SQL OPEN RCYL_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5959;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open RCYL_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE RCYL_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5974;
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
		/* EXEC SQL FETCH RCYL_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiTaskSeqNbr,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->asTableName,
			:pSource->asCondition,
			:pSource->asExprFile,
			:pSource->asTemplateID,
			:pSource->asSplitStr,
			:pSource->asVisitCode,
			:pSource->asModule,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )5989;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiTaskSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[4] = (unsigned long )31;
  sqlstm.sqhsts[4] = (         int  )31;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCondition);
  sqlstm.sqhstl[5] = (unsigned long )61;
  sqlstm.sqhsts[5] = (         int  )61;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asExprFile);
  sqlstm.sqhstl[6] = (unsigned long )41;
  sqlstm.sqhsts[6] = (         int  )41;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asTemplateID);
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )11;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSplitStr);
  sqlstm.sqhstl[8] = (unsigned long )11;
  sqlstm.sqhsts[8] = (         int  )11;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asVisitCode);
  sqlstm.sqhstl[9] = (unsigned long )10;
  sqlstm.sqhsts[9] = (         int  )10;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[10] = (unsigned long )4;
  sqlstm.sqhsts[10] = (         int  )4;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[13] = (unsigned long )4;
  sqlstm.sqhsts[13] = (         int  )4;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[15] = (unsigned long )15;
  sqlstm.sqhsts[15] = (         int  )15;
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


		CheckSqlError("Fetch RCYL_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE RCYL_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )6068;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=RCYL_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iTaskSeqNbr=		pSource->aiTaskSeqNbr[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];

		strcpy(p->sTableName,	pSource->asTableName[iCurPos]);
		strcpy(p->sCondition,	pSource->asCondition[iCurPos]);
		strcpy(p->sExprFile,	pSource->asExprFile[iCurPos]);
		strcpy(p->sTemplateID,	pSource->asTemplateID[iCurPos]);
		strcpy(p->sSplitStr,	pSource->asSplitStr[iCurPos]);
		strcpy(p->sVisitCode,	pSource->asVisitCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sTableName);
		AllTrim(p->sCondition);
		AllTrim(p->sExprFile);
		AllTrim(p->sTemplateID);
		AllTrim(p->sSplitStr);
		AllTrim(p->sVisitCode);
		AllTrim(p->sModule);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表RCYL_TASK_PARAM的链表释放函数**/
void DestroyRcylTaskParam(struct RcylTaskParamStruct *ptHead)
{
	struct RcylTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitRcylTaskParam(struct RcylTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct RcylTaskParamStruct *pTemp,*ptHead=NULL;
	struct RcylTaskParamStruct Temp;
	struct RcylTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyRcylTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct RcylTaskParamStructIn));
	sprintf(TempIn.sTableName,"RCYL_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetRcylTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct RcylTaskParamStruct*)
			malloc(sizeof(struct RcylTaskParamStruct)))==NULL){

			DestroyRcylTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct RcylTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表RCYL_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表RCYL_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从ROLL_TASK_PARAM中用结构缓冲方式取数据*/
int EGetRollTaskParamToStruct(struct RollTaskParamStruct *p,
	struct RollTaskParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				TASK_SEQ_NBR,\n\
				SEQ_NBR,\n\
				PARAM_ID,\n\
				nvl(TABLE_NAME,' '),\n\
				nvl(TEMPLATE_ID,' '),\n\
				nvl(CONDITION,' '),\n\
				nvl(USER_TYPE,' '),\n\
				nvl(SPLIT_TYPE,' '),\n\
				nvl(VISIT_CODE,' '),\n\
				nvl(MODULE,' '),\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ROLL_TASK_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6083;
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


		CheckSqlError(" PREPARE ROLL_TASK_PARAMSCR ROLL_TASK_PARAMCR");

		/* EXEC SQL DECLARE ROLL_TASK_PARAMCR CURSOR FOR ROLL_TASK_PARAMSCR; */ 

		CheckSqlError("Declare ROLL_TASK_PARAMCR");

		/* EXEC SQL OPEN ROLL_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6102;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ROLL_TASK_PARAMCR;");


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

		/* EXEC SQL CLOSE ROLL_TASK_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6117;
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
		/* EXEC SQL FETCH ROLL_TASK_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiTaskSeqNbr,
			:pSource->aiSeqNbr,
			:pSource->aiParamID,
			:pSource->asTableName,
			:pSource->asTemplateID,
			:pSource->asCondition,
			:pSource->asUserType,
			:pSource->asSplitType,
			:pSource->asVisitCode,
			:pSource->asModule,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )6132;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiTaskSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiSeqNbr);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiParamID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[4] = (unsigned long )31;
  sqlstm.sqhsts[4] = (         int  )31;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asTemplateID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )11;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asCondition);
  sqlstm.sqhstl[6] = (unsigned long )61;
  sqlstm.sqhsts[6] = (         int  )61;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asUserType);
  sqlstm.sqhstl[7] = (unsigned long )41;
  sqlstm.sqhsts[7] = (         int  )41;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asSplitType);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asVisitCode);
  sqlstm.sqhstl[9] = (unsigned long )10;
  sqlstm.sqhsts[9] = (         int  )10;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[10] = (unsigned long )4;
  sqlstm.sqhsts[10] = (         int  )4;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asEffDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asExpDate);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )15;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[13] = (unsigned long )4;
  sqlstm.sqhsts[13] = (         int  )4;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asStateDate);
  sqlstm.sqhstl[14] = (unsigned long )15;
  sqlstm.sqhsts[14] = (         int  )15;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asCreatedDate);
  sqlstm.sqhstl[15] = (unsigned long )15;
  sqlstm.sqhsts[15] = (         int  )15;
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


		CheckSqlError("Fetch ROLL_TASK_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ROLL_TASK_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )6211;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ROLL_TASK_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iTaskSeqNbr=		pSource->aiTaskSeqNbr[iCurPos];
		p->iSeqNbr=		pSource->aiSeqNbr[iCurPos];
		p->iParamID=		pSource->aiParamID[iCurPos];

		strcpy(p->sTableName,	pSource->asTableName[iCurPos]);
		strcpy(p->sTemplateID,	pSource->asTemplateID[iCurPos]);
		strcpy(p->sCondition,	pSource->asCondition[iCurPos]);
		
		strcpy(p->sUserType,	pSource->asUserType[iCurPos]);
		strcpy(p->sSplitType,	pSource->asSplitType[iCurPos]);
		strcpy(p->sVisitCode,	pSource->asVisitCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);

		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);

		AllTrim(p->sSourceID);
		AllTrim(p->sTableName);
		AllTrim(p->sTemplateID);
		AllTrim(p->sCondition);
		
		AllTrim(p->sUserType);
		AllTrim(p->sSplitType);
		AllTrim(p->sVisitCode);
		AllTrim(p->sModule);

		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表ROLL_TASK_PARAM的链表释放函数**/
void DestroyRollTaskParam(struct RollTaskParamStruct *ptHead)
{
	struct RollTaskParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitRollTaskParam(struct RollTaskParamStruct **pptHead)
{
	int iCnt=0;
	static struct RollTaskParamStruct *pTemp,*ptHead=NULL;
	struct RollTaskParamStruct Temp;
	struct RollTaskParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyRollTaskParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct RollTaskParamStructIn));
	sprintf(TempIn.sTableName,"ROLL_TASK_PARAM");
	sprintf(TempIn.sCondition,PARAM_COND);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetRollTaskParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct RollTaskParamStruct*)
			malloc(sizeof(struct RollTaskParamStruct)))==NULL){

			DestroyRollTaskParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct RollTaskParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表ROLL_TASK_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表ROLL_TASK_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从ACCT_PARAM中用结构缓冲方式取数据*/
int EGetAcctParamToStruct(struct AcctParamStruct *p,
	struct AcctParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				GROUP_ID,\n\
				FILE_TYPE,\n\
				OPER_TYPE,\n\
				DATE_RULE,\n\
				SOURCE_PATH,\n\
				BACK_PATH,\n\
				FILTER,\n\
				BELONG_CODE,\n\
				MODULE,\n\
				STATE,\n\
				APP_ID,\n\
				TACHE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ACCT_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6226;
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


		CheckSqlError(" PREPARE ACCT_PARAMSCR ACCT_PARAMCR");

		/* EXEC SQL DECLARE ACCT_PARAMCR CURSOR FOR ACCT_PARAMSCR; */ 

		CheckSqlError("Declare ACCT_PARAMCR");

		/* EXEC SQL OPEN ACCT_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6245;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ACCT_PARAMCR;");


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

		/* EXEC SQL CLOSE ACCT_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6260;
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
		/* EXEC SQL FETCH ACCT_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiGroupID,
			:pSource->asFileType,
			:pSource->asOperType,
			:pSource->asDateRule,
			:pSource->asSourcePath,
			:pSource->asBackPath,
			:pSource->asFilter,
			:pSource->asBelongCode,
			:pSource->asModule,
			:pSource->asState,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )6275;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )6;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asOperType);
  sqlstm.sqhstl[3] = (unsigned long )4;
  sqlstm.sqhsts[3] = (         int  )4;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asDateRule);
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )13;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asSourcePath);
  sqlstm.sqhstl[5] = (unsigned long )81;
  sqlstm.sqhsts[5] = (         int  )81;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asBackPath);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[7] = (unsigned long )21;
  sqlstm.sqhsts[7] = (         int  )21;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asBelongCode);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )6;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[10] = (unsigned long )2;
  sqlstm.sqhsts[10] = (         int  )2;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )11;
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


		CheckSqlError("Fetch ACCT_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ACCT_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )6342;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ACCT_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sFileType,	pSource->asFileType[iCurPos]);
		strcpy(p->sOperType,	pSource->asOperType[iCurPos]);
		strcpy(p->sDateRule,	pSource->asDateRule[iCurPos]);
		strcpy(p->sSourcePath,	pSource->asSourcePath[iCurPos]);
		strcpy(p->sBackPath,	pSource->asBackPath[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sBelongCode,	pSource->asBelongCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		p->iTacheID=		pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sFileType);
		AllTrim(p->sOperType);
		AllTrim(p->sDateRule);
		AllTrim(p->sSourcePath);
		AllTrim(p->sBackPath);
		AllTrim(p->sFilter);
		AllTrim(p->sBelongCode);
		AllTrim(p->sModule);
		AllTrim(p->sState);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表ACCT_PARAM的链表释放函数**/
void DestroyAcctParam(struct AcctParamStruct *ptHead)
{
	struct AcctParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitAcctParam(struct AcctParamStruct **pptHead)
{
	int iCnt=0;
	static struct AcctParamStruct *pTemp,*ptHead=NULL;
	struct AcctParamStruct Temp;
	struct AcctParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyAcctParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct AcctParamStructIn));
	sprintf(TempIn.sTableName,"ACCT_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetAcctParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct AcctParamStruct*)
			malloc(sizeof(struct AcctParamStruct)))==NULL){

			DestroyAcctParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct AcctParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表ACCT_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表ACCT_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}
/*批量数据动态从INTF_PARAM中用结构缓冲方式取数据*/
int EGetIntfParamToStruct(struct IntfParamStruct *p,
	struct IntfParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				GROUP_ID,\n\
				SOURCE_PATH,\n\
				BACK_PATH,\n\
				NORMAL_PATH,\n\
				FILTER,\n\
				DELAY,\n\
				nvl(CITY_CODE,' '),\n\
				nvl(FILE_TYPE,' '),\n\
				STATE,\n\
				APP_ID,\n\
				TACHE_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE INTF_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6357;
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


		CheckSqlError(" PREPARE INTF_PARAMSCR INTF_PARAMCR");

		/* EXEC SQL DECLARE INTF_PARAMCR CURSOR FOR INTF_PARAMSCR; */ 

		CheckSqlError("Declare INTF_PARAMCR");

		/* EXEC SQL OPEN INTF_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6376;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open INTF_PARAMCR;");


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

		/* EXEC SQL CLOSE INTF_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6391;
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
		/* EXEC SQL FETCH INTF_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiGroupID,
			:pSource->asSourcePath,
			:pSource->asBackPath,
			:pSource->asNormalPath,
			:pSource->asFilter,
			:pSource->aiDelay,
			:pSource->asCityCode,
			:pSource->asFileType,
			:pSource->asState,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )6406;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiGroupID);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asSourcePath);
  sqlstm.sqhstl[2] = (unsigned long )81;
  sqlstm.sqhsts[2] = (         int  )81;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asBackPath);
  sqlstm.sqhstl[3] = (unsigned long )81;
  sqlstm.sqhsts[3] = (         int  )81;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asNormalPath);
  sqlstm.sqhstl[4] = (unsigned long )81;
  sqlstm.sqhsts[4] = (         int  )81;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[5] = (unsigned long )21;
  sqlstm.sqhsts[5] = (         int  )21;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiDelay);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCityCode);
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )6;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asState);
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )2;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )11;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiTacheID);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
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


		CheckSqlError("Fetch INTF_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE INTF_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )6469;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=INTF_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);
		
		p->iGroupID=		pSource->aiGroupID[iCurPos];

		strcpy(p->sSourcePath,	pSource->asSourcePath[iCurPos]);
		strcpy(p->sBackPath,	pSource->asBackPath[iCurPos]);
		strcpy(p->sNormalPath,	pSource->asNormalPath[iCurPos]);
		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);

		p->iDelay=		pSource->aiDelay[iCurPos];

		strcpy(p->sCityCode,	pSource->asCityCode[iCurPos]);
		strcpy(p->sFileType,	pSource->asFileType[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);
		
		p->iTacheID=		pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sSourcePath);
		AllTrim(p->sBackPath);
		AllTrim(p->sNormalPath);
		AllTrim(p->sFilter);
		AllTrim(p->sCityCode);
		AllTrim(p->sFileType);
		AllTrim(p->sState);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表INTF_PARAM的链表释放函数**/
void DestroyIntfParam(struct IntfParamStruct *ptHead)
{
	struct IntfParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitIntfParam(struct IntfParamStruct **pptHead)
{
	int iCnt=0;
	static struct IntfParamStruct *pTemp,*ptHead=NULL;
	struct IntfParamStruct Temp;
	struct IntfParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyIntfParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct IntfParamStructIn));
	sprintf(TempIn.sTableName,"INTF_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetIntfParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct IntfParamStruct*)
			malloc(sizeof(struct IntfParamStruct)))==NULL){

			DestroyIntfParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct IntfParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表INTF_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表INTF_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从RCYL_PARAM中用结构缓冲方式取数据*/
int EGetRcylParamToStruct(struct RcylParamStruct *p,
	struct RcylParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				TASK_SEQ_NBR,\n\
				TABLE_NAME,\n\
				CONDITION,\n\
				EXPR_FILE,\n\
				TEMPLATE_ID,\n\
				NORMAL_PATH,\n\
				SPLIT_STR,\n\
				VISIT_CODE,\n\
				MODULE,\n\
				FILE_TYPE,\n\
				nvl(APP_ID,'-1'),\n\
				nvl(TACHE_ID,-1)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE RCYL_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6484;
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


		CheckSqlError(" PREPARE RCYL_PARAMSCR RCYL_PARAMCR");

		/* EXEC SQL DECLARE RCYL_PARAMCR CURSOR FOR RCYL_PARAMSCR; */ 

		CheckSqlError("Declare RCYL_PARAMCR");

		/* EXEC SQL OPEN RCYL_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6503;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open RCYL_PARAMCR;");


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

		/* EXEC SQL CLOSE RCYL_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6518;
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
		/* EXEC SQL FETCH RCYL_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiTaskSeqNbr,
			:pSource->asTableName,
			:pSource->asCondition,
			:pSource->asExprFile,
			:pSource->asTemplateID,
			:pSource->asNormalPath,
			:pSource->asSplitStr,
			:pSource->asVisitCode,
			:pSource->asModule,
			:pSource->asFileType,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )6533;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiTaskSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[2] = (unsigned long )31;
  sqlstm.sqhsts[2] = (         int  )31;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCondition);
  sqlstm.sqhstl[3] = (unsigned long )61;
  sqlstm.sqhsts[3] = (         int  )61;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asExprFile);
  sqlstm.sqhstl[4] = (unsigned long )41;
  sqlstm.sqhsts[4] = (         int  )41;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asTemplateID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )11;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asNormalPath);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSplitStr);
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )11;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asVisitCode);
  sqlstm.sqhstl[8] = (unsigned long )10;
  sqlstm.sqhsts[8] = (         int  )10;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[10] = (unsigned long )6;
  sqlstm.sqhsts[10] = (         int  )6;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )11;
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


		CheckSqlError("Fetch RCYL_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE RCYL_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )6600;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=RCYL_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);

		p->iTaskSeqNbr=		pSource->aiTaskSeqNbr[iCurPos];
		
		strcpy(p->sTableName,	pSource->asTableName[iCurPos]);
		strcpy(p->sCondition,	pSource->asCondition[iCurPos]);
		strcpy(p->sExprFile,	pSource->asExprFile[iCurPos]);
		strcpy(p->sTemplateID,	pSource->asTemplateID[iCurPos]);
		strcpy(p->sNormalPath,	pSource->asNormalPath[iCurPos]);
		strcpy(p->sSplitStr,	pSource->asSplitStr[iCurPos]);
		strcpy(p->sVisitCode,	pSource->asVisitCode[iCurPos]);
		strcpy(p->sModule,	pSource->asModule[iCurPos]);
		strcpy(p->sFileType,	pSource->asFileType[iCurPos]);
		strcpy(p->sAppID,	pSource->asAppID[iCurPos]);

		p->iTacheID=		pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sTableName);
		AllTrim(p->sCondition);
		AllTrim(p->sExprFile);
		AllTrim(p->sTemplateID);
		AllTrim(p->sNormalPath);
		AllTrim(p->sSplitStr);
		AllTrim(p->sVisitCode);
		AllTrim(p->sModule);
		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表RCYL_PARAM的链表释放函数**/
void DestroyRcylParam(struct RcylParamStruct *ptHead)
{
	struct RcylParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitRcylParam(struct RcylParamStruct **pptHead)
{
	int iCnt=0;
	static struct RcylParamStruct *pTemp,*ptHead=NULL;
	struct RcylParamStruct Temp;
	struct RcylParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyRcylParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct RcylParamStructIn));
	sprintf(TempIn.sTableName,"RCYL_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetRcylParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct RcylParamStruct*)
			malloc(sizeof(struct RcylParamStruct)))==NULL){

			DestroyRcylParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct RcylParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表RCYL_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表RCYL_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从ROLL_PARAM中用结构缓冲方式取数据*/
int EGetRollParamToStruct(struct RollParamStruct *p,
	struct RollParamStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				TASK_SEQ_NBR,\n\
				TABLE_NAME,\n\
				CONDITION,\n\
				USER_TYPE,\n\
				TEMPLATE_ID,\n\
				NORMAL_PATH,\n\
				SPLIT_TYPE,\n\
				VISIT_CODE,\n\
				MODULE,\n\
				FILE_TYPE,\n\
				nvl(APP_ID,'-1'),\n\
				nvl(TACHE_ID,-1)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE ROLL_PARAMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6615;
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


		CheckSqlError(" PREPARE ROLL_PARAMSCR ROLL_PARAMCR");

		/* EXEC SQL DECLARE ROLL_PARAMCR CURSOR FOR ROLL_PARAMSCR; */ 

		CheckSqlError("Declare ROLL_PARAMCR");

		/* EXEC SQL OPEN ROLL_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6634;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open ROLL_PARAMCR;");


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

		/* EXEC SQL CLOSE ROLL_PARAMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6649;
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
		/* EXEC SQL FETCH ROLL_PARAMCR INTO
			:pSource->asSourceID,
			:pSource->aiTaskSeqNbr,
			:pSource->asTableName,
			:pSource->asCondition,
			:pSource->asUserType,
			:pSource->asTemplateID,
			:pSource->asNormalPath,
			:pSource->asSplitType,
			:pSource->asVisitCode,
			:pSource->asModule,
			:pSource->asFileType,
			:pSource->asAppID,
			:pSource->aiTacheID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )6664;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->aiTaskSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[2] = (unsigned long )31;
  sqlstm.sqhsts[2] = (         int  )31;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCondition);
  sqlstm.sqhstl[3] = (unsigned long )61;
  sqlstm.sqhsts[3] = (         int  )61;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asUserType);
  sqlstm.sqhstl[4] = (unsigned long )41;
  sqlstm.sqhsts[4] = (         int  )41;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asTemplateID);
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )11;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asNormalPath);
  sqlstm.sqhstl[6] = (unsigned long )81;
  sqlstm.sqhsts[6] = (         int  )81;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asSplitType);
  sqlstm.sqhstl[7] = (unsigned long )2;
  sqlstm.sqhsts[7] = (         int  )2;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asVisitCode);
  sqlstm.sqhstl[8] = (unsigned long )10;
  sqlstm.sqhsts[8] = (         int  )10;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asModule);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[10] = (unsigned long )6;
  sqlstm.sqhsts[10] = (         int  )6;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asAppID);
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )11;
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


		CheckSqlError("Fetch ROLL_PARAMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE ROLL_PARAMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )6731;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=ROLL_PARAM_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,		pSource->asSourceID[iCurPos]);

		p->iTaskSeqNbr=			pSource->aiTaskSeqNbr[iCurPos];

		strcpy(p->sTableName,		pSource->asTableName[iCurPos]);
		strcpy(p->sCondition,		pSource->asCondition[iCurPos]);
	
		strcpy(p->sUserType,		pSource->asUserType[iCurPos]);
		strcpy(p->sTemplateID,		pSource->asTemplateID[iCurPos]);
		strcpy(p->sNormalPath,		pSource->asNormalPath[iCurPos]);
		
		strcpy(p->sSplitType,		pSource->asSplitType[iCurPos]);
		strcpy(p->sVisitCode,		pSource->asVisitCode[iCurPos]);
		strcpy(p->sModule,		pSource->asModule[iCurPos]);

		strcpy(p->sFileType,		pSource->asFileType[iCurPos]);
		strcpy(p->sAppID,		pSource->asAppID[iCurPos]);

		p->iTacheID=			pSource->aiTacheID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sTableName);
		AllTrim(p->sCondition);
		AllTrim(p->sUserType);
		AllTrim(p->sTemplateID);
		AllTrim(p->sNormalPath);
		
		AllTrim(p->sSplitType);
		AllTrim(p->sVisitCode);
		AllTrim(p->sModule);

		AllTrim(p->sFileType);
		AllTrim(p->sAppID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表ROLL_PARAM的链表释放函数**/
void DestroyRollParam(struct RollParamStruct *ptHead)
{
	struct RollParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitRollParam(struct RollParamStruct **pptHead)
{
	int iCnt=0;
	static struct RollParamStruct *pTemp,*ptHead=NULL;
	struct RollParamStruct Temp;
	struct RollParamStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyRollParam(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct RollParamStructIn));
	sprintf(TempIn.sTableName,"ROLL_PARAM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetRollParamToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct RollParamStruct*)
			malloc(sizeof(struct RollParamStruct)))==NULL){

			DestroyRollParam(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct RollParamStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表ROLL_PARAM记录数%d",iCnt);
	}

	WriteProcMsg("加载表ROLL_PARAM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从SOURCE_DESC中用结构缓冲方式取数据*/
int EGetSourceDescToStruct(struct SourceDescStruct *p,
	struct SourceDescStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				SOURCE_ID,\n\
				SOURCE_TYPE,\n\
				REMARK,\n\
				nvl(LATN_ID,-1),\n\
				FILTER,\n\
				FILE_TYPE,\n\
				FLOW_ID\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SOURCE_DESCSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6746;
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


		CheckSqlError(" PREPARE SOURCE_DESCSCR SOURCE_DESCCR");

		/* EXEC SQL DECLARE SOURCE_DESCCR CURSOR FOR SOURCE_DESCSCR; */ 

		CheckSqlError("Declare SOURCE_DESCCR");

		/* EXEC SQL OPEN SOURCE_DESCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6765;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SOURCE_DESCCR;");


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

		/* EXEC SQL CLOSE SOURCE_DESCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )6780;
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
		/* EXEC SQL FETCH SOURCE_DESCCR INTO
			:pSource->asSourceID,
			:pSource->asSourceType,
			:pSource->asRemark,
			:pSource->aiLatnID,
			:pSource->asFilter,
			:pSource->asFileType,
			:pSource->aiFlowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )6795;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSourceID);
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )7;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asSourceType);
  sqlstm.sqhstl[1] = (unsigned long )2;
  sqlstm.sqhsts[1] = (         int  )2;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asRemark);
  sqlstm.sqhstl[2] = (unsigned long )41;
  sqlstm.sqhsts[2] = (         int  )41;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiLatnID);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asFilter);
  sqlstm.sqhstl[4] = (unsigned long )21;
  sqlstm.sqhsts[4] = (         int  )21;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFileType);
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )6;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->aiFlowID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
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


		CheckSqlError("Fetch SOURCE_DESCCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SOURCE_DESCCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 21;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )6838;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SOURCE_DESC_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSourceID,	pSource->asSourceID[iCurPos]);
		strcpy(p->sSourceType,	pSource->asSourceType[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);

		p->iLatnID=		pSource->aiLatnID[iCurPos];

		strcpy(p->sFilter,	pSource->asFilter[iCurPos]);
		strcpy(p->sFileType,	pSource->asFileType[iCurPos]);

		p->iFlowID=		pSource->aiFlowID[iCurPos];

		AllTrim(p->sSourceID);
		AllTrim(p->sSourceType);
		AllTrim(p->sRemark);
		AllTrim(p->sFileType);
		AllTrim(p->sFileType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

/**对表SOURCE_DESC的链表释放函数**/
void DestroySourceDesc(struct SourceDescStruct *ptHead)
{
	struct SourceDescStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSourceDesc(struct SourceDescStruct **pptHead)
{
	int iCnt=0;
	static struct SourceDescStruct *pTemp,*ptHead=NULL;
	struct SourceDescStruct Temp;
	struct SourceDescStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySourceDesc(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SourceDescStructIn));
	sprintf(TempIn.sTableName,"SOURCE_DESC");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSourceDescToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SourceDescStruct*)
			malloc(sizeof(struct SourceDescStruct)))==NULL){

			DestroySourceDesc(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SourceDescStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SOURCE_DESC记录数%d",iCnt);
	}

	WriteProcMsg("加载表SOURCE_DESC完毕总记录数%d",iCnt);

	return iCnt;
}
