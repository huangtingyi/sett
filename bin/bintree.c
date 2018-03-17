#include "hnixs.h"
#include "bintree.h"

/*样板函数例子*/
/***
int sample_rand(void *pSource,void *pTarget)
{
        return (rand()%3-1);
}
int keycmp_sample(BINTREE *pBinValue,BINTREE *pBinNode)
{
        void *pTarget=pBinNode->pData,*pSource=pBinValue;
        
        return sample_rand(pSource,pTarget);
}
int keycmpext_sample(void *pValue, BINTREE *pBinNode)
{
        return keycmp_sample((BINTREE *)pValue,pBinNode);
}
void assign_sample(BINTREE **pptHead,void *p)
{
        *pptHead=(BINTREE *)p;
}
int operation_sample(void *pData)
{
        return 0;
}
**/
void **ppLinkNodeLast=NULL;

void link_node_i(void **pp1,void **pp2);

void (*link_node)(void **,void **)=link_node_i;
void link_node_i(void **pp1,void **pp2){;;}

int link_node_travel(void **ppD)
{
	if(ppLinkNodeLast!=NULL)link_node(ppLinkNodeLast,ppD);
	ppLinkNodeLast=ppD;
	return 0;
}

void LinkBin(BINTREE *ptHead,void (*link_node_v)(void **,void **))
{
	ppLinkNodeLast=NULL;
	link_node=link_node_v;
	TravelBin(ptHead,link_node_travel);
	link_node=link_node_i;
	ppLinkNodeLast=NULL;
}
void link_node_hand(void **pp1,void **pp2)
{
	 AppendListTail((LIST**)pp1,(LIST*)(*pp2));
}
void HandShakeBin(BINTREE *ptHead)
{
	LinkBin(ptHead,link_node_hand);
}
void AdjustBin(BINTREE **pptHead)
{
	BINTREE *pTemp,*ptPre,*ptCur;

	switch((*pptHead)->diff){
	case 2:
	ptPre=*pptHead;
	ptCur=ptPre->pRight;
	
	if(ptCur->diff==-1){
		pTemp=ptCur->pLeft;
		
		ptPre->pRight=pTemp->pLeft;
		ptCur->pLeft=pTemp->pRight;
		
		pTemp->pLeft=ptPre;
		pTemp->pRight=ptCur;
		
		switch(pTemp->diff){
		case 0:
		ptPre->diff=0;
		ptCur->diff=0;
		break;
		case 1:
		ptPre->diff=-1;
		ptCur->diff=0;
		break;
		default: /* -1 here */
		ptPre->diff=0;
		ptCur->diff=1;
		break;
		}
		 /* *pptHead left right same high here */
		pTemp->diff=0;
		(*pptHead)=pTemp;
	}
	else{  /* ptCur->diff must ==0 or ==1 ok here*/
		ptPre->pRight=ptCur->pLeft;
		ptCur->pLeft=ptPre;
	/* when ptCur->diff==1 and ptPre->diff=0 ptCur->diff=0*/
	/* when ptCur->diff==0 and ptPre->diff=1 ptCur->diff=-1*/
		ptPre->diff=1-ptCur->diff;
		ptCur->diff--;
		(*pptHead)=ptCur; /* root change to ptCur */
	}
	break;
	case -2:
	ptPre=*pptHead;
	ptCur=ptPre->pLeft;
	if(ptCur->diff==1){
		pTemp=ptCur->pRight;
		
		ptCur->pRight=pTemp->pLeft;
		ptPre->pLeft=pTemp->pRight;
		
		pTemp->pLeft=ptCur; 
		pTemp->pRight=ptPre;
		
		switch(pTemp->diff){
		case 0:
		ptPre->diff=0;
		ptCur->diff=0;
		break;
		case 1:
		ptPre->diff=0;
		ptCur->diff=-1;
		break;
		default: /* -1 */
		ptPre->diff=1;
		ptCur->diff=0;
		break;
		}
		/* *pptHead left right same high here */
		pTemp->diff=0; 
		(*pptHead)=pTemp;
	}
	else{  /* ptCur->diff must ==0 or ==-1 */
		ptPre->pLeft=ptCur->pRight;
		ptCur->pRight=ptPre;
	/* when ptCur->diff==-1 and ptPre->diff=0 ptCur->diff=0*/
	/* when ptCur->diff==0  and ptPre->diff=-1,ptCur->diff=1*/
		ptPre->diff=-1-ptCur->diff;
		ptCur->diff++;
		(*pptHead)=ptCur; /* root change to ptCur */
	}
	break;
	default: break;
	}
}
int4b InsertBin(BINTREE **pptHead, void *pValue, 
        int4b ( *pFunction)(void *,void*), 
        void ( *pAssign)(void **,void *))
{
        int4b diff,res,r;

        BINTREE *pTemp;
    

        if(*pptHead==NULL){
                if((pTemp=MallocBin())==NULL)
                        return -1;

                (*pAssign)(&(pTemp->pData),pValue); 
                *pptHead=pTemp;

                return EQUAL;
        } 
        
        diff=(*pptHead)->diff;
        
        if((res=(*pFunction)(pValue,(*pptHead)->pData))==0){
                (*pAssign)(&((*pptHead)->pData),pValue);
                return EQUAL;
        }

        if(res>0){ /* right */
        
                if((*pptHead)->pRight!=NULL){
                        r=InsertBin( &((*pptHead)->pRight),
                                pValue,pFunction,pAssign);
                        
                        if(r<0) return -1;
                        
                        if(r==HIGHER) (*pptHead)->diff++;


                }
                else { /* pRight==NULL here */
                        if((pTemp=MallocBin())==NULL){
                                printf("error mallocRight BinNode.\n");
                                return -1;
                        }
                        (*pAssign)(&(pTemp->pData),pValue); 
                        (*pptHead)->pRight=pTemp;
                        
                        (*pptHead)->diff++;

                }
        }
        else {
                
                if((*pptHead)->pLeft!=NULL){
                        
                        r=InsertBin( &((*pptHead)->pLeft),
                                pValue,pFunction,pAssign);
                        
                        if(r<0) return -1;
                        
                        if(r==HIGHER) (*pptHead)->diff--;
                }
                else{  /* pLeft==NULL */
                        if((pTemp=MallocBin())==NULL){
                                printf("error mallocLeft BinNode.\n");
                                return -1;
                        }
                        (*pAssign)(&(pTemp->pData),pValue); 
                        (*pptHead)->pLeft=pTemp;

                        (*pptHead)->diff--;
                }   
        }
        
            /* adjust here */
        AdjustBin(pptHead);
        
        if(diff==0&&(*pptHead)->diff) return HIGHER;
        
        return EQUAL;
}

BINTREE * MallocBin()
{
        BINTREE *pTemp;
        
        if((pTemp=(BINTREE *)hmalloc(sizeof(BINTREE)))==NULL)
                return NULL;
        
        pTemp->pLeft=pTemp->pRight=NULL;
        pTemp->diff=0;
        pTemp->pData=NULL;
        return pTemp;
}

int4b SearchBin(BINTREE *ptHead, void *pValue,
        int ( *pFunction)(void *,void *), void **pptCur)
{
        int res;
    
        if(ptHead==NULL) return NOTFOUND;
    
        if((res=(*pFunction)(pValue,ptHead->pData))==0) {               
                *pptCur=ptHead->pData;
                return FOUND;    
        }       
        
        if(res>0) return SearchBin(ptHead->pRight,pValue,pFunction,pptCur);
        else      return SearchBin(ptHead->pLeft, pValue,pFunction,pptCur);
}

int4b DestroyBin(BINTREE *ptHead)
{
        int4b j=0;
        
        if(ptHead==NULL) return 0;
        
        j+=DestroyBin(ptHead->pLeft);
        j+=DestroyBin(ptHead->pRight);
        
        hfree(ptHead,sizeof(BINTREE));
        
        return j+1;
}
int TravelBin(BINTREE *ptHead, int ( *pOperation)(void **))
{
	int j=0;
	
	if(ptHead==NULL) return 0;
	
	if(ptHead->pLeft!=NULL)
		j+=TravelBin(ptHead->pLeft,pOperation);
	j+=(*pOperation)(&(ptHead->pData));
	if(ptHead->pRight!=NULL)
		j+=TravelBin(ptHead->pRight,pOperation);
	return j;
}

int4b DeleteBinMin(BINTREE **pptHead, BINTREE **pptCur)
{
        int4b diff;
        
        BINTREE *pTemp;
    
        *pptCur=NULL;

        diff=(*pptHead)->diff;
        
        if((*pptHead)->pLeft!=NULL){
                if(DeleteBinMin(&((*pptHead)->pLeft),pptCur)==LOWER)
                        (*pptHead)->diff++;
        }
        else{/*(*pptHead)->pLeft==NULL here(*pptHead)->diff in (0,1)*/
                if((*pptHead)->diff==1){
			pTemp=*pptHead;
			*pptHead=pTemp->pRight;
                }
                else{ /* (*pptHead)->diff ==0 leaves here.*/
			pTemp=*pptHead;
			*pptHead=NULL;
                }
                *pptCur=pTemp;
                return LOWER;
        }
                
        AdjustBin(pptHead);
        
        if(diff!=0&&(*pptHead)->diff==0) return LOWER;
        
        return EQUAL;
}

int4b DeleteBin(BINTREE **pptHead,void *p,
	int4b ( *pFunction)(void *,void *),BINTREE **pptCur)
{
        int4b r;
                
        *pptCur=NULL;

        if((r=(*pFunction)(p,(*pptHead)->pData))==0){

                BINTREE *ptCur=NULL,**pptPre;

                *pptCur=*pptHead;

                if((*pptHead)->pLeft==NULL){
                        /*左子树为空，右子树空或非空，叶子节点*/
                        *pptHead=(*pptHead)->pRight;
                        return LOWER;   
                }
                         /*左子树非空，右子树空*/
                if((*pptHead)->pRight==NULL){
                        *pptHead=(*pptHead)->pLeft;
                        return LOWER;
                }

                pptPre=&((*pptHead)->pRight);

                /*左子树非空，右子树非空*/
                r=DeleteBinMin(pptPre,&ptCur);

                if(ptCur==NULL) return EQUAL;

                ptCur->pLeft=(*pptHead)->pLeft;
                ptCur->pRight=(*pptHead)->pRight;

                if(r==LOWER){
                        ptCur->diff=(*pptHead)->diff-1;
                        AdjustBin(&ptCur);
                }
                else
                        ptCur->diff=  (*pptHead)->diff; 

                *pptHead=ptCur;

                return r;
        }

        if(r>0){
                r=DeleteBin(&((*pptHead)->pRight),p,pFunction,pptCur);
                if(r==LOWER){
                        (*pptHead)->diff--;
                        AdjustBin(pptHead);
                }
                return r;
        }

        r=DeleteBin(&((*pptHead)->pLeft),p,pFunction,pptCur);
        if(r==LOWER){
                (*pptHead)->diff++;
                AdjustBin(pptHead);
        }
        return r;
}
void assign_insert_bintree(void **ppData,void *pData)
{
	InsertList((LIST**)(ppData), (LIST*)pData);
}
/*---------------共享内存形式的BINTREE-------------*/
POINTER MallocEBin(void *pNodeSeg,struct ShmCtrlStruct *ptHead)
{
	EBINTREE *pBin;
	POINTER ioffsetTemp;
 
	if((ioffsetTemp=MallocEItem(pNodeSeg,ptHead))==-1) return -1;
	
/*从空闲链表中取得一个节点*/
	pBin=OPEBINTREE(pNodeSeg,ioffsetTemp);
	
	pBin->ioffNext=-1;
	pBin->ioffLeft=-1;
	pBin->ioffRight=-1;
	pBin->ioffData=-1;
	pBin->diff=0;

	return ioffsetTemp;
}
void AdjustEBin(void *pNodeSeg,POINTER  *pioffHead)
{
	POINTER ioffPre,ioffCur,ioffTemp;
	EBINTREE *pTemp,*ptPre,*ptCur;
/*
	switch((*pptHead)->diff){
*/
	switch(OPEBINTREE(pNodeSeg,*pioffHead)->diff){
	case 2:   
/*
	ptPre=*pptHead;
	ptCur=ptPre->pRight; 
*/
	ioffPre=*pioffHead;
	ioffCur=OOEBINTREERIGHT(pNodeSeg,ioffPre);
	
        ptPre=OPEBINTREE(pNodeSeg,ioffPre);
        ptCur=OPEBINTREE(pNodeSeg,ioffCur);

        if(ptCur->diff==-1){
/*
		pTemp=ptCur->pLeft;
		
		ptPre->pRight=pTemp->pLeft;
		ptCur->pLeft=pTemp->pRight;
		
		pTemp->pLeft=ptPre;
		pTemp->pRight=ptCur;
*/
		ioffTemp=OOEBINTREELEFT(pNodeSeg,ioffCur);
		pTemp=OPEBINTREE(pNodeSeg,ioffTemp);
/*		pTemp=PPEBINTREELEFT(pNodeSeg,ptCur);*/
		ptPre->ioffRight=pTemp->ioffLeft;
		ptCur->ioffLeft=pTemp->ioffRight;
		
		pTemp->ioffLeft=ioffPre;
		pTemp->ioffRight=ioffCur;
		
		switch(pTemp->diff){
		case 0:
		ptPre->diff=0;
		ptCur->diff=0;
		break;
		case 1:
		ptPre->diff=-1;
		ptCur->diff=0;
		break;
		default: /* -1 here */
		ptPre->diff=0;
		ptCur->diff=1;
		break;
           	}
           	/* *pptHead left right same high here */
		pTemp->diff=0;
/*           (*pptHead)=pTemp;*/
/*		*pioffHead=POFFCHAR(pNodeSeg,pTemp);*/
		*pioffHead=ioffTemp;
	}
	else{  /* ptCur->diff must ==0 or ==1 ok here*/
		/*ptPre->pRight=ptCur->pLeft;
		ptCur->pLeft=ptPre;*/
		ptPre->ioffRight=	ptCur->ioffLeft;
/*		ptCur->ioffLeft=	POFFCHAR(pNodeSeg,ptPre);*/
		ptCur->ioffLeft=	ioffPre;
		/* when ptCur->diff==1 and ptPre->diff=0 ptCur->diff=0*/
		/* when ptCur->diff==0 and ptPre->diff=1 ptCur->diff=-1*/
		ptPre->diff=1-ptCur->diff;
		ptCur->diff--;
		/*(*pptHead)=ptCur;*/ /* root change to ptCur */
/*		*pioffHead=POFFCHAR(pNodeSeg,ptCur);*/
		*pioffHead=ioffCur;
	}
	break;
	case -2:        
/*      ptPre=*pptHead;
        ptCur=ptPre->pLeft;*/
/*        
        ptPre=OPEBINTREE(pNodeSeg,*pioffHead);
        ptCur=PPEBINTREELEFT(pNodeSeg,ptPre);
*/
       	ioffPre=*pioffHead;
	ioffCur=OOEBINTREELEFT(pNodeSeg,ioffPre);
	
        ptPre=OPEBINTREE(pNodeSeg,ioffPre);
        ptCur=OPEBINTREE(pNodeSeg,ioffCur);
        
        if(ptCur->diff==1){
        /*
		pTemp=ptCur->pRight;
		
		ptCur->pRight=pTemp->pLeft;
		ptPre->pLeft=pTemp->pRight;
		
		pTemp->pLeft=ptCur; 
		pTemp->pRight=ptPre;
	*/
/*		pTemp=PPEBINTREERIGHT(pNodeSeg,ptCur);*/
		ioffTemp=OOEBINTREERIGHT(pNodeSeg,ioffCur);
		pTemp=OPEBINTREE(pNodeSeg,ioffTemp);
		
		ptCur->ioffRight=pTemp->ioffLeft;
		ptPre->ioffLeft=pTemp->ioffRight;
/*		
		pTemp->ioffLeft=POFFCHAR(pNodeSeg,ptCur);
		pTemp->ioffRight=POFFCHAR(pNodeSeg,ptPre);
*/
		pTemp->ioffLeft=ioffCur;
		pTemp->ioffRight=ioffPre;

		switch(pTemp->diff){
		case 0:
		ptPre->diff=0;
		ptCur->diff=0;
		break;
		case 1:
		ptPre->diff=0;
		ptCur->diff=-1;
		break;
		default: /* -1 */
		ptPre->diff=1;
		ptCur->diff=0;
		break;
		}
		/* *pptHead left right same high here */
		pTemp->diff=0; 
		/*(*pptHead)=pTemp;*/
/*		*pioffHead=POFFCHAR(pNodeSeg,pTemp);*/
		*pioffHead=ioffTemp;
        }
        else{  /* ptCur->diff must ==0 or ==-1 */
		/*ptPre->pLeft=ptCur->pRight;
		ptCur->pRight=ptPre;*/
		ptPre->ioffLeft=ptCur->ioffRight;
/*		ptCur->ioffRight=POFFCHAR(pNodeSeg,ptPre);*/
		ptCur->ioffRight=ioffPre;

		/* when ptCur->diff==-1 and ptPre->diff=0 ptCur->diff=0*/
		/* when ptCur->diff==0  and ptPre->diff=-1,ptCur->diff=1*/
		ptPre->diff=-1-ptCur->diff;
		ptCur->diff++;
		/*(*pptHead)=ptCur;*/ /* root change to ptCur */
/*		*pioffHead=POFFCHAR(pNodeSeg,ptCur);*/
		*pioffHead=ioffCur;
        }
	break;
	default: break;
	}
}
        
int4b InsertEBin(void *pNodeSeg,POINTER *pioffsetHead,
	struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
	int4b ( *pFunction)(POINTER,POINTER), 
        void ( *pAssign)(POINTER *,POINTER/*数据偏移*/))
{
        int4b diff,res,r;

	POINTER ioffTemp;
        EBINTREE *pTemp,*ptHead;
    

        if(*pioffsetHead==-1){
                if((ioffTemp=MallocEBin(pNodeSeg,pShmCtrl))==-1) return -1;

		pTemp=OPEBINTREE(pNodeSeg,ioffTemp);
                (*pAssign)(&(pTemp->ioffData),ioffValue);
                
                *pioffsetHead=ioffTemp;

                return EQUAL;
        } 
        
        ptHead=OPEBINTREE(pNodeSeg,*pioffsetHead);
        diff=ptHead->diff;
        
        if((res=(*pFunction)(ioffValue,ptHead->ioffData))==0){
                (*pAssign)(&(ptHead->ioffData),ioffValue);
                return EQUAL;
        }

        if(res>0){ /* right */
        
                if(ptHead->ioffRight!=-1){
                        r=InsertEBin(pNodeSeg,&(ptHead->ioffRight),
                        	pShmCtrl,ioffValue,pFunction,pAssign);
                        
                        if(r<0) return -1;
                        
                        if(r==HIGHER) ptHead->diff++;


                }
                else { /* pRight==NULL here */
                	if((ioffTemp=MallocEBin(pNodeSeg,pShmCtrl))==-1) return -1;
                	
			pTemp=OPEBINTREE(pNodeSeg,ioffTemp);
                	(*pAssign)(&(pTemp->ioffData),ioffValue);
                	
                	ptHead->ioffRight=	ioffTemp;
                	ptHead->diff++;
                }
        }
        else {
                
                if(ptHead->ioffLeft!=-1){
                        
                        r=InsertEBin(pNodeSeg,&(ptHead->ioffLeft),
                        	pShmCtrl,ioffValue,pFunction,pAssign);
                        
                        if(r<0) return -1;

                        if(r==HIGHER) ptHead->diff--;
                }
                else{  /* pLeft==NULL */
                
                	if((ioffTemp=MallocEBin(pNodeSeg,pShmCtrl))==-1) return -1;
                	
			pTemp=OPEBINTREE(pNodeSeg,ioffTemp);
                	(*pAssign)(&(pTemp->ioffData),ioffValue);
                	
                	ptHead->ioffLeft=	ioffTemp;
                	ptHead->diff--;
                }   
        }
        
            /* adjust here */
        AdjustEBin(pNodeSeg,pioffsetHead);
        
        if(diff==0&&OPEBINTREE(pNodeSeg,*pioffsetHead)->diff) return HIGHER;
        
        return EQUAL;
}

int4b SearchEBin(void *pNodeSeg,POINTER ioffsetHead,void *p,
	int ( *pFunction)(void *,POINTER),POINTER *pioffsetCur)
{
        int res;
    	EBINTREE *ptHead;
    		
        if(ioffsetHead==-1) return NOTFOUND;
	    
    	ptHead=OPEBINTREE(pNodeSeg,ioffsetHead);
    	
        if((res=(*pFunction)(p,ptHead->ioffData))==0){
        	
                *pioffsetCur=ptHead->ioffData;
                return FOUND;    
        }       
        
        if(res>0) return SearchEBin(pNodeSeg,ptHead->ioffRight,
        			p,pFunction,pioffsetCur);
        else      return SearchEBin(pNodeSeg,ptHead->ioffLeft,
        			p,pFunction,pioffsetCur);
}
int TravelEBin(void *pNodeSeg,POINTER ioffsetHead,
	int ( *pOperation)(POINTER *))
{
	int j=0;
	EBINTREE *ptHead;
	
	if(ioffsetHead==-1) return 0;
	
	ptHead=OPEBINTREE(pNodeSeg,ioffsetHead);
	
	if(ptHead->ioffLeft!=-1)
		j+=TravelEBin(pNodeSeg,ptHead->ioffLeft,pOperation);
	j+=(*pOperation)(&(ptHead->ioffData));
	if(ptHead->ioffRight!=-1)
		j+=TravelEBin(pNodeSeg,ptHead->ioffRight,pOperation);
	return j;
}
int4b DeleteEBinMin(void *pNodeSeg,POINTER *pioffsetHead,
	POINTER *pioffsetCur)
{
        int4b diff;
        
        POINTER ioffTemp;
        EBINTREE *ptHead=OPEBINTREE(pNodeSeg,*pioffsetHead);
        
        *pioffsetCur=-1;

        diff=ptHead->diff;
        
        if(ptHead->ioffLeft!=-1){
                if(DeleteEBinMin(pNodeSeg,&(ptHead->ioffLeft),pioffsetCur)==LOWER)
                        ptHead->diff++;
        }
        else{/*(*pptHead)->pLeft==NULL here(*pptHead)->diff in (0,1)*/
                if(ptHead->diff==1){
                	
                	ioffTemp=*pioffsetHead;
                	*pioffsetHead=OPEBINTREE(pNodeSeg,ioffTemp)->ioffRight;
                }
                else{ /* (*pptHead)->diff ==0 leaves here.*/
                	ioffTemp=*pioffsetHead;
                	*pioffsetHead=-1;
                }
                *pioffsetCur=ioffTemp;
                return LOWER;
        }
          
        AdjustEBin(pNodeSeg,pioffsetHead);
        
        if(diff!=0&&OPEBINTREE(pNodeSeg,*pioffsetHead)->diff==0) return HIGHER;

        return EQUAL;
}
int4b DeleteEBin(void *pNodeSeg,POINTER *pioffsetHead,void *p,
	int4b ( *pFunction)(void *,POINTER),POINTER *pioffsetCur)
{
        int4b r;

    	EBINTREE *ptHead;
    	
        if(*pioffsetHead==-1) return NOTFOUND;
    
	*pioffsetCur=-1;
	
    	ptHead=OPEBINTREE(pNodeSeg,*pioffsetHead);
    	
        if((r=(*pFunction)(p,ptHead->ioffData))==0){

		POINTER ioffCur=-1,*pioffPre;

		*pioffsetCur=*pioffsetHead;

                if(ptHead->ioffLeft==-1){
                        /*左子树为空，右子树空或非空，叶子节点*/
                	*pioffsetHead=ptHead->ioffRight;
                        return LOWER;   
                }
                         /*左子树非空，右子树空*/
                if(ptHead->ioffRight==-1){
                	*pioffsetHead=ptHead->ioffLeft;
                        return LOWER;
                }

		pioffPre=&(ptHead->ioffRight);

                /*左子树非空，右子树非空*/
                r=DeleteEBinMin(pNodeSeg,pioffPre,&ioffCur);

                if(ioffCur==-1) return EQUAL;/*这种情况不可能出现*/

		OOEBINTREELEFT(pNodeSeg,ioffCur)=ptHead->ioffLeft;
		OOEBINTREERIGHT(pNodeSeg,ioffCur)=ptHead->ioffRight;

                if(r==LOWER){
                        OPEBINTREE(pNodeSeg,ioffCur)->diff=ptHead->diff-1;
                        AdjustEBin(pNodeSeg,&ioffCur);
                }
                else
                        OPEBINTREE(pNodeSeg,ioffCur)->diff=ptHead->diff; 

		
                *pioffsetHead=ioffCur;

                return r;
        }

        if(r>0){
                r=DeleteEBin(pNodeSeg,&(ptHead->ioffRight),p,pFunction,pioffsetCur);
                if(r==LOWER){
                        ptHead->diff--;
                        AdjustEBin(pNodeSeg,pioffsetHead);
                }
                return r;
        }

        r=DeleteEBin(pNodeSeg,&(ptHead->ioffLeft),p,pFunction,pioffsetCur);
        if(r==LOWER){
                ptHead->diff++;
                AdjustEBin(pNodeSeg,pioffsetHead);
        }
        return r;
}
int4b DestroyEBin(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl)
{
        int4b j=0;
        
        if(ioffHead==-1) return 0;
        
        j+=DestroyEBin(pNodeSeg,OOEBINTREELEFT(pNodeSeg,ioffHead),pShmCtrl);
        j+=DestroyEBin(pNodeSeg,OOEBINTREERIGHT(pNodeSeg,ioffHead),pShmCtrl);
        
        FreeEItem(pNodeSeg,pShmCtrl,ioffHead);

        return j+1;
}

/*---------------多块共享内存形式的BINTREE-------------*/
POINTER MallocFBin(void *pNodeSeg,struct ShmCtrlStruct *ptHead)
{
	EBINTREE *pBin;
	POINTER ioffsetTemp;
 
	if((ioffsetTemp=MallocFItem(pNodeSeg,ptHead))==-1) return -1;
	
/*从空闲链表中取得一个节点*/
	pBin=OPFBINTREE(pNodeSeg,ioffsetTemp);
	
	pBin->ioffNext=-1;
	pBin->ioffLeft=-1;
	pBin->ioffRight=-1;
	pBin->ioffData=-1;
	pBin->diff=0;

	return ioffsetTemp;
}
void AdjustFBin(void *pNodeSeg,POINTER  *pioffHead)
{
	POINTER ioffPre,ioffCur,ioffTemp;
	EBINTREE *pTemp,*ptPre,*ptCur;
/*
	switch((*pptHead)->diff){
*/
	switch(OPFBINTREE(pNodeSeg,*pioffHead)->diff){
	case 2:   
/*
	ptPre=*pptHead;
	ptCur=ptPre->pRight; 
*/
	ioffPre=*pioffHead;
	ioffCur=OOFBINTREERIGHT(pNodeSeg,ioffPre);
	
        ptPre=OPFBINTREE(pNodeSeg,ioffPre);
        ptCur=OPFBINTREE(pNodeSeg,ioffCur);

        if(ptCur->diff==-1){
/*
		pTemp=ptCur->pLeft;
		
		ptPre->pRight=pTemp->pLeft;
		ptCur->pLeft=pTemp->pRight;
		
		pTemp->pLeft=ptPre;
		pTemp->pRight=ptCur;
*/
		ioffTemp=OOFBINTREELEFT(pNodeSeg,ioffCur);
		pTemp=OPFBINTREE(pNodeSeg,ioffTemp);
/*		pTemp=PPFBINTREELEFT(pNodeSeg,ptCur);*/
		ptPre->ioffRight=pTemp->ioffLeft;
		ptCur->ioffLeft=pTemp->ioffRight;
		
		pTemp->ioffLeft=ioffPre;
		pTemp->ioffRight=ioffCur;
		
		switch(pTemp->diff){
		case 0:
		ptPre->diff=0;
		ptCur->diff=0;
		break;
		case 1:
		ptPre->diff=-1;
		ptCur->diff=0;
		break;
		default: /* -1 here */
		ptPre->diff=0;
		ptCur->diff=1;
		break;
           	}
           	/* *pptHead left right same high here */
		pTemp->diff=0;
/*           (*pptHead)=pTemp;*/
/*		*pioffHead=POFFCHAR(pNodeSeg,pTemp);*/
		*pioffHead=ioffTemp;
	}
	else{  /* ptCur->diff must ==0 or ==1 ok here*/
		/*ptPre->pRight=ptCur->pLeft;
		ptCur->pLeft=ptPre;*/
		ptPre->ioffRight=	ptCur->ioffLeft;
/*		ptCur->ioffLeft=	POFFCHAR(pNodeSeg,ptPre);*/
		ptCur->ioffLeft=	ioffPre;
		/* when ptCur->diff==1 and ptPre->diff=0 ptCur->diff=0*/
		/* when ptCur->diff==0 and ptPre->diff=1 ptCur->diff=-1*/
		ptPre->diff=1-ptCur->diff;
		ptCur->diff--;
		/*(*pptHead)=ptCur;*/ /* root change to ptCur */
/*		*pioffHead=POFFCHAR(pNodeSeg,ptCur);*/
		*pioffHead=ioffCur;
	}
	break;
	case -2:        
/*      ptPre=*pptHead;
        ptCur=ptPre->pLeft;*/
/*        
        ptPre=OPFBINTREE(pNodeSeg,*pioffHead);
        ptCur=PPFBINTREELEFT(pNodeSeg,ptPre);
*/
       	ioffPre=*pioffHead;
	ioffCur=OOFBINTREELEFT(pNodeSeg,ioffPre);
	
        ptPre=OPFBINTREE(pNodeSeg,ioffPre);
        ptCur=OPFBINTREE(pNodeSeg,ioffCur);
        
        if(ptCur->diff==1){
        /*
		pTemp=ptCur->pRight;
		
		ptCur->pRight=pTemp->pLeft;
		ptPre->pLeft=pTemp->pRight;
		
		pTemp->pLeft=ptCur; 
		pTemp->pRight=ptPre;
	*/
/*		pTemp=PPFBINTREERIGHT(pNodeSeg,ptCur);*/
		ioffTemp=OOFBINTREERIGHT(pNodeSeg,ioffCur);
		pTemp=OPFBINTREE(pNodeSeg,ioffTemp);
		
		ptCur->ioffRight=pTemp->ioffLeft;
		ptPre->ioffLeft=pTemp->ioffRight;
/*		
		pTemp->ioffLeft=POFFCHAR(pNodeSeg,ptCur);
		pTemp->ioffRight=POFFCHAR(pNodeSeg,ptPre);
*/
		pTemp->ioffLeft=ioffCur;
		pTemp->ioffRight=ioffPre;

		switch(pTemp->diff){
		case 0:
		ptPre->diff=0;
		ptCur->diff=0;
		break;
		case 1:
		ptPre->diff=0;
		ptCur->diff=-1;
		break;
		default: /* -1 */
		ptPre->diff=1;
		ptCur->diff=0;
		break;
		}
		/* *pptHead left right same high here */
		pTemp->diff=0; 
		/*(*pptHead)=pTemp;*/
/*		*pioffHead=POFFCHAR(pNodeSeg,pTemp);*/
		*pioffHead=ioffTemp;
        }
        else{  /* ptCur->diff must ==0 or ==-1 */
		/*ptPre->pLeft=ptCur->pRight;
		ptCur->pRight=ptPre;*/
		ptPre->ioffLeft=ptCur->ioffRight;
/*		ptCur->ioffRight=POFFCHAR(pNodeSeg,ptPre);*/
		ptCur->ioffRight=ioffPre;

		/* when ptCur->diff==-1 and ptPre->diff=0 ptCur->diff=0*/
		/* when ptCur->diff==0  and ptPre->diff=-1,ptCur->diff=1*/
		ptPre->diff=-1-ptCur->diff;
		ptCur->diff++;
		/*(*pptHead)=ptCur;*/ /* root change to ptCur */
/*		*pioffHead=POFFCHAR(pNodeSeg,ptCur);*/
		*pioffHead=ioffCur;
        }
	break;
	default: break;
	}
}
        
int4b InsertFBin(void *pNodeSeg,POINTER *pioffsetHead,
	struct ShmCtrlStruct *pShmCtrl,POINTER ioffValue,
	int4b ( *pFunction)(POINTER,POINTER), 
        void ( *pAssign)(POINTER *,POINTER/*数据偏移*/))
{
        int4b diff,res,r;

	POINTER ioffTemp;
        EBINTREE *pTemp,*ptHead;
    

        if(*pioffsetHead==-1){
                if((ioffTemp=MallocFBin(pNodeSeg,pShmCtrl))==-1) return -1;

		pTemp=OPFBINTREE(pNodeSeg,ioffTemp);
                (*pAssign)(&(pTemp->ioffData),ioffValue);
                
                *pioffsetHead=ioffTemp;

                return EQUAL;
        } 
        
        ptHead=OPFBINTREE(pNodeSeg,*pioffsetHead);
        diff=ptHead->diff;
        
        if((res=(*pFunction)(ioffValue,ptHead->ioffData))==0){
                (*pAssign)(&(ptHead->ioffData),ioffValue);
                return EQUAL;
        }

        if(res>0){ /* right */
        
                if(ptHead->ioffRight!=-1){
                        r=InsertFBin(pNodeSeg,&(ptHead->ioffRight),
                        	pShmCtrl,ioffValue,pFunction,pAssign);
                        
                        if(r<0) return -1;
                        
                        if(r==HIGHER) ptHead->diff++;


                }
                else { /* pRight==NULL here */
                	if((ioffTemp=MallocFBin(pNodeSeg,pShmCtrl))==-1) return -1;
                	
			pTemp=OPFBINTREE(pNodeSeg,ioffTemp);
                	(*pAssign)(&(pTemp->ioffData),ioffValue);
                	
                	ptHead->ioffRight=	ioffTemp;
                	ptHead->diff++;
                }
        }
        else {
                
                if(ptHead->ioffLeft!=-1){
                        
                        r=InsertFBin(pNodeSeg,&(ptHead->ioffLeft),
                        	pShmCtrl,ioffValue,pFunction,pAssign);
                        
                        if(r<0) return -1;

                        if(r==HIGHER) ptHead->diff--;
                }
                else{  /* pLeft==NULL */
                
                	if((ioffTemp=MallocFBin(pNodeSeg,pShmCtrl))==-1) return -1;
                	
			pTemp=OPFBINTREE(pNodeSeg,ioffTemp);
                	(*pAssign)(&(pTemp->ioffData),ioffValue);
                	
                	ptHead->ioffLeft=	ioffTemp;
                	ptHead->diff--;
                }   
        }
        
            /* adjust here */
        AdjustFBin(pNodeSeg,pioffsetHead);
        
        if(diff==0&&OPFBINTREE(pNodeSeg,*pioffsetHead)->diff) return HIGHER;
        
        return EQUAL;
}

int4b SearchFBin(void *pNodeSeg,POINTER ioffsetHead,void *p,
	int ( *pFunction)(void *,POINTER),POINTER *pioffsetCur)
{
        int res;
    	EBINTREE *ptHead;
    		
        if(ioffsetHead==-1) return NOTFOUND;
	    
    	ptHead=OPFBINTREE(pNodeSeg,ioffsetHead);
    	
        if((res=(*pFunction)(p,ptHead->ioffData))==0){
        	
                *pioffsetCur=ptHead->ioffData;
                return FOUND;    
        }       
        
        if(res>0) return SearchFBin(pNodeSeg,ptHead->ioffRight,
        			p,pFunction,pioffsetCur);
        else      return SearchFBin(pNodeSeg,ptHead->ioffLeft,
        			p,pFunction,pioffsetCur);
}
int TravelFBin(void *pNodeSeg,POINTER ioffsetHead,
	int ( *pOperation)(POINTER *))
{
	int j=0;
	EBINTREE *ptHead;
	
	if(ioffsetHead==-1) return 0;
	
	ptHead=OPFBINTREE(pNodeSeg,ioffsetHead);
	
	if(ptHead->ioffLeft!=-1)
		j+=TravelFBin(pNodeSeg,ptHead->ioffLeft,pOperation);
	j+=(*pOperation)(&(ptHead->ioffData));
	if(ptHead->ioffRight!=-1)
		j+=TravelFBin(pNodeSeg,ptHead->ioffRight,pOperation);
	return j;
}
int4b DeleteFBinMin(void *pNodeSeg,POINTER *pioffsetHead,
	POINTER *pioffsetCur)
{
        int4b diff;
        
        POINTER ioffTemp;
        EBINTREE *ptHead=OPFBINTREE(pNodeSeg,*pioffsetHead);
        
        *pioffsetCur=-1;

        diff=ptHead->diff;
        
        if(ptHead->ioffLeft!=-1){
                if(DeleteFBinMin(pNodeSeg,&(ptHead->ioffLeft),pioffsetCur)==LOWER)
                        ptHead->diff++;
        }
        else{/*(*pptHead)->pLeft==NULL here(*pptHead)->diff in (0,1)*/
                if(ptHead->diff==1){
                	
                	ioffTemp=*pioffsetHead;
                	*pioffsetHead=OPFBINTREE(pNodeSeg,ioffTemp)->ioffRight;
                }
                else{ /* (*pptHead)->diff ==0 leaves here.*/
                	ioffTemp=*pioffsetHead;
                	*pioffsetHead=-1;
                }
                *pioffsetCur=ioffTemp;
                return LOWER;
        }
          
        AdjustFBin(pNodeSeg,pioffsetHead);
        
        if(diff!=0&&OPFBINTREE(pNodeSeg,*pioffsetHead)->diff==0) return HIGHER;

        return EQUAL;
}
int4b DeleteFBin(void *pNodeSeg,POINTER *pioffsetHead,void *p,
	int4b ( *pFunction)(void *,POINTER),POINTER *pioffsetCur)
{
        int4b r;

    	EBINTREE *ptHead;
    	
        if(*pioffsetHead==-1) return NOTFOUND;
    
	*pioffsetCur=-1;
	
    	ptHead=OPFBINTREE(pNodeSeg,*pioffsetHead);
    	
        if((r=(*pFunction)(p,ptHead->ioffData))==0){

		POINTER ioffCur=-1,*pioffPre;

		*pioffsetCur=*pioffsetHead;

                if(ptHead->ioffLeft==-1){
                        /*左子树为空，右子树空或非空，叶子节点*/
                	*pioffsetHead=ptHead->ioffRight;
                        return LOWER;   
                }
                         /*左子树非空，右子树空*/
                if(ptHead->ioffRight==-1){
                	*pioffsetHead=ptHead->ioffLeft;
                        return LOWER;
                }

		pioffPre=&(ptHead->ioffRight);

                /*左子树非空，右子树非空*/
                r=DeleteFBinMin(pNodeSeg,pioffPre,&ioffCur);

                if(ioffCur==-1) return EQUAL;/*这种情况不可能出现*/

		OOFBINTREELEFT(pNodeSeg,ioffCur)=ptHead->ioffLeft;
		OOFBINTREERIGHT(pNodeSeg,ioffCur)=ptHead->ioffRight;

                if(r==LOWER){
                        OPFBINTREE(pNodeSeg,ioffCur)->diff=ptHead->diff-1;
                        AdjustFBin(pNodeSeg,&ioffCur);
                }
                else
                        OPFBINTREE(pNodeSeg,ioffCur)->diff=ptHead->diff; 

		
                *pioffsetHead=ioffCur;

                return r;
        }

        if(r>0){
                r=DeleteFBin(pNodeSeg,&(ptHead->ioffRight),p,pFunction,pioffsetCur);
                if(r==LOWER){
                        ptHead->diff--;
                        AdjustFBin(pNodeSeg,pioffsetHead);
                }
                return r;
        }

        r=DeleteFBin(pNodeSeg,&(ptHead->ioffLeft),p,pFunction,pioffsetCur);
        if(r==LOWER){
                ptHead->diff++;
                AdjustFBin(pNodeSeg,pioffsetHead);
        }
        return r;
}
int4b DestroyFBin(void *pNodeSeg,POINTER ioffHead,
	struct ShmCtrlStruct *pShmCtrl)
{
        int4b j=0;
        
        if(ioffHead==-1) return 0;
        
        j+=DestroyFBin(pNodeSeg,OOFBINTREELEFT(pNodeSeg,ioffHead),pShmCtrl);
        j+=DestroyFBin(pNodeSeg,OOFBINTREERIGHT(pNodeSeg,ioffHead),pShmCtrl);
        
        FreeFItem(pNodeSeg,pShmCtrl,ioffHead);

        return j+1;
}
