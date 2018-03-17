
#ifndef __BIN_TREE__
#define __BIN_TREE__

#include "datatype.h"
#include "wwshm.h"
#include "list.h"

#ifndef HIGHER
#define HIGHER 1 
#endif
#ifndef LOWER
#define LOWER  -1
#endif
#ifndef EQUAL
#define EQUAL  0 
#endif

typedef struct __Bin_Tree__
{
	struct __Bin_Tree__ *pLeft;
	struct __Bin_Tree__ *pRight;
	void   *pData;
	int    diff;
}   BINTREE;
void LinkBin(BINTREE *ptHead,void (*link_node_v)(void **,void **));
void HandShakeBin(BINTREE *ptHead);
void AdjustBin(BINTREE **pptHead);
int4b InsertBin(BINTREE **pptHead, void *pValue, 
        int4b ( *pFunctionExt)(void *,void*), 
        void ( *pAssign)(void **,void *));
BINTREE * MallocBin();
int4b SearchBin(BINTREE *ptHead, void *pValue,
	int ( *pFunction)(void *,void *), void **pptCur);
int4b DestroyBin(BINTREE *ptHead);
int TravelBin(BINTREE *ptHead, int ( *pOperation)(void **));
int4b DeleteBinMin(BINTREE **pptHead, BINTREE **pptCur);
int4b DeleteBin(BINTREE **pptHead, void *p,
	int4b ( *pFunction)(void *,void *),BINTREE **pptCur);
void assign_insert_bintree(void **ppData,void *pData);

typedef struct __EBin_Tree__
{
	POINTER ioffNext;/*单位为char*/
	POINTER	ioffLeft;/*单位为char*/
	POINTER	ioffRight;/*单位为char*/
	POINTER	ioffData;
	int    diff;
}   EBINTREE;

/**
偏移到偏移OO
指针到指针PP
偏移到指针OP
**/

#define TEBINTREE(p)		((EBINTREE*)(p))
#define OPEBINTREE(s,o)		TEBINTREE((char*)(s)+(o))

#define OOEBINTREENEXT(s,o)	(OPEBINTREE(s,o)->ioffNext)
#define OOEBINTREELEFT(s,o)	(OPEBINTREE(s,o)->ioffLeft)
#define OOEBINTREERIGHT(s,o)	(OPEBINTREE(s,o)->ioffRight)

#define OPEBINTREENEXT(s,o)	OPEBINTREE(s,OOEBINTREENEXT(s,o))
#define OPEBINTREELEFT(s,o)	OPEBINTREE(s,OOEBINTREELEFT(s,o))
#define OPEBINTREERIGHT(s,o)	OPEBINTREE(s,OOEBINTREERIGHT(s,o))

#define PPEBINTREENEXT(s,p)	OPEBINTREE(s,TEBINTREE(p)->ioffNext) 
#define PPEBINTREELEFT(s,p)	OPEBINTREE(s,TEBINTREE(p)->ioffLeft) 
#define PPEBINTREERIGHT(s,p)	OPEBINTREE(s,TEBINTREE(p)->ioffRight)

POINTER MallocEBin(void *pNodeSeg,struct ShmCtrlStruct *ptHead);
void AdjustEBin(void *pNodeSeg,POINTER  *pioffHead);
int4b InsertEBin(void *pNodeSeg,POINTER *pioffsetHead,
	struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
	int4b ( *pFunction)(POINTER,POINTER), 
        void ( *pAssign)(POINTER *,POINTER/*数据偏移*/));
int4b SearchEBin(void *pNodeSeg,POINTER ioffsetHead,void *p,
	int ( *pFunction)(void *,POINTER),POINTER *pioffsetCur);
int TravelEBin(void *pNodeSeg,POINTER ioffsetHead,
	int ( *pOperation)(POINTER *));
int4b DeleteEBinMin(void *pNodeSeg,POINTER *pioffsetHead,
	POINTER *pioffsetCur);
int4b DeleteEBin(void *pNodeSeg,POINTER *pioffsetHead,void *p,
	int4b ( *pFunction)(void *,POINTER),POINTER *pioffsetCur);
int4b DestroyEBin(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl);

#define OPFBINTREE(s,o)		TEBINTREE(OPFLIST(s,o))

#define OOFBINTREENEXT(s,o)	(OPFBINTREE(s,o)->ioffNext)
#define OOFBINTREELEFT(s,o)	(OPFBINTREE(s,o)->ioffLeft)
#define OOFBINTREERIGHT(s,o)	(OPFBINTREE(s,o)->ioffRight)

#define OPFBINTREENEXT(s,o)	OPFBINTREE(s,OOFBINTREENEXT(s,o))
#define OPFBINTREELEFT(s,o)	OPFBINTREE(s,OOFBINTREELEFT(s,o))
#define OPFBINTREERIGHT(s,o)	OPFBINTREE(s,OOFBINTREERIGHT(s,o))

#define PPFBINTREENEXT(s,p)	OPFBINTREE(s,TEBINTREE(p)->ioffNext) 
#define PPFBINTREELEFT(s,p)	OPFBINTREE(s,TEBINTREE(p)->ioffLeft) 
#define PPFBINTREERIGHT(s,p)	OPFBINTREE(s,TEBINTREE(p)->ioffRight)

POINTER MallocFBin(void *pNodeSeg,struct ShmCtrlStruct *ptHead);
void AdjustFBin(void *pNodeSeg,POINTER  *pioffHead);
int4b InsertFBin(void *pNodeSeg,POINTER *pioffsetHead,
	struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
	int4b ( *pFunction)(POINTER,POINTER), 
        void ( *pAssign)(POINTER *,POINTER/*数据偏移*/));
int4b SearchFBin(void *pNodeSeg,POINTER ioffsetHead,void *p,
	int ( *pFunction)(void *,POINTER),POINTER *pioffsetCur);
int TravelFBin(void *pNodeSeg,POINTER ioffsetHead,
	int ( *pOperation)(POINTER *));
int4b DeleteFBinMin(void *pNodeSeg,POINTER *pioffsetHead,
	POINTER *pioffsetCur);
int4b DeleteFBin(void *pNodeSeg,POINTER *pioffsetHead,void *p,
	int4b ( *pFunction)(void *,POINTER),POINTER *pioffsetCur);
int4b DestroyFBin(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl);

#endif

