#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdb.h>
#include <bintree.h>
#include <dbsupp.h>
#include <stt_ticket.h>
#include <wwsupp.h>
#include "imsiesn.h"


static int data_comp_imsiesn_e(void *pValue,void *pData)
{
	int res;
	struct MsisdnImsiEsnStruct *pSource=(struct MsisdnImsiEsnStruct *)pValue;
	struct MsisdnImsiEsnStruct *pTarget=(struct MsisdnImsiEsnStruct *)pData;

	if((res=strcmp(pSource->sYear,pTarget->sYear))!=0) return res;
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sImsi,pTarget->sImsi))!=0) return res;
	return strcmp(pSource->sEsn,pTarget->sEsn);
}
static int data_comp_imsiesn_e1(void *pValue,void *pData)
{
	int res;
	struct PrepTicketStruct *pSource=(struct PrepTicketStruct *)pValue;
	struct MsisdnImsiEsnStruct *pTarget=(struct MsisdnImsiEsnStruct *)pData;

	if((res=strncmp(pSource->sStartTime,pTarget->sYear,4))!=0) return res;
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sImsi,pTarget->sImsi))!=0) return res;
	return strcmp(pSource->sEsn,pTarget->sEsn);
}
/**
yMap结构　6*12共72个字节，表示一年的数据
	6位表示一个月的数据
	
**/
char SetYMap(char sStartTime[],char sYMap[])
{
	int iMonth=0,iDay=0,iMonOff,iDayOff,iDayTail,i,c,d;
	static char B64Anti[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char sMonth[3],sDay[3],*p;
	
	strncpy(sMonth,sStartTime+4,2);sMonth[2]=0;
	strncpy(sDay,sStartTime+6,2);sDay[2]=0;

	iMonth=atoi(sMonth)-1;
	iDay=atoi(sDay)-1;

	iMonOff=iMonth*6;
	iDayOff=(iDay+1)/6;

	iDayTail=iDay-iDayOff*6;
	
	i=iMonOff+iDayOff;
	
	c=1;c<<=iDayTail;
	
	d=0;
	if((p=strchr(B64Anti,sYMap[i]))!=NULL) d=p-B64Anti;
	
	/*如果没有置位*/
	if((c&d)==0){
		d|=c;
		sYMap[i]=B64Anti[d];
		return 1;
	}
	return 0;
}
int MountImsiEsnToBin(BINTREE **ppRoot)
{
	int iCnt=0;
	BINTREE *pRoot=NULL;
	struct MsisdnImsiEsnStruct Temp,*pTemp;
	struct MsisdnImsiEsnStructIn TempIn;

	strcpy(TempIn.sTableName,"MSISDN_IMSI_ESN");
	strcpy(TempIn.sCondition,"");
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;
	while(EGetMsisdnImsiEsnToStruct(&Temp,&TempIn)){

        	if((pTemp=malloc(sizeof(struct MsisdnImsiEsnStruct)))==NULL){
        		printf("error Malloc MsisdnImsiEsnStruct.\n");
			return -1;
		}
		memcpy((void*)pTemp,(void*)&Temp,
			sizeof(struct MsisdnImsiEsnStruct));
		
		if(InsertBin(&pRoot,(void*)pTemp,data_comp_imsiesn_e,
			assign_insert_bintree)<0){
			WriteAlertPrint("生成BINTREE失败bintree_imsiesn");
			return -1;
		}
		iCnt++;
	}
	
	WriteProcMsg("表%s加载二叉树成功,记录数%d",TempIn.sTableName,iCnt);
	*ppRoot=pRoot;

	return 0;
}
struct MsisdnImsiEsnStruct *pUpdateList=NULL;
int dirty_update_list(void **ppData)
{
	struct MsisdnImsiEsnStruct *pTemp=(struct MsisdnImsiEsnStruct *)*ppData;

	if(pTemp->cFlag!=0)
		InsertList((LIST**)&pUpdateList,(LIST*)pTemp);
	return 0;
}
int UpdateList2Db()
{
	static int iCnt=0;
	static struct UMsisdnImsiEsnStructUp TempUp;
	struct UMsisdnImsiEsnStruct Temp;
	struct MsisdnImsiEsnStruct *pTemp=pUpdateList;
	
	if(iCnt==0){
		TempUp.iCurPos=0;
		strcpy(TempUp.sTableName,"MSISDN_IMSI_ESN");
	}
	
	while(pTemp!=NULL){

		strcpy(Temp.sYMap,pTemp->sYMap);
		strcpy(Temp.sRowID,pTemp->sRowID);

		if(EUpdateStructToMsisdnImsiEsn(&Temp,false,&TempUp)<0)
			return -1;
		pTemp->cFlag=0;
		pTemp=pTemp->pNext;
		iCnt++;
	}
	
	if(EUpdateStructToMsisdnImsiEsn(NULL,true,&TempUp)<0) return -1;
	
	pUpdateList=NULL;

	WriteProcPrint("成功更新%d条记录到%s",iCnt,TempUp.sTableName);

	return 0;
}
int my_free_bintree_data(void **ppData)
{
	free((*ppData));
	return 0;
}
int main(int argc,char **argv){

	int iCnt=0,iUpdateCnt=0;/*处理话单数、需要更新数*/
	char sTableName[31],cFlag,stmt[1024],sCondition[128];

	BINTREE *pRoot=NULL;
	
	struct MsisdnImsiEsnStruct *pTemp;
	struct PrepTicketStruct Temp;
	struct PrepTicketStructIn TempIn;

	if(argc!=3){
		printf("用法：%s tablename sCondition\n",argv[0]);
		exit(1);
	}

	InitAppRes(argv[0]);
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[2]);

	if(IniConnect("dataconnstr")<0){
		printf("连接数据库失败\n");
		return -1;
	}

	/*将IMSI_ESN加载到内存中*/
	if(MountImsiEsnToBin(&pRoot)<0) return -1;
	

	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"% AND CALL_TYPE IN ('01','02','03')",sCondition);
	
	TempIn.iBufEmpty =TRUE;
	TempIn.iFirstFlag = TRUE;

	while(EGetPrepTicketToStruct(&Temp,&TempIn)){

		if(!IS_MOB_NBR(Temp.sMsisdn)) continue;
		
		if(strlen(Temp.sImsi)==0)strcpy(Temp.sImsi,"X");
		if(strlen(Temp.sEsn)==0)strcpy(Temp.sEsn,"X");

		iCnt++;

                /*如果找到*/
		if((SearchBin(pRoot,(void*)&Temp,data_comp_imsiesn_e1,
			(void**)&pTemp))==NOTFOUND){

			if((pTemp=malloc(sizeof(struct MsisdnImsiEsnStruct)))==NULL){
				WriteAlertPrint("分配MSISDN_IMSI_ESN失败");
				return -1;
			}

			strncpy(pTemp->sYear,	Temp.sStartTime,4);
			pTemp->sYear[4]=0;

			strcpy(pTemp->sMsisdn,	Temp.sMsisdn);
			strcpy(pTemp->sImsi,	Temp.sImsi);
			strcpy(pTemp->sEsn,	Temp.sEsn);
			strcpy(pTemp->sYMap,"");
			LeftPad(pTemp->sYMap,72,'A');
			pTemp->cFlag=0;
			
			strcpy(pTemp->sRowID,"");
			
			/*设置YMAP*/
			SetYMap(Temp.sStartTime,pTemp->sYMap);

			/*将这条记录写到数据库中*/
			sprintf(stmt,"INSERT INTO MSISDN_IMSI_ESN \n\
				(MSISDN,IMSI,ESN,YEAR,Y_MAP) VALUES (\n\
				'%s','%s','%s','%s','%s')",
				pTemp->sMsisdn,pTemp->sImsi,pTemp->sEsn,
				pTemp->sYear,pTemp->sYMap);
			if(ExecSql(stmt)<0){
				WriteAlertPrint("执行%s失败",stmt);
				return -1;
			}
			CommitWork();
			/*将这条记录的ROWID取到*/
			if(GetMsisdnImsiEsnRowID(pTemp,pTemp->sRowID)<0){
				WriteAlertPrint("获取ROWID失败");
				return -1;
			}
			if(InsertBin(&pRoot,(void*)pTemp,data_comp_imsiesn_e,
				assign_insert_bintree)<0){
				WriteAlertPrint("生成BINTREE失败,新加入");
				return -1;
			}
			continue;
		}
		
		cFlag=SetYMap(Temp.sStartTime,pTemp->sYMap);
		if(cFlag!=0&&pTemp->cFlag==0){
			pTemp->cFlag=1;
			iUpdateCnt++;
		}
		if((iUpdateCnt%30000)==0){
			TravelBin(pRoot,dirty_update_list);
			if(UpdateList2Db()<0){
				WriteAlertPrint("更新记录到表MSISDN_IMSI_ESN错误");
				return -1;
			}
			CommitWork();
		}
	}
	TravelBin(pRoot,dirty_update_list);
	if(UpdateList2Db()<0){
		WriteAlertPrint("更新记录到表MSISDN_IMSI_ESN错误");
		return -1;
	}
	CommitWork();
	TravelBin(pRoot,my_free_bintree_data);
	DestroyBin(pRoot);
	return 0;
}
