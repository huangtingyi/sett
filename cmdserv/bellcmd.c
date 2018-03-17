/*NEWDN还未定义*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmdparse.h"
#include "bellcmd.h"      

int AddCmdHeadTail(char sCmd[])
{
	return 0;
}

int ProcCmd(int(*Proc)(int iBusi,struct ResultStruct **pptHead),
	struct InfoItemStruct *ptInfoItem,char sCmdType[],struct ResultStruct **pptResult)
{
	int iBusiCode;
	char sValue[256];
	struct InfoItemStruct *ptHead,*ptTemp;

	/*CHIMSI,CHMDN CRUSER*/
	if(strcmp(sCmdType,"CRUSER")==0||
		strcmp(sCmdType,"CHGMDN")==0||
		strcmp(sCmdType,"CHIMSI")==0){

			if(AKEYFLAG==0||AKEYFLAG==1){		
				if(IsValidAkey(ptInfoItem)!= 1)
					return -1;
			}
	}
	if(strcmp(sCmdType,"CRUSER")==0){
		/*先删除*/
		AddCmd("DELETE-MS:SUBNBR=K'${DN}.","",pptResult);
	}

	if(strcmp(sCmdType,"CHGMDN")==0){
		
		/*删除旧号新号开户*/
		if(AKEYFLAG==0||AKEYFLAG==1){	
			
			AddCmd("DELETE-MS:SUBNBR=K'${DN}.","",pptResult);
			AddCmd("DELETE-MS:SUBNBR=K'${NEWDN}.","",pptResult);
			/*新号开户,需要换原来的IMSI为NEWIMSI*/
			Proc= ProcCRUSER;
			SwapItemValue("DN","NEWDN",ptInfoItem);
		}
		else{
			/*改号*/
			#define CHGMDN_CMD "MODIFY-MS-DATA:MSIN=K'${IMSI},SNBS=K'${DN}&\"TELE-RT2\",NEWSNBS=K'${NEWDN}&\"TELE-RT2\"."
			AddCmd(CHGMDN_CMD,"",pptResult);
			/*修改业务*/
			Proc= ProcCHGSRV;
			SwapItemValue("DN","NEWDN",ptInfoItem);
		}		
	}
	
	/*删除旧号，新号开户*/
	if(strcmp(sCmdType,"CHIMSI")==0){

		AddCmd("DELETE-MS:SUBNBR=K'${DN}.","",pptResult);
		
		/*新号开户,需要换原来的IMSI为NEWIMSI*/
		Proc= ProcCRUSER;
		SwapItemValue("IMSI","NEWIMSI",ptInfoItem);	
	}
	
	ptHead= ptInfoItem;
	
	while(ptHead!= NULL){

		ptTemp= ptHead;
		ptHead= ptHead->pNext;	
		
		/*BELL的 imsi只需要后10位*/
		if(strcmp(ptTemp->sName,"IMSI")==0||
			strcmp(ptTemp->sName,"NEWIMSI")==0){
			strcpy(sValue,ptTemp->sValue);
			strcpy(ptTemp->sValue,sValue + 5);
		}
		
		/*AKEY转成10进制*/
		/*在replace时处理*/
		
		if((iBusiCode= GetBusiCode(ptTemp)) <0)
			continue;
		Proc(iBusiCode,pptResult);
		
	}
	return 0;
}

/*创建新用户请求*/
int ProcCRUSER(int iBusi,struct ResultStruct **pptHead)
{

#define CREATEMSDATA	"CREATE-MS-DATA:MSIN=K'${IMSI},SNBS=K'${DN}&\"TELE-RT2\"#{SUBST},AUTHDEN=NOTUSED."
#define MODIFYMSDATA	"MODIFY-MS-DATA:SUBNBR=K'${DN}#{SUBST}."
#define ENTERSSV    	"ENTER-SSV:SUBNBR=K'${DN}#{SUBST}."
#define DELSSV      	"DEL-SSV:SUBNBR=K'${DN}#{SUBST}."
#define MODIFYSSV   	"MODIFY-SSV:SUBNBR=K'${DN}#{SUBST}."
	
	static int iFirst= 0;
	static struct ResultStruct *pResult;
	char sParam[8192];
	
	memset(sParam,0,8192);
	
	if(iFirst==0){
		/*BELL的MSC在创建用户时使用一条命令的设置多个参数*/
		pResult= AddCmd(CREATEMSDATA,"",pptHead);
		iFirst= 1;
	}

	switch(iBusi){
	
		/*短信服务(发送、接受)*/
		case SMS2R:
			strcat(sParam,"&K'${DN}&\"SMS-RT1\"");
			strcat(sParam,"&K'${DN}&\"SMS-RT2\"");
			break;

		/*ESN值*/
		case ESN:
			strcat(sParam,",ESNBRHEX=H'${ESN}");
			break;

		/*AKEY值*/
		case AKEY:
			strcat(sParam,",IAKEY=K'${AKEY}");
			break;

		/*漫游时呼叫能力限定(本市漫游)*/
		case ROAMING0R:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			break;

		/*漫游时呼叫能力限定(本市漫游)*/
		case ROAMING0E:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			break;

		/*漫游时呼叫能力限定(省内漫游)*/
		case ROAMING1R:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*漫游时呼叫能力限定(省内漫游)*/
		case ROAMING1E:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			break;

		/*漫游时呼叫能力限定(国内漫游)*/
		case ROAMING2R:
			strcat(sParam,",SUBRST=NEGLIST,AREA=3");
			break;

		/*漫游时呼叫能力限定(国内漫游)*/
		case ROAMING2E:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*漫游时呼叫能力限定(国际漫游)*/
		case ROAMING3R:
			strcat(sParam,",SUBRST=ONAOFPLM,AREA=0");
			break;

		/*漫游时呼叫能力限定(国际漫游)*/
		case ROAMING3E:
			strcat(sParam,",SUBRST=NEGLIST,AREA=3");
			break;

		/*本地呼叫能力限定*/
		case LOCALE:
			strcat(sParam,",CBOIC");
			break;

		/*遇忙前转*/
		case CFBR:
			strcat(sParam,",CFB");
			break;

		/*无应答前转*/
		case CFNRR:
			strcat(sParam,",CFNA");
			break;

		/*立即转移*/
		case CFUR:
			strcat(sParam,",CFU");
			break;

		/*不可及转移*/
		case CFCR:
			strcat(sParam,",CFD");
			break;

		/*主叫号码识别显示*/
		case CLIRR:
			strcat(sParam,",CNIP");
			break;

		/*呼叫等待*/
		case CWR:
			strcat(sParam,",CALLWAIT");
			break;

		/*呼叫保持*/
		case CHR:
			AddCmd(ENTERSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*三方呼叫*/
		case A3WCR:
			strcat(sParam,",PARTYS");
			break;

		/*主叫号码识别显示限制*/
		case CNIRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*主叫号码识别显示限制*/
		case CNIRE:
			AddCmd(DELSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*消息等待通知*/
		case MWNR:
			AddCmd(ENTERSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*消息等待通知*/
		case MWNE:
			AddCmd(DELSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*话音邮箱*/
		case VMRR:
			AddCmd(ENTERSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*话音邮箱*/
		case VMRE:
			AddCmd(DELSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*呼叫转移到语音信箱(BELL交换机指令暂无)*/
		case CTR:
			strcat(sParam,"");
			break;

		/*会议电话(BELL交换机指令暂无)*/
		case CCR:
			strcat(sParam,"");
			break;

		/*来话业务限定*/
		case INTERIM0R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*来话业务限定*/
		case INTERIM0E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*呼出业务限定*/
		case INTERIM1R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*呼出业务限定*/
		case INTERIM1E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*呼入呼出业务限定*/
		case INTERIM2R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*呼入呼出业务限定*/
		case INTERIM2E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*主动停机:呼入锁(甘肃用)*/
		case USERLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*主动停机:呼出锁(甘肃用)*/
		case USERLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*主动停机:呼入、呼出锁(甘肃用)*/
		case USERLOCK2R:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*欠费停机:呼入锁(甘肃用)*/
		case ACCOUNTLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*欠费停机:呼出锁(甘肃用)*/
		case ACCOUNTLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*欠费停机:呼入、呼出锁(甘肃用)*/
		case ACCOUNTLOCK2R:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DELINACO",pptHead);
			break;

		/*被盗锁(甘肃用)*/
		case STOLENLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=STOLUNIT",pptHead);
			break;

		/*复制锁(甘肃用)*/
		case DUPLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DUPLUNIT",pptHead);
			break;

		/*智能网业务(甘肃用)*/
		case SMPR:
			strcat(sParam,",INMOC,INMTC,PPCTEMP");
			AddCmd(MODIFYSSV,",SUPSERV=\"INMOC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"INMTC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"PPCTEMP\",STATUS=ACT",pptHead);
			break;

		/*互联网数据业务*/
		case INTERNETR:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			AddCmd(MODIFYMSDATA,",PDSRATE=\"PDR153600\"&\"PDR153600\"",pptHead);
			break;

		/*互联网数据业务*/
		case INTERNETE:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			break;

		/*增加炫铃*/
		case CRBTR:
			AddCmd(ENTERSSV,",SUPSERV=\"CRBT\",ROUTDGT=K'1111",pptHead);
			break;

		/*取消炫铃*/
		case CRBTE:
			AddCmd(DELSSV,",SUPSERV=\"CRBT\"",pptHead);
			break;

		/*智能网(PPC)*/
		case WINCOS6:
			AddCmd(MODIFYMSDATA,",WINCOS=6",pptHead);
			break;

		/*智能网(VPN)*/
		case WINCOS8:
			AddCmd(MODIFYMSDATA,",WINCOS=8",pptHead);
			break;
		
		/*未知*/
		default:
			break;
	}

	strcat(pResult->sSubParam,sParam);
	puts(pResult->sSubParam);
	return 0;
}

int ProcCHGSRV(int iBusi,struct ResultStruct **pptHead)
{

#define CREATEMSDATA	"CREATE-MS-DATA:MSIN=K'${IMSI},SNBS=K'${DN}&\"TELE-RT2\"#{SUBST},AUTHDEN=NOTUSED."
#define MODIFYMSDATA	"MODIFY-MS-DATA:SUBNBR=K'${DN}#{SUBST}."
#define ENTERSSV    	"ENTER-SSV:SUBNBR=K'${DN}#{SUBST}."
#define DELSSV      	"DEL-SSV:SUBNBR=K'${DN}#{SUBST}."
#define MODIFYSSV   	"MODIFY-SSV:SUBNBR=K'${DN}#{SUBST}."
	char sParam[1024];

	switch(iBusi){
		
		/*短信服务(发送)*/
		case SMS0R:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*短信服务(发送)*/
		case SMS0E:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*短信服务(接受)*/
		case SMS1R:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*短信服务(接受)*/
		case SMS1E:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*短信服务(发送、接受)*/
		case SMS2R:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*短信服务(发送、接受)*/
		case SMS2E:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*COS值*/
		case COS:
			AddCmd(MODIFYMSDATA,",COS=COS",pptHead);
			break;

		/*漫游时呼叫能力限定(本市漫游)*/
		case ROAMING0R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			break;

		/*漫游时呼叫能力限定(本市漫游)*/
		case ROAMING0E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			break;

		/*漫游时呼叫能力限定(省内漫游)*/
		case ROAMING1R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*漫游时呼叫能力限定(省内漫游)*/
		case ROAMING1E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			break;

		/*漫游时呼叫能力限定(国内漫游)*/
		case ROAMING2R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=NEGLIST,AREA=3",pptHead);
			break;

		/*漫游时呼叫能力限定(国内漫游)*/
		case ROAMING2E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*漫游时呼叫能力限定(国际漫游)*/
		case ROAMING3R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			break;

		/*漫游时呼叫能力限定(国际漫游)*/
		case ROAMING3E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=NEGLIST,AREA=3",pptHead);
			break;

		/*本地呼叫能力限定*/
		case LOCALR:
			AddCmd(DELSSV,",SUPSERV=\"CBOIC\"",pptHead);
			break;

		/*本地呼叫能力限定*/
		case LOCALE:
			AddCmd(ENTERSSV,",SUPSERV=\"CBOIC\"",pptHead);
			break;

		/*遇忙前转*/
		case CFBR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFBUSY\"",pptHead);
			break;

		/*遇忙前转*/
		case CFBE:
			AddCmd(DELSSV,",SUPSERV=\"CFBUSY\"",pptHead);
			break;

		/*无应答前转*/
		case CFNRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFNREPLY\"",pptHead);
			break;

		/*无应答前转*/
		case CFNRE:
			AddCmd(DELSSV,",SUPSERV=\"CFNREPLY\"",pptHead);
			break;

		/*立即转移*/
		case CFUR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFU\"",pptHead);
			break;

		/*立即转移*/
		case CFUE:
			AddCmd(DELSSV,",SUPSERV=\"CFU\"",pptHead);
			break;

		/*不可及转移*/
		case CFCR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFD\"",pptHead);
			break;

		/*不可及转移*/
		case CFCE:
			AddCmd(DELSSV,",SUPSERV=\"CFD\"",pptHead);
			break;

		/*主叫号码识别显示*/
		case CLIRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CNIP\"",pptHead);
			break;

		/*主叫号码识别显示*/
		case CLIRE:
			AddCmd(DELSSV,",SUPSERV=\"CNIP\"",pptHead);
			break;

		/*呼叫等待*/
		case CWR:
			AddCmd(ENTERSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*呼叫等待*/
		case CWE:
			AddCmd(DELSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*呼叫保持*/
		case CHR:
			AddCmd(ENTERSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*呼叫保持(指令暂无)*/
		case CHE:
			AddCmd(DELSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*三方呼叫*/
		case A3WCR:
			AddCmd(ENTERSSV,",SUPSERV=\"3PARTYS\"",pptHead);
			break;

		/*三方呼叫*/
		case A3WCE:
			AddCmd(DELSSV,",SUPSERV=\"3PARTYS\"",pptHead);
			break;

		/*主叫号码识别显示限制*/
		case CNIRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*主叫号码识别显示限制*/
		case CNIRE:
			AddCmd(DELSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*消息等待通知*/
		case MWNR:
			AddCmd(ENTERSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*消息等待通知*/
		case MWNE:
			AddCmd(DELSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*话音邮箱*/
		case VMRR:
			AddCmd(ENTERSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*话音邮箱*/
		case VMRE:
			AddCmd(DELSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*呼叫转移到语音信箱(BELL交换机指令暂无)*/
		case CTR:
			strcat(sParam,"");
			break;

		/*呼叫转移到语音信箱(BELL交换机指令暂无)*/
		case CTE:
			strcat(sParam,"");
			break;

		/*会议电话(BELL交换机指令暂无)*/
		case CCR:
			strcat(sParam,"");
			break;

		/*会议电话(BELL交换机指令暂无)*/
		case CCE:
			strcat(sParam,"");
			break;

		/*来话业务限定*/
		case INTERIM0R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*来话业务限定*/
		case INTERIM0E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*呼出业务限定*/
		case INTERIM1R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*呼出业务限定*/
		case INTERIM1E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*呼入呼出业务限定*/
		case INTERIM2R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*呼入呼出业务限定*/
		case INTERIM2E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*主动停机:呼入锁(甘肃用)*/
		case USERLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*主动停机:呼出锁(甘肃用)*/
		case USERLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*主动停机:呼入、呼出锁(甘肃用)*/
		case USERLOCK2R:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*报停复机:未加锁(甘肃用)*/
		case USERLOCK2E:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*欠费停机:呼入锁(甘肃用)*/
		case ACCOUNTLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*欠费停机:呼出锁(甘肃用)*/
		case ACCOUNTLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*欠费停机:呼入、呼出锁(甘肃用)*/
		case ACCOUNTLOCK2R:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DELINACO",pptHead);
			break;

		/*欠费复机:未加锁(甘肃用)*/
		case ACCOUNTLOCK2E:
			AddCmd(MODIFYMSDATA,",AUTHDEN=NOTUSED",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*被盗锁(甘肃用)*/
		case STOLENLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=STOLUNIT",pptHead);
			break;

		/*被盗锁(甘肃用)*/
		case STOLENLOCKE:
			AddCmd(MODIFYMSDATA,",AUTHDEN=NOTUSED",pptHead);
			break;

		/*复制锁(甘肃用)*/
		case DUPLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DUPLUNIT",pptHead);
			break;

		/*复制锁(甘肃用)*/
		case DUPLOCKE:
			AddCmd(MODIFYMSDATA,",AUTHDEN=NOTUSED",pptHead);
			break;

		/*智能网业务(甘肃用)*/
		case SMPR:
			AddCmd(ENTERSSV,",SUPSERV=\"INMOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"INMTC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"PPCTEMP\"",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"INMOC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"INMTC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"PPCTEMP\",STATUS=ACT",pptHead);
			break;

		/*智能网业务(甘肃用)*/
		case SMPE:
			AddCmd(MODIFYMSDATA,",WINCOS=0",pptHead);
			break;

		/*互联网数据业务*/
		case INTERNETR:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			AddCmd(MODIFYMSDATA,",PDSRATE=\"PDR153600\"&\"PDR153600\"",pptHead);
			break;

		/*互联网数据业务*/
		case INTERNETE:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			break;

		/*增加炫铃*/
		case CRBTR:
			AddCmd(ENTERSSV,",SUPSERV=\"CRBT\",ROUTDGT=K'1111",pptHead);
			break;

		/*取消炫铃*/
		case CRBTE:
			AddCmd(DELSSV,",SUPSERV=\"CRBT\"",pptHead);
			break;

		/*智能网(PPC)*/
		case WINCOS6:
			AddCmd(MODIFYMSDATA,",WINCOS=6",pptHead);
			break;

		/*智能网(VPN)*/
		case WINCOS8:
			AddCmd(MODIFYMSDATA,",WINCOS=8",pptHead);
			break;
		/*未知*/
		default:
			break;
	}
	return 0;
}

int ProcDLUSER(int iBusi,struct ResultStruct **pptHead)
{
	if(iBusi==DN)
		AddCmd("DELETE-MS:SUBNBR=K'${DN}.","",pptHead);

	return 0;
}


/*修改用户IMSI请求*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead)
{

	return 0;
}

#define NEWDN 9999
/*修改用户DN请求*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead)
{	
#define CHGMDN_CMD "MODIFY-MS-DATA:MSIN=K'${IMSI},SNBS=K'${DN}&\"TELE-RT2\",NEWSNBS=K'${NEWDN}&\"TELE-RT2\"."
	
	/*直接改号，修改业务*/
	if(iBusi==DN){
		AddCmd(CHGMDN_CMD,"",pptHead);
	}
	return 0;
}

/*修改用户ESN请求*/
int ProcCHGESN(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*修改用户PIC请求*/
int ProcCHGPIC(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*用户信息查询请求*/
int ProcQUINFO(int iBusi,struct ResultStruct **pptHead)
{

	#define QUINFO_CMD "DISPLAY-MS-DATA:SUBNBR=K'${DN},FEATURES=4."

	if(iBusi==DN)
		AddCmd(QUINFO_CMD,"",pptHead);
	return 0;
}

/*用户信息查询反馈*/
int ProcUSIRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*反馈结果应答*/
int ProcRSPACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*收到请求应答*/
int ProcREQACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*请求结果消息*/
int ProcFEBRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*工单内容查询请求*/
int ProcQWINFO(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*工单状态查询请求*/
int ProcQWSTAT(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*工单内容查询结果消息*/
int ProcWDTRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*查询工单结果消息*/
int ProcWITRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}
