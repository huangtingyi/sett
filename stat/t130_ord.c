#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <list.h>
#include <bintree.h>
#include <wwfile.h>
#include <wwdir.h>
#include <wwcoding.h>
#include <wwsupp.h>
#include "t130_supp.h"

BINTREE *pRoot=NULL;
FILE *fp=NULL;

int PrintFile(struct OrdT130AreaCodeStruct *pSource,char sTargetName[])
{
	int iFileRecordLen,iCnt=0;
	struct FileControlStruct *pOutput=NULL;
	struct OrdT130AreaCodeStruct	*ptHead=NULL,*pTemp;
	struct FOrdT130AreaCodeStruct FTemp;

	ptHead=pSource;
	
	iFileRecordLen=sizeof(struct FOrdT130AreaCodeStruct);
	
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;
		
		mvitem_mfordt130areacode(pTemp,&FTemp);
		
		if(item2listtail(&pOutput,(void*)&FTemp,
			iFileRecordLen)<0){
			WriteAlertMsg("数据插入输出链表失败");
			return -1;
		}
	}

	/*输出文件*/
	if(list2fileln(&pOutput,sTargetName)<0){
		WriteAlertMsg("写输出话单文件%s失败.\n",sTargetName);
		printf("写输出话单文件%s失败.\n",sTargetName);
		return -1;
	}

	listfree(&pOutput);

	return iCnt;
}

int OutFileNameA(void **ppRoot)
{
	struct AreaCodeStruct *pTemp=(*ppRoot);
	char sRecord[50],sHead[50];
	int l=0;

	strcpy(sHead,"CITYCODE AREACODEZB  AREACODEXT");
	l+=sprintf(sRecord+l,"%s\r\n",sHead);
	WriteFile(fp,sRecord,l);

	if(pTemp!=NULL){
		l=0;
		l+=sprintf(sRecord+l,"%3s%8s%8s\r\n",
			pTemp->sCityCode,pTemp->sAreaCodeZb,pTemp->sAreaCodeXt);

		WriteFile(fp,sRecord,l);
	}
	return 0;
}

int GetOrdOrdT130AreaCode(struct MobileHeadStruct *pm,struct HeadMobileHeadStruct *ph,
	struct OrdT130AreaCodeStruct **pi)
{
	int l=0;
	char sAreaCode[8],sRemark[60],sHostDate[14];
	struct AreaCodeStruct ptAreachk;
	struct MobileHeadStruct *ptFile=NULL;
	struct HeadMobileHeadStruct *ptFileHead=NULL;
	struct OrdT130AreaCodeStruct *pTemp;
	
	ptFile=pm;
	ptFileHead=ph;

	
	if((pTemp=(struct OrdT130AreaCodeStruct*)malloc(
		sizeof(struct OrdT130AreaCodeStruct )))==NULL){
		WriteAlertMsg("生成失败");
		exit(1);
	}
	
	bzero((void*)pTemp,sizeof(struct OrdT130AreaCodeStruct));
	
	/*取库中的area_code,sRemark*/
	TrimLeftX(ptFile->sAreaCode,'0');
	GetAreaCode(ptFile,ptFileHead,sAreaCode,sRemark);
	
	/*取得OrdT130AreaCodeStruct值*/
	
	sprintf(pTemp->sHead,"%s%s",ptFileHead->sHead,ptFile->sTailHead);
	pTemp->iLen=-1;
	
	l=strlen(ptFile->sAreaCode);	
	if(strcmp(ptFile->sAreaCode,sAreaCode)==0)
		strcpy(pTemp->sAreaCode,sAreaCode);
	else if(strncmp(ptFile->sAreaCode,sAreaCode,l)==0)
		strcpy(pTemp->sAreaCode,sAreaCode);
	else{ 
		strcpy(pTemp->sAreaCode,ptFile->sAreaCode);

		/*插入到输出Areachk bin*/
		strcpy(ptAreachk.sCityCode,ptFile->sCityCode);
		strcpy(ptAreachk.sAreaCodeZb,ptFile->sAreaCode);
		strcpy(ptAreachk.sAreaCodeXt,sAreaCode);
		
	        if(InsertBin(&pRoot,(void *)&ptAreachk,
			data_search_bintree_AreaChk,
			assign_insert_bintree_AreaChk)<0){
			WriteAlertMsg("生成BINTREE失败Areachk");
			return -1;
		}		
	}
	strcpy(pTemp->sHeadType,"");
	strcpy(pTemp->sRemark,sRemark);
	
	GetHostTime(sHostDate);
	strncpy(pTemp->sEffDate,sHostDate,8);
	strcpy(pTemp->sEffDate+8,"000000");
	strcpy(pTemp->sExpDate,"");
	strcpy(pTemp->sStateDate,sHostDate);
	
	pTemp->iStaffID=3001;	
	
	strcpy(pTemp->sComments,"总部号头处理入库待审核");
	pTemp->iOrdSeqNbr=1;
	strcpy(pTemp->sOrdSourceID,"0");
	strncpy(pTemp->sOrdNbr,sHostDate,8);
	strcpy(pTemp->sOrdNbr+8,"CHKC00000000");
	
	*pi=pTemp;
	return 0;
}

int DealTable(struct OrdT130AreaCodeStruct *ptOut,
	struct OrdT130AreaCodeStruct *ptDel)
{
	char sTableName[60],sState[4];
	int iCnt=0;

/*链表ptOut,ptDel入库ord_t130_area_code*/
	strcpy(sTableName,"ORD_T130_AREA_CODE");
	
	if(InsertOrdT130AreaCode(ptOut,sTableName)<0){
		RollbackWorkRelease();
		WriteAlertMsg("写表%s失败.\n",sTableName);
		return -1;
	}

	if(InsertOrdT130AreaCode(ptDel,sTableName)<0){
		RollbackWorkRelease();
		WriteAlertMsg("写表%s失败.\n",sTableName);
		return -1;
	}
	

/*链表ptOut,ptDel入库ord_t130_area_code_log*/
	strcpy(sTableName,"ORD_T130_AREA_CODE_LOG");
	
	if(InsertOrdT130AreaCode(ptOut,sTableName)<0){
		RollbackWorkRelease();
		WriteAlertMsg("写表%s失败.\n",sTableName);
		return -1;
	}

	if(InsertOrdT130AreaCode(ptDel,sTableName)<0){
		RollbackWorkRelease();
		WriteAlertMsg("写表%s失败.\n",sTableName);
		return -1;
	}

/*链表ptOut入库t130_area_code*/	
	strcpy(sTableName,"T130_AREA_CODE");
	strcpy(sState,"A0C");
	if(InsertT130AreaCode(ptOut,sTableName,sState)<0){
		RollbackWorkRelease();
		WriteAlertMsg("写表%s失败.\n",sTableName);
		return -1;
	}


/*链表ptDel,UPDATE t130_area_code*/

	strcpy(sTableName,"T130_AREA_CODE");
	strcpy(sState,"A2A");
	if(UpdateT130AreaCode(ptDel,sTableName,sState)<0){
		RollbackWorkRelease();
		WriteAlertMsg("更新表%s失败.\n",sTableName);
		return -1;
	}

	
	return 0;

}

/*参数：外部要插入的结构，当前结点的数据区*/
int data_search_bintree_AreaChk(void *pValue,void*pData)
{

	struct AreaCodeStruct *pSource=(struct AreaCodeStruct *)pValue;
	struct AreaCodeStruct *pTarget=(struct AreaCodeStruct *)pData;
	int res;

	res=0;

	if((res=strcmp(pSource->sCityCode,pTarget->sCityCode))!=0)return res;
	if((res=strcmp(pSource->sAreaCodeZb,pTarget->sAreaCodeZb))!=0)return res;
	if((res=strcmp(pSource->sAreaCodeXt,pTarget->sAreaCodeXt))!=0)return res;

	return res;
}

void assign_insert_bintree_AreaChk(void **ppData,void *pData)
{
	struct AreaCodeStruct *pValue=(struct AreaCodeStruct *)pData;
	struct AreaCodeStruct *pTemp;

	/*当第一次调用该函数（即创建结点的过程中），*ppData还没加载数据*/
	if((pTemp=(*ppData))==NULL){
		pTemp=malloc(sizeof(struct AreaCodeStruct));
		ERROR_EXIT(pTemp==NULL,"分配AreaCodeStruct结构错误");
		bzero((void*)pTemp,sizeof(struct AreaCodeStruct));

        	strcpy(pTemp->sCityCode,pValue->sCityCode);
        	strcpy(pTemp->sAreaCodeZb,pValue->sAreaCodeZb);
		strcpy(pTemp->sAreaCodeXt,pValue->sAreaCodeXt);
			
		/*将定义好的结点数据区挂回结点上*/
		*ppData=(void*)pTemp;

		return;
	}
	/*如果找到相同的键值的结点,根据对应累加费用*/
	pTemp=(*ppData);

        strcpy(pTemp->sCityCode,pValue->sCityCode);
        strcpy(pTemp->sAreaCodeZb,pValue->sAreaCodeZb);
	strcpy(pTemp->sAreaCodeXt,pValue->sAreaCodeXt);
}

int main(int argc,char *argv[])
{
	int l=0,iCnt=0;
	char sFileName[128],sNormalDir[128];
	char sOutFileNameN[128],sOutFileNameD[128],sOutFileNameA[128];
	char sBaseName[128];
	
        struct FileControlStruct *ptFHead=NULL,*pFTemp;
        struct OrdT130AreaCodeStruct *pTemp=NULL;
        struct OrdT130AreaCodeStruct *ptOut=NULL,*ptDel=NULL,*ptHead=NULL;
        struct MobileHeadStruct FileHead;
        struct HeadMobileHeadStruct FileHeadH; 
        


	if(argc!=3){
		printf("Usage %s filename normaldir.\n",argv[0]);
		return -1;
	}

	strcpy(sFileName,argv[1]);
	strcpy(sNormalDir,argv[2]);

	if(IsFile(sFileName)==FALSE){
		printf("输入文件%s无效.\n",sFileName);
		return -1;
	}

	if(IsDir(sNormalDir)==FALSE){
		WriteAlertMsg(">:输出正常目录%s无效.\n",sNormalDir);
		return -1;
	}
	RegularDir(sNormalDir);

	GetBaseName(sFileName,sBaseName);
	
	sprintf(sOutFileNameN,"%s%s.N",sNormalDir,sBaseName);
	sprintf(sOutFileNameD,"%s%s.D",sNormalDir,sBaseName);
	sprintf(sOutFileNameA,"%s%s.A",sNormalDir,sBaseName);
	
	InitAppRes(argv[0]);
	IniConnect("paramconnstr");
	/*IniConnect("dataconnstr");*/

	
/*将文件数据调用函数加载到内存*/
	if((l=TxtFileToList(sFileName,&ptFHead))<0){
		printf("加载文件%s到内存失败.\n",sFileName);
		WriteErrStackAlert();
		return -1;
	}	
	
	iCnt=0;
	
	while(ptFHead!=NULL){
		
		pFTemp=ptFHead;
		ptFHead=ptFHead->pNext;
		iCnt++;
		
		if(iCnt==1){
			mvitem_fmheadmobilehead((struct FHeadMobileHeadStruct *)pFTemp->pData,&FileHeadH);
			continue;
		}
		else
			mvitem_fmmobilehead((struct FMobileHeadStruct *)pFTemp->pData,&FileHead);
		
		
		/*RECORD_TYPE='10','40','50'的丢弃*/
		if(strcmp(FileHead.sRecordType,"40")==0||
			strcmp(FileHead.sRecordType,"50")==0)	
			continue;
		if(strcmp(FileHead.sAreaCode,"029")==0&&strcmp(FileHead.sCityCode,"844")==0){
			printf("ssss");
		}	

		GetOrdOrdT130AreaCode(&FileHead,&FileHeadH,&pTemp);
		
		if(strcmp(FileHead.sRecordType,"30")==0||
			strcmp(FileHead.sRecordType,"62")==0){

			pTemp->iHeadID=GetHeadId();
			if(pTemp->iHeadID<0){	
				WriteAlertMsg("取iHeadID失败");
				exit(1);
			}
			pTemp->iSeqNbr=1;
			strcpy(pTemp->sState,"A0W");
			strcpy(pTemp->sOrdType,"ADD");

			/*插入到输出链表ptOut*/
			if((ptHead=(struct OrdT130AreaCodeStruct *)malloc(
			 sizeof(struct OrdT130AreaCodeStruct)))==NULL){
				 printf("分配内存失败.\n");
				 return -1;
			
			}
			mvitem_ordt130areacode(pTemp,ptHead);
		
			InsertList((LIST**)&ptOut,(LIST*)ptHead);
			
		}
		else if(strcmp(FileHead.sRecordType,"20")==0||
			strcmp(FileHead.sRecordType,"61")==0){
			
			DGetT130AreaCodeHeadID(pTemp);
			
			strcpy(pTemp->sState,"A0W");
			strcpy(pTemp->sOrdType,"DEL");

			/*插入到删除链表ptDel*/
			if((ptHead=(struct OrdT130AreaCodeStruct *)malloc(
			 sizeof(struct OrdT130AreaCodeStruct)))==NULL){
				 printf("分配内存失败.\n");
				 return -1;
			
			}
			mvitem_ordt130areacode(pTemp,ptHead);
		
			InsertList((LIST**)&ptDel,(LIST*)ptHead);
			
		}
	
	}
	
/*处理ord_t130_area_code,ord_t130_area_code_log和t130_area_code,t130_area_code_chk表*/
	if(DealTable(ptOut,ptDel)<0)return -1;

/*把处理话单输出到文件sOutFileNameN,sOutFileNameD*/
	if((iCnt=PrintFile(ptOut,sOutFileNameN))<0){
		RollbackWorkRelease();
		
	}
	
	WriteProcMsg(" %d 条记录输出到话单文件 %s.N 成功.\n",iCnt,sBaseName);

	if((iCnt=PrintFile(ptDel,sOutFileNameD))<0){
		RollbackWorkRelease();
		return -1;
	}
	
	WriteProcMsg(" %d 条记录输出到话单文件 %s.D 成功.\n",iCnt,sBaseName);

	if((fp=fopen(sOutFileNameA,"w"))==NULL) return -1;
	
	TravelBin(pRoot,OutFileNameA);
	
	fclose(fp);
	printf("文件 %s.A 生成完毕.\n",sBaseName);
	WriteProcMsg("文件 %s.A 生成完毕.",sBaseName);

	DestroyBin(pRoot);
	
	CommitWorkRelease();	
	DisconnectDatabase();
	
	return 0;
}

