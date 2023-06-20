/*
 * sysv_semaphore_producer.c
 *
 *  Created on: Jul 15, 2016
 *      Author: sankarsa
 */


/*
 * sysv_semaphore_producer.c
 *
 *  Created on: Jul 15, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
//#include<iostream>
#include<sys/ipc.h>
#include<sys/sem.h>


int  main(int argc, char *argv[])
{
	 key_t key = ftok("/tmp/sem1", 8);
		int  semid = semget(key,1, 0);
		 if(semid < 0)
		 {
			 perror("Sem get failed\n");
		 }

		 while(1)
		 	{
		 	struct sembuf op[2];
		 	op[0].sem_num = 0;
		 	op[0].sem_op = 0;
		 	op[0].sem_flg = 0;
		 	op[1].sem_num = 0;
		 	op[1].sem_op = 10;
		 	op[1].sem_flg = 0;

		 	int ret = semop(semid,op,2);
		 	if(ret < 0)
		 	{
		 		perror("SEMOP -- ");
		 	}
		 	}



	return 0;
}



