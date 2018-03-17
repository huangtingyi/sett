#include "hnixs.h"
#include "trie.h"

/*��̬����������*/
static int aigCharAnti[256]=
{
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5
};


TRIE * MallocTrie()
{
	int4b i;
	TRIE *pTemp;

	if((pTemp=(TRIE*)hmalloc(sizeof(TRIE)) )==NULL) return NULL;

	for(i=0;i<10;i++){
		pTemp->pNext[i]=NULL;
		pTemp->pData[i]=NULL;
	}

	return pTemp;

}

int4b InsertTrie(TRIE **pptHead,char key[], void *pValue,void (*pAssign)(void **,void *))
{
	TRIE *ptCur,*ptPre;
	int i,offset,iStringLen_1,j=0;
	
	if(*pptHead==NULL) {
		
		if((*pptHead=MallocTrie())==NULL) return -1;
		j++;        	    
	}    
	
	ptCur=ptPre=*pptHead;
	iStringLen_1=strlen(key)-1;   

	for(i=0;i<iStringLen_1;i++){
		
		offset=aigCharAnti[(unsigned char )key[i]];
	    
		if((ptCur=ptPre->pNext[offset])==NULL){	    	
	    		if((ptCur=MallocTrie())==NULL) return -j-1;
			j++;
	    		ptPre->pNext[offset]=ptCur;
	    	}
	    
		ptPre=ptCur;          
	}
	
	offset=aigCharAnti[(unsigned char )key[i]];
	
	/*����Һ���������쳣 2000-02-18 17*/
	(*pAssign)(&(ptCur->pData[offset]),pValue);
	return j;
}
void assign_insert_trie(void **ppData,void *pData)
{
	InsertList((LIST**)(ppData), (LIST*)pData);
}
void** GetTrieLk(TRIE *ptHead,char key[])
{
	unsigned char *pts;
	int iStringLen,offset;
	TRIE *ptCur,*ptPre;

	pts=(unsigned char *)&key[0];
	
	if(ptHead==NULL||(iStringLen= strlen(key))==0) return NULL;

	ptCur=ptPre=ptHead;
	
	while(iStringLen-->0){
		
		   /* �����ֵ�����в�����*/
		if(ptCur==NULL)	return NULL;

		offset=aigCharAnti[*pts++];
		
		ptPre=ptCur;
		ptCur=ptCur->pNext[offset];
	}
	
	pts--;
	offset=aigCharAnti[*pts];
		
	return &(ptPre->pData[offset]);
}
/*
���ܣ��ͷż����е����������ڴ�
����ֵ ���ͷŵ��Ľڵ����
*/
int4b DestroyTrie(TRIE *ptHead)
{
	int4b i,j=0;
	
	if(ptHead==NULL) return 0;
	
	for(i=0;i<10;i++){
		if(ptHead->pNext[i]!=NULL) 
			j+=DestroyTrie(ptHead->pNext[i]);
	}			
	    
	hfree(ptHead,sizeof(TRIE));
	
	return ++j;
}
/*
���ܣ�	�����������ƥ��
������	TRIE *ptHead Ŀ�����ͷָ��
	char key[]��ֵ
	void **pptCur �������ݲ�������ͷָ��
����ֵ��NOTFOUND û�ҵ�
	FOUND	 �ҵ���	
*/
int4b SearchTrie(TRIE *ptHead,char key[], void **pptCur)
{
	unsigned char *pts;
	int4b  iStringLen,offset;
	TRIE *ptCur;
	
	*pptCur=NULL;

	if(ptHead==NULL||(iStringLen=strlen(key))==0) return NOTFOUND;

	pts=(unsigned char *)(&key[0]);
	
	ptCur=ptHead;
	
	while(iStringLen-->0){
		
		if(ptCur==NULL)  break;
		
		offset=aigCharAnti[*pts++];
	
		if(ptCur->pData[offset]!=NULL)
	        	*pptCur=ptCur->pData[offset];
	
		ptCur=ptCur->pNext[offset];
	}
	
	if(*pptCur==NULL) return NOTFOUND;
	return FOUND;
}
/*
���ܣ�	����������ȫƥ��
������	TRIE *ptHead Ŀ�����ͷָ��
	char key[]��ֵ
	void **pptCur �������ݲ�������ͷָ��
����ֵ��NOTFOUND û�ҵ�
	FOUND	 �ҵ���	
*/
int4b SearchTrieF(TRIE *ptHead,char key[], void **pptCur)
{
	unsigned char *pts;
	int4b  iStringLen,offset;
	TRIE *ptCur;
	
	*pptCur=NULL;

	if(ptHead==NULL||(iStringLen=strlen(key))==0) return NOTFOUND;

	pts=(unsigned char *)(&key[0]);

	ptCur=ptHead;
	
	while(iStringLen>0){

		iStringLen--;

		offset=aigCharAnti[*pts++];
	
		if(ptCur->pNext[offset]==NULL) break;
			
		ptCur=ptCur->pNext[offset];
		
	}
	
	*pptCur=ptCur->pData[offset];	
	
	if(*pptCur==NULL||iStringLen!=0) return NOTFOUND;
	return FOUND;
}
/*
���ܣ�	����������ÿһ����������ͬʱ�������������ָ������
������	����ͷָ��
	��ÿһ����������Ĳ�������
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int4b TravelTrieD(TRIE *ptHead, int ( *pTravelOper)(void **))
{
	int4b i,j=0,k;

	if(ptHead==NULL) return 0;

	for(i=0;i<10;i++){
		if((k=TravelTrie(ptHead->pNext[i],pTravelOper))<0) return -1;
		j+=k;	
		if(ptHead->pData[i]!=NULL) {			
			if((k=(*pTravelOper)(&(ptHead->pData[i])))<0) return -1;
			j+=k;
		}	
	}
	return j;
}
int4b TravelTrie(TRIE *ptHead, int ( *pTravelOper)(void **))
{
	return TravelTrieD(ptHead,pTravelOper);
}
/*
���ܣ�	����������ÿһ�������ڵ����ָ������
������	����ͷָ��
	��ÿһ���������ƽڵ��������
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int4b TravelTrieN(TRIE *ptHead,int (*pTravelOper)(TRIE *))
{
	int i,j=0;

	if(ptHead==NULL) return 0;

	for(i=0;i<10;i++)
		j+=TravelTrieNode(ptHead->pNext[i],pTravelOper);

	j+=(*pTravelOper)(ptHead);

	return j;
}
int4b TravelTrieNode(TRIE *ptHead,int (*pTravelOper)(TRIE *))
{
	return TravelTrieN(ptHead,pTravelOper);
}
void DeleteTrie(TRIE **pptHead,char key[], void **pptCur)
{
	unsigned char *pts;
	int4b  iStringLen,offset,sp=0,l;
	TRIE *ptCur,*ptHead=*pptHead;
	TRIE *apTrieStack[100];

	if(ptHead==NULL||(iStringLen=strlen(key))==0) return;

	pts=(unsigned char *)(&key[0]);
	
	ptCur=ptHead;

	l=iStringLen-1;

	while(iStringLen-->0){
		
		if(ptCur==NULL)  break;
		
		offset=aigCharAnti[*pts++];
	
		if(ptCur->pData[offset]!=NULL)
	        	*pptCur=ptCur->pData[offset];

		apTrieStack[sp++]=ptCur;	/*ָ����ջ*/

		ptCur=ptCur->pNext[offset];
	}

	/*û��ƥ��Ĵ�*/	
	if(iStringLen!=0) return;

	/*Ҷ�ӽڵ��ջ������ָ��������Ϊ��*/
	ptCur=apTrieStack[--sp];
	ptCur->pData[offset]=	NULL;

	/*ɾ��Ҷ�ӽڵ�Ϊ�յ������ڵ�*/
	while(l-->0 && TrieEmpty(ptCur)){

		if(ptCur==*pptHead) *pptHead=NULL;

		hfree(ptCur,sizeof(TRIE));

		offset=aigCharAnti[pts[l]];
		ptCur=apTrieStack[--sp];
		ptCur->pNext[offset]=NULL;

	}	
}

int4b TrieEmpty(TRIE *ptHead)
{
	int i;
	for(i=0;i<10;i++)
		if(ptHead->pData[i]!=NULL||
			ptHead->pNext[i]!=NULL) return FALSE;
	return TRUE;
}
void ReHookTrie(TRIE *pRoot,TRIE *ptHead)
{
	int	i,j;
	char	sTemp[200];
	void	**ppTemp;
	static	int l=0;
	static char key[200];
	
	if(ptHead==NULL) return;
	
	for(i=0;i<10;i++){
		if(ptHead->pNext[i]!=NULL){
			key[l++]='0'+i;key[l]=0;
			ReHookTrie(pRoot,ptHead->pNext[i]);
			key[--l]=0;
		}
		if(ptHead->pData[i]!=NULL){
			j=l;
			
			while(j>0){
				strncpy(sTemp,key,j);sTemp[j]=0;
				ppTemp=GetTrieLk(pRoot,sTemp);
				if(ppTemp==NULL) break;
				if((*ppTemp)!=NULL){
					AppendListTail((LIST**)&(ptHead->pData[i]),
						(LIST*)(*ppTemp));
					break;

				}
				j--;
			}
		}
	}
}

/*****************��չ�����㷨******************/

POINTER MallocETrie(void *pNodeSeg,struct ShmCtrlStruct *ptHead)
{
	int i;
	ETRIE *pTrie;
	POINTER ioffsetTemp;
 
	if((ioffsetTemp=MallocEItem(pNodeSeg,ptHead))==-1) return -1;
	
	pTrie=OPETRIE(pNodeSeg,ioffsetTemp);

	for (i=0;i<10;i++){
		pTrie->ioffNxt[i] = -1;
		pTrie->ioffDat[i] = -1;
	}

	return ioffsetTemp;
}
/*"���������ַ�������coredumpΣ��!!!"*/
/*pAssign��ֵ�������е�����ȫ�ֵ�������---�����ݶε�ַOK*/
int  InsertETrie(void *pNodeSeg,POINTER *pioffsetHead,
	char key[],struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
        void (*pAssign)(POINTER*,POINTER/*����ƫ��*/)) /*��չģʽ������*/
{
	ETRIE *ptCur,*ptPre;
	POINTER ioffsetPreLkHead;
	int i,offset,iStringLen_1,j=0;
	
	if(*pioffsetHead==-1){/*ͷ�ڵ�Ϊ��*/
		if((*pioffsetHead=MallocETrie(pNodeSeg,pShmCtrl))==-1)
			return -1; /*�����ڴ�ʧ��*/
		j++;
	}
	/*������*ioffsetHead�Ѿ�����Ч���±�*/
	ptPre=ptCur=OPETRIE(pNodeSeg,(*pioffsetHead));

        iStringLen_1=strlen(key)-1;

	for(i=0;i<iStringLen_1;i++){

                offset=aigCharAnti[(unsigned char )key[i]];

                if(ptPre->ioffDat[offset]!=-1)
                        ioffsetPreLkHead=ptPre->ioffDat[offset];

		if(ptPre->ioffNxt[offset]==-1){
			if((ptPre->ioffNxt[offset]=MallocETrie(pNodeSeg,
				pShmCtrl))==-1)	return -j-1; /*�����ڴ�ʧ��*/
			j++;  /*����Ľڵ���+1*/
		}
		/*�����ڴ�ָ��*/
		ptCur=OPETRIE(pNodeSeg,ptPre->ioffNxt[offset]);
		ptPre=ptCur;
	}
	offset=aigCharAnti[(unsigned char)key[i]];
	(*pAssign)(&(ptCur->ioffDat[offset]),ioffValue);
	
	return j;
}

/*��ȫƥ��
����ioffsetHead,pNodeSeg������Ч������coredump U*/

int SearchETrie(void *pNodeSeg,POINTER ioffsetHead,char key[],POINTER *pioffsetCur)
{
        unsigned char *pts;
        int  iStringLen,offset;
        ETRIE *ptCur;

/*��Ϊ�ջ������ֵΪ����û�ҵ�*/
	if(ioffsetHead==-1||(iStringLen=strlen(key))==0) return NOTFOUND;

	*pioffsetCur=-1;

        pts=(unsigned char *)(&key[0]);
	
	ptCur=OPETRIE(pNodeSeg,ioffsetHead);
	
        while(iStringLen>0){

		iStringLen--;

                offset=aigCharAnti[*pts++];

                if(ptCur->ioffDat[offset]!=-1)
			*pioffsetCur=ptCur->ioffDat[offset];

		/*��һ���Ѿ�û����֦�ˣ��˳���*/
		if(ptCur->ioffNxt[offset]==-1) break;

		ptCur=OPETRIE(pNodeSeg,ptCur->ioffNxt[offset]);
	}
	if(*pioffsetCur==-1) return NOTFOUND;
	return FOUND;
}

/*�ó��������ĳ�����ͬ��Ϊ���Ч��д2������*/
POINTER *GetETrieLk(void *pNodeSeg,POINTER ioffsetHead,char key[])
{

	POINTER *pioffsetCur=NULL;

        unsigned char *pts;
        int  iStringLen,offset;
        ETRIE *ptCur;

/*��Ϊ�ջ������ֵΪ����û�ҵ�*/
	if(ioffsetHead==-1||(iStringLen=strlen(key))==0) return NULL;

        pts=(unsigned char *)(&key[0]);
	
	ptCur=OPETRIE(pNodeSeg,ioffsetHead);
	
        while(iStringLen>0){

		iStringLen--;

                offset=aigCharAnti[*pts++];

                if(ptCur->ioffDat[offset]!=-1)
			pioffsetCur=&(ptCur->ioffDat[offset]);

		/*��һ���Ѿ�û����֦�ˣ��˳���*/
		if(ptCur->ioffNxt[offset]==-1) break;

		ptCur=OPETRIE(pNodeSeg,ptCur->ioffNxt[offset]);
	}

	return iStringLen==0?pioffsetCur:(POINTER *)NULL;
}

/*
���ܣ�  ����������ÿ�ڵ㣬ͬʱ�������������ָ������
������  ����ͷָ��ƫ�ƣ��ε�ַ
	��ÿһ��NODE�ڵ����һ�������ͷ��ڴ�
ע�⣺
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int TravelETrieN(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(ETRIE * ))
{
        int i,j=0;

	ETRIE *ptHead;

        if(ioffsetHead==-1) return 0;
	
	ptHead=OPETRIE(pNodeSeg,ioffsetHead);

        for(i=0;i<10;i++)				
                j+=TravelETrieN(pNodeSeg,ptHead->ioffNxt[i],pTravelOper);

        j+=(*pTravelOper)(ptHead);

        return j;
}

/*
���ܣ�  ����������ÿһ����������ͬʱ�������������ָ������
������  ����ͷָ��ƫ�ƣ��ε�ַ
	��ÿһ����������Ĳ�������
ע�⣺
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int TravelETrieD(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER * ))
{
        int i,j=0;

	ETRIE *ptHead;

        if(ioffsetHead==-1) return 0;
	
	ptHead=OPETRIE(pNodeSeg,ioffsetHead);

        for(i=0;i<10;i++){
                j+=TravelETrieD(pNodeSeg,ptHead->ioffNxt[i],pTravelOper);
        	j+=(*pTravelOper)(&(ptHead->ioffDat[i]));
	}
        return j;
}
int TravelETrie(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER * ))
{
	return TravelETrieD(pNodeSeg,ioffsetHead,pTravelOper);
}
int4b DestroyETrie(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl)
{
	int4b i,j=0;
	ETRIE *ptHead;
	
        if(ioffHead==-1) return 0;
	
	ptHead=OPETRIE(pNodeSeg,ioffHead);

	for(i=0;i<10;i++){
		if(ptHead->ioffNxt[i]!=-1) 
			j+=DestroyETrie(pNodeSeg,ptHead->ioffNxt[i],pShmCtrl);
	}
	
	FreeEItem(pNodeSeg,pShmCtrl,ioffHead);
	
	return ++j;
}
void ReHookETrie(void *pSeg,POINTER ioffRoot,POINTER ioffHead)
{
	int	i,j;
	char	sTemp[200];
	POINTER *pioffTemp;
	ETRIE	*ptHead;
	static	int l=0;
	static char key[200];
	
	if(ioffHead==-1) return;
	
	ptHead=OPETRIE(pSeg,ioffHead);

	for(i=0;i<10;i++){
		if(ptHead->ioffNxt[i]!=-1){
			key[l++]='0'+i;key[l]=0;
			ReHookETrie(pSeg,ioffRoot,ptHead->ioffNxt[i]);
			key[--l]=0;
		}
		if(ptHead->ioffDat[i]!=-1){
			j=l;
			
			while(j>0){
				strncpy(sTemp,key,j);sTemp[j]=0;
				pioffTemp=GetETrieLk(pSeg,ioffRoot,sTemp);

				if(pioffTemp==NULL) break;

				if(*pioffTemp!=-1){
					
					AppendEListTail(pSeg,&(ptHead->ioffDat[i]),
						*pioffTemp);
					break;

				}
				j--;
			}
		}
	}
}

/***********************************************************/
/*****************��鹲���ڴ���չ�����㷨******************/
/***********************************************************/

POINTER MallocFTrie(void *pNodeSeg,struct ShmCtrlStruct *ptHead)
{
	int i;
	ETRIE *pTrie;
	POINTER ioffsetTemp;
 
	if((ioffsetTemp=MallocFItem(pNodeSeg,ptHead))==-1) return -1;
	
	pTrie=OPFTRIE(pNodeSeg,ioffsetTemp);

	for (i=0;i<10;i++){
		pTrie->ioffNxt[i] = -1;
		pTrie->ioffDat[i] = -1;
	}

	return ioffsetTemp;
}
/*"���������ַ�������coredumpΣ��!!!"*/
/*pAssign��ֵ�������е�����ȫ�ֵ�������---�����ݶε�ַOK*/
int  InsertFTrie(void *pNodeSeg,POINTER *pioffsetHead,
	char key[],struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
        void (*pAssign)(POINTER*,POINTER/*����ƫ��*/)) /*��չģʽ������*/
{
	ETRIE *ptCur,*ptPre;
	POINTER ioffsetPreLkHead;
	int i,offset,iStringLen_1,j=0;
	
	if(*pioffsetHead==-1){/*ͷ�ڵ�Ϊ��*/
		if((*pioffsetHead=MallocFTrie(pNodeSeg,pShmCtrl))==-1)
			return -1; /*�����ڴ�ʧ��*/
		j++;
	}
	/*������*ioffsetHead�Ѿ�����Ч���±�*/
	ptPre=ptCur=OPFTRIE(pNodeSeg,(*pioffsetHead));

        iStringLen_1=strlen(key)-1;

	for(i=0;i<iStringLen_1;i++){

                offset=aigCharAnti[(unsigned char )key[i]];

                if(ptPre->ioffDat[offset]!=-1)
                        ioffsetPreLkHead=ptPre->ioffDat[offset];

		if(ptPre->ioffNxt[offset]==-1){
			if((ptPre->ioffNxt[offset]=MallocFTrie(pNodeSeg,
				pShmCtrl))==-1)	return -j-1; /*�����ڴ�ʧ��*/
			j++;  /*����Ľڵ���+1*/
		}
		/*�����ڴ�ָ��*/
		ptCur=OPFTRIE(pNodeSeg,ptPre->ioffNxt[offset]);
		ptPre=ptCur;
	}
	offset=aigCharAnti[(unsigned char)key[i]];
	(*pAssign)(&(ptCur->ioffDat[offset]),ioffValue);
	
	return j;
}

/*��ȫƥ��
����ioffsetHead,pNodeSeg������Ч������coredump U*/

int SearchFTrie(void *pNodeSeg,POINTER ioffsetHead,char key[],POINTER *pioffsetCur)
{
        unsigned char *pts;
        int  iStringLen,offset;
        ETRIE *ptCur;

/*��Ϊ�ջ������ֵΪ����û�ҵ�*/
	if(ioffsetHead==-1||(iStringLen=strlen(key))==0) return NOTFOUND;

	*pioffsetCur=-1;

        pts=(unsigned char *)(&key[0]);
	
	ptCur=OPFTRIE(pNodeSeg,ioffsetHead);
	
        while(iStringLen>0){

		iStringLen--;

                offset=aigCharAnti[*pts++];

                if(ptCur->ioffDat[offset]!=-1)
			*pioffsetCur=ptCur->ioffDat[offset];

		/*��һ���Ѿ�û����֦�ˣ��˳���*/
		if(ptCur->ioffNxt[offset]==-1) break;

		ptCur=OPFTRIE(pNodeSeg,ptCur->ioffNxt[offset]);
	}
	if(*pioffsetCur==-1) return NOTFOUND;
	return FOUND;
}

/*�ó��������ĳ�����ͬ��Ϊ���Ч��д2������*/
POINTER *GetFTrieLk(void *pNodeSeg,POINTER ioffsetHead,char key[])
{

	POINTER *pioffsetCur=NULL;

        unsigned char *pts;
        int  iStringLen,offset;
        ETRIE *ptCur;

/*��Ϊ�ջ������ֵΪ����û�ҵ�*/
	if(ioffsetHead==-1||(iStringLen=strlen(key))==0) return NULL;

        pts=(unsigned char *)(&key[0]);
	
	ptCur=OPFTRIE(pNodeSeg,ioffsetHead);
	
        while(iStringLen>0){

		iStringLen--;

                offset=aigCharAnti[*pts++];

                if(ptCur->ioffDat[offset]!=-1)
			pioffsetCur=&(ptCur->ioffDat[offset]);

		/*��һ���Ѿ�û����֦�ˣ��˳���*/
		if(ptCur->ioffNxt[offset]==-1) break;

		ptCur=OPFTRIE(pNodeSeg,ptCur->ioffNxt[offset]);
	}

	return iStringLen==0?pioffsetCur:(POINTER *)NULL;
}

/*
���ܣ�  ����������ÿ�ڵ㣬ͬʱ�������������ָ������
������  ����ͷָ��ƫ�ƣ��ε�ַ
	��ÿһ��NODE�ڵ����һ�������ͷ��ڴ�
ע�⣺
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int TravelFTrieN(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(ETRIE * ))
{
        int i,j=0;

	ETRIE *ptHead;

        if(ioffsetHead==-1) return 0;
	
	ptHead=OPFTRIE(pNodeSeg,ioffsetHead);

        for(i=0;i<10;i++)				
                j+=TravelFTrieN(pNodeSeg,ptHead->ioffNxt[i],pTravelOper);

        j+=(*pTravelOper)(ptHead);

        return j;
}

/*
���ܣ�  ����������ÿһ����������ͬʱ�������������ָ������
������  ����ͷָ��ƫ�ƣ��ε�ַ
	��ÿһ����������Ĳ�������
ע�⣺
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int TravelFTrieD(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER * ))
{
        int i,j=0;

	ETRIE *ptHead;

        if(ioffsetHead==-1) return 0;
	
	ptHead=OPFTRIE(pNodeSeg,ioffsetHead);

        for(i=0;i<10;i++){
                j+=TravelFTrieD(pNodeSeg,ptHead->ioffNxt[i],pTravelOper);
        	j+=(*pTravelOper)(&(ptHead->ioffDat[i]));
	}
        return j;
}
int TravelFTrie(void *pNodeSeg,POINTER ioffsetHead,
	int (*pTravelOper)(POINTER * ))
{
	return TravelFTrieD(pNodeSeg,ioffsetHead,pTravelOper);
}
int4b DestroyFTrie(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl)
{
	int4b i,j=0;
	ETRIE *ptHead;
	
        if(ioffHead==-1) return 0;
	
	ptHead=OPFTRIE(pNodeSeg,ioffHead);

	for(i=0;i<10;i++){
		if(ptHead->ioffNxt[i]!=-1) 
			j+=DestroyFTrie(pNodeSeg,ptHead->ioffNxt[i],pShmCtrl);
	}
	
	FreeFItem(pNodeSeg,pShmCtrl,ioffHead);
	
	return ++j;
}

void ReHookFTrie(void *pSeg,POINTER ioffRoot,POINTER ioffHead)
{
	int	i,j;
	char	sTemp[200];
	POINTER *pioffTemp;
	ETRIE	*ptHead;
	static	int l=0;
	static char key[200];
	
	if(ioffHead==-1) return;
	
	ptHead=OPFTRIE(pSeg,ioffHead);

	for(i=0;i<10;i++){
		if(ptHead->ioffNxt[i]!=-1){
			key[l++]='0'+i;key[l]=0;
			ReHookFTrie(pSeg,ioffRoot,ptHead->ioffNxt[i]);
			key[--l]=0;
		}
		if(ptHead->ioffDat[i]!=-1){
			j=l;
			
			while(j>0){
				strncpy(sTemp,key,j);sTemp[j]=0;
				pioffTemp=GetFTrieLk(pSeg,ioffRoot,sTemp);

				if(pioffTemp==NULL) break;

				if(*pioffTemp!=-1){
					
					AppendFListTail(pSeg,&(ptHead->ioffDat[i]),
						*pioffTemp);
					break;

				}
				j--;
			}
		}
	}
}

/****************************************************************
*		��ʷ�û�����ά��ר�ü���֧�ֺ�����ʷ֧��		*
*								*
*****************************************************************/


TRIEO *MallocNodeO()
{
	int i;
	TRIEO *pTemp;
	if((pTemp=(TRIEO*)malloc(sizeof(TRIEO)) )==NULL){
		printf("malloc node error.\n");
		/*WriteAlertMsg("����TRIE�ڵ�ʧ��MallocNodeO");*/
		return NULL;
	}
	for(i=0;i<10;i++){
		pTemp->pNext[i]=NULL;
		pTemp->ioffsetData[i]=-1;
	}
	return pTemp;
}

POINTER MallocExt(TRIEEXT *pNodeSeg,
	POINTER *pioffsetFreeNode,POINTER *pioffsetCurNode)
{
	int i;
	TRIEEXT *pTrie;
	POINTER ioffsetTemp;
 
	if(*pioffsetFreeNode==-1){
		/*WriteAlertMsg("�����ڴ�û�п���TRIEEXT�ڵ�");*/
		return -1;
	}	
/*�ӿ���������ȡ��һ���ڵ�*/
	ioffsetTemp=*pioffsetFreeNode;
	pTrie=pNodeSeg+ioffsetTemp;
	*pioffsetFreeNode=pTrie->NextOffset;

	for (i=0;i<10;i++){
		pTrie->ioffsetNext[i] = -1;
		pTrie->ioffsetData[i] = -1;
	}

/*���������Ľڵ���뵽ioffsetCurNode��*/
	pTrie->NextOffset=*pioffsetCurNode;
	*pioffsetCurNode=ioffsetTemp;

	return ioffsetTemp;
}
/*"���������ַ�������coredumpΣ��!!!"*/
/*pAssign��ֵ�������е�����ȫ�ֵ�������---�����ݶε�ַOK*/
int  InsertTrieE(POINTER *pioffsetHead,TRIEEXT *pNodeSeg,
	char key[],POINTER *pioffsetFreeNode,
	POINTER *pioffsetCurNode,POINTER ioffsetData,
        int (*pAssign)(POINTER*,POINTER/*����ƫ��*/)) /*��չģʽ������*/
{
	TRIEEXT *ptCur,*ptPre;
	POINTER ioffsetPreLkHead;
	int i,offset,iStringLen_1,j=0;
	
	if(*pioffsetHead==-1){/*ͷ�ڵ�Ϊ��*/
		if((*pioffsetHead=MallocExt(pNodeSeg,pioffsetFreeNode,
			pioffsetCurNode))==-1) return -1; /*�����ڴ�ʧ��*/
		j++;
	}
	/*������*ioffsetHead�Ѿ�����Ч���±�*/
	ptPre=ptCur=pNodeSeg + (*pioffsetHead);

        iStringLen_1=strlen(key)-1;

	for(i=0;i<iStringLen_1;i++){

                offset=aigCharAnti[(unsigned char )key[i]];

                if(ptPre->ioffsetData[offset]!=-1)
                        ioffsetPreLkHead=ptPre->ioffsetData[offset];

		if(ptPre->ioffsetNext[offset]==-1){
			if((ptPre->ioffsetNext[offset]=MallocExt(pNodeSeg,
				pioffsetFreeNode,
				 pioffsetCurNode))==-1)
				return -j-1; /*�����ڴ�ʧ��*/
			j++;  /*����Ľڵ���+1*/
		}
		/*�����ڴ�ָ��*/
		ptCur=pNodeSeg + ptPre->ioffsetNext[offset];
		ptPre=ptCur;
	}
	offset=aigCharAnti[(unsigned char)key[i]];
	(*pAssign)(&(ptCur->ioffsetData[offset]),ioffsetData);
	
	return j;
}

/*��ȫƥ��
����ioffsetHead,pNodeSeg������Ч������coredump U*/

int SearchTrieE(POINTER ioffsetHead,TRIEEXT *pNodeSeg,char key[],POINTER *pioffsetCur)
{
        unsigned char *pts;
        int  iStringLen,offset;
        TRIEEXT *ptCur;

/*��Ϊ�ջ������ֵΪ����û�ҵ�*/
	if(ioffsetHead==-1||(iStringLen=strlen(key))==0) return NOTFOUND;

	*pioffsetCur=-1;

        pts=(unsigned char *)(&key[0]);

	ptCur=pNodeSeg+ioffsetHead;
	
        while(iStringLen>0){

		iStringLen--;

		offset=aigCharAnti[*pts++];

		if(ptCur->ioffsetData[offset]!=-1)
			*pioffsetCur=ptCur->ioffsetData[offset];
		else
			*pioffsetCur = -1;

		/*��һ���Ѿ�û����֦�ˣ��˳���*/
		if(ptCur->ioffsetNext[offset]==-1) break;

		ptCur=pNodeSeg+ptCur->ioffsetNext[offset];
		
	}
	/*ֻȡ��ȫƥ�䴮*/
	return (*pioffsetCur==-1||iStringLen!=0)?NOTFOUND:FOUND;
}


/*���ݡ�����ioffsetHead,pNodeSeg������Ч������coredump U*/

int SearchTrieEBack(POINTER ioffsetHead,TRIEEXT *pNodeSeg,char key[],POINTER *pioffsetCur)
{
        unsigned char *pts;
        int  iStringLen,offset;
        TRIEEXT *ptCur;

/*��Ϊ�ջ������ֵΪ����û�ҵ�*/
	if(ioffsetHead==-1||(iStringLen=strlen(key))==0) return NOTFOUND;

	*pioffsetCur=-1;

        pts=(unsigned char *)(&key[0]);

	ptCur=pNodeSeg+ioffsetHead;
	
        while(iStringLen>0){

		iStringLen--;

		offset=aigCharAnti[*pts++];

		if(ptCur->ioffsetData[offset]!=-1)
			*pioffsetCur=ptCur->ioffsetData[offset];

		/*��һ���Ѿ�û����֦�ˣ��˳���*/
		if(ptCur->ioffsetNext[offset]==-1) break;

		ptCur=pNodeSeg+ptCur->ioffsetNext[offset];
		
	}
	/*����*/
	return (*pioffsetCur==-1)?NOTFOUND:FOUND;
}


/*�ó��������ĳ�����ͬ��Ϊ���Ч��д2������*/
POINTER *GetTrieLkE(POINTER ioffsetHead,TRIEEXT *pNodeSeg,char key[])
{

	POINTER *pioffsetCur=NULL;

        unsigned char *pts;
        int  iStringLen,offset;
        TRIEEXT *ptCur;

/*��Ϊ�ջ������ֵΪ����û�ҵ�*/
	if(ioffsetHead==-1||(iStringLen=strlen(key))==0) return NULL;

        pts=(unsigned char *)(&key[0]);

	ptCur=pNodeSeg+ioffsetHead;
	
        while(iStringLen>0){

		iStringLen--;

                offset=aigCharAnti[*pts++];

                if(ptCur->ioffsetData[offset]!=-1)
			pioffsetCur=&(ptCur->ioffsetData[offset]);

		/*��һ���Ѿ�û����֦�ˣ��˳���*/
		if(ptCur->ioffsetNext[offset]==-1) break;

		ptCur=pNodeSeg+ptCur->ioffsetNext[offset];
	}

	return iStringLen==0?pioffsetCur:(POINTER *)NULL;
}

/*
���ܣ�  ����������ÿ�ڵ㣬ͬʱ�������������ָ������
������  ����ͷָ��ƫ�ƣ��ε�ַ
	��ÿһ��NODE�ڵ����һ�������ͷ��ڴ�
ע�⣺
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int TravelTrieEN(POINTER ioffsetHead,TRIEEXT *pNodeSeg,
	int (*pTravelOper)(TRIEEXT * ))
{
        int i,j=0;

	TRIEEXT *ptHead;

        if(ioffsetHead==-1) return 0;
	
	ptHead=pNodeSeg+ioffsetHead;

        for(i=0;i<10;i++)				
                j+=TravelTrieEN(ptHead->ioffsetNext[i],pNodeSeg,pTravelOper);

        j+=(*pTravelOper)(ptHead);

        return j;
}

/*
���ܣ�  ����������ÿһ����������ͬʱ�������������ָ������
������  ����ͷָ��ƫ�ƣ��ε�ַ
	��ÿһ����������Ĳ�������
ע�⣺
����ֵ�����������ݲ�������ֵ�ĺͣ���������������й�
*/
int TravelTrieED(POINTER ioffsetHead,TRIEEXT *pNodeSeg,
	int (*pTravelOper)(POINTER ))
{
        int i,j=0;

	TRIEEXT *ptHead;

        if(ioffsetHead==-1) return 0;
	
	ptHead=pNodeSeg+ioffsetHead;

        for(i=0;i<10;i++){
                j+=TravelTrieED(ptHead->ioffsetNext[i],pNodeSeg,pTravelOper);
        	j+=(*pTravelOper)(ptHead->ioffsetData[i]);
	}
        return j;
}
