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

#include "sett_item.h"
#include "dbsupp.h"
#include "stt_ticket.h"

BINTREE *pRoot=NULL;
struct SettItemStruct *pSettItem=NULL;
int (*Ticket2Str)(char sTableName[],char sCondition[],
	char sSourceID[],char sRowID[],char sTemp[]);

void RegRateExprFun();
	
int data_search_bintree_stat_item_e(void *pValue,void*pData)
{
	struct SettItemStruct *pSource=(struct SettItemStruct *)pValue;
	struct SettItemStruct *pTarget=(struct SettItemStruct *)pData;
	int res;
	
	if((res=pSource->iLatnID-pTarget->iLatnID)!=0) return res;
	if((res=pSource->iAcctItemTypeID-pTarget->iAcctItemTypeID)!=0) return res;
	if((res=strcmp(pSource->sUserType,pTarget->sUserType))!=0) return res;
	if((res=strcmp(pSource->sSourceID,pTarget->sSourceID))!=0) return res;
	if((res=strcmp(pSource->sSettItemDate,pTarget->sSettItemDate))!=0) return res;
	if((res=pSource->iOppCarrierID-pTarget->iOppCarrierID)!=0) return res;
	if((res=pSource->iSettCycleID-pTarget->iSettCycleID)!=0) return res;
	return 0;
}
void assign_insert_bintree_stat_item_e(void **ppData,void *pData)
{

	struct SettItemStruct *pTemp;
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct SettItemStruct));
		ERROR_EXIT(pTemp==NULL,"分配SettItem结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct SettItemStruct));
		pTemp->pNext=NULL;
		*ppData=(void*)pTemp;
		return;
	}
	pTemp->iCharge+=((struct SettItemStruct*)pData)->iCharge;
}
int link_sett_item(void **ppData)
{
	InsertList((LIST**)&pSettItem,(LIST*)(*ppData));
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
int main(int argc, char **argv)
{
	int	iCnt=0,iFlag=0,iSplitFlag=-1,iOppCarrierID=-1,iSettCycleID=-1;
	char sSourceID[31],sRowID[19],sTemp[512],sType[2];
	char sTableName[31],sCondition[128],sExprName[128];
	struct	SettItemStruct *ptCur,*ptPre;
	struct SettItemStructOut TempOut;
	
	int	iAcctItemTypeID,iCharge,iLatnID;
	char	sState[2],sDataDate[9],sDealDate[9],sUserType[128];
	struct SettItemStruct	Temp;
		
	if(argc!=5&&argc!=6){
		printf("Usage %s exprfile type(S,M,N,R,X,P,T,t,I,Z,a,F,8,9,U,V) tablename wherecause [1].\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sExprName,argv[1]);
	strncpy(sType,argv[2],1);sType[1]=0;
	strcpy(sTableName,argv[3]);
	strcpy(sCondition,argv[4]);
	
	if(argc==6)iFlag=atoi(argv[5]);

	switch (sType[0]){
		case 'S':Ticket2Str=SttTicket2Str;break;
		case 'M':Ticket2Str=SmscTicket2Str;break;
		case 'N':Ticket2Str=SmspTicket2Str;break;
		case 'R':Ticket2Str=GprsTicket2Str;break;
		case 'X':Ticket2Str=Cdma1xTicket2Str;break;
		case 'P':Ticket2Str=PrepTicket2Str;break;
		case 'T':Ticket2Str=SmsTicket2Str;break;
		case 't':Ticket2Str=NsmsTicket2Str;break;
		case 'I':Ticket2Str=IccTicket2Str;break;
		case 'Z':Ticket2Str=ZnwTicket2Str;break;
		case 'a':Ticket2Str=SmgTicket2Str;break;
		case 'F':Ticket2Str=InfoAcct2Str;break;
		case '8':Ticket2Str=SmspNbrStat2Str;break;
		case '9':Ticket2Str=SpAcctItem2Str;break;
		case 'U':Ticket2Str=MsisdnStat2Str;break;
		case 'V':Ticket2Str=DownVoipStat2Str;break;
		default:
			printf("系统不支持%s的类别,类别=(S,M,N,R,X,P,T,t,I,Z,a,F,8,9,U,V).\n",sType);
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
		
	while(Ticket2Str(sTableName,sCondition,sSourceID,sRowID,sTemp)==true){
				
		TICKET.iOriLen=	strlen(sTemp);
		TICKET.sOri[TICKET.iOriLen]=0;
		strcpy(TICKET.sOri,sTemp);

		set_str_value("$FILENAME",pExprBuf,sSourceID);
		if(ExecCode(pExprBuf)<0){
			printf("执行公式%s失败.\n",sExprName);
			return -1;
		}
		get_int_value("latn_id",pExprBuf,&iLatnID);
		get_int_value("split_flag",pExprBuf,&iSplitFlag);
		get_str_value("data_date",pExprBuf,sDataDate);
		get_str_value("user_type",pExprBuf,sUserType);
		get_int_value("opp_carrier_id",pExprBuf,&iOppCarrierID);
		get_int_value("sett_cycle_id",pExprBuf,&iSettCycleID);
		
		get_str_value("source_id",pExprBuf,sSourceID);
		
		if(strlen(sSourceID)==0)strcpy(sSourceID,"000000");
		
		while(GetAcctItemValue(&iAcctItemTypeID,&iCharge,sState)){
			
			if(iCharge==0) continue;

			Temp.iSettItemID=	0;
			Temp.iLatnID=		iLatnID;
			Temp.iAcctItemTypeID=	iAcctItemTypeID;
			Temp.iCharge=		iCharge;
			strncpy(Temp.sSettItemDate,sDataDate,8);
			strcpy(Temp.sSettItemDate+8,"000000");
			GetHostTime(Temp.sCreatedDate);
			strcpy(Temp.sState,sState);
			strncpy(Temp.sUserType,sUserType,10);Temp.sUserType[10]=0;
			strncpy(Temp.sSourceID,sSourceID,6);Temp.sSourceID[6]=0;
			Temp.iOppCarrierID=iOppCarrierID;
			Temp.iSettCycleID=iSettCycleID;
			
			if(InsertBin(&pRoot,(void *)&Temp,
				data_search_bintree_stat_item_e,
				assign_insert_bintree_stat_item_e)<0){
				WriteAlertMsg("生成BINTREE失败SETT_ITEM_DAY");
				return -1;
			}
			/*默认为-1,这也是get_int_value的默认值*/
			if(strlen(Temp.sUserType)>1&&iSplitFlag==-1){
				Temp.sUserType[1]=0;
				if(InsertBin(&pRoot,(void *)&Temp,
					data_search_bintree_stat_item_e,
					assign_insert_bintree_stat_item_e)<0){
					WriteAlertMsg("生成BINTREE失败SETT_ITEM_DAY");
					return -1;
				}
			}
			if(strcmp(sDataDate,sDealDate)>0)
				strcpy(sDealDate,sDataDate);
		}
		if((++iCnt%30000)==0)
			WriteProcMsg("表%s当前统计记录数为%d",sTableName,iCnt);
	}
	WriteProcMsg("表%s统计完毕,记录数为%d",sTableName,iCnt);
	
/*将帐目挂到pSettItem中*/
	TravelBin(pRoot,link_sett_item);
	DestroyBin(pRoot);
	
/**输出数据到日帐表**/
        bzero((void*)&TempOut,sizeof(struct SettItemStructOut));
        if(iFlag==1) 	strcpy(TempOut.sTableName,"SETT_ITEM");
        else if(iFlag==2)strcpy(TempOut.sTableName,"SETT_ITEM_STAT");
        else if(iFlag==3)strcpy(TempOut.sTableName,"SETT_ITEM_SP");
        else if(iFlag==4)strcpy(TempOut.sTableName,"SETT_ITEM_OTHER");
        else      	strcpy(TempOut.sTableName,"SETT_ITEM_DAY");

	ptCur=pSettItem;
	iCnt=0;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		ptPre->iSettItemID=	iGetAcctItemID();
		if(EInsertStructToSettItem(ptPre,false,&TempOut)<0){
			printf("输出帐目错误SETT_ITEM_DAY.\n");
			WriteErrStackAlert();
			return -1;
		}
		iCnt++;
		
	}
	if(EInsertStructToSettItem(NULL,true,&TempOut)<0){
		printf("输出帐目错误SETT_ITEM_DAY.\n");
		WriteErrStackAlert();
		return -1;
	}
	WriteProcMsg("统计正确输出帐目数%d",iCnt);
	CommitWork();

	printf("日结程序成功,统计正确输出帐目数%d.\n",iCnt);
	
	DisconnectDatabase();
	
	return 0;
}
