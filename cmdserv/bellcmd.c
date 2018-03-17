/*NEWDN��δ����*/
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
		/*��ɾ��*/
		AddCmd("DELETE-MS:SUBNBR=K'${DN}.","",pptResult);
	}

	if(strcmp(sCmdType,"CHGMDN")==0){
		
		/*ɾ���ɺ��ºſ���*/
		if(AKEYFLAG==0||AKEYFLAG==1){	
			
			AddCmd("DELETE-MS:SUBNBR=K'${DN}.","",pptResult);
			AddCmd("DELETE-MS:SUBNBR=K'${NEWDN}.","",pptResult);
			/*�ºſ���,��Ҫ��ԭ����IMSIΪNEWIMSI*/
			Proc= ProcCRUSER;
			SwapItemValue("DN","NEWDN",ptInfoItem);
		}
		else{
			/*�ĺ�*/
			#define CHGMDN_CMD "MODIFY-MS-DATA:MSIN=K'${IMSI},SNBS=K'${DN}&\"TELE-RT2\",NEWSNBS=K'${NEWDN}&\"TELE-RT2\"."
			AddCmd(CHGMDN_CMD,"",pptResult);
			/*�޸�ҵ��*/
			Proc= ProcCHGSRV;
			SwapItemValue("DN","NEWDN",ptInfoItem);
		}		
	}
	
	/*ɾ���ɺţ��ºſ���*/
	if(strcmp(sCmdType,"CHIMSI")==0){

		AddCmd("DELETE-MS:SUBNBR=K'${DN}.","",pptResult);
		
		/*�ºſ���,��Ҫ��ԭ����IMSIΪNEWIMSI*/
		Proc= ProcCRUSER;
		SwapItemValue("IMSI","NEWIMSI",ptInfoItem);	
	}
	
	ptHead= ptInfoItem;
	
	while(ptHead!= NULL){

		ptTemp= ptHead;
		ptHead= ptHead->pNext;	
		
		/*BELL�� imsiֻ��Ҫ��10λ*/
		if(strcmp(ptTemp->sName,"IMSI")==0||
			strcmp(ptTemp->sName,"NEWIMSI")==0){
			strcpy(sValue,ptTemp->sValue);
			strcpy(ptTemp->sValue,sValue + 5);
		}
		
		/*AKEYת��10����*/
		/*��replaceʱ����*/
		
		if((iBusiCode= GetBusiCode(ptTemp)) <0)
			continue;
		Proc(iBusiCode,pptResult);
		
	}
	return 0;
}

/*�������û�����*/
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
		/*BELL��MSC�ڴ����û�ʱʹ��һ����������ö������*/
		pResult= AddCmd(CREATEMSDATA,"",pptHead);
		iFirst= 1;
	}

	switch(iBusi){
	
		/*���ŷ���(���͡�����)*/
		case SMS2R:
			strcat(sParam,"&K'${DN}&\"SMS-RT1\"");
			strcat(sParam,"&K'${DN}&\"SMS-RT2\"");
			break;

		/*ESNֵ*/
		case ESN:
			strcat(sParam,",ESNBRHEX=H'${ESN}");
			break;

		/*AKEYֵ*/
		case AKEY:
			strcat(sParam,",IAKEY=K'${AKEY}");
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING0R:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING0E:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			break;

		/*����ʱ���������޶�(ʡ������)*/
		case ROAMING1R:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*����ʱ���������޶�(ʡ������)*/
		case ROAMING1E:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING2R:
			strcat(sParam,",SUBRST=NEGLIST,AREA=3");
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING2E:
			strcat(sParam,",SUBRST=POSLIST,AREA=1");
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING3R:
			strcat(sParam,",SUBRST=ONAOFPLM,AREA=0");
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING3E:
			strcat(sParam,",SUBRST=NEGLIST,AREA=3");
			break;

		/*���غ��������޶�*/
		case LOCALE:
			strcat(sParam,",CBOIC");
			break;

		/*��æǰת*/
		case CFBR:
			strcat(sParam,",CFB");
			break;

		/*��Ӧ��ǰת*/
		case CFNRR:
			strcat(sParam,",CFNA");
			break;

		/*����ת��*/
		case CFUR:
			strcat(sParam,",CFU");
			break;

		/*���ɼ�ת��*/
		case CFCR:
			strcat(sParam,",CFD");
			break;

		/*���к���ʶ����ʾ*/
		case CLIRR:
			strcat(sParam,",CNIP");
			break;

		/*���еȴ�*/
		case CWR:
			strcat(sParam,",CALLWAIT");
			break;

		/*���б���*/
		case CHR:
			AddCmd(ENTERSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*��������*/
		case A3WCR:
			strcat(sParam,",PARTYS");
			break;

		/*���к���ʶ����ʾ����*/
		case CNIRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*���к���ʶ����ʾ����*/
		case CNIRE:
			AddCmd(DELSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*��Ϣ�ȴ�֪ͨ*/
		case MWNR:
			AddCmd(ENTERSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*��Ϣ�ȴ�֪ͨ*/
		case MWNE:
			AddCmd(DELSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*��������*/
		case VMRR:
			AddCmd(ENTERSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*��������*/
		case VMRE:
			AddCmd(DELSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*����ת�Ƶ���������(BELL������ָ������)*/
		case CTR:
			strcat(sParam,"");
			break;

		/*����绰(BELL������ָ������)*/
		case CCR:
			strcat(sParam,"");
			break;

		/*����ҵ���޶�*/
		case INTERIM0R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM0E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM1R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM1E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*�������ҵ���޶�*/
		case INTERIM2R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*�������ҵ���޶�*/
		case INTERIM2E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*����ͣ��:������(������)*/
		case USERLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*����ͣ��:������(������)*/
		case USERLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*����ͣ��:���롢������(������)*/
		case USERLOCK2R:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*Ƿ��ͣ��:������(������)*/
		case ACCOUNTLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*Ƿ��ͣ��:������(������)*/
		case ACCOUNTLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*Ƿ��ͣ��:���롢������(������)*/
		case ACCOUNTLOCK2R:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DELINACO",pptHead);
			break;

		/*������(������)*/
		case STOLENLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=STOLUNIT",pptHead);
			break;

		/*������(������)*/
		case DUPLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DUPLUNIT",pptHead);
			break;

		/*������ҵ��(������)*/
		case SMPR:
			strcat(sParam,",INMOC,INMTC,PPCTEMP");
			AddCmd(MODIFYSSV,",SUPSERV=\"INMOC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"INMTC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"PPCTEMP\",STATUS=ACT",pptHead);
			break;

		/*����������ҵ��*/
		case INTERNETR:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			AddCmd(MODIFYMSDATA,",PDSRATE=\"PDR153600\"&\"PDR153600\"",pptHead);
			break;

		/*����������ҵ��*/
		case INTERNETE:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			break;

		/*��������*/
		case CRBTR:
			AddCmd(ENTERSSV,",SUPSERV=\"CRBT\",ROUTDGT=K'1111",pptHead);
			break;

		/*ȡ������*/
		case CRBTE:
			AddCmd(DELSSV,",SUPSERV=\"CRBT\"",pptHead);
			break;

		/*������(PPC)*/
		case WINCOS6:
			AddCmd(MODIFYMSDATA,",WINCOS=6",pptHead);
			break;

		/*������(VPN)*/
		case WINCOS8:
			AddCmd(MODIFYMSDATA,",WINCOS=8",pptHead);
			break;
		
		/*δ֪*/
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
		
		/*���ŷ���(����)*/
		case SMS0R:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*���ŷ���(����)*/
		case SMS0E:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*���ŷ���(����)*/
		case SMS1R:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*���ŷ���(����)*/
		case SMS1E:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*���ŷ���(���͡�����)*/
		case SMS2R:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*���ŷ���(���͡�����)*/
		case SMS2E:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MO\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-MT\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT1\"",pptHead);
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"SMS-RT2\"",pptHead);
			break;

		/*COSֵ*/
		case COS:
			AddCmd(MODIFYMSDATA,",COS=COS",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING0R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING0E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			break;

		/*����ʱ���������޶�(ʡ������)*/
		case ROAMING1R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*����ʱ���������޶�(ʡ������)*/
		case ROAMING1E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING2R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=NEGLIST,AREA=3",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING2E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=1",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=POSLIST,AREA=2",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING3R:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING3E:
			AddCmd(MODIFYMSDATA,",SUBRST=ONAOFPLM,AREA=0",pptHead);
			AddCmd(MODIFYMSDATA,",SUBRST=NEGLIST,AREA=3",pptHead);
			break;

		/*���غ��������޶�*/
		case LOCALR:
			AddCmd(DELSSV,",SUPSERV=\"CBOIC\"",pptHead);
			break;

		/*���غ��������޶�*/
		case LOCALE:
			AddCmd(ENTERSSV,",SUPSERV=\"CBOIC\"",pptHead);
			break;

		/*��æǰת*/
		case CFBR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFBUSY\"",pptHead);
			break;

		/*��æǰת*/
		case CFBE:
			AddCmd(DELSSV,",SUPSERV=\"CFBUSY\"",pptHead);
			break;

		/*��Ӧ��ǰת*/
		case CFNRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFNREPLY\"",pptHead);
			break;

		/*��Ӧ��ǰת*/
		case CFNRE:
			AddCmd(DELSSV,",SUPSERV=\"CFNREPLY\"",pptHead);
			break;

		/*����ת��*/
		case CFUR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFU\"",pptHead);
			break;

		/*����ת��*/
		case CFUE:
			AddCmd(DELSSV,",SUPSERV=\"CFU\"",pptHead);
			break;

		/*���ɼ�ת��*/
		case CFCR:
			AddCmd(ENTERSSV,",SUPSERV=\"CFD\"",pptHead);
			break;

		/*���ɼ�ת��*/
		case CFCE:
			AddCmd(DELSSV,",SUPSERV=\"CFD\"",pptHead);
			break;

		/*���к���ʶ����ʾ*/
		case CLIRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CNIP\"",pptHead);
			break;

		/*���к���ʶ����ʾ*/
		case CLIRE:
			AddCmd(DELSSV,",SUPSERV=\"CNIP\"",pptHead);
			break;

		/*���еȴ�*/
		case CWR:
			AddCmd(ENTERSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*���еȴ�*/
		case CWE:
			AddCmd(DELSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*���б���*/
		case CHR:
			AddCmd(ENTERSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*���б���(ָ������)*/
		case CHE:
			AddCmd(DELSSV,",SUPSERV=\"CALLWAIT\"",pptHead);
			break;

		/*��������*/
		case A3WCR:
			AddCmd(ENTERSSV,",SUPSERV=\"3PARTYS\"",pptHead);
			break;

		/*��������*/
		case A3WCE:
			AddCmd(DELSSV,",SUPSERV=\"3PARTYS\"",pptHead);
			break;

		/*���к���ʶ����ʾ����*/
		case CNIRR:
			AddCmd(ENTERSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*���к���ʶ����ʾ����*/
		case CNIRE:
			AddCmd(DELSSV,",SUPSERV=\"CNIR\"",pptHead);
			break;

		/*��Ϣ�ȴ�֪ͨ*/
		case MWNR:
			AddCmd(ENTERSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*��Ϣ�ȴ�֪ͨ*/
		case MWNE:
			AddCmd(DELSSV,",SUPSERV=\"MESSWAIT\"",pptHead);
			break;

		/*��������*/
		case VMRR:
			AddCmd(ENTERSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*��������*/
		case VMRE:
			AddCmd(DELSSV,",SUPSERV=\"VMNOTIFY\"",pptHead);
			break;

		/*����ת�Ƶ���������(BELL������ָ������)*/
		case CTR:
			strcat(sParam,"");
			break;

		/*����ת�Ƶ���������(BELL������ָ������)*/
		case CTE:
			strcat(sParam,"");
			break;

		/*����绰(BELL������ָ������)*/
		case CCR:
			strcat(sParam,"");
			break;

		/*����绰(BELL������ָ������)*/
		case CCE:
			strcat(sParam,"");
			break;

		/*����ҵ���޶�*/
		case INTERIM0R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM0E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM1R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM1E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*�������ҵ���޶�*/
		case INTERIM2R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*�������ҵ���޶�*/
		case INTERIM2E:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*����ͣ��:������(������)*/
		case USERLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*����ͣ��:������(������)*/
		case USERLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*����ͣ��:���롢������(������)*/
		case USERLOCK2R:
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*��ͣ����:δ����(������)*/
		case USERLOCK2E:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*Ƿ��ͣ��:������(������)*/
		case ACCOUNTLOCK0R:
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBIC\"",pptHead);
			break;

		/*Ƿ��ͣ��:������(������)*/
		case ACCOUNTLOCK1R:
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*Ƿ��ͣ��:���롢������(������)*/
		case ACCOUNTLOCK2R:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DELINACO",pptHead);
			break;

		/*Ƿ�Ѹ���:δ����(������)*/
		case ACCOUNTLOCK2E:
			AddCmd(MODIFYMSDATA,",AUTHDEN=NOTUSED",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBIC\"",pptHead);
			AddCmd(DELSSV,",SUPSERV=\"CBOC\"",pptHead);
			break;

		/*������(������)*/
		case STOLENLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=STOLUNIT",pptHead);
			break;

		/*������(������)*/
		case STOLENLOCKE:
			AddCmd(MODIFYMSDATA,",AUTHDEN=NOTUSED",pptHead);
			break;

		/*������(������)*/
		case DUPLOCKR:
			AddCmd(MODIFYMSDATA,",AUTHDEN=DUPLUNIT",pptHead);
			break;

		/*������(������)*/
		case DUPLOCKE:
			AddCmd(MODIFYMSDATA,",AUTHDEN=NOTUSED",pptHead);
			break;

		/*������ҵ��(������)*/
		case SMPR:
			AddCmd(ENTERSSV,",SUPSERV=\"INMOC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"INMTC\"",pptHead);
			AddCmd(ENTERSSV,",SUPSERV=\"PPCTEMP\"",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"INMOC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"INMTC\",STATUS=ACT",pptHead);
			AddCmd(MODIFYSSV,",SUPSERV=\"PPCTEMP\",STATUS=ACT",pptHead);
			break;

		/*������ҵ��(������)*/
		case SMPE:
			AddCmd(MODIFYMSDATA,",WINCOS=0",pptHead);
			break;

		/*����������ҵ��*/
		case INTERNETR:
			AddCmd(MODIFYMSDATA,",NEWSNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			AddCmd(MODIFYMSDATA,",PDSRATE=\"PDR153600\"&\"PDR153600\"",pptHead);
			break;

		/*����������ҵ��*/
		case INTERNETE:
			AddCmd(MODIFYMSDATA,",SNBS=K'${DN}&\"PDS-3G1X\"",pptHead);
			break;

		/*��������*/
		case CRBTR:
			AddCmd(ENTERSSV,",SUPSERV=\"CRBT\",ROUTDGT=K'1111",pptHead);
			break;

		/*ȡ������*/
		case CRBTE:
			AddCmd(DELSSV,",SUPSERV=\"CRBT\"",pptHead);
			break;

		/*������(PPC)*/
		case WINCOS6:
			AddCmd(MODIFYMSDATA,",WINCOS=6",pptHead);
			break;

		/*������(VPN)*/
		case WINCOS8:
			AddCmd(MODIFYMSDATA,",WINCOS=8",pptHead);
			break;
		/*δ֪*/
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


/*�޸��û�IMSI����*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead)
{

	return 0;
}

#define NEWDN 9999
/*�޸��û�DN����*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead)
{	
#define CHGMDN_CMD "MODIFY-MS-DATA:MSIN=K'${IMSI},SNBS=K'${DN}&\"TELE-RT2\",NEWSNBS=K'${NEWDN}&\"TELE-RT2\"."
	
	/*ֱ�Ӹĺţ��޸�ҵ��*/
	if(iBusi==DN){
		AddCmd(CHGMDN_CMD,"",pptHead);
	}
	return 0;
}

/*�޸��û�ESN����*/
int ProcCHGESN(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�޸��û�PIC����*/
int ProcCHGPIC(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�û���Ϣ��ѯ����*/
int ProcQUINFO(int iBusi,struct ResultStruct **pptHead)
{

	#define QUINFO_CMD "DISPLAY-MS-DATA:SUBNBR=K'${DN},FEATURES=4."

	if(iBusi==DN)
		AddCmd(QUINFO_CMD,"",pptHead);
	return 0;
}

/*�û���Ϣ��ѯ����*/
int ProcUSIRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�������Ӧ��*/
int ProcRSPACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�յ�����Ӧ��*/
int ProcREQACK(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*��������Ϣ*/
int ProcFEBRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�������ݲ�ѯ����*/
int ProcQWINFO(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*����״̬��ѯ����*/
int ProcQWSTAT(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*�������ݲ�ѯ�����Ϣ*/
int ProcWDTRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}

/*��ѯ���������Ϣ*/
int ProcWITRSP(int iBusi,struct ResultStruct **pptHead)
{
	return 0;
}
