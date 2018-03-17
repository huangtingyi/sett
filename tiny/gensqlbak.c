#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <wwfile.h>
#include <wwcoding.h>
#include <wwdir.h>
#include <wwtiny.h>
#include <wwdb.h>

int main(int argc,char *argv[])
{
	FILE *fp;
	int l,iInterval;
	char sTableName[31],sTemplateName[31],sTablespaceName[31],sIndexspaceName[31],
		sOutputPath[128],sDataMonth[7],sBeginDate[15],sEndDate[15],sTbind[31],
		sCurDate[15],sTempDate[15],sTempNext[15],sTemp[31];
	char sTxt[10240],sFileName[256];


	if(argc!=6&&argc!=7&&argc!=9){
		printf("Usage %s tablename templatename tbind outputpath yyyymm [DateInterval] [TablespaceName IndexspaceName] .\n",
			argv[0]);
		return -1;
	}

	/*获取参数*/
	strncpy(sTableName,argv[1],30);sTableName[30]=0;
	strncpy(sTemplateName,argv[2],30);sTemplateName[30]=0;
	strncpy(sTbind,argv[3],30);sTbind[30]=0;TrimAllX(sTbind,'"');
	strcpy(sOutputPath,argv[4]);
	strcpy(sDataMonth,argv[5]);
	
	if(IsDir(sOutputPath)==FALSE){
		printf("输出目录%s无效.\n",sOutputPath);
		return -1;
	}
	RegularDir(sOutputPath);

	strcpy(sTempDate,sDataMonth);strcpy(sTempDate+6,"01000000");
	if(tGetTime(sTempDate)<0){
		printf("输入的月份%s非法,格式[yyyymm].\n",argv[5]);
		return -1;
	}

	if(argc==7)iInterval=atoi(argv[6]);
	else iInterval=1;
	if(argc==9){
		strncpy(sTemp,argv[7],30);sTemp[30]=0;
		sprintf(sTablespaceName,"%s%s",sTemp,sTbind);
		strncpy(sTemp,argv[8],30);sTemp[30]=0;
		sprintf(sIndexspaceName,"%s%s",sTemp,sTbind);
	}
	else{
		sprintf(sTablespaceName,"DATA%s",sTbind);
		sprintf(sIndexspaceName,"INDEX%s",sTbind);
	}
	if(iInterval>15){
		printf("日期间隔应小于15，默认设为1.\n");
		iInterval=1;
	}
	strcpy(sBeginDate,sDataMonth);
	strcat(sBeginDate,"01000000");
/*生成建表脚本*/
	strcpy(sEndDate,sBeginDate);
	AddMonths(sEndDate,1);
	AddDates(sEndDate,-1);
	
	l=sprintf(sTxt,"\n\
CREATE TABLE %s \n\
	PARTITION BY RANGE(START_TIME)\n\
	(",sTableName);

	strcpy(sCurDate,sBeginDate);

	for(strcpy(sCurDate,sBeginDate);strcmp(sCurDate,sEndDate)<0;
		AddDates(sCurDate,iInterval)){
				
		strcpy(sTempDate,sCurDate);
		strcpy(sTempNext,sCurDate); AddDates(sTempNext,iInterval);
		sTempDate[8]=0;sTempNext[8]=0;
		
		l+=sprintf(sTxt+l,"\n\
partition PART%s values less than ('%s') tablespace %s,",
			sTempDate,sTempNext,sTablespaceName);
	}
	
	l+=sprintf(sTxt+l,"\n\
partition PART%s values less than (MAXVALUE) tablespace %s\n\
	)\n\
	AS SELECT * FROM PARAM.%s WHERE 1=0;\n",
	sTempNext,sTablespaceName,sTemplateName);

/*生成建索引脚本*/
	strcpy(sEndDate,sBeginDate);
	AddMonths(sEndDate,1);
	AddDates(sEndDate,-1);

	l+=sprintf(sTxt+l,"\n\
CREATE INDEX %s_IND ON %s ( CALLING_NUMBER )LOCAL(",
	sTableName,sTableName);
	
	for(strcpy(sCurDate,sBeginDate);strcmp(sCurDate,sEndDate)<0;
		AddDates(sCurDate,iInterval)){
		
		strcpy(sTempDate,sCurDate);sTempDate[8]=0;
		l+=sprintf(sTxt+l,"\n\
partition PART%s  TABLESPACE %s,",
			sTempDate,sIndexspaceName);
	}
	
	strcpy(sTempDate,sCurDate);sTempDate[8]=0;
	l+=sprintf(sTxt+l,"\n\
partition PART%s  TABLESPACE %s\n);\n",
		sTempDate,sIndexspaceName);
/*生成建索引脚本*/
	strcpy(sEndDate,sBeginDate);
	AddMonths(sEndDate,1);
	AddDates(sEndDate,-1);

	l+=sprintf(sTxt+l,"\n\
CREATE INDEX %s_IND1 ON %s ( GROUP_ID )LOCAL(",
	sTableName,sTableName);
	
	for(strcpy(sCurDate,sBeginDate);strcmp(sCurDate,sEndDate)<0;
		AddDates(sCurDate,iInterval)){
		
		strcpy(sTempDate,sCurDate);sTempDate[8]=0;
		l+=sprintf(sTxt+l,"\n\
partition PART%s  TABLESPACE %s,",
			sTempDate,sIndexspaceName);
	}
	
	strcpy(sTempDate,sCurDate);sTempDate[8]=0;
	l+=sprintf(sTxt+l,"\n\
partition PART%s  TABLESPACE %s\n);\n",
		sTempDate,sIndexspaceName);
/*生成建索引脚本*/
	strcpy(sEndDate,sBeginDate);
	AddMonths(sEndDate,1);
	AddDates(sEndDate,-1);

	l+=sprintf(sTxt+l,"\n\
CREATE INDEX %s_IND2 ON %s ( FILE_NAME )LOCAL(",
	sTableName,sTableName);
	
	for(strcpy(sCurDate,sBeginDate);strcmp(sCurDate,sEndDate)<0;
		AddDates(sCurDate,iInterval)){
		
		strcpy(sTempDate,sCurDate);sTempDate[8]=0;
		l+=sprintf(sTxt+l,"\n\
partition PART%s  TABLESPACE %s,",
			sTempDate,sIndexspaceName);
	}
	
	strcpy(sTempDate,sCurDate);sTempDate[8]=0;
	l+=sprintf(sTxt+l,"\n\
partition PART%s  TABLESPACE %s\n);\n",
		sTempDate,sIndexspaceName);

	sprintf(sFileName,"%s%s.sql",sOutputPath,sTableName);

	if((fp=fopen(sFileName,"w"))==NULL){
		printf("打开输出sql文件 %s 错误.\n",sFileName);
		return -1;
	}
	
	fprintf(fp,"%s",sTxt);
	fclose(fp);
	printf("生成脚本文件 %s　成功.\n",sFileName);
		
	return 0;
}
