
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
    "t130_supp.pc"
};


static unsigned int sqlctx = 283131;


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
   unsigned char  *sqhstv[18];
   unsigned long  sqhstl[18];
            int   sqhsts[18];
            short *sqindv[18];
            int   sqinds[18];
   unsigned long  sqharm[18];
   unsigned long  *sqharc[18];
   unsigned short  sqadto[18];
   unsigned short  sqtdso[18];
} sqlstm = {12,18};

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
5,0,0,1,48,0,4,18,0,0,1,0,0,1,0,2,3,0,0,
24,0,0,2,0,0,17,333,0,0,1,1,0,1,0,1,97,0,0,
43,0,0,2,0,0,21,336,0,0,18,18,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
130,0,0,3,0,0,17,399,0,0,1,1,0,1,0,1,97,0,0,
149,0,0,3,0,0,21,402,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
172,0,0,4,0,0,17,480,0,0,1,1,0,1,0,1,97,0,0,
191,0,0,4,0,0,21,483,0,0,12,12,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
254,0,0,5,0,0,17,673,0,0,1,1,0,1,0,1,97,0,0,
273,0,0,5,0,0,45,679,0,0,0,0,0,1,0,
288,0,0,5,0,0,15,696,0,0,0,0,0,1,0,
303,0,0,5,0,0,13,704,0,0,13,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
370,0,0,5,0,0,15,730,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <param_intf.h>
#include <datatype.h>
#include <bintree.h>
#include <t130_supp.h>

#define IS_UNICOMCDMA(x)      IsDpAccNbr("unicomcdma",x)
#define IS_UNICOMGSM(x)      IsDpAccNbr("unicomgsm",x)

int GetHeadId()
{
	int iHeadId;
	
	/* EXEC SQL SELECT HEAD_ID_SEQ.NEXTVAL INTO :iHeadId FROM DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select HEAD_ID_SEQ.nextval  into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&iHeadId;
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


	if(CheckSqlResult("GET HEAD_ID_SEQ")<0) return -1;

	return iHeadId;
}

int UpdateT130AreaCode(struct OrdT130AreaCodeStruct *pSource,
	char sTableName[],char sState[])
{
	int iCnt=0;
	struct OrdT130AreaCodeStruct *ptHead=NULL,*pTemp;
	struct T130AreaCodeChkStruct Temp;
	struct T130AreaCodeChkStructUp TempUp;

	bzero((void*)&TempUp,sizeof(struct T130AreaCodeChkStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
	ptHead=pSource;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		/*没找到数据的不进行update*/
		if(strcmp(pTemp->sOrdType,"DEL")==0&&
			pTemp->sRowID[0]==0) continue;
		
		mvitem_ordtot130areacode(pTemp,&Temp);
		strcpy(Temp.sState,sState);
		
		if(EUpdateStructToT130AreaCode(&Temp,FALSE,&TempUp)<0){
			printf("Update数据库表%s时出错.\n",sTableName);
			return -1;
		}
		iCnt++;
	}
	if(EUpdateStructToT130AreaCode(NULL,TRUE,&TempUp)<0){
		printf("Update数据库表%s时出错.\n",sTableName);
		return -1;
	}
	
	WriteProcMsg(" %d 条记录更新到 %s 表成功.\n",iCnt,sTableName);
	
	return 0;
}


int InsertOrdT130AreaCode(struct OrdT130AreaCodeStruct *pSource,char sTableName[])
{
	int iCnt=0;
	struct OrdT130AreaCodeStruct *ptHead=NULL,*pTemp;
	struct OrdT130AreaCodeStructOut TempOut;

	bzero((void*)&TempOut,sizeof(struct OrdT130AreaCodeStructOut));
	strcpy(TempOut.sTableName,sTableName);
	
	ptHead=pSource;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*删除的记录，没找到数据的不进行update*/
		if(strcmp(pTemp->sOrdType,"DEL")==0&&
			pTemp->sRowID[0]==0) continue;
		
		if(EInsertStructToOrdT130AreaCode(pTemp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToOrdT130AreaCode(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		return -1;
	}
	
	WriteProcMsg(" %d 条记录输出到 %s 表成功.\n",iCnt,sTableName);
	
	return 0;
}

int InsertT130AreaCode(struct OrdT130AreaCodeStruct *pSource,
	char sTableName[],char sState[])
{
	int iCnt=0;
	struct OrdT130AreaCodeStruct *ptHead=NULL,*pTemp;
	struct T130AreaCodeChkStruct Temp;
	struct T130AreaCodeChkStructOut TempOut;

	bzero((void*)&TempOut,sizeof(struct T130AreaCodeChkStructOut));
	strcpy(TempOut.sTableName,sTableName);
	
	ptHead=pSource;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*删除的记录，没找到数据的不进行update*/
		if(strcmp(pTemp->sOrdType,"DEL")==0&&
			pTemp->sRowID[0]==0) continue;

		mvitem_ordtot130areacode(pTemp,&Temp);
		strcpy(Temp.sState,sState);
		
		if(EInsertStructToT130AreaCodeChk(&Temp,FALSE,&TempOut)<0){
			printf("写数据库表%s时出错.\n",sTableName);
			return -1;
		}
		iCnt++;
	}
	if(EInsertStructToT130AreaCodeChk(NULL,TRUE,&TempOut)<0){
		printf("写数据库表%s时出错.\n",sTableName);
		return -1;
	}
	
	WriteProcMsg(" %d 条记录输出到 %s 表成功.\n",iCnt,sTableName);
	
	return 0;
}

int GetAreaCode(struct MobileHeadStruct *pm,struct HeadMobileHeadStruct *ph,
	char sAreaCode[], char sRemark[])
{

	static struct AreaCodeDescStruct *pTemp=NULL;
	
	if(IS_UNICOMGSM(ph->sHead)||
		IS_UNICOMCDMA(ph->sHead)){
		if(SearchCityCodeDesc(pm->sCityCode,&pTemp)==NOTFOUND)
			return -1;
		strcpy(sAreaCode,pTemp->sAreaCode);
		strcpy(sRemark,	pTemp->sRemark);

	}
	else{
		if(SearchAreaCodeDesc(pm->sAreaCode,&pTemp)==NOTFOUND)
			return -1;	
		strcpy(sAreaCode,pTemp->sAreaCode);
		strcpy(sRemark,	pTemp->sRemark);
	}

	return 0;	
}

int data_search_bintree_t130_area_code_chk_e(void *pValue,void*pData)
{
	struct T130AreaCodeChkStruct *pSource=(struct T130AreaCodeChkStruct *)pValue;
	struct T130AreaCodeChkStruct *pTarget=(struct T130AreaCodeChkStruct *)pData;
	int res;
	
	if((res=strcmp(pSource->sHead,pTarget->sHead))!=0) return res;
	
	return 0;
}
int DGetT130AreaCodeHeadID(struct OrdT130AreaCodeStruct *p)
{
	int l=0;
	static BINTREE *pRootS=NULL;
	static int iFirstFlag=true;


	struct T130AreaCodeChkStruct *pTemp=NULL,*ptHead=NULL;
	struct T130AreaCodeChkStruct Temp;
	
	if(iFirstFlag==true){

		struct T130AreaCodeChkStructIn TempIn;
		
		iFirstFlag=false;
		TempIn.iFirstFlag=true;
		strcpy(TempIn.sTableName,"T130_AREA_CODE");
		strcpy(TempIn.sCondition,"WHERE STATE='A0A'");
		
		/*加载到平衡二叉树,根据 HEAD 建索引;*/
	
		while(EGetT130AreaCodeChkToStruct(&Temp,&TempIn)==true){
	                if((pTemp=malloc(sizeof(struct T130AreaCodeChkStruct)))==NULL){
	                        printf("分配内存失败T130_AREA_CODE_CHK.\n");
	                        return -1;
	                }
			memcpy((void*)pTemp,(void*)&Temp,sizeof(struct T130AreaCodeChkStruct));
			
			if(InsertBin(&pRootS,(void*)pTemp,
				data_search_bintree_t130_area_code_chk_e,
				assign_insert_bintree)<0) return 0;
		}
	}


	bzero((void*)&Temp,sizeof(struct T130AreaCodeChkStruct));
	
	strcpy(Temp.sHead,p->sHead);

	if(SearchBin(pRootS,(void*)&Temp,
		data_search_bintree_t130_area_code_chk_e,
		(void*)&ptHead)==NOTFOUND) return 0;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		l=strlen(p->sAreaCode);
		
		if(strcmp(pTemp->sAreaCode,p->sAreaCode)==0){
			p->iHeadID=pTemp->iHeadID;
			p->iSeqNbr=pTemp->iSeqNbr;
			strcpy(p->sRowID,pTemp->sRowID);
			return 0;
		}
		else if(strncmp(pTemp->sAreaCode,p->sAreaCode,l)==0){
			p->iHeadID=pTemp->iHeadID;
			p->iSeqNbr=pTemp->iSeqNbr;
			strcpy(p->sRowID,pTemp->sRowID);
			return 0;
		}
	}

	p->iHeadID=0;
	p->iSeqNbr=0;
        
        return 0;
        
}

/*批量数据结构缓冲写入ORD_T130_AREA_CODE*/
int EInsertStructToOrdT130AreaCode(struct OrdT130AreaCodeStruct *p,
	int iInsertFlag,struct OrdT130AreaCodeStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		pTarget->aiHeadID[iCurPos]=		p->iHeadID;
		pTarget->aiSeqNbr[iCurPos]=		p->iSeqNbr;

		strcpy(pTarget->asHead[iCurPos],	p->sHead);

		pTarget->aiLen[iCurPos]=		p->iLen;

		strcpy(pTarget->asAreaCode[iCurPos],	p->sAreaCode);
		strcpy(pTarget->asHeadType[iCurPos],	p->sHeadType);
		strcpy(pTarget->asRemark[iCurPos],	p->sRemark);
		strcpy(pTarget->asEffDate[iCurPos],	p->sEffDate);
		strcpy(pTarget->asExpDate[iCurPos],	p->sExpDate);
		strcpy(pTarget->asState[iCurPos],	p->sState);
		strcpy(pTarget->asStateDate[iCurPos],	p->sStateDate);
		strcpy(pTarget->asCreatedDate[iCurPos],	p->sCreatedDate);

		pTarget->aiStaffID[iCurPos]=		p->iStaffID;

		strcpy(pTarget->asOrdType[iCurPos],	p->sOrdType);
		strcpy(pTarget->asOrdNbr[iCurPos],	p->sOrdNbr);

		pTarget->aiOrdSeqNbr[iCurPos]=		p->iOrdSeqNbr;

		strcpy(pTarget->asOrdSourceID[iCurPos],	p->sOrdSourceID);
		strcpy(pTarget->asComments[iCurPos],	p->sComments);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==ORD_T130_AREA_CODE_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				HEAD_ID,\n\
				SEQ_NBR,\n\
				HEAD,\n\
				LEN,\n\
				AREA_CODE,\n\
				HEAD_TYPE,\n\
				REMARK,\n\
				EFF_DATE,\n\
				EXP_DATE,\n\
				STATE,\n\
				STATE_DATE,\n\
				CREATED_DATE,\n\
				STAFF_ID,\n\
				ORD_TYPE,\n\
				ORD_NBR,\n\
				ORD_SEQ_NBR,\n\
				ORD_SOURCE_ID,\n\
				COMMENTS)\n\
			VALUES (\n\
				:aiHeadID,\n\
				:aiSeqNbr,\n\
				:asHead,\n\
				:aiLen,\n\
				:asAreaCode,\n\
				:asHeadType,\n\
				:asRemark,\n\
				to_date(:asEffDate,'yyyymmddhh24miss'),\n\
				to_date(:asExpDate,'yyyymmddhh24miss'),\n\
				:asState,\n\
				to_date(:asStateDate,'yyyymmddhh24miss'),\n\
				to_date(:asCreatedDate,'yyyymmddhh24miss'),\n\
				:aiStaffID,\n\
				:asOrdType,\n\
				:asOrdNbr,\n\
				:aiOrdSeqNbr,\n\
				:asOrdSourceID,\n\
				:asComments\n\
			)",sTableName);

		/* EXEC SQL PREPARE ORD_T130_AREA_CODETRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
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


		if(CheckSqlResult("Prepare insert statement ORD_T130_AREA_CODE")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE ORD_T130_AREA_CODETRG USING
				:pTarget->aiHeadID,
				:pTarget->aiSeqNbr,
				:pTarget->asHead,
				:pTarget->aiLen,
				:pTarget->asAreaCode,
				:pTarget->asHeadType,
				:pTarget->asRemark,
				:pTarget->asEffDate,
				:pTarget->asExpDate,
				:pTarget->asState,
				:pTarget->asStateDate,
				:pTarget->asCreatedDate,
				:pTarget->aiStaffID,
				:pTarget->asOrdType,
				:pTarget->asOrdNbr,
				:pTarget->aiOrdSeqNbr,
				:pTarget->asOrdSourceID,
				:pTarget->asComments; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )43;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiHeadID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asHead);
  sqlstm.sqhstl[2] = (unsigned long )12;
  sqlstm.sqhsts[2] = (         int  )12;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiLen);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asHeadType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asRemark);
  sqlstm.sqhstl[6] = (unsigned long )61;
  sqlstm.sqhsts[6] = (         int  )61;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asEffDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asExpDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asState);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asStateDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asCreatedDate);
  sqlstm.sqhstl[11] = (unsigned long )15;
  sqlstm.sqhsts[11] = (         int  )15;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pTarget->aiStaffID);
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(int);
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pTarget->asOrdType);
  sqlstm.sqhstl[13] = (unsigned long )5;
  sqlstm.sqhsts[13] = (         int  )5;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pTarget->asOrdNbr);
  sqlstm.sqhstl[14] = (unsigned long )31;
  sqlstm.sqhsts[14] = (         int  )31;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)(pTarget->aiOrdSeqNbr);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(int);
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)(pTarget->asOrdSourceID);
  sqlstm.sqhstl[16] = (unsigned long )31;
  sqlstm.sqhsts[16] = (         int  )31;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)(pTarget->asComments);
  sqlstm.sqhstl[17] = (unsigned long )101;
  sqlstm.sqhsts[17] = (         int  )101;
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


		if(CheckSqlResult("Dyn insert into ORD_T130_AREA_CODE")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}



/*批量数据结构缓冲UpdateT130_AREA_CODE*/
int EUpdateStructToT130AreaCode(struct T130AreaCodeChkStruct *p,
	int iUpdateFlag,struct T130AreaCodeChkStructUp *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iUpdateFlag!=TRUE){

/*放置数据到静态缓冲*/
		strcpy(pTarget->asState[iCurPos],	p->sState);
		strcpy(pTarget->asRowID[iCurPos],	p->sRowID);


		iCurPos++;
	}

	if(iUpdateFlag==TRUE||iCurPos==T130_AREA_CODE_CHK_BUFLEN_UP){

/* Update */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			UPDATE %s \n\
			SET \n\
				STATE=		:asState,\n\
				STATE_DATE=	SYSDATE\n\
			WHERE \n\
				ROWID = chartorowid(:asRowID)\n\
			",sTableName);
		/* EXEC SQL PREPARE T130_AREA_CODETRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )130;
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


		if(CheckSqlResult("Prepare Update statement T130_AREA_CODE")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE T130_AREA_CODETRG USING
				:pTarget->asState,
				:pTarget->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )149;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->asState);
  sqlstm.sqhstl[0] = (unsigned long )4;
  sqlstm.sqhsts[0] = (         int  )4;
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


		if(CheckSqlResult("Dyn Update T130_AREA_CODE")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}

/*批量数据结构缓冲写入T130_AREA_CODE_CHK*/
int EInsertStructToT130AreaCodeChk(struct T130AreaCodeChkStruct *p,
	int iInsertFlag,struct T130AreaCodeChkStructOut *pTarget)
{

	int  iCurPos=pTarget->iCurPos;
	char *sTableName=pTarget->sTableName;

	if(iInsertFlag!=TRUE){

/*放置数据到静态缓冲*/
		pTarget->aiHeadID[iCurPos]=		p->iHeadID;
		pTarget->aiSeqNbr[iCurPos]=		p->iSeqNbr;

		strcpy(pTarget->asHead[iCurPos],	p->sHead);

		pTarget->aiLen[iCurPos]=		p->iLen;

		strcpy(pTarget->asAreaCode[iCurPos],	p->sAreaCode);
		strcpy(pTarget->asHeadType[iCurPos],	p->sHeadType);
		strcpy(pTarget->asRemark[iCurPos],	p->sRemark);
		strcpy(pTarget->asEffDate[iCurPos],	p->sEffDate);
		strcpy(pTarget->asExpDate[iCurPos],	p->sExpDate);
		strcpy(pTarget->asState[iCurPos],	p->sState);
		strcpy(pTarget->asStateDate[iCurPos],	p->sStateDate);
		strcpy(pTarget->asCreatedDate[iCurPos],	p->sCreatedDate);

		iCurPos++;
	}

	if(iInsertFlag==TRUE||iCurPos==T130_AREA_CODE_CHK_BUFLEN_OUT){

/* INSERT */
		char statement[8192];

		if(iCurPos==0) return 0;

		sprintf(statement,"\n\
			INSERT INTO %s(\n\
				HEAD_ID,\n\
				SEQ_NBR,\n\
				HEAD,\n\
				LEN,\n\
				AREA_CODE,\n\
				HEAD_TYPE,\n\
				REMARK,\n\
				EFF_DATE,\n\
				EXP_DATE,\n\
				STATE,\n\
				STATE_DATE,\n\
				CREATED_DATE)\n\
			VALUES (\n\
				:aiHeadID,\n\
				:aiSeqNbr,\n\
				:asHead,\n\
				:aiLen,\n\
				:asAreaCode,\n\
				:asHeadType,\n\
				:asRemark,\n\
				to_date(:asEffDate,'yyyymmddhh24miss'),\n\
				to_date(:asExpDate,'yyyymmddhh24miss'),\n\
				:asState,\n\
				to_date(:asStateDate,'yyyymmddhh24miss'),\n\
				to_date(:asCreatedDate,'yyyymmddhh24miss')\n\
			)",sTableName);

		/* EXEC SQL PREPARE T130_AREA_CODE_CHKTRG FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )172;
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


		if(CheckSqlResult("Prepare insert statement T130_AREA_CODE_CHK")<0) return -1;

		/* EXEC SQL FOR :iCurPos EXECUTE T130_AREA_CODE_CHKTRG USING
				:pTarget->aiHeadID,
				:pTarget->aiSeqNbr,
				:pTarget->asHead,
				:pTarget->aiLen,
				:pTarget->asAreaCode,
				:pTarget->asHeadType,
				:pTarget->asRemark,
				:pTarget->asEffDate,
				:pTarget->asExpDate,
				:pTarget->asState,
				:pTarget->asStateDate,
				:pTarget->asCreatedDate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )iCurPos;
  sqlstm.offset = (unsigned int  )191;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)(pTarget->aiHeadID);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(pTarget->aiSeqNbr);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(int);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(pTarget->asHead);
  sqlstm.sqhstl[2] = (unsigned long )12;
  sqlstm.sqhsts[2] = (         int  )12;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pTarget->aiLen);
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(int);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(pTarget->asAreaCode);
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )10;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(pTarget->asHeadType);
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )2;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(pTarget->asRemark);
  sqlstm.sqhstl[6] = (unsigned long )61;
  sqlstm.sqhsts[6] = (         int  )61;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(pTarget->asEffDate);
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )15;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(pTarget->asExpDate);
  sqlstm.sqhstl[8] = (unsigned long )15;
  sqlstm.sqhsts[8] = (         int  )15;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(pTarget->asState);
  sqlstm.sqhstl[9] = (unsigned long )4;
  sqlstm.sqhsts[9] = (         int  )4;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(pTarget->asStateDate);
  sqlstm.sqhstl[10] = (unsigned long )15;
  sqlstm.sqhsts[10] = (         int  )15;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(pTarget->asCreatedDate);
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


		if(CheckSqlResult("Dyn insert into T130_AREA_CODE_CHK")<0) return -1;

		iCurPos=0;
	}

	pTarget->iCurPos=iCurPos;
	return 0;
}


void mvitem_mfordt130areacode(struct OrdT130AreaCodeStruct *pi,
	struct FOrdT130AreaCodeStruct *po)
{
	char sTemp[128];

	memset((void*)po,' ',sizeof(struct FOrdT130AreaCodeStruct));

		sprintf(sTemp,"%06d",pi->iHeadID);
		strncpy(po->sHeadID,sTemp,6);
		sprintf(sTemp,"%03d",pi->iSeqNbr);
		strncpy(po->sSeqNbr,sTemp,3);

		strncpy(po->sHead,pi->sHead,strlen(pi->sHead));

		sprintf(sTemp,"%02d",pi->iLen);
		strncpy(po->sLen,sTemp,2);

		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
		strncpy(po->sHeadType,pi->sHeadType,strlen(pi->sHeadType));
		strncpy(po->sRemark,pi->sRemark,strlen(pi->sRemark));
		strncpy(po->sEffDate,pi->sEffDate,strlen(pi->sEffDate));
		strncpy(po->sExpDate,pi->sExpDate,strlen(pi->sExpDate));
		strncpy(po->sState,pi->sState,strlen(pi->sState));
		strncpy(po->sStateDate,pi->sStateDate,strlen(pi->sStateDate));
		strncpy(po->sCreatedDate,pi->sCreatedDate,strlen(pi->sCreatedDate));

		sprintf(sTemp,"%06d",pi->iStaffID);
		strncpy(po->sStaffID,sTemp,6);

		strncpy(po->sOrdType,pi->sOrdType,strlen(pi->sOrdType));
		strncpy(po->sOrdNbr,pi->sOrdNbr,strlen(pi->sOrdNbr));

		sprintf(sTemp,"%02d",pi->iOrdSeqNbr);
		strncpy(po->sOrdSeqNbr,sTemp,2);

		strncpy(po->sOrdSourceID,pi->sOrdSourceID,strlen(pi->sOrdSourceID));
		strncpy(po->sComments,pi->sComments,strlen(pi->sComments));

}


void mvitem_ordt130areacode(struct OrdT130AreaCodeStruct *pi,struct OrdT130AreaCodeStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct OrdT130AreaCodeStruct));

		po->iHeadID=		pi->iHeadID;
		po->iSeqNbr=		pi->iSeqNbr;

		strncpy(po->sHead,	pi->sHead,11);

		po->iLen=		pi->iLen;

		strncpy(po->sAreaCode,	pi->sAreaCode,9);
		strncpy(po->sHeadType,	pi->sHeadType,1);
		strncpy(po->sRemark,	pi->sRemark,60);
		strncpy(po->sEffDate,	pi->sEffDate,14);
		strncpy(po->sExpDate,	pi->sExpDate,14);
		strncpy(po->sState,	pi->sState,3);
		strncpy(po->sStateDate,	pi->sStateDate,14);
		strncpy(po->sCreatedDate,pi->sStateDate,14);
		strncpy(po->sOrdType,	pi->sOrdType,4);
		
		po->iOrdSeqNbr=		pi->iOrdSeqNbr;
		po->iStaffID=		pi->iStaffID;
		
		strncpy(po->sOrdSourceID,pi->sOrdSourceID,30);
		strncpy(po->sComments,	pi->sComments,100);
		strncpy(po->sOrdNbr,	pi->sOrdNbr,30);
		strncpy(po->sRowID,	pi->sRowID,19);
}


void mvitem_fmmobilehead(struct FMobileHeadStruct *pi,struct MobileHeadStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct MobileHeadStruct));

		strncpy(po->sRecordType,pi->sRecordType,2);
		strncpy(po->sProvCode,	pi->sProvCode,3);
		strncpy(po->sCityCode,	pi->sCityCode,3);
		strncpy(po->sAreaCode,	pi->sAreaCode,8);
		strncpy(po->sTailHead,	pi->sTailHead,6);
		strncpy(po->sReserve,	pi->sReserve,8);

		AllTrim(po->sRecordType);
		AllTrim(po->sProvCode);
		AllTrim(po->sCityCode);
		AllTrim(po->sAreaCode);
		AllTrim(po->sTailHead);
		AllTrim(po->sReserve);
}
void mvitem_fmheadmobilehead(struct FHeadMobileHeadStruct *pi,struct HeadMobileHeadStruct *po)
{/*数据文件移动到内存部分*/

	bzero((void*)po,sizeof(struct HeadMobileHeadStruct));

		strncpy(po->sRecordType,pi->sRecordType,2);
		strncpy(po->sProvCode,	pi->sProvCode,3);
		strncpy(po->sHead,	pi->sHead,3);
		strncpy(po->sDate,	pi->sDate,8);
		strncpy(po->sSumCount,	pi->sSumCount,10);
		strncpy(po->sReserve,	pi->sReserve,4);

		AllTrim(po->sRecordType);
		AllTrim(po->sProvCode);
		AllTrim(po->sHead);
		AllTrim(po->sDate);
		AllTrim(po->sSumCount);
		AllTrim(po->sReserve);
}

     
void mvitem_ordtot130areacode(struct OrdT130AreaCodeStruct *pi,struct T130AreaCodeChkStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct T130AreaCodeChkStruct));

		po->iHeadID=		pi->iHeadID;
		po->iSeqNbr=		pi->iSeqNbr;
		
		strncpy(po->sHead,	pi->sHead,11);

		po->iLen=		pi->iLen;

		strncpy(po->sAreaCode,	pi->sAreaCode,9);
		strncpy(po->sHeadType,	pi->sHeadType,1);
		strncpy(po->sRemark,	pi->sRemark,60);
		strncpy(po->sEffDate,	pi->sEffDate,14);
		strncpy(po->sExpDate,	pi->sExpDate,14);
		strncpy(po->sState,	pi->sState,3);
		strncpy(po->sStateDate,	pi->sStateDate,14);
		strncpy(po->sCreatedDate,pi->sCreatedDate,14);
		strncpy(po->sRowID,	pi->sRowID,19);

}
/*批量数据动态从T130_AREA_CODE_CHK中用结构缓冲方式取数据*/
int EGetT130AreaCodeChkToStruct(struct T130AreaCodeChkStruct *p,
	struct T130AreaCodeChkStructIn *pSource)
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
				nvl(LEN,0),\n\
				nvl(AREA_CODE,' '),\n\
				nvl(HEAD_TYPE,' '),\n\
				REMARK,\n\
				to_char(nvl(EFF_DATE,SYSDATE-3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(EXP_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				nvl(STATE,' '),\n\
				to_char(nvl(STATE_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				to_char(nvl(CREATED_DATE,SYSDATE+3000),'yyyymmddhh24miss'),\n\
				rowidtochar(ROWID)\n\
			FROM %s %s",sTableName,sCondition);

		/* EXEC SQL PREPARE T130_AREA_CODE_CHKSCR FROM :statement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )254;
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


		CheckSqlError(" PREPARE T130_AREA_CODE_CHKSCR T130_AREA_CODE_CHKCR");

		/* EXEC SQL DECLARE T130_AREA_CODE_CHKCR CURSOR FOR T130_AREA_CODE_CHKSCR; */ 

		CheckSqlError("Declare T130_AREA_CODE_CHKCR");

		/* EXEC SQL OPEN T130_AREA_CODE_CHKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )273;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		CheckSqlError("Open T130_AREA_CODE_CHKCR;");


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

		/* EXEC SQL CLOSE T130_AREA_CODE_CHKCR; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )288;
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
		/* EXEC SQL FETCH T130_AREA_CODE_CHKCR INTO
			:pSource->aiHeadID,
			:pSource->aiSeqNbr,
			:pSource->asHead,
			:pSource->aiLen,
			:pSource->asAreaCode,
			:pSource->asHeadType,
			:pSource->asRemark,
			:pSource->asEffDate,
			:pSource->asExpDate,
			:pSource->asState,
			:pSource->asStateDate,
			:pSource->asCreatedDate,
			:pSource->asRowID; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )300;
  sqlstm.offset = (unsigned int  )303;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
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
  sqlstm.sqhstv[12] = (unsigned char  *)(pSource->asRowID);
  sqlstm.sqhstl[12] = (unsigned long )19;
  sqlstm.sqhsts[12] = (         int  )19;
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


		CheckSqlError("Fetch T130_AREA_CODE_CHKCR");

		pSource->iRecCnt=FetchColNum-pSource->iFetchRecNum;

		if(!pSource->iRecCnt){

			pSource->iBufEmpty=TRUE;
			pSource->iCurPos=0;
			pSource->iFetchRecNum=0;
			pSource->iEndFlag=FALSE;
			pSource->iFirstFlag=TRUE;

			/* EXEC SQL CLOSE T130_AREA_CODE_CHKCR; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 18;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )370;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



			return FALSE;
		}

		if(pSource->iRecCnt!=T130_AREA_CODE_CHK_BUFLEN_IN)
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

		p->iLen=		pSource->aiLen[iCurPos];

		strcpy(p->sAreaCode,	pSource->asAreaCode[iCurPos]);
		strcpy(p->sHeadType,	pSource->asHeadType[iCurPos]);
		strcpy(p->sRemark,	pSource->asRemark[iCurPos]);
		strcpy(p->sEffDate,	pSource->asEffDate[iCurPos]);
		strcpy(p->sExpDate,	pSource->asExpDate[iCurPos]);
		strcpy(p->sState,	pSource->asState[iCurPos]);
		strcpy(p->sStateDate,	pSource->asStateDate[iCurPos]);
		strcpy(p->sCreatedDate,	pSource->asCreatedDate[iCurPos]);
		strcpy(p->sRowID,       pSource->asRowID[iCurPos]);
		
		AllTrim(p->sHead);
		AllTrim(p->sAreaCode);
		AllTrim(p->sHeadType);
		AllTrim(p->sRemark);
		AllTrim(p->sEffDate);
		AllTrim(p->sExpDate);
		AllTrim(p->sState);
		AllTrim(p->sStateDate);
		AllTrim(p->sCreatedDate);
		AllTrim(p->sRowID);

	iCurPos++;

	if(iCurPos==pSource->iRecCnt)
		pSource->iBufEmpty=TRUE;
	pSource->iCurPos=iCurPos;
	return TRUE;
}

