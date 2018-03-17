#define SAMPLE_TEST


#include <hnixs.h>
#include <trie.h>
#include <list.h>
#include <wwtiny.h>
#include <wwlog.h>
#include <wwfile.h>
#include "interface.h"

FILE *fp;
int WantToSeeNext()
{
	char sTemp[256];

	printf("want to see next?.(y/n)(default no)");
	fgets(sTemp,256,stdin);
	AllTrim(sTemp);

	if(sTemp[0]=='Y'||sTemp[0]=='y') return TRUE;

	return FALSE;
}
void InitMemTable()
{
	IInitInterface();
}

void DestroyMemTable()
{
	IDetachInterface();
}

void DrawTestingSelect()
{
	system("clear");

	printf("\n----------Testing function selecting....\n\n");
	printf("\t\t1.SearchAccNbrInServ().\n");
	printf("\t\t2.SearchServIDInServ().\n");
	printf("\t\t3.SearchImsiInServ().\n");
	printf("\t\t4.SearchAcctIDInAcct().\n");
	printf("\t\t5.SearchServIDInServAcct().\n");
	printf("\t\t6.SearchServIDInServProduct().\n\n");
	printf("\t\t7.SearchDefaultAcctIDInServ().\n");

	/******* TSearch *******/
	printf("\t\tA.TSearchAccNbrInServ() [List].\n");
	printf("\t\tB.TSearchServIDInServ() [List].\n");
	printf("\t\tC.TSearchImsiInServ() [List].\n");
	printf("\t\tD.TSearchAcctIDInAcct() [List].\n");
	printf("\t\tE.TSearchServIDInServAcct() [List].\n");
	printf("\t\tF.TSearchServIDInServProduct() [List].\n");
	printf("\t\tG.TSearchDefaultAcctIDInServ() [List].\n\n");

	printf("\t\tH.TravelAccNbrInServ().\n");

	printf("\tplease selecting testing function.(q/Q) to quit:");
}

void dumpoutServStruct(struct IServStruct *pTemp)
{
	fs_printf(fp, "\n\t\t--------the serv result of search begin-----------------.\n\n");

	fs_printf(fp, "\t\tsServID:             %s\n", pTemp->sServID);
	fs_printf(fp, "\t\tiServSeqNbr:         %d\n", pTemp->iServSeqNbr);
	fs_printf(fp, "\t\tiBillingTypeID:      %d\n", pTemp->iBillingTypeID);
	fs_printf(fp, "\t\tiServTypeID:         %d\n", pTemp->iServTypeID);
	fs_printf(fp, "\t\tiAreaID:             %d\n", pTemp->iAreaID);
	fs_printf(fp, "\t\tsAccNbrStateID:      %s\n", pTemp->sAccNbrStateID);
	fs_printf(fp, "\t\tiStopTypeID:         %d\n", pTemp->iStopTypeID);
	fs_printf(fp, "\t\tiCycleTypeID:        %d\n", pTemp->iCycleTypeID);
	fs_printf(fp, "\t\tiCentrexID:          %d\n", pTemp->iCentrexID);
	fs_printf(fp, "\t\tiInNetType:          %d\n", pTemp->iInNetType);
	fs_printf(fp, "\t\tsAccNbr:             %s\n", pTemp->sAccNbr);
	fs_printf(fp, "\t\tsImsi:               %s\n", pTemp->sImsi);
	fs_printf(fp, "\t\tsDefaultAcctID:      %s\n", pTemp->sDefaultAcctID);
	fs_printf(fp, "\t\tiQuota:              %ld\n", pTemp->iQuota);
	fs_printf(fp, "\t\tiSiteID:             %d\n", pTemp->iSiteID);
	fs_printf(fp, "\t\tsCompletedDate:      %s\n", pTemp->sCompletedDate);
	fs_printf(fp, "\t\tsCreatedDate:        %s\n", pTemp->sCreatedDate);
	fs_printf(fp, "\t\tiCreditGrade:        %d\n", pTemp->iCreditGrade);
	fs_printf(fp, "\t\tsState:              %s\n", pTemp->sState);
	fs_printf(fp, "\t\tsStateDate:          %s\n", pTemp->sStateDate);

	fs_printf(fp, "\t\tiVipFlag:        	%d\n", pTemp->iVipFlag);

	fs_printf(fp, "\t\tiTServCatgID:        %d\n", pTemp->iTServCatgID);
	fs_printf(fp, "\t\tiAServCatgID:        %d\n", pTemp->iAServCatgID);


	fs_printf(fp, "\n\t\t--------the serv result of search  end-----------------.\n");
}


void dumpoutAcctStruct(struct IAcctStruct *pTemp)
{
	fs_printf(fp, "\n\t\t--------the acct result of search begin-----------------.\n\n");

	fs_printf(fp, "\t\tsAcctID:         %s\n", pTemp->sAcctID);
	fs_printf(fp, "\t\tiAcctSeqNbr:     %d\n", pTemp->iAcctSeqNbr);
	fs_printf(fp, "\t\tiBranchID:       %d\n", pTemp->iBranchID);

	fs_printf(fp, "\t\tsPaymentMethod:  %s\n", pTemp->sPaymentMethod);
	fs_printf(fp, "\t\tsAcctNbr:        %s\n", pTemp->sAcctNbr);
	fs_printf(fp, "\t\tsBankAcct:       %s\n", pTemp->sBankAcct);
	fs_printf(fp, "\t\tiQuota:          %ld\n", pTemp->iQuota);
	fs_printf(fp, "\t\tiCreditGrade:    %d\n", pTemp->iCreditGrade);
	fs_printf(fp, "\t\tiBalance:        %ld\n", pTemp->iBalance);
	fs_printf(fp, "\t\tiChange:         %ld\n", pTemp->iChange);
	fs_printf(fp, "\t\tsCreatedDate:    %s\n", pTemp->sCreatedDate);
	fs_printf(fp, "\t\tsState:          %s\n", pTemp->sState);
	fs_printf(fp, "\t\tsStateDate:      %s\n", pTemp->sStateDate);

	fs_printf(fp, "\n\t\t--------the acct result of search  end-----------------.\n");
}

void dumpoutServAcctStruct(struct IServAcctStruct *pTemp)
{
	fs_printf(fp, "\n\t\t--------the serv_acct result of search begin-----------------.\n\n");

	fs_printf(fp, "\t\tsAcctID:             %s\n", pTemp->sAcctID);
	fs_printf(fp, "\t\tiAcctSeqNbr:         %d\n", pTemp->iAcctSeqNbr);
	fs_printf(fp, "\t\tiAcctItemTypeID:     %d\n", pTemp->iAcctItemTypeID);
	fs_printf(fp, "\t\tsServID:             %s\n", pTemp->sServID);
	fs_printf(fp, "\t\tiServSeqNbr:         %d\n", pTemp->iServSeqNbr);
	fs_printf(fp, "\t\tsState:              %s\n", pTemp->sState);
	fs_printf(fp, "\t\tsStateDate:          %s\n", pTemp->sStateDate);

	fs_printf(fp, "\n\t\t--------the serv_acct result of search  end-----------------.\n");
}


void dumpoutServProductStruct(struct IServProductStruct *pTemp)
{
	fs_printf(fp, "\n\t\t--------------serv_product struct-------------------\n");

	fs_printf(fp, "\t\tiProductID:          %d\n", pTemp->iProductID);
	fs_printf(fp, "\t\tsServID:             %s\n", pTemp->sServID);

	fs_printf(fp, "\t\tiSeqNbr:             %d\n", pTemp->iSeqNbr);

	fs_printf(fp, "\t\tiProductQuantity:    %d\n", pTemp->iProductQuantity);

	fs_printf(fp, "\t\tsState:              %s\n", pTemp->sState);
	fs_printf(fp, "\t\tsStateDate:          %s\n", pTemp->sStateDate);
	fs_printf(fp, "\t\tsExpDate:            %s\n", pTemp->sExpDate);

	fs_printf(fp, "\n\t\t--------------serv_product struct result end----------\n");
}

void TravelAccNbrInServ()
{
	struct IServStruct *pTemp;
	char sTemp[100],sAccNbr[19];
	int ioffsetCur;

	system("clear");
	printf("\n\t\tbegin test TravelAccNbrInServ()........\n\n");

	if(CheckShmServAccess() < 0){
		printf("无法连接SERV共享内存.\n");
		return;
	}
	
	while(1){
		printf("Please input sAccNbr for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sAccNbr,sTemp);

		ioffsetCur=SERV.ioffsetCurData;

		while(ioffsetCur!=-1){
			pTemp=SERVTRIEEXT(ioffsetCur);
			ioffsetCur=pTemp->NextOffset;

			if(strcmp(pTemp->sAccNbr, sAccNbr) != 0)
				continue;

			dumpoutServStruct(pTemp);
		}
		printf("Serv.iCurDataCnt: %d.\n", SERV.iCurDataCnt);

		printf("\ncontinue testing TravelAccNbrInServ()(y/n):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

void TestingSearchAccNbrInServ()
{
	struct IServStruct *pTemp;
	char sTemp[100],sAccNbr[19],sStartTime[15];
	int iOffset;

	system("clear");
	printf("\n\t\tbegin test SearchAccNbrInServ()........\n\n");

	while(1){
		printf("Please input sAccNbr for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sAccNbr,sTemp);

		printf("Please input sStartTime for search('yyyymmddhh24miss')");
		fgets(sTemp,256,stdin);
		sTemp[14]=0;
		AllTrim(sTemp);
		if(strlen(sTemp)==0) GetHostTime(sTemp);

		strcpy(sStartTime,sTemp);

    		system("date");
    		{
    			int i=0;
    			while(i<1000000){
    				ISearchAccNbrInServ(sAccNbr, sStartTime, &pTemp);
    				i++;
    			}
    		}
    		system("date");

		if(ISearchAccNbrInServ(sAccNbr, sStartTime, &pTemp)==FOUND){
			dumpoutServStruct(pTemp);

			if((iOffset = pTemp->ioffsetSAS[SERV__ACC_NBR]) > 0){

				while(iOffset>0){

					if(!WantToSeeNext()) break;

					printf("-----------search next serv----------\n");
					dumpoutServStruct(SERVTRIEEXT(iOffset));
					printf("-----------end search serv----------\n");
					iOffset=NEXT_SERV__ACCNBR(iOffset);
				}
			}
			else
				printf("-----------not found next------------\n");
		}
		else
			printf("sAccNbr %s,sStartTime %s no record in serv.\n",
					sAccNbr,sStartTime);

		printf("\ncontinue testing SearchAccNbrInServ()(y/n):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

void TestingSearchServIDInServ()
{
	struct IServStruct *pTemp;
	char sTemp[100],sServID[11];
	int iServSeqNbr, iOffset;

	system("clear");
	printf("\n\t\tbegin test SearchServIDInServ()........\n\n");

	do{
		printf("Please input ServID for search:");
		fgets(sTemp,256,stdin);
		sTemp[10]=0;
		AllTrim(sTemp);
		strcpy(sServID,sTemp);

		printf("Please input iServSeqNbr for Search:");
		fgets(sTemp,256,stdin);
		sTemp[9]=0;
		AllTrim(sTemp);
		iServSeqNbr=atoi(sTemp);

		if(ISearchServIDInServ(sServID, iServSeqNbr, &pTemp)==FOUND){
			dumpoutServStruct(pTemp);

			if((iOffset = pTemp->ioffsetSAS[SERV__SERV_ID]) > 0){

				while(iOffset>0){

					if(!WantToSeeNext()) break;

				printf("-----------search next serv----------\n");
				dumpoutServStruct(SERVTRIEEXT(iOffset));
				printf("-----------end search next----------\n");

					iOffset=NEXT_SERV__SERVID(iOffset);
				}
			}
			else
				printf("-----------not found next------------\n");
		}
		else
			printf("sServID %s,iServSeqNbr %d no record in serv.\n",
					sServID,iServSeqNbr);
		printf("\ncontinue testing SearchServIDInServ()(y/n):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N') break;
	}while(1);
}

void TestingSearchAcctIDInAcct()
{
	struct IAcctStruct *pTemp;
	char sTemp[100],sAcctID[11];
	int  iOffset;

	system("clear");
	printf("\n\tBegin test SearchAcctIDInAcct().........\n");

	while(1){
		printf("Please input ACCT_ID for search:");
		fgets(sTemp,256,stdin);
		sTemp[10]=0;
		AllTrim(sTemp);
		strcpy(sAcctID,sTemp);

		if(ISearchAcctIDInAcct(sAcctID,&pTemp)==FOUND){
			dumpoutAcctStruct(pTemp);

			if((iOffset = pTemp->ioffsetSAS[ACCT__ACCT_ID]) > 0){

				while(iOffset>0){

					if(!WantToSeeNext()) break;

				printf("---------------next acct struct------------\n");
				dumpoutAcctStruct(ACCTTRIEEXT(iOffset));
				printf("--------------next result end----------\n");
					iOffset=NEXT_ACCT__ACCTID(iOffset);
				}
			}
			else
				printf("---------------not found next-------------\n");
		}
		else
			printf("sAcctID %s, no record in acct.\n",
					sAcctID);
		printf("\ncontinue testing SearchAcctIDInAcct()(y/n):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N') break;
	}
}


/*************************************************************/
void TestingSearchServIDInServAcct()
{
	struct IServAcctStruct *pTemp;
	char sTemp[100], sServID[11];
	int  iServSeqNbr, iOffset;

	while(1){
		printf("Please input SERV_ID for search:");
		fgets(sTemp,256,stdin);
		sTemp[11]=0;
		AllTrim(sTemp);
		strcpy(sServID,sTemp);

		printf("Please input SERV_SEQ_NBR for Search:");
		fgets(sTemp,256,stdin);
		sTemp[9]=0;
		AllTrim(sTemp);
		iServSeqNbr = atoi(sTemp);

		if(ISearchServIDInServAcct(sServID, iServSeqNbr, &pTemp) == FOUND){
			dumpoutServAcctStruct(pTemp);

			if((iOffset = pTemp->ioffsetSAS[SERV_ACCT__SERV_ID]) > 0){

				while(iOffset>0){

					if(!WantToSeeNext()) break;

				fs_printf(fp, "\t\t-------------next serv_acct struct-------------\n");
				dumpoutServAcctStruct(SERVACCTTRIEEXT(iOffset));
				fs_printf(fp, "\t\t-------------next result end----------------\n");
					iOffset=NEXT_SERVACCT__SERVID(iOffset);
				}
			}
			else
				fs_printf(fp, "\t\t-------------not found next---------------------\n");
		}
		else
			printf("sServID %s,iServSeqNbr %d no record in acct.\n",
					sServID, iServSeqNbr);
		printf("\ncontinue testing SearchServIDInServAcct()(y/n):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N') break;
	}
}
void TestingSearchServIDInServProduct()
{
	struct IServProductStruct *pTemp;
	char sServID[11], sTemp[100];
	int iServSeqNbr=0, iOffset;

	printf("\n\tBegin Testing SearchServIDInServProduct().\n");
	while(1){
		printf("Please input SERV_ID for search:");
		fgets(sTemp,256,stdin);
		sTemp[10]=0;
		AllTrim(sTemp);
		strcpy(sServID,sTemp);

		if(ISearchServIDInServProduct(sServID,&pTemp) == FOUND){
			dumpoutServProductStruct(pTemp);

			if((iOffset = pTemp->ioffsetSAS[SERV_PRODUCT__SERV_ID]) > 0){

				while(iOffset>0){

					if(!WantToSeeNext()) break;
				dumpoutServProductStruct(SERVPRODUCTTRIEEXT(iOffset));
					iOffset=NEXT_SERVPRODUCT__SERVID(iOffset);
				}
			}
			else
				printf("\n--------------not found next----------------\n");
		}
		else
			printf("sServID %s,iServSeqNbr %d no record in servproduct.\n",
					sServID, iServSeqNbr);
		printf("\ncontinue testing SearchServIDInServProduct()(y/n):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N') break;
	}
}

/************************ TSearch Begin **************************************/

/***** TSearchServ ****/
void TestingTSearchAccNbrInServ()
{
	int res = 0;
	char sTemp[100],sAccNbr[19];
	POINTER iOffset;
	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp;

	system("clear");
	printf("\n\t\tbegin test TSearchAccNbrInServ()........\n\n");

	while(1){
		printf("\tPlease input AccNbr for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sAccNbr,sTemp);

		res = SearchTrieE(SERV.ioffsetAccNbr,pNodeSeg,sAccNbr,&ioffsetHead);
		if(res == NOTFOUND){
			printf("\tNot found. AccNbr: %s.\n", sAccNbr);
		}
		else{
			pTemp=SERVTRIEEXT(ioffsetHead);
			dumpoutServStruct(pTemp);

			iOffset = NEXT_SERV__ACCNBR(ioffsetHead);
			while(iOffset != -1){
				printf("\tExist next Value. Display Next?<y/n>(Default y):");
				fgets(sTemp,256,stdin);
				if(sTemp[0] == 'n' || sTemp[0] == 'N')
					break;

				pTemp=SERVTRIEEXT(iOffset);
				dumpoutServStruct(pTemp);
				iOffset = NEXT_SERV__ACCNBR(iOffset);
			}
			printf("\tFinish Search AccNbr <%s>.\n", sAccNbr);
		}

		printf("\ncontinue testing TSearchAccNbrInServ().<y/n>(Default y):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

void TestingTSearchServIDInServ()
{
	int res = 0;
	char sTemp[100],sServID[19];
	POINTER iOffset;
	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp;

	system("clear");
	printf("\n\tbegin test TSearchServIDInServ()........\n\n");

	while(1){
		printf("\tPlease input ServID for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sServID,sTemp);

		res = SearchTrieE(SERV.ioffsetServID,pNodeSeg,sServID,&ioffsetHead);
		if(res==NOTFOUND){
			printf("\tNot found. ServID: %s.\n", sServID);
		}
		else{
			pTemp=SERVTRIEEXT(ioffsetHead);
			dumpoutServStruct(pTemp);

			iOffset = NEXT_SERV__SERVID(ioffsetHead);
			while(iOffset != -1){
				printf("\tExist next Value. Display Next?<y/n>(Default y):");
				fgets(sTemp,256,stdin);
				if(sTemp[0] == 'n' || sTemp[0] == 'N')
					break;

				pTemp=SERVTRIEEXT(iOffset);
				dumpoutServStruct(pTemp);
				iOffset = NEXT_SERV__SERVID(iOffset);
			}
			printf("\tFinish Search ServID <%s>.\n", sServID);
		}

		printf("\ncontinue testing TSearchServIDInServ().<y/n>(Default y):");
		fgets(sTemp, 100, stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

void TestingTSearchImsiInServ()
{
	int res = 0;
	char sTemp[100],sImsi[19];
	POINTER iOffset;
	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp;

	system("clear");
	printf("\n\tbegin test TSearchImsiInServ()........\n\n");

	while(1){
		printf("\tPlease input Imsi for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sImsi,sTemp);

		res = SearchTrieE(SERV.ioffsetImsi,pNodeSeg,sImsi,&ioffsetHead);
		if(res == NOTFOUND){
			printf("\tNot found. Imsi: %s.\n", sImsi);
		}
		else{
			pTemp=SERVTRIEEXT(ioffsetHead);
			dumpoutServStruct(pTemp);

			iOffset = NEXT_SERV__IMSI(ioffsetHead);
			while(iOffset != -1){
				printf("\tExist next Value. Display Next?<y/n>(Default y):");
				fgets(sTemp,256,stdin);
				if(sTemp[0] == 'n' || sTemp[0] == 'N')
					break;

				pTemp=SERVTRIEEXT(iOffset);
				dumpoutServStruct(pTemp);
				iOffset = NEXT_SERV__IMSI(iOffset);
			}

			printf("\tFinish Search Imsi <%s>.\n", sImsi);
		}

		printf("\ncontinue testing TSearchImsiInServ().<y/n>(Default y):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

void TestingTSearchDefaultAcctIDInServ()
{
	int res = 0;
	char sTemp[100],sAcctID[11];
	POINTER iOffset;
	TRIEEXT *pNodeSeg=SERV.pNode;
	POINTER ioffsetHead;
	struct IServStruct *pTemp;

	system("clear");
	printf("\n\tbegin test TSearchDefaultAcctIDInServ()........\n\n");

	while(1){
		printf("\tPlease input AcctID for search:");
		fgets(sTemp,256,stdin);
		sTemp[10]=0;
		AllTrim(sTemp);
		strcpy(sAcctID,sTemp);

		res = SearchTrieE(SERV.ioffsetAcctID,pNodeSeg,sAcctID,&ioffsetHead);
		if(res == NOTFOUND){
			printf("\tNot found. AcctID: %s.\n", sAcctID);
		}
		else{
			pTemp=SERVTRIEEXT(ioffsetHead);
			dumpoutServStruct(pTemp);

			iOffset = NEXT_SERV__ACCTID(ioffsetHead);
			while(iOffset != -1){
				printf("\tExist next Value. Display Next?<y/n>(Default y):");
				fgets(sTemp,256,stdin);
				if(sTemp[0] == 'n' || sTemp[0] == 'N')
					break;

				pTemp=SERVTRIEEXT(iOffset);
				dumpoutServStruct(pTemp);
				iOffset = NEXT_SERV__ACCTID(iOffset);
			}

			printf("\tFinish Search AcctID <%s>.\n", sAcctID);
		}

		printf("\ncontinue testing TSearchDefaultAcctIDInServ().<y/n>(Default y):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

/***** TSearchServAcct *****/
void TestingTSearchServIDInServAcct()
{
	int res = 0;
	char sTemp[100],sServID[19];
	POINTER iOffset;
	TRIEEXT *pNodeSeg=SERVACCT.pNode;
	POINTER ioffsetHead;
	struct IServAcctStruct *pTemp;

	system("clear");
	printf("\n\tbegin test TSearchServIDInServAcct()........\n\n");

	while(1){
		printf("\tPlease input ServID for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sServID,sTemp);

		res = SearchTrieE(SERVACCT.ioffsetServID,pNodeSeg,sServID,&ioffsetHead);
		if(res == NOTFOUND){
			printf("\tNot found. ServID: %s.\n", sServID);
		}
		else{
			pTemp=SERVACCTTRIEEXT(ioffsetHead);
			dumpoutServAcctStruct(pTemp);

			iOffset = NEXT_SERVACCT__SERVID(ioffsetHead);
			while(iOffset != -1){
				printf("\tExist next Value. Display Next?<y/n>(Default y):");
				fgets(sTemp,256,stdin);
				if(sTemp[0] == 'n' || sTemp[0] == 'N')
					break;

				pTemp=SERVACCTTRIEEXT(iOffset);
				dumpoutServAcctStruct(pTemp);
				iOffset = NEXT_SERVACCT__SERVID(iOffset);
			}
			printf("\tFinish Search ServID <%s>.\n", sServID);
		}

		printf("\ncontinue testing TSearchServIDInServAcct().<y/n>(Default y):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

/***** TSearchServProduct *****/
void TestingTSearchServIDInServProduct()
{
	int res = 0;
	char sTemp[100],sServID[19];
	POINTER iOffset;
	TRIEEXT *pNodeSeg=SERVPRODUCT.pNode;
	POINTER ioffsetHead;
	struct IServProductStruct *pTemp;

	system("clear");
	printf("\n\tbegin test TSearchServIDInServProduct()........\n\n");

	while(1){
		printf("\tPlease input ServID for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sServID,sTemp);

		res = SearchTrieE(SERVPRODUCT.ioffsetServID,pNodeSeg,sServID,&ioffsetHead);
		if(res==NOTFOUND){
			printf("\tNot found. ServID: %s.\n", sServID);
		}
		else{
			pTemp=SERVPRODUCTTRIEEXT(ioffsetHead);
			dumpoutServProductStruct(pTemp);

			iOffset = NEXT_SERVPRODUCT__SERVID(ioffsetHead);
			while(iOffset != -1){
				printf("\tExist next Value. Display Next?<y/n>(Default y):");
				fgets(sTemp,256,stdin);
				if(sTemp[0] == 'n' || sTemp[0] == 'N')
					break;

				pTemp=SERVPRODUCTTRIEEXT(iOffset);
				dumpoutServProductStruct(pTemp);
				iOffset = NEXT_SERVPRODUCT__SERVID(iOffset);
			}
			printf("\tFinish Search ServID <%s>.\n", sServID);
		}

		printf("\ncontinue testing TSearchServIDInServProduct().<y/n>(Default y):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

/****** TSearchAcct ******/

void TestingTSearchAcctIDInAcct()
{
	int res = 0;
	char sTemp[100],sAcctID[19];
	POINTER iOffset;
	TRIEEXT *pNodeSeg=ACCT.pNode;
	POINTER ioffsetHead;
	struct IAcctStruct *pTemp;

	system("clear");
	printf("\n\tbegin test TSearchAcctIDIDInServ()........\n\n");

	while(1){
		printf("\tPlease input AcctID for search:");
		fgets(sTemp,256,stdin);
		sTemp[18]=0;
		AllTrim(sTemp);
		strcpy(sAcctID,sTemp);

		res = SearchTrieE(ACCT.ioffsetAcctID,pNodeSeg,sAcctID,&ioffsetHead);
		if(res == NOTFOUND){
			printf("\tNot found. AcctID: %s.\n", sAcctID);
		}
		else{
			pTemp=ACCTTRIEEXT(ioffsetHead);
			dumpoutAcctStruct(pTemp);

			iOffset = NEXT_ACCT__ACCTID(ioffsetHead);
			while(iOffset != -1){
				printf("\tExist next Value. Display Next?<y/n>(Default y):");
				fgets(sTemp,256,stdin);
				if(sTemp[0] == 'n' || sTemp[0] == 'N')
					break;

				pTemp=ACCTTRIEEXT(iOffset);
				dumpoutAcctStruct(pTemp);
				iOffset = NEXT_ACCT__ACCTID(iOffset);
			}
			printf("\tFinish Search AcctID <%s>.\n", sAcctID);
		}

		printf("\ncontinue testing TSearchAcctIDInAcct().<y/n>(Default y):");
		fgets(sTemp,256,stdin);
		if(sTemp[0]=='n'||sTemp[0]=='N')
			break;
	}
}

/********************** TSearch End *************************************/

int MainTestSelect()
{
	char sTemp[100];

	fflush(stdin);
	fgets(sTemp, 100, stdin);

	switch(sTemp[0]){
	/*** SERV ***/
	case '1':
		TestingSearchAccNbrInServ();
		return FALSE;
	case '2':
		TestingSearchServIDInServ();
		return FALSE;
	case '3':
/*		TestingSearchImsiInServ();*/
		return FALSE;
	/*** ACCT ***/
	case '4':
		TestingSearchAcctIDInAcct();
		return FALSE;
	/*** SERV_ACCT ***/
	case '5':
		TestingSearchServIDInServAcct();
		return FALSE;
	/*** SERV_PRODUCT ***/
	case '6':
		TestingSearchServIDInServProduct();
		return FALSE;
	case '7':
/*		TestingSearchDefaultAcctIDInServ();*/
		return FALSE;
/************** TSEARCH *******************/
	/*** SERV ***/
	case 'A':
	case 'a':
		TestingTSearchAccNbrInServ();
		return FALSE;
	case 'B':
	case 'b':
		TestingTSearchServIDInServ();
		return FALSE;
	case 'C':
	case 'c':
		TestingTSearchImsiInServ();
		return FALSE;
	/*** ACCT ***/
	case 'D':
	case 'd':
		TestingTSearchAcctIDInAcct();
		return FALSE;
	/*** SERV_ACCT ***/
	case 'E':
	case 'e':
		TestingTSearchServIDInServAcct();
		return FALSE;
	/*** SERV_PRODUCT ***/
	case 'F':
	case 'f':
		TestingTSearchServIDInServProduct();
		return FALSE;
	case 'G':
	case 'g':
		TestingTSearchDefaultAcctIDInServ();
		return FALSE;
	case 'H':
	case 'h':
		TravelAccNbrInServ();
		return FALSE;
	case 'q':
	case 'Q':
		return TRUE;
	default: return FALSE;
	}
}

int main(int argc,char *argv[])
{

	printf(">应用程序启动\n");
	InitMemTable();

	if((fp=fopen("sample.log","a+"))==NULL){
		printf("不能打开日志文件.\n");
	}
	DrawTestingSelect();

	while(!MainTestSelect()) DrawTestingSelect();


	DestroyMemTable();

	printf(">应用程序正常退出\n");

	return 0;
}

