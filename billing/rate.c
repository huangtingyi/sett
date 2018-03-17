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
#include <wwsupp.h>
#include <ticket_field.h>
#include <tariff_disct.h>

#include <ticket.h>
#include <bill_supp.h>

int main(int argc,char *argv[])
{
	int i,iStartPos,iKeyLen,iWantCtl;
	char sTemplateRule[128],sModule[4],sSplitStr[10],sVisitAreaCode[10];
	char sNormalDir[128],sErrDir[128],sExprName[128],sFileName[128];
	char sResult[1024],sSplit[10],sSource[10];
	struct	FileControlListStruct *pControlList=NULL;
	
	if(argc!=13&&argc!=10){
		printf("Usage %s input normaldir errdir expr templateid "
			"splitstr visitcode module source.\n",argv[0]);
		printf("or\n");
		printf("Usage %s input normaldir errdir expr templateid "
			"splitstr visitcode module source split startpos keylen.\n",argv[0]);
		return -1;
	}
/*��ʼ����������*/
	InitAppRes(argv[0]);
	iWantCtl=WantCtl(argv[0]);
	strcpy(sFileName,argv[1]);
	strcpy(sNormalDir,argv[2]);
	strcpy(sErrDir, argv[3]);
	strcpy(sExprName,argv[4]);
	strcpy(sTemplateRule,argv[5]);
	strcpy(sSplitStr,argv[6]);
	strcpy(sVisitAreaCode,argv[7]);
	strncpy(sModule,argv[8],3);sModule[3]=0;
	
	strncpy(sSource,argv[9],6);sSource[6]=0;
	
	iStartPos=iKeyLen=0;
	strcpy(sSplit,"");
	if(argc==13){
		strncpy(sSplit,argv[10],9);sSplit[9]=0;
		iStartPos=atoi(argv[11]);
		iKeyLen=atoi(argv[12]);
	}

/**�������Ϸ���*******/
	if(IsFile(sFileName)==FALSE){
		printf("�����ļ�%s��Ч.\n",sFileName);
		return -1;
	}
	if(IsDir(sNormalDir)==FALSE){
		printf("�������Ŀ¼%s��Ч.\n",sNormalDir);
		return -1;
	}
	if(IsDir(sErrDir)==FALSE){
		printf("����쳣Ŀ¼%s��Ч.\n",sErrDir);
		return -1;
	}
	RegularDir(sNormalDir);
	RegularDir(sErrDir);
/*��ʼ�����۲���*/	
	InitParamMem();
/*����RATE��ʽ*/
	if(CompileExprFile(sExprName)<0) return -1;
		
/*���������б�*/
	InitFileControlList(sTemplateRule,sSplitStr,&pControlList);
	pFileControlList=pControlList;

/*���������������ļ�*/
	i=ProcessRateFile(sFileName,sVisitAreaCode,sModule,sNormalDir,sErrDir,
		sSource,iWantCtl,sSplit,iStartPos,iKeyLen,pControlList,sResult);
/*��ӡ������*/
	printf(sResult);
/*��pFileControlList�ͷ�*/
	DestroyFileControlList(pControlList);
/*�ͷ����۲���*/
	DestroyParamMem();
	return i;
}
