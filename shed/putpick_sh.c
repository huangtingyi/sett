#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>
#include <wwcoding.h>
#include <wwtiny.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwsupp.h>
#include <wwnet.h>
#include <wwdb.h>
#include <dbsupp.h>

#include <gen_supp.h>
#include <param_intf.h>

#include "appsupp.h"
#include "putpick_sh.h"

void DeleteFtpCtl(struct PutPickCtlStruct *p);
int GenFtpSize(struct PutParamStruct *pParam,struct PutPickCtlStruct *p);
int GenFtpPut(struct PutParamStruct *pParam,struct PutPickCtlStruct *p);
int GenFtpRename(struct PutParamStruct *pParam,struct PutPickCtlStruct *p);
int GenFtpDelete(struct PutParamStruct *pParam,struct PutPickCtlStruct *p);
int GetRemoteFileSize(struct PutParamStruct *pParam,struct PutPickCtlStruct *p);
int InitPutPickCtl(struct PutPickCtlStruct *p);

int GetRemoteFileSize(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	int iSize=0;
	char sSize[1024],sCommand[256];

/*生成获取FTP字节的命令*/
	if(GenFtpSize(pParam,p)<0) return -1;
/*执行FTP命令获取dir 信息到本地文件*/
	if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",p->sFtpSize)!=0)
		return -1;
/*获取行记录到sSize中*/
	sprintf(sCommand,"cat %s | head -1",p->sFileSize);
	if(exec2str(sCommand,sSize)!=0) return -1;
/*调用通用获取字节的函数获取对端字节数*/
	iSize=GetFtpDirSize(sSize);
	
	return iSize;
}
void GetFilterFileName(char sLine[],char sFilter[],char sFileName[])
{
	int i=0;
	char	sCommand[256],sTempName[256];

	strcpy(sFileName,"");

	while(1){
		/*取一个字段，则向下处理*/
		GetSepStr(sLine,'\t',i,sTempName);i++;
		if(strcmp(sTempName,"")==0) break;


		/*发现文件列表中的文件名含通配符不处理*/
		if(strchr(sTempName,'*')!=NULL||
			strchr(sTempName,'?')!=NULL||
			strchr(sTempName,'[')!=NULL||
			strchr(sTempName,']')!=NULL) continue;

		TrimAll(sTempName);

		sprintf(sCommand,"echo %s | sed -n /%s/p",sTempName,sFilter);
		if(exec2str(sCommand,sFileName)!=0) continue;

		TrimAll(sFileName);

		if(strcmp(sFileName,sTempName)==0) break;
	}

}
int ProcessMain(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	int iSeq,iSize1,iSize2,iFlag;
	char sDealBeginDate[15],sDealEndDate[15];
	char sFileName[256],sTempName[256],sTemp[256];
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;

/*检查一下网络联通状况*/
	if(PingIpOk(pParam->sIp)==false){
		printALERT("IP地址 %s 无法 ping 通",pParam->sIp);
		return -1;
	}

/*生成一个文件列表*/
	if(dir2list(pParam->sLocalPath,pParam->sFilter,&ptHead)<0){
		printALERT("生成文件列表失败 %s %s",
			pParam->sLocalPath,pParam->sFilter);
		return -1;
	}

/*将文件列表备份*/
	ptLkHead=ptHead;
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);

		if(strcmp(sFileName,"")==0) continue;
	/*将变量保存在结构中*/
	/*如果文件刚被修改则不处理*/
		sprintf(sTempName,"%s%s",pParam->sLocalPath,sFileName);
		if(FileModifyDiff(sTempName)<6) continue;
		
		strcpy(p->sFileName,sFileName);
		sprintf(p->sTargetTemp,"%s.pik",sFileName);

	        if((iFlag=PutLogCheck(pParam->sSourceID,sFileName,-1))<0){
	        	printALERT("调用PickLogCheck失败.");
	        	return -1;
	        }
	        if(iFlag==1) continue;/*已经发送过,则不发送了*/


	/*获取文件序列号*/
		if(pParam->iSeqOff<1) pParam->iSeqOff=1;	
		strncpy(sTemp,sFileName+pParam->iSeqOff-1,pParam->iSeqLen);
		sTemp[pParam->iSeqLen]=0;
		iSeq=	atoi(sTemp);
	       
	        GetHostTime(sDealBeginDate);

	/*生成获取、改名、删除命令脚本文件*/
		if(GenFtpPut(pParam,p)<0) return -1;
		if(GenFtpRename(pParam,p)<0) return -1;
		if(GenFtpDelete(pParam,p)<0) return -1;

	/*到对端主机获取文件*/
		if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",p->sFtpPut)!=0){
			printALERT("FTP发送IP %s的%s下的%s失败.",
				pParam->sIp,pParam->sOppPath,sFileName);
			continue;
		}
	/*发送成功后取一下对端临时文件的大小*/
		iSize1=GetRemoteFileSize(pParam,p);
	/*如果对端的主机文件字节获取不到,则取获取到的文件字节数*/
		
		iSize2=FileSize(sTempName);

	/*如果发送的文件和对端文件大小不一致，则将对端临时文件删除,继续*/		
		if(iSize1!=iSize2){
			if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
				p->sFtpDelete)!=0){
				printALERT("删除对端主机 %s 目录 %s 下的文件 %s 失败",
				pParam->sIp,pParam->sOppPath,p->sTargetTemp);
				return -1;
					
			}
			continue;
		}
		GetHostTime(sDealEndDate);

		if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
			p->sFtpRename)!=0){
			printALERT("备份对端主机 %s 目录 %s 下的文件 %s 到 %s 失败",
				pParam->sIp,pParam->sOppPath,
				p->sTargetTemp,sFileName);
				return -1;
		}

	/*写发送数据库日志*/
		if (InsertPutLog(pParam->sSourceID,iSize1,sFileName,
			sDealBeginDate,sDealEndDate,iSeq,"x",0,"0")<0){

			printALERT("写发送日志失败");

		/*写日志失败则备份发送过的文件为临时文件
			execcmd("cp %s %s%s",sTempName,
				pParam->sLocalPath,p->sTargetTemp);
			return -1;*/
		}

		CommitWork();
	/*记录日志成功后，以下任何异常都要退出，并保留临时文件*/
	
	/*对端文件处理（0 不删除(不支持->2)  1 删除  2 备份）*/
		switch(atoi(pParam->sDeleteType)){
		case 1:/*删除远端文件*/
			if(execcmd("rm -f %s",sTempName)!=0){
				printALERT("删除文件 %s 失败",sTempName);
				return -1;					
			}
			break;
		case 2:
		case 0:
			if(execcmd("mv %s %s%s 2>&1 >/dev/null",
				sTempName,pParam->sLocalBkupPath,sFileName)!=0){
				printALERT("备份文件 %s 到 %s 目录失败",
					sTempName,pParam->sLocalBkupPath);
				return -1;
			}
			printf("sLocalBkupPath=%s\n",pParam->sLocalBkupPath);
			printf("sTempName=%s\n",sTempName);
			break;
		default:
			printALERT("目前不支持 %s 的备份类型",pParam->sDeleteType);
			return -1;
		}			
		
		printNORMAL("%s成功发送文件%s字节%d到 %s:%s下",
			pParam->sSourceID,sFileName,iSize1,
			pParam->sIp,pParam->sOppPath);
	}
	listfree(&ptLkHead);

	return 0;
}

int main(int argc,char **argv)
{
	int iGroupID;
	char sFileName[256];
	struct PutParamStruct *ptHead=NULL,*pTemp=NULL,*ptLkHead=NULL;
	struct PutPickCtlStruct PutCtl;
	

	if(argc!=3){
		printf("Usage %s shm/pick.ini GroupID .\n",argv[0]);
		return -1;
	}

	InitAppRes("putpick.sh");
	
	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);


/*初始化各种的控制文件名*/
	if(InitPutPickCtl(&PutCtl)<0) return -1;

/*将需要处理的参数获取到 链表中*/
	if(GetPutParamList(sFileName,iGroupID,&ptHead)<0) return -1;

	if(ConnectDataDB()<0){
		WriteErrStackAlert();
		return -1;
	}
	ptLkHead=ptHead;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(IsDir(pTemp->sLocalPath)==false){
		        printALERT("本地路径%s无效.",pTemp->sLocalPath);
		        return -1;
		}
	/*如果参数指示要备份传送对端的文件，而且本机目录无效则提示*/
		/*if(strcmp(pTemp->sDeleteType,"2")==0&&
			IsDir(pTemp->sOppBkupPath)==false){
		        printALERT("本地路径%s无效.",pTemp->sOppBkupPath);
		        return -1;
		}*/
		if(ProcessMain(pTemp,&PutCtl)<0) return -1;

	}
/*删除临时控制文件*/
	DeleteFtpCtl(&PutCtl);
/*释放内存*/
	DestroyList((LIST*)ptLkHead);

	DisconnectDatabase();

	return 0;
}

int InitPutPickCtl(struct PutPickCtlStruct *p)
{
	p->pid=getpid();
	GetBillHome(p->sBillHome);
	GetAppHome(p->sAppHome);

	sprintf(p->sFileNameList,"%swork/putpickfilenamelist%d.lst",
		p->sAppHome,p->pid);
	sprintf(p->sFileSize,"%swork/putpicksize%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpSize,"%swork/ftpsize%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpPut,"%swork/ftpput%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpRename,"%swork/ftprename%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpDelete,"%swork/ftpdelete%d.lst",p->sAppHome,p->pid);

	return 0;
}

void DeleteFtpCtl(struct PutPickCtlStruct *p)
{
	char sCommand[2048];

	sprintf(sCommand,
		"rm -rf %s %s %s %s %s %s; 2>&1 >/dev/null",
		p->sFtpPut,p->sFtpDelete,p->sFtpRename,
		p->sFtpSize,p->sFileNameList,p->sFileSize);
	system(sCommand);
}

/*这里是生成取对端临时文件大小的命令脚本*/
int GenFtpSize(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	if(PrintTiny(p->sFtpSize,"open %s\n\
		user %s %s\n\
		cd %s\n\
		dir %s %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sTargetTemp,p->sFileSize)<0){

		printALERT("写文件 %s 失败.",p->sFtpSize);
		return -1;
	}
	return 0;
}

int GenFtpPut(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	if(PrintTiny(p->sFtpPut,"open %s\n\
		user %s %s\n\
		prompt \n\
		bin\n\
		cd %s\n\
		lcd %s\n\
		put %s %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,pParam->sLocalPath,
		p->sFileName,p->sTargetTemp)<0){

		printALERT("写文件 %s 失败.",p->sFtpPut);
		return -1;
	}
	return 0;
}

/*这里的该名是将对端文件改为正式的文件名*/
int GenFtpRename(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	if(PrintTiny(p->sFtpRename,"open %s\n\
		user %s %s\n\
		rename %s/%s %s/%s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sTargetTemp,pParam->sOppPath,
		p->sFileName)<0){
		
		printALERT("写文件 %s 失败.",p->sFtpRename);
		return -1;
	}
	return 0;
}
/*这里是在回退的情况下删除对端的临时文件*/
int GenFtpDelete(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	if(PrintTiny(p->sFtpDelete,"open %s\n\
		user %s %s\n\
		cd %s\n\
		delete %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sTargetTemp)<0){

		printALERT("写文件 %s 失败",p->sFtpDelete);
		return -1;
	}
	return 0;
}

