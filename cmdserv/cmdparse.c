/*
结果文件格式
第一行取值
"11"	交换机请求命令
"12"	联机指令系统请求命令
"21"	交换机应答转换命令
"22" 	系统应答转换命令

第二行10位长，左对齐，右补空。
二个字节为一个字段，
表示命令长度。为16进制的。。
第三行起为命令

*/
#include "hnixs.h"
#include "stt_ticket.h"
#include "cmdparse.h"
#include "cmdsupp.h"

#include "bellcmd.h"

static struct CmdTable CMDTYPE[150]={
{"DN",DN		},
{"IMSI",IMSI		},
{"ESN",ESN		},
{"PIC",PIC              },
{"AKEY",AKEY             },
{"CHECKSUM",CHECKSUM         },
{"KEYID",KEYID            },
{"PREPAIDY",PREPAIDY		},
{"PREPAIDN",PREPAIDN		},
{"SMS0R",SMS0R		},
{"SMS0E",SMS0E		},
{"SMS1R",SMS1R		},
{"SMS1E",SMS1E		},
{"SMS2R",SMS2R		},
{"SMS2E",SMS2E		},
{"INETRIM0R",INETRIM0R        },
{"INETRIM0E",INETRIM0E        },
{"INETRIM1R",INETRIM1R        },
{"INETRIM1E",INETRIM1E        },
{"INETRIM2R",INETRIM2R        },
{"INETRIM2E",INETRIM2E        },
{"ROAMING0R",ROAMING0R	},
{"ROAMING0E",ROAMING0E	},
{"ROAMING1R",ROAMING1R	},
{"ROAMING1E",ROAMING1E	},
{"ROAMING2R",ROAMING2R	},
{"ROAMING2E",ROAMING2E	},
{"ROAMING3R",ROAMING3R	},
{"ROAMING3E",ROAMING3E	},
{"BASICR",BASICR		},
{"BASICE",BASICE		},
{"LOCALR",LOCALR		},
{"LOCALE",LOCALE		},
{"VMRR",VMRR		},
{"VMRE",VMRE		},
{"CFBR",CFBR		},
{"CFBE",CFBE		},
{"CFNRR",CFNRR		},
{"CFNRE",CFNRE		},
{"CFUR",CFUR		},
{"CFUE",CFUE		},
{"CFCR",CFCR		},
{"CFCE",CFCE		},
{"CTR",CTR		},
{"CTE",CTE		},
{"MWNR",MWNR		},
{"MWNE",MWNE		},
{"CWR",CWR		},
{"CWE",CWE		},
{"CHR",CHR		},
{"CHE",CHE		},
{"A3WCR",A3WCR		},
{"A3WCE",A3WCE		},
{"CLIRR",CLIRR		},
{"CLIRE",CLIRE		},
{"CNIRR",CNIRR		},
{"CNIRE",CNIRE		},
{"CCR",CCR		},
{"CCE",CCE		},
{"INTERNETR",INTERNETR	},
{"INTERNETE",INTERNETE	},

{"COS"		,COS		},
{"CRBTE"	,CRBTE		},
{"ACCOUNTLOCK2E",ACCOUNTLOCK2E	},
{"ACCOUNTLOCK1R",ACCOUNTLOCK1R	},
{"WINCOS6"	,WINCOS6	},
{"INTERIM2E"	,INTERIM2E	},
{"USERLOCK2E"	,USERLOCK2E	},
{"INTERIM1E"	,INTERIM1E	},
{"USERLOCK0R"	,USERLOCK0R	},
{"USERLOCK1R"	,USERLOCK1R	},
{"WINCOS8"	,WINCOS8	},
{"INTERIM1R"	,INTERIM1R	},
{"INTERIM0E"	,INTERIM0E	},
{"AKEY"		,AKEY		},
{"INTERIM2R"	,INTERIM2R	},
{"STOLENLOCKR"	,STOLENLOCKR	},
{"INTERIM0R"	,INTERIM0R	},
{"CRBTR"	,CRBTR		},
{"DUPLOCKR"	,DUPLOCKR	},
{"SMPE"		,SMPE		},
{"STOLENLOCKE"	,STOLENLOCKE	},
{"ACCOUNTLOCK2R",ACCOUNTLOCK2R	},
{"ACCOUNTLOCK0R",ACCOUNTLOCK0R	},
{"USERLOCK2R"	,USERLOCK2R	},
{"SMPR"		,SMPR		},
{"DUPLOCKE"	,DUPLOCKE	},

{"CL0E"     	,CL0E      	},
{"CL0R"     	,CL0R      	},
{"PPCE"    	,PPCE     	},
{"PPCR"    	,PPCR     	},
{"VPNR"    	,VPNR     	},
{"VPNE"    	,VPNE     	},
{"RFCR"    	,RFCR     	},
{"RFCE"    	,RFCE     	},
{"CFSVR0R" 	,CFSVR0R  	},
{"CFSVR0E" 	,CFSVR0E  	},
{"CFSVR1E" 	,CFSVR1E  	},
{"CFSVR1R" 	,CFSVR1R  	},
{"CFSVR2R" 	,CFSVR2R  	},
{"CFSVR2E" 	,CFSVR2E  	},
{"CFSVR3E" 	,CFSVR3E  	},
{"CFSVR3R" 	,CFSVR3R  	},
{"SMP0E"   	,SMP0E    	},
{"SMP1E"   	,SMP1E    	},
{"SMP1R"   	,SMP1R    	},

{"LSTCFD"	,LSTCFD		},
{"LSTINTERIM"	,LSTINTERIM	},
{"LSTCFNA"	,LSTCFNA	},
{"LSTROAMING"	,LSTROAMING	},
{"LSTCFB"	,LSTCFB		},
{"LSTINTERNET"	,LSTINTERNET	},
{"LSTWINSVR"	,LSTWINSVR	},
{"INQCODE"	,INQCODE	},
{"LSTCFU"	,LSTCFU		},
{"LSTSMS"	,LSTSMS		},
{"AKEY"		,AKEY		},
{"LSTLOCAL"	,LSTLOCAL	},
{"LSTSUPSVR"	,LSTSUPSVR	},
{NULL,0}};

/*原来的库函数只能操作8位16进制，再在需要转换16位，所以重写*/
int HexStrToIntb(char sTemp[],char sResult[])
{
        static int iFirstFlag=TRUE,aiAnti[256];
        int i,j,iLen;
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
                        if(i>='0'&&i<='9')aiAnti[i]=i-'0';
                }
        }
        iLen=strlen(sTemp);

        if(iLen==0||iLen>16) return 0;

	strcpy(sResult,"0");
        for(i=0;i<iLen;i++){
                j=aiAnti[ p[i] ];
                sprintf(sResult,"%020ld",atol(sResult)*16+j);
        }
        return 0;
}

int HasSubParam(char sTemplate[])
{
	if(strstr(sTemplate,SUBST)==NULL)
		return false;

	return true;
}

/*为命令中的模板绑定值，如${DN}替换成请求串中的DN值，${这里的命名规则以请求串中名值对的名称来命名替换}*/
int BindValue(struct InfoItemStruct *ptInfoItem,char sSource[],char sResults[])
{
	char sPattern[128];
	struct InfoItemStruct *ptHead= ptInfoItem,*pTemp= NULL;

	strcpy(sResults,sSource);
	while(ptHead!= NULL){

		pTemp= ptHead;
		ptHead= ptHead->pNext;

		/*替换子选项*/
		sprintf(sPattern,"${%s}",pTemp->sName);

		/*替换特殊符号*/
		if(strstr(sResults,NEWLINE)!= NULL){
			replace(sResults,NEWLINE,NEWLINEVAL,sResults);
		}
		/*AKEY*/
		if(strcmp(pTemp->sName,"AKEY")==0){
			char sValue[32];
			HexStrToIntb(pTemp->sValue,sValue);
			replace(sResults,sPattern,sValue,sResults);
		}
		/*其它*/
		if(strstr(sResults,sPattern)!= NULL){
			replace(sResults,sPattern,pTemp->sValue,sResults);
		}

	}

	return 0;
}

/*字符串替换*/
char *replace(char sSource[],char sPattern[],char sReplacement[],char sDest[])
{

	char *p,sResult[8192],sHead[4096],sTail[4096];

	strcpy(sResult,sSource);


	while((p= strstr(sResult,sPattern))!= NULL){

		*p= '\0';
		p += strlen(sPattern);

		strcpy(sHead,sResult);
		strcpy(sTail,p);
		sprintf(sResult,"%s%s%s",sHead,sReplacement,sTail);

	}

	strcpy(sDest,sResult);
	return sDest;
}

int main(int argc,char **argv)
{
	FILE *fp;
	int iCmdType,iCmdLen;
	char sCmdPos[256],sTemp[8];
	char sCmdType[32],sAreaCode[8],sMscType[32];
	char sCmdInfo[1024],sOutPutFile[128];
	char sResult[8192],sOutPut[8192],sCmdCatalog[4];
	struct ResultStruct *pResHead,*pResTemp,*pResult;
	struct InfoItemStruct *ptInfoItem= NULL,*ptTemp= NULL,*ptHead=NULL;

	if(argc!= 6){
		printf("Usage:%s MscType AreaCode CmdType CmdInfo OutPutFile\n",argv[0]);
		return -1;
	}

        InitAppRes(argv[0]);
	strncpy(sMscType,argv[1],32);sMscType[31]= '\0';
	strncpy(sAreaCode,argv[2],7);sAreaCode[7]= '\0';
	strncpy(sCmdType,argv[3],32);sCmdType[31]= '\0';
	strncpy(sCmdInfo,argv[4],1024);sCmdInfo[1023]= '\0';
	strncpy(sOutPutFile,argv[5],128);sOutPutFile[127]= '\0';

	if(strlen(sCmdInfo)==0){
		return -1;
	}

	ptInfoItem= GenInfoItemList(sCmdInfo,',','=');
	if(ptInfoItem==NULL){
		printf("获取命令选项失败！\n");
		return -1;
	}

	/*创建新用户请求*/
	if(strcmp(sCmdType,"CRUSER")==0){
		iCmdType= BUSI;
		ProcCmd(ProcCRUSER,ptInfoItem,sCmdType,&pResult);
	}

	/*业务控制请求*/
	if(strcmp(sCmdType,"CHGSRV")==0){
		iCmdType= BUSI;
		ProcCmd(ProcCHGSRV,ptInfoItem,sCmdType,&pResult);
	}

	/*删除用户请求*/
	if(strcmp(sCmdType,"DLUSER")==0){
		iCmdType= BUSI;
		ProcCmd(ProcDLUSER,ptInfoItem,sCmdType,&pResult);
	}

	/*修改用户IMSI请求*/
	if(strcmp(sCmdType,"CHIMSI")==0){
		iCmdType= BUSI;
		ProcCmd(ProcCHIMSI,ptInfoItem,sCmdType,&pResult);
	}

	/*修改用户DN请求*/
	if(strcmp(sCmdType,"CHGMDN")==0){
		iCmdType= BUSI;
		ProcCmd(ProcCHGMDN,ptInfoItem,sCmdType,&pResult);
	}

	/*修改用户ESN请求*/
	if(strcmp(sCmdType,"CHGESN")==0){
		iCmdType= BUSI;
		ProcCmd(ProcCHGESN,ptInfoItem,sCmdType,&pResult);
	}

	/*修改用户PIC请求*/
	if(strcmp(sCmdType,"CHGPIC")==0){
		iCmdType= BUSI;
		ProcCmd(ProcCHGPIC,ptInfoItem,sCmdType,&pResult);
	}

	/*用户信息查询请求*/
	if(strcmp(sCmdType,"QUINFO")==0){
		iCmdType= BUSI;
		ProcCmd(ProcQUINFO,ptInfoItem,sCmdType,&pResult);
	}

	/*用户信息查询反馈*/
	if(strcmp(sCmdType,"USIRSP")==0){
		iCmdType= BUSI;
		ProcCmd(ProcUSIRSP,ptInfoItem,sCmdType,&pResult);
	}

	/*反馈结果应答*/
	if(strcmp(sCmdType,"RSPACK")==0){
		iCmdType= BUSI;
		ProcCmd(ProcRSPACK,ptInfoItem,sCmdType,&pResult);
	}

	/*收到请求应答*/
	if(strcmp(sCmdType,"REQACK")==0){
		iCmdType= BUSI;
		ProcCmd(ProcREQACK,ptInfoItem,sCmdType,&pResult);
	}

	/*请求结果消息*/
	if(strcmp(sCmdType,"FEBRSP")==0){
		iCmdType= BUSI;
		ProcCmd(ProcFEBRSP,ptInfoItem,sCmdType,&pResult);
	}

	/*工单内容查询请求*/
	if(strcmp(sCmdType,"QWINFO")==0){
		iCmdType= QUERY;
		ProcCmd(ProcQWINFO,ptInfoItem,sCmdType,&pResult);
	}

	/*工单状态查询请求*/
	if(strcmp(sCmdType,"QWSTAT")==0){
		iCmdType= QUERY;
		ProcCmd(ProcQWSTAT,ptInfoItem,sCmdType,&pResult);
	}

	/*工单内容查询结果消息*/
	if(strcmp(sCmdType,"WDTRSP")==0){
		iCmdType= QUERY;
		ProcCmd(ProcWDTRSP,ptInfoItem,sCmdType,&pResult);
	}

	/*查询工单结果消息*/
	if(strcmp(sCmdType,"WITRSP")==0){
		iCmdType= QUERY;
		ProcCmd(ProcWITRSP,ptInfoItem,sCmdType,&pResult);
	}

	/*AAA交换机*/
	if(strcmp(sCmdType,"CRTNAI")==0||
	strcmp(sCmdType,"CHGNAI")==0||
	strcmp(sCmdType,"DLTNAI")==0||
	strcmp(sCmdType,"CHGPWD")==0||
	strcmp(sCmdType,"ADDSRV")==0||
	strcmp(sCmdType,"DLTSRV")==0||
	strcmp(sCmdType,"CRIMSI")==0||
	strcmp(sCmdType,"DLIMSI")==0||
	strcmp(sCmdType,"QUIMSI")==0||
	strcmp(sCmdType,"IMSRSP")==0||
	strcmp(sCmdType,"CHGTNL")==0||
	strcmp(sCmdType,"PREQUT")==0||
	strcmp(sCmdType,"FRMQUT")==0||
	strcmp(sCmdType,"CRTRLT")==0||
	strcmp(sCmdType,"CHGRLT")==0||
	strcmp(sCmdType,"DLTRLT")==0||
	strcmp(sCmdType,"CHGDMN")==0){

		iCmdType= BUSI;
		ProcCmd(NULL,ptInfoItem,sCmdType,&pResult);
	}


	ptHead= ptInfoItem;
	while(ptHead!= NULL){

		int iCmdCode;

		ptTemp= ptHead;
		ptHead= ptHead->pNext;

		iCmdCode= GetBusiCode(ptTemp);

		printf("Cmd:%s---%s    Code:%d\n",ptTemp->sName,ptTemp->sValue,iCmdCode);

		if(iCmdCode <= 0) continue;


	}

	sprintf(sCmdCatalog,"%02d\n0000000000000000000000000000000000000000\n",iCmdType);
	/*todo:BindValue and WriteOutPut*/
	fp= fopen(sOutPutFile,"w");
	fputs(sCmdCatalog,fp);
	pResHead=pResult;
	memset(sCmdPos,0,sizeof(sCmdPos));
	while(pResHead!= NULL){

		pResTemp= pResHead;
		pResHead= pResHead->pNext;

		replace(pResTemp->sTemplate,SUBST,pResTemp->sSubParam,sOutPut);
		BindValue(ptInfoItem,sOutPut,sResult);

		/*是否需要添有命令头尾*/
		AddCmdHeadTail(sResult);
		iCmdLen= strlen(sResult);
		sprintf(sTemp,"%02x",iCmdLen);
		strcat(sCmdPos,sTemp);

		fputs(sResult,fp);
	}
	fseek(fp,3,SEEK_SET);
	fputs(sCmdPos,fp);
	fclose(fp);

	return 0;
}

/*获取命令的业务代码*/
int GetBusiCode(struct InfoItemStruct *ptInfoItem)
{
	char sTemp[128];
	char *sValue,*sName;

	sValue= ptInfoItem->sValue;
	sName= ptInfoItem->sName;

	/*标志型*/
	if(strlen(sValue)==1)
		if(sValue[0]=='R'||sValue[0]=='E'
		||sValue[0]=='Y'||sValue[0]=='N'
		||(sValue[0]>= '0'&&sValue[0] <= '9')){
			sprintf(sTemp,"%s%c",sName,sValue[0]);
			return SearchBusiCode(sTemp);
		}

	/*有层次的标记型*/
	if(strlen(sValue)==5)
		if(sValue[0]=='D'
			&&sValue[1]>= '0'&&sValue[1] <= '9'
			&&sValue[2]=='+'&&sValue[3]=='+'
			&&(sValue[4]=='R'||sValue[4]=='E')){
			sprintf(sTemp,"%s%c%c",sName,sValue[1],sValue[4]);
			return SearchBusiCode(sTemp);
		}

	/*值方式的参数，直接使用名称*/
	return SearchBusiCode(sName);

}

int SearchBusiCode(char sName[])
{
	int i= 0;

	while(CMDTYPE[i].iValue!= 0&&CMDTYPE[i].sName!= NULL){

		if(strcmp(CMDTYPE[i].sName,sName)==0)
			return CMDTYPE[i].iValue;
		i++;
	}

	return -1;
}

struct ResultStruct *NewResultNode()
{
	struct ResultStruct *pResTemp;

	pResTemp= calloc(1,sizeof(struct ResultStruct));
	if(pResTemp==NULL){
                puts("为结果节点分配内存失败!\n");
                WriteErrStackAlert();
                exit(-1);
	}
	return pResTemp;
}
struct ResultStruct *AddCmd(char sValue[],char sSubSt[],struct ResultStruct **pptHead)
{
	struct ResultStruct *pTemp;

	pTemp= NewResultNode();
	strcpy(pTemp->sTemplate,sValue);
	strcpy(pTemp->sSubParam,sSubSt);
	InsertListTail((LIST**)pptHead,(LIST*)pTemp);
	return pTemp;
}

struct InfoItemStruct * GetItemValue(struct InfoItemStruct *ptHead,char sName[],char sValue[])
{
        strcpy(sValue,"");
        while(ptHead!=NULL){
                if(strcmp(sName,ptHead->sName)==0){
                        strcpy(sValue,ptHead->sValue);
                        return ptHead;
                }
                ptHead=ptHead->pNext;
        }
	return NULL;
}


int IsValidAkey(struct InfoItemStruct *ptInfoItem)
{
	char sValue[128];

	GetItemValue(ptInfoItem,"AKEY",sValue);

	if(strlen(sValue)!= 16)
		return -1;

	return 1;
}

void SwapItemValue(char sNameA[],char sNameB[],struct InfoItemStruct *ptInfoItem)
{
	char sValueA[256],sValueB[256];
	struct InfoItemStruct *pInfoNodeA,*pInfoNodeB;

	pInfoNodeA= GetItemValue(ptInfoItem,sNameA,sValueA);
	pInfoNodeB= GetItemValue(ptInfoItem,sNameB,sValueB);

	strcpy(pInfoNodeA->sValue,sValueB);
	strcpy(pInfoNodeB->sValue,sValueA);

}
