/*---------����ʵ�ִ��� unicom_ticket.pc----------*/
#include <stdio.h>
#include <stdlib.h>
#include <wwdb.h>
#include <wwlog.h>
#include <wwtiny.h>

#include <stt_ticket.h>

#define	FORMAT_CHK_STD		0	/*��׼��ʽ;*/
#define FORMAT_CHK_FJTEL	1	/*�������Ÿ�ʽ;*/
#define FORMAT_CHK_FJMOB	2	/*�����ƶ���ʽ;*/

/*�������ݽṹ����������ݶ���������*/
int main(int argc,char *argv[])
{
	FILE *fp;
	char	sFileName[128];
	static int iCount=0,iFormat;
        
        struct SttTicketStruct Temp;
        struct SttTicketStructIn TempIn;

	if(argc!=3&&argc!=4&&argc!=5){
		printf("format:: 0:��׼��ʽ,1:�������Ÿ�ʽ,2:�����ƶ���ʽ.\n");
		printf("�÷���%s filename [format] [tablename] [condition].\n",argv[0]);
		exit(1);
	}

        IniConnect("dataconnstr");
        
        bzero((void*)&TempIn,sizeof(struct SttTicketStructIn));
	strcpy(TempIn.sCondition,"");
	
	strcpy(sFileName,argv[1]);
        iFormat=atoi(argv[2]);
        
        if(argc==3){
        	strcpy(TempIn.sTableName,"UNICOM_TICKET");
        }
        else if(argc==4){
        	strcpy(TempIn.sTableName,argv[3]);
        }
        else{
        	strcpy(TempIn.sTableName,argv[3]);
        	strcpy(TempIn.sCondition,argv[4]);
        }
        TempIn.iBufEmpty =TRUE;
        TempIn.iFirstFlag = TRUE;

	if((fp=fopen(sFileName,"w"))==NULL){
		printf("���ļ�%sʧ��.\n",sFileName);
		exit(1);
	}
		
        while(EGetSttTicketToStruct(&Temp,&TempIn)){
        
		iCount++;
		
		if(iFormat==FORMAT_CHK_FJTEL)
			fprintf(fp,"%s\t%s\t%s\t%d\t%s\t%s\t%s\n",
				Temp.sMsisdn,Temp.sOtherParty,
				Temp.sStartTime,Temp.iDuration,
				Temp.sMsc,Temp.sTrunkIn,Temp.sTrunkOut);
		else if(iFormat==FORMAT_CHK_FJMOB)
			fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\n",
				Temp.sCallType,Temp.sMsisdn,Temp.sOtherParty,
				Temp.sStartTime,Temp.iDuration,Temp.sMsc,
				Temp.sTrunkIn,Temp.sTrunkOut,Temp.iTicketTypeID);
		else
			fprintf(fp,"%s\t%s\t%s\t%d\t%d\t%s\t%s\t%s\t%s\n",
				Temp.sMsisdn,Temp.sOtherParty,
				Temp.sStartTime,Temp.iDuration,Temp.iTicketTypeID,
				Temp.sThirdParty,Temp.sMsc,Temp.sTrunkIn,Temp.sTrunkOut);
		if(iCount%10000==0)
			printf("��ǰ�����ͨ������%d.\n",iCount);
        }
	fclose(fp);
        
	printf("�����ͨ��ϣ���������%d.\n",iCount);

        DisconnectDatabase();

	return 0;
}

