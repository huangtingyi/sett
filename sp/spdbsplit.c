#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

#include "dbsupp.h"
#include "stt_ticket.h"
#include "../serv/simple_serv.h"
#include "../serv/serv_intf.h"
#include "spzb_supp.h"

int main(int argc, char **argv)
{
	int  iTotalCnt=0,iOutNCnt=0,iOutOCnt=0;
	char sCondition[128],sMsisdn[20],sTemp[20],sSpCodeType[3];
	char sSourceTabName[31],sNormalTabName[31],sOtherTabName[31];


	struct ISimpleServStruct *pTemp=NULL;
	
	if(argc!=5){
		printf("Usage %s smsp_ticket_normal_xx \
 smsp_ticket_other_xx smsp_ticket_xx wherecause .\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	
	strcpy(sNormalTabName,argv[1]);Upper(sNormalTabName);
	strcpy(sOtherTabName,argv[2]);Upper(sOtherTabName);
	strcpy(sSourceTabName,argv[3]);Upper(sSourceTabName);
	strcpy(sCondition,argv[4]);Upper(sCondition);
	
	        
/**�������ݿ�***/
	if(ConnectDataDB()<0) return -1;

	WriteProcMsg("�Ա�%s�İ��û����Ϸ��뿪ʼ",sSourceTabName);

/**���ش�����Ӫ���û�����**/
	
	if(AttachSimpleServ()<0){
		printf("���ӹ����ڴ�����ʧ��.\n");
		return -1;
	}


/**���ش�����sp�굥**/
	static int iFirstFlag=true;
        static struct SmsTicketStruct Temp;
        static struct SmsTicketStructIn TempIn;

	struct SpContactRelationStruct *pS=NULL;

	struct SmsTicketStructOut TempOutN;
	bzero((void*)&TempOutN,sizeof(struct SmsTicketStructOut));
	strcpy(TempOutN.sTableName,sNormalTabName);

	struct SmsTicketStructOut TempOutO;
	bzero((void*)&TempOutO,sizeof(struct SmsTicketStructOut));
	strcpy(TempOutO.sTableName,sOtherTabName);
	
	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		strcpy(TempIn.sTableName,sSourceTabName);
		strcpy(TempIn.sCondition,sCondition);

		iFirstFlag=false;
	}
	
        /*ȡ�����м�¼���ض�����*/
        while(EGetSmsTicketToStruct(&Temp,&TempIn)){
        	
        	iTotalCnt++;
        /*��sp_acc_nbr��sp_service_code�Ի�*/
        	SetSpAccNbr(&Temp);
        /*ȫ0000�ĺ��붪��*/
        	if(strncmp(Temp.sMsisdn,"000000",6)==0)continue;
	/*ȡ��sp����*/
		if(SearchSpContactRelation(Temp.sSpCode,
			"","",Temp.sStartTime,&pS)==NOTFOUND){
			if(strcmp(Temp.sScpFlag,"3")==0){
				printf("sSpCode=%s,sStartTime=%s.\n",Temp.sSpCode,Temp.sStartTime);
			}
			continue;
		}

		strcpy(sTemp,Temp.sSpCode);
		strcpy(sTemp+5,Temp.sSpServiceCode);
	/*���ܲ��ͱ��ز��ֵ�sp��Ϣ������ͬ��ȡ���Ǳ��صĶ���*/	
		GetBinStr("SP_CONTACT_RELATION",0,sTemp,
			Temp.sStartTime,sSpCodeType);

		if(strcmp(sSpCodeType,"")!=0)continue;



		strcpy(sTemp,"");
		if(strncmp(Temp.sSpProvCode,"*",1)==0)
			strcpy(sTemp,Temp.sSpProvCode+1);
		else{
			if(strcmp(Temp.sSpAccNbr,"")==0&&
				strcmp(Temp.sSpServiceCode,"")!=0){
				if(SearchSpContactRelation(Temp.sSpCode,
				Temp.sSpServiceCode,"",Temp.sStartTime,&pS)==NOTFOUND)
					strcpy(sTemp,"90");
				else strcpy(sTemp,pS->sServiceType);
			}
			else if(strcmp(Temp.sSpAccNbr,"")!=0){
				if(SearchSpContactRelation(Temp.sSpCode,
				"",Temp.sSpAccNbr,Temp.sStartTime,&pS)==NOTFOUND)
					strcpy(sTemp,"90");
				else strcpy(sTemp,pS->sServiceType);
			}
			else{
				if(SearchSpContactRelation(Temp.sSpCode,
				"","",Temp.sStartTime,&pS)==NOTFOUND)
					strcpy(sTemp,"90");
				else strcpy(sTemp,pS->sServiceType);
			}
		}

		strcpy(Temp.sSpProvCode,sTemp);
		strcpy(Temp.sScpFlag,"3");

		strcpy(sMsisdn,Temp.sMsisdn);
		
		if(SearchSimpleServByMsisdn(sMsisdn,&pTemp)!=NULL){

			strcpy(Temp.sHomeProvCode,pTemp->sState);
			/*�������״̬Ϊ�������ʣ��Ϸ��û�(000)*/
			if(strcmp(pTemp->sState,"000")==0){

				if(EInsertStructToSmsTicket(&Temp,FALSE,
					&TempOutN)<0){
					printf("д��%s����.\n",sNormalTabName);
					WriteErrStackAlert();
					return -1;
				}
				iOutNCnt++;
			}	
			else{
				if(EInsertStructToSmsTicket(&Temp,FALSE,
					&TempOutO)<0){
					printf("д��%s����.\n",sOtherTabName);
					WriteErrStackAlert();
					return -1;
				}
				iOutOCnt++;
			}
		}
		else{
			strcpy(Temp.sHomeProvCode,"998");
			if(EInsertStructToSmsTicket(&Temp,FALSE,
				&TempOutO)<0){
				printf("д��%s����.\n",sOtherTabName);
				WriteErrStackAlert();
				return -1;
			}
			iOutOCnt++;
		}
		if((iTotalCnt%30000)==0)
			WriteProcMsg("��%s��ǰ������Ϊ%d ���%s������%d,\
				���%s������%d",sSourceTabName,iTotalCnt,
				sNormalTabName,iOutNCnt,sOtherTabName,iOutOCnt);
				
		if((iTotalCnt%100000)==0)CommitWork();
	}
	if(iOutNCnt!=0)
		if(EInsertStructToSmsTicket(NULL,TRUE,&TempOutN)<0){
			printf("д���ݿ��%sʱ����.\n",sNormalTabName);
			WriteErrStackAlert();
			return -1;
		}
	if(iOutOCnt!=0)
		if(EInsertStructToSmsTicket(NULL,TRUE,&TempOutO)<0){
			printf("д���ݿ��%sʱ����.\n",sOtherTabName);
			WriteErrStackAlert();
			return -1;
		}


	WriteProcMsg("��%s��ǰ������Ϊ%d ���%s������%d,���%s������%d",
		sSourceTabName,iTotalCnt,sNormalTabName,
		iOutNCnt,sOtherTabName,iOutOCnt);
	printf("��%s��ǰ������Ϊ%d ���%s������%d,���%s������%d.\n",
		sSourceTabName,iTotalCnt,sNormalTabName,
		iOutNCnt,sOtherTabName,iOutOCnt);


	CommitWork();
	DisconnectDatabase();

	return 0;
}
