#include "hnixs.h"
#include "wwsem.h"

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

int CreateSem(key_t key,int len)
{
	int semid;
	union my_semun sem;

	if((semid=semget(key,len,0640|IPC_EXCL|IPC_CREAT))==-1) return -1;
	
	sem.val = 1;
	if(semctl(semid,0,SETVAL,sem)==-1) return -1;

	return semid;
}
int AttachSem(key_t key)
{
	int semid;
	
	if((semid=semget(key,0,0))==-1) return -1;
	return semid;
}
int CreateSemX(key_t key,int len)
{
	
	if(CreateSem(key,len)<0) return -1;
	
	return AttachSem(key);
}

int LockSem(int s)
{
	struct sembuf LOCK =   {0,-1,SEM_UNDO};
	return semop(s,&LOCK,1);
}

int UnlockSem(int s)
{
	struct sembuf UNLOCK = {0, 1,SEM_UNDO};
	return semop(s,&UNLOCK,1);
}

int Lock(int s,int ioffset)
{
	struct sembuf LOCK={0, -1,1};

	LOCK.sem_num=ioffset;

	return semop(s,&LOCK,1);
}

int Unlock(int s,int ioffset)
{
	struct sembuf UNLOCK={0, 1,1};

	UNLOCK.sem_num=ioffset;

	return semop(s,&UNLOCK,1);
}

int LockSafe(int s,int ioffset)
{
	struct sembuf LOCK={0, -1,SEM_UNDO};


	LOCK.sem_num=ioffset;

	return semop(s,&LOCK,1);
}

int UnlockSafe(int s,int ioffset)
{
	struct sembuf UNLOCK={0, 1,SEM_UNDO};

	UNLOCK.sem_num=ioffset;

	return semop(s,&UNLOCK,1);
}

void DestroySem(int semid)
{
	semctl(semid,0,IPC_RMID,0);
}

