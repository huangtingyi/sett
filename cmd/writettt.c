#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwtiny.h>
#include <wwfile.h>
#include "ftam.h"

int main(int argc,char *argv[])
{
	FILE *fp;
	int iSeq;
	char	sDate[15],sTargetName[256];
	struct TtcofStruct Temp;
	struct FTttcofStruct FTtt;
	
	
	if(argc!=4){
		printf("usage %s seq createdate tttfile.\n",argv[0]);
		return -1;
	}
	
	iSeq=atoi(argv[1]);
	strncpy(sDate,argv[2],14);sDate[14]=0;
	strcpy(sTargetName,argv[3]);

/*�������Ϸ���*/
	if(iSeq<1||iSeq>=MAX_FILE_SEQ){
		printf("seq=%d ��ֵ������%d��%d֮��.\n",iSeq,1,MAX_FILE_SEQ);
		return -1;
	}
	if(tGetTime(sDate)<0){
		printf("date=%s ������һ���Ϸ�����yyyymmddhh24miss.\n",sDate);
		return -1;
	}
	if(FileSize(sTargetName)!=sizeof(struct FTttcofStruct)*MAX_FILE_SEQ){
		printf("�ļ�%s�ֽ���Ϊ%d,Ӧ���ֽ���Ϊ%d.\n",
			sTargetName,FileSize(sTargetName),
			sizeof(struct FTttcofStruct)*MAX_FILE_SEQ);
		return -1;
	}
/**�̶���д�����������ļ�3���Ӻ���Ϊ�ɼ�ʱ��*/
	AddMinutes(sDate,3);

/*��������ת��Ϊָ����ʽ*/
	Temp.iSeq=	iSeq;
	strcpy(Temp.sStatus,"2");
	strcpy(Temp.sDate,sDate);
	mvitem_tt2ttt(&Temp,&FTtt);
	
/*���ļ�����λ��ָ��λ��*/
	if((fp=fopen(sTargetName,"r+"))==NULL){
		printf("���ļ�%s׷��дʧ��.\n",sTargetName);
		return -1;
	}
	if(fseek(fp,iSeq*sizeof(struct FTttcofStruct),SEEK_SET)==-1){
		printf("��λ�ļ�%sʧ��,pos=%d.\n",sTargetName,
			iSeq*sizeof(struct FTttcofStruct));
		fclose(fp);
		return -1;
	}
	if(fwrite((void*)&FTtt,sizeof(struct FTttcofStruct),1,fp)!=1){
		printf("д�ļ�%sʧ��.\n",sTargetName);
		return -1;
	}
	fclose(fp);
	return 0;
}

