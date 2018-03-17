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

		/*能匹配上一个就是这个*/
		if((pSplitRule=GetMultiSplitRule(pTemp))!=NULL){

			p->iSplitRuleID =	pSplitRule->iSplitRuleID;
			p->iTicketTypeID=	pSplitRule->iTicketTypeID;
			strcpy(p->sSplitType,	pSplitRule->sSplitType);

			if((iRet=CalMainTicketD(p))<0){
				WriteAlertMsg("算费失败");
				return -1;
			}
			ModifyTicketFee(sTemplateRule,f,sMod,pTemp->sSplitType,p);

			l=PrintTicket(p,pTemp->sSplitType,sRec);
		
			pTemp->iCnt++;
			if(Item2FileSplitOut(ppNormal,sRec,l,
				sBaseName,sTargetName,pTemp->sSplitType,
				&pSumLog,sSplitNew,msg)<0){
				WriteAlertPrint("生成正常话单链表错误,消息:%s",msg);
				return -1;
			}
			(*piNormalCnt)++;
			
			break;/*抓到一个是一个*/
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
/*初始化参数部分*/
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

/*做一个类型的校验*/
	if(strcmp(sType,"P")!=0){
		printf("系统仅支持P类型格式输入.\n");
		return -1;
	}
/*初始化批价参数*/
	MoveAllShmToMem();

/*建立资费链表*/
	InitTollTariffList(comp_toll_tariff_ticket);
	
/*得到两个标志*/
	iBillFlag=GetBillingFlag(sSplitStr);
	iFullFlag=GetFullFlag(sSplitStr);
/*建立分离列表*/
	InitFileControlList(sTemplateRule,sSplitStr,&pControlList);
	pFileControlList=pControlList;
	
/*将分离话单指针指向指定话单*/
	pTicketField=&Ticket;

	GetBaseName(sTargetName,sBaseName);sBaseName[19]=0;
	
	if(ConnectDataDB()<0) return -1;
	
	/*更新*/
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
		/**将记录的参数导入MobTicket中**/
		mvitem_prep2mobticket_x(sLine,strlen(sLine),sVisitAreaCode,p);

		/*如果发现参数异常的话单，写入异常列表*/
		strcpy(sAreaCode,p->sAreaCode);
		if(AnalyzeTicketBase(p,sAreaCode,iBillFlag)<0){
			/*这里不要写错单文件，因为无法回收的文件则不回收*/
			iAbnormalCnt++;
			continue;
		}
		PreModifyTicket(p,iBillFlag);

		/*生成输出话单列表*/
		if(MyProcessTicket(pControlList,sTemplateRule,iBillFlag,sBaseName,
			sModule,&pNormal,p,sTargetName,&iFlag,sSplitNew)<0){
			WriteAlertPrint("处理话单失败，表%s，条件%s",
				sTableName,sCondition);
			return -1;
		}
		
		if(iWantUpdate&&iFlag>0){
			/*更新状态及其它字段*/
			strcpy(TempUTicket.sRowID,sRowID);

			if(EUpdateStructToUCommTicket(&TempUTicket,false,&TempUp)<0){
				WriteAlertPrint("表%s更新数据错误",TempUp.sTableName);
				return -1;
			}
		}

		if(strlen(sSplitNew)==0)iAbnormalCnt++;
		else	iNormalCnt++;
			
		if(iCnt%10000==0){

			WriteProcMsg("对表%s出文件,处理数%d,其中异常数%d,输出数%d",
				sTableName,iCnt,iAbnormalCnt,iNormalCnt);

			if(iWantUpdate==1){
				if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
					WriteAlertMsg("表%s更新数据错误.",TempUp.sTableName);
					return -1;
				}
			}
		}
	}
	
	if(iWantUpdate){
		if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
			WriteAlertPrint("表%s更新数据错误",TempUp.sTableName);
			return -1;
		}
	}
	if(WriteRollLogCtl(pSumLog,sTargetName)<0){
		WriteAlertPrint("写日志控制文件失败");
		return -1;
	}
	
	CloseFileOutAll(pNormal);
		
	CommitWork();
	DisconnectDatabase();
	
	WriteProcMsg("对表%s出文件完毕,处理数%d,其中正常数%d,异常数%d",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt);
	if(iNormalCnt==0)
		WriteProcMsg("正常话单数为0，可能1:没有满足条件的特定话单,",
			"2:id=%s,split=%s的分离类型没有一条话单能匹配上",
				sTemplateRule,sSplitStr);
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt,sSplitNew);
	
/*将pControlList释放*/
	DestroyFileControlList(pControlList);
/*释放批价参数*/
	DistroyAllMem();
	return 0;
}
