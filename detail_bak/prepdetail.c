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

	/**复位话单结构的当前输出链表{unlink pCur链表}*/
	ResetTicket();
	/**加载原始话单到指定的原始话单结构字段，设置原始话单长度*/
	l=strlen(sLine);
#ifdef test
	TICKET.iOriLen = l;
	TICKET.sOri[l] = 0;
	memcpy((void*)(TICKET.sOri),sLine,l);

	GetHostTime(sHostTime);	

	set_str_value("$FILENAME",pExprBuf,sExprName);
	set_str_value("$NOW",pExprBuf,sHostTime);
		
	/*执行公式{这里可以获得pCur链表，link}*/
	if((iRet=ExecCode(pExprBuf))<0){
		printf("生成错误话单链表错误.\n");
		return -1;
	}
	get_int_value("ticketvalid",pExprBuf,&iTicketValid);

	/*ticketvalid属性
		<0:无效话单;
		0 :校验不通过异常话单供回收
		>0:正常话单
	*/
	/*对于属性校验不通过的错误话单，则将原始话单附在后面*/
	if(iTicketValid<0){
		//printf("err\n");
		(*iAbnormalCnt)++;
		*iFlag = false;
	}
	else if(iTicketValid==0){/*0表示异常话单*/
		(*iAbnormalCnt)++;
		*iFlag = false;
	}
	else{
		/*得到TICKET.sStd串*/
		GenStdTicket();
		//printf("%s\n",TICKET.sStd);
	}
#endif

	return 0;
}
int main(int argc, char **argv)
{
	int i,l,iRet,iErrCnt=0,iFlag = true;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0;
	
	char sPrepTime[31], sTableName[31], sTargetTable[31], sLine[1024];
	char sType[5], sClass[2];
	char sInput[EXPRLEN], sMessage[2048];
	char sExprName[128];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	struct StPrepTicketStruct sTemp;
	struct StPrepTicketStructOut sOut;
	
	if(argc!=7){
 		printf("Usage %s PrepTime(YYYYMMDD) Type(STT,SMS,MMS) Class(A,B) ExprName InTableName TargetTable \n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	GetBillHome(sExprName);
	
	strcat(sExprName,"/expr/");	
	strcpy(sPrepTime,argv[1]);
	strncpy(sType,argv[2],3);sType[3]=0;AllTrim(sType);
	strcpy(sClass,argv[3]);
	strcat(sExprName,argv[4]);
	strcpy(sTableName,argv[5]);
	strcpy(sTargetTable,argv[6]);

	if(strcmp(sType,"STT") == 0){
		if(sClass[0] == 'A'){
			Ticket2Str=AccSttTicket2Str;
		}
		else if(sClass[0] == 'B'){
			Ticket2Str=OdsSttTicket2Str;
		}
		else{
			printf("系统不支持%s的子类,子类=(A,B).\n",sClass);
			return -1;
		}
	}
	else if(strcmp(sType,"SMS") == 0){
		Ticket2Str=AccSmsTicket2Str;
	}
	else if(strcmp(sType,"MMS") == 0){
		Ticket2Str=AccMmsTicket2Str;
	}
	else{
		printf("系统不支持%s的类别,类别=(STT,SMS,MMS).\n",sType);
		return -1;
	}

	strcpy(sOut.sTableName, sTargetTable);
	
#ifdef test
/*从共享内存中获取必要的参数*/
	MoveAllShmToMem();
/*将公式读到内存*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,sMessage)!=0){
		WriteAlertPrint("读文件%s失败:%s",sExprName,sMessage);
		return -1;
	}
/*加载编译公式函数及参数*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
#endif

/**连接数据库***/
	if(ConnectDataDB()<0) return -1;
	//CreateTable(sTargetTable);
	while(Ticket2Str(sTableName, sLine, sPrepTime)==true){

		iFlag = true;
		/*生成输出话单列表*/
		if((iRet=ProcessTicket(sExprName,sLine,&iAbnormalCnt,&iFlag))<0){
			printf("处理话单失败，表%s.\n",sTableName);
			return -1;
		}	
		if(iFlag == true){
			mvitem_fmstprepticket((struct FStPrepTicketStruct *)TICKET.sStd, &sTemp);
			
			if(EInsertStructToStPrepTicket(&sTemp, false, &sOut)<0){
				WriteAlertMsg("写表%s失败",sTargetTable);
				RollbackWorkRelease();
				return -1;
			}
		}
		if((++iCnt)%500000==0){
			iNormalCnt = iCnt - iAbnormalCnt;
			WriteProcPrint("处理表%s生成表%s,处理数%d,其中异常数%d,输出数%d",
				sTableName,sTargetTable,iCnt,iAbnormalCnt,iNormalCnt);
			CommitWork();
		}
		//if(iCnt == 1) break;
	}
	if(EInsertStructToStPrepTicket(NULL, true, &sOut)<0){
		WriteAlertMsg("写表%s失败",sTargetTable);
		RollbackWorkRelease();
		return -1;
	}
	CommitWork();
	//printf("sLine:%s\n\n",sLine);
	iNormalCnt = iCnt - iAbnormalCnt;
	WriteProcPrint("处理表%s生成表%s完毕,处理数%d,其中异常数%d,输出数%d",
		sTableName,sTargetTable,iCnt,iAbnormalCnt,iNormalCnt);

	DisconnectDatabase();
	
	return 0;
}
