#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>


#define MAX_HEAD 100

struct _InHeadAntiStruct
{
	int ln;
	int cl;
	char sHeadPreFix[20];
	char sHeadRange[1024];
};
struct _InHeadStruct
{
	struct _InHeadStruct *pNext;
	char sAreaCode[10];
	int ln;
	int iCnt;
	struct _InHeadAntiStruct Anti[MAX_HEAD];
};
struct _OutHeadStruct
{
	struct _OutHeadStruct *pNext;

	char sHead[12];
	char sAreaCode[10];
};

/*遇到H1,H2,H3的行，初始化全局变量用的*/
int InitHeadPreFix(char sRecord[],int ln,
	int *piCnt,char asHeadPreFix[MAX_HEAD][20])
{
	int i=0;
	char sTemp[128];

	if(strstr(sRecord,"H1H2H3")==NULL){
		printf("第%d行,标识错误.\n",ln);
		return -1;
	}
	
	for(i=0;i<MAX_HEAD;i++){
		GetSepStrX(sRecord,'\t',i,20,sTemp);
		if(strstr(sTemp,"H1H2H3")!=NULL){
			*piCnt=i;
			strcpy(asHeadPreFix[i],sTemp);
		}
	}

	return 0;
}
int ExistDigital(char sInput[])
{
	int i;
	
	for(i=0;i<strlen(sInput);i++)
		if(sInput[i]>='0'&&sInput[i]<='9') return true;
	return false;
}
int ValidItem(char sItem[],int *piPos)
{
	int i;

	*piPos=0;
	for(i=0;i<strlen(sItem);i++){

		if((sItem[i]>='0'&&sItem[i]<='9')||
			sItem[i]==','||sItem[i]=='-') continue;
		*piPos=i;
		return false;
	}
	return true;
}
/*遇到河北的行，初始化INHEAD结构*/
int InitInHeadStruct(char sRecord[],int ln,int iCnt,
	char asHeadPreFix[MAX_HEAD][20],struct _InHeadStruct *po)
{
	int i=0,j=0,iPos;
	char sTemp[1024];

	bzero((void*)po,sizeof(struct _InHeadStruct));

	GetSepStrX(sRecord,'\t',2,10,sTemp);
	
	strcpy(po->sAreaCode,sTemp);
	po->ln=ln;

	for(i=3;i<MAX_HEAD;i++){
		
		GetSepStrX(sRecord,'\t',i,1023,sTemp);
		/*没东西*/
		if(strlen(sTemp)==0) continue;
		/*没数字的不要*/
		if(ExistDigital(sTemp)==false) continue;

		if(i>iCnt){
			printf("第%d行,格式非法->%d列没标题.\n",ln,i);
			return -1;
		}
		/*获取对应关系*/
		po->Anti[j].ln=ln;
		po->Anti[j].cl=i;
		strcpy(po->Anti[j].sHeadPreFix,asHeadPreFix[i]);
		
		/*支持中文模式*/
		ReplaceStr(sTemp," ","");
		ReplaceStr(sTemp,"　","");
		ReplaceStr(sTemp,"－","-");
		ReplaceStr(sTemp,"，",",");
		ReplaceStr(sTemp,"、",",");
		ReplaceStr(sTemp,"\n","");
		ReplaceStr(sTemp,"\r","");

		
		if(ValidItem(sTemp,&iPos)==false){
			printf("第%d行,第%d列，格式非法,填充符必须为[数字,空格,逗号,间隔符].\n",ln,i);
			printf("内容:|%s|\n",sTemp);printf("      ");
			while(iPos>0){printf(" ");iPos--;}printf("^\n");
			return -1;
		}
		strcpy(po->Anti[j].sHeadRange,sTemp);
		j++;
	}
	po->iCnt=j;

	return 0;
}
/*将文本文件转换到_InHeadList结构中*/
int TxtFile2InHeadList(char sFileName[],struct _InHeadStruct **pptHead)
{
	int iCnt=0,l,ln=0;
	char sRecord[2048],asHeadPreFix[MAX_HEAD][20];
	struct FileControlStruct *ptHead=NULL,*ptLkHead=NULL,*pTemp;
	struct _InHeadStruct *p,*pList=NULL;
	
	if(TxtFileToList(sFileName,&ptLkHead)<0){
		printf("文件%s加载到内存错误.\n",sFileName);
		return -1;
	}
	
	ptHead=ptLkHead;
	
	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		ln++;
		l=pTemp->iLen;if(l>=2047)l=2047;

		memcpy((void*)sRecord,pTemp->pData,l);sRecord[l]=0;
		
		Upper(sRecord);

		/*没数字的空行是不要的*/
		if(ExistDigital(sRecord)==false) continue;
	
		/*如果遇到行头则初始化之*/
		if(strstr(sRecord,"H1H2H3")!=NULL){
			if(InitHeadPreFix(sRecord,ln,&iCnt,asHeadPreFix)<0)
				return -1;
			continue;
		}
		if((p=malloc(sizeof(struct _InHeadStruct)))==NULL){
			printf("分配内存struct _InHeadStruct错误.\n");
			return -1;
		}
		
		if(InitInHeadStruct(sRecord,ln,iCnt,asHeadPreFix,p)<0)
			return -1;
		
		InsertList((LIST**)&pList,(LIST*)p);
	}
	/*释放到原始纪录*/	
	DestroyList((LIST*)ptLkHead);

	ReverseList((LIST**)&pList);
		
	*pptHead=pList;

	return CountList((LIST*)pList);
}
/*将InHeadAnti转换为,OutList链表*/
int CvInHeadAnti2OutHead(char sAreaCode[],struct _InHeadAntiStruct *pi,
	struct _OutHeadStruct **ppOut)
{
	int i=0,iBgn,iEnd,j;
	char sItem[128],*pc,sPreFix[20],sHead[20],sBgn[128],sEnd[128];
	struct _OutHeadStruct *pList=NULL,*pTemp;
	
	
	if((pc=strchr(pi->sHeadPreFix,'H'))==NULL){
		printf("号头标题错误.\n");
		return -1;
	}
	
	strncpy(sPreFix,pi->sHeadPreFix,pc-pi->sHeadPreFix);
	sPreFix[pc-pi->sHeadPreFix]=0;
	
	while(1){
		GetSepStrX(pi->sHeadRange,',',i,127,sItem);
		i++;
		if(i>=100) break;
		if(strlen(sItem)==0) continue;

		/*将item解码成temp写到链表中去*/
		/*不是一个范围*/
		if((pc=strchr(sItem,'-'))==NULL){
			strcpy(sBgn,sItem);
			strcpy(sEnd,sItem);
		}
		else{
			strncpy(sBgn,sItem,pc-sItem);
			sBgn[pc-sItem]=0;AllTrim(sBgn);
			pc++;strcpy(sEnd,pc);AllTrim(sEnd);
		}
		
		/*位长大于4位或H123的4位错误*/
		if((strlen(sBgn)>4||strlen(sEnd)>4)||
			((strlen(sBgn)==4||strlen(sEnd)==4)&&
			 strstr(pi->sHeadPreFix,"H0H1H2H3")==NULL&&1==0)){
			printf("第%d行，第%d列,号头内容错误%s-%s.\n",
				pi->ln,pi->cl,sBgn,sEnd);
			return -1;
		}


		iBgn=atoi(sBgn);iEnd=atoi(sEnd);
		
		for(j=iBgn;j<=iEnd;j++){
			
			if(strstr(pi->sHeadPreFix,"H0H1H2H3")!=NULL||
				strlen(sBgn)==4)
				sprintf(sHead,"%s%04d",sPreFix,j);
			else	sprintf(sHead,"%s%03d",sPreFix,j);
			
			if(strlen(sHead)!=7&&strlen(sHead)!=8&&strlen(sHead)!=9){
				printf("第%d行，第%d列,号头标题错误h=%s.\n",
					pi->ln,pi->cl,sHead);
				return -1;
			}

			if((pTemp=malloc(sizeof(struct _OutHeadStruct)))==NULL){
				printf("分配内存错误.\n");
				return -1;
			}
			
			bzero((void*)pTemp,sizeof(struct _OutHeadStruct));
	
			strcpy(pTemp->sAreaCode,sAreaCode);
			strcpy(pTemp->sHead,sHead);
			
			InsertList((LIST**)&pList,(LIST*)pTemp);
		}
			
	}
	ReverseList((LIST**)&pList);
	
	*ppOut=pList;

	return 0;
}
/*将整个InHead结构转换为OutList链表*/
int CvInHead2OutHead(struct _InHeadStruct *pIn,struct _OutHeadStruct **ppOut)
{
	int i;
	struct _InHeadStruct *ptHead,*pTemp;
	struct _OutHeadStruct *pList=NULL,*pOut=NULL;
	
	ptHead=pIn;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		for(i=0;i<pTemp->iCnt;i++){

			if(CvInHeadAnti2OutHead(pTemp->sAreaCode,
				&pTemp->Anti[i],&pOut)<0) return -1;

			/*将整理好的数据加到末尾*/	
			AppendListTail((LIST**)&pList,(LIST*)pOut);
		}
	}
	
	DestroyList((LIST*)pIn);

	*ppOut=pList;

	return 0;
}
/*将OutList链表转换为文本输出*/
int OutHeadList2TxtFile(struct _OutHeadStruct *pOutList,char sFileName[])
{
	int iCnt=0;
	char sRecord[256];
	struct _OutHeadStruct *ptHead,*pTemp;
	struct FileControlStruct *pList=NULL;
	
	ptHead=pOutList;

	while(ptHead!=NULL){

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		sprintf(sRecord,"%s\t%s\n",pTemp->sHead,pTemp->sAreaCode);
		
		if(item2list(&pList,(void*)sRecord,strlen(sRecord))<0){
			printf("分配内存错误.\n");
			return -1;
		}
		free(pTemp);
	}
	
	ReverseList((LIST**)&pList);
	
	if((iCnt=list2file(&pList,sFileName))<0){
		printf("写文件%s错误.\n",sFileName);
		return -1;
	}

	return iCnt;
}

int main(int argc,char *argv[])
{
	int iCnt;
	char sSourceName[256],sTargetName[256];
	struct _InHeadStruct *ptHead=NULL;
	struct _OutHeadStruct *pOutList=NULL;

        if(argc!=3){
                printf("Usage: cvhead sourcename targetname.\n");
                exit(1);
        }

	strcpy(sSourceName,argv[1]);
	strcpy(sTargetName,argv[2]);

	/*将文件读到InHead结构链表*/
	if(TxtFile2InHeadList(sSourceName,&ptHead)<0) return -1;
	
	/*将InHead结构链表转换为OutHead链表*/
	if(CvInHead2OutHead(ptHead,&pOutList)<0) return -1;
	
	/*将OutHead链表输出到文件*/
	if((iCnt=OutHeadList2TxtFile(pOutList,sTargetName))<0) return -1;
	
	printf("将文件%s转换为%s文件成功,生成%d条纪录.\n",
		sSourceName,sTargetName,iCnt);

	return 0;
}

