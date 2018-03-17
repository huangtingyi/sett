#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdb.h>
#include <wwfile.h>
#include <list.h>
#include <bintree.h>
#include <dbsupp.h>
#include <expr_fun.h>

/*交叉漫游表*/
int data_search_bintree_pick_log_e(void *pValue,void*pData)
{
	struct PickLogStruct *pSource=(struct PickLogStruct *)pValue;
	struct PickLogStruct *pTarget=(struct PickLogStruct *)pData;

/*数据比较部分*/
	return strcmp(pSource->sFileName,pTarget->sFileName);
}
int SearchPickLog(char sSourceID[],char sFileName[],char sTableName[],
	struct PickLogStruct **pptCur)
{
	static int	iFirstFlag=true;
	static	BINTREE *ptHead=NULL;
	struct PickLogStruct *p=NULL,Temp;
	
	static struct PickLogStruct *pControl=NULL;
	
	if(pptCur==NULL){
		DestroyList((LIST*)pControl);
		DestroyBin(ptHead);
		ptHead=NULL;
		pControl=NULL;
		iFirstFlag=true;
		return FOUND;
	}
	
	if(iFirstFlag==true){
		
		struct PickLogStruct *pList=NULL,*pTemp;
		
		if(InitPickLog(sSourceID,sTableName,&pList)<0){
			WriteAlertMsg("加载PICK_LOG失败");
			return -1;
		}

		pControl=pList;
		
		while(pList!=NULL){
			pTemp=pList;
			pList=pList->pNext;
			
			p=pTemp;
			
			if(InsertBin(&ptHead,(void *)p,
				data_search_bintree_pick_log_e,
				assign_insert_bintree)<0){
				WriteAlertMsg("生成BINTREE失败PICK_LOG");
				return -1;
			}
		}
		iFirstFlag=false;
	}
	bzero((void*)&Temp,sizeof(struct PickLogStruct));
	strcpy(Temp.sFileName,sFileName);
	
	if((SearchBin(ptHead,&Temp,data_search_bintree_pick_log_e,
		(void**)&p))==NOTFOUND) 
		return NOTFOUND;
	
	while(p!=NULL){
		if(strcmp(p->sState,"A")==0){
			*pptCur=p;
			return FOUND;
		}
		p=p->pNext;
	}	
	return NOTFOUND;
}
void FilterFileName(char sFileName[])
{
	char *p,sTemp[512];


	strcpy(sTemp,sFileName);

	TrimAll(sTemp);

	
	if((p=strrchr(sTemp,' '))==NULL)
		p=strrchr(sTemp,'\t');

	if(p!=NULL){
		p++;
		strcpy(sFileName,p);
	}
	else
		strcpy(sFileName,sTemp);
	/*去掉扩展名,pick.sh是将gz或.Z的文件名写日志
	if(RLike(sFileName,".Z"))
		sFileName[strlen(sFileName)-2]=0;
	if(RLike(sFileName,".gz"))
		sFileName[strlen(sFileName)-3]=0;
	*/
}
int main(int argc,char *argv[])
{

	char sSourceID[20],sListFileName[120];
	char sFileName[256],sBaseName[256],sTableName[30],sCommand[1024];
	struct PickLogStruct *pNoUse;
	struct FileControlStruct *ptHead=NULL,*pTemp;
	
	if(argc!=3){
		printf("Usage %s source listfilename.\n",argv[0]);
		return -1;
	}
	strcpy(sSourceID,argv[1]);
	strcpy(sListFileName,argv[2]);
	
	if(RLike(argv[0],"putdup")==true)
		strcpy(sTableName,"PUT_LOG");
	else	strcpy(sTableName,"PICK_LOG");
	
	if(TxtFileToList(sListFileName,&ptHead)<0) return -1;
	
	if(ConnectDataDB()<0) return -1;
	
	if(SearchPickLog(sSourceID,"",sTableName,&pNoUse)<0) return -1;
	
	sprintf(sCommand,"cat /dev/null >%s",sListFileName);
	if(system(sCommand)!=0) return -1;
	
	while(ptHead!=NULL){
		
		pTemp=ptHead;
		ptHead=ptHead->pNext;
/*从链表中取出文件名*/
		strncpy(sFileName,pTemp->pData,pTemp->iLen);
		sFileName[pTemp->iLen]=0;
		FilterFileName(sFileName);
		GetBaseName(sFileName,sBaseName);
/*如果已经采集过了文件就ok了，否则将文件名打到文件中sList中*/
		if(SearchPickLog(sSourceID,sBaseName,sTableName,&pNoUse)==FOUND)
			continue;
/*将找不到的话单文件写回到文件中*/
		PrintLog(sListFileName,"%s\n",sBaseName);
	}
	DisconnectDatabase();
	
	return 0;
}
