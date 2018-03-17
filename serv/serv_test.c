#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <trie.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

#include "dbsupp.h"
#include "stt_ticket.h"
#include "simple_serv.h"
#include "serv_intf.h"

int main()
{
	char sMsisdn[20],sImsi[15];
	struct ISimpleServStruct *pTemp=NULL;
	
	if(AttachSimpleServ()<0){
		printf("sMsisdn连接共享内存资料失败.\n");
		return -1;
	}
	
	printf("Please enter msisdn:");
	gets(sMsisdn);
	if(SearchSimpleServByMsisdn(sMsisdn,&pTemp)==NULL){
		printf("sMsisdn无法找到用户资料.\n");
		return -1;
	}
	printf("sMsisdn资料找到\n");
	
	printf("msisdn=%s,imsi=%s,state=%s,billing_type_id=%s.\n",
		pTemp->sMsisdn,pTemp->sImsi,pTemp->sState,pTemp->sBillingTypeID);


	if(AttachSimpleServI()<0){
		printf("sImsi连接共享内存资料失败.\n");
		return -1;
	}
	
	printf("Please enter imsi:");
	gets(sImsi);
	if(SearchSimpleServByImsi(sImsi,&pTemp)==NULL){
		printf("sImsi无法找到用户资料.\n");
		return -1;
	}
	printf("sImsi资料找到\n");
	
	printf("msisdn=%s,imsi=%s,state=%s,billing_type_id=%s.\n",
		pTemp->sMsisdn,pTemp->sImsi,pTemp->sState,pTemp->sBillingTypeID);

	
	return 0;
}
