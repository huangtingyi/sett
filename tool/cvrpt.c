#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>

struct ReportHeadStruct
{
	struct ReportHeadStruct *pNext;
	int	iSheet;				/*SplitCtlBySheet��ʼ��*/
	int	iTitleLine;			/*��ʼ��iTitle����*/
	int	iLatnID;			/*TitleCtl2ReportHead��ʼ��*/
	char	sBillingCycleID[7];
	char	sTitle[128];			/*SplitAllCtl��ʼ��*/
	struct ReportBodyStruct *pBody;		/*SplitAllCtl��ʼ��*/
	struct FileControlStruct *pAllCtl;	/*SplitCtlBySheet��ʼ��*/
	char	sField[1024];			/*SplitAllCtl��ʼ��*/
	int	iFieldCnt;			/*TitleCtl2ReportHead��ʼ��*/
	char	asFieldName[60][60];		/*TitleCtl2ReportHead��ʼ��*/
	struct FileControlStruct *pBodyCtl;
};
struct ReportBodyStruct
{
	struct ReportBodyStruct *pNext;
	char	sAcctItemName[61];
	char	sDetailItemName[61];
	char 	sSettRule[61];
	int	iTotalCnt;
	int	iTotalMin;
	int	iCharge;
	int	iLine;
	int	iDistanceFee;	/*�ƶ���������*/
	int	iTotalDuration;		/*��ʱ������ͨ*/
	int	iTotalSec;		/*����ʱ������ͨ*/
	int	iMoCnt;			/*MO����*/
	int	iMtCnt;			/*MT����*/
	int	iPayFee;		/*Ӧ�����*/
	int	iIncomeFee;		/*Ӧ�ս��*/
	int	iLatnID;		/*��������ʶCS,CMSMS,CUSMS��*/
};
int SheetBegin(struct FileControlStruct *ptHead)
{
	int l,iSheet;
	char sTemp[1024];

	if(ptHead==NULL) return -1;

	l=MY_MIN(ptHead->iLen,1023);
	strncpy(sTemp,(char*)ptHead->pData,l);sTemp[l]=0;

	if(strncmp(sTemp,"sheet=",6)!=0) return -1;

	iSheet=atoi(sTemp+6);

	return iSheet;
}
int GetSheet(struct FileControlStruct **pptHead,struct FileControlStruct **pptList)
{
	int iSheet;
	struct FileControlStruct *ptHead=*pptHead,*pTemp;

	if(ptHead==NULL) return -1;

	if((iSheet=SheetBegin(ptHead))<0) return -1;

	pTemp=ptHead;
	ptHead=ptHead->pNext;

	free(pTemp);

	/*���sheet������һ��sheet�����⴦��*/
	if(SheetBegin(ptHead)>=0){
		*pptList=NULL;
		*pptHead=ptHead;
		return iSheet;
	}

	pTemp=NULL;
	*pptList=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(SheetBegin(ptHead)>=0) break;
	}
	if(ptHead==NULL){
		*pptHead=NULL;
		return iSheet;
	}
	/*�����������*/
	*pptHead=ptHead;
	if(pTemp!=NULL)	pTemp->pNext=NULL;

	return iSheet;
}
int SplitCtlBySheet(struct FileControlStruct *pCtl,char sBillingCycleID[],
	char sType[],int iReportType,struct ReportHeadStruct **pptHead)
{
	int iSheet;

	struct ReportHeadStruct *pTemp;
	struct FileControlStruct *pAllCtl;

	*pptHead=NULL;

	while((iSheet=GetSheet(&pCtl,&pAllCtl))>=0){
		if(iReportType==2){
			if(strcmp(sType,"CT")==0||
				strcmp(sType,"CRC")==0||
				strcmp(sType,"CUGSM")==0||
				strcmp(sType,"CUCDM")==0||
				strcmp(sType,"CM")==0){
				if (iSheet>11)	continue;
			}
			else if(strcmp(sType,"CMSMS")==0||strcmp(sType,"CUSMS")==0||
				strcmp(sType,"CS")==0){
				if (iSheet>0) continue;
			}
		}

		if((pTemp=malloc(sizeof(struct ReportHeadStruct)))==NULL){
			printf("�����ڴ� ReportHeadStruct ����.\n");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct ReportHeadStruct));

		strcpy(pTemp->sBillingCycleID,sBillingCycleID);
		pTemp->iSheet=iSheet;
		pTemp->pAllCtl=pAllCtl;

		InsertListTail((LIST**)pptHead,(LIST*)pTemp);
	}
	return 0;
}
int SplitAllCtl(struct FileControlStruct **ppAllCtl,char sTitle[],
	char sType[],int iReportType,char sField[],
	struct FileControlStruct **ppBodyCtl)
{
	int l,m=0,iTitleLine=1;
	char sTemp[1024];
	struct FileControlStruct *ptHead,*pTemp=NULL;

	ptHead=*ppAllCtl;

	if(ptHead==NULL)return 9999;

	strcpy(sTitle,"");
	strcpy(sTemp,"");


	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		l=MY_MIN(pTemp->iLen,1023);
		strncpy(sTemp,(char*)pTemp->pData,l);sTemp[l]=0;

		if(strstr(sTemp,"���")!=NULL||
			strstr(sTemp,"����ԭ��")!=NULL||
			strstr(sTemp,"�������")!=NULL||
			strstr(sTemp,"���㷽��")!=NULL||
			strstr(sTemp,"�˶Է�")!=NULL) break;

		/*ֻȡ�������㱨��ı������*/
		if(strstr(sTemp,"����")!=NULL&&(strstr(sTemp,"����")!=NULL||
			 strstr(sTemp,"�����")!=NULL)){
			TrimAll(sTemp);l=strlen(sTemp);
			m+=l;
			if(m>=127) return -1;
			strcat(sTitle,sTemp);
		}

		free(pTemp);
		iTitleLine++;
	}

	if(strstr(sTemp,"���")==NULL&&strstr(sTemp,"����ԭ��")==NULL&&
		strstr(sTemp,"�������")==NULL&&strstr(sTemp,"���㷽��")==NULL&&
		strstr(sTemp,"�˶Է�")==NULL)
		return -1;

	strcat(sField,sTemp);

	iTitleLine++;

	if(pTemp==NULL) return -1;

	if(iReportType==1){
		/*�ƶ����Ž���������ɾ��TITLE�ĵڶ���*/
		if(strcmp(sType,"CMSMS")==0){
			ptHead=pTemp;
			pTemp=pTemp->pNext;
			free(ptHead);
			iTitleLine++;
		}
	}

	*ppBodyCtl=pTemp->pNext;
	*ppAllCtl=NULL;

	free(pTemp);

	return iTitleLine;
}
int GetLatnIDFromRemark(char sRemark[])
{
	int iLatnID;
	char sTemp[256];

	strcpy(sTemp,sRemark);

	ReplaceStr(sTemp," ","");
	ReplaceStr(sTemp,"��","");
	
	if(strstr(sTemp,"ʯ��ׯ")!=NULL)      iLatnID=11;
	else if(strstr(sTemp,  "����")!=NULL) iLatnID=10;
	else if(strstr(sTemp,  "����")!=NULL) iLatnID=11;
	else if(strstr(sTemp,  "����")!=NULL) iLatnID=12;
	else if(strstr(sTemp,"�żҿ�")!=NULL) iLatnID=13;
	else if(strstr(sTemp,  "�е�")!=NULL) iLatnID=14;
	else if(strstr(sTemp,  "��ɽ")!=NULL) iLatnID=15;
	else if(strstr(sTemp,  "�ȷ�")!=NULL) iLatnID=16;
	else if(strstr(sTemp,  "����")!=NULL) iLatnID=17;
	else if(strstr(sTemp,  "��ˮ")!=NULL) iLatnID=18;
	else if(strstr(sTemp,  "��̨")!=NULL) iLatnID=19;
	else if(strstr(sTemp,"�ػʵ�")!=NULL) iLatnID=35;
	else iLatnID=-1;

	if(iLatnID==-1){
		Lower(sTemp);
		if(strstr(sTemp,     "shijiazhuang")!=NULL)	iLatnID=11;
		else if(strstr(sTemp,      "handan")!=NULL)	iLatnID=10;
		else if(strstr(sTemp,   "zhengding")!=NULL)	iLatnID=11;
		else if(strstr(sTemp,     "baoding")!=NULL)	iLatnID=12;
		else if(strstr(sTemp, "zhangjiakou")!=NULL)	iLatnID=13;
		else if(strstr(sTemp,     "chengde")!=NULL)	iLatnID=14;
		else if(strstr(sTemp,    "tangshan")!=NULL)	iLatnID=15;
		else if(strstr(sTemp,    "langfang")!=NULL)	iLatnID=16;
		else if(strstr(sTemp,    "cangzhou")!=NULL)	iLatnID=17;
		else if(strstr(sTemp,     "henshui")!=NULL)	iLatnID=18;
		else if(strstr(sTemp,     "xingtai")!=NULL)	iLatnID=19;
		else if(strstr(sTemp, "qinhuangdao")!=NULL)	iLatnID=35;
	}

	return iLatnID;
}
void TitleCtl2ReportHead(char sTitle[],char sField[],
	struct ReportHeadStruct *pTemp)
{
	char sTemp[128];
	int i=0,iFlag=false;

	pTemp->iLatnID=GetLatnIDFromRemark(sTitle);

	while(1){
		GetSepStrX(sField,'\t',i,127,sTemp);
		if(iFlag==true&&strlen(sTemp)==0) break;

		if(strstr(sTemp,"���")!=NULL||
			strstr(sTemp,"����ԭ��")!=NULL||
			strstr(sTemp,"�������")!=NULL||
			strstr(sTemp,"���㷽��")!=NULL||
			strstr(sTemp,"�˶Է�")!=NULL) iFlag=true;

		strcpy(pTemp->asFieldName[i],sTemp);
		i++;
	}

	i++;
	pTemp->iFieldCnt=i;
}
int ExistDigital(char sInput[])
{
	int i;

	for(i=0;i<strlen(sInput);i++)
		if(sInput[i]>='0'&&sInput[i]<='9') return true;
	return false;
}
int ExistChinese(char sInput[])
{
	int i;

	for(i=0;i<strlen(sInput);i++)
		if((sInput[i]&0x80)!=0) return true;
	return false;
}
void RegularNumber(char sTemp[])
{
	ReplaceStr(sTemp,",","");
	ReplaceStr(sTemp,"(","-");
	ReplaceStr(sTemp,")","");
	ReplaceStr(sTemp,"$","");
	ReplaceStr(sTemp,"��","");
	ReplaceStr(sTemp,"\"","");
}
int GetFloatCharge(char sTemp[])
{
	double fTemp=atof(sTemp)*100;
	
	fTemp=fTemp>0?fTemp+0.5:fTemp-0.5;
		
	return (int)(fTemp);
}
void cvitem_ct2reportbody(char sRecord[],int offset,char sType[],
	struct ReportBodyStruct *ptPre,struct ReportBodyStruct *ptCur)
{
	char sTemp[128];

	GetSepStrX(sRecord,'\t',offset+0,60,ptCur->sAcctItemName);
	if(strlen(ptCur->sAcctItemName)==0&&ptPre!=NULL)
		strcpy(ptCur->sAcctItemName,ptPre->sAcctItemName);

	if(strcmp(sType,"CU")==0){
		GetSepStrX(sRecord,'\t',offset+3,60,ptCur->sSettRule);
		if(strlen(ptCur->sSettRule)==0&&ptPre!=NULL)
			strcpy(ptCur->sSettRule,ptPre->sSettRule);
		/*��������*/
		GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalCnt=atoi(sTemp);

		/*ʱ�������ӣ�*/
		GetSepStrX(sRecord,'\t',offset+5,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalMin=atoi(sTemp);
	}
	else{
		GetSepStrX(sRecord,'\t',offset+5,60,ptCur->sSettRule);
		if(strlen(ptCur->sSettRule)==0&&ptPre!=NULL)
			strcpy(ptCur->sSettRule,ptPre->sSettRule);
		/*��������*/
		GetSepStrX(sRecord,'\t',offset+3,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalCnt=atoi(sTemp);

		/*ʱ�������ӣ�*/
		GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalMin=atoi(sTemp);
	}

	GetSepStrX(sRecord,'\t',offset+2,60,ptCur->sDetailItemName);
	if(strlen(ptCur->sDetailItemName)==0){
		GetSepStrX(sRecord,'\t',offset+1,128,sTemp);
		if(strcmp(sTemp,"С��")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sDetailItemName,ptCur->sAcctItemName);
			strcat(ptCur->sDetailItemName,sTemp);
		}
		if(strcmp(sTemp,"�ϼ�")==0||
			strcmp(sTemp,"����")==0||
			strcmp(sTemp,"�ܼ�")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sAcctItemName,"");
			strcpy(ptCur->sDetailItemName,sTemp);
		}
	}
	
	/*�������(Ԫ��*/
	GetSepStrX(sRecord,'\t',offset+6,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iCharge=GetFloatCharge(sTemp);

}
void cvitem_cm2reportbody(char sRecord[],struct ReportBodyStruct *ptCur)
{
	char sTemp[128];

	GetSepStrX(sRecord,'\t',0,60,ptCur->sAcctItemName);

	GetSepStrX(sRecord,'\t',1,128,sTemp);
	ReplaceStr(sTemp," ","");
	strncpy(ptCur->sDetailItemName,sTemp,60);ptCur->sDetailItemName[60]=0;

	/*��������*/
	GetSepStrX(sRecord,'\t',2,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*ʱ�������ӣ�*/
	GetSepStrX(sRecord,'\t',3,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalMin=atoi(sTemp);

	/*��;��*/
	GetSepStrX(sRecord,'\t',4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iDistanceFee=GetFloatCharge(sTemp);

	GetSepStrX(sRecord,'\t',5,60,ptCur->sSettRule);

	/*�������(Ԫ��*/
	GetSepStrX(sRecord,'\t',6,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iCharge=GetFloatCharge(sTemp);
}
void cvitem_cs2reportbody(char sRecord[],struct ReportBodyStruct *ptCur)
{
	char sTemp[128];

	GetSepStrX(sRecord,'\t',1,60,sTemp);
	ptCur->iLatnID=GetLatnIDFromRemark(sTemp);

	GetSepStrX(sRecord,'\t',3,60,ptCur->sAcctItemName);
	GetSepStrX(sRecord,'\t',2,60,ptCur->sDetailItemName);

	/*ͨ��ʱ�����룩*/
	GetSepStrX(sRecord,'\t',4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalDuration=atoi(sTemp);

	/*��������*/
	GetSepStrX(sRecord,'\t',5,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*����ʱ��*/
	GetSepStrX(sRecord,'\t',6,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalSec=atoi(sTemp);

	/*�������*/
	GetSepStrX(sRecord,'\t',7,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalMin=atoi(sTemp);

	/*�������(Ԫ��*/
	GetSepStrX(sRecord,'\t',8,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iCharge=GetFloatCharge(sTemp);
}
void cvitem_cmsms2reportbody(char sRecord[],int offset,
	struct ReportBodyStruct *ptPre,struct ReportBodyStruct *ptCur)
{
	char sTemp[128];

	GetSepStrX(sRecord,'\t',offset+0,60,sTemp);
	ptCur->iLatnID=GetLatnIDFromRemark(sTemp);

	/*�ƶ�MO����*/
	GetSepStrX(sRecord,'\t',offset+1,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iMoCnt=atoi(sTemp);

	/*�ƶ�MT����*/
	GetSepStrX(sRecord,'\t',offset+2,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iMtCnt=atoi(sTemp);

	/*�ƶ�Ӧ�����*/
	GetSepStrX(sRecord,'\t',offset+3,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iPayFee=GetFloatCharge(sTemp);

	/*�ƶ�Ӧ�ս��*/
	GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iIncomeFee=GetFloatCharge(sTemp);

	GetSepStrX(sRecord,'\t',offset+5,60,ptCur->sSettRule);
	if(strlen(ptCur->sSettRule)==0&&ptPre!=NULL)
		strcpy(ptCur->sSettRule,ptPre->sSettRule);

	/*�������(Ԫ��*/
	GetSepStrX(sRecord,'\t',offset+6,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iCharge=GetFloatCharge(sTemp);
}
void cvitem_ctstt2reportbody(char sRecord[],int offset,char sType[],
	struct ReportBodyStruct *ptPre,struct ReportBodyStruct *ptCur)
{
	char sTemp[128];

	GetSepStrX(sRecord,'\t',offset+0,60,ptCur->sAcctItemName);
	if(strlen(ptCur->sAcctItemName)==0&&ptPre!=NULL)
		strcpy(ptCur->sAcctItemName,ptPre->sAcctItemName);
		
	if(strcmp(sType,"CM")==0)
		GetSepStrX(sRecord,'\t',offset+6,60,ptCur->sSettRule);
	else
		GetSepStrX(sRecord,'\t',offset+5,60,ptCur->sSettRule);
		
	if(strlen(ptCur->sSettRule)==0&&ptPre!=NULL)
		strcpy(ptCur->sSettRule,ptPre->sSettRule);
	/*��������*/
	GetSepStrX(sRecord,'\t',offset+3,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*ʱ�������ӣ�*/
	GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalMin=atoi(sTemp);

	GetSepStrX(sRecord,'\t',offset+2,60,ptCur->sDetailItemName);
	if(strlen(ptCur->sDetailItemName)==0){
		GetSepStrX(sRecord,'\t',offset+1,128,sTemp);
		if(strcmp(sTemp,"С��")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sDetailItemName,ptCur->sAcctItemName);
			strcat(ptCur->sDetailItemName,sTemp);
		}
		if(strcmp(sTemp,"�ϼ�")==0||
			strcmp(sTemp,"����")==0||
			strcmp(sTemp,"�ܼ�")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sAcctItemName,"");
			strcpy(ptCur->sDetailItemName,sTemp);
		}
	}
	
	/*�������(Ԫ��*/
	if(strcmp(sType,"CM")==0)
		GetSepStrX(sRecord,'\t',offset+7,128,sTemp);
	else
		GetSepStrX(sRecord,'\t',offset+6,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iCharge=GetFloatCharge(sTemp);

}

void cvitem_csstt2reportbody(char sRecord[],struct ReportBodyStruct *ptPre,
	struct ReportBodyStruct *ptCur)
{
	char sTemp[128];

	GetSepStrX(sRecord,'\t',0,60,sTemp);
	if(strlen(sTemp)==0&&ptPre!=NULL)
		ptCur->iLatnID=ptPre->iLatnID;
	else{
		ptCur->iLatnID=GetLatnIDFromRemark(sTemp);
	}

	GetSepStrX(sRecord,'\t',3,60,ptCur->sAcctItemName);
	GetSepStrX(sRecord,'\t',2,60,ptCur->sDetailItemName);

	/*��������*/
	GetSepStrX(sRecord,'\t',4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*����ʱ��*/
	GetSepStrX(sRecord,'\t',5,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalSec=atoi(sTemp);

	/*�������*/
	GetSepStrX(sRecord,'\t',6,128,ptCur->sSettRule);

	/*�������(Ԫ��*/
	GetSepStrX(sRecord,'\t',7,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iCharge=GetFloatCharge(sTemp);
}
int cvitem_str2reportbody(char sRecord[],char sType[],
	struct ReportBodyStruct *ptPre,struct ReportBodyStruct *ptCur,
	int iReportType)
{
	if(iReportType==1){
		if(strcmp(sType,"CT")==0)
			cvitem_ct2reportbody(sRecord,1,sType,ptPre,ptCur);
		else if(strcmp(sType,"CU")==0||strcmp(sType,"CRC")==0)
			cvitem_ct2reportbody(sRecord,0,sType,ptPre,ptCur);
		else if(strcmp(sType,"CM")==0)
			cvitem_cm2reportbody(sRecord,ptCur);
		else if(strcmp(sType,"CS")==0)
			cvitem_cs2reportbody(sRecord,ptCur);
		else if(strcmp(sType,"CMSMS")==0)
			cvitem_cmsms2reportbody(sRecord,0,ptPre,ptCur);
		else if(strcmp(sType,"CUSMS")==0)
			cvitem_cmsms2reportbody(sRecord,1,ptPre,ptCur);
		else
			return -1;
	}
	else{
		if(strcmp(sType,"CUGSM")==0||
			strcmp(sType,"CUCDM")==0||
			strcmp(sType,"CRC")==0||
			strcmp(sType,"CT")==0||
			strcmp(sType,"CM")==0)
			cvitem_ctstt2reportbody(sRecord,0,sType,ptPre,ptCur);
		else if(strcmp(sType,"CS")==0)
			cvitem_csstt2reportbody(sRecord,ptPre,ptCur);
		else if(strcmp(sType,"CMSMS")==0||strcmp(sType,"CUSMS")==0)
			cvitem_cmsms2reportbody(sRecord,0,ptPre,ptCur);
		else
			return -1;
	}
	return 0;
}
int BodyCtl2ReportBodyList(struct FileControlStruct *pBody,int iTitleLine,
	char sType[],int iReportType,struct ReportBodyStruct **ppBody)
{
	int l,iLine=iTitleLine;
	char sRecord[1024];
	struct ReportBodyStruct *ptLkHead=NULL,*ptPre=NULL,*ptCur;
	struct FileControlStruct *ptHead,*pTemp;

	ptHead=pBody;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;

		l=MY_MIN(pTemp->iLen,1023);
		strncpy(sRecord,(char*)pTemp->pData,l);sRecord[l]=0;

		/*������������ֵ��У������*/
		if(ExistDigital(sRecord)==false&&ExistChinese(sRecord)==false){
			iLine++;
			continue;
		}

		if((ptCur=malloc(sizeof(struct ReportBodyStruct)))==NULL){
			printf("�����ڴ� ReportBodyStruct ʧ��.\n");
			return -1;
		}
		bzero((void*)ptCur,sizeof(struct ReportBodyStruct));

		if(cvitem_str2reportbody(sRecord,sType,ptPre,ptCur,iReportType)<0){
			printf("���ͷǷ�%s,[CT,CM,CU,CRC,CS,CMSMS,CUSMS]",sType);
			return -1;
		}

		ptCur->iLine=iLine++;

		InsertListTail((LIST**)&ptLkHead,(LIST*)ptCur);

		ptPre=ptCur;
	}

	*ppBody=ptLkHead;
	return 0;

}
int output_record(char sType[],char sReportID[],struct ReportHeadStruct *pTemp,
	struct ReportBodyStruct *ptPre,int iReportType,char sRecord[])
{
	if(iReportType==1){
		if(strcmp(sType,"CT")==0||strcmp(sType,"CU")==0||
			strcmp(sType,"CRC")==0){
		sprintf(sRecord,"%-6s%-60s%-60s%09d%09d%-60s%012d%04d%-6s%02d%03d",
				sReportID,ptPre->sAcctItemName,
				ptPre->sDetailItemName,ptPre->iTotalCnt,
				ptPre->iTotalMin,ptPre->sSettRule,
				ptPre->iCharge,pTemp->iLatnID,
				pTemp->sBillingCycleID,
				pTemp->iSheet,ptPre->iLine);
		}
		else if(strcmp(sType,"CM")==0){
		sprintf(sRecord,"%-6s%-60s%-60s%09d%09d%09d%-60s%012d%04d%-6s%02d%03d",
				sReportID,ptPre->sAcctItemName,
				ptPre->sDetailItemName,ptPre->iTotalCnt,
				ptPre->iTotalMin,ptPre->iDistanceFee,
				ptPre->sSettRule,ptPre->iCharge,
				pTemp->iLatnID,pTemp->sBillingCycleID,
				pTemp->iSheet,ptPre->iLine);
		}
		else if(strcmp(sType,"CS")==0){
		sprintf(sRecord,"%-6s%-60s%-60s%012d%09d%012d%09d%012d%04d%-6s%02d%03d",
				sReportID,ptPre->sAcctItemName,
				ptPre->sDetailItemName,ptPre->iTotalDuration,
				ptPre->iTotalCnt,ptPre->iTotalSec,
				ptPre->iTotalMin,ptPre->iCharge,
				ptPre->iLatnID,pTemp->sBillingCycleID,
				pTemp->iSheet,ptPre->iLine);
		}
		else if(strcmp(sType,"CMSMS")==0||strcmp(sType,"CUSMS")==0){
		sprintf(sRecord,"%-6s%012d%012d%012d%012d%-60s%012d%04d%-6s%02d%03d",
				sReportID,ptPre->iMoCnt,ptPre->iMtCnt,
				ptPre->iPayFee,ptPre->iIncomeFee,
				ptPre->sSettRule,ptPre->iCharge,
				ptPre->iLatnID,pTemp->sBillingCycleID,
				pTemp->iSheet,ptPre->iLine);
		}
		else{
			printf("����%s�Ƿ�.\n",sType);
			return -1;
		}
	}
	else if(iReportType==2){
		if(strcmp(sType,"CT")==0||strcmp(sType,"CUGSM")==0||
			strcmp(sType,"CUCDM")==0||
			strcmp(sType,"CRC")==0||
			strcmp(sType,"CM")==0||
			strcmp(sType,"CS")==0){

			int iLatnID=pTemp->iLatnID;

			if(strcmp(sType,"CS")==0) iLatnID=ptPre->iLatnID;
		sprintf(sRecord,"%-6s%-60s%-60s%09d%09d%-60s%012d%04d%-6s%02d%03d%-5s",
				sReportID,ptPre->sAcctItemName,
				ptPre->sDetailItemName,ptPre->iTotalCnt,
				ptPre->iTotalMin,ptPre->sSettRule,
				ptPre->iCharge,iLatnID,pTemp->sBillingCycleID,
				pTemp->iSheet,ptPre->iLine,sType);
		}
		else if(strcmp(sType,"CMSMS")==0||strcmp(sType,"CUSMS")==0){
		sprintf(sRecord,"%-6s%012d%012d%012d%012d%-60s%012d%04d%-6s%02d%03d%-5s",
				sReportID,ptPre->iMoCnt,ptPre->iMtCnt,
				ptPre->iPayFee,ptPre->iIncomeFee,
				ptPre->sSettRule,ptPre->iCharge,
				ptPre->iLatnID,pTemp->sBillingCycleID,
				pTemp->iSheet,ptPre->iLine,sType);
		}
		else{
			printf("����%s�Ƿ�.\n",sType);
			return -1;
		}
	}
	else{
		printf("��������%01d�Ƿ�.\n",iReportType);
		return -1;
	}
	
	return 0;
}
int Output2TxtFile(struct ReportHeadStruct *ptHead,char sReportID[],
	char sType[],int iReportType,char sTargetName[])
{
	int iCnt=0;
	char sRecord[1024];
	struct ReportHeadStruct *pTemp;
	struct ReportBodyStruct *ptCur,*ptPre;
	struct FileControlStruct *ptLkHead=NULL;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		ptCur=pTemp->pBody;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;

			if(output_record(sType,sReportID,pTemp,ptPre,iReportType,sRecord)<0)
				return -1;

			if(item2list(&ptLkHead,(void*)sRecord,strlen(sRecord))<0){
				printf("�ڴ�������.\n");
				return -1;
			}
		}
	}

	ReverseList((LIST**)&ptLkHead);

	if((iCnt=list2fileln(&ptLkHead,sTargetName))<0){
		printf("����д��%s�ļ�����.\n",sTargetName);
		return -1;
	}

	return iCnt;
}
/**
type	���ͼ�����
CT 	��������
CRC	��ͨ����
CU	��ͨ����      �����ķ�Ϊ:CUGSM,CUCDM
CM	�ƶ�����
CS	��ͨ����

CMSMS	�ƶ�����
CUSMS	���Ŷ���
**/
/**
sReportID	��������
1		�Զ˱���
2		��������
**/
int ValidCycle(char sBillingCycleID[])
{
	char sTempDate[15];

	strcpy(sTempDate,sBillingCycleID);
	strcpy(sTempDate+6,"01000000");
	if(tGetTime(sTempDate)<0) return false;
	return true;
}
int main(int argc,char *argv[])
{
	int iCnt,iReportType;
	char sSourceName[256],sTargetName[256],sReportID[20];
	char sBillingCycleID[7],sType[10];
	struct FileControlStruct *pCtl=NULL;
	struct ReportHeadStruct *ptLkHead,*ptHead,*pTemp;

        if(argc!=7){
                printf("Usage: cvrpt sourcename type reportid reporttype cycle targetname.\n");
                exit(1);
        }

	strcpy(sSourceName,argv[1]);
	strcpy(sType,argv[2]);Upper(sType);
	strcpy(sReportID,argv[3]);
	iReportType=atoi(argv[4]);
	strncpy(sBillingCycleID,argv[5],6);sBillingCycleID[6]=0;
	strcpy(sTargetName,argv[6]);

	if(ValidCycle(sBillingCycleID)==false){
		printf("����������Ч��%s.\n",sBillingCycleID);
		return -1;
	}
	/*���ļ�����InHead�ṹ����*/
	if(TxtFileToList(sSourceName,&pCtl)<0){
		printf("�ļ�%s���ص��ڴ����.\n",sSourceName);
		return -1;
	}

	/***����sheet=x sheet=y�ָ� sheet*/
	if(SplitCtlBySheet(pCtl,sBillingCycleID,sType,iReportType,&ptLkHead)<0)
		return -1;

	ptHead=ptLkHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*��AllCtl������ݲ�ͬ�߼����ָ������е�title��body*/
		pTemp->iTitleLine=SplitAllCtl(&(pTemp->pAllCtl),pTemp->sTitle,
			sType,iReportType,pTemp->sField,&(pTemp->pBodyCtl));

		/*��û���ݵ�SHEETֱ��ɾ��*/
		if(pTemp->iTitleLine==9999) continue;

		if(pTemp->iTitleLine<0){
			printf("SplitAllCtl���� %d\n",pTemp->iSheet);
			return -1;
		}

		/*��TitleCtlת������Ҫ��Ԫ��*/
		TitleCtl2ReportHead(pTemp->sTitle,pTemp->sField,pTemp);
		if(iReportType==1){
			/*�����CM������ȡ�����ı�����*/
			if(strcmp(sType,"CM")==0&&pTemp->iLatnID==-1)
				pTemp->iLatnID=GetLatnIDFromRemark(sSourceName);
		}

		/*��BodyCtlת������Ҫ��Ԫ�ص�����*/
		if(BodyCtl2ReportBodyList(pTemp->pBodyCtl,pTemp->iTitleLine,
			sType,iReportType,&(pTemp->pBody))<0) return -1;
	}

	/*��OutHead����������ļ�*/
	if((iCnt=Output2TxtFile(ptLkHead,sReportID,sType,iReportType,sTargetName))<0)
		return -1;

	printf("���ļ�%sת��Ϊ%s�ļ��ɹ�,����%d����¼.\n",
		sSourceName,sTargetName,iCnt);

	return 0;
}

