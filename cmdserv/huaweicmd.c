/*NEWDN还未定义*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmdparse.h"
#include "huaweicmd.h"

int AddCmdHeadTail(char sCmd[])
{
	char sTmpCmd[8192];
	
	/*0x02+command+';'+0x10+0x03*/
	strcpy(sTmpCmd,sCmd);
	sprintf(sCmd,"%c%s;%c%c",2,sTmpCmd,10,3);

	return 0;
}


int ProcCmd(int(*Proc)(int iBusi,struct ResultStruct **pptHead),
	struct InfoItemStruct *ptInfoItem,char sCmdType[],struct ResultStruct **pptResult)
{
	int iBusiCode;
	char sValue[256],sNValue[256],sCmd[256];
	struct InfoItemStruct *ptHead,*ptTemp;

	if(strcmp(sCmdType,"CRUSER")==0){

		/*先增加*/
		AddCmd("def-withtemp:imsi=\"${IMSI}\",mdn=\"${DN}\",tempno=0,ifac=1","",pptResult);
		/*AKey*/
		AddCmd("mod-acsvr:imsi=\"${IMSI}\",msauth=2,shareallow=1,ssdrefacc=1","",pptResult);
		/*修改业务*/
		Proc= ProcCHGSRV;
	}

	if(strcmp(sCmdType,"CHGMDN")==0){
		
		/*改号*/
		GetItemValue(ptInfoItem,"DN",sValue);
		GetItemValue(ptInfoItem,"NEWDN",sNValue);
		sprintf(sCmd,"chg-mdn:oldmdn=\"%s\",newmdn=\"%s\"",sValue,sNValue);

		/*业务变更,需要换原来的DN为NEWDN*/		
		AddCmd(sCmd,"",pptResult);
		Proc= ProcCHGSRV;
		SwapItemValue("DN","NEWDN",ptInfoItem);			
	}
	
	/*删除旧号，新号开户*/
	if(strcmp(sCmdType,"CHIMSI")==0){

		/*改IMSI号*/
		GetItemValue(ptInfoItem,"DN",sValue);
		GetItemValue(ptInfoItem,"NEWIMSI",sNValue);
		sprintf(sCmd,"chg-imsi:mdn=\"86%s\",newimsi=\"%s\",ifac=1,forceflag=1",sValue,sNValue);		
		AddCmd(sCmd,"",pptResult);
		/*AKEY*/
		AddCmd("mod-acsvr:imsi=\"${IMSI}\",msauth=2,shareallow=1,ssdrefacc=1","",pptResult);

		/*业务变更,需要换原来的IMSI为NEWIMSI*/
		Proc= ProcCHGSRV;
		SwapItemValue("IMSI","NEWIMSI",ptInfoItem);	
	}
	
	ptHead= ptInfoItem;
	
	while(ptHead!= NULL){

		ptTemp= ptHead;
		ptHead= ptHead->pNext;	
		
		/*HUAWEI的DN前面需加86*/
		if(strcmp(ptTemp->sName,"DN")==0||
			strcmp(ptTemp->sName,"NEWDN")==0){
				
			strcpy(sValue,ptTemp->sValue);
			strcpy(ptTemp->sValue,"86");
			strcat(ptTemp->sValue,sValue);
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
		
	/*不会执行到此处，在ProcCmd执行*/
	if(iBusi==DN){
		AddCmd("def-withtemp:imsi=\"${IMSI}\",mdn=\"${DN}\",tempno=0,ifac=1","",pptHead);
	}

	return 0;
}

int ProcCHGSRV(int iBusi,struct ResultStruct **pptHead)
{

	switch(iBusi){
		
		/*AKEY值*/
		case AKEY:
			AddCmd("mod-acsvr:imsi=\"${IMSI}\",msauth=2,shareallow=1,ssdrefacc=1","",pptHead);
			break;

		/*短信服务(发送)*/
		case SMS0R:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=true","",pptHead);
			break;

		/*短信服务(发送)*/
		case SMS0E:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=false","",pptHead);
			break;

		/*短信服务(接受)*/
		case SMS1R:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmtpp=true","",pptHead);
			break;

		/*短信服务(接受)*/
		case SMS1E:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmtpp=false","",pptHead);
			break;

		/*短信服务(发送、接受)*/
		case SMS2R:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=true,smmtpp=true","",pptHead);
			break;

		/*短信服务(发送、接受)*/
		case SMS2E:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=false,smmtpp=false","",pptHead);
			break;

		/*漫游时呼叫能力限定(本市漫游)*/
		case ROAMING0R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*漫游时呼叫能力限定(本市漫游)*/
		case ROAMING0E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*漫游时呼叫能力限定(省内漫游)*/
		case ROAMING1R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*漫游时呼叫能力限定(省内漫游)*/
		case ROAMING1E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*漫游时呼叫能力限定(国内漫游)*/
		case ROAMING2R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=1","",pptHead);
			break;

		/*漫游时呼叫能力限定(国内漫游)*/
		case ROAMING2E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*漫游时呼叫能力限定(国际漫游)*/
		case ROAMING3R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=0","",pptHead);
			break;

		/*漫游时呼叫能力限定(国际漫游)*/
		case ROAMING3E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=1","",pptHead);
			break;

		/*遇忙前转*/
		case CFBR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfb=true","",pptHead);
			break;

		/*遇忙前转*/
		case CFBE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfb=false","",pptHead);
			break;

		/*无应答前转*/
		case CFNRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfna=true","",pptHead);
			break;

		/*无应答前转*/
		case CFNRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfna=false","",pptHead);
			break;

		/*立即转移*/
		case CFUR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfu=true","",pptHead);
			break;

		/*立即转移*/
		case CFUE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfu=false","",pptHead);
			break;

		/*不可及转移*/
		case CFCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfd=true","",pptHead);
			break;

		/*不可及转移*/
		case CFCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfd=false","",pptHead);
			break;

		/*主叫号码识别显示*/
		case CLIRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnip=true","",pptHead);
			break;

		/*主叫号码识别显示*/
		case CLIRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnip=false","",pptHead);
			break;

		/*呼叫等待*/
		case CWR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cw=true","",pptHead);
			break;

		/*呼叫等待*/
		case CWE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cw=false","",pptHead);
			break;

		/*三方呼叫*/
		case A3WCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",wc3=true","",pptHead);
			break;

		/*三方呼叫*/
		case A3WCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",wc3=false","",pptHead);
			break;

		/*主叫号码识别显示限制*/
		case CNIRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnir=true","",pptHead);
			break;

		/*主叫号码识别显示限制*/
		case CNIRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnir=false","",pptHead);
			break;

		/*消息等待通知*/
		case MWNR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",mwn=true","",pptHead);
			break;

		/*消息等待通知*/
		case MWNE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",mwn=false","",pptHead);
			break;

		/*话音邮箱*/
		case VMRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",vmr=true","",pptHead);
			break;

		/*话音邮箱*/
		case VMRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",vmr=false","",pptHead);
			break;

		/*呼叫转移到语音信箱*/
		case CTR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",ct=true","",pptHead);
			break;

		/*呼叫转移到语音信箱*/
		case CTE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",ct=false","",pptHead);
			break;

		/*会议电话*/
		case CCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cc=true","",pptHead);
			break;

		/*会议电话*/
		case CCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cc=false","",pptHead);
			break;

		/*远程业务控(甘肃用)*/
		case RFCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",rfc=true","",pptHead);
			break;

		/*远程业务控制(甘肃用)*/
		case RFCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",rfc=false","",pptHead);
			break;

		/*来话业务限定*/
		case INTERIM0R:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=2","",pptHead);
			break;

		/*来话业务限定*/
		case INTERIM0E:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=1","",pptHead);
			break;

		/*呼出业务限定(呼出允许，为国内长途允许?)*/
		case INTERIM1R:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=6","",pptHead);
			break;

		/*呼出业务限定*/
		case INTERIM1E:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=2","",pptHead);
			break;

		/*呼入呼出业务限定*/
		case INTERIM2R:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=2,origin=6","",pptHead);
			break;

		/*呼入呼出业务限定*/
		case INTERIM2E:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=1,origin=2","",pptHead);
			break;

		/*本地呼叫能力限定*/
		case LOCALR:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=7","",pptHead);
			break;

		/*本地呼叫能力限定*/
		case LOCALE:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=6","",pptHead);
			break;

		/*主动停机:呼入锁(甘肃用)*/
		case USERLOCK0R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=1","",pptHead);
			break;

		/*主动停机:呼出锁(甘肃用)*/
		case USERLOCK1R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=2","",pptHead);
			break;

		/*主动停机:呼入、呼出锁(甘肃用)*/
		case USERLOCK2R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=3","",pptHead);
			break;

		/*报停复机:未加锁(甘肃用)*/
		case USERLOCK2E:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=0","",pptHead);
			break;

		/*欠费停机:呼入锁(甘肃用)*/
		case ACCOUNTLOCK0R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=1","",pptHead);
			break;

		/*欠费停机:呼出锁(甘肃用)*/
		case ACCOUNTLOCK1R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=2","",pptHead);
			break;

		/*欠费停机:呼入、呼出锁(甘肃用)*/
		case ACCOUNTLOCK2R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=3","",pptHead);
			break;

		/*欠费复机:未加锁(甘肃用)*/
		case ACCOUNTLOCK2E:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=0","",pptHead);
			break;

		/*被盗锁(甘肃用)*/
		case STOLENLOCKR:
			AddCmd("mod-lockstat:mdn=\"${DN}\",stolenlock=3","",pptHead);
			break;

		/*被盗锁(甘肃用)*/
		case STOLENLOCKE:
			AddCmd("mod-lockstat:mdn=\"${DN}\",stolenlock=0","",pptHead);
			break;

		/*复制锁(甘肃用)*/
		case DUPLOCKR:
			AddCmd("mod-lockstat:mdn=\"${DN}\",duplock=3","",pptHead);
			break;

		/*复制锁(甘肃用)*/
		case DUPLOCKE:
			AddCmd("mod-lockstat:mdn=\"${DN}\",duplock=0","",pptHead);
			break;

		/*移动自由呼:遇忙前转(新疆用)*/
		case CFSVR0R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=1,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*移动自由呼:遇忙前转(新疆用)*/
		case CFSVR0E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=1,cfnum=\"${CFDN}\",ifActive=2,voice=0","",pptHead);
			break;

		/*移动自由呼:隐含条件前转(新疆用)*/
		case CFSVR1R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=2,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*移动自由呼:隐含条件前转(新疆用)*/
		case CFSVR1E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",ifActive=2,cfscode=2,voice=0","",pptHead);
			break;

		/*移动自由呼:无应答前转(新疆用)*/
		case CFSVR2R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=3,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*移动自由呼:无应答前转(新疆用)*/
		case CFSVR2E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=3,cfnum=\"${CFDN}\",ifActive=2,voice=0","",pptHead);
			break;

		/*移动自由呼:无条件前转(新疆用)*/
		case CFSVR3R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=4,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*移动自由呼:无条件前转(新疆用)*/
		case CFSVR3E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=4,cfnum=\"${CFDN}\",ifActive=2,voice=0","",pptHead);
			break;

		/*智能业务(甘肃用)*/
		case SMP0E:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=${SID},ServiceFlag=1,ScpNo=${SCPNO},dppc=${DPPC},fcn=${FCN},cfna=${CFNA}","",pptHead);
			break;

		/*智能业务(甘肃用)*/
		case SMP1E:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=${SID},ServiceFlag=2,ScpNo=${SCPNO},dppc=${DPPC},fcn=${FCN},cfna=${CFNA}","",pptHead);
			break;

		/*智能业务(甘肃用)*/
		case SMP1R:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=${SID},ServiceFlag=3,ScpNo=${SCPNO},dppc=${DPPC},fcn=${FCN},cfna=${CFNA}","",pptHead);
			break;

		/*智能业务VPN*/
		case VPNR:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=130,ServiceFlag=3,ScpNo=${SCPNO}","",pptHead);
			break;

		/*智能业务VPN*/
		case VPNE:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=130,ServiceFlag=1,ScpNo=${SCPNO}","",pptHead);
			break;

		/*智能业务PPC*/
		case PPCR:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=128,ServiceFlag=3,ScpNo=${SCPNO}","",pptHead);
			break;

		/*智能业务PPC*/
		case PPCE:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=128,ServiceFlag=1,ScpNo=${SCPNO}","",pptHead);
			break;

		/*互联网数据业务*/
		case INTERNETR:
			AddCmd("mod-datasvr:mdn=\"${DN}\",PDS1=true","",pptHead);
			break;

		/*互联网数据业务*/
		case INTERNETE:
			AddCmd("mod-datasvr:mdn=\"${DN}\",PDS1=false","",pptHead);
			break;

		/*彩铃业务*/
		case CL0R:
			AddCmd("mod-crbt:mdn=\"${DN}\",crbt=3","",pptHead);
			break;

		/**/
		case CL0E:
			AddCmd("mod-crbt:mdn=\"${DN}\",crbt=1","",pptHead);
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
		AddCmd("del-subscr:mdn=\"${DN}\",forceflag=1","",pptHead);

	return 0;
}


/*修改用户IMSI请求*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead)
{
	/*不会执行到此处，在ProcCmd执行*/
	if(iBusi==DN)
		AddCmd("chg-imsi:mdn=\"86${DN}\",newimsi=\"${NEWIMSI}\",ifac=1,forceflag=1","",pptHead);

	return 0;
}

/*修改用户DN请求*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead)
{
	/*不会执行到此处，在ProcCmd执行*/
	if(iBusi==DN)
		AddCmd("chg-mdn:oldmdn=\"%{DN}\",newmdn=\"${NEWDN}\"","",pptHead);
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
	switch(iBusi){

		/*号码互查*/
		case INQCODE:
			AddCmd("inq-code:mdn=\"${DN}\"","",pptHead);
			break;

		/*鉴权能力*/
			break;

		/*LOCAL*/
		case LSTLOCAL:
			AddCmd("lst-restrsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*ROAMING*/
		case LSTROAMING:
			AddCmd("lst-msclist:mdn=\"${DN}\"","",pptHead);
			break;

		/*查询来话业务限定*/
		case LSTINTERIM:
			AddCmd("lst-restrsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*查询短信服务*/
		case LSTSMS:
			AddCmd("lst-telsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*查询用户补充业务*/
		case LSTSUPSVR:
			AddCmd("lst-supsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*查询锁状态(甘肃用)*/
			break;

		/*移动自由呼CFB(新疆用)*/
		case LSTCFB:
			AddCmd("lst-cfsvr:cfscode=1,mdn=\"${DN}\"","",pptHead);
			break;

		/*移动自由呼CFD(新疆用)*/
		case LSTCFD:
			AddCmd("lst-cfsvr:cfscode=2,mdn=\"${DN}\"","",pptHead);
			break;

		/*移动自由呼CFNA(新疆用)*/
		case LSTCFNA:
			AddCmd("lst-cfsvr:cfscode=3,mdn=\"${DN}\"","",pptHead);
			break;

		/*移动自由呼CFU(新疆用)*/
		case LSTCFU:
			AddCmd("lst-cfsvr:cfscode=4,mdn=\"${DN}\"","",pptHead);
			break;

		/*查询智能网功能*/
		case LSTWINSVR:
			AddCmd("lst-winsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*查询INTERNET功能*/
		case LSTINTERNET:
			AddCmd("lst-datasvr:mdn=\"${DN}\"","",pptHead);
			break;
			
		/*未知*/
		default:
			break;
	}
	
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
