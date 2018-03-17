#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wwtiny.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE 
#define FALSE 0
#endif


int main(int argc,char *argv[])
{
	char sTempRemark[30],sTempAreaCode[10];

	char sTemp[512],sPreHead[5],sSufixHead[5],sAreaCode[5],sStart[5];
	char *pc,*pcPre,*pcCur;
	int iFirstFlag=TRUE,iLineCnt=0,iCnt=0,i=0,j=0,iTail=0;
	FILE *fpIn,*fpOut;

        if(argc!=3){
                printf("Usage: cvhead sourceName targetName.\n");
                exit(1);
        }
	if((fpIn=fopen(argv[1],"rb"))==NULL){
		printf("error open %s.\n",argv[1]);
		exit(1);
	}
	if((fpOut=fopen(argv[2],"w"))==NULL){
		printf("error open %s.\n",argv[2]);
		exit(1);
	}
	while(!feof(fpIn)){
		
		sTemp[0]=0; 
		fgets(sTemp,512,fpIn);
		
		pc=&sTemp[0];
		i=0,j=0;
		iLineCnt++;

/**************�����ļ�ͷ********************/
		if(iFirstFlag==TRUE){
			iFirstFlag=FALSE;
			pcPre=pc;
			/**����һ�麺��--'����'*/
			while(((*pc)&0x80)!=0){
				pc++;pc++;
				if((*pc)==' '||(*pc==0x09)) break;
			}

			/**�����ո�*/
			while((*pc==' ')||(*pc==0x09)) pc++;

			pcPre=pc;
			if((pc=strchr(pc,'H'))==NULL){
				/*printf("������ļ�ͷû���ļ�ͷH��%d,��%ld.\n",iLineCnt,(pc-sTemp));*/
				exit(1);
			}

			strncpy(sPreHead,pcPre,pc-pcPre);
			sPreHead[pc-pcPre]=0;
			iTail=7-(int)(pc-pcPre);
			continue;
		}
		while((*pc==' ')||(*pc==0x09)) pc++;
		pcPre=pc;

		while(((*pc)&0x80)!=0){
			pc++;pc++;
			if((*pc)==' '||(*pc==0x09)) break;
		}

		while((*pc==' ')||(*pc==0x09)) pc++;
		
		while(((*pc)&0x80)!=0){
			pc++;pc++;
			if((*pc)==' '||(*pc==0x09)) break;
		}
		while((*pc==' ')||(*pc==0x09)) pc++;
		
		if((*pc)=='\0'||(*pc)=='\n'||(*pc)=='\r') continue;
		
		strncpy(sTempRemark,pcPre,pc-pcPre);
		sTempRemark[pc-pcPre]=0;
		TrimAll(sTempRemark);
		strncpy(sAreaCode,pc,4);
		TrimAll(sAreaCode);
		pc+=4;
		printf("sAreaCode=%s\n",sAreaCode);
		
		while((*pc==' ')||(*pc==0x09)) pc++;
		
		if(isdigit(*pc)) goto next_h1h2h3;
		

next_h1h2h3:
/******�����ȡһ����H1H2H3****/
		do{
			while((*pc==' ')||(*pc==0x09)) pc++;
				
			while(((*pc)&0x80)!=0){
				pc++;pc++;
				if((*pc)==' '||(*pc==0x09)) break;
			}

			if((*pc)=='\0'||(*pc)=='\n'||(*pc)=='\r') break;
        			
			if(strncmp(pc,"��",2)==0||strncmp(pc,"��",2)==0){
				pc+=2;
			}
			if(strncmp(pc,",",1)==0){
				pc++;
			}
			/*if(strncmp(pc,"-",1)!=0&&strncmp(pc,"��",2)!=0){
				printf("ϵͳ��֧�ַ�,��-���ķָ����%d,��%ld.\n",iLineCnt,(pc-sTemp));
				exit(1);
			}
        		*/
			/*����ֻ��-��*/
			if(*pc=='-') pc++;/**����-**/
			if(strncmp(pc,"��",2)==0) pc+=2;
				
			while((*pc==' ')||(*pc==0x09)) pc++;
				
			if(((*pc)>'9')||((*pc)<'0')){
				printf("�Ƿ��ַ���%d,��%ld.\n",iLineCnt,(pc-sTemp));
				exit(1);
			}
				
			strncpy(sSufixHead,pc,iTail);
			sSufixHead[iTail]=0;
			TrimAll(sSufixHead);
			pc+=iTail;				
        			
			for(i=0;i<iTail;i++) if(!isdigit(sSufixHead[i])) {
				printf("�Ƿ�H1H2H3��%d,��%ld.\n",iLineCnt,(pc-sTemp));
				exit(1);
			}
			
			iCnt++;
			printf ("sAreaCode=%s\n",sAreaCode);
			printf ("\n");
			printf ("sTempRemark=%16s,sAreaCode=%s,sPreHead=%s,sSufixHead=%s\n",sTempRemark,
				sAreaCode,sPreHead,sSufixHead);
			fprintf(fpOut,"%16s\t%s\t%s%s\n",sTempRemark,sAreaCode,sPreHead,sSufixHead);
				
			/*strncpy(sSufixHead,pc,iTail);
			sSufixHead[iTail]=0;
			pc+=iTail;*/
				
			while((*pc==' ')||(*pc==0x09)) pc++;
				
			if((*pc)=='\0'||(*pc)=='\n'||(*pc)=='\r') break;
				
			if(strncmp(pc,"��",2)==0||strncmp(pc,"��",2)==0){
				pc+=2;
				continue;
			}
			if(strncmp(pc,",",1)==0){
				pc++;
				continue;
			}
			if(isdigit(*pc)) continue;
				
			if(*pc=='-') pc++;/**����-**/
			if(strncmp(pc,"��",2)==0) pc+=2;
			
			while((*pc==' ')||(*pc==0x09)) pc++;
				
			strcpy(sStart,sSufixHead);
				
			if(((*pc)>'9')||((*pc)<'0')){
				printf("�Ƿ��ַ���%d,��%ld.\n",iLineCnt,(pc-sTemp));
				exit(1);
			}
				
			strncpy(sSufixHead,pc,iTail);
			sSufixHead[iTail]=0;
			pc+=iTail;
				
			for(i=0;i<iTail;i++) if(!isdigit(sSufixHead[i])) {
				printf("�Ƿ�H1H2H3��%d,��%ld.\n",iLineCnt,(pc-sTemp));
				exit(1);
			}
			
			for(j=atoi(sStart)+1;j<=atoi(sSufixHead);j++){
				iCnt++;
				fprintf(fpOut,"%16s\t%s\t%s%d\n",sTempRemark,sAreaCode,sPreHead,j);
			}
			while((*pc==' ')||(*pc==0x09)) pc++;
			
			if((*pc)=='\0'||(*pc)=='\n'||(*pc)=='\r') break;
	
			if(isdigit(*pc)) continue;

			if(strncmp(pc,"��",2)==0||strncmp(pc,"��",2)==0){
				pc+=2;
				continue;
			}
			if(strncmp(pc,",",1)==0){
				pc++;
				continue;
			}
			pc++;
		}while(1);
	}
	printf("ת��%sΪ%s,ת��%d��,����%d��¼.\n",
		argv[1],argv[2],iLineCnt,iCnt);
	fclose(fpIn);
	fclose(fpOut);
	
	return 0;
}

