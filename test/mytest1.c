#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <wwlog.h>
#include <trie.h>
#include <hnixs.h>
#include <wwsem.h>


struct TrieTestStruct{
	struct TrieTestStruct *pNext;
	char	sAccNbr[12];
	int	iLatnID;
};
static struct TrieTestStruct t1,t2,t3,t4,t5,t6;
int main()
{
	struct TrieTestStruct  *p;
	TRIE *pTrie=NULL;
	char sTemp[256];
	int iErrCode,i=0,id;

	system("date");	

	iErrCode=0;
	i=0;
        system("date");
        while(i<100000000){
               id=shmget(0x6110,0,0400);
		strcpy(sTemp,"123456789012345678901234567890123456789012345678901234567890");

                if(iErrCode!=0){printf("wo chao.\n"); break;}
                i++;
        }
        system("date");

	printf("hello world.\n");
	exit(1);
	
	strcpy(t1.sAccNbr,"8262");
	t1.iLatnID=	591;
	
	strcpy(t2.sAccNbr,"826");
	t2.iLatnID=	592;
	
	strcpy(t3.sAccNbr,"826");
	t3.iLatnID=	593;
	
	strcpy(t4.sAccNbr,"8");
	t4.iLatnID=	594;
	
	strcpy(t5.sAccNbr,"8262");
	t5.iLatnID=	595;

	strcpy(t5.sAccNbr,"8272");
	t5.iLatnID=	596;
	
	InsertTrie(&pTrie,t1.sAccNbr,(void*)&t1,assign_insert_trie);
	InsertTrie(&pTrie,t2.sAccNbr,(void*)&t2,assign_insert_trie);
	InsertTrie(&pTrie,t3.sAccNbr,(void*)&t3,assign_insert_trie);
	InsertTrie(&pTrie,t4.sAccNbr,(void*)&t4,assign_insert_trie);
	InsertTrie(&pTrie,t5.sAccNbr,(void*)&t5,assign_insert_trie);
	InsertTrie(&pTrie,t6.sAccNbr,(void*)&t6,assign_insert_trie);
	
	ReHookTrie(pTrie,pTrie);
	
	SearchTrie(pTrie,"8262234",(void**)&p);
	
	SearchTrie(pTrie,"8271234",(void**)&p);
	
	SearchTrie(pTrie,"8272234",(void**)&p);
	
	SearchTrie(pTrie,"82",(void**)&p);
	                                  
	SearchTrie(pTrie,"8",(void**)&p);
	
	return 0;
}
