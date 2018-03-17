#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include <wwcoding.h>
#include <wwtiny.h>
#include <wwnet.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <dbsupp.h>

#include "gen_supp.h"
#include "param_intf.h"

#include "appsupp.h"
#include "pick_sh.h"


void DeleteFtpCtl(struct PickCtlStruct *p);
int GenFtpNList(struct PickParamStruct *pParam,struct PickCtlStruct *p);
int GenFtpDList(struct PickParamStruct *pParam,struct PickCtlStruct *p);
int GenFtpSize(struct PickParamStruct *pParam,struct PickCtlStruct *p);
int GenFtpGet(struct PickParamStruct *pParam,struct PickCtlStruct *p);
int GenFtpRename(struct PickParamStruct *pParam,struct PickCtlStruct *p);
int GenFtpDelete(struct PickParamStruct *pParam,struct PickCtlStruct *p);
int GetRemoteFileSize(struct PickParamStruct *pParam,struct PickCtlStruct *p);
int InitPickCtl(int iFlag,struct PickCtlStruct *p);
int ProcessMain(struct PickParamStruct *pParam,struct PickCtlStruct *p);

int GetRemoteFileSize(struct PickParamStruct *pParam,struct PickCtlStruct *p)
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
int ChkIpTpye(char sIp[],char sSourceID[],char sFileName[])
{
	if(strcmp(sIp,"133.103.9.233")==0)return 0;
	if(strcmp(sSourceID,"ZNWG01")==0){
		if(strncmp(sFileName,"FileList",8)==0)return 0;
	}
	return -1;
}
int ChkDir(char sFileType[],char sSourceID[])
{
	if(strcmp(sFileType,"H118A")==0)return 0;
	return -1;
}

void GetFilterFileName(char sLine[],char sFilter[],char sFileName[])
{                                

	time_t t1,t2;
	char sFileTime[15],sHostTime[15],sNFilter[32];
	
	strcpy(sNFilter,sFilter);
	ReplaceStr(sNFilter,"$HH$.BIL",".BIL");

	GetFtpFileName(sLine,sNFilter,sFileName);

	/*写死强制网通华为只采三个小时前的文件*/
	if(strcmp(sFilter,sNFilter)!=0){
		
		GetHostTime(sHostTime);	sHostTime[10]=0;
		strcat(sHostTime,"0000");
 		if((t1 = tGetTime(sHostTime)) < 0)t1=10801;

		
		strncpy(sFileTime,sFileName,10);sFileTime[10]=0;
		strcat(sFileTime,"0000");

 		if((t2 = tGetTime(sFileTime)) < 0)t2=0;
 		
 		
		if((t1-t2)<=10800)strcpy(sFileName,"");

	}
	
}
int ProcessOppDir(struct PickParamStruct *pParam,
	struct PickCtlStruct *p,char sInDate[])
{
	int iDay=0;
	char sDate[9],sTemp[128],sChkTime[15],sKeyTime[15];
	char sFileName[128],sDirName[128],sOppPath[128];
	
	struct FileControlStruct *ptHead=NULL,*pTemp;

	
       if(strncmp(sInDate,"D",1)==0){
                strncpy(sTemp,sInDate+1,7);sTemp[7]=0;
                
                iDay=atoi(sTemp);
               
                GetHostTime(sKeyTime);sKeyTime[8]=0;
                strcat(sKeyTime,"000000");
                
                if(AddTimes(sKeyTime,-iDay*86400)<0) return -1;
        }
        else if(strlen(sInDate)==8){
                strncpy(sDate,sInDate,8);sDate[8]=0;
                RegularDir(pParam->sOppPath);
                strcat(pParam->sOppPath,sDate);
                
                if(ProcessMain(pParam,p)<0) return -1;
                
                return 0;
        }
        else{
        	printALERT("date参数不对,date=%s",sInDate);
        	return -1;
	}

	
/*##生成获取目录列表命令*/
	if(GenFtpDList(pParam,p)<0) return -1;

	if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
		p->sFtpDList)!=0){
		printALERT("获取对端文件列表失败DIRNAMELIST,%s",
			p->sFtpDList);
		return 1;
	}
/*如果文件不存在返回*/
	if(IsFile(p->sDirNameList)==FALSE)return -1;
 	
	if(TxtFileToList(p->sDirNameList,&ptHead)<0) return -1;
	
	strcpy(sOppPath,pParam->sOppPath);
	
 	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*从链表中取出目录名*/
		
		
		strncpy(sFileName,pTemp->pData,pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		GetBaseName(sFileName,sDirName);
		
		if(strlen(sDirName)!=8)continue;
		
		strcpy(sChkTime,sDirName);
		strcat(sChkTime,"000000");
		
		if(strcmp(sChkTime,sKeyTime)<0)continue;
		
		strcpy(pParam->sOppPath,sOppPath);
                RegularDir(pParam->sOppPath);
                strcat(pParam->sOppPath,sDirName);
  
                if(ProcessMain(pParam,p)<0) return -1;
		
	}

        return 0; 	
}
int ProcessMain(struct PickParamStruct *pParam,struct PickCtlStruct *p)
{
	int iSeq,iSize1,iSize2,iFlag;
	char sLine[8192],sDealBeginDate[15],sDealEndDate[15];
	char sFileName[256],sTempName[256],sTemp[256];
	struct FileControlStruct *ptHead=NULL,*pTemp,*ptLkHead;

/*##生成获取文件列表命令*/
	if(GenFtpNList(pParam,p)<0) return -1;

	if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
		p->sFtpNList)!=0){
		printALERT("获取对端文件列表失败FILENAMELIST,%s",
			p->sFtpNList);
		return 1;
	}
	
/*如果文件不存在返回*/
	if(IsFile(p->sFileNameList)==FALSE)return -1;

/*如果是不删除的标志，则调用程序对文件列表做预处理*/
	if(strcmp(pParam->sDeleteType,"0")==0){

		if(execcmd("%s %s %s",p->sPickDup,pParam->sSourceID,
			p->sFileNameList)!=0){
			printALERT("调用 %s %s %s失败",p->sPickDup,
				pParam->sSourceID,p->sFileNameList);
			return -1;
		}
	}

/*如果文件获取的文件列表为空则继续*/
	if(FileSize(p->sFileNameList)<=0) return 1;

/*将文件列表读入内存*/
	if(TxtFileToList(p->sFileNameList,&ptHead)<0) return -1;

/*将文件列表备份*/
	ptLkHead=ptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(WantQuit()==true){
			WriteProcMsg("接收到退出信号，程序退出");
			break;
		}

		memcpy(sLine,pTemp->pData,pTemp->iLen);
		sLine[pTemp->iLen] = '\0';

	/*先获取文件名，获取不到则继续*/
		GetFilterFileName(sLine,pParam->sFilter,sFileName);

		if(strcmp(sFileName,"")==0) continue;
	/*将变量保存在结构中*/
		strcpy(p->sFileName,sFileName);
		sprintf(p->sTargetTemp,"%s.pik",sFileName);

	        if((iFlag=PickLogCheck(pParam->sSourceID,sFileName,
			pParam->iChkDays))<0){
	        	printALERT("调用PickLogCheck失败.");
	        	return -1;
	        }
	        if(iFlag==1) continue;/*已经采过,则不采了*/


	/*获取文件序列号*/
		if(pParam->iSeqOff<1) pParam->iSeqOff=1;
		strncpy(sTemp,sFileName+pParam->iSeqOff-1,pParam->iSeqLen);
		sTemp[pParam->iSeqLen]=0;
		iSeq=	atoi(sTemp);
	       
	        GetHostTime(sDealBeginDate);

	/*两次调用FTP获取远端文件字节数，如果字节数不一致则continue*/
		iSize1=GetRemoteFileSize(pParam,p);
		sleep(1);
		iSize2=GetRemoteFileSize(pParam,p);

		if(iSize1!=iSize2) continue;
		
		
	/*生成获取、改名、删除命令脚本文件*/
		if(GenFtpGet(pParam,p)<0) return -1;
		if(GenFtpRename(pParam,p)<0) return -1;
		if(GenFtpDelete(pParam,p)<0) return -1;

	/*到对端主机获取文件*/
		if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",p->sFtpGet)!=0){
			printALERT("FTP获取%s的%s下的%s失败.",
				pParam->sIp,pParam->sOppPath,sFileName);
			continue;
		}
	/*如果对端的主机文件字节获取不到,则取获取到的文件字节数*/
		sprintf(sTempName,"%s%s",pParam->sLocalPath,p->sTargetTemp);
		iSize2=FileSize(sTempName);
	/*如果获取的文件不存在则继续*/
		if(iSize2<0) continue;
		
		iFlag=ChkIpTpye(pParam->sIp,pParam->sSourceID,p->sFileName);
		
		if(iSize1!=0&&iFlag!=0){
			if(iSize1!=iSize2){
			/*备份本地文件，继续采集下一个文件*/
				printALERT("采集的文件%s=%d远端文件%s=%d,大小不同",
					sTempName,iSize2,p->sFileName,iSize1);
				execcmd("rm -f %s.%d",sTempName,p->pid);
				execcmd("mv %s %s.%d.",sTempName,sTempName,p->pid);
				continue;
			}
		}

		iSize1=iSize2;
			
		GetHostTime(sDealEndDate);

	/*写采集数据库日志*/
		if (InsertPickLog(pParam->sSourceID,iSize1,sFileName,
			sDealBeginDate,sDealEndDate,iSeq,pParam->sOutType,
			pParam->iTacheID,pParam->sAppID)<0){

			printALERT("写采集日志失败");

		/*写日志失败则删除采集过来的临时文件*/
			execcmd("rm -f %s",sTempName);
			return -1;
		}

		CommitWork();
	/*记录日志成功后，以下任何异常都要退出，并保留临时文件*/
	
	/*对端文件处理（0 不删除  1 删除  2 备份）*/
		switch(atoi(pParam->sDeleteType)){
		case 1:/*删除远端文件*/
			if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
				p->sFtpDelete)!=0){
				printALERT("删除对端主机 %s 目录 %s 下的文件 %s 失败",
				pParam->sIp,pParam->sOppPath,sFileName);
				return -1;
					
			}
			break;
		case 2:
			if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
				p->sFtpRename)!=0){
				printALERT("备份对端主机 %s 目录 %s 下的文件 %s 到 %s 失败",
					pParam->sIp,pParam->sOppPath,
					sFileName,pParam->sOppBkupPath);
				return -1;
					
			}
			break;
		default:
			break;
		}			

	/*将临时文件名修改为正式的文件名*/
		if(execcmd("mv %s %s%s",sTempName,pParam->sLocalPath,
			p->sFileName)!=0){
			printALERT("改名%s到%s%s失败",
				sTempName,pParam->sLocalPath,p->sFileName);
			return -1;
		}
	
	/*自动解压功能支持，如果遇到压缩的文件则先解压*/
		if(RLike(p->sFileName,".gz")==true){
			if(execcmd("gunzip %s%s",pParam->sLocalPath,
				p->sFileName)!=0){
				printALERT("解压%s%s失败",
					pParam->sLocalPath,p->sFileName);
				return -1;
			}
		}
		else if(RLike(p->sFileName,".Z")==true){
			if(execcmd("uncompress %s%s",pParam->sLocalPath,
				p->sFileName)!=0){
				printALERT("解压%s%s失败",
					pParam->sLocalPath,p->sFileName);
				return -1;
			}
		}
		
		printNORMAL("%s成功采集文件%s字节%d",
			pParam->sSourceID,sFileName,iSize1);
		if(p->iFlag==true)
			printsourceNORMAL(pParam->sSourceID,
			"%s成功采集文件%s字节%d",
			pParam->sSourceID,sFileName,iSize1);
	}

	listfree(&ptLkHead);

	return 0;
}

int main(int argc,char **argv)
{
	int iGroupID,iFlag=true;
	char sFileName[256],sDate[9];
	struct PickParamStruct *ptHead=NULL,*pTemp=NULL,*ptLkHead=NULL;
	struct PickCtlStruct PickCtl;


	if(argc!=4&&argc!=5){
		printf("Usage %s shm|pick.ini|flowxxxx GroupID date [0|1=def].\n",argv[0]);
		printf("date参数说明:.\n");
		printf("	 Dn 	D3则为当前系统时间偏移3天.\n");
		printf("	date    要采集的日期,yyyymmdd格式.\n");
		return -1;
	}

	InitAppRes("pick.sh");
	
	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	strcpy(sDate,argv[3]);


/*默认写pick.sh.xxxxxx.log日志，只有第三个参数为0的时候不写这种日志*/
	iFlag=true;
	if(argc==5){
		if(strcmp(argv[4],"0")==0)iFlag=false;
	}

	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*初始化各种的控制文件名*/
	if(InitPickCtl(iFlag,&PickCtl)<0) return -1;

/*将需要处理的参数获取到 链表中*/
	if(GetPickParamList(sFileName,iGroupID,&ptHead)<0) return -1;

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
	/*检查一下网络联通状况*/
		if(PingIpOk(pTemp->sIp)==false&&
			strcmp(pTemp->sIp,"133.96.48.65")!=0){
			printALERT("IP地址 %s 无法 ping 通",pTemp->sIp);
			continue;
		}
			
	/*是否要做对端按日期分目录处理 /YYYYMMDD */
		if(ChkDir(pTemp->sOutType,pTemp->sSourceID)==0){
	
			if(ProcessOppDir(pTemp,&PickCtl,sDate)<0){
				printALERT("%s IP:%s %s %s 采集失败,ping 通",
					pTemp->sSourceID,pTemp->sIp,
					pTemp->sUserName,pTemp->sPasswd);
			}
		}
		else{
			if(ProcessMain(pTemp,&PickCtl)<0){
				printALERT("%s IP:%s %s %s 采集失败,ping 通",
					pTemp->sSourceID,pTemp->sIp,
					pTemp->sUserName,pTemp->sPasswd);
			}
		}
	/*删除临时控制文件*/
		DeleteFtpCtl(&PickCtl);
		
		if(WantQuit()==true) break;
	}
/*释放内存*/
	DestroyList((LIST*)ptLkHead);

	DisconnectDatabase();

	return 0;
}

int InitPickCtl(int iFlag,struct PickCtlStruct *p)
{
	p->pid=getpid();
	p->iFlag=iFlag;
	GetBillHome(p->sBillHome);
	GetAppHome(p->sAppHome);

	sprintf(p->sFtpNList,"%swork/ftpnlist%d.txt",p->sAppHome,p->pid);
	sprintf(p->sFileNameList,"%swork/pickfilenamelist%d.lst",
		p->sAppHome,p->pid);
	sprintf(p->sFileSize,"%swork/picksize%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpSize,"%swork/ftpsize%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpGet,"%swork/ftpget%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpRename,"%swork/ftprename%d.lst",p->sAppHome,p->pid);
	sprintf(p->sFtpDelete,"%swork/ftpdelete%d.lst",p->sAppHome,p->pid);
	sprintf(p->sPickDup,"%sbin/pickdup",p->sBillHome);
	sprintf(p->sFtpDList,"%swork/ftpdlist%d.txt",p->sAppHome,p->pid);
	sprintf(p->sDirNameList,"%swork/dirnamelist%d.lst",
		p->sAppHome,p->pid);

	if(IsFile(p->sPickDup)==FALSE){
		printALERT("应用程序%s不存在",p->sPickDup);
		return -1;
	}
	return 0;
}

void DeleteFtpCtl(struct PickCtlStruct *p)
{
	char sCommand[2048];

	sprintf(sCommand,
		"rm -rf %s %s %s %s %s %s %s %s %s; 2>&1 >/dev/null",
		p->sFtpGet,p->sFtpDelete,p->sFtpRename,p->sFtpNList,
		p->sFtpSize,p->sFileNameList,p->sFileSize,p->sDirNameList,
		p->sFtpDList);
	system(sCommand);
}

int GenFtpNList(struct PickParamStruct *pParam,struct PickCtlStruct *p)
{
	
	if(PrintTiny(p->sFtpNList,"open %s\n\
		user %s %s\n\
		cd %s\n\
		prompt\n\
		ls -t %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sFileNameList)<0){
			
		printALERT("写文件 %s 失败.",p->sFtpNList);
		return -1;
	}
	return 0;
}

int GenFtpDList(struct PickParamStruct *pParam,struct PickCtlStruct *p)
{
	if(PrintTiny(p->sFtpDList,"open %s\n\
		user %s %s\n\
		cd %s\n\
		prompt\n\
		ls -t %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sDirNameList)<0){
			
		printALERT("写文件 %s 失败.",p->sFtpDList);
		return -1;
	}
	return 0;
}

int GenFtpSize(struct PickParamStruct *pParam,struct PickCtlStruct *p)
{
	if(PrintTiny(p->sFtpSize,"open %s\n\
		user %s %s\n\
		cd %s\n\
		dir %s %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sFileName,p->sFileSize)<0)
		{
		 printALERT("写文件 %s 失败.",p->sFtpSize);
		return -1;
		}
	return 0;
}

int GenFtpGet(struct PickParamStruct *pParam,struct PickCtlStruct *p)
{
	if(PrintTiny(p->sFtpGet,"open %s\n\
		user %s %s\n\
		bin\n\
		cd %s\n\
		lcd %s\n\
		get %s %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,pParam->sLocalPath,
		p->sFileName,p->sTargetTemp)<0){

		printALERT("写文件 %s 失败.",p->sFtpGet);
		return -1;
	}
	return 0;
}

int GenFtpRename(struct PickParamStruct *pParam,struct PickCtlStruct *p)
{
	if(PrintTiny(p->sFtpRename,"open %s\n\
		user %s %s\n\
		rename %s%s %s%s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sFileName,pParam->sOppBkupPath,
		p->sFileName)<0){
		
		printALERT("写文件 %s 失败.",p->sFtpRename);
		return -1;
	}
	return 0;
}

int GenFtpDelete(struct PickParamStruct *pParam,struct PickCtlStruct *p)
{
	if(PrintTiny(p->sFtpDelete,"open %s\n\
		user %s %s\n\
		cd %s\n\
		delete %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sFileName)<0){

		printALERT("写文件 %s 失败",p->sFtpDelete);
		return -1;
	}
	return 0;
}

