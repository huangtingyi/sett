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
		strcpy(msg,"标签必须以<开头");
		return -1;
	}
	p=sElement+1;

	/*跳过标签开始的间隔符*/
	while(JmpSeperator(*p)){
		if((*p)==0){
			strcpy(msg,"获取标签意外结束");
			*piPos=p-sElement;
			return -1;
		}
		p++;
	}
	pb=p;

	while(!NewLine(*p)){
		if((*p)==0){
			strcpy(msg,"获取标签意外结束");
			*piPos=p-sElement;
			return -1;
		}
		/*达到标签尾部*/
		if((*p)=='>') break;
		p++;
	}
	/*表示,达到标签尾部*/
	if((*p)!='>'){
		strcpy(msg,"获取标签意外结束,未遇到>符");
		*piPos=p-sElement;
		return -1;
	}
	if(p-pb>=MAX_XML_TAG_LEN){
		sprintf(msg,"标签大于%d位，超长",MAX_XML_TAG_LEN-1);
		*piPos=p-sElement;
		return -1;
	}
	strncpy(sTag,pb,p-pb);sTag[p-pb]=0;
	ReplaceStr(sTag," ","");
	ReplaceStr(sTag,"\t","");

	*piPos=p+1-sElement;

	/*如果是"/>"，则表示无独立结束标签*/
	if(*(p-1)=='/'){
		/*去掉'/'符*/
		sTag[p-pb-1]=0;
		return 1;
	}
	/*如果是开始标签不做注释处理*/
	if(sTag[0]!='/') return 0;

	/*删除标签后，的单引号注释*/
	p=sElement+*piPos;

	/*跳过空白的*/
	JMP_BLANK(p);
	/*如果发现注释开始*/
	if((*p)=='\''){

		char *p1,*p2;

		p1=strchr(p,'\n');
		p2=strchr(p,'<');

		if(p1==NULL&&p2==NULL){
			sprintf(msg,"删除注释错误,没发现\\n或<注释结束符");
			*piPos=p-sElement;
			return -1;
		}
		/*如果都不空，则取小一个*/
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

	/*跳过空白的*/
	JMP_BLANK(p);

	if((*p)=='<'){
		if(GetXmlTag(sElement,sEndTag,piPos,msg)<0) return -1;

		if(TagEquals(sBgnTag,sEndTag)) return 0;

		/*遇到一个子tag返回-1*/
		return 1;
	}

	pb=p;
	/*跳过内容*/
	while((*p)!='<'){
		if((*p)==0){
			sprintf(msg,"获取标签%s的内容意外结束",sBgnTag);
			*piPos=p-sElement;
			return -1;
		}
		p++;
	}
	/*这里必然*p为'<'*/
	if((p-pb)>=MAX_XML_VALUE_LEN){
		sprintf(msg,"简易标签%s的内容大于%d位，超长",
			sBgnTag,MAX_XML_VALUE_LEN);
		*piPos=p-sElement;
		return -1;
	}
	if(GetXmlTag(p,sEndTag,&iPos,msg)<0){
		(*piPos)=p-sElement+iPos;
		return -1;
	}
	/*如果是标签中有内容又包含子标签的情况*/
	if(sEndTag[0]!='/'){
		*piPos=0;
		return 1;

	}

	if(!TagEquals(sBgnTag,sEndTag)){
		(*piPos)=p-sElement+iPos;
		sprintf(msg,"标签%s和标签%s不对应",sBgnTag,sEndTag);
		return -1;
	}

	strcpy(po->sTag,sBgnTag);
	strncpy(po->sValue,pb,p-pb);po->sValue[p-pb]=0;
	TrimAll(po->sValue);

	/*跳过标签的'<'符号*/
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

	/*如果是一个复杂的xml内容*/
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
	/*跳过空白的*/
	JMP_BLANK(p);
	/*跳过内容*/
	while((*p)!='<'){
		if((*p)==0){
			sprintf(msg,"获取标签%s的内容意外结束",sBgnTag);
			*piPos=p-sElement;
			return NULL;
		}
		p++;
	}
	/*这里必然*p为'<'*/
	if((p-pb)>=MAX_XML_VALUE_LEN){
		sprintf(msg,"简易标签%s的内容大于%d位，超长",
			sBgnTag,MAX_XML_VALUE_LEN);
		*piPos=p-sElement;
		return NULL;
	}

	strncpy(ptHead->sValue,pb,p-pb);ptHead->sValue[p-pb]=0;
	TrimAll(ptHead->sValue);

	iPos=p-sElement;

	while(1){

		p=sElement+iPos;
		/*跳过空白的*/
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
	/*跳过空白的*/
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
		sprintf(msg,"xml文件必须以,<?xml开头,实际开头为:%s",sTemp);
		return NULL;
	}
	if((pc=strstr(sXml+5,"?>"))==NULL){
		sprintf(msg,"找不到xml文件头的,?>结束");
		return NULL;
	}
	if((pc-sXml)>=1024){
		sprintf(msg,"xml的文件头太长大于1024");
		return NULL;
	}
	strncpy(sHead,sXml,pc+2-sXml);sHead[pc+2-sXml]=0;

	if((ptHead=malloc(sizeof(struct XmlDocStruct)))==NULL){
		sprintf(msg,"分配内存XmlDocStruct错误");
		return NULL;
	}

	/*如果文件头初始化错则继续*/
	if(InitXmlHead(sHead,&(ptHead->Head),msg)<0) return NULL;

	pc+=2;/*跳过"?>"*/

	/*跳过空白的*/
	JMP_BLANK(pc);

	if(*pc==0){
		sprintf(msg,"xml的文档没内容,仅有一个头部");
		return NULL;
	}
	if(*pc!='<'){
		sprintf(msg,"xml的文档文件体必须以<开头");
		return NULL;
	}

	if((ptHead->pElement=GetXmlElement(pc,&iPos,msg))==NULL){
		free(ptHead);
		sprintf(msg+strlen(msg),"::错误位置%d,%s",pc-sXml+iPos,pc+iPos);
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

		t=c+1;/*跳过':'*/
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

		/*说明所有层次的都匹配上了*/
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
