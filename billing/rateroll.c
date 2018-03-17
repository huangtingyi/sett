#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>

#include <ticket_field.h>
#include <tariff_disct.h>
#include <ticket.h>
#include <stt_ticket.h>
#include <bill_supp.h>


/*upd_supp.c������*/

int EUpdateXStr2Tab(char sXStr[],char sRowID[],
        int iUpdateFlag,struct MyTabColumnsStruct *ptLkHead,
	struct UStrStructUp *pTarget);

struct FileControlOutStruct *pOutput=NULL;
struct TinyRollLogStruct *pSumLog=NULL;


int GenOutputList(char sSplitType[],char sSourceID[],char sOldRec[],
	char sFileName[],char sNewRec[])
{
	int i,l;
	char sRecord[1024],msg[1024],sTargetName[256],sSplitNew[21];
	
	strcpy(sSplitNew,"");
	
	if(Item2OutListX(&pOutput,sSplitType,sNewRec,strlen(sNewRec),
		sSplitNew,msg)<0){
		WriteAlertMsg("����ԭ�����������");
		return -1;
	}
	l=sprintf(sRecord,"%s::RLL\n",sOldRec);
	
	if(Item2OutListX(&pOutput,sSplitType,sRecord,l,sSplitNew,msg)<0){
		WriteAlertMsg("�����»����������");
		return -1;
	}

	for(i=0;i<strlen(sSplitNew);i++){

		sprintf(sTargetName,"%s.%c",sFileName,sSplitNew[i]);

		if(SumTinyRollLog(&pSumLog,sSourceID,sTargetName,2)<0){
			WriteAlertMsg("������־�ļ��б����");
			return -1;
		}
	}
	
	return 0;	
}
int WantOutput(char sFileName[])
{
	if(strcmp(sFileName,"null")==0||
		strcmp(sFileName,"NULL")==0) return false;
	return true;
}
int main(int argc, char **argv)
{
	int i,l,iRet,iWantOutput=false;
	int iMissCnt=0,iRightCnt=0,iCnt=0,iTicketValid=0;
	
	char  sTableName[31],sCondition[128],sFileName[256],sHostTime[15];
	char  msg[2048],sNewName[8192],sBaseName[128],sRowID[19],sSplitNew[30];
	char  sTemplateRule[128],sInput[EXPRLEN],sModule[4],sNormalDir[256];
	char  sExprName[128],sSplitStr[10],sSplitType[10],sVisitAreaCode[10];
	
	char sOriLine[1024]; /*ԭʼRATE�����¼���½����¼*/
	char sOriIn[1024],sOriRes[1024],sNewRes[1024];/*ԭʼ���롢����������*/

	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	
	struct SplitRuleStruct *pSplitRule=NULL;
	struct	FileControlListStruct *pList;
	struct MyTabColumnsStruct *ptMyTab,*ptIoTab,*ptInTab,*ptOutTab;
	
	struct UStrStructUp *pTarget=NULL;
	
	if(argc!=9){
		printf("Usage %s tablename wherecause exprfile \
templateid splittype visitcode module filename.\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[2]);
	strcpy(sExprName,argv[3]);
	strcpy(sTemplateRule,argv[4]);
	strcpy(sSplitType,argv[5]);sSplitType[1]=0;/*����ֻȡ1λ*/
	strcpy(sVisitAreaCode,argv[6]);
	strncpy(sModule,argv[7],3);sModule[3]=0;
	strcpy(sFileName,argv[8]);
	
	iWantOutput=WantOutput(sFileName);
	pSumLog=NULL;

/*��ʼ�����۲���*/
	MoveAllShmToMem();
	
/*�������ڴ�ȥ��TEMPLATE_ID��Ӧ��SPLIT_TYPE����ȡ����08.06.03*/
	if(GetTemplateSplitStr(sTemplateRule,sSplitStr)<0) return -1;

/*���������б�*/
	InitFileControlList(sTemplateRule,sSplitStr,&pFileControlList);
	
	InitTollTariffList(comp_toll_tariff_ticket);
	
/*����ʽ�����ڴ�*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,msg)!=0){
		WriteAlertPrint("���ļ�%sʧ��:%s",sExprName,msg);
		return -1;
	}
/*���ر��빫ʽ����������*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*���빫ʽ*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		WriteAlertPrint("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	
/**�������ݿ�***/
	if(ConnectDataDB()<0) return -1;

/*��ȡ�µ�SQL������ڻ�ȡ��¼*/
	if(InitMyTabColumns(sTableName,&ptMyTab)<0)return -1;

	GetXStrTableNameStmt(ptMyTab,sTableName,sCondition,sNewName);
	
/*printf("newname=%s\n",sNewName);
*/

	if(InitMyTabIoColumns(sTableName,&ptIoTab)<0) return -1;
	
	SetMyTabColumnOffset(ptMyTab);

	LinkMyTabColumnHead(ptIoTab,ptMyTab);
	
	GetIoMyTabColumnList(&ptIoTab,&ptInTab,&ptOutTab);
	
	SetMyTabColumnOffset(ptInTab);
	SetMyTabColumnOffset(ptOutTab);

/*��ʼ��EUPDATE�ṹ*/	
	if((pTarget=MallocUStrStructUp(ptOutTab))==NULL){
		WriteAlertPrint("�����ڴ�UStrStructUp����");
		return -1;
	}
	strcpy(pTarget->sTableName,sTableName);
	GetUpdSqlStmt(ptOutTab,sTableName,pTarget->sStatement);

/*printf("statement=%s\n",pTarget->sStatement);
*/

	GetHostTime(sHostTime);

	while(XStrTicket2Str(sNewName,"",sBaseName,sRowID,sOriLine)==true){

		iCnt++;

		/*��ԭʼ�����ԭʼ����ֶ����������*/
		GetMyTabStr(ptInTab,sOriLine,sOriIn);
		GetMyTabStr(ptOutTab,sOriLine,sOriRes);
		
		TICKET.iOriLen=strlen(sOriIn);
		strcpy(TICKET.sOri,sOriIn);

		set_str_value("$FILENAME",pExprBuf,sBaseName);
		set_str_value("$MODULE",pExprBuf,sModule);
		set_str_value("$NOW",pExprBuf,sHostTime);
		set_str_value("$SPLITTYPE",pExprBuf,sSplitType);
		set_str_value("$AREACODE",pExprBuf,sVisitAreaCode);

		/*ִ�й�ʽ{������Ի��pCur����link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			WriteAlertPrint("ִ�й�ʽ����");
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		
/*�����RATE���ֻ�����Ч��ֱ�Ӻ���*/
		if(iTicketValid<=0) continue;

/*����ָ���Ļ�������ģ����벢����*/
		pList=GetFileControlList(pFileControlList,sSplitType);
		
		if(pList!=NULL){
			if((pSplitRule=GetMultiSplitRule(pList))==NULL)
				continue;
/*�ڷ���ģ��ƥ�䲻�ϵĻ����Ͳ�Ҫ��*/
			if(pSplitRule->iTicketTypeID<0) continue;
		}

		GenStdTicket();
	/**�����µ������**/
		GetMyTabStr(ptOutTab,TICKET.sStd,sNewRes);
	/*��������ɵĴ���ԭ��һ�µ�ֱ�Ӻ���*/
		if(strcmp(sOriRes,sNewRes)==0){
			iMissCnt++;
			continue;
		}

	/*���Ҫд�ļ���д*/
		if(iWantOutput){
			/*��sOriLine��Ticket.sStdд�����ļ���*/
			if(GenOutputList(sSplitType,sBaseName,sOriLine,
				sFileName,TICKET.sStd)<0){
				WriteAlertMsg("�����������ʧ��");
				return -1;
			}
		}
	/*������ļ�¼�γ�������UPDATE�����µ�ԭ��*/
		
		if(EUpdateXStr2Tab(sNewRes,sRowID,false,ptOutTab,pTarget)<0){
			WriteAlertMsg("��%s�������ݴ���.",sTableName);
			return -1;
		}
		
		if((++iRightCnt)%10000==0){
	
			if(EUpdateXStr2Tab("","",true,ptOutTab,pTarget)<0){
				WriteAlertMsg("��%s�������ݴ���.",sTableName);
				return -1;
			}

			CommitWork();
			WriteProcMsg("�Ա�%s����������Ŀ%d,���в��������۵Ļ�����%d,��������������%d",
				sTableName,iCnt,iMissCnt,iRightCnt);
		}

	}
	
	
	if(EUpdateXStr2Tab("","",true,ptOutTab,pTarget)<0){
		WriteAlertMsg("��%s�������ݴ���.",sTableName);
		return -1;
	}

	WriteProcMsg("�Ա�%s����������Ŀ%d,���в��������۵Ļ�����%d,��������������%d",
		sTableName,iCnt,iMissCnt,iRightCnt);

	CommitWork();
	DisconnectDatabase();
	
/*�������*/
	if(iWantOutput){
		if(WriteRollLogCtl(pSumLog,sFileName)<0){
			WriteAlertMsg("д��־�����ļ�ʧ��");
			return -1;
		}

		GetPathName(sFileName,sNormalDir);
		GetBaseName(sFileName,sBaseName);

		if(OutList2File(pOutput,sNormalDir,sBaseName,sSplitNew)<0){
			WriteAlertMsg("д���������ļ�%sʧ��",sFileName);
			return -1;
		}
	}
	
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iMissCnt,iRightCnt,sSplitNew);

	return 0;
}
