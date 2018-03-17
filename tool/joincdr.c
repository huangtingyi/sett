#include <hnixs.h>
#include <list.h>
#include <bintree.h>
#include <wwdir.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwsupp.h>
#include <ticket_field.h>


struct JoinCdrStruct
{
	struct JoinCdrStruct *pNext;
	char sCallType[3];
	char sMsisdn[16];
	char sOtherParty[25];
	time_t tStartTime;
	int	iDuration;
	int	iRoamFee;
	int	iTollFee;
	int	iAddFee;
	char	sDeformFlag[2];
	struct FileControlStruct *pStdCdr;	
};

/*系统时间*/
int iMaxWaitSec=0;
time_t tHostTime=0;
struct FileControlStruct *pJoinOutList=NULL;	/*合并输出的话单*/
struct FileControlStruct *pJoiningList=NULL;	/*未被合并的话单*/
struct FileControlStruct *pJoinDnList=NULL;	/*合并调的话单*/

void InitJoinCdr(struct FileControlStruct *pTemp,struct JoinCdrStruct *po)
{/*数据文件移动到内存部分*/

	char sTemp[15];
	struct FSttTicketStruct *pi=(struct FSttTicketStruct*)pTemp->pData;
	
	bzero((void*)po,sizeof(struct JoinCdrStruct));

	strncpy(po->sCallType,		pi->sCallType,2);
	strncpy(po->sMsisdn,		pi->sMsisdn,15);
	strncpy(po->sOtherParty,	pi->sOtherParty,24);

	strncpy(sTemp,pi->sStartTime,14); sTemp[14]=0;
	po->tStartTime=tGetTime(sTemp);		
	
	strncpy(sTemp,pi->sDuration,6);sTemp[6]=0;
	po->iDuration=	atoi(sTemp);
	
	strncpy(sTemp,pi->sRoamFee,5);sTemp[5]=0;
	po->iRoamFee=	atoi(sTemp);
	
	strncpy(sTemp,pi->sTollFee,7);sTemp[7]=0;
	po->iTollFee=	atoi(sTemp);
	
	strncpy(sTemp,pi->sAddFee,5);sTemp[5]=0;
	po->iAddFee=	atoi(sTemp);

	strncpy(po->sDeformFlag,	pi->sDeformFlag,1);

	AllTrim(po->sCallType);
	AllTrim(po->sMsisdn);
	AllTrim(po->sOtherParty);
	
	po->pNext=NULL;
	po->pStdCdr=pTemp;
}
int data_search_bintree_join_cdr_e(void *pValue,void*pData)
{
	struct JoinCdrStruct *pSource=(struct JoinCdrStruct *)pValue;
	struct JoinCdrStruct *pTarget=(struct JoinCdrStruct *)pData;

/*数据比较部分*/
	int res=0;

	if((res=strcmp(pSource->sCallType,pTarget->sCallType))!=0) return res;
	if((res=strcmp(pSource->sMsisdn,pTarget->sMsisdn))!=0) return res;
	if((res=strcmp(pSource->sOtherParty,pTarget->sOtherParty))!=0) return res;

	return 0;

}
int comp_list_join_cdr_e(LIST *pValue,LIST*pData)
{
	struct JoinCdrStruct *pSource=(struct JoinCdrStruct *)pValue;
	struct JoinCdrStruct *pTarget=(struct JoinCdrStruct *)pData;

	return pSource->tStartTime-pTarget->tStartTime;
}

void assign_insert_bintree_join_cdr_e(void **ppData,void *pData)
{
	InsertListSort((LIST**)ppData,(LIST*)pData,
		comp_list_join_cdr_e);
}

int AddFileToBin(BINTREE **ppRoot,char sFileName[])
{
	int iCnt=0;
	struct JoinCdrStruct *pJoin=NULL;
	struct FileControlStruct *ptHead=NULL,*pTemp;

	if(TxtFileToList(sFileName,&ptHead)<0){
		WriteAlertPrint("加载文件%s到内存失败",sFileName);
		return -1;
	}
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;

		/*分配内存并生成pJoin结构*/
		if((pJoin=malloc(sizeof(struct JoinCdrStruct)))==NULL){
			WriteAlertPrint("分配JOINCDR内存失败");
			return -1;
		}
		InitJoinCdr(pTemp,pJoin);
		
		/*插入平衡二叉树*/
		if(InsertBin(ppRoot,(void *)pJoin,
			data_search_bintree_join_cdr_e,
			assign_insert_bintree_join_cdr_e)<0){
			WriteAlertPrint("生成BINTREE失败JOIN CDR");
			return -1;
		}
	}
	return iCnt;
}
/*
合并话单主应用
*/
struct JoinCdrStruct *GetJoinCdrList(struct JoinCdrStruct **pptHead)
{
	struct JoinCdrStruct *ptPre,*ptCur=NULL,*ptHead=NULL;

	ptCur=*pptHead;

	if(ptCur==NULL) return NULL;

	while(1){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		/*如果没了，直接返回链表*/
		if(ptCur==NULL) break;

		/*如果已经不连续了话单*/
		if(ptPre->tStartTime+ptPre->iDuration<ptCur->tStartTime){
			ptPre->pNext=NULL;
			break;
		}
	}
	ptHead=*pptHead;
	*pptHead=ptCur;
	
	return ptHead;
}

/*
输入：一个JoinCdrList链表,start_time升序排列.
输出：一个JoinCdrList链表,start_time升序排列,deform_flag打上标记
	被合并的话单,	deform_flag='X'
	合并后完整话单,	deform_flag='0'
	合并后完整话单的start_time,duration,fee等字段修改如下:
		start_time=合并前deform_flag='1'的话单的start_time
		duration=sum(d1,d2,d....,dn)
		fee=sum(fee1,fee2,...,feen)		
*/
void MarkDeformFlagAndModifyStartTimeDuraFee(struct JoinCdrStruct *ptHead)
{
	int iDuration,iRoamFee,iTollFee,iAddFee;
	char sStartTime[15],sDuration[7],sRoamFee[6],sTollFee[8],sAddFee[6];
	struct JoinCdrStruct *pTail,*pNew;
	struct FSttTicketStruct *p;

	if(ptHead==NULL) return;

	/*让pTail指针向最后一张话单*/
	pTail=ptHead;
	while(pTail->pNext!=NULL)pTail=pTail->pNext;

	/*如果不是，遇到结束话单或最后一张话单和系统时间比较是超时，则不处理*/
	if(!(pTail->sDeformFlag[0]=='3'||
		tHostTime-(pTail->tStartTime+pTail->iDuration)>iMaxWaitSec)) return;

	sFormatTime(ptHead->tStartTime,sStartTime);

	/*统计合并字段信息*/	
	iDuration=iRoamFee=iTollFee=iAddFee=0;

	while(ptHead!=NULL){
		iDuration+=ptHead->iDuration;
		iRoamFee+=ptHead->iRoamFee;
		iTollFee+=ptHead->iTollFee;
		iAddFee +=ptHead->iAddFee;
			
		/*到这里，就是起始或中间话单,即被合并调的话单,标记打上*/
		ptHead->sDeformFlag[0]='X';
		/*将third_party用于存储start_time，便于关联*/
		p=(struct FSttTicketStruct *)(ptHead->pStdCdr->pData);
		/*不覆盖最后一张话单的THIRD_PARTY*/
		if(ptHead!=pTail)
			strncpy(p->sThirdParty,sStartTime,14);

		ptHead=ptHead->pNext;		
	}
	
	
/*复制一个新节点，并将合并结果填上，挂在链表末尾*/
	if((pNew=malloc(sizeof(struct JoinCdrStruct)))==NULL){
		WriteAlertPrint("分配JOINCDR内存失败");
		exit(1);
	}
	memcpy((void*)pNew,(void*)pTail,sizeof(struct JoinCdrStruct));
	pNew->sDeformFlag[0]='0';

	pNew->pStdCdr=NULL;
	if(item2list(&pNew->pStdCdr,pTail->pStdCdr->pData,
		pTail->pStdCdr->iLen)<0){
		WriteAlertPrint("分配 FileControl内存错误");
		exit(1);
	}
	
	p=(struct FSttTicketStruct *)(pNew->pStdCdr->pData);
					
	/*将时长、费用及start_time字段填回话单*/
	sprintf(sDuration,"%06d",iDuration);
	sprintf(sRoamFee,"%05d",iRoamFee);
	sprintf(sTollFee,"%07d",iTollFee);
	sprintf(sAddFee,"%05d",iAddFee);
	
	strncpy(p->sStartTime,sStartTime,14);
	strncpy(p->sDuration,sDuration,6);
	strncpy(p->sRoamFee,sRoamFee,5);
	strncpy(p->sTollFee,sTollFee,7);
	strncpy(p->sAddFee,sAddFee,5);
		
	p->sDeformFlag[0]='4';
	
	/*修改最后一张话单pTail的THIRD_PARTY*/
	p=(struct FSttTicketStruct *)(pTail->pStdCdr->pData);
	strncpy(p->sThirdParty,sStartTime,14);

	pTail->pNext=pNew;
}
/*释放JoinCdr链表并将合并结果加入Joined和Joining两个FileControl列表*/
void FreeJoinCdrListAdd2JoinedJoining(struct JoinCdrStruct *ptHead)
{
	struct JoinCdrStruct *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*被合并调的话单就不要了*/
		if(pTemp->sDeformFlag[0]=='X'){
			InsertList((LIST**)&pJoinDnList,(LIST*)pTemp->pStdCdr);
		}/*这里是合并后的话单*/
		else if(pTemp->sDeformFlag[0]=='0'){
			InsertList((LIST**)&pJoinOutList,(LIST*)pTemp->pStdCdr);
		}
		else {/*这里是未合并的话单*/
			InsertList((LIST**)&pJoiningList,(LIST*)pTemp->pStdCdr);
		}
		free(pTemp);
	}
}

int join_cdr_list_add_joined_joined_list(void **pptData)
{
	struct JoinCdrStruct *ptLkHead=(struct JoinCdrStruct *)(*pptData),*ptHead;

	while((ptHead=GetJoinCdrList(&ptLkHead))!=NULL){

		/*打标志并汇总各指标*/
		MarkDeformFlagAndModifyStartTimeDuraFee(ptHead);

		/*释放JoinCdr链表并将合并结果加入Joined和Joining两个FileControl列表*/
		/*这里的FileControl结构加到JoinedList和JoiningList后写文件后释放*/	
		FreeJoinCdrListAdd2JoinedJoining(ptHead);
	}

	/*安全起见，将链表头设为空*/
	*pptData=NULL;

	return 0;
}

/*拿到序列号控制文件名*/
void GetAppSeqName(char sAppSeqName[])
{
	char sAppHome[256];
	
	GetAppHome(sAppHome);
	
	sprintf(sAppSeqName,"%s%s/joincdr.seq",sAppHome,"ctl");
}
/*
输入：
	source_dir下的 *.J的一组文件，
	JOINING.CDR（未完成合并的话单）文件.
输出：
	target_dir下的 JOINEDYYYYMMDDNNNNN.FIX.BIL.B文件，
	和JOINING.CDR（未完成合并的话单）文件
功能:	
	为了安全避免重单，在处理文件前将所有的文件名改名为*.J.tmp
	将输入的文件 *.J的文件加载到内存，并将JOINING.CDR也加载到BIN树内，
	加载话单的数量为100万条为上线，先加载JOINING.CDR话单.
	
	检察待合并的话单，将合并后的话单,deform_flag打为,'0'，
	被合并调的话单的,deform_flag打为'X'
	
	遍历整个树，将未合并的话单写到JOINING.CDR文件中，将合并后的话单写到
	JOINEDYYYYMMDDNNNNN.FIX.BIL.B文件中。
	
	检察JOINING.CDR文件大小，如果大于50万则退出;
	
	再处理完后，将所有*.J.tmp文件删除调.
*/
int main(int argc,char *argv[])
{
	BINTREE *pRoot=NULL;
	int iSeq=0;
	struct FileControlStruct *ptLkHead=NULL,*ptHead,*pTemp;
	char sCmd[1024],sResult[1024];
	char sSourcePath[120],sFilter[20],sTargetPath[120],sAppSeqName[256];
	char sFileName[256],sTargetName[256],sHostDate[15],sTempName[256];
	char sStackName[256],sTmpName[256],sBaseName[256],sDoneName[256];
	
	if(argc!=3){
		printf("Usage: %s joindir maxwaitsec\n",argv[0]);
		exit(1);
	}

	InitAppRes(argv[0]);

	strcpy(sSourcePath,argv[1]);
	strcpy(sTargetPath,argv[1]);
	iMaxWaitSec=atoi(argv[2]);


	RegularDir(sSourcePath);
	RegularDir(sTargetPath);

/*最少等10分钟*/
	if(iMaxWaitSec<600) iMaxWaitSec=600;
	
	strcpy(sFilter,"*.J");

/*拿到控制文件序号*/
	GetAppSeqName(sAppSeqName);
	
	if(IsFile(sAppSeqName)){
		sprintf(sCmd,"head -1 %s",sAppSeqName);
		if(exec2str(sCmd,sResult)<0){
			WriteAlertPrint("执行 %s 失败",sCmd);
			return -1;
		}
		iSeq=atoi(sResult);
	}
	iSeq=iSeq+1;
	
	if(iSeq>99999) iSeq=0;

/*拿到系统时间*/
	tHostTime=tGetHostTime();

	GetHostTime(sHostDate);sHostDate[8]=0;

/*如果有积压的上次的文件，则改名为一个临时文件，加载到一起处理*/	
	sprintf(sStackName,"%sJOINING.CDR",sSourcePath);
	sprintf(sTempName,"%sJOINTP%s%05d.FIX.BIL.J",
		sSourcePath,sHostDate,iSeq);
	if(IsFile(sStackName)&&FileSize(sStackName)>0){
                if(Rename(sStackName,sTempName)<0){
                        WriteAlertPrint("将%s改名为%s失败",sStackName,sTempName);
                        return -1;
                }
	}
/*生成输出文件名*/
	sprintf(sTargetName,"%sJOINED%s%05d.FIX.BIL.B",
		sTargetPath,sHostDate,iSeq);
	sprintf(sDoneName,"%sJOINDN%s%05d.FIX.BIL.O",
		sTargetPath,sHostDate,iSeq);

/*将待处理的文件列表拿到*/
	if(dir2list(sSourcePath,sFilter,&ptLkHead)<0){
		WriteAlertPrint("生成文件列表失败 %s %s",sSourcePath,sFilter);
		return -1;
	}
	WriteProcPrint("加载%d个文件",CountList((LIST*)ptLkHead));

/*作一个循环将*.J的文件修改为*.J.tmp文件*/
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sBaseName,(char*)(pTemp->pData),pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		
		sprintf(sFileName,"%s%s",sSourcePath,sBaseName);
		sprintf(sTmpName,"%s%s.tmp",sSourcePath,sBaseName);
		
                if(Rename(sFileName,sTmpName)<0){
                        WriteAlertPrint("将%s改名为%s失败",sTmpName,sFileName);
                        return -1;
                }
	}		

/*作一个循环将数据加载到BIN树中*/
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sBaseName,(char*)(pTemp->pData),pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		
		sprintf(sTmpName,"%s%s.tmp",sSourcePath,sBaseName);

		if(AddFileToBin(&pRoot,sTmpName)<0) return -1;

	}
/*合并话单*/
	TravelBin(pRoot,join_cdr_list_add_joined_joined_list);
	
/*将合并好的文件写到TargetName文件中*/
	if(list2fileln(&pJoinOutList,sTargetName)<0) return -1;

/*将合并调的记录写到DoneName文件中*/
	if(list2fileln(&pJoinDnList,sDoneName)<0) return -1;

/*将未合并的文件写到StackName文件中*/
	if(list2fileln(&pJoiningList,sStackName)<0) return -1;
		
	WriteProcPrint("生成%s文件成功",sTargetName);

/*删除调处理过的记录*/
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sBaseName,(char*)(pTemp->pData),pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		
		sprintf(sTmpName,"%s%s.tmp",sSourcePath,sBaseName);

                if(Remove(sTmpName)<0){
                        WriteAlertPrint("将%s删除失败",sTmpName);
                        return -1;
                }
	}
/*写控制文件*/
	sprintf(sCmd,"echo %d > %s",iSeq,sAppSeqName);
	if(execcmd(sCmd)<0){
		WriteAlertPrint("执行 %s 失败",sCmd);
		return -1;
	}
	
	return 0;
}
