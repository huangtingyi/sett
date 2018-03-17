
#include <hnixs.h>
#include <list.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwsupp.h>
#include <trie.h>

int FileModifyDiff(char sFileName[])
{
	time_t tHostTime;
	struct stat Temp;

	bzero((void*)&Temp,sizeof(struct stat));

	if(stat(sFileName,&Temp)<0) return -1;

	if(time(&tHostTime)<0) return -1;

	return tHostTime-Temp.st_mtime;	
}
int FileModifyDate(char sFileName[],char sModifyDate[])
{

	struct stat Temp;

	strcpy(sModifyDate,"");
	bzero((void*)&Temp,sizeof(struct stat));

	if(stat(sFileName,&Temp)<0) return -1;

	if(sFormatTime(Temp.st_mtime,sModifyDate)<0) return -1;
		
	return 0;
}

int FileBackupDate(char sFileName[],char sDateRule[],char sBackupDate[])
{	
	char *pc,sTemp[15],sBaseName[128];
	int iYear,iYearOff,iYearLen,iMonth,iMonthOff,iMonthLen;
	int iDate,iDateOff,iDateLen;

	strcpy(sBackupDate,"");

	if((pc=strrchr(sFileName,'/'))==NULL)
		strcpy(sBaseName,sFileName);
	else
		strcpy(sBaseName,pc+1);

        strncpy(sTemp,sDateRule,2);sTemp[2]=0;
        iYearOff= atoi(sTemp);
	strncpy(sTemp,sDateRule+2,2);sTemp[2]=0;
        iYearLen=atoi(sTemp);

        if(iYearLen!=2&&iYearLen!=4) return 0;
        if(iYearOff>strlen(sBaseName)-iYearLen) return -1;

        strncpy(sTemp,sDateRule+4,2);sTemp[2]=0;
        iMonthOff= atoi(sTemp);
        strncpy(sTemp,sDateRule+6,2);sTemp[2]=0;
        iMonthLen= atoi(sTemp);

        if(iMonthLen!=2&&iMonthLen!=1) return 0;
        if(iMonthOff>strlen(sBaseName)-iMonthLen) return -1;

        strncpy(sTemp,sDateRule+8,2);sTemp[2]=0;
        iDateOff=atoi(sTemp);
        strncpy(sTemp,sDateRule+10,2);sTemp[2]=0;
        iDateLen=atoi(sTemp);

        if(iDateLen!=2&&iDateLen!=1) return 0;
        if(iDateOff>strlen(sBaseName)-iDateLen) return -1;

        strncpy(sTemp,sBaseName+iYearOff,iYearLen);sTemp[iYearLen]=0;
        iYear=atoi(sTemp);
        if(iYear<50) iYear+=2000;
        if(iYear<100) iYear+=1900;

        strncpy(sTemp,sBaseName+iMonthOff,iMonthLen);sTemp[iMonthLen]=0;
        iMonth=atoi(sTemp);
        if(iMonth<=0||iMonth>12) return -1;

        strncpy(sTemp,sBaseName+iDateOff,iDateLen);sTemp[iDateLen]=0;
        iDate=atoi(sTemp);
        if(iDate<=0||iDate>31) return -1;

        sprintf(sBackupDate,"%4d%02d%02d000000",iYear,iMonth,iDate);

	return 0;
}
int ParseTabArg(char sRecord[])
{
	int i;

	memset(ParseToken,0,PARSE_ARRAY_LEN*PARSE_ITEM_LEN);

	for(i=0;i<PARSE_ARRAY_LEN;i++){
		GetTabStrX(sRecord,i,PARSE_ITEM_LEN,ParseToken[i]);
		if(strlen(ParseToken[i])==0) break;
	}
	return i;
}
static int IsDateTimeTag(char sStr[])
{
	static int i,len,iFirstFlag=true;
	static char asTag[30][10];

	if(iFirstFlag==true){
		iFirstFlag=false;
		i=0;
		strcpy(asTag[i],"Jan");i++;
		strcpy(asTag[i],"Feb");i++;
		strcpy(asTag[i],"Mar");i++;
		strcpy(asTag[i],"Apr");i++;
		strcpy(asTag[i],"May");i++;
		strcpy(asTag[i],"Jun");i++;
		strcpy(asTag[i],"Jul");i++;
		strcpy(asTag[i],"Aug");i++;
		strcpy(asTag[i],"Sep");i++;
		strcpy(asTag[i],"Oct");i++;
		strcpy(asTag[i],"Nov");i++;
		strcpy(asTag[i],"Dec");i++;
		
		strcpy(asTag[i],"1��");i++;
		strcpy(asTag[i],"2��");i++;
		strcpy(asTag[i],"3��");i++;
		strcpy(asTag[i],"4��");i++;
		strcpy(asTag[i],"5��");i++;
		strcpy(asTag[i],"6��");i++;
		strcpy(asTag[i],"7��");i++;
		strcpy(asTag[i],"8��");i++;
		strcpy(asTag[i],"9��");i++;
		strcpy(asTag[i],"10��");i++;
		strcpy(asTag[i],"11��");i++;
		strcpy(asTag[i],"12��");i++;

		len=i;
	}
	for(i=0;i<len;i++)
		if(strncmp(sStr,asTag[i],strlen(asTag[i]))==0) return true;
	return false;
}
int GetFtpDirSize(char sRecord[])
{
	int i,l,iPos;

/*�����������ַ����ŵ��ڴ滺��*/
	if((l=ParseTabArg(sRecord))<2) return -1;

/*�ҵ������λ��*/
	for(i=0;i<l;i++)
		if(IsDateTimeTag(ParseToken[i])==true) break;

/*�Ҳ���ʱ��,����ʱ���ڵ�һλ*/
	if(i==0)return -1;

/*�ҳ�����ǰһλ��Ӧλ��,��ʱ��dir�����Ϊ��
10-19-05  12:08PM              1024000 UNFT2106GCDR*/
	if(i==l) iPos=l-2;
	else iPos=i-1;
/*���ַ������Ϸ��Լ��,����������������*/
	for(i=0;i<strlen(ParseToken[iPos]);i++)
		if(!isdigit(ParseToken[iPos][i])) return -1;

	return atoi(ParseToken[iPos]);
}
void GetFtpFileName(char sRecord[],char sFilter[],char sFileName[])
{
	int i;
	char sTemp[1024],sTemp1[1024];
	
	strcpy(sFileName,"");

	if((i=GET_TAB_CNT(sRecord))==1){
		
		strcpy(sTemp,sRecord);
		TrimAll(sTemp);
		if(PatternMatch(sTemp,sFilter)==true)
			strcpy(sFileName,sTemp);
		return;
	}
/*�����һ����total�����֡���ģʽ���ⲻ���ļ���*/
	if(i==2){
		GetTabStrX(sRecord,0,1024,sTemp);
		GetTabStrX(sRecord,1,1024,sTemp1);
		if(strcmp(sTemp,"total")==0&&
			IsAllDigit(sTemp1)==true) return;
	}
/*ȡ���һ��������Ϊ�ļ���*/
	GetTabStrX(sRecord,i-1,1024,sTemp);
	
	if(PatternMatch(sTemp,sFilter)==true)
		strcpy(sFileName,sTemp);
}

void GetFileSplit(char sSource[],char sRawName[],char sFileSplit[])
{
	char sPath[256],sBaseName[256];

	GetAppHome(sPath);
	GetBaseName(sRawName,sBaseName);

	sprintf(sFileSplit,"%swork/%s%s.lst",sPath,sSource,sBaseName);
}
void mvitem_ctl2tinysplit(struct FileControlStruct *pi,
	struct TinySplitStruct *po)
{
	int l;
	char sLine[256],sTemp[10];

	l=pi->iLen>255?255:pi->iLen;

	strncpy(sLine,(char*)pi->pData,l);sLine[l]=0;

	bzero((void*)po,sizeof(struct TinySplitStruct ));

	GetSepStrX(sLine,'\t',0,1,po->sSplitType);
	GetSepStrX(sLine,'\t',1,9,po->sKey);

	GetSepStrX(sLine,'\t',2,10,sTemp);
	po->iCnt=atoi(sTemp);
}
int InitTinySplitList(char sSource[],char sBaseName[],
	struct TinySplitStruct **pptHead)
{

	char sFileSplit[256];
	struct FileControlStruct *ptHead,*pTemp;
	struct TinySplitStruct *ptPre=NULL,*ptCur;

	*pptHead=NULL;

	GetFileSplit(sSource,sBaseName,sFileSplit);
	/*����ļ����������ʼ��Ϊ��*/
	if(FileSize(sFileSplit)<=0) return 0;

	if(TxtFileToList(sFileSplit,&ptHead)<0){
		WriteAlertMsg("�����ļ�%s���ڴ�ʧ��",sFileSplit);
		return -1;
	}
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((ptCur=malloc(sizeof(struct TinySplitStruct)))==NULL){
			WriteAlertMsg("�����ڴ�ʧ��");
			return -1;
		}

		mvitem_ctl2tinysplit(pTemp,ptCur);
		free(pTemp);
		InsertList((LIST**)&ptPre,(LIST*)ptCur);
	}
	*pptHead=ptPre;

	return 0;	
}
int SearchTinySplit(struct TinySplitStruct *ptHead,char cSplitType)
{
	while(ptHead!=NULL){
		if(cSplitType==ptHead->sSplitType[0]) return FOUND;
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void RemoveFileSplit(char sSource[],char sBaseName[])
{
	char sFileSplit[256];

	GetFileSplit(sSource,sBaseName,sFileSplit);
	execcmd("rm -f %s",sFileSplit);
}
int SearchTinyRollLog(struct TinyRollLogStruct *ptHead,char sOriFileName[],
	char sFileName[], struct TinyRollLogStruct **pptCur)
{
	*pptCur=NULL;
	while(ptHead!=NULL){
		if(strcmp(sOriFileName,ptHead->sOriFileName)==0&&
			strcmp(sFileName,ptHead->sFileName)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
int SumTinyRollLog(struct TinyRollLogStruct **pptHead,
	char sOriFileName[],char sFileName[],int iCnt)
{
	char sBaseName[128];
	struct TinyRollLogStruct *pTemp=NULL;

	GetBaseNameX(sFileName,sBaseName);

	if(SearchTinyRollLog(*pptHead,sOriFileName,sBaseName,&pTemp)
		==NOTFOUND){
		if((pTemp=malloc(sizeof(struct TinyRollLogStruct)))==NULL){
			WriteAlertMsg("�����ڴ�TinyRollLogStruct����");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct TinyRollLogStruct));
		strcpy(pTemp->sOriFileName,sOriFileName);
		strcpy(pTemp->sFileName,sBaseName);
		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	pTemp->iCnt+=iCnt;
	return 0;	
}
void GetRollLogCtl(char sRawName[],char sRollLogCtl[])
{
	char sPath[256],sBaseName[256];

	GetAppHome(sPath);
	GetBaseName(sRawName,sBaseName);

	sprintf(sRollLogCtl,"%swork/%s.lst",sPath,sBaseName);
}
void RemoveRollLogCtl(char sBaseName[])
{
	char sRollLogCtl[256];

	GetRollLogCtl(sBaseName,sRollLogCtl);
	execcmd("rm -f %s",sRollLogCtl);
}
int WriteRollLogCtl(struct TinyRollLogStruct *ptHead,char sFileName[])
{
	char sRecord[256],sBaseName[128],sRollLogCtl[256];
	struct TinyRollLogStruct *pTemp;
	struct FileControlStruct *pLog=NULL;

	GetBaseNameX(sFileName,sBaseName);

	GetRollLogCtl(sBaseName,sRollLogCtl);

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		sprintf(sRecord,"%s\t%s\t%d\n",pTemp->sOriFileName,
			pTemp->sFileName,pTemp->iCnt);

		if(item2listtail(&pLog,sRecord,strlen(sRecord))<0) return -1;

		free(pTemp);
	}
	if(list2file(&pLog,sRollLogCtl)<0){
		printf("д�ļ�%s����.\n",sRollLogCtl);
		return -1;
	}
	return 0;
}
void mvitem_ctl2tinyrolllog(struct FileControlStruct *pi,
	struct TinyRollLogStruct *po)
{
	int l;
	char sLine[256],sTemp[10];

	l=pi->iLen>255?255:pi->iLen;

	strncpy(sLine,(char*)pi->pData,l);sLine[l]=0;

	bzero((void*)po,sizeof(struct TinyRollLogStruct ));

	GetSepStrX(sLine,'\t',0,40,po->sOriFileName);
	GetSepStrX(sLine,'\t',1,40,po->sFileName);

	GetSepStrX(sLine,'\t',2,10,sTemp);
	po->iCnt=atoi(sTemp);
}
int InitRollLogCtl(char sBaseName[],struct TinyRollLogStruct **pptHead)
{

	char sRollLogCtl[256];
	struct FileControlStruct *ptHead,*pTemp;
	struct TinyRollLogStruct *ptPre=NULL,*ptCur;

	*pptHead=NULL;

	GetRollLogCtl(sBaseName,sRollLogCtl);
	/*����ļ����������ʼ��Ϊ��*/
	if(FileSize(sRollLogCtl)<=0) return 0;

	if(TxtFileToList(sRollLogCtl,&ptHead)<0){
		WriteAlertMsg("�����ļ�%s���ڴ�ʧ��",sRollLogCtl);
		return -1;
	}
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if((ptCur=malloc(sizeof(struct TinyRollLogStruct)))==NULL){
			WriteAlertMsg("�����ڴ�ʧ��");
			return -1;
		}

		mvitem_ctl2tinyrolllog(pTemp,ptCur);
		free(pTemp);
		InsertList((LIST**)&ptPre,(LIST*)ptCur);
	}
	*pptHead=ptPre;

	return 0;	
}

int WantCtl(char sAppName[])
{
	char sBillHome[256],sBaseName[32],sNewName[256];
	
	GetBillHome(sBillHome);
	GetBaseName(sAppName,sBaseName);
	
	sprintf(sNewName,"%sbin/%s",sBillHome,sBaseName);
	
	if(strcmp(sNewName,sAppName)==0) return true;
	
	return false;
}

void GetLogLock(char sStep[],char sSourceID[],char sDate[],
	char sLockName[])
{
	char sPath[256];
	
	GetAppHome(sPath);
	
	if(strlen(sDate)!=0)
		sprintf(sLockName,"%sctl/%s_%s_%s.txt",sPath,sStep,sSourceID,sDate);
	else	sprintf(sLockName,"%sctl/%s_%s.txt",sPath,sStep,sSourceID);
		
}
int LockLog(char sLockName[],char msg[])
{
	time_t tDiff;
	char sCommand[256],sResult[256];

	strcpy(msg,"");

	/*�ļ���������*/
	if(!IsFile(sLockName)){
		sprintf(sCommand,"echo start %d > %s ",getpid(),sLockName);
	
		if(exec2str(sCommand,sResult)!=0){
			sprintf(msg,"ִ��%sʧ��",sCommand);
			return -1;
		}
		return 0;
	}
	/*�ļ��������Ƿ���start*/
	while(1){

		if(!IsFile(sLockName)) break;

		if(ReadFileToBuf(sLockName,256,sResult,msg)<0)
			return -1;

		if(strncmp(sResult,"start",5)!=0) break;
		
		/*����1�����������Զ�����*/
		tDiff=tGetHostTime()-FileModifyTime(sLockName);
		if(tDiff>60){
			WriteProcMsg("������ʱ��,1����,�Զ�����,lockname=%s",
				sLockName);
			break;
		}

		sprintf(msg,"lockname=%s,����ͻ",sLockName);
		return 1;
	}
	/*����Ѿ��������Լ�����*/
	sprintf(sCommand,"echo start %d > %s ",getpid(),sLockName);
	system(sCommand);

	return 0;
}
void UnlockLog(char sLockName[])
{
	char sCommand[256];

	sprintf(sCommand,"rm -rf %s",sLockName);
	system(sCommand);
}

/*�ж��Ƿ����ڲ��ļ���,�ļ���::$SOURCEYYYYMMDDNNNNN.��ͷ*/
int IsInternalName(char sBaseName[])
{
	char sTempName[20],sTempDate[15];
	
	if(sBaseName[19]!='.') return false;

	strncpy(sTempName,sBaseName,19);sTempName[19]=0;
	
	if(strlen(sTempName)!=19) return false;
	
	/*������ں�SEQ�з��ַ���Ϣ����Ƿ�*/
	if(!IsAllDigit(sTempName+6)) return false;
	
	strncpy(sTempDate,sTempName+6,8);
	strcpy(sTempDate+8,"000000");
	
	if(tGetTime(sTempDate)<0) return false;
	
	return true;
}

struct HeadDpStruct
{
	struct HeadDpStruct *pNext;
	char	sHeadDp[21];
	char	sHead[21];
	int	iHeadLen;
	struct HeadDpStruct *pLoadNext;
};

int GetHeadCarrStr(char sHeadCarrDp[],char sHeadCarrStr[])
{
	int iRet;
	char sTemp[512],sPath[128];

	GetIniName(sPath);
	iRet=ReadString(sPath,"bss","headcarr",sHeadCarrDp,sTemp);

	ERROR_RETURNZ(iRet<0,"��ȡbill.ini�ļ�ʧ��");

	ERROR_RETURNA((strlen(sTemp)==0),"bill.ini->bss->headcarr-%s�޶�Ӧ����",
		sHeadCarrDp);
	strcpy(sHeadCarrStr,sTemp);
	return 0;
}
int IsDpAccNbr(char sDp[],char sAccNbr[])
{
	struct HeadDpStruct *pTemp=NULL,*ptHead;
        static  TRIE *pRoot=NULL;
        static int iFirstFlag=true;


	if(iFirstFlag==true){
		int iCnt=0,i=0,j=0,iItemCnt=0;
		char sHeadStr[512],sHeadDpStr[512],sHeadDp[21],sHead[21];
		struct HeadDpStruct *p;

		iFirstFlag=false;

		if(GetHeadCarrStr("headdp",sHeadDpStr)!=0){
			WriteAlertPrint("bill.ini��[headcarr]->headdp����");
			exit(1);
		}

		iCnt=GetSepCnt(sHeadDpStr,',');

		while(i<iCnt){
			GetSepStrX(sHeadDpStr,',',i,20,sHeadDp);

			if(GetHeadCarrStr(sHeadDp,sHeadStr)!=0){
				WriteAlertPrint("bill.ini��[headcarr]->%s����",sHeadDp);
				exit(1);
			}

			iItemCnt=GetSepCnt(sHeadStr,',');

			j=0;
			while(j<iItemCnt){

				p=(struct HeadDpStruct*)
					malloc(sizeof(struct HeadDpStruct));
				ERROR_EXIT(p==NULL,"�����ڴ����");

				GetSepStrX(sHeadStr,',',j,20,sHead);

				strcpy(p->sHeadDp,sHeadDp);
				strcpy(p->sHead,sHead);
				p->iHeadLen=strlen(sHead);

				if(InsertTrie(&pRoot,sHead,(void *)p,
					assign_insert_trie)<0){
				        WriteAlertPrint("����TRIEʧ��sHead");
			        	exit(1);
			        }
			        j++;
			}
			i++;
		}
		ReHookTrie(pRoot,pRoot);
	}

	if(SearchTrie(pRoot,sAccNbr,(void**)&ptHead)==NOTFOUND)return false;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;	
		if(strcmp(sDp,pTemp->sHeadDp)==0&&
			strncmp(sAccNbr,pTemp->sHead,pTemp->iHeadLen)==0)
			return true;
	}

	return false;
}
int SearchAppNext(struct AppNextStruct *ptHead,char sPath[],char sFilter[],
	char sTaskName[],char sAppCodeGrp[])
{
	while(ptHead!=NULL){
		if(strcmp(sPath,ptHead->sPath)==0&&
			strcmp(sFilter,ptHead->sFilter)==0&&
			strcmp(sTaskName,ptHead->sTaskName)==0&&
			strcmp(sAppCodeGrp,ptHead->sAppCodeGrp)==0)
			return FOUND;
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void ReadTaskInfo(char sCtlName[],char sSourceID[],int *ppid,char sTaskTime[])
{
	char sResult[1024],sTemp[256];

	strcpy(sSourceID,"");
	*ppid=0;
	strcpy(sTaskTime,"");

	/*���ﲻУ�����*/
	file2str(sCtlName,sResult);

	GetTabStr(sResult,0,sTemp);
	strncpy(sSourceID,sTemp,31);sSourceID[31]=0;AllTrim(sSourceID);

	GetTabStr(sResult,1,sTemp); *ppid=atoi(sTemp);

	GetTabStr(sResult,2,sTemp);
	strncpy(sTaskTime,sTemp,63);sTaskTime[63]=0;AllTrim(sTaskTime);
}
/*2009.09.08д��Ϣ�ļ������ֶ�����ֵ������¸���*/
void WriteTaskInfo(char sCtlName[],char sSourceID[],char sTaskPid[],
	char sTaskTime[])
{
	int iPid;
	char buf[128],sTempSourceID[32],sTempTime[64],sTempPid[64];
	
	ReadTaskInfo(sCtlName,sTempSourceID,&iPid,sTempTime);
	sprintf(sTempPid,"%d",iPid);
	
	if(strlen(sSourceID)!=0) strcpy(sTempSourceID,sSourceID);
	if(strlen(sTaskPid)!=0)	strcpy(sTempPid,sTaskPid);
	if(strlen(sTaskTime)!=0) strcpy(sTempTime,sTaskTime);
	
	sprintf(buf,"%s %s %s",sTempSourceID,sTempPid,sTempTime);
	
	/*���ﲻУ�����*/
	str2file(buf,sCtlName);
}

void GetAppCode(char sTask[],char sAppCode[])
{
	char sTaskName[256];

	strcpy(sAppCode,"");

	GetTabStrX(sTask,0,255,sTaskName);
	GetBaseName(sTaskName,sAppCode);

	Upper(sAppCode);

	if(RLike(sAppCode,".SH")||
		RLike(sAppCode,"_SH"))sAppCode[strlen(sAppCode)-3]=0;

}
int GetAppGrp(char sTask[])
{
	char sGrp[80];

	GetTabStrX(sTask,2,79,sGrp);
	
	return atoi(sGrp);
}
/*�ļ���ʽΪ��
	fprintf(fp,"%s\t%s\t%s\t%s\n",
		p->sPath,p->sFilter,p->sTaskName,p->sAppCodeGrp);
�ο�,shedtsk.c::WriteAppNextFile����*/
void GetAppNextFileName(char sTask[],char sFileName[])
{
	int iGrpID;
	char sCtlPath[256],sAppCode[64];
	
	GetAppHome(sCtlPath);strcat(sCtlPath,"ctl/");
	
	GetAppCode(sTask,sAppCode);
	iGrpID=GetAppGrp(sTask);
	
	sprintf(sFileName,"%s%s%02d.anf",sCtlPath,sAppCode,iGrpID);
}
/*�ο�WriteTaskStatus����,
 ״̬ͼΪ��shedtsk д�� start,
 	Ӧ�ý��� running,�쳣�˳�abort,�����˳�exit,
 	   shedtsk ÿ�ε��ȼ���׼���̣����Ϊstart ����*/
void GetAppCurFileName(char sTask[],char sFileName[])
{
	int iGrpID;
	char sCtlPath[256],sAppCode[64];
	
	GetAppHome(sCtlPath);strcat(sCtlPath,"ctl/");
	
	GetAppCode(sTask,sAppCode);
	iGrpID=GetAppGrp(sTask);
	
	sprintf(sFileName,"%s%s%02d.acf",sCtlPath,sAppCode,iGrpID);
}

void WriteTaskStatus(char sTask[],char sSourceID[],char sStatus[],
	char sStateDate[],int iCycle,int iOffset,int iForceFlag)
{
}
void ReadTaskStatus(char sTask[],char sSourceID[],char sStatus[],
	char sStateDate[],int *piCycle,int *piOffset,int *piForceFlag)
{
}
/* ���������һ������ʱ�̵�TIME_Tʱ�� */
time_t GetStartupTimeInterval(int iCycle,int iOffset)
{
	char sHostTime[15],sHostDate[15];
	time_t tHostTime,tHostDate,tCycle,tOffset,tBegin;

	tCycle=(time_t)iCycle*(time_t)10;
	tOffset=(time_t)iOffset*(time_t)10;


	GetHostTime(sHostTime);
	
	strcpy(sHostDate,sHostTime);
	strcpy(sHostDate+8,"000000");

	tHostTime=tGetTime(sHostTime);
	tHostDate=tGetTime(sHostDate);


	tBegin=(tHostTime-tHostDate+tCycle-1)/tCycle*tCycle+tHostDate;

	return tBegin+tOffset-tHostTime;
}
