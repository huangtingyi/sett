#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "serv.h"
#include "acct.h"
#include "servacct.h"
#include "servproduct.h"

#include <hnixs.h>
#include <wwdb.h>
#include <wwcoding.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <wwsem.h>
#include <interface.h>

/*****���ϸ���ͨ�ù��̼��غ���ָ��***/

int (*CheckShmEffect)();
void (*DestroyStatList)();
int (*MountingUpdatedToMem)();
int (*MountingTotalToMem)();
int (*BuildTemporaryPrimaryIndex)();
int (*DestroyTemporaryPrimaryIndex)();
int (*CountingCurDeleteRecord)();
int (*CountingIncrementRecord)();
int (*GetTotalBufRecord)();
int (*CountingIncrementNode)();
int (*GetTotalBufNode)();
int (*LockArchShm)();
void (*UnlockArchShm)();
void (*TruncateShmIndexAndRetriveNode)();
int (*RebuildShmCurIndexAndRetriveExpireRecord)();
int (*BuildMemListIndexAndMoveToShm)();
int (*SemWorking)();
int (*ClientUnmountNotify)();
int (*ClientConnectNotify)();
int (*CountingTotalRecord)();
int (*StatTotalNode)();
int (*InitControlRecord)();
void (*CopyControlToShm)();
int  (*DetachArchShm)();



void InitServSupportInterface();
void InitAcctSupportInterface();
void InitServAcctSupportInterface();
void InitServProductSupportInterface();

int giLockGrpID,giSemKey,giShmDataKey,giShmNodeKey;
int giRespondEvent,giDelayCounter,giAbort,giUpdateResult;
int giRebuildFlag;

extern int errno;


#define LOADSERV	1
#define LOADSERVACCT	2
#define LOADSERVPRODUCT 3
#define LOADACCT	4
#define INCREMENTUPDATE	1
#define WHOLEUPDATE	2


int Usage(int argc,char **argv)
{
	printf("Usage: %s [option]\n",argv[0]);
	printf("       -t|-T n    n �趨�Ķ�ʱʱ��.\n");
	printf("       -r|-R      ��������ڴ���ź���.\n");
	printf("       -l|-L      �������ϲ��� serv servacct servproduct acct.\n");
	printf("       -h|-H      ����.\n");          
	return 0;
}

int IncrementUpdateShmArch()
{
	int iNodeBufLen,iNodeNeed;
	time_t	tBeginLoadTime,tEndLoadTime,tBeginUpdateTime,tEndUpdateTime;

	time(&tBeginLoadTime);

	/**һ��ô��������ݿ��޷����ӣ��ʲ��˳�*/
	
	if(MountingUpdatedToMem()<0){
		WriteAlertMsg("���ظ������ϲ�������");
		return 0;
	}
	
	printf("���ظ������ϲ����ɹ�.\n");
	WriteProcMsg("���ظ������ϲ����ɹ�");
	
/*	if(BuildTemporaryPrimaryIndex()<0){
		pprintf(0,0,"Ϊ�������ؼ��ֽ����ڴ�����ʧ��.\n");
		return -1;
	}
*/	
/*	if((iTempCnt=CountingCurDeleteRecord())<0){
		pprintf(0,0,"Ϊ�����ڴ�����ͳ�Ʋ�ɾ����¼ʧ��.\n");
		return -1;
	}
*/
	/**ֻҪ����쳣Ȼ��ȴ�ˢ�¹���*/
	iNodeBufLen=GetTotalBufRecord();	
	iNodeNeed=CountingIncrementRecord();
	
	if(iNodeBufLen<iNodeNeed){
		giRebuildFlag=WHOLEUPDATE;
		return 0;
	}
	printf("ͳ����Ҫ�����ڵ���%d,���������С%d.\n",iNodeNeed,iNodeBufLen);
	WriteProcMsg("ͳ����Ҫ�����ڵ���%d,���������С%d",
		iNodeNeed,iNodeBufLen);
	
	if(GetTotalBufNode()<CountingIncrementNode()){
		giRebuildFlag=WHOLEUPDATE;
		return 0;
	}
	
	time(&tEndLoadTime);
	
	LockArchShm();

	pprintf(0,0,"�����ڴ����.........................���̲����˳�.\n");
	
	if(ClientUnmountNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS����û����Ӧ�ó���(increase)");
		WriteAlertMsg("�����ڴ����(����ʧ��)...........���̿��˳�.");
		return -1;
	}
	
	time(&tBeginUpdateTime);

	pprintf(0,0,"֪ͨ����Ӧ�ó��������û��������ӳɹ�.\n");
	
	TruncateShmIndexAndRetriveNode();
	pprintf(0,0,"ɾ�������ڴ�ԭ�������ڵ�ɹ�.\n");
	
	if(RebuildShmCurIndexAndRetriveExpireRecord()<0){
		UnlockArchShm();
		WriteAlertMsg("ΪĿǰ�����ڴ潨��������ɾ�����ڼ�¼����");
		WriteAlertMsg("�����ڴ����(����ʧ��)...........���̿��˳�");
		return -1;
	}
	pprintf(0,0,"ΪĿǰ�����ڴ潨��������ɾ�����ڼ�¼�ɹ�.\n");
	
	if(BuildMemListIndexAndMoveToShm()<0){
		UnlockArchShm();
		WriteAlertMsg("Ϊ������������������-���ƶ��������ڴ�ʧ��");
		WriteAlertMsg("�����ڴ����(����ʧ��)...........���̿��˳�");
		return -1;
	}

	DestroyStatList();
	
	CopyControlToShm();
	

	if(ClientConnectNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS����û����������(increase)");
		WriteAlertMsg("�����ڴ����(����ʧ��)...........���̿��˳�");
		return -1;
	}
	
	pprintf(0,0,"֪ͨ����Ӧ�ó��������û��������ӳɹ�.\n");
	UnlockArchShm();
	pprintf(0,0,"�����ڴ����(���³ɹ�)...........���̿��˳�.\n");

	time(&tEndUpdateTime);

	pprintf(0,0,"���������������,������%d��,������%d��,����%d��.\n",
		tEndLoadTime-tBeginLoadTime,
		tEndUpdateTime-tBeginUpdateTime,
		tEndUpdateTime-tBeginLoadTime);

	return 0;
}

int WholeUpdateShmArch()
{
	time_t	tBeginLoadTime,tEndLoadTime,tBeginUpdateTime,tEndUpdateTime;

	time(&tBeginLoadTime);

	if(SemWorking()==FALSE){
		
		if((giLockGrpID=CreateSemX(giSemKey,1))<0){
			/**��ȡ�ڴ���ʧ��*/
			WriteAlertMsg("��ȡ�����ڴ���ʧ��");
			return -1;
		}
		
		giRebuildFlag=WHOLEUPDATE;
		return 0;
	}
	
	if(MountingTotalToMem()<0){
		WriteAlertMsg("��ȫ�������ϲ�������");
		return 0;
	}

	time(&tEndLoadTime);
	
	LockArchShm();
	pprintf(0,0,"�����ڴ����.........................���̲����˳�.\n");
	
	if(ClientUnmountNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS����û����Ӧ�ó���");
		return -1;
	}

	time(&tBeginUpdateTime);
	
	pprintf(0,0,"֪ͨ����Ӧ�ó��������û��������ӳɹ�.\n");
	
	if(StatTotalNode()<0){
		UnlockArchShm();
		WriteAlertMsg("����������¼ͳ�ƴ���");
		WriteAlertMsg("�����ڴ����(����ʧ��)........�����˳�");
		return -1;
	}
	pprintf(0,0,"��������������¼ͳ�Ƴɹ�.\n");
	
/*	
	��ͳ�ƿ��Բ�Ҫ����Ϊ�ڼ���MOUNTING��ʱ���Ѿ���
	���ݼ�¼������STAT_ARCHȫ�ֽṹ����
	if(CountingTotalRecord()<0){
		pprintf(0,0,"�������ݼ�¼ͳ�ƴ���.\n");
		UnlockArchShm();
		pprintf(0,0,"�����ڴ����(����ʧ��)........�����˳�.");
		return -1;
	}
	
*/
	if(InitControlRecord()<0){
		UnlockArchShm();
		WriteAlertMsg("���乲���ڴ����");
		WriteAlertMsg("�����ڴ����(����ʧ��)........�����˳�");
		return -1;
	}
	
	pprintf(0,0,"���䲢��ʼ�������ڴ�ɹ�.\n");
	
	if(BuildMemListIndexAndMoveToShm()<0){
		UnlockArchShm();
		WriteAlertMsg("Ϊ������������������-���ƶ��������ڴ�ʧ��");
		WriteAlertMsg("�����ڴ����(����ʧ��)........�����˳�");
		return -1;
	}

	DestroyStatList();
	
	pprintf(0,0,"Ϊ������������������-���ƶ��������ڴ�ɹ�.\n");
	
	CopyControlToShm();
	
	if(ClientConnectNotify()<0){
		UnlockArchShm();
		WriteAlertMsg("CMS����û����������");
		WriteAlertMsg("�����ڴ����(����ʧ��)........�����˳�");
		return -1;
	}
	
	pprintf(0,0,"֪ͨ����Ӧ�ó��������û��������ӳɹ�.\n");
	
	UnlockArchShm();
	pprintf(0,0,"�����ڴ����(����ɹ�)........�����˳�.\n");

	time(&tEndUpdateTime);

	pprintf(0,0,"������ȫ�������,������%d��,������%d��,����%d��.\n",
		tEndLoadTime-tBeginLoadTime,
		tEndUpdateTime-tBeginUpdateTime,
		tEndUpdateTime-tBeginLoadTime);
	
	return 0;
	
}

int main(int argc ,char *argv[])
{
	int iLoadType,iSemID;
        char   sTarget[2048]; 
        time_t	tPreTime,tCurTime;
	
	giRebuildFlag = FALSE;
	
	
	if(ExistOtherOption(argc,argv,"bBrRlLHh?")==TRUE||
		ExistOption(argc,argv,"Hh?")==TRUE){
		Usage(argc, argv);
		return 0;	
	}
	
	if(ExistOption(argc,argv,"rR")==TRUE)	giRebuildFlag = WHOLEUPDATE;
	
	SearchOptionStr(argc,argv,"lL",sTarget);

	printf(">Ӧ�ó�������\n");
	ConnectArchDB();
	
	if(strcmp(sTarget,"serv")==0)
		iLoadType=LOADSERV;
	else if(strcmp(sTarget,"servacct")==0)
		iLoadType=LOADSERVACCT;
	else if (strcmp(sTarget,"servproduct")==0)
		iLoadType=LOADSERVPRODUCT;
	else if (strcmp(sTarget,"acct")==0)
		iLoadType=LOADACCT;
	else {
		pprintf(0,0,"����ѡ��L��l�����Ϊ serv servacct servproduct��acct.\n");
		/*������*/
		return 0;
	}
	
	switch ( iLoadType ) {
	
	case LOADSERV:
		InitServSupportInterface();
	break;
		
	case LOADSERVACCT:
		InitServAcctSupportInterface();
	break;
	
	case LOADSERVPRODUCT:
		InitServProductSupportInterface();
	break;
	
	case LOADACCT:
		InitAcctSupportInterface();
	break;
	
	}

	giAbort = FALSE;
	
	while(1){
		

		giRespondEvent=FALSE;
		
		if(CheckShmEffect()!=TRUE||SemWorking()!=TRUE||
			giRebuildFlag==WHOLEUPDATE){
			
			giRebuildFlag = FALSE;	
			FreeShm(giShmDataKey);
			FreeShm(giShmNodeKey);
			if((iSemID=semget(giSemKey,0,0x400|IPC_CREAT|IPC_EXCL))>=0)
				semctl(iSemID,0,IPC_RMID);
				
			giUpdateResult=WholeUpdateShmArch();
		}
		else{
			giRebuildFlag = FALSE;
			giUpdateResult=IncrementUpdateShmArch();
		}

		
		giRespondEvent=TRUE;
		
		/*�ӳ�һСʱ*/
		giDelayCounter=0;
		
		time(&tPreTime);
		while(giAbort==FALSE){
			
			time(&tCurTime);
			if((tCurTime-tPreTime)>3600||giUpdateResult<0||
				giRebuildFlag!=FALSE) break;
			
			sleep(60);
			
			giDelayCounter++;
		}

#ifdef QHJF
		if(DetachArchShm()<0){
			WriteAlertMsg("���빲���ڴ�ʧ��x,�����˳�");
			exit(1);
		}
#endif
		
		if(giAbort==TRUE||giUpdateResult<0) break;
		
			
	}
	
	if(giUpdateResult<0){
		WriteAlertMsg("ˢ�¹����ڴ���󣬳����˳�");
	}
	else{
		WriteAlertMsg("���յ��˳���������˳�");
	}
		/*������*/
	return 0;
} 

int OnIncrementUpdateArch()
{
	
	if(giRespondEvent==TRUE)		
		giRebuildFlag=INCREMENTUPDATE;
	else
		WriteAlertMsg("���ڸ�����������У�����Ҫˢ��");
		
	return 0;
}
int OnWholeUpdateArch()
{
	
	if(giRespondEvent==TRUE)
		giRebuildFlag=WHOLEUPDATE;
	else
		WriteAlertMsg("���ڸ�����������У�����Ҫ�ؽ�");
	
	return 0;
}
int OnShutDownArch()
{
	giAbort = TRUE;
	return 0;
}
void InitServSupportInterface()
{
	
	giShmDataKey=SERVDATAKEY;
	giShmNodeKey=SERVNODEKEY;
	giSemKey=SERVSEMKEY;
		
	CheckShmEffect=				CheckShmServEffect;
	DestroyStatList=                        DestroyServStatList;
	MountingUpdatedToMem=                   MountingUpdatedServToMem;
	MountingTotalToMem=                     MountingTotalServToMem;
	BuildTemporaryPrimaryIndex=             BuildServTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=       	DestroyServTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingServCurDeleteRecord;
	CountingIncrementRecord=                CountingServIncrementRecord;
	GetTotalBufRecord=                      GetServTotalBufRecord;
	CountingIncrementNode=                  CountingServIncrementNode;
	GetTotalBufNode=                        GetServTotalBufNode;
	LockArchShm=                            LockServShm;
	UnlockArchShm=                          UnlockServShm;
	TruncateShmIndexAndRetriveNode=         TruncateServShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildServShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=           BuildServMemListIndexAndMoveToShm;
	SemWorking=                             ServSemWorking;
	ClientUnmountNotify=                    ClientServUnmountNotify;
	ClientConnectNotify=                    ClientServConnectNotify;
	CountingTotalRecord=                    CountingServTotalRecord;
	StatTotalNode=                      StatServTotalNode;
	InitControlRecord=                      InitServControlRecord;
	CopyControlToShm=                       CopyServControlToShm;
	DetachArchShm=				DetachShmServ;
}

void InitServAcctSupportInterface()
{
	giShmDataKey=SERVACCTDATAKEY;
	giShmNodeKey=SERVACCTNODEKEY;
	giSemKey=SERVACCTSEMKEY;
		
	CheckShmEffect=				CheckShmServAcctEffect;
	DestroyStatList=                        DestroyServAcctStatList;
	MountingUpdatedToMem=                   MountingUpdatedServAcctToMem;
	MountingTotalToMem=                     MountingTotalServAcctToMem;
	BuildTemporaryPrimaryIndex=             BuildServAcctTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=       	DestroyServAcctTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingServAcctCurDeleteRecord;
	CountingIncrementRecord=                CountingServAcctIncrementRecord;
	GetTotalBufRecord=                      GetServAcctTotalBufRecord;
	CountingIncrementNode=                  CountingServAcctIncrementNode;
	GetTotalBufNode=                        GetServAcctTotalBufNode;
	LockArchShm=                            LockServAcctShm;
	UnlockArchShm=                          UnlockServAcctShm;
	TruncateShmIndexAndRetriveNode=         TruncateServAcctShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildServAcctShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=          BuildServAcctMemListIndexAndMoveToShm;
	SemWorking=                             ServAcctSemWorking;
	ClientUnmountNotify=                    ClientServAcctUnmountNotify;
	ClientConnectNotify=                    ClientServAcctConnectNotify;
	CountingTotalRecord=                    CountingServAcctTotalRecord;
	StatTotalNode=                      StatServAcctTotalNode;
	InitControlRecord=                      InitServAcctControlRecord;
	CopyControlToShm=                       CopyServAcctControlToShm;
	DetachArchShm=				DetachShmServAcct;
}

void InitServProductSupportInterface()
{
	giShmDataKey=SERVPRODUCTDATAKEY;
	giShmNodeKey=SERVPRODUCTNODEKEY;
	giSemKey=SERVPRODUCTSEMKEY;
		
		
	CheckShmEffect=				CheckShmServProductEffect;
	DestroyStatList=                        DestroyServProductStatList;
	MountingUpdatedToMem=                   MountingUpdatedServProductToMem;
	MountingTotalToMem=                     MountingTotalServProductToMem;
	BuildTemporaryPrimaryIndex=             BuildServProductTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=       	DestroyServProductTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingServProductCurDeleteRecord;
	CountingIncrementRecord=                CountingServProductIncrementRecord;
	GetTotalBufRecord=                      GetServProductTotalBufRecord;
	CountingIncrementNode=                  CountingServProductIncrementNode;
	GetTotalBufNode=                        GetServProductTotalBufNode;
	LockArchShm=                            LockServProductShm;
	UnlockArchShm=                          UnlockServProductShm;
	TruncateShmIndexAndRetriveNode=         TruncateServProductShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildServProductShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=           BuildServProductMemListIndexAndMoveToShm;
	SemWorking=                             ServProductSemWorking;
	ClientUnmountNotify=                    ClientServProductUnmountNotify;
	ClientConnectNotify=                    ClientServProductConnectNotify;
	CountingTotalRecord=                    CountingServProductTotalRecord;
	StatTotalNode=                      StatServProductTotalNode;
	InitControlRecord=                      InitServProductControlRecord;
	CopyControlToShm=                       CopyServProductControlToShm;
	DetachArchShm=				DetachShmServProduct;
}

void InitAcctSupportInterface()
{
	giShmDataKey=ACCTDATAKEY;
	giShmNodeKey=ACCTNODEKEY;
	giSemKey=ACCTSEMKEY;
		
	CheckShmEffect=				CheckShmAcctEffect;
	DestroyStatList=                        DestroyAcctStatList;
	MountingUpdatedToMem=                   MountingUpdatedAcctToMem;
	MountingTotalToMem=                     MountingTotalAcctToMem;
	BuildTemporaryPrimaryIndex=             BuildAcctTemporaryPrimaryIndex;
	DestroyTemporaryPrimaryIndex=           DestroyAcctTemporaryPrimaryIndex;
	CountingCurDeleteRecord=                CountingAcctCurDeleteRecord;
	CountingIncrementRecord=                CountingAcctIncrementRecord;
	GetTotalBufRecord=                      GetAcctTotalBufRecord;
	CountingIncrementNode=                  CountingAcctIncrementNode;
	GetTotalBufNode=                        GetAcctTotalBufNode;
	LockArchShm=                            LockAcctShm;
	UnlockArchShm=                          UnlockAcctShm;
	TruncateShmIndexAndRetriveNode=         TruncateAcctShmIndexAndRetriveNode;
RebuildShmCurIndexAndRetriveExpireRecord=RebuildAcctShmCurIndexAndRetriveExpireRecord;
	BuildMemListIndexAndMoveToShm=           BuildAcctMemListIndexAndMoveToShm;
	SemWorking=                             AcctSemWorking;
	ClientUnmountNotify=                    ClientAcctUnmountNotify;
	ClientConnectNotify=                    ClientAcctConnectNotify;
	CountingTotalRecord=                    CountingAcctTotalRecord;
	StatTotalNode=                      StatAcctTotalNode;
	InitControlRecord=                      InitAcctControlRecord;
	CopyControlToShm=                       CopyAcctControlToShm;
	DetachArchShm=				DetachShmAcct;
}



/*

һ��ˢ�¹���:

0.(�ڼ��ʱ����)��ȡ�����ڴ������� ---����CHECK�ڵõ�,Ҫ���UPDATE_TIME�ĺϷ���
	RetrieveControlFromShm();
1.�������ݵ���������(������ָ������������)��	
	MountingUpdatedToMem();	
	MountingToMem();
2 ������ʱ���ؼ�������
	BuildTemporaryPrimaryIndex();
	
3 ͳ��ioffsetCurData�������������ؼ�����ͬ�ļ�¼��,
	��ָ������������,���ñ�ʶ(cDeleteFlag)�� 	
	CountingCurDeleteRecord(���ݿ�ϵͳʱ��)

4 ͳ�Ƶĵ����ܼ�¼��������������ݿռ��С,���ؽ��ռ�.(�����¼+ͳ�Ƶļ�¼)			
	CountingIncrementRecord();
	GetTotalBufRecord();
																									
5 ͳ��ioffsetCurData��LIST�ڵ���Ҫ������NODE��¼,�������iNodeBufLen,�����½��ռ�.		
	CountingIncrementNode();
	DestroyCountingNodeIndex();

6 ����											
	LockArchShm();
6.5.֪ͨ�Ͽ���������
	ClientUnmountNotify();
	ʧ��������뿪,��ʾ������CMS.
	UnlockArchShm();
		
7 ��յ�ǰioffsetCurNode����,���������ڵ����ioffsetFreeNode��.				
	TruncateShmIndexAndRetriveNode();

8 ����ioffsetCurData,������i���������е����ݽڵ���뵽��������(ָ����ʶ�����ݽڵ�),		
	RebuildShmCurIndexAndRetriveExpireRecord();
	A)������һ���������ڴ�ֱ�ӹ���ioffsetFreeData.

9 ������������,�������ƶ���ioffsetFreeData�����뵽ioffsetCurData,ͬʱ��������.		
	BuildMemListIndexAndMoveToShm();

10.�������ƽṹ�������ڴ�.				
	CopyControlToShm();
10.5֪ͨ��������
	ClientConnectNotify();
11 ����	
	UnlockArchShm();


----ע���������ʱ,����ָ����˳������

������������.

1 ������;��ָ��KEY,GETһ�����ʧ��,	��������,�����ؽ�����.
	SemWorking();

2.�������ݵ���������(������ָ������������)��		
	MountingTotalToMem();	
	MountingToMem();
	
3. ����							
	LockArchShm();

4.֪ͨ�Ͽ���������
	ClientUnmountNotify();
	ʧ��������뿪,��ʾ������CMS.
	UnlockArchShm();
		
5.ͳ�Ƶĵ����ܼ�¼��������������ݿռ��С,���ؽ��ռ�.(�����¼)
	----ֱ��ȡMountingToMem();�Ľ��
6.ͳ����������Ҫ��NODE�ڵ��С.	
	StatTotalNode();
7.��ʼ����Ҫ�Ŀ��ƽṹ����ʼ��ioffsetFreeData��ioffsetFreeNode��.
	InitControlRecord();
8.������������,�������ƶ���ioffsetFreeData�����뵽ioffsetCurData,ͬʱ��������. ====
	BuildMemListIndexAndMoveToShm();
9.�������ƽṹ�������ڴ�.				
	CopyControlToShm();
10.֪ͨ��������
	ClientConnectNotify();
11.ʧ��������뿪,��ʾ������CMS.
	UnlockArchShm();
	
12.����


����������

	ѭ��:
	while(1){
		
		���������ʶ=FALSE;
		
		(��������ڼ������ڴ����?) 
			if(CheckShmServEffect()==TRUE&&SemWorking()==TRUE)
		����:ˢ�¹���;
		����:��������;
		
		���빲���ڴ�	HP����.
		
		���������ʶ=TRUE;
		�ȴ�1Сʱ
		if(����˳���ʶ==TRUE)
			break;
	}
	
	��Ϣһ:ˢ������
		���(���������ʶ==TRUE);
			���������ʶ=FALSE;
			ˢ�¹���;
			���������ʶ=TRUE;
		����:
			��Ӧ����ˢ������;
	��Ϣ��:�ؽ�����
		���(���������ʶ==TRUE);
			���������ʶ=FALSE;
			�ؽ�����;
			���������ʶ=TRUE;
		����:
			��Ӧ�����ؽ�����;
	��Ϣ��:�˳�����
		�����˳���ʶ =TRUE;
*/
