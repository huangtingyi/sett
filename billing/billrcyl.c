#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwtiny.h>
#include <bintree.h>
#include <expr.h>
#include <expr_fun.h>
#include <expr_var.h>
#include <wwsupp.h>
#include <wwdb.h>
#include <ticket_field.h>
#include <tariff_disct.h>

#include <ticket.h>
#include <stt_ticket.h>
#include <bill_supp.h>

#include <fileout.h>

struct TinyRollLogStruct *pSumLog=NULL;

int MyProcessTicket(struct FileControlListStruct *ptHead,char sTemplateRule[],
	int f,char sBaseName[],char sMod[],struct FileControlOutStruct **ppNormal,
	struct MobTicketStruct *p,char sTargetName[],int *piNormalCnt,char sSplitNew[])
{
	int iRet,l=0;
	char	sRec[512],msg[1024];
	struct SplitRuleStruct *pSplitRule=NULL;
	struct FileControlListStruct *pTemp;
	
	*piNormalCnt=0;

	AnalyzeTicketExtent(p);

	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*��ƥ����һ���������*/
		if((pSplitRule=GetMultiSplitRule(pTemp))!=NULL){

			p->iSplitRuleID =	pSplitRule->iSplitRuleID;
			p->iTicketTypeID=	pSplitRule->iTicketTypeID;
			strcpy(p->sSplitType,	pSplitRule->sSplitType);

			if((iRet=CalMainTicketD(p))<0){
				WriteAlertMsg("���ʧ��");
				return -1;
			}
			ModifyTicketFee(sTemplateRule,f,sMod,pTemp->sSplitType,p);

			l=PrintTicket(p,pTemp->sSplitType,sRec);
		
			pTemp->iCnt++;
			if(Item2FileSplitOut(ppNormal,sRec,l,
				sBaseName,sTargetName,pTemp->sSplitType,
				&pSumLog,sSplitNew,msg)<0){
				WriteAlertPrint("�������������������,��Ϣ:%s",msg);
				return -1;
			}
			(*piNormalCnt)++;
			
			break;/*ץ��һ����һ��*/
		}
	}	
	return 0;
}
int main(int argc,char *argv[])
{

	int  iBillFlag,iFullFlag,iWantUpdate,iFlag=0;
	int  iNormalCnt=0,iAbnormalCnt=0,iCnt=0;

	char sTemplateRule[128],sSplitStr[21],sModule[4],sSplitNew[21],sType[5];
	char sUserType[10],sTargetName[256],sVisitAreaCode[10],sAreaCode[6];
	char sTableName[128],sCondition[128];
	char sBaseName[128],sLine[1024],sRowID[19],sDate[15];

	struct FileControlOutStruct *pNormal=NULL;
	struct	FileControlListStruct *pControlList=NULL;
	struct MobTicketStruct  *p=&Ticket;
	
	struct UCommTicketStruct TempUTicket;
	struct UCommTicketStructUp TempUp;

	
	if(argc!=11){
		printf("Usage %s tablename wherecause type(P) usertype \
templateid splitstr visitcode module targetname update(def=0).\n",argv[0]);
		return -1;
	}
/*��ʼ����������*/
	InitAppRes(argv[0]);
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[2]);
	strncpy(sType,argv[3],4);sType[4]=0;AllTrim(sType);
	strcpy(sUserType,argv[4]);sUserType[1]=0;
	strcpy(sTemplateRule,argv[5]);
	strcpy(sSplitStr,argv[6]);
	strcpy(sVisitAreaCode,argv[7]);
	strncpy(sModule,argv[8],3);sModule[3]=0;
	strcpy(sTargetName,argv[9]);
	if((iWantUpdate=atoi(argv[10]))!=0) iWantUpdate=1;

/*��һ�����͵�У��*/
	if(strcmp(sType,"P")!=0){
		printf("ϵͳ��֧��P���͸�ʽ����.\n");
		return -1;
	}
/*��ʼ�����۲���*/
	MoveAllShmToMem();

/*�����ʷ�����*/
	InitTollTariffList(comp_toll_tariff_ticket);
	
/*�õ�������־*/
	iBillFlag=GetBillingFlag(sSplitStr);
	iFullFlag=GetFullFlag(sSplitStr);
/*���������б�*/
	InitFileControlList(sTemplateRule,sSplitStr,&pControlList);
	pFileControlList=pControlList;
	
/*�����뻰��ָ��ָ��ָ������*/
	pTicketField=&Ticket;

	GetBaseName(sTargetName,sBaseName);sBaseName[19]=0;
	
	if(ConnectDataDB()<0) return -1;
	
	/*����*/
	bzero((void*)&TempUp,sizeof(struct UCommTicketStructUp));
	strcpy(TempUp.sTableName,sTableName);

	strcpy(TempUTicket.sModule,sModule);
	strcpy(TempUTicket.sAreaCode,sVisitAreaCode);
	strcpy(TempUTicket.sState,"1");
	GetHostTime(sDate);
	strcpy(TempUTicket.sUpdateDate,sDate);
	GetBaseNameX(sTargetName,sBaseName);
	strncpy(TempUTicket.sFileName,sBaseName,19);
	TempUTicket.sFileName[19]=0;

	strcpy(sSplitNew,"");
	
	while(PrepTicket2Str(sTableName,sCondition,sBaseName,sRowID,sLine)==true){

		iCnt++;
		/**����¼�Ĳ�������MobTicket��**/
		mvitem_prep2mobticket_x(sLine,strlen(sLine),sVisitAreaCode,p);

		/*������ֲ����쳣�Ļ�����д���쳣�б�*/
		strcpy(sAreaCode,p->sAreaCode);
		if(AnalyzeTicketBase(p,sAreaCode,iBillFlag)<0){
			/*���ﲻҪд���ļ�����Ϊ�޷����յ��ļ��򲻻���*/
			iAbnormalCnt++;
			continue;
		}
		PreModifyTicket(p,iBillFlag);

		/*������������б�*/
		if(MyProcessTicket(pControlList,sTemplateRule,iBillFlag,sBaseName,
			sModule,&pNormal,p,sTargetName,&iFlag,sSplitNew)<0){
			WriteAlertPrint("������ʧ�ܣ���%s������%s",
				sTableName,sCondition);
			return -1;
		}
		
		if(iWantUpdate&&iFlag>0){
			/*����״̬�������ֶ�*/
			strcpy(TempUTicket.sRowID,sRowID);

			if(EUpdateStructToUCommTicket(&TempUTicket,false,&TempUp)<0){
				WriteAlertPrint("��%s�������ݴ���",TempUp.sTableName);
				return -1;
			}
		}

		if(strlen(sSplitNew)==0)iAbnormalCnt++;
		else	iNormalCnt++;
			
		if(iCnt%10000==0){

			WriteProcMsg("�Ա�%s���ļ�,������%d,�����쳣��%d,�����%d",
				sTableName,iCnt,iAbnormalCnt,iNormalCnt);

			if(iWantUpdate==1){
				if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
					WriteAlertMsg("��%s�������ݴ���.",TempUp.sTableName);
					return -1;
				}
			}
		}
	}
	
	if(iWantUpdate){
		if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
			WriteAlertPrint("��%s�������ݴ���",TempUp.sTableName);
			return -1;
		}
	}
	if(WriteRollLogCtl(pSumLog,sTargetName)<0){
		WriteAlertPrint("д��־�����ļ�ʧ��");
		return -1;
	}
	
	CloseFileOutAll(pNormal);
		
	CommitWork();
	DisconnectDatabase();
	
	WriteProcMsg("�Ա�%s���ļ����,������%d,����������%d,�쳣��%d",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt);
	if(iNormalCnt==0)
		WriteProcMsg("����������Ϊ0������1:û�������������ض�����,",
			"2:id=%s,split=%s�ķ�������û��һ��������ƥ����",
				sTemplateRule,sSplitStr);
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt,sSplitNew);
	
/*��pControlList�ͷ�*/
	DestroyFileControlList(pControlList);
/*�ͷ����۲���*/
	DistroyAllMem();
	return 0;
}
