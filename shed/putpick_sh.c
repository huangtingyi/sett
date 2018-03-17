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
void GetFilterFileName(char sLine[],char sFilter[],char sFileName[])
{
	int i=0;
	char	sCommand[256],sTempName[256];

	strcpy(sFileName,"");

	while(1){
		/*ȡһ���ֶΣ������´���*/
		GetSepStr(sLine,'\t',i,sTempName);i++;
		if(strcmp(sTempName,"")==0) break;


		/*�����ļ��б��е��ļ�����ͨ���������*/
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

/*���һ��������ͨ״��*/
	if(PingIpOk(pParam->sIp)==false){
		printALERT("IP��ַ %s �޷� ping ͨ",pParam->sIp);
		return -1;
	}

/*����һ���ļ��б�*/
	if(dir2list(pParam->sLocalPath,pParam->sFilter,&ptHead)<0){
		printALERT("�����ļ��б�ʧ�� %s %s",
			pParam->sLocalPath,pParam->sFilter);
		return -1;
	}

/*���ļ��б���*/
	ptLkHead=ptHead;
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		strncpy(sFileName,(char*)(pTemp->pData),pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		AllTrim(sFileName);

		if(strcmp(sFileName,"")==0) continue;
	/*�����������ڽṹ��*/
	/*����ļ��ձ��޸��򲻴���*/
		sprintf(sTempName,"%s%s",pParam->sLocalPath,sFileName);
		if(FileModifyDiff(sTempName)<6) continue;
		
		strcpy(p->sFileName,sFileName);
		sprintf(p->sTargetTemp,"%s.pik",sFileName);

	        if((iFlag=PutLogCheck(pParam->sSourceID,sFileName,-1))<0){
	        	printALERT("����PickLogCheckʧ��.");
	        	return -1;
	        }
	        if(iFlag==1) continue;/*�Ѿ����͹�,�򲻷�����*/


	/*��ȡ�ļ����к�*/
		if(pParam->iSeqOff<1) pParam->iSeqOff=1;	
		strncpy(sTemp,sFileName+pParam->iSeqOff-1,pParam->iSeqLen);
		sTemp[pParam->iSeqLen]=0;
		iSeq=	atoi(sTemp);
	       
	        GetHostTime(sDealBeginDate);

	/*���ɻ�ȡ��������ɾ������ű��ļ�*/
		if(GenFtpPut(pParam,p)<0) return -1;
		if(GenFtpRename(pParam,p)<0) return -1;
		if(GenFtpDelete(pParam,p)<0) return -1;

	/*���Զ�������ȡ�ļ�*/
		if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",p->sFtpPut)!=0){
			printALERT("FTP����IP %s��%s�µ�%sʧ��.",
				pParam->sIp,pParam->sOppPath,sFileName);
			continue;
		}
	/*���ͳɹ���ȡһ�¶Զ���ʱ�ļ��Ĵ�С*/
		iSize1=GetRemoteFileSize(pParam,p);
	/*����Զ˵������ļ��ֽڻ�ȡ����,��ȡ��ȡ�����ļ��ֽ���*/
		
		iSize2=FileSize(sTempName);

	/*������͵��ļ��ͶԶ��ļ���С��һ�£��򽫶Զ���ʱ�ļ�ɾ��,����*/		
		if(iSize1!=iSize2){
			if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
				p->sFtpDelete)!=0){
				printALERT("ɾ���Զ����� %s Ŀ¼ %s �µ��ļ� %s ʧ��",
				pParam->sIp,pParam->sOppPath,p->sTargetTemp);
				return -1;
					
			}
			continue;
		}
		GetHostTime(sDealEndDate);

		if(execcmd("cat %s | ftp -n 2>&1 >/dev/null",
			p->sFtpRename)!=0){
			printALERT("���ݶԶ����� %s Ŀ¼ %s �µ��ļ� %s �� %s ʧ��",
				pParam->sIp,pParam->sOppPath,
				p->sTargetTemp,sFileName);
				return -1;
		}

	/*д�������ݿ���־*/
		if (InsertPutLog(pParam->sSourceID,iSize1,sFileName,
			sDealBeginDate,sDealEndDate,iSeq,"x",0,"0")<0){

			printALERT("д������־ʧ��");

		/*д��־ʧ���򱸷ݷ��͹����ļ�Ϊ��ʱ�ļ�
			execcmd("cp %s %s%s",sTempName,
				pParam->sLocalPath,p->sTargetTemp);
			return -1;*/
		}

		CommitWork();
	/*��¼��־�ɹ��������κ��쳣��Ҫ�˳�����������ʱ�ļ�*/
	
	/*�Զ��ļ�����0 ��ɾ��(��֧��->2)  1 ɾ��  2 ���ݣ�*/
		switch(atoi(pParam->sDeleteType)){
		case 1:/*ɾ��Զ���ļ�*/
			if(execcmd("rm -f %s",sTempName)!=0){
				printALERT("ɾ���ļ� %s ʧ��",sTempName);
				return -1;					
			}
			break;
		case 2:
		case 0:
			if(execcmd("mv %s %s%s 2>&1 >/dev/null",
				sTempName,pParam->sLocalBkupPath,sFileName)!=0){
				printALERT("�����ļ� %s �� %s Ŀ¼ʧ��",
					sTempName,pParam->sLocalBkupPath);
				return -1;
			}
			printf("sLocalBkupPath=%s\n",pParam->sLocalBkupPath);
			printf("sTempName=%s\n",sTempName);
			break;
		default:
			printALERT("Ŀǰ��֧�� %s �ı�������",pParam->sDeleteType);
			return -1;
		}			
		
		printNORMAL("%s�ɹ������ļ�%s�ֽ�%d�� %s:%s��",
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


/*��ʼ�����ֵĿ����ļ���*/
	if(InitPutPickCtl(&PutCtl)<0) return -1;

/*����Ҫ����Ĳ�����ȡ�� ������*/
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
		        printALERT("����·��%s��Ч.",pTemp->sLocalPath);
		        return -1;
		}
	/*�������ָʾҪ���ݴ��ͶԶ˵��ļ������ұ���Ŀ¼��Ч����ʾ*/
		/*if(strcmp(pTemp->sDeleteType,"2")==0&&
			IsDir(pTemp->sOppBkupPath)==false){
		        printALERT("����·��%s��Ч.",pTemp->sOppBkupPath);
		        return -1;
		}*/
		if(ProcessMain(pTemp,&PutCtl)<0) return -1;

	}
/*ɾ����ʱ�����ļ�*/
	DeleteFtpCtl(&PutCtl);
/*�ͷ��ڴ�*/
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

/*����������ȡ�Զ���ʱ�ļ���С������ű�*/
int GenFtpSize(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	if(PrintTiny(p->sFtpSize,"open %s\n\
		user %s %s\n\
		cd %s\n\
		dir %s %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sTargetTemp,p->sFileSize)<0){

		printALERT("д�ļ� %s ʧ��.",p->sFtpSize);
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

		printALERT("д�ļ� %s ʧ��.",p->sFtpPut);
		return -1;
	}
	return 0;
}

/*����ĸ����ǽ��Զ��ļ���Ϊ��ʽ���ļ���*/
int GenFtpRename(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	if(PrintTiny(p->sFtpRename,"open %s\n\
		user %s %s\n\
		rename %s/%s %s/%s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sTargetTemp,pParam->sOppPath,
		p->sFileName)<0){
		
		printALERT("д�ļ� %s ʧ��.",p->sFtpRename);
		return -1;
	}
	return 0;
}
/*�������ڻ��˵������ɾ���Զ˵���ʱ�ļ�*/
int GenFtpDelete(struct PutParamStruct *pParam,struct PutPickCtlStruct *p)
{
	if(PrintTiny(p->sFtpDelete,"open %s\n\
		user %s %s\n\
		cd %s\n\
		delete %s\n\
		bye\n",
		pParam->sIp,pParam->sUserName,pParam->sPasswd,
		pParam->sOppPath,p->sTargetTemp)<0){

		printALERT("д�ļ� %s ʧ��",p->sFtpDelete);
		return -1;
	}
	return 0;
}

