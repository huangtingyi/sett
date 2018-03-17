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
		printf("打开文件%s失败.\n",sInputName);
		perror("fopen");
		return -1;
	}

	if(fread((void*)&FDbfHead,sizeof(struct FDbfHeadStruct),1,fpIn)!=1){
		printf("读取文件%s控制头失败.\n",sInputName);
		return -1;
	}
	if(FDbfHead.cIdentify!=0x03&&
		FDbfHead.cIdentify!=0x30){
		printf("文件%s不是有效的dbf文件.\n",sInputName);
		return -1;
	}
/*获取一些重要的控制信息**/
	lmem2int4b((unsigned char*)FDbfHead.sRecCnt,4,&iRecCnt);
	lmem2int4b((unsigned char*)FDbfHead.sHeadLen,2,&iHeadLen);
	lmem2int4b((unsigned char*)FDbfHead.sRecLen,2,&iRecLen);

	
	i=iHeadLen-sizeof(struct FDbfHeadStruct)-1;
	
	iMaxCol=i/sizeof(struct FDbfFieldStruct);

	if(iMaxCol>=256){
		printf("无效的dbf文件,字段数太多%d.\n",iMaxCol);
		return -1;
	}
	if(iRecLen>=8191){
		printf("无效的dbf文件,记录太长了%d.\n",iRecLen);
		return -1;
	}


	bzero((void*)&(asDbfField[0]),sizeof(struct FDbfFieldStruct)*256);
	
/*将文件头的0x0D也读入*/
	if(fread((void*)&(asDbfField[0]),(i+1),1,fpIn)!=1){
		printf("读文件字段控制信息写到内存失败.\n");
		return -1;
	}
/*写控制文件*/;
	if((fpCtl=fopen(sOutputCtl,"w"))==NULL){
		printf("打开文件%s失败.\n",sOutputCtl);
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
		printf("无效的dbf文件字段控制表结束,%d.\n",i);
		return -1;
	}

/*写文件体了*/
	if((fpOut=fopen(sOutputName,"w"))==NULL){
		printf("打开文件%s失败.\n",sOutputName);
		perror("fopen output");
		return -1;
	}

	while(!feof(fpIn)){
		i=fread((void*)buf,iRecLen,1,fpIn);
		if(feof(fpIn)){
			if(buf[0]!=0x1A)
				printf("非法DBF文件结束,%d.\n",buf[0]);
			break;
		}
		if(i!=1){
			printf("读文件%s失败.\n",sInputName);
			return -1;
		}
		/*如果是被删除的记录就不写文件了*/
		iCnt++;
		if(buf[0]!=' ') continue;
		buf[iRecLen]=0;
		fprintf(fpOut,"%s\n",buf+1);
		if((iCnt%100000)==0)
			printf("成功转换%s文件到%s文件，记录数%d.\n",
				sInputName,sOutputName,iCnt);
	}
	fclose(fpIn);
	fclose(fpOut);
	
	printf("转换%s文件到%s文件成功，记录总数%d.\n",
		sInputName,sOutputName,iCnt);
	return 0;
}
