#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <hnixs.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwfile.h>



int main(int argc,char *argv[])
{
	int iCnt=0,iRecCnt=0,iSepCnt=0,i=0,iBgnHead,iEndHead,iHeadLen;
	char sSourceName[256],sTargetName[256],sInput[8192],sNetType[11],sTemp[21];
	char sAreaCode[41],sHeadStr[2048],sCarrierName[81],sName[81],sHead[21];
	char sTariff1[21],sTariff2[21],sTariff3[21],sTariff4[21],sTariff5[21];
	char sCmdIn[1024],sNewCmd[1024],sTariff[21];

	struct FileControlStruct *ptHead=NULL,*ptLkHead=NULL,*pTemp;
	
        if(argc!=3){
                printf("Usage: cvhead sourcename targetname.\n");
                exit(1);
        }

	strcpy(sCmdIn,"INSERT INTO INTERNATIONAL_SETT_TARIFF (AREA_CODE,HEAD,CARRIER_NAME,NAME,NET_TYPE,RATE) VALUES ('$AREA_CODE','$HEAD','$CARRIER_NAME','$NAME','$NET_TYPE','$RATE');");

	strcpy(sSourceName,argv[1]);
	strcpy(sTargetName,argv[2]);
	
	if(TxtFileToList(sSourceName,&ptLkHead)<0){
		printf("文件%s加载到内存错误.\n",sSourceName);
		return -1;
	}

	ptHead=ptLkHead;
	while(ptHead!=NULL){

		iRecCnt++;
		iCnt++;

		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		if(pTemp->iLen>sizeof(sInput)){
			printf("第%d条记录超长，大于%d字节,为%d.\n",
				iRecCnt,sizeof(sInput),pTemp->iLen);
			return -1;
		}
		
		strncpy(sInput,(char*)pTemp->pData,pTemp->iLen);
		sInput[pTemp->iLen]=0;
		
		GetSepStrX(sInput,'\t',0,40,sAreaCode);
		GetSepStrX(sInput,'\t',1,2000,sHeadStr);
		GetSepStrX(sInput,'\t',2,80,sCarrierName);
		GetSepStrX(sInput,'\t',3,80,sName);
		GetSepStrX(sInput,'\t',4,10,sNetType);
		GetSepStrX(sInput,'\t',5,20,sTariff1);
		GetSepStrX(sInput,'\t',6,20,sTariff2);
		GetSepStrX(sInput,'\t',7,20,sTariff3);
		GetSepStrX(sInput,'\t',8,20,sTariff4);
		GetSepStrX(sInput,'\t',9,20,sTariff5);
		
		/*printf("%s:%s=%s=%s=%s=%s.\n",sInput,sTariff1,sTariff2,sTariff3,sTariff4,sTariff5);*/
		sprintf(sTariff,"%f",atof(sTariff1)*100+0.5);
/*		printf("%s.\n",sTariff);*/
		sprintf(sTariff,"%d",atoi(sTariff));

/*		if(strlen(sHeadStr)>0){
			printf("hello.\n");
		}
		
		if(strcmp("Botswana",sCarrierName)==0){
			printf("hello2.\n");
		}
*/
		
		ReplaceStr(sCarrierName,"&"," and ");
		ReplaceStr(sName,"&"," and ");
		
		ReplaceStr(sHeadStr," ","");
		ReplaceStr(sHeadStr,"、",",");
		ReplaceStr(sHeadStr,"，",",");
		ReplaceStr(sHeadStr,";",",");
		ReplaceStr(sHeadStr,"；",",");
		ReplaceStr(sHeadStr,"－","-");
		ReplaceStr(sHeadStr,"～","-");
		ReplaceStr(sHeadStr,"\"","");
		
/*		ReplaceStr(sAreaCode,"；",",");*/
		
		if(strstr(sNetType,"固定")!=0) strcpy(sNetType,"0");
		if(strstr(sNetType,"移动")!=0) strcpy(sNetType,"1");
		
		if(strlen(sNetType)>1){
			printf("nettype error = %s.\n",sNetType);
			return -1;
		}

		iSepCnt=GetSepCnt(sHeadStr,',');
		i=0;

		while(i<iSepCnt||
			(i==0&&iSepCnt==0)){

			GetSepStrX(sHeadStr,',',i,20,sHead);
			i++;

			if(strstr(sHead,"-")!=NULL){

/*				printf("the head=%s ::",sHead);*/
      printf("hello1");
				
				GetSepStrX(sHead,'-',0,20,sTemp);
				iBgnHead=atoi(sTemp);
				
				/*起始和sAreaCode相关的要检查*/
				if(strcmp(sAreaCode,sTemp)==0){
					printf("AreaCode=%s,BgnHead=%s无效.\n",
						sAreaCode,sTemp);
					return -1;
				}
				iHeadLen=strlen(sTemp);
      printf("hello2");				
				GetSepStrX(sHead,'-',1,20,sTemp);
				iEndHead=atoi(sTemp);
				
				if(iHeadLen!=strlen(sTemp)){
					printf("%s无效.\n",sHead);
					return -1;
				}
				for(i=iBgnHead;i<=iEndHead;i++){
      printf("hello3");					
					sprintf(sTemp,"%d",i);
					LeftPad(sTemp,iHeadLen,'0');
/*
				printf("%-9s%-11s%-40s%-40s%-10s%-10s%-10s%-10s%-10s%-10s\n",
					sAreaCode,sTemp,sCarrierName,sName,sNetType,
					sTariff1,sTariff2,sTariff3,sTariff4,sTariff5);					
					if(i<iEndHead)	strcat(sTemp,",");
					else		strcat(sTemp,"\n");

					printf("%s",sTemp);
*/				
					strcpy(sNewCmd,sCmdIn);
				strcpy(sNewCmd,sCmdIn);
				ReplaceStr(sNewCmd,"$AREA_CODE",sAreaCode);
				ReplaceStr(sNewCmd,"$HEAD",	sTemp);
				ReplaceStr(sNewCmd,"$CARRIER_NAME",sCarrierName);
				ReplaceStr(sNewCmd,"$NAME",	sName);
				ReplaceStr(sNewCmd,"$NET_TYPE",	sNetType);
				ReplaceStr(sNewCmd,"$RATE",	sTariff);
					printf("%s\n",sNewCmd);
					
				}
			}
			else{
/*				printf("%-9s%-11s%-40s%-40s%-10s%-10s%-10s%-10s%-10s%-10s\n",
					sAreaCode,sHead,sCarrierName,sName,sNetType,
					sTariff1,sTariff2,sTariff3,sTariff4,sTariff5);
				"INSERT INTO INTERNATIONAL_SETT_TARIFF (AREA_CODE,HEAD,CARRIER_NAME,NAME,NET_TYPE,RATE) VALUES ('$AREA_CODE','$HEAD','$CARRIER_NAME','$NAME','$NET_TYPE','$RATE');
*/

				if(iSepCnt>1&&strlen(sHead)==0) continue;

				strcpy(sNewCmd,sCmdIn);
				ReplaceStr(sNewCmd,"$AREA_CODE",sAreaCode);
				ReplaceStr(sNewCmd,"$HEAD",	sHead);
				ReplaceStr(sNewCmd,"$CARRIER_NAME",sCarrierName);
				ReplaceStr(sNewCmd,"$NAME",	sName);
				ReplaceStr(sNewCmd,"$NET_TYPE",	sNetType);
				ReplaceStr(sNewCmd,"$RATE",	sTariff);
			
					printf("%s\n",sNewCmd);
	
			}

		}

/*		if(strlen(sHeadStr)>0)
			printf("%s,\t%s.\n",sCarrierName,sHeadStr);
*/
		if(!IsAllDigit(sAreaCode))
			printf("the areacode=%s.\n",sAreaCode);
	}
		
/*	printf("将文件%s转换为%s文件成功,生成%d条纪录.\n",
		sSourceName,sTargetName,iCnt);
*/
	return 0;
}

