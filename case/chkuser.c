#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdb.h>
#include <bintree.h>
#include <dbsupp.h>
#include <stt_ticket.h>
#include "chkuser.h"

static int data_comp_msisdn_e(void *pValue,void *pData)
{

	struct YzMsisdnStruct *pSource=(struct YzMsisdnStruct *)pValue;
	struct YzMsisdnStruct *pTarget=(struct YzMsisdnStruct *)pData;

/*	printf("pSource->sMsisdn=%s,pTarget->sMsisdn=%s\n",pSource->sMsisdn,pTarget->sMsisdn);*/

	return strcmp(pSource->sMsisdn,pTarget->sMsisdn);
}


static void assign_insert_bintree_msisdn_e(void **ppHead,void *pData)
{
	*ppHead=pData;
}

/*��������д���ݿ�*/
int InsertSmspTicketSame(struct SmscTicketStruct *p,int iInsertFlag,char sTableNameSame[])
{
	static int iFirstFlag=TRUE;
	static struct SmscTicketStructOut TempOut;
	
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		bzero((void*)&TempOut,sizeof(struct SmscTicketStructOut));
		strcpy(TempOut.sTableName,sTableNameSame);
	}

	return EInsertStructToSmscTicket(p,iInsertFlag,&TempOut);
}

int main(int argc,char *argv[]){
	
	BINTREE *pRoot=NULL;
	struct SmscTicketStruct Temp;
	struct SmscTicketStructIn TempIn;
	struct YzMsisdnStruct MsisdnTemp,*pMsisdn,*pUser;
	struct YzMsisdnStructIn MsisdnTempIn;

	char sTableNameSame[256];
	int iCount,iInsCnt;


	if(argc!=3){
		printf("�÷���%s tablename newtable.\n",argv[0]);
		exit(1);
	}

	InitAppRes(argv[0]);
	if(IniConnect("dataconnstr")<0){
		printf("�������ݿ�ʧ��\n");
		return -1;
	}

	strcpy(TempIn.sTableName,argv[1]);
	strcpy(sTableNameSame,argv[2]);
	strcpy(MsisdnTempIn.sTableName,"YZ_MSISDN");
	strcpy(MsisdnTempIn.sCondition,"WHERE STATE < '31'");
	MsisdnTempIn.iBufEmpty =TRUE;
        MsisdnTempIn.iFirstFlag = TRUE;
	TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

	/*���û���Ϣ���ص���*/
	while(EGetYzMsisdnToStruct(&MsisdnTemp,&MsisdnTempIn)){

		if((pMsisdn=malloc(sizeof(struct YzMsisdnStruct)))==NULL){
			printf("error Malloc YzMsisdnStruct.\n");
			return -1;
		}

		memcpy(pMsisdn,&MsisdnTemp,sizeof(struct YzMsisdnStruct));

		if(InsertBin(&pRoot,pMsisdn,data_comp_msisdn_e,
			assign_insert_bintree_msisdn_e)<0){
			WriteAlertMsg("����BINTREEʧ��bintree_msisdn");
			exit(1);
		}
	}
	printf("�û���Ϣ���ض������ɹ�\n");

	while(EGetSmscTicketToStruct(&Temp,&TempIn)){

		iCount++;
		bzero((void*)&MsisdnTemp,sizeof(struct YzMsisdnStruct));
                strcpy(MsisdnTemp.sMsisdn,Temp.sMsisdn);

		if((SearchBin(pRoot,&MsisdnTemp,data_comp_msisdn_e,
			(void**)&pUser))==NOTFOUND) continue;
		if(atoi(pUser->sState) > 30) continue;
			
		if(InsertSmspTicketSame(&Temp,FALSE,sTableNameSame)<0){
			WriteAlertMsg("д���%sʧ��\n",sTableNameSame);
			exit(1);
		}
		iInsCnt++;
		if(iCount%10000==0){
			
			if(InsertSmspTicketSame(NULL,TRUE,sTableNameSame)<0){
				WriteAlertMsg("д���%sʧ��\n",sTableNameSame);
				exit(1);
			}
			CommitWork();
		}
	}

	if(InsertSmspTicketSame(NULL,TRUE,sTableNameSame)<0){
		WriteAlertMsg("д���%sʧ��\n",sTableNameSame);
		exit(1);
	}

	CommitWork();
	DestroyBin(pRoot);
	printf("����%s��%d��,����%s��%d������\n",TempIn.sTableName,iCount,sTableNameSame,iInsCnt);
	return 0;
}
