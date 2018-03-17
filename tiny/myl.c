#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <wwfile.h>
#include <wwtiny.h>

/*单个结构申明*/
struct TelecomTicketStruct{

        struct TelecomTicketStruct *pNext;
        char    sCallingAreaCode[10];
        char    sCallingNbr[25];
        char    sCalledAreaCode[10];
        char    sCalledNbr[25];
        char    sStartTime[15];
        int     iDuration;
        int     iCharge;
        int     iTalkTypeID;
        char    sOCallingNbr[25];
        char    sOCalledNbr[25];
        char    sTrunkIn[8];
        char    sTrunkOut[8];
        struct TelecomTicketStruct *pLoadNext;
};
void RecordToTelecomTicket(char buf[],struct TelecomTicketStruct *p)
{
        char sCallingAreaCode[110],sCallingNbr[125],sCalledAreaCode[110],
        	sCalledNbr[125],sStartTime[125],sDuration[17],sCharge[17],
        	sTalkTypeID[15],sOCallingNbr[125],sOCalledNbr[125],
        	sTrunkIn[18],sTrunkOut[18],sTemp[1024];
        
         SearchOffString(buf,2,'\t',sTemp);
         strcpy(sTrunkIn,sTemp);
         SearchOffString(buf,3,'\t',sTemp);
         strcpy(sTrunkOut,sTemp);
         SearchOffString(buf,4,'\t',sTemp);
         strcpy(sCallingAreaCode,sTemp);
         SearchOffString(buf,5,'\t',sTemp);
         strcpy(sCallingNbr,sTemp);
         SearchOffString(buf,6,'\t',sTemp);
         strcpy(sCalledAreaCode,sTemp);
         SearchOffString(buf,7,'\t',sTemp);
         strcpy(sCalledNbr,sTemp);
         SearchOffString(buf,8,'\t',sTemp);
         strcpy(sStartTime,sTemp);
         SearchOffString(buf,9,'\t',sTemp);
         strcpy(sDuration,sTemp);
         SearchOffString(buf,11,'\t',sTemp);
         strcpy(sCharge,sTemp);
         SearchOffString(buf,13,'\t',sTemp);
         strcpy(sTalkTypeID,sTemp);
         SearchOffString(buf,18,'\t',sTemp);
         strcpy(sOCallingNbr,sTemp);
         SearchOffString(buf,19,'\t',sTemp);
         strcpy(sOCalledNbr,sTemp);
         
         
         
         bzero((void*)p,sizeof(struct TelecomTicketStruct));
         
	strcpy(p->sCallingAreaCode,	sCallingAreaCode);
	strcpy(p->sCallingNbr,		sCallingNbr);
	strcpy(p->sCalledAreaCode,	sCalledAreaCode);
	strcpy(p->sCalledNbr,		sCalledNbr);

/*	strcpy(p->sStartTime,		sStartTime);*/
/*	formatdatetime_long_simp(sStartTime,p->sStartTime);
*/
	{
		char *pPre,*pCur;
		int iYear,iMonth,iDate,iHour,iMin,iSec;
		pCur=pPre=sStartTime;

		while(*pCur!=0&&isdigit(*pCur)) pCur++;
		if(*pCur==0){ goto end_conv;}*pCur=0;pCur++;
		iYear=atoi(pPre);pPre=pCur;
	
		while(*pCur!=0&&isdigit(*pCur)) pCur++;
		if(*pCur==0){ goto end_conv;}*pCur=0;pCur++;
		iMonth=atoi(pPre);pPre=pCur;

		while(*pCur!=0&&isdigit(*pCur)) pCur++;
		if(*pCur==0){ goto end_conv;}*pCur=0;pCur++;
		iDate=atoi(pPre);pPre=pCur;

		while(*pCur!=0&&isdigit(*pCur)) pCur++;
		if(*pCur==0){ goto end_conv;}*pCur=0;pCur++;
		iHour=atoi(pPre);pPre=pCur;

		while(*pCur!=0&&isdigit(*pCur)) pCur++;
		if(*pCur==0){ goto end_conv;}*pCur=0;pCur++;
		iMin=atoi(pPre);pPre=pCur;

		while(*pCur!=0&&isdigit(*pCur)) pCur++;
		*pCur=0;pCur++;
		iSec=atoi(pPre);pPre=pCur;

		sprintf(p->sStartTime,"%04d%02d%02d%02d%02d%02d",
			iYear,iMonth,iDate,iHour,iMin,iSec);
end_conv:	
		pCur=NULL;
	}

	p->iDuration=			atoi(sDuration);
	p->iCharge=			atoi(sCharge);
	p->iTalkTypeID=			atoi(sTalkTypeID);

	strcpy(p->sOCallingNbr,		sOCallingNbr);
	strcpy(p->sOCalledNbr,		sOCalledNbr);
	strcpy(p->sTrunkIn,		sTrunkIn);
	strcpy(p->sTrunkOut,		sTrunkOut);
	                
		
}
int main(int argc,char *argv[])
{
        FILE *fpIn,*fpOut;
        
	char sSourceName[40],sTargetName[40],buf[1024];
	int iCount=0,iFirstFlag=1;
        struct TelecomTicketStruct Temp;


	if(argc!=3){
		printf("用法 : %s sourcename targetname.\n",argv[0]);
		exit(1);
	}
	strcpy(sSourceName,argv[1]);
	strcpy(sTargetName,argv[2]);
	
        if((fpIn=fopen(sSourceName,"r"))==NULL){
        	printf("打开文件%s失败.\n",sSourceName);
        	exit(1);
	}
        if((fpOut=fopen(sTargetName,"w"))==NULL){
        	printf("打开文件%s失败.\n",sTargetName);
        	exit(1);
	}

        while(!feof(fpIn)){
                fgets(buf,1024,fpIn);
                if(feof(fpIn)) break;
                
                if(iFirstFlag){ iFirstFlag=0; continue;}
                
                RecordToTelecomTicket(buf,&Temp);
                Temp.sOCallingNbr[15]=0;
		fprintf(fpOut,"%-15s%-24s%-14s%06d%04d%-12s%-15s%-7s%-7s\n",
			Temp.sOCallingNbr,Temp.sOCalledNbr,Temp.sStartTime,
			Temp.iDuration,Temp.iTalkTypeID," "," ",
			Temp.sTrunkIn,Temp.sTrunkOut);
		iCount++;

	}
	fclose(fpOut);
        fclose(fpIn);
        
        printf("处理完毕，总记录数%d.\n",iCount);
        
        return 0;
}
