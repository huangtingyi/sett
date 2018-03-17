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
#include "gen_supp.h"

/*校验输入文件名*/
int CheckFileName(char sFileName[])
{
	int i=0;
	if(strlen(sFileName)!=16) return -1;

	char sType[4]="",sTime[15]="",sCityCode[5]="",sCheckCityCode[4]="0";
	
	strncpy(sType,sFileName,3);
	sType[3]=0;
	GetHostTime(sTime);
	strncpy(sTime+2,sFileName+3,6);
	strncpy(sCityCode,sFileName+12,4);
	sCityCode[4]=0;
	
	if((strcmp(sType,"TII")!=0&&strcmp(sType,"CII")!=0)||(ChkTime(sTime)<0)) return -1;
		
	if(sCityCode[0]!='.') return -1;
	
/**连接数据库***/
	if(IniConnect("paramconnstr")<0) return -1;
				
	struct AreaCodeDescStruct AreaCodeDesc;
	struct AreaCodeDescStructIn AreaCodeDescIn;
	bzero((void*)&AreaCodeDesc,sizeof(struct AreaCodeDescStruct));
	bzero((void*)&AreaCodeDescIn,sizeof(struct AreaCodeDescStructIn));
	
	AreaCodeDescIn.iBufEmpty=TRUE;
	AreaCodeDescIn.iFirstFlag=TRUE;
	strcpy(AreaCodeDescIn.sTableName,"AREA_CODE_DESC");
	strcpy(AreaCodeDescIn.sCondition,
		"where area_code=capital_area_code and city_code is not null");	

/*读取表数据*/
	while(EGetAreaCodeDescToStruct(&AreaCodeDesc,&AreaCodeDescIn)){
		strncpy(sCheckCityCode+1,AreaCodeDesc.sCityCode,2);
		if(strcmp(sCityCode+1,sCheckCityCode)==0)
			i++;	
	}
	
	if(i==0) return -1;
		
	return 0;
}
int SetFileInfo(struct FileControlStruct **pFileControl,char sInfo[])
{
	int i=0;
	
	if((i=strlen(sInfo))<=0) return -1;
	
	item2list(pFileControl,(void*)sInfo,i);
	
	return 0;
}

int main(int argc,char **argv)
{
	char	sFileName[128]="",sCondition[1024]="",sTableName[41]="",sExprName[128]="";
	char	sInput[EXPRLEN],msg[1024]="",sOriLineIn[1024]="",sOriLineOut[1024]="";
	char	sFileHead[1024]="",sCityCode[4]="",sType[4]="",sSeq[6]="";
	char	sHostTime[15]="",sBeginTime[15],sEndTime[15],sFee[10]="",sCreateTime[9];
	int 	l,i=0,iRet=0,iTicketValid=0,iTollFee=0;
	int	iCnt=0;
	
	struct FileControlStruct *pList=NULL;
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	struct SttTicketStruct SttTicket;
	struct SttTicketStructIn SttTicketIn;
	
	if(argc!=5){
		printf("Usage: %s filename wherecause tablename exprname.\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	GetHostTime(sHostTime);
	strcpy(sFileName,argv[1]);
	strcpy(sCondition,argv[2]);
	strcpy(sTableName,argv[3]);
	strcpy(sExprName,argv[4]);
	
	strncpy(sCityCode,sFileName+13,3);
	sCityCode[4]=0;
	strncpy(sType,sFileName,3);
	sType[3]=0;
	strncpy(sSeq,sFileName+9,3);
	sSeq[5]=0;
	
	if(CheckFileName(sFileName)<0){
		WriteAlertPrint("文件 %s 文件名格式错误.",sFileName);
		return -1;
	}
	
	/*初始化批价参数*/
	MoveAllShmToMem();
	
	/*将公式读到内存*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,msg)!=0){
		WriteAlertPrint("读文件%s失败:%s",sExprName,msg);
		return -1;
	}
/*加载编译公式函数及参数*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		WriteAlertPrint("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;
		
	bzero((void*)&SttTicket,sizeof(struct SttTicketStruct));
	bzero((void*)&SttTicketIn,sizeof(struct SttTicketStructIn));
	
	SttTicketIn.iBufEmpty=TRUE;
	SttTicketIn.iFirstFlag=TRUE;
	strcpy(SttTicketIn.sTableName,sTableName);
	strcpy(SttTicketIn.sCondition,sCondition);
	
	/*读取表数据*/
	while(EGetSttTicketToStruct(&SttTicket,&SttTicketIn)){
		int static isFirst=0;
		
		/*过滤非国际话单话单 (IMSI以46000,46001,46100开头)*/
		if(strncmp(SttTicket.sImsi,"46000",5)==0
			||strncmp(SttTicket.sImsi,"46001",5)==0
			||strncmp(SttTicket.sImsi,"46100",5)==0){
			continue;
		}
		
		if(isFirst==0){
			strcpy(sBeginTime,SttTicket.sStartTime);
			strcpy(sEndTime,SttTicket.sStartTime);
			sBeginTime[14]='\0';
			sEndTime[14]='\0';
			isFirst++;
			
		}else{
			if(strncmp(sBeginTime,SttTicket.sStartTime,14)>=0){
				strcpy(sBeginTime,SttTicket.sStartTime);
				sBeginTime[14]='\0';
			}
			if(strncmp(sEndTime,SttTicket.sStartTime,14)<0){
				strcpy(sEndTime,SttTicket.sStartTime);
				sEndTime[14]='\0';
			}
		}
			
		mvitem_mfsttticket(&SttTicket,(struct FSttTicketStruct *)sOriLineIn);
		/*将数据转存到TICKET全局变量中，公式可直接使用即可*/
		TICKET.iOriLen=strlen(sOriLineIn);
		strcpy(TICKET.sOri,sOriLineIn);
		
		set_str_value("$FILENAME",pExprBuf,sFileName);
		set_str_value("$MODULE",pExprBuf,"VIT");
		set_str_value("$NOW",pExprBuf,sHostTime);
		set_str_value("$SPLITTYPE",pExprBuf,"5");
		set_str_value("$AREACODE",pExprBuf,":9999");
		
		/*执行公式{这里可以获得pCur链表，link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			WriteAlertPrint("执行公式错误");
			return -1;
		}
		
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);

		if(iTicketValid<=0){
			continue;				
		}
		
		iCnt++;
		/*经公式计算后的数据在TICKET.sStd全局变量中*/
		
		/*将结果数据存入文件链表中*/
		GenStdTicket();
		strcpy(sOriLineOut,TICKET.sStd);
		i=strlen(sOriLineOut);

		strncpy(sFee,sOriLineOut+159,9);
		sFee[9]='\0';
		iTollFee+=atoi(sFee);
		
		item2listtail(&pList,(void*)sOriLineOut,i);
		
	}
	strncpy(sCreateTime,sHostTime,8);
	sCreateTime[8]='\0';
	/*生成文件名并将数据写入文件中  sTotalCnt*/
	sprintf(sFileHead,"10%s%s00%s02%s%s%s%06d%015d%135s\n",sCityCode,sType,sSeq,sCreateTime,
		sBeginTime,sEndTime,iCnt,iTollFee," ");
		
	if(SetFileInfo(&pList,sFileHead)<0){
		WriteAlertPrint("设置文件头失败.");
		return -1;
	}
	
	list2file(&pList,sFileName);
	
	DisconnectDatabase();
	
	/*打印出信息*/
	printf("对表%s处理,输出文件%s,生成%d条话单\n",
		sTableName,sFileName,iCnt);
		
	return 0;	
}


