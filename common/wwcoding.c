#include "hnixs.h"
#include "list.h"
#include <wwlog.h>
#include "wwfile.h"
#include "wwtiny.h"
#include "wwcoding.h"
#include "wwsupp.h"

struct FileFormatStruct FILEFMT;

/*.bcd字符装换为-----》字符串
	1）高低，高低，高低，高低	ABCDEF->结束符
		首位为字节高位，函数为10位编码
注意:iLen是被转换字符串的字节数，转换结果为<=2*iLen长,
	该函数填充结束符,而且sOutput长度必须>=2*iLen+1

*/
void hbcd_dec2asc(uint1b *p,int iLen,char sOutput[])
{
	uint1b c;
	static char sAnti[]="0123456789ABCDEF";

	int i,t,j=0;

	for(i=0;i<iLen;i++){

		c=p[i];

		t=(c&0xF0)>>4;		/*先取高位*/

		if(t>=10) break;

		sOutput[j++]=sAnti[t];

		t= c&0x0f;		/*后取低位*/

		if(t>=10) break;

		sOutput[j++]=sAnti[t];
	}
	sOutput[j]=0;
}

/*.bcd字符装换为-----》字符串，
	1）低高，低高，低高，低高	ABCDEF->结束符
		首位为字节低位，函数为10位编码
注意:iLen是被转换字符串的字节数，转换结果为<=2*iLen长

*/

void lbcd_dec2asc(uint1b *p,int iLen,char sOutput[])
{
	uint1b c;
	static char sAnti[]="0123456789ABCDEF";

	int i,t,j=0;

	for(i=0;i<iLen;i++){

		c=p[i];

		t= c&0x0f;		/*先取低位*/

		if(t>=10) break;

		sOutput[j++]=sAnti[t];

		t=(c&0xF0)>>4;		/*后取高位*/

		if(t>=10) break;

		sOutput[j++]=sAnti[t];
	}
	sOutput[j]=0;
}


/*.bcd字符装换为-----》字符串
	1）高低，高低，高低，高低	ABCDEF->结束符
		首位为字节高位，函数为16位编码
注意:iLen是被转换字符串的字节数，转换结果为<=2*iLen长,
	该函数填充结束符,而且sOutput长度必须>=2*iLen+1
*/
void hbcd_hex2asc(uint1b *p,int iLen,char sOutput[])
{
	uint1b c;
	static char sAnti[]="0123456789ABCDEF";

	int i,t,j=0;

	for(i=0;i<iLen;i++){

		c=p[i];

		t=(c&0xF0)>>4;		/*先取高位*/
		sOutput[j++]=sAnti[t];

		t= c&0x0f;		/*后取低位*/
		sOutput[j++]=sAnti[t];
	}
	sOutput[j]=0;
}

/*.bcd字符装换为-----》字符串，
	1）低高，低高，低高，低高	ABCDEF->结束符
		首位为字节低位，函数为16位编码
注意:iLen是被转换字符串的字节数，转换结果为<=2*iLen长

*/

void lbcd_hex2asc(uint1b *p,int iLen,char sOutput[])
{
	uint1b c;
	static char sAnti[]="0123456789ABCDEF";

	int i,t,j=0;

	for(i=0;i<iLen;i++){

		c=p[i];

		t= c&0x0f;		/*先取低位*/
		sOutput[j++]=sAnti[t];

		t=(c&0xF0)>>4;		/*后取高位*/
		sOutput[j++]=sAnti[t];
	}
	sOutput[j]=0;
}

/*.ebcd字符装换为-----》字符串，
	函数为10位编码
注意:iLen是被转换字符串的字节数，转换结果为<=iLen长
*/
void ebcd_dec2asc(uint1b *p,int iLen,char sOutput[])
{
	uint1b c;
	static char sAnti[]="0123456789ABCDEF";

	int i,t,j=0;

	for(i=0;i<iLen;i++){

		c=p[i];

		t= c&0x0f;		/*先取低位*/

		if(t>=10) break;

		sOutput[j++]=sAnti[t];
	}
	sOutput[j]=0;
}

/*.ebcd字符装换为-----》字符串，
	函数为16位编码
注意:iLen是被转换字符串的字节数，转换结果为<=iLen长
*/
void ebcd_hex2asc(uint1b *p,int iLen,char sOutput[])
{
	uint1b c;
	static char sAnti[]="0123456789ABCDEF";

	int i,t,j=0;

	for(i=0;i<iLen;i++){

		c=p[i];
		
		t= c&0x0f;		/*先取低位*/
		sOutput[j++]=sAnti[t];
	}
	sOutput[j]=0;
}
/*字节到整数*/
/*低字节表示整数的高位，IBM等大型机使用，
如0x20304050，在内存中从低到高分别是0x20，0x30，0x40，0x50*/
int hmem2int4b(uint1b *p,int iLen,int4b *piOutput)
{
	int i;
	uint4b j=0;

	if(iLen>4||iLen<=0){
		*piOutput=0;
		return -1;
	}
	for(i=0;i<iLen;i++)
		j=j*256+p[i];

	*piOutput	=(int4b)j;

	return 0;
}
/*字节到整数*/
/*低字节表示整数的低位，高字节表示高字节的高位，PC
如0x20304050，在内存中从低到高分别是0x50，0x40，0x30，0x20*/
int lmem2int4b(uint1b *p,int iLen,int4b *piOutput)
{
	int i;

	uint4b j=0,k=1;

	if(iLen>4||iLen<=0){
		*piOutput=0;
		return -1;
	}

	for(i=0;i<iLen;i++){
		j+=p[i]*k;
		k*=256;
	}
	*piOutput= (int4b)j;

	return 0;
}

/*字节到整数*/
/*低字节表示整数的高位，IBM等大型机使用，
如0x20304050，在内存中从低到高分别是0x20，0x30，0x40，0x50*/
int hmem2int8b(uint1b *p,int iLen,int8b *piOutput)
{
	int i;
	uint8b j=0;

	if(iLen>8||iLen<=0){
		*piOutput=0;
		return -1;
	}
	for(i=0;i<iLen;i++)
		j=j*256+p[i];

	*piOutput	=(int8b)j;

	return 0;
}

/*字节到整数*/
/*低字节表示整数的低位，高字节表示高字节的高位，PC
如0x20304050，在内存中从低到高分别是0x50，0x40，0x30，0x20*/
int lmem2int8b(uint1b *p,int iLen,int8b *piOutput)
{
	int i;

	uint8b j=0,k=1;

	if(iLen>8||iLen<=0){
		*piOutput=0;
		return -1;
	}

	for(i=0;i<iLen;i++){
		j+=p[i]*k;
		k*=256;
	}
	*piOutput= (int8b)j;

	return 0;
}

/*最好这些函数不解码负数*/
int lbcd2int4b(uint1b *p,int iLen,int4b *piOutput)
{
	char sTemp[12];

	if(iLen>5||iLen<0){
		*piOutput=0;
		return -1;
	}
	lbcd_dec2asc(p,iLen,sTemp);
	*piOutput=atoi(sTemp);

	return 0;
}
int hbcd2int4b(uint1b *p,int iLen,int4b *piOutput)
{
	char sTemp[12];

	if(iLen>5||iLen<0){
		*piOutput=0;
		return -1;
	}
	hbcd_dec2asc(p,iLen,sTemp);

	*piOutput=atoi(sTemp);

	return 0;
}

int ebcd2int4b(uint1b *p,int iLen,int4b *piOutput)
{
	char sTemp[12];

	if(iLen>10||iLen<0){
		*piOutput=0;
		return -1;
	}
	ebcd_dec2asc(p,iLen,sTemp);

	*piOutput=atoi(sTemp);

	return 0;
}


int GetCharHex(char c)
{
	if(c>='0'&&c<='9') return c-'0';

	if(c>='A'&&c<='F') return c-'A'+10;

	if(c>='a'&&c<='f') return c-'a'+10;
	
	return -1;
}
int asc_dec2hbcd(char sInput[],uint1b sOutput[])
{
	int j,i=0,k=0,Flag=TRUE;

	while(sInput[i]!='\0'){

		j=GetCharHex(sInput[i]);
		if(j<0||j>10) return -1;

		if(Flag){
			Flag=FALSE;
			sOutput[k]=j<<4;
		}
		else{
			Flag=TRUE;
			sOutput[k]|=j;
			k++;
		}
		i++;
	}
	if(Flag==FALSE){
		sOutput[k]|=0x0f;
		k++;
	}
	return k;
}

int asc_dec2lbcd(char sInput[],uint1b sOutput[])
{
	int j,i=0,k=0,Flag=TRUE;

	while(sInput[i]!='\0'){

		j=GetCharHex(sInput[i]);
		if(j<0||j>10) return -1;

		if(Flag){
			Flag=FALSE;
			sOutput[k]=j;
		}
		else{
			Flag=TRUE;
			sOutput[k]|=(j<<4);
			k++;
		}
		i++;
	}
	if(Flag==FALSE){
		sOutput[k]|=0xf0;
		k++;
	}
	return k;
}

int asc_hex2hbcd(char sInput[],uint1b sOutput[])
{
	int j,i=0,k=0,Flag=TRUE;

	while(sInput[i]!='\0'){

		j=GetCharHex(sInput[i]);
		if(j<0) return -1;

		if(Flag){
			Flag=FALSE;
			sOutput[k]=j<<4;
		}
		else{
			Flag=TRUE;
			sOutput[k]|=j;
			k++;
		}
		i++;
	}
	if(Flag==FALSE){
		sOutput[k]|=0x0f;
		k++;
	}
	return k;
}

int asc_hex2lbcd(char sInput[],uint1b sOutput[])
{
	int j,i=0,k=0,Flag=TRUE;

	while(sInput[i]!='\0'){

		j=GetCharHex(sInput[i]);
		if(j<0) return -1;

		if(Flag){
			Flag=FALSE;
			sOutput[k]=j;
		}
		else{
			Flag=TRUE;
			sOutput[k]|=(j<<4);
			k++;
		}
		i++;
	}
	if(Flag==FALSE){
		sOutput[k]|=0xf0;
		k++;
	}
	return k;
}

int asc_dec2ebcd(char sInput[],uint1b sOutput[])
{
	int j,i=0,k=0;

	while(sInput[i]!='\0'){

		j=GetCharHex(sInput[i]);
		if(j<0||j>15) return -1;

		sOutput[k++]=j|0xf0;
		i++;
	}

	return k;
}
int asc_hex2ebcd(char sInput[],uint1b sOutput[])
{
	int j,i=0,k=0;

	while(sInput[i]!='\0'){

		j=GetCharHex(sInput[i]);
		if(j<0) return -1;

		sOutput[k++]=j|0xf0;
		i++;
	}

	return k;
}

/*整数到流的编码，数据编码成IBM式的整数*/
int int4b2lmem(int4b iInput,uint1b sOutput[])
{
	int	k=0;

	uint4b j=(uint4b) iInput;

	while(j>0){
		sOutput[k++]=(uint1b)(j%256);
		j/=256;
	}
	return k;
}
/*整数到流的编码，数据编码成PC式的整数*/
int int4b2hmem(int4b iInput,uint1b sOutput[])
{
	int k=0,i;
	uint1b sTemp[4];
	
	i=int4b2lmem(iInput,sTemp);
	while(i>0){
		i--;
		sOutput[k++]=sTemp[i];
	}
	return k;
}


/*整数到流的编码，数据编码成IBM式的整数*/
int int8b2hmem(int8b iInput,uint1b sOutput[])
{
	int	k=0;

	uint8b j=(uint8b) iInput;

	while(j>0){
		sOutput[k++]=(uint1b)(j%256);
		j/=256;
	}
	return k;
}
/*整数到流的编码，数据编码成PC式的整数*/
int int8b2lmem(int8b iInput,uint1b sOutput[])
{
	int k=0,i;
	uint1b sTemp[8];
	
	i=int8b2hmem(iInput,sTemp);
	while(i>0){
		i--;
		sOutput[k++]=sTemp[i];
	}
	return k;
}

int int4b2lbcd(int4b iInput,uint1b sOutput[])
{
	char sTemp[12];

	uint4b j=(uint4b)iInput;

	sprintf(sTemp,"%u",j);

	return asc_dec2lbcd(sTemp,sOutput);
}
int int4b2hbcd(int4b iInput,uint1b sOutput[])
{
	char sTemp[12];

	uint4b j=(uint4b)iInput;

	sprintf(sTemp,"%u",j);

	return asc_dec2hbcd(sTemp,sOutput);
}
int int4b2ebcd(int4b iInput,uint1b sOutput[])
{
	char sTemp[12];

	uint4b j=(uint4b)iInput;

	sprintf(sTemp,"%u",j);

	return asc_dec2ebcd(sTemp,sOutput);
}


/***********ASN译码转换函数*****************/

/*
注意,本函数不判断TAG==0的情况,该情况可能是无限长度的TAG
*/

int DecodeTagItem(unsigned char *p,int *piForm,int *piTag,int *piErrCode)
{       
	int j=0,iTag;
	unsigned short int *piTemp;
	unsigned char c;
	
	
        *piErrCode=0;
        piTemp=(unsigned short int *)p;
        
        /**两种结束TAG标识**/
        /*
        if(*piTemp==0||*piTemp==0xffff){
		*piForm=	0;
		*piTag=		(int)(*piTemp);
		return 2;
        } */
	/**一个非法的TAG标识
	if(p[0]==0&&p[1]!=0){
		*piTag=		0;
		*piForm=	0;
		*piErrCode=TAG_INVALID_END;
		return 0;
	}
	*/	
	
	if((p[0]==0&&p[1]==0) || 
		(p[0]==0xff && p[1]==0xff)){
		*piForm=	0;
		*piTag=		p[0]*256+p[1];
		return 2;
        }
	/**一个非法的TAG标识**/
	if(p[0]==0&&p[1]!=0){
		*piTag=		0;
		*piForm=	0;
		*piErrCode=TAG_INVALID_END;
		return 0;
	}
	        
        c=p[0];
        
	*piForm = (0x20 & c) >>5; /*Form=1为嵌套结构*/
	
	if ((0x1F & c ) == 0x1F){/*为多字节Tag码*/
	
		j=1;
		while(p[j]>0x80){
			j++;
			if(j>10){
				*piTag=		0;
				*piErrCode=TAG_INVALID_LEN;
				return 0;
			}
		}
		hmem2int4b(p,j+1,&iTag);
	}
	else
		iTag= c;
	
	if(iTag<0){
		*piTag=iTag;
		*piErrCode=TAG_INVALID_VALUE;
		return 0;
	}
	
	*piTag=iTag;
	
	return j+1;
}

int DecodeLenItem(unsigned char *p,int *piLen)
{
	int j;
	unsigned char c;
	
	c=p[0];
	
	if( c<0x80){/*表示1位长度的长度位编码*/
		*piLen=c;
		return 1;
	}
	if( c>0x80){
		*piLen=0;
		
		j=c&0x7F;
		
		hmem2int4b(p+1,j,piLen);
		
		return j+1;
	}
	/**这里只有无限长度的ASN长度编码了 LEN_BEGIN==0X80**/
	*piLen=-1;/*-1表示无限长*/
	
	return 1;
}


/**空表示遇到不确定长TAGGED DATA的结尾*/

char *SwitchNextTag(char *p,int iCeilLen,int *piErrCode)
{
	char	*c;
	int 	iForm,iTag,iTagBytes,iLenBytes,iDataBytes,iLeftCeil=iCeilLen;
	
	iTagBytes=DecodeTagItem((unsigned char *)p,&iForm,&iTag,piErrCode);
	if(iTag==0||iTag==0xffff||*piErrCode) return NULL;
	
	iLenBytes=DecodeLenItem((unsigned char *)p+iTagBytes, &iDataBytes);
	
	
	if(iDataBytes<0){
		
		p+=iTagBytes+iLenBytes;
		
		iLeftCeil-=(iTagBytes+iLenBytes);
		if(iLeftCeil<0){
			*piErrCode=INVALID_LEN;
			return NULL;
		}
		
		while((c=SwitchNextTag(p,iLeftCeil,piErrCode))!=NULL){
		
			iLeftCeil-=(int)(c-p);
			if(iLeftCeil<0){
				*piErrCode=INVALID_LEN;
				return NULL;
			}
			p=c;
		}
		
		if(*piErrCode!=0) return NULL;
		c=p;
		if(*c==0&&*(c+1)==0){
			c+=2;
			return c;
		}
		*piErrCode=TAG_INVALID_END;
		return NULL;
	}
	
	/*长度越界则返回失败*/	
	if((iTagBytes+iLenBytes+iDataBytes)>iCeilLen){
		*piErrCode=INVALID_LEN;
		return NULL;
	}
	
	return p+iTagBytes+iLenBytes+iDataBytes;	
}
int SearchTagItem(char *p,struct AsnStruct *ptHead,char **ppc,
	int iCeilLen,int *piErrCode)
{
	char 	*c,*d;
	int 	iForm,iTag,iTagBytes,iLenBytes,iDataBytes,iLeftCeil=iCeilLen;
	
	iTagBytes=DecodeTagItem((unsigned char *)p,&iForm,&iTag,piErrCode);
	
	if(*piErrCode) return NOTFOUND;
	
	if(iTag!=ptHead->iTag)	return NOTFOUND;
	
	if(ptHead->pNext==NULL){
		*ppc=p;
		return FOUND;
	}
	
	iLenBytes=DecodeLenItem((unsigned char *)p+iTagBytes,&iDataBytes);

	if(iDataBytes<0){/*表示不确定长度的TAG*/
		
		p+=iTagBytes+iLenBytes;
		
		iLeftCeil-=(iTagBytes+iLenBytes);
		if(iLeftCeil<0){
			*piErrCode=INVALID_LEN;
			return NOTFOUND;
		}
		
		while((c=SwitchNextTag(p,iLeftCeil,piErrCode))!=NULL){/**找结束符**/
			if(SearchTagItem(p,ptHead->pNext,ppc,iLeftCeil,piErrCode)==FOUND)
				return FOUND;
			if(*piErrCode) return NOTFOUND;
			
			iLeftCeil-=(int)(c-p);
			
			if(iLeftCeil<0){
				*piErrCode=INVALID_LEN;
				return NOTFOUND;
			}
			
			p=c;
		}
		
	}
	else{
		p+=iTagBytes+iLenBytes;
		d=p+iDataBytes;
		
		iLeftCeil-=(iTagBytes+iLenBytes);
		
		while((c=SwitchNextTag(p,iLeftCeil,piErrCode))!=NULL){/**找结束符**/
			if(SearchTagItem(p,ptHead->pNext,ppc,iLeftCeil,piErrCode)==FOUND)
				return FOUND;
			
			if(*piErrCode) return NOTFOUND;
			
			p=c;
			if(p>=d)break;
		}
	}
	return NOTFOUND;
}
/***在p所指定的话单中获取sTag指定的参数，用译码函数Decode翻译到po中***/
/***如果为复合的TAGGED DATA则将iTag翻译过去，简单TAGGED DATA则将数据翻译过去*/
int AsnItem(char *p,struct AsnStruct *ptHead,int (*Decode)(char *,int ,void *),
	char *po,int iCeilLen,int *piErrCode)
{
	char	*t;
	int 	iForm,iTag,iTagBytes,iLenBytes,iDataBytes;
	
	if(SearchTagItem(p,ptHead,&t,iCeilLen,piErrCode)==NOTFOUND)
		return NOTFOUND;
	
	if(*piErrCode) return NOTFOUND;
	
	iTagBytes=DecodeTagItem((unsigned char *)t,&iForm,&iTag,piErrCode);
	if(*piErrCode) return NOTFOUND;
	
	iLenBytes=DecodeLenItem((unsigned char *)t+iTagBytes,&iDataBytes);
/**	
	if(iForm!=0)
		Decode(t+iTagBytes+iLenBytes,sizeof(int),(void*)po);
	else
		Decode(t+iTagBytes+iLenBytes,iDataBytes,(void*)po);
**/
	Decode(t+iTagBytes+iLenBytes,iDataBytes,(void*)po);
	
	return FOUND;
}
int GetAsnRecord(int iPos,int iBufLen,char sBlock[2048],
	char sRecord[1024],int *piRecordLen)
{
	int iErrCode=0;
	char *p,*t;

	if(iBufLen-iPos<10) return BLOCK_TAIL;
	
	if(((unsigned char)sBlock[iPos]==0xff&&
		(unsigned char)sBlock[iPos+1]==0xff)||
		((unsigned char)sBlock[iPos]==0x00&&
		(unsigned char)sBlock[iPos+1]==0x00)) return BLOCK_TAIL;
	
	p=sBlock+iPos;

	
	t=SwitchNextTag(p,iBufLen-iPos,&iErrCode);

	/*BLOCK结束,TAG出错,块操作缓冲都跳过块*/
	ERROR_RETURN((t==NULL||iErrCode!=0));


	*piRecordLen=t-p;

	memcpy((void*)sRecord,(void*)p,t-p);
	
	return BLOCK_TICKET;
}
/**********解码接口函数定义******************/


int IA5STRING(char *p,int iLen,void *po)
{
	memcpy(po,(void*)p,iLen);
	*( ((char *)po) + iLen) =0;
	return 0;
}
int ADDRESS_STRING(char *p,int iLen,void *po)
{
	lbcd_dec2asc((unsigned char *)(p+1),iLen-1,(char *)po);
	return 0;
}
int TBCD_STRING(char *p,int iLen,void *po)
{
	lbcd_dec2asc((unsigned char *)p,iLen,(char *)po);
	return 0;
}

int HEX_TBCD_STRING(char *p,int iLen,void *po)
{
	lbcd_hex2asc((unsigned char *)p,iLen,(char *)po);
	return  0;
}
int OCTET_STRING(char *p,int iLen,void *po)
{
	hbcd_dec2asc((unsigned char *)p,iLen,(char *)po);
	return 0;
}
int HEX_OCTET_STRING(char *p,int iLen,void *po)
{
	hbcd_hex2asc((unsigned char *)p,iLen,(char *)po);
	return 0;
}
int ENUMERATED(char *p,int iLen, void *po)
{
	*((int *)po)=((uint1b *)p)[0];
	return 0;
}

int HHMISS_STRING(char *p,int iLen,void *po)
{
	int iDuration=0;
	char s[7],sTemp[3];
	
	if(iLen!=3) return -1;
	
	hbcd_hex2asc((unsigned char *)p,iLen,s);
	
	strncpy(sTemp,s,2);sTemp[2]=0; 
	iDuration+=HexStrToInt(sTemp)*3600;
	
	strncpy(sTemp,s+2,2);sTemp[2]=0;
	iDuration+=HexStrToInt(sTemp)*60;
	
	strncpy(sTemp,s+4,2);sTemp[2]=0;
	iDuration+=HexStrToInt(sTemp);
	
	*(int *)po= iDuration;
	
	return 0;
}

int TBCD_INT4B(char *p,int iLen,void *po)
{
	char sTemp[32];

	lbcd_dec2asc((unsigned char *)p,iLen,(char *)sTemp);
	*((int4b*)po)=atoi(sTemp);
	return 0;
}

int HEX_TBCD_INT4B(char *p,int iLen,void *po)
{
	lmem2int4b((uint1b *)p,iLen,(int4b *)po);
	return  0;
}
int OCTET_INT4B(char *p,int iLen,void *po)
{
	char sTemp[32];
	hbcd_dec2asc((unsigned char *)p,iLen,(char *)sTemp);
	*((int4b*)po)=atoi(sTemp);
	return 0;
}
int HEX_OCTET_INT4B(char *p,int iLen,void *po)
{	
	hmem2int4b((uint1b *)p,iLen,(int4b *)po);
	return  0;
}
/***********增加一组日期时间转换函数********************/
int HEX_YYyyMMDD(char *p, int iLen,void *po)
{
	int iYear,iMonth,iDate;

	if(iLen<3||iLen>4) return -1;

	if(iLen==3){
		iYear=	p[0];
		iMonth= p[1];
		iDate = p[2];
		if(iYear>50) iYear += 1900;
		else 	iYear+=2000;
	}
	else{
		iYear=	p[0]*256+p[1];
		iMonth= p[2];
		iDate = p[3];
	}
	
	if(iYear<1950||iYear>2050) 
		return -1;
	if(iMonth<=0||iMonth>12)
		return -1;
	
	if(iDate<=0||iDate>31) 
		return -1;
	
	sprintf((char*)po,"%04d%02d%02d",iYear,iMonth,iDate);
	
	return 0;
}

int HEX_yyYYMMDD(char *p, int iLen,void *po)
{
	int iYear,iMonth,iDate;

	if(iLen<3||iLen>4) return -1;

	if(iLen==3){
		iYear=	p[0];
		iMonth= p[1];
		iDate = p[2];
		if(iYear>50) iYear += 1900;
		else 	iYear+=2000;
	}
	else{
		iYear=	p[1]*256+p[0];
		iMonth= p[2];
		iDate = p[3];
	}
	
	if(iYear<1950||iYear>2050) 
		return -1;
	if(iMonth<=0||iMonth>12)
		return -1;
	
	if(iDate<=0||iDate>31) 
		return -1;
	
	sprintf((char*)po,"%04d%02d%02d",iYear,iMonth,iDate);
	
	return 0;
}
int TBCD_YYYYMMDD(char *p, int iLen,void *po)
{
	lbcd_dec2asc((unsigned char *)p,4,(char*)po);
	return 0;
}
int TBCD_YYMMDD(char *p, int iLen,void *po)
{
	char sTemp[7];

	lbcd_dec2asc((unsigned char *)p,3,(char*)sTemp);

	if(sTemp[0]<'5')
		sprintf((char*)po,"20%s",sTemp);
	else
		sprintf((char*)po,"19%s",sTemp);
	return 0;
}
int OCTET_YYYYMMDD(char *p, int iLen,void *po)
{
	hbcd_dec2asc((unsigned char *)p,4,(char*)po);
	return 0;
}
int OCTET_YYMMDD(char *p, int iLen,void *po)
{
	char sTemp[7];

	hbcd_dec2asc((unsigned char *)p,3,(char*)sTemp);

	if(sTemp[0]<'5')
		sprintf((char*)po,"20%s",sTemp);
	else
		sprintf((char*)po,"19%s",sTemp);
	return 0;
}
int HEX_HHMISS(char *p, int iLen,void *po)
{
	int iHour,iMinute,iSecond;
	
	if(iLen!=3)	return -1;
	
	iHour	=(unsigned char )p[0];
	iMinute	=(unsigned char )p[1];
	iSecond	=(unsigned char )p[2];
	
	if(iHour<0||iHour>23)
		return -1;

	if(iMinute<0||iMinute>59) 
		return -1;

	if(iSecond<0||iSecond>59) 
		return -1;
	
	sprintf((char *)po,"%02d%02d%02d",iHour,iMinute,iSecond);
	return 0;
}
int TBCD_HHMISS(char *p, int iLen,void *po)
{
	lbcd_dec2asc((unsigned char *)p,3,(char *)po);
	return 0;
}
int OCTET_HHMISS(char *p, int iLen,void *po)
{
	hbcd_dec2asc((unsigned char *)p,3,(char *)po);
	return 0;
}
/*规范后的时间转换函数*/
int STARTDATE_HEX_STRING(char *p, int iLen,void *po)
{
	int iYear,iMonth,iDate;

	if(iLen<3||iLen>4) return -1;

	if(iLen==3){
		iYear=	(unsigned char )p[0];
		iMonth= (unsigned char )p[1];
		iDate = (unsigned char )p[2];
		if(iYear>50) iYear += 1900;
		else 	iYear+=2000;
	}
	else{
		iYear=(unsigned char )p[0]*256+(unsigned char )p[1];
		if(iYear<1950||iYear>2050) 
			iYear=(unsigned char )p[1]*256+	(unsigned char )p[0];
		iMonth= p[2];
		iDate = p[3];
	}
	
	if(iYear<1950||iYear>2050) 
		return -1;
	if(iMonth<=0||iMonth>12)
		return -1;
	
	if(iDate<=0||iDate>31) 
		return -1;
	
	sprintf((char*)po,"%04d%02d%02d",iYear,iMonth,iDate);
	
	return 0;
}
int STARTTIME_HEX_STRING(char *p,int iLen,void *po)
{
	int iHour,iMinute,iSecond;
	
	if(iLen!=3)	return -1;
	
	iHour	=(unsigned char )p[0];
	iMinute	=(unsigned char )p[1];
	iSecond	=(unsigned char )p[2];
	
	if(iHour<0||iHour>23)
		return -1;

	if(iMinute<0||iMinute>59) 
		return -1;

	if(iSecond<0||iSecond>59) 
		return -1;
	
	sprintf((char *)po,"%02d%02d%02d",iHour,iMinute,iSecond);
	
	return 0;
}
int STARTDATE_OCTET_STRING(char *p, int iLen,void *po)
{
	if(iLen<3||iLen>4) return -1;
	if(iLen==3) return OCTET_YYMMDD(p,iLen,po);
	return OCTET_YYYYMMDD(p,iLen,po);
}
int STARTTIME_OCTET_STRING(char *p, int iLen,void *po)
{
	return OCTET_HHMISS(p,iLen,po);
}
int STARTDATE_TBCD_STRING(char *p, int iLen,void *po)
{
	if(iLen<3||iLen>4) return -1;
	if(iLen==3) return TBCD_YYMMDD(p,iLen,po);
	return TBCD_YYYYMMDD(p,iLen,po);
}
int STARTTIME_TBCD_STRING(char *p, int iLen,void *po)
{
	return TBCD_HHMISS(p,iLen,po);
}
int HexStrToInt(char sTemp[])
{
	static int iFirstFlag=TRUE,aiAnti[256];
	int i,j,iRet=0,iLen;
	unsigned char *p=(unsigned char*)sTemp;
	
	if(iFirstFlag==TRUE){
		iFirstFlag=FALSE;
		for(i=0;i<256;i++){
			switch(i){
			case 'a':
			case 'A':aiAnti[i]=10;break;
			case 'b':
			case 'B':aiAnti[i]=11;break;
			case 'c':
			case 'C':aiAnti[i]=12;break;
			case 'd':
			case 'D':aiAnti[i]=13;break;
			case 'e':
			case 'E':aiAnti[i]=14;break;
			case 'f':
			case 'F':aiAnti[i]=15;break;
			
			default :aiAnti[i]=0;			
			}
			if(i>='0'&&i<='9') aiAnti[i]=i-'0';	
		}
	}
	iLen=strlen(sTemp);
	
	if(iLen==0||iLen>8) return 0;
	
	for(i=0;i<iLen;i++){
		j=aiAnti[ p[i] ];
		iRet=iRet*16+j;
	}
	
	return iRet;
}
int BinStrToInt(char sTemp[])
{
	int iRet=0,i;
	for(i=0;i<strlen(sTemp);i++)
		iRet=iRet*2+sTemp[i]-'1';
	return iRet;
}

struct AsnStruct *CompileAsnOff(char sTag[])
{
	int iTag;
	char *c,*t,sTemp[10];
	struct AsnStruct *pTemp,*ptHead=NULL;

	t=sTag;

	while(1){
		
		c=strchr(t,':');
		
		if(c!=NULL){
			strncpy(sTemp,t,c-t);
			sTemp[c-t]=0;
		}
		else
			strcpy(sTemp,t);
			
		iTag=HexStrToInt(sTemp);
		
		if((pTemp=(struct AsnStruct*)malloc(sizeof(struct AsnStruct)))==NULL)
			return NULL;

		pTemp->iTag=iTag;
		pTemp->iTagType=0;
		pTemp->pNext=NULL;

		InsertList((LIST**)&ptHead,(LIST*)pTemp);
		
		if(c==NULL) break;

		t=c+1;/*跳过':'*/
	}
	
	ReverseList((LIST**)&ptHead);

	return ptHead;
}

int GET_ASN_POS(char *pi,char *p,struct PositionStruct *po)
{
	char	*t;
	int 	iForm,iTag,iTagBytes,iLenBytes,iDataBytes,iErrCode=0;
	struct AsnStruct *ptHead=(struct AsnStruct *)p;
	
	po->pData=NULL;
	po->iOffset=-1;
	po->iLen=-1;
	
	if(SearchTagItem(pi,ptHead,&t,2048,&iErrCode)==NOTFOUND)
		return 0;
	
	if(iErrCode!=0) return 0;
	
	iTagBytes=DecodeTagItem((unsigned char *)t,&iForm,&iTag,&iErrCode);
	if(iErrCode!=0) return 0;
	
	iLenBytes=DecodeLenItem((unsigned char *)t+iTagBytes,&iDataBytes);

	po->pData=	pi;
	po->iLen=	iDataBytes;
	po->iOffset=	t-pi+iTagBytes+iLenBytes;
	
	return 0;
}
struct ParamStruct *CompileFixOff(char sInput[])
{
	char *pc,sTemp[128];
	struct ParamStruct *pTemp;

	strcpy(sTemp,sInput);
	if((pc=strchr(sTemp,':'))==NULL) return NULL;
	
	*pc=0;	/*删除:*/
	pc++;
	
	if((pTemp=(struct ParamStruct *)
		malloc(sizeof(struct ParamStruct)))==NULL)
		return NULL;
	memset((void*)pTemp,0,sizeof(struct ParamStruct ));
	
	pTemp->d1=atoi(sTemp);
	pTemp->d2=atoi(pc);
	
	return pTemp;
}
struct ParamStruct *CompileSepOff(char sInput[])
{
	char *pc,sTemp[128];
	struct ParamStruct *pTemp;

	strcpy(sTemp,sInput);
	if((pc=strchr(sTemp,':'))==NULL) return NULL;
	
	*pc=0;	/*删除:*/
	pc++;
	
	if((pTemp=(struct ParamStruct *)
		malloc(sizeof(struct ParamStruct)))==NULL)
		return NULL;
	memset((void*)pTemp,0,sizeof(struct ParamStruct ));
	
	pTemp->d1=atoi(sTemp);
	if(*pc=='t')
		pTemp->d2='\t';
	else if(*pc=='b')
		pTemp->d2=' ';
	else if(*pc=='n')
		pTemp->d2='\n';
	else
		pTemp->d2=*pc;
	
	return pTemp;
}
struct ParamStruct *CompileTabOff(char sInput[])
{
	char sTemp[128];
	struct ParamStruct *pTemp;

	strcpy(sTemp,sInput);
	
	if((pTemp=(struct ParamStruct *)
		malloc(sizeof(struct ParamStruct)))==NULL)
		return NULL;
	memset((void*)pTemp,0,sizeof(struct ParamStruct ));
	
	pTemp->d1=atoi(sTemp);

	return pTemp;
}
int GET_FIX_POS(char *pi,char *p,struct PositionStruct *po)
{
	struct ParamStruct *pTemp=(struct ParamStruct*)p;
	po->pData=	pi;
	po->iOffset=	pTemp->d1;
	po->iLen=	pTemp->d2;
	
	return 0;
}
int GET_SEP_POS(char *pi,char *p,struct PositionStruct *po)
{
	char	*pc,*pt;
	int	i,c;
	struct ParamStruct *pTemp=(struct ParamStruct*)p;
	
	po->pData=NULL;
	po->iOffset=-1;
	po->iLen=-1;
	
	i=pTemp->d1;	
	c=pTemp->d2;
	pc=pi;
	
	while(i>0){
		if((pc=strchr(pc,c))==NULL) return -1;
		pc++;	/*跳过分割符*/
		i--;
	}
	
	if((pt=strchr(pc,c))==NULL){
		if((pt=strchr(pc,'\n'))==NULL)
			po->iLen=strlen(pc);
		else
			po->iLen=pt-pc;
	}
	else
		po->iLen=pt-pc;
	po->iOffset=pc-pi;
	po->pData=	pi;
	
	return 0;
}
int GET_TAB_POS(char *pi,char *p,struct PositionStruct *po)
{
	char	*pc,*pt;
	int	i;
	struct ParamStruct *pTemp=(struct ParamStruct*)p;
	
	po->pData=NULL;
	po->iOffset=-1;
	po->iLen=-1;
	
	i=pTemp->d1;
	pc=pi;
	/*跳过空格和TAB*/
	while((*pc)==' '||(*pc)=='\t') pc++;
	
	while(i>0){
		/*跳过双引号字段*/
		if((*pc)=='\"'){
			pc++;/*跳过第一个引号*/
			while((*pc)!='\"'){
				if((*pc)==0||(*pc)=='\n') return -1;
				pc++;
			}
			pc++;/*跳过第二个引号*/
		}
		else{
			/*跳过字段*/	
			while((*pc)!=' '&&(*pc)!='\t'){
				if((*pc)==0||(*pc)=='\n') return -1;
				pc++;
			}
		}
		/*跳过空格和TAB*/
		while((*pc)==' '||(*pc)=='\t') pc++;

		i--;
	}
	
	pt=pc;
	if((*pc)=='\"'){
		pc++;/*跳过第一个引号*/
		while((*pc)!='\"'){
			if((*pc)==0||(*pc)=='\n') return -1;
			pc++;
		}
		pc++;/*跳过第二个引号*/
	}
	else{
		while((*pc)!=' '&&(*pc)!='\t'){
			if((*pc)==0||(*pc)=='\n') break;
			pc++;
		}
	}
	
	po->pData=	pi;
	po->iLen=pc-pt;
	po->iOffset=pt-pi;
	
	return 0;
}

void GetTabStr(char sInput[],int iOffset,char sOutput[])
{
	struct ParamStruct P;
	struct PositionStruct Pos;
	
	strcpy(sOutput,"");

	P.d1=iOffset;P.d2=0;
	if(GET_TAB_POS(sInput,(char*)&P,&Pos)<0) return;

	strncpy(sOutput,Pos.pData+Pos.iOffset,Pos.iLen);
	sOutput[Pos.iLen]=0;
}
void GetSepStr(char sInput[],char cSep,int iOffset,char sOutput[])
{
	struct ParamStruct P;
	struct PositionStruct Pos;

	strcpy(sOutput,"");

	P.d1=iOffset;P.d2=(int)cSep;
	if(GET_SEP_POS(sInput,(char*)&P,&Pos)<0) return;

	strncpy(sOutput,Pos.pData+Pos.iOffset,Pos.iLen);
	sOutput[Pos.iLen]=0;
}
void GetFixStr(char sInput[],int iOffset,int l,char sOutput[])
{
	strncpy(sOutput,sInput+iOffset,l);sOutput[l]=0;
}

int AssignMemchar2Varchar(char **ppr,char *p1,int l1)
{
	int lr,lr1;
	char sTemp[5],*pr;

	if(p1==NULL) return 0;

	pr=*ppr;

	lr=GetVarcharLen(pr);

	if(lr>=l1){
		memcpy(GetVarcharData(pr),p1,l1);
		return 0;
	}

	lr=l1;
	lr1=GenVarcharLen(lr,(unsigned char*)sTemp);
	
	if((pr=realloc(pr,lr+lr1))==NULL) return -1;
	
	memcpy((void*)pr,(void*)sTemp,lr1);
	memcpy((void*)(pr+lr1),p1,l1);
	
	*ppr=pr;
	
	return 0;
}
int AssignStrchar2Varchar(char **ppr,char *p1)
{
	int lr,lr1,l1;
	char *pr=*ppr;

	if(p1==NULL) return 0;

	lr=GetVarcharLen(pr);
	l1=strlen(p1)+1;

	if(lr>=l1){
		strcpy(GetVarcharData(pr),p1);
		return 0;
	}

	lr=SupposeVarcharLen(l1);
	if((pr=realloc(pr,lr))==NULL) return -1;

	lr1=GenVarcharLen(lr,(unsigned char*)pr);
	strcpy(pr+lr1,p1);
	
	*ppr=pr;

	return 0;
}
int AssignV2VStrchar(char **ppr,char *p1)
{
	int lr,lr1,l1;
	char *pdr,*pd1;
	char *pr=*ppr;

	if(p1==NULL){
		if(pr!=NULL){
			pdr=GetVarcharData(pr);
			strcpy(pdr,"");
		}
		return 0;
	}

	lr=GetVarcharLen(pr);
	l1=GetVarcharStrlen(p1)+1;

	if(lr>=l1){
		pdr=GetVarcharData(pr);
		pd1=GetVarcharData(p1);
		strcpy(pdr,pd1);
		return 0;
	}
	lr=SupposeVarcharLen(l1);
	
	if(pr==NULL) pr=(char*)malloc(lr);
	else	pr=(char*)realloc(pr,lr);

	if(pr==NULL) return -1;

	lr1=GenVarcharLen(lr,(unsigned char*)pr);
	strcpy(pr+lr1,GetVarcharData(p1));
	
	*ppr=pr;

	return 0;
}
int AddV2VStrchar(char **ppr,char *p1,char *p2)
{
	int lr,lr1,l1,l2;
	char *pdr,*pd1,*pd2;
	char *pr=*ppr;

	if(p1==NULL) return AssignV2VStrchar(ppr,p2);
	if(p2==NULL) return AssignV2VStrchar(ppr,p1);

	lr=GetVarcharLen(pr);
	
	l1=GetVarcharStrlen(p1)+1;
	l2=GetVarcharStrlen(p2)+1;

	if(lr>=(l1+l2-1)){
		pdr=GetVarcharData(pr);
		pd1=GetVarcharData(p1);
		pd2=GetVarcharData(p2);
		if(pdr!=pd2){
			strcpy(pdr,pd1);
			strcat(pdr,pd2);
		}
		else{
			char sTemp[256];

			strcpy(sTemp,pd1);
			strcat(sTemp,pd2);
			strcpy(pdr,sTemp);
		}
		return 0;
	}
	lr=SupposeVarcharLen(l1+l2-1);
	if((pr=realloc(pr,lr))==NULL) return -1;

	lr1=GenVarcharLen(lr,(unsigned char*)pr);
	strcpy(pr+lr1,GetVarcharData(p1));
	strcat(pr+lr1,GetVarcharData(p2));
	
	*ppr=pr;

	return 0;
}
int AssignV2VMemchar(char **ppr,char *p1)
{
	int lr,l1;
	char *pr=*ppr;

	if(p1==NULL) return 0;

	lr=GetVarcharLen(pr);
	l1=GetVarcharLen(p1);
	
	if(lr==0){
		lr=GetVarcharSize(p1);
		if((pr=malloc(lr))==NULL) return -1;
		
		memcpy((void*)pr,(void*)p1,lr);
		
		*ppr=pr;
		
		return 0;
	}
	if(lr==l1) memcpy((void*)pr,(void*)p1,GetVarcharSize(p1));
	
	return 0;
}
char *MallocVarchar(int l)
{
	int l1;
	char *p,sTemp[5];

	l1=GenVarcharLen(l,(unsigned char*)sTemp);
	if((p=malloc(l+l1))==NULL) return NULL;
	memcpy((void*)p,(void*)sTemp,l1);
	p[l1]=0;
	return p;
}
int GenVarcharLen(int l,unsigned char sTemp[5])
{
	*((int*)sTemp)=l;
	return sizeof(int);
}
int GenVarcharByStrchar(char sInput[],char sOutput[])
{
	int l1,l;
	char sTemp[5];

	l=strlen(sInput)+1;
	l1=GenVarcharLen(l,(unsigned char*)sTemp);
	
	memcpy((void*)sOutput,(void*)sTemp,l1);
	strncpy((void*)(sOutput+l1),(void*)sInput,l);
	
	return l+l1;
}
int GenVarcharByMemchar(char sInput[],int l,char sOutput[])
{
	int l1;
	char sTemp[5];

	l1=GenVarcharLen(l,(unsigned char*)sTemp);
	
	memcpy((void*)sOutput,(void*)sTemp,l1);
	memcpy((void*)(sOutput+l1),(void*)sInput,l);
	
	return l+l1;
}
char *GetVarcharData(char *p)
{
	if(p==NULL) return NULL;
	return p+sizeof(int);
}
int GetVarcharLen(char *p)
{
	if(p==NULL) return 0;
	return *((int*)p);
}
int GetVarcharStrlen(char *p)
{
	if(p==NULL) return 0;
	return strlen(GetVarcharData(p));
}
int GetVarcharSize(char *p)
{	
	if(p==NULL) return 0;
	return *((int*)p)+sizeof(int);
}

int GenAsncharLen(int l,unsigned char sTemp[5])
{
	if(l<0x7f){
		sTemp[0]=l;
		return 1;
	}
	if(l<0xff){
		sTemp[0]=0x81;
		sTemp[1]=l;
		return 2;
	}
	if(l<0xffff){
		sTemp[0]=0x82;
		sTemp[1]=l/0x100;
		sTemp[2]=l%0x100;
		return 3;
	}
	if(l<0xffffff){
		sTemp[0]=0x83;
		sTemp[1]=l/0x10000;
		sTemp[2]=(l%0x10000)/0x100;
		sTemp[3]=l%0x100;
		return 4;
	}
	sTemp[0]=0x84;
	sTemp[1]=l/0x1000000;
	sTemp[2]=(l%0x1000000)/0x10000;
	sTemp[3]=(l%0x10000)/0x100;
	sTemp[4]=l%0x100;
	return 5;
}
int GenAsncharByStrchar(char sInput[],char sOutput[])
{
	int l1,l;
	char sTemp[5];

	l=strlen(sInput)+1;
	l1=GenAsncharLen(l,(unsigned char*)sTemp);
	
	memcpy((void*)sOutput,(void*)sTemp,l1);
	strncpy((void*)(sOutput+l1),(void*)sInput,l);
	
	return l+l1;
}
char *GetAsncharData(char *p)
{
	int i;
	
	if(p==NULL) return NULL;

	return p+DecodeLenItem((unsigned char*)p,&i);
}
int GetAsncharLen(char *p)
{
	int i,i1;
	
	if(p==NULL) return 0;

	i1=DecodeLenItem((unsigned char*)p,&i);
	return i;
}
int GetAsncharStrlen(char *p)
{
	if(p==NULL) return 0;
	return strlen(GetAsncharData(p));
}
int GetAsncharSize(char *p)
{
	int i,i1;
	
	if(p==NULL) return 0;

	i1=DecodeLenItem((unsigned char*)p,&i);
	return i+i1;
}

/*推测VARCHAR的长度*/
int SupposeVarcharLen(int l)
{
	if(l<=(DEF_STR_LEN-sizeof(int))) return DEF_STR_LEN+1;
	
	if(l<DEF_STR_LEN*2) return l+DEF_STR_LEN/2+1;
	
	return l+DEF_STR_LEN;
}

void GetTabStrX(char sInput[],int iOffset,int iMaxLen,char sOutput[])
{
	int l;
	char sTemp[2048];
	
	GetTabStr(sInput,iOffset,sTemp);
	l=strlen(sTemp);
	if(iMaxLen<l) l=iMaxLen;

	strncpy(sOutput,sTemp,l);sOutput[l]=0;
	AllTrim(sOutput);
}
void GetSepStrX(char sInput[],char cSep,int iOffset,int iMaxLen,char sOutput[])
{
	int l;
	char sTemp[2048];
	
	GetSepStr(sInput,cSep,iOffset,sTemp);
	l=strlen(sTemp);
	if(iMaxLen<l) l=iMaxLen;

	strncpy(sOutput,sTemp,l);sOutput[l]=0;
	AllTrim(sOutput);
}
void GetFixStrX(char sInput[],int iOffset,int l,char sOutput[])
{
	strncpy(sOutput,sInput+iOffset,l);sOutput[l]=0;
	AllTrim(sOutput);
}
int GET_SEP_CNT(char sRecord[],char c)
{
	char	*pc;
	int	i=0;
	
	pc=sRecord;
	
	if(*pc==0) return 0;
	
	while(1){
		if((pc=strchr(pc,c))==NULL) break;
		pc++;	/*跳过分割符*/
		i++;
	}
	return i+1;
}

int GET_TAB_CNT(char sRecord[])
{
	char	*pc;
	int	i=0;

	pc=sRecord;

	if(*pc==0) return 0;
	
	/*跳过空格和TAB*/
	while((*pc)==' '||(*pc)=='\t') pc++;
	
	while(1){
		/*跳过双引号字段*/
		if((*pc)=='\"'){
			pc++;/*跳过第一个引号*/
			while((*pc)!='\"'){
				if((*pc)==0||(*pc)=='\n') return -1;
				pc++;
			}
			pc++;/*跳过第二个引号*/
		}
		else{/*跳过字段*/
			while((*pc)!=' '&&(*pc)!='\t'){
				if((*pc)==0||(*pc)=='\n')break;
				pc++;
			}
		}
		if((*pc)==0||(*pc)=='\n') break;

		i++;
		/*跳过空格和TAB*/
		while((*pc)==' '||(*pc)=='\t') pc++;
	}
		
	return i+1;
}
int IsAllDigit(char sTemp[])
{
	char c;
	
	int i,l=strlen(sTemp);
	
	for(i=0;i<l;i++){

		c=sTemp[i];
		
		if(!(c>='0'&&c<='9')) return false;
	}
	return true;
}
int IsAllHex(char sTemp[])
{
	char c;
	
	int i,l=strlen(sTemp);
	
	for(i=0;i<l;i++){

		c=sTemp[i];
		
		if(!((c>='0'&&c<='9')||
			(c>='a'&&c<='f')||
			(c>='A'&&c<='F'))) return false;
	}
	return true;
}

/*****************************************/
/*********DECODE函数封装******************/
/*****************************************/
char *GetDecodeStr(char sInput[],char sOutput[])
{
	char *pc;
	if((pc=strchr(sInput,':'))==NULL){
		strcpy(sOutput,sInput);
		return NULL;
	}
	strncpy(sOutput,sInput,pc-sInput);
	sOutput[pc-sInput]=0;
	pc++;/*跳过:*/
	return pc;
}
struct DecodeParamStruct *GetDecodeParam(char sInput1[],char sInput2[])
{
	struct DecodeParamStruct *pTemp;

	if((pTemp=(struct DecodeParamStruct *)
		malloc(sizeof(struct DecodeParamStruct)))==NULL)
		return NULL;
	memset((void*)pTemp,0,sizeof(struct DecodeParamStruct));

	if(sInput2[0]=='\''){
		pTemp->cType2=VARTYPE_STR;
		strncpy(pTemp->d2.sValue,sInput2+1,strlen(sInput2)-2);
		pTemp->d2.sValue[strlen(sInput2)-2]=0;
	}
	else{
		pTemp->cType2=VARTYPE_INT;
		if(strncmp(sInput2,"0x",2)==0||
			strncmp(sInput2,"0X",2)==0)
			pTemp->d2.iValue=HexStrToInt(sInput2+2);
		else if(strncmp(sInput2,"0b",2)==0||
			strncmp(sInput2,"0B",2)==0)
			pTemp->d2.iValue=BinStrToInt(sInput2+2);
		else
			pTemp->d2.iValue=atoi(sInput2);
	}
	if(strlen(sInput1)==0){
		pTemp->cType1=0;
		return pTemp;
	}
	if(sInput1[0]=='\''){
		pTemp->cType1=VARTYPE_STR;
		strncpy(pTemp->d1.sValue,sInput1+1,strlen(sInput1)-2);
		pTemp->d1.sValue[strlen(sInput1)-2]=0;
	}
	else{
		pTemp->cType1=VARTYPE_INT;
		if(strncmp(sInput1,"0x",2)==0||
			strncmp(sInput1,"0X",2)==0)
			pTemp->d1.iValue=HexStrToInt(sInput1+2);
		else if(strncmp(sInput1,"0b",2)==0||
			strncmp(sInput1,"0B",2)==0)
			pTemp->d1.iValue=BinStrToInt(sInput1+2);
		else
			pTemp->d1.iValue=atoi(sInput1);
	}

	return pTemp;
}
void DestroyDecodeParam(struct DecodeParamStruct *ptHead)
{
	struct DecodeParamStruct *pTemp;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		free(pTemp);
	}
}
struct DecodeParamStruct *ParamDecode(char sInput[])
{

	char *pPre,*pCur,sPre[128],sCur[128];
	struct DecodeParamStruct *ptHead=NULL,*pTemp;

	pPre=sInput;
	pCur=GetDecodeStr(pPre,sPre);
	while(pCur!=NULL){
		pPre=GetDecodeStr(pCur,sCur);
		if((pTemp=GetDecodeParam(sPre,sCur))==NULL){
			DestroyDecodeParam(ptHead);
			return NULL;
		}
		InsertList((LIST**)&ptHead,(LIST*)pTemp);
		if(pPre==NULL) break;
		pCur=GetDecodeStr(pPre,sPre);
	}
	if(pCur==NULL){
		/*这里生成DECODE最后一项*/
		if((pTemp=GetDecodeParam("",sPre))==NULL){
			DestroyDecodeParam(ptHead);
			return NULL;
		}
		InsertList((LIST**)&ptHead,(LIST*)pTemp);
	}
	/*将链表倒换*/
	ReverseList((LIST**)&ptHead);
	return ptHead;
}

int checki2i(struct DecodeParamStruct *ptHead )
{
	while(ptHead!=NULL){
		if((ptHead->cType1!=0&&ptHead->cType1!=VARTYPE_INT)||
			ptHead->cType2!=VARTYPE_INT) return -1;
		ptHead=ptHead->pNext;
	}
	return 0;
}
int checki2s(struct DecodeParamStruct *ptHead )
{
	while(ptHead!=NULL){
		if((ptHead->cType1!=0&&ptHead->cType1!=VARTYPE_INT)||
			ptHead->cType2!=VARTYPE_STR) return -1;
		ptHead=ptHead->pNext;
	}
	return 0;
}
int checks2i(struct DecodeParamStruct *ptHead )
{
	while(ptHead!=NULL){
		if((ptHead->cType1!=0&&ptHead->cType1!=VARTYPE_STR)||
			ptHead->cType2!=VARTYPE_INT) return -1;
		ptHead=ptHead->pNext;
	}
	return 0;
}
int checks2s(struct DecodeParamStruct *ptHead )
{
	while(ptHead!=NULL){
		if((ptHead->cType1!=0&&ptHead->cType1!=VARTYPE_STR)||
			ptHead->cType2!=VARTYPE_STR) return -1;
		ptHead=ptHead->pNext;
	}
	return 0;
}
struct DecodeParamStruct *CompileI2I(char sInput[])
{
	struct DecodeParamStruct *ptHead;

	if((ptHead=ParamDecode(sInput))==NULL) return NULL;
	if(checki2i(ptHead)<0){
		DestroyDecodeParam(ptHead);
		return NULL;
	}
	return ptHead;
}
struct DecodeParamStruct *CompileI2S(char sInput[])
{
	struct DecodeParamStruct *ptHead;

	if((ptHead=ParamDecode(sInput))==NULL) return NULL;
	if(checki2s(ptHead)<0){
		DestroyDecodeParam(ptHead);
		return NULL;
	}
	return ptHead;
}
struct DecodeParamStruct *CompileS2I(char sInput[])
{
	struct DecodeParamStruct *ptHead;

	if((ptHead=ParamDecode(sInput))==NULL) return NULL;
	if(checks2i(ptHead)<0){
		DestroyDecodeParam(ptHead);
		return NULL;
	}
	return ptHead;
}

struct DecodeParamStruct *CompileS2S(char sInput[])
{
	struct DecodeParamStruct *ptHead;

	if((ptHead=ParamDecode(sInput))==NULL) return NULL;
	if(checks2s(ptHead)<0){
		DestroyDecodeParam(ptHead);
		return NULL;
	}
	return ptHead;
}
int decodei2i(struct DecodeParamStruct *ptHead, int i,char *po)
{
	int *piOut=(int*)po;

	while(ptHead!=NULL){
		/*处理最后一项*/
		if(ptHead->cType1==0||i==ptHead->d1.iValue){
			*piOut=ptHead->d2.iValue;
			return 0;
		}
		ptHead=ptHead->pNext;
	}
	*piOut= i;
	return 0;
}
int decodei2s(struct DecodeParamStruct *ptHead, int i,char *po)
{
	while(ptHead!=NULL){
		/*处理最后一项*/
		if(ptHead->cType1==0||i==ptHead->d1.iValue){
			strcpy(po,ptHead->d2.sValue);
			return 0;
		}
		ptHead=ptHead->pNext;
	}
	strcpy(po,"");
	return 0;
}
int decodes2i(struct DecodeParamStruct *ptHead, char *pi,char *po)
{
	int *piOut=(int*)po;

	while(ptHead!=NULL){
		/*处理最后一项*/
		if(ptHead->cType1==0||
			strcmp(pi,ptHead->d1.sValue)==0){
			*piOut=ptHead->d2.iValue;
			return 0;
		}
		ptHead=ptHead->pNext;
	}
	*piOut= 0;
	return 0;
}

int decodes2s(struct DecodeParamStruct *ptHead, char *pi,char *po)
{

	while(ptHead!=NULL){
		/*处理最后一项*/
		if(ptHead->cType1==0||
			strcmp(pi,ptHead->d1.sValue)==0){
			strcpy(po,ptHead->d2.sValue);
			return 0;
		}
		ptHead=ptHead->pNext;
	}
	strcpy(po,"");
	return 0;
}

int innum(struct DecodeParamStruct *ptHead, int i,char *po)
{
	int *piOut=(int*)po;

	*piOut=0;

	while(ptHead!=NULL){

		if(i==ptHead->d2.iValue){
			*piOut=1;
			break;
		}
		if(ptHead->cType1!=0&&i==ptHead->d1.iValue){
			*piOut=1;
			break;
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}
int instr(struct DecodeParamStruct *ptHead, char sTemp[],char *po)
{
	int *piOut=(int*)po;

	*piOut=0;

	while(ptHead!=NULL){

		if(strcmp(sTemp,ptHead->d2.sValue)==0){
			*piOut=1;
			break;
		}
		if(ptHead->cType1!=0&&
			strcmp(sTemp,ptHead->d1.sValue)==0){
			*piOut=1;
			break;
		}
		ptHead=ptHead->pNext;
	}
	return 0;
}

int ChkBlkFmtPrm(char sInput[],char sHead[],char sBody[],char sTail[])
{
	int iCnt=0,ioffset1,ioffset2;

	strcpy(sHead,"");
	strcpy(sBody,"");
	strcpy(sTail,"");

	iCnt=GetSepCnt(sInput,':');

	if(iCnt==0) return 0;

	if(iCnt<3){
		printf("Fmt参数必须满足x:$(YYY):z模式,YYY可能包行':'");
		return -1;
	}
	GetSepStrX(sInput,':',0,20,sHead);
	GetSepStrX(sInput,':',iCnt-1,20,sTail);
	
	ioffset1=GetSepOff(sInput,':',1);
	ioffset2=GetSepOff(sInput,':',iCnt-1);
	
	strncpy(sBody,sInput+ioffset1,ioffset2-ioffset1-1);
	sBody[ioffset2-ioffset1-1]=0;
	AllTrim(sBody);

	return 0;
}
int ChkFileFmtPrm(char sInput[],char sRec[],char sBlk[])
{
	int iCnt=0;

	strcpy(sRec,"");
	strcpy(sBlk,"");

	iCnt=GetSepCnt(sInput,'#');

	if(iCnt==0) return 0;

	if(iCnt!=1&&iCnt!=2){
		printf("Fmt参数必须满足x#y模式");
		return -1;
	}
	if(iCnt==2) GetSepStrX(sInput,'#',1,80,sBlk);
	
	GetSepStrX(sInput,'#',0,80,sRec);
	
	return 0;
}
int InitBlkFmt(char sHead[],char sBody[],char sTail[],
	struct BlkFmtStruct *p)
{
	int i;
	char *pc,sPos[80],sPrm[80],sTemp[80];

	if(IsAllDigit(sHead)==false){
		printf("head必须为全数字\n");
		return -1;
	}
	p->iHeadLen=atoi(sHead);

	if(IsAllDigit(sTail)==false){
		printf("head必须为全数字\n");
		return -1;
	}
	p->iTailLen=atoi(sTail);

	if((IsAllDigit(sBody)==true)||
		(sBody[0]=='-'&&IsAllDigit(sBody+1)==true)){
		p->iRecLen=atoi(sBody);
		return 0;
	}

	p->iRecLen=-1;

	
	if(!LikeX(sBody,"[h,l,H,L]{*}")&&
		!LikeX(sBody,"{*}")&&
		!LikeX(sBody,"[h,l,H,L]{*}<*>")&&
		!LikeX(sBody,"{*}<*>")){
		printf("body格式必须[h,l,H,L]{*},{*},[h,l,H,L]{*}<*>,{*}<*>\n");
		return -1;
	}
	/*默认是h开头的参数*/
	if(LikeX(sBody,"{*}")||
		LikeX(sBody,"{*}<*>")){
		strcpy(sTemp,"h");
		strcat(sTemp,sBody);
		strcpy(sBody,sTemp);
	}

	/*得到GetLen参数*/
	if(sBody[0]=='h'||sBody[0]=='H')
		p->GetLen=hmem2int4b;
	else	p->GetLen=lmem2int4b;
	
	if(sBody[0]=='H'||sBody[0]=='L') p->iLenInHd=1;

	strcpy(sPos,"");
	strcpy(sPrm,"");

	if((pc=strstr(sBody,"}<"))!=NULL){
		strncpy(sPrm,pc+2,strlen(pc+2)-1);
		sPrm[strlen(pc+2)-1]=0;
	}
	else{
		if((pc=strstr(sBody,"}"))==NULL){
			printf("程序逻辑错误.\n");
			return -1;
		}
	}
	
	strncpy(sPos,sBody+2,pc-(sBody+2));
	sPos[pc-(sBody+2)]=0;

	/*将逗号替换为':'*/
	for(i=0;i<strlen(sPos);i++) if(sPos[i]==',') sPos[i]=':';
	for(i=0;i<strlen(sPrm);i++) if(sPrm[i]==',') sPrm[i]=':';

	if(GetSepCnt(sPos,':')!=2){
		printf("body 模式[h,l]{x}<y>,x必须为a:b,但为%s",sPos);
		return -1;
	}
	GetSepStrX(sPos,':',0,80,sTemp);p->iLenOff=atoi(sTemp);
	GetSepStrX(sPos,':',1,80,sTemp);p->iLenLen=atoi(sTemp);

	if(strlen(sPrm)==0) return 0;

	if((p->pParam=ParamDecode(sPrm))==NULL){
		printf("body 模式[h,l]{x}<y>,y必须为a:b...,但为%s",sPrm);
		return -1;
	}
	if(checki2i(p->pParam)<0){
		printf("body 模式[h,l]{x}<y>,y必须为a:b...,但为%s",sPrm);
		return -1;
	}
	return 0;
}
int CompileFileFormat(struct FileFormatStruct *p)
{
	char *pc;
	char sRec[80],sBlk[80],sHead[20],sTail[20],sBody[80],sInput[256];

	pc=p->sFormat;

	/*拿到file_type串*/
	while((*pc)!=0){
		if(((*pc)>='0'&&(*pc)<='9')||(*pc)=='#') break;
		pc++;
	}
	
	strncpy(p->sFileType,p->sFormat,pc-p->sFormat);
	p->sFileType[pc-p->sFormat]=0;

	if(strcmp(p->sFormat,"asn")==0)
		strcat(p->sFormat,"#0:2048:0");

	/*拿到整个格式参数*/
	strcpy(sInput,pc);

	/*文本格式特殊处理*/
	if(strcmp(p->sFileType,"txt")==0){
		if(strcmp(p->sFormat,"txt")!=0&&
			strcmp(p->sFormat,"txt0:0")!=0&&
			strcmp(p->sFormat,"txt0:1")!=0&&
			strcmp(p->sFormat,"txt1:0")!=0&&
			strcmp(p->sFormat,"txt1:1")!=0){
			printf("txt只支持txt,txt0:0,txt0:1,txt1:0,txt1:1"
				"格式,实际为%s\n",p->sFormat);
			return -1;
		}
		strcpy(sInput,"");
	}

	if(ChkFileFmtPrm(sInput,sRec,sBlk)<0) return -1;

	if(strlen(sRec)!=0){

		if(ChkBlkFmtPrm(sRec,sHead,sBody,sTail)<0) return -1;

		if(InitBlkFmt(sHead,sBody,sTail,&p->Rec)<0) return -1;
	}

	p->Blk.iHeadLen=-1;/*表示Blk无效*/

	if(strlen(sBlk)!=0){
		if(ChkBlkFmtPrm(sBlk,sHead,sBody,sTail)<0) return -1;

		if(InitBlkFmt(sHead,sBody,sTail,&p->Blk)<0) return -1;
	}

	return 0;
}

void Fmt86A13(char sTemp[])
{
        if(LLike(sTemp,"0086")==true)strcpy(sTemp,sTemp+4);
        if(LLike(sTemp,"086")&&strlen(sTemp)>9) strcpy(sTemp,sTemp+3);
        if(LLike(sTemp,"86")&&strlen(sTemp)>9) strcpy(sTemp,sTemp+2);
	if(IS_MOB_NBR(sTemp)&&strlen(sTemp)==12&&sTemp[0]=='0')strcpy(sTemp,sTemp+1);
}
void Fmt86A13X(char sTemp[])
{
        if(LLike(sTemp,"0086")==true)strcpy(sTemp,sTemp+4);
        if(LLike(sTemp,"086")&&strlen(sTemp)>9) strcpy(sTemp,sTemp+3);
	if(IS_MOB_NBR(sTemp)&&strlen(sTemp)==12&&sTemp[0]=='0')strcpy(sTemp,sTemp+1);
}
int GetSepInt(char sInput[],char cSep,int iOffset)
{
	char sOutput[128];

	GetSepStr(sInput,cSep,iOffset,sOutput);
	return atoi(sOutput);
}
int GetTabInt(char sInput[],int iOffset)
{
	char sOutput[128];

	GetTabStr(sInput,iOffset,sOutput);
	return atoi(sOutput);
}
int GetFixInt(char sInput[],int iOffset,int len)
{
	char sOutput[128];

	GetFixStr(sInput,iOffset,len,sOutput);
	return atoi(sOutput);
}
int GetSepCnt(char sInput[],char cSep)
{
	return GET_SEP_CNT(sInput,cSep);
}
int GetTabCnt(char sInput[])
{
	return GET_TAB_CNT(sInput);
}
void ArgStrcpy(char sOutput[],char sInput[],int iMax)
{
	strncpy(sOutput,sInput,iMax);
	sOutput[iMax]=0;
	AllTrim(sOutput);
}
int IpV4Txt2HexStr(char sIp[],char sHex[])
{
	int i0,i1,i2,i3;
	char *pc,sTemp[100];

	strcpy(sHex,"00000000");

	strcpy(sTemp,sIp);pc=sTemp;

	i0=atoi(pc);
	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i1=atoi(pc);

	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i2=atoi(pc);

	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i3=atoi(pc);

	sprintf(sHex,"%02X%02X%02X%02X",i0,i1,i2,i3);

	return 0;
}
int IpV4HexStr2Txt(char sHex[],char sIp[])
{
	int i0,i1,i2,i3;
	char sTemp[8];

	strncpy(sTemp,sHex+0,2);sTemp[2]=0;i0=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+2,2);sTemp[2]=0;i1=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+4,2);sTemp[2]=0;i2=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+6,2);sTemp[2]=0;i3=HexStrToInt(sTemp);

	sprintf(sIp,"%d.%d.%d.%d",i0,i1,i2,i3);

	return 0;
}
int IpV6Txt2HexStr(char sIp[],char sHex[])
{
	int i0,i1,i2,i3,i4,i5;
	char *pc,sTemp[100];

	strcpy(sHex,"000000000000");

	strcpy(sTemp,sIp);pc=sTemp;

	i0=atoi(pc);
	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i1=atoi(pc);

	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i2=atoi(pc);

	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i3=atoi(pc);
	
	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i4=atoi(pc);
	
	if((pc=strchr(pc,'.'))==NULL) return 0;
	*pc=0;pc++;i5=atoi(pc);

	sprintf(sHex,"%02X%02X%02X%02X%02X%02X",i0,i1,i2,i3,i4,i5);

	return 0;
}
int IpV6HexStr2Txt(char sHex[],char sIp[])
{
	int i0,i1,i2,i3,i4,i5;
	char sTemp[8];

	strncpy(sTemp,sHex+0,2);sTemp[2]=0;i0=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+2,2);sTemp[2]=0;i1=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+4,2);sTemp[2]=0;i2=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+6,2);sTemp[2]=0;i3=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+8,2);sTemp[2]=0;i4=HexStrToInt(sTemp);
	strncpy(sTemp,sHex+10,2);sTemp[2]=0;i5=HexStrToInt(sTemp);

	sprintf(sIp,"%d.%d.%d.%d.%d.%d",i0,i1,i2,i3,i4,i5);

	return 0;
}

int GetSepOff(char sInput[],char cSep,int iOffset)
{
	struct ParamStruct P;
	struct PositionStruct Pos;


	P.d1=iOffset;P.d2=(int)cSep;
	if(GET_SEP_POS(sInput,(char*)&P,&Pos)<0) return -1;

	return Pos.iOffset;
}
int GetSepLen(char sInput[],char cSep,int iOffset)
{
	struct ParamStruct P;
	struct PositionStruct Pos;


	P.d1=iOffset;P.d2=(int)cSep;
	if(GET_SEP_POS(sInput,(char*)&P,&Pos)<0) return -1;

	return Pos.iLen;
}

int GetTabOff(char sInput[],int iOffset)
{
	struct ParamStruct P;
	struct PositionStruct Pos;
	
	P.d1=iOffset;P.d2=0;
	if(GET_TAB_POS(sInput,(char*)&P,&Pos)<0) return -1;

	return Pos.iOffset;
}

int GetTabLen(char sInput[],int iOffset)
{
	struct ParamStruct P;
	struct PositionStruct Pos;
	
	P.d1=iOffset;P.d2=0;
	if(GET_TAB_POS(sInput,(char*)&P,&Pos)<0) return -1;

	return Pos.iLen;
}

void FmtNbr(int type,char p1[],char sTemp[])
{
	if(type==1){
		if(strncmp(p1,"179",3)==0||
			strncmp(p1,"193",3)==0||
			(IS_MOB_NBR(p1)&&p1[0]=='1')||
			p1[0]=='0'){
			strcpy(sTemp,p1);
		}
		else{ 
			strcpy(sTemp,"0");
			strcat(sTemp,p1);
		}		
	}
	else if(type==2){
		if(strncmp(p1,"179",3)==0||
			strncmp(p1,"193",3)==0||
			strncmp(p1,"00",2)==0){
			strcpy(sTemp,p1);
		}
		else if(p1[0]=='0'){
			strcpy(sTemp,"0");
			strcat(sTemp,p1);
		}
		else{
			strcpy(sTemp,"00");
			strcat(sTemp,p1);
		}
	}
	else/* ie. type==0 */
		strcpy(sTemp,p1);
}
int ResetErr2Ori(char sRecordType[],char sErrRec[],char sOri[],int *piLen)
{
	if(sRecordType[0]=='B'){
		if(!IsAllHex(sErrRec)) return -1;
		*piLen=asc_hex2hbcd(sErrRec,(unsigned char*)sOri);
	}
	else{
		strcpy(sOri,sErrRec);
		*piLen=strlen(sErrRec);
	}
	return 0;
}
