/* Result Sets Interface */
/* Object support */
struct sqltvn{
	unsigned char *tvnvsn;
	unsigned short tvnvsnl;
	unsigned char *tvnnm;
	unsigned short tvnnml;
	unsigned char *tvnsnm;
	unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts{
	unsigned int adtvsn;
	unsigned short adtmode;
	unsigned short adtnum;
	sqltvn adttvn[1];
};
typedef struct sqladts sqladts;

/* Binding to PL/SQL Records */
struct sqltdss{

	unsigned int tdsvsn;
	unsigned short tdsnum;
	unsigned char *tdsval[1];
};
typedef struct sqltdss sqltdss;

/* File name & Package Name */
struct sqlcxp
{
	unsigned short fillen;
	char  filnam[12];
};
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
	unsigned char 	**sqphsv;
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

	unsigned char  	*sqhstv[MAX_SQLEXD_ARR_SIZE];
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
/*结束结构类型的申明*/
/* SQLLIB Prototypes */
extern int sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,0,0,17,49,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,21,53,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
};

static struct sqladts sqladt ={1,1,0,};
static struct sqltdss sqltds ={1,0,};
static struct sqlcxp sqlfpn ={11,"upd_supp.pc"};
static unsigned int sqlctx = 9459;
static short sqlcud1[1000];


#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwdb.h>
#include <stt_ticket.h>

void InitSqlcud(struct MyTabColumnsStruct *ptHead,short cud[])
{
	int i=0,j=5+2*sizeof(struct sqlcud_row)/sizeof(short);
	struct sqlcud_row *r;
	struct	sqlcud_row_var *v;

	/*复制cud0->cud*/
	while(i<j){cud[i]=sqlcud0[i];i++;}

	r=(struct sqlcud_row*)&cud[5];
	r=r+1;

	r->varnum=r->innum=CountList((LIST*)ptHead)+1;
	i=0;
	while(ptHead!=NULL){

		v=&r->vt[i];
		v->n1=1;v->n2=0;v->n3=0;
/*		这里不需要做类型转换
		if(strcmp(ptHead->sDataType,"NUMBER")==0)
			v->vtype=3;
		else	v->vtype=97;
*/
		v->vtype=97;

		i++;
		ptHead=ptHead->pNext;
	}
/*	最后ROWID的变化*/
	v=&r->vt[i];
	v->n1=1;v->n2=0;v->n3=0;
	v->vtype=97;
}
void InitSqlexd(struct sqlexd *sqlstm,int arrsiz)
{
	bzero((void*)sqlstm,sizeof(struct sqlexd));

	sqlstm->sqlvsn = 12;
	sqlstm->arrsiz = arrsiz;

	sqlstm->stmt = "";
	sqlstm->sqlety = (unsigned short)256;

	sqlstm->sqphsv = sqlstm->sqhstv;
	sqlstm->sqphsl = sqlstm->sqhstl;
	sqlstm->sqphss = sqlstm->sqhsts;
	sqlstm->sqpind = sqlstm->sqindv;
	sqlstm->sqpins = sqlstm->sqinds;
	sqlstm->sqparm = sqlstm->sqharm;
	sqlstm->sqparc = sqlstm->sqharc;
	sqlstm->sqpadto =sqlstm->sqadto;
	sqlstm->sqptdso =sqlstm->sqtdso;

}
void PrepareCursor(char statement[4096],short cud[])
{
	struct sqlexd sqlstm;
	InitSqlexd(&sqlstm,1);

	sqlstm.sqladtp = &sqladt;
	sqlstm.sqltdsp = &sqltds;
	sqlstm.iters = (unsigned int  )1;
	sqlstm.offset = (unsigned int  )5;
	sqlstm.cud = sqlcud0;
	sqlstm.sqlest = (unsigned char  *)&sqlca;

	sqlstm.sqhstv[0] = (         void  *)statement;
	sqlstm.sqhstl[0] = (unsigned int  )4096;
	sqlstm.sqhsts[0] = (         int  )0;

	sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}
void ExecuteCursor(int iCurPos,short cud[],struct MyTabColumnsStruct *ptHead,
	struct UStrStructUp *pTarget)
{
	int i=0,l,j=0;
	struct sqlexd sqlstm;


	InitSqlexd(&sqlstm,CountList((LIST*)ptHead)+1);
	sqlstm.sqlvsn = 12;

	sqlstm.sqladtp = &sqladt;
	sqlstm.sqltdsp = &sqltds;
	sqlstm.iters = (unsigned int  )iCurPos;
	sqlstm.offset = (unsigned int  )24;
	sqlstm.cud = cud;
	sqlstm.sqlest = (unsigned char  *)&sqlca;

	while(ptHead!=NULL){
		l=ptHead->iLen+1;
		sqlstm.sqhstv[i] = (         void  *)(pTarget->asXData+j);
		sqlstm.sqhstl[i] = (unsigned int  )l;
		sqlstm.sqhsts[i] = (         int  )l;

		j+=l*XSTR_BUFLEN_UP;
		i++;
		ptHead=ptHead->pNext;
	}

	sqlstm.sqhstv[i] = (         void  *)(pTarget->asRowID);
	sqlstm.sqhstl[i] = (unsigned int  )19;
	sqlstm.sqhsts[i] = (         int  )19;

	sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}
int EUpdateXStr2Tab(char sXStr[],char sRowID[],
        int iUpdateFlag,struct MyTabColumnsStruct *ptLkHead,
	struct UStrStructUp *pTarget)
{

        int  iCurPos=pTarget->iCurPos;
	struct MyTabColumnsStruct *ptHead=ptLkHead;

	if(iUpdateFlag!=TRUE){

		int i=0,k,l;

		while(ptHead!=NULL){

			l=ptHead->iLen+1;
			k=i+iCurPos*l;

			strncpy(pTarget->asXData+k,sXStr+ptHead->iOffset,l-1);
			pTarget->asXData[k+l-1]=0;
			AllTrim(pTarget->asXData+k);

			i+=l*XSTR_BUFLEN_UP;

			ptHead=ptHead->pNext;
		}
		strcpy(pTarget->asRowID[iCurPos],sRowID);

		iCurPos++;
	}

        if(iUpdateFlag==TRUE||iCurPos==XSTR_BUFLEN_UP){

/* INSERT */
                if(iCurPos==0) return 0;

		InitSqlcud(ptLkHead,sqlcud1);

		PrepareCursor(pTarget->sStatement,sqlcud1);

                if(CheckSqlResult("Prepare UPDATE statement XSTR")<0)
                        return -1;

		ExecuteCursor(iCurPos,sqlcud1,ptLkHead,pTarget);

		if(CheckSqlResult("Dyn UPDATE XSTR")<0) return -1;

		iCurPos=0;
	}

        pTarget->iCurPos=iCurPos;
        return 0;
}
