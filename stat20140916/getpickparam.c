#include <stdio.h>
#include <stdlib.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <wwdb.h>
#include <list.h>
#include <wwfile.h>

#include "gen_supp.h"

int main(int argc, char **argv)
{
	int  iCnt=0,l=0;
	char sNormalDir[256],sOutFileName[256],sFileName[256],sRecord[512];
	
	if(argc!=3){
		printf("Usage %s normaldir filename.\n",argv[0]);
		return -1;
	}
	InitAppRes(argv[0]);
	strcpy(sNormalDir,argv[1]);
	RegularDir(sNormalDir);

	strcpy(sFileName,argv[2]);
	
	sprintf(sOutFileName,"%s%s",sNormalDir,sFileName);

	struct PickTaskParamStruct Temp;
	struct PickTaskParamStructIn TempIn;
	
	FILE *fp=NULL;
	
/**�������ݿ�***/
	if(IniConnect("paramconnstr")<0) return -1;
	

	/**��ʼ�����뻺���Ա**/
	bzero((void*)&TempIn,sizeof(struct PickTaskParamStructIn));
	sprintf(TempIn.sTableName,"PICK_TASK_PARAM");
	sprintf(TempIn.sCondition," WHERE nvl(STATE,'A0A') != 'A0X' ");
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;

	if((fp=fopen(sOutFileName,"w"))==NULL) return -1;
	/*��ȡ����ѭ������**/
	while(EGetPickTaskParamToStruct(&Temp,&TempIn)){

		l=0;
		l+=sprintf(sRecord+l,"%s\t%s\t%s\n",
				Temp.sSourceID,Temp.sOppPath,Temp.sIp);
		WriteFile(fp,sRecord,l);
		++iCnt;
	}
	
	fclose(fp);

	WriteProcMsg(" %d ����¼������ļ� %s �ɹ�.",iCnt,sOutFileName);

	DisconnectDatabase();
	
	return 0;
}
