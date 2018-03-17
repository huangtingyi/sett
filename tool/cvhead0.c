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

	char sTemp[512],sPreHead[5],sSufixHead[5],sStart[5];
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

			/**����һ�麺��--'��;����'*/
			while(((*pc)&0x80)!=0){
				pc++;pc++;
				if((*pc==' ')||(*pc==0x09)) break;
			}

			/**�����ո�*/
			while((*pc==' ')||(*pc==0x09)) pc++;

			pcPre=pc;
			if((pc=strchr(pc,'H'))==NULL){
				printf("������ļ�ͷû���ļ�ͷH��%d,��%d.\n",
					iLineCnt,(pc-sTemp));
				exit(1);
			}
			if(pc-pcPre!=4&&pc-pcPre!=3){
				printf("������ļ�ͷû���ļ�ͷ��4,3λ��%d,��%d.\n",
					iLineCnt,(pc-sTemp));
				exit(1);
			}

			strncpy(sPreHead,pcPre,pc-pcPre);sPreHead[pc-pcPre]=0;
			iTail=7-(int)(pc-pcPre);
			continue;
		}
/**************�����ļ���********************/
		/**�����ո�*/
		while((*pc==' ')||(*pc==0x09)) pc++;
		pcPre=pc;

		if(isdigit(*pc)) goto next_h1h2h3;

		/**����һ�麺��--'������'*/
		while(((*pc)&0x80)!=0){
			pc++;pc++;
			if((*pc==' ')||(*pc==0x09)) break;
		}
		/**�õ��Ǻ��ֵĶ���**/
		while((*pc!=' ')&&(*pc!=0x09)) pc++;
		
		pcCur=pc;
		if(pcCur-pcPre>=30){
			printf("������ļ�ͷ����������30λ��%d,��%d.\n",
				iLineCnt,(pc-sTemp));
			exit(1);
		}
		strncpy(sTempRemark,pcPre,pcCur-pcPre);
		sTempRemark[pcCur-pcPre]=0;

		/**�����ո�*/
		while((*pc==' ')||(*pc==0x09)) pc++;

		pcPre=pc;
		/**��ȡһ������*/
		while(((*pc)>='0')&&((*pc)<='9')){
			pc++;
			if((*pc==' ')||(*pc==0x09)) break;
		}
		pcCur=pc;
		if((pcCur-pcPre==0)||(pcCur-pcPre>9)){
			printf("����̫��9��%d,��%d.\n",iLineCnt,(pc-sTemp));
			exit(1);
		}
		strncpy(sTempAreaCode,pcPre,pcCur-pcPre);
		sTempAreaCode[pcCur-pcPre]=0;

		/**�����ո�*/
		while((*pc==' ')||(*pc==0x09)) pc++;
		
		pcPre=pc;
next_h1h2h3:
/******�����ȡһ����H1H2H3****/
		do{
			while((*pc==' ')||(*pc==0x09)) pc++;

			if((*pc)=='\0'||(*pc)=='\n'||(*pc)=='\r') break;

			if(((*pc)>'9')||((*pc)<'0')){
				printf("�Ƿ��ַ���%d,��%d.\n",
					iLineCnt,(pc-sTemp));
				exit(1);
			}
			strncpy(sSufixHead,pc,iTail);
			sSufixHead[iTail]=0;
			pc+=iTail;
			
			for(i=0;i<iTail;i++){
				if(!isdigit(sSufixHead[i])) {
					printf("�Ƿ�H1H2H3��%d,��%d.\n",
						iLineCnt,(pc-sTemp));
					exit(1);
				}
			}
			iCnt++;
			fprintf(fpOut,"%16s\t%s\t%s%s\n",
				sTempRemark,sTempAreaCode,sPreHead,sSufixHead);
			
			/**�����ո�*/
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

			if(strncmp(pc,"-",1)!=0&&
				strncmp(pc,"��",2)!=0){
				printf("ϵͳ��֧�ַ�,��-���ķָ����%d,��%d.\n",
					iLineCnt,(pc-sTemp));
				exit(1);
			}

			/*����ֻ��-��*/
			if(*pc=='-') pc++;/**����-**/
			else pc+=2;

			/**�����ո�*/
			while((*pc==' ')||(*pc==0x09)) pc++;
			strcpy(sStart,sSufixHead);

			if(((*pc)>'9')||((*pc)<'0')){
				printf("�Ƿ��ַ���%d,��%d.\n",
					iLineCnt,(pc-sTemp));
				exit(1);
			}
			strncpy(sSufixHead,pc,iTail);
			sSufixHead[iTail]=0;
			pc+=iTail;
			for(i=0;i<iTail;i++){
				if(!isdigit(sSufixHead[i])) {
					printf("�Ƿ�H1H2H3��%d,��%d.\n",
						iLineCnt,(pc-sTemp));
					exit(1);
				}
			}
			
			for(j=atoi(sStart)+1;j<=atoi(sSufixHead);j++){
				iCnt++;
				fprintf(fpOut,"%16s\t%s\t%s%d\n",
					sTempRemark,sTempAreaCode,sPreHead,j);
			}

			/**�����ո�*/
			while((*pc==' ')||(*pc==0x09)) pc++;

			if((*pc)=='\0'||(*pc)=='\n'||(*pc)=='\r') break;
	
			if(isdigit(*pc)) continue;

			if(strncmp(pc,"��",2)==0||strncmp(pc,"��",2)==0){
				pc+=2;
				continue;
			}
			if(strncmp(pc,",",1)!=0){
				printf("�Ƿ��ַ���%d,��%d.\n",iLineCnt,
					(pc-sTemp));
				exit(1);
			}
			pc++;

		}while(1);
	}
	printf("ת��%sΪ%s,ת��%d��,����%d��¼.\n",argv[1],argv[2],iLineCnt,iCnt);
	fclose(fpIn);
	fclose(fpOut);
	
	return 0;
}

