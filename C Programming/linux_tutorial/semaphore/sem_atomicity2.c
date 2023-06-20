/*
 * sem_atomicity.c
 *
 *  Created on: Jul 17, 2016
 *      Author: sankarsa
 */


#include<stdio.h>

#include<sys/ipc.h>
#include<sys/sem.h>
void main(int argc, char *argv[])
{
	key_t k = ftok("/tmp/sem3", 8);

	int semid = semget(k,2,IPC_CREAT | 0777);
	if(semid < 0)
	{
		perror("SEM FAILED");
	}
	struct sembuf op[3];

	int ret = 0;
//	op[0].sem_num = 0;
//	op[0].sem_op = 1;
//	op[0].sem_flg = 0;
//
//
//	 ret = semop(semid, op, 1);
//	if(ret < 0)
//	{
//		perror("SEM OP FAILED");
//	}


	op[0].sem_num = 1;
		op[0].sem_op = -1;
		op[0].sem_flg = 0;


		 ret = semop(semid, op, 1);
		if(ret < 0)
		{
			perror("SEM OP FAILED");
		}




}
