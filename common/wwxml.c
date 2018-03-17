#include <stdio.h>
#include <stdlib.h>

#include <wwxml.h>

static int NewLine(char c)
{
        if(c=='\n'||c=='\r') return true;
        return false;
}
static int JmpSeperator(char c)
{
        if(c==' '||c=='\t') return true;
        return false;
}
#define JMP_BLANK(p)	\
	while(NewLine(*(p))||JmpSeperator(*(p))){ \
		if(*(p)==0) break;\
		p++;\
	}
static int TagEquals(char sBgnTag[],char sEndTag[])
{
	if(sEndTag[0]=='/'&&
		strcmp(sBgnTag,sEndTag+1)==0) return true;
	return false;
}
int InitXmlHead(char sHead[],struct XmlHeadStruct *po,char msg[])
{
	strcpy(po->sVersion,"1.0");
	strcpy(po->sEncoding,"utf-8");

	return 0;
}
int GetXmlTag(char sElement[],char sTag[],int *piPos,char msg[])
{
	char *p,*pb;

	strcpy(sTag,"");
	strcpy(msg,"");
	*piPos=0;

	if(sElement[0]!='<'){
		strcpy(msg,"��ǩ������<��ͷ");
		return -1;
	}
	p=sElement+1;

	/*������ǩ��ʼ�ļ����*/
	while(JmpSeperator(*p)){
		if((*p)==0){
			strcpy(msg,"��ȡ��ǩ�������");
			*piPos=p-sElement;
			return -1;
		}
		p++;
	}
	pb=p;

	while(!NewLine(*p)){
		if((*p)==0){
			strcpy(msg,"��ȡ��ǩ�������");
			*piPos=p-sElement;
			return -1;
		}
		/*�ﵽ��ǩβ��*/
		if((*p)=='>') break;
		p++;
	}
	/*��ʾ,�ﵽ��ǩβ��*/
	if((*p)!='>'){
		strcpy(msg,"��ȡ��ǩ�������,δ����>��");
		*piPos=p-sElement;
		return -1;
	}
	if(p-pb>=MAX_XML_TAG_LEN){
		sprintf(msg,"��ǩ����%dλ������",MAX_XML_TAG_LEN-1);
		*piPos=p-sElement;
		return -1;
	}
	strncpy(sTag,pb,p-pb);sTag[p-pb]=0;
	ReplaceStr(sTag," ","");
	ReplaceStr(sTag,"\t","");

	*piPos=p+1-sElement;

	/*�����"/>"�����ʾ�޶���������ǩ*/
	if(*(p-1)=='/'){
		/*ȥ��'/'��*/
		sTag[p-pb-1]=0;
		return 1;
	}
	/*����ǿ�ʼ��ǩ����ע�ʹ���*/
	if(sTag[0]!='/') return 0;

	/*ɾ����ǩ�󣬵ĵ�����ע��*/
	p=sElement+*piPos;

	/*�����հ׵�*/
	JMP_BLANK(p);
	/*�������ע�Ϳ�ʼ*/
	if((*p)=='\''){

		char *p1,*p2;

		p1=strchr(p,'\n');
		p2=strchr(p,'<');

		if(p1==NULL&&p2==NULL){
			sprintf(msg,"ɾ��ע�ʹ���,û����\\n��<ע�ͽ�����");
			*piPos=p-sElement;
			return -1;
		}
		/*��������գ���ȡСһ��*/
		if(p1!=NULL&&p2!=NULL)
			p=p1>p2?p2:p1;
		else if(p1==NULL) p=p2;
		else p=p1;
	}
	*piPos=p-sElement;

	return 0;
}
int InitSimpleElement(char sElement[],struct XmlElementStruct *po,int *piPos,
	char msg[])
{
	int iPos=0;
	char *p,*pb,sBgnTag[MAX_XML_TAG_LEN],sEndTag[MAX_XML_TAG_LEN];

	strcpy(msg,"");

	bzero((void*)po,sizeof(struct XmlElementStruct));

	if(GetXmlTag(sElement,sBgnTag,piPos,msg)<0) return -1;

	p=sElement+(*piPos);

	/*�����հ׵�*/
	JMP_BLANK(p);

	if((*p)=='<'){
		if(GetXmlTag(sElement,sEndTag,piPos,msg)<0) return -1;

		if(TagEquals(sBgnTag,sEndTag)) return 0;

		/*����һ����tag����-1*/
		return 1;
	}

	pb=p;
	/*��������*/
	while((*p)!='<'){
		if((*p)==0){
			sprintf(msg,"��ȡ��ǩ%s�������������",sBgnTag);
			*piPos=p-sElement;
			return -1;
		}
		p++;
	}
	/*�����Ȼ*pΪ'<'*/
	if((p-pb)>=MAX_XML_VALUE_LEN){
		sprintf(msg,"���ױ�ǩ%s�����ݴ���%dλ������",
			sBgnTag,MAX_XML_VALUE_LEN);
		*piPos=p-sElement;
		return -1;
	}
	if(GetXmlTag(p,sEndTag,&iPos,msg)<0){
		(*piPos)=p-sElement+iPos;
		return -1;
	}
	/*����Ǳ�ǩ���������ְ����ӱ�ǩ�����*/
	if(sEndTag[0]!='/'){
		*piPos=0;
		return 1;

	}

	if(!TagEquals(sBgnTag,sEndTag)){
		(*piPos)=p-sElement+iPos;
		sprintf(msg,"��ǩ%s�ͱ�ǩ%s����Ӧ",sBgnTag,sEndTag);
		return -1;
	}

	strcpy(po->sTag,sBgnTag);
	strncpy(po->sValue,pb,p-pb);po->sValue[p-pb]=0;
	TrimAll(po->sValue);

	/*������ǩ��'<'����*/
	*piPos=p-sElement+iPos;
	return 0;
}
struct XmlElementStruct *GetSimpleXmlElement(char sElement[],int *piPos,char msg[])
{
	struct XmlElementStruct Temp,*pTemp;

	if(InitSimpleElement(sElement,&Temp,piPos,msg)!=0) return NULL;

	if((pTemp=malloc(sizeof(struct XmlElementStruct)))==NULL){
		sprintf(msg,"malloc error");
		return NULL;
	}
	memcpy((void*)pTemp,(void*)&Temp,sizeof(struct XmlElementStruct));

	return pTemp;
}
void InsertXmlElementChild(struct XmlElementStruct *ptHead,
	struct XmlElementStruct *pTemp)
{
	AppendListTail((LIST**)&(ptHead->pChild),(LIST*)pTemp);
}
struct XmlElementStruct *GetXmlElement(char sElement[],int *piPos,char msg[])
{
	int iRet=0,iPos=0,dPos=0;
	char *p,*pb,sBgnTag[MAX_XML_TAG_LEN],sEndTag[MAX_XML_TAG_LEN];

	struct XmlElementStruct Temp,*pTemp,*ptHead=NULL;

	iRet=InitSimpleElement(sElement,&Temp,piPos,msg);

	if(iRet<0) return NULL;

	if(iRet==0) return GetSimpleXmlElement(sElement,piPos,msg);

	/*�����һ�����ӵ�xml����*/
	if((ptHead=malloc(sizeof(struct XmlElementStruct)))==NULL){
		sprintf(msg,"malloc head error");
		return NULL;
	}
	bzero((void*)ptHead,sizeof(struct XmlElementStruct));

	if(GetXmlTag(sElement,sBgnTag,&iPos,msg)<0){
		*piPos=iPos;
		return NULL;
	}

	strcpy(ptHead->sTag,sBgnTag);

	pb=p=sElement+iPos;
	/*�����հ׵�*/
	JMP_BLANK(p);
	/*��������*/
	while((*p)!='<'){
		if((*p)==0){
			sprintf(msg,"��ȡ��ǩ%s�������������",sBgnTag);
			*piPos=p-sElement;
			return NULL;
		}
		p++;
	}
	/*�����Ȼ*pΪ'<'*/
	if((p-pb)>=MAX_XML_VALUE_LEN){
		sprintf(msg,"���ױ�ǩ%s�����ݴ���%dλ������",
			sBgnTag,MAX_XML_VALUE_LEN);
		*piPos=p-sElement;
		return NULL;
	}

	strncpy(ptHead->sValue,pb,p-pb);ptHead->sValue[p-pb]=0;
	TrimAll(ptHead->sValue);

	iPos=p-sElement;

	while(1){

		p=sElement+iPos;
		/*�����հ׵�*/
		JMP_BLANK(p);
		iPos=p-sElement;

		if(GetXmlTag(sElement+iPos,sEndTag,&dPos,msg)<0){
			*piPos=iPos+dPos;
			return NULL;
		}
		if(TagEquals(sBgnTag,sEndTag)) break;

		if((pTemp=GetXmlElement(sElement+iPos,&dPos,msg))==NULL){
			FreeXmlElement(ptHead);
			*piPos=iPos+dPos;
			return NULL;
		}

		InsertXmlElementChild(ptHead,pTemp);

		iPos+=dPos;
	}

	iPos+=dPos;

	p=sElement+iPos;
	/*�����հ׵�*/
	JMP_BLANK(p);

	*piPos=p-sElement;

	return ptHead;
}
struct XmlDocStruct *GetXmlDoc(char sXml[],char msg[])
{
	int iPos=0;
	char *pc,sHead[1024],sTemp[10];
	struct XmlDocStruct *ptHead=NULL;


	strcpy(msg,"");

	if(strncmp(sXml,"<?xml",5)!=0){
		strncpy(sTemp,sXml,5);sTemp[5]=0;
		sprintf(msg,"xml�ļ�������,<?xml��ͷ,ʵ�ʿ�ͷΪ:%s",sTemp);
		return NULL;
	}
	if((pc=strstr(sXml+5,"?>"))==NULL){
		sprintf(msg,"�Ҳ���xml�ļ�ͷ��,?>����");
		return NULL;
	}
	if((pc-sXml)>=1024){
		sprintf(msg,"xml���ļ�ͷ̫������1024");
		return NULL;
	}
	strncpy(sHead,sXml,pc+2-sXml);sHead[pc+2-sXml]=0;

	if((ptHead=malloc(sizeof(struct XmlDocStruct)))==NULL){
		sprintf(msg,"�����ڴ�XmlDocStruct����");
		return NULL;
	}

	/*����ļ�ͷ��ʼ���������*/
	if(InitXmlHead(sHead,&(ptHead->Head),msg)<0) return NULL;

	pc+=2;/*����"?>"*/

	/*�����հ׵�*/
	JMP_BLANK(pc);

	if(*pc==0){
		sprintf(msg,"xml���ĵ�û����,����һ��ͷ��");
		return NULL;
	}
	if(*pc!='<'){
		sprintf(msg,"xml���ĵ��ļ��������<��ͷ");
		return NULL;
	}

	if((ptHead->pElement=GetXmlElement(pc,&iPos,msg))==NULL){
		free(ptHead);
		sprintf(msg+strlen(msg),"::����λ��%d,%s",pc-sXml+iPos,pc+iPos);
		return NULL;
	}
	return ptHead;
}

void FreeXmlElement(struct XmlElementStruct *pTemp)
{
	if(pTemp!=NULL){
		if(pTemp->pNext!=NULL) FreeXmlElement(pTemp->pNext);
		if(pTemp->pChild!=NULL)FreeXmlElement(pTemp->pChild);
		free(pTemp);
	}
}
void FreeXmlDoc(struct XmlDocStruct *ptHead)
{

	if(ptHead!=NULL){
		if(ptHead->pElement!=NULL) FreeXmlElement(ptHead->pElement);
		free(ptHead);
	}
}
int PrintSimpleXmlElement(struct XmlElementStruct *pElement,char sXml[])
{
	int l=0;

	struct XmlElementStruct *ptHead,*pTemp;

	l+=sprintf(sXml+l,"\n<%s>",pElement->sTag);

	if(strlen(pElement->sValue)!=0);
		l+=sprintf(sXml+l,"%s",pElement->sValue);

	ptHead=pElement->pChild;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pChild;

		l+=PrintXmlElement(pTemp,sXml+l);
	}
	l+=sprintf(sXml+l,"</%s>",pElement->sTag);
	return l;
}
int PrintXmlElement(struct XmlElementStruct *pElement,char sXml[])
{
	int l=0;

	struct XmlElementStruct *ptHead,*pTemp;

	ptHead=pElement;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		l+=PrintSimpleXmlElement(pTemp,sXml+l);
	}
	return l;
}
void PrintXmlDoc(struct XmlDocStruct *pRoot,char sXml[])
{
	int l=0;

	l=sprintf(sXml,"<?xml version=\"1.0\" encoding=\"utf-8\"?>");

	PrintXmlElement(pRoot->pElement,sXml+l);

	printf("%s",sXml);
}
struct XmlTagStruct *CompileXmlOff(char sTag[])
{
	char *c,*t,sTemp[64];
	struct XmlTagStruct *pTemp,*ptHead=NULL;

	t=sTag;

	while(1){

		c=strchr(t,':');

		if(c!=NULL){
			strncpy(sTemp,t,c-t);
			sTemp[c-t]=0;
		}
		else
			strcpy(sTemp,t);

		if((pTemp=(struct XmlTagStruct*)malloc(
			sizeof(struct XmlTagStruct)))==NULL)return NULL;

		strcpy(pTemp->sTag,sTemp);
		pTemp->pNext=NULL;

		InsertList((LIST**)&ptHead,(LIST*)pTemp);

		if(c==NULL) break;

		t=c+1;/*����':'*/
	}

	ReverseList((LIST**)&ptHead);

	return ptHead;
}
int SearchXmlElement(struct XmlElementStruct *ptHead,char sTag[],
	struct XmlElementStruct **pptCur)
{
	*pptCur=NULL;

	while(ptHead!=NULL){
		if(strcmp(sTag,ptHead->sTag)==0){
			*pptCur=ptHead;
			return FOUND;
		}
		ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}
void GetXmlCont(struct XmlDocStruct *pDoc,struct XmlTagStruct *pXmlTag,
	char sCont[])
{
	struct XmlTagStruct *ptCur,*ptPre;
	struct XmlElementStruct *ptHead=pDoc->pElement,*pTemp;


	strcpy(sCont,"");

	ptCur=pXmlTag;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(SearchXmlElement(ptHead,ptPre->sTag,&pTemp)==NOTFOUND)
			break;

		/*˵�����в�εĶ�ƥ������*/
		if(ptCur==NULL){
			strcpy(sCont,pTemp->sValue);
			break;
		}

		ptHead=pTemp->pChild;
	}
}
int HasXmlCont(struct XmlDocStruct *pDoc,struct XmlTagStruct *pXmlTag)
{
	struct XmlTagStruct *ptCur,*ptPre;
	struct XmlElementStruct *ptHead=pDoc->pElement,*pTemp;

	ptCur=pXmlTag;

	while(ptCur!=NULL){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		if(SearchXmlElement(ptHead,ptPre->sTag,&pTemp)==NOTFOUND)
			return false;

		ptHead=pTemp->pChild;
	}
	return true;
}
