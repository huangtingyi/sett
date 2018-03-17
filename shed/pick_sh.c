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

/*���ɻ�ȡFTP�ֽڵ�����*/
	if(GenFtpSize(pParam,p)<0) return -1;
/*ִ��FTP�����ȡdir ��Ϣ�������ļ�*/
	if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",p->sFtpSize)!=0)
		return -1;
/*��ȡ�м�¼��sSize��*/
	sprintf(sCommand,"cat %s | head -1",p->sFileSize);
	if(exec2str(sCommand,sSize)!=0) return -1;
/*����ͨ�û�ȡ�ֽڵĺ�����ȡ�Զ��ֽ���*/
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

	/*д��ǿ����ͨ��Ϊֻ������Сʱǰ���ļ�*/
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
        	printALERT("date��������,date=%s",sInDate);
        	return -1;
	}

	
/*##���ɻ�ȡĿ¼�б�����*/
	if(GenFtpDList(pParam,p)<0) return -1;

	if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
		p->sFtpDList)!=0){
		printALERT("��ȡ�Զ��ļ��б�ʧ��DIRNAMELIST,%s",
			p->sFtpDList);
		return 1;
	}
/*����ļ������ڷ���*/
	if(IsFile(p->sDirNameList)==FALSE)return -1;
 	
	if(TxtFileToList(p->sDirNameList,&ptHead)<0) return -1;
	
	strcpy(sOppPath,pParam->sOppPath);
	
 	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*��������ȡ��Ŀ¼��*/
		
		
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

/*##���ɻ�ȡ�ļ��б�����*/
	if(GenFtpNList(pParam,p)<0) return -1;

	if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
		p->sFtpNList)!=0){
		printALERT("��ȡ�Զ��ļ��б�ʧ��FILENAMELIST,%s",
			p->sFtpNList);
		return 1;
	}
	
/*����ļ������ڷ���*/
	if(IsFile(p->sFileNameList)==FALSE)return -1;

/*����ǲ�ɾ���ı�־������ó�����ļ��б���Ԥ����*/
	if(strcmp(pParam->sDeleteType,"0")==0){

		if(execcmd("%s %s %s",p->sPickDup,pParam->sSourceID,
			p->sFileNameList)!=0){
			printALERT("���� %s %s %sʧ��",p->sPickDup,
				pParam->sSourceID,p->sFileNameList);
			return -1;
		}
	}

/*����ļ���ȡ���ļ��б�Ϊ�������*/
	if(FileSize(p->sFileNameList)<=0) return 1;

/*���ļ��б�����ڴ�*/
	if(TxtFileToList(p->sFileNameList,&ptHead)<0) return -1;

/*���ļ��б���*/
	ptLkHead=ptHead;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(WantQuit()==true){
			WriteProcMsg("���յ��˳��źţ������˳�");
			break;
		}

		memcpy(sLine,pTemp->pData,pTemp->iLen);
		sLine[pTemp->iLen] = '\0';

	/*�Ȼ�ȡ�ļ�������ȡ���������*/
		GetFilterFileName(sLine,pParam->sFilter,sFileName);

		if(strcmp(sFileName,"")==0) continue;
	/*�����������ڽṹ��*/
		strcpy(p->sFileName,sFileName);
		sprintf(p->sTargetTemp,"%s.pik",sFileName);

	        if((iFlag=PickLogCheck(pParam->sSourceID,sFileName,
			pParam->iChkDays))<0){
	        	printALERT("����PickLogCheckʧ��.");
	        	return -1;
	        }
	        if(iFlag==1) continue;/*�Ѿ��ɹ�,�򲻲���*/


	/*��ȡ�ļ����к�*/
		if(pParam->iSeqOff<1) pParam->iSeqOff=1;
		strncpy(sTemp,sFileName+pParam->iSeqOff-1,pParam->iSeqLen);
		sTemp[pParam->iSeqLen]=0;
		iSeq=	atoi(sTemp);
	       
	        GetHostTime(sDealBeginDate);

	/*���ε���FTP��ȡԶ���ļ��ֽ���������ֽ�����һ����continue*/
		iSize1=GetRemoteFileSize(pParam,p);
		sleep(1);
		iSize2=GetRemoteFileSize(pParam,p);

		if(iSize1!=iSize2) continue;
		
		
	/*���ɻ�ȡ��������ɾ������ű��ļ�*/
		if(GenFtpGet(pParam,p)<0) return -1;
		if(GenFtpRename(pParam,p)<0) return -1;
		if(GenFtpDelete(pParam,p)<0) return -1;

	/*���Զ�������ȡ�ļ�*/
		if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",p->sFtpGet)!=0){
			printALERT("FTP��ȡ%s��%s�µ�%sʧ��.",
				pParam->sIp,pParam->sOppPath,sFileName);
			continue;
		}
	/*����Զ˵������ļ��ֽڻ�ȡ����,��ȡ��ȡ�����ļ��ֽ���*/
		sprintf(sTempName,"%s%s",pParam->sLocalPath,p->sTargetTemp);
		iSize2=FileSize(sTempName);
	/*�����ȡ���ļ������������*/
		if(iSize2<0) continue;
		
		iFlag=ChkIpTpye(pParam->sIp,pParam->sSourceID,p->sFileName);
		
		if(iSize1!=0&&iFlag!=0){
			if(iSize1!=iSize2){
			/*���ݱ����ļ��������ɼ���һ���ļ�*/
				printALERT("�ɼ����ļ�%s=%dԶ���ļ�%s=%d,��С��ͬ",
					sTempName,iSize2,p->sFileName,iSize1);
				execcmd("rm -f %s.%d",sTempName,p->pid);
				execcmd("mv %s %s.%d.",sTempName,sTempName,p->pid);
				continue;
			}
		}

		iSize1=iSize2;
			
		GetHostTime(sDealEndDate);

	/*д�ɼ����ݿ���־*/
		if (InsertPickLog(pParam->sSourceID,iSize1,sFileName,
			sDealBeginDate,sDealEndDate,iSeq,pParam->sOutType,
			pParam->iTacheID,pParam->sAppID)<0){

			printALERT("д�ɼ���־ʧ��");

		/*д��־ʧ����ɾ���ɼ���������ʱ�ļ�*/
			execcmd("rm -f %s",sTempName);
			return -1;
		}

		CommitWork();
	/*��¼��־�ɹ��������κ��쳣��Ҫ�˳�����������ʱ�ļ�*/
	
	/*�Զ��ļ�����0 ��ɾ��  1 ɾ��  2 ���ݣ�*/
		switch(atoi(pParam->sDeleteType)){
		case 1:/*ɾ��Զ���ļ�*/
			if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
				p->sFtpDelete)!=0){
				printALERT("ɾ���Զ����� %s Ŀ¼ %s �µ��ļ� %s ʧ��",
				pParam->sIp,pParam->sOppPath,sFileName);
				return -1;
					
			}
			break;
		case 2:
			if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
				p->sFtpRename)!=0){
				printALERT("���ݶԶ����� %s Ŀ¼ %s �µ��ļ� %s �� %s ʧ��",
					pParam->sIp,pParam->sOppPath,
					sFileName,pParam->sOppBkupPath);
				return -1;
					
			}
			break;
		default:
			break;
		}			

	/*����ʱ�ļ����޸�Ϊ��ʽ���ļ���*/
		if(execcmd("mv %s %s%s",sTempName,pParam->sLocalPath,
			p->sFileName)!=0){
			printALERT("����%s��%s%sʧ��",
				sTempName,pParam->sLocalPath,p->sFileName);
			return -1;
		}
	
	/*�Զ���ѹ����֧�֣��������ѹ�����ļ����Ƚ�ѹ*/
		if(RLike(p->sFileName,".gz")==true){
			if(execcmd("gunzip %s%s",pParam->sLocalPath,
				p->sFileName)!=0){
				printALERT("��ѹ%s%sʧ��",
					pParam->sLocalPath,p->sFileName);
				return -1;
			}
		}
		else if(RLike(p->sFileName,".Z")==true){
			if(execcmd("uncompress %s%s",pParam->sLocalPath,
				p->sFileName)!=0){
				printALERT("��ѹ%s%sʧ��",
					pParam->sLocalPath,p->sFileName);
				return -1;
			}
		}
		
		printNORMAL("%s�ɹ��ɼ��ļ�%s�ֽ�%d",
			pParam->sSourceID,sFileName,iSize1);
		if(p->iFlag==true)
			printsourceNORMAL(pParam->sSourceID,
			"%s�ɹ��ɼ��ļ�%s�ֽ�%d",
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
		printf("date����˵��:.\n");
		printf("	 Dn 	D3��Ϊ��ǰϵͳʱ��ƫ��3��.\n");
		printf("	date    Ҫ�ɼ�������,yyyymmdd��ʽ.\n");
		return -1;
	}

	InitAppRes("pick.sh");
	
	strcpy(sFileName,argv[1]);
	iGroupID=atoi(argv[2]);
	strcpy(sDate,argv[3]);


/*Ĭ��дpick.sh.xxxxxx.log��־��ֻ�е���������Ϊ0��ʱ��д������־*/
	iFlag=true;
	if(argc==5){
		if(strcmp(argv[4],"0")==0)iFlag=false;
	}

	signal(SIGQUIT,NotifyQuit);
	signal(SIGINT, NotifyQuit);

/*��ʼ�����ֵĿ����ļ���*/
	if(InitPickCtl(iFlag,&PickCtl)<0) return -1;

/*����Ҫ����Ĳ�����ȡ�� ������*/
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
		        printALERT("����·��%s��Ч.",pTemp->sLocalPath);
		        return -1;
		}
	/*���һ��������ͨ״��*/
		if(PingIpOk(pTemp->sIp)==false&&
			strcmp(pTemp->sIp,"133.96.48.65")!=0){
			printALERT("IP��ַ %s �޷� ping ͨ",pTemp->sIp);
			continue;
		}
			
	/*�Ƿ�Ҫ���Զ˰����ڷ�Ŀ¼���� /YYYYMMDD */
		if(ChkDir(pTemp->sOutType,pTemp->sSourceID)==0){
	
			if(ProcessOppDir(pTemp,&PickCtl,sDate)<0){
				printALERT("%s IP:%s %s %s �ɼ�ʧ��,ping ͨ",
					pTemp->sSourceID,pTemp->sIp,
					pTemp->sUserName,pTemp->sPasswd);
			}
		}
		else{
			if(ProcessMain(pTemp,&PickCtl)<0){
				printALERT("%s IP:%s %s %s �ɼ�ʧ��,ping ͨ",
					pTemp->sSourceID,pTemp->sIp,
					pTemp->sUserName,pTemp->sPasswd);
			}
		}
	/*ɾ����ʱ�����ļ�*/
		DeleteFtpCtl(&PickCtl);
		
		if(WantQuit()==true) break;
	}
/*�ͷ��ڴ�*/
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
		printALERT("Ӧ�ó���%s������",p->sPickDup);
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
			
		printALERT("д�ļ� %s ʧ��.",p->sFtpNList);
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
			
		printALERT("д�ļ� %s ʧ��.",p->sFtpDList);
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
		 printALERT("д�ļ� %s ʧ��.",p->sFtpSize);
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

		printALERT("д�ļ� %s ʧ��.",p->sFtpGet);
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
		
		printALERT("д�ļ� %s ʧ��.",p->sFtpRename);
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

		printALERT("д�ļ� %s ʧ��",p->sFtpDelete);
		return -1;
	}
	return 0;
}

