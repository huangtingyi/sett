#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <list.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <bintree.h>

#include <hnixs.h>

struct HtmlElementStruct
{
	struct HtmlElementStruct *pSibling;
	struct HtmlElementStruct *pParent;
	struct HtmlElementStruct *pChild;

	struct HtmlPropStruct *pProp;
	struct HtmlContStruct *pCont;
	char	sTag[32];
};
struct HtmlPropStruct
{
	struct HtmlPropStruct *pNext;
	struct HtmlElementStruct *pElement;
	char sName[32];
	char sValue[1];
};
struct HtmlContStruct
{
	struct HtmlContStruct *pNext;
	char sValue[1];
};


#define TYPE_HTML_COMMENT	11	/*html注释*/
#define TYPE_HTML_COMMAND	12	/*html命令*/
#define TYPE_CPP_COMMENT	13	/*C++注释*/
#define TYPE_C_COMMENT		14	/*C注释*/
#define TYPE_TAGSEP		15	/*tag标签*/
#define TYPE_HTML_INDENTIFY	16	/*HTML表识*/
#define TYPE_CONST		17	/*常量*/
#define TYPE_SEPARATOR		18	/*分割符*/
#define TYPE_MATH		19
#define TYPE_LOG1		20
#define TYPE_LOG2		21
#define TYPE_ASSIGN		22
#define TYPE_CONTENT		23
#define	TYPE_INDENTIFY		24
#define TYPE_OTHER		25



char *GetTypeDesc(int iType)
{
	char *asType[]={"COMMENT","COMMAND","CPP_COMM","C_COMM",
		"TAGSEP","IDENTIFY","CONST","SEPARATOR","MATH","LOG1",
		"LOG2","ASSIGN","CONTENT","IDENTIFY","OTHEX"};

	if(iType<11||iType>25) return "OTHER";
	return asType[iType-11];
}
static int new_line(char sInput[])
{
	if(strncmp(sInput,"\n",1)==0||
		strncmp(sInput,"\r",1)==0) return true;
	return false;
}
static int comment_c_begin(char sInput[])
{
	if(strncmp(sInput,"/*",2)==0) return true;
	return false;
}
static int comment_c_end(char sInput[])
{
	if(strncmp(sInput,"*/",2)==0) return true;
	return false;
}
static int comment_html_begin(char sInput[])
{
	if(strncmp(sInput,"<!--",4)==0) return true;
	return false;
}
static int comment_html_end(char sInput[])
{
	if(strncmp(sInput,"-->",3)==0) return true;
	return false;
}
static int command_html_begin(char sInput[])
{
	if(strncmp(sInput,"<!",2)==0) return true;
	return false;
}
static int command_html_end(char sInput[])
{
	if(strncmp(sInput,">",1)==0) return true;
	return false;
}

static int comment_cpp_begin(char sInput[])
{
	if(strncmp(sInput,"//",2)==0) return true;
	return false;
}
static int comment_cpp_end(char sInput[])
{
	return new_line(sInput);
}
static int tagsep_begin(char sInput[],int *pl)
{
	int l=0;

	*pl=0;

	if(strncmp(sInput,"</",2)==0) l=2;
	else if(strncmp(sInput,"/>",2)==0) l=2;
	else if(strncmp(sInput,"<",1)==0) l=1;
	else if(strncmp(sInput,">",1)==0) l=1;
	
	if(l==0) return false;
	
	*pl=l;

	return true;
}
static int html_identify_begin(char sInput[])
{
	if((sInput[0]>='a'&&sInput[0]<='z')||
                (sInput[0]>='A'&& sInput[0]<='Z')||
                sInput[0]=='_'||sInput[0]=='.'||sInput[0]=='-'||sInput[0]=='/'||
                (sInput[0]&0x80)!=0) return true;
	return false;
}
static int html_identify_next(char sInput[])
{
	if((sInput[0]>='a'&&sInput[0]<='z')||
                (sInput[0]>='A'&& sInput[0]<='Z')||
                (sInput[0]>='0'&&sInput[0]<='9')||sInput[0]==':'||sInput[0]=='?'||sInput[0]=='&'||
                sInput[0]=='_'||sInput[0]=='.'||sInput[0]=='-'||sInput[0]=='/'||
                (sInput[0]&0x80)!=0) return true;
	return false;
}

static int identify_begin(char sInput[])
{
	if((sInput[0]>='a'&&sInput[0]<='z')||
                (sInput[0]>='A'&& sInput[0]<='Z')||
                sInput[0]=='_'||(sInput[0]&0x80)!=0) return true;
	return false;
}
static int identify_next(char sInput[])
{
	if((sInput[0]>='a'&&sInput[0]<='z')||
                (sInput[0]>='A'&& sInput[0]<='Z')||
                (sInput[0]>='0'&&sInput[0]<='9')||
                sInput[0]=='_'||(sInput[0]&0x80)!=0) return true;
	return false;
}
static int string_c_begin(char sInput[])
{
	if(strncmp(sInput,"\"",1)==0) return true;
	return false;
}
static int string_c_next(char sInput[])
{
	if(strncmp(sInput,"\\\\",2)==0) return 2;
	if(strncmp(sInput,"\\\"",2)==0) return 2;
	if(strncmp(sInput,"\"",1)==0) return 0;
	else return 1;
}
static int char_c_begin(char sInput[])
{
	if(strncmp(sInput,"\'",1)==0) return true;
	return false;
}
static int char_c_next(char sInput[])
{
	if(strncmp(sInput,"\\\\",2)==0) return 2;
	if(strncmp(sInput,"\\\'",2)==0) return 2;
	if(strncmp(sInput,"\'",1)==0) return 0;
	else return 1;
}
static int input_end(char sInput[])
{
	if(sInput[0]==0) return true;
	return false;
}

static int const_hex_num_begin (char sInput[])
{
	char c1=sInput[0],c2=sInput[1];

        if(c1=='0'&&(c2=='X'||c2=='x')) return true;
        return false;
}

int const_hex_num_next(char sInput[])
{
	char c=sInput[0];

        if((c>='0'&&c<='9')||
                (c>='a'&&c<='f')||
                (c>='A'&&c<='F')) return 1;
        return 0;
}
static int const_html_hex_begin (char sInput[])
{
        if(sInput[0]=='#') return true;
        return false;
}

int const_html_hex_next(char sInput[])
{
	char c=sInput[0];

        if((c>='0'&&c<='9')||
                (c>='a'&&c<='f')||
                (c>='A'&&c<='F')) return 1;
        return 0;
}
int const_dec_num_begin(char sInput[])
{
	char c=sInput[0];

        if(c>='0'&&c<='9') return true;
        return false;
}
int const_dec_num_next(char sInput[])
{
	char c=sInput[0];

        if(c>='0'&&c<='9') return 1;
        return 0;

}
static int const_bin_num_begin (char sInput[])
{
	char c1=sInput[0],c2=sInput[1];

        if(c1=='0'&&(c2=='B'||c2=='b')) return true;
        return false;
}
int const_bin_num_next(char sInput[])
{
	char c=sInput[0];

        if(c>='0'&&c<='1') return 1;
        return 0;
}
int seperator_begin(char sInput[])
{
	if(strchr(" \t\n\r{}:,;",sInput[0])!=NULL)
		return true;
	return false;
}
int math_begin(char sInput[])
{
	if(strchr("+-*/%^()[]?~.",sInput[0])!=NULL) return true;
	return false;
}
int logical_begin(char c)
{
	if(c=='>'||c=='<'||c=='='||
		c=='!'||c=='|'||c=='&') return true;
	return false;
}
int lex_logical(char sInput[],int *piPos,int *piType)
{
	int i=0,iType=0;
	
	*piPos=*piType=0;
	
	if(logical_begin(sInput[i])){
		if(strncmp(sInput+i,">=",2)==0){
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"<=",2)==0){
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"==",2)==0){
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"!=",2)==0||
			strncmp(sInput,"<>",2)==0){
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,">",1)==0){
			iType=TYPE_LOG2;
			i++;
		}
		else if(strncmp(sInput+i,"<",1)==0){
			iType=TYPE_LOG2;
			i++;
		}
		else if(strncmp(sInput+i,"=",1)==0){
			iType=TYPE_ASSIGN;
			i++;
		}
		else if(strncmp(sInput+i,"!",1)==0){
			iType=TYPE_LOG1;
			i++;
		}
		else if(strncmp(sInput+i,"||",2)==0){
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"&&",2)==0){
			iType=TYPE_LOG2;
			i+=2;
		}
		else if(strncmp(sInput+i,"|",1)==0){
			iType=TYPE_MATH;
			i++;
		}
		else if(strncmp(sInput+i,"&",1)==0){
			iType=TYPE_MATH;
			i++;
		}
		else
			return false;
		
		*piPos=i;

		*piType=iType;
				
		return true;
	}
	return false;
}
int lex_const(char sInput[],int *pl,int *piType)
{
	char *pc=sInput;
	int l=0;

	if(string_c_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=string_c_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		pc++;
		*piType=TYPE_CONST;
		goto read_tail;
	}
	if(char_c_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=char_c_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		pc++;
		*piType=TYPE_CONST;
		goto read_tail;
	}
	if(const_hex_num_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=const_hex_num_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		*piType=TYPE_CONST;
		goto read_tail;
	}
	if(const_dec_num_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=const_dec_num_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		*piType=TYPE_CONST;
		goto read_tail;
	}
	if(const_bin_num_begin(pc)){
		pc++;
		if(input_end(pc)) goto read_tail;
		while((l=const_bin_num_next(pc))>0){
			pc+=l;
			if(input_end(pc)) goto read_tail;
		}
		*piType=TYPE_CONST;
		goto read_tail;
	}
	return false;
read_tail:
	*pl=(pc-sInput);
	return true;
}
int StrcmpIgnoreCase(char sInput[],char sData[],int n)
{
	char sSource[256],sTarget[256];
	
	strncpy(sSource,sInput,n);sSource[n]=0;
	strncpy(sTarget,sData,n);sTarget[n]=0;
	
	Upper(sSource);
	Upper(sTarget);
	
	return strcmp(sSource,sTarget);
}
int lex_comment_html_script(char *pc,int *piPos)
{
	*piPos=0;
	
	if(strncmp(pc,"<!--\n",5)==0||
		strncmp(pc,"<!--\r",5)==0){
		*piPos=5;
		return true;
	}
	return false;
}
static int ReadWord(char sInput[],char sOutput[],int *piType)
{
	static int l,contentflag=true,scriptflag=false,iPreScriptFlag=false;
	char *pc=sInput;

	strcpy(sOutput,"");
	*piType=0;

	if(input_end(pc)) return 0;
	
/*1.处理掉HTML注释	*/
	if(!(scriptflag==true&&contentflag==true)){
		if(comment_html_begin(pc)){
			pc+=4;
			if(input_end(pc)) goto read_tail;
			while(!comment_html_end(pc)){
				pc++;
				if(input_end(pc)) goto read_tail;
			}
			pc+=3;
			*piType=TYPE_HTML_COMMENT;
			goto read_tail;
		}
/*2.处理掉HTML命令	*/
		if(command_html_begin(pc)){
			pc+=2;
			if(input_end(pc)) goto read_tail;
			while(!command_html_end(pc)){
				pc++;
				if(input_end(pc)) goto read_tail;
			}
			pc+=1;
			*piType=TYPE_HTML_COMMAND;
			goto read_tail;
		}
	}
/*3.判断是否在script语言内部	*/
	if(scriptflag==false){
		if(StrcmpIgnoreCase(pc,"<SCRIPT",7)==0){
			iPreScriptFlag=scriptflag;
			scriptflag=true;
		}
	}
	else{
		if(strncmp(pc,"/>",2)==0||
			StrcmpIgnoreCase(pc,"</SCRIPT>",9)==0){
			iPreScriptFlag=scriptflag;
			scriptflag=false;
		}
	}
/*4.判断是否在内容之中	*/
	if(contentflag==false){
		if(strncmp(pc,">",1)==0){
			if(scriptflag==false)contentflag=true;
			if(iPreScriptFlag==false&&scriptflag==true){
				iPreScriptFlag=true;
				contentflag=true;
			}
		}
	}
	else{
		if(strncmp(pc,"<",1)==0&&
			(scriptflag==false||iPreScriptFlag==false))
			contentflag=false;
	}
/*5.如果是在javascript中,且是在内容区域,这时候才做注释	*/
	if(scriptflag==true&&contentflag==true){
		
		/*处理特殊的脚本注释，开始行为注释行的情况*/
		if(lex_comment_html_script(pc,&l)){
			pc+=l;
			*piType=TYPE_HTML_COMMENT;
			goto read_tail;
		}
		/*处理script中的html注释行	*/
		if(comment_html_begin(pc)){
			pc+=4;
			if(input_end(pc)) goto read_tail;
			while(!comment_html_end(pc)){
				pc++;
				if(input_end(pc)) goto read_tail;
			}
			pc+=3;
			*piType=TYPE_HTML_COMMENT;
			goto read_tail;
		}
		if(comment_c_begin(pc)){
			pc+=2;
			if(input_end(pc)) goto read_tail;
			while(!comment_c_end(pc)){
				pc++;
				if(input_end(pc)) goto read_tail;
			}
			pc+=2;
			*piType=TYPE_C_COMMENT;
			goto read_tail;
		}
		if(comment_cpp_begin(pc)){
			pc+=2;
			if(input_end(pc)) goto read_tail;
			while(!comment_cpp_end(pc)){
				pc++;
				if(input_end(pc)) goto read_tail;
			}
			while(comment_cpp_end(pc)) pc++;
			*piType=TYPE_CPP_COMMENT;
			goto read_tail;
		}
		if(lex_const(pc,&l,piType)){
			pc+=l;
			goto read_tail;
		}
		if(seperator_begin(pc)){
			pc++;
			*piType=TYPE_SEPARATOR;
			goto read_tail;
		}
		if(identify_begin(pc)){
			pc++;
			if(input_end(pc)) goto read_tail;
			while((l=identify_next(pc))>0){
				pc+=l;
				if(input_end(pc)) goto read_tail;
			}
			*piType=TYPE_INDENTIFY;
			goto read_tail;
		}
		if(math_begin(pc)){
			pc++;
			*piType=TYPE_MATH;
			goto read_tail;
		}
		if(lex_logical(pc,&l,piType)){
			pc+=l;
			goto read_tail;
		}
	}
	else{
		if(tagsep_begin(pc,&l)){
			pc+=l;
			*piType=TYPE_TAGSEP;
			goto read_tail;
		}
		/*在HTML的TAG标记里面*/
		if(contentflag==false){
			
			if(html_identify_begin(pc)){
				pc++;
				if(input_end(pc)) goto read_tail;
				while((l=html_identify_next(pc))>0){
					pc+=l;
					if(input_end(pc)) goto read_tail;
				}
				*piType=TYPE_HTML_INDENTIFY;
				goto read_tail;
			}
			if(seperator_begin(pc)){
				pc++;
				*piType=TYPE_SEPARATOR;
				goto read_tail;
			}
			if(lex_logical(pc,&l,piType)){
				pc+=l;
				goto read_tail;
			}
			if(lex_const(pc,&l,piType)){
				pc+=l;
				goto read_tail;
			}
			if(const_html_hex_begin(pc)){
				pc++;
				if(input_end(pc)) goto read_tail;
				while((l=const_html_hex_next(pc))>0){
					pc+=l;
					if(input_end(pc)) goto read_tail;
				}
				*piType=TYPE_CONST;
				goto read_tail;
			}
		}
		else{
			if(seperator_begin(pc)){
				pc++;
				*piType=TYPE_SEPARATOR;
				goto read_tail;
			}
			if(pc[0]!='<'&&pc[0]!='>'){
				pc++;
				if(input_end(pc)) goto read_tail;
				while(pc[0]!='<'&&pc[0]!='>'){
					pc++;
					if(input_end(pc)) goto read_tail;
				}
				*piType=TYPE_CONTENT;
				goto read_tail;
			}
		}
	}
	*piType=TYPE_OTHER;
	pc++;
read_tail:
	if(pc!=sInput){
		strncpy(sOutput,sInput,pc-sInput);
		sOutput[pc-sInput]=0;
		return pc-sInput;
	}
	return 0;
}
int main(int argc,char *argv[])
{
#define MYMAX_FILESIZE 819200

	int l,i=0,iType=0;
	char sFileName[256],sInput[MYMAX_FILESIZE],sMsg[1024];
	char sWord[2048*10],*sTemp=sInput;

	InitAppRes(argv[0]);

	if(argc!=2){
		printf("Usage %s htmfile.\n",argv[0]);
		return -1;
	}
	strcpy(sFileName,argv[1]);

	if(ReadFileToBuf(sFileName,MYMAX_FILESIZE,sInput,sMsg)<0){
		printf("%s\n",sMsg);
		return -1;
	}
	while((l=ReadWord(sTemp,sWord,&iType))>0){

		sTemp+=l;
		
		/*删除回车、换行*/
		if(iType==TYPE_SEPARATOR&&
			strchr(" \t\n\r",sWord[0])!=NULL) continue;

		if(iType==TYPE_CONTENT&&strlen(sWord)>10)
			printf("i=%d\t%-15s\t%s\n",i++,GetTypeDesc(iType),sWord);
	}
	
	printf("hello world.\n");
	return 0;
}

