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

int CompileExprFile(char sExprName[])
{
	int l;
	static char sPreExpr[256];
	char sInput[EXPRLEN],sMessage[1024];
	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];

/*��ʽ�ļ�����ͬ�򲻱���*/
	if(strcmp(sExprName,sPreExpr)==0) return 0;

	if(pExprBuf!=NULL){
		DestroyExprBuf(pExprBuf);
		pExprBuf=NULL;
	}
	strcpy(sPreExpr,sExprName);
	
/*����ʽ�ļ������ڴ�*/
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
	if(CompileExpr(sInput,asVarOutput,&l)<0){
		printf("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("���빫ʽ%s����::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
	return 0;
}

int ProcessVerifyFile(char sFileName[],char sNormalDir[],
	char sAbnormalDir[],char sResult[])
{
	int l,iRet,iTicketValid=0,iErrCode=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0;
	char sRecord[1024],sHostTime[15];
	char sNormalName[128],sAbnormalName[128],sBaseName[128];
	struct FileControlStruct *ptHead=NULL,*pTemp;
	struct FileControlStruct *pAbnormal=NULL,*pNormal=NULL;

/*���ļ����ݵ��ú������ص��ڴ�*/
	if(TxtFileToList(sFileName,&ptHead)<0){
		sprintf(sResult,"�����ļ�%s���ڴ�ʧ��.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}
	GetBaseName(sFileName,sBaseName);
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		iCnt++;
		
		/**��λ�����ṹ�ĵ�ǰ�������{unlink pCur����}*/
		ResetTicket();
		/**����ԭʼ������ָ����ԭʼ�����ṹ�ֶΣ�����ԭʼ��������*/
		TICKET.iOriLen=	pTemp->iLen;
		TICKET.sOri[pTemp->iLen]=0;
		memcpy((void*)(TICKET.sOri),pTemp->pData,pTemp->iLen);
			
		set_str_value("$FILENAME",pExprBuf,sBaseName);
		GetHostTime(sHostTime);	
		set_str_value("$NOW",pExprBuf,sHostTime);
		
		/*ִ�й�ʽ{������Ի��pCur����link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			printf("ִ�й�ʽ����,%d.\n",iRet);
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_int_value("errcode",pExprBuf,&iErrCode);
			
	/*��������*/

		if(iErrCode<0){
			iAbnormalCnt++;
			l=sprintf(sRecord,"%s%04d\n",TICKET.sOri,-iErrCode);
			if(item2list(&pAbnormal,sRecord,l)<0){
				printf("���ɴ��󻰵��������.\n");
				return -1;
			}
		}
		else{
		
			if(iTicketValid<0){
				iNormalCnt++;
				l=sprintf(sRecord,"%s\n",TICKET.sOri);
				if(item2list(&pNormal,sRecord,l)<0){
					printf("�������������������.\n");
					return -1;
				}	
			}
			else{
				iNormalCnt++;
				GenStdTicket();
				if(item2list(&pNormal,TICKET.sStd,TICKET.iStdLen)<0){
					printf("�������������������.\n");
					return -1;
				}	
			}
		}
			

		/*�ͷ��ڴ�*/
		free(pTemp);
	}
	
	
	DestroyBin(pExprBuf->pRoot);
	strcpy(sNormalName,"NULL");
	strcpy(sAbnormalName,"NULL");
/**д�����쳣����********/
	if(pAbnormal!=NULL){
	/*������Ļ�������һ��*/
		ReverseList((LIST**)&pAbnormal);
		sprintf(sAbnormalName,"%s.abn",sBaseName);
		strcat(sAbnormalDir,sAbnormalName);
		if(list2file(&pAbnormal,sAbnormalDir)<0){
			sprintf(sResult,"д�쳣�����ļ�%sʧ��.\n",sAbnormalDir);
			return -1;
		}
	}

/**д������������********/
	if(pNormal!=NULL){
	/*������Ļ�������һ��*/
		ReverseList((LIST**)&pNormal);
		sprintf(sNormalName,"%s.nor",sBaseName);
		strcat(sNormalDir,sNormalName);
		if(list2file(&pNormal,sNormalDir)<0){
			sprintf(sResult,"д���������ļ�%sʧ��.\n",sNormalDir);
			return -1;
		}
	}
	printf("%s\t%s\t%d\t%d\n",sNormalName,sAbnormalName,iNormalCnt,iAbnormalCnt);
	return 0;
}

int main(int argc,char *argv[])
{
	int i;
	char sExprName[128],sFileName[128];
	char sNormalDir[128],sAbnormalDir[128];
	char sResult[1024];
	
	if(argc!=5){
		printf("Usage %s input expr normaldir abnormaldir.\n",argv[0]);
		return -1;
	}
/*��ʼ����������*/
	InitAppRes(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sExprName,argv[2]);
	strcpy(sNormalDir,argv[3]);
	strcpy(sAbnormalDir,argv[4]);

/**�������Ϸ���*******/
	if(IsFile(sFileName)==FALSE){
		printf("�����ļ�%s��Ч.\n",sFileName);
		return -1;
	}
	if(IsDir(sNormalDir)==FALSE){
		printf("�������Ŀ¼%s��Ч.\n",sNormalDir);
		return -1;
	}
	if(IsDir(sAbnormalDir)==FALSE){
		printf("����쳣Ŀ¼%s��Ч.\n",sAbnormalDir);
		return -1;
	}
	RegularDir(sNormalDir);
	RegularDir(sAbnormalDir);
	
/*���빫ʽ*/
	if(CompileExprFile(sExprName)<0) return -1;
		
/*���������������ļ�*/
	i=ProcessVerifyFile(sFileName,sNormalDir,sAbnormalDir,sResult);
/*��ӡ������*/
	printf(sResult);

	return i;
}
