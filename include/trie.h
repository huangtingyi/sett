
#ifndef	__TRIE_H__
#define __TRIE_H__

#include "datatype.h"
#include "wwshm.h"
#include "list.h"

typedef struct __Trie__ {
	
    struct __Trie__  *pNext[10];
    void  *pData[10];
    
} TRIE;

typedef struct __ETrie__{
	POINTER ioffNext;   /*单位为char*/
	POINTER	ioffNxt[10];/*单位为char*/
	POINTER	ioffDat[10];

} ETRIE;

/**
偏移到偏移OO
指针到指针PP
偏移到指针OP
**/
#define TETRIE(p)		((ETRIE*)(p))
#define OPETRIE(s,o)		TETRIE((char*)(s)+(o))

#define OOETRIENEXT(s,o)	(OPETRIE(s,o)->ioffNext)
#define OOETRIENXT(s,o,f)	(OPETRIE(s,o)->ioffNxt[f])

#define OPETRIENEXT(s,o)	OPETRIE(s,OOETRIENEXT(s,o))
#define OPETRIENXT(s,o,f)	OPETRIE(s,OOETRIENXT(s,o,f))

#define PPETRIENEXT(s,p)	OPETRIE(s,TETRIE(p)->ioffNext)
#define PPETRIENXT(s,p,f)	OPETRIE(s,TETRIE(p)->ioffNxt[f])


TRIE * MallocTrie();
int4b InsertTrie(TRIE **pptHead,char key[], void *pValue,void (*pAssign)(void **,void *));
void assign_insert_trie(void **ppData,void *pData);
void** GetTrieLk(TRIE *ptHead,char key[]);
int4b DestroyTrie(TRIE *ptHead);
int4b SearchTrie(TRIE *ptHead,char key[], void **pptCur);
int4b SearchTrieF(TRIE *ptHead,char key[], void **pptCur);
int4b TravelTrieD(TRIE *ptHead,int (*pTravelOper)(void **));
int4b TravelTrieN(TRIE *ptHead,int (*pTravelOper)(TRIE *));
int4b TravelTrie(TRIE *ptHead, int ( *pTravelOper)(void **));
int4b TravelTrieNode(TRIE *ptHead,int (*pTravelOper)(TRIE *));
void DeleteTrie(TRIE **pptHead,char key[], void **pptCur);
int4b TrieEmpty(TRIE *ptHead);
void ReHookTrie(TRIE *pRoot,TRIE *ptHead);


POINTER MallocETrie(void *pNodeSeg,struct ShmCtrlStruct *ptHead);
int  InsertETrie(void *pNodeSeg,POINTER *pioffsetHead,
	char key[],struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
        void (*pAssign)(POINTER*,POINTER)); /*扩展模式树生成*/
int SearchETrie(void *pNodeSeg,POINTER ioffsetHead,char key[],
	POINTER *pioffsetCur);
POINTER *GetETrieLk(void *pNodeSeg,POINTER ioffsetHead,char key[]);
int TravelETrieN(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(ETRIE * ));
int TravelETrieD(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER* ));
int TravelETrie(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER* ));
int4b DestroyETrie(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl);
void ReHookETrie(void *pSeg,POINTER ioffRoot,POINTER ioffHead);

#define OPFTRIE(s,o)		TETRIE(OPFLIST(s,o))

#define OOFTRIENEXT(s,o)	(OPFTRIE(s,o)->ioffNext)
#define OOFTRIENXT(s,o,f)	(OPFTRIE(s,o)->ioffNxt[f])

#define OPFTRIENEXT(s,o)	OPFTRIE(s,OOFTRIENEXT(s,o))
#define OPFTRIENXT(s,o,f)	OPFTRIE(s,OOFTRIENXT(s,o,f))

#define PPFTRIENEXT(s,p)	OPFTRIE(s,TETRIE(p)->ioffNext)
#define PPFTRIENXT(s,p,f)	OPFTRIE(s,TETRIE(p)->ioffNxt[f])

POINTER MallocFTrie(void *pNodeSeg,struct ShmCtrlStruct *ptHead);
int  InsertFTrie(void *pNodeSeg,POINTER *pioffsetHead,
	char key[],struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
        void (*pAssign)(POINTER*,POINTER)); /*扩展模式树生成*/
int SearchFTrie(void *pNodeSeg,POINTER ioffsetHead,char key[],
	POINTER *pioffsetCur);
POINTER *GetFTrieLk(void *pNodeSeg,POINTER ioffsetHead,char key[]);
int TravelFTrieN(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(ETRIE * ));
int TravelFTrieD(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER* ));
int TravelFTrie(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER* ));
int4b DestroyFTrie(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl);
void ReHookFTrie(void *pSeg,POINTER ioffRoot,POINTER ioffHead);


/****************************************************************
*		用户资料维护专用键树支持函数			*
*								*
*****************************************************************/
typedef struct _Trie_O_ {

	struct _Trie_O_  *pNext[10];
	POINTER ioffsetData[10];
	int	NextOffset;

} TRIEO;

typedef struct _Trie_Ext_{

	POINTER	ioffsetNext[10];
	POINTER	ioffsetData[10];
	int     NextOffset;

} TRIEEXT;
/*"警告如果地址错误可能coredump危险!!!"*/
/*pAssign赋值中隐含中调用了全局的索引段---和数据段地址OK*/
int  InsertTrieE(POINTER *pioffsetHead,TRIEEXT *pNodeSeg,
        char key[],POINTER *pioffsetFreeNode,
	POINTER *pioffsetCurNode,POINTER ioffsetData,
        int (*pAssign)(POINTER*,POINTER/*数据偏移*/)); /*扩展模式树生成*/
/*
功能：  遍历键树的每一个数据链表，同时对数据链表进行指定操作
参数：  键树头指针偏移，段地址
        对每一个数据链表的操作函数
注意：
返回值：是所有数据操作返回值的和，具体与遍历操作有关
*/
int TravelTrieED(POINTER ioffsetHead,TRIEEXT *pNodeSeg,int (*pTravelOper)(POINTER ));
/*
功能：  遍历键树的每节点，同时对数据链表进行指定操作
参数：  键树头指针偏移，段地址
        对每一个NODE节点操作一般用来释放内存
注意：
返回值：是所有数据操作返回值的和，具体与遍历操作有关
*/
int TravelTrieEN(POINTER ioffsetHead,TRIEEXT *pNodeSeg,int (*pTravelOper)(TRIEEXT * ));
/*该程序和上面的程序相同，为提高效率写2个副本*/
POINTER *GetTrieLkE(POINTER ioffsetHead,TRIEEXT *pNodeSeg,char key[]);
/*警告ioffsetHead,pNodeSeg必须有效，否则coredump U*/

int SearchTrieE(POINTER ioffsetHead,TRIEEXT *pNodeSeg,char key[],POINTER *pioffsetCur);
int SearchTrieEBack(POINTER ioffsetHead,TRIEEXT *pNodeSeg,char key[],POINTER *pioffsetCur);
#endif 
