/*
 * sysv_shm1.c
 *
 *  Created on: Jul 18, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

void main(int argc , char * argv[])
{
	printf("Hello world \n");

	key_t key = ftok("/tmp/shm1",8);
	int shid = shmget(key, 1024, IPC_CREAT | 0777); /*key, size, permissoin and flags*/
	if(shid < 0)
	{
		perror("SHARE MEM failed");
		return;
	}
	/*attaching the shared memory*/
	void *share_addr = shmat(shid, 0,SHM_RND );/*shm id, address, flag - SHM_RDONLY, SHM_REMAP, SHM_RND*/
	if(*(int*)share_addr < 0)
	{
		perror("ATTACH failed");
		return ;
	}

	/*Creating writer and reader semaphore*/
	key = ftok("./sysv_shm_server.c",8);
	int semid = semget(key, 2, IPC_CREAT | 0777);
	if(semid < 0)
	{
		perror("SEM MEM failed");
		return;
	}


	union semun s;
	s.val = 1;		/*Writing*/
	int ret = semctl(semid, 0, SETVAL,s);
	if(ret < 0)
	{
		perror("SEM MEM failed");
		return;
	}
	s.val = 0;		/*reading*/
	ret = semctl(semid, 1, SETVAL,s);
	if(ret < 0)
	{
		perror("SEM MEM failed");
		return;
	}

	struct sembuf op[3];

	/*Reading*/
	while(1)
	{
		op[0].sem_num = 1; /*Take the reading semaphore*/
		op[0].sem_op  = -1;
		op[0].sem_flg = 0;
		int o = semop(semid, &op, 1);
		if(o < 0)
		{
			perror("SEM OP FAILED");
			return;
		}

		printf("Data is = %s \n", (char *)share_addr);

		op[0].sem_num = 0; /*Release the writing semaphore*/
		op[0].sem_op  = 1;
		op[0].sem_flg = 0;
		o = semop(semid, &op, 1);
		if(o < 0)
		{
			perror("SEM OP FAILED");
			return;
		}


	}
	ret = shmdt(share_addr);
	if(ret < 0)
	{
			perror("SEM MEM failed");
			return;
	}

	ret  = shmctl(shid, IPC_RMID, NULL);
	if(ret < 0)
	{
			perror("SEM MEM failed");
			return;
	}

}
