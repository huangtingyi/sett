
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
    "sett_supp.pc"
};


static unsigned int sqlctx = 327675;


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
   unsigned char  *sqhstv[104];
   unsigned long  sqhstl[104];
            int   sqhsts[104];
            short *sqindv[104];
            int   sqinds[104];
   unsigned long  sqharm[104];
   unsigned long  *sqharc[104];
   unsigned short  sqadto[104];
   unsigned short  sqtdso[104];
} sqlstm = {12,104};

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
5,0,0,1,0,0,17,144,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,150,0,0,0,0,0,1,0,
39,0,0,1,0,0,15,167,0,0,0,0,0,1,0,
54,0,0,1,0,0,13,175,0,0,104,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,
485,0,0,1,0,0,15,292,0,0,0,0,0,1,0,
500,0,0,2,0,0,17,1486,0,0,1,1,0,1,0,1,97,0,0,
519,0,0,2,0,0,21,1489,0,0,104,104,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
950,0,0,3,55,0,4,1607,0,0,1,0,0,1,0,2,3,0,0,
969,0,0,4,0,0,17,1631,0,0,1,1,0,1,0,1,97,0,0,
988,0,0,4,0,0,45,1637,0,0,0,0,0,1,0,
1003,0,0,4,0,0,13,1643,0,0,5,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,
1038,0,0,4,0,0,15,1652,0,0,0,0,0,1,0,
1053,0,0,4,0,0,15,1655,0,0,0,0,0,1,0,
1068,0,0,5,0,0,17,1698,0,0,1,1,0,1,0,1,97,0,0,
1087,0,0,5,0,0,21,1701,0,0,7,7,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,3,0,0,
1130,0,0,6,0,0,17,1740,0,0,1,1,0,1,0,1,97,0,0,
1149,0,0,6,0,0,45,1746,0,0,0,0,0,1,0,
1164,0,0,6,0,0,15,1763,0,0,0,0,0,1,0,
1179,0,0,6,0,0,13,1771,0,0,8,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,
1226,0,0,6,0,0,15,1792,0,0,0,0,0,1,0,
1241,0,0,7,0,0,17,1953,0,0,1,1,0,1,0,1,97,0,0,
1260,0,0,7,0,0,45,1959,0,0,0,0,0,1,0,
1275,0,0,7,0,0,15,1976,0,0,0,0,0,1,0,
1290,0,0,7,0,0,13,1984,0,0,43,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1477,0,0,7,0,0,15,2040,0,0,0,0,0,1,0,
1492,0,0,8,0,0,17,2562,0,0,1,1,0,1,0,1,97,0,0,
1511,0,0,8,0,0,21,2565,0,0,43,43,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1698,0,0,9,0,0,17,2664,0,0,1,1,0,1,0,1,97,0,0,
1717,0,0,9,0,0,45,2670,0,0,0,0,0,1,0,
1732,0,0,9,0,0,15,2687,0,0,0,0,0,1,0,
1747,0,0,9,0,0,13,2695,0,0,27,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1870,0,0,9,0,0,15,2735,0,0,0,0,0,1,0,
1885,0,0,10,0,0,17,3126,0,0,1,1,0,1,0,1,97,0,0,
1904,0,0,10,0,0,21,3129,0,0,27,27,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2027,0,0,11,0,0,17,3219,0,0,1,1,0,1,0,1,97,0,0,
2046,0,0,11,0,0,45,3225,0,0,0,0,0,1,0,
2061,0,0,11,0,0,15,3242,0,0,0,0,0,1,0,
2076,0,0,11,0,0,13,3250,0,0,34,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,
2227,0,0,11,0,0,15,3297,0,0,0,0,0,1,0,
2242,0,0,12,0,0,17,3749,0,0,1,1,0,1,0,1,97,0,0,
2261,0,0,12,0,0,21,3752,0,0,34,34,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,
2412,0,0,13,0,0,17,3843,0,0,1,1,0,1,0,1,97,0,0,
2431,0,0,13,0,0,45,3849,0,0,0,0,0,1,0,
2446,0,0,13,0,0,15,3866,0,0,0,0,0,1,0,
2461,0,0,13,0,0,13,3874,0,0,25,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,
2576,0,0,13,0,0,15,3912,0,0,0,0,0,1,0,
2591,0,0,14,0,0,17,4291,0,0,1,1,0,1,0,1,97,0,0,
2610,0,0,14,0,0,21,4294,0,0,25,25,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,
2725,0,0,15,0,0,17,4374,0,0,1,1,0,1,0,1,97,0,0,
2744,0,0,15,0,0,45,4380,0,0,0,0,0,1,0,
2759,0,0,15,0,0,15,4397,0,0,0,0,0,1,0,
2774,0,0,15,0,0,13,4405,0,0,22,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2877,0,0,15,0,0,15,4440,0,0,0,0,0,1,0,
2892,0,0,16,0,0,17,4779,0,0,1,1,0,1,0,1,97,0,0,
2911,0,0,16,0,0,21,4782,0,0,22,22,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
3014,0,0,17,0,0,17,4838,0,0,1,1,0,1,0,1,97,0,0,
3033,0,0,17,0,0,45,4844,0,0,0,0,0,1,0,
3048,0,0,17,0,0,15,4861,0,0,0,0,0,1,0,
3063,0,0,17,0,0,13,4869,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3094,0,0,17,0,0,15,4886,0,0,0,0,0,1,0,
3109,0,0,18,0,0,17,4999,0,0,1,1,0,1,0,1,97,0,0,
3128,0,0,18,0,0,45,5005,0,0,0,0,0,1,0,
3143,0,0,18,0,0,15,5022,0,0,0,0,0,1,0,
3158,0,0,18,0,0,13,5030,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
3189,0,0,18,0,0,15,5047,0,0,0,0,0,1,0,
3204,0,0,19,0,0,17,5168,0,0,1,1,0,1,0,1,97,0,0,
3223,0,0,19,0,0,45,5174,0,0,0,0,0,1,0,
3238,0,0,19,0,0,15,5191,0,0,0,0,0,1,0,
3253,0,0,19,0,0,13,5199,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
3284,0,0,19,0,0,15,5216,0,0,0,0,0,1,0,
3299,0,0,20,0,0,17,5302,0,0,1,1,0,1,0,1,97,0,0,
3318,0,0,20,0,0,21,5305,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,
3353,0,0,21,0,0,17,5344,0,0,1,1,0,1,0,1,97,0,0,
3372,0,0,21,0,0,45,5350,0,0,0,0,0,1,0,
3387,0,0,21,0,0,15,5367,0,0,0,0,0,1,0,
3402,0,0,21,0,0,13,5375,0,0,6,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,
3441,0,0,21,0,0,15,5394,0,0,0,0,0,1,0,
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
#include <sett_supp.h>
#include <datatype.h>

#include "../include/stt_ticket.h"




/*批量数据动态从T_TEMPLATE_YD_GW_UE中用结构缓冲方式取数据*/
int EGetTTemplateYdGwUeToStruct(struct TTemplateYdGwUeStruct *p,
	struct TTemplateYdGwUeStructIn *pSource)
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
				nvl(PROD_ID,' '),\n\
				nvl(START_TIME,' '),\n\
				nvl(END_TIME,' '),\n\
				nvl(RATE_TIME,' '),\n\
				nvl(OPERATION_TYPE_ID,' '),\n\
				nvl(CALLING_NUMBER,' '),\n\
				nvl(CALLED_NUMBER,' '),\n\
				nvl(BILLED_NUMBER,' '),\n\
				nvl(THIRD_NUMBER,' '),\n\
				nvl(CALLING_AREA_ID,0),\n\
				nvl(CALLED_AREA_ID,0),\n\
				nvl(IN_TRUNK_NUMBER,' '),\n\
				nvl(OUT_TRUNK_NUMBER,' '),\n\
				nvl(RAW_UNIT_TYPE,0),\n\
				to_char(nvl(RAW_UNITS,0)),\n\
				nvl(RATE_UNIT_TYPE,0),\n\
				nvl(IS_FREE,' '),\n\
				nvl(RATE_UNITS,0),\n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				nvl(CALLING_ROAM_NUMBER,' '),\n\
				nvl(CALLED_ROAM_NUMBER,' '),\n\
				nvl(CALLING_ROAM_AREA_CODE,' '),\n\
				nvl(CALLED_ROAM_AREA_CODE,' '),\n\
				to_char(nvl(TOTAL_DUE_AMOUNT,0)),\n\
				nvl(PROD_INST_ID,0),\n\
				nvl(RATE_ID,0),\n\
				to_char(nvl(UP_FLUX,0)),\n\
				to_char(nvl(DURATION,0)),\n\
				nvl(CITY_ID,0),\n\
				to_char(nvl(DOWN_FLUX,0)),\n\
				nvl(FILE_NAME,' '),\n\
				to_char(nvl(TOTAL_FLUX,0)),\n\
				nvl(STATUS,' '),\n\
				nvl(BILL_CYCLE_SEQ,0),\n\
				to_char(nvl(CURR_BALANCE,0)),\n\
				nvl(CREATE_CYCLE_SEQ,0),\n\
				nvl(RATE_KEY1,' '),\n\
				nvl(RATE_KEY2,' '),\n\
				nvl(RATE_KEY3,' '),\n\
				nvl(PURE_CYCLE_SEQ,0),\n\
				nvl(DIRECTION,0),\n\
				nvl(FILE_CLASS_ID,0),\n\
				nvl(EXCEPTION_TYPE,' '),\n\
				nvl(ORIG_USAGE_TYPE_ID,' '),\n\
				nvl(TOTAL_DUE_UNITS,0),\n\
				to_char(nvl(STL_AMOUNT,0)),\n\
				nvl(POST_FLAG,' '),\n\
				nvl(IS_PREPAY,0),\n\
				nvl(FILE_ID,0),\n\
				nvl(PARENT_FILE_ID,0),\n\
				nvl(TABLE_NAME,' '),\n\
				to_char(nvl(CALLING_COMPANY_ID,0)),\n\
				to_char(nvl(CALLED_COMPANY_ID,0)),\n\
				to_char(nvl(SWITCH_COMPANY_ID,0)),\n\
				nvl(PROVINCE_ID,' '),\n\
				to_char(nvl(DURATION_MINNUM,0)),\n\
				to_char(nvl(DURATION_SEC6,0)),\n\
				nvl(IN_TRUNK_GROUP,' '),\n\
				nvl(OUT_TRUNK_GROUP,' '),\n\
				to_char(nvl(CALLING_NUMBER_COMPANY_ID,0)),\n\
				to_char(nvl(CALLED_NUMBER_COMPANY_ID,0)),\n\
				nvl(CALLING_GROUP_ID,' '),\n\
				nvl(CALLED_GROUP_ID,' '),\n\
				nvl(STL_OBJECT,' '),\n\
				to_char(nvl(PROD_PROP_ID,0)),\n\
				nvl(CALLING_SUB_TYPE,' '),\n\
				nvl(CALLED_SUB_TYPE,' '),\n\
				nvl(STL_DIRECTION,0),\n\
				nvl(PRE_CALL_TYPE,' '),\n\
				nvl(TURN_CODE,' '),\n\
				nvl(TURN_CODE_COMPANY_ID,' '),\n\
				nvl(TURN_CODE_PROVINCE_ID,' '),\n\
				nvl(TURN_CODE_CITY_ID,0),\n\
				nvl(TURN_CODE_OPERATION_TYPE_GRADE,' '),\n\
				nvl(TURN_TYPE,' '),\n\
				nvl(TURN_CDR_ID,' '),\n\
				nvl(SECOND_CALLING_NUMBER,' '),\n\
				nvl(SECOND_CALLING_AREA_CODE,' '),\n\
				nvl(SECOND_CALLING_GROUP_ID,' '),\n\
				nvl(SECOND_CALLING_COMPANY_ID,' '),\n\
				nvl(PRE_CALL_PARENT_CDR_ID,' '),\n\
				nvl(PRE_CALL_SUB_CDR_ID,' '),\n\
				nvl(PRE_CALL_SUB_CDR_NUM,' '),\n\
				nvl(PRE_CALL_SUB_CDR_SEQ,' '),\n\
				to_char(nvl(PRE_CALL_USAGE_EVENT_ID,0)),\n\
				nvl(TURN_PARENT_CDR_ID,' '),\n\
				nvl(TURN_SUB_CDR_ID,' '),\n\
				nvl(TURN_SUB_CDR_NUM,' '),\n\
				nvl(TURN_SUB_CDR_SEQ,' '),\n\
				nvl(TURN_USAGE_EVENT_ID,' '),\n\
				nvl(IN_TRUNK_GENRE,' '),\n\
				nvl(OUT_TRUNK_GENRE,' '),\n\
				nvl(IN_TRUNK_NET_TYPE,' '),\n\
				nvl(OUT_TRUNK_NET_TYPE,' '),\n\
				nvl(CALLING_NUMBER_TYPE,' '),\n\
				nvl(CALLED_NUMBER_TYPE,' '),\n\
				nvl(CALLING_DOMAIN_ID,' '),\n\
				nvl(CALLED_DOMAIN_ID,' '),\n\
				nvl(SECOND_SUB_TYPE,' '),\n\
				nvl(SECOND_CALLING_ROAMNUMBER,' '),\n\
				nvl(VIEW_CALL,' '),\n\
				nvl(GROUP_ID,'0')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE T_TEMPLATE_YD_GW_UESCR FROM :statement; */ 

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


		CheckSqlError(" PREPARE T_TEMPLATE_YD_GW_UESCR T_TEMPLATE_YD_GW_UECR");

		/* EXEC SQL DECLARE T_TEMPLATE_YD_GW_UECR CURSOR FOR T_TEMPLATE_YD_GW_UESCR; */ 

		CheckSqlError("Declare T_TEMPLATE_YD_GW_UECR");

		/* EXEC SQL OPEN T_TEMPLATE_YD_GW_UECR; */ 

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


		CheckSqlError("Open T_TEMPLATE_YD_GW_UECR;");


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

		/* EXEC SQL CLOSE T_TEMPLATE_YD_GW_UECR; */ 

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
		/* EXEC SQL FETCH T_TEMPLATE_YD_GW_UECR INTO
			:pSource->asUsageEventID,
			:pSource->asProdID,
			:pSource->asStartTime,
			:pSource->asEndTime,
			:pSource->asRateTime,
			:pSource->asOperationTypeID,
			:pSource->asCallingNumber,
			:pSource->asCalledNumber,
			:pSource->asBilledNumber,
			:pSource->asThirdNumber,
			:pSource->aiCallingAreaID,
			:pSource->aiCalledAreaID,
			:pSource->asInTrunkNumber,
			:pSource->asOutTrunkNumber,
			:pSource->aiRawUnitType,
			:pSource->asRawUnits,
			:pSource->aiRateUnitType,
			:pSource->asIsFree,
			:pSource->aiRateUnits,
			:pSource->asCallingAreaCode,
			:pSource->asCalledAreaCode,
			:pSource->asCallingRoamNumber,
			:pSource->asCalledRoamNumber,
			:pSource->asCallingRoamAreaCode,
			:pSource->asCalledRoamAreaCode,
			:pSource->asTotalDueAmount,
			:pSource->aiProdInstID,
			:pSource->aiRateID,
			:pSource->asUpFlux,
			:pSource->asDuration,
			:pSource->aiCityID,
			:pSource->asDownFlux,
			:pSource->asFileName,
			:pSource->asTotalFlux,
			:pSource->asStatus,
			:pSource->aiBillCycleSeq,
			:pSource->asCurrBalance,
			:pSource->aiCreateCycleSeq,
			:pSource->asRateKey1,
			:pSource->asRateKey2,
			:pSource->asRateKey3,
			:pSource->aiPureCycleSeq,
			:pSource->aiDirection,
			:pSource->aiFileClassID,
			:pSource->asExceptionType,
			:pSource->asOrigUsageTypeID,
			:pSource->aiTotalDueUnits,
			:pSource->asStlAmount,
			:pSource->asPostFlag,
			:pSource->aiIsPrepay,
			:pSource->aiFileID,
			:pSource->aiParentFileID,
			:pSource->asTableName,
			:pSource->asCallingCompanyID,
			:pSource->asCalledCompanyID,
			:pSource->asSwitchCompanyID,
			:pSource->asProvinceID,
			:pSource->asDurationMinnum,
			:pSource->asDurationSec6,
			:pSource->asInTrunkGroup,
			:pSource->asOutTrunkGroup,
			:pSource->asCallingNumberCompanyID,
			:pSource->asCalledNumberCompanyID,
			:pSource->asCallingGroupID,
			:pSource->asCalledGroupID,
			:pSource->asStlObject,
			:pSource->asProdPropID,
			:pSource->asCallingSubType,
			:pSource->asCalledSubType,
			:pSource->aiStlDirection,
			:pSource->asPreCallType,
			:pSource->asTurnCode,
			:pSource->asTurnCodeCompanyID,
			:pSource->asTurnCodeProvinceID,
			:pSource->aiTurnCodeCityID,
			:pSource->asTurnCodeOperationTypeGrade,
			:pSource->asTurnType,
			:pSource->asTurnCdrID,
			:pSource->asSecondCallingNumber,
			:pSource->asSecondCallingAreaCode,
			:pSource->asSecondCallingGroupID,
			:pSource->asSecondCallingCompanyID,
			:pSource->asPreCallParentCdrID,
			:pSource->asPreCallSubCdrID,
			:pSource->asPreCallSubCdrNum,
			:pSource->asPreCallSubCdrSeq,
			:pSource->asPreCallUsageEventID,
			:pSource->asTurnParentCdrID,
			:pSource->asTurnSubCdrID,
			:pSource->asTurnSubCdrNum,
			:pSource->asTurnSubCdrSeq,
			:pSource->asTurnUsageEventID,
			:pSource->asInTrunkGenre,
			:pSource->asOutTrunkGenre,
			:pSource->asInTrunkNetType,
			:pSource->asOutTrunkNetType,
			:pSource->asCallingNumberType,
			:pSource->asCalledNumberType,
			:pSource->asCallingDomainID,
			:pSource->asCalledDomainID,
			:pSource->asSecondSubType,
			:pSource->asSecondCallingRoamnumber,
			:pSource->asViewCall,
			:pSource->asGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asStartTime);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asEndTime);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )15;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asRateTime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
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
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asCallingNumber);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )31;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCalledNumber);
  sqlstm.sqhstl[7] = (unsigned long )31;
  sqlstm.sqhsts[7] = (         int  )31;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asBilledNumber);
  sqlstm.sqhstl[8] = (unsigned long )31;
  sqlstm.sqhsts[8] = (         int  )31;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asThirdNumber);
  sqlstm.sqhstl[9] = (unsigned long )31;
  sqlstm.sqhsts[9] = (         int  )31;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiCallingAreaID);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiCalledAreaID);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asInTrunkNumber);
  sqlstm.sqhstl[12] = (unsigned long )21;
  sqlstm.sqhsts[12] = (         int  )21;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asOutTrunkNumber);
  sqlstm.sqhstl[13] = (unsigned long )21;
  sqlstm.sqhsts[13] = (         int  )21;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiRawUnitType);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asRawUnits);
  sqlstm.sqhstl[15] = (unsigned long )19;
  sqlstm.sqhsts[15] = (         int  )19;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->aiRateUnitType);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )sizeof(int);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asIsFree);
  sqlstm.sqhstl[17] = (unsigned long )21;
  sqlstm.sqhsts[17] = (         int  )21;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->aiRateUnits);
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )sizeof(int);
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[19] = (unsigned long )11;
  sqlstm.sqhsts[19] = (         int  )11;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[20] = (unsigned long )11;
  sqlstm.sqhsts[20] = (         int  )11;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asCallingRoamNumber);
  sqlstm.sqhstl[21] = (unsigned long )31;
  sqlstm.sqhsts[21] = (         int  )31;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asCalledRoamNumber);
  sqlstm.sqhstl[22] = (unsigned long )31;
  sqlstm.sqhsts[22] = (         int  )31;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asCallingRoamAreaCode);
  sqlstm.sqhstl[23] = (unsigned long )11;
  sqlstm.sqhsts[23] = (         int  )11;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asCalledRoamAreaCode);
  sqlstm.sqhstl[24] = (unsigned long )11;
  sqlstm.sqhsts[24] = (         int  )11;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pSource->asTotalDueAmount);
  sqlstm.sqhstl[25] = (unsigned long )19;
  sqlstm.sqhsts[25] = (         int  )19;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pSource->aiProdInstID);
  sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[26] = (         int  )sizeof(int);
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pSource->aiRateID);
  sqlstm.sqhstl[27] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[27] = (         int  )sizeof(int);
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pSource->asUpFlux);
  sqlstm.sqhstl[28] = (unsigned long )19;
  sqlstm.sqhsts[28] = (         int  )19;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pSource->asDuration);
  sqlstm.sqhstl[29] = (unsigned long )19;
  sqlstm.sqhsts[29] = (         int  )19;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pSource->aiCityID);
  sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[30] = (         int  )sizeof(int);
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pSource->asDownFlux);
  sqlstm.sqhstl[31] = (unsigned long )19;
  sqlstm.sqhsts[31] = (         int  )19;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[32] = (unsigned long )61;
  sqlstm.sqhsts[32] = (         int  )61;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pSource->asTotalFlux);
  sqlstm.sqhstl[33] = (unsigned long )19;
  sqlstm.sqhsts[33] = (         int  )19;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pSource->asStatus);
  sqlstm.sqhstl[34] = (unsigned long )4;
  sqlstm.sqhsts[34] = (         int  )4;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pSource->aiBillCycleSeq);
  sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[35] = (         int  )sizeof(int);
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pSource->asCurrBalance);
  sqlstm.sqhstl[36] = (unsigned long )19;
  sqlstm.sqhsts[36] = (         int  )19;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pSource->aiCreateCycleSeq);
  sqlstm.sqhstl[37] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[37] = (         int  )sizeof(int);
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pSource->asRateKey1);
  sqlstm.sqhstl[38] = (unsigned long )31;
  sqlstm.sqhsts[38] = (         int  )31;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pSource->asRateKey2);
  sqlstm.sqhstl[39] = (unsigned long )31;
  sqlstm.sqhsts[39] = (         int  )31;
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pSource->asRateKey3);
  sqlstm.sqhstl[40] = (unsigned long )31;
  sqlstm.sqhsts[40] = (         int  )31;
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pSource->aiPureCycleSeq);
  sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[41] = (         int  )sizeof(int);
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pSource->aiDirection);
  sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[42] = (         int  )sizeof(int);
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqharc[42] = (unsigned long  *)0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)(pSource->aiFileClassID);
  sqlstm.sqhstl[43] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[43] = (         int  )sizeof(int);
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqharc[43] = (unsigned long  *)0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
  sqlstm.sqhstv[44] = (unsigned char  *)(pSource->asExceptionType);
  sqlstm.sqhstl[44] = (unsigned long )6;
  sqlstm.sqhsts[44] = (         int  )6;
  sqlstm.sqindv[44] = (         short *)0;
  sqlstm.sqinds[44] = (         int  )0;
  sqlstm.sqharm[44] = (unsigned long )0;
  sqlstm.sqharc[44] = (unsigned long  *)0;
  sqlstm.sqadto[44] = (unsigned short )0;
  sqlstm.sqtdso[44] = (unsigned short )0;
  sqlstm.sqhstv[45] = (unsigned char  *)(pSource->asOrigUsageTypeID);
  sqlstm.sqhstl[45] = (unsigned long )13;
  sqlstm.sqhsts[45] = (         int  )13;
  sqlstm.sqindv[45] = (         short *)0;
  sqlstm.sqinds[45] = (         int  )0;
  sqlstm.sqharm[45] = (unsigned long )0;
  sqlstm.sqharc[45] = (unsigned long  *)0;
  sqlstm.sqadto[45] = (unsigned short )0;
  sqlstm.sqtdso[45] = (unsigned short )0;
  sqlstm.sqhstv[46] = (unsigned char  *)(pSource->aiTotalDueUnits);
  sqlstm.sqhstl[46] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[46] = (         int  )sizeof(int);
  sqlstm.sqindv[46] = (         short *)0;
  sqlstm.sqinds[46] = (         int  )0;
  sqlstm.sqharm[46] = (unsigned long )0;
  sqlstm.sqharc[46] = (unsigned long  *)0;
  sqlstm.sqadto[46] = (unsigned short )0;
  sqlstm.sqtdso[46] = (unsigned short )0;
  sqlstm.sqhstv[47] = (unsigned char  *)(pSource->asStlAmount);
  sqlstm.sqhstl[47] = (unsigned long )19;
  sqlstm.sqhsts[47] = (         int  )19;
  sqlstm.sqindv[47] = (         short *)0;
  sqlstm.sqinds[47] = (         int  )0;
  sqlstm.sqharm[47] = (unsigned long )0;
  sqlstm.sqharc[47] = (unsigned long  *)0;
  sqlstm.sqadto[47] = (unsigned short )0;
  sqlstm.sqtdso[47] = (unsigned short )0;
  sqlstm.sqhstv[48] = (unsigned char  *)(pSource->asPostFlag);
  sqlstm.sqhstl[48] = (unsigned long )5;
  sqlstm.sqhsts[48] = (         int  )5;
  sqlstm.sqindv[48] = (         short *)0;
  sqlstm.sqinds[48] = (         int  )0;
  sqlstm.sqharm[48] = (unsigned long )0;
  sqlstm.sqharc[48] = (unsigned long  *)0;
  sqlstm.sqadto[48] = (unsigned short )0;
  sqlstm.sqtdso[48] = (unsigned short )0;
  sqlstm.sqhstv[49] = (unsigned char  *)(pSource->aiIsPrepay);
  sqlstm.sqhstl[49] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[49] = (         int  )sizeof(int);
  sqlstm.sqindv[49] = (         short *)0;
  sqlstm.sqinds[49] = (         int  )0;
  sqlstm.sqharm[49] = (unsigned long )0;
  sqlstm.sqharc[49] = (unsigned long  *)0;
  sqlstm.sqadto[49] = (unsigned short )0;
  sqlstm.sqtdso[49] = (unsigned short )0;
  sqlstm.sqhstv[50] = (unsigned char  *)(pSource->aiFileID);
  sqlstm.sqhstl[50] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[50] = (         int  )sizeof(int);
  sqlstm.sqindv[50] = (         short *)0;
  sqlstm.sqinds[50] = (         int  )0;
  sqlstm.sqharm[50] = (unsigned long )0;
  sqlstm.sqharc[50] = (unsigned long  *)0;
  sqlstm.sqadto[50] = (unsigned short )0;
  sqlstm.sqtdso[50] = (unsigned short )0;
  sqlstm.sqhstv[51] = (unsigned char  *)(pSource->aiParentFileID);
  sqlstm.sqhstl[51] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[51] = (         int  )sizeof(int);
  sqlstm.sqindv[51] = (         short *)0;
  sqlstm.sqinds[51] = (         int  )0;
  sqlstm.sqharm[51] = (unsigned long )0;
  sqlstm.sqharc[51] = (unsigned long  *)0;
  sqlstm.sqadto[51] = (unsigned short )0;
  sqlstm.sqtdso[51] = (unsigned short )0;
  sqlstm.sqhstv[52] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[52] = (unsigned long )31;
  sqlstm.sqhsts[52] = (         int  )31;
  sqlstm.sqindv[52] = (         short *)0;
  sqlstm.sqinds[52] = (         int  )0;
  sqlstm.sqharm[52] = (unsigned long )0;
  sqlstm.sqharc[52] = (unsigned long  *)0;
  sqlstm.sqadto[52] = (unsigned short )0;
  sqlstm.sqtdso[52] = (unsigned short )0;
  sqlstm.sqhstv[53] = (unsigned char  *)(pSource->asCallingCompanyID);
  sqlstm.sqhstl[53] = (unsigned long )19;
  sqlstm.sqhsts[53] = (         int  )19;
  sqlstm.sqindv[53] = (         short *)0;
  sqlstm.sqinds[53] = (         int  )0;
  sqlstm.sqharm[53] = (unsigned long )0;
  sqlstm.sqharc[53] = (unsigned long  *)0;
  sqlstm.sqadto[53] = (unsigned short )0;
  sqlstm.sqtdso[53] = (unsigned short )0;
  sqlstm.sqhstv[54] = (unsigned char  *)(pSource->asCalledCompanyID);
  sqlstm.sqhstl[54] = (unsigned long )19;
  sqlstm.sqhsts[54] = (         int  )19;
  sqlstm.sqindv[54] = (         short *)0;
  sqlstm.sqinds[54] = (         int  )0;
  sqlstm.sqharm[54] = (unsigned long )0;
  sqlstm.sqharc[54] = (unsigned long  *)0;
  sqlstm.sqadto[54] = (unsigned short )0;
  sqlstm.sqtdso[54] = (unsigned short )0;
  sqlstm.sqhstv[55] = (unsigned char  *)(pSource->asSwitchCompanyID);
  sqlstm.sqhstl[55] = (unsigned long )19;
  sqlstm.sqhsts[55] = (         int  )19;
  sqlstm.sqindv[55] = (         short *)0;
  sqlstm.sqinds[55] = (         int  )0;
  sqlstm.sqharm[55] = (unsigned long )0;
  sqlstm.sqharc[55] = (unsigned long  *)0;
  sqlstm.sqadto[55] = (unsigned short )0;
  sqlstm.sqtdso[55] = (unsigned short )0;
  sqlstm.sqhstv[56] = (unsigned char  *)(pSource->asProvinceID);
  sqlstm.sqhstl[56] = (unsigned long )21;
  sqlstm.sqhsts[56] = (         int  )21;
  sqlstm.sqindv[56] = (         short *)0;
  sqlstm.sqinds[56] = (         int  )0;
  sqlstm.sqharm[56] = (unsigned long )0;
  sqlstm.sqharc[56] = (unsigned long  *)0;
  sqlstm.sqadto[56] = (unsigned short )0;
  sqlstm.sqtdso[56] = (unsigned short )0;
  sqlstm.sqhstv[57] = (unsigned char  *)(pSource->asDurationMinnum);
  sqlstm.sqhstl[57] = (unsigned long )19;
  sqlstm.sqhsts[57] = (         int  )19;
  sqlstm.sqindv[57] = (         short *)0;
  sqlstm.sqinds[57] = (         int  )0;
  sqlstm.sqharm[57] = (unsigned long )0;
  sqlstm.sqharc[57] = (unsigned long  *)0;
  sqlstm.sqadto[57] = (unsigned short )0;
  sqlstm.sqtdso[57] = (unsigned short )0;
  sqlstm.sqhstv[58] = (unsigned char  *)(pSource->asDurationSec6);
  sqlstm.sqhstl[58] = (unsigned long )19;
  sqlstm.sqhsts[58] = (         int  )19;
  sqlstm.sqindv[58] = (         short *)0;
  sqlstm.sqinds[58] = (         int  )0;
  sqlstm.sqharm[58] = (unsigned long )0;
  sqlstm.sqharc[58] = (unsigned long  *)0;
  sqlstm.sqadto[58] = (unsigned short )0;
  sqlstm.sqtdso[58] = (unsigned short )0;
  sqlstm.sqhstv[59] = (unsigned char  *)(pSource->asInTrunkGroup);
  sqlstm.sqhstl[59] = (unsigned long )16;
  sqlstm.sqhsts[59] = (         int  )16;
  sqlstm.sqindv[59] = (         short *)0;
  sqlstm.sqinds[59] = (         int  )0;
  sqlstm.sqharm[59] = (unsigned long )0;
  sqlstm.sqharc[59] = (unsigned long  *)0;
  sqlstm.sqadto[59] = (unsigned short )0;
  sqlstm.sqtdso[59] = (unsigned short )0;
  sqlstm.sqhstv[60] = (unsigned char  *)(pSource->asOutTrunkGroup);
  sqlstm.sqhstl[60] = (unsigned long )16;
  sqlstm.sqhsts[60] = (         int  )16;
  sqlstm.sqindv[60] = (         short *)0;
  sqlstm.sqinds[60] = (         int  )0;
  sqlstm.sqharm[60] = (unsigned long )0;
  sqlstm.sqharc[60] = (unsigned long  *)0;
  sqlstm.sqadto[60] = (unsigned short )0;
  sqlstm.sqtdso[60] = (unsigned short )0;
  sqlstm.sqhstv[61] = (unsigned char  *)(pSource->asCallingNumberCompanyID);
  sqlstm.sqhstl[61] = (unsigned long )19;
  sqlstm.sqhsts[61] = (         int  )19;
  sqlstm.sqindv[61] = (         short *)0;
  sqlstm.sqinds[61] = (         int  )0;
  sqlstm.sqharm[61] = (unsigned long )0;
  sqlstm.sqharc[61] = (unsigned long  *)0;
  sqlstm.sqadto[61] = (unsigned short )0;
  sqlstm.sqtdso[61] = (unsigned short )0;
  sqlstm.sqhstv[62] = (unsigned char  *)(pSource->asCalledNumberCompanyID);
  sqlstm.sqhstl[62] = (unsigned long )19;
  sqlstm.sqhsts[62] = (         int  )19;
  sqlstm.sqindv[62] = (         short *)0;
  sqlstm.sqinds[62] = (         int  )0;
  sqlstm.sqharm[62] = (unsigned long )0;
  sqlstm.sqharc[62] = (unsigned long  *)0;
  sqlstm.sqadto[62] = (unsigned short )0;
  sqlstm.sqtdso[62] = (unsigned short )0;
  sqlstm.sqhstv[63] = (unsigned char  *)(pSource->asCallingGroupID);
  sqlstm.sqhstl[63] = (unsigned long )16;
  sqlstm.sqhsts[63] = (         int  )16;
  sqlstm.sqindv[63] = (         short *)0;
  sqlstm.sqinds[63] = (         int  )0;
  sqlstm.sqharm[63] = (unsigned long )0;
  sqlstm.sqharc[63] = (unsigned long  *)0;
  sqlstm.sqadto[63] = (unsigned short )0;
  sqlstm.sqtdso[63] = (unsigned short )0;
  sqlstm.sqhstv[64] = (unsigned char  *)(pSource->asCalledGroupID);
  sqlstm.sqhstl[64] = (unsigned long )16;
  sqlstm.sqhsts[64] = (         int  )16;
  sqlstm.sqindv[64] = (         short *)0;
  sqlstm.sqinds[64] = (         int  )0;
  sqlstm.sqharm[64] = (unsigned long )0;
  sqlstm.sqharc[64] = (unsigned long  *)0;
  sqlstm.sqadto[64] = (unsigned short )0;
  sqlstm.sqtdso[64] = (unsigned short )0;
  sqlstm.sqhstv[65] = (unsigned char  *)(pSource->asStlObject);
  sqlstm.sqhstl[65] = (unsigned long )19;
  sqlstm.sqhsts[65] = (         int  )19;
  sqlstm.sqindv[65] = (         short *)0;
  sqlstm.sqinds[65] = (         int  )0;
  sqlstm.sqharm[65] = (unsigned long )0;
  sqlstm.sqharc[65] = (unsigned long  *)0;
  sqlstm.sqadto[65] = (unsigned short )0;
  sqlstm.sqtdso[65] = (unsigned short )0;
  sqlstm.sqhstv[66] = (unsigned char  *)(pSource->asProdPropID);
  sqlstm.sqhstl[66] = (unsigned long )19;
  sqlstm.sqhsts[66] = (         int  )19;
  sqlstm.sqindv[66] = (         short *)0;
  sqlstm.sqinds[66] = (         int  )0;
  sqlstm.sqharm[66] = (unsigned long )0;
  sqlstm.sqharc[66] = (unsigned long  *)0;
  sqlstm.sqadto[66] = (unsigned short )0;
  sqlstm.sqtdso[66] = (unsigned short )0;
  sqlstm.sqhstv[67] = (unsigned char  *)(pSource->asCallingSubType);
  sqlstm.sqhstl[67] = (unsigned long )19;
  sqlstm.sqhsts[67] = (         int  )19;
  sqlstm.sqindv[67] = (         short *)0;
  sqlstm.sqinds[67] = (         int  )0;
  sqlstm.sqharm[67] = (unsigned long )0;
  sqlstm.sqharc[67] = (unsigned long  *)0;
  sqlstm.sqadto[67] = (unsigned short )0;
  sqlstm.sqtdso[67] = (unsigned short )0;
  sqlstm.sqhstv[68] = (unsigned char  *)(pSource->asCalledSubType);
  sqlstm.sqhstl[68] = (unsigned long )19;
  sqlstm.sqhsts[68] = (         int  )19;
  sqlstm.sqindv[68] = (         short *)0;
  sqlstm.sqinds[68] = (         int  )0;
  sqlstm.sqharm[68] = (unsigned long )0;
  sqlstm.sqharc[68] = (unsigned long  *)0;
  sqlstm.sqadto[68] = (unsigned short )0;
  sqlstm.sqtdso[68] = (unsigned short )0;
  sqlstm.sqhstv[69] = (unsigned char  *)(pSource->aiStlDirection);
  sqlstm.sqhstl[69] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[69] = (         int  )sizeof(int);
  sqlstm.sqindv[69] = (         short *)0;
  sqlstm.sqinds[69] = (         int  )0;
  sqlstm.sqharm[69] = (unsigned long )0;
  sqlstm.sqharc[69] = (unsigned long  *)0;
  sqlstm.sqadto[69] = (unsigned short )0;
  sqlstm.sqtdso[69] = (unsigned short )0;
  sqlstm.sqhstv[70] = (unsigned char  *)(pSource->asPreCallType);
  sqlstm.sqhstl[70] = (unsigned long )31;
  sqlstm.sqhsts[70] = (         int  )31;
  sqlstm.sqindv[70] = (         short *)0;
  sqlstm.sqinds[70] = (         int  )0;
  sqlstm.sqharm[70] = (unsigned long )0;
  sqlstm.sqharc[70] = (unsigned long  *)0;
  sqlstm.sqadto[70] = (unsigned short )0;
  sqlstm.sqtdso[70] = (unsigned short )0;
  sqlstm.sqhstv[71] = (unsigned char  *)(pSource->asTurnCode);
  sqlstm.sqhstl[71] = (unsigned long )51;
  sqlstm.sqhsts[71] = (         int  )51;
  sqlstm.sqindv[71] = (         short *)0;
  sqlstm.sqinds[71] = (         int  )0;
  sqlstm.sqharm[71] = (unsigned long )0;
  sqlstm.sqharc[71] = (unsigned long  *)0;
  sqlstm.sqadto[71] = (unsigned short )0;
  sqlstm.sqtdso[71] = (unsigned short )0;
  sqlstm.sqhstv[72] = (unsigned char  *)(pSource->asTurnCodeCompanyID);
  sqlstm.sqhstl[72] = (unsigned long )11;
  sqlstm.sqhsts[72] = (         int  )11;
  sqlstm.sqindv[72] = (         short *)0;
  sqlstm.sqinds[72] = (         int  )0;
  sqlstm.sqharm[72] = (unsigned long )0;
  sqlstm.sqharc[72] = (unsigned long  *)0;
  sqlstm.sqadto[72] = (unsigned short )0;
  sqlstm.sqtdso[72] = (unsigned short )0;
  sqlstm.sqhstv[73] = (unsigned char  *)(pSource->asTurnCodeProvinceID);
  sqlstm.sqhstl[73] = (unsigned long )21;
  sqlstm.sqhsts[73] = (         int  )21;
  sqlstm.sqindv[73] = (         short *)0;
  sqlstm.sqinds[73] = (         int  )0;
  sqlstm.sqharm[73] = (unsigned long )0;
  sqlstm.sqharc[73] = (unsigned long  *)0;
  sqlstm.sqadto[73] = (unsigned short )0;
  sqlstm.sqtdso[73] = (unsigned short )0;
  sqlstm.sqhstv[74] = (unsigned char  *)(pSource->aiTurnCodeCityID);
  sqlstm.sqhstl[74] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[74] = (         int  )sizeof(int);
  sqlstm.sqindv[74] = (         short *)0;
  sqlstm.sqinds[74] = (         int  )0;
  sqlstm.sqharm[74] = (unsigned long )0;
  sqlstm.sqharc[74] = (unsigned long  *)0;
  sqlstm.sqadto[74] = (unsigned short )0;
  sqlstm.sqtdso[74] = (unsigned short )0;
  sqlstm.sqhstv[75] = (unsigned char  *)(pSource->asTurnCodeOperationTypeGrade);
  sqlstm.sqhstl[75] = (unsigned long )31;
  sqlstm.sqhsts[75] = (         int  )31;
  sqlstm.sqindv[75] = (         short *)0;
  sqlstm.sqinds[75] = (         int  )0;
  sqlstm.sqharm[75] = (unsigned long )0;
  sqlstm.sqharc[75] = (unsigned long  *)0;
  sqlstm.sqadto[75] = (unsigned short )0;
  sqlstm.sqtdso[75] = (unsigned short )0;
  sqlstm.sqhstv[76] = (unsigned char  *)(pSource->asTurnType);
  sqlstm.sqhstl[76] = (unsigned long )31;
  sqlstm.sqhsts[76] = (         int  )31;
  sqlstm.sqindv[76] = (         short *)0;
  sqlstm.sqinds[76] = (         int  )0;
  sqlstm.sqharm[76] = (unsigned long )0;
  sqlstm.sqharc[76] = (unsigned long  *)0;
  sqlstm.sqadto[76] = (unsigned short )0;
  sqlstm.sqtdso[76] = (unsigned short )0;
  sqlstm.sqhstv[77] = (unsigned char  *)(pSource->asTurnCdrID);
  sqlstm.sqhstl[77] = (unsigned long )5;
  sqlstm.sqhsts[77] = (         int  )5;
  sqlstm.sqindv[77] = (         short *)0;
  sqlstm.sqinds[77] = (         int  )0;
  sqlstm.sqharm[77] = (unsigned long )0;
  sqlstm.sqharc[77] = (unsigned long  *)0;
  sqlstm.sqadto[77] = (unsigned short )0;
  sqlstm.sqtdso[77] = (unsigned short )0;
  sqlstm.sqhstv[78] = (unsigned char  *)(pSource->asSecondCallingNumber);
  sqlstm.sqhstl[78] = (unsigned long )31;
  sqlstm.sqhsts[78] = (         int  )31;
  sqlstm.sqindv[78] = (         short *)0;
  sqlstm.sqinds[78] = (         int  )0;
  sqlstm.sqharm[78] = (unsigned long )0;
  sqlstm.sqharc[78] = (unsigned long  *)0;
  sqlstm.sqadto[78] = (unsigned short )0;
  sqlstm.sqtdso[78] = (unsigned short )0;
  sqlstm.sqhstv[79] = (unsigned char  *)(pSource->asSecondCallingAreaCode);
  sqlstm.sqhstl[79] = (unsigned long )11;
  sqlstm.sqhsts[79] = (         int  )11;
  sqlstm.sqindv[79] = (         short *)0;
  sqlstm.sqinds[79] = (         int  )0;
  sqlstm.sqharm[79] = (unsigned long )0;
  sqlstm.sqharc[79] = (unsigned long  *)0;
  sqlstm.sqadto[79] = (unsigned short )0;
  sqlstm.sqtdso[79] = (unsigned short )0;
  sqlstm.sqhstv[80] = (unsigned char  *)(pSource->asSecondCallingGroupID);
  sqlstm.sqhstl[80] = (unsigned long )31;
  sqlstm.sqhsts[80] = (         int  )31;
  sqlstm.sqindv[80] = (         short *)0;
  sqlstm.sqinds[80] = (         int  )0;
  sqlstm.sqharm[80] = (unsigned long )0;
  sqlstm.sqharc[80] = (unsigned long  *)0;
  sqlstm.sqadto[80] = (unsigned short )0;
  sqlstm.sqtdso[80] = (unsigned short )0;
  sqlstm.sqhstv[81] = (unsigned char  *)(pSource->asSecondCallingCompanyID);
  sqlstm.sqhstl[81] = (unsigned long )11;
  sqlstm.sqhsts[81] = (         int  )11;
  sqlstm.sqindv[81] = (         short *)0;
  sqlstm.sqinds[81] = (         int  )0;
  sqlstm.sqharm[81] = (unsigned long )0;
  sqlstm.sqharc[81] = (unsigned long  *)0;
  sqlstm.sqadto[81] = (unsigned short )0;
  sqlstm.sqtdso[81] = (unsigned short )0;
  sqlstm.sqhstv[82] = (unsigned char  *)(pSource->asPreCallParentCdrID);
  sqlstm.sqhstl[82] = (unsigned long )21;
  sqlstm.sqhsts[82] = (         int  )21;
  sqlstm.sqindv[82] = (         short *)0;
  sqlstm.sqinds[82] = (         int  )0;
  sqlstm.sqharm[82] = (unsigned long )0;
  sqlstm.sqharc[82] = (unsigned long  *)0;
  sqlstm.sqadto[82] = (unsigned short )0;
  sqlstm.sqtdso[82] = (unsigned short )0;
  sqlstm.sqhstv[83] = (unsigned char  *)(pSource->asPreCallSubCdrID);
  sqlstm.sqhstl[83] = (unsigned long )21;
  sqlstm.sqhsts[83] = (         int  )21;
  sqlstm.sqindv[83] = (         short *)0;
  sqlstm.sqinds[83] = (         int  )0;
  sqlstm.sqharm[83] = (unsigned long )0;
  sqlstm.sqharc[83] = (unsigned long  *)0;
  sqlstm.sqadto[83] = (unsigned short )0;
  sqlstm.sqtdso[83] = (unsigned short )0;
  sqlstm.sqhstv[84] = (unsigned char  *)(pSource->asPreCallSubCdrNum);
  sqlstm.sqhstl[84] = (unsigned long )5;
  sqlstm.sqhsts[84] = (         int  )5;
  sqlstm.sqindv[84] = (         short *)0;
  sqlstm.sqinds[84] = (         int  )0;
  sqlstm.sqharm[84] = (unsigned long )0;
  sqlstm.sqharc[84] = (unsigned long  *)0;
  sqlstm.sqadto[84] = (unsigned short )0;
  sqlstm.sqtdso[84] = (unsigned short )0;
  sqlstm.sqhstv[85] = (unsigned char  *)(pSource->asPreCallSubCdrSeq);
  sqlstm.sqhstl[85] = (unsigned long )11;
  sqlstm.sqhsts[85] = (         int  )11;
  sqlstm.sqindv[85] = (         short *)0;
  sqlstm.sqinds[85] = (         int  )0;
  sqlstm.sqharm[85] = (unsigned long )0;
  sqlstm.sqharc[85] = (unsigned long  *)0;
  sqlstm.sqadto[85] = (unsigned short )0;
  sqlstm.sqtdso[85] = (unsigned short )0;
  sqlstm.sqhstv[86] = (unsigned char  *)(pSource->asPreCallUsageEventID);
  sqlstm.sqhstl[86] = (unsigned long )19;
  sqlstm.sqhsts[86] = (         int  )19;
  sqlstm.sqindv[86] = (         short *)0;
  sqlstm.sqinds[86] = (         int  )0;
  sqlstm.sqharm[86] = (unsigned long )0;
  sqlstm.sqharc[86] = (unsigned long  *)0;
  sqlstm.sqadto[86] = (unsigned short )0;
  sqlstm.sqtdso[86] = (unsigned short )0;
  sqlstm.sqhstv[87] = (unsigned char  *)(pSource->asTurnParentCdrID);
  sqlstm.sqhstl[87] = (unsigned long )21;
  sqlstm.sqhsts[87] = (         int  )21;
  sqlstm.sqindv[87] = (         short *)0;
  sqlstm.sqinds[87] = (         int  )0;
  sqlstm.sqharm[87] = (unsigned long )0;
  sqlstm.sqharc[87] = (unsigned long  *)0;
  sqlstm.sqadto[87] = (unsigned short )0;
  sqlstm.sqtdso[87] = (unsigned short )0;
  sqlstm.sqhstv[88] = (unsigned char  *)(pSource->asTurnSubCdrID);
  sqlstm.sqhstl[88] = (unsigned long )21;
  sqlstm.sqhsts[88] = (         int  )21;
  sqlstm.sqindv[88] = (         short *)0;
  sqlstm.sqinds[88] = (         int  )0;
  sqlstm.sqharm[88] = (unsigned long )0;
  sqlstm.sqharc[88] = (unsigned long  *)0;
  sqlstm.sqadto[88] = (unsigned short )0;
  sqlstm.sqtdso[88] = (unsigned short )0;
  sqlstm.sqhstv[89] = (unsigned char  *)(pSource->asTurnSubCdrNum);
  sqlstm.sqhstl[89] = (unsigned long )5;
  sqlstm.sqhsts[89] = (         int  )5;
  sqlstm.sqindv[89] = (         short *)0;
  sqlstm.sqinds[89] = (         int  )0;
  sqlstm.sqharm[89] = (unsigned long )0;
  sqlstm.sqharc[89] = (unsigned long  *)0;
  sqlstm.sqadto[89] = (unsigned short )0;
  sqlstm.sqtdso[89] = (unsigned short )0;
  sqlstm.sqhstv[90] = (unsigned char  *)(pSource->asTurnSubCdrSeq);
  sqlstm.sqhstl[90] = (unsigned long )11;
  sqlstm.sqhsts[90] = (         int  )11;
  sqlstm.sqindv[90] = (         short *)0;
  sqlstm.sqinds[90] = (         int  )0;
  sqlstm.sqharm[90] = (unsigned long )0;
  sqlstm.sqharc[90] = (unsigned long  *)0;
  sqlstm.sqadto[90] = (unsigned short )0;
  sqlstm.sqtdso[90] = (unsigned short )0;
  sqlstm.sqhstv[91] = (unsigned char  *)(pSource->asTurnUsageEventID);
  sqlstm.sqhstl[91] = (unsigned long )19;
  sqlstm.sqhsts[91] = (         int  )19;
  sqlstm.sqindv[91] = (         short *)0;
  sqlstm.sqinds[91] = (         int  )0;
  sqlstm.sqharm[91] = (unsigned long )0;
  sqlstm.sqharc[91] = (unsigned long  *)0;
  sqlstm.sqadto[91] = (unsigned short )0;
  sqlstm.sqtdso[91] = (unsigned short )0;
  sqlstm.sqhstv[92] = (unsigned char  *)(pSource->asInTrunkGenre);
  sqlstm.sqhstl[92] = (unsigned long )21;
  sqlstm.sqhsts[92] = (         int  )21;
  sqlstm.sqindv[92] = (         short *)0;
  sqlstm.sqinds[92] = (         int  )0;
  sqlstm.sqharm[92] = (unsigned long )0;
  sqlstm.sqharc[92] = (unsigned long  *)0;
  sqlstm.sqadto[92] = (unsigned short )0;
  sqlstm.sqtdso[92] = (unsigned short )0;
  sqlstm.sqhstv[93] = (unsigned char  *)(pSource->asOutTrunkGenre);
  sqlstm.sqhstl[93] = (unsigned long )21;
  sqlstm.sqhsts[93] = (         int  )21;
  sqlstm.sqindv[93] = (         short *)0;
  sqlstm.sqinds[93] = (         int  )0;
  sqlstm.sqharm[93] = (unsigned long )0;
  sqlstm.sqharc[93] = (unsigned long  *)0;
  sqlstm.sqadto[93] = (unsigned short )0;
  sqlstm.sqtdso[93] = (unsigned short )0;
  sqlstm.sqhstv[94] = (unsigned char  *)(pSource->asInTrunkNetType);
  sqlstm.sqhstl[94] = (unsigned long )21;
  sqlstm.sqhsts[94] = (         int  )21;
  sqlstm.sqindv[94] = (         short *)0;
  sqlstm.sqinds[94] = (         int  )0;
  sqlstm.sqharm[94] = (unsigned long )0;
  sqlstm.sqharc[94] = (unsigned long  *)0;
  sqlstm.sqadto[94] = (unsigned short )0;
  sqlstm.sqtdso[94] = (unsigned short )0;
  sqlstm.sqhstv[95] = (unsigned char  *)(pSource->asOutTrunkNetType);
  sqlstm.sqhstl[95] = (unsigned long )21;
  sqlstm.sqhsts[95] = (         int  )21;
  sqlstm.sqindv[95] = (         short *)0;
  sqlstm.sqinds[95] = (         int  )0;
  sqlstm.sqharm[95] = (unsigned long )0;
  sqlstm.sqharc[95] = (unsigned long  *)0;
  sqlstm.sqadto[95] = (unsigned short )0;
  sqlstm.sqtdso[95] = (unsigned short )0;
  sqlstm.sqhstv[96] = (unsigned char  *)(pSource->asCallingNumberType);
  sqlstm.sqhstl[96] = (unsigned long )21;
  sqlstm.sqhsts[96] = (         int  )21;
  sqlstm.sqindv[96] = (         short *)0;
  sqlstm.sqinds[96] = (         int  )0;
  sqlstm.sqharm[96] = (unsigned long )0;
  sqlstm.sqharc[96] = (unsigned long  *)0;
  sqlstm.sqadto[96] = (unsigned short )0;
  sqlstm.sqtdso[96] = (unsigned short )0;
  sqlstm.sqhstv[97] = (unsigned char  *)(pSource->asCalledNumberType);
  sqlstm.sqhstl[97] = (unsigned long )21;
  sqlstm.sqhsts[97] = (         int  )21;
  sqlstm.sqindv[97] = (         short *)0;
  sqlstm.sqinds[97] = (         int  )0;
  sqlstm.sqharm[97] = (unsigned long )0;
  sqlstm.sqharc[97] = (unsigned long  *)0;
  sqlstm.sqadto[97] = (unsigned short )0;
  sqlstm.sqtdso[97] = (unsigned short )0;
  sqlstm.sqhstv[98] = (unsigned char  *)(pSource->asCallingDomainID);
  sqlstm.sqhstl[98] = (unsigned long )21;
  sqlstm.sqhsts[98] = (         int  )21;
  sqlstm.sqindv[98] = (         short *)0;
  sqlstm.sqinds[98] = (         int  )0;
  sqlstm.sqharm[98] = (unsigned long )0;
  sqlstm.sqharc[98] = (unsigned long  *)0;
  sqlstm.sqadto[98] = (unsigned short )0;
  sqlstm.sqtdso[98] = (unsigned short )0;
  sqlstm.sqhstv[99] = (unsigned char  *)(pSource->asCalledDomainID);
  sqlstm.sqhstl[99] = (unsigned long )21;
  sqlstm.sqhsts[99] = (         int  )21;
  sqlstm.sqindv[99] = (         short *)0;
  sqlstm.sqinds[99] = (         int  )0;
  sqlstm.sqharm[99] = (unsigned long )0;
  sqlstm.sqharc[99] = (unsigned long  *)0;
  sqlstm.sqadto[99] = (unsigned short )0;
  sqlstm.sqtdso[99] = (unsigned short )0;
  sqlstm.sqhstv[100] = (unsigned char  *)(pSource->asSecondSubType);
  sqlstm.sqhstl[100] = (unsigned long )21;
  sqlstm.sqhsts[100] = (         int  )21;
  sqlstm.sqindv[100] = (         short *)0;
  sqlstm.sqinds[100] = (         int  )0;
  sqlstm.sqharm[100] = (unsigned long )0;
  sqlstm.sqharc[100] = (unsigned long  *)0;
  sqlstm.sqadto[100] = (unsigned short )0;
  sqlstm.sqtdso[100] = (unsigned short )0;
  sqlstm.sqhstv[101] = (unsigned char  *)(pSource->asSecondCallingRoamnumber);
  sqlstm.sqhstl[101] = (unsigned long )31;
  sqlstm.sqhsts[101] = (         int  )31;
  sqlstm.sqindv[101] = (         short *)0;
  sqlstm.sqinds[101] = (         int  )0;
  sqlstm.sqharm[101] = (unsigned long )0;
  sqlstm.sqharc[101] = (unsigned long  *)0;
  sqlstm.sqadto[101] = (unsigned short )0;
  sqlstm.sqtdso[101] = (unsigned short )0;
  sqlstm.sqhstv[102] = (unsigned char  *)(pSource->asViewCall);
  sqlstm.sqhstl[102] = (unsigned long )11;
  sqlstm.sqhsts[102] = (         int  )11;
  sqlstm.sqindv[102] = (         short *)0;
  sqlstm.sqinds[102] = (         int  )0;
  sqlstm.sqharm[102] = (unsigned long )0;
  sqlstm.sqharc[102] = (unsigned long  *)0;
  sqlstm.sqadto[102] = (unsigned short )0;
  sqlstm.sqtdso[102] = (unsigned short )0;
  sqlstm.sqhstv[103] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[103] = (unsigned long )3;
  sqlstm.sqhsts[103] = (         int  )3;
  sqlstm.sqindv[103] = (         short *)0;
  sqlstm.sqinds[103] = (         int  )0;
  sqlstm.sqharm[103] = (unsigned long )0;
  sqlstm.sqharc[103] = (unsigned long  *)0;
  sqlstm.sqadto[103] = (unsigned short )0;
  sqlstm.sqtdso[103] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch T_TEMPLATE_YD_GW_UECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE T_TEMPLATE_YD_GW_UECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )485;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=T_TEMPLATE_YD_GW_UE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sUsageEventID,		pSource->asUsageEventID[iCurPos]);
		strcpy(p->sProdID,			pSource->asProdID[iCurPos]);
		strcpy(p->sStartTime,			pSource->asStartTime[iCurPos]);
		strcpy(p->sEndTime,			pSource->asEndTime[iCurPos]);
		strcpy(p->sRateTime,			pSource->asRateTime[iCurPos]);
		strcpy(p->sOperationTypeID,		pSource->asOperationTypeID[iCurPos]);
		strcpy(p->sCallingNumber,		pSource->asCallingNumber[iCurPos]);
		strcpy(p->sCalledNumber,		pSource->asCalledNumber[iCurPos]);
		strcpy(p->sBilledNumber,		pSource->asBilledNumber[iCurPos]);
		strcpy(p->sThirdNumber,			pSource->asThirdNumber[iCurPos]);

		p->iCallingAreaID=			pSource->aiCallingAreaID[iCurPos];
		p->iCalledAreaID=			pSource->aiCalledAreaID[iCurPos];

		strcpy(p->sInTrunkNumber,		pSource->asInTrunkNumber[iCurPos]);
		strcpy(p->sOutTrunkNumber,		pSource->asOutTrunkNumber[iCurPos]);

		p->iRawUnitType=			pSource->aiRawUnitType[iCurPos];

		strcpy(p->sRawUnits,			pSource->asRawUnits[iCurPos]);

		p->iRateUnitType=			pSource->aiRateUnitType[iCurPos];

		strcpy(p->sIsFree,			pSource->asIsFree[iCurPos]);

		p->iRateUnits=				pSource->aiRateUnits[iCurPos];

		strcpy(p->sCallingAreaCode,		pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCalledAreaCode,		pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sCallingRoamNumber,		pSource->asCallingRoamNumber[iCurPos]);
		strcpy(p->sCalledRoamNumber,		pSource->asCalledRoamNumber[iCurPos]);
		strcpy(p->sCallingRoamAreaCode,		pSource->asCallingRoamAreaCode[iCurPos]);
		strcpy(p->sCalledRoamAreaCode,		pSource->asCalledRoamAreaCode[iCurPos]);
		strcpy(p->sTotalDueAmount,		pSource->asTotalDueAmount[iCurPos]);

		p->iProdInstID=				pSource->aiProdInstID[iCurPos];
		p->iRateID=				pSource->aiRateID[iCurPos];

		strcpy(p->sUpFlux,			pSource->asUpFlux[iCurPos]);
		strcpy(p->sDuration,			pSource->asDuration[iCurPos]);

		p->iCityID=				pSource->aiCityID[iCurPos];

		strcpy(p->sDownFlux,			pSource->asDownFlux[iCurPos]);
		strcpy(p->sFileName,			pSource->asFileName[iCurPos]);
		strcpy(p->sTotalFlux,			pSource->asTotalFlux[iCurPos]);
		strcpy(p->sStatus,			pSource->asStatus[iCurPos]);

		p->iBillCycleSeq=			pSource->aiBillCycleSeq[iCurPos];

		strcpy(p->sCurrBalance,			pSource->asCurrBalance[iCurPos]);

		p->iCreateCycleSeq=			pSource->aiCreateCycleSeq[iCurPos];

		strcpy(p->sRateKey1,			pSource->asRateKey1[iCurPos]);
		strcpy(p->sRateKey2,			pSource->asRateKey2[iCurPos]);
		strcpy(p->sRateKey3,			pSource->asRateKey3[iCurPos]);

		p->iPureCycleSeq=			pSource->aiPureCycleSeq[iCurPos];
		p->iDirection=				pSource->aiDirection[iCurPos];
		p->iFileClassID=			pSource->aiFileClassID[iCurPos];

		strcpy(p->sExceptionType,		pSource->asExceptionType[iCurPos]);
		strcpy(p->sOrigUsageTypeID,		pSource->asOrigUsageTypeID[iCurPos]);

		p->iTotalDueUnits=			pSource->aiTotalDueUnits[iCurPos];

		strcpy(p->sStlAmount,			pSource->asStlAmount[iCurPos]);
		strcpy(p->sPostFlag,			pSource->asPostFlag[iCurPos]);

		p->iIsPrepay=				pSource->aiIsPrepay[iCurPos];
		p->iFileID=				pSource->aiFileID[iCurPos];
		p->iParentFileID=			pSource->aiParentFileID[iCurPos];

		strcpy(p->sTableName,			pSource->asTableName[iCurPos]);
		strcpy(p->sCallingCompanyID,		pSource->asCallingCompanyID[iCurPos]);
		strcpy(p->sCalledCompanyID,		pSource->asCalledCompanyID[iCurPos]);
		strcpy(p->sSwitchCompanyID,		pSource->asSwitchCompanyID[iCurPos]);
		strcpy(p->sProvinceID,			pSource->asProvinceID[iCurPos]);
		strcpy(p->sDurationMinnum,		pSource->asDurationMinnum[iCurPos]);
		strcpy(p->sDurationSec6,		pSource->asDurationSec6[iCurPos]);
		strcpy(p->sInTrunkGroup,		pSource->asInTrunkGroup[iCurPos]);
		strcpy(p->sOutTrunkGroup,		pSource->asOutTrunkGroup[iCurPos]);
		strcpy(p->sCallingNumberCompanyID,	pSource->asCallingNumberCompanyID[iCurPos]);
		strcpy(p->sCalledNumberCompanyID,	pSource->asCalledNumberCompanyID[iCurPos]);
		strcpy(p->sCallingGroupID,		pSource->asCallingGroupID[iCurPos]);
		strcpy(p->sCalledGroupID,		pSource->asCalledGroupID[iCurPos]);
		strcpy(p->sStlObject,			pSource->asStlObject[iCurPos]);
		strcpy(p->sProdPropID,			pSource->asProdPropID[iCurPos]);
		strcpy(p->sCallingSubType,		pSource->asCallingSubType[iCurPos]);
		strcpy(p->sCalledSubType,		pSource->asCalledSubType[iCurPos]);

		p->iStlDirection=			pSource->aiStlDirection[iCurPos];

		strcpy(p->sPreCallType,			pSource->asPreCallType[iCurPos]);
		strcpy(p->sTurnCode,			pSource->asTurnCode[iCurPos]);
		strcpy(p->sTurnCodeCompanyID,		pSource->asTurnCodeCompanyID[iCurPos]);
		strcpy(p->sTurnCodeProvinceID,		pSource->asTurnCodeProvinceID[iCurPos]);

		p->iTurnCodeCityID=			pSource->aiTurnCodeCityID[iCurPos];

		strcpy(p->sTurnCodeOperationTypeGrade,	pSource->asTurnCodeOperationTypeGrade[iCurPos]);
		strcpy(p->sTurnType,			pSource->asTurnType[iCurPos]);
		strcpy(p->sTurnCdrID,			pSource->asTurnCdrID[iCurPos]);
		strcpy(p->sSecondCallingNumber,		pSource->asSecondCallingNumber[iCurPos]);
		strcpy(p->sSecondCallingAreaCode,	pSource->asSecondCallingAreaCode[iCurPos]);
		strcpy(p->sSecondCallingGroupID,	pSource->asSecondCallingGroupID[iCurPos]);
		strcpy(p->sSecondCallingCompanyID,	pSource->asSecondCallingCompanyID[iCurPos]);
		strcpy(p->sPreCallParentCdrID,		pSource->asPreCallParentCdrID[iCurPos]);
		strcpy(p->sPreCallSubCdrID,		pSource->asPreCallSubCdrID[iCurPos]);
		strcpy(p->sPreCallSubCdrNum,		pSource->asPreCallSubCdrNum[iCurPos]);
		strcpy(p->sPreCallSubCdrSeq,		pSource->asPreCallSubCdrSeq[iCurPos]);
		strcpy(p->sPreCallUsageEventID,		pSource->asPreCallUsageEventID[iCurPos]);
		strcpy(p->sTurnParentCdrID,		pSource->asTurnParentCdrID[iCurPos]);
		strcpy(p->sTurnSubCdrID,		pSource->asTurnSubCdrID[iCurPos]);
		strcpy(p->sTurnSubCdrNum,		pSource->asTurnSubCdrNum[iCurPos]);
		strcpy(p->sTurnSubCdrSeq,		pSource->asTurnSubCdrSeq[iCurPos]);
		strcpy(p->sTurnUsageEventID,		pSource->asTurnUsageEventID[iCurPos]);
		strcpy(p->sInTrunkGenre,		pSource->asInTrunkGenre[iCurPos]);
		strcpy(p->sOutTrunkGenre,		pSource->asOutTrunkGenre[iCurPos]);
		strcpy(p->sInTrunkNetType,		pSource->asInTrunkNetType[iCurPos]);
		strcpy(p->sOutTrunkNetType,		pSource->asOutTrunkNetType[iCurPos]);
		strcpy(p->sCallingNumberType,		pSource->asCallingNumberType[iCurPos]);
		strcpy(p->sCalledNumberType,		pSource->asCalledNumberType[iCurPos]);
		strcpy(p->sCallingDomainID,		pSource->asCallingDomainID[iCurPos]);
		strcpy(p->sCalledDomainID,		pSource->asCalledDomainID[iCurPos]);
		strcpy(p->sSecondSubType,		pSource->asSecondSubType[iCurPos]);
		strcpy(p->sSecondCallingRoamnumber,	pSource->asSecondCallingRoamnumber[iCurPos]);
		strcpy(p->sViewCall,			pSource->asViewCall[iCurPos]);
		strcpy(p->sGroupID,			pSource->asGroupID[iCurPos]);

		AllTrim(p->sUsageEventID);
		AllTrim(p->sProdID);
		AllTrim(p->sStartTime);
		AllTrim(p->sEndTime);
		AllTrim(p->sRateTime);
		AllTrim(p->sOperationTypeID);
		AllTrim(p->sCallingNumber);
		AllTrim(p->sCalledNumber);
		AllTrim(p->sBilledNumber);
		AllTrim(p->sThirdNumber);
		AllTrim(p->sInTrunkNumber);
		AllTrim(p->sOutTrunkNumber);
		AllTrim(p->sRawUnits);
		AllTrim(p->sIsFree);
		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sCallingRoamNumber);
		AllTrim(p->sCalledRoamNumber);
		AllTrim(p->sCallingRoamAreaCode);
		AllTrim(p->sCalledRoamAreaCode);
		AllTrim(p->sTotalDueAmount);
		AllTrim(p->sUpFlux);
		AllTrim(p->sDuration);
		AllTrim(p->sDownFlux);
		AllTrim(p->sFileName);
		AllTrim(p->sTotalFlux);
		AllTrim(p->sStatus);
		AllTrim(p->sCurrBalance);
		AllTrim(p->sRateKey1);
		AllTrim(p->sRateKey2);
		AllTrim(p->sRateKey3);
		AllTrim(p->sExceptionType);
		AllTrim(p->sOrigUsageTypeID);
		AllTrim(p->sStlAmount);
		AllTrim(p->sPostFlag);
		AllTrim(p->sTableName);
		AllTrim(p->sCallingCompanyID);
		AllTrim(p->sCalledCompanyID);
		AllTrim(p->sSwitchCompanyID);
		AllTrim(p->sProvinceID);
		AllTrim(p->sDurationMinnum);
		AllTrim(p->sDurationSec6);
		AllTrim(p->sInTrunkGroup);
		AllTrim(p->sOutTrunkGroup);
		AllTrim(p->sCallingNumberCompanyID);
		AllTrim(p->sCalledNumberCompanyID);
		AllTrim(p->sCallingGroupID);
		AllTrim(p->sCalledGroupID);
		AllTrim(p->sStlObject);
		AllTrim(p->sProdPropID);
		AllTrim(p->sCallingSubType);
		AllTrim(p->sCalledSubType);
		AllTrim(p->sPreCallType);
		AllTrim(p->sTurnCode);
		AllTrim(p->sTurnCodeCompanyID);
		AllTrim(p->sTurnCodeProvinceID);
		AllTrim(p->sTurnCodeOperationTypeGrade);
		AllTrim(p->sTurnType);
		AllTrim(p->sTurnCdrID);
		AllTrim(p->sSecondCallingNumber);
		AllTrim(p->sSecondCallingAreaCode);
		AllTrim(p->sSecondCallingGroupID);
		AllTrim(p->sSecondCallingCompanyID);
		AllTrim(p->sPreCallParentCdrID);
		AllTrim(p->sPreCallSubCdrID);
		AllTrim(p->sPreCallSubCdrNum);
		AllTrim(p->sPreCallSubCdrSeq);
		AllTrim(p->sPreCallUsageEventID);
		AllTrim(p->sTurnParentCdrID);
		AllTrim(p->sTurnSubCdrID);
		AllTrim(p->sTurnSubCdrNum);
		AllTrim(p->sTurnSubCdrSeq);
		AllTrim(p->sTurnUsageEventID);
		AllTrim(p->sInTrunkGenre);
		AllTrim(p->sOutTrunkGenre);
		AllTrim(p->sInTrunkNetType);
		AllTrim(p->sOutTrunkNetType);
		AllTrim(p->sCallingNumberType);
		AllTrim(p->sCalledNumberType);
		AllTrim(p->sCallingDomainID);
		AllTrim(p->sCalledDomainID);
		AllTrim(p->sSecondSubType);
		AllTrim(p->sSecondCallingRoamnumber);
		AllTrim(p->sViewCall);
		AllTrim(p->sGroupID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_ttemplateydgwue(struct TTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po)
{/*数据移动部分*/

	memset((void*)po,0,sizeof(struct TTemplateYdGwUeStruct));

		strncpy(po->sUsageEventID,		pi->sUsageEventID,18);
		strncpy(po->sProdID,			pi->sProdID,10);
		strncpy(po->sStartTime,			pi->sStartTime,14);
		strncpy(po->sEndTime,			pi->sEndTime,14);
		strncpy(po->sRateTime,			pi->sRateTime,14);
		strncpy(po->sOperationTypeID,		pi->sOperationTypeID,8);
		strncpy(po->sCallingNumber,		pi->sCallingNumber,30);
		strncpy(po->sCalledNumber,		pi->sCalledNumber,30);
		strncpy(po->sBilledNumber,		pi->sBilledNumber,30);
		strncpy(po->sThirdNumber,		pi->sThirdNumber,30);

		po->iCallingAreaID=			pi->iCallingAreaID;
		po->iCalledAreaID=			pi->iCalledAreaID;

		strncpy(po->sInTrunkNumber,		pi->sInTrunkNumber,20);
		strncpy(po->sOutTrunkNumber,		pi->sOutTrunkNumber,20);

		po->iRawUnitType=			pi->iRawUnitType;

		strncpy(po->sRawUnits,			pi->sRawUnits,18);

		po->iRateUnitType=			pi->iRateUnitType;

		strncpy(po->sIsFree,			pi->sIsFree,20);

		po->iRateUnits=				pi->iRateUnits;

		strncpy(po->sCallingAreaCode,		pi->sCallingAreaCode,10);
		strncpy(po->sCalledAreaCode,		pi->sCalledAreaCode,10);
		strncpy(po->sCallingRoamNumber,		pi->sCallingRoamNumber,30);
		strncpy(po->sCalledRoamNumber,		pi->sCalledRoamNumber,30);
		strncpy(po->sCallingRoamAreaCode,	pi->sCallingRoamAreaCode,10);
		strncpy(po->sCalledRoamAreaCode,	pi->sCalledRoamAreaCode,10);
		strncpy(po->sTotalDueAmount,		pi->sTotalDueAmount,18);

		po->iProdInstID=			pi->iProdInstID;
		po->iRateID=				pi->iRateID;

		strncpy(po->sUpFlux,			pi->sUpFlux,18);
		strncpy(po->sDuration,			pi->sDuration,18);

		po->iCityID=				pi->iCityID;

		strncpy(po->sDownFlux,			pi->sDownFlux,18);
		strncpy(po->sFileName,			pi->sFileName,60);
		strncpy(po->sTotalFlux,			pi->sTotalFlux,18);
		strncpy(po->sStatus,			pi->sStatus,3);

		po->iBillCycleSeq=			pi->iBillCycleSeq;

		strncpy(po->sCurrBalance,		pi->sCurrBalance,18);

		po->iCreateCycleSeq=			pi->iCreateCycleSeq;

		strncpy(po->sRateKey1,			pi->sRateKey1,30);
		strncpy(po->sRateKey2,			pi->sRateKey2,30);
		strncpy(po->sRateKey3,			pi->sRateKey3,30);

		po->iPureCycleSeq=			pi->iPureCycleSeq;
		po->iDirection=				pi->iDirection;
		po->iFileClassID=			pi->iFileClassID;

		strncpy(po->sExceptionType,		pi->sExceptionType,5);
		strncpy(po->sOrigUsageTypeID,		pi->sOrigUsageTypeID,12);

		po->iTotalDueUnits=			pi->iTotalDueUnits;

		strncpy(po->sStlAmount,			pi->sStlAmount,18);
		strncpy(po->sPostFlag,			pi->sPostFlag,4);

		po->iIsPrepay=				pi->iIsPrepay;
		po->iFileID=				pi->iFileID;
		po->iParentFileID=			pi->iParentFileID;

		strncpy(po->sTableName,			pi->sTableName,30);
		strncpy(po->sCallingCompanyID,		pi->sCallingCompanyID,18);
		strncpy(po->sCalledCompanyID,		pi->sCalledCompanyID,18);
		strncpy(po->sSwitchCompanyID,		pi->sSwitchCompanyID,18);
		strncpy(po->sProvinceID,		pi->sProvinceID,20);
		strncpy(po->sDurationMinnum,		pi->sDurationMinnum,18);
		strncpy(po->sDurationSec6,		pi->sDurationSec6,18);
		strncpy(po->sInTrunkGroup,		pi->sInTrunkGroup,15);
		strncpy(po->sOutTrunkGroup,		pi->sOutTrunkGroup,15);
		strncpy(po->sCallingNumberCompanyID,	pi->sCallingNumberCompanyID,18);
		strncpy(po->sCalledNumberCompanyID,	pi->sCalledNumberCompanyID,18);
		strncpy(po->sCallingGroupID,		pi->sCallingGroupID,15);
		strncpy(po->sCalledGroupID,		pi->sCalledGroupID,15);
		strncpy(po->sStlObject,			pi->sStlObject,18);
		strncpy(po->sProdPropID,		pi->sProdPropID,18);
		strncpy(po->sCallingSubType,		pi->sCallingSubType,18);
		strncpy(po->sCalledSubType,		pi->sCalledSubType,18);

		po->iStlDirection=			pi->iStlDirection;

		strncpy(po->sPreCallType,		pi->sPreCallType,30);
		strncpy(po->sTurnCode,			pi->sTurnCode,50);
		strncpy(po->sTurnCodeCompanyID,		pi->sTurnCodeCompanyID,10);
		strncpy(po->sTurnCodeProvinceID,	pi->sTurnCodeProvinceID,20);

		po->iTurnCodeCityID=			pi->iTurnCodeCityID;

		strncpy(po->sTurnCodeOperationTypeGrade,pi->sTurnCodeOperationTypeGrade,30);
		strncpy(po->sTurnType,			pi->sTurnType,30);
		strncpy(po->sTurnCdrID,			pi->sTurnCdrID,4);
		strncpy(po->sSecondCallingNumber,	pi->sSecondCallingNumber,30);
		strncpy(po->sSecondCallingAreaCode,	pi->sSecondCallingAreaCode,10);
		strncpy(po->sSecondCallingGroupID,	pi->sSecondCallingGroupID,30);
		strncpy(po->sSecondCallingCompanyID,	pi->sSecondCallingCompanyID,10);
		strncpy(po->sPreCallParentCdrID,	pi->sPreCallParentCdrID,20);
		strncpy(po->sPreCallSubCdrID,		pi->sPreCallSubCdrID,20);
		strncpy(po->sPreCallSubCdrNum,		pi->sPreCallSubCdrNum,4);
		strncpy(po->sPreCallSubCdrSeq,		pi->sPreCallSubCdrSeq,10);
		strncpy(po->sPreCallUsageEventID,	pi->sPreCallUsageEventID,18);
		strncpy(po->sTurnParentCdrID,		pi->sTurnParentCdrID,20);
		strncpy(po->sTurnSubCdrID,		pi->sTurnSubCdrID,20);
		strncpy(po->sTurnSubCdrNum,		pi->sTurnSubCdrNum,4);
		strncpy(po->sTurnSubCdrSeq,		pi->sTurnSubCdrSeq,10);
		strncpy(po->sTurnUsageEventID,		pi->sTurnUsageEventID,18);
		strncpy(po->sInTrunkGenre,		pi->sInTrunkGenre,20);
		strncpy(po->sOutTrunkGenre,		pi->sOutTrunkGenre,20);
		strncpy(po->sInTrunkNetType,		pi->sInTrunkNetType,20);
		strncpy(po->sOutTrunkNetType,		pi->sOutTrunkNetType,20);
		strncpy(po->sCallingNumberType,		pi->sCallingNumberType,20);
		strncpy(po->sCalledNumberType,		pi->sCalledNumberType,20);
		strncpy(po->sCallingDomainID,		pi->sCallingDomainID,20);
		strncpy(po->sCalledDomainID,		pi->sCalledDomainID,20);
		strncpy(po->sSecondSubType,		pi->sSecondSubType,20);
		strncpy(po->sSecondCallingRoamnumber,	pi->sSecondCallingRoamnumber,30);
		strncpy(po->sViewCall,			pi->sViewCall,10);
}
void mvitem_fmttemplateydgwue(struct FTTemplateYdGwUeStruct *pi,struct TTemplateYdGwUeStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	memset((void*)po,0,sizeof(struct TTemplateYdGwUeStruct));

		strncpy(po->sUsageEventID,		pi->sUsageEventID,18);
		strncpy(po->sProdID,			pi->sProdID,10);
		strncpy(po->sStartTime,			pi->sStartTime,14);
		strncpy(po->sEndTime,			pi->sEndTime,14);
		strncpy(po->sRateTime,			pi->sRateTime,14);
		strncpy(po->sOperationTypeID,		pi->sOperationTypeID,8);
		strncpy(po->sCallingNumber,		pi->sCallingNumber,30);
		strncpy(po->sCalledNumber,		pi->sCalledNumber,30);
		strncpy(po->sBilledNumber,		pi->sBilledNumber,30);
		strncpy(po->sThirdNumber,		pi->sThirdNumber,30);

		strncpy(sTemp,		pi->sCallingAreaID,8);sTemp[8]=0;
		po->iCallingAreaID=atoi(sTemp);
		strncpy(sTemp,		pi->sCalledAreaID,8);sTemp[8]=0;
		po->iCalledAreaID=atoi(sTemp);

		strncpy(po->sInTrunkNumber,		pi->sInTrunkNumber,20);
		strncpy(po->sOutTrunkNumber,		pi->sOutTrunkNumber,20);

		strncpy(sTemp,		pi->sRawUnitType,4);sTemp[4]=0;
		po->iRawUnitType=atoi(sTemp);

		strncpy(po->sRawUnits,			pi->sRawUnits,18);

		strncpy(sTemp,		pi->sRateUnitType,4);sTemp[4]=0;
		po->iRateUnitType=atoi(sTemp);

		strncpy(po->sIsFree,			pi->sIsFree,20);

		strncpy(sTemp,			pi->sRateUnits,8);sTemp[8]=0;
		po->iRateUnits=atoi(sTemp);

		strncpy(po->sCallingAreaCode,		pi->sCallingAreaCode,10);
		strncpy(po->sCalledAreaCode,		pi->sCalledAreaCode,10);
		strncpy(po->sCallingRoamNumber,		pi->sCallingRoamNumber,30);
		strncpy(po->sCalledRoamNumber,		pi->sCalledRoamNumber,30);
		strncpy(po->sCallingRoamAreaCode,	pi->sCallingRoamAreaCode,10);
		strncpy(po->sCalledRoamAreaCode,	pi->sCalledRoamAreaCode,10);
		strncpy(po->sTotalDueAmount,		pi->sTotalDueAmount,18);

		strncpy(sTemp,		pi->sProdInstID,8);sTemp[8]=0;
		po->iProdInstID=atoi(sTemp);
		strncpy(sTemp,			pi->sRateID,8);sTemp[8]=0;
		po->iRateID=atoi(sTemp);

		strncpy(po->sUpFlux,			pi->sUpFlux,18);
		strncpy(po->sDuration,			pi->sDuration,18);

		strncpy(sTemp,			pi->sCityID,8);sTemp[8]=0;
		po->iCityID=atoi(sTemp);

		strncpy(po->sDownFlux,			pi->sDownFlux,18);
		strncpy(po->sFileName,			pi->sFileName,60);
		strncpy(po->sTotalFlux,			pi->sTotalFlux,18);
		strncpy(po->sStatus,			pi->sStatus,3);

		strncpy(sTemp,		pi->sBillCycleSeq,8);sTemp[8]=0;
		po->iBillCycleSeq=atoi(sTemp);

		strncpy(po->sCurrBalance,		pi->sCurrBalance,18);

		strncpy(sTemp,		pi->sCreateCycleSeq,8);sTemp[8]=0;
		po->iCreateCycleSeq=atoi(sTemp);

		strncpy(po->sRateKey1,			pi->sRateKey1,30);
		strncpy(po->sRateKey2,			pi->sRateKey2,30);
		strncpy(po->sRateKey3,			pi->sRateKey3,30);

		strncpy(sTemp,		pi->sPureCycleSeq,8);sTemp[8]=0;
		po->iPureCycleSeq=atoi(sTemp);
		strncpy(sTemp,			pi->sDirection,1);sTemp[1]=0;
		po->iDirection=atoi(sTemp);
		strncpy(sTemp,		pi->sFileClassID,8);sTemp[8]=0;
		po->iFileClassID=atoi(sTemp);

		strncpy(po->sExceptionType,		pi->sExceptionType,5);
		strncpy(po->sOrigUsageTypeID,		pi->sOrigUsageTypeID,12);

		strncpy(sTemp,		pi->sTotalDueUnits,8);sTemp[8]=0;
		po->iTotalDueUnits=atoi(sTemp);

		strncpy(po->sStlAmount,			pi->sStlAmount,18);
		strncpy(po->sPostFlag,			pi->sPostFlag,4);

		strncpy(sTemp,			pi->sIsPrepay,1);sTemp[1]=0;
		po->iIsPrepay=atoi(sTemp);
		strncpy(sTemp,			pi->sFileID,9);sTemp[9]=0;
		po->iFileID=atoi(sTemp);
		strncpy(sTemp,		pi->sParentFileID,9);sTemp[9]=0;
		po->iParentFileID=atoi(sTemp);

		strncpy(po->sTableName,			pi->sTableName,30);
		strncpy(po->sCallingCompanyID,		pi->sCallingCompanyID,18);
		strncpy(po->sCalledCompanyID,		pi->sCalledCompanyID,18);
		strncpy(po->sSwitchCompanyID,		pi->sSwitchCompanyID,18);
		strncpy(po->sProvinceID,		pi->sProvinceID,20);
		strncpy(po->sDurationMinnum,		pi->sDurationMinnum,18);
		strncpy(po->sDurationSec6,		pi->sDurationSec6,18);
		strncpy(po->sInTrunkGroup,		pi->sInTrunkGroup,15);
		strncpy(po->sOutTrunkGroup,		pi->sOutTrunkGroup,15);
		strncpy(po->sCallingNumberCompanyID,	pi->sCallingNumberCompanyID,18);
		strncpy(po->sCalledNumberCompanyID,	pi->sCalledNumberCompanyID,18);
		strncpy(po->sCallingGroupID,		pi->sCallingGroupID,15);
		strncpy(po->sCalledGroupID,		pi->sCalledGroupID,15);
		strncpy(po->sStlObject,			pi->sStlObject,18);
		strncpy(po->sProdPropID,		pi->sProdPropID,18);
		strncpy(po->sCallingSubType,		pi->sCallingSubType,18);
		strncpy(po->sCalledSubType,		pi->sCalledSubType,18);

		strncpy(sTemp,		pi->sStlDirection,1);sTemp[1]=0;
		po->iStlDirection=atoi(sTemp);

		strncpy(po->sPreCallType,		pi->sPreCallType,30);
		strncpy(po->sTurnCode,			pi->sTurnCode,50);
		strncpy(po->sTurnCodeCompanyID,		pi->sTurnCodeCompanyID,10);
		strncpy(po->sTurnCodeProvinceID,	pi->sTurnCodeProvinceID,20);

		strncpy(sTemp,		pi->sTurnCodeCityID,8);sTemp[8]=0;
		po->iTurnCodeCityID=atoi(sTemp);

		strncpy(po->sTurnCodeOperationTypeGrade,pi->sTurnCodeOperationTypeGrade,30);
		strncpy(po->sTurnType,			pi->sTurnType,30);
		strncpy(po->sTurnCdrID,			pi->sTurnCdrID,4);
		strncpy(po->sSecondCallingNumber,	pi->sSecondCallingNumber,30);
		strncpy(po->sSecondCallingAreaCode,	pi->sSecondCallingAreaCode,10);
		strncpy(po->sSecondCallingGroupID,	pi->sSecondCallingGroupID,30);
		strncpy(po->sSecondCallingCompanyID,	pi->sSecondCallingCompanyID,10);
		strncpy(po->sPreCallParentCdrID,	pi->sPreCallParentCdrID,20);
		strncpy(po->sPreCallSubCdrID,		pi->sPreCallSubCdrID,20);
		strncpy(po->sPreCallSubCdrNum,		pi->sPreCallSubCdrNum,4);
		strncpy(po->sPreCallSubCdrSeq,		pi->sPreCallSubCdrSeq,10);
		strncpy(po->sPreCallUsageEventID,	pi->sPreCallUsageEventID,18);
		strncpy(po->sTurnParentCdrID,		pi->sTurnParentCdrID,20);
		strncpy(po->sTurnSubCdrID,		pi->sTurnSubCdrID,20);
		strncpy(po->sTurnSubCdrNum,		pi->sTurnSubCdrNum,4);
		strncpy(po->sTurnSubCdrSeq,		pi->sTurnSubCdrSeq,10);
		strncpy(po->sTurnUsageEventID,		pi->sTurnUsageEventID,18);
		strncpy(po->sInTrunkGenre,		pi->sInTrunkGenre,20);
		strncpy(po->sOutTrunkGenre,		pi->sOutTrunkGenre,20);
		strncpy(po->sInTrunkNetType,		pi->sInTrunkNetType,20);
		strncpy(po->sOutTrunkNetType,		pi->sOutTrunkNetType,20);
		strncpy(po->sCallingNumberType,		pi->sCallingNumberType,20);
		strncpy(po->sCalledNumberType,		pi->sCalledNumberType,20);
		strncpy(po->sCallingDomainID,		pi->sCallingDomainID,20);
		strncpy(po->sCalledDomainID,		pi->sCalledDomainID,20);
		strncpy(po->sSecondSubType,		pi->sSecondSubType,20);
		strncpy(po->sSecondCallingRoamnumber,	pi->sSecondCallingRoamnumber,30);
		strncpy(po->sViewCall,			pi->sViewCall,10);

		AllTrim(po->sUsageEventID);
		AllTrim(po->sProdID);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sRateTime);
		AllTrim(po->sOperationTypeID);
		AllTrim(po->sCallingNumber);
		AllTrim(po->sCalledNumber);
		AllTrim(po->sBilledNumber);
		AllTrim(po->sThirdNumber);
		AllTrim(po->sInTrunkNumber);
		AllTrim(po->sOutTrunkNumber);
		AllTrim(po->sRawUnits);
		AllTrim(po->sIsFree);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCalledAreaCode);
		AllTrim(po->sCallingRoamNumber);
		AllTrim(po->sCalledRoamNumber);
		AllTrim(po->sCallingRoamAreaCode);
		AllTrim(po->sCalledRoamAreaCode);
		AllTrim(po->sTotalDueAmount);
		AllTrim(po->sUpFlux);
		AllTrim(po->sDuration);
		AllTrim(po->sDownFlux);
		AllTrim(po->sFileName);
		AllTrim(po->sTotalFlux);
		AllTrim(po->sStatus);
		AllTrim(po->sCurrBalance);
		AllTrim(po->sRateKey1);
		AllTrim(po->sRateKey2);
		AllTrim(po->sRateKey3);
		AllTrim(po->sExceptionType);
		AllTrim(po->sOrigUsageTypeID);
		AllTrim(po->sStlAmount);
		AllTrim(po->sPostFlag);
		AllTrim(po->sTableName);
		AllTrim(po->sCallingCompanyID);
		AllTrim(po->sCalledCompanyID);
		AllTrim(po->sSwitchCompanyID);
		AllTrim(po->sProvinceID);
		AllTrim(po->sDurationMinnum);
		AllTrim(po->sDurationSec6);
		AllTrim(po->sInTrunkGroup);
		AllTrim(po->sOutTrunkGroup);
		AllTrim(po->sCallingNumberCompanyID);
		AllTrim(po->sCalledNumberCompanyID);
		AllTrim(po->sCallingGroupID);
		AllTrim(po->sCalledGroupID);
		AllTrim(po->sStlObject);
		AllTrim(po->sProdPropID);
		AllTrim(po->sCallingSubType);
		AllTrim(po->sCalledSubType);
		AllTrim(po->sPreCallType);
		AllTrim(po->sTurnCode);
		AllTrim(po->sTurnCodeCompanyID);
		AllTrim(po->sTurnCodeProvinceID);
		AllTrim(po->sTurnCodeOperationTypeGrade);
		AllTrim(po->sTurnType);
		AllTrim(po->sTurnCdrID);
		AllTrim(po->sSecondCallingNumber);
		AllTrim(po->sSecondCallingAreaCode);
		AllTrim(po->sSecondCallingGroupID);
		AllTrim(po->sSecondCallingCompanyID);
		AllTrim(po->sPreCallParentCdrID);
		AllTrim(po->sPreCallSubCdrID);
		AllTrim(po->sPreCallSubCdrNum);
		AllTrim(po->sPreCallSubCdrSeq);
		AllTrim(po->sPreCallUsageEventID);
		AllTrim(po->sTurnParentCdrID);
		AllTrim(po->sTurnSubCdrID);
		AllTrim(po->sTurnSubCdrNum);
		AllTrim(po->sTurnSubCdrSeq);
		AllTrim(po->sTurnUsageEventID);
		AllTrim(po->sInTrunkGenre);
		AllTrim(po->sOutTrunkGenre);
		AllTrim(po->sInTrunkNetType);
		AllTrim(po->sOutTrunkNetType);
		AllTrim(po->sCallingNumberType);
		AllTrim(po->sCalledNumberType);
		AllTrim(po->sCallingDomainID);
		AllTrim(po->sCalledDomainID);
		AllTrim(po->sSecondSubType);
		AllTrim(po->sSecondCallingRoamnumber);
		AllTrim(po->sViewCall);
}
void mvitem_mfttemplateydgwue(struct TTemplateYdGwUeStruct *pi,struct FTTemplateYdGwUeStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FTTemplateYdGwUeStruct));

		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));
		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));
		strncpy(po->sRateTime,pi->sRateTime,strlen(pi->sRateTime));
		strncpy(po->sOperationTypeID,pi->sOperationTypeID,strlen(pi->sOperationTypeID));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sBilledNumber,pi->sBilledNumber,strlen(pi->sBilledNumber));
		strncpy(po->sThirdNumber,pi->sThirdNumber,strlen(pi->sThirdNumber));

		sprintf(sTemp,"%08d",pi->iCallingAreaID);
		strncpy(po->sCallingAreaID,sTemp,8);
		sprintf(sTemp,"%08d",pi->iCalledAreaID);
		strncpy(po->sCalledAreaID,sTemp,8);

		strncpy(po->sInTrunkNumber,pi->sInTrunkNumber,strlen(pi->sInTrunkNumber));
		strncpy(po->sOutTrunkNumber,pi->sOutTrunkNumber,strlen(pi->sOutTrunkNumber));

		sprintf(sTemp,"%04d",pi->iRawUnitType);
		strncpy(po->sRawUnitType,sTemp,4);

		strncpy(po->sRawUnits,pi->sRawUnits,strlen(pi->sRawUnits));

		sprintf(sTemp,"%04d",pi->iRateUnitType);
		strncpy(po->sRateUnitType,sTemp,4);

		strncpy(po->sIsFree,pi->sIsFree,strlen(pi->sIsFree));

		sprintf(sTemp,"%08d",pi->iRateUnits);
		strncpy(po->sRateUnits,sTemp,8);

		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sCallingRoamNumber,pi->sCallingRoamNumber,strlen(pi->sCallingRoamNumber));
		strncpy(po->sCalledRoamNumber,pi->sCalledRoamNumber,strlen(pi->sCalledRoamNumber));
		strncpy(po->sCallingRoamAreaCode,pi->sCallingRoamAreaCode,strlen(pi->sCallingRoamAreaCode));
		strncpy(po->sCalledRoamAreaCode,pi->sCalledRoamAreaCode,strlen(pi->sCalledRoamAreaCode));
		strncpy(po->sTotalDueAmount,pi->sTotalDueAmount,strlen(pi->sTotalDueAmount));

		sprintf(sTemp,"%08d",pi->iProdInstID);
		strncpy(po->sProdInstID,sTemp,8);
		sprintf(sTemp,"%08d",pi->iRateID);
		strncpy(po->sRateID,sTemp,8);

		strncpy(po->sUpFlux,pi->sUpFlux,strlen(pi->sUpFlux));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));

		sprintf(sTemp,"%08d",pi->iCityID);
		strncpy(po->sCityID,sTemp,8);

		strncpy(po->sDownFlux,pi->sDownFlux,strlen(pi->sDownFlux));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sTotalFlux,pi->sTotalFlux,strlen(pi->sTotalFlux));
		strncpy(po->sStatus,pi->sStatus,strlen(pi->sStatus));

		sprintf(sTemp,"%08d",pi->iBillCycleSeq);
		strncpy(po->sBillCycleSeq,sTemp,8);

		strncpy(po->sCurrBalance,pi->sCurrBalance,strlen(pi->sCurrBalance));

		sprintf(sTemp,"%08d",pi->iCreateCycleSeq);
		strncpy(po->sCreateCycleSeq,sTemp,8);

		strncpy(po->sRateKey1,pi->sRateKey1,strlen(pi->sRateKey1));
		strncpy(po->sRateKey2,pi->sRateKey2,strlen(pi->sRateKey2));
		strncpy(po->sRateKey3,pi->sRateKey3,strlen(pi->sRateKey3));

		sprintf(sTemp,"%08d",pi->iPureCycleSeq);
		strncpy(po->sPureCycleSeq,sTemp,8);
		sprintf(sTemp,"%01d",pi->iDirection);
		strncpy(po->sDirection,sTemp,1);
		sprintf(sTemp,"%08d",pi->iFileClassID);
		strncpy(po->sFileClassID,sTemp,8);

		strncpy(po->sExceptionType,pi->sExceptionType,strlen(pi->sExceptionType));
		strncpy(po->sOrigUsageTypeID,pi->sOrigUsageTypeID,strlen(pi->sOrigUsageTypeID));

		sprintf(sTemp,"%08d",pi->iTotalDueUnits);
		strncpy(po->sTotalDueUnits,sTemp,8);

		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));
		strncpy(po->sPostFlag,pi->sPostFlag,strlen(pi->sPostFlag));

		sprintf(sTemp,"%01d",pi->iIsPrepay);
		strncpy(po->sIsPrepay,sTemp,1);
		sprintf(sTemp,"%09d",pi->iFileID);
		strncpy(po->sFileID,sTemp,9);
		sprintf(sTemp,"%09d",pi->iParentFileID);
		strncpy(po->sParentFileID,sTemp,9);

		strncpy(po->sTableName,pi->sTableName,strlen(pi->sTableName));
		strncpy(po->sCallingCompanyID,pi->sCallingCompanyID,strlen(pi->sCallingCompanyID));
		strncpy(po->sCalledCompanyID,pi->sCalledCompanyID,strlen(pi->sCalledCompanyID));
		strncpy(po->sSwitchCompanyID,pi->sSwitchCompanyID,strlen(pi->sSwitchCompanyID));
		strncpy(po->sProvinceID,pi->sProvinceID,strlen(pi->sProvinceID));
		strncpy(po->sDurationMinnum,pi->sDurationMinnum,strlen(pi->sDurationMinnum));
		strncpy(po->sDurationSec6,pi->sDurationSec6,strlen(pi->sDurationSec6));
		strncpy(po->sInTrunkGroup,pi->sInTrunkGroup,strlen(pi->sInTrunkGroup));
		strncpy(po->sOutTrunkGroup,pi->sOutTrunkGroup,strlen(pi->sOutTrunkGroup));
		strncpy(po->sCallingNumberCompanyID,pi->sCallingNumberCompanyID,strlen(pi->sCallingNumberCompanyID));
		strncpy(po->sCalledNumberCompanyID,pi->sCalledNumberCompanyID,strlen(pi->sCalledNumberCompanyID));
		strncpy(po->sCallingGroupID,pi->sCallingGroupID,strlen(pi->sCallingGroupID));
		strncpy(po->sCalledGroupID,pi->sCalledGroupID,strlen(pi->sCalledGroupID));
		strncpy(po->sStlObject,pi->sStlObject,strlen(pi->sStlObject));
		strncpy(po->sProdPropID,pi->sProdPropID,strlen(pi->sProdPropID));
		strncpy(po->sCallingSubType,pi->sCallingSubType,strlen(pi->sCallingSubType));
		strncpy(po->sCalledSubType,pi->sCalledSubType,strlen(pi->sCalledSubType));

		sprintf(sTemp,"%01d",pi->iStlDirection);
		strncpy(po->sStlDirection,sTemp,1);

		strncpy(po->sPreCallType,pi->sPreCallType,strlen(pi->sPreCallType));
		strncpy(po->sTurnCode,pi->sTurnCode,strlen(pi->sTurnCode));
		strncpy(po->sTurnCodeCompanyID,pi->sTurnCodeCompanyID,strlen(pi->sTurnCodeCompanyID));
		strncpy(po->sTurnCodeProvinceID,pi->sTurnCodeProvinceID,strlen(pi->sTurnCodeProvinceID));

		sprintf(sTemp,"%08d",pi->iTurnCodeCityID);
		strncpy(po->sTurnCodeCityID,sTemp,8);

		strncpy(po->sTurnCodeOperationTypeGrade,pi->sTurnCodeOperationTypeGrade,strlen(pi->sTurnCodeOperationTypeGrade));
		strncpy(po->sTurnType,pi->sTurnType,strlen(pi->sTurnType));
		strncpy(po->sTurnCdrID,pi->sTurnCdrID,strlen(pi->sTurnCdrID));
		strncpy(po->sSecondCallingNumber,pi->sSecondCallingNumber,strlen(pi->sSecondCallingNumber));
		strncpy(po->sSecondCallingAreaCode,pi->sSecondCallingAreaCode,strlen(pi->sSecondCallingAreaCode));
		strncpy(po->sSecondCallingGroupID,pi->sSecondCallingGroupID,strlen(pi->sSecondCallingGroupID));
		strncpy(po->sSecondCallingCompanyID,pi->sSecondCallingCompanyID,strlen(pi->sSecondCallingCompanyID));
		strncpy(po->sPreCallParentCdrID,pi->sPreCallParentCdrID,strlen(pi->sPreCallParentCdrID));
		strncpy(po->sPreCallSubCdrID,pi->sPreCallSubCdrID,strlen(pi->sPreCallSubCdrID));
		strncpy(po->sPreCallSubCdrNum,pi->sPreCallSubCdrNum,strlen(pi->sPreCallSubCdrNum));
		strncpy(po->sPreCallSubCdrSeq,pi->sPreCallSubCdrSeq,strlen(pi->sPreCallSubCdrSeq));
		strncpy(po->sPreCallUsageEventID,pi->sPreCallUsageEventID,strlen(pi->sPreCallUsageEventID));
		strncpy(po->sTurnParentCdrID,pi->sTurnParentCdrID,strlen(pi->sTurnParentCdrID));
		strncpy(po->sTurnSubCdrID,pi->sTurnSubCdrID,strlen(pi->sTurnSubCdrID));
		strncpy(po->sTurnSubCdrNum,pi->sTurnSubCdrNum,strlen(pi->sTurnSubCdrNum));
		strncpy(po->sTurnSubCdrSeq,pi->sTurnSubCdrSeq,strlen(pi->sTurnSubCdrSeq));
		strncpy(po->sTurnUsageEventID,pi->sTurnUsageEventID,strlen(pi->sTurnUsageEventID));
		strncpy(po->sInTrunkGenre,pi->sInTrunkGenre,strlen(pi->sInTrunkGenre));
		strncpy(po->sOutTrunkGenre,pi->sOutTrunkGenre,strlen(pi->sOutTrunkGenre));
		strncpy(po->sInTrunkNetType,pi->sInTrunkNetType,strlen(pi->sInTrunkNetType));
		strncpy(po->sOutTrunkNetType,pi->sOutTrunkNetType,strlen(pi->sOutTrunkNetType));
		strncpy(po->sCallingNumberType,pi->sCallingNumberType,strlen(pi->sCallingNumberType));
		strncpy(po->sCalledNumberType,pi->sCalledNumberType,strlen(pi->sCalledNumberType));
		strncpy(po->sCallingDomainID,pi->sCallingDomainID,strlen(pi->sCallingDomainID));
		strncpy(po->sCalledDomainID,pi->sCalledDomainID,strlen(pi->sCalledDomainID));
		strncpy(po->sSecondSubType,pi->sSecondSubType,strlen(pi->sSecondSubType));
		strncpy(po->sSecondCallingRoamnumber,pi->sSecondCallingRoamnumber,strlen(pi->sSecondCallingRoamnumber));
		strncpy(po->sViewCall,pi->sViewCall,strlen(pi->sViewCall));

}
/**对表T_TEMPLATE_YD_GW_UE的链表释放函数**/
void DestroyTTemplateYdGwUe(struct TTemplateYdGwUeStruct *ptHead)
{
	struct TTemplateYdGwUeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTTemplateYdGwUe(struct TTemplateYdGwUeStruct **pptHead)
{
	int iCnt=0;
	static struct TTemplateYdGwUeStruct *pTemp,*ptHead=NULL;
	struct TTemplateYdGwUeStruct Temp;
	struct TTemplateYdGwUeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTTemplateYdGwUe(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct TTemplateYdGwUeStructIn));
	sprintf(TempIn.sTableName,"T_TEMPLATE_YD_GW_UE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTTemplateYdGwUeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TTemplateYdGwUeStruct*)
			malloc(sizeof(struct TTemplateYdGwUeStruct)))==NULL){

			DestroyTTemplateYdGwUe(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TTemplateYdGwUeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表T_TEMPLATE_YD_GW_UE记录数%d",iCnt);
	}

	WriteProcMsg("加载表T_TEMPLATE_YD_GW_UE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据结构缓冲写入T_TEMPLATE_YD_GW_UE*/
int EInsertStructToTTemplateYdGwUe(struct TTemplateYdGwUeStruct *p,
	int iInsertFlag,struct TTemplateYdGwUeStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asUsageEventID[iCurPos],		p->sUsageEventID);
		strcpy(pTarget->asProdID[iCurPos],			p->sProdID);
		strcpy(pTarget->asStartTime[iCurPos],			p->sStartTime);
		strcpy(pTarget->asEndTime[iCurPos],			p->sEndTime);
		strcpy(pTarget->asRateTime[iCurPos],			p->sRateTime);
		strcpy(pTarget->asOperationTypeID[iCurPos],		p->sOperationTypeID);
		strcpy(pTarget->asCallingNumber[iCurPos],		p->sCallingNumber);
		strcpy(pTarget->asCalledNumber[iCurPos],		p->sCalledNumber);
		strcpy(pTarget->asBilledNumber[iCurPos],		p->sBilledNumber);
		strcpy(pTarget->asThirdNumber[iCurPos],			p->sThirdNumber);

		pTarget->aiCallingAreaID[iCurPos]=			p->iCallingAreaID;
		pTarget->aiCalledAreaID[iCurPos]=			p->iCalledAreaID;

		strcpy(pTarget->asInTrunkNumber[iCurPos],		p->sInTrunkNumber);
		strcpy(pTarget->asOutTrunkNumber[iCurPos],		p->sOutTrunkNumber);

		pTarget->aiRawUnitType[iCurPos]=			p->iRawUnitType;

		strcpy(pTarget->asRawUnits[iCurPos],			p->sRawUnits);

		pTarget->aiRateUnitType[iCurPos]=			p->iRateUnitType;

		strcpy(pTarget->asIsFree[iCurPos],			p->sIsFree);

		pTarget->aiRateUnits[iCurPos]=				p->iRateUnits;

		strcpy(pTarget->asCallingAreaCode[iCurPos],		p->sCallingAreaCode);
		strcpy(pTarget->asCalledAreaCode[iCurPos],		p->sCalledAreaCode);
		strcpy(pTarget->asCallingRoamNumber[iCurPos],		p->sCallingRoamNumber);
		strcpy(pTarget->asCalledRoamNumber[iCurPos],		p->sCalledRoamNumber);
		strcpy(pTarget->asCallingRoamAreaCode[iCurPos],		p->sCallingRoamAreaCode);
		strcpy(pTarget->asCalledRoamAreaCode[iCurPos],		p->sCalledRoamAreaCode);
		strcpy(pTarget->asTotalDueAmount[iCurPos],		p->sTotalDueAmount);

		pTarget->aiProdInstID[iCurPos]=				p->iProdInstID;
		pTarget->aiRateID[iCurPos]=				p->iRateID;

		strcpy(pTarget->asUpFlux[iCurPos],			p->sUpFlux);
		strcpy(pTarget->asDuration[iCurPos],			p->sDuration);

		pTarget->aiCityID[iCurPos]=				p->iCityID;

		strcpy(pTarget->asDownFlux[iCurPos],			p->sDownFlux);
		strcpy(pTarget->asFileName[iCurPos],			p->sFileName);
		strcpy(pTarget->asTotalFlux[iCurPos],			p->sTotalFlux);
		strcpy(pTarget->asStatus[iCurPos],			p->sStatus);

		pTarget->aiBillCycleSeq[iCurPos]=			p->iBillCycleSeq;

		strcpy(pTarget->asCurrBalance[iCurPos],			p->sCurrBalance);

		pTarget->aiCreateCycleSeq[iCurPos]=			p->iCreateCycleSeq;

		strcpy(pTarget->asRateKey1[iCurPos],			p->sRateKey1);
		strcpy(pTarget->asRateKey2[iCurPos],			p->sRateKey2);
		strcpy(pTarget->asRateKey3[iCurPos],			p->sRateKey3);

		pTarget->aiPureCycleSeq[iCurPos]=			p->iPureCycleSeq;
		pTarget->aiDirection[iCurPos]=				p->iDirection;
		pTarget->aiFileClassID[iCurPos]=			p->iFileClassID;

		strcpy(pTarget->asExceptionType[iCurPos],		p->sExceptionType);
		strcpy(pTarget->asOrigUsageTypeID[iCurPos],		p->sOrigUsageTypeID);

		pTarget->aiTotalDueUnits[iCurPos]=			p->iTotalDueUnits;

		strcpy(pTarget->asStlAmount[iCurPos],			p->sStlAmount);
		strcpy(pTarget->asPostFlag[iCurPos],			p->sPostFlag);

		pTarget->aiIsPrepay[iCurPos]=				p->iIsPrepay;
		pTarget->aiFileID[iCurPos]=				p->iFileID;
		pTarget->aiParentFileID[iCurPos]=			p->iParentFileID;

		strcpy(pTarget->asTableName[iCurPos],			p->sTableName);
		strcpy(pTarget->asCallingCompanyID[iCurPos],		p->sCallingCompanyID);
		strcpy(pTarget->asCalledCompanyID[iCurPos],		p->sCalledCompanyID);
		strcpy(pTarget->asSwitchCompanyID[iCurPos],		p->sSwitchCompanyID);
		strcpy(pTarget->asProvinceID[iCurPos],			p->sProvinceID);
		strcpy(pTarget->asDurationMinnum[iCurPos],		p->sDurationMinnum);
		strcpy(pTarget->asDurationSec6[iCurPos],		p->sDurationSec6);
		strcpy(pTarget->asInTrunkGroup[iCurPos],		p->sInTrunkGroup);
		strcpy(pTarget->asOutTrunkGroup[iCurPos],		p->sOutTrunkGroup);
		strcpy(pTarget->asCallingNumberCompanyID[iCurPos],	p->sCallingNumberCompanyID);
		strcpy(pTarget->asCalledNumberCompanyID[iCurPos],	p->sCalledNumberCompanyID);
		strcpy(pTarget->asCallingGroupID[iCurPos],		p->sCallingGroupID);
		strcpy(pTarget->asCalledGroupID[iCurPos],		p->sCalledGroupID);
		strcpy(pTarget->asStlObject[iCurPos],			p->sStlObject);
		strcpy(pTarget->asProdPropID[iCurPos],			p->sProdPropID);
		strcpy(pTarget->asCallingSubType[iCurPos],		p->sCallingSubType);
		strcpy(pTarget->asCalledSubType[iCurPos],		p->sCalledSubType);

		pTarget->aiStlDirection[iCurPos]=			p->iStlDirection;

		strcpy(pTarget->asPreCallType[iCurPos],			p->sPreCallType);
		strcpy(pTarget->asTurnCode[iCurPos],			p->sTurnCode);
		strcpy(pTarget->asTurnCodeCompanyID[iCurPos],		p->sTurnCodeCompanyID);
		strcpy(pTarget->asTurnCodeProvinceID[iCurPos],		p->sTurnCodeProvinceID);

		pTarget->aiTurnCodeCityID[iCurPos]=			p->iTurnCodeCityID;

		strcpy(pTarget->asTurnCodeOperationTypeGrade[iCurPos],	p->sTurnCodeOperationTypeGrade);
		strcpy(pTarget->asTurnType[iCurPos],			p->sTurnType);
		strcpy(pTarget->asTurnCdrID[iCurPos],			p->sTurnCdrID);
		strcpy(pTarget->asSecondCallingNumber[iCurPos],		p->sSecondCallingNumber);
		strcpy(pTarget->asSecondCallingAreaCode[iCurPos],	p->sSecondCallingAreaCode);
		strcpy(pTarget->asSecondCallingGroupID[iCurPos],	p->sSecondCallingGroupID);
		strcpy(pTarget->asSecondCallingCompanyID[iCurPos],	p->sSecondCallingCompanyID);
		strcpy(pTarget->asPreCallParentCdrID[iCurPos],		p->sPreCallParentCdrID);
		strcpy(pTarget->asPreCallSubCdrID[iCurPos],		p->sPreCallSubCdrID);
		strcpy(pTarget->asPreCallSubCdrNum[iCurPos],		p->sPreCallSubCdrNum);
		strcpy(pTarget->asPreCallSubCdrSeq[iCurPos],		p->sPreCallSubCdrSeq);
		strcpy(pTarget->asPreCallUsageEventID[iCurPos],		p->sPreCallUsageEventID);
		strcpy(pTarget->asTurnParentCdrID[iCurPos],		p->sTurnParentCdrID);
		strcpy(pTarget->asTurnSubCdrID[iCurPos],		p->sTurnSubCdrID);
		strcpy(pTarget->asTurnSubCdrNum[iCurPos],		p->sTurnSubCdrNum);
		strcpy(pTarget->asTurnSubCdrSeq[iCurPos],		p->sTurnSubCdrSeq);
		strcpy(pTarget->asTurnUsageEventID[iCurPos],		p->sTurnUsageEventID);
		strcpy(pTarget->asInTrunkGenre[iCurPos],		p->sInTrunkGenre);
		strcpy(pTarget->asOutTrunkGenre[iCurPos],		p->sOutTrunkGenre);
		strcpy(pTarget->asInTrunkNetType[iCurPos],		p->sInTrunkNetType);
		strcpy(pTarget->asOutTrunkNetType[iCurPos],		p->sOutTrunkNetType);
		strcpy(pTarget->asCallingNumberType[iCurPos],		p->sCallingNumberType);
		strcpy(pTarget->asCalledNumberType[iCurPos],		p->sCalledNumberType);
		strcpy(pTarget->asCallingDomainID[iCurPos],		p->sCallingDomainID);
		strcpy(pTarget->asCalledDomainID[iCurPos],		p->sCalledDomainID);
		strcpy(pTarget->asSecondSubType[iCurPos],		p->sSecondSubType);
		strcpy(pTarget->asSecondCallingRoamnumber[iCurPos],	p->sSecondCallingRoamnumber);
		strcpy(pTarget->asViewCall[iCurPos],			p->sViewCall);
		strcpy(pTarget->asGroupID[iCurPos],			p->sGroupID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==T_TEMPLATE_YD_GW_UE_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				USAGE_EVENT_ID,\n\
				PROD_ID,\n\
				START_TIME,\n\
				END_TIME,\n\
				RATE_TIME,\n\
				OPERATION_TYPE_ID,\n\
				CALLING_NUMBER,\n\
				CALLED_NUMBER,\n\
				BILLED_NUMBER,\n\
				THIRD_NUMBER,\n\
				CALLING_AREA_ID,\n\
				CALLED_AREA_ID,\n\
				IN_TRUNK_NUMBER,\n\
				OUT_TRUNK_NUMBER,\n\
				RAW_UNIT_TYPE,\n\
				RAW_UNITS,\n\
				RATE_UNIT_TYPE,\n\
				IS_FREE,\n\
				RATE_UNITS,\n\
				CALLING_AREA_CODE,\n\
				CALLED_AREA_CODE,\n\
				CALLING_ROAM_NUMBER,\n\
				CALLED_ROAM_NUMBER,\n\
				CALLING_ROAM_AREA_CODE,\n\
				CALLED_ROAM_AREA_CODE,\n\
				TOTAL_DUE_AMOUNT,\n\
				PROD_INST_ID,\n\
				RATE_ID,\n\
				UP_FLUX,\n\
				DURATION,\n\
				CITY_ID,\n\
				DOWN_FLUX,\n\
				FILE_NAME,\n\
				TOTAL_FLUX,\n\
				STATUS,\n\
				BILL_CYCLE_SEQ,\n\
				CURR_BALANCE,\n\
				CREATE_CYCLE_SEQ,\n\
				RATE_KEY1,\n\
				RATE_KEY2,\n\
				RATE_KEY3,\n\
				PURE_CYCLE_SEQ,\n\
				DIRECTION,\n\
				FILE_CLASS_ID,\n\
				EXCEPTION_TYPE,\n\
				ORIG_USAGE_TYPE_ID,\n\
				TOTAL_DUE_UNITS,\n\
				STL_AMOUNT,\n\
				POST_FLAG,\n\
				IS_PREPAY,\n\
				FILE_ID,\n\
				PARENT_FILE_ID,\n\
				TABLE_NAME,\n\
				CALLING_COMPANY_ID,\n\
				CALLED_COMPANY_ID,\n\
				SWITCH_COMPANY_ID,\n\
				PROVINCE_ID,\n\
				DURATION_MINNUM,\n\
				DURATION_SEC6,\n\
				IN_TRUNK_GROUP,\n\
				OUT_TRUNK_GROUP,\n\
				CALLING_NUMBER_COMPANY_ID,\n\
				CALLED_NUMBER_COMPANY_ID,\n\
				CALLING_GROUP_ID,\n\
				CALLED_GROUP_ID,\n\
				STL_OBJECT,\n\
				PROD_PROP_ID,\n\
				CALLING_SUB_TYPE,\n\
				CALLED_SUB_TYPE,\n\
				STL_DIRECTION,\n\
				PRE_CALL_TYPE,\n\
				TURN_CODE,\n\
				TURN_CODE_COMPANY_ID,\n\
				TURN_CODE_PROVINCE_ID,\n\
				TURN_CODE_CITY_ID,\n\
				TURN_CODE_OPERATION_TYPE_GRADE,\n\
				TURN_TYPE,\n\
				TURN_CDR_ID,\n\
				SECOND_CALLING_NUMBER,\n\
				SECOND_CALLING_AREA_CODE,\n\
				SECOND_CALLING_GROUP_ID,\n\
				SECOND_CALLING_COMPANY_ID,\n\
				PRE_CALL_PARENT_CDR_ID,\n\
				PRE_CALL_SUB_CDR_ID,\n\
				PRE_CALL_SUB_CDR_NUM,\n\
				PRE_CALL_SUB_CDR_SEQ,\n\
				PRE_CALL_USAGE_EVENT_ID,\n\
				TURN_PARENT_CDR_ID,\n\
				TURN_SUB_CDR_ID,\n\
				TURN_SUB_CDR_NUM,\n\
				TURN_SUB_CDR_SEQ,\n\
				TURN_USAGE_EVENT_ID,\n\
				IN_TRUNK_GENRE,\n\
				OUT_TRUNK_GENRE,\n\
				IN_TRUNK_NET_TYPE,\n\
				OUT_TRUNK_NET_TYPE,\n\
				CALLING_NUMBER_TYPE,\n\
				CALLED_NUMBER_TYPE,\n\
				CALLING_DOMAIN_ID,\n\
				CALLED_DOMAIN_ID,\n\
				SECOND_SUB_TYPE,\n\
				SECOND_CALLING_ROAMNUMBER,\n\
				VIEW_CALL,\n\
				GROUP_ID)\n\
			VALUES (\n\
				:asUsageEventID,\n\
				:asProdID,\n\
				:asStartTime,\n\
				:asEndTime,\n\
				:asRateTime,\n\
				:asOperationTypeID,\n\
				:asCallingNumber,\n\
				:asCalledNumber,\n\
				:asBilledNumber,\n\
				:asThirdNumber,\n\
				:aiCallingAreaID,\n\
				:aiCalledAreaID,\n\
				:asInTrunkNumber,\n\
				:asOutTrunkNumber,\n\
				:aiRawUnitType,\n\
				to_number(:asRawUnits),\n\
				:aiRateUnitType,\n\
				:asIsFree,\n\
				:aiRateUnits,\n\
				:asCallingAreaCode,\n\
				:asCalledAreaCode,\n\
				:asCallingRoamNumber,\n\
				:asCalledRoamNumber,\n\
				:asCallingRoamAreaCode,\n\
				:asCalledRoamAreaCode,\n\
				to_number(:asTotalDueAmount),\n\
				:aiProdInstID,\n\
				:aiRateID,\n\
				to_number(:asUpFlux),\n\
				to_number(:asDuration),\n\
				:aiCityID,\n\
				to_number(:asDownFlux),\n\
				:asFileName,\n\
				to_number(:asTotalFlux),\n\
				:asStatus,\n\
				:aiBillCycleSeq,\n\
				to_number(:asCurrBalance),\n\
				:aiCreateCycleSeq,\n\
				:asRateKey1,\n\
				:asRateKey2,\n\
				:asRateKey3,\n\
				:aiPureCycleSeq,\n\
				:aiDirection,\n\
				:aiFileClassID,\n\
				:asExceptionType,\n\
				:asOrigUsageTypeID,\n\
				:aiTotalDueUnits,\n\
				to_number(:asStlAmount),\n\
				:asPostFlag,\n\
				:aiIsPrepay,\n\
				:aiFileID,\n\
				:aiParentFileID,\n\
				:asTableName,\n\
				to_number(:asCallingCompanyID),\n\
				to_number(:asCalledCompanyID),\n\
				to_number(:asSwitchCompanyID),\n\
				:asProvinceID,\n\
				to_number(:asDurationMinnum),\n\
				to_number(:asDurationSec6),\n\
				:asInTrunkGroup,\n\
				:asOutTrunkGroup,\n\
				to_number(:asCallingNumberCompanyID),\n\
				to_number(:asCalledNumberCompanyID),\n\
				:asCallingGroupID,\n\
				:asCalledGroupID,\n\
				:asStlObject,\n\
				to_number(:asProdPropID),\n\
				:asCallingSubType,\n\
				:asCalledSubType,\n\
				:aiStlDirection,\n\
				:asPreCallType,\n\
				:asTurnCode,\n\
				:asTurnCodeCompanyID,\n\
				:asTurnCodeProvinceID,\n\
				:aiTurnCodeCityID,\n\
				:asTurnCodeOperationTypeGrade,\n\
				:asTurnType,\n\
				:asTurnCdrID,\n\
				:asSecondCallingNumber,\n\
				:asSecondCallingAreaCode,\n\
				:asSecondCallingGroupID,\n\
				:asSecondCallingCompanyID,\n\
				:asPreCallParentCdrID,\n\
				:asPreCallSubCdrID,\n\
				:asPreCallSubCdrNum,\n\
				:asPreCallSubCdrSeq,\n\
				to_number(:asPreCallUsageEventID),\n\
				:asTurnParentCdrID,\n\
				:asTurnSubCdrID,\n\
				:asTurnSubCdrNum,\n\
				:asTurnSubCdrSeq,\n\
				:asTurnUsageEventID,\n\
				:asInTrunkGenre,\n\
				:asOutTrunkGenre,\n\
				:asInTrunkNetType,\n\
				:asOutTrunkNetType,\n\
				:asCallingNumberType,\n\
				:asCalledNumberType,\n\
				:asCallingDomainID,\n\
				:asCalledDomainID,\n\
				:asSecondSubType,\n\
				:asSecondCallingRoamnumber,\n\
				:asViewCall,\n\
				:asGroupID\n\
			)",sTableName);

		/* EXEC SQL PREPARE T_TEMPLATE_YD_GW_UETRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )500;
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


		if(CheckSqlResult("Prepare insert statement T_TEMPLATE_YD_GW_UE")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE T_TEMPLATE_YD_GW_UETRG USING
				:pTarget->asUsageEventID,
				:pTarget->asProdID,
				:pTarget->asStartTime,
				:pTarget->asEndTime,
				:pTarget->asRateTime,
				:pTarget->asOperationTypeID,
				:pTarget->asCallingNumber,
				:pTarget->asCalledNumber,
				:pTarget->asBilledNumber,
				:pTarget->asThirdNumber,
				:pTarget->aiCallingAreaID,
				:pTarget->aiCalledAreaID,
				:pTarget->asInTrunkNumber,
				:pTarget->asOutTrunkNumber,
				:pTarget->aiRawUnitType,
				:pTarget->asRawUnits,
				:pTarget->aiRateUnitType,
				:pTarget->asIsFree,
				:pTarget->aiRateUnits,
				:pTarget->asCallingAreaCode,
				:pTarget->asCalledAreaCode,
				:pTarget->asCallingRoamNumber,
				:pTarget->asCalledRoamNumber,
				:pTarget->asCallingRoamAreaCode,
				:pTarget->asCalledRoamAreaCode,
				:pTarget->asTotalDueAmount,
				:pTarget->aiProdInstID,
				:pTarget->aiRateID,
				:pTarget->asUpFlux,
				:pTarget->asDuration,
				:pTarget->aiCityID,
				:pTarget->asDownFlux,
				:pTarget->asFileName,
				:pTarget->asTotalFlux,
				:pTarget->asStatus,
				:pTarget->aiBillCycleSeq,
				:pTarget->asCurrBalance,
				:pTarget->aiCreateCycleSeq,
				:pTarget->asRateKey1,
				:pTarget->asRateKey2,
				:pTarget->asRateKey3,
				:pTarget->aiPureCycleSeq,
				:pTarget->aiDirection,
				:pTarget->aiFileClassID,
				:pTarget->asExceptionType,
				:pTarget->asOrigUsageTypeID,
				:pTarget->aiTotalDueUnits,
				:pTarget->asStlAmount,
				:pTarget->asPostFlag,
				:pTarget->aiIsPrepay,
				:pTarget->aiFileID,
				:pTarget->aiParentFileID,
				:pTarget->asTableName,
				:pTarget->asCallingCompanyID,
				:pTarget->asCalledCompanyID,
				:pTarget->asSwitchCompanyID,
				:pTarget->asProvinceID,
				:pTarget->asDurationMinnum,
				:pTarget->asDurationSec6,
				:pTarget->asInTrunkGroup,
				:pTarget->asOutTrunkGroup,
				:pTarget->asCallingNumberCompanyID,
				:pTarget->asCalledNumberCompanyID,
				:pTarget->asCallingGroupID,
				:pTarget->asCalledGroupID,
				:pTarget->asStlObject,
				:pTarget->asProdPropID,
				:pTarget->asCallingSubType,
				:pTarget->asCalledSubType,
				:pTarget->aiStlDirection,
				:pTarget->asPreCallType,
				:pTarget->asTurnCode,
				:pTarget->asTurnCodeCompanyID,
				:pTarget->asTurnCodeProvinceID,
				:pTarget->aiTurnCodeCityID,
				:pTarget->asTurnCodeOperationTypeGrade,
				:pTarget->asTurnType,
				:pTarget->asTurnCdrID,
				:pTarget->asSecondCallingNumber,
				:pTarget->asSecondCallingAreaCode,
				:pTarget->asSecondCallingGroupID,
				:pTarget->asSecondCallingCompanyID,
				:pTarget->asPreCallParentCdrID,
				:pTarget->asPreCallSubCdrID,
				:pTarget->asPreCallSubCdrNum,
				:pTarget->asPreCallSubCdrSeq,
				:pTarget->asPreCallUsageEventID,
				:pTarget->asTurnParentCdrID,
				:pTarget->asTurnSubCdrID,
				:pTarget->asTurnSubCdrNum,
				:pTarget->asTurnSubCdrSeq,
				:pTarget->asTurnUsageEventID,
				:pTarget->asInTrunkGenre,
				:pTarget->asOutTrunkGenre,
				:pTarget->asInTrunkNetType,
				:pTarget->asOutTrunkNetType,
				:pTarget->asCallingNumberType,
				:pTarget->asCalledNumberType,
				:pTarget->asCallingDomainID,
				:pTarget->asCalledDomainID,
				:pTarget->asSecondSubType,
				:pTarget->asSecondCallingRoamnumber,
				:pTarget->asViewCall,
				:pTarget->asGroupID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )519;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asStartTime);
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asEndTime);
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )15;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asRateTime);
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asOperationTypeID);
  sqlstm.sqhstl[5] = (unsigned long )9;
  sqlstm.sqhsts[5] = (         int  )9;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asCallingNumber);
  sqlstm.sqhstl[6] = (unsigned long )31;
  sqlstm.sqhsts[6] = (         int  )31;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asCalledNumber);
  sqlstm.sqhstl[7] = (unsigned long )31;
  sqlstm.sqhsts[7] = (         int  )31;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asBilledNumber);
  sqlstm.sqhstl[8] = (unsigned long )31;
  sqlstm.sqhsts[8] = (         int  )31;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asThirdNumber);
  sqlstm.sqhstl[9] = (unsigned long )31;
  sqlstm.sqhsts[9] = (         int  )31;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiCallingAreaID);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->aiCalledAreaID);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asInTrunkNumber);
  sqlstm.sqhstl[12] = (unsigned long )21;
  sqlstm.sqhsts[12] = (         int  )21;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asOutTrunkNumber);
  sqlstm.sqhstl[13] = (unsigned long )21;
  sqlstm.sqhsts[13] = (         int  )21;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiRawUnitType);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asRawUnits);
  sqlstm.sqhstl[15] = (unsigned long )19;
  sqlstm.sqhsts[15] = (         int  )19;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->aiRateUnitType);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )sizeof(int);
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asIsFree);
  sqlstm.sqhstl[17] = (unsigned long )21;
  sqlstm.sqhsts[17] = (         int  )21;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->aiRateUnits);
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )sizeof(int);
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asCallingAreaCode);
  sqlstm.sqhstl[19] = (unsigned long )11;
  sqlstm.sqhsts[19] = (         int  )11;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asCalledAreaCode);
  sqlstm.sqhstl[20] = (unsigned long )11;
  sqlstm.sqhsts[20] = (         int  )11;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asCallingRoamNumber);
  sqlstm.sqhstl[21] = (unsigned long )31;
  sqlstm.sqhsts[21] = (         int  )31;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asCalledRoamNumber);
  sqlstm.sqhstl[22] = (unsigned long )31;
  sqlstm.sqhsts[22] = (         int  )31;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asCallingRoamAreaCode);
  sqlstm.sqhstl[23] = (unsigned long )11;
  sqlstm.sqhsts[23] = (         int  )11;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asCalledRoamAreaCode);
  sqlstm.sqhstl[24] = (unsigned long )11;
  sqlstm.sqhsts[24] = (         int  )11;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pTarget->asTotalDueAmount);
  sqlstm.sqhstl[25] = (unsigned long )19;
  sqlstm.sqhsts[25] = (         int  )19;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pTarget->aiProdInstID);
  sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[26] = (         int  )sizeof(int);
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pTarget->aiRateID);
  sqlstm.sqhstl[27] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[27] = (         int  )sizeof(int);
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pTarget->asUpFlux);
  sqlstm.sqhstl[28] = (unsigned long )19;
  sqlstm.sqhsts[28] = (         int  )19;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pTarget->asDuration);
  sqlstm.sqhstl[29] = (unsigned long )19;
  sqlstm.sqhsts[29] = (         int  )19;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pTarget->aiCityID);
  sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[30] = (         int  )sizeof(int);
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pTarget->asDownFlux);
  sqlstm.sqhstl[31] = (unsigned long )19;
  sqlstm.sqhsts[31] = (         int  )19;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[32] = (unsigned long )61;
  sqlstm.sqhsts[32] = (         int  )61;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pTarget->asTotalFlux);
  sqlstm.sqhstl[33] = (unsigned long )19;
  sqlstm.sqhsts[33] = (         int  )19;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pTarget->asStatus);
  sqlstm.sqhstl[34] = (unsigned long )4;
  sqlstm.sqhsts[34] = (         int  )4;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pTarget->aiBillCycleSeq);
  sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[35] = (         int  )sizeof(int);
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pTarget->asCurrBalance);
  sqlstm.sqhstl[36] = (unsigned long )19;
  sqlstm.sqhsts[36] = (         int  )19;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pTarget->aiCreateCycleSeq);
  sqlstm.sqhstl[37] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[37] = (         int  )sizeof(int);
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pTarget->asRateKey1);
  sqlstm.sqhstl[38] = (unsigned long )31;
  sqlstm.sqhsts[38] = (         int  )31;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pTarget->asRateKey2);
  sqlstm.sqhstl[39] = (unsigned long )31;
  sqlstm.sqhsts[39] = (         int  )31;
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pTarget->asRateKey3);
  sqlstm.sqhstl[40] = (unsigned long )31;
  sqlstm.sqhsts[40] = (         int  )31;
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pTarget->aiPureCycleSeq);
  sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[41] = (         int  )sizeof(int);
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pTarget->aiDirection);
  sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[42] = (         int  )sizeof(int);
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqharc[42] = (unsigned long  *)0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)(pTarget->aiFileClassID);
  sqlstm.sqhstl[43] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[43] = (         int  )sizeof(int);
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqharc[43] = (unsigned long  *)0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
  sqlstm.sqhstv[44] = (unsigned char  *)(pTarget->asExceptionType);
  sqlstm.sqhstl[44] = (unsigned long )6;
  sqlstm.sqhsts[44] = (         int  )6;
  sqlstm.sqindv[44] = (         short *)0;
  sqlstm.sqinds[44] = (         int  )0;
  sqlstm.sqharm[44] = (unsigned long )0;
  sqlstm.sqharc[44] = (unsigned long  *)0;
  sqlstm.sqadto[44] = (unsigned short )0;
  sqlstm.sqtdso[44] = (unsigned short )0;
  sqlstm.sqhstv[45] = (unsigned char  *)(pTarget->asOrigUsageTypeID);
  sqlstm.sqhstl[45] = (unsigned long )13;
  sqlstm.sqhsts[45] = (         int  )13;
  sqlstm.sqindv[45] = (         short *)0;
  sqlstm.sqinds[45] = (         int  )0;
  sqlstm.sqharm[45] = (unsigned long )0;
  sqlstm.sqharc[45] = (unsigned long  *)0;
  sqlstm.sqadto[45] = (unsigned short )0;
  sqlstm.sqtdso[45] = (unsigned short )0;
  sqlstm.sqhstv[46] = (unsigned char  *)(pTarget->aiTotalDueUnits);
  sqlstm.sqhstl[46] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[46] = (         int  )sizeof(int);
  sqlstm.sqindv[46] = (         short *)0;
  sqlstm.sqinds[46] = (         int  )0;
  sqlstm.sqharm[46] = (unsigned long )0;
  sqlstm.sqharc[46] = (unsigned long  *)0;
  sqlstm.sqadto[46] = (unsigned short )0;
  sqlstm.sqtdso[46] = (unsigned short )0;
  sqlstm.sqhstv[47] = (unsigned char  *)(pTarget->asStlAmount);
  sqlstm.sqhstl[47] = (unsigned long )19;
  sqlstm.sqhsts[47] = (         int  )19;
  sqlstm.sqindv[47] = (         short *)0;
  sqlstm.sqinds[47] = (         int  )0;
  sqlstm.sqharm[47] = (unsigned long )0;
  sqlstm.sqharc[47] = (unsigned long  *)0;
  sqlstm.sqadto[47] = (unsigned short )0;
  sqlstm.sqtdso[47] = (unsigned short )0;
  sqlstm.sqhstv[48] = (unsigned char  *)(pTarget->asPostFlag);
  sqlstm.sqhstl[48] = (unsigned long )5;
  sqlstm.sqhsts[48] = (         int  )5;
  sqlstm.sqindv[48] = (         short *)0;
  sqlstm.sqinds[48] = (         int  )0;
  sqlstm.sqharm[48] = (unsigned long )0;
  sqlstm.sqharc[48] = (unsigned long  *)0;
  sqlstm.sqadto[48] = (unsigned short )0;
  sqlstm.sqtdso[48] = (unsigned short )0;
  sqlstm.sqhstv[49] = (unsigned char  *)(pTarget->aiIsPrepay);
  sqlstm.sqhstl[49] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[49] = (         int  )sizeof(int);
  sqlstm.sqindv[49] = (         short *)0;
  sqlstm.sqinds[49] = (         int  )0;
  sqlstm.sqharm[49] = (unsigned long )0;
  sqlstm.sqharc[49] = (unsigned long  *)0;
  sqlstm.sqadto[49] = (unsigned short )0;
  sqlstm.sqtdso[49] = (unsigned short )0;
  sqlstm.sqhstv[50] = (unsigned char  *)(pTarget->aiFileID);
  sqlstm.sqhstl[50] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[50] = (         int  )sizeof(int);
  sqlstm.sqindv[50] = (         short *)0;
  sqlstm.sqinds[50] = (         int  )0;
  sqlstm.sqharm[50] = (unsigned long )0;
  sqlstm.sqharc[50] = (unsigned long  *)0;
  sqlstm.sqadto[50] = (unsigned short )0;
  sqlstm.sqtdso[50] = (unsigned short )0;
  sqlstm.sqhstv[51] = (unsigned char  *)(pTarget->aiParentFileID);
  sqlstm.sqhstl[51] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[51] = (         int  )sizeof(int);
  sqlstm.sqindv[51] = (         short *)0;
  sqlstm.sqinds[51] = (         int  )0;
  sqlstm.sqharm[51] = (unsigned long )0;
  sqlstm.sqharc[51] = (unsigned long  *)0;
  sqlstm.sqadto[51] = (unsigned short )0;
  sqlstm.sqtdso[51] = (unsigned short )0;
  sqlstm.sqhstv[52] = (unsigned char  *)(pTarget->asTableName);
  sqlstm.sqhstl[52] = (unsigned long )31;
  sqlstm.sqhsts[52] = (         int  )31;
  sqlstm.sqindv[52] = (         short *)0;
  sqlstm.sqinds[52] = (         int  )0;
  sqlstm.sqharm[52] = (unsigned long )0;
  sqlstm.sqharc[52] = (unsigned long  *)0;
  sqlstm.sqadto[52] = (unsigned short )0;
  sqlstm.sqtdso[52] = (unsigned short )0;
  sqlstm.sqhstv[53] = (unsigned char  *)(pTarget->asCallingCompanyID);
  sqlstm.sqhstl[53] = (unsigned long )19;
  sqlstm.sqhsts[53] = (         int  )19;
  sqlstm.sqindv[53] = (         short *)0;
  sqlstm.sqinds[53] = (         int  )0;
  sqlstm.sqharm[53] = (unsigned long )0;
  sqlstm.sqharc[53] = (unsigned long  *)0;
  sqlstm.sqadto[53] = (unsigned short )0;
  sqlstm.sqtdso[53] = (unsigned short )0;
  sqlstm.sqhstv[54] = (unsigned char  *)(pTarget->asCalledCompanyID);
  sqlstm.sqhstl[54] = (unsigned long )19;
  sqlstm.sqhsts[54] = (         int  )19;
  sqlstm.sqindv[54] = (         short *)0;
  sqlstm.sqinds[54] = (         int  )0;
  sqlstm.sqharm[54] = (unsigned long )0;
  sqlstm.sqharc[54] = (unsigned long  *)0;
  sqlstm.sqadto[54] = (unsigned short )0;
  sqlstm.sqtdso[54] = (unsigned short )0;
  sqlstm.sqhstv[55] = (unsigned char  *)(pTarget->asSwitchCompanyID);
  sqlstm.sqhstl[55] = (unsigned long )19;
  sqlstm.sqhsts[55] = (         int  )19;
  sqlstm.sqindv[55] = (         short *)0;
  sqlstm.sqinds[55] = (         int  )0;
  sqlstm.sqharm[55] = (unsigned long )0;
  sqlstm.sqharc[55] = (unsigned long  *)0;
  sqlstm.sqadto[55] = (unsigned short )0;
  sqlstm.sqtdso[55] = (unsigned short )0;
  sqlstm.sqhstv[56] = (unsigned char  *)(pTarget->asProvinceID);
  sqlstm.sqhstl[56] = (unsigned long )21;
  sqlstm.sqhsts[56] = (         int  )21;
  sqlstm.sqindv[56] = (         short *)0;
  sqlstm.sqinds[56] = (         int  )0;
  sqlstm.sqharm[56] = (unsigned long )0;
  sqlstm.sqharc[56] = (unsigned long  *)0;
  sqlstm.sqadto[56] = (unsigned short )0;
  sqlstm.sqtdso[56] = (unsigned short )0;
  sqlstm.sqhstv[57] = (unsigned char  *)(pTarget->asDurationMinnum);
  sqlstm.sqhstl[57] = (unsigned long )19;
  sqlstm.sqhsts[57] = (         int  )19;
  sqlstm.sqindv[57] = (         short *)0;
  sqlstm.sqinds[57] = (         int  )0;
  sqlstm.sqharm[57] = (unsigned long )0;
  sqlstm.sqharc[57] = (unsigned long  *)0;
  sqlstm.sqadto[57] = (unsigned short )0;
  sqlstm.sqtdso[57] = (unsigned short )0;
  sqlstm.sqhstv[58] = (unsigned char  *)(pTarget->asDurationSec6);
  sqlstm.sqhstl[58] = (unsigned long )19;
  sqlstm.sqhsts[58] = (         int  )19;
  sqlstm.sqindv[58] = (         short *)0;
  sqlstm.sqinds[58] = (         int  )0;
  sqlstm.sqharm[58] = (unsigned long )0;
  sqlstm.sqharc[58] = (unsigned long  *)0;
  sqlstm.sqadto[58] = (unsigned short )0;
  sqlstm.sqtdso[58] = (unsigned short )0;
  sqlstm.sqhstv[59] = (unsigned char  *)(pTarget->asInTrunkGroup);
  sqlstm.sqhstl[59] = (unsigned long )16;
  sqlstm.sqhsts[59] = (         int  )16;
  sqlstm.sqindv[59] = (         short *)0;
  sqlstm.sqinds[59] = (         int  )0;
  sqlstm.sqharm[59] = (unsigned long )0;
  sqlstm.sqharc[59] = (unsigned long  *)0;
  sqlstm.sqadto[59] = (unsigned short )0;
  sqlstm.sqtdso[59] = (unsigned short )0;
  sqlstm.sqhstv[60] = (unsigned char  *)(pTarget->asOutTrunkGroup);
  sqlstm.sqhstl[60] = (unsigned long )16;
  sqlstm.sqhsts[60] = (         int  )16;
  sqlstm.sqindv[60] = (         short *)0;
  sqlstm.sqinds[60] = (         int  )0;
  sqlstm.sqharm[60] = (unsigned long )0;
  sqlstm.sqharc[60] = (unsigned long  *)0;
  sqlstm.sqadto[60] = (unsigned short )0;
  sqlstm.sqtdso[60] = (unsigned short )0;
  sqlstm.sqhstv[61] = (unsigned char  *)(pTarget->asCallingNumberCompanyID);
  sqlstm.sqhstl[61] = (unsigned long )19;
  sqlstm.sqhsts[61] = (         int  )19;
  sqlstm.sqindv[61] = (         short *)0;
  sqlstm.sqinds[61] = (         int  )0;
  sqlstm.sqharm[61] = (unsigned long )0;
  sqlstm.sqharc[61] = (unsigned long  *)0;
  sqlstm.sqadto[61] = (unsigned short )0;
  sqlstm.sqtdso[61] = (unsigned short )0;
  sqlstm.sqhstv[62] = (unsigned char  *)(pTarget->asCalledNumberCompanyID);
  sqlstm.sqhstl[62] = (unsigned long )19;
  sqlstm.sqhsts[62] = (         int  )19;
  sqlstm.sqindv[62] = (         short *)0;
  sqlstm.sqinds[62] = (         int  )0;
  sqlstm.sqharm[62] = (unsigned long )0;
  sqlstm.sqharc[62] = (unsigned long  *)0;
  sqlstm.sqadto[62] = (unsigned short )0;
  sqlstm.sqtdso[62] = (unsigned short )0;
  sqlstm.sqhstv[63] = (unsigned char  *)(pTarget->asCallingGroupID);
  sqlstm.sqhstl[63] = (unsigned long )16;
  sqlstm.sqhsts[63] = (         int  )16;
  sqlstm.sqindv[63] = (         short *)0;
  sqlstm.sqinds[63] = (         int  )0;
  sqlstm.sqharm[63] = (unsigned long )0;
  sqlstm.sqharc[63] = (unsigned long  *)0;
  sqlstm.sqadto[63] = (unsigned short )0;
  sqlstm.sqtdso[63] = (unsigned short )0;
  sqlstm.sqhstv[64] = (unsigned char  *)(pTarget->asCalledGroupID);
  sqlstm.sqhstl[64] = (unsigned long )16;
  sqlstm.sqhsts[64] = (         int  )16;
  sqlstm.sqindv[64] = (         short *)0;
  sqlstm.sqinds[64] = (         int  )0;
  sqlstm.sqharm[64] = (unsigned long )0;
  sqlstm.sqharc[64] = (unsigned long  *)0;
  sqlstm.sqadto[64] = (unsigned short )0;
  sqlstm.sqtdso[64] = (unsigned short )0;
  sqlstm.sqhstv[65] = (unsigned char  *)(pTarget->asStlObject);
  sqlstm.sqhstl[65] = (unsigned long )19;
  sqlstm.sqhsts[65] = (         int  )19;
  sqlstm.sqindv[65] = (         short *)0;
  sqlstm.sqinds[65] = (         int  )0;
  sqlstm.sqharm[65] = (unsigned long )0;
  sqlstm.sqharc[65] = (unsigned long  *)0;
  sqlstm.sqadto[65] = (unsigned short )0;
  sqlstm.sqtdso[65] = (unsigned short )0;
  sqlstm.sqhstv[66] = (unsigned char  *)(pTarget->asProdPropID);
  sqlstm.sqhstl[66] = (unsigned long )19;
  sqlstm.sqhsts[66] = (         int  )19;
  sqlstm.sqindv[66] = (         short *)0;
  sqlstm.sqinds[66] = (         int  )0;
  sqlstm.sqharm[66] = (unsigned long )0;
  sqlstm.sqharc[66] = (unsigned long  *)0;
  sqlstm.sqadto[66] = (unsigned short )0;
  sqlstm.sqtdso[66] = (unsigned short )0;
  sqlstm.sqhstv[67] = (unsigned char  *)(pTarget->asCallingSubType);
  sqlstm.sqhstl[67] = (unsigned long )19;
  sqlstm.sqhsts[67] = (         int  )19;
  sqlstm.sqindv[67] = (         short *)0;
  sqlstm.sqinds[67] = (         int  )0;
  sqlstm.sqharm[67] = (unsigned long )0;
  sqlstm.sqharc[67] = (unsigned long  *)0;
  sqlstm.sqadto[67] = (unsigned short )0;
  sqlstm.sqtdso[67] = (unsigned short )0;
  sqlstm.sqhstv[68] = (unsigned char  *)(pTarget->asCalledSubType);
  sqlstm.sqhstl[68] = (unsigned long )19;
  sqlstm.sqhsts[68] = (         int  )19;
  sqlstm.sqindv[68] = (         short *)0;
  sqlstm.sqinds[68] = (         int  )0;
  sqlstm.sqharm[68] = (unsigned long )0;
  sqlstm.sqharc[68] = (unsigned long  *)0;
  sqlstm.sqadto[68] = (unsigned short )0;
  sqlstm.sqtdso[68] = (unsigned short )0;
  sqlstm.sqhstv[69] = (unsigned char  *)(pTarget->aiStlDirection);
  sqlstm.sqhstl[69] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[69] = (         int  )sizeof(int);
  sqlstm.sqindv[69] = (         short *)0;
  sqlstm.sqinds[69] = (         int  )0;
  sqlstm.sqharm[69] = (unsigned long )0;
  sqlstm.sqharc[69] = (unsigned long  *)0;
  sqlstm.sqadto[69] = (unsigned short )0;
  sqlstm.sqtdso[69] = (unsigned short )0;
  sqlstm.sqhstv[70] = (unsigned char  *)(pTarget->asPreCallType);
  sqlstm.sqhstl[70] = (unsigned long )31;
  sqlstm.sqhsts[70] = (         int  )31;
  sqlstm.sqindv[70] = (         short *)0;
  sqlstm.sqinds[70] = (         int  )0;
  sqlstm.sqharm[70] = (unsigned long )0;
  sqlstm.sqharc[70] = (unsigned long  *)0;
  sqlstm.sqadto[70] = (unsigned short )0;
  sqlstm.sqtdso[70] = (unsigned short )0;
  sqlstm.sqhstv[71] = (unsigned char  *)(pTarget->asTurnCode);
  sqlstm.sqhstl[71] = (unsigned long )51;
  sqlstm.sqhsts[71] = (         int  )51;
  sqlstm.sqindv[71] = (         short *)0;
  sqlstm.sqinds[71] = (         int  )0;
  sqlstm.sqharm[71] = (unsigned long )0;
  sqlstm.sqharc[71] = (unsigned long  *)0;
  sqlstm.sqadto[71] = (unsigned short )0;
  sqlstm.sqtdso[71] = (unsigned short )0;
  sqlstm.sqhstv[72] = (unsigned char  *)(pTarget->asTurnCodeCompanyID);
  sqlstm.sqhstl[72] = (unsigned long )11;
  sqlstm.sqhsts[72] = (         int  )11;
  sqlstm.sqindv[72] = (         short *)0;
  sqlstm.sqinds[72] = (         int  )0;
  sqlstm.sqharm[72] = (unsigned long )0;
  sqlstm.sqharc[72] = (unsigned long  *)0;
  sqlstm.sqadto[72] = (unsigned short )0;
  sqlstm.sqtdso[72] = (unsigned short )0;
  sqlstm.sqhstv[73] = (unsigned char  *)(pTarget->asTurnCodeProvinceID);
  sqlstm.sqhstl[73] = (unsigned long )21;
  sqlstm.sqhsts[73] = (         int  )21;
  sqlstm.sqindv[73] = (         short *)0;
  sqlstm.sqinds[73] = (         int  )0;
  sqlstm.sqharm[73] = (unsigned long )0;
  sqlstm.sqharc[73] = (unsigned long  *)0;
  sqlstm.sqadto[73] = (unsigned short )0;
  sqlstm.sqtdso[73] = (unsigned short )0;
  sqlstm.sqhstv[74] = (unsigned char  *)(pTarget->aiTurnCodeCityID);
  sqlstm.sqhstl[74] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[74] = (         int  )sizeof(int);
  sqlstm.sqindv[74] = (         short *)0;
  sqlstm.sqinds[74] = (         int  )0;
  sqlstm.sqharm[74] = (unsigned long )0;
  sqlstm.sqharc[74] = (unsigned long  *)0;
  sqlstm.sqadto[74] = (unsigned short )0;
  sqlstm.sqtdso[74] = (unsigned short )0;
  sqlstm.sqhstv[75] = (unsigned char  *)(pTarget->asTurnCodeOperationTypeGrade);
  sqlstm.sqhstl[75] = (unsigned long )31;
  sqlstm.sqhsts[75] = (         int  )31;
  sqlstm.sqindv[75] = (         short *)0;
  sqlstm.sqinds[75] = (         int  )0;
  sqlstm.sqharm[75] = (unsigned long )0;
  sqlstm.sqharc[75] = (unsigned long  *)0;
  sqlstm.sqadto[75] = (unsigned short )0;
  sqlstm.sqtdso[75] = (unsigned short )0;
  sqlstm.sqhstv[76] = (unsigned char  *)(pTarget->asTurnType);
  sqlstm.sqhstl[76] = (unsigned long )31;
  sqlstm.sqhsts[76] = (         int  )31;
  sqlstm.sqindv[76] = (         short *)0;
  sqlstm.sqinds[76] = (         int  )0;
  sqlstm.sqharm[76] = (unsigned long )0;
  sqlstm.sqharc[76] = (unsigned long  *)0;
  sqlstm.sqadto[76] = (unsigned short )0;
  sqlstm.sqtdso[76] = (unsigned short )0;
  sqlstm.sqhstv[77] = (unsigned char  *)(pTarget->asTurnCdrID);
  sqlstm.sqhstl[77] = (unsigned long )5;
  sqlstm.sqhsts[77] = (         int  )5;
  sqlstm.sqindv[77] = (         short *)0;
  sqlstm.sqinds[77] = (         int  )0;
  sqlstm.sqharm[77] = (unsigned long )0;
  sqlstm.sqharc[77] = (unsigned long  *)0;
  sqlstm.sqadto[77] = (unsigned short )0;
  sqlstm.sqtdso[77] = (unsigned short )0;
  sqlstm.sqhstv[78] = (unsigned char  *)(pTarget->asSecondCallingNumber);
  sqlstm.sqhstl[78] = (unsigned long )31;
  sqlstm.sqhsts[78] = (         int  )31;
  sqlstm.sqindv[78] = (         short *)0;
  sqlstm.sqinds[78] = (         int  )0;
  sqlstm.sqharm[78] = (unsigned long )0;
  sqlstm.sqharc[78] = (unsigned long  *)0;
  sqlstm.sqadto[78] = (unsigned short )0;
  sqlstm.sqtdso[78] = (unsigned short )0;
  sqlstm.sqhstv[79] = (unsigned char  *)(pTarget->asSecondCallingAreaCode);
  sqlstm.sqhstl[79] = (unsigned long )11;
  sqlstm.sqhsts[79] = (         int  )11;
  sqlstm.sqindv[79] = (         short *)0;
  sqlstm.sqinds[79] = (         int  )0;
  sqlstm.sqharm[79] = (unsigned long )0;
  sqlstm.sqharc[79] = (unsigned long  *)0;
  sqlstm.sqadto[79] = (unsigned short )0;
  sqlstm.sqtdso[79] = (unsigned short )0;
  sqlstm.sqhstv[80] = (unsigned char  *)(pTarget->asSecondCallingGroupID);
  sqlstm.sqhstl[80] = (unsigned long )31;
  sqlstm.sqhsts[80] = (         int  )31;
  sqlstm.sqindv[80] = (         short *)0;
  sqlstm.sqinds[80] = (         int  )0;
  sqlstm.sqharm[80] = (unsigned long )0;
  sqlstm.sqharc[80] = (unsigned long  *)0;
  sqlstm.sqadto[80] = (unsigned short )0;
  sqlstm.sqtdso[80] = (unsigned short )0;
  sqlstm.sqhstv[81] = (unsigned char  *)(pTarget->asSecondCallingCompanyID);
  sqlstm.sqhstl[81] = (unsigned long )11;
  sqlstm.sqhsts[81] = (         int  )11;
  sqlstm.sqindv[81] = (         short *)0;
  sqlstm.sqinds[81] = (         int  )0;
  sqlstm.sqharm[81] = (unsigned long )0;
  sqlstm.sqharc[81] = (unsigned long  *)0;
  sqlstm.sqadto[81] = (unsigned short )0;
  sqlstm.sqtdso[81] = (unsigned short )0;
  sqlstm.sqhstv[82] = (unsigned char  *)(pTarget->asPreCallParentCdrID);
  sqlstm.sqhstl[82] = (unsigned long )21;
  sqlstm.sqhsts[82] = (         int  )21;
  sqlstm.sqindv[82] = (         short *)0;
  sqlstm.sqinds[82] = (         int  )0;
  sqlstm.sqharm[82] = (unsigned long )0;
  sqlstm.sqharc[82] = (unsigned long  *)0;
  sqlstm.sqadto[82] = (unsigned short )0;
  sqlstm.sqtdso[82] = (unsigned short )0;
  sqlstm.sqhstv[83] = (unsigned char  *)(pTarget->asPreCallSubCdrID);
  sqlstm.sqhstl[83] = (unsigned long )21;
  sqlstm.sqhsts[83] = (         int  )21;
  sqlstm.sqindv[83] = (         short *)0;
  sqlstm.sqinds[83] = (         int  )0;
  sqlstm.sqharm[83] = (unsigned long )0;
  sqlstm.sqharc[83] = (unsigned long  *)0;
  sqlstm.sqadto[83] = (unsigned short )0;
  sqlstm.sqtdso[83] = (unsigned short )0;
  sqlstm.sqhstv[84] = (unsigned char  *)(pTarget->asPreCallSubCdrNum);
  sqlstm.sqhstl[84] = (unsigned long )5;
  sqlstm.sqhsts[84] = (         int  )5;
  sqlstm.sqindv[84] = (         short *)0;
  sqlstm.sqinds[84] = (         int  )0;
  sqlstm.sqharm[84] = (unsigned long )0;
  sqlstm.sqharc[84] = (unsigned long  *)0;
  sqlstm.sqadto[84] = (unsigned short )0;
  sqlstm.sqtdso[84] = (unsigned short )0;
  sqlstm.sqhstv[85] = (unsigned char  *)(pTarget->asPreCallSubCdrSeq);
  sqlstm.sqhstl[85] = (unsigned long )11;
  sqlstm.sqhsts[85] = (         int  )11;
  sqlstm.sqindv[85] = (         short *)0;
  sqlstm.sqinds[85] = (         int  )0;
  sqlstm.sqharm[85] = (unsigned long )0;
  sqlstm.sqharc[85] = (unsigned long  *)0;
  sqlstm.sqadto[85] = (unsigned short )0;
  sqlstm.sqtdso[85] = (unsigned short )0;
  sqlstm.sqhstv[86] = (unsigned char  *)(pTarget->asPreCallUsageEventID);
  sqlstm.sqhstl[86] = (unsigned long )19;
  sqlstm.sqhsts[86] = (         int  )19;
  sqlstm.sqindv[86] = (         short *)0;
  sqlstm.sqinds[86] = (         int  )0;
  sqlstm.sqharm[86] = (unsigned long )0;
  sqlstm.sqharc[86] = (unsigned long  *)0;
  sqlstm.sqadto[86] = (unsigned short )0;
  sqlstm.sqtdso[86] = (unsigned short )0;
  sqlstm.sqhstv[87] = (unsigned char  *)(pTarget->asTurnParentCdrID);
  sqlstm.sqhstl[87] = (unsigned long )21;
  sqlstm.sqhsts[87] = (         int  )21;
  sqlstm.sqindv[87] = (         short *)0;
  sqlstm.sqinds[87] = (         int  )0;
  sqlstm.sqharm[87] = (unsigned long )0;
  sqlstm.sqharc[87] = (unsigned long  *)0;
  sqlstm.sqadto[87] = (unsigned short )0;
  sqlstm.sqtdso[87] = (unsigned short )0;
  sqlstm.sqhstv[88] = (unsigned char  *)(pTarget->asTurnSubCdrID);
  sqlstm.sqhstl[88] = (unsigned long )21;
  sqlstm.sqhsts[88] = (         int  )21;
  sqlstm.sqindv[88] = (         short *)0;
  sqlstm.sqinds[88] = (         int  )0;
  sqlstm.sqharm[88] = (unsigned long )0;
  sqlstm.sqharc[88] = (unsigned long  *)0;
  sqlstm.sqadto[88] = (unsigned short )0;
  sqlstm.sqtdso[88] = (unsigned short )0;
  sqlstm.sqhstv[89] = (unsigned char  *)(pTarget->asTurnSubCdrNum);
  sqlstm.sqhstl[89] = (unsigned long )5;
  sqlstm.sqhsts[89] = (         int  )5;
  sqlstm.sqindv[89] = (         short *)0;
  sqlstm.sqinds[89] = (         int  )0;
  sqlstm.sqharm[89] = (unsigned long )0;
  sqlstm.sqharc[89] = (unsigned long  *)0;
  sqlstm.sqadto[89] = (unsigned short )0;
  sqlstm.sqtdso[89] = (unsigned short )0;
  sqlstm.sqhstv[90] = (unsigned char  *)(pTarget->asTurnSubCdrSeq);
  sqlstm.sqhstl[90] = (unsigned long )11;
  sqlstm.sqhsts[90] = (         int  )11;
  sqlstm.sqindv[90] = (         short *)0;
  sqlstm.sqinds[90] = (         int  )0;
  sqlstm.sqharm[90] = (unsigned long )0;
  sqlstm.sqharc[90] = (unsigned long  *)0;
  sqlstm.sqadto[90] = (unsigned short )0;
  sqlstm.sqtdso[90] = (unsigned short )0;
  sqlstm.sqhstv[91] = (unsigned char  *)(pTarget->asTurnUsageEventID);
  sqlstm.sqhstl[91] = (unsigned long )19;
  sqlstm.sqhsts[91] = (         int  )19;
  sqlstm.sqindv[91] = (         short *)0;
  sqlstm.sqinds[91] = (         int  )0;
  sqlstm.sqharm[91] = (unsigned long )0;
  sqlstm.sqharc[91] = (unsigned long  *)0;
  sqlstm.sqadto[91] = (unsigned short )0;
  sqlstm.sqtdso[91] = (unsigned short )0;
  sqlstm.sqhstv[92] = (unsigned char  *)(pTarget->asInTrunkGenre);
  sqlstm.sqhstl[92] = (unsigned long )21;
  sqlstm.sqhsts[92] = (         int  )21;
  sqlstm.sqindv[92] = (         short *)0;
  sqlstm.sqinds[92] = (         int  )0;
  sqlstm.sqharm[92] = (unsigned long )0;
  sqlstm.sqharc[92] = (unsigned long  *)0;
  sqlstm.sqadto[92] = (unsigned short )0;
  sqlstm.sqtdso[92] = (unsigned short )0;
  sqlstm.sqhstv[93] = (unsigned char  *)(pTarget->asOutTrunkGenre);
  sqlstm.sqhstl[93] = (unsigned long )21;
  sqlstm.sqhsts[93] = (         int  )21;
  sqlstm.sqindv[93] = (         short *)0;
  sqlstm.sqinds[93] = (         int  )0;
  sqlstm.sqharm[93] = (unsigned long )0;
  sqlstm.sqharc[93] = (unsigned long  *)0;
  sqlstm.sqadto[93] = (unsigned short )0;
  sqlstm.sqtdso[93] = (unsigned short )0;
  sqlstm.sqhstv[94] = (unsigned char  *)(pTarget->asInTrunkNetType);
  sqlstm.sqhstl[94] = (unsigned long )21;
  sqlstm.sqhsts[94] = (         int  )21;
  sqlstm.sqindv[94] = (         short *)0;
  sqlstm.sqinds[94] = (         int  )0;
  sqlstm.sqharm[94] = (unsigned long )0;
  sqlstm.sqharc[94] = (unsigned long  *)0;
  sqlstm.sqadto[94] = (unsigned short )0;
  sqlstm.sqtdso[94] = (unsigned short )0;
  sqlstm.sqhstv[95] = (unsigned char  *)(pTarget->asOutTrunkNetType);
  sqlstm.sqhstl[95] = (unsigned long )21;
  sqlstm.sqhsts[95] = (         int  )21;
  sqlstm.sqindv[95] = (         short *)0;
  sqlstm.sqinds[95] = (         int  )0;
  sqlstm.sqharm[95] = (unsigned long )0;
  sqlstm.sqharc[95] = (unsigned long  *)0;
  sqlstm.sqadto[95] = (unsigned short )0;
  sqlstm.sqtdso[95] = (unsigned short )0;
  sqlstm.sqhstv[96] = (unsigned char  *)(pTarget->asCallingNumberType);
  sqlstm.sqhstl[96] = (unsigned long )21;
  sqlstm.sqhsts[96] = (         int  )21;
  sqlstm.sqindv[96] = (         short *)0;
  sqlstm.sqinds[96] = (         int  )0;
  sqlstm.sqharm[96] = (unsigned long )0;
  sqlstm.sqharc[96] = (unsigned long  *)0;
  sqlstm.sqadto[96] = (unsigned short )0;
  sqlstm.sqtdso[96] = (unsigned short )0;
  sqlstm.sqhstv[97] = (unsigned char  *)(pTarget->asCalledNumberType);
  sqlstm.sqhstl[97] = (unsigned long )21;
  sqlstm.sqhsts[97] = (         int  )21;
  sqlstm.sqindv[97] = (         short *)0;
  sqlstm.sqinds[97] = (         int  )0;
  sqlstm.sqharm[97] = (unsigned long )0;
  sqlstm.sqharc[97] = (unsigned long  *)0;
  sqlstm.sqadto[97] = (unsigned short )0;
  sqlstm.sqtdso[97] = (unsigned short )0;
  sqlstm.sqhstv[98] = (unsigned char  *)(pTarget->asCallingDomainID);
  sqlstm.sqhstl[98] = (unsigned long )21;
  sqlstm.sqhsts[98] = (         int  )21;
  sqlstm.sqindv[98] = (         short *)0;
  sqlstm.sqinds[98] = (         int  )0;
  sqlstm.sqharm[98] = (unsigned long )0;
  sqlstm.sqharc[98] = (unsigned long  *)0;
  sqlstm.sqadto[98] = (unsigned short )0;
  sqlstm.sqtdso[98] = (unsigned short )0;
  sqlstm.sqhstv[99] = (unsigned char  *)(pTarget->asCalledDomainID);
  sqlstm.sqhstl[99] = (unsigned long )21;
  sqlstm.sqhsts[99] = (         int  )21;
  sqlstm.sqindv[99] = (         short *)0;
  sqlstm.sqinds[99] = (         int  )0;
  sqlstm.sqharm[99] = (unsigned long )0;
  sqlstm.sqharc[99] = (unsigned long  *)0;
  sqlstm.sqadto[99] = (unsigned short )0;
  sqlstm.sqtdso[99] = (unsigned short )0;
  sqlstm.sqhstv[100] = (unsigned char  *)(pTarget->asSecondSubType);
  sqlstm.sqhstl[100] = (unsigned long )21;
  sqlstm.sqhsts[100] = (         int  )21;
  sqlstm.sqindv[100] = (         short *)0;
  sqlstm.sqinds[100] = (         int  )0;
  sqlstm.sqharm[100] = (unsigned long )0;
  sqlstm.sqharc[100] = (unsigned long  *)0;
  sqlstm.sqadto[100] = (unsigned short )0;
  sqlstm.sqtdso[100] = (unsigned short )0;
  sqlstm.sqhstv[101] = (unsigned char  *)(pTarget->asSecondCallingRoamnumber);
  sqlstm.sqhstl[101] = (unsigned long )31;
  sqlstm.sqhsts[101] = (         int  )31;
  sqlstm.sqindv[101] = (         short *)0;
  sqlstm.sqinds[101] = (         int  )0;
  sqlstm.sqharm[101] = (unsigned long )0;
  sqlstm.sqharc[101] = (unsigned long  *)0;
  sqlstm.sqadto[101] = (unsigned short )0;
  sqlstm.sqtdso[101] = (unsigned short )0;
  sqlstm.sqhstv[102] = (unsigned char  *)(pTarget->asViewCall);
  sqlstm.sqhstl[102] = (unsigned long )11;
  sqlstm.sqhsts[102] = (         int  )11;
  sqlstm.sqindv[102] = (         short *)0;
  sqlstm.sqinds[102] = (         int  )0;
  sqlstm.sqharm[102] = (unsigned long )0;
  sqlstm.sqharc[102] = (unsigned long  *)0;
  sqlstm.sqadto[102] = (unsigned short )0;
  sqlstm.sqtdso[102] = (unsigned short )0;
  sqlstm.sqhstv[103] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[103] = (unsigned long )3;
  sqlstm.sqhsts[103] = (         int  )3;
  sqlstm.sqindv[103] = (         short *)0;
  sqlstm.sqinds[103] = (         int  )0;
  sqlstm.sqharm[103] = (unsigned long )0;
  sqlstm.sqharc[103] = (unsigned long  *)0;
  sqlstm.sqadto[103] = (unsigned short )0;
  sqlstm.sqtdso[103] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn insert into T_TEMPLATE_YD_GW_UE")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

int GetSettBillStorSeq()
{
	int iSettBillStorSeq=0;
	
	/* EXEC SQL SELECT SETT_BILL_STOR_SEQ.nextval INTO :iSettBillStorSeq FROM DUAL ; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 104;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select SETT_BILL_STOR_SEQ.nextval  into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )950;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iSettBillStorSeq;
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


	CheckSqlError("Get iSettBillStorSeq ERROR");
	
	return iSettBillStorSeq;
	
}

int SDGetSettBillStorLogToStruct(struct SettBillStorLogStruct *p,char sTableName[],char sCondition[])
{

	/*这里不要控制变量*/

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_BILL_STOR_SEQ,0),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(FILE_DATE,' '),\n\
				to_char(nvl(DEAL_TIME,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_BILL_STORSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )969;
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


		CheckSqlError(" PREPARE SETT_BILL_STORSCR SETT_BILL_STORCR");

		/* EXEC SQL DECLARE SETT_BILL_STORCR CURSOR FOR SETT_BILL_STORSCR; */ 

		CheckSqlError("Declare SETT_BILL_STORCR");

		/* EXEC SQL OPEN SETT_BILL_STORCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )988;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_BILL_STORCR;");

	/*这里不修改控制变量*/

/* FETCH */
		/* EXEC SQL FETCH SETT_BILL_STORCR INTO
			:p->iSettBillStorSeq,
			:p->sFileName,
			:p->sFileDate,
			:p->sDealTime,
			:p->sState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1003;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iSettBillStorSeq);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[1] = (unsigned long )65;
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


		CheckSqlError("Fetch SETT_BILL_STORCR");

	if(NoDataFetched){
		/* EXEC SQL CLOSE SETT_BILL_STORCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1038;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return FALSE;
	}
		/* EXEC SQL CLOSE SETT_BILL_STORCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1053;
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
int SDInsertStructToSettBillStorLog(struct SettBillStorLogStruct *p,char sTableName[])
{

/*获取seq值*/
		p->iSettBillStorSeq=GetSettBillStorSeq();

/*放置数据到静态缓冲*/
/*------单个数据不需要存数据-----*/

/* INSERT */
		char statement[8192];

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_BILL_STOR_SEQ,\n\
				FILE_NAME,\n\
				FILE_DATE,\n\
				DEAL_TIME,\n\
				STATE,\n\
				FILE_SIZE,\n\
				FILE_LINES)\n\
			VALUES (\n\
				:iSettBillStorSeq,\n\
				:sFileName,\n\
				:sFileDate,\n\
				to_date(:sDealTime,'yyyymmddhh24miss'),\n\
				:sState,\n\
				:iFileSize,\n\
				:iFileLines\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_BILL_STORTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1068;
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


		if(CheckSqlResult("Prepare insert statement SETT_BILL_STOR")<0) return -1;

		/* EXEC SQL EXECUTE SETT_BILL_STORTRG USING
				:p->iSettBillStorSeq,
				:p->sFileName,
				:p->sFileDate,
				:p->sDealTime,
				:p->sState,
				:p->iFileSize,
				:p->iFileLines; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1087;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(p->iSettBillStorSeq);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(p->sFileName);
  sqlstm.sqhstl[1] = (unsigned long )65;
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
  sqlstm.sqhstv[5] = (unsigned char  *)&(p->iFileSize);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(p->iFileLines);
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


		if(CheckSqlResult("Dyn insert into SETT_BILL_STOR")<0) return -1;

	return 0;
}

/*批量数据动态从TICKET_TYPE_MAP中用结构缓冲方式取数据*/
int EGetTicketTypeMapToStruct(struct TicketTypeMapStruct *p,
	struct TicketTypeMapStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(PROD_ID,' '),\n\
				nvl(IN_TRUNK_CARR_ID,' '),\n\
				nvl(OUT_TRUNK_CARR_ID,' '),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(FLAG,' '),\n\
				nvl(FEE_TYPE,' '),\n\
				nvl(PROD_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE TICKET_TYPE_MAPSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1130;
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


		CheckSqlError(" PREPARE TICKET_TYPE_MAPSCR TICKET_TYPE_MAPCR");

		/* EXEC SQL DECLARE TICKET_TYPE_MAPCR CURSOR FOR TICKET_TYPE_MAPSCR; */ 

		CheckSqlError("Declare TICKET_TYPE_MAPCR");

		/* EXEC SQL OPEN TICKET_TYPE_MAPCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1149;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open TICKET_TYPE_MAPCR;");


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

		/* EXEC SQL CLOSE TICKET_TYPE_MAPCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1164;
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
		/* EXEC SQL FETCH TICKET_TYPE_MAPCR INTO
			:pSource->aiReportItemID,
			:pSource->asProdID,
			:pSource->asInTrunkCarrID,
			:pSource->asOutTrunkCarrID,
			:pSource->asCallType,
			:pSource->asFlag,
			:pSource->asFeeType,
			:pSource->asProdType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1179;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )11;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asInTrunkCarrID);
  sqlstm.sqhstl[2] = (unsigned long )2;
  sqlstm.sqhsts[2] = (         int  )2;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asOutTrunkCarrID);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )2;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[4] = (unsigned long )2;
  sqlstm.sqhsts[4] = (         int  )2;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asFlag);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asFeeType);
  sqlstm.sqhstl[6] = (unsigned long )2;
  sqlstm.sqhsts[6] = (         int  )2;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asProdType);
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


		CheckSqlError("Fetch TICKET_TYPE_MAPCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE TICKET_TYPE_MAPCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1226;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=TICKET_TYPE_MAP_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		p->iReportItemID=		pSource->aiReportItemID[iCurPos];

		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sInTrunkCarrID,	pSource->asInTrunkCarrID[iCurPos]);
		strcpy(p->sOutTrunkCarrID,	pSource->asOutTrunkCarrID[iCurPos]);
		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sFlag,		pSource->asFlag[iCurPos]);
		strcpy(p->sFeeType,		pSource->asFeeType[iCurPos]);
		strcpy(p->sProdType,		pSource->asProdType[iCurPos]);

		AllTrim(p->sProdID);
		AllTrim(p->sInTrunkCarrID);
		AllTrim(p->sOutTrunkCarrID);
		AllTrim(p->sCallType);
		AllTrim(p->sFlag);
		AllTrim(p->sFeeType);
		AllTrim(p->sProdType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表TICKET_TYPE_MAP的链表释放函数**/
void DestroyTicketTypeMap(struct TicketTypeMapStruct *ptHead)
{
	struct TicketTypeMapStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitTicketTypeMap(struct TicketTypeMapStruct **pptHead)
{
	int iCnt=0;
	static struct TicketTypeMapStruct *pTemp,*ptHead=NULL;
	struct TicketTypeMapStruct Temp;
	struct TicketTypeMapStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyTicketTypeMap(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct TicketTypeMapStructIn));
	sprintf(TempIn.sTableName,"param.TICKET_TYPE_MAP");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetTicketTypeMapToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct TicketTypeMapStruct*)
			malloc(sizeof(struct TicketTypeMapStruct)))==NULL){

			DestroyTicketTypeMap(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct TicketTypeMapStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表TICKET_TYPE_MAP记录数%d",iCnt);
	}

	WriteProcMsg("加载表TICKET_TYPE_MAP完毕总记录数%d",iCnt);

	return iCnt;
}
/********************************20140910接口改造*************************************/

/*批量数据动态从SETT_TICKET_UE中用结构缓冲方式取数据*/
int EGetSettTicketUeToStruct(struct SettTicketUeStruct *p,
	struct SettTicketUeStructIn *pSource)
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
				nvl(GROUP_ID,'00'),\n\
				nvl(FILE_NAME,' '),\n\
				nvl(CALL_TYPE,'0'),\n\
				nvl(IN_TRUNK_SUB_TYPE,'0'),\n\
				nvl(OUT_TRUNK_SUB_TYPE,'9')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_TICKET_UESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1241;
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


		CheckSqlError(" PREPARE SETT_TICKET_UESCR SETT_TICKET_UECR");

		/* EXEC SQL DECLARE SETT_TICKET_UECR CURSOR FOR SETT_TICKET_UESCR; */ 

		CheckSqlError("Declare SETT_TICKET_UECR");

		/* EXEC SQL OPEN SETT_TICKET_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1260;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_TICKET_UECR;");


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

		/* EXEC SQL CLOSE SETT_TICKET_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1275;
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
		/* EXEC SQL FETCH SETT_TICKET_UECR INTO
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
			:pSource->asCallType,
			:pSource->asInTrunkSubType,
			:pSource->asOutTrunkSubType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1290;
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
  sqlstm.sqhstv[41] = (unsigned char  *)(pSource->asInTrunkSubType);
  sqlstm.sqhstl[41] = (unsigned long )3;
  sqlstm.sqhsts[41] = (         int  )3;
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pSource->asOutTrunkSubType);
  sqlstm.sqhstl[42] = (unsigned long )3;
  sqlstm.sqhsts[42] = (         int  )3;
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


		CheckSqlError("Fetch SETT_TICKET_UECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_TICKET_UECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1477;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_TICKET_UE_BUFLEN_IN)
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
		strcpy(p->sInTrunkSubType,		pSource->asInTrunkSubType[iCurPos]);
		strcpy(p->sOutTrunkSubType,		pSource->asOutTrunkSubType[iCurPos]);

		strcpy(p->sGroupID,				pSource->asGroupID[iCurPos]);

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
		AllTrim(p->sInTrunkSubType);
		AllTrim(p->sOutTrunkSubType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_settticketue(struct SettTicketUeStruct *pi,struct SettTicketUeStruct *po)
{/*数据移动部分*/

	memset((void*)po,0,sizeof(struct SettTicketUeStruct));

		strncpy(po->sUsageEventID,		pi->sUsageEventID,18);
		strncpy(po->sCityID,			pi->sCityID,6);
		strncpy(po->sCdrType,			pi->sCdrType,4);
		strncpy(po->sCallingCityID,		pi->sCallingCityID,8);
		strncpy(po->sCallingException,		pi->sCallingException,4);
		strncpy(po->sCallingType,		pi->sCallingType,4);
		strncpy(po->sCallingCompCode,		pi->sCallingCompCode,2);
		strncpy(po->sCallingAreaCode,		pi->sCallingAreaCode,8);
		strncpy(po->sCallingNumber,		pi->sCallingNumber,30);
		strncpy(po->sCalledCityID,		pi->sCalledCityID,8);
		strncpy(po->sCalledException,		pi->sCalledException,4);
		strncpy(po->sCalledNumberType,		pi->sCalledNumberType,4);
		strncpy(po->sCalledCompCode,		pi->sCalledCompCode,2);
		strncpy(po->sCalledAreaCode,		pi->sCalledAreaCode,8);
		strncpy(po->sCalledNumber,		pi->sCalledNumber,30);
		strncpy(po->sStartTime,			pi->sStartTime,16);
		strncpy(po->sEndTime,			pi->sEndTime,16);
		strncpy(po->sDuration,			pi->sDuration,18);
		strncpy(po->sInTrunkNumber,		pi->sInTrunkNumber,11);
		strncpy(po->sInCompanyCode,		pi->sInCompanyCode,4);
		strncpy(po->sInTrunkNetType,		pi->sInTrunkNetType,4);
		strncpy(po->sOutTrunkNumber,		pi->sOutTrunkNumber,11);
		strncpy(po->sOutCompanyCode,		pi->sOutCompanyCode,4);
		strncpy(po->sOutTrunkNetType,		pi->sOutTrunkNetType,4);
		strncpy(po->sIsFree,			pi->sIsFree,4);
		strncpy(po->sCallingLocation,		pi->sCallingLocation,4);
		strncpy(po->sSecondCallingLocation,	pi->sSecondCallingLocation,4);
		strncpy(po->sOrigCallingNumber,		pi->sOrigCallingNumber,36);
		strncpy(po->sOrigCalledNumber,		pi->sOrigCalledNumber,36);
		strncpy(po->sOrigSecondCallingNumber,	pi->sOrigSecondCallingNumber,36);
		strncpy(po->sExceptionType,		pi->sExceptionType,10);
		strncpy(po->sPreCallType,		pi->sPreCallType,4);
		strncpy(po->sTurnType,			pi->sTurnType,4);
		strncpy(po->sProdID,			pi->sProdID,15);
		strncpy(po->sRateUnitType,		pi->sRateUnitType,4);
		strncpy(po->sStlDuration,		pi->sStlDuration,18);
		strncpy(po->sRateID,			pi->sRateID,10);
		strncpy(po->sStlAmount,			pi->sStlAmount,18);

		strncpy(po->sInTrunkSubType,			pi->sInTrunkSubType,2);
		strncpy(po->sOutTrunkSubType,			pi->sOutTrunkSubType,2);

		strncpy(po->sGroupID,				pi->sGroupID,2);

		strncpy(po->sFileName,			pi->sFileName,64);
}
void mvitem_fmsettticketue(struct FSettTicketUeStruct *pi,struct SettTicketUeStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	memset((void*)po,0,sizeof(struct SettTicketUeStruct));

		strncpy(po->sUsageEventID,		pi->sUsageEventID,18);
		strncpy(po->sCityID,			pi->sCityID,6);
		strncpy(po->sCdrType,			pi->sCdrType,4);
		strncpy(po->sCallingCityID,		pi->sCallingCityID,8);
		strncpy(po->sCallingException,		pi->sCallingException,4);
		strncpy(po->sCallingType,		pi->sCallingType,4);
		strncpy(po->sCallingCompCode,		pi->sCallingCompCode,2);
		strncpy(po->sCallingAreaCode,		pi->sCallingAreaCode,8);
		strncpy(po->sCallingNumber,		pi->sCallingNumber,30);
		strncpy(po->sCalledCityID,		pi->sCalledCityID,8);
		strncpy(po->sCalledException,		pi->sCalledException,4);
		strncpy(po->sCalledNumberType,		pi->sCalledNumberType,4);
		strncpy(po->sCalledCompCode,		pi->sCalledCompCode,2);
		strncpy(po->sCalledAreaCode,		pi->sCalledAreaCode,8);
		strncpy(po->sCalledNumber,		pi->sCalledNumber,30);
		strncpy(po->sStartTime,			pi->sStartTime,16);
		strncpy(po->sEndTime,			pi->sEndTime,16);
		strncpy(po->sDuration,			pi->sDuration,18);
		strncpy(po->sInTrunkNumber,		pi->sInTrunkNumber,11);
		strncpy(po->sInCompanyCode,		pi->sInCompanyCode,4);
		strncpy(po->sInTrunkNetType,		pi->sInTrunkNetType,4);
		strncpy(po->sOutTrunkNumber,		pi->sOutTrunkNumber,11);
		strncpy(po->sOutCompanyCode,		pi->sOutCompanyCode,4);
		strncpy(po->sOutTrunkNetType,		pi->sOutTrunkNetType,4);
		strncpy(po->sIsFree,			pi->sIsFree,4);
		strncpy(po->sCallingLocation,		pi->sCallingLocation,4);
		strncpy(po->sSecondCallingLocation,	pi->sSecondCallingLocation,4);
		strncpy(po->sOrigCallingNumber,		pi->sOrigCallingNumber,36);
		strncpy(po->sOrigCalledNumber,		pi->sOrigCalledNumber,36);
		strncpy(po->sOrigSecondCallingNumber,	pi->sOrigSecondCallingNumber,36);
		strncpy(po->sExceptionType,		pi->sExceptionType,10);
		strncpy(po->sPreCallType,		pi->sPreCallType,4);
		strncpy(po->sTurnType,			pi->sTurnType,4);
		strncpy(po->sProdID,			pi->sProdID,15);
		strncpy(po->sRateUnitType,		pi->sRateUnitType,4);
		strncpy(po->sStlDuration,		pi->sStlDuration,18);
		strncpy(po->sRateID,			pi->sRateID,10);
		strncpy(po->sStlAmount,			pi->sStlAmount,18);
		
		strncpy(po->sInTrunkSubType,			pi->sInTrunkSubType,2);
		strncpy(po->sOutTrunkSubType,			pi->sOutTrunkSubType,2);

		AllTrim(po->sUsageEventID);
		AllTrim(po->sCityID);
		AllTrim(po->sCdrType);
		AllTrim(po->sCallingCityID);
		AllTrim(po->sCallingException);
		AllTrim(po->sCallingType);
		AllTrim(po->sCallingCompCode);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCallingNumber);
		AllTrim(po->sCalledCityID);
		AllTrim(po->sCalledException);
		AllTrim(po->sCalledNumberType);
		AllTrim(po->sCalledCompCode);
		AllTrim(po->sCalledAreaCode);
		AllTrim(po->sCalledNumber);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sDuration);
		AllTrim(po->sInTrunkNumber);
		AllTrim(po->sInCompanyCode);
		AllTrim(po->sInTrunkNetType);
		AllTrim(po->sOutTrunkNumber);
		AllTrim(po->sOutCompanyCode);
		AllTrim(po->sOutTrunkNetType);
		AllTrim(po->sIsFree);
		AllTrim(po->sCallingLocation);
		AllTrim(po->sSecondCallingLocation);
		AllTrim(po->sOrigCallingNumber);
		AllTrim(po->sOrigCalledNumber);
		AllTrim(po->sOrigSecondCallingNumber);
		AllTrim(po->sExceptionType);
		AllTrim(po->sPreCallType);
		AllTrim(po->sTurnType);
		AllTrim(po->sProdID);
		AllTrim(po->sRateUnitType);
		AllTrim(po->sStlDuration);
		AllTrim(po->sRateID);
		AllTrim(po->sStlAmount);
		AllTrim(po->sInTrunkSubType);
		AllTrim(po->sOutTrunkSubType);
}
void mvitem_mfsettticketue(struct SettTicketUeStruct *pi,struct FSettTicketUeStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettTicketUeStruct));

		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));
		strncpy(po->sCityID,pi->sCityID,strlen(pi->sCityID));
		strncpy(po->sCdrType,pi->sCdrType,strlen(pi->sCdrType));
		strncpy(po->sCallingCityID,pi->sCallingCityID,strlen(pi->sCallingCityID));
		strncpy(po->sCallingException,pi->sCallingException,strlen(pi->sCallingException));
		strncpy(po->sCallingType,pi->sCallingType,strlen(pi->sCallingType));
		strncpy(po->sCallingCompCode,pi->sCallingCompCode,strlen(pi->sCallingCompCode));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCalledCityID,pi->sCalledCityID,strlen(pi->sCalledCityID));
		strncpy(po->sCalledException,pi->sCalledException,strlen(pi->sCalledException));
		strncpy(po->sCalledNumberType,pi->sCalledNumberType,strlen(pi->sCalledNumberType));
		strncpy(po->sCalledCompCode,pi->sCalledCompCode,strlen(pi->sCalledCompCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sInTrunkNumber,pi->sInTrunkNumber,strlen(pi->sInTrunkNumber));
		strncpy(po->sInCompanyCode,pi->sInCompanyCode,strlen(pi->sInCompanyCode));
		strncpy(po->sInTrunkNetType,pi->sInTrunkNetType,strlen(pi->sInTrunkNetType));
		strncpy(po->sOutTrunkNumber,pi->sOutTrunkNumber,strlen(pi->sOutTrunkNumber));
		strncpy(po->sOutCompanyCode,pi->sOutCompanyCode,strlen(pi->sOutCompanyCode));
		strncpy(po->sOutTrunkNetType,pi->sOutTrunkNetType,strlen(pi->sOutTrunkNetType));
		strncpy(po->sIsFree,pi->sIsFree,strlen(pi->sIsFree));
		strncpy(po->sCallingLocation,pi->sCallingLocation,strlen(pi->sCallingLocation));
		strncpy(po->sSecondCallingLocation,pi->sSecondCallingLocation,strlen(pi->sSecondCallingLocation));
		strncpy(po->sOrigCallingNumber,pi->sOrigCallingNumber,strlen(pi->sOrigCallingNumber));
		strncpy(po->sOrigCalledNumber,pi->sOrigCalledNumber,strlen(pi->sOrigCalledNumber));
		strncpy(po->sOrigSecondCallingNumber,pi->sOrigSecondCallingNumber,strlen(pi->sOrigSecondCallingNumber));
		strncpy(po->sExceptionType,pi->sExceptionType,strlen(pi->sExceptionType));
		strncpy(po->sPreCallType,pi->sPreCallType,strlen(pi->sPreCallType));
		strncpy(po->sTurnType,pi->sTurnType,strlen(pi->sTurnType));
		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sRateUnitType,pi->sRateUnitType,strlen(pi->sRateUnitType));
		strncpy(po->sStlDuration,pi->sStlDuration,strlen(pi->sStlDuration));
		strncpy(po->sRateID,pi->sRateID,strlen(pi->sRateID));
		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));
		
		strncpy(po->sInTrunkSubType,pi->sInTrunkSubType,strlen(pi->sInTrunkSubType));
		strncpy(po->sOutTrunkSubType,pi->sOutTrunkSubType,strlen(pi->sOutTrunkSubType));

}
/**对表SETT_TICKET_UE的链表释放函数**/
void DestroySettTicketUe(struct SettTicketUeStruct *ptHead)
{
	struct SettTicketUeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettTicketUe(struct SettTicketUeStruct **pptHead)
{
	int iCnt=0;
	static struct SettTicketUeStruct *pTemp,*ptHead=NULL;
	struct SettTicketUeStruct Temp;
	struct SettTicketUeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettTicketUe(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct SettTicketUeStructIn));
	sprintf(TempIn.sTableName,"SETT_TICKET_UE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettTicketUeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettTicketUeStruct*)
			malloc(sizeof(struct SettTicketUeStruct)))==NULL){

			DestroySettTicketUe(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettTicketUeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_TICKET_UE记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_TICKET_UE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据结构缓冲写入SETT_TICKET_UE*/
int EInsertStructToSettTicketUe(struct SettTicketUeStruct *p,
	int iInsertFlag,struct SettTicketUeStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asUsageEventID[iCurPos],		p->sUsageEventID);
		strcpy(pTarget->asCityID[iCurPos],			p->sCityID);
		strcpy(pTarget->asCdrType[iCurPos],			p->sCdrType);
		strcpy(pTarget->asCallingCityID[iCurPos],		p->sCallingCityID);
		strcpy(pTarget->asCallingException[iCurPos],		p->sCallingException);
		strcpy(pTarget->asCallingType[iCurPos],			p->sCallingType);
		strcpy(pTarget->asCallingCompCode[iCurPos],		p->sCallingCompCode);
		strcpy(pTarget->asCallingAreaCode[iCurPos],		p->sCallingAreaCode);
		strcpy(pTarget->asCallingNumber[iCurPos],		p->sCallingNumber);
		strcpy(pTarget->asCalledCityID[iCurPos],		p->sCalledCityID);
		strcpy(pTarget->asCalledException[iCurPos],		p->sCalledException);
		strcpy(pTarget->asCalledNumberType[iCurPos],		p->sCalledNumberType);
		strcpy(pTarget->asCalledCompCode[iCurPos],		p->sCalledCompCode);
		strcpy(pTarget->asCalledAreaCode[iCurPos],		p->sCalledAreaCode);
		strcpy(pTarget->asCalledNumber[iCurPos],		p->sCalledNumber);
		strcpy(pTarget->asStartTime[iCurPos],			p->sStartTime);
		strcpy(pTarget->asEndTime[iCurPos],			p->sEndTime);
		strcpy(pTarget->asDuration[iCurPos],			p->sDuration);
		strcpy(pTarget->asInTrunkNumber[iCurPos],		p->sInTrunkNumber);
		strcpy(pTarget->asInCompanyCode[iCurPos],		p->sInCompanyCode);
		strcpy(pTarget->asInTrunkNetType[iCurPos],		p->sInTrunkNetType);
		strcpy(pTarget->asOutTrunkNumber[iCurPos],		p->sOutTrunkNumber);
		strcpy(pTarget->asOutCompanyCode[iCurPos],		p->sOutCompanyCode);
		strcpy(pTarget->asOutTrunkNetType[iCurPos],		p->sOutTrunkNetType);
		strcpy(pTarget->asIsFree[iCurPos],			p->sIsFree);
		strcpy(pTarget->asCallingLocation[iCurPos],		p->sCallingLocation);
		strcpy(pTarget->asSecondCallingLocation[iCurPos],	p->sSecondCallingLocation);
		strcpy(pTarget->asOrigCallingNumber[iCurPos],		p->sOrigCallingNumber);
		strcpy(pTarget->asOrigCalledNumber[iCurPos],		p->sOrigCalledNumber);
		strcpy(pTarget->asOrigSecondCallingNumber[iCurPos],	p->sOrigSecondCallingNumber);
		strcpy(pTarget->asExceptionType[iCurPos],		p->sExceptionType);
		strcpy(pTarget->asPreCallType[iCurPos],			p->sPreCallType);
		strcpy(pTarget->asTurnType[iCurPos],			p->sTurnType);
		strcpy(pTarget->asProdID[iCurPos],			p->sProdID);
		strcpy(pTarget->asRateUnitType[iCurPos],		p->sRateUnitType);
		strcpy(pTarget->asStlDuration[iCurPos],			p->sStlDuration);
		strcpy(pTarget->asRateID[iCurPos],			p->sRateID);
		strcpy(pTarget->asStlAmount[iCurPos],			p->sStlAmount);
		
		strcpy(pTarget->asInTrunkSubType[iCurPos],		p->sInTrunkSubType);
		strcpy(pTarget->asOutTrunkSubType[iCurPos],		p->sOutTrunkSubType);

		strcpy(pTarget->asGroupID[iCurPos],			p->sGroupID);

		strcpy(pTarget->asFileName[iCurPos],			p->sFileName);
		strcpy(pTarget->asCallType[iCurPos],			p->sCallType);
		
		strcpy(pTarget->asUsageSeq[iCurPos],			p->sUsageSeq);
		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_TICKET_UE_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				USAGE_EVENT_ID,\n\
				CITY_ID,\n\
				CDR_TYPE,\n\
				CALLING_CITY_ID,\n\
				CALLING_EXCEPTION,\n\
				CALLING_TYPE,\n\
				CALLING_COMP_CODE,\n\
				CALLING_AREA_CODE,\n\
				CALLING_NUMBER,\n\
				CALLED_CITY_ID,\n\
				CALLED_EXCEPTION,\n\
				CALLED_NUMBER_TYPE,\n\
				CALLED_COMP_CODE,\n\
				CALLED_AREA_CODE,\n\
				CALLED_NUMBER,\n\
				START_TIME,\n\
				END_TIME,\n\
				DURATION,\n\
				IN_TRUNK_NUMBER,\n\
				IN_COMPANY_CODE,\n\
				IN_TRUNK_NET_TYPE,\n\
				OUT_TRUNK_NUMBER,\n\
				OUT_COMPANY_CODE,\n\
				OUT_TRUNK_NET_TYPE,\n\
				IS_FREE,\n\
				CALLING_LOCATION,\n\
				SECOND_CALLING_LOCATION,\n\
				ORIG_CALLING_NUMBER,\n\
				ORIG_CALLED_NUMBER,\n\
				ORIG_SECOND_CALLING_NUMBER,\n\
				EXCEPTION_TYPE,\n\
				PRE_CALL_TYPE,\n\
				TURN_TYPE,\n\
				PROD_ID,\n\
				RATE_UNIT_TYPE,\n\
				STL_DURATION,\n\
				RATE_ID,\n\
				STL_AMOUNT,\n\
				GROUP_ID,\n\
				FILE_NAME,\n\
				CALL_TYPE,\n\
				IN_TRUNK_SUB_TYPE,\n\
				OUT_TRUNK_SUB_TYPE,\n\
				USAGE_SEQ)\n\
			VALUES (\n\
				:asUsageEventID,\n\
				:asCityID,\n\
				:asCdrType,\n\
				:asCallingCityID,\n\
				:asCallingException,\n\
				:asCallingType,\n\
				:asCallingCompCode,\n\
				:asCallingAreaCode,\n\
				:asCallingNumber,\n\
				:asCalledCityID,\n\
				:asCalledException,\n\
				:asCalledNumberType,\n\
				:asCalledCompCode,\n\
				:asCalledAreaCode,\n\
				:asCalledNumber,\n\
				:asStartTime,\n\
				:asEndTime,\n\
				to_number(:asDuration),\n\
				:asInTrunkNumber,\n\
				:asInCompanyCode,\n\
				:asInTrunkNetType,\n\
				:asOutTrunkNumber,\n\
				:asOutCompanyCode,\n\
				:asOutTrunkNetType,\n\
				:asIsFree,\n\
				:asCallingLocation,\n\
				:asSecondCallingLocation,\n\
				:asOrigCallingNumber,\n\
				:asOrigCalledNumber,\n\
				:asOrigSecondCallingNumber,\n\
				:asExceptionType,\n\
				:asPreCallType,\n\
				:asTurnType,\n\
				:asProdID,\n\
				:asRateUnitType,\n\
				to_number(:asStlDuration),\n\
				:asRateID,\n\
				to_number(:asStlAmount),\n\
				:asGroupID,\n\
				:asFileName,\n\
				:asCallType,\n\
				:asInTrunkSubType,\n\
				:asOutTrunkSubType,\n\
				SETT_USAGE_SEQ.nextval\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_TICKET_UETRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1492;
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


		if(CheckSqlResult("Prepare insert statement SETT_TICKET_UE")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_TICKET_UETRG USING
				:pTarget->asUsageEventID,
				:pTarget->asCityID,
				:pTarget->asCdrType,
				:pTarget->asCallingCityID,
				:pTarget->asCallingException,
				:pTarget->asCallingType,
				:pTarget->asCallingCompCode,
				:pTarget->asCallingAreaCode,
				:pTarget->asCallingNumber,
				:pTarget->asCalledCityID,
				:pTarget->asCalledException,
				:pTarget->asCalledNumberType,
				:pTarget->asCalledCompCode,
				:pTarget->asCalledAreaCode,
				:pTarget->asCalledNumber,
				:pTarget->asStartTime,
				:pTarget->asEndTime,
				:pTarget->asDuration,
				:pTarget->asInTrunkNumber,
				:pTarget->asInCompanyCode,
				:pTarget->asInTrunkNetType,
				:pTarget->asOutTrunkNumber,
				:pTarget->asOutCompanyCode,
				:pTarget->asOutTrunkNetType,
				:pTarget->asIsFree,
				:pTarget->asCallingLocation,
				:pTarget->asSecondCallingLocation,
				:pTarget->asOrigCallingNumber,
				:pTarget->asOrigCalledNumber,
				:pTarget->asOrigSecondCallingNumber,
				:pTarget->asExceptionType,
				:pTarget->asPreCallType,
				:pTarget->asTurnType,
				:pTarget->asProdID,
				:pTarget->asRateUnitType,
				:pTarget->asStlDuration,
				:pTarget->asRateID,
				:pTarget->asStlAmount,
				:pTarget->asGroupID,
				:pTarget->asFileName,
				:pTarget->asCallType,
				:pTarget->asInTrunkSubType,
				:pTarget->asOutTrunkSubType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1511;
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
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asCityID);
  sqlstm.sqhstl[1] = (unsigned long )7;
  sqlstm.sqhsts[1] = (         int  )7;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asCdrType);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallingCityID);
  sqlstm.sqhstl[3] = (unsigned long )9;
  sqlstm.sqhsts[3] = (         int  )9;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asCallingException);
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )5;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asCallingType);
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )5;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asCallingCompCode);
  sqlstm.sqhstl[6] = (unsigned long )3;
  sqlstm.sqhsts[6] = (         int  )3;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asCallingAreaCode);
  sqlstm.sqhstl[7] = (unsigned long )9;
  sqlstm.sqhsts[7] = (         int  )9;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asCallingNumber);
  sqlstm.sqhstl[8] = (unsigned long )31;
  sqlstm.sqhsts[8] = (         int  )31;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asCalledCityID);
  sqlstm.sqhstl[9] = (unsigned long )9;
  sqlstm.sqhsts[9] = (         int  )9;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asCalledException);
  sqlstm.sqhstl[10] = (unsigned long )5;
  sqlstm.sqhsts[10] = (         int  )5;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asCalledNumberType);
  sqlstm.sqhstl[11] = (unsigned long )5;
  sqlstm.sqhsts[11] = (         int  )5;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asCalledCompCode);
  sqlstm.sqhstl[12] = (unsigned long )3;
  sqlstm.sqhsts[12] = (         int  )3;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asCalledAreaCode);
  sqlstm.sqhstl[13] = (unsigned long )9;
  sqlstm.sqhsts[13] = (         int  )9;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asCalledNumber);
  sqlstm.sqhstl[14] = (unsigned long )31;
  sqlstm.sqhsts[14] = (         int  )31;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asStartTime);
  sqlstm.sqhstl[15] = (unsigned long )17;
  sqlstm.sqhsts[15] = (         int  )17;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asEndTime);
  sqlstm.sqhstl[16] = (unsigned long )17;
  sqlstm.sqhsts[16] = (         int  )17;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asDuration);
  sqlstm.sqhstl[17] = (unsigned long )19;
  sqlstm.sqhsts[17] = (         int  )19;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asInTrunkNumber);
  sqlstm.sqhstl[18] = (unsigned long )12;
  sqlstm.sqhsts[18] = (         int  )12;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asInCompanyCode);
  sqlstm.sqhstl[19] = (unsigned long )5;
  sqlstm.sqhsts[19] = (         int  )5;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asInTrunkNetType);
  sqlstm.sqhstl[20] = (unsigned long )5;
  sqlstm.sqhsts[20] = (         int  )5;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asOutTrunkNumber);
  sqlstm.sqhstl[21] = (unsigned long )12;
  sqlstm.sqhsts[21] = (         int  )12;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asOutCompanyCode);
  sqlstm.sqhstl[22] = (unsigned long )5;
  sqlstm.sqhsts[22] = (         int  )5;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asOutTrunkNetType);
  sqlstm.sqhstl[23] = (unsigned long )5;
  sqlstm.sqhsts[23] = (         int  )5;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asIsFree);
  sqlstm.sqhstl[24] = (unsigned long )5;
  sqlstm.sqhsts[24] = (         int  )5;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pTarget->asCallingLocation);
  sqlstm.sqhstl[25] = (unsigned long )5;
  sqlstm.sqhsts[25] = (         int  )5;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pTarget->asSecondCallingLocation);
  sqlstm.sqhstl[26] = (unsigned long )5;
  sqlstm.sqhsts[26] = (         int  )5;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pTarget->asOrigCallingNumber);
  sqlstm.sqhstl[27] = (unsigned long )37;
  sqlstm.sqhsts[27] = (         int  )37;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pTarget->asOrigCalledNumber);
  sqlstm.sqhstl[28] = (unsigned long )37;
  sqlstm.sqhsts[28] = (         int  )37;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pTarget->asOrigSecondCallingNumber);
  sqlstm.sqhstl[29] = (unsigned long )37;
  sqlstm.sqhsts[29] = (         int  )37;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pTarget->asExceptionType);
  sqlstm.sqhstl[30] = (unsigned long )11;
  sqlstm.sqhsts[30] = (         int  )11;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pTarget->asPreCallType);
  sqlstm.sqhstl[31] = (unsigned long )5;
  sqlstm.sqhsts[31] = (         int  )5;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pTarget->asTurnType);
  sqlstm.sqhstl[32] = (unsigned long )5;
  sqlstm.sqhsts[32] = (         int  )5;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[33] = (unsigned long )16;
  sqlstm.sqhsts[33] = (         int  )16;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqharc[33] = (unsigned long  *)0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)(pTarget->asRateUnitType);
  sqlstm.sqhstl[34] = (unsigned long )5;
  sqlstm.sqhsts[34] = (         int  )5;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqharc[34] = (unsigned long  *)0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pTarget->asStlDuration);
  sqlstm.sqhstl[35] = (unsigned long )19;
  sqlstm.sqhsts[35] = (         int  )19;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqharc[35] = (unsigned long  *)0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)(pTarget->asRateID);
  sqlstm.sqhstl[36] = (unsigned long )11;
  sqlstm.sqhsts[36] = (         int  )11;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqharc[36] = (unsigned long  *)0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)(pTarget->asStlAmount);
  sqlstm.sqhstl[37] = (unsigned long )19;
  sqlstm.sqhsts[37] = (         int  )19;
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqharc[37] = (unsigned long  *)0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[38] = (unsigned long )3;
  sqlstm.sqhsts[38] = (         int  )3;
  sqlstm.sqindv[38] = (         short *)0;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqharc[38] = (unsigned long  *)0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[39] = (unsigned long )65;
  sqlstm.sqhsts[39] = (         int  )65;
  sqlstm.sqindv[39] = (         short *)0;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqharc[39] = (unsigned long  *)0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[40] = (unsigned long )3;
  sqlstm.sqhsts[40] = (         int  )3;
  sqlstm.sqindv[40] = (         short *)0;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqharc[40] = (unsigned long  *)0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)(pTarget->asInTrunkSubType);
  sqlstm.sqhstl[41] = (unsigned long )3;
  sqlstm.sqhsts[41] = (         int  )3;
  sqlstm.sqindv[41] = (         short *)0;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqharc[41] = (unsigned long  *)0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)(pTarget->asOutTrunkSubType);
  sqlstm.sqhstl[42] = (unsigned long )3;
  sqlstm.sqhsts[42] = (         int  )3;
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


		if(CheckSqlResult("Dyn insert into SETT_TICKET_UE")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*批量数据动态从SETT_TICKET_SM中用结构缓冲方式取数据*/
int EGetSettTicketSmToStruct(struct SettTicketSmStruct *p,
	struct SettTicketSmStructIn *pSource)
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
				nvl(GROUP_ID,'00'),\n\
				nvl(CALL_TYPE,'0')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_TICKET_SMSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1698;
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


		CheckSqlError(" PREPARE SETT_TICKET_SMSCR SETT_TICKET_SMCR");

		/* EXEC SQL DECLARE SETT_TICKET_SMCR CURSOR FOR SETT_TICKET_SMSCR; */ 

		CheckSqlError("Declare SETT_TICKET_SMCR");

		/* EXEC SQL OPEN SETT_TICKET_SMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1717;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_TICKET_SMCR;");


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

		/* EXEC SQL CLOSE SETT_TICKET_SMCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1732;
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
		/* EXEC SQL FETCH SETT_TICKET_SMCR INTO
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
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )1747;
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
  sqlstm.sqhstl[4] = (unsigned long )9;
  sqlstm.sqhsts[4] = (         int  )9;
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
  sqlstm.sqhstl[8] = (unsigned long )9;
  sqlstm.sqhsts[8] = (         int  )9;
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
  sqlstm.sqhstl[25] = (unsigned long )4;
  sqlstm.sqhsts[25] = (         int  )4;
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


		CheckSqlError("Fetch SETT_TICKET_SMCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_TICKET_SMCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1870;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_TICKET_SM_BUFLEN_IN)
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
void mvitem_settticketsm(struct SettTicketSmStruct *pi,struct SettTicketSmStruct *po)
{/*数据移动部分*/

	memset((void*)po,0,sizeof(struct SettTicketSmStruct));

		strncpy(po->sProdID,		pi->sProdID,30);
		strncpy(po->sStartTime,		pi->sStartTime,18);
		strncpy(po->sEndTime,		pi->sEndTime,18);
		strncpy(po->sCallingNumber,	pi->sCallingNumber,32);
		strncpy(po->sCallingCityID,	pi->sCallingCityID,8);
		strncpy(po->sCallingCompanyID,	pi->sCallingCompanyID,2);
		strncpy(po->sCallingNumberType,	pi->sCallingNumberType,4);
		strncpy(po->sCalledNumber,	pi->sCalledNumber,32);
		strncpy(po->sCalledCityID,	pi->sCalledCityID,8);
		strncpy(po->sCalledCompanyID,	pi->sCalledCompanyID,2);
		strncpy(po->sCalledNumberType,	pi->sCalledNumberType,4);

		po->iCityID=			pi->iCityID;

		strncpy(po->sIsFree,		pi->sIsFree,4);

		po->iBillCycleSeq=		pi->iBillCycleSeq;

		strncpy(po->sExceptionType,	pi->sExceptionType,8);
		strncpy(po->sStlAmount,		pi->sStlAmount,18);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,32);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,32);
		strncpy(po->sStlDirection,	pi->sStlDirection,4);
		strncpy(po->sUpGw,		pi->sUpGw,32);
		strncpy(po->sDownGw,		pi->sDownGw,32);
		strncpy(po->sUpCompanyID,	pi->sUpCompanyID,2);
		strncpy(po->sDownCompanyID,	pi->sDownCompanyID,2);
		strncpy(po->sUsageEventID,	pi->sUsageEventID,18);
		strncpy(po->sFileName,		pi->sFileName,64);

		strncpy(po->sGroupID,		pi->sGroupID,3);
		strncpy(po->sCallType,		pi->sCallType,2);
}
void mvitem_fmsettticketsm(struct FSettTicketSmStruct *pi,struct SettTicketSmStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	memset((void*)po,0,sizeof(struct SettTicketSmStruct));

		strncpy(po->sProdID,		pi->sProdID,30);
		strncpy(po->sStartTime,		pi->sStartTime,18);
		strncpy(po->sEndTime,		pi->sEndTime,18);
		strncpy(po->sCallingNumber,	pi->sCallingNumber,32);
		strncpy(po->sCallingCityID,	pi->sCallingCityID,8);
		strncpy(po->sCallingCompanyID,	pi->sCallingCompanyID,2);
		strncpy(po->sCallingNumberType,	pi->sCallingNumberType,4);
		strncpy(po->sCalledNumber,	pi->sCalledNumber,32);
		strncpy(po->sCalledCityID,	pi->sCalledCityID,8);
		strncpy(po->sCalledCompanyID,	pi->sCalledCompanyID,2);
		strncpy(po->sCalledNumberType,	pi->sCalledNumberType,4);

		strncpy(sTemp,		pi->sCityID,8);sTemp[8]=0;
		po->iCityID=atoi(sTemp);

		strncpy(po->sIsFree,		pi->sIsFree,4);

		strncpy(sTemp,	pi->sBillCycleSeq,6);sTemp[6]=0;
		po->iBillCycleSeq=atoi(sTemp);

		strncpy(po->sExceptionType,	pi->sExceptionType,8);
		strncpy(po->sStlAmount,		pi->sStlAmount,18);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,32);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,32);
		strncpy(po->sStlDirection,	pi->sStlDirection,4);
		strncpy(po->sUpGw,		pi->sUpGw,32);
		strncpy(po->sDownGw,		pi->sDownGw,32);
		strncpy(po->sUpCompanyID,	pi->sUpCompanyID,2);
		strncpy(po->sDownCompanyID,	pi->sDownCompanyID,2);
		strncpy(po->sUsageEventID,	pi->sUsageEventID,18);

		AllTrim(po->sProdID);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sCallingNumber);
		AllTrim(po->sCallingCityID);
		AllTrim(po->sCallingCompanyID);
		AllTrim(po->sCallingNumberType);
		AllTrim(po->sCalledNumber);
		AllTrim(po->sCalledCityID);
		AllTrim(po->sCalledCompanyID);
		AllTrim(po->sCalledNumberType);
		AllTrim(po->sIsFree);
		AllTrim(po->sExceptionType);
		AllTrim(po->sStlAmount);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCalledAreaCode);
		AllTrim(po->sStlDirection);
		AllTrim(po->sUpGw);
		AllTrim(po->sDownGw);
		AllTrim(po->sUpCompanyID);
		AllTrim(po->sDownCompanyID);
		AllTrim(po->sUsageEventID);
		AllTrim(po->sFileName);
		AllTrim(po->sGroupID);
		AllTrim(po->sCallType);
}
void mvitem_mfsettticketsm(struct SettTicketSmStruct *pi,struct FSettTicketSmStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettTicketSmStruct));

		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCallingCityID,pi->sCallingCityID,strlen(pi->sCallingCityID));
		strncpy(po->sCallingCompanyID,pi->sCallingCompanyID,strlen(pi->sCallingCompanyID));
		strncpy(po->sCallingNumberType,pi->sCallingNumberType,strlen(pi->sCallingNumberType));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sCalledCityID,pi->sCalledCityID,strlen(pi->sCalledCityID));
		strncpy(po->sCalledCompanyID,pi->sCalledCompanyID,strlen(pi->sCalledCompanyID));
		strncpy(po->sCalledNumberType,pi->sCalledNumberType,strlen(pi->sCalledNumberType));

		sprintf(sTemp,"%08d",pi->iCityID);
		strncpy(po->sCityID,sTemp,8);

		strncpy(po->sIsFree,pi->sIsFree,strlen(pi->sIsFree));

		sprintf(sTemp,"%06d",pi->iBillCycleSeq);
		strncpy(po->sBillCycleSeq,sTemp,6);

		strncpy(po->sExceptionType,pi->sExceptionType,strlen(pi->sExceptionType));
		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sStlDirection,pi->sStlDirection,strlen(pi->sStlDirection));
		strncpy(po->sUpGw,pi->sUpGw,strlen(pi->sUpGw));
		strncpy(po->sDownGw,pi->sDownGw,strlen(pi->sDownGw));
		strncpy(po->sUpCompanyID,pi->sUpCompanyID,strlen(pi->sUpCompanyID));
		strncpy(po->sDownCompanyID,pi->sDownCompanyID,strlen(pi->sDownCompanyID));
		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));

}
/**对表SETT_TICKET_SM的链表释放函数**/
void DestroySettTicketSm(struct SettTicketSmStruct *ptHead)
{
	struct SettTicketSmStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettTicketSm(struct SettTicketSmStruct **pptHead)
{
	int iCnt=0;
	static struct SettTicketSmStruct *pTemp,*ptHead=NULL;
	struct SettTicketSmStruct Temp;
	struct SettTicketSmStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettTicketSm(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct SettTicketSmStructIn));
	sprintf(TempIn.sTableName,"SETT_TICKET_SM");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettTicketSmToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettTicketSmStruct*)
			malloc(sizeof(struct SettTicketSmStruct)))==NULL){

			DestroySettTicketSm(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettTicketSmStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_TICKET_SM记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_TICKET_SM完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据结构缓冲写入SETT_TICKET_SM*/
int EInsertStructToSettTicketSm(struct SettTicketSmStruct *p,
	int iInsertFlag,struct SettTicketSmStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asProdID[iCurPos],		p->sProdID);
		strcpy(pTarget->asStartTime[iCurPos],		p->sStartTime);
		strcpy(pTarget->asEndTime[iCurPos],		p->sEndTime);
		strcpy(pTarget->asCallingNumber[iCurPos],	p->sCallingNumber);
		strcpy(pTarget->asCallingCityID[iCurPos],	p->sCallingCityID);
		strcpy(pTarget->asCallingCompanyID[iCurPos],	p->sCallingCompanyID);
		strcpy(pTarget->asCallingNumberType[iCurPos],	p->sCallingNumberType);
		strcpy(pTarget->asCalledNumber[iCurPos],	p->sCalledNumber);
		strcpy(pTarget->asCalledCityID[iCurPos],	p->sCalledCityID);
		strcpy(pTarget->asCalledCompanyID[iCurPos],	p->sCalledCompanyID);
		strcpy(pTarget->asCalledNumberType[iCurPos],	p->sCalledNumberType);

		pTarget->aiCityID[iCurPos]=			p->iCityID;

		strcpy(pTarget->asIsFree[iCurPos],		p->sIsFree);

		pTarget->aiBillCycleSeq[iCurPos]=		p->iBillCycleSeq;

		strcpy(pTarget->asExceptionType[iCurPos],	p->sExceptionType);
		strcpy(pTarget->asStlAmount[iCurPos],		p->sStlAmount);
		strcpy(pTarget->asCallingAreaCode[iCurPos],	p->sCallingAreaCode);
		strcpy(pTarget->asCalledAreaCode[iCurPos],	p->sCalledAreaCode);
		strcpy(pTarget->asStlDirection[iCurPos],	p->sStlDirection);
		strcpy(pTarget->asUpGw[iCurPos],		p->sUpGw);
		strcpy(pTarget->asDownGw[iCurPos],		p->sDownGw);
		strcpy(pTarget->asUpCompanyID[iCurPos],		p->sUpCompanyID);
		strcpy(pTarget->asDownCompanyID[iCurPos],	p->sDownCompanyID);
		strcpy(pTarget->asUsageEventID[iCurPos],	p->sUsageEventID);
		strcpy(pTarget->asFileName[iCurPos],		p->sFileName);

		strcpy(pTarget->asGroupID[iCurPos],		p->sGroupID);
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_TICKET_SM_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				PROD_ID,\n\
				START_TIME,\n\
				END_TIME,\n\
				CALLING_NUMBER,\n\
				CALLING_CITY_ID,\n\
				CALLING_COMPANY_ID,\n\
				CALLING_NUMBER_TYPE,\n\
				CALLED_NUMBER,\n\
				CALLED_CITY_ID,\n\
				CALLED_COMPANY_ID,\n\
				CALLED_NUMBER_TYPE,\n\
				CITY_ID,\n\
				IS_FREE,\n\
				BILL_CYCLE_SEQ,\n\
				EXCEPTION_TYPE,\n\
				STL_AMOUNT,\n\
				CALLING_AREA_CODE,\n\
				CALLED_AREA_CODE,\n\
				STL_DIRECTION,\n\
				UP_GW,\n\
				DOWN_GW,\n\
				UP_COMPANY_ID,\n\
				DOWN_COMPANY_ID,\n\
				USAGE_EVENT_ID,\n\
				FILE_NAME,\n\
				GROUP_ID,\n\
				CALL_TYPE)\n\
			VALUES (\n\
				:asProdID,\n\
				:asStartTime,\n\
				:asEndTime,\n\
				:asCallingNumber,\n\
				:asCallingCityID,\n\
				:asCallingCompanyID,\n\
				:asCallingNumberType,\n\
				:asCalledNumber,\n\
				:asCalledCityID,\n\
				:asCalledCompanyID,\n\
				:asCalledNumberType,\n\
				:aiCityID,\n\
				:asIsFree,\n\
				:aiBillCycleSeq,\n\
				:asExceptionType,\n\
				to_number(:asStlAmount),\n\
				:asCallingAreaCode,\n\
				:asCalledAreaCode,\n\
				:asStlDirection,\n\
				:asUpGw,\n\
				:asDownGw,\n\
				:asUpCompanyID,\n\
				:asDownCompanyID,\n\
				to_number(:asUsageEventID),\n\
				:asFileName,\n\
				:asGroupID,\n\
				:asCallType\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_TICKET_SMTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1885;
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


		if(CheckSqlResult("Prepare insert statement SETT_TICKET_SM")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_TICKET_SMTRG USING
				:pTarget->asProdID,
				:pTarget->asStartTime,
				:pTarget->asEndTime,
				:pTarget->asCallingNumber,
				:pTarget->asCallingCityID,
				:pTarget->asCallingCompanyID,
				:pTarget->asCallingNumberType,
				:pTarget->asCalledNumber,
				:pTarget->asCalledCityID,
				:pTarget->asCalledCompanyID,
				:pTarget->asCalledNumberType,
				:pTarget->aiCityID,
				:pTarget->asIsFree,
				:pTarget->aiBillCycleSeq,
				:pTarget->asExceptionType,
				:pTarget->asStlAmount,
				:pTarget->asCallingAreaCode,
				:pTarget->asCalledAreaCode,
				:pTarget->asStlDirection,
				:pTarget->asUpGw,
				:pTarget->asDownGw,
				:pTarget->asUpCompanyID,
				:pTarget->asDownCompanyID,
				:pTarget->asUsageEventID,
				:pTarget->asFileName,
				:pTarget->asGroupID,
				:pTarget->asCallType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )1904;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )31;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asStartTime);
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )19;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asEndTime);
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )19;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallingNumber);
  sqlstm.sqhstl[3] = (unsigned long )33;
  sqlstm.sqhsts[3] = (         int  )33;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asCallingCityID);
  sqlstm.sqhstl[4] = (unsigned long )9;
  sqlstm.sqhsts[4] = (         int  )9;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asCallingCompanyID);
  sqlstm.sqhstl[5] = (unsigned long )3;
  sqlstm.sqhsts[5] = (         int  )3;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asCallingNumberType);
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )5;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asCalledNumber);
  sqlstm.sqhstl[7] = (unsigned long )33;
  sqlstm.sqhsts[7] = (         int  )33;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asCalledCityID);
  sqlstm.sqhstl[8] = (unsigned long )9;
  sqlstm.sqhsts[8] = (         int  )9;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asCalledCompanyID);
  sqlstm.sqhstl[9] = (unsigned long )3;
  sqlstm.sqhsts[9] = (         int  )3;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asCalledNumberType);
  sqlstm.sqhstl[10] = (unsigned long )5;
  sqlstm.sqhsts[10] = (         int  )5;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->aiCityID);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asIsFree);
  sqlstm.sqhstl[12] = (unsigned long )5;
  sqlstm.sqhsts[12] = (         int  )5;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->aiBillCycleSeq);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asExceptionType);
  sqlstm.sqhstl[14] = (unsigned long )9;
  sqlstm.sqhsts[14] = (         int  )9;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asStlAmount);
  sqlstm.sqhstl[15] = (unsigned long )19;
  sqlstm.sqhsts[15] = (         int  )19;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asCallingAreaCode);
  sqlstm.sqhstl[16] = (unsigned long )33;
  sqlstm.sqhsts[16] = (         int  )33;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asCalledAreaCode);
  sqlstm.sqhstl[17] = (unsigned long )33;
  sqlstm.sqhsts[17] = (         int  )33;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asStlDirection);
  sqlstm.sqhstl[18] = (unsigned long )5;
  sqlstm.sqhsts[18] = (         int  )5;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asUpGw);
  sqlstm.sqhstl[19] = (unsigned long )33;
  sqlstm.sqhsts[19] = (         int  )33;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asDownGw);
  sqlstm.sqhstl[20] = (unsigned long )33;
  sqlstm.sqhsts[20] = (         int  )33;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asUpCompanyID);
  sqlstm.sqhstl[21] = (unsigned long )3;
  sqlstm.sqhsts[21] = (         int  )3;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asDownCompanyID);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asUsageEventID);
  sqlstm.sqhstl[23] = (unsigned long )19;
  sqlstm.sqhsts[23] = (         int  )19;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[24] = (unsigned long )65;
  sqlstm.sqhsts[24] = (         int  )65;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[25] = (unsigned long )4;
  sqlstm.sqhsts[25] = (         int  )4;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pTarget->asCallType);
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


		if(CheckSqlResult("Dyn insert into SETT_TICKET_SM")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*批量数据动态从SETT_TICKET_MMS中用结构缓冲方式取数据*/
int EGetSettTicketMmsToStruct(struct SettTicketMmsStruct *p,
	struct SettTicketMmsStructIn *pSource)
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

		/* EXEC SQL PREPARE SETT_TICKET_MMSSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2027;
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


		CheckSqlError(" PREPARE SETT_TICKET_MMSSCR SETT_TICKET_MMSCR");

		/* EXEC SQL DECLARE SETT_TICKET_MMSCR CURSOR FOR SETT_TICKET_MMSSCR; */ 

		CheckSqlError("Declare SETT_TICKET_MMSCR");

		/* EXEC SQL OPEN SETT_TICKET_MMSCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2046;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_TICKET_MMSCR;");


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

		/* EXEC SQL CLOSE SETT_TICKET_MMSCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2061;
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
		/* EXEC SQL FETCH SETT_TICKET_MMSCR INTO
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
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2076;
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


		CheckSqlError("Fetch SETT_TICKET_MMSCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_TICKET_MMSCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2227;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_TICKET_MMS_BUFLEN_IN)
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
void mvitem_settticketmms(struct SettTicketMmsStruct *pi,struct SettTicketMmsStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct SettTicketMmsStruct));

		strncpy(po->sProdID,		pi->sProdID,30);
		strncpy(po->sStartTime,		pi->sStartTime,18);
		strncpy(po->sEndTime,		pi->sEndTime,18);
		strncpy(po->sCallingNumber,	pi->sCallingNumber,32);
		strncpy(po->sCalledNumber,	pi->sCalledNumber,32);
		strncpy(po->sOperationTypeID,	pi->sOperationTypeID,8);

		po->iCityID=			pi->iCityID;

		strncpy(po->sIsFree,		pi->sIsFree,4);
		strncpy(po->sRateUnitType,	pi->sRateUnitType,4);
		strncpy(po->sRateUnits,		pi->sRateUnits,12);

		po->iBillCycleSeq=		pi->iBillCycleSeq;

		strncpy(po->sExceptionType,	pi->sExceptionType,8);
		strncpy(po->sProvinceID,	pi->sProvinceID,4);
		strncpy(po->sCallingGroupID,	pi->sCallingGroupID,32);
		strncpy(po->sCalledGroupID,	pi->sCalledGroupID,32);
		strncpy(po->sCallingCompanyID,	pi->sCallingCompanyID,8);
		strncpy(po->sCalledCompanyID,	pi->sCalledCompanyID,8);
		strncpy(po->sStlObject,		pi->sStlObject,8);
		strncpy(po->sStlAmount,		pi->sStlAmount,18);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,32);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,32);
		strncpy(po->sStlDirection,	pi->sStlDirection,4);
		strncpy(po->sUpGw,		pi->sUpGw,32);
		strncpy(po->sDownGw,		pi->sDownGw,32);
		strncpy(po->sUpgwGroupID,	pi->sUpgwGroupID,32);
		strncpy(po->sDownGwGroupID,	pi->sDownGwGroupID,32);
		strncpy(po->sUpCompanyID,	pi->sUpCompanyID,32);
		strncpy(po->sDownCompanyID,	pi->sDownCompanyID,32);
		strncpy(po->sUsageEventID,	pi->sUsageEventID,18);
		strncpy(po->sCallingCityCode,	pi->sCallingCityCode,32);
		strncpy(po->sCalledCityCode,	pi->sCalledCityCode,32);
		strncpy(po->sFileName,		pi->sFileName,64);
		strncpy(po->sGroupID,		pi->sGroupID,2);
		strncpy(po->sCallType,		pi->sCallType,2);
}
void mvitem_fmsettticketmms(struct FSettTicketMmsStruct *pi,struct SettTicketMmsStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	bzero((void*)po,sizeof(struct SettTicketMmsStruct));

		strncpy(po->sProdID,		pi->sProdID,30);
		strncpy(po->sStartTime,		pi->sStartTime,18);
		strncpy(po->sEndTime,		pi->sEndTime,18);
		strncpy(po->sCallingNumber,	pi->sCallingNumber,32);
		strncpy(po->sCalledNumber,	pi->sCalledNumber,32);
		strncpy(po->sOperationTypeID,	pi->sOperationTypeID,8);

		strncpy(sTemp,		pi->sCityID,8);sTemp[8]=0;
		po->iCityID=atoi(sTemp);

		strncpy(po->sIsFree,		pi->sIsFree,4);
		strncpy(po->sRateUnitType,	pi->sRateUnitType,4);
		strncpy(po->sRateUnits,		pi->sRateUnits,12);

		strncpy(sTemp,	pi->sBillCycleSeq,6);sTemp[6]=0;
		po->iBillCycleSeq=atoi(sTemp);

		strncpy(po->sExceptionType,	pi->sExceptionType,8);
		strncpy(po->sProvinceID,	pi->sProvinceID,4);
		strncpy(po->sCallingGroupID,	pi->sCallingGroupID,32);
		strncpy(po->sCalledGroupID,	pi->sCalledGroupID,32);
		strncpy(po->sCallingCompanyID,	pi->sCallingCompanyID,8);
		strncpy(po->sCalledCompanyID,	pi->sCalledCompanyID,8);
		strncpy(po->sStlObject,		pi->sStlObject,8);
		strncpy(po->sStlAmount,		pi->sStlAmount,18);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,32);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,32);
		strncpy(po->sStlDirection,	pi->sStlDirection,4);
		strncpy(po->sUpGw,		pi->sUpGw,32);
		strncpy(po->sDownGw,		pi->sDownGw,32);
		strncpy(po->sUpgwGroupID,	pi->sUpgwGroupID,32);
		strncpy(po->sDownGwGroupID,	pi->sDownGwGroupID,32);
		strncpy(po->sUpCompanyID,	pi->sUpCompanyID,32);
		strncpy(po->sDownCompanyID,	pi->sDownCompanyID,32);
		strncpy(po->sUsageEventID,	pi->sUsageEventID,18);
		strncpy(po->sCallingCityCode,	pi->sCallingCityCode,32);
		strncpy(po->sCalledCityCode,	pi->sCalledCityCode,32);

		AllTrim(po->sProdID);
		AllTrim(po->sStartTime);
		AllTrim(po->sEndTime);
		AllTrim(po->sCallingNumber);
		AllTrim(po->sCalledNumber);
		AllTrim(po->sOperationTypeID);
		AllTrim(po->sIsFree);
		AllTrim(po->sRateUnitType);
		AllTrim(po->sRateUnits);
		AllTrim(po->sExceptionType);
		AllTrim(po->sProvinceID);
		AllTrim(po->sCallingGroupID);
		AllTrim(po->sCalledGroupID);
		AllTrim(po->sCallingCompanyID);
		AllTrim(po->sCalledCompanyID);
		AllTrim(po->sStlObject);
		AllTrim(po->sStlAmount);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCalledAreaCode);
		AllTrim(po->sStlDirection);
		AllTrim(po->sUpGw);
		AllTrim(po->sDownGw);
		AllTrim(po->sUpgwGroupID);
		AllTrim(po->sDownGwGroupID);
		AllTrim(po->sUpCompanyID);
		AllTrim(po->sDownCompanyID);
		AllTrim(po->sUsageEventID);
		AllTrim(po->sCallingCityCode);
		AllTrim(po->sCalledCityCode);
		AllTrim(po->sFileName);
		AllTrim(po->sGroupID);
		AllTrim(po->sCallType);
}
void mvitem_mfsettticketmms(struct SettTicketMmsStruct *pi,struct FSettTicketMmsStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettTicketMmsStruct));

		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sEndTime,pi->sEndTime,strlen(pi->sEndTime));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sOperationTypeID,pi->sOperationTypeID,strlen(pi->sOperationTypeID));

		sprintf(sTemp,"%08d",pi->iCityID);
		strncpy(po->sCityID,sTemp,8);

		strncpy(po->sIsFree,pi->sIsFree,strlen(pi->sIsFree));
		strncpy(po->sRateUnitType,pi->sRateUnitType,strlen(pi->sRateUnitType));
		strncpy(po->sRateUnits,pi->sRateUnits,strlen(pi->sRateUnits));

		sprintf(sTemp,"%06d",pi->iBillCycleSeq);
		strncpy(po->sBillCycleSeq,sTemp,6);

		strncpy(po->sExceptionType,pi->sExceptionType,strlen(pi->sExceptionType));
		strncpy(po->sProvinceID,pi->sProvinceID,strlen(pi->sProvinceID));
		strncpy(po->sCallingGroupID,pi->sCallingGroupID,strlen(pi->sCallingGroupID));
		strncpy(po->sCalledGroupID,pi->sCalledGroupID,strlen(pi->sCalledGroupID));
		strncpy(po->sCallingCompanyID,pi->sCallingCompanyID,strlen(pi->sCallingCompanyID));
		strncpy(po->sCalledCompanyID,pi->sCalledCompanyID,strlen(pi->sCalledCompanyID));
		strncpy(po->sStlObject,pi->sStlObject,strlen(pi->sStlObject));
		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sStlDirection,pi->sStlDirection,strlen(pi->sStlDirection));
		strncpy(po->sUpGw,pi->sUpGw,strlen(pi->sUpGw));
		strncpy(po->sDownGw,pi->sDownGw,strlen(pi->sDownGw));
		strncpy(po->sUpgwGroupID,pi->sUpgwGroupID,strlen(pi->sUpgwGroupID));
		strncpy(po->sDownGwGroupID,pi->sDownGwGroupID,strlen(pi->sDownGwGroupID));
		strncpy(po->sUpCompanyID,pi->sUpCompanyID,strlen(pi->sUpCompanyID));
		strncpy(po->sDownCompanyID,pi->sDownCompanyID,strlen(pi->sDownCompanyID));
		strncpy(po->sUsageEventID,pi->sUsageEventID,strlen(pi->sUsageEventID));
		strncpy(po->sCallingCityCode,pi->sCallingCityCode,strlen(pi->sCallingCityCode));
		strncpy(po->sCalledCityCode,pi->sCalledCityCode,strlen(pi->sCalledCityCode));

}
/**对表SETT_TICKET_MMS的链表释放函数**/
void DestroySettTicketMms(struct SettTicketMmsStruct *ptHead)
{
	struct SettTicketMmsStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettTicketMms(struct SettTicketMmsStruct **pptHead)
{
	int iCnt=0;
	static struct SettTicketMmsStruct *pTemp,*ptHead=NULL;
	struct SettTicketMmsStruct Temp;
	struct SettTicketMmsStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettTicketMms(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SettTicketMmsStructIn));
	sprintf(TempIn.sTableName,"SETT_TICKET_MMS");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettTicketMmsToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettTicketMmsStruct*)
			malloc(sizeof(struct SettTicketMmsStruct)))==NULL){

			DestroySettTicketMms(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettTicketMmsStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_TICKET_MMS记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_TICKET_MMS完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据结构缓冲写入SETT_TICKET_MMS*/
int EInsertStructToSettTicketMms(struct SettTicketMmsStruct *p,
	int iInsertFlag,struct SettTicketMmsStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asProdID[iCurPos],		p->sProdID);
		strcpy(pTarget->asStartTime[iCurPos],		p->sStartTime);
		strcpy(pTarget->asEndTime[iCurPos],		p->sEndTime);
		strcpy(pTarget->asCallingNumber[iCurPos],	p->sCallingNumber);
		strcpy(pTarget->asCalledNumber[iCurPos],	p->sCalledNumber);
		strcpy(pTarget->asOperationTypeID[iCurPos],	p->sOperationTypeID);

		pTarget->aiCityID[iCurPos]=			p->iCityID;

		strcpy(pTarget->asIsFree[iCurPos],		p->sIsFree);
		strcpy(pTarget->asRateUnitType[iCurPos],	p->sRateUnitType);
		strcpy(pTarget->asRateUnits[iCurPos],		p->sRateUnits);

		pTarget->aiBillCycleSeq[iCurPos]=		p->iBillCycleSeq;

		strcpy(pTarget->asExceptionType[iCurPos],	p->sExceptionType);
		strcpy(pTarget->asProvinceID[iCurPos],		p->sProvinceID);
		strcpy(pTarget->asCallingGroupID[iCurPos],	p->sCallingGroupID);
		strcpy(pTarget->asCalledGroupID[iCurPos],	p->sCalledGroupID);
		strcpy(pTarget->asCallingCompanyID[iCurPos],	p->sCallingCompanyID);
		strcpy(pTarget->asCalledCompanyID[iCurPos],	p->sCalledCompanyID);
		strcpy(pTarget->asStlObject[iCurPos],		p->sStlObject);
		strcpy(pTarget->asStlAmount[iCurPos],		p->sStlAmount);
		strcpy(pTarget->asCallingAreaCode[iCurPos],	p->sCallingAreaCode);
		strcpy(pTarget->asCalledAreaCode[iCurPos],	p->sCalledAreaCode);
		strcpy(pTarget->asStlDirection[iCurPos],	p->sStlDirection);
		strcpy(pTarget->asUpGw[iCurPos],		p->sUpGw);
		strcpy(pTarget->asDownGw[iCurPos],		p->sDownGw);
		strcpy(pTarget->asUpgwGroupID[iCurPos],		p->sUpgwGroupID);
		strcpy(pTarget->asDownGwGroupID[iCurPos],	p->sDownGwGroupID);
		strcpy(pTarget->asUpCompanyID[iCurPos],		p->sUpCompanyID);
		strcpy(pTarget->asDownCompanyID[iCurPos],	p->sDownCompanyID);
		strcpy(pTarget->asUsageEventID[iCurPos],	p->sUsageEventID);
		strcpy(pTarget->asCallingCityCode[iCurPos],	p->sCallingCityCode);
		strcpy(pTarget->asCalledCityCode[iCurPos],	p->sCalledCityCode);
		strcpy(pTarget->asFileName[iCurPos],		p->sFileName);
		strcpy(pTarget->asGroupID[iCurPos],		p->sGroupID);
		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_TICKET_MMS_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				PROD_ID,\n\
				START_TIME,\n\
				END_TIME,\n\
				CALLING_NUMBER,\n\
				CALLED_NUMBER,\n\
				OPERATION_TYPE_ID,\n\
				CITY_ID,\n\
				IS_FREE,\n\
				RATE_UNIT_TYPE,\n\
				RATE_UNITS,\n\
				BILL_CYCLE_SEQ,\n\
				EXCEPTION_TYPE,\n\
				PROVINCE_ID,\n\
				CALLING_GROUP_ID,\n\
				CALLED_GROUP_ID,\n\
				CALLING_COMPANY_ID,\n\
				CALLED_COMPANY_ID,\n\
				STL_OBJECT,\n\
				STL_AMOUNT,\n\
				CALLING_AREA_CODE,\n\
				CALLED_AREA_CODE,\n\
				STL_DIRECTION,\n\
				UP_GW,\n\
				DOWN_GW,\n\
				UPGW_GROUP_ID,\n\
				DOWN_GW_GROUP_ID,\n\
				UP_COMPANY_ID,\n\
				DOWN_COMPANY_ID,\n\
				USAGE_EVENT_ID,\n\
				CALLING_CITY_CODE,\n\
				CALLED_CITY_CODE,\n\
				FILE_NAME,\n\
				GROUP_ID,\n\
				CALL_TYPE)\n\
			VALUES (\n\
				:asProdID,\n\
				:asStartTime,\n\
				:asEndTime,\n\
				:asCallingNumber,\n\
				:asCalledNumber,\n\
				:asOperationTypeID,\n\
				:aiCityID,\n\
				:asIsFree,\n\
				:asRateUnitType,\n\
				to_number(:asRateUnits),\n\
				:aiBillCycleSeq,\n\
				:asExceptionType,\n\
				:asProvinceID,\n\
				:asCallingGroupID,\n\
				:asCalledGroupID,\n\
				:asCallingCompanyID,\n\
				:asCalledCompanyID,\n\
				:asStlObject,\n\
				to_number(:asStlAmount),\n\
				:asCallingAreaCode,\n\
				:asCalledAreaCode,\n\
				:asStlDirection,\n\
				:asUpGw,\n\
				:asDownGw,\n\
				:asUpgwGroupID,\n\
				:asDownGwGroupID,\n\
				:asUpCompanyID,\n\
				:asDownCompanyID,\n\
				to_number(:asUsageEventID),\n\
				:asCallingCityCode,\n\
				:asCalledCityCode,\n\
				:asFileName,\n\
				:asGroupID,\n\
				:asCallType\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_TICKET_MMSTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2242;
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


		if(CheckSqlResult("Prepare insert statement SETT_TICKET_MMS")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_TICKET_MMSTRG USING
				:pTarget->asProdID,
				:pTarget->asStartTime,
				:pTarget->asEndTime,
				:pTarget->asCallingNumber,
				:pTarget->asCalledNumber,
				:pTarget->asOperationTypeID,
				:pTarget->aiCityID,
				:pTarget->asIsFree,
				:pTarget->asRateUnitType,
				:pTarget->asRateUnits,
				:pTarget->aiBillCycleSeq,
				:pTarget->asExceptionType,
				:pTarget->asProvinceID,
				:pTarget->asCallingGroupID,
				:pTarget->asCalledGroupID,
				:pTarget->asCallingCompanyID,
				:pTarget->asCalledCompanyID,
				:pTarget->asStlObject,
				:pTarget->asStlAmount,
				:pTarget->asCallingAreaCode,
				:pTarget->asCalledAreaCode,
				:pTarget->asStlDirection,
				:pTarget->asUpGw,
				:pTarget->asDownGw,
				:pTarget->asUpgwGroupID,
				:pTarget->asDownGwGroupID,
				:pTarget->asUpCompanyID,
				:pTarget->asDownCompanyID,
				:pTarget->asUsageEventID,
				:pTarget->asCallingCityCode,
				:pTarget->asCalledCityCode,
				:pTarget->asFileName,
				:pTarget->asGroupID,
				:pTarget->asCallType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )2261;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[0] = (unsigned long )31;
  sqlstm.sqhsts[0] = (         int  )31;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asStartTime);
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )19;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asEndTime);
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )19;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallingNumber);
  sqlstm.sqhstl[3] = (unsigned long )33;
  sqlstm.sqhsts[3] = (         int  )33;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asCalledNumber);
  sqlstm.sqhstl[4] = (unsigned long )33;
  sqlstm.sqhsts[4] = (         int  )33;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asOperationTypeID);
  sqlstm.sqhstl[5] = (unsigned long )9;
  sqlstm.sqhsts[5] = (         int  )9;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->aiCityID);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(int);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asIsFree);
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )5;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asRateUnitType);
  sqlstm.sqhstl[8] = (unsigned long )5;
  sqlstm.sqhsts[8] = (         int  )5;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asRateUnits);
  sqlstm.sqhstl[9] = (unsigned long )13;
  sqlstm.sqhsts[9] = (         int  )13;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiBillCycleSeq);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asExceptionType);
  sqlstm.sqhstl[11] = (unsigned long )9;
  sqlstm.sqhsts[11] = (         int  )9;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asProvinceID);
  sqlstm.sqhstl[12] = (unsigned long )5;
  sqlstm.sqhsts[12] = (         int  )5;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asCallingGroupID);
  sqlstm.sqhstl[13] = (unsigned long )33;
  sqlstm.sqhsts[13] = (         int  )33;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asCalledGroupID);
  sqlstm.sqhstl[14] = (unsigned long )33;
  sqlstm.sqhsts[14] = (         int  )33;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asCallingCompanyID);
  sqlstm.sqhstl[15] = (unsigned long )9;
  sqlstm.sqhsts[15] = (         int  )9;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asCalledCompanyID);
  sqlstm.sqhstl[16] = (unsigned long )9;
  sqlstm.sqhsts[16] = (         int  )9;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asStlObject);
  sqlstm.sqhstl[17] = (unsigned long )9;
  sqlstm.sqhsts[17] = (         int  )9;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asStlAmount);
  sqlstm.sqhstl[18] = (unsigned long )19;
  sqlstm.sqhsts[18] = (         int  )19;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asCallingAreaCode);
  sqlstm.sqhstl[19] = (unsigned long )33;
  sqlstm.sqhsts[19] = (         int  )33;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->asCalledAreaCode);
  sqlstm.sqhstl[20] = (unsigned long )33;
  sqlstm.sqhsts[20] = (         int  )33;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asStlDirection);
  sqlstm.sqhstl[21] = (unsigned long )5;
  sqlstm.sqhsts[21] = (         int  )5;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asUpGw);
  sqlstm.sqhstl[22] = (unsigned long )33;
  sqlstm.sqhsts[22] = (         int  )33;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asDownGw);
  sqlstm.sqhstl[23] = (unsigned long )33;
  sqlstm.sqhsts[23] = (         int  )33;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asUpgwGroupID);
  sqlstm.sqhstl[24] = (unsigned long )33;
  sqlstm.sqhsts[24] = (         int  )33;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)(pTarget->asDownGwGroupID);
  sqlstm.sqhstl[25] = (unsigned long )33;
  sqlstm.sqhsts[25] = (         int  )33;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)(pTarget->asUpCompanyID);
  sqlstm.sqhstl[26] = (unsigned long )33;
  sqlstm.sqhsts[26] = (         int  )33;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pTarget->asDownCompanyID);
  sqlstm.sqhstl[27] = (unsigned long )33;
  sqlstm.sqhsts[27] = (         int  )33;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqharc[27] = (unsigned long  *)0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)(pTarget->asUsageEventID);
  sqlstm.sqhstl[28] = (unsigned long )19;
  sqlstm.sqhsts[28] = (         int  )19;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqharc[28] = (unsigned long  *)0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)(pTarget->asCallingCityCode);
  sqlstm.sqhstl[29] = (unsigned long )33;
  sqlstm.sqhsts[29] = (         int  )33;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqharc[29] = (unsigned long  *)0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pTarget->asCalledCityCode);
  sqlstm.sqhstl[30] = (unsigned long )33;
  sqlstm.sqhsts[30] = (         int  )33;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqharc[30] = (unsigned long  *)0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[31] = (unsigned long )65;
  sqlstm.sqhsts[31] = (         int  )65;
  sqlstm.sqindv[31] = (         short *)0;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqharc[31] = (unsigned long  *)0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[32] = (unsigned long )3;
  sqlstm.sqhsts[32] = (         int  )3;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqharc[32] = (unsigned long  *)0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)(pTarget->asCallType);
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


		if(CheckSqlResult("Dyn insert into SETT_TICKET_MMS")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*****************20140915一级统计************************/

/*批量数据动态从SETT_M_TICKET_UE中用结构缓冲方式取数据*/
int EGetSettMTicketUeToStruct(struct SettMTicketUeStruct *p,
	struct SettMTicketUeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(CITY_ID,' '),\n\
				nvl(CALLING_CITY_ID,' '),\n\
				nvl(CALLING_TYPE,' '),\n\
				nvl(CALLING_COMP_CODE,' '),\n\
				nvl(CALLING_AREA_CODE,' '),\n\
				nvl(CALLING_NUMBER,' '),\n\
				nvl(CALLED_CITY_ID,' '),\n\
				nvl(CALLED_NUMBER_TYPE,' '),\n\
				nvl(CALLED_COMP_CODE,' '),\n\
				nvl(CALLED_AREA_CODE,' '),\n\
				nvl(CALLED_NUMBER,' '),\n\
				to_char(nvl(DURATION,0)),\n\
				nvl(PROD_ID,' '),\n\
				to_char(nvl(STL_DURATION,0)),\n\
				to_char(nvl(STL_AMOUNT,0)),\n\
				nvl(SETT_CNT,0),\n\
				nvl(CALL_TYPE,' '),\n\
				nvl(SETT_DATE,' '),\n\
				nvl(GROUP_ID,' '),\n\
				nvl(OTHER_GROUP_ID,' '),\n\
				nvl(REPORT_ITEM_ID,0),\n\
				nvl(CALLING_NBR_TYPE,''),\n\
				nvl(CALLED_NBR_TYPE,''),\n\
				nvl(SETT_DIRECTION,''),\n\
				nvl(SETT_CARR_ID,'')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_M_TICKET_UESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2412;
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


		CheckSqlError(" PREPARE SETT_M_TICKET_UESCR SETT_M_TICKET_UECR");

		/* EXEC SQL DECLARE SETT_M_TICKET_UECR CURSOR FOR SETT_M_TICKET_UESCR; */ 

		CheckSqlError("Declare SETT_M_TICKET_UECR");

		/* EXEC SQL OPEN SETT_M_TICKET_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2431;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_M_TICKET_UECR;");


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

		/* EXEC SQL CLOSE SETT_M_TICKET_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2446;
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
		/* EXEC SQL FETCH SETT_M_TICKET_UECR INTO
			:pSource->asCityID,
			:pSource->asCallingCityID,
			:pSource->asCallingType,
			:pSource->asCallingCompCode,
			:pSource->asCallingAreaCode,
			:pSource->asCallingNumber,
			:pSource->asCalledCityID,
			:pSource->asCalledNumberType,
			:pSource->asCalledCompCode,
			:pSource->asCalledAreaCode,
			:pSource->asCalledNumber,
			:pSource->asDuration,
			:pSource->asProdID,
			:pSource->asStlDuration,
			:pSource->asStlAmount,
			:pSource->aiSettCnt,
			:pSource->asCallType,
			:pSource->asSettDate,
			:pSource->asGroupID,
			:pSource->asOtherGroupID,
			:pSource->aiReportItemID,
			:pSource->asCallingNbrType,
			:pSource->asCalledNbrType,
			:pSource->asSettDirection,
			:pSource->asSettCarrID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2461;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asCityID);
  sqlstm.sqhstl[0] = (unsigned long )9;
  sqlstm.sqhsts[0] = (         int  )9;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCallingCityID);
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )9;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asCallingType);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asCallingCompCode);
  sqlstm.sqhstl[3] = (unsigned long )3;
  sqlstm.sqhsts[3] = (         int  )3;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asCallingAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )9;
  sqlstm.sqhsts[4] = (         int  )9;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asCallingNumber);
  sqlstm.sqhstl[5] = (unsigned long )31;
  sqlstm.sqhsts[5] = (         int  )31;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asCalledCityID);
  sqlstm.sqhstl[6] = (unsigned long )9;
  sqlstm.sqhsts[6] = (         int  )9;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asCalledNumberType);
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )5;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asCalledCompCode);
  sqlstm.sqhstl[8] = (unsigned long )3;
  sqlstm.sqhsts[8] = (         int  )3;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asCalledAreaCode);
  sqlstm.sqhstl[9] = (unsigned long )9;
  sqlstm.sqhsts[9] = (         int  )9;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->asCalledNumber);
  sqlstm.sqhstl[10] = (unsigned long )31;
  sqlstm.sqhsts[10] = (         int  )31;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->asDuration);
  sqlstm.sqhstl[11] = (unsigned long )19;
  sqlstm.sqhsts[11] = (         int  )19;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[12] = (unsigned long )16;
  sqlstm.sqhsts[12] = (         int  )16;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->asStlDuration);
  sqlstm.sqhstl[13] = (unsigned long )19;
  sqlstm.sqhsts[13] = (         int  )19;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->asStlAmount);
  sqlstm.sqhstl[14] = (unsigned long )19;
  sqlstm.sqhsts[14] = (         int  )19;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->aiSettCnt);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asCallType);
  sqlstm.sqhstl[16] = (unsigned long )3;
  sqlstm.sqhsts[16] = (         int  )3;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asSettDate);
  sqlstm.sqhstl[17] = (unsigned long )9;
  sqlstm.sqhsts[17] = (         int  )9;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asGroupID);
  sqlstm.sqhstl[18] = (unsigned long )4;
  sqlstm.sqhsts[18] = (         int  )4;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pSource->asOtherGroupID);
  sqlstm.sqhstl[19] = (unsigned long )4;
  sqlstm.sqhsts[19] = (         int  )4;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pSource->aiReportItemID);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asCallingNbrType);
  sqlstm.sqhstl[21] = (unsigned long )3;
  sqlstm.sqhsts[21] = (         int  )3;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pSource->asCalledNbrType);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pSource->asSettDirection);
  sqlstm.sqhstl[23] = (unsigned long )3;
  sqlstm.sqhsts[23] = (         int  )3;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pSource->asSettCarrID);
  sqlstm.sqhstl[24] = (unsigned long )3;
  sqlstm.sqhsts[24] = (         int  )3;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Fetch SETT_M_TICKET_UECR");
 
		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_M_TICKET_UECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2576;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_M_TICKET_UE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sCityID,		pSource->asCityID[iCurPos]);
		strcpy(p->sCallingCityID,	pSource->asCallingCityID[iCurPos]);
		strcpy(p->sCallingType,		pSource->asCallingType[iCurPos]);
		strcpy(p->sCallingCompCode,	pSource->asCallingCompCode[iCurPos]);
		strcpy(p->sCallingAreaCode,	pSource->asCallingAreaCode[iCurPos]);
		strcpy(p->sCallingNumber,	pSource->asCallingNumber[iCurPos]);
		strcpy(p->sCalledCityID,	pSource->asCalledCityID[iCurPos]);
		strcpy(p->sCalledNumberType,	pSource->asCalledNumberType[iCurPos]);
		strcpy(p->sCalledCompCode,	pSource->asCalledCompCode[iCurPos]);
		strcpy(p->sCalledAreaCode,	pSource->asCalledAreaCode[iCurPos]);
		strcpy(p->sCalledNumber,	pSource->asCalledNumber[iCurPos]);
		strcpy(p->sDuration,		pSource->asDuration[iCurPos]);
		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sStlDuration,		pSource->asStlDuration[iCurPos]);
		strcpy(p->sStlAmount,		pSource->asStlAmount[iCurPos]);

		p->iSettCnt=			pSource->aiSettCnt[iCurPos];

		strcpy(p->sCallType,		pSource->asCallType[iCurPos]);
		strcpy(p->sSettDate,		pSource->asSettDate[iCurPos]);
		strcpy(p->sGroupID,		pSource->asGroupID[iCurPos]);
		strcpy(p->sOtherGroupID,	pSource->asOtherGroupID[iCurPos]);

		p->iReportItemID=		pSource->aiReportItemID[iCurPos];
		
		strcpy(p->sCallingNbrType,	pSource->asCallingNbrType[iCurPos]);
		strcpy(p->sCalledNbrType,	pSource->asCalledNbrType[iCurPos]);
		strcpy(p->sSettDirection,	pSource->asSettDirection[iCurPos]);
		strcpy(p->sSettCarrID,		pSource->asSettCarrID[iCurPos]);

		AllTrim(p->sCityID);
		AllTrim(p->sCallingCityID);
		AllTrim(p->sCallingType);
		AllTrim(p->sCallingCompCode);
		AllTrim(p->sCallingAreaCode);
		AllTrim(p->sCallingNumber);
		AllTrim(p->sCalledCityID);
		AllTrim(p->sCalledNumberType);
		AllTrim(p->sCalledCompCode);
		AllTrim(p->sCalledAreaCode);
		AllTrim(p->sCalledNumber);
		AllTrim(p->sDuration);
		AllTrim(p->sProdID);
		AllTrim(p->sStlDuration);
		AllTrim(p->sStlAmount);
		AllTrim(p->sCallType);
		AllTrim(p->sSettDate);
		AllTrim(p->sGroupID);
		AllTrim(p->sOtherGroupID);
		AllTrim(p->sCallingNbrType);
		AllTrim(p->sCalledNbrType);
		AllTrim(p->sSettDirection);
		AllTrim(p->sSettCarrID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_settmticketue(struct SettMTicketUeStruct *pi,struct SettMTicketUeStruct *po)
{/*数据移动部分*/

	memset((void*)po,0,sizeof(struct SettMTicketUeStruct));

		strncpy(po->sCityID,		pi->sCityID,8);
		strncpy(po->sCallingCityID,	pi->sCallingCityID,8);
		strncpy(po->sCallingType,	pi->sCallingType,4);
		strncpy(po->sCallingCompCode,	pi->sCallingCompCode,2);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,8);
		strncpy(po->sCallingNumber,	pi->sCallingNumber,30);
		strncpy(po->sCalledCityID,	pi->sCalledCityID,8);
		strncpy(po->sCalledNumberType,	pi->sCalledNumberType,4);
		strncpy(po->sCalledCompCode,	pi->sCalledCompCode,2);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,8);
		strncpy(po->sCalledNumber,	pi->sCalledNumber,30);
		strncpy(po->sDuration,		pi->sDuration,18);
		strncpy(po->sProdID,		pi->sProdID,15);
		strncpy(po->sStlDuration,	pi->sStlDuration,18);
		strncpy(po->sStlAmount,		pi->sStlAmount,18);

		po->iSettCnt=			pi->iSettCnt;

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sSettDate,		pi->sSettDate,8);
		strncpy(po->sGroupID,		pi->sGroupID,3);
		strncpy(po->sOtherGroupID,	pi->sOtherGroupID,3);

		po->iReportItemID=		pi->iReportItemID;
		
		strncpy(po->sCallingNbrType,	pi->sCallingNbrType,2);
		strncpy(po->sCalledNbrType,	pi->sCalledNbrType,2);
		strncpy(po->sSettDirection,	pi->sSettDirection,2);
		strncpy(po->sSettCarrID,	pi->sSettCarrID,2);
		
}
void mvitem_fmsettmticketue(struct FSettMTicketUeStruct *pi,struct SettMTicketUeStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	memset((void*)po,0,sizeof(struct SettMTicketUeStruct));

		strncpy(po->sCityID,		pi->sCityID,8);
		strncpy(po->sCallingCityID,	pi->sCallingCityID,8);
		strncpy(po->sCallingType,	pi->sCallingType,4);
		strncpy(po->sCallingCompCode,	pi->sCallingCompCode,2);
		strncpy(po->sCallingAreaCode,	pi->sCallingAreaCode,8);
		strncpy(po->sCallingNumber,	pi->sCallingNumber,30);
		strncpy(po->sCalledCityID,	pi->sCalledCityID,8);
		strncpy(po->sCalledNumberType,	pi->sCalledNumberType,4);
		strncpy(po->sCalledCompCode,	pi->sCalledCompCode,2);
		strncpy(po->sCalledAreaCode,	pi->sCalledAreaCode,8);
		strncpy(po->sCalledNumber,	pi->sCalledNumber,30);
		strncpy(po->sDuration,		pi->sDuration,18);
		strncpy(po->sProdID,		pi->sProdID,15);
		strncpy(po->sStlDuration,	pi->sStlDuration,18);
		strncpy(po->sStlAmount,		pi->sStlAmount,18);

		strncpy(sTemp,		pi->sSettCnt,6);sTemp[6]=0;
		po->iSettCnt=atoi(sTemp);

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sSettDate,		pi->sSettDate,8);
		strncpy(po->sGroupID,		pi->sGroupID,3);
		strncpy(po->sOtherGroupID,	pi->sOtherGroupID,3);

		strncpy(sTemp,	pi->sReportItemID,9);sTemp[9]=0;
		po->iReportItemID=atoi(sTemp);
		
		strncpy(po->sCallingNbrType,		pi->sCallingNbrType,2);
		strncpy(po->sCalledNbrType,		pi->sCalledNbrType,2);
		strncpy(po->sSettDirection,		pi->sSettDirection,2);
		strncpy(po->sSettCarrID,		pi->sSettCarrID,2);
	
		AllTrim(po->sCityID);
		AllTrim(po->sCallingCityID);
		AllTrim(po->sCallingType);
		AllTrim(po->sCallingCompCode);
		AllTrim(po->sCallingAreaCode);
		AllTrim(po->sCallingNumber);
		AllTrim(po->sCalledCityID);
		AllTrim(po->sCalledNumberType);
		AllTrim(po->sCalledCompCode);
		AllTrim(po->sCalledAreaCode);
		AllTrim(po->sCalledNumber);
		AllTrim(po->sDuration);
		AllTrim(po->sProdID);
		AllTrim(po->sStlDuration);
		AllTrim(po->sStlAmount);
		AllTrim(po->sCallType);
		AllTrim(po->sSettDate);
		AllTrim(po->sGroupID);
		AllTrim(po->sOtherGroupID);
		
		AllTrim(po->sCallingNbrType);
		AllTrim(po->sCalledNbrType);
		AllTrim(po->sSettDirection);
		AllTrim(po->sSettCarrID);
}
void mvitem_mfsettmticketue(struct SettMTicketUeStruct *pi,struct FSettMTicketUeStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettMTicketUeStruct));

		strncpy(po->sCityID,pi->sCityID,strlen(pi->sCityID));
		strncpy(po->sCallingCityID,pi->sCallingCityID,strlen(pi->sCallingCityID));
		strncpy(po->sCallingType,pi->sCallingType,strlen(pi->sCallingType));
		strncpy(po->sCallingCompCode,pi->sCallingCompCode,strlen(pi->sCallingCompCode));
		strncpy(po->sCallingAreaCode,pi->sCallingAreaCode,strlen(pi->sCallingAreaCode));
		strncpy(po->sCallingNumber,pi->sCallingNumber,strlen(pi->sCallingNumber));
		strncpy(po->sCalledCityID,pi->sCalledCityID,strlen(pi->sCalledCityID));
		strncpy(po->sCalledNumberType,pi->sCalledNumberType,strlen(pi->sCalledNumberType));
		strncpy(po->sCalledCompCode,pi->sCalledCompCode,strlen(pi->sCalledCompCode));
		strncpy(po->sCalledAreaCode,pi->sCalledAreaCode,strlen(pi->sCalledAreaCode));
		strncpy(po->sCalledNumber,pi->sCalledNumber,strlen(pi->sCalledNumber));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));
		strncpy(po->sStlDuration,pi->sStlDuration,strlen(pi->sStlDuration));
		strncpy(po->sStlAmount,pi->sStlAmount,strlen(pi->sStlAmount));

		sprintf(sTemp,"%06d",pi->iSettCnt);
		strncpy(po->sSettCnt,sTemp,6);

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sSettDate,pi->sSettDate,strlen(pi->sSettDate));
		strncpy(po->sGroupID,pi->sGroupID,strlen(pi->sGroupID));
		strncpy(po->sOtherGroupID,pi->sOtherGroupID,strlen(pi->sOtherGroupID));

		sprintf(sTemp,"%09d",pi->iReportItemID);
		strncpy(po->sReportItemID,sTemp,9);
		
		strncpy(po->sCallingNbrType,		pi->sCallingNbrType,strlen(pi->sCallingNbrType));
		strncpy(po->sCalledNbrType,		pi->sCalledNbrType,strlen(pi->sCalledNbrType));
		strncpy(po->sSettDirection,		pi->sSettDirection,strlen(pi->sSettDirection));
		strncpy(po->sSettCarrID,		pi->sSettCarrID,strlen(pi->sSettCarrID));
}
/**对表SETT_M_TICKET_UE的链表释放函数**/
void DestroySettMTicketUe(struct SettMTicketUeStruct *ptHead)
{
	struct SettMTicketUeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettMTicketUe(struct SettMTicketUeStruct **pptHead)
{
	int iCnt=0;
	static struct SettMTicketUeStruct *pTemp,*ptHead=NULL;
	struct SettMTicketUeStruct Temp;
	struct SettMTicketUeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettMTicketUe(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct SettMTicketUeStructIn));
	sprintf(TempIn.sTableName,"SETT_M_TICKET_UE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettMTicketUeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettMTicketUeStruct*)
			malloc(sizeof(struct SettMTicketUeStruct)))==NULL){

			DestroySettMTicketUe(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettMTicketUeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_M_TICKET_UE记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_M_TICKET_UE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据结构缓冲写入SETT_M_TICKET_UE*/
int EInsertStructToSettMTicketUe(struct SettMTicketUeStruct *p,
	int iInsertFlag,struct SettMTicketUeStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asCityID[iCurPos],		p->sCityID);
		strcpy(pTarget->asCallingCityID[iCurPos],	p->sCallingCityID);
		strcpy(pTarget->asCallingType[iCurPos],		p->sCallingType);
		strcpy(pTarget->asCallingCompCode[iCurPos],	p->sCallingCompCode);
		strcpy(pTarget->asCallingAreaCode[iCurPos],	p->sCallingAreaCode);
		strcpy(pTarget->asCallingNumber[iCurPos],	p->sCallingNumber);
		strcpy(pTarget->asCalledCityID[iCurPos],	p->sCalledCityID);
		strcpy(pTarget->asCalledNumberType[iCurPos],	p->sCalledNumberType);
		strcpy(pTarget->asCalledCompCode[iCurPos],	p->sCalledCompCode);
		strcpy(pTarget->asCalledAreaCode[iCurPos],	p->sCalledAreaCode);
		strcpy(pTarget->asCalledNumber[iCurPos],	p->sCalledNumber);
		strcpy(pTarget->asDuration[iCurPos],		p->sDuration);
		strcpy(pTarget->asProdID[iCurPos],		p->sProdID);
		strcpy(pTarget->asStlDuration[iCurPos],		p->sStlDuration);
		strcpy(pTarget->asStlAmount[iCurPos],		p->sStlAmount);

		pTarget->aiSettCnt[iCurPos]=			p->iSettCnt;

		strcpy(pTarget->asCallType[iCurPos],		p->sCallType);
		strcpy(pTarget->asSettDate[iCurPos],		p->sSettDate);
		strcpy(pTarget->asGroupID[iCurPos],		p->sGroupID);
		strcpy(pTarget->asOtherGroupID[iCurPos],	p->sOtherGroupID);

		pTarget->aiReportItemID[iCurPos]=		p->iReportItemID;
		
		strcpy(pTarget->asCallingNbrType[iCurPos],	p->sCallingNbrType);
		strcpy(pTarget->asCalledNbrType[iCurPos],	p->sCalledNbrType);
		strcpy(pTarget->asSettDirection[iCurPos],	p->sSettDirection);
		strcpy(pTarget->asSettCarrID[iCurPos],		p->sSettCarrID);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_M_TICKET_UE_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				CITY_ID,\n\
				CALLING_CITY_ID,\n\
				CALLING_TYPE,\n\
				CALLING_COMP_CODE,\n\
				CALLING_AREA_CODE,\n\
				CALLING_NUMBER,\n\
				CALLED_CITY_ID,\n\
				CALLED_NUMBER_TYPE,\n\
				CALLED_COMP_CODE,\n\
				CALLED_AREA_CODE,\n\
				CALLED_NUMBER,\n\
				DURATION,\n\
				PROD_ID,\n\
				STL_DURATION,\n\
				STL_AMOUNT,\n\
				SETT_CNT,\n\
				CALL_TYPE,\n\
				SETT_DATE,\n\
				GROUP_ID,\n\
				OTHER_GROUP_ID,\n\
				REPORT_ITEM_ID,\n\
				CALLING_NBR_TYPE,\n\
				CALLED_NBR_TYPE,\n\
				SETT_DIRECTION,\n\
				SETT_CARR_ID)\n\
			VALUES (\n\
				:asCityID,\n\
				:asCallingCityID,\n\
				:asCallingType,\n\
				:asCallingCompCode,\n\
				:asCallingAreaCode,\n\
				:asCallingNumber,\n\
				:asCalledCityID,\n\
				:asCalledNumberType,\n\
				:asCalledCompCode,\n\
				:asCalledAreaCode,\n\
				:asCalledNumber,\n\
				to_number(:asDuration),\n\
				:asProdID,\n\
				to_number(:asStlDuration),\n\
				to_number(:asStlAmount),\n\
				:aiSettCnt,\n\
				:asCallType,\n\
				:asSettDate,\n\
				:asGroupID,\n\
				:asOtherGroupID,\n\
				:aiReportItemID,\n\
				:asCallingNbrType,\n\
				:asCalledNbrType,\n\
				:asSettDirection,\n\
				:asSettCarrID\n\
			)",sTableName);


		/* EXEC SQL PREPARE SETT_M_TICKET_UETRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2591;
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


		if(CheckSqlResult("Prepare insert statement SETT_M_TICKET_UE")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_M_TICKET_UETRG USING
				:pTarget->asCityID,
				:pTarget->asCallingCityID,
				:pTarget->asCallingType,
				:pTarget->asCallingCompCode,
				:pTarget->asCallingAreaCode,
				:pTarget->asCallingNumber,
				:pTarget->asCalledCityID,
				:pTarget->asCalledNumberType,
				:pTarget->asCalledCompCode,
				:pTarget->asCalledAreaCode,
				:pTarget->asCalledNumber,
				:pTarget->asDuration,
				:pTarget->asProdID,
				:pTarget->asStlDuration,
				:pTarget->asStlAmount,
				:pTarget->aiSettCnt,
				:pTarget->asCallType,
				:pTarget->asSettDate,
				:pTarget->asGroupID,
				:pTarget->asOtherGroupID,
				:pTarget->aiReportItemID,
				:pTarget->asCallingNbrType,
				:pTarget->asCalledNbrType,
				:pTarget->asSettDirection,
				:pTarget->asSettCarrID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )2610;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asCityID);
  sqlstm.sqhstl[0] = (unsigned long )9;
  sqlstm.sqhsts[0] = (         int  )9;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asCallingCityID);
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )9;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asCallingType);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->asCallingCompCode);
  sqlstm.sqhstl[3] = (unsigned long )3;
  sqlstm.sqhsts[3] = (         int  )3;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asCallingAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )9;
  sqlstm.sqhsts[4] = (         int  )9;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asCallingNumber);
  sqlstm.sqhstl[5] = (unsigned long )31;
  sqlstm.sqhsts[5] = (         int  )31;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asCalledCityID);
  sqlstm.sqhstl[6] = (unsigned long )9;
  sqlstm.sqhsts[6] = (         int  )9;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asCalledNumberType);
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )5;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asCalledCompCode);
  sqlstm.sqhstl[8] = (unsigned long )3;
  sqlstm.sqhsts[8] = (         int  )3;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asCalledAreaCode);
  sqlstm.sqhstl[9] = (unsigned long )9;
  sqlstm.sqhsts[9] = (         int  )9;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asCalledNumber);
  sqlstm.sqhstl[10] = (unsigned long )31;
  sqlstm.sqhsts[10] = (         int  )31;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asDuration);
  sqlstm.sqhstl[11] = (unsigned long )19;
  sqlstm.sqhsts[11] = (         int  )19;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[12] = (unsigned long )16;
  sqlstm.sqhsts[12] = (         int  )16;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asStlDuration);
  sqlstm.sqhstl[13] = (unsigned long )19;
  sqlstm.sqhsts[13] = (         int  )19;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asStlAmount);
  sqlstm.sqhstl[14] = (unsigned long )19;
  sqlstm.sqhsts[14] = (         int  )19;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->aiSettCnt);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asCallType);
  sqlstm.sqhstl[16] = (unsigned long )3;
  sqlstm.sqhsts[16] = (         int  )3;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asSettDate);
  sqlstm.sqhstl[17] = (unsigned long )9;
  sqlstm.sqhsts[17] = (         int  )9;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asGroupID);
  sqlstm.sqhstl[18] = (unsigned long )4;
  sqlstm.sqhsts[18] = (         int  )4;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)(pTarget->asOtherGroupID);
  sqlstm.sqhstl[19] = (unsigned long )4;
  sqlstm.sqhsts[19] = (         int  )4;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)(pTarget->aiReportItemID);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(int);
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asCallingNbrType);
  sqlstm.sqhstl[21] = (unsigned long )3;
  sqlstm.sqhsts[21] = (         int  )3;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)(pTarget->asCalledNbrType);
  sqlstm.sqhstl[22] = (unsigned long )3;
  sqlstm.sqhsts[22] = (         int  )3;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)(pTarget->asSettDirection);
  sqlstm.sqhstl[23] = (unsigned long )3;
  sqlstm.sqhsts[23] = (         int  )3;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)(pTarget->asSettCarrID);
  sqlstm.sqhstl[24] = (unsigned long )3;
  sqlstm.sqhsts[24] = (         int  )3;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		if(CheckSqlResult("Dyn insert into SETT_M_TICKET_UE")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


/*****************20140915一级统计************************/


/*****************20140916二级统计************************/
/*批量数据动态从SETT_NBR_STAT_UE中用结构缓冲方式取数据*/
int EGetSettNbrStatUeToStruct(struct SettNbrStatUeStruct *p,
	struct SettNbrStatUeStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(SETT_DATE,' '),\n\
				nvl(SETT_CITY,' '),\n\
				nvl(SETT_NUMBER,' '),\n\
				nvl(HOME_AREA_CODE,' '),\n\
				nvl(OTHER_AREA_CODE,' '),\n\
				nvl(VISIT_AREA_CODE,' '),\n\
				nvl(HOME_COMP_CODE,' '),\n\
				nvl(OTHER_COMP_CODE,' '),\n\
				nvl(CALL_DIRECTION,' '),\n\
				nvl(PROD_ID,' '),\n\
				nvl(SETT_INCOME,0),\n\
				nvl(SETT_EXPENSES,0),\n\
				nvl(SETT_DURATION,0),\n\
				nvl(DURATION,0),\n\
				nvl(SETT_CNT,0),\n\
				nvl(SVC_TYPE,' '),\n\
				nvl(HOME_NET_TYPE,' '),\n\
				nvl(OTHER_NET_TYPE,' '),\n\
				nvl(SETT_FLAG,' '),\n\
				nvl(RESERVE1,' '),\n\
				nvl(RESERVE2,' '),\n\
				nvl(IN_COMP,'O')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_NBR_STAT_UESCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2725;
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


		CheckSqlError(" PREPARE SETT_NBR_STAT_UESCR SETT_NBR_STAT_UECR");

		/* EXEC SQL DECLARE SETT_NBR_STAT_UECR CURSOR FOR SETT_NBR_STAT_UESCR; */ 

		CheckSqlError("Declare SETT_NBR_STAT_UECR");

		/* EXEC SQL OPEN SETT_NBR_STAT_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2744;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_NBR_STAT_UECR;");


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

		/* EXEC SQL CLOSE SETT_NBR_STAT_UECR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2759;
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
		/* EXEC SQL FETCH SETT_NBR_STAT_UECR INTO
			:pSource->asSettDate,
			:pSource->asSettCity,
			:pSource->asSettNumber,
			:pSource->asHomeAreaCode,
			:pSource->asOtherAreaCode,
			:pSource->asVisitAreaCode,
			:pSource->asHomeCompCode,
			:pSource->asOtherCompCode,
			:pSource->asCallDirection,
			:pSource->asProdID,
			:pSource->aiSettIncome,
			:pSource->aiSettExpenses,
			:pSource->aiSettDuration,
			:pSource->aiDuration,
			:pSource->aiSettCnt,
			:pSource->asSvcType,
			:pSource->asHomeNetType,
			:pSource->asOtherNetType,
			:pSource->asSettFlag,
			:pSource->asReserve1,
			:pSource->asReserve2,
			:pSource->asInComp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )2774;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asSettDate);
  sqlstm.sqhstl[0] = (unsigned long )9;
  sqlstm.sqhsts[0] = (         int  )9;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asSettCity);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asSettNumber);
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
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asOtherAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
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
  sqlstm.sqhstv[6] = (unsigned char  *)(pSource->asHomeCompCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pSource->asOtherCompCode);
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )6;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pSource->asCallDirection);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[9] = (unsigned long )16;
  sqlstm.sqhsts[9] = (         int  )16;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pSource->aiSettIncome);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pSource->aiSettExpenses);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->aiSettDuration);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pSource->aiDuration);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pSource->aiSettCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pSource->asSvcType);
  sqlstm.sqhstl[15] = (unsigned long )4;
  sqlstm.sqhsts[15] = (         int  )4;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pSource->asHomeNetType);
  sqlstm.sqhstl[16] = (unsigned long )5;
  sqlstm.sqhsts[16] = (         int  )5;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pSource->asOtherNetType);
  sqlstm.sqhstl[17] = (unsigned long )5;
  sqlstm.sqhsts[17] = (         int  )5;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pSource->asSettFlag);
  sqlstm.sqhstl[18] = (unsigned long )2;
  sqlstm.sqhsts[18] = (         int  )2;
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
  sqlstm.sqhstv[21] = (unsigned char  *)(pSource->asInComp);
  sqlstm.sqhstl[21] = (unsigned long )6;
  sqlstm.sqhsts[21] = (         int  )6;
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


		CheckSqlError("Fetch SETT_NBR_STAT_UECR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_NBR_STAT_UECR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2877;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_NBR_STAT_UE_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sSettDate,		pSource->asSettDate[iCurPos]);
		strcpy(p->sSettCity,		pSource->asSettCity[iCurPos]);
		strcpy(p->sSettNumber,		pSource->asSettNumber[iCurPos]);
		strcpy(p->sHomeAreaCode,	pSource->asHomeAreaCode[iCurPos]);
		strcpy(p->sOtherAreaCode,	pSource->asOtherAreaCode[iCurPos]);
		strcpy(p->sVisitAreaCode,	pSource->asVisitAreaCode[iCurPos]);
		strcpy(p->sHomeCompCode,	pSource->asHomeCompCode[iCurPos]);
		strcpy(p->sOtherCompCode,	pSource->asOtherCompCode[iCurPos]);
		strcpy(p->sCallDirection,	pSource->asCallDirection[iCurPos]);
		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);

		p->iSettIncome=			pSource->aiSettIncome[iCurPos];
		p->iSettExpenses=		pSource->aiSettExpenses[iCurPos];
		p->iSettDuration=		pSource->aiSettDuration[iCurPos];
		p->iDuration=			pSource->aiDuration[iCurPos];
		p->iSettCnt=			pSource->aiSettCnt[iCurPos];

		strcpy(p->sSvcType,		pSource->asSvcType[iCurPos]);
		strcpy(p->sHomeNetType,		pSource->asHomeNetType[iCurPos]);
		strcpy(p->sOtherNetType,	pSource->asOtherNetType[iCurPos]);
		strcpy(p->sSettFlag,		pSource->asSettFlag[iCurPos]);
		strcpy(p->sReserve1,		pSource->asReserve1[iCurPos]);
		strcpy(p->sReserve2,		pSource->asReserve2[iCurPos]);
		strcpy(p->sInComp,		pSource->asInComp[iCurPos]);

		AllTrim(p->sSettDate);
		AllTrim(p->sSettCity);
		AllTrim(p->sSettNumber);
		AllTrim(p->sHomeAreaCode);
		AllTrim(p->sOtherAreaCode);
		AllTrim(p->sVisitAreaCode);
		AllTrim(p->sHomeCompCode);
		AllTrim(p->sOtherCompCode);
		AllTrim(p->sCallDirection);
		AllTrim(p->sProdID);
		AllTrim(p->sSvcType);
		AllTrim(p->sHomeNetType);
		AllTrim(p->sOtherNetType);
		AllTrim(p->sSettFlag);
		AllTrim(p->sReserve1);
		AllTrim(p->sReserve2);
		AllTrim(p->sInComp);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
void mvitem_settnbrstatue(struct SettNbrStatUeStruct *pi,struct SettNbrStatUeStruct *po)
{/*数据移动部分*/

	memset((void*)po,0,sizeof(struct SettNbrStatUeStruct));

		strncpy(po->sSettDate,		pi->sSettDate,8);
		strncpy(po->sSettCity,		pi->sSettCity,5);
		strncpy(po->sSettNumber,	pi->sSettNumber,24);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sOtherAreaCode,	pi->sOtherAreaCode,5);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sHomeCompCode,	pi->sHomeCompCode,5);
		strncpy(po->sOtherCompCode,	pi->sOtherCompCode,5);
		strncpy(po->sCallDirection,	pi->sCallDirection,1);
		strncpy(po->sProdID,		pi->sProdID,15);

		po->iSettIncome=		pi->iSettIncome;
		po->iSettExpenses=		pi->iSettExpenses;
		po->iSettDuration=		pi->iSettDuration;
		po->iDuration=			pi->iDuration;
		po->iSettCnt=			pi->iSettCnt;

		strncpy(po->sSvcType,		pi->sSvcType,3);
		strncpy(po->sHomeNetType,	pi->sHomeNetType,4);
		strncpy(po->sOtherNetType,	pi->sOtherNetType,4);
		strncpy(po->sSettFlag,		pi->sSettFlag,1);
		strncpy(po->sReserve1,		pi->sReserve1,10);
		strncpy(po->sReserve2,		pi->sReserve2,10);
		
		strncpy(po->sInComp,		pi->sInComp,5);
}
void mvitem_fmsettnbrstatue(struct FSettNbrStatUeStruct *pi,struct SettNbrStatUeStruct *po)
{/*数据文件移动到内存部分*/
	char sTemp[128];

	memset((void*)po,0,sizeof(struct SettNbrStatUeStruct));

		strncpy(po->sSettDate,		pi->sSettDate,8);
		strncpy(po->sSettCity,		pi->sSettCity,5);
		strncpy(po->sSettNumber,	pi->sSettNumber,24);
		strncpy(po->sHomeAreaCode,	pi->sHomeAreaCode,5);
		strncpy(po->sOtherAreaCode,	pi->sOtherAreaCode,5);
		strncpy(po->sVisitAreaCode,	pi->sVisitAreaCode,5);
		strncpy(po->sHomeCompCode,	pi->sHomeCompCode,5);
		strncpy(po->sOtherCompCode,	pi->sOtherCompCode,5);
		strncpy(po->sCallDirection,	pi->sCallDirection,1);
		strncpy(po->sProdID,		pi->sProdID,15);

		strncpy(sTemp,	pi->sSettIncome,9);sTemp[9]=0;
		po->iSettIncome=atoi(sTemp);
		strncpy(sTemp,	pi->sSettExpenses,9);sTemp[9]=0;
		po->iSettExpenses=atoi(sTemp);
		strncpy(sTemp,	pi->sSettDuration,9);sTemp[9]=0;
		po->iSettDuration=atoi(sTemp);
		strncpy(sTemp,		pi->sDuration,9);sTemp[9]=0;
		po->iDuration=atoi(sTemp);
		strncpy(sTemp,		pi->sSettCnt,9);sTemp[9]=0;
		po->iSettCnt=atoi(sTemp);

		strncpy(po->sSvcType,		pi->sSvcType,3);
		strncpy(po->sHomeNetType,	pi->sHomeNetType,4);
		strncpy(po->sOtherNetType,	pi->sOtherNetType,4);
		strncpy(po->sSettFlag,		pi->sSettFlag,1);
		strncpy(po->sReserve1,		pi->sReserve1,10);
		strncpy(po->sReserve2,		pi->sReserve2,10);

		AllTrim(po->sSettDate);
		AllTrim(po->sSettCity);
		AllTrim(po->sSettNumber);
		AllTrim(po->sHomeAreaCode);
		AllTrim(po->sOtherAreaCode);
		AllTrim(po->sVisitAreaCode);
		AllTrim(po->sHomeCompCode);
		AllTrim(po->sOtherCompCode);
		AllTrim(po->sCallDirection);
		AllTrim(po->sProdID);
		AllTrim(po->sSvcType);
		AllTrim(po->sHomeNetType);
		AllTrim(po->sOtherNetType);
		AllTrim(po->sSettFlag);
		AllTrim(po->sReserve1);
		AllTrim(po->sReserve2);
}
void mvitem_mfsettnbrstatue(struct SettNbrStatUeStruct *pi,struct FSettNbrStatUeStruct *po)
{/*内存数据移动到文件记录到部分*/
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FSettNbrStatUeStruct));

		strncpy(po->sSettDate,pi->sSettDate,strlen(pi->sSettDate));
		strncpy(po->sSettCity,pi->sSettCity,strlen(pi->sSettCity));
		strncpy(po->sSettNumber,pi->sSettNumber,strlen(pi->sSettNumber));
		strncpy(po->sHomeAreaCode,pi->sHomeAreaCode,strlen(pi->sHomeAreaCode));
		strncpy(po->sOtherAreaCode,pi->sOtherAreaCode,strlen(pi->sOtherAreaCode));
		strncpy(po->sVisitAreaCode,pi->sVisitAreaCode,strlen(pi->sVisitAreaCode));
		strncpy(po->sHomeCompCode,pi->sHomeCompCode,strlen(pi->sHomeCompCode));
		strncpy(po->sOtherCompCode,pi->sOtherCompCode,strlen(pi->sOtherCompCode));
		strncpy(po->sCallDirection,pi->sCallDirection,strlen(pi->sCallDirection));
		strncpy(po->sProdID,pi->sProdID,strlen(pi->sProdID));

		sprintf(sTemp,"%09d",pi->iSettIncome);
		strncpy(po->sSettIncome,sTemp,9);
		sprintf(sTemp,"%09d",pi->iSettExpenses);
		strncpy(po->sSettExpenses,sTemp,9);
		sprintf(sTemp,"%09d",pi->iSettDuration);
		strncpy(po->sSettDuration,sTemp,9);
		sprintf(sTemp,"%09d",pi->iDuration);
		strncpy(po->sDuration,sTemp,9);
		sprintf(sTemp,"%09d",pi->iSettCnt);
		strncpy(po->sSettCnt,sTemp,9);

		strncpy(po->sSvcType,pi->sSvcType,strlen(pi->sSvcType));
		strncpy(po->sHomeNetType,pi->sHomeNetType,strlen(pi->sHomeNetType));
		strncpy(po->sOtherNetType,pi->sOtherNetType,strlen(pi->sOtherNetType));
		strncpy(po->sSettFlag,pi->sSettFlag,strlen(pi->sSettFlag));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));
		strncpy(po->sReserve2,pi->sReserve2,strlen(pi->sReserve2));

}
/**对表SETT_NBR_STAT_UE的链表释放函数**/
void DestroySettNbrStatUe(struct SettNbrStatUeStruct *ptHead)
{
	struct SettNbrStatUeStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSettNbrStatUe(struct SettNbrStatUeStruct **pptHead)
{
	int iCnt=0;
	static struct SettNbrStatUeStruct *pTemp,*ptHead=NULL;
	struct SettNbrStatUeStruct Temp;
	struct SettNbrStatUeStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySettNbrStatUe(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct SettNbrStatUeStructIn));
	sprintf(TempIn.sTableName,"SETT_NBR_STAT_UE");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSettNbrStatUeToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SettNbrStatUeStruct*)
			malloc(sizeof(struct SettNbrStatUeStruct)))==NULL){

			DestroySettNbrStatUe(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SettNbrStatUeStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SETT_NBR_STAT_UE记录数%d",iCnt);
	}

	WriteProcMsg("加载表SETT_NBR_STAT_UE完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据结构缓冲写入SETT_NBR_STAT_UE*/
int EInsertStructToSettNbrStatUe(struct SettNbrStatUeStruct *p,
	int iInsertFlag,struct SettNbrStatUeStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asSettDate[iCurPos],		p->sSettDate);
		strcpy(pTarget->asSettCity[iCurPos],		p->sSettCity);
		strcpy(pTarget->asSettNumber[iCurPos],		p->sSettNumber);
		strcpy(pTarget->asHomeAreaCode[iCurPos],	p->sHomeAreaCode);
		strcpy(pTarget->asOtherAreaCode[iCurPos],	p->sOtherAreaCode);
		strcpy(pTarget->asVisitAreaCode[iCurPos],	p->sVisitAreaCode);
		strcpy(pTarget->asHomeCompCode[iCurPos],	p->sHomeCompCode);
		strcpy(pTarget->asOtherCompCode[iCurPos],	p->sOtherCompCode);
		strcpy(pTarget->asCallDirection[iCurPos],	p->sCallDirection);
		strcpy(pTarget->asProdID[iCurPos],		p->sProdID);

		pTarget->aiSettIncome[iCurPos]=			p->iSettIncome;
		pTarget->aiSettExpenses[iCurPos]=		p->iSettExpenses;
		pTarget->aiSettDuration[iCurPos]=		p->iSettDuration;
		pTarget->aiDuration[iCurPos]=			p->iDuration;
		pTarget->aiSettCnt[iCurPos]=			p->iSettCnt;

		strcpy(pTarget->asSvcType[iCurPos],		p->sSvcType);
		strcpy(pTarget->asHomeNetType[iCurPos],		p->sHomeNetType);
		strcpy(pTarget->asOtherNetType[iCurPos],	p->sOtherNetType);
		strcpy(pTarget->asSettFlag[iCurPos],		p->sSettFlag);
		strcpy(pTarget->asReserve1[iCurPos],		p->sReserve1);
		strcpy(pTarget->asReserve2[iCurPos],		p->sReserve2);
		
		strcpy(pTarget->asInComp[iCurPos],		p->sInComp);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_NBR_STAT_UE_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				SETT_DATE,\n\
				SETT_CITY,\n\
				SETT_NUMBER,\n\
				HOME_AREA_CODE,\n\
				OTHER_AREA_CODE,\n\
				VISIT_AREA_CODE,\n\
				HOME_COMP_CODE,\n\
				OTHER_COMP_CODE,\n\
				CALL_DIRECTION,\n\
				PROD_ID,\n\
				SETT_INCOME,\n\
				SETT_EXPENSES,\n\
				SETT_DURATION,\n\
				DURATION,\n\
				SETT_CNT,\n\
				SVC_TYPE,\n\
				HOME_NET_TYPE,\n\
				OTHER_NET_TYPE,\n\
				SETT_FLAG,\n\
				RESERVE1,\n\
				RESERVE2,\n\
				IN_COMP)\n\
			VALUES (\n\
				:asSettDate,\n\
				:asSettCity,\n\
				:asSettNumber,\n\
				:asHomeAreaCode,\n\
				:asOtherAreaCode,\n\
				:asVisitAreaCode,\n\
				:asHomeCompCode,\n\
				:asOtherCompCode,\n\
				:asCallDirection,\n\
				:asProdID,\n\
				:aiSettIncome,\n\
				:aiSettExpenses,\n\
				:aiSettDuration,\n\
				:aiDuration,\n\
				:aiSettCnt,\n\
				:asSvcType,\n\
				:asHomeNetType,\n\
				:asOtherNetType,\n\
				:asSettFlag,\n\
				:asReserve1,\n\
				:asReserve2,\n\
				:asInComp\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_NBR_STAT_UETRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2892;
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


		if(CheckSqlResult("Prepare insert statement SETT_NBR_STAT_UE")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_NBR_STAT_UETRG USING
				:pTarget->asSettDate,
				:pTarget->asSettCity,
				:pTarget->asSettNumber,
				:pTarget->asHomeAreaCode,
				:pTarget->asOtherAreaCode,
				:pTarget->asVisitAreaCode,
				:pTarget->asHomeCompCode,
				:pTarget->asOtherCompCode,
				:pTarget->asCallDirection,
				:pTarget->asProdID,
				:pTarget->aiSettIncome,
				:pTarget->aiSettExpenses,
				:pTarget->aiSettDuration,
				:pTarget->aiDuration,
				:pTarget->aiSettCnt,
				:pTarget->asSvcType,
				:pTarget->asHomeNetType,
				:pTarget->asOtherNetType,
				:pTarget->asSettFlag,
				:pTarget->asReserve1,
				:pTarget->asReserve2,
				:pTarget->asInComp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )2911;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asSettDate);
  sqlstm.sqhstl[0] = (unsigned long )9;
  sqlstm.sqhsts[0] = (         int  )9;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asSettCity);
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asSettNumber);
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
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asOtherAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )6;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asVisitAreaCode);
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )6;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asHomeCompCode);
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )6;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asOtherCompCode);
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )6;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asCallDirection);
  sqlstm.sqhstl[8] = (unsigned long )2;
  sqlstm.sqhsts[8] = (         int  )2;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asProdID);
  sqlstm.sqhstl[9] = (unsigned long )16;
  sqlstm.sqhsts[9] = (         int  )16;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->aiSettIncome);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(int);
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->aiSettExpenses);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(int);
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->aiSettDuration);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->aiDuration);
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(int);
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->aiSettCnt);
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(int);
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->asSvcType);
  sqlstm.sqhstl[15] = (unsigned long )4;
  sqlstm.sqhsts[15] = (         int  )4;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asHomeNetType);
  sqlstm.sqhstl[16] = (unsigned long )5;
  sqlstm.sqhsts[16] = (         int  )5;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asOtherNetType);
  sqlstm.sqhstl[17] = (unsigned long )5;
  sqlstm.sqhsts[17] = (         int  )5;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pTarget->asSettFlag);
  sqlstm.sqhstl[18] = (unsigned long )2;
  sqlstm.sqhsts[18] = (         int  )2;
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
  sqlstm.sqhstv[21] = (unsigned char  *)(pTarget->asInComp);
  sqlstm.sqhstl[21] = (unsigned long )6;
  sqlstm.sqhsts[21] = (         int  )6;
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


		if(CheckSqlResult("Dyn insert into SETT_NBR_STAT_UE")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*****************20140916二级统计************************/

/*批量数据动态从BI_PRODUCT_DESC中用结构缓冲方式取数据*/
int EGetBiProductDescToStruct(struct BiProductDescStruct *p,
	struct BiProductDescStructIn *pSource)
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
				nvl(PROD_NAME,' '),\n\
				nvl(SETT_DIRECTION,' '),\n\
				nvl(SETT_COMPANY,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE BI_PRODUCT_DESCSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3014;
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


		CheckSqlError(" PREPARE BI_PRODUCT_DESCSCR BI_PRODUCT_DESCCR");

		/* EXEC SQL DECLARE BI_PRODUCT_DESCCR CURSOR FOR BI_PRODUCT_DESCSCR; */ 

		CheckSqlError("Declare BI_PRODUCT_DESCCR");

		/* EXEC SQL OPEN BI_PRODUCT_DESCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3033;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open BI_PRODUCT_DESCCR;");


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

		/* EXEC SQL CLOSE BI_PRODUCT_DESCCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3048;
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
		/* EXEC SQL FETCH BI_PRODUCT_DESCCR INTO
			:pSource->asProdID,
			:pSource->asProdName,
			:pSource->asSettDirection,
			:pSource->asSettCompany; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3063;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asProdID);
  sqlstm.sqhstl[0] = (unsigned long )16;
  sqlstm.sqhsts[0] = (         int  )16;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asProdName);
  sqlstm.sqhstl[1] = (unsigned long )129;
  sqlstm.sqhsts[1] = (         int  )129;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asSettDirection);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asSettCompany);
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )5;
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


		CheckSqlError("Fetch BI_PRODUCT_DESCCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE BI_PRODUCT_DESCCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3094;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=BI_PRODUCT_DESC_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sProdID,		pSource->asProdID[iCurPos]);
		strcpy(p->sProdName,		pSource->asProdName[iCurPos]);
		strcpy(p->sSettDirection,	pSource->asSettDirection[iCurPos]);
		strcpy(p->sSettCompany,		pSource->asSettCompany[iCurPos]);

		AllTrim(p->sProdID);
		AllTrim(p->sProdName);
		AllTrim(p->sSettDirection);
		AllTrim(p->sSettCompany);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表BI_PRODUCT_DESC的链表释放函数**/
void DestroyBiProductDesc(struct BiProductDescStruct *ptHead)
{
	struct BiProductDescStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitBiProductDesc(struct BiProductDescStruct **pptHead)
{
	int iCnt=0;
	static struct BiProductDescStruct *pTemp,*ptHead=NULL;
	struct BiProductDescStruct Temp;
	struct BiProductDescStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyBiProductDesc(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct BiProductDescStructIn));
	sprintf(TempIn.sTableName,"param.BI_PRODUCT_DESC");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetBiProductDescToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct BiProductDescStruct*)
			malloc(sizeof(struct BiProductDescStruct)))==NULL){

			DestroyBiProductDesc(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct BiProductDescStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表BI_PRODUCT_DESC记录数%d",iCnt);
	}

	WriteProcMsg("加载表BI_PRODUCT_DESC完毕总记录数%d",iCnt);

	return iCnt;
}

/*批量数据动态从RPT_MID_REL中用结构缓冲方式取数据*/
int EGetRptMidRelToStruct(struct RptMidRelStruct *p,
	struct RptMidRelStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(RPT_CODE,' '),\n\
				nvl(INDEX_ID,' '),\n\
				nvl(INDEX_GROUP_ID,0),\n\
				nvl(INDEX_GROUP_NAME,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE RPT_MID_RELSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3109;
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


		CheckSqlError(" PREPARE RPT_MID_RELSCR RPT_MID_RELCR");

		/* EXEC SQL DECLARE RPT_MID_RELCR CURSOR FOR RPT_MID_RELSCR; */ 

		CheckSqlError("Declare RPT_MID_RELCR");

		/* EXEC SQL OPEN RPT_MID_RELCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3128;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open RPT_MID_RELCR;");


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

		/* EXEC SQL CLOSE RPT_MID_RELCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3143;
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
		/* EXEC SQL FETCH RPT_MID_RELCR INTO
			:pSource->asRptCode,
			:pSource->asIndexID,
			:pSource->aiIndexGroupID,
			:pSource->asIndexGroupName; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3158;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asRptCode);
  sqlstm.sqhstl[0] = (unsigned long )21;
  sqlstm.sqhsts[0] = (         int  )21;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asIndexID);
  sqlstm.sqhstl[1] = (unsigned long )21;
  sqlstm.sqhsts[1] = (         int  )21;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->aiIndexGroupID);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asIndexGroupName);
  sqlstm.sqhstl[3] = (unsigned long )201;
  sqlstm.sqhsts[3] = (         int  )201;
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


		CheckSqlError("Fetch RPT_MID_RELCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE RPT_MID_RELCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3189;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=RPT_MID_REL_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sRptCode,		pSource->asRptCode[iCurPos]);
		strcpy(p->sIndexID,		pSource->asIndexID[iCurPos]);

		p->iIndexGroupID=		pSource->aiIndexGroupID[iCurPos];

		strcpy(p->sIndexGroupName,	pSource->asIndexGroupName[iCurPos]);

		AllTrim(p->sRptCode);
		AllTrim(p->sIndexID);
		AllTrim(p->sIndexGroupName);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表RPT_MID_REL的链表释放函数**/
void DestroyRptMidRel(struct RptMidRelStruct *ptHead)
{
	struct RptMidRelStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitRptMidRel(struct RptMidRelStruct **pptHead)
{
	int iCnt=0;
	static struct RptMidRelStruct *pTemp,*ptHead=NULL;
	struct RptMidRelStruct Temp;
	struct RptMidRelStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroyRptMidRel(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	memset((void*)&TempIn,0,sizeof(struct RptMidRelStructIn));
	sprintf(TempIn.sTableName,"param.RPT_MID_REL");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetRptMidRelToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct RptMidRelStruct*)
			malloc(sizeof(struct RptMidRelStruct)))==NULL){

			DestroyRptMidRel(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct RptMidRelStruct));

		GetSepStr(pTemp->sRptCode,'_',1,pTemp->sHomeCode);
		GetSepStr(pTemp->sRptCode,'_',2,pTemp->sOppCode);
		
		AllTrim(pTemp->sHomeCode);
		AllTrim(pTemp->sOppCode);
		
		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表RPT_MID_REL记录数%d",iCnt);
	}

	WriteProcMsg("加载表RPT_MID_REL完毕总记录数%d",iCnt);

	return iCnt;
}


/*批量数据动态从SETT_INSERT_LOG中用结构缓冲方式取数据*/
int EGetSettInsertLogToStruct(struct SettInsertLogStruct *p,
	struct SettInsertLogStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(FILE_NAME,' '),\n\
				nvl(TABLE_NAME,' '),\n\
				nvl(DATA_DATE,' '),\n\
				nvl(INSERT_CNT,0)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SETT_INSERT_LOGSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3204;
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


		CheckSqlError(" PREPARE SETT_INSERT_LOGSCR SETT_INSERT_LOGCR");

		/* EXEC SQL DECLARE SETT_INSERT_LOGCR CURSOR FOR SETT_INSERT_LOGSCR; */ 

		CheckSqlError("Declare SETT_INSERT_LOGCR");

		/* EXEC SQL OPEN SETT_INSERT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3223;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SETT_INSERT_LOGCR;");


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

		/* EXEC SQL CLOSE SETT_INSERT_LOGCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3238;
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
		/* EXEC SQL FETCH SETT_INSERT_LOGCR INTO
			:pSource->asFileName,
			:pSource->asTableName,
			:pSource->asDataDate,
			:pSource->aiInsertCnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3253;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asFileName);
  sqlstm.sqhstl[0] = (unsigned long )129;
  sqlstm.sqhsts[0] = (         int  )129;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asTableName);
  sqlstm.sqhstl[1] = (unsigned long )31;
  sqlstm.sqhsts[1] = (         int  )31;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asDataDate);
  sqlstm.sqhstl[2] = (unsigned long )9;
  sqlstm.sqhsts[2] = (         int  )9;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->aiInsertCnt);
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


		CheckSqlError("Fetch SETT_INSERT_LOGCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SETT_INSERT_LOGCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3284;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SETT_INSERT_LOG_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sFileName,	pSource->asFileName[iCurPos]);
		strcpy(p->sTableName,	pSource->asTableName[iCurPos]);
		strcpy(p->sDataDate,	pSource->asDataDate[iCurPos]);
		
		p->iInsertCnt=		pSource->aiInsertCnt[iCurPos];

		AllTrim(p->sFileName);
		AllTrim(p->sTableName);
		AllTrim(p->sDataDate);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表SETT_INSERT_LOG的链表释放函数**/
void DestroySettInsertLog(struct SettInsertLogStruct *ptHead)
{
	struct SettInsertLogStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
/*批量数据结构缓冲写入SETT_INSERT_LOG*/
int EInsertStructToSettInsertLog(struct SettInsertLogStruct *p,
	int iInsertFlag,struct SettInsertLogStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asFileName[iCurPos],	p->sFileName);
		strcpy(pTarget->asTableName[iCurPos],	p->sTableName);
		strcpy(pTarget->asDataDate[iCurPos],	p->sDataDate);
		
		pTarget->aiInsertCnt[iCurPos]=		p->iInsertCnt;
		
		strcpy(pTarget->asState[iCurPos],	p->sState);
		
		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==SETT_INSERT_LOG_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				FILE_NAME,\n\
				TABLE_NAME,\n\
				DATA_DATE,\n\
				INSERT_CNT,\n\
				STATE)\n\
			VALUES (\n\
				:asFileName,\n\
				:asTableName,\n\
				:asDataDate,\n\
				:aiInsertCnt,\n\
				:asState\n\
			)",sTableName);

		/* EXEC SQL PREPARE SETT_INSERT_LOGTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3299;
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


		if(CheckSqlResult("Prepare insert statement SETT_INSERT_LOG")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE SETT_INSERT_LOGTRG USING
				:pTarget->asFileName,
				:pTarget->asTableName,
				:pTarget->asDataDate,
				:pTarget->aiInsertCnt,
				:pTarget->asState; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )3318;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asFileName);
  sqlstm.sqhstl[0] = (unsigned long )129;
  sqlstm.sqhsts[0] = (         int  )129;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->asTableName);
  sqlstm.sqhstl[1] = (unsigned long )31;
  sqlstm.sqhsts[1] = (         int  )31;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asDataDate);
  sqlstm.sqhstl[2] = (unsigned long )9;
  sqlstm.sqhsts[2] = (         int  )9;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiInsertCnt);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asState);
  sqlstm.sqhstl[4] = (unsigned long )3;
  sqlstm.sqhsts[4] = (         int  )3;
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


		if(CheckSqlResult("Dyn insert into SETT_INSERT_LOG")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据动态从SUBS_TRUNK中用结构缓冲方式取数据*/
int EGetSubsTrunkToStruct(struct SubsTrunkStruct *p,
	struct SubsTrunkStructIn *pSource)
{

	int  iCurPos=pSource->iCurPos;
	char *sTableName=pSource->sTableName;
	char *sCondition=pSource->sCondition;

	if(pSource->iFirstFlag){

/* CURSOR DEFINE */
		char statement[8192];

		sprintf(statement,"\n\
			SELECT \n\
				nvl(TRUNK_NUMBER,' '),\n\
				nvl(CITY_ID,' '),\n\
				nvl(PROVINCE_ID,' '),\n\
				nvl(TRUNK_DESC,' '),\n\
				nvl(TRUNK_ATTRIBUTE,' '),\n\
				nvl(SUB_TYPE,' ')\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE SUBS_TRUNKSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3353;
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


		CheckSqlError(" PREPARE SUBS_TRUNKSCR SUBS_TRUNKCR");

		/* EXEC SQL DECLARE SUBS_TRUNKCR CURSOR FOR SUBS_TRUNKSCR; */ 

		CheckSqlError("Declare SUBS_TRUNKCR");

		/* EXEC SQL OPEN SUBS_TRUNKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3372;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open SUBS_TRUNKCR;");


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

		/* EXEC SQL CLOSE SUBS_TRUNKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3387;
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
		/* EXEC SQL FETCH SUBS_TRUNKCR INTO
			:pSource->asTrunkNumber,
			:pSource->asCityID,
			:pSource->asProvinceID,
			:pSource->asTrunkDesc,
			:pSource->asTrunkAttribute,
			:pSource->asSubType; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 104;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )3402;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(pSource->asTrunkNumber);
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )13;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pSource->asCityID);
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )5;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pSource->asProvinceID);
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )5;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pSource->asTrunkDesc);
  sqlstm.sqhstl[3] = (unsigned long )41;
  sqlstm.sqhsts[3] = (         int  )41;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pSource->asTrunkAttribute);
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )5;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pSource->asSubType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
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


		CheckSqlError("Fetch SUBS_TRUNKCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE SUBS_TRUNKCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 104;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3441;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=SUBS_TRUNK_BUFLEN_IN)
			pSource->iEndFlag = TRUE;

		pSource->iFetchRecNum=FetchColNum;
		pSource->iCurPos=0;
		iCurPos=0;
		pSource->iBufEmpty=FALSE;
	}

/* 从缓冲区取数据*/
		strcpy(p->sTrunkNumber,		pSource->asTrunkNumber[iCurPos]);
		strcpy(p->sCityID,		pSource->asCityID[iCurPos]);
		strcpy(p->sProvinceID,		pSource->asProvinceID[iCurPos]);
		strcpy(p->sTrunkDesc,		pSource->asTrunkDesc[iCurPos]);
		strcpy(p->sTrunkAttribute,	pSource->asTrunkAttribute[iCurPos]);
		strcpy(p->sSubType,		pSource->asSubType[iCurPos]);

		AllTrim(p->sTrunkNumber);
		AllTrim(p->sCityID);
		AllTrim(p->sProvinceID);
		AllTrim(p->sTrunkDesc);
		AllTrim(p->sTrunkAttribute);
		AllTrim(p->sSubType);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}
/**对表SUBS_TRUNK的链表释放函数**/
void DestroySubsTrunk(struct SubsTrunkStruct *ptHead)
{
	struct SubsTrunkStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pLoadNext;
		free(pTemp);
	}
}
int InitSubsTrunk(struct SubsTrunkStruct **pptHead)
{
	int iCnt=0;
	static struct SubsTrunkStruct *pTemp,*ptHead=NULL;
	struct SubsTrunkStruct Temp;
	struct SubsTrunkStructIn TempIn;

	*pptHead=NULL;
	/*释放内部链表**/
	DestroySubsTrunk(ptHead);
	ptHead=NULL;

	/**初始化输入缓冲成员**/
	bzero((void*)&TempIn,sizeof(struct SubsTrunkStructIn));
	sprintf(TempIn.sTableName,"PARAM.SUBS_TRUNK");
	sprintf(TempIn.sCondition," ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	/*获取数据循环部分**/
	while(EGetSubsTrunkToStruct(&Temp,&TempIn)){

		Temp.pNext=NULL;
		Temp.pLoadNext=NULL;

		if((pTemp=(struct SubsTrunkStruct*)
			malloc(sizeof(struct SubsTrunkStruct)))==NULL){

			DestroySubsTrunk(ptHead);
			ptHead=NULL;
			*pptHead=NULL;
			return -1;
		}

		memcpy((void*)pTemp,(void *)&Temp,sizeof(struct SubsTrunkStruct));

		pTemp->pLoadNext=ptHead;
		ptHead=pTemp;

		InsertList((LIST**)pptHead,(LIST*)pTemp);
		if((++iCnt%10000)==0)
			WriteProcMsg("加载表SUBS_TRUNK记录数%d",iCnt);
	}

	WriteProcMsg("加载表SUBS_TRUNK完毕总记录数%d",iCnt);

	return iCnt;
}


/********************************20140910接口改造*************************************/



