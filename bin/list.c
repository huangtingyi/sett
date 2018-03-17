#include "hnixs.h"
#include "list.h"



/*统计链表节点数目*/
int CountList(LIST* ptHead)
{
	int iCount=0;

	while(ptHead!=NULL){
		ptHead=ptHead->pNext;
		iCount++;
	}

	return iCount;
}
/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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
/*直接将数据插入头节点*/
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
/*其中comp_list是对插入的具体操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	   */
/*对插入的节点的pNext没有要求(链表内部自动复位)    */
/*该函数的LIST *p 参数是外部分配的内存 */
void InsertListSort(LIST **pptHead,LIST *p,int (*comp_list)(LIST *,LIST *))
{
	LIST *ptPre,*ptCur;

	/*空表则直接插入*/
	if(*pptHead==NULL){
		InsertList(pptHead,p);
		return ;
	}

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(p,*pptHead)<=0){
		InsertList(pptHead,p);
		return ;
	}
		/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*如果链表 没有到末尾*/
	while(ptCur!=NULL){
			/*发现一个比输入数据大的节点*/
		if((*comp_list)(p,ptCur)<=0) break;
			/*链表指针向后移动*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*位置确定，只要插入即可*/
	InsertList(&(ptPre->pNext),p);
}

/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的LIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存LIST中，内存可重复利用
*/
int InsertListSumm(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *))
{
	int compr;

	LIST *ptPre,*ptCur;

	/*空表则直接插入*/
	if(*pptHead==NULL){
		InsertList(pptHead,p);
		return FALSE;
	}

	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(p,*pptHead);

        if(compr<0){
		InsertList(pptHead,p);
		return FALSE;
	}

	/*和头节点相等，将数值累加到头节点*/
        if(compr==0){
		(*sum_list)(*pptHead,p);
		return TRUE;
	}


		/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*如果链表 没有到末尾*/
	while(ptCur!=NULL){
		compr=(*comp_list)(p,ptCur);

			/*发现一个比输入数据大的节点,不能累加*/
                if(compr<0) break;
			/*数值逻辑相等，则累加数据*/
		if(compr==0){
			(*sum_list)(ptCur,p);
			return TRUE;
		}
			/*链表指针向后移动*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*位置确定，只要插入即可,插入链表用去内存*/

	InsertList(&(ptPre->pNext),p);

	return FALSE;
}
int InsertListSortSum(LIST **pptHead,LIST *p,
      int (*comp_list)(LIST *,LIST *),
      void (*sum_list)(LIST *,LIST *))
{
	return InsertListSumm(pptHead,p,comp_list,sum_list);
}
/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
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

/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
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
			/*找到了，直接跳过该节点*/
			ptPre->pNext=p->pNext;
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*链表内根本就没有指定节点*/

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
			/*找到了，直接跳过该节点*/
			ptPre->pNext=p->pNext;
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*链表内根本就没有指定节点*/

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

	/*空表则直接插入*/
	if(*pptHead==NULL)
		return InsertLink(pptHead,p,pTemp);

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(p,(*pptHead)->pData)<=0)
		return InsertLink(pptHead,p,pTemp);

		/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*如果链表 没有到末尾*/
	while(ptCur!=NULL){
			/*发现一个比输入数据大的节点*/
		if((*comp_list)(p,ptCur->pData)<=0) break;
			/*链表指针向后移动*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}

	/*位置确定，只要插入即可???*/
	return InsertLink(&(ptPre->pNext),p,pTemp);
}
int4b InsertLinkSumm(LINK **pptHead, void *p,
	int4b ( *comp_list)(void *,void *),
	void ( *sum_list)(void *,void *),LINK **ppTemp)
{
	int4b compr;

	LINK *ptPre,*ptCur;

	/*空表则直接插入*/
	if(*pptHead==NULL){

		if(InsertLink(pptHead,p,*ppTemp)<0) return -1;
		*ppTemp=NULL;
		return 0;
	}

	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(p,(*pptHead)->pData);

        if(compr<0){
		if(InsertLink(pptHead,p,*ppTemp)<0) return -1;
		*ppTemp=NULL;
		return 0;
	}

	/*和头节点相等，将数值累加到头节点*/
        if(compr==0){
		(*sum_list)((*pptHead)->pData,p);
		return 0;
	}


		/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext;
			 /*如果链表 没有到末尾*/
	while(ptCur!=NULL){
		compr=(*comp_list)(p,ptCur->pData);

			/*发现一个比输入数据大的节点,不能累加*/
                if(compr<0) break;
			/*数值逻辑相等，则累加数据*/
		if(compr==0){
			(*sum_list)(ptCur->pData,p);
			return 0;
		}
			/*链表指针向后移动*/
		ptPre=ptCur;
		ptCur=ptPre->pNext;
	}
	/*位置确定，只要插入即可,插入链表用去内存*/

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

/****与LIST对应的EList用于共享内存**/
/*统计链表节点数目*/
int CountEList(void *pSeg,POINTER ioffHead)
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=ELISTNXT(pSeg,ioffHead);
		iCount++;
	}

	return iCount;
}
/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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
/*其中comp_list是对插入的具体操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	   */
/*对插入的节点的pNext没有要求(链表内部自动复位)    */
/*该函数的LIST *p 参数是外部分配的内存 */
void InsertEListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ))
{
	POINTER ioffPre,ioffCur;

	/*空表则直接插入*/
	if(*pioffHead==-1){
		InsertEList(pSeg,pioffHead,ioffValue);
		return ;
	}

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(ioffValue,*pioffHead)<=0){
		InsertEList(pSeg,pioffHead,ioffValue);
		return ;
	}
		/*这里表明输入节点比头节点大*/
	ioffPre=*pioffHead;
	ioffCur=ELISTNXT(pSeg,ioffPre);
			 /*如果链表 没有到末尾*/
	while(ioffCur!=-1){
			/*发现一个比输入数据大的节点*/
		if((*comp_list)(ioffValue,ioffCur)<=0) break;
			/*链表指针向后移动*/
		ioffPre=ioffCur;
		ioffCur=ELISTNXT(pSeg,ioffPre);
	}
	/*位置确定，只要插入即可*/
	InsertEList(pSeg,&(ELISTNXT(pSeg,ioffPre)),ioffValue);
}

/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的LIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存LIST中，内存可重复利用
*/
int InsertEListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ))
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*空表则直接插入*/
	if(*pioffHead==-1){
		InsertEList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}
	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertEList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}

	/*和头节点相等，将数值累加到头节点*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*这里表明输入节点比头节点大*/
	ioffPre=*pioffHead;
	ioffCur=ELISTNXT(pSeg,ioffPre);
			 /*如果链表 没有到末尾*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*发现一个比输入数据大的节点,不能累加*/
                if(compr<0) break;
			/*数值逻辑相等，则累加数据*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*链表指针向后移动*/
		ioffPre=ioffCur;
		ioffCur=ELISTNXT(pSeg,ioffPre);
	}
	/*位置确定，只要插入即可,插入链表用去内存*/

	InsertEList(pSeg,&(ELISTNXT(pSeg,ioffPre)),ioffValue);

	return FALSE;
}

/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
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

/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
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
			/*找到了，直接跳过该节点*/
			ELISTNXT(pSeg,ioffPre)=ELISTNXT(pSeg,ioffValue);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=ELISTNXT(pSeg,ioffPre);
	}
	/*链表内根本就没有指定节点*/

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

/**********普通内存中抽象链表******/
/***************************************************/
/********	指针扩展链表		*******/
/********	指针扩展链表		*******/
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

	/*空表则直接插入*/
	if(*pptHead==NULL){
		InsertVList(pptHead,pValue,get_next);
		return ;
	}

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(pValue,*pptHead)<=0){
		InsertVList(pptHead,pValue,get_next);
		return ;
	}
			/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=*(*get_next)(ptPre);
			 /*如果链表 没有到末尾*/

	while(ptCur!=NULL){

			/*发现一个比输入数据大的节点*/
		if((*comp_list)(pValue,ptCur)<=0) break;
			/*链表指针向后移动*/

		ptPre=ptCur;
		ptCur=*(*get_next)(ptPre);
	}
	/*位置确定，只要插入即可*/
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

	/*空表则直接插入*/
	if(*pptHead==NULL){
		InsertVList(pptHead,pValue,get_next);
		return false;
	}

	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(pValue,*pptHead);
	
	if(compr<0){
		InsertVList(pptHead,pValue,get_next);
		return false;
	}
	
	if(compr==0){
		sum_list(*pptHead,pValue);
		return true;
	}
			/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=*(*get_next)(ptPre);
			 /*如果链表 没有到末尾*/

	while(ptCur!=NULL){

			/*发现一个比输入数据大的节点*/
		compr=(*comp_list)(pValue,ptCur);
		
		if(compr<0) break;
		if(compr==0){
			sum_list(ptCur,pValue);
			return true;
		}
		/*链表指针向后移动*/
		ptPre=ptCur;
		ptCur=*(*get_next)(ptPre);
	}
	/*位置确定，只要插入即可*/
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
			/*找到了，直接跳过该节点*/
			(*assign_list)(ptPre,p);
/*			ptPre->pNext=p->pNext;*/
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=*(*getnext)(ptPre);
/*		ptCur=ptPre->pNext;*/
	}
	/*链表内根本就没有指定节点*/

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
/**共享内存抽象链表***********/
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

	/*空表则直接插入*/
	if(*pioffsetHead==-1){

		*(*get_next)(ioffsetValue)=-1;
		*pioffsetHead=ioffsetValue;
		return ;
	}

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(ioffsetValue,*pioffsetHead)<=0){

		*(*get_next)(ioffsetValue)=*pioffsetHead;
		*pioffsetHead=ioffsetValue;
		return ;
	}
		/*这里表明输入节点比头节点大*/
	ioffsetPre=*pioffsetHead;
	ioffsetCur=*(*get_next)(*pioffsetHead);

			 /*如果链表 没有到末尾*/
	while(ioffsetCur != -1){

			/*发现一个比输入数据大的节点*/
		if((*comp_list)(ioffsetValue,ioffsetCur)<=0) break;

			/*链表指针向后移动*/
		ioffsetPre=ioffsetCur;
		ioffsetCur=*(*get_next)(ioffsetCur);
	}
	/*位置确定，只要插入即可*/
	*(*get_next)(ioffsetPre)=	ioffsetValue;
	*(*get_next)(ioffsetValue)=	ioffsetCur;
}

/****与LIST对应的EList用于共享内存**/
/*统计链表节点数目*/
int CountVEList(POINTER ioffHead,POINTER *(*get_next)(POINTER))
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=*(*get_next)(ioffHead);
		iCount++;
	}
	return iCount;
}
/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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
/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的LIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存LIST中，内存可重复利用
*/
int InsertVEListSumm(POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ),
	POINTER *(*get_next)(POINTER ) )
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*空表则直接插入*/
	if(*pioffHead==-1){
		InsertVEList(pioffHead,ioffValue,get_next);
		return FALSE;
	}
	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertVEList(pioffHead,ioffValue,get_next);
		return FALSE;
	}

	/*和头节点相等，将数值累加到头节点*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*这里表明输入节点比头节点大*/
	ioffPre=*pioffHead;
	ioffCur=*(*get_next)(ioffPre);
			 /*如果链表 没有到末尾*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*发现一个比输入数据大的节点,不能累加*/
                if(compr<0) break;
			/*数值逻辑相等，则累加数据*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*链表指针向后移动*/
		ioffPre=ioffCur;
		ioffCur=*(*get_next)(ioffPre);
	}
	/*位置确定，只要插入即可,插入链表用去内存*/

	InsertVEList((*get_next)(ioffPre),ioffValue,get_next);

	return FALSE;
}
/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
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

/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
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
			/*找到了，直接跳过该节点*/
			*(*get_next)(ioffPre)=*(*get_next)(ioffValue);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=*(*get_next)(ioffPre);
	}
	/*链表内根本就没有指定节点*/

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

/*统计链表节点数目*/
int CountMList(MLIST* ptHead,int n)
{
	int iCount=0;

	while(ptHead!=NULL){
		ptHead=ptHead->pNext[n];
		iCount++;
	}

	return iCount;
}
/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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
/*直接将数据插入头节点*/
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
/*其中comp_list是对插入的具体操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	   */
/*对插入的节点的pNext没有要求(链表内部自动复位)    */
/*该函数的MLIST *p 参数是外部分配的内存 */
void InsertMListSort(MLIST **pptHead,MLIST *p,
	int (*comp_list)(MLIST *,MLIST *),int n)
{
	MLIST *ptPre,*ptCur;

	/*空表则直接插入*/
	if(*pptHead==NULL){
		InsertMList(pptHead,p,n);
		return ;
	}

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(p,*pptHead)<=0){
		InsertMList(pptHead,p,n);
		return ;
	}
		/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext[n];
			 /*如果链表 没有到末尾*/
	while(ptCur!=NULL){
			/*发现一个比输入数据大的节点*/
		if((*comp_list)(p,ptCur)<=0) break;
			/*链表指针向后移动*/
		ptPre=ptCur;
		ptCur=ptPre->pNext[n];
	}
	/*位置确定，只要插入即可*/
	InsertMList(&(ptPre->pNext[n]),p,n);
}

/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的MLIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存MLIST中，内存可重复利用
*/
int InsertMListSumm(MLIST **pptHead,MLIST *p,
      int (*comp_list)(MLIST *,MLIST *),
      void (*sum_list)(MLIST *,MLIST *),int n)
{
	int compr;

	MLIST *ptPre,*ptCur;

	/*空表则直接插入*/
	if(*pptHead==NULL){
		InsertMList(pptHead,p,n);
		return FALSE;
	}

	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(p,*pptHead);

        if(compr<0){
		InsertMList(pptHead,p,n);
		return FALSE;
	}

	/*和头节点相等，将数值累加到头节点*/
        if(compr==0){
		(*sum_list)(*pptHead,p);
		return TRUE;
	}


		/*这里表明输入节点比头节点大*/
	ptPre=*pptHead;
	ptCur=ptPre->pNext[n];
			 /*如果链表 没有到末尾*/
	while(ptCur!=NULL){
		compr=(*comp_list)(p,ptCur);

			/*发现一个比输入数据大的节点,不能累加*/
                if(compr<0) break;
			/*数值逻辑相等，则累加数据*/
		if(compr==0){
			(*sum_list)(ptCur,p);
			return TRUE;
		}
			/*链表指针向后移动*/
		ptPre=ptCur;
		ptCur=ptPre->pNext[n];
	}
	/*位置确定，只要插入即可,插入链表用去内存*/

	InsertMList(&(ptPre->pNext[n]),p,n);

	return FALSE;
}
/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
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

/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
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
			/*找到了，直接跳过该节点*/
			ptPre->pNext[n]=p->pNext[n];
			return TRUE;
		}
		ptPre=ptCur;
		ptCur=ptPre->pNext[n];
	}
	/*链表内根本就没有指定节点*/

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

/****与LIST对应的MEList用于共享内存**/
/*统计链表节点数目*/
int CountMEList(void *pSeg,POINTER ioffHead,int n)
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=MELISTNXT(pSeg,ioffHead,n);
		iCount++;
	}

	return iCount;
}
/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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
/*其中comp_list是对插入的具体操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	   */
/*对插入的节点的pNext没有要求(链表内部自动复位)    */
/*该函数的LIST *p 参数是外部分配的内存 */
void InsertMEListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),int n)
{
	POINTER ioffPre,ioffCur;

	/*空表则直接插入*/
	if(*pioffHead==-1){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return ;
	}

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(ioffValue,*pioffHead)<=0){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return ;
	}
		/*这里表明输入节点比头节点大*/
	ioffPre=*pioffHead;
	ioffCur=MELISTNXT(pSeg,ioffPre,n);
			 /*如果链表 没有到末尾*/
	while(ioffCur!=-1){
			/*发现一个比输入数据大的节点*/
		if((*comp_list)(ioffValue,ioffCur)<=0) break;
			/*链表指针向后移动*/
		ioffPre=ioffCur;
		ioffCur=MELISTNXT(pSeg,ioffPre,n);
	}
	/*位置确定，只要插入即可*/
	InsertMEList(pSeg,&(MELISTNXT(pSeg,ioffPre,n)),ioffValue,n);
}

/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的LIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存LIST中，内存可重复利用
*/
int InsertMEListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ),int n)
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*空表则直接插入*/
	if(*pioffHead==-1){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return FALSE;
	}
	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertMEList(pSeg,pioffHead,ioffValue,n);
		return FALSE;
	}

	/*和头节点相等，将数值累加到头节点*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*这里表明输入节点比头节点大*/
	ioffPre=*pioffHead;
	ioffCur=MELISTNXT(pSeg,ioffPre,n);
			 /*如果链表 没有到末尾*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*发现一个比输入数据大的节点,不能累加*/
                if(compr<0) break;
			/*数值逻辑相等，则累加数据*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*链表指针向后移动*/
		ioffPre=ioffCur;
		ioffCur=MELISTNXT(pSeg,ioffPre,n);
	}
	/*位置确定，只要插入即可,插入链表用去内存*/

	InsertMEList(pSeg,&(MELISTNXT(pSeg,ioffPre,n)),ioffValue,n);

	return FALSE;
}
/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
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

/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
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
			/*找到了，直接跳过该节点*/
			MELISTNXT(pSeg,ioffPre,n)=MELISTNXT(pSeg,ioffValue,n);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=MELISTNXT(pSeg,ioffPre,n);
	}
	/*链表内根本就没有指定节点*/

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
/*多块共享内存链表*/
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
/****与LIST对应的FList用于共享内存**/
/*统计链表节点数目*/
int CountFList(void *pSeg,POINTER ioffHead)
{
	int iCount=0;

	while(ioffHead!=-1){
		ioffHead=FLISTNXT(pSeg,ioffHead);
		iCount++;
	}

	return iCount;
}
/*其中operate_list是对单个节点的操作函数*/
/*该函数很有用可以实现打印释放内存等操作*/
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
/*其中comp_list是对插入的具体操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	   */
/*对插入的节点的pNext没有要求(链表内部自动复位)    */
/*该函数的LIST *p 参数是外部分配的内存 */
void InsertFListSort(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ))
{
	POINTER ioffPre,ioffCur;

	/*空表则直接插入*/
	if(*pioffHead==-1){
		InsertFList(pSeg,pioffHead,ioffValue);
		return ;
	}

	/*如果插入的节点最小，放在最前面*/
	if((*comp_list)(ioffValue,*pioffHead)<=0){
		InsertFList(pSeg,pioffHead,ioffValue);
		return ;
	}
		/*这里表明输入节点比头节点大*/
	ioffPre=*pioffHead;
	ioffCur=FLISTNXT(pSeg,ioffPre);
			 /*如果链表 没有到末尾*/
	while(ioffCur!=-1){
			/*发现一个比输入数据大的节点*/
		if((*comp_list)(ioffValue,ioffCur)<=0) break;
			/*链表指针向后移动*/
		ioffPre=ioffCur;
		ioffCur=FLISTNXT(pSeg,ioffPre);
	}
	/*位置确定，只要插入即可*/
	InsertFList(pSeg,&(FLISTNXT(pSeg,ioffPre)),ioffValue);
}

/*其中comp_list是对插入的具体比较操作,的排序条件,只做升*/
/*comp_list参数1被比数，参数2链表内的数据 	    */
/*sum_list 参数1被累加的外部数据，参数2链表内的数据 */
/*对插入的节点的pNext没有要求(链表内部自动复位)     */
/*该函数的LIST *p 参数是外部分配的内存 */
/*返回值
	FALSE:没有SUM上已有的链表成员，外部内存被链表用去
	TRUE :该部分数值被SUM到已有的内存LIST中，内存可重复利用
*/
int InsertFListSumm(void *pSeg,POINTER *pioffHead,POINTER ioffValue,
	int (*comp_list)(POINTER ,POINTER ),
      void (*sum_list)(POINTER ,POINTER ))
{
	int compr;

	POINTER ioffPre,ioffCur;

	/*空表则直接插入*/
	if(*pioffHead==-1){
		InsertFList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}
	/*如果插入的节点最小，放在最前面*/
	compr=(*comp_list)(ioffValue,*pioffHead);

        if(compr<0){
		InsertFList(pSeg,pioffHead,ioffValue);
		return FALSE;
	}

	/*和头节点相等，将数值累加到头节点*/
        if(compr==0){
		(*sum_list)(*pioffHead,ioffValue);
		return TRUE;
	}


		/*这里表明输入节点比头节点大*/
	ioffPre=*pioffHead;
	ioffCur=FLISTNXT(pSeg,ioffPre);
			 /*如果链表 没有到末尾*/
	while(ioffCur!=-1){

		compr=(*comp_list)(ioffValue,ioffCur);

			/*发现一个比输入数据大的节点,不能累加*/
                if(compr<0) break;
			/*数值逻辑相等，则累加数据*/
		if(compr==0){
			(*sum_list)(ioffCur,ioffValue);
			return TRUE;
		}
			/*链表指针向后移动*/
		ioffPre=ioffCur;
		ioffCur=FLISTNXT(pSeg,ioffPre);
	}
	/*位置确定，只要插入即可,插入链表用去内存*/

	InsertFList(pSeg,&(FLISTNXT(pSeg,ioffPre)),ioffValue);

	return FALSE;
}

/*其中 *pi是要查找的数据*search_list是查询匹配条件*/
/*search_list参数1是链表内的单个ITEM，参数2是外部输入的数据 */
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

/*其中 *p要删除节点的指针*/
/*返回数值：
	TRUE删除了 FALSE未删除*/
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
			/*找到了，直接跳过该节点*/
			FLISTNXT(pSeg,ioffPre)=FLISTNXT(pSeg,ioffValue);
			return TRUE;
		}
		
		ioffPre=ioffCur;
		ioffCur=FLISTNXT(pSeg,ioffPre);
	}
	/*链表内根本就没有指定节点*/

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

/*与旧版的程序兼容*/
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
