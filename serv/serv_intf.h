#ifndef __SERV_INTF_H__
#define __SERV_INTF_H__
struct ShmServHead 
{
	int	iShmKey;
	POINTER	iBlockLen;
	POINTER	iTotalLen;
	struct	ShmCtrlStruct	TrieNode; /*�����ڵ����*/
	struct	ShmCtrlStruct	TrieData; /*�������ݸ���*/
	POINTER	ioffTrie;		  /*ָ��TRIEָ��*/
};
/*�����ṹ����*/
struct ISimpleServStruct{

	POINTER iOffNext;
	char    sMsisdn[16];		/* �û����� */
	char    sImsi[16];		
	char    sState[4];		/* ����״̬ */
	char    sBillingTypeID[11];
	char    sReserve[16];		/* ϵͳ���� */
	char    sCreatedDate[15];	/* ����ʱ�� */
};
#define SIMPLE_SERV_KEY	0x4000c
#define SIMPLE_SERV_KEYI	0x4100c
#define OPSERV(x) OPFLIST(&SERV,x)

int GetBillingTypeID(char sMsisdn[],char sBillingTypeID[]);
void RegSimpleServExprFun();
#endif

