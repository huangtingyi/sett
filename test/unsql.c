#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <wwfile.h>
#include <wwcoding.h>
#include <wwdb.h>

int PrintDs2ScriptFile(struct DataSetStruct *pDs,
	char sTableName[],char sFileName[])
{
	int i,l=0,n,n1;
	char *p;
	char statement[256*1024],sTemp[1024],sTiny[2];
	struct RowStruct *ptHead,*pTemp;
	struct FileControlStruct *pList=NULL;
	
	l=sprintf(sTemp,"INSERT INTO %s (",sTableName);
	for(i=0;i<pDs->iColNum;i++){
		if(i==0)	l+=sprintf(sTemp+l,"%s",pDs->asFieldName[i]);
		else		l+=sprintf(sTemp+l,",%s",pDs->asFieldName[i]);
	}
	l+=sprintf(sTemp+l,") VALUES (");
	
		
	ptHead=pDs->pRow;
	while(ptHead!=NULL){
	
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		
		
		l=sprintf(statement,"%s",sTemp);
		for(i=0;i<pTemp->iColNum;i++){
			
			if(i==0)strcpy(sTiny,"");
			else	strcpy(sTiny,",");
			
			p=pTemp->apIndex[i];
			if(p==NULL){
				l+=sprintf(statement+l,"%snull",sTiny);
				continue;
			}

			n1=DecodeLenItem((unsigned char*)p,&n);
			p+=n1;
			
			switch(pDs->acFieldType[i]){
	
			case VALUE_TYPE_INT:
			case VALUE_TYPE_FLOAT:
			l+=sprintf(statement+l,"%s%s",sTiny,p);
			break;
			case VALUE_TYPE_DATE:
			l+=sprintf(statement+l,
				"%sto_date('%s','yyyymmddhh24miss')",sTiny,p);
			break;
			case VALUE_TYPE_STR:
			default:
			l+=sprintf(statement+l,"%s'%s'",sTiny,p);
			break;
			}
		}
		l+=sprintf(statement+l,");");
		if(item2list(&pList,(void*)statement,l)<0){
			printf("生成数据%s表的链表失败.\n",sTableName);
			return -1;
		}
		/*printf("%s\n",statement);*/
	}
	ReverseList((LIST**)&pList);
	
	if(list2fileln(&pList,sFileName)<0){
		printf("生成文件%s失败.\n",sFileName);
		return -1;
	}
/*	PrintDs(pDs);*/
	return 0;
}
int TestHp()
{
	char sTemp[1024];
	struct FileControlStruct *ptHead=NULL;
	struct PositionStruct Temp,*p;

	strcpy(sTemp,"find /zhjs2/work/pick/stt/HDGG01/ -name \"*.dat\" | sed s,/zhjs2/work/pick/stt/HDGG01/,,");
	exec2list(sTemp,&ptHead);
	Temp.pData=NULL;
	Temp.iOffset=0;
	Temp.iLen=2;
	p=(struct PositionStruct*)(char*)malloc(sizeof(struct PositionStruct))+1;
	
	p->iOffset=Temp.iOffset;
	return 0;

}
int main(int argc,char *argv[])
{
	int iMaxCnt=-1;
	char statement[1024];
	char sMessage[256],sConnStr[128],sTableName[128],sFileName[128];
	
	struct DataSetStruct TempDs;
/*	
	TestHp(); return 0;
*/	
	if(argc!=4&&argc!=5){
		printf("Usage %s connstr table file [maxcnt].\n",argv[0]);
		return -1;
	}
	
	strcpy(sConnStr,argv[1]);
	strcpy(sTableName,argv[2]);
	strcpy(sFileName,argv[3]);
	if(argc==5)	iMaxCnt=atoi(argv[4]);
	else		iMaxCnt=-1;
	

	if(FastConnect(sConnStr)<0){
		printf("连结数据库%s错误.\n",sConnStr);
		return -1;
	}

	sprintf(statement,"SELECT * FROM %s",sTableName);
	
	if(InitStmtDs(statement,&TempDs,iMaxCnt,sMessage)<0){
		printf("读取表%s,%d记录数错误,错误原因%s.\n",
			sTableName,iMaxCnt,sMessage);
		DisconnectDatabase();
		return -1;
	}

	if(PrintDs2ScriptFile(&TempDs,sTableName,sFileName)<0){
		printf("将表%s,%d记录数输出到脚本文件%s失败.\n",
			sTableName,iMaxCnt,sFileName);
		DestroyDataSetRow(&TempDs);
		DisconnectDatabase();
		return -1;
	}
	printf("将表%s,%d记录数输出到脚本文件%s成功.\n",
		sTableName,iMaxCnt,sFileName);

	DestroyDataSetRow(&TempDs);
	DisconnectDatabase();
	
	return 0;
}
