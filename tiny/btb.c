/*---------����ʵ�ִ��� unicom_ticket.pc----------*/
#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>

#include <stt_ticket.h>

int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char sPath[256],sFileName[256],sCommand[256],sPreName[256];
	static int iCount=0,iSeq=0;
        
        struct SttTicketStruct Temp;
        struct SttTicketStructIn TempIn;

	if(argc!=3){
		printf("�÷���%s path tablename.\n",argv[0]);
		exit(1);
	}
	InitAppRes(argv[0]);
        IniConnect("dataconnstr");
        
        bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));
	strcpy(TempIn.sCondition,"");
	
        strcpy(sPath,argv[1]);
        strcpy(TempIn.sTableName,argv[2]);
	RegularDir(sPath);
	Upper(TempIn.sTableName);
	
	strcpy(sPreName,"");
	strcpy(sFileName,"");
	
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;
        	
        while(EGetSttTicketToStruct(&Temp,&TempIn)){
        
		if(iCount%10000==0&&iCount!=0){
			printf("��%s��������������%d.\n",TempIn.sTableName,iCount);
			WriteProcMsg("��%s��������������%d.",TempIn.sTableName,iCount);
		}
		if(iCount%20000000==0){
			if(fp!=NULL)fclose(fp);
			if(strcmp(sPreName,"")!=0){
				sprintf(sCommand,"compress %s",sPreName);
				system(sCommand);
				printf("�ļ� %s �������.\n",sPreName);
				WriteProcMsg("�ļ� %s �������.",sPreName);
			}
			sprintf(sFileName,"%s%s.%03d",
				sPath,TempIn.sTableName,iSeq);
			strcpy(sPreName,sFileName);
			if((fp=fopen(sFileName,"w"))==NULL){
				printf("���ļ�%sʧ��.\n",sFileName);
				exit(1);
			}
			iSeq++;
		}
		iCount++;
			
		fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\n",
			Temp.sCallType,Temp.sMsisdn,Temp.sOtherParty,
			Temp.sStartTime,Temp.iDuration,Temp.iTicketTypeID,
			Temp.sThirdParty,Temp.sMsc,Temp.sTrunkIn,Temp.sTrunkOut,
			Temp.iRoamFee,Temp.iTollFee,Temp.iAddFee,
			Temp.sSplitType,Temp.sUserType,Temp.sSourceID);

        }
	if(fp!=NULL)fclose(fp);
	if(strcmp(sFileName,"")!=0){
		sprintf(sCommand,"compress %s",sFileName);
		system(sCommand);
		printf("�ļ� %s �������.\n",sFileName);
		WriteProcMsg("�ļ� %s �������.",sFileName);
	}
        
	printf("�����ͨ��ϣ���������%d.\n",iCount);
	WriteProcMsg("��%s�����ļ����,��������%d.",TempIn.sTableName,iCount);

        DisconnectDatabase();

	return 0;
}

