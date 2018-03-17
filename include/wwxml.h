#ifndef __WWXML_H__
#define __WWXML_H__

#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <list.h>
#include <wwtiny.h>
#include <wwfile.h>

struct XmlHeadStruct
{
	char sVersion[10];
	char sEncoding[64];
};
struct XmlDocStruct
{
	struct XmlHeadStruct Head;
	struct XmlElementStruct *pElement;
};
struct XmlElementStruct
{
#define MAX_XML_TAG_LEN		64
#define MAX_XML_VALUE_LEN	128
	struct XmlElementStruct *pNext;
	struct XmlElementStruct *pChild;
	char sTag[MAX_XML_TAG_LEN];
	char sValue[MAX_XML_VALUE_LEN];
	char sOriTag[MAX_XML_TAG_LEN];
	char sOriValue[MAX_XML_VALUE_LEN];
};
void FreeXmlDoc(struct XmlDocStruct *ptHead);
void FreeXmlElement(struct XmlElementStruct *pTemp);
int PrintSimpleXmlElement(struct XmlElementStruct *pElement,char sXml[]);
int PrintXmlElement(struct XmlElementStruct *pElement,char sXml[]);
void PrintXmlDoc(struct XmlDocStruct *pRoot,char sXml[]);

struct XmlDocStruct *GetXmlDoc(char sXml[],char msg[]);
void PrintXmlDoc(struct XmlDocStruct *pRoot,char sXml[]);
struct	XmlTagStruct
{
	struct	XmlTagStruct *pNext;
	char	sTag[MAX_XML_TAG_LEN];
};
struct XmlTagStruct *CompileXmlOff(char sTag[]);

int SearchXmlElement(struct XmlElementStruct *ptHead,char sTag[],
	struct XmlElementStruct **pptCur);
void GetXmlCont(struct XmlDocStruct *pDoc,struct XmlTagStruct *pXmlTag,
	char sCont[]);
int HasXmlCont(struct XmlDocStruct *pDoc,struct XmlTagStruct *pXmlTag);


#endif
