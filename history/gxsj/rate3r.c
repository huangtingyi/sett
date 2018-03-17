#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwtiny.h>
#include <bintree.h>
#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <ticket_field.h>
#include <tariff_disct.h>

#include <ticket.h>
#include "user_ticket.h"


int ProcessTicket(struct FileControlListStruct *pList);
int WriteTicketToFile(struct FileControlListStruct *pList,
	char sNormalDir[],char sBaseName[],char sSplitStr[]);
	
int cmitem_bill3r(void *pSource,void *pTarget)
{
	int res=0,iPos,iLen;
	struct FDataTicketBStruct *pTicket=pSource;
	char *p1,*p2;
	
	/*���Ƚ�roam_type,distance_type,opp_ip_type,
	opp_toll_type1,opp_toll_type2,calling_type_id,
	called_type_id,ticket_type_id,roam_fee        
	toll_fee,add_fee�ֶ�*/
	
	p1 = pTicket->sRoamType;
	p2 = pTicket->sOriTypeID;
	iLen = p2-p1+1;
	iPos=p1-(char *)pTicket;
	if ((res=strncmp((char *)pTicket+iPos,(char *)pTarget+iPos,iLen))!=0)
		return res;
		  
	return res;
                  
}

int main(int argc,char *argv[])
{
	FILE *fp;
	int i,l,iRet,iTicketValid=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0,iMissCnt=0;
	
	char sRecord[1024],sTemplateRule[128],sInput[EXPRLEN],sModule[4];
	char  sAbnormalName[128],sFileName[128],sBaseName[128],sNow[15];
	char sNormalDir[128],sErrDir[128],sSplitNew[20],sExprName[128];
	char sSplitStr[10],sVisitAreaCode[10],sTempName[128],sAreaCode[6],*pc;

	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	struct FileControlStruct *ptHead=NULL,*pTemp,*pAbnormal=NULL,FTemp;
	struct TollTariffStruct *pTollTariff;
	struct DisctRuleStruct *pDisctRule;
	
	char sTableName[31],sCondition[256],*p1,*p2;
	int iLen;
	struct DataTicketBStruct	Temp,TempResult;
	struct DataTicketBStructIn	TempIn;
	struct FDataTicketBStruct	FTicket;

	struct UDataTicketBStruct TempUDtt;
	struct UDataTicketBStructUp TempUp;	
	
	if(argc!=9&&argc!=10){
		printf("Usage %s tablename normaldir errdir expr"
		"templateid splitstr visitcode module wherecause.\n",argv[0]);
		return -1;
	}
/*��ʼ����������*/
	InitAppRes(argv[0]);
	
	GetHostTime(sNow);
	sprintf(sFileName,"BILL3R%s.PRE",sNow+2);
	GetBaseName(sFileName,sBaseName);sBaseName[19]=0;
	
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[9]);

	strcpy(sNormalDir,argv[2]);
	strcpy(sErrDir, argv[3]);
	strcpy(sExprName,argv[4]);
	strcpy(sTemplateRule,argv[5]);
	strcpy(sSplitStr,argv[6]);
	if(strlen(sSplitStr)>1||strlen(sSplitStr)==0){
		printf("����ֻ֧��һ����������,%s��Ч.\n",sSplitStr);
		return -1;
	}
	strcpy(sVisitAreaCode,argv[7]);
	strncpy(sModule,argv[8],3);sModule[3]=0;

	strncpy(sAreaCode,sVisitAreaCode,5);sAreaCode[5]=0;

/**�������Ϸ���*******/
	if(IsFile(sExprName)==FALSE){
		printf("��ʽ�ļ�%s��Ч.\n",sExprName);
		return -1;
	}
	if(IsDir(sNormalDir)==FALSE){
		printf("�������Ŀ¼%s��Ч.\n",sNormalDir);
		return -1;
	}
	if(IsDir(sErrDir)==FALSE){
		printf("����쳣Ŀ¼%s��Ч.\n",sErrDir);
		return -1;
	}
	RegularDir(sNormalDir);
	RegularDir(sErrDir);
/*�������ڴ��л�ȡ��Ҫ�Ĳ���*/
	MoveAllShmToMem();

/*���������б�*/
	InitFileControlList(sTemplateRule,sSplitStr,&pFileControlList);
/*�����ʷ�����*/
	pTollTariff=InitTollTariffList(comp_toll_tariff_ticket);
/*�����Ż�����*/
	pDisctRule=InitDisctRuleList(comp_disct_rule_ticket01);
		
/*����ʽ�ļ������ڴ�*/
	if((l=FileSize(sExprName))>=EXPRLEN){
		printf("�����ļ�%s����%d,%d.\n",sExprName,EXPRLEN,l);
		return -1;
	}
	fp=fopen(sExprName,"r");
	if(fread(sInput,l,1,fp)!=1){
		printf("���ļ�%sʧ��.\n",sExprName);
		fclose(fp);
		return -1;
	}
	sInput[l]=0;
	fclose(fp);
/*���ر��빫ʽ����������*/	
	RegPrepVar();
	RegRateExprFun();
	RegRate2ExprFun();
	RegShmUserDataExprFun();
	CheckSysVar=CheckPrepVar;
/*���빫ʽ*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	
/*��ʼ��select��update�ṹ����*/
	bzero((void*)&TempIn,sizeof(struct DataTicketBStructIn));
	TempIn.iFirstFlag=true;
	TempIn.iBufEmpty =true;
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,sCondition);
	
	bzero((void*)&TempUp,sizeof(struct UDataTicketBStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
/**�������ݿ�***/
	if(IniConnect("dataconnstr")<0) return -1;
	
	while(EGetDataTicketBToStruct(&Temp,&TempIn)==true){
		
		/*����¼�Ƶ��ڴ棬������pTempֵ���������������*/
		mvitem_mfdataticketb(&Temp,&FTicket);
		FTemp.pData = &FTicket;
		FTemp.iLen = sizeof(struct FDataTicketBStruct);
		pTemp = &FTemp;	

		iCnt++;		
		/**��λ�����ṹ�ĵ�ǰ�������{unlink pCur����}*/
		ResetTicket();
		/**����ԭʼ������ָ����ԭʼ�����ṹ�ֶΣ�����ԭʼ��������*/
		TICKET.iOriLen=	pTemp->iLen;
		TICKET.sOri[pTemp->iLen]=0;
		memcpy((void*)(TICKET.sOri),pTemp->pData,pTemp->iLen);
	
		set_str_value("$FILENAME",pExprBuf,sBaseName);
		GetHostTime(sNow);	
		set_str_value("$NOW",pExprBuf,sNow);
		set_str_value("$SPLITTYPE",pExprBuf,sSplitStr);
		set_str_value("$AREACODE",pExprBuf,sVisitAreaCode);
		set_str_value("$ACTION",pExprBuf,"billr");

		/*ִ�й�ʽ{������Ի��pCur����link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			printf("���ɴ��󻰵��������.\n");
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		
		if(iTicketValid==-1)continue;
		
		/*ֱ�Ӻ��Ե���Ч����*/
		if(iTicketValid<=0){

			iAbnormalCnt++;

			if((l=mvitem2commerr(pTemp,-iTicketValid,
				sBaseName,sModule,sAreaCode,sRecord))>1024){
				printf("������¼̫��.\n");
				return -1;
			}
			if(item2list(&pAbnormal,sRecord,l)<0){
				printf("�����쳣�����������.\n");
				return -1;
			}
			continue;
		}
		
		/*�����������.*/
		GenStdTicket();

		/*�Ƚ�����ǰ��Ļ���*/
		if(cmitem_bill3r(pTemp->pData,TICKET.sStd)==0){
			iMissCnt++;
			continue;
		}
		
		/*���µ����ݿ�*/
		mvitem_fmdataticketb((struct FDataTicketBStruct *)TICKET.sStd,&TempResult);
		strcpy(TempResult.sRowID,Temp.sRowID);
		mvitem_dataticketb2up(&TempResult,&TempUDtt);		
		if(EUpdateStructToUDataTicketB(&TempUDtt,false,&TempUp)<0){
			WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
			return -1;
		}		

		/*����������컰���б�*/
		if((iRet=ProcessTicket(pFileControlList))<0){
			printf("������ʧ�ܣ��ļ�%s.\n",sFileName);
			return -1;
			
		}
		
		iNormalCnt++;
	}
	if(EUpdateStructToUDataTicketB(NULL,true,&TempUp)<0){
		WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
		return -1;
	}
	CommitWork();	
	
	GetBaseName(sFileName,sBaseName);
	strcpy(sTempName,sBaseName);
	if((pc=strstr(sTempName,".tmp"))!=NULL) *pc=0;
		
	strcpy(sSplitNew,"");

/**д�����쳣����********/
	if(pAbnormal!=NULL){
						
		sprintf(sAbnormalName,"%s%s.a.tmp",sErrDir,sTempName);
		if(list2file(&pAbnormal,sAbnormalName)<0){
			printf("д�쳣�����ļ�%sʧ��.\n",sAbnormalName);
			return -1;
		}
		strcat(sSplitNew,"a");	
	}

/*д������Ӫ�̻���*/
	if(WriteTicketToFile(pFileControlList,sNormalDir,sTempName,sSplitNew)<0){
		printf("�����ļ�%s��������ļ�ʧ��.\n",sFileName);
		return -1;
	}
	printf("%s\t%s\t%d\t%d\t%d\n",sTempName,sSplitNew,iCnt,iNormalCnt,iAbnormalCnt);
	
	DistroyAllMem();	
	printf("��������ɹ�.\n");	
	DisconnectDatabase();
	
	return 0;
}
int WriteTicketToFile(struct FileControlListStruct *pList,
	char sNormalDir[],char sBaseName[],char sSplitStr[])
{
	char sNormalName[128],sRawName[128];
	
	strcpy(sRawName,sBaseName);
	
/*	if((pc=strchr(sRawName,'.'))!=NULL) *pc=0;*/

	while(pList!=NULL){
		if(pList->iCnt!=0){
			sprintf(sNormalName,"%s%s.%s.tmp",sNormalDir,
				sRawName,pList->sSplitType);
			if(list2file(&(pList->pHead),sNormalName)<0){
				printf("д���������ļ�%sʧ��.\n",sNormalName);
				return -1;
			}
			strcat(sSplitStr,pList->sSplitType);
		}
		pList=pList->pNext;
	}
	return 0;
}
int ProcessTicket(struct FileControlListStruct *pList)
{
	struct FileControlListStruct *pTemp;
		
	while(pList!=NULL){
	
		pTemp=pList;
		pList=pList->pNext;
		
		/*GenStdTicket();*/
		pTemp->iCnt++;
		if(item2list(&(pTemp->pHead),TICKET.sStd,TICKET.iStdLen)<0){
			printf("�������������������.\n");
			return -1;
		}
	}
	return 0;
}
