#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdb.h>
#include <bintree.h>
#include <dbsupp.h>
#include <stt_ticket.h>
#include <ticket.h>
#include "param_intf.h"
#include "toll_voip193_supp.h"

struct FileHeadStruct FileHead;
BINTREE *pRoot=NULL;
FILE *fp=NULL;
long dTotalFee=0;
int iCnt=0;

void mvitem_Dvoip193recordstruct(struct MobCalledStatStruct *pi,
	struct DVoip193RecordStruct *po);
	
static int data_comp_voip193_e(void *pValue,void *pData)
{
	int iRes=0;
	struct Voip193RecordStruct *pSource=(struct Voip193RecordStruct *)pValue;
	struct Voip193RecordStruct *pTarget=(struct Voip193RecordStruct *)pData;


	if((iRes=strcmp(pSource->sInCityCode,pTarget->sInCityCode))!=0)
		return iRes;
	if((iRes=strcmp(pSource->sOutCityCode,pTarget->sOutCityCode))!=0)
		return iRes;
	return iRes;
}

static void assign_insert_bintree_voip193_e(void **ppHead,void *pData)
{
	struct Voip193RecordStruct *pTemp;
	if((pTemp=(*ppHead))==NULL){
		pTemp=malloc(sizeof(struct Voip193RecordStruct));
		ERROR_EXIT(pTemp==NULL,"分配Voip193结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct Voip193RecordStruct));
		pTemp->pNext=NULL;
		*ppHead=(void*)pTemp;
		return;
	}
	pTemp->iTollFee1	+=((struct Voip193RecordStruct*)pData)->iTollFee1;
	pTemp->iDuration1	+=((struct Voip193RecordStruct*)pData)->iDuration1;
	pTemp->iCnt1		+=((struct Voip193RecordStruct*)pData)->iCnt1;
	pTemp->iTollFee2	+=((struct Voip193RecordStruct*)pData)->iTollFee2;
	pTemp->iDuration2	+=((struct Voip193RecordStruct*)pData)->iDuration2;
	pTemp->iCnt2		+=((struct Voip193RecordStruct*)pData)->iCnt2;
	pTemp->iTollFee3	+=((struct Voip193RecordStruct*)pData)->iTollFee3;
	pTemp->iDuration3	+=((struct Voip193RecordStruct*)pData)->iDuration3;
	pTemp->iCnt3		+=((struct Voip193RecordStruct*)pData)->iCnt3;
	pTemp->iTollFee4	+=((struct Voip193RecordStruct*)pData)->iTollFee4;
	pTemp->iDuration4	+=((struct Voip193RecordStruct*)pData)->iDuration4;
	pTemp->iCnt4		+=((struct Voip193RecordStruct*)pData)->iCnt4;
	pTemp->iTollFee5	+=((struct Voip193RecordStruct*)pData)->iTollFee5;
	pTemp->iDuration5	+=((struct Voip193RecordStruct*)pData)->iDuration5;
	pTemp->iCnt5		+=((struct Voip193RecordStruct*)pData)->iCnt5;
	pTemp->iTollFee6	+=((struct Voip193RecordStruct*)pData)->iTollFee6;
	pTemp->iDuration6	+=((struct Voip193RecordStruct*)pData)->iDuration6;
	pTemp->iCnt6		+=((struct Voip193RecordStruct*)pData)->iCnt6;
}

static int data_comp_toll_e(void *pValue,void *pData)
{
	int iRes=0;
	struct TollRecordStruct *pSource=(struct TollRecordStruct *)pValue;
	struct TollRecordStruct *pTarget=(struct TollRecordStruct *)pData;


	if((iRes=strcmp(pSource->sInCityCode,pTarget->sInCityCode))!=0)
		return iRes;
	if((iRes=strcmp(pSource->sOutCityCode,pTarget->sOutCityCode))!=0)
		return iRes;
	return iRes;
}

static void assign_insert_bintree_toll_e(void **ppHead,void *pData)
{
	struct TollRecordStruct *pTemp;
	if((pTemp=(*ppHead))==NULL){
		pTemp=malloc(sizeof(struct TollRecordStruct));
		ERROR_EXIT(pTemp==NULL,"分配TollRecord结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct TollRecordStruct));
		pTemp->pNext=NULL;
		*ppHead=(void*)pTemp;
		return;
	}
	pTemp->iTollFee1	+=((struct TollRecordStruct*)pData)->iTollFee1;
	pTemp->iDuration1	+=((struct TollRecordStruct*)pData)->iDuration1;
	pTemp->iCnt1		+=((struct TollRecordStruct*)pData)->iCnt1;
	pTemp->iTollFee2	+=((struct TollRecordStruct*)pData)->iTollFee2;
	pTemp->iDuration2	+=((struct TollRecordStruct*)pData)->iDuration2;
	pTemp->iCnt2		+=((struct TollRecordStruct*)pData)->iCnt2;
	pTemp->iTollFee3	+=((struct TollRecordStruct*)pData)->iTollFee3;
	pTemp->iDuration3	+=((struct TollRecordStruct*)pData)->iDuration3;
	pTemp->iCnt3		+=((struct TollRecordStruct*)pData)->iCnt3;
}

int GenCityCode(char sAreaCode[],char sCityCode[])
{
	struct AreaCodeDescStruct *pTemp=NULL;

/*	if(strncmp(sProvCode,"088",3)==0&&strlen(sAreaCode)==0){
		strcpy(sCityCode,"880");
		return 0;
	}

	if(sAreaCode[0]=='0'){
		strcpy(sCityCode,sAreaCode);
		return 0;
	}
*/
	if(SearchAreaCodeDesc(sAreaCode,&pTemp)==NOTFOUND){
		printf("区号%s没有找到城市代码\n",sAreaCode);
		return -1;
	}
	strcpy(sCityCode,pTemp->sCityCode);
	if ( strcmp(sCityCode,"-1") == 0 ){
               strcpy(sCityCode,"841");
	}

	return 0;
}
int GetInformation(char sFileName[],char sFileType[],char sUserType[],
	char sSettMonth[],char sFileSeq[],char sCompanyCode[],char sNetType[]){
	
	if(strncmp(sFileType,"GTI",3)==0 ||strncmp(sFileType,"TGT",3)==0||
		strncmp(sFileType,"VGT",3)==0 ||strncmp(sFileType,"TVG",3)==0||
		strncmp(sFileType,"1GT",3)==0 ||strncmp(sFileType,"T1G",3)==0){

		strcpy(sUserType,"G");sUserType[2]=0;

		if (strncmp(sFileType,"GTI",3)==0){
			strncpy(sSettMonth,sFileName+3,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+9,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+13,3);sCompanyCode[3]=0;
		}
		else if(strncmp(sFileType,"TGT",3)==0 ||
			strncmp(sFileType,"VGT",3)==0 ||
			strncmp(sFileType,"1GT",3)==0){    

			strncpy(sSettMonth,sFileName+4,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+10,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+14,3);sCompanyCode[3]=0;
			if(strncmp(sFileType,"VGT",3)==0)
				strcpy(sNetType,"I");
			else if(strncmp(sFileType,"1GT",3)==0)
				strcpy(sNetType,"1");
		}
		else if(strncmp(sFileType,"TVG",3)==0||
			strncmp(sFileType,"T1G",3)==0){

			strncpy(sSettMonth,sFileName+5,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+11,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+15,3);sCompanyCode[3]=0;
			if(strncmp(sFileType,"TVG",3)==0)
				strcpy(sNetType,"I");
			else if(strncmp(sFileType,"T1G",3)==0)
				strcpy(sNetType,"1");
		}			
	}
	else if(strncmp(sFileType,"CTI",3)==0 ||strncmp(sFileType,"TCT",3)==0||
		strncmp(sFileType,"VCT",3)==0 ||strncmp(sFileType,"TVC",3)==0||
		strncmp(sFileType,"1CT",3)==0 ||strncmp(sFileType,"T1C",3)==0){
		strcpy(sUserType,"C");sUserType[2]=0;
		if(strncmp(sFileType,"CTI",3)==0){
			strncpy(sSettMonth,sFileName+3,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+9,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+13,3);sCompanyCode[3]=0;
		}
		else if(strncmp(sFileType,"TCT",3)==0||
			strncmp(sFileType,"VCT",3)==0||
			strncmp(sFileType,"1CT",3)==0){

			strncpy(sSettMonth,sFileName+4,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+10,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+14,3);sCompanyCode[3]=0;

			if(strncmp(sFileType,"VCT",3)==0)
				strcpy(sNetType,"I");
			else if(strncmp(sFileType,"1CT",3)==0)
				strcpy(sNetType,"1");
		}
		else if(strncmp(sFileType,"TVC",3)==0||
			strncmp(sFileType,"T1C",3)==0){

			strncpy(sSettMonth,sFileName+5,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+11,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+15,3);sCompanyCode[3]=0;
			
			if(strncmp(sFileType,"TVC",3)==0)
				strcpy(sNetType,"I");
			else if(strncmp(sFileType,"T1C",3)==0)
				strcpy(sNetType,"1");
		}
	}
	else if(strncmp(sFileType,"DTI",3)==0 ||strncmp(sFileType,"TDT",3)==0){

		if(strncmp(sFileType,"DTI",3)==0){
			strncpy(sSettMonth,sFileName+3,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+11,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+15,3);sCompanyCode[3]=0;
		}
		else if(strncmp(sFileType,"TDT",3)==0){

			strncpy(sSettMonth,sFileName+4,6);sSettMonth[6]=0;
			strncpy(sFileSeq,sFileName+12,3);sFileSeq[3]=0;
			strncpy(sCompanyCode,sFileName+16,3);sCompanyCode[3]=0;
		}
		
		strcpy(sNetType,"D");
	}
	else{
		printf("文件名%s非法\n",sFileName);
		return -1;
	}
	return 0;
}

int GetFileHead(char sFileType[],char sFileSeq[],char sCompanyCode[]){

	char sDateTime[15];

	GetHostTime(sDateTime);

	strcpy(FileHead.sType,"00");
	strcpy(FileHead.sCompanyCode,sCompanyCode);

	if(strncmp(sFileType,"GTI",3)==0 ||strncmp(sFileType,"TGT",3)==0)
		strcpy(FileHead.sFileType,"GTI");
	else if(strncmp(sFileType,"VGT",3)==0 ||
		strncmp(sFileType,"TVG",3)==0)
		strcpy(FileHead.sFileType,"VGI");
	else if(strncmp(sFileType,"1GT",3)==0 ||
		strncmp(sFileType,"T1G",3)==0) 
		strcpy(FileHead.sFileType,"1GI");
	else if(strncmp(sFileType,"CTI",3)==0 ||
		strncmp(sFileType,"TCT",3)==0)
		strcpy(FileHead.sFileType,"CTI");
	else if(strncmp(sFileType,"VCT",3)==0 ||
		strncmp(sFileType,"TVC",3)==0)
		strcpy(FileHead.sFileType,"VCI");
	else if(strncmp(sFileType,"1CT",3)==0 ||
		strncmp(sFileType,"T1C",3)==0) 
		strcpy(FileHead.sFileType,"1CI");	
	else if(strncmp(sFileType,"DTI",3)==0 ||
		strncmp(sFileType,"TDT",3)==0) 
		strcpy(FileHead.sFileType,"DTI");	

	strcpy(FileHead.sFileVersion,"01");
	strcpy(FileHead.sFileSeq,sFileSeq);
	strncpy(FileHead.sFileCreateDate,sDateTime,8);

	return 0;
}

int TollFeeDuraStat(void **pRoot){

	struct TollRecordStruct *pTemp=(*pRoot);

	if(pTemp!=NULL){
		iCnt++;
		dTotalFee+=pTemp->iTollFee1+pTemp->iTollFee2+pTemp->iTollFee3;
	}
	return 0;
}
int Void193FeeDuraStat(void **pRoot){

	struct Voip193RecordStruct *pTemp=(*pRoot);

	if(pTemp!=NULL){
		iCnt++;
		dTotalFee+=pTemp->iTollFee1+pTemp->iTollFee2+pTemp->iTollFee3+
			pTemp->iTollFee4+pTemp->iTollFee5+pTemp->iTollFee6;
	}
	return 0;
}

int OutPutTollHead(struct FileHeadStruct *pHead){

	char sRecord[200];
	int l=0;

	l+=sprintf(sRecord+l,"%2s%3s%3s%3s",
		pHead->sType,pHead->sCompanyCode,
		pHead->sFileType ,pHead->sFileSeq);
	l+=sprintf(sRecord+l,"%2s%8s%6s%15s",
		pHead->sFileVersion,pHead->sFileCreateDate,
		pHead->sTotalRecord ,pHead->sTotalFee);
	l+=sprintf(sRecord+l,"%54s\r\n","");

	if(WriteFile(fp,sRecord,l)!=0) return -1;

	return 0;
}
void OutPutVoip193Head(struct FileHeadStruct *pHead){

	char sRecord[200];
	int l=0;

	l+=sprintf(sRecord+l,"%2s%3s%3s%3s",
		pHead->sType,pHead->sCompanyCode,
		pHead->sFileType ,pHead->sFileSeq);
	l+=sprintf(sRecord+l,"%2s%8s%6s%15s",
		pHead->sFileVersion,pHead->sFileCreateDate,
		pHead->sTotalRecord ,pHead->sTotalFee);
	l+=sprintf(sRecord+l,"%144s\r\n","");

	WriteFile(fp,sRecord,l);
}

int OutPutTollFileRecord(void **pRoot){

	char sRecord[200];
	int l=0;
	struct TollRecordStruct *pRecord=(*pRoot);

	if(pRecord!=NULL){
		LeftPad(pRecord->sInCityCode,3,'0');
		LeftPad(pRecord->sOutCityCode,3,'0');

		l+=sprintf(sRecord+l,"%3s%3s",
			pRecord->sInCityCode,pRecord->sOutCityCode);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee1,
			pRecord->iDuration1,pRecord->iCnt1);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee2,
			pRecord->iDuration2,pRecord->iCnt2);
		l+=sprintf(sRecord+l,"%010d%010d%010d\r\n",pRecord->iTollFee3,
			pRecord->iDuration3,pRecord->iCnt3);

		WriteFile(fp,sRecord,l);

	}
	return 0;

}
int OutPutVoip193FileRecord(void **pRoot){

	char sRecord[200];
	int l=0;
	struct Voip193RecordStruct *pRecord=(*pRoot);

	if(pRecord!=NULL){
		LeftPad(pRecord->sInCityCode,3,'0');
		LeftPad(pRecord->sOutCityCode,3,'0');

		l+=sprintf(sRecord+l,"%3s%3s",
			pRecord->sInCityCode,pRecord->sOutCityCode);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee1,
			pRecord->iDuration1,pRecord->iCnt1);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee2,
			pRecord->iDuration2,pRecord->iCnt2);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee3,
			pRecord->iDuration3,pRecord->iCnt3);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee4,
			pRecord->iDuration4,pRecord->iCnt4);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee5,
			pRecord->iDuration5,pRecord->iCnt5);
		l+=sprintf(sRecord+l,"%010d%010d%010d\r\n",pRecord->iTollFee6,
			pRecord->iDuration6,pRecord->iCnt6);

		WriteFile(fp,sRecord,l);

	}
	return 0;

}
int ProcessToll(char sFileName[],char sUserType[],char sCompanyCode[],
	char sSettMonth[],char sTableName[]){
	
	struct MobCalledStatStruct Temp;
	struct MobCalledStatStructIn TempIn;
	struct TollRecordStruct TollRecord;

	bzero((void*)&TempIn,sizeof(struct MobCalledStatStructIn));

	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"\n\
		WHERE CALLING_TYPE='%s' AND \n\
		SETT_MONTH='%s'",sUserType,sSettMonth);

	Upper(TempIn.sTableName);

	TempIn.iBufEmpty=TRUE;
        TempIn.iFirstFlag=TRUE;

        while(EGetMobCalledStatToStruct(&Temp,&TempIn)){
        	
        	if(strcmp(Temp.sCallingAreaCode,"")==0) continue;

/*		if(strncmp(sCompanyCode,"038",3)==0){
			if(strncmp(Temp.sCalledAreaCode,"59",2)!=0)
				continue;
		}
*/
		mvitem_tollrecordstruct(&Temp,&TollRecord);
		

		if(InsertBin(&pRoot,&TollRecord,data_comp_toll_e,
			assign_insert_bintree_toll_e)<0){
			WriteAlertMsg("生成BINTREE失败bintree_accnbr");
			exit(1);
		}
	}

	TravelBin(pRoot,TollFeeDuraStat);

	sprintf(FileHead.sTotalRecord,"%06d",iCnt);
	sprintf(FileHead.sTotalFee,"%015ld",dTotalFee);

	if((fp=fopen(sFileName,"w"))==NULL) return -1;

	OutPutTollHead(&FileHead);

	TravelBin(pRoot,OutPutTollFileRecord);

	fclose(fp);
	DestroyBin(pRoot);
	
	return 0;
}

int ProcessVoip193(char sFileName[],char sUserType[],char sSettMonth[],
	char sNetType[],char sTableName[]){
	
	struct DataCallingStatStruct Temp;
	struct DataCallingStatStructIn TempIn;
	struct Voip193RecordStruct Voip193Record;


	bzero((void*)&TempIn,sizeof(struct DataCallingStatStructIn));

	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"\n\
		WHERE CALLING_TYPE='%s' AND \n\
		CALLING_NET_TYPE='%s' AND \n\
		SETT_MONTH='%s'",sUserType,sNetType,sSettMonth);
	Upper(TempIn.sTableName);

	TempIn.iBufEmpty=TRUE;
        TempIn.iFirstFlag=TRUE;

	while(EGetDataCallingStatToStruct(&Temp,&TempIn)){

		mvitem_voip193recordstruct(&Temp,&Voip193Record);

		if(InsertBin(&pRoot,&Voip193Record,data_comp_voip193_e,
			assign_insert_bintree_voip193_e)<0){
			WriteAlertMsg("生成BINTREE失败bintree_accnbr");
			exit(1);
		}
	}
	
	TravelBin(pRoot,Void193FeeDuraStat);
	
	sprintf(FileHead.sTotalRecord,"%06d",iCnt);
	sprintf(FileHead.sTotalFee,"%015ld",dTotalFee);

	if((fp=fopen(sFileName,"w"))==NULL) return -1;

	OutPutVoip193Head(&FileHead);

	TravelBin(pRoot,OutPutVoip193FileRecord);

	fclose(fp);
	DestroyBin(pRoot);

	return 0;
}

void mvitem_Dvoip193recordstruct(struct MobCalledStatStruct *pi,
	struct DVoip193RecordStruct *po)
{/*数据移动部分*/

	bzero((void*)po,sizeof(struct DVoip193RecordStruct));

	strncpy(po->sInCityCode,	pi->sCallingAreaCode,3);
	po->sInCityCode[3]=0;
	strncpy(po->sOutCityCode,	pi->sCalledAreaCode,3);
	po->sOutCityCode[3]=0;

	if(strcmp(pi->sCalledType,"G")==0){
		po->iTollFee1	=atoi(pi->sTollFee);
		po->iDuration1	=atoi(pi->sTollSec)*6;
		po->iCnt1	=pi->iCnt;
	}
	else if(strcmp(pi->sCalledType,"C")==0){
		po->iTollFee2	=atoi(pi->sTollFee);
	        po->iDuration2	=atoi(pi->sTollSec)*6;
	        po->iCnt2	=pi->iCnt;
	}
	else if(strcmp(pi->sCalledType,"X")==0){
	        po->iTollFee3	=atoi(pi->sTollFee);
		po->iDuration3	=atoi(pi->sTollSec)*6;
		po->iCnt3	=pi->iCnt;
	}

}

static int data_comp_dvoip193_e(void *pValue,void *pData)
{
	int iRes=0;
	struct DVoip193RecordStruct *pSource=(struct DVoip193RecordStruct *)pValue;
	struct DVoip193RecordStruct *pTarget=(struct DVoip193RecordStruct *)pData;


	if((iRes=strcmp(pSource->sInCityCode,pTarget->sInCityCode))!=0)
		return iRes;
	if((iRes=strcmp(pSource->sOutCityCode,pTarget->sOutCityCode))!=0)
		return iRes;
	return iRes;
}

static void assign_insert_bintree_dvoip193_e(void **ppHead,void *pData)
{
	struct DVoip193RecordStruct *pTemp;
	if((pTemp=(*ppHead))==NULL){
		pTemp=malloc(sizeof(struct DVoip193RecordStruct));
		ERROR_EXIT(pTemp==NULL,"分配DVoip193结构错误");
		memcpy((void*)pTemp,pData,sizeof(struct DVoip193RecordStruct));
		pTemp->pNext=NULL;
		*ppHead=(void*)pTemp;
		return;
	}
	pTemp->iTollFee1	+=((struct DVoip193RecordStruct*)pData)->iTollFee1;
	pTemp->iDuration1	+=((struct DVoip193RecordStruct*)pData)->iDuration1;
	pTemp->iCnt1		+=((struct DVoip193RecordStruct*)pData)->iCnt1;
	pTemp->iTollFee2	+=((struct DVoip193RecordStruct*)pData)->iTollFee2;
	pTemp->iDuration2	+=((struct DVoip193RecordStruct*)pData)->iDuration2;
	pTemp->iCnt2		+=((struct DVoip193RecordStruct*)pData)->iCnt2;
	pTemp->iTollFee3	+=((struct DVoip193RecordStruct*)pData)->iTollFee3;
	pTemp->iDuration3	+=((struct DVoip193RecordStruct*)pData)->iDuration3;
	pTemp->iCnt3		+=((struct DVoip193RecordStruct*)pData)->iCnt3;
}

int DVoid193FeeDuraStat(void **pRoot){

	struct DVoip193RecordStruct *pTemp=(*pRoot);

	if(pTemp!=NULL){
		iCnt++;
		dTotalFee+=pTemp->iTollFee1+pTemp->iTollFee2+pTemp->iTollFee3;
	}
	return 0;
}
void OutPutDVoip193Head(struct FileHeadStruct *pHead){

	char sRecord[128];
	int l=0;

	l+=sprintf(sRecord+l,"%2s%3s%3s%3s",
		pHead->sType,pHead->sCompanyCode,
		pHead->sFileType ,pHead->sFileSeq);
	l+=sprintf(sRecord+l,"%2s%8s%6s%15s",
		pHead->sFileVersion,pHead->sFileCreateDate,
		pHead->sTotalRecord ,pHead->sTotalFee);
	l+=sprintf(sRecord+l,"%54s\r\n"," ");

	WriteFile(fp,sRecord,l);
}
int OutPutDVoip193FileRecord(void **pRoot){

	char sRecord[128];
	int l=0;
	struct DVoip193RecordStruct *pRecord=(*pRoot);

	if(pRecord!=NULL){
		LeftPad(pRecord->sInCityCode,3,'0');
		LeftPad(pRecord->sOutCityCode,3,'0');

		l+=sprintf(sRecord+l,"%3s%3s",
			pRecord->sInCityCode,pRecord->sOutCityCode);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee1,
			pRecord->iDuration1,pRecord->iCnt1);
		l+=sprintf(sRecord+l,"%010d%010d%010d",pRecord->iTollFee2,
			pRecord->iDuration2,pRecord->iCnt2);
		l+=sprintf(sRecord+l,"%010d%010d%010d\r\n",pRecord->iTollFee3,
			pRecord->iDuration3,pRecord->iCnt3);

		WriteFile(fp,sRecord,l);

	}
	return 0;

}
int ProcessDVoip193(char sFileName[],char sUserType[],char sSettMonth[],
	char sNetType[],char sTableName[]){
	
	struct MobCalledStatStruct Temp;
	struct MobCalledStatStructIn TempIn;
	struct DVoip193RecordStruct DVoip193Record;


	bzero((void*)&TempIn,sizeof(struct MobCalledStatStructIn));

	strcpy(TempIn.sTableName,sTableName);
	sprintf(TempIn.sCondition,"\n\
		WHERE SETT_MONTH='%s'",sSettMonth);
	Upper(TempIn.sTableName);

	TempIn.iBufEmpty=TRUE;
        TempIn.iFirstFlag=TRUE;

	while(EGetMobCalledStatToStruct(&Temp,&TempIn)){

		mvitem_Dvoip193recordstruct(&Temp,&DVoip193Record);

		if(InsertBin(&pRoot,&DVoip193Record,data_comp_dvoip193_e,
			assign_insert_bintree_dvoip193_e)<0){
			WriteAlertMsg("生成BINTREE失败bintree_accnbr");
			exit(1);
		}
	}
	
	TravelBin(pRoot,DVoid193FeeDuraStat);
	
	sprintf(FileHead.sTotalRecord,"%06d",iCnt);
	sprintf(FileHead.sTotalFee,"%015ld",dTotalFee);

	if((fp=fopen(sFileName,"w"))==NULL) return -1;

	OutPutDVoip193Head(&FileHead);

	TravelBin(pRoot,OutPutDVoip193FileRecord);

	fclose(fp);
	DestroyBin(pRoot);

	return 0;
}

int main(int argc,char *argv[]){
	
	char sFileName[128],sFileType[4],sCompanyCode[4],sBaseName[128];
	char sUserType[2],sSettMonth[7],sFileSeq[4];
	char sNetType[2],sTableName[128];

	if(argc!=3){
		printf("用法：%s tablename filename.\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);

	strcpy(sTableName,argv[1]);
	strcpy(sFileName,argv[2]);
	
	GetBaseName(sFileName,sBaseName);
	strncpy(sFileType,sBaseName,3);sFileType[3]=0;
	
	if(GetInformation(sBaseName,sFileType,sUserType,
		sSettMonth,sFileSeq,sCompanyCode,sNetType)!=0){
		printf("获取文件名上的信息失败\n");
		return -1;
	}
		
	if(GetFileHead(sFileType,sFileSeq,sCompanyCode)!=0){
		printf("获取文件头信息失败\n");
		return -1;
	}
	
	IniConnect("dataconnstr");
	
	if(strncmp(sNetType,"1",1)==0||strncmp(sNetType,"I",1)==0){
		if(ProcessVoip193(sFileName,sUserType,sSettMonth,
				sNetType,sTableName)!=0){
			printf("生成文件%s失败\n",sFileName);
			return -1;
		}
	}
	else if(strncmp(sNetType,"D",1)==0){
		if(ProcessDVoip193(sFileName,sUserType,sSettMonth,
				sNetType,sTableName)!=0){
			printf("生成文件%s失败\n",sFileName);
			return -1;
		}
	}
	else{
		if(ProcessToll(sFileName,sUserType,sCompanyCode,
			sSettMonth,sTableName)!=0){
			printf("生成文件%s失败\n",sFileName);
			return -1;
		}
	}
	
	DisconnectDatabase();

	printf("文件 %s 生成完毕.\n",sFileName);
	WriteProcMsg("文件 %s 生成完毕.",sFileName);
	
	return 0;
}
