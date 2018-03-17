#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <wwdb.h>

#include <dbsupp.h>

/*生成目标文件*/
int main(int argc,char *argv[])
{

	int iUsedPercent,iAlertPercent;
	char sTableSpaceName[20],sLogStr[200];
		
	if(argc!=3){
		printf("Usage %s tabspacename persent.\n",argv[0]);
		return -1;
	}

/*初始化参数部分*/
	iUsedPercent=0;
	iAlertPercent=0;
	strcpy(sTableSpaceName,argv[1]);	
	iAlertPercent = atoi(argv[2]);

/**检查参数合法性*******/
	if (iAlertPercent > 100 || iAlertPercent < 1){
		printf("判断百分比不正确!请输入1-100之间的数字.\n");
		return -1;
	}
	
	if(IniConnect("dataconnstr")<0){
		printf("无法连接数据库.\n");
		return -1;
	}

	iUsedPercent=GetTablespaceUsedPercent(sTableSpaceName);	
	
	if (iUsedPercent > iAlertPercent) {
		sprintf(sLogStr ,"告警!表空间'%s'已经使用%d%c,未使用%d%c\n"
		,sTableSpaceName,iUsedPercent,'%',100-iUsedPercent,'%');
				
	}
	else{
		/*sprintf(sLogStr ,"表空间'%s'正常.\n",sTableSpaceName);*/
		strcpy(sLogStr,"");
	}
			
	printf("%s\n",sLogStr);
	
	DisconnectDatabase();
		
	return 0;
}

