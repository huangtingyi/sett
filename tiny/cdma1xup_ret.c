#include <stdio.h>
#include <string.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <wwfile.h>
#include <wwdir.h>
#include <expr_fun.h>

#include "cdma1xup_ret.h"


int main(int argc, char *argv[])
{
	char sSourceFn[256],sDestFn[256],sResult[490];
	char sFileSeq[5],sCreateDate[9],sStartDateTime[15];
	char sEndDateTime[15],sTotRec[11],sTotDru[11],sStatus[7];
	int iErrCode=0;
	struct	FileControlStruct *pList=NULL;
	struct FirstRecd *CTicket=NULL;
	FILE *fp;
	
	if(argc!=3){
		printf("Usage %s source_file dest_file.\n",argv[0]);
		return -1;
	}
	
	strcpy(	sSourceFn, argv[1] );
	strcpy( sDestFn, argv[2] );
	
	/*将输入文件调用函数加载到内存*/
	if( TxtFileToList(sSourceFn,&pList) < 0 ){
		printf("加载文件%s到内存失败.\n",sSourceFn);
		/*文件无法打开*/
		iErrCode=1;
	}	
	
	if ( pList != NULL ){
		if ( pList->iLen != 488 )
			iErrCode = 200;
	}
	
	bzero(sResult,490);
	
	if ( iErrCode != 0 ){		
		sprintf(sResult,"01038000000%066d%-411s\n",0," ");
	}
	
	if ( iErrCode == 0 ){
		CTicket = (struct FirstRecd *)pList->pData;
		strncpy( sFileSeq, CTicket->file_seq, 4);
		sFileSeq[4] = '\0';
		strncpy( sCreateDate, CTicket->created_date, 8);
		sCreateDate[8] = '\0';		
		
		/*日期时间共14位*/
		strncpy( sStartDateTime, CTicket->first_call_date, 14);
		sStartDateTime[14] = '\0';
		strncpy( sEndDateTime, CTicket->end_call_date, 14);
		sEndDateTime[14] = '\0';
		strncpy(sTotRec, CTicket->all_records, 10);
		sTotRec[10] = '\0';
		strncpy( sTotDru, CTicket->all_durations, 10);
		sTotDru[10] = '\0';	
		
		sprintf(sResult,"01038%-4s00%-8s%-14s%-14s%-10s%-10s%-10s%-411s\n",
			sFileSeq,sCreateDate,sStartDateTime,
			sEndDateTime,sTotRec,sTotRec,sTotDru," ");
	}	
	
	sprintf(sStatus,"::%03d\n",iErrCode);

	fp = fopen( sDestFn, "w" );
	if ( fp == NULL ){
		printf("写文件%s出错!\n",sDestFn );
		return -1;
	}
	
	if(fwrite(sResult,489,1,fp)!=1)
		return -1;
	if(fwrite(sStatus,6,1,fp)!=1)
		return -1;
		
	fclose(fp);

	return 0;
}
