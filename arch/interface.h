
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
			��ʼ��ʱ�������
	 *******************************************************/
#define NOEXIST_ACCT_ITEM_TYPE	0x00001
#define NOEXIST_SERV		0x00002	 
#define NOEXIST_SERV_ACCT	0x00004	 
#define NOEXIST_ACCT		0x00008	 
#define NOEXIST_CUST		0x00010	 
#define NOEXIST_SUBSCRIBER	0x00020	 
#define NOEXIST_SERV_PRODUCT	0x00040	 

	/********************************************************/
	/*		 ���干���ڴ��ź�����Key		*/
	/*							*/
	/********************************************************/
#define SERVSEMKEY ((key_t) 0x40000) /* ���ɻ�ȡ���ź������Ĺؼ��� */
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

#define DELETE_RECORD	'D'	/*Ҫɾ���ļ�¼*/
#define STORE_RECORD	'S'	/*�������ڵļ�¼*/

	/********************************************************/
	/*		SERV��֧�ֲ���				*/
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

	POINTER ioffsetSAS[4]; 	/*��������ָ��*/
	int	NextOffset;	/*��һ���������ݵ�ƫ��*/	
	int	iTServCatgID;	/*�����û�Ⱥ��ʶ*/
	int	iAServCatgID;	/*�ʵ��û�Ⱥ��ʶ*/
	
	char	cDeleteFlag;	/*ɾ����ʶ*/
		
};
/* ʵ�ʴ���ڹ����ڴ��е�Head */
struct ShmServHead{
	
	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*�ڵ��������ͷָ��*/
	POINTER ioffsetFreeData;	/*��¼��������ָ��*/
	
	POINTER ioffsetCurData;		/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	POINTER ioffsetNewData;		/*��¼���������ݵĹ������������*/
	
	POINTER ioffsetCurNode;		/*��¼��ǰ�������Ѿ��洢����������*/
	
	int	iCurDataCnt;		/*��ǰ���ݼ�¼��*/
	int	iCurNodeCnt;		/*��ǰ������¼��*/
	
	int	iDataBufLen;		/*�ܼ�¼����*/
	int	iNodeBufLen;		/*�������ڵ����*/
	
	int	iLockGrpID;		/*�ڴ�����ʶ*/
	
	struct  IServStruct *pData;	/*���ݶε�ַ*/
	TRIEEXT *pNode;			/*�����ڵ�ָ��*/
	struct  ShmServHead *pHead;  	/*����ͷ��ַ*/
		
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
 *            SERV�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/
/*��λ�����ڴ浽�ֲ�������SERV�ṹ��    */
/*�����������SERV�ṹ�е���Ϣ����ʼ��  */
/*����ֵ��0���� -1 ������               */

int InitShmServ();
/*�뿪SERV��Ĺ����ڴ�*/
int DetachShmServ();

int SearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	struct IServStruct **pptCur);
int SearchImsiInServ(char sImsi[],char sStartTime[15],
	struct IServStruct **pptCur);

int SearchServIDInServ(char sServID[],
        int iServSeqNbr,struct IServStruct **pptCur);

/************************************************************
 *            SERV�ṩ�ⲿ���õ�API����                     *
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
 *            SERV�ṩ�ⲿ���õ�API����                     *
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
	/*		ACCT��֧�ֲ���				*/
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
	
	POINTER ioffsetSAS[1]; 	 /*��������ָ��*/
	int	NextOffset;	 /*��һ���������ݵ�ƫ��*/
	char	cDeleteFlag;	/*ɾ����ʶ*/
	
};	
/* ʵ�ʴ���ڹ����ڴ��е�Head */
struct ShmAcctHead{

	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*�ڵ��������ͷָ��*/
	POINTER ioffsetFreeData;	/*��¼��������ָ��*/
	
	POINTER ioffsetCurData;		/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	POINTER ioffsetNewData;		/*��¼���������ݵĹ������������*/
	
	POINTER ioffsetCurNode;		/*��¼��ǰ�������Ѿ��洢����������*/
	
	int	iCurDataCnt;		/*��ǰ���ݼ�¼��*/
	int	iCurNodeCnt;		/*��ǰ������¼��*/
	
	int	iDataBufLen;		/*�ܼ�¼����*/
	int	iNodeBufLen;		/*�������ڵ����*/
	
	int	iLockGrpID;		/*�ڴ�����ʶ*/
	
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
 *            ACCT�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/
/*��λ�����ڴ浽�ֲ�������SERV�ṹ��    */
/*�����������SERV�ṹ�е���Ϣ����ʼ��  */
/*����ֵ��0���� -1 ������               */
int InitShmAcct();
/*�뿪SERV��Ĺ����ڴ�*/
int DetachShmAcct();
int SearchAcctIDInAcct(char sAcctID[],struct IAcctStruct **pptCur);

/************************************************************
 *            ACCT�ṩ�ⲿ���õ�API����                     *
 *                                                          *
 ************************************************************/
int IInitShmAcct();
/*�뿪SERV��Ĺ����ڴ�*/
int IDetachShmAcct();
int ISearchAcctIDInAcct(char sAcctID[],struct IAcctStruct **pptCur);


extern struct ShmAcctHead ACCT;

	/********************************************************/
	/*		SERVACCT��֧�ֲ���			*/
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
	
	POINTER ioffsetSAS[1]; 	 /*��������ָ��*/
	int	NextOffset;	 /*��һ���������ݵ�ƫ��*/
	char	cDeleteFlag;	/*ɾ����ʶ*/
	
};	
/* ʵ�ʴ���ڹ����ڴ��е�Head */
struct ShmServAcctHead{

	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*�ڵ��������ͷָ��*/
	POINTER ioffsetFreeData;	/*��¼��������ָ��*/
	
	POINTER ioffsetCurData;		/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	POINTER ioffsetNewData;		/*��¼���������ݵĹ������������*/
	
	POINTER ioffsetCurNode;		/*��¼��ǰ�������Ѿ��洢����������*/
	
	int	iCurDataCnt;		/*��ǰ���ݼ�¼��*/
	int	iCurNodeCnt;		/*��ǰ������¼��*/
	
	int	iDataBufLen;		/*�ܼ�¼����*/
	int	iNodeBufLen;		/*�������ڵ����*/
	
	int	iLockGrpID;		/*�ڴ�����ʶ*/
	
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
 *            SERVACCT�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/
/*��λ�����ڴ浽�ֲ�������SERV�ṹ��    */
/*�����������SERV�ṹ�е���Ϣ����ʼ��  */
/*����ֵ��0���� -1 ������               */
int InitShmServAcct();
/*�뿪SERV��Ĺ����ڴ�*/
int DetachShmServAcct();

int SearchServIDInServAcct(char sServID[],
                int iServSeqNbr,struct IServAcctStruct **pptCur);

/************************************************************
 *            SERVACCT�ṩ�ⲿ���õ�API����		    *
 *                                                          *
 ************************************************************/
/*��λ�����ڴ浽�ֲ�������SERV�ṹ��    */
/*�����������SERV�ṹ�е���Ϣ����ʼ��  */
/*����ֵ��0���� -1 ������               */
int IInitShmServAcct();
/*�뿪SERV��Ĺ����ڴ�*/
int IDetachShmServAcct();

int ISearchServIDInServAcct(char sServID[],
                int iServSeqNbr,struct IServAcctStruct **pptCur);


extern struct ShmServAcctHead SERVACCT;


	/********************************************************/
	/*		SERVPRODUCT��֧�ֲ���			*/
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
	
	POINTER ioffsetSAS[1]; 	 /*��������ָ��*/
	int	NextOffset;	 /*��һ���������ݵ�ƫ��*/
	char	cDeleteFlag;	/*ɾ����ʶ*/
	
};	
/* ʵ�ʴ���ڹ����ڴ��е�Head */
struct ShmServProductHead{

	int	iShmID;
	POINTER	iTotalLen;
	char	sUpdateTime[15];
	
	POINTER ioffsetFreeNode;	/*�ڵ��������ͷָ��*/
	POINTER ioffsetFreeData;	/*��¼��������ָ��*/
	
	POINTER ioffsetCurData;		/*��¼��ǰ�������Ѿ��洢���ݵ�����*/
	POINTER ioffsetNewData;		/*��¼���������ݵĹ������������*/
	
	POINTER ioffsetCurNode;		/*��¼��ǰ�������Ѿ��洢����������*/
	
	int	iCurDataCnt;		/*��ǰ���ݼ�¼��*/
	int	iCurNodeCnt;		/*��ǰ������¼��*/
	
	int	iDataBufLen;		/*�ܼ�¼����*/
	int	iNodeBufLen;		/*�������ڵ����*/
	
	int	iLockGrpID;		/*�ڴ�����ʶ*/
	
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
 *            SERVPRODUCT�ṩ�ڲ����õ�API����                     *
 *                                                          *
 ************************************************************/
/*��λ�����ڴ浽�ֲ�������SERV�ṹ��    */
/*�����������SERV�ṹ�е���Ϣ����ʼ��  */
/*����ֵ��0���� -1 ������               */
int InitShmServProduct();
/*�뿪SERV��Ĺ����ڴ�*/
int DetachShmServProduct();

int SearchServIDInServProduct(char sServID[],struct IServProductStruct **pptCur);         

/************************************************************
 *            SERVPRODUCT�ṩ�ⲿ���õ�API����		    *
 *                                                          *
 ************************************************************/
/*��λ�����ڴ浽�ֲ�������SERV�ṹ��    */
/*�����������SERV�ṹ�е���Ϣ����ʼ��  */
/*����ֵ��0���� -1 ������               */
int IInitShmServProduct();
/*�뿪SERV��Ĺ����ڴ�*/
int IDetachShmServProduct();

int ISearchServIDInServProduct(char sServID[],struct IServProductStruct **pptCur);
	
extern struct ShmServProductHead SERVPRODUCT;






/****************************************************************
*	��ȫ�ⲿAPI����Ҫ���Ĺ����ڴ���Ч��COREDUMP		*
*	ǿ�ҽ���ʹ�øýӿ�					*
*	�ýӿڲ�Ҫ�������ӿڻ���				*
*	�Ҳ�Ҫֱ�����ӹ����ڴ�					*
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

/**SERV��*/
int CheckShmServAccess();
int USearchAccNbrInServ(char sAccNbr[],char sStartTime[15],
	int (*getdata_fun)(void *p,void *pHead),void *p);
int MSearchAccNbrInServ(char sAccNbr[],
	int (*getdata_fun)(void *p,void *pHead),void *p);
int USearchServIDInServ(char sServID[],int iServSeqNbr,
	int (*getdata_fun)(void *p,void *pHead),void *p);
/*��Ψһ���ң�ȡ��һϵ�е���ֵ*/
int MSearchDefaultAcctIDInServ(char sDefaultAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p);

/**ACCT��*/
int CheckShmAcctAccess();
int USearchAcctIDInAcct(char sAcctID[],
	int (*getdata_fun)(void *p,void *pHead),void *p);
	
	
/**SERVACCT��*/
int CheckShmServAcctAccess();
int MSearchServIDInServAcct(char sServID[],int iServSeqNbr,
	int (*getdata_fun)(void *p,void *pHead),void *p);
	
/**SERVPRODUCT��*/
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
