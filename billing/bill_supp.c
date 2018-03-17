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
#include <stt_ticket.h>

#include <bill_supp.h>

struct	MobTicketStruct Ticket;
struct FileControlStruct *pDup=NULL;
void (*InitMsisdnOtherParty)(struct MobTicketStruct *p);
int (*comp_insert_list_dup_key_e)(LIST *pValue,LIST*pHead);
void (*mvitem_ticket2dup)(struct FPrepTicketStruct *pi,struct DupKeyStruct *po);

int ProcessRateTicket(struct FileControlListStruct *ptHead,char sAreaCode[],
	char sBaseName[],char sModule[],struct FileControlStruct *pRec,
	char sSplitNew[],int *piErrCode,int *piErrInfo)
{
	int iRet,iTicketValid=0,iErrCode=0,iErrInfo=0,iNullFlag=false;
	char	sHostTime[15],msg[1024],sTemp[256];
	struct FileControlListStruct *pTemp;
	
	/**��������ָ����TEMPLATE_RULE_ID��SPLIT_TYPE,�����ñ�ʶ*/
	if(CountList((LIST*)ptHead)==1){
		if(ptHead->pSplitRule==NULL) iNullFlag=true;
	}

	/**��λ�����ṹ�ĵ�ǰ�������{unlink pCur����}*/
	ResetTicket();
	/**����ԭʼ������ָ����ԭʼ�����ṹ�ֶΣ�����ԭʼ��������*/
	TICKET.iOriLen=	pRec->iLen;
	TICKET.sOri[pRec->iLen]=0;
	memcpy((void*)(TICKET.sOri),pRec->pData,pRec->iLen);

	strcpy(sSplitNew,"");
	*piErrCode=0;

	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		set_str_value("$FILENAME",pExprBuf,sBaseName);
		GetHostTime(sHostTime);	
		set_str_value("$NOW",pExprBuf,sHostTime);
		set_str_value("$SPLITTYPE",pExprBuf,pTemp->sSplitType);
		set_str_value("$AREACODE",pExprBuf,sAreaCode);
		set_str_value("$MODULE",pExprBuf,sModule);
		
		
		/*ִ�й�ʽ{������Ի��pCur������link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			printf("ִ�й�ʽ����,%d.\n",iRet);
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_str_value("$SUFFIXSTR",pExprBuf,sTemp);
		GetFixStrX(sTemp,0,20,SUFFIX_STR);
		
		get_str_value("$ERRINFO",pExprBuf,sTemp);
		if(iErrInfo==0) iErrInfo=atoi(sTemp);

		/*���󻰵����������󻰵���Ӧ��continue*/
		if(iTicketValid<=0){
			iErrCode=-iTicketValid;
			break;
		}
/**��������ָ����TEMPLATE_RULE_ID��SPLIT_TYPE,��ƥ���Ϸ���ģ������*/
		if(iNullFlag==true||GetMultiSplitRule(pTemp)!=NULL){

			GenStdTicket();

			if((pTemp->iCnt=Item2OutList(&(pTemp->pHead),
				pTemp->sSplitType,TICKET.sStd,TICKET.iStdLen,
				sSplitNew,msg))<0){
				printf("��������������������,��Ϣ:%s.\n",msg);
				return -1;
			}
			break;
		}
	}
	*piErrCode=	iErrCode;
	*piErrInfo=	iErrInfo;
	return 0;
}
int ProcessRateFile(char sFileName[],char sVisitAreaCode[],char sModule[],
	char sNormalDir[],char sErrDir[],char sSource[],int iWantCtl,
	char sSplit[],int iStartPos,int iKeyLen,
	struct FileControlListStruct *pControlList,char sResult[])
{
	/*����һ���ļ�iErrInfoֻ��һ��ȡֵ*/
	int l,iErrCode=0,iErrInfo=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0;
	char  sRecord[1024],sSplitNew[21],sTempName[128];
	char  sAbnormalName[128],sBaseName[128];
	struct FileControlStruct *ptHead=NULL,*pTemp,*pAbnormal=NULL;
	
	int h=0,t=0;
	char *fmt=FILEFMT.sFormat;

	if(strcmp(fmt,"txt1:0")==0||strcmp(fmt,"txt1:1")==0) h=1;
	else if(strcmp(fmt,"txt0:1")==0||strcmp(fmt,"txt1:1")==0) t=1;
	
/*���ļ����ݵ��ú������ص��ڴ�*/
	if(TxtFileToListX(sFileName,h,t,&ptHead)<0){
		sprintf(sResult,"�����ļ�%s���ڴ�ʧ��.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}

	GetBaseName(sFileName,sBaseName);sBaseName[19]=0;
	
	while(ptHead!=NULL){
		
		iCnt++;

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		/*������������б�*/
		if(ProcessRateTicket(pControlList,sVisitAreaCode,sBaseName,
			sModule,pTemp,sSplitNew,&iErrCode,&iErrInfo)<0){
			sprintf(sResult,"��������ʧ�ܣ��ļ�%s.\n",sFileName);
			return -1;
			
		}
		if(strlen(sSplitNew)==0){

			if(iErrCode==0) iErrCode=-INVALID_SPLIT_RULE;

			if(iErrInfo==0){
				if((l=mvitem2commerr((char*)pTemp->pData,
					pTemp->iLen,iErrCode,sBaseName,
					sModule,sVisitAreaCode,sRecord))>1024){
					sprintf(sResult,"������¼̫��.\n");
					return -1;
				}
			}
			else{
				if((l=mvitem2err((char*)pTemp->pData,pTemp->iLen,
					iErrCode,sRecord))>1024){
					sprintf(sResult,"������¼̫��.\n");
					return -1;
				}
			}
			if(item2list(&pAbnormal,sRecord,l)<0){
				sprintf(sResult,"�����쳣������������.\n");
				return -1;
			}
			iAbnormalCnt++;
		}
		else	iNormalCnt++;
		/*�ͷ��ڴ�*/
		free(pTemp);
	}
	
	GetBaseNameX(sFileName,sTempName);
		
	strcpy(sSplitNew,"");

/**д�����쳣����********/
	if(pAbnormal!=NULL){
		
		ReverseList((LIST**)&pAbnormal);		
		sprintf(sAbnormalName,"%s%s.a.tmp",sErrDir,sTempName);
		if(list2file(&pAbnormal,sAbnormalName)<0){
			sprintf(sResult,"д�쳣�����ļ�%sʧ��.\n",sAbnormalName);
			return -1;
		}
		strcat(sSplitNew,"a");	
	}

/*д������Ӫ�̻���*/
	if(WriteTicketToFile(pControlList,sNormalDir,sTempName,
		sSource,iWantCtl,sSplit,iStartPos,iKeyLen,sSplitNew)<0){
		sprintf(sResult,"�����ļ�%s��������ļ�ʧ��.\n",sFileName);
		return -1;
	}
	sprintf(sResult,"%s%s\t%s\t%d\t%d\t%d\n",sNormalDir,
		sTempName,sSplitNew,iCnt,iNormalCnt,iAbnormalCnt);
	return 0;
}

/*�����ݵ���*/
void InitParamMem()
{
/*�������ڴ��л�ȡ��Ҫ�Ĳ���*/
	MoveAllShmToMem();

/*�����ʷ�����*/
	InitTollTariffList(comp_toll_tariff_ticket);
}
void DestroyParamMem()
{
	DistroyAllMem();
}
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

int WantWriteErrTicket(struct MobTicketStruct *p,int iFlag)
{
	if(iFlag==true){
		if(strcmp(p->sCallType,"01")!=0&&
			strcmp(p->sCallType,"02")!=0&&
			strcmp(p->sCallType,"03")!=0)  return false;
	}
	else{
		if(strcmp(p->sCallType,"01")==0||
			strcmp(p->sCallType,"02")==0||
			strcmp(p->sCallType,"03")==0) return false;
	}
	return true;
}
int mvitem2preperr(struct FileControlStruct *pTemp,
	int iErrCode,char sRecord[512])
{
	int l,i;
	char	*pc=(char*)(pTemp->pData),sTemp[5];
	struct FPrepTicketStruct *p=(struct FPrepTicketStruct*)sRecord;

	l=sizeof(struct FPrepTicketStruct);
	if(pTemp->iLen>l) return -1;

	sprintf(sTemp,"%04d",iErrCode);

	for(i=0;i<l;i++){
		if(i<pTemp->iLen){
			if(pc[i]=='\n')	sRecord[i]=' ';
			else		sRecord[i]=pc[i];
		}
		else	sRecord[i]=' ';
	}
	memcpy((void*)(p->sErrCode),(void*)sTemp,4);
/*	i=strlen(sFileName);if(i>19)i=19;
	memcpy((void*)(p->sFileName),(void*)sFileName,i);
	memcpy((void*)(p->sModule),(void*)sModule,strlen(sModule));
	memcpy((void*)(p->sAreaCode),(void*)sAreaCode,strlen(sAreaCode));
*/	
	sRecord[l++]='\n';
	sRecord[l]=0;

	return l;
}
int GetFullFlag(char sSplitStr[])
{
	if(atoi(sSplitStr)!=0) return false;
	if(strchr(sSplitStr,'B')!=NULL&&
		strchr(sSplitStr,'C')!=NULL) return true;
	return false;
}

void InitSttMsisdnOtherParty(struct MobTicketStruct *p)
{
	/*�������ı��л�����Ҫ��ת����*/
	if(strcmp(p->sCallType,"02")==0){
		strncpy(p->sMsisdn,p->sCalledNbr,15);
		strncpy(p->sOtherParty,	p->sCallingNbr,15);
		p->sOtherParty[15]=0;
	}
	else{
		strcpy(p->sMsisdn,p->sCallingNbr);
		strcpy(p->sOtherParty,	p->sCalledNbr);
	}
	
}
void ModifyVPNOtherParty(struct MobTicketStruct *p)
{
	char sVpnGrpID[16];
	struct ICommSearchStruct *pTemp;

	if(strcmp(p->sCallType,"01")!=0) return;

	if(strlen(p->sOtherParty)>6||
		p->sOtherParty[0]=='0') return;	

	if(SearchCommTrie("SERV_VPN",0,p->sMsisdn,p->sStartTime,&pTemp)
		==NOTFOUND) return;

	GetStrValFromCSX(pTemp,15,sVpnGrpID);

	if(SearchCommBin("VPN_ACC_NBR_ANTI",atoi(p->sOtherParty),sVpnGrpID,
		p->sStartTime,&pTemp)==NOTFOUND) return;

	strcpy(p->sReserve,p->sOtherParty);
	
	GetStrValFromCSX(pTemp,24,p->sOtherParty);
}
void InitBilMsisdnOtherParty(struct MobTicketStruct *p)
{
	/*�������ı��л�����Ҫ��ת����*/
	strcpy(p->sMsisdn,p->sCallingNbr);
	strcpy(p->sOtherParty,	p->sCalledNbr);

	if(strncmp(p->sAreaCode,"93",2)==0||strncmp(p->sAreaCode,"94",2)==0)
		ModifyVPNOtherParty(p);
}
void mvitem_stt2dup(struct FPrepTicketStruct *pi,struct DupKeyStruct *po)
{
	int l=0;
	char	sTemp[32];

	bzero((void*)po,sizeof(struct DupKeyStruct));

	strncpy(po->sCallType,	pi->sCallType,2);
	if(strcmp(po->sCallType,"02")==0){
		strncpy(po->sMsisdn,	pi->sOtherParty,15);
		strncpy(sTemp,	pi->sMsisdn,15);sTemp[15]=0;
	}
	else{
		strncpy(po->sMsisdn,	pi->sMsisdn,15);
		strncpy(sTemp,	pi->sOtherParty,24);sTemp[24]=0;
	}
	AllTrim(po->sMsisdn);
	AllTrim(sTemp);
	
	l=0;
	if(sTemp[0]=='0'){
		struct AreaCodeDescStruct *pTemp;
		if(SearchAreaCodeDesc(sTemp+1,&pTemp)==FOUND)
			l=strlen(pTemp->sAreaCode)+1;
	}

	strcpy(po->sOtherParty,sTemp+l);

	po->sOtherParty[12]=0;
	strncpy(sTemp,  pi->sTrunkIn,6);sTemp[6]=0;
	AllTrim(sTemp);
	strcat(po->sOtherParty,sTemp);

	strncpy(sTemp,  pi->sTrunkOut,6);sTemp[6]=0;
	AllTrim(sTemp);
	strcat(po->sOtherParty,sTemp);

	strncpy(sTemp,	pi->sDuration,6);sTemp[6]=0;
	po->iDuration=	atoi(sTemp);

	strncpy(po->sStartTime,	pi->sStartTime,14);
}
void mvitem_bil2dup(struct FPrepTicketStruct *pi,struct DupKeyStruct *po)
{

	bzero((void*)po,sizeof(struct DupKeyStruct));

	strncpy(po->sCallType,	pi->sCallType,2);

	strncpy(po->sMsisdn,	pi->sMsisdn,15);
	strncpy(po->sOtherParty,	pi->sOtherParty,24);

	AllTrim(po->sMsisdn);
	AllTrim(po->sOtherParty);

	po->iDuration=1;

	strncpy(po->sStartTime,	pi->sStartTime,14);
}

void mvitem_prep2mobticket_x(char sData[],int iLen,
	char sVisitAreaCode[],struct MobTicketStruct *po)
{/*�����ƶ�����*/
	char sTemp[128];

	struct FPrepTicketStruct *pi=(struct FPrepTicketStruct *)sData;
	
	bzero((void*)po,sizeof(struct MobTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sImsi,		pi->sImsi,15);

		strncpy(po->sCallingNbr,	pi->sMsisdn,15);
		strncpy(po->sCalledNbr,		pi->sOtherParty,24);

		strncpy(po->sStartTime,		pi->sStartTime,14);

		strncpy(sTemp,			pi->sDuration,6);sTemp[6]=0;
		po->iDuration=			atoi(sTemp);

		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sLac,		pi->sLac,4);
		strncpy(po->sCellID,		pi->sCellID,4);
		strncpy(po->sOtherLac,		pi->sOtherLac,4);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,4);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sMsrn,		pi->sMsrn,12);
		
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sReserve1,		pi->sReserve1,2);

		strncpy(po->sEsn,		pi->sEsn,15);
		
		strncpy(po->sScpFlag,	pi->sScpFlag,1);
		strncpy(po->sDeformFlag,pi->sDeformFlag,1);
		strncpy(po->sReserve,pi->sReserve,8);
		
		AllTrim(po->sCallType);
		AllTrim(po->sImsi);
		AllTrim(po->sCallingNbr);
		AllTrim(po->sCalledNbr);
		AllTrim(po->sStartTime);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsrn);
		
		AllTrim(po->sUserType);
		AllTrim(po->sReserve1);

		AllTrim(po->sEsn);
		AllTrim(po->sScpFlag);
		AllTrim(po->sDeformFlag);
		AllTrim(po->sReserve);

	/*2008.09.02 ���������еĻ���PREP����ͳһ��billing����,
		ֻ�л�������VISIT_AREA_CODE,���ò�����VISIT_AREA_CODE*/
		if(iLen==sizeof(struct FPrepTicketStruct)){

			strncpy(po->sErrCode,pi->sErrCode,4);
			strncpy(po->sFileName,pi->sFileName,19);
			strncpy(po->sModule,pi->sModule,3);
			strncpy(po->sAreaCode,pi->sAreaCode,5);

			AllTrim(po->sErrCode);
			AllTrim(po->sFileName);
			AllTrim(po->sModule);
			AllTrim(po->sAreaCode);
		}
		
		if(strlen(po->sAreaCode)==0){
			strncpy(po->sAreaCode,sVisitAreaCode,3);
			po->sAreaCode[3]=0;
		}
		
		InitMsisdnOtherParty(po);
		
}
void mvitem_prep2mobticket(struct FileControlStruct *p,
	char sVisitAreaCode[],struct MobTicketStruct *po)
{
	mvitem_prep2mobticket_x(p->pData,p->iLen,sVisitAreaCode,po);
}
int ProcessTicket(struct FileControlListStruct *pList,char sTemplateRule[],
	int f,char sMod[],struct MobTicketStruct *p,char sSplitNew[])
{
	int iRet,l=0;
	char	sRec[512],msg[1024];
	struct SplitRuleStruct *pSplitRule=NULL;
	struct FileControlListStruct *pTemp;
	
	strcpy(sSplitNew,"");

	AnalyzeTicketExtent(p);

	while(pList!=NULL){
	
		pTemp=pList;
		pList=pList->pNext;

		/*��ƥ����һ���������*/
		if((pSplitRule=GetMultiSplitRule(pTemp))!=NULL){

			p->iSplitRuleID =	pSplitRule->iSplitRuleID;
			p->iTicketTypeID=	pSplitRule->iTicketTypeID;
			strcpy(p->sSplitType,	pSplitRule->sSplitType);

			if((iRet=CalMainTicketD(p))<0){
				WriteAlertMsg("���ʧ��");
				return -1;
			}
			ModifyTicketFee(sTemplateRule,f,sMod,pTemp->sSplitType,p);

			l=PrintTicket(p,pTemp->sSplitType,sRec);
		
			if((pTemp->iCnt=Item2OutList(&(pTemp->pHead),
				pTemp->sSplitType,sRec,l,sSplitNew,msg))<0){
				printf("��������������������,��Ϣ:%s.\n",msg);
				return -1;
			}
			break;
		}
	}	
	return 0;
}
int data_search_bintree_dup_key_e(void *pValue,void*pData)
{
	struct DupKeyStruct *pSource=(struct DupKeyStruct *)pValue;
	struct DupKeyStruct *pTarget=(struct DupKeyStruct *)pData;

/*���ݱȽϲ���*/
	int res=0;

	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sOtherParty,pTarget->sOtherParty))!=0) return res;
	
	res =tGetTime(pSource->sStartTime)-tGetTime(pTarget->sStartTime);
	if(res<0||res>0) return res;
	
	res=pSource->iDuration-pTarget->iDuration;
	if(res<0||res>0) return res;

	return 0;

}
int comp_insert_list_dup_key_bil(LIST *pValue,LIST*pHead)
{
	struct DupKeyStruct *pSource=(struct DupKeyStruct *)pValue;
	struct DupKeyStruct *pTarget=(struct DupKeyStruct *)pHead;
/*CALL_TYPE������������**/
	return strcmp(pSource->sCallType,pTarget->sCallType);
}
int comp_insert_list_dup_key_stt(LIST *pValue,LIST*pHead)
{
	struct DupKeyStruct *pSource=(struct DupKeyStruct *)pValue;
	struct DupKeyStruct *pTarget=(struct DupKeyStruct *)pHead;
/*CALL_TYPE���ս�������**/
	return strcmp(pTarget->sCallType,pSource->sCallType);
}
void assign_insert_bintree_dup_key_e(void **ppHead,void *pData)
{
	InsertListSort((LIST**)ppHead,(LIST*)pData,
		comp_insert_list_dup_key_e);
}
int mark_deform_flag_hook_pdup_list(void **ppData)
{
	char sPreCallType[3],sCallType[3],cDeformFlag;
	struct FPrepTicketStruct *p;
	struct DupKeyStruct *pTemp,*ptHead=(struct DupKeyStruct *)(*ppData);

	if(CountList((LIST*)ptHead)==1) goto next_mark_over;

/*���ص���DEFORM_FLAG���*/
	strcpy(sPreCallType,"");
	cDeformFlag='A';

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*p=(struct FPrepTicketStruct *)pTemp->pData;*/
		p=(struct FPrepTicketStruct *)((struct FileControlStruct *)pTemp->pData)->pData;

		strncpy(sCallType,p->sCallType,2);sCallType[2]=0;

		if(strcmp(sCallType,sPreCallType)!=0){
			strcpy(sPreCallType,sCallType);
			p->sDeformFlag[0]=cDeformFlag;
			cDeformFlag++;
			/*����ABCD�ģ���ֱ��ȥ��*/
			if(p->sDeformFlag[0]>='E') p->sDeformFlag[0]='X';
		}
		else/*�����һ������ڶ��Ż�����ΪX*/
			p->sDeformFlag[0]='X';

	}
/*����ñ�ǵĻ����һص�pDup��*/
next_mark_over:
	ptHead=(struct DupKeyStruct *)(*ppData);

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		InsertList((LIST**)&pDup,(LIST*)(pTemp->pData));
	}
/*�ͷ�DupKey�ṹ����*/
	DestroyList((LIST*)(*ppData));
	return 0;
}
void DeleteDupTicket(struct FileControlStruct **pptHead)
{
	BINTREE	*pRoot=NULL;
	struct DupKeyStruct *p;
	struct FileControlStruct *pTemp,*ptHead=(*pptHead);
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((p=(struct DupKeyStruct*)malloc(
			sizeof(struct DupKeyStruct )))==NULL){
			WriteAlertMsg("����DUPKEYʧ��dup_key");
			exit(1);
		}
		/**����¼�Ĳ�������MobTicket��**/
		mvitem_ticket2dup((struct FPrepTicketStruct *)pTemp->pData,
			(struct DupKeyStruct *)p);
		
		p->pData=(void*)pTemp;

		if(InsertBin(&pRoot,(void *)p,
			data_search_bintree_dup_key_e,
			assign_insert_bintree_dup_key_e)<0){
			WriteAlertMsg("����BINTREEʧ��dup_key");
			exit(1);
		}
	}
	pDup=NULL;
	TravelBin(pRoot,mark_deform_flag_hook_pdup_list);
	*pptHead=pDup;
	DestroyBin(pRoot);
}

int GetBillingFlag(char sSplitStr[])
{
	int iFlag;
/*ȷ����������д�������ķ�ʽ*/
	if(atoi(sSplitStr)!=0){
		iFlag=false;
		comp_insert_list_dup_key_e=comp_insert_list_dup_key_stt;
		mvitem_ticket2dup=	mvitem_stt2dup;
		InitMsisdnOtherParty=	InitSttMsisdnOtherParty;
	}
	else{
		iFlag=true;
		comp_insert_list_dup_key_e=comp_insert_list_dup_key_bil;
		mvitem_ticket2dup=	mvitem_bil2dup;
		InitMsisdnOtherParty=InitBilMsisdnOtherParty;	
	}
	return iFlag;
}

static void mymvitem_fmprepticket(struct FPrepTicketStruct *pi,int len,
	struct PrepTicketStruct *po)
{/*�����ļ��ƶ����ڴ沿��*/

	bzero((void*)po,sizeof(struct PrepTicketStruct));

		strncpy(po->sCallType,		pi->sCallType,2);
		strncpy(po->sImsi,		pi->sImsi,15);
		strncpy(po->sMsisdn,		pi->sMsisdn,15);
		strncpy(po->sOtherParty,	pi->sOtherParty,24);
		strncpy(po->sStartTime,		pi->sStartTime,14);
		strncpy(po->sDuration,		pi->sDuration,6);
		strncpy(po->sMsc,		pi->sMsc,10);
		strncpy(po->sTrunkIn,		pi->sTrunkIn,8);
		strncpy(po->sTrunkOut,		pi->sTrunkOut,8);
		strncpy(po->sLac,		pi->sLac,4);
		strncpy(po->sCellID,		pi->sCellID,4);
		strncpy(po->sOtherLac,		pi->sOtherLac,4);
		strncpy(po->sOtherCellID,	pi->sOtherCellID,4);
		strncpy(po->sServiceType,	pi->sServiceType,3);
		strncpy(po->sServiceCode,	pi->sServiceCode,4);
		strncpy(po->sThirdParty,	pi->sThirdParty,15);
		strncpy(po->sMsrn,		pi->sMsrn,12);
		
		strncpy(po->sUserType,		pi->sUserType,1);
		strncpy(po->sReserve1,		pi->sReserve1,2);

		strncpy(po->sEsn,		pi->sEsn,15);

		strncpy(po->sScpFlag,		pi->sScpFlag,1);
		strncpy(po->sDeformFlag,	pi->sDeformFlag,1);
		strncpy(po->sReserve,		pi->sReserve,8);

		if(len==sizeof(struct FPrepTicketStruct)){
			strncpy(po->sErrCode,		pi->sErrCode,4);
			strncpy(po->sFileName,		pi->sFileName,19);
			strncpy(po->sModule,		pi->sModule,3);
			strncpy(po->sAreaCode,		pi->sAreaCode,5);
			
			AllTrim(po->sErrCode);
			AllTrim(po->sFileName);
			AllTrim(po->sModule);
			AllTrim(po->sAreaCode);
		}

		AllTrim(po->sCallType);
		AllTrim(po->sImsi);
		AllTrim(po->sMsisdn);
		AllTrim(po->sOtherParty);
		AllTrim(po->sStartTime);
		AllTrim(po->sDuration);
		AllTrim(po->sMsc);
		AllTrim(po->sTrunkIn);
		AllTrim(po->sTrunkOut);
		AllTrim(po->sLac);
		AllTrim(po->sCellID);
		AllTrim(po->sOtherLac);
		AllTrim(po->sOtherCellID);
		AllTrim(po->sServiceType);
		AllTrim(po->sServiceCode);
		AllTrim(po->sThirdParty);
		AllTrim(po->sMsrn);
		AllTrim(po->sEsn);
		AllTrim(po->sReserve);
}
static void mymvitem_mfprepticket(struct PrepTicketStruct *pi,struct FPrepTicketStruct *po)
{/*�ڴ������ƶ����ļ���¼������*/

	memset((void*)po,' ',sizeof(struct FPrepTicketStruct));

		strncpy(po->sCallType,pi->sCallType,strlen(pi->sCallType));
		strncpy(po->sImsi,pi->sImsi,strlen(pi->sImsi));
		strncpy(po->sMsisdn,pi->sMsisdn,strlen(pi->sMsisdn));
		strncpy(po->sOtherParty,pi->sOtherParty,strlen(pi->sOtherParty));
		strncpy(po->sStartTime,pi->sStartTime,strlen(pi->sStartTime));
		strncpy(po->sDuration,pi->sDuration,strlen(pi->sDuration));
		strncpy(po->sMsc,pi->sMsc,strlen(pi->sMsc));
		strncpy(po->sTrunkIn,pi->sTrunkIn,strlen(pi->sTrunkIn));
		strncpy(po->sTrunkOut,pi->sTrunkOut,strlen(pi->sTrunkOut));
		strncpy(po->sLac,pi->sLac,strlen(pi->sLac));
		strncpy(po->sCellID,pi->sCellID,strlen(pi->sCellID));
		strncpy(po->sOtherLac,pi->sOtherLac,strlen(pi->sOtherLac));
		strncpy(po->sOtherCellID,pi->sOtherCellID,strlen(pi->sOtherCellID));
		strncpy(po->sServiceType,pi->sServiceType,strlen(pi->sServiceType));
		strncpy(po->sServiceCode,pi->sServiceCode,strlen(pi->sServiceCode));
		strncpy(po->sThirdParty,pi->sThirdParty,strlen(pi->sThirdParty));
		strncpy(po->sMsrn,pi->sMsrn,strlen(pi->sMsrn));
		
		strncpy(po->sUserType,pi->sUserType,strlen(pi->sUserType));
		strncpy(po->sReserve1,pi->sReserve1,strlen(pi->sReserve1));

		strncpy(po->sEsn,pi->sEsn,strlen(pi->sEsn));
		strncpy(po->sScpFlag,pi->sScpFlag,strlen(pi->sScpFlag));
		strncpy(po->sDeformFlag,pi->sDeformFlag,strlen(pi->sDeformFlag));
		strncpy(po->sReserve,pi->sReserve,strlen(pi->sReserve));
		strncpy(po->sErrCode,pi->sErrCode,strlen(pi->sErrCode));
		strncpy(po->sFileName,pi->sFileName,strlen(pi->sFileName));
		strncpy(po->sModule,pi->sModule,strlen(pi->sModule));
		strncpy(po->sAreaCode,pi->sAreaCode,strlen(pi->sAreaCode));
}
int AddCondCfwTicket(struct FileControlStruct **pptHead)
{
	struct FileControlStruct *pTemp,*ptHead=(*pptHead),*ptLkHead=NULL;

	struct PrepTicketStruct t,t1,t2;
	char sRecord[512],sBelongCode[10],sCapitalAreaCode[10],sType[2];


	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		mymvitem_fmprepticket((struct FPrepTicketStruct *)pTemp->pData,
			pTemp->iLen,(struct PrepTicketStruct*)&t);
		free(pTemp);

		GetBelongCode(t.sMsisdn,t.sStartTime,sBelongCode);
		GetCapitalCode(sBelongCode,sCapitalAreaCode);
		GetAreaType(sCapitalAreaCode,sType);

		/*ֻ���ʡ�ʼ����������û��Ų�,sType[0]!='2'*/
		if(strcmp(t.sCallType,"03")==0&&
			(strcmp(t.sServiceCode,"002A")==0||
			strcmp(t.sServiceCode,"0028")==0||
			strcmp(t.sServiceCode,"0029")==0)&&
			strcmp(t.sStartTime,"20080401")>=0&&
			sType[0]!='2'){
			
			memcpy((void*)&t1,(void*)&t,sizeof(struct PrepTicketStruct));
			strcpy(t1.sCallType,"01");
			strcpy(t1.sThirdParty,"");

			mymvitem_mfprepticket((struct PrepTicketStruct *)&t1,
				(struct FPrepTicketStruct*)sRecord);

			if(item2list(&ptLkHead,sRecord,
				sizeof(struct FPrepTicketStruct))<0) return -1;

			memcpy((void*)&t2,(void*)&t,sizeof(struct PrepTicketStruct));
			strcpy(t2.sCallType,"02");
			strcpy(t2.sThirdParty,"");
			strcpy(t2.sOtherParty,t.sThirdParty);

			mymvitem_mfprepticket((struct PrepTicketStruct *)&t2,
				(struct FPrepTicketStruct*)sRecord);
			if(item2list(&ptLkHead,sRecord,
				sizeof(struct FPrepTicketStruct))<0) return -1;
		}
		else{
			mymvitem_mfprepticket((struct PrepTicketStruct *)&t,
				(struct FPrepTicketStruct*)sRecord);
			if(item2list(&ptLkHead,sRecord,
				sizeof(struct FPrepTicketStruct))<0) return -1;
		}
	}
	ReverseList((LIST**)(&ptLkHead));
	*pptHead=ptLkHead;
	
	return 0;
}

int ProcessBillFile(char sFileName[],char sVisitAreaCode[],char sModule[],
	char sNormalDir[],char sErrDir[],char sTemplateRule[],
	char sUserType[],int iBillFlag,char sSource[],
	int iWantCtl,char sSplit[],int iStartPos,int iKeyLen,
	struct	FileControlListStruct *pControlList,char sResult[])
{
	int i,l,iErrCode=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0,iIncreaseCnt=0;
	char sSplitNew[30],sTempName[128],sRecord[1024];
	char  sAbnormalName[128],sBaseName[128],sAreaCode[6];
	struct FileControlStruct *ptHead=NULL,*pTemp,*pAbnormal=NULL;
	struct MobTicketStruct  *p=&Ticket;
	
/*	strncpy(sAreaCode,sVisitAreaCode,5);sAreaCode[5]=0;*/

/*���ļ����ݵ��ú������ص��ڴ�*/
	if((l=TxtFileToList(sFileName,&ptHead))<0){
		printf("�����ļ�%s���ڴ�ʧ��.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}
/*ɾ���ظ�����*/
	DeleteDupTicket(&ptHead);

/*ʹ������������*/
	ReverseList((LIST**)&ptHead);
	
/*��������ת�������*/
	if(strcmp(sUserType,"G")==0&&
		iBillFlag==true){
		if(AddCondCfwTicket(&ptHead)<0){
			printf("�ļ�%s�����������ת����ʧ��.\n",sFileName);
			WriteErrStackAlert();
			return -1;
		}
	}

	GetBaseName(sFileName,sBaseName);sBaseName[19]=0;

	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		/**����¼�Ĳ�������MobTicket��**/
		mvitem_prep2mobticket(pTemp,sVisitAreaCode,p);
		/*���۳�����дprep���ļ���*/
		strcpy(p->sFileName,sBaseName);
		
		iIncreaseCnt=1;
		if(strcmp(p->sCallType,"02")==0&&
			strcmp(p->sServiceType,"002")==0)iIncreaseCnt=0;

		
		iCnt+=iIncreaseCnt;
		/*������ֲ����쳣�Ļ�����д���쳣�б�*/
		strcpy(sAreaCode,p->sAreaCode);
		if((i=AnalyzeTicketBase(p,sAreaCode,iBillFlag))<0){

			iAbnormalCnt+=iIncreaseCnt;
			/*if(WantWriteErrTicket(p,iBillFlag)!=true)
				continue;*/

			if((l=mvitem2preperr(pTemp,-i,sRecord))<0){
				sprintf(sResult,"������¼̫��.\n");
				return -1;
			}			
			if(item2list(&pAbnormal,sRecord,l)<0){
				sprintf(sResult,"�����쳣������������.\n");
				return -1;
			}

			free(pTemp);
			continue;
		}
		PreModifyTicket(p,iBillFlag);

		/*������������б�*/
		if(ProcessTicket(pControlList,sTemplateRule,iBillFlag,
			sModule,p,sSplitNew)<0){
			sprintf(sResult,"��������ʧ�ܣ��ļ�%s.\n",sFileName);
			return -1;
			
		}
		/*�����������ȷ���������Ҫ�����󻰵�������²����*/
		if(strlen(sSplitNew)==0){
			iErrCode=-INVALID_SPLIT_RULE;
			if((l=mvitem2preperr(pTemp,iErrCode,sRecord))<0){
				sprintf(sResult,"������¼̫��.\n");
				return -1;
			}			
			if(item2list(&pAbnormal,sRecord,l)<0){
				sprintf(sResult,"�����쳣������������.\n");
				return -1;
			}
			iAbnormalCnt+=iIncreaseCnt;
		}
		else	iNormalCnt+=iIncreaseCnt;
		free(pTemp);
	}
	
	GetBaseNameX(sFileName,sTempName);
		
	strcpy(sSplitNew,"");
/**д�����쳣����********/
	if(pAbnormal!=NULL){
		
		ReverseList((LIST**)&pAbnormal);		
		sprintf(sAbnormalName,"%s%s.a.tmp",sErrDir,sTempName);
		if(list2file(&pAbnormal,sAbnormalName)<0){
			sprintf(sResult,"д�쳣�����ļ�%sʧ��.\n",
				sAbnormalName);
			return -1;
		}
		strcat(sSplitNew,"a");	
	}
/*д������Ӫ�̻���*/
	if(WriteTicketToFile(pControlList,sNormalDir,sTempName,
		sSource,iWantCtl,sSplit,iStartPos,iKeyLen,sSplitNew)<0){
		sprintf(sResult,"�����ļ�%s��������ļ�ʧ��.\n",sFileName);
		return -1;
	}
	
	sprintf(sResult,"%s%s\t%s\t%d\t%d\t%d\n",sNormalDir,
		sTempName,sSplitNew,iCnt,iNormalCnt,iAbnormalCnt);
	
	return 0;
}