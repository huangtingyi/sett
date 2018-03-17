#ifndef __TAB_XSTR_IMPL_H__
#define __TAB_XSTR_IMPL_H__

#include <bintree.h>
#include <list.h>
#include <stt_ticket.h>
#include "extend_supp.h"
#include "extend_intf.h"

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
           char  filnam[16];
};

static struct sqlcxp sqlfpn =
{
    13,
    "comp_suppx.pc"
};

static unsigned int sqlctx = 2525691;                                 


struct sqlexd {
#ifndef	MAX_SQLEXD_ARR_SIZE
#define	MAX_SQLEXD_ARR_SIZE 100
#endif
	unsigned long  sqlvsn;
	unsigned int   arrsiz;                 
	unsigned int   iters;                  
	unsigned int   offset;                 
	unsigned short selerr;                 
	unsigned short sqlety;                 
	unsigned int   occurs;                 
	short 		*cud;                  
	unsigned char  *sqlest;                
	char  		*stmt;                 
	sqladts 	*sqladtp;              
	sqltdss 	*sqltdsp;              
	unsigned char  **sqphsv;
	unsigned long   *sqphsl;                
	int   		*sqphss;               
	short  		**sqpind;              
	int   		*sqpins;               
	unsigned long   *sqparm;                
	unsigned long   **sqparc;               
	unsigned short  *sqpadto;              
	unsigned short  *sqptdso;              
	unsigned int   sqlcmax;                
	unsigned int   sqlcmin;                
	unsigned int   sqlcincr;               
	unsigned int   sqlctimeout;            
	unsigned int   sqlcnowait;             
	int   		sqfoff;                
	unsigned int   sqcmod;                 
	unsigned int   sqfmod;                 
                                               
	unsigned char	*sqhstv[MAX_SQLEXD_ARR_SIZE];
	unsigned long   sqhstl[MAX_SQLEXD_ARR_SIZE];
	int   		sqhsts[MAX_SQLEXD_ARR_SIZE];
	short  		*sqindv[MAX_SQLEXD_ARR_SIZE];
	int   		sqinds[MAX_SQLEXD_ARR_SIZE];
	unsigned long    sqharm[MAX_SQLEXD_ARR_SIZE];
	unsigned long   *sqharc[MAX_SQLEXD_ARR_SIZE];
	unsigned short  sqadto[MAX_SQLEXD_ARR_SIZE];
	unsigned short  sqtdso[MAX_SQLEXD_ARR_SIZE];
};
struct	sqlcud_row_var
{
	short	n1;
	short	vtype;
	short	n2;
	short	n3;
};
struct sqlcud_row
{
	short	offset;
	short	noused1;
	short	noused2;
	short	curind;
	short	noused3;
	short	noused4;
	short	oper;
	short	magic;
	short	noused5;
	short	noused6;
	short	varnum;
	short	innum;
	short	noused7;
	short	noused8;
	short 	noused9;
	struct	sqlcud_row_var vt[1];
};
struct sqlcud_h_row
{
	short	offset;
	short	noused1;
	short	noused2;
	short	curind;
	short	noused3;
	short	noused4;
	short	oper;
	short	magic;
	short	noused5;
	short	noused6;
	short	varnum;
	short	innum;
	short	noused7;
	short	noused8;
	short 	noused9;
};

struct sqlcud_sel_row
{
	struct sqlcud_h_row	h1;
	struct	sqlcud_row_var 	hvt;
	struct sqlcud_h_row	h2;
	struct sqlcud_h_row	h3;
	struct sqlcud_h_row	h4;
	struct	sqlcud_row_var 	vt[1];
	
};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);


struct StrStructOut
{
#ifndef XSTR_BUFLEN_OUT
#define XSTR_BUFLEN_OUT 	300
#endif
	int	iCurPos;
	char	sTableName[31];
	char	sStatement[4096];
	char	asXData[1];
};
int EInsertXStr2Tab(char sXStr[],int iInsertFlag,
	struct TabColumnsStruct *ptLkHead,
	struct StrStructOut *pTarget);
struct StrStructOut *MallocStrStructOut(struct TabColumnsStruct *ptHead);
void GetInsXSqlStmt(struct TabColumnsStruct *ptHead,char sTableName[],
	char statement[]);


struct StrStructIn
{
#ifndef XSTR_BUFLEN_IN
#define XSTR_BUFLEN_IN 	300
#endif
	
	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;

	char	sTableName[31];
	char	sStatement[8192];
/*	char	asRowID[XSTR_BUFLEN_IN][19];*/
	char	asXData[1];
};

struct StrStructIn *MallocStrStructIn(struct TabColumnsStruct *ptHead);

int EGetTab2XStr(struct XStrTicketStruct *p,
	struct TabColumnsStruct *ptLkHead,
	struct StrStructIn *pSource);
void GetSelXSqlStmt(struct TabColumnsStruct *ptHead,char sTableName[],
	char sCondition[],char statement[]);


#endif
