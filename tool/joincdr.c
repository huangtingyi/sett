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

/*ϵͳʱ��*/
int iMaxWaitSec=0;
time_t tHostTime=0;
struct FileControlStruct *pJoinOutList=NULL;	/*�ϲ�����Ļ���*/
struct FileControlStruct *pJoiningList=NULL;	/*δ���ϲ��Ļ���*/
struct FileControlStruct *pJoinDnList=NULL;	/*�ϲ����Ļ���*/

void InitJoinCdr(struct FileControlStruct *pTemp,struct JoinCdrStruct *po)
{/*�����ļ��ƶ����ڴ沿��*/

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

/*���ݱȽϲ���*/
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
		WriteAlertPrint("�����ļ�%s���ڴ�ʧ��",sFileName);
		return -1;
	}
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		iCnt++;

		/*�����ڴ沢����pJoin�ṹ*/
		if((pJoin=malloc(sizeof(struct JoinCdrStruct)))==NULL){
			WriteAlertPrint("����JOINCDR�ڴ�ʧ��");
			return -1;
		}
		InitJoinCdr(pTemp,pJoin);
		
		/*����ƽ�������*/
		if(InsertBin(ppRoot,(void *)pJoin,
			data_search_bintree_join_cdr_e,
			assign_insert_bintree_join_cdr_e)<0){
			WriteAlertPrint("����BINTREEʧ��JOIN CDR");
			return -1;
		}
	}
	return iCnt;
}
/*
�ϲ�������Ӧ��
*/
struct JoinCdrStruct *GetJoinCdrList(struct JoinCdrStruct **pptHead)
{
	struct JoinCdrStruct *ptPre,*ptCur=NULL,*ptHead=NULL;

	ptCur=*pptHead;

	if(ptCur==NULL) return NULL;

	while(1){
		ptPre=ptCur;
		ptCur=ptCur->pNext;

		/*���û�ˣ�ֱ�ӷ�������*/
		if(ptCur==NULL) break;

		/*����Ѿ��������˻���*/
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
���룺һ��JoinCdrList����,start_time��������.
�����һ��JoinCdrList����,start_time��������,deform_flag���ϱ��
	���ϲ��Ļ���,	deform_flag='X'
	�ϲ�����������,	deform_flag='0'
	�ϲ�������������start_time,duration,fee���ֶ��޸�����:
		start_time=�ϲ�ǰdeform_flag='1'�Ļ�����start_time
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

	/*��pTailָ�������һ�Ż���*/
	pTail=ptHead;
	while(pTail->pNext!=NULL)pTail=pTail->pNext;

	/*������ǣ������������������һ�Ż�����ϵͳʱ��Ƚ��ǳ�ʱ���򲻴���*/
	if(!(pTail->sDeformFlag[0]=='3'||
		tHostTime-(pTail->tStartTime+pTail->iDuration)>iMaxWaitSec)) return;

	sFormatTime(ptHead->tStartTime,sStartTime);

	/*ͳ�ƺϲ��ֶ���Ϣ*/	
	iDuration=iRoamFee=iTollFee=iAddFee=0;

	while(ptHead!=NULL){
		iDuration+=ptHead->iDuration;
		iRoamFee+=ptHead->iRoamFee;
		iTollFee+=ptHead->iTollFee;
		iAddFee +=ptHead->iAddFee;
			
		/*�����������ʼ���м仰��,�����ϲ����Ļ���,��Ǵ���*/
		ptHead->sDeformFlag[0]='X';
		/*��third_party���ڴ洢start_time�����ڹ���*/
		p=(struct FSttTicketStruct *)(ptHead->pStdCdr->pData);
		/*���������һ�Ż�����THIRD_PARTY*/
		if(ptHead!=pTail)
			strncpy(p->sThirdParty,sStartTime,14);

		ptHead=ptHead->pNext;		
	}
	
	
/*����һ���½ڵ㣬�����ϲ�������ϣ���������ĩβ*/
	if((pNew=malloc(sizeof(struct JoinCdrStruct)))==NULL){
		WriteAlertPrint("����JOINCDR�ڴ�ʧ��");
		exit(1);
	}
	memcpy((void*)pNew,(void*)pTail,sizeof(struct JoinCdrStruct));
	pNew->sDeformFlag[0]='0';

	pNew->pStdCdr=NULL;
	if(item2list(&pNew->pStdCdr,pTail->pStdCdr->pData,
		pTail->pStdCdr->iLen)<0){
		WriteAlertPrint("���� FileControl�ڴ����");
		exit(1);
	}
	
	p=(struct FSttTicketStruct *)(pNew->pStdCdr->pData);
					
	/*��ʱ�������ü�start_time�ֶ���ػ���*/
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
	
	/*�޸����һ�Ż���pTail��THIRD_PARTY*/
	p=(struct FSttTicketStruct *)(pTail->pStdCdr->pData);
	strncpy(p->sThirdParty,sStartTime,14);

	pTail->pNext=pNew;
}
/*�ͷ�JoinCdr�������ϲ��������Joined��Joining����FileControl�б�*/
void FreeJoinCdrListAdd2JoinedJoining(struct JoinCdrStruct *ptHead)
{
	struct JoinCdrStruct *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		/*���ϲ����Ļ����Ͳ�Ҫ��*/
		if(pTemp->sDeformFlag[0]=='X'){
			InsertList((LIST**)&pJoinDnList,(LIST*)pTemp->pStdCdr);
		}/*�����Ǻϲ���Ļ���*/
		else if(pTemp->sDeformFlag[0]=='0'){
			InsertList((LIST**)&pJoinOutList,(LIST*)pTemp->pStdCdr);
		}
		else {/*������δ�ϲ��Ļ���*/
			InsertList((LIST**)&pJoiningList,(LIST*)pTemp->pStdCdr);
		}
		free(pTemp);
	}
}

int join_cdr_list_add_joined_joined_list(void **pptData)
{
	struct JoinCdrStruct *ptLkHead=(struct JoinCdrStruct *)(*pptData),*ptHead;

	while((ptHead=GetJoinCdrList(&ptLkHead))!=NULL){

		/*���־�����ܸ�ָ��*/
		MarkDeformFlagAndModifyStartTimeDuraFee(ptHead);

		/*�ͷ�JoinCdr�������ϲ��������Joined��Joining����FileControl�б�*/
		/*�����FileControl�ṹ�ӵ�JoinedList��JoiningList��д�ļ����ͷ�*/	
		FreeJoinCdrListAdd2JoinedJoining(ptHead);
	}

	/*��ȫ�����������ͷ��Ϊ��*/
	*pptData=NULL;

	return 0;
}

/*�õ����кſ����ļ���*/
void GetAppSeqName(char sAppSeqName[])
{
	char sAppHome[256];
	
	GetAppHome(sAppHome);
	
	sprintf(sAppSeqName,"%s%s/joincdr.seq",sAppHome,"ctl");
}
/*
���룺
	source_dir�µ� *.J��һ���ļ���
	JOINING.CDR��δ��ɺϲ��Ļ������ļ�.
�����
	target_dir�µ� JOINEDYYYYMMDDNNNNN.FIX.BIL.B�ļ���
	��JOINING.CDR��δ��ɺϲ��Ļ������ļ�
����:	
	Ϊ�˰�ȫ�����ص����ڴ����ļ�ǰ�����е��ļ�������Ϊ*.J.tmp
	��������ļ� *.J���ļ����ص��ڴ棬����JOINING.CDRҲ���ص�BIN���ڣ�
	���ػ���������Ϊ100����Ϊ���ߣ��ȼ���JOINING.CDR����.
	
	�����ϲ��Ļ��������ϲ���Ļ���,deform_flag��Ϊ,'0'��
	���ϲ����Ļ�����,deform_flag��Ϊ'X'
	
	��������������δ�ϲ��Ļ���д��JOINING.CDR�ļ��У����ϲ���Ļ���д��
	JOINEDYYYYMMDDNNNNN.FIX.BIL.B�ļ��С�
	
	���JOINING.CDR�ļ���С���������50�����˳�;
	
	�ٴ�����󣬽�����*.J.tmp�ļ�ɾ����.
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

/*���ٵ�10����*/
	if(iMaxWaitSec<600) iMaxWaitSec=600;
	
	strcpy(sFilter,"*.J");

/*�õ������ļ����*/
	GetAppSeqName(sAppSeqName);
	
	if(IsFile(sAppSeqName)){
		sprintf(sCmd,"head -1 %s",sAppSeqName);
		if(exec2str(sCmd,sResult)<0){
			WriteAlertPrint("ִ�� %s ʧ��",sCmd);
			return -1;
		}
		iSeq=atoi(sResult);
	}
	iSeq=iSeq+1;
	
	if(iSeq>99999) iSeq=0;

/*�õ�ϵͳʱ��*/
	tHostTime=tGetHostTime();

	GetHostTime(sHostDate);sHostDate[8]=0;

/*����л�ѹ���ϴε��ļ��������Ϊһ����ʱ�ļ������ص�һ����*/	
	sprintf(sStackName,"%sJOINING.CDR",sSourcePath);
	sprintf(sTempName,"%sJOINTP%s%05d.FIX.BIL.J",
		sSourcePath,sHostDate,iSeq);
	if(IsFile(sStackName)&&FileSize(sStackName)>0){
                if(Rename(sStackName,sTempName)<0){
                        WriteAlertPrint("��%s����Ϊ%sʧ��",sStackName,sTempName);
                        return -1;
                }
	}
/*��������ļ���*/
	sprintf(sTargetName,"%sJOINED%s%05d.FIX.BIL.B",
		sTargetPath,sHostDate,iSeq);
	sprintf(sDoneName,"%sJOINDN%s%05d.FIX.BIL.O",
		sTargetPath,sHostDate,iSeq);

/*����������ļ��б��õ�*/
	if(dir2list(sSourcePath,sFilter,&ptLkHead)<0){
		WriteAlertPrint("�����ļ��б�ʧ�� %s %s",sSourcePath,sFilter);
		return -1;
	}
	WriteProcPrint("����%d���ļ�",CountList((LIST*)ptLkHead));

/*��һ��ѭ����*.J���ļ��޸�Ϊ*.J.tmp�ļ�*/
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;

		strncpy(sBaseName,(char*)(pTemp->pData),pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		
		sprintf(sFileName,"%s%s",sSourcePath,sBaseName);
		sprintf(sTmpName,"%s%s.tmp",sSourcePath,sBaseName);
		
                if(Rename(sFileName,sTmpName)<0){
                        WriteAlertPrint("��%s����Ϊ%sʧ��",sTmpName,sFileName);
                        return -1;
                }
	}		

/*��һ��ѭ�������ݼ��ص�BIN����*/
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sBaseName,(char*)(pTemp->pData),pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		
		sprintf(sTmpName,"%s%s.tmp",sSourcePath,sBaseName);

		if(AddFileToBin(&pRoot,sTmpName)<0) return -1;

	}
/*�ϲ�����*/
	TravelBin(pRoot,join_cdr_list_add_joined_joined_list);
	
/*���ϲ��õ��ļ�д��TargetName�ļ���*/
	if(list2fileln(&pJoinOutList,sTargetName)<0) return -1;

/*���ϲ����ļ�¼д��DoneName�ļ���*/
	if(list2fileln(&pJoinDnList,sDoneName)<0) return -1;

/*��δ�ϲ����ļ�д��StackName�ļ���*/
	if(list2fileln(&pJoiningList,sStackName)<0) return -1;
		
	WriteProcPrint("����%s�ļ��ɹ�",sTargetName);

/*ɾ����������ļ�¼*/
	ptHead=ptLkHead;
	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		strncpy(sBaseName,(char*)(pTemp->pData),pTemp->iLen);
		sBaseName[pTemp->iLen]=0;
		
		sprintf(sTmpName,"%s%s.tmp",sSourcePath,sBaseName);

                if(Remove(sTmpName)<0){
                        WriteAlertPrint("��%sɾ��ʧ��",sTmpName);
                        return -1;
                }
	}
/*д�����ļ�*/
	sprintf(sCmd,"echo %d > %s",iSeq,sAppSeqName);
	if(execcmd(sCmd)<0){
		WriteAlertPrint("ִ�� %s ʧ��",sCmd);
		return -1;
	}
	
	return 0;
}
