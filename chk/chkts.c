#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

/*����Ŀ���ļ�*/
int main(int argc,char *argv[])
{

	int iUsedPercent,iAlertPercent;
	char sTableSpaceName[20],sLogStr[200];
		
	if(argc!=3){
		printf("Usage %s tabspacename persent.\n",argv[0]);
		return -1;
	}

/*��ʼ����������*/
	iUsedPercent=0;
	iAlertPercent=0;
	strcpy(sTableSpaceName,argv[1]);	
	iAlertPercent = atoi(argv[2]);

/**�������Ϸ���*******/
	if (iAlertPercent > 100 || iAlertPercent < 1){
		printf("�жϰٷֱȲ���ȷ!������1-100֮�������.\n");
		return -1;
	}
	
	if(IniConnect("dataconnstr")<0){
		printf("�޷��������ݿ�.\n");
		return -1;
	}

	iUsedPercent=GetTablespaceUsedPercent(sTableSpaceName);	
	
	if (iUsedPercent > iAlertPercent) {
		sprintf(sLogStr ,"�澯!��ռ�'%s'�Ѿ�ʹ��%d%c,δʹ��%d%c\n"
		,sTableSpaceName,iUsedPercent,'%',100-iUsedPercent,'%');
				
	}
	else{
		/*sprintf(sLogStr ,"��ռ�'%s'����.\n",sTableSpaceName);*/
		strcpy(sLogStr,"");
	}
			
	printf("%s\n",sLogStr);
	
	DisconnectDatabase();
		
	return 0;
}

