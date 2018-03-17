#include <stdio.h>
#include <stdlib.h>

#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>

#include <param_intf.h>
#include <appsupp.h>

#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <ticket_field.h>
#include <tariff_disct.h>

#include <ticket.h>
#include <stt_ticket.h>
#include <bill_supp.h>

struct FileListStruct
{
	struct FileListStruct *pNext;
	char	sBaseName[64];
	char	sSourceID[7];
	char	sDataDate[15];
	int	iByte;
	char	sSplitStr[40];
	int	iCnt;
	int	iNormalCnt;
	int	iAbnoCnt;
	int	iNewCnt;
	char	sTempBaseName[64];
	char	sDealBeginDate[15];
	char	sDealEndDate[15];
	struct TinySplitStruct *pHead;
};

char BILLING[256],EXPRPATH[256],SHELLPATH[256];
int InitBillCtl()
{
	char sPath[256];

	GetBillHome(sPath);

	sprintf(EXPRPATH,"%sexpr/",sPath);
	sprintf(SHELLPATH,"%sshell/",sPath);

	if(IsFile(BILLING)==FALSE){
		printALERT("文件%s无效",BILLING);
		return -1;
	}

	if(IsDir(EXPRPATH)==FALSE){
		printALERT("目录%s无效",EXPRPATH);
		return -1;
	}
	
	if(IsDir(SHELLPATH)==FALSE){
		printALERT("目录%s无效",SHELLPATH);
		return -1;
	}

	return 0;

}
static int GenFileList(struct FileControlStruct *ptHead,
	char sSourceID[],char sPath[],struct FileListStruct **pptList)
{
	char sBaseName[64],sTempName[256],sTempDate[15];
	struct FileControlStruct *pTemp;
	struct FileListStruct *pList;
		
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sBaseName,(char*)(pTemp->pData),pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		AllTrim(sBaseName);

		/*如果拿到的不是一个合法的文件名，则自动跳过*/
		if(IsInternalName(sBaseName)==false){
			free(pTemp);
			continue;
		}

		strncpy(sTempDate,sBaseName+6,8);
		strcpy(sTempDate+8,"000000");
		/*已经是一个合法25位的文件名$SOURCEYYYYMMDDNNNNN.
		按时间分割文件名34位，如：XMGW012009032000000.FIX.J.20090319
		*/
		if(strlen(sBaseName)==34&&ChkDate(sBaseName+26)==0){
			strncpy(sTempDate,sBaseName+26,8);
			strcpy(sTempDate+8,"000000");
		}
		if(tGetTime(sTempDate)<0){
			GetHostTime(sTempDate);
			strcpy(sTempDate+8,"000000");
		}

		if((pList=malloc(sizeof(struct FileListStruct)))==NULL){
			printALERT("分配内存 FileListStruct　失败");
			return -1;
		}
		bzero((void*)pList,sizeof(struct FileListStruct));
		
		strcpy(pList->sSourceID,sSourceID);
		strcpy(pList->sBaseName,sBaseName);
		strcpy(pList->sDataDate,sTempDate);
		sprintf(sTempName,"%s%s",sPath,sBaseName);
		pList->iByte=	FileSize(sTempName);
		InsertList((LIST**)pptList,(LIST*)pList);
		free(pTemp);
	}
	return 0;
}
/*如果BatchFlag=='0'则，只加入一条记录处理*/
static int GetFileList(struct FileListStruct **pptList,int iMaxBytes,
	char sPath[],char sModule[],char sDataDate[],char sBatchFlag[],
	struct FileListStruct **pptHead)
{
	int iTotalBytes=0;
	char	sTempName[256];
	struct FileListStruct *ptHead=*pptList,*pTemp;
	
	*pptList=NULL;
	*pptHead=NULL;
	strcpy(sDataDate,"");

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		/*获取一个sDataDate*/
		if(strlen(sDataDate)==0)
			strcpy(sDataDate,pTemp->sDataDate);

	/*如果不是同一天的，则不打包为一个文件*/
		if(strcmp(sDataDate,pTemp->sDataDate)!=0){
			InsertList((LIST**)pptList,(LIST*)pTemp);
			continue;
		}

	/*如果文件刚被修改则不处理*/
		sprintf(sTempName,"%s%s",sPath,pTemp->sBaseName);
		if(FileModifyDiff(sTempName)<1){
			free(pTemp);
			continue;
		}

	/*检查文件是否被处理，如果处理了则不处理了*/
		if(BillingLogCheck(pTemp->sSourceID,pTemp->sBaseName,
			sModule,"")==1){
			printNORMAL("文件%s已处理",pTemp->sBaseName);
			free(pTemp);
			continue;
		}
	
	/*如果条件都满足则加入到新的列表中去*/
		InsertList((LIST**)pptHead,(LIST*)pTemp);
		iTotalBytes+=pTemp->iByte;
		
	/*如果累计字节数大于最大字节数，则将后续列表保存*/
		if(iTotalBytes>iMaxBytes||sBatchFlag[0]=='0'){
			AppendListTail((LIST**)pptList,(LIST*)ptHead);
			break;
		}
	}
	if(*pptHead==NULL) return NOTFOUND;
	return FOUND;
}
int GetTinySplitList(struct FileListStruct *ptHead,
	struct TinySplitStruct **pptCur)
{
	struct TinySplitStruct *ptLkHead=NULL,*pTemp;
	
	while(ptHead!=NULL){
		if(InitTinySplitList(ptHead->sSourceID,ptHead->sBaseName,&pTemp)<0)
			return -1;
		
		AppendListTail((LIST**)pTemp,(LIST*)ptLkHead);
		ptLkHead=pTemp;
		
		ptHead=ptHead->pNext;
	}
	*pptCur=ptLkHead;
	return 0;
}
static int SplitTypeInTiny(char sSplitType[],struct TinySplitStruct *ptHead)
{
	while(ptHead!=NULL){
		if(strcmp(sSplitType,ptHead->sSplitType)==0) return true;
		ptHead=ptHead->pNext;
	}
	return false;
}
/*从FILELIST链表中获取生成的sSplitStr串*/
static void GetSplitStrList(struct FileListStruct *ptHead,char sSplitStr[])
{
	int i=0;
	char str[2];

	strcpy(sSplitStr,"");

	while(ptHead!=NULL){
		for(i=0;i<strlen(ptHead->sSplitStr);i++){

			str[0]=ptHead->sSplitStr[i];str[1]=0;

			if(strstr(sSplitStr,str)==NULL&&
				SplitTypeInTiny(str,ptHead->pHead)==false)
				strcat(sSplitStr,str);
		}
		ptHead=ptHead->pNext;
	}
}
static int ReadSplitType2List(struct FileListStruct *ptHead,char sPath[],
	char sSplitType[],struct FileControlStruct **pptHead)
{
	char sTempName[256];
	struct FileControlStruct *pTemp;

	*pptHead=NULL;
	
	while(ptHead!=NULL){
		if(strstr(ptHead->sSplitStr,sSplitType)!=NULL){
			sprintf(sTempName,"%s%s.%s.tmp",sPath,
				ptHead->sTempBaseName,sSplitType);

			if(TxtFileToList(sTempName,&pTemp)<0) return -1;
			
			AppendListTail((LIST**)&pTemp,(LIST*)*pptHead);
			*pptHead=pTemp;
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}
static int RemoveSplitTypeFile(struct FileListStruct *ptHead,char sPath[])
{
	int i;
	char sTempName[256],sSplitType[2];

	while(ptHead!=NULL){
		for(i=0;i<strlen(ptHead->sSplitStr);i++){
			
			sSplitType[0]=ptHead->sSplitStr[i];sSplitType[1]=0;
			
			if(SplitTypeInTiny(sSplitType,ptHead->pHead)==true)
				continue;

			sprintf(sTempName,"%s%s.%c.tmp",sPath,
				ptHead->sTempBaseName,ptHead->sSplitStr[i]);
			if(Remove(sTempName)<0){
				printALERT("删除文件%s失败",sTempName);
				return -1;
			}
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}
/*查找tinySplit结构中SPLIT和KEY节点是否存在*/
int SearchMyTinySplit(struct TinySplitStruct *ptHead,char sSplitType[],
	char sKey[])
{
	while(ptHead!=NULL){
		if(strcmp(sSplitType,ptHead->sSplitType)==0&&
			strcmp(sKey,ptHead->sKey)==0)
			return FOUND;

		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
/*从FILELIST中DISTINCT出SPLIT和KEY的TinySplit列表*/
static int GetSplitKeyList(struct FileListStruct *ptHead,
	struct TinySplitStruct **pptHead)
{
	struct TinySplitStruct *ptPre,*ptCur,*pTemp;
	
	while(ptHead!=NULL){
		ptCur=ptHead->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;

			if(SearchMyTinySplit(*pptHead,ptPre->sSplitType,
				ptPre->sKey)==NOTFOUND){
				pTemp=malloc(sizeof(struct TinySplitStruct));
				if(pTemp==NULL){
					printALERT("分配内存TinySplitStruct错误");
					return -1;
				}
				bzero((void*)pTemp,sizeof(struct TinySplitStruct));
				strcpy(pTemp->sSplitType,ptPre->sSplitType);
				strcpy(pTemp->sKey,ptPre->sKey);
				InsertList((LIST**)pptHead,(LIST*)pTemp);
			}
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}
static int ReadSplitKey2List(struct FileListStruct *ptHead,char sPath[],
	struct TinySplitStruct *p,struct FileControlStruct **pptHead)
{
	char sTempName[256];
	struct FileControlStruct *pTemp;
	struct TinySplitStruct *ptPre,*ptCur;
	
	*pptHead=NULL;


	while(ptHead!=NULL){
		ptCur=ptHead->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;

			if(strcmp(p->sSplitType,ptPre->sSplitType)==0&&
				strcmp(p->sKey,ptPre->sKey)==0){

				sprintf(sTempName,"%s%s.%s.%s.tmp",sPath,
					ptHead->sTempBaseName,p->sSplitType,p->sKey);
				if(TxtFileToList(sTempName,&pTemp)<0) return -1;
				
				AppendListTail((LIST**)&pTemp,(LIST*)*pptHead);
				*pptHead=pTemp;
			}
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}
static int RemoveSplitKeyFile(struct FileListStruct *ptHead,char sPath[])
{
	char sTempName[256];
	struct TinySplitStruct *ptPre,*ptCur;

	while(ptHead!=NULL){
/*
这部分功能已在：RemoveSplitTypeFile实现
		if(ptHead->iAbnoCnt!=0){
			sprintf(sTempName,"%s%s.a.tmp",sPath,
				ptHead->sTempBaseName);
			if(Remove(sTempName)<0){
				printALERT("删除文件%s失败",sTempName);
				return -1;
			}
		}
*/
		ptCur=ptHead->pHead;
		while(ptCur!=NULL){
			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			sprintf(sTempName,"%s%s.%s.%s.tmp",sPath,
				ptHead->sTempBaseName,ptPre->sSplitType,
				ptPre->sKey);
			if(Remove(sTempName)<0){
				printALERT("删除文件%s失败",sTempName);
				return -1;
			}
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}
static int RenameOutputFile(struct BillingLogStruct *ptHead,
	char sNormalPath[],char sErrPath[])
{
	char sTempName[256],sTargetName[256],sPath[256];

	while(ptHead!=NULL){
		if(strcmp(ptHead->sFileType,"A")==0||
			strcmp(ptHead->sFileType,"E")==0)
			strcpy(sPath,sErrPath);
		else	strcpy(sPath,sNormalPath);

		sprintf(sTempName,"%s%s.tmp",sPath,ptHead->sFileName);
		sprintf(sTargetName,"%s%s",sPath,ptHead->sFileName);
		if(Rename(sTempName,sTargetName)<0){
			printALERT("将%s改名为%s失败",sTempName,sTargetName);
			return -1;
		}
		WriteProcPrint("生成%s文件",ptHead->sFileName);
		ptHead=ptHead->pNext;
	}
	return 0;
}
static int BackupFileList(struct FileListStruct *ptHead,char sPath[],
	char sBackupPath[])
{
	char sTempName[256],sTargetName[256];

	while(ptHead!=NULL){
		sprintf(sTempName,"%s%s.tmp",sPath,ptHead->sTempBaseName);
		sprintf(sTargetName,"%s%s",sBackupPath,ptHead->sBaseName);
		if(Rename(sTempName,sTargetName)<0){
			/*备份文件失败不退出继续处理*/
			printALERT("将%s改名为%s失败",sTempName,sTargetName);
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}
/*得到一个BillingLogList列表，填写:cnt,file_name,ori_file_name,file_type字段,
	并将文件合并到临时输出文件*/
int GetBillingLogList(struct FileListStruct *ptHead,char sNormalPath[],
	int f,struct BillingLogStruct *p,struct BillingLogStruct **pptHead)
{
	int i=0;
	char sSplitStr[40],sSplitType[2],sTempName[256];
	struct TinySplitStruct *pTiny=NULL,*ptPre,*ptCur;
	struct FileControlStruct *pCtl=NULL;

	*pptHead=NULL;

/*剩cnt,file_name,ori_file_name,file_type四个字段*/

	/*对于没有控制文件的情况处理*/
	GetSplitStrList(ptHead,sSplitStr);
		
	for(i=0;i<strlen(sSplitStr);i++){
		sSplitType[0]=sSplitStr[i];
		sSplitType[1]=0;

		p->sFileType[0]=GetLogFileType(sSplitStr[i]);

		if(ReadSplitType2List(ptHead,sNormalPath,
			sSplitType,&pCtl)<0) return -1;
		p->iCnt=CountList((LIST*)pCtl);

		sprintf(p->sFileName,"%s.%s",p->sOriFileName,sSplitType);
				
		if(item2List((LIST**)pptHead,(LIST*)p,
			sizeof(struct BillingLogStruct))<0){
			printALERT("分配内存BillingLogStruct错误");
			return -1;
		}
			
		/*合并文件写到输出文件中*/
		sprintf(sTempName,"%s%s.tmp",sNormalPath,p->sFileName);
		if(list2fileln(&pCtl,sTempName)<0) return -1;
	}

	if(RemoveSplitTypeFile(ptHead,sNormalPath)<0) return -1;

	if(f==false) return 0;

	/*对于有控制文件的情况*/
	if(GetSplitKeyList(ptHead,&pTiny)<0) return -1;
	ptCur=pTiny;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		p->sFileType[0]=GetLogFileType(ptPre->sSplitType[0]);

		if(ReadSplitKey2List(ptHead,sNormalPath,ptPre,&pCtl)<0)
			return -1;
		p->iCnt=CountList((LIST*)pCtl);
			
		sprintf(p->sFileName,"%s.%s.%s",
			p->sOriFileName,ptPre->sSplitType,ptPre->sKey);
			
		if(item2List((LIST**)pptHead,(LIST*)p,
			sizeof(struct BillingLogStruct))<0){
			printALERT("分配内存BillingLogStruct错误");
			return -1;
		}
		
		/*合并文件写到输出文件中*/
		sprintf(sTempName,"%s%s.tmp",sNormalPath,p->sFileName);
		if(list2fileln(&pCtl,sTempName)<0) return -1;
	}
	
	if(RemoveSplitKeyFile(ptHead,sNormalPath)<0) return -1;

	return 0;
}
/*检查特定的FILE_LIST项的统计信息和实际文件记录数的平衡关系*/
static int CheckBillCnt(struct FileListStruct *ptHead,
	char sNormalPath[],char sErrPath[],char msg[])
{
	char c,cFileType,sTempName[256],pin[256],sBaseName[64],sSplitType[2];
	int iNormalCnt,i,iNewCnt,iAbnoCnt,iTmpCnt,l=0;
	struct TinySplitStruct *pTiny,*ptPre,*ptCur;
	
	strcpy(msg,"");
	strcpy(pin,"");

	if(ptHead==NULL) return -1;
	
	strcpy(sBaseName,ptHead->sTempBaseName);

	/*先做一下异常话单数的校验*/
	if(ptHead->iAbnoCnt!=0){
		sprintf(sTempName,"%s%s.a.tmp",sErrPath,sBaseName);
		iAbnoCnt=FileLines(sTempName);
		if(iAbnoCnt!=ptHead->iAbnoCnt){
			sprintf(msg,"异常话单本应输出%d,实际输%d",
				ptHead->iAbnoCnt,iAbnoCnt);
			return -1;
		}
	}

	pTiny=ptHead->pHead;
	
	iNormalCnt=iNewCnt=0;

	for(i=0;i<strlen(ptHead->sSplitStr);i++){

		sSplitType[0]=ptHead->sSplitStr[i];sSplitType[1]=0;

		if((c=ptHead->sSplitStr[i])=='a') continue;
		
		if(SplitTypeInTiny(sSplitType,ptHead->pHead)==true) continue;

		sprintf(sTempName,"%s%s.%c.tmp",sNormalPath,sBaseName,c);
		iTmpCnt=FileLines(sTempName);

		cFileType=GetLogFileType(c);
		if(cFileType=='C'){
			iNormalCnt+=iTmpCnt;
			l+=sprintf(pin+l,"%c:%d ",c,iTmpCnt);
		}
		else if(cFileType=='N')iNewCnt+=iTmpCnt;
	}

	if(pTiny==NULL){
		if(iNormalCnt!=ptHead->iNormalCnt){
			sprintf(msg,"正常话单本应输出%d,实际输出%d,明细为%s",
				ptHead->iNormalCnt,iNormalCnt,pin);
			return -1;
		}
		return iNewCnt;
	}
	
	ptCur=pTiny;
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;
		
		c=ptPre->sSplitType[0];
		sprintf(sTempName,"%s%s.%c.%s.tmp",
			sNormalPath,sBaseName,c,ptPre->sKey);
		iTmpCnt=FileLines(sTempName);

		cFileType=GetLogFileType(c);
		if(cFileType=='C'){
			iNormalCnt+=iTmpCnt;
			l+=sprintf(pin+l,"%c.%s:%d ",c,ptPre->sKey,iTmpCnt);
		}
		else if(cFileType=='N')iNewCnt+=iTmpCnt;
	}

	if(iNormalCnt!=ptHead->iNormalCnt){
		sprintf(msg,"正常话单本应输出%d,实际输出%d,明细为%s",
			ptHead->iNormalCnt,iNormalCnt,pin);
		return -1;
	}
	return iNewCnt;
}
static int GetFileTypeCnt(struct BillingLogStruct *ptHead,char cFileType)
{
	int iCnt=0;
	
	while(ptHead!=NULL){
		if(cFileType==ptHead->sFileType[0]) iCnt+=ptHead->iCnt;
		ptHead=ptHead->pNext;
	}
	return iCnt;
}
static int GetFileListCnt(struct FileListStruct *ptHead,char cFileType)
{
	int iCnt=0;

	while(ptHead!=NULL){
		if(cFileType=='C')      iCnt+=ptHead->iNormalCnt;
		else if(cFileType=='A') iCnt+=ptHead->iAbnoCnt;
		else if(cFileType=='N') iCnt+=ptHead->iNewCnt;
		ptHead=ptHead->pNext;
	}
	return iCnt;
}
int ProcessFileList(struct FileListStruct *ptHead,
	struct BillParamStruct *p,char msg[])
{
	int i,iBillFlag=false,pid;
	char sLine[512],sFileName[256],sTempName[256];
	char sTempBaseName[60],sTemp[40],sSplitNew[20];
	struct FileListStruct *ptPre,*ptCur;
	struct FileControlListStruct *pCtlList=NULL;

	strcpy(msg,"");
	pid=getpid();

	ptCur=ptHead;
	
	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		GetHostTime(ptPre->sDealBeginDate);

		sprintf(sFileName,"%s%s",p->sSourcePath,ptPre->sBaseName);
		sprintf(sTempBaseName,"%s_%d",ptPre->sBaseName,pid);
		sprintf(sTempName,"%s%s.tmp",p->sSourcePath,sTempBaseName);

/*将被处理的文件修改一个临时文件名*/
		if(Rename(sFileName,sTempName)!=0){
			sprintf(msg,"改名 %s 到 %s 失败",sFileName,sTempName);
			return -1;
		}

/*建立分离列表*/
		InitFileControlList(p->sTemplateID,p->sSplitStr,&pCtlList);
		pFileControlList=pCtlList;
		
		if(RLike(BILLING,"billing")==true){

			iBillFlag=GetBillingFlag(p->sSplitStr);
/*将分离话单指针指向指定话单*/
			pTicketField=&Ticket;
			i=ProcessBillFile(sTempName,p->sBelongCode,
				p->sModule,p->sNormalPath,p->sErrPath,
				p->sTemplateID,p->sUserType,iBillFlag,
				p->sSourceID,true,p->sSplit,p->iStartPos,
				p->iKeyLen,pCtlList,sLine);
		}
		else{
/*调用主函数处理文件*/
			i=ProcessRateFile(sTempName,p->sBelongCode,
				p->sModule,p->sNormalPath,p->sErrPath,
				p->sSourceID,true,p->sSplit,p->iStartPos,
				p->iKeyLen,pCtlList,sLine);

		}

		if(i<0){
			sprintf(msg,"批价失败\n");
			return -1;
		}

/*获取批价命令输出的参数*/
		GetSepStrX(sLine,'\t',1,20,sSplitNew);
		if(strcmp(sSplitNew,"")==0) continue;
		strcpy(ptPre->sSplitStr,sSplitNew);

		GetSepStr(sLine,'\t',2,sTemp);
		ptPre->iCnt=atoi(sTemp);
		GetSepStr(sLine,'\t',3,sTemp);
		ptPre->iNormalCnt=atoi(sTemp);
		GetSepStr(sLine,'\t',4,sTemp);
		ptPre->iAbnoCnt=atoi(sTemp);
		
		strcpy(ptPre->sTempBaseName,sTempBaseName);

		if(InitTinySplitList(p->sSourceID,sTempBaseName,
			&ptPre->pHead)<0) return -1;

		if(ptPre->iCnt!=(ptPre->iNormalCnt+ptPre->iAbnoCnt)){
			sprintf(msg,"批价输出话单不平衡%d!=%d+%d",
				ptPre->iCnt,ptPre->iNormalCnt,ptPre->iAbnoCnt);
			return -1;
		}
		if((ptPre->iNewCnt=CheckBillCnt(ptPre,p->sNormalPath,
			p->sErrPath,msg))<0) return -1;

		/*将pFileControlList释放*/
		DestroyFileControlList(pCtlList);
		
		GetHostTime(ptPre->sDealEndDate);
		WriteProcPrint("处理%s文件完成",ptPre->sBaseName);
	}
	return 0;
}
static int WriteList2BillingLog(struct FileListStruct *ptHead,
	struct BillingLogStruct *pList,char sSplitStr[],char sInType[])
{
	struct BillingLogStruct *pTemp;
	struct BillingProcLogStruct Temp;
	
	if(pList==NULL) return -1;
		
	bzero((void*)&Temp,sizeof(struct BillingProcLogStruct));
	
	Temp.iInputID=pList->iInputID;
	strcpy(Temp.sSourceID,pList->sSourceID);
	strcpy(Temp.sModule,pList->sModule);
	strcpy(Temp.sSplitStr,sSplitStr);
	
	strcpy(Temp.sCurFileName,pList->sOriFileName);

	strcpy(Temp.sFileType,sInType);
	
	strcpy(Temp.sAppCode,pList->sAppCode);
	strcpy(Temp.sAppID,pList->sAppID);
	Temp.iTacheID=	pList->iTacheID;

/*file_name,byte,cnt三个字段由列表字段填写*/
	while(ptHead!=NULL){
		strcpy(Temp.sFileName,ptHead->sBaseName);
		Temp.iByte=	ptHead->iByte;
		Temp.iCnt=	ptHead->iCnt;
		
		strcpy(Temp.sDealBeginDate,ptHead->sDealBeginDate);
		strcpy(Temp.sDealEndDate,ptHead->sDealEndDate);
	
		Temp.iNormalCnt=ptHead->iNormalCnt;
		Temp.iAbnoCnt=	ptHead->iAbnoCnt;
		Temp.iNewCnt=	ptHead->iNewCnt;
	
		if(SDInsertStructToBillingProcLog(&Temp,"BILLING_PROC_LOG")<0)
			return -1;
		
		ptHead=ptHead->pNext;
	}
	
	pTemp=pList;
	while(pTemp!=NULL){
		
		if(SDInsertStructToBillingLog(pTemp,"BILLING_LOG")<0)
			return -1;
		pTemp=pTemp->pNext;
	}
	return 0;
}
static void DestroyMyList(struct FileListStruct *ptHead)
{
	struct FileListStruct *pTemp=ptHead;
	
	while(pTemp!=NULL){
		DestroyList((LIST*)pTemp->pHead);
		pTemp=pTemp->pNext;
	}
	DestroyList((LIST*)ptHead);
}
int ProcessMain(struct BillParamStruct *p)
{
#define BILL_MAX_BYTES	30*1024*1024
	int iSplitKeyFlag,iCnt1,iCnt2,iRet;
	char sAppCode[5],sLockName[256],sStep[4];
	char sTempName[256],msg[2048],sTemp[40],sTempSource[7],sPrefix[40];
	struct FileControlStruct *pFileControl=NULL;
	struct FileListStruct *ptHead,*ptLkHead=NULL;
	struct BillingLogStruct *pLogList=NULL,Temp;
	
/*检查目录是否有效，无效则建立起来*/
	CheckDir(p->sSourcePath);
	CheckDir(p->sBackPath);
	CheckDir(p->sNormalPath);
	CheckDir(p->sErrPath);

/*检查USER_TYPE和公式文件的合法性*/
	if(RLike(BILLING,"billing")==true){
		if(strlen(p->sUserType)!=1){
			printALERT("billing.sh 时 UserType长度必须为1,%s",
				p->sUserType);
			return -1;
		}
		strcpy(sAppCode,"BILL");
		strcpy(sStep,"BIL");
	}
	else{
		sprintf(sTempName,"%s%s",EXPRPATH,p->sUserType);
		if(!IsFile(sTempName)){
			printALERT("rate.sh 时　user_type必须为文件,%s 无效",
				sTempName);
			return -1;
		}
/*编译RATE公式*/
		if(CompileExprFile(sTempName)<0){
			printALERT("rate.sh 编译公式 %s错误",sTempName);
			return -1;
		}
		strcpy(sAppCode,"RATE");
		strcpy(sStep,"RAT");
	}
/*生成一个文件列表*/
	if(dir2list(p->sSourcePath,p->sFilter,&pFileControl)<0){
		printALERT("生成文件列表失败 %s %s",
			p->sSourcePath,p->sFilter);
		return -1;
	}
	if(GenFileList(pFileControl,p->sSourceID,
		p->sSourcePath,&ptLkHead)<0) return -1;

	bzero((void*)&Temp,sizeof(struct BillingLogStruct));
	strcpy(Temp.sSourceID,p->sSourceID);
	strcpy(Temp.sModule,p->sModule);
	strcpy(Temp.sState,"A");
	strcpy(Temp.sAppCode,p->sAppCode);
	strcpy(Temp.sAppID,p->sAppID);
	Temp.iTacheID=	p->iTacheID;
	
	strncpy(sTempSource,Temp.sSourceID,6);sTempSource[6]=0;
	RightPad(sTempSource,6,'0');
	
	iSplitKeyFlag=true;
	if(p->iKeyLen<=0||strlen(p->sSplit)==0)iSplitKeyFlag=false;

	/*拿到一组文件,这组文件的输出将是一个文件*/
	while(GetFileList(&ptLkHead,BILL_MAX_BYTES,p->sSourcePath,p->sModule,
		Temp.sDataDate,p->sBatchFlag,&ptHead)==FOUND){
		
		/*对这组文件进行处理*/
		GetHostTime(Temp.sDealBeginDate);
		if(ProcessFileList(ptHead,p,msg)<0){
			printALERT("%s",msg);
			return -1;
		}
		GetHostTime(Temp.sDealEndDate);
		WriteProcPrint("批处理%d个文件完成",CountList((LIST*)ptHead));

		Temp.iInputID=		GetInputID();

		
/*这里锁定特定SOURCE_ID和特定DATA_DATE,对于锁冲突直接退出*/
		GetLogLock(sAppCode,Temp.sSourceID,Temp.sDataDate,sLockName);
		iRet=LockLog(sLockName,msg);
		if(iRet!=0){
			WriteAlertMsg("信息:%s，进程退出",msg);
			return -1;
		}
/*如果不需要支持批处理，则直接取输入文件名的序列号*/
		if(p->sBatchFlag[0]=='2'){
			strncpy(sTemp,ptHead->sBaseName+14,5);	sTemp[5]=0;
			Temp.iSeq=atoi(sTemp);
			strncpy(sTempSource,ptHead->sBaseName,6);
			sTempSource[6]=0;
		}
		else{/*否则去日志中的序列号*/
			if((Temp.iSeq=GetBillNextSeq(Temp.sSourceID,
				Temp.sDataDate,Temp.sModule))<0) return -1;
		}

		strncpy(sTemp,Temp.sDataDate,8);sTemp[8]=0;
		sprintf(sPrefix,"%s%s%05d",sTempSource,sTemp,Temp.iSeq);
		sprintf(Temp.sOriFileName,"%s.%s.%s",sPrefix,p->sModule,sStep);

		/*生成输出日志列表，并合并文件到输出文件.tmp*/
		if(GetBillingLogList(ptHead,p->sNormalPath,iSplitKeyFlag,
			&Temp,&pLogList)<0) return -1;

		WriteProcPrint("合并输出文件完毕，生成%d个文件",
			CountList((LIST*)pLogList));
		
		/*输入和输出日志话单数平衡关系校验*/
		iCnt1=GetFileListCnt(ptHead,'C');
		iCnt2=GetFileTypeCnt(pLogList,'C');
		if(iCnt1!=iCnt2){
			printALERT("输入和输出正常话单数不一致,in=%d,out=%d",
				iCnt1,iCnt2);
			return -1;
		}
/*		iCnt1=GetFileListCnt(ptHead,'A');
		iCnt2=GetFileTypeCnt(pLogList,'A');
		if(iCnt1!=iCnt2){
			printALERT("输入和输出异常话单数不一致,in=%d,out=%d",
				iCnt1,iCnt2);
			return -1;
		}
*/
		iCnt1=GetFileListCnt(ptHead,'N');
		iCnt2=GetFileTypeCnt(pLogList,'N');
		if(iCnt1!=iCnt2){
			printALERT("输入和输出拆分话单数不一致,in=%d,out=%d",
				iCnt1,iCnt2);
			return -1;
		}

		/*写日志信息*/
		if(WriteList2BillingLog(ptHead,pLogList,p->sSplitStr,p->sInType)<0)
			return -1;

		/*将输出文件改名,如果出错则造成输入一堆文件是.tmp文件*/
		if(RenameOutputFile(pLogList,p->sNormalPath,p->sErrPath)<0)
			return -1;
		
		/*将输入文件备份,如果出错则造成一部分已经成功备份，另一部分积压.tmp文件*/
		BackupFileList(ptHead,p->sSourcePath,p->sBackPath);

		/*日志解锁*/
		UnlockLog(sLockName);

		/*提交任务，释放链表*/
		CommitWork();
		WriteProcPrint("批处理%d个文件,生成%d个文件成功",
			CountList((LIST*)ptHead),CountList((LIST*)pLogList));
		DestroyMyList(ptHead);
		DestroyList((LIST*)pLogList);
	}

	DestroyMyList(ptLkHead);

	return 0;
}

int main(int argc,char *argv[])
{
	int iGroupID,iRet;
	char	sPath[256],sFileName[256],sAppCode[9];
	struct BillParamStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;

	if(argc!=3){
		printf("Usage %s shm/billing.ini|rate.ini/flowxxxx groupid .\n",argv[0]);
		return 0;
	}
	GetBillHome(sPath);
	
	if(RLike(argv[0],"billing_sh")==true){
		InitAppRes("billing.sh");
		sprintf(BILLING,"%sbin/billing",sPath);
		strcpy(sAppCode,"BILLING");
	}
	else if(RLike(argv[0],"rate_sh")==true){
		InitAppRes("rate.sh");
		sprintf(BILLING,"%sbin/rate",sPath);
		strcpy(sAppCode,"RATE");
	}
	else if(RLike(argv[0],"rate2_sh")==true){
		InitAppRes("rate2.sh");
		sprintf(BILLING,"%sbin/rate2",sPath);
		strcpy(sAppCode,"RATX");
	}
	else{
		printALERT("程序名必须为%s,%s,%s",
			"billing_sh","rate_sh","rate2_sh");
		return -1;
	}
	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	
	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*初始化BILL应用位置和公式路径到全局变量*/
	if(InitBillCtl()<0) return -1;

/*初始化批价参数*/
	InitParamMem();

/*将需要处理的参数获取到 链表中*/
	if(GetBillParamList(sFileName,sAppCode,iGroupID,&ptHead)<0) return -1;

	if(ConnectDataDB()<0){
		printALERT("连结数据库失败");
		return -1;
	}

	ptLkHead=ptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if((iRet=ProcessMain(pTemp))<0){
			RollbackWorkRelease();
			return -1;
		}

		if(iRet>0) break;
		
		CommitWork();
		if(WantQuit()==true)break;
	}
	
/*释放批价参数*/
	DestroyParamMem();

	DestroyList((LIST*)ptLkHead);

	DisconnectDatabase();

	return 0;
}
