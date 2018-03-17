#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>

#include <ticket_field.h>
#include <tariff_disct.h>
#include <ticket.h>
#include <detail_intf.h>
#include <detail_supp.h>
#define test

int (*Ticket2Str)(char sTableName[], char sTemp[], char sPrepTime[]);

int ProcessTicket(char sExprName[],char sLine[], int *iAbnormalCnt, int *iFlag)
{
	int iRet,iTicketValid=0,l;
	char sHostTime[15];

	/**��λ�����ṹ�ĵ�ǰ�������{unlink pCur����}*/
	ResetTicket();
	/**����ԭʼ������ָ����ԭʼ�����ṹ�ֶΣ�����ԭʼ��������*/
	l=strlen(sLine);

	TICKET.iOriLen = l;
	TICKET.sOri[l] = 0;
	memcpy((void*)(TICKET.sOri),sLine,l);

	GetHostTime(sHostTime);	

	set_str_value("$FILENAME",pExprBuf,sExprName);
	set_str_value("$NOW",pExprBuf,sHostTime);
		
	/*ִ�й�ʽ{������Ի��pCur����link}*/
	if((iRet=ExecCode(pExprBuf))<0){
		printf("���ɴ��󻰵��������.\n");
		return -1;
	}
	get_int_value("ticketvalid",pExprBuf,&iTicketValid);

	/*ticketvalid����
		<0:��Ч����;
		0 :У�鲻ͨ���쳣����������
		>0:��������
	*/
	/*��������У�鲻ͨ���Ĵ��󻰵�����ԭʼ�������ں���*/
	if(iTicketValid<1){/*��ʾ�쳣����*/
		(*iAbnormalCnt)++;
		*iFlag = false;
	}
	else{
		/*�õ�TICKET.sStd��*/
		GenStdTicket();
	}

	return 0;
}
int main(int argc, char **argv)
{
	int i,l,iRet,iErrCnt=0,iFlag = true, len=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0;
	
	char sPrepTime[31], sTableName[31], sTargetTable[31], sLine[1024];
	char sType[5], sClass[2], sSourceID[6];
	char sInput[EXPRLEN], sMessage[2048];
	char sExprName[128], sStartTime[15], sEndTime[15];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	struct StPrepTicketStruct Temp;
	struct StPrepTicketStructOut TempOut;
	
	if(argc!=8){
 		printf("Usage %s PrepTime(YYYYMMDD) Type(STT,SMS,MMS) Class(A,B) ExprName InTableName TargetTable SourceID\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	GetBillHome(sExprName);
	GetHostTime(sStartTime);
	
	strcat(sExprName,"/expr/");	
	strcpy(sPrepTime,argv[1]);
	strncpy(sType,argv[2],3);sType[3]=0;AllTrim(sType);
	strcpy(sClass,argv[3]);
	strcat(sExprName,argv[4]);
	strcpy(sTableName,argv[5]);
	strcpy(sTargetTable,argv[6]);
	strcpy(sSourceID, argv[7]);
	
	if(strcmp(sType,"STT") == 0){
		if(sClass[0] == 'A'){
			Ticket2Str=AccSttTicket2Str;
		}
		else if(sClass[0] == 'B'){
			Ticket2Str=OdsSttTicket2Str;
		}
		else if(sClass[0] == 'C'){
			Ticket2Str=LocSttTicket2Str;
		}
		else{
			printf("ϵͳ��֧��%s������,����=(A,B,C).\n",sClass);
			return -1;
		}
	}
	else if(strcmp(sType,"SMS") == 0){
		if(sClass[0] == 'A'){
			Ticket2Str=AccSmsTicket2Str;
		}
		else if(sClass[0] == 'B'){
			Ticket2Str=OdsSmsTicket2Str;
		}
		else{
			printf("ϵͳ��֧��%s������,����=(A,B).\n",sClass);
			return -1;
		}
	}
	else if(strcmp(sType,"MMS") == 0){
		if(sClass[0] == 'A'){
			Ticket2Str=AccMmsTicket2Str;
		}
		else if(sClass[0] == 'B'){
			Ticket2Str=OdsMmsTicket2Str;
		}
		else{
			printf("ϵͳ��֧��%s������,����=(A,B).\n",sClass);
			return -1;
		}
	}
	else{
		printf("ϵͳ��֧��%s�����,���=(STT,SMS,MMS).\n",sType);
		return -1;
	}

	strcpy(TempOut.sTableName, sTargetTable);
	
/*�ӹ����ڴ��л�ȡ��Ҫ�Ĳ���*/
	MoveAllShmToMem();
/*����ʽ�����ڴ�*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,sMessage)!=0){
		WriteAlertPrint("���ļ�%sʧ��:%s",sExprName,sMessage);
		return -1;
	}
/*���ر��빫ʽ����������*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*���빫ʽ*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}

/**�������ݿ�***/
	if(ConnectDataDB()<0) return -1;
	while(Ticket2Str(sTableName, sLine, sPrepTime)==true){

		iFlag = true;
		/*������������б�*/
		if((iRet=ProcessTicket(sExprName,sLine,&iAbnormalCnt,&iFlag))<0){
			printf("������ʧ�ܣ���%s.\n",sTableName);
			return -1;
		}	
		if(iFlag == true){
			mvitem_fmstprepticket((struct FStPrepTicketStruct *)TICKET.sStd, &Temp);
			
			if(EInsertStructToStPrepTicket(&Temp, false, &TempOut, sSourceID)<0){
				WriteAlertMsg("д��%sʧ��",sTargetTable);
				RollbackWorkRelease();
				return -1;
			}
		}
		if((++iCnt)%10000==0){
			iNormalCnt = iCnt - iAbnormalCnt;
			
			if(EInsertStructToStPrepTicket(NULL, true, &TempOut, sSourceID)<0){
				WriteAlertMsg("д��%sʧ��",sTargetTable);
				RollbackWorkRelease();
				return -1;
			}
			
			WriteProcPrint("�����%s���ɱ�%s,������%d,�����쳣��%d,�����%d",
				sTableName,sTargetTable,iCnt,iAbnormalCnt,iNormalCnt);
			CommitWork();
		}

	}
	if(EInsertStructToStPrepTicket(NULL, true, &TempOut, sSourceID)<0){
		WriteAlertMsg("д��%sʧ��",sTargetTable);
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	iNormalCnt = iCnt - iAbnormalCnt;
	WriteProcPrint("�����%s���ɱ�%s���,������%d,�����쳣��%d,�����%d",
		sTableName,sTargetTable,iCnt,iAbnormalCnt,iNormalCnt);

	DisconnectDatabase();
	GetHostTime(sEndTime);
	WriteProcMsg("����ʼʱ��:%s,����ʱ��:%s.",sStartTime,sEndTime);
		
	return 0;
}
