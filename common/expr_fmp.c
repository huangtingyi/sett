#include <stdio.h>
#include <hnixs.h>
#include <wwdir.h>
#include <wwlog.h>
#include <list.h>
#include <expr.h>
#include <expr_supp.h>
#include <expr_fun.h>
#include <expr_fmp.h>

struct BlockDefStruct *pDefFun=NULL,*pCurFun=NULL;

/*�����ڴ棬������ʷ����������ͷ��*/
int AssignLSymHead(struct LSymbolStruct **pptHead,struct LSymbolStruct *p)
{
	struct LSymbolStruct *pTemp;

	if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL) return -1;

	memcpy((void*)pTemp,(void*)p,sizeof(struct LSymbolStruct));

	InsertList((LIST**)pptHead,(LIST*)pTemp);

	return 0;
}
/*�����ڴ棬������ʷ����������β��*/
int AssignLSymTail(struct LSymbolStruct **pptHead,struct LSymbolStruct *p)
{
	struct LSymbolStruct *pTemp;

	if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL) return -1;

	memcpy((void*)pTemp,(void*)p,sizeof(struct LSymbolStruct));

	InsertListTail((LIST**)pptHead,(LIST*)pTemp);

	return 0;
}
void PrintLSymList(struct LSymbolStruct *ptHead)
{
	int i=0,j;
	
	printf("------------------------------------------bgn\n");
	while(ptHead!=NULL){
		for(j=0;j<strlen(ptHead->s.sValue);j++)
			putchar(ptHead->s.sValue[j]);

		/*����û�п��еľ��Ӽ���ϻس�*/
		if((strcmp(ptHead->s.sValue,";")==0||
			strcmp(ptHead->s.sValue,"{")==0||
			strcmp(ptHead->s.sValue,"}")==0)&&
			ptHead->pNext!=NULL){

			if(strcmp(ptHead->pNext->s.sValue,"\n")!=0&&
				strcmp(ptHead->pNext->s.sValue,"\r")!=0)
				putchar('\n');
		}
	
		ptHead=ptHead->pNext;
		if(i++>1000) break;

	}
	printf("\n");
	printf("end------------------------------------------\n");
}
/*����һ���궨��*/
int SearchBlockDef(struct BlockDefStruct *ptHead,char sName[],
	struct BlockDefStruct **pptCur)
{
	*pptCur=NULL;
	while(ptHead!=NULL){
		if(strcmp(sName,ptHead->sName)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void DestroyBlockDef(struct BlockDefStruct *ptHead)
{
	struct BlockDefStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		DestroyList((LIST*)pTemp->pHead);
		DestroyList((LIST*)pTemp->pBody);
		free(pTemp);
	}
}
/*���Ԥ��������*/
int ChkPropCond(char sSymbol[],struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pDef)
{
	char sName[128];
	struct BlockDefStruct *pNoUse=NULL;

	strcpy(sName,ptHead->s.sValue);

	if(strcmp(sSymbol,"#ifdef")==0){
		if(SearchBlockDef(pDef,sName,&pNoUse)==FOUND) return true;
		return false;
	}
	else if(strcmp(sSymbol,"#ifndef")==0){
		if(SearchBlockDef(pDef,sName,&pNoUse)==NOTFOUND) return true;
		return false;
	}
	return false;
}
/*֧��Ԥ���빦�ܵ�������䴦��*/
int PropStatement(struct LSymbolStruct *pTemp,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,int iFlag,
	char sMsg[])
{
	int i=-1;
	struct LSymbolStruct *pTail;
	
	strcpy(sMsg,"");

	/*�����Ԥ������䣬�������Ӧ��������*/
	if(pTemp->s.iType==TYPE_PRECOMP_CONTROL){
		/*�����define������޸ĺ�����*/
		if(strcmp(pTemp->s.sValue,"#define")==0)
			i=PropDefineStatement(pTemp,ppDef,ppHead,&pTail,iFlag,sMsg);
		/*�����#include�����ֱ��#include������*/
		else if(strcmp(pTemp->s.sValue,"#include")==0)
			i=PropIncludeStatement(pTemp,ppDef,ppHead,&pTail,sMsg);
		/*�����#ifdef�� #ifndef���*/
		else if(strcmp(pTemp->s.sValue,"#ifdef")==0||
			strcmp(pTemp->s.sValue,"#ifndef")==0)
			i=PropIfStatement(pTemp,ppDef,ppHead,&pTail,sMsg);
		else
			sprintf(sMsg,"Ԥ�������� %s��֧��",pTemp->s.sValue);
	}
	else
		i=PropNormalLines(pTemp,*ppDef,ppHead,&pTail,sMsg);

	if(i<0) return -1;
	*ppTail=pTail;
	return 0;

}
/*�Է�Ԥ�����еĿ�ͷ���д���*/
int PropNormalLines(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	struct LSymbolStruct *pTail,*pTemp,*ptLkHead=NULL;
	
	strcpy(sMsg,"");

	while(ptHead!=NULL){		
		/*����п�ʼ��Ԥ��������ַ������˳�*/
		if(ptHead->s.iType==TYPE_PRECOMP_CONTROL) break;
		
		/*��ȡһ��*/
		if(GetSymLine(ptHead,&pTail,sMsg)<0) return -1;
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
		}

		ptHead=pTail;
	}

	/*�������ptLkHead��ת��*/
	ReverseList((LIST**)&ptLkHead);
	ptHead=ptLkHead;
	ptLkHead=NULL;

	/*��һ���б���к�չ��������չ�����׷�ӵ�ָ���б�*/
	if(DeployMicroList(ptHead,pDef,&ptLkHead,sMsg)<0) return -1;
		
	*ppTail=pTail;
	/*������������������ĩβ*/
	AppendListTail((LIST**)ppHead,(LIST*)ptLkHead);
	
	return 0;
}
/*
1.��������#ifdef �� #ifndef �������;
2.
	����: struct BlockDefStruct **ppDef; �Ѷ���ĺ�
		struct LSymbolStruct *ptHead; ���� #ifdef �� #ifndef �� #if�Ķ���;
	�����
		1.������ #if #ifndef #define #include ��Ԥ����ؼ��ֵȵ� struct LSymbolStruct **ppHead����;
		2.ppTail�����Ķ�����;
		3.����������꣬���޸�ppDef����;
		4.ע���ڴ���ͷ�==========================,Ŀǰû�н��;;
3.����;
	#ifdef ��
	1.�жϺ��Ƿ���������;
������:
	2.ƥ��
		#define
		#ifdef #ifndef
		#else
		#endif
	�⼸������;
	3.
		���
		a)����#define ���޸�Micro����;;
		b)����#ifdef �� #ifndef ���ظ������Լ���ȡһ�鶫��;
		c)����#endif �����;
			��������� #else ���ȡ #ԭʼλ�õ� #else�Ķ�����
			�������ԭʼλ�õ� #endif����Ϣ;;
		c)#else,���¼#elseλ��;
			���ֱ��
			  ����#define ���ǣ����޸�Micro����;;
			  ����#ifxxx��ֱ�ӻ�ȡһ�������;;
			  ����#endif��¼#endifλ��;;

��������:
		#���
			1.����#define������������������Ч;
			2.����#ifdef �� #ifndef ����������;
			3.ֱ������#endif������������������ȡΪ��;
			4.����#else���
				���
			����#define���������޸�Micro��;
			����#ifxxx��ֱ�Ӵ������ý���;;
			����#endif �򣬼�¼#endifλ�ã��� #else��#endif�еĶ����ó���;;

*/
/*����#ifdef �� #ifndef ���*/
int PropIfStatement(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,struct LSymbolStruct **ppTail,char sMsg[])
{
	char sSymbol[30];
	int iTrueFlag,iAfterElse,iFlag;
	
	struct LSymbolStruct *pTail,*pTemp,*pNoUse=NULL,**ppTmp;
	
	strcpy(sMsg,"");

	pTemp=ptHead;
	
	if(pTemp==NULL){
		strcpy(sMsg,"Ԥ����#if����쳣����");
		return -1;
	}

	if(strcmp(pTemp->s.sValue,"#ifdef")!=0&&
		strcmp(pTemp->s.sValue,"#ifndef")!=0){
		strcpy(sMsg,"Ԥ����#if����쳣�����ԡ�#ifdef��#ifndef��ͷ");
		return -1;
	}
	
	strcpy(sSymbol,pTemp->s.sValue);
	
	/*����Ԥ����#if�ؼ���*/
	pTemp=pTemp->pNext;
	
	/*ȡ��һ����Ϊ�߼��ж�*/
	if(GetSymLine(pTemp,&pTail,sMsg)<0) return -1;
	
	iTrueFlag=ChkPropCond(sSymbol,pTemp,*ppDef);
	iAfterElse=false;

	/*�ͷ� #ifdef �� #ifndef ���еĶ���*/
	DestroyList((LIST*)ptHead);
	
	ptHead=pTail;
	while(ptHead!=NULL){
		
		if((iTrueFlag==true&&iAfterElse==false)||
			(iTrueFlag==false&&iAfterElse==true))
			{ppTmp=ppHead;iFlag=true;}
		else{ppTmp=&pNoUse;iFlag=false;}

		/*����else��������־*/
		if(strcmp(ptHead->s.sValue,"#else")==0){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			free(pTemp);
			iAfterElse=true;
			continue;
		}
		/*����,����������÷���ֵ,����������Ϊ��*/
		if(strcmp(ptHead->s.sValue,"#endif")==0){
			pTemp=ptHead;
			*ppTail=ptHead->pNext;
			free(pTemp);
			/*�ͷ�nouse����*/
			DestroyList((LIST*)pNoUse);
			return 0;
		}
		/*������ͨ,#ifdef,#ifndef #include,#define���*/
		if(PropStatement(ptHead,ppDef,ppTmp,&pTail,iFlag,sMsg)<0)
			return -1;

		ptHead=pTail;
	}

	strcpy(sMsg,"������ű���� #ifdef �� #ifndef δƥ����#endif");
	return -1;
}
/*
���� #include���

����:
	1.struct BlockDefStruct **ppDef; �Ѷ���ĺ�
	struct LSymbolStruct *ptHead; ���� #include�Ķ���;
���:
		1.������ #if #ifndef #define #include ��Ԥ����ؼ��ֵȵ� struct LSymbolStruct **ppHead����;
		2.ppTail�����Ķ�����;
		3.����������꣬���޸�ppDef����;
*/
int PropIncludeStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[])
{
	char sInclPath[256],sBaseName[128],l=0,sInclName[256];
	struct LSymbolStruct *pTail,*pTemp;

	strcpy(sMsg,"");

/*�ȵõ���ʽ�����ļ�·��*/
	GetBillHome(sInclPath);
	strcat(sInclPath,"expr/include/");
	
	if(IsDir(sInclPath)==false){
		sprintf(sMsg,"·�� %s��������",sInclPath);
		return -1;
	}
/*����Ƿ��� #include ��ͷ*/
	if((pTemp=ptHead)==NULL){
		strcpy(sMsg,"Ԥ����#include����쳣����");
		return -1;
	}
	if(strcmp(pTemp->s.sValue,"#include")!=0){
		strcpy(sMsg,"Ԥ����#include����쳣�����ԡ�#include��ͷ");
		return -1;
	}
	
	/*����#include*/
	if((pTemp=pTemp->pNext)==NULL){
		strcpy(sMsg,"Ԥ����#include����쳣����");
		return -1;
	}
	
	/*��δ����ǻ�ȡ #include����ļ���,������*ppTail����*/
	if(pTemp->s.iType==TYPE_CONST_STR){
		strncpy(sBaseName,pTemp->s.sValue+1,strlen(pTemp->s.sValue)-2);
		sBaseName[strlen(pTemp->s.sValue)-2]=0;
	}
	else{
		if(strcmp(pTemp->s.sValue,"<")!=0){
			sprintf(sMsg,"#include ֮������ \"�� <,��������%s",
				pTemp->s.sValue);
			return -1;
		}
		/*���� <*/
		if((pTemp=pTemp->pNext)==NULL){
			strcpy(sMsg,"Ԥ����#include����쳣����");
			return -1;
		}
		l=0;
		while(pTemp!=NULL){
			if(strcmp(pTemp->s.sValue,">")==0) break;
			l+=sprintf(sBaseName+l,"%s",pTemp->s.sValue);
			pTemp=pTemp->pNext;
		}
		if(pTemp==NULL){
			strcpy(sMsg,"Ԥ����#include����쳣����");
			return -1;
		}
	}
	
	/*���ñ����ķ�����ֵ*/
	*ppTail=pTemp->pNext;
	pTemp->pNext=NULL;
	
	/*�� #include ���еĶ����ͷ�*/
	DestroyList((LIST*)ptHead);
	
	/*����ȫ���ļ�*/
	sprintf(sInclName,"%s%s",sInclPath,sBaseName);
	
	/*��include�ļ���includeջ�����ڴ���λ*/
	PushFileStack(sInclName);
	
	if(FileLexicalize(sInclName,sMsg)<0) return -1;
	
	/*��SymbolFlow�Ĵʷ������Ľ������ptHead��*/
	if(MoveSymbolFlowToLSymbolList(&ptHead)<0){
		sprintf(sMsg,"�����ڴ� struct LSymbolStruct��ʧ��");
		return -1;
	}
	/*�Ը�����䶼�ô�����һ��ѭ��,����Ԥ�������*/
	while(ptHead!=NULL){
		
		if(PropStatement(ptHead,ppDef,ppHead,&pTail,true,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	
	return 0;
}

/**
	1.��ȡһ���궨���ͷ,���ȡһ������õĺ�;
	2.*ppTail�Ǻ���������;
	3.ptHead������궨������õķ��Ŵ�����;
	4.pa[]���βλ�ʵ�����б�; ===>������ܴ洮����Ҫ������;;
**/

int GetHeadListComm(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[])
{
	int i=0;
	struct LSymbolStruct *pTemp;

	*ppTail=NULL;
	strcpy(sMsg,"");

	if(ptHead==NULL){
		strcpy(sMsg,"���쳣����");
		return -1;
	}

	pTemp=ptHead->pNext;
/*ֱ�ӽ�����OK*/
	if(pTemp==NULL) return 0;
/*����Ҫ���������һ��*/
	if(strcmp(pTemp->s.sValue,"(")!=0){
		*ppTail=ptHead->pNext;
		ptHead->pNext=NULL;
		return 0;
	}
/*����(*/
	pTemp=pTemp->pNext;

	while(pTemp!=NULL){
		/*֧��0����������ʽ*/
		if(i==0&&strcmp(pTemp->s.sValue,")")==0) break;

		pa[i].pSymBgn=pTemp;

		while(pTemp!=NULL){
			if(strcmp(pTemp->s.sValue,")")==0||
				strcmp(pTemp->s.sValue,",")==0) break;
			pTemp=pTemp->pNext;
		}
		if(pTemp==NULL){
			strcpy(sMsg,"���쳣����");
			return -1;
		}
		
		pa[i].pSymEnd=pTemp;

		i++;

		if(strcmp(pTemp->s.sValue,")")==0) break;

		if(strcmp(pTemp->s.sValue,",")!=0){
			sprintf("����β�֮�����Ϊ','���",
				pTemp->s.sValue);
			return -1;
		}
		/*����,','�����*/
		pTemp=pTemp->pNext;
	}
	*ppTail=pTemp->pNext;
	pTemp->pNext=NULL;

	return i;	
}
/*�����ʽ��������̬������Ϊһ����ʶ������ʽ�����򱨴���*/
int CheckModalityParam(char sName[],int iCnt,struct ParamDefStruct pa[],
	char sMsg[])
{
	int i;

	strcpy(sMsg,"");
	for(i=0;i<iCnt;i++){
		if(pa[i].pSymBgn->pNext!=pa[i].pSymEnd){
			sprintf(sMsg,"��%s�ĵ�%d���βγ���1��",sName,i);
			return -1;
		}
		if(pa[i].pSymBgn->s.iType!=TYPE_TEMPVAR){
			sprintf(sMsg,"��%s�ĵ�%d���βα�����һ����ʶ��",
				sName,i);
			return -1;
		}
	}
	return 0;
}
/*��ȡ�궨���ͷ*/
int GetMicroHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[])
{
	int iCnt;
	
	if((iCnt=GetHeadListComm(ptHead,ppTail,pa,sMsg))<0) return -1;
	
	if(CheckModalityParam(ptHead->s.sValue,iCnt,pa,sMsg)<0) return -1;
	
	
	return iCnt;
}
/*��ȡ�궨�������*/
int GetMicroRef(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	struct ParamDefStruct pa[],char sMsg[])
{
	return GetHeadListComm(ptHead,ppTail,pa,sMsg);
}
/*
	1.��ȡһ�м�¼;ע�����\n
*/
int GetSymLine(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	struct LSymbolStruct *pTemp;

	strcpy(sMsg,"");

	*ppTail=NULL;

	if(ptHead==NULL){
		strcpy(sMsg,"������ű����");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		if(strcmp(pTemp->s.sValue,"\n")==0){
			*ppTail=pTemp->pNext;
			pTemp->pNext=NULL;
			return 0;
		}
	}
	return 0;
}
/*��ȡһ������*/
int GetSymBlock(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	int i=0;

	struct LSymbolStruct *pTemp;
	
	strcpy(sMsg,"");

	if(ptHead==NULL){
		strcpy(sMsg,"������ű����");
		return -1;
	}

	if(strcmp(ptHead->s.sValue,"{")!=0){
		strcpy(sMsg,"�Ƿ����鿪ʼ");
		return -1;
	}

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->s.sValue,"{")==0) i++;
		else if(strcmp(pTemp->s.sValue,"}")==0) i--;
		/*i==0��ʾƥ������*/
		if(i==0){
			*ppTail=pTemp->pNext;
			pTemp->pNext=NULL;
			return 0;
		}
	}
	strcpy(sMsg,"������ű����");
	return -1;
}

/*
	������,��ȡһ���궨����,�ҵ�һ��\n�ļ������ok��
	1.ptHead �Ǻ궨��Ŀ�ʼ,���������������������;
		�������ڵ��βζ��滻Ϊ 
		iType=TYPE_MODALITY_PARA
		sValue="%d",n
	2.�������Ķ��������� **ppTail��;
*/
int GetMicroBody(struct LSymbolStruct *ptHead,int iCnt,struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[])
{
	int i;
	struct LSymbolStruct *pTemp;

	if(GetSymLine(ptHead,ppTail,sMsg)<0) return -1;
/*���û�к������ֱ��OK*/
	if(iCnt==0) return 0;
/*����о���Ҫ�滻��*/
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
	
		for(i=0;i<iCnt;i++){
			/*���ƥ�����˺��β����滻֮*/
			if(strcmp(pa[i].pSymBgn->s.sValue,
				pTemp->s.sValue)==0){
				pTemp->s.iType=TYPE_MODALITY_PARA;
				sprintf(pTemp->s.sValue,"%d",i);
				break;
			}
		}
	}
	return 0;
}
/**
��չ����书��
	
����::
	AX(x,y,z)
	struct LSymbolStruct *pHead,���е�һ����һ����ʱ��ʶ����������pDef���ҵ�;;
	struct BlockDefStruct *pItem;
���::
	(3*(x)+6+(y)-(z)) �������;;

	1.struct LSymbolStruct *pHead,���е�һ����һ����ʱ��ʶ����������pDef���ҵ�;;
	2.pItem��������ƥ����ϵĺ궨����ṹ;�궨���б�;
	3.ppHead���Ǻ�չ��ʱ���б�;
	4.ppTail�Ǻ�������������λ��;;
	5.�������б���ͷ��ڴ�;;
**/
int DeployMicroStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct *pItem,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,char sMsg[])
{
	int i,iCnt;
	struct ParamDefStruct pa[32];
	struct LSymbolStruct *pBgn,*pEnd,*ptLkHead=NULL,*ptPre,*ptCur;

/*�����PA����ʵ����*/
	if((iCnt=GetHeadListComm(ptHead,ppTail,pa,sMsg))<0) return -1;
/*�����Ҫ�Ͷ����һ��*/
	if(iCnt!=pItem->iParamCnt){
		sprintf(sMsg,"��%s����ʱ����Ϊ%d,����ʱ����Ϊ%d",
			pItem->sName,pItem->iParamCnt,iCnt);
		return -1;
	}

/*�����βκ���չ���б�*/
	ptCur=pItem->pBody;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		/*�����ʶ���Ǻ��β�������ʵʩ�滻*/
		if(ptPre->s.iType==TYPE_MODALITY_PARA){

			i=atoi(ptPre->s.sValue);

			pBgn=pa[i].pSymBgn;
			pEnd=pa[i].pSymEnd;

			do{
				if(AssignLSymHead(&ptLkHead,pBgn)<0){
					strcpy(sMsg,"�����ڴ�ʧ��");
					return -1;
				}
				pBgn=pBgn->pNext;
			}while(pBgn!=pEnd);		
			
		}
		else{
			if(AssignLSymHead(&ptLkHead,ptPre)<0){
				strcpy(sMsg,"�����ڴ�ʧ��");
				return -1;
			}
		}
	}
	
/*���궨�����ͷŵ�,ֻ���������ͷţ���Ϊ�ڴ���pa������*/
	DestroyList((LIST*)ptHead);

	ReverseList((LIST**)&ptLkHead);
	
	AppendListTail((LIST**)ppHead,(LIST*)ptLkHead);
	return 0;
}
/*��һ���б���к�չ��������չ�����׷�ӵ�ָ���б�*/
int DeployMicroList(struct LSymbolStruct *ptHead,struct BlockDefStruct *pDef,
	struct LSymbolStruct **ppHead,char sMsg[])
{
	struct BlockDefStruct *pBlockDef=NULL;
	struct LSymbolStruct *pTemp,*ptPre,*ptCur,*ptLkHead=NULL;
/*	int i=0;*/

	pTemp=ptHead;
	
	while(pTemp!=NULL){
		
/*		printf("%d.\n",i++);*/

		/*������Ǳ�ʶ�������Ǻ���ֱ�ӽ���ʶ��ȡ��ptPre,
		 ��pTempָ����һ����ʶ������ʹptPre->pNext�ÿ�*/
		if(pTemp->s.iType!=TYPE_TEMPVAR||
			SearchBlockDef(pDef,pTemp->s.sValue,&pBlockDef)
			==NOTFOUND){
			ptPre=pTemp;
			pTemp=pTemp->pNext;
			ptPre->pNext=NULL;
		}
		else{
		/*����Ǻ���չ��֮����չ���Ľ������ptPre�����У�����
		�����õ�pTemp�����ͷţ�ͬʱ��pTempΪ������֮����ַ�*/
			ptPre=NULL;
			if(DeployMicroStatement(pTemp,pBlockDef,
				&ptPre,&ptCur,sMsg)<0) return -1;
		/*��չ��ʱ�Ѿ��������ͷ�ͷ���*/
		/*	DestroyList((LIST*)pTemp);*/
			pTemp=ptCur;
		}
		ptCur=ptPre;
		while(ptCur!=NULL){

			ptPre=ptCur;
			ptCur=ptCur->pNext;
			
			InsertList((LIST**)&ptLkHead,(LIST*)ptPre);
		}
	}
	ReverseList((LIST**)&ptLkHead);
/*
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	PrintLSymList(*ppHead);
	printf("yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n");
	PrintLSymList(ptLkHead);
*/
	AppendListTail((LIST**)ppHead,(LIST*)ptLkHead);

	return 0;
}
/*
===
����궨�����;

����: #define AX(x,y,z) (3*(x)+6+(y)-(z)) �����ƶ���;;
���: struct BlockDefStruct ����ṹ��;

::Ԥ����#define��亯��;;
	ptHead #���� #define������ؼ��ֵĶ���;;���ű�;
	ptHead��ͷ�ͺ��岿�ֱ�Ƕ��,pDef��;
	sName  ::��ǰ�����������ظ��ݹ�չ����,һ����ֱ�ӻ��Ӱ����Լ�,
	pDef   ::ϵͳ���������ĺ��б�;���ڶ���չ��;
	p      ::ϵͳ����ĺ�չ���ṹ;;
	ppTail ::�궨��������������..

=====*********Ŀǰδ���Ǻ����Ұ��������������Ұ�������չ��ֱ�ӣ�Ҳ��������;
*/
int PropDefineStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppHead,
	struct LSymbolStruct **ppTail,int iFlag,char sMsg[])
{
	int i;
	struct BlockDefStruct Temp,*pDef;
	struct LSymbolStruct *pTemp=ptHead,*pTail;
	
	if(pTemp==NULL){
		strcpy(sMsg,"���쳣����");
		return -1;
	}

	/*����#define�ַ�*/
	pTemp=pTemp->pNext;
	free(ptHead); /*�ͷ�#define ��ʶ��*/

	/*���ɺ궨���ͷ����ȡ��������*/
	if((Temp.iParamCnt=GetMicroHead(pTemp,&pTail,Temp.pa,sMsg))<0)
		return -1;

	Temp.cType=VARTYPE_UNK;
	Temp.iCodeAddr=-1;

	/*��ȡ����*/
	strcpy(Temp.sName,pTemp->s.sValue);
	Temp.pHead=pTemp;

	/*��������ΪUNK*/
	for(i=0;i<Temp.iParamCnt;i++)Temp.sType[i]=VARTYPE_UNK;
	Temp.sType[i]=0;
	
	/*ָ��ָ��궨����*/
	pTemp=ptHead=pTail;
	
	/*��ȡ�궨����*/
	if(GetMicroBody(pTemp,Temp.iParamCnt,Temp.pa,&pTail,sMsg)<0)
		return -1;
	/*����Ҫ��һ��ѭ����һ����չ��,��������ŵ�ptHead*/
	ptHead=NULL;
	if(DeployMicroList(pTemp,*ppDef,&ptHead,sMsg)<0) return -1;
	
	*ppTail=pTail;
	Temp.pBody=ptHead;
	
	if(iFlag==true){
		if(SearchBlockDef(*ppDef,Temp.sName,&pDef)==FOUND){
			sprintf(sMsg,"��%s�ظ�����",Temp.sName);
			return -1;
		}
	/*���������궨����Ч���������ĺ���ӵ���������*/
		if((pDef=malloc(sizeof(struct BlockDefStruct)))==NULL){
			strcpy(sMsg,"�����ڴ����");
			return -1;
		}
		memcpy((void*)pDef,(void*)&Temp,sizeof(struct BlockDefStruct));
		InsertList((LIST**)ppDef,(LIST*)pDef);
	}	
	return 0;
}

/*��ȫ�ַ��ű���������*/
int MoveSymbolFlowToLSymbolList(struct LSymbolStruct **pptHead)
{
	int i;
	struct LSymbolStruct *ptLkHead=NULL,*pTemp;
	
	for(i=0;i<igSymCnt;i++){
		
		if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL) return -1;
		
		memcpy((void*)&(pTemp->s),&SymbolFlow[i],
			sizeof(struct SymbolStruct));
		InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	ReverseList((LIST**)&ptLkHead);
	*pptHead=ptLkHead;
	igSymPos=igSymCnt=0;
	return 0;
}
/*�������Ƶ�ȫ�ַ��ű����ͷ�����*/
int MoveLSymListToSymbolFlow(struct LSymbolStruct *ptHead)
{
	int i=0;
	struct LSymbolStruct *pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*\r\n���ֶ��������ط��ű�*/
		if(strcmp(pTemp->s.sValue,"\n")==0||
			strcmp(pTemp->s.sValue,"\r")==0) continue;

		memcpy((void*)&SymbolFlow[i],(void*)&(pTemp->s),
			sizeof(struct SymbolStruct));
		if(++i>SYMBOL_BUFLEN) return -1;
	}
	igSymPos=igSymCnt=i;
	return 0;
}
/*��֧��Ԥ���빦�ܵ��ļ��ʷ�����*/
int FileLexicalize(char sFileName[],char sMsg[])
{
	char sInput[EXPRLEN];

	if(IsFile(sFileName)==false){
		sprintf(sMsg,"�ļ� %s ������",sFileName);
		return -1;
	}
	if(FileSize(sFileName)>=EXPRLEN){
		sprintf(sMsg,"�ļ���%s ��С %d,�������ֵ%d",
			sFileName,FileSize(sFileName),EXPRLEN);
		return -1;
	}
	if(ReadFileToBuf(sFileName,EXPRLEN,sInput,sMsg)<0)
		return -1;
	/*��include������ļ����дʷ�����*/
	if(Lexicalize(sInput)<0){
		sprintf(sMsg,"���ļ���%s �ʷ���������",sFileName);
		FormatExprErrorMsg(sInput);
		return -1;
	}
	return 0;
}
void AddDefSymToHead(struct LSymbolStruct **pptHead,struct BlockDefStruct *p)
{
	struct LSymbolStruct *ptHead=NULL,*pTemp,*ptLkHead=NULL;
	
	while(p!=NULL){

		DestroyList((LIST*)p->pHead);
		p->pHead=NULL;
		ptHead=p->pBody;
		p->pBody=NULL;
		
		while(ptHead!=NULL){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
		}
		p=p->pNext;
	}
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		InsertList((LIST**)pptHead,(LIST*)pTemp);
	}
	
	/*�����������õ������޸�ΪTYPE_FUN*/
	ptHead=*pptHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		if(pTemp->s.iType==TYPE_TEMPVAR){

			if(SearchDefFun(pTemp->s.sValue,&p)==FOUND)
				pTemp->s.iType=TYPE_FUN;
		}	
	}
}
int PropLexicalize(char sInput[],char sMsg[])
{
	struct BlockDefStruct *pDef=NULL;
	struct LSymbolStruct *ptHead,*pTail,*pTemp;
	
	/*��ȫ��ջ���*/
	EmptyFileStack();
	
	/*������ַ�����������һ��������ļ���*/
	PushFileStack("[main]");

	/*��include������ļ����дʷ�����*/
	if(Lexicalize(sInput)<0){
		strcpy(sMsg,"�ʷ���������");
		FormatExprErrorMsg(sInput);
		return -1;
	}
	
	/*��SymbolFlow�Ĵʷ������Ľ������ptHead��*/
	if(MoveSymbolFlowToLSymbolList(&ptHead)<0){
		sprintf(sMsg,"�����ڴ� struct LSymbolStruct��ʧ��");
		return -1;
	}
	/*�Ը�����䶼�ô�����һ��ѭ��,����Ԥ�������*/

	pTemp=NULL;
	while(ptHead!=NULL){
		if(PropStatement(ptHead,&pDef,&pTemp,&pTail,true,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	ptHead=pTemp;
	pTemp=NULL;
	/*ɾ���س�����*/
	DeleteLSymListLrn(&ptHead);
	
	pTemp=NULL;
	/*����������Ĳ��ַŵ�pDefFun������*/	
	if(PropFunDefList(ptHead,&pDefFun,&pTemp,sMsg)<0) return -1;

	ptHead=pTemp;
	pTemp=NULL;
	/*��pDefFun�ķ��ű�ӵ�ptHead��ͷ��*/
	ReverseList((LIST**)&pDefFun);
	AddDefSymToHead(&ptHead,pDefFun);
	ReverseList((LIST**)&pDefFun);

	if(MoveLSymListToSymbolFlow(ptHead)<0){
		sprintf(sMsg,"���ű�̫��,���󳤶�%d,֧�ֳ���%d",
			CountList((LIST*)ptHead),SYMBOL_BUFLEN);
		return -1;
	}

/*	PrintLSymList(ptHead);*/

/*	printf("������=%d.\n",CountList((LIST*)ptHead));
*/	
	DestroyList((LIST*)ptHead);
	DestroyBlockDef(pDef);
	
	return 0;

}
int FilePropLexicalize(char sFileName[],char sMsg[])
{
	struct BlockDefStruct *pDef=NULL;
	struct LSymbolStruct *ptHead,*pTail,*pTemp;
	
	/*��ȫ��ջ���*/
	EmptyFileStack();
	
	/*���ʷ��������ļ���ջ*/
	PushFileStack(sFileName);
	
	/*��include������ļ����дʷ�����*/
	if(FileLexicalize(sFileName,sMsg)<0) return -1;
	
	/*��SymbolFlow�Ĵʷ������Ľ������ptHead��*/
	if(MoveSymbolFlowToLSymbolList(&ptHead)<0){
		sprintf(sMsg,"�����ڴ� struct LSymbolStruct��ʧ��");
		return -1;
	}
	/*�Ը�����䶼�ô�����һ��ѭ��,����Ԥ�������*/

	pTemp=NULL;
	while(ptHead!=NULL){		
		if(PropStatement(ptHead,&pDef,&pTemp,&pTail,true,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	if(MoveLSymListToSymbolFlow(pTemp)<0){
		sprintf(sMsg,"���ű�̫��,���󳤶�%d,֧�ֳ���%d",
			CountList((LIST*)pTemp),SYMBOL_BUFLEN);
		return -1;
	}
/*
	PrintLSymList(pTemp);
*/
	DestroyList((LIST*)pTemp);
	DestroyBlockDef(pDef);

	return 0;

}

/*����һ���궨��*/
int SearchBlockDefByAddr(struct BlockDefStruct *ptHead,int iCodeAddr,
	struct BlockDefStruct **pptCur)
{
	*pptCur=NULL;
	while(ptHead!=NULL){
		if(iCodeAddr==ptHead->iCodeAddr){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
/*����һ���Զ�������������*/
int SearchDefFunByAddr(int iCodeAddr,char sName[])
{
	struct BlockDefStruct *pTemp=NULL;
	strcpy(sName,"");
	if(SearchBlockDefByAddr(pDefFun,iCodeAddr,&pTemp)==FOUND){
		strcpy(sName,pTemp->sName);
		return FOUND;
	}
	return NOTFOUND;
}


void DeleteLSymListLrn(struct LSymbolStruct **pptHead)
{
	struct LSymbolStruct *ptHead=(*pptHead),*ptLkHead=NULL,*pTemp;
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(strcmp(pTemp->s.sValue,"\n")==0||
			strcmp(pTemp->s.sValue,"\r")==0) free(pTemp);
		else InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
	}
	ReverseList((LIST**)&ptLkHead);
	*pptHead=ptLkHead;
}
/*�ж�һ������Ƿ�Ϊ�����������,����Ҫ���ǻس����е�����*/
int IsFunDefStatement(struct LSymbolStruct *ptHead,char sName[])
{
	char sTempName[256];

	strcpy(sName,"");

	if(ptHead==NULL) return false;
	if(ptHead->s.iType!=TYPE_DECLARE) return false;
	if((ptHead=ptHead->pNext)==NULL) return false;

	if(ptHead->s.iType!=TYPE_TEMPVAR) return false;
	strcpy(sTempName,ptHead->s.sValue);
	if((ptHead=ptHead->pNext)==NULL) return false;

	if(strcmp(ptHead->s.sValue,"(")!=0) return false;

	strcpy(sName,sTempName);
	return true;
}
int GetFunParamType(struct LSymbolStruct *pTemp,char sName[],
	int i,char *pcType,char sMsg[])
{
	char sSubItem[100];

	if(i==-1) strcpy(sSubItem,"����ֵ����");
	else	  sprintf(sSubItem,"��%d����������",i);

	if(pTemp->s.iType!=TYPE_DECLARE||
		pTemp->pNext->s.iType!=TYPE_TEMPVAR){
		sprintf(sMsg,"����%s��%s,ӦΪtype tmpvar",
			sName,sSubItem);
		return -1;
	}
	if(strcmp(pTemp->s.sValue,"int")==0)		*pcType='1';
	else if(strcmp(pTemp->s.sValue,"string")==0)	*pcType='2';
	else if(strcmp(pTemp->s.sValue,"double")==0)	*pcType='5';
	else if(strcmp(pTemp->s.sValue,"struct")==0)	*pcType='4';
	else if(strcmp(pTemp->s.sValue,"pointer")==0)	*pcType='3';
	else{
		sprintf(sMsg,"����%s��%s����%s����",
			sName,sSubItem,pTemp->s.sValue);
		return -1;
	}
	return 0;
}
/*==============*/
/*��ȡһ�������ļ�ͷ����*/
int GetFunDefHead(struct LSymbolStruct *ptHead,struct LSymbolStruct **ppTail,
	char sName[],char *pcType,char sType[],
	struct ParamDefStruct pa[],char sMsg[])
{
	int iParamCnt,i,j;
	struct LSymbolStruct *pTemp;

	strcpy(sMsg,"");

	if(IsFunDefStatement(ptHead,sName)==false){
		strcpy(sMsg,"�����㺯����������");
		return -1;
	}
	if(GetFunParamType(ptHead,sName,-1,pcType,sMsg)<0) return -1;

	if((iParamCnt=GetHeadListComm(ptHead->pNext,ppTail,pa,sMsg))<0) return -1;

	for(i=0;i<iParamCnt;i++){
		j=0;
		pTemp=pa[i].pSymBgn;
		while(pTemp!=NULL){
			if(pTemp==pa[i].pSymEnd||j>100) break;
			j++;
			pTemp=pTemp->pNext;
		}
		if(j!=2){
			sprintf(sMsg,"����%s�ĵ�%d�����������������",
				sName,i);
			return -1;
		}
		/*��ȡ����������*/
		if(GetFunParamType(pa[i].pSymBgn,sName,i,&sType[i],sMsg)<0)
			return -1;
	}
	sType[i]=0;
	return i;
}
/*��ȡһ�������嶨��*/
/*
	������,��ȡһ�����������壬���ֱ������;��ʾ��һ������ͷ����;
	1.ptHead �Ǻ�����Ŀ�ʼ,�����������������������;
		���������ڵ��βζ��滻Ϊ 
		iType=TYPE_MODALITY_PARA
		sValue="%d",n
	2.���������Ķ��������� **ppTail��;
*/
int GetFunDefBody(struct LSymbolStruct *ptHead,char sName[],
	int iCnt,char sType[],struct ParamDefStruct pa[],
	struct LSymbolStruct **ppTail,char sMsg[])
{
	int i;
	struct LSymbolStruct *pTemp;

	strcpy(sMsg,"");

	if(ptHead==NULL){
		sprintf(sMsg,"����%s�������",sName);
		return -1;
	}
	/*�������һ��ͷ�ļ���ֱ��OK*/
	if(strcmp(ptHead->s.sValue,";")==0){
		*ppTail=ptHead->pNext;
		ptHead->pNext=NULL;
		return 0;
	}
	/*��ȡһ������������*/
	if(GetSymBlock(ptHead,ppTail,sMsg)<0) return -1;
	
/*����о���Ҫ�滻��*/
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
	
		for(i=0;i<iCnt;i++){
			/*���ƥ�����˺����β����滻֮*/
			if(strcmp(pa[i].pSymBgn->pNext->s.sValue,
				pTemp->s.sValue)==0){

				pTemp->s.iType=TYPE_MODALITY_PARA;
				/*�����ӡ����ʽ������*/
				sprintf(pTemp->s.sValue,"%d",i);
				break;
			}
		}
	}

	return 0;
}
/*����һ������������*/
int PropFunDefStatement(struct LSymbolStruct *ptHead,
	struct BlockDefStruct **ppDef,struct LSymbolStruct **ppTail,
	char sMsg[])
{
	struct BlockDefStruct Temp,*pDef;
	struct LSymbolStruct *pTemp=ptHead,*pTail;
	
	if(pTemp==NULL){
		strcpy(sMsg,"�����쳣����");
		return -1;
	}

	/*���ɺ��������ͷ����ȡ��������*/
	if((Temp.iParamCnt=GetFunDefHead(pTemp,&pTail,Temp.sName,
		&Temp.cType,Temp.sType,Temp.pa,sMsg))<0)
		return -1;
	Temp.pHead=pTemp;
	
	/*ָ��ָ��궨����*/
	pTemp=ptHead=pTail;
	
	/*��ȡ�궨����*/
	if(GetFunDefBody(pTemp,Temp.sName,Temp.iParamCnt,Temp.sType,
		Temp.pa,&pTail,sMsg)<0)	return -1;

	/*����δ����״̬*/
	Temp.iCodeAddr=-1;

	*ppTail=pTail;
	/*�������һ��������ͷ���򽫺����;����*/
	if(pTemp->pNext==NULL){
		Temp.pBody=NULL;
		free(pTemp);
	}
	else{
		/*��������֮ǰ���롡NAME + TYPE=TYPE_FUN�ĺ���*/
		Temp.pBody=pTemp;
		if((pTemp=malloc(sizeof(struct LSymbolStruct)))==NULL){
			sprintf(sMsg,"�����ڴ�LSymbolStruct����");
			return -1;
		}
		bzero((void*)pTemp,sizeof(struct LSymbolStruct));
		strcpy(pTemp->s.sValue,Temp.sName);
		pTemp->s.iType=TYPE_FUN;
		pTemp->s.iOriPos=Temp.pHead->s.iOriPos;
		InsertList((LIST**)&Temp.pBody,(LIST*)pTemp);
	}

	/*���û�ҵ�����*/
	if(SearchBlockDef(*ppDef,Temp.sName,&pDef)==NOTFOUND){
		if((pDef=malloc(sizeof(struct BlockDefStruct)))==NULL){
			strcpy(sMsg,"�����ڴ����");
			return -1;
		}
		memcpy((void*)pDef,(void*)&Temp,sizeof(struct BlockDefStruct));
		InsertList((LIST**)ppDef,(LIST*)pDef);
		return 0;
	}
	/*�������������ƥ���򷵻ش���*/
	if(BlockParamMatch(&Temp,pDef,sMsg)<0) return -1;
	
	/*��������Ĵʷ��������ָ��λ��*/
	DestroyList((LIST*)Temp.pHead);
	pDef->pBody=Temp.pBody;
	
	return 0;
}

int BlockParamMatch(struct BlockDefStruct *p1,struct BlockDefStruct *p2,
	char sMsg[])
{
	int i;

	strcpy(sMsg,"");

	if(p1->iParamCnt!=p2->iParamCnt){
		sprintf(sMsg,"����%s���������������������ƥ��%d,%d",
			p1->sName,p1->iParamCnt,p2->iParamCnt);
		return -1;
	}
	if(p1->cType!=p2->cType){
		sprintf(sMsg,"����%s�����������巵��ֵ��ƥ��%c,%c",
			p1->sName,p1->cType,p2->cType);
		return -1;
	}

	for(i=0;i<p1->iParamCnt;i++){
		if(p1->sType[i]!=p2->sType[i]){
			sprintf(sMsg,"����%s�������������%d�������Ͳ�ƥ��%c,%c",
				p1->sName,i,p1->sType[i],p2->sType[i]);
			return -1;
		}
	}
	if(p2->pBody!=NULL&&p1->pBody!=NULL){
		sprintf(sMsg,"����%s������������",p1->sName);
		return -1;
	}

	return 0;
}
int SearchDefFun(char sSymbol[],struct BlockDefStruct **pptCur)
{
	return SearchBlockDef(pDefFun,sSymbol,pptCur);
}

int PropFunDefList(struct LSymbolStruct *ptHead,struct BlockDefStruct **ppDef,
	struct LSymbolStruct **ppHead,char sMsg[])
{
	char sName[128];
	struct LSymbolStruct *pTemp,*ptLkHead=NULL,*pTail=NULL;
	
	strcpy(sMsg,"");

	while(ptHead!=NULL){
		if(IsFunDefStatement(ptHead,sName)==false){
			pTemp=ptHead;
			ptHead=ptHead->pNext;
			InsertList((LIST**)&ptLkHead,(LIST*)pTemp);
			continue;
		}
		pTail=NULL;
		if(PropFunDefStatement(ptHead,ppDef,&pTail,sMsg)<0)
			return -1;
		ptHead=pTail;
	}
	ReverseList((LIST**)&ptLkHead);

	*ppHead=ptLkHead;
	return 0;
}

