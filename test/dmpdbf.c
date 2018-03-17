#include <stdio.h>
#include <stdlib.h>
#include <wwfile.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <list.h>
#include <wwcoding.h>
#include <wwdbf.h>

/***
identify 03 foxBase
	 30 Visual FoxPro
**/
int main(int argc,char *argv[])
{
	int i=0,iRecCnt=0,iHeadLen=0,iRecLen=0,iMaxCol=0,iCnt=0;
	FILE *fpIn,*fpOut,*fpCtl;
	char buf[8192];
	char sInputName[256],sOutputName[256],sOutputCtl[256];
	struct FDbfHeadStruct FDbfHead;
	struct FDbfFieldStruct asDbfField[256];

	if(argc!=3){
		printf("Usage %s infile outfile.\n",argv[0]);
		return -1;
	}
	strcpy(sInputName,argv[1]);
	strcpy(sOutputName,argv[2]);
	sprintf(sOutputCtl,"%s.ctl",sOutputName);

	if((fpIn=fopen(sInputName,"r"))==NULL){
		printf("���ļ�%sʧ��.\n",sInputName);
		perror("fopen");
		return -1;
	}

	if(fread((void*)&FDbfHead,sizeof(struct FDbfHeadStruct),1,fpIn)!=1){
		printf("��ȡ�ļ�%s����ͷʧ��.\n",sInputName);
		return -1;
	}
	if(FDbfHead.cIdentify!=0x03&&
		FDbfHead.cIdentify!=0x30){
		printf("�ļ�%s������Ч��dbf�ļ�.\n",sInputName);
		return -1;
	}
/*��ȡһЩ��Ҫ�Ŀ�����Ϣ**/
	lmem2int4b((unsigned char*)FDbfHead.sRecCnt,4,&iRecCnt);
	lmem2int4b((unsigned char*)FDbfHead.sHeadLen,2,&iHeadLen);
	lmem2int4b((unsigned char*)FDbfHead.sRecLen,2,&iRecLen);

	
	i=iHeadLen-sizeof(struct FDbfHeadStruct)-1;
	
	iMaxCol=i/sizeof(struct FDbfFieldStruct);

	if(iMaxCol>=256){
		printf("��Ч��dbf�ļ�,�ֶ���̫��%d.\n",iMaxCol);
		return -1;
	}
	if(iRecLen>=8191){
		printf("��Ч��dbf�ļ�,��¼̫����%d.\n",iRecLen);
		return -1;
	}


	bzero((void*)&(asDbfField[0]),sizeof(struct FDbfFieldStruct)*256);
	
/*���ļ�ͷ��0x0DҲ����*/
	if(fread((void*)&(asDbfField[0]),(i+1),1,fpIn)!=1){
		printf("���ļ��ֶο�����Ϣд���ڴ�ʧ��.\n");
		return -1;
	}
/*д�����ļ�*/;
	if((fpCtl=fopen(sOutputCtl,"w"))==NULL){
		printf("���ļ�%sʧ��.\n",sOutputCtl);
		perror("fopen wctl");
		return -1;
	}
	for(i=0;i<iMaxCol;i++){
		if(asDbfField[i].sFieldName[0]==0x0d) break;
		fprintf(fpCtl,"%s\t%d\n",asDbfField[i].sFieldName,
			asDbfField[i].cFieldLen);
	}
	fclose(fpCtl);
	
	if(asDbfField[i].sFieldName[0]!=0x0d){
		printf("��Ч��dbf�ļ��ֶο��Ʊ����,%d.\n",i);
		return -1;
	}

/*д�ļ�����*/
	if((fpOut=fopen(sOutputName,"w"))==NULL){
		printf("���ļ�%sʧ��.\n",sOutputName);
		perror("fopen output");
		return -1;
	}

	while(!feof(fpIn)){
		i=fread((void*)buf,iRecLen,1,fpIn);
		if(feof(fpIn)){
			if(buf[0]!=0x1A)
				printf("�Ƿ�DBF�ļ�����,%d.\n",buf[0]);
			break;
		}
		if(i!=1){
			printf("���ļ�%sʧ��.\n",sInputName);
			return -1;
		}
		/*����Ǳ�ɾ���ļ�¼�Ͳ�д�ļ���*/
		iCnt++;
		if(buf[0]!=' ') continue;
		buf[iRecLen]=0;
		fprintf(fpOut,"%s\n",buf+1);
		if((iCnt%100000)==0)
			printf("�ɹ�ת��%s�ļ���%s�ļ�����¼��%d.\n",
				sInputName,sOutputName,iCnt);
	}
	fclose(fpIn);
	fclose(fpOut);
	
	printf("ת��%s�ļ���%s�ļ��ɹ�����¼����%d.\n",
		sInputName,sOutputName,iCnt);
	return 0;
}
