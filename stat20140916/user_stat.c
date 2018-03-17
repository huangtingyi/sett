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

struct MsisdnStatStruct *pMsisdnStatOut=NULL;
struct MsisdnStatStruct *pMsisdnStatUp=NULL;


int (*Ticket2Str)(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

int GetMsisdnStat(char sInput[],struct MsisdnStatStruct *p)
{

	ParseArgv(sInput,'|');

	strcpy(p->sMsisdn,	ParseToken[0]); p->sMsisdn[15]=0;
	strcpy(p->sAreaCode,	ParseToken[1]);
	p->iAreaID=		atoi(ParseToken[2]);
	
	strcpy(p->sNetType,	ParseToken[3]);
	strcpy(p->sCallType,	ParseToken[4]);
	strcpy(p->sServiceType,	ParseToken[5]);
	if(strcmp(p->sServiceType,"X")==0)return -1;

	p->iTotalDuration=(LONGINT)atoi(ParseToken[6]);
	p->iTotalMin	=(LONGINT)atoi(ParseToken[7]);
	p->iTotalCnt	=atoi(ParseToken[8]);
	p->iTotalFee1	=(LONGINT)atoi(ParseToken[9]);
	p->iTotalFee2	=(LONGINT)atoi(ParseToken[10]);
	p->iTotalFee3	=(LONGINT)atoi(ParseToken[11]);

	return 0;
}
int List2File(struct MsisdnStatStruct *ptHead,char sFileName[])
{
	int l;
	char sRecord[1024];
	struct	MsisdnStatStruct *p;
	struct FileControlStruct *ptLkHead=NULL;

	if(ptHead==NULL) return 0;

	while(ptHead!=NULL){
		p=ptHead;
		ptHead=ptHead->pNext;

		l=sprintf(sRecord,
		"%s\t%s\t%d\t%s\t%s\t%s\t%ld\t%d\t%d\t%ld\t%ld\t%ld",
			p->sMsisdn,p->sAreaCode,p->iAreaID,
			p->sNetType,p->sCallType,p->sServiceType,
			p->iTotalDuration,p->iTotalMin,p->iTotalCnt,
			p->iTotalFee1,p->iTotalFee2,p->iTotalFee3);

		if(item2list(&ptLkHead,sRecord,l)<0){
			printf("分配内存错.\n");
			return -1;
		}
	}
	ReverseList((LIST**)&ptLkHead);
	
	if(list2fileln(&ptLkHead,sFileName)<0){
		printf("写入文件%s错误.\n",sFileName);
		return -1;
	}
	return 0;
}
int OutputList2File(struct MsisdnStatStruct *ptOut,
	struct MsisdnStatStruct *ptUp,char sTableName[])
{
	char sPath[256],sFileName[256];

	GetAppHome(sPath);

	sprintf(sFileName,"%swork/%s.%d.ins.txt",sPath,sTableName,getpid());
	if(List2File(ptOut,sFileName)<0) return -1;

	sprintf(sFileName,"%swork/%s.%d.upd.txt",sPath,sTableName,getpid());
	if(List2File(ptUp,sFileName)<0) return -1;
	return 0;
}
int OutputList2Table(struct MsisdnStatStruct *ptOut,
	struct MsisdnStatStruct *ptUp,char sTableName[])
{
	struct MsisdnStatStructOut TempOut;
	struct MsisdnStatStructUp TempUp;
	struct	MsisdnStatStruct *ptCur,*ptPre;
	int	iCnt=0,iUpdateCnt=0;

/**输出数据到统计表**/
        bzero((void*)&TempOut,sizeof(struct MsisdnStatStructOut));
        bzero((void*)&TempUp,sizeof(struct MsisdnStatStructUp));

        strcpy(TempOut.sTableName,sTableName);
        strcpy(TempUp.sTableName,sTableName);
	
  	ptCur=ptOut;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EInsertStructToMsisdnStat(ptPre,false,&TempOut)<0){
			printf("输出数据错误MSISDN_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iCnt)%10000==0)
			WriteProcMsg("对表%s输出纪录数%d条",sTableName,iCnt);

	}
	if(EInsertStructToMsisdnStat(NULL,true,&TempOut)<0){
		printf("输出数据错误MSISDN_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%s输出完毕,共计记录数%d条",sTableName,iCnt);

/**更新数据到日帐表**/
	ptCur=ptUp;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(EUpdateStructToMsisdnStat(ptPre,false,&TempUp)<0){
			printf("更新数据错误MSISDN_STAT.\n");
			WriteErrStackAlert();
			return -1;
		}
		if((++iUpdateCnt)%10000==0)
			WriteProcMsg("对表%s更新纪录数%d条",sTableName,iUpdateCnt);
	}
	if(EUpdateStructToMsisdnStat(NULL,true,&TempUp)<0){
		printf("更新数据错误MSISDN_STAT.\n");
		WriteErrStackAlert();
		return -1;
	}

	WriteProcMsg("对表%s更新完毕,共计记录数%d条",sTableName,iUpdateCnt);

	WriteProcPrint("汇总数据到表%s正确,输出记录数%d,更新记录数%d",
		sTableName,iCnt,iUpdateCnt);
	return 0;

}
void sum_item_msisdn_stat(struct MsisdnStatStruct *pHead,
	 struct MsisdnStatStruct *pTemp)
{
	pHead->iTotalDuration+=	pTemp->iTotalDuration;
	pHead->iTotalMin+=	pTemp->iTotalMin;
	pHead->iTotalCnt+=	pTemp->iTotalCnt;
	pHead->iTotalFee1+=	pTemp->iTotalFee1;
	pHead->iTotalFee2+=	pTemp->iTotalFee2;
	pHead->iTotalFee3+=	pTemp->iTotalFee3;
	strcpy(pHead->sRowID,	pTemp->sRowID);
}
/*从数据库中取数据，并加到汇总纪录中*/
int MsisdnStat2Bin(BINTREE *pRoot,char sTableName[],char sCycleID[])
{
	int iCnt=0;
	static int iFirstFlag=true;
        static struct MsisdnStatStruct Temp;
        static struct MsisdnStatStructIn TempIn;
        
        static struct MsisdnStatStruct *pHead=NULL;

	if(iFirstFlag==true){
		TempIn.iBufEmpty=TRUE;
        	TempIn.iFirstFlag=TRUE;
		iFirstFlag=false;
	}
	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition," WHERE BILLING_CYCLE_ID ='%s' ",sCycleID);

        /*取出表中记录加载二叉树*/
        while(EGetMsisdnStatToStruct(&Temp,&TempIn)){

		if(SearchBin(pRoot,&Temp,data_search_bintree_msisdn_stat_e,
			(void **)&pHead)==FOUND){

			/*如果由于数据异常导致关键字有多条纪录，则只累加一次*/
			if(pHead->sRowID[0]!=0) continue;

			sum_item_msisdn_stat(pHead,&Temp);
		}
		iCnt++;
        }
	return iCnt;
}

int data_search_bintree_msisdn_stat_e(void *pValue,void*pData)
{
	struct MsisdnStatStruct *pSource=(struct MsisdnStatStruct *)pValue;
	struct MsisdnStatStruct *pTarget=(struct MsisdnStatStruct *)pData;
	int res;

	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sAreaCode,pTarget->sAreaCode))!=0) return res;

	if((res=pSource->iAreaID-pTarget->iAreaID)!=0) return res;

	if((res=strcmp(pSource->sNetType,pTarget->sNetType))!=0) return res;
	if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
	if((res=strcmp(pSource->sServiceType,pTarget->sServiceType))!=0) return res;
	if((res=strcmp(pSource->sBillingCycleID,pTarget->sBillingCycleID))!=0) return res;

	return 0;
}
void assign_insert_bintree_msisdn_stat_e(void **ppData,void *pData)
{
	struct MsisdnStatStruct *pHead=(struct MsisdnStatStruct *)(*ppData);
	struct MsisdnStatStruct *pValue=(struct MsisdnStatStruct *)pData;

	if(pHead==NULL){
		pHead=malloc(sizeof(struct MsisdnStatStruct));
		ERROR_EXIT(pHead==NULL,"分配MsisdnStat结构错误");

		memcpy((void*)pHead,pData,sizeof(struct MsisdnStatStruct));
		pHead->pNext=NULL;
		*ppData=(void*)pHead;
	}
	else{
		pHead->iTotalDuration+=	pValue->iTotalDuration;
		pHead->iTotalMin+=	pValue->iTotalMin;
		pHead->iTotalCnt+=	pValue->iTotalCnt;
		pHead->iTotalFee1+=	pValue->iTotalFee1;
		pHead->iTotalFee2+=	pValue->iTotalFee2;
		pHead->iTotalFee3+=	pValue->iTotalFee3;
	}
}
int link_msisdn_stat_outup(void **ppData)
{
	struct MsisdnStatStruct *pTemp=(struct MsisdnStatStruct *)(*ppData);
	
	if(pTemp->sRowID[0]==0) 
		InsertList((LIST**)&pMsisdnStatOut,(LIST*)pTemp);
	else	InsertList((LIST**)&pMsisdnStatUp,(LIST*)pTemp);

	return 0;
}

int CompileStatExpr(char sExprName[])
{
	int l,i;
	FILE *fp;
	char	sInput[EXPRLEN];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];

	if(IsFile(sExprName)==FALSE){
		printf("公式文件%s无效.\n",sExprName);
		return -1;
	}
/*将公式文件读到内存*/
	if((l=FileSize(sExprName))>=EXPRLEN){
		printf("参数文件%s大于%d,%d.\n",sExprName,EXPRLEN,l);
		return -1;
	}
	fp=fopen(sExprName,"r");
	if(fread(sInput,l,1,fp)!=1){
		printf("读文件%s失败.\n",sExprName);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);

/*注册公式函数*/
	RegPrepVar();
	RegAcctItemVar();
	CheckSysVar=CheckAcctItemVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	return 0;
}
void GetLockName(char sStatName[],int iOppCarr,char sLockName[])
{
	char sPath[256];
	
	GetAppHome(sPath);
	
	sprintf(sLockName,"%sctl/%s_%d.txt",sPath,sStatName,iOppCarr);
}
int LockStat(char sLockName[])
{
	time_t tDiff;
	char sCommand[256],sResult[256],sMessage[256];

	/*文件不存在则*/
	if(!IsFile(sLockName)){
		sprintf(sCommand,"echo start %d > %s ",getpid(),sLockName);
	
		if(exec2str(sCommand,sResult)!=0)
			return -1;
		return 0;
	}
	/*文件存在则是否是start*/
	while(1){
		
		if(!IsFile(sLockName)) break;

		if(ReadFileToBuf(sLockName,256,sResult,sMessage)<0)
			return -1;

		if(strncmp(sResult,"start",5)!=0) break;
		
		/*锁定3个小时以上自动解锁*/
		tDiff=tGetHostTime()-FileModifyTime(sLockName);
		if(tDiff>(3600*3)){
			WriteProcMsg("锁定超时间,3小时,自动解锁");
			break;
		}

		sleep(30);
		WriteProcMsg("等待文件　%s 解锁,diff=%ld",sLockName,tDiff);

	}
	/*如果已经解锁则自己进入*/
	sprintf(sCommand,"echo start %d > %s ",getpid(),sLockName);
	system(sCommand);

	return 0;
}
void UnlockStat(char sLockName[])
{
	char sCommand[256];

	sprintf(sCommand,"rm -rf %s",sLockName);
	system(sCommand);
}
int main(int argc, char **argv)
{
	int  iTotalCnt=0,iCnt=0,t1=0,iTicketValid=-1,iOppCarr=0;
	char sSourceID[31],sRowID[19],sType[2],sStatName[31],sLockName[256];
	char sTableName[31],sCondition[128],sExprName[128],sDateTemp[15];
	char sStatDate[15],sChkDate[15],sStrOri[4096],sTemp[104],sAppID[256];
	char sBillingCycleID[7],*pPre,*pCur;

	struct 	MsisdnStatStruct	Temp;

	BINTREE *pRoot=NULL;

	if(argc!=8){
		printf("Usage %s exprfile type(S,P,t,I,Z,T,N) oppcarr tablename \
statdate stattname [wherecause].\n",argv[0]);
		return -1;
	}
	sprintf(sAppID,"%s_%s",argv[0],argv[3]);
	InitAppRes(sAppID);
	strcpy(sExprName,argv[1]);
	strncpy(sType,argv[2],1);sType[1]=0;
	iOppCarr=	atoi(argv[3]);
	strcpy(sTableName,argv[4]);Upper(sTableName);
	strcpy(sDateTemp,argv[5]);Upper(sDateTemp);sDateTemp[8]=0;
	strcpy(sStatName,argv[6]);Upper(sStatName);
        strcpy(sCondition,argv[7]);Upper(sCondition);

/*取前一天日期*/
        strcpy(sChkDate,sDateTemp); strcat(sChkDate,"000000");
        if((t1=tGetTime(sChkDate))<0) return -1;
        if(AddTimes(sChkDate,-86400)<0) return -1;
        strncpy(sStatDate,sChkDate,8);  sStatDate[8]=0;

	switch (sType[0]){
		case 'S':Ticket2Str=SttTicket2Str;break;
		case 'P':Ticket2Str=PrepTicket2Str;break;
		case 't':Ticket2Str=NsmsTicket2Str;break;
		case 'I':Ticket2Str=IccTicket2Str;break;
		case 'Z':Ticket2Str=ZnwTicket2Str;break;
		case 'T':Ticket2Str=SmsTicket2Str;break;
		case 'N':Ticket2Str=SmspTicket2Str;break;
		default:
			printf("系统不支持%s的类别,类别=(S,P,t,I,Z,T,N).\n",sType);
			return -1;
	}
	RegRateExprFun();
/*处理编译公式*/
	if(CompileStatExpr(sExprName)<0){
		printf("处理公式文件%s失败.\n",sExprName);
		WriteErrStackAlert();
		return -1;
	}
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;

	strncpy(sBillingCycleID,sStatDate,6);sBillingCycleID[6]=0;

	if(strlen(sCondition)==0)
		sprintf(sCondition," WHERE SUBSTR(START_TIME,1,8)='%s' ",sStatDate);

	WriteProcMsg("对表%s的统计开始",sTableName);

	bzero((void*)&Temp,sizeof(struct 	MsisdnStatStruct));
	strncpy(Temp.sBillingCycleID,sBillingCycleID,6);
	Temp.sBillingCycleID[6]=0;
	
	while(Ticket2Str(sTableName,sCondition,sSourceID,sRowID,TICKET.sOri)==true){

		++iTotalCnt;
		if(iTotalCnt==1) TICKET.iOriLen=strlen(TICKET.sOri);

		set_str_value("$FILENAME",pExprBuf,sSourceID);
		set_int_value("opp_carrier_id",pExprBuf,iOppCarr);
		if(ExecCode(pExprBuf)<0){
			printf("执行公式%s失败.\n",sExprName);
			return -1;
		}

		get_str_value("str_ori",pExprBuf,sStrOri);
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);

		if(iTicketValid<0) continue;

		pPre=sStrOri;
		pCur=strchr(pPre,';');
		
		while(1){
			if(pCur!=NULL){
				strncpy(sTemp,pPre,pCur-pPre);
				sTemp[pCur-pPre]=0;
			}
			else	strcpy(sTemp,pPre);

			if(pCur==NULL) break;
			
			pPre=pCur+1;
			pCur=strchr(pPre,';');

			if(sTemp[0]==0) continue;

			if(GetMsisdnStat(sTemp,&Temp)!=0)continue;
			
			if(InsertBin(&pRoot,(void *)&Temp,
				data_search_bintree_msisdn_stat_e,
				assign_insert_bintree_msisdn_stat_e)<0){
				WriteAlertMsg("生成BINTREE失败MSISDN_STAT");
				return -1;
			}

		}

		if((++iCnt%30000)==0)
			WriteProcMsg("表%s当前话单数为%d 参与统计数为%d",
				sTableName,iTotalCnt,iCnt);
	}
	WriteProcMsg("表%s当前话单数为%d 参与统计数为%d",
		sTableName,iTotalCnt,iCnt);

	GetLockName(sStatName,iOppCarr,sLockName);
	
	if(LockStat(sLockName)<0){
		WriteAlertMsg("锁表失败检查 $APPHOME/ctl目录权限");
		return -1;
	}

	WriteProcMsg("加载%s表%s帐周数据到内存",sStatName,sBillingCycleID);

/*加载统计表,将加载的数据和平衡二叉树上的数据汇总*/
	if((iCnt=MsisdnStat2Bin(pRoot,sStatName,sBillingCycleID))<0){
		WriteAlertMsg("生成BINTREE失败");
		UnlockStat(sLockName);
		return -1;
	}
	WriteProcMsg("加载%s表%s帐周的数据完毕,%d条",
		sStatName,sBillingCycleID,iCnt);

/*将有sRowID的加到UPDATE链表，将无ROWID的加到INSERT链表*/
	TravelBin(pRoot,link_msisdn_stat_outup);
	
/**输出数据到统计表**/
	if(OutputList2Table(pMsisdnStatOut,pMsisdnStatUp,sStatName)<0){
		WriteAlertMsg("输出数据到统计表出错.\n");
		UnlockStat(sLockName);
		if(OutputList2File(pMsisdnStatOut,pMsisdnStatUp,sTableName)<0)
			WriteAlertMsg("输统计表错误，输出文件也错\n");
		return -1;
	}

	UnlockStat(sLockName);


	CommitWork();
	DestroyBin(pRoot);
	DisconnectDatabase();

	return 0;
}
