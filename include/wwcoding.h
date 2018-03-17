#ifndef __WWCODING_H__
#define __WWCODING_H__

#include <datatype.h>

/*解码函数*/
void hbcd_dec2asc(uint1b *p,int iLen,char sOutput[]);
void lbcd_dec2asc(uint1b *p,int iLen,char sOutput[]);
void hbcd_hex2asc(uint1b *p,int iLen,char sOutput[]);
void lbcd_hex2asc(uint1b *p,int iLen,char sOutput[]);

void ebcd_dec2asc(uint1b *p,int iLen,char sOutput[]);
void ebcd_hex2asc(uint1b *p,int iLen,char sOutput[]);

int hmem2int4b(uint1b *p,int iLen,int4b *piOutput);
int lmem2int4b(uint1b *p,int iLen,int4b *piOutput);
int hmem2int8b(uint1b *p,int iLen,int8b *piOutput);
int lmem2int8b(uint1b *p,int iLen,int8b *piOutput);

/*一般不用以下编码函数，编码整数*/
int lbcd2int4b(uint1b *p,int iLen,int4b *piOutput);
int hbcd2int4b(uint1b *p,int iLen,int4b *piOutput);
int ebcd2int4b(uint1b *p,int iLen,int4b *piOutput);


int GetCharHex(char c);
/*编码函数*/
int asc_dec2hbcd(char sInput[],uint1b sOutput[]);
int asc_dec2lbcd(char sInput[],uint1b sOutput[]);
int asc_hex2hbcd(char sInput[],uint1b sOutput[]);
int asc_hex2hbcd(char sInput[],uint1b sOutput[]);

int asc_dec2ebcd(char sInput[],uint1b sOutput[]);
int asc_hex2ebcd(char sInput[],uint1b sOutput[]);

int int4b2hmem(int4b iInput,uint1b sOutput[]);
int int4b2lmem(int4b iInput,uint1b sOutput[]);
int int8b2hmem(int8b iInput,uint1b sOutput[]);
int int8b2lmem(int8b iInput,uint1b sOutput[]);

/*一般不用以下解码函数，解码整数*/
int int4b2lbcd(int4b iInput,uint1b sOutput[]);
int int4b2hbcd(int4b iInput,uint1b sOutput[]);
int int4b2ebcd(int4b iInput,uint1b sOutput[]);


#define TAG_INVALID_END		-1
#define TAG_INVALID_LEN		-2
#define TAG_INVALID_VALUE	-3
#define INVALID_LEN		-4;


int HexStrToInt(char sTemp[]);
int BinStrToInt(char sTemp[]);


#define RECORD_BUFFER		2048
#define BLOCK_BUFFER		2048
struct	AsnStruct
{
	struct	AsnStruct *pNext;
	int 	iTag;
	int	iTagType;	/*0 definite 1 indefinite */
};


char *SwitchNextTag(char *p,int iCeilLen,int *piErrCode);
int SearchTagItem(char *p,struct AsnStruct *ptHead,char **ppc,int iCeilLen,int *piErrCode);
/***在p所指定的话单中获取sTag指定的参数，用译码函数Decode翻译到po中***/
/***如果为复合的TAGGED DATA则将iTag翻译过去，简单TAGGED DATA则将数据翻译过去*/
int AsnItem(char *p,struct AsnStruct *ptHead,int (*Decode)(char *,int ,void *),
	char *po,int iCeilLen,int *piErrCode);


#define	ASN_ITEM(__p,__f,__d,__e) {\
		static struct AsnStruct *pHead=NULL;\
		if(pHead==NULL){\
			if((pHead=CompileAsnOff((__p)))==NULL){\
				printf("字符串%s为非法TAG串.\n",(__p));\
				exit(1);\
			}\
		}\
		if(AsnItem(p,pHead,(__f),sTemp,PToken.iRecordLen,&iErrCode)\
			==NOTFOUND){\
			if(iErrCode!=0){\
				PToken.iErrCode	=iErrCode;\
				return __e;\
			}\
			strcpy(sTemp,(__d));\
		}\
				}

#define RECORD_HEAD	1
#define RECORD_TAIL	2
#define RECORD_BODY	3
#define RECORD_PASSED	4

#define BLOCK_TAIL	0
#define BLOCK_TICKET	1
#define DEF_STR_LEN	31	/*默认字符串可用长度为31*/



int GetAsnRecord(int iPos,int iBufLen,char sBlock[2048],
	char sRecord[1024],int *piRecordLen);
struct ParamStruct
{
	int d1;
	int d2;
};
struct PositionStruct
{
	char	*pData;
	int	iOffset;
	int	iLen;
};

int STARTDATE_HEX_STRING(char *p,int iLen,void *po);
int STARTTIME_HEX_STRING(char *p,int iLen,void *po);
int STARTDATE_OCTET_STRING(char *p,int iLen,void *po);
int STARTTIME_OCTET_STRING(char *p,int iLen,void *po);
int STARTDATE_TBCD_STRING(char *p,int iLen,void *po);
int STARTTIME_TBCD_STRING(char *p,int iLen,void *po);

int IA5STRING(char *p,int iLen,void *po);
int ENUMERATED(char *p,int iLen,void *po);
int HHMISS_STRING(char *p,int iLen,void *po);

int ADDRESS_STRING(char *p,int iLen,void *po);

int TBCD_STRING(char *p,int iLen,void *po);
int HEX_TBCD_STRING(char *p,int iLen,void *po);
int OCTET_STRING(char *p,int iLen,void *po);
int HEX_OCTET_STRING(char *p,int iLen,void *po);


int TBCD_INT4B(char *p,int iLen,void *po);
int HEX_TBCD_INT4B(char *p,int iLen,void *po);
int OCTET_INT4B(char *p,int iLen,void *po);
int HEX_OCTET_INT4B(char *p,int iLen,void *po);

/*日期时间增加功能*/
int HEX_YYyyMMDD(char *p, int iLen,void *po);
int HEX_yyYYMMDD(char *p, int iLen,void *po);
int TBCD_YYYYMMDD(char *p, int iLen,void *po);
int TBCD_YYMMDD(char *p, int iLen,void *po);
int OCTET_YYYYMMDD(char *p, int iLen,void *po);
int OCTET_YYMMDD(char *p, int iLen,void *po);
int HEX_HHMISS(char *p, int iLen,void *po);
int TBCD_HHMISS(char *p, int iLen,void *po);
int OCTET_HHMISS(char *p, int iLen,void *po);
int DecodeLenItem(unsigned char *p,int *piLen);

int GET_ASN_POS(char *pi,char *p,struct PositionStruct *po);
int GET_FIX_POS(char *pi,char *p,struct PositionStruct *po);
int GET_SEP_POS(char *pi,char *p,struct PositionStruct *po);
int GET_TAB_POS(char *pi,char *p,struct PositionStruct *po);

struct AsnStruct *CompileAsnOff(char sTag[]);
struct ParamStruct *CompileFixOff(char sInput[]);
struct ParamStruct *CompileSepOff(char sInput[]);
struct ParamStruct *CompileTabOff(char sInput[]);

void GetTabStr(char sInput[],int iOffset,char sOutput[]);
void GetSepStr(char sInput[],char cSep,int iOffset,char sOutput[]);
void GetFixStr(char sInput[],int iOffset,int l,char sOutput[]);

int AssignMemchar2Varchar(char **ppr,char *p1,int l1);
int AssignStrchar2Varchar(char **ppr,char *p1);
int AssignV2VStrchar(char **ppr,char *p1);
int AssignV2VMemchar(char **ppr,char *p1);
char *MallocVarchar(int l);
int GenVarcharLen(int l,unsigned char sTemp[5]);
int GenVarcharByStrchar(char sInput[],char sOutput[]);
int GenVarcharByMemchar(char sInput[],int l,char sOutput[]);
char *GetVarcharData(char *p);
int GetVarcharLen(char *p);
int GetVarcharStrlen(char *p);
int GetVarcharSize();
int SupposeVarcharLen(int l);
int AddV2VStrchar(char **ppr,char *p1,char *p2);
int GenAsncharLen(int l,unsigned char sTemp[5]);
int GenAsncharByStrchar(char sInput[],char sOutput[]);

void GetTabStrX(char sInput[],int iOffset,int iMaxLen,char sOutput[]);
void GetSepStrX(char sInput[],char cSep,int iOffset,int iMaxLen,char sOutput[]);
void GetFixStrX(char sInput[],int iOffset,int l,char sOutput[]);
int GET_SEP_CNT(char sRecord[],char c);
int GET_TAB_CNT(char sRecord[]);
int IsAllDigit(char sTemp[]);
int IsAllHex(char sTemp[]);

#define VARTYPE_INT	'1'
#define VARTYPE_STR	'2'
#define VARTYPE_UNK	'0'
#define VARTYPE_POINTER	'3'
#define VARTYPE_STRUCT	'4'
#define VARTYPE_DOUBLE	'5'

struct DecodeParamStruct
{
	struct DecodeParamStruct *pNext;
	char cType1; /*\0,无效1整数,2串*/
	char cType2; /*1整数,2串*/
	union{
		int	iValue;
		char	sValue[128];
	} d1;
	union{
		int	iValue;
		char	sValue[128];
	} d2;
};

char *GetDecodeStr(char sInput[],char sOutput[]);
struct DecodeParamStruct *GetDecodeParam(char sInput1[],char sInput2[]);
void DestroyDecodeParam(struct DecodeParamStruct *ptHead);
struct DecodeParamStruct *ParamDecode(char sInput[]);

int checki2i(struct DecodeParamStruct *ptHead );
int checki2s(struct DecodeParamStruct *ptHead );
int checks2i(struct DecodeParamStruct *ptHead );
int checks2s(struct DecodeParamStruct *ptHead);
struct DecodeParamStruct *CompileI2I(char sInput[]);
struct DecodeParamStruct *CompileI2S(char sInput[]);
struct DecodeParamStruct *CompileS2I(char sInput[]);
struct DecodeParamStruct *CompileS2S(char sInput[]);
int decodei2i(struct DecodeParamStruct *ptHead, int i,char *po);
int decodei2s(struct DecodeParamStruct *ptHead, int i,char *po);
int decodes2i(struct DecodeParamStruct *ptHead, char *pi,char *po);
int decodes2s(struct DecodeParamStruct *ptHead, char *pi,char *po);

int innum(struct DecodeParamStruct *ptHead, int i,char *po);
int instr(struct DecodeParamStruct *ptHead, char sTemp[],char *po);

struct BlkFmtStruct
{
	int	iHeadLen;
	int	iTailLen;
	int	iRecLen;
	int	iLenInHd;	/*1:文件头,0文件体*/
	int	iLenOff;
	int	iLenLen;
	void	*pParam;
	int 	(*GetLen)(uint1b *p,int iLen,int4b *piOutput);
};
struct FileFormatStruct
{
	char	sFormat[256];
	char 	sFileType[10];
	struct BlkFmtStruct Blk;
	struct BlkFmtStruct Rec;
};

extern struct FileFormatStruct FILEFMT;

int InitBlkFmt(char sHead[],char sBody[],char sTail[],
	struct BlkFmtStruct *p);

int CompileFileFormat(struct FileFormatStruct *p);

void Fmt86A13(char sTemp[]);
void Fmt86A13X(char sTemp[]);

#define ARG_STRCPY(x,y) {strncpy(x,y,sizeof(x)-1);x[sizeof(x)-1]=0;AllTrim(x);}

int GetSepInt(char sInput[],char cSep,int iOffset);
int GetTabInt(char sInput[],int iOffset);
int GetFixInt(char sInput[],int iOffset,int len);
int GetSepCnt(char sInput[],char cSep);
int GetTabCnt(char sInput[]);
void ArgStrcpy(char sOutput[],char sInput[],int iMax);

int IpV4Txt2HexStr(char sIp[],char sHex[]);
int IpV4HexStr2Txt(char sHex[],char sIp[]);
int IpV6Txt2HexStr(char sIp[],char sHex[]);
int IpV6HexStr2Txt(char sHex[],char sIp[]);

int GetSepOff(char sInput[],char cSep,int iOffset);
int GetSepLen(char sInput[],char cSep,int iOffset);
int GetTabOff(char sInput[],int iOffset);
int GetTabLen(char sInput[],int iOffset);

void FmtNbr(int type,char p1[],char sTemp[]);

int ResetErr2Ori(char sRecordType[],char sErrRec[],char sOri[],int *piLen);


#endif
