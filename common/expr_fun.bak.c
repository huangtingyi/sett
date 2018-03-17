
#include <hnixs.h>
#include <wwlog.h>
#include <wwcoding.h>
#include <wwtiny.h>
#include <list.h>
#include <wwfile.h>
#include <expr.h>
#include <expr_supp.h>
#include <expr_var.h>
#include <expr_fun.h>

char	sFileDataDate[15];

int i_initdate(int d1,int r)
{
	char sHostDate[15];
	int i=CODE_VARBUF[d1].u.iValue;
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=0;
	
	GetHostTime(sHostDate);
	AddDates(sHostDate,-i);
	strcpy(sFileDataDate,sHostDate);
	
	return 0;
}
int i_maxdatadate(int d1,int r)
{
	char sTempDate[15];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].u.iValue=0;
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	strncpy(sTempDate,p1,8);
	strcpy(sTempDate+8,"000000");
	
	if(tGetTime(sTempDate)<0){
		CODE_VARBUF[r].u.iValue=-1;
		return 0;
	}
	if(strcmp(sTempDate,sFileDataDate)>0)
		strcpy(sFileDataDate,sTempDate);
	
	return 0;
}
int i_getasnpos(int d1, int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);
	int	iRet;
	struct PositionStruct Temp;
	
	CODE_VARBUF[r].cType=VARTYPE_STRUCT; /*结构体*/
	iRet=GET_ASN_POS(p1,p11,(struct PositionStruct *)&Temp);

	if(AssignMemchar2Varchar(&(CODE_VARBUF[r].u.sValue),
		(char*)&Temp,sizeof(struct PositionStruct))<0) return -1;
	return iRet;
}
int i_asnp(int d1, int r)
{
	struct AsnStruct *pAsn;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pAsn=CompileAsnOff(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pAsn;

	return 0;
}

int i_getfixpos(int d1, int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);

	int	iRet;
	struct PositionStruct Temp;

	CODE_VARBUF[r].cType=VARTYPE_STRUCT; /*结构体*/
	iRet=GET_FIX_POS(p1,p11,(struct PositionStruct *)&Temp);

	if(AssignMemchar2Varchar(&(CODE_VARBUF[r].u.sValue),
		(char*)&Temp,sizeof(struct PositionStruct))<0) return -1;
	return iRet;
}
int i_fixp(int d1, int r)
{
	struct ParamStruct *pParam;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pParam=CompileFixOff(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pParam;

	return 0;
}

int i_gettabpos(int d1, int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);

	int	iRet;
	struct PositionStruct Temp;

	CODE_VARBUF[r].cType=VARTYPE_STRUCT; /*结构体*/
	iRet=GET_TAB_POS(p1,p11,(struct PositionStruct *)&Temp);
	if(AssignMemchar2Varchar(&(CODE_VARBUF[r].u.sValue),
		(char*)&Temp,sizeof(struct PositionStruct))<0) return -1;
	return iRet;
}
int i_tabp(int d1, int r)
{
	struct ParamStruct *pParam;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pParam=CompileTabOff(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pParam;

	return 0;
}


int i_getseppos(int d1, int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);

	int	iRet;
	struct PositionStruct Temp;

	CODE_VARBUF[r].cType=VARTYPE_STRUCT; /*结构体*/
	iRet=GET_SEP_POS(p1,p11,(struct PositionStruct *)&Temp);

	if(AssignMemchar2Varchar(&(CODE_VARBUF[r].u.sValue),
		(char*)&Temp,sizeof(struct PositionStruct))<0) return -1;
	return iRet;
}
int i_sepp(int d1, int r)
{
	struct ParamStruct *pParam;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pParam=CompileSepOff(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pParam;

	return 0;
}

int I_TBCD_INT4B(int d1,int r)
{
	struct PositionStruct *p11;
	
	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	if(p11->iOffset==-1){CODE_VARBUF[r].u.iValue=-1;return 0;}

	return TBCD_INT4B(p11->pData+p11->iOffset,p11->iLen,
		(void*)&(CODE_VARBUF[r].u.iValue));
}
int I_HEX_TBCD_INT4B(int d1,int r)
{
	struct PositionStruct *p11;
	
	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	if(p11->iOffset==-1){CODE_VARBUF[r].u.iValue=-1;return 0;}

	return HEX_TBCD_INT4B(p11->pData+p11->iOffset,p11->iLen,
		(void*)&(CODE_VARBUF[r].u.iValue));
}
int I_OCTET_INT4B(int d1,int r)
{
	struct PositionStruct *p11;
	
	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	if(p11->iOffset==-1){CODE_VARBUF[r].u.iValue=-1;return 0;}

	return OCTET_INT4B(p11->pData+p11->iOffset,p11->iLen,
		(void*)&(CODE_VARBUF[r].u.iValue));
}
int I_HEX_OCTET_INT4B(int d1,int r)
{
	struct PositionStruct *p11;
	
	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	if(p11->iOffset==-1){CODE_VARBUF[r].u.iValue=-1;return 0;}
	
	return HEX_OCTET_INT4B(p11->pData+p11->iOffset,p11->iLen,
		(void*)&(CODE_VARBUF[r].u.iValue));
}
int I_STARTDATE_HEX_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		STARTDATE_HEX_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_STARTTIME_HEX_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	if(p11->iOffset!=-1)	
		STARTTIME_HEX_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_STARTDATE_TBCD_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		STARTDATE_TBCD_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_STARTTIME_TBCD_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		STARTTIME_TBCD_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_STARTDATE_OCTET_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		STARTDATE_OCTET_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_STARTTIME_OCTET_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		STARTTIME_OCTET_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_IA5STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		IA5STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_ENUMERATED(int d1,int r)
{
	struct PositionStruct *p11;
	
	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	if(p11->iOffset==-1){CODE_VARBUF[r].u.iValue=-1;return 0;}
	
	return ENUMERATED(p11->pData+p11->iOffset,p11->iLen,
		(void*)&(CODE_VARBUF[r].u.iValue));
}
int I_HHMISS_STRING(int d1,int r)
{
	struct PositionStruct *p11;
	
	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	if(p11->iOffset==-1){CODE_VARBUF[r].u.iValue=-1;return 0;}

	return HHMISS_STRING(p11->pData+p11->iOffset,p11->iLen,
		(void*)&(CODE_VARBUF[r].u.iValue));
}

int I_ADDRESS_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		ADDRESS_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_TBCD_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		TBCD_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_HEX_TBCD_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		HEX_TBCD_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_OCTET_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		OCTET_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int I_HEX_OCTET_STRING(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		HEX_OCTET_STRING(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

/*******日期时间增加一组函数**********************/
int I_HEX_YYyyMMDD(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		HEX_YYyyMMDD(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_HEX_yyYYMMDD(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		HEX_yyYYMMDD(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_TBCD_YYYYMMDD(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		TBCD_YYYYMMDD(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_TBCD_YYMMDD(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		TBCD_YYMMDD(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}


int I_OCTET_YYYYMMDD(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		OCTET_YYYYMMDD(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_OCTET_YYMMDD(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		OCTET_YYMMDD(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_HEX_HHMISS(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		HEX_HHMISS(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_TBCD_HHMISS(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		TBCD_HHMISS(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int I_OCTET_HHMISS(int d1,int r)
{
	char sTemp[4096];
	struct PositionStruct *p11;

	strcpy(sTemp,"");

	p11=(struct PositionStruct *)GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p11->iOffset!=-1)	
		OCTET_HHMISS(p11->pData+p11->iOffset,p11->iLen,(void*)sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

/***************decode公式接口函数定义****************/
int i_parami2i(int d1, int r)
{
	struct DecodeParamStruct *pParam;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pParam=CompileI2I(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pParam;

	return 0;
}

int i_parami2s(int d1, int r)
{
	struct DecodeParamStruct *pParam;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pParam=CompileI2S(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pParam;

	return 0;
}
int i_params2i(int d1, int r)
{
	struct DecodeParamStruct *pParam;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pParam=CompileS2I(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pParam;

	return 0;
}
int i_params2s(int d1, int r)
{
	struct DecodeParamStruct *pParam;
	char *sInput=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER; /*指针*/

	if((pParam=CompileS2S(sInput))==NULL) return -1;
	
	CODE_VARBUF[r].u.pValue=(char*)pParam;

	return 0;
}

int i_decodei2i(int d1, int r)
{
	int	i=GetIntVariant(CODE_VARBUF,d1);
	char	*p11=GetPointVariant(CODE_VARBUF,d1+1);
	char 	*pr=GetAddrVariant(CODE_VARBUF,r);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	return decodei2i((struct DecodeParamStruct *)p11,i,pr);
}
int i_decodei2s(int d1, int r)
{
	int iRet;
	char sTemp[4096];
	int	i=GetIntVariant(CODE_VARBUF,d1);
	char	*p11=GetPointVariant(CODE_VARBUF,d1+1);

	CODE_VARBUF[r].cType=VARTYPE_STR; 
	iRet=decodei2s((struct DecodeParamStruct *)p11,i,sTemp);
	
	if(AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp)<0)return -1;
	
	return iRet;
}

int i_decodes2i(int d1, int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);
	char *pr=GetAddrVariant(CODE_VARBUF,r);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	return decodes2i((struct DecodeParamStruct *)p11,p1,pr);
}

int i_decodes2s(int d1, int r)
{
	int iRet;
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	iRet=decodes2s((struct DecodeParamStruct *)p11,p1,sTemp);

	if(AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp)<0)return -1;
	
	return iRet;
}

/*********一些基础函数********************/
/***
strlen(a)
substr(a,i,j)
llike(a,b)
rlike(a,b)
atoi(a)
itoa(i)
lpad(a,l,' ')
rpad(a,l,' ')
***/
int i_getsqloff(int d1,int r)
{
	char c,sTemp[11];
	char *p1=(char*)GetPointVariant(CODE_VARBUF,d1);
	int   offset=GetIntVariant(CODE_VARBUF,d1+1);
	int   i=offset,len=GetIntVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_INT;

	while(1){
		c=*(p1+i);

		if(offset+i>=len){
			i=-1;
			break;
		}
		
		if(!((c>='a'&&c<='z')||
			(c>='A'&&c<='Z'))){
			i++;
			continue;
		}
		strncpy(sTemp,p1+i,10);sTemp[10]=0;
		
		Upper(sTemp);
		if(!(strncmp("SELECT",sTemp,6)==0||
			strncmp("INSERT",sTemp,6)==0||
			strncmp("DELETE",sTemp,6)==0||
			strncmp("UPDATE",sTemp,6)==0||
			strncmp("SELECT",sTemp,6)==0||
			strncmp("CREATE",sTemp,6)==0||
			strncmp("DROP",sTemp,4)==0||
			strncmp("TRUNCATE",sTemp,8)==0||
			strncmp("ALTER",sTemp,5)==0||
			strncmp("GRANT",sTemp,5)==0
			)){
			i++;
			continue;
		}
		break;
	}
	
	CODE_VARBUF[r].u.iValue=i;

	return 0;
}

int MyLexConstString(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos;
	char pin[3];

	if(ConstStringBegin(sInput[i])){

		pin[0]='\\';pin[1]=sInput[i];pin[2]=0;

		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->串常量->公式结束");
			return -1;
		}
		while(!ConstStringEnd(sInput[i],pin[1])){

			/*跳过指定转义字符*/
			if(strncmp(sInput+i,pin,2)==0)i+=2;
			else i++;

			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->串常量->公式结束");
				return -1;
			}
		}
		i++; /*跳过"号*/
		
		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;
				
		*piPos=i;
		return true;
	}
	return false;
}
int MyLexConstHexNum(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos;
	
	if(ConstHexNumBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->常HEX整数->公式结束");
			return -1;
		}
		while(ConstHexNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常HEX整数->公式结束");
				return -1;
			}			
		}

		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;
		
		*piPos=i;
		return true;
	}
	return false;
}
int MyLexConstBinNum(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos;
	
	if(ConstBinNumBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->常BIN整数->公式结束");
			return -1;
		}
		while(ConstBinNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常BIN整数->公式结束");
				return -1;
			}			
		}

		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;
		
		*piPos=i;
		return true;
	}
	return false;
}

int MyLexConstDecNum(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos;
	
	if(ConstDecNumBegin(sInput[i])){
		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->常整数->公式结束");
			return -1;
		}
		while(ConstDecNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常整数->公式结束");
				return -1;
			}
		}
		
		if(sInput[i]!='.'){

			/*输出字符串*/
			strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;

			*piPos=i;
			return true;
		}
		/*跳过小数点*/
		i++;
		while(ConstDecNumNext(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->常整数->公式结束");
				return -1;
			}
		}

		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;
		
		*piPos=i;
		return true;		
	}
	return false;
}

int MyLexIdentify(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos;
	char sTemp[256];

	if(IdentifyBegin(sInput[i])||sInput[i]==':'){
		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->标识符->公式结束");
			return -1;
		}
		while(IdentifyNext(sInput[i-1],sInput[i])){
			
			/*汉字就跳过一个字符*/
/*			if(sInput[i-1]&0x80){
				i++;
				if(ExprEnd(sInput[i])){
					ReportExprError(i,"词法错误->标识符->公式结束");
					return -1;
				}
			}
*/
			i++;
			
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->标识符->公式结束");
				return -1;
			}		
		}

		strncpy(sTemp,sInput+(*piPos),i-(*piPos));
		sTemp[i-(*piPos)]=0;
		
		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;
		
		*piPos=i;
		return true;
	}
	return false;
}
int MyLexSeperator(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos;
	
	if(SeperatorBegin(sInput[i])){
		i++;
		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;
		*piPos=i;
		return true;
	}
	return false;
}
int MyLexMath(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos,iType=0;
	
	if(MathBegin(sInput[i])){
		switch(sInput[i]){
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
		case '(':
		case ')':
			iType=TYPE_MATH;
		break;
		default:
			return -1;
		}
		i++;
		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;
		*piPos=i;
		return true;
	}
	return false;
}
int MyLexLogical(char sInput[],int *piPos,char sOutput[])
{
	int i=*piPos,iType=0;
	char sTemp[2];
	
	if(LogicalBegin(sInput[i])){
		if(strncmp(sInput+i,">=",2)==0){
			strcpy(sTemp,"3");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"<=",2)==0){
			strcpy(sTemp,"4");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"==",2)==0){
			strcpy(sTemp,"5");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"!=",2)==0||
			strncmp(sInput,"<>",2)==0){
			strcpy(sTemp,"6");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,">",1)==0){
			strcpy(sTemp,"1");
			iType=TYPE_LOG2;
			i++;
		}
		else if(strncmp(sInput+i,"<",1)==0){
			strcpy(sTemp,"2");
			iType=TYPE_LOG2;
			i++;
		}
		else if(strncmp(sInput+i,"=",1)==0){
			strcpy(sTemp,"=");
			iType=TYPE_ASSIGN;
			i++;
		}
		else if(strncmp(sInput+i,"!",1)==0){
			strcpy(sTemp,"!");
			iType=TYPE_LOG1;
			i++;
		}
		else if(strncmp(sInput+i,"||",2)==0){
			strcpy(sTemp,"|");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"&&",2)==0){
			strcpy(sTemp,"&");
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"|",1)==0){
			strcpy(sTemp,"7");
			iType=TYPE_MATH;
			i++;
		}
		else if(strncmp(sInput+i,"&",1)==0){
			strcpy(sTemp,"8");
			iType=TYPE_MATH;
			i++;
		}
		else
			return false;
		
		/*输出字符串*/
		strncpy(sOutput,sInput+(*piPos),i-(*piPos));sOutput[i-(*piPos)]=0;

		*piPos=i;		
		return true;
	}
	return false;
}
#define IDENTIFY_TYPE_OPER		1	/*SELECT,UPDATE等*/
#define IDENTIFY_TYPE_FUNCTION_NAME	2	/*TRIM,LENGTH等*/
#define IDENTIFY_TYPE_KEY_WORD		3	/*FROM INTO AS WHERE INTERSECT等*/
#define IDENTIFY_TYPE_PARAM		4	/*':'开头的关键字*/
#define IDENTIFY_TYPE_OTHER		5	/*其他类型关键字*/
/*其他复杂类型关键字，带'.'的关键字 CPX,不带'.'关键字 SPL*/

struct MyIdentifyStruct
{
	struct MyIdentifyStruct *pNext;
	char sIdentify[128];
	char sSubType[4];
	int iType;
};
int MyGetIdentifyType(char sTemp[],char sSubType[4])
{
	strcpy(sSubType,"");
	if(sTemp[0]==':'){
		strcpy(sSubType，"PAR");
		return IDENTIFY_TYPE_PARAM;
	}
	
	if(strncmp("SELECT",sTemp,6)==0)	strcpy(sSubType,"SEL");
	else if(strncmp("INSERT",sTemp,6)==0)	strcpy(sSubType,"INS");
	else if(strncmp("DELETE",sTemp,6)==0)	strcpy(sSubType,"DEL");
	else if(strncmp("UPDATE",sTemp,6)==0)	strcpy(sSubType,"UPD");
	else if(strncmp("CREATE",sTemp,6)==0)	strcpy(sSubType,"CRT");
	else if(strncmp("DROP",sTemp,4)==0)	strcpy(sSubType,"DRP");
	else if(strncmp("TRUNCATE",sTemp,8)==0)	strcpy(sSubType,"TRC");
	else if(strncmp("ALTER",sTemp,5)==0)	strcpy(sSubType,"ALT");
	else if(strncmp("GRANT",sTemp,5)==0)	strcpy(sSubType,"GRT");
	
	if(strlen(sSubType)>0){
		return IDENTIFY_TYPE_OPER;
	}
	
	if(strncmp("FROM",sTemp,4)==0||
		strncmp("WHERE",sTemp,5)==0||
		strncmp("AS",sTemp,2)==0||
		strncmp("VALUES",sTemp,6)==0||
		strncmp("INTO",sTemp,4)==0){
			
		strcpy(sSubType，"KEY");
		return IDENTIFY_TYPE_KEY_WORD;
	}
	

	if(strcmp("TRIM",sTemp)==0||
		strcmp("LENGTH",sTemp)==0||
		strcmp("TO_CHAR",sTemp)==0||
		strcmp("TO_DATE",sTemp)==0||
		strcmp("LPAD",sTemp)==0||
		strcmp("RPAD",sTemp)==0){
			
		strcpy(sSubType，"FUN");
		return IDENTIFY_TYPE_FUNCTION_NAME;
	}
	
	strcpy(sSubType，"SPL");
	if(strchr(sTemp,'.')!=NULL) strcpy(sSubType，"CPX");
	
	return IDENTIFY_TYPE_OTHER;

}

static struct MyIdentifyStruct *pMyIdentifyHead=NULL;


int AddMyIdentifyFlow(char sIdentify[])
{
	struct MyIdentifyStruct *pTemp;
	
        if((pTemp=malloc(sizeof(struct MyIdentifyStruct)))==NULL){
        	printf("error Malloc MyIdentifyStruct.\n");
                return -1;
        }
        bzero((void*)pTemp,sizeof(struct MyIdentifyStruct));
        
        pTemp->iType=MyGetIdentifyType(sIdentify,pTemp->sSubType);
        strcpy(pTemp->sIdentify,sIdentify);
                
	InsertList((LIST**)&pMyIdentifyHead,(LIST*)pTemp);

        return 0;
}
/*词法分析,生成具有独立含义的符号流 SymbolFlow*/
int MyLexicalize(char sInput[],char sResult[])
{
	int l=0;
	int i=0,j=0,iRet,iInputLen;
	
	char sOutput[1024];

	iInputLen=strlen(sInput);

	/*去掉'@’字符*/
	while(i<iInputLen){
		if(sInput[i]=='@'){
			i++;
			continue;
		}
		sInput[j++]=sInput[i++];
	}
	sInput[j]=0;
	
	i=0;
	while(i<j){
		
		if(l>=2000) break;

		while((JmpSeperator(sInput[i])||sInput[i]=='@')
			&&!ExprEnd(sInput[i])) i++;

		if(ExprEnd(sInput[i])) break;
	
/*处理C语言注释*/
		if((iRet=LexCComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理C++注释*/
		if((iRet=LexCppComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;

/*处理常量字符串*/
		if((iRet=MyLexConstString(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			l+=sprintf(sResult+l,"CONST=\t%s\n",sOutput);
			continue;
		}
/*处理常量十六进制数*/
		if((iRet=MyLexConstHexNum(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			l+=sprintf(sResult+l,"CONST=\t%s\n",sOutput);
			continue;
		}
/*处理常量二进制数*/
		if((iRet=MyLexConstBinNum(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			l+=sprintf(sResult+l,"CONST=\t%s\n",sOutput);
			continue;
		}
/*处理常量十进制数*/
		if((iRet=MyLexConstDecNum(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			l+=sprintf(sResult+l,"CONST=\t%s\n",sOutput);
			continue;
		}
/*处理标识符*/
		if((iRet=MyLexIdentify(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			Upper(sOutput);
			l+=sprintf(sResult+l,"IDENTIFY=%s\n",sOutput);
			
			if(AddMyIdentifyFlow(sOutput)<0) return -1;

			continue;
		}
/*处理分割符*/
		if((iRet=MyLexSeperator(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			l+=sprintf(sResult+l,"SEP=\t%s\n",sOutput);

			if(AddMyIdentifyFlow(sOutput)<0) return -1;
			continue;
		}
/*处理"+,-,*,/"算术符号*/
		if((iRet=MyLexMath(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			l+=sprintf(sResult+l,"MATH=\t%s\n",sOutput);
			if(AddMyIdentifyFlow(sOutput)<0) return -1;
			continue;
		}

/*处理">,<,=,!,|,&"逻辑符号*/
		if((iRet=MyLexLogical(sInput,&i,sOutput))<0) return -1;
		if(iRet==true){
			l+=sprintf(sResult+l,"LOG=\t%s\n",sOutput);
			continue;
		}
		return -i-1;
	} /*end while(i*/
	
	ReverseList((LIST**)&pMyIdentifyHead);

	return 0;
}

void ConvertSqlToFmtStr(char *p,char sRes[4096])
{
	int l=0;
	char sTemp[12];
	
	strncpy(sTemp,p,10);sTemp[10]=0;
	
	Upper(sTemp);
	
	if(strncmp("SELECT",sTemp,6)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","SEL");
	else if(strncmp("INSERT",sTemp,6)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","INS");
	else if(strncmp("DELETE",sTemp,6)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","DEL");
	else if(strncmp("UPDATE",sTemp,6)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","UPD");
	else if(strncmp("DELETE",sTemp,6)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","DEL");
	else if(strncmp("CREATE",sTemp,6)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","CRT");
	else if(strncmp("DROP",sTemp,4)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","DRP");
	else if(strncmp("TRUNCATE",sTemp,8)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","TRC");
	else if(strncmp("ALTER",sTemp,5)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","ALT");
	else if(strncmp("GRANT",sTemp,5)==0)
		l+=sprintf(sRes+l,"OPER=%s\n","GRT");
	else 	l+=sprintf(sRes+l,"OPER=%s\n","OTH");
		
	if(MyLexicalize(p,sRes+l)<0){
		static int x=0;
		x++;
		printf("hello world %d.\n",x);
		if(x==44)
			printf("error found.\n");
	}
}
int i_getsqlfmtstr(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	ConvertSqlToFmtStr(p1,sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}


int i_strlen(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=strlen(p1);
	return 0;
}
int i_substr(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int   offset=GetIntVariant(CODE_VARBUF,d1+1);
	int   l1,len=GetIntVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	l1=strlen(p1);
	if(len>=4096)len=4095;
	
	if(offset>=0){
		if(l1<offset||len<0){
			strcpy(sTemp,"");
			return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
		}
		strncpy(sTemp,p1+offset,len);
		if(len<4096)/*做一个边界检查*/
			sTemp[len]=0;
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
	}
	if(l1<(-offset)||len<0)
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	strncpy(sTemp,p1+l1+offset,len);
	if(len<4096)/*做一个边界检查*/
		sTemp[len]=0;
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_substr_s(int d1,int r)
{
	char sTemp[4096];

	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	int   ioffset=GetIntVariant(CODE_VARBUF,d1+2);
	
	GetSepStr(p1,p2[0],ioffset,sTemp);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);	
}

int i_substr_t(int d1,int r)
{
	char sTemp[4096];

	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int   ioffset=GetIntVariant(CODE_VARBUF,d1+1);
	
	GetTabStr(p1,ioffset,sTemp);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);	
}

int i_trimsubstr_s(int d1,int r)
{
	char sTemp[4096];

	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	int   ioffset=GetIntVariant(CODE_VARBUF,d1+2);
	
	GetSepStr(p1,p2[0],ioffset,sTemp);
	
	AllTrim(sTemp);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);	
}

int i_trimsubstr_t(int d1,int r)
{
	char sTemp[4096];

	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int   ioffset=GetIntVariant(CODE_VARBUF,d1+1);
	
	GetTabStr(p1,ioffset,sTemp);

	AllTrim(sTemp);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);	
}
int i_cutstr(int d1,int r)
{
	char sTemp[4096];
	char *p1=(char*)GetPointVariant(CODE_VARBUF,d1);
	int   offset=GetIntVariant(CODE_VARBUF,d1+1);
	int   l,len=GetIntVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_STR;

	l=strlen(p1); if(offset<0) offset+=l;

	if(offset<0||len<0)
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");
	if(len>=4096)len=4095;

	strncpy(sTemp,p1+offset,len);sTemp[len]=0;

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_trimcutstr(int d1,int r)
{
	char sTemp[4096];
	char *p1=(char*)GetPointVariant(CODE_VARBUF,d1);
	int   offset=GetIntVariant(CODE_VARBUF,d1+1);
	int   l,len=GetIntVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_STR;

	l=strlen(p1); if(offset<0) offset+=l;

	if(offset<0||len<0||offset>=l)
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	if(len>=4096)len=4095;
	strncpy(sTemp,p1+offset,len);sTemp[len]=0;
	AllTrim(sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_cutstr_s(int d1,int r)
{
	char sTemp[4096];
	char *p1=(char*)GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	int   ioffset=GetIntVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_STR;

	if(ioffset<0)
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	GetSepStr(p1,p2[0],ioffset,sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_trimcutstr_s(int d1,int r)
{
	char sTemp[4096];
	char *p1=(char*)GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	int   ioffset=GetIntVariant(CODE_VARBUF,d1+2);

	CODE_VARBUF[r].cType=VARTYPE_STR;

	if(ioffset<0)
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	GetSepStr(p1,p2[0],ioffset,sTemp);
	AllTrim(sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_cutstr_t(int d1,int r)
{
	char sTemp[4096];
	char *p1=(char*)GetPointVariant(CODE_VARBUF,d1);
	int  ioffset=GetIntVariant(CODE_VARBUF,d1+1);

	CODE_VARBUF[r].cType=VARTYPE_STR;

	if(ioffset<0)
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	GetTabStr(p1,ioffset,sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_trimcutstr_t(int d1,int r)
{
	char sTemp[4096];
	char *p1=(char*)GetPointVariant(CODE_VARBUF,d1);
	int   ioffset=GetIntVariant(CODE_VARBUF,d1+1);

	CODE_VARBUF[r].cType=VARTYPE_STR;

	if(ioffset<0)
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	GetTabStr(p1,ioffset,sTemp);
	AllTrim(sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_fmtnbr(int d1,int r)
{
	char sTemp[4096];
	char *p1=(char*)GetStrVariant(CODE_VARBUF,d1);
	int   type=GetIntVariant(CODE_VARBUF,d1+1);

	CODE_VARBUF[r].cType=VARTYPE_STR;

	FmtNbr(type,p1,sTemp);
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_fmt86a13(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;

	strcpy(sTemp,p1);
	Fmt86A13(sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_fmt86a13x(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;

	strcpy(sTemp,p1);
	Fmt86A13X(sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_ipv4txt2hexstr(int d1,int r)
{
	char sHex[20];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;

	IpV4Txt2HexStr(p1,sHex);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sHex);
}
int i_ipv6txt2hexstr(int d1,int r)
{
	char sHex[20];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;

	IpV6Txt2HexStr(p1,sHex);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sHex);
}
int i_ipv4hexstr2txt(int d1,int r)
{
	char sIp[20];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;

	IpV4HexStr2Txt(p1,sIp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sIp);
}
int i_ipv6hexstr2txt(int d1,int r)
{
	char sIp[20];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;

	IpV6HexStr2Txt(p1,sIp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sIp);
}
int i_llike(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(strncmp(p1,p11,strlen(p11))==0)
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	return 0;
}
int i_rlike(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetStrVariant(CODE_VARBUF,d1+1);
	
	int l1,l11;
	l1=strlen(p1);l11=strlen(p11);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(l11>l1){
		CODE_VARBUF[r].u.iValue=0;
		return 0;
	}
	
	if(strcmp(p1+l1-l11,p11)==0)
		CODE_VARBUF[r].u.iValue=1;
	else
		CODE_VARBUF[r].u.iValue=0;
	
	return 0;
}
int i_atoi(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=atoi(p1);
	return 0;
}
int i_htoi(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=HexStrToInt(p1);
	return 0;
}
int i_itoa(int d1,int r)
{
	char sTemp[128];
	int i=GetIntVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	sprintf(sTemp,"%d",i);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_itoh(int d1,int r)
{
	char sTemp[128];
	int i=GetIntVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	sprintf(sTemp,"%X",i);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_lpad(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetStrVariant(CODE_VARBUF,d1+1);
	int lr=GetIntVariant(CODE_VARBUF,d1+2);

	int  l1,i;
	
	l1=strlen(p1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(lr<l1||lr>4096){
		strcpy(sTemp,p1);
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
	}
	for(i=0;i<lr;i++){
		if(i<lr-l1)sTemp[i]=p11[0];
		else sTemp[i]=*p1++;
	}
	
	sTemp[lr]=0;
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_rpad(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetStrVariant(CODE_VARBUF,d1+1);
	int lr=GetIntVariant(CODE_VARBUF,d1+2);

	int  l1,i;
	l1=strlen(p1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(lr<l1||lr>4096){
		strcpy(sTemp,p1);
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
	}
	for(i=0;i<lr;i++){
		if(i<l1)sTemp[i]=*p1++;
		else sTemp[i]=p11[0];
	}
	
	sTemp[lr]=0;
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_trimx(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetStrVariant(CODE_VARBUF,d1+1);
	
	int i=0;

	CODE_VARBUF[r].cType=VARTYPE_STR;
	if(p1[i]==0){
		strcpy(sTemp,"");
		return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);	
	}	
	if(strchr(p11,p1[0])==NULL){ strcpy(sTemp,p1); goto i_trimx_next;}
	
	while(strchr(p11,p1[i])!=NULL&&p1[i]!=0) i++;

	strcpy(sTemp,p1+i);
	
i_trimx_next:
	i=strlen(sTemp)-1;
	
	while((i>=0)&&strchr(p11,sTemp[i])!=NULL) i--;
	
	sTemp[i+1]=0;

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_rplx(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetStrVariant(CODE_VARBUF,d1+1);
	char *p12=GetStrVariant(CODE_VARBUF,d1+2);
	
	int i,l=strlen(p1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	for(i=0;i<l;i++){/*如果等于x则替换为y*/
		if(p1[i]==p11[0])sTemp[i]=p12[0];
		else sTemp[i]=p1[i];
	}
	sTemp[i]=0;
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_subt(int d1,int r)
{

	char tmp[7];
	int hh,mm,ss,hh1,mm1,ss1;
	
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetStrVariant(CODE_VARBUF,d1+1);
	int  n=GetIntVariant(CODE_VARBUF,d1+2);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	strncpy(tmp,p1,2);
	tmp[2]=0x0;
	hh = atoi(tmp);

	strncpy(tmp,p1+2,2);
	tmp[2]=0x0;
	mm = atoi(tmp);

	strncpy(tmp,p1+4,2);
	tmp[2]=0x0;	   
	ss = atoi(tmp);
	   
	strncpy(tmp,p11,2);
	tmp[2]=0x0;
	hh1 = atoi(tmp);
	strncpy(tmp,p11+2,2);
	tmp[2]=0x0;
	mm1 = atoi(tmp);
	strncpy(tmp,p11+4,2);
	tmp[2]=0x0;	  
	ss1 = atoi(tmp);

	CODE_VARBUF[r].u.iValue=(n*24+hh-hh1)*3600+(mm-mm1)*60+ss-ss1;
	
	return 0;
}
int i_adddt(int d1,int r)
{
	char sTemp[4096];
	
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int i=GetIntVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	strcpy(sTemp,p1);
	if(AddTimes(sTemp,i)<0)	strcpy(sTemp,p1);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

/*设置输出格式函数*/
int i_posp(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *pPre,*pCur,sPre[128],sCur[128];
	struct PositionStruct Temp;

	pPre=p1;
	pCur=GetDecodeStr(pPre,sPre);
	if(pCur==NULL) return -1;
	GetDecodeStr(pCur,sCur);
	
	Temp.iOffset=	atoi(sPre);
	Temp.iLen=	atoi(sCur);
	
	return AssignMemchar2Varchar(&(CODE_VARBUF[r].u.sValue),
		(void*)&Temp,sizeof(struct PositionStruct));
}
int i_setfix(int d1,int r)
{
	int i=GetIntVariant(CODE_VARBUF,d1);
	iFixFlag=i;
	return 0;
}
int i_setoutfmt(int d1,int r)
{
	/*char *p1=GetStrVariant(CODE_VARBUF,d1); *//*输出字段*/
	char *p11=GetStrVariant(CODE_VARBUF,d1+1); /*默认值*/
	char *p12=GetStrVariant(CODE_VARBUF,d1+2); /*格式串*/
	char *p13=GetStrVariant(CODE_VARBUF,d1+3); /*位置结构*/

	struct PositionStruct *p=(struct PositionStruct *)p13;

/*	char cType=	CODE_VARBUF[d1].cType;*/
	int  iIndex=	CODE_VARBUF[d1].iParam; /*话单字段索引*/

	strcpy(TFIELD[iIndex].sDefaultValue,p11); /*填写默认串*/
	strcpy(TFIELD[iIndex].sFormatStr,p12); /*填写默认串*/

	TFIELD[iIndex].Pos.iOffset=	p->iOffset;
	TFIELD[iIndex].Pos.iLen=	p->iLen;

/*获得输出话单尾记录*/
	if(iTailPos<(p->iOffset+p->iLen))
		iTailPos=p->iOffset+p->iLen;
	
	InsertTicketStdTail(&(TFIELD[iIndex]));
	
	CODE_VARBUF[r].cType=	VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=0;

	return 0;
}
int i_resetfmt(int d1,int r)
{
	
	ResetTicketStd();	
	CODE_VARBUF[r].cType=	VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=0;

	return 0;
}

int i_setfilefmt(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1); /*类型*/
	bzero((void*)&FILEFMT,sizeof(struct FileFormatStruct));
	
	strcpy(FILEFMT.sFormat,p1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=0;
	
	if(CompileFileFormat(&FILEFMT)<0) return -1;
	return 0;
}

int i_innum(int d1, int r)
{
	int	i=GetIntVariant(CODE_VARBUF,d1);
	char	*p11=GetPointVariant(CODE_VARBUF,d1+1);
	char 	*pr=GetAddrVariant(CODE_VARBUF,r);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	return innum((struct DecodeParamStruct *)p11,i,pr);
}

int i_instr(int d1, int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p11=GetPointVariant(CODE_VARBUF,d1+1);
	char 	*pr=GetAddrVariant(CODE_VARBUF,r);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	return instr((struct DecodeParamStruct *)p11,p1,pr);
}
int i_gettime(int d1, int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=(int)tGetTime(p1);
	return 0;
}

int i_upper(int d1, int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	strcpy(sTemp,p1);	Upper(sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_lower(int d1, int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	strcpy(sTemp,p1);	Lower(sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_arctime(int d1, int r)
{
	char sTemp[4096];
	int i=GetIntVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	sFormatTime((time_t)i,sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_dumpoutvar(int d1, int r)
{
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=0;
	return GetSysVar(pExprBuf,false);
}
int i_fatoi(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	int i=GetIntVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=atof(p1)*i;
	return 0;
}
int i_fileexist(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(IsFile(p1)==true) CODE_VARBUF[r].u.iValue=1;
	else CODE_VARBUF[r].u.iValue=0;

	return 0;
}
int i_filesize(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=FileSize(p1);

	return 0;
}
int i_fileline(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=FileLine(p1);

	return 0;
}
int i_filemodifydate(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=(int)FileModifyTime(p1);

	return 0;
}

int i_fileextname(int d1,int r)
{
	char *p;
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	if((p=strrchr(p1,'.'))==NULL) p="";
	else p++;

	AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),p);

	return 0;
}
int i_filebasename(int d1,int r)
{
	char sBaseName[256];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	GetBaseName(p1,sBaseName);

	AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sBaseName);

	return 0;
}
int i_filepath(int d1,int r)
{
	int l,l1;
	char sTemp[256],sBaseName[256];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	GetBaseName(p1,sBaseName);

	l=strlen(p1);
	l1=strlen(sBaseName);

	strncpy(sTemp,p1,l-l1);sTemp[l-l1]=0;

	AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);

	return 0;
}

int i_filehead(int d1,int r)
{
	int l;
	FILE *fp;
	char *p,sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	if((fp=fopen(p1,"r"))==NULL) return 0;
	
	l=FileSize(p1);
	if(l>1023) l=1023;

	fread((void*)sTemp,l,1,fp);sTemp[l]=0;

	fclose(fp);

	if((p=strchr(sTemp,'\n'))!=NULL) *p=0;
	
	AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);

	return 0;
}

int i_filetail(int d1,int r)
{
	int l;
	FILE *fp;
	char *p,sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");

	if((fp=fopen(p1,"r"))==NULL) return 0;

	l=FileSize(p1);
	if(l>1023) l=1023;

	fseek(fp,-l,SEEK_END);
	fread((void*)sTemp,l,1,fp);sTemp[l]=0;

	fclose(fp);
	
	if(sTemp[l-1]=='\n') sTemp[l-1]=0;

	if((p=strrchr(sTemp,'\n'))!=NULL){
		p++;
		strcpy(sTemp,p);
	}

	AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);

	return 0;
}
int i_like(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(Like(p1,p2)==true) CODE_VARBUF[r].u.iValue= 1;
	else	CODE_VARBUF[r].u.iValue=0;

	return 0;
}
int i_likex(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if(LikeX(p1,p2)==true) CODE_VARBUF[r].u.iValue= 1;
	else	CODE_VARBUF[r].u.iValue=0;

	return 0;
}
int i_index(int d1,int r)
{
	char *p=NULL;
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	if((p=strstr(p1,p2))!=NULL)
		CODE_VARBUF[r].u.iValue= p-p1;
	else
		CODE_VARBUF[r].u.iValue= -1;

	return 0;
}
int i_index_n(int d1,int r)
{
	char *p=NULL,*pe;
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	int  n=GetIntVariant(CODE_VARBUF,d1+2);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;

	pe=p1+strlen(p1);
	
	while(n>0){
		if(p1>=pe){
			CODE_VARBUF[r].u.iValue= -1;
			return 0;
		}
		if((p=strstr(p1,p2))==NULL){
			CODE_VARBUF[r].u.iValue= -1;
			return 0;
		}
		p1=p+strlen(p2);
		n--;
	}

	if(p!=NULL)
		CODE_VARBUF[r].u.iValue= p-p1;
	else
		CODE_VARBUF[r].u.iValue= -1;

	return 0;
}
int i_getreclen(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue= strlen(p1);

	return 0;
}
int i_gettabcnt(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue= GET_TAB_CNT(p1);

	return 0;
}
int i_getsepcnt(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue= GET_SEP_CNT(p1,p2[0]);

	return 0;
}
int i_getsepstrx(int d1,int r)
{
	char sTemp[128];
	char 	*p1=GetStrVariant(CODE_VARBUF,d1);
	char 	*p2=GetStrVariant(CODE_VARBUF,d1+1);
	int	iOffset=GetIntVariant(CODE_VARBUF,d1+2);
	int	iMaxLen=GetIntVariant(CODE_VARBUF,d1+3);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;

	GetSepStrX(p1,p2[0],iOffset,iMaxLen,sTemp);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_isalldigit(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue= IsAllDigit(p1);

	return 0;
}


int i_isallhex(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue= IsAllHex(p1);

	return 0;
}

int i_atof(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_DOUBLE;
	
	CODE_VARBUF[r].u.dValue=atof(p1);
	return 0;
}

int i_ftoa(int d1,int r)
{
	char sTemp[128];
	double d=GetDoubleVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	sprintf(sTemp,"%f",d);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}

int i_itof(int d1,int r)
{
	int i=GetIntVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_DOUBLE;
	
	CODE_VARBUF[r].u.dValue=(double)i;
	
	return 0;
}
int i_ftoi(int d1,int r)
{
	double d=GetDoubleVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=(int)d;
	
	return 0;
}
void fmt_supp(int d1,int iParamCnt,char sResult[])
{
	int i;
	va_list argptr=NULL;
	char *p,cType,sTemp[256];
	char *fmt=GetStrVariant(CODE_VARBUF,d1);/*定义格式的变量*/

	p=&sTemp[0];

	for(i=1;i<iParamCnt;i++){
		cType=CODE_VARBUF[d1+i].cType;

		if(cType==VARTYPE_INT){
			*((int*)p)=GetIntVariant(CODE_VARBUF,d1+i);
			p=(char*)(((int*)p)+1);
		}
		else if(cType==VARTYPE_STR){
			*((char**)p)=GetStrVariant(CODE_VARBUF,d1+i);
			p=(char*)(((char**)p)+1);
		}
		else if(cType==VARTYPE_DOUBLE){
			*((double*)p)=GetDoubleVariant(CODE_VARBUF,d1+i);
			p=(char*)(((double*)p)+1);
		}
		else{
			*((int*)p)=GetIntVariant(CODE_VARBUF,d1+i);
			p=(char*)(((int*)p)+1);
		}
	}
	argptr=(va_list)&sTemp[0];
	vsprintf(sResult,fmt,argptr);
	va_end(argptr);
}

void fmt_supp_s(int d1,int iParamCnt,char sResult[])
{
	int i,l=0,t;
	char *p,cType,c;
	char *fmt=GetStrVariant(CODE_VARBUF,d1);/*定义格式的变量*/

	c=fmt[0];
	
	strcpy(sResult,"");

	for(i=1;i<iParamCnt;i++){
		cType=CODE_VARBUF[d1+i].cType;

		if(cType==VARTYPE_INT){
			t=GetIntVariant(CODE_VARBUF,d1+i);
			l+=sprintf(sResult+l,"%d%c",t,c);
		}
		else if(cType==VARTYPE_STR){
			p=GetStrVariant(CODE_VARBUF,d1+i);
			l+=sprintf(sResult+l,"%s%c",p,c);
		}
	}
}
int i_format(int d1,int r)
{
	char sTemp[4096];

	int iParamCnt,d2=MY_AD(CODE_FLOW[igCodePos].data2);
	
	CHECK_AD(d2);

	iParamCnt=CODE_VARBUF[d2].iParam;/*调用时的参数个数*/

	fmt_supp(d1,iParamCnt,sTemp);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_format_s(int d1,int r)
{
	char sTemp[4096];

	int iParamCnt,d2=MY_AD(CODE_FLOW[igCodePos].data2);
	
	CHECK_AD(d2);

	iParamCnt=CODE_VARBUF[d2].iParam;/*调用时的参数个数*/

	fmt_supp_s(d1,iParamCnt,sTemp);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_printf(int d1,int r)
{
	char sTemp[4096];

	int iParamCnt,d2=CODE_FLOW[igCodePos].data2;
	
	iParamCnt=CODE_VARBUF[d2].iParam;/*调用时的参数个数*/

	fmt_supp(d1,iParamCnt,sTemp);
	printf(sTemp);

	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	return 0;
}

int i_item2list(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	int l;
	
	CODE_VARBUF[r].cType=VARTYPE_POINTER;
	
	if(p2==NULL)			CODE_VARBUF[r].u.pValue=p1;
	else if((l=strlen(p2))==0)	CODE_VARBUF[r].u.pValue=p1;
	else if(item2list((struct FileControlStruct **)&p1,(void*)p2,l)<0)
		CODE_VARBUF[r].u.pValue=NULL;
	else 	CODE_VARBUF[r].u.pValue=p1;

	return 0;
}

int i_item2listtail(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	int l;
	
	CODE_VARBUF[r].cType=VARTYPE_POINTER;
	
	if(p2==NULL)			CODE_VARBUF[r].u.pValue=p1;
	else if((l=strlen(p2))==0)	CODE_VARBUF[r].u.pValue=p1;
	else if(item2listtail((struct FileControlStruct **)&p1,(void*)p2,l)<0)
		CODE_VARBUF[r].u.pValue=NULL;
	else 	CODE_VARBUF[r].u.pValue=p1;

	return 0;
}

int i_appendlisttail(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetPointVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_POINTER;
	if(p2!=NULL)	AppendListTail((LIST**)&p1,(LIST*)p2);
	CODE_VARBUF[r].u.pValue=p1;

	return 0;
}

int i_list2file(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=list2file((struct FileControlStruct**)&p1,p2);

	return 0;
}

int i_list2fileln(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=list2fileln((struct FileControlStruct**)&p1,p2);

	return 0;
}

int i_list2filelrn(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	CODE_VARBUF[r].u.iValue=list2filelrn((struct FileControlStruct**)&p1,p2);

	return 0;
}
int i_execcmd(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	CODE_VARBUF[r].u.iValue=execcmd(p1);
		
	return 0;
}
int i_exec2str(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	strcpy(sTemp,"");
	
	exec2str(p1,sTemp);

	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_exec2list(int d1,int r)
{
	struct FileControlStruct *pTemp=NULL;
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	exec2list(p1,&pTemp);

	CODE_VARBUF[r].cType=VARTYPE_POINTER;
	CODE_VARBUF[r].u.pValue=(void*)pTemp;
	
	return 0;
}
int i_txtf2list(int d1,int r)
{
	struct FileControlStruct *pTemp=NULL;
	char *p1=GetStrVariant(CODE_VARBUF,d1);
		
	file2list(p1,0,-1,0,&pTemp);

	CODE_VARBUF[r].cType=VARTYPE_POINTER;
	CODE_VARBUF[r].u.pValue=(void*)pTemp;
	
	return 0;
}
int i_listfree(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
		
	listfree((struct FileControlStruct **)&p1);

	CODE_VARBUF[r].cType=VARTYPE_POINTER;
	CODE_VARBUF[r].u.pValue=NULL;
	
	return 0;
}
int i_countlist(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=CountList((LIST*)p1);
	return 0;
}
void getlistmintime(struct FileControlStruct *ptHead,int o,int l,char sTime[])
{
	char sMinTime[15],sCurTime[15];
	
	strcpy(sTime,"");
	strcpy(sMinTime,"99999999999999");
	if(l>14) return;
	
	while(ptHead!=NULL){
		
		if(ptHead->iLen<(o+l)) return;
		strncpy(sCurTime,(char*)(ptHead->pData)+o,l);sCurTime[l]=0;
		
		if(strcmp(sCurTime,sMinTime)<0)	strcpy(sMinTime,sCurTime);
		ptHead=ptHead->pNext;
	}
	strcpy(sTime,sMinTime);
}
void getlistmaxtime(struct FileControlStruct *ptHead,int o,int l,char sTime[])
{
	char sMaxTime[15],sCurTime[15];
	
	strcpy(sTime,"");
	strcpy(sMaxTime,"00000000000000");
	if(l>14) return;
	
	while(ptHead!=NULL){
		
		if(ptHead->iLen<(o+l)) return;
		strncpy(sCurTime,(char*)(ptHead->pData)+o,l);sCurTime[l]=0;
		
		if(strcmp(sCurTime,sMaxTime)>0)	strcpy(sMaxTime,sCurTime);
		ptHead=ptHead->pNext;
	}
	strcpy(sTime,sMaxTime);
}
int getlistsumnum(struct FileControlStruct *ptHead,int o,int l)
{
	int i=0;
	char sTemp[128];	

	while(ptHead!=NULL){
		if(ptHead->iLen<(o+l)) return -1;
		strncpy(sTemp,(char*)(ptHead->pData)+o,l);sTemp[l]=0;
		i+=atoi(sTemp);
		ptHead=ptHead->pNext;
	}
	return i;
}
int i_getlistmintime(int d1,int r)
{
	char sTime[15];
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	int off=GetIntVariant(CODE_VARBUF,d1+1);
	int len=GetIntVariant(CODE_VARBUF,d1+2);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	getlistmintime((struct FileControlStruct*)p1,off,len,sTime);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTime);;
}
int i_getlistmaxtime(int d1,int r)
{
	char sTime[15];
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	int off=GetIntVariant(CODE_VARBUF,d1+1);
	int len=GetIntVariant(CODE_VARBUF,d1+2);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	getlistmaxtime((struct FileControlStruct*)p1,off,len,sTime);

	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTime);;
}

int i_getlistsumnum(int d1,int r)
{
	char *p1=GetPointVariant(CODE_VARBUF,d1);
	int off=GetIntVariant(CODE_VARBUF,d1+1);
	int len=GetIntVariant(CODE_VARBUF,d1+2);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	CODE_VARBUF[r].u.iValue=
		getlistsumnum((struct FileControlStruct*)p1,off,len);

	return 0;
}
int i_ord(int d1,int r)
{
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	if(p1!=NULL) CODE_VARBUF[r].u.iValue=(char)(p1[0]);
	else	CODE_VARBUF[r].u.iValue=0;

	return 0;
}
int i_chr(int d1,int r)
{
	char sTemp[2];
	int i=GetIntVariant(CODE_VARBUF,d1);
	
	sTemp[0]=(char)i; sTemp[1]=0;

	CODE_VARBUF[r].cType=VARTYPE_STR;
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_readstr(int d1,int r)
{
	char sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	char *p3=GetStrVariant(CODE_VARBUF,d1+2);
	char *p4=GetStrVariant(CODE_VARBUF,d1+3);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	ReadString(p1,p2,p3,p4,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
int i_readstrbss(int d1,int r)
{
	char sPath[256],sTemp[4096];
	char *p1=GetStrVariant(CODE_VARBUF,d1);
	char *p2=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	GetIniName(sPath);
	
	ReadString(sPath,"bss",p1,p2,sTemp);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sTemp);
}
/*为了防止某些c对math.h支持不好，写了一个10的指数的函数*/
double i_my_pow10(int k)
{
	int i,j=k>0?k:-k,l=1;
	
	for(i=0;i<j;i++)l*=10;
	
	return k>0?(double)l:1.0/(double)l;
}
int i_getprecision(int d1,int r)
{
	double d=GetDoubleVariant(CODE_VARBUF,d1),x;
	int i=GetIntVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_DOUBLE;
	
	x=i_my_pow10(i);
	CODE_VARBUF[r].u.dValue=(double)((int)(d*x+0.5))/x;

	return 0;
}

int i_getacctitemcharge(int d1,int r)
{
	int iAcctItemTypeID=GetIntVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	IGetAcctItemCharge(iAcctItemTypeID,&(CODE_VARBUF[r].u.iValue));

	return 0;
}
int i_getacctitemstate(int d1,int r)
{
	char sState[10];
	int iAcctItemTypeID=GetIntVariant(CODE_VARBUF,d1);
	
	CODE_VARBUF[r].cType=VARTYPE_STR;
	
	IGetAcctItemState(iAcctItemTypeID,sState);
	
	return AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),sState);
}
int i_setacctitemcharge(int d1,int r)
{
	int iAcctItemTypeID=GetIntVariant(CODE_VARBUF,d1);
	int iCharge=GetIntVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	IPutAcctItemCharge(iAcctItemTypeID,iCharge);
	
	CODE_VARBUF[r].u.iValue=0;
	
	return 0;
}
int i_setacctitemstate(int d1,int r)
{
	int iAcctItemTypeID=GetIntVariant(CODE_VARBUF,d1);
	char *p=GetStrVariant(CODE_VARBUF,d1+1);
	
	CODE_VARBUF[r].cType=VARTYPE_INT;
	
	IPutAcctItemState(iAcctItemTypeID,p);
	
	CODE_VARBUF[r].u.iValue=0;
	
	return 0;
}
void RegExprFun()
{
RegFunItem("getasnpos"           ,i_getasnpos	        ,"33",'4','f');
RegFunItem("asnp"                ,i_asnp                ,"2",'3','F');
RegFunItem("getfixpos"           ,i_getfixpos           ,"33",'4','f');
RegFunItem("fixp"                ,i_fixp                ,"2",'3','F');
RegFunItem("gettabpos"           ,i_gettabpos           ,"33",'4','f');
RegFunItem("tabp"                ,i_tabp                ,"2",'3','F');
RegFunItem("getseppos"           ,i_getseppos           ,"33",'4','f');
RegFunItem("sepp"                ,i_sepp                ,"2",'3','F');
RegFunItem("TBCD_INT4B"          ,I_TBCD_INT4B          ,"4",'1','f');
RegFunItem("HEX_TBCD_INT4B"      ,I_HEX_TBCD_INT4B      ,"4",'1','f');
RegFunItem("OCTET_INT4B"         ,I_OCTET_INT4B         ,"4",'1','f');
RegFunItem("HEX_OCTET_INT4B"     ,I_HEX_OCTET_INT4B     ,"4",'1','f');
RegFunItem("IA5STRING"           ,I_IA5STRING           ,"4",'2','f');
RegFunItem("ENUMERATED"          ,I_ENUMERATED          ,"4",'1','f');
RegFunItem("HHMISS_STRING"       ,I_HHMISS_STRING       ,"4",'1','f');
RegFunItem("ADDRESS_STRING"      ,I_ADDRESS_STRING      ,"4",'2','f');
RegFunItem("TBCD_STRING"         ,I_TBCD_STRING         ,"4",'2','f');
RegFunItem("HEX_TBCD_STRING"     ,I_HEX_TBCD_STRING     ,"4",'2','f');
RegFunItem("OCTET_STRING"        ,I_OCTET_STRING        ,"4",'2','f');
RegFunItem("HEX_OCTET_STRING"    ,I_HEX_OCTET_STRING    ,"4",'2','f');
RegFunItem("pi2i"                ,i_parami2i            ,"2",'3','F');
RegFunItem("pi2s"                ,i_parami2s            ,"2",'3','F');
RegFunItem("ps2i"                ,i_params2i            ,"2",'3','F');
RegFunItem("ps2s"                ,i_params2s            ,"2",'3','F');
RegFunItem("di2i"      		 ,i_decodei2i           ,"13",'1','f');
RegFunItem("di2s"                ,i_decodei2s           ,"13",'2','f');
RegFunItem("ds2i"                ,i_decodes2i           ,"23",'1','f');
RegFunItem("ds2s"                ,i_decodes2s           ,"23",'2','f');
/*2008-05-20增加bill.ini的公式对照关系*/
RegFunItem("qi2i"                ,i_parami2i            ,"2",'3','f');
RegFunItem("qi2s"                ,i_parami2s            ,"2",'3','f');
RegFunItem("qs2i"                ,i_params2i            ,"2",'3','f');
RegFunItem("qs2s"                ,i_params2s            ,"2",'3','f');
RegFunItem("gi2i"      		 ,i_decodei2i           ,"13",'1','f');
RegFunItem("gi2s"                ,i_decodei2s           ,"13",'2','f');
RegFunItem("gs2i"                ,i_decodes2i           ,"23",'1','f');
RegFunItem("gs2s"                ,i_decodes2s           ,"23",'2','f');

RegFunItem("readstrbss"          ,i_readstrbss          ,"22",'2','f');
RegFunItem("readstr"             ,i_readstr             ,"2222",'2','f');
RegFunItem("getprecision"        ,i_getprecision        ,"51",'5','f');

RegFunItem("strlen"              ,i_strlen              ,"2",'1','f');
RegFunItem("length"              ,i_strlen              ,"2",'1','f');
RegFunItem("substr"              ,i_substr              ,"211",'2','f');

RegFunItem("getsqloff"           ,i_getsqloff           ,"311",'1','f');
RegFunItem("getsqlfmtstr"        ,i_getsqlfmtstr        ,"2",'2','f');

RegFunItem("substr_s"            ,i_substr_s            ,"221",'2','f');
RegFunItem("substr_t"            ,i_substr_t            ,"21",'2','f');
RegFunItem("trimsubstr_s"        ,i_trimsubstr_s        ,"221",'2','f');
RegFunItem("trimsubstr_t"        ,i_trimsubstr_t        ,"21",'2','f');

RegFunItem("llike"               ,i_llike               ,"22",'1','f');
RegFunItem("rlike"               ,i_rlike               ,"22",'1','f');
RegFunItem("atoi"                ,i_atoi                ,"2",'1','f');
RegFunItem("htoi"                ,i_htoi                ,"2",'1','f');
RegFunItem("itoa"                ,i_itoa                ,"1",'2','f');
RegFunItem("itoh"                ,i_itoh                ,"1",'2','f');
RegFunItem("lpad"                ,i_lpad                ,"221",'2','f');
RegFunItem("rpad"                ,i_rpad                ,"221",'2','f');
RegFunItem("trimx"               ,i_trimx               ,"22",'2','f');
RegFunItem("rplx"                ,i_rplx                ,"222",'2','f');
RegFunItem("subt"                ,i_subt                ,"221",'1','f');
RegFunItem("adddt"               ,i_adddt              ,"21",'2','f');

/**日期支持函数组**/
RegFunItem("HEX_YYyyMMDD"  ,   I_HEX_YYyyMMDD  ,"4",'2','f');
RegFunItem("HEX_yyYYMMDD"  ,   I_HEX_yyYYMMDD  ,"4",'2','f');
RegFunItem("TBCD_YYYYMMDD" ,   I_TBCD_YYYYMMDD ,"4",'2','f');
RegFunItem("TBCD_YYMMDD"   ,   I_TBCD_YYMMDD   ,"4",'2','f');
RegFunItem("OCTET_YYYYMMDD",   I_OCTET_YYYYMMDD,"4",'2','f');
RegFunItem("OCTET_YYMMDD"  ,   I_OCTET_YYMMDD  ,"4",'2','f');
RegFunItem("HEX_HHMISS"    ,   I_HEX_HHMISS    ,"4",'2','f');
RegFunItem("TBCD_HHMISS"   ,   I_TBCD_HHMISS   ,"4",'2','f');
RegFunItem("OCTET_HHMISS"  ,   I_OCTET_HHMISS  ,"4",'2','f');
/*规范后的日期转换函数*/
RegFunItem("STARTDATE_STRING"	,I_STARTDATE_HEX_STRING    ,"4",'2','f');
RegFunItem("STARTTIME_STRING"	,I_STARTTIME_HEX_STRING    ,"4",'2','f');
RegFunItem("STARTDATE_HEX_STRING",I_STARTDATE_HEX_STRING   ,"4",'2','f');
RegFunItem("STARTTIME_HEX_STRING",I_STARTTIME_HEX_STRING   ,"4",'2','f');

RegFunItem("STARTDATE_OCTET_STRING",I_STARTDATE_OCTET_STRING,"4",'2','f');
RegFunItem("STARTTIME_OCTET_STRING",I_STARTTIME_OCTET_STRING,"4",'2','f');

RegFunItem("STARTDATE_TBCD_STRING",I_STARTDATE_TBCD_STRING ,"4",'2','f');
RegFunItem("STARTTIME_TBCD_STRING",I_STARTTIME_TBCD_STRING ,"4",'2','f');

RegFunItem("posp"                ,i_posp         	,"2",'4','F');
RegFunItem("setfix"              ,i_setfix		,"1",'1','F');
RegFunItem("setfmt"              ,i_setoutfmt           ,"0224",'1','F');
RegFunItem("dynfmt"              ,i_setoutfmt           ,"0224",'1','f');
RegFunItem("resetfmt"            ,i_resetfmt          	,"",'1','f');
RegFunItem("maxdatadate" 	 ,i_maxdatadate		,"2",'1','f');
RegFunItem("initdate"		 ,i_initdate		,"1",'1','F');
RegFunItem("setfilefmt"		 ,i_setfilefmt		,"2",'1','F');
RegFunItem("dumpoutvar"		 ,i_dumpoutvar		,"",'1','F');


/**对IN的支持**/
RegFunItem("pini"                ,i_parami2i	,"2",'3','F');
RegFunItem("pins"                ,i_params2s   	,"2",'3','F');
RegFunItem("innum"               ,i_innum	,"13",'1','f');
RegFunItem("instr"               ,i_instr	,"23",'1','f');
RegFunItem("gettime"             ,i_gettime     ,"2",'1','f');
RegFunItem("arctime"             ,i_arctime     ,"1",'2','f');

RegFunItem("cut"              	 ,i_cutstr      ,"311",'2','f');
RegFunItem("trimcut"             ,i_trimcutstr  ,"311",'2','f');

RegFunItem("cut_s"                 ,i_cutstr_s    ,"321",'2','f');
RegFunItem("trimcut_s"             ,i_trimcutstr_s,"321",'2','f');

RegFunItem("cut_t"          	,i_cutstr_t    ,"31",'2','f');
RegFunItem("trimcut_t"         	,i_trimcutstr_t,"31",'2','f');

RegFunItem("fmtnbr"              ,i_fmtnbr      ,"21",'2','f');
RegFunItem("fmt86a13"            ,i_fmt86a13 	,"2",'2','f');
RegFunItem("fmt86a13x"           ,i_fmt86a13x 	,"2",'2','f');

RegFunItem("ipv4txt2hexstr"      ,i_ipv4txt2hexstr,"2",'2','f');
RegFunItem("ipv6txt2hexstr"      ,i_ipv6txt2hexstr,"2",'2','f');
RegFunItem("ipv4hexstr2txt"      ,i_ipv4hexstr2txt,"2",'2','f');
RegFunItem("ipv6hexstr2txt"      ,i_ipv6hexstr2txt,"2",'2','f');

RegFunItem("upper"               ,i_upper    	,"2",'2','f');
RegFunItem("lower"               ,i_lower    	,"2",'2','f');
RegFunItem("fatoi"      	 ,i_fatoi      ,"21",'1','f');
RegFunItem("getsepstrx"		 ,i_getsepstrx ,"2211",'2','f');
/*文件校验函数*/
RegFunItem("fileexist"      	 ,i_fileexist      ,"2",'1','f');
RegFunItem("filesize"      	 ,i_filesize       ,"2",'1','f');
RegFunItem("fileline"      	 ,i_fileline       ,"2",'1','f');
RegFunItem("filemoditydate"      ,i_filemodifydate ,"2",'1','f');
RegFunItem("fileextname"         ,i_fileextname    ,"2",'2','f');
RegFunItem("filebasename"        ,i_filebasename   ,"2",'2','f');
RegFunItem("filepath"            ,i_filepath       ,"2",'2','f');

RegFunItem("filehead"            ,i_filehead       ,"2",'2','f');
RegFunItem("filetail"            ,i_filetail       ,"2",'2','f');

RegFunItem("like"                ,i_like           ,"22",'1','f');
RegFunItem("likex"               ,i_likex         ,"22",'1','f');
RegFunItem("index"                ,i_index          ,"22",'1','f');
RegFunItem("index_n"              ,i_index_n        ,"221",'1','f');
RegFunItem("getreclen"           ,i_getreclen      ,"3",'1','f');
RegFunItem("gettabcnt"           ,i_gettabcnt      ,"3",'1','f');
RegFunItem("getsepcnt"           ,i_getsepcnt      ,"32",'1','f');
RegFunItem("isalldigit"          ,i_isalldigit     ,"2",'1','f');
RegFunItem("isallhex"            ,i_isallhex       ,"2",'1','f');

RegFunItem("atof"                ,i_atof                ,"2",'5','f');
RegFunItem("ftoa"                ,i_ftoa                ,"5",'2','f');
RegFunItem("itof"                ,i_itof                ,"1",'5','f');
RegFunItem("ftoi"                ,i_ftoi                ,"5",'1','f');

RegFunItem("format"              ,i_format              ,"#",'2','f');
RegFunItem("format_s"            ,i_format_s            ,"#",'2','f');
RegFunItem("printf"              ,i_printf              ,"#",'1','f');

RegFunItem("item2list"		,i_item2list	,"32",'3','f');
RegFunItem("item2listtail"	,i_item2listtail,"32",'3','f');
RegFunItem("appendlisttail"	,i_appendlisttail,"33",'3','f');
RegFunItem("list2file"		,i_list2file	,"32",'1','f');
RegFunItem("list2fileln"	,i_list2fileln	,"32",'1','f');
RegFunItem("list2filelrn"	,i_list2filelrn	,"32",'1','f');

RegFunItem("execcmd"		,i_execcmd	,"2",'1','f');
RegFunItem("exec2str"		,i_exec2str	,"2",'2','f');
RegFunItem("exec2list"		,i_exec2list	,"2",'3','f');
RegFunItem("txtf2list"		,i_txtf2list	,"2",'3','f');
RegFunItem("listfree"		,i_listfree 	,"3",'1','f');
RegFunItem("countlist"		,i_countlist 	,"3",'1','f');

RegFunItem("getlistmintime"     ,i_getlistmintime  ,"311",'2','f');
RegFunItem("getlistmaxtime"     ,i_getlistmaxtime  ,"311",'2','f');
RegFunItem("getlistsumnum"      ,i_getlistsumnum   ,"311",'1','f');

RegFunItem("ord"      		,i_ord   	,"2",'1','f');
RegFunItem("chr"      		,i_chr   	,"1",'2','f');

RegFunItem("getacctitemcharge"	,i_getacctitemcharge  ,"1",'1','f');
RegFunItem("getacctitemstate"	,i_getacctitemstate  ,"1",'2','f');
RegFunItem("setacctitemcharge"	,i_setacctitemcharge  ,"12",'1','f');
RegFunItem("setacctitemstate"	,i_setacctitemstate  ,"12",'1','f');


}

/*以下是opsp where d1=p_op_call时的内置函数*/
int mv_sp2bp(int d1,int r)
{
	MY_BP=MY_SP;
	return 0;
}
int mv_bp2sp(int d1,int r)
{
	MY_SP=MY_BP;
	return 0;
}
int clear_variant(int d1,int r)
{
	if(CODE_VARBUF[r].cType==VARTYPE_INT)
		CODE_VARBUF[r].u.iValue=0;
	else if(CODE_VARBUF[r].cType==VARTYPE_DOUBLE)
		CODE_VARBUF[r].u.dValue=(double)0;
	else if(CODE_VARBUF[r].cType==VARTYPE_STR)
		AssignStrchar2Varchar(&(CODE_VARBUF[r].u.sValue),"");
	return 0;
}
