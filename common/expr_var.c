
#include <hnixs.h>
#include <wwlog.h>
#include <list.h>
#include <expr.h>
#include <expr_supp.h>
#include <expr_var.h>

int	iTailPos=0,iFixFlag=true,igFirst=1;
struct 	TicketStruct TICKET;
void InitTicket();
static void get_t_ori(int iParam,void *p);
static void get_t_len(int iParam,void *p);

int     iAcctItemTypeCnt=0;                     /*用户帐目数*/
int     aiAcctItemType[MAXACCTITEMTYPE];        /*帐目类别下标*/
int     aiAcctItemCharge[MAXACCTITEMTYPE];      /*各种帐目金额数组*/
char    asAcctItemState[MAXACCTITEMTYPE][2];    /*帐目*/

int GetAcctItemValue(int *piAcctItemTypeID,int *piCharge,char sState[2])
{
	int i,j;
	
	if(iAcctItemTypeCnt<=0) return false;
	
	iAcctItemTypeCnt--;
	i=iAcctItemTypeCnt;
	j=aiAcctItemType[i];
	
	*piAcctItemTypeID=	j;	
	*piCharge=		aiAcctItemCharge[j];
	strcpy(sState,		asAcctItemState[j]);
	
	return true;
} 
void SetAcctItemValue(int iAcctItemTypeID,int iCharge,char sState[2])
{
	int i;
	
	for(i=0;i<iAcctItemTypeCnt;i++)
		if(iAcctItemTypeID==aiAcctItemType[i]) break;


	if(i==iAcctItemTypeCnt){	/*生成新帐目了*/

		iAcctItemTypeCnt++;
		aiAcctItemType[i]	=	iAcctItemTypeID;
		aiAcctItemCharge[iAcctItemTypeID]=	iCharge;
			/*新生成肯定为计费*/
		strcpy(asAcctItemState[iAcctItemTypeID],	sState);
	}
	else{	/*已有帐目,则直接更新*/
		aiAcctItemCharge[iAcctItemTypeID]=	iCharge;
		strcpy(asAcctItemState[iAcctItemTypeID],	sState);
	}
}
static void get_t_ori(int iParam,void *p)
{
	(*(char**)p)	= TICKET.sOri;
}
static void get_t_len(int iParam,void *p)
{
	(*(int*)p)	= TICKET.iOriLen;
}
void get_t_integer(int iParam,void *p)
{
	(*(int*)p)=TFIELD[iParam].u.iValue;
}
void get_t_string(int iParam,void *p)
{
	AssignStrchar2Varchar((char**)p,TFIELD[iParam].u.sValue);
/*	strcpy((char *)p,TFIELD[iParam].u.sValue);*/
}
static void get_first(int iParam,void *p)
{
	(*(int*)p)	= igFirst;
}
void get_t_pointer(int iParam,void *p)
{
	(*(char**)p)=TFIELD[iParam].u.pValue;
}
void get_t_double(int iParam,void *p)
{
	(*(double*)p)=TFIELD[iParam].u.dValue;
}
void put_t_integer(int iParam,void *p)
{
	TFIELD[iParam].u.iValue=(*(int*)p);
	InsertTicketCur(&TFIELD[iParam]);	
}
void put_t_string(int iParam,void *p)
{
	strcpy(TFIELD[iParam].u.sValue,GetVarcharData(*(char **)p));
	InsertTicketCur(&TFIELD[iParam]);
}
void put_first(int iParam,void *p)
{
	igFirst=(*(int*)p);
}
void put_t_pointer(int iParam,void *p)
{
	TFIELD[iParam].u.pValue=(*(char**)p);
	InsertTicketCur(&TFIELD[iParam]);	
}
void put_t_double(int iParam,void *p)
{
	TFIELD[iParam].u.dValue=(*(double*)p);
	InsertTicketCur(&TFIELD[iParam]);	
}
int CheckPrepVar(char sVar[],char *pcType)
{
	int iIndex;
        struct  ExprVarStruct *p;

	if(SearchRegVarLink(sVar,&p)==NOTFOUND){
		*pcType=VARTYPE_UNK;
		/*支持自定义字段变量*/
/*		if(strncmp(sVar,"it_",3)==0||
			strncmp(sVar,"pt_",3)==0||
			strncmp(sVar,"st_",3)==0){
			
			if(sVar[0]=='i'){
				*pcType=VARTYPE_INT;
				LoadVariant=	get_t_integer;
				SaveVariant=	put_t_integer;
			}
			else if(sVar[0]=='s'){
				*pcType=VARTYPE_STR;
				LoadVariant=	get_t_string;
				SaveVariant=	put_t_string;
			}

			if((iIndex=AddTicketField(sVar,*pcType))<0)return -1;

			return iIndex;
		}
*/
		return 0;
	}
	LoadVariant=	p->LoadVariant;
	SaveVariant=	p->SaveVariant;
	*pcType=	p->cType;
	
	if(p->cUseType!='f') return 0;
	
	if((iIndex=AddTicketField(sVar,p->cType))<0) return -1;
	
	return iIndex;
	
}
/****************************************************************
*		-------帐单属性函数------------			*
****************************************************************/

void IGetAcctItemCharge(int iParam,int *piOut)
{
	int iTotalFee=0,i,j;

	if(iParam!=0){
		for(i=0;i<iAcctItemTypeCnt;i++){
			if(iParam==aiAcctItemType[i]){
				*piOut=aiAcctItemCharge[iParam];
				return;
			}
		}
		*piOut=0;
		return;
	}
	for(i=0;i<iAcctItemTypeCnt;i++){
		j=aiAcctItemType[i];
		if(asAcctItemState[j][0] == '0'&&j<900000)
			iTotalFee+=aiAcctItemCharge[j];
	}
	*piOut=iTotalFee;
}
void GetAcctItemCharge(int iParam,void *p)
{
	IGetAcctItemCharge(iParam,(int*)p);
}
void IGetAcctItemState(int iParam,char sState[])
{
	int i;

	for(i=0;i<iAcctItemTypeCnt;i++){
		if(iParam==aiAcctItemType[i]){
			strcpy(sState,asAcctItemState[iParam]);
			return;
		}
	}
	strcpy(sState,"");
}
void GetAcctItemState(int iParam,void *p)
{
	char sState[10];

	IGetAcctItemState(iParam,sState);
	
	AssignStrchar2Varchar((char**)p,sState);
}
void IPutAcctItemCharge(int iParam,int iValue)
{
	int i,j;

	/*增加一个所有费变量*/
	if(iParam==0){
		for(i=0;i<iAcctItemTypeCnt;i++){
			j=aiAcctItemType[i];
			aiAcctItemCharge[j]=iValue;
		}
		return;
	}
	for(i=0;i<iAcctItemTypeCnt;i++)
		if(iParam==aiAcctItemType[i]) break;


	if(i==iAcctItemTypeCnt){	/*生成新帐目了*/

		iAcctItemTypeCnt++;
		aiAcctItemType[i]	=	iParam;
		aiAcctItemCharge[iParam]=	iValue;
			/*新生成肯定为计费*/
		strcpy(asAcctItemState[iParam],"0");
	}
	else	/*已有帐目,则直接更新*/
		aiAcctItemCharge[iParam]=	iValue;

}
void PutAcctItemCharge(int iParam,void *p)
{
	int iValue=(*(int*)p);
	IPutAcctItemCharge(iParam,iValue);
}
void IPutAcctItemState(int iParam,char sState[])
{
	int i,j;

	if(iParam==0){
		for(i=0;i<iAcctItemTypeCnt;i++){
			j=aiAcctItemType[i];

			strcpy(asAcctItemState[j],sState);
		}
		return;
	}

	for(i=0;i<iAcctItemTypeCnt;i++)
		if(iParam==aiAcctItemType[i]) break;


	if(i==iAcctItemTypeCnt){	/*生成新帐目了*/
		iAcctItemTypeCnt++;
		aiAcctItemType[i]	=	iParam;
		strcpy(asAcctItemState[iParam],sState);
			/*新生成肯定为费用为0*/
		aiAcctItemCharge[iParam]=	0;


	}
	else	/*已有帐目,则直接更新*/
		strcpy(asAcctItemState[iParam],sState);
}
void PutAcctItemState(int iParam,void *p)
{
	IPutAcctItemState(iParam,GetVarcharData(*(char**)p));
}
int CheckAcctItemVar(char sVar[],char *pcType)
{
        int i;
        char sTemp[7];
        
        struct  ExprVarStruct *p;

	if(SearchRegVarLink(sVar,&p)==NOTFOUND) return -1;

	if(p->cUseType=='A'){
       		strncpy(sTemp,sVar+1,6);
       		sTemp[6]=0;
        	i=atoi(sTemp);
	}
	else if(p->cUseType=='f'){
		if((i=AddTicketField(sVar,p->cType))<0) return -1;
	}
	
	LoadVariant=	p->LoadVariant;
	SaveVariant=	p->SaveVariant;
	*pcType=	p->cType;
	
        return i;
}
void RegAcctItemVar()
{
RegVarItem(GetAcctItemCharge,PutAcctItemCharge,VARTYPE_INT,'A',"F******");
RegVarItem(GetAcctItemState, PutAcctItemState, VARTYPE_STR,'A',"S******");

RegVarItem(get_t_integer, put_t_integer,  VARTYPE_INT,'f',"it_#" );
RegVarItem(get_t_string,  put_t_string,   VARTYPE_STR,'f',"st_#" );
RegVarItem(get_t_pointer, put_t_pointer,  VARTYPE_POINTER,'f',"pt_#" );
RegVarItem(get_t_double,  put_t_double,   VARTYPE_DOUBLE,'f',"dt_#" );
}
void RegPrepVar()
{

RegVarItem(get_t_ori   ,  NULL        ,  VARTYPE_POINTER,'T',"t_ori"       );
RegVarItem(get_t_len   ,  NULL        ,  VARTYPE_INT,'T',"t_len"       );
RegVarItem(get_first   ,  put_first   ,  VARTYPE_INT,'f',"first"       );

RegVarItem(get_t_integer, put_t_integer, VARTYPE_INT,'f',"t_call_type"   );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_imsi"        );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_calling_nbr" );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_called_nbr"  );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_msisdn"      );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_other_party" );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_start_date"  );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_start_time"  );
RegVarItem(get_t_integer, put_t_integer, VARTYPE_INT,'f',"t_duration"    );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_msrn"        );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_msc"         );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_lac"         );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_cell_id"     );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_other_lac"   );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_other_cell_id");
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_trunk_in"    );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_trunk_out"   );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_service_type");
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_service_code");
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"t_third_party" );

RegVarItem(get_t_integer, put_t_integer,  VARTYPE_INT,'f',"it_#" );
RegVarItem(get_t_string,  put_t_string,  VARTYPE_STR,'f',"st_#" );
RegVarItem(get_t_pointer, put_t_pointer,  VARTYPE_POINTER,'f',"pt_#" );
RegVarItem(get_t_double,  put_t_double,   VARTYPE_DOUBLE,'f',"dt_#" );

}
int AddTicketField(char sVar[],char cType)
{
	int	i;
	static int iFirstFlag=true;
	struct ETicketFieldStruct *p;
	if(iFirstFlag==true){
		iFirstFlag=false;
		InitTicket();
	}
	if(TICKET.iPos>=MAXFIELDNUM) return -1;
/*字段重复检测*/
	for(i=0;i<TICKET.iPos;i++){
		p=&(TFIELD[i]);
		if(strcmp(sVar,p->sName)==0) return i;
	}
	
	p=&(TFIELD[TICKET.iPos]);
	p->iIndex=	TICKET.iPos;
	p->cType=	cType;
	strcpy(p->sName,sVar);
	p->iLen=	0;
	p->cCur=	0;
	p->pCur=p->pNext=p->pStd=NULL;
	p->u.iValue=0;

	InsertTicketAll(p);

	TICKET.iPos++;
	return p->iIndex;
}
void InitTicket()
{

	TICKET.iOriLen=0;
	TICKET.iStdLen=0;
	TICKET.iPos=1;
	TICKET.pCur=NULL;
	TICKET.pStd=NULL;
	TICKET.pAll=NULL;
}
void ResetTicket()
{
	struct ETicketFieldStruct *pCur;

/*复位Cur链表*/
	pCur=TICKET.pCur;
	while(pCur!=NULL){
		pCur->cCur=0;
		pCur->u.iValue=0;
		pCur=pCur->pCur;
	}
	TICKET.iOriLen=0;
	TICKET.iStdLen=0;
	TICKET.pCur=NULL;
}
void ResetTicketStd()
{
	struct ETicketFieldStruct *pStd;

/*复位Cur链表*/
	pStd=TICKET.pStd;
	while(pStd!=NULL){
		pStd->cStd=0;
		pStd->u.iValue=0;
		pStd=pStd->pStd;
	}
	TICKET.iOriLen=0;
	TICKET.iStdLen=0;
	TICKET.pStd=NULL;
	iTailPos=0;
}
void InsertTicketAll(struct ETicketFieldStruct *p)
{
	p->pNext=	TICKET.pAll;
	TICKET.pAll=	p;
}
void InsertTicketCur(struct ETicketFieldStruct *p)
{
	if(p->cCur==0){
		p->cCur=	1;
		p->pCur=	TICKET.pCur;
		TICKET.pCur=	p;
	}
}
void InsertTicketStd(struct ETicketFieldStruct *p)
{
/*第一个变量不加入输出链表，可能是临时变量*/
	if(p->iIndex==0) return;
	
	if(p->cStd==0){
		p->cStd=1;
		p->pStd=	TICKET.pStd;
		TICKET.pStd=	p;
	}
}
void InsertTicketStdTail(struct ETicketFieldStruct *p)
{
	struct ETicketFieldStruct *ptHead=TICKET.pStd;

/*第一个变量不加入输出链表，可能是临时变量*/
	if(p->iIndex==0) return;
	
	if(p->cStd==0){
		p->cStd=1;
		if(ptHead==NULL){
			p->pStd=	NULL;
			TICKET.pStd=	p;
			return;
		}
		while(ptHead->pStd!=NULL) ptHead=ptHead->pStd;
		p->pStd=NULL;
		ptHead->pStd=p;
	}
}
void GenStdTicket()
{
	int 	l=0;
	char	sTemp[4096];
	struct ETicketFieldStruct *pTemp=TICKET.pStd;

/*初始化空记录*/
	if(iFixFlag==true){
		memset((void*)(TICKET.sStd),' ',iTailPos);
		sprintf(TICKET.sStd+iTailPos,"\n");
		TICKET.iStdLen=	iTailPos+1;
	}
	else{
		TICKET.iStdLen=	0;
		strcpy(TICKET.sStd,"");
	}
	{
		static int xx=0;
		
		xx++;
		printf("x=%d.\n",xx);
		if(xx==3862){
			printf("hello.\n");
		}
	}

	while(pTemp!=NULL){
		if(pTemp->cCur==0){/*没有输出,需要默认值*/
			strncpy(sTemp,pTemp->sDefaultValue,pTemp->Pos.iLen);
			sTemp[pTemp->Pos.iLen]=0;
		}
		else{/*需要取具体的话单*/
			if(pTemp->cType==VARTYPE_INT)
				sprintf(sTemp,pTemp->sFormatStr,pTemp->u.iValue);
			else
				sprintf(sTemp,pTemp->sFormatStr,pTemp->u.sValue);
			sTemp[pTemp->Pos.iLen]=0;
		}
		if(iFixFlag==false){
			l=strlen(sTemp);
			strcat(TICKET.sStd,sTemp);
			TICKET.iStdLen+=l;
		}
		else{
			strncpy(TICKET.sStd+pTemp->Pos.iOffset,
				sTemp,strlen(sTemp));
		}
		pTemp=pTemp->pStd;
	}
	if(iFixFlag==false){
		strcat(TICKET.sStd,"\n");
		TICKET.iStdLen++;
	}
}
void InitExprIntfVar()
{
	iTailPos=0;
	iFixFlag=true;
	iAcctItemTypeCnt=0;
	ResetTicketStd();
	igFirst=1;
}
