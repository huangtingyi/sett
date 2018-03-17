#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <ticket_field.h>
#include <tariff_disct.h>


int OriFile2List(char sFileName[],struct FileControlStruct **pptHead);
void ErrField2ErrTicket(char sErrField[],struct ErrTicketStruct *po);

int WantBillExpr(char sModule[])
{
	char sTemp[128],sPath[128];

	GetIniName(sPath);
	if(ReadString(sPath,"bss","prep","billexpr",sTemp)<0) return false;
	
	if(strstr(sTemp,sModule)==NULL) return false;
	return true;
}
/* 将_$(pid).tmp，这种文件的末尾去掉 */
void TrimPrepName(char sSourceID[])
{
	char *pc;

	if(RLike(sSourceID,".tmp")==false) return;

	pc=sSourceID+strlen(sSourceID)-4;

	*pc=0;

	while(pc>sSourceID){
		if(*pc=='_'){
			*pc=0;
			break;
		}
		pc--;
	}
}
void ErrField2ErrTicket(char sErrField[],struct ErrTicketStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct ErrTicketStruct));
/*
$ERRFIELD 编码规则：
CALL_TYPE,MSISDN,OTHER_PARTY,START_TIME,DURATION,IMSI,MSC,
RESERVE1,RESERVE2,RESERVE3,RESERVE4,STATE

*/
		GetSepStr(sErrField,',',0,po->sCallType);
		AllTrim(po->sCallType);
		GetSepStr(sErrField,',',1,po->sMsisdn);
		AllTrim(po->sMsisdn);
		GetSepStr(sErrField,',',2,po->sOtherParty);
		AllTrim(po->sOtherParty);
		GetSepStr(sErrField,',',3,po->sStartTime);
		AllTrim(po->sStartTime);
		GetSepStr(sErrField,',',4,po->sDuration);
		AllTrim(po->sDuration);
		GetSepStr(sErrField,',',5,po->sImsi);AllTrim(po->sImsi);
		GetSepStr(sErrField,',',6,po->sMsc);AllTrim(po->sMsc);
		GetSepStr(sErrField,',',7,po->sReserve1);
		AllTrim(po->sReserve1);
		GetSepStr(sErrField,',',8,po->sReserve2);
		AllTrim(po->sReserve2);
		GetSepStr(sErrField,',',9,po->sReserve3);
		AllTrim(po->sReserve3);
		GetSepStr(sErrField,',',10,po->sReserve4);
		AllTrim(po->sReserve4);
		GetSepStr(sErrField,',',11,po->sState);AllTrim(po->sState);
		if(strcmp(po->sState,"")==0)strcpy(po->sState,"3");

}

int GenStdErrTicket(char sFileType[],char sModule[],char sSourceID[],
	char sFileName[],char sAreaCode[],int iErrCode,int iLine,char sOri[],
	int iOriLen,char sErrField[],char sStdErr[])
{
	int l=0;
	char sTempFileName[128],sTempAreaCode[6];
	
	struct ErrTicketStruct Temp;

	ErrField2ErrTicket(sErrField,&Temp);
	
	if(strncmp(sFileType,"txt",3)==0){
		strcpy(Temp.sRecordType,"T");
		strcpy(Temp.sErrRec,sOri);
	}
	else{
		strcpy(Temp.sRecordType,"B");
		hbcd_hex2asc((unsigned char *)sOri,iOriLen,Temp.sErrRec);
	}

        strcpy(sTempFileName,sFileName);

        if(strlen(sTempFileName)>40)sTempFileName[40]=0;
        
        strncpy(sTempAreaCode,sAreaCode,5);sTempAreaCode[5]=0;
        
	l+=sprintf(sStdErr+l,"%1s%-2s%-15s%-24s",
		Temp.sRecordType,Temp.sCallType,Temp.sMsisdn,Temp.sOtherParty);
	l+=sprintf(sStdErr+l,"%-14s%-6s%-15s%-15s",
		Temp.sStartTime,Temp.sDuration,Temp.sImsi,Temp.sMsc);
	l+=sprintf(sStdErr+l,"%-20s%-20s%-30s%-30s",
		Temp.sReserve1,Temp.sReserve2,Temp.sReserve3,Temp.sReserve4);
	l+=sprintf(sStdErr+l,"%-6s%-40s%08d%04d%-19s%-3s%-5s%1s%s\n",
		sSourceID,sTempFileName,iLine,iErrCode,"NORECYLE",
		sModule,sTempAreaCode,Temp.sState,Temp.sErrRec);

	return l;
}
int main(int argc,char *argv[])
{
	FILE *fp;
	int i,l,iRet,iTicketValid=0,iByte=0,iStartPos=0,iKeyLen=0;
	int iErrCnt=0,iNormalCnt=0,iAbnormalCnt=0,iCnt=0,iLen,iWantCtl=0;
	char sSource[10],sUserType[2],sStdErr[4096];
	char sInput[EXPRLEN],sBaseName[128],sTargetName[128],sSourceID[128];
	char sFileName[128],sExprName[128],sNormalDir[128],sErrDir[128];
	char sNormalName[128],sAbnormalName[128],sErrName[128],sTempName[128];
	char sDataDate[15],sMsc[16],sAreaCode[6],sNow[15],sModule[10];
	char sSuffixStr[21],sTemp[256],sMsg[256],sSplit[10],sSplitNew[20];
	char sFileType[40],sErrField[1024];
	
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pAbnormal=NULL,*pErr=NULL;
	struct FileControlOutStruct *pNormal=NULL;
	
	if(argc!=14&&argc!=11&&argc!=12){
		printf("Usage: %s expr input ndir edir msc area mod "
			"usertype source filetype [target].\n",argv[0]);
		printf("or\n");
		printf(" %s expr input ndir edir msc area mod usertype "
			"source filetype split offset keylen .\n",argv[0]);
		return -1;
	}
/*初始化参数部分*/
	InitAppRes(argv[0]);
	iWantCtl=WantCtl(argv[0]);
	strcpy(sExprName,argv[1]);
	strcpy(sFileName,argv[2]);
	strcpy(sNormalDir,argv[3]);
	strcpy(sErrDir, argv[4]);
	strcpy(sMsc,	argv[5]);
	strcpy(sAreaCode,argv[6]);
	strcpy(sModule,argv[7]);
	
	strncpy(sUserType,argv[8],1);sUserType[1]=0;
	strncpy(sSource,argv[9],6);sSource[6]=0;
	strncpy(sFileType,argv[10],10);sFileType[10]=0;
	
	iStartPos=iKeyLen=0;
	strcpy(sSplit,"");
	strcpy(sTargetName,"");
	if(argc==12) strcpy(sTargetName,argv[11]);
	if(argc==14){
		strncpy(sSplit,argv[11],9);sSplit[9]=0;
		iStartPos=atoi(argv[12]);
		iKeyLen=atoi(argv[13]);
	}

	strcpy(sSplitNew,"");
	
/**检查参数合法性*******/
	if(IsFile(sExprName)==FALSE){
		printf("公式文件%s无效.\n",sExprName);
		return -1;
	}
	if(IsFile(sFileName)==FALSE){
		printf("输入文件%s无效.\n",sFileName);
		return -1;
	}
	if(IsDir(sNormalDir)==FALSE){
		printf("输出正常目录%s无效.\n",sNormalDir);
		return -1;
	}
	if(IsDir(sErrDir)==FALSE){
		printf("输出异常目录%s无效.\n",sErrDir);
		return -1;
	}
	RegularDir(sNormalDir);
	RegularDir(sErrDir);
	
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

/*加载编译公式函数及参数*/	
	RegPrepVar();
	CheckSysVar=CheckPrepVar;
	if(WantBillExpr(sModule)){
		MoveAllShmToMem();
		InitTollTariffList(comp_toll_tariff_ticket);
		RegRateExprFun();
	}
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
/*将文件数据调用函数加载到内存*/
	if((l=OriFile2List(sFileName,&ptHead))<0){
		printf("加载文件%s到内存失败.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}
/*获取输入文件字节数*/
	iByte=FileSize(sFileName);
/*生成输出文件名*/
	GetBaseName(sFileName,sBaseName);
	if(strlen(sTargetName)!=0)GetBaseName(sTargetName,sBaseName);

	strcpy(sSourceID,sBaseName);
	TrimPrepName(sSourceID);
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		/**复位话单结构的当前输出链表{unlink pCur链表}*/
		ResetTicket();
		/**加载原始话单到指定的原始话单结构字段，设置原始话单长度*/
		iLen=MY_MIN(pTemp->iLen,sizeof(TICKET.sOri)-1);
		TICKET.iOriLen=	iLen;
		TICKET.sOri[iLen]=0;
		memset((void*)(TICKET.sOri),0,sizeof(TICKET.sOri)-1);
		memcpy((void*)(TICKET.sOri),pTemp->pData,iLen);
		/*释放话单*/
		free(pTemp);
	
		set_str_value("$FILENAME",pExprBuf,sSourceID);
		set_str_value("$FILEINFO",pExprBuf,sBaseName);
		GetHostTime(sNow);	
		set_str_value("$NOW",pExprBuf,sNow);
		set_str_value("$MSC",pExprBuf,sMsc);
		set_str_value("$AREACODE",pExprBuf,sAreaCode);
		set_str_value("$USERTYPE",pExprBuf,sUserType);
		set_str_value("$MODULE",pExprBuf,sModule);
		set_str_value("$FILETYPE",pExprBuf,sFileType);
		
		/*执行公式{这里可以获得pCur链表，link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			printf("执行公式%s失败.\n",sExprName);
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_str_value("$SUFFIXSTR",pExprBuf,sTemp);
		GetFixStrX(sTemp,0,20,sSuffixStr);
		if(strlen(sSuffixStr)==0)strcpy(sSuffixStr,"C");
		
		get_str_value("$ERRFIELD",pExprBuf,sErrField);
		/*生成标准输出话单*/
		GenStdTicket();

		/*ticketvalid属性
			<0:无效话单;
			0 :校验不通过异常话单供回收
			>0:正常话单
		*/
		/*对于属性校验不通过的错误话单，则将原始话单附在后面*/
		if(iTicketValid<0){
			iErrCnt++;

			l=GenStdErrTicket(FILEFMT.sFileType,sModule,sSource,
				sSourceID,sAreaCode,-iTicketValid,iCnt,TICKET.sOri,
				TICKET.iOriLen,sErrField,sStdErr);
			
			if(item2list(&pErr,sStdErr,l)<0){
				printf("生成错误话单链表错误.\n");
				return -1;
			}
			continue;
		}
		
		if(iTicketValid==0){/*0表示异常话单*/
			iAbnormalCnt++;
			if(item2list(&pAbnormal,TICKET.sStd,TICKET.iStdLen)<0){
				printf("生成异常话单链表错误.\n");
				return -1;
			}
		}
		else{
			iNormalCnt++;
			if(Item2OutListX(&pNormal,sSuffixStr,TICKET.sStd,
				TICKET.iStdLen,sSplitNew,sMsg)<0){
				printf("生成正常话单链表错误,信息%s.\n",sMsg);
				return -1;
			}
		}
	}

	DestroyBin(pExprBuf->pRoot);
	strncpy(sDataDate,sFileDataDate,8);sDataDate[8]=0;
	GetBaseNameX(sBaseName,sTempName);
	sprintf(sNormalName,"%s%s%s",sNormalDir,sDataDate,sTempName);
	sprintf(sAbnormalName,"%s%s.abn",sErrDir,sTempName);
	sprintf(sErrName,"%s%s.err",sErrDir,sTempName);

/*将输出的话单正序一下*/
	ReverseList((LIST**)&pErr);
	ReverseList((LIST**)&pAbnormal);

/*输出话单错误*/
	strcpy(sSplitNew,"");
	if(pErr!=NULL){
		if(list2file(&pErr,sErrName)<0){
			printf("写错误话单文件%s失败.\n",sErrName);
			return -1;
		}
		strcat(sSplitNew,"e");
	}
	if(pAbnormal!=NULL){
		if(list2file(&pAbnormal,sAbnormalName)<0){
			printf("写异常话单文件%s失败.\n",sAbnormalName);
			return -1;
		}
		strcat(sSplitNew,"a");
	}
	if(pNormal!=NULL){

		GetBaseName(sNormalName,sTempName);
		if(OutSplitList2File(pNormal,sNormalDir,sTempName,sSource,
			iWantCtl,sSplit,iStartPos,iKeyLen,sSplitNew)<0){
			printf("写正常话单文件%s失败.\n",sNormalName);
			return -1;
		}
	}
	printf("%s\t%d\t%d\t%d\t%d\t%d\t%s\n",
		sNormalName,iByte,iNormalCnt,iErrCnt,iAbnormalCnt,iCnt,sSplitNew);
	return 0;
}
int OriFile2List(char sFileName[],struct FileControlStruct **pptHead)
{
	
	int l;
	char *sFileType=FILEFMT.sFileType;
	struct FileFormatStruct *fmt=&FILEFMT;


	if(fmt->Blk.iRecLen==-1){
		fmt->Blk.iRecLen=FileSize(sFileName)
			-fmt->Blk.iHeadLen-fmt->Blk.iTailLen;
	}

	if(strcmp(sFileType,"bin")==0){	/*华为、Alcatel、贝尔等*/
		if(fmt->Rec.iRecLen>0&&fmt->Blk.iHeadLen==-1){
			l=BinFixFileToList(sFileName,fmt->Rec.iHeadLen,
				fmt->Rec.iRecLen,fmt->Rec.iTailLen,pptHead);
		}
		else{
			l=BinDynFileToList(sFileName,fmt,pptHead);
		}
	}
	else if(strcmp(sFileType,"blk")==0){
		if(fmt->Rec.iRecLen>0){
			l=BlkFixFileToList(sFileName,fmt->Rec.iHeadLen,
				fmt->Rec.iRecLen,fmt->Rec.iTailLen,pptHead);
		}
		else{
			l=BlkDynFileToList(sFileName,fmt,pptHead);
		}
	}
	else if(strcmp(sFileType,"asn")==0)	/*西门子、中兴、爱立信等*/
		l=AsnFileToList(sFileName,fmt,pptHead);
	else if(strcmp(sFileType,"asnhw")==0)
		l=AsnHwFileToList(sFileName,pptHead);
	else if(strcmp(sFileType,"txt")==0){	/*短信等格式*/

		int h=0,t=0;

		if(strcmp(fmt->sFormat,"txt1:0")==0||
			strcmp(fmt->sFormat,"txt1:1")==0) h=1;
		if(strcmp(fmt->sFormat,"txt0:1")==0||
			strcmp(fmt->sFormat,"txt1:1")==0) t=1;

		l=TxtFileToListX(sFileName,h,t,pptHead);
	}
	else if(strcmp(sFileType,"txttt")==0)/*文件格式把一个文件读成一条记录*/
		l=TxtttFileToList(sFileName,pptHead);
	else if(strcmp(sFileType,"nortel")==0)	/*北电格式专用*/
		l=NortelFileToList(sFileName,pptHead);
	else{
		printf("目前只支持asn,txt,txttt,bin,blk,nortel等格式.\n");
		return -1;
	}
	if(l<0){
		PushErrStackB("加载格式为%s的文件%s错误",
			fmt->sFormat,sFileName);
	}
	return l;
}
