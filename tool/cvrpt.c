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
	int	iSheet;				/*SplitCtlBySheet初始化*/
	int	iTitleLine;			/*初始化iTitle行数*/
	int	iLatnID;			/*TitleCtl2ReportHead初始化*/
	char	sBillingCycleID[7];
	char	sTitle[128];			/*SplitAllCtl初始化*/
	struct ReportBodyStruct *pBody;		/*SplitAllCtl初始化*/
	struct FileControlStruct *pAllCtl;	/*SplitCtlBySheet初始化*/
	char	sField[1024];			/*SplitAllCtl初始化*/
	int	iFieldCnt;			/*TitleCtl2ReportHead初始化*/
	char	asFieldName[60][60];		/*TitleCtl2ReportHead初始化*/
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
	int	iDistanceFee;	/*移动交互报表*/
	int	iTotalDuration;		/*总时长，卫通*/
	int	iTotalSec;		/*结算时长，卫通*/
	int	iMoCnt;			/*MO次数*/
	int	iMtCnt;			/*MT次数*/
	int	iPayFee;		/*应付金额*/
	int	iIncomeFee;		/*应收金额*/
	int	iLatnID;		/*本地网标识CS,CMSMS,CUSMS用*/
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

	/*如果sheet紧接这一个sheet的特殊处理*/
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
	/*设置输出链表*/
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
			printf("分配内存 ReportHeadStruct 错误.\n");
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

		if(strstr(sTemp,"序号")!=NULL||
			strstr(sTemp,"结算原则")!=NULL||
			strstr(sTemp,"结算规则")!=NULL||
			strstr(sTemp,"结算方法")!=NULL||
			strstr(sTemp,"核对方")!=NULL) break;

		/*只取包含结算报表的标题的行*/
		if(strstr(sTemp,"结算")!=NULL&&(strstr(sTemp,"报表")!=NULL||
			 strstr(sTemp,"结算表")!=NULL)){
			TrimAll(sTemp);l=strlen(sTemp);
			m+=l;
			if(m>=127) return -1;
			strcat(sTitle,sTemp);
		}

		free(pTemp);
		iTitleLine++;
	}

	if(strstr(sTemp,"序号")==NULL&&strstr(sTemp,"结算原则")==NULL&&
		strstr(sTemp,"结算规则")==NULL&&strstr(sTemp,"结算方法")==NULL&&
		strstr(sTemp,"核对方")==NULL)
		return -1;

	strcat(sField,sTemp);

	iTitleLine++;

	if(pTemp==NULL) return -1;

	if(iReportType==1){
		/*移动短信交互报表则删除TITLE的第二行*/
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
	ReplaceStr(sTemp,"　","");
	
	if(strstr(sTemp,"石家庄")!=NULL)      iLatnID=11;
	else if(strstr(sTemp,  "邯郸")!=NULL) iLatnID=10;
	else if(strstr(sTemp,  "正定")!=NULL) iLatnID=11;
	else if(strstr(sTemp,  "保定")!=NULL) iLatnID=12;
	else if(strstr(sTemp,"张家口")!=NULL) iLatnID=13;
	else if(strstr(sTemp,  "承德")!=NULL) iLatnID=14;
	else if(strstr(sTemp,  "唐山")!=NULL) iLatnID=15;
	else if(strstr(sTemp,  "廊坊")!=NULL) iLatnID=16;
	else if(strstr(sTemp,  "沧州")!=NULL) iLatnID=17;
	else if(strstr(sTemp,  "衡水")!=NULL) iLatnID=18;
	else if(strstr(sTemp,  "邢台")!=NULL) iLatnID=19;
	else if(strstr(sTemp,"秦皇岛")!=NULL) iLatnID=35;
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

		if(strstr(sTemp,"序号")!=NULL||
			strstr(sTemp,"结算原则")!=NULL||
			strstr(sTemp,"结算规则")!=NULL||
			strstr(sTemp,"结算方法")!=NULL||
			strstr(sTemp,"核对方")!=NULL) iFlag=true;

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
	ReplaceStr(sTemp,"￥","");
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
		/*话单张数*/
		GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalCnt=atoi(sTemp);

		/*时长（分钟）*/
		GetSepStrX(sRecord,'\t',offset+5,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalMin=atoi(sTemp);
	}
	else{
		GetSepStrX(sRecord,'\t',offset+5,60,ptCur->sSettRule);
		if(strlen(ptCur->sSettRule)==0&&ptPre!=NULL)
			strcpy(ptCur->sSettRule,ptPre->sSettRule);
		/*话单张数*/
		GetSepStrX(sRecord,'\t',offset+3,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalCnt=atoi(sTemp);

		/*时长（分钟）*/
		GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
		RegularNumber(sTemp);
		ptCur->iTotalMin=atoi(sTemp);
	}

	GetSepStrX(sRecord,'\t',offset+2,60,ptCur->sDetailItemName);
	if(strlen(ptCur->sDetailItemName)==0){
		GetSepStrX(sRecord,'\t',offset+1,128,sTemp);
		if(strcmp(sTemp,"小计")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sDetailItemName,ptCur->sAcctItemName);
			strcat(ptCur->sDetailItemName,sTemp);
		}
		if(strcmp(sTemp,"合计")==0||
			strcmp(sTemp,"共计")==0||
			strcmp(sTemp,"总计")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sAcctItemName,"");
			strcpy(ptCur->sDetailItemName,sTemp);
		}
	}
	
	/*结算费用(元）*/
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

	/*话单张数*/
	GetSepStrX(sRecord,'\t',2,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*时长（分钟）*/
	GetSepStrX(sRecord,'\t',3,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalMin=atoi(sTemp);

	/*长途费*/
	GetSepStrX(sRecord,'\t',4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iDistanceFee=GetFloatCharge(sTemp);

	GetSepStrX(sRecord,'\t',5,60,ptCur->sSettRule);

	/*结算费用(元）*/
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

	/*通话时长（秒）*/
	GetSepStrX(sRecord,'\t',4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalDuration=atoi(sTemp);

	/*话单张数*/
	GetSepStrX(sRecord,'\t',5,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*结算时长*/
	GetSepStrX(sRecord,'\t',6,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalSec=atoi(sTemp);

	/*结算次数*/
	GetSepStrX(sRecord,'\t',7,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalMin=atoi(sTemp);

	/*结算费用(元）*/
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

	/*移动MO条数*/
	GetSepStrX(sRecord,'\t',offset+1,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iMoCnt=atoi(sTemp);

	/*移动MT条数*/
	GetSepStrX(sRecord,'\t',offset+2,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iMtCnt=atoi(sTemp);

	/*移动应付金额*/
	GetSepStrX(sRecord,'\t',offset+3,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iPayFee=GetFloatCharge(sTemp);

	/*移动应收金额*/
	GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iIncomeFee=GetFloatCharge(sTemp);

	GetSepStrX(sRecord,'\t',offset+5,60,ptCur->sSettRule);
	if(strlen(ptCur->sSettRule)==0&&ptPre!=NULL)
		strcpy(ptCur->sSettRule,ptPre->sSettRule);

	/*结算费用(元）*/
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
	/*话单张数*/
	GetSepStrX(sRecord,'\t',offset+3,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*时长（分钟）*/
	GetSepStrX(sRecord,'\t',offset+4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalMin=atoi(sTemp);

	GetSepStrX(sRecord,'\t',offset+2,60,ptCur->sDetailItemName);
	if(strlen(ptCur->sDetailItemName)==0){
		GetSepStrX(sRecord,'\t',offset+1,128,sTemp);
		if(strcmp(sTemp,"小计")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sDetailItemName,ptCur->sAcctItemName);
			strcat(ptCur->sDetailItemName,sTemp);
		}
		if(strcmp(sTemp,"合计")==0||
			strcmp(sTemp,"共计")==0||
			strcmp(sTemp,"总计")==0){
			strcpy(ptCur->sSettRule,"");
			strcpy(ptCur->sAcctItemName,"");
			strcpy(ptCur->sDetailItemName,sTemp);
		}
	}
	
	/*结算费用(元）*/
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

	/*话单张数*/
	GetSepStrX(sRecord,'\t',4,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalCnt=atoi(sTemp);

	/*结算时长*/
	GetSepStrX(sRecord,'\t',5,128,sTemp);
	RegularNumber(sTemp);
	ptCur->iTotalSec=atoi(sTemp);

	/*结算规则*/
	GetSepStrX(sRecord,'\t',6,128,ptCur->sSettRule);

	/*结算费用(元）*/
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

		/*如果不存在数字的行，则忽略*/
		if(ExistDigital(sRecord)==false&&ExistChinese(sRecord)==false){
			iLine++;
			continue;
		}

		if((ptCur=malloc(sizeof(struct ReportBodyStruct)))==NULL){
			printf("分配内存 ReportBodyStruct 失败.\n");
			return -1;
		}
		bzero((void*)ptCur,sizeof(struct ReportBodyStruct));

		if(cvitem_str2reportbody(sRecord,sType,ptPre,ptCur,iReportType)<0){
			printf("类型非法%s,[CT,CM,CU,CRC,CS,CMSMS,CUSMS]",sType);
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
			printf("类型%s非法.\n",sType);
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
			printf("类型%s非法.\n",sType);
			return -1;
		}
	}
	else{
		printf("报表类型%01d非法.\n",iReportType);
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
				printf("内存分配错误.\n");
				return -1;
			}
		}
	}

	ReverseList((LIST**)&ptLkHead);

	if((iCnt=list2fileln(&ptLkHead,sTargetName))<0){
		printf("链表写入%s文件错误.\n",sTargetName);
		return -1;
	}

	return iCnt;
}
/**
type	类型及描述
CT 	电信语音
CRC	铁通语音
CU	联通语音      本方的分为:CUGSM,CUCDM
CM	移动语音
CS	卫通语音

CMSMS	移动短信
CUSMS	电信短信
**/
/**
sReportID	报表类型
1		对端报表
2		本方报表
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
		printf("输入帐期无效　%s.\n",sBillingCycleID);
		return -1;
	}
	/*将文件读到InHead结构链表*/
	if(TxtFileToList(sSourceName,&pCtl)<0){
		printf("文件%s加载到内存错误.\n",sSourceName);
		return -1;
	}

	/***根据sheet=x sheet=y分割 sheet*/
	if(SplitCtlBySheet(pCtl,sBillingCycleID,sType,iReportType,&ptLkHead)<0)
		return -1;

	ptHead=ptLkHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*将AllCtl链表根据不同逻辑，分割链表中的title和body*/
		pTemp->iTitleLine=SplitAllCtl(&(pTemp->pAllCtl),pTemp->sTitle,
			sType,iReportType,pTemp->sField,&(pTemp->pBodyCtl));

		/*对没内容的SHEET直接删除*/
		if(pTemp->iTitleLine==9999) continue;

		if(pTemp->iTitleLine<0){
			printf("SplitAllCtl错误 %d\n",pTemp->iSheet);
			return -1;
		}

		/*将TitleCtl转换出需要的元素*/
		TitleCtl2ReportHead(pTemp->sTitle,pTemp->sField,pTemp);
		if(iReportType==1){
			/*如果是CM的类型取参数的本地网*/
			if(strcmp(sType,"CM")==0&&pTemp->iLatnID==-1)
				pTemp->iLatnID=GetLatnIDFromRemark(sSourceName);
		}

		/*将BodyCtl转换出需要的元素到链表*/
		if(BodyCtl2ReportBodyList(pTemp->pBodyCtl,pTemp->iTitleLine,
			sType,iReportType,&(pTemp->pBody))<0) return -1;
	}

	/*将OutHead链表输出到文件*/
	if((iCnt=Output2TxtFile(ptLkHead,sReportID,sType,iReportType,sTargetName))<0)
		return -1;

	printf("将文件%s转换为%s文件成功,生成%d条纪录.\n",
		sSourceName,sTargetName,iCnt);

	return 0;
}

