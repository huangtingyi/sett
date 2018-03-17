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

/*计算链表的个数*/
int CountList(LIST* ptHead);

/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
int TravelList(LIST *ptHead,int (*operate_list)(LIST *));


/*直接将数据插入头节点*/
void InsertList(LIST **pptHead,LIST *p);
void InsertListTail(LIST **pptHead,LIST *p);
void AppendListTail(LIST **pptHead,LIST *p);


/*其中comp_list是对插入的具体操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	   */
/*对插入的节点的pNext没有要求(链表内部自动复位)    */
/*该函数的LIST *p 参数是外部分配的内存 			*/
void InsertListSort(LIST **pptHead,LIST *p,int (*comp_list)(LIST *,LIST *));


/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的LIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存LIST中，内存可重复利用
*/
int InsertListSumm(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *));
int InsertListSortSum(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *));

/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
int SearchList(LIST *ptHead,void *pi,LIST **p,int (*comp_list)(void *,LIST *));


/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
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
偏移到偏移OO
指针到指针PP
偏移到指针OP
**/
#define TPOINTER(o)	((POINTER)(o))
#define TELIST(p)	((ELIST*)(p))
#define OPELIST(s,o)	TELIST((char*)(s)+(o))
#define POFFCHAR(s,p)	TPOINTER((char*)(p)-(char*)(s))
#define OOELISTNXT(s,o) OPELIST(s,o)->ioffNext
#define PPELISTNXT(s,p) OPELIST(s,TELIST(p)->ioffNext)
#define OPELISTNXT(s,o) OPELIST(s,OPELIST(s,o)->ioffNext)


/*计算链表的个数*/
int CountEList(void *pSeg,POINTER ioffHead);

/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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

/*计算链表的个数*/
int CountFList(void *pSeg,POINTER ioffHead);

/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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

/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
int TravelVlist(void *ptHead,int (*operate_list)(void *),
	void *(*getnext)(void*));

int CountVlist(void *ptHead,void *(*getnext)(void*));

/*直接将数据插入头节点*/
void InsertVlist(void **pptHead,void *p,void **(*get_next)(void *));

void InsertVListSort(void **pptHead,void *pValue,
	int (*comp_list)(void *,void *),void **(*get_next)(void *));

/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的LIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存LIST中，内存可重复利用
*/
int InsertVListSumm(void **pptHead,void *pValue,
        int (*comp_list)(void *,void *),
        void (*sum_list)(void *,void *),
        void **(*get_next)(void *),void (*assign_list)(void*,void *));

/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
int SearchVlist(void *ptHead,void *pi,void **p,
        int (*comp_list)(void *,void *),void **(*get_next)(void *));


/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
int DeleteVList(void **pptHead,void *p,void (*assign_list)(void*,void *),
		void **(*getnext)(void *));
void ReverseVList(void **pptHead,void **(*getnext)(void *));

/*****************抽象共享内存链表****/
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
偏移到偏移OO
指针到指针PP
偏移到指针OP
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

/*与旧版的程序兼容*/
void InsertListE(POINTER *pioffsetHead,POINTER ioffsetValue,
	POINTER *(*get_next)(POINTER));
void InsertListSortE(POINTER *pioffsetHead,POINTER ioffsetValue,
	int (*comp_list)(POINTER ,POINTER ),POINTER *(*get_next)(POINTER ));

#endif
