#ifndef __SERV_INTF_H__
#define __SERV_INTF_H__
struct ShmServHead 
{
	int	iShmKey;
	POINTER	iBlockLen;
	POINTER	iTotalLen;
	struct	ShmCtrlStruct	TrieNode; /*索引节点个数*/
	struct	ShmCtrlStruct	TrieData; /*索引数据个数*/
	POINTER	ioffTrie;		  /*指向TRIE指针*/
};
/*单个结构申明*/
struct ISimpleServStruct{

	POINTER iOffNext;
	char    sMsisdn[16];		/* 用户号码 */
	char    sImsi[16];		
	char    sState[4];		/* 出帐状态 */
	char    sBillingTypeID[11];
	char    sReserve[16];		/* 系统保留 */
	char    sCreatedDate[15];	/* 创建时间 */
};
#define SIMPLE_SERV_KEY	0x4000c
#define SIMPLE_SERV_KEYI	0x4100c
#define OPSERV(x) OPFLIST(&SERV,x)

int GetBillingTypeID(char sMsisdn[],char sBillingTypeID[]);
void RegSimpleServExprFun();
#endif

