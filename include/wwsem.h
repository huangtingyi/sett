#ifndef	__WWSEM_H__
#define __WWSEM_H__

#include "datatype.h"

union my_semun
{
	int	val;
	struct semid_ds	*buf;
	unsigned short	*array;
};

int CreateSem(key_t key,int len);
int AttachSem(key_t key);
void DestroySem(int sem_id);

int CreateSemX(key_t key,int len);
int LockSem(int s);
int UnlockSem(int s);

int Lock(int s,int ioffset);
int Unlock(int s,int ioffset);
int LockSafe(int s,int ioffset);
int UnlockSafe(int s,int ioffset);

#endif
