
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <trie.h>

#define SHM_NODE_FULL -2
#define SHM_DATA_FULL -3
#define SHM_IS_FULL 	-1

#ifndef TRUE
#define TRUE  1
#define FALSE 0
#define FOUND 1
#define NOTFOUND 0
#endif


	/********************************************************
			初始化时错误代码
	 *******************************************************/
#define NOEXIST_ACCT_ITEM_TYPE	0x00001
#define NOEXIST_SERV		0x00002	 
#define NOEXIST_SERV_ACCT	0x00004	 
#define NOEXIST_ACCT		0x00008	 
#define NOEXIST_CUST		0x00010	 
#define NOEXIST_SUBSCRIBER	0x00020	 
#define NOEXIST_SERV_PRODUCT	0x00040	 

	/********************************************************/
	/*		 定义共享内存信号量的Key		*/
	/*							*/
	/********************************************************/
#define SERVSEMKEY ((key_t) 0x40000) /* 生成或取得信号量集的关键字 */
#define ACCTSEMKEY ((key_t) 0x40001)
#define SERVACCTSEMKEY ((key_t) 0x40003)
#define SERVPRODUCTSEMKEY ((key_t) 0x40004)
	
	
#define SERVDATAKEY 	0x40001
#define SERVNODEKEY 	0x40002

#define ACCTDATAKEY 	0x40003
#define ACCTNODEKEY 	0x40004

#define SERVACCTDATAKEY 	0x40007
#define SERVACCTNODEKEY 	0x40008

#define SERVPRODUCTDATAKEY 	0x40009
#define SERVPRODUCTNODEKEY 	0x4000a



#define SERV__ACC_NBR    	0
#define SERV__SERV_ID    	1 
#define SERV__IMSI		2 
#define SERV__ACCT_ID		3 

#define ACCT__ACCT_ID    	0

#define SERV_ACCT__SERV_ID   	0

#define SERV_PRODUCT__SERV_ID 	0


#define DATA_LOST	-1
#define NODE_LOST	-2

#define DELETE_RECORD	'D'	/*要删除的记录*/
#define STORE_RECORD	'S'	/*继续存在的记录*/

	/********************************************************/
	/*		SERV表支持部分				*/
	/*							*/
	/********************************************************/
	
struct IServStruct{
	
	char    sServID[11];
	int     iServSeqNbr;
	int     iBillingTypeID;
	int     iServTypeID;
	int     iAreaID;
	char    sAccNbrStateID[4];
	int     iStopTypeID;
	int     iCycleTypeID;
	int     iCentrexID;
	int     iInNetType;
	char    sAccNbr[21];
	char    sImsi[21];
	char    sDefaultAcctID[11];
	int	iQuota;			
	int     iSiteID;	
	char    sCompletedDate[15];	
	char    sCreatedDate[15];	
	int     iCreditGrade;		
		
	char    sState[4];
	char    sStateDate[15];		
	int	iVipFlag;

	POINTER ioffsetSAS[4]; 	/*索引控制指针*/
	int	NextOffset;	/*下一个空闲数据的偏移*/	
	int	iTServCatgID;	/*话单用户群标识*/
	int	iAServCatgID;	/*帐单用户群标识*/
	
	char	cDeleteFlag;	/*删除标识*/
		
};
/* 实际存放在共享内存中的Head */
struct ShmServHead{
	
	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*节点空闲链表头指针*/
	POINTER ioffsetFreeData;	/*记录空闲数据指针*/
	
	POINTER ioffsetCurData;		/*记录当前共享中已经存储数据的链表*/
	POINTER ioffsetNewData;		/*记录新增加数据的共享的数据链表*/
	
	POINTER ioffsetCurNode;		/*记录当前共享中已经存储索引的链表*/
	
	int	iCurDataCnt;		/*当前数据记录数*/
	int	iCurNodeCnt;		/*当前索引记录数*/
	
	int	iDataBufLen;		/*总记录个数*/
	int	iNodeBufLen;		/*总索引节点个数*/
	
	int	iLockGrpID;		/*内存锁标识*/
	
	struct  IServStruct *pData;	/*数据段地址*/
	TRIEEXT *pNode;			/*索引节点指针*/
	struct  ShmServHead *pHead;  	/*控制头地址*/
		
	POINTER ioffsetAccNbr;
	POINTER ioffsetServID; 
	POINTER ioffsetImsi;
	POINTER ioffsetAcctID;

};

#define OFFSETSERV(x)	(x-SERV.pData)	
#define SERVTRIEEXT(x)	(SERV.pData+x)
#define SERVTRIENODE(x)	(SERV.pNode+x)

#define NEXT_SERV__SERVID(x) 	(SERV.pData[x].ioffsetSAS[SERV__SERV_ID])
#define NEXT_SERV__IMSI(x)	(SERV.pData[x].ioffsetSAS[SERV__IMSI])
#define NEXT_SERV__ACCNBR(x)	(SERV.pData[x].ioffsetSAS[SERV__ACC_NBR])
#define NEXT_SERV__ACCTID(x)	(SERV.pData[x].ioffsetSAS[SERV__ACCT_ID])

/************************************************************
 *            SERV提供内部引用的API函数                     *
 *                                                          *
 ************************************************************/
/*定位共享内存到局部变量的SERV结构中    */
/*如果不完整则SERV结构中的信息被初始化  */
/*返回值：0完整 -1 不完整               */

int InitShmServ();
/*离开SERV表的共享内存*/
int DetachShmServ();

int SearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	struct IServStruct **pptCur);
int SearchImsiInServ(char sImsi[],char sStartTime[15],
	struct IServStruct **pptCur);

int SearchServIDInServ(char sServID[],
        int iServSeqNbr,struct IServStruct **pptCur);

/************************************************************
 *            SERV提供外部引用的API函数                     *
 *                                                          *
 ************************************************************/
int IInitShmServ();
int IDetachShmServ();

int ISearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	struct IServStruct **pptCur);
int ISearchImsiInServ(char sImsi[],struct IServStruct **pptCur);

int ISearchServIDInServ(char sServID[],
                int iServSeqNbr,struct IServStruct **pptCur);

extern struct ShmServHead SERV;




	/********************************************************/
/************************************************************
 *            SERV提供外部引用的API函数                     *
 *                                                          *
 ************************************************************/
int IInitShmServ();
int IDetachShmServ();

int ISearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	struct IServStruct **pptCur);
int ISearchImsiInServ(char sImsi[],struct IServStruct **pptCur);

int ISearchServIDInServ(char sServID[],
                int iServSeqNbr,struct IServStruct **pptCur);

extern struct ShmServHead SERV;




	/********************************************************/
	/*		ACCT表支持部分				*/
	/*							*/
	/********************************************************/
struct IAcctStruct{

	char    sAcctID[11];
	int     iAcctSeqNbr;
	int     iBranchID;
	char    sPaymentMethod[4];
	char    sAcctNbr[31];
	char    sBankAcct[31];
	int	iQuota;
	int     iCreditGrade;
	int	iBalance;
	int	iChange;
	char    sCreatedDate[15];
	char    sState[4];
	char    sStateDate[15];
	
	POINTER ioffsetSAS[1]; 	 /*索引控制指针*/
	int	NextOffset;	 /*下一个空闲数据的偏移*/
	char	cDeleteFlag;	/*删除标识*/
	
};	
/* 实际存放在共享内存中的Head */
struct ShmAcctHead{

	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*节点空闲链表头指针*/
	POINTER ioffsetFreeData;	/*记录空闲数据指针*/
	
	POINTER ioffsetCurData;		/*记录当前共享中已经存储数据的链表*/
	POINTER ioffsetNewData;		/*记录新增加数据的共享的数据链表*/
	
	POINTER ioffsetCurNode;		/*记录当前共享中已经存储索引的链表*/
	
	int	iCurDataCnt;		/*当前数据记录数*/
	int	iCurNodeCnt;		/*当前索引记录数*/
	
	int	iDataBufLen;		/*总记录个数*/
	int	iNodeBufLen;		/*总索引节点个数*/
	
	int	iLockGrpID;		/*内存锁标识*/
	
	struct IAcctStruct *pData;
	TRIEEXT *pNode;
	struct ShmAcctHead *pHead;

	POINTER ioffsetAcctID; 
};

#define OFFSETACCT(x)	(x-ACCT.pData)
#define ACCTTRIEEXT(x)	(ACCT.pData+x)
#define ACCTTRIENODE(x) (ACCT.pNode+x)
#define NEXT_ACCT__ACCTID(x) 	(ACCT.pData[x].ioffsetSAS[ACCT__ACCT_ID])


/************************************************************
 *            ACCT提供内部引用的API函数                     *
 *                                                          *
 ************************************************************/
/*定位共享内存到局部变量的SERV结构中    */
/*如果不完整则SERV结构中的信息被初始化  */
/*返回值：0完整 -1 不完整               */
int InitShmAcct();
/*离开SERV表的共享内存*/
int DetachShmAcct();
int SearchAcctIDInAcct(char sAcctID[],struct IAcctStruct **pptCur);

/************************************************************
 *            ACCT提供外部引用的API函数                     *
 *                                                          *
 ************************************************************/
int IInitShmAcct();
/*离开SERV表的共享内存*/
int IDetachShmAcct();
int ISearchAcctIDInAcct(char sAcctID[],struct IAcctStruct **pptCur);


extern struct ShmAcctHead ACCT;

	/********************************************************/
	/*		SERVACCT表支持部分			*/
	/*							*/
	/********************************************************/
struct IServAcctStruct{

	char    sAcctID[11];
	int     iAcctSeqNbr;
	int     iAcctItemTypeID;
	char    sServID[11];
	int     iServSeqNbr;
	char    sState[4];
	char    sStateDate[15];
	
	POINTER ioffsetSAS[1]; 	 /*索引控制指针*/
	int	NextOffset;	 /*下一个空闲数据的偏移*/
	char	cDeleteFlag;	/*删除标识*/
	
};	
/* 实际存放在共享内存中的Head */
struct ShmServAcctHead{

	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*节点空闲链表头指针*/
	POINTER ioffsetFreeData;	/*记录空闲数据指针*/
	
	POINTER ioffsetCurData;		/*记录当前共享中已经存储数据的链表*/
	POINTER ioffsetNewData;		/*记录新增加数据的共享的数据链表*/
	
	POINTER ioffsetCurNode;		/*记录当前共享中已经存储索引的链表*/
	
	int	iCurDataCnt;		/*当前数据记录数*/
	int	iCurNodeCnt;		/*当前索引记录数*/
	
	int	iDataBufLen;		/*总记录个数*/
	int	iNodeBufLen;		/*总索引节点个数*/
	
	int	iLockGrpID;		/*内存锁标识*/
	
        struct IServAcctStruct *pData;
        TRIEEXT *pNode;
        struct ShmServAcctHead *pHead;
        
        POINTER ioffsetServID; 
};
#define OFFSETSERVACCT(x)	(x-SERVACCT.pData)
#define SERVACCTTRIEEXT(x)	(SERVACCT.pData+x)
#define SERVACCTTRIENODE(x)	(SERVACCT.pNode+x)
#define NEXT_SERVACCT__SERVID(x) 	(SERVACCT.pData[x].ioffsetSAS[SERV_ACCT__SERV_ID])


/************************************************************
 *            SERVACCT提供内部引用的API函数                     *
 *                                                          *
 ************************************************************/
/*定位共享内存到局部变量的SERV结构中    */
/*如果不完整则SERV结构中的信息被初始化  */
/*返回值：0完整 -1 不完整               */
int InitShmServAcct();
/*离开SERV表的共享内存*/
int DetachShmServAcct();

int SearchServIDInServAcct(char sServID[],
                int iServSeqNbr,struct IServAcctStruct **pptCur);

/************************************************************
 *            SERVACCT提供外部引用的API函数		    *
 *                                                          *
 ************************************************************/
/*定位共享内存到局部变量的SERV结构中    */
/*如果不完整则SERV结构中的信息被初始化  */
/*返回值：0完整 -1 不完整               */
int IInitShmServAcct();
/*离开SERV表的共享内存*/
int IDetachShmServAcct();

int ISearchServIDInServAcct(char sServID[],
                int iServSeqNbr,struct IServAcctStruct **pptCur);


extern struct ShmServAcctHead SERVACCT;


	/********************************************************/
	/*		SERVPRODUCT表支持部分			*/
	/*							*/
	/********************************************************/
struct IServProductStruct{

	int     iProductID;
	char    sServID[11];
	int     iServSeqNbr;
	int     iSeqNbr;
	int     iProductTypeID;
	int     iProductQuantity;
	char    sState[4];
	char    sStateDate[15];
	char    sExpDate[15];
	
	POINTER ioffsetSAS[1]; 	 /*索引控制指针*/
	int	NextOffset;	 /*下一个空闲数据的偏移*/
	char	cDeleteFlag;	/*删除标识*/
	
};	
/* 实际存放在共享内存中的Head */
struct ShmServProductHead{

	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*节点空闲链表头指针*/
	POINTER ioffsetFreeData;	/*记录空闲数据指针*/
	
	POINTER ioffsetCurData;		/*记录当前共享中已经存储数据的链表*/
	POINTER ioffsetNewData;		/*记录新增加数据的共享的数据链表*/
	
	POINTER ioffsetCurNode;		/*记录当前共享中已经存储索引的链表*/
	
	int	iCurDataCnt;		/*当前数据记录数*/
	int	iCurNodeCnt;		/*当前索引记录数*/
	
	int	iDataBufLen;		/*总记录个数*/
	int	iNodeBufLen;		/*总索引节点个数*/
	
	int	iLockGrpID;		/*内存锁标识*/
	
        struct IServProductStruct *pData;
        TRIEEXT *pNode;
        struct ShmServProductHead *pHead;
        
        POINTER ioffsetServID; 

};
#define OFFSETSERVPRODUCT(x)	(x-SERVPRODUCT.pData)
#define SERVPRODUCTTRIEEXT(x)	(SERVPRODUCT.pData+x)
#define SERVPRODUCTTRIENODE(x)  (SERVPRODUCT.pNode+x)
#define NEXT_SERVPRODUCT__SERVID(x) 	(SERVPRODUCT.pData[x].ioffsetSAS[SERV_PRODUCT__SERV_ID])


/************************************************************
 *            SERVPRODUCT提供内部引用的API函数                     *
 *                                                          *
 ************************************************************/
/*定位共享内存到局部变量的SERV结构中    */
/*如果不完整则SERV结构中的信息被初始化  */
/*返回值：0完整 -1 不完整               */
int InitShmServProduct();
/*离开SERV表的共享内存*/
int DetachShmServProduct();

int SearchServIDInServProduct(char sServID[],struct IServProductStruct **pptCur);         

/************************************************************
 *            SERVPRODUCT提供外部引用的API函数		    *
 *                                                          *
 ************************************************************/
/*定位共享内存到局部变量的SERV结构中    */
/*如果不完整则SERV结构中的信息被初始化  */
/*返回值：0完整 -1 不完整               */
int IInitShmServProduct();
/*离开SERV表的共享内存*/
int IDetachShmServProduct();

int ISearchServIDInServProduct(char sServID[],struct IServProductStruct **pptCur);
	
extern struct ShmServProductHead SERVPRODUCT;






/****************************************************************
*	安全外部API，不要担心共享内存无效的COREDUMP		*
*	强烈建议使用该接口					*
*	该接口不要与以往接口混用				*
*	且不要直接连接共享内存					*
****************************************************************/

#define SHM_ACCESS_FAIL		-1
#define MOVE_ITEM_SUCCESS	2
#define MOVE_ITEM_FAIL		-2
#define MUTI_ITEM_SUCCESS	-3
#ifndef FOUND			
#define FOUND			1
#endif
#ifndef NOTFOUND			
#define NOTFOUND		0
#endif

int ShmServHeadValid();
int ShmAcctHeadValid();
int ShmServAcctHeadValid();
int ShmServProductHeadValid();

/**SERV表*/
int CheckShmServAccess();
int USearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	int (*getdata_fun)(void *p,void *pHead),void *p);
int MSearchAccNbrInServ(char sAccNbr[],
	int (*getdata_fun)(void *p,void *pHead),void *p);
int USearchServIDInServ(char sServID[],int iServSeqNbr,
	int (*getdata_fun)(void *p,void *pHead),void *p);
/*非唯一查找，取出一系列的数值*/
int MSearchDefaultAcctIDInServ(char sDefaultAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p);

/**ACCT表*/
int CheckShmAcctAccess();
int USearchAcctIDInAcct(char sAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p);
	
	
/**SERVACCT表*/
int CheckShmServAcctAccess();
int MSearchServIDInServAcct(char sServID[],int iServSeqNbr,
	int (*getdata_fun)(void *p,void *pHead),void *p);
	
/**SERVPRODUCT表*/
int CheckShmServProductAccess();
int MSearchServIDInServProduct(char sServID[],char sStartTime[],
	int (*getdata_fun)(void *p,void *pHead),void *p);	
	


void InitAcctItemTypeAnti();
int GetPayAcctItemType(int iAcctItemTypeID);
int GetSaleAcctItemType(int iAcctItemTypeID);



int USearchAccNbr(char sAccNbr[],char sStartTime[15],int iAcctItemTypeID,
	int (*getdata_fun)(void *p,void *pHead),void *p,char sAcctID[]);

int USearchAcctID(char sAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p);
int USearchServID(char sServID[],int iServSeqNbr,
	int iAcctItemTypeID,char sAcctID[]);

int IInitInterface();
int IDetachInterface();

int USearchAccNbrUsingImsiInServ(char sImsi[15],char sStartTime[15],
	char sAccNbr[16]);
int USearchServIDE(char sServID[],int iServSeqNbr,int iAcctItemTypeID,
        char sAcctID[],char sAccNbr[]);
int SearchServIDInServE(char sServID[],char sStartTime[],
        struct IServStruct **pptCur);
int MESearchAcctIDInServ(char sAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p);

int USearchSeqNbrInServ(char sAccNbr[12],char sCycleBeginDate[15],
	char sCycleEndDate[15],int *piServSeqNbr);
int USearchServIDInServE(char sServID[],char sStartTime[],
	int (*getdata_fun)(void *p,void *pHead),void *p);
	
extern int giLockGrpID;


#endif
