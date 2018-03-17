#include <hnixs.h>
#include <wwlog.h>
#include <wwfile.h>

#define TYPE_LOG1		1
#define TYPE_LOG2		2
#define TYPE_MATH		3
#define TYPE_CONTROL		4
#define TYPE_CONST		5
#define TYPE_SYSVAR		6
#define TYPE_TEMPVAR		7
#define TYPE_SEPARATOR		8
#define TYPE_ASSIGN		9
#define TYPE_MATH1		10
#define TYPE_CONST_STR		11
#define TYPE_CONST_HEX		12
#define TYPE_CONST_DEC		13
#define TYPE_CONST_BIN		14
#define TYPE_CONST_DOUBLE	17
#define TYPE_CONST_LONG_STR	18/*长字符串*/
#define SYMBOL_LENGTH		255
#define SYMBOL_BUFLEN		100000

#define C_TYPEP		SymbolFlow[igSymPos-1].iType
#define C_TYPEN		SymbolFlow[igSymPos+1].iType
#define C_CVALUEP 	SymbolFlow[igSymPos-1].sValue[0]
#define C_CVALUEN 	SymbolFlow[igSymPos+1].sValue[0]
#define C_TYPE   	SymbolFlow[igSymPos].iType
#define C_SVALUE 	SymbolFlow[igSymPos].sValue
#define C_CVALUE 	SymbolFlow[igSymPos].sValue[0]
#define C_ORIPOS	SymbolFlow[igSymPos].iOriPos



#define ADDSYMBOLFLOW(a,b,c,d) {if(AddSymbolFlow(a,b,c,d)<0) return -1;}

struct ErrMsgStruct
{
	int iPos;
	char sMsg[1024];
};
struct ErrMsgStruct ErrMsg;

/*定义词法分析生成的符号流*/
struct SymbolStruct{
	char sValue[SYMBOL_LENGTH+1];
	int  iType;
	int  iOriPos;
};
int igSymCnt;   /*符号流长度*/
int igSymPos;   /*符号流当前指针*/
struct SymbolStruct SymbolFlow[SYMBOL_BUFLEN];

void ReportExprError(int iPos,char *fmt,...)
{
	int l;
	va_list	argptr;

	ErrMsg.iPos=	iPos;
	
	strcat(ErrMsg.sMsg,"\n");
	l=strlen(ErrMsg.sMsg);
	
	va_start(argptr, fmt);
	vsprintf(ErrMsg.sMsg+l,fmt,argptr);
	va_end(argptr);
}
void RegularConstStr(char sInput[])
{
	int i=0,j=0;
	char sTemp[16384];
	
	while(i<strlen(sInput)){

		if(strncmp(sInput+i,"\\\\",2)==0){
			sTemp[j++]= '\\';i+=2;
		}
		else if(strncmp(sInput+i,"\\a",2)==0){
			sTemp[j++]= '\a';i+=2;
		}
		else if(strncmp(sInput+i,"\\b",2)==0){
			sTemp[j++]= '\b';i+=2;
		}
		else if(strncmp(sInput+i,"\\f",2)==0){
			sTemp[j++]= '\f';i+=2;
		}
		else if(strncmp(sInput+i,"\\n",2)==0){
			sTemp[j++]= '\n';i+=2;
		}
		else if(strncmp(sInput+i,"\\r",2)==0){
			sTemp[j++]= '\r';i+=2;
		}
		else if(strncmp(sInput+i,"\\t",2)==0){
			sTemp[j++]= '\t';i+=2;
		}
		else if(strncmp(sInput+i,"\\v",2)==0){
			sTemp[j++]= '\v';i+=2;
		}
		else if(strncmp(sInput+i,"\\\"",2)==0){
			sTemp[j++]= '\"';i+=2;
		}
		else
			sTemp[j++]= sInput[i++];
	}
	sTemp[j]=0;
	strcpy(sInput,sTemp);
}
int GetSymType(char sSymbol[])
{

/*特殊处理：如果汉字则处理为常量*/
	if(sSymbol[0]&0x80) return TYPE_CONST;
	
	return TYPE_TEMPVAR;
}
int EncodingOriPos(int iOriPos)
{
	return iOriPos;
}
void DecodingOriPos(int iOriPos,int *piIndex,int *piOriPos)
{
	*piIndex=iOriPos/(256*256);
	*piOriPos=iOriPos%(256*256);
}
void GetLinePosInfo(char sInput[],int iOff,int *piLine,int *piPos)
{
	int i,iLine=1,iPos=0,j;

	for(i=0;i<iOff;i++){
		if(sInput[i]=='\n'){
			iLine++;
			iPos=i+1;
		}
	}
	i=iPos;j=0;
	while(i<iOff){
		if(sInput[i]!='\t') j++;
		else	j=(j+8)/8*8;
		i++;
	}
	iPos=j;
	*piLine=iLine;
	*piPos=iPos;	
}
void FormatExprErrorMsg(char sInput[])
{
	int iLine=0,iPos=0,i=0,j,l,iIndex,iOffset;
	char sLine[512],sLineBegin[512],sLineEnd[512],sPin[512];
	char sTemp[512];

	/*将错误位置解码*/
	DecodingOriPos(ErrMsg.iPos,&iIndex,&iOffset);
	
	GetLinePosInfo(sInput,iOffset,&iLine,&iPos);

	i=iOffset;j=0;
	while(sInput[i]!='\n'&&sInput[i]!=0)
		sLineEnd[j++]=sInput[i++];

	sLineEnd[j]=0;
		
	i=iOffset-1;j=0;
	while(sInput[i]!='\n'&&i>0)
		sLineBegin[j++]=sInput[i--];
	sLineBegin[j]=0;
	
	l=strlen(sLineBegin);
	for(i=0,j=0;i<l;i++)
		sLine[j++]=sLineBegin[l-i-1];
	sLine[j]=0;
	strcat(sLine,sLineEnd);
	
	strcpy(sTemp,ErrMsg.sMsg);
	for(i=0;i<iPos;i++) sPin[i]=' '; sPin[i++]='^';sPin[i]=0;
	sprintf(ErrMsg.sMsg,"%s\n%s\n位置:%d行%d列,%s",
		sLine,sPin,iLine,iPos+1,sTemp);
}
int AddSymbolFlow(char sInput[],int iOffset,int iLen,int iType)
{
	int i,j=0;
	char	sTemp[16384];
	
	if(iType==TYPE_CONST_STR){
		for(i=iOffset;i<iOffset+iLen;i++){
			/*unix下和dos下的字符常量内的序行支持*/
			if(strncmp(sInput+i,"\\\n",2)==0){i+=2;continue;}
			if(strncmp(sInput+i,"\\\r\n",3)==0){i+=3;continue;}
			sTemp[j++]=sInput[i];
		}
		sTemp[j]=0;
		if(sInput[iOffset]=='"') RegularConstStr(sTemp);
			
	}
	else{
		strncpy(sTemp,sInput+iOffset,iLen);
		sTemp[iLen]=0;
	}

	strcpy(C_SVALUE,sTemp);
	
	if(iType!=-1)	C_TYPE	=iType;
	else		C_TYPE	=GetSymType(sTemp);

	C_ORIPOS=	EncodingOriPos(iOffset+iLen-1);
	igSymPos++;
	if(igSymPos>=SYMBOL_BUFLEN){
		ReportExprError(iOffset,
			"系统错误->符号变量超过%d个",SYMBOL_BUFLEN);
		return -1;
	}
	return 0;
}
int ConstStringBegin(char c)
{
	if(c=='"'||c=='\'') return true;
	return false;
}
int ConstStringEnd(char c,char x)
{
	if(c==x) return true;
	return false;
}
int NewLine(char c)
{
	if(c=='\n'||c=='\r') return true;
	return false;
}
int JmpSeperator(char c)
{
	if(c==' '||c=='\t') return true;
	return false;
}
int StatementEnd(char c)
{
	if(c==';') return true;
	return false;
}
int WordEnd(char c)
{
	if(c==',') return true;
	return false;
}
int ExprEnd(char c)
{
	if(c==0) return true;
	return false;
}
int CommentCBegin(char c1,char c2)
{
	if(c1=='/'&&c2=='*') return true;
	return false;
}
int CommentCEnd(char c1,char c2)
{
	if(c1=='*'&&c2=='/') return true;
	return false;
}
int LexCComment(char sInput[],int *piPos)
{	
	int i=*piPos;
	
	if(CommentCBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->C注释->未匹配'*/'公式结束");
			return -1;
		}
		while(!CommentCEnd(sInput[i],sInput[i+1])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->C注释->未匹配'*/'公式结束");
				return -1;
			}
		}
		i+=2;
		*piPos=i;
		return true;
	}
	return false;
}
int CommentCppBegin(char c1,char c2)
{
	if(c1=='/'&&c2=='/') return true;
	return false;
}
int LexCppComment(char sInput[],int *piPos)
{
	int i=*piPos;
	
	if(CommentCppBegin(sInput[i],sInput[i+1])){
		i+=2;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->Cpp注释->公式结束");
			return -1;
		}
		while(!NewLine(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->Cpp注释->公式结束");
				return -1;
			}
		}
		i++; /*跳过回车*/
		*piPos=i;
		return true;
	}
	return false;
}
int CommentShBegin(char c)
{
	if(c=='#') return true;
	return false;
}
int LexShComment(char sInput[],int *piPos)
{	
	int i=*piPos;
	if(CommentShBegin(sInput[i])){
		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->#注释->公式结束");
			return -1;
		}
		while(!NewLine(sInput[i])){
			i++;
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->#注释->公式结束");
				return -1;
			}
		}
		i++; /*跳过回车*/
		*piPos=i;
		return true;
	}
	return false;

}
int LexConstString(char sInput[],int *piPos)
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
		
		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,*piPos,i-(*piPos),TYPE_CONST_STR);
		
		*piPos=i;
		return true;
	}
	return false;
}
int ConstDecNumBegin(char c)
{
	if((c>='0'&&c<='9')||c=='.') return true;
	return false;
}
int ConstDecNumNext(char c)
{
	if(c>='0'&&c<='9') return true;
	return false;
}
int LexConstDecNum(char sInput[],int *piPos)
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
			/*加入符号表*/
			ADDSYMBOLFLOW(sInput,*piPos,i-(*piPos),TYPE_CONST_DEC);
		
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

		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,*piPos,i-(*piPos),TYPE_CONST_DOUBLE);
		*piPos=i;
		return true;		
	}
	return false;
}

int ConstHexNumBegin(char c1,char c2)
{
	if(c1=='0'&&(c2=='X'||c2=='x')) return true;
	return false;
}
int ConstHexNumNext(char c)
{
	if((c>='0'&&c<='9')||
		(c>='a'&&c<='f')||
		(c>='A'&&c<='F')) return true;
	return false;
}
int LexConstHexNum(char sInput[],int *piPos)
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

		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,(*piPos),i-(*piPos),TYPE_CONST_HEX);
		
		*piPos=i;
		return true;
	}
	return false;
}
int ConstBinNumBegin(char c1,char c2)
{
	if(c1=='0'&&(c2=='B'||c2=='b')) return true;
	return false;
}
int ConstBinNumNext(char c)
{
	if(c>='0'&&c<='1') return true;
	return false;
}
int LexConstBinNum(char sInput[],int *piPos)
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

		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,(*piPos),i-(*piPos),TYPE_CONST_BIN);
		
		*piPos=i;
		return true;
	}
	return false;
}
int IdentifyBegin(char c)
{
	if(c=='_'||c=='$'||(c>='a' && c<='z')||
		(c>='A' && c<='Z')||(c&0x80)||c=='#') return true;
	return false;
}
int IdentifyNext(char c1,char c2)
{
	/*如果是汉字就不检测下一个字符*/
	if((c1&0x80)&&(c2&0x80)) return true;
	
	if( c2=='_'||c2=='.'||c2=='@'||(c2>='a' && c2<='z') || 
		(c2>='A' && c2<='Z') || 
		(c2>='0' && c2<='9') || (c2&0x80) ) return true;
	return false;
}
int IdentifyNextExt(char c)
{
	if(c==':'||c=='?'||c=='+'||c=='-'||c=='&'||
		c=='/'||c=='\\'||c=='.'||c=='='||c=='\'') return true;
	return false;
}
int LexIdentify(char sInput[],int *piPos)
{
	int i=*piPos,flag=false;
	char sTemp[16384];

	if(IdentifyBegin(sInput[i])){
		i++;
		if(ExprEnd(sInput[i])){
			ReportExprError(i,"词法错误->标识符->公式结束");
			return -1;
		}

		while(IdentifyNext(sInput[i-1],sInput[i])||
			(flag==true&&IdentifyNextExt(sInput[i]))){
			
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
			
			if(strncmp(sInput+i,"://",3)==0)flag=true;
			
			if(ExprEnd(sInput[i])){
				ReportExprError(i,"词法错误->标识符->公式结束");
				return -1;
			}		
		}

		strncpy(sTemp,sInput+(*piPos),i-(*piPos));
		sTemp[i-(*piPos)]=0;
		
		/*加入符号表*/
		ADDSYMBOLFLOW(sInput,(*piPos),i-(*piPos),GetSymType(sTemp));
		
		*piPos=i;
		return true;
	}
	return false;
}
int SeperatorBegin(char c)
{
	if(c=='{'||c=='}'||c==':'||
		c==','||c==';'||NewLine(c)) return true;
	return false;
}
int LexSeperator(char sInput[],int *piPos)
{
	int i=*piPos;
	
	if(SeperatorBegin(sInput[i])){
		i++;
		ADDSYMBOLFLOW(sInput,(*piPos),1,TYPE_SEPARATOR);
		*piPos=i;
		return true;
	}
	return false;
}
int MathBegin(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||
		c=='%'||c=='^'||c=='['||c==']'||c=='?'||c=='~'||
		c=='('||c==')') return true;
	return false;
}
int GetTypeMath(int iSymPos)
{
	int iType;

	/*回退一格*/
	iSymPos--;
	
	/*去掉前导的换行*/
	while(iSymPos>0){
		if(NewLine(SymbolFlow[iSymPos].sValue[0])==false) break;
		iSymPos--;
	}

	if(iSymPos<=0) return TYPE_MATH1;
		
	iType=SymbolFlow[iSymPos].iType;
	if((iType==TYPE_CONST_HEX) ||
		(iType==TYPE_CONST_BIN) ||
		(iType==TYPE_CONST_DEC) ||
		(iType==TYPE_CONST_STR) ||
		(iType==TYPE_CONST_DOUBLE) ||
		(iType==TYPE_SYSVAR) ||
		(iType==TYPE_TEMPVAR)||(iType==TYPE_MATH&&
			SymbolFlow[iSymPos].sValue[0]==')')) return TYPE_MATH;
	return TYPE_MATH1;
}
int LexMath(char sInput[],int *piPos)
{
	int i=*piPos,iType=0;
	
	if(MathBegin(sInput[i])){
		switch(sInput[i]){
		case '+':
		case '-':
			/*判断是单目运算符（正，负）还是双目运算符（加，减）
		          双目运算符是连结两个运算项的，
		          运算项是一个变量或是由括号括起来的表达式，
		          因此判断是双目运算符只判断前面是否变量或右括号
		         */
			if(igSymPos!=0&&
			    ( (C_TYPEP==TYPE_CONST_HEX) ||
			      (C_TYPEP==TYPE_CONST_BIN) ||
			      (C_TYPEP==TYPE_CONST_DEC) ||
			      (C_TYPEP==TYPE_CONST_STR) ||
			      (C_TYPEP==TYPE_CONST_DOUBLE) ||
			      (C_TYPEP==TYPE_SYSVAR) ||
			      (C_TYPEP==TYPE_TEMPVAR)||
			      (C_TYPEP==TYPE_MATH&&C_CVALUEP==')') 
			    )
			)
				iType=TYPE_MATH;
			else
				iType=GetTypeMath(igSymPos);
		break;
		case '*':
		case '/':
		case '%':
		case '^':
		case '(':
		case ')':
		case '[':
		case ']':
		case '?':
		case '~':
			iType=TYPE_MATH;
		break;
		default:
			return -1;
		}
		i++;
		ADDSYMBOLFLOW(sInput,(*piPos),1,iType);
		*piPos=i;
		return true;
	}
	return false;
}
int LogicalBegin(char c)
{
	if(c=='>'||c=='<'||c=='='||
		c=='!'||c=='|'||c=='&') return true;
	return false;
}
int LexLogical(char sInput[],int *piPos)
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
		
		ADDSYMBOLFLOW(sTemp,0,1,iType);
		*piPos=i;
		/*由于需要修改ori_pos*/
		SymbolFlow[igSymPos-1].iOriPos= i-1;
		
		return true;
	}
	return false;
}
/*词法分析,生成具有独立含义的符号流 SymbolFlow*/
int Lexicalize(char sInput[])
{
	int i=0,iRet,iInputLen;
	
	iInputLen=strlen(sInput);
	
	igSymPos=0;
	while(i<iInputLen){
		
		while(JmpSeperator(sInput[i])&&!ExprEnd(sInput[i])) i++;

		if(ExprEnd(sInput[i])) break;
	
/*续行处理，一般是用于宏定义*/
		if(strncmp(sInput+i,"\\\n",2)==0){i+=2;continue;}
		if(strncmp(sInput+i,"\\\r\n",3)==0){i+=3;continue;}
/*处理C语言注释*/
		if((iRet=LexCComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理C++注释*/
		if((iRet=LexCppComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;

/*处理Sh注释	if((iRet=LexShComment(sInput,&i))<0) return -1;
		if(iRet==true) continue;
*/
/*处理常量字符串*/
		if((iRet=LexConstString(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理常量十六进制数*/
		if((iRet=LexConstHexNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理常量二进制数*/
		if((iRet=LexConstBinNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理常量十进制数*/
		if((iRet=LexConstDecNum(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理标识符*/
		if((iRet=LexIdentify(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理分割符*/
		if((iRet=LexSeperator(sInput,&i))<0) return -1;
		if(iRet==true) continue;
/*处理"+,-,*,/"算术符号*/
		if((iRet=LexMath(sInput,&i))<0) return -1;
		if(iRet==true) continue;
		
/*处理">,<,=,!,|,&"逻辑符号*/
		if((iRet=LexLogical(sInput,&i))<0) return -1;
		if(iRet==true) continue;

		ReportExprError(i,"词法错误->遇到非法字符");
		return -i-1;
	} /*end while(i*/
	igSymCnt=igSymPos;
	return 0;
}
void GetTypeComment(int iType,char sValue[],char sTemp[])
{
	char sComment[10];

	strcpy(sComment,"");

	switch(iType){
	case TYPE_LOG2:
	case TYPE_LOG1:
	case TYPE_MATH:
	case TYPE_ASSIGN:
		switch(sValue[0]){
		case '1': strcpy(sComment,">");	break;
		case '2': strcpy(sComment,"<");	break;
		case '3': strcpy(sComment,">=");break;
		case '4': strcpy(sComment,"<=");break;
		case '5': strcpy(sComment,"==");break;
		case '6': strcpy(sComment,"!=");break;
		case '7': strcpy(sComment,"|");break;
		case '8': strcpy(sComment,"&");break;
		case '&': strcpy(sComment,"&&");break;
		case '|': strcpy(sComment,"||");break;
		case '!': strcpy(sComment,"!");break;
		case '=': strcpy(sComment,"=");break;
		}
	break;
	default: break;
	}
	if(strlen(sComment)==0&&iType==TYPE_MATH)
		strcpy(sComment,sValue);

	if(strlen(sComment)!=0)
		sprintf(sTemp,"(%s)",sComment);
	else	strcpy(sTemp,"");
}
void DisplaySymbolFlow()
{
	int iType,i;
	char asType[23][12]={"LOG1","LOG2","MATH","CONTROL","CONST",
		"SYSVAR","TEMPVAR","SEPARATOR","ASSIGN","MATH1","CONSTSTR",
		"CONSTHEX","CONSTDEC","CONSTBIN","SFUN","DFUN","DOUBLE",
		"LCONSTSTR","MODALITY","PRECOMP","DECLARE","MICRO","FUN"};
	char sComment[8];
	
	for(i=0;i<igSymCnt;i++){
       		iType=SymbolFlow[i].iType-1;
       		
       		GetTypeComment(SymbolFlow[i].iType,SymbolFlow[i].sValue,sComment);
       		
		if(strchr(SymbolFlow[i].sValue,'%')==NULL)
       			WriteProcMsg("%03d: %10s  %s%s",
				i,asType[iType],SymbolFlow[i].sValue,sComment);
		else if(strcmp(SymbolFlow[i].sValue,"\n")==0)
       			WriteProcMsg("%03d: %10s  \\n",i,asType[iType]);
		else
       			WriteProcMsg("%03d: %10s %s",i,asType[iType],sComment);
/*
       		if(strcmp(SymbolFlow[i].sValue,"\n")==0)
       			printf("%03d: %10s  \\n\n",i,asType[iType]);
       		else  	printf("%03d: %10s  %s%s\n",i,
       				asType[iType],SymbolFlow[i].sValue,sComment);
*/
       }
}
int main(int argc,char *argv[])
{
#define MYMAX_FILESIZE 819200

	int l;
	char sInput[MYMAX_FILESIZE],sMsg[1024];
	
	InitAppRes(argv[0]);

	if((l=ReadFileToBuf("index.html",MYMAX_FILESIZE,sInput,sMsg))<0){
		printf("%s\n",sMsg);
		return -1;
	}
	if(Lexicalize(sInput)<0){
		FormatExprErrorMsg(sInput);
		igSymCnt=igSymPos;
		DisplaySymbolFlow();
		printf("词法分析错误.\n%s\n",ErrMsg.sMsg);
		return -1;
	}
	DisplaySymbolFlow();
	printf("hello world.\n");
	return 0;
}

