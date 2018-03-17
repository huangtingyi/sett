#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <datatype.h>

#include <stt_ticket.h>
#include <wwsupp.h>


int main(int argc,char *argv[])
{
	
	int iTotalCnt=0,iCnt=0,iCnti=0,iRet,iFlag,iOppCarrierID,iCarrierID=3;
	char sCalledCode[9],sVisitAreaCode[9],sRawOtherParty[25],sType[4];
	char sHomeAreaCode[9];
        
        struct PrepTicketStruct Temp;
        struct PrepTicketStructIn TempIn;

	struct PrepTicketStructOut TempOut;
	 
	if(argc!=5){
		printf("�÷���%s soutablename Condition outtablename type[cfw,gj].\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);
        IniConnect("dataconnstr");
        
        bzero((void*)&TempIn,sizeof(struct PrepTicketStructIn));
	
	bzero((void*)&TempOut,sizeof(struct PrepTicketStructOut));
	
        strcpy(TempIn.sTableName,argv[1]);
        Upper(TempIn.sTableName);
        strcpy(TempIn.sCondition,argv[2]);
        Upper(TempIn.sCondition);
        strcpy(TempOut.sTableName,argv[3]);
	Upper(TempOut.sTableName);
	
	strcpy(sType,argv[4]);
	
	
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;
        	
        while(EGetPrepTicketToStruct(&Temp,&TempIn)){
        
        	iTotalCnt++;

/*        	
6����1���쳣����ת�ƵĻ������
A�û�����B�û���B�û���ת��C�û�
B�û��Ǹ�����ʡ����ͨGSM�û���C�û�����ʡ�̶��绰��
���������Ǻ���ת�ƣ���ʼ���ںͽ������ڿ�������ѡ��
ͨ���ۼƴ���>N�Σ�ͨ���ۼ�ʱ��>M���ӡ�
��ص���Сʱ�䵥λ����        	
*/  
		if(strcmp(Temp.sCallType,"01")==0||
			strcmp(Temp.sCallType,"02")==0||
			strcmp(Temp.sCallType,"03")==0)iFlag=1;
		else iFlag=0;
		GetHomeAreaCode(Temp.sMsisdn,Temp.sImsi,"591",
		iFlag,Temp.sStartTime,&iRet,sHomeAreaCode);

        	GetCalledAreaCode(Temp.sCallType,Temp.sOtherParty,"591",
                Temp.sStartTime,&iRet,sCalledCode);

        	GetRawNbr(Temp.sOtherParty,sCalledCode,Temp.sStartTime,sRawOtherParty);
        	
        	GetHeadCarr(Temp.sOtherParty,sRawOtherParty,sCalledCode,Temp.sStartTime,&iOppCarrierID);

/**msisdnΪ������ʡ����ͨGSM�û�,other_party����ʡ�̶��绰**/
        	
        	if(strncmp(sType,"cfw",3)==0&&
        		strcmp(Temp.sCallType,"03")==0&&
        		IS_UNICOM_GSM(Temp.sMsisdn)&&
        		strncmp(sHomeAreaCode,"59",2)==0&&
        		strncmp(sCalledCode,"59",2)!=0&&
        		!IS_MOB_NBR(sRawOtherParty)){

	 	      	if(iOppCarrierID==1||
	        		iOppCarrierID==4||
	        		iOppCarrierID==5||
	        		iOppCarrierID==6){

		        	strcpy(Temp.sErrCode,"1001");
				if(EInsertStructToPrepTicket(&Temp,FALSE,&TempOut)<0){
					printf("д��%s����.\n",TempOut.sTableName); 
					WriteProcMsg("д��%s����.",TempOut.sTableName); 
					WriteErrStackAlert();
					return -1;
				}
				if(++iCnt%100==0){
					printf("��%s ��¼%d ������ת����������%d.\n",TempIn.sTableName,iTotalCnt,iCnt);
					WriteProcMsg("��%s ��¼%d ������ת����������%d.",TempIn.sTableName,iTotalCnt,iCnt);
				}
	        	}
        	}
        	
/**���й�������**/
		if(strncmp(sType,"gj",2)==0&&
			strcmp(Temp.sCallType,"07")!=0&&
			strcmp(Temp.sCallType,"08")!=0&&
			strcmp(Temp.sCallType,"01")!=0&&
			strcmp(Temp.sCallType,"03")!=0&&
			strncmp(Temp.sCallType,"1",1)!=0&&
			strlen(Temp.sMsisdn)>6&&
			strlen(Temp.sOtherParty)>6){

/*��msc,trunk_in,trunk_out�ҵ�������Ӫ��*/

			 
			if(strncmp(Temp.sMsisdn,"00",2)==0&&
				strncmp(sHomeAreaCode,"0",1)!=0)
				strcpy(sHomeAreaCode,"09999");

			if(strncmp(Temp.sOtherParty,"00",2)==0&&
				strncmp(sCalledCode,"0",1)!=0)
				strcpy(sCalledCode,"09999");


			if(strcmp(Temp.sCallType,"02")==0){
				iCarrierID=3;
				sprintf(Temp.sModule,"%d",iCarrierID);
			
			}
			else{
				GetTrunkCarrier(Temp.sMsc,Temp.sTrunkOut,
					Temp.sStartTime,"O",&iCarrierID);
	
				 sprintf(Temp.sModule,"%d",iCarrierID);
			
			}
			
			if((strcmp(Temp.sCallType,"02")==0&&
				(strncmp(sCalledCode,"0",1)==0||
				strncmp(Temp.sOtherParty,"00",2)==0))||
			   (strcmp(Temp.sCallType,"02")!=0&&
			   	(strncmp(sHomeAreaCode,"0",1)==0||
			   	strncmp(Temp.sMsisdn,"00",2)==0)&&
			   	iCarrierID!=3)){
			   		
			   		
			   	if(strcmp(Temp.sCallType,"02")==0){
					strcpy(Temp.sAreaCode,sCalledCode);
					strcpy(Temp.sReserve,sHomeAreaCode);
				}
				else{
					strcpy(Temp.sAreaCode,sHomeAreaCode);
					strcpy(Temp.sReserve,sCalledCode);
				}
				
				strcpy(Temp.sErrCode,"2001");
				
				if(EInsertStructToPrepTicket(&Temp,FALSE,&TempOut)<0){
					printf("д��%s����.\n",TempOut.sTableName); 
					WriteProcMsg("д��%s����.",TempOut.sTableName); 
					WriteErrStackAlert();
					return -1;
				}
				if(++iCnti%10000==0){
					printf("��%s ��¼%d ����������������������%d.\n",TempIn.sTableName,iTotalCnt,iCnti);
					WriteProcMsg("��%s ��¼%d ����������������������%d.",TempIn.sTableName,iTotalCnt,iCnti);
				}
				aa:;
					
			}
		}
		
		if(iTotalCnt%100000==0){
			printf("��%s ��¼%d ����������������������%d.\n",TempIn.sTableName,iTotalCnt,iCnti);
			WriteProcMsg("��%s ��¼%d ����������������������%d.",TempIn.sTableName,iTotalCnt,iCnti);
		}
        	
       }
	if(iCnt!=0||iCnti!=0)
		if(EInsertStructToPrepTicket(NULL,TRUE,&TempOut)<0){
			printf("д��%s����.\n",TempOut.sTableName); 
			WriteProcMsg("д��%s����.",TempOut.sTableName); 
			WriteErrStackAlert();
			return -1;
		}

	if(strncmp(sType,"gj",2)==0){
		printf("�����%s����ܼ�¼%d ������������%d.\n",TempIn.sTableName,iTotalCnt,iCnti);
		WriteProcMsg("�����%s����ܼ�¼%d ������������%d.",TempIn.sTableName,iTotalCnt,iCnti);
	}
	if(strncmp(sType,"cfw",3)==0){
		printf("�����%s����ܼ�¼%d ������ת����%d.\n",TempIn.sTableName,iTotalCnt,iCnt);
		WriteProcMsg("�����%s����ܼ�¼%d ������ת����%d.",TempIn.sTableName,iTotalCnt,iCnt);
	}
	CommitWork();
        DisconnectDatabase();

	return 0;
}

