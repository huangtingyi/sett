/*NEWDN��δ����*/
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

		/*������*/
		AddCmd("def-withtemp:imsi=\"${IMSI}\",mdn=\"${DN}\",tempno=0,ifac=1","",pptResult);
		/*AKey*/
		AddCmd("mod-acsvr:imsi=\"${IMSI}\",msauth=2,shareallow=1,ssdrefacc=1","",pptResult);
		/*�޸�ҵ��*/
		Proc= ProcCHGSRV;
	}

	if(strcmp(sCmdType,"CHGMDN")==0){
		
		/*�ĺ�*/
		GetItemValue(ptInfoItem,"DN",sValue);
		GetItemValue(ptInfoItem,"NEWDN",sNValue);
		sprintf(sCmd,"chg-mdn:oldmdn=\"%s\",newmdn=\"%s\"",sValue,sNValue);

		/*ҵ����,��Ҫ��ԭ����DNΪNEWDN*/		
		AddCmd(sCmd,"",pptResult);
		Proc= ProcCHGSRV;
		SwapItemValue("DN","NEWDN",ptInfoItem);			
	}
	
	/*ɾ���ɺţ��ºſ���*/
	if(strcmp(sCmdType,"CHIMSI")==0){

		/*��IMSI��*/
		GetItemValue(ptInfoItem,"DN",sValue);
		GetItemValue(ptInfoItem,"NEWIMSI",sNValue);
		sprintf(sCmd,"chg-imsi:mdn=\"86%s\",newimsi=\"%s\",ifac=1,forceflag=1",sValue,sNValue);		
		AddCmd(sCmd,"",pptResult);
		/*AKEY*/
		AddCmd("mod-acsvr:imsi=\"${IMSI}\",msauth=2,shareallow=1,ssdrefacc=1","",pptResult);

		/*ҵ����,��Ҫ��ԭ����IMSIΪNEWIMSI*/
		Proc= ProcCHGSRV;
		SwapItemValue("IMSI","NEWIMSI",ptInfoItem);	
	}
	
	ptHead= ptInfoItem;
	
	while(ptHead!= NULL){

		ptTemp= ptHead;
		ptHead= ptHead->pNext;	
		
		/*HUAWEI��DNǰ�����86*/
		if(strcmp(ptTemp->sName,"DN")==0||
			strcmp(ptTemp->sName,"NEWDN")==0){
				
			strcpy(sValue,ptTemp->sValue);
			strcpy(ptTemp->sValue,"86");
			strcat(ptTemp->sValue,sValue);
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
		
	/*����ִ�е��˴�����ProcCmdִ��*/
	if(iBusi==DN){
		AddCmd("def-withtemp:imsi=\"${IMSI}\",mdn=\"${DN}\",tempno=0,ifac=1","",pptHead);
	}

	return 0;
}

int ProcCHGSRV(int iBusi,struct ResultStruct **pptHead)
{

	switch(iBusi){
		
		/*AKEYֵ*/
		case AKEY:
			AddCmd("mod-acsvr:imsi=\"${IMSI}\",msauth=2,shareallow=1,ssdrefacc=1","",pptHead);
			break;

		/*���ŷ���(����)*/
		case SMS0R:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=true","",pptHead);
			break;

		/*���ŷ���(����)*/
		case SMS0E:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=false","",pptHead);
			break;

		/*���ŷ���(����)*/
		case SMS1R:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmtpp=true","",pptHead);
			break;

		/*���ŷ���(����)*/
		case SMS1E:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmtpp=false","",pptHead);
			break;

		/*���ŷ���(���͡�����)*/
		case SMS2R:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=true,smmtpp=true","",pptHead);
			break;

		/*���ŷ���(���͡�����)*/
		case SMS2E:
			AddCmd("mod-telsvr:mdn=\"${DN}\",smmopp=false,smmtpp=false","",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING0R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING0E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*����ʱ���������޶�(ʡ������)*/
		case ROAMING1R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*����ʱ���������޶�(ʡ������)*/
		case ROAMING1E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING2R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=1","",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING2E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=2,tempno=1","",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING3R:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=0","",pptHead);
			break;

		/*����ʱ���������޶�(��������)*/
		case ROAMING3E:
			AddCmd("mod-msclist:mdn=\"${DN}\",roamflag=1","",pptHead);
			break;

		/*��æǰת*/
		case CFBR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfb=true","",pptHead);
			break;

		/*��æǰת*/
		case CFBE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfb=false","",pptHead);
			break;

		/*��Ӧ��ǰת*/
		case CFNRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfna=true","",pptHead);
			break;

		/*��Ӧ��ǰת*/
		case CFNRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfna=false","",pptHead);
			break;

		/*����ת��*/
		case CFUR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfu=true","",pptHead);
			break;

		/*����ת��*/
		case CFUE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfu=false","",pptHead);
			break;

		/*���ɼ�ת��*/
		case CFCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfd=true","",pptHead);
			break;

		/*���ɼ�ת��*/
		case CFCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cfd=false","",pptHead);
			break;

		/*���к���ʶ����ʾ*/
		case CLIRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnip=true","",pptHead);
			break;

		/*���к���ʶ����ʾ*/
		case CLIRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnip=false","",pptHead);
			break;

		/*���еȴ�*/
		case CWR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cw=true","",pptHead);
			break;

		/*���еȴ�*/
		case CWE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cw=false","",pptHead);
			break;

		/*��������*/
		case A3WCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",wc3=true","",pptHead);
			break;

		/*��������*/
		case A3WCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",wc3=false","",pptHead);
			break;

		/*���к���ʶ����ʾ����*/
		case CNIRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnir=true","",pptHead);
			break;

		/*���к���ʶ����ʾ����*/
		case CNIRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cnir=false","",pptHead);
			break;

		/*��Ϣ�ȴ�֪ͨ*/
		case MWNR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",mwn=true","",pptHead);
			break;

		/*��Ϣ�ȴ�֪ͨ*/
		case MWNE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",mwn=false","",pptHead);
			break;

		/*��������*/
		case VMRR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",vmr=true","",pptHead);
			break;

		/*��������*/
		case VMRE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",vmr=false","",pptHead);
			break;

		/*����ת�Ƶ���������*/
		case CTR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",ct=true","",pptHead);
			break;

		/*����ת�Ƶ���������*/
		case CTE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",ct=false","",pptHead);
			break;

		/*����绰*/
		case CCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cc=true","",pptHead);
			break;

		/*����绰*/
		case CCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",cc=false","",pptHead);
			break;

		/*Զ��ҵ���(������)*/
		case RFCR:
			AddCmd("mod-supsvr:mdn=\"${DN}\",rfc=true","",pptHead);
			break;

		/*Զ��ҵ�����(������)*/
		case RFCE:
			AddCmd("mod-supsvr:mdn=\"${DN}\",rfc=false","",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM0R:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=2","",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM0E:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=1","",pptHead);
			break;

		/*����ҵ���޶�(��������Ϊ���ڳ�;����?)*/
		case INTERIM1R:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=6","",pptHead);
			break;

		/*����ҵ���޶�*/
		case INTERIM1E:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=2","",pptHead);
			break;

		/*�������ҵ���޶�*/
		case INTERIM2R:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=2,origin=6","",pptHead);
			break;

		/*�������ҵ���޶�*/
		case INTERIM2E:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",termina=1,origin=2","",pptHead);
			break;

		/*���غ��������޶�*/
		case LOCALR:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=7","",pptHead);
			break;

		/*���غ��������޶�*/
		case LOCALE:
			AddCmd("mod-restrsvr:mdn=\"${DN}\",origin=6","",pptHead);
			break;

		/*����ͣ��:������(������)*/
		case USERLOCK0R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=1","",pptHead);
			break;

		/*����ͣ��:������(������)*/
		case USERLOCK1R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=2","",pptHead);
			break;

		/*����ͣ��:���롢������(������)*/
		case USERLOCK2R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=3","",pptHead);
			break;

		/*��ͣ����:δ����(������)*/
		case USERLOCK2E:
			AddCmd("mod-lockstat:mdn=\"${DN}\",userlock=0","",pptHead);
			break;

		/*Ƿ��ͣ��:������(������)*/
		case ACCOUNTLOCK0R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=1","",pptHead);
			break;

		/*Ƿ��ͣ��:������(������)*/
		case ACCOUNTLOCK1R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=2","",pptHead);
			break;

		/*Ƿ��ͣ��:���롢������(������)*/
		case ACCOUNTLOCK2R:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=3","",pptHead);
			break;

		/*Ƿ�Ѹ���:δ����(������)*/
		case ACCOUNTLOCK2E:
			AddCmd("mod-lockstat:mdn=\"${DN}\",accountlock=0","",pptHead);
			break;

		/*������(������)*/
		case STOLENLOCKR:
			AddCmd("mod-lockstat:mdn=\"${DN}\",stolenlock=3","",pptHead);
			break;

		/*������(������)*/
		case STOLENLOCKE:
			AddCmd("mod-lockstat:mdn=\"${DN}\",stolenlock=0","",pptHead);
			break;

		/*������(������)*/
		case DUPLOCKR:
			AddCmd("mod-lockstat:mdn=\"${DN}\",duplock=3","",pptHead);
			break;

		/*������(������)*/
		case DUPLOCKE:
			AddCmd("mod-lockstat:mdn=\"${DN}\",duplock=0","",pptHead);
			break;

		/*�ƶ����ɺ�:��æǰת(�½���)*/
		case CFSVR0R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=1,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*�ƶ����ɺ�:��æǰת(�½���)*/
		case CFSVR0E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=1,cfnum=\"${CFDN}\",ifActive=2,voice=0","",pptHead);
			break;

		/*�ƶ����ɺ�:��������ǰת(�½���)*/
		case CFSVR1R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=2,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*�ƶ����ɺ�:��������ǰת(�½���)*/
		case CFSVR1E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",ifActive=2,cfscode=2,voice=0","",pptHead);
			break;

		/*�ƶ����ɺ�:��Ӧ��ǰת(�½���)*/
		case CFSVR2R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=3,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*�ƶ����ɺ�:��Ӧ��ǰת(�½���)*/
		case CFSVR2E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=3,cfnum=\"${CFDN}\",ifActive=2,voice=0","",pptHead);
			break;

		/*�ƶ����ɺ�:������ǰת(�½���)*/
		case CFSVR3R:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=4,cfnum=\"${CFDN}\",ifActive=3,voice=0","",pptHead);
			break;

		/*�ƶ����ɺ�:������ǰת(�½���)*/
		case CFSVR3E:
			AddCmd("mod-cfsvr:mdn=\"${DN}\",cfscode=4,cfnum=\"${CFDN}\",ifActive=2,voice=0","",pptHead);
			break;

		/*����ҵ��(������)*/
		case SMP0E:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=${SID},ServiceFlag=1,ScpNo=${SCPNO},dppc=${DPPC},fcn=${FCN},cfna=${CFNA}","",pptHead);
			break;

		/*����ҵ��(������)*/
		case SMP1E:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=${SID},ServiceFlag=2,ScpNo=${SCPNO},dppc=${DPPC},fcn=${FCN},cfna=${CFNA}","",pptHead);
			break;

		/*����ҵ��(������)*/
		case SMP1R:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=${SID},ServiceFlag=3,ScpNo=${SCPNO},dppc=${DPPC},fcn=${FCN},cfna=${CFNA}","",pptHead);
			break;

		/*����ҵ��VPN*/
		case VPNR:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=130,ServiceFlag=3,ScpNo=${SCPNO}","",pptHead);
			break;

		/*����ҵ��VPN*/
		case VPNE:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=130,ServiceFlag=1,ScpNo=${SCPNO}","",pptHead);
			break;

		/*����ҵ��PPC*/
		case PPCR:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=128,ServiceFlag=3,ScpNo=${SCPNO}","",pptHead);
			break;

		/*����ҵ��PPC*/
		case PPCE:
			AddCmd("mod-winsvr:mdn=\"${DN}\",ServiceID=128,ServiceFlag=1,ScpNo=${SCPNO}","",pptHead);
			break;

		/*����������ҵ��*/
		case INTERNETR:
			AddCmd("mod-datasvr:mdn=\"${DN}\",PDS1=true","",pptHead);
			break;

		/*����������ҵ��*/
		case INTERNETE:
			AddCmd("mod-datasvr:mdn=\"${DN}\",PDS1=false","",pptHead);
			break;

		/*����ҵ��*/
		case CL0R:
			AddCmd("mod-crbt:mdn=\"${DN}\",crbt=3","",pptHead);
			break;

		/**/
		case CL0E:
			AddCmd("mod-crbt:mdn=\"${DN}\",crbt=1","",pptHead);
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
		AddCmd("del-subscr:mdn=\"${DN}\",forceflag=1","",pptHead);

	return 0;
}


/*�޸��û�IMSI����*/
int ProcCHIMSI(int iBusi,struct ResultStruct **pptHead)
{
	/*����ִ�е��˴�����ProcCmdִ��*/
	if(iBusi==DN)
		AddCmd("chg-imsi:mdn=\"86${DN}\",newimsi=\"${NEWIMSI}\",ifac=1,forceflag=1","",pptHead);

	return 0;
}

/*�޸��û�DN����*/
int ProcCHGMDN(int iBusi,struct ResultStruct **pptHead)
{
	/*����ִ�е��˴�����ProcCmdִ��*/
	if(iBusi==DN)
		AddCmd("chg-mdn:oldmdn=\"%{DN}\",newmdn=\"${NEWDN}\"","",pptHead);
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
	switch(iBusi){

		/*���뻥��*/
		case INQCODE:
			AddCmd("inq-code:mdn=\"${DN}\"","",pptHead);
			break;

		/*��Ȩ����*/
			break;

		/*LOCAL*/
		case LSTLOCAL:
			AddCmd("lst-restrsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*ROAMING*/
		case LSTROAMING:
			AddCmd("lst-msclist:mdn=\"${DN}\"","",pptHead);
			break;

		/*��ѯ����ҵ���޶�*/
		case LSTINTERIM:
			AddCmd("lst-restrsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*��ѯ���ŷ���*/
		case LSTSMS:
			AddCmd("lst-telsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*��ѯ�û�����ҵ��*/
		case LSTSUPSVR:
			AddCmd("lst-supsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*��ѯ��״̬(������)*/
			break;

		/*�ƶ����ɺ�CFB(�½���)*/
		case LSTCFB:
			AddCmd("lst-cfsvr:cfscode=1,mdn=\"${DN}\"","",pptHead);
			break;

		/*�ƶ����ɺ�CFD(�½���)*/
		case LSTCFD:
			AddCmd("lst-cfsvr:cfscode=2,mdn=\"${DN}\"","",pptHead);
			break;

		/*�ƶ����ɺ�CFNA(�½���)*/
		case LSTCFNA:
			AddCmd("lst-cfsvr:cfscode=3,mdn=\"${DN}\"","",pptHead);
			break;

		/*�ƶ����ɺ�CFU(�½���)*/
		case LSTCFU:
			AddCmd("lst-cfsvr:cfscode=4,mdn=\"${DN}\"","",pptHead);
			break;

		/*��ѯ����������*/
		case LSTWINSVR:
			AddCmd("lst-winsvr:mdn=\"${DN}\"","",pptHead);
			break;

		/*��ѯINTERNET����*/
		case LSTINTERNET:
			AddCmd("lst-datasvr:mdn=\"${DN}\"","",pptHead);
			break;
			
		/*δ֪*/
		default:
			break;
	}
	
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
