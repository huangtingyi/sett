#include <stdio.h>
#include <stdlib.h>
#include <wwlog.h>
#include <wwtiny.h>
#include <wwdir.h>
#include <list.h>
#include <expr.h>
#include <expr_var.h>
#include <expr_fun.h>
#include <wwsupp.h>
#include <wwdb.h>

#include <ticket_field.h>
#include <tariff_disct.h>
#include <ticket.h>
#include <stt_ticket.h>

#include <fileout.h>

struct TinyRollLogStruct *pSumLog=NULL;

int main(int argc, char **argv)
{
	int i,l,iRet,iErrCnt=0,iWantUpdate=false,iTicketValid=0;
	int iNormalCnt=0,iAbnormalCnt=0,iCnt=0,iOriLen=0,iLen=0;
	
	char sTableName[32],sCondition[128];
	char	msg[2048],sType[5],sTargetName[256];
	char  sMsc[16],sInput[EXPRLEN],sModule[4],sSplitNew[21];
	char  sBaseName[128],sDateTime[15],sNormalPath[128];
	char  sExprName[128],sUserType[10],sAreaCode[10];
	char  sOri[4096],sSourceID[7],sFileType[7],sNow[15];
	char  sTemp[64],sSuffixStr[20],sFileName[256],sMsg[1024];

	struct OutputExprStruct asVarOutput[SYSVAR_COUNT];
	
	struct FileControlStruct *pAbnormal=NULL;
	struct FileControlOutStruct *pNormal=NULL;

	struct UCommTicketStruct TempUTicket;
	struct UCommTicketStructUp TempUp;
	
	struct ErrTicketStructIn TempIn;
	struct ErrTicketStruct Temp;

	if(argc!=13){
		printf("Usage %s tablename wherecause type[E] exprfile \
MSC usertype visitcode module source filetype targetname update(def=0).\n",argv[0]);
		return -1;
	}
	
	InitAppRes(argv[0]);
	
	strcpy(sTableName,argv[1]);
	strcpy(sCondition,argv[2]);
	strncpy(sType,argv[3],4);sType[4]=0;AllTrim(sType);
	strcpy(sExprName,argv[4]);
	strcpy(sMsc,argv[5]);
	strcpy(sUserType,argv[6]);
	strcpy(sAreaCode,argv[7]);
	strncpy(sModule,argv[8],3);sModule[3]=0;
	strncpy(sSourceID,argv[9],6);sSourceID[6]=0;
	strncpy(sFileType,argv[10],5);sFileType[5]=0;
	
	strcpy(sTargetName,argv[11]);

	if((iWantUpdate=atoi(argv[12]))!=0) iWantUpdate=1;
	
	strcpy(sSplitNew,"");

	RegularDir(sNormalPath);

/*做一个类型的校验*/
	if(strcmp(sType,"E")!=0){
		printf("系统仅支持E类型格式输入.\n");
		return -1;
	}

/*初始化批价参数*/
	MoveAllShmToMem();
	
/*将公式读到内存*/
	if(MyReadExprFileToBuf(sExprName,EXPRLEN,
		sInput,msg)!=0){
		WriteAlertPrint("读文件%s失败:%s",sExprName,msg);
		return -1;
	}
/*加载编译公式函数及参数*/	
	RegPrepVar();
	RegRateExprFun();
	CheckSysVar=CheckPrepVar;
/*编译公式*/
	if((i=CompileExpr(sInput,asVarOutput,&l))<0){
		printf("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		WriteAlertMsg("编译公式%s错误::\n%s\n",
			sExprName,pExprBuf->sErrorMsg);
		return -1;
	}
/**连接数据库***/
	if(ConnectDataDB()<0) return -1;
	
	/*更新*/
	bzero((void*)&TempUp,sizeof(struct UCommTicketStructUp));
	strcpy(TempUp.sTableName,sTableName);
	
	GetHostTime(sDateTime);

	/*计算文件名*/
	strcpy(TempUTicket.sModule,sModule);
	strcpy(TempUTicket.sAreaCode,sAreaCode);
	strcpy(TempUTicket.sState,"1");
	strcpy(TempUTicket.sUpdateDate,sDateTime);
	GetBaseNameX(sTargetName,sBaseName);
	strncpy(TempUTicket.sFileName,sBaseName,19);
	TempUTicket.sFileName[19]=0;
	
	bzero((void*)&Temp,sizeof(struct ErrTicketStruct));
	bzero((void*)&TempIn,sizeof(struct ErrTicketStructIn));
	
	strcpy(TempIn.sTableName,sTableName);
	strcpy(TempIn.sCondition,sCondition);
	TempIn.iFirstFlag =TRUE;
	TempIn.iBufEmpty =TRUE;
		
	 while(EGetErrTicketToStruct(&Temp,&TempIn)){
		/*打印程序处理进程*/
		if((++iCnt)%10000==0){

			WriteProcMsg("对表%s出文件,处理数%d,其中异常数%d,输出数%d",
				sTableName,iCnt,iAbnormalCnt,iNormalCnt);

			if(iWantUpdate==1){
				if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
					WriteAlertMsg("表%s更新数据错误.",TempUp.sTableName);
					return -1;
				}
			}
		}

		if(ResetErr2Ori(Temp.sRecordType,Temp.sErrRec,sOri,&iOriLen)<0){
			WriteAlertPrint("恢复错单文件到原始格式失败，表%s",sTableName);
			return -1;
		}
				
		/**加载原始话单到指定的原始话单结构字段，设置原始话单长度*/
		iLen=MY_MIN(iOriLen,sizeof(TICKET.sOri)-1);
		TICKET.iOriLen=	iLen;
		TICKET.sOri[iLen]=0;
		
		memcpy((void*)(TICKET.sOri),sOri,iLen);
		
		/**复位话单结构的当前输出链表{unlink pCur链表}*/
		ResetTicket();
		set_str_value("$FILENAME",pExprBuf,sSourceID);
		set_str_value("$FILEINFO",pExprBuf,sBaseName);
		GetHostTime(sNow);	
		set_str_value("$NOW",pExprBuf,sNow);
		set_str_value("$MSC",pExprBuf,sMsc);
		set_str_value("$AREACODE",pExprBuf,sAreaCode);
		set_str_value("$USERTYPE",pExprBuf,sUserType);
		set_str_value("$MODULE",pExprBuf,sModule);
		set_str_value("$FILETYPE",pExprBuf,sFileType);
		
		/*执行公式{这里可以获得pCur链表，link}*/
		if((iRet=ExecCode(pExprBuf))<0){
			printf("执行公式%s失败.\n",sExprName);
			return -1;
		}
		get_int_value("ticketvalid",pExprBuf,&iTicketValid);
		get_str_value("$SUFFIXSTR",pExprBuf,sTemp);
		GetFixStrX(sTemp,0,20,sSuffixStr);
		if(strlen(sSuffixStr)==0)strcpy(sSuffixStr,"C");
		
		/*生成标准输出话单*/
		GenStdTicket();

		/*ticketvalid属性
			<0:无效话单;
			0 :校验不通过异常话单供回收
			>0:正常话单
		*/
		/*对于属性校验不通过的错误话单，则将原始话单附在后面*/
		if(iTicketValid<0){
			/*无效话单继续无效则不回收*/
			iErrCnt++;
			continue;
		}
		
		if(iTicketValid==0){/*0表示异常话单*/
			iAbnormalCnt++;
			
			
			if(Item2FileOut(&pAbnormal,TICKET.sStd,TICKET.iStdLen,
				sTargetName,"a")<0){
				WriteAlertPrint("生成异常话单链表错误");
				return -1;
			}
			GetOutFileName(sTargetName,"a",sFileName);
			if(SumTinyRollLog(&pSumLog,sBaseName,sFileName,1)<0){
				WriteAlertMsg("生成日志文件列表错误");
				return -1;
			}
			if(strstr(sSplitNew,"a")==NULL) strcat(sSplitNew,"a");
		}
		else{
			iNormalCnt++;
			
			if(Item2FileSplitOut(&pNormal,TICKET.sStd,
				TICKET.iStdLen,sBaseName,sTargetName,
				"C",&pSumLog,sSplitNew,sMsg)<0){
				WriteAlertPrint("生成正常话单链表错误,消息:%s",msg);
				return -1;
			}
		}

		if(iWantUpdate==1){
			strcpy(TempUTicket.sRowID,Temp.sRowID);
			if(EUpdateStructToUCommTicket(&TempUTicket,false,&TempUp)<0){
				WriteAlertMsg("表%s更新数据错误.",TempUp.sTableName);
				return -1;
			}
		}
	}
	if(iWantUpdate==1){

		if(EUpdateStructToUCommTicket(NULL,true,&TempUp)<0){
			WriteAlertMsg("表%s更新数据错误.",TempUp.sTableName);
			return -1;
		}
	}

	if(WriteRollLogCtl(pSumLog,sTargetName)<0){
		WriteAlertMsg("写日志控制文件失败");
		return -1;
	}

	CloseFileOut(pAbnormal);
	CloseFileOutAll(pNormal);

	WriteProcMsg("对表%s出文件完毕,处理数%d,其中正常数%d,异常数%d",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt);
	if(iNormalCnt==0)
		WriteProcMsg("正常话单数为0，可能1:没有满足条件的特定话单,",
			"2:id=%s,split=%s的分离类型没有一条话单能匹配上",
				sMsc,sUserType);
	printf("%s\t%d\t%d\t%d\t%s\n",
		sTableName,iCnt,iNormalCnt,iAbnormalCnt,sSplitNew);
	
	CommitWork();
	DisconnectDatabase();
	
/*释放参数*/
	DistroyAllMem();

	
	return 0;
}
