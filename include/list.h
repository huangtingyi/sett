#ifndef __LIST_H__
#define __LIST_H__

#include "datatype.h"

typedef struct __List__
{
	struct __List__ *pNext;
} LIST;

typedef struct __Link__
{
	struct __Link__ *pNext;
	void	*pData;
} LINK;

/*��������ĸ���*/
int CountList(LIST* ptHead);

/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelList(LIST *ptHead,int (*operate_list)(LIST *));


/*ֱ�ӽ����ݲ���ͷ�ڵ�*/
void InsertList(LIST **pptHead,LIST *p);
void InsertListTail(LIST **pptHead,LIST *p);
void AppendListTail(LIST **pptHead,LIST *p);


/*����comp_list�ǶԲ���ľ������,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	   */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)    */
/*�ú�����LIST *p �������ⲿ������ڴ� 			*/
void InsertListSort(LIST **pptHead,LIST *p,int (*comp_list)(LIST *,LIST *));


/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����LIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�LIST�У��ڴ���ظ�����
*/
int InsertListSumm(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *));
int InsertListSortSum(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *));

/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchList(LIST *ptHead,void *pi,LIST **p,int (*comp_list)(void *,LIST *));


/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteList(LIST **pptHead,LIST *p);

void DestroyList(LIST *p);
void FreeList(LIST *p);
void ReverseList(LIST **pptHead);
void assign_insert_list(void **ppData,void *pData);


LINK *MallocLink();
int4b InsertLink(LINK **pptHead, void *pData,LINK *pTemp);
int4b DeleteLink(LINK **pptHead, LINK *p);
int4b SearchLink(LINK *ptHead, void *pi, LINK **p, 
	int4b ( *comp_Link)(void *,void *));
int4b InsertLinkSort(LINK **pptHead, void *p,
	int4b (*comp_Link)(void *,void *),LINK *pTemp);
int4b InsertLinkSumm(LINK **pptHead, void *p, 
	int4b ( *comp_Link)(void *,void *), 
	void ( *sum_Link)(void *,void *),LINK **ppTemp);
int4b CountLink(LINK *ptHead);
int4b TravelLink(LINK *ptHead, int4b (*operate_Link)(void *));
void DestroyLink(LINK *ptHead);
void ClearLink(LINK *ptHead);

	
typedef struct __E_List__
{
	POINTER ioffNext;
} ELIST;

#define ELISTNXT(p,o) ((ELIST*)(((char*)(p))+(o)))->ioffNext

/**
ƫ�Ƶ�ƫ��OO
ָ�뵽ָ��PP
ƫ�Ƶ�ָ��OP
**/
#define TPOINTER(o)	((POINTER)(o))
#define TELIST(p)	((ELIST*)(p))
#define OPELIST(s,o)	TELIST((char*)(s)+(o))
#define POFFCHAR(s,p)	TPOINTER((char*)(p)-(char*)(s))
#define OOELISTNXT(s,o) OPELIST(s,o)->ioffNext
#define PPELISTNXT(s,p) OPELIST(s,TELIST(p)->ioffNext)
#define OPELISTNXT(s,o) OPELIST(s,OPELIST(s,o)->ioffNext)


/*��������ĸ���*/
int CountEList(void *pSeg,POINTER ioffHead);

/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelEList(void *pSeg,POINTER ioffHead,int (*operate_list)(POINTER));


void InsertEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void InsertEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void AppendEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void InsertEListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ));
int InsertEListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ));
int SearchEList(void *pSeg,POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,POINTER));
int DeleteEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void ReverseEList(void *pSeg,POINTER *pioffHead);


#define FLISTMAX 20
struct FMemStruct
{
	POINTER iTotalLen;
	POINTER iBlockLen;
	int	iBlockCnt;
	void	*apHead[FLISTMAX];
};
POINTER PoFList(struct FMemStruct *p,void *pv);
void *OpFList(struct FMemStruct *p,POINTER o);
#define FMEM(s)	((struct FMemStruct *)s)
#define OPFLIST(s,o)	TELIST(((o)/FMEM(s)->iBlockLen>FLISTMAX?\
		NULL:(char*)(FMEM(s)->apHead[(o)/FMEM(s)->iBlockLen])+\
		(o)%FMEM(s)->iBlockLen))
/*#define OPFLIST(s,o)    TELIST(OpFList((struct FMemStruct *)(s),o))*/
#define OOFLISTNXT(s,o) OPFLIST(s,o)->ioffNext
#define FLISTNXT(s,o) 	OOFLISTNXT(s,o)
#define PPFLISTNXT(s,p) OPFLIST(s,TELIST(p)->ioffNext)
#define OPFLISTNXT(s,o) OPFLIST(s,OPFLIST(s,o)->ioffNext)
#define POFLIST(s,p)	TPOINTER(PoFList((struct FMemStruct *)(s),(p)))
#define FLISTLEN(s)	((struct FMemStruct*)(s))->iTotalLen

/*��������ĸ���*/
int CountFList(void *pSeg,POINTER ioffHead);

/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelFList(void *pSeg,POINTER ioffHead,int (*operate_list)(POINTER));


void InsertFList(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void InsertFListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void AppendFListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void InsertFListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ));
int InsertFListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ));
int SearchFList(void *pSeg,POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,POINTER));
int DeleteFList(void *pSeg,POINTER *pioffHead,POINTER ioffValue);
void ReverseFList(void *pSeg,POINTER *pioffHead);

/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelVlist(void *ptHead,int (*operate_list)(void *),
	void *(*getnext)(void*));

int CountVlist(void *ptHead,void *(*getnext)(void*));

/*ֱ�ӽ����ݲ���ͷ�ڵ�*/
void InsertVlist(void **pptHead,void *p,void **(*get_next)(void *));

void InsertVListSort(void **pptHead,void *pValue,
	int (*comp_list)(void *,void *),void **(*get_next)(void *));

/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����LIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�LIST�У��ڴ���ظ�����
*/
int InsertVListSumm(void **pptHead,void *pValue,
        int (*comp_list)(void *,void *),
        void (*sum_list)(void *,void *),
        void **(*get_next)(void *),void (*assign_list)(void*,void *));

/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchVlist(void *ptHead,void *pi,void **p,
        int (*comp_list)(void *,void *),void **(*get_next)(void *));


/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteVList(void **pptHead,void *p,void (*assign_list)(void*,void *),
		void **(*getnext)(void *));
void ReverseVList(void **pptHead,void **(*getnext)(void *));

/*****************�������ڴ�����****/
void InsertVEList(POINTER *pioffsetHead,POINTER ioffsetValue,
	POINTER *(*get_next)(POINTER));
void InsertVEListSort(POINTER *pioffsetHead,POINTER ioffsetValue,
	int (*comp_list)(POINTER ,POINTER ),POINTER *(*get_next)(POINTER ));
int CountVEList(POINTER ioffHead,POINTER *(*get_next)(POINTER));
int TravelVEList(POINTER ioffHead,int (*operate_list)(POINTER),
	POINTER *(*get_next)(POINTER));
void InsertVEListTail(POINTER *pioffHead,POINTER ioffValue,
	POINTER *(*get_next)(POINTER));
void AppendVEListTail(POINTER *pioffHead,POINTER ioffValue,
	POINTER *(*get_next)(POINTER));
int InsertVEListSumm(POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ),
	POINTER *(*get_next)(POINTER ) );
int SearchVEList(POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,POINTER),
	POINTER *(*get_next)(POINTER ));
int DeleteVEList(POINTER *pioffHead,POINTER ioffValue,
	POINTER *(*get_next)(POINTER ));
void ReverseVEList(void *pSeg,POINTER *pioffHead,
	POINTER *(*get_next)(POINTER ));

typedef struct __MList__
{
        struct __MList__ *pNext[1];
} MLIST;

int CountMList(MLIST* ptHead,int n);
int TravelMList(MLIST *ptHead,int (*operate_list)(MLIST *),int n);
void InsertMList(MLIST **pptHead,MLIST *p,int n);
void InsertMListTail(MLIST **pptHead,MLIST *p,int n);
void AppendMListTail(MLIST **pptHead,MLIST *p,int n);
void InsertMListSort(MLIST **pptHead,MLIST *p,
	int (*comp_list)(MLIST *,MLIST *),int n);
int InsertMListSumm(MLIST **pptHead,MLIST *p,
      int (*comp_list)(MLIST *,MLIST *),
      void (*sum_list)(MLIST *,MLIST *),int n);
int SearchMList(MLIST *ptHead,void *pi,MLIST **p,
	int (*comp_list)(void *,MLIST *),int n);
int DeleteMList(MLIST **pptHead,MLIST *p,int n);
void DestroyMList(MLIST *ptHead,int n);
void ReverseMList(MLIST **pptHead,int n);


typedef struct __ME_List__
{
        POINTER ioffNext[1];
} MELIST;

#define MELISTNXT(p,o,n) ((MELIST*)(((char*)(p))+(o)))->ioffNext[n]

/**
ƫ�Ƶ�ƫ��OO
ָ�뵽ָ��PP
ƫ�Ƶ�ָ��OP
**/
#define TMELIST(p)	((MELIST*)(p))
#define OPMELIST(s,o)	TMELIST((char*)(s)+(o))
#define POMELIST(s,p)	TPOINTER((char*)(p)-(char*)(s))
#define OOMELISTNXT(s,o,n) TMELIST(OPELIST(s,o)->ioffNext[n])
#define PPMELISTNXT(s,p,n) OPMELIST(s,TELIST(p)->ioffNext[n])
#define OPMELISTNXT(s,o,n) OPMELIST(s,OPELIST(s,o)->ioffNext[n])

int CountMEList(void *pSeg,POINTER ioffHead,int n);
int TravelMEList(void *pSeg,POINTER ioffHead,
	int (*operate_list)(POINTER),int n);
void InsertMEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n);
void InsertMEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n);
void AppendMEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n);
void InsertMEListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),int n);
int InsertMEListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ),int n);
int SearchMEList(void *pSeg,POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,void *,POINTER),int n);
int DeleteMEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n);
void ReverseMEList(void *pSeg,POINTER *pioffHead,int n);

/*��ɰ�ĳ������*/
void InsertListE(POINTER *pioffsetHead,POINTER ioffsetValue,
	POINTER *(*get_next)(POINTER));
void InsertListSortE(POINTER *pioffsetHead,POINTER ioffsetValue,
	int (*comp_list)(POINTER ,POINTER ),POINTER *(*get_next)(POINTER ));

#endif
