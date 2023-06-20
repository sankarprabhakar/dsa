/*
 * sysv_semaphore_1.c
 *
 *  Created on: Jul 15, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};



void main(int argc, char*argv[])
{
	printf("");

	key_t key = ftok("/tmp/sem1", 8);

	int semid = semget(key,1, IPC_CREAT | 0777);
	if(semid < 0)
	{
		perror("SEM CREATE FAILED");
		return;
	}

	union semun s;
	struct semid_ds s1;
	s1.sem_otime = 0;
	s.buf = &s1;
	while(s1.sem_otime != 0)
	{

		int ret = semctl(semid, 0/*semnum*/,IPC_STAT,s);
		if(ret < 0)
		{
			perror("SEMCTL ERROR");
			return;
		}
		printf("o time = %d \n", s1.sem_otime);
		sleep(1);
	}

#if 0
	/*Setting the value for the semaphore*/
	s.val = 1;
	ret = semctl(semid, 0/*semnum*/,SETVAL,s);
	if(ret < 0)
	{
		perror("SEMCTL ERROR");
		return;
	}
	ret = semctl(semid, 0/*semnum*/,GETVAL,s);
	if(ret < 0)
	{
		perror("SEMCTL ERROR");
		return;
	}
		printf("setvl  = %d \n", s.val);

#endif

	s.buf = &s1;
int	ret = semctl(semid, 0/*semnum*/,IPC_STAT,s);
	if(ret < 0)
	{
		perror("SEMCTL ERROR");
		return;
	}
	printf("o time = %d  %d\n", s1.sem_otime, s1.sem_ctime);


	struct sembuf operations[1];

	operations[0].sem_num = 0;
	operations[0].sem_op = -1;
	operations[0].sem_flg = 0;

int count = 0;
	/*acquire a semaphore*/
	while(1)
	{
		ret = semop(semid, &operations, 1);
		if(ret < 0)
		{
			perror("SEMOP failed");
		}
		else
		{
			count++;
			printf("Taking %d th item\n",count);
		}
		if(count == 35)
		{
			sem_unlink("/tmp/sem1");
			break;
		}

	}

}
