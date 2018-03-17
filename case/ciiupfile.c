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

/*У�������ļ���*/
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
	
/**�������ݿ�***/
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

/*��ȡ������*/
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
		WriteAlertPrint("�ļ� %s �ļ�����ʽ����.",sFileName);
		return -1;
	}
	
	/*��ʼ�����۲���*/
	MoveAllShmToMem();
	
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
		
	bzero((void*)&SttTicket,sizeof(struct SttTicketStruct));
	bzero((void*)&SttTicketIn,sizeof(struct SttTicketStructIn));
	
	SttTicketIn.iBufEmpty=TRUE;
	SttTicketIn.iFirstFlag=TRUE;
	strcpy(SttTicketIn.sTableName,sTableName);
	strcpy(SttTicketIn.sCondition,sCondition);
	
	/*��ȡ������*/
	while(EGetSttTicketToStruct(&SttTicket,&SttTicketIn)){
		int static isFirst=0;
		
		/*���˷ǹ��ʻ������� (IMSI��46000,46001,46100��ͷ)*/
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
		/*������ת�浽TICKETȫ�ֱ����У���ʽ��ֱ��ʹ�ü���*/
		TICKET.iOriLen=strlen(sOriLineIn);
		strcpy(TICKET.sOri,sOriLineIn);
		
		set_str_value("$FILENAME",pExprBuf,sFileName);
		set_str_value("$MODULE",pExprBuf,"VIT");
		set_str_value("$NOW",pExprBuf,sHostTime);
		set_str_value("$SPLITTYPE",pExprBuf,"5");
		set_str_value("$AREACODE",pExprBuf,":9999");
		
		/*ִ�й�ʽ{������Ի��pCur����link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			WriteAlertPrint("ִ�й�ʽ����");
			return -1;
		}
		
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);

		if(iTicketValid<=0){
			continue;				
		}
		
		iCnt++;
		/*����ʽ������������TICKET.sStdȫ�ֱ�����*/
		
		/*��������ݴ����ļ�������*/
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
	/*�����ļ�����������д���ļ���  sTotalCnt*/
	sprintf(sFileHead,"10%s%s00%s02%s%s%s%06d%015d%135s\n",sCityCode,sType,sSeq,sCreateTime,
		sBeginTime,sEndTime,iCnt,iTollFee," ");
		
	if(SetFileInfo(&pList,sFileHead)<0){
		WriteAlertPrint("�����ļ�ͷʧ��.");
		return -1;
	}
	
	list2file(&pList,sFileName);
	
	DisconnectDatabase();
	
	/*��ӡ����Ϣ*/
	printf("�Ա�%s����,����ļ�%s,����%d������\n",
		sTableName,sFileName,iCnt);
		
	return 0;	
}


