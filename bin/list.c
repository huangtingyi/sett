#include "hnixs.h"
#include "list.h"



/*ͳ������ڵ���Ŀ*/
int CountList(LIST* ptHead)
{
	int iCount=0;

	while(ptHead!=NULL){
		ptHead=ptHead->pNext;
		iCount++;
	}

	return iCount;
}
/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelList(LIST *ptHead,int (*operate_list)(LIST *))
{
	int j,sum=0;

	LIST *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		if((j=(*operate_list)(pTemp))<0) return -1;
		sum+=j;
	}

	return sum;
}
/*ֱ�ӽ����ݲ���ͷ�ڵ�*/
void InsertList(LIST **pptHead,LIST *p)
{
	p->pNext=	*pptHead;
	*pptHead=	p;
}
void InsertListTail(LIST **pptHead,LIST *p)
{	
	LIST *ptHead=(*pptHead);
	if(ptHead==NULL){
		InsertList(pptHead,p);
		return ;
	}
	while(ptHead->pNext!=NULL) ptHead=ptHead->pNext;
	InsertList((LIST**)&(ptHead->pNext),(LIST*)p);
}
void AppendListTail(LIST **pptHead,LIST *p)
{	
	LIST *ptHead=(*pptHead);
	if(ptHead==NULL){
		*pptHead=p;
		return ;
	}
	while(ptHead->pNext!=NULL) ptHead=ptHead->pNext;
	ptHead->pNext=p;
}
/*����comp_list�ǶԲ���ľ������,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	   */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)    */
/*�ú�����LIST *p �������ⲿ������ڴ� */
void InsertListSort(LIST **pptHead,LIST *p,int (*comp_list)(LIST *,LIST *))
{
	LIST *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL){
		InsertList(pptHead,p);
		return ;
	}

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(p,*pptHead)<=0){
		InsertList(pptHead,p);
		return ;
	}
		/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*������� û�е�ĩβ*/
	while(ptCur!=NULL){
			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(p,ptCur)<=0) break;
			/*����ָ������ƶ�*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	InsertList(&(ptPre->pNext),p);
}

/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����LIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�LIST�У��ڴ���ظ�����
*/
int InsertListSumm(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *))
{
	int compr;

	LIST *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL){
		InsertList(pptHead,p);
		return FALSE;
	}

	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(p,*pptHead);

        if(compr<0){
		InsertList(pptHead,p);
		return FALSE;
	}

	/*��ͷ�ڵ���ȣ�����ֵ�ۼӵ�ͷ�ڵ�*/
        if(compr==0){
		(*sum_list)(*pptHead,p);
		return TRUE;
	}


		/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*������� û�е�ĩβ*/
	while(ptCur!=NULL){
		compr=(*comp_list)(p,ptCur);

			/*����һ�����������ݴ�Ľڵ�,�����ۼ�*/
                if(compr<0) break;
			/*��ֵ�߼���ȣ����ۼ�����*/
		if(compr==0){
			(*sum_list)(ptCur,p);
			return TRUE;
		}
			/*����ָ������ƶ�*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*λ��ȷ����ֻҪ���뼴��,����������ȥ�ڴ�*/

	InsertList(&(ptPre->pNext),p);

	return FALSE;
}
int InsertListSortSum(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *))
{
	return InsertListSumm(pptHead,p,comp_list,sum_list);
}
/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchList(LIST *ptHead,void *pi,LIST **p,
	int (*comp_list)(void *,LIST *))
{
	while(ptHead!=NULL){
		if((*comp_list)(pi,ptHead)==0){
			*p=ptHead;
			return FOUND;
		}
	        ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}

/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteList(LIST **pptHead,LIST *p)
{
	LIST *ptPre,*ptCur;

	if(p==*pptHead){
		*pptHead=p->pNext;
		return TRUE;
	}

	ptPre=*pptHead;
	ptCur=ptPre->pNext;

	while(ptCur!=NULL){
		if(p==ptCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			ptPre->pNext=p->pNext;
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
void DestroyList(LIST *ptHead)
{
	LIST *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		hfree(pTemp,sizeof(LIST));
	}
}
void FreeList(LIST *ptHead)
{
	DestroyList(ptHead);
}
void ReverseList(LIST **pptHead)
{
	LIST *pPre,*pCur;
	
	pCur=*pptHead;
	*pptHead=NULL;
	
	while(pCur!=NULL){
		pPre=pCur;
		pCur=pCur->pNext;
		InsertList(pptHead,pPre);
	}
}
void assign_insert_list(void **ppData,void *pData)
{
	InsertList((LIST**)(ppData), (LIST*)pData);
}
LINK *MallocLink()
{
	LINK *pTemp;
	if((pTemp=(LINK*)hmalloc(sizeof(LINK)))==NULL)
		return NULL;
	pTemp->pNext=NULL;
	pTemp->pData=NULL;
	return pTemp;
}
int4b InsertLink(LINK **pptHead, void *pData,LINK *pTemp)
{
	LINK *pNode;

	if(pTemp==NULL){
		if((pNode=MallocLink())==NULL) return -1;
	}
	else
		pNode=pTemp;

	pNode->pNext=	*pptHead;
	*pptHead=pNode;

	return 0;
}

int4b DeleteLink(LINK **pptHead, LINK *p)
{
	LINK *ptPre,*ptCur;

	if(p==*pptHead){
		*pptHead=p->pNext;
		return TRUE;
	}

	ptPre=*pptHead;
	ptCur=ptPre->pNext;

	while(ptCur!=NULL){
		if(p==ptCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			ptPre->pNext=p->pNext;
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
int4b SearchLink(LINK *ptHead, void *pi, LINK **p,
	int4b ( *comp_list)(void *,void *))
{
	while(ptHead!=NULL){
		if((*comp_list)(pi,ptHead->pData)==0){
			*p=ptHead;
			return FOUND;
		}
	        ptHead=ptHead->pNext;
	}
	return NOTFOUND;
}

int4b InsertLinkSort(LINK **pptHead, void *p,
	int4b ( *comp_list)(void *,void *),LINK *pTemp)
{
	LINK *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL)
		return InsertLink(pptHead,p,pTemp);

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(p,(*pptHead)->pData)<=0)
		return InsertLink(pptHead,p,pTemp);

		/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*������� û�е�ĩβ*/
	while(ptCur!=NULL){
			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(p,ptCur->pData)<=0) break;
			/*����ָ������ƶ�*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}

	/*λ��ȷ����ֻҪ���뼴��???*/
	return InsertLink(&(ptPre->pNext),p,pTemp);
}
int4b InsertLinkSumm(LINK **pptHead, void *p,
	int4b ( *comp_list)(void *,void *),
	void ( *sum_list)(void *,void *),LINK **ppTemp)
{
	int4b compr;

	LINK *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL){

		if(InsertLink(pptHead,p,*ppTemp)<0) return -1;
		*ppTemp=NULL;
		return 0;
	}

	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(p,(*pptHead)->pData);

        if(compr<0){
		if(InsertLink(pptHead,p,*ppTemp)<0) return -1;
		*ppTemp=NULL;
		return 0;
	}

	/*��ͷ�ڵ���ȣ�����ֵ�ۼӵ�ͷ�ڵ�*/
        if(compr==0){
		(*sum_list)((*pptHead)->pData,p);
		return 0;
	}


		/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*������� û�е�ĩβ*/
	while(ptCur!=NULL){
		compr=(*comp_list)(p,ptCur->pData);

			/*����һ�����������ݴ�Ľڵ�,�����ۼ�*/
                if(compr<0) break;
			/*��ֵ�߼���ȣ����ۼ�����*/
		if(compr==0){
			(*sum_list)(ptCur->pData,p);
			return 0;
		}
			/*����ָ������ƶ�*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*λ��ȷ����ֻҪ���뼴��,����������ȥ�ڴ�*/

	if(InsertLink(&(ptPre->pNext),p,*ppTemp)<0) return -1;
	*ppTemp=NULL;

	return 0;
}

int4b CountLink(LINK *ptHead)
{
	int4b i=0;
	while(ptHead!=NULL){i++;ptHead=ptHead->pNext;}
	return i;
}

int4b TravelLink(LINK *ptHead, int4b ( *operate_list)(void *))
{
	int4b j,sum=0;

	LINK *pNext;

	while(ptHead!=NULL){
		pNext=ptHead->pNext;
		if((j=(*operate_list)(ptHead->pData))<0) return -1;
		ptHead=pNext;
		sum+=j;
	}

	return sum;
}

void DestroyLink(LINK *ptHead)
{
	LINK *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext;
		hfree(pTemp,sizeof(LINK));
	}
}

void ClearLink(LINK *ptHead)
{
	DestroyLink(ptHead);
}

/****��LIST��Ӧ��EList���ڹ����ڴ�**/
/*ͳ������ڵ���Ŀ*/
int CountEList(void *pSeg,POINTER ioffHead)
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=ELISTNXT(pSeg,ioffHead);
		iCount++;
	}

	return iCount;
}
/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelEList(void *pSeg,POINTER ioffHead,int (*operate_list)(POINTER))
{
	int j,sum=0;

	POINTER ioffTmp;

	while(ioffHead!=-1){
		ioffTmp=ioffHead;
		ioffHead=ELISTNXT(pSeg,ioffHead);

		if((j=(*operate_list)(ioffTmp))<0) return -1;

		sum+=j;
	}

	return sum;
}
void InsertEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{
	ELISTNXT(pSeg,ioffValue)=(*pioffHead);
	(*pioffHead)= ioffValue;
}
void InsertEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		InsertEList(pSeg,pioffHead,ioffValue);
		return ;
	}

	while(ELISTNXT(pSeg,ioffHead)!=-1) ioffHead=ELISTNXT(pSeg,ioffHead);

	InsertEList(pSeg,&ELISTNXT(pSeg,ioffHead),ioffValue);
}
void AppendEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		*pioffHead=ioffValue;
		return ;
	}

	while(ELISTNXT(pSeg,ioffHead)!=-1) ioffHead=ELISTNXT(pSeg,ioffHead);

	ELISTNXT(pSeg,ioffHead)=ioffValue;
}
/*����comp_list�ǶԲ���ľ������,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	   */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)    */
/*�ú�����LIST *p �������ⲿ������ڴ� */
void InsertEListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ))
{
	POINTER ioffPre,ioffCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffHead==-1){
		InsertEList(pSeg,pioffHead,ioffValue);
		return ;
	}

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(ioffValue,*pioffHead)<=0){
		InsertEList(pSeg,pioffHead,ioffValue);
		return ;
	}
		/*�����������ڵ��ͷ�ڵ��*/
	ioffPre=*pioffHead;
	ioffCur=ELISTNXT(pSeg,ioffPre);
			 /*������� û�е�ĩβ*/
	while(ioffCur!=-1){
			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(ioffValue,ioffCur)<=0) break;
			/*����ָ������ƶ�*/
		ioffPre=ioffCur;
		ioffCur=ELISTNXT(pSeg,ioffPre);
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	InsertEList(pSeg,&(ELISTNXT(pSeg,ioffPre)),ioffValue);
}

/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����LIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�LIST�У��ڴ���ظ�����
*/
int InsertEListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ))
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffHead==-1){
		InsertEList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}
	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertEList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}

	/*��ͷ�ڵ���ȣ�����ֵ�ۼӵ�ͷ�ڵ�*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*�����������ڵ��ͷ�ڵ��*/
	ioffPre=*pioffHead;
	ioffCur=ELISTNXT(pSeg,ioffPre);
			 /*������� û�е�ĩβ*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*����һ�����������ݴ�Ľڵ�,�����ۼ�*/
                if(compr<0) break;
			/*��ֵ�߼���ȣ����ۼ�����*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*����ָ������ƶ�*/
		ioffPre=ioffCur;
		ioffCur=ELISTNXT(pSeg,ioffPre);
	}
	/*λ��ȷ����ֻҪ���뼴��,����������ȥ�ڴ�*/

	InsertEList(pSeg,&(ELISTNXT(pSeg,ioffPre)),ioffValue);

	return FALSE;
}

/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchEList(void *pSeg,POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,POINTER))
{
	while(ioffHead!=-1){

		if((*comp_list)(pi,ioffHead)==0){
			*pioff=ioffHead;
			return FOUND;
		}
		ioffHead=ELISTNXT(pSeg,ioffHead);
	}
	return NOTFOUND;
}

/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{
	POINTER ioffPre,ioffCur;

	if(ioffValue==*pioffHead){
		*pioffHead=ELISTNXT(pSeg,ioffValue);
		return TRUE;
	}


	ioffPre=*pioffHead;
	ioffCur=ELISTNXT(pSeg,ioffPre);

	while(ioffCur!=-1){

		if(ioffValue==ioffCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			ELISTNXT(pSeg,ioffPre)=ELISTNXT(pSeg,ioffValue);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=ELISTNXT(pSeg,ioffPre);
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
void ReverseEList(void *pSeg,POINTER *pioffHead)
{
	POINTER ioffPre,ioffCur;
	
	ioffCur=*pioffHead;
	*pioffHead=-1;
	
	while(ioffCur!=-1){

		ioffPre=ioffCur;
		ioffCur=ELISTNXT(pSeg,ioffPre);

		InsertEList(pSeg,pioffHead,ioffPre);
	}
}

/**********��ͨ�ڴ��г�������******/
/***************************************************/
/********	ָ����չ����		*******/
/********	ָ����չ����		*******/
/***************************************************/

int TravelVList(void *ptHead,int (*operate_list)(void *),
	void *(*getnext)(void*))
{
	int j,sum=0;

	void *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=(*getnext)(ptHead);

		if((j=(*operate_list)(pTemp))<0) return -1;

		sum+=j;
	}

	return sum;
}
int CountVlist(void *ptHead,void *(*getnext)(void*))
{
	int iCount=0;
	
	while(ptHead!=NULL){
		ptHead=(*getnext)(ptHead);
		iCount++;
	}

	return iCount;

}
void InsertVList(void **pptHead,void *pValue,void **(*get_next)(void *))
{
	*(*get_next)(pValue)=	*pptHead;
	*pptHead=		pValue;
}
void InsertVListTail(void **pptHead,void *pValue,void **(*get_next)(void *))
{
	
	void *ptHead=(*pptHead);
	
	if(ptHead==NULL){
		InsertVList(pptHead,pValue,get_next);
		return ;
	}
	while(*get_next(ptHead)!=NULL) ptHead=*get_next(ptHead);
	
	InsertVList(get_next(ptHead),pValue,get_next);

}
void AppendVListTail(void **pptHead,void *pValue,void **(*get_next)(void *))
{
	void *ptHead=(*pptHead);
	
	if(ptHead==NULL){
		*pptHead=pValue;
		return ;
	}
	while(*get_next(ptHead)!=NULL) ptHead=*get_next(ptHead);
	
	*get_next(ptHead)=	pValue;
}
void InsertVListSort(void **pptHead,void *pValue,
	int (*comp_list)(void *,void *),void **(*get_next)(void *))
{
	void *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL){
		InsertVList(pptHead,pValue,get_next);
		return ;
	}

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(pValue,*pptHead)<=0){
		InsertVList(pptHead,pValue,get_next);
		return ;
	}
			/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=*(*get_next)(ptPre);
			 /*������� û�е�ĩβ*/

	while(ptCur!=NULL){

			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(pValue,ptCur)<=0) break;
			/*����ָ������ƶ�*/

		ptPre=ptCur;
		ptCur=*(*get_next)(ptPre);
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	*(*get_next)(ptPre)=	pValue;
	*(*get_next)(pValue)=	ptCur;
}
int InsertVListSumm(void **pptHead,void *pValue,
        int (*comp_list)(void *,void *),
        void (*sum_list)(void *,void *),
        void **(*get_next)(void *),void (*assign_list)(void*,void *))
{
	int compr;
	void *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL){
		InsertVList(pptHead,pValue,get_next);
		return false;
	}

	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(pValue,*pptHead);
	
	if(compr<0){
		InsertVList(pptHead,pValue,get_next);
		return false;
	}
	
	if(compr==0){
		sum_list(*pptHead,pValue);
		return true;
	}
			/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=*(*get_next)(ptPre);
			 /*������� û�е�ĩβ*/

	while(ptCur!=NULL){

			/*����һ�����������ݴ�Ľڵ�*/
		compr=(*comp_list)(pValue,ptCur);
		
		if(compr<0) break;
		if(compr==0){
			sum_list(ptCur,pValue);
			return true;
		}
		/*����ָ������ƶ�*/
		ptPre=ptCur;
		ptCur=*(*get_next)(ptPre);
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	*(*get_next)(ptPre)=	pValue;
	*(*get_next)(pValue)=	ptCur;
	return false;
}
int SearchVList(void *ptHead,void *pi,void **p,
	int (*comp_list)(void *,void *),
	void **(*getnext)(void *))
{
	while(ptHead!=NULL){
		if((*comp_list)(pi,ptHead)==0){
			*p=ptHead;
			return FOUND;
		}
	        ptHead=*getnext(ptHead);	
	}	
	return NOTFOUND;
}
int DeleteVList(void **pptHead,void *p,void (*assign_list)(void*,void *),
		void **(*getnext)(void *))
{
	void *ptPre,*ptCur;

	if(p==*pptHead){
		*pptHead=*(*getnext)(p);
		return TRUE;
	}	

	ptPre=*pptHead;
	ptCur=*(*getnext)(ptPre);

	while(ptCur!=NULL){
		if(p==ptCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			(*assign_list)(ptPre,p);
/*			ptPre->pNext=p->pNext;*/
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=*(*getnext)(ptPre);
/*		ptCur=ptPre->pNext;*/
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
void ReverseVList(void **pptHead,void **(*getnext)(void *))
{
	void *pPre,*pCur;
	
	pCur=*pptHead;
	*pptHead=NULL;
	
	while(pCur!=NULL){
		pPre=pCur;
		pCur=*getnext(pPre);
		InsertVList(pptHead,pPre,getnext);
	}
}
/**�����ڴ��������***********/
void InsertVEList(POINTER *pioffsetHead,POINTER ioffsetValue,
	POINTER *(*get_next)(POINTER))
{
	*(*get_next)(ioffsetValue)=	*pioffsetHead;
	*pioffsetHead=			ioffsetValue;
}
void InsertVEListSort(POINTER *pioffsetHead,POINTER ioffsetValue,
	int (*comp_list)(POINTER ,POINTER ),POINTER *(*get_next)(POINTER ))
{
	POINTER ioffsetPre,ioffsetCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffsetHead==-1){

		*(*get_next)(ioffsetValue)=-1;
		*pioffsetHead=ioffsetValue;
		return ;
	}

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(ioffsetValue,*pioffsetHead)<=0){

		*(*get_next)(ioffsetValue)=*pioffsetHead;
		*pioffsetHead=ioffsetValue;
		return ;
	}
		/*�����������ڵ��ͷ�ڵ��*/
	ioffsetPre=*pioffsetHead;
	ioffsetCur=*(*get_next)(*pioffsetHead);

			 /*������� û�е�ĩβ*/
	while(ioffsetCur != -1){

			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(ioffsetValue,ioffsetCur)<=0) break;

			/*����ָ������ƶ�*/
		ioffsetPre=ioffsetCur;
		ioffsetCur=*(*get_next)(ioffsetCur);
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	*(*get_next)(ioffsetPre)=	ioffsetValue;
	*(*get_next)(ioffsetValue)=	ioffsetCur;
}

/****��LIST��Ӧ��EList���ڹ����ڴ�**/
/*ͳ������ڵ���Ŀ*/
int CountVEList(POINTER ioffHead,POINTER *(*get_next)(POINTER))
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=*(*get_next)(ioffHead);
		iCount++;
	}
	return iCount;
}
/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelVEList(POINTER ioffHead,int (*operate_list)(POINTER),
	POINTER *(*get_next)(POINTER))
{
	int j,sum=0;

	POINTER ioffTmp;

	while(ioffHead!=-1){
		ioffTmp=ioffHead;
		ioffHead=*(*get_next)(ioffHead);

		if((j=(*operate_list)(ioffTmp))<0) return -1;

		sum+=j;
	}

	return sum;
}
void InsertVEListTail(POINTER *pioffHead,POINTER ioffValue,
	POINTER *(*get_next)(POINTER))
{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		InsertVEList(pioffHead,ioffValue,get_next);
		return ;
	}

	while((*(*get_next)(ioffHead))!=-1) ioffHead=*(*get_next)(ioffHead);

	InsertVEList((*get_next)(ioffHead),ioffValue,get_next);
}
void AppendVEListTail(POINTER *pioffHead,POINTER ioffValue,
	POINTER *(*get_next)(POINTER))

{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		*pioffHead=ioffValue;
		return ;
	}

	while((*(*get_next)(ioffHead))!=-1) ioffHead=*(*get_next)(ioffHead);

	*(*get_next)(ioffHead)= ioffValue;
}
/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����LIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�LIST�У��ڴ���ظ�����
*/
int InsertVEListSumm(POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ),
	POINTER *(*get_next)(POINTER ) )
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffHead==-1){
		InsertVEList(pioffHead,ioffValue,get_next);
		return FALSE;
	}
	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertVEList(pioffHead,ioffValue,get_next);
		return FALSE;
	}

	/*��ͷ�ڵ���ȣ�����ֵ�ۼӵ�ͷ�ڵ�*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*�����������ڵ��ͷ�ڵ��*/
	ioffPre=*pioffHead;
	ioffCur=*(*get_next)(ioffPre);
			 /*������� û�е�ĩβ*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*����һ�����������ݴ�Ľڵ�,�����ۼ�*/
                if(compr<0) break;
			/*��ֵ�߼���ȣ����ۼ�����*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*����ָ������ƶ�*/
		ioffPre=ioffCur;
		ioffCur=*(*get_next)(ioffPre);
	}
	/*λ��ȷ����ֻҪ���뼴��,����������ȥ�ڴ�*/

	InsertVEList((*get_next)(ioffPre),ioffValue,get_next);

	return FALSE;
}
/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchVEList(POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,POINTER),
	POINTER *(*get_next)(POINTER ))
{
	while(ioffHead!=-1){

		if((*comp_list)(pi,ioffHead)==0){
			*pioff=ioffHead;
			return FOUND;
		}
		ioffHead=*(*get_next)(ioffHead);
	}
	return NOTFOUND;
}

/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteVEList(POINTER *pioffHead,POINTER ioffValue,
	POINTER *(*get_next)(POINTER ))
{
	POINTER ioffPre,ioffCur;

	if(ioffValue==*pioffHead){
		*pioffHead=*(*get_next)(ioffValue);
		return TRUE;
	}


	ioffPre=*pioffHead;
	ioffCur=*(*get_next)(ioffPre);

	while(ioffCur!=-1){

		if(ioffValue==ioffCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			*(*get_next)(ioffPre)=*(*get_next)(ioffValue);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=*(*get_next)(ioffPre);
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
void ReverseVEList(void *pSeg,POINTER *pioffHead,
	POINTER *(*get_next)(POINTER ))
{
	POINTER ioffPre,ioffCur;
	
	ioffCur=*pioffHead;
	*pioffHead=-1;
	
	while(ioffCur!=-1){

		ioffPre=ioffCur;
		ioffCur=*(*get_next)(ioffPre);

		InsertVEList(pioffHead,ioffPre,get_next);
	}
}

/*ͳ������ڵ���Ŀ*/
int CountMList(MLIST* ptHead,int n)
{
	int iCount=0;

	while(ptHead!=NULL){
		ptHead=ptHead->pNext[n];
		iCount++;
	}

	return iCount;
}
/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelMList(MLIST *ptHead,int (*operate_list)(MLIST *),int n)
{
	int j,sum=0;

	MLIST *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext[n];
		if((j=(*operate_list)(pTemp))<0) return -1;
		sum+=j;
	}

	return sum;
}
/*ֱ�ӽ����ݲ���ͷ�ڵ�*/
void InsertMList(MLIST **pptHead,MLIST *p,int n)
{
	p->pNext[n]=	*pptHead;
	*pptHead=	p;
}
void InsertMListTail(MLIST **pptHead,MLIST *p,int n)
{	
	MLIST *ptHead=(*pptHead);
	if(ptHead==NULL){
		InsertMList(pptHead,p,n);
		return ;
	}
	while(ptHead->pNext[n]!=NULL) ptHead=ptHead->pNext[n];
	InsertMList((MLIST**)&(ptHead->pNext[n]),(MLIST*)p,n);
}
void AppendMListTail(MLIST **pptHead,MLIST *p,int n)
{	
	MLIST *ptHead=(*pptHead);
	if(ptHead==NULL){
		*pptHead=p;
		return ;
	}
	while(ptHead->pNext[n]!=NULL) ptHead=ptHead->pNext[n];
	ptHead->pNext[n]=p;
}
/*����comp_list�ǶԲ���ľ������,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	   */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)    */
/*�ú�����MLIST *p �������ⲿ������ڴ� */
void InsertMListSort(MLIST **pptHead,MLIST *p,
	int (*comp_list)(MLIST *,MLIST *),int n)
{
	MLIST *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL){
		InsertMList(pptHead,p,n);
		return ;
	}

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(p,*pptHead)<=0){
		InsertMList(pptHead,p,n);
		return ;
	}
		/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext[n];
			 /*������� û�е�ĩβ*/
	while(ptCur!=NULL){
			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(p,ptCur)<=0) break;
			/*����ָ������ƶ�*/
		ptPre=ptCur;
		ptCur=ptPre->pNext[n];
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	InsertMList(&(ptPre->pNext[n]),p,n);
}

/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����MLIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�MLIST�У��ڴ���ظ�����
*/
int InsertMListSumm(MLIST **pptHead,MLIST *p,
      int (*comp_list)(MLIST *,MLIST *),
      void (*sum_list)(MLIST *,MLIST *),int n)
{
	int compr;

	MLIST *ptPre,*ptCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pptHead==NULL){
		InsertMList(pptHead,p,n);
		return FALSE;
	}

	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(p,*pptHead);

        if(compr<0){
		InsertMList(pptHead,p,n);
		return FALSE;
	}

	/*��ͷ�ڵ���ȣ�����ֵ�ۼӵ�ͷ�ڵ�*/
        if(compr==0){
		(*sum_list)(*pptHead,p);
		return TRUE;
	}


		/*�����������ڵ��ͷ�ڵ��*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext[n];
			 /*������� û�е�ĩβ*/
	while(ptCur!=NULL){
		compr=(*comp_list)(p,ptCur);

			/*����һ�����������ݴ�Ľڵ�,�����ۼ�*/
                if(compr<0) break;
			/*��ֵ�߼���ȣ����ۼ�����*/
		if(compr==0){
			(*sum_list)(ptCur,p);
			return TRUE;
		}
			/*����ָ������ƶ�*/
		ptPre=ptCur;
		ptCur=ptPre->pNext[n];
	}
	/*λ��ȷ����ֻҪ���뼴��,����������ȥ�ڴ�*/

	InsertMList(&(ptPre->pNext[n]),p,n);

	return FALSE;
}
/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchMList(MLIST *ptHead,void *pi,MLIST **p,
	int (*comp_list)(void *,MLIST *),int n)
{
	while(ptHead!=NULL){
		if((*comp_list)(pi,ptHead)==0){
			*p=ptHead;
			return FOUND;
		}
	        ptHead=ptHead->pNext[n];
	}
	return NOTFOUND;
}

/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteMList(MLIST **pptHead,MLIST *p,int n)
{
	MLIST *ptPre,*ptCur;

	if(p==*pptHead){
		*pptHead=p->pNext[n];
		return TRUE;
	}

	ptPre=*pptHead;
	ptCur=ptPre->pNext[n];

	while(ptCur!=NULL){
		if(p==ptCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			ptPre->pNext[n]=p->pNext[n];
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=ptPre->pNext[n];
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
void DestroyMList(MLIST *ptHead,int n)
{
	MLIST *pTemp;

	while(ptHead!=NULL){
		pTemp=ptHead;
		ptHead=ptHead->pNext[n];
		hfree(pTemp,sizeof(MLIST));
	}
}
void ReverseMList(MLIST **pptHead,int n)
{
	MLIST *pPre,*pCur;
	
	pCur=*pptHead;
	*pptHead=NULL;
	
	while(pCur!=NULL){
		pPre=pCur;
		pCur=pCur->pNext[n];
		InsertMList(pptHead,pPre,n);
	}
}

/****��LIST��Ӧ��MEList���ڹ����ڴ�**/
/*ͳ������ڵ���Ŀ*/
int CountMEList(void *pSeg,POINTER ioffHead,int n)
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=MELISTNXT(pSeg,ioffHead,n);
		iCount++;
	}

	return iCount;
}
/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelMEList(void *pSeg,POINTER ioffHead,
	int (*operate_list)(POINTER),int n)
{
	int j,sum=0;

	POINTER ioffTmp;

	while(ioffHead!=-1){
		ioffTmp=ioffHead;
		ioffHead=MELISTNXT(pSeg,ioffHead,n);

		if((j=(*operate_list)(ioffTmp))<0) return -1;

		sum+=j;
	}

	return sum;
}
void InsertMEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n)
{
	MELISTNXT(pSeg,ioffValue,n)=(*pioffHead);
	(*pioffHead)= ioffValue;
}
void InsertMEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n)
{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return ;
	}

	while(MELISTNXT(pSeg,ioffHead,n)!=-1) ioffHead=MELISTNXT(pSeg,ioffHead,n);

	InsertMEList(pSeg,&MELISTNXT(pSeg,ioffHead,n),ioffValue,n);
}
void AppendMEListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n)
{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		*pioffHead=ioffValue;
		return ;
	}

	while(MELISTNXT(pSeg,ioffHead,n)!=-1)
		ioffHead=MELISTNXT(pSeg,ioffHead,n);

	MELISTNXT(pSeg,ioffHead,n)=ioffValue;
}
/*����comp_list�ǶԲ���ľ������,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	   */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)    */
/*�ú�����LIST *p �������ⲿ������ڴ� */
void InsertMEListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),int n)
{
	POINTER ioffPre,ioffCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffHead==-1){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return ;
	}

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(ioffValue,*pioffHead)<=0){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return ;
	}
		/*�����������ڵ��ͷ�ڵ��*/
	ioffPre=*pioffHead;
	ioffCur=MELISTNXT(pSeg,ioffPre,n);
			 /*������� û�е�ĩβ*/
	while(ioffCur!=-1){
			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(ioffValue,ioffCur)<=0) break;
			/*����ָ������ƶ�*/
		ioffPre=ioffCur;
		ioffCur=MELISTNXT(pSeg,ioffPre,n);
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	InsertMEList(pSeg,&(MELISTNXT(pSeg,ioffPre,n)),ioffValue,n);
}

/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����LIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�LIST�У��ڴ���ظ�����
*/
int InsertMEListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ),int n)
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffHead==-1){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return FALSE;
	}
	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return FALSE;
	}

	/*��ͷ�ڵ���ȣ�����ֵ�ۼӵ�ͷ�ڵ�*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*�����������ڵ��ͷ�ڵ��*/
	ioffPre=*pioffHead;
	ioffCur=MELISTNXT(pSeg,ioffPre,n);
			 /*������� û�е�ĩβ*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*����һ�����������ݴ�Ľڵ�,�����ۼ�*/
                if(compr<0) break;
			/*��ֵ�߼���ȣ����ۼ�����*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*����ָ������ƶ�*/
		ioffPre=ioffCur;
		ioffCur=MELISTNXT(pSeg,ioffPre,n);
	}
	/*λ��ȷ����ֻҪ���뼴��,����������ȥ�ڴ�*/

	InsertMEList(pSeg,&(MELISTNXT(pSeg,ioffPre,n)),ioffValue,n);

	return FALSE;
}
/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchMEList(void *pSeg,POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,void *,POINTER),int n)
{
	while(ioffHead!=-1){

		if((*comp_list)(pSeg,pi,ioffHead)==0){
			*pioff=ioffHead;
			return FOUND;
		}
		ioffHead=MELISTNXT(pSeg,ioffHead,n);
	}
	return NOTFOUND;
}

/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteMEList(void *pSeg,POINTER *pioffHead,POINTER ioffValue,int n)
{
	POINTER ioffPre,ioffCur;

	if(ioffValue==*pioffHead){
		*pioffHead=MELISTNXT(pSeg,ioffValue,n);
		return TRUE;
	}


	ioffPre=*pioffHead;
	ioffCur=MELISTNXT(pSeg,ioffPre,n);

	while(ioffCur!=-1){

		if(ioffValue==ioffCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			MELISTNXT(pSeg,ioffPre,n)=MELISTNXT(pSeg,ioffValue,n);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=MELISTNXT(pSeg,ioffPre,n);
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
void ReverseMEList(void *pSeg,POINTER *pioffHead,int n)
{
	POINTER ioffPre,ioffCur;
	
	ioffCur=*pioffHead;
	*pioffHead=-1;
	
	while(ioffCur!=-1){

		ioffPre=ioffCur;
		ioffCur=MELISTNXT(pSeg,ioffPre,n);

		InsertMEList(pSeg,pioffHead,ioffPre,n);
	}
}
/***********************************************************/
/*��鹲���ڴ�����*/
/***********************************************************/
POINTER PoFList(struct FMemStruct *p,void *pv)
{
	int i;
	for(i=0;i<FLISTMAX;i++)
		if(pv>=p->apHead[i]&&
			(char*)pv<((char*)p->apHead[i]+p->iBlockLen))break;
	if(i==FLISTMAX)return -1;
	return i*p->iBlockLen+((char*)pv-(char*)p->apHead[i]);
}
void *OpFList(struct FMemStruct *p,POINTER o)
{
	POINTER i;

	i=o/p->iBlockLen;

	if(i>=FLISTMAX)return NULL;
	return (char*)p->apHead[i]+o%p->iBlockLen;
}
/****��LIST��Ӧ��FList���ڹ����ڴ�**/
/*ͳ������ڵ���Ŀ*/
int CountFList(void *pSeg,POINTER ioffHead)
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=FLISTNXT(pSeg,ioffHead);
		iCount++;
	}

	return iCount;
}
/*����operate_list�ǶԵ����ڵ�Ĳ�������*/
/*�ú��������ÿ���ʵ�ִ�ӡ�ͷ��ڴ�Ȳ���*/
int TravelFList(void *pSeg,POINTER ioffHead,int (*operate_list)(POINTER))
{
	int j,sum=0;

	POINTER ioffTmp;

	while(ioffHead!=-1){
		ioffTmp=ioffHead;
		ioffHead=FLISTNXT(pSeg,ioffHead);

		if((j=(*operate_list)(ioffTmp))<0) return -1;

		sum+=j;
	}

	return sum;
}
void InsertFList(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{
	FLISTNXT(pSeg,ioffValue)=(*pioffHead);
	(*pioffHead)= ioffValue;
}
void InsertFListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		InsertFList(pSeg,pioffHead,ioffValue);
		return ;
	}

	while(FLISTNXT(pSeg,ioffHead)!=-1) ioffHead=FLISTNXT(pSeg,ioffHead);

	InsertFList(pSeg,&FLISTNXT(pSeg,ioffHead),ioffValue);
}
void AppendFListTail(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{	
	POINTER ioffHead=(*pioffHead);

	if(ioffHead==-1){
		*pioffHead=ioffValue;
		return ;
	}

	while(FLISTNXT(pSeg,ioffHead)!=-1) ioffHead=FLISTNXT(pSeg,ioffHead);

	FLISTNXT(pSeg,ioffHead)=ioffValue;
}
/*����comp_list�ǶԲ���ľ������,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	   */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)    */
/*�ú�����LIST *p �������ⲿ������ڴ� */
void InsertFListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ))
{
	POINTER ioffPre,ioffCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffHead==-1){
		InsertFList(pSeg,pioffHead,ioffValue);
		return ;
	}

	/*�������Ľڵ���С��������ǰ��*/
	if((*comp_list)(ioffValue,*pioffHead)<=0){
		InsertFList(pSeg,pioffHead,ioffValue);
		return ;
	}
		/*�����������ڵ��ͷ�ڵ��*/
	ioffPre=*pioffHead;
	ioffCur=FLISTNXT(pSeg,ioffPre);
			 /*������� û�е�ĩβ*/
	while(ioffCur!=-1){
			/*����һ�����������ݴ�Ľڵ�*/
		if((*comp_list)(ioffValue,ioffCur)<=0) break;
			/*����ָ������ƶ�*/
		ioffPre=ioffCur;
		ioffCur=FLISTNXT(pSeg,ioffPre);
	}
	/*λ��ȷ����ֻҪ���뼴��*/
	InsertFList(pSeg,&(FLISTNXT(pSeg,ioffPre)),ioffValue);
}

/*����comp_list�ǶԲ���ľ���Ƚϲ���,����������,ֻ����*/
/*comp_list����1������������2�����ڵ����� 	    */
/*sum_list ����1���ۼӵ��ⲿ���ݣ�����2�����ڵ����� */
/*�Բ���Ľڵ��pNextû��Ҫ��(�����ڲ��Զ���λ)     */
/*�ú�����LIST *p �������ⲿ������ڴ� */
/*����ֵ
	FALSE:û��SUM�����е������Ա���ⲿ�ڴ汻������ȥ
	TRUE :�ò�����ֵ��SUM�����е��ڴ�LIST�У��ڴ���ظ�����
*/
int InsertFListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ))
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*�ձ���ֱ�Ӳ���*/
	if(*pioffHead==-1){
		InsertFList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}
	/*�������Ľڵ���С��������ǰ��*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertFList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}

	/*��ͷ�ڵ���ȣ�����ֵ�ۼӵ�ͷ�ڵ�*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*�����������ڵ��ͷ�ڵ��*/
	ioffPre=*pioffHead;
	ioffCur=FLISTNXT(pSeg,ioffPre);
			 /*������� û�е�ĩβ*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*����һ�����������ݴ�Ľڵ�,�����ۼ�*/
                if(compr<0) break;
			/*��ֵ�߼���ȣ����ۼ�����*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*����ָ������ƶ�*/
		ioffPre=ioffCur;
		ioffCur=FLISTNXT(pSeg,ioffPre);
	}
	/*λ��ȷ����ֻҪ���뼴��,����������ȥ�ڴ�*/

	InsertFList(pSeg,&(FLISTNXT(pSeg,ioffPre)),ioffValue);

	return FALSE;
}

/*���� *pi��Ҫ���ҵ�����*search_list�ǲ�ѯƥ������*/
/*search_list����1�������ڵĵ���ITEM������2���ⲿ��������� */
int SearchFList(void *pSeg,POINTER ioffHead,void *pi,POINTER *pioff,
	int (*comp_list)(void *,POINTER))
{
	while(ioffHead!=-1){

		if((*comp_list)(pi,ioffHead)==0){
			*pioff=ioffHead;
			return FOUND;
		}
		ioffHead=FLISTNXT(pSeg,ioffHead);
	}
	return NOTFOUND;
}

/*���� *pҪɾ���ڵ��ָ��*/
/*������ֵ��
	TRUEɾ���� FALSEδɾ��*/
int DeleteFList(void *pSeg,POINTER *pioffHead,POINTER ioffValue)
{
	POINTER ioffPre,ioffCur;

	if(ioffValue==*pioffHead){
		*pioffHead=FLISTNXT(pSeg,ioffValue);
		return TRUE;
	}


	ioffPre=*pioffHead;
	ioffCur=FLISTNXT(pSeg,ioffPre);

	while(ioffCur!=-1){

		if(ioffValue==ioffCur) {
			/*�ҵ��ˣ�ֱ�������ýڵ�*/
			FLISTNXT(pSeg,ioffPre)=FLISTNXT(pSeg,ioffValue);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=FLISTNXT(pSeg,ioffPre);
	}
	/*�����ڸ�����û��ָ���ڵ�*/

	return FALSE;
}
void ReverseFList(void *pSeg,POINTER *pioffHead)
{
	POINTER ioffPre,ioffCur;
	
	ioffCur=*pioffHead;
	*pioffHead=-1;
	
	while(ioffCur!=-1){

		ioffPre=ioffCur;
		ioffCur=FLISTNXT(pSeg,ioffPre);

		InsertFList(pSeg,pioffHead,ioffPre);
	}
}

/*��ɰ�ĳ������*/
void InsertListE(POINTER *pioffsetHead,POINTER ioffsetValue,
	POINTER *(*get_next)(POINTER))
{
	InsertVEList(pioffsetHead,ioffsetValue,get_next);
}	
void InsertListSortE(POINTER *pioffsetHead,POINTER ioffsetValue,
	int (*comp_list)(POINTER ,POINTER ),POINTER *(*get_next)(POINTER ))
{
	InsertVEListSort(pioffsetHead,ioffsetValue,comp_list,get_next);
}
